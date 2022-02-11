static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ? V_4 : V_5 ;
}
static inline T_1 F_2 ( T_1 V_6 ,
T_1 V_7 )
{
return F_3 ( V_6 , V_7 ) ;
}
static inline struct V_8 * F_4 ( struct V_9 * V_10 )
{
return F_5 ( V_10 , struct V_8 , V_11 ) ;
}
static inline struct V_1 * F_6 ( struct V_12 * V_2 )
{
return F_5 ( V_2 , struct V_1 , V_13 . V_14 ) ;
}
static inline struct V_15 * F_7 (
struct V_16 * V_17 )
{
return F_5 ( V_17 , struct V_15 , V_18 . V_19 ) ;
}
static void F_8 ( struct V_15 * V_20 )
{
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ )
F_9 ( V_20 -> V_2 -> V_23 , V_20 -> V_24 [ V_21 ] . V_25 ,
V_20 -> V_24 [ V_21 ] . V_26 ) ;
F_10 ( V_20 ) ;
}
static void F_11 ( struct V_27 * V_18 )
{
F_8 (
F_5 ( V_18 , struct V_15 , V_18 ) ) ;
}
static void F_12 (
struct V_1 * V_14 ,
struct V_28 * V_29 ,
T_1 V_6 ,
T_1 V_30 ,
T_1 * V_31 ,
T_2 V_32 )
{
T_1 V_7 = F_1 ( V_14 ) ;
V_29 -> V_33 = F_13 ( T_2 , V_6 , V_7 ) ;
if ( ! V_30 )
return;
if ( * V_31 + V_29 -> V_33 < V_30 )
return;
V_29 -> V_33 = V_30 - * V_31 ;
* V_31 = 0 ;
V_29 -> V_34 |= V_32 ;
}
static inline T_1 F_14 (
struct V_1 * V_2 ,
struct V_35 * V_36 ,
unsigned int V_37 )
{
T_1 V_22 = 0 ;
struct V_35 * V_38 ;
unsigned int V_21 ;
T_1 V_39 = F_1 ( V_2 ) ;
F_15 (sgl, sgent, sg_len, i)
V_22 += F_2 (
F_16 ( V_38 ) , V_39 ) ;
return V_22 ;
}
static struct V_15 * F_17 (
struct V_12 * V_14 , enum V_40 V_41 ,
bool V_42 , T_2 V_34 , T_2 V_32 , T_1 V_22 ,
T_3 V_43 , T_3 V_44 , T_1 V_45 ,
T_1 V_30 , T_4 V_46 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
T_1 V_6 = V_45 , V_31 ;
T_1 V_47 ;
struct V_15 * V_10 ;
struct V_48 * V_49 ;
struct V_28 * V_29 ;
if ( ! V_22 )
return NULL ;
V_10 = F_18 ( sizeof( * V_10 ) + V_22 * sizeof( struct V_48 ) ,
V_46 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_2 = V_2 ;
V_10 -> V_50 = V_41 ;
V_10 -> V_42 = V_42 ;
for ( V_47 = 0 , V_31 = 0 ; V_47 < V_22 ; V_10 -> V_22 ++ , V_47 ++ ) {
V_49 = & V_10 -> V_24 [ V_47 ] ;
V_49 -> V_25 = F_19 ( V_2 -> V_23 , V_46 ,
& V_49 -> V_26 ) ;
if ( ! V_49 -> V_25 )
goto V_51;
V_29 = V_49 -> V_25 ;
V_29 -> V_34 = V_34 ;
V_29 -> V_43 = V_43 ;
V_29 -> V_44 = V_44 ;
V_29 -> V_52 = 0 ;
V_29 -> V_53 = 0 ;
if ( V_45 ) {
F_12 (
V_2 , V_29 ,
V_6 , V_30 , & V_31 ,
V_42 ? V_32 : 0 ) ;
V_6 -= V_29 -> V_33 ;
}
if ( V_47 )
V_10 -> V_24 [ V_47 - 1 ] . V_25 -> V_53 = V_49 -> V_26 ;
if ( V_43 && ( V_34 & V_54 ) )
V_43 += V_29 -> V_33 ;
if ( V_44 && ( V_34 & V_55 ) )
V_44 += V_29 -> V_33 ;
V_10 -> V_56 += V_29 -> V_33 ;
}
V_10 -> V_24 [ V_10 -> V_22 - 1 ] . V_25 -> V_34 |= V_32 ;
if ( V_45 && ( V_10 -> V_56 != V_45 ) )
goto V_51;
return V_10 ;
V_51:
F_8 ( V_10 ) ;
return NULL ;
}
static void F_20 (
struct V_12 * V_14 ,
enum V_40 V_41 ,
struct V_48 * V_25 ,
struct V_35 * V_36 ,
unsigned int V_37 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
T_1 V_6 , V_7 ;
unsigned int V_21 ;
T_3 V_57 ;
struct V_35 * V_38 ;
V_7 = F_1 ( V_2 ) ;
F_15 (sgl, sgent, sg_len, i) {
for ( V_57 = F_21 ( V_38 ) , V_6 = F_16 ( V_38 ) ;
V_6 > 0 ;
V_57 += V_25 -> V_25 -> V_33 , V_6 -= V_25 -> V_25 -> V_33 , V_25 ++ ) {
if ( V_41 == V_58 )
V_25 -> V_25 -> V_44 = V_57 ;
else
V_25 -> V_25 -> V_43 = V_57 ;
V_25 -> V_25 -> V_33 = F_22 ( V_6 , V_7 ) ;
}
}
}
static int F_23 ( void T_5 * V_59 )
{
unsigned long V_60 ;
long int V_61 = 10000 ;
V_60 = F_24 ( V_59 + V_62 ) ;
if ( ! ( V_60 & V_63 ) )
return 0 ;
F_25 ( 0 , V_59 + V_62 ) ;
while ( ( V_60 & V_64 ) && -- V_61 ) {
F_26 () ;
V_60 = F_24 ( V_59 + V_62 ) ;
}
if ( ! V_61 )
return - V_65 ;
if ( ! ( V_60 & V_63 ) )
return 0 ;
F_25 ( 0 , V_59 + V_66 ) ;
F_25 ( V_67 | V_63 ,
V_59 + V_62 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_27 * V_18 = F_28 ( & V_2 -> V_13 ) ;
struct V_15 * V_10 ;
if ( ! V_18 ) {
V_2 -> V_20 = NULL ;
return;
}
F_29 ( & V_18 -> V_68 ) ;
V_2 -> V_20 = V_10 = F_7 ( & V_18 -> V_19 ) ;
F_25 ( V_10 -> V_24 [ 0 ] . V_26 , V_2 -> V_59 + V_69 ) ;
F_25 ( V_63 , V_2 -> V_59 + V_62 ) ;
}
static T_6 F_30 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
struct V_15 * V_10 ;
unsigned long V_72 ;
if ( V_2 -> V_73 & V_74 ) {
V_72 = F_24 ( V_2 -> V_59 + V_62 ) ;
if ( ! ( V_72 & V_75 ) )
return V_76 ;
}
F_31 ( & V_2 -> V_13 . V_77 , V_72 ) ;
F_25 ( V_75 , V_2 -> V_59 + V_62 ) ;
V_10 = V_2 -> V_20 ;
if ( V_10 ) {
if ( V_10 -> V_42 ) {
F_32 ( & V_10 -> V_18 ) ;
F_25 ( V_63 ,
V_2 -> V_59 + V_62 ) ;
} else {
F_33 ( & V_2 -> V_20 -> V_18 ) ;
F_27 ( V_2 ) ;
}
}
F_34 ( & V_2 -> V_13 . V_77 , V_72 ) ;
return V_78 ;
}
static int F_35 ( struct V_12 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_79 * V_80 = V_2 -> V_13 . V_14 . V_79 -> V_80 ;
F_36 ( V_80 , L_1 , V_2 -> V_81 ) ;
V_2 -> V_23 = F_37 ( F_38 ( V_80 ) , V_80 ,
sizeof( struct V_28 ) , 0 , 0 ) ;
if ( ! V_2 -> V_23 ) {
F_39 ( V_80 , L_2 ) ;
return - V_82 ;
}
return F_40 ( V_2 -> V_83 , F_30 ,
V_2 -> V_73 , L_3 , V_2 ) ;
}
static void F_41 ( struct V_12 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
F_42 ( & V_2 -> V_13 ) ;
F_43 ( V_2 -> V_83 , V_2 ) ;
F_44 ( V_2 -> V_23 ) ;
F_36 ( V_2 -> V_13 . V_14 . V_79 -> V_80 , L_4 , V_2 -> V_81 ) ;
}
static T_1 F_45 ( struct V_15 * V_10 )
{
return V_10 -> V_56 ;
}
static T_1 F_46 ( struct V_15 * V_10 , T_3 V_57 )
{
unsigned int V_21 ;
T_1 V_56 ;
for ( V_56 = V_21 = 0 ; V_21 < V_10 -> V_22 ; V_21 ++ ) {
struct V_28 * V_29 = V_10 -> V_24 [ V_21 ] . V_25 ;
T_1 V_84 = V_29 -> V_33 ;
T_3 V_85 ;
if ( V_10 -> V_50 == V_58 )
V_85 = V_29 -> V_44 ;
else
V_85 = V_29 -> V_43 ;
if ( V_56 )
V_56 += V_84 ;
else if ( V_57 >= V_85 && V_57 < V_85 + V_84 )
V_56 += V_85 + V_84 - V_57 ;
}
return V_56 ;
}
static enum V_86 F_47 ( struct V_12 * V_14 ,
T_7 V_87 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_27 * V_18 ;
enum V_86 V_90 ;
unsigned long V_72 ;
V_90 = F_48 ( V_14 , V_87 , V_89 ) ;
if ( V_90 == V_91 || ! V_89 )
return V_90 ;
F_31 ( & V_2 -> V_13 . V_77 , V_72 ) ;
V_18 = F_49 ( & V_2 -> V_13 , V_87 ) ;
if ( V_18 ) {
V_89 -> V_92 =
F_45 ( F_7 ( & V_18 -> V_19 ) ) ;
} else if ( V_2 -> V_20 && V_2 -> V_20 -> V_18 . V_19 . V_87 == V_87 ) {
struct V_15 * V_10 = V_2 -> V_20 ;
T_3 V_93 ;
if ( V_10 -> V_50 == V_94 )
V_93 = F_24 ( V_2 -> V_59 + V_95 ) ;
else if ( V_10 -> V_50 == V_58 )
V_93 = F_24 ( V_2 -> V_59 + V_96 ) ;
else
V_93 = 0 ;
V_89 -> V_92 = F_46 ( V_10 , V_93 ) ;
} else {
V_89 -> V_92 = 0 ;
}
F_34 ( & V_2 -> V_13 . V_77 , V_72 ) ;
return V_90 ;
}
static void F_50 ( struct V_12 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
unsigned long V_72 ;
F_31 ( & V_2 -> V_13 . V_77 , V_72 ) ;
if ( F_51 ( & V_2 -> V_13 ) && ! V_2 -> V_20 )
F_27 ( V_2 ) ;
F_34 ( & V_2 -> V_13 . V_77 , V_72 ) ;
}
static struct V_16 * F_52 (
struct V_12 * V_14 , T_3 V_44 , T_3 V_43 ,
T_1 V_6 , unsigned long V_72 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_15 * V_10 ;
T_2 V_34 = V_55 | V_54 ;
T_2 V_97 = V_98 | V_99 ;
T_1 V_7 = F_1 ( V_2 ) ;
T_1 V_22 ;
if ( ! V_43 || ! V_44 || ! V_6 )
return NULL ;
V_22 = F_2 ( V_6 , V_7 ) ;
V_10 = F_17 ( V_14 , V_100 , false ,
V_34 , V_97 , V_22 ,
V_43 , V_44 , V_6 , 0 , V_101 ) ;
if ( ! V_10 )
return NULL ;
return F_53 ( & V_2 -> V_13 , & V_10 -> V_18 , V_72 ) ;
}
static struct V_16 * F_54 (
struct V_12 * V_14 ,
struct V_35 * V_36 , unsigned int V_37 ,
enum V_40 V_41 ,
unsigned long V_72 , void * V_102 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_15 * V_10 ;
T_3 V_43 = 0 , V_44 = 0 ;
T_2 V_34 = V_99 ;
T_2 V_97 = V_98 ;
T_1 V_22 ;
if ( ! F_55 ( V_41 ) ) {
F_39 ( V_14 -> V_79 -> V_80 ,
L_5 , V_103 ) ;
return NULL ;
}
if ( V_2 -> V_104 != 0 )
V_34 |= F_56 ( V_2 -> V_104 ) ;
if ( V_41 == V_58 ) {
if ( V_2 -> V_105 . V_106 != V_107 )
return NULL ;
V_43 = V_2 -> V_105 . V_108 ;
V_34 |= V_109 | V_55 ;
} else {
if ( V_2 -> V_105 . V_110 != V_107 )
return NULL ;
V_44 = V_2 -> V_105 . V_111 ;
V_34 |= V_112 | V_54 ;
}
V_22 = F_14 ( V_2 , V_36 , V_37 ) ;
V_10 = F_17 ( V_14 , V_41 , false ,
V_34 , V_97 ,
V_22 , V_43 , V_44 , 0 , 0 ,
V_101 ) ;
if ( ! V_10 )
return NULL ;
F_20 ( V_14 , V_41 , V_10 -> V_24 ,
V_36 , V_37 ) ;
return F_53 ( & V_2 -> V_13 , & V_10 -> V_18 , V_72 ) ;
}
static struct V_16 * F_57 (
struct V_12 * V_14 , T_3 V_113 , T_1 V_45 ,
T_1 V_30 , enum V_40 V_41 ,
unsigned long V_72 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_15 * V_10 ;
T_3 V_43 , V_44 ;
T_2 V_34 = V_99 ;
T_2 V_97 = V_98 ;
T_1 V_7 = F_1 ( V_2 ) ;
T_1 V_22 ;
if ( ! F_55 ( V_41 ) ) {
F_39 ( V_14 -> V_79 -> V_80 , L_5 , V_103 ) ;
return NULL ;
}
if ( ! V_45 ) {
F_39 ( V_14 -> V_79 -> V_80 ,
L_6 , V_103 ) ;
return NULL ;
}
if ( V_45 % V_30 )
F_58 ( V_14 -> V_79 -> V_80 ,
L_7 ,
V_103 , V_45 , V_30 ) ;
if ( V_2 -> V_104 != 0 )
V_34 |= F_56 ( V_2 -> V_104 ) ;
if ( V_41 == V_58 ) {
if ( V_2 -> V_105 . V_106 != V_107 )
return NULL ;
V_43 = V_2 -> V_105 . V_108 ;
V_44 = V_113 ;
V_34 |= V_109 | V_55 ;
} else {
if ( V_2 -> V_105 . V_110 != V_107 )
return NULL ;
V_44 = V_2 -> V_105 . V_111 ;
V_43 = V_113 ;
V_34 |= V_112 | V_54 ;
}
V_22 =
F_3 ( V_45 , V_30 ) *
F_2 ( V_30 , V_7 ) ;
V_10 = F_17 ( V_14 , V_41 , true ,
V_34 , V_97 ,
V_22 , V_43 , V_44 , V_45 ,
V_30 , V_114 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_24 [ V_10 -> V_22 - 1 ] . V_25 -> V_53 = V_10 -> V_24 [ 0 ] . V_26 ;
return F_53 ( & V_2 -> V_13 , & V_10 -> V_18 , V_72 ) ;
}
static int F_59 ( struct V_12 * V_14 ,
struct V_115 * V_105 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
if ( ( V_105 -> V_41 == V_58 &&
V_105 -> V_106 != V_107 ) ||
( V_105 -> V_41 == V_94 &&
V_105 -> V_110 != V_107 ) ||
! F_55 ( V_105 -> V_41 ) ) {
return - V_116 ;
}
V_2 -> V_105 = * V_105 ;
return 0 ;
}
static int F_60 ( struct V_12 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
struct V_8 * V_10 = F_4 ( V_2 -> V_13 . V_14 . V_79 ) ;
unsigned long V_72 ;
int V_61 = 10000 ;
F_61 ( V_117 ) ;
F_31 ( & V_2 -> V_13 . V_77 , V_72 ) ;
F_62 ( & V_10 -> V_77 ) ;
F_63 ( & V_2 -> V_68 ) ;
F_64 ( & V_10 -> V_77 ) ;
if ( V_2 -> V_20 ) {
F_11 ( & V_2 -> V_20 -> V_18 ) ;
V_2 -> V_20 = NULL ;
F_23 ( V_2 -> V_59 ) ;
while ( -- V_61 ) {
if ( ! ( F_24 ( V_2 -> V_59 + V_62 ) &
V_63 ) )
break;
F_26 () ;
}
if ( ! V_61 )
F_39 ( V_10 -> V_11 . V_80 , L_8 ) ;
}
F_65 ( & V_2 -> V_13 , & V_117 ) ;
F_34 ( & V_2 -> V_13 . V_77 , V_72 ) ;
F_66 ( & V_2 -> V_13 , & V_117 ) ;
return 0 ;
}
static int F_67 ( struct V_8 * V_10 , int V_118 ,
int V_70 , unsigned int V_73 )
{
struct V_1 * V_2 ;
V_2 = F_68 ( V_10 -> V_11 . V_80 , sizeof( * V_2 ) , V_101 ) ;
if ( ! V_2 )
return - V_82 ;
V_2 -> V_13 . V_119 = F_11 ;
F_69 ( & V_2 -> V_13 , & V_10 -> V_11 ) ;
F_70 ( & V_2 -> V_68 ) ;
V_2 -> V_59 = F_71 ( V_10 -> V_120 , V_118 ) ;
V_2 -> V_81 = V_118 ;
V_2 -> V_83 = V_70 ;
V_2 -> V_73 = V_73 ;
if ( F_24 ( V_2 -> V_59 + V_121 ) &
V_122 )
V_2 -> V_3 = true ;
return 0 ;
}
static void F_72 ( struct V_8 * V_123 )
{
struct V_1 * V_2 , * V_53 ;
F_73 (c, next, &od->ddev.channels,
vc.chan.device_node) {
F_29 ( & V_2 -> V_13 . V_14 . V_124 ) ;
F_74 ( & V_2 -> V_13 . V_125 ) ;
}
}
static struct V_12 * F_75 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
struct V_8 * V_10 = V_129 -> V_130 ;
struct V_12 * V_14 ;
V_14 = F_76 ( & V_10 -> V_11 ) ;
if ( ! V_14 )
return NULL ;
F_6 ( V_14 ) -> V_104 = V_127 -> args [ 0 ] ;
return V_14 ;
}
static int F_77 ( struct V_131 * V_132 )
{
struct V_8 * V_123 ;
struct V_133 * V_134 ;
void T_5 * V_120 ;
int V_135 ;
int V_21 , V_136 ;
int V_70 [ V_137 + 1 ] ;
int V_73 ;
T_8 V_138 ;
char V_139 [ V_140 ] ;
if ( ! V_132 -> V_80 . V_141 )
V_132 -> V_80 . V_141 = & V_132 -> V_80 . V_142 ;
V_135 = F_78 ( & V_132 -> V_80 , F_79 ( 32 ) ) ;
if ( V_135 )
return V_135 ;
V_123 = F_68 ( & V_132 -> V_80 , sizeof( * V_123 ) , V_101 ) ;
if ( ! V_123 )
return - V_82 ;
V_132 -> V_80 . V_143 = & V_123 -> V_143 ;
F_80 ( & V_132 -> V_80 , 0x3FFFFFFF ) ;
V_134 = F_81 ( V_132 , V_144 , 0 ) ;
V_120 = F_82 ( & V_132 -> V_80 , V_134 ) ;
if ( F_83 ( V_120 ) )
return F_84 ( V_120 ) ;
V_123 -> V_120 = V_120 ;
F_85 ( V_145 , V_123 -> V_11 . V_146 ) ;
F_85 ( V_147 , V_123 -> V_11 . V_146 ) ;
F_85 ( V_148 , V_123 -> V_11 . V_146 ) ;
F_85 ( V_145 , V_123 -> V_11 . V_146 ) ;
F_85 ( V_149 , V_123 -> V_11 . V_146 ) ;
V_123 -> V_11 . V_150 = F_35 ;
V_123 -> V_11 . V_151 = F_41 ;
V_123 -> V_11 . V_152 = F_47 ;
V_123 -> V_11 . V_153 = F_50 ;
V_123 -> V_11 . V_154 = F_57 ;
V_123 -> V_11 . V_155 = F_54 ;
V_123 -> V_11 . V_156 = F_52 ;
V_123 -> V_11 . V_157 = F_59 ;
V_123 -> V_11 . V_158 = F_60 ;
V_123 -> V_11 . V_159 = F_86 ( V_107 ) ;
V_123 -> V_11 . V_160 = F_86 ( V_107 ) ;
V_123 -> V_11 . V_161 = F_86 ( V_58 ) | F_86 ( V_94 ) |
F_86 ( V_100 ) ;
V_123 -> V_11 . V_162 = V_163 ;
V_123 -> V_11 . V_80 = & V_132 -> V_80 ;
F_70 ( & V_123 -> V_11 . V_164 ) ;
F_87 ( & V_123 -> V_77 ) ;
F_88 ( V_132 , V_123 ) ;
if ( F_89 ( V_132 -> V_80 . V_165 ,
L_9 ,
& V_138 ) ) {
F_39 ( & V_132 -> V_80 , L_10 ) ;
V_135 = - V_116 ;
goto V_166;
}
for ( V_21 = 0 ; V_21 <= V_137 ; V_21 ++ ) {
if ( ! ( V_138 & ( 1 << V_21 ) ) ) {
V_70 [ V_21 ] = - 1 ;
continue;
}
snprintf ( V_139 , sizeof( V_139 ) , L_11 , V_21 ) ;
V_70 [ V_21 ] = F_90 ( V_132 , V_139 ) ;
if ( V_70 [ V_21 ] >= 0 )
continue;
F_58 ( & V_132 -> V_80 ,
L_12 ) ;
V_70 [ V_21 ] = F_91 ( V_132 , V_21 < 11 ? V_21 : 11 ) ;
}
for ( V_21 = 0 ; V_21 <= V_137 ; V_21 ++ ) {
if ( V_70 [ V_21 ] < 0 )
continue;
V_73 = 0 ;
for ( V_136 = 0 ; V_136 <= V_137 ; V_136 ++ )
if ( ( V_21 != V_136 ) && ( V_70 [ V_136 ] == V_70 [ V_21 ] ) ) {
V_73 = V_74 ;
break;
}
V_135 = F_67 ( V_123 , V_21 , V_70 [ V_21 ] , V_73 ) ;
if ( V_135 )
goto V_166;
}
F_36 ( & V_132 -> V_80 , L_13 , V_21 ) ;
V_135 = F_92 ( V_132 -> V_80 . V_165 ,
F_75 , V_123 ) ;
if ( V_135 ) {
F_39 ( & V_132 -> V_80 , L_14 ) ;
goto V_166;
}
V_135 = F_93 ( & V_123 -> V_11 ) ;
if ( V_135 ) {
F_39 ( & V_132 -> V_80 ,
L_15 , V_135 ) ;
goto V_166;
}
F_36 ( & V_132 -> V_80 , L_16 ) ;
return 0 ;
V_166:
F_72 ( V_123 ) ;
return V_135 ;
}
static int F_94 ( struct V_131 * V_132 )
{
struct V_8 * V_123 = F_95 ( V_132 ) ;
F_96 ( & V_123 -> V_11 ) ;
F_72 ( V_123 ) ;
return 0 ;
}
