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
F_19 ( & V_27 , V_26 ) ;
V_3 = F_9 ( V_5 ) ;
if ( V_25 )
V_3 |= 1 << V_5 -> V_28 ;
else
V_3 &= ~ ( 1 << V_5 -> V_28 ) ;
F_10 ( V_5 , V_3 ) ;
F_20 ( & V_27 , V_26 ) ;
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
F_19 ( & V_5 -> V_56 , V_26 ) ;
F_33 ( V_5 , V_55 ) ;
F_20 ( & V_5 -> V_56 , V_26 ) ;
}
static T_2 F_35 ( int V_57 , void * V_58 )
{
struct V_4 * V_5 = V_58 ;
F_12 ( V_5 , F_11 ( V_5 ) &
V_5 -> V_7 -> V_8 -> V_59 ) ;
if ( V_5 -> V_26 & V_60 )
V_5 -> V_61 += V_5 -> V_54 + 1 ;
if ( ! ( V_5 -> V_26 & V_51 ) )
V_5 -> V_48 = V_5 -> V_53 ;
V_5 -> V_26 |= V_62 ;
if ( V_5 -> V_26 & V_63 ) {
if ( ! ( V_5 -> V_26 & V_52 ) ) {
if ( V_5 -> V_64 . V_65 == V_66 ) {
V_5 -> V_48 = V_5 -> V_53 ;
V_5 -> V_26 |= V_51 ;
}
V_5 -> V_64 . V_67 ( & V_5 -> V_64 ) ;
}
}
V_5 -> V_26 &= ~ V_52 ;
if ( V_5 -> V_26 & V_51 ) {
V_5 -> V_26 &= ~ V_51 ;
F_31 ( V_5 , 1 ) ;
if ( V_5 -> V_26 & V_63 )
if ( ( V_5 -> V_64 . V_65 == V_68 )
|| ( V_5 -> V_54 == V_5 -> V_48 ) )
V_5 -> V_26 &= ~ V_51 ;
}
V_5 -> V_26 &= ~ V_62 ;
return V_69 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned long V_70 )
{
int V_31 = 0 ;
unsigned long V_26 ;
F_19 ( & V_5 -> V_56 , V_26 ) ;
if ( ! ( V_5 -> V_26 & ( V_63 | V_60 ) ) )
V_31 = F_21 ( V_5 , & V_5 -> V_29 ) ;
if ( V_31 )
goto V_71;
V_5 -> V_26 |= V_70 ;
if ( ( V_70 == V_60 ) && ( ! ( V_5 -> V_26 & V_63 ) ) )
F_33 ( V_5 , V_5 -> V_53 ) ;
V_71:
F_20 ( & V_5 -> V_56 , V_26 ) ;
return V_31 ;
}
static void F_37 ( struct V_4 * V_5 , unsigned long V_70 )
{
unsigned long V_26 ;
unsigned long V_72 ;
F_19 ( & V_5 -> V_56 , V_26 ) ;
V_72 = V_5 -> V_26 & ( V_63 | V_60 ) ;
V_5 -> V_26 &= ~ V_70 ;
if ( V_72 && ! ( V_5 -> V_26 & ( V_63 | V_60 ) ) )
F_29 ( V_5 ) ;
if ( ( V_70 == V_63 ) && ( V_5 -> V_26 & V_60 ) )
F_33 ( V_5 , V_5 -> V_53 ) ;
F_20 ( & V_5 -> V_56 , V_26 ) ;
}
static struct V_4 * F_38 ( struct V_73 * V_74 )
{
return F_39 ( V_74 , struct V_4 , V_74 ) ;
}
static T_3 F_40 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_38 ( V_74 ) ;
unsigned long V_26 , V_75 ;
unsigned long V_3 ;
int V_18 ;
F_19 ( & V_5 -> V_56 , V_26 ) ;
V_3 = V_5 -> V_61 ;
V_75 = F_16 ( V_5 , & V_18 ) ;
if ( F_17 ( V_18 ) )
V_75 += V_5 -> V_54 + 1 ;
F_20 ( & V_5 -> V_56 , V_26 ) ;
return V_3 + V_75 ;
}
static int F_41 ( struct V_73 * V_74 )
{
int V_31 ;
struct V_4 * V_5 = F_38 ( V_74 ) ;
F_42 ( V_5 -> V_76 ) ;
V_5 -> V_61 = 0 ;
V_31 = F_36 ( V_5 , V_60 ) ;
if ( ! V_31 ) {
F_43 ( V_74 , V_5 -> V_29 ) ;
V_5 -> V_76 = true ;
}
return V_31 ;
}
static void F_44 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_38 ( V_74 ) ;
F_42 ( ! V_5 -> V_76 ) ;
F_37 ( V_5 , V_60 ) ;
V_5 -> V_76 = false ;
}
static void F_45 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_38 ( V_74 ) ;
F_37 ( V_5 , V_60 ) ;
F_46 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
}
static void F_47 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_38 ( V_74 ) ;
F_48 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
F_36 ( V_5 , V_60 ) ;
}
static int F_49 ( struct V_4 * V_5 ,
const char * V_77 )
{
struct V_73 * V_74 = & V_5 -> V_74 ;
V_74 -> V_77 = V_77 ;
V_74 -> V_78 = 125 ;
V_74 -> V_79 = F_40 ;
V_74 -> V_80 = F_41 ;
V_74 -> V_81 = F_44 ;
V_74 -> V_82 = F_45 ;
V_74 -> V_83 = F_47 ;
V_74 -> V_84 = F_50 ( sizeof( unsigned long ) * 8 ) ;
V_74 -> V_26 = V_85 ;
F_51 ( & V_5 -> V_7 -> V_32 -> V_33 , L_5 ,
V_5 -> V_35 ) ;
F_52 ( V_74 , 1 ) ;
return 0 ;
}
static struct V_4 * F_53 ( struct V_86 * V_64 )
{
return F_39 ( V_64 , struct V_4 , V_64 ) ;
}
static void F_54 ( struct V_4 * V_5 , int V_87 )
{
struct V_86 * V_64 = & V_5 -> V_64 ;
F_36 ( V_5 , V_63 ) ;
V_64 -> V_88 = 32 ;
V_64 -> V_89 = F_55 ( V_5 -> V_29 , V_90 , V_64 -> V_88 ) ;
V_64 -> V_91 = F_56 ( V_5 -> V_53 , V_64 ) ;
V_64 -> V_92 = F_56 ( 0x1f , V_64 ) ;
if ( V_87 )
F_34 ( V_5 , ( ( V_5 -> V_29 + V_93 / 2 ) / V_93 ) - 1 ) ;
else
F_34 ( V_5 , V_5 -> V_53 ) ;
}
static void F_57 ( enum V_94 V_65 ,
struct V_86 * V_64 )
{
struct V_4 * V_5 = F_53 ( V_64 ) ;
switch ( V_64 -> V_65 ) {
case V_95 :
case V_66 :
F_37 ( V_5 , V_63 ) ;
break;
default:
break;
}
switch ( V_65 ) {
case V_95 :
F_51 ( & V_5 -> V_7 -> V_32 -> V_33 ,
L_6 , V_5 -> V_35 ) ;
F_54 ( V_5 , 1 ) ;
break;
case V_66 :
F_51 ( & V_5 -> V_7 -> V_32 -> V_33 ,
L_7 , V_5 -> V_35 ) ;
F_54 ( V_5 , 0 ) ;
break;
case V_68 :
case V_96 :
F_37 ( V_5 , V_63 ) ;
break;
default:
break;
}
}
static int F_58 ( unsigned long V_55 ,
struct V_86 * V_64 )
{
struct V_4 * V_5 = F_53 ( V_64 ) ;
F_59 ( V_64 -> V_65 != V_66 ) ;
if ( F_60 ( V_5 -> V_26 & V_62 ) )
V_5 -> V_48 = V_55 - 1 ;
else
F_34 ( V_5 , V_55 - 1 ) ;
return 0 ;
}
static void F_61 ( struct V_86 * V_64 )
{
struct V_4 * V_5 = F_53 ( V_64 ) ;
F_46 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
F_62 ( V_5 -> V_7 -> V_34 ) ;
}
static void F_63 ( struct V_86 * V_64 )
{
struct V_4 * V_5 = F_53 ( V_64 ) ;
F_64 ( V_5 -> V_7 -> V_34 ) ;
F_48 ( & V_5 -> V_7 -> V_32 -> V_33 ) ;
}
static int F_65 ( struct V_4 * V_5 ,
const char * V_77 )
{
struct V_86 * V_64 = & V_5 -> V_64 ;
int V_57 ;
int V_31 ;
V_57 = F_66 ( V_5 -> V_7 -> V_32 , V_5 -> V_7 -> V_97 ? 0 : V_5 -> V_35 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_8 ,
V_5 -> V_35 ) ;
return V_57 ;
}
V_31 = F_67 ( V_57 , F_35 ,
V_98 | V_99 | V_100 ,
F_68 ( & V_5 -> V_7 -> V_32 -> V_33 ) , V_5 ) ;
if ( V_31 ) {
F_25 ( & V_5 -> V_7 -> V_32 -> V_33 , L_9 ,
V_5 -> V_35 , V_57 ) ;
return V_31 ;
}
V_64 -> V_77 = V_77 ;
V_64 -> V_101 = V_102 ;
V_64 -> V_101 |= V_103 ;
V_64 -> V_78 = 125 ;
V_64 -> V_104 = V_105 ;
V_64 -> V_106 = F_58 ;
V_64 -> V_107 = F_57 ;
V_64 -> V_82 = F_61 ;
V_64 -> V_83 = F_63 ;
F_51 ( & V_5 -> V_7 -> V_32 -> V_33 , L_10 ,
V_5 -> V_35 ) ;
F_69 ( V_64 ) ;
return 0 ;
}
static int F_70 ( struct V_4 * V_5 , const char * V_77 ,
bool V_108 , bool V_73 )
{
int V_31 ;
if ( V_108 ) {
V_5 -> V_7 -> V_109 = true ;
V_31 = F_65 ( V_5 , V_77 ) ;
if ( V_31 < 0 )
return V_31 ;
}
if ( V_73 ) {
V_5 -> V_7 -> V_110 = true ;
F_49 ( V_5 , V_77 ) ;
}
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned int V_35 ,
unsigned int V_111 , bool V_108 ,
bool V_73 , struct V_112 * V_7 )
{
int V_31 ;
if ( ! V_108 && ! V_73 )
return 0 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_111 = V_111 ;
if ( V_7 -> V_97 ) {
V_5 -> V_12 = V_7 -> V_113 ;
} else {
switch ( V_7 -> V_8 -> V_114 ) {
case V_115 :
V_5 -> V_12 = V_7 -> V_10 + 2 + V_5 -> V_111 * 6 ;
break;
case V_116 :
case V_117 :
V_5 -> V_12 = V_7 -> V_10 + 0x10 + V_5 -> V_111 * 0x10 ;
break;
case V_118 :
V_5 -> V_12 = V_7 -> V_10 + 0x40 ;
break;
case V_119 :
V_5 -> V_6 = V_7 -> V_10 + V_5 -> V_111 * 0x100 ;
V_5 -> V_12 = V_5 -> V_6 + 0x10 ;
break;
}
}
if ( V_7 -> V_8 -> V_37 == ( sizeof( V_5 -> V_53 ) * 8 ) )
V_5 -> V_53 = ~ 0 ;
else
V_5 -> V_53 = ( 1 << V_7 -> V_8 -> V_37 ) - 1 ;
V_5 -> V_54 = V_5 -> V_53 ;
F_72 ( & V_5 -> V_56 ) ;
if ( V_7 -> V_97 ) {
V_5 -> V_28 = V_5 -> V_111 ;
} else {
V_5 -> V_28 = V_7 -> V_8 -> V_114 == V_119
? 0 : V_5 -> V_111 ;
}
V_31 = F_70 ( V_5 , F_68 ( & V_7 -> V_32 -> V_33 ) ,
V_108 , V_73 ) ;
if ( V_31 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_11 ,
V_5 -> V_35 ) ;
return V_31 ;
}
V_5 -> V_76 = false ;
return 0 ;
}
static int F_73 ( struct V_112 * V_7 )
{
struct V_120 * V_121 ;
V_121 = F_74 ( V_7 -> V_32 , V_122 , 0 ) ;
if ( ! V_121 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_12 ) ;
return - V_123 ;
}
V_7 -> V_10 = F_75 ( V_121 -> V_25 , F_76 ( V_121 ) ) ;
if ( V_7 -> V_10 == NULL ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_13 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_77 ( struct V_112 * V_7 )
{
struct V_124 * V_125 = V_7 -> V_32 -> V_33 . V_126 ;
struct V_120 * V_127 , * V_128 ;
V_127 = F_74 ( V_7 -> V_32 , V_122 , 0 ) ;
if ( ! V_127 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_12 ) ;
return - V_123 ;
}
V_7 -> V_113 = F_75 ( V_127 -> V_25 , F_76 ( V_127 ) ) ;
if ( V_7 -> V_113 == NULL ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_13 ) ;
return - V_123 ;
}
V_128 = F_74 ( V_7 -> V_32 , V_122 , 1 ) ;
V_7 -> V_10 = F_75 ( V_128 ? V_128 -> V_25 :
V_127 -> V_25 - V_125 -> V_129 ,
V_128 ? F_76 ( V_128 ) : 2 ) ;
if ( V_7 -> V_10 == NULL ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_14 ) ;
F_78 ( V_7 -> V_113 ) ;
return - V_123 ;
}
if ( F_76 ( V_127 ) == 6 )
V_7 -> V_8 = & V_130 [ V_115 ] ;
else if ( V_128 && ( F_76 ( V_128 ) == 4 ) )
V_7 -> V_8 = & V_130 [ V_119 ] ;
else
V_7 -> V_8 = & V_130 [ V_116 ] ;
return 0 ;
}
static void F_79 ( struct V_112 * V_7 )
{
F_78 ( V_7 -> V_10 ) ;
if ( V_7 -> V_113 )
F_78 ( V_7 -> V_113 ) ;
}
static int F_80 ( struct V_112 * V_7 , struct V_131 * V_32 )
{
struct V_124 * V_125 = V_32 -> V_33 . V_126 ;
const struct V_132 * V_133 = V_32 -> V_134 ;
unsigned int V_135 ;
int V_31 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_32 = V_32 ;
if ( ! V_125 ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_15 ) ;
return - V_123 ;
}
V_7 -> V_8 = ( const struct V_130 * ) V_133 -> V_136 ;
V_7 -> V_97 = V_7 -> V_8 ? false : true ;
V_7 -> V_34 = F_81 ( & V_7 -> V_32 -> V_33 , V_7 -> V_97 ? L_16 : L_17 ) ;
if ( F_82 ( V_7 -> V_34 ) ) {
F_25 ( & V_7 -> V_32 -> V_33 , L_18 ) ;
return F_83 ( V_7 -> V_34 ) ;
}
V_31 = F_64 ( V_7 -> V_34 ) ;
if ( V_31 < 0 )
goto V_137;
if ( V_7 -> V_97 )
V_31 = F_77 ( V_7 ) ;
else
V_31 = F_73 ( V_7 ) ;
if ( V_31 < 0 )
goto V_138;
if ( V_7 -> V_97 ) {
V_7 -> V_139 = 1 ;
V_135 = 0 ;
} else {
V_7 -> V_139 = F_84 ( V_125 -> V_140 ) ;
V_135 = V_125 -> V_140 ;
}
V_7 -> V_141 = F_85 ( V_7 -> V_139 * sizeof( * V_7 -> V_141 ) ,
V_142 ) ;
if ( V_7 -> V_141 == NULL ) {
V_31 = - V_143 ;
goto V_144;
}
if ( V_7 -> V_97 ) {
V_31 = F_71 ( & V_7 -> V_141 [ 0 ] ,
V_125 -> V_28 , V_125 -> V_28 ,
V_125 -> V_145 != 0 ,
V_125 -> V_146 != 0 , V_7 ) ;
if ( V_31 < 0 )
goto V_144;
} else {
unsigned int V_84 = V_135 ;
unsigned int V_147 ;
for ( V_147 = 0 ; V_147 < V_7 -> V_139 ; ++ V_147 ) {
unsigned int V_111 = F_86 ( V_84 ) - 1 ;
bool V_73 = V_147 == 1 || V_7 -> V_139 == 1 ;
bool V_108 = V_147 == 0 ;
V_31 = F_71 ( & V_7 -> V_141 [ V_147 ] , V_147 , V_111 ,
V_108 , V_73 ,
V_7 ) ;
if ( V_31 < 0 )
goto V_144;
V_84 &= ~ ( 1 << V_111 ) ;
}
}
F_87 ( V_32 , V_7 ) ;
return 0 ;
V_144:
F_88 ( V_7 -> V_141 ) ;
F_79 ( V_7 ) ;
V_138:
F_62 ( V_7 -> V_34 ) ;
V_137:
F_89 ( V_7 -> V_34 ) ;
return V_31 ;
}
static int F_90 ( struct V_131 * V_32 )
{
struct V_112 * V_7 = F_91 ( V_32 ) ;
int V_31 ;
if ( ! F_92 ( V_32 ) ) {
F_93 ( & V_32 -> V_33 ) ;
F_94 ( & V_32 -> V_33 ) ;
}
if ( V_7 ) {
F_51 ( & V_32 -> V_33 , L_19 ) ;
goto V_71;
}
V_7 = F_85 ( sizeof( * V_7 ) , V_142 ) ;
if ( V_7 == NULL )
return - V_143 ;
V_31 = F_80 ( V_7 , V_32 ) ;
if ( V_31 ) {
F_88 ( V_7 ) ;
F_95 ( & V_32 -> V_33 ) ;
return V_31 ;
}
if ( F_92 ( V_32 ) )
return 0 ;
V_71:
if ( V_7 -> V_109 || V_7 -> V_110 )
F_96 ( & V_32 -> V_33 ) ;
else
F_95 ( & V_32 -> V_33 ) ;
return 0 ;
}
static int F_97 ( struct V_131 * V_32 )
{
return - V_148 ;
}
static int T_4 F_98 ( void )
{
return F_99 ( & V_149 ) ;
}
static void T_5 F_100 ( void )
{
F_101 ( & V_149 ) ;
}
