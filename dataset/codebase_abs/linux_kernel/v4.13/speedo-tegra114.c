static void T_1 F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
T_2 V_4 ;
T_2 V_5 = V_2 -> V_6 ;
enum V_7 V_8 = V_2 -> V_9 ;
switch ( V_5 ) {
case 0x00 :
case 0x10 :
case 0x05 :
case 0x06 :
V_2 -> V_10 = 1 ;
V_2 -> V_11 = 0 ;
* V_3 = V_12 ;
break;
case 0x03 :
case 0x04 :
V_2 -> V_10 = 2 ;
V_2 -> V_11 = 1 ;
* V_3 = V_13 ;
break;
default:
F_2 ( L_1 , V_5 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
* V_3 = V_12 ;
break;
}
if ( V_8 == V_14 ) {
V_4 = F_3 ( 0x270 ) << 1 ;
V_4 |= F_3 ( 0x26c ) ;
if ( ! V_4 )
V_2 -> V_10 = 0 ;
}
}
void T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_2 V_16 ;
int V_3 ;
int V_17 ;
F_5 ( F_6 ( V_18 ) !=
V_19 ) ;
F_5 ( F_6 ( V_20 ) !=
V_19 ) ;
F_1 ( V_2 , & V_3 ) ;
V_15 = F_3 ( 0x12c ) + 1024 ;
V_16 = F_3 ( 0x134 ) ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ )
if ( V_15 < V_18 [ V_3 ] [ V_17 ] )
break;
V_2 -> V_22 = V_17 ;
for ( V_17 = 0 ; V_17 < V_23 ; V_17 ++ )
if ( V_16 < V_20 [ V_3 ] [ V_17 ] )
break;
V_2 -> V_24 = V_17 ;
}
