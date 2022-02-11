static int T_1 F_1 ( char * V_1 )
{
V_2 |= V_3 | V_4 ;
return 1 ;
}
static int T_1 F_2 ( char * line )
{
V_5 = V_6 ;
if ( line [ 0 ] == '/' || line [ 0 ] == ',' || ( line [ 0 ] >= '0' && line [ 0 ] <= '9' ) ) {
F_3 ( V_7 , line , sizeof( V_7 ) ) ;
} else {
T_2 V_8 = strlen ( line ) + sizeof( V_9 ) - 1 ;
if ( V_8 >= sizeof( V_7 ) )
line [ sizeof( V_7 ) - sizeof( V_9 ) - 2 ] = '\0' ;
sprintf ( V_7 , V_9 , line ) ;
}
V_10 = F_4 ( V_7 ) ;
return 1 ;
}
static int T_1 F_5 ( char * V_11 , const char * V_12 ,
const T_2 V_13 )
{
if ( F_3 ( V_11 , V_12 , V_13 ) > V_13 )
return - 1 ;
return 0 ;
}
static int T_1 F_6 ( char * V_11 , const char * V_12 ,
const T_2 V_13 )
{
T_2 V_14 = strlen ( V_11 ) ;
if ( V_14 && V_11 [ V_14 - 1 ] != ',' )
if ( F_7 ( V_11 , L_1 , V_13 ) > V_13 )
return - 1 ;
if ( F_7 ( V_11 , V_12 , V_13 ) > V_13 )
return - 1 ;
return 0 ;
}
static int T_1 F_8 ( char * V_15 , char * V_16 ,
const T_2 V_17 )
{
char * V_18 ;
V_18 = F_9 ( & V_15 , L_1 ) ;
if ( * V_18 != '\0' && strcmp ( V_18 , L_2 ) != 0 )
if ( F_5 ( V_16 , V_18 , V_17 ) )
return - 1 ;
if ( V_15 != NULL && * V_15 != '\0' )
if ( F_6 ( V_19 , V_15 ,
sizeof( V_19 ) ) )
return - 1 ;
return 0 ;
}
static int T_1 F_10 ( char * V_20 )
{
char V_21 [ sizeof( L_3 ) + V_22 + 1 ] ;
int V_14 , V_23 = - 1 ;
char * V_24 = NULL ;
const T_2 V_25 = sizeof( V_26 ) ;
V_24 = F_11 ( V_25 , V_27 ) ;
if ( V_24 == NULL )
goto V_28;
strcpy ( V_24 , V_9 ) ;
if ( V_29 [ 0 ] != '\0' ) {
F_12 ( L_4 ,
V_29 ) ;
if ( F_8 ( V_29 , V_24 , V_25 ) )
goto V_30;
}
if ( V_20 [ 0 ] != '\0' ) {
F_12 ( L_5 , V_20 ) ;
if ( F_8 ( V_20 , V_24 , V_25 ) )
goto V_30;
}
snprintf ( V_21 , sizeof( V_21 ) , L_6 ,
& V_31 ) ;
if ( F_6 ( V_19 , V_21 ,
sizeof( V_19 ) ) )
goto V_30;
V_14 = snprintf ( V_26 , sizeof( V_26 ) ,
V_24 , F_13 () -> V_32 ) ;
if ( V_14 > ( int ) sizeof( V_26 ) )
goto V_33;
V_14 = snprintf ( V_34 , sizeof( V_34 ) ,
L_7 , & V_31 , V_26 ) ;
if ( V_14 > ( int ) sizeof( V_34 ) )
goto V_33;
V_23 = 0 ;
V_35:
F_14 ( V_24 ) ;
return V_23 ;
V_28:
F_15 ( V_36 L_8 ) ;
goto V_35;
V_30:
F_15 ( V_36 L_9 ) ;
goto V_35;
V_33:
F_15 ( V_36 L_10 ) ;
goto V_35;
}
int T_1 F_16 ( char * * V_37 , char * * V_38 )
{
V_31 = V_10 ;
if ( V_31 == F_17 ( V_39 ) ) {
F_15 ( V_36 L_11 ) ;
return - 1 ;
}
if ( F_10 ( V_7 ) < 0 )
return - 1 ;
* V_37 = V_34 ;
* V_38 = V_19 ;
return 0 ;
}
