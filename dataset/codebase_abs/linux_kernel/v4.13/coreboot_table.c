int F_1 ( int V_1 , void * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
void * V_8 ;
int V_9 ;
if ( ! V_10 )
return - V_11 ;
F_2 ( & V_5 , V_10 , sizeof( V_5 ) ) ;
if ( strncmp ( V_5 . V_12 , L_1 , sizeof( V_5 . V_12 ) ) ) {
F_3 ( L_2 ) ;
return - V_13 ;
}
V_8 = ( void * ) V_10 + V_5 . V_14 ;
for ( V_9 = 0 ; V_9 < V_5 . V_15 ; V_9 ++ ) {
F_2 ( & V_7 , V_8 , sizeof( V_7 ) ) ;
if ( V_7 . V_1 == V_1 ) {
if ( V_3 < V_7 . V_16 )
return - V_17 ;
F_2 ( V_2 , V_8 , V_7 . V_16 ) ;
return 0 ;
}
V_8 += V_7 . V_16 ;
}
return - V_18 ;
}
int F_4 ( void T_2 * V_19 )
{
V_10 = V_19 ;
return 0 ;
}
int F_5 ( void )
{
if ( V_10 )
F_6 ( V_10 ) ;
return 0 ;
}
