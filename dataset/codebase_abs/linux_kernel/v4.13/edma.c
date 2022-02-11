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
static void F_25 ( struct V_1 * V_2 , int V_15 ,
int V_16 )
{
int V_17 = V_15 * 4 ;
F_5 ( V_2 , V_18 , ~ ( 0x7 << V_17 ) , ( ( V_16 & 0x7 ) << V_17 ) ) ;
}
static void F_26 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
if ( V_2 -> V_24 ) {
V_21 = F_27 ( V_21 ) ;
F_9 ( V_2 , V_25 , V_22 , ( V_21 << 5 ) ) ;
}
}
static void F_28 ( struct V_19 * V_20 , bool V_26 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
if ( V_26 ) {
F_17 ( V_2 , V_27 , V_22 >> 5 ,
F_29 ( V_22 & 0x1f ) ) ;
F_17 ( V_2 , V_28 , V_22 >> 5 ,
F_29 ( V_22 & 0x1f ) ) ;
} else {
F_17 ( V_2 , V_29 , V_22 >> 5 ,
F_29 ( V_22 & 0x1f ) ) ;
}
}
static void F_30 ( struct V_1 * V_2 , unsigned V_21 ,
const struct V_30 * V_31 )
{
V_21 = F_27 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return;
F_31 ( V_2 -> V_4 + F_32 ( V_21 ) , V_31 , V_33 ) ;
}
static int F_33 ( struct V_1 * V_2 , unsigned V_21 ,
struct V_30 * V_31 )
{
V_21 = F_27 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return - V_34 ;
F_34 ( V_31 , V_2 -> V_4 + F_32 ( V_21 ) , V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 >= 0 ) {
V_21 = F_27 ( V_21 ) ;
if ( V_2 -> V_24 && V_21 < V_2 -> V_35 )
V_21 = V_36 ;
}
if ( V_21 < 0 ) {
if ( V_2 -> V_24 )
V_21 = 0 ;
else
V_21 = V_2 -> V_35 ;
for (; ; ) {
V_21 = F_36 ( V_2 -> V_37 ,
V_2 -> V_32 ,
V_21 ) ;
if ( V_21 == V_2 -> V_32 )
return - V_38 ;
if ( ! F_37 ( V_21 , V_2 -> V_37 ) )
break;
}
} else if ( V_21 >= V_2 -> V_32 ) {
return - V_34 ;
} else if ( F_37 ( V_21 , V_2 -> V_37 ) ) {
return - V_39 ;
}
F_30 ( V_2 , V_21 , & V_40 ) ;
return F_38 ( V_2 -> V_41 , V_21 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned V_21 )
{
V_21 = F_27 ( V_21 ) ;
if ( V_21 >= V_2 -> V_32 )
return;
F_30 ( V_2 , V_21 , & V_40 ) ;
F_40 ( V_21 , V_2 -> V_37 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_42 , unsigned V_43 )
{
if ( F_42 ( F_43 ( V_42 ) != F_43 ( V_43 ) ) )
F_44 ( V_2 -> V_44 , L_1 ) ;
V_42 = F_27 ( V_42 ) ;
V_43 = F_27 ( V_43 ) ;
if ( V_42 >= V_2 -> V_32 || V_43 >= V_2 -> V_32 )
return;
F_20 ( V_2 , V_45 , V_42 , 0xffff0000 ,
F_32 ( V_43 ) ) ;
}
static T_1 F_45 ( struct V_1 * V_2 , unsigned V_21 ,
bool V_46 )
{
T_2 V_47 ;
V_21 = F_27 ( V_21 ) ;
V_47 = F_32 ( V_21 ) ;
V_47 += V_46 ? V_48 : V_49 ;
return F_1 ( V_2 , V_47 ) ;
}
static void F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
if ( ! V_20 -> V_51 ) {
F_47 ( V_2 -> V_44 , L_2 , V_9 ,
F_15 ( V_2 , V_52 , V_9 ) ) ;
F_17 ( V_2 , V_52 , V_9 , V_50 ) ;
} else {
F_47 ( V_2 -> V_44 , L_3 , V_9 ,
F_15 ( V_2 , V_53 , V_9 ) ) ;
F_9 ( V_2 , V_54 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_17 ( V_2 , V_57 , V_9 , V_50 ) ;
F_47 ( V_2 -> V_44 , L_4 , V_9 ,
F_15 ( V_2 , V_58 , V_9 ) ) ;
}
}
static void F_48 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
F_17 ( V_2 , V_59 , V_9 , V_50 ) ;
F_17 ( V_2 , V_60 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_27 , V_9 , V_50 ) ;
F_47 ( V_2 -> V_44 , L_4 , V_9 ,
F_15 ( V_2 , V_58 , V_9 ) ) ;
}
static void F_49 ( struct V_19 * V_20 )
{
int V_22 = F_27 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
F_17 ( V_20 -> V_2 , V_59 , V_22 >> 5 , V_50 ) ;
}
static void F_50 ( struct V_19 * V_20 )
{
int V_22 = F_27 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
F_17 ( V_20 -> V_2 , V_57 , V_22 >> 5 , V_50 ) ;
}
static void F_51 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
F_17 ( V_2 , V_52 , ( V_22 >> 5 ) , V_50 ) ;
F_47 ( V_2 -> V_44 , L_2 , ( V_22 >> 5 ) ,
F_15 ( V_2 , V_52 , ( V_22 >> 5 ) ) ) ;
}
static void F_52 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
int V_9 = ( V_22 >> 5 ) ;
unsigned int V_50 = F_29 ( V_22 & 0x1f ) ;
F_47 ( V_2 -> V_44 , L_5 , V_9 , F_8 ( V_2 , V_61 , V_9 ) ) ;
F_17 ( V_2 , V_60 , V_9 , V_50 ) ;
F_9 ( V_2 , V_55 , V_9 , V_50 ) ;
F_17 ( V_2 , V_56 , V_9 , V_50 ) ;
F_3 ( V_2 , V_62 , F_29 ( 16 ) | F_29 ( 1 ) | F_29 ( 0 ) ) ;
}
static void F_53 ( struct V_19 * V_20 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
int V_17 = ( V_22 & 0x7 ) * 4 ;
if ( V_64 == V_65 )
V_64 = V_2 -> V_66 ;
if ( V_64 >= V_2 -> V_67 )
return;
V_64 &= 7 ;
F_10 ( V_2 , V_68 , ( V_22 >> 3 ) , ~ ( 0x7 << V_17 ) ,
V_64 << V_17 ) ;
}
static int F_54 ( struct V_19 * V_20 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
int V_22 = F_27 ( V_20 -> V_23 ) ;
F_12 ( V_2 , V_69 , 0 , V_22 >> 5 , F_29 ( V_22 & 0x1f ) ) ;
F_48 ( V_20 ) ;
F_28 ( V_20 , true ) ;
F_53 ( V_20 , V_64 ) ;
return 0 ;
}
static void F_55 ( struct V_19 * V_20 )
{
F_48 ( V_20 ) ;
F_28 ( V_20 , false ) ;
}
static inline struct V_1 * F_56 ( struct V_70 * V_71 )
{
return F_57 ( V_71 , struct V_1 , V_72 ) ;
}
static inline struct V_19 * F_58 ( struct V_73 * V_74 )
{
return F_57 ( V_74 , struct V_19 , V_75 . V_76 ) ;
}
static inline struct V_77 * F_59 ( struct V_78 * V_79 )
{
return F_57 ( V_79 , struct V_77 , V_80 . V_79 ) ;
}
static void F_60 ( struct V_81 * V_80 )
{
F_61 ( F_57 ( V_80 , struct V_77 , V_80 ) ) ;
}
static void F_62 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_81 * V_80 ;
struct V_77 * V_82 ;
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
int V_8 , V_9 , V_84 , V_85 ;
if ( ! V_20 -> V_82 ) {
V_80 = F_63 ( & V_20 -> V_75 ) ;
if ( ! V_80 )
return;
F_64 ( & V_80 -> V_86 ) ;
V_20 -> V_82 = F_59 ( & V_80 -> V_79 ) ;
}
V_82 = V_20 -> V_82 ;
V_84 = V_82 -> V_87 - V_82 -> V_88 ;
V_85 = F_65 ( V_89 , V_84 ) ;
V_82 -> V_90 = 0 ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
V_9 = V_8 + V_82 -> V_88 ;
F_30 ( V_2 , V_20 -> V_21 [ V_8 ] , & V_82 -> V_91 [ V_9 ] . V_31 ) ;
V_82 -> V_90 += V_82 -> V_91 [ V_9 ] . V_13 ;
F_66 ( V_44 ,
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
F_41 ( V_2 , V_20 -> V_21 [ V_8 ] , V_20 -> V_21 [ V_8 + 1 ] ) ;
}
V_82 -> V_88 += V_85 ;
if ( V_82 -> V_88 == V_82 -> V_87 ) {
if ( V_82 -> V_99 )
F_41 ( V_2 , V_20 -> V_21 [ V_85 - 1 ] , V_20 -> V_21 [ 1 ] ) ;
else
F_41 ( V_2 , V_20 -> V_21 [ V_85 - 1 ] ,
V_20 -> V_2 -> V_100 ) ;
}
if ( V_20 -> V_101 ) {
F_47 ( V_44 , L_17 , V_20 -> V_23 ) ;
F_52 ( V_20 ) ;
F_48 ( V_20 ) ;
F_46 ( V_20 ) ;
F_51 ( V_20 ) ;
V_20 -> V_101 = 0 ;
} else if ( V_82 -> V_88 <= V_89 ) {
F_47 ( V_44 , L_18 ,
V_20 -> V_23 ) ;
F_46 ( V_20 ) ;
} else {
F_47 ( V_44 , L_19 ,
V_20 -> V_23 , V_82 -> V_88 ) ;
F_50 ( V_20 ) ;
}
}
static int F_67 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
unsigned long V_102 ;
F_68 ( V_103 ) ;
F_69 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( V_20 -> V_82 ) {
F_48 ( V_20 ) ;
if ( ! V_20 -> V_105 && V_20 -> V_82 -> V_99 )
F_53 ( V_20 , V_65 ) ;
F_60 ( & V_20 -> V_82 -> V_80 ) ;
V_20 -> V_82 = NULL ;
}
F_70 ( & V_20 -> V_75 , & V_103 ) ;
F_71 ( & V_20 -> V_75 . V_104 , V_102 ) ;
F_72 ( & V_20 -> V_75 , & V_103 ) ;
return 0 ;
}
static void F_73 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
F_74 ( & V_20 -> V_75 ) ;
}
static int F_75 ( struct V_73 * V_76 ,
struct V_106 * V_107 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
if ( V_107 -> V_108 == V_109 ||
V_107 -> V_110 == V_109 )
return - V_34 ;
memcpy ( & V_20 -> V_107 , V_107 , sizeof( V_20 -> V_107 ) ) ;
return 0 ;
}
static int F_76 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
if ( ! V_20 -> V_82 )
return - V_34 ;
F_49 ( V_20 ) ;
return 0 ;
}
static int F_77 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
F_50 ( V_20 ) ;
return 0 ;
}
static int F_78 ( struct V_73 * V_76 , struct V_111 * V_112 ,
T_1 V_113 , T_1 V_114 , T_2 V_115 ,
unsigned int V_116 , unsigned int V_117 ,
enum V_118 V_119 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
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
F_79 ( V_44 , L_20 ) ;
return - V_34 ;
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
F_79 ( V_44 , L_21 , V_132 ) ;
return - V_34 ;
}
V_31 -> V_92 = F_80 ( F_27 ( V_20 -> V_23 ) ) ;
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
static struct V_78 * F_81 (
struct V_73 * V_76 , struct V_134 * V_135 ,
unsigned int V_90 , enum V_118 V_119 ,
unsigned long V_136 , void * V_137 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_77 * V_82 ;
T_1 V_113 = 0 , V_114 = 0 ;
enum V_138 V_139 ;
T_2 V_115 ;
struct V_134 * V_140 ;
int V_8 , V_85 , V_141 ;
if ( F_42 ( ! V_20 || ! V_135 || ! V_90 ) )
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
F_79 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_79 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
V_82 = F_82 ( sizeof( * V_82 ) + V_90 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_87 = V_90 ;
V_82 -> V_146 = 0 ;
V_82 -> V_119 = V_119 ;
V_82 -> V_20 = V_20 ;
V_85 = F_83 ( unsigned , V_89 , V_90 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
V_20 -> V_21 [ V_8 ] =
F_35 ( V_20 -> V_2 , V_36 ) ;
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
F_61 ( V_82 ) ;
F_79 ( V_44 , L_24 ,
V_132 ) ;
return NULL ;
}
}
}
F_84 (sgl, sg, sg_len, i) {
if ( V_119 == V_130 )
V_114 = F_85 ( V_140 ) ;
else
V_113 = F_85 ( V_140 ) ;
V_141 = F_78 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
V_114 , V_115 , V_139 ,
F_86 ( V_140 ) , V_119 ) ;
if ( V_141 < 0 ) {
F_61 ( V_82 ) ;
return NULL ;
}
V_82 -> V_126 = V_141 ;
V_82 -> V_146 += F_86 ( V_140 ) ;
if ( V_8 == V_90 - 1 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
else if ( ! ( ( V_8 + 1 ) % V_89 ) )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= ( V_147 | V_148 ) ;
}
V_82 -> V_149 = V_82 -> V_146 ;
return F_87 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_88 (
struct V_73 * V_76 , T_1 V_150 , T_1 V_93 ,
T_3 V_13 , unsigned long V_136 )
{
int V_141 , V_85 ;
struct V_77 * V_82 ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_19 * V_20 = F_58 ( V_76 ) ;
unsigned int V_151 , V_152 ;
if ( F_42 ( ! V_20 || ! V_13 ) )
return NULL ;
if ( V_13 < V_127 ) {
V_151 = V_13 ;
V_152 = V_13 ;
V_85 = 1 ;
} else {
V_151 = V_153 - 1 ;
V_152 = F_89 ( V_13 , V_151 ) ;
if ( F_42 ( V_152 == V_13 ) )
V_85 = 1 ;
else
V_85 = 2 ;
}
V_82 = F_82 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_87 = V_85 ;
V_82 -> V_146 = V_82 -> V_149 = V_13 ;
V_82 -> V_119 = V_131 ;
V_82 -> V_20 = V_20 ;
V_141 = F_78 ( V_76 , & V_82 -> V_91 [ 0 ] , V_93 , V_150 , 1 ,
V_151 , V_152 , V_131 ) ;
if ( V_141 < 0 ) {
F_61 ( V_82 ) ;
return NULL ;
}
V_82 -> V_126 = V_141 ;
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_154 ;
if ( V_85 == 1 ) {
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_147 ;
} else {
V_82 -> V_91 [ 0 ] . V_31 . V_92 |= V_155 ;
if ( V_20 -> V_21 [ 1 ] < 0 ) {
V_20 -> V_21 [ 1 ] = F_35 ( V_20 -> V_2 ,
V_36 ) ;
if ( V_20 -> V_21 [ 1 ] < 0 ) {
F_61 ( V_82 ) ;
F_79 ( V_44 , L_24 ,
V_132 ) ;
return NULL ;
}
}
V_150 += V_152 ;
V_93 += V_152 ;
V_152 = V_151 = V_13 % ( V_153 - 1 ) ;
V_141 = F_78 ( V_76 , & V_82 -> V_91 [ 1 ] , V_93 , V_150 , 1 ,
V_151 , V_152 , V_131 ) ;
if ( V_141 < 0 ) {
F_61 ( V_82 ) ;
return NULL ;
}
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_154 ;
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_147 ;
}
return F_87 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_90 (
struct V_73 * V_76 , T_1 V_156 , T_3 V_157 ,
T_3 V_158 , enum V_118 V_119 ,
unsigned long V_136 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_77 * V_82 ;
T_1 V_113 , V_114 ;
enum V_138 V_139 ;
bool V_159 = false ;
T_2 V_115 ;
int V_8 , V_141 , V_85 ;
if ( F_42 ( ! V_20 || ! V_157 || ! V_158 ) )
return NULL ;
if ( V_119 == V_130 ) {
V_113 = V_20 -> V_107 . V_113 ;
V_114 = V_156 ;
V_139 = V_20 -> V_107 . V_108 ;
V_115 = V_20 -> V_107 . V_142 ;
} else if ( V_119 == V_128 ) {
V_113 = V_156 ;
V_114 = V_20 -> V_107 . V_114 ;
V_139 = V_20 -> V_107 . V_110 ;
V_115 = V_20 -> V_107 . V_143 ;
} else {
F_79 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_79 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
if ( F_42 ( V_157 % V_158 ) ) {
F_79 ( V_44 , L_25 ) ;
return NULL ;
}
V_85 = ( V_157 / V_158 ) + 1 ;
if ( V_85 > V_89 ) {
if ( V_115 == V_158 ) {
V_158 = V_157 ;
V_85 = 2 ;
V_159 = true ;
} else {
return NULL ;
}
}
V_82 = F_82 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 )
return NULL ;
V_82 -> V_99 = 1 ;
V_82 -> V_87 = V_85 ;
V_82 -> V_146 = V_82 -> V_149 = V_157 ;
V_82 -> V_119 = V_119 ;
V_82 -> V_20 = V_20 ;
F_47 ( V_44 , L_26 ,
V_132 , V_20 -> V_23 , V_85 , V_158 , V_157 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
V_20 -> V_21 [ V_8 ] =
F_35 ( V_20 -> V_2 , V_36 ) ;
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
F_61 ( V_82 ) ;
F_79 ( V_44 , L_24 ,
V_132 ) ;
return NULL ;
}
}
if ( V_8 == V_85 - 1 ) {
memcpy ( & V_82 -> V_91 [ V_8 ] , & V_82 -> V_91 [ 0 ] ,
sizeof( V_82 -> V_91 [ 0 ] ) ) ;
break;
}
V_141 = F_78 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
V_114 , V_115 , V_139 , V_158 ,
V_119 ) ;
if ( V_141 < 0 ) {
F_61 ( V_82 ) ;
return NULL ;
}
if ( V_119 == V_130 )
V_114 += V_158 ;
else
V_113 += V_158 ;
F_66 ( V_44 , L_27 , V_132 , V_8 ) ;
F_66 ( V_44 ,
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
if ( V_136 & V_160 ) {
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
if ( V_159 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_161 ;
}
}
if ( ! V_20 -> V_105 )
F_53 ( V_20 , V_162 ) ;
return F_87 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static void F_91 ( struct V_19 * V_20 )
{
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_77 * V_82 ;
F_92 ( & V_20 -> V_75 . V_104 ) ;
V_82 = V_20 -> V_82 ;
if ( V_82 ) {
if ( V_82 -> V_99 ) {
F_93 ( & V_82 -> V_80 ) ;
F_94 ( & V_20 -> V_75 . V_104 ) ;
return;
} else if ( V_82 -> V_88 == V_82 -> V_87 ) {
V_82 -> V_146 = 0 ;
F_48 ( V_20 ) ;
F_95 ( & V_82 -> V_80 ) ;
V_20 -> V_82 = NULL ;
F_47 ( V_44 , L_28 ,
V_20 -> V_23 ) ;
} else {
F_47 ( V_44 , L_29 ,
V_20 -> V_23 ) ;
F_49 ( V_20 ) ;
V_82 -> V_146 -= V_82 -> V_90 ;
V_82 -> V_149 = V_82 -> V_146 ;
V_82 -> V_163 = V_82 -> V_88 ;
}
F_62 ( V_20 ) ;
}
F_94 ( & V_20 -> V_75 . V_104 ) ;
}
static T_4 F_96 ( int V_164 , void * V_165 )
{
struct V_1 * V_2 = V_165 ;
int V_166 ;
T_2 V_167 ;
T_2 V_168 ;
T_2 V_169 ;
V_166 = V_2 -> V_41 ;
if ( V_166 < 0 )
return V_170 ;
F_66 ( V_2 -> V_44 , L_30 ) ;
V_168 = F_15 ( V_2 , V_171 , 0 ) ;
if ( ! V_168 ) {
V_168 = F_15 ( V_2 , V_171 , 1 ) ;
if ( ! V_168 )
return V_170 ;
V_167 = F_15 ( V_2 , V_172 , 1 ) ;
V_169 = 1 ;
} else {
V_167 = F_15 ( V_2 , V_172 , 0 ) ;
V_169 = 0 ;
}
do {
T_2 V_21 ;
T_2 V_22 ;
V_21 = F_97 ( V_168 ) ;
V_168 &= ~ ( F_29 ( V_21 ) ) ;
if ( V_167 & F_29 ( V_21 ) ) {
V_22 = ( V_169 << 5 ) | V_21 ;
F_17 ( V_2 , V_27 , V_169 , F_29 ( V_21 ) ) ;
F_91 ( & V_2 -> V_173 [ V_22 ] ) ;
}
} while ( V_168 );
F_16 ( V_2 , V_174 , 1 ) ;
return V_175 ;
}
static void F_98 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_30 V_14 ;
int V_176 ;
if ( ! V_20 -> V_82 )
return;
F_92 ( & V_20 -> V_75 . V_104 ) ;
V_176 = F_33 ( V_2 , V_20 -> V_21 [ 0 ] , & V_14 ) ;
if ( V_176 || ( V_14 . V_94 == 0 && V_14 . V_95 == 0 ) ) {
F_47 ( V_44 , L_31 ) ;
V_20 -> V_101 = 1 ;
} else {
F_47 ( V_44 , L_32 ) ;
F_52 ( V_20 ) ;
F_48 ( V_20 ) ;
F_46 ( V_20 ) ;
F_51 ( V_20 ) ;
}
F_94 ( & V_20 -> V_75 . V_104 ) ;
}
static inline bool F_99 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 , V_61 , 0 ) ||
F_8 ( V_2 , V_61 , 1 ) ||
F_1 ( V_2 , V_177 ) || F_1 ( V_2 , V_178 ) )
return true ;
return false ;
}
static T_4 F_100 ( int V_164 , void * V_165 )
{
struct V_1 * V_2 = V_165 ;
int V_8 , V_9 ;
int V_166 ;
unsigned int V_179 = 0 ;
unsigned int V_5 ;
V_166 = V_2 -> V_41 ;
if ( V_166 < 0 )
return V_170 ;
F_66 ( V_2 -> V_44 , L_33 ) ;
if ( ! F_99 ( V_2 ) ) {
F_79 ( V_2 -> V_44 , L_34 ,
V_132 ) ;
F_3 ( V_2 , V_180 , 1 ) ;
return V_170 ;
}
while ( 1 ) {
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
unsigned long V_181 ;
V_5 = F_8 ( V_2 , V_61 , V_9 ) ;
if ( ! V_5 )
continue;
F_47 ( V_2 -> V_44 , L_35 , V_9 , V_5 ) ;
V_181 = V_5 ;
for ( V_8 = F_101 ( & V_181 , 32 , 0 ) ; V_8 < 32 ;
V_8 = F_101 ( & V_181 , 32 , V_8 + 1 ) ) {
int V_182 = ( V_9 << 5 ) + V_8 ;
F_9 ( V_2 , V_55 , V_9 , F_29 ( V_8 ) ) ;
F_17 ( V_2 , V_56 , V_9 ,
F_29 ( V_8 ) ) ;
F_98 ( & V_2 -> V_173 [ V_182 ] ) ;
}
}
V_5 = F_1 ( V_2 , V_177 ) ;
if ( V_5 ) {
F_47 ( V_2 -> V_44 , L_36 , V_5 ) ;
F_3 ( V_2 , V_183 , V_5 ) ;
F_16 ( V_2 , V_184 , V_5 ) ;
}
V_5 = F_1 ( V_2 , V_178 ) ;
if ( V_5 ) {
F_44 ( V_2 -> V_44 , L_37 , V_5 ) ;
F_3 ( V_2 , V_62 , V_5 ) ;
}
if ( ! F_99 ( V_2 ) )
break;
V_179 ++ ;
if ( V_179 > 10 )
break;
}
F_3 ( V_2 , V_180 , 1 ) ;
return V_175 ;
}
static int F_102 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
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
V_141 = F_54 ( V_20 , V_64 ) ;
if ( V_141 )
return V_141 ;
V_20 -> V_21 [ 0 ] = F_35 ( V_2 , V_20 -> V_23 ) ;
if ( V_20 -> V_21 [ 0 ] < 0 ) {
F_79 ( V_44 , L_38 ,
F_27 ( V_20 -> V_23 ) ) ;
V_141 = V_20 -> V_21 [ 0 ] ;
goto V_187;
}
F_26 ( V_20 , V_20 -> V_21 [ 0 ] ) ;
V_20 -> V_188 = true ;
F_47 ( V_44 , L_39 ,
F_27 ( V_20 -> V_23 ) , V_76 -> V_189 ,
V_20 -> V_51 ? L_40 : L_41 ) ;
return 0 ;
V_187:
F_55 ( V_20 ) ;
return V_141 ;
}
static void F_103 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
struct V_83 * V_44 = V_20 -> V_2 -> V_44 ;
int V_8 ;
F_48 ( V_20 ) ;
F_104 ( & V_20 -> V_75 ) ;
for ( V_8 = 0 ; V_8 < V_190 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] >= 0 ) {
F_39 ( V_20 -> V_2 , V_20 -> V_21 [ V_8 ] ) ;
V_20 -> V_21 [ V_8 ] = - 1 ;
}
}
F_26 ( V_20 , V_20 -> V_2 -> V_100 ) ;
if ( V_20 -> V_188 ) {
F_55 ( V_20 ) ;
V_20 -> V_188 = false ;
}
V_20 -> V_105 = NULL ;
V_20 -> V_51 = false ;
F_47 ( V_44 , L_42 ,
F_27 ( V_20 -> V_23 ) , V_76 -> V_189 ) ;
}
static void F_105 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
unsigned long V_102 ;
F_69 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( F_106 ( & V_20 -> V_75 ) && ! V_20 -> V_82 )
F_62 ( V_20 ) ;
F_71 ( & V_20 -> V_75 . V_104 , V_102 ) ;
}
static T_2 F_107 ( struct V_77 * V_82 )
{
bool V_46 = V_82 -> V_119 == V_130 ;
int V_191 = V_192 ;
struct V_19 * V_20 = V_82 -> V_20 ;
struct V_111 * V_91 = V_82 -> V_91 ;
T_1 V_193 , V_194 ;
int V_8 ;
V_194 = F_45 ( V_20 -> V_2 , V_20 -> V_21 [ 0 ] , V_46 ) ;
while ( F_1 ( V_20 -> V_2 , V_195 ) & V_196 ) {
if ( F_45 ( V_20 -> V_2 ,
V_20 -> V_21 [ 0 ] , V_46 ) != V_194 ) {
break;
}
if ( ! -- V_191 ) {
F_108 ( V_20 -> V_75 . V_76 . V_83 -> V_44 ,
L_43 ,
V_132 ) ;
break;
}
F_109 () ;
}
if ( V_82 -> V_99 ) {
V_193 = V_194 - V_91 -> V_129 ;
V_82 -> V_149 = V_82 -> V_146 - V_193 ;
return V_82 -> V_149 ;
}
V_91 += V_82 -> V_163 ;
for ( V_8 = V_82 -> V_163 ; V_8 < V_82 -> V_88 ; V_8 ++ , V_91 ++ ) {
if ( V_194 >= V_91 -> V_129 && V_194 < V_91 -> V_129 + V_91 -> V_13 )
return V_82 -> V_149 - ( V_194 - V_91 -> V_129 ) ;
V_82 -> V_163 ++ ;
V_82 -> V_149 -= V_91 -> V_13 ;
}
return V_82 -> V_149 ;
}
static enum V_197 F_110 ( struct V_73 * V_76 ,
T_5 V_198 ,
struct V_199 * V_200 )
{
struct V_19 * V_20 = F_58 ( V_76 ) ;
struct V_81 * V_80 ;
enum V_197 V_141 ;
unsigned long V_102 ;
V_141 = F_111 ( V_76 , V_198 , V_200 ) ;
if ( V_141 == V_201 || ! V_200 )
return V_141 ;
F_69 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( V_20 -> V_82 && V_20 -> V_82 -> V_80 . V_79 . V_198 == V_198 )
V_200 -> V_146 = F_107 ( V_20 -> V_82 ) ;
else if ( ( V_80 = F_112 ( & V_20 -> V_75 , V_198 ) ) )
V_200 -> V_146 = F_59 ( & V_80 -> V_79 ) -> V_146 ;
F_71 ( & V_20 -> V_75 . V_104 , V_102 ) ;
return V_141 ;
}
static bool F_113 ( int V_23 , T_6 * V_202 )
{
if ( ! V_202 )
return false ;
while ( * V_202 != - 1 ) {
if ( * V_202 == V_23 )
return true ;
V_202 ++ ;
}
return false ;
}
static void F_114 ( struct V_1 * V_2 , bool V_203 )
{
struct V_70 * V_204 = & V_2 -> V_72 ;
struct V_70 * V_205 = NULL ;
T_6 * V_202 = V_2 -> V_186 -> V_202 ;
int V_8 , V_9 ;
F_115 ( V_204 -> V_206 ) ;
F_116 ( V_207 , V_204 -> V_206 ) ;
F_116 ( V_208 , V_204 -> V_206 ) ;
if ( V_2 -> V_203 && ! V_202 ) {
F_44 ( V_2 -> V_44 ,
L_44 ) ;
F_116 ( V_209 , V_204 -> V_206 ) ;
V_204 -> V_210 = F_88 ;
V_204 -> V_211 = F_29 ( V_131 ) ;
}
V_204 -> V_212 = F_81 ;
V_204 -> V_213 = F_90 ;
V_204 -> V_214 = F_102 ;
V_204 -> V_215 = F_103 ;
V_204 -> V_216 = F_105 ;
V_204 -> V_217 = F_110 ;
V_204 -> V_218 = F_75 ;
V_204 -> V_219 = F_76 ;
V_204 -> V_220 = F_77 ;
V_204 -> V_221 = F_67 ;
V_204 -> V_222 = F_73 ;
V_204 -> V_223 = V_224 ;
V_204 -> V_225 = V_224 ;
V_204 -> V_211 |= ( F_29 ( V_130 ) | F_29 ( V_128 ) ) ;
V_204 -> V_226 = V_227 ;
V_204 -> V_44 = V_2 -> V_44 ;
F_117 ( & V_204 -> V_228 ) ;
if ( V_202 ) {
V_205 = F_118 ( V_2 -> V_44 , sizeof( * V_205 ) , V_229 ) ;
V_2 -> V_230 = V_205 ;
F_115 ( V_205 -> V_206 ) ;
F_116 ( V_209 , V_205 -> V_206 ) ;
V_205 -> V_210 = F_88 ;
V_205 -> V_214 = F_102 ;
V_205 -> V_215 = F_103 ;
V_205 -> V_216 = F_105 ;
V_205 -> V_217 = F_110 ;
V_205 -> V_218 = F_75 ;
V_205 -> V_219 = F_76 ;
V_205 -> V_220 = F_77 ;
V_205 -> V_221 = F_67 ;
V_205 -> V_222 = F_73 ;
V_205 -> V_223 = V_224 ;
V_205 -> V_225 = V_224 ;
V_205 -> V_211 = F_29 ( V_131 ) ;
V_205 -> V_226 = V_227 ;
V_205 -> V_44 = V_2 -> V_44 ;
F_117 ( & V_205 -> V_228 ) ;
} else if ( ! V_2 -> V_203 ) {
F_119 ( V_2 -> V_44 , L_45 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_35 ; V_8 ++ ) {
struct V_19 * V_20 = & V_2 -> V_173 [ V_8 ] ;
V_20 -> V_23 = F_38 ( V_2 -> V_41 , V_8 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> V_75 . V_231 = F_60 ;
if ( V_205 && F_113 ( V_8 , V_202 ) )
F_120 ( & V_20 -> V_75 , V_205 ) ;
else
F_120 ( & V_20 -> V_75 , V_204 ) ;
F_117 ( & V_20 -> V_86 ) ;
for ( V_9 = 0 ; V_9 < V_190 ; V_9 ++ )
V_20 -> V_21 [ V_9 ] = - 1 ;
}
}
static int F_121 ( struct V_83 * V_44 , struct V_232 * V_233 ,
struct V_1 * V_2 )
{
int V_8 ;
T_2 V_234 , V_235 ;
F_122 ( * V_236 ) [ 2 ] ;
V_235 = F_1 ( V_2 , V_237 ) ;
V_234 = F_123 ( V_235 ) ;
V_2 -> V_238 = F_29 ( V_234 ) ;
V_234 = F_124 ( V_235 ) ;
V_2 -> V_35 = F_29 ( V_234 + 1 ) ;
V_234 = F_125 ( V_235 ) ;
V_2 -> V_239 = V_234 * 2 ;
V_234 = F_126 ( V_235 ) ;
V_2 -> V_32 = F_29 ( V_234 + 4 ) ;
V_234 = F_127 ( V_235 ) ;
V_2 -> V_67 = V_234 + 1 ;
V_2 -> V_24 = ( V_235 & V_240 ) ? true : false ;
F_47 ( V_44 , L_46 , V_235 ) ;
F_47 ( V_44 , L_47 , V_2 -> V_238 ) ;
F_47 ( V_44 , L_48 , V_2 -> V_35 ) ;
F_47 ( V_44 , L_49 , V_2 -> V_239 ) ;
F_47 ( V_44 , L_50 , V_2 -> V_32 ) ;
F_47 ( V_44 , L_51 , V_2 -> V_67 ) ;
F_47 ( V_44 , L_52 , V_2 -> V_24 ? L_53 : L_54 ) ;
if ( V_233 -> V_241 )
return 0 ;
V_236 = F_128 ( V_44 , V_2 -> V_67 + 1 , sizeof( F_122 ) ,
V_229 ) ;
if ( ! V_236 )
return - V_38 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_67 ; V_8 ++ ) {
V_236 [ V_8 ] [ 0 ] = V_8 ;
V_236 [ V_8 ] [ 1 ] = V_8 ;
}
V_236 [ V_8 ] [ 0 ] = - 1 ;
V_236 [ V_8 ] [ 1 ] = - 1 ;
V_233 -> V_241 = V_236 ;
V_233 -> V_66 = V_8 - 1 ;
return 0 ;
}
static int F_129 ( struct V_83 * V_44 , struct V_232 * V_233 ,
T_3 V_242 )
{
const char V_243 [] = L_55 ;
struct V_244 V_245 ;
void T_7 * V_246 ;
F_130 ( * V_247 ) [ 2 ] ;
T_3 V_248 = V_242 / sizeof( F_130 ) ;
T_2 V_249 , V_3 , V_250 ;
int V_141 , V_8 ;
V_247 = F_128 ( V_44 , V_248 + 2 , sizeof( F_130 ) , V_229 ) ;
if ( ! V_247 )
return - V_38 ;
V_141 = F_131 ( V_44 -> V_251 , 1 , & V_245 ) ;
if ( V_141 )
return - V_38 ;
V_246 = F_132 ( V_44 , V_245 . V_252 , F_133 ( & V_245 ) ) ;
if ( ! V_246 )
return - V_38 ;
V_141 = F_134 ( V_44 -> V_251 , V_243 , ( V_253 * ) V_247 ,
V_248 ) ;
if ( V_141 )
return - V_254 ;
V_248 >>= 1 ;
V_247 [ V_248 ] [ 0 ] = - 1 ;
V_247 [ V_248 ] [ 1 ] = - 1 ;
for ( V_8 = 0 ; V_8 < V_248 ; V_8 ++ ) {
V_249 = ( V_247 [ V_8 ] [ 1 ] & 0x03 ) << 3 ;
V_3 = V_247 [ V_8 ] [ 1 ] & 0xfffffffc ;
V_250 = F_135 ( V_246 + V_3 ) ;
V_250 &= ~ ( 0xff << V_249 ) ;
V_250 |= V_247 [ V_8 ] [ 0 ] << V_249 ;
F_136 ( V_250 , ( V_246 + V_3 ) ) ;
}
V_233 -> V_247 = ( const F_130 ( * ) [ 2 ] ) V_247 ;
return 0 ;
}
static struct V_232 * F_137 ( struct V_83 * V_44 ,
bool V_203 )
{
struct V_232 * V_186 ;
struct V_255 * V_256 ;
int V_242 , V_141 ;
V_186 = F_118 ( V_44 , sizeof( struct V_232 ) , V_229 ) ;
if ( ! V_186 )
return F_138 ( - V_38 ) ;
if ( V_203 ) {
V_256 = F_139 ( V_44 -> V_251 , L_55 ,
& V_242 ) ;
if ( V_256 ) {
V_141 = F_129 ( V_44 , V_186 , V_242 ) ;
if ( V_141 )
return F_138 ( V_141 ) ;
}
return V_186 ;
}
V_256 = F_139 ( V_44 -> V_251 , L_56 , & V_242 ) ;
if ( V_256 ) {
const char V_243 [] = L_56 ;
T_3 V_248 = V_242 / sizeof( T_6 ) ;
T_6 * V_257 ;
V_257 = F_128 ( V_44 , V_248 + 1 , sizeof( T_6 ) ,
V_229 ) ;
if ( ! V_257 )
return F_138 ( - V_38 ) ;
V_141 = F_140 ( V_44 -> V_251 , V_243 ,
( T_2 * ) V_257 , V_248 ) ;
if ( V_141 )
return F_138 ( V_141 ) ;
V_257 [ V_248 ] = - 1 ;
V_186 -> V_202 = V_257 ;
}
V_256 = F_139 ( V_44 -> V_251 , L_57 ,
& V_242 ) ;
if ( V_256 ) {
const char V_243 [] = L_57 ;
T_2 ( * V_258 ) [ 2 ] ;
F_130 ( * V_259 ) [ 2 ] ;
T_3 V_248 = V_242 / sizeof( * V_258 ) ;
struct V_260 * V_261 ;
int V_8 ;
if ( ! V_248 )
return V_186 ;
V_258 = F_141 ( V_248 , sizeof( * V_258 ) , V_229 ) ;
if ( ! V_258 )
return F_138 ( - V_38 ) ;
V_261 = F_118 ( V_44 , sizeof( * V_261 ) , V_229 ) ;
if ( ! V_261 ) {
F_61 ( V_258 ) ;
return F_138 ( - V_38 ) ;
}
V_259 = F_128 ( V_44 , V_248 + 1 , sizeof( * V_259 ) ,
V_229 ) ;
if ( ! V_259 ) {
F_61 ( V_258 ) ;
return F_138 ( - V_38 ) ;
}
V_141 = F_140 ( V_44 -> V_251 , V_243 ,
( T_2 * ) V_258 , V_248 * 2 ) ;
if ( V_141 ) {
F_61 ( V_258 ) ;
return F_138 ( V_141 ) ;
}
for ( V_8 = 0 ; V_8 < V_248 ; V_8 ++ ) {
V_259 [ V_8 ] [ 0 ] = V_258 [ V_8 ] [ 0 ] ;
V_259 [ V_8 ] [ 1 ] = V_258 [ V_8 ] [ 1 ] ;
}
V_259 [ V_248 ] [ 0 ] = - 1 ;
V_259 [ V_248 ] [ 1 ] = - 1 ;
V_186 -> V_262 = V_261 ;
V_186 -> V_262 -> V_259 = ( const F_130 ( * ) [ 2 ] ) V_259 ;
F_61 ( V_258 ) ;
}
return V_186 ;
}
static struct V_73 * F_142 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = V_266 -> V_267 ;
struct V_73 * V_76 = NULL ;
struct V_19 * V_20 ;
int V_8 ;
if ( ! V_2 || V_264 -> V_268 < 1 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_2 -> V_35 ; V_8 ++ ) {
V_20 = & V_2 -> V_173 [ V_8 ] ;
if ( V_20 -> V_23 == V_264 -> args [ 0 ] ) {
V_76 = & V_20 -> V_75 . V_76 ;
break;
}
}
if ( ! V_76 )
return NULL ;
if ( V_20 -> V_2 -> V_203 && V_264 -> V_268 == 1 )
goto V_269;
if ( ! V_20 -> V_2 -> V_203 && V_264 -> V_268 == 2 &&
V_264 -> args [ 1 ] < V_20 -> V_2 -> V_67 ) {
V_20 -> V_105 = & V_20 -> V_2 -> V_185 [ V_264 -> args [ 1 ] ] ;
goto V_269;
}
return NULL ;
V_269:
V_20 -> V_51 = true ;
return F_143 ( V_76 ) ;
}
static struct V_232 * F_137 ( struct V_83 * V_44 ,
bool V_203 )
{
return F_138 ( - V_34 ) ;
}
static struct V_73 * F_142 ( struct V_263 * V_264 ,
struct V_265 * V_266 )
{
return NULL ;
}
static int F_144 ( struct V_270 * V_271 )
{
struct V_232 * V_186 = V_271 -> V_44 . V_272 ;
F_122 ( * V_241 ) [ 2 ] ;
int V_8 , V_273 , V_274 ;
const F_130 ( * V_259 ) [ 2 ] ;
const F_130 ( * V_247 ) [ 2 ] ;
int V_164 ;
char * V_275 ;
struct V_244 * V_276 ;
struct V_277 * V_86 = V_271 -> V_44 . V_251 ;
struct V_83 * V_44 = & V_271 -> V_44 ;
struct V_1 * V_2 ;
bool V_203 = true ;
int V_141 ;
if ( V_86 ) {
const struct V_278 * V_279 ;
V_279 = F_145 ( V_280 , V_86 ) ;
if ( V_279 && ( * ( T_2 * ) V_279 -> V_165 ) == V_281 )
V_203 = false ;
V_186 = F_137 ( V_44 , V_203 ) ;
if ( F_146 ( V_186 ) ) {
F_79 ( V_44 , L_58 ) ;
return F_147 ( V_186 ) ;
}
}
if ( ! V_186 )
return - V_282 ;
F_148 ( V_44 ) ;
V_141 = F_149 ( V_44 ) ;
if ( V_141 < 0 ) {
F_79 ( V_44 , L_59 ) ;
return V_141 ;
}
V_141 = F_150 ( V_44 , F_151 ( 32 ) ) ;
if ( V_141 )
return V_141 ;
V_2 = F_118 ( V_44 , sizeof( * V_2 ) , V_229 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_41 = V_271 -> V_41 ;
V_2 -> V_203 = V_203 ;
if ( V_2 -> V_41 < 0 )
V_2 -> V_41 = 0 ;
V_276 = F_152 ( V_271 , V_283 , L_60 ) ;
if ( ! V_276 ) {
F_47 ( V_44 , L_61 ) ;
V_276 = F_153 ( V_271 , V_283 , 0 ) ;
if ( ! V_276 ) {
F_79 ( V_44 , L_62 ) ;
return - V_282 ;
}
}
V_2 -> V_4 = F_154 ( V_44 , V_276 ) ;
if ( F_146 ( V_2 -> V_4 ) )
return F_147 ( V_2 -> V_4 ) ;
F_155 ( V_271 , V_2 ) ;
V_141 = F_121 ( V_44 , V_186 , V_2 ) ;
if ( V_141 )
return V_141 ;
V_2 -> V_173 = F_128 ( V_44 , V_2 -> V_35 ,
sizeof( * V_2 -> V_173 ) , V_229 ) ;
if ( ! V_2 -> V_173 )
return - V_38 ;
V_2 -> V_37 = F_128 ( V_44 , F_156 ( V_2 -> V_32 ) ,
sizeof( unsigned long ) , V_229 ) ;
if ( ! V_2 -> V_37 )
return - V_38 ;
V_2 -> V_66 = V_186 -> V_66 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_32 ; V_8 ++ )
F_30 ( V_2 , V_8 , & V_40 ) ;
if ( V_186 -> V_262 ) {
V_259 = V_186 -> V_262 -> V_259 ;
if ( V_259 ) {
for ( V_8 = 0 ; V_259 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ ) {
V_273 = V_259 [ V_8 ] [ 0 ] ;
V_274 = V_259 [ V_8 ] [ 1 ] ;
F_23 ( V_273 , V_274 , V_2 -> V_37 ) ;
}
}
}
V_247 = V_186 -> V_247 ;
if ( V_247 ) {
for ( V_8 = 0 ; V_247 [ V_8 ] [ 1 ] != - 1 ; V_8 ++ ) {
V_273 = V_247 [ V_8 ] [ 1 ] ;
}
}
V_164 = F_157 ( V_271 , L_63 ) ;
if ( V_164 < 0 && V_86 )
V_164 = F_158 ( V_86 , 0 ) ;
if ( V_164 >= 0 ) {
V_275 = F_159 ( V_44 , V_229 , L_64 ,
F_160 ( V_44 ) ) ;
V_141 = F_161 ( V_44 , V_164 , F_96 , 0 , V_275 ,
V_2 ) ;
if ( V_141 ) {
F_79 ( V_44 , L_65 , V_164 , V_141 ) ;
return V_141 ;
}
V_2 -> V_284 = V_164 ;
}
V_164 = F_157 ( V_271 , L_66 ) ;
if ( V_164 < 0 && V_86 )
V_164 = F_158 ( V_86 , 2 ) ;
if ( V_164 >= 0 ) {
V_275 = F_159 ( V_44 , V_229 , L_67 ,
F_160 ( V_44 ) ) ;
V_141 = F_161 ( V_44 , V_164 , F_100 , 0 , V_275 ,
V_2 ) ;
if ( V_141 ) {
F_79 ( V_44 , L_68 , V_164 , V_141 ) ;
return V_141 ;
}
V_2 -> V_285 = V_164 ;
}
V_2 -> V_100 = F_35 ( V_2 , V_36 ) ;
if ( V_2 -> V_100 < 0 ) {
F_79 ( V_44 , L_69 ) ;
return V_2 -> V_100 ;
}
V_241 = V_186 -> V_241 ;
if ( ! V_2 -> V_203 ) {
int V_286 = 0 ;
struct V_263 V_287 ;
V_2 -> V_185 = F_128 ( V_44 , V_2 -> V_67 ,
sizeof( * V_2 -> V_185 ) , V_229 ) ;
if ( ! V_2 -> V_185 )
return - V_38 ;
for ( V_8 = 0 ; ; V_8 ++ ) {
V_141 = F_162 ( V_86 , L_70 ,
1 , V_8 , & V_287 ) ;
if ( V_141 || V_8 == V_2 -> V_67 )
break;
V_2 -> V_185 [ V_8 ] . V_86 = V_287 . V_288 ;
V_2 -> V_185 [ V_8 ] . V_41 = V_8 ;
V_241 [ V_8 ] [ 1 ] = V_287 . args [ 0 ] ;
if ( V_241 [ V_8 ] [ 1 ] > V_286 ) {
V_286 = V_241 [ V_8 ] [ 1 ] ;
V_186 -> V_66 = V_8 ;
}
}
}
for ( V_8 = 0 ; V_241 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_25 ( V_2 , V_241 [ V_8 ] [ 0 ] ,
V_241 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_238 ; V_8 ++ ) {
F_13 ( V_2 , V_69 , V_8 , 0 , 0x0 ) ;
F_13 ( V_2 , V_69 , V_8 , 1 , 0x0 ) ;
F_9 ( V_2 , V_289 , V_8 , 0x0 ) ;
}
V_2 -> V_186 = V_186 ;
F_114 ( V_2 , V_203 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_35 ; V_8 ++ ) {
F_53 ( & V_2 -> V_173 [ V_8 ] ,
V_186 -> V_66 ) ;
F_26 ( & V_2 -> V_173 [ V_8 ] , V_2 -> V_100 ) ;
}
V_2 -> V_72 . V_290 . V_291 = V_186 -> V_292 ;
V_2 -> V_72 . V_290 . V_293 = V_186 -> V_294 ;
V_2 -> V_72 . V_290 . V_295 = V_296 ;
V_141 = F_163 ( & V_2 -> V_72 ) ;
if ( V_141 ) {
F_79 ( V_44 , L_71 , V_141 ) ;
goto V_297;
}
if ( V_2 -> V_230 ) {
V_141 = F_163 ( V_2 -> V_230 ) ;
if ( V_141 ) {
F_79 ( V_44 , L_72 ,
V_141 ) ;
F_164 ( & V_2 -> V_72 ) ;
goto V_297;
}
}
if ( V_86 )
F_165 ( V_86 , F_142 , V_2 ) ;
F_119 ( V_44 , L_73 ) ;
return 0 ;
V_297:
F_39 ( V_2 , V_2 -> V_100 ) ;
return V_141 ;
}
static void F_166 ( struct V_70 * V_298 )
{
struct V_19 * V_20 , * V_299 ;
F_167 (echan, _echan,
&dmadev->channels, vchan.chan.device_node) {
F_64 ( & V_20 -> V_75 . V_76 . V_277 ) ;
F_168 ( & V_20 -> V_75 . V_300 ) ;
}
}
static int F_169 ( struct V_270 * V_271 )
{
struct V_83 * V_44 = & V_271 -> V_44 ;
struct V_1 * V_2 = F_170 ( V_44 ) ;
F_171 ( V_44 , V_2 -> V_284 , V_2 ) ;
F_171 ( V_44 , V_2 -> V_285 , V_2 ) ;
F_166 ( & V_2 -> V_72 ) ;
if ( V_44 -> V_251 )
F_172 ( V_44 -> V_251 ) ;
F_164 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_230 )
F_164 ( V_2 -> V_230 ) ;
F_39 ( V_2 , V_2 -> V_100 ) ;
return 0 ;
}
static int F_173 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_170 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_173 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_35 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_188 )
F_28 ( & V_20 [ V_8 ] , false ) ;
}
return 0 ;
}
static int F_174 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_170 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_173 ;
int V_8 ;
F_122 ( * V_241 ) [ 2 ] ;
F_30 ( V_2 , V_2 -> V_100 , & V_40 ) ;
V_241 = V_2 -> V_186 -> V_241 ;
for ( V_8 = 0 ; V_241 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_25 ( V_2 , V_241 [ V_8 ] [ 0 ] ,
V_241 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_35 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_188 ) {
F_12 ( V_2 , V_69 , 0 , V_8 >> 5 ,
F_29 ( V_8 & 0x1f ) ) ;
F_28 ( & V_20 [ V_8 ] , true ) ;
F_26 ( & V_20 [ V_8 ] , V_20 [ V_8 ] . V_21 [ 0 ] ) ;
}
}
return 0 ;
}
static int F_175 ( struct V_270 * V_271 )
{
F_148 ( & V_271 -> V_44 ) ;
return F_149 ( & V_271 -> V_44 ) ;
}
bool V_296 ( struct V_73 * V_76 , void * V_31 )
{
bool V_279 = false ;
if ( V_76 -> V_83 -> V_44 -> V_301 == & V_302 . V_301 ) {
struct V_19 * V_20 = F_58 ( V_76 ) ;
unsigned V_303 = * ( unsigned * ) V_31 ;
if ( V_303 == V_20 -> V_23 ) {
V_20 -> V_51 = true ;
V_279 = true ;
}
}
return V_279 ;
}
static int F_176 ( void )
{
int V_141 ;
V_141 = F_177 ( & V_304 ) ;
if ( V_141 )
return V_141 ;
return F_177 ( & V_302 ) ;
}
static void T_8 F_178 ( void )
{
F_179 ( & V_302 ) ;
F_179 ( & V_304 ) ;
}
