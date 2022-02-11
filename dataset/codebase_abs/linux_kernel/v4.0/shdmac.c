static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_7 -> V_8 +
V_2 -> V_9 . V_10 ;
T_1 V_11 = V_4 -> V_7 -> V_12 ? 1 << V_6 -> V_13 : 0 ;
F_3 ( V_11 , V_4 -> V_14 + V_6 -> V_15 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
F_3 ( V_16 , V_2 -> V_18 + V_17 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_17 )
{
return F_6 ( V_2 -> V_18 + V_17 ) ;
}
static T_2 F_7 ( struct V_3 * V_4 )
{
void T_3 * V_19 = V_4 -> V_14 + V_20 ;
if ( V_4 -> V_7 -> V_21 )
return F_6 ( V_19 ) ;
else
return F_8 ( V_19 ) ;
}
static void F_9 ( struct V_3 * V_4 , T_2 V_16 )
{
void T_3 * V_19 = V_4 -> V_14 + V_20 ;
if ( V_4 -> V_7 -> V_21 )
F_3 ( V_16 , V_19 ) ;
else
F_10 ( V_16 , V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_16 , V_2 -> V_18 + V_4 -> V_22 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( V_2 -> V_18 + V_4 -> V_22 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
unsigned short V_23 ;
unsigned long V_24 ;
F_14 ( & V_25 , V_24 ) ;
V_23 = F_7 ( V_4 ) ;
F_9 ( V_4 , V_23 & ~ ( V_26 | V_27 | V_28 ) ) ;
F_15 ( & V_25 , V_24 ) ;
}
static int F_16 ( struct V_3 * V_4 )
{
unsigned short V_23 ;
unsigned long V_24 ;
F_14 ( & V_25 , V_24 ) ;
V_23 = F_7 ( V_4 ) & ~ ( V_26 | V_27 | V_28 ) ;
if ( V_4 -> V_7 -> V_29 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_7 -> V_31 ; V_30 ++ ) {
struct V_1 * V_32 = V_4 -> V_33 [ V_30 ] ;
if ( V_32 )
F_1 ( V_32 ) ;
}
}
F_9 ( V_4 , V_23 | V_4 -> V_7 -> V_34 ) ;
V_23 = F_7 ( V_4 ) ;
F_15 ( & V_25 , V_24 ) ;
if ( V_23 & ( V_27 | V_26 ) ) {
F_17 ( V_4 -> V_35 . V_36 . V_37 , L_1 ) ;
return - V_38 ;
}
if ( V_4 -> V_7 -> V_34 & ~ V_23 )
F_17 ( V_4 -> V_35 . V_36 . V_37 ,
L_2 ,
V_23 , V_4 -> V_7 -> V_34 ) ;
return 0 ;
}
static bool F_18 ( struct V_1 * V_32 )
{
T_1 V_39 = F_12 ( V_32 ) ;
if ( ( V_39 & ( V_40 | V_41 ) ) == V_40 )
return true ;
return false ;
}
static unsigned int F_19 ( struct V_1 * V_32 , T_1 V_39 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
int V_43 = ( ( V_39 & V_7 -> V_44 ) >> V_7 -> V_45 ) |
( ( V_39 & V_7 -> V_46 ) >> V_7 -> V_47 ) ;
if ( V_43 >= V_7 -> V_48 )
V_43 = 0 ;
return V_7 -> V_49 [ V_43 ] ;
}
static T_1 F_20 ( struct V_1 * V_32 , int V_50 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_7 -> V_48 ; V_30 ++ )
if ( V_7 -> V_49 [ V_30 ] == V_50 )
break;
if ( V_30 == V_7 -> V_48 )
V_30 = 0 ;
return ( ( V_30 << V_7 -> V_45 ) & V_7 -> V_44 ) |
( ( V_30 << V_7 -> V_47 ) & V_7 -> V_46 ) ;
}
static void F_21 ( struct V_1 * V_32 , struct V_51 * V_52 )
{
F_4 ( V_32 , V_52 -> V_53 , V_54 ) ;
F_4 ( V_32 , V_52 -> V_55 , V_56 ) ;
F_4 ( V_32 , V_52 -> V_57 >> V_32 -> V_58 , V_59 ) ;
}
static void F_22 ( struct V_1 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
T_1 V_39 = F_12 ( V_32 ) ;
if ( V_4 -> V_7 -> V_60 )
F_4 ( V_32 , 0xFFFFFFFF , V_61 ) ;
V_39 |= V_40 | V_4 -> V_62 ;
F_11 ( V_32 , V_39 & ~ V_41 ) ;
}
static void F_23 ( struct V_1 * V_32 )
{
T_1 V_39 = V_63 | V_64 | V_65 | F_20 ( V_32 ,
V_66 ) ;
V_32 -> V_58 = F_19 ( V_32 , V_39 ) ;
F_11 ( V_32 , V_39 ) ;
}
static int F_24 ( struct V_1 * V_32 , T_1 V_11 )
{
if ( F_18 ( V_32 ) )
return - V_67 ;
V_32 -> V_58 = F_19 ( V_32 , V_11 ) ;
F_11 ( V_32 , V_11 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_32 , T_2 V_11 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
const struct V_5 * V_6 = & V_7 -> V_8 [ V_32 -> V_9 . V_10 ] ;
void T_3 * V_19 = V_4 -> V_68 ;
unsigned int V_69 = V_6 -> V_70 ;
if ( F_18 ( V_32 ) )
return - V_67 ;
if ( V_7 -> V_71 )
return 0 ;
if ( ! V_19 )
V_19 = V_4 -> V_14 ;
V_19 += V_6 -> V_68 ;
F_10 ( ( F_8 ( V_19 ) & ( 0xff00 >> V_69 ) ) | ( V_11 << V_69 ) ,
V_19 ) ;
return 0 ;
}
static void F_26 ( struct V_9 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
struct V_75 * V_76 = F_27 ( V_74 ,
struct V_75 , V_73 ) ;
F_28 ( V_32 -> V_9 . V_37 , L_3 ,
V_74 -> V_77 . V_78 , V_32 -> V_9 . V_10 ,
V_76 -> V_52 . V_57 , V_76 -> V_52 . V_53 , V_76 -> V_52 . V_55 ) ;
F_21 ( V_32 , & V_76 -> V_52 ) ;
F_22 ( V_32 ) ;
}
static bool F_29 ( struct V_9 * V_72 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
return F_18 ( V_32 ) ;
}
static void F_30 ( struct V_9 * V_72 ,
int V_79 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
if ( V_79 >= 0 ) {
const struct V_80 * V_81 =
V_32 -> V_82 ;
F_25 ( V_32 , V_81 -> V_83 ) ;
F_24 ( V_32 , V_81 -> V_39 ) ;
} else {
F_23 ( V_32 ) ;
}
}
static const struct V_80 * F_31 (
struct V_1 * V_32 , int V_84 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
const struct V_80 * V_81 ;
int V_30 ;
if ( ! V_32 -> V_9 . V_37 -> V_85 ) {
if ( V_84 >= V_86 )
return NULL ;
for ( V_30 = 0 , V_81 = V_7 -> V_87 ; V_30 < V_7 -> V_88 ; V_30 ++ , V_81 ++ )
if ( V_81 -> V_79 == V_84 )
return V_81 ;
} else {
for ( V_30 = 0 , V_81 = V_7 -> V_87 ; V_30 < V_7 -> V_88 ; V_30 ++ , V_81 ++ )
if ( V_81 -> V_83 == V_84 ) {
V_32 -> V_9 . V_79 = V_30 ;
return V_81 ;
}
}
return NULL ;
}
static int F_32 ( struct V_9 * V_72 ,
int V_79 , T_4 V_89 , bool V_90 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
const struct V_80 * V_81 = F_31 ( V_32 , V_79 ) ;
if ( ! V_81 )
return - V_91 ;
if ( ! V_90 ) {
V_32 -> V_82 = V_81 ;
V_32 -> V_89 = V_89 ? : V_81 -> V_19 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
T_1 V_39 = F_12 ( V_32 ) ;
V_39 &= ~ ( V_40 | V_41 | V_4 -> V_62 ) ;
F_11 ( V_32 , V_39 ) ;
}
static int F_34 ( struct V_9 * V_72 ,
struct V_73 * V_74 ,
T_4 V_92 , T_4 V_93 , T_5 * V_94 )
{
struct V_75 * V_76 = F_27 ( V_74 ,
struct V_75 , V_73 ) ;
if ( * V_94 > V_72 -> V_95 )
* V_94 = V_72 -> V_95 ;
V_76 -> V_52 . V_53 = V_92 ;
V_76 -> V_52 . V_55 = V_93 ;
V_76 -> V_52 . V_57 = * V_94 ;
return 0 ;
}
static void F_35 ( struct V_9 * V_72 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
F_33 ( V_32 ) ;
}
static bool F_36 ( struct V_9 * V_72 , int V_96 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
if ( ! ( F_12 ( V_32 ) & V_41 ) )
return false ;
F_33 ( V_32 ) ;
return true ;
}
static T_5 F_37 ( struct V_9 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_32 = F_27 ( V_72 , struct V_1 ,
V_9 ) ;
struct V_75 * V_76 = F_27 ( V_74 ,
struct V_75 , V_73 ) ;
return V_76 -> V_52 . V_57 -
( F_5 ( V_32 , V_59 ) << V_32 -> V_58 ) ;
}
static bool F_38 ( struct V_3 * V_4 )
{
bool V_97 ;
F_13 ( V_4 ) ;
V_97 = F_39 ( & V_4 -> V_35 ) ;
F_16 ( V_4 ) ;
return V_97 ;
}
static T_6 F_40 ( int V_96 , void * V_16 )
{
struct V_3 * V_4 = V_16 ;
if ( ! ( F_7 ( V_4 ) & V_27 ) )
return V_98 ;
F_38 ( V_4 ) ;
return V_99 ;
}
static bool F_41 ( struct V_9 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_32 = F_27 ( V_72 ,
struct V_1 , V_9 ) ;
struct V_75 * V_76 = F_27 ( V_74 ,
struct V_75 , V_73 ) ;
T_1 V_100 = F_5 ( V_32 , V_54 ) ;
T_1 V_101 = F_5 ( V_32 , V_56 ) ;
return ( V_74 -> V_102 == V_103 &&
( V_76 -> V_52 . V_55 + V_76 -> V_52 . V_57 ) == V_101 ) ||
( V_74 -> V_102 != V_103 &&
( V_76 -> V_52 . V_53 + V_76 -> V_52 . V_57 ) == V_100 ) ;
}
static bool F_42 ( struct V_3 * V_4 )
{
if ( ( F_7 ( V_4 ) & V_26 ) == 0 )
return false ;
return F_38 ( V_4 ) ;
}
static int F_43 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_16 )
{
struct V_3 * V_4 ;
int V_97 = V_107 ;
bool V_108 ;
if ( ! F_44 () )
return V_107 ;
F_45 () ;
F_46 (shdev, &sh_dmae_devices, node) {
V_108 = F_42 ( V_4 ) ;
if ( V_108 == true )
V_97 = V_109 ;
}
F_47 () ;
return V_97 ;
}
static int F_48 ( struct V_3 * V_4 , int V_10 ,
int V_96 , unsigned long V_24 )
{
const struct V_5 * V_6 = & V_4 -> V_7 -> V_8 [ V_10 ] ;
struct V_35 * V_110 = & V_4 -> V_35 ;
struct V_111 * V_112 = F_49 ( V_110 -> V_36 . V_37 ) ;
struct V_1 * V_32 ;
struct V_9 * V_72 ;
int V_113 ;
V_32 = F_50 ( V_110 -> V_36 . V_37 , sizeof( struct V_1 ) ,
V_114 ) ;
if ( ! V_32 ) {
F_51 ( V_110 -> V_36 . V_37 ,
L_4 ) ;
return - V_115 ;
}
V_72 = & V_32 -> V_9 ;
V_72 -> V_95 = V_116 + 1 ;
F_52 ( V_110 , V_72 , V_10 ) ;
V_32 -> V_18 = V_4 -> V_14 + V_6 -> V_117 ;
if ( V_112 -> V_10 >= 0 )
snprintf ( V_32 -> V_118 , sizeof( V_32 -> V_118 ) ,
L_5 , V_112 -> V_10 , V_10 ) ;
else
snprintf ( V_32 -> V_118 , sizeof( V_32 -> V_118 ) ,
L_6 , V_10 ) ;
V_113 = F_53 ( V_72 , V_96 , V_24 , V_32 -> V_118 ) ;
if ( V_113 ) {
F_51 ( V_110 -> V_36 . V_37 ,
L_7 ,
V_10 , V_113 ) ;
goto V_119;
}
V_4 -> V_33 [ V_10 ] = V_32 ;
return 0 ;
V_119:
F_54 ( V_72 ) ;
return V_113 ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_9 * V_72 ;
int V_30 ;
F_56 (schan, &shdev->shdma_dev, i) {
F_57 ( ! V_72 ) ;
F_54 ( V_72 ) ;
}
}
static int F_58 ( struct V_120 * V_37 )
{
struct V_3 * V_4 = F_59 ( V_37 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static int F_60 ( struct V_120 * V_37 )
{
struct V_3 * V_4 = F_59 ( V_37 ) ;
return F_16 ( V_4 ) ;
}
static int F_61 ( struct V_120 * V_37 )
{
struct V_3 * V_4 = F_59 ( V_37 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static int F_62 ( struct V_120 * V_37 )
{
struct V_3 * V_4 = F_59 ( V_37 ) ;
int V_30 , V_97 ;
V_97 = F_16 ( V_4 ) ;
if ( V_97 < 0 )
F_51 ( V_37 , L_8 ) ;
for ( V_30 = 0 ; V_30 < V_4 -> V_7 -> V_31 ; V_30 ++ ) {
struct V_1 * V_32 = V_4 -> V_33 [ V_30 ] ;
if ( ! V_32 -> V_9 . V_121 )
continue;
if ( V_32 -> V_9 . V_79 >= 0 ) {
const struct V_80 * V_81 = V_32 -> V_82 ;
F_25 ( V_32 , V_81 -> V_83 ) ;
F_24 ( V_32 , V_81 -> V_39 ) ;
} else {
F_23 ( V_32 ) ;
}
}
return 0 ;
}
static T_4 F_63 ( struct V_9 * V_72 )
{
struct V_1 * V_32 = F_27 ( V_72 ,
struct V_1 , V_9 ) ;
return V_32 -> V_89 ;
}
static struct V_73 * F_64 ( void * V_122 , int V_30 )
{
return & ( (struct V_75 * ) V_122 ) [ V_30 ] . V_73 ;
}
static int F_65 ( struct V_111 * V_112 )
{
const enum V_123 V_124 =
V_125 | V_126 |
V_127 | V_128 |
V_129 | V_130 ;
const struct V_42 * V_7 ;
unsigned long V_131 [ V_132 ] = {} ;
int V_133 [ V_132 ] ;
#if F_66 ( V_134 ) || F_66 ( V_135 )
unsigned long V_136 = 0 ;
int V_137 ;
#endif
int V_113 , V_30 , V_138 = 0 , V_139 = 0 , V_140 = 0 ;
struct V_3 * V_4 ;
struct V_141 * V_36 ;
struct V_142 * V_33 , * V_68 , * V_143 , * V_144 ;
if ( V_112 -> V_37 . V_85 )
V_7 = F_67 ( V_145 , & V_112 -> V_37 ) -> V_16 ;
else
V_7 = F_68 ( & V_112 -> V_37 ) ;
if ( ! V_7 || ! V_7 -> V_31 )
return - V_146 ;
V_33 = F_69 ( V_112 , V_147 , 0 ) ;
V_68 = F_69 ( V_112 , V_147 , 1 ) ;
V_143 = F_69 ( V_112 , V_148 , 0 ) ;
if ( ! V_33 || ! V_143 )
return - V_146 ;
V_4 = F_50 ( & V_112 -> V_37 , sizeof( struct V_3 ) ,
V_114 ) ;
if ( ! V_4 ) {
F_51 ( & V_112 -> V_37 , L_9 ) ;
return - V_115 ;
}
V_36 = & V_4 -> V_35 . V_36 ;
V_4 -> V_14 = F_70 ( & V_112 -> V_37 , V_33 ) ;
if ( F_71 ( V_4 -> V_14 ) )
return F_72 ( V_4 -> V_14 ) ;
if ( V_68 ) {
V_4 -> V_68 = F_70 ( & V_112 -> V_37 , V_68 ) ;
if ( F_71 ( V_4 -> V_68 ) )
return F_72 ( V_4 -> V_68 ) ;
}
V_36 -> V_149 = V_124 ;
V_36 -> V_150 = V_124 ;
V_36 -> V_151 = F_73 ( V_152 ) | F_73 ( V_103 ) ;
V_36 -> V_153 = V_154 ;
if ( ! V_7 -> V_155 )
F_74 ( V_156 , V_36 -> V_157 ) ;
if ( V_7 -> V_87 && V_7 -> V_88 )
F_74 ( V_158 , V_36 -> V_157 ) ;
V_36 -> V_159 = V_66 ;
V_4 -> V_35 . V_160 = & V_161 ;
V_4 -> V_35 . V_162 = sizeof( struct V_75 ) ;
V_113 = F_75 ( & V_112 -> V_37 , & V_4 -> V_35 ,
V_7 -> V_31 ) ;
if ( V_113 < 0 )
goto V_163;
V_4 -> V_7 = V_7 ;
if ( V_7 -> V_22 )
V_4 -> V_22 = V_7 -> V_22 ;
else
V_4 -> V_22 = V_164 ;
if ( V_7 -> V_62 )
V_4 -> V_62 = V_7 -> V_62 ;
else
V_4 -> V_62 = V_165 ;
F_76 ( V_112 , V_4 ) ;
F_77 ( & V_112 -> V_37 ) ;
V_113 = F_78 ( & V_112 -> V_37 ) ;
if ( V_113 < 0 )
F_51 ( & V_112 -> V_37 , L_10 , V_166 , V_113 ) ;
F_79 ( & V_25 ) ;
F_80 ( & V_4 -> V_167 , & V_168 ) ;
F_81 ( & V_25 ) ;
V_113 = F_16 ( V_4 ) ;
if ( V_113 )
goto V_169;
#if F_66 ( V_134 ) || F_66 ( V_170 )
V_144 = F_69 ( V_112 , V_148 , 1 ) ;
if ( ! V_144 )
V_144 = V_143 ;
else
V_139 ++ ;
if ( V_144 == V_143 ||
( V_143 -> V_24 & V_171 ) == V_172 )
V_136 = V_173 ;
V_137 = V_143 -> V_174 ;
V_113 = F_82 ( & V_112 -> V_37 , V_137 , F_40 , V_136 ,
L_11 , V_4 ) ;
if ( V_113 ) {
F_51 ( & V_112 -> V_37 ,
L_12 ,
V_137 , V_113 ) ;
goto V_175;
}
#else
V_144 = V_143 ;
#endif
if ( V_144 -> V_174 == V_144 -> V_176 &&
! F_69 ( V_112 , V_148 , 1 ) ) {
for (; V_138 < V_7 -> V_31 ; V_138 ++ ) {
if ( V_138 < V_132 ) {
V_133 [ V_138 ] = V_144 -> V_174 ;
V_131 [ V_138 ] = V_173 ;
} else {
V_140 = 1 ;
break;
}
}
} else {
do {
for ( V_30 = V_144 -> V_174 ; V_30 <= V_144 -> V_176 ; V_30 ++ ) {
if ( V_138 >= V_132 ) {
V_140 = 1 ;
break;
}
if ( ( V_143 -> V_24 & V_171 ) ==
V_172 )
V_131 [ V_138 ] = V_173 ;
else
V_131 [ V_138 ] = 0 ;
F_28 ( & V_112 -> V_37 ,
L_13 ,
V_30 , V_138 ) ;
V_133 [ V_138 ++ ] = V_30 ;
}
if ( V_138 >= V_132 )
break;
V_144 = F_69 ( V_112 ,
V_148 , ++ V_139 ) ;
} while ( V_138 < V_7 -> V_31 && V_144 );
}
for ( V_30 = 0 ; V_30 < V_138 ; V_30 ++ ) {
V_113 = F_48 ( V_4 , V_30 , V_133 [ V_30 ] , V_131 [ V_30 ] ) ;
if ( V_113 )
goto V_177;
}
if ( V_140 )
F_83 ( & V_112 -> V_37 , L_14
L_15 ,
V_7 -> V_31 , V_132 ) ;
F_84 ( & V_112 -> V_37 ) ;
V_113 = F_85 ( & V_4 -> V_35 . V_36 ) ;
if ( V_113 < 0 )
goto V_178;
return V_113 ;
V_178:
F_86 ( & V_112 -> V_37 ) ;
V_177:
F_55 ( V_4 ) ;
#if F_66 ( V_134 ) || F_66 ( V_170 )
V_175:
#endif
V_169:
F_79 ( & V_25 ) ;
F_87 ( & V_4 -> V_167 ) ;
F_81 ( & V_25 ) ;
F_84 ( & V_112 -> V_37 ) ;
F_88 ( & V_112 -> V_37 ) ;
F_89 ( & V_4 -> V_35 ) ;
V_163:
F_90 () ;
return V_113 ;
}
static int F_91 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_92 ( V_112 ) ;
struct V_141 * V_36 = & V_4 -> V_35 . V_36 ;
F_93 ( V_36 ) ;
F_79 ( & V_25 ) ;
F_87 ( & V_4 -> V_167 ) ;
F_81 ( & V_25 ) ;
F_88 ( & V_112 -> V_37 ) ;
F_55 ( V_4 ) ;
F_89 ( & V_4 -> V_35 ) ;
F_90 () ;
return 0 ;
}
static int T_7 F_94 ( void )
{
int V_113 = F_95 ( & V_179 ) ;
if ( V_113 )
return V_113 ;
return F_96 ( & V_180 , F_65 ) ;
}
static void T_8 F_97 ( void )
{
F_98 ( & V_180 ) ;
F_99 ( & V_179 ) ;
}
