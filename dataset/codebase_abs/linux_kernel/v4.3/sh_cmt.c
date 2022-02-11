static unsigned long F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
return F_2 ( V_1 + ( V_2 << 1 ) ) ;
}
static unsigned long F_3 ( void T_1 * V_1 , unsigned long V_2 )
{
return F_4 ( V_1 + ( V_2 << 2 ) ) ;
}
static void F_5 ( void T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
F_6 ( V_3 , V_1 + ( V_2 << 1 ) ) ;
}
static void F_7 ( void T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
F_8 ( V_3 , V_1 + ( V_2 << 2 ) ) ;
}
static inline unsigned long F_9 ( struct V_4 * V_5 )
{
if ( V_5 -> V_6 )
return V_5 -> V_7 -> V_8 -> V_9 ( V_5 -> V_6 , 0 ) ;
else
return V_5 -> V_7 -> V_8 -> V_9 ( V_5 -> V_7 -> V_10 , 0 ) ;
}
static inline void F_10 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
if ( V_5 -> V_6 )
V_5 -> V_7 -> V_8 -> V_11 ( V_5 -> V_6 , 0 , V_3 ) ;
else
V_5 -> V_7 -> V_8 -> V_11 ( V_5 -> V_7 -> V_10 , 0 , V_3 ) ;
}
static inline unsigned long F_11 ( struct V_4 * V_5 )
{
return V_5 -> V_7 -> V_8 -> V_9 ( V_5 -> V_12 , V_13 ) ;
}
static inline void F_12 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_7 -> V_8 -> V_11 ( V_5 -> V_12 , V_13 , V_3 ) ;
}
static inline unsigned long F_13 ( struct V_4 * V_5 )
{
return V_5 -> V_7 -> V_8 -> V_14 ( V_5 -> V_12 , V_15 ) ;
}
static inline void F_14 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_7 -> V_8 -> V_16 ( V_5 -> V_12 , V_15 , V_3 ) ;
}
static inline void F_15 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_7 -> V_8 -> V_16 ( V_5 -> V_12 , V_17 , V_3 ) ;
}
static unsigned long F_16 ( struct V_4 * V_5 ,
int * V_18 )
{
unsigned long V_19 , V_20 , V_21 ;
int V_22 , V_23 ;
V_22 = F_11 ( V_5 ) & V_5 -> V_7 -> V_8 -> V_24 ;
do {
V_23 = V_22 ;
V_19 = F_13 ( V_5 ) ;
V_20 = F_13 ( V_5 ) ;
V_21 = F_13 ( V_5 ) ;
V_22 = F_11 ( V_5 ) & V_5 -> V_7 -> V_8 -> V_24 ;
} while ( F_17 ( ( V_22 != V_23 ) || ( V_19 > V_20 && V_19 < V_21 )
|| ( V_20 > V_21 && V_20 < V_19 ) || ( V_21 > V_19 && V_21 < V_20 ) ) );
* V_18 = V_22 ;
return V_20 ;
}
static void F_18 ( struct V_4 * V_5 , int V_25 )
{
unsigned long V_26 , V_3 ;
F_19 ( & V_5 -> V_7 -> V_27 , V_26 ) ;
V_3 = F_9 ( V_5 ) ;
if ( V_25 )
V_3 |= 1 << V_5 -> V_28 ;
else
V_3 &= ~ ( 1 << V_5 -> V_28 ) ;
F_10 ( V_5 , V_3 ) ;
F_20 ( & V_5 -> V_7 -> V_27 , V_26 ) ;
}
static int F_21 ( struct V_4 * V_5 , unsigned long * V_29 )
{
int V_30 , V_31 ;
F_22 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
F_23 ( & V_5 -> V_7 -> V_32 -> V_33 , true ) ;
V_31 = F_24 ( V_5 -> V_7 -> V_34 ) ;
if ( V_31 ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_1 ,
V_5 -> V_35 ) ;
goto V_36;
}
F_18 ( V_5 , 0 ) ;
if ( V_5 -> V_7 -> V_8 -> V_37 == 16 ) {
* V_29 = F_26 ( V_5 -> V_7 -> V_34 ) / 512 ;
F_12 ( V_5 , V_38 |
V_39 ) ;
} else {
* V_29 = F_26 ( V_5 -> V_7 -> V_34 ) / 8 ;
F_12 ( V_5 , V_40 |
V_41 |
V_42 |
V_43 ) ;
}
F_15 ( V_5 , 0xffffffff ) ;
F_14 ( V_5 , 0 ) ;
for ( V_30 = 0 ; V_30 < 100 ; V_30 ++ ) {
if ( ! F_13 ( V_5 ) )
break;
F_27 ( 1 ) ;
}
if ( F_13 ( V_5 ) ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_2 ,
V_5 -> V_35 ) ;
V_31 = - V_44 ;
goto V_45;
}
F_18 ( V_5 , 1 ) ;
return 0 ;
V_45:
F_28 ( V_5 -> V_7 -> V_34 ) ;
V_36:
return V_31 ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_18 ( V_5 , 0 ) ;
F_12 ( V_5 , 0 ) ;
F_28 ( V_5 -> V_7 -> V_34 ) ;
F_23 ( & V_5 -> V_7 -> V_32 -> V_33 , false ) ;
F_30 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
}
static void F_31 ( struct V_4 * V_5 ,
int V_46 )
{
unsigned long V_47 ;
unsigned long V_3 = V_5 -> V_48 ;
unsigned long V_49 = 0 ;
unsigned long V_50 = 0 ;
int V_18 ;
V_50 = F_16 ( V_5 , & V_18 ) ;
V_5 -> V_26 |= V_51 ;
if ( V_18 ) {
V_5 -> V_26 |= V_52 ;
return;
}
if ( V_46 )
V_50 = 0 ;
do {
V_47 = V_50 + V_3 + V_49 ;
if ( V_47 > V_5 -> V_53 )
V_47 = V_5 -> V_53 ;
F_15 ( V_5 , V_47 ) ;
V_50 = F_16 ( V_5 , & V_18 ) ;
if ( V_18 && ( V_47 > V_5 -> V_54 ) ) {
V_5 -> V_26 |= V_52 ;
break;
}
if ( V_18 ) {
V_5 -> V_54 = V_47 ;
break;
}
if ( V_50 < V_47 ) {
V_5 -> V_54 = V_47 ;
break;
}
if ( V_49 )
V_49 <<= 1 ;
else
V_49 = 1 ;
if ( ! V_49 )
F_32 ( & V_5 -> V_7 -> V_32 -> V_33 , L_3 ,
V_5 -> V_35 ) ;
} while ( V_49 );
}
static void F_33 ( struct V_4 * V_5 , unsigned long V_55 )
{
if ( V_55 > V_5 -> V_53 )
F_32 ( & V_5 -> V_7 -> V_32 -> V_33 , L_4 ,
V_5 -> V_35 ) ;
V_5 -> V_48 = V_55 ;
F_31 ( V_5 , 0 ) ;
}
static void F_34 ( struct V_4 * V_5 , unsigned long V_55 )
{
unsigned long V_26 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
F_33 ( V_5 , V_55 ) ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
}
static T_2 F_35 ( int V_56 , void * V_57 )
{
struct V_4 * V_5 = V_57 ;
F_12 ( V_5 , F_11 ( V_5 ) &
V_5 -> V_7 -> V_8 -> V_58 ) ;
if ( V_5 -> V_26 & V_59 )
V_5 -> V_60 += V_5 -> V_54 + 1 ;
if ( ! ( V_5 -> V_26 & V_51 ) )
V_5 -> V_48 = V_5 -> V_53 ;
V_5 -> V_26 |= V_61 ;
if ( V_5 -> V_26 & V_62 ) {
if ( ! ( V_5 -> V_26 & V_52 ) ) {
if ( F_36 ( & V_5 -> V_63 ) ) {
V_5 -> V_48 = V_5 -> V_53 ;
V_5 -> V_26 |= V_51 ;
}
V_5 -> V_63 . V_64 ( & V_5 -> V_63 ) ;
}
}
V_5 -> V_26 &= ~ V_52 ;
if ( V_5 -> V_26 & V_51 ) {
V_5 -> V_26 &= ~ V_51 ;
F_31 ( V_5 , 1 ) ;
if ( V_5 -> V_26 & V_62 )
if ( ( F_37 ( & V_5 -> V_63 ) )
|| ( V_5 -> V_54 == V_5 -> V_48 ) )
V_5 -> V_26 &= ~ V_51 ;
}
V_5 -> V_26 &= ~ V_61 ;
return V_65 ;
}
static int F_38 ( struct V_4 * V_5 , unsigned long V_66 )
{
int V_31 = 0 ;
unsigned long V_26 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
if ( ! ( V_5 -> V_26 & ( V_62 | V_59 ) ) )
V_31 = F_21 ( V_5 , & V_5 -> V_29 ) ;
if ( V_31 )
goto V_67;
V_5 -> V_26 |= V_66 ;
if ( ( V_66 == V_59 ) && ( ! ( V_5 -> V_26 & V_62 ) ) )
F_33 ( V_5 , V_5 -> V_53 ) ;
V_67:
F_20 ( & V_5 -> V_27 , V_26 ) ;
return V_31 ;
}
static void F_39 ( struct V_4 * V_5 , unsigned long V_66 )
{
unsigned long V_26 ;
unsigned long V_68 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
V_68 = V_5 -> V_26 & ( V_62 | V_59 ) ;
V_5 -> V_26 &= ~ V_66 ;
if ( V_68 && ! ( V_5 -> V_26 & ( V_62 | V_59 ) ) )
F_29 ( V_5 ) ;
if ( ( V_66 == V_62 ) && ( V_5 -> V_26 & V_59 ) )
F_33 ( V_5 , V_5 -> V_53 ) ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
}
static struct V_4 * F_40 ( struct V_69 * V_70 )
{
return F_41 ( V_70 , struct V_4 , V_70 ) ;
}
static T_3 F_42 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_40 ( V_70 ) ;
unsigned long V_26 , V_71 ;
unsigned long V_3 ;
int V_18 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
V_3 = V_5 -> V_60 ;
V_71 = F_16 ( V_5 , & V_18 ) ;
if ( F_17 ( V_18 ) )
V_71 += V_5 -> V_54 + 1 ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
return V_3 + V_71 ;
}
static int F_43 ( struct V_69 * V_70 )
{
int V_31 ;
struct V_4 * V_5 = F_40 ( V_70 ) ;
F_44 ( V_5 -> V_72 ) ;
V_5 -> V_60 = 0 ;
V_31 = F_38 ( V_5 , V_59 ) ;
if ( ! V_31 ) {
F_45 ( V_70 , V_5 -> V_29 ) ;
V_5 -> V_72 = true ;
}
return V_31 ;
}
static void F_46 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_40 ( V_70 ) ;
F_44 ( ! V_5 -> V_72 ) ;
F_39 ( V_5 , V_59 ) ;
V_5 -> V_72 = false ;
}
static void F_47 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_40 ( V_70 ) ;
if ( ! V_5 -> V_72 )
return;
F_39 ( V_5 , V_59 ) ;
F_48 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
}
static void F_49 ( struct V_69 * V_70 )
{
struct V_4 * V_5 = F_40 ( V_70 ) ;
if ( ! V_5 -> V_72 )
return;
F_50 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
F_38 ( V_5 , V_59 ) ;
}
static int F_51 ( struct V_4 * V_5 ,
const char * V_73 )
{
struct V_69 * V_70 = & V_5 -> V_70 ;
V_70 -> V_73 = V_73 ;
V_70 -> V_74 = 125 ;
V_70 -> V_75 = F_42 ;
V_70 -> V_76 = F_43 ;
V_70 -> V_77 = F_46 ;
V_70 -> V_78 = F_47 ;
V_70 -> V_79 = F_49 ;
V_70 -> V_80 = F_52 ( sizeof( unsigned long ) * 8 ) ;
V_70 -> V_26 = V_81 ;
F_53 ( & V_5 -> V_7 -> V_32 -> V_33 , L_5 ,
V_5 -> V_35 ) ;
F_54 ( V_70 , 1 ) ;
return 0 ;
}
static struct V_4 * F_55 ( struct V_82 * V_63 )
{
return F_41 ( V_63 , struct V_4 , V_63 ) ;
}
static void F_56 ( struct V_4 * V_5 , int V_83 )
{
struct V_82 * V_63 = & V_5 -> V_63 ;
F_38 ( V_5 , V_62 ) ;
V_63 -> V_84 = 32 ;
V_63 -> V_85 = F_57 ( V_5 -> V_29 , V_86 , V_63 -> V_84 ) ;
V_63 -> V_87 = F_58 ( V_5 -> V_53 , V_63 ) ;
V_63 -> V_88 = F_58 ( 0x1f , V_63 ) ;
if ( V_83 )
F_34 ( V_5 , ( ( V_5 -> V_29 + V_89 / 2 ) / V_89 ) - 1 ) ;
else
F_34 ( V_5 , V_5 -> V_53 ) ;
}
static int F_59 ( struct V_82 * V_63 )
{
struct V_4 * V_5 = F_55 ( V_63 ) ;
F_39 ( V_5 , V_62 ) ;
return 0 ;
}
static int F_60 ( struct V_82 * V_63 ,
int V_83 )
{
struct V_4 * V_5 = F_55 ( V_63 ) ;
if ( F_36 ( V_63 ) || F_61 ( V_63 ) )
F_39 ( V_5 , V_62 ) ;
F_53 ( & V_5 -> V_7 -> V_32 -> V_33 , L_6 ,
V_5 -> V_35 , V_83 ? L_7 : L_8 ) ;
F_56 ( V_5 , V_83 ) ;
return 0 ;
}
static int F_62 ( struct V_82 * V_63 )
{
return F_60 ( V_63 , 0 ) ;
}
static int F_63 ( struct V_82 * V_63 )
{
return F_60 ( V_63 , 1 ) ;
}
static int F_64 ( unsigned long V_55 ,
struct V_82 * V_63 )
{
struct V_4 * V_5 = F_55 ( V_63 ) ;
F_65 ( ! F_36 ( V_63 ) ) ;
if ( F_66 ( V_5 -> V_26 & V_61 ) )
V_5 -> V_48 = V_55 - 1 ;
else
F_34 ( V_5 , V_55 - 1 ) ;
return 0 ;
}
static void F_67 ( struct V_82 * V_63 )
{
struct V_4 * V_5 = F_55 ( V_63 ) ;
F_48 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
F_68 ( V_5 -> V_7 -> V_34 ) ;
}
static void F_69 ( struct V_82 * V_63 )
{
struct V_4 * V_5 = F_55 ( V_63 ) ;
F_70 ( V_5 -> V_7 -> V_34 ) ;
F_50 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
}
static int F_71 ( struct V_4 * V_5 ,
const char * V_73 )
{
struct V_82 * V_63 = & V_5 -> V_63 ;
int V_56 ;
int V_31 ;
V_56 = F_72 ( V_5 -> V_7 -> V_32 , V_5 -> V_35 ) ;
if ( V_56 < 0 ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_9 ,
V_5 -> V_35 ) ;
return V_56 ;
}
V_31 = F_73 ( V_56 , F_35 ,
V_90 | V_91 | V_92 ,
F_74 ( & V_5 -> V_7 -> V_32 -> V_33 ) , V_5 ) ;
if ( V_31 ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_10 ,
V_5 -> V_35 , V_56 ) ;
return V_31 ;
}
V_63 -> V_73 = V_73 ;
V_63 -> V_93 = V_94 ;
V_63 -> V_93 |= V_95 ;
V_63 -> V_74 = 125 ;
V_63 -> V_96 = V_97 ;
V_63 -> V_98 = F_64 ;
V_63 -> V_99 = F_59 ;
V_63 -> V_100 = F_63 ;
V_63 -> V_101 = F_62 ;
V_63 -> V_78 = F_67 ;
V_63 -> V_79 = F_69 ;
F_53 ( & V_5 -> V_7 -> V_32 -> V_33 , L_11 ,
V_5 -> V_35 ) ;
F_75 ( V_63 ) ;
return 0 ;
}
static int F_76 ( struct V_4 * V_5 , const char * V_73 ,
bool V_102 , bool V_69 )
{
int V_31 ;
if ( V_102 ) {
V_5 -> V_7 -> V_103 = true ;
V_31 = F_71 ( V_5 , V_73 ) ;
if ( V_31 < 0 )
return V_31 ;
}
if ( V_69 ) {
V_5 -> V_7 -> V_104 = true ;
F_51 ( V_5 , V_73 ) ;
}
return 0 ;
}
static int F_77 ( struct V_4 * V_5 , unsigned int V_35 ,
unsigned int V_105 , bool V_102 ,
bool V_69 , struct V_106 * V_7 )
{
int V_31 ;
if ( ! V_102 && ! V_69 )
return 0 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_105 = V_105 ;
switch ( V_7 -> V_8 -> V_107 ) {
case V_108 :
V_5 -> V_12 = V_7 -> V_10 + 2 + V_5 -> V_105 * 6 ;
break;
case V_109 :
case V_110 :
V_5 -> V_12 = V_7 -> V_10 + 0x10 + V_5 -> V_105 * 0x10 ;
break;
case V_111 :
V_5 -> V_12 = V_7 -> V_10 + 0x40 ;
break;
case V_112 :
V_5 -> V_6 = V_7 -> V_10 + V_5 -> V_105 * 0x100 ;
V_5 -> V_12 = V_5 -> V_6 + 0x10 ;
break;
}
if ( V_7 -> V_8 -> V_37 == ( sizeof( V_5 -> V_53 ) * 8 ) )
V_5 -> V_53 = ~ 0 ;
else
V_5 -> V_53 = ( 1 << V_7 -> V_8 -> V_37 ) - 1 ;
V_5 -> V_54 = V_5 -> V_53 ;
F_78 ( & V_5 -> V_27 ) ;
V_5 -> V_28 = V_7 -> V_8 -> V_107 == V_112 ? 0 : V_5 -> V_105 ;
V_31 = F_76 ( V_5 , F_74 ( & V_7 -> V_32 -> V_33 ) ,
V_102 , V_69 ) ;
if ( V_31 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_12 ,
V_5 -> V_35 ) ;
return V_31 ;
}
V_5 -> V_72 = false ;
return 0 ;
}
static int F_79 ( struct V_106 * V_7 )
{
struct V_113 * V_114 ;
V_114 = F_80 ( V_7 -> V_32 , V_115 , 0 ) ;
if ( ! V_114 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_13 ) ;
return - V_116 ;
}
V_7 -> V_10 = F_81 ( V_114 -> V_25 , F_82 ( V_114 ) ) ;
if ( V_7 -> V_10 == NULL ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_14 ) ;
return - V_116 ;
}
return 0 ;
}
static int F_83 ( struct V_106 * V_7 )
{
struct V_117 * V_118 = V_7 -> V_32 -> V_33 . V_119 ;
return F_84 ( V_118 , L_15 ,
& V_7 -> V_120 ) ;
}
static int F_85 ( struct V_106 * V_7 , struct V_121 * V_32 )
{
unsigned int V_80 ;
unsigned int V_122 ;
int V_31 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_32 = V_32 ;
F_78 ( & V_7 -> V_27 ) ;
if ( F_86 ( V_123 ) && V_32 -> V_33 . V_119 ) {
const struct V_124 * V_125 ;
V_125 = F_87 ( V_126 , V_32 -> V_33 . V_119 ) ;
V_7 -> V_8 = V_125 -> V_127 ;
V_31 = F_83 ( V_7 ) ;
if ( V_31 < 0 )
return V_31 ;
} else if ( V_32 -> V_33 . V_128 ) {
struct V_129 * V_130 = V_32 -> V_33 . V_128 ;
const struct V_131 * V_125 = V_32 -> V_132 ;
V_7 -> V_8 = ( const struct V_133 * ) V_125 -> V_134 ;
V_7 -> V_120 = V_130 -> V_135 ;
} else {
F_25 ( & V_7 -> V_32 -> V_33 , L_16 ) ;
return - V_116 ;
}
V_7 -> V_34 = F_88 ( & V_7 -> V_32 -> V_33 , L_17 ) ;
if ( F_89 ( V_7 -> V_34 ) ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_18 ) ;
return F_90 ( V_7 -> V_34 ) ;
}
V_31 = F_70 ( V_7 -> V_34 ) ;
if ( V_31 < 0 )
goto V_136;
V_31 = F_79 ( V_7 ) ;
if ( V_31 < 0 )
goto V_137;
V_7 -> V_138 = F_91 ( V_7 -> V_120 ) ;
V_7 -> V_139 = F_92 ( V_7 -> V_138 * sizeof( * V_7 -> V_139 ) ,
V_140 ) ;
if ( V_7 -> V_139 == NULL ) {
V_31 = - V_141 ;
goto V_142;
}
for ( V_122 = 0 , V_80 = V_7 -> V_120 ; V_122 < V_7 -> V_138 ; ++ V_122 ) {
unsigned int V_105 = F_93 ( V_80 ) - 1 ;
bool V_69 = V_122 == 1 || V_7 -> V_138 == 1 ;
bool V_102 = V_122 == 0 ;
V_31 = F_77 ( & V_7 -> V_139 [ V_122 ] , V_122 , V_105 ,
V_102 , V_69 , V_7 ) ;
if ( V_31 < 0 )
goto V_142;
V_80 &= ~ ( 1 << V_105 ) ;
}
F_94 ( V_32 , V_7 ) ;
return 0 ;
V_142:
F_95 ( V_7 -> V_139 ) ;
F_96 ( V_7 -> V_10 ) ;
V_137:
F_68 ( V_7 -> V_34 ) ;
V_136:
F_97 ( V_7 -> V_34 ) ;
return V_31 ;
}
static int F_98 ( struct V_121 * V_32 )
{
struct V_106 * V_7 = F_99 ( V_32 ) ;
int V_31 ;
if ( ! F_100 ( V_32 ) ) {
F_101 ( & V_32 -> V_33 ) ;
F_102 ( & V_32 -> V_33 ) ;
}
if ( V_7 ) {
F_53 ( & V_32 -> V_33 , L_19 ) ;
goto V_67;
}
V_7 = F_92 ( sizeof( * V_7 ) , V_140 ) ;
if ( V_7 == NULL )
return - V_141 ;
V_31 = F_85 ( V_7 , V_32 ) ;
if ( V_31 ) {
F_95 ( V_7 ) ;
F_103 ( & V_32 -> V_33 ) ;
return V_31 ;
}
if ( F_100 ( V_32 ) )
return 0 ;
V_67:
if ( V_7 -> V_103 || V_7 -> V_104 )
F_104 ( & V_32 -> V_33 ) ;
else
F_103 ( & V_32 -> V_33 ) ;
return 0 ;
}
static int F_105 ( struct V_121 * V_32 )
{
return - V_143 ;
}
static int T_4 F_106 ( void )
{
return F_107 ( & V_144 ) ;
}
static void T_5 F_108 ( void )
{
F_109 ( & V_144 ) ;
}
