static int T_1 F_1 ( void )
{
struct V_1 T_2 * V_2 ;
struct V_3 * V_4 ;
const T_3 * V_5 ;
T_4 V_6 ;
int V_7 , V_8 , V_9 ;
V_4 = F_2 ( NULL , V_10 ) ;
if ( ! V_4 )
return 0 ;
V_2 = F_3 ( V_4 , 0 ) ;
if ( ! V_2 )
return 0 ;
V_9 = F_4 ( V_4 , L_1 , & V_6 , 1 ) ;
if ( ! V_9 )
F_5 ( V_6 , V_11 ) ;
V_5 = F_6 ( V_4 , L_2 , & V_8 ) ;
if ( V_5 ) {
V_8 /= sizeof( T_4 ) ;
if ( V_8 > V_12 )
V_8 = V_12 ;
for ( V_7 = 0 ; V_7 <= V_8 ; V_7 ++ )
F_7 ( F_8 ( & V_5 [ V_7 ] ) , & V_2 -> V_13 [ V_7 ] ) ;
}
V_9 = F_4 ( V_4 , L_3 , & V_6 , 1 ) ;
if ( ! V_9 )
F_7 ( V_6 , & V_2 -> V_14 ) ;
V_9 = F_4 ( V_4 , L_4 , & V_6 , 1 ) ;
if ( ! V_9 )
F_7 ( V_6 , & V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
