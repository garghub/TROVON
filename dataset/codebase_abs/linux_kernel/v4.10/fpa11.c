static void F_1 ( void )
{
int V_1 ;
T_1 * V_2 = F_2 () ;
for ( V_1 = 0 ; V_1 <= 7 ; V_1 ++ ) {
V_2 -> V_3 [ V_1 ] = V_4 ;
}
V_2 -> V_5 = V_6 | V_7 ;
}
T_2 F_3 ( const unsigned int V_8 )
{
switch ( V_8 & V_9 ) {
default:
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
}
}
T_2 F_4 ( const unsigned int V_8 )
{
#ifdef F_5
switch ( V_8 & V_18 ) {
case V_19 :
return 32 ;
case V_20 :
return 64 ;
case V_21 :
return 80 ;
default:
return 80 ;
}
#endif
return 80 ;
}
void F_6 ( union V_22 * V_23 )
{
T_1 * V_2 = ( T_1 * ) V_23 ;
#ifdef F_7
F_8 ( L_1 ) ;
#endif
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
F_1 () ;
V_2 -> V_24 = 1 ;
}
unsigned int F_9 ( unsigned int V_8 )
{
unsigned int V_25 ;
#ifdef F_7
F_8 ( L_2 , V_8 ) ;
#endif
V_25 = V_8 & 0x00000f00 ;
if ( V_25 == 0x00000100 || V_25 == 0x00000200 ) {
V_25 = V_8 & 0x0e000000 ;
if ( V_25 == 0x0e000000 ) {
if ( V_8 & 0x00000010 ) {
return F_10 ( V_8 ) ;
} else {
return F_11 ( V_8 ) ;
}
} else if ( V_25 == 0x0c000000 ) {
return F_12 ( V_8 ) ;
}
}
return 0 ;
}
