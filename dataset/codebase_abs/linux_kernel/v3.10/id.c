unsigned int F_1 ( void )
{
return V_1 ;
}
static T_1 T_2 F_2 ( void )
{
T_3 V_2 , V_3 ;
V_2 = F_3 ( V_4 ) ;
V_3 = F_3 ( V_5 ) ;
if ( ( ( V_2 >> 20 ) == 0 ) || ( V_2 == V_3 ) )
V_2 = 0 ;
else
V_2 &= 0xffff ;
if ( V_2 )
return V_2 ;
V_2 = ( ( V_3 >> 12 ) & 0xffff ) ;
return V_2 ;
}
static T_4 T_2 F_4 ( void )
{
T_3 V_6 ;
V_6 = F_3 ( V_7 ) ;
if ( ( ( V_6 >> 12 ) & 0xffff ) == F_2 () )
V_6 = 0 ;
V_6 = ( V_6 >> 17 ) & 0xf ;
if ( V_6 )
return V_6 ;
V_6 = ( F_3 ( V_5 ) >> 28 ) & 0xf ;
return V_6 ;
}
void T_2 F_5 ( void )
{
int V_8 ;
T_1 V_9 ;
T_4 V_6 ;
T_3 V_3 ;
T_4 V_10 ;
V_9 = F_2 () ;
V_6 = F_4 () ;
V_3 = F_3 ( V_11 ) ;
#ifdef F_6
F_7 ( V_12 L_1 , F_3 ( V_13 ) ) ;
F_7 ( V_12 L_2 ,
F_3 ( V_7 ) ,
( F_3 ( V_7 ) >> 17 ) & 0xf ) ;
F_7 ( V_12 L_3 ,
F_3 ( V_14 ) ) ;
F_7 ( V_12 L_4 ,
F_3 ( V_4 ) ,
F_3 ( V_4 ) & 0xffff ) ;
F_7 ( V_12 L_5 , F_3 ( V_11 ) ) ;
F_7 ( V_12 L_6 , F_3 ( V_5 ) ) ;
F_7 ( V_12 L_7 , V_9 , V_6 ) ;
#endif
V_15 = F_3 ( V_13 ) ;
V_16 = F_3 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < F_8 ( V_17 ) ; V_8 ++ ) {
if ( V_9 == ( V_17 [ V_8 ] . V_9 ) ) {
V_1 = V_17 [ V_8 ] . type ;
break;
}
}
for ( V_8 = 0 ; V_8 < F_8 ( V_17 ) ; V_8 ++ ) {
if ( V_9 == V_17 [ V_8 ] . V_9 && V_6 == V_17 [ V_8 ] . V_6 ) {
V_1 = V_17 [ V_8 ] . type ;
break;
}
}
for ( V_8 = 0 ; V_8 < F_8 ( V_17 ) ; V_8 ++ ) {
if ( V_9 == V_17 [ V_8 ] . V_9
&& V_6 == V_17 [ V_8 ] . V_6
&& V_3 == V_17 [ V_8 ] . V_3 ) {
V_1 = V_17 [ V_8 ] . type ;
break;
}
}
V_10 = V_1 >> 24 ;
switch ( V_10 ) {
case 0x07 :
case 0x08 :
V_1 |= 0x07 ;
break;
case 0x03 :
case 0x15 :
V_1 |= 0x15 ;
break;
case 0x16 :
case 0x17 :
V_1 |= 0x16 ;
break;
default:
F_7 ( V_18 L_8 , V_10 ) ;
}
F_7 ( V_18 L_9 , V_1 >> 16 ) ;
if ( ( V_1 >> 8 ) & 0xff )
F_7 ( V_18 L_10 , ( V_1 >> 8 ) & 0xff ) ;
F_7 ( V_18 L_11 ,
V_6 , V_1 & 0xff , V_16 ,
V_15 ) ;
}
