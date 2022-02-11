static void F_1 ( T_1 T_2 * V_1 , T_1 V_2 )
{
V_2 &= 0x00ffffff ;
F_2 ( V_2 , V_1 ) ;
}
static T_1 F_3 ( T_1 T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( T_1 T_2 * V_1 , T_1 V_3 , T_1 V_2 )
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
V_7 = F_3 ( V_6 -> V_10 + V_1 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static void F_9 ( struct V_5 * V_6 ,
T_1 V_1 , T_1 V_3 , T_1 V_2 )
{
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
F_5 ( V_6 -> V_10 + V_1 , V_3 , V_2 ) ;
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
static int F_13 ( struct V_11 * V_12 )
{
return V_12 -> V_14 ;
}
static struct V_15 * F_14 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
return V_19 -> V_21 ;
}
static struct V_11 * F_15 ( struct V_15 * V_22 )
{
struct V_5 * V_6 = F_16 ( V_22 ) ;
if ( V_22 -> V_23 == 0 )
return & V_6 -> V_24 ;
else
return & V_6 -> V_25 ;
}
static struct V_11 * F_17 ( struct V_16 * V_17 )
{
return F_15 ( F_14 ( V_17 ) ) ;
}
static T_3 F_18 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_26 )
return NULL ;
return V_6 -> V_26 -> V_27 ;
}
static T_1 F_19 ( struct V_11 * V_12 )
{
int V_28 = F_12 ( V_12 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
if ( ! V_6 -> V_26 )
return 0 ;
return V_28 ? V_6 -> V_26 -> V_29 :
V_6 -> V_26 -> V_30 ;
}
static inline int F_20 ( int V_31 )
{
return V_31 == V_32 ;
}
static inline int F_21 ( struct V_16 * V_17 )
{
return F_20 ( V_17 -> V_31 ) ;
}
static inline struct V_33 * F_22 ( struct V_11 * V_12 ,
int V_34 )
{
return V_34 ? & V_12 -> V_35 : & V_12 -> V_36 ;
}
static T_1 F_23 ( struct V_11 * V_12 , int V_34 )
{
int V_28 = F_12 ( V_12 ) ;
T_1 V_37 ;
if ( V_28 )
V_37 = V_34 ? V_38 : V_39 ;
else
V_37 = V_34 ? V_40 : V_41 ;
return V_37 ;
}
static int F_24 ( struct V_11 * V_12 , int V_42 )
{
return V_42 * V_12 -> V_43 ;
}
static int F_25 ( struct V_11 * V_12 , int V_44 )
{
return V_44 / V_12 -> V_43 ;
}
static int F_26 ( struct V_11 * V_12 ,
int V_34 )
{
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
int V_7 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = ! ! V_45 -> V_17 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static void F_27 ( struct V_11 * V_12 ,
int V_34 ,
struct V_16 * V_17 )
{
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
struct V_46 * V_47 = V_17 -> V_47 ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_45 -> V_17 = V_17 ;
V_45 -> V_48 = F_24 ( V_12 , V_47 -> V_49 ) ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = F_24 ( V_12 , V_47 -> V_52 ) ;
V_45 -> V_53 = 0 ;
V_45 -> V_54 = - 1 ;
V_45 -> V_55 = - 1 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_28 ( struct V_11 * V_12 , int V_34 )
{
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
struct V_15 * V_22 = F_14 ( V_45 -> V_17 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
if ( V_45 -> V_54 > 0 )
F_29 ( V_22 -> V_56 , L_1 , V_45 -> V_54 ) ;
if ( V_45 -> V_55 > 0 )
F_29 ( V_22 -> V_56 , L_2 , V_45 -> V_55 ) ;
V_45 -> V_17 = NULL ;
V_45 -> V_48 = 0 ;
V_45 -> V_50 = 0 ;
V_45 -> V_51 = 0 ;
V_45 -> V_53 = 0 ;
V_45 -> V_54 = 0 ;
V_45 -> V_55 = 0 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static int F_30 ( struct V_11 * V_12 , int V_34 )
{
T_1 V_57 ;
int V_42 ;
V_57 = V_34 ?
F_31 ( V_12 , V_58 ) :
F_31 ( V_12 , V_59 ) ;
V_42 = 0x1ff & ( V_57 >> 8 ) ;
return F_24 ( V_12 , V_42 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
T_1 V_60 = F_31 ( V_12 , V_58 ) ;
T_1 V_61 = F_31 ( V_12 , V_59 ) ;
if ( V_60 & V_62 )
V_12 -> V_35 . V_54 ++ ;
if ( V_60 & V_63 )
V_12 -> V_35 . V_55 ++ ;
if ( V_61 & V_62 )
V_12 -> V_36 . V_54 ++ ;
if ( V_61 & V_63 )
V_12 -> V_36 . V_55 ++ ;
F_33 ( V_12 , V_58 , 0 ) ;
F_33 ( V_12 , V_59 , 0 ) ;
}
static T_4 * F_34 ( struct V_11 * V_12 , int V_31 )
{
int V_34 = F_20 ( V_31 ) ;
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
struct V_46 * V_47 = V_45 -> V_17 -> V_47 ;
return V_47 -> V_64 +
F_35 ( V_47 , V_45 -> V_50 ) ;
}
static void F_36 ( struct V_11 * V_12 , int V_65 )
{
T_5 * V_66 ;
int V_67 ;
V_66 = ( T_5 * ) F_34 ( V_12 , V_32 ) ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
F_33 ( V_12 , V_68 , ( ( T_1 ) * ( V_66 + V_67 ) << 8 ) ) ;
}
static void F_37 ( struct V_11 * V_12 , int V_65 )
{
T_5 * V_66 ;
int V_67 ;
V_66 = ( T_5 * ) F_34 ( V_12 , V_69 ) ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
* ( V_66 + V_67 ) = ( T_5 ) ( F_31 ( V_12 , V_70 ) >> 8 ) ;
}
static void F_38 ( struct V_11 * V_12 , int V_65 )
{
T_1 * V_66 ;
int V_67 ;
V_66 = ( T_1 * ) F_34 ( V_12 , V_32 ) ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
F_33 ( V_12 , V_68 , * ( V_66 + V_67 ) ) ;
}
static void F_39 ( struct V_11 * V_12 , int V_65 )
{
T_1 * V_66 ;
int V_67 ;
V_66 = ( T_1 * ) F_34 ( V_12 , V_69 ) ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
* ( V_66 + V_67 ) = F_31 ( V_12 , V_70 ) ;
}
static void F_40 ( struct V_11 * V_12 , int V_34 )
{
T_1 V_2 = F_41 ( 1 , F_23 ( V_12 , V_34 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_42 ( V_6 , V_71 , V_2 , V_2 ) ;
F_42 ( V_6 , V_72 , V_2 , V_2 ) ;
}
static void F_43 ( struct V_11 * V_12 , int V_34 )
{
T_1 V_2 = F_41 ( 1 , F_23 ( V_12 , V_34 ) ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
F_42 ( V_6 , V_71 , V_2 , 0 ) ;
F_42 ( V_6 , V_72 , V_2 , 0 ) ;
}
static T_1 F_44 ( struct V_5 * V_6 )
{
return F_45 ( V_6 , V_73 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
V_2 |= F_41 ( 1 , F_23 ( V_12 , 0 ) ) ;
V_2 |= F_41 ( 1 , F_23 ( V_12 , 1 ) ) ;
F_42 ( V_6 , V_73 , V_2 , 0 ) ;
}
static void F_47 ( struct V_11 * V_12 , int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_3 , V_4 ;
if ( V_6 -> V_75 -> V_76 < 2 ) {
F_48 ( L_3 , V_77 ) ;
return;
}
V_3 = V_78 | V_79 ;
V_4 = V_74 ? V_3 : 0 ;
F_12 ( V_12 ) ?
F_42 ( V_6 , V_80 , V_3 , V_4 ) :
F_42 ( V_6 , V_81 , V_3 , V_4 ) ;
}
static int F_49 ( struct V_82 * V_56 , struct V_11 * V_12 ,
long V_83 , int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_3 V_27 = F_18 ( V_6 ) ;
int V_84 = V_6 -> V_75 -> V_76 ;
int V_7 ;
V_7 = V_27 ( V_56 , F_12 ( V_12 ) , V_83 , V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_74 )
return 0 ;
if ( V_7 > 0 ) {
T_1 V_2 = 0 ;
switch ( V_7 & V_85 ) {
default:
case V_86 :
V_2 |= ( 0x0 << 12 ) ;
break;
case V_87 :
V_2 |= ( 0x1 << 12 ) ;
break;
case V_88 :
V_2 |= ( 0x2 << 12 ) ;
break;
case V_89 :
V_2 |= ( 0x3 << 12 ) ;
break;
case V_90 :
if ( V_84 < 2 )
F_29 ( V_56 , L_4 ) ;
else
V_2 |= ( 0x4 << 12 ) ;
break;
}
switch ( V_7 & V_91 ) {
default:
case V_92 :
V_2 |= ( 0x0 << 8 ) ;
break;
case V_93 :
V_2 |= ( 0x1 << 8 ) ;
break;
case V_94 :
V_2 |= ( 0x2 << 8 ) ;
break;
case V_95 :
V_2 |= ( 0x3 << 8 ) ;
break;
case V_96 :
V_2 |= ( 0x4 << 8 ) ;
break;
case V_97 :
if ( V_84 < 2 )
F_29 ( V_56 , L_4 ) ;
else
V_2 |= ( 0x7 << 8 ) ;
break;
}
F_50 ( V_12 , V_98 , ( V_99 | V_100 ) , V_2 ) ;
F_51 ( 10 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static void F_52 ( struct V_11 * V_12 , int V_34 , int V_74 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_101 = F_12 ( V_12 ) ? V_102 : V_103 ;
if ( V_74 )
F_40 ( V_12 , V_34 ) ;
else
F_43 ( V_12 , V_34 ) ;
if ( F_11 ( V_12 ) )
F_53 ( V_6 , V_104 , V_101 , ( V_74 ) ? V_101 : 0 ) ;
}
static void F_54 ( struct V_11 * V_12 ,
int V_34 ,
struct V_82 * V_56 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
T_1 V_37 , V_67 ;
int V_105 ;
V_37 = F_55 ( V_6 , V_106 ) ;
V_37 >>= F_23 ( V_12 , V_34 ) ;
V_37 &= V_107 ;
V_105 = 256 << V_37 ;
F_56 ( V_56 , L_5 , V_105 ) ;
for ( V_67 = 1 ; V_67 < V_12 -> V_43 ; V_67 <<= 1 )
V_105 >>= 1 ;
F_56 ( V_56 , L_6 ,
V_12 -> V_43 , V_105 ) ;
V_45 -> V_108 = F_24 ( V_12 , V_105 ) ;
if ( V_34 ) {
F_33 ( V_12 , V_109 , V_110 ) ;
F_50 ( V_12 , V_109 , V_111 , V_111 ) ;
} else {
F_33 ( V_12 , V_112 , V_110 ) ;
F_50 ( V_12 , V_112 , V_111 , V_111 ) ;
}
}
static int F_57 ( struct V_11 * V_12 , int V_31 )
{
struct V_46 * V_47 ;
struct V_16 * V_17 = NULL ;
int V_34 = F_20 ( V_31 ) ;
struct V_33 * V_45 = F_22 ( V_12 , V_34 ) ;
int V_113 ;
int V_114 ;
int V_44 ;
int V_115 ;
int V_116 ;
void (* F_58)( struct V_11 * V_12 , int V_117 );
if ( ! V_12 ||
! V_45 -> V_17 ||
! V_45 -> V_17 -> V_47 )
return - V_118 ;
V_116 = 0 ;
V_17 = V_45 -> V_17 ;
V_47 = V_17 -> V_47 ;
if ( V_45 -> V_50 >=
V_45 -> V_51 * ( V_45 -> V_53 + 1 ) ) {
V_116 = 1 ;
V_45 -> V_53 = ( V_45 -> V_53 + 1 ) % V_47 -> V_119 ;
if ( 0 == V_45 -> V_53 )
V_45 -> V_50 = 0 ;
}
V_114 = F_35 ( V_47 , 1 ) ;
V_113 = V_45 -> V_48 - V_45 -> V_50 ;
if ( V_34 ) {
V_115 = V_45 -> V_108 ;
V_115 -= F_30 ( V_12 , V_34 ) ;
V_44 = V_113 ;
switch ( V_114 ) {
case 2 :
F_58 = F_36 ;
break;
case 4 :
F_58 = F_38 ;
break;
default:
return - V_118 ;
}
} else {
V_115 = V_113 ;
V_44 = F_30 ( V_12 , V_34 ) ;
switch ( V_114 ) {
case 2 :
F_58 = F_37 ;
break;
case 4 :
F_58 = F_39 ;
break;
default:
return - V_118 ;
}
}
V_44 = F_59 ( V_44 , V_115 ) ;
F_58 ( V_12 , V_44 ) ;
V_45 -> V_50 += V_44 ;
if ( V_116 )
F_60 ( V_17 ) ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 )
{
return F_57 ( V_12 , V_69 ) ;
}
static int F_62 ( struct V_11 * V_12 )
{
return F_57 ( V_12 , V_32 ) ;
}
static T_6 F_63 ( int V_120 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_73 = F_44 ( V_6 ) ;
F_53 ( V_6 , V_121 , V_122 , 0 ) ;
F_53 ( V_6 , V_121 , V_122 , V_122 ) ;
if ( V_73 & F_41 ( 1 , V_38 ) )
F_62 ( & V_6 -> V_24 ) ;
if ( V_73 & F_41 ( 1 , V_40 ) )
F_62 ( & V_6 -> V_25 ) ;
if ( V_73 & F_41 ( 1 , V_39 ) )
F_61 ( & V_6 -> V_24 ) ;
if ( V_73 & F_41 ( 1 , V_41 ) )
F_61 ( & V_6 -> V_25 ) ;
F_32 ( & V_6 -> V_24 ) ;
F_32 ( & V_6 -> V_25 ) ;
F_46 ( & V_6 -> V_24 ) ;
F_46 ( & V_6 -> V_25 ) ;
return V_123 ;
}
static int F_64 ( struct V_11 * V_12 ,
int V_34 ,
struct V_82 * V_56 )
{
T_1 V_8 = F_19 ( V_12 ) ;
T_1 V_2 = 0 ;
F_65 ( V_56 ) ;
if ( F_11 ( V_12 ) )
V_2 = V_124 | V_125 ;
F_50 ( V_12 , V_98 , ( V_124 | V_125 ) , V_2 ) ;
V_2 = 0 ;
if ( V_126 & V_8 )
V_2 |= 1 << 12 ;
if ( V_127 & V_8 )
V_2 |= 1 << 8 ;
if ( V_128 & V_8 )
V_2 |= 1 << 4 ;
if ( V_129 & V_8 )
V_2 |= 1 << 0 ;
F_33 ( V_12 , V_130 , V_2 ) ;
F_33 ( V_12 , V_131 , V_12 -> V_132 ) ;
F_33 ( V_12 , V_133 , V_12 -> V_134 ) ;
if ( F_13 ( V_12 ) ) {
F_47 ( V_12 , 1 ) ;
F_50 ( V_12 , V_135 , V_136 , V_136 ) ;
}
F_43 ( V_12 , V_34 ) ;
F_46 ( V_12 ) ;
F_54 ( V_12 , V_34 , V_56 ) ;
return 0 ;
}
static void F_66 ( struct V_11 * V_12 ,
int V_34 ,
struct V_82 * V_56 )
{
if ( F_11 ( V_12 ) )
F_49 ( V_56 , V_12 , V_12 -> V_83 , 0 ) ;
F_67 ( V_56 ) ;
}
static int F_68 ( struct V_16 * V_17 ,
struct V_15 * V_22 )
{
struct V_11 * V_12 = F_17 ( V_17 ) ;
int V_34 = F_21 ( V_17 ) ;
return F_64 ( V_12 , V_34 , V_22 -> V_56 ) ;
}
static void F_69 ( struct V_16 * V_17 ,
struct V_15 * V_22 )
{
struct V_11 * V_12 = F_17 ( V_17 ) ;
int V_34 = F_21 ( V_17 ) ;
F_66 ( V_12 , V_34 , V_22 -> V_56 ) ;
V_12 -> V_83 = 0 ;
}
static int F_70 ( struct V_16 * V_17 , int V_137 ,
struct V_15 * V_22 )
{
struct V_11 * V_12 = F_17 ( V_17 ) ;
int V_34 = F_21 ( V_17 ) ;
int V_7 = 0 ;
switch ( V_137 ) {
case V_138 :
F_27 ( V_12 , V_34 , V_17 ) ;
V_7 = V_34 ? F_62 ( V_12 ) : F_61 ( V_12 ) ;
F_71 ( V_12 , V_34 ) ;
break;
case V_139 :
F_72 ( V_12 , V_34 ) ;
F_28 ( V_12 , V_34 ) ;
break;
}
return V_7 ;
}
static int F_73 ( struct V_11 * V_12 , unsigned int V_140 )
{
T_1 V_2 = 0 ;
switch ( V_140 & V_141 ) {
case V_142 :
V_2 = V_143 ;
V_12 -> V_43 = 2 ;
break;
case V_144 :
V_2 = V_145 ;
V_12 -> V_43 = 2 ;
break;
default:
return - V_118 ;
}
V_12 -> V_132 = V_2 ;
V_12 -> V_134 = V_2 ;
return 0 ;
}
static int F_74 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_1 V_2 = 0 ;
if ( V_6 -> V_75 -> V_76 < 2 )
return - V_118 ;
V_2 = V_146 | V_147 | V_145 ;
V_12 -> V_43 = 2 ;
V_12 -> V_14 = 1 ;
V_12 -> V_132 = V_2 ;
V_12 -> V_134 = V_2 ;
return 0 ;
}
static int F_75 ( struct V_15 * V_22 , unsigned int V_140 )
{
struct V_11 * V_12 = F_15 ( V_22 ) ;
struct V_5 * V_6 = F_10 ( V_12 ) ;
T_3 V_27 = F_18 ( V_6 ) ;
T_1 V_8 = F_19 ( V_12 ) ;
int V_7 ;
switch ( V_140 & V_148 ) {
case V_149 :
V_12 -> V_13 = 1 ;
break;
case V_150 :
break;
default:
return - V_118 ;
}
if ( F_11 ( V_12 ) && ! V_27 ) {
F_29 ( V_22 -> V_56 , L_7 ) ;
return - V_118 ;
}
switch ( V_8 & V_151 ) {
case V_152 :
V_7 = F_73 ( V_12 , V_140 & V_141 ) ;
break;
case V_153 :
V_7 = F_74 ( V_12 ) ;
break;
default:
V_7 = - V_118 ;
}
return V_7 ;
}
static int F_76 ( struct V_16 * V_17 ,
struct V_154 * V_155 ,
struct V_15 * V_22 )
{
struct V_11 * V_12 = F_17 ( V_17 ) ;
long V_83 = F_77 ( V_155 ) ;
int V_7 ;
if ( ! F_11 ( V_12 ) )
return 0 ;
V_7 = F_49 ( V_22 -> V_56 , V_12 , V_83 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_12 -> V_83 = V_83 ;
return V_7 ;
}
static int F_78 ( struct V_16 * V_17 )
{
struct V_46 * V_47 = V_17 -> V_47 ;
int V_7 = 0 ;
F_79 ( V_17 , & V_156 ) ;
V_7 = F_80 ( V_47 ,
V_157 ) ;
return V_7 ;
}
static int F_81 ( struct V_16 * V_17 ,
struct V_154 * V_158 )
{
return F_82 ( V_17 ,
F_83 ( V_158 ) ) ;
}
static int F_84 ( struct V_16 * V_17 )
{
return F_85 ( V_17 ) ;
}
static T_7 F_86 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = F_17 ( V_17 ) ;
struct V_33 * V_45 = F_22 ( V_12 , F_21 ( V_17 ) ) ;
int V_159 = V_45 -> V_50 - 1 ;
if ( V_159 < 0 )
V_159 = 0 ;
return F_25 ( V_12 , V_159 ) ;
}
static void F_87 ( struct V_160 * V_161 )
{
F_88 ( V_161 ) ;
}
static int F_89 ( struct V_18 * V_19 )
{
struct V_160 * V_161 = V_19 -> V_161 ;
return F_90 (
V_161 ,
V_162 ,
F_91 ( V_163 ) ,
V_164 , V_165 ) ;
}
static int F_92 ( struct V_166 * V_167 )
{
struct V_5 * V_6 ;
const struct V_168 * V_169 ;
struct V_170 * V_171 ;
unsigned int V_120 ;
int V_7 ;
V_169 = V_167 -> V_169 ;
if ( ! V_169 ) {
F_29 ( & V_167 -> V_56 , L_8 ) ;
return - V_172 ;
}
V_171 = F_93 ( V_167 , V_173 , 0 ) ;
V_120 = F_94 ( V_167 , 0 ) ;
if ( ! V_171 || ( int ) V_120 <= 0 ) {
F_29 ( & V_167 -> V_56 , L_9 ) ;
V_7 = - V_172 ;
goto exit;
}
V_6 = F_95 ( sizeof( * V_6 ) , V_163 ) ;
if ( ! V_6 ) {
F_29 ( & V_167 -> V_56 , L_10 ) ;
V_7 = - V_174 ;
goto exit;
}
V_6 -> V_10 = F_96 ( V_171 -> V_66 , F_97 ( V_171 ) ) ;
if ( ! V_6 -> V_10 ) {
V_7 = - V_175 ;
F_29 ( & V_167 -> V_56 , L_11 ) ;
goto V_176;
}
V_6 -> V_120 = V_120 ;
V_6 -> V_26 = V_167 -> V_56 . V_177 ;
V_6 -> V_75 = (struct V_178 * ) V_169 -> V_179 ;
F_98 ( & V_6 -> V_9 ) ;
V_6 -> V_24 . V_10 = V_6 -> V_10 ;
V_6 -> V_24 . V_6 = V_6 ;
V_6 -> V_25 . V_10 = V_6 -> V_10 + 0x40 ;
V_6 -> V_25 . V_6 = V_6 ;
F_99 ( & V_167 -> V_56 ) ;
F_100 ( & V_167 -> V_56 , V_6 ) ;
V_7 = F_101 ( V_120 , & F_63 , 0 ,
V_169 -> V_180 , V_6 ) ;
if ( V_7 ) {
F_29 ( & V_167 -> V_56 , L_12 ) ;
goto V_181;
}
V_7 = F_102 ( & V_167 -> V_56 , & V_182 ) ;
if ( V_7 < 0 ) {
F_29 ( & V_167 -> V_56 , L_13 ) ;
goto V_183;
}
V_7 = F_103 ( & V_167 -> V_56 , V_184 ,
F_104 ( V_184 ) ) ;
if ( V_7 < 0 ) {
F_29 ( & V_167 -> V_56 , L_14 ) ;
goto V_185;
}
return V_7 ;
V_185:
F_105 ( & V_167 -> V_56 ) ;
V_183:
F_106 ( V_120 , V_6 ) ;
V_181:
F_107 ( V_6 -> V_10 ) ;
F_108 ( & V_167 -> V_56 ) ;
V_176:
F_109 ( V_6 ) ;
V_6 = NULL ;
exit:
return V_7 ;
}
static int F_110 ( struct V_166 * V_167 )
{
struct V_5 * V_6 ;
V_6 = F_111 ( & V_167 -> V_56 ) ;
F_106 ( V_6 -> V_120 , V_6 ) ;
F_108 ( & V_167 -> V_56 ) ;
F_112 ( & V_167 -> V_56 , F_104 ( V_184 ) ) ;
F_105 ( & V_167 -> V_56 ) ;
F_107 ( V_6 -> V_10 ) ;
F_109 ( V_6 ) ;
return 0 ;
}
static void F_113 ( struct V_11 * V_12 ,
int V_34 ,
struct V_82 * V_56 )
{
if ( ! F_26 ( V_12 , V_34 ) )
return;
F_72 ( V_12 , V_34 ) ;
F_66 ( V_12 , V_34 , V_56 ) ;
}
static void F_114 ( struct V_11 * V_12 ,
int V_34 ,
struct V_82 * V_56 )
{
if ( ! F_26 ( V_12 , V_34 ) )
return;
F_64 ( V_12 , V_34 , V_56 ) ;
if ( F_11 ( V_12 ) && V_12 -> V_83 )
F_49 ( V_56 , V_12 , V_12 -> V_83 , 1 ) ;
F_71 ( V_12 , V_34 ) ;
}
static int F_115 ( struct V_82 * V_56 )
{
struct V_5 * V_6 = F_111 ( V_56 ) ;
struct V_11 * V_24 = & V_6 -> V_24 ;
struct V_11 * V_25 = & V_6 -> V_25 ;
F_113 ( V_24 , 1 , V_56 ) ;
F_113 ( V_24 , 0 , V_56 ) ;
F_113 ( V_25 , 1 , V_56 ) ;
F_113 ( V_25 , 0 , V_56 ) ;
return 0 ;
}
static int F_116 ( struct V_82 * V_56 )
{
struct V_5 * V_6 = F_111 ( V_56 ) ;
struct V_11 * V_24 = & V_6 -> V_24 ;
struct V_11 * V_25 = & V_6 -> V_25 ;
F_114 ( V_24 , 1 , V_56 ) ;
F_114 ( V_24 , 0 , V_56 ) ;
F_114 ( V_25 , 1 , V_56 ) ;
F_114 ( V_25 , 0 , V_56 ) ;
return 0 ;
}
static int F_117 ( struct V_82 * V_56 )
{
return 0 ;
}
static int T_8 F_118 ( void )
{
return F_119 ( & V_186 ) ;
}
static void T_9 F_120 ( void )
{
F_121 ( & V_186 ) ;
}
