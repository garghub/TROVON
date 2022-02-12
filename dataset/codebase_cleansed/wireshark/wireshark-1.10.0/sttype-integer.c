void
sttype_register_integer(void)
{
static sttype_t integer_type = {
STTYPE_INTEGER,
"INTEGER",
NULL,
NULL,
NULL
};
sttype_register(&integer_type);
}
