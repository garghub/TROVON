void F_1 ( int V_1 , int V_2 )
{
void T_1 * V_3 = F_2 ( V_4 , 0xF4 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ ) {
if ( V_6 [ V_5 ] . V_1 == V_1 ) {
F_4 ( V_2 , V_3 + V_6 [ V_5 ] . V_7 ) ;
return;
}
}
F_5 ( V_3 ) ;
}
void F_6 ( int V_1 , int V_2 )
{
void T_1 * V_3 = F_2 ( V_4 , 0x170 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_8 ) ; V_5 ++ ) {
if ( V_8 [ V_5 ] . V_2 == V_2 ) {
F_4 ( V_1 ,
V_3 + V_8 [ V_5 ] . V_7 ) ;
return;
}
}
F_5 ( V_3 ) ;
}
