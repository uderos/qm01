#include "stdafx.h"
#include "QbitDm.h"

namespace udr
{

QbitDm::QbitDm() : m_density_matrix(qb_dm_t::Zero())
{
}

QbitDm::QbitDm(const QbitState & qb_state) :
	m_density_matrix(qb_state.get() * qb_state.get().adjoint())
{
}

QbitDm::QbitDm(const qb_dm_t & dm) :
	m_density_matrix(dm)
{
}

std::string QbitDm::to_string() const
{
	std::ostringstream oss;
	oss << "<" << m_density_matrix << ">";
	return oss.str();
}

void QbitDm::set(const qb_dm_t & dm)
{
	m_density_matrix = dm;
}

const qb_dm_t & QbitDm::get() const
{
	return m_density_matrix;
}

bool QbitDm::isValid() const
{
	const scalar_t trace = m_density_matrix.trace();
	const auto err = std::abs(trace - scalar_t(1.0));
	return (err < 1e-6);
}

bool QbitDm::isPureState() const
{
	bool is_pure_state = false;

	if (isValid())
	{
		const auto mtest = (m_density_matrix * m_density_matrix) - m_density_matrix;
		const auto err = mtest.norm();
		is_pure_state = (err < 1e-6);
	}

	return is_pure_state;
}

QbitDm QbitDm::operator+(const QbitDm & rv)
{
	return QbitDm(m_density_matrix + rv.m_density_matrix);
}

QbitDm QbitDm::operator*(const scalar_t scalar)
{
	return QbitDm(m_density_matrix * scalar);
}







}; //  namespace udr
