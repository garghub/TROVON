unsigned long F_1 ( void )
{
unsigned long V_1 = V_2 ;
if ( F_2 ( V_3 ) & 0x40 )
return V_1 >> 1 ;
return V_1 ;
}
unsigned long F_3 ( void )
{
switch ( F_2 ( V_3 ) & 0xc ) {
case 0 :
return V_4 ;
case 4 :
return V_2 ;
case 8 :
return V_2 << 1 ;
default:
return V_2 >> 1 ;
}
}
unsigned long F_4 ( void )
{
if ( ( ( F_2 ( V_3 ) >> 3 ) & 0x3 ) == 0x2 )
return V_5 ;
return V_4 ;
}
unsigned long F_5 ( void )
{
unsigned long V_6 = F_4 () ;
if ( F_2 ( V_3 ) & F_6 ( 0 ) )
return V_6 ;
return V_6 >> 1 ;
}
unsigned long F_7 ( void )
{
if ( F_2 ( V_3 ) & F_6 ( 2 ) )
return F_5 () ;
else
return F_4 () ;
}
unsigned long F_8 ( void )
{
unsigned int V_7 ;
unsigned long V_8 ;
V_7 = ( F_2 ( V_9 ) >> 4 ) & 0xf ;
switch ( V_7 ) {
case 0 :
V_8 = V_10 ;
break;
case 1 :
V_8 = V_11 ;
break;
case 2 :
V_8 = V_5 ;
break;
case 3 :
V_8 = V_4 ;
break;
case 5 :
case 6 :
V_8 = V_12 ;
break;
case 7 :
V_8 = V_13 ;
break;
case 4 :
case 8 :
case 9 :
V_8 = V_14 ;
break;
default:
V_8 = 0 ;
break;
}
return V_8 ;
}
unsigned long F_9 ( void )
{
unsigned int V_15 , V_16 ;
unsigned long V_8 ;
V_16 = F_8 () ;
V_15 = F_2 ( V_9 ) & 0x3 ;
switch ( V_15 ) {
case 0 :
V_8 = V_16 ;
break;
case 2 :
V_8 = V_16 / 2 ;
break;
case 3 :
V_8 = ( V_16 * 2 ) / 5 ;
break;
case 4 :
V_8 = V_16 / 3 ;
break;
default:
V_8 = 0 ;
break;
}
return V_8 ;
}
