#ifndef UDR_QM_DATA_TYPES_H
#define UDR_QM_DATA_TYPES_H


namespace udr
{
using scalar_t = std::complex<double>;
using qb_state_t = Eigen::Matrix<scalar_t, 2, 1>;
using qb_dm_t = Eigen::Matrix<scalar_t, 2, 2>;

enum class eBasis
{
	STANDARD,
	HADAMARD,

	DEFAULT = STANDARD
};

}; // namespace udr

#endif // UDR_QM_DATA_TYPES_H
