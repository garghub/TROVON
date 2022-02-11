static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_8 ;
V_6 = F_2 ( V_4 ) ;
V_8 = V_2 -> type -> V_9 ( V_2 , V_4 , & V_7 ) ;
F_3 ( V_4 , ( V_7 - V_2 -> V_10 . V_11 ) - V_4 -> V_12 ) ;
F_4 ( V_4 , - V_2 -> V_10 . V_11 ) ;
V_4 -> V_13 = V_4 -> V_14 + V_8 ;
F_5 ( V_4 , V_8 ) ;
memmove ( F_2 ( V_4 ) , V_6 , V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_15 = V_4 -> V_12 - F_7 ( V_4 ) ;
if ( V_4 -> V_13 != V_4 -> V_14 ) {
memmove ( F_7 ( V_4 ) ,
F_8 ( V_4 ) , V_15 ) ;
V_4 -> V_14 = V_4 -> V_13 ;
}
F_2 ( V_4 ) -> V_16 = F_9 ( V_4 -> V_17 + V_15 -
sizeof( struct V_5 ) ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_18 , V_19 ) ;
}
static void T_3 F_13 ( void )
{
int V_20 ;
V_20 = F_14 ( & V_18 , V_19 ) ;
F_15 ( V_20 ) ;
}
