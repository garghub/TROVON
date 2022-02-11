static bool F_1 ( T_1 V_1 )
{
return
V_1 == 0xf0 || V_1 == 0xf2 || V_1 == 0xf3
|| V_1 == 0x2e || V_1 == 0x36 || V_1 == 0x3e || V_1 == 0x26
|| V_1 == 0x64 || V_1 == 0x65
|| V_1 == 0x66
|| V_1 == 0x67 ;
}
static bool F_2 ( T_1 V_1 )
{
return ( V_1 & 0xf0 ) == 0x40 ;
}
static bool F_2 ( T_1 V_1 )
{
return false ;
}
void F_3 ( const T_1 * V_2 , unsigned int * V_3 )
{
int V_4 = 4 ;
for (; F_1 ( * V_2 ) ; ++ V_2 ) {
if ( * V_2 == 0x66 )
V_4 = 2 ;
}
if ( F_2 ( * V_2 ) ) {
T_1 V_5 = * V_2 ;
++ V_2 ;
if ( V_5 & V_6 ) {
switch ( * V_2 ) {
case 0x63 :
* V_3 = 4 ;
return;
case 0x0f :
++ V_2 ;
switch ( * V_2 ) {
case 0xb6 :
case 0xbe :
* V_3 = 1 ;
return;
case 0xb7 :
case 0xbf :
* V_3 = 2 ;
return;
}
break;
}
* V_3 = 8 ;
return;
}
}
if ( * V_2 == 0x0f ) {
++ V_2 ;
if ( * V_2 == 0xb7 || * V_2 == 0xbf )
V_4 = 2 ;
}
* V_3 = ( * V_2 & 1 ) ? V_4 : 1 ;
}
const T_1 * F_4 ( const T_1 * V_2 )
{
while ( F_1 ( * V_2 ) )
++ V_2 ;
if ( F_2 ( * V_2 ) )
++ V_2 ;
return V_2 ;
}
