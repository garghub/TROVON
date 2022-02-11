static void T_1 F_1 ( void )
{
void T_2 * V_1 = F_2 ( 0xffd85000 ) ;
F_3 ( 0x0131000e , V_1 + V_2 ) ;
F_3 ( 0 , V_1 + V_3 ) ;
}
static inline void F_1 ( void ) {}
static int F_4 ( struct V_4 * V_5 )
{
return F_5 ( F_6 ( V_5 ) ) ;
}
static int F_7 ( struct V_4 * V_5 )
{
return F_8 ( F_6 ( V_5 ) ) ;
}
static bool F_9 ( struct V_4 * V_5 )
{
return F_10 ( F_6 ( V_5 ) ) ;
}
static bool F_11 ( struct V_6 * V_7 )
{
return true ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = & V_9 -> V_5 ;
F_13 ( V_5 , NULL , false ) ;
V_5 -> V_10 . V_11 = V_12 ;
V_5 -> V_10 . V_13 = V_14 ;
V_5 -> V_10 . V_15 = F_11 ;
V_5 -> V_16 = true ;
V_5 -> V_17 = F_4 ;
V_5 -> V_18 = F_7 ;
if ( F_9 ( & V_9 -> V_5 ) )
F_7 ( & V_9 -> V_5 ) ;
}
void T_1 F_14 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_15 ( V_20 ) ; V_19 ++ )
F_12 ( & V_20 [ V_19 ] ) ;
}
void T_1 F_16 ( void )
{
static int V_21 ;
if ( ! V_21 ++ )
F_1 () ;
}
