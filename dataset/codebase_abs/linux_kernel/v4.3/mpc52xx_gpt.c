static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_4 ( & V_4 -> V_7 -> V_8 , V_9 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_7 ( & V_4 -> V_7 -> V_8 , V_9 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_9 ( & V_4 -> V_7 -> V_10 , V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
T_1 V_13 ;
F_11 ( V_4 -> V_14 , L_1 , V_15 , V_2 -> V_16 , V_12 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_13 = F_12 ( & V_4 -> V_7 -> V_8 ) & ~ V_17 ;
if ( V_12 & V_18 )
V_13 |= V_19 ;
if ( V_12 & V_20 )
V_13 |= V_21 ;
F_9 ( & V_4 -> V_7 -> V_8 , V_13 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_14 ( V_23 ) ;
int V_24 ;
T_1 V_10 ;
V_10 = F_12 ( & V_4 -> V_7 -> V_10 ) & V_11 ;
if ( V_10 ) {
V_24 = F_15 ( V_4 -> V_25 , 0 ) ;
F_16 ( V_24 ) ;
}
}
static int F_17 ( struct V_26 * V_27 , unsigned int V_28 ,
T_2 V_29 )
{
struct V_3 * V_4 = V_27 -> V_30 ;
F_11 ( V_4 -> V_14 , L_2 , V_15 , V_27 , V_28 ) ;
F_18 ( V_28 , V_4 ) ;
F_19 ( V_28 , & V_31 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 , struct V_33 * V_34 ,
const T_1 * V_35 , unsigned int V_36 ,
T_2 * V_37 ,
unsigned int * V_38 )
{
struct V_3 * V_4 = V_27 -> V_30 ;
F_11 ( V_4 -> V_14 , L_3 , V_15 , V_35 [ 0 ] ) ;
if ( ( V_36 < 1 ) || ( V_35 [ 0 ] > 3 ) ) {
F_21 ( V_4 -> V_14 , L_4 , V_34 -> V_39 ) ;
return - V_40 ;
}
* V_37 = 0 ;
* V_38 = V_35 [ 0 ] ;
return 0 ;
}
static void
F_22 ( struct V_3 * V_4 , struct V_33 * V_41 )
{
int V_42 ;
unsigned long V_5 ;
T_1 V_8 ;
V_42 = F_23 ( V_41 , 0 ) ;
if ( ! V_42 )
return;
V_4 -> V_25 = F_24 ( V_41 , 1 , & V_43 , V_4 ) ;
if ( ! V_4 -> V_25 ) {
F_21 ( V_4 -> V_14 , L_5 ) ;
return;
}
F_25 ( V_42 , V_4 ) ;
F_26 ( V_42 , F_13 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_8 = F_12 ( & V_4 -> V_7 -> V_8 ) ;
if ( ( V_8 & V_44 ) == 0 )
F_9 ( & V_4 -> V_7 -> V_8 , V_8 | V_45 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
F_11 ( V_4 -> V_14 , L_6 , V_15 , V_42 ) ;
}
static inline struct V_3 * F_27 ( struct V_46 * V_47 )
{
return F_28 ( V_47 , struct V_3 , V_47 ) ;
}
static int F_29 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_3 * V_4 = F_27 ( V_47 ) ;
return ( F_12 ( & V_4 -> V_7 -> V_10 ) >> 8 ) & 1 ;
}
static void
F_30 ( struct V_46 * V_47 , unsigned int V_48 , int V_49 )
{
struct V_3 * V_4 = F_27 ( V_47 ) ;
unsigned long V_5 ;
T_1 V_50 ;
F_11 ( V_4 -> V_14 , L_7 , V_15 , V_48 , V_49 ) ;
V_50 = V_49 ? V_51 : V_52 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_31 ( & V_4 -> V_7 -> V_8 , V_53 , V_50 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static int F_32 ( struct V_46 * V_47 , unsigned int V_48 )
{
struct V_3 * V_4 = F_27 ( V_47 ) ;
unsigned long V_5 ;
F_11 ( V_4 -> V_14 , L_8 , V_15 , V_48 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_7 ( & V_4 -> V_7 -> V_8 , V_53 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static int
F_33 ( struct V_46 * V_47 , unsigned int V_48 , int V_54 )
{
F_30 ( V_47 , V_48 , V_54 ) ;
return 0 ;
}
static void
F_34 ( struct V_3 * V_4 , struct V_33 * V_41 )
{
int V_55 ;
if ( ! F_35 ( V_41 , L_9 , NULL ) )
return;
V_4 -> V_47 . V_56 = F_36 ( V_41 -> V_39 , V_57 ) ;
if ( ! V_4 -> V_47 . V_56 ) {
F_21 ( V_4 -> V_14 , L_10 ) ;
return;
}
V_4 -> V_47 . V_58 = 1 ;
V_4 -> V_47 . V_59 = F_32 ;
V_4 -> V_47 . V_60 = F_33 ;
V_4 -> V_47 . V_61 = F_29 ;
V_4 -> V_47 . V_62 = F_30 ;
V_4 -> V_47 . V_63 = - 1 ;
V_4 -> V_47 . V_64 = V_41 ;
F_31 ( & V_4 -> V_7 -> V_8 , V_44 ,
V_65 ) ;
V_55 = F_37 ( & V_4 -> V_47 ) ;
if ( V_55 )
F_21 ( V_4 -> V_14 , L_11 , V_55 ) ;
F_11 ( V_4 -> V_14 , L_12 , V_15 ) ;
}
static void
F_34 ( struct V_3 * V_66 , struct V_33 * V_67 ) { }
struct V_3 * F_38 ( int V_16 )
{
struct V_3 * V_4 ;
struct V_68 * V_69 ;
F_39 ( & V_70 ) ;
F_40 (pos, &mpc52xx_gpt_list) {
V_4 = F_28 ( V_69 , struct V_3 , V_71 ) ;
if ( V_4 -> V_25 && V_16 == F_15 ( V_4 -> V_25 , 0 ) ) {
F_41 ( & V_70 ) ;
return V_4 ;
}
}
F_41 ( & V_70 ) ;
return NULL ;
}
static int F_42 ( struct V_3 * V_4 , T_3 V_72 ,
int V_73 , int V_74 )
{
T_1 V_75 , V_62 ;
T_3 V_76 ;
T_1 V_77 ;
unsigned long V_5 ;
V_75 = V_44 | V_78 ;
V_62 = V_65 | V_79 ;
if ( V_74 ) {
V_75 |= V_9 ;
V_62 |= V_80 ;
} else if ( V_73 )
V_62 |= V_78 ;
V_76 = V_72 * ( T_3 ) V_4 -> V_81 ;
F_43 ( V_76 , 1000000000 ) ;
if ( V_76 > 0xffffffff )
return - V_40 ;
V_77 = ( V_76 >> 16 ) + 1 ;
F_43 ( V_76 , V_77 ) ;
if ( V_76 > 0xffff ) {
F_44 ( L_13 ,
V_77 , V_76 ) ;
return - V_40 ;
}
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_74 )
V_4 -> V_82 |= V_83 ;
else if ( ( V_4 -> V_82 & V_83 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_84 ;
}
F_9 ( & V_4 -> V_7 -> V_85 , V_77 << 16 | V_76 ) ;
F_31 ( & V_4 -> V_7 -> V_8 , V_75 , V_62 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 , T_3 V_72 ,
int V_73 )
{
return F_42 ( V_4 , V_72 , V_73 , 0 ) ;
}
int F_46 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( ( V_4 -> V_82 & V_83 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_84 ;
}
F_7 ( & V_4 -> V_7 -> V_8 , V_79 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
T_3 F_47 ( struct V_3 * V_4 )
{
T_3 V_72 ;
T_3 V_77 ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_72 = F_12 ( & V_4 -> V_7 -> V_85 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
V_77 = V_72 >> 16 ;
V_72 &= 0xffff ;
if ( V_77 == 0 )
V_77 = 0x10000 ;
V_72 = V_72 * V_77 * 1000000000ULL ;
F_43 ( V_72 , ( T_3 ) V_4 -> V_81 ) ;
return V_72 ;
}
static inline void F_48 ( struct V_3 * V_86 )
{
unsigned long V_5 ;
F_3 ( & V_86 -> V_6 , V_5 ) ;
F_49 ( ( V_87 * ) & V_86 -> V_7 -> V_8 , V_88 ) ;
F_5 ( & V_86 -> V_6 , V_5 ) ;
}
static T_4 F_50 ( struct V_89 * V_89 , const char T_5 * V_90 ,
T_6 V_91 , T_7 * V_92 )
{
struct V_3 * V_86 = V_89 -> V_93 ;
F_48 ( V_86 ) ;
return 0 ;
}
static long F_51 ( struct V_89 * V_89 , unsigned int V_94 ,
unsigned long V_95 )
{
struct V_3 * V_86 = V_89 -> V_93 ;
int T_5 * V_90 = ( int T_5 * ) V_95 ;
int V_96 ;
T_3 V_97 ;
int V_98 = 0 ;
switch ( V_94 ) {
case V_99 :
V_98 = F_52 ( V_90 , & V_100 ,
sizeof( V_100 ) ) ;
if ( V_98 )
V_98 = - V_101 ;
break;
case V_102 :
case V_103 :
V_98 = F_53 ( 0 , V_90 ) ;
break;
case V_104 :
F_48 ( V_86 ) ;
break;
case V_105 :
V_98 = F_54 ( V_96 , V_90 ) ;
if ( V_98 )
break;
V_97 = ( T_3 ) V_96 * 1000000000ULL ;
V_98 = F_42 ( V_86 , V_97 , 0 , 1 ) ;
if ( V_98 )
break;
case V_106 :
V_97 =
F_47 ( V_86 ) + 500000000ULL ;
F_43 ( V_97 , 1000000000ULL ) ;
V_96 = ( int ) V_97 ;
V_98 = F_53 ( V_96 , V_90 ) ;
break;
default:
V_98 = - V_107 ;
}
return V_98 ;
}
static int F_55 ( struct V_108 * V_108 , struct V_89 * V_89 )
{
int V_98 ;
if ( ! V_109 )
return - V_110 ;
if ( F_56 ( 0 , & V_111 ) )
return - V_84 ;
V_98 = F_42 ( V_109 , 30ULL * 1000000000ULL ,
0 , 1 ) ;
if ( V_98 ) {
F_57 ( 0 , & V_111 ) ;
return V_98 ;
}
V_89 -> V_93 = V_109 ;
return F_58 ( V_108 , V_89 ) ;
}
static int F_59 ( struct V_108 * V_108 , struct V_89 * V_89 )
{
#if ! F_60 ( V_112 )
struct V_3 * V_86 = V_89 -> V_93 ;
unsigned long V_5 ;
F_3 ( & V_86 -> V_6 , V_5 ) ;
F_7 ( & V_86 -> V_7 -> V_8 ,
V_79 | V_80 ) ;
V_86 -> V_82 &= ~ V_83 ;
F_5 ( & V_86 -> V_6 , V_5 ) ;
#endif
F_57 ( 0 , & V_111 ) ;
return 0 ;
}
static int F_61 ( void )
{
int V_113 ;
V_113 = F_62 ( & V_114 ) ;
if ( V_113 )
F_44 ( L_14 , V_115 ) ;
else
F_63 ( L_15 , V_115 ) ;
return V_113 ;
}
static int F_64 ( struct V_3 * V_4 ,
const T_1 * V_72 )
{
T_3 V_97 ;
V_109 = V_4 ;
if ( ! V_72 || * V_72 == 0 )
return 0 ;
V_97 = ( T_3 ) * V_72 * 1000000000ULL ;
if ( F_42 ( V_4 , V_97 , 0 , 1 ) )
F_65 ( V_4 -> V_14 , L_16 ) ;
else
F_66 ( V_4 -> V_14 , L_17 , * V_72 ) ;
return 0 ;
}
static int F_61 ( void )
{
return 0 ;
}
static inline int F_64 ( struct V_3 * V_4 ,
const T_1 * V_72 )
{
return 0 ;
}
static int F_67 ( struct V_116 * V_117 )
{
struct V_3 * V_4 ;
V_4 = F_68 ( sizeof *V_4 , V_57 ) ;
if ( ! V_4 )
return - V_118 ;
F_69 ( & V_4 -> V_6 ) ;
V_4 -> V_14 = & V_117 -> V_14 ;
V_4 -> V_81 = F_70 ( V_117 -> V_14 . V_64 ) ;
V_4 -> V_7 = F_71 ( V_117 -> V_14 . V_64 , 0 ) ;
if ( ! V_4 -> V_7 ) {
F_72 ( V_4 ) ;
return - V_118 ;
}
F_73 ( & V_117 -> V_14 , V_4 ) ;
F_34 ( V_4 , V_117 -> V_14 . V_64 ) ;
F_22 ( V_4 , V_117 -> V_14 . V_64 ) ;
F_39 ( & V_70 ) ;
F_74 ( & V_4 -> V_71 , & V_119 ) ;
F_41 ( & V_70 ) ;
if ( F_75 ( V_117 -> V_14 . V_64 , L_18 , NULL ) ||
F_75 ( V_117 -> V_14 . V_64 , L_19 , NULL ) ) {
const T_1 * V_120 ;
V_4 -> V_82 = V_121 ;
V_120 = F_75 ( V_117 -> V_14 . V_64 ,
L_20 , NULL ) ;
if ( V_120 ) {
F_66 ( V_4 -> V_14 , L_21 ) ;
V_4 -> V_82 |= V_83 ;
} else
F_66 ( V_4 -> V_14 , L_22 ) ;
F_64 ( V_4 , V_120 ) ;
}
return 0 ;
}
static int F_76 ( struct V_116 * V_117 )
{
return - V_84 ;
}
static int T_8 F_77 ( void )
{
return F_78 ( & V_122 ) ;
}
