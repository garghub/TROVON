static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 = V_3 >> 8 ;
T_1 V_8 = V_3 & 0xff ;
T_1 V_9 = V_10 + V_7 * 0x10 ;
return F_3 ( V_6 , V_9 , F_4 ( V_8 ) ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 = V_3 >> 8 ;
T_1 V_8 = V_3 & 0xff ;
T_1 V_9 = V_11 + V_7 * 0x10 ;
return F_3 ( V_6 , V_9 , F_4 ( V_8 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_3 ( V_6 , V_12 , F_4 ( V_3 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
return F_3 ( V_6 , V_13 , F_4 ( V_3 ) ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
struct V_20 * V_18 = & V_15 -> V_18 ;
enum V_21 type ;
struct V_4 * V_5 ;
struct V_6 * V_6 ;
V_5 = F_9 ( V_18 , sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
type = (enum V_21 ) F_10 ( V_18 ) ;
V_6 = F_11 ( V_17 ) ;
if ( F_12 ( V_6 ) ) {
F_13 ( V_18 , L_1 ) ;
return F_14 ( V_6 ) ;
}
V_5 -> V_6 = V_6 ;
V_5 -> V_2 . V_19 = V_17 ;
if ( type == V_24 ) {
V_5 -> V_2 . V_25 = & V_26 ;
V_5 -> V_2 . V_27 = V_28 ;
} else {
V_5 -> V_2 . V_25 = & V_29 ;
V_5 -> V_2 . V_27 = V_30 ;
}
return F_15 ( & V_5 -> V_2 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
