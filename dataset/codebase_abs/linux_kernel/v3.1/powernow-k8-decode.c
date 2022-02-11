static int F_1 ( T_1 V_1 , T_1 * V_2 , T_1 * V_3 )
{
int V_4 = 1 ;
T_2 V_5 = 0 ;
int V_6 ;
char V_7 [ 20 ] ;
if ( V_1 > V_8 )
goto V_9;
sprintf ( V_7 , L_1 , V_1 ) ;
V_6 = F_2 ( V_7 , V_10 ) ;
if ( V_6 < 0 )
goto V_9;
F_3 ( V_6 , V_11 , V_12 ) ;
if ( F_4 ( V_6 , & V_5 , 8 ) != 8 )
goto V_13;
* V_2 = ( ( T_1 ) ( V_5 & 0xffffffffull ) ) & V_14 ;
* V_3 = ( ( T_1 ) ( V_5 >> 32 & 0xffffffffull ) ) & V_15 ;
V_4 = 0 ;
V_13:
F_5 ( V_6 ) ;
V_9:
return V_4 ;
}
static T_1 F_6 ( T_1 V_2 )
{
return 800 + ( V_2 * 100 ) ;
}
static T_1 F_7 ( T_1 V_3 )
{
return 1550 - V_3 * 25 ;
}
int main ( int V_16 , char * V_17 [] )
{
int V_4 ;
int V_1 ;
T_1 V_2 , V_3 ;
if ( V_16 < 2 )
V_1 = 0 ;
else
V_1 = strtoul ( V_17 [ 1 ] , NULL , 0 ) ;
V_4 = F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_4 ) {
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
exit ( 1 ) ;
}
printf ( L_5 ,
V_1 ,
F_6 ( V_2 ) ,
F_7 ( V_3 ) ) ;
return 0 ;
}
