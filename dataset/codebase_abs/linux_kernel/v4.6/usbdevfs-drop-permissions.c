void F_1 ( int V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , V_4 , & V_2 ) ;
if ( V_3 )
printf ( L_1 , V_3 ) ;
else
printf ( L_2 ) ;
}
void F_3 ( int V_1 )
{
int V_3 ;
V_3 = F_2 ( V_1 , V_5 ) ;
if ( ! V_3 )
printf ( L_3 ) ;
else
printf ( L_4 ,
- V_3 , strerror ( - V_3 ) ) ;
}
void F_4 ( int V_1 )
{
int V_6 , V_3 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_3 = F_2 ( V_1 , V_7 , & V_6 ) ;
if ( ! V_3 )
printf ( L_5 , V_6 ) ;
else
printf ( L_6 ,
V_6 , - V_3 , strerror ( - V_3 ) ) ;
}
}
int main ( int V_8 , char * V_9 [] )
{
T_1 V_2 , V_10 ;
int V_11 , V_1 ;
V_1 = F_5 ( V_9 [ 1 ] , V_12 ) ;
if ( V_1 < 0 ) {
printf ( L_7 ) ;
goto V_13;
}
F_2 ( V_1 , V_14 , & V_10 ) ;
if ( ! ( V_10 & V_15 ) ) {
printf ( L_8 ) ;
goto V_16;
}
F_1 ( V_1 , - 1U ) ;
printf ( L_9
L_10
L_11
L_12
L_13
L_14 ) ;
while ( scanf ( L_15 , & V_11 ) == 1 ) {
switch ( V_11 ) {
case 0 :
goto exit;
case 1 :
F_3 ( V_1 ) ;
break;
case 2 :
F_4 ( V_1 ) ;
break;
case 3 :
printf ( L_16 ) ;
scanf ( L_17 , & V_2 ) ;
F_1 ( V_1 , V_2 ) ;
break;
default:
printf ( L_18 ) ;
}
printf ( L_19 ) ;
}
exit:
F_6 ( V_1 ) ;
return 0 ;
V_16:
F_6 ( V_1 ) ;
V_13:
return 1 ;
}
