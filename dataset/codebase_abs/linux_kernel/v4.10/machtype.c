const char * F_1 ( void )
{
return V_1 [ V_2 ] ;
}
void __weak T_1 F_2 ( void )
{
}
void T_1 F_3 ( void )
{
char * V_3 , V_4 [ V_5 + 1 ] ;
int V_6 = V_7 ;
V_2 = V_8 ;
V_3 = strstr ( V_9 , L_1 ) ;
if ( ! V_3 ) {
F_2 () ;
return;
}
V_3 += strlen ( L_1 ) ;
strncpy ( V_4 , V_3 , V_5 ) ;
V_4 [ V_5 ] = '\0' ;
V_3 = strstr ( V_4 , L_2 ) ;
if ( V_3 )
* V_3 = '\0' ;
for (; V_1 [ V_6 ] ; V_6 ++ )
if ( strstr ( V_1 [ V_6 ] , V_4 ) ) {
V_2 = V_6 ;
break;
}
}
