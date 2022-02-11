int F_1 ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
char V_4 [ 256 ] , * V_5 ;
int V_6 = 1 ;
unsigned long V_7 ;
V_5 = F_2 ( V_1 , V_2 , V_8 ) ;
while ( ( V_3 = F_3 () ) != V_9 ) {
switch ( V_3 ) {
case V_9 :
case V_10 :
F_4 ( V_11 , L_1 , V_5 ) ;
goto V_12;
case V_13 :
F_5 ( V_8 ) ;
V_6 = 0 ;
goto V_12;
}
}
V_6 = 0 ;
for ( V_2 = F_6 () ; * V_2 ; V_2 ++ ) {
if ( sscanf ( * V_2 , L_2 , & V_7 ) == 0 )
V_6 ++ ;
else {
F_7 ( V_14
| V_15 , NULL ) ;
F_8 ( V_7 , V_4 , sizeof V_4 ) ;
F_4 ( V_16 , L_3 , V_4 ) ;
}
}
V_12:
return ( V_6 ) ;
}
