static void F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
if ( V_2 && V_2 -> V_3 ) {
V_2 -> V_3 ( V_2 ) ;
}
return;
}
void F_2 ( T_1 * V_2 , T_2 * V_4 , const char * V_5 )
{
T_3 V_6 ;
if ( ! V_2 || ! V_4 ) {
return;
}
V_6 = V_2 -> V_7 ;
if ( ! V_2 -> V_7 )
F_3 ( V_2 , V_5 ) ;
V_2 -> V_8 = V_9 ;
F_4 ( V_4 ) ;
if ( ! V_6 )
F_5 ( V_2 ) ;
}
T_3 F_6 ( T_1 * V_2 , T_2 * V_4 , T_4 * V_10 , const T_5 * V_11 )
{
T_3 V_6 ;
if ( ! V_2 ) {
return FALSE ;
}
V_6 = V_2 -> V_7 ;
V_2 -> V_12 = F_7 ( V_11 , L_1 ) ;
if ( V_2 -> V_12 == NULL ) {
F_8 ( V_11 , V_13 , TRUE ) ;
return FALSE ;
}
F_9 ( V_10 , V_2 -> V_12 ) ;
if ( ferror ( V_2 -> V_12 ) ) {
F_10 ( V_11 , V_13 ) ;
fclose ( V_2 -> V_12 ) ;
return FALSE ;
}
if ( ! V_2 -> V_7 )
F_3 ( V_2 , NULL ) ;
V_2 -> V_8 = V_14 ;
V_2 -> V_15 = V_10 ;
F_4 ( V_4 ) ;
V_2 -> V_8 = V_9 ;
if ( ! V_6 )
F_5 ( V_2 ) ;
if ( ferror ( V_2 -> V_12 ) ) {
F_10 ( V_11 , V_13 ) ;
fclose ( V_2 -> V_12 ) ;
return FALSE ;
}
if ( fclose ( V_2 -> V_12 ) == V_16 ) {
F_10 ( V_11 , V_13 ) ;
return FALSE ;
}
return TRUE ;
}
T_3 F_11 ( const T_4 * V_17 , T_4 * V_18 )
{
if ( V_17 == NULL || V_18 == NULL )
return FALSE ;
if ( ( F_12 ( & ( V_17 -> V_19 ) , & ( V_18 -> V_20 ) ) )
&& ( V_17 -> V_21 == V_18 -> V_22 )
&& ( F_12 ( & ( V_17 -> V_20 ) , & ( V_18 -> V_19 ) ) )
&& ( V_17 -> V_22 == V_18 -> V_21 ) )
return TRUE ;
else
return FALSE ;
}
void F_13 ( T_1 * V_2 , T_2 * V_4 , T_4 * V_23 , T_4 * V_24 )
{
T_3 V_6 ;
if ( ! V_2 ) {
return;
}
V_6 = V_2 -> V_7 ;
if ( ! V_2 -> V_7 )
F_3 ( V_2 , NULL ) ;
V_2 -> V_8 = V_25 ;
V_2 -> V_15 = V_23 ;
V_2 -> V_26 = V_24 ;
F_4 ( V_4 ) ;
V_2 -> V_8 = V_9 ;
if ( ! V_6 )
F_5 ( V_2 ) ;
}
void
F_5 ( T_1 * V_2 )
{
if ( V_2 && V_2 -> V_7 ) {
F_14 ( V_2 ) ;
V_2 -> V_7 = FALSE ;
}
}
void
F_3 ( T_1 * V_2 , const char * V_5 )
{
T_6 * V_27 ;
if ( ! V_2 ) {
return;
}
if ( ! V_2 -> V_7 ) {
V_27 = F_15 ( L_2 , V_2 ,
V_5 , 0 , V_28 , V_29 ,
F_1 ) ;
if ( V_27 != NULL ) {
F_16 ( V_30 , V_31 ,
L_3 , V_27 -> V_32 ) ;
F_17 ( V_27 , TRUE ) ;
exit ( 1 ) ;
}
V_2 -> V_7 = TRUE ;
}
}
