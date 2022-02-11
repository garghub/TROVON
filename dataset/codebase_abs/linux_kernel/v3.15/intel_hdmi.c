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
enum V_32 V_33 ,
struct V_5 * V_6 )
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
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
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
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
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
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
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
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
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
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
T_2 V_50 = F_32 ( V_46 -> V_51 . V_33 ) ;
T_2 V_52 ;
int V_39 ;
T_2 V_37 = F_6 ( V_50 ) ;
V_52 = F_15 ( type ,
V_46 -> V_51 . V_33 ,
V_6 ) ;
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
T_4 V_54 [ V_43 ] ;
T_3 V_35 ;
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
T_2 V_70 = F_44 ( V_15 -> V_70 ) ;
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
if ( V_70 != ( V_37 & V_72 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_72 ;
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
T_2 V_70 = F_44 ( V_15 -> V_70 ) ;
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
if ( V_70 != ( V_37 & V_72 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_72 ;
V_37 |= V_70 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_28 | V_73 |
V_74 ) ;
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
V_37 &= ~ ( V_28 | V_73 |
V_74 ) ;
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
V_37 &= ~ ( V_28 | V_73 |
V_74 ) ;
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
V_37 &= ~ ( V_75 | V_76 |
V_31 | V_77 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_49 ( struct V_78 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_47 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_57 * V_58 = & V_47 -> V_51 . V_58 ;
T_2 V_79 ;
V_79 = V_80 ;
if ( ! F_50 ( V_4 ) )
V_79 |= V_2 -> V_81 ;
if ( V_58 -> V_82 & V_83 )
V_79 |= V_84 ;
if ( V_58 -> V_82 & V_85 )
V_79 |= V_86 ;
if ( V_47 -> V_51 . V_87 > 24 )
V_79 |= V_88 ;
else
V_79 |= V_89 ;
if ( V_2 -> V_71 && F_51 ( V_4 ) )
V_79 |= V_90 ;
if ( V_2 -> V_91 ) {
F_12 ( L_8 ,
F_52 ( V_47 -> V_49 ) ) ;
V_79 |= V_92 ;
V_79 |= V_90 ;
F_53 ( & V_13 -> V_3 , V_58 ) ;
}
if ( F_51 ( V_4 ) )
V_79 |= F_54 ( V_47 -> V_49 ) ;
else
V_79 |= F_55 ( V_47 -> V_49 ) ;
F_20 ( V_2 -> V_11 , V_79 ) ;
F_22 ( V_2 -> V_11 ) ;
V_2 -> V_93 ( & V_13 -> V_3 , V_58 ) ;
}
static bool F_56 ( struct V_78 * V_13 ,
enum V_49 * V_49 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_94 V_95 ;
T_2 V_96 ;
V_95 = F_57 ( V_13 ) ;
if ( ! F_58 ( V_6 , V_95 ) )
return false ;
V_96 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_96 & V_10 ) )
return false ;
if ( F_51 ( V_4 ) )
* V_49 = F_59 ( V_96 ) ;
else
* V_49 = F_60 ( V_96 ) ;
return true ;
}
static void F_61 ( struct V_78 * V_13 ,
struct V_97 * V_98 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
T_2 V_96 , V_82 = 0 ;
int V_99 ;
V_96 = F_6 ( V_2 -> V_11 ) ;
if ( V_96 & V_86 )
V_82 |= V_85 ;
else
V_82 |= V_100 ;
if ( V_96 & V_84 )
V_82 |= V_83 ;
else
V_82 |= V_101 ;
V_98 -> V_58 . V_82 |= V_82 ;
if ( ( V_96 & V_102 ) == V_88 )
V_99 = V_98 -> V_103 * 2 / 3 ;
else
V_99 = V_98 -> V_103 ;
if ( F_50 ( V_6 -> V_4 ) )
F_62 ( V_98 , V_99 ) ;
V_98 -> V_58 . V_104 = V_99 ;
}
static void F_63 ( struct V_78 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_105 ;
T_2 V_106 = V_10 ;
if ( V_2 -> V_91 )
V_106 |= V_92 ;
V_105 = F_6 ( V_2 -> V_11 ) ;
if ( F_64 ( V_4 ) )
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
static void F_65 ( struct V_78 * V_13 )
{
}
static void F_66 ( struct V_78 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_105 ;
T_2 V_106 = V_10 | V_92 ;
V_105 = F_6 ( V_2 -> V_11 ) ;
if ( F_64 ( V_4 ) ) {
struct V_107 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_105 & V_108 ) {
V_105 &= ~ V_108 ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_105 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_67 ( V_4 , V_49 ) ;
else
F_68 ( 50 ) ;
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
static int F_69 ( struct V_2 * V_16 , bool V_109 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_109 && ! V_16 -> V_71 ) || F_70 ( V_4 ) )
return 165000 ;
else if ( F_71 ( V_4 ) || F_72 ( V_4 ) -> V_110 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_111
F_73 ( struct V_17 * V_18 ,
struct V_57 * V_112 )
{
if ( V_112 -> clock > F_69 ( F_9 ( V_18 ) ,
true ) )
return V_113 ;
if ( V_112 -> clock < 20000 )
return V_114 ;
if ( V_112 -> V_82 & V_115 )
return V_116 ;
return V_117 ;
}
static bool F_74 ( struct V_46 * V_47 )
{
struct V_1 * V_4 = V_47 -> V_3 . V_4 ;
struct V_78 * V_13 ;
int V_118 = 0 , V_119 = 0 ;
if ( ! F_50 ( V_4 ) )
return false ;
F_75 (encoder, &dev->mode_config.encoder_list, base.head) {
if ( V_13 -> V_120 != V_47 )
continue;
V_119 += V_13 -> type == V_121 ;
V_118 ++ ;
}
return V_119 > 0 && V_119 == V_118 ;
}
bool F_76 ( struct V_78 * V_13 ,
struct V_97 * V_98 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_57 * V_58 = & V_98 -> V_58 ;
int V_122 = V_98 -> V_58 . V_104 * 3 / 2 ;
int V_123 = F_69 ( V_2 , false ) ;
int V_124 ;
if ( V_2 -> V_125 ) {
if ( V_2 -> V_71 &&
F_77 ( V_58 ) > 1 )
V_2 -> V_81 = V_126 ;
else
V_2 -> V_81 = 0 ;
}
if ( V_2 -> V_81 )
V_98 -> V_62 = true ;
if ( F_50 ( V_4 ) && ! F_4 ( V_4 ) )
V_98 -> V_127 = true ;
if ( V_98 -> V_87 > 8 * 3 && V_2 -> V_71 &&
V_122 <= V_123 &&
F_74 ( V_13 -> V_120 ) ) {
F_78 ( L_9 ) ;
V_124 = 12 * 3 ;
V_98 -> V_103 = V_122 ;
} else {
F_78 ( L_10 ) ;
V_124 = 8 * 3 ;
}
if ( ! V_98 -> V_128 ) {
F_78 ( L_11 , V_124 ) ;
V_98 -> V_87 = V_124 ;
}
if ( V_58 -> V_104 > V_123 ) {
F_78 ( L_12 ) ;
return false ;
}
return true ;
}
static enum V_129
F_79 ( struct V_17 * V_18 , bool V_130 )
{
struct V_1 * V_4 = V_18 -> V_4 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_78 * V_78 = & V_15 -> V_3 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_131 * V_131 ;
enum V_94 V_95 ;
enum V_129 V_132 = V_133 ;
F_78 ( L_13 ,
V_18 -> V_3 . V_134 , F_80 ( V_18 ) ) ;
V_95 = F_57 ( V_78 ) ;
F_81 ( V_6 , V_95 ) ;
V_2 -> V_71 = false ;
V_2 -> V_91 = false ;
V_2 -> V_61 = false ;
V_131 = F_82 ( V_18 ,
F_83 ( V_6 ,
V_2 -> V_135 ) ) ;
if ( V_131 ) {
if ( V_131 -> V_136 & V_137 ) {
V_132 = V_138 ;
if ( V_2 -> V_139 != V_140 )
V_2 -> V_71 =
F_84 ( V_131 ) ;
V_2 -> V_91 = F_85 ( V_131 ) ;
V_2 -> V_61 =
F_86 ( V_131 ) ;
}
F_87 ( V_131 ) ;
}
if ( V_132 == V_138 ) {
if ( V_2 -> V_139 != V_141 )
V_2 -> V_91 =
( V_2 -> V_139 == V_142 ) ;
V_78 -> type = V_121 ;
}
F_88 ( V_6 , V_95 ) ;
return V_132 ;
}
static int F_89 ( struct V_17 * V_18 )
{
struct V_78 * V_78 = F_10 ( V_18 ) ;
struct V_2 * V_2 = F_7 ( & V_78 -> V_3 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
enum V_94 V_95 ;
int V_59 ;
V_95 = F_57 ( V_78 ) ;
F_81 ( V_6 , V_95 ) ;
V_59 = F_90 ( V_18 ,
F_83 ( V_6 ,
V_2 -> V_135 ) ) ;
F_88 ( V_6 , V_95 ) ;
return V_59 ;
}
static bool
F_91 ( struct V_17 * V_18 )
{
struct V_78 * V_78 = F_10 ( V_18 ) ;
struct V_2 * V_2 = F_7 ( & V_78 -> V_3 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
enum V_94 V_95 ;
struct V_131 * V_131 ;
bool V_91 = false ;
V_95 = F_57 ( V_78 ) ;
F_81 ( V_6 , V_95 ) ;
V_131 = F_82 ( V_18 ,
F_83 ( V_6 ,
V_2 -> V_135 ) ) ;
if ( V_131 ) {
if ( V_131 -> V_136 & V_137 )
V_91 = F_85 ( V_131 ) ;
F_87 ( V_131 ) ;
}
F_88 ( V_6 , V_95 ) ;
return V_91 ;
}
static int
F_92 ( struct V_17 * V_18 ,
struct V_143 * V_144 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_59 ;
V_59 = F_93 ( & V_18 -> V_3 , V_144 , V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_144 == V_6 -> V_145 ) {
enum V_146 V_39 = V_37 ;
bool V_91 ;
if ( V_39 == V_2 -> V_139 )
return 0 ;
V_2 -> V_139 = V_39 ;
if ( V_39 == V_141 )
V_91 = F_91 ( V_18 ) ;
else
V_91 = ( V_39 == V_142 ) ;
if ( V_39 == V_140 )
V_2 -> V_71 = 0 ;
V_2 -> V_91 = V_91 ;
goto V_147;
}
if ( V_144 == V_6 -> V_148 ) {
bool V_149 = V_2 -> V_125 ;
T_1 V_150 = V_2 -> V_81 ;
switch ( V_37 ) {
case V_151 :
V_2 -> V_125 = true ;
break;
case V_152 :
V_2 -> V_125 = false ;
V_2 -> V_81 = 0 ;
break;
case V_153 :
V_2 -> V_125 = false ;
V_2 -> V_81 = V_126 ;
break;
default:
return - V_154 ;
}
if ( V_149 == V_2 -> V_125 &&
V_150 == V_2 -> V_81 )
return 0 ;
goto V_147;
}
return - V_154 ;
V_147:
if ( V_15 -> V_3 . V_3 . V_47 )
F_94 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_95 ( struct V_78 * V_13 )
{
struct V_14 * V_155 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_156 V_70 = F_96 ( V_155 ) ;
int V_49 = V_46 -> V_49 ;
T_2 V_37 ;
if ( ! F_97 ( V_4 ) )
return;
F_98 ( & V_6 -> V_157 ) ;
V_37 = F_99 ( V_6 , V_49 , F_100 ( V_70 ) ) ;
V_37 = 0 ;
if ( V_49 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_101 ( V_6 , V_49 , F_102 ( V_70 ) , V_37 ) ;
F_101 ( V_6 , V_49 , F_103 ( V_70 ) , 0 ) ;
F_101 ( V_6 , V_49 , F_104 ( V_70 ) , 0x2b245f5f ) ;
F_101 ( V_6 , V_49 , F_105 ( V_70 ) , 0x5578b83a ) ;
F_101 ( V_6 , V_49 , F_106 ( V_70 ) , 0x0c782040 ) ;
F_101 ( V_6 , V_49 , F_107 ( V_70 ) , 0x2b247878 ) ;
F_101 ( V_6 , V_49 , F_108 ( V_70 ) , 0x00030000 ) ;
F_101 ( V_6 , V_49 , F_109 ( V_70 ) , 0x00002000 ) ;
F_101 ( V_6 , V_49 , F_103 ( V_70 ) , V_158 ) ;
F_101 ( V_6 , V_49 , F_110 ( V_70 ) , 0x00760018 ) ;
F_101 ( V_6 , V_49 , F_111 ( V_70 ) , 0x00400888 ) ;
F_112 ( & V_6 -> V_157 ) ;
F_63 ( V_13 ) ;
F_113 ( V_6 , V_155 ) ;
}
static void F_114 ( struct V_78 * V_13 )
{
struct V_14 * V_155 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_156 V_70 = F_96 ( V_155 ) ;
int V_49 = V_46 -> V_49 ;
if ( ! F_97 ( V_4 ) )
return;
F_98 ( & V_6 -> V_157 ) ;
F_101 ( V_6 , V_49 , F_115 ( V_70 ) ,
V_159 |
V_160 ) ;
F_101 ( V_6 , V_49 , F_116 ( V_70 ) ,
V_161 |
V_162 |
( 1 << V_163 ) |
V_164 ) ;
F_101 ( V_6 , V_49 , F_117 ( V_70 ) , 0x00750f00 ) ;
F_101 ( V_6 , V_49 , F_118 ( V_70 ) , 0x00001500 ) ;
F_101 ( V_6 , V_49 , F_119 ( V_70 ) , 0x40400000 ) ;
F_101 ( V_6 , V_49 , F_109 ( V_70 ) , 0x00002000 ) ;
F_101 ( V_6 , V_49 , F_103 ( V_70 ) , V_158 ) ;
F_112 ( & V_6 -> V_157 ) ;
}
static void F_120 ( struct V_78 * V_13 )
{
struct V_14 * V_155 = F_43 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_156 V_70 = F_96 ( V_155 ) ;
int V_49 = V_46 -> V_49 ;
F_98 ( & V_6 -> V_157 ) ;
F_101 ( V_6 , V_49 , F_115 ( V_70 ) , 0x00000000 ) ;
F_101 ( V_6 , V_49 , F_116 ( V_70 ) , 0x00e00060 ) ;
F_112 ( & V_6 -> V_157 ) ;
}
static void F_121 ( struct V_17 * V_18 )
{
F_122 ( V_18 ) ;
F_87 ( V_18 ) ;
}
static void
F_123 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_124 ( V_18 ) ;
F_125 ( V_18 ) ;
V_2 -> V_125 = true ;
}
void F_126 ( struct V_14 * V_15 ,
struct V_165 * V_165 )
{
struct V_17 * V_18 = & V_165 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_78 * V_78 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_78 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_70 V_70 = V_15 -> V_70 ;
F_127 ( V_4 , V_18 , & V_166 ,
V_167 ) ;
F_128 ( V_18 , & V_168 ) ;
V_18 -> V_169 = 1 ;
V_18 -> V_170 = 0 ;
V_18 -> V_171 = 1 ;
switch ( V_70 ) {
case V_172 :
V_2 -> V_135 = V_173 ;
V_78 -> V_174 = V_175 ;
break;
case V_176 :
V_2 -> V_135 = V_177 ;
V_78 -> V_174 = V_178 ;
break;
case V_179 :
V_2 -> V_135 = V_180 ;
V_78 -> V_174 = V_181 ;
break;
case V_182 :
V_78 -> V_174 = V_183 ;
default:
F_129 () ;
}
if ( F_97 ( V_4 ) ) {
V_2 -> V_55 = F_28 ;
V_2 -> V_93 = F_47 ;
} else if ( ! F_50 ( V_4 ) ) {
V_2 -> V_55 = F_19 ;
V_2 -> V_93 = F_42 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_55 = F_31 ;
V_2 -> V_93 = F_48 ;
} else if ( F_64 ( V_4 ) ) {
V_2 -> V_55 = F_23 ;
V_2 -> V_93 = F_45 ;
} else {
V_2 -> V_55 = F_27 ;
V_2 -> V_93 = F_46 ;
}
if ( F_4 ( V_4 ) )
V_165 -> V_184 = V_185 ;
else
V_165 -> V_184 = V_186 ;
V_165 -> V_187 = V_188 ;
F_123 ( V_2 , V_18 ) ;
F_130 ( V_165 , V_78 ) ;
F_131 ( V_18 ) ;
if ( F_70 ( V_4 ) && ! F_132 ( V_4 ) ) {
T_2 V_105 = F_6 ( V_189 ) ;
F_20 ( V_189 , ( V_105 & ~ 0xf ) | 0xd ) ;
}
}
void F_133 ( struct V_1 * V_4 , int V_11 , enum V_70 V_70 )
{
struct V_14 * V_15 ;
struct V_78 * V_78 ;
struct V_165 * V_165 ;
V_15 = F_134 ( sizeof( * V_15 ) , V_190 ) ;
if ( ! V_15 )
return;
V_165 = F_134 ( sizeof( * V_165 ) , V_190 ) ;
if ( ! V_165 ) {
F_87 ( V_15 ) ;
return;
}
V_78 = & V_15 -> V_3 ;
F_135 ( V_4 , & V_78 -> V_3 , & V_191 ,
V_192 ) ;
V_78 -> V_193 = F_76 ;
V_78 -> V_194 = F_49 ;
V_78 -> V_195 = F_66 ;
V_78 -> V_184 = F_56 ;
V_78 -> V_196 = F_61 ;
if ( F_97 ( V_4 ) ) {
V_78 -> V_197 = F_114 ;
V_78 -> V_198 = F_95 ;
V_78 -> V_199 = F_65 ;
V_78 -> V_200 = F_120 ;
} else {
V_78 -> V_199 = F_63 ;
}
V_78 -> type = V_121 ;
V_78 -> V_201 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_78 -> V_202 = 1 << V_203 ;
if ( F_70 ( V_4 ) )
V_78 -> V_202 |= 1 << V_121 ;
V_15 -> V_70 = V_70 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_204 . V_205 = 0 ;
F_126 ( V_15 , V_165 ) ;
}
