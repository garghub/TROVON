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
default:
snprintf ( V_2 , V_3 , L_17 , V_1 ) ;
break;
}
return V_2 ;
}
static inline T_1 F_9 ( struct V_13 * V_14 , T_1 V_1 )
{
T_1 V_15 = F_10 ( V_14 -> V_16 + V_1 ) ;
#ifdef F_11
if ( V_14 -> V_17 & V_18 ) {
char V_2 [ 16 ] ;
F_12 ( V_14 -> V_19 , L_18 , V_15 ,
F_1 ( V_1 , V_2 , sizeof( V_2 ) ) ) ;
}
#endif
return V_15 ;
}
static inline void F_13 ( struct V_13 * V_14 ,
T_1 V_1 , T_1 V_15 )
{
#ifdef F_11
if ( V_14 -> V_17 & V_18 ) {
char V_2 [ 16 ] ;
F_12 ( V_14 -> V_19 , L_19 , V_15 ,
F_1 ( V_1 , V_2 ) ) ;
}
#endif
F_14 ( V_15 , V_14 -> V_16 + V_1 ) ;
}
static void F_15 ( struct V_13 * V_14 , T_1 V_1 ,
T_1 * V_15 , int V_20 )
{
for (; V_20 -- ; V_15 ++ , V_1 += 4 )
* V_15 = F_9 ( V_14 , V_1 ) ;
}
static void F_16 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_15 , int V_20 )
{
for (; V_20 -- ; V_15 ++ , V_1 += 4 )
F_13 ( V_14 , V_1 , * V_15 ) ;
}
static inline void F_17 ( struct V_13 * V_14 , T_1 V_1 ,
T_1 * V_15 )
{
F_15 ( V_14 , V_1 , V_15 , F_18 ( V_21 ) ) ;
}
static inline void F_19 ( struct V_13 * V_14 , T_1 V_1 ,
const T_1 * V_15 )
{
F_16 ( V_14 , V_1 , V_15 , F_18 ( V_21 ) ) ;
}
static inline int F_20 ( struct V_13 * V_14 ,
T_3 V_22 )
{
T_1 V_23 = F_9 ( V_14 , V_6 ) ;
if ( F_21 ( V_23 & V_24 ) )
return V_22 ( V_14 ) ;
V_14 -> V_22 = V_22 ;
F_13 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
static inline T_2 F_22 ( T_2 V_26 , T_2 V_27 )
{
V_26 &= V_27 - 1 ;
return V_26 ? V_27 - V_26 : 0 ;
}
static inline struct V_28 *
F_23 ( struct V_29 * V_30 )
{
return F_24 ( V_30 , struct V_28 , V_31 ) ;
}
static struct V_13 * F_25 ( struct V_32 * V_33 )
{
struct V_13 * V_34 = NULL ;
struct V_13 * V_2 ;
F_26 ( & V_35 . V_36 ) ;
if ( ! V_33 -> V_14 ) {
F_27 (tmp, &atmel_aes.dev_list, list) {
V_34 = V_2 ;
break;
}
V_33 -> V_14 = V_34 ;
} else {
V_34 = V_33 -> V_14 ;
}
F_28 ( & V_35 . V_36 ) ;
return V_34 ;
}
static int F_29 ( struct V_13 * V_14 )
{
int V_37 ;
V_37 = F_30 ( V_14 -> V_38 ) ;
if ( V_37 )
return V_37 ;
if ( ! ( V_14 -> V_17 & V_39 ) ) {
F_13 ( V_14 , V_4 , V_40 ) ;
F_13 ( V_14 , V_5 , 0xE << V_41 ) ;
V_14 -> V_17 |= V_39 ;
}
return 0 ;
}
static inline unsigned int F_31 ( struct V_13 * V_14 )
{
return F_9 ( V_14 , V_42 ) & 0x00000fff ;
}
static int F_32 ( struct V_13 * V_14 )
{
int V_37 ;
V_37 = F_29 ( V_14 ) ;
if ( V_37 )
return V_37 ;
V_14 -> V_43 = F_31 ( V_14 ) ;
F_33 ( V_14 -> V_19 , L_20 , V_14 -> V_43 ) ;
F_34 ( V_14 -> V_38 ) ;
return 0 ;
}
static inline void F_35 ( struct V_13 * V_14 ,
const struct V_44 * V_45 )
{
V_14 -> V_17 = ( V_14 -> V_17 & V_46 ) | V_45 -> V_47 ;
}
static inline bool F_36 ( const struct V_13 * V_14 )
{
return ( V_14 -> V_17 & V_48 ) ;
}
static inline int F_37 ( struct V_13 * V_14 , int V_37 )
{
F_34 ( V_14 -> V_38 ) ;
V_14 -> V_17 &= ~ V_49 ;
if ( V_14 -> V_50 )
V_14 -> V_51 -> V_52 ( V_14 -> V_51 , V_37 ) ;
F_38 ( & V_14 -> V_53 ) ;
return V_37 ;
}
static void F_39 ( struct V_13 * V_14 , bool V_54 ,
const T_1 * V_55 )
{
T_1 V_56 = 0 ;
if ( V_14 -> V_33 -> V_57 == V_58 )
V_56 |= V_59 ;
else if ( V_14 -> V_33 -> V_57 == V_60 )
V_56 |= V_61 ;
else
V_56 |= V_62 ;
V_56 |= V_14 -> V_17 & V_63 ;
if ( V_54 ) {
V_56 |= V_64 ;
if ( V_14 -> V_65 . V_66 )
V_56 |= V_67 ;
} else {
V_56 |= V_68 ;
}
F_13 ( V_14 , V_5 , V_56 ) ;
F_16 ( V_14 , F_2 ( 0 ) , V_14 -> V_33 -> V_69 ,
F_18 ( V_14 -> V_33 -> V_57 ) ) ;
if ( V_55 && ( V_56 & V_70 ) != V_71 )
F_19 ( V_14 , F_5 ( 0 ) , V_55 ) ;
}
static int F_40 ( struct V_13 * V_14 )
{
int V_37 = 0 ;
T_1 V_23 ;
for (; ; ) {
F_17 ( V_14 , F_4 ( 0 ) , V_14 -> V_72 ) ;
V_14 -> V_72 += 4 ;
V_14 -> V_73 -= V_21 ;
if ( V_14 -> V_73 < V_21 )
break;
F_19 ( V_14 , F_3 ( 0 ) , V_14 -> V_72 ) ;
V_23 = F_9 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_40 ;
F_13 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
if ( ! F_41 ( V_14 -> V_74 , F_42 ( V_14 -> V_74 ) ,
V_14 -> V_75 , V_14 -> V_76 ) )
V_37 = - V_77 ;
if ( V_37 )
return F_37 ( V_14 , V_37 ) ;
return V_14 -> V_78 ( V_14 ) ;
}
static int F_43 ( struct V_13 * V_14 ,
struct V_79 * V_80 ,
struct V_79 * V_81 ,
T_2 V_26 ,
T_3 V_22 )
{
T_2 V_82 = F_22 ( V_26 , V_21 ) ;
if ( F_21 ( V_26 == 0 ) )
return - V_77 ;
F_44 ( V_80 , F_42 ( V_80 ) , V_14 -> V_75 , V_26 ) ;
V_14 -> V_76 = V_26 ;
V_14 -> V_74 = V_81 ;
V_14 -> V_78 = V_22 ;
V_14 -> V_73 = V_26 + V_82 ;
V_14 -> V_72 = ( T_1 * ) V_14 -> V_75 ;
F_19 ( V_14 , F_3 ( 0 ) , V_14 -> V_72 ) ;
return F_20 ( V_14 , F_40 ) ;
}
static bool F_45 ( struct V_13 * V_14 ,
struct V_79 * V_83 ,
T_2 V_26 ,
struct V_84 * V_85 )
{
int V_86 ;
if ( ! F_46 ( V_26 , V_14 -> V_33 -> V_27 ) )
return false ;
for ( V_86 = 0 ; V_83 ; V_83 = F_47 ( V_83 ) , ++ V_86 ) {
if ( ! F_46 ( V_83 -> V_1 , sizeof( T_1 ) ) )
return false ;
if ( V_26 <= V_83 -> V_87 ) {
if ( ! F_46 ( V_26 , V_14 -> V_33 -> V_27 ) )
return false ;
V_85 -> V_86 = V_86 + 1 ;
V_85 -> V_88 = V_83 -> V_87 - V_26 ;
V_83 -> V_87 = V_26 ;
return true ;
}
if ( ! F_46 ( V_83 -> V_87 , V_14 -> V_33 -> V_27 ) )
return false ;
V_26 -= V_83 -> V_87 ;
}
return false ;
}
static inline void F_48 ( const struct V_84 * V_85 )
{
struct V_79 * V_83 = V_85 -> V_83 ;
int V_86 = V_85 -> V_86 ;
if ( ! V_85 -> V_88 )
return;
while ( -- V_86 > 0 && V_83 )
V_83 = F_47 ( V_83 ) ;
if ( ! V_83 )
return;
V_83 -> V_87 += V_85 -> V_88 ;
}
static int F_49 ( struct V_13 * V_14 ,
struct V_79 * V_80 ,
struct V_79 * V_81 ,
T_2 V_26 )
{
bool V_89 , V_90 ;
T_2 V_82 ;
V_14 -> V_76 = V_26 ;
V_14 -> V_80 . V_83 = V_80 ;
V_14 -> V_81 . V_83 = V_81 ;
V_14 -> V_74 = V_81 ;
V_89 = F_45 ( V_14 , V_80 , V_26 , & V_14 -> V_80 ) ;
if ( V_80 == V_81 )
V_90 = V_89 ;
else
V_90 = F_45 ( V_14 , V_81 , V_26 , & V_14 -> V_81 ) ;
if ( ! V_89 || ! V_90 ) {
V_82 = F_22 ( V_26 , V_14 -> V_33 -> V_27 ) ;
if ( V_14 -> V_91 < V_26 + V_82 )
return - V_92 ;
if ( ! V_89 ) {
F_44 ( V_80 , F_42 ( V_80 ) , V_14 -> V_75 , V_26 ) ;
V_14 -> V_80 . V_83 = & V_14 -> V_93 ;
V_14 -> V_80 . V_86 = 1 ;
V_14 -> V_80 . V_88 = 0 ;
}
if ( ! V_90 ) {
V_14 -> V_81 . V_83 = & V_14 -> V_93 ;
V_14 -> V_81 . V_86 = 1 ;
V_14 -> V_81 . V_88 = 0 ;
}
F_50 ( & V_14 -> V_93 , 1 ) ;
F_51 ( & V_14 -> V_93 , V_14 -> V_75 , V_26 + V_82 ) ;
}
if ( V_14 -> V_80 . V_83 == V_14 -> V_81 . V_83 ) {
V_14 -> V_80 . V_94 = F_52 ( V_14 -> V_19 , V_14 -> V_80 . V_83 , V_14 -> V_80 . V_86 ,
V_95 ) ;
V_14 -> V_81 . V_94 = V_14 -> V_80 . V_94 ;
if ( ! V_14 -> V_80 . V_94 )
return - V_96 ;
} else {
V_14 -> V_80 . V_94 = F_52 ( V_14 -> V_19 , V_14 -> V_80 . V_83 , V_14 -> V_80 . V_86 ,
V_97 ) ;
if ( ! V_14 -> V_80 . V_94 )
return - V_96 ;
V_14 -> V_81 . V_94 = F_52 ( V_14 -> V_19 , V_14 -> V_81 . V_83 , V_14 -> V_81 . V_86 ,
V_98 ) ;
if ( ! V_14 -> V_81 . V_94 ) {
F_53 ( V_14 -> V_19 , V_14 -> V_80 . V_83 , V_14 -> V_80 . V_86 ,
V_97 ) ;
return - V_96 ;
}
}
return 0 ;
}
static void F_54 ( struct V_13 * V_14 )
{
if ( V_14 -> V_80 . V_83 == V_14 -> V_81 . V_83 ) {
F_53 ( V_14 -> V_19 , V_14 -> V_80 . V_83 , V_14 -> V_80 . V_86 ,
V_95 ) ;
if ( V_14 -> V_80 . V_83 != & V_14 -> V_93 )
F_48 ( & V_14 -> V_80 ) ;
} else {
F_53 ( V_14 -> V_19 , V_14 -> V_81 . V_83 , V_14 -> V_81 . V_86 ,
V_98 ) ;
if ( V_14 -> V_81 . V_83 != & V_14 -> V_93 )
F_48 ( & V_14 -> V_81 ) ;
F_53 ( V_14 -> V_19 , V_14 -> V_80 . V_83 , V_14 -> V_80 . V_86 ,
V_97 ) ;
if ( V_14 -> V_80 . V_83 != & V_14 -> V_93 )
F_48 ( & V_14 -> V_80 ) ;
}
if ( V_14 -> V_81 . V_83 == & V_14 -> V_93 )
F_41 ( V_14 -> V_74 , F_42 ( V_14 -> V_74 ) ,
V_14 -> V_75 , V_14 -> V_76 ) ;
}
static int F_55 ( struct V_13 * V_14 ,
enum V_99 V_100 ,
enum V_101 V_102 ,
T_1 V_103 )
{
struct V_104 * V_105 ;
struct V_106 V_107 ;
T_4 V_108 ;
struct V_84 * V_85 ;
int V_37 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . V_109 = V_102 ;
V_107 . V_110 = V_100 ;
V_107 . V_111 = V_100 ;
V_107 . V_112 = V_103 ;
V_107 . V_113 = V_103 ;
switch ( V_102 ) {
case V_114 :
V_85 = & V_14 -> V_80 ;
V_108 = NULL ;
V_107 . V_115 = V_14 -> V_116 + F_3 ( 0 ) ;
break;
case V_117 :
V_85 = & V_14 -> V_81 ;
V_108 = V_118 ;
V_107 . V_119 = V_14 -> V_116 + F_4 ( 0 ) ;
break;
default:
return - V_77 ;
}
V_37 = F_56 ( V_85 -> V_120 , & V_107 ) ;
if ( V_37 )
return V_37 ;
V_105 = F_57 ( V_85 -> V_120 , V_85 -> V_83 , V_85 -> V_94 , V_102 ,
V_121 | V_122 ) ;
if ( ! V_105 )
return - V_92 ;
V_105 -> V_108 = V_108 ;
V_105 -> V_123 = V_14 ;
F_58 ( V_105 ) ;
F_59 ( V_85 -> V_120 ) ;
return 0 ;
}
static void F_60 ( struct V_13 * V_14 ,
enum V_101 V_102 )
{
struct V_84 * V_85 ;
switch ( V_102 ) {
case V_114 :
V_85 = & V_14 -> V_80 ;
break;
case V_117 :
V_85 = & V_14 -> V_81 ;
break;
default:
return;
}
F_61 ( V_85 -> V_120 ) ;
}
static int F_62 ( struct V_13 * V_14 ,
struct V_79 * V_80 ,
struct V_79 * V_81 ,
T_2 V_26 ,
T_3 V_22 )
{
enum V_99 V_100 ;
T_1 V_103 ;
int V_37 ;
switch ( V_14 -> V_33 -> V_27 ) {
case V_124 :
V_100 = V_125 ;
V_103 = 1 ;
break;
case V_126 :
V_100 = V_127 ;
V_103 = 1 ;
break;
case V_128 :
case V_129 :
V_100 = V_130 ;
V_103 = 1 ;
break;
case V_21 :
V_100 = V_130 ;
V_103 = V_14 -> V_65 . V_131 ;
break;
default:
V_37 = - V_77 ;
goto exit;
}
V_37 = F_49 ( V_14 , V_80 , V_81 , V_26 ) ;
if ( V_37 )
goto exit;
V_14 -> V_22 = V_22 ;
V_37 = F_55 ( V_14 , V_100 , V_117 ,
V_103 ) ;
if ( V_37 )
goto V_132;
V_37 = F_55 ( V_14 , V_100 , V_114 ,
V_103 ) ;
if ( V_37 )
goto V_133;
return - V_25 ;
V_133:
F_60 ( V_14 , V_117 ) ;
V_132:
F_54 ( V_14 ) ;
exit:
return F_37 ( V_14 , V_37 ) ;
}
static void F_63 ( struct V_13 * V_14 )
{
F_60 ( V_14 , V_114 ) ;
F_60 ( V_14 , V_117 ) ;
F_54 ( V_14 ) ;
}
static void V_118 ( void * V_72 )
{
struct V_13 * V_14 = V_72 ;
F_63 ( V_14 ) ;
V_14 -> V_50 = true ;
( void ) V_14 -> V_22 ( V_14 ) ;
}
static int F_64 ( struct V_13 * V_14 ,
struct V_29 * V_134 )
{
struct V_29 * V_51 , * V_135 ;
struct V_32 * V_33 ;
unsigned long V_17 ;
int V_37 , V_136 = 0 ;
F_65 ( & V_14 -> V_36 , V_17 ) ;
if ( V_134 )
V_136 = F_66 ( & V_14 -> V_137 , V_134 ) ;
if ( V_14 -> V_17 & V_49 ) {
F_67 ( & V_14 -> V_36 , V_17 ) ;
return V_136 ;
}
V_135 = F_68 ( & V_14 -> V_137 ) ;
V_51 = F_69 ( & V_14 -> V_137 ) ;
if ( V_51 )
V_14 -> V_17 |= V_49 ;
F_67 ( & V_14 -> V_36 , V_17 ) ;
if ( ! V_51 )
return V_136 ;
if ( V_135 )
V_135 -> V_52 ( V_135 , - V_25 ) ;
V_33 = F_70 ( V_51 -> V_138 ) ;
V_14 -> V_51 = V_51 ;
V_14 -> V_33 = V_33 ;
V_14 -> V_50 = ( V_51 != V_134 ) ;
V_37 = V_33 -> V_139 ( V_14 ) ;
return ( V_14 -> V_50 ) ? V_136 : V_37 ;
}
static int F_71 ( struct V_13 * V_14 )
{
return F_37 ( V_14 , 0 ) ;
}
static int F_72 ( struct V_13 * V_14 )
{
struct V_140 * V_30 = F_73 ( V_14 -> V_51 ) ;
struct V_44 * V_45 = F_74 ( V_30 ) ;
bool V_54 = ( V_30 -> V_141 >= V_142 ||
V_14 -> V_33 -> V_27 != V_21 ) ;
int V_37 ;
F_35 ( V_14 , V_45 ) ;
V_37 = F_29 ( V_14 ) ;
if ( V_37 )
return F_37 ( V_14 , V_37 ) ;
F_39 ( V_14 , V_54 , V_30 -> V_143 ) ;
if ( V_54 )
return F_62 ( V_14 , V_30 -> V_80 , V_30 -> V_81 , V_30 -> V_141 ,
F_71 ) ;
return F_43 ( V_14 , V_30 -> V_80 , V_30 -> V_81 , V_30 -> V_141 ,
F_71 ) ;
}
static inline struct V_144 *
F_75 ( struct V_32 * V_33 )
{
return F_24 ( V_33 , struct V_144 , V_31 ) ;
}
static int F_76 ( struct V_13 * V_14 )
{
struct V_144 * V_33 = F_75 ( V_14 -> V_33 ) ;
struct V_140 * V_30 = F_73 ( V_14 -> V_51 ) ;
struct V_79 * V_80 , * V_81 ;
T_1 V_145 , V_146 ;
T_2 V_73 ;
bool V_54 , V_147 = false ;
V_33 -> V_1 += V_14 -> V_76 ;
if ( V_33 -> V_1 >= V_30 -> V_141 )
return F_71 ( V_14 ) ;
V_73 = V_30 -> V_141 - V_33 -> V_1 ;
V_146 = F_77 ( V_73 , V_21 ) ;
V_145 = F_78 ( V_33 -> V_55 [ 3 ] ) ;
if ( V_14 -> V_65 . V_148 ) {
T_1 V_139 = V_145 ;
T_1 V_149 = V_139 + V_146 - 1 ;
if ( V_149 < V_139 ) {
V_145 |= 0xffffffff ;
V_73 = V_21 * - V_139 ;
V_147 = true ;
}
} else {
T_5 V_139 = V_145 & 0xffff ;
T_5 V_149 = V_139 + ( T_5 ) V_146 - 1 ;
if ( V_146 >> 16 || V_149 < V_139 ) {
V_145 |= 0xffff ;
V_73 = V_21 * ( 0x10000 - V_139 ) ;
V_147 = true ;
}
}
V_54 = ( V_73 >= V_142 ) ;
V_80 = F_79 ( V_33 -> V_80 , V_30 -> V_80 , V_33 -> V_1 ) ;
V_81 = ( ( V_30 -> V_80 == V_30 -> V_81 ) ? V_80 :
F_79 ( V_33 -> V_81 , V_30 -> V_81 , V_33 -> V_1 ) ) ;
F_39 ( V_14 , V_54 , V_33 -> V_55 ) ;
if ( F_21 ( V_147 ) ) {
V_33 -> V_55 [ 3 ] = F_80 ( V_145 ) ;
F_81 ( ( V_150 * ) V_33 -> V_55 , V_21 ) ;
}
if ( V_54 )
return F_62 ( V_14 , V_80 , V_81 , V_73 ,
F_76 ) ;
return F_43 ( V_14 , V_80 , V_81 , V_73 ,
F_76 ) ;
}
static int F_82 ( struct V_13 * V_14 )
{
struct V_144 * V_33 = F_75 ( V_14 -> V_33 ) ;
struct V_140 * V_30 = F_73 ( V_14 -> V_51 ) ;
struct V_44 * V_45 = F_74 ( V_30 ) ;
int V_37 ;
F_35 ( V_14 , V_45 ) ;
V_37 = F_29 ( V_14 ) ;
if ( V_37 )
return F_37 ( V_14 , V_37 ) ;
memcpy ( V_33 -> V_55 , V_30 -> V_143 , V_21 ) ;
V_33 -> V_1 = 0 ;
V_14 -> V_76 = 0 ;
return F_76 ( V_14 ) ;
}
static int F_83 ( struct V_140 * V_30 , unsigned long V_47 )
{
struct V_32 * V_33 ;
struct V_44 * V_45 ;
struct V_13 * V_14 ;
V_33 = F_84 ( F_85 ( V_30 ) ) ;
switch ( V_47 & V_151 ) {
case V_152 :
V_33 -> V_27 = V_124 ;
break;
case V_153 :
V_33 -> V_27 = V_126 ;
break;
case V_154 :
V_33 -> V_27 = V_128 ;
break;
case V_155 :
V_33 -> V_27 = V_129 ;
break;
default:
V_33 -> V_27 = V_21 ;
break;
}
V_14 = F_25 ( V_33 ) ;
if ( ! V_14 )
return - V_156 ;
V_45 = F_74 ( V_30 ) ;
V_45 -> V_47 = V_47 ;
return F_64 ( V_14 , & V_30 -> V_31 ) ;
}
static int F_86 ( struct V_157 * V_138 , const V_150 * V_69 ,
unsigned int V_57 )
{
struct V_32 * V_33 = F_84 ( V_138 ) ;
if ( V_57 != V_58 &&
V_57 != V_60 &&
V_57 != V_158 ) {
F_87 ( V_138 , V_159 ) ;
return - V_77 ;
}
memcpy ( V_33 -> V_69 , V_69 , V_57 ) ;
V_33 -> V_57 = V_57 ;
return 0 ;
}
static int F_88 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_160 | V_48 ) ;
}
static int F_89 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_160 ) ;
}
static int F_90 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_161 | V_48 ) ;
}
static int F_91 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_161 ) ;
}
static int F_92 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_162 | V_48 ) ;
}
static int F_93 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_162 ) ;
}
static int F_94 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_163 | V_48 ) ;
}
static int F_95 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_163 ) ;
}
static int F_96 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_155 | V_48 ) ;
}
static int F_97 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_155 ) ;
}
static int F_98 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_154 | V_48 ) ;
}
static int F_99 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_154 ) ;
}
static int F_100 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_153 | V_48 ) ;
}
static int F_101 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_153 ) ;
}
static int F_102 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_152 | V_48 ) ;
}
static int F_103 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_152 ) ;
}
static int F_104 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_164 | V_48 ) ;
}
static int F_105 ( struct V_140 * V_30 )
{
return F_83 ( V_30 , V_164 ) ;
}
static int F_106 ( struct V_165 * V_138 )
{
struct V_166 * V_33 = F_70 ( V_138 ) ;
V_138 -> V_167 . V_168 = sizeof( struct V_44 ) ;
V_33 -> V_31 . V_139 = F_72 ;
return 0 ;
}
static int F_107 ( struct V_165 * V_138 )
{
struct V_166 * V_33 = F_70 ( V_138 ) ;
V_138 -> V_167 . V_168 = sizeof( struct V_44 ) ;
V_33 -> V_31 . V_139 = F_82 ;
return 0 ;
}
static void F_108 ( struct V_165 * V_138 )
{
}
static inline struct V_169 *
F_109 ( struct V_32 * V_33 )
{
return F_24 ( V_33 , struct V_169 , V_31 ) ;
}
static int F_110 ( struct V_13 * V_14 ,
const T_1 * V_72 , T_2 V_73 ,
const T_1 * V_170 , T_1 * V_171 ,
T_3 V_22 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
V_14 -> V_72 = ( T_1 * ) V_72 ;
V_14 -> V_73 = V_73 ;
V_33 -> V_170 = V_170 ;
V_33 -> V_171 = V_171 ;
V_33 -> V_172 = V_22 ;
F_39 ( V_14 , false , NULL ) ;
return F_20 ( V_14 , V_173 ) ;
}
static int V_173 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
F_13 ( V_14 , V_10 , V_14 -> V_76 ) ;
F_13 ( V_14 , V_11 , 0 ) ;
if ( V_33 -> V_170 )
F_19 ( V_14 , F_6 ( 0 ) , V_33 -> V_170 ) ;
return F_111 ( V_14 ) ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
T_1 V_23 ;
while ( V_14 -> V_73 > 0 ) {
F_19 ( V_14 , F_3 ( 0 ) , V_14 -> V_72 ) ;
V_14 -> V_72 += 4 ;
V_14 -> V_73 -= V_21 ;
V_23 = F_9 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_111 ;
F_13 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
F_17 ( V_14 , F_6 ( 0 ) , V_33 -> V_171 ) ;
return V_33 -> V_172 ( V_14 ) ;
}
static int F_112 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
struct V_174 * V_138 = F_113 ( V_30 ) ;
struct V_44 * V_45 = F_114 ( V_30 ) ;
T_2 V_175 = F_115 ( V_138 ) ;
T_2 V_73 , V_82 ;
const void * V_55 = V_30 -> V_55 ;
V_150 * V_72 = V_14 -> V_75 ;
int V_37 ;
F_35 ( V_14 , V_45 ) ;
V_37 = F_29 ( V_14 ) ;
if ( V_37 )
return F_37 ( V_14 , V_37 ) ;
if ( F_116 ( V_175 == 12 ) ) {
memcpy ( V_33 -> j0 , V_55 , V_175 ) ;
V_33 -> j0 [ 3 ] = F_80 ( 1 ) ;
return F_117 ( V_14 ) ;
}
V_82 = F_22 ( V_175 , V_21 ) ;
V_73 = V_175 + V_82 + V_21 ;
if ( V_73 > V_14 -> V_91 )
return F_37 ( V_14 , - V_77 ) ;
memcpy ( V_72 , V_55 , V_175 ) ;
memset ( V_72 + V_175 , 0 , V_82 + sizeof( V_176 ) ) ;
( ( V_176 * ) ( V_72 + V_73 ) ) [ - 1 ] = F_118 ( V_175 * 8 ) ;
return F_110 ( V_14 , ( const T_1 * ) V_72 , V_73 ,
NULL , V_33 -> j0 , F_117 ) ;
}
static int F_117 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
struct V_174 * V_138 = F_113 ( V_30 ) ;
bool V_177 = F_36 ( V_14 ) ;
T_1 V_178 ;
V_178 = F_119 ( V_138 ) ;
V_33 -> V_179 = V_30 -> V_180 - ( V_177 ? 0 : V_178 ) ;
if ( F_116 ( V_30 -> V_181 != 0 || V_33 -> V_179 != 0 ) )
V_14 -> V_17 |= V_182 ;
F_39 ( V_14 , false , NULL ) ;
return F_20 ( V_14 , V_183 ) ;
}
static int V_183 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
T_1 V_184 , * j0 = V_33 -> j0 ;
T_2 V_82 ;
V_184 = j0 [ 3 ] ;
j0 [ 3 ] = F_80 ( F_78 ( j0 [ 3 ] ) + 1 ) ;
F_19 ( V_14 , F_5 ( 0 ) , j0 ) ;
j0 [ 3 ] = V_184 ;
F_13 ( V_14 , V_10 , V_30 -> V_181 ) ;
F_13 ( V_14 , V_11 , V_33 -> V_179 ) ;
if ( F_21 ( V_30 -> V_181 == 0 ) ) {
V_14 -> V_73 = 0 ;
return F_120 ( V_14 ) ;
}
V_82 = F_22 ( V_30 -> V_181 , V_21 ) ;
if ( F_21 ( V_30 -> V_181 + V_82 > V_14 -> V_91 ) )
return F_37 ( V_14 , - V_77 ) ;
F_44 ( V_30 -> V_80 , F_42 ( V_30 -> V_80 ) , V_14 -> V_75 , V_30 -> V_181 ) ;
V_14 -> V_72 = ( T_1 * ) V_14 -> V_75 ;
V_14 -> V_73 = V_30 -> V_181 + V_82 ;
return F_120 ( V_14 ) ;
}
static int F_120 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
bool V_54 = ( V_33 -> V_179 >= V_142 ) ;
struct V_79 * V_80 , * V_81 ;
T_1 V_23 , V_185 ;
while ( V_14 -> V_73 > 0 ) {
F_19 ( V_14 , F_3 ( 0 ) , V_14 -> V_72 ) ;
V_14 -> V_72 += 4 ;
V_14 -> V_73 -= V_21 ;
V_23 = F_9 ( V_14 , V_6 ) ;
if ( ! ( V_23 & V_24 ) ) {
V_14 -> V_22 = F_120 ;
F_13 ( V_14 , V_8 , V_24 ) ;
return - V_25 ;
}
}
if ( F_21 ( V_33 -> V_179 == 0 ) )
return F_121 ( V_14 ) ;
V_80 = F_79 ( V_33 -> V_80 , V_30 -> V_80 , V_30 -> V_181 ) ;
V_81 = ( ( V_30 -> V_80 == V_30 -> V_81 ) ? V_80 :
F_79 ( V_33 -> V_81 , V_30 -> V_81 , V_30 -> V_181 ) ) ;
if ( V_54 ) {
V_185 = F_9 ( V_14 , V_5 ) ;
V_185 &= ~ ( V_186 | V_67 ) ;
V_185 |= V_64 ;
if ( V_14 -> V_65 . V_66 )
V_185 |= V_67 ;
F_13 ( V_14 , V_5 , V_185 ) ;
return F_62 ( V_14 , V_80 , V_81 , V_33 -> V_179 ,
F_121 ) ;
}
return F_43 ( V_14 , V_80 , V_81 , V_33 -> V_179 ,
F_121 ) ;
}
static int F_121 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
V_176 * V_72 = V_14 -> V_75 ;
if ( F_116 ( V_14 -> V_17 & V_182 ) ) {
if ( ! ( F_9 ( V_14 , V_6 ) & V_187 ) ) {
V_14 -> V_22 = F_121 ;
F_13 ( V_14 , V_8 , V_187 ) ;
return - V_25 ;
}
return F_122 ( V_14 ) ;
}
F_17 ( V_14 , F_6 ( 0 ) , V_33 -> V_188 ) ;
V_72 [ 0 ] = F_118 ( V_30 -> V_181 * 8 ) ;
V_72 [ 1 ] = F_118 ( V_33 -> V_179 * 8 ) ;
return F_110 ( V_14 , ( const T_1 * ) V_72 , V_21 ,
V_33 -> V_188 , V_33 -> V_188 , V_189 ) ;
}
static int V_189 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
unsigned long V_17 ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 &= ~ ( V_151 | V_182 ) ;
V_14 -> V_17 |= V_164 ;
F_39 ( V_14 , false , V_33 -> j0 ) ;
V_14 -> V_17 = V_17 ;
F_19 ( V_14 , F_3 ( 0 ) , V_33 -> V_188 ) ;
return F_20 ( V_14 , F_122 ) ;
}
static int F_122 ( struct V_13 * V_14 )
{
struct V_169 * V_33 = F_109 ( V_14 -> V_33 ) ;
struct V_28 * V_30 = F_23 ( V_14 -> V_51 ) ;
struct V_174 * V_138 = F_113 ( V_30 ) ;
bool V_177 = F_36 ( V_14 ) ;
T_1 V_1 , V_178 , V_190 [ 4 ] , * V_191 = V_33 -> V_192 ;
int V_37 ;
if ( F_116 ( V_14 -> V_17 & V_182 ) )
F_17 ( V_14 , F_7 ( 0 ) , V_33 -> V_192 ) ;
else
F_17 ( V_14 , F_4 ( 0 ) , V_33 -> V_192 ) ;
V_1 = V_30 -> V_181 + V_33 -> V_179 ;
V_178 = F_119 ( V_138 ) ;
if ( V_177 ) {
F_123 ( V_191 , V_30 -> V_81 , V_1 , V_178 , 1 ) ;
V_37 = 0 ;
} else {
F_123 ( V_190 , V_30 -> V_80 , V_1 , V_178 , 0 ) ;
V_37 = F_124 ( V_190 , V_191 , V_178 ) ? - V_193 : 0 ;
}
return F_37 ( V_14 , V_37 ) ;
}
static int F_125 ( struct V_28 * V_30 ,
unsigned long V_47 )
{
struct V_32 * V_33 ;
struct V_44 * V_45 ;
struct V_13 * V_14 ;
V_33 = F_126 ( F_113 ( V_30 ) ) ;
V_33 -> V_27 = V_21 ;
V_14 = F_25 ( V_33 ) ;
if ( ! V_14 )
return - V_156 ;
V_45 = F_114 ( V_30 ) ;
V_45 -> V_47 = V_194 | V_47 ;
return F_64 ( V_14 , & V_30 -> V_31 ) ;
}
static int F_127 ( struct V_174 * V_138 , const V_150 * V_69 ,
unsigned int V_57 )
{
struct V_32 * V_33 = F_126 ( V_138 ) ;
if ( V_57 != V_158 &&
V_57 != V_60 &&
V_57 != V_58 ) {
F_128 ( V_138 , V_159 ) ;
return - V_77 ;
}
memcpy ( V_33 -> V_69 , V_69 , V_57 ) ;
V_33 -> V_57 = V_57 ;
return 0 ;
}
static int F_129 ( struct V_174 * V_138 ,
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
return - V_77 ;
}
return 0 ;
}
static int F_130 ( struct V_28 * V_30 )
{
return F_125 ( V_30 , V_48 ) ;
}
static int F_131 ( struct V_28 * V_30 )
{
return F_125 ( V_30 , 0 ) ;
}
static int F_132 ( struct V_174 * V_138 )
{
struct V_169 * V_33 = F_126 ( V_138 ) ;
F_133 ( V_138 , sizeof( struct V_44 ) ) ;
V_33 -> V_31 . V_139 = F_112 ;
return 0 ;
}
static void F_134 ( struct V_174 * V_138 )
{
}
static int F_135 ( struct V_13 * V_14 )
{
V_14 -> V_75 = ( void * ) F_136 ( V_195 , V_196 ) ;
V_14 -> V_91 = V_197 ;
V_14 -> V_91 &= ~ ( V_21 - 1 ) ;
if ( ! V_14 -> V_75 ) {
F_137 ( V_14 -> V_19 , L_21 ) ;
return - V_92 ;
}
return 0 ;
}
static void F_138 ( struct V_13 * V_14 )
{
F_139 ( ( unsigned long ) V_14 -> V_75 ) ;
}
static bool F_140 ( struct V_198 * V_120 , void * V_199 )
{
struct V_200 * V_201 = V_199 ;
if ( V_201 && V_201 -> V_202 == V_120 -> V_203 -> V_19 ) {
V_120 -> V_204 = V_201 ;
return true ;
} else {
return false ;
}
}
static int F_141 ( struct V_13 * V_14 ,
struct V_205 * V_206 )
{
struct V_200 * V_199 ;
int V_37 = - V_92 ;
T_6 V_207 ;
F_142 ( V_207 ) ;
F_143 ( V_208 , V_207 ) ;
V_199 = & V_206 -> V_209 -> V_210 ;
V_14 -> V_80 . V_120 = F_144 ( V_207 , F_140 ,
V_199 , V_14 -> V_19 , L_22 ) ;
if ( ! V_14 -> V_80 . V_120 )
goto V_211;
V_199 = & V_206 -> V_209 -> V_212 ;
V_14 -> V_81 . V_120 = F_144 ( V_207 , F_140 ,
V_199 , V_14 -> V_19 , L_23 ) ;
if ( ! V_14 -> V_81 . V_120 )
goto V_213;
return 0 ;
V_213:
F_145 ( V_14 -> V_80 . V_120 ) ;
V_211:
F_146 ( V_14 -> V_19 , L_24 ) ;
return V_37 ;
}
static void F_147 ( struct V_13 * V_14 )
{
F_145 ( V_14 -> V_81 . V_120 ) ;
F_145 ( V_14 -> V_80 . V_120 ) ;
}
static void F_148 ( unsigned long V_72 )
{
struct V_13 * V_14 = (struct V_13 * ) V_72 ;
F_64 ( V_14 , NULL ) ;
}
static void F_149 ( unsigned long V_72 )
{
struct V_13 * V_14 = (struct V_13 * ) V_72 ;
V_14 -> V_50 = true ;
( void ) V_14 -> V_22 ( V_14 ) ;
}
static T_7 F_150 ( int V_214 , void * V_215 )
{
struct V_13 * V_34 = V_215 ;
T_1 V_216 ;
V_216 = F_9 ( V_34 , V_6 ) ;
if ( V_216 & F_9 ( V_34 , V_7 ) ) {
F_13 ( V_34 , V_9 , V_216 ) ;
if ( V_49 & V_34 -> V_17 )
F_38 ( & V_34 -> V_217 ) ;
else
F_146 ( V_34 -> V_19 , L_25 ) ;
return V_218 ;
}
return V_219 ;
}
static void F_151 ( struct V_13 * V_14 )
{
int V_220 ;
if ( V_14 -> V_65 . V_221 )
F_152 ( & V_222 ) ;
if ( V_14 -> V_65 . V_223 )
F_153 ( & V_224 ) ;
for ( V_220 = 0 ; V_220 < F_154 ( V_225 ) ; V_220 ++ )
F_153 ( & V_225 [ V_220 ] ) ;
}
static int F_155 ( struct V_13 * V_14 )
{
int V_37 , V_220 , V_226 ;
for ( V_220 = 0 ; V_220 < F_154 ( V_225 ) ; V_220 ++ ) {
V_37 = F_156 ( & V_225 [ V_220 ] ) ;
if ( V_37 )
goto V_227;
}
if ( V_14 -> V_65 . V_223 ) {
V_37 = F_156 ( & V_224 ) ;
if ( V_37 )
goto V_228;
}
if ( V_14 -> V_65 . V_221 ) {
V_37 = F_157 ( & V_222 ) ;
if ( V_37 )
goto V_229;
}
return 0 ;
V_229:
F_153 ( & V_224 ) ;
V_228:
V_220 = F_154 ( V_225 ) ;
V_227:
for ( V_226 = 0 ; V_226 < V_220 ; V_226 ++ )
F_153 ( & V_225 [ V_226 ] ) ;
return V_37 ;
}
static void F_158 ( struct V_13 * V_14 )
{
V_14 -> V_65 . V_66 = 0 ;
V_14 -> V_65 . V_223 = 0 ;
V_14 -> V_65 . V_148 = 0 ;
V_14 -> V_65 . V_221 = 0 ;
V_14 -> V_65 . V_131 = 1 ;
switch ( V_14 -> V_43 & 0xff0 ) {
case 0x500 :
V_14 -> V_65 . V_66 = 1 ;
V_14 -> V_65 . V_223 = 1 ;
V_14 -> V_65 . V_148 = 1 ;
V_14 -> V_65 . V_221 = 1 ;
V_14 -> V_65 . V_131 = 4 ;
break;
case 0x200 :
V_14 -> V_65 . V_66 = 1 ;
V_14 -> V_65 . V_223 = 1 ;
V_14 -> V_65 . V_148 = 1 ;
V_14 -> V_65 . V_221 = 1 ;
V_14 -> V_65 . V_131 = 4 ;
break;
case 0x130 :
V_14 -> V_65 . V_66 = 1 ;
V_14 -> V_65 . V_223 = 1 ;
V_14 -> V_65 . V_131 = 4 ;
break;
case 0x120 :
break;
default:
F_146 ( V_14 -> V_19 ,
L_26 ) ;
break;
}
}
static struct V_205 * F_159 ( struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_19 . V_234 ;
struct V_205 * V_206 ;
if ( ! V_233 ) {
F_137 ( & V_231 -> V_19 , L_27 ) ;
return F_160 ( - V_77 ) ;
}
V_206 = F_161 ( & V_231 -> V_19 , sizeof( * V_206 ) , V_195 ) ;
if ( ! V_206 ) {
F_137 ( & V_231 -> V_19 , L_28 ) ;
return F_160 ( - V_92 ) ;
}
V_206 -> V_209 = F_161 ( & V_231 -> V_19 ,
sizeof( * ( V_206 -> V_209 ) ) ,
V_195 ) ;
if ( ! V_206 -> V_209 ) {
F_137 ( & V_231 -> V_19 , L_29 ) ;
F_162 ( & V_231 -> V_19 , V_206 ) ;
return F_160 ( - V_92 ) ;
}
return V_206 ;
}
static inline struct V_205 * F_159 ( struct V_230 * V_231 )
{
return F_160 ( - V_77 ) ;
}
static int F_163 ( struct V_230 * V_231 )
{
struct V_13 * V_34 ;
struct V_205 * V_206 ;
struct V_203 * V_19 = & V_231 -> V_19 ;
struct V_235 * V_236 ;
int V_37 ;
V_206 = V_231 -> V_19 . V_237 ;
if ( ! V_206 ) {
V_206 = F_159 ( V_231 ) ;
if ( F_164 ( V_206 ) ) {
V_37 = F_165 ( V_206 ) ;
goto V_238;
}
}
if ( ! V_206 -> V_209 ) {
V_37 = - V_239 ;
goto V_238;
}
V_34 = F_161 ( & V_231 -> V_19 , sizeof( * V_34 ) , V_195 ) ;
if ( V_34 == NULL ) {
F_137 ( V_19 , L_30 ) ;
V_37 = - V_92 ;
goto V_238;
}
V_34 -> V_19 = V_19 ;
F_166 ( V_231 , V_34 ) ;
F_167 ( & V_34 -> V_240 ) ;
F_168 ( & V_34 -> V_36 ) ;
F_169 ( & V_34 -> V_217 , F_149 ,
( unsigned long ) V_34 ) ;
F_169 ( & V_34 -> V_53 , F_148 ,
( unsigned long ) V_34 ) ;
F_170 ( & V_34 -> V_137 , V_241 ) ;
V_34 -> V_214 = - 1 ;
V_236 = F_171 ( V_231 , V_242 , 0 ) ;
if ( ! V_236 ) {
F_137 ( V_19 , L_31 ) ;
V_37 = - V_156 ;
goto V_243;
}
V_34 -> V_116 = V_236 -> V_139 ;
V_34 -> V_214 = F_172 ( V_231 , 0 ) ;
if ( V_34 -> V_214 < 0 ) {
F_137 ( V_19 , L_32 ) ;
V_37 = V_34 -> V_214 ;
goto V_243;
}
V_37 = F_173 ( & V_231 -> V_19 , V_34 -> V_214 , F_150 ,
V_244 , L_33 , V_34 ) ;
if ( V_37 ) {
F_137 ( V_19 , L_34 ) ;
goto V_243;
}
V_34 -> V_38 = F_174 ( & V_231 -> V_19 , L_35 ) ;
if ( F_164 ( V_34 -> V_38 ) ) {
F_137 ( V_19 , L_36 ) ;
V_37 = F_165 ( V_34 -> V_38 ) ;
goto V_243;
}
V_34 -> V_16 = F_175 ( & V_231 -> V_19 , V_236 ) ;
if ( ! V_34 -> V_16 ) {
F_137 ( V_19 , L_37 ) ;
V_37 = - V_92 ;
goto V_243;
}
V_37 = F_176 ( V_34 -> V_38 ) ;
if ( V_37 )
goto V_243;
V_37 = F_32 ( V_34 ) ;
if ( V_37 )
goto V_245;
F_158 ( V_34 ) ;
V_37 = F_135 ( V_34 ) ;
if ( V_37 )
goto V_246;
V_37 = F_141 ( V_34 , V_206 ) ;
if ( V_37 )
goto V_247;
F_177 ( & V_35 . V_36 ) ;
F_178 ( & V_34 -> V_240 , & V_35 . V_248 ) ;
F_179 ( & V_35 . V_36 ) ;
V_37 = F_155 ( V_34 ) ;
if ( V_37 )
goto V_249;
F_33 ( V_19 , L_38 ,
F_180 ( V_34 -> V_80 . V_120 ) ,
F_180 ( V_34 -> V_81 . V_120 ) ) ;
return 0 ;
V_249:
F_177 ( & V_35 . V_36 ) ;
F_181 ( & V_34 -> V_240 ) ;
F_179 ( & V_35 . V_36 ) ;
F_147 ( V_34 ) ;
V_247:
F_138 ( V_34 ) ;
V_246:
V_245:
F_182 ( V_34 -> V_38 ) ;
V_243:
F_183 ( & V_34 -> V_217 ) ;
F_183 ( & V_34 -> V_53 ) ;
V_238:
F_137 ( V_19 , L_39 ) ;
return V_37 ;
}
static int F_184 ( struct V_230 * V_231 )
{
static struct V_13 * V_34 ;
V_34 = F_185 ( V_231 ) ;
if ( ! V_34 )
return - V_156 ;
F_177 ( & V_35 . V_36 ) ;
F_181 ( & V_34 -> V_240 ) ;
F_179 ( & V_35 . V_36 ) ;
F_151 ( V_34 ) ;
F_183 ( & V_34 -> V_217 ) ;
F_183 ( & V_34 -> V_53 ) ;
F_147 ( V_34 ) ;
F_138 ( V_34 ) ;
F_182 ( V_34 -> V_38 ) ;
return 0 ;
}
