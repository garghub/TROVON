static void F_1 ( unsigned long V_1 )
{
F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( L_1 ) ;
else if ( V_4 ) {
F_3 ( L_2 ) ;
F_4 ( L_3 ) ;
} else {
F_3 ( L_4 ) ;
F_5 () ;
F_3 ( L_5 ) ;
}
}
static int F_6 ( struct V_5 * V_6 )
{
if ( ! F_7 ( & V_7 , V_8 + ( V_6 -> V_9 * V_10 ) ) )
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 )
{
if ( F_10 ( & V_7 ) )
F_2 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_11 )
{
V_6 -> V_9 = V_11 ;
return 0 ;
}
static int T_1 F_12 ( void )
{
int V_12 ;
if ( V_13 < 1 || V_13 > 65535 ) {
F_13 ( L_6 ,
V_14 ) ;
return - V_15 ;
}
V_16 . V_9 = V_13 ;
F_14 ( & V_16 , V_17 ) ;
F_15 ( & V_16 ) ;
V_12 = F_16 ( & V_16 ) ;
if ( V_12 )
return V_12 ;
F_13 ( L_7 ,
V_3 , V_13 , V_4 , V_17 ) ;
return 0 ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_16 ) ;
}
