static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_4 , V_5 [ V_3 ] . V_6 * 1000 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_4 ;
return F_4 ( V_2 , V_5 , 20 * 1000 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( ! F_6 ( V_8 ) )
F_7 ( V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_8 = F_9 ( V_2 ) ;
if ( F_6 ( V_8 ) )
F_10 ( L_1 , F_11 ( V_8 ) ) ;
else
F_12 ( L_2 , V_8 -> type ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_5 = F_14 ( & V_10 -> V_13 ) ;
if ( ! V_5 ) {
F_10 ( L_3 ) ;
return - V_14 ;
}
V_4 = F_15 ( & V_10 -> V_13 , L_4 ) ;
if ( F_6 ( V_4 ) ) {
F_10 ( L_5 ) ;
return F_11 ( V_4 ) ;
}
F_12 ( L_6 ) ;
F_16 (pos, freq_table)
F_12 ( L_7 , V_12 -> V_6 / 1000 ) ;
return F_17 ( & V_15 ) ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_16 ) ;
}
