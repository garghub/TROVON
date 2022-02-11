static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_2 * V_4 = F_2 ( V_3 ) ;
int V_5 = F_3 ( V_3 ) ;
int V_6 ;
F_4 (nla, head, len, rem) {
if ( V_3 -> V_7 & V_8 ) {
V_3 -> V_7 &= ~ V_8 ;
if ( V_7 ( V_3 ) > V_1 )
return - V_9 ;
}
}
return 0 ;
}
int F_5 ( struct V_2 * V_10 [] , int V_1 , struct V_2 * V_3 ,
const struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_1 ( V_1 , V_3 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_10 , V_1 , V_3 , V_12 , NULL ) ;
return V_13 ;
}
struct V_2 * F_7 ( int V_1 , struct V_2 * V_3 , int V_14 )
{
int V_13 ;
V_13 = F_1 ( V_1 , V_3 ) ;
if ( V_13 )
return F_8 ( V_13 ) ;
return F_9 ( V_3 , V_14 ) ;
}
