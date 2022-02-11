void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const char * * V_6 ;
int V_7 , V_8 ;
if ( ! V_2 -> V_9 ) {
F_2 ( & V_4 -> V_10 , L_1 ) ;
return;
}
V_7 = F_3 ( V_2 -> V_9 , L_2 ,
NULL , 0 ) ;
if ( V_7 < 0 )
return;
if ( V_7 != V_4 -> V_11 ) {
F_2 ( V_2 -> V_9 ,
L_3 , V_7 ,
V_4 -> V_11 ) ;
return;
}
V_6 = F_4 ( V_4 -> V_11 , sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 )
return;
V_7 = F_3 ( V_2 -> V_9 , L_2 ,
V_6 , V_4 -> V_11 ) ;
if ( V_7 < 0 ) {
F_2 ( V_2 -> V_9 , L_4 ) ;
F_5 ( V_6 ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ )
V_4 -> V_13 [ V_8 ] . V_14 = V_6 [ V_8 ] ;
F_5 ( V_6 ) ;
}
