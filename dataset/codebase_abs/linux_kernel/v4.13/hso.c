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
F_16 ( L_15 , V_49 ) ;
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
static void F_18 ( int V_50 , const char * V_51 ,
struct V_2 * V_3 )
{
char * V_52 ;
switch ( V_50 ) {
case - V_53 :
V_52 = L_16 ;
break;
case - V_54 :
V_52 = L_17 ;
break;
case - V_55 :
V_52 = L_18 ;
break;
case - V_56 :
V_52 = L_19 ;
break;
case - V_57 :
V_52 = L_20 ;
break;
case - V_58 :
V_52 = L_21 ;
break;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_62 :
V_52 = L_22 ;
break;
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
V_52 = L_23 ;
if ( V_3 )
F_19 ( V_3 -> V_67 ) ;
break;
default:
V_52 = L_24 ;
break;
}
F_20 ( 0x1 , L_25 ,
V_51 , V_52 , V_50 ) ;
}
static int F_21 ( struct V_68 * V_69 )
{
struct V_1 * V_70 = F_22 ( V_69 ) ;
unsigned long V_47 = 0 ;
if ( ! V_70 ) {
F_8 ( & V_69 -> V_15 , L_26 ) ;
return - V_53 ;
}
V_70 -> V_71 = NULL ;
F_13 ( & V_70 -> V_72 , V_47 ) ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = 0 ;
V_70 -> V_76 = sizeof( struct V_77 ) ;
F_14 ( & V_70 -> V_72 , V_47 ) ;
F_23 ( V_78 , & V_70 -> V_47 ) ;
F_24 ( V_70 -> V_36 ) ;
F_25 ( V_69 ) ;
return 0 ;
}
static int F_26 ( struct V_68 * V_69 )
{
struct V_1 * V_70 = F_22 ( V_69 ) ;
F_27 ( V_69 ) ;
F_28 ( V_78 , & V_70 -> V_47 ) ;
F_29 ( V_70 -> V_36 ) ;
return 0 ;
}
static void F_30 ( struct V_32 * V_32 )
{
struct V_1 * V_70 = V_32 -> V_79 ;
int V_50 = V_32 -> V_50 ;
if ( ! V_70 || ! F_31 ( V_78 , & V_70 -> V_47 ) ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_27 , V_49 ) ;
return;
}
if ( ! F_32 ( V_70 -> V_69 ) ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_28 ,
V_49 ) ;
return;
}
if ( V_50 )
F_18 ( V_50 , V_49 , V_70 -> V_36 ) ;
F_33 ( V_70 -> V_36 ) ;
F_34 ( V_70 -> V_69 ) ;
}
static T_3 F_35 ( struct V_80 * V_81 ,
struct V_68 * V_69 )
{
struct V_1 * V_70 = F_22 ( V_69 ) ;
int V_38 ;
F_27 ( V_69 ) ;
if ( F_36 ( V_70 -> V_36 ) == - V_60 ) {
V_70 -> V_71 = V_81 ;
return V_82 ;
}
F_37 ( V_81 -> V_83 , V_81 -> V_11 ) ;
memcpy ( V_70 -> V_84 , V_81 -> V_83 , V_81 -> V_11 ) ;
F_20 ( 0x1 , L_29 , V_81 -> V_11 , V_85 ) ;
F_38 ( V_70 -> V_86 ,
V_70 -> V_36 -> V_87 ,
F_39 ( V_70 -> V_36 -> V_87 ,
V_70 -> V_88 ->
V_89 & 0x7F ) ,
V_70 -> V_84 , V_81 -> V_11 , F_30 ,
V_70 ) ;
V_70 -> V_86 -> V_90 |= V_91 ;
V_38 = F_40 ( V_70 -> V_86 , V_92 ) ;
if ( V_38 ) {
F_41 ( & V_70 -> V_36 -> V_67 -> V_15 ,
L_30 , V_38 ) ;
V_69 -> V_93 . V_94 ++ ;
F_25 ( V_69 ) ;
} else {
V_69 -> V_93 . V_95 ++ ;
V_69 -> V_93 . V_96 += V_81 -> V_11 ;
}
F_42 ( V_81 ) ;
return V_82 ;
}
static void F_43 ( struct V_68 * V_69 )
{
struct V_1 * V_70 = F_22 ( V_69 ) ;
if ( ! V_70 )
return;
F_41 ( & V_69 -> V_15 , L_31 ) ;
if ( V_70 -> V_86 &&
( V_70 -> V_86 -> V_50 == - V_97 ) )
F_44 ( V_70 -> V_86 ) ;
V_69 -> V_93 . V_94 ++ ;
}
static void F_45 ( struct V_1 * V_70 , unsigned char * V_98 ,
unsigned int V_99 , unsigned char V_100 )
{
unsigned short V_101 ;
unsigned short V_102 = 0 ;
unsigned short V_103 ;
F_20 ( 0x1 , L_32 , V_99 ) ;
F_46 ( V_98 , F_47 ( 128 , ( int ) V_99 ) ) ;
while ( V_99 ) {
switch ( V_70 -> V_73 ) {
case V_74 :
V_101 =
( V_99 <
V_70 -> V_76 ) ? V_99 : V_70 ->
V_76 ;
memcpy ( ( ( unsigned char * ) ( & V_70 -> V_104 ) ) +
V_70 -> V_75 , V_98 + V_102 ,
V_101 ) ;
V_70 -> V_75 += V_101 ;
V_102 += V_101 ;
V_70 -> V_76 -= V_101 ;
V_99 -= V_101 ;
if ( ! V_70 -> V_76 ) {
V_103 = F_48 ( V_70 -> V_104 . V_105 ) ;
if ( ( V_103 > V_106 ) ||
( V_103 < sizeof( struct V_77 ) ) ) {
F_8 ( & V_70 -> V_69 -> V_15 ,
L_33 ,
V_103 ) ;
V_70 -> V_73 = V_107 ;
continue;
}
V_70 -> V_108 = F_49 ( V_70 -> V_69 ,
V_103 ) ;
if ( ! V_70 -> V_108 ) {
F_20 ( 0x1 , L_34 ) ;
V_70 -> V_73 = V_107 ;
continue;
}
F_50 ( V_70 -> V_108 ,
( char * ) & ( V_70 -> V_104 ) ,
sizeof( struct V_77 ) ) ;
V_70 -> V_75 = sizeof( struct V_77 ) ;
V_70 -> V_76 =
V_103 - sizeof( struct V_77 ) ;
V_70 -> V_73 = V_109 ;
}
break;
case V_109 :
V_101 = ( V_99 < V_70 -> V_76 )
? V_99 : V_70 -> V_76 ;
F_50 ( V_70 -> V_108 ,
V_98 + V_102 ,
V_101 ) ;
V_70 -> V_76 -= V_101 ;
V_99 -= V_101 ;
V_102 += V_101 ;
V_70 -> V_75 += V_101 ;
if ( ! V_70 -> V_76 ) {
V_70 -> V_108 -> V_110 = F_51 ( V_111 ) ;
F_52 ( V_70 -> V_108 ) ;
F_53 ( V_70 -> V_108 ) ;
V_70 -> V_108 = NULL ;
V_70 -> V_69 -> V_93 . V_112 ++ ;
V_70 -> V_69 -> V_93 . V_113 += V_70 -> V_75 ;
V_70 -> V_75 = 0 ;
V_70 -> V_76 = sizeof( struct V_77 ) ;
V_70 -> V_73 = V_74 ;
}
break;
case V_107 :
F_20 ( 0x1 , L_35 ) ;
V_99 = 0 ;
break;
default:
F_20 ( 0x1 , L_36 ) ;
V_99 -- ;
break;
}
}
if ( V_100 ) {
if ( V_70 -> V_73 == V_107 ) {
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = 0 ;
V_70 -> V_76 = sizeof( struct V_77 ) ;
}
}
}
static void F_54 ( struct V_32 * V_32 , T_4 V_114 )
{
static const T_5 V_115 [ 4 ] = { 0xDE , 0xAD , 0xBE , 0xEF } ;
T_2 V_116 = V_32 -> V_117 % F_55 ( V_114 ) ;
if ( ( ( V_116 == 5 ) || ( V_116 == 6 ) ) &&
! memcmp ( ( ( T_5 * ) V_32 -> V_118 ) + V_32 -> V_117 - 4 ,
V_115 , 4 ) ) {
V_32 -> V_117 -= 4 ;
}
}
static void F_56 ( struct V_32 * V_32 )
{
struct V_1 * V_70 = V_32 -> V_79 ;
struct V_68 * V_69 ;
int V_38 ;
int V_50 = V_32 -> V_50 ;
if ( V_50 ) {
F_18 ( V_50 , V_49 , V_70 -> V_36 ) ;
return;
}
if ( ! V_70 || ! F_31 ( V_78 , & V_70 -> V_47 ) ) {
F_20 ( 0x1 , L_37 ) ;
return;
}
F_57 ( V_32 -> V_15 ) ;
V_69 = V_70 -> V_69 ;
if ( ! F_32 ( V_69 ) ) {
return;
}
if ( V_70 -> V_36 -> V_19 & V_119 )
F_54 ( V_32 , V_70 -> V_120 -> V_121 ) ;
if ( V_32 -> V_117 ) {
F_58 ( & V_70 -> V_72 ) ;
F_45 ( V_70 , V_32 -> V_118 , V_32 -> V_117 ,
( V_32 -> V_122 >
V_32 -> V_117 ) ? 1 : 0 ) ;
F_59 ( & V_70 -> V_72 ) ;
}
F_38 ( V_32 ,
V_70 -> V_36 -> V_87 ,
F_60 ( V_70 -> V_36 -> V_87 ,
V_70 -> V_120 ->
V_89 & 0x7F ) ,
V_32 -> V_118 , V_123 ,
F_56 , V_70 ) ;
V_38 = F_40 ( V_32 , V_92 ) ;
if ( V_38 )
F_41 ( & V_70 -> V_36 -> V_67 -> V_15 ,
L_38 , V_49 ,
V_38 ) ;
}
static void F_61 ( struct V_124 * V_125 )
{
V_125 -> V_126 &=
~ ( V_127
| V_128
| V_129
| V_130
| V_131
| V_132
| V_133
| V_134 ) ;
V_125 -> V_135 &= ~ V_136 ;
V_125 -> V_137 &=
~ ( V_138
| V_139
| V_140
| V_141
| V_142 ) ;
V_125 -> V_143 &=
~ ( V_144
| V_145
| V_146
| V_147 ) ;
V_125 -> V_143 |= V_148 ;
F_62 ( V_125 , 115200 , 115200 ) ;
}
static void F_63 ( struct V_149 * V_150 ,
struct V_124 * V_151 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
if ( ! V_31 ) {
F_16 ( L_39 , V_49 ) ;
return;
}
F_20 ( 0x8 , L_40 , V_31 -> V_153 ) ;
V_150 -> V_125 . V_126 &= ~ V_134 ;
V_150 -> V_125 . V_143 &=
~ ( V_144
| V_145
| V_146
| V_147 ) ;
V_150 -> V_125 . V_143 |= V_148 ;
F_64 ( V_150 , 115200 , 115200 ) ;
}
static void F_65 ( struct V_6 * V_31 , struct V_32 * V_32 )
{
int V_38 ;
F_38 ( V_32 , V_31 -> V_36 -> V_87 ,
F_60 ( V_31 -> V_36 -> V_87 ,
V_31 -> V_120 ->
V_89 & 0x7F ) ,
V_32 -> V_118 , V_31 -> V_154 ,
V_155 , V_31 ) ;
V_38 = F_40 ( V_32 , V_92 ) ;
if ( V_38 ) {
F_8 ( & V_32 -> V_15 -> V_15 , L_41 ,
V_49 , V_38 ) ;
}
}
static void F_66 ( struct V_6 * V_31 )
{
int V_99 ;
struct V_32 * V_156 ;
while ( V_31 -> V_157 [ V_31 -> V_158 ] ) {
V_156 = V_31 -> V_35 [ V_31 -> V_158 ] ;
V_99 = F_67 ( V_156 , V_31 ) ;
if ( V_99 == - 1 )
return;
if ( V_99 == 0 ) {
V_31 -> V_158 ++ ;
if ( V_31 -> V_158 >= V_31 -> V_34 )
V_31 -> V_158 = 0 ;
F_65 ( V_31 , V_156 ) ;
}
}
}
static void F_68 ( struct V_6 * V_31 )
{
int V_99 = 0 ;
struct V_32 * V_32 ;
V_32 = V_31 -> V_35 [ 0 ] ;
if ( V_31 -> V_40 . V_99 > 0 ) {
V_99 = F_67 ( V_32 , V_31 ) ;
if ( V_99 == - 1 )
return;
}
if ( V_99 == 0 && ( ( V_32 -> V_117 != 0 ) ||
( V_31 -> V_159 == V_160 ) ) ) {
V_31 -> V_159 = V_161 ;
F_69 ( V_31 ) ;
} else
V_31 -> V_159 = V_162 ;
}
static void V_155 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_79 ;
int V_50 = V_32 -> V_50 ;
F_20 ( 0x8 , L_42 , V_50 ) ;
if ( ! V_31 ) {
F_20 ( 0x1 , L_43 ) ;
return;
}
if ( V_50 ) {
F_18 ( V_50 , V_49 , V_31 -> V_36 ) ;
return;
}
F_20 ( 0x1 , L_44 , V_32 -> V_117 ) ;
F_37 ( V_32 -> V_118 , V_32 -> V_117 ) ;
if ( V_31 -> V_40 . V_99 == 0 )
return;
if ( V_31 -> V_36 -> V_19 & V_119 )
F_54 ( V_32 , V_31 -> V_120 -> V_121 ) ;
F_58 ( & V_31 -> V_163 ) ;
V_31 -> V_157 [ F_7 ( V_31 , V_32 ) ] = 1 ;
F_66 ( V_31 ) ;
F_59 ( & V_31 -> V_163 ) ;
}
static void F_70 ( struct V_6 * V_31 )
{
unsigned long V_47 ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
if ( ( V_31 -> V_36 -> V_19 & V_164 ) )
F_68 ( V_31 ) ;
else
F_66 ( V_31 ) ;
F_14 ( & V_31 -> V_163 , V_47 ) ;
}
static void F_71 ( struct V_149 * V_150 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
F_72 ( & V_31 -> V_165 ) ;
}
static int F_73 ( struct V_149 * V_150 , struct V_166 * V_167 )
{
struct V_6 * V_31 = F_12 ( V_150 -> V_46 ) ;
int V_38 ;
if ( V_31 == NULL || V_31 -> V_168 != V_169 ) {
F_74 ( 1 ) ;
V_150 -> V_152 = NULL ;
F_20 ( 0x1 , L_45 ) ;
return - V_53 ;
}
F_75 ( & V_31 -> V_36 -> V_170 ) ;
V_38 = F_76 ( V_31 -> V_36 -> V_67 ) ;
if ( V_38 < 0 )
goto V_171;
F_20 ( 0x1 , L_46 , V_31 -> V_153 ) ;
V_150 -> V_152 = V_31 ;
F_77 ( & V_31 -> V_40 , V_150 ) ;
V_31 -> V_40 . V_99 ++ ;
if ( V_31 -> V_40 . V_99 == 1 ) {
V_31 -> V_159 = V_162 ;
F_63 ( V_150 , NULL ) ;
F_78 ( & V_31 -> V_165 ,
( void (*) ( unsigned long ) ) F_70 ,
( unsigned long ) V_31 ) ;
V_38 = F_79 ( V_31 -> V_36 , V_172 ) ;
if ( V_38 ) {
F_80 ( V_31 -> V_36 ) ;
V_31 -> V_40 . V_99 -- ;
} else {
F_81 ( & V_31 -> V_36 -> V_173 ) ;
}
} else {
F_20 ( 0x1 , L_47 ) ;
}
F_82 ( V_31 -> V_36 -> V_67 ) ;
if ( V_38 )
F_83 ( V_150 , V_174 | V_175 , 0 ) ;
V_171:
F_84 ( & V_31 -> V_36 -> V_170 ) ;
return V_38 ;
}
static void F_85 ( struct V_149 * V_150 , struct V_166 * V_167 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
T_5 V_176 ;
F_20 ( 0x1 , L_48 ) ;
if ( V_31 == NULL )
return;
F_75 ( & V_31 -> V_36 -> V_170 ) ;
V_176 = V_31 -> V_36 -> V_176 ;
if ( ! V_176 )
F_76 ( V_31 -> V_36 -> V_67 ) ;
V_31 -> V_40 . V_99 -- ;
if ( V_31 -> V_40 . V_99 <= 0 ) {
V_31 -> V_40 . V_99 = 0 ;
F_77 ( & V_31 -> V_40 , NULL ) ;
if ( ! V_176 )
F_80 ( V_31 -> V_36 ) ;
F_86 ( & V_31 -> V_165 ) ;
}
if ( ! V_176 )
F_82 ( V_31 -> V_36 -> V_67 ) ;
F_84 ( & V_31 -> V_36 -> V_170 ) ;
}
static int F_87 ( struct V_149 * V_150 , const unsigned char * V_10 ,
int V_99 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
int V_177 , V_96 ;
unsigned long V_47 ;
if ( V_31 == NULL ) {
F_16 ( L_49 , V_49 ) ;
return - V_53 ;
}
F_13 ( & V_31 -> V_163 , V_47 ) ;
V_177 = V_31 -> V_178 - V_31 -> V_179 ;
V_96 = ( V_99 < V_177 ) ? V_99 : V_177 ;
if ( ! V_96 )
goto V_180;
memcpy ( V_31 -> V_181 + V_31 -> V_179 , V_10 , V_96 ) ;
V_31 -> V_179 += V_96 ;
V_180:
F_14 ( & V_31 -> V_163 , V_47 ) ;
F_88 ( V_31 ) ;
return V_96 ;
}
static int F_89 ( struct V_149 * V_150 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
int V_182 ;
unsigned long V_47 ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
V_182 = V_31 -> V_178 - V_31 -> V_179 ;
F_14 ( & V_31 -> V_163 , V_47 ) ;
return V_182 ;
}
static void F_90 ( struct V_149 * V_150 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
if ( ! V_31 )
return;
F_91 ( & V_31 -> V_36 -> V_173 , V_183 ) ;
}
static void F_92 ( struct V_149 * V_150 , struct V_124 * V_151 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
unsigned long V_47 ;
if ( V_151 )
F_20 ( 0x16 , L_50 ,
V_150 -> V_125 . V_143 , V_151 -> V_143 ) ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
if ( V_31 -> V_40 . V_99 )
F_63 ( V_150 , V_151 ) ;
else
V_150 -> V_125 = * V_151 ;
F_14 ( & V_31 -> V_163 , V_47 ) ;
}
static int F_93 ( struct V_149 * V_150 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
int V_184 ;
unsigned long V_47 ;
if ( V_31 == NULL )
return 0 ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
V_184 = V_31 -> V_179 ;
F_14 ( & V_31 -> V_163 , V_47 ) ;
return V_184 ;
}
static int F_94 ( struct V_6 * V_31 ,
struct V_185 * V_186 ,
struct V_187 * V_87 )
{
int V_38 ;
if ( V_31 -> V_36 -> V_176 )
return - V_53 ;
F_95 ( V_186 -> V_32 , V_87 ,
F_96 ( V_87 ,
V_186 -> V_188 ->
V_89 & 0x7F ) ,
& V_186 -> V_189 ,
sizeof( struct V_190 ) ,
V_191 , V_31 ,
V_186 -> V_188 -> V_192 ) ;
V_38 = F_40 ( V_186 -> V_32 , V_92 ) ;
if ( V_38 ) {
F_41 ( & V_87 -> V_15 , L_51 , V_49 ,
V_38 ) ;
}
return V_38 ;
}
static void V_191 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_79 ;
struct V_185 * V_186 ;
int V_50 = V_32 -> V_50 ;
T_6 V_193 , V_194 ;
struct V_195 * V_196 ;
struct V_190 * V_189 ;
struct V_187 * V_87 ;
struct V_197 * V_67 ;
int V_198 ;
if ( ! V_31 )
return;
if ( V_50 ) {
F_18 ( V_50 , V_49 , V_31 -> V_36 ) ;
return;
}
V_186 = V_31 -> V_186 ;
if ( ! V_186 )
return;
F_97 ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 ) ;
V_87 = V_31 -> V_36 -> V_87 ;
V_67 = V_31 -> V_36 -> V_67 ;
V_198 = V_67 -> V_199 -> V_200 . V_201 ;
V_189 = & V_186 -> V_189 ;
if ( V_189 -> V_202 != V_203 ||
V_189 -> V_204 != V_205 ||
F_55 ( V_189 -> V_206 ) != V_207 ||
F_55 ( V_189 -> V_208 ) != V_198 ||
F_55 ( V_189 -> V_209 ) != V_210 ) {
F_41 ( & V_87 -> V_15 ,
L_52 ) ;
F_46 ( V_189 ,
sizeof( struct V_190 ) ) ;
} else {
V_193 = F_55 ( V_189 ->
V_193 ) ;
V_194 = V_186 -> V_194 ;
V_196 = & V_186 -> V_196 ;
F_58 ( & V_31 -> V_163 ) ;
if ( ( V_193 & V_211 ) !=
( V_194 & V_211 ) )
V_196 -> V_212 ++ ;
if ( ( V_193 & V_213 ) !=
( V_194 & V_213 ) )
V_196 -> V_212 ++ ;
if ( ( V_193 & V_214 ) !=
( V_194 & V_214 ) )
V_196 -> V_215 ++ ;
if ( ( V_193 & V_216 ) &&
! ( V_194 & V_216 ) )
V_196 -> V_217 ++ ;
if ( ( V_193 & V_218 ) !=
( V_194 & V_218 ) )
V_196 -> V_219 ++ ;
if ( ( V_193 & V_220 ) !=
( V_194 & V_220 ) )
V_196 -> V_221 ++ ;
if ( ( V_193 & V_222 ) !=
( V_194 & V_222 ) )
V_196 -> V_223 ++ ;
V_186 -> V_194 = V_193 ;
F_59 ( & V_31 -> V_163 ) ;
V_186 -> V_224 = 1 ;
F_98 ( & V_186 -> V_225 ) ;
}
memset ( V_189 , 0 ,
sizeof( struct V_190 ) ) ;
F_94 ( V_31 ,
V_186 ,
V_31 -> V_36 -> V_87 ) ;
}
static int
F_99 ( struct V_6 * V_31 , unsigned long V_226 )
{
F_100 ( V_227 , V_228 ) ;
struct V_195 V_229 , V_230 ;
struct V_185 * V_186 ;
int V_231 ;
V_186 = V_31 -> V_186 ;
if ( ! V_186 )
return - V_54 ;
F_101 ( & V_31 -> V_163 ) ;
memcpy ( & V_229 , & V_186 -> V_196 , sizeof( struct V_195 ) ) ;
F_102 ( & V_31 -> V_163 ) ;
F_103 ( & V_186 -> V_225 , & V_227 ) ;
for (; ; ) {
F_101 ( & V_31 -> V_163 ) ;
memcpy ( & V_230 , & V_186 -> V_196 , sizeof( struct V_195 ) ) ;
F_102 ( & V_31 -> V_163 ) ;
F_104 ( V_232 ) ;
if ( ( ( V_226 & V_233 ) && ( V_230 . V_217 != V_229 . V_217 ) ) ||
( ( V_226 & V_234 ) && ( V_230 . V_221 != V_229 . V_221 ) ) ||
( ( V_226 & V_235 ) && ( V_230 . V_223 != V_229 . V_223 ) ) ) {
V_231 = 0 ;
break;
}
F_105 () ;
if ( F_106 ( V_228 ) ) {
V_231 = - V_236 ;
break;
}
V_229 = V_230 ;
}
F_107 ( V_237 ) ;
F_108 ( & V_186 -> V_225 , & V_227 ) ;
return V_231 ;
}
static int F_109 ( struct V_149 * V_150 ,
struct V_238 * V_196 )
{
struct V_195 V_230 ;
struct V_6 * V_31 = V_150 -> V_152 ;
struct V_185 * V_186 = V_31 -> V_186 ;
memset ( V_196 , 0 , sizeof( struct V_238 ) ) ;
if ( ! V_186 )
return - V_54 ;
F_101 ( & V_31 -> V_163 ) ;
memcpy ( & V_230 , & V_186 -> V_196 , sizeof( struct V_195 ) ) ;
F_102 ( & V_31 -> V_163 ) ;
V_196 -> V_239 = V_230 . V_239 ;
V_196 -> V_221 = V_230 . V_221 ;
V_196 -> V_217 = V_230 . V_217 ;
V_196 -> V_223 = V_230 . V_223 ;
V_196 -> V_240 = V_230 . V_240 ;
V_196 -> V_241 = V_230 . V_241 ;
V_196 -> V_215 = V_230 . V_215 ;
V_196 -> V_242 = V_230 . V_242 ;
V_196 -> V_212 = V_230 . V_212 ;
V_196 -> V_219 = V_230 . V_219 ;
V_196 -> V_243 = V_230 . V_243 ;
return 0 ;
}
static int F_110 ( struct V_149 * V_150 )
{
int V_244 ;
struct V_6 * V_31 = V_150 -> V_152 ;
struct V_185 * V_186 ;
T_6 V_193 ;
if ( ! V_31 ) {
F_20 ( 0x1 , L_53 ) ;
return - V_59 ;
}
F_101 ( & V_31 -> V_163 ) ;
V_244 = ( ( V_31 -> V_245 ) ? V_174 : 0 ) |
( ( V_31 -> V_246 ) ? V_175 : 0 ) ;
V_186 = V_31 -> V_186 ;
if ( V_186 ) {
V_193 = F_55 (
V_186 -> V_194 ) ;
if ( V_193 & V_216 )
V_244 |= V_233 ;
if ( V_193 & V_222 )
V_244 |= V_235 ;
if ( V_193 & V_220 )
V_244 |= V_234 ;
}
F_102 ( & V_31 -> V_163 ) ;
return V_244 ;
}
static int F_83 ( struct V_149 * V_150 ,
unsigned int V_247 , unsigned int V_248 )
{
int V_249 = 0 ;
unsigned long V_47 ;
int V_198 ;
struct V_6 * V_31 = V_150 -> V_152 ;
struct V_197 * V_67 ;
if ( ! V_31 ) {
F_20 ( 0x1 , L_53 ) ;
return - V_59 ;
}
if ( ( V_31 -> V_36 -> V_19 & V_20 ) != V_29 )
return - V_59 ;
V_67 = V_31 -> V_36 -> V_67 ;
V_198 = V_67 -> V_199 -> V_200 . V_201 ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
if ( V_247 & V_174 )
V_31 -> V_245 = 1 ;
if ( V_247 & V_175 )
V_31 -> V_246 = 1 ;
if ( V_248 & V_174 )
V_31 -> V_245 = 0 ;
if ( V_248 & V_175 )
V_31 -> V_246 = 0 ;
if ( V_31 -> V_246 )
V_249 |= 0x01 ;
if ( V_31 -> V_245 )
V_249 |= 0x02 ;
F_14 ( & V_31 -> V_163 , V_47 ) ;
return F_111 ( V_31 -> V_36 -> V_87 ,
F_112 ( V_31 -> V_36 -> V_87 , 0 ) , 0x22 ,
0x21 , V_249 , V_198 , NULL , 0 ,
V_250 ) ;
}
static int F_113 ( struct V_149 * V_150 ,
unsigned int V_251 , unsigned long V_226 )
{
struct V_6 * V_31 = V_150 -> V_152 ;
int V_231 = 0 ;
F_20 ( 0x8 , L_54 , V_251 , V_226 ) ;
if ( ! V_31 )
return - V_53 ;
switch ( V_251 ) {
case V_252 :
V_231 = F_99 ( V_31 , V_226 ) ;
break;
default:
V_231 = - V_253 ;
break;
}
return V_231 ;
}
static void F_88 ( struct V_6 * V_31 )
{
T_5 * V_254 ;
unsigned long V_47 ;
int V_255 ;
F_13 ( & V_31 -> V_163 , V_47 ) ;
if ( ! V_31 -> V_179 )
goto V_180;
if ( V_31 -> V_256 )
goto V_180;
if ( F_36 ( V_31 -> V_36 ) == - V_60 )
goto V_180;
V_254 = V_31 -> V_181 ;
V_31 -> V_181 = V_31 -> V_257 ;
V_31 -> V_257 = V_254 ;
V_31 -> V_258 = V_31 -> V_179 ;
V_31 -> V_179 = 0 ;
if ( V_254 && V_31 -> V_259 ) {
V_255 = V_31 -> V_259 ( V_31 ) ;
if ( V_255 >= 0 )
V_31 -> V_256 = 1 ;
}
V_180:
F_14 ( & V_31 -> V_163 , V_47 ) ;
}
static int F_114 ( struct V_6 * V_31 , T_5 type , T_6 V_40 ,
struct V_32 * V_260 ,
struct V_261 * V_262 ,
T_5 * V_263 , T_2 V_264 )
{
int V_38 ;
int V_265 ;
if ( ! V_31 || ! V_260 || ! V_262 ) {
F_16 ( L_55 , V_49 ) ;
return - V_59 ;
}
V_262 -> V_206 = 0 ;
V_262 -> V_208 = F_115 ( F_10 ( V_40 ) ) ;
V_262 -> V_209 = F_115 ( V_264 ) ;
if ( type == V_266 ) {
V_262 -> V_267 = V_268 |
V_269 |
V_270 ;
V_262 -> V_271 = V_266 ;
V_265 = F_112 ( V_31 -> V_36 -> V_87 , 0 ) ;
} else {
V_262 -> V_267 = V_272 |
V_269 |
V_270 ;
V_262 -> V_271 = V_273 ;
V_265 = F_116 ( V_31 -> V_36 -> V_87 , 0 ) ;
}
F_20 ( 0x2 , L_56 ,
type == V_266 ? L_57 : L_58 ,
V_262 -> V_267 , V_262 -> V_209 , V_40 ) ;
V_260 -> V_90 = 0 ;
F_117 ( V_260 ,
V_31 -> V_36 -> V_87 ,
V_265 ,
( T_5 * ) V_262 ,
V_263 , V_264 , V_274 , V_31 ) ;
V_38 = F_40 ( V_260 , V_92 ) ;
if ( V_38 ) {
F_8 ( & V_260 -> V_15 -> V_15 ,
L_59 , V_49 ,
V_38 , type ) ;
return V_38 ;
}
return V_264 ;
}
static int F_69 ( struct V_6 * V_31 )
{
if ( ! V_31 )
return - V_59 ;
memset ( V_31 -> V_275 [ 0 ] , 0 , V_276 ) ;
if ( V_31 -> V_34 != 1 ) {
F_8 ( & V_31 -> V_36 -> V_67 -> V_15 ,
L_60
L_61 ) ;
return 0 ;
}
return F_114 ( V_31 ,
V_266 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_35 [ 0 ] ,
& V_31 -> V_277 ,
V_31 -> V_275 [ 0 ] , V_31 -> V_154 ) ;
}
static void F_118 ( struct V_32 * V_32 )
{
struct V_41 * V_42 = V_32 -> V_79 ;
struct V_6 * V_31 ;
unsigned char * V_278 ;
int V_50 = V_32 -> V_50 ;
int V_43 ;
F_57 ( V_32 -> V_15 ) ;
if ( ! V_42 )
return;
if ( V_50 ) {
F_18 ( V_50 , V_49 , NULL ) ;
return;
}
F_20 ( 0x8 , L_62 , V_50 ) ;
V_278 = V_32 -> V_118 ;
F_20 ( 0x8 , L_63 , * V_278 ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( * V_278 & ( 1 << V_43 ) ) {
V_31 = F_11 ( V_42 ,
( 1 << V_43 ) ) ;
if ( V_31 != NULL ) {
F_20 ( 0x1 , L_64 ,
V_43 ) ;
F_58 ( & V_31 -> V_163 ) ;
if ( V_31 -> V_159 == V_162 &&
V_31 -> V_40 . V_99 > 0 ) {
if ( ! V_31 -> V_157 [ 0 ] ) {
V_31 -> V_159 = V_161 ;
F_69 ( V_31 ) ;
} else
V_31 -> V_159 = V_160 ;
} else {
F_20 ( 0x1 , L_65 ,
V_43 ) ;
}
F_59 ( & V_31 -> V_163 ) ;
}
}
}
F_119 ( V_42 , V_32 -> V_15 , V_92 ) ;
}
static int F_120 ( struct V_6 * V_31 )
{
if ( NULL == V_31 )
return - V_59 ;
return F_114 ( V_31 ,
V_273 ,
V_31 -> V_36 -> V_19 & V_20 ,
V_31 -> V_279 ,
& V_31 -> V_280 ,
V_31 -> V_257 , V_31 -> V_258 ) ;
}
static void F_121 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_79 ;
int V_50 = V_32 -> V_50 ;
if ( ! V_31 ) {
F_20 ( 0x1 , L_43 ) ;
return;
}
F_58 ( & V_31 -> V_163 ) ;
V_31 -> V_256 = 0 ;
F_59 ( & V_31 -> V_163 ) ;
if ( V_50 ) {
F_18 ( V_50 , V_49 , V_31 -> V_36 ) ;
return;
}
F_33 ( V_31 -> V_36 ) ;
F_122 ( & V_31 -> V_40 ) ;
F_88 ( V_31 ) ;
F_20 ( 0x1 , L_36 ) ;
}
static int F_123 ( struct V_6 * V_31 )
{
int V_99 = V_31 -> V_258 ;
int V_38 ;
F_38 ( V_31 -> V_279 ,
V_31 -> V_36 -> V_87 ,
F_39 ( V_31 -> V_36 -> V_87 ,
V_31 -> V_88 ->
V_89 & 0x7F ) ,
V_31 -> V_257 , V_31 -> V_258 ,
F_121 , V_31 ) ;
V_38 = F_40 ( V_31 -> V_279 , V_92 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_87 -> V_15 ,
L_66 , V_38 ) ;
return V_38 ;
}
return V_99 ;
}
static void V_274 ( struct V_32 * V_32 )
{
struct V_6 * V_31 = V_32 -> V_79 ;
struct V_261 * V_281 ;
int V_50 = V_32 -> V_50 ;
if ( ! V_31 )
return;
F_58 ( & V_31 -> V_163 ) ;
V_31 -> V_256 = 0 ;
F_59 ( & V_31 -> V_163 ) ;
if ( V_50 ) {
F_18 ( V_50 , V_49 , V_31 -> V_36 ) ;
return;
}
V_281 = (struct V_261 * ) ( V_32 -> V_282 ) ;
F_20 ( 0x8 , L_67 , V_50 ) ;
F_20 ( 0x8 , L_68 , V_32 -> V_117 ) ;
F_37 ( V_32 -> V_118 , V_32 -> V_117 ) ;
if ( V_281 -> V_267 ==
( V_268 | V_269 | V_270 ) ) {
V_31 -> V_157 [ 0 ] = 1 ;
F_58 ( & V_31 -> V_163 ) ;
F_68 ( V_31 ) ;
F_59 ( & V_31 -> V_163 ) ;
} else {
F_33 ( V_31 -> V_36 ) ;
F_122 ( & V_31 -> V_40 ) ;
F_88 ( V_31 ) ;
}
}
static int F_67 ( struct V_32 * V_32 , struct V_6 * V_31 )
{
struct V_149 * V_150 ;
int V_99 ;
if ( V_32 == NULL || V_31 == NULL ) {
F_20 ( 0x1 , L_69 ) ;
return - 2 ;
}
V_150 = F_124 ( & V_31 -> V_40 ) ;
if ( V_150 && F_125 ( V_150 ) ) {
F_126 ( V_150 ) ;
return - 1 ;
}
F_20 ( 0x1 , L_70 ) ;
V_99 = F_127 ( & V_31 -> V_40 , V_32 -> V_117 ) ;
if ( V_99 >= V_32 -> V_117 ) {
F_128 ( & V_31 -> V_40 , V_32 -> V_118 ,
V_32 -> V_117 ) ;
F_129 ( & V_31 -> V_40 ) ;
} else {
F_41 ( & V_31 -> V_36 -> V_87 -> V_15 ,
L_71 , V_32 -> V_117 ) ;
}
F_126 ( V_150 ) ;
V_31 -> V_157 [ F_7 ( V_31 , V_32 ) ] = 0 ;
return 0 ;
}
static void F_130 ( struct V_2 * V_3 )
{
char * V_283 ;
char V_284 [ 20 ] ;
switch ( V_3 -> V_19 & V_20 ) {
case V_21 :
V_283 = L_2 ;
break;
case V_22 :
V_283 = L_3 ;
break;
case V_24 :
V_283 = L_5 ;
break;
case V_25 :
V_283 = L_72 ;
break;
case V_23 :
V_283 = L_4 ;
break;
case V_26 :
V_283 = L_7 ;
break;
case V_27 :
V_283 = L_8 ;
break;
case V_28 :
V_283 = L_9 ;
break;
case V_29 :
V_283 = L_10 ;
break;
case V_30 :
V_283 = L_11 ;
break;
default:
V_283 = L_12 ;
break;
}
if ( ( V_3 -> V_19 & V_20 ) == V_30 ) {
sprintf ( V_284 , L_73 , F_1 ( V_3 ) -> V_69 -> V_12 ) ;
} else
sprintf ( V_284 , L_74 , V_285 ,
F_2 ( V_3 ) -> V_153 ) ;
F_131 ( & V_3 -> V_67 -> V_15 , L_75 ,
V_283 , V_284 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_53 ;
for ( V_43 = 0 ; V_43 < V_286 ; V_43 ++ ) {
F_38 ( V_1 -> V_287 [ V_43 ] ,
V_3 -> V_87 ,
F_60 ( V_3 -> V_87 ,
V_1 -> V_120 ->
V_89 & 0x7F ) ,
V_1 -> V_288 [ V_43 ] ,
V_123 , F_56 ,
V_1 ) ;
V_38 = F_40 ( V_1 -> V_287 [ V_43 ] ,
V_289 ) ;
if ( V_38 )
F_41 ( & V_3 -> V_87 -> V_15 ,
L_76 , V_49 ,
V_43 , V_38 ) ;
}
return V_38 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return - V_53 ;
for ( V_43 = 0 ; V_43 < V_286 ; V_43 ++ ) {
if ( V_1 -> V_287 [ V_43 ] )
F_132 ( V_1 -> V_287 [ V_43 ] ) ;
}
if ( V_1 -> V_86 )
F_132 ( V_1 -> V_86 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 , T_7 V_47 )
{
int V_43 , V_38 = 0 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return - V_53 ;
if ( ! ( V_31 -> V_36 -> V_19 & V_164 ) ) {
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_38 ( V_31 -> V_35 [ V_43 ] ,
V_31 -> V_36 -> V_87 ,
F_60 ( V_31 -> V_36 -> V_87 ,
V_31 -> V_120 ->
V_89 &
0x7F ) ,
V_31 -> V_275 [ V_43 ] ,
V_31 -> V_154 ,
V_155 ,
V_31 ) ;
V_38 = F_40 ( V_31 -> V_35 [ V_43 ] , V_47 ) ;
if ( V_38 ) {
F_41 ( & V_31 -> V_36 -> V_87 -> V_15 ,
L_66 ,
V_38 ) ;
break;
}
}
} else {
F_75 ( & V_31 -> V_42 -> V_290 ) ;
if ( ! V_31 -> V_42 -> V_291 ) {
V_38 =
F_119 ( V_31 -> V_42 ,
V_3 -> V_87 , V_47 ) ;
}
V_31 -> V_42 -> V_291 ++ ;
F_84 ( & V_31 -> V_42 -> V_290 ) ;
}
if ( V_31 -> V_186 )
F_94 ( V_31 ,
V_31 -> V_186 ,
V_31 -> V_36 -> V_87 ) ;
return V_38 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_6 * V_31 = F_2 ( V_3 ) ;
struct V_185 * V_186 ;
if ( ! V_31 )
return - V_53 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
if ( V_31 -> V_35 [ V_43 ] ) {
F_132 ( V_31 -> V_35 [ V_43 ] ) ;
V_31 -> V_157 [ V_43 ] = 0 ;
}
}
V_31 -> V_158 = 0 ;
if ( V_31 -> V_279 )
F_132 ( V_31 -> V_279 ) ;
if ( V_31 -> V_42 ) {
F_75 ( & V_31 -> V_42 -> V_290 ) ;
if ( V_31 -> V_42 -> V_291 &&
( -- V_31 -> V_42 -> V_291 == 0 ) ) {
struct V_32 * V_32 ;
V_32 = V_31 -> V_42 -> V_292 ;
if ( V_32 )
F_132 ( V_32 ) ;
}
F_84 ( & V_31 -> V_42 -> V_290 ) ;
}
V_186 = V_31 -> V_186 ;
if ( V_186 ) {
F_98 ( & V_186 -> V_225 ) ;
F_132 ( V_186 -> V_32 ) ;
}
return 0 ;
}
static void F_133 ( struct V_6 * V_31 )
{
F_134 ( V_293 , V_31 -> V_153 ) ;
}
static void F_135 ( struct V_6 * V_31 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
F_136 ( V_31 -> V_35 [ V_43 ] ) ;
F_137 ( V_31 -> V_275 [ V_43 ] ) ;
}
F_136 ( V_31 -> V_279 ) ;
F_137 ( V_31 -> V_181 ) ;
F_137 ( V_31 -> V_257 ) ;
F_138 ( & V_31 -> V_40 ) ;
}
static int F_139 ( struct V_6 * V_31 , int V_294 ,
int V_295 , int V_296 )
{
struct V_14 * V_15 ;
int V_153 ;
int V_43 ;
F_140 ( & V_31 -> V_40 ) ;
V_153 = F_15 () ;
if ( V_153 < 0 )
goto exit;
V_31 -> V_36 -> V_15 = F_141 ( & V_31 -> V_40 ,
V_293 , V_153 , & V_31 -> V_36 -> V_67 -> V_15 ,
V_31 -> V_36 , V_297 ) ;
V_15 = V_31 -> V_36 -> V_15 ;
V_31 -> V_153 = V_153 ;
V_31 -> V_168 = V_169 ;
F_142 ( & V_31 -> V_163 ) ;
V_31 -> V_34 = V_294 ;
V_31 -> V_154 = V_295 ;
for ( V_43 = 0 ; V_43 < V_31 -> V_34 ; V_43 ++ ) {
V_31 -> V_35 [ V_43 ] = F_143 ( 0 , V_172 ) ;
if ( ! V_31 -> V_35 [ V_43 ] )
goto exit;
V_31 -> V_35 [ V_43 ] -> V_118 = NULL ;
V_31 -> V_35 [ V_43 ] -> V_122 = 0 ;
V_31 -> V_275 [ V_43 ] = F_144 ( V_31 -> V_154 ,
V_172 ) ;
if ( ! V_31 -> V_275 [ V_43 ] )
goto exit;
}
V_31 -> V_279 = F_143 ( 0 , V_172 ) ;
if ( ! V_31 -> V_279 )
goto exit;
V_31 -> V_279 -> V_118 = NULL ;
V_31 -> V_279 -> V_122 = 0 ;
V_31 -> V_258 = 0 ;
V_31 -> V_179 = 0 ;
V_31 -> V_178 = V_296 ;
V_31 -> V_257 = F_144 ( V_31 -> V_178 , V_172 ) ;
if ( ! V_31 -> V_257 )
goto exit;
V_31 -> V_181 = F_144 ( V_31 -> V_178 , V_172 ) ;
if ( ! V_31 -> V_181 )
goto exit;
return 0 ;
exit:
F_133 ( V_31 ) ;
F_135 ( V_31 ) ;
return - 1 ;
}
static struct V_2 * F_145 ( struct V_197 * V_298 ,
int V_19 )
{
struct V_2 * V_3 ;
V_3 = F_144 ( sizeof( * V_3 ) , V_92 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_19 = V_19 ;
V_3 -> V_87 = F_146 ( V_298 ) ;
V_3 -> V_67 = V_298 ;
F_147 ( & V_3 -> V_173 ) ;
F_148 ( & V_3 -> V_170 ) ;
F_149 ( & V_3 -> V_299 , V_299 ) ;
F_149 ( & V_3 -> V_300 , V_300 ) ;
return V_3 ;
}
static int F_150 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_301 ; V_43 ++ ) {
if ( V_302 [ V_43 ] == V_3 ) {
V_302 [ V_43 ] = NULL ;
break;
}
}
if ( V_43 == V_301 )
return - 1 ;
return 0 ;
}
static void F_151 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return;
F_150 ( V_1 -> V_36 ) ;
if ( V_1 -> V_69 )
F_152 ( V_1 -> V_69 ) ;
for ( V_43 = 0 ; V_43 < V_286 ; V_43 ++ ) {
F_136 ( V_1 -> V_287 [ V_43 ] ) ;
F_137 ( V_1 -> V_288 [ V_43 ] ) ;
V_1 -> V_288 [ V_43 ] = NULL ;
}
F_136 ( V_1 -> V_86 ) ;
F_137 ( V_1 -> V_84 ) ;
V_1 -> V_84 = NULL ;
if ( V_1 -> V_69 )
F_153 ( V_1 -> V_69 ) ;
F_137 ( V_3 ) ;
}
static void F_154 ( struct V_68 * V_69 )
{
struct V_1 * V_1 = F_22 ( V_69 ) ;
F_20 ( 0x1 , L_77 , sizeof( * V_1 ) ) ;
V_69 -> V_303 = & V_304 ;
V_69 -> V_305 = V_306 ;
V_69 -> V_47 = V_307 | V_308 | V_309 ;
V_69 -> type = V_310 ;
V_69 -> V_311 = V_312 - 14 ;
V_69 -> V_313 = 10 ;
V_69 -> V_314 = & V_315 ;
F_142 ( & V_1 -> V_72 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_301 ; V_43 ++ ) {
if ( V_302 [ V_43 ] == NULL ) {
V_302 [ V_43 ] = V_3 ;
break;
}
}
if ( V_43 == V_301 )
return - 1 ;
return 0 ;
}
static int F_156 ( void * V_83 , bool V_316 )
{
struct V_2 * V_3 = V_83 ;
int V_317 = ! V_316 ;
int V_318 ;
F_75 ( & V_3 -> V_170 ) ;
if ( V_3 -> V_176 )
V_318 = 0 ;
else
V_318 = F_111 ( V_3 -> V_87 , F_112 ( V_3 -> V_87 , 0 ) ,
V_317 ? 0x82 : 0x81 , 0x40 , 0 , 0 , NULL , 0 ,
V_250 ) ;
F_84 ( & V_3 -> V_170 ) ;
return V_318 ;
}
static void F_157 ( struct V_2 * V_3 ,
struct V_197 * V_67 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_14 * V_15 = & V_1 -> V_69 -> V_15 ;
static T_2 V_319 ;
snprintf ( V_1 -> V_12 , sizeof( V_1 -> V_12 ) , L_78 ,
V_319 ++ ) ;
V_1 -> V_320 = F_158 ( V_1 -> V_12 ,
& F_146 ( V_67 ) -> V_15 ,
V_321 ,
& V_322 , V_3 ) ;
if ( ! V_1 -> V_320 ) {
F_8 ( V_15 , L_79 , V_49 ) ;
return;
}
if ( F_159 ( V_1 -> V_320 ) < 0 ) {
F_160 ( V_1 -> V_320 ) ;
V_1 -> V_320 = NULL ;
F_8 ( V_15 , L_80 , V_49 ) ;
return;
}
}
static struct V_2 * F_161 ( struct V_197 * V_67 ,
int V_19 )
{
int V_38 , V_43 ;
struct V_68 * V_69 ;
struct V_1 * V_1 ;
struct V_2 * V_3 ;
V_3 = F_145 ( V_67 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_69 = F_162 ( sizeof( struct V_1 ) , L_81 , V_323 ,
F_154 ) ;
if ( ! V_69 ) {
F_8 ( & V_67 -> V_15 , L_82 ) ;
goto exit;
}
V_1 = F_22 ( V_69 ) ;
V_3 -> V_4 . V_5 = V_1 ;
V_1 -> V_69 = V_69 ;
V_1 -> V_36 = V_3 ;
V_1 -> V_120 = F_163 ( V_67 , V_324 ,
V_268 ) ;
if ( ! V_1 -> V_120 ) {
F_8 ( & V_67 -> V_15 , L_83 ) ;
goto exit;
}
V_1 -> V_88 = F_163 ( V_67 , V_324 ,
V_272 ) ;
if ( ! V_1 -> V_88 ) {
F_8 ( & V_67 -> V_15 , L_84 ) ;
goto exit;
}
F_164 ( V_69 , & V_67 -> V_15 ) ;
F_165 ( V_69 , & V_325 ) ;
for ( V_43 = 0 ; V_43 < V_286 ; V_43 ++ ) {
V_1 -> V_287 [ V_43 ] = F_143 ( 0 , V_172 ) ;
if ( ! V_1 -> V_287 [ V_43 ] )
goto exit;
V_1 -> V_288 [ V_43 ] = F_144 ( V_123 ,
V_172 ) ;
if ( ! V_1 -> V_288 [ V_43 ] )
goto exit;
}
V_1 -> V_86 = F_143 ( 0 , V_172 ) ;
if ( ! V_1 -> V_86 )
goto exit;
V_1 -> V_84 = F_144 ( V_85 , V_172 ) ;
if ( ! V_1 -> V_84 )
goto exit;
F_155 ( V_3 ) ;
V_38 = F_166 ( V_69 ) ;
if ( V_38 ) {
F_8 ( & V_67 -> V_15 , L_85 ) ;
goto exit;
}
F_130 ( V_3 ) ;
F_157 ( V_3 , V_67 ) ;
return V_3 ;
exit:
F_151 ( V_3 ) ;
return NULL ;
}
static void F_167 ( struct V_6 * V_31 )
{
struct V_185 * V_186 ;
if ( ! V_31 )
return;
V_186 = V_31 -> V_186 ;
if ( V_186 ) {
F_136 ( V_186 -> V_32 ) ;
V_186 -> V_32 = NULL ;
V_31 -> V_186 = NULL ;
F_137 ( V_186 ) ;
}
}
static void F_168 ( struct V_2 * V_3 )
{
struct V_6 * V_31 = F_2 ( V_3 ) ;
if ( ! V_31 )
return;
F_135 ( V_31 ) ;
if ( V_31 -> V_42 ) {
F_75 ( & V_31 -> V_42 -> V_290 ) ;
if ( -- V_31 -> V_42 -> V_326 == 0 )
F_169 ( V_31 -> V_42 ) ;
else
F_84 ( & V_31 -> V_42 -> V_290 ) ;
}
F_167 ( V_31 ) ;
F_137 ( V_31 ) ;
F_137 ( V_3 ) ;
}
static struct V_2 * F_170 (
struct V_197 * V_67 , int V_40 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_294 ;
struct V_185 * V_186 ;
V_3 = F_145 ( V_67 , V_40 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_144 ( sizeof( * V_31 ) , V_172 ) ;
if ( ! V_31 )
goto exit;
V_31 -> V_36 = V_3 ;
V_3 -> V_4 . V_7 = V_31 ;
if ( ( V_40 & V_20 ) == V_29 ) {
V_294 = 2 ;
V_31 -> V_186 = F_144 ( sizeof( struct V_185 ) ,
V_172 ) ;
if ( V_31 -> V_186 ) {
V_186 = V_31 -> V_186 ;
V_186 -> V_32 = F_143 ( 0 , V_172 ) ;
if ( V_186 -> V_32 ) {
F_148 ( & V_186 -> V_170 ) ;
F_171 ( & V_186 -> V_225 ) ;
V_186 -> V_188 = F_163 (
V_67 ,
V_327 ,
V_268 ) ;
} else
F_167 ( V_31 ) ;
}
}
else
V_294 = 1 ;
if ( F_139 ( V_31 , V_294 , V_328 ,
V_329 ) )
goto exit;
V_31 -> V_120 = F_163 ( V_67 , V_324 ,
V_268 ) ;
if ( ! V_31 -> V_120 ) {
F_8 ( & V_67 -> V_15 , L_86 ) ;
goto V_330;
}
if ( !
( V_31 -> V_88 =
F_163 ( V_67 , V_324 , V_272 ) ) ) {
F_8 ( & V_67 -> V_15 , L_86 ) ;
goto V_330;
}
V_31 -> V_259 = F_123 ;
F_17 ( V_31 -> V_153 , V_31 ) ;
F_130 ( V_3 ) ;
return V_3 ;
V_330:
F_133 ( V_31 ) ;
F_135 ( V_31 ) ;
exit:
F_167 ( V_31 ) ;
F_137 ( V_31 ) ;
F_137 ( V_3 ) ;
return NULL ;
}
static
struct V_2 * F_172 ( struct V_197 * V_67 ,
int V_40 ,
struct V_41 * V_37 )
{
struct V_2 * V_3 ;
struct V_6 * V_31 ;
int V_19 ;
V_19 = V_164 ;
V_19 &= ~ V_20 ;
V_19 |= F_9 ( V_40 ) ;
if ( ( V_19 & V_20 ) == V_39 )
return NULL ;
V_3 = F_145 ( V_67 , V_19 ) ;
if ( ! V_3 )
return NULL ;
V_31 = F_144 ( sizeof( * V_31 ) , V_172 ) ;
if ( ! V_31 )
goto exit;
V_3 -> V_4 . V_7 = V_31 ;
V_31 -> V_36 = V_3 ;
if ( F_139
( V_31 , 1 , V_276 , V_331 ) )
goto exit;
V_31 -> V_178 -- ;
V_31 -> V_259 = F_120 ;
V_31 -> V_42 = V_37 ;
F_75 ( & V_31 -> V_42 -> V_290 ) ;
V_31 -> V_42 -> V_326 ++ ;
F_84 ( & V_31 -> V_42 -> V_290 ) ;
F_17 ( V_31 -> V_153 , V_31 ) ;
F_130 ( V_3 ) ;
return V_3 ;
exit:
if ( V_31 ) {
F_134 ( V_293 , V_31 -> V_153 ) ;
F_137 ( V_31 ) ;
}
F_137 ( V_3 ) ;
return NULL ;
}
static void F_169 ( struct V_41 * V_37 )
{
F_136 ( V_37 -> V_292 ) ;
F_137 ( V_37 -> V_332 ) ;
F_84 ( & V_37 -> V_290 ) ;
F_137 ( V_37 ) ;
}
static
struct V_41 * F_173 ( struct V_197 * V_67 )
{
struct V_41 * V_37 = F_144 ( sizeof( * V_37 ) , V_172 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_333 = F_163 ( V_67 , V_327 ,
V_268 ) ;
if ( ! V_37 -> V_333 ) {
F_8 ( & V_67 -> V_15 , L_87 ) ;
goto exit;
}
V_37 -> V_292 = F_143 ( 0 , V_172 ) ;
if ( ! V_37 -> V_292 )
goto exit;
V_37 -> V_332 =
F_144 ( F_55 ( V_37 -> V_333 -> V_121 ) ,
V_172 ) ;
if ( ! V_37 -> V_332 )
goto exit;
F_148 ( & V_37 -> V_290 ) ;
return V_37 ;
exit:
F_137 ( V_37 -> V_332 ) ;
F_136 ( V_37 -> V_292 ) ;
F_137 ( V_37 ) ;
return NULL ;
}
static int F_174 ( struct V_197 * V_67 )
{
struct V_187 * V_334 = F_146 ( V_67 ) ;
T_5 * V_335 = F_175 ( 17 , V_172 ) ;
T_2 V_198 = V_67 -> V_199 -> V_200 . V_201 ;
T_8 V_38 ;
if ( ! V_335 )
return - V_336 ;
if ( F_111 ( V_334 , F_112 ( V_334 , 0 ) ,
0x86 , 0xC0 , 0 , 0 , V_335 , 17 ,
V_250 ) != 0x11 ) {
F_137 ( V_335 ) ;
return - V_337 ;
}
switch ( V_335 [ V_198 ] ) {
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
V_38 = V_338 ;
break;
case 0xa :
V_38 = V_26 ;
break;
case 0xb :
V_38 = V_339 ;
break;
default:
V_38 = 0 ;
}
if ( V_38 )
V_38 |= V_340 ;
if ( V_335 [ 16 ] & 0x1 )
V_38 |= V_119 ;
F_137 ( V_335 ) ;
return V_38 ;
}
static int F_176 ( struct V_197 * V_67 ,
const struct V_341 * V_342 )
{
int V_37 , V_43 , V_198 , V_19 ;
unsigned char V_343 ;
struct V_2 * V_3 = NULL ;
struct V_41 * V_42 ;
struct V_2 * V_344 = NULL ;
if ( V_67 -> V_199 -> V_200 . V_345 != 0xFF ) {
F_8 ( & V_67 -> V_15 , L_88 ) ;
return - V_53 ;
}
V_198 = V_67 -> V_199 -> V_200 . V_201 ;
if ( V_342 -> V_346 )
V_19 = ( ( T_2 * ) ( V_342 -> V_346 ) ) [ V_198 ] ;
else
V_19 = F_174 ( V_67 ) ;
if ( V_67 -> V_347 > 1 )
F_177 ( F_146 ( V_67 ) , V_198 , 1 ) ;
V_67 -> V_348 = 1 ;
switch ( V_19 & V_349 ) {
case V_164 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_350 ) {
V_3 = F_161 ( V_67 ,
V_19 ) ;
if ( ! V_3 )
goto exit;
V_344 = V_3 ;
}
}
if ( F_178 ( V_67 , & V_343 ) )
goto exit;
V_42 = F_173 ( V_67 ) ;
if ( ! V_42 )
goto exit;
for ( V_43 = 1 , V_37 = 0 ; V_43 < 0x100 ; V_43 = V_43 << 1 , V_37 ++ ) {
if ( V_343 & V_43 ) {
V_3 = F_172 (
V_67 , V_43 , V_42 ) ;
if ( ! V_3 )
goto exit;
}
}
if ( V_344 )
V_3 = V_344 ;
break;
case V_340 :
if ( ( V_19 & V_20 ) == V_30 ) {
if ( ! V_350 )
V_3 =
F_161 ( V_67 , V_19 ) ;
} else {
V_3 =
F_170 ( V_67 , V_19 ) ;
}
if ( ! V_3 )
goto exit;
break;
default:
goto exit;
}
F_179 ( V_67 , V_3 ) ;
return 0 ;
exit:
F_180 ( V_67 ) ;
return - V_53 ;
}
static void F_181 ( struct V_197 * V_67 )
{
F_180 ( V_67 ) ;
F_179 ( V_67 , NULL ) ;
}
static void V_299 ( struct V_351 * V_83 )
{
struct V_2 * V_3 =
F_182 ( V_83 , struct V_2 , V_299 ) ;
F_76 ( V_3 -> V_67 ) ;
}
static void V_300 ( struct V_351 * V_83 )
{
struct V_2 * V_3 =
F_182 ( V_83 , struct V_2 , V_300 ) ;
F_82 ( V_3 -> V_67 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
if ( V_3 -> V_87 -> V_352 == V_353 ) {
if ( ! V_3 -> V_354 ) {
V_3 -> V_354 = 1 ;
F_183 ( & V_3 -> V_299 ) ;
}
}
if ( V_3 -> V_87 -> V_352 != V_355 )
return - V_60 ;
F_57 ( V_3 -> V_87 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
if ( V_3 -> V_87 -> V_352 != V_353 ) {
if ( V_3 -> V_354 ) {
V_3 -> V_354 = 0 ;
F_183 ( & V_3 -> V_300 ) ;
return - V_60 ;
}
}
V_3 -> V_354 = 0 ;
return 0 ;
}
static int F_184 ( struct V_197 * V_356 , T_9 V_357 )
{
int V_43 , V_38 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_67 == V_356 ) ) {
V_38 = F_80 ( V_45 [ V_43 ] ) ;
if ( V_38 )
goto V_180;
}
}
for ( V_43 = 0 ; V_43 < V_301 ; V_43 ++ ) {
if ( V_302 [ V_43 ] &&
( V_302 [ V_43 ] -> V_67 == V_356 ) ) {
V_38 = F_29 ( V_302 [ V_43 ] ) ;
if ( V_38 )
goto V_180;
}
}
V_180:
return 0 ;
}
static int F_185 ( struct V_197 * V_356 )
{
int V_43 , V_38 = 0 ;
struct V_1 * V_1 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] && ( V_45 [ V_43 ] -> V_67 == V_356 ) ) {
if ( F_2 ( V_45 [ V_43 ] ) -> V_40 . V_99 ) {
V_38 =
F_79 ( V_45 [ V_43 ] , V_289 ) ;
F_88 ( F_2 ( V_45 [ V_43 ] ) ) ;
if ( V_38 )
goto V_180;
}
}
}
for ( V_43 = 0 ; V_43 < V_301 ; V_43 ++ ) {
if ( V_302 [ V_43 ] &&
( V_302 [ V_43 ] -> V_67 == V_356 ) ) {
V_1 = F_1 ( V_302 [ V_43 ] ) ;
if ( V_1 -> V_47 & V_358 ) {
if ( V_1 -> V_71 ) {
F_131 ( & V_356 -> V_15 ,
L_89
L_90 ) ;
F_35 ( V_1 -> V_71 ,
V_1 -> V_69 ) ;
V_1 -> V_71 = NULL ;
}
V_38 = F_24 ( V_302 [ V_43 ] ) ;
if ( V_38 )
goto V_180;
}
}
}
V_180:
return V_38 ;
}
static void V_183 ( struct V_359 * V_173 )
{
struct V_2 * V_3 = F_182 ( V_173 , struct V_2 , V_173 ) ;
F_168 ( V_3 ) ;
}
static void F_180 ( struct V_197 * V_67 )
{
struct V_6 * V_31 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_45 [ V_43 ] &&
( V_45 [ V_43 ] -> V_67 == V_67 ) ) {
V_31 = F_2 ( V_45 [ V_43 ] ) ;
F_186 ( & V_31 -> V_40 , false ) ;
F_75 ( & V_31 -> V_36 -> V_170 ) ;
V_31 -> V_36 -> V_176 = 1 ;
F_84 ( & V_31 -> V_36 -> V_170 ) ;
F_187 ( & V_45 [ V_43 ] -> V_300 ) ;
F_187 ( & V_45 [ V_43 ] -> V_299 ) ;
F_133 ( V_31 ) ;
F_91 ( & V_45 [ V_43 ] -> V_173 , V_183 ) ;
F_17 ( V_43 , NULL ) ;
}
}
for ( V_43 = 0 ; V_43 < V_301 ; V_43 ++ ) {
if ( V_302 [ V_43 ] &&
( V_302 [ V_43 ] -> V_67 == V_67 ) ) {
struct V_320 * V_360 = F_1 ( V_302 [ V_43 ] ) -> V_320 ;
F_27 ( F_1 ( V_302 [ V_43 ] ) -> V_69 ) ;
F_29 ( V_302 [ V_43 ] ) ;
F_187 ( & V_302 [ V_43 ] -> V_300 ) ;
F_187 ( & V_302 [ V_43 ] -> V_299 ) ;
if ( V_360 ) {
F_188 ( V_360 ) ;
F_160 ( V_360 ) ;
}
F_151 ( V_302 [ V_43 ] ) ;
}
}
}
static struct V_361 * F_163 ( struct V_197 * V_298 ,
int type , int V_362 )
{
int V_43 ;
struct V_363 * V_356 = V_298 -> V_199 ;
struct V_361 * V_188 ;
for ( V_43 = 0 ; V_43 < V_356 -> V_200 . V_364 ; V_43 ++ ) {
V_188 = & V_356 -> V_365 [ V_43 ] . V_200 ;
if ( ( ( V_188 -> V_89 & V_366 ) == V_362 ) &&
( F_189 ( V_188 ) == type ) )
return V_188 ;
}
return NULL ;
}
static int F_178 ( struct V_197 * V_298 , unsigned char * V_367 )
{
int V_43 ;
struct V_363 * V_356 = V_298 -> V_199 ;
if ( V_356 -> V_368 == 3 ) {
* V_367 = V_356 -> V_369 [ 2 ] ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_356 -> V_200 . V_364 ; V_43 ++ ) {
if ( V_356 -> V_365 [ V_43 ] . V_368 == 3 ) {
* V_367 = V_356 -> V_365 [ V_43 ] . V_369 [ 2 ] ;
return 0 ;
}
}
return - 1 ;
}
static int F_119 ( struct V_41 * V_42 ,
struct V_187 * V_87 , T_7 V_370 )
{
int V_38 ;
F_95 ( V_42 -> V_292 , V_87 ,
F_96 ( V_87 ,
V_42 -> V_333 -> V_89 & 0x7F ) ,
V_42 -> V_332 ,
1 ,
F_118 , V_42 ,
V_42 -> V_333 -> V_192 ) ;
V_38 = F_40 ( V_42 -> V_292 , V_370 ) ;
if ( V_38 )
F_41 ( & V_87 -> V_15 , L_91 , V_49 ,
V_38 ) ;
return V_38 ;
}
static int T_10 F_190 ( void )
{
int V_43 ;
int V_38 ;
F_191 ( L_13 , V_371 ) ;
F_142 ( & V_48 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
V_45 [ V_43 ] = NULL ;
V_293 = F_192 ( V_44 ) ;
if ( ! V_293 )
return - V_336 ;
V_293 -> V_372 = V_372 ;
V_293 -> V_12 = V_285 ;
if ( V_373 )
V_293 -> V_374 = V_373 ;
V_293 -> V_375 = 0 ;
V_293 -> type = V_376 ;
V_293 -> V_377 = V_378 ;
V_293 -> V_47 = V_379 | V_380 ;
V_293 -> V_381 = V_382 ;
F_61 ( & V_293 -> V_381 ) ;
F_193 ( V_293 , & V_383 ) ;
V_38 = F_194 ( V_293 ) ;
if ( V_38 ) {
F_16 ( L_92 ,
V_49 , V_38 ) ;
goto V_384;
}
V_38 = F_195 ( & V_385 ) ;
if ( V_38 ) {
F_16 ( L_93 , V_38 ) ;
goto V_386;
}
return 0 ;
V_386:
F_196 ( V_293 ) ;
V_384:
F_197 ( V_293 ) ;
return V_38 ;
}
static void T_11 F_198 ( void )
{
F_191 ( L_94 ) ;
F_196 ( V_293 ) ;
F_199 ( & V_385 ) ;
F_197 ( V_293 ) ;
}
