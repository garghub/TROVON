static void F_1 ( void )
{
struct V_1 V_2 ;
V_3 = 0 ;
if ( ! F_2 ( V_4 ) ) {
return;
}
if ( F_3 ( V_4 , & V_5 ) ) {
fprintf ( V_6 , L_1 ) ;
return;
}
memcpy ( & V_2 , & V_5 ,
sizeof( struct V_1 ) ) ;
V_2 . V_7 &= ~ ( V_8 | V_9 ) ;
V_2 . V_10 [ V_11 ] = 1 ;
V_2 . V_10 [ V_12 ] = 0 ;
if ( F_4 ( V_4 , V_13 , & V_2 ) ) {
fprintf ( V_6 , L_2 ) ;
return;
}
V_3 = 1 ;
}
static void F_5 ( void )
{
if ( ! V_3 ) {
return;
}
if ( F_4 ( V_4 , V_13 , & V_5 ) ) {
fprintf ( V_6 , L_3 ) ;
}
}
T_1 F_6 ( void )
{
T_1 V_14 ;
V_15 = stdout ;
F_1 () ;
V_14 = F_7 ( & V_16 ) ;
if ( F_8 ( V_14 ) ) {
return ( V_14 ) ;
}
return ( V_17 ) ;
}
T_1 F_9 ( void )
{
F_5 () ;
return ( V_17 ) ;
}
T_2 F_10 ( void )
{
return ( 0 ) ;
}
T_1
F_11 ( const struct V_18 * V_19 ,
T_3 * V_20 )
{
if ( ! V_19 || ! V_20 ) {
return ( V_21 ) ;
}
* V_20 = NULL ;
return ( V_17 ) ;
}
T_1
F_12 ( struct V_22 * V_23 ,
struct V_22 * * V_24 )
{
if ( ! V_23 || ! V_24 ) {
return ( V_21 ) ;
}
* V_24 = NULL ;
#ifdef F_13
F_14 ( V_23 , V_24 ) ;
return ( V_17 ) ;
#else
return ( V_25 ) ;
#endif
}
T_1
F_15 ( struct V_22 * V_23 ,
T_2 * V_26 ,
T_4 * V_27 )
{
return ( V_28 ) ;
}
T_1 F_16 ( T_5 V_29 , T_4 V_30 , T_4 V_31 )
{
return ( V_17 ) ;
}
void F_17 ( void * V_32 )
{
V_15 = V_32 ;
}
void T_6 F_18 ( const char * V_33 , ... )
{
T_7 args ;
T_5 V_34 ;
V_34 = V_35 ;
if ( V_34 & V_36 ) {
if ( V_37 ) {
va_start ( args , V_33 ) ;
vfprintf ( V_37 , V_33 , args ) ;
va_end ( args ) ;
} else {
V_34 |= V_38 ;
}
}
if ( V_34 & V_38 ) {
va_start ( args , V_33 ) ;
vfprintf ( V_15 , V_33 , args ) ;
va_end ( args ) ;
}
}
void F_19 ( const char * V_33 , T_7 args )
{
T_5 V_34 ;
char V_39 [ V_40 ] ;
vsnprintf ( V_39 , V_40 , V_33 , args ) ;
V_34 = V_35 ;
if ( V_34 & V_36 ) {
if ( V_37 ) {
fputs ( V_39 , V_37 ) ;
} else {
V_34 |= V_38 ;
}
}
if ( V_34 & V_38 ) {
fputs ( V_39 , V_15 ) ;
}
}
T_1 F_20 ( char * V_39 , T_4 V_41 , T_4 * V_42 )
{
int V_43 ;
T_4 V_44 ;
for ( V_44 = 0 ; ; V_44 ++ ) {
if ( V_44 >= V_41 ) {
return ( V_45 ) ;
}
if ( ( V_43 = getchar () ) == V_46 ) {
return ( V_47 ) ;
}
if ( ! V_43 || V_43 == V_48 ) {
break;
}
V_39 [ V_44 ] = ( char ) V_43 ;
}
V_39 [ V_44 ] = 0 ;
if ( V_42 ) {
* V_42 = V_44 ;
}
return ( V_17 ) ;
}
void * F_21 ( T_2 V_49 , T_8 V_50 )
{
return ( F_22 ( ( T_8 ) V_49 ) ) ;
}
void F_23 ( void * V_49 , T_8 V_50 )
{
return;
}
void * F_24 ( T_8 V_51 )
{
void * V_52 ;
V_52 = ( void * ) malloc ( ( V_53 ) V_51 ) ;
return ( V_52 ) ;
}
void * F_25 ( T_8 V_51 )
{
void * V_52 ;
V_52 = ( void * ) calloc ( 1 , ( V_53 ) V_51 ) ;
return ( V_52 ) ;
}
void F_26 ( void * V_52 )
{
free ( V_52 ) ;
}
T_1
F_27 ( T_4 V_54 ,
T_4 V_55 , T_9 * V_56 )
{
* V_56 = ( T_9 ) 1 ;
return ( V_17 ) ;
}
T_1 F_28 ( T_9 V_57 )
{
return ( V_17 ) ;
}
T_1 F_29 ( T_9 V_57 , T_4 V_58 , T_10 V_59 )
{
return ( V_17 ) ;
}
T_1 F_30 ( T_9 V_57 , T_4 V_58 )
{
return ( V_17 ) ;
}
T_1
F_27 ( T_4 V_54 ,
T_4 V_55 , T_9 * V_56 )
{
T_11 * V_60 ;
if ( ! V_56 ) {
return ( V_21 ) ;
}
#ifdef F_31
{
static int V_61 = 0 ;
char V_62 [ 32 ] ;
snprintf ( V_62 , sizeof( V_62 ) , L_4 ,
V_61 ++ ) ;
printf ( L_5 , V_62 ) ;
V_60 =
F_32 ( V_62 , V_63 | V_64 , 0755 ,
V_55 ) ;
if ( ! V_60 ) {
return ( V_65 ) ;
}
F_33 ( V_62 ) ;
}
#else
V_60 = F_24 ( sizeof( T_11 ) ) ;
if ( ! V_60 ) {
return ( V_65 ) ;
}
if ( F_34 ( V_60 , 0 , V_55 ) == - 1 ) {
F_26 ( V_60 ) ;
return ( V_21 ) ;
}
#endif
* V_56 = ( T_9 ) V_60 ;
return ( V_17 ) ;
}
T_1 F_28 ( T_9 V_57 )
{
T_11 * V_60 = ( T_11 * ) V_57 ;
if ( ! V_60 ) {
return ( V_21 ) ;
}
#ifdef F_31
if ( F_35 ( V_60 ) == - 1 ) {
return ( V_21 ) ;
}
#else
if ( F_36 ( V_60 ) == - 1 ) {
return ( V_21 ) ;
}
#endif
return ( V_17 ) ;
}
T_1
F_29 ( T_9 V_57 , T_4 V_58 , T_10 V_66 )
{
T_1 V_14 = V_17 ;
T_11 * V_60 = ( T_11 * ) V_57 ;
#ifndef F_37
struct V_67 time ;
int V_68 ;
#endif
if ( ! V_60 ) {
return ( V_21 ) ;
}
switch ( V_66 ) {
case 0 :
if ( F_38 ( V_60 ) == - 1 ) {
V_14 = ( V_69 ) ;
}
break;
case V_70 :
if ( F_39 ( V_60 ) ) {
V_14 = ( V_69 ) ;
}
break;
default:
#ifdef F_37
while ( V_66 ) {
if ( F_38 ( V_60 ) == 0 ) {
return ( V_17 ) ;
}
if ( V_66 >= 10 ) {
V_66 -= 10 ;
F_40 ( 10 * V_71 ) ;
} else {
V_66 -- ;
F_40 ( V_71 ) ;
}
}
V_14 = ( V_69 ) ;
#else
if ( F_41 ( V_72 , & time ) == - 1 ) {
perror ( L_6 ) ;
return ( V_69 ) ;
}
time . V_73 += ( V_66 / V_74 ) ;
time . V_75 +=
( ( V_66 % V_74 ) * V_76 ) ;
if ( time . V_75 >= V_77 ) {
time . V_73 += ( time . V_75 / V_77 ) ;
time . V_75 = ( time . V_75 % V_77 ) ;
}
while ( ( ( V_68 = F_42 ( V_60 , & time ) ) == - 1 )
&& ( V_78 == V_79 ) ) {
continue;
}
if ( V_68 != 0 ) {
if ( V_78 != V_80 ) {
perror ( L_7 ) ;
}
V_14 = ( V_69 ) ;
}
#endif
break;
}
return ( V_14 ) ;
}
T_1 F_30 ( T_9 V_57 , T_4 V_58 )
{
T_11 * V_60 = ( T_11 * ) V_57 ;
if ( ! V_60 ) {
return ( V_21 ) ;
}
if ( F_43 ( V_60 ) == - 1 ) {
return ( V_81 ) ;
}
return ( V_17 ) ;
}
T_1 F_7 ( T_12 * V_56 )
{
return ( F_27 ( 1 , 1 , V_56 ) ) ;
}
void F_44 ( T_12 V_57 )
{
F_28 ( V_57 ) ;
}
T_13 F_45 ( T_9 V_57 )
{
F_29 ( V_57 , 1 , 0xFFFF ) ;
return ( 0 ) ;
}
void F_46 ( T_12 V_57 , T_13 V_34 )
{
F_30 ( V_57 , 1 ) ;
}
T_4
F_47 ( T_4 V_82 ,
T_14 V_83 ,
void * V_84 )
{
return ( V_17 ) ;
}
T_1
F_48 ( T_4 V_82 ,
T_14 V_83 )
{
return ( V_17 ) ;
}
void F_49 ( T_4 V_85 )
{
if ( V_85 ) {
F_40 ( V_85 ) ;
}
}
void F_50 ( T_15 V_86 )
{
F_51 ( V_86 / V_74 ) ;
F_40 ( ( V_86 % V_74 ) * V_71 ) ;
}
T_15 F_52 ( void )
{
struct V_87 time ;
F_53 ( & time , NULL ) ;
return ( ( ( T_15 ) time . V_73 * V_88 ) +
( ( T_15 ) time . V_89 * V_90 ) ) ;
}
T_1
F_54 ( struct V_91 * V_92 ,
T_4 V_93 , T_15 * V_94 , T_4 V_95 )
{
* V_94 = 0 ;
return ( V_17 ) ;
}
T_1
F_55 ( struct V_91 * V_92 ,
T_4 V_93 , T_15 V_94 , T_4 V_95 )
{
return ( V_17 ) ;
}
T_1 F_56 ( T_16 V_96 , T_4 * V_94 , T_4 V_95 )
{
switch ( V_95 ) {
case 8 :
* V_94 = 0xFF ;
break;
case 16 :
* V_94 = 0xFFFF ;
break;
case 32 :
* V_94 = 0xFFFFFFFF ;
break;
default:
return ( V_21 ) ;
}
return ( V_17 ) ;
}
T_1 F_57 ( T_16 V_96 , T_4 V_94 , T_4 V_95 )
{
return ( V_17 ) ;
}
T_1
F_58 ( T_2 V_96 , T_15 * V_94 , T_4 V_95 )
{
switch ( V_95 ) {
case 8 :
case 16 :
case 32 :
case 64 :
* V_94 = 0 ;
break;
default:
return ( V_21 ) ;
}
return ( V_17 ) ;
}
T_1
F_59 ( T_2 V_96 , T_15 V_94 , T_4 V_95 )
{
return ( V_17 ) ;
}
T_5 F_60 ( void * V_97 , T_8 V_50 )
{
return ( TRUE ) ;
}
T_5 F_61 ( void * V_97 , T_8 V_50 )
{
return ( TRUE ) ;
}
T_1 F_62 ( T_4 V_98 , void * V_99 )
{
switch ( V_98 ) {
case V_100 :
break;
case V_101 :
break;
default:
break;
}
return ( V_17 ) ;
}
T_17 F_63 ( void )
{
T_18 V_102 ;
V_102 = F_64 () ;
return ( F_65 ( V_102 ) ) ;
}
T_1
F_66 ( T_19 type ,
T_20 V_98 , void * V_84 )
{
T_18 V_102 ;
int V_103 ;
V_103 =
F_67 ( & V_102 , NULL , ( V_104 ) V_98 , V_84 ) ;
if ( V_103 ) {
F_18 ( L_8 ) ;
}
return ( 0 ) ;
}
T_17 F_63 ( void )
{
return ( 1 ) ;
}
T_1
F_66 ( T_19 type ,
T_20 V_98 , void * V_84 )
{
V_98 ( V_84 ) ;
return ( V_17 ) ;
}
void F_68 ( void )
{
return;
}
