static int F_1 ( struct F_1 * V_1 )
{
int error = V_2 ;
char * V_3 , * V_4 ;
V_5 = 0 ;
V_4 = ( char * ) V_1 -> V_6 ;
snprintf ( V_7 , sizeof( V_7 ) , L_1 ,
( char * ) V_1 -> V_6 , ( char * ) V_1 -> V_8 ) ;
F_2 ( V_9 , L_2 , V_7 ) ;
while ( ( V_3 = strchr ( V_4 , '/' ) ) != NULL ) {
if ( V_3 == V_4 ) {
V_4 ++ ;
continue;
}
* V_3 = '\0' ;
if ( F_3 ( ( char * ) V_1 -> V_6 , V_10 ) ) {
if ( V_1 -> V_11 & V_12 ) {
if ( F_4 ( ( char * ) V_1 -> V_6 , 0755 ) ) {
F_2 ( V_13 , L_3 ,
( char * ) V_1 -> V_6 ) ;
goto V_14;
}
} else {
F_2 ( V_13 , L_4 ,
( char * ) V_1 -> V_6 ) ;
goto V_14;
}
}
V_4 = V_3 + 1 ;
* V_3 = '/' ;
}
if ( ! F_3 ( V_7 , V_10 ) ) {
F_2 ( V_9 , L_5 , V_7 ) ;
if ( ! ( V_1 -> V_11 & V_15 ) ) {
error = V_16 ;
goto V_14;
}
}
V_17 = F_5 ( V_7 ,
V_18 | V_19 | V_20 | V_21 , 0744 ) ;
if ( V_17 == - 1 ) {
F_2 ( V_9 , L_6 , strerror ( V_22 ) ) ;
goto V_14;
}
error = 0 ;
V_14:
return error ;
}
static int F_6 ( struct V_23 * V_24 )
{
T_1 V_25 ;
int V_26 = 0 ;
V_25 = F_7 ( V_17 , V_24 -> V_27 , V_24 -> V_28 ,
V_24 -> V_29 ) ;
V_5 += V_24 -> V_28 ;
if ( V_25 != V_24 -> V_28 ) {
switch ( V_22 ) {
case V_30 :
V_26 = V_31 ;
break;
default:
V_26 = V_2 ;
break;
}
F_2 ( V_13 , L_7 ,
V_5 , ( long ) V_25 , strerror ( V_22 ) ) ;
}
return V_26 ;
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
void F_12 ( char * V_32 [] )
{
fprintf ( V_33 , L_8
L_9
L_10
L_11 , V_32 [ 0 ] ) ;
}
int main ( int V_34 , char * V_32 [] )
{
int V_35 , V_36 ;
int error ;
int V_37 = 1 , V_38 = 0 , V_39 ;
int V_40 = V_41 ;
char * V_42 [ 4096 * 2 ] ;
struct V_43 * V_44 ;
int V_45 = 1 ;
T_2 V_46 ;
static struct V_47 V_48 [] = {
{ L_12 , V_49 , 0 , 'h' } ,
{ L_13 , V_49 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_39 = F_13 ( V_34 , V_32 , L_14 , V_48 ,
& V_38 ) ) != - 1 ) {
switch ( V_39 ) {
case 'n' :
V_37 = 0 ;
break;
case 'h' :
default:
F_12 ( V_32 ) ;
exit ( V_50 ) ;
}
}
if ( V_37 && F_14 ( 1 , 0 ) ) {
F_2 ( V_13 , L_15 , strerror ( V_22 ) ) ;
exit ( V_50 ) ;
}
F_15 ( L_16 , 0 , V_51 ) ;
F_2 ( V_9 , L_17 , F_16 () ) ;
V_35 = F_5 ( L_18 , V_18 ) ;
if ( V_35 < 0 ) {
F_2 ( V_13 , L_19 ,
V_22 , strerror ( V_22 ) ) ;
exit ( V_50 ) ;
}
if ( ( F_17 ( V_35 , & V_40 , sizeof( int ) ) ) != sizeof( int ) ) {
F_2 ( V_13 , L_20 , strerror ( V_22 ) ) ;
exit ( V_50 ) ;
}
while ( 1 ) {
V_36 = F_18 ( V_35 , V_42 , ( 4096 * 2 ) , 0 ) ;
if ( V_36 < 0 ) {
F_2 ( V_13 , L_21 , strerror ( V_22 ) ) ;
exit ( V_50 ) ;
}
if ( V_45 ) {
if ( V_36 != sizeof( V_46 ) ) {
F_2 ( V_13 , L_22 ) ;
exit ( V_50 ) ;
}
V_46 = * ( T_2 * ) V_42 ;
V_45 = 0 ;
F_2 ( V_9 , L_23 ,
V_46 ) ;
continue;
}
V_44 = (struct V_43 * ) V_42 ;
switch ( V_44 -> V_52 ) {
case V_53 :
error = F_1 ( (struct F_1 * ) V_44 ) ;
break;
case V_54 :
error = F_6 ( (struct V_23 * ) V_44 ) ;
break;
case V_55 :
error = F_8 () ;
break;
case V_56 :
error = F_10 () ;
break;
default:
F_2 ( V_13 , L_24 ,
V_44 -> V_52 ) ;
}
if ( F_7 ( V_35 , & error , sizeof( int ) , 0 ) != sizeof( int ) ) {
F_2 ( V_13 , L_25 , strerror ( V_22 ) ) ;
exit ( V_50 ) ;
}
}
}
