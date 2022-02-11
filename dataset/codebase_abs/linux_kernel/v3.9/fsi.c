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
static T_1 F_21 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
int V_33 = F_22 ( V_14 , V_32 ) ;
int V_34 = F_13 ( V_14 ) ;
T_1 V_35 ;
if ( V_34 )
V_35 = V_33 ? V_36 : V_37 ;
else
V_35 = V_33 ? V_38 : V_39 ;
return V_35 ;
}
static int F_23 ( struct V_13 * V_14 , int V_40 )
{
return V_40 * V_14 -> V_41 ;
}
static int F_24 ( struct V_13 * V_14 , int V_42 )
{
return V_42 / V_14 -> V_41 ;
}
static int F_25 ( struct V_13 * V_14 ,
struct V_31 * V_32 )
{
int V_33 = F_22 ( V_14 , V_32 ) ;
T_1 V_43 ;
int V_40 ;
V_43 = V_33 ?
F_26 ( V_14 , V_44 ) :
F_26 ( V_14 , V_45 ) ;
V_40 = 0x1ff & ( V_43 >> 8 ) ;
return F_23 ( V_14 , V_40 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
T_1 V_46 = F_26 ( V_14 , V_44 ) ;
T_1 V_47 = F_26 ( V_14 , V_45 ) ;
if ( V_46 & V_48 )
V_14 -> V_49 . V_50 ++ ;
if ( V_46 & V_51 )
V_14 -> V_49 . V_52 ++ ;
if ( V_47 & V_48 )
V_14 -> V_53 . V_50 ++ ;
if ( V_47 & V_51 )
V_14 -> V_53 . V_52 ++ ;
F_28 ( V_14 , V_44 , 0 ) ;
F_28 ( V_14 , V_45 , 0 ) ;
}
static inline int F_22 ( struct V_13 * V_14 ,
struct V_31 * V_32 )
{
return & V_14 -> V_49 == V_32 ;
}
static inline struct V_31 * F_29 ( struct V_13 * V_14 ,
struct V_18 * V_19 )
{
return F_16 ( V_19 ) ? & V_14 -> V_49 : & V_14 -> V_53 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
int V_7 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_7 = ! ! ( V_32 -> V_19 && V_32 -> V_19 -> V_54 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
return V_7 ;
}
static struct V_13 * F_31 ( struct V_31 * V_32 )
{
return V_32 -> V_55 ;
}
static void F_32 ( struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_18 * V_19 )
{
struct V_56 * V_54 = V_19 -> V_54 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
V_32 -> V_19 = V_19 ;
V_32 -> V_57 = F_23 ( V_14 , V_54 -> V_58 ) ;
V_32 -> V_59 = 0 ;
V_32 -> V_60 = F_23 ( V_14 , V_54 -> V_61 ) ;
V_32 -> V_62 = 0 ;
V_32 -> V_63 = F_33 ( V_54 , 1 ) ;
V_32 -> V_64 = 0 ;
V_32 -> V_50 = - 1 ;
V_32 -> V_52 = - 1 ;
F_34 ( V_32 , V_65 , V_14 , V_32 ) ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static void F_35 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_22 * V_27 = F_17 ( V_32 -> V_19 ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
unsigned long V_8 ;
F_7 ( & V_6 -> V_9 , V_8 ) ;
if ( V_32 -> V_50 > 0 )
F_36 ( V_27 -> V_66 , L_1 , V_32 -> V_50 ) ;
if ( V_32 -> V_52 > 0 )
F_36 ( V_27 -> V_66 , L_2 , V_32 -> V_52 ) ;
F_34 ( V_32 , V_67 , V_14 , V_32 ) ;
V_32 -> V_19 = NULL ;
V_32 -> V_57 = 0 ;
V_32 -> V_59 = 0 ;
V_32 -> V_60 = 0 ;
V_32 -> V_62 = 0 ;
V_32 -> V_63 = 0 ;
V_32 -> V_64 = 0 ;
V_32 -> V_50 = 0 ;
V_32 -> V_52 = 0 ;
F_8 ( & V_6 -> V_9 , V_8 ) ;
}
static int F_37 ( struct V_31 * V_32 )
{
struct V_13 * V_14 = F_31 ( V_32 ) ;
if ( ! V_14 )
return - V_68 ;
return F_34 ( V_32 , V_69 , V_14 , V_32 ) ;
}
static int F_38 ( struct V_13 * V_14 , struct V_70 * V_66 )
{
struct V_31 * V_32 ;
int V_71 , V_72 ;
V_32 = & V_14 -> V_49 ;
V_71 = F_34 ( V_32 , V_73 , V_14 , V_32 , V_66 ) ;
V_32 = & V_14 -> V_53 ;
V_72 = F_34 ( V_32 , V_73 , V_14 , V_32 , V_66 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_31 * V_32 ;
int V_71 , V_72 ;
V_32 = & V_14 -> V_49 ;
V_71 = F_34 ( V_32 , remove , V_14 , V_32 ) ;
V_32 = & V_14 -> V_53 ;
V_72 = F_34 ( V_32 , remove , V_14 , V_32 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
static void F_40 ( struct V_13 * V_14 , struct V_31 * V_32 ,
T_1 V_74 , struct V_70 * V_66 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_33 = F_22 ( V_14 , V_32 ) ;
T_1 V_75 = V_14 -> V_75 ;
if ( F_10 ( V_6 ) >= 2 ) {
T_1 V_76 = 0 ;
switch ( V_74 ) {
case V_77 :
V_75 |= V_78 ;
V_76 |= V_79 ;
F_41 ( V_66 , L_3 ) ;
break;
case V_80 :
V_75 |= V_81 ;
V_76 |= V_82 ;
F_41 ( V_66 , L_4 ) ;
break;
case V_83 :
default:
V_75 |= V_78 ;
V_76 |= V_84 ;
F_41 ( V_66 , L_5 ) ;
break;
}
if ( V_33 )
F_28 ( V_14 , V_85 , V_76 ) ;
else
F_28 ( V_14 , V_86 , V_76 ) ;
}
if ( V_33 )
F_28 ( V_14 , V_87 , V_75 ) ;
else
F_28 ( V_14 , V_88 , V_75 ) ;
}
static void F_42 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
T_1 V_2 = F_43 ( 1 , F_21 ( V_14 , V_32 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_44 ( V_6 , V_89 , V_2 , V_2 ) ;
F_44 ( V_6 , V_90 , V_2 , V_2 ) ;
}
static void F_45 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
T_1 V_2 = F_43 ( 1 , F_21 ( V_14 , V_32 ) ) ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
F_44 ( V_6 , V_89 , V_2 , 0 ) ;
F_44 ( V_6 , V_90 , V_2 , 0 ) ;
}
static T_1 F_46 ( struct V_5 * V_6 )
{
return F_47 ( V_6 , V_91 ) ;
}
static void F_48 ( struct V_13 * V_14 )
{
T_1 V_2 = 0 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
V_2 |= F_43 ( 1 , F_21 ( V_14 , & V_14 -> V_49 ) ) ;
V_2 |= F_43 ( 1 , F_21 ( V_14 , & V_14 -> V_53 ) ) ;
F_44 ( V_6 , V_91 , V_2 , 0 ) ;
}
static void F_49 ( struct V_13 * V_14 , int V_92 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_3 , V_4 ;
V_3 = V_93 | V_94 ;
V_4 = V_92 ? V_3 : 0 ;
F_13 ( V_14 ) ?
F_44 ( V_6 , V_95 , V_3 , V_4 ) :
F_44 ( V_6 , V_96 , V_3 , V_4 ) ;
}
static int F_50 ( struct V_70 * V_66 ,
struct V_13 * V_14 ,
int V_97 ,
int V_98 ,
int div ,
int (* F_51)( struct V_70 * V_66 ,
struct V_13 * V_14 ) )
{
struct V_99 * clock = & V_14 -> clock ;
int V_34 = F_13 ( V_14 ) ;
clock -> V_97 = NULL ;
clock -> V_98 = NULL ;
clock -> div = NULL ;
clock -> V_100 = 0 ;
clock -> V_101 = 0 ;
clock -> F_51 = F_51 ;
clock -> V_102 = F_52 ( V_66 , NULL ) ;
if ( F_53 ( clock -> V_102 ) )
return - V_103 ;
if ( V_97 ) {
clock -> V_97 = F_52 ( V_66 , V_34 ? L_6 : L_7 ) ;
if ( F_53 ( clock -> V_97 ) ) {
F_36 ( V_66 , L_8 ) ;
return - V_103 ;
}
if ( clock -> V_97 == clock -> V_102 ) {
F_36 ( V_66 , L_9 ) ;
return - V_103 ;
}
}
if ( V_98 ) {
clock -> V_98 = F_52 ( V_66 , V_34 ? L_10 : L_11 ) ;
if ( F_53 ( clock -> V_98 ) ) {
F_36 ( V_66 , L_12 ) ;
return - V_103 ;
}
if ( clock -> V_98 == clock -> V_102 ) {
F_36 ( V_66 , L_13 ) ;
return - V_103 ;
}
}
if ( div ) {
clock -> div = F_52 ( V_66 , V_34 ? L_14 : L_15 ) ;
if ( F_53 ( clock -> div ) ) {
F_36 ( V_66 , L_16 ) ;
return - V_103 ;
}
if ( clock -> div == clock -> V_102 ) {
F_36 ( V_66 , L_17 ) ;
return - V_103 ;
}
}
return 0 ;
}
static void F_54 ( struct V_13 * V_14 , unsigned long V_100 )
{
V_14 -> clock . V_100 = V_100 ;
}
static int F_55 ( struct V_13 * V_14 )
{
return V_14 -> clock . F_51 &&
V_14 -> clock . V_100 ;
}
static int F_56 ( struct V_70 * V_66 ,
struct V_13 * V_14 )
{
struct V_99 * clock = & V_14 -> clock ;
int V_7 = - V_103 ;
if ( ! F_55 ( V_14 ) )
return V_7 ;
if ( 0 == clock -> V_101 ) {
V_7 = clock -> F_51 ( V_66 , V_14 ) ;
if ( V_7 < 0 ) {
F_57 ( V_14 ) ;
return V_7 ;
}
if ( clock -> V_97 )
F_58 ( clock -> V_97 ) ;
if ( clock -> V_98 )
F_58 ( clock -> V_98 ) ;
if ( clock -> div )
F_58 ( clock -> div ) ;
clock -> V_101 ++ ;
}
return V_7 ;
}
static int F_59 ( struct V_70 * V_66 ,
struct V_13 * V_14 )
{
struct V_99 * clock = & V_14 -> clock ;
if ( ! F_55 ( V_14 ) )
return - V_103 ;
if ( 1 == clock -> V_101 -- ) {
if ( clock -> V_97 )
F_60 ( clock -> V_97 ) ;
if ( clock -> V_98 )
F_60 ( clock -> V_98 ) ;
if ( clock -> div )
F_60 ( clock -> div ) ;
}
return 0 ;
}
static int F_61 ( struct V_70 * V_66 ,
struct V_13 * V_14 ,
int V_104 , int V_105 )
{
T_1 V_2 = 0 ;
if ( V_105 > V_104 ) {
F_36 ( V_66 , L_18 , V_104 , V_105 ) ;
return - V_103 ;
}
switch ( V_104 ) {
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
F_36 ( V_66 , L_19 , V_104 ) ;
return - V_103 ;
}
switch ( V_105 ) {
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
F_36 ( V_66 , L_20 , V_105 ) ;
return - V_103 ;
}
F_41 ( V_66 , L_21 , V_104 , V_105 ) ;
F_62 ( V_14 , V_106 , ( V_107 | V_108 ) , V_2 ) ;
F_63 ( 10 ) ;
return 0 ;
}
static int F_64 ( struct V_70 * V_66 ,
struct V_13 * V_14 )
{
struct V_109 * V_97 = V_14 -> clock . V_97 ;
struct V_109 * V_98 = V_14 -> clock . V_98 ;
unsigned long V_100 = V_14 -> clock . V_100 ;
unsigned long V_110 ;
int V_104 , V_105 ;
int V_7 = 0 ;
V_110 = F_65 ( V_97 ) ;
if ( V_110 % V_100 ) {
F_36 ( V_66 , L_22 ) ;
return - V_103 ;
}
F_66 ( V_98 , V_97 ) ;
F_67 ( V_98 , V_110 ) ;
V_105 = V_14 -> V_41 * 32 ;
V_104 = V_110 / V_100 ;
F_41 ( V_66 , L_23 , V_110 , V_100 ) ;
V_7 = F_61 ( V_66 , V_14 , V_104 , V_105 ) ;
if ( V_7 < 0 )
F_36 ( V_66 , L_24 , V_111 ) ;
return V_7 ;
}
static int F_68 ( struct V_70 * V_66 ,
struct V_13 * V_14 )
{
struct V_109 * V_98 = V_14 -> clock . V_98 ;
struct V_109 * div = V_14 -> clock . div ;
unsigned long V_100 = V_14 -> clock . V_100 ;
unsigned long V_112 = 0 ;
unsigned long V_113 , V_114 ;
unsigned long V_115 , V_116 ;
unsigned long V_117 , V_118 ;
int V_119 ;
int V_104 , V_105 ;
int V_7 = - V_103 ;
if ( ! ( 12288000 % V_100 ) )
V_112 = 12288000 ;
if ( ! ( 11289600 % V_100 ) )
V_112 = 11289600 ;
if ( ! V_112 ) {
F_36 ( V_66 , L_25 ) ;
return V_7 ;
}
V_105 = V_14 -> V_41 * 32 ;
V_104 = V_112 / V_100 ;
V_7 = F_61 ( V_66 , V_14 , V_104 , V_105 ) ;
if ( V_7 < 0 ) {
F_36 ( V_66 , L_24 , V_111 ) ;
return V_7 ;
}
V_116 = ~ 0 ;
V_117 = 0 ;
V_118 = 0 ;
for ( V_119 = 1 ; V_119 < 0xffff ; V_119 ++ ) {
V_114 = V_112 * V_119 ;
if ( V_114 > 100000000 )
break;
V_114 = F_69 ( V_98 , V_114 ) ;
V_113 = V_114 / V_119 ;
V_115 = abs ( V_113 - V_112 ) ;
if ( V_115 < V_116 ) {
V_116 = V_115 ;
V_117 = V_114 ;
V_118 = V_113 ;
}
}
V_7 = F_67 ( V_98 , V_117 ) ;
if ( V_7 < 0 ) {
F_36 ( V_66 , L_26 ) ;
return - V_68 ;
}
V_7 = F_67 ( div , F_69 ( div , V_118 ) ) ;
if ( V_7 < 0 ) {
F_36 ( V_66 , L_27 ) ;
return - V_68 ;
}
F_41 ( V_66 , L_28 ,
F_65 ( V_98 ) , F_65 ( div ) ) ;
return V_7 ;
}
static void F_70 ( struct V_13 * V_14 , T_3 * V_120 , int V_42 )
{
int V_121 ;
if ( F_15 ( V_14 ) ) {
T_1 * V_122 = ( T_1 * ) V_120 ;
for ( V_121 = 0 ; V_121 < V_42 / 2 ; V_121 ++ )
F_28 ( V_14 , V_123 , V_122 [ V_121 ] ) ;
} else {
T_4 * V_122 = ( T_4 * ) V_120 ;
for ( V_121 = 0 ; V_121 < V_42 ; V_121 ++ )
F_28 ( V_14 , V_123 , ( ( T_1 ) * ( V_122 + V_121 ) << 8 ) ) ;
}
}
static void F_71 ( struct V_13 * V_14 , T_3 * V_120 , int V_42 )
{
T_4 * V_122 = ( T_4 * ) V_120 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_42 ; V_121 ++ )
* ( V_122 + V_121 ) = ( T_4 ) ( F_26 ( V_14 , V_124 ) >> 8 ) ;
}
static void F_72 ( struct V_13 * V_14 , T_3 * V_120 , int V_42 )
{
T_1 * V_122 = ( T_1 * ) V_120 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_42 ; V_121 ++ )
F_28 ( V_14 , V_123 , * ( V_122 + V_121 ) ) ;
}
static void F_73 ( struct V_13 * V_14 , T_3 * V_120 , int V_42 )
{
T_1 * V_122 = ( T_1 * ) V_120 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_42 ; V_121 ++ )
* ( V_122 + V_121 ) = F_26 ( V_14 , V_124 ) ;
}
static T_3 * F_74 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_56 * V_54 = V_32 -> V_19 -> V_54 ;
return V_54 -> V_125 +
F_33 ( V_54 , V_32 -> V_59 ) ;
}
static int F_75 ( struct V_13 * V_14 , struct V_31 * V_32 ,
void (* F_76)( struct V_13 * V_14 , T_3 * V_122 , int V_42 ) ,
void (* F_77)( struct V_13 * V_14 , T_3 * V_122 , int V_42 ) ,
int V_42 )
{
struct V_56 * V_54 ;
struct V_18 * V_19 ;
T_3 * V_122 ;
int V_126 ;
if ( ! F_30 ( V_14 , V_32 ) )
return - V_103 ;
V_126 = 0 ;
V_19 = V_32 -> V_19 ;
V_54 = V_19 -> V_54 ;
if ( V_32 -> V_59 >=
V_32 -> V_60 * ( V_32 -> V_62 + 1 ) ) {
V_126 = 1 ;
V_32 -> V_62 = ( V_32 -> V_62 + 1 ) % V_54 -> V_127 ;
if ( 0 == V_32 -> V_62 )
V_32 -> V_59 = 0 ;
}
V_122 = F_74 ( V_14 , V_32 ) ;
switch ( V_32 -> V_63 ) {
case 2 :
F_76 ( V_14 , V_122 , V_42 ) ;
break;
case 4 :
F_77 ( V_14 , V_122 , V_42 ) ;
break;
default:
return - V_103 ;
}
V_32 -> V_59 += V_42 ;
if ( V_126 )
F_78 ( V_19 ) ;
return 0 ;
}
static int F_79 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
int V_128 ;
int V_129 ;
int V_42 ;
V_128 = F_25 ( V_14 , V_32 ) ;
V_129 = V_32 -> V_57 - V_32 -> V_59 ;
V_42 = V_116 ( V_128 , V_129 ) ;
return F_75 ( V_14 , V_32 ,
F_71 ,
F_73 ,
V_42 ) ;
}
static int F_80 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
int V_128 ;
int V_129 ;
int V_42 ;
V_128 = V_32 -> V_57 - V_32 -> V_59 ;
V_129 = V_32 -> V_130 -
F_25 ( V_14 , V_32 ) ;
V_42 = V_116 ( V_128 , V_129 ) ;
return F_75 ( V_14 , V_32 ,
F_70 ,
F_72 ,
V_42 ) ;
}
static void F_81 ( struct V_13 * V_14 , struct V_31 * V_32 ,
int V_92 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_109 = F_13 ( V_14 ) ? V_131 : V_132 ;
if ( V_92 )
F_42 ( V_14 , V_32 ) ;
else
F_45 ( V_14 , V_32 ) ;
if ( F_12 ( V_14 ) )
F_82 ( V_6 , V_133 , V_109 , ( V_92 ) ? V_109 : 0 ) ;
}
static int F_83 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
if ( F_15 ( V_14 ) )
V_32 -> V_64 = F_84 ( 24 , V_83 ) |
F_84 ( 16 , V_80 ) ;
else
V_32 -> V_64 = F_84 ( 24 , V_83 ) |
F_84 ( 16 , V_83 ) ;
return 0 ;
}
static int F_85 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
V_32 -> V_64 = F_84 ( 24 , V_83 ) |
F_84 ( 16 , V_83 ) ;
return 0 ;
}
static T_5 F_86 ( int V_134 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
T_1 V_91 = F_46 ( V_6 ) ;
F_82 ( V_6 , V_135 , V_136 , 0 ) ;
F_82 ( V_6 , V_135 , V_136 , V_136 ) ;
if ( V_91 & F_43 ( 1 , V_36 ) )
F_37 ( & V_6 -> V_29 . V_49 ) ;
if ( V_91 & F_43 ( 1 , V_38 ) )
F_37 ( & V_6 -> V_30 . V_49 ) ;
if ( V_91 & F_43 ( 1 , V_37 ) )
F_37 ( & V_6 -> V_29 . V_53 ) ;
if ( V_91 & F_43 ( 1 , V_39 ) )
F_37 ( & V_6 -> V_30 . V_53 ) ;
F_27 ( & V_6 -> V_29 ) ;
F_27 ( & V_6 -> V_30 ) ;
F_48 ( & V_6 -> V_29 ) ;
F_48 ( & V_6 -> V_30 ) ;
return V_137 ;
}
static int F_87 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_56 * V_54 = V_32 -> V_19 -> V_54 ;
struct V_22 * V_27 = F_17 ( V_32 -> V_19 ) ;
enum V_138 V_139 = F_22 ( V_14 , V_32 ) ?
V_140 : V_141 ;
V_32 -> V_64 = F_84 ( 24 , V_83 ) |
F_84 ( 16 , V_80 ) ;
V_32 -> V_76 = F_88 ( V_27 -> V_66 , V_54 -> V_125 ,
F_89 ( V_32 -> V_19 ) , V_139 ) ;
return 0 ;
}
static int F_90 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
struct V_22 * V_27 = F_17 ( V_32 -> V_19 ) ;
enum V_138 V_139 = F_22 ( V_14 , V_32 ) ?
V_140 : V_141 ;
F_91 ( V_27 -> V_66 , V_32 -> V_76 ,
F_89 ( V_32 -> V_19 ) , V_139 ) ;
return 0 ;
}
static T_6 F_92 ( struct V_31 * V_32 )
{
struct V_56 * V_54 = V_32 -> V_19 -> V_54 ;
return V_32 -> V_76 + F_33 ( V_54 , V_32 -> V_59 ) ;
}
static void F_93 ( void * V_2 )
{
struct V_31 * V_32 = (struct V_31 * ) V_2 ;
struct V_13 * V_14 = F_31 ( V_32 ) ;
struct V_56 * V_54 = V_32 -> V_19 -> V_54 ;
struct V_22 * V_27 = F_17 ( V_32 -> V_19 ) ;
enum V_138 V_139 = F_22 ( V_14 , V_32 ) ?
V_140 : V_141 ;
F_94 ( V_27 -> V_66 , F_92 ( V_32 ) ,
F_33 ( V_54 , V_32 -> V_60 ) , V_139 ) ;
V_32 -> V_59 += V_32 -> V_60 ;
V_32 -> V_62 ++ ;
if ( V_32 -> V_62 >= V_54 -> V_127 ) {
V_32 -> V_62 = 0 ;
V_32 -> V_59 = 0 ;
}
F_27 ( V_14 ) ;
F_37 ( V_32 ) ;
F_78 ( V_32 -> V_19 ) ;
}
static void F_95 ( struct V_142 * V_143 )
{
struct V_31 * V_32 = F_96 ( V_143 , struct V_31 , V_143 ) ;
struct V_13 * V_14 = F_31 ( V_32 ) ;
struct V_22 * V_27 ;
struct V_144 * V_145 ;
struct V_56 * V_54 ;
enum V_138 V_139 ;
int V_33 = F_22 ( V_14 , V_32 ) ;
int V_146 ;
T_6 V_122 ;
if ( ! F_30 ( V_14 , V_32 ) )
return;
V_27 = F_17 ( V_32 -> V_19 ) ;
V_54 = V_32 -> V_19 -> V_54 ;
V_139 = V_33 ? V_140 : V_141 ;
V_146 = F_33 ( V_54 , V_32 -> V_60 ) ;
V_122 = F_92 ( V_32 ) ;
F_97 ( V_27 -> V_66 , V_122 , V_146 , V_139 ) ;
V_145 = F_98 ( V_32 -> V_147 , V_122 , V_146 , V_139 ,
V_148 | V_149 ) ;
if ( ! V_145 ) {
F_36 ( V_27 -> V_66 , L_29 ) ;
return;
}
V_145 -> V_150 = F_93 ;
V_145 -> V_151 = V_32 ;
if ( F_99 ( V_145 ) < 0 ) {
F_36 ( V_27 -> V_66 , L_30 ) ;
return;
}
F_100 ( V_32 -> V_147 ) ;
if ( ! V_33 ) {
if ( V_48 & F_26 ( V_14 , V_45 ) ) {
F_62 ( V_14 , V_152 , V_153 , V_153 ) ;
F_28 ( V_14 , V_45 , 0 ) ;
}
}
}
static bool F_101 ( struct V_154 * V_147 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
V_147 -> V_158 = V_157 ;
return true ;
}
static int F_102 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
F_103 ( & V_32 -> V_143 ) ;
return 0 ;
}
static void F_104 ( struct V_13 * V_14 , struct V_31 * V_32 ,
int V_159 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
T_1 V_109 = F_13 ( V_14 ) ? V_131 : V_132 ;
T_1 V_92 = V_159 ? V_160 : 0 ;
F_62 ( V_14 , V_85 , V_160 , V_92 ) ;
F_105 ( V_32 -> V_147 ) ;
if ( F_12 ( V_14 ) )
F_82 ( V_6 , V_133 , V_109 , ( V_92 ) ? V_109 : 0 ) ;
}
static int F_106 ( struct V_13 * V_14 , struct V_31 * V_32 , struct V_70 * V_66 )
{
T_7 V_3 ;
F_107 ( V_3 ) ;
F_108 ( V_161 , V_3 ) ;
V_32 -> V_147 = F_109 ( V_3 , F_101 , & V_32 -> V_157 ) ;
if ( ! V_32 -> V_147 ) {
if ( F_22 ( V_14 , V_32 ) )
V_14 -> V_49 . V_162 = & V_163 ;
else
V_14 -> V_53 . V_162 = & V_164 ;
F_110 ( V_66 , L_31 ) ;
return F_38 ( V_14 , V_66 ) ;
}
F_111 ( & V_32 -> V_143 , F_95 ) ;
return 0 ;
}
static int F_112 ( struct V_13 * V_14 , struct V_31 * V_32 )
{
F_113 ( & V_32 -> V_143 ) ;
F_114 ( V_14 , V_32 ) ;
if ( V_32 -> V_147 )
F_115 ( V_32 -> V_147 ) ;
V_32 -> V_147 = NULL ;
return 0 ;
}
static void F_116 ( struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_70 * V_66 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
int V_33 = F_22 ( V_14 , V_32 ) ;
T_1 V_35 , V_121 ;
int V_165 ;
V_35 = F_117 ( V_6 , V_166 ) ;
V_35 >>= F_21 ( V_14 , V_32 ) ;
V_35 &= V_167 ;
V_165 = 256 << V_35 ;
F_41 ( V_66 , L_32 , V_165 ) ;
for ( V_121 = 1 ; V_121 < V_14 -> V_41 ; V_121 <<= 1 )
V_165 >>= 1 ;
F_41 ( V_66 , L_33 ,
V_14 -> V_41 , V_165 ) ;
V_32 -> V_130 = F_23 ( V_14 , V_165 ) ;
if ( V_33 ) {
F_28 ( V_14 , V_168 , V_169 ) ;
F_62 ( V_14 , V_168 , V_153 , V_153 ) ;
} else {
F_28 ( V_14 , V_152 , V_169 ) ;
F_62 ( V_14 , V_152 , V_153 , V_153 ) ;
}
}
static int F_118 ( struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_70 * V_66 )
{
T_1 V_2 = 0 ;
if ( F_12 ( V_14 ) )
V_2 = V_170 | V_171 ;
F_62 ( V_14 , V_106 , ( V_170 | V_171 ) , V_2 ) ;
V_2 = 0 ;
if ( V_14 -> V_172 )
V_2 |= ( 1 << 0 ) ;
if ( V_14 -> V_173 )
V_2 |= ( 1 << 4 ) ;
if ( F_12 ( V_14 ) )
V_2 <<= 8 ;
F_28 ( V_14 , V_174 , V_2 ) ;
if ( F_14 ( V_14 ) ) {
F_49 ( V_14 , 1 ) ;
F_62 ( V_14 , V_175 , V_176 , V_176 ) ;
}
V_2 = 0 ;
switch ( V_32 -> V_63 ) {
case 2 :
V_2 = F_119 ( 16 , V_32 -> V_64 ) ;
break;
case 4 :
V_2 = F_119 ( 24 , V_32 -> V_64 ) ;
break;
}
F_40 ( V_14 , V_32 , V_2 , V_66 ) ;
F_45 ( V_14 , V_32 ) ;
F_48 ( V_14 ) ;
F_116 ( V_14 , V_32 , V_66 ) ;
if ( F_12 ( V_14 ) )
return F_56 ( V_66 , V_14 ) ;
return 0 ;
}
static int F_120 ( struct V_13 * V_14 ,
struct V_70 * V_66 )
{
if ( F_12 ( V_14 ) )
return F_59 ( V_66 , V_14 ) ;
return 0 ;
}
static int F_121 ( struct V_18 * V_19 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
F_57 ( V_14 ) ;
return 0 ;
}
static void F_122 ( struct V_18 * V_19 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
F_57 ( V_14 ) ;
}
static int F_123 ( struct V_18 * V_19 , int V_177 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
struct V_31 * V_32 = F_29 ( V_14 , V_19 ) ;
int V_7 = 0 ;
switch ( V_177 ) {
case V_178 :
F_32 ( V_14 , V_32 , V_19 ) ;
if ( ! V_7 )
V_7 = F_118 ( V_14 , V_32 , V_27 -> V_66 ) ;
if ( ! V_7 )
V_7 = F_37 ( V_32 ) ;
if ( ! V_7 )
F_124 ( V_14 , V_32 ) ;
break;
case V_179 :
if ( ! V_7 )
V_7 = F_120 ( V_14 , V_27 -> V_66 ) ;
F_114 ( V_14 , V_32 ) ;
F_35 ( V_14 , V_32 ) ;
break;
}
return V_7 ;
}
static int F_125 ( struct V_13 * V_14 , unsigned int V_75 )
{
switch ( V_75 & V_180 ) {
case V_181 :
V_14 -> V_75 = V_182 ;
V_14 -> V_41 = 2 ;
break;
case V_183 :
V_14 -> V_75 = V_184 ;
V_14 -> V_41 = 2 ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_126 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
if ( F_10 ( V_6 ) < 2 )
return - V_103 ;
V_14 -> V_75 = V_185 | V_184 ;
V_14 -> V_41 = 2 ;
return 0 ;
}
static int F_127 ( struct V_22 * V_27 , unsigned int V_75 )
{
struct V_13 * V_14 = F_18 ( V_27 ) ;
int V_7 ;
switch ( V_75 & V_186 ) {
case V_187 :
V_14 -> V_15 = 1 ;
break;
case V_188 :
break;
default:
return - V_103 ;
}
switch ( V_75 & V_189 ) {
case V_190 :
V_14 -> V_172 = 0 ;
V_14 -> V_173 = 1 ;
break;
case V_191 :
V_14 -> V_172 = 1 ;
V_14 -> V_173 = 0 ;
break;
case V_192 :
V_14 -> V_172 = 1 ;
V_14 -> V_173 = 1 ;
break;
case V_193 :
default:
V_14 -> V_172 = 0 ;
V_14 -> V_173 = 0 ;
break;
}
if ( F_12 ( V_14 ) ) {
if ( V_14 -> V_194 )
F_50 ( V_27 -> V_66 , V_14 , 0 , 1 , 1 ,
F_68 ) ;
else
F_50 ( V_27 -> V_66 , V_14 , 1 , 1 , 0 ,
F_64 ) ;
}
if ( F_14 ( V_14 ) )
V_7 = F_126 ( V_14 ) ;
else
V_7 = F_125 ( V_14 , V_75 & V_180 ) ;
return V_7 ;
}
static int F_128 ( struct V_18 * V_19 ,
struct V_195 * V_196 ,
struct V_22 * V_27 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
if ( F_12 ( V_14 ) )
F_54 ( V_14 , F_129 ( V_196 ) ) ;
return 0 ;
}
static int F_130 ( struct V_18 * V_19 )
{
struct V_56 * V_54 = V_19 -> V_54 ;
int V_7 = 0 ;
F_131 ( V_19 , & V_197 ) ;
V_7 = F_132 ( V_54 ,
V_198 ) ;
return V_7 ;
}
static int F_133 ( struct V_18 * V_19 ,
struct V_195 * V_199 )
{
return F_134 ( V_19 ,
F_135 ( V_199 ) ) ;
}
static int F_136 ( struct V_18 * V_19 )
{
return F_137 ( V_19 ) ;
}
static T_8 F_138 ( struct V_18 * V_19 )
{
struct V_13 * V_14 = F_20 ( V_19 ) ;
struct V_31 * V_32 = F_29 ( V_14 , V_19 ) ;
return F_24 ( V_14 , V_32 -> V_59 ) ;
}
static void F_139 ( struct V_200 * V_201 )
{
F_140 ( V_201 ) ;
}
static int F_141 ( struct V_23 * V_24 )
{
struct V_200 * V_201 = V_24 -> V_201 ;
return F_142 (
V_201 ,
V_202 ,
F_143 ( V_203 ) ,
V_204 , V_205 ) ;
}
static void F_144 ( char * V_206 ,
struct V_207 * V_208 ,
struct V_209 * V_210 ,
struct V_70 * V_66 )
{
int V_121 ;
char V_211 [ 128 ] ;
unsigned long V_8 = 0 ;
struct {
char * V_206 ;
unsigned int V_4 ;
} V_212 [] = {
{ L_34 , V_213 } ,
{ L_35 , V_214 } ,
{ L_36 , V_215 } ,
} ;
for ( V_121 = 0 ; V_121 < F_145 ( V_212 ) ; V_121 ++ ) {
sprintf ( V_211 , L_37 , V_206 , V_212 [ V_121 ] . V_206 ) ;
if ( F_146 ( V_208 , V_211 , NULL ) )
V_8 |= V_212 [ V_121 ] . V_4 ;
}
V_210 -> V_8 = V_8 ;
F_41 ( V_66 , L_38 , V_206 , V_210 -> V_8 ) ;
}
static void F_147 ( struct V_13 * V_14 ,
struct V_209 * V_210 )
{
if ( V_210 -> V_8 & V_213 )
V_14 -> V_16 = 1 ;
if ( V_210 -> V_8 & V_215 )
V_14 -> V_194 = 1 ;
if ( V_210 -> V_8 & V_214 )
V_14 -> V_17 = 1 ;
}
static void F_148 ( struct V_13 * V_14 ,
struct V_209 * V_210 )
{
V_14 -> V_49 . V_162 = & V_163 ;
V_14 -> V_49 . V_55 = V_14 ;
V_14 -> V_53 . V_162 = & V_164 ;
V_14 -> V_53 . V_55 = V_14 ;
if ( V_210 -> V_216 ) {
V_14 -> V_49 . V_157 . V_217 . V_218 = V_210 -> V_216 ;
V_14 -> V_49 . V_162 = & V_219 ;
}
}
static int F_149 ( struct V_220 * V_221 )
{
struct V_5 * V_6 ;
struct V_207 * V_208 = V_221 -> V_66 . V_222 ;
struct V_223 V_210 ;
const struct V_224 * V_11 ;
struct V_13 * V_14 ;
struct V_225 * V_226 ;
unsigned int V_134 ;
int V_7 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_11 = NULL ;
if ( V_208 ) {
const struct V_227 * V_228 ;
V_228 = F_150 ( V_229 , & V_221 -> V_66 ) ;
if ( V_228 ) {
V_11 = V_228 -> V_2 ;
F_144 ( L_39 , V_208 , & V_210 . V_230 , & V_221 -> V_66 ) ;
F_144 ( L_40 , V_208 , & V_210 . V_231 , & V_221 -> V_66 ) ;
}
} else {
const struct V_232 * V_233 = V_221 -> V_233 ;
if ( V_233 )
V_11 = (struct V_224 * ) V_233 -> V_234 ;
if ( V_221 -> V_66 . V_235 )
memcpy ( & V_210 , V_221 -> V_66 . V_235 , sizeof( V_210 ) ) ;
}
if ( ! V_11 ) {
F_36 ( & V_221 -> V_66 , L_41 ) ;
return - V_236 ;
}
V_226 = F_151 ( V_221 , V_237 , 0 ) ;
V_134 = F_152 ( V_221 , 0 ) ;
if ( ! V_226 || ( int ) V_134 <= 0 ) {
F_36 ( & V_221 -> V_66 , L_42 ) ;
return - V_236 ;
}
V_6 = F_153 ( & V_221 -> V_66 , sizeof( * V_6 ) , V_203 ) ;
if ( ! V_6 ) {
F_36 ( & V_221 -> V_66 , L_43 ) ;
return - V_238 ;
}
V_6 -> V_10 = F_154 ( & V_221 -> V_66 ,
V_226 -> V_159 , F_155 ( V_226 ) ) ;
if ( ! V_6 -> V_10 ) {
F_36 ( & V_221 -> V_66 , L_44 ) ;
return - V_239 ;
}
V_6 -> V_134 = V_134 ;
V_6 -> V_11 = V_11 ;
F_156 ( & V_6 -> V_9 ) ;
V_14 = & V_6 -> V_29 ;
V_14 -> V_10 = V_6 -> V_10 ;
V_14 -> V_6 = V_6 ;
F_147 ( V_14 , & V_210 . V_230 ) ;
F_148 ( V_14 , & V_210 . V_230 ) ;
V_7 = F_38 ( V_14 , & V_221 -> V_66 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_221 -> V_66 , L_45 ) ;
return V_7 ;
}
V_14 = & V_6 -> V_30 ;
V_14 -> V_10 = V_6 -> V_10 + 0x40 ;
V_14 -> V_6 = V_6 ;
F_147 ( V_14 , & V_210 . V_231 ) ;
F_148 ( V_14 , & V_210 . V_231 ) ;
V_7 = F_38 ( V_14 , & V_221 -> V_66 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_221 -> V_66 , L_46 ) ;
goto V_240;
}
F_157 ( & V_221 -> V_66 ) ;
F_158 ( & V_221 -> V_66 , V_6 ) ;
V_7 = F_159 ( & V_221 -> V_66 , V_134 , & F_86 , 0 ,
F_160 ( & V_221 -> V_66 ) , V_6 ) ;
if ( V_7 ) {
F_36 ( & V_221 -> V_66 , L_47 ) ;
goto V_241;
}
V_7 = F_161 ( & V_221 -> V_66 , & V_242 ) ;
if ( V_7 < 0 ) {
F_36 ( & V_221 -> V_66 , L_48 ) ;
goto V_241;
}
V_7 = F_162 ( & V_221 -> V_66 , V_243 ,
F_145 ( V_243 ) ) ;
if ( V_7 < 0 ) {
F_36 ( & V_221 -> V_66 , L_49 ) ;
goto V_244;
}
return V_7 ;
V_244:
F_163 ( & V_221 -> V_66 ) ;
V_241:
F_164 ( & V_221 -> V_66 ) ;
F_39 ( & V_6 -> V_30 ) ;
V_240:
F_39 ( & V_6 -> V_29 ) ;
return V_7 ;
}
static int F_165 ( struct V_220 * V_221 )
{
struct V_5 * V_6 ;
V_6 = F_166 ( & V_221 -> V_66 ) ;
F_164 ( & V_221 -> V_66 ) ;
F_167 ( & V_221 -> V_66 , F_145 ( V_243 ) ) ;
F_163 ( & V_221 -> V_66 ) ;
F_39 ( & V_6 -> V_29 ) ;
F_39 ( & V_6 -> V_30 ) ;
return 0 ;
}
static void F_168 ( struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_70 * V_66 )
{
if ( ! F_30 ( V_14 , V_32 ) )
return;
F_114 ( V_14 , V_32 ) ;
F_120 ( V_14 , V_66 ) ;
}
static void F_169 ( struct V_13 * V_14 ,
struct V_31 * V_32 ,
struct V_70 * V_66 )
{
if ( ! F_30 ( V_14 , V_32 ) )
return;
F_118 ( V_14 , V_32 , V_66 ) ;
F_124 ( V_14 , V_32 ) ;
}
static int F_170 ( struct V_70 * V_66 )
{
struct V_5 * V_6 = F_166 ( V_66 ) ;
struct V_13 * V_29 = & V_6 -> V_29 ;
struct V_13 * V_30 = & V_6 -> V_30 ;
F_168 ( V_29 , & V_29 -> V_49 , V_66 ) ;
F_168 ( V_29 , & V_29 -> V_53 , V_66 ) ;
F_168 ( V_30 , & V_30 -> V_49 , V_66 ) ;
F_168 ( V_30 , & V_30 -> V_53 , V_66 ) ;
return 0 ;
}
static int F_171 ( struct V_70 * V_66 )
{
struct V_5 * V_6 = F_166 ( V_66 ) ;
struct V_13 * V_29 = & V_6 -> V_29 ;
struct V_13 * V_30 = & V_6 -> V_30 ;
F_169 ( V_29 , & V_29 -> V_49 , V_66 ) ;
F_169 ( V_29 , & V_29 -> V_53 , V_66 ) ;
F_169 ( V_30 , & V_30 -> V_49 , V_66 ) ;
F_169 ( V_30 , & V_30 -> V_53 , V_66 ) ;
return 0 ;
}
