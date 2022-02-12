static void
double_fvalue_new(fvalue_t *fv)
{
fv->value.floating = 0.0;
}
static void
double_fvalue_set_floating(fvalue_t *fv, gdouble value)
{
fv->value.floating = value;
}
static double
value_get_floating(fvalue_t *fv)
{
return fv->value.floating;
}
static gboolean
val_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
char *endptr = NULL;
fv->value.floating = g_ascii_strtod(s, &endptr);
if (endptr == s || *endptr != '\0') {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid number.", s);
return FALSE;
}
if (errno == ERANGE) {
if (fv->value.floating == 0) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" causes floating-point underflow.", s);
}
else if (fv->value.floating == HUGE_VAL) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" causes floating-point overflow.", s);
}
else {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid floating-point number.",
s);
}
return FALSE;
}
return TRUE;
}
static int
float_val_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return DOUBLE_REPR_LENGTH;
}
static void
float_val_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf, unsigned int size)
{
g_snprintf(buf, size, "%." G_STRINGIFY(FLT_DIG) "g", fv->value.floating);
}
static int
double_val_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return DOUBLE_REPR_LENGTH;
}
static void
double_val_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf, unsigned int size)
{
g_snprintf(buf, size, "%." G_STRINGIFY(DBL_DIG) "g", fv->value.floating);
}
static gboolean
cmp_eq(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating == b->value.floating;
}
static gboolean
cmp_ne(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating != b->value.floating;
}
static gboolean
cmp_gt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating > b->value.floating;
}
static gboolean
cmp_ge(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating >= b->value.floating;
}
static gboolean
cmp_lt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating < b->value.floating;
}
static gboolean
cmp_le(const fvalue_t *a, const fvalue_t *b)
{
return a->value.floating <= b->value.floating;
}
void
ftype_register_double(void)
{
static ftype_t float_type = {
FT_FLOAT,
"FT_FLOAT",
"Floating point (single-precision)",
0,
double_fvalue_new,
NULL,
val_from_unparsed,
NULL,
float_val_to_repr,
float_val_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
double_fvalue_set_floating,
NULL,
NULL,
NULL,
NULL,
NULL,
value_get_floating,
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
NULL,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t double_type = {
FT_DOUBLE,
"FT_DOUBLE",
"Floating point (double-precision)",
0,
double_fvalue_new,
NULL,
val_from_unparsed,
NULL,
double_val_to_repr,
double_val_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
double_fvalue_set_floating,
NULL,
NULL,
NULL,
NULL,
NULL,
value_get_floating,
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
NULL,
NULL,
NULL,
NULL,
NULL,
};
ftype_register(FT_FLOAT, &float_type);
ftype_register(FT_DOUBLE, &double_type);
}
