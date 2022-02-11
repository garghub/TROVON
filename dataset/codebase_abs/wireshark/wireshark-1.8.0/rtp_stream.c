static void F_1 ( void * T_1 V_1 )
{
F_2 ( V_2 . V_3 ) ;
return;
}
void F_3 ( void )
{
T_2 V_4 = V_2 . V_5 ;
if ( ! V_2 . V_5 )
F_4 () ;
V_2 . V_6 = V_7 ;
F_5 ( & V_8 ) ;
if ( ! V_4 )
F_6 () ;
}
T_2 F_7 ( T_3 * V_9 , const T_4 * V_10 )
{
T_2 V_4 = V_2 . V_5 ;
V_2 . V_11 = F_8 ( V_10 , L_1 ) ;
if ( V_2 . V_11 == NULL ) {
F_9 ( V_10 , V_12 , TRUE ) ;
return FALSE ;
}
F_10 ( V_9 , V_2 . V_11 ) ;
if ( ferror ( V_2 . V_11 ) ) {
F_11 ( V_10 , V_12 ) ;
fclose ( V_2 . V_11 ) ;
return FALSE ;
}
if ( ! V_2 . V_5 )
F_4 () ;
V_2 . V_6 = V_13 ;
V_2 . V_14 = V_9 ;
F_5 ( & V_8 ) ;
V_2 . V_6 = V_7 ;
if ( ! V_4 )
F_6 () ;
if ( ferror ( V_2 . V_11 ) ) {
F_11 ( V_10 , V_12 ) ;
fclose ( V_2 . V_11 ) ;
return FALSE ;
}
if ( fclose ( V_2 . V_11 ) == V_15 ) {
F_11 ( V_10 , V_12 ) ;
return FALSE ;
}
return TRUE ;
}
void F_12 ( T_3 * V_16 , T_3 * V_17 )
{
T_2 V_4 = V_2 . V_5 ;
if ( ! V_2 . V_5 )
F_4 () ;
V_2 . V_6 = V_18 ;
V_2 . V_14 = V_16 ;
V_2 . V_19 = V_17 ;
F_5 ( & V_8 ) ;
V_2 . V_6 = V_7 ;
if ( ! V_4 )
F_6 () ;
}
const T_5 * F_13 ( void )
{
return & V_2 ;
}
void
F_6 ( void )
{
if ( V_2 . V_5 ) {
F_14 () ;
F_15 ( & V_2 ) ;
F_16 () ;
V_2 . V_5 = FALSE ;
}
}
void
F_4 ( void )
{
T_6 * V_20 ;
if ( ! V_2 . V_5 ) {
V_20 = F_17 ( L_2 , & V_2 ,
NULL , 0 , V_21 , V_22 ,
F_1 ) ;
if ( V_20 != NULL ) {
F_18 ( V_23 , V_24 ,
L_3 , V_20 -> V_25 ) ;
F_19 ( V_20 , TRUE ) ;
exit ( 1 ) ;
}
V_2 . V_5 = TRUE ;
}
}
