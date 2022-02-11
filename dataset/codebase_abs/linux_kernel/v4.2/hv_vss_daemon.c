static int F_1 ( char * V_1 , unsigned int V_2 )
{
int V_3 , V_4 = F_2 ( V_1 , V_5 ) ;
if ( V_4 < 0 )
return 1 ;
V_3 = F_3 ( V_4 , V_2 , 0 ) ;
if ( V_3 ) {
if ( ( V_2 == V_6 && V_7 == V_8 ) ||
( V_2 == V_9 && V_7 == V_10 ) ) {
F_4 ( V_4 ) ;
return 0 ;
}
}
F_4 ( V_4 ) ;
return ! ! V_3 ;
}
static int F_5 ( int V_11 )
{
char V_12 [] = L_1 ;
T_1 * V_13 ;
struct V_14 * V_15 ;
char V_16 [ 1024 ] = { 0 } ;
unsigned int V_2 ;
int error = 0 , V_17 = 0 , V_18 = 0 ;
switch ( V_11 ) {
case V_19 :
V_2 = V_6 ;
break;
case V_20 :
V_2 = V_9 ;
break;
default:
return - 1 ;
}
V_13 = F_6 ( L_2 , L_3 ) ;
if ( V_13 == NULL )
return - 1 ;
while ( ( V_15 = F_7 ( V_13 ) ) ) {
if ( strncmp ( V_15 -> V_21 , V_12 , strlen ( V_12 ) ) )
continue;
if ( F_8 ( V_15 , V_22 ) != NULL )
continue;
if ( strcmp ( V_15 -> V_23 , L_4 ) == 0 )
continue;
if ( strcmp ( V_15 -> V_24 , L_5 ) == 0 ) {
V_17 = 1 ;
continue;
}
error |= F_1 ( V_15 -> V_24 , V_2 ) ;
if ( error && V_11 == V_19 )
goto V_25;
}
F_9 ( V_13 ) ;
if ( V_17 ) {
error |= F_1 ( L_5 , V_2 ) ;
if ( error && V_11 == V_19 )
goto V_25;
}
goto V_26;
V_25:
V_18 = V_7 ;
if ( V_15 ) {
strncpy ( V_16 , V_15 -> V_24 , sizeof( V_16 ) - 1 ) ;
F_9 ( V_13 ) ;
}
F_5 ( V_20 ) ;
if ( V_15 )
F_10 ( V_27 , L_6 ,
V_16 , V_18 , strerror ( V_18 ) ) ;
else
F_10 ( V_27 , L_7 , V_18 ,
strerror ( V_18 ) ) ;
V_26:
return error ;
}
void F_11 ( char * V_28 [] )
{
fprintf ( V_29 , L_8
L_9
L_10
L_11 , V_28 [ 0 ] ) ;
}
int main ( int V_30 , char * V_28 [] )
{
int V_31 , V_32 ;
int error ;
struct V_33 V_34 ;
int V_35 ;
struct V_36 V_37 [ 1 ] ;
int V_38 = 1 , V_39 = 0 , V_40 ;
int V_41 = 1 ;
T_2 V_42 ;
static struct V_43 V_44 [] = {
{ L_12 , V_45 , 0 , 'h' } ,
{ L_13 , V_45 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_40 = F_12 ( V_30 , V_28 , L_14 , V_44 ,
& V_39 ) ) != - 1 ) {
switch ( V_40 ) {
case 'n' :
V_38 = 0 ;
break;
case 'h' :
default:
F_11 ( V_28 ) ;
exit ( V_46 ) ;
}
}
if ( V_38 && F_13 ( 1 , 0 ) )
return 1 ;
F_14 ( L_15 , 0 , V_47 ) ;
F_10 ( V_48 , L_16 , F_15 () ) ;
V_31 = F_2 ( L_17 , V_49 ) ;
if ( V_31 < 0 ) {
F_10 ( V_27 , L_18 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_46 ) ;
}
V_37 -> V_50 . V_11 = V_51 ;
V_32 = F_16 ( V_31 , V_37 , sizeof( struct V_36 ) ) ;
if ( V_32 < 0 ) {
F_10 ( V_27 , L_19 ,
V_7 , strerror ( V_7 ) ) ;
F_4 ( V_31 ) ;
exit ( V_46 ) ;
}
V_34 . V_4 = V_31 ;
while ( 1 ) {
V_34 . V_52 = V_53 ;
V_34 . V_54 = 0 ;
if ( F_17 ( & V_34 , 1 , - 1 ) < 0 ) {
F_10 ( V_27 , L_20 , V_7 , strerror ( V_7 ) ) ;
if ( V_7 == V_10 ) {
F_4 ( V_31 ) ;
exit ( V_46 ) ;
}
else
continue;
}
V_32 = F_18 ( V_31 , V_37 , sizeof( struct V_36 ) ) ;
if ( V_41 ) {
if ( V_32 != sizeof( V_42 ) ) {
F_10 ( V_27 , L_21 ) ;
exit ( V_46 ) ;
}
V_42 = * ( T_2 * ) V_37 ;
V_41 = 0 ;
F_10 ( V_48 , L_22 ,
V_42 ) ;
continue;
}
if ( V_32 != sizeof( struct V_36 ) ) {
F_10 ( V_27 , L_23 ,
V_7 , strerror ( V_7 ) ) ;
F_4 ( V_31 ) ;
return V_46 ;
}
V_35 = V_37 -> V_50 . V_11 ;
error = V_55 ;
switch ( V_35 ) {
case V_19 :
case V_20 :
error = F_5 ( V_35 ) ;
F_10 ( V_48 , L_24 ,
V_35 == V_19 ? L_25 : L_26 ,
error ? L_27 : L_28 ) ;
if ( error ) {
error = V_56 ;
F_10 ( V_27 , L_29 , V_35 ) ;
F_10 ( V_27 , L_30 ) ;
F_10 ( V_27 , L_31 ) ;
}
break;
default:
F_10 ( V_27 , L_32 , V_35 ) ;
}
V_37 -> error = error ;
V_32 = F_16 ( V_31 , & error , sizeof( struct V_36 ) ) ;
if ( V_32 != sizeof( struct V_36 ) ) {
F_10 ( V_27 , L_33 , V_7 ,
strerror ( V_7 ) ) ;
exit ( V_46 ) ;
}
}
F_4 ( V_31 ) ;
exit ( 0 ) ;
}
