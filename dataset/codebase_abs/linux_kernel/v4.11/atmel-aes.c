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
case V_13 :
return L_17 ;
case F_9 ( 0 ) :
case F_9 ( 1 ) :
case F_9 ( 2 ) :
case F_9 ( 3 ) :
snprintf ( V_2 , V_3 , L_18 , ( V_1 - F_9 ( 0 ) ) >> 2 ) ;
break;
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
snprintf ( V_2 , V_3 , L_19 , ( V_1 - F_10 ( 0 ) ) >> 2 ) ;
break;
default:
snprintf ( V_2 , V_3 , L_20 , V_1 ) ;
break;
}
return V_2 ;
}
static inline T_1 F_11 ( struct V_14 * V_15 , T_1 V_1 )
{
T_1 V_16 = F_12 ( V_15 -> V_17 + V_1 ) ;
#ifdef F_13
if ( V_15 -> V_18 & V_19 ) {
char V_2 [ 16 ] ;
F_14 ( V_15 -> V_20 , L_21 , V_16 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ) ;
}
#endif
return V_16 ;
}
static inline void F_15 ( struct V_14 * V_15 ,
T_1 V_1 , T_1 V_16 )
{
#ifdef F_13
if ( V_15 -> V_18 & V_19 ) {
char V_2 [ 16 ] ;
F_14 ( V_15 -> V_20 , L_22 , V_16 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ) ;
}
#endif
F_16 ( V_16 , V_15 -> V_17 + V_1 ) ;
}
static void F_17 ( struct V_14 * V_15 , T_1 V_1 ,
T_1 * V_16 , int V_21 )
{
for (; V_21 -- ; V_16 ++ , V_1 += 4 )
* V_16 = F_11 ( V_15 , V_1 ) ;
}
static void F_18 ( struct V_14 * V_15 , T_1 V_1 ,
const T_1 * V_16 , int V_21 )
{
for (; V_21 -- ; V_16 ++ , V_1 += 4 )
F_15 ( V_15 , V_1 , * V_16 ) ;
}
static inline void F_19 ( struct V_14 * V_15 , T_1 V_1 ,
T_1 * V_16 )
{
F_17 ( V_15 , V_1 , V_16 , F_20 ( V_22 ) ) ;
}
static inline void F_21 ( struct V_14 * V_15 , T_1 V_1 ,
const T_1 * V_16 )
{
F_18 ( V_15 , V_1 , V_16 , F_20 ( V_22 ) ) ;
}
static inline int F_22 ( struct V_14 * V_15 ,
T_3 V_23 )
{
T_1 V_24 = F_11 ( V_15 , V_6 ) ;
if ( F_23 ( V_24 & V_25 ) )
return V_23 ( V_15 ) ;
V_15 -> V_23 = V_23 ;
F_15 ( V_15 , V_8 , V_25 ) ;
return - V_26 ;
}
static inline T_2 F_24 ( T_2 V_27 , T_2 V_28 )
{
V_27 &= V_28 - 1 ;
return V_27 ? V_28 - V_27 : 0 ;
}
static struct V_14 * F_25 ( struct V_29 * V_30 )
{
struct V_14 * V_31 = NULL ;
struct V_14 * V_2 ;
F_26 ( & V_32 . V_33 ) ;
if ( ! V_30 -> V_15 ) {
F_27 (tmp, &atmel_aes.dev_list, list) {
V_31 = V_2 ;
break;
}
V_30 -> V_15 = V_31 ;
} else {
V_31 = V_30 -> V_15 ;
}
F_28 ( & V_32 . V_33 ) ;
return V_31 ;
}
static int F_29 ( struct V_14 * V_15 )
{
int V_34 ;
V_34 = F_30 ( V_15 -> V_35 ) ;
if ( V_34 )
return V_34 ;
if ( ! ( V_15 -> V_18 & V_36 ) ) {
F_15 ( V_15 , V_4 , V_37 ) ;
F_15 ( V_15 , V_5 , 0xE << V_38 ) ;
V_15 -> V_18 |= V_36 ;
}
return 0 ;
}
static inline unsigned int F_31 ( struct V_14 * V_15 )
{
return F_11 ( V_15 , V_39 ) & 0x00000fff ;
}
static int F_32 ( struct V_14 * V_15 )
{
int V_34 ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return V_34 ;
V_15 -> V_40 = F_31 ( V_15 ) ;
F_33 ( V_15 -> V_20 , L_23 , V_15 -> V_40 ) ;
F_34 ( V_15 -> V_35 ) ;
return 0 ;
}
static inline void F_35 ( struct V_14 * V_15 ,
const struct V_41 * V_42 )
{
V_15 -> V_18 = ( V_15 -> V_18 & V_43 ) | V_42 -> V_44 ;
}
static inline bool F_36 ( const struct V_14 * V_15 )
{
return ( V_15 -> V_18 & V_45 ) ;
}
static inline int F_37 ( struct V_14 * V_15 , int V_34 )
{
#ifdef F_38
F_39 ( V_15 , V_34 ) ;
#endif
F_34 ( V_15 -> V_35 ) ;
V_15 -> V_18 &= ~ V_46 ;
if ( V_15 -> V_47 )
V_15 -> V_48 -> V_49 ( V_15 -> V_48 , V_34 ) ;
F_40 ( & V_15 -> V_50 ) ;
return V_34 ;
}
static void F_41 ( struct V_14 * V_15 , bool V_51 ,
const T_1 * V_52 , const T_1 * V_53 , int V_54 )
{
T_1 V_55 = 0 ;
if ( V_54 == V_56 )
V_55 |= V_57 ;
else if ( V_54 == V_58 )
V_55 |= V_59 ;
else
V_55 |= V_60 ;
V_55 |= V_15 -> V_18 & V_61 ;
if ( V_51 ) {
V_55 |= V_62 ;
if ( V_15 -> V_63 . V_64 )
V_55 |= V_65 ;
} else {
V_55 |= V_66 ;
}
F_15 ( V_15 , V_5 , V_55 ) ;
F_18 ( V_15 , F_2 ( 0 ) , V_53 , F_20 ( V_54 ) ) ;
if ( V_52 && ( V_55 & V_67 ) != V_68 )
F_21 ( V_15 , F_5 ( 0 ) , V_52 ) ;
}
static inline void F_42 ( struct V_14 * V_15 , bool V_51 ,
const T_1 * V_52 )
{
F_41 ( V_15 , V_51 , V_52 ,
V_15 -> V_30 -> V_53 , V_15 -> V_30 -> V_54 ) ;
}
static int F_43 ( struct V_14 * V_15 )
{
int V_34 = 0 ;
T_1 V_24 ;
for (; ; ) {
F_19 ( V_15 , F_4 ( 0 ) , V_15 -> V_69 ) ;
V_15 -> V_69 += 4 ;
V_15 -> V_70 -= V_22 ;
if ( V_15 -> V_70 < V_22 )
break;
F_21 ( V_15 , F_3 ( 0 ) , V_15 -> V_69 ) ;
V_24 = F_11 ( V_15 , V_6 ) ;
if ( ! ( V_24 & V_25 ) ) {
V_15 -> V_23 = F_43 ;
F_15 ( V_15 , V_8 , V_25 ) ;
return - V_26 ;
}
}
if ( ! F_44 ( V_15 -> V_71 , F_45 ( V_15 -> V_71 ) ,
V_15 -> V_72 , V_15 -> V_73 ) )
V_34 = - V_74 ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
return V_15 -> V_75 ( V_15 ) ;
}
static int F_46 ( struct V_14 * V_15 ,
struct V_76 * V_77 ,
struct V_76 * V_78 ,
T_2 V_27 ,
T_3 V_23 )
{
T_2 V_79 = F_24 ( V_27 , V_22 ) ;
if ( F_23 ( V_27 == 0 ) )
return - V_74 ;
F_47 ( V_77 , F_45 ( V_77 ) , V_15 -> V_72 , V_27 ) ;
V_15 -> V_73 = V_27 ;
V_15 -> V_71 = V_78 ;
V_15 -> V_75 = V_23 ;
V_15 -> V_70 = V_27 + V_79 ;
V_15 -> V_69 = ( T_1 * ) V_15 -> V_72 ;
F_21 ( V_15 , F_3 ( 0 ) , V_15 -> V_69 ) ;
return F_22 ( V_15 , F_43 ) ;
}
static bool F_48 ( struct V_14 * V_15 ,
struct V_76 * V_80 ,
T_2 V_27 ,
struct V_81 * V_82 )
{
int V_83 ;
if ( ! F_49 ( V_27 , V_15 -> V_30 -> V_28 ) )
return false ;
for ( V_83 = 0 ; V_80 ; V_80 = F_50 ( V_80 ) , ++ V_83 ) {
if ( ! F_49 ( V_80 -> V_1 , sizeof( T_1 ) ) )
return false ;
if ( V_27 <= V_80 -> V_84 ) {
if ( ! F_49 ( V_27 , V_15 -> V_30 -> V_28 ) )
return false ;
V_82 -> V_83 = V_83 + 1 ;
V_82 -> V_85 = V_80 -> V_84 - V_27 ;
V_80 -> V_84 = V_27 ;
return true ;
}
if ( ! F_49 ( V_80 -> V_84 , V_15 -> V_30 -> V_28 ) )
return false ;
V_27 -= V_80 -> V_84 ;
}
return false ;
}
static inline void F_51 ( const struct V_81 * V_82 )
{
struct V_76 * V_80 = V_82 -> V_80 ;
int V_83 = V_82 -> V_83 ;
if ( ! V_82 -> V_85 )
return;
while ( -- V_83 > 0 && V_80 )
V_80 = F_50 ( V_80 ) ;
if ( ! V_80 )
return;
V_80 -> V_84 += V_82 -> V_85 ;
}
static int F_52 ( struct V_14 * V_15 ,
struct V_76 * V_77 ,
struct V_76 * V_78 ,
T_2 V_27 )
{
bool V_86 , V_87 ;
T_2 V_79 ;
V_15 -> V_73 = V_27 ;
V_15 -> V_77 . V_80 = V_77 ;
V_15 -> V_78 . V_80 = V_78 ;
V_15 -> V_71 = V_78 ;
V_86 = F_48 ( V_15 , V_77 , V_27 , & V_15 -> V_77 ) ;
if ( V_77 == V_78 )
V_87 = V_86 ;
else
V_87 = F_48 ( V_15 , V_78 , V_27 , & V_15 -> V_78 ) ;
if ( ! V_86 || ! V_87 ) {
V_79 = F_24 ( V_27 , V_15 -> V_30 -> V_28 ) ;
if ( V_15 -> V_88 < V_27 + V_79 )
return - V_89 ;
if ( ! V_86 ) {
F_47 ( V_77 , F_45 ( V_77 ) , V_15 -> V_72 , V_27 ) ;
V_15 -> V_77 . V_80 = & V_15 -> V_90 ;
V_15 -> V_77 . V_83 = 1 ;
V_15 -> V_77 . V_85 = 0 ;
}
if ( ! V_87 ) {
V_15 -> V_78 . V_80 = & V_15 -> V_90 ;
V_15 -> V_78 . V_83 = 1 ;
V_15 -> V_78 . V_85 = 0 ;
}
F_53 ( & V_15 -> V_90 , 1 ) ;
F_54 ( & V_15 -> V_90 , V_15 -> V_72 , V_27 + V_79 ) ;
}
if ( V_15 -> V_77 . V_80 == V_15 -> V_78 . V_80 ) {
V_15 -> V_77 . V_91 = F_55 ( V_15 -> V_20 , V_15 -> V_77 . V_80 , V_15 -> V_77 . V_83 ,
V_92 ) ;
V_15 -> V_78 . V_91 = V_15 -> V_77 . V_91 ;
if ( ! V_15 -> V_77 . V_91 )
return - V_93 ;
} else {
V_15 -> V_77 . V_91 = F_55 ( V_15 -> V_20 , V_15 -> V_77 . V_80 , V_15 -> V_77 . V_83 ,
V_94 ) ;
if ( ! V_15 -> V_77 . V_91 )
return - V_93 ;
V_15 -> V_78 . V_91 = F_55 ( V_15 -> V_20 , V_15 -> V_78 . V_80 , V_15 -> V_78 . V_83 ,
V_95 ) ;
if ( ! V_15 -> V_78 . V_91 ) {
F_56 ( V_15 -> V_20 , V_15 -> V_77 . V_80 , V_15 -> V_77 . V_83 ,
V_94 ) ;
return - V_93 ;
}
}
return 0 ;
}
static void F_57 ( struct V_14 * V_15 )
{
if ( V_15 -> V_77 . V_80 == V_15 -> V_78 . V_80 ) {
F_56 ( V_15 -> V_20 , V_15 -> V_77 . V_80 , V_15 -> V_77 . V_83 ,
V_92 ) ;
if ( V_15 -> V_77 . V_80 != & V_15 -> V_90 )
F_51 ( & V_15 -> V_77 ) ;
} else {
F_56 ( V_15 -> V_20 , V_15 -> V_78 . V_80 , V_15 -> V_78 . V_83 ,
V_95 ) ;
if ( V_15 -> V_78 . V_80 != & V_15 -> V_90 )
F_51 ( & V_15 -> V_78 ) ;
F_56 ( V_15 -> V_20 , V_15 -> V_77 . V_80 , V_15 -> V_77 . V_83 ,
V_94 ) ;
if ( V_15 -> V_77 . V_80 != & V_15 -> V_90 )
F_51 ( & V_15 -> V_77 ) ;
}
if ( V_15 -> V_78 . V_80 == & V_15 -> V_90 )
F_44 ( V_15 -> V_71 , F_45 ( V_15 -> V_71 ) ,
V_15 -> V_72 , V_15 -> V_73 ) ;
}
static int F_58 ( struct V_14 * V_15 ,
enum V_96 V_97 ,
enum V_98 V_99 ,
T_1 V_100 )
{
struct V_101 * V_102 ;
struct V_103 V_104 ;
T_4 V_105 ;
struct V_81 * V_82 ;
int V_34 ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_106 = V_99 ;
V_104 . V_107 = V_97 ;
V_104 . V_108 = V_97 ;
V_104 . V_109 = V_100 ;
V_104 . V_110 = V_100 ;
switch ( V_99 ) {
case V_111 :
V_82 = & V_15 -> V_77 ;
V_105 = NULL ;
V_104 . V_112 = V_15 -> V_113 + F_3 ( 0 ) ;
break;
case V_114 :
V_82 = & V_15 -> V_78 ;
V_105 = V_115 ;
V_104 . V_116 = V_15 -> V_113 + F_4 ( 0 ) ;
break;
default:
return - V_74 ;
}
V_34 = F_59 ( V_82 -> V_117 , & V_104 ) ;
if ( V_34 )
return V_34 ;
V_102 = F_60 ( V_82 -> V_117 , V_82 -> V_80 , V_82 -> V_91 , V_99 ,
V_118 | V_119 ) ;
if ( ! V_102 )
return - V_89 ;
V_102 -> V_105 = V_105 ;
V_102 -> V_120 = V_15 ;
F_61 ( V_102 ) ;
F_62 ( V_82 -> V_117 ) ;
return 0 ;
}
static void F_63 ( struct V_14 * V_15 ,
enum V_98 V_99 )
{
struct V_81 * V_82 ;
switch ( V_99 ) {
case V_111 :
V_82 = & V_15 -> V_77 ;
break;
case V_114 :
V_82 = & V_15 -> V_78 ;
break;
default:
return;
}
F_64 ( V_82 -> V_117 ) ;
}
static int F_65 ( struct V_14 * V_15 ,
struct V_76 * V_77 ,
struct V_76 * V_78 ,
T_2 V_27 ,
T_3 V_23 )
{
enum V_96 V_97 ;
T_1 V_100 ;
int V_34 ;
switch ( V_15 -> V_30 -> V_28 ) {
case V_121 :
V_97 = V_122 ;
V_100 = 1 ;
break;
case V_123 :
V_97 = V_124 ;
V_100 = 1 ;
break;
case V_125 :
case V_126 :
V_97 = V_127 ;
V_100 = 1 ;
break;
case V_22 :
V_97 = V_127 ;
V_100 = V_15 -> V_63 . V_128 ;
break;
default:
V_34 = - V_74 ;
goto exit;
}
V_34 = F_52 ( V_15 , V_77 , V_78 , V_27 ) ;
if ( V_34 )
goto exit;
V_15 -> V_23 = V_23 ;
V_34 = F_58 ( V_15 , V_97 , V_114 ,
V_100 ) ;
if ( V_34 )
goto V_129;
V_34 = F_58 ( V_15 , V_97 , V_111 ,
V_100 ) ;
if ( V_34 )
goto V_130;
return - V_26 ;
V_130:
F_63 ( V_15 , V_114 ) ;
V_129:
F_57 ( V_15 ) ;
exit:
return F_37 ( V_15 , V_34 ) ;
}
static void F_66 ( struct V_14 * V_15 )
{
F_63 ( V_15 , V_111 ) ;
F_63 ( V_15 , V_114 ) ;
F_57 ( V_15 ) ;
}
static void V_115 ( void * V_69 )
{
struct V_14 * V_15 = V_69 ;
F_66 ( V_15 ) ;
V_15 -> V_47 = true ;
( void ) V_15 -> V_23 ( V_15 ) ;
}
static int F_67 ( struct V_14 * V_15 ,
struct V_131 * V_132 )
{
struct V_131 * V_48 , * V_133 ;
struct V_29 * V_30 ;
unsigned long V_18 ;
bool V_134 ;
int V_34 , V_135 = 0 ;
F_68 ( & V_15 -> V_33 , V_18 ) ;
if ( V_132 )
V_135 = F_69 ( & V_15 -> V_136 , V_132 ) ;
if ( V_15 -> V_18 & V_46 ) {
F_70 ( & V_15 -> V_33 , V_18 ) ;
return V_135 ;
}
V_133 = F_71 ( & V_15 -> V_136 ) ;
V_48 = F_72 ( & V_15 -> V_136 ) ;
if ( V_48 )
V_15 -> V_18 |= V_46 ;
F_70 ( & V_15 -> V_33 , V_18 ) ;
if ( ! V_48 )
return V_135 ;
if ( V_133 )
V_133 -> V_49 ( V_133 , - V_26 ) ;
V_30 = F_73 ( V_48 -> V_137 ) ;
V_15 -> V_48 = V_48 ;
V_15 -> V_30 = V_30 ;
V_134 = ( V_48 != V_132 ) ;
V_15 -> V_47 = V_134 ;
V_34 = V_30 -> V_138 ( V_15 ) ;
return ( V_134 ) ? V_135 : V_34 ;
}
static int F_74 ( struct V_14 * V_15 )
{
return F_37 ( V_15 , 0 ) ;
}
static int F_75 ( struct V_14 * V_15 )
{
struct V_139 * V_140 = F_76 ( V_15 -> V_48 ) ;
struct V_41 * V_42 = F_77 ( V_140 ) ;
bool V_51 = ( V_140 -> V_141 >= V_142 ||
V_15 -> V_30 -> V_28 != V_22 ) ;
int V_34 ;
F_35 ( V_15 , V_42 ) ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
F_42 ( V_15 , V_51 , V_140 -> V_143 ) ;
if ( V_51 )
return F_65 ( V_15 , V_140 -> V_77 , V_140 -> V_78 , V_140 -> V_141 ,
F_74 ) ;
return F_46 ( V_15 , V_140 -> V_77 , V_140 -> V_78 , V_140 -> V_141 ,
F_74 ) ;
}
static inline struct V_144 *
F_78 ( struct V_29 * V_30 )
{
return F_79 ( V_30 , struct V_144 , V_145 ) ;
}
static int F_80 ( struct V_14 * V_15 )
{
struct V_144 * V_30 = F_78 ( V_15 -> V_30 ) ;
struct V_139 * V_140 = F_76 ( V_15 -> V_48 ) ;
struct V_76 * V_77 , * V_78 ;
T_1 V_146 , V_147 ;
T_2 V_70 ;
bool V_51 , V_148 = false ;
V_30 -> V_1 += V_15 -> V_73 ;
if ( V_30 -> V_1 >= V_140 -> V_141 )
return F_74 ( V_15 ) ;
V_70 = V_140 -> V_141 - V_30 -> V_1 ;
V_147 = F_81 ( V_70 , V_22 ) ;
V_146 = F_82 ( V_30 -> V_52 [ 3 ] ) ;
if ( V_15 -> V_63 . V_149 ) {
T_1 V_138 = V_146 ;
T_1 V_150 = V_138 + V_147 - 1 ;
if ( V_150 < V_138 ) {
V_146 |= 0xffffffff ;
V_70 = V_22 * - V_138 ;
V_148 = true ;
}
} else {
T_5 V_138 = V_146 & 0xffff ;
T_5 V_150 = V_138 + ( T_5 ) V_147 - 1 ;
if ( V_147 >> 16 || V_150 < V_138 ) {
V_146 |= 0xffff ;
V_70 = V_22 * ( 0x10000 - V_138 ) ;
V_148 = true ;
}
}
V_51 = ( V_70 >= V_142 ) ;
V_77 = F_83 ( V_30 -> V_77 , V_140 -> V_77 , V_30 -> V_1 ) ;
V_78 = ( ( V_140 -> V_77 == V_140 -> V_78 ) ? V_77 :
F_83 ( V_30 -> V_78 , V_140 -> V_78 , V_30 -> V_1 ) ) ;
F_42 ( V_15 , V_51 , V_30 -> V_52 ) ;
if ( F_23 ( V_148 ) ) {
V_30 -> V_52 [ 3 ] = F_84 ( V_146 ) ;
F_85 ( ( V_151 * ) V_30 -> V_52 , V_22 ) ;
}
if ( V_51 )
return F_65 ( V_15 , V_77 , V_78 , V_70 ,
F_80 ) ;
return F_46 ( V_15 , V_77 , V_78 , V_70 ,
F_80 ) ;
}
static int F_86 ( struct V_14 * V_15 )
{
struct V_144 * V_30 = F_78 ( V_15 -> V_30 ) ;
struct V_139 * V_140 = F_76 ( V_15 -> V_48 ) ;
struct V_41 * V_42 = F_77 ( V_140 ) ;
int V_34 ;
F_35 ( V_15 , V_42 ) ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
memcpy ( V_30 -> V_52 , V_140 -> V_143 , V_22 ) ;
V_30 -> V_1 = 0 ;
V_15 -> V_73 = 0 ;
return F_80 ( V_15 ) ;
}
static int F_87 ( struct V_139 * V_140 , unsigned long V_44 )
{
struct V_29 * V_30 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
V_30 = F_88 ( F_89 ( V_140 ) ) ;
switch ( V_44 & V_152 ) {
case V_153 :
V_30 -> V_28 = V_121 ;
break;
case V_154 :
V_30 -> V_28 = V_123 ;
break;
case V_155 :
V_30 -> V_28 = V_125 ;
break;
case V_156 :
V_30 -> V_28 = V_126 ;
break;
default:
V_30 -> V_28 = V_22 ;
break;
}
V_15 = F_25 ( V_30 ) ;
if ( ! V_15 )
return - V_157 ;
V_42 = F_77 ( V_140 ) ;
V_42 -> V_44 = V_44 ;
return F_67 ( V_15 , & V_140 -> V_145 ) ;
}
static int F_90 ( struct V_158 * V_137 , const V_151 * V_53 ,
unsigned int V_54 )
{
struct V_29 * V_30 = F_88 ( V_137 ) ;
if ( V_54 != V_56 &&
V_54 != V_58 &&
V_54 != V_159 ) {
F_91 ( V_137 , V_160 ) ;
return - V_74 ;
}
memcpy ( V_30 -> V_53 , V_53 , V_54 ) ;
V_30 -> V_54 = V_54 ;
return 0 ;
}
static int F_92 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_161 | V_45 ) ;
}
static int F_93 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_161 ) ;
}
static int F_94 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_162 | V_45 ) ;
}
static int F_95 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_162 ) ;
}
static int F_96 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_163 | V_45 ) ;
}
static int F_97 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_163 ) ;
}
static int F_98 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_164 | V_45 ) ;
}
static int F_99 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_164 ) ;
}
static int F_100 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_156 | V_45 ) ;
}
static int F_101 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_156 ) ;
}
static int F_102 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_155 | V_45 ) ;
}
static int F_103 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_155 ) ;
}
static int F_104 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_154 | V_45 ) ;
}
static int F_105 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_154 ) ;
}
static int F_106 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_153 | V_45 ) ;
}
static int F_107 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_153 ) ;
}
static int F_108 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_165 | V_45 ) ;
}
static int F_109 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_165 ) ;
}
static int F_110 ( struct V_166 * V_137 )
{
struct V_167 * V_30 = F_73 ( V_137 ) ;
V_137 -> V_168 . V_169 = sizeof( struct V_41 ) ;
V_30 -> V_145 . V_138 = F_75 ;
return 0 ;
}
static int F_111 ( struct V_166 * V_137 )
{
struct V_167 * V_30 = F_73 ( V_137 ) ;
V_137 -> V_168 . V_169 = sizeof( struct V_41 ) ;
V_30 -> V_145 . V_138 = F_86 ;
return 0 ;
}
static void F_112 ( struct V_166 * V_137 )
{
}
static inline struct V_170 *
F_113 ( struct V_29 * V_30 )
{
return F_79 ( V_30 , struct V_170 , V_145 ) ;
}
static int F_114 ( struct V_14 * V_15 ,
const T_1 * V_69 , T_2 V_70 ,
const T_1 * V_171 , T_1 * V_172 ,
T_3 V_23 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
V_15 -> V_69 = ( T_1 * ) V_69 ;
V_15 -> V_70 = V_70 ;
V_30 -> V_171 = V_171 ;
V_30 -> V_172 = V_172 ;
V_30 -> V_173 = V_23 ;
F_42 ( V_15 , false , NULL ) ;
return F_22 ( V_15 , V_174 ) ;
}
static int V_174 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
F_15 ( V_15 , V_10 , V_15 -> V_73 ) ;
F_15 ( V_15 , V_11 , 0 ) ;
if ( V_30 -> V_171 )
F_21 ( V_15 , F_6 ( 0 ) , V_30 -> V_171 ) ;
return F_115 ( V_15 ) ;
}
static int F_115 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
T_1 V_24 ;
while ( V_15 -> V_70 > 0 ) {
F_21 ( V_15 , F_3 ( 0 ) , V_15 -> V_69 ) ;
V_15 -> V_69 += 4 ;
V_15 -> V_70 -= V_22 ;
V_24 = F_11 ( V_15 , V_6 ) ;
if ( ! ( V_24 & V_25 ) ) {
V_15 -> V_23 = F_115 ;
F_15 ( V_15 , V_8 , V_25 ) ;
return - V_26 ;
}
}
F_19 ( V_15 , F_6 ( 0 ) , V_30 -> V_172 ) ;
return V_30 -> V_173 ( V_15 ) ;
}
static int F_116 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
struct V_41 * V_42 = F_119 ( V_140 ) ;
T_2 V_177 = F_120 ( V_137 ) ;
T_2 V_70 , V_79 ;
const void * V_52 = V_140 -> V_52 ;
V_151 * V_69 = V_15 -> V_72 ;
int V_34 ;
F_35 ( V_15 , V_42 ) ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
if ( F_121 ( V_177 == 12 ) ) {
memcpy ( V_30 -> j0 , V_52 , V_177 ) ;
V_30 -> j0 [ 3 ] = F_84 ( 1 ) ;
return F_122 ( V_15 ) ;
}
V_79 = F_24 ( V_177 , V_22 ) ;
V_70 = V_177 + V_79 + V_22 ;
if ( V_70 > V_15 -> V_88 )
return F_37 ( V_15 , - V_74 ) ;
memcpy ( V_69 , V_52 , V_177 ) ;
memset ( V_69 + V_177 , 0 , V_79 + sizeof( V_178 ) ) ;
( ( V_178 * ) ( V_69 + V_70 ) ) [ - 1 ] = F_123 ( V_177 * 8 ) ;
return F_114 ( V_15 , ( const T_1 * ) V_69 , V_70 ,
NULL , V_30 -> j0 , F_122 ) ;
}
static int F_122 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
bool V_179 = F_36 ( V_15 ) ;
T_1 V_180 ;
V_180 = F_124 ( V_137 ) ;
V_30 -> V_181 = V_140 -> V_182 - ( V_179 ? 0 : V_180 ) ;
if ( F_121 ( V_140 -> V_183 != 0 || V_30 -> V_181 != 0 ) )
V_15 -> V_18 |= V_184 ;
F_42 ( V_15 , false , NULL ) ;
return F_22 ( V_15 , V_185 ) ;
}
static int V_185 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
T_1 V_186 , * j0 = V_30 -> j0 ;
T_2 V_79 ;
V_186 = j0 [ 3 ] ;
j0 [ 3 ] = F_84 ( F_82 ( j0 [ 3 ] ) + 1 ) ;
F_21 ( V_15 , F_5 ( 0 ) , j0 ) ;
j0 [ 3 ] = V_186 ;
F_15 ( V_15 , V_10 , V_140 -> V_183 ) ;
F_15 ( V_15 , V_11 , V_30 -> V_181 ) ;
if ( F_23 ( V_140 -> V_183 == 0 ) ) {
V_15 -> V_70 = 0 ;
return F_125 ( V_15 ) ;
}
V_79 = F_24 ( V_140 -> V_183 , V_22 ) ;
if ( F_23 ( V_140 -> V_183 + V_79 > V_15 -> V_88 ) )
return F_37 ( V_15 , - V_74 ) ;
F_47 ( V_140 -> V_77 , F_45 ( V_140 -> V_77 ) , V_15 -> V_72 , V_140 -> V_183 ) ;
V_15 -> V_69 = ( T_1 * ) V_15 -> V_72 ;
V_15 -> V_70 = V_140 -> V_183 + V_79 ;
return F_125 ( V_15 ) ;
}
static int F_125 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
bool V_51 = ( V_30 -> V_181 >= V_142 ) ;
struct V_76 * V_77 , * V_78 ;
T_1 V_24 , V_187 ;
while ( V_15 -> V_70 > 0 ) {
F_21 ( V_15 , F_3 ( 0 ) , V_15 -> V_69 ) ;
V_15 -> V_69 += 4 ;
V_15 -> V_70 -= V_22 ;
V_24 = F_11 ( V_15 , V_6 ) ;
if ( ! ( V_24 & V_25 ) ) {
V_15 -> V_23 = F_125 ;
F_15 ( V_15 , V_8 , V_25 ) ;
return - V_26 ;
}
}
if ( F_23 ( V_30 -> V_181 == 0 ) )
return F_126 ( V_15 ) ;
V_77 = F_83 ( V_30 -> V_77 , V_140 -> V_77 , V_140 -> V_183 ) ;
V_78 = ( ( V_140 -> V_77 == V_140 -> V_78 ) ? V_77 :
F_83 ( V_30 -> V_78 , V_140 -> V_78 , V_140 -> V_183 ) ) ;
if ( V_51 ) {
V_187 = F_11 ( V_15 , V_5 ) ;
V_187 &= ~ ( V_188 | V_65 ) ;
V_187 |= V_62 ;
if ( V_15 -> V_63 . V_64 )
V_187 |= V_65 ;
F_15 ( V_15 , V_5 , V_187 ) ;
return F_65 ( V_15 , V_77 , V_78 , V_30 -> V_181 ,
F_126 ) ;
}
return F_46 ( V_15 , V_77 , V_78 , V_30 -> V_181 ,
F_126 ) ;
}
static int F_126 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
V_178 * V_69 = V_15 -> V_72 ;
if ( F_121 ( V_15 -> V_18 & V_184 ) ) {
if ( ! ( F_11 ( V_15 , V_6 ) & V_189 ) ) {
V_15 -> V_23 = F_126 ;
F_15 ( V_15 , V_8 , V_189 ) ;
return - V_26 ;
}
return F_127 ( V_15 ) ;
}
F_19 ( V_15 , F_6 ( 0 ) , V_30 -> V_190 ) ;
V_69 [ 0 ] = F_123 ( V_140 -> V_183 * 8 ) ;
V_69 [ 1 ] = F_123 ( V_30 -> V_181 * 8 ) ;
return F_114 ( V_15 , ( const T_1 * ) V_69 , V_22 ,
V_30 -> V_190 , V_30 -> V_190 , V_191 ) ;
}
static int V_191 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
unsigned long V_18 ;
V_18 = V_15 -> V_18 ;
V_15 -> V_18 &= ~ ( V_152 | V_184 ) ;
V_15 -> V_18 |= V_165 ;
F_42 ( V_15 , false , V_30 -> j0 ) ;
V_15 -> V_18 = V_18 ;
F_21 ( V_15 , F_3 ( 0 ) , V_30 -> V_190 ) ;
return F_22 ( V_15 , F_127 ) ;
}
static int F_127 ( struct V_14 * V_15 )
{
struct V_170 * V_30 = F_113 ( V_15 -> V_30 ) ;
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
bool V_179 = F_36 ( V_15 ) ;
T_1 V_1 , V_180 , V_192 [ 4 ] , * V_193 = V_30 -> V_194 ;
int V_34 ;
if ( F_121 ( V_15 -> V_18 & V_184 ) )
F_19 ( V_15 , F_7 ( 0 ) , V_30 -> V_194 ) ;
else
F_19 ( V_15 , F_4 ( 0 ) , V_30 -> V_194 ) ;
V_1 = V_140 -> V_183 + V_30 -> V_181 ;
V_180 = F_124 ( V_137 ) ;
if ( V_179 ) {
F_128 ( V_193 , V_140 -> V_78 , V_1 , V_180 , 1 ) ;
V_34 = 0 ;
} else {
F_128 ( V_192 , V_140 -> V_77 , V_1 , V_180 , 0 ) ;
V_34 = F_129 ( V_192 , V_193 , V_180 ) ? - V_195 : 0 ;
}
return F_37 ( V_15 , V_34 ) ;
}
static int F_130 ( struct V_175 * V_140 ,
unsigned long V_44 )
{
struct V_29 * V_30 ;
struct V_41 * V_42 ;
struct V_14 * V_15 ;
V_30 = F_131 ( F_118 ( V_140 ) ) ;
V_30 -> V_28 = V_22 ;
V_15 = F_25 ( V_30 ) ;
if ( ! V_15 )
return - V_157 ;
V_42 = F_119 ( V_140 ) ;
V_42 -> V_44 = V_196 | V_44 ;
return F_67 ( V_15 , & V_140 -> V_145 ) ;
}
static int F_132 ( struct V_176 * V_137 , const V_151 * V_53 ,
unsigned int V_54 )
{
struct V_29 * V_30 = F_131 ( V_137 ) ;
if ( V_54 != V_159 &&
V_54 != V_58 &&
V_54 != V_56 ) {
F_133 ( V_137 , V_160 ) ;
return - V_74 ;
}
memcpy ( V_30 -> V_53 , V_53 , V_54 ) ;
V_30 -> V_54 = V_54 ;
return 0 ;
}
static int F_134 ( struct V_176 * V_137 ,
unsigned int V_180 )
{
switch ( V_180 ) {
case 4 :
case 8 :
case 12 :
case 13 :
case 14 :
case 15 :
case 16 :
break;
default:
return - V_74 ;
}
return 0 ;
}
static int F_135 ( struct V_175 * V_140 )
{
return F_130 ( V_140 , V_45 ) ;
}
static int F_136 ( struct V_175 * V_140 )
{
return F_130 ( V_140 , 0 ) ;
}
static int F_137 ( struct V_176 * V_137 )
{
struct V_170 * V_30 = F_131 ( V_137 ) ;
F_138 ( V_137 , sizeof( struct V_41 ) ) ;
V_30 -> V_145 . V_138 = F_116 ;
return 0 ;
}
static void F_139 ( struct V_176 * V_137 )
{
}
static inline struct V_197 *
F_140 ( struct V_29 * V_30 )
{
return F_79 ( V_30 , struct V_197 , V_145 ) ;
}
static int F_141 ( struct V_14 * V_15 )
{
struct V_197 * V_30 = F_140 ( V_15 -> V_30 ) ;
struct V_139 * V_140 = F_76 ( V_15 -> V_48 ) ;
struct V_41 * V_42 = F_77 ( V_140 ) ;
unsigned long V_18 ;
int V_34 ;
F_35 ( V_15 , V_42 ) ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
V_18 = V_15 -> V_18 ;
V_15 -> V_18 &= ~ V_61 ;
V_15 -> V_18 |= ( V_161 | V_45 ) ;
F_41 ( V_15 , false , NULL ,
V_30 -> V_198 , V_30 -> V_145 . V_54 ) ;
V_15 -> V_18 = V_18 ;
F_21 ( V_15 , F_3 ( 0 ) , V_140 -> V_143 ) ;
return F_22 ( V_15 , V_199 ) ;
}
static int V_199 ( struct V_14 * V_15 )
{
struct V_139 * V_140 = F_76 ( V_15 -> V_48 ) ;
bool V_51 = ( V_140 -> V_141 >= V_142 ) ;
T_1 V_200 [ V_22 / sizeof( T_1 ) ] ;
static const T_1 V_201 [ V_22 / sizeof( T_1 ) ] = { F_142 ( 1 ) , } ;
V_151 * V_202 = ( V_151 * ) V_200 ;
int V_203 ;
F_19 ( V_15 , F_4 ( 0 ) , V_200 ) ;
for ( V_203 = 0 ; V_203 < V_22 / 2 ; ++ V_203 ) {
V_151 V_2 = V_202 [ V_22 - 1 - V_203 ] ;
V_202 [ V_22 - 1 - V_203 ] = V_202 [ V_203 ] ;
V_202 [ V_203 ] = V_2 ;
}
F_42 ( V_15 , V_51 , NULL ) ;
F_21 ( V_15 , F_9 ( 0 ) , V_200 ) ;
F_21 ( V_15 , F_10 ( 0 ) , V_201 ) ;
if ( V_51 )
return F_65 ( V_15 , V_140 -> V_77 , V_140 -> V_78 , V_140 -> V_141 ,
F_74 ) ;
return F_46 ( V_15 , V_140 -> V_77 , V_140 -> V_78 , V_140 -> V_141 ,
F_74 ) ;
}
static int F_143 ( struct V_158 * V_137 , const V_151 * V_53 ,
unsigned int V_54 )
{
struct V_197 * V_30 = F_88 ( V_137 ) ;
int V_34 ;
V_34 = F_144 ( F_145 ( V_137 ) , V_53 , V_54 ) ;
if ( V_34 )
return V_34 ;
memcpy ( V_30 -> V_145 . V_53 , V_53 , V_54 / 2 ) ;
memcpy ( V_30 -> V_198 , V_53 + V_54 / 2 , V_54 / 2 ) ;
V_30 -> V_145 . V_54 = V_54 / 2 ;
return 0 ;
}
static int F_146 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_204 | V_45 ) ;
}
static int F_147 ( struct V_139 * V_140 )
{
return F_87 ( V_140 , V_204 ) ;
}
static int F_148 ( struct V_166 * V_137 )
{
struct V_197 * V_30 = F_73 ( V_137 ) ;
V_137 -> V_168 . V_169 = sizeof( struct V_41 ) ;
V_30 -> V_145 . V_138 = F_141 ;
return 0 ;
}
static void F_39 ( struct V_14 * V_15 , int V_34 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
if ( V_34 && ( V_15 -> V_18 & V_206 ) )
F_149 ( & V_42 -> V_207 ) ;
V_15 -> V_18 &= ~ V_206 ;
}
static int F_150 ( struct V_14 * V_15 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
struct V_208 * V_30 = F_131 ( V_137 ) ;
int V_34 ;
F_35 ( V_15 , & V_42 -> V_145 ) ;
V_34 = F_29 ( V_15 ) ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
return F_151 ( & V_42 -> V_207 , V_30 -> V_209 ,
V_210 , V_15 ) ;
}
static int V_210 ( struct V_14 * V_15 , int V_34 ,
bool V_47 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
if ( V_47 )
V_15 -> V_47 = true ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
V_15 -> V_18 |= V_206 ;
return F_152 ( & V_42 -> V_207 ,
V_140 -> V_77 , V_140 -> V_183 ,
V_42 -> V_181 ,
V_211 , V_15 ) ;
}
static int V_211 ( struct V_14 * V_15 , int V_34 ,
bool V_47 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
bool V_179 = F_36 ( V_15 ) ;
struct V_76 * V_77 , * V_78 ;
T_1 V_52 [ V_22 / sizeof( T_1 ) ] ;
T_1 V_212 ;
if ( V_47 )
V_15 -> V_47 = true ;
if ( V_34 )
return F_37 ( V_15 , V_34 ) ;
V_77 = F_83 ( V_42 -> V_77 , V_140 -> V_77 , V_140 -> V_183 ) ;
V_78 = V_77 ;
if ( V_140 -> V_77 != V_140 -> V_78 )
V_78 = F_83 ( V_42 -> V_78 , V_140 -> V_78 , V_140 -> V_183 ) ;
memcpy ( V_52 , V_140 -> V_52 , sizeof( V_52 ) ) ;
F_42 ( V_15 , true , V_52 ) ;
V_212 = V_213 ;
if ( ! V_179 )
V_212 |= V_214 ;
F_15 ( V_15 , V_13 , V_212 ) ;
return F_65 ( V_15 , V_77 , V_78 , V_42 -> V_181 ,
V_215 ) ;
}
static int V_215 ( struct V_14 * V_15 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
V_15 -> V_18 &= ~ V_206 ;
return F_153 ( & V_42 -> V_207 ,
V_42 -> V_216 , sizeof( V_42 -> V_216 ) ,
V_217 , V_15 ) ;
}
static int V_217 ( struct V_14 * V_15 , int V_34 ,
bool V_47 )
{
struct V_175 * V_140 = F_117 ( V_15 -> V_48 ) ;
struct V_205 * V_42 = F_119 ( V_140 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
bool V_179 = F_36 ( V_15 ) ;
T_1 V_218 [ V_219 / sizeof( T_1 ) ] , * V_220 = V_42 -> V_216 ;
T_1 V_221 , V_180 ;
if ( V_47 )
V_15 -> V_47 = true ;
if ( V_34 )
goto V_49;
V_221 = V_140 -> V_183 + V_42 -> V_181 ;
V_180 = F_124 ( V_137 ) ;
if ( V_179 ) {
F_128 ( V_220 , V_140 -> V_78 , V_221 , V_180 , 1 ) ;
} else {
F_128 ( V_218 , V_140 -> V_77 , V_221 , V_180 , 0 ) ;
if ( F_129 ( V_218 , V_220 , V_180 ) )
V_34 = - V_195 ;
}
V_49:
return F_37 ( V_15 , V_34 ) ;
}
static int F_154 ( struct V_176 * V_137 , const V_151 * V_53 ,
unsigned int V_54 )
{
struct V_208 * V_30 = F_131 ( V_137 ) ;
struct V_222 V_223 ;
T_1 V_18 ;
int V_34 ;
if ( F_155 ( & V_223 , V_53 , V_54 ) != 0 )
goto V_224;
if ( V_223 . V_225 > sizeof( V_30 -> V_145 . V_53 ) )
goto V_224;
V_18 = F_156 ( V_137 ) ;
V_34 = F_157 ( V_30 -> V_209 ,
V_223 . V_226 , V_223 . V_227 ,
& V_18 ) ;
F_133 ( V_137 , V_18 & V_228 ) ;
if ( V_34 ) {
F_158 ( & V_223 , sizeof( V_223 ) ) ;
return V_34 ;
}
V_30 -> V_145 . V_54 = V_223 . V_225 ;
memcpy ( V_30 -> V_145 . V_53 , V_223 . V_229 , V_223 . V_225 ) ;
F_158 ( & V_223 , sizeof( V_223 ) ) ;
return 0 ;
V_224:
F_133 ( V_137 , V_160 ) ;
F_158 ( & V_53 , sizeof( V_223 ) ) ;
return - V_74 ;
}
static int F_159 ( struct V_176 * V_137 ,
unsigned long V_230 )
{
struct V_208 * V_30 = F_131 ( V_137 ) ;
unsigned int V_231 = F_160 () ;
V_30 -> V_209 = F_161 ( V_230 ) ;
if ( F_162 ( V_30 -> V_209 ) )
return F_163 ( V_30 -> V_209 ) ;
F_138 ( V_137 , ( sizeof( struct V_205 ) +
V_231 ) ) ;
V_30 -> V_145 . V_138 = F_150 ;
return 0 ;
}
static int F_164 ( struct V_176 * V_137 )
{
return F_159 ( V_137 , V_232 ) ;
}
static int F_165 ( struct V_176 * V_137 )
{
return F_159 ( V_137 , V_233 ) ;
}
static int F_166 ( struct V_176 * V_137 )
{
return F_159 ( V_137 , V_234 ) ;
}
static int F_167 ( struct V_176 * V_137 )
{
return F_159 ( V_137 , V_235 ) ;
}
static int F_168 ( struct V_176 * V_137 )
{
return F_159 ( V_137 , V_236 ) ;
}
static void F_169 ( struct V_176 * V_137 )
{
struct V_208 * V_30 = F_131 ( V_137 ) ;
F_170 ( V_30 -> V_209 ) ;
}
static int F_171 ( struct V_175 * V_140 ,
unsigned long V_44 )
{
struct V_205 * V_42 = F_119 ( V_140 ) ;
struct V_176 * V_137 = F_118 ( V_140 ) ;
struct V_29 * V_30 = F_131 ( V_137 ) ;
T_1 V_180 = F_124 ( V_137 ) ;
bool V_179 = ( V_44 & V_45 ) ;
struct V_14 * V_15 ;
if ( ! V_179 && V_140 -> V_182 < V_180 )
return - V_74 ;
V_42 -> V_181 = V_140 -> V_182 - ( V_179 ? 0 : V_180 ) ;
if ( ! V_42 -> V_181 && ! V_140 -> V_183 )
return - V_74 ;
V_42 -> V_145 . V_44 = V_44 ;
V_30 -> V_28 = V_22 ;
V_15 = F_25 ( V_30 ) ;
if ( ! V_15 )
return - V_157 ;
return F_67 ( V_15 , & V_140 -> V_145 ) ;
}
static int F_172 ( struct V_175 * V_140 )
{
return F_171 ( V_140 , V_162 | V_45 ) ;
}
static int F_173 ( struct V_175 * V_140 )
{
return F_171 ( V_140 , V_162 ) ;
}
static int F_174 ( struct V_14 * V_15 )
{
V_15 -> V_72 = ( void * ) F_175 ( V_237 , V_238 ) ;
V_15 -> V_88 = V_239 ;
V_15 -> V_88 &= ~ ( V_22 - 1 ) ;
if ( ! V_15 -> V_72 ) {
F_176 ( V_15 -> V_20 , L_24 ) ;
return - V_89 ;
}
return 0 ;
}
static void F_177 ( struct V_14 * V_15 )
{
F_178 ( ( unsigned long ) V_15 -> V_72 ) ;
}
static bool F_179 ( struct V_240 * V_117 , void * V_241 )
{
struct V_242 * V_243 = V_241 ;
if ( V_243 && V_243 -> V_244 == V_117 -> V_245 -> V_20 ) {
V_117 -> V_246 = V_243 ;
return true ;
} else {
return false ;
}
}
static int F_180 ( struct V_14 * V_15 ,
struct V_247 * V_248 )
{
struct V_242 * V_241 ;
int V_34 = - V_89 ;
T_6 V_249 ;
F_181 ( V_249 ) ;
F_182 ( V_250 , V_249 ) ;
V_241 = & V_248 -> V_251 -> V_252 ;
V_15 -> V_77 . V_117 = F_183 ( V_249 , F_179 ,
V_241 , V_15 -> V_20 , L_25 ) ;
if ( ! V_15 -> V_77 . V_117 )
goto V_253;
V_241 = & V_248 -> V_251 -> V_254 ;
V_15 -> V_78 . V_117 = F_183 ( V_249 , F_179 ,
V_241 , V_15 -> V_20 , L_26 ) ;
if ( ! V_15 -> V_78 . V_117 )
goto V_255;
return 0 ;
V_255:
F_184 ( V_15 -> V_77 . V_117 ) ;
V_253:
F_185 ( V_15 -> V_20 , L_27 ) ;
return V_34 ;
}
static void F_186 ( struct V_14 * V_15 )
{
F_184 ( V_15 -> V_78 . V_117 ) ;
F_184 ( V_15 -> V_77 . V_117 ) ;
}
static void F_187 ( unsigned long V_69 )
{
struct V_14 * V_15 = (struct V_14 * ) V_69 ;
F_67 ( V_15 , NULL ) ;
}
static void F_188 ( unsigned long V_69 )
{
struct V_14 * V_15 = (struct V_14 * ) V_69 ;
V_15 -> V_47 = true ;
( void ) V_15 -> V_23 ( V_15 ) ;
}
static T_7 F_189 ( int V_256 , void * V_257 )
{
struct V_14 * V_31 = V_257 ;
T_1 V_258 ;
V_258 = F_11 ( V_31 , V_6 ) ;
if ( V_258 & F_11 ( V_31 , V_7 ) ) {
F_15 ( V_31 , V_9 , V_258 ) ;
if ( V_46 & V_31 -> V_18 )
F_40 ( & V_31 -> V_259 ) ;
else
F_185 ( V_31 -> V_20 , L_28 ) ;
return V_260 ;
}
return V_261 ;
}
static void F_190 ( struct V_14 * V_15 )
{
int V_203 ;
#ifdef F_38
if ( V_15 -> V_63 . V_262 )
for ( V_203 = 0 ; V_203 < F_191 ( V_263 ) ; V_203 ++ )
F_192 ( & V_263 [ V_203 ] ) ;
#endif
if ( V_15 -> V_63 . V_264 )
F_193 ( & V_265 ) ;
if ( V_15 -> V_63 . V_266 )
F_192 ( & V_267 ) ;
if ( V_15 -> V_63 . V_268 )
F_193 ( & V_269 ) ;
for ( V_203 = 0 ; V_203 < F_191 ( V_270 ) ; V_203 ++ )
F_193 ( & V_270 [ V_203 ] ) ;
}
static int F_194 ( struct V_14 * V_15 )
{
int V_34 , V_203 , V_271 ;
for ( V_203 = 0 ; V_203 < F_191 ( V_270 ) ; V_203 ++ ) {
V_34 = F_195 ( & V_270 [ V_203 ] ) ;
if ( V_34 )
goto V_272;
}
if ( V_15 -> V_63 . V_268 ) {
V_34 = F_195 ( & V_269 ) ;
if ( V_34 )
goto V_273;
}
if ( V_15 -> V_63 . V_266 ) {
V_34 = F_196 ( & V_267 ) ;
if ( V_34 )
goto V_274;
}
if ( V_15 -> V_63 . V_264 ) {
V_34 = F_195 ( & V_265 ) ;
if ( V_34 )
goto V_275;
}
#ifdef F_38
if ( V_15 -> V_63 . V_262 ) {
for ( V_203 = 0 ; V_203 < F_191 ( V_263 ) ; V_203 ++ ) {
V_34 = F_196 ( & V_263 [ V_203 ] ) ;
if ( V_34 )
goto V_276;
}
}
#endif
return 0 ;
#ifdef F_38
V_276:
for ( V_271 = 0 ; V_271 < V_203 ; V_271 ++ )
F_192 ( & V_263 [ V_271 ] ) ;
F_193 ( & V_265 ) ;
#endif
V_275:
F_192 ( & V_267 ) ;
V_274:
F_193 ( & V_269 ) ;
V_273:
V_203 = F_191 ( V_270 ) ;
V_272:
for ( V_271 = 0 ; V_271 < V_203 ; V_271 ++ )
F_193 ( & V_270 [ V_271 ] ) ;
return V_34 ;
}
static void F_197 ( struct V_14 * V_15 )
{
V_15 -> V_63 . V_64 = 0 ;
V_15 -> V_63 . V_268 = 0 ;
V_15 -> V_63 . V_149 = 0 ;
V_15 -> V_63 . V_266 = 0 ;
V_15 -> V_63 . V_264 = 0 ;
V_15 -> V_63 . V_262 = 0 ;
V_15 -> V_63 . V_128 = 1 ;
switch ( V_15 -> V_40 & 0xff0 ) {
case 0x500 :
V_15 -> V_63 . V_64 = 1 ;
V_15 -> V_63 . V_268 = 1 ;
V_15 -> V_63 . V_149 = 1 ;
V_15 -> V_63 . V_266 = 1 ;
V_15 -> V_63 . V_264 = 1 ;
V_15 -> V_63 . V_262 = 1 ;
V_15 -> V_63 . V_128 = 4 ;
break;
case 0x200 :
V_15 -> V_63 . V_64 = 1 ;
V_15 -> V_63 . V_268 = 1 ;
V_15 -> V_63 . V_149 = 1 ;
V_15 -> V_63 . V_266 = 1 ;
V_15 -> V_63 . V_128 = 4 ;
break;
case 0x130 :
V_15 -> V_63 . V_64 = 1 ;
V_15 -> V_63 . V_268 = 1 ;
V_15 -> V_63 . V_128 = 4 ;
break;
case 0x120 :
break;
default:
F_185 ( V_15 -> V_20 ,
L_29 ) ;
break;
}
}
static struct V_247 * F_198 ( struct V_277 * V_278 )
{
struct V_279 * V_280 = V_278 -> V_20 . V_281 ;
struct V_247 * V_248 ;
if ( ! V_280 ) {
F_176 ( & V_278 -> V_20 , L_30 ) ;
return F_199 ( - V_74 ) ;
}
V_248 = F_200 ( & V_278 -> V_20 , sizeof( * V_248 ) , V_237 ) ;
if ( ! V_248 ) {
F_176 ( & V_278 -> V_20 , L_31 ) ;
return F_199 ( - V_89 ) ;
}
V_248 -> V_251 = F_200 ( & V_278 -> V_20 ,
sizeof( * ( V_248 -> V_251 ) ) ,
V_237 ) ;
if ( ! V_248 -> V_251 ) {
F_176 ( & V_278 -> V_20 , L_32 ) ;
F_201 ( & V_278 -> V_20 , V_248 ) ;
return F_199 ( - V_89 ) ;
}
return V_248 ;
}
static inline struct V_247 * F_198 ( struct V_277 * V_278 )
{
return F_199 ( - V_74 ) ;
}
static int F_202 ( struct V_277 * V_278 )
{
struct V_14 * V_31 ;
struct V_247 * V_248 ;
struct V_245 * V_20 = & V_278 -> V_20 ;
struct V_282 * V_283 ;
int V_34 ;
V_248 = V_278 -> V_20 . V_284 ;
if ( ! V_248 ) {
V_248 = F_198 ( V_278 ) ;
if ( F_162 ( V_248 ) ) {
V_34 = F_163 ( V_248 ) ;
goto V_285;
}
}
if ( ! V_248 -> V_251 ) {
V_34 = - V_286 ;
goto V_285;
}
V_31 = F_200 ( & V_278 -> V_20 , sizeof( * V_31 ) , V_237 ) ;
if ( V_31 == NULL ) {
F_176 ( V_20 , L_33 ) ;
V_34 = - V_89 ;
goto V_285;
}
V_31 -> V_20 = V_20 ;
F_203 ( V_278 , V_31 ) ;
F_204 ( & V_31 -> V_287 ) ;
F_205 ( & V_31 -> V_33 ) ;
F_206 ( & V_31 -> V_259 , F_188 ,
( unsigned long ) V_31 ) ;
F_206 ( & V_31 -> V_50 , F_187 ,
( unsigned long ) V_31 ) ;
F_207 ( & V_31 -> V_136 , V_288 ) ;
V_31 -> V_256 = - 1 ;
V_283 = F_208 ( V_278 , V_289 , 0 ) ;
if ( ! V_283 ) {
F_176 ( V_20 , L_34 ) ;
V_34 = - V_157 ;
goto V_290;
}
V_31 -> V_113 = V_283 -> V_138 ;
V_31 -> V_256 = F_209 ( V_278 , 0 ) ;
if ( V_31 -> V_256 < 0 ) {
F_176 ( V_20 , L_35 ) ;
V_34 = V_31 -> V_256 ;
goto V_290;
}
V_34 = F_210 ( & V_278 -> V_20 , V_31 -> V_256 , F_189 ,
V_291 , L_36 , V_31 ) ;
if ( V_34 ) {
F_176 ( V_20 , L_37 ) ;
goto V_290;
}
V_31 -> V_35 = F_211 ( & V_278 -> V_20 , L_38 ) ;
if ( F_162 ( V_31 -> V_35 ) ) {
F_176 ( V_20 , L_39 ) ;
V_34 = F_163 ( V_31 -> V_35 ) ;
goto V_290;
}
V_31 -> V_17 = F_212 ( & V_278 -> V_20 , V_283 ) ;
if ( F_162 ( V_31 -> V_17 ) ) {
F_176 ( V_20 , L_40 ) ;
V_34 = F_163 ( V_31 -> V_17 ) ;
goto V_290;
}
V_34 = F_213 ( V_31 -> V_35 ) ;
if ( V_34 )
goto V_290;
V_34 = F_32 ( V_31 ) ;
if ( V_34 )
goto V_292;
F_197 ( V_31 ) ;
#ifdef F_38
if ( V_31 -> V_63 . V_262 && ! F_214 () ) {
V_34 = - V_293 ;
goto V_292;
}
#endif
V_34 = F_174 ( V_31 ) ;
if ( V_34 )
goto V_294;
V_34 = F_180 ( V_31 , V_248 ) ;
if ( V_34 )
goto V_295;
F_215 ( & V_32 . V_33 ) ;
F_216 ( & V_31 -> V_287 , & V_32 . V_296 ) ;
F_217 ( & V_32 . V_33 ) ;
V_34 = F_194 ( V_31 ) ;
if ( V_34 )
goto V_297;
F_33 ( V_20 , L_41 ,
F_218 ( V_31 -> V_77 . V_117 ) ,
F_218 ( V_31 -> V_78 . V_117 ) ) ;
return 0 ;
V_297:
F_215 ( & V_32 . V_33 ) ;
F_219 ( & V_31 -> V_287 ) ;
F_217 ( & V_32 . V_33 ) ;
F_186 ( V_31 ) ;
V_295:
F_177 ( V_31 ) ;
V_294:
V_292:
F_220 ( V_31 -> V_35 ) ;
V_290:
F_221 ( & V_31 -> V_259 ) ;
F_221 ( & V_31 -> V_50 ) ;
V_285:
if ( V_34 != - V_293 )
F_176 ( V_20 , L_42 ) ;
return V_34 ;
}
static int F_222 ( struct V_277 * V_278 )
{
struct V_14 * V_31 ;
V_31 = F_223 ( V_278 ) ;
if ( ! V_31 )
return - V_157 ;
F_215 ( & V_32 . V_33 ) ;
F_219 ( & V_31 -> V_287 ) ;
F_217 ( & V_32 . V_33 ) ;
F_190 ( V_31 ) ;
F_221 ( & V_31 -> V_259 ) ;
F_221 ( & V_31 -> V_50 ) ;
F_186 ( V_31 ) ;
F_177 ( V_31 ) ;
F_220 ( V_31 -> V_35 ) ;
return 0 ;
}
