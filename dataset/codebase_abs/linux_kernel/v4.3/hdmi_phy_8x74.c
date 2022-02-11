static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_6 * V_2 )
{
struct V_1 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_6 * V_2 ,
unsigned long int V_8 )
{
struct V_1 * V_7 = F_4 ( V_2 ) ;
F_1 ( V_7 , V_9 , 0x1b ) ;
F_1 ( V_7 , V_10 , 0xf2 ) ;
F_1 ( V_7 , V_11 , 0x0 ) ;
F_1 ( V_7 , V_12 , 0x0 ) ;
F_1 ( V_7 , V_13 , 0x0 ) ;
F_1 ( V_7 , V_14 , 0x0 ) ;
F_1 ( V_7 , V_15 , 0x0 ) ;
F_1 ( V_7 , V_16 , 0x20 ) ;
}
static void F_7 ( struct V_6 * V_2 )
{
struct V_1 * V_7 = F_4 ( V_2 ) ;
F_1 ( V_7 , V_17 , 0x7f ) ;
}
struct V_6 * F_8 ( struct V_18 * V_18 )
{
struct V_1 * V_7 ;
struct V_6 * V_2 = NULL ;
int V_19 ;
V_7 = F_9 ( sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 ) {
V_19 = - V_21 ;
goto V_22;
}
V_2 = & V_7 -> V_23 ;
V_2 -> V_24 = & V_25 ;
V_7 -> V_5 = F_10 ( V_18 -> V_26 ,
L_1 , L_2 ) ;
if ( F_11 ( V_7 -> V_5 ) ) {
V_19 = F_12 ( V_7 -> V_5 ) ;
goto V_22;
}
return V_2 ;
V_22:
if ( V_2 )
F_3 ( V_2 ) ;
return F_13 ( V_19 ) ;
}
