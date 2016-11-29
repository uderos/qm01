#ifndef UDR_QM_QB_STATE_H
#define UDR_QM_QB_STATE_H

#include "DataTypes.h"

namespace udr
{

class QbitState
{
	public:
		QbitState();
		QbitState(const qb_state_t qb_state);
		QbitState(const scalar_t alpha, 
				const scalar_t beta);
		virtual ~QbitState() = default;

		void set(const scalar_t alpha, 
				 const scalar_t beta);
		const qb_state_t & get() const;

		const scalar_t operator[](const int idx) const;

		QbitState operator+(const QbitState & rv);
		QbitState operator*(const scalar_t scalar);

		void normalize();

		std::string to_string() const;

	private:

		qb_state_t m_std_state;
};

}; // namespace udr

#endif // UDR_QM_QB_STATE_H
