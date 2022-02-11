static void
F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 . V_4 . V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
T_1 V_8 ;
V_8 = F_2 ( V_3 ) ? V_9 : V_10 ;
F_3 ( F_4 ( V_1 -> V_11 ) & V_8 ,
L_1 ) ;
}
struct V_1 * F_5 ( struct V_12 * V_13 )
{
return F_6 ( V_13 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_7 ( struct V_14 * V_15 )
{
return F_6 ( F_8 ( V_15 ) ,
struct V_1 , V_4 ) ;
}
void F_9 ( struct V_16 * V_17 )
{
T_2 * V_18 = ( T_2 * ) V_17 ;
T_2 V_19 = 0 ;
unsigned V_20 ;
V_17 -> V_21 = 0 ;
V_17 -> V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_23 + V_24 ; V_20 ++ )
V_19 += V_18 [ V_20 ] ;
V_17 -> V_21 = 0x100 - V_19 ;
}
static T_3 F_10 ( struct V_16 * V_17 )
{
switch ( V_17 -> type ) {
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
default:
F_11 ( L_2 , V_17 -> type ) ;
return 0 ;
}
}
static T_3 F_12 ( struct V_16 * V_17 )
{
switch ( V_17 -> type ) {
case V_25 :
return V_29 ;
case V_27 :
return V_30 ;
default:
F_11 ( L_2 , V_17 -> type ) ;
return 0 ;
}
}
static T_3 F_13 ( struct V_16 * V_17 )
{
switch ( V_17 -> type ) {
case V_25 :
return V_31 ;
case V_27 :
return V_32 ;
default:
F_11 ( L_2 , V_17 -> type ) ;
return 0 ;
}
}
static T_3 F_14 ( struct V_16 * V_17 , enum V_33 V_33 )
{
switch ( V_17 -> type ) {
case V_25 :
return F_15 ( V_33 ) ;
case V_27 :
return F_16 ( V_33 ) ;
default:
F_11 ( L_2 , V_17 -> type ) ;
return 0 ;
}
}
static void F_17 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
T_3 V_34 = F_4 ( V_35 ) ;
unsigned V_20 , V_23 = V_24 + V_17 -> V_23 ;
F_3 ( ! ( V_34 & V_36 ) , L_3 ) ;
V_34 &= ~ ( V_37 | 0xf ) ;
V_34 |= F_10 ( V_17 ) ;
V_34 &= ~ F_12 ( V_17 ) ;
F_18 ( V_35 , V_34 ) ;
F_19 () ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 += 4 ) {
F_18 ( V_38 , * V_18 ) ;
V_18 ++ ;
}
for (; V_20 < V_39 ; V_20 += 4 )
F_18 ( V_38 , 0 ) ;
F_19 () ;
V_34 |= F_12 ( V_17 ) ;
V_34 &= ~ V_40 ;
V_34 |= V_41 ;
F_18 ( V_35 , V_34 ) ;
F_20 ( V_35 ) ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
int V_44 = F_23 ( V_42 -> V_33 ) ;
unsigned V_20 , V_23 = V_24 + V_17 -> V_23 ;
T_3 V_34 = F_4 ( V_44 ) ;
F_3 ( ! ( V_34 & V_36 ) , L_3 ) ;
V_34 &= ~ ( V_37 | 0xf ) ;
V_34 |= F_10 ( V_17 ) ;
V_34 &= ~ F_12 ( V_17 ) ;
F_18 ( V_44 , V_34 ) ;
F_19 () ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 += 4 ) {
F_18 ( F_24 ( V_42 -> V_33 ) , * V_18 ) ;
V_18 ++ ;
}
for (; V_20 < V_39 ; V_20 += 4 )
F_18 ( F_24 ( V_42 -> V_33 ) , 0 ) ;
F_19 () ;
V_34 |= F_12 ( V_17 ) ;
V_34 &= ~ V_40 ;
V_34 |= V_41 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
}
static void F_25 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
int V_44 = F_23 ( V_42 -> V_33 ) ;
unsigned V_20 , V_23 = V_24 + V_17 -> V_23 ;
T_3 V_34 = F_4 ( V_44 ) ;
F_3 ( ! ( V_34 & V_36 ) , L_3 ) ;
V_34 &= ~ ( V_37 | 0xf ) ;
V_34 |= F_10 ( V_17 ) ;
if ( V_17 -> type != V_25 )
V_34 &= ~ F_12 ( V_17 ) ;
F_18 ( V_44 , V_34 ) ;
F_19 () ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 += 4 ) {
F_18 ( F_24 ( V_42 -> V_33 ) , * V_18 ) ;
V_18 ++ ;
}
for (; V_20 < V_39 ; V_20 += 4 )
F_18 ( F_24 ( V_42 -> V_33 ) , 0 ) ;
F_19 () ;
V_34 |= F_12 ( V_17 ) ;
V_34 &= ~ V_40 ;
V_34 |= V_41 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
}
static void F_26 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
int V_44 = F_27 ( V_42 -> V_33 ) ;
unsigned V_20 , V_23 = V_24 + V_17 -> V_23 ;
T_3 V_34 = F_4 ( V_44 ) ;
F_3 ( ! ( V_34 & V_36 ) , L_3 ) ;
V_34 &= ~ ( V_37 | 0xf ) ;
V_34 |= F_10 ( V_17 ) ;
V_34 &= ~ F_12 ( V_17 ) ;
F_18 ( V_44 , V_34 ) ;
F_19 () ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 += 4 ) {
F_18 ( F_28 ( V_42 -> V_33 ) , * V_18 ) ;
V_18 ++ ;
}
for (; V_20 < V_39 ; V_20 += 4 )
F_18 ( F_28 ( V_42 -> V_33 ) , 0 ) ;
F_19 () ;
V_34 |= F_12 ( V_17 ) ;
V_34 &= ~ V_40 ;
V_34 |= V_41 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
}
static void F_29 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
T_1 * V_18 = ( T_1 * ) V_17 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
T_3 V_45 = F_30 ( V_42 -> V_33 ) ;
T_3 V_46 = F_14 ( V_17 , V_42 -> V_33 ) ;
unsigned int V_20 , V_23 = V_24 + V_17 -> V_23 ;
T_3 V_34 = F_4 ( V_45 ) ;
if ( V_46 == 0 )
return;
V_34 &= ~ F_13 ( V_17 ) ;
F_18 ( V_45 , V_34 ) ;
F_19 () ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 += 4 ) {
F_18 ( V_46 + V_20 , * V_18 ) ;
V_18 ++ ;
}
for (; V_20 < V_39 ; V_20 += 4 )
F_18 ( V_46 + V_20 , 0 ) ;
F_19 () ;
V_34 |= F_13 ( V_17 ) ;
F_18 ( V_45 , V_34 ) ;
F_20 ( V_45 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
F_9 ( V_17 ) ;
V_1 -> V_47 ( V_13 , V_17 ) ;
}
static void F_32 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_16 V_50 = {
. type = V_25 ,
. V_51 = V_52 ,
. V_23 = V_53 ,
} ;
if ( V_49 -> V_54 & V_55 )
V_50 . V_56 . V_57 . V_58 |= V_59 ;
F_31 ( V_13 , & V_50 ) ;
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_16 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . type = V_27 ;
V_60 . V_51 = V_61 ;
V_60 . V_23 = V_62 ;
strcpy ( V_60 . V_56 . V_63 . V_64 , L_4 ) ;
strcpy ( V_60 . V_56 . V_63 . V_65 , L_5 ) ;
V_60 . V_56 . V_63 . V_66 = V_67 ;
F_31 ( V_13 , & V_60 ) ;
}
static void F_34 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_13 -> V_3 -> V_7 ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_44 = V_35 ;
T_3 V_34 = F_4 ( V_44 ) ;
T_3 V_68 ;
F_1 ( V_1 ) ;
V_34 |= V_26 | V_41 ;
if ( ! V_1 -> V_69 ) {
if ( ! ( V_34 & V_36 ) )
return;
V_34 &= ~ V_36 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
return;
}
switch ( V_1 -> V_11 ) {
case V_70 :
V_68 = V_71 ;
break;
case V_72 :
V_68 = V_73 ;
break;
default:
F_35 () ;
return;
}
if ( V_68 != ( V_34 & V_74 ) ) {
if ( V_34 & V_36 ) {
V_34 &= ~ V_36 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
}
V_34 &= ~ V_74 ;
V_34 |= V_68 ;
}
V_34 |= V_36 ;
V_34 &= ~ V_75 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
F_32 ( V_13 , V_49 ) ;
F_33 ( V_13 ) ;
}
static void F_36 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_13 -> V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_44 = F_23 ( V_42 -> V_33 ) ;
T_3 V_34 = F_4 ( V_44 ) ;
T_3 V_68 ;
F_1 ( V_1 ) ;
V_34 |= V_26 | V_41 ;
if ( ! V_1 -> V_69 ) {
if ( ! ( V_34 & V_36 ) )
return;
V_34 &= ~ V_36 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
return;
}
switch ( V_1 -> V_11 ) {
case V_76 :
V_68 = V_71 ;
break;
case V_77 :
V_68 = V_73 ;
break;
case V_78 :
V_68 = V_79 ;
break;
default:
F_35 () ;
return;
}
if ( V_68 != ( V_34 & V_74 ) ) {
if ( V_34 & V_36 ) {
V_34 &= ~ V_36 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
}
V_34 &= ~ V_74 ;
V_34 |= V_68 ;
}
V_34 |= V_36 ;
V_34 &= ~ ( V_75 | V_80 |
V_81 ) ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
F_32 ( V_13 , V_49 ) ;
F_33 ( V_13 ) ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_13 -> V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_44 = F_23 ( V_42 -> V_33 ) ;
T_3 V_34 = F_4 ( V_44 ) ;
F_1 ( V_1 ) ;
V_34 |= V_26 | V_41 ;
if ( ! V_1 -> V_69 ) {
if ( ! ( V_34 & V_36 ) )
return;
V_34 &= ~ ( V_36 | V_29 ) ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
return;
}
V_34 |= V_36 | V_29 ;
V_34 &= ~ ( V_75 | V_80 |
V_81 ) ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
F_32 ( V_13 , V_49 ) ;
F_33 ( V_13 ) ;
}
static void F_38 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_13 -> V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_44 = F_27 ( V_42 -> V_33 ) ;
T_3 V_34 = F_4 ( V_44 ) ;
F_1 ( V_1 ) ;
V_34 |= V_26 | V_41 ;
if ( ! V_1 -> V_69 ) {
if ( ! ( V_34 & V_36 ) )
return;
V_34 &= ~ V_36 ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
return;
}
V_34 |= V_36 ;
V_34 &= ~ ( V_75 | V_80 |
V_81 ) ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
F_32 ( V_13 , V_49 ) ;
F_33 ( V_13 ) ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_13 -> V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_44 = F_30 ( V_42 -> V_33 ) ;
T_3 V_34 = F_4 ( V_44 ) ;
F_1 ( V_1 ) ;
if ( ! V_1 -> V_69 ) {
F_18 ( V_44 , 0 ) ;
F_20 ( V_44 ) ;
return;
}
V_34 &= ~ ( V_82 | V_83 |
V_84 | V_85 ) ;
F_18 ( V_44 , V_34 ) ;
F_20 ( V_44 ) ;
F_32 ( V_13 , V_49 ) ;
F_33 ( V_13 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
struct V_48 * V_86 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_42 * V_42 = F_22 ( V_13 -> V_43 ) ;
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_3 V_87 ;
V_87 = V_88 ;
if ( ! F_41 ( V_3 ) )
V_87 |= V_1 -> V_89 ;
if ( V_49 -> V_54 & V_90 )
V_87 |= V_91 ;
if ( V_49 -> V_54 & V_92 )
V_87 |= V_93 ;
if ( V_42 -> V_94 > 24 )
V_87 |= V_95 ;
else
V_87 |= V_96 ;
if ( V_1 -> V_69 && F_42 ( V_3 ) )
V_87 |= V_97 ;
if ( V_1 -> V_98 ) {
F_11 ( L_6 ,
F_43 ( V_42 -> V_33 ) ) ;
V_87 |= V_99 ;
V_87 |= V_100 ;
F_44 ( V_13 , V_49 ) ;
}
if ( F_42 ( V_3 ) )
V_87 |= F_45 ( V_42 -> V_33 ) ;
else if ( V_42 -> V_33 == V_101 )
V_87 |= V_102 ;
F_18 ( V_1 -> V_11 , V_87 ) ;
F_20 ( V_1 -> V_11 ) ;
V_1 -> V_103 ( V_13 , V_49 ) ;
}
static bool F_46 ( struct V_104 * V_13 ,
enum V_33 * V_33 )
{
struct V_2 * V_3 = V_13 -> V_4 . V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_1 = F_5 ( & V_13 -> V_4 ) ;
T_3 V_105 ;
V_105 = F_4 ( V_1 -> V_11 ) ;
if ( ! ( V_105 & V_10 ) )
return false ;
if ( F_42 ( V_3 ) )
* V_33 = F_47 ( V_105 ) ;
else
* V_33 = F_48 ( V_105 ) ;
return true ;
}
static void F_49 ( struct V_104 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_4 . V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_1 = F_5 ( & V_13 -> V_4 ) ;
T_3 V_106 ;
T_3 V_107 = V_10 ;
if ( V_1 -> V_98 )
V_107 |= V_99 ;
V_106 = F_4 ( V_1 -> V_11 ) ;
if ( F_50 ( V_3 ) ) {
struct V_108 * V_43 = V_13 -> V_4 . V_43 ;
int V_33 = V_43 ? F_22 ( V_43 ) -> V_33 : - 1 ;
if ( V_33 == V_101 )
V_107 |= V_102 ;
}
if ( F_41 ( V_3 ) ) {
F_18 ( V_1 -> V_11 , V_106 & ~ V_10 ) ;
F_20 ( V_1 -> V_11 ) ;
}
V_106 |= V_107 ;
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
if ( F_41 ( V_3 ) ) {
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
}
}
static void F_51 ( struct V_104 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_4 . V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_1 * V_1 = F_5 ( & V_13 -> V_4 ) ;
T_3 V_106 ;
T_3 V_107 = V_10 | V_99 ;
V_106 = F_4 ( V_1 -> V_11 ) ;
if ( F_50 ( V_3 ) ) {
struct V_108 * V_43 = V_13 -> V_4 . V_43 ;
int V_33 = V_43 ? F_22 ( V_43 ) -> V_33 : - 1 ;
if ( V_106 & V_102 ) {
V_106 &= ~ V_102 ;
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
if ( V_43 )
F_52 ( V_3 , V_33 ) ;
else
F_53 ( 50 ) ;
}
}
if ( F_41 ( V_3 ) ) {
F_18 ( V_1 -> V_11 , V_106 & ~ V_10 ) ;
F_20 ( V_1 -> V_11 ) ;
}
V_106 &= ~ V_107 ;
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
if ( F_41 ( V_3 ) ) {
F_18 ( V_1 -> V_11 , V_106 ) ;
F_20 ( V_1 -> V_11 ) ;
}
}
static int F_54 ( struct V_14 * V_15 ,
struct V_48 * V_86 )
{
if ( V_86 -> clock > 165000 )
return V_109 ;
if ( V_86 -> clock < 20000 )
return V_110 ;
if ( V_86 -> V_54 & V_111 )
return V_112 ;
return V_113 ;
}
static bool F_55 ( struct V_12 * V_13 ,
const struct V_48 * V_86 ,
struct V_48 * V_49 )
{
return true ;
}
static bool F_56 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 . V_4 . V_3 ;
struct V_5 * V_6 = V_3 -> V_7 ;
T_1 V_114 ;
switch ( V_1 -> V_11 ) {
case V_70 :
V_114 = V_115 ;
break;
case V_72 :
V_114 = V_116 ;
break;
default:
V_114 = 0 ;
break;
}
return F_4 ( V_117 ) & V_114 ;
}
static enum V_118
F_57 ( struct V_14 * V_15 , bool V_119 )
{
struct V_1 * V_1 = F_7 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_3 -> V_7 ;
struct V_120 * V_120 ;
enum V_118 V_121 = V_122 ;
if ( F_58 ( V_15 -> V_3 ) && ! F_56 ( V_1 ) )
return V_121 ;
V_1 -> V_69 = false ;
V_1 -> V_98 = false ;
V_120 = F_59 ( V_15 ,
F_60 ( V_6 ,
V_1 -> V_123 ) ) ;
if ( V_120 ) {
if ( V_120 -> V_124 & V_125 ) {
V_121 = V_126 ;
if ( V_1 -> V_127 != V_128 )
V_1 -> V_69 =
F_61 ( V_120 ) ;
V_1 -> V_98 = F_62 ( V_120 ) ;
}
F_63 ( V_120 ) ;
}
if ( V_121 == V_126 ) {
if ( V_1 -> V_127 != V_129 )
V_1 -> V_98 =
( V_1 -> V_127 == V_130 ) ;
}
return V_121 ;
}
static int F_64 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_7 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_3 -> V_7 ;
return F_65 ( V_15 ,
F_60 ( V_6 ,
V_1 -> V_123 ) ) ;
}
static bool
F_66 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_7 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_3 -> V_7 ;
struct V_120 * V_120 ;
bool V_98 = false ;
V_120 = F_59 ( V_15 ,
F_60 ( V_6 ,
V_1 -> V_123 ) ) ;
if ( V_120 ) {
if ( V_120 -> V_124 & V_125 )
V_98 = F_62 ( V_120 ) ;
F_63 ( V_120 ) ;
}
return V_98 ;
}
static int
F_67 ( struct V_14 * V_15 ,
struct V_131 * V_132 ,
T_4 V_34 )
{
struct V_1 * V_1 = F_7 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_3 -> V_7 ;
int V_133 ;
V_133 = F_68 ( V_15 , V_132 , V_34 ) ;
if ( V_133 )
return V_133 ;
if ( V_132 == V_6 -> V_134 ) {
enum V_135 V_20 = V_34 ;
bool V_98 ;
if ( V_20 == V_1 -> V_127 )
return 0 ;
V_1 -> V_127 = V_20 ;
if ( V_20 == V_129 )
V_98 = F_66 ( V_15 ) ;
else
V_98 = ( V_20 == V_130 ) ;
if ( V_20 == V_128 )
V_1 -> V_69 = 0 ;
V_1 -> V_98 = V_98 ;
goto V_136;
}
if ( V_132 == V_6 -> V_137 ) {
if ( V_34 == ! ! V_1 -> V_89 )
return 0 ;
V_1 -> V_89 = V_34 ? V_138 : 0 ;
goto V_136;
}
return - V_139 ;
V_136:
if ( V_1 -> V_4 . V_4 . V_43 ) {
struct V_108 * V_43 = V_1 -> V_4 . V_4 . V_43 ;
F_69 ( V_43 , & V_43 -> V_86 ,
V_43 -> V_140 , V_43 -> V_141 , V_43 -> V_142 ) ;
}
return 0 ;
}
static void F_70 ( struct V_14 * V_15 )
{
F_71 ( V_15 ) ;
F_72 ( V_15 ) ;
F_63 ( V_15 ) ;
}
static void
F_73 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
F_75 ( V_15 ) ;
}
void F_76 ( struct V_2 * V_3 , int V_11 , enum V_68 V_68 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_14 * V_15 ;
struct V_104 * V_104 ;
struct V_143 * V_143 ;
struct V_1 * V_1 ;
V_1 = F_77 ( sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_1 )
return;
V_143 = F_77 ( sizeof( struct V_143 ) , V_144 ) ;
if ( ! V_143 ) {
F_63 ( V_1 ) ;
return;
}
V_104 = & V_1 -> V_4 ;
F_78 ( V_3 , & V_104 -> V_4 , & V_145 ,
V_146 ) ;
V_15 = & V_143 -> V_4 ;
F_79 ( V_3 , V_15 , & V_147 ,
V_148 ) ;
F_80 ( V_15 , & V_149 ) ;
V_104 -> type = V_150 ;
V_15 -> V_151 = V_152 ;
V_15 -> V_153 = 1 ;
V_15 -> V_154 = 0 ;
V_104 -> V_155 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_104 -> V_156 = false ;
V_1 -> V_157 = V_68 ;
switch ( V_68 ) {
case V_158 :
V_1 -> V_123 = V_159 ;
V_6 -> V_160 |= V_161 ;
break;
case V_162 :
V_1 -> V_123 = V_163 ;
V_6 -> V_160 |= V_164 ;
break;
case V_165 :
V_1 -> V_123 = V_166 ;
V_6 -> V_160 |= V_167 ;
break;
case V_168 :
default:
F_35 () ;
}
V_1 -> V_11 = V_11 ;
if ( ! F_41 ( V_3 ) ) {
V_1 -> V_47 = F_17 ;
V_1 -> V_103 = F_34 ;
} else if ( F_81 ( V_3 ) ) {
V_1 -> V_47 = F_26 ;
V_1 -> V_103 = F_38 ;
} else if ( F_2 ( V_3 ) ) {
V_1 -> V_47 = F_29 ;
V_1 -> V_103 = F_39 ;
} else if ( F_50 ( V_3 ) ) {
V_1 -> V_47 = F_21 ;
V_1 -> V_103 = F_36 ;
} else {
V_1 -> V_47 = F_25 ;
V_1 -> V_103 = F_37 ;
}
if ( F_2 ( V_3 ) ) {
V_104 -> V_169 = V_170 ;
V_104 -> V_171 = V_172 ;
V_104 -> V_173 = V_174 ;
F_82 ( & V_104 -> V_4 ,
& V_175 ) ;
} else {
V_104 -> V_169 = F_49 ;
V_104 -> V_171 = F_51 ;
V_104 -> V_173 = F_46 ;
F_82 ( & V_104 -> V_4 ,
& V_176 ) ;
}
V_143 -> V_173 = V_177 ;
F_73 ( V_1 , V_15 ) ;
F_83 ( V_143 , V_104 ) ;
F_84 ( V_15 ) ;
if ( F_58 ( V_3 ) && ! F_85 ( V_3 ) ) {
T_3 V_106 = F_4 ( V_178 ) ;
F_18 ( V_178 , ( V_106 & ~ 0xf ) | 0xd ) ;
}
}
