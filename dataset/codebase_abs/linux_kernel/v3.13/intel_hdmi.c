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
int V_103 ;
V_100 = F_6 ( V_2 -> V_11 ) ;
if ( V_100 & V_92 )
V_88 |= V_91 ;
else
V_88 |= V_104 ;
if ( V_100 & V_90 )
V_88 |= V_89 ;
else
V_88 |= V_105 ;
V_102 -> V_58 . V_88 |= V_88 ;
if ( ( V_100 & V_106 ) == V_94 )
V_103 = V_102 -> V_107 * 2 / 3 ;
else
V_103 = V_102 -> V_107 ;
if ( F_50 ( V_6 -> V_4 ) )
F_60 ( V_102 , V_103 ) ;
V_102 -> V_58 . V_108 = V_103 ;
}
static void F_61 ( struct V_84 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_109 ;
T_2 V_110 = V_10 ;
if ( V_2 -> V_97 )
V_110 |= V_98 ;
V_109 = F_6 ( V_2 -> V_11 ) ;
if ( F_62 ( V_4 ) )
V_110 |= F_55 ( V_46 -> V_49 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_109 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_109 |= V_110 ;
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_63 ( struct V_84 * V_13 )
{
}
static void F_64 ( struct V_84 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_109 ;
T_2 V_110 = V_10 | V_98 ;
V_109 = F_6 ( V_2 -> V_11 ) ;
if ( F_62 ( V_4 ) ) {
struct V_111 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_109 & V_112 ) {
V_109 &= ~ V_112 ;
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_65 ( V_4 , V_49 ) ;
else
F_66 ( 50 ) ;
}
}
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_109 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_109 &= ~ V_110 ;
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_109 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_67 ( struct V_2 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( F_68 ( V_4 ) )
return 165000 ;
else if ( F_69 ( V_4 ) || F_70 ( V_4 ) -> V_113 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_71 ( struct V_17 * V_18 ,
struct V_57 * V_114 )
{
if ( V_114 -> clock > F_67 ( F_9 ( V_18 ) ) )
return V_115 ;
if ( V_114 -> clock < 20000 )
return V_116 ;
if ( V_114 -> V_88 & V_117 )
return V_118 ;
return V_119 ;
}
bool F_72 ( struct V_84 * V_13 ,
struct V_101 * V_102 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_57 * V_58 = & V_102 -> V_58 ;
int V_120 = V_102 -> V_58 . V_108 * 3 / 2 ;
int V_121 = F_67 ( V_2 ) ;
int V_122 ;
if ( V_2 -> V_123 ) {
if ( V_2 -> V_71 &&
F_73 ( V_58 ) > 1 )
V_2 -> V_87 = V_124 ;
else
V_2 -> V_87 = 0 ;
}
if ( V_2 -> V_87 )
V_102 -> V_62 = true ;
if ( F_50 ( V_4 ) && ! F_4 ( V_4 ) )
V_102 -> V_125 = true ;
if ( V_102 -> V_93 > 8 * 3 && V_120 <= V_121
&& F_50 ( V_4 ) ) {
F_74 ( L_9 ) ;
V_122 = 12 * 3 ;
V_102 -> V_107 = V_120 ;
} else {
F_74 ( L_10 ) ;
V_122 = 8 * 3 ;
}
if ( ! V_102 -> V_126 ) {
F_74 ( L_11 , V_122 ) ;
V_102 -> V_93 = V_122 ;
}
if ( V_58 -> V_108 > V_121 ) {
F_74 ( L_12 ) ;
return false ;
}
return true ;
}
static enum V_127
F_75 ( struct V_17 * V_18 , bool V_128 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_84 * V_84 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_129 * V_129 ;
enum V_127 V_130 = V_131 ;
F_74 ( L_13 ,
V_18 -> V_3 . V_132 , F_76 ( V_18 ) ) ;
V_2 -> V_71 = false ;
V_2 -> V_97 = false ;
V_2 -> V_61 = false ;
V_129 = F_77 ( V_18 ,
F_78 ( V_6 ,
V_2 -> V_133 ) ) ;
if ( V_129 ) {
if ( V_129 -> V_134 & V_135 ) {
V_130 = V_136 ;
if ( V_2 -> V_137 != V_138 )
V_2 -> V_71 =
F_79 ( V_129 ) ;
V_2 -> V_97 = F_80 ( V_129 ) ;
V_2 -> V_61 =
F_81 ( V_129 ) ;
}
F_82 ( V_129 ) ;
}
if ( V_130 == V_136 ) {
if ( V_2 -> V_137 != V_139 )
V_2 -> V_97 =
( V_2 -> V_137 == V_140 ) ;
V_84 -> type = V_141 ;
}
return V_130 ;
}
static int F_83 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
return F_84 ( V_18 ,
F_78 ( V_6 ,
V_2 -> V_133 ) ) ;
}
static bool
F_85 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
struct V_129 * V_129 ;
bool V_97 = false ;
V_129 = F_77 ( V_18 ,
F_78 ( V_6 ,
V_2 -> V_133 ) ) ;
if ( V_129 ) {
if ( V_129 -> V_134 & V_135 )
V_97 = F_80 ( V_129 ) ;
F_82 ( V_129 ) ;
}
return V_97 ;
}
static int
F_86 ( struct V_17 * V_18 ,
struct V_142 * V_143 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_59 ;
V_59 = F_87 ( & V_18 -> V_3 , V_143 , V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_143 == V_6 -> V_144 ) {
enum V_145 V_39 = V_37 ;
bool V_97 ;
if ( V_39 == V_2 -> V_137 )
return 0 ;
V_2 -> V_137 = V_39 ;
if ( V_39 == V_139 )
V_97 = F_85 ( V_18 ) ;
else
V_97 = ( V_39 == V_140 ) ;
if ( V_39 == V_138 )
V_2 -> V_71 = 0 ;
V_2 -> V_97 = V_97 ;
goto V_146;
}
if ( V_143 == V_6 -> V_147 ) {
bool V_148 = V_2 -> V_123 ;
T_1 V_149 = V_2 -> V_87 ;
switch ( V_37 ) {
case V_150 :
V_2 -> V_123 = true ;
break;
case V_151 :
V_2 -> V_123 = false ;
V_2 -> V_87 = 0 ;
break;
case V_152 :
V_2 -> V_123 = false ;
V_2 -> V_87 = V_124 ;
break;
default:
return - V_153 ;
}
if ( V_148 == V_2 -> V_123 &&
V_149 == V_2 -> V_87 )
return 0 ;
goto V_146;
}
return - V_153 ;
V_146:
if ( V_15 -> V_3 . V_3 . V_47 )
F_88 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_89 ( struct V_84 * V_13 )
{
struct V_14 * V_154 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
int V_70 = F_90 ( V_154 ) ;
int V_49 = V_46 -> V_49 ;
T_2 V_37 ;
if ( ! F_91 ( V_4 ) )
return;
F_92 ( & V_6 -> V_155 ) ;
V_37 = F_93 ( V_6 , V_49 , F_94 ( V_70 ) ) ;
V_37 = 0 ;
if ( V_49 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_95 ( V_6 , V_49 , F_96 ( V_70 ) , V_37 ) ;
F_95 ( V_6 , V_49 , F_97 ( V_70 ) , 0 ) ;
F_95 ( V_6 , V_49 , F_98 ( V_70 ) ,
0x2b245f5f ) ;
F_95 ( V_6 , V_49 , F_99 ( V_70 ) ,
0x5578b83a ) ;
F_95 ( V_6 , V_49 , F_100 ( V_70 ) ,
0x0c782040 ) ;
F_95 ( V_6 , V_49 , F_101 ( V_70 ) ,
0x2b247878 ) ;
F_95 ( V_6 , V_49 , F_102 ( V_70 ) , 0x00030000 ) ;
F_95 ( V_6 , V_49 , F_103 ( V_70 ) ,
0x00002000 ) ;
F_95 ( V_6 , V_49 , F_97 ( V_70 ) ,
V_156 ) ;
F_95 ( V_6 , V_49 , F_104 ( V_70 ) ,
0x00760018 ) ;
F_95 ( V_6 , V_49 , F_105 ( V_70 ) ,
0x00400888 ) ;
F_106 ( & V_6 -> V_155 ) ;
F_61 ( V_13 ) ;
F_107 ( V_6 , V_70 ) ;
}
static void F_108 ( struct V_84 * V_13 )
{
struct V_14 * V_154 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
int V_70 = F_90 ( V_154 ) ;
int V_49 = V_46 -> V_49 ;
if ( ! F_91 ( V_4 ) )
return;
F_92 ( & V_6 -> V_155 ) ;
F_95 ( V_6 , V_49 , F_109 ( V_70 ) ,
V_157 |
V_158 ) ;
F_95 ( V_6 , V_49 , F_110 ( V_70 ) ,
V_159 |
V_160 |
( 1 << V_161 ) |
V_162 ) ;
F_95 ( V_6 , V_49 , F_111 ( V_70 ) , 0x00750f00 ) ;
F_95 ( V_6 , V_49 , F_112 ( V_70 ) , 0x00001500 ) ;
F_95 ( V_6 , V_49 , F_113 ( V_70 ) , 0x40400000 ) ;
F_95 ( V_6 , V_49 , F_103 ( V_70 ) ,
0x00002000 ) ;
F_95 ( V_6 , V_49 , F_97 ( V_70 ) ,
V_156 ) ;
F_106 ( & V_6 -> V_155 ) ;
}
static void F_114 ( struct V_84 * V_13 )
{
struct V_14 * V_154 = F_43 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
int V_70 = F_90 ( V_154 ) ;
int V_49 = V_46 -> V_49 ;
F_92 ( & V_6 -> V_155 ) ;
F_95 ( V_6 , V_49 , F_109 ( V_70 ) , 0x00000000 ) ;
F_95 ( V_6 , V_49 , F_110 ( V_70 ) , 0x00e00060 ) ;
F_106 ( & V_6 -> V_155 ) ;
}
static void F_115 ( struct V_17 * V_18 )
{
F_116 ( V_18 ) ;
F_82 ( V_18 ) ;
}
static void
F_117 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_118 ( V_18 ) ;
F_119 ( V_18 ) ;
V_2 -> V_123 = true ;
}
void F_120 ( struct V_14 * V_15 ,
struct V_163 * V_163 )
{
struct V_17 * V_18 = & V_163 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_84 * V_84 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_84 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_70 V_70 = V_15 -> V_70 ;
F_121 ( V_4 , V_18 , & V_164 ,
V_165 ) ;
F_122 ( V_18 , & V_166 ) ;
V_18 -> V_167 = 1 ;
V_18 -> V_168 = 0 ;
V_18 -> V_169 = 1 ;
switch ( V_70 ) {
case V_72 :
V_2 -> V_133 = V_170 ;
V_84 -> V_171 = V_172 ;
break;
case V_74 :
V_2 -> V_133 = V_173 ;
V_84 -> V_171 = V_174 ;
break;
case V_77 :
V_2 -> V_133 = V_175 ;
V_84 -> V_171 = V_176 ;
break;
case V_177 :
V_84 -> V_171 = V_178 ;
default:
F_44 () ;
}
if ( F_91 ( V_4 ) ) {
V_2 -> V_55 = F_28 ;
V_2 -> V_99 = F_47 ;
} else if ( ! F_50 ( V_4 ) ) {
V_2 -> V_55 = F_19 ;
V_2 -> V_99 = F_42 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_55 = F_31 ;
V_2 -> V_99 = F_48 ;
} else if ( F_62 ( V_4 ) ) {
V_2 -> V_55 = F_23 ;
V_2 -> V_99 = F_45 ;
} else {
V_2 -> V_55 = F_27 ;
V_2 -> V_99 = F_46 ;
}
if ( F_4 ( V_4 ) )
V_163 -> V_179 = V_180 ;
else
V_163 -> V_179 = V_181 ;
F_117 ( V_2 , V_18 ) ;
F_123 ( V_163 , V_84 ) ;
F_124 ( V_18 ) ;
if ( F_68 ( V_4 ) && ! F_125 ( V_4 ) ) {
T_2 V_109 = F_6 ( V_182 ) ;
F_20 ( V_182 , ( V_109 & ~ 0xf ) | 0xd ) ;
}
}
void F_126 ( struct V_1 * V_4 , int V_11 , enum V_70 V_70 )
{
struct V_14 * V_15 ;
struct V_84 * V_84 ;
struct V_163 * V_163 ;
V_15 = F_127 ( sizeof( * V_15 ) , V_183 ) ;
if ( ! V_15 )
return;
V_163 = F_127 ( sizeof( * V_163 ) , V_183 ) ;
if ( ! V_163 ) {
F_82 ( V_15 ) ;
return;
}
V_84 = & V_15 -> V_3 ;
F_128 ( V_4 , & V_84 -> V_3 , & V_184 ,
V_185 ) ;
V_84 -> V_186 = F_72 ;
V_84 -> V_187 = F_49 ;
V_84 -> V_188 = F_64 ;
V_84 -> V_179 = F_56 ;
V_84 -> V_189 = F_59 ;
if ( F_91 ( V_4 ) ) {
V_84 -> V_190 = F_108 ;
V_84 -> V_191 = F_89 ;
V_84 -> V_192 = F_63 ;
V_84 -> V_193 = F_114 ;
} else {
V_84 -> V_192 = F_61 ;
}
V_84 -> type = V_141 ;
V_84 -> V_194 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_84 -> V_195 = false ;
V_15 -> V_70 = V_70 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_196 . V_197 = 0 ;
F_120 ( V_15 , V_163 ) ;
}
