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
static T_2 F_11 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_13 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_26 ;
case V_22 :
return V_27 ;
case V_24 :
return V_28 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_14 ( enum V_19 type )
{
switch ( type ) {
case V_20 :
return V_29 ;
case V_22 :
return V_30 ;
case V_24 :
return V_31 ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static T_2 F_15 ( enum V_19 type ,
enum V_32 V_33 )
{
switch ( type ) {
case V_20 :
return F_16 ( V_33 ) ;
case V_22 :
return F_17 ( V_33 ) ;
case V_24 :
return F_18 ( V_33 ) ;
default:
F_12 ( L_2 , type ) ;
return 0 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
enum V_19 type ,
const T_3 * V_34 , T_4 V_35 )
{
T_1 * V_36 = ( T_1 * ) V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_37 = F_6 ( V_38 ) ;
int V_39 ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_38 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( V_42 , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( V_42 , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_38 , V_37 ) ;
F_22 ( V_38 ) ;
}
static void F_23 ( struct V_12 * V_13 ,
enum V_19 type ,
const T_3 * V_34 , T_4 V_35 )
{
T_1 * V_36 = ( T_1 * ) V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_39 , V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_48 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_26 ( V_46 -> V_49 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_26 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
enum V_19 type ,
const T_3 * V_34 , T_4 V_35 )
{
T_1 * V_36 = ( T_1 * ) V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_39 , V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
if ( type != V_20 )
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_48 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_26 ( V_46 -> V_49 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_26 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
static void F_28 ( struct V_12 * V_13 ,
enum V_19 type ,
const T_3 * V_34 , T_4 V_35 )
{
T_1 * V_36 = ( T_1 * ) V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
int V_39 , V_48 = F_29 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_48 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_30 ( V_46 -> V_49 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_30 ( V_46 -> V_49 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
static void F_31 ( struct V_12 * V_13 ,
enum V_19 type ,
const T_3 * V_34 , T_4 V_35 )
{
T_1 * V_36 = ( T_1 * ) V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
T_2 V_50 = F_32 ( V_46 -> V_51 . V_33 ) ;
T_2 V_52 ;
int V_39 ;
T_2 V_37 = F_6 ( V_50 ) ;
V_52 = F_15 ( type ,
V_46 -> V_51 . V_33 ) ;
if ( V_52 == 0 )
return;
V_37 &= ~ F_14 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( V_52 + V_39 , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( V_52 + V_39 , 0 ) ;
F_21 () ;
V_37 |= F_14 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static void F_33 ( struct V_12 * V_13 ,
union V_53 * V_34 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_54 [ V_43 ] ;
T_4 V_35 ;
V_35 = F_34 ( V_34 , V_54 + 1 , sizeof( V_54 ) - 1 ) ;
if ( V_35 < 0 )
return;
V_54 [ 0 ] = V_54 [ 1 ] ;
V_54 [ 1 ] = V_54 [ 2 ] ;
V_54 [ 2 ] = V_54 [ 3 ] ;
V_54 [ 3 ] = 0 ;
V_35 ++ ;
V_2 -> V_55 ( V_13 , V_34 -> V_56 . type , V_54 , V_35 ) ;
}
static void F_35 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
union V_53 V_34 ;
int V_59 ;
V_59 = F_36 ( & V_34 . V_60 ,
V_58 ) ;
if ( V_59 < 0 ) {
F_37 ( L_4 ) ;
return;
}
if ( V_2 -> V_61 ) {
if ( V_46 -> V_51 . V_62 )
V_34 . V_60 . V_63 =
V_64 ;
else
V_34 . V_60 . V_63 =
V_65 ;
}
F_33 ( V_13 , & V_34 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
union V_53 V_34 ;
int V_59 ;
V_59 = F_39 ( & V_34 . V_66 , L_5 , L_6 ) ;
if ( V_59 < 0 ) {
F_37 ( L_7 ) ;
return;
}
V_34 . V_66 . V_67 = V_68 ;
F_33 ( V_13 , & V_34 ) ;
}
static void
F_40 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
union V_53 V_34 ;
int V_59 ;
V_59 = F_41 ( & V_34 . V_69 . V_16 ,
V_58 ) ;
if ( V_59 < 0 )
return;
F_33 ( V_13 , & V_34 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_43 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_48 = V_38 ;
T_2 V_37 = F_6 ( V_48 ) ;
T_2 V_70 ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_2 -> V_71 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
switch ( V_15 -> V_70 ) {
case V_72 :
V_70 = V_73 ;
break;
case V_74 :
V_70 = V_75 ;
break;
default:
F_44 () ;
return;
}
if ( V_70 != ( V_37 & V_76 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_76 ;
V_37 |= V_70 ;
}
V_37 |= V_40 ;
V_37 &= ~ V_28 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_45 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_14 * V_15 = F_43 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
T_2 V_70 ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_2 -> V_71 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
switch ( V_15 -> V_70 ) {
case V_72 :
V_70 = V_73 ;
break;
case V_74 :
V_70 = V_75 ;
break;
case V_77 :
V_70 = V_78 ;
break;
default:
F_44 () ;
return;
}
if ( V_70 != ( V_37 & V_76 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_76 ;
V_37 |= V_70 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_28 | V_79 |
V_80 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_46 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_2 -> V_71 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
V_37 |= V_40 | V_26 ;
V_37 &= ~ ( V_28 | V_79 |
V_80 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_47 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_29 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_2 -> V_71 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_28 | V_79 |
V_80 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_48 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_32 ( V_46 -> V_51 . V_33 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
if ( ! V_2 -> V_71 ) {
F_20 ( V_48 , 0 ) ;
F_22 ( V_48 ) ;
return;
}
V_37 &= ~ ( V_81 | V_82 |
V_31 | V_83 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_49 ( struct V_84 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_47 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_57 * V_58 = & V_47 -> V_51 . V_58 ;
T_2 V_85 ;
V_85 = V_86 ;
if ( ! F_50 ( V_4 ) )
V_85 |= V_2 -> V_87 ;
if ( V_58 -> V_88 & V_89 )
V_85 |= V_90 ;
if ( V_58 -> V_88 & V_91 )
V_85 |= V_92 ;
if ( V_47 -> V_51 . V_93 > 24 )
V_85 |= V_94 ;
else
V_85 |= V_95 ;
if ( V_2 -> V_71 && F_51 ( V_4 ) )
V_85 |= V_96 ;
if ( V_2 -> V_97 ) {
F_12 ( L_8 ,
F_52 ( V_47 -> V_49 ) ) ;
V_85 |= V_98 ;
V_85 |= V_96 ;
F_53 ( & V_13 -> V_3 , V_58 ) ;
}
if ( F_51 ( V_4 ) )
V_85 |= F_54 ( V_47 -> V_49 ) ;
else
V_85 |= F_55 ( V_47 -> V_49 ) ;
F_20 ( V_2 -> V_11 , V_85 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_99 ( & V_13 -> V_3 , V_58 ) ;
}
static bool F_56 ( struct V_84 * V_13 ,
enum V_49 * V_49 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_100 ;
V_100 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_100 & V_10 ) )
return false ;
if ( F_51 ( V_4 ) )
* V_49 = F_57 ( V_100 ) ;
else
* V_49 = F_58 ( V_100 ) ;
return true ;
}
static void F_59 ( struct V_84 * V_13 ,
struct V_101 * V_102 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
T_2 V_100 , V_88 = 0 ;
V_100 = F_6 ( V_2 -> V_11 ) ;
if ( V_100 & V_92 )
V_88 |= V_91 ;
else
V_88 |= V_103 ;
if ( V_100 & V_90 )
V_88 |= V_89 ;
else
V_88 |= V_104 ;
V_102 -> V_58 . V_88 |= V_88 ;
}
static void F_60 ( struct V_84 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_105 ;
T_2 V_106 = V_10 ;
if ( V_2 -> V_97 )
V_106 |= V_98 ;
V_105 = F_6 ( V_2 -> V_11 ) ;
if ( F_61 ( V_4 ) )
V_106 |= F_55 ( V_46 -> V_49 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_105 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_105 |= V_106 ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_62 ( struct V_84 * V_13 )
{
}
static void F_63 ( struct V_84 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_105 ;
T_2 V_106 = V_10 | V_98 ;
V_105 = F_6 ( V_2 -> V_11 ) ;
if ( F_61 ( V_4 ) ) {
struct V_107 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_105 & V_108 ) {
V_105 &= ~ V_108 ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_64 ( V_4 , V_49 ) ;
else
F_65 ( 50 ) ;
}
}
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_105 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_105 &= ~ V_106 ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_66 ( struct V_2 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( F_67 ( V_4 ) )
return 165000 ;
else if ( F_68 ( V_4 ) )
return 300000 ;
else
return 225000 ;
}
static int F_69 ( struct V_17 * V_18 ,
struct V_57 * V_109 )
{
if ( V_109 -> clock > F_66 ( F_9 ( V_18 ) ) )
return V_110 ;
if ( V_109 -> clock < 20000 )
return V_111 ;
if ( V_109 -> V_88 & V_112 )
return V_113 ;
return V_114 ;
}
bool F_70 ( struct V_84 * V_13 ,
struct V_101 * V_102 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_57 * V_58 = & V_102 -> V_58 ;
int V_115 = V_102 -> V_116 . clock * 3 / 2 ;
int V_117 = F_66 ( V_2 ) ;
int V_118 ;
if ( V_2 -> V_119 ) {
if ( V_2 -> V_71 &&
F_71 ( V_58 ) > 1 )
V_2 -> V_87 = V_120 ;
else
V_2 -> V_87 = 0 ;
}
if ( V_2 -> V_87 )
V_102 -> V_62 = true ;
if ( F_50 ( V_4 ) && ! F_4 ( V_4 ) )
V_102 -> V_121 = true ;
if ( V_102 -> V_93 > 8 * 3 && V_115 <= V_117
&& F_50 ( V_4 ) ) {
F_72 ( L_9 ) ;
V_118 = 12 * 3 ;
V_102 -> V_122 = V_115 ;
} else {
F_72 ( L_10 ) ;
V_118 = 8 * 3 ;
}
if ( ! V_102 -> V_123 ) {
F_72 ( L_11 , V_118 ) ;
V_102 -> V_93 = V_118 ;
}
if ( V_58 -> clock > V_117 ) {
F_72 ( L_12 ) ;
return false ;
}
return true ;
}
static enum V_124
F_73 ( struct V_17 * V_18 , bool V_125 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_84 * V_84 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_126 * V_126 ;
enum V_124 V_127 = V_128 ;
F_72 ( L_13 ,
V_18 -> V_3 . V_129 , F_74 ( V_18 ) ) ;
V_2 -> V_71 = false ;
V_2 -> V_97 = false ;
V_2 -> V_61 = false ;
V_126 = F_75 ( V_18 ,
F_76 ( V_6 ,
V_2 -> V_130 ) ) ;
if ( V_126 ) {
if ( V_126 -> V_131 & V_132 ) {
V_127 = V_133 ;
if ( V_2 -> V_134 != V_135 )
V_2 -> V_71 =
F_77 ( V_126 ) ;
V_2 -> V_97 = F_78 ( V_126 ) ;
V_2 -> V_61 =
F_79 ( V_126 ) ;
}
F_80 ( V_126 ) ;
}
if ( V_127 == V_133 ) {
if ( V_2 -> V_134 != V_136 )
V_2 -> V_97 =
( V_2 -> V_134 == V_137 ) ;
V_84 -> type = V_138 ;
}
return V_127 ;
}
static int F_81 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_82 ( V_18 ,
F_76 ( V_6 ,
V_2 -> V_130 ) ) ;
}
static bool
F_83 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_126 * V_126 ;
bool V_97 = false ;
V_126 = F_75 ( V_18 ,
F_76 ( V_6 ,
V_2 -> V_130 ) ) ;
if ( V_126 ) {
if ( V_126 -> V_131 & V_132 )
V_97 = F_78 ( V_126 ) ;
F_80 ( V_126 ) ;
}
return V_97 ;
}
static int
F_84 ( struct V_17 * V_18 ,
struct V_139 * V_140 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_59 ;
V_59 = F_85 ( & V_18 -> V_3 , V_140 , V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_140 == V_6 -> V_141 ) {
enum V_142 V_39 = V_37 ;
bool V_97 ;
if ( V_39 == V_2 -> V_134 )
return 0 ;
V_2 -> V_134 = V_39 ;
if ( V_39 == V_136 )
V_97 = F_83 ( V_18 ) ;
else
V_97 = ( V_39 == V_137 ) ;
if ( V_39 == V_135 )
V_2 -> V_71 = 0 ;
V_2 -> V_97 = V_97 ;
goto V_143;
}
if ( V_140 == V_6 -> V_144 ) {
bool V_145 = V_2 -> V_119 ;
T_1 V_146 = V_2 -> V_87 ;
switch ( V_37 ) {
case V_147 :
V_2 -> V_119 = true ;
break;
case V_148 :
V_2 -> V_119 = false ;
V_2 -> V_87 = 0 ;
break;
case V_149 :
V_2 -> V_119 = false ;
V_2 -> V_87 = V_120 ;
break;
default:
return - V_150 ;
}
if ( V_145 == V_2 -> V_119 &&
V_146 == V_2 -> V_87 )
return 0 ;
goto V_143;
}
return - V_150 ;
V_143:
if ( V_15 -> V_3 . V_3 . V_47 )
F_86 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_87 ( struct V_84 * V_13 )
{
struct V_14 * V_151 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
int V_70 = F_88 ( V_151 ) ;
int V_49 = V_46 -> V_49 ;
T_2 V_37 ;
if ( ! F_89 ( V_4 ) )
return;
F_90 ( & V_6 -> V_152 ) ;
V_37 = F_91 ( V_6 , F_92 ( V_70 ) ) ;
V_37 = 0 ;
if ( V_49 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_93 ( V_6 , F_94 ( V_70 ) , V_37 ) ;
F_93 ( V_6 , F_95 ( V_70 ) , 0 ) ;
F_93 ( V_6 , F_96 ( V_70 ) ,
0x2b245f5f ) ;
F_93 ( V_6 , F_97 ( V_70 ) ,
0x5578b83a ) ;
F_93 ( V_6 , F_98 ( V_70 ) ,
0x0c782040 ) ;
F_93 ( V_6 , F_99 ( V_70 ) ,
0x2b247878 ) ;
F_93 ( V_6 , F_100 ( V_70 ) , 0x00030000 ) ;
F_93 ( V_6 , F_101 ( V_70 ) ,
0x00002000 ) ;
F_93 ( V_6 , F_95 ( V_70 ) ,
V_153 ) ;
F_93 ( V_6 , F_102 ( V_70 ) ,
0x00760018 ) ;
F_93 ( V_6 , F_103 ( V_70 ) ,
0x00400888 ) ;
F_104 ( & V_6 -> V_152 ) ;
F_60 ( V_13 ) ;
F_105 ( V_6 , V_70 ) ;
}
static void F_106 ( struct V_84 * V_13 )
{
struct V_14 * V_151 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_70 = F_88 ( V_151 ) ;
if ( ! F_89 ( V_4 ) )
return;
F_90 ( & V_6 -> V_152 ) ;
F_93 ( V_6 , F_107 ( V_70 ) ,
V_154 |
V_155 ) ;
F_93 ( V_6 , F_108 ( V_70 ) ,
V_156 |
V_157 |
( 1 << V_158 ) |
V_159 ) ;
F_93 ( V_6 , F_109 ( V_70 ) , 0x00750f00 ) ;
F_93 ( V_6 , F_110 ( V_70 ) , 0x00001500 ) ;
F_93 ( V_6 , F_111 ( V_70 ) , 0x40400000 ) ;
F_93 ( V_6 , F_101 ( V_70 ) ,
0x00002000 ) ;
F_93 ( V_6 , F_95 ( V_70 ) ,
V_153 ) ;
F_104 ( & V_6 -> V_152 ) ;
}
static void F_112 ( struct V_84 * V_13 )
{
struct V_14 * V_151 = F_43 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
int V_70 = F_88 ( V_151 ) ;
F_90 ( & V_6 -> V_152 ) ;
F_93 ( V_6 , F_107 ( V_70 ) , 0x00000000 ) ;
F_93 ( V_6 , F_108 ( V_70 ) , 0x00e00060 ) ;
F_104 ( & V_6 -> V_152 ) ;
}
static void F_113 ( struct V_17 * V_18 )
{
F_114 ( V_18 ) ;
F_115 ( V_18 ) ;
F_80 ( V_18 ) ;
}
static void
F_116 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_117 ( V_18 ) ;
F_118 ( V_18 ) ;
V_2 -> V_119 = true ;
}
void F_119 ( struct V_14 * V_15 ,
struct V_160 * V_160 )
{
struct V_17 * V_18 = & V_160 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_84 * V_84 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_84 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_70 V_70 = V_15 -> V_70 ;
F_120 ( V_4 , V_18 , & V_161 ,
V_162 ) ;
F_121 ( V_18 , & V_163 ) ;
V_18 -> V_164 = 1 ;
V_18 -> V_165 = 0 ;
switch ( V_70 ) {
case V_72 :
V_2 -> V_130 = V_166 ;
V_84 -> V_167 = V_168 ;
break;
case V_74 :
V_2 -> V_130 = V_169 ;
V_84 -> V_167 = V_170 ;
break;
case V_77 :
V_2 -> V_130 = V_171 ;
V_84 -> V_167 = V_172 ;
break;
case V_173 :
V_84 -> V_167 = V_174 ;
default:
F_44 () ;
}
if ( F_89 ( V_4 ) ) {
V_2 -> V_55 = F_28 ;
V_2 -> V_99 = F_47 ;
} else if ( ! F_50 ( V_4 ) ) {
V_2 -> V_55 = F_19 ;
V_2 -> V_99 = F_42 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_55 = F_31 ;
V_2 -> V_99 = F_48 ;
} else if ( F_61 ( V_4 ) ) {
V_2 -> V_55 = F_23 ;
V_2 -> V_99 = F_45 ;
} else {
V_2 -> V_55 = F_27 ;
V_2 -> V_99 = F_46 ;
}
if ( F_4 ( V_4 ) )
V_160 -> V_175 = V_176 ;
else
V_160 -> V_175 = V_177 ;
F_116 ( V_2 , V_18 ) ;
F_122 ( V_160 , V_84 ) ;
F_123 ( V_18 ) ;
if ( F_67 ( V_4 ) && ! F_124 ( V_4 ) ) {
T_2 V_105 = F_6 ( V_178 ) ;
F_20 ( V_178 , ( V_105 & ~ 0xf ) | 0xd ) ;
}
}
void F_125 ( struct V_1 * V_4 , int V_11 , enum V_70 V_70 )
{
struct V_14 * V_15 ;
struct V_84 * V_84 ;
struct V_160 * V_160 ;
V_15 = F_126 ( sizeof( struct V_14 ) , V_179 ) ;
if ( ! V_15 )
return;
V_160 = F_126 ( sizeof( struct V_160 ) , V_179 ) ;
if ( ! V_160 ) {
F_80 ( V_15 ) ;
return;
}
V_84 = & V_15 -> V_3 ;
F_127 ( V_4 , & V_84 -> V_3 , & V_180 ,
V_181 ) ;
V_84 -> V_182 = F_70 ;
V_84 -> V_183 = F_49 ;
V_84 -> V_184 = F_63 ;
V_84 -> V_175 = F_56 ;
V_84 -> V_185 = F_59 ;
if ( F_89 ( V_4 ) ) {
V_84 -> V_186 = F_106 ;
V_84 -> V_187 = F_87 ;
V_84 -> V_188 = F_62 ;
V_84 -> V_189 = F_112 ;
} else {
V_84 -> V_188 = F_60 ;
}
V_84 -> type = V_138 ;
V_84 -> V_190 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_84 -> V_191 = false ;
V_15 -> V_70 = V_70 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_192 . V_193 = 0 ;
F_119 ( V_15 , V_160 ) ;
}
