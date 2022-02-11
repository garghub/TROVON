static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 T_5 V_3 )
{
T_6 * V_4 ;
T_7 * V_5 ;
T_8 V_6 ;
T_9 * type ;
T_9 * V_7 ;
V_4 = F_2 ( F_3 ( V_1 ) ) ;
if ( F_4 ( V_4 ) == 0 )
return FALSE ;
if ( V_2 -> type != V_8 )
return FALSE ;
if ( F_5 ( V_4 , & V_5 , & V_6 ) ) {
F_6 ( V_5 , & V_6 , 2 , & type , - 1 ) ;
if ( strcmp ( type , L_1 ) == 0 ) {
F_6 ( V_5 , & V_6 , 3 , & V_7 , - 1 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
F_8 ( type ) ;
}
return TRUE ;
}
static void
F_9 ( T_2 * V_9 )
{
#ifdef F_10
T_10 * V_10 ;
const char * V_11 ;
#endif
#ifdef F_11
T_11 * V_12 ;
#endif
T_12 * type ;
#ifdef F_10
for ( V_10 = V_13 ; V_10 != NULL ; V_10 = V_10 -> V_14 )
{
type = F_12 ( L_2 ) ;
V_11 = L_2 ;
if ( V_10 -> V_15 )
{
type = F_13 ( type , L_3 ) ;
V_11 = L_4 ;
}
if ( V_10 -> V_16 )
{
type = F_13 ( type , V_11 ) ;
type = F_13 ( type , L_5 ) ;
V_11 = L_4 ;
}
if ( V_10 -> V_17 )
{
type = F_13 ( type , V_11 ) ;
type = F_13 ( type , L_6 ) ;
V_11 = L_4 ;
}
if ( V_10 -> V_18 )
{
type = F_13 ( type , V_11 ) ;
type = F_13 ( type , L_7 ) ;
}
F_14 ( V_9 , 0 , V_10 -> V_19 , 1 , V_10 -> V_20 ,
2 , type -> V_21 , 3 , F_15 ( V_10 -> V_22 ) , - 1 ) ;
F_16 ( type , TRUE ) ;
}
#endif
#ifdef F_11
for ( V_12 = V_23 ; V_12 != NULL ; V_12 = V_12 -> V_14 )
{
type = F_12 ( L_2 ) ;
type = F_13 ( type , L_1 ) ;
F_14 ( V_9 , 0 , V_12 -> V_19 , 1 , V_12 -> V_20 , 2 , type -> V_21 , 3 , V_12 -> V_24 , - 1 ) ;
F_16 ( type , TRUE ) ;
}
#endif
}
T_2 *
F_17 ( void )
{
T_2 * V_25 ;
T_2 * V_26 ;
static const T_9 * V_27 [] = { L_8 , L_9 , L_10 , L_11 } ;
V_25 = F_18 ( NULL , NULL ) ;
F_19 ( F_20 ( V_25 ) ,
V_28 ) ;
V_26 = F_21 ( 4 , V_27 ) ;
F_9 ( V_26 ) ;
F_22 ( V_26 , L_12 ,
F_23 ( F_1 ) , NULL ) ;
F_24 ( F_25 ( V_25 ) , V_26 ) ;
return V_25 ;
}
