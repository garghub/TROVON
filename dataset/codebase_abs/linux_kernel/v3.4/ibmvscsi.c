static int F_1 ( struct V_1 * V_2 ,
int V_3 , struct V_4 * V_5 )
{
int V_6 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = F_2 ( V_2 -> V_3 , sizeof( * V_2 -> V_8 ) , V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
V_2 -> V_11 =
F_3 ( V_5 -> V_12 ,
V_2 -> V_3 * sizeof( * V_2 -> V_11 ) ,
& V_2 -> V_13 , 0 ) ;
if ( ! V_2 -> V_11 ) {
F_4 ( V_2 -> V_8 ) ;
return - V_10 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_3 ; ++ V_6 ) {
struct V_14 * V_15 = & V_2 -> V_8 [ V_6 ] ;
memset ( & V_15 -> V_16 , 0x00 , sizeof( V_15 -> V_16 ) ) ;
F_5 ( & V_15 -> free , 1 ) ;
V_15 -> V_16 . V_17 = 0x80 ;
V_15 -> V_16 . V_18 = sizeof( * V_15 -> V_19 ) ;
V_15 -> V_16 . V_20 = V_2 -> V_13 +
sizeof( * V_15 -> V_19 ) * V_6 ;
V_15 -> V_19 = V_2 -> V_11 + V_6 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_21 = NULL ;
V_15 -> V_22 = 0 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_6 , V_23 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_3 ; ++ V_6 ) {
if ( F_7 ( & V_2 -> V_8 [ V_6 ] . free ) != 1 )
++ V_23 ;
if ( V_2 -> V_8 [ V_6 ] . V_21 ) {
F_8 ( V_5 -> V_12 ,
V_24 * sizeof( struct V_25 ) ,
V_2 -> V_8 [ V_6 ] . V_21 ,
V_2 -> V_8 [ V_6 ] . V_22 ) ;
}
}
if ( V_23 )
F_9 ( V_5 -> V_12 , L_1
L_2 , V_23 ) ;
F_4 ( V_2 -> V_8 ) ;
F_8 ( V_5 -> V_12 ,
V_2 -> V_3 * sizeof( * V_2 -> V_11 ) ,
V_2 -> V_11 , V_2 -> V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_26 = V_15 - V_2 -> V_8 ;
if ( V_26 < 0 || V_26 >= V_2 -> V_3 )
return 0 ;
if ( V_15 != V_2 -> V_8 + V_26 )
return 0 ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
if ( ! F_10 ( V_2 , V_15 ) ) {
F_12 ( V_15 -> V_5 -> V_12 , L_3
L_4 , V_15 , V_2 -> V_8 ) ;
return;
}
if ( F_13 ( & V_15 -> free ) != 1 ) {
F_12 ( V_15 -> V_5 -> V_12 , L_5
L_6 , V_15 ) ;
return;
}
}
static struct V_14 * F_14 ( struct V_1 * V_2 )
{
int V_6 ;
int V_27 = V_2 -> V_3 ;
int V_28 = V_2 -> V_7 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
V_28 = ( V_28 + 1 ) % V_27 ;
if ( ! F_15 ( & V_2 -> V_8 [ V_28 ] . free ) ) {
V_2 -> V_7 = V_28 ;
return & V_2 -> V_8 [ V_28 ] ;
}
}
F_16 ( V_29 L_7 ) ;
return NULL ;
}
static void F_17 ( struct V_14 * V_30 ,
void (* F_18) ( struct V_14 * ) ,
T_1 V_31 ,
int V_32 )
{
V_30 -> V_33 = NULL ;
V_30 -> V_34 = NULL ;
V_30 -> V_35 = NULL ;
V_30 -> V_16 . V_31 = V_31 ;
V_30 -> V_16 . V_32 = V_32 ;
V_30 -> F_18 = F_18 ;
}
static void F_19 ( struct V_36 * V_37 ,
struct V_38 * V_38 ,
int V_39 )
{
T_1 V_40 ;
if ( V_39 == 0 )
return;
if ( V_39 == 1 )
V_40 = V_41 ;
else {
V_40 = V_42 ;
V_39 = F_20 ( V_39 , V_43 ) ;
if ( V_37 -> V_44 == V_45 )
V_38 -> V_46 = V_39 ;
else
V_38 -> V_47 = V_39 ;
}
if ( V_37 -> V_44 == V_45 )
V_38 -> V_48 = V_40 << 4 ;
else
V_38 -> V_48 = V_40 ;
}
static void F_21 ( struct V_38 * V_37 ,
struct V_14 * V_30 ,
struct V_49 * V_12 )
{
T_1 V_50 , V_51 ;
V_50 = V_37 -> V_48 >> 4 ;
V_51 = V_37 -> V_48 & ( ( 1U << 4 ) - 1 ) ;
if ( V_50 == V_52 && V_51 == V_52 )
return;
if ( V_30 -> V_33 )
F_22 ( V_30 -> V_33 ) ;
}
static int F_23 ( struct V_36 * V_37 , int V_53 ,
struct V_25 * V_54 )
{
int V_6 ;
struct V_55 * V_56 ;
T_2 V_57 = 0 ;
F_24 (cmd, sg, nseg, i) {
struct V_25 * V_58 = V_54 + V_6 ;
V_58 -> V_59 = F_25 ( V_56 ) ;
V_58 -> V_60 = F_26 ( V_56 ) ;
V_58 -> V_61 = 0 ;
V_57 += F_26 ( V_56 ) ;
}
return V_57 ;
}
static int F_27 ( struct V_36 * V_37 ,
struct V_14 * V_30 ,
struct V_38 * V_38 , struct V_49 * V_12 )
{
int V_62 ;
T_2 V_57 = 0 ;
struct V_25 * V_63 =
(struct V_25 * ) V_38 -> V_64 ;
struct V_65 * V_66 =
(struct V_65 * ) V_63 ;
V_62 = F_28 ( V_37 ) ;
if ( ! V_62 )
return 1 ;
else if ( V_62 < 0 )
return 0 ;
F_19 ( V_37 , V_38 , V_62 ) ;
if ( V_62 == 1 ) {
F_23 ( V_37 , V_62 , V_63 ) ;
return 1 ;
}
V_66 -> V_67 . V_59 = 0 ;
V_66 -> V_67 . V_60 = V_62 * sizeof( struct V_25 ) ;
V_66 -> V_67 . V_61 = 0 ;
if ( V_62 <= V_43 ) {
V_57 = F_23 ( V_37 , V_62 ,
& V_66 -> V_68 [ 0 ] ) ;
V_66 -> V_60 = V_57 ;
return 1 ;
}
if ( ! V_30 -> V_21 ) {
V_30 -> V_21 = (struct V_25 * )
F_3 ( V_12 ,
V_24 * sizeof( struct V_25 ) ,
& V_30 -> V_22 , 0 ) ;
if ( ! V_30 -> V_21 ) {
if ( ! F_29 ( V_69 ) )
F_30 ( V_29 , V_37 -> V_49 ,
L_8
L_9 ) ;
F_22 ( V_37 ) ;
return 0 ;
}
}
V_57 = F_23 ( V_37 , V_62 , V_30 -> V_21 ) ;
V_66 -> V_60 = V_57 ;
V_66 -> V_67 . V_59 = V_30 -> V_22 ;
V_66 -> V_67 . V_60 = V_62 * sizeof( V_66 -> V_68 [ 0 ] ) ;
memcpy ( V_66 -> V_68 , V_30 -> V_21 ,
V_43 * sizeof( struct V_25 ) ) ;
return 1 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_14 * V_30 ,
struct V_38 * V_38 , struct V_49 * V_12 )
{
switch ( V_37 -> V_44 ) {
case V_70 :
case V_45 :
break;
case V_71 :
return 1 ;
case V_72 :
F_30 ( V_29 , V_37 -> V_49 ,
L_10 ) ;
return 0 ;
default:
F_30 ( V_29 , V_37 -> V_49 ,
L_11 ,
V_37 -> V_44 ) ;
return 0 ;
}
return F_27 ( V_37 , V_30 , V_38 , V_12 ) ;
}
static void F_32 ( struct V_4 * V_5 , int V_73 )
{
struct V_14 * V_15 ;
unsigned long V_74 ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
while ( ! F_34 ( & V_5 -> V_77 ) ) {
V_15 = F_35 ( & V_5 -> V_77 , struct V_14 , V_78 ) ;
F_36 ( & V_15 -> V_78 ) ;
F_37 ( & V_15 -> V_79 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( V_15 -> V_33 ) {
V_15 -> V_33 -> V_80 = ( V_73 << 16 ) ;
F_21 ( & V_15 -> V_81 . V_82 . V_37 , V_15 ,
V_15 -> V_5 -> V_12 ) ;
if ( V_15 -> V_34 )
V_15 -> V_34 ( V_15 -> V_33 ) ;
} else if ( V_15 -> F_18 )
V_15 -> F_18 ( V_15 ) ;
F_11 ( & V_15 -> V_5 -> V_2 , V_15 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
}
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
}
static void F_39 ( struct V_4 * V_5 )
{
F_40 ( V_5 -> V_75 ) ;
F_5 ( & V_5 -> V_83 , 0 ) ;
F_32 ( V_5 , V_84 ) ;
V_5 -> V_85 = 1 ;
F_41 ( & V_5 -> V_86 ) ;
}
static void F_42 ( struct V_14 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
F_12 ( V_5 -> V_12 , L_12 ,
V_30 -> V_81 . V_82 . V_37 . V_87 ) ;
F_39 ( V_5 ) ;
}
static int F_43 ( struct V_14 * V_30 ,
struct V_4 * V_5 ,
unsigned long V_32 )
{
T_2 * V_88 = ( T_2 * ) & V_30 -> V_16 ;
int V_89 = 0 ;
int V_90 ;
int V_91 = 0 ;
if ( V_30 -> V_16 . V_31 == V_92 ) {
V_91 = 1 ;
V_89 =
F_15 ( & V_5 -> V_83 ) ;
if ( V_89 < - 1 )
goto V_93;
else if ( V_89 == - 1 &&
V_30 -> V_81 . V_82 . V_94 . V_87 != V_95 )
goto V_96;
else if ( V_89 < 2 &&
V_30 -> V_81 . V_82 . V_37 . V_87 != V_97 ) {
int V_98 = V_89 ;
struct V_14 * V_99 ;
F_44 (tmp_evt, &hostdata->sent, list) {
V_98 ++ ;
}
if ( V_98 > 2 )
goto V_96;
}
}
* V_30 -> V_19 = V_30 -> V_81 ;
V_30 -> V_19 -> V_82 . V_100 . V_101 = ( T_2 ) V_30 ;
F_45 ( & V_30 -> V_78 , & V_5 -> V_77 ) ;
F_46 ( & V_30 -> V_79 ) ;
if ( V_32 ) {
V_30 -> V_79 . V_63 = ( unsigned long ) V_30 ;
V_30 -> V_79 . V_102 = V_103 + ( V_32 * V_104 ) ;
V_30 -> V_79 . V_105 = ( void (*) ( unsigned long ) ) F_42 ;
F_47 ( & V_30 -> V_79 ) ;
}
if ( ( V_90 =
V_106 -> V_107 ( V_5 , V_88 [ 0 ] , V_88 [ 1 ] ) ) != 0 ) {
F_36 ( & V_30 -> V_78 ) ;
F_37 ( & V_30 -> V_79 ) ;
if ( V_90 == V_108 ) {
F_9 ( V_5 -> V_12 , L_13
L_14 ) ;
goto V_96;
}
F_12 ( V_5 -> V_12 , L_15 , V_90 ) ;
if ( V_91 )
F_48 ( & V_5 -> V_83 ) ;
goto V_93;
}
return 0 ;
V_96:
F_21 ( & V_30 -> V_81 . V_82 . V_37 , V_30 , V_5 -> V_12 ) ;
F_11 ( & V_5 -> V_2 , V_30 ) ;
if ( V_91 && V_89 != - 1 )
F_48 ( & V_5 -> V_83 ) ;
return V_109 ;
V_93:
F_21 ( & V_30 -> V_81 . V_82 . V_37 , V_30 , V_5 -> V_12 ) ;
if ( V_30 -> V_33 != NULL ) {
V_30 -> V_33 -> V_80 = V_84 << 16 ;
V_30 -> V_34 ( V_30 -> V_33 ) ;
} else if ( V_30 -> F_18 )
V_30 -> F_18 ( V_30 ) ;
F_11 ( & V_5 -> V_2 , V_30 ) ;
return 0 ;
}
static void F_49 ( struct V_14 * V_30 )
{
struct V_110 * V_100 = & V_30 -> V_19 -> V_82 . V_100 ;
struct V_36 * V_33 = V_30 -> V_33 ;
if ( F_50 ( V_100 -> V_87 != V_111 ) ) {
if ( F_51 () )
F_9 ( V_30 -> V_5 -> V_12 ,
L_16 , V_100 -> V_87 ) ;
}
if ( V_33 ) {
V_33 -> V_80 |= V_100 -> V_112 ;
if ( ( ( V_33 -> V_80 >> 1 ) & 0x1f ) == V_113 )
memcpy ( V_33 -> V_114 ,
V_100 -> V_63 ,
V_100 -> V_115 ) ;
F_21 ( & V_30 -> V_81 . V_82 . V_37 ,
V_30 ,
V_30 -> V_5 -> V_12 ) ;
if ( V_100 -> V_74 & V_116 )
F_52 ( V_33 , V_100 -> V_117 ) ;
else if ( V_100 -> V_74 & V_118 )
F_52 ( V_33 , V_100 -> V_119 ) ;
}
if ( V_30 -> V_34 )
V_30 -> V_34 ( V_33 ) ;
}
static inline T_3 F_53 ( struct V_120 * V_12 )
{
return ( 0x2 << 14 ) | ( V_12 -> V_121 << 8 ) | ( V_12 -> V_122 << 5 ) | V_12 -> V_123 ;
}
static int F_54 ( struct V_36 * V_33 ,
void (* F_18) ( struct V_36 * ) )
{
struct V_38 * V_38 ;
struct V_14 * V_30 ;
struct V_65 * V_66 ;
struct V_4 * V_5 = F_55 ( V_33 -> V_49 -> V_75 ) ;
T_3 V_123 = F_53 ( V_33 -> V_49 ) ;
T_1 V_50 , V_51 ;
V_33 -> V_80 = ( V_124 << 16 ) ;
V_30 = F_14 ( & V_5 -> V_2 ) ;
if ( ! V_30 )
return V_109 ;
V_38 = & V_30 -> V_81 . V_82 . V_37 ;
memset ( V_38 , 0x00 , V_125 ) ;
V_38 -> V_87 = V_126 ;
memcpy ( V_38 -> V_127 , V_33 -> V_33 , sizeof( V_38 -> V_127 ) ) ;
V_38 -> V_123 = ( ( T_2 ) V_123 ) << 48 ;
if ( ! F_31 ( V_33 , V_30 , V_38 , V_5 -> V_12 ) ) {
if ( ! F_29 ( V_69 ) )
F_30 ( V_29 , V_33 -> V_49 ,
L_17 ) ;
F_11 ( & V_5 -> V_2 , V_30 ) ;
return V_109 ;
}
F_17 ( V_30 ,
F_49 ,
V_92 ,
V_33 -> V_128 -> V_32 / V_104 ) ;
V_30 -> V_33 = V_33 ;
V_30 -> V_34 = F_18 ;
V_66 = (struct V_65 * ) V_38 -> V_64 ;
V_50 = V_38 -> V_48 >> 4 ;
V_51 = V_38 -> V_48 & ( ( 1U << 4 ) - 1 ) ;
if ( ( V_51 == V_42 ||
V_50 == V_42 ) &&
V_66 -> V_67 . V_59 == 0 ) {
V_66 -> V_67 . V_59 = V_30 -> V_16 . V_20 +
F_56 ( struct V_38 , V_64 ) +
F_56 ( struct V_65 , V_68 ) ;
}
return F_43 ( V_30 , V_5 , 0 ) ;
}
void F_57 ( struct V_4 * V_5 )
{
F_58 ( V_5 -> V_12 , V_5 -> V_129 ,
sizeof( V_5 -> V_130 ) , V_72 ) ;
F_58 ( V_5 -> V_12 , V_5 -> V_131 ,
sizeof( V_5 -> V_132 ) , V_72 ) ;
}
static void F_59 ( struct V_14 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
switch ( V_30 -> V_19 -> V_82 . F_59 . V_87 ) {
case V_133 :
break;
case V_134 :
F_60 ( V_5 -> V_12 , L_18 ,
V_30 -> V_19 -> V_82 . V_135 . V_136 ) ;
F_5 ( & V_5 -> V_83 , - 1 ) ;
return;
default:
F_12 ( V_5 -> V_12 , L_19 ,
V_30 -> V_19 -> V_82 . F_59 . V_87 ) ;
F_5 ( & V_5 -> V_83 , - 1 ) ;
return;
}
F_60 ( V_5 -> V_12 , L_20 ) ;
V_5 -> V_137 = 0 ;
F_5 ( & V_5 -> V_83 ,
V_30 -> V_19 -> V_82 . F_59 . V_138 ) ;
F_61 ( V_5 -> V_75 ) ;
}
static int F_62 ( struct V_4 * V_5 )
{
int V_90 ;
unsigned long V_74 ;
struct V_139 * V_140 ;
struct V_14 * V_30 = F_14 ( & V_5 -> V_2 ) ;
F_63 ( ! V_30 ) ;
F_17 ( V_30 , F_59 ,
V_92 , V_141 ) ;
V_140 = & V_30 -> V_81 . V_82 . V_94 ;
memset ( V_140 , 0 , sizeof( * V_140 ) ) ;
V_140 -> V_87 = V_95 ;
V_140 -> V_142 = sizeof( union V_143 ) ;
V_140 -> V_144 = V_145 | V_146 ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_5 ( & V_5 -> V_83 , 0 ) ;
V_90 = F_43 ( V_30 , V_5 , V_141 * 2 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_60 ( V_5 -> V_12 , L_21 ) ;
return V_90 ;
}
static void F_64 ( struct V_14 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
if ( V_30 -> V_19 -> V_147 . V_148 . V_149 . V_112 ) {
F_12 ( V_5 -> V_12 , L_22 ,
V_30 -> V_19 -> V_147 . V_148 . V_149 . V_112 ) ;
} else {
if ( V_5 -> V_130 . V_150 . V_149 . V_151 != V_152 )
F_60 ( V_5 -> V_12 , L_23 ) ;
if ( V_153 ) {
if ( V_5 -> V_130 . V_154 . V_149 . V_151 ==
V_152 )
F_60 ( V_5 -> V_12 , L_24 ) ;
else
F_60 ( V_5 -> V_12 , L_25 ) ;
}
}
F_62 ( V_5 ) ;
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_155 * V_156 ;
struct V_14 * V_30 ;
unsigned long V_74 ;
struct V_157 * V_158 = V_5 -> V_12 -> V_158 ;
const char * V_159 ;
V_30 = F_14 ( & V_5 -> V_2 ) ;
F_63 ( ! V_30 ) ;
F_17 ( V_30 , F_64 ,
V_160 , V_161 ) ;
V_156 = & V_30 -> V_81 . V_147 . V_148 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_5 -> V_130 . V_74 = V_162 ;
if ( V_5 -> V_137 )
V_5 -> V_130 . V_74 |= V_163 ;
strncpy ( V_5 -> V_130 . V_164 , F_66 ( & V_5 -> V_75 -> V_165 ) ,
sizeof( V_5 -> V_130 . V_164 ) ) ;
V_5 -> V_130 . V_164 [ sizeof( V_5 -> V_130 . V_164 ) - 1 ] = '\0' ;
V_159 = F_67 ( V_158 , L_26 , NULL ) ;
V_159 = V_159 ? V_159 : F_66 ( V_5 -> V_12 ) ;
strncpy ( V_5 -> V_130 . V_166 , V_159 , sizeof( V_5 -> V_130 . V_166 ) ) ;
V_5 -> V_130 . V_166 [ sizeof( V_5 -> V_130 . V_166 ) - 1 ] = '\0' ;
V_156 -> V_149 . type = V_167 ;
V_156 -> V_168 = V_5 -> V_129 ;
V_5 -> V_130 . V_150 . V_149 . V_169 = V_170 ;
V_5 -> V_130 . V_150 . V_149 . V_171 = sizeof( V_5 -> V_130 . V_150 ) ;
V_5 -> V_130 . V_150 . V_149 . V_151 = V_152 ;
V_5 -> V_130 . V_150 . V_172 = 1 ;
if ( V_153 ) {
V_5 -> V_130 . V_154 . V_149 . V_169 = V_173 ;
V_5 -> V_130 . V_154 . V_149 . V_171 = sizeof( V_5 -> V_130 . V_154 ) ;
V_5 -> V_130 . V_154 . V_149 . V_151 = V_152 ;
V_5 -> V_130 . V_154 . type = V_174 ;
V_156 -> V_149 . V_171 = sizeof( V_5 -> V_130 ) ;
} else
V_156 -> V_149 . V_171 = sizeof( V_5 -> V_130 ) - sizeof( V_5 -> V_130 . V_154 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( F_43 ( V_30 , V_5 , V_161 * 2 ) )
F_12 ( V_5 -> V_12 , L_27 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
}
static void F_68 ( struct V_14 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
T_1 V_112 = V_30 -> V_19 -> V_147 . V_175 . V_149 . V_112 ;
if ( V_112 == V_176 )
F_12 ( V_5 -> V_12 , L_28 ) ;
else if ( V_112 == V_177 )
F_12 ( V_5 -> V_12 , L_29 ) ;
else if ( V_112 != V_178 )
F_12 ( V_5 -> V_12 , L_30 , V_112 ) ;
F_65 ( V_5 ) ;
}
static int F_69 ( struct V_4 * V_5 )
{
int V_90 ;
unsigned long V_74 ;
struct V_179 * V_180 ;
struct V_14 * V_30 ;
if ( ! V_175 ) {
F_65 ( V_5 ) ;
return 0 ;
}
V_30 = F_14 ( & V_5 -> V_2 ) ;
F_63 ( ! V_30 ) ;
F_17 ( V_30 , F_68 , V_160 , V_161 ) ;
V_180 = & V_30 -> V_81 . V_147 . V_175 ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_149 . type = V_181 ;
V_180 -> V_149 . V_171 = sizeof( * V_180 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
V_90 = F_43 ( V_30 , V_5 , V_161 * 2 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
return V_90 ;
}
static void F_70 ( struct V_14 * V_30 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
if ( V_30 -> V_19 -> V_147 . V_182 . V_149 . V_112 ) {
F_12 ( V_5 -> V_12 , L_31 ,
V_30 -> V_19 -> V_147 . V_182 . V_149 . V_112 ) ;
} else {
F_60 ( V_5 -> V_12 , L_32
L_33 ,
V_5 -> V_132 . V_183 ,
V_5 -> V_132 . V_184 ,
V_5 -> V_132 . V_185 ,
V_5 -> V_132 . V_186 ,
V_5 -> V_132 . V_187 [ 0 ] ) ;
if ( V_5 -> V_132 . V_187 [ 0 ] )
V_5 -> V_75 -> V_188 =
V_5 -> V_132 . V_187 [ 0 ] >> 9 ;
if ( V_5 -> V_132 . V_186 == 3 &&
strcmp ( V_5 -> V_132 . V_183 , L_34 ) <= 0 ) {
F_12 ( V_5 -> V_12 , L_35 ,
V_5 -> V_132 . V_183 ) ;
F_12 ( V_5 -> V_12 , L_36 ,
V_43 ) ;
V_5 -> V_75 -> V_189 = V_43 ;
}
if ( V_5 -> V_132 . V_186 == 3 ) {
F_69 ( V_5 ) ;
return;
}
}
F_62 ( V_5 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_190 * V_156 ;
struct V_14 * V_30 ;
unsigned long V_74 ;
V_30 = F_14 ( & V_5 -> V_2 ) ;
F_63 ( ! V_30 ) ;
F_17 ( V_30 ,
F_70 ,
V_160 ,
V_161 ) ;
V_156 = & V_30 -> V_81 . V_147 . V_182 ;
memset ( V_156 , 0x00 , sizeof( * V_156 ) ) ;
V_156 -> V_149 . type = V_191 ;
V_156 -> V_149 . V_171 = sizeof( V_5 -> V_132 ) ;
V_156 -> V_168 = V_5 -> V_131 ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( F_43 ( V_30 , V_5 , V_161 * 2 ) )
F_12 ( V_5 -> V_12 , L_37 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
}
static void F_72 ( struct V_4 * V_5 )
{
F_71 ( V_5 ) ;
}
static void F_73 ( struct V_14 * V_30 )
{
if ( V_30 -> V_35 )
* V_30 -> V_35 = * V_30 -> V_19 ;
F_74 ( & V_30 -> V_192 ) ;
}
static int F_75 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = F_55 ( V_37 -> V_49 -> V_75 ) ;
struct V_193 * V_194 ;
struct V_14 * V_15 ;
struct V_14 * V_99 , * V_195 ;
union V_196 V_110 ;
int V_197 ;
unsigned long V_74 ;
T_3 V_123 = F_53 ( V_37 -> V_49 ) ;
unsigned long V_198 = 0 ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
V_198 = V_103 + ( V_199 * V_104 ) ;
do {
V_195 = NULL ;
F_44 (tmp_evt, &hostdata->sent, list) {
if ( V_99 -> V_33 == V_37 ) {
V_195 = V_99 ;
break;
}
}
if ( ! V_195 ) {
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
return V_200 ;
}
V_15 = F_14 ( & V_5 -> V_2 ) ;
if ( V_15 == NULL ) {
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_30 ( V_29 , V_37 -> V_49 ,
L_38 ) ;
return V_201 ;
}
F_17 ( V_15 ,
F_73 ,
V_92 ,
V_202 ) ;
V_194 = & V_15 -> V_81 . V_82 . V_194 ;
memset ( V_194 , 0x00 , sizeof( * V_194 ) ) ;
V_194 -> V_87 = V_97 ;
V_194 -> V_123 = ( ( T_2 ) V_123 ) << 48 ;
V_194 -> V_203 = V_204 ;
V_194 -> V_205 = ( T_2 ) V_195 ;
V_15 -> V_35 = & V_110 ;
F_76 ( & V_15 -> V_192 ) ;
V_197 = F_43 ( V_15 , V_5 , V_202 * 2 ) ;
if ( V_197 != V_109 )
break;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_77 ( 10 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
} while ( F_78 ( V_103 , V_198 ) );
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( V_197 != 0 ) {
F_30 ( V_29 , V_37 -> V_49 ,
L_39 , V_197 ) ;
return V_201 ;
}
F_30 ( V_206 , V_37 -> V_49 ,
L_40 ,
( ( ( T_2 ) V_123 ) << 48 ) , ( T_2 ) V_195 ) ;
F_79 ( & V_15 -> V_192 ) ;
if ( F_50 ( V_110 . V_82 . V_100 . V_87 != V_111 ) ) {
if ( F_51 () )
F_30 ( V_207 , V_37 -> V_49 , L_41 ,
V_110 . V_82 . V_100 . V_87 ) ;
return V_201 ;
}
if ( V_110 . V_82 . V_100 . V_74 & V_208 )
V_197 = * ( ( int * ) V_110 . V_82 . V_100 . V_63 ) ;
else
V_197 = V_110 . V_82 . V_100 . V_112 ;
if ( V_197 ) {
if ( F_51 () )
F_30 ( V_207 , V_37 -> V_49 ,
L_42 ,
V_197 , V_194 -> V_205 ) ;
return V_201 ;
}
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
V_195 = NULL ;
F_44 (tmp_evt, &hostdata->sent, list) {
if ( V_99 -> V_33 == V_37 ) {
V_195 = V_99 ;
break;
}
}
if ( V_195 == NULL ) {
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_30 ( V_206 , V_37 -> V_49 , L_43 ,
V_194 -> V_205 ) ;
return V_200 ;
}
F_30 ( V_206 , V_37 -> V_49 , L_44 ,
V_194 -> V_205 ) ;
V_37 -> V_80 = ( V_209 << 16 ) ;
F_36 ( & V_195 -> V_78 ) ;
F_21 ( & V_195 -> V_81 . V_82 . V_37 , V_195 ,
V_195 -> V_5 -> V_12 ) ;
F_11 ( & V_195 -> V_5 -> V_2 , V_195 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_48 ( & V_5 -> V_83 ) ;
return V_200 ;
}
static int F_80 ( struct V_36 * V_37 )
{
struct V_4 * V_5 = F_55 ( V_37 -> V_49 -> V_75 ) ;
struct V_193 * V_194 ;
struct V_14 * V_15 ;
struct V_14 * V_99 , * V_210 ;
union V_196 V_110 ;
int V_197 ;
unsigned long V_74 ;
T_3 V_123 = F_53 ( V_37 -> V_49 ) ;
unsigned long V_198 = 0 ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
V_198 = V_103 + ( V_199 * V_104 ) ;
do {
V_15 = F_14 ( & V_5 -> V_2 ) ;
if ( V_15 == NULL ) {
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_30 ( V_29 , V_37 -> V_49 ,
L_45 ) ;
return V_201 ;
}
F_17 ( V_15 ,
F_73 ,
V_92 ,
V_211 ) ;
V_194 = & V_15 -> V_81 . V_82 . V_194 ;
memset ( V_194 , 0x00 , sizeof( * V_194 ) ) ;
V_194 -> V_87 = V_97 ;
V_194 -> V_123 = ( ( T_2 ) V_123 ) << 48 ;
V_194 -> V_203 = V_212 ;
V_15 -> V_35 = & V_110 ;
F_76 ( & V_15 -> V_192 ) ;
V_197 = F_43 ( V_15 , V_5 , V_211 * 2 ) ;
if ( V_197 != V_109 )
break;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_77 ( 10 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
} while ( F_78 ( V_103 , V_198 ) );
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( V_197 != 0 ) {
F_30 ( V_29 , V_37 -> V_49 ,
L_46 , V_197 ) ;
return V_201 ;
}
F_30 ( V_206 , V_37 -> V_49 , L_47 ,
( ( ( T_2 ) V_123 ) << 48 ) ) ;
F_79 ( & V_15 -> V_192 ) ;
if ( F_50 ( V_110 . V_82 . V_100 . V_87 != V_111 ) ) {
if ( F_51 () )
F_30 ( V_207 , V_37 -> V_49 , L_48 ,
V_110 . V_82 . V_100 . V_87 ) ;
return V_201 ;
}
if ( V_110 . V_82 . V_100 . V_74 & V_208 )
V_197 = * ( ( int * ) V_110 . V_82 . V_100 . V_63 ) ;
else
V_197 = V_110 . V_82 . V_100 . V_112 ;
if ( V_197 ) {
if ( F_51 () )
F_30 ( V_207 , V_37 -> V_49 ,
L_49 ,
V_197 , V_194 -> V_205 ) ;
return V_201 ;
}
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
F_81 (tmp_evt, pos, &hostdata->sent, list) {
if ( ( V_99 -> V_33 ) && ( V_99 -> V_33 -> V_49 == V_37 -> V_49 ) ) {
if ( V_99 -> V_33 )
V_99 -> V_33 -> V_80 = ( V_213 << 16 ) ;
F_36 ( & V_99 -> V_78 ) ;
F_21 ( & V_99 -> V_81 . V_82 . V_37 , V_99 ,
V_99 -> V_5 -> V_12 ) ;
F_11 ( & V_99 -> V_5 -> V_2 ,
V_99 ) ;
F_48 ( & V_5 -> V_83 ) ;
if ( V_99 -> V_34 )
V_99 -> V_34 ( V_99 -> V_33 ) ;
else if ( V_99 -> F_18 )
V_99 -> F_18 ( V_99 ) ;
}
}
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
return V_200 ;
}
static int F_82 ( struct V_36 * V_37 )
{
unsigned long V_198 = 0 ;
struct V_4 * V_5 = F_55 ( V_37 -> V_49 -> V_75 ) ;
F_12 ( V_5 -> V_12 , L_50 ) ;
F_39 ( V_5 ) ;
for ( V_198 = V_103 + ( V_199 * V_104 ) ;
F_78 ( V_103 , V_198 ) &&
F_7 ( & V_5 -> V_83 ) < 2 ; ) {
F_77 ( 10 ) ;
}
if ( F_7 ( & V_5 -> V_83 ) <= 0 )
return V_201 ;
return V_200 ;
}
void F_83 ( struct V_214 * V_16 ,
struct V_4 * V_5 )
{
long V_90 ;
unsigned long V_74 ;
struct V_14 * V_30 =
(struct V_14 * ) V_16 -> V_20 ;
switch ( V_16 -> V_17 ) {
case 0xC0 :
switch ( V_16 -> V_31 ) {
case 0x01 :
F_60 ( V_5 -> V_12 , L_51 ) ;
if ( ( V_90 = V_106 -> V_107 ( V_5 ,
0xC002000000000000LL , 0 ) ) == 0 ) {
F_72 ( V_5 ) ;
} else {
F_12 ( V_5 -> V_12 , L_52 , V_90 ) ;
}
break;
case 0x02 :
F_60 ( V_5 -> V_12 , L_53 ) ;
F_72 ( V_5 ) ;
break;
default:
F_12 ( V_5 -> V_12 , L_54 , V_16 -> V_31 ) ;
}
return;
case 0xFF :
F_40 ( V_5 -> V_75 ) ;
F_5 ( & V_5 -> V_83 , 0 ) ;
if ( V_16 -> V_31 == 0x06 ) {
F_60 ( V_5 -> V_12 , L_55 ) ;
V_5 -> V_137 = 1 ;
V_5 -> V_215 = 1 ;
F_32 ( V_5 , V_216 ) ;
F_41 ( & V_5 -> V_86 ) ;
} else {
F_12 ( V_5 -> V_12 , L_56 ,
V_16 -> V_31 ) ;
F_39 ( V_5 ) ;
}
return;
case 0x80 :
break;
default:
F_12 ( V_5 -> V_12 , L_57 ,
V_16 -> V_17 ) ;
return;
}
if ( ! F_10 ( & V_5 -> V_2 , V_30 ) ) {
F_12 ( V_5 -> V_12 , L_58 ,
( void * ) V_16 -> V_20 ) ;
return;
}
if ( F_7 ( & V_30 -> free ) ) {
F_12 ( V_5 -> V_12 , L_59 ,
( void * ) V_16 -> V_20 ) ;
return;
}
if ( V_16 -> V_31 == V_92 )
F_84 ( V_30 -> V_19 -> V_82 . V_100 . V_138 ,
& V_5 -> V_83 ) ;
F_37 ( & V_30 -> V_79 ) ;
if ( ( V_16 -> V_112 != V_217 && V_16 -> V_112 != V_218 ) && V_30 -> V_33 )
V_30 -> V_33 -> V_80 = V_84 << 16 ;
if ( V_30 -> F_18 )
V_30 -> F_18 ( V_30 ) ;
else
F_12 ( V_5 -> V_12 , L_60 ) ;
F_33 ( V_30 -> V_5 -> V_75 -> V_76 , V_74 ) ;
F_36 ( & V_30 -> V_78 ) ;
F_11 ( & V_30 -> V_5 -> V_2 , V_30 ) ;
F_38 ( V_30 -> V_5 -> V_75 -> V_76 , V_74 ) ;
}
static int F_85 ( struct V_4 * V_5 ,
unsigned char * V_168 , int V_171 )
{
struct V_219 * V_220 ;
struct V_14 * V_30 ;
unsigned long V_74 ;
T_4 V_221 ;
int V_90 ;
V_30 = F_14 ( & V_5 -> V_2 ) ;
if ( ! V_30 ) {
F_12 ( V_5 -> V_12 , L_61 ) ;
return - 1 ;
}
F_17 ( V_30 ,
F_73 ,
V_160 ,
V_161 ) ;
V_220 = & V_30 -> V_81 . V_147 . V_220 ;
memset ( V_220 , 0x00 , sizeof( * V_220 ) ) ;
V_220 -> V_149 . type = V_222 ;
V_220 -> V_149 . V_171 = V_171 ;
V_220 -> V_168 = V_221 = F_86 ( V_5 -> V_12 , V_168 ,
V_171 ,
V_72 ) ;
if ( F_87 ( V_5 -> V_12 , V_220 -> V_168 ) ) {
if ( ! F_29 ( V_69 ) )
F_12 ( V_5 -> V_12 ,
L_62 ) ;
F_11 ( & V_5 -> V_2 , V_30 ) ;
return - 1 ;
}
F_76 ( & V_30 -> V_192 ) ;
F_33 ( V_5 -> V_75 -> V_76 , V_74 ) ;
V_90 = F_43 ( V_30 , V_5 , V_161 * 2 ) ;
F_38 ( V_5 -> V_75 -> V_76 , V_74 ) ;
if ( V_90 == 0 )
F_79 ( & V_30 -> V_192 ) ;
F_58 ( V_5 -> V_12 , V_221 , V_171 , V_72 ) ;
return V_90 ;
}
static int F_88 ( struct V_120 * V_223 )
{
struct V_224 * V_225 = V_223 -> V_75 ;
unsigned long V_226 = 0 ;
F_33 ( V_225 -> V_76 , V_226 ) ;
if ( V_223 -> type == V_227 ) {
V_223 -> V_228 = 1 ;
F_89 ( V_223 -> V_229 , 120 * V_104 ) ;
}
F_90 ( V_223 , 0 , V_225 -> V_230 ) ;
F_38 ( V_225 -> V_76 , V_226 ) ;
return 0 ;
}
static int F_91 ( struct V_120 * V_223 , int V_231 ,
int V_136 )
{
if ( V_136 != V_232 )
return - V_233 ;
if ( V_231 > V_234 )
V_231 = V_234 ;
F_90 ( V_223 , 0 , V_231 ) ;
return V_223 -> V_235 ;
}
static T_5 F_92 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , sizeof( V_5 -> V_130 . V_166 ) , L_63 ,
V_5 -> V_130 . V_166 ) ;
return V_60 ;
}
static T_5 F_94 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , sizeof( V_5 -> V_130 . V_164 ) , L_63 ,
V_5 -> V_130 . V_164 ) ;
return V_60 ;
}
static T_5 F_95 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , V_239 , L_63 ,
V_5 -> V_132 . V_183 ) ;
return V_60 ;
}
static T_5 F_96 ( struct V_49 * V_12 ,
struct V_236 * V_237 ,
char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , V_239 , L_63 ,
V_5 -> V_132 . V_184 ) ;
return V_60 ;
}
static T_5 F_97 ( struct V_49 * V_12 ,
struct V_236 * V_237 ,
char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , V_239 , L_64 ,
V_5 -> V_132 . V_185 ) ;
return V_60 ;
}
static T_5 F_98 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , V_239 , L_64 ,
V_5 -> V_132 . V_240 ) ;
return V_60 ;
}
static T_5 F_99 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
int V_60 ;
V_60 = snprintf ( V_238 , V_239 , L_64 , V_5 -> V_132 . V_186 ) ;
return V_60 ;
}
static T_5 F_100 ( struct V_49 * V_12 ,
struct V_236 * V_237 , char * V_238 )
{
struct V_224 * V_225 = F_93 ( V_12 ) ;
struct V_4 * V_5 = F_55 ( V_225 ) ;
if ( F_85 ( V_5 , V_238 , V_239 ) == 0 )
return strlen ( V_238 ) ;
else
return 0 ;
}
static unsigned long F_101 ( struct V_241 * V_242 )
{
unsigned long V_243 = V_244 * sizeof( union V_196 ) ;
V_243 += ( V_245 * 512 *
V_246 ) ;
return V_243 ;
}
static void F_102 ( struct V_4 * V_5 )
{
int V_90 ;
char * V_247 = L_65 ;
if ( V_5 -> V_85 ) {
F_103 () ;
V_5 -> V_85 = 0 ;
V_90 = V_106 -> V_248 ( & V_5 -> V_249 , V_5 ) ;
if ( ! V_90 )
V_90 = V_106 -> V_107 ( V_5 , 0xC001000000000000LL , 0 ) ;
F_104 ( F_105 ( V_5 -> V_12 ) ) ;
} else if ( V_5 -> V_215 ) {
F_103 () ;
V_247 = L_66 ;
V_90 = V_106 -> V_250 ( & V_5 -> V_249 , V_5 ) ;
V_5 -> V_215 = 0 ;
if ( ! V_90 )
V_90 = V_106 -> V_107 ( V_5 , 0xC001000000000000LL , 0 ) ;
} else
return;
if ( V_90 ) {
F_5 ( & V_5 -> V_83 , - 1 ) ;
F_12 ( V_5 -> V_12 , L_67 , V_247 ) ;
}
F_61 ( V_5 -> V_75 ) ;
}
static int F_106 ( struct V_4 * V_5 )
{
if ( F_107 () )
return 1 ;
else if ( V_5 -> V_85 ) {
F_103 () ;
return 1 ;
} else if ( V_5 -> V_215 ) {
F_103 () ;
return 1 ;
}
return 0 ;
}
static int F_108 ( void * V_63 )
{
struct V_4 * V_5 = V_63 ;
int V_90 ;
F_109 ( V_251 , - 20 ) ;
while ( 1 ) {
V_90 = F_110 ( V_5 -> V_86 ,
F_106 ( V_5 ) ) ;
F_63 ( V_90 ) ;
if ( F_107 () )
break;
F_102 ( V_5 ) ;
}
return 0 ;
}
static int F_111 ( struct V_241 * V_242 , const struct V_252 * V_121 )
{
struct V_4 * V_5 ;
struct V_224 * V_75 ;
struct V_49 * V_12 = & V_242 -> V_12 ;
struct V_253 V_254 ;
struct V_255 * V_256 ;
unsigned long V_198 = 0 ;
int V_90 ;
F_112 ( & V_242 -> V_12 , NULL ) ;
V_75 = F_113 ( & V_257 , sizeof( * V_5 ) ) ;
if ( ! V_75 ) {
F_12 ( & V_242 -> V_12 , L_68 ) ;
goto V_258;
}
V_75 -> V_259 = V_260 ;
V_5 = F_55 ( V_75 ) ;
memset ( V_5 , 0x00 , sizeof( * V_5 ) ) ;
F_114 ( & V_5 -> V_77 ) ;
F_115 ( & V_5 -> V_86 ) ;
V_5 -> V_75 = V_75 ;
V_5 -> V_12 = V_12 ;
F_5 ( & V_5 -> V_83 , - 1 ) ;
V_5 -> V_75 -> V_188 = V_245 ;
if ( F_116 ( V_5 ) ) {
F_12 ( & V_242 -> V_12 , L_69 ) ;
goto V_261;
}
V_5 -> V_262 = F_117 ( F_108 , V_5 , L_70 ,
L_71 , V_75 -> V_263 ) ;
if ( F_118 ( V_5 -> V_262 ) ) {
F_12 ( & V_242 -> V_12 , L_72 ,
F_119 ( V_5 -> V_262 ) ) ;
goto V_264;
}
V_90 = V_106 -> V_265 ( & V_5 -> V_249 , V_5 , V_244 ) ;
if ( V_90 != 0 && V_90 != V_266 ) {
F_12 ( & V_242 -> V_12 , L_73 , V_90 ) ;
goto V_267;
}
if ( F_1 ( & V_5 -> V_2 , V_244 , V_5 ) != 0 ) {
F_12 ( & V_242 -> V_12 , L_74 ) ;
goto V_268;
}
V_75 -> V_269 = 8 ;
V_75 -> V_270 = V_270 ;
V_75 -> V_271 = V_271 ;
V_75 -> V_272 = 16 ;
if ( F_120 ( V_5 -> V_75 , V_5 -> V_12 ) )
goto V_273;
memcpy ( V_254 . V_274 , V_5 -> V_132 . V_184 ,
sizeof( V_254 . V_274 ) ) ;
V_254 . V_275 = V_276 ;
V_256 = F_121 ( V_75 , & V_254 ) ;
if ( F_118 ( V_256 ) )
goto V_277;
if ( V_106 -> V_107 ( V_5 , 0xC001000000000000LL , 0 ) == 0
|| V_90 == V_266 ) {
for ( V_198 = V_103 + ( V_199 * V_104 ) ;
F_78 ( V_103 , V_198 ) &&
F_7 ( & V_5 -> V_83 ) < 2 ; ) {
F_77 ( 10 ) ;
}
if ( F_7 ( & V_5 -> V_83 ) > 0 )
F_122 ( V_75 ) ;
}
F_112 ( & V_242 -> V_12 , V_5 ) ;
return 0 ;
V_277:
F_123 ( V_5 -> V_75 ) ;
V_273:
F_6 ( & V_5 -> V_2 , V_5 ) ;
V_268:
V_106 -> V_278 ( & V_5 -> V_249 , V_5 , V_244 ) ;
V_267:
F_124 ( V_5 -> V_262 ) ;
V_264:
F_57 ( V_5 ) ;
V_261:
F_125 ( V_75 ) ;
V_258:
return - 1 ;
}
static int F_126 ( struct V_241 * V_242 )
{
struct V_4 * V_5 = F_127 ( & V_242 -> V_12 ) ;
F_57 ( V_5 ) ;
F_6 ( & V_5 -> V_2 , V_5 ) ;
V_106 -> V_278 ( & V_5 -> V_249 , V_5 ,
V_244 ) ;
F_124 ( V_5 -> V_262 ) ;
F_128 ( V_5 -> V_75 ) ;
F_123 ( V_5 -> V_75 ) ;
F_125 ( V_5 -> V_75 ) ;
return 0 ;
}
static int F_129 ( struct V_49 * V_12 )
{
struct V_4 * V_5 = F_127 ( V_12 ) ;
return V_106 -> V_279 ( V_5 ) ;
}
int T_6 F_130 ( void )
{
int V_280 ;
V_257 . V_281 = V_282 ;
V_244 = V_282 + 2 ;
if ( F_29 ( V_283 ) )
V_106 = & V_284 ;
else
return - V_285 ;
V_260 =
F_131 ( & V_286 ) ;
if ( ! V_260 )
return - V_10 ;
V_280 = F_132 ( & V_287 ) ;
if ( V_280 )
F_133 ( V_260 ) ;
return V_280 ;
}
void T_7 F_134 ( void )
{
F_135 ( & V_287 ) ;
F_133 ( V_260 ) ;
}
