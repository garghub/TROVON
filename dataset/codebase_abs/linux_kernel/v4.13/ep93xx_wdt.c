static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0xaaaa , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0xaa55 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x5555 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
int V_12 ;
V_4 = F_7 ( & V_8 -> V_13 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_10 = F_8 ( V_8 , V_16 , 0 ) ;
V_4 -> V_5 = F_9 ( & V_8 -> V_13 , V_10 ) ;
if ( F_10 ( V_4 -> V_5 ) )
return F_11 ( V_4 -> V_5 ) ;
V_11 = F_12 ( V_4 -> V_5 + V_6 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_17 = ( V_11 & 0x01 ) ? V_18 : 0 ;
V_2 -> V_19 = & V_20 ;
V_2 -> V_21 = & V_22 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 200 ;
V_2 -> V_25 = & V_8 -> V_13 ;
F_13 ( V_2 , V_26 ) ;
V_2 -> V_27 = V_28 ;
F_14 ( V_2 , V_27 , & V_8 -> V_13 ) ;
F_15 ( V_2 , V_4 ) ;
V_12 = F_16 ( & V_8 -> V_13 , V_2 ) ;
if ( V_12 )
return V_12 ;
F_17 ( & V_8 -> V_13 , L_1 ,
( V_11 & 0x08 ) ? L_2 : L_3 ) ;
return 0 ;
}
