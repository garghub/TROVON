static void F_1 ( const struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , L_1 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
int F_3 ( const struct V_1 * V_3 , T_1 V_7 , T_1 V_8 )
{
F_1 ( V_3 ) ;
return V_3 -> V_6 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_9 [ V_11 ] ;
if ( V_10 -> V_12 )
return;
if ( ! V_13 . V_14 )
return;
F_5 ( V_2 ) ;
if ( V_10 -> V_15 )
F_6 ( V_10 ) ;
V_10 -> V_12 = F_7 ( ( void * ) V_13 . V_14 ) ;
V_10 -> V_16 = V_10 -> V_12 + 256 * 1024 - 1 ;
V_10 -> V_17 = V_18 | V_19 |
V_20 ;
F_2 ( & V_2 -> V_3 , L_2 ,
V_11 , V_10 ) ;
}
int F_8 ( struct V_1 * V_3 )
{
return 0 ;
}
