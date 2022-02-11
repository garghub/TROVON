static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_3 . V_5 , struct V_1 ,
V_6 ) ;
}
static struct V_2 * F_3 ( struct V_7 * V_8 )
{
return F_2 ( V_8 , struct V_2 , V_4 . V_3 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
return F_2 ( V_11 , struct V_9 , V_11 ) ;
}
static struct V_5 * F_5 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 . V_3 . V_12 -> V_5 ;
}
static T_1 F_6 ( struct V_1 * V_13 , T_1 V_14 )
{
return F_7 ( V_13 -> V_15 + V_14 ) ;
}
static void F_8 ( struct V_1 * V_13 , T_1 V_14 , T_1 V_16 )
{
F_9 ( V_16 , V_13 -> V_15 + V_14 ) ;
}
static struct V_9 * F_10 ( T_1 V_17 )
{
return F_11 ( sizeof( struct V_9 ) +
sizeof( struct V_18 ) * V_17 , V_19 ) ;
}
static int F_12 ( struct V_2 * V_3 ,
enum V_20 V_21 )
{
switch ( V_21 ) {
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
default:
F_13 ( F_5 ( V_3 ) , L_1 ) ;
return - V_28 ;
}
}
static int F_14 ( struct V_2 * V_3 , T_1 V_29 )
{
switch ( V_29 ) {
case 0 :
case 1 :
return V_30 ;
case 4 :
return V_31 ;
case 8 :
return V_32 ;
case 16 :
return V_33 ;
default:
F_13 ( F_5 ( V_3 ) , L_2 ) ;
return - V_28 ;
}
}
static void F_15 ( struct V_2 * V_3 ,
T_1 V_34 , T_1 V_35 )
{
V_3 -> V_36 . V_37 &= ~ V_38 ;
V_3 -> V_36 . V_39 &= ~ V_40 ;
if ( ( ! V_34 ) && ( ! V_35 ) ) {
V_3 -> V_36 . V_39 |= V_40 ;
} else {
V_3 -> V_36 . V_37 |= V_38 ;
}
}
static int F_16 ( struct V_7 * V_8 ,
struct V_41 * V_42 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
memcpy ( & V_3 -> V_43 , V_42 , sizeof( * V_42 ) ) ;
V_3 -> V_44 = true ;
return 0 ;
}
static T_1 F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_45 , V_46 ;
if ( V_3 -> V_47 & 4 )
V_46 = F_6 ( V_13 , V_48 ) ;
else
V_46 = F_6 ( V_13 , V_49 ) ;
V_45 = V_46 >> ( ( ( V_3 -> V_47 & 2 ) << 3 ) | ( ( V_3 -> V_47 & 1 ) * 6 ) ) ;
return V_45 ;
}
static void F_18 ( struct V_2 * V_3 , T_1 V_45 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_50 ;
V_50 = V_45 << ( ( ( V_3 -> V_47 & 2 ) << 3 ) | ( ( V_3 -> V_47 & 1 ) * 6 ) ) ;
if ( V_3 -> V_47 & 4 )
F_8 ( V_13 , V_51 , V_50 ) ;
else
F_8 ( V_13 , V_52 , V_50 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_53 = V_54 + F_20 ( 5000 ) ;
T_1 V_39 , V_47 ;
V_47 = V_3 -> V_47 ;
V_39 = F_6 ( V_13 , F_21 ( V_47 ) ) ;
if ( V_39 & V_55 ) {
V_39 &= ~ V_55 ;
F_8 ( V_13 , F_21 ( V_47 ) , V_39 ) ;
do {
V_39 = F_6 ( V_13 , F_21 ( V_47 ) ) ;
V_39 &= V_55 ;
if ( ! V_39 )
break;
if ( F_22 ( V_54 , V_53 ) ) {
F_13 ( F_5 ( V_3 ) , L_3 ,
V_56 ) ;
return - V_57 ;
}
F_23 () ;
} while ( 1 );
}
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_39 , V_37 , V_58 ;
int V_59 ;
V_39 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
V_39 &= ~ V_60 ;
F_8 ( V_13 , F_21 ( V_3 -> V_47 ) , V_39 ) ;
V_37 = F_6 ( V_13 , F_25 ( V_3 -> V_47 ) ) ;
V_37 &= ~ V_61 ;
F_8 ( V_13 , F_25 ( V_3 -> V_47 ) , V_37 ) ;
V_59 = F_19 ( V_3 ) ;
if ( V_59 < 0 )
return;
V_58 = F_17 ( V_3 ) ;
if ( V_58 ) {
F_26 ( F_5 ( V_3 ) , L_4 ,
V_56 , V_58 ) ;
F_18 ( V_3 , V_58 ) ;
}
V_3 -> V_62 = false ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
unsigned long V_45 ;
F_28 ( V_63 ) ;
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
if ( V_3 -> V_62 ) {
F_24 ( V_3 ) ;
V_3 -> V_65 = NULL ;
}
F_30 ( & V_3 -> V_4 , & V_63 ) ;
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
F_32 ( & V_3 -> V_4 , & V_63 ) ;
return 0 ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_34 ( & V_3 -> V_4 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_66 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
T_1 V_67 = F_6 ( V_13 , F_36 ( V_3 -> V_47 ) ) ;
T_1 V_68 = F_6 ( V_13 , F_37 ( V_3 -> V_47 ) ) ;
T_1 V_69 = F_6 ( V_13 , F_38 ( V_3 -> V_47 ) ) ;
T_1 V_70 = F_6 ( V_13 , F_39 ( V_3 -> V_47 ) ) ;
T_1 V_71 = F_6 ( V_13 , F_25 ( V_3 -> V_47 ) ) ;
F_26 ( F_5 ( V_3 ) , L_5 , V_66 ) ;
F_26 ( F_5 ( V_3 ) , L_6 , V_67 ) ;
F_26 ( F_5 ( V_3 ) , L_7 , V_68 ) ;
F_26 ( F_5 ( V_3 ) , L_8 , V_69 ) ;
F_26 ( F_5 ( V_3 ) , L_9 , V_70 ) ;
F_26 ( F_5 ( V_3 ) , L_10 , V_71 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 ;
struct V_18 * V_72 ;
struct V_73 * V_14 ;
T_1 V_58 ;
int V_59 ;
V_59 = F_19 ( V_3 ) ;
if ( V_59 < 0 )
return;
if ( ! V_3 -> V_65 ) {
V_11 = F_41 ( & V_3 -> V_4 ) ;
if ( ! V_11 )
return;
V_3 -> V_65 = F_4 ( V_11 ) ;
V_3 -> V_74 = 0 ;
}
if ( V_3 -> V_74 == V_3 -> V_65 -> V_17 )
V_3 -> V_74 = 0 ;
V_72 = & V_3 -> V_65 -> V_72 [ V_3 -> V_74 ] ;
V_14 = & V_72 -> V_36 ;
F_8 ( V_13 , F_21 ( V_3 -> V_47 ) , V_14 -> V_39 ) ;
F_8 ( V_13 , F_37 ( V_3 -> V_47 ) , V_14 -> V_75 ) ;
F_8 ( V_13 , F_38 ( V_3 -> V_47 ) , V_14 -> V_76 ) ;
F_8 ( V_13 , F_25 ( V_3 -> V_47 ) , V_14 -> V_37 ) ;
F_8 ( V_13 , F_39 ( V_3 -> V_47 ) , V_14 -> V_77 ) ;
F_8 ( V_13 , F_36 ( V_3 -> V_47 ) , V_14 -> V_78 ) ;
V_3 -> V_74 ++ ;
V_58 = F_17 ( V_3 ) ;
if ( V_58 )
F_18 ( V_3 , V_58 ) ;
F_35 ( V_3 ) ;
V_14 -> V_39 |= V_55 ;
F_8 ( V_13 , F_21 ( V_3 -> V_47 ) , V_14 -> V_39 ) ;
V_3 -> V_62 = true ;
F_26 ( F_5 ( V_3 ) , L_11 , & V_3 -> V_4 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_18 * V_72 ;
T_1 V_39 , V_76 , V_77 , V_47 ;
V_47 = V_3 -> V_47 ;
V_39 = F_6 ( V_13 , F_21 ( V_47 ) ) ;
if ( V_39 & V_79 ) {
if ( V_3 -> V_74 == V_3 -> V_65 -> V_17 )
V_3 -> V_74 = 0 ;
V_72 = & V_3 -> V_65 -> V_72 [ V_3 -> V_74 ] ;
if ( V_39 & V_80 ) {
V_76 = V_72 -> V_36 . V_76 ;
F_8 ( V_13 , F_38 ( V_47 ) , V_76 ) ;
F_26 ( F_5 ( V_3 ) , L_12 ,
F_6 ( V_13 , F_38 ( V_47 ) ) ) ;
} else {
V_77 = V_72 -> V_36 . V_77 ;
F_8 ( V_13 , F_39 ( V_47 ) , V_77 ) ;
F_26 ( F_5 ( V_3 ) , L_13 ,
F_6 ( V_13 , F_39 ( V_47 ) ) ) ;
}
}
}
static void F_43 ( struct V_2 * V_3 )
{
if ( V_3 -> V_65 ) {
if ( V_3 -> V_65 -> V_81 ) {
F_44 ( & V_3 -> V_65 -> V_11 ) ;
V_3 -> V_74 ++ ;
F_42 ( V_3 ) ;
} else {
V_3 -> V_62 = false ;
if ( V_3 -> V_74 == V_3 -> V_65 -> V_17 ) {
F_45 ( & V_3 -> V_65 -> V_11 . V_82 ) ;
F_46 ( & V_3 -> V_65 -> V_11 ) ;
V_3 -> V_65 = NULL ;
}
F_40 ( V_3 ) ;
}
}
}
static T_2 F_47 ( int V_83 , void * V_84 )
{
struct V_2 * V_3 = V_84 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_58 , V_66 ;
F_48 ( & V_3 -> V_4 . V_64 ) ;
V_58 = F_17 ( V_3 ) ;
V_66 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
if ( ( V_58 & V_85 ) && ( V_66 & V_86 ) ) {
F_18 ( V_3 , V_85 ) ;
F_43 ( V_3 ) ;
} else {
F_18 ( V_3 , V_58 ) ;
F_13 ( F_5 ( V_3 ) , L_14 , V_58 ) ;
}
F_49 ( & V_3 -> V_4 . V_64 ) ;
return V_87 ;
}
static void F_50 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
unsigned long V_45 ;
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
if ( F_51 ( & V_3 -> V_4 ) && ! V_3 -> V_65 && ! V_3 -> V_62 ) {
F_26 ( F_5 ( V_3 ) , L_15 , & V_3 -> V_4 ) ;
F_40 ( V_3 ) ;
if ( V_3 -> V_65 -> V_81 )
F_42 ( V_3 ) ;
}
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
enum V_88 V_89 ,
enum V_20 * V_90 )
{
enum V_20 V_91 , V_92 ;
int V_93 , V_94 ;
int V_95 , V_96 ;
T_1 V_34 , V_35 ;
T_1 V_39 = 0 ;
V_91 = V_3 -> V_43 . V_91 ;
V_92 = V_3 -> V_43 . V_92 ;
V_34 = V_3 -> V_43 . V_34 ;
V_35 = V_3 -> V_43 . V_35 ;
switch ( V_89 ) {
case V_97 :
V_94 = F_12 ( V_3 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
V_96 = F_14 ( V_3 , V_35 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! V_91 )
V_91 = V_92 ;
V_93 = F_12 ( V_3 , V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
V_95 = F_14 ( V_3 , V_34 ) ;
if ( V_95 < 0 )
return V_95 ;
V_39 = F_53 ( V_98 ) |
F_54 ( V_94 ) |
F_55 ( V_93 ) |
F_56 ( V_96 ) |
F_57 ( V_95 ) ;
V_3 -> V_36 . V_75 = V_3 -> V_43 . V_99 ;
* V_90 = V_92 ;
break;
case V_100 :
V_93 = F_12 ( V_3 , V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
V_95 = F_14 ( V_3 , V_34 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( ! V_92 )
V_92 = V_91 ;
V_94 = F_12 ( V_3 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
V_96 = F_14 ( V_3 , V_35 ) ;
if ( V_96 < 0 )
return V_96 ;
V_39 = F_53 ( V_101 ) |
F_54 ( V_93 ) |
F_55 ( V_94 ) |
F_56 ( V_95 ) |
F_57 ( V_96 ) ;
V_3 -> V_36 . V_75 = V_3 -> V_43 . V_102 ;
* V_90 = V_3 -> V_43 . V_91 ;
break;
default:
F_13 ( F_5 ( V_3 ) , L_16 ) ;
return - V_28 ;
}
F_15 ( V_3 , V_34 , V_35 ) ;
V_3 -> V_36 . V_39 &= ~ ( V_103 |
V_104 | V_105 |
V_106 | V_107 ) ;
V_3 -> V_36 . V_39 |= V_39 ;
return 0 ;
}
static void F_58 ( struct V_73 * V_108 )
{
memset ( V_108 , 0 , sizeof( struct V_73 ) ) ;
}
static struct V_109 * F_59 (
struct V_7 * V_8 , struct V_110 * V_111 ,
T_1 V_112 , enum V_88 V_89 ,
unsigned long V_45 , void * V_113 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_65 ;
struct V_110 * V_114 ;
enum V_20 V_90 ;
T_1 V_115 ;
int V_116 , V_59 ;
if ( ! V_3 -> V_44 ) {
F_13 ( F_5 ( V_3 ) , L_17 ) ;
return NULL ;
}
if ( V_112 < 1 ) {
F_13 ( F_5 ( V_3 ) , L_18 , V_112 ) ;
return NULL ;
}
V_65 = F_10 ( V_112 ) ;
if ( ! V_65 )
return NULL ;
V_59 = F_52 ( V_3 , V_89 , & V_90 ) ;
if ( V_59 < 0 )
goto V_117;
if ( V_3 -> V_43 . V_118 )
V_3 -> V_36 . V_39 |= V_119 ;
else
V_3 -> V_36 . V_39 &= ~ V_119 ;
F_60 (sgl, sg, sg_len, i) {
V_65 -> V_72 [ V_116 ] . V_120 = F_61 ( V_114 ) ;
V_115 = V_65 -> V_72 [ V_116 ] . V_120 / V_90 ;
if ( V_115 > V_121 ) {
F_13 ( F_5 ( V_3 ) , L_19 ) ;
goto V_117;
}
F_58 ( & V_65 -> V_72 [ V_116 ] . V_36 ) ;
V_65 -> V_72 [ V_116 ] . V_36 . V_39 = V_3 -> V_36 . V_39 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_37 = V_3 -> V_36 . V_37 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_75 = V_3 -> V_36 . V_75 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_76 = F_62 ( V_114 ) ;
V_65 -> V_72 [ V_116 ] . V_36 . V_77 = F_62 ( V_114 ) ;
V_65 -> V_72 [ V_116 ] . V_36 . V_78 = V_115 ;
}
V_65 -> V_17 = V_112 ;
V_65 -> V_81 = false ;
return F_63 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
V_117:
F_64 ( V_65 ) ;
return NULL ;
}
static struct V_109 * F_65 (
struct V_7 * V_8 , T_3 V_122 , T_4 V_123 ,
T_4 V_124 , enum V_88 V_89 ,
unsigned long V_45 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_65 ;
enum V_20 V_90 ;
T_1 V_125 , V_115 ;
int V_116 , V_59 ;
if ( ! V_123 || ! V_124 ) {
F_13 ( F_5 ( V_3 ) , L_20 ) ;
return NULL ;
}
if ( ! V_3 -> V_44 ) {
F_13 ( F_5 ( V_3 ) , L_17 ) ;
return NULL ;
}
if ( V_123 % V_124 ) {
F_13 ( F_5 ( V_3 ) , L_21 ) ;
return NULL ;
}
if ( V_3 -> V_62 ) {
F_13 ( F_5 ( V_3 ) , L_22 ) ;
return NULL ;
}
V_59 = F_52 ( V_3 , V_89 , & V_90 ) ;
if ( V_59 < 0 )
return NULL ;
V_115 = V_124 / V_90 ;
if ( V_115 > V_121 ) {
F_13 ( F_5 ( V_3 ) , L_23 ) ;
return NULL ;
}
if ( V_123 == V_124 )
V_3 -> V_36 . V_39 |= V_126 ;
else
V_3 -> V_36 . V_39 |= V_79 ;
V_3 -> V_36 . V_39 &= ~ V_119 ;
V_125 = V_123 / V_124 ;
V_65 = F_10 ( V_125 ) ;
if ( ! V_65 )
return NULL ;
for ( V_116 = 0 ; V_116 < V_125 ; V_116 ++ ) {
V_65 -> V_72 [ V_116 ] . V_120 = V_124 ;
F_58 ( & V_65 -> V_72 [ V_116 ] . V_36 ) ;
V_65 -> V_72 [ V_116 ] . V_36 . V_39 = V_3 -> V_36 . V_39 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_37 = V_3 -> V_36 . V_37 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_75 = V_3 -> V_36 . V_75 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_76 = V_122 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_77 = V_122 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_78 = V_115 ;
V_122 += V_124 ;
}
V_65 -> V_17 = V_125 ;
V_65 -> V_81 = true ;
return F_63 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
}
static struct V_109 * F_66 (
struct V_7 * V_8 , T_3 V_127 ,
T_3 V_128 , T_4 V_120 , unsigned long V_45 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_17 ;
struct V_9 * V_65 ;
T_4 V_129 , V_130 ;
int V_116 ;
V_17 = F_67 ( V_120 , V_121 ) ;
V_65 = F_10 ( V_17 ) ;
if ( ! V_65 )
return NULL ;
for ( V_130 = 0 , V_116 = 0 ; V_130 < V_120 ; V_130 += V_129 , V_116 ++ ) {
V_129 = F_68 ( T_4 , V_120 - V_130 ,
V_121 ) ;
V_65 -> V_72 [ V_116 ] . V_120 = V_129 ;
F_58 ( & V_65 -> V_72 [ V_116 ] . V_36 ) ;
V_65 -> V_72 [ V_116 ] . V_36 . V_39 =
F_53 ( V_131 ) |
V_132 |
V_133 |
V_86 |
V_134 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_37 = V_135 |
F_69 ( V_136 ) |
V_61 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_75 = V_128 + V_130 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_76 = V_127 + V_130 ;
V_65 -> V_72 [ V_116 ] . V_36 . V_78 = V_129 ;
}
V_65 -> V_17 = V_17 ;
V_65 -> V_81 = false ;
return F_63 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
}
static T_1 F_70 ( struct V_2 * V_3 )
{
T_1 V_39 , V_21 , V_67 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
V_39 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
V_21 = F_71 ( V_39 ) ;
V_67 = F_6 ( V_13 , F_36 ( V_3 -> V_47 ) ) ;
return V_67 << V_21 ;
}
static T_4 F_72 ( struct V_2 * V_3 ,
struct V_9 * V_65 ,
T_1 V_74 )
{
T_1 V_137 = 0 ;
int V_116 ;
if ( V_3 -> V_65 -> V_81 && V_74 == 0 )
return F_70 ( V_3 ) ;
for ( V_116 = V_74 ; V_116 < V_65 -> V_17 ; V_116 ++ )
V_137 += V_65 -> V_72 [ V_116 ] . V_120 ;
V_137 += F_70 ( V_3 ) ;
return V_137 ;
}
static enum V_138 F_73 ( struct V_7 * V_8 ,
T_5 V_139 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_10 * V_11 ;
enum V_138 V_58 ;
unsigned long V_45 ;
T_1 V_137 = 0 ;
V_58 = F_74 ( V_8 , V_139 , V_141 ) ;
if ( ( V_58 == V_142 ) || ( ! V_141 ) )
return V_58 ;
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
V_11 = F_75 ( & V_3 -> V_4 , V_139 ) ;
if ( V_3 -> V_65 && V_139 == V_3 -> V_65 -> V_11 . V_143 . V_139 )
V_137 = F_72 ( V_3 , V_3 -> V_65 ,
V_3 -> V_74 ) ;
else if ( V_11 )
V_137 = F_72 ( V_3 ,
F_4 ( V_11 ) , 0 ) ;
F_76 ( V_141 , V_137 ) ;
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
return V_58 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_59 ;
V_3 -> V_44 = false ;
V_59 = F_78 ( V_13 -> V_144 ) ;
if ( V_59 < 0 ) {
F_13 ( F_5 ( V_3 ) , L_24 , V_59 ) ;
return V_59 ;
}
V_59 = F_19 ( V_3 ) ;
if ( V_59 < 0 )
F_79 ( V_13 -> V_144 ) ;
return V_59 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_45 ;
F_26 ( F_5 ( V_3 ) , L_25 , V_3 -> V_47 ) ;
if ( V_3 -> V_62 ) {
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
F_24 ( V_3 ) ;
V_3 -> V_65 = NULL ;
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
}
F_79 ( V_13 -> V_144 ) ;
F_81 ( F_82 ( V_8 ) ) ;
}
static void F_83 ( struct V_10 * V_11 )
{
F_64 ( F_2 ( V_11 , struct V_9 , V_11 ) ) ;
}
static void F_84 ( struct V_2 * V_3 ,
struct V_145 * V_146 )
{
F_58 ( & V_3 -> V_36 ) ;
V_3 -> V_36 . V_39 = V_146 -> V_147 & V_148 ;
V_3 -> V_36 . V_39 |= F_85 ( V_146 -> V_149 ) ;
V_3 -> V_36 . V_39 |= V_134 | V_86 ;
V_3 -> V_36 . V_37 = V_146 -> V_150 & V_151 ;
}
static struct V_7 * F_86 ( struct V_152 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_13 = V_155 -> V_156 ;
struct V_5 * V_12 = V_13 -> V_6 . V_12 ;
struct V_145 V_146 ;
struct V_2 * V_3 ;
struct V_7 * V_8 ;
if ( V_153 -> V_157 < 4 ) {
F_13 ( V_12 , L_26 ) ;
return NULL ;
}
V_146 . V_158 = V_153 -> args [ 0 ] ;
V_146 . V_149 = V_153 -> args [ 1 ] ;
V_146 . V_147 = V_153 -> args [ 2 ] ;
V_146 . V_150 = V_153 -> args [ 3 ] ;
if ( ( V_146 . V_158 >= V_159 ) ||
( V_146 . V_149 >= V_160 ) ) {
F_13 ( V_12 , L_27 ) ;
return NULL ;
}
V_3 = & V_13 -> V_3 [ V_146 . V_158 ] ;
V_8 = F_87 ( & V_3 -> V_4 . V_3 ) ;
if ( ! V_8 ) {
F_13 ( V_12 , L_28 ) ;
return NULL ;
}
F_84 ( V_3 , & V_146 ) ;
return V_8 ;
}
static int F_88 ( struct V_161 * V_162 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_163 * V_164 ;
const struct V_165 * V_166 ;
struct V_167 * V_168 ;
int V_116 , V_59 ;
V_166 = F_89 ( V_169 , & V_162 -> V_12 ) ;
if ( ! V_166 ) {
F_13 ( & V_162 -> V_12 , L_29 ) ;
return - V_170 ;
}
V_13 = F_90 ( & V_162 -> V_12 , sizeof( * V_13 ) , V_171 ) ;
if ( ! V_13 )
return - V_172 ;
V_164 = & V_13 -> V_6 ;
V_168 = F_91 ( V_162 , V_173 , 0 ) ;
V_13 -> V_15 = F_92 ( & V_162 -> V_12 , V_168 ) ;
if ( F_93 ( V_13 -> V_15 ) )
return F_94 ( V_13 -> V_15 ) ;
V_13 -> V_144 = F_95 ( & V_162 -> V_12 , NULL ) ;
if ( F_93 ( V_13 -> V_144 ) ) {
F_13 ( & V_162 -> V_12 , L_30 ) ;
return F_94 ( V_13 -> V_144 ) ;
}
V_13 -> V_174 = F_96 ( V_162 -> V_12 . V_175 ,
L_31 ) ;
V_13 -> V_176 = F_97 ( & V_162 -> V_12 , NULL ) ;
if ( ! F_93 ( V_13 -> V_176 ) ) {
F_98 ( V_13 -> V_176 ) ;
F_99 ( 2 ) ;
F_100 ( V_13 -> V_176 ) ;
}
F_101 ( V_177 , V_164 -> V_178 ) ;
F_101 ( V_179 , V_164 -> V_178 ) ;
F_101 ( V_180 , V_164 -> V_178 ) ;
V_164 -> V_181 = F_77 ;
V_164 -> V_182 = F_80 ;
V_164 -> V_183 = F_73 ;
V_164 -> V_184 = F_50 ;
V_164 -> V_185 = F_59 ;
V_164 -> V_186 = F_65 ;
V_164 -> V_187 = F_16 ;
V_164 -> V_188 = F_27 ;
V_164 -> V_189 = F_33 ;
V_164 -> V_190 = F_102 ( V_22 ) |
F_102 ( V_24 ) |
F_102 ( V_26 ) ;
V_164 -> V_191 = F_102 ( V_22 ) |
F_102 ( V_24 ) |
F_102 ( V_26 ) ;
V_164 -> V_192 = F_102 ( V_100 ) | F_102 ( V_97 ) ;
V_164 -> V_193 = V_194 ;
V_164 -> V_195 = V_196 ;
V_164 -> V_12 = & V_162 -> V_12 ;
F_103 ( & V_164 -> V_197 ) ;
if ( V_13 -> V_174 ) {
F_101 ( V_198 , V_164 -> V_178 ) ;
V_164 -> V_199 = F_66 ;
V_164 -> V_192 |= F_102 ( V_200 ) ;
}
for ( V_116 = 0 ; V_116 < V_159 ; V_116 ++ ) {
V_3 = & V_13 -> V_3 [ V_116 ] ;
V_3 -> V_47 = V_116 ;
V_3 -> V_4 . V_201 = F_83 ;
F_104 ( & V_3 -> V_4 , V_164 ) ;
}
V_59 = F_105 ( V_164 ) ;
if ( V_59 )
return V_59 ;
for ( V_116 = 0 ; V_116 < V_159 ; V_116 ++ ) {
V_3 = & V_13 -> V_3 [ V_116 ] ;
V_168 = F_91 ( V_162 , V_202 , V_116 ) ;
if ( ! V_168 ) {
V_59 = - V_28 ;
F_13 ( & V_162 -> V_12 , L_32 , V_116 ) ;
goto V_203;
}
V_3 -> V_83 = V_168 -> V_204 ;
V_59 = F_106 ( & V_162 -> V_12 , V_3 -> V_83 ,
F_47 , 0 ,
F_107 ( F_5 ( V_3 ) ) , V_3 ) ;
if ( V_59 ) {
F_13 ( & V_162 -> V_12 ,
L_33 ,
V_59 , V_116 ) ;
goto V_203;
}
}
V_59 = F_108 ( V_162 -> V_12 . V_175 ,
F_86 , V_13 ) ;
if ( V_59 < 0 ) {
F_13 ( & V_162 -> V_12 ,
L_34 , V_59 ) ;
goto V_203;
}
F_109 ( V_162 , V_13 ) ;
F_110 ( & V_162 -> V_12 , L_35 ) ;
return 0 ;
V_203:
F_111 ( V_164 ) ;
return V_59 ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_205 , F_88 ) ;
}
