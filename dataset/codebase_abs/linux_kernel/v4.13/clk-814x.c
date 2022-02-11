static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( ! V_3 )
return - V_4 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return - V_4 ;
}
F_4 ( V_2 , NULL , NULL , NULL ) ;
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_5 , V_6 ;
if ( ! V_3 )
return - V_4 ;
for ( V_5 = 0 ; V_5 < F_6 ( V_7 ) ; V_5 ++ ) {
struct V_8 * clock ;
clock = F_7 ( NULL , V_7 [ V_5 ] ) ;
if ( F_8 ( F_9 ( clock ) , L_3 ,
V_7 [ V_5 ] ) )
continue;
V_6 = F_10 ( clock ) ;
if ( F_8 ( V_6 , L_4 ,
V_7 [ V_5 ] ) )
continue;
}
return 0 ;
}
int T_1 F_11 ( void )
{
F_12 ( V_9 ) ;
F_13 () ;
F_14 ( NULL , 0 ) ;
V_3 = true ;
return 0 ;
}
