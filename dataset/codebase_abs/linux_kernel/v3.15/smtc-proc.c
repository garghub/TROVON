static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
extern unsigned long V_5 ;
F_2 ( V_2 , L_1 , V_6 ) ;
F_2 ( V_2 , L_2 , F_3 () ) ;
F_2 ( V_2 , L_3 , V_5 ) ;
F_2 ( V_2 , L_4 ) ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_4 , V_8 [ V_4 ] . V_9 ) ;
F_2 ( V_2 , L_6 ) ;
for( V_4 = 0 ; V_4 < V_7 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_4 , V_8 [ V_4 ] . V_10 ) ;
F_2 ( V_2 , L_7 ,
F_4 ( & V_11 ) ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_6 ( V_13 , F_1 , NULL ) ;
}
void F_7 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; V_4 ++ ) {
V_8 [ V_4 ] . V_9 = 0 ;
V_8 [ V_4 ] . V_10 = 0 ;
}
F_8 ( & V_11 , 0 ) ;
F_9 ( L_8 , 0444 , NULL , & V_14 ) ;
}
static int F_10 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned long V_21 = V_20 -> V_21 ;
if ( ! V_22 )
return V_23 ;
F_2 ( V_2 , L_9 , V_24 [ V_21 ] . V_25 ) ;
F_2 ( V_2 , L_10 , V_24 [ V_21 ] . V_26 ) ;
return V_23 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( F_10 , 0 ) ;
}
