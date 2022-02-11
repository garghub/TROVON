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
static inline void F_15 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_19 , V_3 , V_4 , V_5 ) ;
}
static inline void F_16 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_20 , V_3 , V_16 , V_2 ) ;
}
static inline void F_17 ( unsigned int V_3 , unsigned int V_16 ,
T_1 V_2 , struct V_6 * V_7 )
{
if ( ! F_3 ( V_2 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_5 ( V_3 , V_17 , V_16 , V_7 ) ;
} else {
F_6 ( V_7 , V_21 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_18 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_22 , V_3 , V_4 , V_5 ) ;
}
static inline void F_19 ( unsigned int V_3 , unsigned int V_16 ,
T_1 V_2 , struct V_6 * V_7 )
{
if ( V_2 >= F_14 ( 16 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_18 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_23 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_20 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_24 , V_3 , V_4 , V_5 ) ;
}
static inline void F_21 ( T_3 V_3 , T_3 V_16 , T_1 V_2 , struct V_6 * V_7 )
{
if ( V_2 >= F_14 ( 16 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_20 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_25 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_22 ( int V_26 , struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) )
F_6 ( V_7 , V_20 , V_28 , V_28 , V_26 ) ;
else
F_6 ( V_7 , V_21 , V_28 , V_28 , V_26 ) ;
}
static inline void F_24 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_29 , V_3 , V_4 , V_5 ) ;
}
static inline void F_25 ( unsigned int V_30 , struct V_6 * V_7 )
{
F_24 ( V_30 , V_14 , V_30 , V_7 ) ;
}
static inline void F_26 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_32 , V_3 , V_16 , V_31 ) ;
}
static inline void F_27 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
if ( V_31 >= F_14 ( 5 ) )
F_28 ( V_3 , V_14 , V_7 ) ;
else
F_6 ( V_7 , V_33 , V_3 , V_16 , V_31 ) ;
}
static inline void F_29 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_34 , V_3 , V_16 , V_31 ) ;
}
static inline void F_30 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
if ( V_31 >= F_14 ( 5 ) )
F_28 ( V_3 , V_14 , V_7 ) ;
else
F_6 ( V_7 , V_35 , V_3 , V_16 , V_31 ) ;
}
static inline void F_31 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_36 , V_3 , V_4 , V_5 ) ;
}
static inline void F_32 ( unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_37 , V_3 , V_4 , V_5 ) ;
}
static inline void F_33 ( unsigned V_3 , unsigned int V_16 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( ! F_3 ( ( T_2 ) V_2 ) ) {
F_8 ( V_17 , V_2 , V_7 ) ;
F_32 ( V_3 , V_16 , V_17 , V_7 ) ;
} else {
F_6 ( V_7 , V_38 , V_3 , V_16 , V_2 ) ;
}
}
static inline void F_34 ( T_3 V_30 , T_3 V_39 ,
unsigned int V_26 ,
struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) )
F_6 ( V_7 , V_40 , V_30 , V_26 , V_39 ) ;
else
F_6 ( V_7 , V_41 , V_30 , V_26 , V_39 ) ;
}
static inline void F_35 ( T_3 V_30 , T_3 V_39 , unsigned int V_26 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_41 , V_30 , V_26 , V_39 ) ;
}
static inline void F_36 ( T_3 V_30 , T_3 V_39 ,
unsigned int V_26 ,
struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) )
F_6 ( V_7 , V_42 , V_30 , V_26 , V_39 ) ;
else
F_6 ( V_7 , V_43 , V_30 , V_26 , V_39 ) ;
}
static inline void F_37 ( unsigned int V_30 , unsigned int V_39 ,
unsigned int V_26 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_43 , V_30 , V_26 , V_39 ) ;
}
static inline void F_38 ( unsigned int V_30 , unsigned int V_39 ,
unsigned int V_26 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_44 , V_30 , V_26 , V_39 ) ;
}
static inline void F_39 ( unsigned int V_30 , unsigned int V_39 ,
unsigned int V_26 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_45 , V_30 , V_26 , V_39 ) ;
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
F_43 ( & V_11 , V_3 ) ;
}
V_7 -> V_12 += 2 ;
}
static inline void F_45 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_47 , V_3 , V_16 , V_31 ) ;
}
static inline void F_46 ( unsigned int V_3 , unsigned int V_16 ,
unsigned int V_31 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_48 , V_3 , V_16 , V_31 ) ;
}
static inline void F_47 ( unsigned int V_3 , unsigned int V_16 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_49 , V_3 , V_16 ) ;
}
static inline void F_48 ( unsigned int V_3 , unsigned int V_16 ,
int V_2 , struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) )
F_6 ( V_7 , V_42 , V_3 , V_2 , V_16 ) ;
else
F_6 ( V_7 , V_43 , V_3 , V_2 , V_16 ) ;
}
static inline void F_49 ( unsigned int V_30 , T_3 V_2 ,
struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) ) {
F_8 ( V_17 , ( V_50 ) V_2 >> 32 , V_7 ) ;
F_45 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_17 , V_13 , ( V_2 >> 16 ) & 0xffff , V_7 ) ;
F_45 ( V_13 , V_17 , 16 , V_7 ) ;
F_13 ( V_30 , V_13 , V_2 & 0xffff , V_7 ) ;
} else {
F_8 ( V_30 , V_2 , V_7 ) ;
}
}
static inline void F_50 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
if ( F_23 ( V_27 ) )
F_15 ( V_3 , V_16 , V_14 , V_7 ) ;
else
F_5 ( V_3 , V_16 , V_14 , V_7 ) ;
}
static inline void F_28 ( T_3 V_3 , T_3 V_16 , struct V_6 * V_7 )
{
F_5 ( V_3 , V_16 , V_14 , V_7 ) ;
}
static inline T_1 F_51 ( unsigned int V_51 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 == NULL )
return 0 ;
return V_7 -> V_52 [ V_51 ] -
( V_7 -> V_12 * 4 - V_7 -> V_53 ) - 4 ;
}
static inline void F_52 ( int V_54 , unsigned int V_55 , unsigned int V_56 ,
unsigned int V_2 , struct V_6 * V_7 )
{
if ( V_7 -> V_10 != NULL ) {
T_1 * V_11 = & V_7 -> V_10 [ V_7 -> V_12 ] ;
switch ( V_54 ) {
case V_57 :
F_53 ( & V_11 , V_55 , V_56 , V_2 ) ;
break;
case V_58 :
F_54 ( & V_11 , V_55 , V_56 , V_2 ) ;
break;
case V_59 :
F_55 ( & V_11 , V_2 ) ;
break;
default:
F_56 ( L_1 ,
V_60 , V_54 ) ;
}
}
V_7 -> V_12 ++ ;
}
static inline void F_57 ( unsigned int V_2 , struct V_6 * V_7 )
{
F_52 ( V_59 , V_14 , V_14 , V_2 , V_7 ) ;
}
static inline void F_58 ( unsigned int V_61 , unsigned int V_30 ,
struct V_6 * V_7 )
{
F_6 ( V_7 , V_62 , V_61 , V_30 ) ;
}
static inline void F_59 ( unsigned int V_30 , struct V_6 * V_7 )
{
F_6 ( V_7 , V_63 , V_30 ) ;
}
static inline T_4 F_60 ( unsigned int V_64 )
{
unsigned int V_65 = F_23 ( V_27 ) ? 16 : 8 ;
V_64 = ( V_64 + ( V_65 - 1 ) ) & - V_65 ;
return V_64 ;
}
static bool F_61 ( T_4 V_66 )
{
switch ( V_66 ) {
case V_67 | V_68 | V_69 :
case V_67 | V_68 | V_70 :
case V_67 | V_71 | V_70 :
case V_67 | V_72 | V_70 :
return true ;
default:
return false ;
}
}
static void F_62 ( struct V_6 * V_7 , unsigned V_26 )
{
int V_73 = 0 , V_74 = 0 ;
T_1 V_75 , V_76 ;
F_22 ( - F_60 ( V_26 ) , V_7 ) ;
if ( V_7 -> V_77 & V_78 ) {
if ( F_23 ( V_27 ) )
V_74 = F_60 ( V_26 ) - V_79 ;
else
V_74 = F_60 ( V_26 ) + V_79 ;
F_34 ( V_80 , V_28 , V_74 , V_7 ) ;
F_34 ( V_81 , V_28 , V_74 + V_79 , V_7 ) ;
V_74 = 0 ;
}
V_76 = V_75 = V_7 -> V_77 >> V_82 ;
while ( V_76 ) {
if ( ( V_75 >> V_73 ) & 0x1 ) {
F_34 ( V_83 + V_73 , V_28 , V_74 ,
V_7 ) ;
V_74 += V_79 ;
}
V_73 ++ ;
V_76 >>= 1 ;
}
if ( V_7 -> V_77 & V_78 ) {
F_34 ( V_84 , V_28 , V_74 , V_7 ) ;
V_74 += V_79 ;
}
if ( V_7 -> V_77 & V_85 ) {
if ( V_74 % ( V_79 * 2 ) )
V_74 += V_79 ;
if ( F_23 ( V_27 ) )
F_16 ( V_86 , V_28 , V_74 , V_7 ) ;
else
F_17 ( V_86 , V_28 , V_74 , V_7 ) ;
}
}
static void F_63 ( struct V_6 * V_7 ,
unsigned int V_26 )
{
int V_73 , V_74 = 0 ;
T_1 V_75 , V_76 ;
if ( V_7 -> V_77 & V_78 ) {
if ( F_23 ( V_27 ) )
V_74 = F_60 ( V_26 ) - V_79 ;
else
V_74 = F_60 ( V_26 ) + V_79 ;
F_36 ( V_80 , V_28 , V_74 , V_7 ) ;
F_36 ( V_81 , V_28 , V_74 + V_79 , V_7 ) ;
V_74 = 0 ;
}
V_76 = V_75 = V_7 -> V_77 >> V_82 ;
V_73 = 0 ;
while ( V_76 ) {
if ( ( V_75 >> V_73 ) & 0x1 ) {
F_36 ( V_83 + V_73 , V_28 , V_74 ,
V_7 ) ;
V_74 += V_79 ;
}
V_73 ++ ;
V_76 >>= 1 ;
}
if ( V_7 -> V_77 & V_78 )
F_36 ( V_84 , V_28 , V_74 , V_7 ) ;
F_22 ( F_60 ( V_26 ) , V_7 ) ;
}
static unsigned int F_64 ( struct V_6 * V_7 )
{
int V_87 = 0 ;
V_87 += F_65 ( V_7 -> V_77 >> V_82 ) * V_79 ;
if ( V_7 -> V_77 & V_85 )
V_87 += 4 * V_88 ;
if ( V_7 -> V_77 & V_78 )
V_87 += F_23 ( V_27 ) ?
( V_89 + 1 ) * V_79 : V_79 ;
return V_87 - V_79 ;
}
static void F_66 ( struct V_6 * V_7 )
{
T_4 V_90 = V_7 -> V_91 -> V_92 [ 0 ] . V_93 ;
int V_87 ;
V_87 = F_64 ( V_7 ) ;
F_62 ( V_7 , V_87 ) ;
if ( V_7 -> V_77 & V_94 )
F_50 ( V_95 , V_80 , V_7 ) ;
if ( V_7 -> V_77 & V_96 )
F_28 ( V_97 , V_14 , V_7 ) ;
if ( ( V_90 != ( V_98 | V_99 ) ) && ! ( F_61 ( V_90 ) ) )
F_28 ( V_100 , V_14 , V_7 ) ;
}
static void F_67 ( struct V_6 * V_7 )
{
unsigned int V_87 ;
V_87 = F_64 ( V_7 ) ;
F_63 ( V_7 , V_87 ) ;
F_59 ( V_84 , V_7 ) ;
F_7 ( V_7 ) ;
}
static V_50 F_68 ( struct V_101 * V_102 , unsigned V_26 )
{
T_5 V_103 ;
int V_104 ;
V_104 = F_69 ( V_102 , V_26 , & V_103 , 1 ) ;
return ( V_50 ) V_104 << 32 | V_103 ;
}
static V_50 F_70 ( struct V_101 * V_102 , unsigned V_26 )
{
T_4 V_103 ;
int V_104 ;
V_104 = F_69 ( V_102 , V_26 , & V_103 , 2 ) ;
return ( V_50 ) V_104 << 32 | F_71 ( V_103 ) ;
}
static V_50 F_72 ( struct V_101 * V_102 , unsigned V_26 )
{
T_1 V_103 ;
int V_104 ;
V_104 = F_69 ( V_102 , V_26 , & V_103 , 4 ) ;
return ( V_50 ) V_104 << 32 | F_73 ( V_103 ) ;
}
static int F_74 ( void )
{
struct V_101 V_105 = {
. V_106 = ~ 0 ,
} ;
T_5 * V_107 = ( T_5 * ) & V_105 ;
unsigned int V_108 ;
for ( V_108 = 0 ; V_108 < sizeof( struct V_101 ) ; V_108 ++ ) {
if ( V_107 [ V_108 ] == V_109 )
return V_108 ;
}
F_75 ( L_2 ) ;
return - 1 ;
}
static int F_76 ( struct V_6 * V_7 )
{
void * V_110 [] = { F_68 , F_70 , F_72 } ;
const struct V_111 * V_112 = V_7 -> V_91 ;
const struct V_113 * V_66 ;
unsigned int V_73 , V_108 , V_114 , V_115 ;
T_1 V_1 , V_116 V_117 ;
for ( V_73 = 0 ; V_73 < V_112 -> V_118 ; V_73 ++ ) {
T_4 V_93 ;
V_66 = & ( V_112 -> V_92 [ V_73 ] ) ;
F_77 ( L_3 ,
V_60 , V_66 -> V_93 , V_66 -> V_119 , V_66 -> V_120 , V_66 -> V_1 ) ;
V_1 = V_66 -> V_1 ;
V_93 = F_78 ( V_66 ) ;
if ( V_7 -> V_10 == NULL )
V_7 -> V_52 [ V_73 ] = V_7 -> V_12 * 4 ;
switch ( V_93 ) {
case V_67 | V_121 :
V_7 -> V_77 |= V_122 ;
F_8 ( V_100 , V_1 , V_7 ) ;
break;
case V_67 | V_68 | V_69 :
F_79 ( F_80 ( struct V_101 , V_118 ) != 4 ) ;
V_7 -> V_77 |= V_94 | V_122 ;
V_108 = F_81 ( struct V_101 , V_118 ) ;
F_37 ( V_100 , V_95 , V_108 , V_7 ) ;
break;
case V_67 | V_123 :
V_7 -> V_77 |= V_85 | V_122 ;
F_37 ( V_100 , V_86 , F_82 ( V_1 ) , V_7 ) ;
break;
case V_67 | V_68 | V_70 :
V_114 = 2 ;
goto V_124;
case V_67 | V_71 | V_70 :
V_114 = 1 ;
goto V_124;
case V_67 | V_72 | V_70 :
V_114 = 0 ;
V_124:
if ( ( int ) V_1 < 0 )
return - V_125 ;
F_8 ( V_126 , V_1 , V_7 ) ;
V_127:
F_31 ( V_128 , V_126 , V_14 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 ,
F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_50 ( V_129 , V_14 , V_7 ) ;
V_7 -> V_77 |= V_78 | V_130 | V_131 |
V_94 | V_122 ;
F_49 ( V_128 , ( T_3 ) V_110 [ V_114 ] ,
V_7 ) ;
F_50 ( V_80 , V_95 , V_7 ) ;
F_58 ( V_132 , V_128 , V_7 ) ;
F_50 ( V_81 , V_126 , V_7 ) ;
if ( F_23 ( V_27 ) ) {
F_46 ( V_128 , V_133 , 0 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 , 3 << 2 ,
V_7 ) ;
} else {
F_52 ( V_58 , V_134 , V_14 , 3 << 2 ,
V_7 ) ;
}
F_7 ( V_7 ) ;
F_57 ( F_51 ( V_73 + 1 , V_7 ) , V_7 ) ;
F_28 ( V_100 , V_133 , V_7 ) ;
F_57 ( F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_50 ( V_129 , V_14 , V_7 ) ;
break;
case V_67 | V_68 | V_135 :
V_114 = 2 ;
goto V_136;
case V_67 | V_71 | V_135 :
V_114 = 1 ;
goto V_136;
case V_67 | V_72 | V_135 :
V_114 = 0 ;
V_136:
V_7 -> V_77 |= V_130 | V_96 ;
F_17 ( V_126 , V_97 , V_1 , V_7 ) ;
goto V_127;
case V_137 | V_121 :
V_7 -> V_77 |= V_96 ;
F_8 ( V_97 , V_1 , V_7 ) ;
break;
case V_137 | V_123 :
V_7 -> V_77 |= V_96 | V_85 ;
F_37 ( V_97 , V_86 , F_82 ( V_1 ) , V_7 ) ;
break;
case V_137 | V_68 | V_69 :
V_7 -> V_77 |= V_96 | V_94 ;
V_108 = F_81 ( struct V_101 , V_118 ) ;
F_37 ( V_97 , V_95 , V_108 , V_7 ) ;
break;
case V_137 | V_72 | V_138 :
if ( ( int ) V_1 < 0 )
return - V_125 ;
V_7 -> V_77 |= V_96 | V_78 | V_131 | V_94 ;
F_49 ( V_128 , ( T_3 ) F_68 , V_7 ) ;
F_8 ( V_81 , V_1 , V_7 ) ;
F_58 ( V_132 , V_128 , V_7 ) ;
F_50 ( V_80 , V_95 , V_7 ) ;
if ( F_23 ( V_27 ) ) {
F_46 ( V_128 , V_133 , 0 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 ,
3 << 2 , V_7 ) ;
} else {
F_52 ( V_58 , V_134 , V_14 ,
3 << 2 , V_7 ) ;
}
F_19 ( V_97 , V_133 , 0xf , V_7 ) ;
F_57 ( F_51 ( V_73 + 1 , V_7 ) , V_7 ) ;
F_27 ( V_97 , V_97 , 2 , V_7 ) ;
F_57 ( F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_8 ( V_129 , 0 , V_7 ) ;
break;
case V_139 :
V_7 -> V_77 |= V_85 | V_122 ;
F_35 ( V_100 , V_86 , F_82 ( V_1 ) , V_7 ) ;
break;
case V_140 :
V_7 -> V_77 |= V_85 | V_96 ;
F_35 ( V_97 , V_86 , F_82 ( V_1 ) , V_7 ) ;
break;
case V_141 | V_142 | V_99 :
V_7 -> V_77 |= V_122 ;
F_17 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_141 | V_142 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_5 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_144 | V_99 :
V_7 -> V_77 |= V_122 ;
F_17 ( V_100 , V_100 , - V_1 , V_7 ) ;
break;
case V_141 | V_144 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_24 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_145 | V_99 :
V_7 -> V_77 |= V_122 | V_131 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_40 ( V_100 , V_100 , V_128 , V_7 ) ;
break;
case V_141 | V_145 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_40 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_146 | V_99 :
if ( V_1 == 1 )
break;
if ( F_1 ( & V_1 ) ) {
V_7 -> V_77 |= V_122 ;
F_30 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
}
V_7 -> V_77 |= V_122 | V_131 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_41 ( V_100 , V_128 , V_7 ) ;
break;
case V_141 | V_147 | V_99 :
if ( V_1 == 1 || F_1 ( & V_1 ) ) {
V_7 -> V_77 |= V_122 ;
F_28 ( V_100 , V_14 , V_7 ) ;
} else {
V_7 -> V_77 |= V_122 | V_131 ;
F_8 ( V_128 , V_1 , V_7 ) ;
F_44 ( V_100 , V_128 , V_7 ) ;
}
break;
case V_141 | V_146 | V_143 :
V_7 -> V_77 |= V_96 | V_122 ;
F_52 ( V_57 , V_97 , V_14 ,
F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_8 ( V_133 , 0 , V_7 ) ;
F_41 ( V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_147 | V_143 :
V_7 -> V_77 |= V_96 | V_122 ;
F_52 ( V_57 , V_97 , V_14 ,
F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_8 ( V_133 , 0 , V_7 ) ;
F_44 ( V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_148 | V_99 :
V_7 -> V_77 |= V_122 ;
F_13 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_141 | V_148 | V_143 :
V_7 -> V_77 |= V_122 ;
F_13 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_149 | V_99 :
V_7 -> V_77 |= V_122 ;
F_21 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_150 | V_151 :
case V_141 | V_149 | V_143 :
V_7 -> V_77 |= V_122 ;
F_20 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_152 | V_99 :
V_7 -> V_77 |= V_122 ;
F_19 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_141 | V_152 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_18 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_153 | V_99 :
V_7 -> V_77 |= V_122 ;
F_27 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_141 | V_153 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_26 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_154 | V_99 :
V_7 -> V_77 |= V_122 ;
F_30 ( V_100 , V_100 , V_1 , V_7 ) ;
break;
case V_141 | V_154 | V_143 :
V_7 -> V_77 |= V_122 | V_96 ;
F_29 ( V_100 , V_100 , V_97 , V_7 ) ;
break;
case V_141 | V_155 :
V_7 -> V_77 |= V_122 ;
F_25 ( V_100 , V_7 ) ;
break;
case V_156 | V_157 :
F_57 ( F_51 ( V_73 + V_1 + 1 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_156 | V_158 | V_99 :
V_115 = V_57 | V_159 ;
goto V_160;
case V_156 | V_158 | V_143 :
V_7 -> V_77 |= V_96 ;
V_115 = V_57 | V_161 ;
goto V_160;
case V_156 | V_162 | V_99 :
V_115 = V_163 | V_159 ;
goto V_160;
case V_156 | V_162 | V_143 :
V_7 -> V_77 |= V_96 ;
V_115 = V_163 | V_161 ;
goto V_160;
case V_156 | V_164 | V_99 :
V_115 = V_165 | V_159 ;
goto V_160;
case V_156 | V_164 | V_143 :
V_7 -> V_77 |= V_96 ;
V_115 = V_165 | V_161 ;
V_160:
if ( ( V_115 & V_163 ) ||
( V_115 & V_165 ) ) {
if ( V_115 & V_159 ) {
V_7 -> V_77 |= V_131 | V_122 ;
F_33 ( V_128 , V_100 , V_1 , V_7 ) ;
} else {
V_7 -> V_77 |= V_131 | V_122 |
V_96 ;
F_32 ( V_128 , V_100 , V_97 , V_7 ) ;
}
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 , V_116 ,
V_7 ) ;
F_7 ( V_7 ) ;
if ( V_115 & V_165 ) {
V_7 -> V_77 |= V_131 | V_122 | V_96 ;
if ( V_115 & V_159 )
F_8 ( V_128 , V_1 , V_7 ) ;
else
F_28 ( V_128 , V_97 ,
V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 , V_7 ) ;
F_52 ( V_57 , V_100 , V_128 ,
V_116 , V_7 ) ;
F_7 ( V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 , V_7 ) ;
F_57 ( V_116 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 , V_7 ) ;
F_57 ( V_116 , V_7 ) ;
F_7 ( V_7 ) ;
}
} else {
if ( V_115 & V_159 ) {
V_7 -> V_77 |= V_131 | V_122 ;
F_8 ( V_128 , V_1 , V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 , V_7 ) ;
F_52 ( V_57 , V_100 , V_128 ,
V_116 , V_7 ) ;
F_7 ( V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 ,
V_7 ) ;
F_52 ( V_58 , V_100 , V_128 ,
V_116 , V_7 ) ;
F_7 ( V_7 ) ;
} else {
V_7 -> V_77 |= V_122 | V_96 ;
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 ,
V_7 ) ;
F_52 ( V_57 , V_100 , V_97 ,
V_116 , V_7 ) ;
F_7 ( V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 , V_7 ) ;
F_52 ( V_58 , V_100 , V_97 ,
V_116 , V_7 ) ;
F_7 ( V_7 ) ;
}
}
break;
case V_156 | V_166 | V_99 :
V_7 -> V_77 |= V_131 | V_167 | V_122 ;
F_8 ( V_168 , V_1 , V_7 ) ;
F_18 ( V_128 , V_100 , V_168 , V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 , V_116 , V_7 ) ;
F_7 ( V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 , V_7 ) ;
F_57 ( V_116 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_156 | V_166 | V_143 :
V_7 -> V_77 |= V_131 | V_96 | V_122 ;
F_18 ( V_128 , V_100 , V_97 , V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_119 + 1 , V_7 ) ;
F_52 ( V_58 , V_128 , V_14 , V_116 , V_7 ) ;
F_7 ( V_7 ) ;
V_116 = F_51 ( V_73 + V_66 -> V_120 + 1 , V_7 ) ;
F_57 ( V_116 , V_7 ) ;
F_7 ( V_7 ) ;
break;
case V_98 | V_169 :
V_7 -> V_77 |= V_122 ;
if ( V_73 != V_112 -> V_118 - 1 )
F_57 ( F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_50 ( V_129 , V_100 , V_7 ) ;
break;
case V_98 | V_99 :
F_8 ( V_129 , V_1 , V_7 ) ;
if ( V_73 != V_112 -> V_118 - 1 ) {
F_57 ( F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_7 ( V_7 ) ;
}
break;
case V_170 | V_171 :
V_7 -> V_77 |= V_96 | V_122 ;
F_28 ( V_97 , V_100 , V_7 ) ;
break;
case V_170 | V_172 :
V_7 -> V_77 |= V_122 | V_96 ;
F_28 ( V_100 , V_97 , V_7 ) ;
break;
case V_150 | V_173 :
V_7 -> V_77 |= V_94 | V_130 | V_122 ;
F_79 ( F_80 ( struct V_101 ,
V_174 ) != 2 ) ;
V_108 = F_81 ( struct V_101 , V_174 ) ;
F_39 ( V_100 , V_95 , V_108 , V_7 ) ;
#ifdef F_83
if ( V_175 ) {
F_47 ( V_100 , V_100 , V_7 ) ;
} else {
F_19 ( V_13 , V_100 , 0xff , V_7 ) ;
F_27 ( V_17 , V_13 , 8 , V_7 ) ;
F_30 ( V_13 , V_100 , 8 , V_7 ) ;
F_19 ( V_13 , V_13 , 0xff , V_7 ) ;
F_12 ( V_100 , V_17 , V_13 , V_7 ) ;
}
#endif
break;
case V_150 | V_176 :
V_7 -> V_77 |= V_122 | V_130 ;
F_79 ( F_80 ( struct V_177 ,
V_178 ) != 4 ) ;
V_108 = F_81 ( struct V_177 , V_178 ) ;
F_37 ( V_100 , 28 , V_108 , V_7 ) ;
break;
case V_150 | V_179 :
V_7 -> V_77 |= V_94 | V_122 | V_131 ;
V_108 = F_81 ( struct V_101 , V_180 ) ;
F_48 ( V_128 , V_95 , V_108 , V_7 ) ;
F_52 ( V_57 , V_128 , V_14 ,
F_51 ( V_112 -> V_118 , V_7 ) , V_7 ) ;
F_50 ( V_129 , V_14 , V_7 ) ;
F_79 ( F_80 ( struct V_181 ,
V_182 ) != 4 ) ;
V_108 = F_81 ( struct V_181 , V_182 ) ;
F_37 ( V_100 , V_128 , V_108 , V_7 ) ;
break;
case V_150 | V_183 :
V_7 -> V_77 |= V_94 | V_122 ;
F_79 ( F_80 ( struct V_101 , V_184 ) != 4 ) ;
V_108 = F_81 ( struct V_101 , V_184 ) ;
F_37 ( V_100 , V_95 , V_108 , V_7 ) ;
break;
case V_150 | V_185 :
V_7 -> V_77 |= V_94 | V_122 ;
F_79 ( F_80 ( struct V_101 , V_186 ) != 4 ) ;
V_108 = F_81 ( struct V_101 , V_186 ) ;
F_37 ( V_100 , V_95 , V_108 , V_7 ) ;
break;
case V_150 | V_187 :
case V_150 | V_188 :
V_7 -> V_77 |= V_94 | V_131 | V_122 ;
F_79 ( F_80 ( struct V_101 ,
V_189 ) != 2 ) ;
V_108 = F_81 ( struct V_101 , V_189 ) ;
F_39 ( V_128 , V_95 , V_108 , V_7 ) ;
if ( V_93 == ( V_150 | V_187 ) ) {
F_19 ( V_100 , V_128 , ( T_4 ) ~ V_190 , V_7 ) ;
} else {
F_19 ( V_100 , V_128 , V_190 , V_7 ) ;
F_32 ( V_100 , V_14 , V_100 , V_7 ) ;
}
break;
case V_150 | V_191 :
V_7 -> V_77 |= V_94 ;
V_108 = F_74 () ;
if ( V_108 < 0 )
return - 1 ;
F_38 ( V_17 , V_95 , V_108 , V_7 ) ;
F_19 ( V_100 , V_17 , V_109 , V_7 ) ;
#ifdef F_84
F_30 ( V_100 , V_100 , 5 , V_7 ) ;
#endif
break;
case V_150 | V_192 :
V_7 -> V_77 |= V_94 | V_122 ;
F_79 ( F_80 ( struct V_101 ,
V_193 ) != 2 ) ;
F_79 ( F_81 ( struct V_101 ,
V_193 ) > 0xff ) ;
V_108 = F_81 ( struct V_101 , V_193 ) ;
F_39 ( V_100 , V_95 , V_108 , V_7 ) ;
break;
default:
F_77 ( L_4 , __FILE__ ,
V_66 -> V_93 ) ;
return - 1 ;
}
}
if ( V_7 -> V_10 == NULL )
V_7 -> V_52 [ V_73 ] = V_7 -> V_12 * 4 ;
return 0 ;
}
void F_85 ( struct V_111 * V_194 )
{
struct V_6 V_7 ;
unsigned int V_195 , V_196 ;
if ( ! V_197 )
return;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_52 = F_86 ( V_194 -> V_118 , sizeof( * V_7 . V_52 ) , V_198 ) ;
if ( V_7 . V_52 == NULL )
return;
V_7 . V_91 = V_194 ;
if ( F_76 ( & V_7 ) )
goto V_199;
V_196 = V_7 . V_12 ;
F_66 ( & V_7 ) ;
V_7 . V_53 = ( V_7 . V_12 - V_196 ) * 4 ;
F_67 ( & V_7 ) ;
V_195 = 4 * V_7 . V_12 ;
V_7 . V_10 = F_87 ( V_195 ) ;
if ( V_7 . V_10 == NULL )
goto V_199;
memset ( V_7 . V_10 , 0 , V_195 ) ;
V_7 . V_12 = 0 ;
F_66 ( & V_7 ) ;
F_76 ( & V_7 ) ;
F_67 ( & V_7 ) ;
F_88 ( ( T_3 ) V_7 . V_10 , ( T_3 ) ( V_7 . V_10 + V_7 . V_12 ) ) ;
if ( V_197 > 1 )
F_89 ( V_194 -> V_118 , V_195 , 2 , V_7 . V_10 ) ;
V_194 -> V_200 = ( void * ) V_7 . V_10 ;
V_194 -> V_201 = 1 ;
V_199:
F_90 ( V_7 . V_52 ) ;
}
void F_91 ( struct V_111 * V_194 )
{
if ( V_194 -> V_201 )
F_92 ( NULL , V_194 -> V_200 ) ;
F_90 ( V_194 ) ;
}
