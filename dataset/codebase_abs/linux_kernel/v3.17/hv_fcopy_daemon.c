static int F_1 ( struct F_1 * V_1 )
{
int error = V_2 ;
char * V_3 , * V_4 ;
if ( strlen ( ( char * ) V_1 -> V_5 ) < ( V_6 - 2 ) )
strcat ( ( char * ) V_1 -> V_5 , L_1 ) ;
V_4 = ( char * ) V_1 -> V_5 ;
snprintf ( V_7 , sizeof( V_7 ) , L_2 ,
( char * ) V_1 -> V_5 , V_1 -> V_8 ) ;
F_2 ( V_9 , L_3 , V_7 ) ;
while ( ( V_3 = strchr ( V_4 , '/' ) ) != NULL ) {
if ( V_3 == V_4 ) {
V_4 ++ ;
continue;
}
* V_3 = '\0' ;
if ( F_3 ( ( char * ) V_1 -> V_5 , V_10 ) ) {
if ( V_1 -> V_11 & V_12 ) {
if ( F_4 ( ( char * ) V_1 -> V_5 , 0755 ) ) {
F_2 ( V_13 , L_4 ,
( char * ) V_1 -> V_5 ) ;
goto V_14;
}
} else {
F_2 ( V_13 , L_5 ,
( char * ) V_1 -> V_5 ) ;
goto V_14;
}
}
V_4 = V_3 + 1 ;
* V_3 = '/' ;
}
if ( ! F_3 ( V_7 , V_10 ) ) {
F_2 ( V_9 , L_6 , V_7 ) ;
if ( ! ( V_1 -> V_11 & V_15 ) ) {
error = V_16 ;
goto V_14;
}
}
V_17 = F_5 ( V_7 ,
V_18 | V_19 | V_20 | V_21 , 0744 ) ;
if ( V_17 == - 1 ) {
F_2 ( V_9 , L_7 , strerror ( V_22 ) ) ;
goto V_14;
}
error = 0 ;
V_14:
return error ;
}
static int F_6 ( struct V_23 * V_24 )
{
T_1 V_25 ;
V_25 = F_7 ( V_17 , V_24 -> V_26 , V_24 -> V_27 ,
V_24 -> V_28 ) ;
if ( V_25 != V_24 -> V_27 )
return V_2 ;
return 0 ;
}
static int F_8 ( void )
{
F_9 ( V_17 ) ;
return 0 ;
}
static int F_10 ( void )
{
F_9 ( V_17 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
int main ( void )
{
int V_29 , V_30 , V_31 ;
int error ;
int V_32 = V_33 ;
char * V_34 [ 4096 * 2 ] ;
struct V_35 * V_36 ;
if ( F_12 ( 1 , 0 ) ) {
F_2 ( V_13 , L_8 , strerror ( V_22 ) ) ;
exit ( V_37 ) ;
}
F_13 ( L_9 , 0 , V_38 ) ;
F_2 ( V_9 , L_10 , F_14 () ) ;
V_30 = F_5 ( L_11 , V_18 ) ;
if ( V_30 < 0 ) {
F_2 ( V_13 , L_12 ,
V_22 , strerror ( V_22 ) ) ;
exit ( V_37 ) ;
}
if ( ( F_15 ( V_30 , & V_32 , sizeof( int ) ) ) != sizeof( int ) ) {
F_2 ( V_13 , L_13 , strerror ( V_22 ) ) ;
exit ( V_37 ) ;
}
while ( 1 ) {
V_31 = F_16 ( V_30 , V_34 , ( 4096 * 2 ) , 0 ) ;
if ( V_31 < 0 ) {
F_2 ( V_13 , L_14 , strerror ( V_22 ) ) ;
exit ( V_37 ) ;
}
V_36 = (struct V_35 * ) V_34 ;
switch ( V_36 -> V_39 ) {
case V_40 :
error = F_1 ( (struct F_1 * ) V_36 ) ;
break;
case V_41 :
error = F_6 ( (struct V_23 * ) V_36 ) ;
break;
case V_42 :
error = F_8 () ;
break;
case V_43 :
error = F_10 () ;
break;
default:
F_2 ( V_13 , L_15 ,
V_36 -> V_39 ) ;
}
if ( F_7 ( V_30 , & error , sizeof( int ) , 0 ) != sizeof( int ) ) {
F_2 ( V_13 , L_16 , strerror ( V_22 ) ) ;
exit ( V_37 ) ;
}
}
}
