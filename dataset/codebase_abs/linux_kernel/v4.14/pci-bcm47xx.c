int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_3 , V_4 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_6 L_1 ,
F_5 ( V_2 ) ) ;
return V_5 ;
}
F_6 ( V_2 , V_7 , & V_4 ) ;
V_3 = F_7 ( V_2 -> V_8 ) ;
V_5 = F_8 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 2 ) {
F_4 ( V_6 L_2 ,
F_5 ( V_2 ) ) ;
return V_5 ;
}
V_2 -> V_9 = V_5 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_10 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( V_6 L_1 ,
F_5 ( V_2 ) ) ;
return V_5 ;
}
V_5 = F_11 ( V_2 ) ;
if ( V_5 < 2 ) {
F_4 ( V_6 L_2 ,
F_5 ( V_2 ) ) ;
return V_5 ;
}
V_2 -> V_9 = V_5 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
#ifdef F_13
if ( V_10 == V_11 )
return F_2 ( V_2 ) ;
else
#endif
#ifdef F_14
if ( V_10 == V_12 )
return F_9 ( V_2 ) ;
else
#endif
return 0 ;
}
