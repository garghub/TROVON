void F_1 ( void )
{
#ifdef F_2
if ( V_1 ) {
fclose ( V_1 ) ;
V_1 = NULL ;
V_2 = FALSE ;
F_3 ( L_1 ,
V_3 ) ;
}
#endif
}
void F_4 ( char * V_4 )
{
#ifdef F_2
F_1 () ;
V_1 = fopen ( V_4 , L_2 ) ;
if ( ! V_1 ) {
F_3 ( L_3 , V_4 ) ;
return;
}
F_3 ( L_4 , V_4 ) ;
strncpy ( V_3 , V_4 ,
sizeof( V_3 ) ) ;
V_2 = TRUE ;
#endif
}
static T_1 F_5 ( struct V_5 * V_6 )
{
T_1 V_7 = V_8 ;
F_6 ( F_5 ) ;
#if 0
if (!table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
table_info.pointer = table;
status = acpi_tb_recognize_table(&table_info, ACPI_TABLE_ALL);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_tb_init_table_descriptor(&table_info);
if (ACPI_FAILURE(status)) {
if (status == AE_ALREADY_EXISTS) {
status = AE_OK;
}
acpi_tb_delete_single_table(&table_info);
return_ACPI_STATUS(status);
}
#if ( ! F_7 ( V_9 ) && ! F_7 ( V_10 ) )
status =
acpi_ns_load_table(table_info.installed_desc, acpi_gbl_root_node);
if (ACPI_FAILURE(status)) {
acpi_tb_delete_tables_by_type(ACPI_TABLE_ID_DSDT);
return_ACPI_STATUS(status);
}
#endif
#endif
F_8 ( V_7 ) ;
}
T_1
F_9 ( char * V_11 ,
struct V_5 * * V_12 ,
T_2 V_13 )
{
#ifdef F_2
T_1 V_7 ;
struct V_5 * V_6 ;
T_2 V_14 = TRUE ;
V_7 = F_10 ( V_11 , & V_6 ) ;
if ( F_11 ( V_7 ) ) {
return ( V_7 ) ;
}
if ( V_13 ) {
V_14 = F_12 ( V_6 ) ;
if ( ! V_14 ) {
F_13 ( ( V_15 , V_8 ,
L_5
L_6 ,
V_6 -> V_16 ) ) ;
return ( V_17 ) ;
}
}
if ( V_14 ) {
V_7 = F_5 ( V_6 ) ;
if ( F_11 ( V_7 ) ) {
if ( V_7 == V_18 ) {
F_3
( L_7 ,
V_6 -> V_16 ) ;
} else {
F_3 ( L_8 ,
F_14 ( V_7 ) ) ;
}
return ( V_7 ) ;
}
F_15 ( 0 , V_6 ) ;
fprintf ( V_19 ,
L_9 ,
V_6 -> V_16 ) ;
}
V_20 = FALSE ;
if ( V_12 ) {
* V_12 = V_6 ;
}
#endif
return ( V_8 ) ;
}
