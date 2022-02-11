int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 . V_7 ; V_4 ++ ) {
if ( V_2 -> V_5 . V_6 . free [ V_4 ] ) {
V_2 -> V_5 . V_6 . free [ V_4 ] = false ;
* V_3 = V_2 -> V_5 . V_6 . V_3 [ V_4 ] ;
return 0 ;
}
}
return - V_8 ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 . V_7 ; V_4 ++ ) {
if ( V_2 -> V_5 . V_6 . V_3 [ V_4 ] == V_3 ) {
V_2 -> V_5 . V_6 . free [ V_4 ] = true ;
return;
}
}
}
