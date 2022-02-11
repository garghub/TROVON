static void F_1 ( char V_1 , const char * V_2 )
{
struct V_3 * V_4 = V_5 ;
unsigned long V_6 ;
if ( V_4 )
F_2 ( V_4 -> V_7 , V_4 -> V_8 ) ;
V_6 = V_9 + V_10 ;
while ( F_3 ( V_9 , V_6 ) )
F_4 () ;
F_5 ( & V_4 -> V_11 -> V_12 , L_1 ) ;
}
static int F_6 ( struct V_13 * V_11 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( & V_11 -> V_12 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 ) {
F_8 ( & V_11 -> V_12 , L_2 ) ;
return - V_15 ;
}
V_4 -> V_8 = F_9 ( V_11 -> V_12 . V_16 , 0 ) ;
if ( ! V_4 -> V_8 ) {
F_10 ( & V_11 -> V_12 , V_4 ) ;
F_8 ( & V_11 -> V_12 , L_3 ) ;
return - V_15 ;
}
if ( F_11 ( V_11 -> V_12 . V_16 , L_4 , & V_4 -> V_7 ) )
V_4 -> V_7 = 0xFFFFFFFF ;
V_4 -> V_11 = V_11 ;
V_17 = F_1 ;
V_5 = V_4 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_18 ) ;
}
