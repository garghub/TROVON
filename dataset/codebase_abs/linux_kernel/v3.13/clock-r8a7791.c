void T_1 F_1 ( void )
{
void T_2 * V_1 = F_2 ( V_2 , V_3 ) ;
T_3 V_4 ;
int V_5 , V_6 = 0 ;
F_3 ( ! V_1 ) ;
V_4 = F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
switch ( V_4 & ( F_6 ( 14 ) | F_6 ( 13 ) ) ) {
case 0 :
F_7 ( 15 , & V_7 , 172 , 208 , 106 , 88 ) ;
break;
case F_6 ( 13 ) :
F_7 ( 20 , & V_7 , 130 , 156 , 80 , 66 ) ;
break;
case F_6 ( 14 ) :
F_7 ( 26 , & V_8 , 200 , 240 , 122 , 102 ) ;
break;
case F_6 ( 13 ) | F_6 ( 14 ) :
F_7 ( 30 , & V_8 , 172 , 208 , 106 , 88 ) ;
break;
}
for ( V_5 = 0 ; ! V_6 && ( V_5 < F_8 ( V_9 ) ) ; V_5 ++ )
V_6 = F_9 ( V_9 [ V_5 ] ) ;
if ( ! V_6 )
V_6 = F_10 ( V_10 , V_11 ) ;
F_11 ( V_12 , F_8 ( V_12 ) ) ;
if ( ! V_6 )
F_12 () ;
else
goto V_13;
return;
V_13:
F_13 ( L_1 ) ;
}
