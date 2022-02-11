static void
F_1 ( T_1 V_1 )
{
int V_2 = 0 ;
while ( V_3 [ V_2 ] . V_4 != NULL ) {
if ( ( V_3 [ V_2 ] . V_5 ) == V_1 ) {
F_2 ( L_1 , V_1 ,
V_3 [ V_2 ] . V_4 ) ;
}
V_2 ++ ;
}
return;
}
int
F_3 ( char * V_6 , bool V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
unsigned int V_10 ;
int V_11 = - V_12 ;
T_1 V_13 = V_9 -> V_14 ;
if ( V_13 == 0 )
return 0 ;
if ( V_7 && ( V_13 != V_15 ) &&
( V_13 != V_16 ) )
F_1 ( V_13 ) ;
else if ( V_17 & V_18 )
F_1 ( V_13 ) ;
for ( V_10 = 0 ; V_10 < sizeof( V_3 ) /
sizeof( struct V_19 ) ; V_10 ++ ) {
if ( V_3 [ V_10 ] . V_5 == V_13 ) {
V_11 = V_3 [ V_10 ] . V_20 ;
break;
}
}
F_5 ( V_21 , L_2 ,
F_6 ( V_13 ) , V_11 ) ;
return V_11 ;
}
