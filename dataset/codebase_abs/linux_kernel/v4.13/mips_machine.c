T_1 int F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
F_2 (mach) {
if ( V_3 -> V_4 == NULL )
continue;
if ( strcmp ( V_3 -> V_4 , V_1 ) == 0 ) {
V_5 = V_3 -> V_6 ;
return 0 ;
}
}
F_3 ( L_1 , V_1 ) ;
F_3 ( L_2 , L_3 , L_4 ) ;
F_2 (mach)
F_3 ( L_2 , V_3 -> V_4 , V_3 -> V_7 ) ;
return 1 ;
}
T_1 void F_4 ( void )
{
struct V_2 * V_3 ;
F_2 (mach) {
if ( V_5 == V_3 -> V_6 ) {
V_2 = V_3 ;
break;
}
}
if ( ! V_2 )
return;
F_5 ( V_2 -> V_7 ) ;
if ( V_2 -> V_8 )
V_2 -> V_8 () ;
}
