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
if ( ! F_45 ( V_4 ) )
V_97 |= V_2 -> V_99 ;
if ( V_55 -> V_60 & V_100 )
V_97 |= V_101 ;
if ( V_55 -> V_60 & V_102 )
V_97 |= V_103 ;
if ( V_46 -> V_51 . V_104 > 24 )
V_97 |= V_105 ;
else
V_97 |= V_106 ;
if ( V_2 -> V_81 && F_46 ( V_4 ) )
V_97 |= V_107 ;
if ( V_2 -> V_108 ) {
F_13 ( L_6 ,
F_47 ( V_46 -> V_49 ) ) ;
V_97 |= V_109 ;
V_97 |= V_107 ;
F_48 ( V_13 , V_55 ) ;
}
if ( F_46 ( V_4 ) )
V_97 |= F_49 ( V_46 -> V_49 ) ;
else
V_97 |= F_50 ( V_46 -> V_49 ) ;
F_20 ( V_2 -> V_11 , V_97 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_110 ( V_13 , V_55 ) ;
}
static bool F_51 ( struct V_111 * V_13 ,
enum V_49 * V_49 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_112 ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_112 & V_10 ) )
return false ;
if ( F_46 ( V_4 ) )
* V_49 = F_52 ( V_112 ) ;
else
* V_49 = F_53 ( V_112 ) ;
return true ;
}
static void F_54 ( struct V_111 * V_13 ,
struct V_113 * V_114 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
T_3 V_112 , V_60 = 0 ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( V_112 & V_103 )
V_60 |= V_102 ;
else
V_60 |= V_115 ;
if ( V_112 & V_101 )
V_60 |= V_100 ;
else
V_60 |= V_116 ;
V_114 -> V_55 . V_60 |= V_60 ;
}
static void F_55 ( struct V_111 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_117 ;
T_3 V_118 = V_10 ;
if ( V_2 -> V_108 )
V_118 |= V_109 ;
V_117 = F_6 ( V_2 -> V_11 ) ;
if ( F_56 ( V_4 ) )
V_118 |= F_50 ( V_46 -> V_49 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_117 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_117 |= V_118 ;
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( F_57 ( V_4 ) ) {
struct V_14 * V_119 =
F_38 ( & V_13 -> V_3 ) ;
int V_120 = F_58 ( V_119 ) ;
F_59 ( V_6 , V_120 ) ;
}
}
static void F_60 ( struct V_111 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_3 V_117 ;
T_3 V_118 = V_10 | V_109 ;
V_117 = F_6 ( V_2 -> V_11 ) ;
if ( F_56 ( V_4 ) ) {
struct V_121 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_117 & V_122 ) {
V_117 &= ~ V_122 ;
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_61 ( V_4 , V_49 ) ;
else
F_62 ( 50 ) ;
}
}
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_117 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_117 &= ~ V_118 ;
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_45 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_117 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_63 ( struct V_2 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( F_64 ( V_4 ) )
return 165000 ;
else if ( F_65 ( V_4 ) )
return 300000 ;
else
return 225000 ;
}
static int F_66 ( struct V_17 * V_18 ,
struct V_54 * V_96 )
{
if ( V_96 -> clock > F_63 ( F_9 ( V_18 ) ) )
return V_123 ;
if ( V_96 -> clock < 20000 )
return V_124 ;
if ( V_96 -> V_60 & V_125 )
return V_126 ;
return V_127 ;
}
bool F_67 ( struct V_111 * V_13 ,
struct V_113 * V_114 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_54 * V_55 = & V_114 -> V_55 ;
int V_128 = V_114 -> V_129 . clock * 3 / 2 ;
int V_130 = F_63 ( V_2 ) ;
int V_131 ;
if ( V_2 -> V_132 ) {
if ( V_2 -> V_81 &&
F_35 ( V_55 ) > 1 )
V_2 -> V_99 = V_133 ;
else
V_2 -> V_99 = 0 ;
}
if ( V_2 -> V_99 )
V_114 -> V_67 = true ;
if ( F_45 ( V_4 ) && ! F_4 ( V_4 ) )
V_114 -> V_134 = true ;
if ( V_114 -> V_104 > 8 * 3 && V_128 <= V_130
&& F_45 ( V_4 ) ) {
F_68 ( L_7 ) ;
V_131 = 12 * 3 ;
V_114 -> V_135 = V_128 ;
} else {
F_68 ( L_8 ) ;
V_131 = 8 * 3 ;
}
if ( ! V_114 -> V_136 ) {
F_68 ( L_9 , V_131 ) ;
V_114 -> V_104 = V_131 ;
}
if ( V_55 -> clock > V_130 ) {
F_68 ( L_10 ) ;
return false ;
}
return true ;
}
static enum V_137
F_69 ( struct V_17 * V_18 , bool V_138 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_111 * V_111 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_139 * V_139 ;
enum V_137 V_140 = V_141 ;
V_2 -> V_81 = false ;
V_2 -> V_108 = false ;
V_2 -> V_66 = false ;
V_139 = F_70 ( V_18 ,
F_71 ( V_6 ,
V_2 -> V_142 ) ) ;
if ( V_139 ) {
if ( V_139 -> V_143 & V_144 ) {
V_140 = V_145 ;
if ( V_2 -> V_146 != V_147 )
V_2 -> V_81 =
F_72 ( V_139 ) ;
V_2 -> V_108 = F_73 ( V_139 ) ;
V_2 -> V_66 =
F_74 ( V_139 ) ;
}
F_75 ( V_139 ) ;
}
if ( V_140 == V_145 ) {
if ( V_2 -> V_146 != V_148 )
V_2 -> V_108 =
( V_2 -> V_146 == V_149 ) ;
V_111 -> type = V_150 ;
}
return V_140 ;
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_77 ( V_18 ,
F_71 ( V_6 ,
V_2 -> V_142 ) ) ;
}
static bool
F_78 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_139 * V_139 ;
bool V_108 = false ;
V_139 = F_70 ( V_18 ,
F_71 ( V_6 ,
V_2 -> V_142 ) ) ;
if ( V_139 ) {
if ( V_139 -> V_143 & V_144 )
V_108 = F_73 ( V_139 ) ;
F_75 ( V_139 ) ;
}
return V_108 ;
}
static int
F_79 ( struct V_17 * V_18 ,
struct V_151 * V_152 ,
T_4 V_38 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_153 ;
V_153 = F_80 ( & V_18 -> V_3 , V_152 , V_38 ) ;
if ( V_153 )
return V_153 ;
if ( V_152 == V_6 -> V_154 ) {
enum V_155 V_23 = V_38 ;
bool V_108 ;
if ( V_23 == V_2 -> V_146 )
return 0 ;
V_2 -> V_146 = V_23 ;
if ( V_23 == V_148 )
V_108 = F_78 ( V_18 ) ;
else
V_108 = ( V_23 == V_149 ) ;
if ( V_23 == V_147 )
V_2 -> V_81 = 0 ;
V_2 -> V_108 = V_108 ;
goto V_156;
}
if ( V_152 == V_6 -> V_157 ) {
bool V_158 = V_2 -> V_132 ;
T_1 V_159 = V_2 -> V_99 ;
switch ( V_38 ) {
case V_160 :
V_2 -> V_132 = true ;
break;
case V_161 :
V_2 -> V_132 = false ;
V_2 -> V_99 = 0 ;
break;
case V_162 :
V_2 -> V_132 = false ;
V_2 -> V_99 = V_133 ;
break;
default:
return - V_163 ;
}
if ( V_158 == V_2 -> V_132 &&
V_159 == V_2 -> V_99 )
return 0 ;
goto V_156;
}
return - V_163 ;
V_156:
if ( V_15 -> V_3 . V_3 . V_47 )
F_81 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_82 ( struct V_111 * V_13 )
{
struct V_14 * V_119 = F_38 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
int V_80 = F_58 ( V_119 ) ;
int V_49 = V_46 -> V_49 ;
T_3 V_38 ;
if ( ! F_57 ( V_4 ) )
return;
V_38 = F_83 ( V_6 , F_84 ( V_80 ) ) ;
V_38 = 0 ;
if ( V_49 )
V_38 |= ( 1 << 21 ) ;
else
V_38 &= ~ ( 1 << 21 ) ;
V_38 |= 0x001000c4 ;
F_85 ( V_6 , F_86 ( V_80 ) , V_38 ) ;
F_85 ( V_6 , F_87 ( V_80 ) , 0 ) ;
F_85 ( V_6 , F_88 ( V_80 ) ,
0x2b245f5f ) ;
F_85 ( V_6 , F_89 ( V_80 ) ,
0x5578b83a ) ;
F_85 ( V_6 , F_90 ( V_80 ) ,
0x0c782040 ) ;
F_85 ( V_6 , F_91 ( V_80 ) ,
0x2b247878 ) ;
F_85 ( V_6 , F_92 ( V_80 ) , 0x00030000 ) ;
F_85 ( V_6 , F_93 ( V_80 ) ,
0x00002000 ) ;
F_85 ( V_6 , F_87 ( V_80 ) ,
V_164 ) ;
F_85 ( V_6 , F_94 ( V_80 ) ,
0x00760018 ) ;
F_85 ( V_6 , F_95 ( V_80 ) ,
0x00400888 ) ;
}
static void F_96 ( struct V_111 * V_13 )
{
struct V_14 * V_119 = F_38 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_80 = F_58 ( V_119 ) ;
if ( ! F_57 ( V_4 ) )
return;
F_85 ( V_6 , F_97 ( V_80 ) ,
V_165 |
V_166 ) ;
F_85 ( V_6 , F_98 ( V_80 ) ,
V_167 |
V_168 |
( 1 << V_169 ) |
V_170 ) ;
F_85 ( V_6 , F_99 ( V_80 ) , 0x00750f00 ) ;
F_85 ( V_6 , F_100 ( V_80 ) , 0x00001500 ) ;
F_85 ( V_6 , F_101 ( V_80 ) , 0x40400000 ) ;
F_85 ( V_6 , F_93 ( V_80 ) ,
0x00002000 ) ;
F_85 ( V_6 , F_87 ( V_80 ) ,
V_164 ) ;
}
static void F_102 ( struct V_111 * V_13 )
{
struct V_14 * V_119 = F_38 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
int V_80 = F_58 ( V_119 ) ;
F_103 ( & V_6 -> V_171 ) ;
F_85 ( V_6 , F_97 ( V_80 ) , 0x00000000 ) ;
F_85 ( V_6 , F_98 ( V_80 ) , 0x00e00060 ) ;
F_104 ( & V_6 -> V_171 ) ;
}
static void F_105 ( struct V_17 * V_18 )
{
F_106 ( V_18 ) ;
F_107 ( V_18 ) ;
F_75 ( V_18 ) ;
}
static void
F_108 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_109 ( V_18 ) ;
F_110 ( V_18 ) ;
V_2 -> V_132 = true ;
}
void F_111 ( struct V_14 * V_15 ,
struct V_172 * V_172 )
{
struct V_17 * V_18 = & V_172 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_111 * V_111 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_111 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_80 V_80 = V_15 -> V_80 ;
F_112 ( V_4 , V_18 , & V_173 ,
V_174 ) ;
F_113 ( V_18 , & V_175 ) ;
V_18 -> V_176 = 1 ;
V_18 -> V_177 = 0 ;
switch ( V_80 ) {
case V_82 :
V_2 -> V_142 = V_178 ;
V_111 -> V_179 = V_180 ;
break;
case V_84 :
V_2 -> V_142 = V_181 ;
V_111 -> V_179 = V_182 ;
break;
case V_88 :
V_2 -> V_142 = V_183 ;
V_111 -> V_179 = V_184 ;
break;
case V_185 :
V_111 -> V_179 = V_186 ;
default:
F_39 () ;
}
if ( F_57 ( V_4 ) ) {
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
V_172 -> V_187 = V_188 ;
else
V_172 -> V_187 = V_189 ;
F_108 ( V_2 , V_18 ) ;
F_114 ( V_172 , V_111 ) ;
F_115 ( V_18 ) ;
if ( F_64 ( V_4 ) && ! F_116 ( V_4 ) ) {
T_3 V_117 = F_6 ( V_190 ) ;
F_20 ( V_190 , ( V_117 & ~ 0xf ) | 0xd ) ;
}
}
void F_117 ( struct V_1 * V_4 , int V_11 , enum V_80 V_80 )
{
struct V_14 * V_15 ;
struct V_111 * V_111 ;
struct V_12 * V_13 ;
struct V_172 * V_172 ;
V_15 = F_118 ( sizeof( struct V_14 ) , V_191 ) ;
if ( ! V_15 )
return;
V_172 = F_118 ( sizeof( struct V_172 ) , V_191 ) ;
if ( ! V_172 ) {
F_75 ( V_15 ) ;
return;
}
V_111 = & V_15 -> V_3 ;
V_13 = & V_111 -> V_3 ;
F_119 ( V_4 , & V_111 -> V_3 , & V_192 ,
V_193 ) ;
F_120 ( & V_111 -> V_3 , & V_194 ) ;
V_111 -> V_195 = F_67 ;
V_111 -> V_196 = F_55 ;
V_111 -> V_197 = F_60 ;
V_111 -> V_187 = F_51 ;
V_111 -> V_198 = F_54 ;
if ( F_57 ( V_4 ) ) {
V_111 -> V_199 = F_82 ;
V_111 -> V_200 = F_96 ;
V_111 -> V_201 = F_102 ;
}
V_111 -> type = V_150 ;
V_111 -> V_202 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_111 -> V_203 = false ;
V_15 -> V_80 = V_80 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_204 . V_205 = 0 ;
F_111 ( V_15 , V_172 ) ;
}
