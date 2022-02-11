T_1 void F_1 ( const char * V_1 )
{
char * V_2 ;
if ( V_1 == NULL )
return;
V_2 = F_2 ( V_1 , V_3 ) ;
if ( ! V_2 )
F_3 ( L_1 ) ;
V_4 = V_2 ;
}
char * F_4 ( void )
{
return V_4 ;
}
T_1 int F_5 ( char * V_5 )
{
struct V_6 * V_7 ;
F_6 (mach) {
if ( V_7 -> V_8 == NULL )
continue;
if ( strcmp ( V_7 -> V_8 , V_5 ) == 0 ) {
V_9 = V_7 -> V_10 ;
return 0 ;
}
}
F_3 ( L_2 , V_5 ) ;
F_3 ( L_3 , L_4 , L_5 ) ;
F_6 (mach)
F_3 ( L_3 , V_7 -> V_8 , V_7 -> V_11 ) ;
return 1 ;
}
T_1 void F_7 ( void )
{
struct V_6 * V_7 ;
F_6 (mach) {
if ( V_9 == V_7 -> V_10 ) {
V_6 = V_7 ;
break;
}
}
if ( ! V_6 )
return;
F_1 ( V_6 -> V_11 ) ;
F_8 ( L_6 , V_4 ) ;
if ( V_6 -> V_12 )
V_6 -> V_12 () ;
}
