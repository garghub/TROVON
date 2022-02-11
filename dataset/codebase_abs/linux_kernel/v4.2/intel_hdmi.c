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
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_28 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
if ( F_25 ( V_15 -> V_46 ) == ( V_37 & V_47 ) )
return V_37 & V_40 ;
return false ;
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
struct V_14 * V_15 = F_24 ( V_13 ) ;
int V_50 = F_34 ( V_48 -> V_51 ) ;
T_2 V_37 = F_6 ( V_50 ) ;
if ( F_25 ( V_15 -> V_46 ) == ( V_37 & V_47 ) )
return V_37 & V_40 ;
return false ;
}
static void F_37 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_34 , T_3 V_35 )
{
const T_1 * V_36 = V_34 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_49 ) ;
T_2 V_52 = F_38 ( V_48 -> V_53 -> V_33 ) ;
T_2 V_54 ;
int V_39 ;
T_2 V_37 = F_6 ( V_52 ) ;
V_54 = F_15 ( type ,
V_48 -> V_53 -> V_33 ,
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
T_2 V_52 = F_38 ( V_48 -> V_53 -> V_33 ) ;
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
if ( V_48 -> V_53 -> V_66 )
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
T_2 V_50 = F_38 ( V_48 -> V_53 -> V_33 ) ;
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
struct V_59 * V_60 = & V_49 -> V_53 -> V_3 . V_60 ;
T_2 V_81 ;
V_81 = V_82 ;
if ( ! F_55 ( V_4 ) )
V_81 |= V_2 -> V_83 ;
if ( V_60 -> V_84 & V_85 )
V_81 |= V_86 ;
if ( V_60 -> V_84 & V_87 )
V_81 |= V_88 ;
if ( V_49 -> V_53 -> V_89 > 24 )
V_81 |= V_90 ;
else
V_81 |= V_91 ;
if ( V_49 -> V_53 -> V_92 )
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
V_98 -> V_3 . V_60 . V_84 |= V_84 ;
if ( ( V_96 & V_107 ) == V_90 )
V_99 = V_98 -> V_108 * 2 / 3 ;
else
V_99 = V_98 -> V_108 ;
if ( F_55 ( V_6 -> V_4 ) )
F_68 ( V_98 , V_99 ) ;
V_98 -> V_3 . V_60 . V_109 = V_99 ;
}
static void F_69 ( struct V_80 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_110 ;
T_2 V_111 = V_10 ;
if ( V_48 -> V_53 -> V_105 )
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
if ( V_48 -> V_53 -> V_105 ) {
F_71 ( ! V_48 -> V_53 -> V_92 ) ;
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
V_110 = F_6 ( V_2 -> V_11 ) ;
V_110 &= ~ ( V_10 | V_104 ) ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_70 ( V_4 ) && V_49 -> V_51 == V_112 ) {
V_110 &= ~ V_113 ;
V_110 |= V_10 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
V_110 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_110 ) ;
F_22 ( V_2 -> V_11 ) ;
}
}
static void F_76 ( struct V_80 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_53 -> V_105 )
F_77 ( V_13 ) ;
F_75 ( V_13 ) ;
}
static void F_78 ( struct V_80 * V_13 )
{
struct V_48 * V_49 = F_27 ( V_13 -> V_3 . V_49 ) ;
if ( V_49 -> V_53 -> V_105 )
F_77 ( V_13 ) ;
}
static void F_79 ( struct V_80 * V_13 )
{
F_75 ( V_13 ) ;
}
static int F_80 ( struct V_2 * V_16 , bool V_114 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_114 && ! V_16 -> V_92 ) || F_81 ( V_4 ) )
return 165000 ;
else if ( F_82 ( V_4 ) || F_83 ( V_4 ) -> V_115 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_116
F_84 ( struct V_17 * V_18 ,
struct V_59 * V_117 )
{
int clock = V_117 -> clock ;
if ( V_117 -> V_84 & V_118 )
clock *= 2 ;
if ( clock > F_80 ( F_9 ( V_18 ) ,
true ) )
return V_119 ;
if ( clock < 20000 )
return V_120 ;
if ( V_117 -> V_84 & V_121 )
return V_122 ;
return V_123 ;
}
static bool F_85 ( struct V_97 * V_124 )
{
struct V_1 * V_4 = V_124 -> V_3 . V_49 -> V_4 ;
struct V_125 * V_126 ;
struct V_80 * V_13 ;
struct V_17 * V_18 ;
struct V_127 * V_128 ;
int V_129 = 0 , V_130 = 0 ;
int V_39 ;
if ( F_86 ( V_4 ) )
return false ;
V_126 = V_124 -> V_3 . V_126 ;
F_87 (state, connector, connector_state, i) {
if ( V_128 -> V_49 != V_124 -> V_3 . V_49 )
continue;
V_13 = F_88 ( V_128 -> V_131 ) ;
V_130 += V_13 -> type == V_132 ;
V_129 ++ ;
}
return V_130 > 0 && V_130 == V_129 ;
}
bool F_89 ( struct V_80 * V_13 ,
struct V_97 * V_98 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_59 * V_60 = & V_98 -> V_3 . V_60 ;
int V_133 = V_98 -> V_3 . V_60 . V_109 * 3 / 2 ;
int V_134 = F_80 ( V_2 , false ) ;
int V_135 ;
V_98 -> V_92 = V_2 -> V_92 ;
if ( V_98 -> V_92 )
V_98 -> V_103 = true ;
if ( V_2 -> V_136 ) {
if ( V_98 -> V_92 &&
F_90 ( V_60 ) > 1 )
V_2 -> V_83 = V_106 ;
else
V_2 -> V_83 = 0 ;
}
if ( V_60 -> V_84 & V_118 ) {
V_98 -> V_137 = 2 ;
}
if ( V_2 -> V_83 )
V_98 -> V_66 = true ;
if ( F_55 ( V_4 ) && ! F_4 ( V_4 ) )
V_98 -> V_138 = true ;
if ( V_98 -> V_92 && V_2 -> V_105 )
V_98 -> V_105 = true ;
if ( V_98 -> V_89 > 8 * 3 && V_98 -> V_92 &&
V_133 <= V_134 &&
F_85 ( V_98 ) &&
0 ) {
F_91 ( L_9 ) ;
V_135 = 12 * 3 ;
V_98 -> V_108 = V_133 ;
} else {
F_91 ( L_10 ) ;
V_135 = 8 * 3 ;
}
if ( ! V_98 -> V_139 ) {
F_91 ( L_11 , V_135 ) ;
V_98 -> V_89 = V_135 ;
}
if ( V_60 -> V_109 > V_134 ) {
F_91 ( L_12 ) ;
return false ;
}
return true ;
}
static void
F_92 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_92 = false ;
V_2 -> V_105 = false ;
V_2 -> V_65 = false ;
F_93 ( F_94 ( V_18 ) -> V_140 ) ;
F_94 ( V_18 ) -> V_140 = NULL ;
}
static bool
F_95 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_96 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_80 * V_80 =
& F_2 ( V_2 ) -> V_3 ;
enum V_94 V_95 ;
struct V_141 * V_141 ;
bool V_142 = false ;
V_95 = F_62 ( V_80 ) ;
F_97 ( V_6 , V_95 ) ;
V_141 = F_98 ( V_18 ,
F_99 ( V_6 ,
V_2 -> V_143 ) ) ;
F_100 ( V_6 , V_95 ) ;
F_94 ( V_18 ) -> V_140 = V_141 ;
if ( V_141 && V_141 -> V_144 & V_145 ) {
V_2 -> V_65 =
F_101 ( V_141 ) ;
V_2 -> V_105 = F_102 ( V_141 ) ;
if ( V_2 -> V_146 != V_147 )
V_2 -> V_105 =
V_2 -> V_146 == V_148 ;
if ( V_2 -> V_146 != V_149 )
V_2 -> V_92 =
F_103 ( V_141 ) ;
V_142 = true ;
}
return V_142 ;
}
static enum V_150
F_104 ( struct V_17 * V_18 , bool V_151 )
{
enum V_150 V_152 ;
F_91 ( L_13 ,
V_18 -> V_3 . V_153 , V_18 -> V_154 ) ;
F_92 ( V_18 ) ;
if ( F_95 ( V_18 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_132 ;
V_152 = V_155 ;
} else
V_152 = V_156 ;
return V_152 ;
}
static void
F_105 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_91 ( L_13 ,
V_18 -> V_3 . V_153 , V_18 -> V_154 ) ;
F_92 ( V_18 ) ;
if ( V_18 -> V_152 != V_155 )
return;
F_95 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_132 ;
}
static int F_106 ( struct V_17 * V_18 )
{
struct V_141 * V_141 ;
V_141 = F_94 ( V_18 ) -> V_140 ;
if ( V_141 == NULL )
return 0 ;
return F_107 ( V_18 , V_141 ) ;
}
static bool
F_108 ( struct V_17 * V_18 )
{
bool V_105 = false ;
struct V_141 * V_141 ;
V_141 = F_94 ( V_18 ) -> V_140 ;
if ( V_141 && V_141 -> V_144 & V_145 )
V_105 = F_102 ( V_141 ) ;
return V_105 ;
}
static int
F_109 ( struct V_17 * V_18 ,
struct V_157 * V_158 ,
T_5 V_37 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_61 ;
V_61 = F_110 ( & V_18 -> V_3 , V_158 , V_37 ) ;
if ( V_61 )
return V_61 ;
if ( V_158 == V_6 -> V_159 ) {
enum V_160 V_39 = V_37 ;
bool V_105 ;
if ( V_39 == V_2 -> V_146 )
return 0 ;
V_2 -> V_146 = V_39 ;
if ( V_39 == V_147 )
V_105 = F_108 ( V_18 ) ;
else
V_105 = ( V_39 == V_148 ) ;
if ( V_39 == V_149 )
V_2 -> V_92 = 0 ;
V_2 -> V_105 = V_105 ;
goto V_161;
}
if ( V_158 == V_6 -> V_162 ) {
bool V_163 = V_2 -> V_136 ;
T_1 V_164 = V_2 -> V_83 ;
switch ( V_37 ) {
case V_165 :
V_2 -> V_136 = true ;
break;
case V_166 :
V_2 -> V_136 = false ;
V_2 -> V_83 = 0 ;
break;
case V_167 :
V_2 -> V_136 = false ;
V_2 -> V_83 = V_106 ;
break;
default:
return - V_168 ;
}
if ( V_163 == V_2 -> V_136 &&
V_164 == V_2 -> V_83 )
return 0 ;
goto V_161;
}
if ( V_158 == V_18 -> V_4 -> V_169 . V_170 ) {
switch ( V_37 ) {
case V_171 :
V_2 -> V_63 = V_172 ;
break;
case V_173 :
V_2 -> V_63 = V_174 ;
break;
case V_175 :
V_2 -> V_63 = V_176 ;
break;
default:
return - V_168 ;
}
goto V_161;
}
return - V_168 ;
V_161:
if ( V_15 -> V_3 . V_3 . V_49 )
F_111 ( V_15 -> V_3 . V_3 . V_49 ) ;
return 0 ;
}
static void F_112 ( struct V_80 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_48 * V_48 = F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 -> V_3 . V_60 ;
F_54 ( V_13 ) ;
V_2 -> V_177 ( & V_13 -> V_3 ,
V_48 -> V_53 -> V_92 ,
V_60 ) ;
}
static void F_113 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_178 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 -> V_3 . V_60 ;
enum V_179 V_46 = F_114 ( V_178 ) ;
int V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_115 ( & V_6 -> V_180 ) ;
V_37 = F_116 ( V_6 , V_51 , F_117 ( V_46 ) ) ;
V_37 = 0 ;
if ( V_51 )
V_37 |= ( 1 << 21 ) ;
else
V_37 &= ~ ( 1 << 21 ) ;
V_37 |= 0x001000c4 ;
F_118 ( V_6 , V_51 , F_119 ( V_46 ) , V_37 ) ;
F_118 ( V_6 , V_51 , F_120 ( V_46 ) , 0 ) ;
F_118 ( V_6 , V_51 , F_121 ( V_46 ) , 0x2b245f5f ) ;
F_118 ( V_6 , V_51 , F_122 ( V_46 ) , 0x5578b83a ) ;
F_118 ( V_6 , V_51 , F_123 ( V_46 ) , 0x0c782040 ) ;
F_118 ( V_6 , V_51 , F_124 ( V_46 ) , 0x2b247878 ) ;
F_118 ( V_6 , V_51 , F_125 ( V_46 ) , 0x00030000 ) ;
F_118 ( V_6 , V_51 , F_126 ( V_46 ) , 0x00002000 ) ;
F_118 ( V_6 , V_51 , F_120 ( V_46 ) , V_181 ) ;
F_118 ( V_6 , V_51 , F_127 ( V_46 ) , 0x00760018 ) ;
F_118 ( V_6 , V_51 , F_128 ( V_46 ) , 0x00400888 ) ;
F_129 ( & V_6 -> V_180 ) ;
V_2 -> V_177 ( & V_13 -> V_3 ,
V_48 -> V_53 -> V_92 ,
V_60 ) ;
F_69 ( V_13 ) ;
F_130 ( V_6 , V_178 , 0x0 ) ;
}
static void F_131 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_179 V_46 = F_114 ( V_178 ) ;
int V_51 = V_48 -> V_51 ;
F_54 ( V_13 ) ;
F_115 ( & V_6 -> V_180 ) ;
F_118 ( V_6 , V_51 , F_132 ( V_46 ) ,
V_182 |
V_183 ) ;
F_118 ( V_6 , V_51 , F_133 ( V_46 ) ,
V_184 |
V_185 |
( 1 << V_186 ) |
V_187 ) ;
F_118 ( V_6 , V_51 , F_134 ( V_46 ) , 0x00750f00 ) ;
F_118 ( V_6 , V_51 , F_135 ( V_46 ) , 0x00001500 ) ;
F_118 ( V_6 , V_51 , F_136 ( V_46 ) , 0x40400000 ) ;
F_118 ( V_6 , V_51 , F_126 ( V_46 ) , 0x00002000 ) ;
F_118 ( V_6 , V_51 , F_120 ( V_46 ) , V_181 ) ;
F_129 ( & V_6 -> V_180 ) ;
}
static void F_137 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_179 V_188 = F_114 ( V_178 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_54 ( V_13 ) ;
F_115 ( & V_6 -> V_180 ) ;
if ( V_51 != V_112 ) {
V_37 = F_116 ( V_6 , V_51 , V_189 ) ;
V_37 &= ~ ( V_190 | V_191 ) ;
if ( V_188 == V_192 )
V_37 |= V_193 ;
if ( V_188 == V_194 )
V_37 |= V_195 ;
F_118 ( V_6 , V_51 , V_189 , V_37 ) ;
} else {
V_37 = F_116 ( V_6 , V_51 , V_196 ) ;
V_37 &= ~ ( V_197 | V_198 ) ;
if ( V_188 == V_192 )
V_37 |= V_199 ;
if ( V_188 == V_194 )
V_37 |= V_200 ;
F_118 ( V_6 , V_51 , V_196 , V_37 ) ;
}
V_37 = F_116 ( V_6 , V_51 , F_117 ( V_188 ) ) ;
V_37 |= V_201 ;
if ( V_51 != V_112 )
V_37 &= ~ V_202 ;
else
V_37 |= V_202 ;
F_118 ( V_6 , V_51 , F_117 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_138 ( V_188 ) ) ;
V_37 |= V_201 ;
if ( V_51 != V_112 )
V_37 &= ~ V_202 ;
else
V_37 |= V_202 ;
F_118 ( V_6 , V_51 , F_138 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_139 ( V_188 ) ) ;
if ( V_51 != V_112 )
V_37 &= ~ V_203 ;
else
V_37 |= V_203 ;
F_118 ( V_6 , V_51 , F_139 ( V_188 ) , V_37 ) ;
F_129 ( & V_6 -> V_180 ) ;
}
static void F_140 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_179 V_46 = F_114 ( V_178 ) ;
int V_51 = V_48 -> V_51 ;
F_115 ( & V_6 -> V_180 ) ;
F_118 ( V_6 , V_51 , F_132 ( V_46 ) , 0x00000000 ) ;
F_118 ( V_6 , V_51 , F_133 ( V_46 ) , 0x00e00060 ) ;
F_129 ( & V_6 -> V_180 ) ;
}
static void F_141 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
enum V_179 V_188 = F_114 ( V_178 ) ;
enum V_51 V_51 = V_48 -> V_51 ;
T_2 V_37 ;
F_115 ( & V_6 -> V_180 ) ;
V_37 = F_116 ( V_6 , V_51 , F_142 ( V_188 ) ) ;
V_37 |= V_204 ;
F_118 ( V_6 , V_51 , F_142 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_143 ( V_188 ) ) ;
V_37 |= V_204 ;
F_118 ( V_6 , V_51 , F_143 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_144 ( V_188 ) ) ;
V_37 &= ~ ( V_182 | V_183 ) ;
F_118 ( V_6 , V_51 , F_144 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_145 ( V_188 ) ) ;
V_37 &= ~ ( V_182 | V_183 ) ;
F_118 ( V_6 , V_51 , F_145 ( V_188 ) , V_37 ) ;
F_129 ( & V_6 -> V_180 ) ;
}
static void F_146 ( struct V_80 * V_13 )
{
struct V_14 * V_178 = F_24 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_178 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_48 =
F_27 ( V_13 -> V_3 . V_49 ) ;
struct V_59 * V_60 =
& V_48 -> V_53 -> V_3 . V_60 ;
enum V_179 V_188 = F_114 ( V_178 ) ;
int V_51 = V_48 -> V_51 ;
int V_36 , V_39 , V_205 ;
T_2 V_37 ;
F_115 ( & V_6 -> V_180 ) ;
V_37 = F_116 ( V_6 , V_51 , F_147 ( V_188 ) ) ;
V_37 &= ~ V_206 ;
F_118 ( V_6 , V_51 , F_147 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_148 ( V_188 ) ) ;
V_37 &= ~ V_206 ;
F_118 ( V_6 , V_51 , F_148 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_142 ( V_188 ) ) ;
V_37 |= V_204 ;
F_118 ( V_6 , V_51 , F_142 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_143 ( V_188 ) ) ;
V_37 |= V_204 ;
F_118 ( V_6 , V_51 , F_143 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_144 ( V_188 ) ) ;
V_37 |= ( V_182 | V_183 ) ;
F_118 ( V_6 , V_51 , F_144 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_145 ( V_188 ) ) ;
V_37 |= ( V_182 | V_183 ) ;
F_118 ( V_6 , V_51 , F_145 ( V_188 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_36 = ( V_39 == 1 ) ? 0x0 : 0x1 ;
F_118 ( V_6 , V_51 , F_149 ( V_188 , V_39 ) ,
V_36 << V_207 ) ;
}
if ( V_48 -> V_53 -> V_108 > 270000 )
V_205 = 0x18 ;
else if ( V_48 -> V_53 -> V_108 > 135000 )
V_205 = 0xd ;
else if ( V_48 -> V_53 -> V_108 > 67500 )
V_205 = 0x7 ;
else if ( V_48 -> V_53 -> V_108 > 33750 )
V_205 = 0x4 ;
else
V_205 = 0x2 ;
V_37 = F_116 ( V_6 , V_51 , F_147 ( V_188 ) ) ;
V_37 |= F_150 ( 0x1f ) ;
F_118 ( V_6 , V_51 , F_147 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_148 ( V_188 ) ) ;
V_37 |= F_150 ( 0x1f ) ;
F_118 ( V_6 , V_51 , F_148 ( V_188 ) , V_37 ) ;
F_118 ( V_6 , V_51 , F_151 ( V_188 ) ,
F_152 ( V_205 ) |
V_208 |
F_153 ( 0x1f ) |
F_154 ( 6 ) |
F_155 ( 0 ) ) ;
F_118 ( V_6 , V_51 , F_156 ( V_188 ) ,
F_152 ( V_205 ) |
V_208 |
F_153 ( 0x1f ) |
F_154 ( 7 ) |
F_155 ( 5 ) ) ;
V_37 = F_116 ( V_6 , V_51 , F_157 ( V_188 ) ) ;
V_37 &= ~ ( V_209 | V_210 ) ;
V_37 &= ~ ( V_211 | V_212 ) ;
V_37 |= V_213 | V_214 ;
F_118 ( V_6 , V_51 , F_157 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_158 ( V_188 ) ) ;
V_37 &= ~ ( V_209 | V_210 ) ;
V_37 &= ~ ( V_211 | V_212 ) ;
V_37 |= V_213 | V_214 ;
F_118 ( V_6 , V_51 , F_158 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_159 ( V_188 ) ) ;
V_37 &= ~ ( V_215 | V_216 ) ;
V_37 |= V_217 | V_218 ;
F_118 ( V_6 , V_51 , F_159 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_160 ( V_188 ) ) ;
V_37 &= ~ ( V_215 | V_216 ) ;
V_37 |= V_217 | V_218 ;
F_118 ( V_6 , V_51 , F_160 ( V_188 ) , V_37 ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_116 ( V_6 , V_51 , F_161 ( V_188 , V_39 ) ) ;
V_37 &= ~ V_219 ;
V_37 |= 128 << V_220 ;
F_118 ( V_6 , V_51 , F_161 ( V_188 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_116 ( V_6 , V_51 , F_162 ( V_188 , V_39 ) ) ;
V_37 &= ~ V_221 ;
V_37 |= 102 << V_222 ;
F_118 ( V_6 , V_51 , F_162 ( V_188 , V_39 ) , V_37 ) ;
}
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ ) {
V_37 = F_116 ( V_6 , V_51 , F_163 ( V_188 , V_39 ) ) ;
V_37 &= ~ V_223 ;
F_118 ( V_6 , V_51 , F_163 ( V_188 , V_39 ) , V_37 ) ;
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
V_37 = F_116 ( V_6 , V_51 , F_157 ( V_188 ) ) ;
V_37 |= V_209 | V_210 ;
F_118 ( V_6 , V_51 , F_157 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , F_158 ( V_188 ) ) ;
V_37 |= V_209 | V_210 ;
F_118 ( V_6 , V_51 , F_158 ( V_188 ) , V_37 ) ;
V_37 = F_116 ( V_6 , V_51 , V_224 ) ;
V_37 |= V_225 ;
F_118 ( V_6 , V_51 , V_224 , V_37 ) ;
F_129 ( & V_6 -> V_180 ) ;
V_2 -> V_177 ( & V_13 -> V_3 ,
V_48 -> V_53 -> V_92 ,
V_60 ) ;
F_69 ( V_13 ) ;
F_130 ( V_6 , V_178 , 0x0 ) ;
}
static void F_164 ( struct V_17 * V_18 )
{
F_93 ( F_94 ( V_18 ) -> V_140 ) ;
F_165 ( V_18 ) ;
F_93 ( V_18 ) ;
}
static void
F_166 ( struct V_17 * V_18 )
{
if ( ! F_167 ( V_18 -> V_4 ) )
F_168 ( & V_18 -> V_3 ,
V_18 -> V_4 -> V_169 . V_170 ,
V_171 ) ;
}
static void
F_169 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_170 ( V_18 ) ;
F_171 ( V_18 ) ;
V_2 -> V_136 = true ;
F_166 ( V_18 ) ;
V_2 -> V_63 = V_172 ;
}
void F_172 ( struct V_14 * V_15 ,
struct V_226 * V_226 )
{
struct V_17 * V_18 = & V_226 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_80 * V_80 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_80 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_46 V_46 = V_15 -> V_46 ;
F_173 ( V_4 , V_18 , & V_227 ,
V_228 ) ;
F_174 ( V_18 , & V_229 ) ;
V_18 -> V_230 = 1 ;
V_18 -> V_231 = 0 ;
V_18 -> V_232 = 1 ;
switch ( V_46 ) {
case V_233 :
if ( F_175 ( V_6 ) )
V_2 -> V_143 = V_234 ;
else
V_2 -> V_143 = V_235 ;
V_80 -> V_236 = V_237 ;
break;
case V_238 :
if ( F_175 ( V_6 ) )
V_2 -> V_143 = V_239 ;
else
V_2 -> V_143 = V_240 ;
V_80 -> V_236 = V_241 ;
break;
case V_242 :
if ( F_71 ( F_175 ( V_6 ) ) )
V_2 -> V_143 = V_243 ;
else if ( F_58 ( V_6 ) )
V_2 -> V_143 = V_244 ;
else
V_2 -> V_143 = V_245 ;
V_80 -> V_236 = V_246 ;
break;
case V_247 :
V_80 -> V_236 = V_248 ;
default:
F_176 () ;
}
if ( F_177 ( V_4 ) ) {
V_2 -> V_57 = F_33 ;
V_2 -> V_177 = F_52 ;
V_2 -> V_102 = F_36 ;
} else if ( F_81 ( V_4 ) ) {
V_2 -> V_57 = F_19 ;
V_2 -> V_177 = F_49 ;
V_2 -> V_102 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_57 = F_37 ;
V_2 -> V_177 = F_53 ;
V_2 -> V_102 = F_39 ;
} else if ( F_70 ( V_4 ) ) {
V_2 -> V_57 = F_26 ;
V_2 -> V_177 = F_50 ;
V_2 -> V_102 = F_30 ;
} else {
V_2 -> V_57 = F_31 ;
V_2 -> V_177 = F_51 ;
V_2 -> V_102 = F_32 ;
}
if ( F_4 ( V_4 ) )
V_226 -> V_249 = V_250 ;
else
V_226 -> V_249 = V_251 ;
V_226 -> V_252 = V_253 ;
F_169 ( V_2 , V_18 ) ;
F_178 ( V_226 , V_80 ) ;
F_179 ( V_18 ) ;
if ( F_81 ( V_4 ) && ! F_180 ( V_4 ) ) {
T_2 V_110 = F_6 ( V_254 ) ;
F_20 ( V_254 , ( V_110 & ~ 0xf ) | 0xd ) ;
}
}
void F_181 ( struct V_1 * V_4 , int V_11 , enum V_46 V_46 )
{
struct V_14 * V_15 ;
struct V_80 * V_80 ;
struct V_226 * V_226 ;
V_15 = F_182 ( sizeof( * V_15 ) , V_255 ) ;
if ( ! V_15 )
return;
V_226 = F_183 () ;
if ( ! V_226 ) {
F_93 ( V_15 ) ;
return;
}
V_80 = & V_15 -> V_3 ;
F_184 ( V_4 , & V_80 -> V_3 , & V_256 ,
V_257 ) ;
V_80 -> V_258 = F_89 ;
if ( F_55 ( V_4 ) ) {
V_80 -> V_259 = F_78 ;
V_80 -> V_260 = F_79 ;
} else {
V_80 -> V_259 = F_76 ;
}
V_80 -> V_249 = F_61 ;
V_80 -> V_261 = F_67 ;
if ( F_58 ( V_4 ) ) {
V_80 -> V_262 = F_137 ;
V_80 -> V_263 = F_146 ;
V_80 -> V_74 = F_74 ;
V_80 -> V_260 = F_141 ;
} else if ( F_177 ( V_4 ) ) {
V_80 -> V_262 = F_131 ;
V_80 -> V_263 = F_113 ;
V_80 -> V_74 = F_74 ;
V_80 -> V_260 = F_140 ;
} else {
V_80 -> V_263 = F_112 ;
V_80 -> V_74 = F_69 ;
}
V_80 -> type = V_132 ;
if ( F_58 ( V_4 ) ) {
if ( V_46 == V_242 )
V_80 -> V_264 = 1 << 2 ;
else
V_80 -> V_264 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_80 -> V_264 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_80 -> V_265 = 1 << V_266 ;
if ( F_81 ( V_4 ) )
V_80 -> V_265 |= 1 << V_132 ;
V_15 -> V_46 = V_46 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_267 . V_268 = 0 ;
F_172 ( V_15 , V_226 ) ;
}
