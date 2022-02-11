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
struct V_16 V_17 ;
char V_18 [ 1024 ] = { 0 } ;
unsigned int V_2 ;
int error = 0 , V_19 = 0 , V_20 = 0 ;
switch ( V_11 ) {
case V_21 :
V_2 = V_6 ;
break;
case V_22 :
V_2 = V_9 ;
break;
default:
return - 1 ;
}
V_13 = F_6 ( L_2 , L_3 ) ;
if ( V_13 == NULL )
return - 1 ;
while ( ( V_15 = F_7 ( V_13 ) ) ) {
if ( strncmp ( V_15 -> V_23 , V_12 , strlen ( V_12 ) ) )
continue;
if ( V_16 ( V_15 -> V_23 , & V_17 ) == - 1 )
continue;
if ( F_8 ( V_17 . V_24 ) && F_9 ( V_17 . V_25 ) == V_26 )
continue;
if ( F_10 ( V_15 , V_27 ) != NULL )
continue;
if ( strcmp ( V_15 -> V_28 , L_4 ) == 0 )
continue;
if ( strcmp ( V_15 -> V_29 , L_5 ) == 0 ) {
V_19 = 1 ;
continue;
}
error |= F_1 ( V_15 -> V_29 , V_2 ) ;
if ( error && V_11 == V_21 )
goto V_30;
}
F_11 ( V_13 ) ;
if ( V_19 ) {
error |= F_1 ( L_5 , V_2 ) ;
if ( error && V_11 == V_21 )
goto V_30;
}
goto V_31;
V_30:
V_20 = V_7 ;
if ( V_15 ) {
strncpy ( V_18 , V_15 -> V_29 , sizeof( V_18 ) - 1 ) ;
F_11 ( V_13 ) ;
}
F_5 ( V_22 ) ;
if ( V_15 )
F_12 ( V_32 , L_6 ,
V_18 , V_20 , strerror ( V_20 ) ) ;
else
F_12 ( V_32 , L_7 , V_20 ,
strerror ( V_20 ) ) ;
V_31:
return error ;
}
void F_13 ( char * V_33 [] )
{
fprintf ( V_34 , L_8
L_9
L_10
L_11 , V_33 [ 0 ] ) ;
}
int main ( int V_35 , char * V_33 [] )
{
int V_36 , V_37 ;
int error ;
struct V_38 V_39 ;
int V_40 ;
struct V_41 V_42 [ 1 ] ;
int V_43 = 1 , V_44 = 0 , V_45 ;
int V_46 = 1 ;
T_2 V_47 ;
static struct V_48 V_49 [] = {
{ L_12 , V_50 , 0 , 'h' } ,
{ L_13 , V_50 , 0 , 'n' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_45 = F_14 ( V_35 , V_33 , L_14 , V_49 ,
& V_44 ) ) != - 1 ) {
switch ( V_45 ) {
case 'n' :
V_43 = 0 ;
break;
case 'h' :
default:
F_13 ( V_33 ) ;
exit ( V_51 ) ;
}
}
if ( V_43 && F_15 ( 1 , 0 ) )
return 1 ;
F_16 ( L_15 , 0 , V_52 ) ;
F_12 ( V_53 , L_16 , F_17 () ) ;
V_36 = F_2 ( L_17 , V_54 ) ;
if ( V_36 < 0 ) {
F_12 ( V_32 , L_18 ,
V_7 , strerror ( V_7 ) ) ;
exit ( V_51 ) ;
}
V_42 -> V_55 . V_11 = V_56 ;
V_37 = F_18 ( V_36 , V_42 , sizeof( struct V_41 ) ) ;
if ( V_37 < 0 ) {
F_12 ( V_32 , L_19 ,
V_7 , strerror ( V_7 ) ) ;
F_4 ( V_36 ) ;
exit ( V_51 ) ;
}
V_39 . V_4 = V_36 ;
while ( 1 ) {
V_39 . V_57 = V_58 ;
V_39 . V_59 = 0 ;
if ( F_19 ( & V_39 , 1 , - 1 ) < 0 ) {
F_12 ( V_32 , L_20 , V_7 , strerror ( V_7 ) ) ;
if ( V_7 == V_10 ) {
F_4 ( V_36 ) ;
exit ( V_51 ) ;
}
else
continue;
}
V_37 = F_20 ( V_36 , V_42 , sizeof( struct V_41 ) ) ;
if ( V_46 ) {
if ( V_37 != sizeof( V_47 ) ) {
F_12 ( V_32 , L_21 ) ;
exit ( V_51 ) ;
}
V_47 = * ( T_2 * ) V_42 ;
V_46 = 0 ;
F_12 ( V_53 , L_22 ,
V_47 ) ;
continue;
}
if ( V_37 != sizeof( struct V_41 ) ) {
F_12 ( V_32 , L_23 ,
V_7 , strerror ( V_7 ) ) ;
F_4 ( V_36 ) ;
return V_51 ;
}
V_40 = V_42 -> V_55 . V_11 ;
error = V_60 ;
switch ( V_40 ) {
case V_21 :
case V_22 :
error = F_5 ( V_40 ) ;
F_12 ( V_53 , L_24 ,
V_40 == V_21 ? L_25 : L_26 ,
error ? L_27 : L_28 ) ;
if ( error ) {
error = V_61 ;
F_12 ( V_32 , L_29 , V_40 ) ;
F_12 ( V_32 , L_30 ) ;
F_12 ( V_32 , L_31 ) ;
}
break;
case V_62 :
F_12 ( V_53 , L_32 ) ;
break;
default:
F_12 ( V_32 , L_33 , V_40 ) ;
}
V_42 -> error = error ;
V_37 = F_18 ( V_36 , V_42 , sizeof( struct V_41 ) ) ;
if ( V_37 != sizeof( struct V_41 ) ) {
F_12 ( V_32 , L_34 , V_7 ,
strerror ( V_7 ) ) ;
if ( V_40 == V_21 )
F_5 ( V_22 ) ;
}
}
F_4 ( V_36 ) ;
exit ( 0 ) ;
}
