static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 = ( V_1 | V_3 |
V_4 |
V_5 |
V_6 ) ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_2 ) ;
}
static void F_4 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 = ( V_1 | V_3 |
V_4 ) ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_2 ) ;
}
void T_2 F_5 ( unsigned long V_7 , T_3 V_8 )
{
unsigned int V_1 ;
int V_9 ;
V_10 . V_8 = V_8 ;
V_11 . V_12 = V_7 ;
V_9 = F_6 ( & V_13 ) ;
if ( V_9 ) {
F_7 ( L_1 , V_9 ) ;
return;
}
V_9 = F_6 ( & V_14 ) ;
if ( V_9 ) {
F_7 ( L_2 , V_9 ) ;
F_8 ( & V_13 ) ;
return;
}
V_1 = F_2 ( V_15 ) ;
V_1 = V_1 & ( ~ ( V_16 ) ) ;
F_3 ( V_1 , V_15 ) ;
V_1 = F_2 ( V_15 ) ;
}
