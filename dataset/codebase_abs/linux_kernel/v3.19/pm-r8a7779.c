static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & F_2 ( V_3 , struct V_4 , V_5 ) -> V_6 ;
}
static void T_1 F_3 ( void )
{
void T_2 * V_7 = F_4 ( 0xffd85000 ) ;
F_5 ( 0x0131000e , V_7 + V_8 ) ;
F_5 ( 0 , V_7 + V_9 ) ;
}
static inline void F_3 ( void ) {}
static int F_6 ( struct V_2 * V_5 )
{
return F_7 ( F_1 ( V_5 ) ) ;
}
static int F_8 ( struct V_2 * V_5 )
{
return F_9 ( F_1 ( V_5 ) ) ;
}
static bool F_10 ( struct V_2 * V_5 )
{
return F_11 ( F_1 ( V_5 ) ) ;
}
static bool F_12 ( struct V_10 * V_11 )
{
return true ;
}
static void F_13 ( struct V_4 * V_12 )
{
struct V_2 * V_5 = & V_12 -> V_5 ;
V_5 -> V_13 = V_14 ;
F_14 ( V_5 , NULL , false ) ;
V_5 -> V_15 . V_16 = F_12 ;
V_5 -> V_17 = F_6 ;
V_5 -> V_18 = F_8 ;
if ( F_10 ( & V_12 -> V_5 ) )
F_8 ( & V_12 -> V_5 ) ;
}
void T_1 F_15 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_16 ( V_20 ) ; V_19 ++ )
F_13 ( & V_20 [ V_19 ] ) ;
}
void T_1 F_17 ( void )
{
static int V_21 ;
if ( ! V_21 ++ )
F_3 () ;
}
