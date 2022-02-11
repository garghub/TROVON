static void
F_1 ( T_1 * V_1 )
{
#ifdef F_2
T_2 * V_2 ;
const char * V_3 ;
#endif
#ifdef F_3
T_3 * V_4 ;
#endif
T_4 * type ;
#ifdef F_2
for ( V_2 = V_5 ; V_2 != NULL ; V_2 = V_2 -> V_6 )
{
type = F_4 ( L_1 ) ;
V_3 = L_1 ;
if ( V_2 -> V_7 )
{
type = F_5 ( type , L_2 ) ;
V_3 = L_3 ;
}
if ( V_2 -> V_8 )
{
type = F_5 ( type , V_3 ) ;
type = F_5 ( type , L_4 ) ;
V_3 = L_3 ;
}
if ( V_2 -> V_9 )
{
type = F_5 ( type , V_3 ) ;
type = F_5 ( type , L_5 ) ;
V_3 = L_3 ;
}
if ( V_2 -> V_10 )
{
type = F_5 ( type , V_3 ) ;
type = F_5 ( type , L_6 ) ;
}
F_6 ( V_1 , 0 , V_2 -> V_11 , 1 , V_2 -> V_12 ,
2 , type -> V_13 , 3 , F_7 ( V_2 -> V_14 ) , - 1 ) ;
F_8 ( type , TRUE ) ;
}
#endif
#ifdef F_3
for ( V_4 = V_15 ; V_4 != NULL ; V_4 = V_4 -> V_6 )
{
type = F_4 ( L_1 ) ;
type = F_5 ( type , L_7 ) ;
F_6 ( V_1 , 0 , V_4 -> V_11 , 1 , V_4 -> V_12 , 2 , type -> V_13 , 3 , V_4 -> V_16 , - 1 ) ;
F_8 ( type , TRUE ) ;
}
#endif
}
T_1 *
F_9 ( void )
{
T_1 * V_17 ;
T_1 * V_18 ;
const T_5 * V_19 [] = { L_8 , L_9 , L_10 , L_11 } ;
V_17 = F_10 ( NULL , NULL ) ;
F_11 ( F_12 ( V_17 ) ,
V_20 ) ;
V_18 = F_13 ( 4 , V_19 ) ;
F_1 ( V_18 ) ;
F_14 ( F_15 ( V_17 ) , V_18 ) ;
return V_17 ;
}
