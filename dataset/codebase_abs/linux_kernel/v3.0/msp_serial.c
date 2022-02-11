void T_1 F_1 ( void )
{
char * V_1 ;
char * V_2 ;
struct V_3 V_4 ;
unsigned int V_5 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_1 = F_2 ( L_1 ) ;
if( ! ( V_1 && * V_1 && ( V_5 = F_3 ( V_1 , & V_2 , 10 ) ) && * V_2 == 0 ) )
V_5 = V_6 ;
F_4 ( L_2 , V_5 ) ;
V_4 . V_7 = V_8 ;
V_4 . V_9 = F_5 ( V_4 . V_7 , V_10 ) ;
V_4 . V_11 = V_12 ;
V_4 . V_5 = V_5 ;
V_4 . V_13 = 2 ;
V_4 . V_14 = V_15 ;
V_4 . V_16 = V_17 | V_18 ;
V_4 . type = V_19 ;
V_4 . line = 0 ;
V_4 . V_20 = ( void * ) V_21 ;
if ( F_6 ( & V_4 ) )
F_7 ( V_22 L_3 ) ;
switch ( V_23 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
* V_30 = 0x00002299 ;
break;
default:
return;
}
V_4 . V_7 = V_31 ;
V_4 . V_9 = F_5 ( V_4 . V_7 , V_10 ) ;
V_4 . V_11 = V_32 ;
V_4 . line = 1 ;
V_4 . V_20 = ( void * ) V_33 ;
if ( F_6 ( & V_4 ) )
F_7 ( V_22 L_4 ) ;
}
