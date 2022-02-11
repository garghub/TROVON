static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned long V_4 [ V_5 ] ;
struct V_6 * V_6 = V_2 -> V_7 ;
int V_8 ;
memset ( V_4 , 0 , sizeof( unsigned long ) * V_5 ) ;
F_2 ( V_4 , V_9 ,
V_6 -> V_10 . V_11 ) ;
for ( V_8 = 0 ; V_9 [ V_8 ] . V_12 ; V_8 ++ )
F_3 ( V_2 , L_1 , V_9 [ V_8 ] . V_12 ,
V_4 [ V_8 ] ) ;
return 0 ;
}
static int F_4 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
return F_5 ( V_13 , V_14 , F_1 ) ;
}
int T_1 F_6 ( struct V_6 * V_6 )
{
if ( ! F_7 ( L_2 , V_15 , V_6 -> V_16 ,
& V_17 ) )
return - V_18 ;
return 0 ;
}
void F_8 ( struct V_6 * V_6 )
{
F_9 ( L_2 , V_6 -> V_16 ) ;
}
