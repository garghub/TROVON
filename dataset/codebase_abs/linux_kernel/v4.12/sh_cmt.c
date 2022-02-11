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
static int F_21 ( struct V_4 * V_5 )
{
int V_29 , V_30 ;
F_22 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
F_23 ( & V_5 -> V_7 -> V_31 -> V_32 , true ) ;
V_30 = F_24 ( V_5 -> V_7 -> V_33 ) ;
if ( V_30 ) {
F_25 ( & V_5 -> V_7 -> V_31 -> V_32 , L_1 ,
V_5 -> V_34 ) ;
goto V_35;
}
F_18 ( V_5 , 0 ) ;
if ( V_5 -> V_7 -> V_8 -> V_36 == 16 ) {
F_12 ( V_5 , V_37 |
V_38 ) ;
} else {
F_12 ( V_5 , V_39 |
V_40 |
V_41 |
V_42 ) ;
}
F_15 ( V_5 , 0xffffffff ) ;
F_14 ( V_5 , 0 ) ;
for ( V_29 = 0 ; V_29 < 100 ; V_29 ++ ) {
if ( ! F_13 ( V_5 ) )
break;
F_26 ( 1 ) ;
}
if ( F_13 ( V_5 ) ) {
F_25 ( & V_5 -> V_7 -> V_31 -> V_32 , L_2 ,
V_5 -> V_34 ) ;
V_30 = - V_43 ;
goto V_44;
}
F_18 ( V_5 , 1 ) ;
return 0 ;
V_44:
F_27 ( V_5 -> V_7 -> V_33 ) ;
V_35:
return V_30 ;
}
static void F_28 ( struct V_4 * V_5 )
{
F_18 ( V_5 , 0 ) ;
F_12 ( V_5 , 0 ) ;
F_27 ( V_5 -> V_7 -> V_33 ) ;
F_23 ( & V_5 -> V_7 -> V_31 -> V_32 , false ) ;
F_29 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
}
static void F_30 ( struct V_4 * V_5 ,
int V_45 )
{
unsigned long V_46 ;
unsigned long V_3 = V_5 -> V_47 ;
unsigned long V_48 = 0 ;
unsigned long V_49 = 0 ;
int V_18 ;
V_49 = F_16 ( V_5 , & V_18 ) ;
V_5 -> V_26 |= V_50 ;
if ( V_18 ) {
V_5 -> V_26 |= V_51 ;
return;
}
if ( V_45 )
V_49 = 0 ;
do {
V_46 = V_49 + V_3 + V_48 ;
if ( V_46 > V_5 -> V_52 )
V_46 = V_5 -> V_52 ;
F_15 ( V_5 , V_46 ) ;
V_49 = F_16 ( V_5 , & V_18 ) ;
if ( V_18 && ( V_46 > V_5 -> V_53 ) ) {
V_5 -> V_26 |= V_51 ;
break;
}
if ( V_18 ) {
V_5 -> V_53 = V_46 ;
break;
}
if ( V_49 < V_46 ) {
V_5 -> V_53 = V_46 ;
break;
}
if ( V_48 )
V_48 <<= 1 ;
else
V_48 = 1 ;
if ( ! V_48 )
F_31 ( & V_5 -> V_7 -> V_31 -> V_32 , L_3 ,
V_5 -> V_34 ) ;
} while ( V_48 );
}
static void F_32 ( struct V_4 * V_5 , unsigned long V_54 )
{
if ( V_54 > V_5 -> V_52 )
F_31 ( & V_5 -> V_7 -> V_31 -> V_32 , L_4 ,
V_5 -> V_34 ) ;
V_5 -> V_47 = V_54 ;
F_30 ( V_5 , 0 ) ;
}
static void F_33 ( struct V_4 * V_5 , unsigned long V_54 )
{
unsigned long V_26 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
F_32 ( V_5 , V_54 ) ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
}
static T_2 F_34 ( int V_55 , void * V_56 )
{
struct V_4 * V_5 = V_56 ;
F_12 ( V_5 , F_11 ( V_5 ) &
V_5 -> V_7 -> V_8 -> V_57 ) ;
if ( V_5 -> V_26 & V_58 )
V_5 -> V_59 += V_5 -> V_53 + 1 ;
if ( ! ( V_5 -> V_26 & V_50 ) )
V_5 -> V_47 = V_5 -> V_52 ;
V_5 -> V_26 |= V_60 ;
if ( V_5 -> V_26 & V_61 ) {
if ( ! ( V_5 -> V_26 & V_51 ) ) {
if ( F_35 ( & V_5 -> V_62 ) ) {
V_5 -> V_47 = V_5 -> V_52 ;
V_5 -> V_26 |= V_50 ;
}
V_5 -> V_62 . V_63 ( & V_5 -> V_62 ) ;
}
}
V_5 -> V_26 &= ~ V_51 ;
if ( V_5 -> V_26 & V_50 ) {
V_5 -> V_26 &= ~ V_50 ;
F_30 ( V_5 , 1 ) ;
if ( V_5 -> V_26 & V_61 )
if ( ( F_36 ( & V_5 -> V_62 ) )
|| ( V_5 -> V_53 == V_5 -> V_47 ) )
V_5 -> V_26 &= ~ V_50 ;
}
V_5 -> V_26 &= ~ V_60 ;
return V_64 ;
}
static int F_37 ( struct V_4 * V_5 , unsigned long V_65 )
{
int V_30 = 0 ;
unsigned long V_26 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
if ( ! ( V_5 -> V_26 & ( V_61 | V_58 ) ) )
V_30 = F_21 ( V_5 ) ;
if ( V_30 )
goto V_66;
V_5 -> V_26 |= V_65 ;
if ( ( V_65 == V_58 ) && ( ! ( V_5 -> V_26 & V_61 ) ) )
F_32 ( V_5 , V_5 -> V_52 ) ;
V_66:
F_20 ( & V_5 -> V_27 , V_26 ) ;
return V_30 ;
}
static void F_38 ( struct V_4 * V_5 , unsigned long V_65 )
{
unsigned long V_26 ;
unsigned long V_67 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
V_67 = V_5 -> V_26 & ( V_61 | V_58 ) ;
V_5 -> V_26 &= ~ V_65 ;
if ( V_67 && ! ( V_5 -> V_26 & ( V_61 | V_58 ) ) )
F_28 ( V_5 ) ;
if ( ( V_65 == V_61 ) && ( V_5 -> V_26 & V_58 ) )
F_32 ( V_5 , V_5 -> V_52 ) ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
}
static struct V_4 * F_39 ( struct V_68 * V_69 )
{
return F_40 ( V_69 , struct V_4 , V_69 ) ;
}
static T_3 F_41 ( struct V_68 * V_69 )
{
struct V_4 * V_5 = F_39 ( V_69 ) ;
unsigned long V_26 , V_70 ;
unsigned long V_3 ;
int V_18 ;
F_19 ( & V_5 -> V_27 , V_26 ) ;
V_3 = V_5 -> V_59 ;
V_70 = F_16 ( V_5 , & V_18 ) ;
if ( F_17 ( V_18 ) )
V_70 += V_5 -> V_53 + 1 ;
F_20 ( & V_5 -> V_27 , V_26 ) ;
return V_3 + V_70 ;
}
static int F_42 ( struct V_68 * V_69 )
{
int V_30 ;
struct V_4 * V_5 = F_39 ( V_69 ) ;
F_43 ( V_5 -> V_71 ) ;
V_5 -> V_59 = 0 ;
V_30 = F_37 ( V_5 , V_58 ) ;
if ( ! V_30 )
V_5 -> V_71 = true ;
return V_30 ;
}
static void F_44 ( struct V_68 * V_69 )
{
struct V_4 * V_5 = F_39 ( V_69 ) ;
F_43 ( ! V_5 -> V_71 ) ;
F_38 ( V_5 , V_58 ) ;
V_5 -> V_71 = false ;
}
static void F_45 ( struct V_68 * V_69 )
{
struct V_4 * V_5 = F_39 ( V_69 ) ;
if ( ! V_5 -> V_71 )
return;
F_38 ( V_5 , V_58 ) ;
F_46 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
}
static void F_47 ( struct V_68 * V_69 )
{
struct V_4 * V_5 = F_39 ( V_69 ) ;
if ( ! V_5 -> V_71 )
return;
F_48 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
F_37 ( V_5 , V_58 ) ;
}
static int F_49 ( struct V_4 * V_5 ,
const char * V_72 )
{
struct V_68 * V_69 = & V_5 -> V_69 ;
V_69 -> V_72 = V_72 ;
V_69 -> V_73 = 125 ;
V_69 -> V_74 = F_41 ;
V_69 -> V_75 = F_42 ;
V_69 -> V_76 = F_44 ;
V_69 -> V_77 = F_45 ;
V_69 -> V_78 = F_47 ;
V_69 -> V_79 = F_50 ( sizeof( unsigned long ) * 8 ) ;
V_69 -> V_26 = V_80 ;
F_51 ( & V_5 -> V_7 -> V_31 -> V_32 , L_5 ,
V_5 -> V_34 ) ;
F_52 ( V_69 , V_5 -> V_7 -> V_81 ) ;
return 0 ;
}
static struct V_4 * F_53 ( struct V_82 * V_62 )
{
return F_40 ( V_62 , struct V_4 , V_62 ) ;
}
static void F_54 ( struct V_4 * V_5 , int V_83 )
{
F_37 ( V_5 , V_61 ) ;
if ( V_83 )
F_33 ( V_5 , ( ( V_5 -> V_7 -> V_81 + V_84 / 2 ) / V_84 ) - 1 ) ;
else
F_33 ( V_5 , V_5 -> V_52 ) ;
}
static int F_55 ( struct V_82 * V_62 )
{
struct V_4 * V_5 = F_53 ( V_62 ) ;
F_38 ( V_5 , V_61 ) ;
return 0 ;
}
static int F_56 ( struct V_82 * V_62 ,
int V_83 )
{
struct V_4 * V_5 = F_53 ( V_62 ) ;
if ( F_35 ( V_62 ) || F_57 ( V_62 ) )
F_38 ( V_5 , V_61 ) ;
F_51 ( & V_5 -> V_7 -> V_31 -> V_32 , L_6 ,
V_5 -> V_34 , V_83 ? L_7 : L_8 ) ;
F_54 ( V_5 , V_83 ) ;
return 0 ;
}
static int F_58 ( struct V_82 * V_62 )
{
return F_56 ( V_62 , 0 ) ;
}
static int F_59 ( struct V_82 * V_62 )
{
return F_56 ( V_62 , 1 ) ;
}
static int F_60 ( unsigned long V_54 ,
struct V_82 * V_62 )
{
struct V_4 * V_5 = F_53 ( V_62 ) ;
F_61 ( ! F_35 ( V_62 ) ) ;
if ( F_62 ( V_5 -> V_26 & V_60 ) )
V_5 -> V_47 = V_54 - 1 ;
else
F_33 ( V_5 , V_54 - 1 ) ;
return 0 ;
}
static void F_63 ( struct V_82 * V_62 )
{
struct V_4 * V_5 = F_53 ( V_62 ) ;
F_46 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
F_64 ( V_5 -> V_7 -> V_33 ) ;
}
static void F_65 ( struct V_82 * V_62 )
{
struct V_4 * V_5 = F_53 ( V_62 ) ;
F_66 ( V_5 -> V_7 -> V_33 ) ;
F_48 ( & V_5 -> V_7 -> V_31 -> V_32 ) ;
}
static int F_67 ( struct V_4 * V_5 ,
const char * V_72 )
{
struct V_82 * V_62 = & V_5 -> V_62 ;
int V_55 ;
int V_30 ;
V_55 = F_68 ( V_5 -> V_7 -> V_31 , V_5 -> V_34 ) ;
if ( V_55 < 0 ) {
F_25 ( & V_5 -> V_7 -> V_31 -> V_32 , L_9 ,
V_5 -> V_34 ) ;
return V_55 ;
}
V_30 = F_69 ( V_55 , F_34 ,
V_85 | V_86 | V_87 ,
F_70 ( & V_5 -> V_7 -> V_31 -> V_32 ) , V_5 ) ;
if ( V_30 ) {
F_25 ( & V_5 -> V_7 -> V_31 -> V_32 , L_10 ,
V_5 -> V_34 , V_55 ) ;
return V_30 ;
}
V_62 -> V_72 = V_72 ;
V_62 -> V_88 = V_89 ;
V_62 -> V_88 |= V_90 ;
V_62 -> V_73 = 125 ;
V_62 -> V_91 = V_92 ;
V_62 -> V_93 = F_60 ;
V_62 -> V_94 = F_55 ;
V_62 -> V_95 = F_59 ;
V_62 -> V_96 = F_58 ;
V_62 -> V_77 = F_63 ;
V_62 -> V_78 = F_65 ;
V_62 -> V_97 = 32 ;
V_62 -> V_98 = F_71 ( V_5 -> V_7 -> V_81 , V_99 , V_62 -> V_97 ) ;
V_62 -> V_100 = F_72 ( V_5 -> V_52 , V_62 ) ;
V_62 -> V_101 = V_5 -> V_52 ;
V_62 -> V_102 = F_72 ( 0x1f , V_62 ) ;
V_62 -> V_103 = 0x1f ;
F_51 ( & V_5 -> V_7 -> V_31 -> V_32 , L_11 ,
V_5 -> V_34 ) ;
F_73 ( V_62 ) ;
return 0 ;
}
static int F_74 ( struct V_4 * V_5 , const char * V_72 ,
bool V_104 , bool V_68 )
{
int V_30 ;
if ( V_104 ) {
V_5 -> V_7 -> V_105 = true ;
V_30 = F_67 ( V_5 , V_72 ) ;
if ( V_30 < 0 )
return V_30 ;
}
if ( V_68 ) {
V_5 -> V_7 -> V_106 = true ;
F_49 ( V_5 , V_72 ) ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_5 , unsigned int V_34 ,
unsigned int V_107 , bool V_104 ,
bool V_68 , struct V_108 * V_7 )
{
int V_30 ;
if ( ! V_104 && ! V_68 )
return 0 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_34 = V_34 ;
V_5 -> V_107 = V_107 ;
switch ( V_7 -> V_8 -> V_109 ) {
case V_110 :
V_5 -> V_12 = V_7 -> V_10 + 2 + V_5 -> V_107 * 6 ;
break;
case V_111 :
case V_112 :
V_5 -> V_12 = V_7 -> V_10 + 0x10 + V_5 -> V_107 * 0x10 ;
break;
case V_113 :
V_5 -> V_12 = V_7 -> V_10 + 0x40 ;
break;
case V_114 :
V_5 -> V_6 = V_7 -> V_10 + V_5 -> V_107 * 0x100 ;
V_5 -> V_12 = V_5 -> V_6 + 0x10 ;
break;
}
if ( V_7 -> V_8 -> V_36 == ( sizeof( V_5 -> V_52 ) * 8 ) )
V_5 -> V_52 = ~ 0 ;
else
V_5 -> V_52 = ( 1 << V_7 -> V_8 -> V_36 ) - 1 ;
V_5 -> V_53 = V_5 -> V_52 ;
F_76 ( & V_5 -> V_27 ) ;
V_5 -> V_28 = V_7 -> V_8 -> V_109 == V_114 ? 0 : V_5 -> V_107 ;
V_30 = F_74 ( V_5 , F_70 ( & V_7 -> V_31 -> V_32 ) ,
V_104 , V_68 ) ;
if ( V_30 ) {
F_25 ( & V_7 -> V_31 -> V_32 , L_12 ,
V_5 -> V_34 ) ;
return V_30 ;
}
V_5 -> V_71 = false ;
return 0 ;
}
static int F_77 ( struct V_108 * V_7 )
{
struct V_115 * V_116 ;
V_116 = F_78 ( V_7 -> V_31 , V_117 , 0 ) ;
if ( ! V_116 ) {
F_25 ( & V_7 -> V_31 -> V_32 , L_13 ) ;
return - V_118 ;
}
V_7 -> V_10 = F_79 ( V_116 -> V_25 , F_80 ( V_116 ) ) ;
if ( V_7 -> V_10 == NULL ) {
F_25 ( & V_7 -> V_31 -> V_32 , L_14 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_81 ( struct V_108 * V_7 )
{
struct V_119 * V_120 = V_7 -> V_31 -> V_32 . V_121 ;
return F_82 ( V_120 , L_15 ,
& V_7 -> V_122 ) ;
}
static int F_83 ( struct V_108 * V_7 , struct V_123 * V_31 )
{
unsigned int V_79 ;
unsigned int V_124 ;
int V_30 ;
V_7 -> V_31 = V_31 ;
F_76 ( & V_7 -> V_27 ) ;
if ( F_84 ( V_125 ) && V_31 -> V_32 . V_121 ) {
const struct V_126 * V_127 ;
V_127 = F_85 ( V_128 , V_31 -> V_32 . V_121 ) ;
V_7 -> V_8 = V_127 -> V_129 ;
V_30 = F_81 ( V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
} else if ( V_31 -> V_32 . V_130 ) {
struct V_131 * V_132 = V_31 -> V_32 . V_130 ;
const struct V_133 * V_127 = V_31 -> V_134 ;
V_7 -> V_8 = ( const struct V_135 * ) V_127 -> V_136 ;
V_7 -> V_122 = V_132 -> V_137 ;
} else {
F_25 ( & V_7 -> V_31 -> V_32 , L_16 ) ;
return - V_118 ;
}
V_7 -> V_33 = F_86 ( & V_7 -> V_31 -> V_32 , L_17 ) ;
if ( F_87 ( V_7 -> V_33 ) ) {
F_25 ( & V_7 -> V_31 -> V_32 , L_18 ) ;
return F_88 ( V_7 -> V_33 ) ;
}
V_30 = F_66 ( V_7 -> V_33 ) ;
if ( V_30 < 0 )
goto V_138;
V_30 = F_24 ( V_7 -> V_33 ) ;
if ( V_30 < 0 )
goto V_139;
if ( V_7 -> V_8 -> V_36 == 16 )
V_7 -> V_81 = F_89 ( V_7 -> V_33 ) / 512 ;
else
V_7 -> V_81 = F_89 ( V_7 -> V_33 ) / 8 ;
F_27 ( V_7 -> V_33 ) ;
V_30 = F_77 ( V_7 ) ;
if ( V_30 < 0 )
goto V_139;
V_7 -> V_140 = F_90 ( V_7 -> V_122 ) ;
V_7 -> V_141 = F_91 ( V_7 -> V_140 * sizeof( * V_7 -> V_141 ) ,
V_142 ) ;
if ( V_7 -> V_141 == NULL ) {
V_30 = - V_143 ;
goto V_144;
}
for ( V_124 = 0 , V_79 = V_7 -> V_122 ; V_124 < V_7 -> V_140 ; ++ V_124 ) {
unsigned int V_107 = F_92 ( V_79 ) - 1 ;
bool V_68 = V_124 == 1 || V_7 -> V_140 == 1 ;
bool V_104 = V_124 == 0 ;
V_30 = F_75 ( & V_7 -> V_141 [ V_124 ] , V_124 , V_107 ,
V_104 , V_68 , V_7 ) ;
if ( V_30 < 0 )
goto V_144;
V_79 &= ~ ( 1 << V_107 ) ;
}
F_93 ( V_31 , V_7 ) ;
return 0 ;
V_144:
F_94 ( V_7 -> V_141 ) ;
F_95 ( V_7 -> V_10 ) ;
V_139:
F_64 ( V_7 -> V_33 ) ;
V_138:
F_96 ( V_7 -> V_33 ) ;
return V_30 ;
}
static int F_97 ( struct V_123 * V_31 )
{
struct V_108 * V_7 = F_98 ( V_31 ) ;
int V_30 ;
if ( ! F_99 ( V_31 ) ) {
F_100 ( & V_31 -> V_32 ) ;
F_101 ( & V_31 -> V_32 ) ;
}
if ( V_7 ) {
F_51 ( & V_31 -> V_32 , L_19 ) ;
goto V_66;
}
V_7 = F_91 ( sizeof( * V_7 ) , V_142 ) ;
if ( V_7 == NULL )
return - V_143 ;
V_30 = F_83 ( V_7 , V_31 ) ;
if ( V_30 ) {
F_94 ( V_7 ) ;
F_102 ( & V_31 -> V_32 ) ;
return V_30 ;
}
if ( F_99 ( V_31 ) )
return 0 ;
V_66:
if ( V_7 -> V_105 || V_7 -> V_106 )
F_103 ( & V_31 -> V_32 ) ;
else
F_102 ( & V_31 -> V_32 ) ;
return 0 ;
}
static int F_104 ( struct V_123 * V_31 )
{
return - V_145 ;
}
static int T_4 F_105 ( void )
{
return F_106 ( & V_146 ) ;
}
static void T_5 F_107 ( void )
{
F_108 ( & V_146 ) ;
}
