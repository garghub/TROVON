static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_5 , struct V_6 * V_6 )
{
return F_4 ( V_6 , F_1 , NULL ) ;
}
static T_1 F_5 ( struct V_6 * V_6 ,
const char T_2 * V_7 , T_3 V_8 , T_4 * V_9 )
{
char V_10 ;
if ( F_6 ( V_10 , V_7 ) )
return - V_11 ;
if ( V_10 < '0' || V_10 > '9' )
return - V_12 ;
V_4 = V_10 - '0' ;
return V_8 ;
}
void F_7 ( void )
{
int V_13 ;
if ( ! ( V_14 = F_8 ( L_2 , NULL ) ) )
return;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
F_9 ( V_16 [ V_13 ] . V_17 , 0 , V_14 , V_16 [ V_13 ] . V_18 ) ;
}
void F_10 ( void )
{
int V_13 ;
if ( V_14 ) {
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
F_11 ( V_16 [ V_13 ] . V_17 , V_14 ) ;
F_11 ( L_2 , NULL ) ;
}
}
