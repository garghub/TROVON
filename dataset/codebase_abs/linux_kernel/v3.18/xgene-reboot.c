static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_6 ;
unsigned long V_7 ;
if ( V_5 )
F_2 ( V_5 -> V_8 , V_5 -> V_9 ) ;
V_7 = V_10 + V_11 ;
while ( F_3 ( V_10 , V_7 ) )
F_4 () ;
F_5 ( & V_5 -> V_12 -> V_13 , L_1 ) ;
}
static int F_6 ( struct V_14 * V_12 )
{
struct V_4 * V_5 ;
V_5 = F_7 ( & V_12 -> V_13 , sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 ) {
F_8 ( & V_12 -> V_13 , L_2 ) ;
return - V_16 ;
}
V_5 -> V_9 = F_9 ( V_12 -> V_13 . V_17 , 0 ) ;
if ( ! V_5 -> V_9 ) {
F_10 ( & V_12 -> V_13 , V_5 ) ;
F_8 ( & V_12 -> V_13 , L_3 ) ;
return - V_16 ;
}
if ( F_11 ( V_12 -> V_13 . V_17 , L_4 , & V_5 -> V_8 ) )
V_5 -> V_8 = 0xFFFFFFFF ;
V_5 -> V_12 = V_12 ;
V_18 = F_1 ;
V_6 = V_5 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_19 ) ;
}
