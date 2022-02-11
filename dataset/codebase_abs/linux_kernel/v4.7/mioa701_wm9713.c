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
struct V_12 * V_13 = V_8 -> V_14 -> V_13 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
V_16 = F_5 ( V_13 , V_13 -> V_17 [ 0 ] . V_18 ) ;
V_2 = V_16 -> V_2 ;
return F_1 ( V_2 , F_6 ( V_11 ) ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
F_8 ( V_2 , V_5 , 0x100 , 0x100 ) ;
F_8 ( V_2 , V_19 , 0xc000 , 0xc000 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
int V_22 ;
if ( ! F_10 () )
return - V_23 ;
V_24 . V_25 = & V_21 -> V_25 ;
V_22 = F_11 ( & V_21 -> V_25 , & V_24 ) ;
if ( ! V_22 )
F_12 ( & V_21 -> V_25 , L_1
L_2
L_3 ) ;
return V_22 ;
}
