static void F_1 ( void )
{
V_1 = F_2 ( V_2 , sizeof( V_3 ) ,
sizeof( struct V_4 ) , 100 , 0 ) ;
if ( V_1 < 0 )
error ( 1 , V_5 , L_1 ) ;
}
static void F_3 ( void )
{
static char V_6 [ 1 << 16 ] ;
struct V_7 V_8 [] = {
F_4 ( V_9 , V_10 ) ,
F_5 ( V_11 | V_12 , 0 , 0 , 0 ,
V_13 ) ,
F_6 ( V_14 , V_15 , V_16 , - 8 ) ,
F_4 ( V_17 , V_15 ) ,
F_7 ( V_18 , V_17 , - 8 ) ,
F_8 ( V_10 , V_1 ) ,
F_4 ( V_19 , V_17 ) ,
F_5 ( V_11 | V_12 , 0 , 0 , 0 ,
V_20 ) ,
F_9 ( V_21 , V_16 , 0 , 14 ) ,
F_4 ( V_10 , V_9 ) ,
F_5 ( V_11 | V_12 , 0 , 0 , 0 ,
V_22 ) ,
F_6 ( V_14 , V_15 , V_16 ,
- 32 + ( V_23 ) F_10 ( struct V_4 , V_24 ) ) ,
F_11 ( V_14 , V_15 ,
- 32 + ( V_23 ) F_10 ( struct V_4 , V_25 ) , 1 ) ,
F_12 ( V_26 , V_10 , V_9 ,
F_10 ( struct V_27 , V_28 ) ) ,
F_6 ( V_14 , V_15 , V_10 ,
- 32 + ( V_23 ) F_10 ( struct V_4 , V_29 ) ) ,
F_8 ( V_10 , V_1 ) ,
F_4 ( V_19 , V_17 ) ,
F_4 ( V_30 , V_15 ) ,
F_7 ( V_18 , V_30 , - 32 ) ,
F_13 ( V_31 , 0 ) ,
F_5 ( V_11 | V_12 , 0 , 0 , 0 ,
V_32 ) ,
F_9 ( V_33 , 0 , 0 , 5 ) ,
F_4 ( V_34 , V_16 ) ,
F_13 ( V_10 , 1 ) ,
F_14 ( V_14 , V_34 , V_10 ,
F_10 ( struct V_4 , V_25 ) ) ,
F_12 ( V_26 , V_10 , V_9 ,
F_10 ( struct V_27 , V_28 ) ) ,
F_14 ( V_14 , V_34 , V_10 ,
F_10 ( struct V_4 , V_29 ) ) ,
F_12 ( V_26 , V_16 , V_9 ,
F_10 ( struct V_27 , V_28 ) ) ,
F_15 () ,
} ;
V_35 = F_16 ( V_36 , V_8 ,
F_17 ( V_8 ) , L_2 , 0 ,
V_6 , sizeof( V_6 ) ) ;
if ( V_35 < 0 )
error ( 1 , V_5 , L_3 , V_6 ) ;
}
static void F_18 ( char * V_37 )
{
int V_38 ;
char V_39 [ 100 ] ;
if ( F_19 ( V_35 , V_37 ) )
error ( 1 , V_5 , L_4 ) ;
if ( strlen ( V_37 ) > 50 ) {
printf ( L_5 , V_37 ) ;
exit ( 1 ) ;
}
sprintf ( V_39 , L_6 ,
V_37 ) ;
V_38 = system ( V_39 ) ;
if ( V_38 < 0 ) {
printf ( L_7 , F_20 ( V_38 ) ) ;
exit ( 1 ) ;
}
}
static void F_21 ( void )
{
struct V_4 V_40 ;
V_3 V_41 = V_42 ;
V_3 V_43 ;
int V_44 ;
while ( F_22 ( V_1 , & V_41 , & V_43 ) > - 1 ) {
V_41 = V_43 ;
V_44 = F_23 ( V_1 , & V_41 , & V_40 ) ;
if ( V_44 < 0 ) {
error ( 1 , V_5 , L_8 ,
V_41 ) ;
} else {
printf ( L_9
L_10 , V_41 , V_40 . V_24 ,
V_40 . V_25 , V_40 . V_29 ) ;
}
}
}
static void F_24 ( void )
{
struct V_45 V_46 = { 0 } ;
struct V_45 V_47 = { 0 } ;
struct V_4 V_48 ;
int V_49 , V_50 , V_51 , V_52 ;
char V_53 = 'a' ;
char V_54 ;
T_1 V_55 ;
int V_44 ;
T_2 V_56 = sizeof( V_55 ) ;
T_2 V_57 = sizeof( V_46 ) ;
V_49 = F_25 ( V_58 , V_59 , 0 ) ;
if ( V_49 < 0 )
error ( 1 , V_5 , L_11 ) ;
V_46 . V_60 = V_61 ;
V_46 . V_62 = F_26 ( V_63 ) ;
if ( F_27 ( L_12 , & V_46 . V_64 ) == 0 )
error ( 1 , V_5 , L_13 ) ;
if ( F_28 ( V_49 , (struct V_65 * ) & V_46 , sizeof( V_46 ) ) == - 1 )
error ( 1 , V_5 , L_14 ) ;
V_50 = F_25 ( V_58 , V_59 , 0 ) ;
if ( V_50 < 0 )
error ( 1 , V_5 , L_15 ) ;
V_44 = F_29 ( V_50 , V_66 , V_67 , & V_55 , & V_56 ) ;
if ( V_44 < 0 )
printf ( L_16 , strerror ( V_5 ) ) ;
V_44 = F_23 ( V_1 , & V_55 , & V_48 ) ;
if ( V_44 != - 1 )
error ( 1 , V_5 , L_17 ) ;
for ( V_51 = 0 ; V_51 < 10 ; V_51 ++ ) {
V_44 = F_30 ( V_50 , & V_53 , sizeof( V_53 ) , 0 ,
(struct V_65 * ) & V_46 , V_57 ) ;
if ( V_44 == - 1 )
error ( 1 , V_5 , L_18 ) ;
if ( V_44 != sizeof( V_53 ) )
error ( 1 , 0 , L_19 , V_44 , sizeof( V_53 ) ) ;
V_52 = F_31 ( V_49 , & V_54 , sizeof( V_54 ) , 0 ,
(struct V_65 * ) & V_47 , & V_57 ) ;
if ( V_52 < 0 )
error ( 1 , V_5 , L_20 ) ;
V_44 = memcmp ( & ( V_46 . V_64 ) , & ( V_47 . V_64 ) ,
sizeof( V_47 . V_64 ) ) ;
if ( V_44 != 0 )
error ( 1 , V_68 , L_21 , V_44 ) ;
printf ( L_22 , V_54 ) ;
V_44 = F_23 ( V_1 , & V_55 , & V_48 ) ;
if ( V_44 < 0 )
error ( 1 , V_5 , L_23 ,
V_55 ) ;
printf ( L_24
L_25 , V_55 , V_48 . V_24 ,
V_48 . V_25 , V_48 . V_29 ) ;
}
F_32 ( V_50 ) ;
F_32 ( V_49 ) ;
}
static int F_33 ( void )
{
printf ( L_26
L_27
L_28
L_29 ) ;
return 1 ;
}
static void F_34 ( int V_38 )
{
V_69 = true ;
}
int main ( int V_70 , char * V_71 [] )
{
int V_72 ;
bool V_73 = false ;
bool V_74 = false ;
if ( V_70 != 3 )
return F_33 () ;
while ( ( V_72 = F_35 ( V_70 , V_71 , L_30 ) ) != - 1 ) {
switch ( V_72 ) {
case 't' :
V_73 = true ;
break;
case 's' :
V_74 = true ;
break;
default:
printf ( L_31 , V_72 ) ;
F_33 () ;
return - 1 ;
}
}
F_1 () ;
F_3 () ;
F_18 ( V_71 [ 2 ] ) ;
if ( V_73 ) {
if ( signal ( V_75 , F_34 ) == V_76 )
error ( 1 , V_5 , L_32 ) ;
if ( signal ( V_77 , F_34 ) == V_76 )
error ( 1 , V_5 , L_33 ) ;
while ( ! V_69 ) {
F_21 () ;
printf ( L_34 ) ;
F_36 ( 1 ) ;
} ;
} else if ( V_74 ) {
F_24 () ;
}
F_32 ( V_35 ) ;
F_32 ( V_1 ) ;
return 0 ;
}
