T_1 void F_1 ( void )
{
unsigned short V_1 ;
if ( F_2 ( V_2 ) & V_3 )
V_1 = F_3 ( V_4 ) ;
else
V_1 = F_3 ( V_5 ) ;
switch ( V_1 ) {
case 0x3380 :
case 0x3384 :
case 0x3388 :
case 0x338c :
case 0x3382 :
case 0x3386 :
case 0x338a :
case 0x338e :
return;
case 0x3310 :
case 0x3312 :
case 0x3314 :
case 0x3318 :
case 0x331a :
case 0x331c :
case 0x33c0 :
case 0x33c2 :
case 0x33c4 :
case 0x33c8 :
case 0x33ca :
case 0x33cc :
case 0x33b0 :
case 0x33b2 :
case 0x33b4 :
case 0x33b8 :
case 0x33ba :
case 0x33bc :
case 0x3320 :
case 0x3322 :
case 0x3324 :
case 0x3328 :
case 0x332a :
case 0x332c :
F_4 ( & V_6 ) ;
return;
default:
F_4 ( & V_6 ) ;
F_4 ( & V_7 ) ;
F_4 ( & V_8 ) ;
F_4 ( & V_9 ) ;
return;
}
}
