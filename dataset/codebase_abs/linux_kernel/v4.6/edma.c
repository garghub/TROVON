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
if ( V_21 >= 0 ) {
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
static void F_74 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
F_75 ( & V_20 -> V_75 ) ;
}
static int F_76 ( struct V_73 * V_76 ,
struct V_106 * V_107 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
if ( V_107 -> V_108 == V_109 ||
V_107 -> V_110 == V_109 )
return - V_38 ;
memcpy ( & V_20 -> V_107 , V_107 , sizeof( V_20 -> V_107 ) ) ;
return 0 ;
}
static int F_77 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
if ( ! V_20 -> V_82 )
return - V_38 ;
F_50 ( V_20 ) ;
return 0 ;
}
static int F_78 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
F_51 ( V_20 ) ;
return 0 ;
}
static int F_79 ( struct V_73 * V_76 , struct V_111 * V_112 ,
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
F_80 ( V_44 , L_20 ) ;
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
F_80 ( V_44 , L_21 , V_132 ) ;
return - V_38 ;
}
V_31 -> V_92 = F_81 ( F_29 ( V_20 -> V_23 ) ) ;
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
static struct V_78 * F_82 (
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
F_80 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_80 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
V_82 = F_83 ( sizeof( * V_82 ) + V_90 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_80 ( V_44 , L_24 , V_132 ) ;
return NULL ;
}
V_82 -> V_87 = V_90 ;
V_82 -> V_146 = 0 ;
V_82 -> V_119 = V_119 ;
V_82 -> V_20 = V_20 ;
V_85 = F_84 ( unsigned , V_89 , V_90 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
V_20 -> V_21 [ V_8 ] =
F_37 ( V_20 -> V_2 , V_35 ) ;
if ( V_20 -> V_21 [ V_8 ] < 0 ) {
F_62 ( V_82 ) ;
F_80 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
}
F_85 (sgl, sg, sg_len, i) {
if ( V_119 == V_130 )
V_114 = F_86 ( V_140 ) ;
else
V_113 = F_86 ( V_140 ) ;
V_141 = F_79 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
V_114 , V_115 , V_139 ,
F_87 ( V_140 ) , V_119 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
V_82 -> V_126 = V_141 ;
V_82 -> V_146 += F_87 ( V_140 ) ;
if ( ! ( ( V_8 + 1 ) % V_89 ) )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
if ( V_8 == V_90 - 1 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
}
V_82 -> V_148 = V_82 -> V_146 ;
return F_88 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_89 (
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
V_151 = F_90 ( V_13 , V_150 ) ;
if ( F_43 ( V_151 == V_13 ) )
V_85 = 1 ;
else
V_85 = 2 ;
}
V_82 = F_83 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_48 ( V_44 , L_26 ) ;
return NULL ;
}
V_82 -> V_87 = V_85 ;
V_82 -> V_146 = V_82 -> V_148 = V_13 ;
V_82 -> V_119 = V_131 ;
V_82 -> V_20 = V_20 ;
V_141 = F_79 ( V_76 , & V_82 -> V_91 [ 0 ] , V_93 , V_149 , 1 ,
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
F_80 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
V_149 += V_151 ;
V_93 += V_151 ;
V_151 = V_150 = V_13 % ( V_152 - 1 ) ;
V_141 = F_79 ( V_76 , & V_82 -> V_91 [ 1 ] , V_93 , V_149 , 1 ,
V_150 , V_151 , V_131 ) ;
if ( V_141 < 0 ) {
F_62 ( V_82 ) ;
return NULL ;
}
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_153 ;
V_82 -> V_91 [ 1 ] . V_31 . V_92 |= V_147 ;
}
return F_88 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static struct V_78 * F_91 (
struct V_73 * V_76 , T_1 V_155 , T_3 V_156 ,
T_3 V_157 , enum V_118 V_119 ,
unsigned long V_136 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_76 -> V_83 -> V_44 ;
struct V_77 * V_82 ;
T_1 V_113 , V_114 ;
enum V_138 V_139 ;
bool V_158 = false ;
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
F_80 ( V_44 , L_22 , V_132 , V_119 ) ;
return NULL ;
}
if ( V_139 == V_144 ) {
F_80 ( V_44 , L_23 , V_132 ) ;
return NULL ;
}
if ( F_43 ( V_156 % V_157 ) ) {
F_80 ( V_44 , L_27 ) ;
return NULL ;
}
V_85 = ( V_156 / V_157 ) + 1 ;
if ( V_85 > V_89 ) {
if ( V_115 == V_157 ) {
V_157 = V_156 ;
V_85 = 2 ;
V_158 = true ;
} else {
return NULL ;
}
}
V_82 = F_83 ( sizeof( * V_82 ) + V_85 * sizeof( V_82 -> V_91 [ 0 ] ) ,
V_145 ) ;
if ( ! V_82 ) {
F_80 ( V_44 , L_24 , V_132 ) ;
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
F_80 ( V_44 , L_25 ,
V_132 ) ;
return NULL ;
}
}
if ( V_8 == V_85 - 1 ) {
memcpy ( & V_82 -> V_91 [ V_8 ] , & V_82 -> V_91 [ 0 ] ,
sizeof( V_82 -> V_91 [ 0 ] ) ) ;
break;
}
V_141 = F_79 ( V_76 , & V_82 -> V_91 [ V_8 ] , V_113 ,
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
if ( V_136 & V_159 ) {
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_147 ;
if ( V_158 )
V_82 -> V_91 [ V_8 ] . V_31 . V_92 |= V_160 ;
}
}
if ( ! V_20 -> V_105 )
F_54 ( V_20 , V_161 ) ;
return F_88 ( & V_20 -> V_75 , & V_82 -> V_80 , V_136 ) ;
}
static void F_92 ( struct V_19 * V_20 )
{
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_77 * V_82 ;
F_93 ( & V_20 -> V_75 . V_104 ) ;
V_82 = V_20 -> V_82 ;
if ( V_82 ) {
if ( V_82 -> V_99 ) {
F_94 ( & V_82 -> V_80 ) ;
F_95 ( & V_20 -> V_75 . V_104 ) ;
return;
} else if ( V_82 -> V_88 == V_82 -> V_87 ) {
V_82 -> V_146 = 0 ;
F_49 ( V_20 ) ;
F_96 ( & V_82 -> V_80 ) ;
V_20 -> V_82 = NULL ;
F_48 ( V_44 , L_30 ,
V_20 -> V_23 ) ;
} else {
F_48 ( V_44 , L_31 ,
V_20 -> V_23 ) ;
F_50 ( V_20 ) ;
V_82 -> V_146 -= V_82 -> V_90 ;
V_82 -> V_148 = V_82 -> V_146 ;
V_82 -> V_162 = V_82 -> V_88 ;
}
F_63 ( V_20 ) ;
}
F_95 ( & V_20 -> V_75 . V_104 ) ;
}
static T_4 F_97 ( int V_163 , void * V_164 )
{
struct V_1 * V_2 = V_164 ;
int V_165 ;
T_2 V_166 ;
T_2 V_167 ;
T_2 V_168 ;
V_165 = V_2 -> V_41 ;
if ( V_165 < 0 )
return V_169 ;
F_67 ( V_2 -> V_44 , L_32 ) ;
V_167 = F_15 ( V_2 , V_170 , 0 ) ;
if ( ! V_167 ) {
V_167 = F_15 ( V_2 , V_170 , 1 ) ;
if ( ! V_167 )
return V_169 ;
V_166 = F_15 ( V_2 , V_171 , 1 ) ;
V_168 = 1 ;
} else {
V_166 = F_15 ( V_2 , V_171 , 0 ) ;
V_168 = 0 ;
}
do {
T_2 V_21 ;
T_2 V_22 ;
V_21 = F_98 ( V_167 ) ;
V_167 &= ~ ( F_31 ( V_21 ) ) ;
if ( V_166 & F_31 ( V_21 ) ) {
V_22 = ( V_168 << 5 ) | V_21 ;
F_17 ( V_2 , V_27 , V_168 , F_31 ( V_21 ) ) ;
F_92 ( & V_2 -> V_172 [ V_22 ] ) ;
}
} while ( V_167 );
F_16 ( V_2 , V_173 , 1 ) ;
return V_174 ;
}
static void F_99 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_83 * V_44 = V_20 -> V_75 . V_76 . V_83 -> V_44 ;
struct V_30 V_14 ;
if ( ! V_20 -> V_82 )
return;
F_93 ( & V_20 -> V_75 . V_104 ) ;
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
F_95 ( & V_20 -> V_75 . V_104 ) ;
}
static inline bool F_100 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 , V_61 , 0 ) ||
F_8 ( V_2 , V_61 , 1 ) ||
F_1 ( V_2 , V_175 ) || F_1 ( V_2 , V_176 ) )
return true ;
return false ;
}
static T_4 F_101 ( int V_163 , void * V_164 )
{
struct V_1 * V_2 = V_164 ;
int V_8 , V_9 ;
int V_165 ;
unsigned int V_177 = 0 ;
unsigned int V_5 ;
V_165 = V_2 -> V_41 ;
if ( V_165 < 0 )
return V_169 ;
F_67 ( V_2 -> V_44 , L_35 ) ;
if ( ! F_100 ( V_2 ) )
return V_169 ;
while ( 1 ) {
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
unsigned long V_178 ;
V_5 = F_8 ( V_2 , V_61 , V_9 ) ;
if ( ! V_5 )
continue;
F_48 ( V_2 -> V_44 , L_36 , V_9 , V_5 ) ;
V_178 = V_5 ;
for ( V_8 = F_102 ( & V_178 , 32 , 0 ) ; V_8 < 32 ;
V_8 = F_102 ( & V_178 , 32 , V_8 + 1 ) ) {
int V_179 = ( V_9 << 5 ) + V_8 ;
F_9 ( V_2 , V_55 , V_9 , F_31 ( V_8 ) ) ;
F_17 ( V_2 , V_56 , V_9 ,
F_31 ( V_8 ) ) ;
F_99 ( & V_2 -> V_172 [ V_179 ] ) ;
}
}
V_5 = F_1 ( V_2 , V_175 ) ;
if ( V_5 ) {
F_48 ( V_2 -> V_44 , L_37 , V_5 ) ;
F_3 ( V_2 , V_180 , V_5 ) ;
F_16 ( V_2 , V_181 , V_5 ) ;
}
V_5 = F_1 ( V_2 , V_176 ) ;
if ( V_5 ) {
F_45 ( V_2 -> V_44 , L_38 , V_5 ) ;
F_3 ( V_2 , V_62 , V_5 ) ;
}
if ( ! F_100 ( V_2 ) )
break;
V_177 ++ ;
if ( V_177 > 10 )
break;
}
F_3 ( V_2 , V_182 , 1 ) ;
return V_174 ;
}
static int F_103 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_83 * V_44 = V_2 -> V_44 ;
enum V_63 V_64 = V_65 ;
int V_141 ;
if ( V_20 -> V_105 ) {
V_64 = V_20 -> V_105 -> V_41 ;
} else if ( V_2 -> V_183 ) {
V_20 -> V_105 = & V_2 -> V_183 [ V_2 -> V_184 -> V_66 ] ;
V_64 = V_20 -> V_105 -> V_41 ;
}
V_141 = F_55 ( V_20 , V_64 ) ;
if ( V_141 )
return V_141 ;
V_20 -> V_21 [ 0 ] = F_37 ( V_2 , V_20 -> V_23 ) ;
if ( V_20 -> V_21 [ 0 ] < 0 ) {
F_80 ( V_44 , L_39 ,
F_29 ( V_20 -> V_23 ) ) ;
goto V_185;
}
F_28 ( V_20 , V_20 -> V_21 [ 0 ] ) ;
V_20 -> V_186 = true ;
F_48 ( V_44 , L_40 ,
F_29 ( V_20 -> V_23 ) , V_76 -> V_187 ,
V_20 -> V_51 ? L_41 : L_42 ) ;
return 0 ;
V_185:
F_56 ( V_20 ) ;
return V_141 ;
}
static void F_104 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_83 * V_44 = V_20 -> V_2 -> V_44 ;
int V_8 ;
F_49 ( V_20 ) ;
F_105 ( & V_20 -> V_75 ) ;
for ( V_8 = 0 ; V_8 < V_188 ; V_8 ++ ) {
if ( V_20 -> V_21 [ V_8 ] >= 0 ) {
F_41 ( V_20 -> V_2 , V_20 -> V_21 [ V_8 ] ) ;
V_20 -> V_21 [ V_8 ] = - 1 ;
}
}
F_28 ( V_20 , V_20 -> V_2 -> V_100 ) ;
if ( V_20 -> V_186 ) {
F_56 ( V_20 ) ;
V_20 -> V_186 = false ;
}
V_20 -> V_105 = NULL ;
V_20 -> V_51 = false ;
F_48 ( V_44 , L_43 ,
F_29 ( V_20 -> V_23 ) , V_76 -> V_187 ) ;
}
static void F_106 ( struct V_73 * V_76 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned long V_102 ;
F_70 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( F_107 ( & V_20 -> V_75 ) && ! V_20 -> V_82 )
F_63 ( V_20 ) ;
F_72 ( & V_20 -> V_75 . V_104 , V_102 ) ;
}
static T_2 F_108 ( struct V_77 * V_82 )
{
bool V_46 = V_82 -> V_119 == V_130 ;
int V_189 = V_190 ;
struct V_19 * V_20 = V_82 -> V_20 ;
struct V_111 * V_91 = V_82 -> V_91 ;
T_1 V_191 , V_192 ;
int V_8 ;
V_192 = F_46 ( V_20 -> V_2 , V_20 -> V_21 [ 0 ] , V_46 ) ;
while ( F_1 ( V_20 -> V_2 , V_193 ) & V_194 ) {
if ( F_46 ( V_20 -> V_2 ,
V_20 -> V_21 [ 0 ] , V_46 ) != V_192 ) {
break;
}
if ( ! -- V_189 ) {
F_109 ( V_20 -> V_75 . V_76 . V_83 -> V_44 ,
L_44 ,
V_132 ) ;
break;
}
F_110 () ;
}
if ( V_82 -> V_99 ) {
V_191 = V_192 - V_91 -> V_129 ;
V_82 -> V_148 = V_82 -> V_146 - V_191 ;
return V_82 -> V_148 ;
}
V_91 += V_82 -> V_162 ;
for ( V_8 = V_82 -> V_162 ; V_8 < V_82 -> V_88 ; V_8 ++ , V_91 ++ ) {
if ( V_192 >= V_91 -> V_129 && V_192 < V_91 -> V_129 + V_91 -> V_13 )
return V_82 -> V_148 - ( V_192 - V_91 -> V_129 ) ;
V_82 -> V_162 ++ ;
V_82 -> V_148 -= V_91 -> V_13 ;
}
return V_82 -> V_148 ;
}
static enum V_195 F_111 ( struct V_73 * V_76 ,
T_5 V_196 ,
struct V_197 * V_198 )
{
struct V_19 * V_20 = F_59 ( V_76 ) ;
struct V_81 * V_80 ;
enum V_195 V_141 ;
unsigned long V_102 ;
V_141 = F_112 ( V_76 , V_196 , V_198 ) ;
if ( V_141 == V_199 || ! V_198 )
return V_141 ;
F_70 ( & V_20 -> V_75 . V_104 , V_102 ) ;
if ( V_20 -> V_82 && V_20 -> V_82 -> V_80 . V_79 . V_196 == V_196 )
V_198 -> V_146 = F_108 ( V_20 -> V_82 ) ;
else if ( ( V_80 = F_113 ( & V_20 -> V_75 , V_196 ) ) )
V_198 -> V_146 = F_60 ( & V_80 -> V_79 ) -> V_146 ;
F_72 ( & V_20 -> V_75 . V_104 , V_102 ) ;
return V_141 ;
}
static bool F_114 ( int V_23 , T_6 * V_200 )
{
if ( ! V_200 )
return false ;
while ( * V_200 != - 1 ) {
if ( * V_200 == V_23 )
return true ;
V_200 ++ ;
}
return false ;
}
static void F_115 ( struct V_1 * V_2 , bool V_201 )
{
struct V_70 * V_202 = & V_2 -> V_72 ;
struct V_70 * V_203 = NULL ;
T_6 * V_200 = V_2 -> V_184 -> V_200 ;
int V_8 , V_9 ;
F_116 ( V_202 -> V_204 ) ;
F_117 ( V_205 , V_202 -> V_204 ) ;
F_117 ( V_206 , V_202 -> V_204 ) ;
if ( V_2 -> V_201 && ! V_200 ) {
F_45 ( V_2 -> V_44 ,
L_45 ) ;
F_117 ( V_207 , V_202 -> V_204 ) ;
V_202 -> V_208 = F_89 ;
V_202 -> V_209 = F_31 ( V_131 ) ;
}
V_202 -> V_210 = F_82 ;
V_202 -> V_211 = F_91 ;
V_202 -> V_212 = F_103 ;
V_202 -> V_213 = F_104 ;
V_202 -> V_214 = F_106 ;
V_202 -> V_215 = F_111 ;
V_202 -> V_216 = F_76 ;
V_202 -> V_217 = F_77 ;
V_202 -> V_218 = F_78 ;
V_202 -> V_219 = F_68 ;
V_202 -> V_220 = F_74 ;
V_202 -> V_221 = V_222 ;
V_202 -> V_223 = V_222 ;
V_202 -> V_209 |= ( F_31 ( V_130 ) | F_31 ( V_128 ) ) ;
V_202 -> V_224 = V_225 ;
V_202 -> V_44 = V_2 -> V_44 ;
F_118 ( & V_202 -> V_226 ) ;
if ( V_200 ) {
V_203 = F_119 ( V_2 -> V_44 , sizeof( * V_203 ) , V_227 ) ;
V_2 -> V_228 = V_203 ;
F_116 ( V_203 -> V_204 ) ;
F_117 ( V_207 , V_203 -> V_204 ) ;
V_203 -> V_208 = F_89 ;
V_203 -> V_212 = F_103 ;
V_203 -> V_213 = F_104 ;
V_203 -> V_214 = F_106 ;
V_203 -> V_215 = F_111 ;
V_203 -> V_216 = F_76 ;
V_203 -> V_217 = F_77 ;
V_203 -> V_218 = F_78 ;
V_203 -> V_219 = F_68 ;
V_203 -> V_220 = F_74 ;
V_203 -> V_221 = V_222 ;
V_203 -> V_223 = V_222 ;
V_203 -> V_209 = F_31 ( V_131 ) ;
V_203 -> V_224 = V_225 ;
V_203 -> V_44 = V_2 -> V_44 ;
F_118 ( & V_203 -> V_226 ) ;
} else if ( ! V_2 -> V_201 ) {
F_120 ( V_2 -> V_44 , L_46 ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
struct V_19 * V_20 = & V_2 -> V_172 [ V_8 ] ;
V_20 -> V_23 = F_40 ( V_2 -> V_41 , V_8 ) ;
V_20 -> V_2 = V_2 ;
V_20 -> V_75 . V_229 = F_61 ;
if ( V_203 && F_114 ( V_8 , V_200 ) )
F_121 ( & V_20 -> V_75 , V_203 ) ;
else
F_121 ( & V_20 -> V_75 , V_202 ) ;
F_118 ( & V_20 -> V_86 ) ;
for ( V_9 = 0 ; V_9 < V_188 ; V_9 ++ )
V_20 -> V_21 [ V_9 ] = - 1 ;
}
}
static int F_122 ( struct V_83 * V_44 , struct V_230 * V_231 ,
struct V_1 * V_2 )
{
int V_8 ;
T_2 V_232 , V_233 ;
F_123 ( * V_234 ) [ 2 ] ;
V_233 = F_1 ( V_2 , V_235 ) ;
V_232 = F_124 ( V_233 ) ;
V_2 -> V_236 = F_31 ( V_232 ) ;
V_232 = F_125 ( V_233 ) ;
V_2 -> V_34 = F_31 ( V_232 + 1 ) ;
V_232 = F_126 ( V_233 ) ;
V_2 -> V_237 = V_232 * 2 ;
V_232 = F_127 ( V_233 ) ;
V_2 -> V_32 = F_31 ( V_232 + 4 ) ;
V_232 = F_128 ( V_233 ) ;
V_2 -> V_67 = V_232 + 1 ;
V_2 -> V_24 = ( V_233 & V_238 ) ? true : false ;
F_48 ( V_44 , L_47 , V_233 ) ;
F_48 ( V_44 , L_48 , V_2 -> V_236 ) ;
F_48 ( V_44 , L_49 , V_2 -> V_34 ) ;
F_48 ( V_44 , L_50 , V_2 -> V_237 ) ;
F_48 ( V_44 , L_51 , V_2 -> V_32 ) ;
F_48 ( V_44 , L_52 , V_2 -> V_67 ) ;
F_48 ( V_44 , L_53 , V_2 -> V_24 ? L_54 : L_55 ) ;
if ( V_231 -> V_239 )
return 0 ;
V_234 = F_129 ( V_44 , V_2 -> V_67 + 1 , sizeof( F_123 ) ,
V_227 ) ;
if ( ! V_234 )
return - V_37 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_67 ; V_8 ++ ) {
V_234 [ V_8 ] [ 0 ] = V_8 ;
V_234 [ V_8 ] [ 1 ] = V_8 ;
}
V_234 [ V_8 ] [ 0 ] = - 1 ;
V_234 [ V_8 ] [ 1 ] = - 1 ;
V_231 -> V_239 = V_234 ;
V_231 -> V_66 = V_8 - 1 ;
return 0 ;
}
static int F_130 ( struct V_83 * V_44 , struct V_230 * V_231 ,
T_3 V_240 )
{
const char V_241 [] = L_56 ;
struct V_242 V_243 ;
void T_7 * V_244 ;
F_131 ( * V_245 ) [ 2 ] ;
T_3 V_246 = V_240 / sizeof( F_131 ) ;
T_2 V_247 , V_3 , V_248 ;
int V_141 , V_8 ;
V_245 = F_129 ( V_44 , V_246 + 2 , sizeof( F_131 ) , V_227 ) ;
if ( ! V_245 )
return - V_37 ;
V_141 = F_132 ( V_44 -> V_249 , 1 , & V_243 ) ;
if ( V_141 )
return - V_37 ;
V_244 = F_133 ( V_44 , V_243 . V_250 , F_134 ( & V_243 ) ) ;
if ( ! V_244 )
return - V_37 ;
V_141 = F_135 ( V_44 -> V_249 , V_241 , ( V_251 * ) V_245 ,
V_246 ) ;
if ( V_141 )
return - V_252 ;
V_246 >>= 1 ;
V_245 [ V_246 ] [ 0 ] = - 1 ;
V_245 [ V_246 ] [ 1 ] = - 1 ;
for ( V_8 = 0 ; V_8 < V_246 ; V_8 ++ ) {
V_247 = ( V_245 [ V_8 ] [ 1 ] & 0x03 ) << 3 ;
V_3 = V_245 [ V_8 ] [ 1 ] & 0xfffffffc ;
V_248 = F_136 ( V_244 + V_3 ) ;
V_248 &= ~ ( 0xff << V_247 ) ;
V_248 |= V_245 [ V_8 ] [ 0 ] << V_247 ;
F_137 ( V_248 , ( V_244 + V_3 ) ) ;
}
V_231 -> V_245 = ( const F_131 ( * ) [ 2 ] ) V_245 ;
return 0 ;
}
static struct V_230 * F_138 ( struct V_83 * V_44 ,
bool V_201 )
{
struct V_230 * V_184 ;
struct V_253 * V_254 ;
T_3 V_240 ;
int V_141 ;
V_184 = F_119 ( V_44 , sizeof( struct V_230 ) , V_227 ) ;
if ( ! V_184 )
return F_139 ( - V_37 ) ;
if ( V_201 ) {
V_254 = F_140 ( V_44 -> V_249 , L_56 ,
& V_240 ) ;
if ( V_254 ) {
V_141 = F_130 ( V_44 , V_184 , V_240 ) ;
if ( V_141 )
return F_139 ( V_141 ) ;
}
return V_184 ;
}
V_254 = F_140 ( V_44 -> V_249 , L_57 , & V_240 ) ;
if ( V_254 ) {
const char V_241 [] = L_57 ;
T_3 V_246 = V_240 / sizeof( T_6 ) ;
T_6 * V_255 ;
V_255 = F_129 ( V_44 , V_246 + 1 , sizeof( T_6 ) ,
V_227 ) ;
if ( ! V_255 )
return F_139 ( - V_37 ) ;
V_141 = F_141 ( V_44 -> V_249 , V_241 ,
( T_2 * ) V_255 , V_246 ) ;
if ( V_141 )
return F_139 ( V_141 ) ;
V_255 [ V_246 ] = - 1 ;
V_184 -> V_200 = V_255 ;
}
V_254 = F_140 ( V_44 -> V_249 , L_58 ,
& V_240 ) ;
if ( V_254 ) {
const char V_241 [] = L_58 ;
T_2 ( * V_256 ) [ 2 ] ;
F_131 ( * V_257 ) [ 2 ] ;
T_3 V_246 = V_240 / sizeof( * V_256 ) ;
struct V_258 * V_259 ;
int V_8 ;
if ( ! V_246 )
return V_184 ;
V_256 = F_142 ( V_246 , sizeof( * V_256 ) , V_227 ) ;
if ( ! V_256 )
return F_139 ( - V_37 ) ;
V_259 = F_119 ( V_44 , sizeof( * V_259 ) , V_227 ) ;
if ( ! V_259 ) {
F_62 ( V_256 ) ;
return F_139 ( - V_37 ) ;
}
V_257 = F_129 ( V_44 , V_246 + 1 , sizeof( * V_257 ) ,
V_227 ) ;
if ( ! V_257 ) {
F_62 ( V_256 ) ;
return F_139 ( - V_37 ) ;
}
V_141 = F_141 ( V_44 -> V_249 , V_241 ,
( T_2 * ) V_256 , V_246 * 2 ) ;
if ( V_141 ) {
F_62 ( V_256 ) ;
return F_139 ( V_141 ) ;
}
for ( V_8 = 0 ; V_8 < V_246 ; V_8 ++ ) {
V_257 [ V_8 ] [ 0 ] = V_256 [ V_8 ] [ 0 ] ;
V_257 [ V_8 ] [ 1 ] = V_256 [ V_8 ] [ 1 ] ;
}
V_257 [ V_246 ] [ 0 ] = - 1 ;
V_257 [ V_246 ] [ 1 ] = - 1 ;
V_184 -> V_260 = V_259 ;
V_184 -> V_260 -> V_257 = ( const F_131 ( * ) [ 2 ] ) V_257 ;
F_62 ( V_256 ) ;
}
return V_184 ;
}
static struct V_73 * F_143 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = V_264 -> V_265 ;
struct V_73 * V_76 = NULL ;
struct V_19 * V_20 ;
int V_8 ;
if ( ! V_2 || V_262 -> V_266 < 1 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
V_20 = & V_2 -> V_172 [ V_8 ] ;
if ( V_20 -> V_23 == V_262 -> args [ 0 ] ) {
V_76 = & V_20 -> V_75 . V_76 ;
break;
}
}
if ( ! V_76 )
return NULL ;
if ( V_20 -> V_2 -> V_201 && V_262 -> V_266 == 1 )
goto V_267;
if ( ! V_20 -> V_2 -> V_201 && V_262 -> V_266 == 2 &&
V_262 -> args [ 1 ] < V_20 -> V_2 -> V_67 ) {
V_20 -> V_105 = & V_20 -> V_2 -> V_183 [ V_262 -> args [ 1 ] ] ;
goto V_267;
}
return NULL ;
V_267:
V_20 -> V_51 = true ;
return F_144 ( V_76 ) ;
}
static struct V_230 * F_138 ( struct V_83 * V_44 ,
bool V_201 )
{
return F_139 ( - V_38 ) ;
}
static struct V_73 * F_143 ( struct V_261 * V_262 ,
struct V_263 * V_264 )
{
return NULL ;
}
static int F_145 ( struct V_268 * V_269 )
{
struct V_230 * V_184 = V_269 -> V_44 . V_270 ;
F_123 ( * V_239 ) [ 2 ] ;
int V_8 , V_271 , V_272 ;
const F_131 ( * V_257 ) [ 2 ] ;
const F_131 ( * V_245 ) [ 2 ] ;
int V_163 ;
char * V_273 ;
struct V_242 * V_274 ;
struct V_275 * V_86 = V_269 -> V_44 . V_249 ;
struct V_83 * V_44 = & V_269 -> V_44 ;
struct V_1 * V_2 ;
bool V_201 = true ;
int V_141 ;
if ( V_86 ) {
const struct V_276 * V_277 ;
V_277 = F_146 ( V_278 , V_86 ) ;
if ( V_277 && ( T_2 ) V_277 -> V_164 == V_279 )
V_201 = false ;
V_184 = F_138 ( V_44 , V_201 ) ;
if ( F_147 ( V_184 ) ) {
F_80 ( V_44 , L_59 ) ;
return F_148 ( V_184 ) ;
}
}
if ( ! V_184 )
return - V_280 ;
F_149 ( V_44 ) ;
V_141 = F_150 ( V_44 ) ;
if ( V_141 < 0 ) {
F_80 ( V_44 , L_60 ) ;
return V_141 ;
}
V_141 = F_151 ( V_44 , F_152 ( 32 ) ) ;
if ( V_141 )
return V_141 ;
V_2 = F_119 ( V_44 , sizeof( * V_2 ) , V_227 ) ;
if ( ! V_2 ) {
F_80 ( V_44 , L_61 ) ;
return - V_37 ;
}
V_2 -> V_44 = V_44 ;
V_2 -> V_41 = V_269 -> V_41 ;
V_2 -> V_201 = V_201 ;
if ( V_2 -> V_41 < 0 )
V_2 -> V_41 = 0 ;
V_274 = F_153 ( V_269 , V_281 , L_62 ) ;
if ( ! V_274 ) {
F_48 ( V_44 , L_63 ) ;
V_274 = F_154 ( V_269 , V_281 , 0 ) ;
if ( ! V_274 ) {
F_80 ( V_44 , L_64 ) ;
return - V_280 ;
}
}
V_2 -> V_4 = F_155 ( V_44 , V_274 ) ;
if ( F_147 ( V_2 -> V_4 ) )
return F_148 ( V_2 -> V_4 ) ;
F_156 ( V_269 , V_2 ) ;
V_141 = F_122 ( V_44 , V_184 , V_2 ) ;
if ( V_141 )
return V_141 ;
V_2 -> V_172 = F_129 ( V_44 , V_2 -> V_34 ,
sizeof( * V_2 -> V_172 ) , V_227 ) ;
if ( ! V_2 -> V_172 )
return - V_37 ;
V_2 -> V_36 = F_129 ( V_44 , F_157 ( V_2 -> V_32 ) ,
sizeof( unsigned long ) , V_227 ) ;
if ( ! V_2 -> V_36 )
return - V_37 ;
V_2 -> V_66 = V_184 -> V_66 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_32 ; V_8 ++ )
F_32 ( V_2 , V_8 , & V_40 ) ;
if ( V_184 -> V_260 ) {
V_257 = V_184 -> V_260 -> V_257 ;
if ( V_257 ) {
for ( V_8 = 0 ; V_257 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ ) {
V_271 = V_257 [ V_8 ] [ 0 ] ;
V_272 = V_257 [ V_8 ] [ 1 ] ;
F_23 ( V_271 , V_272 , V_2 -> V_36 ) ;
}
}
}
V_245 = V_184 -> V_245 ;
if ( V_245 ) {
for ( V_8 = 0 ; V_245 [ V_8 ] [ 1 ] != - 1 ; V_8 ++ ) {
V_271 = V_245 [ V_8 ] [ 1 ] ;
}
}
V_163 = F_158 ( V_269 , L_65 ) ;
if ( V_163 < 0 && V_86 )
V_163 = F_159 ( V_86 , 0 ) ;
if ( V_163 >= 0 ) {
V_273 = F_160 ( V_44 , V_227 , L_66 ,
F_161 ( V_44 ) ) ;
V_141 = F_162 ( V_44 , V_163 , F_97 , 0 , V_273 ,
V_2 ) ;
if ( V_141 ) {
F_80 ( V_44 , L_67 , V_163 , V_141 ) ;
return V_141 ;
}
}
V_163 = F_158 ( V_269 , L_68 ) ;
if ( V_163 < 0 && V_86 )
V_163 = F_159 ( V_86 , 2 ) ;
if ( V_163 >= 0 ) {
V_273 = F_160 ( V_44 , V_227 , L_69 ,
F_161 ( V_44 ) ) ;
V_141 = F_162 ( V_44 , V_163 , F_101 , 0 , V_273 ,
V_2 ) ;
if ( V_141 ) {
F_80 ( V_44 , L_70 , V_163 , V_141 ) ;
return V_141 ;
}
}
V_2 -> V_100 = F_37 ( V_2 , V_35 ) ;
if ( V_2 -> V_100 < 0 ) {
F_80 ( V_44 , L_71 ) ;
return V_2 -> V_100 ;
}
V_239 = V_184 -> V_239 ;
if ( ! V_2 -> V_201 ) {
int V_282 = 0 ;
struct V_261 V_283 ;
V_2 -> V_183 = F_129 ( V_44 , V_2 -> V_67 ,
sizeof( * V_2 -> V_183 ) , V_227 ) ;
if ( ! V_2 -> V_183 )
return - V_37 ;
for ( V_8 = 0 ; ; V_8 ++ ) {
V_141 = F_163 ( V_86 , L_72 ,
1 , V_8 , & V_283 ) ;
if ( V_141 || V_8 == V_2 -> V_67 )
break;
V_2 -> V_183 [ V_8 ] . V_86 = V_283 . V_284 ;
V_2 -> V_183 [ V_8 ] . V_41 = V_8 ;
V_239 [ V_8 ] [ 1 ] = V_283 . args [ 0 ] ;
if ( V_239 [ V_8 ] [ 1 ] > V_282 ) {
V_282 = V_239 [ V_8 ] [ 1 ] ;
V_184 -> V_66 = V_8 ;
}
}
}
for ( V_8 = 0 ; V_239 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_27 ( V_2 , V_239 [ V_8 ] [ 0 ] ,
V_239 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_236 ; V_8 ++ ) {
F_13 ( V_2 , V_69 , V_8 , 0 , 0x0 ) ;
F_13 ( V_2 , V_69 , V_8 , 1 , 0x0 ) ;
F_9 ( V_2 , V_285 , V_8 , 0x0 ) ;
}
V_2 -> V_184 = V_184 ;
F_115 ( V_2 , V_201 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
F_54 ( & V_2 -> V_172 [ V_8 ] ,
V_184 -> V_66 ) ;
F_28 ( & V_2 -> V_172 [ V_8 ] , V_2 -> V_100 ) ;
}
V_2 -> V_72 . V_286 . V_287 = V_184 -> V_288 ;
V_2 -> V_72 . V_286 . V_289 = V_184 -> V_290 ;
V_2 -> V_72 . V_286 . V_291 = V_292 ;
V_141 = F_164 ( & V_2 -> V_72 ) ;
if ( V_141 ) {
F_80 ( V_44 , L_73 , V_141 ) ;
goto V_293;
}
if ( V_2 -> V_228 ) {
V_141 = F_164 ( V_2 -> V_228 ) ;
if ( V_141 ) {
F_80 ( V_44 , L_74 ,
V_141 ) ;
F_165 ( & V_2 -> V_72 ) ;
goto V_293;
}
}
if ( V_86 )
F_166 ( V_86 , F_143 , V_2 ) ;
F_120 ( V_44 , L_75 ) ;
return 0 ;
V_293:
F_41 ( V_2 , V_2 -> V_100 ) ;
return V_141 ;
}
static int F_167 ( struct V_268 * V_269 )
{
struct V_83 * V_44 = & V_269 -> V_44 ;
struct V_1 * V_2 = F_168 ( V_44 ) ;
if ( V_44 -> V_249 )
F_169 ( V_44 -> V_249 ) ;
F_165 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_228 )
F_165 ( V_2 -> V_228 ) ;
F_41 ( V_2 , V_2 -> V_100 ) ;
return 0 ;
}
static int F_170 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_168 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_172 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_186 )
F_30 ( & V_20 [ V_8 ] , false ) ;
}
return 0 ;
}
static int F_171 ( struct V_83 * V_44 )
{
struct V_1 * V_2 = F_168 ( V_44 ) ;
struct V_19 * V_20 = V_2 -> V_172 ;
int V_8 ;
F_123 ( * V_239 ) [ 2 ] ;
V_239 = V_2 -> V_184 -> V_239 ;
for ( V_8 = 0 ; V_239 [ V_8 ] [ 0 ] != - 1 ; V_8 ++ )
F_27 ( V_2 , V_239 [ V_8 ] [ 0 ] ,
V_239 [ V_8 ] [ 1 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_34 ; V_8 ++ ) {
if ( V_20 [ V_8 ] . V_186 ) {
F_12 ( V_2 , V_69 , 0 , V_8 >> 5 ,
F_31 ( V_8 & 0x1f ) ) ;
F_30 ( & V_20 [ V_8 ] , true ) ;
F_28 ( & V_20 [ V_8 ] , V_20 [ V_8 ] . V_21 [ 0 ] ) ;
}
}
return 0 ;
}
static int F_172 ( struct V_268 * V_269 )
{
F_149 ( & V_269 -> V_44 ) ;
return F_150 ( & V_269 -> V_44 ) ;
}
bool V_292 ( struct V_73 * V_76 , void * V_31 )
{
bool V_277 = false ;
if ( V_76 -> V_83 -> V_44 -> V_294 == & V_295 . V_294 ) {
struct V_19 * V_20 = F_59 ( V_76 ) ;
unsigned V_296 = * ( unsigned * ) V_31 ;
if ( V_296 == V_20 -> V_23 ) {
V_20 -> V_51 = true ;
V_277 = true ;
}
}
return V_277 ;
}
static int F_173 ( void )
{
int V_141 ;
V_141 = F_174 ( & V_297 ) ;
if ( V_141 )
return V_141 ;
return F_174 ( & V_295 ) ;
}
static void T_8 F_175 ( void )
{
F_176 ( & V_295 ) ;
F_176 ( & V_297 ) ;
}
