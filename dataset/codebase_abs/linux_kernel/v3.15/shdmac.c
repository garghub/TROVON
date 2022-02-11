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
T_1 V_39 = V_63 | V_64 | 0x400 | F_20 ( V_32 ,
V_65 ) ;
V_32 -> V_58 = F_19 ( V_32 , V_39 ) ;
F_11 ( V_32 , V_39 ) ;
}
static int F_24 ( struct V_1 * V_32 , T_1 V_11 )
{
if ( F_18 ( V_32 ) )
return - V_66 ;
V_32 -> V_58 = F_19 ( V_32 , V_11 ) ;
F_11 ( V_32 , V_11 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_32 , T_2 V_11 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
const struct V_5 * V_6 = & V_7 -> V_8 [ V_32 -> V_9 . V_10 ] ;
void T_3 * V_19 = V_4 -> V_67 ;
unsigned int V_68 = V_6 -> V_69 ;
if ( F_18 ( V_32 ) )
return - V_66 ;
if ( V_7 -> V_70 )
return 0 ;
if ( ! V_19 )
V_19 = V_4 -> V_14 ;
V_19 += V_6 -> V_67 ;
F_10 ( ( F_8 ( V_19 ) & ( 0xff00 >> V_68 ) ) | ( V_11 << V_68 ) ,
V_19 ) ;
return 0 ;
}
static void F_26 ( struct V_9 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
struct V_74 * V_75 = F_27 ( V_73 ,
struct V_74 , V_72 ) ;
F_28 ( V_32 -> V_9 . V_37 , L_3 ,
V_73 -> V_76 . V_77 , V_32 -> V_9 . V_10 ,
V_75 -> V_52 . V_57 , V_75 -> V_52 . V_53 , V_75 -> V_52 . V_55 ) ;
F_21 ( V_32 , & V_75 -> V_52 ) ;
F_22 ( V_32 ) ;
}
static bool F_29 ( struct V_9 * V_71 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
return F_18 ( V_32 ) ;
}
static void F_30 ( struct V_9 * V_71 ,
int V_78 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
if ( V_78 >= 0 ) {
const struct V_79 * V_80 =
V_32 -> V_81 ;
F_25 ( V_32 , V_80 -> V_82 ) ;
F_24 ( V_32 , V_80 -> V_39 ) ;
} else {
F_23 ( V_32 ) ;
}
}
static const struct V_79 * F_31 (
struct V_1 * V_32 , int V_83 )
{
struct V_3 * V_4 = F_2 ( V_32 ) ;
const struct V_42 * V_7 = V_4 -> V_7 ;
const struct V_79 * V_80 ;
int V_30 ;
if ( ! V_32 -> V_9 . V_37 -> V_84 ) {
if ( V_83 >= V_85 )
return NULL ;
for ( V_30 = 0 , V_80 = V_7 -> V_86 ; V_30 < V_7 -> V_87 ; V_30 ++ , V_80 ++ )
if ( V_80 -> V_78 == V_83 )
return V_80 ;
} else {
for ( V_30 = 0 , V_80 = V_7 -> V_86 ; V_30 < V_7 -> V_87 ; V_30 ++ , V_80 ++ )
if ( V_80 -> V_82 == V_83 ) {
V_32 -> V_9 . V_78 = V_30 ;
return V_80 ;
}
}
return NULL ;
}
static int F_32 ( struct V_9 * V_71 ,
int V_78 , T_4 V_88 , bool V_89 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
const struct V_79 * V_80 = F_31 ( V_32 , V_78 ) ;
if ( ! V_80 )
return - V_90 ;
if ( ! V_89 ) {
V_32 -> V_81 = V_80 ;
V_32 -> V_88 = V_88 ? : V_80 -> V_19 ;
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
static int F_34 ( struct V_9 * V_71 ,
struct V_72 * V_73 ,
T_4 V_91 , T_4 V_92 , T_5 * V_93 )
{
struct V_74 * V_75 = F_27 ( V_73 ,
struct V_74 , V_72 ) ;
if ( * V_93 > V_71 -> V_94 )
* V_93 = V_71 -> V_94 ;
V_75 -> V_52 . V_53 = V_91 ;
V_75 -> V_52 . V_55 = V_92 ;
V_75 -> V_52 . V_57 = * V_93 ;
return 0 ;
}
static void F_35 ( struct V_9 * V_71 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
F_33 ( V_32 ) ;
}
static bool F_36 ( struct V_9 * V_71 , int V_95 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
if ( ! ( F_12 ( V_32 ) & V_41 ) )
return false ;
F_33 ( V_32 ) ;
return true ;
}
static T_5 F_37 ( struct V_9 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_32 = F_27 ( V_71 , struct V_1 ,
V_9 ) ;
struct V_74 * V_75 = F_27 ( V_73 ,
struct V_74 , V_72 ) ;
return V_75 -> V_52 . V_57 -
( F_5 ( V_32 , V_59 ) << V_32 -> V_58 ) ;
}
static bool F_38 ( struct V_3 * V_4 )
{
bool V_96 ;
F_13 ( V_4 ) ;
V_96 = F_39 ( & V_4 -> V_35 ) ;
F_16 ( V_4 ) ;
return V_96 ;
}
static T_6 F_40 ( int V_95 , void * V_16 )
{
struct V_3 * V_4 = V_16 ;
if ( ! ( F_7 ( V_4 ) & V_27 ) )
return V_97 ;
F_38 ( V_4 ) ;
return V_98 ;
}
static bool F_41 ( struct V_9 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_32 = F_27 ( V_71 ,
struct V_1 , V_9 ) ;
struct V_74 * V_75 = F_27 ( V_73 ,
struct V_74 , V_72 ) ;
T_1 V_99 = F_5 ( V_32 , V_54 ) ;
T_1 V_100 = F_5 ( V_32 , V_56 ) ;
return ( V_73 -> V_101 == V_102 &&
( V_75 -> V_52 . V_55 + V_75 -> V_52 . V_57 ) == V_100 ) ||
( V_73 -> V_101 != V_102 &&
( V_75 -> V_52 . V_53 + V_75 -> V_52 . V_57 ) == V_99 ) ;
}
static bool F_42 ( struct V_3 * V_4 )
{
if ( ( F_7 ( V_4 ) & V_26 ) == 0 )
return false ;
return F_38 ( V_4 ) ;
}
static int F_43 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_16 )
{
struct V_3 * V_4 ;
int V_96 = V_106 ;
bool V_107 ;
if ( ! F_44 () )
return V_106 ;
F_45 () ;
F_46 (shdev, &sh_dmae_devices, node) {
V_107 = F_42 ( V_4 ) ;
if ( V_107 == true )
V_96 = V_108 ;
}
F_47 () ;
return V_96 ;
}
static int F_48 ( struct V_3 * V_4 , int V_10 ,
int V_95 , unsigned long V_24 )
{
const struct V_5 * V_6 = & V_4 -> V_7 -> V_8 [ V_10 ] ;
struct V_35 * V_109 = & V_4 -> V_35 ;
struct V_110 * V_111 = F_49 ( V_109 -> V_36 . V_37 ) ;
struct V_1 * V_32 ;
struct V_9 * V_71 ;
int V_112 ;
V_32 = F_50 ( V_109 -> V_36 . V_37 , sizeof( struct V_1 ) ,
V_113 ) ;
if ( ! V_32 ) {
F_51 ( V_109 -> V_36 . V_37 ,
L_4 ) ;
return - V_114 ;
}
V_71 = & V_32 -> V_9 ;
V_71 -> V_94 = V_115 + 1 ;
F_52 ( V_109 , V_71 , V_10 ) ;
V_32 -> V_18 = V_4 -> V_14 + V_6 -> V_116 ;
if ( V_111 -> V_10 >= 0 )
snprintf ( V_32 -> V_117 , sizeof( V_32 -> V_117 ) ,
L_5 , V_111 -> V_10 , V_10 ) ;
else
snprintf ( V_32 -> V_117 , sizeof( V_32 -> V_117 ) ,
L_6 , V_10 ) ;
V_112 = F_53 ( V_71 , V_95 , V_24 , V_32 -> V_117 ) ;
if ( V_112 ) {
F_51 ( V_109 -> V_36 . V_37 ,
L_7 ,
V_10 , V_112 ) ;
goto V_118;
}
V_4 -> V_33 [ V_10 ] = V_32 ;
return 0 ;
V_118:
F_54 ( V_71 ) ;
return V_112 ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_119 * V_36 = & V_4 -> V_35 . V_36 ;
struct V_9 * V_71 ;
int V_30 ;
F_56 (schan, &shdev->shdma_dev, i) {
F_57 ( ! V_71 ) ;
F_54 ( V_71 ) ;
}
V_36 -> V_120 = 0 ;
}
static void F_58 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_59 ( V_111 ) ;
F_13 ( V_4 ) ;
}
static int F_60 ( struct V_121 * V_37 )
{
return 0 ;
}
static int F_61 ( struct V_121 * V_37 )
{
struct V_3 * V_4 = F_62 ( V_37 ) ;
return F_16 ( V_4 ) ;
}
static int F_63 ( struct V_121 * V_37 )
{
return 0 ;
}
static int F_64 ( struct V_121 * V_37 )
{
struct V_3 * V_4 = F_62 ( V_37 ) ;
int V_30 , V_96 ;
V_96 = F_16 ( V_4 ) ;
if ( V_96 < 0 )
F_51 ( V_37 , L_8 ) ;
for ( V_30 = 0 ; V_30 < V_4 -> V_7 -> V_31 ; V_30 ++ ) {
struct V_1 * V_32 = V_4 -> V_33 [ V_30 ] ;
if ( ! V_32 -> V_9 . V_122 )
continue;
if ( V_32 -> V_9 . V_78 >= 0 ) {
const struct V_79 * V_80 = V_32 -> V_81 ;
F_25 ( V_32 , V_80 -> V_82 ) ;
F_24 ( V_32 , V_80 -> V_39 ) ;
} else {
F_23 ( V_32 ) ;
}
}
return 0 ;
}
static T_4 F_65 ( struct V_9 * V_71 )
{
struct V_1 * V_32 = F_27 ( V_71 ,
struct V_1 , V_9 ) ;
return V_32 -> V_88 ;
}
static struct V_72 * F_66 ( void * V_123 , int V_30 )
{
return & ( (struct V_74 * ) V_123 ) [ V_30 ] . V_72 ;
}
static int F_67 ( struct V_110 * V_111 )
{
const struct V_42 * V_7 ;
unsigned long V_124 [ V_125 ] = {} ;
int V_126 [ V_125 ] ;
#if F_68 ( V_127 ) || F_68 ( V_128 )
unsigned long V_129 = 0 ;
int V_130 ;
#endif
int V_112 , V_30 , V_131 = 0 , V_132 = 0 , V_133 = 0 ;
struct V_3 * V_4 ;
struct V_119 * V_36 ;
struct V_134 * V_33 , * V_67 , * V_135 , * V_136 ;
if ( V_111 -> V_37 . V_84 )
V_7 = F_69 ( V_137 , & V_111 -> V_37 ) -> V_16 ;
else
V_7 = F_70 ( & V_111 -> V_37 ) ;
if ( ! V_7 || ! V_7 -> V_31 )
return - V_138 ;
V_33 = F_71 ( V_111 , V_139 , 0 ) ;
V_67 = F_71 ( V_111 , V_139 , 1 ) ;
V_135 = F_71 ( V_111 , V_140 , 0 ) ;
if ( ! V_33 || ! V_135 )
return - V_138 ;
V_4 = F_50 ( & V_111 -> V_37 , sizeof( struct V_3 ) ,
V_113 ) ;
if ( ! V_4 ) {
F_51 ( & V_111 -> V_37 , L_9 ) ;
return - V_114 ;
}
V_36 = & V_4 -> V_35 . V_36 ;
V_4 -> V_14 = F_72 ( & V_111 -> V_37 , V_33 ) ;
if ( F_73 ( V_4 -> V_14 ) )
return F_74 ( V_4 -> V_14 ) ;
if ( V_67 ) {
V_4 -> V_67 = F_72 ( & V_111 -> V_37 , V_67 ) ;
if ( F_73 ( V_4 -> V_67 ) )
return F_74 ( V_4 -> V_67 ) ;
}
if ( ! V_7 -> V_141 )
F_75 ( V_142 , V_36 -> V_143 ) ;
if ( V_7 -> V_86 && V_7 -> V_87 )
F_75 ( V_144 , V_36 -> V_143 ) ;
V_36 -> V_145 = V_65 ;
V_4 -> V_35 . V_146 = & V_147 ;
V_4 -> V_35 . V_148 = sizeof( struct V_74 ) ;
V_112 = F_76 ( & V_111 -> V_37 , & V_4 -> V_35 ,
V_7 -> V_31 ) ;
if ( V_112 < 0 )
goto V_149;
V_4 -> V_7 = V_7 ;
if ( V_7 -> V_22 )
V_4 -> V_22 = V_7 -> V_22 ;
else
V_4 -> V_22 = V_150 ;
if ( V_7 -> V_62 )
V_4 -> V_62 = V_7 -> V_62 ;
else
V_4 -> V_62 = V_151 ;
F_77 ( V_111 , V_4 ) ;
F_78 ( & V_111 -> V_37 ) ;
V_112 = F_79 ( & V_111 -> V_37 ) ;
if ( V_112 < 0 )
F_51 ( & V_111 -> V_37 , L_10 , V_152 , V_112 ) ;
F_80 ( & V_25 ) ;
F_81 ( & V_4 -> V_153 , & V_154 ) ;
F_82 ( & V_25 ) ;
V_112 = F_16 ( V_4 ) ;
if ( V_112 )
goto V_155;
#if F_68 ( V_127 ) || F_68 ( V_156 )
V_136 = F_71 ( V_111 , V_140 , 1 ) ;
if ( ! V_136 )
V_136 = V_135 ;
else
V_132 ++ ;
if ( V_136 == V_135 ||
( V_135 -> V_24 & V_157 ) == V_158 )
V_129 = V_159 ;
V_130 = V_135 -> V_160 ;
V_112 = F_83 ( & V_111 -> V_37 , V_130 , F_40 , V_129 ,
L_11 , V_4 ) ;
if ( V_112 ) {
F_51 ( & V_111 -> V_37 ,
L_12 ,
V_130 , V_112 ) ;
goto V_161;
}
#else
V_136 = V_135 ;
#endif
if ( V_136 -> V_160 == V_136 -> V_162 &&
! F_71 ( V_111 , V_140 , 1 ) ) {
for (; V_131 < V_7 -> V_31 ; V_131 ++ ) {
if ( V_131 < V_125 ) {
V_126 [ V_131 ] = V_136 -> V_160 ;
V_124 [ V_131 ] = V_159 ;
} else {
V_133 = 1 ;
break;
}
}
} else {
do {
for ( V_30 = V_136 -> V_160 ; V_30 <= V_136 -> V_162 ; V_30 ++ ) {
if ( V_131 >= V_125 ) {
V_133 = 1 ;
break;
}
if ( ( V_135 -> V_24 & V_157 ) ==
V_158 )
V_124 [ V_131 ] = V_159 ;
else
V_124 [ V_131 ] = 0 ;
F_28 ( & V_111 -> V_37 ,
L_13 ,
V_30 , V_131 ) ;
V_126 [ V_131 ++ ] = V_30 ;
}
if ( V_131 >= V_125 )
break;
V_136 = F_71 ( V_111 ,
V_140 , ++ V_132 ) ;
} while ( V_131 < V_7 -> V_31 && V_136 );
}
for ( V_30 = 0 ; V_30 < V_131 ; V_30 ++ ) {
V_112 = F_48 ( V_4 , V_30 , V_126 [ V_30 ] , V_124 [ V_30 ] ) ;
if ( V_112 )
goto V_163;
}
if ( V_133 )
F_84 ( & V_111 -> V_37 , L_14
L_15 ,
V_7 -> V_31 , V_125 ) ;
F_85 ( & V_111 -> V_37 ) ;
V_112 = F_86 ( & V_4 -> V_35 . V_36 ) ;
if ( V_112 < 0 )
goto V_164;
return V_112 ;
V_164:
F_87 ( & V_111 -> V_37 ) ;
V_163:
F_55 ( V_4 ) ;
#if F_68 ( V_127 ) || F_68 ( V_156 )
V_161:
#endif
V_155:
F_80 ( & V_25 ) ;
F_88 ( & V_4 -> V_153 ) ;
F_82 ( & V_25 ) ;
F_85 ( & V_111 -> V_37 ) ;
F_89 ( & V_111 -> V_37 ) ;
F_90 ( & V_4 -> V_35 ) ;
V_149:
F_91 () ;
return V_112 ;
}
static int F_92 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_59 ( V_111 ) ;
struct V_119 * V_36 = & V_4 -> V_35 . V_36 ;
F_93 ( V_36 ) ;
F_80 ( & V_25 ) ;
F_88 ( & V_4 -> V_153 ) ;
F_82 ( & V_25 ) ;
F_89 ( & V_111 -> V_37 ) ;
F_55 ( V_4 ) ;
F_90 ( & V_4 -> V_35 ) ;
F_91 () ;
return 0 ;
}
static int T_7 F_94 ( void )
{
int V_112 = F_95 ( & V_165 ) ;
if ( V_112 )
return V_112 ;
return F_96 ( & V_166 , F_67 ) ;
}
static void T_8 F_97 ( void )
{
F_98 ( & V_166 ) ;
F_99 ( & V_165 ) ;
}
