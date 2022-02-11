static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_5 = F_3 ( V_4 , true ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_4 -> V_6 , V_7 ,
V_8 ) ;
if ( V_5 ) {
F_3 ( V_4 , false ) ;
return V_5 ;
}
return F_3 ( V_4 , false ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_11 ;
const struct V_12 * V_13 = F_6 ( V_10 ) ;
const char * V_14 = V_13 ? V_13 -> V_14 : NULL ;
const int V_15 = V_13 ? V_13 -> V_16 : 0 ;
V_11 = F_7 ( V_10 , & V_17 ) ;
if ( F_8 ( V_11 ) ) {
F_9 ( & V_10 -> V_18 , L_1 ,
( int ) F_10 ( V_11 ) ) ;
return F_10 ( V_11 ) ;
}
return F_11 ( V_11 , V_10 -> V_19 , V_14 ,
F_1 , V_15 ) ;
}
static int F_12 ( struct V_9 * V_10 )
{
return F_13 ( & V_10 -> V_18 ) ;
}
