void F_1 ( void )
{
T_1 div ;
union V_1 V_2 ;
union V_3 V_4 ;
union V_5 V_6 ;
union V_7 V_8 ;
int V_9 ;
unsigned long V_10 ;
F_2 ( & V_11 ) ;
V_12 ++ ;
if ( V_12 != 1 )
goto exit;
V_10 = 64000000000ull / F_3 () ;
V_2 . T_1 = 0 ;
V_2 . V_13 . V_14 = 1 ;
F_4 ( F_5 ( 0 ) , V_2 . T_1 ) ;
V_4 . T_1 = F_6 ( F_7 ( 0 ) ) ;
if ( V_4 . V_13 . V_15 )
goto V_16;
V_4 . V_13 . V_17 = 1 ;
V_4 . V_13 . V_15 = 0 ;
V_4 . V_13 . V_18 = 0 ;
V_4 . V_13 . V_19 = 0 ;
V_4 . V_13 . V_20 = 0 ;
V_4 . V_13 . V_21 = 0 ;
V_4 . V_13 . V_22 = 0 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
V_4 . V_13 . V_23 = 0 ;
V_4 . V_13 . V_24 = 0 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
div = F_3 () / 130000000ull ;
switch ( div ) {
case 0 :
div = 1 ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
break;
case 5 :
div = 4 ;
break;
case 6 :
case 7 :
div = 6 ;
break;
case 8 :
case 9 :
case 10 :
case 11 :
div = 8 ;
break;
default:
div = 12 ;
break;
}
V_4 . V_13 . V_25 = div ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
V_4 . T_1 = F_6 ( F_7 ( 0 ) ) ;
V_4 . V_13 . V_21 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
V_4 . V_13 . V_19 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
F_8 ( V_10 ) ;
V_4 . V_13 . V_17 = 0 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
F_9 ( 1 ) ;
V_6 . T_1 = F_6 ( F_10 ( 0 ) ) ;
V_6 . V_13 . V_26 = 1 ;
F_4 ( F_10 ( 0 ) , V_6 . T_1 ) ;
F_8 ( 10 ) ;
V_6 . V_13 . V_26 = 0 ;
F_4 ( F_10 ( 0 ) , V_6 . T_1 ) ;
F_8 ( 20 ) ;
V_4 . V_13 . V_20 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
V_4 . V_13 . V_22 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
F_8 ( V_10 ) ;
V_4 . V_13 . V_18 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
F_11 ( 1 ) ;
V_4 . V_13 . V_15 = 1 ;
F_4 ( F_7 ( 0 ) , V_4 . T_1 ) ;
V_16:
for ( V_9 = 0 ; V_9 <= 1 ; V_9 ++ ) {
V_8 . T_1 =
F_6 ( F_12 ( V_9 , 0 ) ) ;
V_8 . V_13 . V_27 = 15 ;
V_8 . V_13 . V_28 = 1 ;
V_8 . V_13 . V_29 = 1 ;
F_4 ( F_12 ( V_9 , 0 ) ,
V_8 . T_1 ) ;
}
F_4 ( F_13 ( 0 ) , 0x20ull ) ;
exit:
F_14 ( & V_11 ) ;
}
void F_15 ( void )
{
F_2 ( & V_11 ) ;
V_12 -- ;
F_14 ( & V_11 ) ;
}
