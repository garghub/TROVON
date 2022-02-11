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
static int F_10 ( struct V_5 * V_6 )
{
return V_6 -> V_11 -> V_12 ;
}
static struct V_5 * F_11 ( struct V_13 * V_14 )
{
return V_14 -> V_6 ;
}
static int F_12 ( struct V_13 * V_14 )
{
return V_14 -> V_15 ;
}
static int F_13 ( struct V_13 * V_14 )
{
return V_14 -> V_6 -> V_10 == V_14 -> V_10 ;
}
static int F_14 ( struct V_13 * V_14 )
{
return V_14 -> V_16 ;
}
static int F_15 ( struct V_13 * V_14 )
{
return V_14 -> V_17 ;
}
static int F_16 ( struct V_18 * V_19 )
{
return V_19 -> V_20 == V_21 ;
}
static struct V_22 * F_17 ( struct V_18 * V_19 )
{
struct V_23 * V_24 = V_19 -> V_25 ;
return V_24 -> V_26 ;
}
static struct V_13 * F_18 ( struct V_22 * V_27 )
{
struct V_5 * V_6 = F_19 ( V_27 ) ;
if ( V_27 -> V_28 == 0 )
return & V_6 -> V_29 ;
else
return & V_6 -> V_30 ;
}
static struct V_13 * F_20 ( struct V_18 * V_19 )
{
return F_18 ( F_17 ( V_19 ) ) ;
}
static T_3 F_21 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_31 )
return NULL ;
return V_14 -> V_31 -> V_32 ;
}
static T_1 F_22 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_31 )
return 0 ;
return V_14 -> V_31 -> V_8 ;
}
static T_1 F_23 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_35 = F_24 ( V_14 , V_34 ) ;
int V_36 = F_13 ( V_14 ) ;
T_1 V_37 ;
if ( V_36 )
V_37 = V_35 ? V_38 : V_39 ;
else
V_37 = V_35 ? V_40 : V_41 ;
return V_37 ;
}
static int F_25 ( struct V_13 * V_14 , int V_42 )
{
return V_42 * V_14 -> V_43 ;
}
static int F_26 ( struct V_13 * V_14 , int V_44 )
{
return V_44 / V_14 -> V_43 ;
}
static int F_27 ( struct V_13 * V_14 ,
struct V_33 * V_34 )
{
int V_35 = F_24 ( V_14 , V_34 ) ;
T_1 V_45 ;
int V_42 ;
V_45 = V_35 ?
F_28 ( V_14 , V_46 ) :
F_28 ( V_14 , V_47 ) ;
V_42 = 0x1ff & ( V_45 >> 8 ) ;
return F_25 ( V_14 , V_42 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
T_1 V_48 = F_28 ( V_14 , V_46 ) ;
T_1 V_49 = F_28 ( V_14 , V_47 ) ;
if ( V_48 & V_50 )
V_14 -> V_51 . V_52 ++ ;
if ( V_48 & V_53 )
V_14 -> V_51 . V_54 ++ ;
if ( V_49 & V_50 )
V_14 -> V_55 . V_52 ++ ;
if ( V_49 & V_53 )
V_14 -> V_55 . V_54 ++ ;
F_30 ( V_14 , V_46 , 0 ) ;
F_30 ( V_14 , V_47 , 0 ) ;
}
static inline int F_24 ( struct V_13 * V_14 ,
struct V_33 * V_34 )
{
return & V_14 -> V_51 == V_34 ;
}
static inline struct V_33 * F_31 ( struct V_13 * V_14 ,
struct V_18 * V_19 )
{
return F_16 ( V_19 ) ? & V_14 -> V_51 : & V_14 -> V_55 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
int V_7 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = ! ! ( V_34 -> V_19 && V_34 -> V_19 -> V_56 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static struct V_13 * F_33 ( struct V_33 * V_34 )
{
return V_34 -> V_57 ;
}
static void F_34 ( struct V_13 * V_14 ,
struct V_33 * V_34 ,
struct V_18 * V_19 )
{
struct V_58 * V_56 = V_19 -> V_56 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_34 -> V_19 = V_19 ;
V_34 -> V_59 = F_25 ( V_14 , V_56 -> V_60 ) ;
V_34 -> V_61 = 0 ;
V_34 -> V_62 = F_25 ( V_14 , V_56 -> V_63 ) ;
V_34 -> V_64 = 0 ;
V_34 -> V_65 = F_35 ( V_56 , 1 ) ;
V_34 -> V_66 = 0 ;
V_34 -> V_52 = - 1 ;
V_34 -> V_54 = - 1 ;
F_36 ( V_34 , V_67 , V_14 , V_34 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_37 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
struct V_22 * V_27 = F_17 ( V_34 -> V_19 ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
if ( V_34 -> V_52 > 0 )
F_38 ( V_27 -> V_68 , L_1 , V_34 -> V_52 ) ;
if ( V_34 -> V_54 > 0 )
F_38 ( V_27 -> V_68 , L_2 , V_34 -> V_54 ) ;
F_36 ( V_34 , V_69 , V_14 , V_34 ) ;
V_34 -> V_19 = NULL ;
V_34 -> V_59 = 0 ;
V_34 -> V_61 = 0 ;
V_34 -> V_62 = 0 ;
V_34 -> V_64 = 0 ;
V_34 -> V_65 = 0 ;
V_34 -> V_66 = 0 ;
V_34 -> V_52 = 0 ;
V_34 -> V_54 = 0 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static int F_39 ( struct V_33 * V_34 )
{
struct V_13 * V_14 = F_33 ( V_34 ) ;
if ( ! V_14 )
return - V_70 ;
return F_36 ( V_34 , V_71 , V_14 , V_34 ) ;
}
static int F_40 ( struct V_13 * V_14 , struct V_72 * V_68 )
{
struct V_33 * V_34 ;
int V_73 , V_74 ;
V_34 = & V_14 -> V_51 ;
V_73 = F_36 ( V_34 , V_75 , V_14 , V_34 , V_68 ) ;
V_34 = & V_14 -> V_55 ;
V_74 = F_36 ( V_34 , V_75 , V_14 , V_34 , V_68 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_74 < 0 )
return V_74 ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 )
{
struct V_33 * V_34 ;
int V_73 , V_74 ;
V_34 = & V_14 -> V_51 ;
V_73 = F_36 ( V_34 , remove , V_14 , V_34 ) ;
V_34 = & V_14 -> V_55 ;
V_74 = F_36 ( V_34 , remove , V_14 , V_34 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_74 < 0 )
return V_74 ;
return 0 ;
}
static void F_42 ( struct V_13 * V_14 , struct V_33 * V_34 ,
T_1 V_76 , struct V_72 * V_68 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_35 = F_24 ( V_14 , V_34 ) ;
T_1 V_77 = V_14 -> V_77 ;
if ( F_10 ( V_6 ) >= 2 ) {
T_1 V_78 = 0 ;
switch ( V_76 ) {
case V_79 :
V_77 |= V_80 ;
V_78 |= V_81 ;
F_43 ( V_68 , L_3 ) ;
break;
case V_82 :
V_77 |= V_83 ;
V_78 |= V_84 ;
F_43 ( V_68 , L_4 ) ;
break;
case V_85 :
default:
V_77 |= V_80 ;
V_78 |= V_86 ;
F_43 ( V_68 , L_5 ) ;
break;
}
if ( V_35 )
F_30 ( V_14 , V_87 , V_78 ) ;
else
F_30 ( V_14 , V_88 , V_78 ) ;
}
if ( V_35 )
F_30 ( V_14 , V_89 , V_77 ) ;
else
F_30 ( V_14 , V_90 , V_77 ) ;
}
static void F_44 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
T_1 V_2 = F_45 ( 1 , F_23 ( V_14 , V_34 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_46 ( V_6 , V_91 , V_2 , V_2 ) ;
F_46 ( V_6 , V_92 , V_2 , V_2 ) ;
}
static void F_47 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
T_1 V_2 = F_45 ( 1 , F_23 ( V_14 , V_34 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_46 ( V_6 , V_91 , V_2 , 0 ) ;
F_46 ( V_6 , V_92 , V_2 , 0 ) ;
}
static T_1 F_48 ( struct V_5 * V_6 )
{
return F_49 ( V_6 , V_93 ) ;
}
static void F_50 ( struct V_13 * V_14 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
V_2 |= F_45 ( 1 , F_23 ( V_14 , & V_14 -> V_51 ) ) ;
V_2 |= F_45 ( 1 , F_23 ( V_14 , & V_14 -> V_55 ) ) ;
F_46 ( V_6 , V_93 , V_2 , 0 ) ;
}
static void F_51 ( struct V_13 * V_14 , int V_94 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_3 , V_4 ;
V_3 = V_95 | V_96 ;
V_4 = V_94 ? V_3 : 0 ;
F_13 ( V_14 ) ?
F_46 ( V_6 , V_97 , V_3 , V_4 ) :
F_46 ( V_6 , V_98 , V_3 , V_4 ) ;
}
static int F_52 ( struct V_72 * V_68 ,
struct V_13 * V_14 ,
int V_99 ,
int V_100 ,
int div ,
int (* V_32)( struct V_72 * V_68 ,
struct V_13 * V_14 ,
unsigned long V_101 ) )
{
struct V_102 * clock = & V_14 -> clock ;
int V_36 = F_13 ( V_14 ) ;
clock -> V_99 = NULL ;
clock -> V_100 = NULL ;
clock -> div = NULL ;
clock -> V_101 = 0 ;
clock -> V_103 = 0 ;
clock -> V_32 = V_32 ;
clock -> V_104 = F_53 ( V_68 , NULL ) ;
if ( F_54 ( clock -> V_104 ) )
return - V_105 ;
if ( V_99 ) {
clock -> V_99 = F_53 ( V_68 , V_36 ? L_6 : L_7 ) ;
if ( F_54 ( clock -> V_99 ) ) {
F_38 ( V_68 , L_8 ) ;
return - V_105 ;
}
if ( clock -> V_99 == clock -> V_104 ) {
F_38 ( V_68 , L_9 ) ;
return - V_105 ;
}
}
if ( V_100 ) {
clock -> V_100 = F_53 ( V_68 , V_36 ? L_10 : L_11 ) ;
if ( F_54 ( clock -> V_100 ) ) {
F_38 ( V_68 , L_12 ) ;
return - V_105 ;
}
if ( clock -> V_100 == clock -> V_104 ) {
F_38 ( V_68 , L_13 ) ;
return - V_105 ;
}
}
if ( div ) {
clock -> div = F_53 ( V_68 , V_36 ? L_14 : L_15 ) ;
if ( F_54 ( clock -> div ) ) {
F_38 ( V_68 , L_16 ) ;
return - V_105 ;
}
if ( clock -> div == clock -> V_104 ) {
F_38 ( V_68 , L_17 ) ;
return - V_105 ;
}
}
return 0 ;
}
static void F_55 ( struct V_13 * V_14 , unsigned long V_101 )
{
V_14 -> clock . V_101 = V_101 ;
}
static int F_56 ( struct V_13 * V_14 )
{
return V_14 -> clock . V_32 &&
V_14 -> clock . V_101 ;
}
static int F_57 ( struct V_72 * V_68 ,
struct V_13 * V_14 ,
unsigned long V_101 )
{
struct V_102 * clock = & V_14 -> clock ;
int V_7 = - V_105 ;
if ( ! F_56 ( V_14 ) )
return V_7 ;
if ( 0 == clock -> V_103 ) {
V_7 = clock -> V_32 ( V_68 , V_14 , V_101 ) ;
if ( V_7 < 0 ) {
F_58 ( V_14 ) ;
return V_7 ;
}
if ( clock -> V_99 )
F_59 ( clock -> V_99 ) ;
if ( clock -> V_100 )
F_59 ( clock -> V_100 ) ;
if ( clock -> div )
F_59 ( clock -> div ) ;
clock -> V_103 ++ ;
}
return V_7 ;
}
static int F_60 ( struct V_72 * V_68 ,
struct V_13 * V_14 )
{
struct V_102 * clock = & V_14 -> clock ;
if ( ! F_56 ( V_14 ) )
return - V_105 ;
if ( 1 == clock -> V_103 -- ) {
if ( clock -> V_99 )
F_61 ( clock -> V_99 ) ;
if ( clock -> V_100 )
F_61 ( clock -> V_100 ) ;
if ( clock -> div )
F_61 ( clock -> div ) ;
}
return 0 ;
}
static int F_62 ( struct V_72 * V_68 ,
struct V_13 * V_14 ,
int V_106 , int V_107 )
{
T_1 V_2 = 0 ;
if ( V_107 > V_106 ) {
F_38 ( V_68 , L_18 , V_106 , V_107 ) ;
return - V_105 ;
}
switch ( V_106 ) {
case 512 :
V_2 |= ( 0x0 << 12 ) ;
break;
case 256 :
V_2 |= ( 0x1 << 12 ) ;
break;
case 128 :
V_2 |= ( 0x2 << 12 ) ;
break;
case 64 :
V_2 |= ( 0x3 << 12 ) ;
break;
case 32 :
V_2 |= ( 0x4 << 12 ) ;
break;
default:
F_38 ( V_68 , L_19 , V_106 ) ;
return - V_105 ;
}
switch ( V_107 ) {
case 32 :
V_2 |= ( 0x0 << 8 ) ;
break;
case 64 :
V_2 |= ( 0x1 << 8 ) ;
break;
case 128 :
V_2 |= ( 0x2 << 8 ) ;
break;
case 256 :
V_2 |= ( 0x3 << 8 ) ;
break;
case 512 :
V_2 |= ( 0x4 << 8 ) ;
break;
case 16 :
V_2 |= ( 0x7 << 8 ) ;
break;
default:
F_38 ( V_68 , L_20 , V_107 ) ;
return - V_105 ;
}
F_43 ( V_68 , L_21 , V_106 , V_107 ) ;
F_63 ( V_14 , V_108 , ( V_109 | V_110 ) , V_2 ) ;
F_64 ( 10 ) ;
return 0 ;
}
static int F_65 ( struct V_72 * V_68 ,
struct V_13 * V_14 ,
unsigned long V_101 )
{
struct V_111 * V_99 = V_14 -> clock . V_99 ;
struct V_111 * V_100 = V_14 -> clock . V_100 ;
unsigned long V_112 ;
int V_106 , V_107 ;
int V_7 = 0 ;
V_112 = F_66 ( V_99 ) ;
if ( V_112 % V_101 ) {
F_38 ( V_68 , L_22 ) ;
return - V_105 ;
}
F_67 ( V_100 , V_99 ) ;
F_68 ( V_100 , V_112 ) ;
V_107 = V_14 -> V_43 * 32 ;
V_106 = V_112 / V_101 ;
F_43 ( V_68 , L_23 , V_112 , V_101 ) ;
V_7 = F_62 ( V_68 , V_14 , V_106 , V_107 ) ;
if ( V_7 < 0 )
F_38 ( V_68 , L_24 , V_113 ) ;
return V_7 ;
}
static int F_69 ( struct V_72 * V_68 ,
struct V_13 * V_14 ,
unsigned long V_101 )
{
struct V_111 * V_100 = V_14 -> clock . V_100 ;
struct V_111 * div = V_14 -> clock . div ;
unsigned long V_114 = 0 ;
unsigned long V_115 , V_116 ;
unsigned long V_117 , V_118 ;
unsigned long V_119 , V_120 ;
int V_121 ;
int V_106 , V_107 ;
int V_7 = - V_105 ;
if ( ! ( 12288000 % V_101 ) )
V_114 = 12288000 ;
if ( ! ( 11289600 % V_101 ) )
V_114 = 11289600 ;
if ( ! V_114 ) {
F_38 ( V_68 , L_25 ) ;
return V_7 ;
}
V_107 = V_14 -> V_43 * 32 ;
V_106 = V_114 / V_101 ;
V_7 = F_62 ( V_68 , V_14 , V_106 , V_107 ) ;
if ( V_7 < 0 ) {
F_38 ( V_68 , L_24 , V_113 ) ;
return V_7 ;
}
V_118 = ~ 0 ;
V_119 = 0 ;
V_120 = 0 ;
for ( V_121 = 1 ; V_121 < 0xffff ; V_121 ++ ) {
V_116 = V_114 * V_121 ;
if ( V_116 > 100000000 )
break;
V_116 = F_70 ( V_100 , V_116 ) ;
V_115 = V_116 / V_121 ;
V_117 = abs ( V_115 - V_114 ) ;
if ( V_117 < V_118 ) {
V_118 = V_117 ;
V_119 = V_116 ;
V_120 = V_115 ;
}
}
V_7 = F_68 ( V_100 , V_119 ) ;
if ( V_7 < 0 ) {
F_38 ( V_68 , L_26 ) ;
return - V_70 ;
}
V_7 = F_68 ( div , F_70 ( div , V_120 ) ) ;
if ( V_7 < 0 ) {
F_38 ( V_68 , L_27 ) ;
return - V_70 ;
}
F_43 ( V_68 , L_28 ,
F_66 ( V_100 ) , F_66 ( div ) ) ;
return V_7 ;
}
static int F_71 ( struct V_72 * V_68 , struct V_13 * V_14 ,
long V_101 , int V_94 )
{
T_3 V_32 = F_21 ( V_14 ) ;
int V_7 ;
if ( ! V_32 ) {
if ( V_94 )
return F_57 ( V_68 , V_14 , V_101 ) ;
else
return F_60 ( V_68 , V_14 ) ;
}
V_7 = V_32 ( V_68 , V_101 , V_94 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_94 )
return 0 ;
if ( V_7 > 0 ) {
T_1 V_2 = 0 ;
switch ( V_7 & V_122 ) {
default:
case V_123 :
V_2 |= ( 0x0 << 12 ) ;
break;
case V_124 :
V_2 |= ( 0x1 << 12 ) ;
break;
case V_125 :
V_2 |= ( 0x2 << 12 ) ;
break;
case V_126 :
V_2 |= ( 0x3 << 12 ) ;
break;
case V_127 :
V_2 |= ( 0x4 << 12 ) ;
break;
}
switch ( V_7 & V_128 ) {
default:
case V_129 :
V_2 |= ( 0x0 << 8 ) ;
break;
case V_130 :
V_2 |= ( 0x1 << 8 ) ;
break;
case V_131 :
V_2 |= ( 0x2 << 8 ) ;
break;
case V_132 :
V_2 |= ( 0x3 << 8 ) ;
break;
case V_133 :
V_2 |= ( 0x4 << 8 ) ;
break;
case V_134 :
V_2 |= ( 0x7 << 8 ) ;
break;
}
F_63 ( V_14 , V_108 , ( V_109 | V_110 ) , V_2 ) ;
F_64 ( 10 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static void F_72 ( struct V_13 * V_14 , T_4 * V_135 , int V_44 )
{
int V_136 ;
if ( F_15 ( V_14 ) ) {
T_1 * V_137 = ( T_1 * ) V_135 ;
for ( V_136 = 0 ; V_136 < V_44 / 2 ; V_136 ++ )
F_30 ( V_14 , V_138 , V_137 [ V_136 ] ) ;
} else {
T_5 * V_137 = ( T_5 * ) V_135 ;
for ( V_136 = 0 ; V_136 < V_44 ; V_136 ++ )
F_30 ( V_14 , V_138 , ( ( T_1 ) * ( V_137 + V_136 ) << 8 ) ) ;
}
}
static void F_73 ( struct V_13 * V_14 , T_4 * V_135 , int V_44 )
{
T_5 * V_137 = ( T_5 * ) V_135 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_44 ; V_136 ++ )
* ( V_137 + V_136 ) = ( T_5 ) ( F_28 ( V_14 , V_139 ) >> 8 ) ;
}
static void F_74 ( struct V_13 * V_14 , T_4 * V_135 , int V_44 )
{
T_1 * V_137 = ( T_1 * ) V_135 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_44 ; V_136 ++ )
F_30 ( V_14 , V_138 , * ( V_137 + V_136 ) ) ;
}
static void F_75 ( struct V_13 * V_14 , T_4 * V_135 , int V_44 )
{
T_1 * V_137 = ( T_1 * ) V_135 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_44 ; V_136 ++ )
* ( V_137 + V_136 ) = F_28 ( V_14 , V_139 ) ;
}
static T_4 * F_76 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
struct V_58 * V_56 = V_34 -> V_19 -> V_56 ;
return V_56 -> V_140 +
F_35 ( V_56 , V_34 -> V_61 ) ;
}
static int F_77 ( struct V_13 * V_14 , struct V_33 * V_34 ,
void (* F_78)( struct V_13 * V_14 , T_4 * V_137 , int V_44 ) ,
void (* F_79)( struct V_13 * V_14 , T_4 * V_137 , int V_44 ) ,
int V_44 )
{
struct V_58 * V_56 ;
struct V_18 * V_19 ;
T_4 * V_137 ;
int V_141 ;
if ( ! F_32 ( V_14 , V_34 ) )
return - V_105 ;
V_141 = 0 ;
V_19 = V_34 -> V_19 ;
V_56 = V_19 -> V_56 ;
if ( V_34 -> V_61 >=
V_34 -> V_62 * ( V_34 -> V_64 + 1 ) ) {
V_141 = 1 ;
V_34 -> V_64 = ( V_34 -> V_64 + 1 ) % V_56 -> V_142 ;
if ( 0 == V_34 -> V_64 )
V_34 -> V_61 = 0 ;
}
V_137 = F_76 ( V_14 , V_34 ) ;
switch ( V_34 -> V_65 ) {
case 2 :
F_78 ( V_14 , V_137 , V_44 ) ;
break;
case 4 :
F_79 ( V_14 , V_137 , V_44 ) ;
break;
default:
return - V_105 ;
}
V_34 -> V_61 += V_44 ;
if ( V_141 )
F_80 ( V_19 ) ;
return 0 ;
}
static int F_81 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_143 ;
int V_144 ;
int V_44 ;
V_143 = F_27 ( V_14 , V_34 ) ;
V_144 = V_34 -> V_59 - V_34 -> V_61 ;
V_44 = V_118 ( V_143 , V_144 ) ;
return F_77 ( V_14 , V_34 ,
F_73 ,
F_75 ,
V_44 ) ;
}
static int F_82 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
int V_143 ;
int V_144 ;
int V_44 ;
V_143 = V_34 -> V_59 - V_34 -> V_61 ;
V_144 = V_34 -> V_145 -
F_27 ( V_14 , V_34 ) ;
V_44 = V_118 ( V_143 , V_144 ) ;
return F_77 ( V_14 , V_34 ,
F_72 ,
F_74 ,
V_44 ) ;
}
static void F_83 ( struct V_13 * V_14 , struct V_33 * V_34 ,
int V_94 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_111 = F_13 ( V_14 ) ? V_146 : V_147 ;
if ( V_94 )
F_44 ( V_14 , V_34 ) ;
else
F_47 ( V_14 , V_34 ) ;
if ( F_12 ( V_14 ) )
F_84 ( V_6 , V_148 , V_111 , ( V_94 ) ? V_111 : 0 ) ;
}
static int F_85 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
if ( F_15 ( V_14 ) )
V_34 -> V_66 = F_86 ( 24 , V_85 ) |
F_86 ( 16 , V_82 ) ;
else
V_34 -> V_66 = F_86 ( 24 , V_85 ) |
F_86 ( 16 , V_85 ) ;
return 0 ;
}
static int F_87 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
V_34 -> V_66 = F_86 ( 24 , V_85 ) |
F_86 ( 16 , V_85 ) ;
return 0 ;
}
static T_6 F_88 ( int V_149 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_93 = F_48 ( V_6 ) ;
F_84 ( V_6 , V_150 , V_151 , 0 ) ;
F_84 ( V_6 , V_150 , V_151 , V_151 ) ;
if ( V_93 & F_45 ( 1 , V_38 ) )
F_39 ( & V_6 -> V_29 . V_51 ) ;
if ( V_93 & F_45 ( 1 , V_40 ) )
F_39 ( & V_6 -> V_30 . V_51 ) ;
if ( V_93 & F_45 ( 1 , V_39 ) )
F_39 ( & V_6 -> V_29 . V_55 ) ;
if ( V_93 & F_45 ( 1 , V_41 ) )
F_39 ( & V_6 -> V_30 . V_55 ) ;
F_29 ( & V_6 -> V_29 ) ;
F_29 ( & V_6 -> V_30 ) ;
F_50 ( & V_6 -> V_29 ) ;
F_50 ( & V_6 -> V_30 ) ;
return V_152 ;
}
static int F_89 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
struct V_58 * V_56 = V_34 -> V_19 -> V_56 ;
struct V_22 * V_27 = F_17 ( V_34 -> V_19 ) ;
enum V_153 V_154 = F_24 ( V_14 , V_34 ) ?
V_155 : V_156 ;
V_34 -> V_66 = F_86 ( 24 , V_85 ) |
F_86 ( 16 , V_82 ) ;
V_34 -> V_78 = F_90 ( V_27 -> V_68 , V_56 -> V_140 ,
F_91 ( V_34 -> V_19 ) , V_154 ) ;
return 0 ;
}
static int F_92 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
struct V_22 * V_27 = F_17 ( V_34 -> V_19 ) ;
enum V_153 V_154 = F_24 ( V_14 , V_34 ) ?
V_155 : V_156 ;
F_93 ( V_27 -> V_68 , V_34 -> V_78 ,
F_91 ( V_34 -> V_19 ) , V_154 ) ;
return 0 ;
}
static T_7 F_94 ( struct V_33 * V_34 )
{
struct V_58 * V_56 = V_34 -> V_19 -> V_56 ;
return V_34 -> V_78 + F_35 ( V_56 , V_34 -> V_61 ) ;
}
static void F_95 ( void * V_2 )
{
struct V_33 * V_34 = (struct V_33 * ) V_2 ;
struct V_13 * V_14 = F_33 ( V_34 ) ;
struct V_58 * V_56 = V_34 -> V_19 -> V_56 ;
struct V_22 * V_27 = F_17 ( V_34 -> V_19 ) ;
enum V_153 V_154 = F_24 ( V_14 , V_34 ) ?
V_155 : V_156 ;
F_96 ( V_27 -> V_68 , F_94 ( V_34 ) ,
F_35 ( V_56 , V_34 -> V_62 ) , V_154 ) ;
V_34 -> V_61 += V_34 -> V_62 ;
V_34 -> V_64 ++ ;
if ( V_34 -> V_64 >= V_56 -> V_142 ) {
V_34 -> V_64 = 0 ;
V_34 -> V_61 = 0 ;
}
F_29 ( V_14 ) ;
F_39 ( V_34 ) ;
F_80 ( V_34 -> V_19 ) ;
}
static void F_97 ( struct V_157 * V_158 )
{
struct V_33 * V_34 = F_98 ( V_158 , struct V_33 , V_158 ) ;
struct V_13 * V_14 = F_33 ( V_34 ) ;
struct V_22 * V_27 ;
struct V_159 * V_160 ;
struct V_58 * V_56 ;
enum V_153 V_154 ;
int V_35 = F_24 ( V_14 , V_34 ) ;
int V_161 ;
T_7 V_137 ;
if ( ! F_32 ( V_14 , V_34 ) )
return;
V_27 = F_17 ( V_34 -> V_19 ) ;
V_56 = V_34 -> V_19 -> V_56 ;
V_154 = V_35 ? V_155 : V_156 ;
V_161 = F_35 ( V_56 , V_34 -> V_62 ) ;
V_137 = F_94 ( V_34 ) ;
F_99 ( V_27 -> V_68 , V_137 , V_161 , V_154 ) ;
V_160 = F_100 ( V_34 -> V_162 , V_137 , V_161 , V_154 ,
V_163 | V_164 ) ;
if ( ! V_160 ) {
F_38 ( V_27 -> V_68 , L_29 ) ;
return;
}
V_160 -> V_165 = F_95 ;
V_160 -> V_166 = V_34 ;
if ( F_101 ( V_160 ) < 0 ) {
F_38 ( V_27 -> V_68 , L_30 ) ;
return;
}
F_102 ( V_34 -> V_162 ) ;
if ( ! V_35 ) {
if ( V_50 & F_28 ( V_14 , V_47 ) ) {
F_63 ( V_14 , V_167 , V_168 , V_168 ) ;
F_30 ( V_14 , V_47 , 0 ) ;
}
}
}
static bool F_103 ( struct V_169 * V_162 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
V_162 -> V_173 = V_172 ;
return true ;
}
static int F_104 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
F_105 ( & V_34 -> V_158 ) ;
return 0 ;
}
static void F_106 ( struct V_13 * V_14 , struct V_33 * V_34 ,
int V_174 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_111 = F_13 ( V_14 ) ? V_146 : V_147 ;
T_1 V_94 = V_174 ? V_175 : 0 ;
F_63 ( V_14 , V_87 , V_175 , V_94 ) ;
F_107 ( V_34 -> V_162 ) ;
if ( F_12 ( V_14 ) )
F_84 ( V_6 , V_148 , V_111 , ( V_94 ) ? V_111 : 0 ) ;
}
static int F_108 ( struct V_13 * V_14 , struct V_33 * V_34 , struct V_72 * V_68 )
{
T_8 V_3 ;
F_109 ( V_3 ) ;
F_110 ( V_176 , V_3 ) ;
V_34 -> V_162 = F_111 ( V_3 , F_103 , & V_34 -> V_172 ) ;
if ( ! V_34 -> V_162 ) {
if ( F_24 ( V_14 , V_34 ) )
V_14 -> V_51 . V_177 = & V_178 ;
else
V_14 -> V_55 . V_177 = & V_179 ;
F_112 ( V_68 , L_31 ) ;
return F_40 ( V_14 , V_68 ) ;
}
F_113 ( & V_34 -> V_158 , F_97 ) ;
return 0 ;
}
static int F_114 ( struct V_13 * V_14 , struct V_33 * V_34 )
{
F_115 ( & V_34 -> V_158 ) ;
F_116 ( V_14 , V_34 ) ;
if ( V_34 -> V_162 )
F_117 ( V_34 -> V_162 ) ;
V_34 -> V_162 = NULL ;
return 0 ;
}
static void F_118 ( struct V_13 * V_14 ,
struct V_33 * V_34 ,
struct V_72 * V_68 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_35 = F_24 ( V_14 , V_34 ) ;
T_1 V_37 , V_136 ;
int V_180 ;
V_37 = F_119 ( V_6 , V_181 ) ;
V_37 >>= F_23 ( V_14 , V_34 ) ;
V_37 &= V_182 ;
V_180 = 256 << V_37 ;
F_43 ( V_68 , L_32 , V_180 ) ;
for ( V_136 = 1 ; V_136 < V_14 -> V_43 ; V_136 <<= 1 )
V_180 >>= 1 ;
F_43 ( V_68 , L_33 ,
V_14 -> V_43 , V_180 ) ;
V_34 -> V_145 = F_25 ( V_14 , V_180 ) ;
if ( V_35 ) {
F_30 ( V_14 , V_183 , V_184 ) ;
F_63 ( V_14 , V_183 , V_168 , V_168 ) ;
} else {
F_30 ( V_14 , V_167 , V_184 ) ;
F_63 ( V_14 , V_167 , V_168 , V_168 ) ;
}
}
static int F_120 ( struct V_13 * V_14 ,
struct V_33 * V_34 ,
struct V_72 * V_68 )
{
T_1 V_8 = F_22 ( V_14 ) ;
T_1 V_2 = 0 ;
if ( F_12 ( V_14 ) )
V_2 = V_185 | V_186 ;
F_63 ( V_14 , V_108 , ( V_185 | V_186 ) , V_2 ) ;
V_2 = 0 ;
if ( V_14 -> V_187 )
V_2 |= ( 1 << 0 ) ;
if ( V_14 -> V_188 )
V_2 |= ( 1 << 4 ) ;
if ( F_12 ( V_14 ) )
V_2 <<= 8 ;
if ( V_189 & V_8 )
V_2 |= 1 << 12 ;
if ( V_190 & V_8 )
V_2 |= 1 << 8 ;
if ( V_191 & V_8 )
V_2 |= 1 << 4 ;
if ( V_192 & V_8 )
V_2 |= 1 << 0 ;
F_30 ( V_14 , V_193 , V_2 ) ;
if ( F_14 ( V_14 ) ) {
F_51 ( V_14 , 1 ) ;
F_63 ( V_14 , V_194 , V_195 , V_195 ) ;
}
V_2 = 0 ;
switch ( V_34 -> V_65 ) {
case 2 :
V_2 = F_121 ( 16 , V_34 -> V_66 ) ;
break;
case 4 :
V_2 = F_121 ( 24 , V_34 -> V_66 ) ;
break;
}
F_42 ( V_14 , V_34 , V_2 , V_68 ) ;
F_47 ( V_14 , V_34 ) ;
F_50 ( V_14 ) ;
F_118 ( V_14 , V_34 , V_68 ) ;
if ( F_12 ( V_14 ) )
return F_71 ( V_68 , V_14 , V_14 -> V_101 , 1 ) ;
return 0 ;
}
static int F_122 ( struct V_13 * V_14 ,
struct V_72 * V_68 )
{
if ( F_12 ( V_14 ) )
return F_71 ( V_68 , V_14 , V_14 -> V_101 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_18 * V_19 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
F_58 ( V_14 ) ;
V_14 -> V_101 = 0 ;
return 0 ;
}
static void F_124 ( struct V_18 * V_19 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
F_58 ( V_14 ) ;
V_14 -> V_101 = 0 ;
}
static int F_125 ( struct V_18 * V_19 , int V_196 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
struct V_33 * V_34 = F_31 ( V_14 , V_19 ) ;
int V_7 = 0 ;
switch ( V_196 ) {
case V_197 :
F_34 ( V_14 , V_34 , V_19 ) ;
if ( ! V_7 )
V_7 = F_120 ( V_14 , V_34 , V_27 -> V_68 ) ;
if ( ! V_7 )
V_7 = F_39 ( V_34 ) ;
if ( ! V_7 )
F_126 ( V_14 , V_34 ) ;
break;
case V_198 :
if ( ! V_7 )
V_7 = F_122 ( V_14 , V_27 -> V_68 ) ;
F_116 ( V_14 , V_34 ) ;
F_37 ( V_14 , V_34 ) ;
break;
}
return V_7 ;
}
static int F_127 ( struct V_13 * V_14 , unsigned int V_77 )
{
switch ( V_77 & V_199 ) {
case V_200 :
V_14 -> V_77 = V_201 ;
V_14 -> V_43 = 2 ;
break;
case V_202 :
V_14 -> V_77 = V_203 ;
V_14 -> V_43 = 2 ;
break;
default:
return - V_105 ;
}
return 0 ;
}
static int F_128 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
if ( F_10 ( V_6 ) < 2 )
return - V_105 ;
V_14 -> V_77 = V_204 | V_203 ;
V_14 -> V_43 = 2 ;
return 0 ;
}
static int F_129 ( struct V_22 * V_27 , unsigned int V_77 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
T_3 V_32 = F_21 ( V_14 ) ;
int V_7 ;
switch ( V_77 & V_205 ) {
case V_206 :
V_14 -> V_15 = 1 ;
break;
case V_207 :
break;
default:
return - V_105 ;
}
switch ( V_77 & V_208 ) {
case V_209 :
V_14 -> V_187 = 0 ;
V_14 -> V_188 = 1 ;
break;
case V_210 :
V_14 -> V_187 = 1 ;
V_14 -> V_188 = 0 ;
break;
case V_211 :
V_14 -> V_187 = 1 ;
V_14 -> V_188 = 1 ;
break;
case V_212 :
default:
V_14 -> V_187 = 0 ;
V_14 -> V_188 = 0 ;
break;
}
if ( F_12 ( V_14 ) ) {
if ( V_32 )
F_130 ( V_27 -> V_68 , L_34 ) ;
if ( V_14 -> V_213 )
F_52 ( V_27 -> V_68 , V_14 , 0 , 1 , 1 ,
F_69 ) ;
else
F_52 ( V_27 -> V_68 , V_14 , 1 , 1 , 0 ,
F_65 ) ;
}
if ( F_14 ( V_14 ) )
V_7 = F_128 ( V_14 ) ;
else
V_7 = F_127 ( V_14 , V_77 & V_199 ) ;
return V_7 ;
}
static int F_131 ( struct V_18 * V_19 ,
struct V_214 * V_215 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
if ( F_12 ( V_14 ) ) {
V_14 -> V_101 = F_132 ( V_215 ) ;
F_55 ( V_14 , V_14 -> V_101 ) ;
}
return 0 ;
}
static int F_133 ( struct V_18 * V_19 )
{
struct V_58 * V_56 = V_19 -> V_56 ;
int V_7 = 0 ;
F_134 ( V_19 , & V_216 ) ;
V_7 = F_135 ( V_56 ,
V_217 ) ;
return V_7 ;
}
static int F_136 ( struct V_18 * V_19 ,
struct V_214 * V_218 )
{
return F_137 ( V_19 ,
F_138 ( V_218 ) ) ;
}
static int F_139 ( struct V_18 * V_19 )
{
return F_140 ( V_19 ) ;
}
static T_9 F_141 ( struct V_18 * V_19 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
struct V_33 * V_34 = F_31 ( V_14 , V_19 ) ;
return F_26 ( V_14 , V_34 -> V_61 ) ;
}
static void F_142 ( struct V_219 * V_220 )
{
F_143 ( V_220 ) ;
}
static int F_144 ( struct V_23 * V_24 )
{
struct V_219 * V_220 = V_24 -> V_220 ;
return F_145 (
V_220 ,
V_221 ,
F_146 ( V_222 ) ,
V_223 , V_224 ) ;
}
static void F_147 ( struct V_13 * V_14 ,
struct V_225 * V_31 )
{
if ( V_31 -> V_8 & V_226 )
V_14 -> V_16 = 1 ;
if ( V_31 -> V_8 & V_227 )
V_14 -> V_213 = 1 ;
if ( V_31 -> V_8 & V_228 )
V_14 -> V_17 = 1 ;
}
static void F_148 ( struct V_13 * V_14 ,
struct V_225 * V_31 )
{
V_14 -> V_51 . V_177 = & V_178 ;
V_14 -> V_51 . V_57 = V_14 ;
V_14 -> V_55 . V_177 = & V_179 ;
V_14 -> V_55 . V_57 = V_14 ;
if ( V_31 -> V_229 ) {
V_14 -> V_51 . V_172 . V_230 . V_231 = V_31 -> V_229 ;
V_14 -> V_51 . V_177 = & V_232 ;
}
}
static int F_149 ( struct V_233 * V_234 )
{
struct V_5 * V_6 ;
const struct V_235 * V_236 ;
struct V_237 * V_31 = V_234 -> V_68 . V_238 ;
struct V_225 V_239 , * V_240 ;
struct V_13 * V_14 ;
struct V_241 * V_242 ;
unsigned int V_149 ;
int V_7 ;
V_239 . V_8 = 0 ;
V_239 . V_229 = 0 ;
V_239 . V_243 = 0 ;
V_236 = V_234 -> V_236 ;
if ( ! V_236 ) {
F_38 ( & V_234 -> V_68 , L_35 ) ;
return - V_244 ;
}
V_242 = F_150 ( V_234 , V_245 , 0 ) ;
V_149 = F_151 ( V_234 , 0 ) ;
if ( ! V_242 || ( int ) V_149 <= 0 ) {
F_38 ( & V_234 -> V_68 , L_36 ) ;
return - V_244 ;
}
V_6 = F_152 ( & V_234 -> V_68 , sizeof( * V_6 ) , V_222 ) ;
if ( ! V_6 ) {
F_38 ( & V_234 -> V_68 , L_37 ) ;
return - V_246 ;
}
V_6 -> V_10 = F_153 ( & V_234 -> V_68 ,
V_242 -> V_174 , F_154 ( V_242 ) ) ;
if ( ! V_6 -> V_10 ) {
F_38 ( & V_234 -> V_68 , L_38 ) ;
return - V_247 ;
}
V_6 -> V_149 = V_149 ;
V_6 -> V_11 = (struct V_248 * ) V_236 -> V_249 ;
F_155 ( & V_6 -> V_9 ) ;
V_240 = ( V_31 ) ? & V_31 -> V_250 : & V_239 ;
V_14 = & V_6 -> V_29 ;
V_14 -> V_10 = V_6 -> V_10 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_31 = V_240 ;
F_147 ( V_14 , V_240 ) ;
F_148 ( V_14 , V_240 ) ;
V_7 = F_40 ( V_14 , & V_234 -> V_68 ) ;
if ( V_7 < 0 ) {
F_38 ( & V_234 -> V_68 , L_39 ) ;
return V_7 ;
}
V_240 = ( V_31 ) ? & V_31 -> V_251 : & V_239 ;
V_14 = & V_6 -> V_30 ;
V_14 -> V_10 = V_6 -> V_10 + 0x40 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_31 = V_240 ;
F_147 ( V_14 , V_240 ) ;
F_148 ( V_14 , V_240 ) ;
V_7 = F_40 ( V_14 , & V_234 -> V_68 ) ;
if ( V_7 < 0 ) {
F_38 ( & V_234 -> V_68 , L_40 ) ;
goto V_252;
}
F_156 ( & V_234 -> V_68 ) ;
F_157 ( & V_234 -> V_68 , V_6 ) ;
V_7 = F_158 ( & V_234 -> V_68 , V_149 , & F_88 , 0 ,
V_236 -> V_253 , V_6 ) ;
if ( V_7 ) {
F_38 ( & V_234 -> V_68 , L_41 ) ;
goto V_254;
}
V_7 = F_159 ( & V_234 -> V_68 , & V_255 ) ;
if ( V_7 < 0 ) {
F_38 ( & V_234 -> V_68 , L_42 ) ;
goto V_254;
}
V_7 = F_160 ( & V_234 -> V_68 , V_256 ,
F_161 ( V_256 ) ) ;
if ( V_7 < 0 ) {
F_38 ( & V_234 -> V_68 , L_43 ) ;
goto V_257;
}
return V_7 ;
V_257:
F_162 ( & V_234 -> V_68 ) ;
V_254:
F_163 ( & V_234 -> V_68 ) ;
F_41 ( & V_6 -> V_30 ) ;
V_252:
F_41 ( & V_6 -> V_29 ) ;
return V_7 ;
}
static int F_164 ( struct V_233 * V_234 )
{
struct V_5 * V_6 ;
V_6 = F_165 ( & V_234 -> V_68 ) ;
F_163 ( & V_234 -> V_68 ) ;
F_166 ( & V_234 -> V_68 , F_161 ( V_256 ) ) ;
F_162 ( & V_234 -> V_68 ) ;
F_41 ( & V_6 -> V_29 ) ;
F_41 ( & V_6 -> V_30 ) ;
return 0 ;
}
static void F_167 ( struct V_13 * V_14 ,
struct V_33 * V_34 ,
struct V_72 * V_68 )
{
if ( ! F_32 ( V_14 , V_34 ) )
return;
F_116 ( V_14 , V_34 ) ;
F_122 ( V_14 , V_68 ) ;
}
static void F_168 ( struct V_13 * V_14 ,
struct V_33 * V_34 ,
struct V_72 * V_68 )
{
if ( ! F_32 ( V_14 , V_34 ) )
return;
F_120 ( V_14 , V_34 , V_68 ) ;
F_126 ( V_14 , V_34 ) ;
}
static int F_169 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = F_165 ( V_68 ) ;
struct V_13 * V_29 = & V_6 -> V_29 ;
struct V_13 * V_30 = & V_6 -> V_30 ;
F_167 ( V_29 , & V_29 -> V_51 , V_68 ) ;
F_167 ( V_29 , & V_29 -> V_55 , V_68 ) ;
F_167 ( V_30 , & V_30 -> V_51 , V_68 ) ;
F_167 ( V_30 , & V_30 -> V_55 , V_68 ) ;
return 0 ;
}
static int F_170 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = F_165 ( V_68 ) ;
struct V_13 * V_29 = & V_6 -> V_29 ;
struct V_13 * V_30 = & V_6 -> V_30 ;
F_168 ( V_29 , & V_29 -> V_51 , V_68 ) ;
F_168 ( V_29 , & V_29 -> V_55 , V_68 ) ;
F_168 ( V_30 , & V_30 -> V_51 , V_68 ) ;
F_168 ( V_30 , & V_30 -> V_55 , V_68 ) ;
return 0 ;
}
