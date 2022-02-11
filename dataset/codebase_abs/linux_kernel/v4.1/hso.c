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
F_19 ( V_3 -> V_68 ) ;
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
F_41 ( & V_71 -> V_36 -> V_68 -> V_15 ,
L_30 , V_38 ) ;
V_70 -> V_94 . V_95 ++ ;
F_25 ( V_70 ) ;
} else {
V_70 -> V_94 . V_96 ++ ;
V_70 -> V_94 . V_97 += V_82 -> V_11 ;
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
( V_71 -> V_87 -> V_51 == - V_98 ) )
F_44 ( V_71 -> V_87 ) ;
V_70 -> V_94 . V_95 ++ ;
}
static void F_45 ( struct V_1 * V_71 , unsigned char * V_99 ,
unsigned int V_100 , unsigned char V_101 )
{
unsigned short V_102 ;
unsigned short V_103 = 0 ;
unsigned short V_104 ;
unsigned char * V_105 ;
F_20 ( L_32 , V_100 ) ;
F_46 ( V_99 , F_47 ( 128 , ( int ) V_100 ) ) ;
while ( V_100 ) {
switch ( V_71 -> V_74 ) {
case V_75 :
V_102 =
( V_100 <
V_71 -> V_77 ) ? V_100 : V_71 ->
V_77 ;
memcpy ( ( ( unsigned char * ) ( & V_71 -> V_106 ) ) +
V_71 -> V_76 , V_99 + V_103 ,
V_102 ) ;
V_71 -> V_76 += V_102 ;
V_103 += V_102 ;
V_71 -> V_77 -= V_102 ;
V_100 -= V_102 ;
if ( ! V_71 -> V_77 ) {
V_104 = F_48 ( V_71 -> V_106 . V_107 ) ;
if ( ( V_104 > V_108 ) ||
( V_104 < sizeof( struct V_78 ) ) ) {
F_8 ( & V_71 -> V_70 -> V_15 ,
L_33 ,
V_104 ) ;
V_71 -> V_74 = V_109 ;
continue;
}
V_71 -> V_110 = F_49 ( V_71 -> V_70 ,
V_104 ) ;
if ( ! V_71 -> V_110 ) {
F_20 ( L_34 ) ;
V_71 -> V_74 = V_109 ;
continue;
}
V_105 =
F_50 ( V_71 -> V_110 ,
sizeof( struct V_78 ) ) ;
memcpy ( V_105 , ( char * ) & ( V_71 -> V_106 ) ,
sizeof( struct V_78 ) ) ;
V_71 -> V_76 = sizeof( struct V_78 ) ;
V_71 -> V_77 =
V_104 - sizeof( struct V_78 ) ;
V_71 -> V_74 = V_111 ;
}
break;
case V_111 :
V_102 = ( V_100 < V_71 -> V_77 )
? V_100 : V_71 -> V_77 ;
V_105 = F_50 ( V_71 -> V_110 , V_102 ) ;
memcpy ( V_105 , V_99 + V_103 , V_102 ) ;
V_71 -> V_77 -= V_102 ;
V_100 -= V_102 ;
V_103 += V_102 ;
V_71 -> V_76 += V_102 ;
if ( ! V_71 -> V_77 ) {
V_71 -> V_110 -> V_112 = F_51 ( V_113 ) ;
F_52 ( V_71 -> V_110 ) ;
F_53 ( V_71 -> V_110 ) ;
V_71 -> V_110 = NULL ;
V_71 -> V_70 -> V_94 . V_114 ++ ;
V_71 -> V_70 -> V_94 . V_115 += V_71 -> V_76 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = sizeof( struct V_78 ) ;
V_71 -> V_74 = V_75 ;
}
break;
case V_109 :
F_20 ( L_35 ) ;
V_100 = 0 ;
break;
default:
F_20 ( L_36 ) ;
V_100 -- ;
break;
}
}
if ( V_101 ) {
if ( V_71 -> V_74 == V_109 ) {
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = sizeof( struct V_78 ) ;
}
}
}
static void F_54 ( struct V_32 * V_32 , T_4 V_116 )
{
static const T_5 V_117 [ 4 ] = { 0xDE , 0xAD , 0xBE , 0xEF } ;
T_2 V_118 = V_32 -> V_119 % F_55 ( V_116 ) ;
if ( ( ( V_118 == 5 ) || ( V_118 == 6 ) ) &&
! memcmp ( ( ( T_5 * ) V_32 -> V_120 ) + V_32 -> V_119 - 4 ,
V_117 , 4 ) ) {
V_32 -> V_119 -= 4 ;
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
if ( V_71 -> V_36 -> V_19 & V_121 )
F_54 ( V_32 , V_71 -> V_122 -> V_123 ) ;
if ( V_32 -> V_119 ) {
F_58 ( & V_71 -> V_73 ) ;
F_45 ( V_71 , V_32 -> V_120 , V_32 -> V_119 ,
( V_32 -> V_124 >
V_32 -> V_119 ) ? 1 : 0 ) ;
F_59 ( & V_71 -> V_73 ) ;
}
F_38 ( V_32 ,
V_71 -> V_36 -> V_88 ,
F_60 ( V_71 -> V_36 -> V_88 ,
V_71 -> V_122 ->
V_90 & 0x7F ) ,
V_32 -> V_120 , V_125 ,
F_56 , V_71 ) ;
V_38 = F_40 ( V_32 , V_93 ) ;
if ( V_38 )
F_41 ( & V_71 -> V_36 -> V_68 -> V_15 ,
L_38 , V_50 ,
V_38 ) ;
}
static void F_61 ( struct V_126 * V_127 )
{
V_127 -> V_128 &=
~ ( V_129
| V_130
| V_131
| V_132
| V_133
| V_134
| V_135
| V_136 ) ;
V_127 -> V_137 &= ~ V_138 ;
V_127 -> V_139 &=
~ ( V_140
| V_141
| V_142
| V_143
| V_144 ) ;
V_127 -> V_145 &=
~ ( V_146
| V_147
| V_148
| V_149 ) ;
V_127 -> V_145 |= V_150 ;
F_62 ( V_127 , 115200 , 115200 ) ;
}
static void F_63 ( struct V_151 * V_152 ,
struct V_126 * V_153 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
if ( ! V_31 ) {
F_16 ( V_49 L_39 , V_50 ) ;
return;
}
F_64 ( L_40 , V_31 -> V_155 ) ;
V_152 -> V_127 . V_128 &= ~ V_136 ;
V_152 -> V_127 . V_145 &=
~ ( V_146
| V_147
| V_148
| V_149 ) ;
V_152 -> V_127 . V_145 |= V_150 ;
F_65 ( V_152 , 115200 , 115200 ) ;
}
static void F_66 ( struct V_6 * V_31 , struct V_32 * V_32 )
{
int V_38 ;
F_38 ( V_32 , V_31 -> V_36 -> V_88 ,
F_60 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_122 ->
V_90 & 0x7F ) ,
V_32 -> V_120 , V_31 -> V_156 ,
V_157 , V_31 ) ;
V_38 = F_40 ( V_32 , V_93 ) ;
if ( V_38 ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_41 ,
V_50 , V_38 ) ;
}
}
static void F_67 ( struct V_6 * V_31 )
{
int V_100 ;
struct V_32 * V_158 ;
while ( V_31 -> V_159 [ V_31 -> V_160 ] ) {
V_158 = V_31 -> V_35 [ V_31 -> V_160 ] ;
V_100 = F_68 ( V_158 , V_31 ) ;
if ( V_100 == - 1 )
return;
if ( V_100 == 0 ) {
V_31 -> V_160 ++ ;
if ( V_31 -> V_160 >= V_31 -> V_34 )
V_31 -> V_160 = 0 ;
F_66 ( V_31 , V_158 ) ;
}
}
}
static void F_69 ( struct V_6 * V_31 )
{
int V_100 = 0 ;
struct V_32 * V_32 ;
V_32 = V_31 -> V_35 [ 0 ] ;
if ( V_31 -> V_40 . V_100 > 0 ) {
V_100 = F_68 ( V_32 , V_31 ) ;
if ( V_100 == - 1 )
return;
}
if ( V_100 == 0 && ( ( V_32 -> V_119 != 0 ) ||
( V_31 -> V_161 == V_162 ) ) ) {
V_31 -> V_161 = V_163 ;
F_70 ( V_31 ) ;
} else
V_31 -> V_161 = V_164 ;
}
static void V_157 ( struct V_32 * V_32 )
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
F_20 ( L_44 , V_32 -> V_119 ) ;
F_37 ( V_32 -> V_120 , V_32 -> V_119 ) ;
if ( V_31 -> V_40 . V_100 == 0 )
return;
if ( V_31 -> V_36 -> V_19 & V_121 )
F_54 ( V_32 , V_31 -> V_122 -> V_123 ) ;
F_58 ( & V_31 -> V_165 ) ;
V_31 -> V_159 [ F_7 ( V_31 , V_32 ) ] = 1 ;
F_67 ( V_31 ) ;
F_59 ( & V_31 -> V_165 ) ;
}
static void F_71 ( struct V_6 * V_31 )
{
unsigned long V_47 ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
if ( ( V_31 -> V_36 -> V_19 & V_166 ) )
F_69 ( V_31 ) ;
else
F_67 ( V_31 ) ;
F_14 ( & V_31 -> V_165 , V_47 ) ;
}
static void F_72 ( struct V_151 * V_152 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
F_73 ( & V_31 -> V_167 ) ;
}
static int F_74 ( struct V_151 * V_152 , struct V_168 * V_169 )
{
struct V_6 * V_31 = F_12 ( V_152 -> V_46 ) ;
int V_38 ;
if ( V_31 == NULL || V_31 -> V_170 != V_171 ) {
F_75 ( 1 ) ;
V_152 -> V_154 = NULL ;
F_20 ( L_45 ) ;
return - V_54 ;
}
F_76 ( & V_31 -> V_36 -> V_172 ) ;
V_38 = F_77 ( V_31 -> V_36 -> V_68 ) ;
if ( V_38 < 0 )
goto V_173;
F_20 ( L_46 , V_31 -> V_155 ) ;
V_152 -> V_154 = V_31 ;
F_78 ( & V_31 -> V_40 , V_152 ) ;
V_31 -> V_40 . V_100 ++ ;
if ( V_31 -> V_40 . V_100 == 1 ) {
V_31 -> V_161 = V_164 ;
F_63 ( V_152 , NULL ) ;
F_79 ( & V_31 -> V_167 ,
( void (*) ( unsigned long ) ) F_71 ,
( unsigned long ) V_31 ) ;
V_38 = F_80 ( V_31 -> V_36 , V_174 ) ;
if ( V_38 ) {
F_81 ( V_31 -> V_36 ) ;
V_31 -> V_40 . V_100 -- ;
} else {
F_82 ( & V_31 -> V_36 -> V_175 ) ;
}
} else {
F_20 ( L_47 ) ;
}
F_83 ( V_31 -> V_36 -> V_68 ) ;
if ( V_38 )
F_84 ( V_152 , V_176 | V_177 , 0 ) ;
V_173:
F_85 ( & V_31 -> V_36 -> V_172 ) ;
return V_38 ;
}
static void F_86 ( struct V_151 * V_152 , struct V_168 * V_169 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
T_5 V_178 ;
F_20 ( L_48 ) ;
if ( V_31 == NULL )
return;
F_76 ( & V_31 -> V_36 -> V_172 ) ;
V_178 = V_31 -> V_36 -> V_178 ;
if ( ! V_178 )
F_77 ( V_31 -> V_36 -> V_68 ) ;
V_31 -> V_40 . V_100 -- ;
if ( V_31 -> V_40 . V_100 <= 0 ) {
V_31 -> V_40 . V_100 = 0 ;
F_78 ( & V_31 -> V_40 , NULL ) ;
if ( ! V_178 )
F_81 ( V_31 -> V_36 ) ;
F_87 ( & V_31 -> V_167 ) ;
}
if ( ! V_178 )
F_83 ( V_31 -> V_36 -> V_68 ) ;
F_85 ( & V_31 -> V_36 -> V_172 ) ;
}
static int F_88 ( struct V_151 * V_152 , const unsigned char * V_10 ,
int V_100 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
int V_179 , V_97 ;
unsigned long V_47 ;
if ( V_31 == NULL ) {
F_16 ( V_49 L_49 , V_50 ) ;
return - V_54 ;
}
F_13 ( & V_31 -> V_165 , V_47 ) ;
V_179 = V_31 -> V_180 - V_31 -> V_181 ;
V_97 = ( V_100 < V_179 ) ? V_100 : V_179 ;
if ( ! V_97 )
goto V_182;
memcpy ( V_31 -> V_183 + V_31 -> V_181 , V_10 , V_97 ) ;
V_31 -> V_181 += V_97 ;
V_182:
F_14 ( & V_31 -> V_165 , V_47 ) ;
F_89 ( V_31 ) ;
return V_97 ;
}
static int F_90 ( struct V_151 * V_152 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
int V_184 ;
unsigned long V_47 ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
V_184 = V_31 -> V_180 - V_31 -> V_181 ;
F_14 ( & V_31 -> V_165 , V_47 ) ;
return V_184 ;
}
static void F_91 ( struct V_151 * V_152 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
if ( ! V_31 )
return;
F_92 ( & V_31 -> V_36 -> V_175 , V_185 ) ;
}
static void F_93 ( struct V_151 * V_152 , struct V_126 * V_153 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
unsigned long V_47 ;
if ( V_153 )
F_94 ( L_50 ,
V_152 -> V_127 . V_145 , V_153 -> V_145 ) ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
if ( V_31 -> V_40 . V_100 )
F_63 ( V_152 , V_153 ) ;
else
V_152 -> V_127 = * V_153 ;
F_14 ( & V_31 -> V_165 , V_47 ) ;
}
static int F_95 ( struct V_151 * V_152 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
int V_186 ;
unsigned long V_47 ;
if ( V_31 == NULL )
return 0 ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
V_186 = V_31 -> V_181 ;
F_14 ( & V_31 -> V_165 , V_47 ) ;
return V_186 ;
}
static int F_96 ( struct V_6 * V_31 ,
struct V_187 * V_188 ,
struct V_189 * V_88 )
{
int V_38 ;
if ( V_31 -> V_36 -> V_178 )
return - V_54 ;
F_97 ( V_188 -> V_32 , V_88 ,
F_98 ( V_88 ,
V_188 -> V_190 ->
V_90 & 0x7F ) ,
& V_188 -> V_191 ,
sizeof( struct V_192 ) ,
V_193 , V_31 ,
V_188 -> V_190 -> V_194 ) ;
V_38 = F_40 ( V_188 -> V_32 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_88 -> V_15 , L_51 , V_50 ,
V_38 ) ;
}
return V_38 ;
}
static void V_193 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_187 * V_188 ;
int V_51 = V_32 -> V_51 ;
T_6 V_195 , V_196 ;
struct V_197 * V_198 ;
struct V_192 * V_191 ;
struct V_189 * V_88 ;
struct V_199 * V_68 ;
int V_200 ;
if ( ! V_31 )
return;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_188 = V_31 -> V_188 ;
if ( ! V_188 )
return;
F_99 ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 ) ;
V_88 = V_31 -> V_36 -> V_88 ;
V_68 = V_31 -> V_36 -> V_68 ;
V_200 = V_68 -> V_201 -> V_202 . V_203 ;
V_191 = & V_188 -> V_191 ;
if ( V_191 -> V_204 != V_205 ||
V_191 -> V_206 != V_207 ||
F_55 ( V_191 -> V_208 ) != V_209 ||
F_55 ( V_191 -> V_210 ) != V_200 ||
F_55 ( V_191 -> V_211 ) != V_212 ) {
F_41 ( & V_88 -> V_15 ,
L_52 ) ;
F_46 ( V_191 ,
sizeof( struct V_192 ) ) ;
} else {
V_195 = F_55 ( V_191 ->
V_195 ) ;
V_196 = V_188 -> V_196 ;
V_198 = & V_188 -> V_198 ;
F_58 ( & V_31 -> V_165 ) ;
if ( ( V_195 & V_213 ) !=
( V_196 & V_213 ) )
V_198 -> V_214 ++ ;
if ( ( V_195 & V_215 ) !=
( V_196 & V_215 ) )
V_198 -> V_214 ++ ;
if ( ( V_195 & V_216 ) !=
( V_196 & V_216 ) )
V_198 -> V_217 ++ ;
if ( ( V_195 & V_218 ) &&
! ( V_196 & V_218 ) )
V_198 -> V_219 ++ ;
if ( ( V_195 & V_220 ) !=
( V_196 & V_220 ) )
V_198 -> V_221 ++ ;
if ( ( V_195 & V_222 ) !=
( V_196 & V_222 ) )
V_198 -> V_223 ++ ;
if ( ( V_195 & V_224 ) !=
( V_196 & V_224 ) )
V_198 -> V_225 ++ ;
V_188 -> V_196 = V_195 ;
F_59 ( & V_31 -> V_165 ) ;
V_188 -> V_226 = 1 ;
F_100 ( & V_188 -> V_227 ) ;
}
memset ( V_191 , 0 ,
sizeof( struct V_192 ) ) ;
F_96 ( V_31 ,
V_188 ,
V_31 -> V_36 -> V_88 ) ;
}
static int
F_101 ( struct V_6 * V_31 , unsigned long V_228 )
{
F_102 ( V_229 , V_230 ) ;
struct V_197 V_231 , V_232 ;
struct V_187 * V_188 ;
int V_233 ;
V_188 = V_31 -> V_188 ;
if ( ! V_188 )
return - V_55 ;
F_103 ( & V_31 -> V_165 ) ;
memcpy ( & V_231 , & V_188 -> V_198 , sizeof( struct V_197 ) ) ;
F_104 ( & V_31 -> V_165 ) ;
F_105 ( & V_188 -> V_227 , & V_229 ) ;
for (; ; ) {
F_103 ( & V_31 -> V_165 ) ;
memcpy ( & V_232 , & V_188 -> V_198 , sizeof( struct V_197 ) ) ;
F_104 ( & V_31 -> V_165 ) ;
F_106 ( V_234 ) ;
if ( ( ( V_228 & V_235 ) && ( V_232 . V_219 != V_231 . V_219 ) ) ||
( ( V_228 & V_236 ) && ( V_232 . V_223 != V_231 . V_223 ) ) ||
( ( V_228 & V_237 ) && ( V_232 . V_225 != V_231 . V_225 ) ) ) {
V_233 = 0 ;
break;
}
F_107 () ;
if ( F_108 ( V_230 ) ) {
V_233 = - V_238 ;
break;
}
V_231 = V_232 ;
}
F_109 ( V_239 ) ;
F_110 ( & V_188 -> V_227 , & V_229 ) ;
return V_233 ;
}
static int F_111 ( struct V_151 * V_152 ,
struct V_240 * V_198 )
{
struct V_197 V_232 ;
struct V_6 * V_31 = V_152 -> V_154 ;
struct V_187 * V_188 = V_31 -> V_188 ;
memset ( V_198 , 0 , sizeof( struct V_240 ) ) ;
if ( ! V_188 )
return - V_55 ;
F_103 ( & V_31 -> V_165 ) ;
memcpy ( & V_232 , & V_188 -> V_198 , sizeof( struct V_197 ) ) ;
F_104 ( & V_31 -> V_165 ) ;
V_198 -> V_241 = V_232 . V_241 ;
V_198 -> V_223 = V_232 . V_223 ;
V_198 -> V_219 = V_232 . V_219 ;
V_198 -> V_225 = V_232 . V_225 ;
V_198 -> V_242 = V_232 . V_242 ;
V_198 -> V_243 = V_232 . V_243 ;
V_198 -> V_217 = V_232 . V_217 ;
V_198 -> V_244 = V_232 . V_244 ;
V_198 -> V_214 = V_232 . V_214 ;
V_198 -> V_221 = V_232 . V_221 ;
V_198 -> V_245 = V_232 . V_245 ;
return 0 ;
}
static int F_112 ( struct V_151 * V_152 )
{
int V_246 ;
struct V_6 * V_31 = V_152 -> V_154 ;
struct V_187 * V_188 ;
T_6 V_195 ;
if ( ! V_31 ) {
F_20 ( L_53 ) ;
return - V_60 ;
}
F_103 ( & V_31 -> V_165 ) ;
V_246 = ( ( V_31 -> V_247 ) ? V_176 : 0 ) |
( ( V_31 -> V_248 ) ? V_177 : 0 ) ;
V_188 = V_31 -> V_188 ;
if ( V_188 ) {
V_195 = F_55 (
V_188 -> V_196 ) ;
if ( V_195 & V_218 )
V_246 |= V_235 ;
if ( V_195 & V_224 )
V_246 |= V_237 ;
if ( V_195 & V_222 )
V_246 |= V_236 ;
}
F_104 ( & V_31 -> V_165 ) ;
return V_246 ;
}
static int F_84 ( struct V_151 * V_152 ,
unsigned int V_249 , unsigned int V_250 )
{
int V_251 = 0 ;
unsigned long V_47 ;
int V_200 ;
struct V_6 * V_31 = V_152 -> V_154 ;
struct V_199 * V_68 ;
if ( ! V_31 ) {
F_20 ( L_53 ) ;
return - V_60 ;
}
if ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 )
return - V_60 ;
V_68 = V_31 -> V_36 -> V_68 ;
V_200 = V_68 -> V_201 -> V_202 . V_203 ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
if ( V_249 & V_176 )
V_31 -> V_247 = 1 ;
if ( V_249 & V_177 )
V_31 -> V_248 = 1 ;
if ( V_250 & V_176 )
V_31 -> V_247 = 0 ;
if ( V_250 & V_177 )
V_31 -> V_248 = 0 ;
if ( V_31 -> V_248 )
V_251 |= 0x01 ;
if ( V_31 -> V_247 )
V_251 |= 0x02 ;
F_14 ( & V_31 -> V_165 , V_47 ) ;
return F_113 ( V_31 -> V_36 -> V_88 ,
F_114 ( V_31 -> V_36 -> V_88 , 0 ) , 0x22 ,
0x21 , V_251 , V_200 , NULL , 0 ,
V_252 ) ;
}
static int F_115 ( struct V_151 * V_152 ,
unsigned int V_253 , unsigned long V_228 )
{
struct V_6 * V_31 = V_152 -> V_154 ;
int V_233 = 0 ;
F_64 ( L_54 , V_253 , V_228 ) ;
if ( ! V_31 )
return - V_54 ;
switch ( V_253 ) {
case V_254 :
V_233 = F_101 ( V_31 , V_228 ) ;
break;
default:
V_233 = - V_255 ;
break;
}
return V_233 ;
}
static void F_89 ( struct V_6 * V_31 )
{
T_5 * V_256 ;
unsigned long V_47 ;
int V_257 ;
F_13 ( & V_31 -> V_165 , V_47 ) ;
if ( ! V_31 -> V_181 )
goto V_182;
if ( V_31 -> V_258 )
goto V_182;
if ( F_36 ( V_31 -> V_36 ) == - V_61 )
goto V_182;
V_256 = V_31 -> V_183 ;
V_31 -> V_183 = V_31 -> V_259 ;
V_31 -> V_259 = V_256 ;
V_31 -> V_260 = V_31 -> V_181 ;
V_31 -> V_181 = 0 ;
if ( V_256 && V_31 -> V_261 ) {
V_257 = V_31 -> V_261 ( V_31 ) ;
if ( V_257 >= 0 )
V_31 -> V_258 = 1 ;
}
V_182:
F_14 ( & V_31 -> V_165 , V_47 ) ;
}
static int F_116 ( struct V_6 * V_31 , T_5 type , T_6 V_40 ,
struct V_32 * V_262 ,
struct V_263 * V_264 ,
T_5 * V_265 , T_2 V_266 )
{
int V_38 ;
int V_267 ;
if ( ! V_31 || ! V_262 || ! V_264 ) {
F_16 ( V_49 L_55 , V_50 ) ;
return - V_60 ;
}
V_264 -> V_208 = 0 ;
V_264 -> V_210 = F_117 ( F_10 ( V_40 ) ) ;
V_264 -> V_211 = F_117 ( V_266 ) ;
if ( type == V_268 ) {
V_264 -> V_269 = V_270 |
V_271 |
V_272 ;
V_264 -> V_273 = V_268 ;
V_267 = F_114 ( V_31 -> V_36 -> V_88 , 0 ) ;
} else {
V_264 -> V_269 = V_274 |
V_271 |
V_272 ;
V_264 -> V_273 = V_275 ;
V_267 = F_118 ( V_31 -> V_36 -> V_88 , 0 ) ;
}
F_119 ( L_56 ,
type == V_268 ? L_57 : L_58 ,
V_264 -> V_269 , V_264 -> V_211 , V_40 ) ;
V_262 -> V_91 = 0 ;
F_120 ( V_262 ,
V_31 -> V_36 -> V_88 ,
V_267 ,
( T_5 * ) V_264 ,
V_265 , V_266 , V_276 , V_31 ) ;
V_38 = F_40 ( V_262 , V_93 ) ;
if ( V_38 ) {
F_8 ( & V_262 -> V_15 -> V_15 ,
L_59 , V_50 ,
V_38 , type ) ;
return V_38 ;
}
return V_266 ;
}
static int F_70 ( struct V_6 * V_31 )
{
if ( ! V_31 )
return - V_60 ;
memset ( V_31 -> V_277 [ 0 ] , 0 , V_278 ) ;
if ( V_31 -> V_34 != 1 ) {
F_8 ( & V_31 -> V_36 -> V_68 -> V_15 ,
L_60
L_61 ) ;
return 0 ;
}
return F_116 ( V_31 ,
V_268 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_35 [ 0 ] ,
& V_31 -> V_279 ,
V_31 -> V_277 [ 0 ] , V_31 -> V_156 ) ;
}
static void F_121 ( struct V_32 * V_32 )
{
struct V_41 * V_42 = V_32 -> V_80 ;
struct V_6 * V_31 ;
unsigned char * V_280 ;
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
V_280 = V_32 -> V_120 ;
F_64 ( L_63 , * V_280 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( * V_280 & ( 1 << V_43 ) ) {
V_31 = F_11 ( V_42 ,
( 1 << V_43 ) ) ;
if ( V_31 != NULL ) {
F_20 ( L_64 , V_43 ) ;
F_58 ( & V_31 -> V_165 ) ;
if ( V_31 -> V_161 == V_164 &&
V_31 -> V_40 . V_100 > 0 ) {
if ( ! V_31 -> V_159 [ 0 ] ) {
V_31 -> V_161 = V_163 ;
F_70 ( V_31 ) ;
} else
V_31 -> V_161 = V_162 ;
} else {
F_20 ( L_65
L_66 , V_43 ) ;
}
F_59 ( & V_31 -> V_165 ) ;
}
}
}
F_122 ( V_42 , V_32 -> V_15 , V_93 ) ;
}
static int F_123 ( struct V_6 * V_31 )
{
if ( NULL == V_31 )
return - V_60 ;
return F_116 ( V_31 ,
V_275 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_281 ,
& V_31 -> V_282 ,
V_31 -> V_259 , V_31 -> V_260 ) ;
}
static void F_124 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_31 ) {
F_20 ( L_43 ) ;
return;
}
F_58 ( & V_31 -> V_165 ) ;
V_31 -> V_258 = 0 ;
F_59 ( & V_31 -> V_165 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
F_33 ( V_31 -> V_36 ) ;
F_125 ( & V_31 -> V_40 ) ;
F_89 ( V_31 ) ;
F_20 ( L_36 ) ;
}
static int F_126 ( struct V_6 * V_31 )
{
int V_100 = V_31 -> V_260 ;
int V_38 ;
F_38 ( V_31 -> V_281 ,
V_31 -> V_36 -> V_88 ,
F_39 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_89 ->
V_90 & 0x7F ) ,
V_31 -> V_259 , V_31 -> V_260 ,
F_124 , V_31 ) ;
V_38 = F_40 ( V_31 -> V_281 , V_93 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_67 , V_38 ) ;
return V_38 ;
}
return V_100 ;
}
static void V_276 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_80 ;
struct V_263 * V_283 ;
int V_51 = V_32 -> V_51 ;
if ( ! V_31 )
return;
F_58 ( & V_31 -> V_165 ) ;
V_31 -> V_258 = 0 ;
F_59 ( & V_31 -> V_165 ) ;
if ( V_51 ) {
F_18 ( V_51 , V_50 , V_31 -> V_36 ) ;
return;
}
V_283 = (struct V_263 * ) ( V_32 -> V_284 ) ;
F_64 ( L_68 , V_51 ) ;
F_64 ( L_69 , V_32 -> V_119 ) ;
F_37 ( V_32 -> V_120 , V_32 -> V_119 ) ;
if ( V_283 -> V_269 ==
( V_270 | V_271 | V_272 ) ) {
V_31 -> V_159 [ 0 ] = 1 ;
F_58 ( & V_31 -> V_165 ) ;
F_69 ( V_31 ) ;
F_59 ( & V_31 -> V_165 ) ;
} else {
F_33 ( V_31 -> V_36 ) ;
F_125 ( & V_31 -> V_40 ) ;
F_89 ( V_31 ) ;
}
}
static int F_68 ( struct V_32 * V_32 , struct V_6 * V_31 )
{
struct V_151 * V_152 ;
int V_100 ;
if ( V_32 == NULL || V_31 == NULL ) {
F_20 ( L_70 ) ;
return - 2 ;
}
V_152 = F_127 ( & V_31 -> V_40 ) ;
if ( V_152 && F_31 ( V_285 , & V_152 -> V_47 ) ) {
F_128 ( V_152 ) ;
return - 1 ;
}
F_20 ( L_71 ) ;
V_100 = F_129 ( & V_31 -> V_40 , V_32 -> V_119 ) ;
if ( V_100 >= V_32 -> V_119 ) {
F_130 ( & V_31 -> V_40 , V_32 -> V_120 ,
V_32 -> V_119 ) ;
F_131 ( & V_31 -> V_40 ) ;
} else {
F_41 ( & V_31 -> V_36 -> V_88 -> V_15 ,
L_72 , V_32 -> V_119 ) ;
}
F_128 ( V_152 ) ;
V_31 -> V_159 [ F_7 ( V_31 , V_32 ) ] = 0 ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
char * V_286 ;
char V_287 [ 20 ] ;
switch ( V_3 -> V_19 & V_20 ) {
case V_21 :
V_286 = L_2 ;
break;
case V_22 :
V_286 = L_3 ;
break;
case V_24 :
V_286 = L_5 ;
break;
case V_25 :
V_286 = L_73 ;
break;
case V_23 :
V_286 = L_4 ;
break;
case V_26 :
V_286 = L_7 ;
break;
case V_27 :
V_286 = L_8 ;
break;
case V_28 :
V_286 = L_9 ;
break;
case V_29 :
V_286 = L_10 ;
break;
case V_30 :
V_286 = L_11 ;
break;
default:
V_286 = L_12 ;
break;
}
if ( ( V_3 -> V_19 & V_20 ) == V_30 ) {
sprintf ( V_287 , L_74 , F_1 ( V_3 ) -> V_70 -> V_12 ) ;
} else
sprintf ( V_287 , L_75 , V_288 ,
F_2 ( V_3 ) -> V_155 ) ;
F_133 ( & V_3 -> V_68 -> V_15 , L_76 ,
V_286 , V_287 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ ) {
F_38 ( V_1 -> V_290 [ V_43 ] ,
V_3 -> V_88 ,
F_60 ( V_3 -> V_88 ,
V_1 -> V_122 ->
V_90 & 0x7F ) ,
V_1 -> V_291 [ V_43 ] ,
V_125 , F_56 ,
V_1 ) ;
V_38 = F_40 ( V_1 -> V_290 [ V_43 ] ,
V_292 ) ;
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
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ ) {
if ( V_1 -> V_290 [ V_43 ] )
F_134 ( V_1 -> V_290 [ V_43 ] ) ;
}
if ( V_1 -> V_87 )
F_134 ( V_1 -> V_87 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 , T_7 V_47 )
{
int V_43 , V_38 = 0 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return - V_54 ;
if ( ! ( V_31 -> V_36 -> V_19 & V_166 ) ) {
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_38 ( V_31 -> V_35 [ V_43 ] ,
V_31 -> V_36 -> V_88 ,
F_60 ( V_31 -> V_36 -> V_88 ,
V_31 -> V_122 ->
V_90 &
0x7F ) ,
V_31 -> V_277 [ V_43 ] ,
V_31 -> V_156 ,
V_157 ,
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
F_76 ( & V_31 -> V_42 -> V_293 ) ;
if ( ! V_31 -> V_42 -> V_294 ) {
V_38 =
F_122 ( V_31 -> V_42 ,
V_3 -> V_88 , V_47 ) ;
}
V_31 -> V_42 -> V_294 ++ ;
F_85 ( & V_31 -> V_42 -> V_293 ) ;
}
if ( V_31 -> V_188 )
F_96 ( V_31 ,
V_31 -> V_188 ,
V_31 -> V_36 -> V_88 ) ;
return V_38 ;
}
static int F_81 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
struct V_187 * V_188 ;
if ( ! V_31 )
return - V_54 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
if ( V_31 -> V_35 [ V_43 ] ) {
F_134 ( V_31 -> V_35 [ V_43 ] ) ;
V_31 -> V_159 [ V_43 ] = 0 ;
}
}
V_31 -> V_160 = 0 ;
if ( V_31 -> V_281 )
F_134 ( V_31 -> V_281 ) ;
if ( V_31 -> V_42 ) {
F_76 ( & V_31 -> V_42 -> V_293 ) ;
if ( V_31 -> V_42 -> V_294 &&
( -- V_31 -> V_42 -> V_294 == 0 ) ) {
struct V_32 * V_32 ;
V_32 = V_31 -> V_42 -> V_295 ;
if ( V_32 )
F_134 ( V_32 ) ;
}
F_85 ( & V_31 -> V_42 -> V_293 ) ;
}
V_188 = V_31 -> V_188 ;
if ( V_188 ) {
F_100 ( & V_188 -> V_227 ) ;
F_134 ( V_188 -> V_32 ) ;
}
return 0 ;
}
static void F_135 ( struct V_6 * V_31 )
{
F_136 ( V_296 , V_31 -> V_155 ) ;
}
static void F_137 ( struct V_6 * V_31 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_138 ( V_31 -> V_35 [ V_43 ] ) ;
F_139 ( V_31 -> V_277 [ V_43 ] ) ;
}
F_138 ( V_31 -> V_281 ) ;
F_139 ( V_31 -> V_183 ) ;
F_139 ( V_31 -> V_259 ) ;
F_140 ( & V_31 -> V_40 ) ;
}
static int F_141 ( struct V_6 * V_31 , int V_297 ,
int V_298 , int V_299 )
{
struct V_14 * V_15 ;
int V_155 ;
int V_43 ;
F_142 ( & V_31 -> V_40 ) ;
V_155 = F_15 () ;
if ( V_155 < 0 )
goto exit;
V_31 -> V_36 -> V_15 = F_143 ( & V_31 -> V_40 ,
V_296 , V_155 , & V_31 -> V_36 -> V_68 -> V_15 ,
V_31 -> V_36 , V_300 ) ;
V_15 = V_31 -> V_36 -> V_15 ;
V_31 -> V_155 = V_155 ;
V_31 -> V_170 = V_171 ;
F_144 ( & V_31 -> V_165 ) ;
V_31 -> V_34 = V_297 ;
V_31 -> V_156 = V_298 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
V_31 -> V_35 [ V_43 ] = F_145 ( 0 , V_174 ) ;
if ( ! V_31 -> V_35 [ V_43 ] ) {
F_8 ( V_15 , L_78 ) ;
goto exit;
}
V_31 -> V_35 [ V_43 ] -> V_120 = NULL ;
V_31 -> V_35 [ V_43 ] -> V_124 = 0 ;
V_31 -> V_277 [ V_43 ] = F_146 ( V_31 -> V_156 ,
V_174 ) ;
if ( ! V_31 -> V_277 [ V_43 ] )
goto exit;
}
V_31 -> V_281 = F_145 ( 0 , V_174 ) ;
if ( ! V_31 -> V_281 ) {
F_8 ( V_15 , L_78 ) ;
goto exit;
}
V_31 -> V_281 -> V_120 = NULL ;
V_31 -> V_281 -> V_124 = 0 ;
V_31 -> V_260 = 0 ;
V_31 -> V_181 = 0 ;
V_31 -> V_180 = V_299 ;
V_31 -> V_259 = F_146 ( V_31 -> V_180 , V_174 ) ;
if ( ! V_31 -> V_259 )
goto exit;
V_31 -> V_183 = F_146 ( V_31 -> V_180 , V_174 ) ;
if ( ! V_31 -> V_183 )
goto exit;
return 0 ;
exit:
F_135 ( V_31 ) ;
F_137 ( V_31 ) ;
return - 1 ;
}
static struct V_2 * F_147 ( struct V_199 * V_301 ,
int V_19 )
{
struct V_2 * V_3 ;
V_3 = F_146 ( sizeof( * V_3 ) , V_93 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_88 = F_148 ( V_301 ) ;
V_3 -> V_68 = V_301 ;
F_149 ( & V_3 -> V_175 ) ;
F_150 ( & V_3 -> V_172 ) ;
F_151 ( & V_3 -> V_302 , V_302 ) ;
F_151 ( & V_3 -> V_303 , V_303 ) ;
return V_3 ;
}
static int F_152 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
if ( V_305 [ V_43 ] == V_3 ) {
V_305 [ V_43 ] = NULL ;
break;
}
}
if ( V_43 == V_304 )
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
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ ) {
F_138 ( V_1 -> V_290 [ V_43 ] ) ;
F_139 ( V_1 -> V_291 [ V_43 ] ) ;
V_1 -> V_291 [ V_43 ] = NULL ;
}
F_138 ( V_1 -> V_87 ) ;
F_139 ( V_1 -> V_85 ) ;
V_1 -> V_85 = NULL ;
if ( V_1 -> V_70 )
F_155 ( V_1 -> V_70 ) ;
F_139 ( V_3 ) ;
}
static void F_156 ( struct V_69 * V_70 )
{
struct V_1 * V_1 = F_22 ( V_70 ) ;
F_20 ( L_79 , ( int ) sizeof( * V_1 ) ) ;
V_70 -> V_306 = & V_307 ;
V_70 -> V_308 = V_309 ;
V_70 -> V_47 = V_310 | V_311 | V_312 ;
V_70 -> type = V_313 ;
V_70 -> V_314 = V_315 - 14 ;
V_70 -> V_316 = 10 ;
V_70 -> V_317 = & V_318 ;
F_144 ( & V_1 -> V_73 ) ;
}
static int F_157 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
if ( V_305 [ V_43 ] == NULL ) {
V_305 [ V_43 ] = V_3 ;
break;
}
}
if ( V_43 == V_304 )
return - 1 ;
return 0 ;
}
static int F_158 ( void * V_84 , bool V_319 )
{
struct V_2 * V_3 = V_84 ;
int V_320 = ! V_319 ;
int V_321 ;
F_76 ( & V_3 -> V_172 ) ;
if ( V_3 -> V_178 )
V_321 = 0 ;
else
V_321 = F_113 ( V_3 -> V_88 , F_114 ( V_3 -> V_88 , 0 ) ,
V_320 ? 0x82 : 0x81 , 0x40 , 0 , 0 , NULL , 0 ,
V_252 ) ;
F_85 ( & V_3 -> V_172 ) ;
return V_321 ;
}
static void F_159 ( struct V_2 * V_3 ,
struct V_199 * V_68 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_14 * V_15 = & V_1 -> V_70 -> V_15 ;
static T_2 V_322 ;
snprintf ( V_1 -> V_12 , sizeof( V_1 -> V_12 ) , L_80 ,
V_322 ++ ) ;
V_1 -> V_323 = F_160 ( V_1 -> V_12 ,
& F_148 ( V_68 ) -> V_15 ,
V_324 ,
& V_325 , V_3 ) ;
if ( ! V_1 -> V_323 ) {
F_8 ( V_15 , L_81 , V_50 ) ;
return;
}
if ( F_161 ( V_1 -> V_323 ) < 0 ) {
F_162 ( V_1 -> V_323 ) ;
V_1 -> V_323 = NULL ;
F_8 ( V_15 , L_82 , V_50 ) ;
return;
}
}
static struct V_2 * F_163 ( struct V_199 * V_68 ,
int V_19 )
{
int V_38 , V_43 ;
struct V_69 * V_70 ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
V_3 = F_147 ( V_68 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_70 = F_164 ( sizeof( struct V_1 ) , L_83 , V_326 ,
F_156 ) ;
if ( ! V_70 ) {
F_8 ( & V_68 -> V_15 , L_84 ) ;
goto exit;
}
V_1 = F_22 ( V_70 ) ;
V_3 -> V_4 . V_5 = V_1 ;
V_1 -> V_70 = V_70 ;
V_1 -> V_36 = V_3 ;
V_1 -> V_122 = F_165 ( V_68 , V_327 ,
V_270 ) ;
if ( ! V_1 -> V_122 ) {
F_8 ( & V_68 -> V_15 , L_85 ) ;
goto exit;
}
V_1 -> V_89 = F_165 ( V_68 , V_327 ,
V_274 ) ;
if ( ! V_1 -> V_89 ) {
F_8 ( & V_68 -> V_15 , L_86 ) ;
goto exit;
}
F_166 ( V_70 , & V_68 -> V_15 ) ;
F_167 ( V_70 , & V_328 ) ;
V_38 = F_168 ( V_70 ) ;
if ( V_38 ) {
F_8 ( & V_68 -> V_15 , L_87 ) ;
goto exit;
}
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ ) {
V_1 -> V_290 [ V_43 ] = F_145 ( 0 , V_174 ) ;
if ( ! V_1 -> V_290 [ V_43 ] ) {
F_8 ( & V_68 -> V_15 , L_88 ) ;
goto exit;
}
V_1 -> V_291 [ V_43 ] = F_146 ( V_125 ,
V_174 ) ;
if ( ! V_1 -> V_291 [ V_43 ] )
goto exit;
}
V_1 -> V_87 = F_145 ( 0 , V_174 ) ;
if ( ! V_1 -> V_87 ) {
F_8 ( & V_68 -> V_15 , L_89 ) ;
goto exit;
}
V_1 -> V_85 = F_146 ( V_86 , V_174 ) ;
if ( ! V_1 -> V_85 )
goto exit;
F_157 ( V_3 ) ;
F_132 ( V_3 ) ;
F_159 ( V_3 , V_68 ) ;
return V_3 ;
exit:
F_153 ( V_3 ) ;
return NULL ;
}
static void F_169 ( struct V_6 * V_31 )
{
struct V_187 * V_188 ;
if ( ! V_31 )
return;
V_188 = V_31 -> V_188 ;
if ( V_188 ) {
F_138 ( V_188 -> V_32 ) ;
V_188 -> V_32 = NULL ;
V_31 -> V_188 = NULL ;
F_139 ( V_188 ) ;
}
}
static void F_170 ( struct V_2 * V_3 )
{
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return;
F_137 ( V_31 ) ;
if ( V_31 -> V_42 ) {
F_76 ( & V_31 -> V_42 -> V_293 ) ;
if ( -- V_31 -> V_42 -> V_329 == 0 )
F_171 ( V_31 -> V_42 ) ;
else
F_85 ( & V_31 -> V_42 -> V_293 ) ;
}
F_169 ( V_31 ) ;
F_139 ( V_31 ) ;
F_139 ( V_3 ) ;
}
static struct V_2 * F_172 (
struct V_199 * V_68 , int V_40 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_297 ;
struct V_187 * V_188 ;
V_3 = F_147 ( V_68 , V_40 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_146 ( sizeof( * V_31 ) , V_174 ) ;
if ( ! V_31 )
goto exit;
V_31 -> V_36 = V_3 ;
V_3 -> V_4 . V_7 = V_31 ;
if ( ( V_40 & V_20 ) == V_29 ) {
V_297 = 2 ;
V_31 -> V_188 = F_146 ( sizeof( struct V_187 ) ,
V_174 ) ;
if ( V_31 -> V_188 ) {
V_188 = V_31 -> V_188 ;
V_188 -> V_32 = F_145 ( 0 , V_174 ) ;
if ( V_188 -> V_32 ) {
F_150 ( & V_188 -> V_172 ) ;
F_173 ( & V_188 -> V_227 ) ;
V_188 -> V_190 = F_165 (
V_68 ,
V_330 ,
V_270 ) ;
} else
F_169 ( V_31 ) ;
}
}
else
V_297 = 1 ;
if ( F_141 ( V_31 , V_297 , V_331 ,
V_332 ) )
goto exit;
V_31 -> V_122 = F_165 ( V_68 , V_327 ,
V_270 ) ;
if ( ! V_31 -> V_122 ) {
F_8 ( & V_68 -> V_15 , L_90 ) ;
goto V_333;
}
if ( !
( V_31 -> V_89 =
F_165 ( V_68 , V_327 , V_274 ) ) ) {
F_8 ( & V_68 -> V_15 , L_90 ) ;
goto V_333;
}
V_31 -> V_261 = F_126 ;
F_17 ( V_31 -> V_155 , V_31 ) ;
F_132 ( V_3 ) ;
return V_3 ;
V_333:
F_135 ( V_31 ) ;
F_137 ( V_31 ) ;
exit:
F_169 ( V_31 ) ;
F_139 ( V_31 ) ;
F_139 ( V_3 ) ;
return NULL ;
}
static
struct V_2 * F_174 ( struct V_199 * V_68 ,
int V_40 ,
struct V_41 * V_37 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_19 ;
V_19 = V_166 ;
V_19 &= ~ V_20 ;
V_19 |= F_9 ( V_40 ) ;
if ( ( V_19 & V_20 ) == V_39 )
return NULL ;
V_3 = F_147 ( V_68 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_146 ( sizeof( * V_31 ) , V_174 ) ;
if ( ! V_31 )
goto exit;
V_3 -> V_4 . V_7 = V_31 ;
V_31 -> V_36 = V_3 ;
if ( F_141
( V_31 , 1 , V_278 , V_334 ) )
goto exit;
V_31 -> V_180 -- ;
V_31 -> V_261 = F_123 ;
V_31 -> V_42 = V_37 ;
F_76 ( & V_31 -> V_42 -> V_293 ) ;
V_31 -> V_42 -> V_329 ++ ;
F_85 ( & V_31 -> V_42 -> V_293 ) ;
F_17 ( V_31 -> V_155 , V_31 ) ;
F_132 ( V_3 ) ;
return V_3 ;
exit:
if ( V_31 ) {
F_136 ( V_296 , V_31 -> V_155 ) ;
F_139 ( V_31 ) ;
}
F_139 ( V_3 ) ;
return NULL ;
}
static void F_171 ( struct V_41 * V_37 )
{
F_138 ( V_37 -> V_295 ) ;
F_139 ( V_37 -> V_335 ) ;
F_85 ( & V_37 -> V_293 ) ;
F_139 ( V_37 ) ;
}
static
struct V_41 * F_175 ( struct V_199 * V_68 )
{
struct V_41 * V_37 = F_146 ( sizeof( * V_37 ) , V_174 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_336 = F_165 ( V_68 , V_330 ,
V_270 ) ;
if ( ! V_37 -> V_336 ) {
F_8 ( & V_68 -> V_15 , L_91 ) ;
goto exit;
}
V_37 -> V_295 = F_145 ( 0 , V_174 ) ;
if ( ! V_37 -> V_295 ) {
F_8 ( & V_68 -> V_15 , L_92 ) ;
goto exit;
}
V_37 -> V_335 =
F_146 ( F_55 ( V_37 -> V_336 -> V_123 ) ,
V_174 ) ;
if ( ! V_37 -> V_335 )
goto exit;
F_150 ( & V_37 -> V_293 ) ;
return V_37 ;
exit:
F_139 ( V_37 -> V_335 ) ;
F_138 ( V_37 -> V_295 ) ;
F_139 ( V_37 ) ;
return NULL ;
}
static int F_176 ( struct V_199 * V_68 )
{
struct V_189 * V_337 = F_148 ( V_68 ) ;
T_5 * V_338 = F_177 ( 17 , V_174 ) ;
T_2 V_200 = V_68 -> V_201 -> V_202 . V_203 ;
T_8 V_38 ;
if ( ! V_338 )
return - V_339 ;
if ( F_113 ( V_337 , F_114 ( V_337 , 0 ) ,
0x86 , 0xC0 , 0 , 0 , V_338 , 17 ,
V_252 ) != 0x11 ) {
F_139 ( V_338 ) ;
return - V_340 ;
}
switch ( V_338 [ V_200 ] ) {
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
V_38 = V_341 ;
break;
case 0xa :
V_38 = V_26 ;
break;
case 0xb :
V_38 = V_342 ;
break;
default:
V_38 = 0 ;
}
if ( V_38 )
V_38 |= V_343 ;
if ( V_338 [ 16 ] & 0x1 )
V_38 |= V_121 ;
F_139 ( V_338 ) ;
return V_38 ;
}
static int F_178 ( struct V_199 * V_68 ,
const struct V_344 * V_345 )
{
int V_37 , V_43 , V_200 , V_19 ;
unsigned char V_346 ;
struct V_2 * V_3 = NULL ;
struct V_41 * V_42 ;
struct V_2 * V_347 = NULL ;
if ( V_68 -> V_201 -> V_202 . V_348 != 0xFF ) {
F_8 ( & V_68 -> V_15 , L_93 ) ;
return - V_54 ;
}
V_200 = V_68 -> V_201 -> V_202 . V_203 ;
if ( V_345 -> V_349 )
V_19 = ( ( T_2 * ) ( V_345 -> V_349 ) ) [ V_200 ] ;
else
V_19 = F_176 ( V_68 ) ;
if ( V_68 -> V_350 > 1 )
F_179 ( F_148 ( V_68 ) , V_200 , 1 ) ;
V_68 -> V_351 = 1 ;
switch ( V_19 & V_352 ) {
case V_166 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_353 ) {
V_3 = F_163 ( V_68 ,
V_19 ) ;
if ( ! V_3 )
goto exit;
V_347 = V_3 ;
}
}
if ( F_180 ( V_68 , & V_346 ) )
goto exit;
V_42 = F_175 ( V_68 ) ;
if ( ! V_42 )
goto exit;
for ( V_43 = 1 , V_37 = 0 ; V_43 < 0x100 ; V_43 = V_43 << 1 , V_37 ++ ) {
if ( V_346 & V_43 ) {
V_3 = F_174 (
V_68 , V_43 , V_42 ) ;
if ( ! V_3 )
goto exit;
}
}
if ( V_347 )
V_3 = V_347 ;
break;
case V_343 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_353 )
V_3 =
F_163 ( V_68 , V_19 ) ;
} else {
V_3 =
F_172 ( V_68 , V_19 ) ;
}
if ( ! V_3 )
goto exit;
break;
default:
goto exit;
}
F_181 ( V_68 , V_3 ) ;
return 0 ;
exit:
F_182 ( V_68 ) ;
return - V_54 ;
}
static void F_183 ( struct V_199 * V_68 )
{
F_182 ( V_68 ) ;
F_181 ( V_68 , NULL ) ;
}
static void V_302 ( struct V_354 * V_84 )
{
struct V_2 * V_3 =
F_184 ( V_84 , struct V_2 , V_302 ) ;
F_77 ( V_3 -> V_68 ) ;
}
static void V_303 ( struct V_354 * V_84 )
{
struct V_2 * V_3 =
F_184 ( V_84 , struct V_2 , V_303 ) ;
F_83 ( V_3 -> V_68 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_355 == V_356 ) {
if ( ! V_3 -> V_357 ) {
V_3 -> V_357 = 1 ;
F_185 ( & V_3 -> V_302 ) ;
}
}
if ( V_3 -> V_88 -> V_355 != V_358 )
return - V_61 ;
F_57 ( V_3 -> V_88 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( V_3 -> V_88 -> V_355 != V_356 ) {
if ( V_3 -> V_357 ) {
V_3 -> V_357 = 0 ;
F_185 ( & V_3 -> V_303 ) ;
return - V_61 ;
}
}
V_3 -> V_357 = 0 ;
return 0 ;
}
static int F_186 ( struct V_199 * V_359 , T_9 V_360 )
{
int V_43 , V_38 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_68 == V_359 ) ) {
V_38 = F_81 ( V_45 [ V_43 ] ) ;
if ( V_38 )
goto V_182;
}
}
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
if ( V_305 [ V_43 ] &&
( V_305 [ V_43 ] -> V_68 == V_359 ) ) {
V_38 = F_29 ( V_305 [ V_43 ] ) ;
if ( V_38 )
goto V_182;
}
}
V_182:
return 0 ;
}
static int F_187 ( struct V_199 * V_359 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_68 == V_359 ) ) {
if ( F_2 ( V_45 [ V_43 ] ) -> V_40 . V_100 ) {
V_38 =
F_80 ( V_45 [ V_43 ] , V_292 ) ;
F_89 ( F_2 ( V_45 [ V_43 ] ) ) ;
if ( V_38 )
goto V_182;
}
}
}
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
if ( V_305 [ V_43 ] &&
( V_305 [ V_43 ] -> V_68 == V_359 ) ) {
V_1 = F_1 ( V_305 [ V_43 ] ) ;
if ( V_1 -> V_47 & V_361 ) {
if ( V_1 -> V_72 ) {
F_133 ( & V_359 -> V_15 ,
L_94
L_95 ) ;
F_35 ( V_1 -> V_72 ,
V_1 -> V_70 ) ;
V_1 -> V_72 = NULL ;
}
V_38 = F_24 ( V_305 [ V_43 ] ) ;
if ( V_38 )
goto V_182;
}
}
}
V_182:
return V_38 ;
}
static void V_185 ( struct V_362 * V_175 )
{
struct V_2 * V_3 = F_184 ( V_175 , struct V_2 , V_175 ) ;
F_170 ( V_3 ) ;
}
static void F_182 ( struct V_199 * V_68 )
{
struct V_6 * V_31 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] &&
( V_45 [ V_43 ] -> V_68 == V_68 ) ) {
V_31 = F_2 ( V_45 [ V_43 ] ) ;
F_188 ( & V_31 -> V_40 , false ) ;
F_76 ( & V_31 -> V_36 -> V_172 ) ;
V_31 -> V_36 -> V_178 = 1 ;
F_85 ( & V_31 -> V_36 -> V_172 ) ;
F_189 ( & V_45 [ V_43 ] -> V_303 ) ;
F_189 ( & V_45 [ V_43 ] -> V_302 ) ;
F_135 ( V_31 ) ;
F_92 ( & V_45 [ V_43 ] -> V_175 , V_185 ) ;
F_17 ( V_43 , NULL ) ;
}
}
for ( V_43 = 0 ; V_43 < V_304 ; V_43 ++ ) {
if ( V_305 [ V_43 ] &&
( V_305 [ V_43 ] -> V_68 == V_68 ) ) {
struct V_323 * V_363 = F_1 ( V_305 [ V_43 ] ) -> V_323 ;
F_27 ( F_1 ( V_305 [ V_43 ] ) -> V_70 ) ;
F_29 ( V_305 [ V_43 ] ) ;
F_189 ( & V_305 [ V_43 ] -> V_303 ) ;
F_189 ( & V_305 [ V_43 ] -> V_302 ) ;
if ( V_363 ) {
F_190 ( V_363 ) ;
F_162 ( V_363 ) ;
}
F_153 ( V_305 [ V_43 ] ) ;
}
}
}
static struct V_364 * F_165 ( struct V_199 * V_301 ,
int type , int V_365 )
{
int V_43 ;
struct V_366 * V_359 = V_301 -> V_201 ;
struct V_364 * V_190 ;
for ( V_43 = 0 ; V_43 < V_359 -> V_202 . V_367 ; V_43 ++ ) {
V_190 = & V_359 -> V_368 [ V_43 ] . V_202 ;
if ( ( ( V_190 -> V_90 & V_369 ) == V_365 ) &&
( F_191 ( V_190 ) == type ) )
return V_190 ;
}
return NULL ;
}
static int F_180 ( struct V_199 * V_301 , unsigned char * V_370 )
{
int V_43 ;
struct V_366 * V_359 = V_301 -> V_201 ;
if ( V_359 -> V_371 == 3 ) {
* V_370 = V_359 -> V_372 [ 2 ] ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_359 -> V_202 . V_367 ; V_43 ++ ) {
if ( V_359 -> V_368 [ V_43 ] . V_371 == 3 ) {
* V_370 = V_359 -> V_368 [ V_43 ] . V_372 [ 2 ] ;
return 0 ;
}
}
return - 1 ;
}
static int F_122 ( struct V_41 * V_42 ,
struct V_189 * V_88 , T_7 V_373 )
{
int V_38 ;
F_97 ( V_42 -> V_295 , V_88 ,
F_98 ( V_88 ,
V_42 -> V_336 -> V_90 & 0x7F ) ,
V_42 -> V_335 ,
1 ,
F_121 , V_42 ,
V_42 -> V_336 -> V_194 ) ;
V_38 = F_40 ( V_42 -> V_295 , V_373 ) ;
if ( V_38 )
F_41 ( & V_88 -> V_15 , L_96 , V_50 ,
V_38 ) ;
return V_38 ;
}
static int T_10 F_192 ( void )
{
int V_43 ;
int V_38 ;
F_16 ( V_374 L_97 , V_375 ) ;
F_144 ( & V_48 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
V_45 [ V_43 ] = NULL ;
V_296 = F_193 ( V_44 ) ;
if ( ! V_296 )
return - V_339 ;
V_296 -> V_376 = V_376 ;
V_296 -> V_12 = V_288 ;
if ( V_377 )
V_296 -> V_378 = V_377 ;
V_296 -> V_379 = 0 ;
V_296 -> type = V_380 ;
V_296 -> V_381 = V_382 ;
V_296 -> V_47 = V_383 | V_384 ;
V_296 -> V_385 = V_386 ;
F_61 ( & V_296 -> V_385 ) ;
F_194 ( V_296 , & V_387 ) ;
V_38 = F_195 ( V_296 ) ;
if ( V_38 ) {
F_16 ( V_49 L_98 ,
V_50 , V_38 ) ;
goto V_388;
}
V_38 = F_196 ( & V_389 ) ;
if ( V_38 ) {
F_16 ( V_49 L_99 ,
V_38 ) ;
goto V_390;
}
return 0 ;
V_390:
F_197 ( V_296 ) ;
V_388:
F_198 ( V_296 ) ;
return V_38 ;
}
static void T_11 F_199 ( void )
{
F_16 ( V_374 L_100 ) ;
F_197 ( V_296 ) ;
F_198 ( V_296 ) ;
F_200 ( & V_389 ) ;
}
