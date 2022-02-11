static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 ) -> V_3 . V_3 . V_4 ;
}
static void
F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
V_8 = F_4 ( V_4 ) ? V_9 : V_10 ;
F_5 ( F_6 ( V_2 -> V_11 ) & V_8 ,
L_1 ) ;
}
struct V_2 * F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 =
F_8 ( V_13 , struct V_14 , V_3 . V_3 ) ;
return & V_15 -> V_16 ;
}
static struct V_2 * F_9 ( struct V_17 * V_18 )
{
return F_7 ( & F_10 ( V_18 ) -> V_3 ) ;
}
void F_11 ( struct V_19 * V_20 )
{
T_2 * V_21 = ( T_2 * ) V_20 ;
T_2 V_22 = 0 ;
unsigned V_23 ;
V_20 -> V_24 = 0 ;
V_20 -> V_25 = 0 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_26 + V_27 ; V_23 ++ )
V_22 += V_21 [ V_23 ] ;
V_20 -> V_24 = 0x100 - V_22 ;
}
static T_3 F_12 ( struct V_19 * V_20 )
{
switch ( V_20 -> type ) {
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
default:
F_13 ( L_2 , V_20 -> type ) ;
return 0 ;
}
}
static T_3 F_14 ( struct V_19 * V_20 )
{
switch ( V_20 -> type ) {
case V_28 :
return V_32 ;
case V_30 :
return V_33 ;
default:
F_13 ( L_2 , V_20 -> type ) ;
return 0 ;
}
}
static T_3 F_15 ( struct V_19 * V_20 )
{
switch ( V_20 -> type ) {
case V_28 :
return V_34 ;
case V_30 :
return V_35 ;
default:
F_13 ( L_2 , V_20 -> type ) ;
return 0 ;
}
}
static T_3 F_16 ( struct V_19 * V_20 ,
enum V_36 V_37 )
{
switch ( V_20 -> type ) {
case V_28 :
return F_17 ( V_37 ) ;
case V_30 :
return F_18 ( V_37 ) ;
default:
F_13 ( L_2 , V_20 -> type ) ;
return 0 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_3 V_38 = F_6 ( V_39 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( V_20 ) ;
V_38 &= ~ F_14 ( V_20 ) ;
F_20 ( V_39 , V_38 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( V_42 , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_43 ; V_23 += 4 )
F_20 ( V_42 , 0 ) ;
F_21 () ;
V_38 |= F_14 ( V_20 ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_39 , V_38 ) ;
F_22 ( V_39 ) ;
}
static void F_23 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_48 = F_25 ( V_46 -> V_49 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_38 = F_6 ( V_48 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( V_20 ) ;
V_38 &= ~ F_14 ( V_20 ) ;
F_20 ( V_48 , V_38 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_26 ( V_46 -> V_49 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_43 ; V_23 += 4 )
F_20 ( F_26 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_38 |= F_14 ( V_20 ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_48 = F_25 ( V_46 -> V_49 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_38 = F_6 ( V_48 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( V_20 ) ;
if ( V_20 -> type != V_28 )
V_38 &= ~ F_14 ( V_20 ) ;
F_20 ( V_48 , V_38 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_26 ( V_46 -> V_49 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_43 ; V_23 += 4 )
F_20 ( F_26 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_38 |= F_14 ( V_20 ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
}
static void F_28 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_48 = F_29 ( V_46 -> V_49 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_38 = F_6 ( V_48 ) ;
F_5 ( ! ( V_38 & V_40 ) , L_3 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( V_20 ) ;
V_38 &= ~ F_14 ( V_20 ) ;
F_20 ( V_48 , V_38 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_30 ( V_46 -> V_49 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_43 ; V_23 += 4 )
F_20 ( F_30 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_38 |= F_14 ( V_20 ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
T_3 V_50 = F_32 ( V_46 -> V_51 . V_37 ) ;
T_3 V_52 = F_16 ( V_20 , V_46 -> V_51 . V_37 ) ;
unsigned int V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_38 = F_6 ( V_50 ) ;
if ( V_52 == 0 )
return;
V_38 &= ~ F_15 ( V_20 ) ;
F_20 ( V_50 , V_38 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( V_52 + V_23 , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_43 ; V_23 += 4 )
F_20 ( V_52 + V_23 , 0 ) ;
F_21 () ;
V_38 |= F_15 ( V_20 ) ;
F_20 ( V_50 , V_38 ) ;
F_22 ( V_50 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
F_11 ( V_20 ) ;
V_2 -> V_53 ( V_13 , V_20 ) ;
}
static void F_34 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_19 V_56 = {
. type = V_28 ,
. V_57 = V_58 ,
. V_26 = V_59 ,
} ;
if ( V_55 -> V_60 & V_61 )
V_56 . V_62 . V_63 . V_64 |= V_65 ;
if ( V_2 -> V_66 ) {
if ( V_46 -> V_51 . V_67 )
V_56 . V_62 . V_63 . V_68 |= V_69 ;
else
V_56 . V_62 . V_63 . V_68 |= V_70 ;
}
V_56 . V_62 . V_63 . V_71 = F_35 ( V_55 ) ;
F_33 ( V_13 , & V_56 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
struct V_19 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . type = V_30 ;
V_72 . V_57 = V_73 ;
V_72 . V_26 = V_74 ;
strcpy ( V_72 . V_62 . V_75 . V_76 , L_4 ) ;
strcpy ( V_72 . V_62 . V_75 . V_77 , L_5 ) ;
V_72 . V_62 . V_75 . V_78 = V_79 ;
F_33 ( V_13 , & V_72 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_38 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_48 = V_39 ;
T_3 V_38 = F_6 ( V_48 ) ;
T_3 V_80 ;
F_3 ( V_2 ) ;
V_38 |= V_29 | V_45 ;
if ( ! V_2 -> V_81 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ V_40 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
return;
}
switch ( V_15 -> V_80 ) {
case V_82 :
V_80 = V_83 ;
break;
case V_84 :
V_80 = V_85 ;
break;
default:
F_39 () ;
return;
}
if ( V_80 != ( V_38 & V_86 ) ) {
if ( V_38 & V_40 ) {
V_38 &= ~ V_40 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
}
V_38 &= ~ V_86 ;
V_38 |= V_80 ;
}
V_38 |= V_40 ;
V_38 &= ~ V_87 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
F_34 ( V_13 , V_55 ) ;
F_36 ( V_13 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_14 * V_15 = F_38 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_48 = F_25 ( V_46 -> V_49 ) ;
T_3 V_38 = F_6 ( V_48 ) ;
T_3 V_80 ;
F_3 ( V_2 ) ;
V_38 |= V_29 | V_45 ;
if ( ! V_2 -> V_81 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ V_40 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
return;
}
switch ( V_15 -> V_80 ) {
case V_82 :
V_80 = V_83 ;
break;
case V_84 :
V_80 = V_85 ;
break;
case V_88 :
V_80 = V_89 ;
break;
default:
F_39 () ;
return;
}
if ( V_80 != ( V_38 & V_86 ) ) {
if ( V_38 & V_40 ) {
V_38 &= ~ V_40 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
}
V_38 &= ~ V_86 ;
V_38 |= V_80 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_87 | V_90 |
V_91 ) ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
F_34 ( V_13 , V_55 ) ;
F_36 ( V_13 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_48 = F_25 ( V_46 -> V_49 ) ;
T_3 V_38 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
V_38 |= V_29 | V_45 ;
if ( ! V_2 -> V_81 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_32 ) ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
return;
}
V_38 |= V_40 | V_32 ;
V_38 &= ~ ( V_87 | V_90 |
V_91 ) ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
F_34 ( V_13 , V_55 ) ;
F_36 ( V_13 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_48 = F_29 ( V_46 -> V_49 ) ;
T_3 V_38 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
V_38 |= V_29 | V_45 ;
if ( ! V_2 -> V_81 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ V_40 ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
return;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_87 | V_90 |
V_91 ) ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
F_34 ( V_13 , V_55 ) ;
F_36 ( V_13 ) ;
}
static void F_43 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_48 = F_32 ( V_46 -> V_51 . V_37 ) ;
T_3 V_38 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_81 ) {
F_20 ( V_48 , 0 ) ;
F_22 ( V_48 ) ;
return;
}
V_38 &= ~ ( V_92 | V_93 |
V_94 | V_95 ) ;
F_20 ( V_48 , V_38 ) ;
F_22 ( V_48 ) ;
F_34 ( V_13 , V_55 ) ;
F_36 ( V_13 ) ;
}
static void F_44 ( struct V_12 * V_13 ,
struct V_54 * V_96 ,
struct V_54 * V_55 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_97 ;
V_97 = V_98 ;
if ( ! F_45 ( V_4 ) && ! F_46 ( V_4 ) )
V_97 |= V_2 -> V_99 ;
if ( V_55 -> V_60 & V_100 )
V_97 |= V_101 ;
if ( V_55 -> V_60 & V_102 )
V_97 |= V_103 ;
if ( V_46 -> V_51 . V_104 > 24 )
V_97 |= V_105 ;
else
V_97 |= V_106 ;
if ( V_2 -> V_81 && F_47 ( V_4 ) )
V_97 |= V_107 ;
if ( V_2 -> V_108 ) {
F_13 ( L_6 ,
F_48 ( V_46 -> V_49 ) ) ;
V_97 |= V_109 ;
V_97 |= V_107 ;
F_49 ( V_13 , V_55 ) ;
}
if ( F_47 ( V_4 ) )
V_97 |= F_50 ( V_46 -> V_49 ) ;
else
V_97 |= F_51 ( V_46 -> V_49 ) ;
F_20 ( V_2 -> V_11 , V_97 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_110 ( V_13 , V_55 ) ;
}
static bool F_52 ( struct V_111 * V_13 ,
enum V_49 * V_49 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_112 ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_112 & V_10 ) )
return false ;
if ( F_47 ( V_4 ) )
* V_49 = F_53 ( V_112 ) ;
else
* V_49 = F_54 ( V_112 ) ;
return true ;
}
static void F_55 ( struct V_111 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_113 ;
T_3 V_114 = V_10 ;
if ( V_2 -> V_108 )
V_114 |= V_109 ;
V_113 = F_6 ( V_2 -> V_11 ) ;
if ( F_56 ( V_4 ) )
V_114 |= F_51 ( V_46 -> V_49 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_113 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_113 |= V_114 ;
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_57 ( struct V_111 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_113 ;
T_3 V_114 = V_10 | V_109 ;
V_113 = F_6 ( V_2 -> V_11 ) ;
if ( F_56 ( V_4 ) ) {
struct V_115 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_113 & V_116 ) {
V_113 &= ~ V_116 ;
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_58 ( V_4 , V_49 ) ;
else
F_59 ( 50 ) ;
}
}
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_113 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_113 &= ~ V_114 ;
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_113 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_60 ( struct V_17 * V_18 ,
struct V_54 * V_96 )
{
if ( V_96 -> clock > 165000 )
return V_117 ;
if ( V_96 -> clock < 20000 )
return V_118 ;
if ( V_96 -> V_60 & V_119 )
return V_120 ;
return V_121 ;
}
bool F_61 ( struct V_111 * V_13 ,
struct V_122 * V_123 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_54 * V_55 = & V_123 -> V_55 ;
if ( V_2 -> V_124 ) {
if ( V_2 -> V_81 &&
F_35 ( V_55 ) > 1 )
V_2 -> V_99 = V_125 ;
else
V_2 -> V_99 = 0 ;
}
if ( V_2 -> V_99 )
V_123 -> V_67 = true ;
if ( F_45 ( V_4 ) && ! F_4 ( V_4 ) )
V_123 -> V_126 = true ;
if ( V_123 -> V_104 > 8 * 3 && F_45 ( V_4 ) ) {
F_62 ( L_7 ) ;
V_123 -> V_104 = 12 * 3 ;
} else {
F_62 ( L_8 ) ;
V_123 -> V_104 = 8 * 3 ;
}
return true ;
}
static enum V_127
F_63 ( struct V_17 * V_18 , bool V_128 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_111 * V_111 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_129 * V_129 ;
enum V_127 V_130 = V_131 ;
V_2 -> V_81 = false ;
V_2 -> V_108 = false ;
V_2 -> V_66 = false ;
V_129 = F_64 ( V_18 ,
F_65 ( V_6 ,
V_2 -> V_132 ) ) ;
if ( V_129 ) {
if ( V_129 -> V_133 & V_134 ) {
V_130 = V_135 ;
if ( V_2 -> V_136 != V_137 )
V_2 -> V_81 =
F_66 ( V_129 ) ;
V_2 -> V_108 = F_67 ( V_129 ) ;
V_2 -> V_66 =
F_68 ( V_129 ) ;
}
F_69 ( V_129 ) ;
}
if ( V_130 == V_135 ) {
if ( V_2 -> V_136 != V_138 )
V_2 -> V_108 =
( V_2 -> V_136 == V_139 ) ;
V_111 -> type = V_140 ;
}
return V_130 ;
}
static int F_70 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_71 ( V_18 ,
F_65 ( V_6 ,
V_2 -> V_132 ) ) ;
}
static bool
F_72 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_129 * V_129 ;
bool V_108 = false ;
V_129 = F_64 ( V_18 ,
F_65 ( V_6 ,
V_2 -> V_132 ) ) ;
if ( V_129 ) {
if ( V_129 -> V_133 & V_134 )
V_108 = F_67 ( V_129 ) ;
F_69 ( V_129 ) ;
}
return V_108 ;
}
static int
F_73 ( struct V_17 * V_18 ,
struct V_141 * V_142 ,
T_4 V_38 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_143 ;
V_143 = F_74 ( & V_18 -> V_3 , V_142 , V_38 ) ;
if ( V_143 )
return V_143 ;
if ( V_142 == V_6 -> V_144 ) {
enum V_145 V_23 = V_38 ;
bool V_108 ;
if ( V_23 == V_2 -> V_136 )
return 0 ;
V_2 -> V_136 = V_23 ;
if ( V_23 == V_138 )
V_108 = F_72 ( V_18 ) ;
else
V_108 = ( V_23 == V_139 ) ;
if ( V_23 == V_137 )
V_2 -> V_81 = 0 ;
V_2 -> V_108 = V_108 ;
goto V_146;
}
if ( V_142 == V_6 -> V_147 ) {
bool V_148 = V_2 -> V_124 ;
T_1 V_149 = V_2 -> V_99 ;
switch ( V_38 ) {
case V_150 :
V_2 -> V_124 = true ;
break;
case V_151 :
V_2 -> V_124 = false ;
V_2 -> V_99 = 0 ;
break;
case V_152 :
V_2 -> V_124 = false ;
V_2 -> V_99 = V_125 ;
break;
default:
return - V_153 ;
}
if ( V_148 == V_2 -> V_124 &&
V_149 == V_2 -> V_99 )
return 0 ;
goto V_146;
}
return - V_153 ;
V_146:
if ( V_15 -> V_3 . V_3 . V_47 )
F_75 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_76 ( struct V_17 * V_18 )
{
F_77 ( V_18 ) ;
F_78 ( V_18 ) ;
F_69 ( V_18 ) ;
}
static void
F_79 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_80 ( V_18 ) ;
F_81 ( V_18 ) ;
V_2 -> V_124 = true ;
}
void F_82 ( struct V_14 * V_15 ,
struct V_154 * V_154 )
{
struct V_17 * V_18 = & V_154 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_111 * V_111 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_111 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_80 V_80 = V_15 -> V_80 ;
F_83 ( V_4 , V_18 , & V_155 ,
V_156 ) ;
F_84 ( V_18 , & V_157 ) ;
V_18 -> V_158 = 1 ;
V_18 -> V_159 = 0 ;
switch ( V_80 ) {
case V_82 :
V_2 -> V_132 = V_160 ;
V_111 -> V_161 = V_162 ;
break;
case V_84 :
V_2 -> V_132 = V_163 ;
V_111 -> V_161 = V_164 ;
break;
case V_88 :
V_2 -> V_132 = V_165 ;
V_111 -> V_161 = V_166 ;
break;
case V_167 :
V_111 -> V_161 = V_168 ;
default:
F_39 () ;
}
if ( F_46 ( V_4 ) ) {
V_2 -> V_53 = F_28 ;
V_2 -> V_110 = F_42 ;
} else if ( ! F_45 ( V_4 ) ) {
V_2 -> V_53 = F_19 ;
V_2 -> V_110 = F_37 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_53 = F_31 ;
V_2 -> V_110 = F_43 ;
} else if ( F_56 ( V_4 ) ) {
V_2 -> V_53 = F_23 ;
V_2 -> V_110 = F_40 ;
} else {
V_2 -> V_53 = F_27 ;
V_2 -> V_110 = F_41 ;
}
if ( F_4 ( V_4 ) )
V_154 -> V_169 = V_170 ;
else
V_154 -> V_169 = V_171 ;
F_79 ( V_2 , V_18 ) ;
F_85 ( V_154 , V_111 ) ;
F_86 ( V_18 ) ;
if ( F_87 ( V_4 ) && ! F_88 ( V_4 ) ) {
T_3 V_113 = F_6 ( V_172 ) ;
F_20 ( V_172 , ( V_113 & ~ 0xf ) | 0xd ) ;
}
}
void F_89 ( struct V_1 * V_4 , int V_11 , enum V_80 V_80 )
{
struct V_14 * V_15 ;
struct V_111 * V_111 ;
struct V_12 * V_13 ;
struct V_154 * V_154 ;
V_15 = F_90 ( sizeof( struct V_14 ) , V_173 ) ;
if ( ! V_15 )
return;
V_154 = F_90 ( sizeof( struct V_154 ) , V_173 ) ;
if ( ! V_154 ) {
F_69 ( V_15 ) ;
return;
}
V_111 = & V_15 -> V_3 ;
V_13 = & V_111 -> V_3 ;
F_91 ( V_4 , & V_111 -> V_3 , & V_174 ,
V_175 ) ;
F_92 ( & V_111 -> V_3 , & V_176 ) ;
V_111 -> V_177 = F_61 ;
V_111 -> V_178 = F_55 ;
V_111 -> V_179 = F_57 ;
V_111 -> V_169 = F_52 ;
V_111 -> type = V_140 ;
V_111 -> V_180 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_111 -> V_181 = false ;
V_15 -> V_80 = V_80 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_182 . V_183 = 0 ;
F_82 ( V_15 , V_154 ) ;
}
