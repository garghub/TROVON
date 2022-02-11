int F_1 ( void )
{
return 1 ;
}
void F_2 ( void )
{
T_1 * V_1 = F_3 () ;
if ( V_1 != NULL ) {
T_2 * V_2 = & V_1 -> V_3 ;
if ( V_2 != NULL && V_2 -> V_2 != NULL && V_2 -> V_4 ) {
F_4 () ;
V_2 -> V_2 = NULL ;
}
}
}
int F_5 ( T_2 * V_2 )
{
V_2 -> V_2 = F_6 ( NULL ) ;
if ( V_2 -> V_2 == NULL ) {
V_2 -> V_4 = 0 ;
V_2 -> V_2 = F_7 () ;
if ( V_2 -> V_2 == NULL )
return 0 ;
} else {
V_2 -> V_4 = 1 ;
}
return 1 ;
}
VOID T_3 F_8 ( T_4 V_5 )
{
F_9 () ;
}
