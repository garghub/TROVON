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
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_66 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
T_1 V_67 = F_6 ( V_13 , F_34 ( V_3 -> V_47 ) ) ;
T_1 V_68 = F_6 ( V_13 , F_35 ( V_3 -> V_47 ) ) ;
T_1 V_69 = F_6 ( V_13 , F_36 ( V_3 -> V_47 ) ) ;
T_1 V_70 = F_6 ( V_13 , F_37 ( V_3 -> V_47 ) ) ;
T_1 V_71 = F_6 ( V_13 , F_25 ( V_3 -> V_47 ) ) ;
F_26 ( F_5 ( V_3 ) , L_5 , V_66 ) ;
F_26 ( F_5 ( V_3 ) , L_6 , V_67 ) ;
F_26 ( F_5 ( V_3 ) , L_7 , V_68 ) ;
F_26 ( F_5 ( V_3 ) , L_8 , V_69 ) ;
F_26 ( F_5 ( V_3 ) , L_9 , V_70 ) ;
F_26 ( F_5 ( V_3 ) , L_10 , V_71 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_10 * V_11 ;
struct V_18 * V_72 ;
struct V_73 * V_14 ;
T_1 V_58 ;
int V_59 ;
V_59 = F_19 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ! V_3 -> V_65 ) {
V_11 = F_39 ( & V_3 -> V_4 ) ;
if ( ! V_11 )
return - V_74 ;
V_3 -> V_65 = F_4 ( V_11 ) ;
V_3 -> V_75 = 0 ;
}
if ( V_3 -> V_75 == V_3 -> V_65 -> V_17 )
V_3 -> V_75 = 0 ;
V_72 = & V_3 -> V_65 -> V_72 [ V_3 -> V_75 ] ;
V_14 = & V_72 -> V_36 ;
F_8 ( V_13 , F_21 ( V_3 -> V_47 ) , V_14 -> V_39 ) ;
F_8 ( V_13 , F_35 ( V_3 -> V_47 ) , V_14 -> V_76 ) ;
F_8 ( V_13 , F_36 ( V_3 -> V_47 ) , V_14 -> V_77 ) ;
F_8 ( V_13 , F_25 ( V_3 -> V_47 ) , V_14 -> V_37 ) ;
F_8 ( V_13 , F_37 ( V_3 -> V_47 ) , V_14 -> V_78 ) ;
F_8 ( V_13 , F_34 ( V_3 -> V_47 ) , V_14 -> V_79 ) ;
V_3 -> V_75 ++ ;
V_58 = F_17 ( V_3 ) ;
if ( V_58 )
F_18 ( V_3 , V_58 ) ;
F_33 ( V_3 ) ;
V_14 -> V_39 |= V_55 ;
F_8 ( V_13 , F_21 ( V_3 -> V_47 ) , V_14 -> V_39 ) ;
V_3 -> V_62 = true ;
return 0 ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_18 * V_72 ;
T_1 V_39 , V_77 , V_78 , V_47 ;
V_47 = V_3 -> V_47 ;
V_39 = F_6 ( V_13 , F_21 ( V_47 ) ) ;
if ( V_39 & V_80 ) {
if ( V_3 -> V_75 == V_3 -> V_65 -> V_17 )
V_3 -> V_75 = 0 ;
V_72 = & V_3 -> V_65 -> V_72 [ V_3 -> V_75 ] ;
if ( V_39 & V_81 ) {
V_77 = V_72 -> V_36 . V_77 ;
F_8 ( V_13 , F_36 ( V_47 ) , V_77 ) ;
F_26 ( F_5 ( V_3 ) , L_11 ,
F_6 ( V_13 , F_36 ( V_47 ) ) ) ;
} else {
V_78 = V_72 -> V_36 . V_78 ;
F_8 ( V_13 , F_37 ( V_47 ) , V_78 ) ;
F_26 ( F_5 ( V_3 ) , L_12 ,
F_6 ( V_13 , F_37 ( V_47 ) ) ) ;
}
V_3 -> V_75 ++ ;
}
}
static void F_41 ( struct V_2 * V_3 )
{
if ( V_3 -> V_65 ) {
if ( V_3 -> V_65 -> V_82 ) {
F_42 ( & V_3 -> V_65 -> V_11 ) ;
F_40 ( V_3 ) ;
} else {
V_3 -> V_62 = false ;
if ( V_3 -> V_75 == V_3 -> V_65 -> V_17 ) {
F_43 ( & V_3 -> V_65 -> V_11 . V_83 ) ;
F_44 ( & V_3 -> V_65 -> V_11 ) ;
V_3 -> V_65 = NULL ;
}
F_38 ( V_3 ) ;
}
}
}
static T_2 F_45 ( int V_84 , void * V_85 )
{
struct V_2 * V_3 = V_85 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_58 , V_66 , V_71 ;
F_46 ( & V_3 -> V_4 . V_64 ) ;
V_58 = F_17 ( V_3 ) ;
V_66 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
V_71 = F_6 ( V_13 , F_25 ( V_3 -> V_47 ) ) ;
if ( ( V_58 & V_86 ) && ( V_66 & V_87 ) ) {
F_18 ( V_3 , V_86 ) ;
F_41 ( V_3 ) ;
} else {
F_18 ( V_3 , V_58 ) ;
F_13 ( F_5 ( V_3 ) , L_13 , V_58 ) ;
}
F_47 ( & V_3 -> V_4 . V_64 ) ;
return V_88 ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
unsigned long V_45 ;
int V_59 ;
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
if ( ! V_3 -> V_62 ) {
if ( F_49 ( & V_3 -> V_4 ) && ! V_3 -> V_65 ) {
V_59 = F_38 ( V_3 ) ;
if ( ( ! V_59 ) && ( V_3 -> V_65 -> V_82 ) )
F_40 ( V_3 ) ;
}
}
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
enum V_89 V_90 ,
enum V_20 * V_91 )
{
enum V_20 V_92 , V_93 ;
int V_94 , V_95 ;
int V_96 , V_97 ;
T_1 V_34 , V_35 ;
T_3 V_98 , V_99 ;
T_1 V_39 = 0 ;
V_92 = V_3 -> V_43 . V_92 ;
V_93 = V_3 -> V_43 . V_93 ;
V_34 = V_3 -> V_43 . V_34 ;
V_35 = V_3 -> V_43 . V_35 ;
V_98 = V_3 -> V_43 . V_98 ;
V_99 = V_3 -> V_43 . V_99 ;
switch ( V_90 ) {
case V_100 :
V_95 = F_12 ( V_3 , V_93 ) ;
if ( V_95 < 0 )
return V_95 ;
V_97 = F_14 ( V_3 , V_35 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( ! V_92 )
V_92 = V_93 ;
V_94 = F_12 ( V_3 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
V_96 = F_14 ( V_3 , V_34 ) ;
if ( V_96 < 0 )
return V_96 ;
V_39 = F_51 ( V_101 ) |
F_52 ( V_95 ) |
F_53 ( V_94 ) |
F_54 ( V_97 ) |
F_55 ( V_96 ) ;
V_3 -> V_36 . V_76 = V_3 -> V_43 . V_99 ;
* V_91 = V_93 ;
break;
case V_102 :
V_94 = F_12 ( V_3 , V_92 ) ;
if ( V_94 < 0 )
return V_94 ;
V_96 = F_14 ( V_3 , V_34 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! V_93 )
V_93 = V_92 ;
V_95 = F_12 ( V_3 , V_93 ) ;
if ( V_95 < 0 )
return V_95 ;
V_97 = F_14 ( V_3 , V_35 ) ;
if ( V_97 < 0 )
return V_97 ;
V_39 = F_51 ( V_103 ) |
F_52 ( V_94 ) |
F_53 ( V_95 ) |
F_54 ( V_96 ) |
F_55 ( V_97 ) ;
V_3 -> V_36 . V_76 = V_3 -> V_43 . V_98 ;
* V_91 = V_3 -> V_43 . V_92 ;
break;
default:
F_13 ( F_5 ( V_3 ) , L_14 ) ;
return - V_28 ;
}
F_15 ( V_3 , V_34 , V_35 ) ;
V_3 -> V_36 . V_39 &= ~ ( V_104 |
V_105 | V_106 |
V_107 | V_108 ) ;
V_3 -> V_36 . V_39 |= V_39 ;
return 0 ;
}
static void F_56 ( struct V_73 * V_109 )
{
memset ( V_109 , 0 , sizeof( struct V_73 ) ) ;
}
static struct V_110 * F_57 (
struct V_7 * V_8 , struct V_111 * V_112 ,
T_1 V_113 , enum V_89 V_90 ,
unsigned long V_45 , void * V_114 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_65 ;
struct V_111 * V_115 ;
enum V_20 V_91 ;
T_1 V_116 ;
int V_117 , V_59 ;
if ( ! V_3 -> V_44 ) {
F_13 ( F_5 ( V_3 ) , L_15 ) ;
return NULL ;
}
if ( V_113 < 1 ) {
F_13 ( F_5 ( V_3 ) , L_16 , V_113 ) ;
return NULL ;
}
V_65 = F_10 ( V_113 ) ;
if ( ! V_65 )
return NULL ;
V_59 = F_50 ( V_3 , V_90 , & V_91 ) ;
if ( V_59 < 0 )
goto V_118;
if ( V_3 -> V_43 . V_119 )
V_3 -> V_36 . V_39 |= V_120 ;
else
V_3 -> V_36 . V_39 &= ~ V_120 ;
F_58 (sgl, sg, sg_len, i) {
V_65 -> V_72 [ V_117 ] . V_121 = F_59 ( V_115 ) ;
V_116 = V_65 -> V_72 [ V_117 ] . V_121 / V_91 ;
if ( V_116 > V_122 ) {
F_13 ( F_5 ( V_3 ) , L_17 ) ;
goto V_118;
}
F_56 ( & V_65 -> V_72 [ V_117 ] . V_36 ) ;
V_65 -> V_72 [ V_117 ] . V_36 . V_39 = V_3 -> V_36 . V_39 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_37 = V_3 -> V_36 . V_37 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_76 = V_3 -> V_36 . V_76 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_77 = F_60 ( V_115 ) ;
V_65 -> V_72 [ V_117 ] . V_36 . V_78 = F_60 ( V_115 ) ;
V_65 -> V_72 [ V_117 ] . V_36 . V_79 = V_116 ;
}
V_65 -> V_17 = V_113 ;
V_65 -> V_82 = false ;
return F_61 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
V_118:
F_62 ( V_65 ) ;
return NULL ;
}
static struct V_110 * F_63 (
struct V_7 * V_8 , T_3 V_123 , T_4 V_124 ,
T_4 V_125 , enum V_89 V_90 ,
unsigned long V_45 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_65 ;
enum V_20 V_91 ;
T_1 V_126 , V_116 ;
int V_117 , V_59 ;
if ( ! V_124 || ! V_125 ) {
F_13 ( F_5 ( V_3 ) , L_18 ) ;
return NULL ;
}
if ( ! V_3 -> V_44 ) {
F_13 ( F_5 ( V_3 ) , L_15 ) ;
return NULL ;
}
if ( V_124 % V_125 ) {
F_13 ( F_5 ( V_3 ) , L_19 ) ;
return NULL ;
}
if ( V_3 -> V_62 ) {
F_13 ( F_5 ( V_3 ) , L_20 ) ;
return NULL ;
}
V_59 = F_50 ( V_3 , V_90 , & V_91 ) ;
if ( V_59 < 0 )
return NULL ;
V_116 = V_125 / V_91 ;
if ( V_116 > V_122 ) {
F_13 ( F_5 ( V_3 ) , L_21 ) ;
return NULL ;
}
if ( V_124 == V_125 )
V_3 -> V_36 . V_39 |= V_127 ;
else
V_3 -> V_36 . V_39 |= V_80 ;
V_3 -> V_36 . V_39 &= ~ V_120 ;
V_126 = V_124 / V_125 ;
V_65 = F_10 ( V_126 ) ;
if ( ! V_65 )
return NULL ;
for ( V_117 = 0 ; V_117 < V_126 ; V_117 ++ ) {
V_65 -> V_72 [ V_117 ] . V_121 = V_125 ;
F_56 ( & V_65 -> V_72 [ V_117 ] . V_36 ) ;
V_65 -> V_72 [ V_117 ] . V_36 . V_39 = V_3 -> V_36 . V_39 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_37 = V_3 -> V_36 . V_37 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_76 = V_3 -> V_36 . V_76 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_77 = V_123 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_78 = V_123 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_79 = V_116 ;
V_123 += V_125 ;
}
V_65 -> V_17 = V_126 ;
V_65 -> V_82 = true ;
return F_61 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
}
static struct V_110 * F_64 (
struct V_7 * V_8 , T_3 V_128 ,
T_3 V_129 , T_4 V_121 , unsigned long V_45 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
T_1 V_17 ;
struct V_9 * V_65 ;
T_4 V_130 , V_131 ;
int V_117 ;
V_17 = F_65 ( V_121 , V_122 ) ;
V_65 = F_10 ( V_17 ) ;
if ( ! V_65 )
return NULL ;
for ( V_131 = 0 , V_117 = 0 ; V_131 < V_121 ; V_131 += V_130 , V_117 ++ ) {
V_130 = F_66 ( T_4 , V_121 - V_131 ,
V_122 ) ;
V_65 -> V_72 [ V_117 ] . V_121 = V_130 ;
F_56 ( & V_65 -> V_72 [ V_117 ] . V_36 ) ;
V_65 -> V_72 [ V_117 ] . V_36 . V_39 =
F_51 ( V_132 ) |
V_133 |
V_134 |
V_87 |
V_135 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_37 = V_136 |
F_67 ( V_137 ) |
V_61 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_76 = V_129 + V_131 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_77 = V_128 + V_131 ;
V_65 -> V_72 [ V_117 ] . V_36 . V_79 = V_130 ;
}
V_65 -> V_17 = V_17 ;
V_65 -> V_82 = false ;
return F_61 ( & V_3 -> V_4 , & V_65 -> V_11 , V_45 ) ;
}
static T_4 F_68 ( struct V_2 * V_3 ,
struct V_9 * V_65 ,
T_1 V_75 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_1 V_39 , V_21 , V_138 , V_139 ;
int V_117 ;
V_138 = 0 ;
for ( V_117 = V_75 ; V_117 < V_65 -> V_17 ; V_117 ++ )
V_138 += V_65 -> V_72 [ V_117 ] . V_121 ;
if ( V_75 != 0 ) {
V_39 = F_6 ( V_13 , F_21 ( V_3 -> V_47 ) ) ;
V_21 = F_69 ( V_39 ) ;
V_139 = F_6 ( V_13 , F_34 ( V_3 -> V_47 ) ) ;
V_138 += V_139 << V_21 ;
}
return V_138 ;
}
static enum V_140 F_70 ( struct V_7 * V_8 ,
T_5 V_141 ,
struct V_142 * V_143 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_10 * V_11 ;
enum V_140 V_58 ;
unsigned long V_45 ;
T_1 V_138 ;
V_58 = F_71 ( V_8 , V_141 , V_143 ) ;
if ( ( V_58 == V_144 ) || ( ! V_143 ) )
return V_58 ;
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
V_11 = F_72 ( & V_3 -> V_4 , V_141 ) ;
if ( V_141 == V_3 -> V_65 -> V_11 . V_145 . V_141 ) {
V_138 = F_68 ( V_3 , V_3 -> V_65 ,
V_3 -> V_75 ) ;
} else if ( V_11 ) {
V_138 = F_68 ( V_3 ,
F_4 ( V_11 ) , 0 ) ;
} else {
V_138 = 0 ;
}
F_73 ( V_143 , V_138 ) ;
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
return V_58 ;
}
static int F_74 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
int V_59 ;
V_3 -> V_44 = false ;
V_59 = F_75 ( V_13 -> V_146 ) ;
if ( V_59 < 0 ) {
F_13 ( F_5 ( V_3 ) , L_22 , V_59 ) ;
return V_59 ;
}
V_59 = F_19 ( V_3 ) ;
if ( V_59 < 0 )
F_76 ( V_13 -> V_146 ) ;
return V_59 ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_45 ;
F_26 ( F_5 ( V_3 ) , L_23 , V_3 -> V_47 ) ;
if ( V_3 -> V_62 ) {
F_29 ( & V_3 -> V_4 . V_64 , V_45 ) ;
F_24 ( V_3 ) ;
V_3 -> V_65 = NULL ;
F_31 ( & V_3 -> V_4 . V_64 , V_45 ) ;
}
F_76 ( V_13 -> V_146 ) ;
F_78 ( F_79 ( V_8 ) ) ;
}
static void F_80 ( struct V_10 * V_11 )
{
F_62 ( F_2 ( V_11 , struct V_9 , V_11 ) ) ;
}
void F_81 ( struct V_2 * V_3 ,
struct V_147 * V_148 )
{
F_56 ( & V_3 -> V_36 ) ;
V_3 -> V_36 . V_39 = V_148 -> V_149 & V_150 ;
V_3 -> V_36 . V_39 |= F_82 ( V_148 -> V_151 ) ;
V_3 -> V_36 . V_39 |= V_135 | V_87 ;
V_3 -> V_36 . V_37 = V_148 -> V_152 & V_153 ;
}
static struct V_7 * F_83 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
struct V_1 * V_13 = V_157 -> V_158 ;
struct V_147 V_148 ;
struct V_2 * V_3 ;
struct V_7 * V_8 ;
if ( V_155 -> V_159 < 3 )
return NULL ;
V_148 . V_160 = V_155 -> args [ 0 ] ;
V_148 . V_151 = V_155 -> args [ 1 ] ;
V_148 . V_149 = V_155 -> args [ 2 ] ;
V_148 . V_152 = 0 ;
if ( ( V_148 . V_160 >= V_161 ) || ( V_148 . V_151 >=
V_162 ) )
return NULL ;
if ( V_155 -> V_159 > 3 )
V_148 . V_152 = V_155 -> args [ 3 ] ;
V_3 = & V_13 -> V_3 [ V_148 . V_160 ] ;
V_8 = F_84 ( & V_3 -> V_4 . V_3 ) ;
if ( V_8 )
F_81 ( V_3 , & V_148 ) ;
return V_8 ;
}
static int F_85 ( struct V_163 * V_164 )
{
struct V_2 * V_3 ;
struct V_1 * V_13 ;
struct V_165 * V_166 ;
const struct V_167 * V_168 ;
struct V_169 * V_170 ;
int V_117 , V_59 ;
V_168 = F_86 ( V_171 , & V_164 -> V_12 ) ;
if ( ! V_168 ) {
F_13 ( & V_164 -> V_12 , L_24 ) ;
return - V_172 ;
}
V_13 = F_87 ( & V_164 -> V_12 , sizeof( * V_13 ) , V_173 ) ;
if ( ! V_13 )
return - V_174 ;
V_166 = & V_13 -> V_6 ;
V_170 = F_88 ( V_164 , V_175 , 0 ) ;
V_13 -> V_15 = F_89 ( & V_164 -> V_12 , V_170 ) ;
if ( F_90 ( V_13 -> V_15 ) )
return F_91 ( V_13 -> V_15 ) ;
V_13 -> V_146 = F_92 ( & V_164 -> V_12 , NULL ) ;
if ( F_90 ( V_13 -> V_146 ) ) {
F_13 ( & V_164 -> V_12 , L_25 ) ;
return F_91 ( V_13 -> V_146 ) ;
}
V_13 -> V_176 = F_93 ( V_164 -> V_12 . V_177 ,
L_26 ) ;
V_13 -> V_178 = F_94 ( & V_164 -> V_12 , NULL ) ;
if ( ! F_90 ( V_13 -> V_178 ) ) {
F_95 ( V_13 -> V_178 ) ;
F_96 ( 2 ) ;
F_97 ( V_13 -> V_178 ) ;
}
F_98 ( V_179 , V_166 -> V_180 ) ;
F_98 ( V_181 , V_166 -> V_180 ) ;
F_98 ( V_182 , V_166 -> V_180 ) ;
V_166 -> V_183 = F_74 ;
V_166 -> V_184 = F_77 ;
V_166 -> V_185 = F_70 ;
V_166 -> V_186 = F_48 ;
V_166 -> V_187 = F_57 ;
V_166 -> V_188 = F_63 ;
V_166 -> V_189 = F_16 ;
V_166 -> V_190 = F_27 ;
V_166 -> V_191 = F_99 ( V_22 ) |
F_99 ( V_24 ) |
F_99 ( V_26 ) ;
V_166 -> V_192 = F_99 ( V_22 ) |
F_99 ( V_24 ) |
F_99 ( V_26 ) ;
V_166 -> V_193 = F_99 ( V_102 ) | F_99 ( V_100 ) ;
V_166 -> V_194 = V_195 ;
V_166 -> V_12 = & V_164 -> V_12 ;
F_100 ( & V_166 -> V_196 ) ;
if ( V_13 -> V_176 ) {
F_98 ( V_197 , V_166 -> V_180 ) ;
V_166 -> V_198 = F_64 ;
V_166 -> V_193 |= F_99 ( V_199 ) ;
}
for ( V_117 = 0 ; V_117 < V_161 ; V_117 ++ ) {
V_3 = & V_13 -> V_3 [ V_117 ] ;
V_3 -> V_47 = V_117 ;
V_3 -> V_4 . V_200 = F_80 ;
F_101 ( & V_3 -> V_4 , V_166 ) ;
}
V_59 = F_102 ( V_166 ) ;
if ( V_59 )
return V_59 ;
for ( V_117 = 0 ; V_117 < V_161 ; V_117 ++ ) {
V_3 = & V_13 -> V_3 [ V_117 ] ;
V_170 = F_88 ( V_164 , V_201 , V_117 ) ;
if ( ! V_170 ) {
V_59 = - V_28 ;
F_13 ( & V_164 -> V_12 , L_27 , V_117 ) ;
goto V_202;
}
V_3 -> V_84 = V_170 -> V_203 ;
V_59 = F_103 ( & V_164 -> V_12 , V_3 -> V_84 ,
F_45 , 0 ,
F_104 ( F_5 ( V_3 ) ) , V_3 ) ;
if ( V_59 ) {
F_13 ( & V_164 -> V_12 ,
L_28 ,
V_59 , V_117 ) ;
goto V_202;
}
}
V_59 = F_105 ( V_164 -> V_12 . V_177 ,
F_83 , V_13 ) ;
if ( V_59 < 0 ) {
F_13 ( & V_164 -> V_12 ,
L_29 , V_59 ) ;
goto V_202;
}
F_106 ( V_164 , V_13 ) ;
F_107 ( & V_164 -> V_12 , L_30 ) ;
return 0 ;
V_202:
F_108 ( V_166 ) ;
return V_59 ;
}
static int T_6 F_109 ( void )
{
return F_110 ( & V_204 , F_85 ) ;
}
