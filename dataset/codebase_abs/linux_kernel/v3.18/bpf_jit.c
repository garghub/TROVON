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
F_42 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_44 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_46 , V_3 , V_16 , V_30 ) ;
}
static inline void F_45 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_47 , V_3 , V_16 , V_30 ) ;
}
static inline void F_46 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_48 , V_3 , V_16 ) ;
}
static inline void F_47 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_41 , V_3 , V_2 , V_16 ) ;
}
static inline void F_48 ( unsigned int V_29 , T_3 V_2 ,
struct V_6 * V_7 )
{
if ( F_49 ( V_49 ) ) {
F_8 ( V_17 , ( V_50 ) V_2 >> 32 , V_7 ) ;
F_44 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_17 , V_13 , ( V_2 >> 16 ) & 0xffff , V_7 ) ;
F_44 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_29 , V_13 , V_2 & 0xffff , V_7 ) ;
} else {
F_8 ( V_29 , V_2 , V_7 ) ;
}
}
static inline void F_50 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_22 ( V_7 , V_51 , V_3 , V_16 , V_14 ) ;
}
static inline void F_27 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_5 ( V_3 , V_16 , V_14 , V_7 ) ;
}
static inline T_1 F_51 ( unsigned int V_52 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 == NULL )
return 0 ;
return V_7 -> V_53 [ V_52 ] -
( V_7 -> V_12 * 4 - V_7 -> V_54 ) - 4 ;
}
static inline void F_52 ( int V_55 , unsigned int V_56 , unsigned int V_57 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
switch ( V_55 ) {
case V_58 :
F_53 ( & V_11 , V_56 , V_57 , V_2 ) ;
break;
case V_59 :
F_54 ( & V_11 , V_56 , V_57 , V_2 ) ;
break;
case V_60 :
F_55 ( & V_11 , V_2 ) ;
break;
default:
F_56 ( L_1 ,
V_61 , V_55 ) ;
}
}
V_7 -> V_12 ++ ;
}
static inline void F_57 ( unsigned int V_2 , struct V_6 * V_7 )
{
F_52 ( V_60 , V_14 , V_14 , V_2 , V_7 ) ;
}
static inline void F_58 ( unsigned int V_62 , unsigned int V_29 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_63 , V_62 , V_29 ) ;
}
static inline void F_59 ( unsigned int V_29 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_64 , V_29 ) ;
}
static inline T_4 F_60 ( unsigned int V_65 )
{
unsigned int V_66 = F_49 ( V_49 ) ? 16 : 8 ;
V_65 = ( V_65 + ( V_66 - 1 ) ) & - V_66 ;
return V_65 ;
}
static bool F_61 ( T_4 V_67 )
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
static void F_62 ( struct V_6 * V_7 , unsigned V_25 )
{
int V_74 = 0 , V_75 = 0 ;
T_1 V_76 , V_77 ;
F_21 ( - F_60 ( V_25 ) , V_7 ) ;
if ( V_7 -> V_78 & V_79 ) {
if ( F_49 ( V_49 ) )
V_75 = F_60 ( V_25 ) - V_80 ;
else
V_75 = F_60 ( V_25 ) + V_80 ;
F_33 ( V_81 , V_27 , V_75 , V_7 ) ;
F_33 ( V_82 , V_27 , V_75 + V_80 , V_7 ) ;
V_75 = 0 ;
}
V_77 = V_76 = V_7 -> V_78 >> V_83 ;
while ( V_77 ) {
if ( ( V_76 >> V_74 ) & 0x1 ) {
F_33 ( V_84 + V_74 , V_27 , V_75 ,
V_7 ) ;
V_75 += V_80 ;
}
V_74 ++ ;
V_77 >>= 1 ;
}
if ( V_7 -> V_78 & V_79 ) {
F_33 ( V_85 , V_27 , V_75 , V_7 ) ;
V_75 += V_80 ;
}
if ( V_7 -> V_78 & V_86 ) {
if ( V_75 % ( V_80 * 2 ) )
V_75 += V_80 ;
F_22 ( V_7 , V_26 , V_87 , V_27 , V_75 ) ;
}
}
static void F_63 ( struct V_6 * V_7 ,
unsigned int V_25 )
{
int V_74 , V_75 = 0 ;
T_1 V_76 , V_77 ;
if ( V_7 -> V_78 & V_79 ) {
if ( F_49 ( V_49 ) )
V_75 = F_60 ( V_25 ) - V_80 ;
else
V_75 = F_60 ( V_25 ) + V_80 ;
F_35 ( V_81 , V_27 , V_75 , V_7 ) ;
F_35 ( V_82 , V_27 , V_75 + V_80 , V_7 ) ;
V_75 = 0 ;
}
V_77 = V_76 = V_7 -> V_78 >> V_83 ;
V_74 = 0 ;
while ( V_77 ) {
if ( ( V_76 >> V_74 ) & 0x1 ) {
F_35 ( V_84 + V_74 , V_27 , V_75 ,
V_7 ) ;
V_75 += V_80 ;
}
V_74 ++ ;
V_77 >>= 1 ;
}
if ( V_7 -> V_78 & V_79 )
F_35 ( V_85 , V_27 , V_75 , V_7 ) ;
F_21 ( F_60 ( V_25 ) , V_7 ) ;
}
static unsigned int F_64 ( struct V_6 * V_7 )
{
int V_88 = 0 ;
V_88 += F_65 ( V_7 -> V_78 >> V_83 ) * V_80 ;
if ( V_7 -> V_78 & V_86 )
V_88 += 4 * V_89 ;
if ( V_7 -> V_78 & V_79 )
V_88 += F_49 ( V_49 ) ?
( V_90 + 1 ) * V_80 : V_80 ;
return V_88 - V_80 ;
}
static void F_66 ( struct V_6 * V_7 )
{
T_4 V_91 = V_7 -> V_92 -> V_93 [ 0 ] . V_94 ;
int V_88 ;
V_88 = F_64 ( V_7 ) ;
F_62 ( V_7 , V_88 ) ;
if ( V_7 -> V_78 & V_95 )
F_50 ( V_96 , V_81 , V_7 ) ;
if ( V_7 -> V_78 & V_97 )
F_27 ( V_98 , V_14 , V_7 ) ;
if ( ( V_91 != ( V_99 | V_100 ) ) && ! ( F_61 ( V_91 ) ) )
F_27 ( V_101 , V_14 , V_7 ) ;
}
static void F_67 ( struct V_6 * V_7 )
{
unsigned int V_88 ;
V_88 = F_64 ( V_7 ) ;
F_63 ( V_7 , V_88 ) ;
F_59 ( V_85 , V_7 ) ;
F_7 ( V_7 ) ;
}
static V_50 F_68 ( struct V_102 * V_103 , unsigned V_25 )
{
T_5 V_104 ;
int V_105 ;
V_105 = F_69 ( V_103 , V_25 , & V_104 , 1 ) ;
return ( V_50 ) V_105 << 32 | V_104 ;
}
static V_50 F_70 ( struct V_102 * V_103 , unsigned V_25 )
{
T_4 V_104 ;
int V_105 ;
V_105 = F_69 ( V_103 , V_25 , & V_104 , 2 ) ;
return ( V_50 ) V_105 << 32 | F_71 ( V_104 ) ;
}
static V_50 F_72 ( struct V_102 * V_103 , unsigned V_25 )
{
T_1 V_104 ;
int V_105 ;
V_105 = F_69 ( V_103 , V_25 , & V_104 , 4 ) ;
return ( V_50 ) V_105 << 32 | F_73 ( V_104 ) ;
}
static int F_74 ( struct V_6 * V_7 )
{
void * V_106 [] = { F_68 , F_70 , F_72 } ;
const struct V_107 * V_108 = V_7 -> V_92 ;
const struct V_109 * V_67 ;
unsigned int V_74 , V_110 , V_111 , V_112 ;
T_1 V_1 , V_113 V_114 ;
for ( V_74 = 0 ; V_74 < V_108 -> V_115 ; V_74 ++ ) {
T_4 V_94 ;
V_67 = & ( V_108 -> V_93 [ V_74 ] ) ;
F_75 ( L_2 ,
V_61 , V_67 -> V_94 , V_67 -> V_116 , V_67 -> V_117 , V_67 -> V_1 ) ;
V_1 = V_67 -> V_1 ;
V_94 = F_76 ( V_67 ) ;
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_74 ] = V_7 -> V_12 * 4 ;
switch ( V_94 ) {
case V_68 | V_118 :
V_7 -> V_78 |= V_119 ;
F_8 ( V_101 , V_1 , V_7 ) ;
break;
case V_68 | V_69 | V_70 :
F_77 ( F_78 ( struct V_102 , V_115 ) != 4 ) ;
V_7 -> V_78 |= V_95 | V_119 ;
V_110 = F_79 ( struct V_102 , V_115 ) ;
F_36 ( V_101 , V_96 , V_110 , V_7 ) ;
break;
case V_68 | V_120 :
V_7 -> V_78 |= V_86 | V_119 ;
F_36 ( V_101 , V_87 , F_80 ( V_1 ) , V_7 ) ;
break;
case V_68 | V_69 | V_71 :
V_111 = 2 ;
goto V_121;
case V_68 | V_72 | V_71 :
V_111 = 1 ;
goto V_121;
case V_68 | V_73 | V_71 :
V_111 = 0 ;
V_121:
if ( ( int ) V_1 < 0 )
return - V_122 ;
F_8 ( V_123 , V_1 , V_7 ) ;
V_124:
F_30 ( V_125 , V_123 , V_14 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 ,
F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_50 ( V_126 , V_14 , V_7 ) ;
V_7 -> V_78 |= V_79 | V_127 | V_128 |
V_95 | V_119 ;
F_48 ( V_125 , ( T_3 ) V_106 [ V_111 ] ,
V_7 ) ;
F_50 ( V_81 , V_96 , V_7 ) ;
F_58 ( V_129 , V_125 , V_7 ) ;
F_50 ( V_82 , V_123 , V_7 ) ;
if ( F_49 ( V_49 ) ) {
F_45 ( V_125 , V_130 , 0 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 , 3 << 2 ,
V_7 ) ;
} else {
F_52 ( V_59 , V_131 , V_14 , 3 << 2 ,
V_7 ) ;
}
F_7 ( V_7 ) ;
F_57 ( F_51 ( V_74 + 1 , V_7 ) , V_7 ) ;
F_27 ( V_101 , V_130 , V_7 ) ;
F_57 ( F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_50 ( V_126 , V_14 , V_7 ) ;
break;
case V_68 | V_69 | V_132 :
V_111 = 2 ;
goto V_133;
case V_68 | V_72 | V_132 :
V_111 = 1 ;
goto V_133;
case V_68 | V_73 | V_132 :
V_111 = 0 ;
V_133:
V_7 -> V_78 |= V_127 | V_97 ;
F_16 ( V_123 , V_98 , V_1 , V_7 ) ;
goto V_124;
case V_134 | V_118 :
V_7 -> V_78 |= V_97 ;
F_8 ( V_98 , V_1 , V_7 ) ;
break;
case V_134 | V_120 :
V_7 -> V_78 |= V_97 | V_86 ;
F_36 ( V_98 , V_87 , F_80 ( V_1 ) , V_7 ) ;
break;
case V_134 | V_69 | V_70 :
V_7 -> V_78 |= V_97 | V_95 ;
V_110 = F_79 ( struct V_102 , V_115 ) ;
F_36 ( V_98 , V_96 , V_110 , V_7 ) ;
break;
case V_134 | V_73 | V_135 :
if ( ( int ) V_1 < 0 )
return - V_122 ;
V_7 -> V_78 |= V_97 | V_79 | V_128 | V_95 ;
F_48 ( V_125 , ( T_3 ) F_68 , V_7 ) ;
F_8 ( V_82 , V_1 , V_7 ) ;
F_58 ( V_129 , V_125 , V_7 ) ;
F_50 ( V_81 , V_96 , V_7 ) ;
if ( F_49 ( V_49 ) ) {
F_45 ( V_125 , V_130 , 0 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 ,
3 << 2 , V_7 ) ;
} else {
F_52 ( V_59 , V_131 , V_14 ,
3 << 2 , V_7 ) ;
}
F_18 ( V_98 , V_130 , 0xf , V_7 ) ;
F_57 ( F_51 ( V_74 + 1 , V_7 ) , V_7 ) ;
F_26 ( V_98 , V_98 , 2 , V_7 ) ;
F_57 ( F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_8 ( V_126 , 0 , V_7 ) ;
break;
case V_136 :
V_7 -> V_78 |= V_86 | V_119 ;
F_34 ( V_101 , V_87 , F_80 ( V_1 ) , V_7 ) ;
break;
case V_137 :
V_7 -> V_78 |= V_86 | V_97 ;
F_34 ( V_98 , V_87 , F_80 ( V_1 ) , V_7 ) ;
break;
case V_138 | V_139 | V_100 :
V_7 -> V_78 |= V_119 ;
F_16 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_138 | V_139 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_5 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_141 | V_100 :
V_7 -> V_78 |= V_119 ;
F_16 ( V_101 , V_101 , - V_1 , V_7 ) ;
break;
case V_138 | V_141 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_23 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_142 | V_100 :
V_7 -> V_78 |= V_119 | V_128 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_39 ( V_101 , V_101 , V_125 , V_7 ) ;
break;
case V_138 | V_142 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_39 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_143 | V_100 :
if ( V_1 == 1 )
break;
if ( F_1 ( & V_1 ) ) {
V_7 -> V_78 |= V_119 ;
F_29 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
}
V_7 -> V_78 |= V_119 | V_128 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_40 ( V_101 , V_125 , V_7 ) ;
break;
case V_138 | V_144 | V_100 :
if ( V_1 == 1 || F_1 ( & V_1 ) ) {
V_7 -> V_78 |= V_119 ;
F_27 ( V_101 , V_14 , V_7 ) ;
} else {
V_7 -> V_78 |= V_119 | V_128 ;
F_8 ( V_125 , V_1 , V_7 ) ;
F_43 ( V_101 , V_125 , V_7 ) ;
}
break;
case V_138 | V_143 | V_140 :
V_7 -> V_78 |= V_97 | V_119 ;
F_52 ( V_58 , V_98 , V_14 ,
F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_8 ( V_130 , 0 , V_7 ) ;
F_40 ( V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_144 | V_140 :
V_7 -> V_78 |= V_97 | V_119 ;
F_52 ( V_58 , V_98 , V_14 ,
F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_8 ( V_130 , 0 , V_7 ) ;
F_43 ( V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_145 | V_100 :
V_7 -> V_78 |= V_119 ;
F_13 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_138 | V_145 | V_140 :
V_7 -> V_78 |= V_119 ;
F_13 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_146 | V_100 :
V_7 -> V_78 |= V_119 ;
F_20 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_147 | V_148 :
case V_138 | V_146 | V_140 :
V_7 -> V_78 |= V_119 ;
F_19 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_149 | V_100 :
V_7 -> V_78 |= V_119 ;
F_18 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_138 | V_149 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_17 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_150 | V_100 :
V_7 -> V_78 |= V_119 ;
F_26 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_138 | V_150 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_25 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_151 | V_100 :
V_7 -> V_78 |= V_119 ;
F_29 ( V_101 , V_101 , V_1 , V_7 ) ;
break;
case V_138 | V_151 | V_140 :
V_7 -> V_78 |= V_119 | V_97 ;
F_28 ( V_101 , V_101 , V_98 , V_7 ) ;
break;
case V_138 | V_152 :
V_7 -> V_78 |= V_119 ;
F_24 ( V_101 , V_7 ) ;
break;
case V_153 | V_154 :
F_57 ( F_51 ( V_74 + V_1 + 1 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_153 | V_155 | V_100 :
V_112 = V_58 | V_156 ;
goto V_157;
case V_153 | V_155 | V_140 :
V_7 -> V_78 |= V_97 ;
V_112 = V_58 | V_158 ;
goto V_157;
case V_153 | V_159 | V_100 :
V_112 = V_160 | V_156 ;
goto V_157;
case V_153 | V_159 | V_140 :
V_7 -> V_78 |= V_97 ;
V_112 = V_160 | V_158 ;
goto V_157;
case V_153 | V_161 | V_100 :
V_112 = V_162 | V_156 ;
goto V_157;
case V_153 | V_161 | V_140 :
V_7 -> V_78 |= V_97 ;
V_112 = V_162 | V_158 ;
V_157:
if ( ( V_112 & V_160 ) ||
( V_112 & V_162 ) ) {
if ( V_112 & V_156 ) {
V_7 -> V_78 |= V_128 | V_119 ;
F_32 ( V_125 , V_101 , V_1 , V_7 ) ;
} else {
V_7 -> V_78 |= V_128 | V_119 |
V_97 ;
F_31 ( V_125 , V_101 , V_98 , V_7 ) ;
}
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 , V_113 ,
V_7 ) ;
F_7 ( V_7 ) ;
if ( V_112 & V_162 ) {
V_7 -> V_78 |= V_128 | V_119 | V_97 ;
if ( V_112 & V_156 )
F_8 ( V_125 , V_1 , V_7 ) ;
else
F_27 ( V_125 , V_98 ,
V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_52 ( V_58 , V_101 , V_125 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_57 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_57 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
}
} else {
if ( V_112 & V_156 ) {
V_7 -> V_78 |= V_128 | V_119 ;
F_8 ( V_125 , V_1 , V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_52 ( V_58 , V_101 , V_125 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 ,
V_7 ) ;
F_52 ( V_59 , V_101 , V_125 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_7 -> V_78 |= V_119 | V_97 ;
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 ,
V_7 ) ;
F_52 ( V_58 , V_101 , V_98 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_52 ( V_59 , V_101 , V_98 ,
V_113 , V_7 ) ;
F_7 ( V_7 ) ;
}
}
break;
case V_153 | V_163 | V_100 :
V_7 -> V_78 |= V_128 | V_164 | V_119 ;
F_8 ( V_165 , V_1 , V_7 ) ;
F_17 ( V_125 , V_101 , V_165 , V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 , V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_57 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_153 | V_163 | V_140 :
V_7 -> V_78 |= V_128 | V_97 | V_119 ;
F_17 ( V_125 , V_101 , V_98 , V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_116 + 1 , V_7 ) ;
F_52 ( V_59 , V_125 , V_14 , V_113 , V_7 ) ;
F_7 ( V_7 ) ;
V_113 = F_51 ( V_74 + V_67 -> V_117 + 1 , V_7 ) ;
F_57 ( V_113 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_99 | V_166 :
V_7 -> V_78 |= V_119 ;
if ( V_74 != V_108 -> V_115 - 1 )
F_57 ( F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_50 ( V_126 , V_101 , V_7 ) ;
break;
case V_99 | V_100 :
F_8 ( V_126 , V_1 , V_7 ) ;
if ( V_74 != V_108 -> V_115 - 1 ) {
F_57 ( F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
}
break;
case V_167 | V_168 :
V_7 -> V_78 |= V_97 | V_119 ;
F_27 ( V_98 , V_101 , V_7 ) ;
break;
case V_167 | V_169 :
V_7 -> V_78 |= V_119 | V_97 ;
F_27 ( V_101 , V_98 , V_7 ) ;
break;
case V_147 | V_170 :
V_7 -> V_78 |= V_95 | V_127 | V_119 ;
F_77 ( F_78 ( struct V_102 ,
V_171 ) != 2 ) ;
V_110 = F_79 ( struct V_102 , V_171 ) ;
F_38 ( V_101 , V_96 , V_110 , V_7 ) ;
#ifdef F_81
if ( V_172 ) {
F_46 ( V_101 , V_101 , V_7 ) ;
} else {
F_18 ( V_13 , V_101 , 0xff , V_7 ) ;
F_26 ( V_17 , V_13 , 8 , V_7 ) ;
F_29 ( V_13 , V_101 , 8 , V_7 ) ;
F_18 ( V_13 , V_13 , 0xff , V_7 ) ;
F_12 ( V_101 , V_17 , V_13 , V_7 ) ;
}
#endif
break;
case V_147 | V_173 :
V_7 -> V_78 |= V_119 | V_127 ;
F_77 ( F_78 ( struct V_174 ,
V_175 ) != 4 ) ;
V_110 = F_79 ( struct V_174 , V_175 ) ;
F_36 ( V_101 , 28 , V_110 , V_7 ) ;
break;
case V_147 | V_176 :
V_7 -> V_78 |= V_95 | V_119 | V_128 ;
V_110 = F_79 ( struct V_102 , V_177 ) ;
F_47 ( V_125 , V_96 , V_110 , V_7 ) ;
F_52 ( V_58 , V_125 , V_14 ,
F_51 ( V_108 -> V_115 , V_7 ) , V_7 ) ;
F_50 ( V_126 , V_14 , V_7 ) ;
F_77 ( F_78 ( struct V_178 ,
V_179 ) != 4 ) ;
V_110 = F_79 ( struct V_178 , V_179 ) ;
F_36 ( V_101 , V_125 , V_110 , V_7 ) ;
break;
case V_147 | V_180 :
V_7 -> V_78 |= V_95 | V_119 ;
F_77 ( F_78 ( struct V_102 , V_181 ) != 4 ) ;
V_110 = F_79 ( struct V_102 , V_181 ) ;
F_36 ( V_101 , V_96 , V_110 , V_7 ) ;
break;
case V_147 | V_182 :
V_7 -> V_78 |= V_95 | V_119 ;
F_77 ( F_78 ( struct V_102 , V_183 ) != 4 ) ;
V_110 = F_79 ( struct V_102 , V_183 ) ;
F_36 ( V_101 , V_96 , V_110 , V_7 ) ;
break;
case V_147 | V_184 :
case V_147 | V_185 :
V_7 -> V_78 |= V_95 | V_128 | V_119 ;
F_77 ( F_78 ( struct V_102 ,
V_186 ) != 2 ) ;
V_110 = F_79 ( struct V_102 , V_186 ) ;
F_38 ( V_125 , V_96 , V_110 , V_7 ) ;
if ( V_94 == ( V_147 | V_184 ) ) {
F_18 ( V_101 , V_125 , ( T_4 ) ~ V_187 , V_7 ) ;
} else {
F_18 ( V_101 , V_125 , V_187 , V_7 ) ;
F_31 ( V_101 , V_14 , V_101 , V_7 ) ;
}
break;
case V_147 | V_188 :
V_7 -> V_78 |= V_95 ;
F_37 ( V_17 , V_96 , F_82 () , V_7 ) ;
F_18 ( V_101 , V_17 , V_189 , V_7 ) ;
#ifdef F_83
F_29 ( V_101 , V_101 , 5 , V_7 ) ;
#endif
break;
case V_147 | V_190 :
V_7 -> V_78 |= V_95 | V_119 ;
F_77 ( F_78 ( struct V_102 ,
V_191 ) != 2 ) ;
F_77 ( F_79 ( struct V_102 ,
V_191 ) > 0xff ) ;
V_110 = F_79 ( struct V_102 , V_191 ) ;
F_38 ( V_101 , V_96 , V_110 , V_7 ) ;
break;
default:
F_75 ( L_3 , __FILE__ ,
V_67 -> V_94 ) ;
return - 1 ;
}
}
if ( V_7 -> V_10 == NULL )
V_7 -> V_53 [ V_74 ] = V_7 -> V_12 * 4 ;
return 0 ;
}
void F_84 ( struct V_107 * V_192 )
{
struct V_6 V_7 ;
unsigned int V_193 , V_194 ;
if ( ! V_195 )
return;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_53 = F_85 ( V_192 -> V_115 , sizeof( * V_7 . V_53 ) , V_196 ) ;
if ( V_7 . V_53 == NULL )
return;
V_7 . V_92 = V_192 ;
if ( F_74 ( & V_7 ) )
goto V_197;
V_194 = V_7 . V_12 ;
F_66 ( & V_7 ) ;
V_7 . V_54 = ( V_7 . V_12 - V_194 ) * 4 ;
F_67 ( & V_7 ) ;
V_193 = 4 * V_7 . V_12 ;
V_7 . V_10 = F_86 ( V_193 ) ;
if ( V_7 . V_10 == NULL )
goto V_197;
memset ( V_7 . V_10 , 0 , V_193 ) ;
V_7 . V_12 = 0 ;
F_66 ( & V_7 ) ;
F_74 ( & V_7 ) ;
F_67 ( & V_7 ) ;
F_87 ( ( T_3 ) V_7 . V_10 , ( T_3 ) ( V_7 . V_10 + V_7 . V_12 ) ) ;
if ( V_195 > 1 )
F_88 ( V_192 -> V_115 , V_193 , 2 , V_7 . V_10 ) ;
V_192 -> V_198 = ( void * ) V_7 . V_10 ;
V_192 -> V_199 = true ;
V_197:
F_89 ( V_7 . V_53 ) ;
}
void F_90 ( struct V_107 * V_192 )
{
if ( V_192 -> V_199 )
F_91 ( NULL , V_192 -> V_198 ) ;
F_92 ( V_192 ) ;
}
