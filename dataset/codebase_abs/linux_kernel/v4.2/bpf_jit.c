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
static bool F_62 ( T_4 V_67 )
{
switch ( V_67 ) {
case V_68 | V_69 | V_70 :
case V_68 | V_69 | V_71 :
case V_68 | V_72 | V_71 :
case V_68 | V_73 | V_71 :
return true ;
default:
return false ;
}
}
static void F_63 ( struct V_6 * V_7 , unsigned V_25 )
{
int V_74 = 0 , V_75 = 0 ;
T_1 V_76 , V_77 ;
F_21 ( - F_61 ( V_25 ) , V_7 ) ;
V_77 = V_76 = V_7 -> V_78 >> V_79 ;
while ( V_77 ) {
if ( ( V_76 >> V_74 ) & 0x1 ) {
F_33 ( V_80 + V_74 , V_27 , V_75 ,
V_7 ) ;
V_75 += V_81 ;
}
V_74 ++ ;
V_77 >>= 1 ;
}
if ( V_7 -> V_78 & V_82 ) {
F_33 ( V_83 , V_27 , V_75 , V_7 ) ;
V_75 += V_81 ;
}
if ( V_7 -> V_78 & V_84 ) {
if ( V_75 % ( V_81 * 2 ) )
V_75 += V_81 ;
F_22 ( V_7 , V_26 , V_85 , V_27 , V_75 ) ;
}
}
static void F_64 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
int V_74 , V_75 = 0 ;
T_1 V_76 , V_77 ;
V_77 = V_76 = V_7 -> V_78 >> V_79 ;
V_74 = 0 ;
while ( V_77 ) {
if ( ( V_76 >> V_74 ) & 0x1 ) {
F_35 ( V_80 + V_74 , V_27 , V_75 ,
V_7 ) ;
V_75 += V_81 ;
}
V_74 ++ ;
V_77 >>= 1 ;
}
if ( V_7 -> V_78 & V_82 )
F_35 ( V_83 , V_27 , V_75 , V_7 ) ;
F_21 ( F_61 ( V_25 ) , V_7 ) ;
}
static unsigned int F_65 ( struct V_6 * V_7 )
{
int V_86 = 0 ;
V_86 += F_66 ( V_7 -> V_78 >> V_79 ) * V_81 ;
if ( V_7 -> V_78 & V_84 )
V_86 += 4 * V_87 ;
if ( V_7 -> V_78 & V_82 )
V_86 += V_81 ;
return V_86 ;
}
static void F_67 ( struct V_6 * V_7 )
{
T_4 V_88 = V_7 -> V_89 -> V_90 [ 0 ] . V_91 ;
int V_86 ;
V_86 = F_65 ( V_7 ) ;
F_63 ( V_7 , V_86 ) ;
if ( V_7 -> V_78 & V_92 )
F_51 ( V_93 , V_94 , V_7 ) ;
if ( V_7 -> V_78 & V_95 ) {
F_36 ( V_96 , V_93 , F_68 ( struct V_97 , V_98 ) ,
V_7 ) ;
F_36 ( V_17 , V_93 , F_68 ( struct V_97 , V_99 ) ,
V_7 ) ;
F_48 ( V_100 , V_93 ,
F_68 ( struct V_97 , V_101 ) , V_7 ) ;
F_23 ( V_102 , V_96 , V_17 , V_7 ) ;
}
if ( V_7 -> V_78 & V_103 )
F_27 ( V_104 , V_14 , V_7 ) ;
if ( ( V_88 != ( V_105 | V_106 ) ) && ! ( F_62 ( V_88 ) ) )
F_27 ( V_107 , V_14 , V_7 ) ;
}
static void F_69 ( struct V_6 * V_7 )
{
unsigned int V_86 ;
V_86 = F_65 ( V_7 ) ;
F_64 ( V_7 , V_86 ) ;
F_60 ( V_83 , V_7 ) ;
F_7 ( V_7 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
const struct V_108 * V_109 = V_7 -> V_89 ;
const struct V_110 * V_67 ;
unsigned int V_74 , V_111 , V_112 ;
T_1 V_1 , V_113 V_114 ;
T_5 (* F_71)( unsigned long * V_115 , int V_25 );
for ( V_74 = 0 ; V_74 < V_109 -> V_98 ; V_74 ++ ) {
T_4 V_91 ;
V_67 = & ( V_109 -> V_90 [ V_74 ] ) ;
F_72 ( L_2 ,
V_61 , V_67 -> V_91 , V_67 -> V_116 , V_67 -> V_117 , V_67 -> V_1 ) ;
V_1 = V_67 -> V_1 ;
V_91 = F_73 ( V_67 ) ;
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_74 ] = V_7 -> V_12 * 4 ;
switch ( V_91 ) {
case V_68 | V_118 :
V_7 -> V_78 |= V_119 ;
F_8 ( V_107 , V_1 , V_7 ) ;
break;
case V_68 | V_69 | V_70 :
F_74 ( F_75 ( struct V_97 , V_98 ) != 4 ) ;
V_7 -> V_78 |= V_92 | V_119 ;
V_111 = F_68 ( struct V_97 , V_98 ) ;
F_36 ( V_107 , V_93 , V_111 , V_7 ) ;
break;
case V_68 | V_120 :
V_7 -> V_78 |= V_84 | V_119 ;
F_36 ( V_107 , V_85 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_68 | V_69 | V_71 :
F_71 = F_77 ( V_1 , V_121 ) ;
goto V_122;
case V_68 | V_72 | V_71 :
F_71 = F_77 ( V_1 , V_123 ) ;
goto V_122;
case V_68 | V_73 | V_71 :
F_71 = F_77 ( V_1 , V_124 ) ;
V_122:
F_8 ( V_125 , V_1 , V_7 ) ;
V_126:
V_7 -> V_78 |= V_82 | V_127 |
V_92 | V_119 | V_95 ;
F_49 ( V_128 , ( T_3 ) F_71 , V_7 ) ;
F_51 ( V_94 , V_93 , V_7 ) ;
F_59 ( V_129 , V_128 , V_7 ) ;
F_51 ( V_130 , V_125 , V_7 ) ;
F_53 ( V_58 , V_131 , 0 , F_52 ( V_74 + 1 , V_7 ) ,
V_7 ) ;
F_51 ( V_131 , V_14 , V_7 ) ;
F_58 ( F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_68 | V_69 | V_132 :
F_71 = V_121 ;
goto V_133;
case V_68 | V_72 | V_132 :
F_71 = V_123 ;
goto V_133;
case V_68 | V_73 | V_132 :
F_71 = V_124 ;
V_133:
V_7 -> V_78 |= V_127 | V_103 ;
F_16 ( V_125 , V_104 , V_1 , V_7 ) ;
goto V_126;
case V_134 | V_118 :
V_7 -> V_78 |= V_103 ;
F_8 ( V_104 , V_1 , V_7 ) ;
break;
case V_134 | V_120 :
V_7 -> V_78 |= V_103 | V_84 ;
F_36 ( V_104 , V_85 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_134 | V_69 | V_70 :
V_7 -> V_78 |= V_103 | V_92 ;
V_111 = F_68 ( struct V_97 , V_98 ) ;
F_36 ( V_104 , V_93 , V_111 , V_7 ) ;
break;
case V_134 | V_73 | V_135 :
V_7 -> V_78 |= V_103 | V_82 | V_92 ;
F_49 ( V_128 , ( T_3 ) V_124 , V_7 ) ;
F_8 ( V_130 , V_1 , V_7 ) ;
F_59 ( V_129 , V_128 , V_7 ) ;
F_51 ( V_94 , V_93 , V_7 ) ;
F_53 ( V_59 , V_131 , 0 ,
F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_51 ( V_131 , V_14 , V_7 ) ;
F_18 ( V_104 , V_107 , 0xf , V_7 ) ;
F_58 ( F_52 ( V_74 + 1 , V_7 ) , V_7 ) ;
F_26 ( V_104 , V_104 , 2 , V_7 ) ;
break;
case V_136 :
V_7 -> V_78 |= V_84 | V_119 ;
F_34 ( V_107 , V_85 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_137 :
V_7 -> V_78 |= V_84 | V_103 ;
F_34 ( V_104 , V_85 , F_76 ( V_1 ) , V_7 ) ;
break;
case V_138 | V_139 | V_106 :
V_7 -> V_78 |= V_119 ;
F_16 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_138 | V_139 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_5 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_141 | V_106 :
V_7 -> V_78 |= V_119 ;
F_16 ( V_107 , V_107 , - V_1 , V_7 ) ;
break;
case V_138 | V_141 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_23 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_142 | V_106 :
V_7 -> V_78 |= V_119 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_39 ( V_107 , V_107 , V_128 , V_7 ) ;
break;
case V_138 | V_142 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_39 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_143 | V_106 :
if ( V_1 == 1 )
break;
if ( F_1 ( & V_1 ) ) {
V_7 -> V_78 |= V_119 ;
F_29 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
}
V_7 -> V_78 |= V_119 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_40 ( V_107 , V_128 , V_7 ) ;
break;
case V_138 | V_144 | V_106 :
if ( V_1 == 1 ) {
V_7 -> V_78 |= V_119 ;
F_27 ( V_107 , V_14 , V_7 ) ;
} else {
V_7 -> V_78 |= V_119 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_43 ( V_107 , V_128 , V_7 ) ;
}
break;
case V_138 | V_143 | V_140 :
V_7 -> V_78 |= V_103 | V_119 ;
F_53 ( V_58 , V_104 , V_14 ,
F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_8 ( V_131 , 0 , V_7 ) ;
F_40 ( V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_144 | V_140 :
V_7 -> V_78 |= V_103 | V_119 ;
F_53 ( V_58 , V_104 , V_14 ,
F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_8 ( V_131 , 0 , V_7 ) ;
F_43 ( V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_145 | V_106 :
V_7 -> V_78 |= V_119 ;
F_13 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_138 | V_145 | V_140 :
V_7 -> V_78 |= V_119 ;
F_13 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_146 | V_106 :
V_7 -> V_78 |= V_119 ;
F_20 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_147 | V_148 :
case V_138 | V_146 | V_140 :
V_7 -> V_78 |= V_119 ;
F_19 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_149 | V_106 :
V_7 -> V_78 |= V_119 ;
F_18 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_138 | V_149 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_17 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_150 | V_106 :
V_7 -> V_78 |= V_119 ;
F_26 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_138 | V_150 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_25 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_151 | V_106 :
V_7 -> V_78 |= V_119 ;
F_29 ( V_107 , V_107 , V_1 , V_7 ) ;
break;
case V_138 | V_151 | V_140 :
V_7 -> V_78 |= V_119 | V_103 ;
F_28 ( V_107 , V_107 , V_104 , V_7 ) ;
break;
case V_138 | V_152 :
V_7 -> V_78 |= V_119 ;
F_24 ( V_107 , V_7 ) ;
break;
case V_153 | V_154 :
F_58 ( F_52 ( V_74 + V_1 + 1 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_153 | V_155 | V_106 :
V_112 = V_58 | V_156 ;
goto V_157;
case V_153 | V_155 | V_140 :
V_7 -> V_78 |= V_103 ;
V_112 = V_58 | V_158 ;
goto V_157;
case V_153 | V_159 | V_106 :
V_112 = V_160 | V_156 ;
goto V_157;
case V_153 | V_159 | V_140 :
V_7 -> V_78 |= V_103 ;
V_112 = V_160 | V_158 ;
goto V_157;
case V_153 | V_161 | V_106 :
V_112 = V_162 | V_156 ;
goto V_157;
case V_153 | V_161 | V_140 :
V_7 -> V_78 |= V_103 ;
V_112 = V_162 | V_158 ;
V_157:
if ( ( V_112 & V_160 ) ||
( V_112 & V_162 ) ) {
if ( V_112 & V_156 ) {
V_7 -> V_78 |= V_119 ;
F_32 ( V_128 , V_107 , V_1 , V_7 ) ;
} else {
V_7 -> V_78 |= V_119 |
V_103 ;
F_31 ( V_128 , V_107 , V_104 , V_7 ) ;
}
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_53 ( V_59 , V_128 , V_14 , V_113 ,
V_7 ) ;
F_7 ( V_7 ) ;
if ( V_112 & V_162 ) {
V_7 -> V_78 |= V_119 | V_103 ;
if ( V_112 & V_156 )
F_8 ( V_128 , V_1 , V_7 ) ;
else
F_27 ( V_128 , V_104 ,
V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_53 ( V_58 , V_107 , V_128 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_58 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_58 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
}
} else {
if ( V_112 & V_156 ) {
V_7 -> V_78 |= V_119 ;
F_8 ( V_128 , V_1 , V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_53 ( V_58 , V_107 , V_128 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 ,
V_7 ) ;
F_53 ( V_59 , V_107 , V_128 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_7 -> V_78 |= V_119 | V_103 ;
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 ,
V_7 ) ;
F_53 ( V_58 , V_107 , V_104 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_53 ( V_59 , V_107 , V_104 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
}
}
break;
case V_153 | V_163 | V_106 :
V_7 -> V_78 |= V_119 ;
F_8 ( V_164 , V_1 , V_7 ) ;
F_17 ( V_128 , V_107 , V_164 , V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_53 ( V_59 , V_128 , V_14 , V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_58 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_153 | V_163 | V_140 :
V_7 -> V_78 |= V_103 | V_119 ;
F_17 ( V_128 , V_107 , V_104 , V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_53 ( V_59 , V_128 , V_14 , V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_52 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_58 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_105 | V_165 :
V_7 -> V_78 |= V_119 ;
if ( V_74 != V_109 -> V_98 - 1 )
F_58 ( F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_51 ( V_131 , V_107 , V_7 ) ;
break;
case V_105 | V_106 :
F_8 ( V_131 , V_1 , V_7 ) ;
if ( V_74 != V_109 -> V_98 - 1 ) {
F_58 ( F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
}
break;
case V_166 | V_167 :
V_7 -> V_78 |= V_103 | V_119 ;
F_27 ( V_104 , V_107 , V_7 ) ;
break;
case V_166 | V_168 :
V_7 -> V_78 |= V_119 | V_103 ;
F_27 ( V_107 , V_104 , V_7 ) ;
break;
case V_147 | V_169 :
V_7 -> V_78 |= V_92 | V_127 | V_119 ;
F_74 ( F_75 ( struct V_97 ,
V_170 ) != 2 ) ;
V_111 = F_68 ( struct V_97 , V_170 ) ;
F_38 ( V_107 , V_93 , V_111 , V_7 ) ;
#ifdef F_78
if ( V_171 ) {
F_47 ( V_107 , V_107 , V_7 ) ;
} else {
F_18 ( V_13 , V_107 , 0xff , V_7 ) ;
F_26 ( V_17 , V_13 , 8 , V_7 ) ;
F_29 ( V_13 , V_107 , 8 , V_7 ) ;
F_18 ( V_13 , V_13 , 0xff , V_7 ) ;
F_12 ( V_107 , V_17 , V_13 , V_7 ) ;
}
#endif
break;
case V_147 | V_172 :
V_7 -> V_78 |= V_119 | V_127 ;
F_74 ( F_75 ( struct V_173 ,
V_174 ) != 4 ) ;
V_111 = F_68 ( struct V_173 , V_174 ) ;
F_36 ( V_107 , 28 , V_111 , V_7 ) ;
break;
case V_147 | V_175 :
V_7 -> V_78 |= V_92 | V_119 ;
V_111 = F_68 ( struct V_97 , V_176 ) ;
F_48 ( V_128 , V_93 , V_111 , V_7 ) ;
F_53 ( V_58 , V_128 , V_14 ,
F_52 ( V_109 -> V_98 , V_7 ) , V_7 ) ;
F_51 ( V_131 , V_14 , V_7 ) ;
F_74 ( F_75 ( struct V_177 ,
V_178 ) != 4 ) ;
V_111 = F_68 ( struct V_177 , V_178 ) ;
F_36 ( V_107 , V_128 , V_111 , V_7 ) ;
break;
case V_147 | V_179 :
V_7 -> V_78 |= V_92 | V_119 ;
F_74 ( F_75 ( struct V_97 , V_180 ) != 4 ) ;
V_111 = F_68 ( struct V_97 , V_180 ) ;
F_36 ( V_107 , V_93 , V_111 , V_7 ) ;
break;
case V_147 | V_181 :
V_7 -> V_78 |= V_92 | V_119 ;
F_74 ( F_75 ( struct V_97 , V_182 ) != 4 ) ;
V_111 = F_68 ( struct V_97 , V_182 ) ;
F_36 ( V_107 , V_93 , V_111 , V_7 ) ;
break;
case V_147 | V_183 :
case V_147 | V_184 :
V_7 -> V_78 |= V_92 | V_119 ;
F_74 ( F_75 ( struct V_97 ,
V_185 ) != 2 ) ;
V_111 = F_68 ( struct V_97 , V_185 ) ;
F_38 ( V_128 , V_93 , V_111 , V_7 ) ;
if ( V_91 == ( V_147 | V_183 ) ) {
F_18 ( V_107 , V_128 , ( T_4 ) ~ V_186 , V_7 ) ;
} else {
F_18 ( V_107 , V_128 , V_186 , V_7 ) ;
F_31 ( V_107 , V_14 , V_107 , V_7 ) ;
}
break;
case V_147 | V_187 :
V_7 -> V_78 |= V_92 ;
F_37 ( V_17 , V_93 , F_79 () , V_7 ) ;
F_18 ( V_107 , V_17 , V_188 , V_7 ) ;
#ifdef F_80
F_29 ( V_107 , V_107 , 5 , V_7 ) ;
#endif
break;
case V_147 | V_189 :
V_7 -> V_78 |= V_92 | V_119 ;
F_74 ( F_75 ( struct V_97 ,
V_190 ) != 2 ) ;
F_74 ( F_68 ( struct V_97 ,
V_190 ) > 0xff ) ;
V_111 = F_68 ( struct V_97 , V_190 ) ;
F_38 ( V_107 , V_93 , V_111 , V_7 ) ;
break;
default:
F_72 ( L_3 , __FILE__ ,
V_67 -> V_91 ) ;
return - 1 ;
}
}
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_74 ] = V_7 -> V_12 * 4 ;
return 0 ;
}
void F_81 ( struct V_108 * V_191 )
{
struct V_6 V_7 ;
unsigned int V_192 , V_193 ;
if ( ! V_194 )
return;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_53 = F_82 ( V_191 -> V_98 , sizeof( * V_7 . V_53 ) , V_195 ) ;
if ( V_7 . V_53 == NULL )
return;
V_7 . V_89 = V_191 ;
if ( F_70 ( & V_7 ) )
goto V_196;
V_193 = V_7 . V_12 ;
F_67 ( & V_7 ) ;
V_7 . V_54 = ( V_7 . V_12 - V_193 ) * 4 ;
F_69 ( & V_7 ) ;
V_192 = 4 * V_7 . V_12 ;
V_7 . V_10 = F_83 ( V_192 ) ;
if ( V_7 . V_10 == NULL )
goto V_196;
memset ( V_7 . V_10 , 0 , V_192 ) ;
V_7 . V_12 = 0 ;
F_67 ( & V_7 ) ;
F_70 ( & V_7 ) ;
F_69 ( & V_7 ) ;
F_84 ( ( T_3 ) V_7 . V_10 , ( T_3 ) ( V_7 . V_10 + V_7 . V_12 ) ) ;
if ( V_194 > 1 )
F_85 ( V_191 -> V_98 , V_192 , 2 , V_7 . V_10 ) ;
V_191 -> V_197 = ( void * ) V_7 . V_10 ;
V_191 -> V_198 = true ;
V_196:
F_86 ( V_7 . V_53 ) ;
}
void F_87 ( struct V_108 * V_191 )
{
if ( V_191 -> V_198 )
F_88 ( V_191 -> V_197 ) ;
F_89 ( V_191 ) ;
}
