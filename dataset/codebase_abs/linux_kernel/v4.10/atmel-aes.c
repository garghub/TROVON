static const char * F_1 ( T_1 V_1 , char * V_2 , T_2 V_3 )
{
switch ( V_1 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
case V_6 :
return L_3 ;
case V_7 :
return L_4 ;
case V_8 :
return L_5 ;
case V_9 :
return L_6 ;
case F_2 ( 0 ) :
case F_2 ( 1 ) :
case F_2 ( 2 ) :
case F_2 ( 3 ) :
case F_2 ( 4 ) :
case F_2 ( 5 ) :
case F_2 ( 6 ) :
case F_2 ( 7 ) :
snprintf ( V_2 , V_3 , L_7 , ( V_1 - F_2 ( 0 ) ) >> 2 ) ;
break;
case F_3 ( 0 ) :
case F_3 ( 1 ) :
case F_3 ( 2 ) :
case F_3 ( 3 ) :
snprintf ( V_2 , V_3 , L_8 , ( V_1 - F_3 ( 0 ) ) >> 2 ) ;
break;
case F_4 ( 0 ) :
case F_4 ( 1 ) :
case F_4 ( 2 ) :
case F_4 ( 3 ) :
snprintf ( V_2 , V_3 , L_9 , ( V_1 - F_4 ( 0 ) ) >> 2 ) ;
break;
case F_5 ( 0 ) :
case F_5 ( 1 ) :
case F_5 ( 2 ) :
case F_5 ( 3 ) :
snprintf ( V_2 , V_3 , L_10 , ( V_1 - F_5 ( 0 ) ) >> 2 ) ;
break;
case V_10 :
return L_11 ;
case V_11 :
return L_12 ;
case F_6 ( 0 ) :
case F_6 ( 1 ) :
case F_6 ( 2 ) :
case F_6 ( 3 ) :
snprintf ( V_2 , V_3 , L_13 , ( V_1 - F_6 ( 0 ) ) >> 2 ) ;
break;
case F_7 ( 0 ) :
case F_7 ( 1 ) :
case F_7 ( 2 ) :
case F_7 ( 3 ) :
snprintf ( V_2 , V_3 , L_14 , ( V_1 - F_7 ( 0 ) ) >> 2 ) ;
break;
case V_12 :
return L_15 ;
case F_8 ( 0 ) :
case F_8 ( 1 ) :
case F_8 ( 2 ) :
case F_8 ( 3 ) :
snprintf ( V_2 , V_3 , L_16 , ( V_1 - F_8 ( 0 ) ) >> 2 ) ;
break;
case F_9 ( 0 ) :
case F_9 ( 1 ) :
case F_9 ( 2 ) :
case F_9 ( 3 ) :
snprintf ( V_2 , V_3 , L_17 , ( V_1 - F_9 ( 0 ) ) >> 2 ) ;
break;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
snprintf ( V_2 , V_3 , L_18 , ( V_1 - F_10 ( 0 ) ) >> 2 ) ;
break;
default:
snprintf ( V_2 , V_3 , L_19 , V_1 ) ;
break;
}
return V_2 ;
}
static inline T_1 F_11 ( struct V_13 * V_14 , T_1 V_1 )
{
T_1 V_15 = F_12 ( V_14 -> V_16 + V_1 ) ;
#ifdef F_13
if ( V_14 -> V_17 & V_18 ) {
char V_2 [ 16 ] ;
F_14 ( V_14 -> V_19 , L_20 , V_15 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ) ;
}
#endif
return V_15 ;
}
static inline void F_15 ( struct V_13 * V_14 ,
T_1 V_1 , T_1 V_15 )
{
#ifdef F_13
if ( V_14 -> V_17 & V_18 ) {
char V_2 [ 16 ] ;
F_14 ( V_14 -> V_19 , L_21 , V_15 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ) ;
}
#endif
F_16 ( V_15 , V_14 -> V_16 + V_1 ) ;
}
static void F_17 ( struct V_13 * V_14 , T_1 V_1 ,
T_1 * V_15 , int V_20 )
{
for (; V_20 -- ; V_15 ++ , V_1 += 4 )
* V_15 = F_11 ( V_14 , V_1 ) ;
}
static void F_18 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_15 , int V_20 )
{
for (; V_20 -- ; V_15 ++ , V_1 += 4 )
F_15 ( V_14 , V_1 , * V_15 ) ;
}
static inline void F_19 ( struct V_13 * V_14 , T_1 V_1 ,
T_1 * V_15 )
{
F_17 ( V_14 , V_1 , V_15 , F_20 ( V_21 ) ) ;
}
static inline void F_21 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_15 )
{
F_18 ( V_14 , V_1 , V_15 , F_20 ( V_21 ) ) ;
}
static inline int F_22 ( struct V_13 * V_14 ,
T_3 V_22 )
{
T_1 V_23 = F_11 ( V_14 , V_6 ) ;
if ( F_23 ( V_23 & V_24 ) )
return V_22 ( V_14 ) ;
V_14 -> V_22 = V_22 ;
F_15 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
static inline T_2 F_24 ( T_2 V_26 , T_2 V_27 )
{
V_26 &= V_27 - 1 ;
return V_26 ? V_27 - V_26 : 0 ;
}
static struct V_13 * F_25 ( struct V_28 * V_29 )
{
struct V_13 * V_30 = NULL ;
struct V_13 * V_2 ;
F_26 ( & V_31 . V_32 ) ;
if ( ! V_29 -> V_14 ) {
F_27 (tmp, &atmel_aes.dev_list, list) {
V_30 = V_2 ;
break;
}
V_29 -> V_14 = V_30 ;
} else {
V_30 = V_29 -> V_14 ;
}
F_28 ( & V_31 . V_32 ) ;
return V_30 ;
}
static int F_29 ( struct V_13 * V_14 )
{
int V_33 ;
V_33 = F_30 ( V_14 -> V_34 ) ;
if ( V_33 )
return V_33 ;
if ( ! ( V_14 -> V_17 & V_35 ) ) {
F_15 ( V_14 , V_4 , V_36 ) ;
F_15 ( V_14 , V_5 , 0xE << V_37 ) ;
V_14 -> V_17 |= V_35 ;
}
return 0 ;
}
static inline unsigned int F_31 ( struct V_13 * V_14 )
{
return F_11 ( V_14 , V_38 ) & 0x00000fff ;
}
static int F_32 ( struct V_13 * V_14 )
{
int V_33 ;
V_33 = F_29 ( V_14 ) ;
if ( V_33 )
return V_33 ;
V_14 -> V_39 = F_31 ( V_14 ) ;
F_33 ( V_14 -> V_19 , L_22 , V_14 -> V_39 ) ;
F_34 ( V_14 -> V_34 ) ;
return 0 ;
}
static inline void F_35 ( struct V_13 * V_14 ,
const struct V_40 * V_41 )
{
V_14 -> V_17 = ( V_14 -> V_17 & V_42 ) | V_41 -> V_43 ;
}
static inline bool F_36 ( const struct V_13 * V_14 )
{
return ( V_14 -> V_17 & V_44 ) ;
}
static inline int F_37 ( struct V_13 * V_14 , int V_33 )
{
F_34 ( V_14 -> V_34 ) ;
V_14 -> V_17 &= ~ V_45 ;
if ( V_14 -> V_46 )
V_14 -> V_47 -> V_48 ( V_14 -> V_47 , V_33 ) ;
F_38 ( & V_14 -> V_49 ) ;
return V_33 ;
}
static void F_39 ( struct V_13 * V_14 , bool V_50 ,
const T_1 * V_51 , const T_1 * V_52 , int V_53 )
{
T_1 V_54 = 0 ;
if ( V_53 == V_55 )
V_54 |= V_56 ;
else if ( V_53 == V_57 )
V_54 |= V_58 ;
else
V_54 |= V_59 ;
V_54 |= V_14 -> V_17 & V_60 ;
if ( V_50 ) {
V_54 |= V_61 ;
if ( V_14 -> V_62 . V_63 )
V_54 |= V_64 ;
} else {
V_54 |= V_65 ;
}
F_15 ( V_14 , V_5 , V_54 ) ;
F_18 ( V_14 , F_2 ( 0 ) , V_52 , F_20 ( V_53 ) ) ;
if ( V_51 && ( V_54 & V_66 ) != V_67 )
F_21 ( V_14 , F_5 ( 0 ) , V_51 ) ;
}
static inline void F_40 ( struct V_13 * V_14 , bool V_50 ,
const T_1 * V_51 )
{
F_39 ( V_14 , V_50 , V_51 ,
V_14 -> V_29 -> V_52 , V_14 -> V_29 -> V_53 ) ;
}
static int F_41 ( struct V_13 * V_14 )
{
int V_33 = 0 ;
T_1 V_23 ;
for (; ; ) {
F_19 ( V_14 , F_4 ( 0 ) , V_14 -> V_68 ) ;
V_14 -> V_68 += 4 ;
V_14 -> V_69 -= V_21 ;
if ( V_14 -> V_69 < V_21 )
break;
F_21 ( V_14 , F_3 ( 0 ) , V_14 -> V_68 ) ;
V_23 = F_11 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_41 ;
F_15 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
if ( ! F_42 ( V_14 -> V_70 , F_43 ( V_14 -> V_70 ) ,
V_14 -> V_71 , V_14 -> V_72 ) )
V_33 = - V_73 ;
if ( V_33 )
return F_37 ( V_14 , V_33 ) ;
return V_14 -> V_74 ( V_14 ) ;
}
static int F_44 ( struct V_13 * V_14 ,
struct V_75 * V_76 ,
struct V_75 * V_77 ,
T_2 V_26 ,
T_3 V_22 )
{
T_2 V_78 = F_24 ( V_26 , V_21 ) ;
if ( F_23 ( V_26 == 0 ) )
return - V_73 ;
F_45 ( V_76 , F_43 ( V_76 ) , V_14 -> V_71 , V_26 ) ;
V_14 -> V_72 = V_26 ;
V_14 -> V_70 = V_77 ;
V_14 -> V_74 = V_22 ;
V_14 -> V_69 = V_26 + V_78 ;
V_14 -> V_68 = ( T_1 * ) V_14 -> V_71 ;
F_21 ( V_14 , F_3 ( 0 ) , V_14 -> V_68 ) ;
return F_22 ( V_14 , F_41 ) ;
}
static bool F_46 ( struct V_13 * V_14 ,
struct V_75 * V_79 ,
T_2 V_26 ,
struct V_80 * V_81 )
{
int V_82 ;
if ( ! F_47 ( V_26 , V_14 -> V_29 -> V_27 ) )
return false ;
for ( V_82 = 0 ; V_79 ; V_79 = F_48 ( V_79 ) , ++ V_82 ) {
if ( ! F_47 ( V_79 -> V_1 , sizeof( T_1 ) ) )
return false ;
if ( V_26 <= V_79 -> V_83 ) {
if ( ! F_47 ( V_26 , V_14 -> V_29 -> V_27 ) )
return false ;
V_81 -> V_82 = V_82 + 1 ;
V_81 -> V_84 = V_79 -> V_83 - V_26 ;
V_79 -> V_83 = V_26 ;
return true ;
}
if ( ! F_47 ( V_79 -> V_83 , V_14 -> V_29 -> V_27 ) )
return false ;
V_26 -= V_79 -> V_83 ;
}
return false ;
}
static inline void F_49 ( const struct V_80 * V_81 )
{
struct V_75 * V_79 = V_81 -> V_79 ;
int V_82 = V_81 -> V_82 ;
if ( ! V_81 -> V_84 )
return;
while ( -- V_82 > 0 && V_79 )
V_79 = F_48 ( V_79 ) ;
if ( ! V_79 )
return;
V_79 -> V_83 += V_81 -> V_84 ;
}
static int F_50 ( struct V_13 * V_14 ,
struct V_75 * V_76 ,
struct V_75 * V_77 ,
T_2 V_26 )
{
bool V_85 , V_86 ;
T_2 V_78 ;
V_14 -> V_72 = V_26 ;
V_14 -> V_76 . V_79 = V_76 ;
V_14 -> V_77 . V_79 = V_77 ;
V_14 -> V_70 = V_77 ;
V_85 = F_46 ( V_14 , V_76 , V_26 , & V_14 -> V_76 ) ;
if ( V_76 == V_77 )
V_86 = V_85 ;
else
V_86 = F_46 ( V_14 , V_77 , V_26 , & V_14 -> V_77 ) ;
if ( ! V_85 || ! V_86 ) {
V_78 = F_24 ( V_26 , V_14 -> V_29 -> V_27 ) ;
if ( V_14 -> V_87 < V_26 + V_78 )
return - V_88 ;
if ( ! V_85 ) {
F_45 ( V_76 , F_43 ( V_76 ) , V_14 -> V_71 , V_26 ) ;
V_14 -> V_76 . V_79 = & V_14 -> V_89 ;
V_14 -> V_76 . V_82 = 1 ;
V_14 -> V_76 . V_84 = 0 ;
}
if ( ! V_86 ) {
V_14 -> V_77 . V_79 = & V_14 -> V_89 ;
V_14 -> V_77 . V_82 = 1 ;
V_14 -> V_77 . V_84 = 0 ;
}
F_51 ( & V_14 -> V_89 , 1 ) ;
F_52 ( & V_14 -> V_89 , V_14 -> V_71 , V_26 + V_78 ) ;
}
if ( V_14 -> V_76 . V_79 == V_14 -> V_77 . V_79 ) {
V_14 -> V_76 . V_90 = F_53 ( V_14 -> V_19 , V_14 -> V_76 . V_79 , V_14 -> V_76 . V_82 ,
V_91 ) ;
V_14 -> V_77 . V_90 = V_14 -> V_76 . V_90 ;
if ( ! V_14 -> V_76 . V_90 )
return - V_92 ;
} else {
V_14 -> V_76 . V_90 = F_53 ( V_14 -> V_19 , V_14 -> V_76 . V_79 , V_14 -> V_76 . V_82 ,
V_93 ) ;
if ( ! V_14 -> V_76 . V_90 )
return - V_92 ;
V_14 -> V_77 . V_90 = F_53 ( V_14 -> V_19 , V_14 -> V_77 . V_79 , V_14 -> V_77 . V_82 ,
V_94 ) ;
if ( ! V_14 -> V_77 . V_90 ) {
F_54 ( V_14 -> V_19 , V_14 -> V_76 . V_79 , V_14 -> V_76 . V_82 ,
V_93 ) ;
return - V_92 ;
}
}
return 0 ;
}
static void F_55 ( struct V_13 * V_14 )
{
if ( V_14 -> V_76 . V_79 == V_14 -> V_77 . V_79 ) {
F_54 ( V_14 -> V_19 , V_14 -> V_76 . V_79 , V_14 -> V_76 . V_82 ,
V_91 ) ;
if ( V_14 -> V_76 . V_79 != & V_14 -> V_89 )
F_49 ( & V_14 -> V_76 ) ;
} else {
F_54 ( V_14 -> V_19 , V_14 -> V_77 . V_79 , V_14 -> V_77 . V_82 ,
V_94 ) ;
if ( V_14 -> V_77 . V_79 != & V_14 -> V_89 )
F_49 ( & V_14 -> V_77 ) ;
F_54 ( V_14 -> V_19 , V_14 -> V_76 . V_79 , V_14 -> V_76 . V_82 ,
V_93 ) ;
if ( V_14 -> V_76 . V_79 != & V_14 -> V_89 )
F_49 ( & V_14 -> V_76 ) ;
}
if ( V_14 -> V_77 . V_79 == & V_14 -> V_89 )
F_42 ( V_14 -> V_70 , F_43 ( V_14 -> V_70 ) ,
V_14 -> V_71 , V_14 -> V_72 ) ;
}
static int F_56 ( struct V_13 * V_14 ,
enum V_95 V_96 ,
enum V_97 V_98 ,
T_1 V_99 )
{
struct V_100 * V_101 ;
struct V_102 V_103 ;
T_4 V_104 ;
struct V_80 * V_81 ;
int V_33 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_105 = V_98 ;
V_103 . V_106 = V_96 ;
V_103 . V_107 = V_96 ;
V_103 . V_108 = V_99 ;
V_103 . V_109 = V_99 ;
switch ( V_98 ) {
case V_110 :
V_81 = & V_14 -> V_76 ;
V_104 = NULL ;
V_103 . V_111 = V_14 -> V_112 + F_3 ( 0 ) ;
break;
case V_113 :
V_81 = & V_14 -> V_77 ;
V_104 = V_114 ;
V_103 . V_115 = V_14 -> V_112 + F_4 ( 0 ) ;
break;
default:
return - V_73 ;
}
V_33 = F_57 ( V_81 -> V_116 , & V_103 ) ;
if ( V_33 )
return V_33 ;
V_101 = F_58 ( V_81 -> V_116 , V_81 -> V_79 , V_81 -> V_90 , V_98 ,
V_117 | V_118 ) ;
if ( ! V_101 )
return - V_88 ;
V_101 -> V_104 = V_104 ;
V_101 -> V_119 = V_14 ;
F_59 ( V_101 ) ;
F_60 ( V_81 -> V_116 ) ;
return 0 ;
}
static void F_61 ( struct V_13 * V_14 ,
enum V_97 V_98 )
{
struct V_80 * V_81 ;
switch ( V_98 ) {
case V_110 :
V_81 = & V_14 -> V_76 ;
break;
case V_113 :
V_81 = & V_14 -> V_77 ;
break;
default:
return;
}
F_62 ( V_81 -> V_116 ) ;
}
static int F_63 ( struct V_13 * V_14 ,
struct V_75 * V_76 ,
struct V_75 * V_77 ,
T_2 V_26 ,
T_3 V_22 )
{
enum V_95 V_96 ;
T_1 V_99 ;
int V_33 ;
switch ( V_14 -> V_29 -> V_27 ) {
case V_120 :
V_96 = V_121 ;
V_99 = 1 ;
break;
case V_122 :
V_96 = V_123 ;
V_99 = 1 ;
break;
case V_124 :
case V_125 :
V_96 = V_126 ;
V_99 = 1 ;
break;
case V_21 :
V_96 = V_126 ;
V_99 = V_14 -> V_62 . V_127 ;
break;
default:
V_33 = - V_73 ;
goto exit;
}
V_33 = F_50 ( V_14 , V_76 , V_77 , V_26 ) ;
if ( V_33 )
goto exit;
V_14 -> V_22 = V_22 ;
V_33 = F_56 ( V_14 , V_96 , V_113 ,
V_99 ) ;
if ( V_33 )
goto V_128;
V_33 = F_56 ( V_14 , V_96 , V_110 ,
V_99 ) ;
if ( V_33 )
goto V_129;
return - V_25 ;
V_129:
F_61 ( V_14 , V_113 ) ;
V_128:
F_55 ( V_14 ) ;
exit:
return F_37 ( V_14 , V_33 ) ;
}
static void F_64 ( struct V_13 * V_14 )
{
F_61 ( V_14 , V_110 ) ;
F_61 ( V_14 , V_113 ) ;
F_55 ( V_14 ) ;
}
static void V_114 ( void * V_68 )
{
struct V_13 * V_14 = V_68 ;
F_64 ( V_14 ) ;
V_14 -> V_46 = true ;
( void ) V_14 -> V_22 ( V_14 ) ;
}
static int F_65 ( struct V_13 * V_14 ,
struct V_130 * V_131 )
{
struct V_130 * V_47 , * V_132 ;
struct V_28 * V_29 ;
unsigned long V_17 ;
int V_33 , V_133 = 0 ;
F_66 ( & V_14 -> V_32 , V_17 ) ;
if ( V_131 )
V_133 = F_67 ( & V_14 -> V_134 , V_131 ) ;
if ( V_14 -> V_17 & V_45 ) {
F_68 ( & V_14 -> V_32 , V_17 ) ;
return V_133 ;
}
V_132 = F_69 ( & V_14 -> V_134 ) ;
V_47 = F_70 ( & V_14 -> V_134 ) ;
if ( V_47 )
V_14 -> V_17 |= V_45 ;
F_68 ( & V_14 -> V_32 , V_17 ) ;
if ( ! V_47 )
return V_133 ;
if ( V_132 )
V_132 -> V_48 ( V_132 , - V_25 ) ;
V_29 = F_71 ( V_47 -> V_135 ) ;
V_14 -> V_47 = V_47 ;
V_14 -> V_29 = V_29 ;
V_14 -> V_46 = ( V_47 != V_131 ) ;
V_33 = V_29 -> V_136 ( V_14 ) ;
return ( V_14 -> V_46 ) ? V_133 : V_33 ;
}
static int F_72 ( struct V_13 * V_14 )
{
return F_37 ( V_14 , 0 ) ;
}
static int F_73 ( struct V_13 * V_14 )
{
struct V_137 * V_138 = F_74 ( V_14 -> V_47 ) ;
struct V_40 * V_41 = F_75 ( V_138 ) ;
bool V_50 = ( V_138 -> V_139 >= V_140 ||
V_14 -> V_29 -> V_27 != V_21 ) ;
int V_33 ;
F_35 ( V_14 , V_41 ) ;
V_33 = F_29 ( V_14 ) ;
if ( V_33 )
return F_37 ( V_14 , V_33 ) ;
F_40 ( V_14 , V_50 , V_138 -> V_141 ) ;
if ( V_50 )
return F_63 ( V_14 , V_138 -> V_76 , V_138 -> V_77 , V_138 -> V_139 ,
F_72 ) ;
return F_44 ( V_14 , V_138 -> V_76 , V_138 -> V_77 , V_138 -> V_139 ,
F_72 ) ;
}
static inline struct V_142 *
F_76 ( struct V_28 * V_29 )
{
return F_77 ( V_29 , struct V_142 , V_143 ) ;
}
static int F_78 ( struct V_13 * V_14 )
{
struct V_142 * V_29 = F_76 ( V_14 -> V_29 ) ;
struct V_137 * V_138 = F_74 ( V_14 -> V_47 ) ;
struct V_75 * V_76 , * V_77 ;
T_1 V_144 , V_145 ;
T_2 V_69 ;
bool V_50 , V_146 = false ;
V_29 -> V_1 += V_14 -> V_72 ;
if ( V_29 -> V_1 >= V_138 -> V_139 )
return F_72 ( V_14 ) ;
V_69 = V_138 -> V_139 - V_29 -> V_1 ;
V_145 = F_79 ( V_69 , V_21 ) ;
V_144 = F_80 ( V_29 -> V_51 [ 3 ] ) ;
if ( V_14 -> V_62 . V_147 ) {
T_1 V_136 = V_144 ;
T_1 V_148 = V_136 + V_145 - 1 ;
if ( V_148 < V_136 ) {
V_144 |= 0xffffffff ;
V_69 = V_21 * - V_136 ;
V_146 = true ;
}
} else {
T_5 V_136 = V_144 & 0xffff ;
T_5 V_148 = V_136 + ( T_5 ) V_145 - 1 ;
if ( V_145 >> 16 || V_148 < V_136 ) {
V_144 |= 0xffff ;
V_69 = V_21 * ( 0x10000 - V_136 ) ;
V_146 = true ;
}
}
V_50 = ( V_69 >= V_140 ) ;
V_76 = F_81 ( V_29 -> V_76 , V_138 -> V_76 , V_29 -> V_1 ) ;
V_77 = ( ( V_138 -> V_76 == V_138 -> V_77 ) ? V_76 :
F_81 ( V_29 -> V_77 , V_138 -> V_77 , V_29 -> V_1 ) ) ;
F_40 ( V_14 , V_50 , V_29 -> V_51 ) ;
if ( F_23 ( V_146 ) ) {
V_29 -> V_51 [ 3 ] = F_82 ( V_144 ) ;
F_83 ( ( V_149 * ) V_29 -> V_51 , V_21 ) ;
}
if ( V_50 )
return F_63 ( V_14 , V_76 , V_77 , V_69 ,
F_78 ) ;
return F_44 ( V_14 , V_76 , V_77 , V_69 ,
F_78 ) ;
}
static int F_84 ( struct V_13 * V_14 )
{
struct V_142 * V_29 = F_76 ( V_14 -> V_29 ) ;
struct V_137 * V_138 = F_74 ( V_14 -> V_47 ) ;
struct V_40 * V_41 = F_75 ( V_138 ) ;
int V_33 ;
F_35 ( V_14 , V_41 ) ;
V_33 = F_29 ( V_14 ) ;
if ( V_33 )
return F_37 ( V_14 , V_33 ) ;
memcpy ( V_29 -> V_51 , V_138 -> V_141 , V_21 ) ;
V_29 -> V_1 = 0 ;
V_14 -> V_72 = 0 ;
return F_78 ( V_14 ) ;
}
static int F_85 ( struct V_137 * V_138 , unsigned long V_43 )
{
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
V_29 = F_86 ( F_87 ( V_138 ) ) ;
switch ( V_43 & V_150 ) {
case V_151 :
V_29 -> V_27 = V_120 ;
break;
case V_152 :
V_29 -> V_27 = V_122 ;
break;
case V_153 :
V_29 -> V_27 = V_124 ;
break;
case V_154 :
V_29 -> V_27 = V_125 ;
break;
default:
V_29 -> V_27 = V_21 ;
break;
}
V_14 = F_25 ( V_29 ) ;
if ( ! V_14 )
return - V_155 ;
V_41 = F_75 ( V_138 ) ;
V_41 -> V_43 = V_43 ;
return F_65 ( V_14 , & V_138 -> V_143 ) ;
}
static int F_88 ( struct V_156 * V_135 , const V_149 * V_52 ,
unsigned int V_53 )
{
struct V_28 * V_29 = F_86 ( V_135 ) ;
if ( V_53 != V_55 &&
V_53 != V_57 &&
V_53 != V_157 ) {
F_89 ( V_135 , V_158 ) ;
return - V_73 ;
}
memcpy ( V_29 -> V_52 , V_52 , V_53 ) ;
V_29 -> V_53 = V_53 ;
return 0 ;
}
static int F_90 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_159 | V_44 ) ;
}
static int F_91 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_159 ) ;
}
static int F_92 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_160 | V_44 ) ;
}
static int F_93 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_160 ) ;
}
static int F_94 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_161 | V_44 ) ;
}
static int F_95 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_161 ) ;
}
static int F_96 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_162 | V_44 ) ;
}
static int F_97 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_162 ) ;
}
static int F_98 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_154 | V_44 ) ;
}
static int F_99 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_154 ) ;
}
static int F_100 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_153 | V_44 ) ;
}
static int F_101 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_153 ) ;
}
static int F_102 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_152 | V_44 ) ;
}
static int F_103 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_152 ) ;
}
static int F_104 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_151 | V_44 ) ;
}
static int F_105 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_151 ) ;
}
static int F_106 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_163 | V_44 ) ;
}
static int F_107 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_163 ) ;
}
static int F_108 ( struct V_164 * V_135 )
{
struct V_165 * V_29 = F_71 ( V_135 ) ;
V_135 -> V_166 . V_167 = sizeof( struct V_40 ) ;
V_29 -> V_143 . V_136 = F_73 ;
return 0 ;
}
static int F_109 ( struct V_164 * V_135 )
{
struct V_165 * V_29 = F_71 ( V_135 ) ;
V_135 -> V_166 . V_167 = sizeof( struct V_40 ) ;
V_29 -> V_143 . V_136 = F_84 ;
return 0 ;
}
static void F_110 ( struct V_164 * V_135 )
{
}
static inline struct V_168 *
F_111 ( struct V_28 * V_29 )
{
return F_77 ( V_29 , struct V_168 , V_143 ) ;
}
static int F_112 ( struct V_13 * V_14 ,
const T_1 * V_68 , T_2 V_69 ,
const T_1 * V_169 , T_1 * V_170 ,
T_3 V_22 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
V_14 -> V_68 = ( T_1 * ) V_68 ;
V_14 -> V_69 = V_69 ;
V_29 -> V_169 = V_169 ;
V_29 -> V_170 = V_170 ;
V_29 -> V_171 = V_22 ;
F_40 ( V_14 , false , NULL ) ;
return F_22 ( V_14 , V_172 ) ;
}
static int V_172 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
F_15 ( V_14 , V_10 , V_14 -> V_72 ) ;
F_15 ( V_14 , V_11 , 0 ) ;
if ( V_29 -> V_169 )
F_21 ( V_14 , F_6 ( 0 ) , V_29 -> V_169 ) ;
return F_113 ( V_14 ) ;
}
static int F_113 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
T_1 V_23 ;
while ( V_14 -> V_69 > 0 ) {
F_21 ( V_14 , F_3 ( 0 ) , V_14 -> V_68 ) ;
V_14 -> V_68 += 4 ;
V_14 -> V_69 -= V_21 ;
V_23 = F_11 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_113 ;
F_15 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
F_19 ( V_14 , F_6 ( 0 ) , V_29 -> V_170 ) ;
return V_29 -> V_171 ( V_14 ) ;
}
static int F_114 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
struct V_174 * V_135 = F_116 ( V_138 ) ;
struct V_40 * V_41 = F_117 ( V_138 ) ;
T_2 V_175 = F_118 ( V_135 ) ;
T_2 V_69 , V_78 ;
const void * V_51 = V_138 -> V_51 ;
V_149 * V_68 = V_14 -> V_71 ;
int V_33 ;
F_35 ( V_14 , V_41 ) ;
V_33 = F_29 ( V_14 ) ;
if ( V_33 )
return F_37 ( V_14 , V_33 ) ;
if ( F_119 ( V_175 == 12 ) ) {
memcpy ( V_29 -> j0 , V_51 , V_175 ) ;
V_29 -> j0 [ 3 ] = F_82 ( 1 ) ;
return F_120 ( V_14 ) ;
}
V_78 = F_24 ( V_175 , V_21 ) ;
V_69 = V_175 + V_78 + V_21 ;
if ( V_69 > V_14 -> V_87 )
return F_37 ( V_14 , - V_73 ) ;
memcpy ( V_68 , V_51 , V_175 ) ;
memset ( V_68 + V_175 , 0 , V_78 + sizeof( V_176 ) ) ;
( ( V_176 * ) ( V_68 + V_69 ) ) [ - 1 ] = F_121 ( V_175 * 8 ) ;
return F_112 ( V_14 , ( const T_1 * ) V_68 , V_69 ,
NULL , V_29 -> j0 , F_120 ) ;
}
static int F_120 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
struct V_174 * V_135 = F_116 ( V_138 ) ;
bool V_177 = F_36 ( V_14 ) ;
T_1 V_178 ;
V_178 = F_122 ( V_135 ) ;
V_29 -> V_179 = V_138 -> V_180 - ( V_177 ? 0 : V_178 ) ;
if ( F_119 ( V_138 -> V_181 != 0 || V_29 -> V_179 != 0 ) )
V_14 -> V_17 |= V_182 ;
F_40 ( V_14 , false , NULL ) ;
return F_22 ( V_14 , V_183 ) ;
}
static int V_183 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
T_1 V_184 , * j0 = V_29 -> j0 ;
T_2 V_78 ;
V_184 = j0 [ 3 ] ;
j0 [ 3 ] = F_82 ( F_80 ( j0 [ 3 ] ) + 1 ) ;
F_21 ( V_14 , F_5 ( 0 ) , j0 ) ;
j0 [ 3 ] = V_184 ;
F_15 ( V_14 , V_10 , V_138 -> V_181 ) ;
F_15 ( V_14 , V_11 , V_29 -> V_179 ) ;
if ( F_23 ( V_138 -> V_181 == 0 ) ) {
V_14 -> V_69 = 0 ;
return F_123 ( V_14 ) ;
}
V_78 = F_24 ( V_138 -> V_181 , V_21 ) ;
if ( F_23 ( V_138 -> V_181 + V_78 > V_14 -> V_87 ) )
return F_37 ( V_14 , - V_73 ) ;
F_45 ( V_138 -> V_76 , F_43 ( V_138 -> V_76 ) , V_14 -> V_71 , V_138 -> V_181 ) ;
V_14 -> V_68 = ( T_1 * ) V_14 -> V_71 ;
V_14 -> V_69 = V_138 -> V_181 + V_78 ;
return F_123 ( V_14 ) ;
}
static int F_123 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
bool V_50 = ( V_29 -> V_179 >= V_140 ) ;
struct V_75 * V_76 , * V_77 ;
T_1 V_23 , V_185 ;
while ( V_14 -> V_69 > 0 ) {
F_21 ( V_14 , F_3 ( 0 ) , V_14 -> V_68 ) ;
V_14 -> V_68 += 4 ;
V_14 -> V_69 -= V_21 ;
V_23 = F_11 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_123 ;
F_15 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
if ( F_23 ( V_29 -> V_179 == 0 ) )
return F_124 ( V_14 ) ;
V_76 = F_81 ( V_29 -> V_76 , V_138 -> V_76 , V_138 -> V_181 ) ;
V_77 = ( ( V_138 -> V_76 == V_138 -> V_77 ) ? V_76 :
F_81 ( V_29 -> V_77 , V_138 -> V_77 , V_138 -> V_181 ) ) ;
if ( V_50 ) {
V_185 = F_11 ( V_14 , V_5 ) ;
V_185 &= ~ ( V_186 | V_64 ) ;
V_185 |= V_61 ;
if ( V_14 -> V_62 . V_63 )
V_185 |= V_64 ;
F_15 ( V_14 , V_5 , V_185 ) ;
return F_63 ( V_14 , V_76 , V_77 , V_29 -> V_179 ,
F_124 ) ;
}
return F_44 ( V_14 , V_76 , V_77 , V_29 -> V_179 ,
F_124 ) ;
}
static int F_124 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
V_176 * V_68 = V_14 -> V_71 ;
if ( F_119 ( V_14 -> V_17 & V_182 ) ) {
if ( ! ( F_11 ( V_14 , V_6 ) & V_187 ) ) {
V_14 -> V_22 = F_124 ;
F_15 ( V_14 , V_8 , V_187 ) ;
return - V_25 ;
}
return F_125 ( V_14 ) ;
}
F_19 ( V_14 , F_6 ( 0 ) , V_29 -> V_188 ) ;
V_68 [ 0 ] = F_121 ( V_138 -> V_181 * 8 ) ;
V_68 [ 1 ] = F_121 ( V_29 -> V_179 * 8 ) ;
return F_112 ( V_14 , ( const T_1 * ) V_68 , V_21 ,
V_29 -> V_188 , V_29 -> V_188 , V_189 ) ;
}
static int V_189 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
unsigned long V_17 ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 &= ~ ( V_150 | V_182 ) ;
V_14 -> V_17 |= V_163 ;
F_40 ( V_14 , false , V_29 -> j0 ) ;
V_14 -> V_17 = V_17 ;
F_21 ( V_14 , F_3 ( 0 ) , V_29 -> V_188 ) ;
return F_22 ( V_14 , F_125 ) ;
}
static int F_125 ( struct V_13 * V_14 )
{
struct V_168 * V_29 = F_111 ( V_14 -> V_29 ) ;
struct V_173 * V_138 = F_115 ( V_14 -> V_47 ) ;
struct V_174 * V_135 = F_116 ( V_138 ) ;
bool V_177 = F_36 ( V_14 ) ;
T_1 V_1 , V_178 , V_190 [ 4 ] , * V_191 = V_29 -> V_192 ;
int V_33 ;
if ( F_119 ( V_14 -> V_17 & V_182 ) )
F_19 ( V_14 , F_7 ( 0 ) , V_29 -> V_192 ) ;
else
F_19 ( V_14 , F_4 ( 0 ) , V_29 -> V_192 ) ;
V_1 = V_138 -> V_181 + V_29 -> V_179 ;
V_178 = F_122 ( V_135 ) ;
if ( V_177 ) {
F_126 ( V_191 , V_138 -> V_77 , V_1 , V_178 , 1 ) ;
V_33 = 0 ;
} else {
F_126 ( V_190 , V_138 -> V_76 , V_1 , V_178 , 0 ) ;
V_33 = F_127 ( V_190 , V_191 , V_178 ) ? - V_193 : 0 ;
}
return F_37 ( V_14 , V_33 ) ;
}
static int F_128 ( struct V_173 * V_138 ,
unsigned long V_43 )
{
struct V_28 * V_29 ;
struct V_40 * V_41 ;
struct V_13 * V_14 ;
V_29 = F_129 ( F_116 ( V_138 ) ) ;
V_29 -> V_27 = V_21 ;
V_14 = F_25 ( V_29 ) ;
if ( ! V_14 )
return - V_155 ;
V_41 = F_117 ( V_138 ) ;
V_41 -> V_43 = V_194 | V_43 ;
return F_65 ( V_14 , & V_138 -> V_143 ) ;
}
static int F_130 ( struct V_174 * V_135 , const V_149 * V_52 ,
unsigned int V_53 )
{
struct V_28 * V_29 = F_129 ( V_135 ) ;
if ( V_53 != V_157 &&
V_53 != V_57 &&
V_53 != V_55 ) {
F_131 ( V_135 , V_158 ) ;
return - V_73 ;
}
memcpy ( V_29 -> V_52 , V_52 , V_53 ) ;
V_29 -> V_53 = V_53 ;
return 0 ;
}
static int F_132 ( struct V_174 * V_135 ,
unsigned int V_178 )
{
switch ( V_178 ) {
case 4 :
case 8 :
case 12 :
case 13 :
case 14 :
case 15 :
case 16 :
break;
default:
return - V_73 ;
}
return 0 ;
}
static int F_133 ( struct V_173 * V_138 )
{
return F_128 ( V_138 , V_44 ) ;
}
static int F_134 ( struct V_173 * V_138 )
{
return F_128 ( V_138 , 0 ) ;
}
static int F_135 ( struct V_174 * V_135 )
{
struct V_168 * V_29 = F_129 ( V_135 ) ;
F_136 ( V_135 , sizeof( struct V_40 ) ) ;
V_29 -> V_143 . V_136 = F_114 ;
return 0 ;
}
static void F_137 ( struct V_174 * V_135 )
{
}
static inline struct V_195 *
F_138 ( struct V_28 * V_29 )
{
return F_77 ( V_29 , struct V_195 , V_143 ) ;
}
static int F_139 ( struct V_13 * V_14 )
{
struct V_195 * V_29 = F_138 ( V_14 -> V_29 ) ;
struct V_137 * V_138 = F_74 ( V_14 -> V_47 ) ;
struct V_40 * V_41 = F_75 ( V_138 ) ;
unsigned long V_17 ;
int V_33 ;
F_35 ( V_14 , V_41 ) ;
V_33 = F_29 ( V_14 ) ;
if ( V_33 )
return F_37 ( V_14 , V_33 ) ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 &= ~ V_60 ;
V_14 -> V_17 |= ( V_159 | V_44 ) ;
F_39 ( V_14 , false , NULL ,
V_29 -> V_196 , V_29 -> V_143 . V_53 ) ;
V_14 -> V_17 = V_17 ;
F_21 ( V_14 , F_3 ( 0 ) , V_138 -> V_141 ) ;
return F_22 ( V_14 , V_197 ) ;
}
static int V_197 ( struct V_13 * V_14 )
{
struct V_137 * V_138 = F_74 ( V_14 -> V_47 ) ;
bool V_50 = ( V_138 -> V_139 >= V_140 ) ;
T_1 V_198 [ V_21 / sizeof( T_1 ) ] ;
static const T_1 V_199 [ V_21 / sizeof( T_1 ) ] = { F_140 ( 1 ) , } ;
V_149 * V_200 = ( V_149 * ) V_198 ;
int V_201 ;
F_19 ( V_14 , F_4 ( 0 ) , V_198 ) ;
for ( V_201 = 0 ; V_201 < V_21 / 2 ; ++ V_201 ) {
V_149 V_2 = V_200 [ V_21 - 1 - V_201 ] ;
V_200 [ V_21 - 1 - V_201 ] = V_200 [ V_201 ] ;
V_200 [ V_201 ] = V_2 ;
}
F_40 ( V_14 , V_50 , NULL ) ;
F_21 ( V_14 , F_9 ( 0 ) , V_198 ) ;
F_21 ( V_14 , F_10 ( 0 ) , V_199 ) ;
if ( V_50 )
return F_63 ( V_14 , V_138 -> V_76 , V_138 -> V_77 , V_138 -> V_139 ,
F_72 ) ;
return F_44 ( V_14 , V_138 -> V_76 , V_138 -> V_77 , V_138 -> V_139 ,
F_72 ) ;
}
static int F_141 ( struct V_156 * V_135 , const V_149 * V_52 ,
unsigned int V_53 )
{
struct V_195 * V_29 = F_86 ( V_135 ) ;
int V_33 ;
V_33 = F_142 ( F_143 ( V_135 ) , V_52 , V_53 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_29 -> V_143 . V_52 , V_52 , V_53 / 2 ) ;
memcpy ( V_29 -> V_196 , V_52 + V_53 / 2 , V_53 / 2 ) ;
V_29 -> V_143 . V_53 = V_53 / 2 ;
return 0 ;
}
static int F_144 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_202 | V_44 ) ;
}
static int F_145 ( struct V_137 * V_138 )
{
return F_85 ( V_138 , V_202 ) ;
}
static int F_146 ( struct V_164 * V_135 )
{
struct V_195 * V_29 = F_71 ( V_135 ) ;
V_135 -> V_166 . V_167 = sizeof( struct V_40 ) ;
V_29 -> V_143 . V_136 = F_139 ;
return 0 ;
}
static int F_147 ( struct V_13 * V_14 )
{
V_14 -> V_71 = ( void * ) F_148 ( V_203 , V_204 ) ;
V_14 -> V_87 = V_205 ;
V_14 -> V_87 &= ~ ( V_21 - 1 ) ;
if ( ! V_14 -> V_71 ) {
F_149 ( V_14 -> V_19 , L_23 ) ;
return - V_88 ;
}
return 0 ;
}
static void F_150 ( struct V_13 * V_14 )
{
F_151 ( ( unsigned long ) V_14 -> V_71 ) ;
}
static bool F_152 ( struct V_206 * V_116 , void * V_207 )
{
struct V_208 * V_209 = V_207 ;
if ( V_209 && V_209 -> V_210 == V_116 -> V_211 -> V_19 ) {
V_116 -> V_212 = V_209 ;
return true ;
} else {
return false ;
}
}
static int F_153 ( struct V_13 * V_14 ,
struct V_213 * V_214 )
{
struct V_208 * V_207 ;
int V_33 = - V_88 ;
T_6 V_215 ;
F_154 ( V_215 ) ;
F_155 ( V_216 , V_215 ) ;
V_207 = & V_214 -> V_217 -> V_218 ;
V_14 -> V_76 . V_116 = F_156 ( V_215 , F_152 ,
V_207 , V_14 -> V_19 , L_24 ) ;
if ( ! V_14 -> V_76 . V_116 )
goto V_219;
V_207 = & V_214 -> V_217 -> V_220 ;
V_14 -> V_77 . V_116 = F_156 ( V_215 , F_152 ,
V_207 , V_14 -> V_19 , L_25 ) ;
if ( ! V_14 -> V_77 . V_116 )
goto V_221;
return 0 ;
V_221:
F_157 ( V_14 -> V_76 . V_116 ) ;
V_219:
F_158 ( V_14 -> V_19 , L_26 ) ;
return V_33 ;
}
static void F_159 ( struct V_13 * V_14 )
{
F_157 ( V_14 -> V_77 . V_116 ) ;
F_157 ( V_14 -> V_76 . V_116 ) ;
}
static void F_160 ( unsigned long V_68 )
{
struct V_13 * V_14 = (struct V_13 * ) V_68 ;
F_65 ( V_14 , NULL ) ;
}
static void F_161 ( unsigned long V_68 )
{
struct V_13 * V_14 = (struct V_13 * ) V_68 ;
V_14 -> V_46 = true ;
( void ) V_14 -> V_22 ( V_14 ) ;
}
static T_7 F_162 ( int V_222 , void * V_223 )
{
struct V_13 * V_30 = V_223 ;
T_1 V_224 ;
V_224 = F_11 ( V_30 , V_6 ) ;
if ( V_224 & F_11 ( V_30 , V_7 ) ) {
F_15 ( V_30 , V_9 , V_224 ) ;
if ( V_45 & V_30 -> V_17 )
F_38 ( & V_30 -> V_225 ) ;
else
F_158 ( V_30 -> V_19 , L_27 ) ;
return V_226 ;
}
return V_227 ;
}
static void F_163 ( struct V_13 * V_14 )
{
int V_201 ;
if ( V_14 -> V_62 . V_228 )
F_164 ( & V_229 ) ;
if ( V_14 -> V_62 . V_230 )
F_165 ( & V_231 ) ;
if ( V_14 -> V_62 . V_232 )
F_164 ( & V_233 ) ;
for ( V_201 = 0 ; V_201 < F_166 ( V_234 ) ; V_201 ++ )
F_164 ( & V_234 [ V_201 ] ) ;
}
static int F_167 ( struct V_13 * V_14 )
{
int V_33 , V_201 , V_235 ;
for ( V_201 = 0 ; V_201 < F_166 ( V_234 ) ; V_201 ++ ) {
V_33 = F_168 ( & V_234 [ V_201 ] ) ;
if ( V_33 )
goto V_236;
}
if ( V_14 -> V_62 . V_232 ) {
V_33 = F_168 ( & V_233 ) ;
if ( V_33 )
goto V_237;
}
if ( V_14 -> V_62 . V_230 ) {
V_33 = F_169 ( & V_231 ) ;
if ( V_33 )
goto V_238;
}
if ( V_14 -> V_62 . V_228 ) {
V_33 = F_168 ( & V_229 ) ;
if ( V_33 )
goto V_239;
}
return 0 ;
V_239:
F_165 ( & V_231 ) ;
V_238:
F_164 ( & V_233 ) ;
V_237:
V_201 = F_166 ( V_234 ) ;
V_236:
for ( V_235 = 0 ; V_235 < V_201 ; V_235 ++ )
F_164 ( & V_234 [ V_235 ] ) ;
return V_33 ;
}
static void F_170 ( struct V_13 * V_14 )
{
V_14 -> V_62 . V_63 = 0 ;
V_14 -> V_62 . V_232 = 0 ;
V_14 -> V_62 . V_147 = 0 ;
V_14 -> V_62 . V_230 = 0 ;
V_14 -> V_62 . V_228 = 0 ;
V_14 -> V_62 . V_127 = 1 ;
switch ( V_14 -> V_39 & 0xff0 ) {
case 0x500 :
V_14 -> V_62 . V_63 = 1 ;
V_14 -> V_62 . V_232 = 1 ;
V_14 -> V_62 . V_147 = 1 ;
V_14 -> V_62 . V_230 = 1 ;
V_14 -> V_62 . V_228 = 1 ;
V_14 -> V_62 . V_127 = 4 ;
break;
case 0x200 :
V_14 -> V_62 . V_63 = 1 ;
V_14 -> V_62 . V_232 = 1 ;
V_14 -> V_62 . V_147 = 1 ;
V_14 -> V_62 . V_230 = 1 ;
V_14 -> V_62 . V_127 = 4 ;
break;
case 0x130 :
V_14 -> V_62 . V_63 = 1 ;
V_14 -> V_62 . V_232 = 1 ;
V_14 -> V_62 . V_127 = 4 ;
break;
case 0x120 :
break;
default:
F_158 ( V_14 -> V_19 ,
L_28 ) ;
break;
}
}
static struct V_213 * F_171 ( struct V_240 * V_241 )
{
struct V_242 * V_243 = V_241 -> V_19 . V_244 ;
struct V_213 * V_214 ;
if ( ! V_243 ) {
F_149 ( & V_241 -> V_19 , L_29 ) ;
return F_172 ( - V_73 ) ;
}
V_214 = F_173 ( & V_241 -> V_19 , sizeof( * V_214 ) , V_203 ) ;
if ( ! V_214 ) {
F_149 ( & V_241 -> V_19 , L_30 ) ;
return F_172 ( - V_88 ) ;
}
V_214 -> V_217 = F_173 ( & V_241 -> V_19 ,
sizeof( * ( V_214 -> V_217 ) ) ,
V_203 ) ;
if ( ! V_214 -> V_217 ) {
F_149 ( & V_241 -> V_19 , L_31 ) ;
F_174 ( & V_241 -> V_19 , V_214 ) ;
return F_172 ( - V_88 ) ;
}
return V_214 ;
}
static inline struct V_213 * F_171 ( struct V_240 * V_241 )
{
return F_172 ( - V_73 ) ;
}
static int F_175 ( struct V_240 * V_241 )
{
struct V_13 * V_30 ;
struct V_213 * V_214 ;
struct V_211 * V_19 = & V_241 -> V_19 ;
struct V_245 * V_246 ;
int V_33 ;
V_214 = V_241 -> V_19 . V_247 ;
if ( ! V_214 ) {
V_214 = F_171 ( V_241 ) ;
if ( F_176 ( V_214 ) ) {
V_33 = F_177 ( V_214 ) ;
goto V_248;
}
}
if ( ! V_214 -> V_217 ) {
V_33 = - V_249 ;
goto V_248;
}
V_30 = F_173 ( & V_241 -> V_19 , sizeof( * V_30 ) , V_203 ) ;
if ( V_30 == NULL ) {
F_149 ( V_19 , L_32 ) ;
V_33 = - V_88 ;
goto V_248;
}
V_30 -> V_19 = V_19 ;
F_178 ( V_241 , V_30 ) ;
F_179 ( & V_30 -> V_250 ) ;
F_180 ( & V_30 -> V_32 ) ;
F_181 ( & V_30 -> V_225 , F_161 ,
( unsigned long ) V_30 ) ;
F_181 ( & V_30 -> V_49 , F_160 ,
( unsigned long ) V_30 ) ;
F_182 ( & V_30 -> V_134 , V_251 ) ;
V_30 -> V_222 = - 1 ;
V_246 = F_183 ( V_241 , V_252 , 0 ) ;
if ( ! V_246 ) {
F_149 ( V_19 , L_33 ) ;
V_33 = - V_155 ;
goto V_253;
}
V_30 -> V_112 = V_246 -> V_136 ;
V_30 -> V_222 = F_184 ( V_241 , 0 ) ;
if ( V_30 -> V_222 < 0 ) {
F_149 ( V_19 , L_34 ) ;
V_33 = V_30 -> V_222 ;
goto V_253;
}
V_33 = F_185 ( & V_241 -> V_19 , V_30 -> V_222 , F_162 ,
V_254 , L_35 , V_30 ) ;
if ( V_33 ) {
F_149 ( V_19 , L_36 ) ;
goto V_253;
}
V_30 -> V_34 = F_186 ( & V_241 -> V_19 , L_37 ) ;
if ( F_176 ( V_30 -> V_34 ) ) {
F_149 ( V_19 , L_38 ) ;
V_33 = F_177 ( V_30 -> V_34 ) ;
goto V_253;
}
V_30 -> V_16 = F_187 ( & V_241 -> V_19 , V_246 ) ;
if ( F_176 ( V_30 -> V_16 ) ) {
F_149 ( V_19 , L_39 ) ;
V_33 = F_177 ( V_30 -> V_16 ) ;
goto V_253;
}
V_33 = F_188 ( V_30 -> V_34 ) ;
if ( V_33 )
goto V_253;
V_33 = F_32 ( V_30 ) ;
if ( V_33 )
goto V_255;
F_170 ( V_30 ) ;
V_33 = F_147 ( V_30 ) ;
if ( V_33 )
goto V_256;
V_33 = F_153 ( V_30 , V_214 ) ;
if ( V_33 )
goto V_257;
F_189 ( & V_31 . V_32 ) ;
F_190 ( & V_30 -> V_250 , & V_31 . V_258 ) ;
F_191 ( & V_31 . V_32 ) ;
V_33 = F_167 ( V_30 ) ;
if ( V_33 )
goto V_259;
F_33 ( V_19 , L_40 ,
F_192 ( V_30 -> V_76 . V_116 ) ,
F_192 ( V_30 -> V_77 . V_116 ) ) ;
return 0 ;
V_259:
F_189 ( & V_31 . V_32 ) ;
F_193 ( & V_30 -> V_250 ) ;
F_191 ( & V_31 . V_32 ) ;
F_159 ( V_30 ) ;
V_257:
F_150 ( V_30 ) ;
V_256:
V_255:
F_194 ( V_30 -> V_34 ) ;
V_253:
F_195 ( & V_30 -> V_225 ) ;
F_195 ( & V_30 -> V_49 ) ;
V_248:
F_149 ( V_19 , L_41 ) ;
return V_33 ;
}
static int F_196 ( struct V_240 * V_241 )
{
struct V_13 * V_30 ;
V_30 = F_197 ( V_241 ) ;
if ( ! V_30 )
return - V_155 ;
F_189 ( & V_31 . V_32 ) ;
F_193 ( & V_30 -> V_250 ) ;
F_191 ( & V_31 . V_32 ) ;
F_163 ( V_30 ) ;
F_195 ( & V_30 -> V_225 ) ;
F_195 ( & V_30 -> V_49 ) ;
F_159 ( V_30 ) ;
F_150 ( V_30 ) ;
F_194 ( V_30 -> V_34 ) ;
return 0 ;
}
