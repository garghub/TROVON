static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , 0x00 ) ;
F_3 ( V_4 , 0x00 ) ;
F_3 ( V_4 , 0x00 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = F_5 ( V_4 ) ;
struct V_7 V_8 ;
if ( ! V_6 )
return - V_9 ;
V_8 = V_10 ;
V_8 . V_11 = 8 ;
V_8 . V_12 = 16 ;
V_8 . V_13 = 0x1 ;
return F_6 ( & V_4 -> V_2 ,
F_7 ( V_4 , & V_8 ) ,
V_6 -> V_14 , F_1 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
F_9 ( & V_4 -> V_2 ) ;
return 0 ;
}
