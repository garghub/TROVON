int F_1 ( T_1 V_1 , unsigned int * V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 ,
V_6 ) ;
* V_2 = F_3 ( V_4 , V_1 ) ;
return ( * V_2 > 0 ) ? * V_2 : - V_7 ;
}
int F_4 ( struct V_8 * V_9 , T_1 V_1 , int V_10 ,
int V_11 )
{
struct V_12 V_13 ;
if ( F_5 ( ! V_5 ) ) {
F_6 ( L_1 ) ;
return - V_7 ;
}
V_13 . V_14 = V_5 ;
V_13 . V_15 [ 0 ] = V_1 ;
V_13 . V_15 [ 1 ] = F_7 ( V_10 , V_11 ) ;
V_13 . V_16 = 2 ;
return F_8 ( & V_13 ) ;
}
void F_9 ( T_1 V_1 )
{
struct V_3 * V_4 = F_2 ( V_5 ,
V_6 ) ;
int V_2 = F_3 ( V_4 , V_1 ) ;
F_10 ( V_2 ) ;
}
void T_2 F_11 ( enum V_17 V_18 ,
struct V_19 * V_14 )
{
V_20 = V_18 ;
V_5 = V_14 ;
}
