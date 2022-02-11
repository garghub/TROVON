static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 )
return V_3 -> V_4 ;
return NULL ;
}
static inline struct V_5 * F_2 ( struct V_6 * V_7 )
{
return V_7 -> V_8 . V_9 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
return V_7 -> V_8 . V_10 ;
}
static void F_4 ( int V_11 , const char * V_12 , unsigned char * V_13 ,
unsigned int V_14 )
{
static char V_15 [ 255 ] ;
sprintf ( V_15 , L_1 , V_11 , V_12 ) ;
F_5 ( V_15 , V_16 , V_13 , V_14 ) ;
}
static T_1 F_6 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_13 )
{
struct V_6 * V_7 = F_7 ( V_18 ) ;
char * V_21 ;
if ( ! V_7 )
return 0 ;
switch ( V_7 -> V_22 & V_23 ) {
case V_24 :
V_21 = L_2 ;
break;
case V_25 :
V_21 = L_3 ;
break;
case V_26 :
V_21 = L_4 ;
break;
case V_27 :
V_21 = L_5 ;
break;
case V_28 :
V_21 = L_6 ;
break;
case V_29 :
V_21 = L_7 ;
break;
case V_30 :
V_21 = L_8 ;
break;
case V_31 :
V_21 = L_9 ;
break;
case V_32 :
V_21 = L_10 ;
break;
case V_33 :
V_21 = L_11 ;
break;
default:
V_21 = L_12 ;
break;
}
return sprintf ( V_13 , L_13 , V_21 ) ;
}
static int F_8 ( struct V_1 * V_34 , struct V_35 * V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_37 ; V_36 ++ )
if ( V_34 -> V_38 [ V_36 ] == V_35 )
return V_36 ;
F_9 ( V_34 -> V_39 -> V_18 , L_14 ) ;
return - 1 ;
}
static T_2 F_10 ( int V_40 )
{
T_2 V_41 ;
switch ( V_40 ) {
case 0x1 :
V_41 = V_24 ;
break;
case 0x2 :
V_41 = V_25 ;
break;
case 0x4 :
V_41 = V_29 ;
break;
case 0x8 :
V_41 = V_27 ;
break;
case 0x10 :
V_41 = V_26 ;
break;
default:
V_41 = V_42 ;
}
return V_41 ;
}
static T_2 F_11 ( int V_43 )
{
T_2 V_41 ;
switch ( V_43 & V_23 ) {
case V_24 :
V_41 = 0x0 ;
break;
case V_25 :
V_41 = 0x1 ;
break;
case V_29 :
V_41 = 0x2 ;
break;
case V_27 :
V_41 = 0x3 ;
break;
case V_26 :
V_41 = 0x4 ;
break;
default:
V_41 = 0x0 ;
}
return V_41 ;
}
static struct V_1 * F_12 (
struct V_44 * V_45 ,
int V_40 )
{
int V_46 , V_43 ;
V_43 = F_10 ( V_40 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_48 [ V_46 ] &&
( F_3 ( V_48 [ V_46 ] ) -> V_45 == V_45 ) &&
( ( V_48 [ V_46 ] -> V_22 & V_23 ) == V_43 ) ) {
return F_3 ( V_48 [ V_46 ] ) ;
}
}
return NULL ;
}
static struct V_1 * F_13 ( unsigned V_49 )
{
struct V_1 * V_34 = NULL ;
unsigned long V_50 ;
F_14 ( & V_51 , V_50 ) ;
if ( V_48 [ V_49 ] )
V_34 = F_3 ( V_48 [ V_49 ] ) ;
F_15 ( & V_51 , V_50 ) ;
return V_34 ;
}
static int F_16 ( void )
{
int V_49 ;
unsigned long V_50 ;
F_14 ( & V_51 , V_50 ) ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ ) {
if ( V_48 [ V_49 ] == NULL ) {
F_15 ( & V_51 , V_50 ) ;
return V_49 ;
}
}
F_15 ( & V_51 , V_50 ) ;
F_17 ( V_52 L_15 , V_53 ) ;
return - 1 ;
}
static void F_18 ( unsigned V_49 , struct V_1 * V_34 )
{
unsigned long V_50 ;
F_14 ( & V_51 , V_50 ) ;
if ( V_34 )
V_48 [ V_49 ] = V_34 -> V_39 ;
else
V_48 [ V_49 ] = NULL ;
F_15 ( & V_51 , V_50 ) ;
}
static void F_19 ( int V_54 , const char * V_55 ,
struct V_6 * V_7 )
{
char * V_56 ;
switch ( V_54 ) {
case - V_57 :
V_56 = L_16 ;
break;
case - V_58 :
V_56 = L_17 ;
break;
case - V_59 :
V_56 = L_18 ;
break;
case - V_60 :
V_56 = L_19 ;
break;
case - V_61 :
V_56 = L_20 ;
break;
case - V_62 :
V_56 = L_21 ;
break;
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
V_56 = L_22 ;
break;
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
V_56 = L_23 ;
if ( V_7 )
F_20 ( & V_7 -> V_71 ) ;
break;
default:
V_56 = L_24 ;
break;
}
F_21 ( L_25 , V_55 , V_56 , V_54 ) ;
}
static int F_22 ( struct V_72 * V_73 )
{
struct V_5 * V_74 = F_23 ( V_73 ) ;
unsigned long V_50 = 0 ;
if ( ! V_74 ) {
F_9 ( & V_73 -> V_18 , L_26 ) ;
return - V_57 ;
}
V_74 -> V_75 = NULL ;
F_14 ( & V_74 -> V_76 , V_50 ) ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = sizeof( struct V_81 ) ;
F_15 ( & V_74 -> V_76 , V_50 ) ;
F_24 ( V_82 , & V_74 -> V_50 ) ;
F_25 ( V_74 -> V_39 ) ;
F_26 ( V_73 ) ;
return 0 ;
}
static int F_27 ( struct V_72 * V_73 )
{
struct V_5 * V_74 = F_23 ( V_73 ) ;
F_28 ( V_73 ) ;
F_29 ( V_82 , & V_74 -> V_50 ) ;
F_30 ( V_74 -> V_39 ) ;
return 0 ;
}
static void F_31 ( struct V_35 * V_35 )
{
struct V_5 * V_74 = V_35 -> V_83 ;
int V_54 = V_35 -> V_54 ;
if ( ! V_74 || ! F_32 ( V_82 , & V_74 -> V_50 ) ) {
F_9 ( & V_35 -> V_18 -> V_18 , L_27 , V_53 ) ;
return;
}
if ( ! F_33 ( V_74 -> V_73 ) ) {
F_9 ( & V_35 -> V_18 -> V_18 , L_28 ,
V_53 ) ;
return;
}
if ( V_54 )
F_19 ( V_54 , V_53 , V_74 -> V_39 ) ;
F_34 ( V_74 -> V_39 ) ;
F_35 ( V_74 -> V_73 ) ;
}
static T_3 F_36 ( struct V_84 * V_85 ,
struct V_72 * V_73 )
{
struct V_5 * V_74 = F_23 ( V_73 ) ;
int V_41 ;
F_28 ( V_73 ) ;
if ( F_37 ( V_74 -> V_39 ) == - V_64 ) {
V_74 -> V_75 = V_85 ;
return V_86 ;
}
F_38 ( V_85 -> V_87 , V_85 -> V_14 ) ;
memcpy ( V_74 -> V_88 , V_85 -> V_87 , V_85 -> V_14 ) ;
F_21 ( L_29 , V_85 -> V_14 , V_89 ) ;
F_39 ( V_74 -> V_90 ,
V_74 -> V_39 -> V_91 ,
F_40 ( V_74 -> V_39 -> V_91 ,
V_74 -> V_92 ->
V_93 & 0x7F ) ,
V_74 -> V_88 , V_85 -> V_14 , F_31 ,
V_74 ) ;
V_74 -> V_90 -> V_94 |= V_95 ;
V_41 = F_41 ( V_74 -> V_90 , V_96 ) ;
if ( V_41 ) {
F_42 ( & V_74 -> V_39 -> V_97 -> V_18 ,
L_30 , V_41 ) ;
V_73 -> V_98 . V_99 ++ ;
F_26 ( V_73 ) ;
} else {
V_73 -> V_98 . V_100 ++ ;
V_73 -> V_98 . V_101 += V_85 -> V_14 ;
}
F_43 ( V_85 ) ;
return V_86 ;
}
static void F_44 ( struct V_72 * V_73 )
{
struct V_5 * V_74 = F_23 ( V_73 ) ;
if ( ! V_74 )
return;
F_42 ( & V_73 -> V_18 , L_31 ) ;
if ( V_74 -> V_90 &&
( V_74 -> V_90 -> V_54 == - V_102 ) )
F_45 ( V_74 -> V_90 ) ;
V_73 -> V_98 . V_99 ++ ;
}
static void F_46 ( struct V_5 * V_74 , unsigned char * V_103 ,
unsigned int V_104 , unsigned char V_105 )
{
unsigned short V_106 ;
unsigned short V_107 = 0 ;
unsigned short V_108 ;
unsigned char * V_109 ;
F_21 ( L_32 , V_104 ) ;
F_47 ( V_103 , F_48 ( 128 , ( int ) V_104 ) ) ;
while ( V_104 ) {
switch ( V_74 -> V_77 ) {
case V_78 :
V_106 =
( V_104 <
V_74 -> V_80 ) ? V_104 : V_74 ->
V_80 ;
memcpy ( ( ( unsigned char * ) ( & V_74 -> V_110 ) ) +
V_74 -> V_79 , V_103 + V_107 ,
V_106 ) ;
V_74 -> V_79 += V_106 ;
V_107 += V_106 ;
V_74 -> V_80 -= V_106 ;
V_104 -= V_106 ;
if ( ! V_74 -> V_80 ) {
V_108 = F_49 ( V_74 -> V_110 . V_111 ) ;
if ( ( V_108 > V_112 ) ||
( V_108 < sizeof( struct V_81 ) ) ) {
F_9 ( & V_74 -> V_73 -> V_18 ,
L_33 ,
V_108 ) ;
V_74 -> V_77 = V_113 ;
continue;
}
V_74 -> V_114 = F_50 ( V_74 -> V_73 ,
V_108 ) ;
if ( ! V_74 -> V_114 ) {
F_21 ( L_34 ) ;
V_74 -> V_77 = V_113 ;
return;
}
V_109 =
F_51 ( V_74 -> V_114 ,
sizeof( struct V_81 ) ) ;
memcpy ( V_109 , ( char * ) & ( V_74 -> V_110 ) ,
sizeof( struct V_81 ) ) ;
V_74 -> V_79 = sizeof( struct V_81 ) ;
V_74 -> V_80 =
V_108 - sizeof( struct V_81 ) ;
V_74 -> V_77 = V_115 ;
}
break;
case V_115 :
V_106 = ( V_104 < V_74 -> V_80 )
? V_104 : V_74 -> V_80 ;
V_109 = F_51 ( V_74 -> V_114 , V_106 ) ;
memcpy ( V_109 , V_103 + V_107 , V_106 ) ;
V_74 -> V_80 -= V_106 ;
V_104 -= V_106 ;
V_107 += V_106 ;
V_74 -> V_79 += V_106 ;
if ( ! V_74 -> V_80 ) {
V_74 -> V_114 -> V_116 = F_52 ( V_117 ) ;
F_53 ( V_74 -> V_114 ) ;
F_54 ( V_74 -> V_114 ) ;
V_74 -> V_114 = NULL ;
V_74 -> V_73 -> V_98 . V_118 ++ ;
V_74 -> V_73 -> V_98 . V_119 += V_74 -> V_79 ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = sizeof( struct V_81 ) ;
V_74 -> V_77 = V_78 ;
}
break;
case V_113 :
F_21 ( L_35 ) ;
V_104 = 0 ;
break;
default:
F_21 ( L_36 ) ;
V_104 -- ;
break;
}
}
if ( V_105 ) {
if ( V_74 -> V_77 == V_113 ) {
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = sizeof( struct V_81 ) ;
}
}
}
static void F_55 ( struct V_35 * V_35 , T_4 V_120 )
{
static const T_5 V_121 [ 4 ] = { 0xDE , 0xAD , 0xBE , 0xEF } ;
T_2 V_122 = V_35 -> V_123 % F_56 ( V_120 ) ;
if ( ( ( V_122 == 5 ) || ( V_122 == 6 ) ) &&
! memcmp ( ( ( T_5 * ) V_35 -> V_124 ) + V_35 -> V_123 - 4 ,
V_121 , 4 ) ) {
V_35 -> V_123 -= 4 ;
}
}
static void F_57 ( struct V_35 * V_35 )
{
struct V_5 * V_74 = V_35 -> V_83 ;
struct V_72 * V_73 ;
int V_41 ;
int V_54 = V_35 -> V_54 ;
if ( V_54 ) {
F_19 ( V_54 , V_53 , V_74 -> V_39 ) ;
return;
}
if ( ! V_74 || ! F_32 ( V_82 , & V_74 -> V_50 ) ) {
F_21 ( L_37 ) ;
return;
}
F_58 ( V_35 -> V_18 ) ;
V_73 = V_74 -> V_73 ;
if ( ! F_33 ( V_73 ) ) {
return;
}
if ( V_74 -> V_39 -> V_22 & V_125 )
F_55 ( V_35 , V_74 -> V_126 -> V_127 ) ;
if ( V_35 -> V_123 ) {
F_59 ( & V_74 -> V_76 ) ;
F_46 ( V_74 , V_35 -> V_124 , V_35 -> V_123 ,
( V_35 -> V_128 >
V_35 -> V_123 ) ? 1 : 0 ) ;
F_60 ( & V_74 -> V_76 ) ;
}
F_39 ( V_35 ,
V_74 -> V_39 -> V_91 ,
F_61 ( V_74 -> V_39 -> V_91 ,
V_74 -> V_126 ->
V_93 & 0x7F ) ,
V_35 -> V_124 , V_129 ,
F_57 , V_74 ) ;
V_41 = F_41 ( V_35 , V_96 ) ;
if ( V_41 )
F_42 ( & V_74 -> V_39 -> V_97 -> V_18 ,
L_38 , V_53 ,
V_41 ) ;
}
static void F_62 ( struct V_130 * V_131 )
{
V_131 -> V_132 &=
~ ( V_133
| V_134
| V_135
| V_136
| V_137
| V_138
| V_139
| V_140 ) ;
V_131 -> V_141 &= ~ V_142 ;
V_131 -> V_143 &=
~ ( V_144
| V_145
| V_146
| V_147
| V_148 ) ;
V_131 -> V_149 &=
~ ( V_150
| V_151
| V_152
| V_153 ) ;
V_131 -> V_149 |= V_154 ;
F_63 ( V_131 , 115200 , 115200 ) ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_130 * V_155 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_130 * V_131 ;
if ( ! V_34 ) {
F_17 ( V_52 L_39 , V_53 ) ;
return;
}
F_65 ( L_40 , V_34 -> V_156 ) ;
V_131 = V_3 -> V_131 ;
V_131 -> V_132 &= ~ V_140 ;
V_131 -> V_149 &=
~ ( V_150
| V_151
| V_152
| V_153 ) ;
V_131 -> V_149 |= V_154 ;
F_66 ( V_3 , 115200 , 115200 ) ;
}
static void F_67 ( struct V_1 * V_34 , struct V_35 * V_35 )
{
int V_41 ;
F_39 ( V_35 , V_34 -> V_39 -> V_91 ,
F_61 ( V_34 -> V_39 -> V_91 ,
V_34 -> V_126 ->
V_93 & 0x7F ) ,
V_35 -> V_124 , V_34 -> V_157 ,
V_158 , V_34 ) ;
V_41 = F_41 ( V_35 , V_96 ) ;
if ( V_41 ) {
F_9 ( & V_35 -> V_18 -> V_18 , L_41 ,
V_53 , V_41 ) ;
}
}
static void F_68 ( struct V_1 * V_34 )
{
int V_104 ;
struct V_35 * V_159 ;
while ( V_34 -> V_160 [ V_34 -> V_161 ] ) {
V_159 = V_34 -> V_38 [ V_34 -> V_161 ] ;
V_104 = F_69 ( V_159 , V_34 ) ;
if ( V_104 == - 1 )
return;
if ( V_104 == 0 ) {
V_34 -> V_161 ++ ;
if ( V_34 -> V_161 >= V_34 -> V_37 )
V_34 -> V_161 = 0 ;
F_67 ( V_34 , V_159 ) ;
}
}
}
static void F_70 ( struct V_1 * V_34 )
{
int V_104 = 0 ;
struct V_35 * V_35 ;
V_35 = V_34 -> V_38 [ 0 ] ;
if ( V_34 -> V_162 > 0 ) {
V_104 = F_69 ( V_35 , V_34 ) ;
if ( V_104 == - 1 )
return;
}
if ( V_104 == 0 && ( ( V_35 -> V_123 != 0 ) ||
( V_34 -> V_163 == V_164 ) ) ) {
V_34 -> V_163 = V_165 ;
F_71 ( V_34 ) ;
} else
V_34 -> V_163 = V_166 ;
}
static void V_158 ( struct V_35 * V_35 )
{
struct V_1 * V_34 = V_35 -> V_83 ;
int V_54 = V_35 -> V_54 ;
if ( ! V_34 ) {
F_21 ( L_42 ) ;
return;
} else if ( V_54 ) {
F_19 ( V_54 , V_53 , V_34 -> V_39 ) ;
return;
}
F_65 ( L_43 , V_54 ) ;
F_21 ( L_44 , V_35 -> V_123 ) ;
F_38 ( V_35 -> V_124 , V_35 -> V_123 ) ;
if ( V_34 -> V_162 == 0 )
return;
if ( V_54 == 0 ) {
if ( V_34 -> V_39 -> V_22 & V_125 )
F_55 ( V_35 , V_34 -> V_126 -> V_127 ) ;
F_59 ( & V_34 -> V_167 ) ;
V_34 -> V_160 [ F_8 ( V_34 , V_35 ) ] = 1 ;
F_68 ( V_34 ) ;
F_60 ( & V_34 -> V_167 ) ;
} else if ( V_54 == - V_58 || V_54 == - V_168 ) {
F_72 ( L_45 , V_34 -> V_156 ) ;
F_59 ( & V_34 -> V_167 ) ;
V_34 -> V_160 [ F_8 ( V_34 , V_35 ) ] = 0 ;
F_67 ( V_34 , V_35 ) ;
F_60 ( & V_34 -> V_167 ) ;
} else {
F_72 ( L_46 , V_34 -> V_156 , V_54 ) ;
return;
}
}
static void F_73 ( struct V_1 * V_34 )
{
unsigned long V_50 ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
if ( ( V_34 -> V_39 -> V_22 & V_169 ) )
F_70 ( V_34 ) ;
else
F_68 ( V_34 ) ;
F_15 ( & V_34 -> V_167 , V_50 ) ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
F_75 ( & V_34 -> V_170 ) ;
}
static void F_76 ( struct V_171 * V_172 )
{
struct V_1 * V_34 =
F_77 ( V_172 , struct V_1 ,
V_173 ) ;
F_73 ( V_34 ) ;
}
static int F_78 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_1 * V_34 = F_13 ( V_3 -> V_49 ) ;
int V_41 ;
if ( V_34 == NULL || V_34 -> V_176 != V_177 ) {
F_79 ( 1 ) ;
V_3 -> V_4 = NULL ;
F_21 ( L_47 ) ;
return - V_57 ;
}
F_80 ( & V_34 -> V_39 -> V_178 ) ;
V_41 = F_81 ( V_34 -> V_39 -> V_97 ) ;
if ( V_41 < 0 )
goto V_179;
F_21 ( L_48 , V_34 -> V_156 ) ;
F_82 ( & V_34 -> V_39 -> V_180 ) ;
F_83 ( & V_34 -> V_167 ) ;
V_3 -> V_4 = V_34 ;
F_84 ( V_34 -> V_3 ) ;
V_34 -> V_3 = F_85 ( V_3 ) ;
F_86 ( & V_34 -> V_167 ) ;
V_34 -> V_162 ++ ;
if ( V_34 -> V_162 == 1 ) {
V_34 -> V_163 = V_166 ;
F_64 ( V_3 , NULL ) ;
F_87 ( & V_34 -> V_170 ,
( void (*) ( unsigned long ) ) F_73 ,
( unsigned long ) V_34 ) ;
F_88 ( & V_34 -> V_173 ,
F_76 ) ;
V_41 = F_89 ( V_34 -> V_39 , V_181 ) ;
if ( V_41 ) {
F_90 ( V_34 -> V_39 ) ;
V_34 -> V_162 -- ;
F_91 ( & V_34 -> V_39 -> V_180 , V_182 ) ;
}
} else {
F_21 ( L_49 ) ;
}
F_92 ( V_34 -> V_39 -> V_97 ) ;
if ( V_41 )
F_93 ( V_3 , V_183 | V_184 , 0 ) ;
V_179:
F_94 ( & V_34 -> V_39 -> V_178 ) ;
return V_41 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_1 * V_34 = V_3 -> V_4 ;
T_5 V_185 ;
F_21 ( L_50 ) ;
if ( V_34 == NULL )
return;
F_80 ( & V_34 -> V_39 -> V_178 ) ;
V_185 = V_34 -> V_39 -> V_185 ;
if ( ! V_185 )
F_81 ( V_34 -> V_39 -> V_97 ) ;
V_34 -> V_162 -- ;
if ( V_34 -> V_162 <= 0 ) {
V_34 -> V_162 = 0 ;
F_83 ( & V_34 -> V_167 ) ;
if ( V_34 -> V_3 == V_3 ) {
V_34 -> V_3 -> V_4 = NULL ;
V_34 -> V_3 = NULL ;
F_84 ( V_3 ) ;
}
F_86 ( & V_34 -> V_167 ) ;
if ( ! V_185 )
F_90 ( V_34 -> V_39 ) ;
F_96 ( & V_34 -> V_170 ) ;
F_97 ( & V_34 -> V_173 ) ;
}
if ( ! V_185 )
F_92 ( V_34 -> V_39 -> V_97 ) ;
F_94 ( & V_34 -> V_39 -> V_178 ) ;
F_91 ( & V_34 -> V_39 -> V_180 , V_182 ) ;
}
static int F_98 ( struct V_2 * V_3 , const unsigned char * V_13 ,
int V_104 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_186 , V_101 ;
unsigned long V_50 ;
if ( V_34 == NULL ) {
F_17 ( V_52 L_51 , V_53 ) ;
return - V_57 ;
}
F_14 ( & V_34 -> V_167 , V_50 ) ;
V_186 = V_34 -> V_187 - V_34 -> V_188 ;
V_101 = ( V_104 < V_186 ) ? V_104 : V_186 ;
if ( ! V_101 )
goto V_189;
memcpy ( V_34 -> V_190 + V_34 -> V_188 , V_13 , V_101 ) ;
V_34 -> V_188 += V_101 ;
V_189:
F_15 ( & V_34 -> V_167 , V_50 ) ;
F_99 ( V_34 ) ;
return V_101 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_191 ;
unsigned long V_50 ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
V_191 = V_34 -> V_187 - V_34 -> V_188 ;
F_15 ( & V_34 -> V_167 , V_50 ) ;
return V_191 ;
}
static void F_101 ( struct V_2 * V_3 , struct V_130 * V_155 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
unsigned long V_50 ;
if ( V_155 )
F_102 ( L_52 ,
V_3 -> V_131 -> V_149 , V_155 -> V_149 ) ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
if ( V_34 -> V_162 )
F_64 ( V_3 , V_155 ) ;
else
V_3 -> V_131 = V_155 ;
F_15 ( & V_34 -> V_167 , V_50 ) ;
}
static int F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_192 ;
unsigned long V_50 ;
if ( V_34 == NULL )
return 0 ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
V_192 = V_34 -> V_188 ;
F_15 ( & V_34 -> V_167 , V_50 ) ;
return V_192 ;
}
static int F_104 ( struct V_1 * V_34 ,
struct V_193 * V_194 ,
struct V_195 * V_91 )
{
int V_41 ;
if ( V_34 -> V_39 -> V_185 )
return - V_57 ;
F_105 ( V_194 -> V_35 , V_91 ,
F_106 ( V_91 ,
V_194 -> V_196 ->
V_93 & 0x7F ) ,
& V_194 -> V_197 ,
sizeof( struct V_198 ) ,
V_199 , V_34 ,
V_194 -> V_196 -> V_200 ) ;
V_41 = F_41 ( V_194 -> V_35 , V_96 ) ;
if ( V_41 ) {
F_42 ( & V_91 -> V_18 , L_53 , V_53 ,
V_41 ) ;
}
return V_41 ;
}
static void V_199 ( struct V_35 * V_35 )
{
struct V_1 * V_34 = V_35 -> V_83 ;
struct V_193 * V_194 ;
int V_54 = V_35 -> V_54 ;
T_6 V_201 , V_202 ;
struct V_203 * V_204 ;
struct V_198 * V_197 ;
struct V_195 * V_91 ;
if ( ! V_34 )
return;
if ( V_54 ) {
F_19 ( V_54 , V_53 , V_34 -> V_39 ) ;
return;
}
V_194 = V_34 -> V_194 ;
if ( ! V_194 )
return;
V_91 = V_34 -> V_39 -> V_91 ;
V_197 = & V_194 -> V_197 ;
if ( V_197 -> V_205 != V_206 ||
V_197 -> V_207 != V_208 ||
F_56 ( V_197 -> V_209 ) != V_210 ||
F_56 ( V_197 -> V_211 ) != V_212 ||
F_56 ( V_197 -> V_213 ) != V_214 ) {
F_42 ( & V_91 -> V_18 ,
L_54 ) ;
F_47 ( V_197 ,
sizeof( struct V_198 ) ) ;
} else {
V_201 = F_56 ( V_197 ->
V_201 ) ;
V_202 = V_194 -> V_202 ;
V_204 = & V_194 -> V_204 ;
F_59 ( & V_34 -> V_167 ) ;
if ( ( V_201 & V_215 ) !=
( V_202 & V_215 ) )
V_204 -> V_216 ++ ;
if ( ( V_201 & V_217 ) !=
( V_202 & V_217 ) )
V_204 -> V_216 ++ ;
if ( ( V_201 & V_218 ) !=
( V_202 & V_218 ) )
V_204 -> V_219 ++ ;
if ( ( V_201 & V_220 ) &&
! ( V_202 & V_220 ) )
V_204 -> V_221 ++ ;
if ( ( V_201 & V_222 ) !=
( V_202 & V_222 ) )
V_204 -> V_223 ++ ;
if ( ( V_201 & V_224 ) !=
( V_202 & V_224 ) )
V_204 -> V_225 ++ ;
if ( ( V_201 & V_226 ) !=
( V_202 & V_226 ) )
V_204 -> V_227 ++ ;
V_194 -> V_202 = V_201 ;
F_60 ( & V_34 -> V_167 ) ;
V_194 -> V_228 = 1 ;
F_107 ( & V_194 -> V_229 ) ;
}
memset ( V_197 , 0 ,
sizeof( struct V_198 ) ) ;
F_104 ( V_34 ,
V_194 ,
V_34 -> V_39 -> V_91 ) ;
}
static int
F_108 ( struct V_1 * V_34 , unsigned long V_230 )
{
F_109 ( V_231 , V_232 ) ;
struct V_203 V_233 , V_234 ;
struct V_193 * V_194 ;
int V_235 ;
V_194 = V_34 -> V_194 ;
if ( ! V_194 )
return - V_58 ;
F_83 ( & V_34 -> V_167 ) ;
memcpy ( & V_233 , & V_194 -> V_204 , sizeof( struct V_203 ) ) ;
F_86 ( & V_34 -> V_167 ) ;
F_110 ( & V_194 -> V_229 , & V_231 ) ;
for (; ; ) {
F_83 ( & V_34 -> V_167 ) ;
memcpy ( & V_234 , & V_194 -> V_204 , sizeof( struct V_203 ) ) ;
F_86 ( & V_34 -> V_167 ) ;
F_111 ( V_236 ) ;
if ( ( ( V_230 & V_237 ) && ( V_234 . V_221 != V_233 . V_221 ) ) ||
( ( V_230 & V_238 ) && ( V_234 . V_225 != V_233 . V_225 ) ) ||
( ( V_230 & V_239 ) && ( V_234 . V_227 != V_233 . V_227 ) ) ) {
V_235 = 0 ;
break;
}
F_112 () ;
if ( F_113 ( V_232 ) ) {
V_235 = - V_240 ;
break;
}
V_233 = V_234 ;
}
V_232 -> V_241 = V_242 ;
F_114 ( & V_194 -> V_229 , & V_231 ) ;
return V_235 ;
}
static int F_115 ( struct V_2 * V_3 ,
struct V_243 * V_204 )
{
struct V_203 V_234 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_193 * V_194 = V_34 -> V_194 ;
memset ( & V_204 , 0 , sizeof( struct V_243 ) ) ;
if ( ! V_194 )
return - V_58 ;
F_83 ( & V_34 -> V_167 ) ;
memcpy ( & V_234 , & V_194 -> V_204 , sizeof( struct V_203 ) ) ;
F_86 ( & V_34 -> V_167 ) ;
V_204 -> V_244 = V_234 . V_244 ;
V_204 -> V_225 = V_234 . V_225 ;
V_204 -> V_221 = V_234 . V_221 ;
V_204 -> V_227 = V_234 . V_227 ;
V_204 -> V_245 = V_234 . V_245 ;
V_204 -> V_246 = V_234 . V_246 ;
V_204 -> V_219 = V_234 . V_219 ;
V_204 -> V_247 = V_234 . V_247 ;
V_204 -> V_216 = V_234 . V_216 ;
V_204 -> V_223 = V_234 . V_223 ;
V_204 -> V_248 = V_234 . V_248 ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 )
{
int V_249 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
struct V_193 * V_194 ;
T_6 V_201 ;
if ( ! V_34 ) {
F_21 ( L_55 ) ;
return - V_63 ;
}
F_83 ( & V_34 -> V_167 ) ;
V_249 = ( ( V_34 -> V_250 ) ? V_183 : 0 ) |
( ( V_34 -> V_251 ) ? V_184 : 0 ) ;
V_194 = V_34 -> V_194 ;
if ( V_194 ) {
V_201 = F_56 (
V_194 -> V_202 ) ;
if ( V_201 & V_220 )
V_249 |= V_237 ;
if ( V_201 & V_226 )
V_249 |= V_239 ;
if ( V_201 & V_224 )
V_249 |= V_238 ;
}
F_86 ( & V_34 -> V_167 ) ;
return V_249 ;
}
static int F_93 ( struct V_2 * V_3 ,
unsigned int V_252 , unsigned int V_253 )
{
int V_254 = 0 ;
unsigned long V_50 ;
int V_255 ;
struct V_1 * V_34 = F_1 ( V_3 ) ;
if ( ! V_34 ) {
F_21 ( L_55 ) ;
return - V_63 ;
}
if ( ( V_34 -> V_39 -> V_22 & V_23 ) != V_32 )
return - V_63 ;
V_255 = V_34 -> V_39 -> V_97 -> V_256 -> V_257 . V_258 ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
if ( V_252 & V_183 )
V_34 -> V_250 = 1 ;
if ( V_252 & V_184 )
V_34 -> V_251 = 1 ;
if ( V_253 & V_183 )
V_34 -> V_250 = 0 ;
if ( V_253 & V_184 )
V_34 -> V_251 = 0 ;
if ( V_34 -> V_251 )
V_254 |= 0x01 ;
if ( V_34 -> V_250 )
V_254 |= 0x02 ;
F_15 ( & V_34 -> V_167 , V_50 ) ;
return F_117 ( V_34 -> V_39 -> V_91 ,
F_118 ( V_34 -> V_39 -> V_91 , 0 ) , 0x22 ,
0x21 , V_254 , V_255 , NULL , 0 ,
V_259 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
unsigned int V_260 , unsigned long V_230 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
int V_235 = 0 ;
F_65 ( L_56 , V_260 , V_230 ) ;
if ( ! V_34 )
return - V_57 ;
switch ( V_260 ) {
case V_261 :
V_235 = F_108 ( V_34 , V_230 ) ;
break;
default:
V_235 = - V_262 ;
break;
}
return V_235 ;
}
static void F_99 ( struct V_1 * V_34 )
{
T_5 * V_263 ;
unsigned long V_50 ;
int V_264 ;
F_14 ( & V_34 -> V_167 , V_50 ) ;
if ( ! V_34 -> V_188 )
goto V_189;
if ( V_34 -> V_265 )
goto V_189;
if ( F_37 ( V_34 -> V_39 ) == - V_64 )
goto V_189;
V_263 = V_34 -> V_190 ;
V_34 -> V_190 = V_34 -> V_266 ;
V_34 -> V_266 = V_263 ;
V_34 -> V_267 = V_34 -> V_188 ;
V_34 -> V_188 = 0 ;
if ( V_263 && V_34 -> V_268 ) {
V_264 = V_34 -> V_268 ( V_34 ) ;
if ( V_264 >= 0 )
V_34 -> V_265 = 1 ;
}
V_189:
F_15 ( & V_34 -> V_167 , V_50 ) ;
}
static int F_120 ( struct V_1 * V_34 , T_5 type , T_6 V_43 ,
struct V_35 * V_269 ,
struct V_270 * V_271 ,
T_5 * V_272 , T_2 V_273 )
{
int V_41 ;
int V_274 ;
if ( ! V_34 || ! V_269 || ! V_271 ) {
F_17 ( V_52 L_57 , V_53 ) ;
return - V_63 ;
}
V_271 -> V_209 = 0 ;
V_271 -> V_211 = F_121 ( F_11 ( V_43 ) ) ;
V_271 -> V_213 = F_121 ( V_273 ) ;
if ( type == V_275 ) {
V_271 -> V_276 = V_277 |
V_278 |
V_279 ;
V_271 -> V_280 = V_275 ;
V_274 = F_118 ( V_34 -> V_39 -> V_91 , 0 ) ;
} else {
V_271 -> V_276 = V_281 |
V_278 |
V_279 ;
V_271 -> V_280 = V_282 ;
V_274 = F_122 ( V_34 -> V_39 -> V_91 , 0 ) ;
}
F_72 ( L_58 ,
type == V_275 ? L_59 : L_60 ,
V_271 -> V_276 , V_271 -> V_213 , V_43 ) ;
V_269 -> V_94 = 0 ;
F_123 ( V_269 ,
V_34 -> V_39 -> V_91 ,
V_274 ,
( T_5 * ) V_271 ,
V_272 , V_273 , V_283 , V_34 ) ;
V_41 = F_41 ( V_269 , V_96 ) ;
if ( V_41 ) {
F_9 ( & V_269 -> V_18 -> V_18 ,
L_61 , V_53 ,
V_41 , type ) ;
return V_41 ;
}
return V_273 ;
}
static int F_71 ( struct V_1 * V_34 )
{
if ( ! V_34 )
return - V_63 ;
memset ( V_34 -> V_284 [ 0 ] , 0 , V_285 ) ;
if ( V_34 -> V_37 != 1 ) {
F_9 ( & V_34 -> V_39 -> V_97 -> V_18 ,
L_62
L_63 ) ;
return 0 ;
}
return F_120 ( V_34 ,
V_275 ,
V_34 -> V_39 -> V_22 & V_23 ,
V_34 -> V_38 [ 0 ] ,
& V_34 -> V_286 ,
V_34 -> V_284 [ 0 ] , V_34 -> V_157 ) ;
}
static void F_124 ( struct V_35 * V_35 )
{
struct V_44 * V_45 = V_35 -> V_83 ;
struct V_1 * V_34 ;
unsigned char * V_287 ;
int V_54 = V_35 -> V_54 ;
int V_46 ;
F_58 ( V_35 -> V_18 ) ;
if ( ! V_45 )
return;
if ( V_54 ) {
F_19 ( V_54 , V_53 , NULL ) ;
return;
}
F_65 ( L_64 , V_54 ) ;
V_287 = V_35 -> V_124 ;
F_65 ( L_65 , * V_287 ) ;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
if ( * V_287 & ( 1 << V_46 ) ) {
V_34 = F_12 ( V_45 ,
( 1 << V_46 ) ) ;
if ( V_34 != NULL ) {
F_21 ( L_66 , V_46 ) ;
F_59 ( & V_34 -> V_167 ) ;
if ( V_34 -> V_163 == V_166 &&
V_34 -> V_162 > 0 ) {
if ( ! V_34 -> V_160 [ 0 ] ) {
V_34 -> V_163 = V_165 ;
F_71 ( V_34 ) ;
} else
V_34 -> V_163 = V_164 ;
} else {
F_21 ( L_67
L_68 , V_46 ) ;
}
F_60 ( & V_34 -> V_167 ) ;
}
}
}
F_125 ( V_45 , V_35 -> V_18 , V_96 ) ;
}
static int F_126 ( struct V_1 * V_34 )
{
if ( NULL == V_34 )
return - V_63 ;
return F_120 ( V_34 ,
V_282 ,
V_34 -> V_39 -> V_22 & V_23 ,
V_34 -> V_288 ,
& V_34 -> V_289 ,
V_34 -> V_266 , V_34 -> V_267 ) ;
}
static void F_127 ( struct V_35 * V_35 )
{
struct V_1 * V_34 = V_35 -> V_83 ;
int V_54 = V_35 -> V_54 ;
struct V_2 * V_3 ;
if ( ! V_34 ) {
F_21 ( L_42 ) ;
return;
}
F_59 ( & V_34 -> V_167 ) ;
V_34 -> V_265 = 0 ;
V_3 = F_85 ( V_34 -> V_3 ) ;
F_60 ( & V_34 -> V_167 ) ;
if ( V_54 ) {
F_19 ( V_54 , V_53 , V_34 -> V_39 ) ;
F_84 ( V_3 ) ;
return;
}
F_34 ( V_34 -> V_39 ) ;
if ( V_3 ) {
F_128 ( V_3 ) ;
F_84 ( V_3 ) ;
}
F_99 ( V_34 ) ;
F_21 ( L_36 ) ;
}
static int F_129 ( struct V_1 * V_34 )
{
int V_104 = V_34 -> V_267 ;
int V_41 ;
F_39 ( V_34 -> V_288 ,
V_34 -> V_39 -> V_91 ,
F_40 ( V_34 -> V_39 -> V_91 ,
V_34 -> V_92 ->
V_93 & 0x7F ) ,
V_34 -> V_266 , V_34 -> V_267 ,
F_127 , V_34 ) ;
V_41 = F_41 ( V_34 -> V_288 , V_96 ) ;
if ( V_41 ) {
F_42 ( & V_34 -> V_39 -> V_91 -> V_18 ,
L_69 , V_41 ) ;
return V_41 ;
}
return V_104 ;
}
static void V_283 ( struct V_35 * V_35 )
{
struct V_1 * V_34 = V_35 -> V_83 ;
struct V_270 * V_290 ;
int V_54 = V_35 -> V_54 ;
struct V_2 * V_3 ;
if ( ! V_34 )
return;
F_59 ( & V_34 -> V_167 ) ;
V_34 -> V_265 = 0 ;
V_3 = F_85 ( V_34 -> V_3 ) ;
F_60 ( & V_34 -> V_167 ) ;
if ( V_54 ) {
F_19 ( V_54 , V_53 , V_34 -> V_39 ) ;
F_84 ( V_3 ) ;
return;
}
V_290 = (struct V_270 * ) ( V_35 -> V_291 ) ;
F_65 ( L_70 , V_54 ) ;
F_65 ( L_71 , V_35 -> V_123 ) ;
F_38 ( V_35 -> V_124 , V_35 -> V_123 ) ;
if ( V_290 -> V_276 ==
( V_277 | V_278 | V_279 ) ) {
V_34 -> V_160 [ 0 ] = 1 ;
F_59 ( & V_34 -> V_167 ) ;
F_70 ( V_34 ) ;
F_60 ( & V_34 -> V_167 ) ;
} else {
F_34 ( V_34 -> V_39 ) ;
if ( V_3 )
F_128 ( V_3 ) ;
F_99 ( V_34 ) ;
}
F_84 ( V_3 ) ;
}
static int F_69 ( struct V_35 * V_35 , struct V_1 * V_34 )
{
struct V_2 * V_3 ;
int V_292 = 0 ;
int V_293 ;
if ( V_35 == NULL || V_34 == NULL ) {
F_21 ( L_72 ) ;
return - 2 ;
}
V_3 = F_85 ( V_34 -> V_3 ) ;
if ( V_3 ) {
V_292 = V_35 -> V_123 -
V_34 -> V_294 ;
F_21 ( L_73 ) ;
while ( V_292 ) {
if ( F_32 ( V_295 , & V_3 -> V_50 ) ) {
F_84 ( V_3 ) ;
return - 1 ;
}
V_293 = F_130
( V_3 , V_35 -> V_124 +
V_34 -> V_294 ,
V_292 ) ;
V_34 -> V_294 += V_293 ;
V_292 -= V_293 ;
F_131 ( V_3 ) ;
}
}
if ( V_292 == 0 ) {
V_34 -> V_294 = 0 ;
V_34 -> V_160 [ F_8 ( V_34 , V_35 ) ] = 0 ;
}
F_84 ( V_3 ) ;
return V_292 ;
}
static void F_132 ( struct V_6 * V_7 )
{
char * V_296 ;
char V_297 [ 20 ] ;
switch ( V_7 -> V_22 & V_23 ) {
case V_24 :
V_296 = L_2 ;
break;
case V_25 :
V_296 = L_3 ;
break;
case V_27 :
V_296 = L_5 ;
break;
case V_28 :
V_296 = L_74 ;
break;
case V_26 :
V_296 = L_4 ;
break;
case V_29 :
V_296 = L_7 ;
break;
case V_30 :
V_296 = L_8 ;
break;
case V_31 :
V_296 = L_9 ;
break;
case V_32 :
V_296 = L_10 ;
break;
case V_33 :
V_296 = L_11 ;
break;
default:
V_296 = L_12 ;
break;
}
if ( ( V_7 -> V_22 & V_23 ) == V_33 ) {
sprintf ( V_297 , L_75 , F_2 ( V_7 ) -> V_73 -> V_15 ) ;
} else
sprintf ( V_297 , L_76 , V_298 ,
F_3 ( V_7 ) -> V_156 ) ;
F_133 ( & V_7 -> V_97 -> V_18 , L_77 ,
V_296 , V_297 ) ;
}
static int F_25 ( struct V_6 * V_7 )
{
int V_46 , V_41 = 0 ;
struct V_5 * V_5 = F_2 ( V_7 ) ;
if ( ! V_5 )
return - V_57 ;
for ( V_46 = 0 ; V_46 < V_299 ; V_46 ++ ) {
F_39 ( V_5 -> V_300 [ V_46 ] ,
V_7 -> V_91 ,
F_61 ( V_7 -> V_91 ,
V_5 -> V_126 ->
V_93 & 0x7F ) ,
V_5 -> V_301 [ V_46 ] ,
V_129 , F_57 ,
V_5 ) ;
V_41 = F_41 ( V_5 -> V_300 [ V_46 ] ,
V_302 ) ;
if ( V_41 )
F_42 ( & V_7 -> V_91 -> V_18 ,
L_78 , V_53 ,
V_46 , V_41 ) ;
}
return V_41 ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_46 ;
struct V_5 * V_5 = F_2 ( V_7 ) ;
if ( ! V_5 )
return - V_57 ;
for ( V_46 = 0 ; V_46 < V_299 ; V_46 ++ ) {
if ( V_5 -> V_300 [ V_46 ] )
F_134 ( V_5 -> V_300 [ V_46 ] ) ;
}
if ( V_5 -> V_90 )
F_134 ( V_5 -> V_90 ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 , T_7 V_50 )
{
int V_46 , V_41 = 0 ;
struct V_1 * V_34 = F_3 ( V_7 ) ;
if ( ! V_34 )
return - V_57 ;
if ( ! ( V_34 -> V_39 -> V_22 & V_169 ) ) {
for ( V_46 = 0 ; V_46 < V_34 -> V_37 ; V_46 ++ ) {
F_39 ( V_34 -> V_38 [ V_46 ] ,
V_34 -> V_39 -> V_91 ,
F_61 ( V_34 -> V_39 -> V_91 ,
V_34 -> V_126 ->
V_93 &
0x7F ) ,
V_34 -> V_284 [ V_46 ] ,
V_34 -> V_157 ,
V_158 ,
V_34 ) ;
V_41 = F_41 ( V_34 -> V_38 [ V_46 ] , V_50 ) ;
if ( V_41 ) {
F_42 ( & V_34 -> V_39 -> V_91 -> V_18 ,
L_69 ,
V_41 ) ;
break;
}
}
} else {
F_80 ( & V_34 -> V_45 -> V_303 ) ;
if ( ! V_34 -> V_45 -> V_304 ) {
V_41 =
F_125 ( V_34 -> V_45 ,
V_7 -> V_91 , V_50 ) ;
}
V_34 -> V_45 -> V_304 ++ ;
F_94 ( & V_34 -> V_45 -> V_303 ) ;
}
if ( V_34 -> V_194 )
F_104 ( V_34 ,
V_34 -> V_194 ,
V_34 -> V_39 -> V_91 ) ;
return V_41 ;
}
static int F_90 ( struct V_6 * V_7 )
{
int V_46 ;
struct V_1 * V_34 = F_3 ( V_7 ) ;
struct V_193 * V_194 ;
if ( ! V_34 )
return - V_57 ;
for ( V_46 = 0 ; V_46 < V_34 -> V_37 ; V_46 ++ ) {
if ( V_34 -> V_38 [ V_46 ] ) {
F_134 ( V_34 -> V_38 [ V_46 ] ) ;
V_34 -> V_160 [ V_46 ] = 0 ;
}
}
V_34 -> V_161 = 0 ;
V_34 -> V_294 = 0 ;
if ( V_34 -> V_288 )
F_134 ( V_34 -> V_288 ) ;
if ( V_34 -> V_45 ) {
F_80 ( & V_34 -> V_45 -> V_303 ) ;
if ( V_34 -> V_45 -> V_304 &&
( -- V_34 -> V_45 -> V_304 == 0 ) ) {
struct V_35 * V_35 ;
V_35 = V_34 -> V_45 -> V_305 ;
if ( V_35 )
F_134 ( V_35 ) ;
}
F_94 ( & V_34 -> V_45 -> V_303 ) ;
}
V_194 = V_34 -> V_194 ;
if ( V_194 ) {
F_107 ( & V_194 -> V_229 ) ;
F_134 ( V_194 -> V_35 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_34 )
{
int V_46 ;
if ( V_34 -> V_39 -> V_18 )
F_136 ( V_34 -> V_39 -> V_18 , & V_306 ) ;
F_137 ( V_307 , V_34 -> V_156 ) ;
for ( V_46 = 0 ; V_46 < V_34 -> V_37 ; V_46 ++ ) {
F_138 ( V_34 -> V_38 [ V_46 ] ) ;
F_139 ( V_34 -> V_284 [ V_46 ] ) ;
}
F_138 ( V_34 -> V_288 ) ;
F_139 ( V_34 -> V_266 ) ;
}
static int F_140 ( struct V_1 * V_34 , int V_308 ,
int V_309 , int V_310 )
{
struct V_17 * V_18 ;
int V_156 ;
int V_46 ;
V_156 = F_16 () ;
if ( V_156 < 0 )
goto exit;
V_34 -> V_39 -> V_18 = F_141 ( V_307 , V_156 ,
& V_34 -> V_39 -> V_97 -> V_18 ) ;
V_18 = V_34 -> V_39 -> V_18 ;
F_142 ( V_18 , V_34 -> V_39 ) ;
V_46 = F_143 ( V_18 , & V_306 ) ;
V_34 -> V_156 = V_156 ;
V_34 -> V_176 = V_177 ;
F_144 ( & V_34 -> V_167 ) ;
V_34 -> V_37 = V_308 ;
V_34 -> V_157 = V_309 ;
for ( V_46 = 0 ; V_46 < V_34 -> V_37 ; V_46 ++ ) {
V_34 -> V_38 [ V_46 ] = F_145 ( 0 , V_181 ) ;
if ( ! V_34 -> V_38 [ V_46 ] ) {
F_9 ( V_18 , L_79 ) ;
goto exit;
}
V_34 -> V_38 [ V_46 ] -> V_124 = NULL ;
V_34 -> V_38 [ V_46 ] -> V_128 = 0 ;
V_34 -> V_284 [ V_46 ] = F_146 ( V_34 -> V_157 ,
V_181 ) ;
if ( ! V_34 -> V_284 [ V_46 ] ) {
F_9 ( V_18 , L_80 , V_53 ) ;
goto exit;
}
}
V_34 -> V_288 = F_145 ( 0 , V_181 ) ;
if ( ! V_34 -> V_288 ) {
F_9 ( V_18 , L_79 ) ;
goto exit;
}
V_34 -> V_288 -> V_124 = NULL ;
V_34 -> V_288 -> V_128 = 0 ;
V_34 -> V_267 = 0 ;
V_34 -> V_188 = 0 ;
V_34 -> V_187 = V_310 ;
V_34 -> V_266 = F_146 ( V_34 -> V_187 , V_181 ) ;
if ( ! V_34 -> V_266 ) {
F_9 ( V_18 , L_80 , V_53 ) ;
goto exit;
}
V_34 -> V_190 = F_146 ( V_34 -> V_187 , V_181 ) ;
if ( ! V_34 -> V_190 ) {
F_9 ( V_18 , L_80 , V_53 ) ;
goto exit;
}
return 0 ;
exit:
F_135 ( V_34 ) ;
return - 1 ;
}
static struct V_6 * F_147 ( struct V_311 * V_312 ,
int V_22 )
{
struct V_6 * V_7 ;
V_7 = F_146 ( sizeof( * V_7 ) , V_96 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_22 = V_22 ;
V_7 -> V_91 = F_148 ( V_312 ) ;
V_7 -> V_97 = V_312 ;
F_149 ( & V_7 -> V_180 ) ;
F_150 ( & V_7 -> V_178 ) ;
F_88 ( & V_7 -> V_313 , V_313 ) ;
F_88 ( & V_7 -> V_314 , V_314 ) ;
F_88 ( & V_7 -> V_71 , V_71 ) ;
return V_7 ;
}
static int F_151 ( struct V_6 * V_7 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_315 ; V_46 ++ ) {
if ( V_316 [ V_46 ] == V_7 ) {
V_316 [ V_46 ] = NULL ;
break;
}
}
if ( V_46 == V_315 )
return - 1 ;
return 0 ;
}
static void F_152 ( struct V_6 * V_7 )
{
int V_46 ;
struct V_5 * V_5 = F_2 ( V_7 ) ;
if ( ! V_5 )
return;
F_151 ( V_5 -> V_39 ) ;
if ( V_5 -> V_73 )
F_153 ( V_5 -> V_73 ) ;
for ( V_46 = 0 ; V_46 < V_299 ; V_46 ++ ) {
F_138 ( V_5 -> V_300 [ V_46 ] ) ;
F_139 ( V_5 -> V_301 [ V_46 ] ) ;
V_5 -> V_301 [ V_46 ] = NULL ;
}
F_138 ( V_5 -> V_90 ) ;
F_139 ( V_5 -> V_88 ) ;
V_5 -> V_88 = NULL ;
if ( V_5 -> V_73 )
F_154 ( V_5 -> V_73 ) ;
F_139 ( V_7 ) ;
}
static void F_155 ( struct V_72 * V_73 )
{
struct V_5 * V_5 = F_23 ( V_73 ) ;
F_21 ( L_81 , ( int ) sizeof( * V_5 ) ) ;
V_73 -> V_317 = & V_318 ;
V_73 -> V_319 = V_320 ;
V_73 -> V_50 = V_321 | V_322 | V_323 ;
V_73 -> type = V_324 ;
V_73 -> V_325 = V_326 - 14 ;
V_73 -> V_327 = 10 ;
F_156 ( V_73 , & V_328 ) ;
F_144 ( & V_5 -> V_76 ) ;
}
static int F_157 ( struct V_6 * V_7 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_315 ; V_46 ++ ) {
if ( V_316 [ V_46 ] == NULL ) {
V_316 [ V_46 ] = V_7 ;
break;
}
}
if ( V_46 == V_315 )
return - 1 ;
return 0 ;
}
static int F_158 ( void * V_87 , bool V_329 )
{
struct V_6 * V_7 = V_87 ;
int V_330 = ! V_329 ;
int V_331 ;
F_80 ( & V_7 -> V_178 ) ;
if ( V_7 -> V_185 )
V_331 = 0 ;
else
V_331 = F_117 ( V_7 -> V_91 , F_118 ( V_7 -> V_91 , 0 ) ,
V_330 ? 0x82 : 0x81 , 0x40 , 0 , 0 , NULL , 0 ,
V_259 ) ;
F_94 ( & V_7 -> V_178 ) ;
return V_331 ;
}
static void F_159 ( struct V_6 * V_7 ,
struct V_311 * V_97 )
{
struct V_5 * V_5 = F_2 ( V_7 ) ;
struct V_17 * V_18 = & V_5 -> V_73 -> V_18 ;
char * V_332 ;
V_332 = F_146 ( 20 , V_181 ) ;
if ( ! V_332 )
F_9 ( V_18 , L_80 , V_53 ) ;
snprintf ( V_332 , 20 , L_82 ,
V_97 -> V_256 -> V_257 . V_258 ) ;
V_5 -> V_333 = F_160 ( V_332 ,
& F_148 ( V_97 ) -> V_18 ,
V_334 ,
& V_335 , V_7 ) ;
if ( ! V_5 -> V_333 ) {
F_9 ( V_18 , L_80 , V_53 ) ;
F_139 ( V_332 ) ;
return;
}
if ( F_161 ( V_5 -> V_333 ) < 0 ) {
F_162 ( V_5 -> V_333 ) ;
F_139 ( V_332 ) ;
V_5 -> V_333 = NULL ;
F_9 ( V_18 , L_83 , V_53 ) ;
return;
}
}
static struct V_6 * F_163 ( struct V_311 * V_97 ,
int V_22 )
{
int V_41 , V_46 ;
struct V_72 * V_73 ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_147 ( V_97 , V_22 ) ;
if ( ! V_7 )
return NULL ;
V_73 = F_164 ( sizeof( struct V_5 ) , L_84 , F_155 ) ;
if ( ! V_73 ) {
F_9 ( & V_97 -> V_18 , L_85 ) ;
goto exit;
}
V_5 = F_23 ( V_73 ) ;
V_7 -> V_8 . V_9 = V_5 ;
V_5 -> V_73 = V_73 ;
V_5 -> V_39 = V_7 ;
V_5 -> V_126 = F_165 ( V_97 , V_336 ,
V_277 ) ;
if ( ! V_5 -> V_126 ) {
F_9 ( & V_97 -> V_18 , L_86 ) ;
goto exit;
}
V_5 -> V_92 = F_165 ( V_97 , V_336 ,
V_281 ) ;
if ( ! V_5 -> V_92 ) {
F_9 ( & V_97 -> V_18 , L_87 ) ;
goto exit;
}
F_166 ( V_73 , & V_97 -> V_18 ) ;
F_167 ( V_73 , & V_337 ) ;
V_41 = F_168 ( V_73 ) ;
if ( V_41 ) {
F_9 ( & V_97 -> V_18 , L_88 ) ;
goto exit;
}
for ( V_46 = 0 ; V_46 < V_299 ; V_46 ++ ) {
V_5 -> V_300 [ V_46 ] = F_145 ( 0 , V_181 ) ;
if ( ! V_5 -> V_300 [ V_46 ] ) {
F_9 ( & V_97 -> V_18 , L_89 ) ;
goto exit;
}
V_5 -> V_301 [ V_46 ] = F_146 ( V_129 ,
V_181 ) ;
if ( ! V_5 -> V_301 [ V_46 ] ) {
F_9 ( & V_97 -> V_18 , L_90 ) ;
goto exit;
}
}
V_5 -> V_90 = F_145 ( 0 , V_181 ) ;
if ( ! V_5 -> V_90 ) {
F_9 ( & V_97 -> V_18 , L_91 ) ;
goto exit;
}
V_5 -> V_88 = F_146 ( V_89 , V_181 ) ;
if ( ! V_5 -> V_88 ) {
F_9 ( & V_97 -> V_18 , L_92 ) ;
goto exit;
}
F_157 ( V_7 ) ;
F_132 ( V_7 ) ;
F_159 ( V_7 , V_97 ) ;
return V_7 ;
exit:
F_152 ( V_7 ) ;
return NULL ;
}
static void F_169 ( struct V_1 * V_34 )
{
struct V_193 * V_194 ;
if ( ! V_34 )
return;
V_194 = V_34 -> V_194 ;
if ( V_194 ) {
F_138 ( V_194 -> V_35 ) ;
V_194 -> V_35 = NULL ;
V_34 -> V_194 = NULL ;
F_139 ( V_194 ) ;
}
}
static void F_170 ( struct V_6 * V_7 )
{
struct V_1 * V_34 = F_3 ( V_7 ) ;
if ( ! V_34 )
return;
F_18 ( V_34 -> V_156 , NULL ) ;
F_135 ( V_34 ) ;
if ( V_34 -> V_45 ) {
F_80 ( & V_34 -> V_45 -> V_303 ) ;
if ( -- V_34 -> V_45 -> V_338 == 0 )
F_171 ( V_34 -> V_45 ) ;
else
F_94 ( & V_34 -> V_45 -> V_303 ) ;
}
F_169 ( V_34 ) ;
F_139 ( V_34 ) ;
F_139 ( V_7 ) ;
}
static struct V_6 * F_172 (
struct V_311 * V_97 , int V_43 )
{
struct V_6 * V_7 ;
struct V_1 * V_34 ;
int V_308 ;
struct V_193 * V_194 ;
V_7 = F_147 ( V_97 , V_43 ) ;
if ( ! V_7 )
return NULL ;
V_34 = F_146 ( sizeof( * V_34 ) , V_181 ) ;
if ( ! V_34 )
goto exit;
V_34 -> V_39 = V_7 ;
V_7 -> V_8 . V_10 = V_34 ;
if ( ( V_43 & V_23 ) == V_32 ) {
V_308 = 2 ;
V_34 -> V_194 = F_146 ( sizeof( struct V_193 ) ,
V_181 ) ;
if ( V_34 -> V_194 ) {
V_194 = V_34 -> V_194 ;
V_194 -> V_35 = F_145 ( 0 , V_181 ) ;
if ( V_194 -> V_35 ) {
F_150 ( & V_194 -> V_178 ) ;
F_173 ( & V_194 -> V_229 ) ;
V_194 -> V_196 = F_165 (
V_97 ,
V_339 ,
V_277 ) ;
} else
F_169 ( V_34 ) ;
}
}
else
V_308 = 1 ;
if ( F_140 ( V_34 , V_308 , V_340 ,
V_341 ) )
goto exit;
V_34 -> V_126 = F_165 ( V_97 , V_336 ,
V_277 ) ;
if ( ! V_34 -> V_126 ) {
F_9 ( & V_97 -> V_18 , L_93 ) ;
goto V_342;
}
if ( !
( V_34 -> V_92 =
F_165 ( V_97 , V_336 , V_281 ) ) ) {
F_9 ( & V_97 -> V_18 , L_93 ) ;
goto V_342;
}
V_34 -> V_268 = F_129 ;
F_18 ( V_34 -> V_156 , V_34 ) ;
F_132 ( V_7 ) ;
return V_7 ;
V_342:
F_135 ( V_34 ) ;
exit:
F_169 ( V_34 ) ;
F_139 ( V_34 ) ;
F_139 ( V_7 ) ;
return NULL ;
}
static
struct V_6 * F_174 ( struct V_311 * V_97 ,
int V_43 ,
struct V_44 * V_40 )
{
struct V_6 * V_7 ;
struct V_1 * V_34 ;
int V_22 ;
V_22 = V_169 ;
V_22 &= ~ V_23 ;
V_22 |= F_10 ( V_43 ) ;
if ( ( V_22 & V_23 ) == V_42 )
return NULL ;
V_7 = F_147 ( V_97 , V_22 ) ;
if ( ! V_7 )
return NULL ;
V_34 = F_146 ( sizeof( * V_34 ) , V_181 ) ;
if ( ! V_34 )
goto exit;
V_7 -> V_8 . V_10 = V_34 ;
V_34 -> V_39 = V_7 ;
if ( F_140
( V_34 , 1 , V_285 , V_343 ) )
goto exit;
V_34 -> V_187 -- ;
V_34 -> V_268 = F_126 ;
V_34 -> V_45 = V_40 ;
F_80 ( & V_34 -> V_45 -> V_303 ) ;
V_34 -> V_45 -> V_338 ++ ;
F_94 ( & V_34 -> V_45 -> V_303 ) ;
F_18 ( V_34 -> V_156 , V_34 ) ;
F_132 ( V_7 ) ;
return V_7 ;
exit:
if ( V_34 ) {
F_137 ( V_307 , V_34 -> V_156 ) ;
F_139 ( V_34 ) ;
}
if ( V_7 )
F_139 ( V_7 ) ;
return NULL ;
}
static void F_171 ( struct V_44 * V_40 )
{
F_138 ( V_40 -> V_305 ) ;
F_139 ( V_40 -> V_344 ) ;
F_94 ( & V_40 -> V_303 ) ;
F_139 ( V_40 ) ;
}
static
struct V_44 * F_175 ( struct V_311 * V_97 )
{
struct V_44 * V_40 = F_146 ( sizeof( * V_40 ) , V_181 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_345 = F_165 ( V_97 , V_339 ,
V_277 ) ;
if ( ! V_40 -> V_345 ) {
F_9 ( & V_97 -> V_18 , L_94 ) ;
goto exit;
}
V_40 -> V_305 = F_145 ( 0 , V_181 ) ;
if ( ! V_40 -> V_305 ) {
F_9 ( & V_97 -> V_18 , L_95 ) ;
goto exit;
}
V_40 -> V_344 =
F_146 ( F_56 ( V_40 -> V_345 -> V_127 ) ,
V_181 ) ;
if ( ! V_40 -> V_344 ) {
F_9 ( & V_97 -> V_18 , L_96 ) ;
goto exit;
}
F_150 ( & V_40 -> V_303 ) ;
return V_40 ;
exit:
F_139 ( V_40 -> V_344 ) ;
F_138 ( V_40 -> V_305 ) ;
F_139 ( V_40 ) ;
return NULL ;
}
static int F_176 ( struct V_311 * V_97 )
{
struct V_195 * V_346 = F_148 ( V_97 ) ;
T_5 V_347 [ 17 ] ;
T_2 V_255 = V_97 -> V_256 -> V_257 . V_258 ;
T_8 V_41 ;
if ( F_117 ( V_346 , F_118 ( V_346 , 0 ) ,
0x86 , 0xC0 , 0 , 0 , V_347 , 17 ,
V_259 ) != 0x11 ) {
return - V_348 ;
}
switch ( V_347 [ V_255 ] ) {
case 0x0 :
V_41 = 0 ;
break;
case 0x1 :
V_41 = V_30 ;
break;
case 0x2 :
V_41 = V_27 ;
break;
case 0x3 :
V_41 = V_28 ;
break;
case 0x4 :
V_41 = V_25 ;
break;
case 0x5 :
V_41 = V_26 ;
break;
case 0x6 :
V_41 = V_24 ;
break;
case 0x7 :
V_41 = V_33 ;
break;
case 0x8 :
V_41 = V_32 ;
break;
case 0x9 :
V_41 = V_349 ;
break;
case 0xa :
V_41 = V_29 ;
break;
case 0xb :
V_41 = V_350 ;
break;
default:
V_41 = 0 ;
}
if ( V_41 )
V_41 |= V_351 ;
if ( V_347 [ 16 ] & 0x1 )
V_41 |= V_125 ;
return V_41 ;
}
static int F_177 ( struct V_311 * V_97 ,
const struct V_352 * V_353 )
{
int V_40 , V_46 , V_255 , V_22 ;
unsigned char V_354 ;
struct V_6 * V_7 = NULL ;
struct V_44 * V_45 ;
struct V_6 * V_355 = NULL ;
V_255 = V_97 -> V_256 -> V_257 . V_258 ;
if ( V_353 -> V_356 )
V_22 = ( ( T_2 * ) ( V_353 -> V_356 ) ) [ V_255 ] ;
else
V_22 = F_176 ( V_97 ) ;
if ( V_97 -> V_357 -> V_257 . V_358 != 0xFF ) {
F_9 ( & V_97 -> V_18 , L_97 ) ;
return - V_57 ;
}
if ( V_97 -> V_359 > 1 )
F_178 ( F_148 ( V_97 ) , V_255 , 1 ) ;
V_97 -> V_360 = 1 ;
switch ( V_22 & V_361 ) {
case V_169 :
if ( ( V_22 & V_23 ) == V_33 ) {
if ( ! V_362 ) {
V_7 = F_163 ( V_97 ,
V_22 ) ;
if ( ! V_7 )
goto exit;
V_355 = V_7 ;
}
}
if ( F_179 ( V_97 , & V_354 ) )
goto exit;
V_45 = F_175 ( V_97 ) ;
if ( ! V_45 )
goto exit;
for ( V_46 = 1 , V_40 = 0 ; V_46 < 0x100 ; V_46 = V_46 << 1 , V_40 ++ ) {
if ( V_354 & V_46 ) {
V_7 = F_174 (
V_97 , V_46 , V_45 ) ;
if ( ! V_7 )
goto exit;
}
}
if ( V_355 )
V_7 = V_355 ;
break;
case V_351 :
if ( ( V_22 & V_23 ) == V_33 ) {
if ( ! V_362 )
V_7 =
F_163 ( V_97 , V_22 ) ;
} else {
V_7 =
F_172 ( V_97 , V_22 ) ;
}
if ( ! V_7 )
goto exit;
break;
default:
goto exit;
}
F_180 ( V_97 , V_7 ) ;
return 0 ;
exit:
F_181 ( V_97 ) ;
return - V_57 ;
}
static void F_182 ( struct V_311 * V_97 )
{
F_181 ( V_97 ) ;
F_180 ( V_97 , NULL ) ;
}
static void V_313 ( struct V_171 * V_87 )
{
struct V_6 * V_7 =
F_77 ( V_87 , struct V_6 , V_313 ) ;
F_81 ( V_7 -> V_97 ) ;
}
static void V_314 ( struct V_171 * V_87 )
{
struct V_6 * V_7 =
F_77 ( V_87 , struct V_6 , V_314 ) ;
F_92 ( V_7 -> V_97 ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
if ( V_7 -> V_91 -> V_241 == V_363 ) {
if ( ! V_7 -> V_364 ) {
V_7 -> V_364 = 1 ;
F_20 ( & V_7 -> V_313 ) ;
}
}
if ( V_7 -> V_91 -> V_241 != V_365 )
return - V_64 ;
F_58 ( V_7 -> V_91 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
if ( V_7 -> V_91 -> V_241 != V_363 ) {
if ( V_7 -> V_364 ) {
V_7 -> V_364 = 0 ;
F_20 ( & V_7 -> V_314 ) ;
return - V_64 ;
}
}
V_7 -> V_364 = 0 ;
return 0 ;
}
static int F_183 ( struct V_311 * V_366 , T_9 V_367 )
{
int V_46 , V_41 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_48 [ V_46 ] && ( V_48 [ V_46 ] -> V_97 == V_366 ) ) {
V_41 = F_90 ( V_48 [ V_46 ] ) ;
if ( V_41 )
goto V_189;
}
}
for ( V_46 = 0 ; V_46 < V_315 ; V_46 ++ ) {
if ( V_316 [ V_46 ] &&
( V_316 [ V_46 ] -> V_97 == V_366 ) ) {
V_41 = F_30 ( V_316 [ V_46 ] ) ;
if ( V_41 )
goto V_189;
}
}
V_189:
return 0 ;
}
static int F_184 ( struct V_311 * V_366 )
{
int V_46 , V_41 = 0 ;
struct V_5 * V_5 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_48 [ V_46 ] && ( V_48 [ V_46 ] -> V_97 == V_366 ) ) {
if ( F_3 ( V_48 [ V_46 ] ) -> V_162 ) {
V_41 =
F_89 ( V_48 [ V_46 ] , V_302 ) ;
F_99 ( F_3 ( V_48 [ V_46 ] ) ) ;
if ( V_41 )
goto V_189;
}
}
}
for ( V_46 = 0 ; V_46 < V_315 ; V_46 ++ ) {
if ( V_316 [ V_46 ] &&
( V_316 [ V_46 ] -> V_97 == V_366 ) ) {
V_5 = F_2 ( V_316 [ V_46 ] ) ;
if ( V_5 -> V_50 & V_368 ) {
if ( V_5 -> V_75 ) {
F_133 ( & V_366 -> V_18 ,
L_98
L_99 ) ;
F_36 ( V_5 -> V_75 ,
V_5 -> V_73 ) ;
V_5 -> V_75 = NULL ;
}
V_41 = F_25 ( V_316 [ V_46 ] ) ;
if ( V_41 )
goto V_189;
}
}
}
V_189:
return V_41 ;
}
static void V_71 ( struct V_171 * V_87 )
{
struct V_6 * V_7 =
F_77 ( V_87 , struct V_6 , V_71 ) ;
struct V_195 * V_91 = V_7 -> V_91 ;
int V_41 ;
if ( V_7 -> V_185 ) {
F_21 ( L_100 ) ;
} else {
V_41 = F_185 ( V_91 , V_7 -> V_97 ) ;
if ( V_41 < 0 )
F_21 ( L_101 , V_41 ) ;
else {
F_186 ( V_91 ) ;
F_187 ( V_91 ) ;
}
}
}
static void V_182 ( struct V_369 * V_180 )
{
struct V_6 * V_7 = F_77 ( V_180 , struct V_6 , V_180 ) ;
F_170 ( V_7 ) ;
}
static void F_181 ( struct V_311 * V_97 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
if ( V_48 [ V_46 ] &&
( V_48 [ V_46 ] -> V_97 == V_97 ) ) {
V_7 = F_3 ( V_48 [ V_46 ] ) ;
F_83 ( & V_7 -> V_167 ) ;
V_3 = F_85 ( V_7 -> V_3 ) ;
F_86 ( & V_7 -> V_167 ) ;
if ( V_3 )
F_188 ( V_3 ) ;
F_80 ( & V_7 -> V_39 -> V_178 ) ;
F_84 ( V_3 ) ;
V_7 -> V_39 -> V_185 = 1 ;
F_94 ( & V_7 -> V_39 -> V_178 ) ;
F_91 ( & V_48 [ V_46 ] -> V_180 , V_182 ) ;
}
}
for ( V_46 = 0 ; V_46 < V_315 ; V_46 ++ ) {
if ( V_316 [ V_46 ] &&
( V_316 [ V_46 ] -> V_97 == V_97 ) ) {
struct V_333 * V_370 = F_2 ( V_316 [ V_46 ] ) -> V_333 ;
F_28 ( F_2 ( V_316 [ V_46 ] ) -> V_73 ) ;
F_30 ( V_316 [ V_46 ] ) ;
F_97 ( & V_316 [ V_46 ] -> V_314 ) ;
F_97 ( & V_316 [ V_46 ] -> V_313 ) ;
if ( V_370 ) {
F_189 ( V_370 ) ;
F_162 ( V_370 ) ;
}
F_152 ( V_316 [ V_46 ] ) ;
}
}
}
static struct V_371 * F_165 ( struct V_311 * V_312 ,
int type , int V_372 )
{
int V_46 ;
struct V_373 * V_366 = V_312 -> V_357 ;
struct V_371 * V_196 ;
for ( V_46 = 0 ; V_46 < V_366 -> V_257 . V_374 ; V_46 ++ ) {
V_196 = & V_366 -> V_375 [ V_46 ] . V_257 ;
if ( ( ( V_196 -> V_93 & V_376 ) == V_372 ) &&
( F_190 ( V_196 ) == type ) )
return V_196 ;
}
return NULL ;
}
static int F_179 ( struct V_311 * V_312 , unsigned char * V_377 )
{
int V_46 ;
struct V_373 * V_366 = V_312 -> V_357 ;
if ( V_366 -> V_378 == 3 ) {
* V_377 = V_366 -> V_379 [ 2 ] ;
return 0 ;
}
for ( V_46 = 0 ; V_46 < V_366 -> V_257 . V_374 ; V_46 ++ ) {
if ( V_366 -> V_375 [ V_46 ] . V_378 == 3 ) {
* V_377 = V_366 -> V_375 [ V_46 ] . V_379 [ 2 ] ;
return 0 ;
}
}
return - 1 ;
}
static int F_125 ( struct V_44 * V_45 ,
struct V_195 * V_91 , T_7 V_380 )
{
int V_41 ;
F_105 ( V_45 -> V_305 , V_91 ,
F_106 ( V_91 ,
V_45 -> V_345 -> V_93 & 0x7F ) ,
V_45 -> V_344 ,
1 ,
F_124 , V_45 ,
V_45 -> V_345 -> V_200 ) ;
V_41 = F_41 ( V_45 -> V_305 , V_380 ) ;
if ( V_41 )
F_42 ( & V_91 -> V_18 , L_102 , V_53 ,
V_41 ) ;
return V_41 ;
}
static int T_10 F_191 ( void )
{
int V_46 ;
int V_41 ;
F_17 ( V_381 L_103 , V_382 ) ;
F_144 ( & V_51 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
V_48 [ V_46 ] = NULL ;
V_307 = F_192 ( V_47 ) ;
if ( ! V_307 )
return - V_383 ;
V_307 -> V_176 = V_384 ;
V_307 -> V_385 = V_386 ;
V_307 -> V_387 = V_387 ;
V_307 -> V_15 = V_298 ;
if ( V_388 )
V_307 -> V_389 = V_388 ;
V_307 -> V_390 = 0 ;
V_307 -> V_391 = V_47 ;
V_307 -> type = V_392 ;
V_307 -> V_393 = V_394 ;
V_307 -> V_50 = V_395 | V_396 ;
V_307 -> V_397 = V_398 ;
F_62 ( & V_307 -> V_397 ) ;
F_193 ( V_307 , & V_399 ) ;
V_41 = F_194 ( V_307 ) ;
if ( V_41 ) {
F_17 ( V_52 L_104 ,
V_53 , V_41 ) ;
return V_41 ;
}
V_41 = F_195 ( & V_400 ) ;
if ( V_41 ) {
F_17 ( V_52 L_105 ,
V_41 ) ;
F_196 ( V_307 ) ;
return V_41 ;
}
return 0 ;
}
static void T_11 F_197 ( void )
{
F_17 ( V_381 L_106 ) ;
F_196 ( V_307 ) ;
F_198 ( & V_400 ) ;
}
