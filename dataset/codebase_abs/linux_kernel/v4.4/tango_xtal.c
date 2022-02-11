static unsigned long T_1 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static T_2 T_1 F_3 ( void )
{
return F_1 () ;
}
static T_3 F_4 ( struct V_2 * V_3 )
{
return F_1 () ;
}
static void T_4 F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_6 ;
int V_7 , V_8 ;
V_1 = F_6 ( V_5 , 0 ) ;
if ( V_1 == NULL ) {
F_7 ( L_1 , V_5 -> V_9 ) ;
return;
}
V_6 = F_8 ( V_5 , 0 ) ;
if ( F_9 ( V_6 ) ) {
F_7 ( L_2 , V_5 -> V_9 ) ;
return;
}
V_7 = F_10 ( V_6 ) ;
V_10 . V_11 = V_7 ;
V_10 . V_12 = F_1 ;
V_8 = F_11 ( & V_13 , V_7 ) ;
if ( V_8 != 0 ) {
F_7 ( L_3 , V_5 -> V_9 ) ;
return;
}
F_12 ( F_3 , 32 , V_7 ) ;
F_13 ( & V_10 ) ;
}
