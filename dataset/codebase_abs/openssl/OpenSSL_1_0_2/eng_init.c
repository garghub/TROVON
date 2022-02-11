int F_1 ( T_1 * V_1 )
{
int V_2 = 1 ;
if ( ( V_1 -> V_3 == 0 ) && V_1 -> V_4 )
V_2 = V_1 -> V_4 ( V_1 ) ;
if ( V_2 ) {
V_1 -> V_5 ++ ;
V_1 -> V_3 ++ ;
F_2 (e, 0 , 1 )
F_2 (e, 1 , 1 )
}
return V_2 ;
}
int F_3 ( T_1 * V_1 , int V_6 )
{
int V_2 = 1 ;
V_1 -> V_3 -- ;
F_2 ( V_1 , 1 , - 1 ) ;
if ( ( V_1 -> V_3 == 0 ) && V_1 -> V_7 ) {
if ( V_6 )
F_4 ( V_8 ) ;
V_2 = V_1 -> V_7 ( V_1 ) ;
if ( V_6 )
F_5 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
}
#ifdef F_6
if ( V_1 -> V_3 < 0 ) {
fprintf ( V_9 , L_1 ) ;
abort () ;
}
#endif
if ( ! F_7 ( V_1 , 0 ) ) {
F_8 ( V_10 , V_11 ) ;
return 0 ;
}
return V_2 ;
}
int F_9 ( T_1 * V_1 )
{
int V_12 ;
if ( V_1 == NULL ) {
F_8 ( V_13 , V_14 ) ;
return 0 ;
}
F_5 ( V_8 ) ;
V_12 = F_1 ( V_1 ) ;
F_4 ( V_8 ) ;
return V_12 ;
}
int F_10 ( T_1 * V_1 )
{
int V_2 = 1 ;
if ( V_1 == NULL ) {
F_8 ( V_15 , V_14 ) ;
return 0 ;
}
F_5 ( V_8 ) ;
V_2 = F_3 ( V_1 , 1 ) ;
F_4 ( V_8 ) ;
if ( ! V_2 ) {
F_8 ( V_15 , V_11 ) ;
return 0 ;
}
return V_2 ;
}
