static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
return ( unsigned int ) F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 , unsigned V_6 ,
unsigned V_7 )
{
unsigned V_5 = F_1 ( V_2 , V_3 ) ;
V_5 &= V_6 ;
V_5 |= V_7 ;
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 , unsigned V_6 )
{
unsigned V_5 = F_1 ( V_2 , V_3 ) ;
V_5 &= V_6 ;
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 , unsigned V_7 )
{
unsigned V_5 = F_1 ( V_2 , V_3 ) ;
V_5 |= V_7 ;
F_3 ( V_2 , V_3 , V_5 ) ;
}
static inline unsigned int F_8 ( struct V_1 * V_2 , int V_3 ,
int V_8 )
{
return F_1 ( V_2 , V_3 + ( V_8 << 2 ) ) ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 , int V_8 ,
unsigned V_5 )
{
F_3 ( V_2 , V_3 + ( V_8 << 2 ) , V_5 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , int V_3 , int V_8 ,
unsigned V_6 , unsigned V_7 )
{
F_5 ( V_2 , V_3 + ( V_8 << 2 ) , V_6 , V_7 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_3 , int V_8 ,
unsigned V_7 )
{
F_7 ( V_2 , V_3 + ( V_8 << 2 ) , V_7 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_3 , int V_8 , int V_9 ,
unsigned V_7 )
{
F_7 ( V_2 , V_3 + ( ( V_8 * 2 + V_9 ) << 2 ) , V_7 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 , int V_8 ,
int V_9 , unsigned V_5 )
{
F_3 ( V_2 , V_3 + ( ( V_8 * 2 + V_9 ) << 2 ) , V_5 ) ;
}
static inline unsigned int F_14 ( struct V_1 * V_2 , int V_3 )
{
return F_1 ( V_2 , V_10 + V_3 ) ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 ,
int V_3 , int V_8 )
{
return F_1 ( V_2 , V_10 + V_3 + ( V_8 << 2 ) ) ;
}
static inline void F_16 ( struct V_1 * V_2 , int V_3 ,
unsigned V_5 )
{
F_3 ( V_2 , V_10 + V_3 , V_5 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , int V_3 ,
int V_8 , unsigned V_5 )
{
F_3 ( V_2 , V_10 + V_3 + ( V_8 << 2 ) , V_5 ) ;
}
static inline unsigned int F_18 ( struct V_1 * V_2 , int V_3 ,
int V_11 )
{
return F_1 ( V_2 , V_12 + V_3 + ( V_11 << 5 ) ) ;
}
static inline void F_19 ( struct V_1 * V_2 , int V_3 ,
int V_11 , unsigned V_5 )
{
F_3 ( V_2 , V_12 + V_3 + ( V_11 << 5 ) , V_5 ) ;
}
static inline void F_20 ( struct V_1 * V_2 , int V_3 ,
int V_11 , unsigned V_6 , unsigned V_7 )
{
F_5 ( V_2 , V_12 + V_3 + ( V_11 << 5 ) , V_6 , V_7 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , int V_3 , int V_11 ,
unsigned V_6 )
{
F_6 ( V_2 , V_12 + V_3 + ( V_11 << 5 ) , V_6 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , int V_3 , int V_11 ,
unsigned V_7 )
{
F_7 ( V_2 , V_12 + V_3 + ( V_11 << 5 ) , V_7 ) ;
}
static inline void F_23 ( int V_3 , int V_13 , unsigned long * V_14 )
{
for (; V_13 > 0 ; V_13 -- )
F_24 ( V_3 + ( V_13 - 1 ) , V_14 ) ;
}
static inline void F_25 ( int V_3 , int V_13 , unsigned long * V_14 )
{
for (; V_13 > 0 ; V_13 -- )
F_26 ( V_3 + ( V_13 - 1 ) , V_14 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_15 ,
int V_16 )
{
int V_17 = V_15 * 4 ;
F_5 ( V_2 , V_18 , ~ ( 0x7 << V_17 ) , ( ( V_16 & 0x7 ) << V_17 ) ) ;
}
static void F_28 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
if ( V_2 -> V_24 ) {
V_21 = F_29 ( V_21 ) ;
F_9 ( V_2 , V_25 , V_22 , ( V_21 << 5 ) ) ;
}
}
static void F_30 ( struct V_19 * V_20 , bool V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
if ( V_26 ) {
F_17 ( V_2 , V_27 , V_22 >> 5 ,
F_31 ( V_22 & 0x1f ) ) ;
F_17 ( V_2 , V_28 , V_22 >> 5 ,
F_31 ( V_22 & 0x1f ) ) ;
} else {
F_17 ( V_2 , V_29 , V_22 >> 5 ,
F_31 ( V_22 & 0x1f ) ) ;
}
}
static void F_32 ( struct V_1 * V_2 , unsigned V_21 ,
const struct V_30 * V_31 )
{
V_21 = F_29 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return;
F_33 ( V_2 -> V_4 + F_34 ( V_21 ) , V_31 , V_33 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned V_21 ,
struct V_30 * V_31 )
{
V_21 = F_29 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return;
F_36 ( V_31 , V_2 -> V_4 + F_34 ( V_21 ) , V_33 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 > 0 ) {
V_21 = F_29 ( V_21 ) ;
if ( V_2 -> V_24 && V_21 < V_2 -> V_34 )
V_21 = V_35 ;
}
if ( V_21 < 0 ) {
if ( V_2 -> V_24 )
V_21 = 0 ;
else
V_21 = V_2 -> V_34 ;
for (; ; ) {
V_21 = F_38 ( V_2 -> V_36 ,
V_2 -> V_32 ,
V_21 ) ;
if ( V_21 == V_2 -> V_32 )
return - V_37 ;
if ( ! F_39 ( V_21 , V_2 -> V_36 ) )
break;
}
} else if ( V_21 >= V_2 -> V_32 ) {
return - V_38 ;
} else if ( F_39 ( V_21 , V_2 -> V_36 ) ) {
return - V_39 ;
}
F_32 ( V_2 , V_21 , & V_40 ) ;
return F_40 ( V_2 -> V_41 , V_21 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_21 )
{
V_21 = F_29 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return;
F_32 ( V_2 , V_21 , & V_40 ) ;
F_26 ( V_21 , V_2 -> V_36 ) ;
}
static void F_42 ( struct V_1 * V_2 , unsigned V_42 , unsigned V_43 )
{
if ( F_43 ( F_44 ( V_42 ) != F_44 ( V_43 ) ) )
F_45 ( V_2 -> V_44 , L_1 ) ;
V_42 = F_29 ( V_42 ) ;
V_43 = F_29 ( V_43 ) ;
if ( V_42 >= V_2 -> V_32 || V_43 >= V_2 -> V_32 )
return;
F_20 ( V_2 , V_45 , V_42 , 0xffff0000 ,
F_34 ( V_43 ) ) ;
}
static T_1 F_46 ( struct V_1 * V_2 , unsigned V_21 ,
bool V_46 )
{
T_2 V_47 ;
V_21 = F_29 ( V_21 ) ;
V_47 = F_34 ( V_21 ) ;
V_47 += V_46 ? V_48 : V_49 ;
return F_1 ( V_2 , V_47 ) ;
}
static void F_47 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
if ( ! V_20 -> V_51 ) {
F_48 ( V_2 -> V_44 , L_2 , V_9 ,
F_15 ( V_2 , V_52 , V_9 ) ) ;
F_17 ( V_2 , V_52 , V_9 , V_50 ) ;
} else {
F_48 ( V_2 -> V_44 , L_3 , V_9 ,
F_15 ( V_2 , V_53 , V_9 ) ) ;
F_9 ( V_2 , V_54 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_17 ( V_2 , V_57 , V_9 , V_50 ) ;
F_48 ( V_2 -> V_44 , L_4 , V_9 ,
F_15 ( V_2 , V_58 , V_9 ) ) ;
}
}
static void F_49 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
F_17 ( V_2 , V_59 , V_9 , V_50 ) ;
F_17 ( V_2 , V_60 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_27 , V_9 , V_50 ) ;
F_48 ( V_2 -> V_44 , L_4 , V_9 ,
F_15 ( V_2 , V_58 , V_9 ) ) ;
}
static void F_50 ( struct V_19 * V_20 )
{
int V_22 = F_29 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
F_17 ( V_20 -> V_2 , V_59 , V_22 >> 5 , V_50 ) ;
}
static void F_51 ( struct V_19 * V_20 )
{
int V_22 = F_29 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
F_17 ( V_20 -> V_2 , V_57 , V_22 >> 5 , V_50 ) ;
}
static void F_52 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
F_17 ( V_2 , V_52 , ( V_22 >> 5 ) , V_50 ) ;
F_48 ( V_2 -> V_44 , L_2 , ( V_22 >> 5 ) ,
F_15 ( V_2 , V_52 , ( V_22 >> 5 ) ) ) ;
}
static void F_53 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_31 ( V_22 & 0x1f ) ;
F_48 ( V_2 -> V_44 , L_5 , V_9 , F_8 ( V_2 , V_61 , V_9 ) ) ;
F_17 ( V_2 , V_60 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_3 ( V_2 , V_62 , F_31 ( 16 ) | F_31 ( 1 ) | F_31 ( 0 ) ) ;
}
static void F_54 ( struct V_19 * V_20 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
int V_17 = ( V_22 & 0x7 ) * 4 ;
if ( V_64 == V_65 )
V_64 = V_2 -> V_66 ;
if ( V_64 >= V_2 -> V_67 )
return;
V_64 &= 7 ;
F_10 ( V_2 , V_68 , ( V_22 >> 3 ) , ~ ( 0x7 << V_17 ) ,
V_64 << V_17 ) ;
}
static int F_55 ( struct V_19 * V_20 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_29 ( V_20 -> V_23 ) ;
F_12 ( V_2 , V_69 , 0 , V_22 >> 5 , F_31 ( V_22 & 0x1f ) ) ;
F_49 ( V_20 ) ;
F_30 ( V_20 , true ) ;
F_54 ( V_20 , V_64 ) ;
return 0 ;
}
static void F_56 ( struct V_19 * V_20 )
{
F_49 ( V_20 ) ;
F_30 ( V_20 , false ) ;
}
static inline struct V_1 * F_57 ( struct V_70 * V_71 )
{
return F_58 ( V_71 , struct V_1 , V_72 ) ;
}
static inline struct V_19 * F_59 ( struct V_73 * V_74 )
{
return F_58 ( V_74 , struct V_19 , V_75 . V_76 ) ;
}
static inline struct V_77 * F_60 ( struct V_78 * V_79 )
{
return F_58 ( V_79 , struct V_77 , V_80 . V_79 ) ;
}
static void F_61 ( struct V_81 * V_80 )
{
F_62 ( F_58 ( V_80 , struct V_77 , V_80 ) ) ;
}
static void F_63 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_81 * V_80 ;
struct V_77 * V_82 ;
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
int V_8 , V_9 , V_84 , V_85 ;
if ( ! V_20 -> V_82 ) {
V_80 = F_64 ( & V_20 -> V_75 ) ;
if ( ! V_80 )
return;
F_65 ( & V_80 -> V_86 ) ;
V_20 -> V_82 = F_60 ( & V_80 -> V_79 ) ;
}
V_82 = V_20 -> V_82 ;
V_84 = V_82 -> V_87 - V_82 -> V_88 ;
V_85 = F_66 ( V_89 , V_84 ) ;
V_82 -> V_90 = 0 ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
V_9 = V_8 + V_82 -> V_88 ;
F_32 ( V_2 , V_20 -> V_21 [ V_8 ] , & V_82 -> V_91 [ V_9 ] . V_31 ) ;
V_82 -> V_90 += V_82 -> V_91 [ V_9 ] . V_13 ;
F_67 ( V_44 ,
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_9 , V_20 -> V_23 , V_20 -> V_21 [ V_8 ] ,
V_82 -> V_91 [ V_9 ] . V_31 . V_92 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_93 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_46 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_94 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_95 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_96 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_97 ,
V_82 -> V_91 [ V_9 ] . V_31 . V_98 ) ;
if ( V_8 != ( V_85 - 1 ) )
F_42 ( V_2 , V_20 -> V_21 [ V_8 ] , V_20 -> V_21 [ V_8 + 1 ] ) ;
}
V_82 -> V_88 += V_85 ;
if ( V_82 -> V_88 == V_82 -> V_87 ) {
if ( V_82 -> V_99 )
F_42 ( V_2 , V_20 -> V_21 [ V_85 - 1 ] , V_20 -> V_21 [ 1 ] ) ;
else
F_42 ( V_2 , V_20 -> V_21 [ V_85 - 1 ] ,
V_20 -> V_2 -> V_100 ) ;
}
if ( V_20 -> V_101 ) {
F_48 ( V_44 , L_17 , V_20 -> V_23 ) ;
F_53 ( V_20 ) ;
F_49 ( V_20 ) ;
F_47 ( V_20 ) ;
F_52 ( V_20 ) ;
V_20 -> V_101 = 0 ;
} else if ( V_82 -> V_88 <= V_89 ) {
F_48 ( V_44 , L_18 ,
V_20 -> V_23 ) ;
F_47 ( V_20 ) ;
} else {
F_48 ( V_44 , L_19 ,
V_20 -> V_23 , V_82 -> V_88 ) ;
F_51 ( V_20 ) ;
}
}
static int F_68 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned long V_102 ;
F_69 ( V_103 ) ;
F_70 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( V_20 -> V_82 ) {
F_49 ( V_20 ) ;
if ( ! V_20 -> V_105 && V_20 -> V_82 -> V_99 )
F_54 ( V_20 , V_65 ) ;
F_61 ( & V_20 -> V_82 -> V_80 ) ;
V_20 -> V_82 = NULL ;
}
F_71 ( & V_20 -> V_75 , & V_103 ) ;
F_72 ( & V_20 -> V_75 . V_104 , V_102 ) ;
F_73 ( & V_20 -> V_75 , & V_103 ) ;
return 0 ;
}
static int F_74 ( struct V_73 * V_76 ,
struct V_106 * V_107 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
if ( V_107 -> V_108 == V_109 ||
V_107 -> V_110 == V_109 )
return - V_38 ;
memcpy ( & V_20 -> V_107 , V_107 , sizeof( V_20 -> V_107 ) ) ;
return 0 ;
}
static int F_75 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
if ( ! V_20 -> V_82 )
return - V_38 ;
F_50 ( V_20 ) ;
return 0 ;
}
static int F_76 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
F_51 ( V_20 ) ;
return 0 ;
}
static int F_77 ( struct V_73 * V_76 , struct V_111 * V_112 ,
T_1 V_113 , T_1 V_114 , T_2 V_115 ,
unsigned int V_116 , unsigned int V_117 ,
enum V_118 V_119 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_30 * V_31 = & V_112 -> V_31 ;
int V_120 , V_95 , V_121 ;
int V_122 , V_123 , V_124 , V_125 ;
int V_126 ;
if ( ! V_115 )
V_115 = 1 ;
if ( V_115 == 1 ) {
V_126 = false ;
V_95 = V_117 / V_116 / ( V_127 - 1 ) ;
V_120 = V_117 / V_116 - V_95 * ( V_127 - 1 ) ;
if ( V_120 )
V_95 ++ ;
else
V_120 = V_127 - 1 ;
V_121 = V_116 ;
} else {
V_126 = true ;
V_120 = V_115 ;
V_95 = V_117 / ( V_116 * V_120 ) ;
if ( V_95 > ( V_127 - 1 ) ) {
F_78 ( V_44 , L_20 ) ;
return - V_38 ;
}
V_121 = V_116 * V_120 ;
}
V_112 -> V_13 = V_117 ;
if ( V_119 == V_128 ) {
V_122 = V_116 ;
V_124 = V_121 ;
V_123 = 0 ;
V_125 = 0 ;
V_112 -> V_129 = V_113 ;
} else if ( V_119 == V_130 ) {
V_122 = 0 ;
V_124 = 0 ;
V_123 = V_116 ;
V_125 = V_121 ;
V_112 -> V_129 = V_114 ;
} else if ( V_119 == V_131 ) {
V_122 = V_116 ;
V_124 = V_121 ;
V_123 = V_116 ;
V_125 = V_121 ;
} else {
F_78 ( V_44 , L_21 , V_132 ) ;
return - V_38 ;
}
V_31 -> V_92 = F_79 ( F_29 ( V_20 -> V_23 ) ) ;
if ( V_126 )
V_31 -> V_92 |= V_133 ;
V_31 -> V_93 = V_113 ;
V_31 -> V_46 = V_114 ;
V_31 -> V_96 = ( V_123 << 16 ) | V_122 ;
V_31 -> V_97 = ( V_125 << 16 ) | V_124 ;
V_31 -> V_94 = V_120 << 16 | V_116 ;
V_31 -> V_95 = V_95 ;
V_31 -> V_98 = 0xffffffff ;
return V_126 ;
}
static struct V_78 * F_80 (
struct V_73 * V_76 , struct V_134 * V_135 ,
unsigned int V_90 , enum V_118 V_119 ,
unsigned long V_136 , void * V_137 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_77 * V_82 ;
T_1 V_113 = 0 , V_114 = 0 ;
enum V_138 V_139 ;
T_2 V_115 ;
struct V_134 * V_140 ;
int V_8 , V_85 , V_141 ;
if ( F_43 ( ! V_20 || ! V_135 || ! V_90 ) )
return NULL ;
if ( V_119 == V_130 ) {
V_113 = V_20 -> V_107 . V_113 ;
V_139 = V_20 -> V_107 . V_108 ;
V_115 = V_20 -> V_107 . V_142 ;
} else if ( V_119 == V_128 ) {
V_114 = V_20 -> V_107 . V_114 ;
V_139 = V_20 -> V_107 . V_110 ;
V_115 = V_20 -> V_107 . V_143 ;
} else {
F_78 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_78 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
V_82 = F_81 ( sizeof( * V_82 ) + V_90 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_78 ( V_44 , L_24 , V_132 ) ;
return NULL ;
}
V_82 -> V_87 = V_90 ;
V_82 -> V_146 = 0 ;
V_82 -> V_119 = V_119 ;
V_82 -> V_20 = V_20 ;
V_85 = F_82 ( unsigned , V_89 , V_90 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
V_20 -> V_21 [ V_8 ] =
F_37 ( V_20 -> V_2 , V_35 ) ;
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
F_62 ( V_82 ) ;
F_78 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
}
F_83 (sgl, sg, sg_len, i) {
if ( V_119 == V_130 )
V_114 = F_84 ( V_140 ) ;
else
V_113 = F_84 ( V_140 ) ;
V_141 = F_77 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
V_114 , V_115 , V_139 ,
F_85 ( V_140 ) , V_119 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
V_82 -> V_126 = V_141 ;
V_82 -> V_146 += F_85 ( V_140 ) ;
if ( ! ( ( V_8 + 1 ) % V_89 ) )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
if ( V_8 == V_90 - 1 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
}
V_82 -> V_148 = V_82 -> V_146 ;
return F_86 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_87 (
struct V_73 * V_76 , T_1 V_149 , T_1 V_93 ,
T_3 V_13 , unsigned long V_136 )
{
int V_141 , V_85 ;
struct V_77 * V_82 ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned int V_150 , V_151 ;
if ( F_43 ( ! V_20 || ! V_13 ) )
return NULL ;
if ( V_13 < V_127 ) {
V_150 = V_13 ;
V_151 = V_13 ;
V_85 = 1 ;
} else {
V_150 = V_152 - 1 ;
V_151 = F_88 ( V_13 , V_150 ) ;
if ( F_43 ( V_151 == V_13 ) )
V_85 = 1 ;
else
V_85 = 2 ;
}
V_82 = F_81 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_48 ( V_44 , L_26 ) ;
return NULL ;
}
V_82 -> V_87 = V_85 ;
V_82 -> V_146 = V_82 -> V_148 = V_13 ;
V_82 -> V_119 = V_131 ;
V_82 -> V_20 = V_20 ;
V_141 = F_77 ( V_76 , & V_82 -> V_91 [ 0 ] , V_93 , V_149 , 1 ,
V_150 , V_151 , V_131 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
V_82 -> V_126 = V_141 ;
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_153 ;
if ( V_85 == 1 ) {
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_147 ;
} else {
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_154 ;
if ( V_20 -> V_21 [ 1 ] < 0 ) {
V_20 -> V_21 [ 1 ] = F_37 ( V_20 -> V_2 ,
V_35 ) ;
if ( V_20 -> V_21 [ 1 ] < 0 ) {
F_62 ( V_82 ) ;
F_78 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
V_149 += V_151 ;
V_93 += V_151 ;
V_151 = V_150 = V_13 % ( V_152 - 1 ) ;
V_141 = F_77 ( V_76 , & V_82 -> V_91 [ 1 ] , V_93 , V_149 , 1 ,
V_150 , V_151 , V_131 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_153 ;
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_147 ;
}
return F_86 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_89 (
struct V_73 * V_76 , T_1 V_155 , T_3 V_156 ,
T_3 V_157 , enum V_118 V_119 ,
unsigned long V_136 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_77 * V_82 ;
T_1 V_113 , V_114 ;
enum V_138 V_139 ;
T_2 V_115 ;
int V_8 , V_141 , V_85 ;
if ( F_43 ( ! V_20 || ! V_156 || ! V_157 ) )
return NULL ;
if ( V_119 == V_130 ) {
V_113 = V_20 -> V_107 . V_113 ;
V_114 = V_155 ;
V_139 = V_20 -> V_107 . V_108 ;
V_115 = V_20 -> V_107 . V_142 ;
} else if ( V_119 == V_128 ) {
V_113 = V_155 ;
V_114 = V_20 -> V_107 . V_114 ;
V_139 = V_20 -> V_107 . V_110 ;
V_115 = V_20 -> V_107 . V_143 ;
} else {
F_78 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_78 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
if ( F_43 ( V_156 % V_157 ) ) {
F_78 ( V_44 , L_27 ) ;
return NULL ;
}
V_85 = ( V_156 / V_157 ) + 1 ;
if ( V_85 > V_89 )
return NULL ;
V_82 = F_81 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_78 ( V_44 , L_24 , V_132 ) ;
return NULL ;
}
V_82 -> V_99 = 1 ;
V_82 -> V_87 = V_85 ;
V_82 -> V_146 = V_82 -> V_148 = V_156 ;
V_82 -> V_119 = V_119 ;
V_82 -> V_20 = V_20 ;
F_48 ( V_44 , L_28 ,
V_132 , V_20 -> V_23 , V_85 , V_157 , V_156 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
V_20 -> V_21 [ V_8 ] =
F_37 ( V_20 -> V_2 , V_35 ) ;
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
F_62 ( V_82 ) ;
F_78 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
if ( V_8 == V_85 - 1 ) {
memcpy ( & V_82 -> V_91 [ V_8 ] , & V_82 -> V_91 [ 0 ] ,
sizeof( V_82 -> V_91 [ 0 ] ) ) ;
break;
}
V_141 = F_77 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
V_114 , V_115 , V_139 , V_157 ,
V_119 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
if ( V_119 == V_130 )
V_114 += V_157 ;
else
V_113 += V_157 ;
F_67 ( V_44 , L_29 , V_132 , V_8 ) ;
F_67 ( V_44 ,
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_8 , V_20 -> V_23 , V_20 -> V_21 [ V_8 ] ,
V_82 -> V_91 [ V_8 ] . V_31 . V_92 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_93 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_46 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_94 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_95 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_96 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_97 ,
V_82 -> V_91 [ V_8 ] . V_31 . V_98 ) ;
V_82 -> V_126 = V_141 ;
if ( V_136 & V_158 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
}
if ( ! V_20 -> V_105 )
F_54 ( V_20 , V_159 ) ;
return F_86 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static void F_90 ( struct V_19 * V_20 )
{
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_77 * V_82 = V_20 -> V_82 ;
if ( ! V_82 )
return;
F_91 ( & V_20 -> V_75 . V_104 ) ;
if ( V_82 -> V_99 ) {
F_92 ( & V_82 -> V_80 ) ;
F_93 ( & V_20 -> V_75 . V_104 ) ;
return;
} else if ( V_82 -> V_88 == V_82 -> V_87 ) {
V_82 -> V_146 = 0 ;
F_49 ( V_20 ) ;
F_94 ( & V_82 -> V_80 ) ;
V_20 -> V_82 = NULL ;
F_48 ( V_44 , L_30 ,
V_20 -> V_23 ) ;
} else {
F_48 ( V_44 , L_31 ,
V_20 -> V_23 ) ;
F_50 ( V_20 ) ;
V_82 -> V_146 -= V_82 -> V_90 ;
V_82 -> V_148 = V_82 -> V_146 ;
V_82 -> V_160 = V_82 -> V_88 ;
}
F_63 ( V_20 ) ;
F_93 ( & V_20 -> V_75 . V_104 ) ;
}
static T_4 F_95 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
int V_163 ;
T_2 V_164 ;
T_2 V_165 ;
T_2 V_166 ;
V_163 = V_2 -> V_41 ;
if ( V_163 < 0 )
return V_167 ;
F_67 ( V_2 -> V_44 , L_32 ) ;
V_165 = F_15 ( V_2 , V_168 , 0 ) ;
if ( ! V_165 ) {
V_165 = F_15 ( V_2 , V_168 , 1 ) ;
if ( ! V_165 )
return V_167 ;
V_164 = F_15 ( V_2 , V_169 , 1 ) ;
V_166 = 1 ;
} else {
V_164 = F_15 ( V_2 , V_169 , 0 ) ;
V_166 = 0 ;
}
do {
T_2 V_21 ;
T_2 V_22 ;
V_21 = F_96 ( V_165 ) ;
V_165 &= ~ ( F_31 ( V_21 ) ) ;
if ( V_164 & F_31 ( V_21 ) ) {
V_22 = ( V_166 << 5 ) | V_21 ;
F_17 ( V_2 , V_27 , V_166 , F_31 ( V_21 ) ) ;
F_90 ( & V_2 -> V_170 [ V_22 ] ) ;
}
} while ( V_165 );
F_16 ( V_2 , V_171 , 1 ) ;
return V_172 ;
}
static void F_97 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_30 V_14 ;
if ( ! V_20 -> V_82 )
return;
F_91 ( & V_20 -> V_75 . V_104 ) ;
F_35 ( V_2 , V_20 -> V_21 [ 0 ] , & V_14 ) ;
if ( V_14 . V_94 == 0 && V_14 . V_95 == 0 ) {
F_48 ( V_44 , L_33 ) ;
V_20 -> V_101 = 1 ;
} else {
F_48 ( V_44 , L_34 ) ;
F_53 ( V_20 ) ;
F_49 ( V_20 ) ;
F_47 ( V_20 ) ;
F_52 ( V_20 ) ;
}
F_93 ( & V_20 -> V_75 . V_104 ) ;
}
static inline bool F_98 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 , V_61 , 0 ) ||
F_8 ( V_2 , V_61 , 1 ) ||
F_1 ( V_2 , V_173 ) || F_1 ( V_2 , V_174 ) )
return true ;
return false ;
}
static T_4 F_99 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
int V_8 , V_9 ;
int V_163 ;
unsigned int V_175 = 0 ;
unsigned int V_5 ;
V_163 = V_2 -> V_41 ;
if ( V_163 < 0 )
return V_167 ;
F_67 ( V_2 -> V_44 , L_35 ) ;
if ( ! F_98 ( V_2 ) )
return V_167 ;
while ( 1 ) {
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
unsigned long V_176 ;
V_5 = F_8 ( V_2 , V_61 , V_9 ) ;
if ( ! V_5 )
continue;
F_48 ( V_2 -> V_44 , L_36 , V_9 , V_5 ) ;
V_176 = V_5 ;
for ( V_8 = F_100 ( & V_176 , 32 , 0 ) ; V_8 < 32 ;
V_8 = F_100 ( & V_176 , 32 , V_8 + 1 ) ) {
int V_177 = ( V_9 << 5 ) + V_8 ;
F_9 ( V_2 , V_55 , V_9 , F_31 ( V_8 ) ) ;
F_17 ( V_2 , V_56 , V_9 ,
F_31 ( V_8 ) ) ;
F_97 ( & V_2 -> V_170 [ V_177 ] ) ;
}
}
V_5 = F_1 ( V_2 , V_173 ) ;
if ( V_5 ) {
F_48 ( V_2 -> V_44 , L_37 , V_5 ) ;
F_3 ( V_2 , V_178 , V_5 ) ;
F_16 ( V_2 , V_179 , V_5 ) ;
}
V_5 = F_1 ( V_2 , V_174 ) ;
if ( V_5 ) {
F_45 ( V_2 -> V_44 , L_38 , V_5 ) ;
F_3 ( V_2 , V_62 , V_5 ) ;
}
if ( ! F_98 ( V_2 ) )
break;
V_175 ++ ;
if ( V_175 > 10 )
break;
}
F_3 ( V_2 , V_180 , 1 ) ;
return V_172 ;
}
static void F_101 ( struct V_181 * V_105 , bool V_26 )
{
struct V_182 * V_183 ;
int V_141 ;
if ( ! F_102 ( V_184 ) || ! V_105 )
return;
V_183 = F_103 ( V_105 -> V_86 ) ;
if ( ! V_183 ) {
F_104 ( L_39 , V_132 ) ;
return;
}
if ( ! F_105 ( & V_183 -> V_44 ) )
F_106 ( & V_183 -> V_44 ) ;
if ( V_26 )
V_141 = F_107 ( & V_183 -> V_44 ) ;
else
V_141 = F_108 ( & V_183 -> V_44 ) ;
if ( V_141 < 0 )
F_104 ( L_40 , V_132 ,
V_26 ? L_41 : L_42 , F_109 ( & V_183 -> V_44 ) ) ;
}
static int F_110 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_83 * V_44 = V_2 -> V_44 ;
enum V_63 V_64 = V_65 ;
int V_141 ;
if ( V_20 -> V_105 ) {
V_64 = V_20 -> V_105 -> V_41 ;
} else if ( V_2 -> V_185 ) {
V_20 -> V_105 = & V_2 -> V_185 [ V_2 -> V_186 -> V_66 ] ;
V_64 = V_20 -> V_105 -> V_41 ;
}
V_141 = F_55 ( V_20 , V_64 ) ;
if ( V_141 )
return V_141 ;
V_20 -> V_21 [ 0 ] = F_37 ( V_2 , V_20 -> V_23 ) ;
if ( V_20 -> V_21 [ 0 ] < 0 ) {
F_78 ( V_44 , L_43 ,
F_29 ( V_20 -> V_23 ) ) ;
goto V_187;
}
F_28 ( V_20 , V_20 -> V_21 [ 0 ] ) ;
V_20 -> V_188 = true ;
F_48 ( V_44 , L_44 ,
F_29 ( V_20 -> V_23 ) , V_76 -> V_189 ,
V_20 -> V_51 ? L_45 : L_46 ) ;
F_101 ( V_20 -> V_105 , true ) ;
return 0 ;
V_187:
F_56 ( V_20 ) ;
return V_141 ;
}
static void F_111 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_20 -> V_2 -> V_44 ;
int V_8 ;
F_49 ( V_20 ) ;
F_112 ( & V_20 -> V_75 ) ;
for ( V_8 = 0 ; V_8 < V_190 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] >= 0 ) {
F_41 ( V_20 -> V_2 , V_20 -> V_21 [ V_8 ] ) ;
V_20 -> V_21 [ V_8 ] = - 1 ;
}
}
F_28 ( V_20 , V_20 -> V_2 -> V_100 ) ;
if ( V_20 -> V_188 ) {
F_56 ( V_20 ) ;
V_20 -> V_188 = false ;
}
F_101 ( V_20 -> V_105 , false ) ;
V_20 -> V_105 = NULL ;
V_20 -> V_51 = false ;
F_48 ( V_44 , L_47 ,
F_29 ( V_20 -> V_23 ) , V_76 -> V_189 ) ;
}
static void F_113 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned long V_102 ;
F_70 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( F_114 ( & V_20 -> V_75 ) && ! V_20 -> V_82 )
F_63 ( V_20 ) ;
F_72 ( & V_20 -> V_75 . V_104 , V_102 ) ;
}
static T_2 F_115 ( struct V_77 * V_82 )
{
bool V_46 = V_82 -> V_119 == V_130 ;
struct V_111 * V_91 = V_82 -> V_91 ;
T_1 V_191 , V_192 ;
int V_8 ;
V_192 = F_46 ( V_82 -> V_20 -> V_2 , V_82 -> V_20 -> V_21 [ 0 ] , V_46 ) ;
if ( V_82 -> V_99 ) {
V_191 = V_192 - V_91 -> V_129 ;
V_82 -> V_148 = V_82 -> V_146 - V_191 ;
return V_82 -> V_148 ;
}
V_91 += V_82 -> V_160 ;
for ( V_8 = V_82 -> V_160 ; V_8 < V_82 -> V_88 ; V_8 ++ , V_91 ++ ) {
if ( V_192 >= V_91 -> V_129 && V_192 < V_91 -> V_129 + V_91 -> V_13 )
return V_82 -> V_148 - ( V_192 - V_91 -> V_129 ) ;
V_82 -> V_160 ++ ;
V_82 -> V_148 -= V_91 -> V_13 ;
}
return V_82 -> V_148 ;
}
static enum V_193 F_116 ( struct V_73 * V_76 ,
T_5 V_194 ,
struct V_195 * V_196 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_81 * V_80 ;
enum V_193 V_141 ;
unsigned long V_102 ;
V_141 = F_117 ( V_76 , V_194 , V_196 ) ;
if ( V_141 == V_197 || ! V_196 )
return V_141 ;
F_70 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( V_20 -> V_82 && V_20 -> V_82 -> V_80 . V_79 . V_194 == V_194 )
V_196 -> V_146 = F_115 ( V_20 -> V_82 ) ;
else if ( ( V_80 = F_118 ( & V_20 -> V_75 , V_194 ) ) )
V_196 -> V_146 = F_60 ( & V_80 -> V_79 ) -> V_146 ;
F_72 ( & V_20 -> V_75 . V_104 , V_102 ) ;
return V_141 ;
}
static bool F_119 ( int V_23 , T_6 * V_198 )
{
if ( ! V_198 )
return false ;
while ( * V_198 != - 1 ) {
if ( * V_198 == V_23 )
return true ;
V_198 ++ ;
}
return false ;
}
static void F_120 ( struct V_1 * V_2 , bool V_199 )
{
struct V_70 * V_200 = & V_2 -> V_72 ;
struct V_70 * V_201 = NULL ;
T_6 * V_198 = V_2 -> V_186 -> V_198 ;
int V_8 , V_9 ;
F_121 ( V_200 -> V_202 ) ;
F_122 ( V_203 , V_200 -> V_202 ) ;
F_122 ( V_204 , V_200 -> V_202 ) ;
if ( V_2 -> V_199 && ! V_198 ) {
F_45 ( V_2 -> V_44 ,
L_48 ) ;
F_122 ( V_205 , V_200 -> V_202 ) ;
V_200 -> V_206 = F_87 ;
V_200 -> V_207 = F_31 ( V_131 ) ;
}
V_200 -> V_208 = F_80 ;
V_200 -> V_209 = F_89 ;
V_200 -> V_210 = F_110 ;
V_200 -> V_211 = F_111 ;
V_200 -> V_212 = F_113 ;
V_200 -> V_213 = F_116 ;
V_200 -> V_214 = F_74 ;
V_200 -> V_215 = F_75 ;
V_200 -> V_216 = F_76 ;
V_200 -> V_217 = F_68 ;
V_200 -> V_218 = V_219 ;
V_200 -> V_220 = V_219 ;
V_200 -> V_207 |= ( F_31 ( V_130 ) | F_31 ( V_128 ) ) ;
V_200 -> V_221 = V_222 ;
V_200 -> V_44 = V_2 -> V_44 ;
F_123 ( & V_200 -> V_223 ) ;
if ( V_198 ) {
V_201 = F_124 ( V_2 -> V_44 , sizeof( * V_201 ) , V_224 ) ;
V_2 -> V_225 = V_201 ;
F_121 ( V_201 -> V_202 ) ;
F_122 ( V_205 , V_201 -> V_202 ) ;
V_201 -> V_206 = F_87 ;
V_201 -> V_210 = F_110 ;
V_201 -> V_211 = F_111 ;
V_201 -> V_212 = F_113 ;
V_201 -> V_213 = F_116 ;
V_201 -> V_214 = F_74 ;
V_201 -> V_215 = F_75 ;
V_201 -> V_216 = F_76 ;
V_201 -> V_217 = F_68 ;
V_201 -> V_218 = V_219 ;
V_201 -> V_220 = V_219 ;
V_201 -> V_207 = F_31 ( V_131 ) ;
V_201 -> V_221 = V_222 ;
V_201 -> V_44 = V_2 -> V_44 ;
F_123 ( & V_201 -> V_223 ) ;
} else if ( ! V_2 -> V_199 ) {
F_125 ( V_2 -> V_44 , L_49 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
struct V_19 * V_20 = & V_2 -> V_170 [ V_8 ] ;
V_20 -> V_23 = F_40 ( V_2 -> V_41 , V_8 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> V_75 . V_226 = F_61 ;
if ( V_201 && F_119 ( V_8 , V_198 ) )
F_126 ( & V_20 -> V_75 , V_201 ) ;
else
F_126 ( & V_20 -> V_75 , V_200 ) ;
F_123 ( & V_20 -> V_86 ) ;
for ( V_9 = 0 ; V_9 < V_190 ; V_9 ++ )
V_20 -> V_21 [ V_9 ] = - 1 ;
}
}
static int F_127 ( struct V_83 * V_44 , struct V_227 * V_228 ,
struct V_1 * V_2 )
{
int V_8 ;
T_2 V_229 , V_230 ;
F_128 ( * V_231 ) [ 2 ] ;
V_230 = F_1 ( V_2 , V_232 ) ;
V_229 = F_129 ( V_230 ) ;
V_2 -> V_233 = F_31 ( V_229 ) ;
V_229 = F_130 ( V_230 ) ;
V_2 -> V_34 = F_31 ( V_229 + 1 ) ;
V_229 = F_131 ( V_230 ) ;
V_2 -> V_234 = V_229 * 2 ;
V_229 = F_132 ( V_230 ) ;
V_2 -> V_32 = F_31 ( V_229 + 4 ) ;
V_229 = F_133 ( V_230 ) ;
V_2 -> V_67 = V_229 + 1 ;
V_2 -> V_24 = ( V_230 & V_235 ) ? true : false ;
F_48 ( V_44 , L_50 , V_230 ) ;
F_48 ( V_44 , L_51 , V_2 -> V_233 ) ;
F_48 ( V_44 , L_52 , V_2 -> V_34 ) ;
F_48 ( V_44 , L_53 , V_2 -> V_234 ) ;
F_48 ( V_44 , L_54 , V_2 -> V_32 ) ;
F_48 ( V_44 , L_55 , V_2 -> V_67 ) ;
F_48 ( V_44 , L_56 , V_2 -> V_24 ? L_57 : L_58 ) ;
if ( V_228 -> V_236 )
return 0 ;
V_231 = F_134 ( V_44 , V_2 -> V_67 + 1 , sizeof( F_128 ) ,
V_224 ) ;
if ( ! V_231 )
return - V_37 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_67 ; V_8 ++ ) {
V_231 [ V_8 ] [ 0 ] = V_8 ;
V_231 [ V_8 ] [ 1 ] = V_8 ;
}
V_231 [ V_8 ] [ 0 ] = - 1 ;
V_231 [ V_8 ] [ 1 ] = - 1 ;
V_228 -> V_236 = V_231 ;
V_228 -> V_66 = V_8 - 1 ;
return 0 ;
}
static int F_135 ( struct V_83 * V_44 , struct V_227 * V_228 ,
T_3 V_237 )
{
const char V_238 [] = L_59 ;
struct V_239 V_240 ;
void T_7 * V_241 ;
F_136 ( * V_242 ) [ 2 ] ;
T_3 V_243 = V_237 / sizeof( F_136 ) ;
T_2 V_244 , V_3 , V_245 ;
int V_141 , V_8 ;
V_242 = F_134 ( V_44 , V_243 + 2 , sizeof( F_136 ) , V_224 ) ;
if ( ! V_242 )
return - V_37 ;
V_141 = F_137 ( V_44 -> V_246 , 1 , & V_240 ) ;
if ( V_141 )
return - V_37 ;
V_241 = F_138 ( V_44 , V_240 . V_247 , F_139 ( & V_240 ) ) ;
if ( ! V_241 )
return - V_37 ;
V_141 = F_140 ( V_44 -> V_246 , V_238 , ( V_248 * ) V_242 ,
V_243 ) ;
if ( V_141 )
return - V_249 ;
V_243 >>= 1 ;
V_242 [ V_243 ] [ 0 ] = - 1 ;
V_242 [ V_243 ] [ 1 ] = - 1 ;
for ( V_8 = 0 ; V_8 < V_243 ; V_8 ++ ) {
V_244 = ( V_242 [ V_8 ] [ 1 ] & 0x03 ) << 3 ;
V_3 = V_242 [ V_8 ] [ 1 ] & 0xfffffffc ;
V_245 = F_141 ( V_241 + V_3 ) ;
V_245 &= ~ ( 0xff << V_244 ) ;
V_245 |= V_242 [ V_8 ] [ 0 ] << V_244 ;
F_142 ( V_245 , ( V_241 + V_3 ) ) ;
}
V_228 -> V_242 = ( const F_136 ( * ) [ 2 ] ) V_242 ;
return 0 ;
}
static struct V_227 * F_143 ( struct V_83 * V_44 ,
bool V_199 )
{
struct V_227 * V_186 ;
struct V_250 * V_251 ;
T_3 V_237 ;
int V_141 ;
V_186 = F_124 ( V_44 , sizeof( struct V_227 ) , V_224 ) ;
if ( ! V_186 )
return F_144 ( - V_37 ) ;
if ( V_199 ) {
V_251 = F_145 ( V_44 -> V_246 , L_59 ,
& V_237 ) ;
if ( V_251 ) {
V_141 = F_135 ( V_44 , V_186 , V_237 ) ;
if ( V_141 )
return F_144 ( V_141 ) ;
}
return V_186 ;
}
V_251 = F_145 ( V_44 -> V_246 , L_60 , & V_237 ) ;
if ( V_251 ) {
const char V_238 [] = L_60 ;
T_3 V_243 = V_237 / sizeof( T_6 ) ;
T_6 * V_252 ;
V_252 = F_134 ( V_44 , V_243 + 1 , sizeof( T_6 ) ,
V_224 ) ;
if ( ! V_252 )
return F_144 ( - V_37 ) ;
V_141 = F_146 ( V_44 -> V_246 , V_238 ,
( T_2 * ) V_252 , V_243 ) ;
if ( V_141 )
return F_144 ( V_141 ) ;
V_252 [ V_243 ] = - 1 ;
V_186 -> V_198 = V_252 ;
}
V_251 = F_145 ( V_44 -> V_246 , L_61 ,
& V_237 ) ;
if ( V_251 ) {
const char V_238 [] = L_61 ;
T_2 ( * V_253 ) [ 2 ] ;
F_136 ( * V_254 ) [ 2 ] ;
T_3 V_243 = V_237 / sizeof( * V_253 ) ;
struct V_255 * V_256 ;
int V_8 ;
if ( ! V_243 )
return V_186 ;
V_253 = F_147 ( V_243 , sizeof( * V_253 ) , V_224 ) ;
if ( ! V_253 )
return F_144 ( - V_37 ) ;
V_256 = F_124 ( V_44 , sizeof( * V_256 ) , V_224 ) ;
if ( ! V_256 ) {
F_62 ( V_253 ) ;
return F_144 ( - V_37 ) ;
}
V_254 = F_134 ( V_44 , V_243 + 1 , sizeof( * V_254 ) ,
V_224 ) ;
if ( ! V_254 ) {
F_62 ( V_253 ) ;
return F_144 ( - V_37 ) ;
}
V_141 = F_146 ( V_44 -> V_246 , V_238 ,
( T_2 * ) V_253 , V_243 * 2 ) ;
if ( V_141 ) {
F_62 ( V_253 ) ;
return F_144 ( V_141 ) ;
}
for ( V_8 = 0 ; V_8 < V_243 ; V_8 ++ ) {
V_254 [ V_8 ] [ 0 ] = V_253 [ V_8 ] [ 0 ] ;
V_254 [ V_8 ] [ 1 ] = V_253 [ V_8 ] [ 1 ] ;
}
V_254 [ V_243 ] [ 0 ] = - 1 ;
V_254 [ V_243 ] [ 1 ] = - 1 ;
V_186 -> V_257 = V_256 ;
V_186 -> V_257 -> V_254 = ( const F_136 ( * ) [ 2 ] ) V_254 ;
F_62 ( V_253 ) ;
}
return V_186 ;
}
static struct V_73 * F_148 ( struct V_258 * V_259 ,
struct V_260 * V_261 )
{
struct V_1 * V_2 = V_261 -> V_262 ;
struct V_73 * V_76 = NULL ;
struct V_19 * V_20 ;
int V_8 ;
if ( ! V_2 || V_259 -> V_263 < 1 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
V_20 = & V_2 -> V_170 [ V_8 ] ;
if ( V_20 -> V_23 == V_259 -> args [ 0 ] ) {
V_76 = & V_20 -> V_75 . V_76 ;
break;
}
}
if ( ! V_76 )
return NULL ;
if ( V_20 -> V_2 -> V_199 && V_259 -> V_263 == 1 )
goto V_264;
if ( ! V_20 -> V_2 -> V_199 && V_259 -> V_263 == 2 &&
V_259 -> args [ 1 ] < V_20 -> V_2 -> V_67 ) {
V_20 -> V_105 = & V_20 -> V_2 -> V_185 [ V_259 -> args [ 1 ] ] ;
goto V_264;
}
return NULL ;
V_264:
V_20 -> V_51 = true ;
return F_149 ( V_76 ) ;
}
static struct V_227 * F_143 ( struct V_83 * V_44 ,
bool V_199 )
{
return F_144 ( - V_38 ) ;
}
static struct V_73 * F_148 ( struct V_258 * V_259 ,
struct V_260 * V_261 )
{
return NULL ;
}
static int F_150 ( struct V_182 * V_265 )
{
struct V_227 * V_186 = V_265 -> V_44 . V_266 ;
F_128 ( * V_236 ) [ 2 ] ;
int V_8 , V_267 , V_268 ;
const F_136 ( * V_254 ) [ 2 ] ;
const F_136 ( * V_242 ) [ 2 ] ;
int V_161 ;
char * V_269 ;
struct V_239 * V_270 ;
struct V_271 * V_86 = V_265 -> V_44 . V_246 ;
struct V_83 * V_44 = & V_265 -> V_44 ;
struct V_1 * V_2 ;
bool V_199 = true ;
int V_141 ;
if ( V_86 ) {
const struct V_272 * V_273 ;
V_273 = F_151 ( V_274 , V_86 ) ;
if ( V_273 && ( T_2 ) V_273 -> V_162 == V_275 )
V_199 = false ;
V_186 = F_143 ( V_44 , V_199 ) ;
if ( F_152 ( V_186 ) ) {
F_78 ( V_44 , L_62 ) ;
return F_153 ( V_186 ) ;
}
}
if ( ! V_186 )
return - V_276 ;
F_106 ( V_44 ) ;
V_141 = F_107 ( V_44 ) ;
if ( V_141 < 0 ) {
F_78 ( V_44 , L_63 ) ;
return V_141 ;
}
V_141 = F_154 ( V_44 , F_155 ( 32 ) ) ;
if ( V_141 )
return V_141 ;
V_2 = F_124 ( V_44 , sizeof( * V_2 ) , V_224 ) ;
if ( ! V_2 ) {
F_78 ( V_44 , L_64 ) ;
return - V_37 ;
}
V_2 -> V_44 = V_44 ;
V_2 -> V_41 = V_265 -> V_41 ;
V_2 -> V_199 = V_199 ;
if ( V_2 -> V_41 < 0 )
V_2 -> V_41 = 0 ;
V_270 = F_156 ( V_265 , V_277 , L_65 ) ;
if ( ! V_270 ) {
F_48 ( V_44 , L_66 ) ;
V_270 = F_157 ( V_265 , V_277 , 0 ) ;
if ( ! V_270 ) {
F_78 ( V_44 , L_67 ) ;
return - V_276 ;
}
}
V_2 -> V_4 = F_158 ( V_44 , V_270 ) ;
if ( F_152 ( V_2 -> V_4 ) )
return F_153 ( V_2 -> V_4 ) ;
F_159 ( V_265 , V_2 ) ;
V_141 = F_127 ( V_44 , V_186 , V_2 ) ;
if ( V_141 )
return V_141 ;
V_2 -> V_170 = F_134 ( V_44 , V_2 -> V_34 ,
sizeof( * V_2 -> V_170 ) , V_224 ) ;
if ( ! V_2 -> V_170 )
return - V_37 ;
V_2 -> V_36 = F_134 ( V_44 , F_160 ( V_2 -> V_32 ) ,
sizeof( unsigned long ) , V_224 ) ;
if ( ! V_2 -> V_36 )
return - V_37 ;
V_2 -> V_66 = V_186 -> V_66 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_32 ; V_8 ++ )
F_32 ( V_2 , V_8 , & V_40 ) ;
if ( V_186 -> V_257 ) {
V_254 = V_186 -> V_257 -> V_254 ;
if ( V_254 ) {
for ( V_8 = 0 ; V_254 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ ) {
V_267 = V_254 [ V_8 ] [ 0 ] ;
V_268 = V_254 [ V_8 ] [ 1 ] ;
F_23 ( V_267 , V_268 , V_2 -> V_36 ) ;
}
}
}
V_242 = V_186 -> V_242 ;
if ( V_242 ) {
for ( V_8 = 0 ; V_242 [ V_8 ] [ 1 ] != - 1 ; V_8 ++ ) {
V_267 = V_242 [ V_8 ] [ 1 ] ;
}
}
V_161 = F_161 ( V_265 , L_68 ) ;
if ( V_161 < 0 && V_86 )
V_161 = F_162 ( V_86 , 0 ) ;
if ( V_161 >= 0 ) {
V_269 = F_163 ( V_44 , V_224 , L_69 ,
F_109 ( V_44 ) ) ;
V_141 = F_164 ( V_44 , V_161 , F_95 , 0 , V_269 ,
V_2 ) ;
if ( V_141 ) {
F_78 ( V_44 , L_70 , V_161 , V_141 ) ;
return V_141 ;
}
}
V_161 = F_161 ( V_265 , L_71 ) ;
if ( V_161 < 0 && V_86 )
V_161 = F_162 ( V_86 , 2 ) ;
if ( V_161 >= 0 ) {
V_269 = F_163 ( V_44 , V_224 , L_72 ,
F_109 ( V_44 ) ) ;
V_141 = F_164 ( V_44 , V_161 , F_99 , 0 , V_269 ,
V_2 ) ;
if ( V_141 ) {
F_78 ( V_44 , L_73 , V_161 , V_141 ) ;
return V_141 ;
}
}
V_2 -> V_100 = F_37 ( V_2 , V_35 ) ;
if ( V_2 -> V_100 < 0 ) {
F_78 ( V_44 , L_74 ) ;
return V_2 -> V_100 ;
}
V_236 = V_186 -> V_236 ;
if ( ! V_2 -> V_199 ) {
int V_278 = 0 ;
struct V_258 V_279 ;
V_2 -> V_185 = F_134 ( V_44 , V_2 -> V_67 ,
sizeof( * V_2 -> V_185 ) , V_224 ) ;
if ( ! V_2 -> V_185 )
return - V_37 ;
for ( V_8 = 0 ; ; V_8 ++ ) {
V_141 = F_165 ( V_86 , L_75 ,
1 , V_8 , & V_279 ) ;
if ( V_141 || V_8 == V_2 -> V_67 )
break;
V_2 -> V_185 [ V_8 ] . V_86 = V_279 . V_280 ;
V_2 -> V_185 [ V_8 ] . V_41 = V_8 ;
V_236 [ V_8 ] [ 1 ] = V_279 . args [ 0 ] ;
if ( V_236 [ V_8 ] [ 1 ] > V_278 ) {
V_278 = V_236 [ V_8 ] [ 1 ] ;
V_186 -> V_66 = V_8 ;
}
}
}
for ( V_8 = 0 ; V_236 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_27 ( V_2 , V_236 [ V_8 ] [ 0 ] ,
V_236 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_233 ; V_8 ++ ) {
F_13 ( V_2 , V_69 , V_8 , 0 , 0x0 ) ;
F_13 ( V_2 , V_69 , V_8 , 1 , 0x0 ) ;
F_9 ( V_2 , V_281 , V_8 , 0x0 ) ;
}
V_2 -> V_186 = V_186 ;
F_120 ( V_2 , V_199 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
F_54 ( & V_2 -> V_170 [ V_8 ] ,
V_186 -> V_66 ) ;
F_28 ( & V_2 -> V_170 [ V_8 ] , V_2 -> V_100 ) ;
}
V_141 = F_166 ( & V_2 -> V_72 ) ;
if ( V_141 ) {
F_78 ( V_44 , L_76 , V_141 ) ;
goto V_282;
}
if ( V_2 -> V_225 ) {
V_141 = F_166 ( V_2 -> V_225 ) ;
if ( V_141 ) {
F_78 ( V_44 , L_77 ,
V_141 ) ;
F_167 ( & V_2 -> V_72 ) ;
goto V_282;
}
}
if ( V_86 )
F_168 ( V_86 , F_148 , V_2 ) ;
F_125 ( V_44 , L_78 ) ;
return 0 ;
V_282:
F_41 ( V_2 , V_2 -> V_100 ) ;
return V_141 ;
}
static int F_169 ( struct V_182 * V_265 )
{
struct V_83 * V_44 = & V_265 -> V_44 ;
struct V_1 * V_2 = F_170 ( V_44 ) ;
if ( V_44 -> V_246 )
F_171 ( V_44 -> V_246 ) ;
F_167 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_225 )
F_167 ( V_2 -> V_225 ) ;
F_41 ( V_2 , V_2 -> V_100 ) ;
return 0 ;
}
static int F_172 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_170 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_170 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_188 ) {
F_30 ( & V_20 [ V_8 ] , false ) ;
F_101 ( V_20 [ V_8 ] . V_105 , false ) ;
}
}
return 0 ;
}
static int F_173 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_170 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_170 ;
int V_8 ;
F_128 ( * V_236 ) [ 2 ] ;
V_236 = V_2 -> V_186 -> V_236 ;
for ( V_8 = 0 ; V_236 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_27 ( V_2 , V_236 [ V_8 ] [ 0 ] ,
V_236 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_188 ) {
F_12 ( V_2 , V_69 , 0 , V_8 >> 5 ,
F_31 ( V_8 & 0x1f ) ) ;
F_30 ( & V_20 [ V_8 ] , true ) ;
F_28 ( & V_20 [ V_8 ] , V_20 [ V_8 ] . V_21 [ 0 ] ) ;
F_101 ( V_20 [ V_8 ] . V_105 , true ) ;
}
}
return 0 ;
}
bool F_174 ( struct V_73 * V_76 , void * V_31 )
{
bool V_273 = false ;
if ( V_76 -> V_83 -> V_44 -> V_283 == & V_284 . V_283 ) {
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned V_285 = * ( unsigned * ) V_31 ;
if ( V_285 == V_20 -> V_23 ) {
V_20 -> V_51 = true ;
V_273 = true ;
}
}
return V_273 ;
}
static int F_175 ( void )
{
int V_141 ;
V_141 = F_176 ( & V_286 ) ;
if ( V_141 )
return V_141 ;
return F_176 ( & V_284 ) ;
}
static void T_8 F_177 ( void )
{
F_178 ( & V_284 ) ;
F_178 ( & V_286 ) ;
}
