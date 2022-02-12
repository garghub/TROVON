void
sttype_register_pointer(void)
{
static sttype_t field_type = {
STTYPE_FIELD,
"FIELD",
NULL,
NULL,
NULL
};
static sttype_t fvalue_type = {
STTYPE_FVALUE,
"FVALUE",
NULL,
NULL,
NULL
};
sttype_register(&field_type);
sttype_register(&fvalue_type);
}
