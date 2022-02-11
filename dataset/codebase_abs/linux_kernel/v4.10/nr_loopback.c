void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static inline int F_3 ( void )
{
return F_4 ( & V_2 ) ;
}
int F_5 ( struct V_3 * V_4 )
{
struct V_3 * V_5 ;
if ( ( V_5 = F_6 ( V_4 -> V_6 , V_7 ) ) != NULL ) {
F_7 ( V_4 , F_8 ( V_5 , V_4 -> V_6 ) , V_4 -> V_6 ) ;
F_9 ( V_5 ) ;
F_10 ( & V_1 , V_5 ) ;
if ( ! F_3 () )
F_11 ( & V_2 , V_8 + 10 ) ;
}
F_12 ( V_4 ) ;
return 1 ;
}
static void F_13 ( unsigned long V_9 )
{
struct V_3 * V_4 ;
T_2 * V_10 ;
struct V_11 * V_12 ;
if ( ( V_4 = F_14 ( & V_1 ) ) != NULL ) {
V_10 = ( T_2 * ) ( V_4 -> V_13 + 7 ) ;
V_12 = F_15 ( V_10 ) ;
if ( V_12 == NULL || F_16 ( V_4 , V_12 ) == 0 )
F_12 ( V_4 ) ;
if ( V_12 != NULL )
F_17 ( V_12 ) ;
if ( ! F_18 ( & V_1 ) && ! F_3 () )
F_11 ( & V_2 , V_8 + 10 ) ;
}
}
void T_3 F_19 ( void )
{
F_20 ( & V_2 ) ;
F_21 ( & V_1 ) ;
}
