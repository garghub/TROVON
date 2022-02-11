static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
unsigned long * V_6 ;
int V_7 , V_8 ;
V_8 = V_4 / sizeof( unsigned long ) ;
V_6 = ( unsigned long * ) V_3 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
F_2 ( V_6 ++ ) ;
return V_8 * sizeof( unsigned long ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
F_4 ( & V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_12 ;
V_12 = F_6 ( & V_11 ) ;
if ( V_12 ) {
if ( V_12 == - V_13 )
V_12 = - V_14 ;
return V_12 ;
}
F_7 ( L_1 ) ;
return 0 ;
}
