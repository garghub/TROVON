void F_1 ( union V_1 * V_2 )
{
union V_1 * V_3 = V_2 ;
union V_1 * V_4 = NULL ;
union V_1 * V_5 = NULL ;
F_2 ( V_6 , V_2 ) ;
while ( V_3 ) {
if ( V_3 != V_5 ) {
V_4 = F_3 ( V_3 , 0 ) ;
if ( V_4 ) {
V_3 = V_4 ;
continue;
}
}
V_4 = V_3 -> V_7 . V_4 ;
V_5 = V_3 -> V_7 . V_5 ;
F_4 ( V_3 ) ;
if ( V_3 == V_2 ) {
V_8 ;
}
if ( V_4 ) {
V_3 = V_4 ;
} else {
V_3 = V_5 ;
}
}
V_8 ;
}
