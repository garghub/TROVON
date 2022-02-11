static int T_1 F_1 ( int V_1 )
{
switch ( V_1 ) {
case 1 :
F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_5 ) ;
break;
case 5 :
F_2 ( V_6 , V_7 ) ;
F_3 ( V_8 , V_9 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static void T_1 F_4 ( char V_1 , int V_10 )
{
T_2 V_11 ;
V_11 = F_5 ( 2 ) ;
F_6 ( 0 , V_12 + F_7 ( V_1 ) ) ;
F_6 ( ( ( V_11 / V_10 ) / 16 ) - 1 , V_12 + F_8 ( V_1 ) ) ;
F_6 ( V_13 , V_12 + F_7 ( V_1 ) ) ;
F_6 ( V_14 | V_15 ,
V_12 + F_9 ( F_10 ( V_1 ) ) ) ;
}
static void T_1 F_11 ( char V_1 , int V_10 )
{
if ( F_1 ( V_1 ) )
return;
V_16 = V_1 ;
F_4 ( V_16 , V_10 ) ;
}
static char * T_1 F_12 ( void )
{
#ifdef F_13
return V_17 ;
#else
return F_14 () ;
#endif
}
static int T_1 F_15 ( char * V_18 )
{
char * V_19 ;
int V_1 = - 1 ;
if ( ! V_18 || * V_18 == '\0' )
goto V_20;
V_19 = strstr ( V_18 , L_1 ) ;
if ( V_19 ) {
V_19 = strstr ( V_19 , L_2 ) ;
if ( V_19 )
V_19 += 4 ;
else
goto V_20;
V_1 = ( * V_19 ) - '0' ;
}
V_20:
return V_1 ;
}
static int T_1 F_16 ( char * V_18 )
{
char * V_19 ;
int V_10 = - 1 ;
if ( ! V_18 || * V_18 == '\0' )
goto V_20;
V_19 = strstr ( V_18 , L_1 ) ;
if ( V_19 ) {
V_19 = strstr ( V_19 , L_2 ) ;
if ( V_19 )
V_19 += 6 ;
else
goto V_20;
V_10 = 0 ;
while ( * V_19 >= '0' && * V_19 <= '9' )
V_10 = V_10 * 10 + * V_19 ++ - '0' ;
}
V_20:
return V_10 ;
}
void T_1 F_17 ( char V_1 )
{
char * V_18 = F_12 () ;
int V_10 = - 1 ;
V_12 = F_18 ( V_21 , 0xc00 ) ;
V_10 = F_16 ( V_18 ) ;
if ( V_1 == - 1 )
V_1 = F_15 ( V_18 ) ;
if ( V_1 == - 1 )
V_1 = V_22 ;
if ( V_10 == - 1 )
V_10 = V_23 ;
F_11 ( V_1 , V_10 ) ;
}
int F_19 ( char V_24 )
{
if ( V_16 >= 0 ) {
while ( F_20 (
V_12 + F_10 ( V_16 ) ) & V_25 )
;
F_6 ( V_24 , V_12 + F_21 ( V_16 ) ) ;
}
return 1 ;
}
