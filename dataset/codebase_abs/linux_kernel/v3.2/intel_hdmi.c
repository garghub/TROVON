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
for ( V_11 = 0 ; V_11 < V_8 -> V_14 + V_15 ; V_11 ++ )
V_10 += V_9 [ V_11 ] ;
V_8 -> V_12 = 0x100 - V_10 ;
}
static T_2 F_6 ( struct V_7 * V_8 )
{
T_2 V_16 = 0 ;
switch ( V_8 -> type ) {
case V_17 :
V_16 |= V_18 ;
break;
case V_19 :
V_16 |= V_20 ;
break;
default:
F_7 ( L_1 , V_8 -> type ) ;
break;
}
return V_16 ;
}
static T_2 F_8 ( struct V_7 * V_8 )
{
T_2 V_16 = 0 ;
switch ( V_8 -> type ) {
case V_17 :
V_16 |= V_21 | V_22 ;
break;
case V_19 :
V_16 |= V_23 | V_22 ;
break;
default:
F_7 ( L_1 , V_8 -> type ) ;
break;
}
return V_16 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_29 , V_16 , V_30 = F_10 ( V_31 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
if ( V_1 -> V_32 == V_33 )
V_29 = V_34 ;
else if ( V_1 -> V_32 == V_35 )
V_29 = V_36 ;
else
return;
V_16 = F_6 ( V_8 ) ;
V_30 &= ~ V_37 ;
F_11 ( V_31 , V_30 | V_29 | V_16 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_11 ( V_38 , * V_9 ) ;
V_9 ++ ;
}
V_16 |= F_8 ( V_8 ) ;
F_11 ( V_31 , V_39 | V_30 | V_29 | V_16 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_3 * V_9 = ( T_3 * ) V_8 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_40 * V_41 = V_3 -> V_41 ;
struct V_42 * V_42 = F_13 ( V_41 ) ;
int V_43 = F_14 ( V_42 -> V_44 ) ;
unsigned V_11 , V_14 = V_15 + V_8 -> V_14 ;
T_2 V_16 , V_30 = F_10 ( V_43 ) ;
F_15 ( V_25 , V_42 -> V_44 ) ;
V_16 = F_6 ( V_8 ) ;
V_30 &= ~ ( V_37 | 0xf ) ;
F_11 ( V_43 , V_39 | V_30 | V_16 ) ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 += 4 ) {
F_11 ( F_16 ( V_42 -> V_44 ) , * V_9 ) ;
V_9 ++ ;
}
V_16 |= F_8 ( V_8 ) ;
F_11 ( V_43 , V_39 | V_30 | V_16 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_45 )
return;
F_5 ( V_8 ) ;
V_1 -> V_46 ( V_3 , V_8 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_7 V_47 = {
. type = V_17 ,
. V_48 = V_49 ,
. V_14 = V_50 ,
} ;
F_17 ( V_3 , & V_47 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_7 V_51 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . type = V_19 ;
V_51 . V_48 = V_52 ;
V_51 . V_14 = V_53 ;
strcpy ( V_51 . V_54 . V_55 . V_56 , L_2 ) ;
strcpy ( V_51 . V_54 . V_55 . V_57 , L_3 ) ;
V_51 . V_54 . V_55 . V_58 = V_59 ;
F_17 ( V_3 , & V_51 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_60 * V_62 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_40 * V_41 = V_3 -> V_41 ;
struct V_42 * V_42 = F_13 ( V_41 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_63 ;
V_63 = V_64 | V_65 ;
if ( ! F_21 ( V_25 ) )
V_63 |= V_1 -> V_66 ;
if ( V_62 -> V_16 & V_67 )
V_63 |= V_68 ;
if ( V_62 -> V_16 & V_69 )
V_63 |= V_70 ;
if ( V_42 -> V_71 > 24 )
V_63 |= V_72 ;
else
V_63 |= V_73 ;
if ( V_1 -> V_45 && F_22 ( V_25 ) )
V_63 |= V_74 ;
if ( V_1 -> V_75 ) {
F_7 ( L_4 ,
F_23 ( V_42 -> V_44 ) ) ;
V_63 |= V_76 ;
V_63 |= V_77 ;
F_24 ( V_3 , V_62 ) ;
}
if ( F_22 ( V_25 ) )
V_63 |= F_25 ( V_42 -> V_44 ) ;
else if ( V_42 -> V_44 == 1 )
V_63 |= V_78 ;
F_11 ( V_1 -> V_32 , V_63 ) ;
F_26 ( V_1 -> V_32 ) ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
}
static void F_27 ( struct V_2 * V_3 , int V_61 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_79 ;
V_79 = F_10 ( V_1 -> V_32 ) ;
if ( F_21 ( V_25 ) ) {
F_11 ( V_1 -> V_32 , V_79 & ~ V_80 ) ;
F_26 ( V_1 -> V_32 ) ;
}
if ( V_61 != V_81 ) {
V_79 &= ~ V_80 ;
} else {
V_79 |= V_80 ;
}
F_11 ( V_1 -> V_32 , V_79 ) ;
F_26 ( V_1 -> V_32 ) ;
if ( F_21 ( V_25 ) ) {
F_11 ( V_1 -> V_32 , V_79 ) ;
F_26 ( V_1 -> V_32 ) ;
}
}
static int F_28 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
if ( V_61 -> clock > 165000 )
return V_82 ;
if ( V_61 -> clock < 20000 )
return V_83 ;
if ( V_61 -> V_16 & V_84 )
return V_85 ;
return V_86 ;
}
static bool F_29 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
struct V_60 * V_62 )
{
return true ;
}
static enum V_87
F_30 ( struct V_5 * V_6 , bool V_88 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
struct V_89 * V_89 ;
enum V_87 V_90 = V_91 ;
V_1 -> V_45 = false ;
V_1 -> V_75 = false ;
V_89 = F_31 ( V_6 ,
& V_27 -> V_92 [ V_1 -> V_93 ] . V_94 ) ;
if ( V_89 ) {
if ( V_89 -> V_95 & V_96 ) {
V_90 = V_97 ;
V_1 -> V_45 = F_32 ( V_89 ) ;
V_1 -> V_75 = F_33 ( V_89 ) ;
}
V_6 -> V_98 . V_99 = NULL ;
F_34 ( V_89 ) ;
}
if ( V_90 == V_97 ) {
if ( V_1 -> V_100 )
V_1 -> V_75 = V_1 -> V_100 > 0 ;
}
return V_90 ;
}
static int F_35 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
return F_36 ( V_6 ,
& V_27 -> V_92 [ V_1 -> V_93 ] . V_94 ) ;
}
static bool
F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
struct V_89 * V_89 ;
bool V_75 = false ;
V_89 = F_31 ( V_6 ,
& V_27 -> V_92 [ V_1 -> V_93 ] . V_94 ) ;
if ( V_89 ) {
if ( V_89 -> V_95 & V_96 )
V_75 = F_33 ( V_89 ) ;
V_6 -> V_98 . V_99 = NULL ;
F_34 ( V_89 ) ;
}
return V_75 ;
}
static int
F_38 ( struct V_5 * V_6 ,
struct V_101 * V_102 ,
T_4 V_30 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_26 * V_27 = V_6 -> V_25 -> V_28 ;
int V_103 ;
V_103 = F_39 ( V_6 , V_102 , V_30 ) ;
if ( V_103 )
return V_103 ;
if ( V_102 == V_27 -> V_104 ) {
int V_11 = V_30 ;
bool V_75 ;
if ( V_11 == V_1 -> V_100 )
return 0 ;
V_1 -> V_100 = V_11 ;
if ( V_11 == 0 )
V_75 = F_37 ( V_6 ) ;
else
V_75 = V_11 > 0 ;
if ( V_75 == V_1 -> V_75 )
return 0 ;
V_1 -> V_75 = V_75 ;
goto V_105;
}
if ( V_102 == V_27 -> V_106 ) {
if ( V_30 == ! ! V_1 -> V_66 )
return 0 ;
V_1 -> V_66 = V_30 ? V_107 : 0 ;
goto V_105;
}
return - V_108 ;
V_105:
if ( V_1 -> V_4 . V_4 . V_41 ) {
struct V_40 * V_41 = V_1 -> V_4 . V_4 . V_41 ;
F_40 ( V_41 , & V_41 -> V_61 ,
V_41 -> V_109 , V_41 -> V_110 ,
V_41 -> V_111 ) ;
}
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
F_34 ( V_6 ) ;
}
static void
F_44 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_45 ( V_6 ) ;
F_46 ( V_6 ) ;
}
void F_47 ( struct V_24 * V_25 , int V_32 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_5 * V_6 ;
struct V_112 * V_112 ;
struct V_113 * V_113 ;
struct V_1 * V_1 ;
int V_11 ;
V_1 = F_48 ( sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_1 )
return;
V_113 = F_48 ( sizeof( struct V_113 ) , V_114 ) ;
if ( ! V_113 ) {
F_34 ( V_1 ) ;
return;
}
V_112 = & V_1 -> V_4 ;
F_49 ( V_25 , & V_112 -> V_4 , & V_115 ,
V_116 ) ;
V_6 = & V_113 -> V_4 ;
F_50 ( V_25 , V_6 , & V_117 ,
V_118 ) ;
F_51 ( V_6 , & V_119 ) ;
V_112 -> type = V_120 ;
V_6 -> V_121 = V_122 ;
V_6 -> V_123 = 0 ;
V_6 -> V_124 = 0 ;
V_112 -> V_125 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
if ( V_32 == V_33 ) {
V_112 -> V_126 = ( 1 << V_127 ) ;
V_1 -> V_93 = V_128 ;
V_27 -> V_129 |= V_130 ;
} else if ( V_32 == V_35 ) {
V_112 -> V_126 = ( 1 << V_131 ) ;
V_1 -> V_93 = V_132 ;
V_27 -> V_129 |= V_133 ;
} else if ( V_32 == V_134 ) {
V_112 -> V_126 = ( 1 << V_135 ) ;
V_1 -> V_93 = V_128 ;
V_27 -> V_129 |= V_130 ;
} else if ( V_32 == V_136 ) {
V_112 -> V_126 = ( 1 << V_137 ) ;
V_1 -> V_93 = V_132 ;
V_27 -> V_129 |= V_133 ;
} else if ( V_32 == V_138 ) {
V_112 -> V_126 = ( 1 << V_139 ) ;
V_1 -> V_93 = V_140 ;
V_27 -> V_129 |= V_141 ;
}
V_1 -> V_32 = V_32 ;
if ( ! F_21 ( V_25 ) ) {
V_1 -> V_46 = F_9 ;
F_11 ( V_31 , 0 ) ;
} else {
V_1 -> V_46 = F_12 ;
F_52 (i)
F_11 ( F_14 ( V_11 ) , 0 ) ;
}
F_53 ( & V_112 -> V_4 , & V_142 ) ;
F_44 ( V_1 , V_6 ) ;
F_54 ( V_113 , V_112 ) ;
F_55 ( V_6 ) ;
if ( F_56 ( V_25 ) && ! F_57 ( V_25 ) ) {
T_2 V_79 = F_10 ( V_143 ) ;
F_11 ( V_143 , ( V_79 & ~ 0xf ) | 0xd ) ;
}
}
