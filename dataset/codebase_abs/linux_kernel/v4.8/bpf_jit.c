static inline int F_1 ( T_1 * V_1 )
{
if ( ! ( * V_1 & ( * V_1 - 1 ) ) ) {
* V_1 = F_2 ( * V_1 ) ;
return 1 ;
}
return 0 ;
}
static inline bool F_3 ( T_2 V_2 )
{
return ! ( V_2 >= F_4 ( 15 ) || V_2 < - F_4 ( 15 ) ) ;
}
static inline void F_5 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_8 , V_3 , V_4 , V_5 ) ;
}
static inline void F_7 ( struct V_6 * V_7 )
{
F_6 ( V_7 , V_9 ) ;
}
static inline void F_8 ( unsigned int V_3 , T_1 V_2 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
if ( ! F_3 ( V_2 ) ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_9 ( & V_11 , V_13 , ( T_2 ) V_2 >> 16 ) ;
V_11 = & V_7 -> V_10 [ V_7 -> V_12 + 1 ] ;
F_10 ( & V_11 , V_3 , V_13 , V_2 & 0xffff ) ;
} else {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_11 ( & V_11 , V_3 , V_14 , V_2 ) ;
}
}
V_7 -> V_12 ++ ;
if ( ! F_3 ( V_2 ) )
V_7 -> V_12 ++ ;
}
static inline void F_12 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_15 , V_3 , V_4 , V_5 ) ;
}
static inline void F_13 ( unsigned int V_3 , unsigned V_16 , T_1 V_2 ,
struct V_6 * V_7 )
{
if ( V_2 >= F_14 ( 16 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_12 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_18 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_15 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_19 , V_3 , V_16 , V_2 ) ;
}
static inline void F_16 ( unsigned int V_3 , unsigned int V_16 ,
T_1 V_2 , struct V_6 * V_7 )
{
if ( ! F_3 ( V_2 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_5 ( V_3 , V_17 , V_16 , V_7 ) ;
} else {
F_6 ( V_7 , V_20 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_17 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_21 , V_3 , V_4 , V_5 ) ;
}
static inline void F_18 ( unsigned int V_3 , unsigned int V_16 ,
T_1 V_2 , struct V_6 * V_7 )
{
if ( V_2 >= F_14 ( 16 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_17 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_22 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_19 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_23 , V_3 , V_4 , V_5 ) ;
}
static inline void F_20 ( T_3 V_3 , T_3 V_16 , T_1 V_2 , struct V_6 * V_7 )
{
if ( V_2 >= F_14 ( 16 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_19 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_24 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_21 ( int V_25 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_26 , V_27 , V_27 , V_25 ) ;
}
static inline void F_23 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_28 , V_3 , V_4 , V_5 ) ;
}
static inline void F_24 ( unsigned int V_29 , struct V_6 * V_7 )
{
F_23 ( V_29 , V_14 , V_29 , V_7 ) ;
}
static inline void F_25 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_31 , V_3 , V_16 , V_30 ) ;
}
static inline void F_26 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
if ( V_30 >= F_14 ( 5 ) )
F_27 ( V_3 , V_14 , V_7 ) ;
else
F_6 ( V_7 , V_32 , V_3 , V_16 , V_30 ) ;
}
static inline void F_28 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_33 , V_3 , V_16 , V_30 ) ;
}
static inline void F_29 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
if ( V_30 >= F_14 ( 5 ) )
F_27 ( V_3 , V_14 , V_7 ) ;
else
F_6 ( V_7 , V_34 , V_3 , V_16 , V_30 ) ;
}
static inline void F_30 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_35 , V_3 , V_4 , V_5 ) ;
}
static inline void F_31 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_36 , V_3 , V_4 , V_5 ) ;
}
static inline void F_32 ( unsigned V_3 , unsigned int V_16 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( ! F_3 ( ( T_2 ) V_2 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_31 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_37 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_33 ( T_3 V_29 , T_3 V_38 ,
unsigned int V_25 ,
struct V_6 * V_7 )
{
F_22 ( V_7 , V_39 , V_29 , V_25 , V_38 ) ;
}
static inline void F_34 ( T_3 V_29 , T_3 V_38 , unsigned int V_25 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_40 , V_29 , V_25 , V_38 ) ;
}
static inline void F_35 ( T_3 V_29 , T_3 V_38 ,
unsigned int V_25 ,
struct V_6 * V_7 )
{
F_22 ( V_7 , V_41 , V_29 , V_25 , V_38 ) ;
}
static inline void F_36 ( unsigned int V_29 , unsigned int V_38 ,
unsigned int V_25 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_42 , V_29 , V_25 , V_38 ) ;
}
static inline void F_37 ( unsigned int V_29 , unsigned int V_38 ,
unsigned int V_25 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_43 , V_29 , V_25 , V_38 ) ;
}
static inline void F_38 ( unsigned int V_29 , unsigned int V_38 ,
unsigned int V_25 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_44 , V_29 , V_25 , V_38 ) ;
}
static inline void F_39 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_45 , V_3 , V_4 , V_5 ) ;
}
static inline void F_40 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_41 ( & V_11 , V_3 , V_16 ) ;
V_11 = & V_7 -> V_10 [ V_7 -> V_12 + 1 ] ;
F_42 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_43 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_41 ( & V_11 , V_3 , V_16 ) ;
V_11 = & V_7 -> V_10 [ V_7 -> V_12 + 1 ] ;
F_44 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_45 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_46 , V_3 , V_16 , V_30 ) ;
}
static inline void F_46 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_47 , V_3 , V_16 , V_30 ) ;
}
static inline void F_47 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_48 , V_3 , V_16 ) ;
}
static inline void F_48 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_41 , V_3 , V_2 , V_16 ) ;
}
static inline void F_49 ( unsigned int V_29 , T_3 V_2 ,
struct V_6 * V_7 )
{
if ( F_50 ( V_49 ) ) {
F_8 ( V_17 , ( V_50 ) V_2 >> 32 , V_7 ) ;
F_45 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_17 , V_13 , ( V_2 >> 16 ) & 0xffff , V_7 ) ;
F_45 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_29 , V_13 , V_2 & 0xffff , V_7 ) ;
} else {
F_8 ( V_29 , V_2 , V_7 ) ;
}
}
static inline void F_51 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_51 , V_3 , V_16 , V_14 ) ;
}
static inline void F_27 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_5 ( V_3 , V_16 , V_14 , V_7 ) ;
}
static inline T_1 F_52 ( unsigned int V_52 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 == NULL )
return 0 ;
return V_7 -> V_53 [ V_52 ] -
( V_7 -> V_12 * 4 - V_7 -> V_54 ) - 4 ;
}
static inline void F_53 ( int V_55 , unsigned int V_56 , unsigned int V_57 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
switch ( V_55 ) {
case V_58 :
F_54 ( & V_11 , V_56 , V_57 , V_2 ) ;
break;
case V_59 :
F_55 ( & V_11 , V_56 , V_57 , V_2 ) ;
break;
case V_60 :
F_56 ( & V_11 , V_2 ) ;
break;
default:
F_57 ( L_1 ,
V_61 , V_55 ) ;
}
}
V_7 -> V_12 ++ ;
}
static inline void F_58 ( unsigned int V_2 , struct V_6 * V_7 )
{
F_53 ( V_60 , V_14 , V_14 , V_2 , V_7 ) ;
}
static inline void F_59 ( unsigned int V_62 , unsigned int V_29 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_63 , V_62 , V_29 ) ;
}
static inline void F_60 ( unsigned int V_29 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_64 , V_29 ) ;
}
static inline T_4 F_61 ( unsigned int V_65 )
{
unsigned int V_66 = F_50 ( V_49 ) ? 16 : 8 ;
V_65 = ( V_65 + ( V_66 - 1 ) ) & - V_66 ;
return V_65 ;
}
static void F_62 ( struct V_6 * V_7 , unsigned V_25 )
{
int V_67 = 0 , V_68 = 0 ;
T_1 V_69 , V_70 ;
F_21 ( - F_61 ( V_25 ) , V_7 ) ;
V_70 = V_69 = V_7 -> V_71 >> V_72 ;
while ( V_70 ) {
if ( ( V_69 >> V_67 ) & 0x1 ) {
F_33 ( V_73 + V_67 , V_27 , V_68 ,
V_7 ) ;
V_68 += V_74 ;
}
V_67 ++ ;
V_70 >>= 1 ;
}
if ( V_7 -> V_71 & V_75 ) {
F_33 ( V_76 , V_27 , V_68 , V_7 ) ;
V_68 += V_74 ;
}
if ( V_7 -> V_71 & V_77 ) {
if ( V_68 % ( V_74 * 2 ) )
V_68 += V_74 ;
F_22 ( V_7 , V_26 , V_78 , V_27 , V_68 ) ;
}
}
static void F_63 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
int V_67 , V_68 = 0 ;
T_1 V_69 , V_70 ;
V_70 = V_69 = V_7 -> V_71 >> V_72 ;
V_67 = 0 ;
while ( V_70 ) {
if ( ( V_69 >> V_67 ) & 0x1 ) {
F_35 ( V_73 + V_67 , V_27 , V_68 ,
V_7 ) ;
V_68 += V_74 ;
}
V_67 ++ ;
V_70 >>= 1 ;
}
if ( V_7 -> V_71 & V_75 )
F_35 ( V_76 , V_27 , V_68 , V_7 ) ;
F_21 ( F_61 ( V_25 ) , V_7 ) ;
}
static unsigned int F_64 ( struct V_6 * V_7 )
{
int V_79 = 0 ;
V_79 += F_65 ( V_7 -> V_71 >> V_72 ) * V_74 ;
if ( V_7 -> V_71 & V_77 )
V_79 += 4 * V_80 ;
if ( V_7 -> V_71 & V_75 )
V_79 += V_74 ;
return V_79 ;
}
static void F_66 ( struct V_6 * V_7 )
{
int V_79 ;
V_79 = F_64 ( V_7 ) ;
F_62 ( V_7 , V_79 ) ;
if ( V_7 -> V_71 & V_81 )
F_51 ( V_82 , V_83 , V_7 ) ;
if ( V_7 -> V_71 & V_84 ) {
F_36 ( V_85 , V_82 , F_67 ( struct V_86 , V_87 ) ,
V_7 ) ;
F_36 ( V_17 , V_82 , F_67 ( struct V_86 , V_88 ) ,
V_7 ) ;
F_48 ( V_89 , V_82 ,
F_67 ( struct V_86 , V_90 ) , V_7 ) ;
F_23 ( V_91 , V_85 , V_17 , V_7 ) ;
}
if ( V_7 -> V_71 & V_92 )
F_27 ( V_93 , V_14 , V_7 ) ;
if ( F_68 ( & V_7 -> V_94 -> V_95 [ 0 ] ) )
F_27 ( V_96 , V_14 , V_7 ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
unsigned int V_79 ;
V_79 = F_64 ( V_7 ) ;
F_63 ( V_7 , V_79 ) ;
F_60 ( V_76 , V_7 ) ;
F_7 ( V_7 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
const struct V_97 * V_98 = V_7 -> V_94 ;
const struct V_99 * V_100 ;
unsigned int V_67 , V_101 , V_102 ;
T_1 V_1 , V_103 V_104 ;
T_5 (* F_71)( unsigned long * V_105 , int V_25 );
for ( V_67 = 0 ; V_67 < V_98 -> V_87 ; V_67 ++ ) {
T_4 V_106 ;
V_100 = & ( V_98 -> V_95 [ V_67 ] ) ;
F_72 ( L_2 ,
V_61 , V_100 -> V_106 , V_100 -> V_107 , V_100 -> V_108 , V_100 -> V_1 ) ;
V_1 = V_100 -> V_1 ;
V_106 = F_73 ( V_100 ) ;
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_67 ] = V_7 -> V_12 * 4 ;
switch ( V_106 ) {
case V_109 | V_110 :
V_7 -> V_71 |= V_111 ;
F_8 ( V_96 , V_1 , V_7 ) ;
break;
case V_109 | V_112 | V_113 :
F_74 ( F_75 ( struct V_86 , V_87 ) != 4 ) ;
V_7 -> V_71 |= V_81 | V_111 ;
V_101 = F_67 ( struct V_86 , V_87 ) ;
F_36 ( V_96 , V_82 , V_101 , V_7 ) ;
break;
case V_109 | V_114 :
V_7 -> V_71 |= V_77 | V_111 ;
F_36 ( V_96 , V_78 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_109 | V_112 | V_115 :
F_71 = F_77 ( V_1 , V_116 ) ;
goto V_117;
case V_109 | V_118 | V_115 :
F_71 = F_77 ( V_1 , V_119 ) ;
goto V_117;
case V_109 | V_120 | V_115 :
F_71 = F_77 ( V_1 , V_121 ) ;
V_117:
F_8 ( V_122 , V_1 , V_7 ) ;
V_123:
V_7 -> V_71 |= V_75 | V_124 |
V_81 | V_111 | V_84 ;
F_49 ( V_125 , ( T_3 ) F_71 , V_7 ) ;
F_51 ( V_83 , V_82 , V_7 ) ;
F_59 ( V_126 , V_125 , V_7 ) ;
F_51 ( V_127 , V_122 , V_7 ) ;
F_53 ( V_58 , V_128 , 0 , F_52 ( V_67 + 1 , V_7 ) ,
V_7 ) ;
F_51 ( V_128 , V_14 , V_7 ) ;
F_58 ( F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_109 | V_112 | V_129 :
F_71 = V_116 ;
goto V_130;
case V_109 | V_118 | V_129 :
F_71 = V_119 ;
goto V_130;
case V_109 | V_120 | V_129 :
F_71 = V_121 ;
V_130:
V_7 -> V_71 |= V_124 | V_92 ;
F_16 ( V_122 , V_93 , V_1 , V_7 ) ;
goto V_123;
case V_131 | V_110 :
V_7 -> V_71 |= V_92 ;
F_8 ( V_93 , V_1 , V_7 ) ;
break;
case V_131 | V_114 :
V_7 -> V_71 |= V_92 | V_77 ;
F_36 ( V_93 , V_78 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_131 | V_112 | V_113 :
V_7 -> V_71 |= V_92 | V_81 ;
V_101 = F_67 ( struct V_86 , V_87 ) ;
F_36 ( V_93 , V_82 , V_101 , V_7 ) ;
break;
case V_131 | V_120 | V_132 :
V_7 -> V_71 |= V_92 | V_75 | V_81 ;
F_49 ( V_125 , ( T_3 ) V_121 , V_7 ) ;
F_8 ( V_127 , V_1 , V_7 ) ;
F_59 ( V_126 , V_125 , V_7 ) ;
F_51 ( V_83 , V_82 , V_7 ) ;
F_53 ( V_59 , V_128 , 0 ,
F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_51 ( V_128 , V_14 , V_7 ) ;
F_18 ( V_93 , V_96 , 0xf , V_7 ) ;
F_58 ( F_52 ( V_67 + 1 , V_7 ) , V_7 ) ;
F_26 ( V_93 , V_93 , 2 , V_7 ) ;
break;
case V_133 :
V_7 -> V_71 |= V_77 | V_111 ;
F_34 ( V_96 , V_78 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_134 :
V_7 -> V_71 |= V_77 | V_92 ;
F_34 ( V_93 , V_78 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_135 | V_136 | V_137 :
V_7 -> V_71 |= V_111 ;
F_16 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_135 | V_136 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_5 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_139 | V_137 :
V_7 -> V_71 |= V_111 ;
F_16 ( V_96 , V_96 , - V_1 , V_7 ) ;
break;
case V_135 | V_139 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_23 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_140 | V_137 :
V_7 -> V_71 |= V_111 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_39 ( V_96 , V_96 , V_125 , V_7 ) ;
break;
case V_135 | V_140 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_39 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_141 | V_137 :
if ( V_1 == 1 )
break;
if ( F_1 ( & V_1 ) ) {
V_7 -> V_71 |= V_111 ;
F_29 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
}
V_7 -> V_71 |= V_111 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_40 ( V_96 , V_125 , V_7 ) ;
break;
case V_135 | V_142 | V_137 :
if ( V_1 == 1 ) {
V_7 -> V_71 |= V_111 ;
F_27 ( V_96 , V_14 , V_7 ) ;
} else {
V_7 -> V_71 |= V_111 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_43 ( V_96 , V_125 , V_7 ) ;
}
break;
case V_135 | V_141 | V_138 :
V_7 -> V_71 |= V_92 | V_111 ;
F_53 ( V_58 , V_93 , V_14 ,
F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_8 ( V_128 , 0 , V_7 ) ;
F_40 ( V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_142 | V_138 :
V_7 -> V_71 |= V_92 | V_111 ;
F_53 ( V_58 , V_93 , V_14 ,
F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_8 ( V_128 , 0 , V_7 ) ;
F_43 ( V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_143 | V_137 :
V_7 -> V_71 |= V_111 ;
F_13 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_135 | V_143 | V_138 :
V_7 -> V_71 |= V_111 ;
F_13 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_144 | V_137 :
V_7 -> V_71 |= V_111 ;
F_20 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_145 | V_146 :
case V_135 | V_144 | V_138 :
V_7 -> V_71 |= V_111 ;
F_19 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_147 | V_137 :
V_7 -> V_71 |= V_111 ;
F_18 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_135 | V_147 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_17 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_148 | V_137 :
V_7 -> V_71 |= V_111 ;
F_26 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_135 | V_148 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_25 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_149 | V_137 :
V_7 -> V_71 |= V_111 ;
F_29 ( V_96 , V_96 , V_1 , V_7 ) ;
break;
case V_135 | V_149 | V_138 :
V_7 -> V_71 |= V_111 | V_92 ;
F_28 ( V_96 , V_96 , V_93 , V_7 ) ;
break;
case V_135 | V_150 :
V_7 -> V_71 |= V_111 ;
F_24 ( V_96 , V_7 ) ;
break;
case V_151 | V_152 :
F_58 ( F_52 ( V_67 + V_1 + 1 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_151 | V_153 | V_137 :
V_102 = V_58 | V_154 ;
goto V_155;
case V_151 | V_153 | V_138 :
V_7 -> V_71 |= V_92 ;
V_102 = V_58 | V_156 ;
goto V_155;
case V_151 | V_157 | V_137 :
V_102 = V_158 | V_154 ;
goto V_155;
case V_151 | V_157 | V_138 :
V_7 -> V_71 |= V_92 ;
V_102 = V_158 | V_156 ;
goto V_155;
case V_151 | V_159 | V_137 :
V_102 = V_160 | V_154 ;
goto V_155;
case V_151 | V_159 | V_138 :
V_7 -> V_71 |= V_92 ;
V_102 = V_160 | V_156 ;
V_155:
if ( ( V_102 & V_158 ) ||
( V_102 & V_160 ) ) {
if ( V_102 & V_154 ) {
V_7 -> V_71 |= V_111 ;
F_32 ( V_125 , V_96 , V_1 , V_7 ) ;
} else {
V_7 -> V_71 |= V_111 |
V_92 ;
F_31 ( V_125 , V_96 , V_93 , V_7 ) ;
}
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 , V_7 ) ;
F_53 ( V_59 , V_125 , V_14 , V_103 ,
V_7 ) ;
F_7 ( V_7 ) ;
if ( V_102 & V_160 ) {
V_7 -> V_71 |= V_111 | V_92 ;
if ( V_102 & V_154 )
F_8 ( V_125 , V_1 , V_7 ) ;
else
F_27 ( V_125 , V_93 ,
V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 , V_7 ) ;
F_53 ( V_58 , V_96 , V_125 ,
V_103 , V_7 ) ;
F_7 ( V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 , V_7 ) ;
F_58 ( V_103 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 , V_7 ) ;
F_58 ( V_103 , V_7 ) ;
F_7 ( V_7 ) ;
}
} else {
if ( V_102 & V_154 ) {
V_7 -> V_71 |= V_111 ;
F_8 ( V_125 , V_1 , V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 , V_7 ) ;
F_53 ( V_58 , V_96 , V_125 ,
V_103 , V_7 ) ;
F_7 ( V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 ,
V_7 ) ;
F_53 ( V_59 , V_96 , V_125 ,
V_103 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_7 -> V_71 |= V_111 | V_92 ;
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 ,
V_7 ) ;
F_53 ( V_58 , V_96 , V_93 ,
V_103 , V_7 ) ;
F_7 ( V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 , V_7 ) ;
F_53 ( V_59 , V_96 , V_93 ,
V_103 , V_7 ) ;
F_7 ( V_7 ) ;
}
}
break;
case V_151 | V_161 | V_137 :
V_7 -> V_71 |= V_111 ;
F_8 ( V_162 , V_1 , V_7 ) ;
F_17 ( V_125 , V_96 , V_162 , V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 , V_7 ) ;
F_53 ( V_59 , V_125 , V_14 , V_103 , V_7 ) ;
F_7 ( V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 , V_7 ) ;
F_58 ( V_103 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_151 | V_161 | V_138 :
V_7 -> V_71 |= V_92 | V_111 ;
F_17 ( V_125 , V_96 , V_93 , V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_107 + 1 , V_7 ) ;
F_53 ( V_59 , V_125 , V_14 , V_103 , V_7 ) ;
F_7 ( V_7 ) ;
V_103 = F_52 ( V_67 + V_100 -> V_108 + 1 , V_7 ) ;
F_58 ( V_103 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_163 | V_164 :
V_7 -> V_71 |= V_111 ;
if ( V_67 != V_98 -> V_87 - 1 )
F_58 ( F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_51 ( V_128 , V_96 , V_7 ) ;
break;
case V_163 | V_137 :
F_8 ( V_128 , V_1 , V_7 ) ;
if ( V_67 != V_98 -> V_87 - 1 ) {
F_58 ( F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
}
break;
case V_165 | V_166 :
V_7 -> V_71 |= V_92 | V_111 ;
F_27 ( V_93 , V_96 , V_7 ) ;
break;
case V_165 | V_167 :
V_7 -> V_71 |= V_111 | V_92 ;
F_27 ( V_96 , V_93 , V_7 ) ;
break;
case V_145 | V_168 :
V_7 -> V_71 |= V_81 | V_124 | V_111 ;
F_74 ( F_75 ( struct V_86 ,
V_169 ) != 2 ) ;
V_101 = F_67 ( struct V_86 , V_169 ) ;
F_38 ( V_96 , V_82 , V_101 , V_7 ) ;
#ifdef F_78
if ( V_170 ) {
F_47 ( V_96 , V_96 , V_7 ) ;
} else {
F_18 ( V_13 , V_96 , 0xff , V_7 ) ;
F_26 ( V_17 , V_13 , 8 , V_7 ) ;
F_29 ( V_13 , V_96 , 8 , V_7 ) ;
F_18 ( V_13 , V_13 , 0xff , V_7 ) ;
F_12 ( V_96 , V_17 , V_13 , V_7 ) ;
}
#endif
break;
case V_145 | V_171 :
V_7 -> V_71 |= V_111 | V_124 ;
F_74 ( F_75 ( struct V_172 ,
V_173 ) != 4 ) ;
V_101 = F_67 ( struct V_172 , V_173 ) ;
F_36 ( V_96 , 28 , V_101 , V_7 ) ;
break;
case V_145 | V_174 :
V_7 -> V_71 |= V_81 | V_111 ;
V_101 = F_67 ( struct V_86 , V_175 ) ;
F_48 ( V_125 , V_82 , V_101 , V_7 ) ;
F_53 ( V_58 , V_125 , V_14 ,
F_52 ( V_98 -> V_87 , V_7 ) , V_7 ) ;
F_51 ( V_128 , V_14 , V_7 ) ;
F_74 ( F_75 ( struct V_176 ,
V_177 ) != 4 ) ;
V_101 = F_67 ( struct V_176 , V_177 ) ;
F_36 ( V_96 , V_125 , V_101 , V_7 ) ;
break;
case V_145 | V_178 :
V_7 -> V_71 |= V_81 | V_111 ;
F_74 ( F_75 ( struct V_86 , V_179 ) != 4 ) ;
V_101 = F_67 ( struct V_86 , V_179 ) ;
F_36 ( V_96 , V_82 , V_101 , V_7 ) ;
break;
case V_145 | V_180 :
V_7 -> V_71 |= V_81 | V_111 ;
F_74 ( F_75 ( struct V_86 , V_181 ) != 4 ) ;
V_101 = F_67 ( struct V_86 , V_181 ) ;
F_36 ( V_96 , V_82 , V_101 , V_7 ) ;
break;
case V_145 | V_182 :
case V_145 | V_183 :
V_7 -> V_71 |= V_81 | V_111 ;
F_74 ( F_75 ( struct V_86 ,
V_184 ) != 2 ) ;
V_101 = F_67 ( struct V_86 , V_184 ) ;
F_38 ( V_125 , V_82 , V_101 , V_7 ) ;
if ( V_106 == ( V_145 | V_182 ) ) {
F_18 ( V_96 , V_125 , ( T_4 ) ~ V_185 , V_7 ) ;
} else {
F_18 ( V_96 , V_125 , V_185 , V_7 ) ;
F_31 ( V_96 , V_14 , V_96 , V_7 ) ;
}
break;
case V_145 | V_186 :
V_7 -> V_71 |= V_81 ;
F_37 ( V_17 , V_82 , F_79 () , V_7 ) ;
F_18 ( V_96 , V_17 , V_187 , V_7 ) ;
#ifdef F_80
F_29 ( V_96 , V_96 , 5 , V_7 ) ;
#endif
break;
case V_145 | V_188 :
V_7 -> V_71 |= V_81 | V_111 ;
F_74 ( F_75 ( struct V_86 ,
V_189 ) != 2 ) ;
F_74 ( F_67 ( struct V_86 ,
V_189 ) > 0xff ) ;
V_101 = F_67 ( struct V_86 , V_189 ) ;
F_38 ( V_96 , V_82 , V_101 , V_7 ) ;
break;
default:
F_72 ( L_3 , __FILE__ ,
V_100 -> V_106 ) ;
return - 1 ;
}
}
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_67 ] = V_7 -> V_12 * 4 ;
return 0 ;
}
void F_81 ( struct V_97 * V_190 )
{
struct V_6 V_7 ;
unsigned int V_191 , V_192 ;
if ( ! V_193 )
return;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_53 = F_82 ( V_190 -> V_87 + 1 , sizeof( * V_7 . V_53 ) , V_194 ) ;
if ( V_7 . V_53 == NULL )
return;
V_7 . V_94 = V_190 ;
if ( F_70 ( & V_7 ) )
goto V_195;
V_192 = V_7 . V_12 ;
F_66 ( & V_7 ) ;
V_7 . V_54 = ( V_7 . V_12 - V_192 ) * 4 ;
F_69 ( & V_7 ) ;
V_191 = 4 * V_7 . V_12 ;
V_7 . V_10 = F_83 ( V_191 ) ;
if ( V_7 . V_10 == NULL )
goto V_195;
memset ( V_7 . V_10 , 0 , V_191 ) ;
V_7 . V_12 = 0 ;
F_66 ( & V_7 ) ;
F_70 ( & V_7 ) ;
F_69 ( & V_7 ) ;
F_84 ( ( T_3 ) V_7 . V_10 , ( T_3 ) ( V_7 . V_10 + V_7 . V_12 ) ) ;
if ( V_193 > 1 )
F_85 ( V_190 -> V_87 , V_191 , 2 , V_7 . V_10 ) ;
V_190 -> V_196 = ( void * ) V_7 . V_10 ;
V_190 -> V_197 = 1 ;
V_195:
F_86 ( V_7 . V_53 ) ;
}
void F_87 ( struct V_97 * V_190 )
{
if ( V_190 -> V_197 )
F_88 ( V_190 -> V_196 ) ;
F_89 ( V_190 ) ;
}
