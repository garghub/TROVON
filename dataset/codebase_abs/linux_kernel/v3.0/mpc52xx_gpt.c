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
void F_13 ( unsigned int V_22 , struct V_23 * V_24 )
{
struct V_3 * V_4 = F_14 ( V_22 ) ;
int V_25 ;
T_1 V_10 ;
V_10 = F_12 ( & V_4 -> V_7 -> V_10 ) & V_11 ;
if ( V_10 ) {
V_25 = F_15 ( V_4 -> V_26 , 0 ) ;
F_16 ( V_25 ) ;
}
}
static int F_17 ( struct V_27 * V_28 , unsigned int V_22 ,
T_2 V_29 )
{
struct V_3 * V_4 = V_28 -> V_30 ;
F_11 ( V_4 -> V_14 , L_2 , V_15 , V_28 , V_22 ) ;
F_18 ( V_22 , V_4 ) ;
F_19 ( V_22 , & V_31 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 , struct V_33 * V_34 ,
const T_1 * V_35 , unsigned int V_36 ,
T_2 * V_37 ,
unsigned int * V_38 )
{
struct V_3 * V_4 = V_28 -> V_30 ;
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
V_4 -> V_26 = F_24 ( V_41 , V_43 , 1 ,
& V_44 , - 1 ) ;
if ( ! V_4 -> V_26 ) {
F_21 ( V_4 -> V_14 , L_5 ) ;
return;
}
V_4 -> V_26 -> V_30 = V_4 ;
F_25 ( V_42 , V_4 ) ;
F_26 ( V_42 , F_13 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_8 = F_12 ( & V_4 -> V_7 -> V_8 ) ;
if ( ( V_8 & V_45 ) == 0 )
F_9 ( & V_4 -> V_7 -> V_8 , V_8 | V_46 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
F_11 ( V_4 -> V_14 , L_6 , V_15 , V_42 ) ;
}
static inline struct V_3 * F_27 ( struct V_47 * V_48 )
{
return F_28 ( V_48 , struct V_3 , V_48 ) ;
}
static int F_29 ( struct V_47 * V_48 , unsigned int V_49 )
{
struct V_3 * V_4 = F_27 ( V_48 ) ;
return ( F_12 ( & V_4 -> V_7 -> V_10 ) >> 8 ) & 1 ;
}
static void
F_30 ( struct V_47 * V_48 , unsigned int V_49 , int V_50 )
{
struct V_3 * V_4 = F_27 ( V_48 ) ;
unsigned long V_5 ;
T_1 V_51 ;
F_11 ( V_4 -> V_14 , L_7 , V_15 , V_49 , V_50 ) ;
V_51 = V_50 ? V_52 : V_53 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_31 ( & V_4 -> V_7 -> V_8 , V_54 , V_51 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
}
static int F_32 ( struct V_47 * V_48 , unsigned int V_49 )
{
struct V_3 * V_4 = F_27 ( V_48 ) ;
unsigned long V_5 ;
F_11 ( V_4 -> V_14 , L_8 , V_15 , V_49 ) ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_7 ( & V_4 -> V_7 -> V_8 , V_54 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static int
F_33 ( struct V_47 * V_48 , unsigned int V_49 , int V_55 )
{
F_30 ( V_48 , V_49 , V_55 ) ;
return 0 ;
}
static void
F_34 ( struct V_3 * V_4 , struct V_33 * V_41 )
{
int V_56 ;
if ( ! F_35 ( V_41 , L_9 , NULL ) )
return;
V_4 -> V_48 . V_57 = F_36 ( V_41 -> V_39 , V_58 ) ;
if ( ! V_4 -> V_48 . V_57 ) {
F_21 ( V_4 -> V_14 , L_10 ) ;
return;
}
V_4 -> V_48 . V_59 = 1 ;
V_4 -> V_48 . V_60 = F_32 ;
V_4 -> V_48 . V_61 = F_33 ;
V_4 -> V_48 . V_62 = F_29 ;
V_4 -> V_48 . V_63 = F_30 ;
V_4 -> V_48 . V_64 = - 1 ;
V_4 -> V_48 . V_65 = V_41 ;
F_31 ( & V_4 -> V_7 -> V_8 , V_45 ,
V_66 ) ;
V_56 = F_37 ( & V_4 -> V_48 ) ;
if ( V_56 )
F_21 ( V_4 -> V_14 , L_11 , V_56 ) ;
F_11 ( V_4 -> V_14 , L_12 , V_15 ) ;
}
static void
F_34 ( struct V_3 * V_67 , struct V_33 * V_68 ) { }
struct V_3 * F_38 ( int V_16 )
{
struct V_3 * V_4 ;
struct V_69 * V_70 ;
F_39 ( & V_71 ) ;
F_40 (pos, &mpc52xx_gpt_list) {
V_4 = F_28 ( V_70 , struct V_3 , V_72 ) ;
if ( V_4 -> V_26 && V_16 == F_15 ( V_4 -> V_26 , 0 ) ) {
F_41 ( & V_71 ) ;
return V_4 ;
}
}
F_41 ( & V_71 ) ;
return NULL ;
}
static int F_42 ( struct V_3 * V_4 , T_3 V_73 ,
int V_74 , int V_75 )
{
T_1 V_76 , V_63 ;
T_3 V_77 ;
T_1 V_78 ;
unsigned long V_5 ;
V_76 = V_45 | V_79 ;
V_63 = V_66 | V_80 ;
if ( V_75 ) {
V_76 |= V_9 ;
V_63 |= V_81 ;
} else if ( V_74 )
V_63 |= V_79 ;
V_77 = V_73 * ( T_3 ) V_4 -> V_82 ;
F_43 ( V_77 , 1000000000 ) ;
if ( V_77 > 0xffffffff )
return - V_40 ;
V_78 = ( V_77 >> 16 ) + 1 ;
F_43 ( V_77 , V_78 ) ;
if ( V_77 > 0xffff ) {
F_44 ( L_13 ,
V_78 , V_77 ) ;
return - V_40 ;
}
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( V_75 )
V_4 -> V_83 |= V_84 ;
else if ( ( V_4 -> V_83 & V_84 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_85 ;
}
F_9 ( & V_4 -> V_7 -> V_86 , V_78 << 16 | V_77 ) ;
F_31 ( & V_4 -> V_7 -> V_8 , V_76 , V_63 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_4 , T_3 V_73 ,
int V_74 )
{
return F_42 ( V_4 , V_73 , V_74 , 0 ) ;
}
int F_46 ( struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
if ( ( V_4 -> V_83 & V_84 ) != 0 ) {
F_5 ( & V_4 -> V_6 , V_5 ) ;
return - V_85 ;
}
F_7 ( & V_4 -> V_7 -> V_8 , V_80 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
T_3 F_47 ( struct V_3 * V_4 )
{
T_3 V_73 ;
T_3 V_78 ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_73 = F_12 ( & V_4 -> V_7 -> V_86 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
V_78 = V_73 >> 16 ;
V_73 &= 0xffff ;
if ( V_78 == 0 )
V_78 = 0x10000 ;
V_73 = V_73 * V_78 * 1000000000ULL ;
F_43 ( V_73 , ( T_3 ) V_4 -> V_82 ) ;
return V_73 ;
}
static inline void F_48 ( struct V_3 * V_87 )
{
unsigned long V_5 ;
F_3 ( & V_87 -> V_6 , V_5 ) ;
F_49 ( ( V_88 * ) & V_87 -> V_7 -> V_8 , V_89 ) ;
F_5 ( & V_87 -> V_6 , V_5 ) ;
}
static T_4 F_50 ( struct V_90 * V_90 , const char T_5 * V_91 ,
T_6 V_92 , T_7 * V_93 )
{
struct V_3 * V_87 = V_90 -> V_94 ;
F_48 ( V_87 ) ;
return 0 ;
}
static long F_51 ( struct V_90 * V_90 , unsigned int V_95 ,
unsigned long V_96 )
{
struct V_3 * V_87 = V_90 -> V_94 ;
int T_5 * V_91 = ( int T_5 * ) V_96 ;
int V_97 ;
T_3 V_98 ;
int V_99 = 0 ;
switch ( V_95 ) {
case V_100 :
V_99 = F_52 ( V_91 , & V_101 ,
sizeof( V_101 ) ) ;
if ( V_99 )
V_99 = - V_102 ;
break;
case V_103 :
case V_104 :
V_99 = F_53 ( 0 , V_91 ) ;
break;
case V_105 :
F_48 ( V_87 ) ;
break;
case V_106 :
V_99 = F_54 ( V_97 , V_91 ) ;
if ( V_99 )
break;
V_98 = ( T_3 ) V_97 * 1000000000ULL ;
V_99 = F_42 ( V_87 , V_98 , 0 , 1 ) ;
if ( V_99 )
break;
case V_107 :
V_98 =
F_47 ( V_87 ) + 500000000ULL ;
F_43 ( V_98 , 1000000000ULL ) ;
V_97 = ( int ) V_98 ;
V_99 = F_53 ( V_97 , V_91 ) ;
break;
default:
V_99 = - V_108 ;
}
return V_99 ;
}
static int F_55 ( struct V_109 * V_109 , struct V_90 * V_90 )
{
int V_99 ;
if ( ! V_110 )
return - V_111 ;
if ( F_56 ( 0 , & V_112 ) )
return - V_85 ;
V_99 = F_42 ( V_110 , 30ULL * 1000000000ULL ,
0 , 1 ) ;
if ( V_99 ) {
F_57 ( 0 , & V_112 ) ;
return V_99 ;
}
V_90 -> V_94 = V_110 ;
return F_58 ( V_109 , V_90 ) ;
}
static int F_59 ( struct V_109 * V_109 , struct V_90 * V_90 )
{
#if ! F_60 ( V_113 )
struct V_3 * V_87 = V_90 -> V_94 ;
unsigned long V_5 ;
F_3 ( & V_87 -> V_6 , V_5 ) ;
F_7 ( & V_87 -> V_7 -> V_8 ,
V_80 | V_81 ) ;
V_87 -> V_83 &= ~ V_84 ;
F_5 ( & V_87 -> V_6 , V_5 ) ;
#endif
F_57 ( 0 , & V_112 ) ;
return 0 ;
}
static int T_8 F_61 ( void )
{
int V_114 ;
V_114 = F_62 ( & V_115 ) ;
if ( V_114 )
F_44 ( L_14 , V_116 ) ;
else
F_63 ( L_15 , V_116 ) ;
return V_114 ;
}
static int F_64 ( struct V_3 * V_4 ,
const T_1 * V_73 )
{
T_3 V_98 ;
V_110 = V_4 ;
if ( ! V_73 || * V_73 == 0 )
return 0 ;
V_98 = ( T_3 ) * V_73 * 1000000000ULL ;
if ( F_42 ( V_4 , V_98 , 0 , 1 ) )
F_65 ( V_4 -> V_14 , L_16 ) ;
else
F_66 ( V_4 -> V_14 , L_17 , * V_73 ) ;
return 0 ;
}
static int T_8 F_61 ( void )
{
return 0 ;
}
static inline int F_64 ( struct V_3 * V_4 ,
const T_1 * V_73 )
{
return 0 ;
}
static int T_8 F_67 ( struct V_117 * V_118 )
{
struct V_3 * V_4 ;
V_4 = F_68 ( sizeof *V_4 , V_58 ) ;
if ( ! V_4 )
return - V_119 ;
F_69 ( & V_4 -> V_6 ) ;
V_4 -> V_14 = & V_118 -> V_14 ;
V_4 -> V_82 = F_70 ( V_118 -> V_14 . V_65 ) ;
V_4 -> V_7 = F_71 ( V_118 -> V_14 . V_65 , 0 ) ;
if ( ! V_4 -> V_7 ) {
F_72 ( V_4 ) ;
return - V_119 ;
}
F_73 ( & V_118 -> V_14 , V_4 ) ;
F_34 ( V_4 , V_118 -> V_14 . V_65 ) ;
F_22 ( V_4 , V_118 -> V_14 . V_65 ) ;
F_39 ( & V_71 ) ;
F_74 ( & V_4 -> V_72 , & V_120 ) ;
F_41 ( & V_71 ) ;
if ( F_75 ( V_118 -> V_14 . V_65 , L_18 , NULL ) ||
F_75 ( V_118 -> V_14 . V_65 , L_19 , NULL ) ) {
const T_1 * V_121 ;
V_4 -> V_83 = V_122 ;
V_121 = F_75 ( V_118 -> V_14 . V_65 ,
L_20 , NULL ) ;
if ( V_121 ) {
F_66 ( V_4 -> V_14 , L_21 ) ;
V_4 -> V_83 |= V_84 ;
} else
F_66 ( V_4 -> V_14 , L_22 ) ;
F_64 ( V_4 , V_121 ) ;
}
return 0 ;
}
static int F_76 ( struct V_117 * V_118 )
{
return - V_85 ;
}
static int T_9 F_77 ( void )
{
return F_78 ( & V_123 ) ;
}
