static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
static inline struct V_8 *
F_4 ( struct V_6 * V_7 )
{
return F_2 ( F_3 ( V_7 ) ,
struct V_8 , V_4 ) ;
}
static inline struct V_9 *
F_5 ( struct V_6 * V_7 )
{
return F_2 ( F_3 ( V_7 ) ,
struct V_9 , V_4 ) ;
}
static bool F_6 ( struct V_10 * V_11 , T_1 V_12 )
{
V_11 -> V_13 |= V_12 & V_14 ;
V_11 -> V_15 ^= V_12 & V_11 -> V_15 ;
return ! V_11 -> V_15 || V_11 -> V_13 ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_9 * V_18 = V_17 ;
T_1 V_19 , V_20 ;
bool V_21 ;
F_8 ( V_18 -> V_4 . V_22 , V_23 , & V_19 ) ;
V_20 = V_19 & ( V_18 -> V_11 . V_15 | V_14 ) ;
V_21 = F_6 ( & V_18 -> V_11 , V_19 ) ;
if ( V_20 )
F_9 ( V_18 -> V_4 . V_22 , V_24 , V_20 ) ;
if ( V_21 )
F_10 ( & V_18 -> F_10 ) ;
return V_20 ? V_25 : V_26 ;
}
static int F_11 ( struct V_9 * V_18 , bool V_27 ,
unsigned int V_28 )
{
int V_29 ;
if ( ! V_28 )
V_28 = V_30 ;
if ( V_27 ) {
T_1 V_12 ;
V_29 = F_12 ( V_18 -> V_4 . V_22 ,
V_23 , V_12 ,
F_6 ( & V_18 -> V_11 ,
V_12 ) ,
0 , V_28 * 1000 ) ;
} else {
F_13 ( & V_18 -> F_10 ) ;
F_9 ( V_18 -> V_4 . V_22 , V_31 ,
V_18 -> V_11 . V_15 | V_14 ) ;
V_29 = F_14 ( & V_18 -> F_10 ,
F_15 ( V_28 ) ) ;
if ( ! V_29 )
V_29 = - V_32 ;
else
V_29 = 0 ;
F_9 ( V_18 -> V_4 . V_22 , V_24 , 0xffffffff ) ;
}
if ( V_18 -> V_11 . V_13 & V_33 ) {
F_16 ( V_18 -> V_4 . V_34 , L_1 ) ;
V_29 = - V_32 ;
}
if ( V_18 -> V_11 . V_13 & V_35 ) {
F_16 ( V_18 -> V_4 . V_34 , L_2 ) ;
V_29 = - V_36 ;
}
if ( V_18 -> V_11 . V_13 & V_37 ) {
F_16 ( V_18 -> V_4 . V_34 , L_3 ) ;
V_29 = - V_36 ;
}
if ( V_18 -> V_11 . V_13 & V_38 ) {
F_16 ( V_18 -> V_4 . V_34 , L_4 ) ;
V_29 = - V_36 ;
}
return V_29 ;
}
static void F_17 ( void * V_17 )
{
struct V_39 * V_40 = V_17 ;
F_10 ( V_40 ) ;
}
static int F_18 ( struct V_5 * V_18 ,
void * V_41 , T_3 V_42 , T_4 V_43 ,
enum V_44 V_45 )
{
F_19 ( V_40 ) ;
T_3 V_46 , V_47 , V_48 ;
struct V_49 * V_50 ;
T_5 V_51 ;
V_48 = F_20 ( V_18 -> V_34 , V_41 , V_43 , V_45 ) ;
if ( F_21 ( V_18 -> V_34 , V_42 ) ) {
F_16 ( V_18 -> V_34 ,
L_5 ) ;
goto V_52;
}
if ( V_45 == V_53 ) {
V_46 = V_42 ;
V_47 = V_48 ;
} else {
V_46 = V_48 ;
V_47 = V_42 ;
}
V_50 = F_22 ( V_18 -> V_54 , V_47 , V_46 , V_43 ,
V_55 | V_56 ) ;
if ( ! V_50 ) {
F_16 ( V_18 -> V_34 , L_6 ) ;
goto V_57;
}
V_50 -> V_58 = F_17 ;
V_50 -> V_59 = & V_40 ;
V_51 = F_23 ( V_50 ) ;
if ( F_24 ( V_51 ) ) {
F_16 ( V_18 -> V_34 , L_7 ) ;
goto V_57;
}
F_25 ( V_18 -> V_54 ) ;
F_26 ( & V_40 ) ;
return 0 ;
V_57:
F_27 ( V_18 -> V_34 , V_48 , V_43 , V_45 ) ;
V_52:
F_28 ( V_18 -> V_34 , L_8 ) ;
return - V_36 ;
}
static T_6 F_29 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
return F_31 ( V_62 -> V_63 -> V_64 . V_65 ) ;
}
static T_7 F_32 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
return F_33 ( V_62 -> V_63 -> V_64 . V_65 ) ;
}
static void F_34 ( struct V_60 * V_61 , T_6 V_66 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( V_3 -> V_67 & V_68 )
F_35 ( V_66 | ( V_66 << 8 ) , V_62 -> V_63 -> V_64 . V_65 ) ;
else
F_36 ( V_66 , V_62 -> V_63 -> V_64 . V_65 ) ;
}
static void F_37 ( struct V_60 * V_61 , T_6 * V_41 , int V_43 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_18 -> V_54 && F_38 ( V_41 ) &&
V_43 >= V_70 &&
! F_18 ( V_18 , V_41 , V_62 -> V_63 -> V_64 . V_71 , V_43 ,
V_53 ) )
return;
if ( V_3 -> V_67 & V_68 )
F_39 ( V_62 -> V_63 -> V_64 . V_65 , V_41 , V_43 / 2 ) ;
else
F_40 ( V_62 -> V_63 -> V_64 . V_65 , V_41 , V_43 ) ;
}
static void F_41 ( struct V_60 * V_61 , const T_6 * V_41 , int V_43 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_18 -> V_54 && F_38 ( V_41 ) &&
V_43 >= V_70 &&
! F_18 ( V_18 , ( void * ) V_41 , V_62 -> V_63 -> V_64 . V_71 ,
V_43 , V_72 ) )
return;
if ( V_3 -> V_67 & V_68 )
F_42 ( V_62 -> V_63 -> V_64 . V_65 , V_41 , V_43 / 2 ) ;
else
F_43 ( V_62 -> V_63 -> V_64 . V_65 , V_41 , V_43 ) ;
}
static int F_44 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
return F_45 ( V_62 -> V_63 -> V_73 . V_74 ) ;
}
static void F_46 ( struct V_60 * V_61 , int V_75 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( V_75 < 0 || V_75 >= V_62 -> V_76 ) {
V_62 -> V_63 = NULL ;
V_3 -> V_77 = NULL ;
return;
}
V_62 -> V_63 = & V_62 -> V_75 [ V_75 ] ;
if ( V_62 -> V_63 -> V_73 . type == V_78 )
V_3 -> V_77 = F_44 ;
}
static int F_47 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_9 * V_18 ;
T_1 V_12 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
F_8 ( V_18 -> V_4 . V_22 , V_23 , & V_12 ) ;
return V_12 & F_48 ( V_62 -> V_63 -> V_73 . V_79 ) ;
}
static void F_49 ( struct V_60 * V_61 , int V_75 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_9 * V_18 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
F_46 ( V_61 , V_75 ) ;
if ( ! V_62 -> V_63 ) {
F_9 ( V_18 -> V_4 . V_22 , V_80 ,
V_81 ) ;
return;
}
if ( V_62 -> V_63 -> V_73 . type == V_82 )
V_3 -> V_77 = F_47 ;
F_50 ( V_18 -> V_4 . V_22 , V_83 ,
V_84 |
V_85 |
V_86 |
V_87 ,
F_51 ( V_61 -> V_88 ) |
F_52 ( V_61 -> V_89 ) |
V_86 ) ;
F_9 ( V_18 -> V_4 . V_22 , V_80 ,
V_90 ) ;
}
static int F_53 ( struct V_9 * V_18 , bool V_27 )
{
T_6 * V_91 = V_18 -> V_11 . V_91 ;
unsigned int V_11 = 0 ;
T_1 V_92 , V_93 ;
int V_94 , V_29 ;
V_18 -> V_11 . V_15 = V_95 ;
for ( V_94 = 0 ; V_94 < V_18 -> V_11 . V_96 ; V_94 ++ )
V_11 |= F_54 ( V_94 , V_18 -> V_11 . V_97 [ V_94 ] ) ;
if ( V_18 -> V_11 . V_98 == V_99 )
F_9 ( V_18 -> V_4 . V_22 , V_100 , * V_91 ++ ) ;
V_11 |= F_55 ( V_18 -> V_11 . V_75 ) |
F_56 ( V_18 -> V_11 . V_98 ) ;
if ( V_18 -> V_11 . V_96 > 1 )
V_11 |= V_101 ;
V_92 = V_91 [ 0 ] | ( V_91 [ 1 ] << 8 ) | ( V_91 [ 2 ] << 16 ) |
( V_91 [ 3 ] << 24 ) ;
if ( V_18 -> V_11 . V_17 != V_102 ) {
V_11 |= V_103 ;
V_18 -> V_11 . V_15 |= V_104 ;
if ( V_18 -> V_11 . V_17 == V_105 )
V_11 |= V_106 ;
}
F_8 ( V_18 -> V_4 . V_22 , V_23 , & V_93 ) ;
F_9 ( V_18 -> V_64 , V_11 , V_92 ) ;
V_29 = F_11 ( V_18 , V_27 , 0 ) ;
if ( V_29 )
F_16 ( V_18 -> V_4 . V_34 ,
L_9 ,
V_29 ) ;
memset ( & V_18 -> V_11 , 0 , sizeof( V_18 -> V_11 ) ) ;
return V_29 ;
}
static void F_57 ( struct V_60 * V_61 , int V_107 ,
unsigned int V_108 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_9 * V_18 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
if ( V_108 & V_109 ) {
if ( V_18 -> V_11 . V_98 == V_99 )
return;
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_107 ;
} else if ( V_108 & V_110 ) {
if ( V_18 -> V_11 . V_96 > 1 )
return;
V_18 -> V_11 . V_97 [ V_18 -> V_11 . V_96 ++ ] = V_107 ;
}
if ( V_107 == V_111 ) {
V_18 -> V_11 . V_75 = V_62 -> V_63 -> V_79 ;
F_53 ( V_18 , true ) ;
}
}
static void F_58 ( struct V_60 * V_61 , int V_112 ,
unsigned int V_108 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( ( V_108 & V_113 ) && V_62 -> V_63 -> V_114 ) {
if ( V_108 & V_115 )
F_59 ( V_62 -> V_63 -> V_114 , 0 ) ;
else
F_59 ( V_62 -> V_63 -> V_114 , 1 ) ;
}
if ( V_108 & V_109 )
F_60 ( V_112 , V_62 -> V_63 -> V_64 . V_65 + V_18 -> V_116 -> V_117 ) ;
else if ( V_108 & V_110 )
F_60 ( V_112 , V_62 -> V_63 -> V_64 . V_65 + V_18 -> V_116 -> V_118 ) ;
}
static void F_61 ( struct V_2 * V_3 , const T_6 * V_41 ,
bool V_119 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_9 * V_18 ;
int V_29 = - V_36 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
if ( V_18 -> V_4 . V_54 )
V_29 = F_18 ( & V_18 -> V_4 , ( void * ) V_41 ,
V_18 -> V_120 . V_71 , V_61 -> V_88 ,
V_72 ) ;
if ( V_29 )
F_63 ( V_18 -> V_120 . V_65 , V_41 , V_61 -> V_88 ) ;
if ( V_119 )
F_63 ( V_18 -> V_120 . V_65 + V_61 -> V_88 , V_3 -> V_121 ,
V_61 -> V_89 ) ;
}
static void F_64 ( struct V_2 * V_3 , T_6 * V_41 ,
bool V_119 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_9 * V_18 ;
int V_29 = - V_36 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
if ( V_18 -> V_4 . V_54 )
V_29 = F_18 ( & V_18 -> V_4 , V_41 , V_18 -> V_120 . V_71 ,
V_61 -> V_88 , V_53 ) ;
if ( V_29 )
F_65 ( V_41 , V_18 -> V_120 . V_65 , V_61 -> V_88 ) ;
if ( V_119 )
F_65 ( V_3 -> V_121 , V_18 -> V_120 . V_65 + V_61 -> V_88 ,
V_61 -> V_89 ) ;
}
static void F_66 ( struct V_2 * V_3 , int V_122 , int V_123 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_9 * V_18 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
if ( V_123 >= 0 ) {
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_123 ;
if ( V_61 -> V_88 > 512 )
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_123 >> 8 ;
}
if ( V_122 >= 0 ) {
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_122 ;
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_122 >> 8 ;
if ( ( V_61 -> V_88 > 512 && V_3 -> V_124 > V_125 ) ||
( V_61 -> V_88 <= 512 && V_3 -> V_124 > V_126 ) )
V_18 -> V_11 . V_91 [ V_18 -> V_11 . V_98 ++ ] = V_122 >> 16 ;
}
}
static int F_67 ( struct V_2 * V_3 , int V_11 , bool V_127 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_127 )
return 0 ;
V_29 = F_68 ( V_62 -> V_128 , V_11 ) ;
if ( V_29 )
F_16 ( V_18 -> V_34 ,
L_10 , V_29 ) ;
return V_29 ;
}
static void F_69 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
if ( ! V_127 )
F_70 ( V_62 -> V_128 ) ;
}
static int F_71 ( struct V_2 * V_3 , bool V_127 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
struct V_129 V_130 ;
void * V_131 ;
int V_29 , V_94 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_127 )
return 0 ;
V_29 = F_72 ( V_62 -> V_128 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 ,
L_11 ,
V_29 ) ;
return V_29 ;
}
F_73 ( V_61 , 0 , & V_130 ) ;
V_131 = V_3 -> V_121 + V_130 . V_132 ;
for ( V_94 = 0 ; V_94 < V_3 -> V_133 . V_134 ; V_94 ++ ) {
F_74 ( V_62 -> V_128 , V_94 ,
V_131 ) ;
V_131 += V_3 -> V_133 . V_135 ;
}
return 0 ;
}
static int F_75 ( struct V_2 * V_3 , void * V_41 ,
bool V_127 )
{
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
struct V_129 V_130 ;
int V_29 , V_94 , V_136 = 0 ;
void * V_137 , * V_131 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_127 )
return 0 ;
V_29 = F_72 ( V_62 -> V_128 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 ,
L_12 ,
V_29 ) ;
return V_29 ;
}
F_73 ( V_61 , 0 , & V_130 ) ;
V_131 = V_3 -> V_121 + V_130 . V_132 ;
V_137 = V_41 ;
for ( V_94 = 0 ; V_94 < V_3 -> V_133 . V_134 ; V_94 ++ ) {
V_29 = F_76 ( V_62 -> V_128 , V_94 , V_137 ,
V_131 ) ;
if ( V_29 < 0 && ! F_77 ( V_62 -> V_128 ) )
V_29 = F_78 ( V_137 ,
V_3 -> V_133 . V_138 ,
V_131 ,
V_3 -> V_133 . V_135 ,
NULL , 0 ,
V_3 -> V_133 . V_139 ) ;
if ( V_29 >= 0 )
V_136 = F_79 ( V_29 , V_136 ) ;
else
V_61 -> V_140 . V_141 ++ ;
V_137 += V_3 -> V_133 . V_138 ;
V_131 += V_3 -> V_133 . V_135 ;
}
return V_136 ;
}
static int F_80 ( struct V_2 * V_3 , const T_6 * V_41 ,
bool V_119 , int V_122 , bool V_127 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
int V_29 ;
V_29 = F_67 ( V_3 , V_142 , V_127 ) ;
if ( V_29 )
return V_29 ;
F_41 ( V_61 , V_41 , V_61 -> V_88 ) ;
V_29 = F_71 ( V_3 , V_127 ) ;
if ( V_29 ) {
F_70 ( V_62 -> V_128 ) ;
return V_29 ;
}
F_69 ( V_3 , V_127 ) ;
F_41 ( V_61 , V_3 -> V_121 , V_61 -> V_89 ) ;
return 0 ;
}
static int F_81 ( struct V_60 * V_61 ,
struct V_2 * V_3 , const T_6 * V_41 ,
int V_119 , int V_122 )
{
return F_80 ( V_3 , V_41 , V_119 , V_122 , false ) ;
}
static int F_82 ( struct V_60 * V_61 ,
struct V_2 * V_3 ,
const T_6 * V_41 , int V_119 ,
int V_122 )
{
return F_80 ( V_3 , V_41 , V_119 , V_122 , true ) ;
}
static int F_83 ( struct V_2 * V_3 , T_6 * V_41 ,
bool V_119 , int V_122 , bool V_127 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
int V_29 ;
V_29 = F_67 ( V_3 , V_143 , V_127 ) ;
if ( V_29 )
return V_29 ;
F_37 ( V_61 , V_41 , V_61 -> V_88 ) ;
F_37 ( V_61 , V_3 -> V_121 , V_61 -> V_89 ) ;
V_29 = F_75 ( V_3 , V_41 , V_127 ) ;
F_69 ( V_3 , V_127 ) ;
return V_29 ;
}
static int F_84 ( struct V_60 * V_61 ,
struct V_2 * V_3 , T_6 * V_41 ,
int V_119 , int V_122 )
{
return F_83 ( V_3 , V_41 , V_119 , V_122 , false ) ;
}
static int F_85 ( struct V_60 * V_61 ,
struct V_2 * V_3 , T_6 * V_41 ,
int V_119 , int V_122 )
{
return F_83 ( V_3 , V_41 , V_119 , V_122 , true ) ;
}
static int F_86 ( struct V_2 * V_3 ,
const T_6 * V_41 , bool V_119 ,
int V_122 , bool V_127 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_9 * V_18 ;
int V_29 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
F_61 ( V_3 , V_41 , false ) ;
V_18 -> V_11 . V_97 [ 0 ] = V_144 ;
V_18 -> V_11 . V_96 = 1 ;
F_66 ( V_3 , V_122 , 0x0 ) ;
V_18 -> V_11 . V_75 = V_62 -> V_63 -> V_79 ;
V_18 -> V_11 . V_17 = V_105 ;
V_29 = F_67 ( V_3 , V_142 , V_127 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_53 ( V_18 , false ) ;
if ( V_29 ) {
F_69 ( V_3 , V_127 ) ;
F_16 ( V_18 -> V_4 . V_34 ,
L_11 ,
V_29 ) ;
return V_29 ;
}
V_29 = F_71 ( V_3 , V_127 ) ;
F_69 ( V_3 , V_127 ) ;
if ( V_29 )
return V_29 ;
F_41 ( V_61 , V_3 -> V_121 , V_61 -> V_89 ) ;
V_18 -> V_11 . V_97 [ 0 ] = V_145 ;
V_18 -> V_11 . V_96 = 1 ;
V_18 -> V_11 . V_75 = V_62 -> V_63 -> V_79 ;
V_29 = F_53 ( V_18 , false ) ;
if ( V_29 )
F_16 ( V_18 -> V_4 . V_34 , L_13 ,
V_29 ) ;
return V_29 ;
}
static int F_87 ( struct V_60 * V_61 ,
struct V_2 * V_3 ,
const T_6 * V_41 , int V_119 ,
int V_122 )
{
return F_86 ( V_3 , V_41 , V_119 , V_122 ,
false ) ;
}
static int F_88 ( struct V_60 * V_61 ,
struct V_2 * V_3 ,
const T_6 * V_41 ,
int V_119 , int V_122 )
{
return F_86 ( V_3 , V_41 , V_119 , V_122 ,
true ) ;
}
static int F_89 ( struct V_2 * V_3 , T_6 * V_41 ,
bool V_119 , int V_122 ,
bool V_127 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_9 * V_18 ;
int V_29 ;
V_18 = F_5 ( V_3 -> V_69 ) ;
if ( V_62 -> V_63 -> V_73 . type != V_82 ) {
V_3 -> V_146 ( V_61 , V_147 , 0x00 , V_122 ) ;
return F_83 ( V_3 , V_41 , V_119 , V_122 ,
V_127 ) ;
}
V_18 -> V_11 . V_97 [ V_18 -> V_11 . V_96 ++ ] = V_147 ;
if ( V_61 -> V_88 > 512 )
V_18 -> V_11 . V_97 [ V_18 -> V_11 . V_96 ++ ] = V_148 ;
F_66 ( V_3 , V_122 , 0x0 ) ;
V_18 -> V_11 . V_75 = V_62 -> V_63 -> V_79 ;
V_18 -> V_11 . V_17 = V_149 ;
V_29 = F_67 ( V_3 , V_143 , V_127 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_53 ( V_18 , false ) ;
if ( V_29 ) {
F_69 ( V_3 , V_127 ) ;
F_16 ( V_18 -> V_4 . V_34 ,
L_14 ,
V_29 ) ;
return V_29 ;
}
F_64 ( V_3 , V_41 , true ) ;
V_29 = F_75 ( V_3 , V_41 , V_127 ) ;
F_69 ( V_3 , V_127 ) ;
return V_29 ;
}
static int F_90 ( struct V_60 * V_61 ,
struct V_2 * V_3 , T_6 * V_41 ,
int V_119 , int V_122 )
{
return F_89 ( V_3 , V_41 , V_119 , V_122 ,
false ) ;
}
static int F_91 ( struct V_60 * V_61 ,
struct V_2 * V_3 ,
T_6 * V_41 , int V_119 ,
int V_122 )
{
return F_89 ( V_3 , V_41 , V_119 , V_122 ,
true ) ;
}
static int F_92 ( struct V_2 * V_3 )
{
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
struct V_150 V_151 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( ! V_18 -> V_128 ) {
F_16 ( V_18 -> V_34 , L_15 ) ;
return - V_152 ;
}
if ( V_18 -> V_116 -> V_153 ) {
T_1 V_93 ;
if ( ! F_93 ( V_18 -> V_34 -> V_154 , L_16 ,
& V_93 ) )
V_3 -> V_133 . V_139 = V_93 ;
if ( ! F_93 ( V_18 -> V_34 -> V_154 ,
L_17 ,
& V_93 ) )
V_3 -> V_133 . V_138 = V_93 ;
}
if ( V_3 -> V_133 . V_67 & V_155 )
V_151 . V_133 . V_139 = V_156 ;
else if ( V_3 -> V_133 . V_139 )
V_151 . V_133 . V_139 = V_3 -> V_133 . V_139 ;
else if ( V_3 -> V_157 )
V_151 . V_133 . V_139 = V_3 -> V_157 ;
else
V_151 . V_133 . V_139 = V_156 ;
if ( V_3 -> V_133 . V_138 )
V_151 . V_133 . V_158 = V_3 -> V_133 . V_138 ;
else if ( V_3 -> V_159 )
V_151 . V_133 . V_158 = V_3 -> V_159 ;
else
V_151 . V_133 . V_158 = V_160 ;
V_151 . V_161 = V_61 -> V_88 ;
V_151 . V_89 = V_61 -> V_89 ;
if ( V_61 -> V_88 <= 512 ) {
V_151 . V_133 . V_135 = 4 ;
V_151 . V_133 . V_162 = 0 ;
} else {
V_151 . V_133 . V_135 = V_61 -> V_89 - 2 ;
V_151 . V_133 . V_162 = V_163 ;
}
V_62 -> V_128 = F_94 ( V_18 -> V_128 , & V_151 ) ;
if ( F_95 ( V_62 -> V_128 ) )
return F_96 ( V_62 -> V_128 ) ;
V_3 -> V_133 . V_164 = V_165 ;
V_3 -> V_133 . V_138 = V_151 . V_133 . V_158 ;
V_3 -> V_133 . V_135 = V_151 . V_133 . V_135 / V_151 . V_133 . V_166 ;
V_3 -> V_133 . V_139 = V_151 . V_133 . V_139 ;
V_3 -> V_67 |= V_167 ;
F_97 ( V_61 , & V_168 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
switch ( V_3 -> V_133 . V_169 ) {
case V_170 :
case V_171 :
break;
case V_172 :
V_29 = F_92 ( V_3 ) ;
if ( V_29 )
return V_29 ;
V_3 -> V_133 . V_173 = F_84 ;
V_3 -> V_133 . V_174 = F_81 ;
V_3 -> V_133 . V_175 = F_85 ;
V_3 -> V_133 . V_176 = F_82 ;
break;
default:
F_16 ( V_18 -> V_34 , L_18 ,
V_3 -> V_133 . V_169 ) ;
return - V_152 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
int V_29 ;
V_29 = F_98 ( V_62 ) ;
if ( V_29 )
return V_29 ;
if ( V_3 -> V_133 . V_169 != V_172 )
return 0 ;
V_3 -> V_133 . V_173 = F_90 ;
V_3 -> V_133 . V_174 = F_87 ;
V_3 -> V_133 . V_175 = F_91 ;
V_3 -> V_133 . V_176 = F_88 ;
V_3 -> V_133 . V_67 |= V_177 ;
return 0 ;
}
static void F_100 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
V_61 -> V_34 . V_178 = V_18 -> V_34 ;
V_62 -> V_4 . V_69 = & V_18 -> V_4 ;
V_3 -> V_179 = F_58 ;
V_3 -> V_180 = F_29 ;
V_3 -> V_181 = F_32 ;
V_3 -> V_182 = F_34 ;
V_3 -> V_183 = F_37 ;
V_3 -> V_184 = F_41 ;
V_3 -> V_185 = F_46 ;
V_3 -> V_186 = 40 ;
if ( V_18 -> V_54 )
V_3 -> V_67 |= V_187 ;
if ( V_18 -> V_128 )
V_3 -> V_133 . V_169 = V_172 ;
}
static void F_101 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_8 * V_188 ;
int V_94 ;
F_100 ( V_18 , V_62 ) ;
V_188 = F_4 ( V_3 -> V_69 ) ;
if ( ! V_188 -> V_189 )
return;
for ( V_94 = 0 ; V_94 < V_62 -> V_76 ; V_94 ++ )
F_50 ( V_188 -> V_189 , V_188 -> V_190 ,
F_102 ( V_62 -> V_75 [ V_94 ] . V_79 ) , F_102 ( V_62 -> V_75 [ V_94 ] . V_79 ) ) ;
}
static void F_103 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
F_100 ( V_18 , V_62 ) ;
V_3 -> V_179 = F_57 ;
V_3 -> V_185 = F_49 ;
}
static int F_104 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
V_29 = F_105 ( V_61 , V_62 -> V_76 , NULL ) ;
if ( V_29 )
F_16 ( V_18 -> V_34 , L_19 , V_29 ) ;
return V_29 ;
}
static int F_106 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
int V_29 ;
V_29 = F_107 ( V_61 ) ;
if ( V_29 )
return V_29 ;
F_108 ( V_3 ) ;
F_109 ( & V_62 -> V_191 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_18 -> V_116 -> V_153 || ! V_18 -> V_34 -> V_154 ) {
V_61 -> V_192 = L_20 ;
} else if ( ! V_61 -> V_192 ) {
V_61 -> V_192 = F_111 ( V_18 -> V_34 , V_193 ,
L_21 , F_112 ( V_18 -> V_34 ) ,
V_62 -> V_75 [ 0 ] . V_79 ) ;
if ( ! V_61 -> V_192 ) {
F_16 ( V_18 -> V_34 , L_22 ) ;
return - V_194 ;
}
}
V_29 = F_113 ( V_61 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_23 , V_29 ) ;
return V_29 ;
}
V_29 = F_114 ( V_61 , NULL , 0 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_24 , V_29 ) ;
F_108 ( V_3 ) ;
return V_29 ;
}
F_115 ( & V_62 -> V_191 , & V_18 -> V_195 ) ;
return 0 ;
}
static struct V_1 * F_116 ( struct V_5 * V_18 ,
struct V_196 * V_197 ,
int V_198 )
{
struct V_1 * V_62 ;
struct V_199 * V_74 ;
int V_76 , V_29 , V_94 ;
V_76 = F_117 ( V_197 , L_25 ,
V_198 * sizeof( T_1 ) ) ;
if ( V_76 < 1 ) {
F_16 ( V_18 -> V_34 , L_26 ) ;
return F_118 ( - V_200 ) ;
}
V_62 = F_119 ( V_18 -> V_34 ,
sizeof( * V_62 ) + ( V_76 * sizeof( * V_62 -> V_75 ) ) ,
V_193 ) ;
if ( ! V_62 ) {
F_16 ( V_18 -> V_34 , L_27 ) ;
return F_118 ( - V_194 ) ;
}
V_62 -> V_76 = V_76 ;
V_74 = F_120 ( V_18 -> V_34 , L_28 , 0 ,
& V_197 -> V_201 , V_202 ,
L_29 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_203 ) {
F_16 ( V_18 -> V_34 ,
L_30 ,
F_96 ( V_74 ) ) ;
return F_121 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) )
V_62 -> V_204 = V_74 ;
for ( V_94 = 0 ; V_94 < V_76 ; V_94 ++ ) {
struct V_205 V_206 ;
T_1 V_93 ;
V_29 = F_122 ( V_197 , 0 , & V_206 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_31 ,
V_29 ) ;
return F_118 ( V_29 ) ;
}
V_29 = F_123 ( V_197 , L_25 , V_94 * V_198 ,
& V_93 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_31 ,
V_29 ) ;
return F_118 ( V_29 ) ;
}
V_62 -> V_75 [ V_94 ] . V_79 = V_93 ;
V_62 -> V_75 [ V_94 ] . V_64 . V_71 = V_206 . V_207 ;
V_62 -> V_75 [ V_94 ] . V_64 . V_65 = F_124 ( V_18 -> V_34 , & V_206 ) ;
if ( F_95 ( V_62 -> V_75 [ V_94 ] . V_64 . V_65 ) )
return F_121 ( V_62 -> V_75 [ V_94 ] . V_64 . V_65 ) ;
if ( ! F_93 ( V_197 , L_32 , & V_93 ) ) {
if ( V_93 > V_208 )
return F_118 ( - V_200 ) ;
V_62 -> V_75 [ V_94 ] . V_73 . type = V_82 ;
V_62 -> V_75 [ V_94 ] . V_73 . V_79 = V_93 ;
} else {
V_74 = F_120 ( V_18 -> V_34 ,
L_33 , V_94 , & V_197 -> V_201 ,
V_202 , L_34 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_203 ) {
F_16 ( V_18 -> V_34 ,
L_35 ,
F_96 ( V_74 ) ) ;
return F_121 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) ) {
V_62 -> V_75 [ V_94 ] . V_73 . type = V_78 ;
V_62 -> V_75 [ V_94 ] . V_73 . V_74 = V_74 ;
}
}
V_74 = F_120 ( V_18 -> V_34 , L_36 ,
V_94 , & V_197 -> V_201 ,
V_209 ,
L_37 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_203 ) {
F_16 ( V_18 -> V_34 ,
L_38 ,
F_96 ( V_74 ) ) ;
return F_121 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) )
V_62 -> V_75 [ V_94 ] . V_114 = V_74 ;
}
F_125 ( & V_62 -> V_4 , V_197 ) ;
return V_62 ;
}
static int
F_126 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
int V_29 ;
if ( V_62 -> V_204 && F_45 ( V_62 -> V_204 ) ) {
F_127 ( V_18 -> V_34 , L_39 ) ;
return 0 ;
}
V_18 -> V_116 -> V_210 -> V_211 ( V_18 , V_62 ) ;
V_29 = F_104 ( V_62 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_18 -> V_116 -> V_210 -> V_212 ( V_62 ) ;
if ( V_29 )
return V_29 ;
return F_110 ( V_62 ) ;
}
static int
F_128 ( struct V_5 * V_18 )
{
struct V_1 * V_62 , * V_213 ;
int V_29 ;
F_129 (nand, tmp, &nc->chips, node) {
V_29 = F_106 ( V_62 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_130 ( struct V_5 * V_18 )
{
struct V_214 * V_34 = V_18 -> V_34 ;
struct V_215 * V_216 = F_131 ( V_34 ) ;
struct V_1 * V_62 ;
struct V_199 * V_74 ;
struct V_205 * V_206 ;
V_62 = F_119 ( V_18 -> V_34 , sizeof( * V_62 ) + sizeof( * V_62 -> V_75 ) ,
V_193 ) ;
if ( ! V_62 )
return - V_194 ;
V_62 -> V_76 = 1 ;
V_206 = F_132 ( V_216 , V_217 , 0 ) ;
V_62 -> V_75 [ 0 ] . V_64 . V_65 = F_124 ( V_34 , V_206 ) ;
if ( F_95 ( V_62 -> V_75 [ 0 ] . V_64 . V_65 ) )
return F_96 ( V_62 -> V_75 [ 0 ] . V_64 . V_65 ) ;
V_62 -> V_75 [ 0 ] . V_64 . V_71 = V_206 -> V_207 ;
V_62 -> V_75 [ 0 ] . V_79 = 3 ;
V_74 = F_133 ( V_34 , NULL , 0 , V_202 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 , L_35 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
if ( V_74 ) {
V_62 -> V_75 [ 0 ] . V_73 . type = V_78 ;
V_62 -> V_75 [ 0 ] . V_73 . V_74 = V_74 ;
}
V_74 = F_133 ( V_34 , NULL , 1 , V_209 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 , L_38 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
V_62 -> V_75 [ 0 ] . V_114 = V_74 ;
V_74 = F_133 ( V_18 -> V_34 , NULL , 2 , V_202 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 ,
L_30 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
V_62 -> V_204 = V_74 ;
F_125 ( & V_62 -> V_4 , V_18 -> V_34 -> V_154 ) ;
return F_126 ( V_18 , V_62 ) ;
}
static int F_134 ( struct V_5 * V_18 )
{
struct V_196 * V_197 , * V_218 ;
struct V_214 * V_34 = V_18 -> V_34 ;
int V_29 , V_198 ;
T_1 V_93 ;
if ( V_18 -> V_116 -> V_153 )
return F_130 ( V_18 ) ;
V_197 = V_34 -> V_154 ;
V_29 = F_93 ( V_197 , L_40 , & V_93 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_41 ) ;
return V_29 ;
}
V_198 = V_93 ;
V_29 = F_93 ( V_197 , L_42 , & V_93 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_41 ) ;
return V_29 ;
}
V_198 += V_93 ;
F_135 (np, nand_np) {
struct V_1 * V_62 ;
V_62 = F_116 ( V_18 , V_218 , V_198 ) ;
if ( F_95 ( V_62 ) ) {
V_29 = F_96 ( V_62 ) ;
goto V_52;
}
V_29 = F_126 ( V_18 , V_62 ) ;
if ( V_29 )
goto V_52;
}
return 0 ;
V_52:
F_128 ( V_18 ) ;
return V_29 ;
}
static void F_136 ( struct V_5 * V_18 )
{
if ( V_18 -> V_54 )
F_137 ( V_18 -> V_54 ) ;
F_138 ( V_18 -> V_219 ) ;
}
static int F_139 ( struct V_5 * V_18 ,
struct V_215 * V_216 ,
const struct V_220 * V_116 )
{
struct V_214 * V_34 = & V_216 -> V_34 ;
struct V_196 * V_197 = V_34 -> V_154 ;
int V_29 ;
F_140 ( & V_18 -> V_4 ) ;
F_141 ( & V_18 -> V_195 ) ;
V_18 -> V_34 = V_34 ;
V_18 -> V_116 = V_116 ;
F_142 ( V_216 , V_18 ) ;
V_18 -> V_128 = F_143 ( V_34 ) ;
if ( F_95 ( V_18 -> V_128 ) ) {
V_29 = F_96 ( V_18 -> V_128 ) ;
if ( V_29 != - V_221 )
F_16 ( V_34 , L_43 ,
V_29 ) ;
return V_29 ;
}
if ( V_18 -> V_116 -> V_222 ) {
T_8 V_223 ;
F_144 ( V_223 ) ;
F_145 ( V_224 , V_223 ) ;
V_18 -> V_54 = F_146 ( V_223 , NULL , NULL ) ;
if ( ! V_18 -> V_54 )
F_16 ( V_18 -> V_34 , L_44 ) ;
}
if ( V_18 -> V_116 -> V_153 )
return 0 ;
V_197 = F_147 ( V_34 -> V_178 -> V_154 , L_45 , 0 ) ;
if ( ! V_197 ) {
F_16 ( V_34 , L_46 ) ;
return - V_200 ;
}
V_18 -> V_22 = F_148 ( V_197 ) ;
F_149 ( V_197 ) ;
if ( F_95 ( V_18 -> V_22 ) ) {
V_29 = F_96 ( V_18 -> V_22 ) ;
F_16 ( V_34 , L_47 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static int
F_150 ( struct V_8 * V_18 )
{
struct V_214 * V_34 = V_18 -> V_4 . V_34 ;
const struct V_225 * V_226 ;
struct V_196 * V_197 ;
int V_29 ;
if ( V_18 -> V_4 . V_116 -> V_153 )
return 0 ;
V_197 = F_147 ( V_34 -> V_178 -> V_154 , L_48 , 0 ) ;
if ( ! V_197 )
return 0 ;
V_226 = F_151 ( V_227 , V_197 ) ;
if ( ! V_226 ) {
F_149 ( V_197 ) ;
return 0 ;
}
V_18 -> V_189 = F_148 ( V_197 ) ;
F_149 ( V_197 ) ;
if ( F_95 ( V_18 -> V_189 ) ) {
V_29 = F_96 ( V_18 -> V_189 ) ;
F_16 ( V_34 , L_49 , V_29 ) ;
return V_29 ;
}
V_18 -> V_190 = ( unsigned int ) V_226 -> V_17 ;
if ( F_152 ( V_34 -> V_178 -> V_154 ,
L_50 ) )
V_18 -> V_190 += 4 ;
return 0 ;
}
static int
F_153 ( struct V_9 * V_18 )
{
struct V_228 V_229 = {
. V_230 = 32 ,
. V_231 = 32 ,
. V_232 = 4 ,
} ;
struct V_214 * V_34 = V_18 -> V_4 . V_34 ;
struct V_196 * V_218 , * V_233 ;
void T_9 * V_234 ;
struct V_205 V_206 ;
int V_29 ;
V_218 = V_34 -> V_154 ;
V_233 = F_154 ( V_34 -> V_154 , NULL ,
L_51 ) ;
V_18 -> V_235 = F_155 ( V_233 , 0 ) ;
if ( F_95 ( V_18 -> V_235 ) ) {
V_29 = F_96 ( V_18 -> V_235 ) ;
F_16 ( V_34 , L_52 ,
V_29 ) ;
goto V_236;
}
V_29 = F_156 ( V_18 -> V_235 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_53 ,
V_29 ) ;
goto V_236;
}
V_18 -> V_16 = F_157 ( V_218 , 0 ) ;
if ( V_18 -> V_16 < 0 ) {
V_29 = V_18 -> V_16 ;
if ( V_29 != - V_221 )
F_16 ( V_34 , L_54 ,
V_29 ) ;
goto V_236;
}
V_29 = F_122 ( V_233 , 0 , & V_206 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_55 ,
V_29 ) ;
goto V_236;
}
V_234 = F_124 ( V_34 , & V_206 ) ;
if ( F_95 ( V_234 ) ) {
V_29 = F_96 ( V_234 ) ;
goto V_236;
}
V_229 . V_192 = L_56 ;
V_229 . V_237 = F_158 ( & V_206 ) - 4 ;
V_18 -> V_64 = F_159 ( V_34 , V_234 , & V_229 ) ;
if ( F_95 ( V_18 -> V_64 ) ) {
V_29 = F_96 ( V_18 -> V_64 ) ;
F_16 ( V_34 , L_57 ,
V_29 ) ;
goto V_236;
}
V_29 = F_122 ( V_233 , 1 , & V_206 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_58 ,
V_29 ) ;
goto V_236;
}
V_234 = F_124 ( V_34 , & V_206 ) ;
if ( F_95 ( V_234 ) ) {
V_29 = F_96 ( V_234 ) ;
goto V_236;
}
V_229 . V_192 = L_59 ;
V_229 . V_237 = F_158 ( & V_206 ) - 4 ;
V_18 -> V_4 . V_22 = F_159 ( V_34 , V_234 , & V_229 ) ;
if ( F_95 ( V_18 -> V_4 . V_22 ) ) {
V_29 = F_96 ( V_18 -> V_4 . V_22 ) ;
F_16 ( V_34 , L_57 ,
V_29 ) ;
goto V_236;
}
V_29 = F_122 ( V_233 , 2 , & V_206 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_60 ,
V_29 ) ;
goto V_236;
}
V_18 -> V_120 . V_65 = F_124 ( V_34 , & V_206 ) ;
if ( F_95 ( V_18 -> V_120 . V_65 ) ) {
V_29 = F_96 ( V_18 -> V_120 . V_65 ) ;
goto V_236;
}
V_18 -> V_120 . V_71 = V_206 . V_207 ;
V_236:
F_149 ( V_233 ) ;
return V_29 ;
}
static int
F_160 ( struct V_9 * V_18 )
{
struct V_214 * V_34 = V_18 -> V_4 . V_34 ;
struct V_196 * V_197 ;
int V_29 ;
V_197 = F_147 ( V_34 -> V_178 -> V_154 , L_45 , 0 ) ;
if ( ! V_197 ) {
F_16 ( V_34 , L_46 ) ;
return - V_200 ;
}
V_18 -> V_16 = F_157 ( V_197 , 0 ) ;
F_149 ( V_197 ) ;
if ( V_18 -> V_16 < 0 ) {
if ( V_18 -> V_16 != - V_221 )
F_16 ( V_34 , L_54 ,
V_18 -> V_16 ) ;
return V_18 -> V_16 ;
}
V_197 = F_147 ( V_34 -> V_154 , L_61 , 0 ) ;
if ( ! V_197 ) {
F_16 ( V_34 , L_62 ) ;
return - V_200 ;
}
V_18 -> V_64 = F_148 ( V_197 ) ;
F_149 ( V_197 ) ;
if ( F_95 ( V_18 -> V_64 ) ) {
V_29 = F_96 ( V_18 -> V_64 ) ;
F_16 ( V_34 , L_63 , V_29 ) ;
return V_29 ;
}
V_18 -> V_120 . V_238 = F_161 ( V_18 -> V_4 . V_34 -> V_154 ,
L_64 , 0 ) ;
if ( ! V_18 -> V_120 . V_238 ) {
F_16 ( V_18 -> V_4 . V_34 , L_65 ) ;
return - V_194 ;
}
V_18 -> V_120 . V_65 = F_162 ( V_18 -> V_120 . V_238 ,
V_239 ,
& V_18 -> V_120 . V_71 ) ;
if ( ! V_18 -> V_120 . V_65 ) {
F_16 ( V_18 -> V_4 . V_34 ,
L_66 ) ;
return - V_194 ;
}
return 0 ;
}
static int
F_163 ( struct V_5 * V_18 )
{
struct V_9 * V_240 ;
int V_29 ;
V_29 = F_128 ( V_18 ) ;
if ( V_29 )
return V_29 ;
V_240 = F_2 ( V_18 , struct V_9 , V_4 ) ;
if ( V_240 -> V_120 . V_238 )
F_164 ( V_240 -> V_120 . V_238 ,
( unsigned long ) V_240 -> V_120 . V_65 ,
V_239 ) ;
if ( V_240 -> V_235 ) {
F_165 ( V_240 -> V_235 ) ;
F_138 ( V_240 -> V_235 ) ;
}
F_136 ( V_18 ) ;
return 0 ;
}
static int F_166 ( struct V_215 * V_216 ,
const struct V_220 * V_116 )
{
struct V_214 * V_34 = & V_216 -> V_34 ;
struct V_9 * V_18 ;
int V_29 ;
V_18 = F_119 ( V_34 , sizeof( * V_18 ) , V_193 ) ;
if ( ! V_18 )
return - V_194 ;
V_29 = F_139 ( & V_18 -> V_4 , V_216 , V_116 ) ;
if ( V_29 )
return V_29 ;
if ( V_116 -> V_153 )
V_29 = F_153 ( V_18 ) ;
else
V_29 = F_160 ( V_18 ) ;
if ( V_29 )
return V_29 ;
F_9 ( V_18 -> V_4 . V_22 , V_24 , 0xffffffff ) ;
V_29 = F_167 ( V_34 , V_18 -> V_16 , F_7 ,
V_241 , L_67 , V_18 ) ;
if ( V_29 ) {
F_16 ( V_34 ,
L_68 ,
V_29 ) ;
goto V_52;
}
F_9 ( V_18 -> V_4 . V_22 , V_83 ,
V_242 ) ;
V_29 = F_134 ( & V_18 -> V_4 ) ;
if ( V_29 )
goto V_52;
return 0 ;
V_52:
F_163 ( & V_18 -> V_4 ) ;
return V_29 ;
}
static int F_168 ( struct V_215 * V_216 ,
const struct V_220 * V_116 )
{
struct V_214 * V_34 = & V_216 -> V_34 ;
struct V_8 * V_18 ;
int V_29 ;
V_18 = F_119 ( V_34 , sizeof( * V_18 ) , V_193 ) ;
if ( ! V_18 )
return - V_194 ;
V_29 = F_139 ( & V_18 -> V_4 , V_216 , V_116 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_150 ( V_18 ) ;
if ( V_29 )
return V_29 ;
return F_134 ( & V_18 -> V_4 ) ;
}
static int
F_169 ( struct V_5 * V_18 )
{
int V_29 ;
V_29 = F_128 ( V_18 ) ;
if ( V_29 )
return V_29 ;
F_136 ( V_18 ) ;
return 0 ;
}
static int F_170 ( struct V_215 * V_216 )
{
const struct V_220 * V_116 ;
if ( V_216 -> V_243 )
V_116 = ( void * ) V_216 -> V_243 -> V_244 ;
else
V_116 = F_171 ( & V_216 -> V_34 ) ;
if ( ! V_116 ) {
F_16 ( & V_216 -> V_34 , L_69 ) ;
return - V_200 ;
}
if ( V_116 -> V_153 ) {
T_1 V_117 = 21 ;
if ( F_154 ( V_216 -> V_34 . V_154 , NULL ,
L_51 ) )
V_116 = & V_245 ;
if ( ! V_116 -> V_222 &&
F_172 ( V_216 -> V_34 . V_154 ,
L_70 ) )
V_116 = & V_246 ;
F_93 ( V_216 -> V_34 . V_154 ,
L_71 , & V_117 ) ;
if ( V_117 != 21 )
V_116 = & V_247 ;
}
return V_116 -> V_210 -> V_248 ( V_216 , V_116 ) ;
}
static int F_173 ( struct V_215 * V_216 )
{
struct V_5 * V_18 = F_174 ( V_216 ) ;
return V_18 -> V_116 -> V_210 -> remove ( V_18 ) ;
}
