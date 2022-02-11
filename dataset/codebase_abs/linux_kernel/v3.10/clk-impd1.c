void F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
int V_6 ;
if ( V_2 > 3 ) {
F_2 ( L_1 ) ;
return;
}
V_4 = & V_7 [ V_2 ] ;
V_5 = F_3 ( NULL , & V_8 , V_1 ) ;
V_4 -> V_9 = V_5 ;
V_4 -> V_10 [ 0 ] = F_4 ( V_5 , NULL , L_2 , V_2 ) ;
V_5 = F_5 ( NULL , L_3 , NULL , V_11 ,
14745600 ) ;
V_4 -> V_12 = V_5 ;
V_4 -> V_10 [ 1 ] = F_4 ( V_5 , NULL , L_4 , V_2 ) ;
V_4 -> V_10 [ 2 ] = F_4 ( V_5 , NULL , L_5 , V_2 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_4 -> V_10 ) ; V_6 ++ )
F_7 ( V_4 -> V_10 [ V_6 ] ) ;
}
void F_8 ( unsigned int V_2 )
{
int V_6 ;
struct V_3 * V_4 ;
if ( V_2 > 3 )
return;
V_4 = & V_7 [ V_2 ] ;
for ( V_6 = 0 ; V_6 < F_6 ( V_4 -> V_10 ) ; V_6 ++ )
F_9 ( V_4 -> V_10 [ V_6 ] ) ;
F_10 ( V_4 -> V_12 ) ;
F_10 ( V_4 -> V_9 ) ;
}
