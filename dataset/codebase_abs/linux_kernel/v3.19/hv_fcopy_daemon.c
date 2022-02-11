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
void F_12 ( char * V_29 [] )
{
fprintf ( V_30 , L_8
L_9
L_10
L_11 , V_29 [ 0 ] ) ;
}
int main ( int V_31 , char * V_29 [] )
{
int V_32 , V_33 , V_34 ;
int error ;
int V_35 = 1 , V_36 = 0 , V_37 ;
int V_38 = V_39 ;
char * V_40 [ 4096 * 2 ] ;
struct V_41 * V_42 ;
static struct V_43 V_44 [] = {
{ L_12 , V_45 , 0 , 'h' } ,
{ L_13 , V_45 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_37 = F_13 ( V_31 , V_29 , L_14 , V_44 ,
& V_36 ) ) != - 1 ) {
switch ( V_37 ) {
case 'n' :
V_35 = 0 ;
break;
case 'h' :
default:
F_12 ( V_29 ) ;
exit ( V_46 ) ;
}
}
if ( V_35 && F_14 ( 1 , 0 ) ) {
F_2 ( V_13 , L_15 , strerror ( V_22 ) ) ;
exit ( V_46 ) ;
}
F_15 ( L_16 , 0 , V_47 ) ;
F_2 ( V_9 , L_17 , F_16 () ) ;
V_33 = F_5 ( L_18 , V_18 ) ;
if ( V_33 < 0 ) {
F_2 ( V_13 , L_19 ,
V_22 , strerror ( V_22 ) ) ;
exit ( V_46 ) ;
}
if ( ( F_17 ( V_33 , & V_38 , sizeof( int ) ) ) != sizeof( int ) ) {
F_2 ( V_13 , L_20 , strerror ( V_22 ) ) ;
exit ( V_46 ) ;
}
while ( 1 ) {
V_34 = F_18 ( V_33 , V_40 , ( 4096 * 2 ) , 0 ) ;
if ( V_34 < 0 ) {
F_2 ( V_13 , L_21 , strerror ( V_22 ) ) ;
exit ( V_46 ) ;
}
V_42 = (struct V_41 * ) V_40 ;
switch ( V_42 -> V_48 ) {
case V_49 :
error = F_1 ( (struct F_1 * ) V_42 ) ;
break;
case V_50 :
error = F_6 ( (struct V_23 * ) V_42 ) ;
break;
case V_51 :
error = F_8 () ;
break;
case V_52 :
error = F_10 () ;
break;
default:
F_2 ( V_13 , L_22 ,
V_42 -> V_48 ) ;
}
if ( F_7 ( V_33 , & error , sizeof( int ) , 0 ) != sizeof( int ) ) {
F_2 ( V_13 , L_23 , strerror ( V_22 ) ) ;
exit ( V_46 ) ;
}
}
}
