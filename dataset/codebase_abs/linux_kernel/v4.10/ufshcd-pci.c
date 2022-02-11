static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( F_3 ( V_2 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( F_3 ( V_2 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( F_3 ( V_2 ) ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( F_3 ( V_2 ) ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_13 ( (struct V_5 * ) F_14 ( V_4 ) ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
F_16 ( & V_4 -> V_2 ) ;
F_17 ( & V_4 -> V_2 ) ;
F_18 ( V_6 ) ;
F_19 ( V_6 ) ;
}
static int
F_20 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
struct V_5 * V_6 ;
void T_1 * V_9 ;
int V_10 ;
V_10 = F_21 ( V_4 ) ;
if ( V_10 ) {
F_22 ( & V_4 -> V_2 , L_1 ) ;
return V_10 ;
}
F_23 ( V_4 ) ;
V_10 = F_24 ( V_4 , 1 << 0 , V_11 ) ;
if ( V_10 < 0 ) {
F_22 ( & V_4 -> V_2 , L_2 ) ;
return V_10 ;
}
V_9 = F_25 ( V_4 ) [ 0 ] ;
V_10 = F_26 ( & V_4 -> V_2 , & V_6 ) ;
if ( V_10 ) {
F_22 ( & V_4 -> V_2 , L_3 ) ;
return V_10 ;
}
F_27 ( & V_6 -> V_12 ) ;
V_10 = F_28 ( V_6 , V_9 , V_4 -> V_13 ) ;
if ( V_10 ) {
F_22 ( & V_4 -> V_2 , L_4 ) ;
F_19 ( V_6 ) ;
return V_10 ;
}
F_29 ( V_4 , V_6 ) ;
F_30 ( & V_4 -> V_2 ) ;
F_31 ( & V_4 -> V_2 ) ;
return 0 ;
}
