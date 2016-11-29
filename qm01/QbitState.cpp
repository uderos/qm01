
#include "stdafx.h"

#include "QbitState.h"

namespace udr
{

QbitState::QbitState() : m_std_state(qb_state_t::Zero())
{
}

QbitState::QbitState(const qb_state_t qb_state) :
	m_std_state(qb_state)
{
}

QbitState::QbitState(const scalar_t alpha, 
				 const scalar_t beta)
{
	set(alpha, beta);
}


void QbitState::set(const scalar_t alpha, 
				  const scalar_t beta)
{
	m_std_state(0) = alpha;
	m_std_state(1) = beta;
}

const qb_state_t & QbitState::get() const
{
	return m_std_state;
}


const scalar_t QbitState::operator[](const int idx) const
{
	if (idx < 0 || idx >= m_std_state.rows())
		throw std::invalid_argument(std::to_string(idx));
	return m_std_state(idx);
}

QbitState QbitState::operator+(const QbitState & rv)
{
	return QbitState(m_std_state + rv.m_std_state);
}

QbitState QbitState::operator*(const scalar_t scalar)
{
	return QbitState(m_std_state * scalar);
}

void  QbitState::normalize()
{
	m_std_state.normalize();
}

std::string QbitState::to_string() const
{
	std::ostringstream oss;
	oss << "<" << m_std_state(0)
		<< "," << m_std_state(1)
		<< ">";
	return oss.str();
}

}; // namespace udr

