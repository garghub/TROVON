static int T_1 F_1 ( void )
{
union V_1 V_2 ;
T_2 V_3 ;
if ( ! F_2 () )
return 0 ;
V_2 . V_4 = F_3 ( F_4 ( 0 ) ) ;
if ( V_2 . V_5 . V_6 ) {
V_3 = F_5 ( V_7 ) ;
V_3 &= ~ V_8 ;
F_6 ( V_7 , V_3 ) ;
F_7 ( 2 ) ;
V_3 |= V_9 ;
F_6 ( V_7 , V_3 ) ;
V_3 = F_5 ( V_10 ) ;
V_3 |= V_8 ;
F_6 ( V_10 , V_3 ) ;
}
return 0 ;
}
static void F_8 ( struct V_11 * V_12 )
{
V_4 div ;
union V_13 V_14 ;
union V_1 V_2 ;
union V_15 V_16 ;
int V_17 ;
unsigned long V_18 ;
T_2 V_19 = 12000000 ;
bool V_20 = false ;
F_9 ( & V_21 ) ;
V_22 ++ ;
if ( V_22 != 1 )
goto exit;
V_18 = 64000000000ull / F_10 () ;
if ( V_12 -> V_23 ) {
struct V_24 * V_25 ;
const char * V_26 ;
V_25 = F_11 ( V_12 -> V_23 ) ;
if ( ! V_25 ) {
F_12 ( V_12 , L_1 ) ;
goto exit;
}
V_17 = F_13 ( V_25 ,
L_2 , & V_19 ) ;
if ( V_17 ) {
F_12 ( V_12 , L_3 ) ;
goto exit;
}
V_17 = F_14 ( V_25 ,
L_4 , & V_26 ) ;
if ( ! V_17 && strcmp ( L_5 , V_26 ) == 0 )
V_20 = true ;
}
V_14 . V_4 = 0 ;
V_14 . V_5 . V_27 = 1 ;
F_15 ( F_16 ( 0 ) , V_14 . V_4 ) ;
for ( V_17 = 0 ; V_17 <= 1 ; V_17 ++ ) {
V_16 . V_4 =
F_3 ( F_17 ( V_17 , 0 ) ) ;
V_16 . V_5 . V_28 = 15 ;
V_16 . V_5 . V_29 = 1 ;
V_16 . V_5 . V_30 = 1 ;
F_15 ( F_17 ( V_17 , 0 ) ,
V_16 . V_4 ) ;
}
V_2 . V_4 = F_3 ( F_4 ( 0 ) ) ;
if ( V_2 . V_5 . V_6 )
goto V_31;
V_2 . V_5 . V_32 = 1 ;
V_2 . V_5 . V_6 = 0 ;
V_2 . V_5 . V_33 = 0 ;
V_2 . V_5 . V_34 = 0 ;
V_2 . V_5 . V_35 = 0 ;
V_2 . V_5 . V_36 = 0 ;
V_2 . V_5 . V_37 = 0 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
V_2 . V_5 . V_38 = V_20 ? 0 : 1 ;
switch ( V_19 ) {
default:
F_18 ( L_6 ,
V_19 ) ;
case 12000000 :
V_2 . V_5 . V_39 = 0 ;
break;
case 24000000 :
V_2 . V_5 . V_39 = 1 ;
break;
case 48000000 :
V_2 . V_5 . V_39 = 2 ;
break;
}
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
div = F_10 () / 130000000ull ;
switch ( div ) {
case 0 :
div = 1 ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
break;
case 5 :
div = 4 ;
break;
case 6 :
case 7 :
div = 6 ;
break;
case 8 :
case 9 :
case 10 :
case 11 :
div = 8 ;
break;
default:
div = 12 ;
break;
}
V_2 . V_5 . V_40 = div ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
V_2 . V_4 = F_3 ( F_4 ( 0 ) ) ;
V_2 . V_5 . V_36 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
V_2 . V_5 . V_34 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_19 ( V_18 ) ;
V_2 . V_5 . V_32 = 0 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_7 ( 3 ) ;
V_2 . V_5 . V_35 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
V_2 . V_5 . V_37 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_19 ( V_18 ) ;
V_2 . V_5 . V_33 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_20 ( 1 ) ;
V_2 . V_5 . V_33 = 0 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_7 ( 1 ) ;
V_2 . V_5 . V_33 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
F_20 ( 1 ) ;
V_2 . V_5 . V_6 = 1 ;
F_15 ( F_4 ( 0 ) , V_2 . V_4 ) ;
V_31:
F_15 ( F_21 ( 0 ) , 0x20ull ) ;
exit:
F_22 ( & V_21 ) ;
}
static void F_23 ( void )
{
F_9 ( & V_21 ) ;
V_22 -- ;
F_22 ( & V_21 ) ;
}
static int F_24 ( struct V_41 * V_42 )
{
F_8 ( & V_42 -> V_12 ) ;
return 0 ;
}
static void F_25 ( struct V_41 * V_42 )
{
F_23 () ;
}
static void T_1 F_26 ( struct V_11 * V_12 )
{
union V_43 V_44 ;
F_8 ( V_12 ) ;
V_44 . V_4 = F_3 ( F_27 ( 0 ) ) ;
V_44 . V_5 . V_45 = 1 ;
V_44 . V_5 . V_46 = 0 ;
#ifdef F_28
V_44 . V_5 . V_47 = 1 ;
V_44 . V_5 . V_48 = 1 ;
#else
V_44 . V_5 . V_47 = 0 ;
V_44 . V_5 . V_48 = 0 ;
V_44 . V_5 . V_49 = 1 ;
#endif
F_15 ( F_27 ( 0 ) , V_44 . V_4 ) ;
F_23 () ;
}
static int T_1 F_29 ( void )
{
struct V_41 * V_50 ;
struct V_24 * V_51 ;
int V_52 = 0 ;
V_51 = F_30 ( NULL , L_7 ) ;
if ( ! V_51 )
return 0 ;
V_50 = F_31 ( V_51 ) ;
if ( ! V_50 )
return 0 ;
V_50 -> V_12 . V_53 = & V_54 ;
F_26 ( & V_50 -> V_12 ) ;
return V_52 ;
}
static int F_32 ( struct V_41 * V_42 )
{
F_8 ( & V_42 -> V_12 ) ;
return 0 ;
}
static void F_33 ( struct V_41 * V_42 )
{
F_23 () ;
}
static void T_1 F_34 ( struct V_11 * V_12 )
{
union V_55 V_56 ;
F_8 ( V_12 ) ;
V_56 . V_4 = F_3 ( F_35 ( 0 ) ) ;
V_56 . V_5 . V_46 = 0 ;
#ifdef F_28
V_56 . V_5 . V_47 = 1 ;
V_56 . V_5 . V_48 = 1 ;
#else
V_56 . V_5 . V_47 = 0 ;
V_56 . V_5 . V_48 = 0 ;
V_56 . V_5 . V_49 = 1 ;
#endif
F_15 ( F_35 ( 0 ) , V_56 . V_4 ) ;
F_23 () ;
}
static int T_1 F_36 ( void )
{
struct V_41 * V_50 ;
struct V_24 * V_57 ;
int V_52 = 0 ;
V_57 = F_30 ( NULL , L_8 ) ;
if ( ! V_57 )
return 0 ;
V_50 = F_31 ( V_57 ) ;
if ( ! V_50 )
return 0 ;
V_50 -> V_12 . V_53 = & V_58 ;
F_34 ( & V_50 -> V_12 ) ;
return V_52 ;
}
static int T_1 F_37 ( void )
{
struct V_41 * V_50 ;
int V_52 = 0 ;
struct V_59 V_60 [] = {
{
. V_61 = V_62 ,
. V_63 = F_38 ( V_64 ) ,
. V_65 = F_38 ( V_64 ) + 0xf
} , {
. V_61 = V_62 ,
. V_63 = F_39 ( 8 , 0 ) ,
. V_65 = F_39 ( 8 , 0 ) + 0x7
}
} ;
V_50 = F_40 ( L_9 , - 1 ) ;
if ( ! V_50 ) {
V_52 = - V_66 ;
goto V_67;
}
V_52 = F_41 ( V_50 , V_60 ,
F_42 ( V_60 ) ) ;
if ( V_52 )
goto V_68;
V_52 = F_43 ( V_50 ) ;
if ( V_52 )
goto V_68;
return V_52 ;
V_68:
F_44 ( V_50 ) ;
V_67:
return V_52 ;
}
static bool T_1 F_45 ( void )
{
return ! F_46 ( V_69 ) &&
! F_46 ( V_70 ) &&
! F_46 ( V_71 ) ;
}
static void T_1 F_47 ( int V_72 , int V_73 )
{
const T_3 * V_74 ;
const T_3 * V_75 ;
const T_3 * V_76 ;
T_2 V_77 ;
int V_78 ;
int V_79 ;
const char * V_80 ;
int V_81 ;
char V_82 [ 20 ] ;
V_74 = F_48 ( V_83 , V_72 , L_10 , NULL ) ;
if ( ! V_74 )
return;
V_77 = F_49 ( V_74 ) ;
V_78 = F_50 ( V_83 , V_77 ) ;
V_75 = F_48 ( V_83 , V_72 , L_11 , NULL ) ;
if ( V_75 ) {
T_2 V_84 = F_49 ( V_75 ) ;
V_79 = F_50 ( V_83 , V_84 ) ;
} else {
V_79 = - 1 ;
}
if ( V_73 < 0 || V_78 < 0 ) {
F_51 ( V_83 , V_72 , L_10 ) ;
F_51 ( V_83 , V_72 , L_11 ) ;
if ( V_78 >= 0 )
F_52 ( V_83 , V_78 ) ;
if ( V_79 >= 0 )
F_52 ( V_83 , V_79 ) ;
return;
}
if ( V_73 >= 256 && V_79 > 0 ) {
const struct V_85 * V_86 ;
struct V_85 * V_87 ;
T_2 V_88 ;
V_86 = F_53 ( V_83 , V_72 , L_10 , NULL ) ;
V_88 = V_86 -> V_89 ;
F_52 ( V_83 , V_78 ) ;
F_51 ( V_83 , V_72 , L_10 ) ;
V_87 = F_54 ( V_83 , V_72 , L_11 , NULL ) ;
V_87 -> V_89 = V_88 ;
V_78 = V_79 ;
}
V_73 &= 0xff ;
if ( F_45 () ) {
F_51 ( V_83 , V_78 , L_12 ) ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
strcpy ( V_82 , L_13 ) ;
V_80 = F_48 ( V_83 , V_78 , L_14 ,
& V_81 ) ;
if ( V_80 && V_81 >= strlen ( V_82 ) )
F_55 ( V_83 , V_78 ,
L_14 , V_82 , V_81 ) ;
}
V_76 = F_48 ( V_83 , V_78 , L_15 , NULL ) ;
if ( V_73 == F_49 ( V_76 ) )
return;
F_56 ( V_83 , V_78 , L_15 , V_73 ) ;
snprintf ( V_82 , sizeof( V_82 ) , L_16 , V_73 ) ;
V_80 = F_57 ( V_83 , V_78 , & V_81 ) ;
if ( V_80 && V_81 == strlen ( V_82 ) )
F_58 ( V_83 , V_78 , V_82 ) ;
else
F_18 ( L_17 , V_80 ) ;
}
static void T_1 F_59 ( int V_90 , V_4 * V_91 )
{
const T_4 * V_92 ;
int V_93 ;
T_4 V_94 [ 6 ] ;
V_4 V_95 = * V_91 ;
int V_96 ;
V_92 = F_48 ( V_83 , V_90 , L_18 ,
& V_93 ) ;
if ( ! V_92 || V_93 != 6 || F_60 ( V_92 ) )
return;
V_94 [ 0 ] = ( V_95 >> 40 ) & 0xff ;
V_94 [ 1 ] = ( V_95 >> 32 ) & 0xff ;
V_94 [ 2 ] = ( V_95 >> 24 ) & 0xff ;
V_94 [ 3 ] = ( V_95 >> 16 ) & 0xff ;
V_94 [ 4 ] = ( V_95 >> 8 ) & 0xff ;
V_94 [ 5 ] = V_95 & 0xff ;
V_96 = F_55 ( V_83 , V_90 , L_18 ,
V_94 , sizeof( V_94 ) ) ;
if ( V_96 ) {
F_18 ( L_19 , V_96 ) ;
return;
}
* V_91 = V_95 + 1 ;
}
static void T_1 F_61 ( int V_97 )
{
const T_3 * V_74 ;
V_74 = F_48 ( V_83 , V_97 , L_10 , NULL ) ;
if ( V_74 ) {
T_2 V_98 = F_49 ( V_74 ) ;
int V_80 = F_50 ( V_83 , V_98 ) ;
if ( V_80 >= 0 )
F_52 ( V_83 , V_80 ) ;
}
F_52 ( V_83 , V_97 ) ;
}
static void T_1 F_62 ( int V_99 , int V_17 , int V_80 , int V_100 )
{
char V_101 [ 20 ] ;
int V_72 ;
int V_73 ;
int V_102 ;
snprintf ( V_101 , sizeof( V_101 ) , L_20 , V_80 ) ;
V_72 = F_63 ( V_83 , V_99 , V_101 ) ;
if ( V_72 < 0 )
return;
if ( V_80 > V_100 ) {
F_64 ( L_21 , V_17 , V_80 ) ;
F_61 ( V_72 ) ;
return;
}
if ( F_46 ( V_103 ) )
V_102 = ( 0x100 * V_17 ) + ( 0x10 * V_80 ) + 0x800 ;
else
V_102 = 16 * V_17 + V_80 ;
V_73 = F_65 ( V_102 ) ;
F_47 ( V_72 , V_73 ) ;
}
static void T_1 F_66 ( int V_104 , int V_105 )
{
char V_101 [ 20 ] ;
int V_99 ;
int V_80 ;
int V_106 = 0 ;
snprintf ( V_101 , sizeof( V_101 ) , L_22 , V_105 ) ;
V_99 = F_63 ( V_83 , V_104 , V_101 ) ;
if ( V_99 < 0 )
return;
if ( F_67 ( V_105 ) == 0 )
V_106 = F_68 ( V_105 ) ;
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ )
F_62 ( V_99 , V_105 , V_80 , V_106 - 1 ) ;
}
void T_1 F_69 ( void )
{
const char * V_107 ;
char V_101 [ 20 ] ;
V_4 V_108 ;
int V_109 ;
int V_104 ;
int V_17 ;
V_109 = F_70 ( V_83 , L_23 ) ;
if ( V_109 < 0 )
return;
V_108 =
( ( V_110 -> V_108 [ 0 ] & 0xffull ) ) << 40 |
( ( V_110 -> V_108 [ 1 ] & 0xffull ) ) << 32 |
( ( V_110 -> V_108 [ 2 ] & 0xffull ) ) << 24 |
( ( V_110 -> V_108 [ 3 ] & 0xffull ) ) << 16 |
( ( V_110 -> V_108 [ 4 ] & 0xffull ) ) << 8 |
( V_110 -> V_108 [ 5 ] & 0xffull ) ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_111 ;
snprintf ( V_101 , sizeof( V_101 ) , L_24 , V_17 ) ;
V_107 = F_48 ( V_83 , V_109 ,
V_101 , NULL ) ;
if ( ! V_107 )
continue;
V_111 = F_70 ( V_83 , V_107 ) ;
if ( V_111 < 0 )
continue;
F_59 ( V_111 , & V_108 ) ;
}
V_107 = F_48 ( V_83 , V_109 , L_25 , NULL ) ;
if ( ! V_107 )
return;
V_104 = F_70 ( V_83 , V_107 ) ;
if ( V_104 < 0 )
return;
for ( V_17 = 0 ; V_17 <= 4 ; V_17 ++ ) {
int V_99 ;
int V_80 ;
snprintf ( V_101 , sizeof( V_101 ) , L_22 , V_17 ) ;
V_99 = F_63 ( V_83 , V_104 ,
V_101 ) ;
if ( V_99 < 0 )
continue;
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ ) {
int V_72 ;
snprintf ( V_101 , sizeof( V_101 ) ,
L_20 , V_80 ) ;
V_72 = F_63 ( V_83 , V_99 ,
V_101 ) ;
if ( V_72 < 0 )
continue;
F_59 ( V_72 , & V_108 ) ;
}
}
}
int T_1 F_71 ( void )
{
int V_17 , V_112 , V_113 ;
const char * V_114 ;
const char * V_107 ;
char V_101 [ 20 ] ;
int V_109 ;
if ( F_72 ( V_83 ) )
F_73 ( L_26 ) ;
F_74 ( V_110 -> V_115 == V_116 ,
L_27 ,
F_75 ( V_110 -> V_115 ) ) ;
V_109 = F_70 ( V_83 , L_23 ) ;
if ( V_109 < 0 ) {
F_18 ( L_28 ) ;
return - V_117 ;
}
if ( F_46 ( V_69 ) || F_46 ( V_118 ) )
V_112 = 2 ;
else if ( F_46 ( V_71 ) || F_46 ( V_103 ) )
V_112 = 1 ;
else
V_112 = 0 ;
if ( V_110 -> V_115 == V_119 )
V_112 = 0 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_111 ;
snprintf ( V_101 , sizeof( V_101 ) ,
L_24 , V_17 ) ;
V_107 = F_48 ( V_83 , V_109 ,
V_101 , NULL ) ;
if ( V_107 ) {
V_111 = F_70 ( V_83 , V_107 ) ;
if ( V_111 < 0 )
continue;
if ( V_17 >= V_112 ) {
F_64 ( L_29 , V_17 ) ;
F_61 ( V_111 ) ;
F_51 ( V_83 , V_109 ,
V_101 ) ;
} else {
int V_73 = F_65 ( V_120 + V_17 ) ;
F_47 ( V_111 , V_73 ) ;
}
}
}
V_114 = F_48 ( V_83 , V_109 , L_25 , NULL ) ;
if ( V_114 ) {
int V_104 = F_70 ( V_83 , V_114 ) ;
if ( V_104 >= 0 )
for ( V_17 = 0 ; V_17 <= 4 ; V_17 ++ )
F_66 ( V_104 , V_17 ) ;
}
if ( F_46 ( V_69 ) ||
F_46 ( V_118 ) ||
F_46 ( V_103 ) ||
F_46 ( V_71 ) )
V_112 = 2 ;
else
V_112 = 1 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_121 ;
snprintf ( V_101 , sizeof( V_101 ) ,
L_30 , V_17 ) ;
V_107 = F_48 ( V_83 , V_109 ,
V_101 , NULL ) ;
if ( V_107 ) {
V_121 = F_70 ( V_83 , V_107 ) ;
if ( V_121 < 0 )
continue;
if ( V_17 >= V_112 ) {
F_64 ( L_31 , V_17 ) ;
F_52 ( V_83 , V_121 ) ;
F_51 ( V_83 , V_109 ,
V_101 ) ;
}
}
}
if ( F_46 ( V_103 ) )
V_112 = 4 ;
else if ( F_46 ( V_69 ) ||
F_46 ( V_118 ) ||
F_46 ( V_71 ) )
V_112 = 2 ;
else
V_112 = 1 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_121 ;
snprintf ( V_101 , sizeof( V_101 ) ,
L_32 , V_17 ) ;
V_107 = F_48 ( V_83 , V_109 ,
V_101 , NULL ) ;
if ( V_107 ) {
V_121 = F_70 ( V_83 , V_107 ) ;
if ( V_121 < 0 )
continue;
if ( V_17 >= V_112 ) {
F_64 ( L_33 , V_17 ) ;
F_52 ( V_83 , V_121 ) ;
F_51 ( V_83 , V_109 ,
V_101 ) ;
}
}
}
V_113 = 3 ;
if ( F_46 ( V_69 ) )
V_113 |= 4 ;
for ( V_17 = 0 ; V_17 < 3 ; V_17 ++ ) {
int V_122 ;
snprintf ( V_101 , sizeof( V_101 ) ,
L_34 , V_17 ) ;
V_107 = F_48 ( V_83 , V_109 ,
V_101 , NULL ) ;
if ( V_107 ) {
V_122 = F_70 ( V_83 , V_107 ) ;
if ( V_113 & ( 1 << V_17 ) ) {
T_3 V_123 ;
V_123 = F_76 ( F_10 () ) ;
F_55 ( V_83 ,
V_122 , L_35 ,
& V_123 , sizeof( V_123 ) ) ;
continue;
}
F_64 ( L_36 , V_17 ) ;
F_52 ( V_83 , V_122 ) ;
F_51 ( V_83 , V_109 ,
V_101 ) ;
}
}
V_107 = F_48 ( V_83 , V_109 ,
L_37 , NULL ) ;
if ( V_107 ) {
union V_124 V_125 ;
unsigned long V_126 , V_127 , V_128 ;
unsigned long V_129 = 0 ;
unsigned long V_130 = 0 ;
int V_131 , V_132 ;
bool V_133 = false ;
bool V_134 = false ;
T_3 V_135 [ 6 ] ;
T_3 * V_136 ;
int V_137 ;
int V_138 = F_70 ( V_83 , V_107 ) ;
V_126 = 0 ;
if ( V_110 -> V_139 == 1
&& V_110 -> V_140 >= 1 ) {
if ( V_110 -> V_141 )
V_126 = V_110 -> V_141 ;
} else {
V_126 = 0x1d000800 ;
}
if ( ! V_126 )
goto V_142;
for ( V_131 = 0 ; V_131 < 8 ; V_131 ++ ) {
V_125 . V_4 = F_3 ( F_77 ( V_131 ) ) ;
V_127 = V_125 . V_5 . V_143 << 16 ;
V_128 = ( V_125 . V_5 . V_144 + 1 ) << 16 ;
if ( V_125 . V_5 . V_27 && V_126 >= V_127
&& V_126 < V_127 + V_128 ) {
V_133 = V_125 . V_5 . V_145 ;
break;
}
}
if ( V_131 >= 7 ) {
goto V_142;
}
if ( ! ( V_126 & 0xfffful ) ) {
V_125 . V_4 =
F_3 ( F_77 ( V_131 + 1 ) ) ;
V_129 = V_125 . V_5 . V_143 << 16 ;
V_130 = ( V_125 . V_5 . V_144 + 1 ) << 16 ;
if ( ! V_125 . V_5 . V_27 )
goto V_142;
V_134 = true ;
} else {
F_51 ( V_83 , V_138 , L_38 ) ;
F_51 ( V_83 , V_138 , L_39 ) ;
if ( ! V_133 ) {
T_3 V_145 = F_76 ( 8 ) ;
F_55 ( V_83 , V_138 ,
L_40 , & V_145 , sizeof( V_145 ) ) ;
}
}
V_135 [ 0 ] = F_76 ( V_131 ) ;
V_135 [ 1 ] = F_76 ( 0 ) ;
V_135 [ 2 ] = F_76 ( 0x10000 ) ;
V_135 [ 3 ] = F_76 ( V_131 + 1 ) ;
V_135 [ 4 ] = F_76 ( 0 ) ;
V_135 [ 5 ] = F_76 ( 0x10000 ) ;
F_55 ( V_83 , V_138 ,
L_15 , V_135 , sizeof( V_135 ) ) ;
V_132 = F_78 ( V_83 , V_138 ) ;
if ( V_132 < 0 )
goto V_142;
V_136 = F_79 ( V_83 , V_132 , L_41 , & V_137 ) ;
if ( ! V_136 || V_137 < ( 5 * 8 * sizeof( T_3 ) ) )
goto V_142;
V_136 [ ( V_131 * 5 ) + 2 ] = F_76 ( V_127 >> 32 ) ;
V_136 [ ( V_131 * 5 ) + 3 ] = F_76 ( V_127 & 0xffffffff ) ;
V_136 [ ( V_131 * 5 ) + 4 ] = F_76 ( V_128 ) ;
if ( V_134 ) {
V_131 ++ ;
V_136 [ ( V_131 * 5 ) + 2 ] = F_76 ( V_129 >> 32 ) ;
V_136 [ ( V_131 * 5 ) + 3 ] = F_76 ( V_129 & 0xffffffff ) ;
V_136 [ ( V_131 * 5 ) + 4 ] = F_76 ( V_130 ) ;
}
goto V_146;
V_142:
F_52 ( V_83 , V_138 ) ;
V_146:
;
}
V_107 = F_48 ( V_83 , V_109 ,
L_42 , NULL ) ;
if ( V_107 ) {
union V_124 V_125 ;
unsigned long V_126 , V_127 , V_128 ;
int V_131 , V_132 ;
T_3 V_135 [ 6 ] ;
T_3 * V_136 ;
int V_137 ;
int V_147 = F_70 ( V_83 , V_107 ) ;
V_126 = V_110 -> V_148 ;
if ( V_126 == 0 )
goto V_149;
for ( V_131 = 0 ; V_131 < 8 ; V_131 ++ ) {
V_125 . V_4 = F_3 ( F_77 ( V_131 ) ) ;
V_127 = V_125 . V_5 . V_143 << 16 ;
V_128 = ( V_125 . V_5 . V_144 + 1 ) << 16 ;
if ( V_125 . V_5 . V_27 && V_126 >= V_127
&& V_126 < V_127 + V_128 )
break;
}
if ( V_131 > 7 )
goto V_149;
V_135 [ 0 ] = F_76 ( V_131 ) ;
V_135 [ 1 ] = F_76 ( 0x20 ) ;
V_135 [ 2 ] = F_76 ( 0x20 ) ;
V_135 [ 3 ] = F_76 ( V_131 ) ;
V_135 [ 4 ] = F_76 ( 0 ) ;
V_135 [ 5 ] = F_76 ( 0x20 ) ;
F_55 ( V_83 , V_147 ,
L_15 , V_135 , sizeof( V_135 ) ) ;
V_132 = F_78 ( V_83 , V_147 ) ;
if ( V_132 < 0 )
goto V_149;
V_136 = F_79 ( V_83 , V_132 , L_41 , & V_137 ) ;
if ( ! V_136 || V_137 < ( 5 * 8 * sizeof( T_3 ) ) )
goto V_149;
V_136 [ ( V_131 * 5 ) + 2 ] = F_76 ( V_127 >> 32 ) ;
V_136 [ ( V_131 * 5 ) + 3 ] = F_76 ( V_127 & 0xffffffff ) ;
V_136 [ ( V_131 * 5 ) + 4 ] = F_76 ( V_128 ) ;
goto V_150;
V_149:
F_52 ( V_83 , V_147 ) ;
V_150:
;
}
#ifdef F_80
V_107 = F_48 ( V_83 , V_109 ,
L_43 , NULL ) ;
if ( V_107 ) {
int V_151 = F_70 ( V_83 , V_107 ) ;
if ( V_151 >= 0 && ( ! F_46 ( V_70 ) ||
V_110 -> V_115 == V_152 ) ) {
F_64 ( L_44 ) ;
F_52 ( V_83 , V_151 ) ;
F_51 ( V_83 , V_109 , L_43 ) ;
} else if ( V_110 -> V_115 == V_119 ||
V_110 -> V_115 == V_153 ) {
F_51 ( V_83 , V_151 , L_4 ) ;
}
}
V_107 = F_48 ( V_83 , V_109 ,
L_45 , NULL ) ;
if ( V_107 ) {
int V_154 = F_70 ( V_83 , V_107 ) ;
if ( V_154 >= 0 && ( F_81 () == V_155 ||
! F_82 ( V_156 ) ) ) {
F_64 ( L_46 ) ;
F_52 ( V_83 , V_154 ) ;
F_51 ( V_83 , V_109 , L_45 ) ;
} else {
T_3 V_157 [ 1 ] ;
enum V_158 V_159 ;
V_159 = F_83 () ;
switch ( V_159 ) {
case V_160 :
V_157 [ 0 ] = F_76 ( 48000000 ) ;
F_55 ( V_83 , V_154 ,
L_2 , V_157 , sizeof( V_157 ) ) ;
case V_161 :
F_51 ( V_83 , V_154 , L_4 ) ;
break;
default:
break;
}
}
}
#endif
return 0 ;
}
static int T_1 F_84 ( void )
{
return F_85 ( NULL , V_162 , NULL ) ;
}
