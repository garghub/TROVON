void F_1 ( int V_1 )
{
F_2 ( false ) ;
F_3 ( V_1 , L_1 ) ;
}
void F_4 ( T_1 * V_2 )
{
T_2 V_3 ;
T_3 * V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
V_4 = F_5 ( V_2 ) ;
V_5 = F_6 ( V_4 , V_2 -> V_2 ) ;
F_7 ( V_4 , V_5 , & V_3 ) ;
V_7 = V_3 . V_7 * 3 / 4 ;
V_6 = V_3 . V_6 * 3 / 4 ;
F_8 ( F_9 ( V_2 ) , V_7 , V_6 ) ;
}
const char * F_10 ( double V_8 )
{
if ( V_8 >= V_9 )
return L_2 ;
if ( V_8 >= V_10 )
return L_3 ;
return NULL ;
}
T_1 * F_11 ( void )
{
T_1 * V_11 ;
T_1 * V_12 ;
T_1 * V_13 ;
V_11 = F_12 () ;
F_13 ( V_11 , TRUE ) ;
V_12 = F_14 ( L_4 ) ;
F_15 ( V_12 ) ;
V_13 = F_16 ( F_17 ( V_11 ) ) ;
F_18 ( F_19 ( V_13 ) , V_12 ) ;
F_20 ( F_17 ( V_11 ) , V_14 ,
V_15 ) ;
F_21 ( V_11 , L_5 ,
F_22 ( V_16 ) , NULL ) ;
V_17 -> V_11 = V_11 ;
V_17 -> V_18 = V_12 ;
return V_11 ;
}
T_1 * F_23 ( void )
{
T_1 * V_19 ;
unsigned V_20 ;
V_19 = F_24 () ;
V_20 = F_25 ( F_26 ( V_19 ) ,
L_6 ) ;
V_17 -> V_21 = V_19 ;
V_17 -> V_22 = V_20 ;
return V_19 ;
}
