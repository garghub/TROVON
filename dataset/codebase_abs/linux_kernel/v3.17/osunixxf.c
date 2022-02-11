static void F_1 ( void )
{
struct V_1 V_2 ;
if ( F_2 ( V_3 , & V_4 ) ) {
fprintf ( V_5 , L_1 ) ;
return;
}
memcpy ( & V_2 , & V_4 ,
sizeof( struct V_1 ) ) ;
V_2 . V_6 &= ~ ( V_7 | V_8 ) ;
V_2 . V_9 [ V_10 ] = 1 ;
V_2 . V_9 [ V_11 ] = 0 ;
if ( F_3 ( V_3 , V_12 , & V_2 ) ) {
fprintf ( V_5 , L_2 ) ;
return;
}
V_13 = 1 ;
}
static void F_4 ( void )
{
if ( ! V_13 ) {
return;
}
if ( F_3 ( V_3 , V_12 , & V_4 ) ) {
fprintf ( V_5 , L_3 ) ;
}
}
T_1 F_5 ( void )
{
T_1 V_14 ;
V_15 = stdout ;
F_1 () ;
V_14 = F_6 ( & V_16 ) ;
if ( F_7 ( V_14 ) ) {
return ( V_14 ) ;
}
return ( V_17 ) ;
}
T_1 F_8 ( void )
{
F_4 () ;
return ( V_17 ) ;
}
T_2 F_9 ( void )
{
return ( 0 ) ;
}
T_1
F_10 ( const struct V_18 * V_19 ,
T_3 * V_20 )
{
if ( ! V_19 || ! V_20 ) {
return ( V_21 ) ;
}
* V_20 = NULL ;
return ( V_17 ) ;
}
T_1
F_11 ( struct V_22 * V_23 ,
struct V_22 * * V_24 )
{
if ( ! V_23 || ! V_24 ) {
return ( V_21 ) ;
}
* V_24 = NULL ;
#ifdef F_12
F_13 ( V_23 , V_24 ) ;
return ( V_17 ) ;
#else
return ( V_25 ) ;
#endif
}
T_1
F_14 ( struct V_22 * V_23 ,
T_2 * V_26 ,
T_4 * V_27 )
{
return ( V_28 ) ;
}
void F_15 ( void * V_29 )
{
V_15 = V_29 ;
}
void T_5 F_16 ( const char * V_30 , ... )
{
T_6 args ;
T_7 V_31 ;
V_31 = V_32 ;
if ( V_31 & V_33 ) {
if ( V_34 ) {
va_start ( args , V_30 ) ;
vfprintf ( V_34 , V_30 , args ) ;
va_end ( args ) ;
} else {
V_31 |= V_35 ;
}
}
if ( V_31 & V_35 ) {
va_start ( args , V_30 ) ;
vfprintf ( V_15 , V_30 , args ) ;
va_end ( args ) ;
}
}
void F_17 ( const char * V_30 , T_6 args )
{
T_7 V_31 ;
char V_36 [ V_37 ] ;
vsnprintf ( V_36 , V_37 , V_30 , args ) ;
V_31 = V_32 ;
if ( V_31 & V_33 ) {
if ( V_34 ) {
fputs ( V_36 , V_34 ) ;
} else {
V_31 |= V_35 ;
}
}
if ( V_31 & V_35 ) {
fputs ( V_36 , V_15 ) ;
}
}
T_1 F_18 ( char * V_36 , T_4 V_38 , T_4 * V_39 )
{
int V_40 ;
T_4 V_41 ;
for ( V_41 = 0 ; ; V_41 ++ ) {
if ( V_41 >= V_38 ) {
return ( V_42 ) ;
}
if ( ( V_40 = getchar () ) == V_43 ) {
return ( V_44 ) ;
}
if ( ! V_40 || V_40 == V_45 ) {
break;
}
V_36 [ V_41 ] = ( char ) V_40 ;
}
V_36 [ V_41 ] = 0 ;
if ( V_39 ) {
* V_39 = V_41 ;
}
return ( V_17 ) ;
}
void * F_19 ( T_2 V_46 , T_8 V_47 )
{
return ( F_20 ( ( T_8 ) V_46 ) ) ;
}
void F_21 ( void * V_46 , T_8 V_47 )
{
return;
}
void * F_22 ( T_8 V_48 )
{
void * V_49 ;
V_49 = ( void * ) malloc ( ( V_50 ) V_48 ) ;
return ( V_49 ) ;
}
void * F_23 ( T_8 V_48 )
{
void * V_49 ;
V_49 = ( void * ) calloc ( 1 , ( V_50 ) V_48 ) ;
return ( V_49 ) ;
}
void F_24 ( void * V_49 )
{
free ( V_49 ) ;
}
T_1
F_25 ( T_4 V_51 ,
T_4 V_52 , T_9 * V_53 )
{
* V_53 = ( T_9 ) 1 ;
return ( V_17 ) ;
}
T_1 F_26 ( T_9 V_54 )
{
return ( V_17 ) ;
}
T_1 F_27 ( T_9 V_54 , T_4 V_55 , T_10 V_56 )
{
return ( V_17 ) ;
}
T_1 F_28 ( T_9 V_54 , T_4 V_55 )
{
return ( V_17 ) ;
}
T_1
F_25 ( T_4 V_51 ,
T_4 V_52 , T_9 * V_53 )
{
T_11 * V_57 ;
if ( ! V_53 ) {
return ( V_21 ) ;
}
#ifdef F_29
{
char * V_58 = tmpnam ( NULL ) ;
V_57 =
F_30 ( V_58 , V_59 | V_60 , 0755 ,
V_52 ) ;
if ( ! V_57 ) {
return ( V_61 ) ;
}
F_31 ( V_58 ) ;
}
#else
V_57 = F_22 ( sizeof( T_11 ) ) ;
if ( ! V_57 ) {
return ( V_61 ) ;
}
if ( F_32 ( V_57 , 0 , V_52 ) == - 1 ) {
F_24 ( V_57 ) ;
return ( V_21 ) ;
}
#endif
* V_53 = ( T_9 ) V_57 ;
return ( V_17 ) ;
}
T_1 F_26 ( T_9 V_54 )
{
T_11 * V_57 = ( T_11 * ) V_54 ;
if ( ! V_57 ) {
return ( V_21 ) ;
}
if ( F_33 ( V_57 ) == - 1 ) {
return ( V_21 ) ;
}
return ( V_17 ) ;
}
T_1
F_27 ( T_9 V_54 , T_4 V_55 , T_10 V_62 )
{
T_1 V_14 = V_17 ;
T_11 * V_57 = ( T_11 * ) V_54 ;
#ifndef F_34
struct V_63 time ;
int V_64 ;
#endif
if ( ! V_57 ) {
return ( V_21 ) ;
}
switch ( V_62 ) {
case 0 :
if ( F_35 ( V_57 ) == - 1 ) {
V_14 = ( V_65 ) ;
}
break;
case V_66 :
if ( F_36 ( V_57 ) ) {
V_14 = ( V_65 ) ;
}
break;
default:
#ifdef F_34
while ( V_62 ) {
if ( F_35 ( V_57 ) == 0 ) {
return ( V_17 ) ;
}
if ( V_62 >= 10 ) {
V_62 -= 10 ;
F_37 ( 10 * V_67 ) ;
} else {
V_62 -- ;
F_37 ( V_67 ) ;
}
}
V_14 = ( V_65 ) ;
#else
if ( F_38 ( V_68 , & time ) == - 1 ) {
perror ( L_4 ) ;
return ( V_65 ) ;
}
time . V_69 += ( V_62 / V_70 ) ;
time . V_71 +=
( ( V_62 % V_70 ) * V_72 ) ;
if ( time . V_71 >= V_73 ) {
time . V_69 += ( time . V_71 / V_73 ) ;
time . V_71 = ( time . V_71 % V_73 ) ;
}
while ( ( ( V_64 = F_39 ( V_57 , & time ) ) == - 1 )
&& ( V_74 == V_75 ) ) {
continue;
}
if ( V_64 != 0 ) {
if ( V_74 != V_76 ) {
perror ( L_5 ) ;
}
V_14 = ( V_65 ) ;
}
#endif
break;
}
return ( V_14 ) ;
}
T_1 F_28 ( T_9 V_54 , T_4 V_55 )
{
T_11 * V_57 = ( T_11 * ) V_54 ;
if ( ! V_57 ) {
return ( V_21 ) ;
}
if ( F_40 ( V_57 ) == - 1 ) {
return ( V_77 ) ;
}
return ( V_17 ) ;
}
T_1 F_6 ( T_12 * V_53 )
{
return ( F_25 ( 1 , 1 , V_53 ) ) ;
}
void F_41 ( T_12 V_54 )
{
F_26 ( V_54 ) ;
}
T_13 F_42 ( T_9 V_54 )
{
F_27 ( V_54 , 1 , 0xFFFF ) ;
return ( 0 ) ;
}
void F_43 ( T_12 V_54 , T_13 V_31 )
{
F_28 ( V_54 , 1 ) ;
}
T_4
F_44 ( T_4 V_78 ,
T_14 V_79 ,
void * V_80 )
{
return ( V_17 ) ;
}
T_1
F_45 ( T_4 V_78 ,
T_14 V_79 )
{
return ( V_17 ) ;
}
void F_46 ( T_4 V_81 )
{
if ( V_81 ) {
F_37 ( V_81 ) ;
}
}
void F_47 ( T_15 V_82 )
{
F_48 ( V_82 / V_70 ) ;
F_37 ( ( V_82 % V_70 ) * V_67 ) ;
}
T_15 F_49 ( void )
{
struct V_83 time ;
F_50 ( & time , NULL ) ;
return ( ( ( T_15 ) time . V_69 * V_84 ) +
( ( T_15 ) time . V_85 * V_86 ) ) ;
}
T_1
F_51 ( struct V_87 * V_88 ,
T_4 V_89 , T_15 * V_90 , T_4 V_91 )
{
* V_90 = 0 ;
return ( V_17 ) ;
}
T_1
F_52 ( struct V_87 * V_88 ,
T_4 V_89 , T_15 V_90 , T_4 V_91 )
{
return ( V_17 ) ;
}
T_1 F_53 ( T_16 V_92 , T_4 * V_90 , T_4 V_91 )
{
switch ( V_91 ) {
case 8 :
* V_90 = 0xFF ;
break;
case 16 :
* V_90 = 0xFFFF ;
break;
case 32 :
* V_90 = 0xFFFFFFFF ;
break;
default:
return ( V_21 ) ;
}
return ( V_17 ) ;
}
T_1 F_54 ( T_16 V_92 , T_4 V_90 , T_4 V_91 )
{
return ( V_17 ) ;
}
T_1
F_55 ( T_2 V_92 , T_15 * V_90 , T_4 V_91 )
{
switch ( V_91 ) {
case 8 :
case 16 :
case 32 :
case 64 :
* V_90 = 0 ;
break;
default:
return ( V_21 ) ;
}
return ( V_17 ) ;
}
T_1
F_56 ( T_2 V_92 , T_15 V_90 , T_4 V_91 )
{
return ( V_17 ) ;
}
T_7 F_57 ( void * V_93 , T_8 V_47 )
{
return ( TRUE ) ;
}
T_7 F_58 ( void * V_93 , T_8 V_47 )
{
return ( TRUE ) ;
}
T_1 F_59 ( T_4 V_94 , void * V_95 )
{
switch ( V_94 ) {
case V_96 :
break;
case V_97 :
break;
default:
break;
}
return ( V_17 ) ;
}
T_17 F_60 ( void )
{
T_18 V_98 ;
V_98 = F_61 () ;
return ( F_62 ( V_98 ) ) ;
}
T_1
F_63 ( T_19 type ,
T_20 V_94 , void * V_80 )
{
T_18 V_98 ;
int V_99 ;
V_99 =
F_64 ( & V_98 , NULL , ( V_100 ) V_94 , V_80 ) ;
if ( V_99 ) {
F_16 ( L_6 ) ;
}
return ( 0 ) ;
}
T_17 F_60 ( void )
{
return ( 1 ) ;
}
T_1
F_63 ( T_19 type ,
T_20 V_94 , void * V_80 )
{
V_94 ( V_80 ) ;
return ( V_17 ) ;
}
void F_65 ( void )
{
return;
}
