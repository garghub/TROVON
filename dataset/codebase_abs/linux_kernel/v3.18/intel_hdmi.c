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
V_58 -> V_60 = V_2 -> V_61 ;
V_59 = F_36 ( & V_34 . V_62 ,
V_58 ) ;
if ( V_59 < 0 ) {
F_37 ( L_4 ) ;
return;
}
if ( V_2 -> V_63 ) {
if ( V_46 -> V_51 . V_64 )
V_34 . V_62 . V_65 =
V_66 ;
else
V_34 . V_62 . V_65 =
V_67 ;
}
F_33 ( V_13 , & V_34 ) ;
}
static void F_38 ( struct V_12 * V_13 )
{
union V_53 V_34 ;
int V_59 ;
V_59 = F_39 ( & V_34 . V_68 , L_5 , L_6 ) ;
if ( V_59 < 0 ) {
F_37 ( L_7 ) ;
return;
}
V_34 . V_68 . V_69 = V_70 ;
F_33 ( V_13 , & V_34 ) ;
}
static void
F_40 ( struct V_12 * V_13 ,
struct V_57 * V_58 )
{
union V_53 V_34 ;
int V_59 ;
V_59 = F_41 ( & V_34 . V_71 . V_16 ,
V_58 ) ;
if ( V_59 < 0 )
return;
F_33 ( V_13 , & V_34 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
bool V_72 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_43 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_48 = V_38 ;
T_2 V_37 = F_6 ( V_48 ) ;
T_2 V_73 = F_44 ( V_15 -> V_73 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_72 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
if ( V_73 != ( V_37 & V_74 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_74 ;
V_37 |= V_73 ;
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
bool V_72 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_14 * V_15 = F_43 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
T_2 V_73 = F_44 ( V_15 -> V_73 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_72 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
if ( V_73 != ( V_37 & V_74 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_74 ;
V_37 |= V_73 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_28 | V_75 |
V_76 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_46 ( struct V_12 * V_13 ,
bool V_72 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_25 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_72 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
V_37 |= V_40 | V_26 ;
V_37 &= ~ ( V_28 | V_75 |
V_76 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_47 ( struct V_12 * V_13 ,
bool V_72 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_43 ( V_13 ) ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_29 ( V_46 -> V_49 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
T_2 V_73 = F_44 ( V_15 -> V_73 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_72 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
return;
}
if ( V_73 != ( V_37 & V_74 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
}
V_37 &= ~ V_74 ;
V_37 |= V_73 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_26 | V_28 |
V_75 | V_76 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_48 ( struct V_12 * V_13 ,
bool V_72 ,
struct V_57 * V_58 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_47 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_48 = F_32 ( V_46 -> V_51 . V_33 ) ;
T_2 V_37 = F_6 ( V_48 ) ;
F_3 ( V_2 ) ;
if ( ! V_72 ) {
F_20 ( V_48 , 0 ) ;
F_22 ( V_48 ) ;
return;
}
V_37 &= ~ ( V_77 | V_78 |
V_31 | V_79 ) ;
F_20 ( V_48 , V_37 ) ;
F_22 ( V_48 ) ;
F_35 ( V_13 , V_58 ) ;
F_38 ( V_13 ) ;
F_40 ( V_13 , V_58 ) ;
}
static void F_49 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_47 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_57 * V_58 = & V_47 -> V_51 . V_58 ;
T_2 V_81 ;
V_81 = V_82 ;
if ( ! F_50 ( V_4 ) )
V_81 |= V_2 -> V_83 ;
if ( V_58 -> V_84 & V_85 )
V_81 |= V_86 ;
if ( V_58 -> V_84 & V_87 )
V_81 |= V_88 ;
if ( V_47 -> V_51 . V_89 > 24 )
V_81 |= V_90 ;
else
V_81 |= V_91 ;
if ( V_47 -> V_51 . V_92 )
V_81 |= V_93 ;
if ( V_47 -> V_51 . V_94 ) {
F_51 ( ! V_47 -> V_51 . V_92 ) ;
F_12 ( L_8 ,
F_52 ( V_47 -> V_49 ) ) ;
V_81 |= V_95 ;
F_53 ( & V_13 -> V_3 , V_58 ) ;
}
if ( F_54 ( V_4 ) )
V_81 |= F_55 ( V_47 -> V_49 ) ;
else if ( F_56 ( V_4 ) )
V_81 |= F_57 ( V_47 -> V_49 ) ;
else
V_81 |= F_58 ( V_47 -> V_49 ) ;
F_20 ( V_2 -> V_11 , V_81 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_59 ( struct V_80 * V_13 ,
enum V_49 * V_49 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_96 V_97 ;
T_2 V_98 ;
V_97 = F_60 ( V_13 ) ;
if ( ! F_61 ( V_6 , V_97 ) )
return false ;
V_98 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_98 & V_10 ) )
return false ;
if ( F_54 ( V_4 ) )
* V_49 = F_62 ( V_98 ) ;
else if ( F_56 ( V_4 ) )
* V_49 = F_63 ( V_98 ) ;
else
* V_49 = F_64 ( V_98 ) ;
return true ;
}
static void F_65 ( struct V_80 * V_13 ,
struct V_99 * V_100 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_98 , V_84 = 0 ;
int V_101 ;
V_98 = F_6 ( V_2 -> V_11 ) ;
if ( V_98 & V_88 )
V_84 |= V_87 ;
else
V_84 |= V_102 ;
if ( V_98 & V_86 )
V_84 |= V_85 ;
else
V_84 |= V_103 ;
if ( V_98 & V_93 )
V_100 -> V_92 = true ;
if ( V_98 & V_95 )
V_100 -> V_94 = true ;
if ( ! F_50 ( V_4 ) &&
V_98 & V_104 )
V_100 -> V_64 = true ;
V_100 -> V_58 . V_84 |= V_84 ;
if ( ( V_98 & V_105 ) == V_90 )
V_101 = V_100 -> V_106 * 2 / 3 ;
else
V_101 = V_100 -> V_106 ;
if ( F_50 ( V_6 -> V_4 ) )
F_66 ( V_100 , V_101 ) ;
V_100 -> V_58 . V_107 = V_101 ;
}
static void F_67 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_108 ;
T_2 V_109 = V_10 ;
if ( V_46 -> V_51 . V_94 )
V_109 |= V_95 ;
V_108 = F_6 ( V_2 -> V_11 ) ;
if ( F_68 ( V_4 ) )
V_109 |= F_58 ( V_46 -> V_49 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_108 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_108 |= V_109 ;
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_69 ( struct V_80 * V_13 )
{
}
static void F_70 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_108 ;
T_2 V_109 = V_10 | V_95 ;
V_108 = F_6 ( V_2 -> V_11 ) ;
if ( F_68 ( V_4 ) ) {
struct V_110 * V_47 = V_13 -> V_3 . V_47 ;
int V_49 = V_47 ? F_24 ( V_47 ) -> V_49 : - 1 ;
if ( V_108 & V_111 ) {
V_108 &= ~ V_111 ;
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_47 )
F_71 ( V_4 , V_49 ) ;
else
F_72 ( 50 ) ;
}
}
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_108 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_108 &= ~ V_109 ;
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_50 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_108 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_73 ( struct V_2 * V_16 , bool V_112 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_112 && ! V_16 -> V_92 ) || F_74 ( V_4 ) )
return 165000 ;
else if ( F_75 ( V_4 ) || F_76 ( V_4 ) -> V_113 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_114
F_77 ( struct V_17 * V_18 ,
struct V_57 * V_115 )
{
int clock = V_115 -> clock ;
if ( V_115 -> V_84 & V_116 )
clock *= 2 ;
if ( clock > F_73 ( F_9 ( V_18 ) ,
true ) )
return V_117 ;
if ( clock < 20000 )
return V_118 ;
if ( V_115 -> V_84 & V_119 )
return V_120 ;
return V_121 ;
}
static bool F_78 ( struct V_46 * V_47 )
{
struct V_1 * V_4 = V_47 -> V_3 . V_4 ;
struct V_80 * V_13 ;
int V_122 = 0 , V_123 = 0 ;
if ( F_79 ( V_4 ) )
return false ;
F_80 (dev, encoder) {
if ( V_13 -> V_124 != V_47 )
continue;
V_123 += V_13 -> type == V_125 ;
V_122 ++ ;
}
return V_123 > 0 && V_123 == V_122 ;
}
bool F_81 ( struct V_80 * V_13 ,
struct V_99 * V_100 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_57 * V_58 = & V_100 -> V_58 ;
int V_126 = V_100 -> V_58 . V_107 * 3 / 2 ;
int V_127 = F_73 ( V_2 , false ) ;
int V_128 ;
V_100 -> V_92 = V_2 -> V_92 ;
if ( V_2 -> V_129 ) {
if ( V_100 -> V_92 &&
F_82 ( V_58 ) > 1 )
V_2 -> V_83 = V_104 ;
else
V_2 -> V_83 = 0 ;
}
if ( V_58 -> V_84 & V_116 ) {
V_100 -> V_130 = 2 ;
}
if ( V_2 -> V_83 )
V_100 -> V_64 = true ;
if ( F_50 ( V_4 ) && ! F_4 ( V_4 ) )
V_100 -> V_131 = true ;
if ( V_100 -> V_92 && V_2 -> V_94 )
V_100 -> V_94 = true ;
if ( V_100 -> V_89 > 8 * 3 && V_100 -> V_92 &&
V_126 <= V_127 &&
F_78 ( V_13 -> V_124 ) ) {
F_83 ( L_9 ) ;
V_128 = 12 * 3 ;
V_100 -> V_106 = V_126 ;
} else {
F_83 ( L_10 ) ;
V_128 = 8 * 3 ;
}
if ( ! V_100 -> V_132 ) {
F_83 ( L_11 , V_128 ) ;
V_100 -> V_89 = V_128 ;
}
if ( V_58 -> V_107 > V_127 ) {
F_83 ( L_12 ) ;
return false ;
}
return true ;
}
static void
F_84 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_92 = false ;
V_2 -> V_94 = false ;
V_2 -> V_63 = false ;
F_85 ( F_86 ( V_18 ) -> V_133 ) ;
F_86 ( V_18 ) -> V_133 = NULL ;
}
static bool
F_87 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_88 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_80 * V_80 =
& F_2 ( V_2 ) -> V_3 ;
enum V_96 V_97 ;
struct V_134 * V_134 ;
bool V_135 = false ;
V_97 = F_60 ( V_80 ) ;
F_89 ( V_6 , V_97 ) ;
V_134 = F_90 ( V_18 ,
F_91 ( V_6 ,
V_2 -> V_136 ) ) ;
F_92 ( V_6 , V_97 ) ;
F_86 ( V_18 ) -> V_133 = V_134 ;
if ( V_134 && V_134 -> V_137 & V_138 ) {
V_2 -> V_63 =
F_93 ( V_134 ) ;
V_2 -> V_94 = F_94 ( V_134 ) ;
if ( V_2 -> V_139 != V_140 )
V_2 -> V_94 =
V_2 -> V_139 == V_141 ;
if ( V_2 -> V_139 != V_142 )
V_2 -> V_92 =
F_95 ( V_134 ) ;
V_135 = true ;
}
return V_135 ;
}
static enum V_143
F_96 ( struct V_17 * V_18 , bool V_144 )
{
enum V_143 V_145 ;
F_83 ( L_13 ,
V_18 -> V_3 . V_146 , V_18 -> V_147 ) ;
F_84 ( V_18 ) ;
if ( F_87 ( V_18 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_125 ;
V_145 = V_148 ;
} else
V_145 = V_149 ;
return V_145 ;
}
static void
F_97 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_83 ( L_13 ,
V_18 -> V_3 . V_146 , V_18 -> V_147 ) ;
F_84 ( V_18 ) ;
if ( V_18 -> V_145 != V_148 )
return;
F_87 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_125 ;
}
static int F_98 ( struct V_17 * V_18 )
{
struct V_134 * V_134 ;
V_134 = F_86 ( V_18 ) -> V_133 ;
if ( V_134 == NULL )
return 0 ;
return F_99 ( V_18 , V_134 ) ;
}
static bool
F_100 ( struct V_17 * V_18 )
{
bool V_94 = false ;
struct V_134 * V_134 ;
V_134 = F_86 ( V_18 ) -> V_133 ;
if ( V_134 && V_134 -> V_137 & V_138 )
V_94 = F_94 ( V_134 ) ;
return V_94 ;
}
static int
F_101 ( struct V_17 * V_18 ,
struct V_150 * V_151 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_59 ;
V_59 = F_102 ( & V_18 -> V_3 , V_151 , V_37 ) ;
if ( V_59 )
return V_59 ;
if ( V_151 == V_6 -> V_152 ) {
enum V_153 V_39 = V_37 ;
bool V_94 ;
if ( V_39 == V_2 -> V_139 )
return 0 ;
V_2 -> V_139 = V_39 ;
if ( V_39 == V_140 )
V_94 = F_100 ( V_18 ) ;
else
V_94 = ( V_39 == V_141 ) ;
if ( V_39 == V_142 )
V_2 -> V_92 = 0 ;
V_2 -> V_94 = V_94 ;
goto V_154;
}
if ( V_151 == V_6 -> V_155 ) {
bool V_156 = V_2 -> V_129 ;
T_1 V_157 = V_2 -> V_83 ;
switch ( V_37 ) {
case V_158 :
V_2 -> V_129 = true ;
break;
case V_159 :
V_2 -> V_129 = false ;
V_2 -> V_83 = 0 ;
break;
case V_160 :
V_2 -> V_129 = false ;
V_2 -> V_83 = V_104 ;
break;
default:
return - V_161 ;
}
if ( V_156 == V_2 -> V_129 &&
V_157 == V_2 -> V_83 )
return 0 ;
goto V_154;
}
if ( V_151 == V_18 -> V_4 -> V_162 . V_163 ) {
switch ( V_37 ) {
case V_164 :
V_2 -> V_61 = V_165 ;
break;
case V_166 :
V_2 -> V_61 = V_167 ;
break;
case V_168 :
V_2 -> V_61 = V_169 ;
break;
default:
return - V_161 ;
}
goto V_154;
}
return - V_161 ;
V_154:
if ( V_15 -> V_3 . V_3 . V_47 )
F_103 ( V_15 -> V_3 . V_3 . V_47 ) ;
return 0 ;
}
static void F_104 ( struct V_80 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_46 * V_46 = F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_57 * V_58 =
& V_46 -> V_51 . V_58 ;
F_49 ( V_13 ) ;
V_2 -> V_170 ( & V_13 -> V_3 ,
V_46 -> V_51 . V_92 ,
V_58 ) ;
}
static void F_105 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_171 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
struct V_57 * V_58 =
& V_46 -> V_51 . V_58 ;
enum V_172 V_73 = F_106 ( V_171 ) ;
int V_49 = V_46 -> V_49 ;
T_2 V_37 ;
F_107 ( & V_6 -> V_173 ) ;
V_37 = F_108 ( V_6 , V_49 , F_109 ( V_73 ) ) ;
V_37 = 0 ;
if ( V_49 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_110 ( V_6 , V_49 , F_111 ( V_73 ) , V_37 ) ;
F_110 ( V_6 , V_49 , F_112 ( V_73 ) , 0 ) ;
F_110 ( V_6 , V_49 , F_113 ( V_73 ) , 0x2b245f5f ) ;
F_110 ( V_6 , V_49 , F_114 ( V_73 ) , 0x5578b83a ) ;
F_110 ( V_6 , V_49 , F_115 ( V_73 ) , 0x0c782040 ) ;
F_110 ( V_6 , V_49 , F_116 ( V_73 ) , 0x2b247878 ) ;
F_110 ( V_6 , V_49 , F_117 ( V_73 ) , 0x00030000 ) ;
F_110 ( V_6 , V_49 , F_118 ( V_73 ) , 0x00002000 ) ;
F_110 ( V_6 , V_49 , F_112 ( V_73 ) , V_174 ) ;
F_110 ( V_6 , V_49 , F_119 ( V_73 ) , 0x00760018 ) ;
F_110 ( V_6 , V_49 , F_120 ( V_73 ) , 0x00400888 ) ;
F_121 ( & V_6 -> V_173 ) ;
V_2 -> V_170 ( & V_13 -> V_3 ,
V_46 -> V_51 . V_92 ,
V_58 ) ;
F_67 ( V_13 ) ;
F_122 ( V_6 , V_171 ) ;
}
static void F_123 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_172 V_73 = F_106 ( V_171 ) ;
int V_49 = V_46 -> V_49 ;
F_49 ( V_13 ) ;
F_107 ( & V_6 -> V_173 ) ;
F_110 ( V_6 , V_49 , F_124 ( V_73 ) ,
V_175 |
V_176 ) ;
F_110 ( V_6 , V_49 , F_125 ( V_73 ) ,
V_177 |
V_178 |
( 1 << V_179 ) |
V_180 ) ;
F_110 ( V_6 , V_49 , F_126 ( V_73 ) , 0x00750f00 ) ;
F_110 ( V_6 , V_49 , F_127 ( V_73 ) , 0x00001500 ) ;
F_110 ( V_6 , V_49 , F_128 ( V_73 ) , 0x40400000 ) ;
F_110 ( V_6 , V_49 , F_118 ( V_73 ) , 0x00002000 ) ;
F_110 ( V_6 , V_49 , F_112 ( V_73 ) , V_174 ) ;
F_121 ( & V_6 -> V_173 ) ;
}
static void F_129 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_172 V_181 = F_106 ( V_171 ) ;
enum V_49 V_49 = V_46 -> V_49 ;
T_2 V_37 ;
F_49 ( V_13 ) ;
F_107 ( & V_6 -> V_173 ) ;
if ( V_49 != V_182 ) {
V_37 = F_108 ( V_6 , V_49 , V_183 ) ;
V_37 &= ~ ( V_184 | V_185 ) ;
if ( V_181 == V_186 )
V_37 |= V_187 ;
if ( V_181 == V_188 )
V_37 |= V_189 ;
F_110 ( V_6 , V_49 , V_183 , V_37 ) ;
} else {
V_37 = F_108 ( V_6 , V_49 , V_190 ) ;
V_37 &= ~ ( V_191 | V_192 ) ;
if ( V_181 == V_186 )
V_37 |= V_193 ;
if ( V_181 == V_188 )
V_37 |= V_194 ;
F_110 ( V_6 , V_49 , V_190 , V_37 ) ;
}
V_37 = F_108 ( V_6 , V_49 , F_109 ( V_181 ) ) ;
V_37 |= V_195 ;
if ( V_49 != V_182 )
V_37 &= ~ V_196 ;
else
V_37 |= V_196 ;
F_110 ( V_6 , V_49 , F_109 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_130 ( V_181 ) ) ;
V_37 |= V_195 ;
if ( V_49 != V_182 )
V_37 &= ~ V_196 ;
else
V_37 |= V_196 ;
F_110 ( V_6 , V_49 , F_130 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_131 ( V_181 ) ) ;
if ( V_49 != V_182 )
V_37 &= ~ V_197 ;
else
V_37 |= V_197 ;
F_110 ( V_6 , V_49 , F_131 ( V_181 ) , V_37 ) ;
F_121 ( & V_6 -> V_173 ) ;
}
static void F_132 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_172 V_73 = F_106 ( V_171 ) ;
int V_49 = V_46 -> V_49 ;
F_107 ( & V_6 -> V_173 ) ;
F_110 ( V_6 , V_49 , F_124 ( V_73 ) , 0x00000000 ) ;
F_110 ( V_6 , V_49 , F_125 ( V_73 ) , 0x00e00060 ) ;
F_121 ( & V_6 -> V_173 ) ;
}
static void F_133 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_172 V_181 = F_106 ( V_171 ) ;
enum V_49 V_49 = V_46 -> V_49 ;
T_2 V_37 ;
F_107 ( & V_6 -> V_173 ) ;
V_37 = F_108 ( V_6 , V_49 , F_134 ( V_181 ) ) ;
V_37 |= V_198 ;
F_110 ( V_6 , V_49 , F_134 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_135 ( V_181 ) ) ;
V_37 |= V_198 ;
F_110 ( V_6 , V_49 , F_135 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_136 ( V_181 ) ) ;
V_37 &= ~ ( V_175 | V_176 ) ;
F_110 ( V_6 , V_49 , F_136 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_137 ( V_181 ) ) ;
V_37 &= ~ ( V_175 | V_176 ) ;
F_110 ( V_6 , V_49 , F_137 ( V_181 ) , V_37 ) ;
F_121 ( & V_6 -> V_173 ) ;
}
static void F_138 ( struct V_80 * V_13 )
{
struct V_14 * V_171 = F_43 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_46 =
F_24 ( V_13 -> V_3 . V_47 ) ;
enum V_172 V_181 = F_106 ( V_171 ) ;
int V_49 = V_46 -> V_49 ;
int V_36 , V_39 ;
T_2 V_37 ;
F_107 ( & V_6 -> V_173 ) ;
V_37 = F_108 ( V_6 , V_49 , F_134 ( V_181 ) ) ;
V_37 |= V_198 ;
F_110 ( V_6 , V_49 , F_134 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_135 ( V_181 ) ) ;
V_37 |= V_198 ;
F_110 ( V_6 , V_49 , F_135 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_136 ( V_181 ) ) ;
V_37 |= ( V_175 | V_176 ) ;
F_110 ( V_6 , V_49 , F_136 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_137 ( V_181 ) ) ;
V_37 |= ( V_175 | V_176 ) ;
F_110 ( V_6 , V_49 , F_137 ( V_181 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_36 = ( V_39 == 1 ) ? 0x0 : 0x6 ;
F_110 ( V_6 , V_49 , F_139 ( V_181 , V_39 ) ,
V_36 << V_199 ) ;
V_36 = ( V_39 == 1 ) ? 0x0 : 0x1 ;
F_110 ( V_6 , V_49 , F_140 ( V_181 , V_39 ) ,
V_36 << V_200 ) ;
}
V_37 = F_108 ( V_6 , V_49 , F_141 ( V_181 ) ) ;
V_37 &= ~ ( V_201 | V_202 ) ;
F_110 ( V_6 , V_49 , F_141 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_142 ( V_181 ) ) ;
V_37 &= ~ ( V_201 | V_202 ) ;
F_110 ( V_6 , V_49 , F_142 ( V_181 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_108 ( V_6 , V_49 , F_143 ( V_181 , V_39 ) ) ;
V_37 &= ~ V_203 ;
V_37 |= 128 << V_204 ;
F_110 ( V_6 , V_49 , F_143 ( V_181 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_108 ( V_6 , V_49 , F_144 ( V_181 , V_39 ) ) ;
V_37 &= ~ V_205 ;
V_37 |= 102 << V_206 ;
F_110 ( V_6 , V_49 , F_144 ( V_181 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_108 ( V_6 , V_49 , F_145 ( V_181 , V_39 ) ) ;
V_37 &= ~ V_207 ;
F_110 ( V_6 , V_49 , F_145 ( V_181 , V_39 ) , V_37 ) ;
}
#if 0
val = vlv_dpio_read(dev_priv, pipe, VLV_TX_DW3(ch));
if (ch)
val |= DPIO_TX_UNIQ_TRANS_SCALE_CH1;
else
val |= DPIO_TX_UNIQ_TRANS_SCALE_CH0;
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW3(ch), val);
vlv_dpio_write(dev_priv, pipe, VLV_TX_DW2(ch),
vlv_dpio_read(dev_priv, pipe, VLV_TX_DW2(ch)) |
(0x9a << DPIO_UNIQ_TRANS_SCALE_SHIFT));
#endif
V_37 = F_108 ( V_6 , V_49 , F_141 ( V_181 ) ) ;
V_37 |= V_201 | V_202 ;
F_110 ( V_6 , V_49 , F_141 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , F_142 ( V_181 ) ) ;
V_37 |= V_201 | V_202 ;
F_110 ( V_6 , V_49 , F_142 ( V_181 ) , V_37 ) ;
V_37 = F_108 ( V_6 , V_49 , V_208 ) ;
V_37 |= V_209 ;
F_110 ( V_6 , V_49 , V_208 , V_37 ) ;
F_121 ( & V_6 -> V_173 ) ;
F_67 ( V_13 ) ;
F_122 ( V_6 , V_171 ) ;
}
static void F_146 ( struct V_17 * V_18 )
{
F_85 ( F_86 ( V_18 ) -> V_133 ) ;
F_147 ( V_18 ) ;
F_85 ( V_18 ) ;
}
static void
F_148 ( struct V_17 * V_18 )
{
if ( ! F_149 ( V_18 -> V_4 ) )
F_150 ( & V_18 -> V_3 ,
V_18 -> V_4 -> V_162 . V_163 ,
V_164 ) ;
}
static void
F_151 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_152 ( V_18 ) ;
F_153 ( V_18 ) ;
V_2 -> V_129 = true ;
F_148 ( V_18 ) ;
V_2 -> V_61 = V_165 ;
}
void F_154 ( struct V_14 * V_15 ,
struct V_210 * V_210 )
{
struct V_17 * V_18 = & V_210 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_80 * V_80 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_80 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_73 V_73 = V_15 -> V_73 ;
F_155 ( V_4 , V_18 , & V_211 ,
V_212 ) ;
F_156 ( V_18 , & V_213 ) ;
V_18 -> V_214 = 1 ;
V_18 -> V_215 = 0 ;
V_18 -> V_216 = 1 ;
switch ( V_73 ) {
case V_217 :
V_2 -> V_136 = V_218 ;
V_80 -> V_219 = V_220 ;
break;
case V_221 :
V_2 -> V_136 = V_222 ;
V_80 -> V_219 = V_223 ;
break;
case V_224 :
if ( F_56 ( V_4 ) )
V_2 -> V_136 = V_225 ;
else
V_2 -> V_136 = V_226 ;
V_80 -> V_219 = V_227 ;
break;
case V_228 :
V_80 -> V_219 = V_229 ;
default:
F_157 () ;
}
if ( F_158 ( V_4 ) ) {
V_2 -> V_55 = F_28 ;
V_2 -> V_170 = F_47 ;
} else if ( F_74 ( V_4 ) ) {
V_2 -> V_55 = F_19 ;
V_2 -> V_170 = F_42 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_55 = F_31 ;
V_2 -> V_170 = F_48 ;
} else if ( F_68 ( V_4 ) ) {
V_2 -> V_55 = F_23 ;
V_2 -> V_170 = F_45 ;
} else {
V_2 -> V_55 = F_27 ;
V_2 -> V_170 = F_46 ;
}
if ( F_4 ( V_4 ) )
V_210 -> V_230 = V_231 ;
else
V_210 -> V_230 = V_232 ;
V_210 -> V_233 = V_234 ;
F_151 ( V_2 , V_18 ) ;
F_159 ( V_210 , V_80 ) ;
F_160 ( V_18 ) ;
if ( F_74 ( V_4 ) && ! F_161 ( V_4 ) ) {
T_2 V_108 = F_6 ( V_235 ) ;
F_20 ( V_235 , ( V_108 & ~ 0xf ) | 0xd ) ;
}
}
void F_162 ( struct V_1 * V_4 , int V_11 , enum V_73 V_73 )
{
struct V_14 * V_15 ;
struct V_80 * V_80 ;
struct V_210 * V_210 ;
V_15 = F_163 ( sizeof( * V_15 ) , V_236 ) ;
if ( ! V_15 )
return;
V_210 = F_163 ( sizeof( * V_210 ) , V_236 ) ;
if ( ! V_210 ) {
F_85 ( V_15 ) ;
return;
}
V_80 = & V_15 -> V_3 ;
F_164 ( V_4 , & V_80 -> V_3 , & V_237 ,
V_238 ) ;
V_80 -> V_239 = F_81 ;
V_80 -> V_240 = F_70 ;
V_80 -> V_230 = F_59 ;
V_80 -> V_241 = F_65 ;
if ( F_56 ( V_4 ) ) {
V_80 -> V_242 = F_129 ;
V_80 -> V_243 = F_138 ;
V_80 -> V_72 = F_69 ;
V_80 -> V_244 = F_133 ;
} else if ( F_158 ( V_4 ) ) {
V_80 -> V_242 = F_123 ;
V_80 -> V_243 = F_105 ;
V_80 -> V_72 = F_69 ;
V_80 -> V_244 = F_132 ;
} else {
V_80 -> V_243 = F_104 ;
V_80 -> V_72 = F_67 ;
}
V_80 -> type = V_125 ;
if ( F_56 ( V_4 ) ) {
if ( V_73 == V_224 )
V_80 -> V_245 = 1 << 2 ;
else
V_80 -> V_245 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_80 -> V_245 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_80 -> V_246 = 1 << V_247 ;
if ( F_74 ( V_4 ) )
V_80 -> V_246 |= 1 << V_125 ;
V_15 -> V_73 = V_73 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_248 . V_249 = 0 ;
F_154 ( V_15 , V_210 ) ;
}
