static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 , L_1 ) ;
F_2 ( V_2 , L_2 ) ;
for ( V_4 = 0 ; V_4 < 32 ; V_4 ++ ) {
if ( V_5 [ V_4 ] == 0 )
continue;
F_3 ( V_2 , L_3 ,
V_4 ? 1 << ( V_4 - 1 ) : 0 , 1 << V_4 ,
V_5 [ V_4 ] ) ;
}
return 0 ;
}
static int F_4 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_5 ( V_7 , F_1 , NULL ) ;
}
static int T_1 F_6 ( void )
{
struct V_8 * V_9 ;
V_9 = F_7 ( L_4 , 0444 , NULL , NULL ,
& V_10 ) ;
if ( ! V_9 ) {
F_8 ( L_5 ) ;
return - V_11 ;
}
return 0 ;
}
void F_9 ( struct V_12 * V_13 )
{
int V_4 = F_10 ( F_11 ( V_13 -> V_14 ) , V_15 - 1 ) ;
V_5 [ V_4 ] ++ ;
F_12 ( L_6 , ( V_16 ) V_13 -> V_14 ,
V_13 -> V_17 / V_18 ) ;
}
