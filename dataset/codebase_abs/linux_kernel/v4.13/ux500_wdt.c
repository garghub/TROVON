static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
F_3 ( V_2 ) ;
F_8 ( V_3 , V_4 * 1000 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_10 ( & V_6 -> V_10 ) ;
if ( V_9 ) {
if ( V_9 -> V_4 > 0 )
V_4 = V_9 -> V_4 ;
if ( V_9 -> V_11 )
V_12 . V_13 = V_14 ;
}
V_12 . V_15 = & V_6 -> V_10 ;
F_11 ( & V_12 , V_16 ) ;
F_12 ( V_17 , false ) ;
F_8 ( V_3 , V_4 * 1000 ) ;
V_7 = F_13 ( & V_12 ) ;
if ( V_7 )
return V_7 ;
F_14 ( & V_6 -> V_10 , L_1 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_10 )
{
F_16 ( & V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
T_1 V_18 )
{
if ( F_18 ( & V_12 ) ) {
F_3 ( & V_12 ) ;
F_12 ( V_17 , true ) ;
F_8 ( V_3 , V_4 * 1000 ) ;
F_1 ( & V_12 ) ;
}
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
if ( F_18 ( & V_12 ) ) {
F_3 ( & V_12 ) ;
F_12 ( V_17 , false ) ;
F_8 ( V_3 , V_4 * 1000 ) ;
F_1 ( & V_12 ) ;
}
return 0 ;
}
