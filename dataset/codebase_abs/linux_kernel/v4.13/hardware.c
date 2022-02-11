const char * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
for ( V_4 = V_5 ; V_4 -> V_6 != V_7 ; V_4 ++ ) {
if ( ( V_4 -> V_6 == V_2 -> V_6 ) &&
( V_4 -> V_8 == V_2 -> V_8 ) &&
( V_4 -> V_9 == V_2 -> V_9 ) ) {
return V_4 -> V_10 ;
}
}
switch ( V_2 -> V_6 ) {
case V_11 :
return L_1 ;
case V_12 :
switch ( V_2 -> V_9 ) {
case 0x0D : return L_2 ;
case 0x0E : return L_3 ;
}
break;
case V_13 :
return L_4 ;
}
return L_5 ;
}
enum V_14
F_2 ( unsigned long V_8 )
{
struct V_15 * V_16 ;
unsigned short V_17 = ( ( unsigned short ) ( V_8 ) ) >> 4 ;
for ( V_16 = V_18 ; 0 != V_16 -> V_19 ; V_16 ++ ) {
if ( V_16 -> V_17 == ( V_17 & V_16 -> V_19 ) )
return V_16 -> V_20 ;
}
F_3 ( L_6 ) ;
return V_21 ;
}
