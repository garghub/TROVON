static void F_1 ( T_1 V_1 , T_1 V_2 )
{
V_2 &= 0x00ffffff ;
F_2 ( V_2 , V_1 ) ;
}
static T_1 F_3 ( T_1 V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( T_1 V_1 , T_1 V_3 , T_1 V_2 )
{
T_1 V_4 = F_3 ( V_1 ) ;
V_4 &= ~ V_3 ;
V_4 |= V_2 & V_3 ;
F_1 ( V_1 , V_4 ) ;
}
static T_1 F_6 ( struct V_5 * V_6 , T_1 V_1 )
{
T_1 V_7 ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = F_3 ( ( T_1 ) ( V_6 -> V_10 + V_1 ) ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static void F_9 ( struct V_5 * V_6 ,
T_1 V_1 , T_1 V_3 , T_1 V_2 )
{
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
F_5 ( ( T_1 ) ( V_6 -> V_10 + V_1 ) , V_3 , V_2 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static struct V_5 * F_10 ( struct V_11 * V_12 )
{
return V_12 -> V_6 ;
}
static int F_11 ( struct V_11 * V_12 )
{
return V_12 -> V_13 ;
}
static int F_12 ( struct V_11 * V_12 )
{
return V_12 -> V_6 -> V_10 == V_12 -> V_10 ;
}
static struct V_14 * F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
return V_18 -> V_20 ;
}
static struct V_11 * F_14 ( struct V_14 * V_21 )
{
struct V_5 * V_6 = F_15 ( V_21 ) ;
if ( V_21 -> V_22 == 0 )
return & V_6 -> V_23 ;
else
return & V_6 -> V_24 ;
}
static struct V_11 * F_16 ( struct V_15 * V_16 )
{
return F_14 ( F_13 ( V_16 ) ) ;
}
static T_2 F_17 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_25 )
return NULL ;
return V_6 -> V_25 -> V_26 ;
}
static T_1 F_18 ( struct V_11 * V_12 )
{
int V_27 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
if ( ! V_6 -> V_25 )
return 0 ;
return V_27 ? V_6 -> V_25 -> V_28 :
V_6 -> V_25 -> V_29 ;
}
static inline int F_19 ( int V_30 )
{
return V_30 == V_31 ;
}
static inline int F_20 ( struct V_15 * V_16 )
{
return F_19 ( V_16 -> V_30 ) ;
}
static inline struct V_32 * F_21 ( struct V_11 * V_12 ,
int V_33 )
{
return V_33 ? & V_12 -> V_34 : & V_12 -> V_35 ;
}
static T_1 F_22 ( struct V_11 * V_12 , int V_33 )
{
int V_27 = F_12 ( V_12 ) ;
T_1 V_36 ;
if ( V_27 )
V_36 = V_33 ? V_37 : V_38 ;
else
V_36 = V_33 ? V_39 : V_40 ;
return V_36 ;
}
static void F_23 ( struct V_11 * V_12 ,
int V_33 ,
struct V_15 * V_16 ,
T_1 V_41 ,
T_1 V_42 )
{
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
V_43 -> V_16 = V_16 ;
V_43 -> V_44 = V_41 ;
V_43 -> V_45 = 0 ;
V_43 -> V_42 = V_42 ;
V_43 -> V_46 = 0 ;
V_43 -> V_47 = - 1 ;
V_43 -> V_48 = - 1 ;
}
static void F_24 ( struct V_11 * V_12 , int V_33 )
{
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
struct V_14 * V_21 = F_13 ( V_43 -> V_16 ) ;
if ( V_43 -> V_47 > 0 )
F_25 ( V_21 -> V_49 , L_1 , V_43 -> V_47 ) ;
if ( V_43 -> V_48 > 0 )
F_25 ( V_21 -> V_49 , L_2 , V_43 -> V_48 ) ;
V_43 -> V_16 = NULL ;
V_43 -> V_44 = 0 ;
V_43 -> V_45 = 0 ;
V_43 -> V_42 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_47 = 0 ;
V_43 -> V_48 = 0 ;
}
static int F_26 ( struct V_11 * V_12 , int V_33 )
{
T_1 V_50 ;
int V_51 ;
V_50 = V_33 ?
F_27 ( V_12 , V_52 ) :
F_27 ( V_12 , V_53 ) ;
V_51 = 0x1ff & ( V_50 >> 8 ) ;
V_51 *= V_12 -> V_54 ;
return V_51 ;
}
static int F_28 ( int V_55 , int V_56 )
{
return V_55 / V_56 ;
}
static int F_29 ( int V_57 , int V_56 )
{
return V_57 * V_56 ;
}
static int F_30 ( struct V_11 * V_12 , int V_33 )
{
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
struct V_15 * V_16 = V_43 -> V_16 ;
struct V_58 * V_59 = V_16 -> V_59 ;
return F_31 ( V_59 , 1 ) / V_12 -> V_54 ;
}
static void F_32 ( struct V_11 * V_12 )
{
T_1 V_60 = F_27 ( V_12 , V_52 ) ;
T_1 V_61 = F_27 ( V_12 , V_53 ) ;
if ( V_60 & V_62 )
V_12 -> V_34 . V_47 ++ ;
if ( V_60 & V_63 )
V_12 -> V_34 . V_48 ++ ;
if ( V_61 & V_62 )
V_12 -> V_35 . V_47 ++ ;
if ( V_61 & V_63 )
V_12 -> V_35 . V_48 ++ ;
F_33 ( V_12 , V_52 , 0 ) ;
F_33 ( V_12 , V_53 , 0 ) ;
}
static T_3 * F_34 ( struct V_11 * V_12 , int V_30 )
{
int V_33 = F_19 ( V_30 ) ;
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
return V_43 -> V_16 -> V_59 -> V_64 + V_43 -> V_45 ;
}
static void F_35 ( struct V_11 * V_12 , int V_57 )
{
T_4 * V_65 ;
int V_66 ;
V_65 = ( T_4 * ) F_34 ( V_12 , V_31 ) ;
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ )
F_33 ( V_12 , V_67 , ( ( T_1 ) * ( V_65 + V_66 ) << 8 ) ) ;
}
static void F_36 ( struct V_11 * V_12 , int V_57 )
{
T_4 * V_65 ;
int V_66 ;
V_65 = ( T_4 * ) F_34 ( V_12 , V_68 ) ;
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ )
* ( V_65 + V_66 ) = ( T_4 ) ( F_27 ( V_12 , V_69 ) >> 8 ) ;
}
static void F_37 ( struct V_11 * V_12 , int V_57 )
{
T_1 * V_65 ;
int V_66 ;
V_65 = ( T_1 * ) F_34 ( V_12 , V_31 ) ;
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ )
F_33 ( V_12 , V_67 , * ( V_65 + V_66 ) ) ;
}
static void F_38 ( struct V_11 * V_12 , int V_57 )
{
T_1 * V_65 ;
int V_66 ;
V_65 = ( T_1 * ) F_34 ( V_12 , V_68 ) ;
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ )
* ( V_65 + V_66 ) = F_27 ( V_12 , V_69 ) ;
}
static void F_39 ( struct V_11 * V_12 , int V_33 )
{
T_1 V_2 = F_40 ( 1 , F_22 ( V_12 , V_33 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_41 ( V_6 , V_70 , V_2 , V_2 ) ;
F_41 ( V_6 , V_71 , V_2 , V_2 ) ;
}
static void F_42 ( struct V_11 * V_12 , int V_33 )
{
T_1 V_2 = F_40 ( 1 , F_22 ( V_12 , V_33 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_41 ( V_6 , V_70 , V_2 , 0 ) ;
F_41 ( V_6 , V_71 , V_2 , 0 ) ;
}
static T_1 F_43 ( struct V_5 * V_6 )
{
return F_44 ( V_6 , V_72 ) ;
}
static void F_45 ( struct V_11 * V_12 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
V_2 |= F_40 ( 1 , F_22 ( V_12 , 0 ) ) ;
V_2 |= F_40 ( 1 , F_22 ( V_12 , 1 ) ) ;
F_41 ( V_6 , V_72 , V_2 , 0 ) ;
}
static void F_46 ( struct V_11 * V_12 , int V_73 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_3 , V_4 ;
if ( V_6 -> V_74 -> V_75 < 2 ) {
F_47 ( L_3 , V_76 ) ;
return;
}
V_3 = V_77 | V_78 ;
V_4 = V_73 ? V_3 : 0 ;
F_12 ( V_12 ) ?
F_41 ( V_6 , V_79 , V_3 , V_4 ) :
F_41 ( V_6 , V_80 , V_3 , V_4 ) ;
}
static void F_48 ( struct V_5 * V_6 ,
struct V_81 * V_49 ,
int V_73 )
{
F_49 ( V_49 ) ;
if ( V_73 ) {
F_50 ( V_6 , V_82 , V_83 , V_83 ) ;
F_50 ( V_6 , V_82 , V_84 | V_85 , 0 ) ;
} else {
F_50 ( V_6 , V_82 , V_83 , 0 ) ;
}
F_51 ( V_49 ) ;
}
static void F_52 ( struct V_11 * V_12 , int V_73 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_86 = F_12 ( V_12 ) ? V_84 : V_85 ;
T_1 V_87 = F_12 ( V_12 ) ? V_88 : V_89 ;
int V_90 = F_11 ( V_12 ) ;
F_50 ( V_6 , V_82 , V_86 , ( V_73 ) ? V_86 : 0 ) ;
if ( V_90 )
F_50 ( V_6 , V_91 , V_87 , ( V_73 ) ? V_87 : 0 ) ;
}
static void F_53 ( struct V_11 * V_12 ,
int V_33 ,
struct V_14 * V_21 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
T_1 V_36 , V_66 ;
V_36 = F_54 ( V_6 , V_92 ) ;
V_36 >>= F_22 ( V_12 , V_33 ) ;
V_36 &= V_93 ;
V_43 -> V_94 = 256 << V_36 ;
F_55 ( V_21 -> V_49 , L_4 , V_43 -> V_94 ) ;
for ( V_66 = 1 ; V_66 < V_12 -> V_54 ; V_66 <<= 1 )
V_43 -> V_94 >>= 1 ;
F_55 ( V_21 -> V_49 , L_5 ,
V_12 -> V_54 , V_43 -> V_94 ) ;
if ( V_33 ) {
F_33 ( V_12 , V_95 , V_96 ) ;
F_56 ( V_12 , V_95 , V_97 , V_97 ) ;
} else {
F_33 ( V_12 , V_98 , V_96 ) ;
F_56 ( V_12 , V_98 , V_97 , V_97 ) ;
}
}
static int F_57 ( struct V_11 * V_12 , int V_30 )
{
struct V_58 * V_59 ;
struct V_15 * V_16 = NULL ;
int V_33 = F_19 ( V_30 ) ;
struct V_32 * V_43 = F_21 ( V_12 , V_33 ) ;
int V_99 ;
int V_51 ;
int V_100 ;
int V_101 ;
int V_102 ;
void (* F_58)( struct V_11 * V_12 , int V_103 );
if ( ! V_12 ||
! V_43 -> V_16 ||
! V_43 -> V_16 -> V_59 )
return - V_104 ;
V_102 = 0 ;
V_16 = V_43 -> V_16 ;
V_59 = V_16 -> V_59 ;
if ( V_43 -> V_45 >=
F_59 ( V_43 -> V_46 + 1 , V_43 -> V_42 ) ) {
V_102 = 1 ;
V_43 -> V_46 = ( V_43 -> V_46 + 1 ) % V_59 -> V_105 ;
if ( 0 == V_43 -> V_46 )
V_43 -> V_45 = 0 ;
}
V_101 = F_30 ( V_12 , V_33 ) ;
V_99 = F_28 ( V_43 -> V_44 - V_43 -> V_45 ,
V_101 ) ;
if ( V_33 ) {
V_100 = V_43 -> V_94 * V_12 -> V_54 ;
V_100 -= F_26 ( V_12 , V_33 ) ;
V_51 = V_99 ;
switch ( V_101 ) {
case 2 :
F_58 = F_35 ;
break;
case 4 :
F_58 = F_37 ;
break;
default:
return - V_104 ;
}
} else {
V_100 = V_99 ;
V_51 = F_26 ( V_12 , V_33 ) ;
switch ( V_101 ) {
case 2 :
F_58 = F_36 ;
break;
case 4 :
F_58 = F_38 ;
break;
default:
return - V_104 ;
}
}
V_51 = F_60 ( V_51 , V_100 ) ;
F_58 ( V_12 , V_51 ) ;
V_43 -> V_45 += F_59 ( V_51 , V_101 ) ;
if ( V_102 )
F_61 ( V_16 ) ;
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
return F_57 ( V_12 , V_68 ) ;
}
static int F_63 ( struct V_11 * V_12 )
{
return F_57 ( V_12 , V_31 ) ;
}
static T_5 F_64 ( int V_106 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_72 = F_43 ( V_6 ) ;
F_50 ( V_6 , V_82 , V_107 , 0 ) ;
F_50 ( V_6 , V_82 , V_107 , V_107 ) ;
if ( V_72 & F_40 ( 1 , V_37 ) )
F_63 ( & V_6 -> V_23 ) ;
if ( V_72 & F_40 ( 1 , V_39 ) )
F_63 ( & V_6 -> V_24 ) ;
if ( V_72 & F_40 ( 1 , V_38 ) )
F_62 ( & V_6 -> V_23 ) ;
if ( V_72 & F_40 ( 1 , V_40 ) )
F_62 ( & V_6 -> V_24 ) ;
F_32 ( & V_6 -> V_23 ) ;
F_32 ( & V_6 -> V_24 ) ;
F_45 ( & V_6 -> V_23 ) ;
F_45 ( & V_6 -> V_24 ) ;
return V_108 ;
}
static int F_65 ( struct V_15 * V_16 ,
struct V_14 * V_21 )
{
struct V_11 * V_12 = F_16 ( V_16 ) ;
T_1 V_8 = F_18 ( V_12 ) ;
T_1 V_2 ;
int V_33 = F_20 ( V_16 ) ;
F_49 ( V_21 -> V_49 ) ;
V_2 = 0 ;
if ( V_109 & V_8 )
V_2 |= 1 << 12 ;
if ( V_110 & V_8 )
V_2 |= 1 << 8 ;
if ( V_111 & V_8 )
V_2 |= 1 << 4 ;
if ( V_112 & V_8 )
V_2 |= 1 << 0 ;
F_33 ( V_12 , V_113 , V_2 ) ;
F_42 ( V_12 , V_33 ) ;
F_45 ( V_12 ) ;
F_53 ( V_12 , V_33 , V_21 ) ;
return 0 ;
}
static void F_66 ( struct V_15 * V_16 ,
struct V_14 * V_21 )
{
struct V_11 * V_12 = F_16 ( V_16 ) ;
int V_33 = F_20 ( V_16 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_26 = F_17 ( V_6 ) ;
F_42 ( V_12 , V_33 ) ;
if ( F_11 ( V_12 ) )
V_26 ( V_21 -> V_49 , F_12 ( V_12 ) , V_12 -> V_114 , 0 ) ;
V_12 -> V_114 = 0 ;
F_51 ( V_21 -> V_49 ) ;
}
static int F_67 ( struct V_15 * V_16 , int V_115 ,
struct V_14 * V_21 )
{
struct V_11 * V_12 = F_16 ( V_16 ) ;
struct V_58 * V_59 = V_16 -> V_59 ;
int V_33 = F_20 ( V_16 ) ;
int V_7 = 0 ;
switch ( V_115 ) {
case V_116 :
F_23 ( V_12 , V_33 , V_16 ,
F_31 ( V_59 , V_59 -> V_117 ) ,
F_31 ( V_59 , V_59 -> V_118 ) ) ;
V_7 = V_33 ? F_63 ( V_12 ) : F_62 ( V_12 ) ;
F_39 ( V_12 , V_33 ) ;
F_68 ( V_12 ) ;
break;
case V_119 :
F_69 ( V_12 ) ;
F_42 ( V_12 , V_33 ) ;
F_24 ( V_12 , V_33 ) ;
break;
}
return V_7 ;
}
static int F_70 ( struct V_11 * V_12 , unsigned int V_120 )
{
T_1 V_2 = 0 ;
switch ( V_120 & V_121 ) {
case V_122 :
V_2 = V_123 ;
V_12 -> V_54 = 2 ;
break;
case V_124 :
V_2 = V_125 ;
V_12 -> V_54 = 2 ;
break;
default:
return - V_104 ;
}
F_33 ( V_12 , V_126 , V_2 ) ;
F_33 ( V_12 , V_127 , V_2 ) ;
return 0 ;
}
static int F_71 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_2 = 0 ;
if ( V_6 -> V_74 -> V_75 < 2 )
return - V_104 ;
V_2 = V_128 | V_129 | V_125 ;
V_12 -> V_54 = 2 ;
F_46 ( V_12 , 1 ) ;
F_56 ( V_12 , V_130 , V_131 , V_131 ) ;
F_33 ( V_12 , V_126 , V_2 ) ;
F_33 ( V_12 , V_127 , V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_14 * V_21 , unsigned int V_120 )
{
struct V_11 * V_12 = F_14 ( V_21 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_26 = F_17 ( V_6 ) ;
T_1 V_8 = F_18 ( V_12 ) ;
T_1 V_2 = 0 ;
int V_7 ;
F_49 ( V_21 -> V_49 ) ;
switch ( V_120 & V_132 ) {
case V_133 :
V_2 = V_134 | V_135 ;
V_12 -> V_13 = 1 ;
break;
case V_136 :
break;
default:
V_7 = - V_104 ;
goto V_137;
}
if ( F_11 ( V_12 ) && ! V_26 ) {
F_25 ( V_21 -> V_49 , L_6 ) ;
V_7 = - V_104 ;
goto V_137;
}
F_56 ( V_12 , V_138 , ( V_134 | V_135 ) , V_2 ) ;
switch ( V_8 & V_139 ) {
case V_140 :
V_7 = F_70 ( V_12 , V_120 & V_121 ) ;
break;
case V_141 :
V_7 = F_71 ( V_12 ) ;
break;
default:
V_7 = - V_104 ;
}
V_137:
F_51 ( V_21 -> V_49 ) ;
return V_7 ;
}
static int F_73 ( struct V_15 * V_16 ,
struct V_142 * V_143 ,
struct V_14 * V_21 )
{
struct V_11 * V_12 = F_16 ( V_16 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_2 V_26 = F_17 ( V_6 ) ;
int V_144 = V_6 -> V_74 -> V_75 ;
long V_114 = F_74 ( V_143 ) ;
int V_7 ;
if ( ! F_11 ( V_12 ) )
return 0 ;
V_7 = V_26 ( V_21 -> V_49 , F_12 ( V_12 ) , V_114 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_12 -> V_114 = V_114 ;
if ( V_7 > 0 ) {
T_1 V_2 = 0 ;
switch ( V_7 & V_145 ) {
default:
case V_146 :
V_2 |= ( 0x0 << 12 ) ;
break;
case V_147 :
V_2 |= ( 0x1 << 12 ) ;
break;
case V_148 :
V_2 |= ( 0x2 << 12 ) ;
break;
case V_149 :
V_2 |= ( 0x3 << 12 ) ;
break;
case V_150 :
if ( V_144 < 2 )
F_25 ( V_21 -> V_49 , L_7 ) ;
else
V_2 |= ( 0x4 << 12 ) ;
break;
}
switch ( V_7 & V_151 ) {
default:
case V_152 :
V_2 |= ( 0x0 << 8 ) ;
break;
case V_153 :
V_2 |= ( 0x1 << 8 ) ;
break;
case V_154 :
V_2 |= ( 0x2 << 8 ) ;
break;
case V_155 :
V_2 |= ( 0x3 << 8 ) ;
break;
case V_156 :
V_2 |= ( 0x4 << 8 ) ;
break;
case V_157 :
if ( V_144 < 2 )
F_25 ( V_21 -> V_49 , L_7 ) ;
else
V_2 |= ( 0x7 << 8 ) ;
break;
}
F_56 ( V_12 , V_138 , ( V_158 | V_159 ) , V_2 ) ;
F_75 ( 10 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_76 ( struct V_15 * V_16 )
{
struct V_58 * V_59 = V_16 -> V_59 ;
int V_7 = 0 ;
F_77 ( V_16 , & V_160 ) ;
V_7 = F_78 ( V_59 ,
V_161 ) ;
return V_7 ;
}
static int F_79 ( struct V_15 * V_16 ,
struct V_142 * V_162 )
{
return F_80 ( V_16 ,
F_81 ( V_162 ) ) ;
}
static int F_82 ( struct V_15 * V_16 )
{
return F_83 ( V_16 ) ;
}
static T_6 F_84 ( struct V_15 * V_16 )
{
struct V_58 * V_59 = V_16 -> V_59 ;
struct V_11 * V_12 = F_16 ( V_16 ) ;
struct V_32 * V_43 = F_21 ( V_12 , F_20 ( V_16 ) ) ;
long V_163 ;
V_163 = ( V_43 -> V_45 - 1 ) ;
if ( V_163 < 0 )
V_163 = 0 ;
return F_85 ( V_59 , V_163 ) ;
}
static void F_86 ( struct V_164 * V_165 )
{
F_87 ( V_165 ) ;
}
static int F_88 ( struct V_166 * V_167 ,
struct V_14 * V_21 ,
struct V_164 * V_165 )
{
return F_89 (
V_165 ,
V_168 ,
F_90 ( V_169 ) ,
V_170 , V_171 ) ;
}
static int F_91 ( struct V_172 * V_173 )
{
struct V_5 * V_6 ;
const struct V_174 * V_175 ;
struct V_176 * V_177 ;
unsigned int V_106 ;
int V_7 ;
V_175 = V_173 -> V_175 ;
if ( ! V_175 ) {
F_25 ( & V_173 -> V_49 , L_8 ) ;
return - V_178 ;
}
V_177 = F_92 ( V_173 , V_179 , 0 ) ;
V_106 = F_93 ( V_173 , 0 ) ;
if ( ! V_177 || ( int ) V_106 <= 0 ) {
F_25 ( & V_173 -> V_49 , L_9 ) ;
V_7 = - V_178 ;
goto exit;
}
V_6 = F_94 ( sizeof( * V_6 ) , V_169 ) ;
if ( ! V_6 ) {
F_25 ( & V_173 -> V_49 , L_10 ) ;
V_7 = - V_180 ;
goto exit;
}
V_6 -> V_10 = F_95 ( V_177 -> V_65 , F_96 ( V_177 ) ) ;
if ( ! V_6 -> V_10 ) {
V_7 = - V_181 ;
F_25 ( & V_173 -> V_49 , L_11 ) ;
goto V_182;
}
V_6 -> V_106 = V_106 ;
V_6 -> V_25 = V_173 -> V_49 . V_183 ;
V_6 -> V_74 = (struct V_184 * ) V_175 -> V_185 ;
F_97 ( & V_6 -> V_9 ) ;
V_6 -> V_23 . V_10 = V_6 -> V_10 ;
V_6 -> V_23 . V_6 = V_6 ;
V_6 -> V_24 . V_10 = V_6 -> V_10 + 0x40 ;
V_6 -> V_24 . V_6 = V_6 ;
F_98 ( & V_173 -> V_49 ) ;
F_99 ( & V_173 -> V_49 , V_6 ) ;
F_100 ( V_6 , & V_173 -> V_49 ) ;
V_7 = F_101 ( V_106 , & F_64 , V_186 ,
V_175 -> V_187 , V_6 ) ;
if ( V_7 ) {
F_25 ( & V_173 -> V_49 , L_12 ) ;
goto V_188;
}
V_7 = F_102 ( & V_173 -> V_49 , & V_189 ) ;
if ( V_7 < 0 ) {
F_25 ( & V_173 -> V_49 , L_13 ) ;
goto V_190;
}
V_7 = F_103 ( & V_173 -> V_49 , V_191 ,
F_104 ( V_191 ) ) ;
if ( V_7 < 0 ) {
F_25 ( & V_173 -> V_49 , L_14 ) ;
goto V_192;
}
return V_7 ;
V_192:
F_105 ( & V_173 -> V_49 ) ;
V_190:
F_106 ( V_106 , V_6 ) ;
V_188:
F_107 ( V_6 -> V_10 ) ;
F_108 ( & V_173 -> V_49 ) ;
V_182:
F_109 ( V_6 ) ;
V_6 = NULL ;
exit:
return V_7 ;
}
static int F_110 ( struct V_172 * V_173 )
{
struct V_5 * V_6 ;
V_6 = F_111 ( & V_173 -> V_49 ) ;
F_112 ( V_6 , & V_173 -> V_49 ) ;
F_106 ( V_6 -> V_106 , V_6 ) ;
F_108 ( & V_173 -> V_49 ) ;
F_113 ( & V_173 -> V_49 , F_104 ( V_191 ) ) ;
F_105 ( & V_173 -> V_49 ) ;
F_107 ( V_6 -> V_10 ) ;
F_109 ( V_6 ) ;
return 0 ;
}
static void F_114 ( struct V_11 * V_12 ,
struct V_81 * V_49 ,
T_2 V_26 )
{
V_12 -> V_193 = F_27 ( V_12 , V_126 ) ;
V_12 -> V_194 = F_27 ( V_12 , V_127 ) ;
V_12 -> V_195 = F_27 ( V_12 , V_138 ) ;
V_12 -> V_196 = F_27 ( V_12 , V_113 ) ;
V_12 -> V_197 = F_27 ( V_12 , V_130 ) ;
if ( F_11 ( V_12 ) )
V_26 ( V_49 , F_12 ( V_12 ) , V_12 -> V_114 , 0 ) ;
}
static void F_115 ( struct V_11 * V_12 ,
struct V_81 * V_49 ,
T_2 V_26 )
{
F_33 ( V_12 , V_126 , V_12 -> V_193 ) ;
F_33 ( V_12 , V_127 , V_12 -> V_194 ) ;
F_33 ( V_12 , V_138 , V_12 -> V_195 ) ;
F_33 ( V_12 , V_113 , V_12 -> V_196 ) ;
F_33 ( V_12 , V_130 , V_12 -> V_197 ) ;
if ( F_11 ( V_12 ) )
V_26 ( V_49 , F_12 ( V_12 ) , V_12 -> V_114 , 1 ) ;
}
static int F_116 ( struct V_81 * V_49 )
{
struct V_5 * V_6 = F_111 ( V_49 ) ;
T_2 V_26 = F_17 ( V_6 ) ;
F_49 ( V_49 ) ;
F_114 ( & V_6 -> V_23 , V_49 , V_26 ) ;
F_114 ( & V_6 -> V_24 , V_49 , V_26 ) ;
V_6 -> V_198 = F_44 ( V_6 , V_79 ) ;
V_6 -> V_199 = F_44 ( V_6 , V_80 ) ;
V_6 -> V_200 = F_44 ( V_6 , V_71 ) ;
V_6 -> V_201 = F_44 ( V_6 , V_70 ) ;
V_6 -> V_202 = F_54 ( V_6 , V_91 ) ;
V_6 -> V_203 = F_54 ( V_6 , V_82 ) ;
F_112 ( V_6 , V_49 ) ;
F_51 ( V_49 ) ;
return 0 ;
}
static int F_117 ( struct V_81 * V_49 )
{
struct V_5 * V_6 = F_111 ( V_49 ) ;
T_2 V_26 = F_17 ( V_6 ) ;
F_49 ( V_49 ) ;
F_100 ( V_6 , V_49 ) ;
F_50 ( V_6 , V_82 , 0xffff , V_6 -> V_203 ) ;
F_50 ( V_6 , V_91 , 0xffff , V_6 -> V_202 ) ;
F_41 ( V_6 , V_79 , 0xffff , V_6 -> V_198 ) ;
F_41 ( V_6 , V_80 , 0xffff , V_6 -> V_199 ) ;
F_41 ( V_6 , V_71 , 0xffff , V_6 -> V_200 ) ;
F_41 ( V_6 , V_70 , 0xffff , V_6 -> V_201 ) ;
F_115 ( & V_6 -> V_23 , V_49 , V_26 ) ;
F_115 ( & V_6 -> V_24 , V_49 , V_26 ) ;
F_51 ( V_49 ) ;
return 0 ;
}
static int F_118 ( struct V_81 * V_49 )
{
return 0 ;
}
static int T_7 F_119 ( void )
{
return F_120 ( & V_204 ) ;
}
static void T_8 F_121 ( void )
{
F_122 ( & V_204 ) ;
}
