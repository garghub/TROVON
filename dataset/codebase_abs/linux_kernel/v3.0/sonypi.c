static int F_1 ( T_1 V_1 , T_1 V_2 )
{
#ifdef F_2
if ( V_3 )
return F_3 ( V_1 , V_2 ) ;
#endif
F_4 ( 1 , F_5 ( V_4 ) & 3 , V_5 ) ;
F_6 ( 0x81 , V_4 ) ;
F_4 ( 0 , F_5 ( V_4 ) & 2 , V_5 ) ;
F_6 ( V_1 , V_6 ) ;
F_4 ( 0 , F_5 ( V_4 ) & 2 , V_5 ) ;
F_6 ( V_2 , V_6 ) ;
F_4 ( 0 , F_5 ( V_4 ) & 2 , V_5 ) ;
return 0 ;
}
static int F_7 ( T_1 V_1 , T_1 * V_2 )
{
#ifdef F_2
if ( V_3 )
return F_8 ( V_1 , V_2 ) ;
#endif
F_4 ( 1 , F_5 ( V_4 ) & 3 , V_5 ) ;
F_6 ( 0x80 , V_4 ) ;
F_4 ( 0 , F_5 ( V_4 ) & 2 , V_5 ) ;
F_6 ( V_1 , V_6 ) ;
F_4 ( 0 , F_5 ( V_4 ) & 2 , V_5 ) ;
* V_2 = F_5 ( V_6 ) ;
return 0 ;
}
static int F_9 ( T_1 V_1 , T_2 * V_2 )
{
T_1 V_7 , V_8 ;
if ( F_7 ( V_1 , & V_7 ) )
return - 1 ;
if ( F_7 ( V_1 + 1 , & V_8 ) )
return - 1 ;
* V_2 = V_7 | ( V_8 << 8 ) ;
return 0 ;
}
static void F_10 ( void )
{
T_3 V_9 ;
F_11 ( V_10 . V_11 , V_12 , & V_9 ) ;
V_9 = ( V_9 & 0xFFFF0000 ) | ( ( T_3 ) V_10 . V_13 ) ;
F_12 ( V_10 . V_11 , V_12 , V_9 ) ;
F_11 ( V_10 . V_11 , V_12 , & V_9 ) ;
V_9 = ( V_9 & 0xFFF0FFFF ) |
( ( ( T_3 ) V_10 . V_13 ^ V_10 . V_14 ) << 16 ) ;
F_12 ( V_10 . V_11 , V_12 , V_9 ) ;
V_9 = F_13 ( V_15 ) ;
V_9 &= ~ ( ( ( T_3 ) 0x3 ) << V_16 ) ;
V_9 |= ( ( ( T_3 ) V_10 . V_17 ) << V_16 ) ;
F_14 ( V_9 , V_15 ) ;
F_11 ( V_10 . V_11 , V_12 , & V_9 ) ;
V_9 = ( V_9 & 0xFF1FFFFF ) | 0x00C00000 ;
F_12 ( V_10 . V_11 , V_12 , V_9 ) ;
}
static void F_15 ( void )
{
if ( F_1 ( V_18 , ( V_10 . V_13 & 0xFF00 ) >> 8 ) )
F_16 ( V_19 L_1 ) ;
if ( F_1 ( V_20 , V_10 . V_13 & 0x00FF ) )
F_16 ( V_19 L_1 ) ;
if ( F_1 ( V_21 , V_10 . V_17 ) )
F_16 ( V_19 L_1 ) ;
F_17 ( 10 ) ;
}
static void F_18 ( void )
{
T_2 V_22 ;
T_1 V_23 ;
F_15 () ;
V_22 = ( V_10 . V_13 & 0xFFF0 ) | 0x01 ;
F_19 ( V_10 . V_11 , V_24 , V_22 ) ;
F_20 ( V_10 . V_11 , V_25 , & V_23 ) ;
V_23 = ( V_23 & 0xCF ) | 0x10 ;
F_21 ( V_10 . V_11 , V_25 , V_23 ) ;
}
static void F_22 ( void )
{
T_3 V_9 ;
F_11 ( V_10 . V_11 , V_12 , & V_9 ) ;
V_9 = V_9 & 0xFF3FFFFF ;
F_12 ( V_10 . V_11 , V_12 , V_9 ) ;
V_9 = F_13 ( V_15 ) ;
V_9 |= ( 0x3 << V_16 ) ;
F_14 ( V_9 , V_15 ) ;
}
static void F_23 ( void )
{
if ( F_1 ( V_18 , 0 ) )
F_16 ( V_19 L_1 ) ;
if ( F_1 ( V_20 , 0 ) )
F_16 ( V_19 L_1 ) ;
if ( F_1 ( V_21 , 0 ) )
F_16 ( V_19 L_1 ) ;
}
static void F_24 ( void )
{
F_23 () ;
F_17 ( 10 ) ;
F_19 ( V_10 . V_11 , V_24 , 0 ) ;
}
static T_1 F_25 ( T_1 V_11 )
{
T_1 V_26 , V_27 ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_11 , V_10 . V_14 ) ;
V_26 = F_5 ( V_10 . V_14 ) ;
V_27 = F_5 ( V_10 . V_13 ) ;
return V_27 ;
}
static T_1 F_27 ( T_1 V_11 , T_1 V_28 )
{
T_1 V_26 ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_11 , V_10 . V_14 ) ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_28 , V_10 . V_13 ) ;
V_26 = F_5 ( V_10 . V_13 ) ;
return V_26 ;
}
static T_1 F_28 ( T_1 V_11 , T_1 V_28 , T_1 V_9 )
{
T_1 V_26 ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_11 , V_10 . V_14 ) ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_28 , V_10 . V_13 ) ;
F_4 ( 0 , F_5 ( V_10 . V_14 ) & 2 , V_5 ) ;
F_26 ( V_9 , V_10 . V_13 ) ;
V_26 = F_5 ( V_10 . V_13 ) ;
return V_26 ;
}
static void F_29 ( T_1 V_28 , T_1 V_9 )
{
F_4 ( 0 , F_28 ( 0x90 , V_28 , V_9 ) , V_29 ) ;
}
static int F_30 ( void )
{
T_1 V_9 ;
V_9 = F_27 ( 0x8f , V_30 ) ;
return ( V_9 != 0xff && ( V_9 & V_31 ) ) ;
}
static void F_31 ( void )
{
F_29 ( V_32 , V_33 ) ;
if ( ! V_10 . V_34 )
return;
F_27 ( 0x91 , 0 ) ;
V_10 . V_34 = 0 ;
}
static void F_32 ( void )
{
int V_35 , V_36 ;
if ( V_10 . V_34 )
return;
for ( V_36 = 5 ; V_36 > 0 ; V_36 -- ) {
while ( F_27 ( 0x91 , 0x1 ) )
F_33 ( 10 ) ;
F_25 ( 0x93 ) ;
for ( V_35 = 400 ; V_35 > 0 ; V_35 -- ) {
if ( F_30 () )
break;
F_33 ( 10 ) ;
}
if ( V_35 )
break;
}
if ( V_36 == 0 ) {
F_16 ( V_19 L_2 ) ;
return;
}
F_29 ( 0x10 , 0x5a ) ;
V_10 . V_34 = 1 ;
}
static void F_34 ( T_1 V_37 )
{
V_37 = ! ! V_37 ;
if ( V_10 . V_38 == V_37 )
return;
F_27 ( 0x96 , V_37 ) ;
F_25 ( 0x82 ) ;
V_10 . V_38 = V_37 ;
}
static void F_35 ( struct V_39 * V_40 )
{
struct V_41 V_42 ;
while ( F_36 ( & V_10 . V_43 , ( unsigned char * ) & V_42 ,
sizeof( V_42 ) , & V_10 . V_44 )
== sizeof( V_42 ) ) {
F_33 ( 10 ) ;
F_37 ( V_42 . V_11 , V_42 . V_45 , 0 ) ;
F_38 ( V_42 . V_11 ) ;
}
}
static void F_39 ( T_1 V_46 )
{
struct V_47 * V_48 = V_10 . V_49 ;
struct V_47 * V_50 = V_10 . V_51 ;
struct V_41 V_42 = { NULL } ;
int V_35 ;
switch ( V_46 ) {
case V_52 :
case V_53 :
F_40 ( V_48 , V_54 , 1 ) ;
F_38 ( V_48 ) ;
break;
case V_55 :
case V_56 :
F_40 ( V_48 , V_54 , - 1 ) ;
F_38 ( V_48 ) ;
break;
case V_57 :
V_42 . V_45 = V_58 ;
V_42 . V_11 = V_48 ;
break;
case V_59 :
break;
default:
for ( V_35 = 0 ; V_60 [ V_35 ] . V_61 ; V_35 ++ )
if ( V_46 == V_60 [ V_35 ] . V_61 ) {
V_42 . V_11 = V_50 ;
V_42 . V_45 = V_60 [ V_35 ] . V_62 ;
break;
}
break;
}
if ( V_42 . V_11 ) {
F_37 ( V_42 . V_11 , V_42 . V_45 , 1 ) ;
F_38 ( V_42 . V_11 ) ;
F_41 ( & V_10 . V_43 ,
( unsigned char * ) & V_42 , sizeof( V_42 ) ,
& V_10 . V_44 ) ;
F_42 ( & V_10 . V_63 ) ;
}
}
static T_4 F_43 ( int V_64 , void * V_65 )
{
T_1 V_26 , V_27 , V_46 = 0 ;
int V_35 , V_36 ;
V_26 = F_5 ( V_10 . V_13 ) ;
V_27 = F_5 ( V_10 . V_13 + V_10 . V_66 ) ;
for ( V_35 = 0 ; V_67 [ V_35 ] . V_68 ; V_35 ++ ) {
if ( V_10 . V_68 != V_67 [ V_35 ] . V_68 )
continue;
if ( ( V_27 & V_67 [ V_35 ] . V_69 ) !=
V_67 [ V_35 ] . V_69 )
continue;
if ( ! ( V_70 & V_67 [ V_35 ] . V_70 ) )
continue;
for ( V_36 = 0 ; V_67 [ V_35 ] . V_71 [ V_36 ] . V_46 ; V_36 ++ ) {
if ( V_26 == V_67 [ V_35 ] . V_71 [ V_36 ] . V_69 ) {
V_46 = V_67 [ V_35 ] . V_71 [ V_36 ] . V_46 ;
goto V_72;
}
}
}
if ( V_73 )
F_16 ( V_19
L_3 ,
V_26 , V_27 ) ;
return V_74 ;
V_72:
if ( V_73 > 1 )
F_16 ( V_75
L_4 , V_26 , V_27 ) ;
if ( V_76 )
F_39 ( V_46 ) ;
#ifdef F_2
if ( V_77 )
F_44 ( V_77 , 1 , V_46 ) ;
#endif
F_41 ( & V_10 . V_78 , ( unsigned char * ) & V_46 ,
sizeof( V_46 ) , & V_10 . V_79 ) ;
F_45 ( & V_10 . V_80 , V_81 , V_82 ) ;
F_46 ( & V_10 . V_83 ) ;
return V_74 ;
}
static int F_47 ( int V_84 , struct V_85 * V_86 , int V_87 )
{
return F_48 ( V_84 , V_86 , V_87 , & V_10 . V_80 ) ;
}
static int F_49 ( struct V_88 * V_88 , struct V_85 * V_85 )
{
F_50 ( & V_10 . V_89 ) ;
V_10 . V_90 -- ;
F_51 ( & V_10 . V_89 ) ;
return 0 ;
}
static int F_52 ( struct V_88 * V_88 , struct V_85 * V_85 )
{
F_50 ( & V_10 . V_89 ) ;
if ( ! V_10 . V_90 )
F_53 ( & V_10 . V_78 ) ;
V_10 . V_90 ++ ;
F_51 ( & V_10 . V_89 ) ;
return 0 ;
}
static T_5 F_54 ( struct V_85 * V_85 , char T_6 * V_91 ,
T_7 V_92 , T_8 * V_93 )
{
T_5 V_94 ;
unsigned char V_95 ;
if ( ( F_55 ( & V_10 . V_78 ) == 0 ) &&
( V_85 -> V_96 & V_97 ) )
return - V_98 ;
V_94 = F_56 ( V_10 . V_83 ,
F_55 ( & V_10 . V_78 ) != 0 ) ;
if ( V_94 )
return V_94 ;
while ( V_94 < V_92 &&
( F_36 ( & V_10 . V_78 , & V_95 , sizeof( V_95 ) ,
& V_10 . V_79 ) == sizeof( V_95 ) ) ) {
if ( F_57 ( V_95 , V_91 ++ ) )
return - V_99 ;
V_94 ++ ;
}
if ( V_94 > 0 ) {
struct V_88 * V_88 = V_85 -> V_100 . V_101 -> V_102 ;
V_88 -> V_103 = F_58 ( V_88 -> V_104 ) ;
}
return V_94 ;
}
static unsigned int F_59 ( struct V_85 * V_85 , T_9 * V_105 )
{
F_60 ( V_85 , & V_10 . V_83 , V_105 ) ;
if ( F_55 ( & V_10 . V_78 ) )
return V_106 | V_107 ;
return 0 ;
}
static long F_61 ( struct V_85 * V_108 ,
unsigned int V_109 , unsigned long V_110 )
{
long V_94 = 0 ;
void T_6 * V_111 = ( void T_6 * ) V_110 ;
T_1 V_112 ;
T_2 V_113 ;
F_50 ( & V_10 . V_89 ) ;
switch ( V_109 ) {
case V_114 :
if ( F_7 ( V_115 , & V_112 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_112 , sizeof( V_112 ) ) )
V_94 = - V_99 ;
break;
case V_117 :
if ( F_63 ( & V_112 , V_111 , sizeof( V_112 ) ) ) {
V_94 = - V_99 ;
break;
}
if ( F_1 ( V_115 , V_112 ) )
V_94 = - V_116 ;
break;
case V_118 :
if ( F_9 ( V_119 , & V_113 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_113 , sizeof( V_113 ) ) )
V_94 = - V_99 ;
break;
case V_120 :
if ( F_9 ( V_121 , & V_113 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_113 , sizeof( V_113 ) ) )
V_94 = - V_99 ;
break;
case V_122 :
if ( F_9 ( V_123 , & V_113 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_113 , sizeof( V_113 ) ) )
V_94 = - V_99 ;
break;
case V_124 :
if ( F_9 ( V_125 , & V_113 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_113 , sizeof( V_113 ) ) )
V_94 = - V_99 ;
break;
case V_126 :
if ( F_7 ( V_127 , & V_112 ) ) {
V_94 = - V_116 ;
break;
}
V_112 &= 0x07 ;
if ( F_62 ( V_111 , & V_112 , sizeof( V_112 ) ) )
V_94 = - V_99 ;
break;
case V_128 :
V_112 = V_10 . V_38 ;
if ( F_62 ( V_111 , & V_112 , sizeof( V_112 ) ) )
V_94 = - V_99 ;
break;
case V_129 :
if ( F_63 ( & V_112 , V_111 , sizeof( V_112 ) ) ) {
V_94 = - V_99 ;
break;
}
F_34 ( V_112 ) ;
break;
case V_130 :
if ( F_7 ( V_131 , & V_112 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_112 , sizeof( V_112 ) ) )
V_94 = - V_99 ;
break;
case V_132 :
if ( F_63 ( & V_112 , V_111 , sizeof( V_112 ) ) ) {
V_94 = - V_99 ;
break;
}
if ( F_1 ( V_131 , V_112 ) )
V_94 = - V_116 ;
break;
case V_133 :
if ( F_7 ( V_134 , & V_112 ) ) {
V_94 = - V_116 ;
break;
}
if ( F_62 ( V_111 , & V_112 , sizeof( V_112 ) ) )
V_94 = - V_99 ;
break;
default:
V_94 = - V_135 ;
}
F_51 ( & V_10 . V_89 ) ;
return V_94 ;
}
static void F_64 ( unsigned int V_136 )
{
switch ( V_10 . V_68 ) {
case V_137 :
F_10 () ;
break;
case V_138 :
F_15 () ;
break;
case V_139 :
F_18 () ;
break;
}
F_25 ( 0x82 ) ;
F_27 ( 0x81 , 0xff ) ;
F_25 ( V_140 ? 0x92 : 0x82 ) ;
if ( ! V_3 && V_141 )
F_26 ( 0xf0 , 0xb2 ) ;
if ( V_142 && V_136 )
F_32 () ;
}
static int F_65 ( void )
{
F_27 ( 0x81 , 0 ) ;
if ( V_142 )
F_31 () ;
if ( ! V_3 && V_141 )
F_26 ( 0xf1 , 0xb2 ) ;
switch ( V_10 . V_68 ) {
case V_137 :
F_22 () ;
break;
case V_138 :
F_23 () ;
break;
case V_139 :
F_24 () ;
break;
}
return 0 ;
}
static int F_66 ( struct V_143 * V_144 )
{
V_77 = V_144 ;
strcpy ( F_67 ( V_144 ) , L_5 ) ;
strcpy ( F_68 ( V_144 ) , L_6 ) ;
return 0 ;
}
static int F_69 ( struct V_143 * V_144 , int type )
{
V_77 = NULL ;
return 0 ;
}
static int T_10 F_70 ( struct V_145 * V_146 )
{
struct V_47 * V_48 ;
struct V_47 * V_50 ;
int V_35 ;
int error ;
V_10 . V_49 = V_48 = F_71 () ;
if ( ! V_48 )
return - V_147 ;
V_48 -> V_148 = L_7 ;
V_48 -> V_149 . V_150 = V_151 ;
V_48 -> V_149 . V_152 = V_153 ;
V_48 -> V_11 . V_154 = & V_146 -> V_11 ;
V_48 -> V_155 [ 0 ] = F_72 ( V_156 ) | F_72 ( V_157 ) ;
V_48 -> V_158 [ F_73 ( V_159 ) ] = F_72 ( V_58 ) ;
V_48 -> V_160 [ 0 ] = F_72 ( V_54 ) ;
V_10 . V_51 = V_50 = F_71 () ;
if ( ! V_50 ) {
error = - V_147 ;
goto V_161;
}
V_50 -> V_148 = L_8 ;
V_50 -> V_149 . V_150 = V_151 ;
V_50 -> V_149 . V_152 = V_153 ;
V_50 -> V_11 . V_154 = & V_146 -> V_11 ;
V_50 -> V_155 [ 0 ] = F_72 ( V_156 ) ;
for ( V_35 = 0 ; V_60 [ V_35 ] . V_61 ; V_35 ++ )
if ( V_60 [ V_35 ] . V_62 )
F_74 ( V_60 [ V_35 ] . V_62 , V_50 -> V_158 ) ;
error = F_75 ( V_48 ) ;
if ( error )
goto V_162;
error = F_75 ( V_50 ) ;
if ( error )
goto V_163;
return 0 ;
V_163:
F_76 ( V_48 ) ;
V_48 = NULL ;
V_162:
F_77 ( V_50 ) ;
V_10 . V_51 = NULL ;
V_161:
F_77 ( V_48 ) ;
V_10 . V_49 = NULL ;
return error ;
}
static int T_10 F_78 ( struct V_10 * V_11 ,
const struct V_164 * V_165 )
{
const struct V_164 * V_166 = V_165 ;
while ( V_167 && V_166 -> V_168 ) {
if ( ! F_79 ( V_166 -> V_168 ,
V_10 . V_169 ,
L_9 ) ) {
F_16 ( V_170 L_10
L_11 ,
V_166 -> V_168 ) ;
return - V_171 ;
}
F_80 ( V_166 -> V_168 , V_10 . V_169 ) ;
V_166 ++ ;
}
while ( V_165 -> V_168 ) {
if ( F_79 ( V_165 -> V_168 ,
V_10 . V_169 ,
L_12 ) ) {
V_11 -> V_13 = V_165 -> V_168 ;
V_11 -> V_14 = V_165 -> V_172 ;
return 0 ;
}
V_165 ++ ;
}
return - V_171 ;
}
static int T_10 F_81 ( struct V_10 * V_11 ,
const struct V_173 * V_174 )
{
while ( V_174 -> V_64 ) {
if ( ! F_82 ( V_174 -> V_64 , F_43 ,
V_175 , L_13 , F_43 ) ) {
V_11 -> V_64 = V_174 -> V_64 ;
V_11 -> V_17 = V_174 -> V_17 ;
return 0 ;
}
V_174 ++ ;
}
return - V_171 ;
}
static void T_10 F_83 ( void )
{
F_16 ( V_75 L_14
L_15
L_16 ,
V_10 . V_68 ,
V_73 ,
V_141 ? L_17 : L_18 ,
V_142 ? L_17 : L_18 ,
V_140 ? L_17 : L_18 ,
V_70 ,
V_76 ? L_17 : L_18 ,
V_3 ? L_17 : L_18 ) ;
F_16 ( V_75 L_19 ,
V_10 . V_64 ,
V_10 . V_13 , V_10 . V_14 ) ;
if ( V_176 == - 1 )
F_16 ( V_75 L_20 ,
V_177 . V_176 ) ;
}
static int T_10 F_84 ( struct V_145 * V_11 )
{
const struct V_164 * V_165 ;
const struct V_173 * V_174 ;
struct V_178 * V_179 ;
int error ;
F_16 ( V_19 L_21
L_22
L_23 ) ;
F_85 ( & V_10 . V_79 ) ;
error = F_86 ( & V_10 . V_78 , V_180 , V_181 ) ;
if ( error ) {
F_16 ( V_170 L_24 ) ;
return error ;
}
F_87 ( & V_10 . V_83 ) ;
F_88 ( & V_10 . V_89 ) ;
V_10 . V_38 = - 1 ;
if ( ( V_179 = F_89 ( V_182 ,
V_183 , NULL ) ) )
V_10 . V_68 = V_137 ;
else if ( ( V_179 = F_89 ( V_182 ,
V_184 , NULL ) ) )
V_10 . V_68 = V_139 ;
else if ( ( V_179 = F_89 ( V_182 ,
V_185 , NULL ) ) )
V_10 . V_68 = V_139 ;
else
V_10 . V_68 = V_138 ;
if ( V_179 && F_90 ( V_179 ) ) {
F_16 ( V_170 L_25 ) ;
error = - V_116 ;
goto V_186;
}
V_10 . V_11 = V_179 ;
if ( V_10 . V_68 == V_137 ) {
V_165 = V_187 ;
V_10 . V_169 = V_188 ;
V_10 . V_66 = V_189 ;
V_174 = V_190 ;
} else if ( V_10 . V_68 == V_138 ) {
V_165 = V_191 ;
V_10 . V_169 = V_192 ;
V_10 . V_66 = V_193 ;
V_174 = V_194 ;
} else {
V_165 = V_195 ;
V_10 . V_169 = V_196 ;
V_10 . V_66 = V_197 ;
V_174 = V_198 ;
}
error = F_78 ( & V_10 , V_165 ) ;
if ( error ) {
F_16 ( V_170 L_26 ) ;
goto V_199;
}
error = F_81 ( & V_10 , V_174 ) ;
if ( error ) {
F_16 ( V_170 L_27 ) ;
goto V_200;
}
if ( V_176 != - 1 )
V_177 . V_176 = V_176 ;
error = F_91 ( & V_177 ) ;
if ( error ) {
F_16 ( V_170 L_28 ) ;
goto V_201;
}
F_83 () ;
if ( V_76 ) {
error = F_70 ( V_11 ) ;
if ( error ) {
F_16 ( V_170
L_29 ) ;
goto V_202;
}
F_85 ( & V_10 . V_44 ) ;
error = F_86 ( & V_10 . V_43 , V_180 ,
V_181 ) ;
if ( error ) {
F_16 ( V_170 L_24 ) ;
goto V_203;
}
F_92 ( & V_10 . V_63 , F_35 ) ;
}
F_64 ( 0 ) ;
return 0 ;
V_203:
F_76 ( V_10 . V_51 ) ;
F_76 ( V_10 . V_49 ) ;
V_202:
F_93 ( & V_177 ) ;
V_201:
F_94 ( V_10 . V_64 , F_43 ) ;
V_200:
F_80 ( V_10 . V_13 , V_10 . V_169 ) ;
V_199:
if ( V_179 )
F_95 ( V_179 ) ;
V_186:
F_96 ( V_179 ) ;
F_97 ( & V_10 . V_78 ) ;
return error ;
}
static int T_11 F_98 ( struct V_145 * V_11 )
{
F_65 () ;
F_99 ( V_10 . V_64 ) ;
F_100 ( & V_10 . V_63 ) ;
if ( V_76 ) {
F_76 ( V_10 . V_51 ) ;
F_76 ( V_10 . V_49 ) ;
F_97 ( & V_10 . V_43 ) ;
}
F_93 ( & V_177 ) ;
F_94 ( V_10 . V_64 , F_43 ) ;
F_80 ( V_10 . V_13 , V_10 . V_169 ) ;
if ( V_10 . V_11 ) {
F_95 ( V_10 . V_11 ) ;
F_96 ( V_10 . V_11 ) ;
}
F_97 ( & V_10 . V_78 ) ;
return 0 ;
}
static int F_101 ( struct V_145 * V_11 , T_12 V_37 )
{
V_204 = V_10 . V_34 ;
F_65 () ;
return 0 ;
}
static int F_102 ( struct V_145 * V_11 )
{
F_64 ( V_204 ) ;
return 0 ;
}
static void F_103 ( struct V_145 * V_11 )
{
F_65 () ;
}
static int T_13 F_104 ( void )
{
int error ;
F_16 ( V_75
L_30 ,
V_205 ) ;
if ( ! F_105 ( V_206 ) )
return - V_207 ;
error = F_106 ( & V_208 ) ;
if ( error )
return error ;
V_209 = F_107 ( L_13 , - 1 ) ;
if ( ! V_209 ) {
error = - V_147 ;
goto V_210;
}
error = F_108 ( V_209 ) ;
if ( error )
goto V_211;
#ifdef F_2
if ( F_109 ( & V_212 ) >= 0 )
V_213 = 1 ;
#endif
return 0 ;
V_211:
F_110 ( V_209 ) ;
V_210:
F_111 ( & V_208 ) ;
return error ;
}
static void T_14 F_112 ( void )
{
#ifdef F_2
if ( V_213 )
F_113 ( & V_212 ) ;
#endif
F_114 ( V_209 ) ;
F_111 ( & V_208 ) ;
F_16 ( V_75 L_31 ) ;
}
