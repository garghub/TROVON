static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_5 [] = {
{
. V_6 = V_7 ,
. V_8 = F_2 ( V_9 ) ,
. V_10 = F_2 ( V_9 ) + 0xf
} , {
. V_6 = V_7 ,
. V_8 = F_3 ( 8 , 0 ) ,
. V_10 = F_3 ( 8 , 0 ) + 0x7
}
} ;
V_2 = F_4 ( L_1 , - 1 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_3 = F_5 ( V_2 , V_5 ,
F_6 ( V_5 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static int T_1 F_9 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_14 [] = {
{
. V_6 = V_7 ,
} , {
. V_6 = V_15 ,
}
} ;
if ( ! F_10 ( V_16 ) )
return 0 ;
if ( F_11 () || F_12 () )
return 0 ;
V_2 = F_4 ( L_2 , 0 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_14 [ 0 ] . V_8 = 0x00016F0000000000ULL ;
V_14 [ 0 ] . V_10 = V_14 [ 0 ] . V_8 + 0x100 ;
V_14 [ 1 ] . V_8 = V_17 ;
V_14 [ 1 ] . V_10 = V_17 ;
V_3 = F_5 ( V_2 , V_14 ,
F_6 ( V_14 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static int T_1 F_13 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
struct V_4 V_14 [] = {
{
. V_6 = V_7 ,
} , {
. V_6 = V_15 ,
}
} ;
if ( ! F_10 ( V_16 ) )
return 0 ;
if ( F_11 () || F_12 () )
return 0 ;
V_2 = F_4 ( L_3 , 0 ) ;
if ( ! V_2 ) {
V_3 = - V_11 ;
goto V_12;
}
V_14 [ 0 ] . V_8 = 0x00016F0000000400ULL ;
V_14 [ 0 ] . V_10 = V_14 [ 0 ] . V_8 + 0x100 ;
V_14 [ 1 ] . V_8 = V_17 ;
V_14 [ 1 ] . V_10 = V_17 ;
V_3 = F_5 ( V_2 , V_14 ,
F_6 ( V_14 ) ) ;
if ( V_3 )
goto V_13;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
return V_3 ;
V_13:
F_8 ( V_2 ) ;
V_12:
return V_3 ;
}
static bool T_1 F_14 ( void )
{
return ! F_10 ( V_18 ) &&
! F_10 ( V_19 ) &&
! F_10 ( V_20 ) ;
}
static void T_1 F_15 ( int V_21 , int V_22 )
{
const T_2 * V_23 ;
const T_2 * V_24 ;
const T_2 * V_25 ;
T_3 V_26 ;
int V_27 ;
int V_28 ;
const char * V_29 ;
int V_30 ;
char V_31 [ 20 ] ;
V_23 = F_16 ( V_32 , V_21 , L_4 , NULL ) ;
if ( ! V_23 )
return;
V_26 = F_17 ( V_23 ) ;
V_27 = F_18 ( V_32 , V_26 ) ;
V_24 = F_16 ( V_32 , V_21 , L_5 , NULL ) ;
if ( V_24 ) {
T_3 V_33 = F_17 ( V_24 ) ;
V_28 = F_18 ( V_32 , V_33 ) ;
} else {
V_28 = - 1 ;
}
if ( V_22 < 0 || V_27 < 0 ) {
F_19 ( V_32 , V_21 , L_4 ) ;
F_19 ( V_32 , V_21 , L_5 ) ;
if ( V_27 >= 0 )
F_20 ( V_32 , V_27 ) ;
if ( V_28 >= 0 )
F_20 ( V_32 , V_28 ) ;
return;
}
if ( V_22 >= 256 && V_28 > 0 ) {
const struct V_34 * V_35 ;
struct V_34 * V_36 ;
T_3 V_37 ;
V_35 = F_21 ( V_32 , V_21 , L_4 , NULL ) ;
V_37 = V_35 -> V_38 ;
F_20 ( V_32 , V_27 ) ;
F_19 ( V_32 , V_21 , L_4 ) ;
V_36 = F_22 ( V_32 , V_21 , L_5 , NULL ) ;
V_36 -> V_38 = V_37 ;
V_27 = V_28 ;
}
V_22 &= 0xff ;
if ( F_14 () ) {
F_19 ( V_32 , V_27 , L_6 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
strcpy ( V_31 , L_7 ) ;
V_29 = F_16 ( V_32 , V_27 , L_8 ,
& V_30 ) ;
if ( V_29 && V_30 >= strlen ( V_31 ) )
F_23 ( V_32 , V_27 ,
L_8 , V_31 , V_30 ) ;
}
V_25 = F_16 ( V_32 , V_27 , L_9 , NULL ) ;
if ( V_22 == F_17 ( V_25 ) )
return;
F_24 ( V_32 , V_27 , L_9 , V_22 ) ;
snprintf ( V_31 , sizeof( V_31 ) , L_10 , V_22 ) ;
V_29 = F_25 ( V_32 , V_27 , & V_30 ) ;
if ( V_29 && V_30 == strlen ( V_31 ) )
F_26 ( V_32 , V_27 , V_31 ) ;
else
F_27 ( L_11 , V_29 ) ;
}
static void T_1 F_28 ( int V_39 , T_4 * V_40 )
{
T_5 V_41 [ 6 ] ;
T_4 V_42 = * V_40 ;
int V_43 ;
V_41 [ 0 ] = ( V_42 >> 40 ) & 0xff ;
V_41 [ 1 ] = ( V_42 >> 32 ) & 0xff ;
V_41 [ 2 ] = ( V_42 >> 24 ) & 0xff ;
V_41 [ 3 ] = ( V_42 >> 16 ) & 0xff ;
V_41 [ 4 ] = ( V_42 >> 8 ) & 0xff ;
V_41 [ 5 ] = V_42 & 0xff ;
V_43 = F_23 ( V_32 , V_39 , L_12 ,
V_41 , sizeof( V_41 ) ) ;
if ( V_43 ) {
F_27 ( L_13 , V_43 ) ;
return;
}
* V_40 = V_42 + 1 ;
}
static void T_1 F_29 ( int V_44 )
{
const T_2 * V_23 ;
V_23 = F_16 ( V_32 , V_44 , L_4 , NULL ) ;
if ( V_23 ) {
T_3 V_45 = F_17 ( V_23 ) ;
int V_29 = F_18 ( V_32 , V_45 ) ;
if ( V_29 >= 0 )
F_20 ( V_32 , V_29 ) ;
}
F_20 ( V_32 , V_44 ) ;
}
static void T_1 F_30 ( int V_46 , int V_47 , int V_29 , int V_48 , T_4 * V_40 )
{
char V_49 [ 20 ] ;
int V_21 ;
int V_22 ;
int V_50 ;
snprintf ( V_49 , sizeof( V_49 ) , L_14 , V_29 ) ;
V_21 = F_31 ( V_32 , V_46 , V_49 ) ;
if ( V_21 < 0 )
return;
if ( V_29 > V_48 ) {
F_32 ( L_15 , V_47 , V_29 ) ;
F_29 ( V_21 ) ;
return;
}
if ( F_10 ( V_51 ) )
V_50 = ( 0x100 * V_47 ) + ( 0x10 * V_29 ) + 0x800 ;
else
V_50 = 16 * V_47 + V_29 ;
V_22 = F_33 ( V_50 ) ;
F_15 ( V_21 , V_22 ) ;
F_28 ( V_21 , V_40 ) ;
}
static void T_1 F_34 ( int V_52 , int V_53 , T_4 * V_40 )
{
char V_49 [ 20 ] ;
int V_46 ;
int V_29 ;
int V_54 = 0 ;
snprintf ( V_49 , sizeof( V_49 ) , L_16 , V_53 ) ;
V_46 = F_31 ( V_32 , V_52 , V_49 ) ;
if ( V_46 < 0 )
return;
if ( F_35 ( V_53 ) == 0 )
V_54 = F_36 ( V_53 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ )
F_30 ( V_46 , V_53 , V_29 , V_54 - 1 , V_40 ) ;
}
int T_1 F_37 ( void )
{
int V_47 , V_55 , V_56 ;
const char * V_57 ;
const char * V_58 ;
char V_49 [ 20 ] ;
int V_59 ;
T_4 V_60 ;
if ( F_38 ( V_32 ) )
F_39 ( L_17 ) ;
V_59 = F_40 ( V_32 , L_18 ) ;
if ( V_59 < 0 ) {
F_27 ( L_19 ) ;
return - V_61 ;
}
V_60 =
( ( V_62 -> V_60 [ 0 ] & 0xffull ) ) << 40 |
( ( V_62 -> V_60 [ 1 ] & 0xffull ) ) << 32 |
( ( V_62 -> V_60 [ 2 ] & 0xffull ) ) << 24 |
( ( V_62 -> V_60 [ 3 ] & 0xffull ) ) << 16 |
( ( V_62 -> V_60 [ 4 ] & 0xffull ) ) << 8 |
( V_62 -> V_60 [ 5 ] & 0xffull ) ;
if ( F_10 ( V_18 ) || F_10 ( V_16 ) )
V_55 = 2 ;
else if ( F_10 ( V_20 ) || F_10 ( V_51 ) )
V_55 = 1 ;
else
V_55 = 0 ;
if ( V_62 -> V_63 == V_64 )
V_55 = 0 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_65 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_20 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_65 = F_40 ( V_32 , V_58 ) ;
if ( V_65 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_21 , V_47 ) ;
F_29 ( V_65 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
} else {
int V_22 = F_33 ( V_66 + V_47 ) ;
F_15 ( V_65 , V_22 ) ;
F_28 ( V_65 , & V_60 ) ;
}
}
}
V_57 = F_16 ( V_32 , V_59 , L_22 , NULL ) ;
if ( V_57 ) {
int V_52 = F_40 ( V_32 , V_57 ) ;
if ( V_52 >= 0 )
for ( V_47 = 0 ; V_47 <= 4 ; V_47 ++ )
F_34 ( V_52 , V_47 , & V_60 ) ;
}
if ( F_10 ( V_18 ) ||
F_10 ( V_16 ) ||
F_10 ( V_51 ) ||
F_10 ( V_20 ) )
V_55 = 2 ;
else
V_55 = 1 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_67 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_23 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_67 = F_40 ( V_32 , V_58 ) ;
if ( V_67 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_24 , V_47 ) ;
F_20 ( V_32 , V_67 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
}
if ( F_10 ( V_51 ) )
V_55 = 4 ;
else if ( F_10 ( V_18 ) ||
F_10 ( V_16 ) ||
F_10 ( V_20 ) )
V_55 = 2 ;
else
V_55 = 1 ;
for ( V_47 = 0 ; V_47 < 2 ; V_47 ++ ) {
int V_67 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_25 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_67 = F_40 ( V_32 , V_58 ) ;
if ( V_67 < 0 )
continue;
if ( V_47 >= V_55 ) {
F_32 ( L_26 , V_47 ) ;
F_20 ( V_32 , V_67 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
}
V_56 = 3 ;
if ( F_10 ( V_18 ) )
V_56 |= 4 ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
int V_68 ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_27 , V_47 ) ;
V_58 = F_16 ( V_32 , V_59 ,
V_49 , NULL ) ;
if ( V_58 ) {
V_68 = F_40 ( V_32 , V_58 ) ;
if ( V_56 & ( 1 << V_47 ) ) {
T_2 V_69 ;
V_69 = F_41 ( F_42 () ) ;
F_23 ( V_32 ,
V_68 , L_28 ,
& V_69 , sizeof( V_69 ) ) ;
continue;
}
F_32 ( L_29 , V_47 ) ;
F_20 ( V_32 , V_68 ) ;
F_19 ( V_32 , V_59 ,
V_49 ) ;
}
}
V_58 = F_16 ( V_32 , V_59 ,
L_30 , NULL ) ;
if ( V_58 ) {
union V_70 V_71 ;
unsigned long V_72 , V_73 , V_74 ;
unsigned long V_75 = 0 ;
unsigned long V_76 = 0 ;
int V_77 , V_78 ;
bool V_79 = false ;
bool V_80 = false ;
T_2 V_81 [ 6 ] ;
T_2 * V_82 ;
int V_83 ;
int V_84 = F_40 ( V_32 , V_58 ) ;
V_72 = 0 ;
if ( V_62 -> V_85 == 1
&& V_62 -> V_86 >= 1 ) {
if ( V_62 -> V_87 )
V_72 = V_62 -> V_87 ;
} else {
V_72 = 0x1d000800 ;
}
if ( ! V_72 )
goto V_88;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_71 . T_4 = F_43 ( F_44 ( V_77 ) ) ;
V_73 = V_71 . V_89 . V_90 << 16 ;
V_74 = ( V_71 . V_89 . V_91 + 1 ) << 16 ;
if ( V_71 . V_89 . V_92 && V_72 >= V_73
&& V_72 < V_73 + V_74 ) {
V_79 = V_71 . V_89 . V_93 ;
break;
}
}
if ( V_77 >= 7 ) {
goto V_88;
}
if ( ! ( V_72 & 0xfffful ) ) {
V_71 . T_4 =
F_43 ( F_44 ( V_77 + 1 ) ) ;
V_75 = V_71 . V_89 . V_90 << 16 ;
V_76 = ( V_71 . V_89 . V_91 + 1 ) << 16 ;
if ( ! V_71 . V_89 . V_92 )
goto V_88;
V_80 = true ;
} else {
F_19 ( V_32 , V_84 , L_31 ) ;
F_19 ( V_32 , V_84 , L_32 ) ;
if ( ! V_79 ) {
T_2 V_93 = F_41 ( 8 ) ;
F_23 ( V_32 , V_84 ,
L_33 , & V_93 , sizeof( V_93 ) ) ;
}
}
V_81 [ 0 ] = F_41 ( V_77 ) ;
V_81 [ 1 ] = F_41 ( 0 ) ;
V_81 [ 2 ] = F_41 ( 0x10000 ) ;
V_81 [ 3 ] = F_41 ( V_77 + 1 ) ;
V_81 [ 4 ] = F_41 ( 0 ) ;
V_81 [ 5 ] = F_41 ( 0x10000 ) ;
F_23 ( V_32 , V_84 ,
L_9 , V_81 , sizeof( V_81 ) ) ;
V_78 = F_45 ( V_32 , V_84 ) ;
if ( V_78 < 0 )
goto V_88;
V_82 = F_46 ( V_32 , V_78 , L_34 , & V_83 ) ;
if ( ! V_82 || V_83 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_88;
V_82 [ ( V_77 * 5 ) + 2 ] = F_41 ( V_73 >> 32 ) ;
V_82 [ ( V_77 * 5 ) + 3 ] = F_41 ( V_73 & 0xffffffff ) ;
V_82 [ ( V_77 * 5 ) + 4 ] = F_41 ( V_74 ) ;
if ( V_80 ) {
V_77 ++ ;
V_82 [ ( V_77 * 5 ) + 2 ] = F_41 ( V_75 >> 32 ) ;
V_82 [ ( V_77 * 5 ) + 3 ] = F_41 ( V_75 & 0xffffffff ) ;
V_82 [ ( V_77 * 5 ) + 4 ] = F_41 ( V_76 ) ;
}
goto V_94;
V_88:
F_20 ( V_32 , V_84 ) ;
V_94:
;
}
V_58 = F_16 ( V_32 , V_59 ,
L_35 , NULL ) ;
if ( V_58 ) {
union V_70 V_71 ;
unsigned long V_72 , V_73 , V_74 ;
int V_77 , V_78 ;
T_2 V_81 [ 6 ] ;
T_2 * V_82 ;
int V_83 ;
int V_95 = F_40 ( V_32 , V_58 ) ;
V_72 = V_62 -> V_96 ;
if ( V_72 == 0 )
goto V_97;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
V_71 . T_4 = F_43 ( F_44 ( V_77 ) ) ;
V_73 = V_71 . V_89 . V_90 << 16 ;
V_74 = ( V_71 . V_89 . V_91 + 1 ) << 16 ;
if ( V_71 . V_89 . V_92 && V_72 >= V_73
&& V_72 < V_73 + V_74 )
break;
}
if ( V_77 > 7 )
goto V_97;
V_81 [ 0 ] = F_41 ( V_77 ) ;
V_81 [ 1 ] = F_41 ( 0x20 ) ;
V_81 [ 2 ] = F_41 ( 0x20 ) ;
V_81 [ 3 ] = F_41 ( V_77 ) ;
V_81 [ 4 ] = F_41 ( 0 ) ;
V_81 [ 5 ] = F_41 ( 0x20 ) ;
F_23 ( V_32 , V_95 ,
L_9 , V_81 , sizeof( V_81 ) ) ;
V_78 = F_45 ( V_32 , V_95 ) ;
if ( V_78 < 0 )
goto V_97;
V_82 = F_46 ( V_32 , V_78 , L_34 , & V_83 ) ;
if ( ! V_82 || V_83 < ( 5 * 8 * sizeof( T_2 ) ) )
goto V_97;
V_82 [ ( V_77 * 5 ) + 2 ] = F_41 ( V_73 >> 32 ) ;
V_82 [ ( V_77 * 5 ) + 3 ] = F_41 ( V_73 & 0xffffffff ) ;
V_82 [ ( V_77 * 5 ) + 4 ] = F_41 ( V_74 ) ;
goto V_98;
V_97:
F_20 ( V_32 , V_95 ) ;
V_98:
;
}
V_58 = F_16 ( V_32 , V_59 ,
L_36 , NULL ) ;
if ( V_58 ) {
int V_99 = F_40 ( V_32 , V_58 ) ;
if ( V_99 >= 0 && ( ! F_10 ( V_19 ) ||
V_62 -> V_63 == V_100 ) ) {
F_32 ( L_37 ) ;
F_20 ( V_32 , V_99 ) ;
F_19 ( V_32 , V_59 , L_36 ) ;
} else if ( V_62 -> V_63 == V_64 ||
V_62 -> V_63 == V_101 ) {
F_19 ( V_32 , V_99 , L_38 ) ;
}
}
V_58 = F_16 ( V_32 , V_59 ,
L_39 , NULL ) ;
if ( V_58 ) {
int V_102 = F_40 ( V_32 , V_58 ) ;
if ( V_102 >= 0 && ( F_47 () == V_103 ||
! F_48 ( V_104 ) ) ) {
F_32 ( L_40 ) ;
F_20 ( V_32 , V_102 ) ;
F_19 ( V_32 , V_59 , L_39 ) ;
} else {
T_2 V_105 [ 1 ] ;
enum V_106 V_107 ;
V_107 = F_49 () ;
switch ( V_107 ) {
case V_108 :
V_105 [ 0 ] = F_41 ( 48000000 ) ;
F_23 ( V_32 , V_102 ,
L_41 , V_105 , sizeof( V_105 ) ) ;
case V_109 :
F_19 ( V_32 , V_102 , L_38 ) ;
break;
default:
break;
}
}
}
return 0 ;
}
static int T_1 F_50 ( void )
{
return F_51 ( NULL , V_110 , NULL ) ;
}
