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
static void F_9 ( struct V_14 * V_15 )
{
T_2 div ;
union V_16 V_17 ;
union V_18 V_19 ;
union V_20 V_21 ;
union V_22 V_23 ;
int V_24 ;
unsigned long V_25 ;
T_3 V_26 = 12000000 ;
bool V_27 = false ;
F_10 ( & V_28 ) ;
V_29 ++ ;
if ( V_29 != 1 )
goto exit;
V_25 = 64000000000ull / F_11 () ;
if ( V_15 -> V_30 ) {
struct V_31 * V_32 ;
const char * V_33 ;
V_32 = F_12 ( V_15 -> V_30 ) ;
if ( ! V_32 ) {
F_13 ( V_15 , L_2 ) ;
goto exit;
}
V_24 = F_14 ( V_32 ,
L_3 , & V_26 ) ;
if ( V_24 ) {
F_13 ( V_15 , L_4 ) ;
goto exit;
}
V_24 = F_15 ( V_32 ,
L_5 , & V_33 ) ;
if ( ! V_24 && strcmp ( L_6 , V_33 ) == 0 )
V_27 = true ;
}
V_17 . T_2 = 0 ;
V_17 . V_34 . V_35 = 1 ;
F_16 ( F_17 ( 0 ) , V_17 . T_2 ) ;
V_19 . T_2 = F_18 ( F_19 ( 0 ) ) ;
if ( V_19 . V_34 . V_36 )
goto V_37;
V_19 . V_34 . V_38 = 1 ;
V_19 . V_34 . V_36 = 0 ;
V_19 . V_34 . V_39 = 0 ;
V_19 . V_34 . V_40 = 0 ;
V_19 . V_34 . V_41 = 0 ;
V_19 . V_34 . V_42 = 0 ;
V_19 . V_34 . V_43 = 0 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
V_19 . V_34 . V_44 = V_27 ? 0 : 1 ;
switch ( V_26 ) {
default:
F_20 ( L_7 ,
V_26 ) ;
case 12000000 :
V_19 . V_34 . V_45 = 0 ;
break;
case 24000000 :
V_19 . V_34 . V_45 = 1 ;
break;
case 48000000 :
V_19 . V_34 . V_45 = 2 ;
break;
}
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
div = F_11 () / 130000000ull ;
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
V_19 . V_34 . V_46 = div ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
V_19 . T_2 = F_18 ( F_19 ( 0 ) ) ;
V_19 . V_34 . V_42 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
V_19 . V_34 . V_40 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
F_21 ( V_25 ) ;
V_19 . V_34 . V_38 = 0 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
F_22 ( 1 ) ;
V_21 . T_2 = F_18 ( F_23 ( 0 ) ) ;
V_21 . V_34 . V_47 = 1 ;
F_16 ( F_23 ( 0 ) , V_21 . T_2 ) ;
F_21 ( 10 ) ;
V_21 . V_34 . V_47 = 0 ;
F_16 ( F_23 ( 0 ) , V_21 . T_2 ) ;
F_21 ( 20 ) ;
V_19 . V_34 . V_41 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
V_19 . V_34 . V_43 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
F_21 ( V_25 ) ;
V_19 . V_34 . V_39 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
F_24 ( 1 ) ;
V_19 . V_34 . V_36 = 1 ;
F_16 ( F_19 ( 0 ) , V_19 . T_2 ) ;
V_37:
for ( V_24 = 0 ; V_24 <= 1 ; V_24 ++ ) {
V_23 . T_2 =
F_18 ( F_25 ( V_24 , 0 ) ) ;
V_23 . V_34 . V_48 = 15 ;
V_23 . V_34 . V_49 = 1 ;
V_23 . V_34 . V_50 = 1 ;
F_16 ( F_25 ( V_24 , 0 ) ,
V_23 . T_2 ) ;
}
F_16 ( F_26 ( 0 ) , 0x20ull ) ;
exit:
F_27 ( & V_28 ) ;
}
static void F_28 ( void )
{
F_10 ( & V_28 ) ;
V_29 -- ;
F_27 ( & V_28 ) ;
}
static int F_29 ( struct V_1 * V_51 )
{
F_9 ( & V_51 -> V_15 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_51 )
{
F_28 () ;
}
static void T_1 F_31 ( struct V_14 * V_15 )
{
union V_52 V_53 ;
F_9 ( V_15 ) ;
V_53 . T_2 = F_18 ( F_32 ( 0 ) ) ;
V_53 . V_34 . V_54 = 1 ;
V_53 . V_34 . V_55 = 0 ;
#ifdef F_33
V_53 . V_34 . V_56 = 1 ;
V_53 . V_34 . V_57 = 1 ;
#else
V_53 . V_34 . V_56 = 0 ;
V_53 . V_34 . V_57 = 0 ;
V_53 . V_34 . V_58 = 1 ;
#endif
F_16 ( F_32 ( 0 ) , V_53 . T_2 ) ;
F_28 () ;
}
static int T_1 F_34 ( void )
{
struct V_1 * V_2 ;
struct V_31 * V_59 ;
int V_3 = 0 ;
V_59 = F_35 ( NULL , L_8 ) ;
if ( ! V_59 )
return 0 ;
V_2 = F_36 ( V_59 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_15 . V_60 = & V_61 ;
F_31 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static int F_37 ( struct V_1 * V_51 )
{
F_9 ( & V_51 -> V_15 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_51 )
{
F_28 () ;
}
static void T_1 F_39 ( struct V_14 * V_15 )
{
union V_62 V_63 ;
F_9 ( V_15 ) ;
V_63 . T_2 = F_18 ( F_40 ( 0 ) ) ;
V_63 . V_34 . V_55 = 0 ;
#ifdef F_33
V_63 . V_34 . V_56 = 1 ;
V_63 . V_34 . V_57 = 1 ;
#else
V_63 . V_34 . V_56 = 0 ;
V_63 . V_34 . V_57 = 0 ;
V_63 . V_34 . V_58 = 1 ;
#endif
F_16 ( F_40 ( 0 ) , V_63 . T_2 ) ;
F_28 () ;
}
static int T_1 F_41 ( void )
{
struct V_1 * V_2 ;
struct V_31 * V_64 ;
int V_3 = 0 ;
V_64 = F_35 ( NULL , L_9 ) ;
if ( ! V_64 )
return 0 ;
V_2 = F_36 ( V_64 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_15 . V_60 = & V_65 ;
F_39 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static bool T_1 F_42 ( void )
{
return ! F_43 ( V_66 ) &&
! F_43 ( V_67 ) &&
! F_43 ( V_68 ) ;
}
static void T_1 F_44 ( int V_69 , int V_70 )
{
const T_4 * V_71 ;
const T_4 * V_72 ;
const T_4 * V_73 ;
T_3 V_74 ;
int V_75 ;
int V_76 ;
const char * V_77 ;
int V_78 ;
char V_79 [ 20 ] ;
V_71 = F_45 ( V_80 , V_69 , L_10 , NULL ) ;
if ( ! V_71 )
return;
V_74 = F_46 ( V_71 ) ;
V_75 = F_47 ( V_80 , V_74 ) ;
V_72 = F_45 ( V_80 , V_69 , L_11 , NULL ) ;
if ( V_72 ) {
T_3 V_81 = F_46 ( V_72 ) ;
V_76 = F_47 ( V_80 , V_81 ) ;
} else {
V_76 = - 1 ;
}
if ( V_70 < 0 || V_75 < 0 ) {
F_48 ( V_80 , V_69 , L_10 ) ;
F_48 ( V_80 , V_69 , L_11 ) ;
if ( V_75 >= 0 )
F_49 ( V_80 , V_75 ) ;
if ( V_76 >= 0 )
F_49 ( V_80 , V_76 ) ;
return;
}
if ( V_70 >= 256 && V_76 > 0 ) {
const struct V_82 * V_83 ;
struct V_82 * V_84 ;
T_3 V_85 ;
V_83 = F_50 ( V_80 , V_69 , L_10 , NULL ) ;
V_85 = V_83 -> V_86 ;
F_49 ( V_80 , V_75 ) ;
F_48 ( V_80 , V_69 , L_10 ) ;
V_84 = F_51 ( V_80 , V_69 , L_11 , NULL ) ;
V_84 -> V_86 = V_85 ;
V_75 = V_76 ;
}
V_70 &= 0xff ;
if ( F_42 () ) {
F_48 ( V_80 , V_75 , L_12 ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
strcpy ( V_79 , L_13 ) ;
V_77 = F_45 ( V_80 , V_75 , L_14 ,
& V_78 ) ;
if ( V_77 && V_78 >= strlen ( V_79 ) )
F_52 ( V_80 , V_75 ,
L_14 , V_79 , V_78 ) ;
}
V_73 = F_45 ( V_80 , V_75 , L_15 , NULL ) ;
if ( V_70 == F_46 ( V_73 ) )
return;
F_53 ( V_80 , V_75 , L_15 , V_70 ) ;
snprintf ( V_79 , sizeof( V_79 ) , L_16 , V_70 ) ;
V_77 = F_54 ( V_80 , V_75 , & V_78 ) ;
if ( V_77 && V_78 == strlen ( V_79 ) )
F_55 ( V_80 , V_75 , V_79 ) ;
else
F_20 ( L_17 , V_77 ) ;
}
static void T_1 F_56 ( int V_87 , T_2 * V_88 )
{
const T_5 * V_89 ;
int V_90 ;
T_5 V_91 [ 6 ] ;
T_2 V_92 = * V_88 ;
int V_93 ;
V_89 = F_45 ( V_80 , V_87 , L_18 ,
& V_90 ) ;
if ( ! V_89 || V_90 != 6 || F_57 ( V_89 ) )
return;
V_91 [ 0 ] = ( V_92 >> 40 ) & 0xff ;
V_91 [ 1 ] = ( V_92 >> 32 ) & 0xff ;
V_91 [ 2 ] = ( V_92 >> 24 ) & 0xff ;
V_91 [ 3 ] = ( V_92 >> 16 ) & 0xff ;
V_91 [ 4 ] = ( V_92 >> 8 ) & 0xff ;
V_91 [ 5 ] = V_92 & 0xff ;
V_93 = F_52 ( V_80 , V_87 , L_18 ,
V_91 , sizeof( V_91 ) ) ;
if ( V_93 ) {
F_20 ( L_19 , V_93 ) ;
return;
}
* V_88 = V_92 + 1 ;
}
static void T_1 F_58 ( int V_94 )
{
const T_4 * V_71 ;
V_71 = F_45 ( V_80 , V_94 , L_10 , NULL ) ;
if ( V_71 ) {
T_3 V_95 = F_46 ( V_71 ) ;
int V_77 = F_47 ( V_80 , V_95 ) ;
if ( V_77 >= 0 )
F_49 ( V_80 , V_77 ) ;
}
F_49 ( V_80 , V_94 ) ;
}
static void T_1 F_59 ( int V_96 , int V_24 , int V_77 , int V_97 )
{
char V_98 [ 20 ] ;
int V_69 ;
int V_70 ;
int V_99 ;
snprintf ( V_98 , sizeof( V_98 ) , L_20 , V_77 ) ;
V_69 = F_60 ( V_80 , V_96 , V_98 ) ;
if ( V_69 < 0 )
return;
if ( V_77 > V_97 ) {
F_61 ( L_21 , V_24 , V_77 ) ;
F_58 ( V_69 ) ;
return;
}
if ( F_43 ( V_100 ) )
V_99 = ( 0x100 * V_24 ) + ( 0x10 * V_77 ) + 0x800 ;
else
V_99 = 16 * V_24 + V_77 ;
V_70 = F_62 ( V_99 ) ;
F_44 ( V_69 , V_70 ) ;
}
static void T_1 F_63 ( int V_101 , int V_102 )
{
char V_98 [ 20 ] ;
int V_96 ;
int V_77 ;
int V_103 = 0 ;
snprintf ( V_98 , sizeof( V_98 ) , L_22 , V_102 ) ;
V_96 = F_60 ( V_80 , V_101 , V_98 ) ;
if ( V_96 < 0 )
return;
if ( F_64 ( V_102 ) == 0 )
V_103 = F_65 ( V_102 ) ;
for ( V_77 = 0 ; V_77 < 16 ; V_77 ++ )
F_59 ( V_96 , V_102 , V_77 , V_103 - 1 ) ;
}
void T_1 F_66 ( void )
{
const char * V_104 ;
char V_98 [ 20 ] ;
T_2 V_105 ;
int V_106 ;
int V_101 ;
int V_24 ;
V_106 = F_67 ( V_80 , L_23 ) ;
if ( V_106 < 0 )
return;
V_105 =
( ( V_107 -> V_105 [ 0 ] & 0xffull ) ) << 40 |
( ( V_107 -> V_105 [ 1 ] & 0xffull ) ) << 32 |
( ( V_107 -> V_105 [ 2 ] & 0xffull ) ) << 24 |
( ( V_107 -> V_105 [ 3 ] & 0xffull ) ) << 16 |
( ( V_107 -> V_105 [ 4 ] & 0xffull ) ) << 8 |
( V_107 -> V_105 [ 5 ] & 0xffull ) ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_108 ;
snprintf ( V_98 , sizeof( V_98 ) , L_24 , V_24 ) ;
V_104 = F_45 ( V_80 , V_106 ,
V_98 , NULL ) ;
if ( ! V_104 )
continue;
V_108 = F_67 ( V_80 , V_104 ) ;
if ( V_108 < 0 )
continue;
F_56 ( V_108 , & V_105 ) ;
}
V_104 = F_45 ( V_80 , V_106 , L_25 , NULL ) ;
if ( ! V_104 )
return;
V_101 = F_67 ( V_80 , V_104 ) ;
if ( V_101 < 0 )
return;
for ( V_24 = 0 ; V_24 <= 4 ; V_24 ++ ) {
int V_96 ;
int V_77 ;
snprintf ( V_98 , sizeof( V_98 ) , L_22 , V_24 ) ;
V_96 = F_60 ( V_80 , V_101 ,
V_98 ) ;
if ( V_96 < 0 )
continue;
for ( V_77 = 0 ; V_77 < 16 ; V_77 ++ ) {
int V_69 ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_20 , V_77 ) ;
V_69 = F_60 ( V_80 , V_96 ,
V_98 ) ;
if ( V_69 < 0 )
continue;
F_56 ( V_69 , & V_105 ) ;
}
}
}
int T_1 F_68 ( void )
{
int V_24 , V_109 , V_110 ;
const char * V_111 ;
const char * V_104 ;
char V_98 [ 20 ] ;
int V_106 ;
if ( F_69 ( V_80 ) )
F_70 ( L_26 ) ;
V_106 = F_67 ( V_80 , L_23 ) ;
if ( V_106 < 0 ) {
F_20 ( L_27 ) ;
return - V_112 ;
}
if ( F_43 ( V_66 ) || F_43 ( V_113 ) )
V_109 = 2 ;
else if ( F_43 ( V_68 ) || F_43 ( V_100 ) )
V_109 = 1 ;
else
V_109 = 0 ;
if ( V_107 -> V_114 == V_115 )
V_109 = 0 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_108 ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_24 , V_24 ) ;
V_104 = F_45 ( V_80 , V_106 ,
V_98 , NULL ) ;
if ( V_104 ) {
V_108 = F_67 ( V_80 , V_104 ) ;
if ( V_108 < 0 )
continue;
if ( V_24 >= V_109 ) {
F_61 ( L_28 , V_24 ) ;
F_58 ( V_108 ) ;
F_48 ( V_80 , V_106 ,
V_98 ) ;
} else {
int V_70 = F_62 ( V_116 + V_24 ) ;
F_44 ( V_108 , V_70 ) ;
}
}
}
V_111 = F_45 ( V_80 , V_106 , L_25 , NULL ) ;
if ( V_111 ) {
int V_101 = F_67 ( V_80 , V_111 ) ;
if ( V_101 >= 0 )
for ( V_24 = 0 ; V_24 <= 4 ; V_24 ++ )
F_63 ( V_101 , V_24 ) ;
}
if ( F_43 ( V_66 ) ||
F_43 ( V_113 ) ||
F_43 ( V_100 ) ||
F_43 ( V_68 ) )
V_109 = 2 ;
else
V_109 = 1 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_117 ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_29 , V_24 ) ;
V_104 = F_45 ( V_80 , V_106 ,
V_98 , NULL ) ;
if ( V_104 ) {
V_117 = F_67 ( V_80 , V_104 ) ;
if ( V_117 < 0 )
continue;
if ( V_24 >= V_109 ) {
F_61 ( L_30 , V_24 ) ;
F_49 ( V_80 , V_117 ) ;
F_48 ( V_80 , V_106 ,
V_98 ) ;
}
}
}
if ( F_43 ( V_100 ) )
V_109 = 4 ;
else if ( F_43 ( V_66 ) ||
F_43 ( V_113 ) ||
F_43 ( V_68 ) )
V_109 = 2 ;
else
V_109 = 1 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_117 ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_31 , V_24 ) ;
V_104 = F_45 ( V_80 , V_106 ,
V_98 , NULL ) ;
if ( V_104 ) {
V_117 = F_67 ( V_80 , V_104 ) ;
if ( V_117 < 0 )
continue;
if ( V_24 >= V_109 ) {
F_61 ( L_32 , V_24 ) ;
F_49 ( V_80 , V_117 ) ;
F_48 ( V_80 , V_106 ,
V_98 ) ;
}
}
}
V_110 = 3 ;
if ( F_43 ( V_66 ) )
V_110 |= 4 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ ) {
int V_118 ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_33 , V_24 ) ;
V_104 = F_45 ( V_80 , V_106 ,
V_98 , NULL ) ;
if ( V_104 ) {
V_118 = F_67 ( V_80 , V_104 ) ;
if ( V_110 & ( 1 << V_24 ) ) {
T_4 V_119 ;
V_119 = F_71 ( F_11 () ) ;
F_52 ( V_80 ,
V_118 , L_34 ,
& V_119 , sizeof( V_119 ) ) ;
continue;
}
F_61 ( L_35 , V_24 ) ;
F_49 ( V_80 , V_118 ) ;
F_48 ( V_80 , V_106 ,
V_98 ) ;
}
}
V_104 = F_45 ( V_80 , V_106 ,
L_36 , NULL ) ;
if ( V_104 ) {
union V_120 V_121 ;
unsigned long V_122 , V_123 , V_124 ;
unsigned long V_125 = 0 ;
unsigned long V_126 = 0 ;
int V_127 , V_128 ;
bool V_129 = false ;
bool V_130 = false ;
T_4 V_131 [ 6 ] ;
T_4 * V_132 ;
int V_133 ;
int V_134 = F_67 ( V_80 , V_104 ) ;
V_122 = 0 ;
if ( V_107 -> V_135 == 1
&& V_107 -> V_136 >= 1 ) {
if ( V_107 -> V_137 )
V_122 = V_107 -> V_137 ;
} else {
V_122 = 0x1d000800 ;
}
if ( ! V_122 )
goto V_138;
for ( V_127 = 0 ; V_127 < 8 ; V_127 ++ ) {
V_121 . T_2 = F_18 ( F_72 ( V_127 ) ) ;
V_123 = V_121 . V_34 . V_139 << 16 ;
V_124 = ( V_121 . V_34 . V_140 + 1 ) << 16 ;
if ( V_121 . V_34 . V_35 && V_122 >= V_123
&& V_122 < V_123 + V_124 ) {
V_129 = V_121 . V_34 . V_141 ;
break;
}
}
if ( V_127 >= 7 ) {
goto V_138;
}
if ( ! ( V_122 & 0xfffful ) ) {
V_121 . T_2 =
F_18 ( F_72 ( V_127 + 1 ) ) ;
V_125 = V_121 . V_34 . V_139 << 16 ;
V_126 = ( V_121 . V_34 . V_140 + 1 ) << 16 ;
if ( ! V_121 . V_34 . V_35 )
goto V_138;
V_130 = true ;
} else {
F_48 ( V_80 , V_134 , L_37 ) ;
F_48 ( V_80 , V_134 , L_38 ) ;
if ( ! V_129 ) {
T_4 V_141 = F_71 ( 8 ) ;
F_52 ( V_80 , V_134 ,
L_39 , & V_141 , sizeof( V_141 ) ) ;
}
}
V_131 [ 0 ] = F_71 ( V_127 ) ;
V_131 [ 1 ] = F_71 ( 0 ) ;
V_131 [ 2 ] = F_71 ( 0x10000 ) ;
V_131 [ 3 ] = F_71 ( V_127 + 1 ) ;
V_131 [ 4 ] = F_71 ( 0 ) ;
V_131 [ 5 ] = F_71 ( 0x10000 ) ;
F_52 ( V_80 , V_134 ,
L_15 , V_131 , sizeof( V_131 ) ) ;
V_128 = F_73 ( V_80 , V_134 ) ;
if ( V_128 < 0 )
goto V_138;
V_132 = F_74 ( V_80 , V_128 , L_40 , & V_133 ) ;
if ( ! V_132 || V_133 < ( 5 * 8 * sizeof( T_4 ) ) )
goto V_138;
V_132 [ ( V_127 * 5 ) + 2 ] = F_71 ( V_123 >> 32 ) ;
V_132 [ ( V_127 * 5 ) + 3 ] = F_71 ( V_123 & 0xffffffff ) ;
V_132 [ ( V_127 * 5 ) + 4 ] = F_71 ( V_124 ) ;
if ( V_130 ) {
V_127 ++ ;
V_132 [ ( V_127 * 5 ) + 2 ] = F_71 ( V_125 >> 32 ) ;
V_132 [ ( V_127 * 5 ) + 3 ] = F_71 ( V_125 & 0xffffffff ) ;
V_132 [ ( V_127 * 5 ) + 4 ] = F_71 ( V_126 ) ;
}
goto V_142;
V_138:
F_49 ( V_80 , V_134 ) ;
V_142:
;
}
V_104 = F_45 ( V_80 , V_106 ,
L_41 , NULL ) ;
if ( V_104 ) {
union V_120 V_121 ;
unsigned long V_122 , V_123 , V_124 ;
int V_127 , V_128 ;
T_4 V_131 [ 6 ] ;
T_4 * V_132 ;
int V_133 ;
int V_143 = F_67 ( V_80 , V_104 ) ;
V_122 = V_107 -> V_144 ;
if ( V_122 == 0 )
goto V_145;
for ( V_127 = 0 ; V_127 < 8 ; V_127 ++ ) {
V_121 . T_2 = F_18 ( F_72 ( V_127 ) ) ;
V_123 = V_121 . V_34 . V_139 << 16 ;
V_124 = ( V_121 . V_34 . V_140 + 1 ) << 16 ;
if ( V_121 . V_34 . V_35 && V_122 >= V_123
&& V_122 < V_123 + V_124 )
break;
}
if ( V_127 > 7 )
goto V_145;
V_131 [ 0 ] = F_71 ( V_127 ) ;
V_131 [ 1 ] = F_71 ( 0x20 ) ;
V_131 [ 2 ] = F_71 ( 0x20 ) ;
V_131 [ 3 ] = F_71 ( V_127 ) ;
V_131 [ 4 ] = F_71 ( 0 ) ;
V_131 [ 5 ] = F_71 ( 0x20 ) ;
F_52 ( V_80 , V_143 ,
L_15 , V_131 , sizeof( V_131 ) ) ;
V_128 = F_73 ( V_80 , V_143 ) ;
if ( V_128 < 0 )
goto V_145;
V_132 = F_74 ( V_80 , V_128 , L_40 , & V_133 ) ;
if ( ! V_132 || V_133 < ( 5 * 8 * sizeof( T_4 ) ) )
goto V_145;
V_132 [ ( V_127 * 5 ) + 2 ] = F_71 ( V_123 >> 32 ) ;
V_132 [ ( V_127 * 5 ) + 3 ] = F_71 ( V_123 & 0xffffffff ) ;
V_132 [ ( V_127 * 5 ) + 4 ] = F_71 ( V_124 ) ;
goto V_146;
V_145:
F_49 ( V_80 , V_143 ) ;
V_146:
;
}
V_104 = F_45 ( V_80 , V_106 ,
L_42 , NULL ) ;
if ( V_104 ) {
int V_147 = F_67 ( V_80 , V_104 ) ;
if ( V_147 >= 0 && ( ! F_43 ( V_67 ) ||
V_107 -> V_114 == V_148 ) ) {
F_61 ( L_43 ) ;
F_49 ( V_80 , V_147 ) ;
F_48 ( V_80 , V_106 , L_42 ) ;
} else if ( V_107 -> V_114 == V_115 ||
V_107 -> V_114 == V_149 ) {
F_48 ( V_80 , V_147 , L_5 ) ;
}
}
V_104 = F_45 ( V_80 , V_106 ,
L_44 , NULL ) ;
if ( V_104 ) {
int V_150 = F_67 ( V_80 , V_104 ) ;
if ( V_150 >= 0 && ( F_75 () == V_151 ||
! F_76 ( V_152 ) ) ) {
F_61 ( L_45 ) ;
F_49 ( V_80 , V_150 ) ;
F_48 ( V_80 , V_106 , L_44 ) ;
} else {
T_4 V_153 [ 1 ] ;
enum V_154 V_155 ;
V_155 = F_77 () ;
switch ( V_155 ) {
case V_156 :
V_153 [ 0 ] = F_71 ( 48000000 ) ;
F_52 ( V_80 , V_150 ,
L_3 , V_153 , sizeof( V_153 ) ) ;
case V_157 :
F_48 ( V_80 , V_150 , L_5 ) ;
break;
default:
break;
}
}
}
if ( V_107 -> V_114 != V_158 ) {
int V_159 = F_67 ( V_80 ,
L_46 ) ;
if ( V_159 >= 0 )
F_49 ( V_80 , V_159 ) ;
}
return 0 ;
}
static int T_1 F_78 ( void )
{
return F_79 ( NULL , V_160 , NULL ) ;
}
