static void F_1 ( int V_1 )
{
unsigned long V_2 = V_3 + ( ( V_1 * V_4 ) / 1000 ) ;
while ( F_2 ( V_3 , V_2 ) )
F_3 () ;
}
static void F_4 ( int V_5 )
{
F_5 ( 0 , F_6 ( V_5 ) ) ;
F_5 ( V_6 | V_7 , F_7 ( V_5 ) ) ;
F_5 ( 1 , F_8 ( V_5 ) ) ;
F_5 ( 0 , F_9 ( V_5 ) ) ;
F_5 ( V_7 , F_7 ( V_5 ) ) ;
F_10 ( F_11 ( V_5 ) ) ;
F_10 ( F_12 ( V_5 ) ) ;
F_5 ( V_8 | V_9 , F_13 ( V_5 ) ) ;
F_1 ( 100 ) ;
F_5 ( V_10 | V_11 | V_8 | V_9 , F_13 ( V_5 ) ) ;
F_1 ( 100 ) ;
}
static int F_14 ( int V_5 , unsigned char V_12 )
{
unsigned char V_13 ;
int V_14 ;
unsigned long V_2 = V_3 + V_4 / 10 ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
V_13 = ( V_12 & 0x80 ) ? ( V_11 | V_10 ) : V_10 ;
F_5 ( V_13 | V_8 | V_9 , F_13 ( V_5 ) ) ;
V_12 <<= 1 ;
F_5 ( 0xfc , F_15 ( V_5 ) ) ;
while ( ( F_10 ( F_11 ( V_5 ) ) & V_15 ) == 0 )
if ( F_16 ( V_3 , V_2 ) )
return - 1 ;
}
return 0 ;
}
static unsigned char * F_17 ( unsigned char * V_16 , int V_17 ,
unsigned int V_18 )
{
const char * V_19 [ 2 ] = { V_20 , V_21 } ;
const struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
switch ( V_18 ) {
case 0 :
V_23 = NULL ;
break;
case V_29 :
case V_30 :
V_18 -- ;
V_25 = F_18 ( L_1 , 0 , NULL , 0 ) ;
if ( F_19 ( V_25 ) ) {
F_20 ( V_31 L_2 ) ;
return NULL ;
}
V_28 = F_21 ( & V_23 , V_19 [ V_18 ] , & V_25 -> V_32 ) ;
F_22 ( V_25 ) ;
if ( V_28 ) {
F_20 ( V_31 L_3 ,
V_19 [ V_18 ] ) ;
return NULL ;
}
if ( V_23 -> V_33 != V_34 ) {
F_20 ( V_31 L_4 ,
V_23 -> V_33 , V_19 [ V_18 ] ) ;
F_23 ( V_23 ) ;
return NULL ;
}
V_16 = ( unsigned char * ) V_23 -> V_35 ;
break;
default:
F_20 ( V_31 L_5 , V_18 ) ;
return NULL ;
}
V_27 = V_36 ;
while ( V_27 ) {
if ( V_27 -> V_17 == V_17 ) {
memcpy ( V_27 -> V_16 , V_16 , V_34 ) ;
goto V_37;
}
V_27 = V_27 -> V_38 ;
}
if ( ( V_27 = F_24 ( sizeof( struct V_26 ) , V_39 ) ) == NULL ) {
F_23 ( V_23 ) ;
return NULL ;
}
memcpy ( V_27 -> V_16 , V_16 , V_34 ) ;
V_27 -> V_17 = V_17 ;
V_27 -> V_38 = V_36 ;
V_36 = V_27 ;
V_37:
F_23 ( V_23 ) ;
return V_27 -> V_16 ;
}
static unsigned char * F_25 ( int V_17 )
{
struct V_26 * V_27 ;
V_27 = V_36 ;
while ( V_27 ) {
if ( V_27 -> V_17 == V_17 )
return V_27 -> V_16 ;
V_27 = V_27 -> V_38 ;
}
switch ( V_17 ) {
case 1200 :
return F_17 ( NULL , V_17 , V_29 ) ;
default:
return F_17 ( NULL , V_17 , V_30 ) ;
}
}
static int F_26 ( int V_5 , int V_17 )
{
int V_40 , V_41 ;
unsigned char * V_42 ;
V_42 = F_25 ( V_17 ) ;
if ( V_42 == NULL )
return - 1 ;
F_4 ( V_5 ) ;
for ( V_40 = 0 ; V_40 < V_34 ; V_40 ++ ) {
if ( F_14 ( V_5 , V_42 [ V_40 ] ) ) {
F_20 ( V_31 L_6 ) ;
return - 1 ;
}
}
F_14 ( V_5 , 0xFF ) ;
V_41 = F_10 ( F_12 ( V_5 ) ) ;
F_1 ( 50 ) ;
return ( V_41 & V_43 ) ? 0 : - 1 ;
}
static void F_27 ( struct V_44 * V_32 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
int V_47 = 115200 / V_46 -> V_48 ;
F_5 ( 0 , F_6 ( V_32 -> V_49 ) ) ;
F_5 ( V_6 | V_50 , F_7 ( V_32 -> V_49 ) ) ;
F_5 ( V_47 , F_8 ( V_32 -> V_49 ) ) ;
F_5 ( 0 , F_9 ( V_32 -> V_49 ) ) ;
F_5 ( V_50 , F_7 ( V_32 -> V_49 ) ) ;
F_5 ( V_51 , F_13 ( V_32 -> V_49 ) ) ;
F_5 ( 0x00 , F_29 ( V_32 -> V_49 ) ) ;
F_10 ( F_30 ( V_32 -> V_49 ) ) ;
F_10 ( F_12 ( V_32 -> V_49 ) ) ;
F_5 ( V_52 , F_6 ( V_32 -> V_49 ) ) ;
}
static enum V_53 F_31 ( unsigned int V_5 )
{
unsigned char V_54 , V_55 , V_56 ;
enum V_53 V_57 ;
enum V_53 V_58 [] =
{ V_59 , V_60 , V_61 , V_62 } ;
V_54 = F_10 ( F_13 ( V_5 ) ) ;
F_5 ( V_54 | 0x10 , F_13 ( V_5 ) ) ;
V_55 = F_10 ( F_12 ( V_5 ) ) ;
F_5 ( 0x1a , F_13 ( V_5 ) ) ;
V_56 = F_10 ( F_12 ( V_5 ) ) & 0xf0 ;
F_5 ( V_54 , F_13 ( V_5 ) ) ;
F_5 ( V_55 , F_12 ( V_5 ) ) ;
if ( V_56 != 0x90 )
return V_60 ;
F_10 ( F_30 ( V_5 ) ) ;
F_10 ( F_30 ( V_5 ) ) ;
F_5 ( 0x01 , F_29 ( V_5 ) ) ;
V_57 = V_58 [ ( F_10 ( F_32 ( V_5 ) ) >> 6 ) & 3 ] ;
if ( V_57 == V_59 ) {
F_5 ( 0x5a , F_33 ( V_5 ) ) ;
V_54 = F_10 ( F_33 ( V_5 ) ) ;
F_5 ( 0xa5 , F_33 ( V_5 ) ) ;
V_55 = F_10 ( F_33 ( V_5 ) ) ;
if ( ( V_54 != 0x5a ) || ( V_55 != 0xa5 ) )
V_57 = V_63 ;
}
return V_57 ;
}
static inline void F_34 ( struct V_44 * V_32 , struct V_45 * V_46 )
{
if ( V_46 -> V_64 && V_46 -> V_65 >= 3 && V_46 -> V_65 < V_66 ) {
int V_67 = V_46 -> V_65 - 2 + 1 ;
struct V_68 * V_69 ;
if ( ( V_46 -> V_70 & V_46 -> V_71 ) != 0xFF ) {
} else {
if ( ! ( V_69 = F_35 ( V_67 ) ) ) {
F_20 ( V_72 L_7 , V_32 -> V_73 ) ;
++ V_32 -> V_74 . V_75 ;
} else {
unsigned char * V_76 ;
V_76 = F_36 ( V_69 , V_67 ) ;
* V_76 ++ = 0 ;
memcpy ( V_76 , V_46 -> V_77 , V_67 - 1 ) ;
V_69 -> V_78 = F_37 ( V_69 , V_32 ) ;
F_38 ( V_69 ) ;
++ V_32 -> V_74 . V_79 ;
}
}
}
V_46 -> V_65 = 0 ;
V_46 -> V_71 = 0x21 ;
V_46 -> V_70 = 0xf3 ;
}
static inline void F_39 ( struct V_44 * V_32 , struct V_45 * V_46 , unsigned char V_80 )
{
if ( V_46 -> V_65 < V_66 ) {
unsigned char V_81 = V_46 -> V_71 ;
V_46 -> V_71 = ( V_82 [ V_81 ] ^ V_46 -> V_70 ) ;
V_46 -> V_70 = ( V_83 [ V_81 ] ^ V_80 ) ;
V_46 -> V_77 [ V_46 -> V_65 ++ ] = V_80 ;
}
}
static void F_40 ( struct V_44 * V_32 )
{
F_5 ( V_84 , F_13 ( V_32 -> V_49 ) ) ;
}
static void F_41 ( struct V_44 * V_32 )
{
F_5 ( V_51 , F_13 ( V_32 -> V_49 ) ) ;
}
static T_1 F_42 ( struct V_68 * V_69 ,
struct V_44 * V_32 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
F_43 ( & V_46 -> V_85 , V_69 ) ;
V_32 -> V_86 = V_3 ;
return V_87 ;
}
static void F_44 ( struct V_44 * V_32 , struct V_45 * V_46 )
{
if ( ( V_46 -> V_88 == V_89 ) || ( V_46 -> V_90 == 0 ) )
V_46 -> V_91 = 1 ;
else
V_46 -> V_91 = ( V_46 -> V_17 * V_46 -> V_90 ) / 8000 ;
V_46 -> V_88 = V_92 ;
F_40 ( V_32 ) ;
}
static void F_45 ( struct V_44 * V_32 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
if ( V_46 -> V_93 != V_94 || V_46 -> V_88 != V_95 ||
F_46 ( & V_46 -> V_85 ) )
return;
if ( V_46 -> V_96 ) {
F_44 ( V_32 , V_46 ) ;
return;
}
if ( V_46 -> V_64 ) {
V_46 -> V_97 = V_46 -> V_98 / 10 ;
return;
}
if ( ( -- V_46 -> V_97 ) > 0 )
return;
V_46 -> V_97 = V_46 -> V_98 / 10 ;
if ( ( F_47 () % 256 ) > V_46 -> V_99 )
return;
F_44 ( V_32 , V_46 ) ;
}
static void F_48 ( unsigned long V_100 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
struct V_44 * V_32 = V_102 [ V_40 ] ;
if ( V_32 && F_49 ( V_32 ) )
F_45 ( V_32 ) ;
}
V_103 . V_104 = V_3 + V_4 / 100 ;
F_50 ( & V_103 ) ;
}
static void F_51 ( struct V_44 * V_32 , struct V_45 * V_46 )
{
struct V_68 * V_69 ;
unsigned char V_105 , V_106 ;
switch ( V_46 -> V_88 ) {
case V_95 :
break;
case V_92 :
if ( -- V_46 -> V_91 <= 0 ) {
if ( ! ( V_69 = F_52 ( & V_46 -> V_85 ) ) ) {
F_41 ( V_32 ) ;
V_46 -> V_88 = V_95 ;
break;
}
V_46 -> V_88 = V_107 ;
if ( V_69 -> V_35 [ 0 ] != 0 ) {
F_53 ( V_69 ) ;
break;
}
V_46 -> V_108 = V_69 -> V_109 - 1 ;
if ( V_46 -> V_108 >= V_66 || V_46 -> V_108 < 2 ) {
F_53 ( V_69 ) ;
break;
}
F_54 ( V_69 , 1 ,
V_46 -> V_110 ,
V_46 -> V_108 ) ;
F_53 ( V_69 ) ;
V_46 -> V_91 = 0 ;
V_46 -> V_111 = 0x21 ;
V_46 -> V_112 = 0xf3 ;
V_46 -> V_88 = V_107 ;
}
break;
case V_107 :
V_105 = V_46 -> V_110 [ V_46 -> V_91 ++ ] ;
F_5 ( V_105 , F_15 ( V_32 -> V_49 ) ) ;
V_106 = V_46 -> V_111 ;
V_46 -> V_111 = V_82 [ V_106 ] ^ V_46 -> V_112 ;
V_46 -> V_112 = V_83 [ V_106 ] ^ V_105 ;
if ( V_46 -> V_91 >= V_46 -> V_108 ) {
V_46 -> V_88 = V_113 ;
}
break;
case V_113 :
V_46 -> V_112 = V_82 [ V_46 -> V_111 ] ^ V_46 -> V_112 ;
V_46 -> V_111 = V_83 [ V_46 -> V_111 ] ^ V_82 [ V_46 -> V_112 ] ^ 0xff ;
F_5 ( V_46 -> V_111 , F_15 ( V_32 -> V_49 ) ) ;
V_46 -> V_88 = V_114 ;
break;
case V_114 :
F_5 ( V_83 [ V_46 -> V_112 ] ^ 0xFF , F_15 ( V_32 -> V_49 ) ) ;
if ( F_46 ( & V_46 -> V_85 ) ) {
V_46 -> V_91 = ( V_46 -> V_17 * V_46 -> V_115 ) / 8000 ;
if ( V_46 -> V_96 == 2 )
V_46 -> V_91 += ( V_46 -> V_17 * V_46 -> V_116 ) / 8 ;
if ( V_46 -> V_91 == 0 )
V_46 -> V_91 = 1 ;
V_46 -> V_88 = V_89 ;
} else {
V_46 -> V_91 = 1 ;
V_46 -> V_88 = V_92 ;
}
++ V_32 -> V_74 . V_117 ;
break;
case V_89 :
if ( -- V_46 -> V_91 <= 0 ) {
V_46 -> V_88 = V_95 ;
F_41 ( V_32 ) ;
}
break;
}
}
static T_2 F_55 ( int V_118 , void * V_119 )
{
struct V_44 * V_32 ;
struct V_45 * V_46 ;
unsigned char V_120 ;
int V_121 = 100 ;
int V_40 ;
int V_122 = 0 ;
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
V_32 = V_102 [ V_40 ] ;
V_46 = F_28 ( V_32 ) ;
if ( ! F_49 ( V_32 ) )
continue;
while ( ( V_120 = V_123 & F_10 ( F_32 ( V_32 -> V_49 ) ) ) != V_124 ) {
unsigned char V_125 = F_10 ( F_12 ( V_32 -> V_49 ) ) ;
unsigned char V_126 = F_10 ( F_11 ( V_32 -> V_49 ) ) ;
unsigned char V_80 ;
V_122 = 1 ;
if ( V_126 & V_127 )
++ V_32 -> V_74 . V_128 ;
V_46 -> V_64 = ( V_125 & V_129 ) ? 1 : 0 ;
if ( -- V_121 <= 0 ) {
F_20 ( V_31 L_8 ,
V_32 -> V_73 , V_120 ) ;
goto V_37;
}
if ( V_125 & V_130 ) {
++ V_46 -> V_131 ;
F_51 ( V_32 , V_46 ) ;
}
if ( V_126 & V_132 ) {
++ V_46 -> V_133 ;
V_80 = F_10 ( F_30 ( V_32 -> V_49 ) ) ;
if ( V_125 & V_134 )
F_34 ( V_32 , V_46 ) ;
else
F_39 ( V_32 , V_46 , V_80 ) ;
}
}
}
V_37:
return F_56 ( V_122 ) ;
}
static void * F_57 ( struct V_135 * V_136 , T_3 * V_137 )
{
return ( * V_137 < V_101 ) ? V_102 [ * V_137 ] : NULL ;
}
static void * F_58 ( struct V_135 * V_136 , void * V_138 , T_3 * V_137 )
{
++ * V_137 ;
return ( * V_137 < V_101 ) ? V_102 [ * V_137 ] : NULL ;
}
static void F_59 ( struct V_135 * V_136 , void * V_138 )
{
}
static int F_60 ( struct V_135 * V_136 , void * V_138 )
{
struct V_44 * V_32 = V_138 ;
const struct V_45 * V_46 = F_28 ( V_32 ) ;
F_61 ( V_136 , L_9 , V_32 -> V_73 ) ;
F_61 ( V_136 , L_10 , F_49 ( V_32 ) ) ;
F_61 ( V_136 , L_11 , V_46 -> V_17 ) ;
F_61 ( V_136 , L_12 , V_46 -> V_5 ) ;
F_61 ( V_136 , L_13 , V_46 -> V_48 ) ;
F_61 ( V_136 , L_14 , V_46 -> V_118 ) ;
F_61 ( V_136 , L_15 , V_46 -> V_88 ) ;
F_61 ( V_136 , L_16 , V_46 -> V_96 ) ;
F_61 ( V_136 , L_17 , V_46 -> V_116 ) ;
F_61 ( V_136 , L_18 , V_46 -> V_90 ) ;
F_61 ( V_136 , L_19 , V_46 -> V_115 ) ;
F_61 ( V_136 , L_20 , V_46 -> V_98 ) ;
F_61 ( V_136 , L_21 , V_46 -> V_99 ) ;
F_61 ( V_136 , L_22 , V_32 -> V_74 . V_117 ) ;
F_61 ( V_136 , L_23 , V_32 -> V_74 . V_79 ) ;
F_61 ( V_136 , L_24 , V_46 -> V_131 ) ;
F_61 ( V_136 , L_25 , V_46 -> V_133 ) ;
F_61 ( V_136 , L_26 , V_32 -> V_74 . V_128 ) ;
F_61 ( V_136 , L_27 ) ;
return 0 ;
}
static int F_62 ( struct V_139 * V_139 , struct V_140 * V_140 )
{
return F_63 ( V_140 , & V_141 ) ;
}
static int F_64 ( struct V_44 * V_32 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
enum V_53 V_57 ;
int V_40 ;
int V_142 = 0 ;
F_20 ( V_143 L_28 , V_32 -> V_73 , V_32 -> V_49 , V_32 -> V_118 ) ;
if ( ! V_46 -> V_17 )
return - V_144 ;
if ( ! V_32 -> V_49 || V_32 -> V_49 > 0x1000 - V_145 ||
V_32 -> V_118 < 2 || V_32 -> V_118 > 15 ) {
return - V_144 ;
}
if ( ! F_65 ( V_32 -> V_49 , V_145 , V_32 -> V_73 ) )
{
F_20 ( V_31 L_29 , V_32 -> V_73 , V_32 -> V_49 ) ;
return - V_146 ;
}
if ( ( V_57 = F_31 ( V_32 -> V_49 ) ) == V_60 ) {
F_20 ( V_31 L_30 , V_32 -> V_73 ) ;
V_142 = - V_147 ;
goto V_148;
}
if ( F_26 ( V_32 -> V_49 , V_46 -> V_17 ) ) {
F_20 ( V_31 L_31 , V_32 -> V_73 ) ;
V_142 = - V_147 ;
goto V_148;
}
F_5 ( 0 , F_6 ( V_32 -> V_49 ) ) ;
if ( F_66 ( V_32 -> V_118 , F_55 , V_149 | V_150 , V_32 -> V_73 , V_32 ) ) {
F_20 ( V_31 L_32 , V_32 -> V_73 , V_32 -> V_118 ) ;
V_142 = - V_151 ;
goto V_148;
}
F_27 ( V_32 ) ;
F_67 ( V_32 ) ;
V_46 -> V_97 = V_46 -> V_98 / 10 ;
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
struct V_44 * V_152 = V_102 [ V_40 ] ;
F_10 ( F_11 ( V_152 -> V_49 ) ) ;
V_152 -> V_74 . V_128 = 0 ;
}
F_20 ( V_143 L_33 , V_32 -> V_73 , V_32 -> V_49 , V_32 -> V_118 ,
V_153 [ V_57 ] ) ;
return 0 ;
V_148:
F_68 ( V_32 -> V_49 , V_145 ) ;
return V_142 ;
}
static int F_69 ( struct V_44 * V_32 )
{
struct V_68 * V_69 ;
struct V_45 * V_46 = F_28 ( V_32 ) ;
if ( ! V_32 )
return - V_154 ;
F_5 ( 0 , F_6 ( V_32 -> V_49 ) ) ;
F_5 ( 1 , F_13 ( V_32 -> V_49 ) ) ;
F_70 ( V_32 -> V_118 , V_32 ) ;
F_68 ( V_32 -> V_49 , V_145 ) ;
F_71 ( V_32 ) ;
while ( ( V_69 = F_52 ( & V_46 -> V_85 ) ) )
F_72 ( V_69 ) ;
F_20 ( V_143 L_34 ,
V_155 , V_32 -> V_49 , V_32 -> V_118 ) ;
return 0 ;
}
static int F_73 ( struct V_44 * V_32 , struct V_156 * V_157 , int V_158 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
struct V_159 V_160 ;
struct V_161 * V_162 ;
int V_163 ;
if ( F_74 ( & V_163 , V_157 -> V_164 , sizeof( int ) ) )
return - V_165 ;
if ( V_46 -> V_93 != V_94 )
return - V_154 ;
if ( ! F_75 ( V_166 ) )
return - V_167 ;
if ( V_158 != V_168 )
return - V_154 ;
switch ( V_163 ) {
case V_169 :
return - V_154 ;
case V_170 :
if ( F_49 ( V_32 ) )
return - V_154 ;
if ( ( V_162 = F_24 ( sizeof( struct V_161 ) , V_39 ) ) == NULL )
return - V_171 ;
if ( F_74 ( V_162 , V_157 -> V_164 , sizeof( struct V_161 ) ) ) {
F_76 ( V_162 ) ;
return - V_165 ;
}
if ( V_162 -> V_17 > V_172 ) {
F_76 ( V_162 ) ;
return - V_154 ;
}
F_17 ( V_162 -> V_16 , V_162 -> V_17 , 0 ) ;
F_76 ( V_162 ) ;
break;
case V_173 :
if ( ! F_75 ( V_174 ) )
return - V_167 ;
if ( F_74 ( & V_160 , V_157 -> V_164 , sizeof( struct V_159 ) ) )
return - V_165 ;
if ( ( V_160 . V_175 . V_176 & V_177 ) && F_49 ( V_32 ) )
return - V_154 ;
if ( ( V_160 . V_175 . V_176 & V_178 ) && F_49 ( V_32 ) )
return - V_154 ;
if ( ( V_160 . V_175 . V_176 & V_179 ) && F_49 ( V_32 ) )
return - V_154 ;
if ( ( V_160 . V_175 . V_176 & V_180 ) && F_49 ( V_32 ) )
return - V_154 ;
if ( V_160 . V_175 . V_176 & V_177 ) {
V_46 -> V_5 = V_160 . V_175 . V_5 ;
V_32 -> V_49 = V_160 . V_175 . V_5 ;
}
if ( V_160 . V_175 . V_176 & V_178 ) {
if ( V_160 . V_175 . V_118 > 15 )
return - V_154 ;
V_46 -> V_118 = V_160 . V_175 . V_118 ;
V_32 -> V_118 = V_160 . V_175 . V_118 ;
}
if ( V_160 . V_175 . V_176 & V_179 ) {
if ( V_160 . V_175 . V_17 > V_172 )
return - V_154 ;
V_46 -> V_17 = V_160 . V_175 . V_17 ;
}
if ( V_160 . V_175 . V_176 & V_180 ) {
if ( V_160 . V_175 . V_48 > V_181 )
return - V_154 ;
V_46 -> V_48 = V_160 . V_175 . V_48 ;
}
if ( V_160 . V_175 . V_176 & V_182 ) {
if ( V_160 . V_175 . V_183 > V_184 )
return - V_154 ;
V_46 -> V_96 = V_160 . V_175 . V_183 ;
}
if ( V_160 . V_175 . V_176 & V_185 ) {
if ( V_160 . V_175 . V_186 > V_187 )
return - V_154 ;
V_46 -> V_116 = V_160 . V_175 . V_186 ;
}
if ( V_160 . V_175 . V_176 & V_188 ) {
if ( V_160 . V_175 . V_189 > V_190 )
return - V_154 ;
V_46 -> V_90 = V_160 . V_175 . V_189 ;
}
if ( V_160 . V_175 . V_176 & V_191 ) {
if ( V_160 . V_175 . V_115 > V_192 )
return - V_154 ;
V_46 -> V_115 = V_160 . V_175 . V_115 ;
}
if ( V_160 . V_175 . V_176 & V_193 ) {
if ( V_160 . V_175 . V_194 > V_195 )
return - V_154 ;
V_46 -> V_99 = V_160 . V_175 . V_194 ;
}
if ( V_160 . V_175 . V_176 & V_196 ) {
if ( V_160 . V_175 . V_197 > V_198 )
return - V_154 ;
V_46 -> V_98 = V_160 . V_175 . V_197 ;
V_46 -> V_97 = V_46 -> V_98 / 10 ;
}
break;
case V_199 :
V_160 . V_175 . V_176 = 0xffffffff ;
V_160 . V_175 . V_5 = V_46 -> V_5 ;
V_160 . V_175 . V_118 = V_46 -> V_118 ;
V_160 . V_175 . V_17 = V_46 -> V_17 ;
V_160 . V_175 . V_48 = V_46 -> V_48 ;
V_160 . V_175 . V_183 = V_46 -> V_96 ;
V_160 . V_175 . V_189 = V_46 -> V_90 ;
V_160 . V_175 . V_186 = V_46 -> V_116 ;
V_160 . V_175 . V_115 = V_46 -> V_115 ;
V_160 . V_175 . V_194 = V_46 -> V_99 ;
V_160 . V_175 . V_197 = V_46 -> V_98 ;
if ( F_77 ( V_157 -> V_164 , & V_160 , sizeof( struct V_159 ) ) )
return - V_165 ;
break;
default:
return - V_154 ;
}
return 0 ;
}
static int F_78 ( struct V_44 * V_32 , void * V_200 )
{
struct V_201 * V_202 = (struct V_201 * ) V_200 ;
memcpy ( V_32 -> V_203 , V_202 -> V_204 , V_32 -> V_205 ) ;
return 0 ;
}
static void F_79 ( struct V_44 * V_32 )
{
struct V_45 * V_46 = F_28 ( V_32 ) ;
V_46 -> V_93 = V_94 ;
V_46 -> V_17 = V_206 ;
V_46 -> V_48 = V_206 * 2 ;
V_46 -> V_5 = 0 ;
V_46 -> V_118 = 0 ;
V_46 -> V_96 = 0 ;
V_46 -> V_116 = V_207 ;
V_46 -> V_90 = V_208 ;
V_46 -> V_115 = V_209 ;
V_46 -> V_98 = V_210 ;
V_46 -> V_99 = V_211 ;
V_46 -> V_32 = V_32 ;
V_32 -> V_49 = V_46 -> V_5 ;
V_32 -> V_118 = V_46 -> V_118 ;
F_80 ( & V_46 -> V_85 ) ;
V_32 -> V_212 = & V_213 ;
V_32 -> V_214 = & V_215 ;
V_32 -> type = V_216 ;
V_32 -> V_217 = V_218 ;
V_32 -> V_219 = V_220 ;
V_32 -> V_205 = V_221 ;
memcpy ( V_32 -> V_222 , & V_223 , V_221 ) ;
memcpy ( V_32 -> V_203 , & V_224 , V_221 ) ;
}
static int T_4 F_81 ( void )
{
struct V_44 * V_32 ;
int V_40 , V_28 ;
char V_73 [ V_225 ] ;
F_20 ( V_226 ) ;
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
sprintf ( V_73 , L_35 , V_40 ) ;
V_32 = F_82 ( sizeof( struct V_45 ) , V_73 ,
F_79 ) ;
if ( ! V_32 ) {
F_83 ( L_36 ) ;
V_28 = - V_227 ;
goto error;
}
V_28 = F_84 ( V_32 ) ;
if ( V_28 ) {
F_20 ( V_72 L_37 , V_32 -> V_73 ) ;
goto error;
}
V_102 [ V_40 ] = V_32 ;
}
V_103 . V_228 = F_48 ;
V_103 . V_104 = V_3 + V_4 / 100 ;
F_50 ( & V_103 ) ;
F_85 ( L_1 , V_229 , V_230 . V_231 , & V_232 ) ;
return 0 ;
error:
while ( -- V_40 >= 0 ) {
F_86 ( V_102 [ V_40 ] ) ;
F_87 ( V_102 [ V_40 ] ) ;
}
return V_28 ;
}
static void T_5 F_88 ( void )
{
struct V_26 * V_27 ;
int V_40 ;
F_89 ( & V_103 ) ;
for ( V_40 = 0 ; V_40 < V_101 ; V_40 ++ ) {
struct V_44 * V_32 = V_102 [ V_40 ] ;
if ( V_32 ) {
F_86 ( V_32 ) ;
F_87 ( V_32 ) ;
}
}
while ( V_36 ) {
V_27 = V_36 ;
V_36 = V_36 -> V_38 ;
F_76 ( V_27 ) ;
}
F_90 ( L_1 , V_230 . V_231 ) ;
}
