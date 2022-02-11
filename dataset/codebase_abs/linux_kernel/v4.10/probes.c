int F_1 ( T_1 * V_1 )
{
if ( ! F_2 ( ( unsigned char * ) V_1 ) )
return - V_2 ;
switch ( V_1 [ 0 ] >> 8 ) {
case 0x0c :
case 0x0b :
case 0x83 :
case 0x44 :
case 0xac :
case 0xad :
return - V_2 ;
case 0xc6 :
switch ( V_1 [ 0 ] & 0x0f ) {
case 0x00 :
return - V_2 ;
}
}
switch ( V_1 [ 0 ] ) {
case 0x0101 :
case 0xb25a :
case 0xb240 :
case 0xb258 :
case 0xb218 :
case 0xb228 :
case 0xb98d :
case 0xe560 :
case 0xe561 :
case 0xb2f8 :
return - V_2 ;
}
return 0 ;
}
int F_3 ( T_1 * V_1 )
{
int V_3 = V_4 ;
switch ( V_1 [ 0 ] >> 8 ) {
case 0x05 :
case 0x0d :
V_3 = V_5 ;
if ( ( V_1 [ 0 ] & 0x0f ) == 0 )
V_3 |= V_6 ;
break;
case 0x06 :
case 0x07 :
V_3 = V_6 ;
break;
case 0x45 :
case 0x4d :
V_3 = V_5 ;
break;
case 0x47 :
case 0x46 :
case 0x86 :
case 0x87 :
V_3 = V_6 ;
break;
case 0x82 :
V_3 = V_7 ;
break;
case 0xb2 :
if ( ( V_1 [ 0 ] & 0xff ) == 0xb2 )
V_3 = V_7 ;
break;
case 0xa7 :
if ( ( V_1 [ 0 ] & 0x0f ) == 0x05 )
V_3 |= V_5 ;
break;
case 0xc0 :
if ( ( V_1 [ 0 ] & 0x0f ) == 0x05 )
V_3 |= V_5 ;
break;
case 0xeb :
switch ( V_1 [ 2 ] & 0xff ) {
case 0x44 :
case 0x45 :
V_3 = V_6 ;
break;
}
break;
case 0xe3 :
if ( ( V_1 [ 2 ] & 0xff ) == 0x46 )
V_3 = V_6 ;
break;
case 0xec :
switch ( V_1 [ 2 ] & 0xff ) {
case 0xe5 :
case 0xe6 :
case 0xf6 :
case 0xf7 :
case 0xfc :
case 0xfd :
case 0xfe :
case 0xff :
V_3 = V_6 ;
break;
}
break;
}
return V_3 ;
}
int F_4 ( T_1 * V_1 )
{
switch ( V_1 [ 0 ] >> 8 ) {
case 0xc0 :
if ( ( V_1 [ 0 ] & 0x0f ) == 0x00 )
return true ;
break;
case 0xc4 :
switch ( V_1 [ 0 ] & 0x0f ) {
case 0x02 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x0b :
case 0x0c :
case 0x0d :
case 0x0e :
case 0x0f :
return true ;
}
break;
case 0xc6 :
switch ( V_1 [ 0 ] & 0x0f ) {
case 0x02 :
case 0x04 :
case 0x05 :
case 0x06 :
case 0x07 :
case 0x08 :
case 0x0a :
case 0x0c :
case 0x0d :
case 0x0e :
case 0x0f :
return true ;
}
break;
}
return false ;
}
