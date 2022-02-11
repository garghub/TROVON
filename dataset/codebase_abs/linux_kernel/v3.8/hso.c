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
if ( ! V_31 ) {
F_20 ( L_42 ) ;
return;
} else if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
F_64 ( L_43 , V_51 ) ;
F_20 ( L_44 , V_32 -> V_120 ) ;
F_37 ( V_32 -> V_121 , V_32 -> V_120 ) ;
if ( V_31 -> V_40 . V_101 == 0 )
return;
if ( V_51 == 0 ) {
if ( V_31 -> V_36 -> V_19 & V_122 )
F_54 ( V_32 , V_31 -> V_123 -> V_124 ) ;
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_160 [ F_7 ( V_31 , V_32 ) ] = 1 ;
F_67 ( V_31 ) ;
F_59 ( & V_31 -> V_166 ) ;
} else if ( V_51 == - V_55 || V_51 == - V_167 ) {
F_71 ( L_45 , V_31 -> V_156 ) ;
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_160 [ F_7 ( V_31 , V_32 ) ] = 0 ;
F_66 ( V_31 , V_32 ) ;
F_59 ( & V_31 -> V_166 ) ;
} else {
F_71 ( L_46 , V_31 -> V_156 , V_51 ) ;
return;
}
}
static void F_72 ( struct V_6 * V_31 )
{
unsigned long V_47 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( ( V_31 -> V_36 -> V_19 & V_168 ) )
F_69 ( V_31 ) ;
else
F_67 ( V_31 ) ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static void F_73 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
F_74 ( & V_31 -> V_169 ) ;
}
static void F_75 ( struct V_170 * V_171 )
{
struct V_6 * V_31 =
F_76 ( V_171 , struct V_6 ,
V_172 ) ;
F_72 ( V_31 ) ;
}
static int F_77 ( struct V_152 * V_153 , struct V_173 * V_174 )
{
struct V_6 * V_31 = F_12 ( V_153 -> V_46 ) ;
int V_38 ;
if ( V_31 == NULL || V_31 -> V_175 != V_176 ) {
F_78 ( 1 ) ;
V_153 -> V_155 = NULL ;
F_20 ( L_47 ) ;
return - V_54 ;
}
F_79 ( & V_31 -> V_36 -> V_177 ) ;
V_38 = F_80 ( V_31 -> V_36 -> V_94 ) ;
if ( V_38 < 0 )
goto V_178;
F_20 ( L_48 , V_31 -> V_156 ) ;
F_81 ( & V_31 -> V_36 -> V_179 ) ;
V_153 -> V_155 = V_31 ;
F_82 ( & V_31 -> V_40 , V_153 ) ;
V_31 -> V_40 . V_101 ++ ;
if ( V_31 -> V_40 . V_101 == 1 ) {
V_31 -> V_162 = V_165 ;
F_63 ( V_153 , NULL ) ;
F_83 ( & V_31 -> V_169 ,
( void (*) ( unsigned long ) ) F_72 ,
( unsigned long ) V_31 ) ;
F_84 ( & V_31 -> V_172 ,
F_75 ) ;
V_38 = F_85 ( V_31 -> V_36 , V_180 ) ;
if ( V_38 ) {
F_86 ( V_31 -> V_36 ) ;
V_31 -> V_40 . V_101 -- ;
F_87 ( & V_31 -> V_36 -> V_179 , V_181 ) ;
}
} else {
F_20 ( L_49 ) ;
}
F_88 ( V_31 -> V_36 -> V_94 ) ;
if ( V_38 )
F_89 ( V_153 , V_182 | V_183 , 0 ) ;
V_178:
F_90 ( & V_31 -> V_36 -> V_177 ) ;
return V_38 ;
}
static void F_91 ( struct V_152 * V_153 , struct V_173 * V_174 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
T_5 V_184 ;
F_20 ( L_50 ) ;
if ( V_31 == NULL )
return;
F_79 ( & V_31 -> V_36 -> V_177 ) ;
V_184 = V_31 -> V_36 -> V_184 ;
if ( ! V_184 )
F_80 ( V_31 -> V_36 -> V_94 ) ;
V_31 -> V_40 . V_101 -- ;
if ( V_31 -> V_40 . V_101 <= 0 ) {
V_31 -> V_40 . V_101 = 0 ;
F_82 ( & V_31 -> V_40 , NULL ) ;
if ( ! V_184 )
F_86 ( V_31 -> V_36 ) ;
F_92 ( & V_31 -> V_169 ) ;
F_93 ( & V_31 -> V_172 ) ;
}
if ( ! V_184 )
F_88 ( V_31 -> V_36 -> V_94 ) ;
F_90 ( & V_31 -> V_36 -> V_177 ) ;
F_87 ( & V_31 -> V_36 -> V_179 , V_181 ) ;
}
static int F_94 ( struct V_152 * V_153 , const unsigned char * V_10 ,
int V_101 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_185 , V_98 ;
unsigned long V_47 ;
if ( V_31 == NULL ) {
F_16 ( V_49 L_51 , V_50 ) ;
return - V_54 ;
}
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_185 = V_31 -> V_186 - V_31 -> V_187 ;
V_98 = ( V_101 < V_185 ) ? V_101 : V_185 ;
if ( ! V_98 )
goto V_188;
memcpy ( V_31 -> V_189 + V_31 -> V_187 , V_10 , V_98 ) ;
V_31 -> V_187 += V_98 ;
V_188:
F_14 ( & V_31 -> V_166 , V_47 ) ;
F_95 ( V_31 ) ;
return V_98 ;
}
static int F_96 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_190 ;
unsigned long V_47 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_190 = V_31 -> V_186 - V_31 -> V_187 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return V_190 ;
}
static void F_97 ( struct V_152 * V_153 , struct V_127 * V_154 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
unsigned long V_47 ;
if ( V_154 )
F_98 ( L_52 ,
V_153 -> V_128 . V_146 , V_154 -> V_146 ) ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( V_31 -> V_40 . V_101 )
F_63 ( V_153 , V_154 ) ;
else
V_153 -> V_128 = * V_154 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static int F_99 ( struct V_152 * V_153 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_191 ;
unsigned long V_47 ;
if ( V_31 == NULL )
return 0 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
V_191 = V_31 -> V_187 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return V_191 ;
}
static int F_100 ( struct V_6 * V_31 ,
struct V_192 * V_193 ,
struct V_194 * V_88 )
{
int V_38 ;
if ( V_31 -> V_36 -> V_184 )
return - V_54 ;
F_101 ( V_193 -> V_32 , V_88 ,
F_102 ( V_88 ,
V_193 -> V_195 ->
V_90 & 0x7F ) ,
& V_193 -> V_196 ,
sizeof( struct V_197 ) ,
V_198 , V_31 ,
V_193 -> V_195 -> V_199 ) ;
V_38 = F_40 ( V_193 -> V_32 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_88 -> V_15 , L_53 , V_50 ,
V_38 ) ;
}
return V_38 ;
}
static void V_198 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_192 * V_193 ;
int V_51 = V_32 -> V_51 ;
T_6 V_200 , V_201 ;
struct V_202 * V_203 ;
struct V_197 * V_196 ;
struct V_194 * V_88 ;
if ( ! V_31 )
return;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_193 = V_31 -> V_193 ;
if ( ! V_193 )
return;
V_88 = V_31 -> V_36 -> V_88 ;
V_196 = & V_193 -> V_196 ;
if ( V_196 -> V_204 != V_205 ||
V_196 -> V_206 != V_207 ||
F_55 ( V_196 -> V_208 ) != V_209 ||
F_55 ( V_196 -> V_210 ) != V_211 ||
F_55 ( V_196 -> V_212 ) != V_213 ) {
F_41 ( & V_88 -> V_15 ,
L_54 ) ;
F_46 ( V_196 ,
sizeof( struct V_197 ) ) ;
} else {
V_200 = F_55 ( V_196 ->
V_200 ) ;
V_201 = V_193 -> V_201 ;
V_203 = & V_193 -> V_203 ;
F_58 ( & V_31 -> V_166 ) ;
if ( ( V_200 & V_214 ) !=
( V_201 & V_214 ) )
V_203 -> V_215 ++ ;
if ( ( V_200 & V_216 ) !=
( V_201 & V_216 ) )
V_203 -> V_215 ++ ;
if ( ( V_200 & V_217 ) !=
( V_201 & V_217 ) )
V_203 -> V_218 ++ ;
if ( ( V_200 & V_219 ) &&
! ( V_201 & V_219 ) )
V_203 -> V_220 ++ ;
if ( ( V_200 & V_221 ) !=
( V_201 & V_221 ) )
V_203 -> V_222 ++ ;
if ( ( V_200 & V_223 ) !=
( V_201 & V_223 ) )
V_203 -> V_224 ++ ;
if ( ( V_200 & V_225 ) !=
( V_201 & V_225 ) )
V_203 -> V_226 ++ ;
V_193 -> V_201 = V_200 ;
F_59 ( & V_31 -> V_166 ) ;
V_193 -> V_227 = 1 ;
F_103 ( & V_193 -> V_228 ) ;
}
memset ( V_196 , 0 ,
sizeof( struct V_197 ) ) ;
F_100 ( V_31 ,
V_193 ,
V_31 -> V_36 -> V_88 ) ;
}
static int
F_104 ( struct V_6 * V_31 , unsigned long V_229 )
{
F_105 ( V_230 , V_231 ) ;
struct V_202 V_232 , V_233 ;
struct V_192 * V_193 ;
int V_234 ;
V_193 = V_31 -> V_193 ;
if ( ! V_193 )
return - V_55 ;
F_106 ( & V_31 -> V_166 ) ;
memcpy ( & V_232 , & V_193 -> V_203 , sizeof( struct V_202 ) ) ;
F_107 ( & V_31 -> V_166 ) ;
F_108 ( & V_193 -> V_228 , & V_230 ) ;
for (; ; ) {
F_106 ( & V_31 -> V_166 ) ;
memcpy ( & V_233 , & V_193 -> V_203 , sizeof( struct V_202 ) ) ;
F_107 ( & V_31 -> V_166 ) ;
F_109 ( V_235 ) ;
if ( ( ( V_229 & V_236 ) && ( V_233 . V_220 != V_232 . V_220 ) ) ||
( ( V_229 & V_237 ) && ( V_233 . V_224 != V_232 . V_224 ) ) ||
( ( V_229 & V_238 ) && ( V_233 . V_226 != V_232 . V_226 ) ) ) {
V_234 = 0 ;
break;
}
F_110 () ;
if ( F_111 ( V_231 ) ) {
V_234 = - V_239 ;
break;
}
V_232 = V_233 ;
}
V_231 -> V_240 = V_241 ;
F_112 ( & V_193 -> V_228 , & V_230 ) ;
return V_234 ;
}
static int F_113 ( struct V_152 * V_153 ,
struct V_242 * V_203 )
{
struct V_202 V_233 ;
struct V_6 * V_31 = V_153 -> V_155 ;
struct V_192 * V_193 = V_31 -> V_193 ;
memset ( V_203 , 0 , sizeof( struct V_242 ) ) ;
if ( ! V_193 )
return - V_55 ;
F_106 ( & V_31 -> V_166 ) ;
memcpy ( & V_233 , & V_193 -> V_203 , sizeof( struct V_202 ) ) ;
F_107 ( & V_31 -> V_166 ) ;
V_203 -> V_243 = V_233 . V_243 ;
V_203 -> V_224 = V_233 . V_224 ;
V_203 -> V_220 = V_233 . V_220 ;
V_203 -> V_226 = V_233 . V_226 ;
V_203 -> V_244 = V_233 . V_244 ;
V_203 -> V_245 = V_233 . V_245 ;
V_203 -> V_218 = V_233 . V_218 ;
V_203 -> V_246 = V_233 . V_246 ;
V_203 -> V_215 = V_233 . V_215 ;
V_203 -> V_222 = V_233 . V_222 ;
V_203 -> V_247 = V_233 . V_247 ;
return 0 ;
}
static int F_114 ( struct V_152 * V_153 )
{
int V_248 ;
struct V_6 * V_31 = V_153 -> V_155 ;
struct V_192 * V_193 ;
T_6 V_200 ;
if ( ! V_31 ) {
F_20 ( L_55 ) ;
return - V_60 ;
}
F_106 ( & V_31 -> V_166 ) ;
V_248 = ( ( V_31 -> V_249 ) ? V_182 : 0 ) |
( ( V_31 -> V_250 ) ? V_183 : 0 ) ;
V_193 = V_31 -> V_193 ;
if ( V_193 ) {
V_200 = F_55 (
V_193 -> V_201 ) ;
if ( V_200 & V_219 )
V_248 |= V_236 ;
if ( V_200 & V_225 )
V_248 |= V_238 ;
if ( V_200 & V_223 )
V_248 |= V_237 ;
}
F_107 ( & V_31 -> V_166 ) ;
return V_248 ;
}
static int F_89 ( struct V_152 * V_153 ,
unsigned int V_251 , unsigned int V_252 )
{
int V_253 = 0 ;
unsigned long V_47 ;
int V_254 ;
struct V_6 * V_31 = V_153 -> V_155 ;
if ( ! V_31 ) {
F_20 ( L_55 ) ;
return - V_60 ;
}
if ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 )
return - V_60 ;
V_254 = V_31 -> V_36 -> V_94 -> V_255 -> V_256 . V_257 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( V_251 & V_182 )
V_31 -> V_249 = 1 ;
if ( V_251 & V_183 )
V_31 -> V_250 = 1 ;
if ( V_252 & V_182 )
V_31 -> V_249 = 0 ;
if ( V_252 & V_183 )
V_31 -> V_250 = 0 ;
if ( V_31 -> V_250 )
V_253 |= 0x01 ;
if ( V_31 -> V_249 )
V_253 |= 0x02 ;
F_14 ( & V_31 -> V_166 , V_47 ) ;
return F_115 ( V_31 -> V_36 -> V_88 ,
F_116 ( V_31 -> V_36 -> V_88 , 0 ) , 0x22 ,
0x21 , V_253 , V_254 , NULL , 0 ,
V_258 ) ;
}
static int F_117 ( struct V_152 * V_153 ,
unsigned int V_259 , unsigned long V_229 )
{
struct V_6 * V_31 = V_153 -> V_155 ;
int V_234 = 0 ;
F_64 ( L_56 , V_259 , V_229 ) ;
if ( ! V_31 )
return - V_54 ;
switch ( V_259 ) {
case V_260 :
V_234 = F_104 ( V_31 , V_229 ) ;
break;
default:
V_234 = - V_261 ;
break;
}
return V_234 ;
}
static void F_95 ( struct V_6 * V_31 )
{
T_5 * V_262 ;
unsigned long V_47 ;
int V_263 ;
F_13 ( & V_31 -> V_166 , V_47 ) ;
if ( ! V_31 -> V_187 )
goto V_188;
if ( V_31 -> V_264 )
goto V_188;
if ( F_36 ( V_31 -> V_36 ) == - V_61 )
goto V_188;
V_262 = V_31 -> V_189 ;
V_31 -> V_189 = V_31 -> V_265 ;
V_31 -> V_265 = V_262 ;
V_31 -> V_266 = V_31 -> V_187 ;
V_31 -> V_187 = 0 ;
if ( V_262 && V_31 -> V_267 ) {
V_263 = V_31 -> V_267 ( V_31 ) ;
if ( V_263 >= 0 )
V_31 -> V_264 = 1 ;
}
V_188:
F_14 ( & V_31 -> V_166 , V_47 ) ;
}
static int F_118 ( struct V_6 * V_31 , T_5 type , T_6 V_40 ,
struct V_32 * V_268 ,
struct V_269 * V_270 ,
T_5 * V_271 , T_2 V_272 )
{
int V_38 ;
int V_273 ;
if ( ! V_31 || ! V_268 || ! V_270 ) {
F_16 ( V_49 L_57 , V_50 ) ;
return - V_60 ;
}
V_270 -> V_208 = 0 ;
V_270 -> V_210 = F_119 ( F_10 ( V_40 ) ) ;
V_270 -> V_212 = F_119 ( V_272 ) ;
if ( type == V_274 ) {
V_270 -> V_275 = V_276 |
V_277 |
V_278 ;
V_270 -> V_279 = V_274 ;
V_273 = F_116 ( V_31 -> V_36 -> V_88 , 0 ) ;
} else {
V_270 -> V_275 = V_280 |
V_277 |
V_278 ;
V_270 -> V_279 = V_281 ;
V_273 = F_120 ( V_31 -> V_36 -> V_88 , 0 ) ;
}
F_71 ( L_58 ,
type == V_274 ? L_59 : L_60 ,
V_270 -> V_275 , V_270 -> V_212 , V_40 ) ;
V_268 -> V_91 = 0 ;
F_121 ( V_268 ,
V_31 -> V_36 -> V_88 ,
V_273 ,
( T_5 * ) V_270 ,
V_271 , V_272 , V_282 , V_31 ) ;
V_38 = F_40 ( V_268 , V_93 ) ;
if ( V_38 ) {
F_8 ( & V_268 -> V_15 -> V_15 ,
L_61 , V_50 ,
V_38 , type ) ;
return V_38 ;
}
return V_272 ;
}
static int F_70 ( struct V_6 * V_31 )
{
if ( ! V_31 )
return - V_60 ;
memset ( V_31 -> V_283 [ 0 ] , 0 , V_284 ) ;
if ( V_31 -> V_34 != 1 ) {
F_8 ( & V_31 -> V_36 -> V_94 -> V_15 ,
L_62
L_63 ) ;
return 0 ;
}
return F_118 ( V_31 ,
V_274 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_35 [ 0 ] ,
& V_31 -> V_285 ,
V_31 -> V_283 [ 0 ] , V_31 -> V_157 ) ;
}
static void F_122 ( struct V_32 * V_32 )
{
struct V_41 * V_42 = V_32 -> V_80 ;
struct V_6 * V_31 ;
unsigned char * V_286 ;
int V_51 = V_32 -> V_51 ;
int V_43 ;
F_57 ( V_32 -> V_15 ) ;
if ( ! V_42 )
return;
if ( V_51 ) {
F_18 ( V_51 , V_50 , NULL ) ;
return;
}
F_64 ( L_64 , V_51 ) ;
V_286 = V_32 -> V_121 ;
F_64 ( L_65 , * V_286 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( * V_286 & ( 1 << V_43 ) ) {
V_31 = F_11 ( V_42 ,
( 1 << V_43 ) ) ;
if ( V_31 != NULL ) {
F_20 ( L_66 , V_43 ) ;
F_58 ( & V_31 -> V_166 ) ;
if ( V_31 -> V_162 == V_165 &&
V_31 -> V_40 . V_101 > 0 ) {
if ( ! V_31 -> V_160 [ 0 ] ) {
V_31 -> V_162 = V_164 ;
F_70 ( V_31 ) ;
} else
V_31 -> V_162 = V_163 ;
} else {
F_20 ( L_67
L_68 , V_43 ) ;
}
F_59 ( & V_31 -> V_166 ) ;
}
}
}
F_123 ( V_42 , V_32 -> V_15 , V_93 ) ;
}
static int F_124 ( struct V_6 * V_31 )
{
if ( NULL == V_31 )
return - V_60 ;
return F_118 ( V_31 ,
V_281 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_287 ,
& V_31 -> V_288 ,
V_31 -> V_265 , V_31 -> V_266 ) ;
}
static void F_125 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
int V_51 = V_32 -> V_51 ;
struct V_152 * V_153 ;
if ( ! V_31 ) {
F_20 ( L_42 ) ;
return;
}
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_264 = 0 ;
F_59 ( & V_31 -> V_166 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
F_33 ( V_31 -> V_36 ) ;
V_153 = F_126 ( & V_31 -> V_40 ) ;
if ( V_153 ) {
F_127 ( V_153 ) ;
F_128 ( V_153 ) ;
}
F_95 ( V_31 ) ;
F_20 ( L_36 ) ;
}
static int F_129 ( struct V_6 * V_31 )
{
int V_101 = V_31 -> V_266 ;
int V_38 ;
F_38 ( V_31 -> V_287 ,
V_31 -> V_36 -> V_88 ,
F_39 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_89 ->
V_90 & 0x7F ) ,
V_31 -> V_265 , V_31 -> V_266 ,
F_125 , V_31 ) ;
V_38 = F_40 ( V_31 -> V_287 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_69 , V_38 ) ;
return V_38 ;
}
return V_101 ;
}
static void V_282 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_269 * V_289 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_31 )
return;
F_58 ( & V_31 -> V_166 ) ;
V_31 -> V_264 = 0 ;
F_59 ( & V_31 -> V_166 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_289 = (struct V_269 * ) ( V_32 -> V_290 ) ;
F_64 ( L_70 , V_51 ) ;
F_64 ( L_71 , V_32 -> V_120 ) ;
F_37 ( V_32 -> V_121 , V_32 -> V_120 ) ;
if ( V_289 -> V_275 ==
( V_276 | V_277 | V_278 ) ) {
V_31 -> V_160 [ 0 ] = 1 ;
F_58 ( & V_31 -> V_166 ) ;
F_69 ( V_31 ) ;
F_59 ( & V_31 -> V_166 ) ;
} else {
struct V_152 * V_153 = F_126 ( & V_31 -> V_40 ) ;
F_33 ( V_31 -> V_36 ) ;
if ( V_153 ) {
F_127 ( V_153 ) ;
F_128 ( V_153 ) ;
}
F_95 ( V_31 ) ;
}
}
static int F_68 ( struct V_32 * V_32 , struct V_6 * V_31 )
{
struct V_152 * V_153 ;
int V_291 = 0 ;
int V_292 ;
if ( V_32 == NULL || V_31 == NULL ) {
F_20 ( L_72 ) ;
return - 2 ;
}
V_153 = F_126 ( & V_31 -> V_40 ) ;
if ( V_153 ) {
V_291 = V_32 -> V_120 -
V_31 -> V_293 ;
F_20 ( L_73 ) ;
while ( V_291 ) {
if ( F_31 ( V_294 , & V_153 -> V_47 ) ) {
F_128 ( V_153 ) ;
return - 1 ;
}
V_292 = F_130
( V_153 , V_32 -> V_121 +
V_31 -> V_293 ,
V_291 ) ;
V_31 -> V_293 += V_292 ;
V_291 -= V_292 ;
F_131 ( V_153 ) ;
}
F_128 ( V_153 ) ;
}
if ( V_291 == 0 ) {
V_31 -> V_293 = 0 ;
V_31 -> V_160 [ F_7 ( V_31 , V_32 ) ] = 0 ;
}
return V_291 ;
}
static void F_132 ( struct V_2 * V_3 )
{
char * V_295 ;
char V_296 [ 20 ] ;
switch ( V_3 -> V_19 & V_20 ) {
case V_21 :
V_295 = L_2 ;
break;
case V_22 :
V_295 = L_3 ;
break;
case V_24 :
V_295 = L_5 ;
break;
case V_25 :
V_295 = L_74 ;
break;
case V_23 :
V_295 = L_4 ;
break;
case V_26 :
V_295 = L_7 ;
break;
case V_27 :
V_295 = L_8 ;
break;
case V_28 :
V_295 = L_9 ;
break;
case V_29 :
V_295 = L_10 ;
break;
case V_30 :
V_295 = L_11 ;
break;
default:
V_295 = L_12 ;
break;
}
if ( ( V_3 -> V_19 & V_20 ) == V_30 ) {
sprintf ( V_296 , L_75 , F_1 ( V_3 ) -> V_70 -> V_12 ) ;
} else
sprintf ( V_296 , L_76 , V_297 ,
F_2 ( V_3 ) -> V_156 ) ;
F_133 ( & V_3 -> V_94 -> V_15 , L_77 ,
V_295 , V_296 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_298 ; V_43 ++ ) {
F_38 ( V_1 -> V_299 [ V_43 ] ,
V_3 -> V_88 ,
F_60 ( V_3 -> V_88 ,
V_1 -> V_123 ->
V_90 & 0x7F ) ,
V_1 -> V_300 [ V_43 ] ,
V_126 , F_56 ,
V_1 ) ;
V_38 = F_40 ( V_1 -> V_299 [ V_43 ] ,
V_301 ) ;
if ( V_38 )
F_41 ( & V_3 -> V_88 -> V_15 ,
L_78 , V_50 ,
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
for ( V_43 = 0 ; V_43 < V_298 ; V_43 ++ ) {
if ( V_1 -> V_299 [ V_43 ] )
F_134 ( V_1 -> V_299 [ V_43 ] ) ;
}
if ( V_1 -> V_87 )
F_134 ( V_1 -> V_87 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , T_7 V_47 )
{
int V_43 , V_38 = 0 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return - V_54 ;
if ( ! ( V_31 -> V_36 -> V_19 & V_168 ) ) {
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_38 ( V_31 -> V_35 [ V_43 ] ,
V_31 -> V_36 -> V_88 ,
F_60 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_123 ->
V_90 &
0x7F ) ,
V_31 -> V_283 [ V_43 ] ,
V_31 -> V_157 ,
V_158 ,
V_31 ) ;
V_38 = F_40 ( V_31 -> V_35 [ V_43 ] , V_47 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_69 ,
V_38 ) ;
break;
}
}
} else {
F_79 ( & V_31 -> V_42 -> V_302 ) ;
if ( ! V_31 -> V_42 -> V_303 ) {
V_38 =
F_123 ( V_31 -> V_42 ,
V_3 -> V_88 , V_47 ) ;
}
V_31 -> V_42 -> V_303 ++ ;
F_90 ( & V_31 -> V_42 -> V_302 ) ;
}
if ( V_31 -> V_193 )
F_100 ( V_31 ,
V_31 -> V_193 ,
V_31 -> V_36 -> V_88 ) ;
return V_38 ;
}
static int F_86 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
struct V_192 * V_193 ;
if ( ! V_31 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
if ( V_31 -> V_35 [ V_43 ] ) {
F_134 ( V_31 -> V_35 [ V_43 ] ) ;
V_31 -> V_160 [ V_43 ] = 0 ;
}
}
V_31 -> V_161 = 0 ;
V_31 -> V_293 = 0 ;
if ( V_31 -> V_287 )
F_134 ( V_31 -> V_287 ) ;
if ( V_31 -> V_42 ) {
F_79 ( & V_31 -> V_42 -> V_302 ) ;
if ( V_31 -> V_42 -> V_303 &&
( -- V_31 -> V_42 -> V_303 == 0 ) ) {
struct V_32 * V_32 ;
V_32 = V_31 -> V_42 -> V_304 ;
if ( V_32 )
F_134 ( V_32 ) ;
}
F_90 ( & V_31 -> V_42 -> V_302 ) ;
}
V_193 = V_31 -> V_193 ;
if ( V_193 ) {
F_103 ( & V_193 -> V_228 ) ;
F_134 ( V_193 -> V_32 ) ;
}
return 0 ;
}
static void F_135 ( struct V_6 * V_31 )
{
int V_43 ;
if ( V_31 -> V_36 -> V_15 )
F_136 ( V_31 -> V_36 -> V_15 , & V_305 ) ;
F_137 ( V_306 , V_31 -> V_156 ) ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_138 ( V_31 -> V_35 [ V_43 ] ) ;
F_139 ( V_31 -> V_283 [ V_43 ] ) ;
}
F_138 ( V_31 -> V_287 ) ;
F_139 ( V_31 -> V_265 ) ;
F_140 ( & V_31 -> V_40 ) ;
}
static int F_141 ( struct V_6 * V_31 , int V_307 ,
int V_308 , int V_309 )
{
struct V_14 * V_15 ;
int V_156 ;
int V_43 ;
F_142 ( & V_31 -> V_40 ) ;
V_156 = F_15 () ;
if ( V_156 < 0 )
goto exit;
V_31 -> V_36 -> V_15 = F_143 ( & V_31 -> V_40 , V_306 ,
V_156 , & V_31 -> V_36 -> V_94 -> V_15 ) ;
V_15 = V_31 -> V_36 -> V_15 ;
F_144 ( V_15 , V_31 -> V_36 ) ;
V_43 = F_145 ( V_15 , & V_305 ) ;
V_31 -> V_156 = V_156 ;
V_31 -> V_175 = V_176 ;
F_146 ( & V_31 -> V_166 ) ;
V_31 -> V_34 = V_307 ;
V_31 -> V_157 = V_308 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
V_31 -> V_35 [ V_43 ] = F_147 ( 0 , V_180 ) ;
if ( ! V_31 -> V_35 [ V_43 ] ) {
F_8 ( V_15 , L_79 ) ;
goto exit;
}
V_31 -> V_35 [ V_43 ] -> V_121 = NULL ;
V_31 -> V_35 [ V_43 ] -> V_125 = 0 ;
V_31 -> V_283 [ V_43 ] = F_148 ( V_31 -> V_157 ,
V_180 ) ;
if ( ! V_31 -> V_283 [ V_43 ] ) {
F_8 ( V_15 , L_80 , V_50 ) ;
goto exit;
}
}
V_31 -> V_287 = F_147 ( 0 , V_180 ) ;
if ( ! V_31 -> V_287 ) {
F_8 ( V_15 , L_79 ) ;
goto exit;
}
V_31 -> V_287 -> V_121 = NULL ;
V_31 -> V_287 -> V_125 = 0 ;
V_31 -> V_266 = 0 ;
V_31 -> V_187 = 0 ;
V_31 -> V_186 = V_309 ;
V_31 -> V_265 = F_148 ( V_31 -> V_186 , V_180 ) ;
if ( ! V_31 -> V_265 ) {
F_8 ( V_15 , L_80 , V_50 ) ;
goto exit;
}
V_31 -> V_189 = F_148 ( V_31 -> V_186 , V_180 ) ;
if ( ! V_31 -> V_189 ) {
F_8 ( V_15 , L_80 , V_50 ) ;
goto exit;
}
return 0 ;
exit:
F_135 ( V_31 ) ;
return - 1 ;
}
static struct V_2 * F_149 ( struct V_310 * V_311 ,
int V_19 )
{
struct V_2 * V_3 ;
V_3 = F_148 ( sizeof( * V_3 ) , V_93 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_88 = F_150 ( V_311 ) ;
V_3 -> V_94 = V_311 ;
F_151 ( & V_3 -> V_179 ) ;
F_152 ( & V_3 -> V_177 ) ;
F_84 ( & V_3 -> V_312 , V_312 ) ;
F_84 ( & V_3 -> V_313 , V_313 ) ;
F_84 ( & V_3 -> V_68 , V_68 ) ;
return V_3 ;
}
static int F_153 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_314 ; V_43 ++ ) {
if ( V_315 [ V_43 ] == V_3 ) {
V_315 [ V_43 ] = NULL ;
break;
}
}
if ( V_43 == V_314 )
return - 1 ;
return 0 ;
}
static void F_154 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return;
F_153 ( V_1 -> V_36 ) ;
if ( V_1 -> V_70 )
F_155 ( V_1 -> V_70 ) ;
for ( V_43 = 0 ; V_43 < V_298 ; V_43 ++ ) {
F_138 ( V_1 -> V_299 [ V_43 ] ) ;
F_139 ( V_1 -> V_300 [ V_43 ] ) ;
V_1 -> V_300 [ V_43 ] = NULL ;
}
F_138 ( V_1 -> V_87 ) ;
F_139 ( V_1 -> V_85 ) ;
V_1 -> V_85 = NULL ;
if ( V_1 -> V_70 )
F_156 ( V_1 -> V_70 ) ;
F_139 ( V_3 ) ;
}
static void F_157 ( struct V_69 * V_70 )
{
struct V_1 * V_1 = F_22 ( V_70 ) ;
F_20 ( L_81 , ( int ) sizeof( * V_1 ) ) ;
V_70 -> V_316 = & V_317 ;
V_70 -> V_318 = V_319 ;
V_70 -> V_47 = V_320 | V_321 | V_322 ;
V_70 -> type = V_323 ;
V_70 -> V_324 = V_325 - 14 ;
V_70 -> V_326 = 10 ;
F_158 ( V_70 , & V_327 ) ;
F_146 ( & V_1 -> V_73 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_314 ; V_43 ++ ) {
if ( V_315 [ V_43 ] == NULL ) {
V_315 [ V_43 ] = V_3 ;
break;
}
}
if ( V_43 == V_314 )
return - 1 ;
return 0 ;
}
static int F_160 ( void * V_84 , bool V_328 )
{
struct V_2 * V_3 = V_84 ;
int V_329 = ! V_328 ;
int V_330 ;
F_79 ( & V_3 -> V_177 ) ;
if ( V_3 -> V_184 )
V_330 = 0 ;
else
V_330 = F_115 ( V_3 -> V_88 , F_116 ( V_3 -> V_88 , 0 ) ,
V_329 ? 0x82 : 0x81 , 0x40 , 0 , 0 , NULL , 0 ,
V_258 ) ;
F_90 ( & V_3 -> V_177 ) ;
return V_330 ;
}
static void F_161 ( struct V_2 * V_3 ,
struct V_310 * V_94 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_14 * V_15 = & V_1 -> V_70 -> V_15 ;
char * V_331 ;
V_331 = F_148 ( 20 , V_180 ) ;
if ( ! V_331 )
F_8 ( V_15 , L_80 , V_50 ) ;
snprintf ( V_331 , 20 , L_82 ,
V_94 -> V_255 -> V_256 . V_257 ) ;
V_1 -> V_332 = F_162 ( V_331 ,
& F_150 ( V_94 ) -> V_15 ,
V_333 ,
& V_334 , V_3 ) ;
if ( ! V_1 -> V_332 ) {
F_8 ( V_15 , L_80 , V_50 ) ;
F_139 ( V_331 ) ;
return;
}
if ( F_163 ( V_1 -> V_332 ) < 0 ) {
F_164 ( V_1 -> V_332 ) ;
F_139 ( V_331 ) ;
V_1 -> V_332 = NULL ;
F_8 ( V_15 , L_83 , V_50 ) ;
return;
}
}
static struct V_2 * F_165 ( struct V_310 * V_94 ,
int V_19 )
{
int V_38 , V_43 ;
struct V_69 * V_70 ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
V_3 = F_149 ( V_94 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_70 = F_166 ( sizeof( struct V_1 ) , L_84 , F_157 ) ;
if ( ! V_70 ) {
F_8 ( & V_94 -> V_15 , L_85 ) ;
goto exit;
}
V_1 = F_22 ( V_70 ) ;
V_3 -> V_4 . V_5 = V_1 ;
V_1 -> V_70 = V_70 ;
V_1 -> V_36 = V_3 ;
V_1 -> V_123 = F_167 ( V_94 , V_335 ,
V_276 ) ;
if ( ! V_1 -> V_123 ) {
F_8 ( & V_94 -> V_15 , L_86 ) ;
goto exit;
}
V_1 -> V_89 = F_167 ( V_94 , V_335 ,
V_280 ) ;
if ( ! V_1 -> V_89 ) {
F_8 ( & V_94 -> V_15 , L_87 ) ;
goto exit;
}
F_168 ( V_70 , & V_94 -> V_15 ) ;
F_169 ( V_70 , & V_336 ) ;
V_38 = F_170 ( V_70 ) ;
if ( V_38 ) {
F_8 ( & V_94 -> V_15 , L_88 ) ;
goto exit;
}
for ( V_43 = 0 ; V_43 < V_298 ; V_43 ++ ) {
V_1 -> V_299 [ V_43 ] = F_147 ( 0 , V_180 ) ;
if ( ! V_1 -> V_299 [ V_43 ] ) {
F_8 ( & V_94 -> V_15 , L_89 ) ;
goto exit;
}
V_1 -> V_300 [ V_43 ] = F_148 ( V_126 ,
V_180 ) ;
if ( ! V_1 -> V_300 [ V_43 ] ) {
F_8 ( & V_94 -> V_15 , L_90 ) ;
goto exit;
}
}
V_1 -> V_87 = F_147 ( 0 , V_180 ) ;
if ( ! V_1 -> V_87 ) {
F_8 ( & V_94 -> V_15 , L_91 ) ;
goto exit;
}
V_1 -> V_85 = F_148 ( V_86 , V_180 ) ;
if ( ! V_1 -> V_85 ) {
F_8 ( & V_94 -> V_15 , L_92 ) ;
goto exit;
}
F_159 ( V_3 ) ;
F_132 ( V_3 ) ;
F_161 ( V_3 , V_94 ) ;
return V_3 ;
exit:
F_154 ( V_3 ) ;
return NULL ;
}
static void F_171 ( struct V_6 * V_31 )
{
struct V_192 * V_193 ;
if ( ! V_31 )
return;
V_193 = V_31 -> V_193 ;
if ( V_193 ) {
F_138 ( V_193 -> V_32 ) ;
V_193 -> V_32 = NULL ;
V_31 -> V_193 = NULL ;
F_139 ( V_193 ) ;
}
}
static void F_172 ( struct V_2 * V_3 )
{
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return;
F_17 ( V_31 -> V_156 , NULL ) ;
F_135 ( V_31 ) ;
if ( V_31 -> V_42 ) {
F_79 ( & V_31 -> V_42 -> V_302 ) ;
if ( -- V_31 -> V_42 -> V_337 == 0 )
F_173 ( V_31 -> V_42 ) ;
else
F_90 ( & V_31 -> V_42 -> V_302 ) ;
}
F_171 ( V_31 ) ;
F_139 ( V_31 ) ;
F_139 ( V_3 ) ;
}
static struct V_2 * F_174 (
struct V_310 * V_94 , int V_40 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_307 ;
struct V_192 * V_193 ;
V_3 = F_149 ( V_94 , V_40 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_148 ( sizeof( * V_31 ) , V_180 ) ;
if ( ! V_31 )
goto exit;
V_31 -> V_36 = V_3 ;
V_3 -> V_4 . V_7 = V_31 ;
if ( ( V_40 & V_20 ) == V_29 ) {
V_307 = 2 ;
V_31 -> V_193 = F_148 ( sizeof( struct V_192 ) ,
V_180 ) ;
if ( V_31 -> V_193 ) {
V_193 = V_31 -> V_193 ;
V_193 -> V_32 = F_147 ( 0 , V_180 ) ;
if ( V_193 -> V_32 ) {
F_152 ( & V_193 -> V_177 ) ;
F_175 ( & V_193 -> V_228 ) ;
V_193 -> V_195 = F_167 (
V_94 ,
V_338 ,
V_276 ) ;
} else
F_171 ( V_31 ) ;
}
}
else
V_307 = 1 ;
if ( F_141 ( V_31 , V_307 , V_339 ,
V_340 ) )
goto exit;
V_31 -> V_123 = F_167 ( V_94 , V_335 ,
V_276 ) ;
if ( ! V_31 -> V_123 ) {
F_8 ( & V_94 -> V_15 , L_93 ) ;
goto V_341;
}
if ( !
( V_31 -> V_89 =
F_167 ( V_94 , V_335 , V_280 ) ) ) {
F_8 ( & V_94 -> V_15 , L_93 ) ;
goto V_341;
}
V_31 -> V_267 = F_129 ;
F_17 ( V_31 -> V_156 , V_31 ) ;
F_132 ( V_3 ) ;
return V_3 ;
V_341:
F_135 ( V_31 ) ;
exit:
F_171 ( V_31 ) ;
F_139 ( V_31 ) ;
F_139 ( V_3 ) ;
return NULL ;
}
static
struct V_2 * F_176 ( struct V_310 * V_94 ,
int V_40 ,
struct V_41 * V_37 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_19 ;
V_19 = V_168 ;
V_19 &= ~ V_20 ;
V_19 |= F_9 ( V_40 ) ;
if ( ( V_19 & V_20 ) == V_39 )
return NULL ;
V_3 = F_149 ( V_94 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_148 ( sizeof( * V_31 ) , V_180 ) ;
if ( ! V_31 )
goto exit;
V_3 -> V_4 . V_7 = V_31 ;
V_31 -> V_36 = V_3 ;
if ( F_141
( V_31 , 1 , V_284 , V_342 ) )
goto exit;
V_31 -> V_186 -- ;
V_31 -> V_267 = F_124 ;
V_31 -> V_42 = V_37 ;
F_79 ( & V_31 -> V_42 -> V_302 ) ;
V_31 -> V_42 -> V_337 ++ ;
F_90 ( & V_31 -> V_42 -> V_302 ) ;
F_17 ( V_31 -> V_156 , V_31 ) ;
F_132 ( V_3 ) ;
return V_3 ;
exit:
if ( V_31 ) {
F_137 ( V_306 , V_31 -> V_156 ) ;
F_139 ( V_31 ) ;
}
if ( V_3 )
F_139 ( V_3 ) ;
return NULL ;
}
static void F_173 ( struct V_41 * V_37 )
{
F_138 ( V_37 -> V_304 ) ;
F_139 ( V_37 -> V_343 ) ;
F_90 ( & V_37 -> V_302 ) ;
F_139 ( V_37 ) ;
}
static
struct V_41 * F_177 ( struct V_310 * V_94 )
{
struct V_41 * V_37 = F_148 ( sizeof( * V_37 ) , V_180 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_344 = F_167 ( V_94 , V_338 ,
V_276 ) ;
if ( ! V_37 -> V_344 ) {
F_8 ( & V_94 -> V_15 , L_94 ) ;
goto exit;
}
V_37 -> V_304 = F_147 ( 0 , V_180 ) ;
if ( ! V_37 -> V_304 ) {
F_8 ( & V_94 -> V_15 , L_95 ) ;
goto exit;
}
V_37 -> V_343 =
F_148 ( F_55 ( V_37 -> V_344 -> V_124 ) ,
V_180 ) ;
if ( ! V_37 -> V_343 ) {
F_8 ( & V_94 -> V_15 , L_96 ) ;
goto exit;
}
F_152 ( & V_37 -> V_302 ) ;
return V_37 ;
exit:
F_139 ( V_37 -> V_343 ) ;
F_138 ( V_37 -> V_304 ) ;
F_139 ( V_37 ) ;
return NULL ;
}
static int F_178 ( struct V_310 * V_94 )
{
struct V_194 * V_345 = F_150 ( V_94 ) ;
T_5 V_346 [ 17 ] ;
T_2 V_254 = V_94 -> V_255 -> V_256 . V_257 ;
T_8 V_38 ;
if ( F_115 ( V_345 , F_116 ( V_345 , 0 ) ,
0x86 , 0xC0 , 0 , 0 , V_346 , 17 ,
V_258 ) != 0x11 ) {
return - V_347 ;
}
switch ( V_346 [ V_254 ] ) {
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
V_38 = V_348 ;
break;
case 0xa :
V_38 = V_26 ;
break;
case 0xb :
V_38 = V_349 ;
break;
default:
V_38 = 0 ;
}
if ( V_38 )
V_38 |= V_350 ;
if ( V_346 [ 16 ] & 0x1 )
V_38 |= V_122 ;
return V_38 ;
}
static int F_179 ( struct V_310 * V_94 ,
const struct V_351 * V_352 )
{
int V_37 , V_43 , V_254 , V_19 ;
unsigned char V_353 ;
struct V_2 * V_3 = NULL ;
struct V_41 * V_42 ;
struct V_2 * V_354 = NULL ;
V_254 = V_94 -> V_255 -> V_256 . V_257 ;
if ( V_352 -> V_355 )
V_19 = ( ( T_2 * ) ( V_352 -> V_355 ) ) [ V_254 ] ;
else
V_19 = F_178 ( V_94 ) ;
if ( V_94 -> V_356 -> V_256 . V_357 != 0xFF ) {
F_8 ( & V_94 -> V_15 , L_97 ) ;
return - V_54 ;
}
if ( V_94 -> V_358 > 1 )
F_180 ( F_150 ( V_94 ) , V_254 , 1 ) ;
V_94 -> V_359 = 1 ;
switch ( V_19 & V_360 ) {
case V_168 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_361 ) {
V_3 = F_165 ( V_94 ,
V_19 ) ;
if ( ! V_3 )
goto exit;
V_354 = V_3 ;
}
}
if ( F_181 ( V_94 , & V_353 ) )
goto exit;
V_42 = F_177 ( V_94 ) ;
if ( ! V_42 )
goto exit;
for ( V_43 = 1 , V_37 = 0 ; V_43 < 0x100 ; V_43 = V_43 << 1 , V_37 ++ ) {
if ( V_353 & V_43 ) {
V_3 = F_176 (
V_94 , V_43 , V_42 ) ;
if ( ! V_3 )
goto exit;
}
}
if ( V_354 )
V_3 = V_354 ;
break;
case V_350 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_361 )
V_3 =
F_165 ( V_94 , V_19 ) ;
} else {
V_3 =
F_174 ( V_94 , V_19 ) ;
}
if ( ! V_3 )
goto exit;
break;
default:
goto exit;
}
F_182 ( V_94 , V_3 ) ;
return 0 ;
exit:
F_183 ( V_94 ) ;
return - V_54 ;
}
static void F_184 ( struct V_310 * V_94 )
{
F_183 ( V_94 ) ;
F_182 ( V_94 , NULL ) ;
}
static void V_312 ( struct V_170 * V_84 )
{
struct V_2 * V_3 =
F_76 ( V_84 , struct V_2 , V_312 ) ;
F_80 ( V_3 -> V_94 ) ;
}
static void V_313 ( struct V_170 * V_84 )
{
struct V_2 * V_3 =
F_76 ( V_84 , struct V_2 , V_313 ) ;
F_88 ( V_3 -> V_94 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_240 == V_362 ) {
if ( ! V_3 -> V_363 ) {
V_3 -> V_363 = 1 ;
F_19 ( & V_3 -> V_312 ) ;
}
}
if ( V_3 -> V_88 -> V_240 != V_364 )
return - V_61 ;
F_57 ( V_3 -> V_88 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_240 != V_362 ) {
if ( V_3 -> V_363 ) {
V_3 -> V_363 = 0 ;
F_19 ( & V_3 -> V_313 ) ;
return - V_61 ;
}
}
V_3 -> V_363 = 0 ;
return 0 ;
}
static int F_185 ( struct V_310 * V_365 , T_9 V_366 )
{
int V_43 , V_38 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_94 == V_365 ) ) {
V_38 = F_86 ( V_45 [ V_43 ] ) ;
if ( V_38 )
goto V_188;
}
}
for ( V_43 = 0 ; V_43 < V_314 ; V_43 ++ ) {
if ( V_315 [ V_43 ] &&
( V_315 [ V_43 ] -> V_94 == V_365 ) ) {
V_38 = F_29 ( V_315 [ V_43 ] ) ;
if ( V_38 )
goto V_188;
}
}
V_188:
return 0 ;
}
static int F_186 ( struct V_310 * V_365 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_94 == V_365 ) ) {
if ( F_2 ( V_45 [ V_43 ] ) -> V_40 . V_101 ) {
V_38 =
F_85 ( V_45 [ V_43 ] , V_301 ) ;
F_95 ( F_2 ( V_45 [ V_43 ] ) ) ;
if ( V_38 )
goto V_188;
}
}
}
for ( V_43 = 0 ; V_43 < V_314 ; V_43 ++ ) {
if ( V_315 [ V_43 ] &&
( V_315 [ V_43 ] -> V_94 == V_365 ) ) {
V_1 = F_1 ( V_315 [ V_43 ] ) ;
if ( V_1 -> V_47 & V_367 ) {
if ( V_1 -> V_72 ) {
F_133 ( & V_365 -> V_15 ,
L_98
L_99 ) ;
F_35 ( V_1 -> V_72 ,
V_1 -> V_70 ) ;
V_1 -> V_72 = NULL ;
}
V_38 = F_24 ( V_315 [ V_43 ] ) ;
if ( V_38 )
goto V_188;
}
}
}
V_188:
return V_38 ;
}
static void V_68 ( struct V_170 * V_84 )
{
struct V_2 * V_3 =
F_76 ( V_84 , struct V_2 , V_68 ) ;
struct V_194 * V_88 = V_3 -> V_88 ;
int V_38 ;
if ( V_3 -> V_184 ) {
F_20 ( L_100 ) ;
} else {
V_38 = F_187 ( V_88 , V_3 -> V_94 ) ;
if ( V_38 < 0 )
F_20 ( L_101 , V_38 ) ;
else {
F_188 ( V_88 ) ;
F_189 ( V_88 ) ;
}
}
}
static void V_181 ( struct V_368 * V_179 )
{
struct V_2 * V_3 = F_76 ( V_179 , struct V_2 , V_179 ) ;
F_172 ( V_3 ) ;
}
static void F_183 ( struct V_310 * V_94 )
{
struct V_6 * V_3 ;
struct V_152 * V_153 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] &&
( V_45 [ V_43 ] -> V_94 == V_94 ) ) {
V_3 = F_2 ( V_45 [ V_43 ] ) ;
V_153 = F_126 ( & V_3 -> V_40 ) ;
if ( V_153 ) {
F_190 ( V_153 ) ;
F_128 ( V_153 ) ;
}
F_79 ( & V_3 -> V_36 -> V_177 ) ;
V_3 -> V_36 -> V_184 = 1 ;
F_90 ( & V_3 -> V_36 -> V_177 ) ;
F_87 ( & V_45 [ V_43 ] -> V_179 , V_181 ) ;
}
}
for ( V_43 = 0 ; V_43 < V_314 ; V_43 ++ ) {
if ( V_315 [ V_43 ] &&
( V_315 [ V_43 ] -> V_94 == V_94 ) ) {
struct V_332 * V_369 = F_1 ( V_315 [ V_43 ] ) -> V_332 ;
F_27 ( F_1 ( V_315 [ V_43 ] ) -> V_70 ) ;
F_29 ( V_315 [ V_43 ] ) ;
F_93 ( & V_315 [ V_43 ] -> V_313 ) ;
F_93 ( & V_315 [ V_43 ] -> V_312 ) ;
if ( V_369 ) {
F_191 ( V_369 ) ;
F_164 ( V_369 ) ;
}
F_154 ( V_315 [ V_43 ] ) ;
}
}
}
static struct V_370 * F_167 ( struct V_310 * V_311 ,
int type , int V_371 )
{
int V_43 ;
struct V_372 * V_365 = V_311 -> V_356 ;
struct V_370 * V_195 ;
for ( V_43 = 0 ; V_43 < V_365 -> V_256 . V_373 ; V_43 ++ ) {
V_195 = & V_365 -> V_374 [ V_43 ] . V_256 ;
if ( ( ( V_195 -> V_90 & V_375 ) == V_371 ) &&
( F_192 ( V_195 ) == type ) )
return V_195 ;
}
return NULL ;
}
static int F_181 ( struct V_310 * V_311 , unsigned char * V_376 )
{
int V_43 ;
struct V_372 * V_365 = V_311 -> V_356 ;
if ( V_365 -> V_377 == 3 ) {
* V_376 = V_365 -> V_378 [ 2 ] ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_365 -> V_256 . V_373 ; V_43 ++ ) {
if ( V_365 -> V_374 [ V_43 ] . V_377 == 3 ) {
* V_376 = V_365 -> V_374 [ V_43 ] . V_378 [ 2 ] ;
return 0 ;
}
}
return - 1 ;
}
static int F_123 ( struct V_41 * V_42 ,
struct V_194 * V_88 , T_7 V_379 )
{
int V_38 ;
F_101 ( V_42 -> V_304 , V_88 ,
F_102 ( V_88 ,
V_42 -> V_344 -> V_90 & 0x7F ) ,
V_42 -> V_343 ,
1 ,
F_122 , V_42 ,
V_42 -> V_344 -> V_199 ) ;
V_38 = F_40 ( V_42 -> V_304 , V_379 ) ;
if ( V_38 )
F_41 ( & V_88 -> V_15 , L_102 , V_50 ,
V_38 ) ;
return V_38 ;
}
static int T_10 F_193 ( void )
{
int V_43 ;
int V_38 ;
F_16 ( V_380 L_103 , V_381 ) ;
F_146 ( & V_48 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
V_45 [ V_43 ] = NULL ;
V_306 = F_194 ( V_44 ) ;
if ( ! V_306 )
return - V_382 ;
V_306 -> V_383 = V_383 ;
V_306 -> V_12 = V_297 ;
if ( V_384 )
V_306 -> V_385 = V_384 ;
V_306 -> V_386 = 0 ;
V_306 -> type = V_387 ;
V_306 -> V_388 = V_389 ;
V_306 -> V_47 = V_390 | V_391 ;
V_306 -> V_392 = V_393 ;
F_61 ( & V_306 -> V_392 ) ;
F_195 ( V_306 , & V_394 ) ;
V_38 = F_196 ( V_306 ) ;
if ( V_38 ) {
F_16 ( V_49 L_104 ,
V_50 , V_38 ) ;
goto V_395;
}
V_38 = F_197 ( & V_396 ) ;
if ( V_38 ) {
F_16 ( V_49 L_105 ,
V_38 ) ;
goto V_397;
}
return 0 ;
V_397:
F_198 ( V_306 ) ;
V_395:
F_199 ( V_306 ) ;
return V_38 ;
}
static void T_11 F_200 ( void )
{
F_16 ( V_380 L_106 ) ;
F_198 ( V_306 ) ;
F_199 ( V_306 ) ;
F_201 ( & V_396 ) ;
}
