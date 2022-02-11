static void F_1 ( int V_1 , int V_2 , int * V_3 )
{
T_1 V_4 ;
switch ( V_2 ) {
case 0x00 :
case 0x10 :
case 0x05 :
case 0x06 :
V_5 = 1 ;
V_6 = 0 ;
* V_3 = V_7 ;
break;
case 0x03 :
case 0x04 :
V_5 = 2 ;
V_6 = 1 ;
* V_3 = V_8 ;
break;
default:
F_2 ( L_1 , V_2 ) ;
V_5 = 0 ;
V_6 = 0 ;
* V_3 = V_7 ;
break;
}
if ( V_1 == V_9 ) {
V_4 = F_3 ( 0x270 ) << 1 ;
V_4 |= F_3 ( 0x26c ) ;
if ( ! V_4 )
V_5 = 0 ;
}
}
void F_4 ( void )
{
T_1 V_10 ;
T_1 V_11 ;
int V_3 ;
int V_12 ;
F_5 ( F_6 ( V_13 ) !=
V_14 ) ;
F_5 ( F_6 ( V_15 ) !=
V_14 ) ;
F_1 ( V_16 , V_17 , & V_3 ) ;
V_10 = F_3 ( 0x12c ) + 1024 ;
V_11 = F_3 ( 0x134 ) ;
for ( V_12 = 0 ; V_12 < V_18 ; V_12 ++ )
if ( V_10 < V_13 [ V_3 ] [ V_12 ] )
break;
V_19 = V_12 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ )
if ( V_11 < V_15 [ V_3 ] [ V_12 ] )
break;
V_21 = V_12 ;
}
