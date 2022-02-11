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
F_21 ( V_4 -> V_14 , L_4 , V_34 ) ;
return - V_39 ;
}
* V_37 = 0 ;
* V_38 = V_35 [ 0 ] ;
return 0 ;
}
static void
F_22 ( struct V_3 * V_4 , struct V_33 * V_40 )
{
int V_41 ;
unsigned long V_5 ;
T_1 V_8 ;
V_41 = F_23 ( V_40 , 0 ) ;
if ( ! V_41 )
return;
V_4 -> V_25 = F_24 ( V_40 , 1 , & V_42 , V_4 ) ;
if ( ! V_4 -> V_25 ) {
F_21 ( V_4 -> V_14 , L_5 ) ;
return;
}
F_25 ( V_41 , V_4 ) ;
F_26 ( V_41 , F_13 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_8 = F_12 ( & V_4 -> V_7 -> V_8 ) ;
if ( ( V_8 & V_43 ) == 0 )
F_9 ( & V_4 -> V_7 -> V_8 , V_8 | V_44 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
F_11 ( V_4 -> V_14 , L_6 , V_15 , V_41 ) ;
}
static int F_27 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_3 * V_4 = F_28 ( V_46 ) ;
return ( F_12 ( & V_4 -> V_7 -> V_10 ) >> 8 ) & 1 ;
}
static void
F_29 ( struct V_45 * V_46 , unsigned int V_47 , int V_48 )
{
struct V_3 * V_4 = F_28 ( V_46 ) ;
unsigned long V_5 ;
T_1 V_49 ;
F_11 ( V_4 -> V_14 , L_7 , V_15 , V_47 , V_48 ) ;
V_49 = V_48 ? V_50 : V_51 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_30 ( & V_4 -> V_7 -> V_8 , V_52 , V_49 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static int F_31 ( struct V_45 * V_46 , unsigned int V_47 )
{
struct V_3 * V_4 = F_28 ( V_46 ) ;
unsigned long V_5 ;
F_11 ( V_4 -> V_14 , L_8 , V_15 , V_47 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_7 ( & V_4 -> V_7 -> V_8 , V_52 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static int
F_32 ( struct V_45 * V_46 , unsigned int V_47 , int V_53 )
{
F_29 ( V_46 , V_47 , V_53 ) ;
return 0 ;
}
static void
F_33 ( struct V_3 * V_4 , struct V_33 * V_40 )
{
int V_54 ;
if ( ! F_34 ( V_40 , L_9 , NULL ) )
return;
V_4 -> V_46 . V_55 = F_35 ( V_56 , L_10 , V_40 ) ;
if ( ! V_4 -> V_46 . V_55 ) {
F_21 ( V_4 -> V_14 , L_11 ) ;
return;
}
V_4 -> V_46 . V_57 = 1 ;
V_4 -> V_46 . V_58 = F_31 ;
V_4 -> V_46 . V_59 = F_32 ;
V_4 -> V_46 . V_60 = F_27 ;
V_4 -> V_46 . V_61 = F_29 ;
V_4 -> V_46 . V_62 = - 1 ;
V_4 -> V_46 . V_63 = V_40 ;
F_30 ( & V_4 -> V_7 -> V_8 , V_43 ,
V_64 ) ;
V_54 = F_36 ( & V_4 -> V_46 , V_4 ) ;
if ( V_54 )
F_21 ( V_4 -> V_14 , L_12 , V_54 ) ;
F_11 ( V_4 -> V_14 , L_13 , V_15 ) ;
}
static void
F_33 ( struct V_3 * V_65 , struct V_33 * V_66 ) { }
struct V_3 * F_37 ( int V_16 )
{
struct V_3 * V_4 ;
struct V_67 * V_68 ;
F_38 ( & V_69 ) ;
F_39 (pos, &mpc52xx_gpt_list) {
V_4 = F_40 ( V_68 , struct V_3 , V_70 ) ;
if ( V_4 -> V_25 && V_16 == F_15 ( V_4 -> V_25 , 0 ) ) {
F_41 ( & V_69 ) ;
return V_4 ;
}
}
F_41 ( & V_69 ) ;
return NULL ;
}
static int F_42 ( struct V_3 * V_4 , T_3 V_71 ,
int V_72 , int V_73 )
{
T_1 V_74 , V_61 ;
T_3 V_75 ;
T_1 V_76 ;
unsigned long V_5 ;
V_74 = V_43 | V_77 ;
V_61 = V_64 | V_78 ;
if ( V_73 ) {
V_74 |= V_9 ;
V_61 |= V_79 ;
} else if ( V_72 )
V_61 |= V_77 ;
V_75 = V_71 * ( T_3 ) V_4 -> V_80 ;
F_43 ( V_75 , 1000000000 ) ;
if ( V_75 > 0xffffffff )
return - V_39 ;
V_76 = ( V_75 >> 16 ) + 1 ;
F_43 ( V_75 , V_76 ) ;
if ( V_75 > 0xffff ) {
F_44 ( L_14 ,
V_76 , V_75 ) ;
return - V_39 ;
}
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_73 )
V_4 -> V_81 |= V_82 ;
else if ( ( V_4 -> V_81 & V_82 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_83 ;
}
F_9 ( & V_4 -> V_7 -> V_84 , V_76 << 16 | V_75 ) ;
F_30 ( & V_4 -> V_7 -> V_8 , V_74 , V_61 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 , T_3 V_71 ,
int V_72 )
{
return F_42 ( V_4 , V_71 , V_72 , 0 ) ;
}
int F_46 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( ( V_4 -> V_81 & V_82 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_83 ;
}
F_7 ( & V_4 -> V_7 -> V_8 , V_78 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
T_3 F_47 ( struct V_3 * V_4 )
{
T_3 V_71 ;
T_3 V_76 ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_71 = F_12 ( & V_4 -> V_7 -> V_84 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
V_76 = V_71 >> 16 ;
V_71 &= 0xffff ;
if ( V_76 == 0 )
V_76 = 0x10000 ;
V_71 = V_71 * V_76 * 1000000000ULL ;
F_43 ( V_71 , ( T_3 ) V_4 -> V_80 ) ;
return V_71 ;
}
static inline void F_48 ( struct V_3 * V_85 )
{
unsigned long V_5 ;
F_3 ( & V_85 -> V_6 , V_5 ) ;
F_49 ( ( V_86 * ) & V_85 -> V_7 -> V_8 , V_87 ) ;
F_5 ( & V_85 -> V_6 , V_5 ) ;
}
static T_4 F_50 ( struct V_88 * V_88 , const char T_5 * V_89 ,
T_6 V_90 , T_7 * V_91 )
{
struct V_3 * V_85 = V_88 -> V_92 ;
F_48 ( V_85 ) ;
return 0 ;
}
static long F_51 ( struct V_88 * V_88 , unsigned int V_93 ,
unsigned long V_94 )
{
struct V_3 * V_85 = V_88 -> V_92 ;
int T_5 * V_89 = ( int T_5 * ) V_94 ;
int V_95 ;
T_3 V_96 ;
int V_97 = 0 ;
switch ( V_93 ) {
case V_98 :
V_97 = F_52 ( V_89 , & V_99 ,
sizeof( V_99 ) ) ;
if ( V_97 )
V_97 = - V_100 ;
break;
case V_101 :
case V_102 :
V_97 = F_53 ( 0 , V_89 ) ;
break;
case V_103 :
F_48 ( V_85 ) ;
break;
case V_104 :
V_97 = F_54 ( V_95 , V_89 ) ;
if ( V_97 )
break;
V_96 = ( T_3 ) V_95 * 1000000000ULL ;
V_97 = F_42 ( V_85 , V_96 , 0 , 1 ) ;
if ( V_97 )
break;
case V_105 :
V_96 =
F_47 ( V_85 ) + 500000000ULL ;
F_43 ( V_96 , 1000000000ULL ) ;
V_95 = ( int ) V_96 ;
V_97 = F_53 ( V_95 , V_89 ) ;
break;
default:
V_97 = - V_106 ;
}
return V_97 ;
}
static int F_55 ( struct V_107 * V_107 , struct V_88 * V_88 )
{
int V_97 ;
if ( ! V_108 )
return - V_109 ;
if ( F_56 ( 0 , & V_110 ) )
return - V_83 ;
V_97 = F_42 ( V_108 , 30ULL * 1000000000ULL ,
0 , 1 ) ;
if ( V_97 ) {
F_57 ( 0 , & V_110 ) ;
return V_97 ;
}
V_88 -> V_92 = V_108 ;
return F_58 ( V_107 , V_88 ) ;
}
static int F_59 ( struct V_107 * V_107 , struct V_88 * V_88 )
{
#if ! F_60 ( V_111 )
struct V_3 * V_85 = V_88 -> V_92 ;
unsigned long V_5 ;
F_3 ( & V_85 -> V_6 , V_5 ) ;
F_7 ( & V_85 -> V_7 -> V_8 ,
V_78 | V_79 ) ;
V_85 -> V_81 &= ~ V_82 ;
F_5 ( & V_85 -> V_6 , V_5 ) ;
#endif
F_57 ( 0 , & V_110 ) ;
return 0 ;
}
static int F_61 ( void )
{
int V_112 ;
V_112 = F_62 ( & V_113 ) ;
if ( V_112 )
F_44 ( L_15 , V_114 ) ;
else
F_63 ( L_16 , V_114 ) ;
return V_112 ;
}
static int F_64 ( struct V_3 * V_4 ,
const T_1 * V_71 )
{
T_3 V_96 ;
V_108 = V_4 ;
if ( ! V_71 || * V_71 == 0 )
return 0 ;
V_96 = ( T_3 ) * V_71 * 1000000000ULL ;
if ( F_42 ( V_4 , V_96 , 0 , 1 ) )
F_65 ( V_4 -> V_14 , L_17 ) ;
else
F_66 ( V_4 -> V_14 , L_18 , * V_71 ) ;
return 0 ;
}
static int F_61 ( void )
{
return 0 ;
}
static inline int F_64 ( struct V_3 * V_4 ,
const T_1 * V_71 )
{
return 0 ;
}
static int F_67 ( struct V_115 * V_116 )
{
struct V_3 * V_4 ;
V_4 = F_68 ( & V_116 -> V_14 , sizeof *V_4 , V_56 ) ;
if ( ! V_4 )
return - V_117 ;
F_69 ( & V_4 -> V_6 ) ;
V_4 -> V_14 = & V_116 -> V_14 ;
V_4 -> V_80 = F_70 ( V_116 -> V_14 . V_63 ) ;
V_4 -> V_7 = F_71 ( V_116 -> V_14 . V_63 , 0 ) ;
if ( ! V_4 -> V_7 )
return - V_117 ;
F_72 ( & V_116 -> V_14 , V_4 ) ;
F_33 ( V_4 , V_116 -> V_14 . V_63 ) ;
F_22 ( V_4 , V_116 -> V_14 . V_63 ) ;
F_38 ( & V_69 ) ;
F_73 ( & V_4 -> V_70 , & V_118 ) ;
F_41 ( & V_69 ) ;
if ( F_74 ( V_116 -> V_14 . V_63 , L_19 , NULL ) ||
F_74 ( V_116 -> V_14 . V_63 , L_20 , NULL ) ) {
const T_1 * V_119 ;
V_4 -> V_81 = V_120 ;
V_119 = F_74 ( V_116 -> V_14 . V_63 ,
L_21 , NULL ) ;
if ( V_119 ) {
F_66 ( V_4 -> V_14 , L_22 ) ;
V_4 -> V_81 |= V_82 ;
} else
F_66 ( V_4 -> V_14 , L_23 ) ;
F_64 ( V_4 , V_119 ) ;
}
return 0 ;
}
static int F_75 ( struct V_115 * V_116 )
{
return - V_83 ;
}
static int T_8 F_76 ( void )
{
return F_77 ( & V_121 ) ;
}
