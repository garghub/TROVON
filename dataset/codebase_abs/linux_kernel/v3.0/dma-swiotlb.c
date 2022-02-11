void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 -> V_7 ) ;
V_6 = & V_2 -> V_8 . V_9 ;
V_6 -> V_10 =
V_4 -> V_11 + V_4 -> V_12 ;
}
static int F_3 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
struct V_17 * V_8 = V_16 ;
struct V_5 * V_6 ;
if ( V_15 != V_18 )
return 0 ;
V_6 = & V_8 -> V_9 ;
V_6 -> V_10 = 0 ;
if ( ( F_4 ( V_8 ) + 1 ) < F_5 () )
F_6 ( V_8 , & V_19 ) ;
return V_20 ;
}
int T_1 F_7 ( void )
{
F_8 ( & V_21 ,
& V_22 ) ;
return 0 ;
}
