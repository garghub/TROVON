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
for ( V_11 = 0 ; V_11 < sizeof( * V_8 ) ; V_11 ++ )
V_10 += V_9 [ V_11 ] ;
V_8 -> V_12 = 0x100 - V_10 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_7 V_8 = {
. type = V_14 ,
. V_15 = V_16 ,
. V_17 = V_18 ,
} ;
T_2 * V_9 = ( T_2 * ) & V_8 ;
struct V_19 * V_20 = V_3 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_24 ;
unsigned V_11 ;
if ( ! V_1 -> V_25 )
return;
if ( V_1 -> V_26 == V_27 )
V_24 = V_28 ;
else if ( V_1 -> V_26 == V_29 )
V_24 = V_30 ;
else
return;
F_7 ( V_31 , V_32 | V_24 |
V_33 | V_34 ) ;
F_5 ( & V_8 ) ;
for ( V_11 = 0 ; V_11 < sizeof( V_8 ) ; V_11 += 4 ) {
F_7 ( V_35 , * V_9 ) ;
V_9 ++ ;
}
F_7 ( V_31 , V_32 | V_24 |
V_33 | V_34 |
V_36 ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_37 * V_39 )
{
struct V_19 * V_20 = V_3 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_40 * V_41 = V_3 -> V_41 ;
struct V_42 * V_42 = F_9 ( V_41 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_43 ;
V_43 = V_44 | V_45 ;
V_43 |= V_1 -> V_46 ;
if ( V_39 -> V_47 & V_48 )
V_43 |= V_49 ;
if ( V_39 -> V_47 & V_50 )
V_43 |= V_51 ;
if ( V_1 -> V_25 && F_10 ( V_20 ) )
V_43 |= V_52 ;
if ( V_1 -> V_53 ) {
V_43 |= V_54 ;
V_43 |= V_55 ;
}
if ( V_42 -> V_56 == 1 ) {
if ( F_10 ( V_20 ) )
V_43 |= V_57 ;
else
V_43 |= V_58 ;
}
F_7 ( V_1 -> V_26 , V_43 ) ;
F_11 ( V_1 -> V_26 ) ;
F_6 ( V_3 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_38 )
{
struct V_19 * V_20 = V_3 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_59 ;
V_59 = F_13 ( V_1 -> V_26 ) ;
if ( F_14 ( V_20 ) ) {
F_7 ( V_1 -> V_26 , V_59 & ~ V_60 ) ;
F_11 ( V_1 -> V_26 ) ;
}
if ( V_38 != V_61 ) {
V_59 &= ~ V_60 ;
} else {
V_59 |= V_60 ;
}
F_7 ( V_1 -> V_26 , V_59 ) ;
F_11 ( V_1 -> V_26 ) ;
if ( F_14 ( V_20 ) ) {
F_7 ( V_1 -> V_26 , V_59 ) ;
F_11 ( V_1 -> V_26 ) ;
}
}
static int F_15 ( struct V_5 * V_6 ,
struct V_37 * V_38 )
{
if ( V_38 -> clock > 165000 )
return V_62 ;
if ( V_38 -> clock < 20000 )
return V_63 ;
if ( V_38 -> V_47 & V_64 )
return V_65 ;
return V_66 ;
}
static bool F_16 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_37 * V_39 )
{
return true ;
}
static enum V_67
F_17 ( struct V_5 * V_6 , bool V_68 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_21 * V_22 = V_6 -> V_20 -> V_23 ;
struct V_69 * V_69 ;
enum V_67 V_70 = V_71 ;
V_1 -> V_25 = false ;
V_1 -> V_53 = false ;
V_69 = F_18 ( V_6 ,
& V_22 -> V_72 [ V_1 -> V_73 ] . V_74 ) ;
if ( V_69 ) {
if ( V_69 -> V_75 & V_76 ) {
V_70 = V_77 ;
V_1 -> V_25 = F_19 ( V_69 ) ;
V_1 -> V_53 = F_20 ( V_69 ) ;
}
V_6 -> V_78 . V_79 = NULL ;
F_21 ( V_69 ) ;
}
if ( V_70 == V_77 ) {
if ( V_1 -> V_80 )
V_1 -> V_53 = V_1 -> V_80 > 0 ;
}
return V_70 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_21 * V_22 = V_6 -> V_20 -> V_23 ;
return F_23 ( V_6 ,
& V_22 -> V_72 [ V_1 -> V_73 ] . V_74 ) ;
}
static bool
F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_21 * V_22 = V_6 -> V_20 -> V_23 ;
struct V_69 * V_69 ;
bool V_53 = false ;
V_69 = F_18 ( V_6 ,
& V_22 -> V_72 [ V_1 -> V_73 ] . V_74 ) ;
if ( V_69 ) {
if ( V_69 -> V_75 & V_76 )
V_53 = F_20 ( V_69 ) ;
V_6 -> V_78 . V_79 = NULL ;
F_21 ( V_69 ) ;
}
return V_53 ;
}
static int
F_25 ( struct V_5 * V_6 ,
struct V_81 * V_82 ,
T_4 V_83 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_21 * V_22 = V_6 -> V_20 -> V_23 ;
int V_84 ;
V_84 = F_26 ( V_6 , V_82 , V_83 ) ;
if ( V_84 )
return V_84 ;
if ( V_82 == V_22 -> V_85 ) {
int V_11 = V_83 ;
bool V_53 ;
if ( V_11 == V_1 -> V_80 )
return 0 ;
V_1 -> V_80 = V_11 ;
if ( V_11 == 0 )
V_53 = F_24 ( V_6 ) ;
else
V_53 = V_11 > 0 ;
if ( V_53 == V_1 -> V_53 )
return 0 ;
V_1 -> V_53 = V_53 ;
goto V_86;
}
if ( V_82 == V_22 -> V_87 ) {
if ( V_83 == ! ! V_1 -> V_46 )
return 0 ;
V_1 -> V_46 = V_83 ? V_88 : 0 ;
goto V_86;
}
return - V_89 ;
V_86:
if ( V_1 -> V_4 . V_4 . V_41 ) {
struct V_40 * V_41 = V_1 -> V_4 . V_4 . V_41 ;
F_27 ( V_41 , & V_41 -> V_38 ,
V_41 -> V_90 , V_41 -> V_91 ,
V_41 -> V_92 ) ;
}
return 0 ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_21 ( V_6 ) ;
}
static void
F_31 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
}
void F_34 ( struct V_19 * V_20 , int V_26 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_5 * V_6 ;
struct V_93 * V_93 ;
struct V_94 * V_94 ;
struct V_1 * V_1 ;
V_1 = F_35 ( sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_1 )
return;
V_94 = F_35 ( sizeof( struct V_94 ) , V_95 ) ;
if ( ! V_94 ) {
F_21 ( V_1 ) ;
return;
}
V_93 = & V_1 -> V_4 ;
F_36 ( V_20 , & V_93 -> V_4 , & V_96 ,
V_97 ) ;
V_6 = & V_94 -> V_4 ;
F_37 ( V_20 , V_6 , & V_98 ,
V_99 ) ;
F_38 ( V_6 , & V_100 ) ;
V_93 -> type = V_101 ;
V_6 -> V_102 = V_103 ;
V_6 -> V_104 = 0 ;
V_6 -> V_105 = 0 ;
V_93 -> V_106 = ( 1 << 0 ) | ( 1 << 1 ) ;
if ( V_26 == V_27 ) {
V_93 -> V_107 = ( 1 << V_108 ) ;
V_1 -> V_73 = V_109 ;
V_22 -> V_110 |= V_111 ;
} else if ( V_26 == V_29 ) {
V_93 -> V_107 = ( 1 << V_112 ) ;
V_1 -> V_73 = V_113 ;
V_22 -> V_110 |= V_114 ;
} else if ( V_26 == V_115 ) {
V_93 -> V_107 = ( 1 << V_116 ) ;
V_1 -> V_73 = V_109 ;
V_22 -> V_110 |= V_111 ;
} else if ( V_26 == V_117 ) {
V_93 -> V_107 = ( 1 << V_118 ) ;
V_1 -> V_73 = V_113 ;
V_22 -> V_110 |= V_114 ;
} else if ( V_26 == V_119 ) {
V_93 -> V_107 = ( 1 << V_120 ) ;
V_1 -> V_73 = V_121 ;
V_22 -> V_110 |= V_122 ;
}
V_1 -> V_26 = V_26 ;
F_39 ( & V_93 -> V_4 , & V_123 ) ;
F_31 ( V_1 , V_6 ) ;
F_40 ( V_94 , V_93 ) ;
F_41 ( V_6 ) ;
if ( F_42 ( V_20 ) && ! F_43 ( V_20 ) ) {
T_3 V_59 = F_13 ( V_124 ) ;
F_7 ( V_124 , ( V_59 & ~ 0xf ) | 0xd ) ;
}
}
