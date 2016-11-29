#ifndef UDR_QM_QB_DENSITY_MATRIX_H
#define UDR_QM_QB_DENSITY_MATRIX_H

#include "QbitState.h"

namespace udr
{
class QbitDm
{
	public:
		QbitDm();
		QbitDm(const QbitState & qb_state);
		QbitDm(const qb_dm_t & dm);

		virtual ~QbitDm() = default;

		void set(const qb_dm_t & dm);
		const qb_dm_t & get() const;

		std::string to_string() const;

		bool isValid() const;
		bool isPureState() const;

		QbitDm operator+(const QbitDm & rv);
		QbitDm operator*(const scalar_t scalar);


	private:

		qb_dm_t m_density_matrix;
};

}; // namespace udr

#endif // UDR_QM_QB_DENSITY_MATRIX_H
