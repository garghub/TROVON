static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_6 ;
V_6 = V_7 ;
V_6 . V_8 = 8 ;
V_6 . V_9 = 16 ;
V_6 . V_10 = 0x09 ;
V_6 . V_11 = 0x08 ;
return F_3 ( & V_2 -> V_12 , F_4 ( V_2 , & V_6 ) ,
(enum V_13 ) V_4 -> V_14 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
