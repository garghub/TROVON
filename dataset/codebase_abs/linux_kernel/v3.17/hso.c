static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_5 ;
}
static inline struct V_6 * F_2 ( struct V_2 * V_3 )
{
return V_3 -> V_4 . V_7 ;
}
static void F_3 ( int V_8 , const char * V_9 , unsigned char * V_10 ,
unsigned int V_11 )
{
static char V_12 [ 255 ] ;
sprintf ( V_12 , L_1 , V_8 , V_9 ) ;
F_4 ( V_12 , V_13 , V_10 , V_11 ) ;
}
static T_1 F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_10 )
{
struct V_2 * V_3 = F_6 ( V_15 ) ;
char * V_18 ;
if ( ! V_3 )
return 0 ;
switch ( V_3 -> V_19 & V_20 ) {
case V_21 :
V_18 = L_2 ;
break;
case V_22 :
V_18 = L_3 ;
break;
case V_23 :
V_18 = L_4 ;
break;
case V_24 :
V_18 = L_5 ;
break;
case V_25 :
V_18 = L_6 ;
break;
case V_26 :
V_18 = L_7 ;
break;
case V_27 :
V_18 = L_8 ;
break;
case V_28 :
V_18 = L_9 ;
break;
case V_29 :
V_18 = L_10 ;
break;
case V_30 :
V_18 = L_11 ;
break;
default:
V_18 = L_12 ;
break;
}
return sprintf ( V_10 , L_13 , V_18 ) ;
}
static int F_7 ( struct V_6 * V_31 , struct V_32 * V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_34 ; V_33 ++ )
if ( V_31 -> V_35 [ V_33 ] == V_32 )
return V_33 ;
F_8 ( V_31 -> V_36 -> V_15 , L_14 ) ;
return - 1 ;
}
static T_2 F_9 ( int V_37 )
{
T_2 V_38 ;
switch ( V_37 ) {
case 0x1 :
V_38 = V_21 ;
break;
case 0x2 :
V_38 = V_22 ;
break;
case 0x4 :
V_38 = V_26 ;
break;
case 0x8 :
V_38 = V_24 ;
break;
case 0x10 :
V_38 = V_23 ;
break;
default:
V_38 = V_39 ;
}
return V_38 ;
}
static T_2 F_10 ( int V_40 )
{
T_2 V_38 ;
switch ( V_40 & V_20 ) {
case V_21 :
V_38 = 0x0 ;
break;
case V_22 :
V_38 = 0x1 ;
break;
case V_26 :
V_38 = 0x2 ;
break;
case V_24 :
V_38 = 0x3 ;
break;
case V_23 :
V_38 = 0x4 ;
break;
default:
V_38 = 0x0 ;
}
return V_38 ;
}
static struct V_6 * F_11 (
struct V_41 * V_42 ,
int V_37 )
{
int V_43 , V_40 ;
V_40 = F_9 ( V_37 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] &&
( F_2 ( V_45 [ V_43 ] ) -> V_42 == V_42 ) &&
( ( V_45 [ V_43 ] -> V_19 & V_20 ) == V_40 ) ) {
return F_2 ( V_45 [ V_43 ] ) ;
}
}
return NULL ;
}
static struct V_6 * F_12 ( unsigned V_46 )
{
struct V_6 * V_31 = NULL ;
unsigned long V_47 ;
F_13 ( & V_48 , V_47 ) ;
if ( V_45 [ V_46 ] )
V_31 = F_2 ( V_45 [ V_46 ] ) ;
F_14 ( & V_48 , V_47 ) ;
return V_31 ;
}
static int F_15 ( void )
{
int V_46 ;
unsigned long V_47 ;
F_13 ( & V_48 , V_47 ) ;
for ( V_46 = 0 ; V_46 < V_44 ; V_46 ++ ) {
if ( V_45 [ V_46 ] == NULL ) {
F_14 ( & V_48 , V_47 ) ;
return V_46 ;
}
}
F_14 ( & V_48 , V_47 ) ;
F_16 ( V_49 L_15 , V_50 ) ;
return - 1 ;
}
static void F_17 ( unsigned V_46 , struct V_6 * V_31 )
{
unsigned long V_47 ;
F_13 ( & V_48 , V_47 ) ;
if ( V_31 )
V_45 [ V_46 ] = V_31 -> V_36 ;
else
V_45 [ V_46 ] = NULL ;
F_14 ( & V_48 , V_47 ) ;
}
static void F_18 ( int V_51 , const char * V_52 ,
struct V_2 * V_3 )
{
char * V_53 ;
switch ( V_51 ) {
case - V_54 :
V_53 = L_16 ;
break;
case - V_55 :
V_53 = L_17 ;
break;
case - V_56 :
V_53 = L_18 ;
break;
case - V_57 :
V_53 = L_19 ;
break;
case - V_58 :
V_53 = L_20 ;
break;
case - V_59 :
V_53 = L_21 ;
break;
case - V_60 :
case - V_61 :
case - V_62 :
case - V_63 :
V_53 = L_22 ;
break;
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
V_53 = L_23 ;
if ( V_3 )
F_19 ( & V_3 -> V_68 ) ;
break;
default:
V_53 = L_24 ;
break;
}
F_20 ( L_25 , V_52 , V_53 , V_51 ) ;
}
static int F_21 ( struct V_69 * V_70 )
{
struct V_1 * V_71 = F_22 ( V_70 ) ;
unsigned long V_47 = 0 ;
if ( ! V_71 ) {
F_8 ( & V_70 -> V_15 , L_26 ) ;
return - V_54 ;
}
V_71 -> V_72 = NULL ;
F_13 ( & V_71 -> V_73 , V_47 ) ;
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = sizeof( struct V_78 ) ;
F_14 ( & V_71 -> V_73 , V_47 ) ;
F_23 ( V_79 , & V_71 -> V_47 ) ;
F_24 ( V_71 -> V_36 ) ;
F_25 ( V_70 ) ;
return 0 ;
}
static int F_26 ( struct V_69 * V_70 )
{
struct V_1 * V_71 = F_22 ( V_70 ) ;
F_27 ( V_70 ) ;
F_28 ( V_79 , & V_71 -> V_47 ) ;
F_29 ( V_71 -> V_36 ) ;
return 0 ;
}
static void F_30 ( struct V_32 * V_32 )
{
struct V_1 * V_71 = V_32 -> V_80 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_71 || ! F_31 ( V_79 , & V_71 -> V_47 ) ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_27 , V_50 ) ;
return;
}
if ( ! F_32 ( V_71 -> V_70 ) ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_28 ,
V_50 ) ;
return;
}
if ( V_51 )
F_18 ( V_51 , V_50 , V_71 -> V_36 ) ;
F_33 ( V_71 -> V_36 ) ;
F_34 ( V_71 -> V_70 ) ;
}
static T_3 F_35 ( struct V_81 * V_82 ,
struct V_69 * V_70 )
{
struct V_1 * V_71 = F_22 ( V_70 ) ;
int V_38 ;
F_27 ( V_70 ) ;
if ( F_36 ( V_71 -> V_36 ) == - V_61 ) {
V_71 -> V_72 = V_82 ;
return V_83 ;
}
F_37 ( V_82 -> V_84 , V_82 -> V_11 ) ;
memcpy ( V_71 -> V_85 , V_82 -> V_84 , V_82 -> V_11 ) ;
F_20 ( L_29 , V_82 -> V_11 , V_86 ) ;
F_38 ( V_71 -> V_87 ,
V_71 -> V_36 -> V_88 ,
F_39 ( V_71 -> V_36 -> V_88 ,
V_71 -> V_89 ->
V_90 & 0x7F ) ,
V_71 -> V_85 , V_82 -> V_11 , F_30 ,
V_71 ) ;
V_71 -> V_87 -> V_91 |= V_92 ;
V_38 = F_40 ( V_71 -> V_87 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_71 -> V_36 -> V_94 -> V_15 ,
L_30 , V_38 ) ;
V_70 -> V_95 . V_96 ++ ;
F_25 ( V_70 ) ;
} else {
V_70 -> V_95 . V_97 ++ ;
V_70 -> V_95 . V_98 += V_82 -> V_11 ;
}
F_42 ( V_82 ) ;
return V_83 ;
}
static void F_43 ( struct V_69 * V_70 )
{
struct V_1 * V_71 = F_22 ( V_70 ) ;
if ( ! V_71 )
return;
F_41 ( & V_70 -> V_15 , L_31 ) ;
if ( V_71 -> V_87 &&
( V_71 -> V_87 -> V_51 == - V_99 ) )
F_44 ( V_71 -> V_87 ) ;
V_70 -> V_95 . V_96 ++ ;
}
static void F_45 ( struct V_1 * V_71 , unsigned char * V_100 ,
unsigned int V_101 , unsigned char V_102 )
{
unsigned short V_103 ;
unsigned short V_104 = 0 ;
unsigned short V_105 ;
unsigned char * V_106 ;
F_20 ( L_32 , V_101 ) ;
F_46 ( V_100 , F_47 ( 128 , ( int ) V_101 ) ) ;
while ( V_101 ) {
switch ( V_71 -> V_74 ) {
case V_75 :
V_103 =
( V_101 <
V_71 -> V_77 ) ? V_101 : V_71 ->
V_77 ;
memcpy ( ( ( unsigned char * ) ( & V_71 -> V_107 ) ) +
V_71 -> V_76 , V_100 + V_104 ,
V_103 ) ;
V_71 -> V_76 += V_103 ;
V_104 += V_103 ;
V_71 -> V_77 -= V_103 ;
V_101 -= V_103 ;
if ( ! V_71 -> V_77 ) {
V_105 = F_48 ( V_71 -> V_107 . V_108 ) ;
if ( ( V_105 > V_109 ) ||
( V_105 < sizeof( struct V_78 ) ) ) {
F_8 ( & V_71 -> V_70 -> V_15 ,
L_33 ,
V_105 ) ;
V_71 -> V_74 = V_110 ;
continue;
}
V_71 -> V_111 = F_49 ( V_71 -> V_70 ,
V_105 ) ;
if ( ! V_71 -> V_111 ) {
F_20 ( L_34 ) ;
V_71 -> V_74 = V_110 ;
return;
}
V_106 =
F_50 ( V_71 -> V_111 ,
sizeof( struct V_78 ) ) ;
memcpy ( V_106 , ( char * ) & ( V_71 -> V_107 ) ,
sizeof( struct V_78 ) ) ;
V_71 -> V_76 = sizeof( struct V_78 ) ;
V_71 -> V_77 =
V_105 - sizeof( struct V_78 ) ;
V_71 -> V_74 = V_112 ;
}
break;
case V_112 :
V_103 = ( V_101 < V_71 -> V_77 )
? V_101 : V_71 -> V_77 ;
V_106 = F_50 ( V_71 -> V_111 , V_103 ) ;
memcpy ( V_106 , V_100 + V_104 , V_103 ) ;
V_71 -> V_77 -= V_103 ;
V_101 -= V_103 ;
V_104 += V_103 ;
V_71 -> V_76 += V_103 ;
if ( ! V_71 -> V_77 ) {
V_71 -> V_111 -> V_113 = F_51 ( V_114 ) ;
F_52 ( V_71 -> V_111 ) ;
F_53 ( V_71 -> V_111 ) ;
V_71 -> V_111 = NULL ;
V_71 -> V_70 -> V_95 . V_115 ++ ;
V_71 -> V_70 -> V_95 . V_116 += V_71 -> V_76 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = sizeof( struct V_78 ) ;
V_71 -> V_74 = V_75 ;
}
break;
case V_110 :
F_20 ( L_35 ) ;
V_101 = 0 ;
break;
default:
F_20 ( L_36 ) ;
V_101 -- ;
break;
}
}
if ( V_102 ) {
if ( V_71 -> V_74 == V_110 ) {
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = sizeof( struct V_78 ) ;
}
}
}
static void F_54 ( struct V_32 * V_32 , T_4 V_117 )
{
static const T_5 V_118 [ 4 ] = { 0xDE , 0xAD , 0xBE , 0xEF } ;
T_2 V_119 = V_32 -> V_120 % F_55 ( V_117 ) ;
if ( ( ( V_119 == 5 ) || ( V_119 == 6 ) ) &&
! memcmp ( ( ( T_5 * ) V_32 -> V_121 ) + V_32 -> V_120 - 4 ,
V_118 , 4 ) ) {
V_32 -> V_120 -= 4 ;
}
}
static void F_56 ( struct V_32 * V_32 )
{
struct V_1 * V_71 = V_32 -> V_80 ;
struct V_69 * V_70 ;
int V_38 ;
int V_51 = V_32 -> V_51 ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_71 -> V_36 ) ;
return;
}
if ( ! V_71 || ! F_31 ( V_79 , & V_71 -> V_47 ) ) {
F_20 ( L_37 ) ;
return;
}
F_57 ( V_32 -> V_15 ) ;
V_70 = V_71 -> V_70 ;
if ( ! F_32 ( V_70 ) ) {
return;
}
if ( V_71 -> V_36 -> V_19 & V_122 )
F_54 ( V_32 , V_71 -> V_123 -> V_124 ) ;
if ( V_32 -> V_120 ) {
F_58 ( & V_71 -> V_73 ) ;
F_45 ( V_71 , V_32 -> V_121 , V_32 -> V_120 ,
( V_32 -> V_125 >
V_32 -> V_120 ) ? 1 : 0 ) ;
F_59 ( & V_71 -> V_73 ) ;
}
F_38 ( V_32 ,
V_71 -> V_36 -> V_88 ,
F_60 ( V_71 -> V_36 -> V_88 ,
V_71 -> V_123 ->
V_90 & 0x7F ) ,
V_32 -> V_121 , V_126 ,
F_56 , V_71 ) ;
V_38 = F_40 ( V_32 , V_93 ) ;
if ( V_38 )
F_41 ( & V_71 -> V_36 -> V_94 -> V_15 ,
L_38 , V_50 ,
V_38 ) ;
}
static void F_61 ( struct V_127 * V_128 )
{
V_128 -> V_129 &=
~ ( V_130
| V_131
| V_132
| V_133
| V_134
| V_135
| V_136
| V_137 ) ;
V_128 -> V_138 &= ~ V_139 ;
V_128 -> V_140 &=
~ ( V_141
| V_142
| V_143
| V_144
| V_145 ) ;
V_128 -> V_146 &=
~ ( V_147
| V_148
| V_149
| V_150 ) ;
V_128 -> V_146 |= V_151 ;
F_62 ( V_128 , 115200 , 115200 ) ;
}
static void F_63 ( struct V_152 * V_153 ,
struct V_127 * V_154 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
if ( ! V_31 ) {
F_16 ( V_49 L_39 , V_50 ) ;
return;
}
F_64 ( L_40 , V_31 -> V_156 ) ;
V_153 -> V_128 . V_129 &= ~ V_137 ;
V_153 -> V_128 . V_146 &=
~ ( V_147
| V_148
| V_149
| V_150 ) ;
V_153 -> V_128 . V_146 |= V_151 ;
F_65 ( V_153 , 115200 , 115200 ) ;
}
static void F_66 ( struct V_6 * V_31 , struct V_32 * V_32 )
{
int V_38 ;
F_38 ( V_32 , V_31 -> V_36 -> V_88 ,
F_60 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_123 ->
V_90 & 0x7F ) ,
V_32 -> V_121 , V_31 -> V_157 ,
V_158 , V_31 ) ;
V_38 = F_40 ( V_32 , V_93 ) ;
if ( V_38 ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_41 ,
V_50 , V_38 ) ;
}
}
static void F_67 ( struct V_6 * V_31 )
{
int V_101 ;
struct V_32 * V_159 ;
while ( V_31 -> V_160 [ V_31 -> V_161 ] ) {
V_159 = V_31 -> V_35 [ V_31 -> V_161 ] ;
V_101 = F_68 ( V_159 , V_31 ) ;
if ( V_101 == - 1 )
return;
if ( V_101 == 0 ) {
V_31 -> V_161 ++ ;
if ( V_31 -> V_161 >= V_31 -> V_34 )
V_31 -> V_161 = 0 ;
F_66 ( V_31 , V_159 ) ;
}
}
}
static void F_69 ( struct V_6 * V_31 )
{
int V_101 = 0 ;
struct V_32 * V_32 ;
V_32 = V_31 -> V_35 [ 0 ] ;
if ( V_31 -> V_40 . V_101 > 0 ) {
V_101 = F_68 ( V_32 , V_31 ) ;
if ( V_101 == - 1 )
return;
}
if ( V_101 == 0 && ( ( V_32 -> V_120 != 0 ) ||
( V_31 -> V_162 == V_163 ) ) ) {
V_31 -> V_162 = V_164 ;
F_70 ( V_31 ) ;
} else
V_31 -> V_162 = V_165 ;
}
static void V_158 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
int V_51 = V_32 -> V_51 ;
F_64 ( L_42 , V_51 ) ;
if ( ! V_31 ) {
F_20 ( L_43 ) ;
return;
}
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
F_20 ( L_44 , V_32 -> V_120 ) ;
F_37 ( V_32 -> V_121 , V_32 -> V_120 ) ;
if ( V_31 -> V_40 . V_101 == 0 )
return;
if ( V_31 -> V_36 -> V_19 & V_122 )
F_54 ( V_32 , V_31 -> V_123 -> V_124 ) ;
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_160 [ F_7 ( V_31 , V_32 ) ] = 1 ;
F_67 ( V_31 ) ;
F_59 ( & V_31 -> V_166 ) ;
}
static void F_71 ( struct V_6 * V_31 )
{
unsigned long V_47 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( ( V_31 -> V_36 -> V_19 & V_167 ) )
F_69 ( V_31 ) ;
else
F_67 ( V_31 ) ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static void F_72 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
F_73 ( & V_31 -> V_168 ) ;
}
static int F_74 ( struct V_152 * V_153 , struct V_169 * V_170 )
{
struct V_6 * V_31 = F_12 ( V_153 -> V_46 ) ;
int V_38 ;
if ( V_31 == NULL || V_31 -> V_171 != V_172 ) {
F_75 ( 1 ) ;
V_153 -> V_155 = NULL ;
F_20 ( L_45 ) ;
return - V_54 ;
}
F_76 ( & V_31 -> V_36 -> V_173 ) ;
V_38 = F_77 ( V_31 -> V_36 -> V_94 ) ;
if ( V_38 < 0 )
goto V_174;
F_20 ( L_46 , V_31 -> V_156 ) ;
F_78 ( & V_31 -> V_36 -> V_175 ) ;
V_153 -> V_155 = V_31 ;
F_79 ( & V_31 -> V_40 , V_153 ) ;
V_31 -> V_40 . V_101 ++ ;
if ( V_31 -> V_40 . V_101 == 1 ) {
V_31 -> V_162 = V_165 ;
F_63 ( V_153 , NULL ) ;
F_80 ( & V_31 -> V_168 ,
( void (*) ( unsigned long ) ) F_71 ,
( unsigned long ) V_31 ) ;
V_38 = F_81 ( V_31 -> V_36 , V_176 ) ;
if ( V_38 ) {
F_82 ( V_31 -> V_36 ) ;
V_31 -> V_40 . V_101 -- ;
F_83 ( & V_31 -> V_36 -> V_175 , V_177 ) ;
}
} else {
F_20 ( L_47 ) ;
}
F_84 ( V_31 -> V_36 -> V_94 ) ;
if ( V_38 )
F_85 ( V_153 , V_178 | V_179 , 0 ) ;
V_174:
F_86 ( & V_31 -> V_36 -> V_173 ) ;
return V_38 ;
}
static void F_87 ( struct V_152 * V_153 , struct V_169 * V_170 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
T_5 V_180 ;
F_20 ( L_48 ) ;
if ( V_31 == NULL )
return;
F_76 ( & V_31 -> V_36 -> V_173 ) ;
V_180 = V_31 -> V_36 -> V_180 ;
if ( ! V_180 )
F_77 ( V_31 -> V_36 -> V_94 ) ;
V_31 -> V_40 . V_101 -- ;
if ( V_31 -> V_40 . V_101 <= 0 ) {
V_31 -> V_40 . V_101 = 0 ;
F_79 ( & V_31 -> V_40 , NULL ) ;
if ( ! V_180 )
F_82 ( V_31 -> V_36 ) ;
F_88 ( & V_31 -> V_168 ) ;
}
if ( ! V_180 )
F_84 ( V_31 -> V_36 -> V_94 ) ;
F_86 ( & V_31 -> V_36 -> V_173 ) ;
F_83 ( & V_31 -> V_36 -> V_175 , V_177 ) ;
}
static int F_89 ( struct V_152 * V_153 , const unsigned char * V_10 ,
int V_101 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_181 , V_98 ;
unsigned long V_47 ;
if ( V_31 == NULL ) {
F_16 ( V_49 L_49 , V_50 ) ;
return - V_54 ;
}
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_181 = V_31 -> V_182 - V_31 -> V_183 ;
V_98 = ( V_101 < V_181 ) ? V_101 : V_181 ;
if ( ! V_98 )
goto V_184;
memcpy ( V_31 -> V_185 + V_31 -> V_183 , V_10 , V_98 ) ;
V_31 -> V_183 += V_98 ;
V_184:
F_14 ( & V_31 -> V_166 , V_47 ) ;
F_90 ( V_31 ) ;
return V_98 ;
}
static int F_91 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_186 ;
unsigned long V_47 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_186 = V_31 -> V_182 - V_31 -> V_183 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return V_186 ;
}
static void F_92 ( struct V_152 * V_153 , struct V_127 * V_154 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
unsigned long V_47 ;
if ( V_154 )
F_93 ( L_50 ,
V_153 -> V_128 . V_146 , V_154 -> V_146 ) ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( V_31 -> V_40 . V_101 )
F_63 ( V_153 , V_154 ) ;
else
V_153 -> V_128 = * V_154 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static int F_94 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_187 ;
unsigned long V_47 ;
if ( V_31 == NULL )
return 0 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_187 = V_31 -> V_183 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return V_187 ;
}
static int F_95 ( struct V_6 * V_31 ,
struct V_188 * V_189 ,
struct V_190 * V_88 )
{
int V_38 ;
if ( V_31 -> V_36 -> V_180 )
return - V_54 ;
F_96 ( V_189 -> V_32 , V_88 ,
F_97 ( V_88 ,
V_189 -> V_191 ->
V_90 & 0x7F ) ,
& V_189 -> V_192 ,
sizeof( struct V_193 ) ,
V_194 , V_31 ,
V_189 -> V_191 -> V_195 ) ;
V_38 = F_40 ( V_189 -> V_32 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_88 -> V_15 , L_51 , V_50 ,
V_38 ) ;
}
return V_38 ;
}
static void V_194 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_188 * V_189 ;
int V_51 = V_32 -> V_51 ;
T_6 V_196 , V_197 ;
struct V_198 * V_199 ;
struct V_193 * V_192 ;
struct V_190 * V_88 ;
int V_200 ;
if ( ! V_31 )
return;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_189 = V_31 -> V_189 ;
if ( ! V_189 )
return;
F_98 ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 ) ;
V_88 = V_31 -> V_36 -> V_88 ;
V_200 = V_31 -> V_36 -> V_94 -> V_201 -> V_202 . V_203 ;
V_192 = & V_189 -> V_192 ;
if ( V_192 -> V_204 != V_205 ||
V_192 -> V_206 != V_207 ||
F_55 ( V_192 -> V_208 ) != V_209 ||
F_55 ( V_192 -> V_210 ) != V_200 ||
F_55 ( V_192 -> V_211 ) != V_212 ) {
F_41 ( & V_88 -> V_15 ,
L_52 ) ;
F_46 ( V_192 ,
sizeof( struct V_193 ) ) ;
} else {
V_196 = F_55 ( V_192 ->
V_196 ) ;
V_197 = V_189 -> V_197 ;
V_199 = & V_189 -> V_199 ;
F_58 ( & V_31 -> V_166 ) ;
if ( ( V_196 & V_213 ) !=
( V_197 & V_213 ) )
V_199 -> V_214 ++ ;
if ( ( V_196 & V_215 ) !=
( V_197 & V_215 ) )
V_199 -> V_214 ++ ;
if ( ( V_196 & V_216 ) !=
( V_197 & V_216 ) )
V_199 -> V_217 ++ ;
if ( ( V_196 & V_218 ) &&
! ( V_197 & V_218 ) )
V_199 -> V_219 ++ ;
if ( ( V_196 & V_220 ) !=
( V_197 & V_220 ) )
V_199 -> V_221 ++ ;
if ( ( V_196 & V_222 ) !=
( V_197 & V_222 ) )
V_199 -> V_223 ++ ;
if ( ( V_196 & V_224 ) !=
( V_197 & V_224 ) )
V_199 -> V_225 ++ ;
V_189 -> V_197 = V_196 ;
F_59 ( & V_31 -> V_166 ) ;
V_189 -> V_226 = 1 ;
F_99 ( & V_189 -> V_227 ) ;
}
memset ( V_192 , 0 ,
sizeof( struct V_193 ) ) ;
F_95 ( V_31 ,
V_189 ,
V_31 -> V_36 -> V_88 ) ;
}
static int
F_100 ( struct V_6 * V_31 , unsigned long V_228 )
{
F_101 ( V_229 , V_230 ) ;
struct V_198 V_231 , V_232 ;
struct V_188 * V_189 ;
int V_233 ;
V_189 = V_31 -> V_189 ;
if ( ! V_189 )
return - V_55 ;
F_102 ( & V_31 -> V_166 ) ;
memcpy ( & V_231 , & V_189 -> V_199 , sizeof( struct V_198 ) ) ;
F_103 ( & V_31 -> V_166 ) ;
F_104 ( & V_189 -> V_227 , & V_229 ) ;
for (; ; ) {
F_102 ( & V_31 -> V_166 ) ;
memcpy ( & V_232 , & V_189 -> V_199 , sizeof( struct V_198 ) ) ;
F_103 ( & V_31 -> V_166 ) ;
F_105 ( V_234 ) ;
if ( ( ( V_228 & V_235 ) && ( V_232 . V_219 != V_231 . V_219 ) ) ||
( ( V_228 & V_236 ) && ( V_232 . V_223 != V_231 . V_223 ) ) ||
( ( V_228 & V_237 ) && ( V_232 . V_225 != V_231 . V_225 ) ) ) {
V_233 = 0 ;
break;
}
F_106 () ;
if ( F_107 ( V_230 ) ) {
V_233 = - V_238 ;
break;
}
V_231 = V_232 ;
}
V_230 -> V_239 = V_240 ;
F_108 ( & V_189 -> V_227 , & V_229 ) ;
return V_233 ;
}
static int F_109 ( struct V_152 * V_153 ,
struct V_241 * V_199 )
{
struct V_198 V_232 ;
struct V_6 * V_31 = V_153 -> V_155 ;
struct V_188 * V_189 = V_31 -> V_189 ;
memset ( V_199 , 0 , sizeof( struct V_241 ) ) ;
if ( ! V_189 )
return - V_55 ;
F_102 ( & V_31 -> V_166 ) ;
memcpy ( & V_232 , & V_189 -> V_199 , sizeof( struct V_198 ) ) ;
F_103 ( & V_31 -> V_166 ) ;
V_199 -> V_242 = V_232 . V_242 ;
V_199 -> V_223 = V_232 . V_223 ;
V_199 -> V_219 = V_232 . V_219 ;
V_199 -> V_225 = V_232 . V_225 ;
V_199 -> V_243 = V_232 . V_243 ;
V_199 -> V_244 = V_232 . V_244 ;
V_199 -> V_217 = V_232 . V_217 ;
V_199 -> V_245 = V_232 . V_245 ;
V_199 -> V_214 = V_232 . V_214 ;
V_199 -> V_221 = V_232 . V_221 ;
V_199 -> V_246 = V_232 . V_246 ;
return 0 ;
}
static int F_110 ( struct V_152 * V_153 )
{
int V_247 ;
struct V_6 * V_31 = V_153 -> V_155 ;
struct V_188 * V_189 ;
T_6 V_196 ;
if ( ! V_31 ) {
F_20 ( L_53 ) ;
return - V_60 ;
}
F_102 ( & V_31 -> V_166 ) ;
V_247 = ( ( V_31 -> V_248 ) ? V_178 : 0 ) |
( ( V_31 -> V_249 ) ? V_179 : 0 ) ;
V_189 = V_31 -> V_189 ;
if ( V_189 ) {
V_196 = F_55 (
V_189 -> V_197 ) ;
if ( V_196 & V_218 )
V_247 |= V_235 ;
if ( V_196 & V_224 )
V_247 |= V_237 ;
if ( V_196 & V_222 )
V_247 |= V_236 ;
}
F_103 ( & V_31 -> V_166 ) ;
return V_247 ;
}
static int F_85 ( struct V_152 * V_153 ,
unsigned int V_250 , unsigned int V_251 )
{
int V_252 = 0 ;
unsigned long V_47 ;
int V_200 ;
struct V_6 * V_31 = V_153 -> V_155 ;
if ( ! V_31 ) {
F_20 ( L_53 ) ;
return - V_60 ;
}
if ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 )
return - V_60 ;
V_200 = V_31 -> V_36 -> V_94 -> V_201 -> V_202 . V_203 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( V_250 & V_178 )
V_31 -> V_248 = 1 ;
if ( V_250 & V_179 )
V_31 -> V_249 = 1 ;
if ( V_251 & V_178 )
V_31 -> V_248 = 0 ;
if ( V_251 & V_179 )
V_31 -> V_249 = 0 ;
if ( V_31 -> V_249 )
V_252 |= 0x01 ;
if ( V_31 -> V_248 )
V_252 |= 0x02 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return F_111 ( V_31 -> V_36 -> V_88 ,
F_112 ( V_31 -> V_36 -> V_88 , 0 ) , 0x22 ,
0x21 , V_252 , V_200 , NULL , 0 ,
V_253 ) ;
}
static int F_113 ( struct V_152 * V_153 ,
unsigned int V_254 , unsigned long V_228 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_233 = 0 ;
F_64 ( L_54 , V_254 , V_228 ) ;
if ( ! V_31 )
return - V_54 ;
switch ( V_254 ) {
case V_255 :
V_233 = F_100 ( V_31 , V_228 ) ;
break;
default:
V_233 = - V_256 ;
break;
}
return V_233 ;
}
static void F_90 ( struct V_6 * V_31 )
{
T_5 * V_257 ;
unsigned long V_47 ;
int V_258 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( ! V_31 -> V_183 )
goto V_184;
if ( V_31 -> V_259 )
goto V_184;
if ( F_36 ( V_31 -> V_36 ) == - V_61 )
goto V_184;
V_257 = V_31 -> V_185 ;
V_31 -> V_185 = V_31 -> V_260 ;
V_31 -> V_260 = V_257 ;
V_31 -> V_261 = V_31 -> V_183 ;
V_31 -> V_183 = 0 ;
if ( V_257 && V_31 -> V_262 ) {
V_258 = V_31 -> V_262 ( V_31 ) ;
if ( V_258 >= 0 )
V_31 -> V_259 = 1 ;
}
V_184:
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static int F_114 ( struct V_6 * V_31 , T_5 type , T_6 V_40 ,
struct V_32 * V_263 ,
struct V_264 * V_265 ,
T_5 * V_266 , T_2 V_267 )
{
int V_38 ;
int V_268 ;
if ( ! V_31 || ! V_263 || ! V_265 ) {
F_16 ( V_49 L_55 , V_50 ) ;
return - V_60 ;
}
V_265 -> V_208 = 0 ;
V_265 -> V_210 = F_115 ( F_10 ( V_40 ) ) ;
V_265 -> V_211 = F_115 ( V_267 ) ;
if ( type == V_269 ) {
V_265 -> V_270 = V_271 |
V_272 |
V_273 ;
V_265 -> V_274 = V_269 ;
V_268 = F_112 ( V_31 -> V_36 -> V_88 , 0 ) ;
} else {
V_265 -> V_270 = V_275 |
V_272 |
V_273 ;
V_265 -> V_274 = V_276 ;
V_268 = F_116 ( V_31 -> V_36 -> V_88 , 0 ) ;
}
F_117 ( L_56 ,
type == V_269 ? L_57 : L_58 ,
V_265 -> V_270 , V_265 -> V_211 , V_40 ) ;
V_263 -> V_91 = 0 ;
F_118 ( V_263 ,
V_31 -> V_36 -> V_88 ,
V_268 ,
( T_5 * ) V_265 ,
V_266 , V_267 , V_277 , V_31 ) ;
V_38 = F_40 ( V_263 , V_93 ) ;
if ( V_38 ) {
F_8 ( & V_263 -> V_15 -> V_15 ,
L_59 , V_50 ,
V_38 , type ) ;
return V_38 ;
}
return V_267 ;
}
static int F_70 ( struct V_6 * V_31 )
{
if ( ! V_31 )
return - V_60 ;
memset ( V_31 -> V_278 [ 0 ] , 0 , V_279 ) ;
if ( V_31 -> V_34 != 1 ) {
F_8 ( & V_31 -> V_36 -> V_94 -> V_15 ,
L_60
L_61 ) ;
return 0 ;
}
return F_114 ( V_31 ,
V_269 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_35 [ 0 ] ,
& V_31 -> V_280 ,
V_31 -> V_278 [ 0 ] , V_31 -> V_157 ) ;
}
static void F_119 ( struct V_32 * V_32 )
{
struct V_41 * V_42 = V_32 -> V_80 ;
struct V_6 * V_31 ;
unsigned char * V_281 ;
int V_51 = V_32 -> V_51 ;
int V_43 ;
F_57 ( V_32 -> V_15 ) ;
if ( ! V_42 )
return;
if ( V_51 ) {
F_18 ( V_51 , V_50 , NULL ) ;
return;
}
F_64 ( L_62 , V_51 ) ;
V_281 = V_32 -> V_121 ;
F_64 ( L_63 , * V_281 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( * V_281 & ( 1 << V_43 ) ) {
V_31 = F_11 ( V_42 ,
( 1 << V_43 ) ) ;
if ( V_31 != NULL ) {
F_20 ( L_64 , V_43 ) ;
F_58 ( & V_31 -> V_166 ) ;
if ( V_31 -> V_162 == V_165 &&
V_31 -> V_40 . V_101 > 0 ) {
if ( ! V_31 -> V_160 [ 0 ] ) {
V_31 -> V_162 = V_164 ;
F_70 ( V_31 ) ;
} else
V_31 -> V_162 = V_163 ;
} else {
F_20 ( L_65
L_66 , V_43 ) ;
}
F_59 ( & V_31 -> V_166 ) ;
}
}
}
F_120 ( V_42 , V_32 -> V_15 , V_93 ) ;
}
static int F_121 ( struct V_6 * V_31 )
{
if ( NULL == V_31 )
return - V_60 ;
return F_114 ( V_31 ,
V_276 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_282 ,
& V_31 -> V_283 ,
V_31 -> V_260 , V_31 -> V_261 ) ;
}
static void F_122 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_31 ) {
F_20 ( L_43 ) ;
return;
}
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_259 = 0 ;
F_59 ( & V_31 -> V_166 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
F_33 ( V_31 -> V_36 ) ;
F_123 ( & V_31 -> V_40 ) ;
F_90 ( V_31 ) ;
F_20 ( L_36 ) ;
}
static int F_124 ( struct V_6 * V_31 )
{
int V_101 = V_31 -> V_261 ;
int V_38 ;
F_38 ( V_31 -> V_282 ,
V_31 -> V_36 -> V_88 ,
F_39 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_89 ->
V_90 & 0x7F ) ,
V_31 -> V_260 , V_31 -> V_261 ,
F_122 , V_31 ) ;
V_38 = F_40 ( V_31 -> V_282 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_67 , V_38 ) ;
return V_38 ;
}
return V_101 ;
}
static void V_277 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_264 * V_284 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_31 )
return;
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_259 = 0 ;
F_59 ( & V_31 -> V_166 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_284 = (struct V_264 * ) ( V_32 -> V_285 ) ;
F_64 ( L_68 , V_51 ) ;
F_64 ( L_69 , V_32 -> V_120 ) ;
F_37 ( V_32 -> V_121 , V_32 -> V_120 ) ;
if ( V_284 -> V_270 ==
( V_271 | V_272 | V_273 ) ) {
V_31 -> V_160 [ 0 ] = 1 ;
F_58 ( & V_31 -> V_166 ) ;
F_69 ( V_31 ) ;
F_59 ( & V_31 -> V_166 ) ;
} else {
F_33 ( V_31 -> V_36 ) ;
F_123 ( & V_31 -> V_40 ) ;
F_90 ( V_31 ) ;
}
}
static int F_68 ( struct V_32 * V_32 , struct V_6 * V_31 )
{
struct V_152 * V_153 ;
int V_101 ;
if ( V_32 == NULL || V_31 == NULL ) {
F_20 ( L_70 ) ;
return - 2 ;
}
V_153 = F_125 ( & V_31 -> V_40 ) ;
if ( V_153 && F_31 ( V_286 , & V_153 -> V_47 ) ) {
F_126 ( V_153 ) ;
return - 1 ;
}
F_20 ( L_71 ) ;
V_101 = F_127 ( & V_31 -> V_40 , V_32 -> V_120 ) ;
if ( V_101 >= V_32 -> V_120 ) {
F_128 ( & V_31 -> V_40 , V_32 -> V_121 ,
V_32 -> V_120 ) ;
F_129 ( & V_31 -> V_40 ) ;
} else {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_72 , V_32 -> V_120 ) ;
}
F_126 ( V_153 ) ;
V_31 -> V_160 [ F_7 ( V_31 , V_32 ) ] = 0 ;
return 0 ;
}
static void F_130 ( struct V_2 * V_3 )
{
char * V_287 ;
char V_288 [ 20 ] ;
switch ( V_3 -> V_19 & V_20 ) {
case V_21 :
V_287 = L_2 ;
break;
case V_22 :
V_287 = L_3 ;
break;
case V_24 :
V_287 = L_5 ;
break;
case V_25 :
V_287 = L_73 ;
break;
case V_23 :
V_287 = L_4 ;
break;
case V_26 :
V_287 = L_7 ;
break;
case V_27 :
V_287 = L_8 ;
break;
case V_28 :
V_287 = L_9 ;
break;
case V_29 :
V_287 = L_10 ;
break;
case V_30 :
V_287 = L_11 ;
break;
default:
V_287 = L_12 ;
break;
}
if ( ( V_3 -> V_19 & V_20 ) == V_30 ) {
sprintf ( V_288 , L_74 , F_1 ( V_3 ) -> V_70 -> V_12 ) ;
} else
sprintf ( V_288 , L_75 , V_289 ,
F_2 ( V_3 ) -> V_156 ) ;
F_131 ( & V_3 -> V_94 -> V_15 , L_76 ,
V_287 , V_288 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ ) {
F_38 ( V_1 -> V_291 [ V_43 ] ,
V_3 -> V_88 ,
F_60 ( V_3 -> V_88 ,
V_1 -> V_123 ->
V_90 & 0x7F ) ,
V_1 -> V_292 [ V_43 ] ,
V_126 , F_56 ,
V_1 ) ;
V_38 = F_40 ( V_1 -> V_291 [ V_43 ] ,
V_293 ) ;
if ( V_38 )
F_41 ( & V_3 -> V_88 -> V_15 ,
L_77 , V_50 ,
V_43 , V_38 ) ;
}
return V_38 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ ) {
if ( V_1 -> V_291 [ V_43 ] )
F_132 ( V_1 -> V_291 [ V_43 ] ) ;
}
if ( V_1 -> V_87 )
F_132 ( V_1 -> V_87 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_3 , T_7 V_47 )
{
int V_43 , V_38 = 0 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return - V_54 ;
if ( ! ( V_31 -> V_36 -> V_19 & V_167 ) ) {
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_38 ( V_31 -> V_35 [ V_43 ] ,
V_31 -> V_36 -> V_88 ,
F_60 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_123 ->
V_90 &
0x7F ) ,
V_31 -> V_278 [ V_43 ] ,
V_31 -> V_157 ,
V_158 ,
V_31 ) ;
V_38 = F_40 ( V_31 -> V_35 [ V_43 ] , V_47 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_67 ,
V_38 ) ;
break;
}
}
} else {
F_76 ( & V_31 -> V_42 -> V_294 ) ;
if ( ! V_31 -> V_42 -> V_295 ) {
V_38 =
F_120 ( V_31 -> V_42 ,
V_3 -> V_88 , V_47 ) ;
}
V_31 -> V_42 -> V_295 ++ ;
F_86 ( & V_31 -> V_42 -> V_294 ) ;
}
if ( V_31 -> V_189 )
F_95 ( V_31 ,
V_31 -> V_189 ,
V_31 -> V_36 -> V_88 ) ;
return V_38 ;
}
static int F_82 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
struct V_188 * V_189 ;
if ( ! V_31 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
if ( V_31 -> V_35 [ V_43 ] ) {
F_132 ( V_31 -> V_35 [ V_43 ] ) ;
V_31 -> V_160 [ V_43 ] = 0 ;
}
}
V_31 -> V_161 = 0 ;
if ( V_31 -> V_282 )
F_132 ( V_31 -> V_282 ) ;
if ( V_31 -> V_42 ) {
F_76 ( & V_31 -> V_42 -> V_294 ) ;
if ( V_31 -> V_42 -> V_295 &&
( -- V_31 -> V_42 -> V_295 == 0 ) ) {
struct V_32 * V_32 ;
V_32 = V_31 -> V_42 -> V_296 ;
if ( V_32 )
F_132 ( V_32 ) ;
}
F_86 ( & V_31 -> V_42 -> V_294 ) ;
}
V_189 = V_31 -> V_189 ;
if ( V_189 ) {
F_99 ( & V_189 -> V_227 ) ;
F_132 ( V_189 -> V_32 ) ;
}
return 0 ;
}
static void F_133 ( struct V_6 * V_31 )
{
int V_43 ;
if ( V_31 -> V_36 -> V_15 )
F_134 ( V_31 -> V_36 -> V_15 , & V_297 ) ;
F_135 ( V_298 , V_31 -> V_156 ) ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_136 ( V_31 -> V_35 [ V_43 ] ) ;
F_137 ( V_31 -> V_278 [ V_43 ] ) ;
}
F_136 ( V_31 -> V_282 ) ;
F_137 ( V_31 -> V_260 ) ;
F_138 ( & V_31 -> V_40 ) ;
}
static int F_139 ( struct V_6 * V_31 , int V_299 ,
int V_300 , int V_301 )
{
struct V_14 * V_15 ;
int V_156 ;
int V_43 ;
F_140 ( & V_31 -> V_40 ) ;
V_156 = F_15 () ;
if ( V_156 < 0 )
goto exit;
V_31 -> V_36 -> V_15 = F_141 ( & V_31 -> V_40 , V_298 ,
V_156 , & V_31 -> V_36 -> V_94 -> V_15 ) ;
V_15 = V_31 -> V_36 -> V_15 ;
F_142 ( V_15 , V_31 -> V_36 ) ;
V_43 = F_143 ( V_15 , & V_297 ) ;
V_31 -> V_156 = V_156 ;
V_31 -> V_171 = V_172 ;
F_144 ( & V_31 -> V_166 ) ;
V_31 -> V_34 = V_299 ;
V_31 -> V_157 = V_300 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
V_31 -> V_35 [ V_43 ] = F_145 ( 0 , V_176 ) ;
if ( ! V_31 -> V_35 [ V_43 ] ) {
F_8 ( V_15 , L_78 ) ;
goto exit;
}
V_31 -> V_35 [ V_43 ] -> V_121 = NULL ;
V_31 -> V_35 [ V_43 ] -> V_125 = 0 ;
V_31 -> V_278 [ V_43 ] = F_146 ( V_31 -> V_157 ,
V_176 ) ;
if ( ! V_31 -> V_278 [ V_43 ] )
goto exit;
}
V_31 -> V_282 = F_145 ( 0 , V_176 ) ;
if ( ! V_31 -> V_282 ) {
F_8 ( V_15 , L_78 ) ;
goto exit;
}
V_31 -> V_282 -> V_121 = NULL ;
V_31 -> V_282 -> V_125 = 0 ;
V_31 -> V_261 = 0 ;
V_31 -> V_183 = 0 ;
V_31 -> V_182 = V_301 ;
V_31 -> V_260 = F_146 ( V_31 -> V_182 , V_176 ) ;
if ( ! V_31 -> V_260 )
goto exit;
V_31 -> V_185 = F_146 ( V_31 -> V_182 , V_176 ) ;
if ( ! V_31 -> V_185 )
goto exit;
return 0 ;
exit:
F_133 ( V_31 ) ;
return - 1 ;
}
static struct V_2 * F_147 ( struct V_302 * V_303 ,
int V_19 )
{
struct V_2 * V_3 ;
V_3 = F_146 ( sizeof( * V_3 ) , V_93 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_88 = F_148 ( V_303 ) ;
V_3 -> V_94 = V_303 ;
F_149 ( & V_3 -> V_175 ) ;
F_150 ( & V_3 -> V_173 ) ;
F_151 ( & V_3 -> V_304 , V_304 ) ;
F_151 ( & V_3 -> V_305 , V_305 ) ;
F_151 ( & V_3 -> V_68 , V_68 ) ;
return V_3 ;
}
static int F_152 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
if ( V_307 [ V_43 ] == V_3 ) {
V_307 [ V_43 ] = NULL ;
break;
}
}
if ( V_43 == V_306 )
return - 1 ;
return 0 ;
}
static void F_153 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return;
F_152 ( V_1 -> V_36 ) ;
if ( V_1 -> V_70 )
F_154 ( V_1 -> V_70 ) ;
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ ) {
F_136 ( V_1 -> V_291 [ V_43 ] ) ;
F_137 ( V_1 -> V_292 [ V_43 ] ) ;
V_1 -> V_292 [ V_43 ] = NULL ;
}
F_136 ( V_1 -> V_87 ) ;
F_137 ( V_1 -> V_85 ) ;
V_1 -> V_85 = NULL ;
if ( V_1 -> V_70 )
F_155 ( V_1 -> V_70 ) ;
F_137 ( V_3 ) ;
}
static void F_156 ( struct V_69 * V_70 )
{
struct V_1 * V_1 = F_22 ( V_70 ) ;
F_20 ( L_79 , ( int ) sizeof( * V_1 ) ) ;
V_70 -> V_308 = & V_309 ;
V_70 -> V_310 = V_311 ;
V_70 -> V_47 = V_312 | V_313 | V_314 ;
V_70 -> type = V_315 ;
V_70 -> V_316 = V_317 - 14 ;
V_70 -> V_318 = 10 ;
V_70 -> V_319 = & V_320 ;
F_144 ( & V_1 -> V_73 ) ;
}
static int F_157 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
if ( V_307 [ V_43 ] == NULL ) {
V_307 [ V_43 ] = V_3 ;
break;
}
}
if ( V_43 == V_306 )
return - 1 ;
return 0 ;
}
static int F_158 ( void * V_84 , bool V_321 )
{
struct V_2 * V_3 = V_84 ;
int V_322 = ! V_321 ;
int V_323 ;
F_76 ( & V_3 -> V_173 ) ;
if ( V_3 -> V_180 )
V_323 = 0 ;
else
V_323 = F_111 ( V_3 -> V_88 , F_112 ( V_3 -> V_88 , 0 ) ,
V_322 ? 0x82 : 0x81 , 0x40 , 0 , 0 , NULL , 0 ,
V_253 ) ;
F_86 ( & V_3 -> V_173 ) ;
return V_323 ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_302 * V_94 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_14 * V_15 = & V_1 -> V_70 -> V_15 ;
char * V_324 ;
V_324 = F_146 ( 20 , V_176 ) ;
if ( ! V_324 )
F_8 ( V_15 , L_80 , V_50 ) ;
snprintf ( V_324 , 20 , L_81 ,
V_94 -> V_201 -> V_202 . V_203 ) ;
V_1 -> V_325 = F_160 ( V_324 ,
& F_148 ( V_94 ) -> V_15 ,
V_326 ,
& V_327 , V_3 ) ;
if ( ! V_1 -> V_325 ) {
F_8 ( V_15 , L_80 , V_50 ) ;
F_137 ( V_324 ) ;
return;
}
if ( F_161 ( V_1 -> V_325 ) < 0 ) {
F_162 ( V_1 -> V_325 ) ;
F_137 ( V_324 ) ;
V_1 -> V_325 = NULL ;
F_8 ( V_15 , L_82 , V_50 ) ;
return;
}
}
static struct V_2 * F_163 ( struct V_302 * V_94 ,
int V_19 )
{
int V_38 , V_43 ;
struct V_69 * V_70 ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
V_3 = F_147 ( V_94 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_70 = F_164 ( sizeof( struct V_1 ) , L_83 , V_328 ,
F_156 ) ;
if ( ! V_70 ) {
F_8 ( & V_94 -> V_15 , L_84 ) ;
goto exit;
}
V_1 = F_22 ( V_70 ) ;
V_3 -> V_4 . V_5 = V_1 ;
V_1 -> V_70 = V_70 ;
V_1 -> V_36 = V_3 ;
V_1 -> V_123 = F_165 ( V_94 , V_329 ,
V_271 ) ;
if ( ! V_1 -> V_123 ) {
F_8 ( & V_94 -> V_15 , L_85 ) ;
goto exit;
}
V_1 -> V_89 = F_165 ( V_94 , V_329 ,
V_275 ) ;
if ( ! V_1 -> V_89 ) {
F_8 ( & V_94 -> V_15 , L_86 ) ;
goto exit;
}
F_166 ( V_70 , & V_94 -> V_15 ) ;
F_167 ( V_70 , & V_330 ) ;
V_38 = F_168 ( V_70 ) ;
if ( V_38 ) {
F_8 ( & V_94 -> V_15 , L_87 ) ;
goto exit;
}
for ( V_43 = 0 ; V_43 < V_290 ; V_43 ++ ) {
V_1 -> V_291 [ V_43 ] = F_145 ( 0 , V_176 ) ;
if ( ! V_1 -> V_291 [ V_43 ] ) {
F_8 ( & V_94 -> V_15 , L_88 ) ;
goto exit;
}
V_1 -> V_292 [ V_43 ] = F_146 ( V_126 ,
V_176 ) ;
if ( ! V_1 -> V_292 [ V_43 ] )
goto exit;
}
V_1 -> V_87 = F_145 ( 0 , V_176 ) ;
if ( ! V_1 -> V_87 ) {
F_8 ( & V_94 -> V_15 , L_89 ) ;
goto exit;
}
V_1 -> V_85 = F_146 ( V_86 , V_176 ) ;
if ( ! V_1 -> V_85 )
goto exit;
F_157 ( V_3 ) ;
F_130 ( V_3 ) ;
F_159 ( V_3 , V_94 ) ;
return V_3 ;
exit:
F_153 ( V_3 ) ;
return NULL ;
}
static void F_169 ( struct V_6 * V_31 )
{
struct V_188 * V_189 ;
if ( ! V_31 )
return;
V_189 = V_31 -> V_189 ;
if ( V_189 ) {
F_136 ( V_189 -> V_32 ) ;
V_189 -> V_32 = NULL ;
V_31 -> V_189 = NULL ;
F_137 ( V_189 ) ;
}
}
static void F_170 ( struct V_2 * V_3 )
{
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return;
F_17 ( V_31 -> V_156 , NULL ) ;
F_133 ( V_31 ) ;
if ( V_31 -> V_42 ) {
F_76 ( & V_31 -> V_42 -> V_294 ) ;
if ( -- V_31 -> V_42 -> V_331 == 0 )
F_171 ( V_31 -> V_42 ) ;
else
F_86 ( & V_31 -> V_42 -> V_294 ) ;
}
F_169 ( V_31 ) ;
F_137 ( V_31 ) ;
F_137 ( V_3 ) ;
}
static struct V_2 * F_172 (
struct V_302 * V_94 , int V_40 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_299 ;
struct V_188 * V_189 ;
V_3 = F_147 ( V_94 , V_40 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_146 ( sizeof( * V_31 ) , V_176 ) ;
if ( ! V_31 )
goto exit;
V_31 -> V_36 = V_3 ;
V_3 -> V_4 . V_7 = V_31 ;
if ( ( V_40 & V_20 ) == V_29 ) {
V_299 = 2 ;
V_31 -> V_189 = F_146 ( sizeof( struct V_188 ) ,
V_176 ) ;
if ( V_31 -> V_189 ) {
V_189 = V_31 -> V_189 ;
V_189 -> V_32 = F_145 ( 0 , V_176 ) ;
if ( V_189 -> V_32 ) {
F_150 ( & V_189 -> V_173 ) ;
F_173 ( & V_189 -> V_227 ) ;
V_189 -> V_191 = F_165 (
V_94 ,
V_332 ,
V_271 ) ;
} else
F_169 ( V_31 ) ;
}
}
else
V_299 = 1 ;
if ( F_139 ( V_31 , V_299 , V_333 ,
V_334 ) )
goto exit;
V_31 -> V_123 = F_165 ( V_94 , V_329 ,
V_271 ) ;
if ( ! V_31 -> V_123 ) {
F_8 ( & V_94 -> V_15 , L_90 ) ;
goto V_335;
}
if ( !
( V_31 -> V_89 =
F_165 ( V_94 , V_329 , V_275 ) ) ) {
F_8 ( & V_94 -> V_15 , L_90 ) ;
goto V_335;
}
V_31 -> V_262 = F_124 ;
F_17 ( V_31 -> V_156 , V_31 ) ;
F_130 ( V_3 ) ;
return V_3 ;
V_335:
F_133 ( V_31 ) ;
exit:
F_169 ( V_31 ) ;
F_137 ( V_31 ) ;
F_137 ( V_3 ) ;
return NULL ;
}
static
struct V_2 * F_174 ( struct V_302 * V_94 ,
int V_40 ,
struct V_41 * V_37 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_19 ;
V_19 = V_167 ;
V_19 &= ~ V_20 ;
V_19 |= F_9 ( V_40 ) ;
if ( ( V_19 & V_20 ) == V_39 )
return NULL ;
V_3 = F_147 ( V_94 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_146 ( sizeof( * V_31 ) , V_176 ) ;
if ( ! V_31 )
goto exit;
V_3 -> V_4 . V_7 = V_31 ;
V_31 -> V_36 = V_3 ;
if ( F_139
( V_31 , 1 , V_279 , V_336 ) )
goto exit;
V_31 -> V_182 -- ;
V_31 -> V_262 = F_121 ;
V_31 -> V_42 = V_37 ;
F_76 ( & V_31 -> V_42 -> V_294 ) ;
V_31 -> V_42 -> V_331 ++ ;
F_86 ( & V_31 -> V_42 -> V_294 ) ;
F_17 ( V_31 -> V_156 , V_31 ) ;
F_130 ( V_3 ) ;
return V_3 ;
exit:
if ( V_31 ) {
F_135 ( V_298 , V_31 -> V_156 ) ;
F_137 ( V_31 ) ;
}
if ( V_3 )
F_137 ( V_3 ) ;
return NULL ;
}
static void F_171 ( struct V_41 * V_37 )
{
F_136 ( V_37 -> V_296 ) ;
F_137 ( V_37 -> V_337 ) ;
F_86 ( & V_37 -> V_294 ) ;
F_137 ( V_37 ) ;
}
static
struct V_41 * F_175 ( struct V_302 * V_94 )
{
struct V_41 * V_37 = F_146 ( sizeof( * V_37 ) , V_176 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_338 = F_165 ( V_94 , V_332 ,
V_271 ) ;
if ( ! V_37 -> V_338 ) {
F_8 ( & V_94 -> V_15 , L_91 ) ;
goto exit;
}
V_37 -> V_296 = F_145 ( 0 , V_176 ) ;
if ( ! V_37 -> V_296 ) {
F_8 ( & V_94 -> V_15 , L_92 ) ;
goto exit;
}
V_37 -> V_337 =
F_146 ( F_55 ( V_37 -> V_338 -> V_124 ) ,
V_176 ) ;
if ( ! V_37 -> V_337 )
goto exit;
F_150 ( & V_37 -> V_294 ) ;
return V_37 ;
exit:
F_137 ( V_37 -> V_337 ) ;
F_136 ( V_37 -> V_296 ) ;
F_137 ( V_37 ) ;
return NULL ;
}
static int F_176 ( struct V_302 * V_94 )
{
struct V_190 * V_339 = F_148 ( V_94 ) ;
T_5 * V_340 = F_177 ( 17 , V_176 ) ;
T_2 V_200 = V_94 -> V_201 -> V_202 . V_203 ;
T_8 V_38 ;
if ( ! V_340 )
return - V_341 ;
if ( F_111 ( V_339 , F_112 ( V_339 , 0 ) ,
0x86 , 0xC0 , 0 , 0 , V_340 , 17 ,
V_253 ) != 0x11 ) {
F_137 ( V_340 ) ;
return - V_342 ;
}
switch ( V_340 [ V_200 ] ) {
case 0x0 :
V_38 = 0 ;
break;
case 0x1 :
V_38 = V_27 ;
break;
case 0x2 :
V_38 = V_24 ;
break;
case 0x3 :
V_38 = V_25 ;
break;
case 0x4 :
V_38 = V_22 ;
break;
case 0x5 :
V_38 = V_23 ;
break;
case 0x6 :
V_38 = V_21 ;
break;
case 0x7 :
V_38 = V_30 ;
break;
case 0x8 :
V_38 = V_29 ;
break;
case 0x9 :
V_38 = V_343 ;
break;
case 0xa :
V_38 = V_26 ;
break;
case 0xb :
V_38 = V_344 ;
break;
default:
V_38 = 0 ;
}
if ( V_38 )
V_38 |= V_345 ;
if ( V_340 [ 16 ] & 0x1 )
V_38 |= V_122 ;
F_137 ( V_340 ) ;
return V_38 ;
}
static int F_178 ( struct V_302 * V_94 ,
const struct V_346 * V_347 )
{
int V_37 , V_43 , V_200 , V_19 ;
unsigned char V_348 ;
struct V_2 * V_3 = NULL ;
struct V_41 * V_42 ;
struct V_2 * V_349 = NULL ;
if ( V_94 -> V_350 -> V_202 . V_351 != 0xFF ) {
F_8 ( & V_94 -> V_15 , L_93 ) ;
return - V_54 ;
}
V_200 = V_94 -> V_201 -> V_202 . V_203 ;
if ( V_347 -> V_352 )
V_19 = ( ( T_2 * ) ( V_347 -> V_352 ) ) [ V_200 ] ;
else
V_19 = F_176 ( V_94 ) ;
if ( V_94 -> V_353 > 1 )
F_179 ( F_148 ( V_94 ) , V_200 , 1 ) ;
V_94 -> V_354 = 1 ;
switch ( V_19 & V_355 ) {
case V_167 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_356 ) {
V_3 = F_163 ( V_94 ,
V_19 ) ;
if ( ! V_3 )
goto exit;
V_349 = V_3 ;
}
}
if ( F_180 ( V_94 , & V_348 ) )
goto exit;
V_42 = F_175 ( V_94 ) ;
if ( ! V_42 )
goto exit;
for ( V_43 = 1 , V_37 = 0 ; V_43 < 0x100 ; V_43 = V_43 << 1 , V_37 ++ ) {
if ( V_348 & V_43 ) {
V_3 = F_174 (
V_94 , V_43 , V_42 ) ;
if ( ! V_3 )
goto exit;
}
}
if ( V_349 )
V_3 = V_349 ;
break;
case V_345 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_356 )
V_3 =
F_163 ( V_94 , V_19 ) ;
} else {
V_3 =
F_172 ( V_94 , V_19 ) ;
}
if ( ! V_3 )
goto exit;
break;
default:
goto exit;
}
F_181 ( V_94 , V_3 ) ;
return 0 ;
exit:
F_182 ( V_94 ) ;
return - V_54 ;
}
static void F_183 ( struct V_302 * V_94 )
{
F_182 ( V_94 ) ;
F_181 ( V_94 , NULL ) ;
}
static void V_304 ( struct V_357 * V_84 )
{
struct V_2 * V_3 =
F_184 ( V_84 , struct V_2 , V_304 ) ;
F_77 ( V_3 -> V_94 ) ;
}
static void V_305 ( struct V_357 * V_84 )
{
struct V_2 * V_3 =
F_184 ( V_84 , struct V_2 , V_305 ) ;
F_84 ( V_3 -> V_94 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_239 == V_358 ) {
if ( ! V_3 -> V_359 ) {
V_3 -> V_359 = 1 ;
F_19 ( & V_3 -> V_304 ) ;
}
}
if ( V_3 -> V_88 -> V_239 != V_360 )
return - V_61 ;
F_57 ( V_3 -> V_88 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_239 != V_358 ) {
if ( V_3 -> V_359 ) {
V_3 -> V_359 = 0 ;
F_19 ( & V_3 -> V_305 ) ;
return - V_61 ;
}
}
V_3 -> V_359 = 0 ;
return 0 ;
}
static int F_185 ( struct V_302 * V_361 , T_9 V_362 )
{
int V_43 , V_38 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_94 == V_361 ) ) {
V_38 = F_82 ( V_45 [ V_43 ] ) ;
if ( V_38 )
goto V_184;
}
}
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
if ( V_307 [ V_43 ] &&
( V_307 [ V_43 ] -> V_94 == V_361 ) ) {
V_38 = F_29 ( V_307 [ V_43 ] ) ;
if ( V_38 )
goto V_184;
}
}
V_184:
return 0 ;
}
static int F_186 ( struct V_302 * V_361 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_94 == V_361 ) ) {
if ( F_2 ( V_45 [ V_43 ] ) -> V_40 . V_101 ) {
V_38 =
F_81 ( V_45 [ V_43 ] , V_293 ) ;
F_90 ( F_2 ( V_45 [ V_43 ] ) ) ;
if ( V_38 )
goto V_184;
}
}
}
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
if ( V_307 [ V_43 ] &&
( V_307 [ V_43 ] -> V_94 == V_361 ) ) {
V_1 = F_1 ( V_307 [ V_43 ] ) ;
if ( V_1 -> V_47 & V_363 ) {
if ( V_1 -> V_72 ) {
F_131 ( & V_361 -> V_15 ,
L_94
L_95 ) ;
F_35 ( V_1 -> V_72 ,
V_1 -> V_70 ) ;
V_1 -> V_72 = NULL ;
}
V_38 = F_24 ( V_307 [ V_43 ] ) ;
if ( V_38 )
goto V_184;
}
}
}
V_184:
return V_38 ;
}
static void V_68 ( struct V_357 * V_84 )
{
struct V_2 * V_3 =
F_184 ( V_84 , struct V_2 , V_68 ) ;
struct V_190 * V_88 = V_3 -> V_88 ;
int V_38 ;
if ( V_3 -> V_180 ) {
F_20 ( L_96 ) ;
} else {
V_38 = F_187 ( V_88 , V_3 -> V_94 ) ;
if ( V_38 < 0 )
F_20 ( L_97 , V_38 ) ;
else {
F_188 ( V_88 ) ;
F_189 ( V_88 ) ;
}
}
}
static void V_177 ( struct V_364 * V_175 )
{
struct V_2 * V_3 = F_184 ( V_175 , struct V_2 , V_175 ) ;
F_170 ( V_3 ) ;
}
static void F_182 ( struct V_302 * V_94 )
{
struct V_6 * V_3 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] &&
( V_45 [ V_43 ] -> V_94 == V_94 ) ) {
V_3 = F_2 ( V_45 [ V_43 ] ) ;
F_190 ( & V_3 -> V_40 , false ) ;
F_76 ( & V_3 -> V_36 -> V_173 ) ;
V_3 -> V_36 -> V_180 = 1 ;
F_86 ( & V_3 -> V_36 -> V_173 ) ;
F_83 ( & V_45 [ V_43 ] -> V_175 , V_177 ) ;
}
}
for ( V_43 = 0 ; V_43 < V_306 ; V_43 ++ ) {
if ( V_307 [ V_43 ] &&
( V_307 [ V_43 ] -> V_94 == V_94 ) ) {
struct V_325 * V_365 = F_1 ( V_307 [ V_43 ] ) -> V_325 ;
F_27 ( F_1 ( V_307 [ V_43 ] ) -> V_70 ) ;
F_29 ( V_307 [ V_43 ] ) ;
F_191 ( & V_307 [ V_43 ] -> V_305 ) ;
F_191 ( & V_307 [ V_43 ] -> V_304 ) ;
if ( V_365 ) {
F_192 ( V_365 ) ;
F_162 ( V_365 ) ;
}
F_153 ( V_307 [ V_43 ] ) ;
}
}
}
static struct V_366 * F_165 ( struct V_302 * V_303 ,
int type , int V_367 )
{
int V_43 ;
struct V_368 * V_361 = V_303 -> V_350 ;
struct V_366 * V_191 ;
for ( V_43 = 0 ; V_43 < V_361 -> V_202 . V_369 ; V_43 ++ ) {
V_191 = & V_361 -> V_370 [ V_43 ] . V_202 ;
if ( ( ( V_191 -> V_90 & V_371 ) == V_367 ) &&
( F_193 ( V_191 ) == type ) )
return V_191 ;
}
return NULL ;
}
static int F_180 ( struct V_302 * V_303 , unsigned char * V_372 )
{
int V_43 ;
struct V_368 * V_361 = V_303 -> V_350 ;
if ( V_361 -> V_373 == 3 ) {
* V_372 = V_361 -> V_374 [ 2 ] ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_361 -> V_202 . V_369 ; V_43 ++ ) {
if ( V_361 -> V_370 [ V_43 ] . V_373 == 3 ) {
* V_372 = V_361 -> V_370 [ V_43 ] . V_374 [ 2 ] ;
return 0 ;
}
}
return - 1 ;
}
static int F_120 ( struct V_41 * V_42 ,
struct V_190 * V_88 , T_7 V_375 )
{
int V_38 ;
F_96 ( V_42 -> V_296 , V_88 ,
F_97 ( V_88 ,
V_42 -> V_338 -> V_90 & 0x7F ) ,
V_42 -> V_337 ,
1 ,
F_119 , V_42 ,
V_42 -> V_338 -> V_195 ) ;
V_38 = F_40 ( V_42 -> V_296 , V_375 ) ;
if ( V_38 )
F_41 ( & V_88 -> V_15 , L_98 , V_50 ,
V_38 ) ;
return V_38 ;
}
static int T_10 F_194 ( void )
{
int V_43 ;
int V_38 ;
F_16 ( V_376 L_99 , V_377 ) ;
F_144 ( & V_48 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
V_45 [ V_43 ] = NULL ;
V_298 = F_195 ( V_44 ) ;
if ( ! V_298 )
return - V_341 ;
V_298 -> V_378 = V_378 ;
V_298 -> V_12 = V_289 ;
if ( V_379 )
V_298 -> V_380 = V_379 ;
V_298 -> V_381 = 0 ;
V_298 -> type = V_382 ;
V_298 -> V_383 = V_384 ;
V_298 -> V_47 = V_385 | V_386 ;
V_298 -> V_387 = V_388 ;
F_61 ( & V_298 -> V_387 ) ;
F_196 ( V_298 , & V_389 ) ;
V_38 = F_197 ( V_298 ) ;
if ( V_38 ) {
F_16 ( V_49 L_100 ,
V_50 , V_38 ) ;
goto V_390;
}
V_38 = F_198 ( & V_391 ) ;
if ( V_38 ) {
F_16 ( V_49 L_101 ,
V_38 ) ;
goto V_392;
}
return 0 ;
V_392:
F_199 ( V_298 ) ;
V_390:
F_200 ( V_298 ) ;
return V_38 ;
}
static void T_11 F_201 ( void )
{
F_16 ( V_376 L_102 ) ;
F_199 ( V_298 ) ;
F_200 ( V_298 ) ;
F_202 ( & V_391 ) ;
}
