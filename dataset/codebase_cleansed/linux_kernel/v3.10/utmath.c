acpi_status
acpi_ut_short_divide(u64 dividend,
u32 divisor, u64 *out_quotient, u32 *out_remainder)
{
union uint64_overlay dividend_ovl;
union uint64_overlay quotient;
u32 remainder32;
ACPI_FUNCTION_TRACE(ut_short_divide);
if (divisor == 0) {
ACPI_ERROR((AE_INFO, "Divide by zero"));
return_ACPI_STATUS(AE_AML_DIVIDE_BY_ZERO);
}
dividend_ovl.full = dividend;
ACPI_DIV_64_BY_32(0, dividend_ovl.part.hi, divisor,
quotient.part.hi, remainder32);
ACPI_DIV_64_BY_32(remainder32, dividend_ovl.part.lo, divisor,
quotient.part.lo, remainder32);
if (out_quotient) {
*out_quotient = quotient.full;
}
if (out_remainder) {
*out_remainder = remainder32;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ut_divide(u64 in_dividend,
u64 in_divisor, u64 *out_quotient, u64 *out_remainder)
{
union uint64_overlay dividend;
union uint64_overlay divisor;
union uint64_overlay quotient;
union uint64_overlay remainder;
union uint64_overlay normalized_dividend;
union uint64_overlay normalized_divisor;
u32 partial1;
union uint64_overlay partial2;
union uint64_overlay partial3;
ACPI_FUNCTION_TRACE(ut_divide);
if (in_divisor == 0) {
ACPI_ERROR((AE_INFO, "Divide by zero"));
return_ACPI_STATUS(AE_AML_DIVIDE_BY_ZERO);
}
divisor.full = in_divisor;
dividend.full = in_dividend;
if (divisor.part.hi == 0) {
remainder.part.hi = 0;
ACPI_DIV_64_BY_32(0, dividend.part.hi, divisor.part.lo,
quotient.part.hi, partial1);
ACPI_DIV_64_BY_32(partial1, dividend.part.lo, divisor.part.lo,
quotient.part.lo, remainder.part.lo);
}
else {
quotient.part.hi = 0;
normalized_dividend = dividend;
normalized_divisor = divisor;
do {
ACPI_SHIFT_RIGHT_64(normalized_divisor.part.hi,
normalized_divisor.part.lo);
ACPI_SHIFT_RIGHT_64(normalized_dividend.part.hi,
normalized_dividend.part.lo);
} while (normalized_divisor.part.hi != 0);
ACPI_DIV_64_BY_32(normalized_dividend.part.hi,
normalized_dividend.part.lo,
normalized_divisor.part.lo,
quotient.part.lo, partial1);
partial1 = quotient.part.lo * divisor.part.hi;
partial2.full = (u64) quotient.part.lo * divisor.part.lo;
partial3.full = (u64) partial2.part.hi + partial1;
remainder.part.hi = partial3.part.lo;
remainder.part.lo = partial2.part.lo;
if (partial3.part.hi == 0) {
if (partial3.part.lo >= dividend.part.hi) {
if (partial3.part.lo == dividend.part.hi) {
if (partial2.part.lo > dividend.part.lo) {
quotient.part.lo--;
remainder.full -= divisor.full;
}
} else {
quotient.part.lo--;
remainder.full -= divisor.full;
}
}
remainder.full = remainder.full - dividend.full;
remainder.part.hi = (u32) - ((s32) remainder.part.hi);
remainder.part.lo = (u32) - ((s32) remainder.part.lo);
if (remainder.part.lo) {
remainder.part.hi--;
}
}
}
if (out_quotient) {
*out_quotient = quotient.full;
}
if (out_remainder) {
*out_remainder = remainder.full;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ut_short_divide(u64 in_dividend,
u32 divisor, u64 *out_quotient, u32 *out_remainder)
{
ACPI_FUNCTION_TRACE(ut_short_divide);
if (divisor == 0) {
ACPI_ERROR((AE_INFO, "Divide by zero"));
return_ACPI_STATUS(AE_AML_DIVIDE_BY_ZERO);
}
if (out_quotient) {
*out_quotient = in_dividend / divisor;
}
if (out_remainder) {
*out_remainder = (u32) (in_dividend % divisor);
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ut_divide(u64 in_dividend,
u64 in_divisor, u64 *out_quotient, u64 *out_remainder)
{
ACPI_FUNCTION_TRACE(ut_divide);
if (in_divisor == 0) {
ACPI_ERROR((AE_INFO, "Divide by zero"));
return_ACPI_STATUS(AE_AML_DIVIDE_BY_ZERO);
}
if (out_quotient) {
*out_quotient = in_dividend / in_divisor;
}
if (out_remainder) {
*out_remainder = in_dividend % in_divisor;
}
return_ACPI_STATUS(AE_OK);
}
