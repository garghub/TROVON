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
static inline void F_39 ( unsigned int V_29 , unsigned int V_38 ,
unsigned int V_25 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_45 , V_29 , V_25 , V_38 ) ;
}
static inline void F_40 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_46 , V_3 , V_4 , V_5 ) ;
}
static inline void F_41 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_42 ( & V_11 , V_3 , V_16 ) ;
V_11 = & V_7 -> V_10 [ V_7 -> V_12 + 1 ] ;
F_43 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_44 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
F_42 ( & V_11 , V_3 , V_16 ) ;
V_11 = & V_7 -> V_10 [ V_7 -> V_12 + 1 ] ;
F_45 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_46 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_47 , V_3 , V_16 , V_30 ) ;
}
static inline void F_47 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_48 , V_3 , V_16 , V_30 ) ;
}
static inline void F_48 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_49 , V_3 , V_16 ) ;
}
static inline void F_49 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_41 , V_3 , V_2 , V_16 ) ;
}
static inline void F_50 ( unsigned int V_29 , T_3 V_2 ,
struct V_6 * V_7 )
{
if ( F_51 ( V_50 ) ) {
F_8 ( V_17 , ( V_51 ) V_2 >> 32 , V_7 ) ;
F_46 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_17 , V_13 , ( V_2 >> 16 ) & 0xffff , V_7 ) ;
F_46 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_29 , V_13 , V_2 & 0xffff , V_7 ) ;
} else {
F_8 ( V_29 , V_2 , V_7 ) ;
}
}
static inline void F_52 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_52 , V_3 , V_16 , V_14 ) ;
}
static inline void F_27 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_5 ( V_3 , V_16 , V_14 , V_7 ) ;
}
static inline T_1 F_53 ( unsigned int V_53 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 == NULL )
return 0 ;
return V_7 -> V_54 [ V_53 ] -
( V_7 -> V_12 * 4 - V_7 -> V_55 ) - 4 ;
}
static inline void F_54 ( int V_56 , unsigned int V_57 , unsigned int V_58 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
switch ( V_56 ) {
case V_59 :
F_55 ( & V_11 , V_57 , V_58 , V_2 ) ;
break;
case V_60 :
F_56 ( & V_11 , V_57 , V_58 , V_2 ) ;
break;
case V_61 :
F_57 ( & V_11 , V_2 ) ;
break;
default:
F_58 ( L_1 ,
V_62 , V_56 ) ;
}
}
V_7 -> V_12 ++ ;
}
static inline void F_59 ( unsigned int V_2 , struct V_6 * V_7 )
{
F_54 ( V_61 , V_14 , V_14 , V_2 , V_7 ) ;
}
static inline void F_60 ( unsigned int V_63 , unsigned int V_29 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_64 , V_63 , V_29 ) ;
}
static inline void F_61 ( unsigned int V_29 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_65 , V_29 ) ;
}
static inline T_4 F_62 ( unsigned int V_66 )
{
unsigned int V_67 = F_51 ( V_50 ) ? 16 : 8 ;
V_66 = ( V_66 + ( V_67 - 1 ) ) & - V_67 ;
return V_66 ;
}
static void F_63 ( struct V_6 * V_7 , unsigned V_25 )
{
int V_68 = 0 , V_69 = 0 ;
T_1 V_70 , V_71 ;
if ( V_25 )
F_21 ( - F_62 ( V_25 ) , V_7 ) ;
V_71 = V_70 = V_7 -> V_72 >> V_73 ;
while ( V_71 ) {
if ( ( V_70 >> V_68 ) & 0x1 ) {
F_33 ( V_74 + V_68 , V_27 , V_69 ,
V_7 ) ;
V_69 += V_75 ;
}
V_68 ++ ;
V_71 >>= 1 ;
}
if ( V_7 -> V_72 & V_76 ) {
F_33 ( V_77 , V_27 , V_69 , V_7 ) ;
V_69 += V_75 ;
}
if ( V_7 -> V_72 & V_78 ) {
if ( V_69 % ( V_75 * 2 ) )
V_69 += V_75 ;
F_22 ( V_7 , V_26 , V_79 , V_27 , V_69 ) ;
}
}
static void F_64 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
int V_68 , V_69 = 0 ;
T_1 V_70 , V_71 ;
V_71 = V_70 = V_7 -> V_72 >> V_73 ;
V_68 = 0 ;
while ( V_71 ) {
if ( ( V_70 >> V_68 ) & 0x1 ) {
F_35 ( V_74 + V_68 , V_27 , V_69 ,
V_7 ) ;
V_69 += V_75 ;
}
V_68 ++ ;
V_71 >>= 1 ;
}
if ( V_7 -> V_72 & V_76 )
F_35 ( V_77 , V_27 , V_69 , V_7 ) ;
if ( V_25 )
F_21 ( F_62 ( V_25 ) , V_7 ) ;
}
static unsigned int F_65 ( struct V_6 * V_7 )
{
int V_80 = 0 ;
V_80 += F_66 ( V_7 -> V_72 >> V_73 ) * V_75 ;
if ( V_7 -> V_72 & V_78 )
V_80 += 4 * V_81 ;
if ( V_7 -> V_72 & V_76 )
V_80 += V_75 ;
return V_80 ;
}
static void F_67 ( struct V_6 * V_7 )
{
int V_80 ;
V_80 = F_65 ( V_7 ) ;
F_63 ( V_7 , V_80 ) ;
if ( V_7 -> V_72 & V_82 )
F_52 ( V_83 , V_84 , V_7 ) ;
if ( V_7 -> V_72 & V_85 ) {
F_36 ( V_86 , V_83 , F_68 ( struct V_87 , V_88 ) ,
V_7 ) ;
F_36 ( V_17 , V_83 , F_68 ( struct V_87 , V_89 ) ,
V_7 ) ;
F_49 ( V_90 , V_83 ,
F_68 ( struct V_87 , V_91 ) , V_7 ) ;
F_23 ( V_92 , V_86 , V_17 , V_7 ) ;
}
if ( V_7 -> V_72 & V_93 )
F_27 ( V_94 , V_14 , V_7 ) ;
if ( F_69 ( & V_7 -> V_95 -> V_96 [ 0 ] ) &&
( V_7 -> V_72 & V_97 ) )
F_27 ( V_98 , V_14 , V_7 ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
unsigned int V_80 ;
V_80 = F_65 ( V_7 ) ;
F_64 ( V_7 , V_80 ) ;
F_61 ( V_77 , V_7 ) ;
F_7 ( V_7 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
const struct V_99 * V_100 = V_7 -> V_95 ;
const struct V_101 * V_102 ;
unsigned int V_68 , V_103 , V_104 ;
T_1 V_1 , V_105 V_106 ;
T_5 (* F_72)( unsigned long * V_107 , int V_25 );
for ( V_68 = 0 ; V_68 < V_100 -> V_88 ; V_68 ++ ) {
T_4 V_108 ;
V_102 = & ( V_100 -> V_96 [ V_68 ] ) ;
F_73 ( L_2 ,
V_62 , V_102 -> V_108 , V_102 -> V_109 , V_102 -> V_110 , V_102 -> V_1 ) ;
V_1 = V_102 -> V_1 ;
V_108 = F_74 ( V_102 ) ;
if ( V_7 -> V_10 == NULL )
V_7 -> V_54 [ V_68 ] = V_7 -> V_12 * 4 ;
switch ( V_108 ) {
case V_111 | V_112 :
V_7 -> V_72 |= V_97 ;
F_8 ( V_98 , V_1 , V_7 ) ;
break;
case V_111 | V_113 | V_114 :
F_75 ( F_76 ( struct V_87 , V_88 ) != 4 ) ;
V_7 -> V_72 |= V_82 | V_97 ;
V_103 = F_68 ( struct V_87 , V_88 ) ;
F_36 ( V_98 , V_83 , V_103 , V_7 ) ;
break;
case V_111 | V_115 :
V_7 -> V_72 |= V_78 | V_97 ;
F_36 ( V_98 , V_79 , F_77 ( V_1 ) , V_7 ) ;
break;
case V_111 | V_113 | V_116 :
F_72 = F_78 ( V_1 , V_117 ) ;
goto V_118;
case V_111 | V_119 | V_116 :
F_72 = F_78 ( V_1 , V_120 ) ;
goto V_118;
case V_111 | V_121 | V_116 :
F_72 = F_78 ( V_1 , V_122 ) ;
V_118:
F_8 ( V_123 , V_1 , V_7 ) ;
V_124:
V_7 -> V_72 |= V_76 | V_125 |
V_82 | V_97 | V_85 ;
F_50 ( V_126 , ( T_3 ) F_72 , V_7 ) ;
F_52 ( V_84 , V_83 , V_7 ) ;
F_60 ( V_127 , V_126 , V_7 ) ;
F_52 ( V_128 , V_123 , V_7 ) ;
F_54 ( V_59 , V_129 , 0 , F_53 ( V_68 + 1 , V_7 ) ,
V_7 ) ;
F_52 ( V_129 , V_14 , V_7 ) ;
F_59 ( F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_111 | V_113 | V_130 :
F_72 = V_117 ;
goto V_131;
case V_111 | V_119 | V_130 :
F_72 = V_120 ;
goto V_131;
case V_111 | V_121 | V_130 :
F_72 = V_122 ;
V_131:
V_7 -> V_72 |= V_125 | V_93 ;
F_16 ( V_123 , V_94 , V_1 , V_7 ) ;
goto V_124;
case V_132 | V_112 :
V_7 -> V_72 |= V_93 ;
F_8 ( V_94 , V_1 , V_7 ) ;
break;
case V_132 | V_115 :
V_7 -> V_72 |= V_93 | V_78 ;
F_36 ( V_94 , V_79 , F_77 ( V_1 ) , V_7 ) ;
break;
case V_132 | V_113 | V_114 :
V_7 -> V_72 |= V_93 | V_82 ;
V_103 = F_68 ( struct V_87 , V_88 ) ;
F_36 ( V_94 , V_83 , V_103 , V_7 ) ;
break;
case V_132 | V_121 | V_133 :
V_7 -> V_72 |= V_93 | V_76 | V_82 ;
F_50 ( V_126 , ( T_3 ) V_122 , V_7 ) ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_60 ( V_127 , V_126 , V_7 ) ;
F_52 ( V_84 , V_83 , V_7 ) ;
F_54 ( V_60 , V_129 , 0 ,
F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_52 ( V_129 , V_14 , V_7 ) ;
F_18 ( V_94 , V_98 , 0xf , V_7 ) ;
F_59 ( F_53 ( V_68 + 1 , V_7 ) , V_7 ) ;
F_26 ( V_94 , V_94 , 2 , V_7 ) ;
break;
case V_134 :
V_7 -> V_72 |= V_78 | V_97 ;
F_34 ( V_98 , V_79 , F_77 ( V_1 ) , V_7 ) ;
break;
case V_135 :
V_7 -> V_72 |= V_78 | V_93 ;
F_34 ( V_94 , V_79 , F_77 ( V_1 ) , V_7 ) ;
break;
case V_136 | V_137 | V_138 :
V_7 -> V_72 |= V_97 ;
F_16 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_136 | V_137 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_5 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_140 | V_138 :
V_7 -> V_72 |= V_97 ;
F_16 ( V_98 , V_98 , - V_1 , V_7 ) ;
break;
case V_136 | V_140 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_23 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_141 | V_138 :
V_7 -> V_72 |= V_97 ;
F_8 ( V_126 , V_1 , V_7 ) ;
F_40 ( V_98 , V_98 , V_126 , V_7 ) ;
break;
case V_136 | V_141 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_40 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_142 | V_138 :
if ( V_1 == 1 )
break;
if ( F_1 ( & V_1 ) ) {
V_7 -> V_72 |= V_97 ;
F_29 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
}
V_7 -> V_72 |= V_97 ;
F_8 ( V_126 , V_1 , V_7 ) ;
F_41 ( V_98 , V_126 , V_7 ) ;
break;
case V_136 | V_143 | V_138 :
if ( V_1 == 1 ) {
V_7 -> V_72 |= V_97 ;
F_27 ( V_98 , V_14 , V_7 ) ;
} else {
V_7 -> V_72 |= V_97 ;
F_8 ( V_126 , V_1 , V_7 ) ;
F_44 ( V_98 , V_126 , V_7 ) ;
}
break;
case V_136 | V_142 | V_139 :
V_7 -> V_72 |= V_93 | V_97 ;
F_54 ( V_59 , V_94 , V_14 ,
F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_8 ( V_129 , 0 , V_7 ) ;
F_41 ( V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_143 | V_139 :
V_7 -> V_72 |= V_93 | V_97 ;
F_54 ( V_59 , V_94 , V_14 ,
F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_8 ( V_129 , 0 , V_7 ) ;
F_44 ( V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_144 | V_138 :
V_7 -> V_72 |= V_97 ;
F_13 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_136 | V_144 | V_139 :
V_7 -> V_72 |= V_97 ;
F_13 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_145 | V_138 :
V_7 -> V_72 |= V_97 ;
F_20 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_146 | V_147 :
case V_136 | V_145 | V_139 :
V_7 -> V_72 |= V_97 ;
F_19 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_148 | V_138 :
V_7 -> V_72 |= V_97 ;
F_18 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_136 | V_148 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_17 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_149 | V_138 :
V_7 -> V_72 |= V_97 ;
F_26 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_136 | V_149 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_25 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_150 | V_138 :
V_7 -> V_72 |= V_97 ;
F_29 ( V_98 , V_98 , V_1 , V_7 ) ;
break;
case V_136 | V_150 | V_139 :
V_7 -> V_72 |= V_97 | V_93 ;
F_28 ( V_98 , V_98 , V_94 , V_7 ) ;
break;
case V_136 | V_151 :
V_7 -> V_72 |= V_97 ;
F_24 ( V_98 , V_7 ) ;
break;
case V_152 | V_153 :
F_59 ( F_53 ( V_68 + V_1 + 1 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_152 | V_154 | V_138 :
V_104 = V_59 | V_155 ;
goto V_156;
case V_152 | V_154 | V_139 :
V_7 -> V_72 |= V_93 ;
V_104 = V_59 | V_157 ;
goto V_156;
case V_152 | V_158 | V_138 :
V_104 = V_159 | V_155 ;
goto V_156;
case V_152 | V_158 | V_139 :
V_7 -> V_72 |= V_93 ;
V_104 = V_159 | V_157 ;
goto V_156;
case V_152 | V_160 | V_138 :
V_104 = V_161 | V_155 ;
goto V_156;
case V_152 | V_160 | V_139 :
V_7 -> V_72 |= V_93 ;
V_104 = V_161 | V_157 ;
V_156:
if ( ( V_104 & V_159 ) ||
( V_104 & V_161 ) ) {
if ( V_104 & V_155 ) {
V_7 -> V_72 |= V_97 ;
F_32 ( V_126 , V_98 , V_1 , V_7 ) ;
} else {
V_7 -> V_72 |= V_97 |
V_93 ;
F_31 ( V_126 , V_98 , V_94 , V_7 ) ;
}
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 , V_7 ) ;
F_54 ( V_60 , V_126 , V_14 , V_105 ,
V_7 ) ;
F_7 ( V_7 ) ;
if ( V_104 & V_161 ) {
V_7 -> V_72 |= V_97 | V_93 ;
if ( V_104 & V_155 )
F_8 ( V_126 , V_1 , V_7 ) ;
else
F_27 ( V_126 , V_94 ,
V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 , V_7 ) ;
F_54 ( V_59 , V_98 , V_126 ,
V_105 , V_7 ) ;
F_7 ( V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 , V_7 ) ;
F_59 ( V_105 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 , V_7 ) ;
F_59 ( V_105 , V_7 ) ;
F_7 ( V_7 ) ;
}
} else {
if ( V_104 & V_155 ) {
V_7 -> V_72 |= V_97 ;
F_8 ( V_126 , V_1 , V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 , V_7 ) ;
F_54 ( V_59 , V_98 , V_126 ,
V_105 , V_7 ) ;
F_7 ( V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 ,
V_7 ) ;
F_54 ( V_60 , V_98 , V_126 ,
V_105 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_7 -> V_72 |= V_97 | V_93 ;
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 ,
V_7 ) ;
F_54 ( V_59 , V_98 , V_94 ,
V_105 , V_7 ) ;
F_7 ( V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 , V_7 ) ;
F_54 ( V_60 , V_98 , V_94 ,
V_105 , V_7 ) ;
F_7 ( V_7 ) ;
}
}
break;
case V_152 | V_162 | V_138 :
V_7 -> V_72 |= V_97 ;
F_8 ( V_163 , V_1 , V_7 ) ;
F_17 ( V_126 , V_98 , V_163 , V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 , V_7 ) ;
F_54 ( V_60 , V_126 , V_14 , V_105 , V_7 ) ;
F_7 ( V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 , V_7 ) ;
F_59 ( V_105 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_152 | V_162 | V_139 :
V_7 -> V_72 |= V_93 | V_97 ;
F_17 ( V_126 , V_98 , V_94 , V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_109 + 1 , V_7 ) ;
F_54 ( V_60 , V_126 , V_14 , V_105 , V_7 ) ;
F_7 ( V_7 ) ;
V_105 = F_53 ( V_68 + V_102 -> V_110 + 1 , V_7 ) ;
F_59 ( V_105 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_164 | V_165 :
V_7 -> V_72 |= V_97 ;
if ( V_68 != V_100 -> V_88 - 1 )
F_59 ( F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_52 ( V_129 , V_98 , V_7 ) ;
break;
case V_164 | V_138 :
F_8 ( V_129 , V_1 , V_7 ) ;
if ( V_68 != V_100 -> V_88 - 1 ) {
F_59 ( F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
}
break;
case V_166 | V_167 :
V_7 -> V_72 |= V_93 | V_97 ;
F_27 ( V_94 , V_98 , V_7 ) ;
break;
case V_166 | V_168 :
V_7 -> V_72 |= V_97 | V_93 ;
F_27 ( V_98 , V_94 , V_7 ) ;
break;
case V_146 | V_169 :
V_7 -> V_72 |= V_82 | V_125 | V_97 ;
F_75 ( F_76 ( struct V_87 ,
V_170 ) != 2 ) ;
V_103 = F_68 ( struct V_87 , V_170 ) ;
F_38 ( V_98 , V_83 , V_103 , V_7 ) ;
#ifdef F_79
if ( V_171 ) {
F_48 ( V_98 , V_98 , V_7 ) ;
} else {
F_18 ( V_13 , V_98 , 0xff , V_7 ) ;
F_26 ( V_17 , V_13 , 8 , V_7 ) ;
F_29 ( V_13 , V_98 , 8 , V_7 ) ;
F_18 ( V_13 , V_13 , 0xff , V_7 ) ;
F_12 ( V_98 , V_17 , V_13 , V_7 ) ;
}
#endif
break;
case V_146 | V_172 :
V_7 -> V_72 |= V_97 | V_125 ;
F_75 ( F_76 ( struct V_173 ,
V_174 ) != 4 ) ;
V_103 = F_68 ( struct V_173 , V_174 ) ;
F_36 ( V_98 , 28 , V_103 , V_7 ) ;
break;
case V_146 | V_175 :
case V_146 | V_176 :
V_7 -> V_72 |= V_82 | V_97 ;
V_103 = F_68 ( struct V_87 , V_177 ) ;
F_49 ( V_126 , V_83 , V_103 , V_7 ) ;
F_54 ( V_59 , V_126 , V_14 ,
F_53 ( V_100 -> V_88 , V_7 ) , V_7 ) ;
F_52 ( V_129 , V_14 , V_7 ) ;
if ( V_108 == ( V_146 | V_175 ) ) {
F_75 ( F_76 ( struct V_178 , V_179 ) != 4 ) ;
V_103 = F_68 ( struct V_178 , V_179 ) ;
F_36 ( V_98 , V_126 , V_103 , V_7 ) ;
} else {
F_75 ( F_76 ( struct V_178 , type ) != 2 ) ;
V_103 = F_68 ( struct V_178 , type ) ;
F_39 ( V_98 , V_126 , V_103 , V_7 ) ;
}
break;
case V_146 | V_180 :
V_7 -> V_72 |= V_82 | V_97 ;
F_75 ( F_76 ( struct V_87 , V_181 ) != 4 ) ;
V_103 = F_68 ( struct V_87 , V_181 ) ;
F_36 ( V_98 , V_83 , V_103 , V_7 ) ;
break;
case V_146 | V_182 :
V_7 -> V_72 |= V_82 | V_97 ;
F_75 ( F_76 ( struct V_87 , V_183 ) != 4 ) ;
V_103 = F_68 ( struct V_87 , V_183 ) ;
F_36 ( V_98 , V_83 , V_103 , V_7 ) ;
break;
case V_146 | V_184 :
case V_146 | V_185 :
V_7 -> V_72 |= V_82 | V_97 ;
F_75 ( F_76 ( struct V_87 ,
V_186 ) != 2 ) ;
V_103 = F_68 ( struct V_87 , V_186 ) ;
F_39 ( V_126 , V_83 , V_103 , V_7 ) ;
if ( V_108 == ( V_146 | V_184 ) ) {
F_18 ( V_98 , V_126 , ( T_4 ) ~ V_187 , V_7 ) ;
} else {
F_18 ( V_98 , V_126 , V_187 , V_7 ) ;
F_31 ( V_98 , V_14 , V_98 , V_7 ) ;
}
break;
case V_146 | V_188 :
V_7 -> V_72 |= V_82 ;
F_37 ( V_17 , V_83 , F_80 () , V_7 ) ;
F_18 ( V_98 , V_17 , V_189 , V_7 ) ;
#ifdef F_81
F_29 ( V_98 , V_98 , 5 , V_7 ) ;
#endif
break;
case V_146 | V_190 :
V_7 -> V_72 |= V_82 | V_97 ;
F_75 ( F_76 ( struct V_87 ,
V_191 ) != 2 ) ;
F_75 ( F_68 ( struct V_87 ,
V_191 ) > 0xff ) ;
V_103 = F_68 ( struct V_87 , V_191 ) ;
F_39 ( V_98 , V_83 , V_103 , V_7 ) ;
break;
default:
F_73 ( L_3 , __FILE__ ,
V_102 -> V_108 ) ;
return - 1 ;
}
}
if ( V_7 -> V_10 == NULL )
V_7 -> V_54 [ V_68 ] = V_7 -> V_12 * 4 ;
return 0 ;
}
void F_82 ( struct V_99 * V_192 )
{
struct V_6 V_7 ;
unsigned int V_193 , V_194 ;
if ( ! V_195 )
return;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_54 = F_83 ( V_192 -> V_88 + 1 , sizeof( * V_7 . V_54 ) , V_196 ) ;
if ( V_7 . V_54 == NULL )
return;
V_7 . V_95 = V_192 ;
if ( F_71 ( & V_7 ) )
goto V_197;
V_194 = V_7 . V_12 ;
F_67 ( & V_7 ) ;
V_7 . V_55 = ( V_7 . V_12 - V_194 ) * 4 ;
F_70 ( & V_7 ) ;
V_193 = 4 * V_7 . V_12 ;
V_7 . V_10 = F_84 ( V_193 ) ;
if ( V_7 . V_10 == NULL )
goto V_197;
memset ( V_7 . V_10 , 0 , V_193 ) ;
V_7 . V_12 = 0 ;
F_67 ( & V_7 ) ;
F_71 ( & V_7 ) ;
F_70 ( & V_7 ) ;
F_85 ( ( T_3 ) V_7 . V_10 , ( T_3 ) ( V_7 . V_10 + V_7 . V_12 ) ) ;
if ( V_195 > 1 )
F_86 ( V_192 -> V_88 , V_193 , 2 , V_7 . V_10 ) ;
V_192 -> V_198 = ( void * ) V_7 . V_10 ;
V_192 -> V_199 = 1 ;
V_197:
F_87 ( V_7 . V_54 ) ;
}
void F_88 ( struct V_99 * V_192 )
{
if ( V_192 -> V_199 )
F_89 ( V_192 -> V_198 ) ;
F_90 ( V_192 ) ;
}
