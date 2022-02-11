static inline T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_3 ( unsigned int V_1 , T_1 V_4 )
{
F_4 ( V_2 . V_3 + V_1 , V_4 ) ;
}
static inline void F_5 ( unsigned int V_1 , T_1 V_5 )
{
T_1 V_6 = F_1 ( V_1 ) | V_5 ;
F_3 ( V_1 , V_6 ) ;
}
static inline void F_6 ( unsigned int V_1 , T_1 V_7 , T_1 V_5 )
{
T_1 V_6 = ( F_1 ( V_1 ) & V_7 ) | V_5 ;
F_3 ( V_1 , V_6 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
int V_10 , int V_11 )
{
int V_12 , V_13 , V_14 , V_15 = 0 ;
T_2 V_16 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_14 = V_10 ;
do {
V_16 = F_1 ( F_8 ( V_12 ) ) &
V_17 ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_13 = 1 ;
break;
default:
V_13 = 0 ;
F_9 ( 10 ) ;
}
} while ( ! V_13 && -- V_14 );
if ( ! V_14 && V_11 ) {
F_10 ( L_1 ,
V_22 , V_12 ) ;
F_5 ( V_23 , V_24 ) ;
V_15 = 1 ;
}
}
return V_15 ;
}
static void F_11 ( struct V_8 * V_9 )
{
int V_15 ;
V_15 = F_7 ( V_9 , 700 , 1 ) ;
F_5 ( V_25 , 0 ) ;
F_5 ( V_26 , 0 ) ;
if ( V_15 )
F_6 ( V_23 , ~ V_24 , 0 ) ;
F_12 () ;
}
static void F_13 ( struct V_8 * V_9 )
{
F_5 ( F_8 ( 0 ) , V_27 ) ;
F_12 () ;
}
static T_3 F_14 ( struct V_8 * V_9 , void * V_28 , int V_29 )
{
return V_9 -> V_30 [ V_29 ] +
( V_28 - V_9 -> V_31 [ V_29 ] ) ;
}
static void F_15 ( struct V_8 * V_9 ,
enum V_32 V_29 , T_4 V_33 ,
int V_34 )
{
if ( ! V_34 )
V_9 -> V_35 [ V_29 ] =
V_9 -> V_36 [ V_29 ] ;
V_9 -> V_36 [ V_29 ] += V_33 ;
if ( ( V_9 -> V_31 [ V_29 ] + ( V_9 -> V_37 / 2 ) ) <=
V_9 -> V_36 [ V_29 ] ) {
V_9 -> V_36 [ V_29 ] = V_9 -> V_31 [ V_29 ] ;
}
}
static int F_16 ( struct V_8 * V_9 ,
enum V_38 V_39 )
{
T_2 V_40 ;
int V_41 , V_12 , V_34 ;
enum V_32 V_29 ;
T_2 V_42 = 0 ;
void * V_43 ;
unsigned long V_44 ;
int V_45 = 0 ;
switch ( V_39 ) {
case V_46 :
V_45 = 1 ;
case V_47 :
V_42 = V_48 ;
break;
case V_49 :
V_45 = 1 ;
case V_50 :
V_42 = V_51 ;
break;
}
F_7 ( V_9 , 700 , 0 ) ;
V_41 = 4 ;
F_17 ( & V_9 -> V_52 , V_44 ) ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_43 = V_9 -> V_36 [ 0 ] ;
for ( V_34 = 0 ; V_34 < V_41 ; V_34 ++ ) {
V_12 = V_34 * 2 + V_29 ;
if ( V_45 )
V_40 = V_9 -> V_53 ;
else
V_40 =
F_14 ( V_9 ,
V_9 -> V_36 [ V_29 ] ,
V_29 ) ;
F_3 ( F_18 ( V_12 ) ,
( V_54 |
V_40 ) ) ;
if ( V_29 == 0 )
F_3 ( F_19 ( V_12 ) ,
( V_55 |
F_20 ( 0 ) ) ) ;
else
F_3 ( F_19 ( V_12 ) ,
( V_55 |
F_21 ( 0 ) ) ) ;
F_3 ( F_22 ( V_12 ) , 0 ) ;
if ( ! V_45 )
F_15 ( V_9 , V_29 ,
V_56 ,
V_34 ) ;
if ( V_12 == 0 )
F_3 ( F_8 ( V_12 ) ,
V_42 ) ;
else
F_3 ( F_8 ( V_12 ) ,
F_23 ( V_12
- 1 ) |
V_27 ) ;
}
}
F_12 () ;
F_24 ( & V_9 -> V_52 , V_44 ) ;
return 0 ;
}
static T_5 F_25 ( int V_57 , void * V_58 )
{
T_2 V_59 ;
int V_60 = 0 ;
struct V_8 * V_9 = V_58 ;
if ( ! V_9 -> V_61 ) {
F_5 ( V_26 , 0 ) ;
F_5 ( V_25 , 0 ) ;
return V_62 ;
}
V_59 = F_1 ( V_26 ) ;
if ( V_59 & F_26 ( 0 ) ) {
F_3 ( V_26 , F_26 ( 0 ) ) ;
if ( V_59 & F_27 ( 0 ) ) {
F_3 ( V_26 , V_59 ) ;
V_60 = 1 ;
}
if ( V_9 -> V_45 ) {
F_16 ( V_9 ,
( V_60 ) ?
V_46 :
V_49 ) ;
F_13 ( V_9 ) ;
V_9 -> V_45 -- ;
} else {
F_16 ( V_9 ,
( V_60 ) ?
V_47 :
V_50 ) ;
F_13 ( V_9 ) ;
F_28 ( V_9 -> V_63 ) ;
}
} else if ( V_59 & F_27 ( 0 ) ) {
F_3 ( V_26 , F_27 ( 0 ) ) ;
F_16 ( V_9 ,
V_46 ) ;
F_13 ( V_9 ) ;
F_16 ( V_9 ,
V_46 ) ;
F_13 ( V_9 ) ;
}
return V_62 ;
}
static int F_29 ( int V_64 )
{
return F_30 ( V_64 ) ;
}
static int F_31 ( struct V_8 * V_9 )
{
int V_65 , V_14 , V_66 ;
F_32 ( L_2 , V_22 ) ;
V_65 = F_33 ( V_9 -> V_67 . V_68 ,
V_9 -> V_67 . V_69 ,
V_9 -> V_67 . V_70 ,
V_9 -> V_67 . V_71 ,
V_9 -> V_67 . V_72 ) ;
F_6 ( V_73 ,
~ ( F_34 ( 0 ) |
F_34 ( 1 ) |
F_34 ( 2 ) |
F_34 ( 3 ) ) ,
0 ) ;
F_12 () ;
V_14 = 1000 ;
while ( ( F_1 ( V_73 ) &
( F_35 ( 0 ) |
F_35 ( 1 ) |
F_35 ( 2 ) |
F_35 ( 3 ) ) ) &&
-- V_14 ) {
F_9 ( 1 ) ;
}
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
F_5 ( F_36 ( V_66 ) ,
V_74 ) ;
F_9 ( 10 ) ;
}
F_12 () ;
F_5 ( V_73 , F_34 ( 0 ) ) ;
F_6 ( F_36 ( 0 ) ,
~ V_75 ,
V_76 ) ;
F_6 ( F_37 ( 0 ) ,
~ V_77 ,
V_78 ) ;
F_12 () ;
F_32 ( L_3 , V_22 ) ;
return V_65 ;
}
static int F_38 ( struct V_79 * V_63 )
{
struct V_8 * V_9 = F_39 ( V_63 ) ;
struct V_80 V_67 ;
int V_65 ;
V_67 = V_9 -> V_67 ;
F_32 ( L_4 , V_22 ,
V_63 -> V_81 -> V_82 ,
F_40 ( V_63 -> V_81 -> V_83 ) ) ;
F_32 ( L_5 , V_22 ,
V_9 -> V_67 . V_69 , V_9 -> V_67 . V_70 ) ;
switch ( V_63 -> V_81 -> V_82 ) {
case 44100 :
V_67 . V_69 = V_84 ;
break;
case 48000 :
V_67 . V_69 = V_85 ;
break;
case 88200 :
V_67 . V_69 = V_86 ;
break;
case 96000 :
V_67 . V_69 = V_87 ;
break;
default:
F_10 ( L_6 , V_22 ,
V_63 -> V_81 -> V_82 ) ;
return 1 ;
}
switch ( F_40 ( V_63 -> V_81 -> V_83 ) ) {
case 16 :
V_67 . V_70 = V_88 ;
break;
case 24 :
V_67 . V_70 = V_89 ;
break;
default:
F_10 ( L_7 , V_22 ,
F_40 ( V_63 -> V_81 -> V_83 ) ) ;
return 1 ;
}
memcpy ( V_67 . V_90 , V_91 , 8 ) ;
if ( memcmp ( & V_9 -> V_67 , & V_67 , sizeof( V_67 ) ) ) {
F_32 ( L_8 , V_22 ,
V_9 -> V_67 . V_69 , V_9 -> V_67 . V_70 ) ;
V_9 -> V_67 = V_67 ;
F_31 ( V_9 ) ;
V_65 = 0 ;
} else
V_65 = 1 ;
if ( V_67 . V_90 [ 0 ] & 0x02 )
F_41 ( 1 ) ;
else
F_41 ( 0 ) ;
return V_65 ;
}
static int F_42 ( struct V_79 * V_63 )
{
struct V_92 * V_81 = V_63 -> V_81 ;
struct V_8 * V_9 = F_39 ( V_63 ) ;
int V_93 ;
V_93 = V_63 -> V_94 -> V_95 ;
V_9 -> V_63 = V_63 ;
V_81 -> V_96 = V_97 ;
V_9 -> V_98 = V_99 ;
F_29 ( 0 ) ;
F_43 ( V_81 , 0 , V_100 ,
V_101 * 4 * 2 ) ;
return 0 ;
}
static int F_44 ( struct V_79 * V_63 )
{
F_29 ( 1 ) ;
return 0 ;
}
static int F_45 ( struct V_79 * V_63 ,
struct V_102 * V_103 )
{
T_4 V_104 ;
V_104 = F_46 ( V_103 ) ;
F_47 ( V_63 , V_104 ) ;
return 0 ;
}
static int F_48 ( struct V_79 * V_63 )
{
int V_65 ;
V_65 = F_49 ( V_63 ) ;
return V_65 ;
}
static int F_50 ( struct V_79 * V_63 ,
unsigned int V_105 )
{
int V_65 ;
int V_82 ;
V_82 = V_63 -> V_81 -> V_82 ;
V_65 = F_51 ( V_63 -> V_81 -> V_83 ,
V_82 * V_105 / 1000 )
* V_63 -> V_81 -> V_106 ;
F_32 ( L_9 ,
V_22 ,
V_105 ,
V_82 ,
F_51 ( V_63 -> V_81 -> V_83 , V_82 ) ,
V_82 * V_105 / 1000 ,
V_65 ) ;
return V_65 ;
}
static int F_52 ( struct V_79 * V_63 )
{
struct V_92 * V_81 = V_63 -> V_81 ;
struct V_8 * V_9 = F_39 ( V_63 ) ;
unsigned long V_44 ;
if ( ! F_38 ( V_63 ) ) {
F_3 ( V_107 ,
F_26 ( 0 ) |
F_27 ( 0 ) ) ;
V_9 -> V_45 = F_50 ( V_63 ,
V_9 -> V_98 ) /
( V_101 * 4 ) ;
}
F_17 ( & V_9 -> V_52 , V_44 ) ;
{
V_9 -> V_37 = V_81 -> V_108 ;
V_9 -> V_35 [ V_109 ] =
V_9 -> V_36 [ V_109 ] =
V_9 -> V_31 [ V_109 ] =
V_81 -> V_110 ;
V_9 -> V_30 [ V_109 ] = V_81 -> V_40 ;
V_9 -> V_35 [ V_111 ] =
V_9 -> V_36 [ V_111 ] =
V_9 -> V_31 [ V_111 ] =
V_81 -> V_110 + ( V_81 -> V_108 / 2 ) ;
V_9 -> V_30 [ V_111 ] =
V_81 -> V_40 + ( V_81 -> V_108 / 2 ) ;
F_32 ( L_10 , V_22 ,
V_9 -> V_31 [ V_109 ] ,
V_9 -> V_30 [ V_109 ] ) ;
}
F_24 ( & V_9 -> V_52 , V_44 ) ;
F_53 () ;
return 0 ;
}
static int F_54 ( struct V_79 * V_63 ,
int V_112 )
{
struct V_8 * V_9 = F_39 ( V_63 ) ;
int V_65 = 0 ;
switch ( V_112 ) {
case V_113 :
F_5 ( V_26 , 0 ) ;
F_55 ( & V_9 -> V_52 ) ;
{
V_9 -> V_61 = 1 ;
}
F_56 ( & V_9 -> V_52 ) ;
F_16 ( V_9 ,
V_46 ) ;
F_13 ( V_9 ) ;
while ( F_1 ( F_8 ( 7 ) ) &
V_17 ) {
F_9 ( 1 ) ;
}
F_16 ( V_9 , V_49 ) ;
F_13 ( V_9 ) ;
break;
case V_114 :
F_55 ( & V_9 -> V_52 ) ;
{
V_9 -> V_61 = 0 ;
}
F_56 ( & V_9 -> V_52 ) ;
F_11 ( V_9 ) ;
break;
default:
break;
}
return V_65 ;
}
static T_6 F_57 (
struct V_79 * V_63 )
{
struct V_8 * V_9 = F_39 ( V_63 ) ;
T_4 V_115 ;
T_6 V_65 ;
F_55 ( & V_9 -> V_52 ) ;
{
V_115 = ( T_4 ) ( V_9 -> V_35 [ V_109 ] -
V_9 -> V_31 [ V_109 ] ) ;
}
F_56 ( & V_9 -> V_52 ) ;
V_65 = F_58 ( V_63 -> V_81 , V_115 * 2 ) ;
return V_65 ;
}
static int F_59 ( struct V_116 * V_117 ,
struct V_118 * V_119 )
{
V_119 -> type = V_120 ;
V_119 -> V_10 = 1 ;
return 0 ;
}
static int F_60 ( struct V_116 * V_117 ,
struct V_121 * V_122 )
{
memset ( V_122 -> V_123 . V_124 . V_16 , 0xff , 8 ) ;
return 0 ;
}
static int F_61 ( struct V_116 * V_117 ,
struct V_121 * V_122 )
{
return 0 ;
}
static int F_62 ( struct V_116 * V_117 ,
struct V_121 * V_122 )
{
memcpy ( V_122 -> V_123 . V_124 . V_16 , V_91 , 8 ) ;
return 0 ;
}
static int F_63 ( struct V_116 * V_117 ,
struct V_121 * V_122 )
{
if ( memcmp ( V_91 , V_122 -> V_123 . V_124 . V_16 , 8 ) ) {
memcpy ( V_91 , V_122 -> V_123 . V_124 . V_16 , 8 ) ;
return 1 ;
}
return 0 ;
}
static int T_7 F_64 ( void )
{
V_2 . V_3 =
F_65 ( V_2 . V_125 -> V_126 -> V_127 ,
V_2 . V_125 -> V_126 -> V_128 ) ;
if ( ! V_2 . V_3 ) {
F_10 ( L_11 ,
V_22 , V_2 . V_125 -> V_126 -> V_129 ,
V_2 . V_125 -> V_126 -> V_128 ) ;
return - V_130 ;
}
return 0 ;
}
static void F_66 ( void )
{
F_67 ( V_2 . V_3 ) ;
V_2 . V_3 = NULL ;
}
static int T_7 F_68 ( void )
{
int V_65 ;
T_8 V_129 , V_131 ;
T_8 T_9 * V_132 ;
V_65 = F_69 ( 1 , & V_129 , & V_131 ) ;
if ( V_65 ) {
F_10 ( L_12 , V_22 ,
V_65 ) ;
return - V_130 ;
}
V_132 = F_65 ( V_129 , V_131 ) ;
if ( ! V_132 ) {
F_10 ( L_13 , V_22 ) ;
return - V_130 ;
}
V_2 . V_133 = F_70 ( V_132 ) ;
F_67 ( V_132 ) ;
V_65 = F_71 ( 1 ) ;
if ( V_65 )
F_10 ( L_14 , V_22 ) ;
V_65 = F_72 ( V_134 ,
V_2 . V_133 ,
& V_2 . V_135 ) ;
if ( V_65 ) {
F_10 ( L_15 , V_22 , V_65 ) ;
return V_65 ;
}
V_65 = F_73 ( V_2 . V_135 , F_25 , 0 ,
V_136 , & V_2 ) ;
if ( V_65 ) {
F_10 ( L_16 , V_22 , V_65 ) ;
goto V_137;
}
return 0 ;
V_137:
F_74 ( V_2 . V_135 ) ;
return V_65 ;
}
static void F_75 ( void )
{
F_76 ( V_2 . V_135 , & V_2 ) ;
F_74 ( V_2 . V_135 ) ;
}
static void T_7 F_77 ( T_10 V_138 )
{
T_10 V_4 ;
int V_65 ;
V_4 = ( V_138 & ( 0x0fUL << 32 ) ) >> ( 32 - 20 ) |
( 0x03UL << 24 ) |
( 0x0fUL << 12 ) |
( V_139 ) ;
V_65 = F_78 ( 0x100 , 0x007 , V_4 ) ;
if ( V_65 )
F_10 ( L_17 , V_22 ,
V_65 ) ;
}
static void T_7 F_79 ( struct V_8 * V_9 )
{
F_3 ( V_140 , 0 ) ;
F_6 ( V_141 ,
V_142 ,
V_143 ) ;
F_6 ( V_73 ,
~ ( V_144 |
V_145 ) ,
0 ) ;
F_5 ( V_73 ,
V_146 ) ;
}
static int T_7 F_80 ( struct V_8 * V_9 )
{
int V_65 ;
F_32 ( L_2 , V_22 ) ;
V_9 -> V_67 . V_68 = V_147 ;
V_9 -> V_67 . V_69 = V_85 ;
V_9 -> V_67 . V_70 = V_88 ;
V_9 -> V_67 . V_71 = V_148 ;
V_9 -> V_67 . V_72 = V_149 ;
memcpy ( V_9 -> V_67 . V_90 , V_91 , 8 ) ;
V_65 = F_31 ( V_9 ) ;
F_79 ( V_9 ) ;
F_16 ( V_9 , V_46 ) ;
F_13 ( V_9 ) ;
F_32 ( L_3 , V_22 ) ;
return V_65 ;
}
static int T_7 F_81 ( struct V_150 * V_151 )
{
int V_66 , V_65 ;
T_8 V_129 , V_131 ;
F_82 ( ! F_83 ( V_152 ) ) ;
F_82 ( V_151 -> V_153 != V_154 ) ;
V_2 . V_125 = V_151 ;
V_65 = F_84 ( V_151 ) ;
if ( V_65 )
return - V_130 ;
V_65 = F_69 ( 2 , & V_129 , & V_131 ) ;
if ( V_65 ) {
F_10 ( L_18 , V_22 , V_65 ) ;
goto V_155;
}
F_85 ( V_151 , V_151 -> V_126 , V_129 , V_131 ,
V_156 ) ;
V_65 = F_64 () ;
if ( V_65 )
goto V_157;
F_86 ( V_151 , V_151 -> V_158 ,
V_156 ,
0 ,
NULL ,
F_87 ( V_159 , V_160 ) ) ;
V_151 -> V_158 -> V_161 = V_139 ;
V_65 = F_88 ( V_151 -> V_158 ) ;
if ( V_65 ) {
F_10 ( L_19 , V_22 ) ;
goto V_162;
}
F_77 ( V_151 -> V_158 -> V_127 ) ;
V_2 . V_98 = V_99 ;
if ( F_68 () ) {
V_65 = - V_130 ;
goto V_163;
}
V_65 = F_89 ( V_164 , V_165 , V_166 , 0 , & V_2 . V_9 ) ;
if ( V_65 < 0 )
goto V_167;
strcpy ( V_2 . V_9 -> V_168 , L_20 ) ;
strcpy ( V_2 . V_9 -> V_169 , L_20 ) ;
strcpy ( V_2 . V_9 -> V_170 , L_21 ) ;
for ( V_66 = 0 ; V_66 < F_90 ( V_171 ) ; V_66 ++ ) {
V_65 = F_91 ( V_2 . V_9 ,
F_92 ( & V_171 [ V_66 ] , & V_2 ) ) ;
if ( V_65 < 0 )
goto V_172;
}
V_65 = F_93 ( V_2 . V_9 ,
L_22 ,
0 ,
1 ,
0 ,
& ( V_2 . V_94 ) ) ;
if ( V_65 )
goto V_172;
V_2 . V_94 -> V_173 = & V_2 ;
strcpy ( V_2 . V_94 -> V_174 , L_22 ) ;
F_94 ( V_2 . V_94 , V_175 ,
& V_176 ) ;
V_2 . V_94 -> V_177 = V_178 ;
V_65 = F_95 ( V_2 . V_94 ,
V_179 ,
& V_151 -> V_180 ,
V_181 ,
V_181 ) ;
if ( V_65 < 0 ) {
F_10 ( L_23 , V_22 ) ;
goto V_172;
}
V_2 . V_182 =
F_96 ( & V_2 . V_125 -> V_180 ,
V_160 ,
& V_2 . V_53 ,
V_183 ) ;
if ( ! V_2 . V_182 ) {
F_10 ( L_24 , V_22 ) ;
V_65 = - V_184 ;
goto V_185;
}
F_32 ( L_25 , V_22 ,
V_2 . V_182 ,
V_2 . V_53 ) ;
F_80 ( & V_2 ) ;
F_97 ( V_2 . V_9 , & V_151 -> V_180 ) ;
V_65 = F_98 ( V_2 . V_9 ) ;
if ( V_65 < 0 )
goto V_186;
F_10 ( L_26 ,
V_2 . V_9 -> V_170 , V_2 . V_98 ) ;
return 0 ;
V_186:
F_99 ( & V_2 . V_125 -> V_180 ,
V_160 ,
V_2 . V_182 ,
V_2 . V_53 ) ;
V_185:
F_100 ( V_2 . V_94 ) ;
V_172:
F_101 ( V_2 . V_9 ) ;
V_167:
F_75 () ;
V_163:
F_102 ( V_151 -> V_158 ) ;
V_162:
F_66 () ;
V_157:
F_71 ( 2 ) ;
V_155:
F_103 ( V_151 ) ;
return V_65 ;
}
static int F_104 ( struct V_150 * V_151 )
{
int V_65 ;
F_10 ( L_27 , V_22 , V_151 -> V_153 ) ;
if ( V_151 -> V_153 != V_154 )
return - V_130 ;
V_65 = F_101 ( V_2 . V_9 ) ;
if ( V_65 )
F_10 ( L_28 , V_22 , V_65 ) ;
F_99 ( & V_151 -> V_180 ,
V_160 ,
V_2 . V_182 ,
V_2 . V_53 ) ;
F_102 ( V_151 -> V_158 ) ;
F_75 () ;
F_66 () ;
F_71 ( 2 ) ;
F_103 ( V_151 ) ;
F_10 ( L_29 , V_22 , V_151 -> V_153 ) ;
return 0 ;
}
static int T_11 F_105 ( void )
{
int V_65 ;
if ( ! F_83 ( V_152 ) )
return - V_130 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
F_106 ( & V_2 . V_52 ) ;
V_65 = F_107 ( & V_187 ) ;
return V_65 ;
}
static void T_12 F_108 ( void )
{
F_109 ( & V_187 ) ;
}
