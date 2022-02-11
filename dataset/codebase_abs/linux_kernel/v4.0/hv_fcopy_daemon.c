static int F_1 ( struct F_1 * V_1 )
{
int error = V_2 ;
char * V_3 , * V_4 ;
V_4 = ( char * ) V_1 -> V_5 ;
snprintf ( V_6 , sizeof( V_6 ) , L_1 ,
( char * ) V_1 -> V_5 , ( char * ) V_1 -> V_7 ) ;
F_2 ( V_8 , L_2 , V_6 ) ;
while ( ( V_3 = strchr ( V_4 , '/' ) ) != NULL ) {
if ( V_3 == V_4 ) {
V_4 ++ ;
continue;
}
* V_3 = '\0' ;
if ( F_3 ( ( char * ) V_1 -> V_5 , V_9 ) ) {
if ( V_1 -> V_10 & V_11 ) {
if ( F_4 ( ( char * ) V_1 -> V_5 , 0755 ) ) {
F_2 ( V_12 , L_3 ,
( char * ) V_1 -> V_5 ) ;
goto V_13;
}
} else {
F_2 ( V_12 , L_4 ,
( char * ) V_1 -> V_5 ) ;
goto V_13;
}
}
V_4 = V_3 + 1 ;
* V_3 = '/' ;
}
if ( ! F_3 ( V_6 , V_9 ) ) {
F_2 ( V_8 , L_5 , V_6 ) ;
if ( ! ( V_1 -> V_10 & V_14 ) ) {
error = V_15 ;
goto V_13;
}
}
V_16 = F_5 ( V_6 ,
V_17 | V_18 | V_19 | V_20 , 0744 ) ;
if ( V_16 == - 1 ) {
F_2 ( V_8 , L_6 , strerror ( V_21 ) ) ;
goto V_13;
}
error = 0 ;
V_13:
return error ;
}
static int F_6 ( struct V_22 * V_23 )
{
T_1 V_24 ;
V_24 = F_7 ( V_16 , V_23 -> V_25 , V_23 -> V_26 ,
V_23 -> V_27 ) ;
if ( V_24 != V_23 -> V_26 )
return V_2 ;
return 0 ;
}
static int F_8 ( void )
{
F_9 ( V_16 ) ;
return 0 ;
}
static int F_10 ( void )
{
F_9 ( V_16 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
void F_12 ( char * V_28 [] )
{
fprintf ( V_29 , L_7
L_8
L_9
L_10 , V_28 [ 0 ] ) ;
}
int main ( int V_30 , char * V_28 [] )
{
int V_31 , V_32 ;
int error ;
int V_33 = 1 , V_34 = 0 , V_35 ;
int V_36 = V_37 ;
char * V_38 [ 4096 * 2 ] ;
struct V_39 * V_40 ;
static struct V_41 V_42 [] = {
{ L_11 , V_43 , 0 , 'h' } ,
{ L_12 , V_43 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_35 = F_13 ( V_30 , V_28 , L_13 , V_42 ,
& V_34 ) ) != - 1 ) {
switch ( V_35 ) {
case 'n' :
V_33 = 0 ;
break;
case 'h' :
default:
F_12 ( V_28 ) ;
exit ( V_44 ) ;
}
}
if ( V_33 && F_14 ( 1 , 0 ) ) {
F_2 ( V_12 , L_14 , strerror ( V_21 ) ) ;
exit ( V_44 ) ;
}
F_15 ( L_15 , 0 , V_45 ) ;
F_2 ( V_8 , L_16 , F_16 () ) ;
V_31 = F_5 ( L_17 , V_17 ) ;
if ( V_31 < 0 ) {
F_2 ( V_12 , L_18 ,
V_21 , strerror ( V_21 ) ) ;
exit ( V_44 ) ;
}
if ( ( F_17 ( V_31 , & V_36 , sizeof( int ) ) ) != sizeof( int ) ) {
F_2 ( V_12 , L_19 , strerror ( V_21 ) ) ;
exit ( V_44 ) ;
}
while ( 1 ) {
V_32 = F_18 ( V_31 , V_38 , ( 4096 * 2 ) , 0 ) ;
if ( V_32 < 0 ) {
F_2 ( V_12 , L_20 , strerror ( V_21 ) ) ;
exit ( V_44 ) ;
}
V_40 = (struct V_39 * ) V_38 ;
switch ( V_40 -> V_46 ) {
case V_47 :
error = F_1 ( (struct F_1 * ) V_40 ) ;
break;
case V_48 :
error = F_6 ( (struct V_22 * ) V_40 ) ;
break;
case V_49 :
error = F_8 () ;
break;
case V_50 :
error = F_10 () ;
break;
default:
F_2 ( V_12 , L_21 ,
V_40 -> V_46 ) ;
}
if ( F_7 ( V_31 , & error , sizeof( int ) , 0 ) != sizeof( int ) ) {
F_2 ( V_12 , L_22 , strerror ( V_21 ) ) ;
exit ( V_44 ) ;
}
}
}
