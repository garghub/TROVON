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
static bool F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
T_2 V_37 = F_6 ( V_38 ) ;
if ( F_25 ( V_15 -> V_46 ) == ( V_37 & V_47 ) )
return V_37 & V_40 ;
return false ;
}
static void F_26 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
return V_37 & V_40 ;
}
static void F_31 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
if ( type != V_20 )
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_29 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_29 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_32 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
return V_37 & V_40 ;
}
static void F_33 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_39 , V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_5 ( ! ( V_37 & V_40 ) , L_3 ) ;
V_37 &= ~ ( V_41 | 0xf ) ;
V_37 |= F_11 ( type ) ;
V_37 &= ~ F_13 ( type ) ;
F_20 ( V_50 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( F_35 ( V_48 -> V_51 ) , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( F_35 ( V_48 -> V_51 ) , 0 ) ;
F_21 () ;
V_37 |= F_13 ( type ) ;
V_37 &= ~ V_44 ;
V_37 |= V_45 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
static bool F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
int V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
return V_37 & V_40 ;
}
static void F_37 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_52 = F_38 ( V_48 -> V_53 . V_33 ) ;
T_2 V_54 ;
int V_39 ;
T_2 V_37 = F_6 ( V_52 ) ;
V_54 = F_15 ( type ,
V_48 -> V_53 . V_33 ,
V_6 ) ;
if ( V_54 == 0 )
return;
V_37 &= ~ F_14 ( type ) ;
F_20 ( V_52 , V_37 ) ;
F_21 () ;
for ( V_39 = 0 ; V_39 < V_35 ; V_39 += 4 ) {
F_20 ( V_54 + V_39 , * V_36 ) ;
V_36 ++ ;
}
for (; V_39 < V_43 ; V_39 += 4 )
F_20 ( V_54 + V_39 , 0 ) ;
F_21 () ;
V_37 |= F_14 ( type ) ;
F_20 ( V_52 , V_37 ) ;
F_22 ( V_52 ) ;
}
static bool F_39 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_52 = F_38 ( V_48 -> V_53 . V_33 ) ;
T_2 V_37 = F_6 ( V_52 ) ;
return V_37 & ( V_29 | V_30 |
V_31 ) ;
}
static void F_40 ( struct V_12 * V_13 ,
union V_55 * V_34 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_4 V_56 [ V_43 ] ;
T_3 V_35 ;
V_35 = F_41 ( V_34 , V_56 + 1 , sizeof( V_56 ) - 1 ) ;
if ( V_35 < 0 )
return;
V_56 [ 0 ] = V_56 [ 1 ] ;
V_56 [ 1 ] = V_56 [ 2 ] ;
V_56 [ 2 ] = V_56 [ 3 ] ;
V_56 [ 3 ] = 0 ;
V_35 ++ ;
V_2 -> V_57 ( V_13 , V_34 -> V_58 . type , V_56 , V_35 ) ;
}
static void F_42 ( struct V_12 * V_13 ,
struct V_59 * V_60 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
union V_55 V_34 ;
int V_61 ;
V_60 -> V_62 = V_2 -> V_63 ;
V_61 = F_43 ( & V_34 . V_64 ,
V_60 ) ;
if ( V_61 < 0 ) {
F_44 ( L_4 ) ;
return;
}
if ( V_2 -> V_65 ) {
if ( V_48 -> V_53 . V_66 )
V_34 . V_64 . V_67 =
V_68 ;
else
V_34 . V_64 . V_67 =
V_69 ;
}
F_40 ( V_13 , & V_34 ) ;
}
static void F_45 ( struct V_12 * V_13 )
{
union V_55 V_34 ;
int V_61 ;
V_61 = F_46 ( & V_34 . V_70 , L_5 , L_6 ) ;
if ( V_61 < 0 ) {
F_44 ( L_7 ) ;
return;
}
V_34 . V_70 . V_71 = V_72 ;
F_40 ( V_13 , & V_34 ) ;
}
static void
F_47 ( struct V_12 * V_13 ,
struct V_59 * V_60 )
{
union V_55 V_34 ;
int V_61 ;
V_61 = F_48 ( & V_34 . V_73 . V_16 ,
V_60 ) ;
if ( V_61 < 0 )
return;
F_40 ( V_13 , & V_34 ) ;
}
static void F_49 ( struct V_12 * V_13 ,
bool V_74 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = V_38 ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_46 = F_25 ( V_15 -> V_46 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_74 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_46 != ( V_37 & V_47 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
V_37 &= ~ V_47 ;
V_37 |= V_46 ;
}
V_37 |= V_40 ;
V_37 &= ~ V_28 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_60 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_60 ) ;
}
static void F_50 ( struct V_12 * V_13 ,
bool V_74 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_46 = F_25 ( V_15 -> V_46 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_74 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_46 != ( V_37 & V_47 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
V_37 &= ~ V_47 ;
V_37 |= V_46 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_28 | V_75 |
V_76 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_60 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_60 ) ;
}
static void F_51 ( struct V_12 * V_13 ,
bool V_74 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_74 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ ( V_40 | V_26 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
V_37 |= V_40 | V_26 ;
V_37 &= ~ ( V_28 | V_75 |
V_76 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_60 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_60 ) ;
}
static void F_52 ( struct V_12 * V_13 ,
bool V_74 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_24 ( V_13 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
T_2 V_46 = F_25 ( V_15 -> V_46 ) ;
F_3 ( V_2 ) ;
V_37 |= V_21 | V_45 ;
if ( ! V_74 ) {
if ( ! ( V_37 & V_40 ) )
return;
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
return;
}
if ( V_46 != ( V_37 & V_47 ) ) {
if ( V_37 & V_40 ) {
V_37 &= ~ V_40 ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
}
V_37 &= ~ V_47 ;
V_37 |= V_46 ;
}
V_37 |= V_40 ;
V_37 &= ~ ( V_26 | V_28 |
V_75 | V_76 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_60 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_60 ) ;
}
static void F_53 ( struct V_12 * V_13 ,
bool V_74 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_2 V_50 = F_38 ( V_48 -> V_53 . V_33 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
F_3 ( V_2 ) ;
if ( ! V_74 ) {
F_20 ( V_50 , 0 ) ;
F_22 ( V_50 ) ;
return;
}
V_37 &= ~ ( V_77 | V_78 |
V_31 | V_79 ) ;
F_20 ( V_50 , V_37 ) ;
F_22 ( V_50 ) ;
F_42 ( V_13 , V_60 ) ;
F_45 ( V_13 ) ;
F_47 ( V_13 , V_60 ) ;
}
static void F_54 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_59 * V_60 = & V_49 -> V_53 . V_60 ;
T_2 V_81 ;
V_81 = V_82 ;
if ( ! F_55 ( V_4 ) )
V_81 |= V_2 -> V_83 ;
if ( V_60 -> V_84 & V_85 )
V_81 |= V_86 ;
if ( V_60 -> V_84 & V_87 )
V_81 |= V_88 ;
if ( V_49 -> V_53 . V_89 > 24 )
V_81 |= V_90 ;
else
V_81 |= V_91 ;
if ( V_49 -> V_53 . V_92 )
V_81 |= V_93 ;
if ( F_56 ( V_4 ) )
V_81 |= F_57 ( V_49 -> V_51 ) ;
else if ( F_58 ( V_4 ) )
V_81 |= F_59 ( V_49 -> V_51 ) ;
else
V_81 |= F_60 ( V_49 -> V_51 ) ;
F_20 ( V_2 -> V_11 , V_81 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_61 ( struct V_80 * V_13 ,
enum V_51 * V_51 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_94 V_95 ;
T_2 V_96 ;
V_95 = F_62 ( V_13 ) ;
if ( ! F_63 ( V_6 , V_95 ) )
return false ;
V_96 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_96 & V_10 ) )
return false ;
if ( F_56 ( V_4 ) )
* V_51 = F_64 ( V_96 ) ;
else if ( F_58 ( V_4 ) )
* V_51 = F_65 ( V_96 ) ;
else
* V_51 = F_66 ( V_96 ) ;
return true ;
}
static void F_67 ( struct V_80 * V_13 ,
struct V_97 * V_98 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_96 , V_84 = 0 ;
int V_99 ;
V_96 = F_6 ( V_2 -> V_11 ) ;
if ( V_96 & V_88 )
V_84 |= V_87 ;
else
V_84 |= V_100 ;
if ( V_96 & V_86 )
V_84 |= V_85 ;
else
V_84 |= V_101 ;
if ( V_96 & V_93 )
V_98 -> V_92 = true ;
if ( V_2 -> V_102 ( & V_13 -> V_3 ) )
V_98 -> V_103 = true ;
if ( V_96 & V_104 )
V_98 -> V_105 = true ;
if ( ! F_55 ( V_4 ) &&
V_96 & V_106 )
V_98 -> V_66 = true ;
V_98 -> V_60 . V_84 |= V_84 ;
if ( ( V_96 & V_107 ) == V_90 )
V_99 = V_98 -> V_108 * 2 / 3 ;
else
V_99 = V_98 -> V_108 ;
if ( F_55 ( V_6 -> V_4 ) )
F_68 ( V_98 , V_99 ) ;
V_98 -> V_60 . V_109 = V_99 ;
}
static void F_69 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_110 ;
T_2 V_111 = V_10 ;
if ( V_48 -> V_53 . V_105 )
V_111 |= V_104 ;
V_110 = F_6 ( V_2 -> V_11 ) ;
if ( F_70 ( V_4 ) )
V_111 |= F_60 ( V_48 -> V_51 ) ;
if ( F_55 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_110 |= V_111 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_55 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_48 -> V_53 . V_105 ) {
F_71 ( ! V_48 -> V_53 . V_92 ) ;
F_12 ( L_8 ,
F_72 ( V_48 -> V_51 ) ) ;
F_73 ( V_13 ) ;
}
}
static void F_74 ( struct V_80 * V_13 )
{
}
static void F_75 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
T_2 V_110 ;
T_2 V_111 = V_10 | V_104 ;
if ( V_49 -> V_53 . V_105 )
F_76 ( V_13 ) ;
V_110 = F_6 ( V_2 -> V_11 ) ;
if ( F_70 ( V_4 ) ) {
struct V_112 * V_49 = V_13 -> V_3 . V_49 ;
int V_51 = V_49 ? F_27 ( V_49 ) -> V_51 : - 1 ;
if ( V_110 & V_113 ) {
V_110 &= ~ V_113 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_49 )
F_77 ( V_4 , V_51 ) ;
else
F_78 ( 50 ) ;
}
}
if ( F_55 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
}
V_110 &= ~ V_111 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_55 ( V_4 ) ) {
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static int F_79 ( struct V_2 * V_16 , bool V_114 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_114 && ! V_16 -> V_92 ) || F_80 ( V_4 ) )
return 165000 ;
else if ( F_81 ( V_4 ) || F_82 ( V_4 ) -> V_115 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_116
F_83 ( struct V_17 * V_18 ,
struct V_59 * V_117 )
{
int clock = V_117 -> clock ;
if ( V_117 -> V_84 & V_118 )
clock *= 2 ;
if ( clock > F_79 ( F_9 ( V_18 ) ,
true ) )
return V_119 ;
if ( clock < 20000 )
return V_120 ;
if ( V_117 -> V_84 & V_121 )
return V_122 ;
return V_123 ;
}
static bool F_84 ( struct V_48 * V_49 )
{
struct V_1 * V_4 = V_49 -> V_3 . V_4 ;
struct V_80 * V_13 ;
int V_124 = 0 , V_125 = 0 ;
if ( F_85 ( V_4 ) )
return false ;
F_86 (dev, encoder) {
if ( V_13 -> V_126 != V_49 )
continue;
V_125 += V_13 -> type == V_127 ;
V_124 ++ ;
}
return V_125 > 0 && V_125 == V_124 ;
}
bool F_87 ( struct V_80 * V_13 ,
struct V_97 * V_98 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_59 * V_60 = & V_98 -> V_60 ;
int V_128 = V_98 -> V_60 . V_109 * 3 / 2 ;
int V_129 = F_79 ( V_2 , false ) ;
int V_130 ;
V_98 -> V_92 = V_2 -> V_92 ;
if ( V_98 -> V_92 )
V_98 -> V_103 = true ;
if ( V_2 -> V_131 ) {
if ( V_98 -> V_92 &&
F_88 ( V_60 ) > 1 )
V_2 -> V_83 = V_106 ;
else
V_2 -> V_83 = 0 ;
}
if ( V_60 -> V_84 & V_118 ) {
V_98 -> V_132 = 2 ;
}
if ( V_2 -> V_83 )
V_98 -> V_66 = true ;
if ( F_55 ( V_4 ) && ! F_4 ( V_4 ) )
V_98 -> V_133 = true ;
if ( V_98 -> V_92 && V_2 -> V_105 )
V_98 -> V_105 = true ;
if ( V_98 -> V_89 > 8 * 3 && V_98 -> V_92 &&
V_128 <= V_129 &&
F_84 ( V_13 -> V_126 ) ) {
F_89 ( L_9 ) ;
V_130 = 12 * 3 ;
V_98 -> V_108 = V_128 ;
} else {
F_89 ( L_10 ) ;
V_130 = 8 * 3 ;
}
if ( ! V_98 -> V_134 ) {
F_89 ( L_11 , V_130 ) ;
V_98 -> V_89 = V_130 ;
}
if ( V_60 -> V_109 > V_129 ) {
F_89 ( L_12 ) ;
return false ;
}
return true ;
}
static void
F_90 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_92 = false ;
V_2 -> V_105 = false ;
V_2 -> V_65 = false ;
F_91 ( F_92 ( V_18 ) -> V_135 ) ;
F_92 ( V_18 ) -> V_135 = NULL ;
}
static bool
F_93 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_94 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_80 * V_80 =
& F_2 ( V_2 ) -> V_3 ;
enum V_94 V_95 ;
struct V_136 * V_136 ;
bool V_137 = false ;
V_95 = F_62 ( V_80 ) ;
F_95 ( V_6 , V_95 ) ;
V_136 = F_96 ( V_18 ,
F_97 ( V_6 ,
V_2 -> V_138 ) ) ;
F_98 ( V_6 , V_95 ) ;
F_92 ( V_18 ) -> V_135 = V_136 ;
if ( V_136 && V_136 -> V_139 & V_140 ) {
V_2 -> V_65 =
F_99 ( V_136 ) ;
V_2 -> V_105 = F_100 ( V_136 ) ;
if ( V_2 -> V_141 != V_142 )
V_2 -> V_105 =
V_2 -> V_141 == V_143 ;
if ( V_2 -> V_141 != V_144 )
V_2 -> V_92 =
F_101 ( V_136 ) ;
V_137 = true ;
}
return V_137 ;
}
static enum V_145
F_102 ( struct V_17 * V_18 , bool V_146 )
{
enum V_145 V_147 ;
F_89 ( L_13 ,
V_18 -> V_3 . V_148 , V_18 -> V_149 ) ;
F_90 ( V_18 ) ;
if ( F_93 ( V_18 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_127 ;
V_147 = V_150 ;
} else
V_147 = V_151 ;
return V_147 ;
}
static void
F_103 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_89 ( L_13 ,
V_18 -> V_3 . V_148 , V_18 -> V_149 ) ;
F_90 ( V_18 ) ;
if ( V_18 -> V_147 != V_150 )
return;
F_93 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_127 ;
}
static int F_104 ( struct V_17 * V_18 )
{
struct V_136 * V_136 ;
V_136 = F_92 ( V_18 ) -> V_135 ;
if ( V_136 == NULL )
return 0 ;
return F_105 ( V_18 , V_136 ) ;
}
static bool
F_106 ( struct V_17 * V_18 )
{
bool V_105 = false ;
struct V_136 * V_136 ;
V_136 = F_92 ( V_18 ) -> V_135 ;
if ( V_136 && V_136 -> V_139 & V_140 )
V_105 = F_100 ( V_136 ) ;
return V_105 ;
}
static int
F_107 ( struct V_17 * V_18 ,
struct V_152 * V_153 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_61 ;
V_61 = F_108 ( & V_18 -> V_3 , V_153 , V_37 ) ;
if ( V_61 )
return V_61 ;
if ( V_153 == V_6 -> V_154 ) {
enum V_155 V_39 = V_37 ;
bool V_105 ;
if ( V_39 == V_2 -> V_141 )
return 0 ;
V_2 -> V_141 = V_39 ;
if ( V_39 == V_142 )
V_105 = F_106 ( V_18 ) ;
else
V_105 = ( V_39 == V_143 ) ;
if ( V_39 == V_144 )
V_2 -> V_92 = 0 ;
V_2 -> V_105 = V_105 ;
goto V_156;
}
if ( V_153 == V_6 -> V_157 ) {
bool V_158 = V_2 -> V_131 ;
T_1 V_159 = V_2 -> V_83 ;
switch ( V_37 ) {
case V_160 :
V_2 -> V_131 = true ;
break;
case V_161 :
V_2 -> V_131 = false ;
V_2 -> V_83 = 0 ;
break;
case V_162 :
V_2 -> V_131 = false ;
V_2 -> V_83 = V_106 ;
break;
default:
return - V_163 ;
}
if ( V_158 == V_2 -> V_131 &&
V_159 == V_2 -> V_83 )
return 0 ;
goto V_156;
}
if ( V_153 == V_18 -> V_4 -> V_164 . V_165 ) {
switch ( V_37 ) {
case V_166 :
V_2 -> V_63 = V_167 ;
break;
case V_168 :
V_2 -> V_63 = V_169 ;
break;
case V_170 :
V_2 -> V_63 = V_171 ;
break;
default:
return - V_163 ;
}
goto V_156;
}
return - V_163 ;
V_156:
if ( V_15 -> V_3 . V_3 . V_49 )
F_109 ( V_15 -> V_3 . V_3 . V_49 ) ;
return 0 ;
}
static void F_110 ( struct V_80 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 . V_60 ;
F_54 ( V_13 ) ;
V_2 -> V_172 ( & V_13 -> V_3 ,
V_48 -> V_53 . V_92 ,
V_60 ) ;
}
static void F_111 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_173 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 . V_60 ;
enum V_174 V_46 = F_112 ( V_173 ) ;
int V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_113 ( & V_6 -> V_175 ) ;
V_37 = F_114 ( V_6 , V_51 , F_115 ( V_46 ) ) ;
V_37 = 0 ;
if ( V_51 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_116 ( V_6 , V_51 , F_117 ( V_46 ) , V_37 ) ;
F_116 ( V_6 , V_51 , F_118 ( V_46 ) , 0 ) ;
F_116 ( V_6 , V_51 , F_119 ( V_46 ) , 0x2b245f5f ) ;
F_116 ( V_6 , V_51 , F_120 ( V_46 ) , 0x5578b83a ) ;
F_116 ( V_6 , V_51 , F_121 ( V_46 ) , 0x0c782040 ) ;
F_116 ( V_6 , V_51 , F_122 ( V_46 ) , 0x2b247878 ) ;
F_116 ( V_6 , V_51 , F_123 ( V_46 ) , 0x00030000 ) ;
F_116 ( V_6 , V_51 , F_124 ( V_46 ) , 0x00002000 ) ;
F_116 ( V_6 , V_51 , F_118 ( V_46 ) , V_176 ) ;
F_116 ( V_6 , V_51 , F_125 ( V_46 ) , 0x00760018 ) ;
F_116 ( V_6 , V_51 , F_126 ( V_46 ) , 0x00400888 ) ;
F_127 ( & V_6 -> V_175 ) ;
V_2 -> V_172 ( & V_13 -> V_3 ,
V_48 -> V_53 . V_92 ,
V_60 ) ;
F_69 ( V_13 ) ;
F_128 ( V_6 , V_173 ) ;
}
static void F_129 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_174 V_46 = F_112 ( V_173 ) ;
int V_51 = V_48 -> V_51 ;
F_54 ( V_13 ) ;
F_113 ( & V_6 -> V_175 ) ;
F_116 ( V_6 , V_51 , F_130 ( V_46 ) ,
V_177 |
V_178 ) ;
F_116 ( V_6 , V_51 , F_131 ( V_46 ) ,
V_179 |
V_180 |
( 1 << V_181 ) |
V_182 ) ;
F_116 ( V_6 , V_51 , F_132 ( V_46 ) , 0x00750f00 ) ;
F_116 ( V_6 , V_51 , F_133 ( V_46 ) , 0x00001500 ) ;
F_116 ( V_6 , V_51 , F_134 ( V_46 ) , 0x40400000 ) ;
F_116 ( V_6 , V_51 , F_124 ( V_46 ) , 0x00002000 ) ;
F_116 ( V_6 , V_51 , F_118 ( V_46 ) , V_176 ) ;
F_127 ( & V_6 -> V_175 ) ;
}
static void F_135 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_174 V_183 = F_112 ( V_173 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_54 ( V_13 ) ;
F_113 ( & V_6 -> V_175 ) ;
if ( V_51 != V_184 ) {
V_37 = F_114 ( V_6 , V_51 , V_185 ) ;
V_37 &= ~ ( V_186 | V_187 ) ;
if ( V_183 == V_188 )
V_37 |= V_189 ;
if ( V_183 == V_190 )
V_37 |= V_191 ;
F_116 ( V_6 , V_51 , V_185 , V_37 ) ;
} else {
V_37 = F_114 ( V_6 , V_51 , V_192 ) ;
V_37 &= ~ ( V_193 | V_194 ) ;
if ( V_183 == V_188 )
V_37 |= V_195 ;
if ( V_183 == V_190 )
V_37 |= V_196 ;
F_116 ( V_6 , V_51 , V_192 , V_37 ) ;
}
V_37 = F_114 ( V_6 , V_51 , F_115 ( V_183 ) ) ;
V_37 |= V_197 ;
if ( V_51 != V_184 )
V_37 &= ~ V_198 ;
else
V_37 |= V_198 ;
F_116 ( V_6 , V_51 , F_115 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_136 ( V_183 ) ) ;
V_37 |= V_197 ;
if ( V_51 != V_184 )
V_37 &= ~ V_198 ;
else
V_37 |= V_198 ;
F_116 ( V_6 , V_51 , F_136 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_137 ( V_183 ) ) ;
if ( V_51 != V_184 )
V_37 &= ~ V_199 ;
else
V_37 |= V_199 ;
F_116 ( V_6 , V_51 , F_137 ( V_183 ) , V_37 ) ;
F_127 ( & V_6 -> V_175 ) ;
}
static void F_138 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_174 V_46 = F_112 ( V_173 ) ;
int V_51 = V_48 -> V_51 ;
F_113 ( & V_6 -> V_175 ) ;
F_116 ( V_6 , V_51 , F_130 ( V_46 ) , 0x00000000 ) ;
F_116 ( V_6 , V_51 , F_131 ( V_46 ) , 0x00e00060 ) ;
F_127 ( & V_6 -> V_175 ) ;
}
static void F_139 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_174 V_183 = F_112 ( V_173 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_113 ( & V_6 -> V_175 ) ;
V_37 = F_114 ( V_6 , V_51 , F_140 ( V_183 ) ) ;
V_37 |= V_200 ;
F_116 ( V_6 , V_51 , F_140 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_141 ( V_183 ) ) ;
V_37 |= V_200 ;
F_116 ( V_6 , V_51 , F_141 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_142 ( V_183 ) ) ;
V_37 &= ~ ( V_177 | V_178 ) ;
F_116 ( V_6 , V_51 , F_142 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_143 ( V_183 ) ) ;
V_37 &= ~ ( V_177 | V_178 ) ;
F_116 ( V_6 , V_51 , F_143 ( V_183 ) , V_37 ) ;
F_127 ( & V_6 -> V_175 ) ;
}
static void F_144 ( struct V_80 * V_13 )
{
struct V_14 * V_173 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_173 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 . V_60 ;
enum V_174 V_183 = F_112 ( V_173 ) ;
int V_51 = V_48 -> V_51 ;
int V_36 , V_39 ;
T_2 V_37 ;
F_113 ( & V_6 -> V_175 ) ;
V_37 = F_114 ( V_6 , V_51 , F_145 ( V_183 ) ) ;
V_37 &= ~ V_201 ;
F_116 ( V_6 , V_51 , F_145 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_146 ( V_183 ) ) ;
V_37 &= ~ V_201 ;
F_116 ( V_6 , V_51 , F_146 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_140 ( V_183 ) ) ;
V_37 |= V_200 ;
F_116 ( V_6 , V_51 , F_140 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_141 ( V_183 ) ) ;
V_37 |= V_200 ;
F_116 ( V_6 , V_51 , F_141 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_142 ( V_183 ) ) ;
V_37 |= ( V_177 | V_178 ) ;
F_116 ( V_6 , V_51 , F_142 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_143 ( V_183 ) ) ;
V_37 |= ( V_177 | V_178 ) ;
F_116 ( V_6 , V_51 , F_143 ( V_183 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_36 = ( V_39 == 1 ) ? 0x0 : 0x6 ;
F_116 ( V_6 , V_51 , F_147 ( V_183 , V_39 ) ,
V_36 << V_202 ) ;
V_36 = ( V_39 == 1 ) ? 0x0 : 0x1 ;
F_116 ( V_6 , V_51 , F_148 ( V_183 , V_39 ) ,
V_36 << V_203 ) ;
}
V_37 = F_114 ( V_6 , V_51 , F_149 ( V_183 ) ) ;
V_37 &= ~ ( V_204 | V_205 ) ;
V_37 &= ~ ( V_206 | V_207 ) ;
V_37 |= V_208 | V_209 ;
F_116 ( V_6 , V_51 , F_149 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_150 ( V_183 ) ) ;
V_37 &= ~ ( V_204 | V_205 ) ;
V_37 &= ~ ( V_206 | V_207 ) ;
V_37 |= V_208 | V_209 ;
F_116 ( V_6 , V_51 , F_150 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_151 ( V_183 ) ) ;
V_37 &= ~ ( V_210 | V_211 ) ;
V_37 |= V_212 | V_213 ;
F_116 ( V_6 , V_51 , F_151 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_152 ( V_183 ) ) ;
V_37 &= ~ ( V_210 | V_211 ) ;
V_37 |= V_212 | V_213 ;
F_116 ( V_6 , V_51 , F_152 ( V_183 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_114 ( V_6 , V_51 , F_153 ( V_183 , V_39 ) ) ;
V_37 &= ~ V_214 ;
V_37 |= 128 << V_215 ;
F_116 ( V_6 , V_51 , F_153 ( V_183 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_114 ( V_6 , V_51 , F_154 ( V_183 , V_39 ) ) ;
V_37 &= ~ V_216 ;
V_37 |= 102 << V_217 ;
F_116 ( V_6 , V_51 , F_154 ( V_183 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_114 ( V_6 , V_51 , F_155 ( V_183 , V_39 ) ) ;
V_37 &= ~ V_218 ;
F_116 ( V_6 , V_51 , F_155 ( V_183 , V_39 ) , V_37 ) ;
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
V_37 = F_114 ( V_6 , V_51 , F_149 ( V_183 ) ) ;
V_37 |= V_204 | V_205 ;
F_116 ( V_6 , V_51 , F_149 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , F_150 ( V_183 ) ) ;
V_37 |= V_204 | V_205 ;
F_116 ( V_6 , V_51 , F_150 ( V_183 ) , V_37 ) ;
V_37 = F_114 ( V_6 , V_51 , V_219 ) ;
V_37 |= V_220 ;
F_116 ( V_6 , V_51 , V_219 , V_37 ) ;
F_127 ( & V_6 -> V_175 ) ;
V_2 -> V_172 ( & V_13 -> V_3 ,
V_48 -> V_53 . V_92 ,
V_60 ) ;
F_69 ( V_13 ) ;
F_128 ( V_6 , V_173 ) ;
}
static void F_156 ( struct V_17 * V_18 )
{
F_91 ( F_92 ( V_18 ) -> V_135 ) ;
F_157 ( V_18 ) ;
F_91 ( V_18 ) ;
}
static void
F_158 ( struct V_17 * V_18 )
{
if ( ! F_159 ( V_18 -> V_4 ) )
F_160 ( & V_18 -> V_3 ,
V_18 -> V_4 -> V_164 . V_165 ,
V_166 ) ;
}
static void
F_161 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_162 ( V_18 ) ;
F_163 ( V_18 ) ;
V_2 -> V_131 = true ;
F_158 ( V_18 ) ;
V_2 -> V_63 = V_167 ;
}
void F_164 ( struct V_14 * V_15 ,
struct V_221 * V_221 )
{
struct V_17 * V_18 = & V_221 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_80 * V_80 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_80 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_46 V_46 = V_15 -> V_46 ;
F_165 ( V_4 , V_18 , & V_222 ,
V_223 ) ;
F_166 ( V_18 , & V_224 ) ;
V_18 -> V_225 = 1 ;
V_18 -> V_226 = 0 ;
V_18 -> V_227 = 1 ;
switch ( V_46 ) {
case V_228 :
V_2 -> V_138 = V_229 ;
V_80 -> V_230 = V_231 ;
break;
case V_232 :
V_2 -> V_138 = V_233 ;
V_80 -> V_230 = V_234 ;
break;
case V_235 :
if ( F_58 ( V_4 ) )
V_2 -> V_138 = V_236 ;
else
V_2 -> V_138 = V_237 ;
V_80 -> V_230 = V_238 ;
break;
case V_239 :
V_80 -> V_230 = V_240 ;
default:
F_167 () ;
}
if ( F_168 ( V_4 ) ) {
V_2 -> V_57 = F_33 ;
V_2 -> V_172 = F_52 ;
V_2 -> V_102 = F_36 ;
} else if ( F_80 ( V_4 ) ) {
V_2 -> V_57 = F_19 ;
V_2 -> V_172 = F_49 ;
V_2 -> V_102 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_57 = F_37 ;
V_2 -> V_172 = F_53 ;
V_2 -> V_102 = F_39 ;
} else if ( F_70 ( V_4 ) ) {
V_2 -> V_57 = F_26 ;
V_2 -> V_172 = F_50 ;
V_2 -> V_102 = F_30 ;
} else {
V_2 -> V_57 = F_31 ;
V_2 -> V_172 = F_51 ;
V_2 -> V_102 = F_32 ;
}
if ( F_4 ( V_4 ) )
V_221 -> V_241 = V_242 ;
else
V_221 -> V_241 = V_243 ;
V_221 -> V_244 = V_245 ;
F_161 ( V_2 , V_18 ) ;
F_169 ( V_221 , V_80 ) ;
F_170 ( V_18 ) ;
if ( F_80 ( V_4 ) && ! F_171 ( V_4 ) ) {
T_2 V_110 = F_6 ( V_246 ) ;
F_20 ( V_246 , ( V_110 & ~ 0xf ) | 0xd ) ;
}
}
void F_172 ( struct V_1 * V_4 , int V_11 , enum V_46 V_46 )
{
struct V_14 * V_15 ;
struct V_80 * V_80 ;
struct V_221 * V_221 ;
V_15 = F_173 ( sizeof( * V_15 ) , V_247 ) ;
if ( ! V_15 )
return;
V_221 = F_173 ( sizeof( * V_221 ) , V_247 ) ;
if ( ! V_221 ) {
F_91 ( V_15 ) ;
return;
}
V_80 = & V_15 -> V_3 ;
F_174 ( V_4 , & V_80 -> V_3 , & V_248 ,
V_249 ) ;
V_80 -> V_250 = F_87 ;
V_80 -> V_251 = F_75 ;
V_80 -> V_241 = F_61 ;
V_80 -> V_252 = F_67 ;
if ( F_58 ( V_4 ) ) {
V_80 -> V_253 = F_135 ;
V_80 -> V_254 = F_144 ;
V_80 -> V_74 = F_74 ;
V_80 -> V_255 = F_139 ;
} else if ( F_168 ( V_4 ) ) {
V_80 -> V_253 = F_129 ;
V_80 -> V_254 = F_111 ;
V_80 -> V_74 = F_74 ;
V_80 -> V_255 = F_138 ;
} else {
V_80 -> V_254 = F_110 ;
V_80 -> V_74 = F_69 ;
}
V_80 -> type = V_127 ;
if ( F_58 ( V_4 ) ) {
if ( V_46 == V_235 )
V_80 -> V_256 = 1 << 2 ;
else
V_80 -> V_256 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_80 -> V_256 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_80 -> V_257 = 1 << V_258 ;
if ( F_80 ( V_4 ) )
V_80 -> V_257 |= 1 << V_127 ;
V_15 -> V_46 = V_46 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_259 . V_260 = 0 ;
F_164 ( V_15 , V_221 ) ;
}
