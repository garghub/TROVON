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
V_53 . V_34 . V_56 = 1 ;
V_53 . V_34 . V_57 = 1 ;
F_16 ( F_32 ( 0 ) , V_53 . T_2 ) ;
F_28 () ;
}
static int T_1 F_33 ( void )
{
struct V_1 * V_2 ;
struct V_31 * V_58 ;
int V_3 = 0 ;
V_58 = F_34 ( NULL , L_8 ) ;
if ( ! V_58 )
return 0 ;
V_2 = F_35 ( V_58 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_15 . V_59 = & V_60 ;
F_31 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static int F_36 ( struct V_1 * V_51 )
{
F_9 ( & V_51 -> V_15 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_51 )
{
F_28 () ;
}
static void T_1 F_38 ( struct V_14 * V_15 )
{
union V_61 V_62 ;
F_9 ( V_15 ) ;
V_62 . T_2 = F_18 ( F_39 ( 0 ) ) ;
V_62 . V_34 . V_55 = 0 ;
V_62 . V_34 . V_56 = 1 ;
V_62 . V_34 . V_57 = 1 ;
F_16 ( F_39 ( 0 ) , V_62 . T_2 ) ;
F_28 () ;
}
static int T_1 F_40 ( void )
{
struct V_1 * V_2 ;
struct V_31 * V_63 ;
int V_3 = 0 ;
V_63 = F_34 ( NULL , L_9 ) ;
if ( ! V_63 )
return 0 ;
V_2 = F_35 ( V_63 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_15 . V_59 = & V_64 ;
F_38 ( & V_2 -> V_15 ) ;
return V_3 ;
}
static bool T_1 F_41 ( void )
{
return ! F_42 ( V_65 ) &&
! F_42 ( V_66 ) &&
! F_42 ( V_67 ) ;
}
static void T_1 F_43 ( int V_68 , int V_69 )
{
const T_4 * V_70 ;
const T_4 * V_71 ;
const T_4 * V_72 ;
T_3 V_73 ;
int V_74 ;
int V_75 ;
const char * V_76 ;
int V_77 ;
char V_78 [ 20 ] ;
V_70 = F_44 ( V_79 , V_68 , L_10 , NULL ) ;
if ( ! V_70 )
return;
V_73 = F_45 ( V_70 ) ;
V_74 = F_46 ( V_79 , V_73 ) ;
V_71 = F_44 ( V_79 , V_68 , L_11 , NULL ) ;
if ( V_71 ) {
T_3 V_80 = F_45 ( V_71 ) ;
V_75 = F_46 ( V_79 , V_80 ) ;
} else {
V_75 = - 1 ;
}
if ( V_69 < 0 || V_74 < 0 ) {
F_47 ( V_79 , V_68 , L_10 ) ;
F_47 ( V_79 , V_68 , L_11 ) ;
if ( V_74 >= 0 )
F_48 ( V_79 , V_74 ) ;
if ( V_75 >= 0 )
F_48 ( V_79 , V_75 ) ;
return;
}
if ( V_69 >= 256 && V_75 > 0 ) {
const struct V_81 * V_82 ;
struct V_81 * V_83 ;
T_3 V_84 ;
V_82 = F_49 ( V_79 , V_68 , L_10 , NULL ) ;
V_84 = V_82 -> V_85 ;
F_48 ( V_79 , V_74 ) ;
F_47 ( V_79 , V_68 , L_10 ) ;
V_83 = F_50 ( V_79 , V_68 , L_11 , NULL ) ;
V_83 -> V_85 = V_84 ;
V_74 = V_75 ;
}
V_69 &= 0xff ;
if ( F_41 () ) {
F_47 ( V_79 , V_74 , L_12 ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
strcpy ( V_78 , L_13 ) ;
V_76 = F_44 ( V_79 , V_74 , L_14 ,
& V_77 ) ;
if ( V_76 && V_77 >= strlen ( V_78 ) )
F_51 ( V_79 , V_74 ,
L_14 , V_78 , V_77 ) ;
}
V_72 = F_44 ( V_79 , V_74 , L_15 , NULL ) ;
if ( V_69 == F_45 ( V_72 ) )
return;
F_52 ( V_79 , V_74 , L_15 , V_69 ) ;
snprintf ( V_78 , sizeof( V_78 ) , L_16 , V_69 ) ;
V_76 = F_53 ( V_79 , V_74 , & V_77 ) ;
if ( V_76 && V_77 == strlen ( V_78 ) )
F_54 ( V_79 , V_74 , V_78 ) ;
else
F_20 ( L_17 , V_76 ) ;
}
static void T_1 F_55 ( int V_86 , T_2 * V_87 )
{
T_5 V_88 [ 6 ] ;
T_2 V_89 = * V_87 ;
int V_90 ;
V_88 [ 0 ] = ( V_89 >> 40 ) & 0xff ;
V_88 [ 1 ] = ( V_89 >> 32 ) & 0xff ;
V_88 [ 2 ] = ( V_89 >> 24 ) & 0xff ;
V_88 [ 3 ] = ( V_89 >> 16 ) & 0xff ;
V_88 [ 4 ] = ( V_89 >> 8 ) & 0xff ;
V_88 [ 5 ] = V_89 & 0xff ;
V_90 = F_51 ( V_79 , V_86 , L_18 ,
V_88 , sizeof( V_88 ) ) ;
if ( V_90 ) {
F_20 ( L_19 , V_90 ) ;
return;
}
* V_87 = V_89 + 1 ;
}
static void T_1 F_56 ( int V_91 )
{
const T_4 * V_70 ;
V_70 = F_44 ( V_79 , V_91 , L_10 , NULL ) ;
if ( V_70 ) {
T_3 V_92 = F_45 ( V_70 ) ;
int V_76 = F_46 ( V_79 , V_92 ) ;
if ( V_76 >= 0 )
F_48 ( V_79 , V_76 ) ;
}
F_48 ( V_79 , V_91 ) ;
}
static void T_1 F_57 ( int V_93 , int V_24 , int V_76 , int V_94 , T_2 * V_87 )
{
char V_95 [ 20 ] ;
int V_68 ;
int V_69 ;
int V_96 ;
snprintf ( V_95 , sizeof( V_95 ) , L_20 , V_76 ) ;
V_68 = F_58 ( V_79 , V_93 , V_95 ) ;
if ( V_68 < 0 )
return;
if ( V_76 > V_94 ) {
F_59 ( L_21 , V_24 , V_76 ) ;
F_56 ( V_68 ) ;
return;
}
if ( F_42 ( V_97 ) )
V_96 = ( 0x100 * V_24 ) + ( 0x10 * V_76 ) + 0x800 ;
else
V_96 = 16 * V_24 + V_76 ;
V_69 = F_60 ( V_96 ) ;
F_43 ( V_68 , V_69 ) ;
F_55 ( V_68 , V_87 ) ;
}
static void T_1 F_61 ( int V_98 , int V_99 , T_2 * V_87 )
{
char V_95 [ 20 ] ;
int V_93 ;
int V_76 ;
int V_100 = 0 ;
snprintf ( V_95 , sizeof( V_95 ) , L_22 , V_99 ) ;
V_93 = F_58 ( V_79 , V_98 , V_95 ) ;
if ( V_93 < 0 )
return;
if ( F_62 ( V_99 ) == 0 )
V_100 = F_63 ( V_99 ) ;
for ( V_76 = 0 ; V_76 < 16 ; V_76 ++ )
F_57 ( V_93 , V_99 , V_76 , V_100 - 1 , V_87 ) ;
}
int T_1 F_64 ( void )
{
int V_24 , V_101 , V_102 ;
const char * V_103 ;
const char * V_104 ;
char V_95 [ 20 ] ;
int V_105 ;
T_2 V_106 ;
if ( F_65 ( V_79 ) )
F_66 ( L_23 ) ;
V_105 = F_67 ( V_79 , L_24 ) ;
if ( V_105 < 0 ) {
F_20 ( L_25 ) ;
return - V_107 ;
}
V_106 =
( ( V_108 -> V_106 [ 0 ] & 0xffull ) ) << 40 |
( ( V_108 -> V_106 [ 1 ] & 0xffull ) ) << 32 |
( ( V_108 -> V_106 [ 2 ] & 0xffull ) ) << 24 |
( ( V_108 -> V_106 [ 3 ] & 0xffull ) ) << 16 |
( ( V_108 -> V_106 [ 4 ] & 0xffull ) ) << 8 |
( V_108 -> V_106 [ 5 ] & 0xffull ) ;
if ( F_42 ( V_65 ) || F_42 ( V_109 ) )
V_101 = 2 ;
else if ( F_42 ( V_67 ) || F_42 ( V_97 ) )
V_101 = 1 ;
else
V_101 = 0 ;
if ( V_108 -> V_110 == V_111 )
V_101 = 0 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_112 ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_26 , V_24 ) ;
V_104 = F_44 ( V_79 , V_105 ,
V_95 , NULL ) ;
if ( V_104 ) {
V_112 = F_67 ( V_79 , V_104 ) ;
if ( V_112 < 0 )
continue;
if ( V_24 >= V_101 ) {
F_59 ( L_27 , V_24 ) ;
F_56 ( V_112 ) ;
F_47 ( V_79 , V_105 ,
V_95 ) ;
} else {
int V_69 = F_60 ( V_113 + V_24 ) ;
F_43 ( V_112 , V_69 ) ;
F_55 ( V_112 , & V_106 ) ;
}
}
}
V_103 = F_44 ( V_79 , V_105 , L_28 , NULL ) ;
if ( V_103 ) {
int V_98 = F_67 ( V_79 , V_103 ) ;
if ( V_98 >= 0 )
for ( V_24 = 0 ; V_24 <= 4 ; V_24 ++ )
F_61 ( V_98 , V_24 , & V_106 ) ;
}
if ( F_42 ( V_65 ) ||
F_42 ( V_109 ) ||
F_42 ( V_97 ) ||
F_42 ( V_67 ) )
V_101 = 2 ;
else
V_101 = 1 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_114 ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_29 , V_24 ) ;
V_104 = F_44 ( V_79 , V_105 ,
V_95 , NULL ) ;
if ( V_104 ) {
V_114 = F_67 ( V_79 , V_104 ) ;
if ( V_114 < 0 )
continue;
if ( V_24 >= V_101 ) {
F_59 ( L_30 , V_24 ) ;
F_48 ( V_79 , V_114 ) ;
F_47 ( V_79 , V_105 ,
V_95 ) ;
}
}
}
if ( F_42 ( V_97 ) )
V_101 = 4 ;
else if ( F_42 ( V_65 ) ||
F_42 ( V_109 ) ||
F_42 ( V_67 ) )
V_101 = 2 ;
else
V_101 = 1 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ ) {
int V_114 ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_31 , V_24 ) ;
V_104 = F_44 ( V_79 , V_105 ,
V_95 , NULL ) ;
if ( V_104 ) {
V_114 = F_67 ( V_79 , V_104 ) ;
if ( V_114 < 0 )
continue;
if ( V_24 >= V_101 ) {
F_59 ( L_32 , V_24 ) ;
F_48 ( V_79 , V_114 ) ;
F_47 ( V_79 , V_105 ,
V_95 ) ;
}
}
}
V_102 = 3 ;
if ( F_42 ( V_65 ) )
V_102 |= 4 ;
for ( V_24 = 0 ; V_24 < 3 ; V_24 ++ ) {
int V_115 ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_33 , V_24 ) ;
V_104 = F_44 ( V_79 , V_105 ,
V_95 , NULL ) ;
if ( V_104 ) {
V_115 = F_67 ( V_79 , V_104 ) ;
if ( V_102 & ( 1 << V_24 ) ) {
T_4 V_116 ;
V_116 = F_68 ( F_11 () ) ;
F_51 ( V_79 ,
V_115 , L_34 ,
& V_116 , sizeof( V_116 ) ) ;
continue;
}
F_59 ( L_35 , V_24 ) ;
F_48 ( V_79 , V_115 ) ;
F_47 ( V_79 , V_105 ,
V_95 ) ;
}
}
V_104 = F_44 ( V_79 , V_105 ,
L_36 , NULL ) ;
if ( V_104 ) {
union V_117 V_118 ;
unsigned long V_119 , V_120 , V_121 ;
unsigned long V_122 = 0 ;
unsigned long V_123 = 0 ;
int V_124 , V_125 ;
bool V_126 = false ;
bool V_127 = false ;
T_4 V_128 [ 6 ] ;
T_4 * V_129 ;
int V_130 ;
int V_131 = F_67 ( V_79 , V_104 ) ;
V_119 = 0 ;
if ( V_108 -> V_132 == 1
&& V_108 -> V_133 >= 1 ) {
if ( V_108 -> V_134 )
V_119 = V_108 -> V_134 ;
} else {
V_119 = 0x1d000800 ;
}
if ( ! V_119 )
goto V_135;
for ( V_124 = 0 ; V_124 < 8 ; V_124 ++ ) {
V_118 . T_2 = F_18 ( F_69 ( V_124 ) ) ;
V_120 = V_118 . V_34 . V_136 << 16 ;
V_121 = ( V_118 . V_34 . V_137 + 1 ) << 16 ;
if ( V_118 . V_34 . V_35 && V_119 >= V_120
&& V_119 < V_120 + V_121 ) {
V_126 = V_118 . V_34 . V_138 ;
break;
}
}
if ( V_124 >= 7 ) {
goto V_135;
}
if ( ! ( V_119 & 0xfffful ) ) {
V_118 . T_2 =
F_18 ( F_69 ( V_124 + 1 ) ) ;
V_122 = V_118 . V_34 . V_136 << 16 ;
V_123 = ( V_118 . V_34 . V_137 + 1 ) << 16 ;
if ( ! V_118 . V_34 . V_35 )
goto V_135;
V_127 = true ;
} else {
F_47 ( V_79 , V_131 , L_37 ) ;
F_47 ( V_79 , V_131 , L_38 ) ;
if ( ! V_126 ) {
T_4 V_138 = F_68 ( 8 ) ;
F_51 ( V_79 , V_131 ,
L_39 , & V_138 , sizeof( V_138 ) ) ;
}
}
V_128 [ 0 ] = F_68 ( V_124 ) ;
V_128 [ 1 ] = F_68 ( 0 ) ;
V_128 [ 2 ] = F_68 ( 0x10000 ) ;
V_128 [ 3 ] = F_68 ( V_124 + 1 ) ;
V_128 [ 4 ] = F_68 ( 0 ) ;
V_128 [ 5 ] = F_68 ( 0x10000 ) ;
F_51 ( V_79 , V_131 ,
L_15 , V_128 , sizeof( V_128 ) ) ;
V_125 = F_70 ( V_79 , V_131 ) ;
if ( V_125 < 0 )
goto V_135;
V_129 = F_71 ( V_79 , V_125 , L_40 , & V_130 ) ;
if ( ! V_129 || V_130 < ( 5 * 8 * sizeof( T_4 ) ) )
goto V_135;
V_129 [ ( V_124 * 5 ) + 2 ] = F_68 ( V_120 >> 32 ) ;
V_129 [ ( V_124 * 5 ) + 3 ] = F_68 ( V_120 & 0xffffffff ) ;
V_129 [ ( V_124 * 5 ) + 4 ] = F_68 ( V_121 ) ;
if ( V_127 ) {
V_124 ++ ;
V_129 [ ( V_124 * 5 ) + 2 ] = F_68 ( V_122 >> 32 ) ;
V_129 [ ( V_124 * 5 ) + 3 ] = F_68 ( V_122 & 0xffffffff ) ;
V_129 [ ( V_124 * 5 ) + 4 ] = F_68 ( V_123 ) ;
}
goto V_139;
V_135:
F_48 ( V_79 , V_131 ) ;
V_139:
;
}
V_104 = F_44 ( V_79 , V_105 ,
L_41 , NULL ) ;
if ( V_104 ) {
union V_117 V_118 ;
unsigned long V_119 , V_120 , V_121 ;
int V_124 , V_125 ;
T_4 V_128 [ 6 ] ;
T_4 * V_129 ;
int V_130 ;
int V_140 = F_67 ( V_79 , V_104 ) ;
V_119 = V_108 -> V_141 ;
if ( V_119 == 0 )
goto V_142;
for ( V_124 = 0 ; V_124 < 8 ; V_124 ++ ) {
V_118 . T_2 = F_18 ( F_69 ( V_124 ) ) ;
V_120 = V_118 . V_34 . V_136 << 16 ;
V_121 = ( V_118 . V_34 . V_137 + 1 ) << 16 ;
if ( V_118 . V_34 . V_35 && V_119 >= V_120
&& V_119 < V_120 + V_121 )
break;
}
if ( V_124 > 7 )
goto V_142;
V_128 [ 0 ] = F_68 ( V_124 ) ;
V_128 [ 1 ] = F_68 ( 0x20 ) ;
V_128 [ 2 ] = F_68 ( 0x20 ) ;
V_128 [ 3 ] = F_68 ( V_124 ) ;
V_128 [ 4 ] = F_68 ( 0 ) ;
V_128 [ 5 ] = F_68 ( 0x20 ) ;
F_51 ( V_79 , V_140 ,
L_15 , V_128 , sizeof( V_128 ) ) ;
V_125 = F_70 ( V_79 , V_140 ) ;
if ( V_125 < 0 )
goto V_142;
V_129 = F_71 ( V_79 , V_125 , L_40 , & V_130 ) ;
if ( ! V_129 || V_130 < ( 5 * 8 * sizeof( T_4 ) ) )
goto V_142;
V_129 [ ( V_124 * 5 ) + 2 ] = F_68 ( V_120 >> 32 ) ;
V_129 [ ( V_124 * 5 ) + 3 ] = F_68 ( V_120 & 0xffffffff ) ;
V_129 [ ( V_124 * 5 ) + 4 ] = F_68 ( V_121 ) ;
goto V_143;
V_142:
F_48 ( V_79 , V_140 ) ;
V_143:
;
}
V_104 = F_44 ( V_79 , V_105 ,
L_42 , NULL ) ;
if ( V_104 ) {
int V_144 = F_67 ( V_79 , V_104 ) ;
if ( V_144 >= 0 && ( ! F_42 ( V_66 ) ||
V_108 -> V_110 == V_145 ) ) {
F_59 ( L_43 ) ;
F_48 ( V_79 , V_144 ) ;
F_47 ( V_79 , V_105 , L_42 ) ;
} else if ( V_108 -> V_110 == V_111 ||
V_108 -> V_110 == V_146 ) {
F_47 ( V_79 , V_144 , L_5 ) ;
}
}
V_104 = F_44 ( V_79 , V_105 ,
L_44 , NULL ) ;
if ( V_104 ) {
int V_147 = F_67 ( V_79 , V_104 ) ;
if ( V_147 >= 0 && ( F_72 () == V_148 ||
! F_73 ( V_149 ) ) ) {
F_59 ( L_45 ) ;
F_48 ( V_79 , V_147 ) ;
F_47 ( V_79 , V_105 , L_44 ) ;
} else {
T_4 V_150 [ 1 ] ;
enum V_151 V_152 ;
V_152 = F_74 () ;
switch ( V_152 ) {
case V_153 :
V_150 [ 0 ] = F_68 ( 48000000 ) ;
F_51 ( V_79 , V_147 ,
L_3 , V_150 , sizeof( V_150 ) ) ;
case V_154 :
F_47 ( V_79 , V_147 , L_5 ) ;
break;
default:
break;
}
}
}
return 0 ;
}
static int T_1 F_75 ( void )
{
return F_76 ( NULL , V_155 , NULL ) ;
}
