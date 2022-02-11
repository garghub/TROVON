static const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
} ;
return V_3 [ V_2 ] ;
}
static void F_2 ( struct V_7 * V_8 ,
enum V_1 V_2 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
enum V_1 V_11 = V_10 -> V_12 ;
F_4 ( L_4 ,
F_5 ( V_8 ) , V_8 , F_1 ( V_11 ) ,
F_1 ( V_2 ) ) ;
F_6 ( V_2 == V_11 ) ;
V_10 -> V_12 = V_2 ;
}
static inline T_1 F_7 ( struct V_7 * V_8 )
{
const struct V_9 * V_10 = F_3 ( V_8 ) ;
const T_2 V_13 = F_8 ( T_2 , 4380U , 2 * V_10 -> V_14 , 4 * V_10 -> V_14 ) ;
return F_9 ( V_13 << 6 , V_10 -> V_15 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
V_10 -> V_16 = F_11 ( ( ( T_1 ) V_10 -> V_14 ) << 6 , V_10 -> V_17 ) ;
F_12 ( V_10 -> V_16 == 0 ) ;
F_4 ( L_5 , V_10 -> V_16 ,
V_10 -> V_14 , ( unsigned int ) ( V_10 -> V_17 >> 6 ) ) ;
}
static T_3 F_13 ( struct V_9 * V_10 , T_4 V_18 )
{
T_3 V_19 = F_14 ( V_18 , V_10 -> V_20 ) ;
return V_19 / V_10 -> V_15 ;
}
static void F_15 ( struct V_7 * V_8 , T_4 * V_21 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_5 V_22 = 2 * V_10 -> V_23 ;
const T_5 V_24 = V_10 -> V_17 ;
T_4 V_18 = V_21 ? * V_21 : F_16 () ;
if ( F_13 ( V_10 , V_18 ) >= 2 ) {
V_22 = F_7 ( V_8 ) ;
V_22 = F_17 ( V_22 , 2 * V_10 -> V_23 ) ;
}
if ( V_10 -> V_25 > 0 ) {
V_10 -> V_17 = F_18 ( ( ( T_5 ) V_10 -> V_26 ) << 6 , V_22 ) ;
V_10 -> V_17 = F_17 ( V_10 -> V_17 , ( ( ( T_5 ) V_10 -> V_14 ) << 6 ) / V_27 ) ;
} else if ( F_14 ( V_18 , V_10 -> V_28 ) - ( V_29 ) V_10 -> V_15 >= 0 ) {
V_10 -> V_17 = F_18 ( 2 * V_10 -> V_17 , V_22 ) ;
V_10 -> V_17 = F_17 ( V_10 -> V_17 ,
F_9 ( ( ( T_5 ) V_10 -> V_14 ) << 6 , V_10 -> V_15 ) ) ;
V_10 -> V_28 = V_18 ;
}
if ( V_10 -> V_17 != V_24 ) {
F_4 ( L_6
L_7 , ( unsigned int ) ( V_24 >> 6 ) ,
( unsigned int ) ( V_10 -> V_17 >> 6 ) , V_10 -> V_26 ,
( unsigned int ) ( V_10 -> V_23 >> 6 ) ) ;
F_10 ( V_10 ) ;
}
}
static inline void F_19 ( struct V_9 * V_10 , int V_30 )
{
const T_6 V_31 = V_10 -> V_14 ;
V_10 -> V_14 = F_20 ( V_10 -> V_14 , V_30 , 9 ) ;
if ( V_10 -> V_14 != V_31 )
F_10 ( V_10 ) ;
}
static inline void F_21 ( struct V_9 * V_10 ,
T_4 V_18 )
{
T_3 V_19 = F_14 ( V_18 , V_10 -> V_20 ) ,
V_32 = ( 4 * V_19 ) / V_10 -> V_15 ;
if ( V_32 > 0 ) {
V_10 -> V_20 = V_18 ;
V_10 -> V_33 += F_18 ( V_32 , 5U ) ;
V_10 -> V_33 &= 0xF ;
}
}
static void F_22 ( unsigned long V_34 )
{
struct V_7 * V_8 = (struct V_7 * ) V_34 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_35 = V_36 / 5 ;
F_23 ( V_8 ) ;
if ( F_24 ( V_8 ) ) {
goto V_37;
}
F_4 ( L_8 , F_5 ( V_8 ) , V_8 ,
F_1 ( V_10 -> V_12 ) ) ;
if ( ( 1 << V_8 -> V_38 ) & ~ ( V_39 | V_40 ) )
goto V_41;
if ( V_10 -> V_12 == V_6 )
F_2 ( V_8 , V_5 ) ;
if ( V_10 -> V_42 == 0 || V_10 -> V_25 == 0 ) {
V_10 -> V_17 = F_17 ( V_10 -> V_17 / 2 ,
( ( ( T_5 ) V_10 -> V_14 ) << 6 ) / V_27 ) ;
F_10 ( V_10 ) ;
} else {
if ( V_10 -> V_26 > ( V_10 -> V_23 >> 5 ) )
V_10 -> V_23 =
F_17 ( V_10 -> V_23 / 2 ,
( ( ( T_5 ) V_10 -> V_14 ) << 6 ) / ( 2 * V_27 ) ) ;
else {
V_10 -> V_23 = V_10 -> V_26 ;
V_10 -> V_23 <<= 4 ;
}
F_15 ( V_8 , NULL ) ;
}
F_4 ( L_9 ,
( unsigned long long ) V_10 -> V_17 ) ;
if ( F_25 ( V_10 -> V_42 == 0 ) )
V_35 = V_43 ;
else
V_35 = F_17 ( V_10 -> V_42 , 2 * V_10 -> V_16 ) ;
V_37:
F_26 ( V_8 , & V_10 -> V_44 ,
V_45 + F_27 ( V_35 ) ) ;
V_41:
F_28 ( V_8 ) ;
F_29 ( V_8 ) ;
}
static int F_30 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
struct V_48 * V_49 = F_31 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_4 V_18 = F_16 () ;
V_29 V_50 ;
if ( F_25 ( V_47 -> V_30 == 0 ) )
return - V_51 ;
if ( V_10 -> V_12 == V_4 ) {
F_26 ( V_8 , & V_10 -> V_44 , ( V_45 +
F_27 ( V_43 ) ) ) ;
V_10 -> V_33 = 0 ;
V_10 -> V_20 = V_18 ;
V_10 -> V_52 = V_18 ;
V_10 -> V_14 = V_47 -> V_30 ;
if ( V_49 -> V_53 ) {
F_4 ( L_10 , V_49 -> V_53 ) ;
V_10 -> V_15 = V_49 -> V_53 ;
V_10 -> V_17 = F_7 ( V_8 ) ;
V_10 -> V_28 = V_18 ;
} else {
V_10 -> V_15 = V_54 ;
V_10 -> V_17 = V_10 -> V_14 ;
V_10 -> V_17 <<= 6 ;
}
F_10 ( V_10 ) ;
F_2 ( V_8 , V_5 ) ;
} else {
V_50 = F_14 ( V_10 -> V_52 , V_18 ) ;
F_4 ( L_11 , ( long ) V_50 ) ;
if ( V_50 >= V_55 )
return ( T_3 ) V_50 / V_56 ;
F_21 ( V_10 , V_18 ) ;
}
V_49 -> V_57 = 1 ;
F_32 ( V_47 ) -> V_58 = V_10 -> V_33 ;
V_10 -> V_52 = F_33 ( V_10 -> V_52 , V_10 -> V_16 ) ;
return V_59 ;
}
static void F_34 ( struct V_7 * V_8 , unsigned int V_30 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_19 ( V_10 , V_30 ) ;
if ( F_35 ( & V_10 -> V_60 , F_31 ( V_8 ) -> V_61 ) )
F_36 ( L_12 ) ;
}
static void F_37 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_62 * V_63 ;
T_4 V_18 ;
unsigned long V_35 ;
T_3 V_64 ;
if ( ! ( F_32 ( V_47 ) -> V_65 == V_66 ||
F_32 ( V_47 ) -> V_65 == V_67 ) )
return;
V_63 = F_38 ( V_10 -> V_60 , F_39 ( V_47 ) ) ;
if ( V_63 == NULL )
return;
F_40 ( & V_63 -> V_68 ) ;
V_18 = F_16 () ;
V_64 = F_41 ( V_8 , F_14 ( V_18 , V_63 -> V_21 ) ) ;
V_10 -> V_15 = F_20 ( V_10 -> V_15 , V_64 , 9 ) ;
if ( V_10 -> V_12 == V_5 ) {
F_2 ( V_8 , V_6 ) ;
if ( V_10 -> V_42 == 0 ) {
V_10 -> V_17 = F_7 ( V_8 ) ;
V_10 -> V_28 = V_18 ;
F_10 ( V_10 ) ;
goto V_69;
} else if ( V_10 -> V_25 == 0 ) {
goto V_69;
}
}
if ( V_10 -> V_25 > 0 )
V_10 -> V_26 = F_42 ( V_10 -> V_14 , V_10 -> V_15 , V_10 -> V_25 ) ;
F_15 ( V_8 , & V_18 ) ;
V_69:
F_4 ( L_13
L_14 ,
F_5 ( V_8 ) , V_8 , V_10 -> V_15 , V_64 ,
V_10 -> V_14 , V_10 -> V_25 , V_10 -> V_26 ,
( unsigned int ) ( V_10 -> V_23 >> 6 ) ,
( unsigned int ) ( V_10 -> V_17 >> 6 ) ) ;
F_43 ( V_8 , & V_10 -> V_44 ) ;
V_8 -> V_70 ( V_8 ) ;
V_10 -> V_42 = F_44 ( T_3 , 4 * V_10 -> V_15 ,
V_36 / V_71 * F_45 ( V_8 ) ) ;
V_35 = F_17 ( V_10 -> V_42 , 2 * V_10 -> V_16 ) ;
F_4 ( L_15
L_16 ,
F_5 ( V_8 ) , V_8 , F_27 ( V_35 ) , V_35 ) ;
F_26 ( V_8 , & V_10 -> V_44 ,
V_45 + F_27 ( V_35 ) ) ;
}
static int F_46 ( struct V_7 * V_8 , T_7 V_72 ,
T_7 V_73 , T_7 * V_74 , T_7 V_75 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_8 V_76 ;
switch ( V_73 ) {
case V_77 :
case V_78 :
if ( V_72 == V_79 )
break;
if ( F_25 ( V_75 != 4 ) ) {
F_47 ( L_17 ,
F_5 ( V_8 ) , V_8 , V_75 , V_73 ) ;
return - V_80 ;
}
V_76 = F_48 ( F_49 ( ( T_8 * ) V_74 ) ) ;
if ( V_73 == V_77 ) {
V_10 -> V_23 = V_76 ;
V_10 -> V_23 <<= 6 ;
F_4 ( L_18 ,
F_5 ( V_8 ) , V_8 , V_76 ) ;
} else {
V_10 -> V_25 = F_50 ( V_76 ) ;
F_4 ( L_19 ,
F_5 ( V_8 ) , V_8 , V_76 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_81 * V_81 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_52 ( V_81 ) ;
V_10 -> V_12 = V_4 ;
V_10 -> V_60 = NULL ;
F_53 ( & V_10 -> V_44 ,
F_22 , ( unsigned long ) V_8 ) ;
return 0 ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_43 ( V_8 , & V_10 -> V_44 ) ;
F_40 ( & V_10 -> V_60 ) ;
}
static void F_55 ( struct V_7 * V_8 , struct V_82 * V_83 )
{
V_83 -> V_84 = F_3 ( V_8 ) -> V_42 ;
V_83 -> V_85 = F_3 ( V_8 ) -> V_15 ;
}
static int F_56 ( struct V_7 * V_8 , const int V_86 , int V_30 ,
T_3 T_9 * V_74 , int T_9 * V_75 )
{
const struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_87 V_88 ;
const void * V_89 ;
switch ( V_86 ) {
case V_90 :
if ( V_30 < sizeof( V_88 ) )
return - V_80 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_91 = V_10 -> V_17 ;
V_88 . V_92 = V_10 -> V_23 ;
V_88 . V_93 = V_10 -> V_26 ;
V_88 . V_94 = V_10 -> V_15 ;
V_88 . V_95 = V_10 -> V_25 ;
V_88 . V_96 = V_10 -> V_42 ;
V_88 . V_97 = V_10 -> V_16 ;
V_30 = sizeof( V_88 ) ;
V_89 = & V_88 ;
break;
default:
return - V_98 ;
}
if ( F_57 ( V_30 , V_75 ) || F_58 ( V_74 , V_89 , V_30 ) )
return - V_99 ;
return 0 ;
}
static const char * F_59 ( enum V_100 V_2 )
{
static const char * const V_101 [] = {
[ V_102 ] = L_20 ,
[ V_103 ] = L_21 ,
} ;
return V_101 [ V_2 ] ;
}
static void F_60 ( struct V_7 * V_8 ,
enum V_100 V_2 )
{
struct V_104 * V_10 = F_61 ( V_8 ) ;
enum V_100 V_11 = V_10 -> V_105 ;
F_4 ( L_4 ,
F_5 ( V_8 ) , V_8 , F_59 ( V_11 ) ,
F_59 ( V_2 ) ) ;
F_6 ( V_2 == V_11 ) ;
V_10 -> V_105 = V_2 ;
}
static void F_62 ( struct V_7 * V_8 ,
const struct V_46 * V_47 ,
enum V_106 V_107 )
{
struct V_104 * V_10 = F_61 ( V_8 ) ;
struct V_48 * V_49 = F_31 ( V_8 ) ;
T_4 V_18 = F_16 () ;
V_29 V_19 = 0 ;
switch ( V_107 ) {
case V_108 :
V_10 -> V_109 = 0 ;
V_10 -> V_110 = ~ 0U ;
break;
case V_111 :
if ( V_10 -> V_109 > 0 )
break;
case V_112 :
V_19 = F_14 ( V_18 , V_10 -> V_113 ) ;
if ( V_19 <= 0 )
F_63 ( L_22 , ( long ) V_19 ) ;
else
V_10 -> V_109 = F_11 ( V_10 -> V_114 , V_19 ) ;
break;
default:
return;
}
F_4 ( L_23 , ( long ) V_19 ,
V_10 -> V_109 , V_10 -> V_110 ) ;
V_10 -> V_113 = V_18 ;
V_10 -> V_115 = F_64 ( V_47 ) -> V_116 ;
V_10 -> V_114 = 0 ;
V_49 -> V_117 = 1 ;
F_65 ( V_8 ) ;
}
static int F_66 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
const struct V_104 * V_10 = F_61 ( V_8 ) ;
T_8 V_118 , V_119 ;
if ( ! ( V_8 -> V_38 == V_120 || V_8 -> V_38 == V_121 ) )
return 0 ;
if ( F_67 ( V_47 ) )
return 0 ;
V_118 = F_68 ( V_10 -> V_109 ) ;
V_119 = F_68 ( V_10 -> V_110 ) ;
if ( F_69 ( V_47 , V_78 ,
& V_119 , sizeof( V_119 ) ) ||
F_69 ( V_47 , V_77 ,
& V_118 , sizeof( V_118 ) ) )
return - 1 ;
return 0 ;
}
static T_3 F_70 ( struct V_7 * V_8 )
{
struct V_104 * V_10 = F_61 ( V_8 ) ;
T_3 V_118 , V_122 , V_19 ;
T_1 V_123 ;
if ( V_10 -> V_124 == 0 ) {
F_47 ( L_24 ) ;
V_10 -> V_124 = V_54 ;
}
V_19 = F_71 ( F_72 ( V_10 -> V_113 ) ) ;
V_118 = F_11 ( V_10 -> V_114 , V_19 ) ;
if ( V_118 == 0 ) {
F_47 ( L_25 ) ;
if ( V_10 -> V_109 == 0 ) {
F_63 ( L_26 ) ;
return ~ 0U ;
}
V_118 = V_10 -> V_109 ;
}
V_123 = F_9 ( V_10 -> V_125 , V_10 -> V_124 ) ;
V_123 = F_11 ( V_123 , V_118 ) ;
V_122 = F_73 ( V_123 ) ;
F_4 ( L_27
L_28 , F_5 ( V_8 ) , V_8 , V_118 , V_122 ) ;
return V_122 == 0 ? ~ 0U : F_9 ( 1 , V_122 ) ;
}
static void F_74 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
struct V_104 * V_10 = F_61 ( V_8 ) ;
enum V_106 V_126 = V_127 ;
const T_1 V_128 = F_31 ( V_8 ) -> V_129 . V_130 ;
const bool V_131 = F_75 ( V_47 ) ;
if ( F_25 ( V_10 -> V_105 == V_102 ) ) {
if ( V_131 ) {
const T_3 V_132 = V_47 -> V_30 - F_64 ( V_47 ) -> V_133 * 4 ;
V_126 = V_108 ;
F_60 ( V_8 , V_103 ) ;
V_10 -> V_125 = V_132 ;
}
goto V_134;
}
if ( F_76 ( & V_10 -> V_135 , V_47 ) )
return;
if ( V_131 ) {
const T_3 V_132 = V_47 -> V_30 - F_64 ( V_47 ) -> V_133 * 4 ;
V_10 -> V_125 = F_20 ( V_10 -> V_125 , V_132 , 9 ) ;
V_10 -> V_114 += V_132 ;
}
if ( F_77 ( & V_10 -> V_135 , & V_10 -> V_136 ,
V_47 , V_128 , F_70 , V_8 ) ) {
V_126 = V_111 ;
goto V_137;
}
if ( F_78 ( & V_10 -> V_135 ) )
return;
if ( F_25 ( ! V_131 ) )
goto V_134;
if ( ! F_79 ( & V_10 -> V_136 ) ) {
const T_3 V_138 = F_80 ( & V_10 -> V_135 , V_47 ) ;
if ( V_138 != 0 )
V_10 -> V_124 = F_20 ( V_10 -> V_124 , V_138 , 9 ) ;
} else if ( F_81 ( & V_10 -> V_136 , V_47 ) ) {
V_126 = V_111 ;
}
if ( F_82 ( F_64 ( V_47 ) -> V_116 , V_10 -> V_115 ) > 3 )
V_126 = V_112 ;
V_134:
F_83 ( & V_10 -> V_135 , V_47 , V_128 ) ;
V_137:
if ( V_126 )
F_62 ( V_8 , V_47 , V_126 ) ;
}
static int F_84 ( struct V_81 * V_81 , struct V_7 * V_8 )
{
struct V_104 * V_10 = F_52 ( V_81 ) ;
V_10 -> V_105 = V_102 ;
F_85 ( & V_10 -> V_136 ) ;
return F_86 ( & V_10 -> V_135 ) ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_104 * V_10 = F_61 ( V_8 ) ;
F_88 ( & V_10 -> V_135 ) ;
F_89 ( & V_10 -> V_136 ) ;
}
static void F_90 ( struct V_7 * V_8 , struct V_82 * V_83 )
{
V_83 -> V_139 = F_61 ( V_8 ) -> V_105 ;
V_83 -> V_140 |= V_141 ;
V_83 -> V_142 = F_61 ( V_8 ) -> V_124 ;
}
static int F_91 ( struct V_7 * V_8 , const int V_86 , int V_30 ,
T_3 T_9 * V_74 , int T_9 * V_75 )
{
const struct V_104 * V_10 = F_61 ( V_8 ) ;
struct V_143 V_144 ;
const void * V_89 ;
switch ( V_86 ) {
case V_145 :
if ( V_30 < sizeof( V_144 ) )
return - V_80 ;
V_144 . V_146 = V_10 -> V_109 ;
V_144 . V_147 = V_10 -> V_124 ;
V_144 . V_148 = F_50 ( V_10 -> V_110 ) ;
V_30 = sizeof( V_144 ) ;
V_89 = & V_144 ;
break;
default:
return - V_98 ;
}
if ( F_57 ( V_30 , V_75 ) || F_58 ( V_74 , V_89 , V_30 ) )
return - V_99 ;
return 0 ;
}
