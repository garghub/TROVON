static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return & V_2 -> V_5 == V_4 ;
}
static void F_2 ( T_1 T_2 * V_6 , T_1 V_7 )
{
V_7 &= 0x00ffffff ;
F_3 ( V_7 , V_6 ) ;
}
static T_1 F_4 ( T_1 T_2 * V_6 )
{
return F_5 ( V_6 ) ;
}
static void F_6 ( T_1 T_2 * V_6 , T_1 V_8 , T_1 V_7 )
{
T_1 V_9 = F_4 ( V_6 ) ;
V_9 &= ~ V_8 ;
V_9 |= V_7 & V_8 ;
F_2 ( V_6 , V_9 ) ;
}
static T_1 F_7 ( struct V_10 * V_11 , T_1 V_6 )
{
T_1 V_12 ;
unsigned long V_13 ;
F_8 ( & V_11 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_11 -> V_15 + V_6 ) ;
F_9 ( & V_11 -> V_14 , V_13 ) ;
return V_12 ;
}
static void F_10 ( struct V_10 * V_11 ,
T_1 V_6 , T_1 V_8 , T_1 V_7 )
{
unsigned long V_13 ;
F_8 ( & V_11 -> V_14 , V_13 ) ;
F_6 ( V_11 -> V_15 + V_6 , V_8 , V_7 ) ;
F_9 ( & V_11 -> V_14 , V_13 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
return V_11 -> V_16 -> V_17 ;
}
static struct V_10 * F_12 ( struct V_1 * V_2 )
{
return V_2 -> V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_18 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return V_2 -> V_11 -> V_15 == V_2 -> V_15 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_19 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_20 ;
}
static int F_17 ( struct V_21 * V_22 )
{
return V_22 -> V_23 == V_24 ;
}
static struct V_25 * F_18 ( struct V_21 * V_22 )
{
struct V_26 * V_27 = V_22 -> V_28 ;
return V_27 -> V_29 ;
}
static struct V_1 * F_19 ( struct V_25 * V_30 )
{
struct V_10 * V_11 = F_20 ( V_30 ) ;
if ( V_30 -> V_31 == 0 )
return & V_11 -> V_32 ;
else
return & V_11 -> V_33 ;
}
static struct V_1 * F_21 ( struct V_21 * V_22 )
{
return F_19 ( F_18 ( V_22 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_34 = F_1 ( V_2 , V_4 ) ;
int V_35 = F_14 ( V_2 ) ;
T_1 V_36 ;
if ( V_35 )
V_36 = V_34 ? V_37 : V_38 ;
else
V_36 = V_34 ? V_39 : V_40 ;
return V_36 ;
}
static int F_23 ( struct V_1 * V_2 , int V_41 )
{
return V_41 * V_2 -> V_42 ;
}
static int F_24 ( struct V_1 * V_2 , int V_43 )
{
return V_43 / V_2 -> V_42 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_34 = F_1 ( V_2 , V_4 ) ;
T_1 V_44 ;
int V_41 ;
V_44 = V_34 ?
F_26 ( V_2 , V_45 ) :
F_26 ( V_2 , V_46 ) ;
V_41 = 0x1ff & ( V_44 >> 8 ) ;
return F_23 ( V_2 , V_41 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_47 = F_26 ( V_2 , V_45 ) ;
T_1 V_48 = F_26 ( V_2 , V_46 ) ;
if ( V_47 & V_49 )
V_2 -> V_5 . V_50 ++ ;
if ( V_47 & V_51 )
V_2 -> V_5 . V_52 ++ ;
if ( V_48 & V_49 )
V_2 -> V_53 . V_50 ++ ;
if ( V_48 & V_51 )
V_2 -> V_53 . V_52 ++ ;
F_28 ( V_2 , V_45 , 0 ) ;
F_28 ( V_2 , V_46 , 0 ) ;
}
static inline struct V_3 * F_29 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
return F_17 ( V_22 ) ? & V_2 -> V_5 : & V_2 -> V_53 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
unsigned long V_13 ;
int V_12 ;
F_8 ( & V_11 -> V_14 , V_13 ) ;
V_12 = ! ! ( V_4 -> V_22 && V_4 -> V_22 -> V_54 ) ;
F_9 ( & V_11 -> V_14 , V_13 ) ;
return V_12 ;
}
static struct V_1 * F_31 ( struct V_3 * V_4 )
{
return V_4 -> V_55 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_56 * V_54 = V_22 -> V_54 ;
struct V_10 * V_11 = F_12 ( V_2 ) ;
unsigned long V_13 ;
F_8 ( & V_11 -> V_14 , V_13 ) ;
V_4 -> V_22 = V_22 ;
V_4 -> V_57 = F_23 ( V_2 , V_54 -> V_58 ) ;
V_4 -> V_59 = 0 ;
V_4 -> V_60 = F_23 ( V_2 , V_54 -> V_61 ) ;
V_4 -> V_62 = 0 ;
V_4 -> V_63 = F_33 ( V_54 , 1 ) ;
V_4 -> V_64 = 0 ;
V_4 -> V_50 = - 1 ;
V_4 -> V_52 = - 1 ;
F_34 ( V_4 , V_65 , V_2 , V_4 ) ;
F_9 ( & V_11 -> V_14 , V_13 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_25 * V_30 = F_18 ( V_4 -> V_22 ) ;
struct V_10 * V_11 = F_12 ( V_2 ) ;
unsigned long V_13 ;
F_8 ( & V_11 -> V_14 , V_13 ) ;
if ( V_4 -> V_50 > 0 )
F_36 ( V_30 -> V_66 , L_1 , V_4 -> V_50 ) ;
if ( V_4 -> V_52 > 0 )
F_36 ( V_30 -> V_66 , L_2 , V_4 -> V_52 ) ;
F_34 ( V_4 , V_67 , V_2 , V_4 ) ;
V_4 -> V_22 = NULL ;
V_4 -> V_57 = 0 ;
V_4 -> V_59 = 0 ;
V_4 -> V_60 = 0 ;
V_4 -> V_62 = 0 ;
V_4 -> V_63 = 0 ;
V_4 -> V_64 = 0 ;
V_4 -> V_50 = 0 ;
V_4 -> V_52 = 0 ;
F_9 ( & V_11 -> V_14 , V_13 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
if ( ! V_2 )
return - V_68 ;
return F_34 ( V_4 , V_69 , V_2 , V_4 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_70 * V_66 )
{
struct V_3 * V_4 ;
int V_71 , V_72 ;
V_4 = & V_2 -> V_5 ;
V_71 = F_34 ( V_4 , V_73 , V_2 , V_4 , V_66 ) ;
V_4 = & V_2 -> V_53 ;
V_72 = F_34 ( V_4 , V_73 , V_2 , V_4 , V_66 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_71 , V_72 ;
V_4 = & V_2 -> V_5 ;
V_71 = F_34 ( V_4 , remove , V_2 , V_4 ) ;
V_4 = & V_2 -> V_53 ;
V_72 = F_34 ( V_4 , remove , V_2 , V_4 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_72 < 0 )
return V_72 ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_74 , struct V_70 * V_66 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
int V_34 = F_1 ( V_2 , V_4 ) ;
T_1 V_75 = V_2 -> V_75 ;
if ( F_11 ( V_11 ) >= 2 ) {
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
if ( V_34 )
F_28 ( V_2 , V_85 , V_76 ) ;
else
F_28 ( V_2 , V_86 , V_76 ) ;
}
if ( V_34 )
F_28 ( V_2 , V_87 , V_75 ) ;
else
F_28 ( V_2 , V_88 , V_75 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_7 = F_43 ( 1 , F_22 ( V_2 , V_4 ) ) ;
struct V_10 * V_11 = F_12 ( V_2 ) ;
F_44 ( V_11 , V_89 , V_7 , V_7 ) ;
F_44 ( V_11 , V_90 , V_7 , V_7 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_7 = F_43 ( 1 , F_22 ( V_2 , V_4 ) ) ;
struct V_10 * V_11 = F_12 ( V_2 ) ;
F_44 ( V_11 , V_89 , V_7 , 0 ) ;
F_44 ( V_11 , V_90 , V_7 , 0 ) ;
}
static T_1 F_46 ( struct V_10 * V_11 )
{
return F_47 ( V_11 , V_91 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_1 V_7 = 0 ;
struct V_10 * V_11 = F_12 ( V_2 ) ;
V_7 |= F_43 ( 1 , F_22 ( V_2 , & V_2 -> V_5 ) ) ;
V_7 |= F_43 ( 1 , F_22 ( V_2 , & V_2 -> V_53 ) ) ;
F_44 ( V_11 , V_91 , V_7 , 0 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_92 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
T_1 V_8 , V_9 ;
V_8 = V_93 | V_94 ;
V_9 = V_92 ? V_8 : 0 ;
F_14 ( V_2 ) ?
F_44 ( V_11 , V_95 , V_8 , V_9 ) :
F_44 ( V_11 , V_96 , V_8 , V_9 ) ;
}
static int F_50 ( struct V_70 * V_66 ,
struct V_1 * V_2 ,
int V_97 ,
int V_98 ,
int div ,
int (* F_51)( struct V_70 * V_66 ,
struct V_1 * V_2 ) )
{
struct V_99 * clock = & V_2 -> clock ;
int V_35 = F_14 ( V_2 ) ;
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
clock -> V_97 = F_52 ( V_66 , V_35 ? L_6 : L_7 ) ;
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
clock -> V_98 = F_52 ( V_66 , V_35 ? L_10 : L_11 ) ;
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
clock -> div = F_52 ( V_66 , V_35 ? L_14 : L_15 ) ;
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
static void F_54 ( struct V_1 * V_2 , unsigned long V_100 )
{
V_2 -> clock . V_100 = V_100 ;
}
static int F_55 ( struct V_1 * V_2 )
{
return V_2 -> clock . F_51 &&
V_2 -> clock . V_100 ;
}
static int F_56 ( struct V_70 * V_66 ,
struct V_1 * V_2 )
{
struct V_99 * clock = & V_2 -> clock ;
int V_12 = - V_103 ;
if ( ! F_55 ( V_2 ) )
return V_12 ;
if ( 0 == clock -> V_101 ) {
V_12 = clock -> F_51 ( V_66 , V_2 ) ;
if ( V_12 < 0 ) {
F_57 ( V_2 ) ;
return V_12 ;
}
F_58 ( clock -> V_97 ) ;
F_58 ( clock -> V_98 ) ;
F_58 ( clock -> div ) ;
clock -> V_101 ++ ;
}
return V_12 ;
}
static int F_59 ( struct V_70 * V_66 ,
struct V_1 * V_2 )
{
struct V_99 * clock = & V_2 -> clock ;
if ( ! F_55 ( V_2 ) )
return - V_103 ;
if ( 1 == clock -> V_101 -- ) {
F_60 ( clock -> V_97 ) ;
F_60 ( clock -> V_98 ) ;
F_60 ( clock -> div ) ;
}
return 0 ;
}
static int F_61 ( struct V_70 * V_66 ,
struct V_1 * V_2 ,
int V_104 , int V_105 )
{
T_1 V_7 = 0 ;
if ( V_105 > V_104 ) {
F_36 ( V_66 , L_18 , V_104 , V_105 ) ;
return - V_103 ;
}
switch ( V_104 ) {
case 512 :
V_7 |= ( 0x0 << 12 ) ;
break;
case 256 :
V_7 |= ( 0x1 << 12 ) ;
break;
case 128 :
V_7 |= ( 0x2 << 12 ) ;
break;
case 64 :
V_7 |= ( 0x3 << 12 ) ;
break;
case 32 :
V_7 |= ( 0x4 << 12 ) ;
break;
default:
F_36 ( V_66 , L_19 , V_104 ) ;
return - V_103 ;
}
switch ( V_105 ) {
case 32 :
V_7 |= ( 0x0 << 8 ) ;
break;
case 64 :
V_7 |= ( 0x1 << 8 ) ;
break;
case 128 :
V_7 |= ( 0x2 << 8 ) ;
break;
case 256 :
V_7 |= ( 0x3 << 8 ) ;
break;
case 512 :
V_7 |= ( 0x4 << 8 ) ;
break;
case 16 :
V_7 |= ( 0x7 << 8 ) ;
break;
default:
F_36 ( V_66 , L_20 , V_105 ) ;
return - V_103 ;
}
F_41 ( V_66 , L_21 , V_104 , V_105 ) ;
F_62 ( V_2 , V_106 , ( V_107 | V_108 ) , V_7 ) ;
F_63 ( 10 ) ;
return 0 ;
}
static int F_64 ( struct V_70 * V_66 ,
struct V_1 * V_2 )
{
struct V_109 * V_97 = V_2 -> clock . V_97 ;
struct V_109 * V_98 = V_2 -> clock . V_98 ;
unsigned long V_100 = V_2 -> clock . V_100 ;
unsigned long V_110 ;
int V_104 , V_105 ;
int V_12 = 0 ;
V_110 = F_65 ( V_97 ) ;
if ( V_110 % V_100 ) {
F_36 ( V_66 , L_22 ) ;
return - V_103 ;
}
F_66 ( V_98 , V_97 ) ;
F_67 ( V_98 , V_110 ) ;
V_105 = V_2 -> V_42 * 32 ;
V_104 = V_110 / V_100 ;
F_41 ( V_66 , L_23 , V_110 , V_100 ) ;
V_12 = F_61 ( V_66 , V_2 , V_104 , V_105 ) ;
if ( V_12 < 0 )
F_36 ( V_66 , L_24 , V_111 ) ;
return V_12 ;
}
static int F_68 ( struct V_70 * V_66 ,
struct V_1 * V_2 )
{
struct V_109 * V_98 = V_2 -> clock . V_98 ;
struct V_109 * div = V_2 -> clock . div ;
unsigned long V_100 = V_2 -> clock . V_100 ;
unsigned long V_112 = 0 ;
unsigned long V_113 , V_114 ;
unsigned long V_115 , V_116 ;
unsigned long V_117 , V_118 ;
int V_119 ;
int V_104 , V_105 ;
int V_12 = - V_103 ;
if ( ! ( 12288000 % V_100 ) )
V_112 = 12288000 ;
if ( ! ( 11289600 % V_100 ) )
V_112 = 11289600 ;
if ( ! V_112 ) {
F_36 ( V_66 , L_25 ) ;
return V_12 ;
}
V_105 = V_2 -> V_42 * 32 ;
V_104 = V_112 / V_100 ;
V_12 = F_61 ( V_66 , V_2 , V_104 , V_105 ) ;
if ( V_12 < 0 ) {
F_36 ( V_66 , L_24 , V_111 ) ;
return V_12 ;
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
V_12 = F_67 ( V_98 , V_117 ) ;
if ( V_12 < 0 ) {
F_36 ( V_66 , L_26 ) ;
return - V_68 ;
}
V_12 = F_67 ( div , F_69 ( div , V_118 ) ) ;
if ( V_12 < 0 ) {
F_36 ( V_66 , L_27 ) ;
return - V_68 ;
}
F_41 ( V_66 , L_28 ,
F_65 ( V_98 ) , F_65 ( div ) ) ;
return V_12 ;
}
static void F_70 ( struct V_3 * V_4 , int V_120 )
{
V_4 -> V_59 += V_120 ;
if ( V_4 -> V_59 >=
V_4 -> V_60 * ( V_4 -> V_62 + 1 ) ) {
struct V_21 * V_22 = V_4 -> V_22 ;
struct V_56 * V_54 = V_22 -> V_54 ;
V_4 -> V_62 ++ ;
if ( V_4 -> V_62 >= V_54 -> V_121 ) {
V_4 -> V_59 = 0 ;
V_4 -> V_62 = 0 ;
}
F_71 ( V_22 ) ;
}
}
static void F_72 ( struct V_1 * V_2 , T_3 * V_122 , int V_43 )
{
int V_123 ;
if ( F_16 ( V_2 ) ) {
T_1 * V_124 = ( T_1 * ) V_122 ;
for ( V_123 = 0 ; V_123 < V_43 / 2 ; V_123 ++ )
F_28 ( V_2 , V_125 , V_124 [ V_123 ] ) ;
} else {
T_4 * V_124 = ( T_4 * ) V_122 ;
for ( V_123 = 0 ; V_123 < V_43 ; V_123 ++ )
F_28 ( V_2 , V_125 , ( ( T_1 ) * ( V_124 + V_123 ) << 8 ) ) ;
}
}
static void F_73 ( struct V_1 * V_2 , T_3 * V_122 , int V_43 )
{
T_4 * V_124 = ( T_4 * ) V_122 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_43 ; V_123 ++ )
* ( V_124 + V_123 ) = ( T_4 ) ( F_26 ( V_2 , V_126 ) >> 8 ) ;
}
static void F_74 ( struct V_1 * V_2 , T_3 * V_122 , int V_43 )
{
T_1 * V_124 = ( T_1 * ) V_122 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_43 ; V_123 ++ )
F_28 ( V_2 , V_125 , * ( V_124 + V_123 ) ) ;
}
static void F_75 ( struct V_1 * V_2 , T_3 * V_122 , int V_43 )
{
T_1 * V_124 = ( T_1 * ) V_122 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_43 ; V_123 ++ )
* ( V_124 + V_123 ) = F_26 ( V_2 , V_126 ) ;
}
static T_3 * F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_56 * V_54 = V_4 -> V_22 -> V_54 ;
return V_54 -> V_127 +
F_33 ( V_54 , V_4 -> V_59 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void (* F_78)( struct V_1 * V_2 , T_3 * V_124 , int V_43 ) ,
void (* F_79)( struct V_1 * V_2 , T_3 * V_124 , int V_43 ) ,
int V_43 )
{
T_3 * V_124 ;
if ( ! F_30 ( V_2 , V_4 ) )
return - V_103 ;
V_124 = F_76 ( V_2 , V_4 ) ;
switch ( V_4 -> V_63 ) {
case 2 :
F_78 ( V_2 , V_124 , V_43 ) ;
break;
case 4 :
F_79 ( V_2 , V_124 , V_43 ) ;
break;
default:
return - V_103 ;
}
F_70 ( V_4 , V_43 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_128 ;
int V_129 ;
int V_43 ;
V_128 = F_25 ( V_2 , V_4 ) ;
V_129 = V_4 -> V_57 - V_4 -> V_59 ;
V_43 = V_116 ( V_128 , V_129 ) ;
return F_77 ( V_2 , V_4 ,
F_73 ,
F_75 ,
V_43 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_128 ;
int V_129 ;
int V_43 ;
V_128 = V_4 -> V_57 - V_4 -> V_59 ;
V_129 = V_4 -> V_130 -
F_25 ( V_2 , V_4 ) ;
V_43 = V_116 ( V_128 , V_129 ) ;
return F_77 ( V_2 , V_4 ,
F_72 ,
F_74 ,
V_43 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_92 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
T_1 V_109 = F_14 ( V_2 ) ? V_131 : V_132 ;
if ( V_92 )
F_42 ( V_2 , V_4 ) ;
else
F_45 ( V_2 , V_4 ) ;
if ( F_13 ( V_2 ) )
F_83 ( V_11 , V_133 , V_109 , ( V_92 ) ? V_109 : 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_16 ( V_2 ) )
V_4 -> V_64 = F_85 ( 24 , V_83 ) |
F_85 ( 16 , V_80 ) ;
else
V_4 -> V_64 = F_85 ( 24 , V_83 ) |
F_85 ( 16 , V_83 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_64 = F_85 ( 24 , V_83 ) |
F_85 ( 16 , V_83 ) ;
return 0 ;
}
static T_5 F_87 ( int V_134 , void * V_7 )
{
struct V_10 * V_11 = V_7 ;
T_1 V_91 = F_46 ( V_11 ) ;
F_83 ( V_11 , V_135 , V_136 , 0 ) ;
F_83 ( V_11 , V_135 , V_136 , V_136 ) ;
if ( V_91 & F_43 ( 1 , V_37 ) )
F_37 ( & V_11 -> V_32 . V_5 ) ;
if ( V_91 & F_43 ( 1 , V_39 ) )
F_37 ( & V_11 -> V_33 . V_5 ) ;
if ( V_91 & F_43 ( 1 , V_38 ) )
F_37 ( & V_11 -> V_32 . V_53 ) ;
if ( V_91 & F_43 ( 1 , V_40 ) )
F_37 ( & V_11 -> V_33 . V_53 ) ;
F_27 ( & V_11 -> V_32 ) ;
F_27 ( & V_11 -> V_33 ) ;
F_48 ( & V_11 -> V_32 ) ;
F_48 ( & V_11 -> V_33 ) ;
return V_137 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_64 = F_85 ( 24 , V_83 ) |
F_85 ( 16 , V_80 ) ;
return 0 ;
}
static void F_89 ( void * V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_7 ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
F_70 ( V_4 , V_4 -> V_60 ) ;
F_27 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_25 * V_30 = F_18 ( V_4 -> V_22 ) ;
struct V_21 * V_22 = V_4 -> V_22 ;
struct V_138 * V_139 ;
int V_34 = F_1 ( V_2 , V_4 ) ;
enum V_140 V_141 ;
int V_12 = - V_68 ;
if ( V_34 )
V_141 = V_142 ;
else
V_141 = V_143 ;
V_139 = F_91 ( V_4 -> V_144 ,
V_22 -> V_54 -> V_145 ,
F_92 ( V_22 ) ,
F_93 ( V_22 ) ,
V_141 ,
V_146 | V_147 ) ;
if ( ! V_139 ) {
F_36 ( V_30 -> V_66 , L_29 ) ;
goto V_148;
}
V_139 -> V_149 = F_89 ;
V_139 -> V_150 = V_4 ;
if ( F_94 ( V_139 ) < 0 ) {
F_36 ( V_30 -> V_66 , L_30 ) ;
goto V_148;
}
F_95 ( V_4 -> V_144 ) ;
if ( ! V_34 ) {
if ( V_49 & F_26 ( V_2 , V_46 ) ) {
F_62 ( V_2 , V_151 , V_152 , V_152 ) ;
F_28 ( V_2 , V_46 , 0 ) ;
}
}
V_12 = 0 ;
V_148:
return V_12 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_153 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
T_1 V_109 = F_14 ( V_2 ) ? V_131 : V_132 ;
T_1 V_92 = V_153 ? V_154 : 0 ;
F_62 ( V_2 , V_85 , V_154 , V_92 ) ;
F_97 ( V_4 -> V_144 ) ;
if ( F_13 ( V_2 ) )
F_83 ( V_11 , V_133 , V_109 , ( V_92 ) ? V_109 : 0 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_70 * V_66 )
{
int V_34 = F_1 ( V_2 , V_4 ) ;
#ifdef F_99
T_6 V_8 ;
F_100 ( V_8 ) ;
F_101 ( V_155 , V_8 ) ;
V_4 -> V_144 = F_102 ( V_8 , V_156 ,
( void * ) V_4 -> V_157 ) ;
#else
V_4 -> V_144 = F_103 ( V_66 , V_34 ? L_31 : L_32 ) ;
#endif
if ( V_4 -> V_144 ) {
struct V_158 V_159 = {} ;
int V_12 ;
if ( V_34 ) {
V_159 . V_160 = V_2 -> V_161 + V_162 ;
V_159 . V_163 = V_164 ;
V_159 . V_165 = V_142 ;
} else {
V_159 . V_166 = V_2 -> V_161 + V_167 ;
V_159 . V_168 = V_164 ;
V_159 . V_165 = V_143 ;
}
V_12 = F_104 ( V_4 -> V_144 , & V_159 ) ;
if ( V_12 < 0 ) {
F_105 ( V_4 -> V_144 ) ;
V_4 -> V_144 = NULL ;
}
}
if ( ! V_4 -> V_144 ) {
if ( V_34 )
V_2 -> V_5 . V_169 = & V_170 ;
else
V_2 -> V_53 . V_169 = & V_171 ;
F_106 ( V_66 , L_33 ) ;
return F_38 ( V_2 , V_66 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_108 ( V_2 , V_4 ) ;
if ( V_4 -> V_144 )
F_105 ( V_4 -> V_144 ) ;
V_4 -> V_144 = NULL ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_66 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
int V_34 = F_1 ( V_2 , V_4 ) ;
T_1 V_36 , V_123 ;
int V_172 ;
V_36 = F_110 ( V_11 , V_173 ) ;
V_36 >>= F_22 ( V_2 , V_4 ) ;
V_36 &= V_174 ;
V_172 = 256 << V_36 ;
F_41 ( V_66 , L_34 , V_172 ) ;
for ( V_123 = 1 ; V_123 < V_2 -> V_42 ; V_123 <<= 1 )
V_172 >>= 1 ;
F_41 ( V_66 , L_35 ,
V_2 -> V_42 , V_172 ) ;
V_4 -> V_130 = F_23 ( V_2 , V_172 ) ;
if ( V_34 ) {
F_28 ( V_2 , V_175 , V_176 ) ;
F_62 ( V_2 , V_175 , V_152 , V_152 ) ;
} else {
F_28 ( V_2 , V_151 , V_176 ) ;
F_62 ( V_2 , V_151 , V_152 , V_152 ) ;
}
}
static int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_66 )
{
T_1 V_7 = 0 ;
if ( F_13 ( V_2 ) )
V_7 = V_177 | V_178 ;
F_62 ( V_2 , V_106 , ( V_177 | V_178 ) , V_7 ) ;
V_7 = 0 ;
if ( V_2 -> V_179 )
V_7 |= ( 1 << 0 ) ;
if ( V_2 -> V_180 )
V_7 |= ( 1 << 4 ) ;
if ( F_13 ( V_2 ) )
V_7 <<= 8 ;
F_28 ( V_2 , V_181 , V_7 ) ;
if ( F_15 ( V_2 ) ) {
F_49 ( V_2 , 1 ) ;
F_62 ( V_2 , V_182 , V_183 , V_183 ) ;
}
V_7 = 0 ;
switch ( V_4 -> V_63 ) {
case 2 :
V_7 = F_112 ( 16 , V_4 -> V_64 ) ;
break;
case 4 :
V_7 = F_112 ( 24 , V_4 -> V_64 ) ;
break;
}
F_40 ( V_2 , V_4 , V_7 , V_66 ) ;
F_45 ( V_2 , V_4 ) ;
F_48 ( V_2 ) ;
F_109 ( V_2 , V_4 , V_66 ) ;
if ( F_13 ( V_2 ) )
return F_56 ( V_66 , V_2 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_70 * V_66 )
{
if ( F_13 ( V_2 ) )
return F_59 ( V_66 , V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_21 * V_22 ,
struct V_25 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static void F_115 ( struct V_21 * V_22 ,
struct V_25 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
F_57 ( V_2 ) ;
}
static int F_116 ( struct V_21 * V_22 , int V_184 ,
struct V_25 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_3 * V_4 = F_29 ( V_2 , V_22 ) ;
int V_12 = 0 ;
switch ( V_184 ) {
case V_185 :
F_32 ( V_2 , V_4 , V_22 ) ;
if ( ! V_12 )
V_12 = F_111 ( V_2 , V_4 , V_30 -> V_66 ) ;
if ( ! V_12 )
V_12 = F_117 ( V_2 , V_4 ) ;
if ( ! V_12 )
V_12 = F_37 ( V_4 ) ;
break;
case V_186 :
if ( ! V_12 )
V_12 = F_113 ( V_2 , V_30 -> V_66 ) ;
F_108 ( V_2 , V_4 ) ;
F_35 ( V_2 , V_4 ) ;
break;
}
return V_12 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned int V_75 )
{
switch ( V_75 & V_187 ) {
case V_188 :
V_2 -> V_75 = V_189 ;
V_2 -> V_42 = 2 ;
break;
case V_190 :
V_2 -> V_75 = V_191 ;
V_2 -> V_42 = 2 ;
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_12 ( V_2 ) ;
if ( F_11 ( V_11 ) < 2 )
return - V_103 ;
V_2 -> V_75 = V_192 | V_191 ;
V_2 -> V_42 = 2 ;
return 0 ;
}
static int F_120 ( struct V_25 * V_30 , unsigned int V_75 )
{
struct V_1 * V_2 = F_19 ( V_30 ) ;
int V_12 ;
switch ( V_75 & V_193 ) {
case V_194 :
break;
case V_195 :
V_2 -> V_18 = 1 ;
break;
default:
return - V_103 ;
}
switch ( V_75 & V_196 ) {
case V_197 :
V_2 -> V_179 = 0 ;
V_2 -> V_180 = 1 ;
break;
case V_198 :
V_2 -> V_179 = 1 ;
V_2 -> V_180 = 0 ;
break;
case V_199 :
V_2 -> V_179 = 1 ;
V_2 -> V_180 = 1 ;
break;
case V_200 :
default:
V_2 -> V_179 = 0 ;
V_2 -> V_180 = 0 ;
break;
}
if ( F_13 ( V_2 ) ) {
if ( V_2 -> V_201 )
F_50 ( V_30 -> V_66 , V_2 , 0 , 1 , 1 ,
F_68 ) ;
else
F_50 ( V_30 -> V_66 , V_2 , 1 , 1 , 0 ,
F_64 ) ;
}
if ( F_15 ( V_2 ) )
V_12 = F_119 ( V_2 ) ;
else
V_12 = F_118 ( V_2 , V_75 & V_187 ) ;
return V_12 ;
}
static int F_121 ( struct V_21 * V_22 ,
struct V_202 * V_203 ,
struct V_25 * V_30 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
if ( F_13 ( V_2 ) )
F_54 ( V_2 , F_122 ( V_203 ) ) ;
return 0 ;
}
static int F_123 ( struct V_21 * V_22 )
{
struct V_56 * V_54 = V_22 -> V_54 ;
int V_12 = 0 ;
F_124 ( V_22 , & V_204 ) ;
V_12 = F_125 ( V_54 ,
V_205 ) ;
return V_12 ;
}
static int F_126 ( struct V_21 * V_22 ,
struct V_202 * V_206 )
{
return F_127 ( V_22 ,
F_128 ( V_206 ) ) ;
}
static int F_129 ( struct V_21 * V_22 )
{
return F_130 ( V_22 ) ;
}
static T_7 F_131 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
struct V_3 * V_4 = F_29 ( V_2 , V_22 ) ;
return F_24 ( V_2 , V_4 -> V_59 ) ;
}
static int F_132 ( struct V_26 * V_27 )
{
return F_133 (
V_27 -> V_207 ,
V_208 ,
V_27 -> V_209 -> V_210 -> V_66 ,
V_211 , V_212 ) ;
}
static void F_134 ( char * V_213 ,
struct V_214 * V_215 ,
struct V_216 * V_217 ,
struct V_70 * V_66 )
{
int V_123 ;
char V_218 [ 128 ] ;
unsigned long V_13 = 0 ;
struct {
char * V_213 ;
unsigned int V_9 ;
} V_219 [] = {
{ L_36 , V_220 } ,
{ L_37 , V_221 } ,
{ L_38 , V_222 } ,
} ;
for ( V_123 = 0 ; V_123 < F_135 ( V_219 ) ; V_123 ++ ) {
sprintf ( V_218 , L_39 , V_213 , V_219 [ V_123 ] . V_213 ) ;
if ( F_136 ( V_215 , V_218 , NULL ) )
V_13 |= V_219 [ V_123 ] . V_9 ;
}
V_217 -> V_13 = V_13 ;
F_41 ( V_66 , L_40 , V_213 , V_217 -> V_13 ) ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
if ( V_217 -> V_13 & V_220 )
V_2 -> V_19 = 1 ;
if ( V_217 -> V_13 & V_222 )
V_2 -> V_201 = 1 ;
if ( V_217 -> V_13 & V_221 )
V_2 -> V_20 = 1 ;
}
static void F_138 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
V_2 -> V_5 . V_169 = & V_170 ;
V_2 -> V_5 . V_55 = V_2 ;
V_2 -> V_53 . V_169 = & V_171 ;
V_2 -> V_53 . V_55 = V_2 ;
if ( V_217 -> V_223 ) {
V_2 -> V_5 . V_157 = V_217 -> V_223 ;
V_2 -> V_5 . V_169 = & V_224 ;
}
}
static int F_139 ( struct V_225 * V_226 )
{
struct V_10 * V_11 ;
struct V_214 * V_215 = V_226 -> V_66 . V_227 ;
struct V_228 V_217 ;
const struct V_229 * V_16 ;
struct V_1 * V_2 ;
struct V_230 * V_231 ;
unsigned int V_134 ;
int V_12 ;
memset ( & V_217 , 0 , sizeof( V_217 ) ) ;
V_16 = NULL ;
if ( V_215 ) {
const struct V_232 * V_233 ;
V_233 = F_140 ( V_234 , & V_226 -> V_66 ) ;
if ( V_233 ) {
V_16 = V_233 -> V_7 ;
F_134 ( L_41 , V_215 , & V_217 . V_235 , & V_226 -> V_66 ) ;
F_134 ( L_42 , V_215 , & V_217 . V_236 , & V_226 -> V_66 ) ;
}
} else {
const struct V_237 * V_238 = V_226 -> V_238 ;
if ( V_238 )
V_16 = (struct V_229 * ) V_238 -> V_239 ;
if ( V_226 -> V_66 . V_240 )
memcpy ( & V_217 , V_226 -> V_66 . V_240 , sizeof( V_217 ) ) ;
}
if ( ! V_16 ) {
F_36 ( & V_226 -> V_66 , L_43 ) ;
return - V_241 ;
}
V_231 = F_141 ( V_226 , V_242 , 0 ) ;
V_134 = F_142 ( V_226 , 0 ) ;
if ( ! V_231 || ( int ) V_134 <= 0 ) {
F_36 ( & V_226 -> V_66 , L_44 ) ;
return - V_241 ;
}
V_11 = F_143 ( & V_226 -> V_66 , sizeof( * V_11 ) , V_243 ) ;
if ( ! V_11 ) {
F_36 ( & V_226 -> V_66 , L_45 ) ;
return - V_244 ;
}
V_11 -> V_15 = F_144 ( & V_226 -> V_66 ,
V_231 -> V_153 , F_145 ( V_231 ) ) ;
if ( ! V_11 -> V_15 ) {
F_36 ( & V_226 -> V_66 , L_46 ) ;
return - V_245 ;
}
V_11 -> V_16 = V_16 ;
F_146 ( & V_11 -> V_14 ) ;
V_2 = & V_11 -> V_32 ;
V_2 -> V_15 = V_11 -> V_15 ;
V_2 -> V_161 = V_231 -> V_153 ;
V_2 -> V_11 = V_11 ;
F_137 ( V_2 , & V_217 . V_235 ) ;
F_138 ( V_2 , & V_217 . V_235 ) ;
V_12 = F_38 ( V_2 , & V_226 -> V_66 ) ;
if ( V_12 < 0 ) {
F_36 ( & V_226 -> V_66 , L_47 ) ;
return V_12 ;
}
V_2 = & V_11 -> V_33 ;
V_2 -> V_15 = V_11 -> V_15 + 0x40 ;
V_2 -> V_161 = V_231 -> V_153 + 0x40 ;
V_2 -> V_11 = V_11 ;
F_137 ( V_2 , & V_217 . V_236 ) ;
F_138 ( V_2 , & V_217 . V_236 ) ;
V_12 = F_38 ( V_2 , & V_226 -> V_66 ) ;
if ( V_12 < 0 ) {
F_36 ( & V_226 -> V_66 , L_48 ) ;
goto V_246;
}
F_147 ( & V_226 -> V_66 ) ;
F_148 ( & V_226 -> V_66 , V_11 ) ;
V_12 = F_149 ( & V_226 -> V_66 , V_134 , & F_87 , 0 ,
F_150 ( & V_226 -> V_66 ) , V_11 ) ;
if ( V_12 ) {
F_36 ( & V_226 -> V_66 , L_49 ) ;
goto V_247;
}
V_12 = F_151 ( & V_226 -> V_66 , & V_248 ) ;
if ( V_12 < 0 ) {
F_36 ( & V_226 -> V_66 , L_50 ) ;
goto V_247;
}
V_12 = F_152 ( & V_226 -> V_66 , & V_249 ,
V_250 , F_135 ( V_250 ) ) ;
if ( V_12 < 0 ) {
F_36 ( & V_226 -> V_66 , L_51 ) ;
goto V_251;
}
return V_12 ;
V_251:
F_153 ( & V_226 -> V_66 ) ;
V_247:
F_154 ( & V_226 -> V_66 ) ;
F_39 ( & V_11 -> V_33 ) ;
V_246:
F_39 ( & V_11 -> V_32 ) ;
return V_12 ;
}
static int F_155 ( struct V_225 * V_226 )
{
struct V_10 * V_11 ;
V_11 = F_156 ( & V_226 -> V_66 ) ;
F_154 ( & V_226 -> V_66 ) ;
F_157 ( & V_226 -> V_66 ) ;
F_153 ( & V_226 -> V_66 ) ;
F_39 ( & V_11 -> V_32 ) ;
F_39 ( & V_11 -> V_33 ) ;
return 0 ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_66 )
{
if ( ! F_30 ( V_2 , V_4 ) )
return;
F_108 ( V_2 , V_4 ) ;
F_113 ( V_2 , V_66 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_66 )
{
if ( ! F_30 ( V_2 , V_4 ) )
return;
F_111 ( V_2 , V_4 , V_66 ) ;
F_117 ( V_2 , V_4 ) ;
}
static int F_160 ( struct V_70 * V_66 )
{
struct V_10 * V_11 = F_156 ( V_66 ) ;
struct V_1 * V_32 = & V_11 -> V_32 ;
struct V_1 * V_33 = & V_11 -> V_33 ;
F_158 ( V_32 , & V_32 -> V_5 , V_66 ) ;
F_158 ( V_32 , & V_32 -> V_53 , V_66 ) ;
F_158 ( V_33 , & V_33 -> V_5 , V_66 ) ;
F_158 ( V_33 , & V_33 -> V_53 , V_66 ) ;
return 0 ;
}
static int F_161 ( struct V_70 * V_66 )
{
struct V_10 * V_11 = F_156 ( V_66 ) ;
struct V_1 * V_32 = & V_11 -> V_32 ;
struct V_1 * V_33 = & V_11 -> V_33 ;
F_159 ( V_32 , & V_32 -> V_5 , V_66 ) ;
F_159 ( V_32 , & V_32 -> V_53 , V_66 ) ;
F_159 ( V_33 , & V_33 -> V_5 , V_66 ) ;
F_159 ( V_33 , & V_33 -> V_53 , V_66 ) ;
return 0 ;
}
