static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
V_5 = V_6 | V_7 ;
else
V_5 = ~ ( V_6 | V_7 ) ;
F_2 ( V_5 , V_8 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_4 ( V_10 , V_13 , 0 ) ;
if ( ! V_12 )
return - V_14 ;
V_8 = F_5 ( & V_10 -> V_15 , V_12 -> V_16 , F_6 ( V_12 ) ) ;
if ( ! V_8 )
return - V_17 ;
V_5 = V_6 | V_7 ;
F_2 ( V_5 , V_8 ) ;
return F_7 ( & V_10 -> V_15 , & V_18 ) ;
}
