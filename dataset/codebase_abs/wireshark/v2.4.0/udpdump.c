static int F_1 ( char * V_1 )
{
unsigned V_2 = 0 ;
if ( ! V_1 ) {
F_2 ( L_1 ) ;
return V_3 ;
}
printf ( L_2
L_3 ,
V_2 ++ , V_4 ) ;
printf ( L_4
L_5 ,
V_2 ++ ) ;
return V_5 ;
}
static int F_3 ( const T_1 V_6 , T_2 * V_7 )
{
int V_8 ;
struct V_9 V_10 ;
#ifndef F_4
struct V_11 V_12 = { 1 , 0 } ;
#endif
* V_7 = F_5 ( V_13 , V_14 , 0 ) ;
if ( * V_7 == V_15 ) {
F_2 ( L_6 , strerror ( V_16 ) ) ;
return V_3 ;
}
V_8 = 1 ;
if ( F_6 ( * V_7 , V_17 , V_18 , ( char * ) & V_8 , ( V_19 ) sizeof( int ) ) < 0 ) {
F_2 ( L_7 , strerror ( V_16 ) ) ;
goto V_20;
}
#ifndef F_4
if ( F_6 ( * V_7 , V_17 , V_21 , ( char * ) & V_12 , ( V_19 ) sizeof( V_12 ) ) < 0 ) {
F_2 ( L_8 , strerror ( V_16 ) ) ;
goto V_20;
}
#endif
memset ( & V_10 , 0x0 , sizeof( V_10 ) ) ;
V_10 . V_22 = V_13 ;
V_10 . V_23 . V_24 = F_7 ( V_25 ) ;
V_10 . V_26 = F_8 ( V_6 ) ;
if ( F_9 ( * V_7 , (struct V_27 * ) & V_10 , ( V_19 ) sizeof( V_10 ) ) < 0 ) {
F_2 ( L_9 , strerror ( V_16 ) ) ;
goto V_20;
}
return V_5 ;
V_20:
F_10 ( * V_7 ) ;
return V_3 ;
}
static void F_11 ( int T_3 V_28 )
{
F_2 ( L_10 ) ;
V_29 = FALSE ;
}
static int F_12 ( const char * V_30 , T_4 * * V_31 )
{
T_5 V_32 = 0 ;
int V_33 ;
if ( ! F_13 ( V_30 , L_11 ) ) {
* V_31 = stdout ;
return V_5 ;
}
* V_31 = fopen ( V_30 , L_12 ) ;
if ( ! ( * V_31 ) ) {
F_2 ( L_13 , F_14 ( V_16 ) ) ;
return V_3 ;
}
if ( ! F_15 ( * V_31 , 252 , V_34 , FALSE , & V_32 , & V_33 ) ) {
F_2 ( L_14 ) ;
return V_3 ;
}
return V_5 ;
}
static void F_16 ( char * V_35 , T_6 * V_36 , const char * V_37 )
{
T_7 V_38 = strlen ( V_37 ) ;
T_1 V_39 = ( T_1 ) ( ( V_38 + 3 ) & 0xfffffffc ) ;
V_35 [ * V_36 ] = 0 ;
V_35 [ * V_36 + 1 ] = V_40 ;
* V_36 += 2 ;
V_35 [ * V_36 ] = V_39 >> 8 ;
V_35 [ * V_36 + 1 ] = V_39 & 0xff ;
* V_36 += 2 ;
memcpy ( V_35 + * V_36 , V_37 , V_38 ) ;
* V_36 += V_39 ;
}
static void F_17 ( char * V_35 , T_6 * V_36 , T_8 V_41 )
{
V_35 [ * V_36 ] = 0x00 ;
V_35 [ * V_36 + 1 ] = V_42 ;
V_35 [ * V_36 + 2 ] = 0 ;
V_35 [ * V_36 + 3 ] = 4 ;
* V_36 += 4 ;
memcpy ( V_35 + * V_36 , & V_41 , 4 ) ;
* V_36 += 4 ;
}
static void F_18 ( char * V_35 , T_6 * V_36 , T_8 V_43 )
{
V_35 [ * V_36 ] = 0 ;
V_35 [ * V_36 + 1 ] = V_44 ;
V_35 [ * V_36 + 2 ] = 0 ;
V_35 [ * V_36 + 3 ] = 4 ;
* V_36 += 4 ;
memcpy ( V_35 + * V_36 , & V_43 , 4 ) ;
* V_36 += 4 ;
}
static void F_19 ( char * V_35 , T_6 * V_36 , T_9 V_45 )
{
T_8 V_6 = F_7 ( V_45 ) ;
V_35 [ * V_36 ] = 0 ;
V_35 [ * V_36 + 1 ] = V_46 ;
V_35 [ * V_36 + 2 ] = 0 ;
V_35 [ * V_36 + 3 ] = 4 ;
* V_36 += 4 ;
memcpy ( V_35 + * V_36 , & V_6 , 4 ) ;
* V_36 += 4 ;
}
static void F_20 ( char * V_35 , T_6 * V_36 , T_9 V_47 )
{
T_8 V_6 = F_7 ( V_47 ) ;
V_35 [ * V_36 ] = 0 ;
V_35 [ * V_36 + 1 ] = V_48 ;
V_35 [ * V_36 + 2 ] = 0 ;
V_35 [ * V_36 + 3 ] = 4 ;
* V_36 += 4 ;
memcpy ( V_35 + * V_36 , & V_6 , 4 ) ;
* V_36 += 4 ;
}
static void F_21 ( char * V_35 , T_6 * V_36 )
{
memset ( V_35 + * V_36 , 0x0 , 4 ) ;
* V_36 += 4 ;
}
static int F_22 ( const char * V_37 , const T_1 V_49 , const char * V_50 ,
const T_10 V_51 , const struct V_9 V_52 , T_4 * V_31 )
{
char * V_35 ;
T_6 V_36 = 0 ;
T_11 V_53 = time ( NULL ) ;
T_5 V_32 = 0 ;
int V_33 ;
int V_54 = V_5 ;
V_35 = ( char * ) F_23 ( V_55 + ( ( strlen ( V_37 ) + 3 ) & 0xfffffffc ) + V_51 ) ;
F_16 ( V_35 , & V_36 , V_37 ) ;
F_17 ( V_35 , & V_36 , V_52 . V_23 . V_24 ) ;
F_18 ( V_35 , & V_36 , F_24 ( L_15 ) ) ;
F_19 ( V_35 , & V_36 , V_52 . V_26 ) ;
F_20 ( V_35 , & V_36 , V_49 ) ;
F_21 ( V_35 , & V_36 ) ;
memcpy ( V_35 + V_36 , V_50 , V_51 ) ;
V_36 += ( T_6 ) V_51 ;
if ( ! F_25 ( V_31 , V_53 , ( V_56 ) ( V_53 / 1000 ) , V_36 , V_36 , V_35 , & V_32 , & V_33 ) ) {
F_2 ( L_16 ) ;
V_54 = V_3 ;
}
fflush ( V_31 ) ;
F_26 ( V_35 ) ;
return V_54 ;
}
static void F_27 ( const char * V_30 , const T_1 V_6 , const char * V_37 )
{
struct V_9 V_52 ;
int V_57 = sizeof( V_52 ) ;
T_2 V_7 ;
char * V_50 ;
T_10 V_51 ;
T_4 * V_31 = NULL ;
if ( signal ( V_58 , F_11 ) == V_59 ) {
F_2 ( L_17 ) ;
return;
}
if ( F_12 ( V_30 , & V_31 ) == V_3 ) {
if ( V_31 )
fclose ( V_31 ) ;
return;
}
if ( F_3 ( V_6 , & V_7 ) == V_3 )
return;
F_28 ( L_18 , V_6 ) ;
V_50 = ( char * ) F_29 ( V_60 ) ;
while( V_29 == TRUE ) {
memset ( V_50 , 0x0 , V_60 ) ;
V_51 = F_30 ( V_7 , V_50 , V_60 , 0 , (struct V_27 * ) & V_52 , & V_57 ) ;
if ( V_51 < 0 ) {
switch( V_16 ) {
case V_61 :
case V_62 :
break;
default:
#ifdef F_4
{
T_12 * V_63 = NULL ;
int V_33 = F_31 () ;
F_32 ( V_64 | V_65 | V_66 ,
NULL , V_33 ,
F_33 ( V_67 , V_68 ) ,
( V_69 ) & V_63 , 0 , NULL ) ;
F_2 ( L_19 , V_63 , V_33 ) ;
F_34 ( V_63 ) ;
}
#else
F_2 ( L_20 , strerror ( V_16 ) , V_16 ) ;
#endif
V_29 = FALSE ;
break;
}
} else {
if ( F_22 ( V_37 , V_6 , V_50 , V_51 , V_52 , V_31 ) == V_3 )
V_29 = FALSE ;
}
}
fclose ( V_31 ) ;
F_10 ( V_7 ) ;
F_26 ( V_50 ) ;
}
int main ( int V_70 , char * V_71 [] )
{
int V_72 = 0 ;
int V_73 ;
T_1 V_6 = 0 ;
int V_54 = V_3 ;
T_13 * V_74 = F_35 ( T_13 , 1 ) ;
char * V_75 ;
char * V_76 = NULL ;
char * V_77 = NULL ;
char * V_78 = NULL ;
#ifdef F_4
T_14 V_79 ;
F_36 () ;
#endif
V_75 = F_37 ( L_21 ) ;
F_38 ( V_74 , V_71 [ 0 ] , V_80 , V_81 , V_82 ,
V_75 ) ;
F_26 ( V_75 ) ;
F_39 ( V_74 , V_83 , L_22 , 252 , L_23 ) ;
V_76 = F_40 (
L_24
L_25
L_26
L_27 ,
V_71 [ 0 ] , V_71 [ 0 ] , V_83 , V_71 [ 0 ] , V_83 , V_71 [ 0 ] , V_83 ) ;
F_41 ( V_74 , V_76 ) ;
F_26 ( V_76 ) ;
F_42 ( V_74 , L_28 , L_29 ) ;
F_42 ( V_74 , L_30 , L_31 ) ;
V_78 = F_40 ( L_32 , V_4 ) ;
F_42 ( V_74 , L_33 , V_78 ) ;
F_26 ( V_78 ) ;
V_84 = 0 ;
V_85 = 0 ;
if ( V_70 == 1 ) {
F_43 ( V_74 ) ;
goto V_86;
}
while ( ( V_73 = F_44 ( V_70 , V_71 , L_34 , V_87 , & V_72 ) ) != - 1 ) {
switch ( V_73 ) {
case V_88 :
F_43 ( V_74 ) ;
V_54 = V_5 ;
goto V_86;
case V_89 :
printf ( L_35 , V_74 -> V_90 ) ;
goto V_86;
case V_91 :
if ( ! F_45 ( V_92 , NULL , & V_6 ) ) {
F_2 ( L_36 , V_92 ) ;
goto V_86;
}
break;
case V_93 :
F_26 ( V_77 ) ;
V_77 = F_46 ( V_92 ) ;
break;
case ':' :
F_2 ( L_37 , V_71 [ V_85 - 1 ] ) ;
break;
default:
if ( ! F_47 ( V_74 , V_73 - V_94 , V_92 ) ) {
F_2 ( L_38 , V_71 [ V_85 - 1 ] ) ;
goto V_86;
}
}
}
if ( V_85 != V_70 ) {
F_2 ( L_39 , V_71 [ V_85 ] ) ;
goto V_86;
}
if ( F_48 ( V_74 ) ) {
V_54 = V_5 ;
goto V_86;
}
if ( V_74 -> V_95 ) {
V_54 = F_1 ( V_74 -> V_1 ) ;
goto V_86;
}
if ( ! V_77 )
V_77 = F_46 ( L_40 ) ;
#ifdef F_4
V_73 = F_49 ( F_50 ( 1 , 1 ) , & V_79 ) ;
if ( V_73 != 0 ) {
F_2 ( L_41 , V_73 ) ;
goto V_86;
}
#endif
if ( V_6 == 0 )
V_6 = V_4 ;
if ( V_74 -> V_96 )
F_27 ( V_74 -> V_30 , V_6 , V_77 ) ;
V_86:
F_51 ( & V_74 ) ;
F_26 ( V_77 ) ;
return V_54 ;
}
int T_15
F_52 ( struct V_97 * V_98 ,
struct V_97 * V_99 ,
char * V_100 ,
int V_101 )
{
return main ( V_102 , V_103 ) ;
}
