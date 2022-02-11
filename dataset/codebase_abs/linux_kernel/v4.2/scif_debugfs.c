static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 ,
V_5 . V_6 , V_5 . V_7 ,
V_5 . V_8 ) ;
if ( ! V_9 )
return 0 ;
F_2 ( V_2 , L_2 , L_3 , L_4 ) ;
for ( V_4 = 0 ; V_4 <= V_5 . V_8 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_9 [ V_4 ] . V_4 ,
F_3 ( & V_9 [ V_4 ] ) ?
L_6 : L_7 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_5 ( V_11 , F_1 , V_10 -> V_12 ) ;
}
static int F_6 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_7 ( V_10 , V_11 ) ;
}
void T_1 F_8 ( void )
{
struct V_13 * V_14 ;
V_15 = F_9 ( V_16 , NULL ) ;
if ( ! V_15 ) {
F_10 ( V_5 . V_17 . V_18 ,
L_8 ) ;
return;
}
V_14 = F_11 ( L_9 , 0444 , V_15 ,
NULL , & V_19 ) ;
F_12 ( L_10 , 0666 , V_15 , & V_5 . V_20 ) ;
F_12 ( L_11 , 0666 , V_15 , & V_5 . V_21 ) ;
}
void F_13 ( void )
{
F_14 ( V_15 ) ;
}
