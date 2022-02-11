static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned short V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 , V_5 ) ;
F_3 ( V_2 , V_5 , V_4 | 0x0100 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 | ( 1 << 15 ) ) ;
} else {
V_4 = F_2 ( V_2 , V_5 ) ;
F_3 ( V_2 , V_5 , V_4 & ~ 0x0100 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 & ~ ( 1 << 15 ) ) ;
}
return 0 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
return F_1 ( V_2 , F_5 ( V_11 ) ) ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned short V_4 ;
V_4 = V_2 -> V_14 -> V_15 ( V_2 , V_5 ) ;
V_2 -> V_14 -> V_16 ( V_2 , V_5 , V_4 | 0x0100 ) ;
V_4 = V_2 -> V_14 -> V_15 ( V_2 , V_17 ) ;
V_2 -> V_14 -> V_16 ( V_2 , V_17 , V_4 | 0xc000 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
int V_20 ;
if ( ! F_8 () )
return - V_21 ;
V_22 . V_23 = & V_19 -> V_23 ;
V_20 = F_9 ( & V_22 ) ;
if ( ! V_20 )
F_10 ( & V_19 -> V_23 , L_1
L_2
L_3 ) ;
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_24 * V_25 = F_12 ( V_19 ) ;
F_13 ( V_25 ) ;
return 0 ;
}
