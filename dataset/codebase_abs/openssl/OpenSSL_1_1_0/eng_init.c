int F_1 ( T_1 * V_1 )
{
int V_2 = 1 ;
if ( ( V_1 -> V_3 == 0 ) && V_1 -> V_4 )
V_2 = V_1 -> V_4 ( V_1 ) ;
if ( V_2 ) {
V_1 -> V_5 ++ ;
V_1 -> V_3 ++ ;
F_2 ( V_1 , 0 , 1 ) ;
F_2 ( V_1 , 1 , 1 ) ;
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
F_6 ( V_1 -> V_3 < 0 ) ;
if ( ! F_7 ( V_1 , 0 ) ) {
F_8 ( V_9 , V_10 ) ;
return 0 ;
}
return V_2 ;
}
int F_9 ( T_1 * V_1 )
{
int V_11 ;
if ( V_1 == NULL ) {
F_8 ( V_12 , V_13 ) ;
return 0 ;
}
if ( ! F_10 ( & V_14 , V_15 ) ) {
F_8 ( V_12 , V_16 ) ;
return 0 ;
}
F_5 ( V_8 ) ;
V_11 = F_1 ( V_1 ) ;
F_4 ( V_8 ) ;
return V_11 ;
}
int F_11 ( T_1 * V_1 )
{
int V_2 = 1 ;
if ( V_1 == NULL )
return 1 ;
F_5 ( V_8 ) ;
V_2 = F_3 ( V_1 , 1 ) ;
F_4 ( V_8 ) ;
if ( ! V_2 ) {
F_8 ( V_17 , V_10 ) ;
return 0 ;
}
return V_2 ;
}
