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
static T_3 F_16 ( struct V_19 * V_20 , enum V_36 V_36 )
{
switch ( V_20 -> type ) {
case V_28 :
return F_17 ( V_36 ) ;
case V_30 :
return F_18 ( V_36 ) ;
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
T_3 V_37 = F_6 ( V_38 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
F_5 ( ! ( V_37 & V_39 ) , L_3 ) ;
V_37 &= ~ ( V_40 | 0xf ) ;
V_37 |= F_12 ( V_20 ) ;
V_37 &= ~ F_14 ( V_20 ) ;
F_20 ( V_38 , V_37 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( V_41 , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_42 ; V_23 += 4 )
F_20 ( V_41 , 0 ) ;
F_21 () ;
V_37 |= F_14 ( V_20 ) ;
V_37 &= ~ V_43 ;
V_37 |= V_44 ;
F_20 ( V_38 , V_37 ) ;
F_22 ( V_38 ) ;
}
static void F_23 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
int V_47 = F_25 ( V_45 -> V_36 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_37 = F_6 ( V_47 ) ;
F_5 ( ! ( V_37 & V_39 ) , L_3 ) ;
V_37 &= ~ ( V_40 | 0xf ) ;
V_37 |= F_12 ( V_20 ) ;
V_37 &= ~ F_14 ( V_20 ) ;
F_20 ( V_47 , V_37 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_26 ( V_45 -> V_36 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_42 ; V_23 += 4 )
F_20 ( F_26 ( V_45 -> V_36 ) , 0 ) ;
F_21 () ;
V_37 |= F_14 ( V_20 ) ;
V_37 &= ~ V_43 ;
V_37 |= V_44 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
int V_47 = F_25 ( V_45 -> V_36 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_37 = F_6 ( V_47 ) ;
F_5 ( ! ( V_37 & V_39 ) , L_3 ) ;
V_37 &= ~ ( V_40 | 0xf ) ;
V_37 |= F_12 ( V_20 ) ;
if ( V_20 -> type != V_28 )
V_37 &= ~ F_14 ( V_20 ) ;
F_20 ( V_47 , V_37 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_26 ( V_45 -> V_36 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_42 ; V_23 += 4 )
F_20 ( F_26 ( V_45 -> V_36 ) , 0 ) ;
F_21 () ;
V_37 |= F_14 ( V_20 ) ;
V_37 &= ~ V_43 ;
V_37 |= V_44 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
static void F_28 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
int V_47 = F_29 ( V_45 -> V_36 ) ;
unsigned V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_37 = F_6 ( V_47 ) ;
F_5 ( ! ( V_37 & V_39 ) , L_3 ) ;
V_37 &= ~ ( V_40 | 0xf ) ;
V_37 |= F_12 ( V_20 ) ;
V_37 &= ~ F_14 ( V_20 ) ;
F_20 ( V_47 , V_37 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( F_30 ( V_45 -> V_36 ) , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_42 ; V_23 += 4 )
F_20 ( F_30 ( V_45 -> V_36 ) , 0 ) ;
F_21 () ;
V_37 |= F_14 ( V_20 ) ;
V_37 &= ~ V_43 ;
V_37 |= V_44 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
T_1 * V_21 = ( T_1 * ) V_20 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
T_3 V_48 = F_32 ( V_45 -> V_36 ) ;
T_3 V_49 = F_16 ( V_20 , V_45 -> V_36 ) ;
unsigned int V_23 , V_26 = V_27 + V_20 -> V_26 ;
T_3 V_37 = F_6 ( V_48 ) ;
if ( V_49 == 0 )
return;
V_37 &= ~ F_15 ( V_20 ) ;
F_20 ( V_48 , V_37 ) ;
F_21 () ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 4 ) {
F_20 ( V_49 + V_23 , * V_21 ) ;
V_21 ++ ;
}
for (; V_23 < V_42 ; V_23 += 4 )
F_20 ( V_49 + V_23 , 0 ) ;
F_21 () ;
V_37 |= F_15 ( V_20 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
struct V_19 * V_20 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
F_11 ( V_20 ) ;
V_2 -> V_50 ( V_13 , V_20 ) ;
}
static void F_34 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_19 V_53 = {
. type = V_28 ,
. V_54 = V_55 ,
. V_26 = V_56 ,
} ;
if ( V_52 -> V_57 & V_58 )
V_53 . V_59 . V_60 . V_61 |= V_62 ;
if ( V_2 -> V_63 ) {
if ( V_52 -> V_64 & V_65 )
V_53 . V_59 . V_60 . V_66 |= V_67 ;
else
V_53 . V_59 . V_60 . V_66 |= V_68 ;
}
V_53 . V_59 . V_60 . V_69 = F_35 ( V_52 ) ;
F_33 ( V_13 , & V_53 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
struct V_19 V_70 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . type = V_30 ;
V_70 . V_54 = V_71 ;
V_70 . V_26 = V_72 ;
strcpy ( V_70 . V_59 . V_73 . V_74 , L_4 ) ;
strcpy ( V_70 . V_59 . V_73 . V_75 , L_5 ) ;
V_70 . V_59 . V_73 . V_76 = V_77 ;
F_33 ( V_13 , & V_70 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_38 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_47 = V_38 ;
T_3 V_37 = F_6 ( V_47 ) ;
T_3 V_78 ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_79 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
switch ( V_15 -> V_78 ) {
case V_80 :
V_78 = V_81 ;
break;
case V_82 :
V_78 = V_83 ;
break;
default:
F_39 () ;
return;
}
if ( V_78 != ( V_37 & V_84 ) ) {
if ( V_37 & V_39 ) {
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
V_37 &= ~ V_84 ;
V_37 |= V_78 ;
}
V_37 |= V_39 ;
V_37 &= ~ V_85 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_14 * V_15 = F_38 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_47 = F_25 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
T_3 V_78 ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_79 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
switch ( V_15 -> V_78 ) {
case V_80 :
V_78 = V_81 ;
break;
case V_82 :
V_78 = V_83 ;
break;
case V_86 :
V_78 = V_87 ;
break;
default:
F_39 () ;
return;
}
if ( V_78 != ( V_37 & V_84 ) ) {
if ( V_37 & V_39 ) {
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
V_37 &= ~ V_84 ;
V_37 |= V_78 ;
}
V_37 |= V_39 ;
V_37 &= ~ ( V_85 | V_88 |
V_89 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = F_25 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_79 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ ( V_39 | V_32 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 |= V_39 | V_32 ;
V_37 &= ~ ( V_85 | V_88 |
V_89 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = F_29 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_79 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 |= V_39 ;
V_37 &= ~ ( V_85 | V_88 |
V_89 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_43 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = F_32 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_79 ) {
F_20 ( V_47 , 0 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 &= ~ ( V_90 | V_91 |
V_92 | V_93 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_44 ( struct V_12 * V_13 ,
struct V_51 * V_94 ,
struct V_51 * V_52 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_95 ;
V_95 = V_96 ;
if ( ! F_45 ( V_4 ) )
V_95 |= V_2 -> V_97 ;
if ( V_52 -> V_57 & V_98 )
V_95 |= V_99 ;
if ( V_52 -> V_57 & V_100 )
V_95 |= V_101 ;
if ( V_45 -> V_102 > 24 )
V_95 |= V_103 ;
else
V_95 |= V_104 ;
if ( V_2 -> V_79 && F_46 ( V_4 ) )
V_95 |= V_105 ;
if ( V_2 -> V_106 ) {
F_13 ( L_6 ,
F_47 ( V_45 -> V_36 ) ) ;
V_95 |= V_107 ;
V_95 |= V_108 ;
F_48 ( V_13 , V_52 ) ;
}
if ( F_46 ( V_4 ) )
V_95 |= F_49 ( V_45 -> V_36 ) ;
else if ( V_45 -> V_36 == V_109 )
V_95 |= V_110 ;
F_20 ( V_2 -> V_11 , V_95 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_111 ( V_13 , V_52 ) ;
}
static bool F_50 ( struct V_112 * V_13 ,
enum V_36 * V_36 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_113 ;
V_113 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_113 & V_10 ) )
return false ;
if ( F_46 ( V_4 ) )
* V_36 = F_51 ( V_113 ) ;
else
* V_36 = F_52 ( V_113 ) ;
return true ;
}
static void F_53 ( struct V_112 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_114 ;
T_3 V_115 = V_10 ;
if ( V_2 -> V_106 )
V_115 |= V_107 ;
V_114 = F_6 ( V_2 -> V_11 ) ;
if ( F_54 ( V_4 ) ) {
struct V_116 * V_46 = V_13 -> V_3 . V_46 ;
int V_36 = V_46 ? F_24 ( V_46 ) -> V_36 : - 1 ;
if ( V_36 == V_109 )
V_115 |= V_110 ;
}
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_114 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_114 |= V_115 ;
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_55 ( struct V_112 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_114 ;
T_3 V_115 = V_10 | V_107 ;
V_114 = F_6 ( V_2 -> V_11 ) ;
if ( F_54 ( V_4 ) ) {
struct V_116 * V_46 = V_13 -> V_3 . V_46 ;
int V_36 = V_46 ? F_24 ( V_46 ) -> V_36 : - 1 ;
if ( V_114 & V_110 ) {
V_114 &= ~ V_110 ;
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_46 )
F_56 ( V_4 , V_36 ) ;
else
F_57 ( 50 ) ;
}
}
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_114 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_114 &= ~ V_115 ;
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_114 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_58 ( struct V_17 * V_18 ,
struct V_51 * V_94 )
{
if ( V_94 -> clock > 165000 )
return V_117 ;
if ( V_94 -> clock < 20000 )
return V_118 ;
if ( V_94 -> V_57 & V_119 )
return V_120 ;
return V_121 ;
}
bool F_59 ( struct V_12 * V_13 ,
const struct V_51 * V_94 ,
struct V_51 * V_52 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
if ( V_2 -> V_122 ) {
if ( V_2 -> V_79 &&
F_35 ( V_52 ) > 1 )
V_2 -> V_97 = V_123 ;
else
V_2 -> V_97 = 0 ;
}
if ( V_2 -> V_97 )
V_52 -> V_64 |= V_65 ;
return true ;
}
static enum V_124
F_60 ( struct V_17 * V_18 , bool V_125 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_112 * V_112 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_126 ;
enum V_124 V_127 = V_128 ;
V_2 -> V_79 = false ;
V_2 -> V_106 = false ;
V_2 -> V_63 = false ;
V_126 = F_61 ( V_18 ,
F_62 ( V_6 ,
V_2 -> V_129 ) ) ;
if ( V_126 ) {
if ( V_126 -> V_130 & V_131 ) {
V_127 = V_132 ;
if ( V_2 -> V_133 != V_134 )
V_2 -> V_79 =
F_63 ( V_126 ) ;
V_2 -> V_106 = F_64 ( V_126 ) ;
V_2 -> V_63 =
F_65 ( V_126 ) ;
}
F_66 ( V_126 ) ;
}
if ( V_127 == V_132 ) {
if ( V_2 -> V_133 != V_135 )
V_2 -> V_106 =
( V_2 -> V_133 == V_136 ) ;
V_112 -> type = V_137 ;
}
return V_127 ;
}
static int F_67 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_68 ( V_18 ,
F_62 ( V_6 ,
V_2 -> V_129 ) ) ;
}
static bool
F_69 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_126 * V_126 ;
bool V_106 = false ;
V_126 = F_61 ( V_18 ,
F_62 ( V_6 ,
V_2 -> V_129 ) ) ;
if ( V_126 ) {
if ( V_126 -> V_130 & V_131 )
V_106 = F_64 ( V_126 ) ;
F_66 ( V_126 ) ;
}
return V_106 ;
}
static int
F_70 ( struct V_17 * V_18 ,
struct V_138 * V_139 ,
T_4 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_140 ;
V_140 = F_71 ( & V_18 -> V_3 , V_139 , V_37 ) ;
if ( V_140 )
return V_140 ;
if ( V_139 == V_6 -> V_141 ) {
enum V_142 V_23 = V_37 ;
bool V_106 ;
if ( V_23 == V_2 -> V_133 )
return 0 ;
V_2 -> V_133 = V_23 ;
if ( V_23 == V_135 )
V_106 = F_69 ( V_18 ) ;
else
V_106 = ( V_23 == V_136 ) ;
if ( V_23 == V_134 )
V_2 -> V_79 = 0 ;
V_2 -> V_106 = V_106 ;
goto V_143;
}
if ( V_139 == V_6 -> V_144 ) {
switch ( V_37 ) {
case V_145 :
V_2 -> V_122 = true ;
break;
case V_146 :
V_2 -> V_122 = false ;
V_2 -> V_97 = 0 ;
break;
case V_147 :
V_2 -> V_122 = false ;
V_2 -> V_97 = V_123 ;
break;
default:
return - V_148 ;
}
goto V_143;
}
return - V_148 ;
V_143:
if ( V_15 -> V_3 . V_3 . V_46 )
F_72 ( V_15 -> V_3 . V_3 . V_46 ) ;
return 0 ;
}
static void F_73 ( struct V_17 * V_18 )
{
F_74 ( V_18 ) ;
F_75 ( V_18 ) ;
F_66 ( V_18 ) ;
}
static void
F_76 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_77 ( V_18 ) ;
F_78 ( V_18 ) ;
V_2 -> V_122 = true ;
}
void F_79 ( struct V_14 * V_15 ,
struct V_149 * V_149 )
{
struct V_17 * V_18 = & V_149 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_112 * V_112 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_112 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_78 V_78 = V_15 -> V_78 ;
F_80 ( V_4 , V_18 , & V_150 ,
V_151 ) ;
F_81 ( V_18 , & V_152 ) ;
V_18 -> V_153 = V_154 ;
V_18 -> V_155 = 1 ;
V_18 -> V_156 = 0 ;
switch ( V_78 ) {
case V_80 :
V_2 -> V_129 = V_157 ;
V_6 -> V_158 |= V_159 ;
break;
case V_82 :
V_2 -> V_129 = V_160 ;
V_6 -> V_158 |= V_161 ;
break;
case V_86 :
V_2 -> V_129 = V_162 ;
V_6 -> V_158 |= V_163 ;
break;
case V_164 :
default:
F_39 () ;
}
if ( ! F_45 ( V_4 ) ) {
V_2 -> V_50 = F_19 ;
V_2 -> V_111 = F_37 ;
} else if ( F_82 ( V_4 ) ) {
V_2 -> V_50 = F_28 ;
V_2 -> V_111 = F_42 ;
} else if ( F_83 ( V_4 ) ) {
V_2 -> V_50 = F_31 ;
V_2 -> V_111 = F_43 ;
} else if ( F_54 ( V_4 ) ) {
V_2 -> V_50 = F_23 ;
V_2 -> V_111 = F_40 ;
} else {
V_2 -> V_50 = F_27 ;
V_2 -> V_111 = F_41 ;
}
if ( F_4 ( V_4 ) )
V_149 -> V_165 = V_166 ;
else
V_149 -> V_165 = V_167 ;
F_76 ( V_2 , V_18 ) ;
F_84 ( V_149 , V_112 ) ;
F_85 ( V_18 ) ;
if ( F_86 ( V_4 ) && ! F_87 ( V_4 ) ) {
T_3 V_114 = F_6 ( V_168 ) ;
F_20 ( V_168 , ( V_114 & ~ 0xf ) | 0xd ) ;
}
}
void F_88 ( struct V_1 * V_4 , int V_11 , enum V_78 V_78 )
{
struct V_14 * V_15 ;
struct V_112 * V_112 ;
struct V_12 * V_13 ;
struct V_149 * V_149 ;
V_15 = F_89 ( sizeof( struct V_14 ) , V_169 ) ;
if ( ! V_15 )
return;
V_149 = F_89 ( sizeof( struct V_149 ) , V_169 ) ;
if ( ! V_149 ) {
F_66 ( V_15 ) ;
return;
}
V_112 = & V_15 -> V_3 ;
V_13 = & V_112 -> V_3 ;
F_90 ( V_4 , & V_112 -> V_3 , & V_170 ,
V_171 ) ;
F_91 ( & V_112 -> V_3 , & V_172 ) ;
V_112 -> V_173 = F_53 ;
V_112 -> V_174 = F_55 ;
V_112 -> V_165 = F_50 ;
V_112 -> type = V_137 ;
V_112 -> V_175 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_112 -> V_176 = false ;
V_15 -> V_78 = V_78 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_177 . V_178 = 0 ;
F_79 ( V_15 , V_149 ) ;
}
