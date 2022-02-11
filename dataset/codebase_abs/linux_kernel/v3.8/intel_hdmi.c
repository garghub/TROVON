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
struct V_19 V_53 = {
. type = V_28 ,
. V_54 = V_55 ,
. V_26 = V_56 ,
} ;
if ( V_52 -> V_57 & V_58 )
V_53 . V_59 . V_60 . V_61 |= V_62 ;
V_53 . V_59 . V_60 . V_63 = F_35 ( V_52 ) ;
F_33 ( V_13 , & V_53 ) ;
}
static void F_36 ( struct V_12 * V_13 )
{
struct V_19 V_64 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . type = V_30 ;
V_64 . V_54 = V_65 ;
V_64 . V_26 = V_66 ;
strcpy ( V_64 . V_59 . V_67 . V_68 , L_4 ) ;
strcpy ( V_64 . V_59 . V_67 . V_69 , L_5 ) ;
V_64 . V_59 . V_67 . V_70 = V_71 ;
F_33 ( V_13 , & V_64 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = V_38 ;
T_3 V_37 = F_6 ( V_47 ) ;
T_3 V_72 ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_73 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
switch ( V_2 -> V_11 ) {
case V_74 :
V_72 = V_75 ;
break;
case V_76 :
V_72 = V_77 ;
break;
default:
F_38 () ;
return;
}
if ( V_72 != ( V_37 & V_78 ) ) {
if ( V_37 & V_39 ) {
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
V_37 &= ~ V_78 ;
V_37 |= V_72 ;
}
V_37 |= V_39 ;
V_37 &= ~ V_79 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = F_25 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
T_3 V_72 ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_73 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
switch ( V_2 -> V_11 ) {
case V_80 :
V_72 = V_75 ;
break;
case V_81 :
V_72 = V_77 ;
break;
case V_82 :
V_72 = V_83 ;
break;
default:
F_38 () ;
return;
}
if ( V_72 != ( V_37 & V_78 ) ) {
if ( V_37 & V_39 ) {
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
}
V_37 &= ~ V_78 ;
V_37 |= V_72 ;
}
V_37 |= V_39 ;
V_37 &= ~ ( V_79 | V_84 |
V_85 ) ;
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
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_47 = F_25 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_73 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ ( V_39 | V_32 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 |= V_39 | V_32 ;
V_37 &= ~ ( V_79 | V_84 |
V_85 ) ;
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
T_3 V_47 = F_29 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
V_37 |= V_29 | V_44 ;
if ( ! V_2 -> V_73 ) {
if ( ! ( V_37 & V_39 ) )
return;
V_37 &= ~ V_39 ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 |= V_39 ;
V_37 &= ~ ( V_79 | V_84 |
V_85 ) ;
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
T_3 V_47 = F_32 ( V_45 -> V_36 ) ;
T_3 V_37 = F_6 ( V_47 ) ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_73 ) {
F_20 ( V_47 , 0 ) ;
F_22 ( V_47 ) ;
return;
}
V_37 &= ~ ( V_86 | V_87 |
V_88 | V_89 ) ;
F_20 ( V_47 , V_37 ) ;
F_22 ( V_47 ) ;
F_34 ( V_13 , V_52 ) ;
F_36 ( V_13 ) ;
}
static void F_43 ( struct V_12 * V_13 ,
struct V_51 * V_90 ,
struct V_51 * V_52 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_45 = F_24 ( V_13 -> V_46 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_91 ;
V_91 = V_92 ;
if ( ! F_44 ( V_4 ) )
V_91 |= V_2 -> V_93 ;
if ( V_52 -> V_57 & V_94 )
V_91 |= V_95 ;
if ( V_52 -> V_57 & V_96 )
V_91 |= V_97 ;
if ( V_45 -> V_98 > 24 )
V_91 |= V_99 ;
else
V_91 |= V_100 ;
if ( V_2 -> V_73 && F_45 ( V_4 ) )
V_91 |= V_101 ;
if ( V_2 -> V_102 ) {
F_13 ( L_6 ,
F_46 ( V_45 -> V_36 ) ) ;
V_91 |= V_103 ;
V_91 |= V_104 ;
F_47 ( V_13 , V_52 ) ;
}
if ( F_45 ( V_4 ) )
V_91 |= F_48 ( V_45 -> V_36 ) ;
else if ( V_45 -> V_36 == V_105 )
V_91 |= V_106 ;
F_20 ( V_2 -> V_11 , V_91 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_107 ( V_13 , V_52 ) ;
}
static bool F_49 ( struct V_108 * V_13 ,
enum V_36 * V_36 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_109 ;
V_109 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_109 & V_10 ) )
return false ;
if ( F_45 ( V_4 ) )
* V_36 = F_50 ( V_109 ) ;
else
* V_36 = F_51 ( V_109 ) ;
return true ;
}
static void F_52 ( struct V_108 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_110 ;
T_3 V_111 = V_10 ;
if ( V_2 -> V_102 )
V_111 |= V_103 ;
V_110 = F_6 ( V_2 -> V_11 ) ;
if ( F_53 ( V_4 ) ) {
struct V_112 * V_46 = V_13 -> V_3 . V_46 ;
int V_36 = V_46 ? F_24 ( V_46 ) -> V_36 : - 1 ;
if ( V_36 == V_105 )
V_111 |= V_106 ;
}
if ( F_44 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_110 |= V_111 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_44 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_54 ( struct V_108 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_110 ;
T_3 V_111 = V_10 | V_103 ;
V_110 = F_6 ( V_2 -> V_11 ) ;
if ( F_53 ( V_4 ) ) {
struct V_112 * V_46 = V_13 -> V_3 . V_46 ;
int V_36 = V_46 ? F_24 ( V_46 ) -> V_36 : - 1 ;
if ( V_110 & V_106 ) {
V_110 &= ~ V_106 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_46 )
F_55 ( V_4 , V_36 ) ;
else
F_56 ( 50 ) ;
}
}
if ( F_44 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_110 &= ~ V_111 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_44 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_57 ( struct V_17 * V_18 ,
struct V_51 * V_90 )
{
if ( V_90 -> clock > 165000 )
return V_113 ;
if ( V_90 -> clock < 20000 )
return V_114 ;
if ( V_90 -> V_57 & V_115 )
return V_116 ;
return V_117 ;
}
bool F_58 ( struct V_12 * V_13 ,
const struct V_51 * V_90 ,
struct V_51 * V_52 )
{
return true ;
}
static bool F_59 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_118 ;
switch ( V_2 -> V_11 ) {
case V_74 :
V_118 = V_119 ;
break;
case V_76 :
V_118 = V_120 ;
break;
default:
V_118 = 0 ;
break;
}
return F_6 ( V_121 ) & V_118 ;
}
static enum V_122
F_60 ( struct V_17 * V_18 , bool V_123 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_108 * V_108 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_124 * V_124 ;
enum V_122 V_125 = V_126 ;
if ( F_61 ( V_18 -> V_4 ) && ! F_59 ( V_2 ) )
return V_125 ;
V_2 -> V_73 = false ;
V_2 -> V_102 = false ;
V_124 = F_62 ( V_18 ,
F_63 ( V_6 ,
V_2 -> V_127 ) ) ;
if ( V_124 ) {
if ( V_124 -> V_128 & V_129 ) {
V_125 = V_130 ;
if ( V_2 -> V_131 != V_132 )
V_2 -> V_73 =
F_64 ( V_124 ) ;
V_2 -> V_102 = F_65 ( V_124 ) ;
}
F_66 ( V_124 ) ;
}
if ( V_125 == V_130 ) {
if ( V_2 -> V_131 != V_133 )
V_2 -> V_102 =
( V_2 -> V_131 == V_134 ) ;
V_108 -> type = V_135 ;
}
return V_125 ;
}
static int F_67 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_68 ( V_18 ,
F_63 ( V_6 ,
V_2 -> V_127 ) ) ;
}
static bool
F_69 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_124 * V_124 ;
bool V_102 = false ;
V_124 = F_62 ( V_18 ,
F_63 ( V_6 ,
V_2 -> V_127 ) ) ;
if ( V_124 ) {
if ( V_124 -> V_128 & V_129 )
V_102 = F_65 ( V_124 ) ;
F_66 ( V_124 ) ;
}
return V_102 ;
}
static int
F_70 ( struct V_17 * V_18 ,
struct V_136 * V_137 ,
T_4 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_138 ;
V_138 = F_71 ( & V_18 -> V_3 , V_137 , V_37 ) ;
if ( V_138 )
return V_138 ;
if ( V_137 == V_6 -> V_139 ) {
enum V_140 V_23 = V_37 ;
bool V_102 ;
if ( V_23 == V_2 -> V_131 )
return 0 ;
V_2 -> V_131 = V_23 ;
if ( V_23 == V_133 )
V_102 = F_69 ( V_18 ) ;
else
V_102 = ( V_23 == V_134 ) ;
if ( V_23 == V_132 )
V_2 -> V_73 = 0 ;
V_2 -> V_102 = V_102 ;
goto V_141;
}
if ( V_137 == V_6 -> V_142 ) {
if ( V_37 == ! ! V_2 -> V_93 )
return 0 ;
V_2 -> V_93 = V_37 ? V_143 : 0 ;
goto V_141;
}
return - V_144 ;
V_141:
if ( V_15 -> V_3 . V_3 . V_46 ) {
struct V_112 * V_46 = V_15 -> V_3 . V_3 . V_46 ;
F_72 ( V_46 , & V_46 -> V_90 ,
V_46 -> V_145 , V_46 -> V_146 , V_46 -> V_147 ) ;
}
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
}
void F_79 ( struct V_14 * V_15 ,
struct V_148 * V_148 )
{
struct V_17 * V_18 = & V_148 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_108 * V_108 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_108 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_72 V_72 = V_15 -> V_72 ;
F_80 ( V_4 , V_18 , & V_149 ,
V_150 ) ;
F_81 ( V_18 , & V_151 ) ;
V_18 -> V_152 = V_153 ;
V_18 -> V_154 = 1 ;
V_18 -> V_155 = 0 ;
switch ( V_72 ) {
case V_156 :
V_2 -> V_127 = V_157 ;
V_6 -> V_158 |= V_159 ;
break;
case V_160 :
V_2 -> V_127 = V_161 ;
V_6 -> V_158 |= V_162 ;
break;
case V_163 :
V_2 -> V_127 = V_164 ;
V_6 -> V_158 |= V_165 ;
break;
case V_166 :
default:
F_38 () ;
}
if ( ! F_44 ( V_4 ) ) {
V_2 -> V_50 = F_19 ;
V_2 -> V_107 = F_37 ;
} else if ( F_82 ( V_4 ) ) {
V_2 -> V_50 = F_28 ;
V_2 -> V_107 = F_41 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_50 = F_31 ;
V_2 -> V_107 = F_42 ;
} else if ( F_53 ( V_4 ) ) {
V_2 -> V_50 = F_23 ;
V_2 -> V_107 = F_39 ;
} else {
V_2 -> V_50 = F_27 ;
V_2 -> V_107 = F_40 ;
}
if ( F_4 ( V_4 ) )
V_148 -> V_167 = V_168 ;
else
V_148 -> V_167 = V_169 ;
F_76 ( V_2 , V_18 ) ;
F_83 ( V_148 , V_108 ) ;
F_84 ( V_18 ) ;
if ( F_61 ( V_4 ) && ! F_85 ( V_4 ) ) {
T_3 V_110 = F_6 ( V_170 ) ;
F_20 ( V_170 , ( V_110 & ~ 0xf ) | 0xd ) ;
}
}
void F_86 ( struct V_1 * V_4 , int V_11 , enum V_72 V_72 )
{
struct V_14 * V_15 ;
struct V_108 * V_108 ;
struct V_12 * V_13 ;
struct V_148 * V_148 ;
V_15 = F_87 ( sizeof( struct V_14 ) , V_171 ) ;
if ( ! V_15 )
return;
V_148 = F_87 ( sizeof( struct V_148 ) , V_171 ) ;
if ( ! V_148 ) {
F_66 ( V_15 ) ;
return;
}
V_108 = & V_15 -> V_3 ;
V_13 = & V_108 -> V_3 ;
F_88 ( V_4 , & V_108 -> V_3 , & V_172 ,
V_173 ) ;
F_89 ( & V_108 -> V_3 , & V_174 ) ;
V_108 -> V_175 = F_52 ;
V_108 -> V_176 = F_54 ;
V_108 -> V_167 = F_49 ;
V_108 -> type = V_135 ;
V_108 -> V_177 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_108 -> V_178 = false ;
V_15 -> V_72 = V_72 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_179 . V_180 = 0 ;
F_79 ( V_15 , V_148 ) ;
}
