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
int V_29 , V_12 ;
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
V_12 = V_3 -> V_146 ( V_61 , V_3 ) ;
if ( V_12 & V_147 )
return - V_36 ;
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
V_3 -> V_148 ( V_61 , V_149 , 0x00 , V_122 ) ;
return F_83 ( V_3 , V_41 , V_119 , V_122 ,
V_127 ) ;
}
V_18 -> V_11 . V_97 [ V_18 -> V_11 . V_96 ++ ] = V_149 ;
if ( V_61 -> V_88 > 512 )
V_18 -> V_11 . V_97 [ V_18 -> V_11 . V_96 ++ ] = V_150 ;
F_66 ( V_3 , V_122 , 0x0 ) ;
V_18 -> V_11 . V_75 = V_62 -> V_63 -> V_79 ;
V_18 -> V_11 . V_17 = V_151 ;
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
struct V_152 V_153 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( ! V_18 -> V_128 ) {
F_16 ( V_18 -> V_34 , L_15 ) ;
return - V_154 ;
}
if ( V_18 -> V_116 -> V_155 ) {
T_1 V_93 ;
if ( ! F_93 ( V_18 -> V_34 -> V_156 , L_16 ,
& V_93 ) )
V_3 -> V_133 . V_139 = V_93 ;
if ( ! F_93 ( V_18 -> V_34 -> V_156 ,
L_17 ,
& V_93 ) )
V_3 -> V_133 . V_138 = V_93 ;
}
if ( V_3 -> V_133 . V_67 & V_157 )
V_153 . V_133 . V_139 = V_158 ;
else if ( V_3 -> V_133 . V_139 )
V_153 . V_133 . V_139 = V_3 -> V_133 . V_139 ;
else if ( V_3 -> V_159 )
V_153 . V_133 . V_139 = V_3 -> V_159 ;
else
V_153 . V_133 . V_139 = V_158 ;
if ( V_3 -> V_133 . V_138 )
V_153 . V_133 . V_160 = V_3 -> V_133 . V_138 ;
else if ( V_3 -> V_161 )
V_153 . V_133 . V_160 = V_3 -> V_161 ;
else
V_153 . V_133 . V_160 = V_162 ;
V_153 . V_163 = V_61 -> V_88 ;
V_153 . V_89 = V_61 -> V_89 ;
if ( V_61 -> V_88 <= 512 ) {
V_153 . V_133 . V_135 = 4 ;
V_153 . V_133 . V_164 = 0 ;
} else {
V_153 . V_133 . V_135 = V_61 -> V_89 - 2 ;
V_153 . V_133 . V_164 = V_165 ;
}
V_62 -> V_128 = F_94 ( V_18 -> V_128 , & V_153 ) ;
if ( F_95 ( V_62 -> V_128 ) )
return F_96 ( V_62 -> V_128 ) ;
V_3 -> V_133 . V_166 = V_167 ;
V_3 -> V_133 . V_138 = V_153 . V_133 . V_160 ;
V_3 -> V_133 . V_135 = V_153 . V_133 . V_135 / V_153 . V_133 . V_168 ;
V_3 -> V_133 . V_139 = V_153 . V_133 . V_139 ;
V_3 -> V_67 |= V_169 ;
F_97 ( V_61 , & V_170 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
switch ( V_3 -> V_133 . V_171 ) {
case V_172 :
case V_173 :
break;
case V_174 :
V_29 = F_92 ( V_3 ) ;
if ( V_29 )
return V_29 ;
V_3 -> V_133 . V_175 = F_84 ;
V_3 -> V_133 . V_176 = F_81 ;
V_3 -> V_133 . V_177 = F_85 ;
V_3 -> V_133 . V_178 = F_82 ;
break;
default:
F_16 ( V_18 -> V_34 , L_18 ,
V_3 -> V_133 . V_171 ) ;
return - V_154 ;
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
if ( V_3 -> V_133 . V_171 != V_174 )
return 0 ;
V_3 -> V_133 . V_175 = F_90 ;
V_3 -> V_133 . V_176 = F_87 ;
V_3 -> V_133 . V_177 = F_91 ;
V_3 -> V_133 . V_178 = F_88 ;
V_3 -> V_133 . V_67 |= V_179 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_62 ,
const struct V_180 * V_181 ,
struct V_182 * V_183 )
{
T_1 V_184 , V_185 , V_186 , V_187 ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_62 -> V_4 . V_69 ) ;
if ( V_181 -> type != V_188 )
return - V_154 ;
if ( V_181 -> V_189 . V_190 . V_191 < 30000 )
return - V_154 ;
F_101 ( V_183 ) ;
V_187 = V_192 / F_102 ( V_18 -> V_193 ) ;
V_187 *= 1000 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_194 , V_187 ) ;
V_185 = V_184 ;
V_29 = F_104 ( V_183 , V_195 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_186 = F_105 ( V_181 -> V_189 . V_190 . V_196 , V_181 -> V_189 . V_190 . V_197 ,
V_181 -> V_189 . V_190 . V_198 ) ;
V_186 = F_79 ( V_186 , V_181 -> V_189 . V_190 . V_199 ) ;
V_184 = F_103 ( V_186 , V_187 ) ;
V_184 = V_184 > V_185 ? V_184 - V_185 : 0 ;
V_185 += V_184 ;
V_29 = F_106 ( V_183 , V_195 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_186 = F_105 ( V_181 -> V_189 . V_190 . V_200 , V_181 -> V_189 . V_190 . V_201 ,
V_181 -> V_189 . V_190 . V_202 ) ;
V_186 = F_105 ( V_186 , V_181 -> V_189 . V_190 . V_203 ,
V_181 -> V_189 . V_190 . V_204 ) ;
V_184 = F_103 ( V_186 , V_187 ) ;
V_185 += V_184 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_205 , V_187 ) ;
V_184 = F_79 ( V_185 , V_184 ) ;
V_29 = F_107 ( V_183 , V_195 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_104 ( V_183 , V_206 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_186 = F_79 ( V_181 -> V_189 . V_190 . V_207 , V_181 -> V_189 . V_190 . V_208 ) ;
V_184 = F_103 ( V_186 , V_187 ) ;
V_185 = V_184 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_209 , V_187 ) ;
V_184 -= V_185 ;
if ( V_184 > V_210 )
V_184 = V_210 ;
else if ( V_184 < V_211 )
V_184 = V_211 ;
V_183 -> V_171 |= F_108 ( V_184 ) |
V_212 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_213 , V_187 ) ;
V_185 += V_184 ;
V_29 = F_104 ( V_183 , V_214 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_191 , V_187 ) ;
V_184 = F_79 ( V_185 , V_184 ) ;
V_29 = F_107 ( V_183 , V_214 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_104 ( V_183 , V_215 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_216 , V_187 ) ;
V_29 = F_109 ( V_183 ,
V_217 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_218 , V_187 ) ;
V_29 = F_109 ( V_183 ,
V_219 ,
V_184 ) ;
if ( V_29 && V_29 != - V_220 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_221 , V_187 ) ;
V_29 = F_109 ( V_183 ,
V_222 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_223 , V_187 ) ;
V_29 = F_109 ( V_183 ,
V_224 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_184 = F_103 ( V_181 -> V_189 . V_190 . V_225 , V_187 ) ;
V_29 = F_109 ( V_183 ,
V_226 ,
V_184 ) ;
if ( V_29 )
return V_29 ;
V_183 -> V_189 |= V_227 ;
if ( V_62 -> V_4 . V_67 & V_68 )
V_183 -> V_171 |= V_228 ;
V_183 -> V_171 |= V_229 |
V_230 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_62 ,
int V_231 ,
const struct V_180 * V_181 )
{
struct V_5 * V_18 ;
struct V_182 V_183 ;
struct V_232 * V_75 ;
int V_29 ;
V_18 = F_3 ( V_62 -> V_4 . V_69 ) ;
V_29 = F_100 ( V_62 , V_181 , & V_183 ) ;
if ( V_29 )
return V_29 ;
if ( V_231 == V_233 )
return 0 ;
V_75 = & V_62 -> V_75 [ V_231 ] ;
V_75 -> V_183 = V_183 ;
F_111 ( V_18 -> V_22 , V_75 -> V_79 , & V_75 -> V_183 ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_62 ,
int V_231 ,
const struct V_180 * V_181 )
{
struct V_9 * V_18 ;
struct V_182 V_183 ;
struct V_232 * V_75 ;
int V_29 ;
V_18 = F_5 ( V_62 -> V_4 . V_69 ) ;
V_29 = F_100 ( V_62 , V_181 , & V_183 ) ;
if ( V_29 )
return V_29 ;
if ( V_231 == V_233 )
return 0 ;
V_75 = & V_62 -> V_75 [ V_231 ] ;
V_75 -> V_183 = V_183 ;
if ( V_75 -> V_73 . type == V_82 )
V_75 -> V_183 . V_189 |= F_113 ( V_75 -> V_73 . V_79 ) ;
F_114 ( V_18 -> V_4 . V_22 , V_18 -> V_234 , V_75 -> V_79 ,
& V_75 -> V_183 ) ;
return 0 ;
}
static int F_115 ( struct V_60 * V_61 , int V_231 ,
const struct V_180 * V_181 )
{
struct V_2 * V_3 = F_30 ( V_61 ) ;
struct V_1 * V_62 = F_1 ( V_3 ) ;
struct V_5 * V_18 ;
V_18 = F_3 ( V_62 -> V_4 . V_69 ) ;
if ( V_231 >= V_62 -> V_76 ||
( V_231 < 0 && V_231 != V_233 ) )
return - V_235 ;
return V_18 -> V_116 -> V_236 -> V_237 ( V_62 , V_231 , V_181 ) ;
}
static void F_116 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
V_61 -> V_34 . V_238 = V_18 -> V_34 ;
V_62 -> V_4 . V_69 = & V_18 -> V_4 ;
V_3 -> V_239 = F_58 ;
V_3 -> V_240 = F_29 ;
V_3 -> V_241 = F_32 ;
V_3 -> V_242 = F_34 ;
V_3 -> V_243 = F_37 ;
V_3 -> V_244 = F_41 ;
V_3 -> V_245 = F_46 ;
if ( V_18 -> V_193 && V_18 -> V_116 -> V_236 -> V_237 )
V_3 -> V_237 = F_115 ;
V_3 -> V_246 = 40 ;
if ( V_18 -> V_54 )
V_3 -> V_67 |= V_247 ;
if ( V_18 -> V_128 )
V_3 -> V_133 . V_171 = V_174 ;
}
static void F_117 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_8 * V_248 ;
int V_94 ;
F_116 ( V_18 , V_62 ) ;
V_248 = F_4 ( V_3 -> V_69 ) ;
if ( ! V_248 -> V_249 )
return;
for ( V_94 = 0 ; V_94 < V_62 -> V_76 ; V_94 ++ )
F_50 ( V_248 -> V_249 , V_248 -> V_250 ,
F_118 ( V_62 -> V_75 [ V_94 ] . V_79 ) , F_118 ( V_62 -> V_75 [ V_94 ] . V_79 ) ) ;
}
static void F_119 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
F_116 ( V_18 , V_62 ) ;
V_3 -> V_239 = F_57 ;
V_3 -> V_245 = F_49 ;
}
static int F_120 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
V_29 = F_121 ( V_61 , V_62 -> V_76 , NULL ) ;
if ( V_29 )
F_16 ( V_18 -> V_34 , L_19 , V_29 ) ;
return V_29 ;
}
static int F_122 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
int V_29 ;
V_29 = F_123 ( V_61 ) ;
if ( V_29 )
return V_29 ;
F_124 ( V_3 ) ;
F_125 ( & V_62 -> V_251 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_62 )
{
struct V_2 * V_3 = & V_62 -> V_4 ;
struct V_60 * V_61 = F_62 ( V_3 ) ;
struct V_5 * V_18 ;
int V_29 ;
V_18 = F_3 ( V_3 -> V_69 ) ;
if ( V_18 -> V_116 -> V_155 || ! V_18 -> V_34 -> V_156 ) {
V_61 -> V_252 = L_20 ;
} else if ( ! V_61 -> V_252 ) {
V_61 -> V_252 = F_127 ( V_18 -> V_34 , V_253 ,
L_21 , F_128 ( V_18 -> V_34 ) ,
V_62 -> V_75 [ 0 ] . V_79 ) ;
if ( ! V_61 -> V_252 ) {
F_16 ( V_18 -> V_34 , L_22 ) ;
return - V_254 ;
}
}
V_29 = F_129 ( V_61 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_23 , V_29 ) ;
return V_29 ;
}
V_29 = F_130 ( V_61 , NULL , 0 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_24 , V_29 ) ;
F_124 ( V_3 ) ;
return V_29 ;
}
F_131 ( & V_62 -> V_251 , & V_18 -> V_255 ) ;
return 0 ;
}
static struct V_1 * F_132 ( struct V_5 * V_18 ,
struct V_256 * V_257 ,
int V_258 )
{
struct V_1 * V_62 ;
struct V_259 * V_74 ;
int V_76 , V_29 , V_94 ;
V_76 = F_133 ( V_257 , L_25 ,
V_258 * sizeof( T_1 ) ) ;
if ( V_76 < 1 ) {
F_16 ( V_18 -> V_34 , L_26 ) ;
return F_134 ( - V_235 ) ;
}
V_62 = F_135 ( V_18 -> V_34 ,
sizeof( * V_62 ) + ( V_76 * sizeof( * V_62 -> V_75 ) ) ,
V_253 ) ;
if ( ! V_62 ) {
F_16 ( V_18 -> V_34 , L_27 ) ;
return F_134 ( - V_254 ) ;
}
V_62 -> V_76 = V_76 ;
V_74 = F_136 ( V_18 -> V_34 , L_28 , 0 ,
& V_257 -> V_260 , V_261 ,
L_29 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_262 ) {
F_16 ( V_18 -> V_34 ,
L_30 ,
F_96 ( V_74 ) ) ;
return F_137 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) )
V_62 -> V_263 = V_74 ;
for ( V_94 = 0 ; V_94 < V_76 ; V_94 ++ ) {
struct V_264 V_265 ;
T_1 V_93 ;
V_29 = F_138 ( V_257 , 0 , & V_265 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_31 ,
V_29 ) ;
return F_134 ( V_29 ) ;
}
V_29 = F_139 ( V_257 , L_25 , V_94 * V_258 ,
& V_93 ) ;
if ( V_29 ) {
F_16 ( V_18 -> V_34 , L_31 ,
V_29 ) ;
return F_134 ( V_29 ) ;
}
V_62 -> V_75 [ V_94 ] . V_79 = V_93 ;
V_62 -> V_75 [ V_94 ] . V_64 . V_71 = V_265 . V_266 ;
V_62 -> V_75 [ V_94 ] . V_64 . V_65 = F_140 ( V_18 -> V_34 , & V_265 ) ;
if ( F_95 ( V_62 -> V_75 [ V_94 ] . V_64 . V_65 ) )
return F_137 ( V_62 -> V_75 [ V_94 ] . V_64 . V_65 ) ;
if ( ! F_93 ( V_257 , L_32 , & V_93 ) ) {
if ( V_93 > V_267 )
return F_134 ( - V_235 ) ;
V_62 -> V_75 [ V_94 ] . V_73 . type = V_82 ;
V_62 -> V_75 [ V_94 ] . V_73 . V_79 = V_93 ;
} else {
V_74 = F_136 ( V_18 -> V_34 ,
L_33 , V_94 , & V_257 -> V_260 ,
V_261 , L_34 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_262 ) {
F_16 ( V_18 -> V_34 ,
L_35 ,
F_96 ( V_74 ) ) ;
return F_137 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) ) {
V_62 -> V_75 [ V_94 ] . V_73 . type = V_78 ;
V_62 -> V_75 [ V_94 ] . V_73 . V_74 = V_74 ;
}
}
V_74 = F_136 ( V_18 -> V_34 , L_36 ,
V_94 , & V_257 -> V_260 ,
V_268 ,
L_37 ) ;
if ( F_95 ( V_74 ) && F_96 ( V_74 ) != - V_262 ) {
F_16 ( V_18 -> V_34 ,
L_38 ,
F_96 ( V_74 ) ) ;
return F_137 ( V_74 ) ;
}
if ( ! F_95 ( V_74 ) )
V_62 -> V_75 [ V_94 ] . V_114 = V_74 ;
}
F_141 ( & V_62 -> V_4 , V_257 ) ;
return V_62 ;
}
static int
F_142 ( struct V_5 * V_18 ,
struct V_1 * V_62 )
{
int V_29 ;
if ( V_62 -> V_263 && F_45 ( V_62 -> V_263 ) ) {
F_143 ( V_18 -> V_34 , L_39 ) ;
return 0 ;
}
V_18 -> V_116 -> V_236 -> V_269 ( V_18 , V_62 ) ;
V_29 = F_120 ( V_62 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_18 -> V_116 -> V_236 -> V_270 ( V_62 ) ;
if ( V_29 )
return V_29 ;
return F_126 ( V_62 ) ;
}
static int
F_144 ( struct V_5 * V_18 )
{
struct V_1 * V_62 , * V_271 ;
int V_29 ;
F_145 (nand, tmp, &nc->chips, node) {
V_29 = F_122 ( V_62 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_146 ( struct V_5 * V_18 )
{
struct V_272 * V_34 = V_18 -> V_34 ;
struct V_273 * V_274 = F_147 ( V_34 ) ;
struct V_1 * V_62 ;
struct V_259 * V_74 ;
struct V_264 * V_265 ;
V_62 = F_135 ( V_18 -> V_34 , sizeof( * V_62 ) + sizeof( * V_62 -> V_75 ) ,
V_253 ) ;
if ( ! V_62 )
return - V_254 ;
V_62 -> V_76 = 1 ;
V_265 = F_148 ( V_274 , V_275 , 0 ) ;
V_62 -> V_75 [ 0 ] . V_64 . V_65 = F_140 ( V_34 , V_265 ) ;
if ( F_95 ( V_62 -> V_75 [ 0 ] . V_64 . V_65 ) )
return F_96 ( V_62 -> V_75 [ 0 ] . V_64 . V_65 ) ;
V_62 -> V_75 [ 0 ] . V_64 . V_71 = V_265 -> V_266 ;
V_62 -> V_75 [ 0 ] . V_79 = 3 ;
V_74 = F_149 ( V_34 , NULL , 0 , V_261 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 , L_35 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
if ( V_74 ) {
V_62 -> V_75 [ 0 ] . V_73 . type = V_78 ;
V_62 -> V_75 [ 0 ] . V_73 . V_74 = V_74 ;
}
V_74 = F_149 ( V_34 , NULL , 1 , V_268 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 , L_38 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
V_62 -> V_75 [ 0 ] . V_114 = V_74 ;
V_74 = F_149 ( V_18 -> V_34 , NULL , 2 , V_261 ) ;
if ( F_95 ( V_74 ) ) {
F_16 ( V_34 ,
L_30 ,
F_96 ( V_74 ) ) ;
return F_96 ( V_74 ) ;
}
V_62 -> V_263 = V_74 ;
F_141 ( & V_62 -> V_4 , V_18 -> V_34 -> V_156 ) ;
return F_142 ( V_18 , V_62 ) ;
}
static int F_150 ( struct V_5 * V_18 )
{
struct V_256 * V_257 , * V_276 ;
struct V_272 * V_34 = V_18 -> V_34 ;
int V_29 , V_258 ;
T_1 V_93 ;
if ( V_18 -> V_116 -> V_155 )
return F_146 ( V_18 ) ;
V_257 = V_34 -> V_156 ;
V_29 = F_93 ( V_257 , L_40 , & V_93 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_41 ) ;
return V_29 ;
}
V_258 = V_93 ;
V_29 = F_93 ( V_257 , L_42 , & V_93 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_41 ) ;
return V_29 ;
}
V_258 += V_93 ;
F_151 (np, nand_np) {
struct V_1 * V_62 ;
V_62 = F_132 ( V_18 , V_276 , V_258 ) ;
if ( F_95 ( V_62 ) ) {
V_29 = F_96 ( V_62 ) ;
goto V_52;
}
V_29 = F_142 ( V_18 , V_62 ) ;
if ( V_29 )
goto V_52;
}
return 0 ;
V_52:
F_144 ( V_18 ) ;
return V_29 ;
}
static void F_152 ( struct V_5 * V_18 )
{
if ( V_18 -> V_54 )
F_153 ( V_18 -> V_54 ) ;
F_154 ( V_18 -> V_193 ) ;
}
static int F_155 ( struct V_5 * V_18 ,
struct V_273 * V_274 ,
const struct V_277 * V_116 )
{
struct V_272 * V_34 = & V_274 -> V_34 ;
struct V_256 * V_257 = V_34 -> V_156 ;
int V_29 ;
F_156 ( & V_18 -> V_4 ) ;
F_157 ( & V_18 -> V_255 ) ;
V_18 -> V_34 = V_34 ;
V_18 -> V_116 = V_116 ;
F_158 ( V_274 , V_18 ) ;
V_18 -> V_128 = F_159 ( V_34 ) ;
if ( F_95 ( V_18 -> V_128 ) ) {
V_29 = F_96 ( V_18 -> V_128 ) ;
if ( V_29 != - V_278 )
F_16 ( V_34 , L_43 ,
V_29 ) ;
return V_29 ;
}
if ( V_18 -> V_116 -> V_279 ) {
T_8 V_280 ;
F_160 ( V_280 ) ;
F_161 ( V_281 , V_280 ) ;
V_18 -> V_54 = F_162 ( V_280 , NULL , NULL ) ;
if ( ! V_18 -> V_54 )
F_16 ( V_18 -> V_34 , L_44 ) ;
}
if ( V_18 -> V_116 -> V_155 )
return 0 ;
V_18 -> V_193 = F_163 ( V_34 -> V_238 -> V_156 , 0 ) ;
if ( F_95 ( V_18 -> V_193 ) ) {
F_16 ( V_34 , L_45 ) ;
return F_96 ( V_18 -> V_193 ) ;
}
V_257 = F_164 ( V_34 -> V_238 -> V_156 , L_46 , 0 ) ;
if ( ! V_257 ) {
F_16 ( V_34 , L_47 ) ;
return - V_235 ;
}
V_18 -> V_22 = F_165 ( V_257 ) ;
F_166 ( V_257 ) ;
if ( F_95 ( V_18 -> V_22 ) ) {
V_29 = F_96 ( V_18 -> V_22 ) ;
F_16 ( V_34 , L_48 , V_29 ) ;
return V_29 ;
}
return 0 ;
}
static int
F_167 ( struct V_8 * V_18 )
{
struct V_272 * V_34 = V_18 -> V_4 . V_34 ;
const struct V_282 * V_283 ;
struct V_256 * V_257 ;
int V_29 ;
if ( V_18 -> V_4 . V_116 -> V_155 )
return 0 ;
V_257 = F_164 ( V_34 -> V_238 -> V_156 , L_49 , 0 ) ;
if ( ! V_257 )
return 0 ;
V_283 = F_168 ( V_284 , V_257 ) ;
if ( ! V_283 ) {
F_166 ( V_257 ) ;
return 0 ;
}
V_18 -> V_249 = F_165 ( V_257 ) ;
F_166 ( V_257 ) ;
if ( F_95 ( V_18 -> V_249 ) ) {
V_29 = F_96 ( V_18 -> V_249 ) ;
F_16 ( V_34 , L_50 , V_29 ) ;
return V_29 ;
}
V_18 -> V_250 = ( unsigned int ) V_283 -> V_17 ;
if ( F_169 ( V_34 -> V_238 -> V_156 ,
L_51 ) )
V_18 -> V_250 += 4 ;
return 0 ;
}
static int
F_170 ( struct V_9 * V_18 )
{
struct V_285 V_286 = {
. V_287 = 32 ,
. V_288 = 32 ,
. V_289 = 4 ,
} ;
struct V_272 * V_34 = V_18 -> V_4 . V_34 ;
struct V_256 * V_276 , * V_290 ;
void T_9 * V_291 ;
struct V_264 V_265 ;
int V_29 ;
V_276 = V_34 -> V_156 ;
V_290 = F_171 ( V_34 -> V_156 , NULL ,
L_52 ) ;
V_18 -> V_292 = F_163 ( V_290 , 0 ) ;
if ( F_95 ( V_18 -> V_292 ) ) {
V_29 = F_96 ( V_18 -> V_292 ) ;
F_16 ( V_34 , L_53 ,
V_29 ) ;
goto V_293;
}
V_29 = F_172 ( V_18 -> V_292 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_54 ,
V_29 ) ;
goto V_293;
}
V_18 -> V_16 = F_173 ( V_276 , 0 ) ;
if ( V_18 -> V_16 <= 0 ) {
V_29 = V_18 -> V_16 ? : - V_294 ;
if ( V_29 != - V_278 )
F_16 ( V_34 , L_55 ,
V_29 ) ;
goto V_293;
}
V_29 = F_138 ( V_290 , 0 , & V_265 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_56 ,
V_29 ) ;
goto V_293;
}
V_291 = F_140 ( V_34 , & V_265 ) ;
if ( F_95 ( V_291 ) ) {
V_29 = F_96 ( V_291 ) ;
goto V_293;
}
V_286 . V_252 = L_57 ;
V_286 . V_295 = F_174 ( & V_265 ) - 4 ;
V_18 -> V_64 = F_175 ( V_34 , V_291 , & V_286 ) ;
if ( F_95 ( V_18 -> V_64 ) ) {
V_29 = F_96 ( V_18 -> V_64 ) ;
F_16 ( V_34 , L_58 ,
V_29 ) ;
goto V_293;
}
V_29 = F_138 ( V_290 , 1 , & V_265 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_59 ,
V_29 ) ;
goto V_293;
}
V_291 = F_140 ( V_34 , & V_265 ) ;
if ( F_95 ( V_291 ) ) {
V_29 = F_96 ( V_291 ) ;
goto V_293;
}
V_286 . V_252 = L_60 ;
V_286 . V_295 = F_174 ( & V_265 ) - 4 ;
V_18 -> V_4 . V_22 = F_175 ( V_34 , V_291 , & V_286 ) ;
if ( F_95 ( V_18 -> V_4 . V_22 ) ) {
V_29 = F_96 ( V_18 -> V_4 . V_22 ) ;
F_16 ( V_34 , L_58 ,
V_29 ) ;
goto V_293;
}
V_29 = F_138 ( V_290 , 2 , & V_265 ) ;
if ( V_29 ) {
F_16 ( V_34 , L_61 ,
V_29 ) ;
goto V_293;
}
V_18 -> V_120 . V_65 = F_140 ( V_34 , & V_265 ) ;
if ( F_95 ( V_18 -> V_120 . V_65 ) ) {
V_29 = F_96 ( V_18 -> V_120 . V_65 ) ;
goto V_293;
}
V_18 -> V_120 . V_71 = V_265 . V_266 ;
V_293:
F_166 ( V_290 ) ;
return V_29 ;
}
static int
F_176 ( struct V_9 * V_18 )
{
struct V_272 * V_34 = V_18 -> V_4 . V_34 ;
struct V_256 * V_257 ;
int V_29 ;
V_257 = F_164 ( V_34 -> V_238 -> V_156 , L_46 , 0 ) ;
if ( ! V_257 ) {
F_16 ( V_34 , L_47 ) ;
return - V_235 ;
}
V_18 -> V_234 = F_177 ( V_257 ) ;
V_18 -> V_16 = F_173 ( V_257 , 0 ) ;
F_166 ( V_257 ) ;
if ( V_18 -> V_16 <= 0 ) {
V_29 = V_18 -> V_16 ? : - V_294 ;
if ( V_29 != - V_278 )
F_16 ( V_34 , L_55 ,
V_29 ) ;
return V_29 ;
}
V_257 = F_164 ( V_34 -> V_156 , L_62 , 0 ) ;
if ( ! V_257 ) {
F_16 ( V_34 , L_63 ) ;
return - V_235 ;
}
V_18 -> V_64 = F_165 ( V_257 ) ;
F_166 ( V_257 ) ;
if ( F_95 ( V_18 -> V_64 ) ) {
V_29 = F_96 ( V_18 -> V_64 ) ;
F_16 ( V_34 , L_64 , V_29 ) ;
return V_29 ;
}
V_18 -> V_120 . V_296 = F_178 ( V_18 -> V_4 . V_34 -> V_156 ,
L_65 , 0 ) ;
if ( ! V_18 -> V_120 . V_296 ) {
F_16 ( V_18 -> V_4 . V_34 , L_66 ) ;
return - V_254 ;
}
V_18 -> V_120 . V_65 = F_179 ( V_18 -> V_120 . V_296 ,
V_297 ,
& V_18 -> V_120 . V_71 ) ;
if ( ! V_18 -> V_120 . V_65 ) {
F_16 ( V_18 -> V_4 . V_34 ,
L_67 ) ;
return - V_254 ;
}
return 0 ;
}
static int
F_180 ( struct V_5 * V_18 )
{
struct V_9 * V_298 ;
int V_29 ;
V_29 = F_144 ( V_18 ) ;
if ( V_29 )
return V_29 ;
V_298 = F_2 ( V_18 , struct V_9 , V_4 ) ;
if ( V_298 -> V_120 . V_296 )
F_181 ( V_298 -> V_120 . V_296 ,
( unsigned long ) V_298 -> V_120 . V_65 ,
V_297 ) ;
if ( V_298 -> V_292 ) {
F_182 ( V_298 -> V_292 ) ;
F_154 ( V_298 -> V_292 ) ;
}
F_152 ( V_18 ) ;
return 0 ;
}
static int F_183 ( struct V_273 * V_274 ,
const struct V_277 * V_116 )
{
struct V_272 * V_34 = & V_274 -> V_34 ;
struct V_9 * V_18 ;
int V_29 ;
V_18 = F_135 ( V_34 , sizeof( * V_18 ) , V_253 ) ;
if ( ! V_18 )
return - V_254 ;
V_29 = F_155 ( & V_18 -> V_4 , V_274 , V_116 ) ;
if ( V_29 )
return V_29 ;
if ( V_116 -> V_155 )
V_29 = F_170 ( V_18 ) ;
else
V_29 = F_176 ( V_18 ) ;
if ( V_29 )
return V_29 ;
F_9 ( V_18 -> V_4 . V_22 , V_24 , 0xffffffff ) ;
V_29 = F_184 ( V_34 , V_18 -> V_16 , F_7 ,
V_299 , L_68 , V_18 ) ;
if ( V_29 ) {
F_16 ( V_34 ,
L_69 ,
V_29 ) ;
goto V_52;
}
F_9 ( V_18 -> V_4 . V_22 , V_83 ,
V_300 ) ;
V_29 = F_150 ( & V_18 -> V_4 ) ;
if ( V_29 )
goto V_52;
return 0 ;
V_52:
F_180 ( & V_18 -> V_4 ) ;
return V_29 ;
}
static int F_185 ( struct V_273 * V_274 ,
const struct V_277 * V_116 )
{
struct V_272 * V_34 = & V_274 -> V_34 ;
struct V_8 * V_18 ;
int V_29 ;
V_18 = F_135 ( V_34 , sizeof( * V_18 ) , V_253 ) ;
if ( ! V_18 )
return - V_254 ;
V_29 = F_155 ( & V_18 -> V_4 , V_274 , V_116 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_167 ( V_18 ) ;
if ( V_29 )
return V_29 ;
return F_150 ( & V_18 -> V_4 ) ;
}
static int
F_186 ( struct V_5 * V_18 )
{
int V_29 ;
V_29 = F_144 ( V_18 ) ;
if ( V_29 )
return V_29 ;
F_152 ( V_18 ) ;
return 0 ;
}
static int F_187 ( struct V_273 * V_274 )
{
const struct V_277 * V_116 ;
if ( V_274 -> V_301 )
V_116 = ( void * ) V_274 -> V_301 -> V_302 ;
else
V_116 = F_188 ( & V_274 -> V_34 ) ;
if ( ! V_116 ) {
F_16 ( & V_274 -> V_34 , L_70 ) ;
return - V_235 ;
}
if ( V_116 -> V_155 ) {
T_1 V_117 = 21 ;
if ( F_171 ( V_274 -> V_34 . V_156 , NULL ,
L_52 ) )
V_116 = & V_303 ;
if ( ! V_116 -> V_279 &&
F_189 ( V_274 -> V_34 . V_156 ,
L_71 ) )
V_116 = & V_304 ;
F_93 ( V_274 -> V_34 . V_156 ,
L_72 , & V_117 ) ;
if ( V_117 != 21 )
V_116 = & V_305 ;
}
return V_116 -> V_236 -> V_306 ( V_274 , V_116 ) ;
}
static int F_190 ( struct V_273 * V_274 )
{
struct V_5 * V_18 = F_191 ( V_274 ) ;
return V_18 -> V_116 -> V_236 -> remove ( V_18 ) ;
}
static T_10 int F_192 ( struct V_272 * V_34 )
{
struct V_5 * V_18 = F_193 ( V_34 ) ;
struct V_1 * V_62 ;
F_194 (nand, &nc->chips, node) {
int V_94 ;
for ( V_94 = 0 ; V_94 < V_62 -> V_76 ; V_94 ++ )
F_195 ( & V_62 -> V_4 , V_94 ) ;
}
return 0 ;
}
