static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_3 V_3 )
{
T_3 V_4 ;
T_3 V_5 = 0 ;
if ( V_2 != V_3 ) {
F_2 ( ( V_6 ,
L_1 ,
V_3 , V_2 ) ) ;
}
for ( V_4 = 1 ; V_4 < V_3 ; V_4 ++ ) {
if ( V_1 [ V_4 ] == 0x0A ) {
if ( V_1 [ V_4 - 1 ] != 0x0D ) {
return ( V_7 ) ;
} else {
V_5 ++ ;
}
V_4 ++ ;
}
}
if ( ! V_5 ) {
return ( V_7 ) ;
}
F_3 ( L_2 ) ;
F_3 ( L_3 , V_5 ) ;
F_3 ( L_4 ) ;
return ( V_8 ) ;
}
static T_1
F_4 ( T_4 * V_9 ,
struct V_10 * * V_1 , T_3 * V_2 )
{
struct V_10 V_11 ;
T_3 V_12 ;
T_1 V_13 ;
T_3 V_14 ;
T_2 V_15 = TRUE ;
T_5 V_16 ;
V_14 = F_5 ( V_9 ) ;
if ( V_14 == V_17 ) {
return ( V_18 ) ;
}
if ( V_14 < 4 ) {
return ( V_19 ) ;
}
fseek ( V_9 , 0 , V_20 ) ;
V_16 = fread ( & V_11 , 1 , sizeof( struct V_10 ) , V_9 ) ;
if ( V_16 != sizeof( struct V_10 ) ) {
F_3 ( L_5 ) ;
return ( V_19 ) ;
}
if ( F_6 ( V_11 . V_21 ) ) {
* V_2 = V_14 ;
V_15 = FALSE ;
} else {
#if 0
status = acpi_tb_validate_table_header(&table_header);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Table header is invalid!\n");
return (status);
}
#endif
if ( V_11 . V_22 > V_14 ) {
F_3
( L_6 ,
V_11 . V_22 , V_14 ) ;
#ifdef F_7
V_13 = F_8 ( V_9 , NULL , FALSE ) ;
if ( F_9 ( V_13 ) ) {
F_3
( L_7 ) ;
}
#endif
return ( V_19 ) ;
}
#ifdef F_10
if ( ! F_11
( ( char * ) V_11 . V_21 , V_23 )
&& ! F_11 ( ( char * ) V_11 . V_21 ,
V_24 )
&& ! F_11 ( ( char * ) V_11 . V_21 ,
V_25 ) ) {
F_3
( L_8 ,
( char * ) V_11 . V_21 ) ;
F_12 ( & V_11 ,
sizeof( struct V_10 ) ) ;
return ( V_18 ) ;
}
#endif
* V_2 = V_11 . V_22 ;
}
* V_1 = F_13 ( ( V_26 ) V_14 ) ;
if ( ! * V_1 ) {
F_3
( L_9 ,
V_11 . V_21 , * V_2 ) ;
return ( V_27 ) ;
}
fseek ( V_9 , 0 , V_20 ) ;
V_12 = fread ( * V_1 , 1 , ( V_26 ) V_14 , V_9 ) ;
if ( V_12 == V_14 ) {
if ( V_15 ) {
V_13 = F_14 ( ( void * ) * V_1 ,
F_15 ( struct
V_10 ,
* V_1 ) ->
V_22 ) ;
if ( V_13 == V_28 ) {
V_13 =
F_1 ( ( T_2 * )
* V_1 ,
V_14 ,
( * V_1 ) ->
V_22 ) ;
return ( V_13 ) ;
}
}
return ( V_7 ) ;
}
if ( V_12 > 0 ) {
F_3 ( L_10 ,
V_14 , V_12 ) ;
return ( V_7 ) ;
}
F_3 ( L_11 ) ;
F_16 ( * V_1 ) ;
* V_1 = NULL ;
* V_2 = 0 ;
return ( V_18 ) ;
}
T_1
F_17 ( char * V_29 , struct V_10 * * V_1 )
{
T_4 * V_30 ;
T_3 V_14 ;
T_3 V_2 ;
T_1 V_13 = V_18 ;
V_30 = fopen ( V_29 , L_12 ) ;
if ( ! V_30 ) {
perror ( L_13 ) ;
return ( V_13 ) ;
}
V_14 = F_5 ( V_30 ) ;
if ( V_14 == V_17 ) {
goto exit;
}
fprintf ( V_31 ,
L_14 ,
V_29 , V_14 , V_14 ) ;
V_13 = F_4 ( V_30 , V_1 , & V_2 ) ;
if ( F_18 ( V_13 ) ) {
F_3 ( L_15 ) ;
}
exit:
fclose ( V_30 ) ;
return ( V_13 ) ;
}
