static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
void F_5 ( struct V_7 * V_8 )
{
T_1 * V_9 = ( T_1 * ) V_8 ;
T_1 V_10 = 0 ;
unsigned V_11 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
for ( V_11 = 5 ; V_11 < V_8 -> V_14 ; V_11 ++ )
V_10 += V_9 [ V_11 ] ;
V_8 -> V_12 = 0x100 - V_10 ;
}
static T_2 F_6 ( struct V_7 * V_8 )
{
T_2 V_15 = 0 ;
switch ( V_8 -> type ) {
case V_16 :
V_15 |= V_17 ;
break;
case V_18 :
V_15 |= V_19 ;
break;
default:
F_7 ( L_1 , V_8 -> type ) ;
break;
}
return V_15 ;
}
static T_2 F_8 ( struct V_7 * V_8 )
{
T_2 V_15 = 0 ;
switch ( V_8 -> type ) {
case V_16 :
V_15 |= V_20 | V_21 ;
break;
case V_18 :
V_15 |= V_22 | V_23 ;
break;
default:
F_7 ( L_1 , V_8 -> type ) ;
break;
}
return V_15 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_29 , V_15 , V_30 = F_10 ( V_31 ) ;
unsigned V_11 , V_14 = V_32 + V_8 -> V_14 ;
if ( V_1 -> V_33 == V_34 )
V_29 = V_35 ;
else if ( V_1 -> V_33 == V_36 )
V_29 = V_37 ;
else
return;
V_15 = F_6 ( V_8 ) ;
V_30 &= ~ V_38 ;
F_11 ( V_31 , V_30 | V_29 | V_15 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_11 ( V_39 , * V_9 ) ;
V_9 ++ ;
}
V_15 |= F_8 ( V_8 ) ;
F_11 ( V_31 , V_40 | V_30 | V_29 | V_15 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_41 * V_42 = V_3 -> V_42 ;
struct V_43 * V_43 = F_13 ( V_42 ) ;
int V_44 = F_14 ( V_43 -> V_45 ) ;
unsigned V_11 , V_14 = V_32 + V_8 -> V_14 ;
T_2 V_15 , V_30 = F_10 ( V_44 ) ;
F_15 ( V_25 , V_43 -> V_45 ) ;
V_15 = F_6 ( V_8 ) ;
V_30 &= ~ V_38 ;
F_11 ( V_44 , V_30 | V_15 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_11 ( F_16 ( V_43 -> V_45 ) , * V_9 ) ;
V_9 ++ ;
}
V_15 |= F_8 ( V_8 ) ;
F_11 ( V_44 , V_40 | V_30 | V_15 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_46 )
return;
F_5 ( V_8 ) ;
V_1 -> V_47 ( V_3 , V_8 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_7 V_48 = {
. type = V_16 ,
. V_49 = V_50 ,
. V_14 = V_51 ,
} ;
F_17 ( V_3 , & V_48 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_7 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . type = V_18 ;
V_52 . V_49 = V_53 ;
V_52 . V_14 = V_54 ;
strcpy ( V_52 . V_55 . V_56 . V_57 , L_2 ) ;
strcpy ( V_52 . V_55 . V_56 . V_58 , L_3 ) ;
V_52 . V_55 . V_56 . V_59 = V_60 ;
F_17 ( V_3 , & V_52 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_61 * V_63 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_41 * V_42 = V_3 -> V_42 ;
struct V_43 * V_43 = F_13 ( V_42 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_64 ;
V_64 = V_65 | V_66 ;
if ( ! F_21 ( V_25 ) )
V_64 |= V_1 -> V_67 ;
if ( V_63 -> V_15 & V_68 )
V_64 |= V_69 ;
if ( V_63 -> V_15 & V_70 )
V_64 |= V_71 ;
if ( V_43 -> V_72 > 24 )
V_64 |= V_73 ;
else
V_64 |= V_74 ;
if ( V_1 -> V_46 && F_22 ( V_25 ) )
V_64 |= V_75 ;
if ( V_1 -> V_76 ) {
V_64 |= V_77 ;
V_64 |= V_78 ;
}
if ( V_43 -> V_45 == 1 ) {
if ( F_22 ( V_25 ) )
V_64 |= V_79 ;
else
V_64 |= V_80 ;
}
F_11 ( V_1 -> V_33 , V_64 ) ;
F_23 ( V_1 -> V_33 ) ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
}
static void F_24 ( struct V_2 * V_3 , int V_62 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_81 ;
V_81 = F_10 ( V_1 -> V_33 ) ;
if ( F_21 ( V_25 ) ) {
F_11 ( V_1 -> V_33 , V_81 & ~ V_82 ) ;
F_23 ( V_1 -> V_33 ) ;
}
if ( V_62 != V_83 ) {
V_81 &= ~ V_82 ;
} else {
V_81 |= V_82 ;
}
F_11 ( V_1 -> V_33 , V_81 ) ;
F_23 ( V_1 -> V_33 ) ;
if ( F_21 ( V_25 ) ) {
F_11 ( V_1 -> V_33 , V_81 ) ;
F_23 ( V_1 -> V_33 ) ;
}
}
static int F_25 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
if ( V_62 -> clock > 165000 )
return V_84 ;
if ( V_62 -> clock < 20000 )
return V_85 ;
if ( V_62 -> V_15 & V_86 )
return V_87 ;
return V_88 ;
}
static bool F_26 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_61 * V_63 )
{
return true ;
}
static enum V_89
F_27 ( struct V_5 * V_6 , bool V_90 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
struct V_91 * V_91 ;
enum V_89 V_92 = V_93 ;
V_1 -> V_46 = false ;
V_1 -> V_76 = false ;
V_91 = F_28 ( V_6 ,
& V_27 -> V_94 [ V_1 -> V_95 ] . V_96 ) ;
if ( V_91 ) {
if ( V_91 -> V_97 & V_98 ) {
V_92 = V_99 ;
V_1 -> V_46 = F_29 ( V_91 ) ;
V_1 -> V_76 = F_30 ( V_91 ) ;
}
V_6 -> V_100 . V_101 = NULL ;
F_31 ( V_91 ) ;
}
if ( V_92 == V_99 ) {
if ( V_1 -> V_102 )
V_1 -> V_76 = V_1 -> V_102 > 0 ;
}
return V_92 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
return F_33 ( V_6 ,
& V_27 -> V_94 [ V_1 -> V_95 ] . V_96 ) ;
}
static bool
F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
struct V_91 * V_91 ;
bool V_76 = false ;
V_91 = F_28 ( V_6 ,
& V_27 -> V_94 [ V_1 -> V_95 ] . V_96 ) ;
if ( V_91 ) {
if ( V_91 -> V_97 & V_98 )
V_76 = F_30 ( V_91 ) ;
V_6 -> V_100 . V_101 = NULL ;
F_31 ( V_91 ) ;
}
return V_76 ;
}
static int
F_35 ( struct V_5 * V_6 ,
struct V_103 * V_104 ,
T_4 V_30 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
int V_105 ;
V_105 = F_36 ( V_6 , V_104 , V_30 ) ;
if ( V_105 )
return V_105 ;
if ( V_104 == V_27 -> V_106 ) {
int V_11 = V_30 ;
bool V_76 ;
if ( V_11 == V_1 -> V_102 )
return 0 ;
V_1 -> V_102 = V_11 ;
if ( V_11 == 0 )
V_76 = F_34 ( V_6 ) ;
else
V_76 = V_11 > 0 ;
if ( V_76 == V_1 -> V_76 )
return 0 ;
V_1 -> V_76 = V_76 ;
goto V_107;
}
if ( V_104 == V_27 -> V_108 ) {
if ( V_30 == ! ! V_1 -> V_67 )
return 0 ;
V_1 -> V_67 = V_30 ? V_109 : 0 ;
goto V_107;
}
return - V_110 ;
V_107:
if ( V_1 -> V_4 . V_4 . V_42 ) {
struct V_41 * V_42 = V_1 -> V_4 . V_4 . V_42 ;
F_37 ( V_42 , & V_42 -> V_62 ,
V_42 -> V_111 , V_42 -> V_112 ,
V_42 -> V_113 ) ;
}
return 0 ;
}
static void F_38 ( struct V_5 * V_6 )
{
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_31 ( V_6 ) ;
}
static void
F_41 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
}
void F_44 ( struct V_24 * V_25 , int V_33 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_5 * V_6 ;
struct V_114 * V_114 ;
struct V_115 * V_115 ;
struct V_1 * V_1 ;
V_1 = F_45 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_1 )
return;
V_115 = F_45 ( sizeof( struct V_115 ) , V_116 ) ;
if ( ! V_115 ) {
F_31 ( V_1 ) ;
return;
}
V_114 = & V_1 -> V_4 ;
F_46 ( V_25 , & V_114 -> V_4 , & V_117 ,
V_118 ) ;
V_6 = & V_115 -> V_4 ;
F_47 ( V_25 , V_6 , & V_119 ,
V_120 ) ;
F_48 ( V_6 , & V_121 ) ;
V_114 -> type = V_122 ;
V_6 -> V_123 = V_124 ;
V_6 -> V_125 = 0 ;
V_6 -> V_126 = 0 ;
V_114 -> V_127 = ( 1 << 0 ) | ( 1 << 1 ) ;
if ( V_33 == V_34 ) {
V_114 -> V_128 = ( 1 << V_129 ) ;
V_1 -> V_95 = V_130 ;
V_27 -> V_131 |= V_132 ;
} else if ( V_33 == V_36 ) {
V_114 -> V_128 = ( 1 << V_133 ) ;
V_1 -> V_95 = V_134 ;
V_27 -> V_131 |= V_135 ;
} else if ( V_33 == V_136 ) {
V_114 -> V_128 = ( 1 << V_137 ) ;
V_1 -> V_95 = V_130 ;
V_27 -> V_131 |= V_132 ;
} else if ( V_33 == V_138 ) {
V_114 -> V_128 = ( 1 << V_139 ) ;
V_1 -> V_95 = V_134 ;
V_27 -> V_131 |= V_135 ;
} else if ( V_33 == V_140 ) {
V_114 -> V_128 = ( 1 << V_141 ) ;
V_1 -> V_95 = V_142 ;
V_27 -> V_131 |= V_143 ;
}
V_1 -> V_33 = V_33 ;
if ( ! F_21 ( V_25 ) )
V_1 -> V_47 = F_9 ;
else
V_1 -> V_47 = F_12 ;
F_49 ( & V_114 -> V_4 , & V_144 ) ;
F_41 ( V_1 , V_6 ) ;
F_50 ( V_115 , V_114 ) ;
F_51 ( V_6 ) ;
if ( F_52 ( V_25 ) && ! F_53 ( V_25 ) ) {
T_2 V_81 = F_10 ( V_145 ) ;
F_11 ( V_145 , ( V_81 & ~ 0xf ) | 0xd ) ;
}
}
