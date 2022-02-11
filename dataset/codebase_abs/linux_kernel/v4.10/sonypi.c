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
F_41 ( & V_10 . V_77 , ( unsigned char * ) & V_46 ,
sizeof( V_46 ) , & V_10 . V_78 ) ;
F_44 ( & V_10 . V_79 , V_80 , V_81 ) ;
F_45 ( & V_10 . V_82 ) ;
return V_74 ;
}
static int F_46 ( int V_83 , struct V_84 * V_85 , int V_86 )
{
return F_47 ( V_83 , V_85 , V_86 , & V_10 . V_79 ) ;
}
static int F_48 ( struct V_87 * V_87 , struct V_84 * V_84 )
{
F_49 ( & V_10 . V_88 ) ;
V_10 . V_89 -- ;
F_50 ( & V_10 . V_88 ) ;
return 0 ;
}
static int F_51 ( struct V_87 * V_87 , struct V_84 * V_84 )
{
F_49 ( & V_10 . V_88 ) ;
if ( ! V_10 . V_89 )
F_52 ( & V_10 . V_77 ) ;
V_10 . V_89 ++ ;
F_50 ( & V_10 . V_88 ) ;
return 0 ;
}
static T_5 F_53 ( struct V_84 * V_84 , char T_6 * V_90 ,
T_7 V_91 , T_8 * V_92 )
{
T_5 V_93 ;
unsigned char V_94 ;
if ( ( F_54 ( & V_10 . V_77 ) == 0 ) &&
( V_84 -> V_95 & V_96 ) )
return - V_97 ;
V_93 = F_55 ( V_10 . V_82 ,
F_54 ( & V_10 . V_77 ) != 0 ) ;
if ( V_93 )
return V_93 ;
while ( V_93 < V_91 &&
( F_36 ( & V_10 . V_77 , & V_94 , sizeof( V_94 ) ,
& V_10 . V_78 ) == sizeof( V_94 ) ) ) {
if ( F_56 ( V_94 , V_90 ++ ) )
return - V_98 ;
V_93 ++ ;
}
if ( V_93 > 0 ) {
struct V_87 * V_87 = F_57 ( V_84 ) ;
V_87 -> V_99 = F_58 ( V_87 ) ;
}
return V_93 ;
}
static unsigned int F_59 ( struct V_84 * V_84 , T_9 * V_100 )
{
F_60 ( V_84 , & V_10 . V_82 , V_100 ) ;
if ( F_54 ( & V_10 . V_77 ) )
return V_101 | V_102 ;
return 0 ;
}
static long F_61 ( struct V_84 * V_103 ,
unsigned int V_104 , unsigned long V_105 )
{
long V_93 = 0 ;
void T_6 * V_106 = ( void T_6 * ) V_105 ;
T_1 V_107 ;
T_2 V_108 ;
F_49 ( & V_10 . V_88 ) ;
switch ( V_104 ) {
case V_109 :
if ( F_7 ( V_110 , & V_107 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_107 , sizeof( V_107 ) ) )
V_93 = - V_98 ;
break;
case V_112 :
if ( F_63 ( & V_107 , V_106 , sizeof( V_107 ) ) ) {
V_93 = - V_98 ;
break;
}
if ( F_1 ( V_110 , V_107 ) )
V_93 = - V_111 ;
break;
case V_113 :
if ( F_9 ( V_114 , & V_108 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_108 , sizeof( V_108 ) ) )
V_93 = - V_98 ;
break;
case V_115 :
if ( F_9 ( V_116 , & V_108 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_108 , sizeof( V_108 ) ) )
V_93 = - V_98 ;
break;
case V_117 :
if ( F_9 ( V_118 , & V_108 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_108 , sizeof( V_108 ) ) )
V_93 = - V_98 ;
break;
case V_119 :
if ( F_9 ( V_120 , & V_108 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_108 , sizeof( V_108 ) ) )
V_93 = - V_98 ;
break;
case V_121 :
if ( F_7 ( V_122 , & V_107 ) ) {
V_93 = - V_111 ;
break;
}
V_107 &= 0x07 ;
if ( F_62 ( V_106 , & V_107 , sizeof( V_107 ) ) )
V_93 = - V_98 ;
break;
case V_123 :
V_107 = V_10 . V_38 ;
if ( F_62 ( V_106 , & V_107 , sizeof( V_107 ) ) )
V_93 = - V_98 ;
break;
case V_124 :
if ( F_63 ( & V_107 , V_106 , sizeof( V_107 ) ) ) {
V_93 = - V_98 ;
break;
}
F_34 ( V_107 ) ;
break;
case V_125 :
if ( F_7 ( V_126 , & V_107 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_107 , sizeof( V_107 ) ) )
V_93 = - V_98 ;
break;
case V_127 :
if ( F_63 ( & V_107 , V_106 , sizeof( V_107 ) ) ) {
V_93 = - V_98 ;
break;
}
if ( F_1 ( V_126 , V_107 ) )
V_93 = - V_111 ;
break;
case V_128 :
if ( F_7 ( V_129 , & V_107 ) ) {
V_93 = - V_111 ;
break;
}
if ( F_62 ( V_106 , & V_107 , sizeof( V_107 ) ) )
V_93 = - V_98 ;
break;
default:
V_93 = - V_130 ;
}
F_50 ( & V_10 . V_88 ) ;
return V_93 ;
}
static void F_64 ( unsigned int V_131 )
{
switch ( V_10 . V_68 ) {
case V_132 :
F_10 () ;
break;
case V_133 :
F_15 () ;
break;
case V_134 :
F_18 () ;
break;
}
F_25 ( 0x82 ) ;
F_27 ( 0x81 , 0xff ) ;
F_25 ( V_135 ? 0x92 : 0x82 ) ;
if ( ! V_3 && V_136 )
F_26 ( 0xf0 , 0xb2 ) ;
if ( V_137 && V_131 )
F_32 () ;
}
static int F_65 ( void )
{
F_27 ( 0x81 , 0 ) ;
if ( V_137 )
F_31 () ;
if ( ! V_3 && V_136 )
F_26 ( 0xf1 , 0xb2 ) ;
switch ( V_10 . V_68 ) {
case V_132 :
F_22 () ;
break;
case V_133 :
F_23 () ;
break;
case V_134 :
F_24 () ;
break;
}
return 0 ;
}
static int F_66 ( struct V_138 * V_139 )
{
V_140 = V_139 ;
strcpy ( F_67 ( V_139 ) , L_5 ) ;
strcpy ( F_68 ( V_139 ) , L_6 ) ;
return 0 ;
}
static int F_69 ( struct V_138 * V_139 )
{
V_140 = NULL ;
return 0 ;
}
static int F_70 ( struct V_141 * V_142 )
{
struct V_47 * V_48 ;
struct V_47 * V_50 ;
int V_35 ;
int error ;
V_10 . V_49 = V_48 = F_71 () ;
if ( ! V_48 )
return - V_143 ;
V_48 -> V_144 = L_7 ;
V_48 -> V_145 . V_146 = V_147 ;
V_48 -> V_145 . V_148 = V_149 ;
V_48 -> V_11 . V_150 = & V_142 -> V_11 ;
V_48 -> V_151 [ 0 ] = F_72 ( V_152 ) | F_72 ( V_153 ) ;
V_48 -> V_154 [ F_73 ( V_155 ) ] = F_72 ( V_58 ) ;
V_48 -> V_156 [ 0 ] = F_72 ( V_54 ) ;
V_10 . V_51 = V_50 = F_71 () ;
if ( ! V_50 ) {
error = - V_143 ;
goto V_157;
}
V_50 -> V_144 = L_8 ;
V_50 -> V_145 . V_146 = V_147 ;
V_50 -> V_145 . V_148 = V_149 ;
V_50 -> V_11 . V_150 = & V_142 -> V_11 ;
V_50 -> V_151 [ 0 ] = F_72 ( V_152 ) ;
for ( V_35 = 0 ; V_60 [ V_35 ] . V_61 ; V_35 ++ )
if ( V_60 [ V_35 ] . V_62 )
F_74 ( V_60 [ V_35 ] . V_62 , V_50 -> V_154 ) ;
error = F_75 ( V_48 ) ;
if ( error )
goto V_158;
error = F_75 ( V_50 ) ;
if ( error )
goto V_159;
return 0 ;
V_159:
F_76 ( V_48 ) ;
V_48 = NULL ;
V_158:
F_77 ( V_50 ) ;
V_10 . V_51 = NULL ;
V_157:
F_77 ( V_48 ) ;
V_10 . V_49 = NULL ;
return error ;
}
static int F_78 ( struct V_10 * V_11 ,
const struct V_160 * V_161 )
{
const struct V_160 * V_162 = V_161 ;
while ( V_163 && V_162 -> V_164 ) {
if ( ! F_79 ( V_162 -> V_164 ,
V_10 . V_165 ,
L_9 ) ) {
F_16 ( V_166 L_10
L_11 ,
V_162 -> V_164 ) ;
return - V_167 ;
}
F_80 ( V_162 -> V_164 , V_10 . V_165 ) ;
V_162 ++ ;
}
while ( V_161 -> V_164 ) {
if ( F_79 ( V_161 -> V_164 ,
V_10 . V_165 ,
L_12 ) ) {
V_11 -> V_13 = V_161 -> V_164 ;
V_11 -> V_14 = V_161 -> V_168 ;
return 0 ;
}
V_161 ++ ;
}
return - V_167 ;
}
static int F_81 ( struct V_10 * V_11 ,
const struct V_169 * V_170 )
{
while ( V_170 -> V_64 ) {
if ( ! F_82 ( V_170 -> V_64 , F_43 ,
V_171 , L_13 , F_43 ) ) {
V_11 -> V_64 = V_170 -> V_64 ;
V_11 -> V_17 = V_170 -> V_17 ;
return 0 ;
}
V_170 ++ ;
}
return - V_167 ;
}
static void F_83 ( void )
{
F_16 ( V_75 L_14
L_15
L_16 ,
V_10 . V_68 ,
V_73 ,
V_136 ? L_17 : L_18 ,
V_137 ? L_17 : L_18 ,
V_135 ? L_17 : L_18 ,
V_70 ,
V_76 ? L_17 : L_18 ,
V_3 ? L_17 : L_18 ) ;
F_16 ( V_75 L_19 ,
V_10 . V_64 ,
V_10 . V_13 , V_10 . V_14 ) ;
if ( V_172 == - 1 )
F_16 ( V_75 L_20 ,
V_173 . V_172 ) ;
}
static int F_84 ( struct V_141 * V_11 )
{
const struct V_160 * V_161 ;
const struct V_169 * V_170 ;
struct V_174 * V_175 ;
int error ;
F_16 ( V_19 L_21
L_22
L_23 ) ;
F_85 ( & V_10 . V_78 ) ;
error = F_86 ( & V_10 . V_77 , V_176 , V_177 ) ;
if ( error ) {
F_16 ( V_166 L_24 ) ;
return error ;
}
F_87 ( & V_10 . V_82 ) ;
F_88 ( & V_10 . V_88 ) ;
V_10 . V_38 = - 1 ;
if ( ( V_175 = F_89 ( V_178 ,
V_179 , NULL ) ) )
V_10 . V_68 = V_132 ;
else if ( ( V_175 = F_89 ( V_178 ,
V_180 , NULL ) ) )
V_10 . V_68 = V_134 ;
else if ( ( V_175 = F_89 ( V_178 ,
V_181 , NULL ) ) )
V_10 . V_68 = V_134 ;
else
V_10 . V_68 = V_133 ;
if ( V_175 && F_90 ( V_175 ) ) {
F_16 ( V_166 L_25 ) ;
error = - V_111 ;
goto V_182;
}
V_10 . V_11 = V_175 ;
if ( V_10 . V_68 == V_132 ) {
V_161 = V_183 ;
V_10 . V_165 = V_184 ;
V_10 . V_66 = V_185 ;
V_170 = V_186 ;
} else if ( V_10 . V_68 == V_133 ) {
V_161 = V_187 ;
V_10 . V_165 = V_188 ;
V_10 . V_66 = V_189 ;
V_170 = V_190 ;
} else {
V_161 = V_191 ;
V_10 . V_165 = V_192 ;
V_10 . V_66 = V_193 ;
V_170 = V_194 ;
}
error = F_78 ( & V_10 , V_161 ) ;
if ( error ) {
F_16 ( V_166 L_26 ) ;
goto V_195;
}
error = F_81 ( & V_10 , V_170 ) ;
if ( error ) {
F_16 ( V_166 L_27 ) ;
goto V_196;
}
if ( V_172 != - 1 )
V_173 . V_172 = V_172 ;
error = F_91 ( & V_173 ) ;
if ( error ) {
F_16 ( V_166 L_28 ) ;
goto V_197;
}
F_83 () ;
if ( V_76 ) {
error = F_70 ( V_11 ) ;
if ( error ) {
F_16 ( V_166
L_29 ) ;
goto V_198;
}
F_85 ( & V_10 . V_44 ) ;
error = F_86 ( & V_10 . V_43 , V_176 ,
V_177 ) ;
if ( error ) {
F_16 ( V_166 L_24 ) ;
goto V_199;
}
F_92 ( & V_10 . V_63 , F_35 ) ;
}
F_64 ( 0 ) ;
return 0 ;
V_199:
F_76 ( V_10 . V_51 ) ;
F_76 ( V_10 . V_49 ) ;
V_198:
F_93 ( & V_173 ) ;
V_197:
F_94 ( V_10 . V_64 , F_43 ) ;
V_196:
F_80 ( V_10 . V_13 , V_10 . V_165 ) ;
V_195:
if ( V_175 )
F_95 ( V_175 ) ;
V_182:
F_96 ( V_175 ) ;
F_97 ( & V_10 . V_77 ) ;
return error ;
}
static int F_98 ( struct V_141 * V_11 )
{
F_65 () ;
F_99 ( V_10 . V_64 ) ;
F_100 ( & V_10 . V_63 ) ;
if ( V_76 ) {
F_76 ( V_10 . V_51 ) ;
F_76 ( V_10 . V_49 ) ;
F_97 ( & V_10 . V_43 ) ;
}
F_93 ( & V_173 ) ;
F_94 ( V_10 . V_64 , F_43 ) ;
F_80 ( V_10 . V_13 , V_10 . V_165 ) ;
if ( V_10 . V_11 ) {
F_95 ( V_10 . V_11 ) ;
F_96 ( V_10 . V_11 ) ;
}
F_97 ( & V_10 . V_77 ) ;
return 0 ;
}
static int F_101 ( struct V_139 * V_11 )
{
V_200 = V_10 . V_34 ;
F_65 () ;
return 0 ;
}
static int F_102 ( struct V_139 * V_11 )
{
F_64 ( V_200 ) ;
return 0 ;
}
static void F_103 ( struct V_141 * V_11 )
{
F_65 () ;
}
static int T_10 F_104 ( void )
{
int error ;
F_16 ( V_75
L_30 ,
V_201 ) ;
if ( ! F_105 ( V_202 ) )
return - V_203 ;
error = F_106 ( & V_204 ) ;
if ( error )
return error ;
V_205 = F_107 ( L_13 , - 1 ) ;
if ( ! V_205 ) {
error = - V_143 ;
goto V_206;
}
error = F_108 ( V_205 ) ;
if ( error )
goto V_207;
#ifdef F_2
if ( F_109 ( & V_208 ) >= 0 )
V_209 = 1 ;
#endif
return 0 ;
V_207:
F_110 ( V_205 ) ;
V_206:
F_111 ( & V_204 ) ;
return error ;
}
static void T_11 F_112 ( void )
{
#ifdef F_2
if ( V_209 )
F_113 ( & V_208 ) ;
#endif
F_114 ( V_205 ) ;
F_111 ( & V_204 ) ;
F_16 ( V_75 L_31 ) ;
}
