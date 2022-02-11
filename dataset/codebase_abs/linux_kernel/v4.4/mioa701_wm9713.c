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
struct V_1 * V_2 = V_8 -> V_12 -> V_13 -> V_14 [ 0 ] . V_2 ;
return F_1 ( V_2 , F_5 ( V_11 ) ) ;
}
static int F_6 ( struct V_15 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
F_7 ( V_2 , V_5 , 0x100 , 0x100 ) ;
F_7 ( V_2 , V_16 , 0xc000 , 0xc000 ) ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 )
{
int V_19 ;
if ( ! F_9 () )
return - V_20 ;
V_21 . V_22 = & V_18 -> V_22 ;
V_19 = F_10 ( & V_18 -> V_22 , & V_21 ) ;
if ( ! V_19 )
F_11 ( & V_18 -> V_22 , L_1
L_2
L_3 ) ;
return V_19 ;
}
