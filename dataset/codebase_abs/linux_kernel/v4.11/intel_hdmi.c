static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 ) -> V_3 . V_3 . V_4 ;
}
static void
F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_1 V_7 ;
V_7 = F_5 ( V_6 ) ? V_8 : V_9 ;
F_6 ( F_7 ( V_2 -> V_10 ) & V_7 ,
L_1 ) ;
}
struct V_2 * F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 =
F_9 ( V_12 , struct V_13 , V_3 . V_3 ) ;
return & V_14 -> V_15 ;
}
static struct V_2 * F_10 ( struct V_16 * V_17 )
{
return F_8 ( & F_11 ( V_17 ) -> V_3 ) ;
}
static T_2 F_12 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_20 ;
case V_21 :
return V_22 ;
case V_23 :
return V_24 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_2 F_14 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_25 ;
case V_21 :
return V_26 ;
case V_23 :
return V_27 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_2 F_15 ( enum V_18 type )
{
switch ( type ) {
case V_19 :
return V_28 ;
case V_21 :
return V_29 ;
case V_23 :
return V_30 ;
default:
F_13 ( type ) ;
return 0 ;
}
}
static T_3
F_16 ( struct V_5 * V_6 ,
enum V_31 V_32 ,
enum V_18 type ,
int V_33 )
{
switch ( type ) {
case V_19 :
return F_17 ( V_32 , V_33 ) ;
case V_21 :
return F_18 ( V_32 , V_33 ) ;
case V_23 :
return F_19 ( V_32 , V_33 ) ;
default:
F_13 ( type ) ;
return V_34 ;
}
}
static void F_20 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_40 = F_7 ( V_41 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_41 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( V_44 , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( V_44 , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_41 , V_40 ) ;
F_23 ( V_41 ) ;
}
static bool F_24 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
T_2 V_40 = F_7 ( V_41 ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_26 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_30 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_31 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_3 V_53 = F_29 ( V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_32 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
if ( type != V_19 )
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_30 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_33 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_40 = F_7 ( F_29 ( V_54 ) ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_34 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
int V_33 ;
F_6 ( ! ( V_40 & V_42 ) , L_2 ) ;
V_40 &= ~ ( V_43 | 0xf ) ;
V_40 |= F_12 ( type ) ;
V_40 &= ~ F_14 ( type ) ;
F_21 ( V_53 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_36 ( V_51 -> V_54 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_36 ( V_51 -> V_54 ) , 0 ) ;
F_22 () ;
V_40 |= F_14 ( type ) ;
V_40 &= ~ V_46 ;
V_40 |= V_47 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
}
static bool F_37 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_40 = F_7 ( F_35 ( V_54 ) ) ;
if ( ( V_40 & V_42 ) == 0 )
return false ;
if ( ( V_40 & V_49 ) != F_26 ( V_14 -> V_50 ) )
return false ;
return V_40 & ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
}
static void F_38 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
enum V_18 type ,
const void * V_37 , T_4 V_38 )
{
const T_1 * V_39 = V_37 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_31 V_32 = V_36 -> V_32 ;
T_3 V_57 = F_39 ( V_32 ) ;
T_3 V_58 ;
int V_33 ;
T_2 V_40 = F_7 ( V_57 ) ;
V_58 = F_16 ( V_6 , V_32 , type , 0 ) ;
V_40 &= ~ F_15 ( type ) ;
F_21 ( V_57 , V_40 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 += 4 ) {
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , * V_39 ) ;
V_39 ++ ;
}
for (; V_33 < V_45 ; V_33 += 4 )
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , 0 ) ;
F_22 () ;
V_40 |= F_15 ( type ) ;
F_21 ( V_57 , V_40 ) ;
F_23 ( V_57 ) ;
}
static bool F_40 ( struct V_11 * V_12 ,
const struct V_35 * V_48 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
T_2 V_40 = F_7 ( F_39 ( V_48 -> V_32 ) ) ;
return V_40 & ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
union V_62 * V_37 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_5 V_63 [ V_45 ] ;
T_4 V_38 ;
V_38 = F_42 ( V_37 , V_63 + 1 , sizeof( V_63 ) - 1 ) ;
if ( V_38 < 0 )
return;
V_63 [ 0 ] = V_63 [ 1 ] ;
V_63 [ 1 ] = V_63 [ 2 ] ;
V_63 [ 2 ] = V_63 [ 3 ] ;
V_63 [ 3 ] = 0 ;
V_38 ++ ;
V_2 -> V_64 ( V_12 , V_36 , V_37 -> V_65 . type , V_63 , V_38 ) ;
}
static void F_43 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
const struct V_66 * V_67 =
& V_36 -> V_3 . V_67 ;
union V_62 V_37 ;
int V_68 ;
V_68 = F_44 ( & V_37 . V_69 ,
V_67 ) ;
if ( V_68 < 0 ) {
F_45 ( L_3 ) ;
return;
}
F_46 ( & V_37 . V_69 , V_67 ,
V_36 -> V_70 ?
V_71 :
V_72 ,
V_2 -> V_73 ) ;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void F_47 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
union V_62 V_37 ;
int V_68 ;
V_68 = F_48 ( & V_37 . V_74 , L_4 , L_5 ) ;
if ( V_68 < 0 ) {
F_45 ( L_6 ) ;
return;
}
V_37 . V_74 . V_75 = V_76 ;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void
F_49 ( struct V_11 * V_12 ,
const struct V_35 * V_36 )
{
union V_62 V_37 ;
int V_68 ;
V_68 = F_50 ( & V_37 . V_77 . V_15 ,
& V_36 -> V_3 . V_67 ) ;
if ( V_68 < 0 )
return;
F_41 ( V_12 , V_36 , & V_37 ) ;
}
static void F_51 ( struct V_11 * V_12 ,
bool V_78 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_53 = V_41 ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_78 ) {
if ( ! ( V_40 & V_42 ) )
return;
if ( V_50 != ( V_40 & V_49 ) ) {
F_52 ( L_7 ,
( V_40 & V_49 ) >> 29 ) ;
return;
}
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_26 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
if ( V_40 & V_42 ) {
F_52 ( L_8 ,
( V_40 & V_49 ) >> 29 ) ;
return;
}
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_26 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static bool F_53 ( const struct V_79 * V_80 )
{
struct V_16 * V_17 = V_80 -> V_17 ;
return V_17 -> V_81 . V_82 > 8 ;
}
static bool F_54 ( int V_83 ,
const struct V_66 * V_84 )
{
unsigned int V_85 ;
switch ( V_83 ) {
case 30 :
V_85 = 4 ;
break;
case 36 :
V_85 = 2 ;
break;
case 48 :
V_85 = 1 ;
break;
default:
return false ;
}
return V_84 -> V_86 % V_85 == 0 &&
V_84 -> V_87 % V_85 == 0 &&
V_84 -> V_88 % V_85 == 0 &&
V_84 -> V_89 % V_85 == 0 &&
V_84 -> V_90 % V_85 == 0 &&
V_84 -> V_91 % V_85 == 0 &&
( ( V_84 -> V_92 & V_93 ) == 0 ||
V_84 -> V_87 / 2 % V_85 == 0 ) ;
}
static bool F_55 ( struct V_11 * V_12 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_52 = F_28 ( V_36 -> V_3 . V_52 ) ;
T_3 V_53 ;
T_2 V_40 = 0 ;
if ( F_5 ( V_6 ) )
V_53 = F_56 ( V_36 -> V_32 ) ;
else if ( F_57 ( V_6 ) || F_58 ( V_6 ) )
V_53 = F_59 ( V_52 -> V_54 ) ;
else if ( F_60 ( V_6 ) )
V_53 = F_61 ( V_52 -> V_54 ) ;
else
return false ;
if ( F_53 ( V_80 ) )
V_40 |= V_94 ;
if ( F_54 ( V_36 -> V_83 ,
& V_36 -> V_3 . V_67 ) )
V_40 |= V_95 ;
F_21 ( V_53 , V_40 ) ;
return V_40 != 0 ;
}
static void F_62 ( struct V_11 * V_12 ,
bool V_78 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_78 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
F_6 ( V_40 & V_42 ,
L_9 ,
( V_40 & V_49 ) >> 29 ) ;
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_80 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_63 ( struct V_11 * V_12 ,
bool V_78 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_78 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
V_40 |= V_42 | V_25 ;
V_40 &= ~ ( V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_80 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_64 ( struct V_11 * V_12 ,
bool V_78 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_51 * V_51 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
T_2 V_50 = F_26 ( V_14 -> V_50 ) ;
F_3 ( V_2 ) ;
V_40 |= V_20 | V_47 ;
if ( ! V_78 ) {
if ( ! ( V_40 & V_42 ) )
return;
V_40 &= ~ ( V_42 | V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( V_50 != ( V_40 & V_49 ) ) {
F_6 ( V_40 & V_42 ,
L_9 ,
( V_40 & V_49 ) >> 29 ) ;
V_40 &= ~ V_49 ;
V_40 |= V_50 ;
}
V_40 |= V_42 ;
V_40 &= ~ ( V_25 |
V_27 | V_55 |
V_26 | V_56 ) ;
if ( F_55 ( V_12 , V_36 , V_80 ) )
V_40 |= V_56 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
static void F_65 ( struct V_11 * V_12 ,
bool V_78 ,
const struct V_35 * V_36 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_53 = F_39 ( V_36 -> V_32 ) ;
T_2 V_40 = F_7 ( V_53 ) ;
F_3 ( V_2 ) ;
V_40 &= ~ ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
if ( ! V_78 ) {
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
return;
}
if ( F_55 ( V_12 , V_36 , V_80 ) )
V_40 |= V_60 ;
F_21 ( V_53 , V_40 ) ;
F_23 ( V_53 ) ;
F_43 ( V_12 , V_36 ) ;
F_47 ( V_12 , V_36 ) ;
F_49 ( V_12 , V_36 ) ;
}
void F_66 ( struct V_2 * V_15 , bool V_78 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
struct V_96 * V_97 =
F_67 ( V_6 , V_15 -> V_98 ) ;
if ( V_15 -> V_99 . type < V_100 )
return;
F_52 ( L_10 ,
V_78 ? L_11 : L_12 ) ;
F_68 ( V_15 -> V_99 . type ,
V_97 , V_78 ) ;
}
static void F_69 ( struct V_101 * V_12 ,
const struct V_35 * V_36 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_52 = F_28 ( V_36 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
const struct V_66 * V_67 = & V_36 -> V_3 . V_67 ;
T_2 V_102 ;
F_66 ( V_2 , true ) ;
V_102 = V_103 ;
if ( ! F_60 ( V_6 ) && V_36 -> V_70 )
V_102 |= V_104 ;
if ( V_67 -> V_92 & V_105 )
V_102 |= V_106 ;
if ( V_67 -> V_92 & V_107 )
V_102 |= V_108 ;
if ( V_36 -> V_83 > 24 )
V_102 |= V_109 ;
else
V_102 |= V_110 ;
if ( V_36 -> V_111 )
V_102 |= V_112 ;
if ( F_70 ( V_6 ) )
V_102 |= F_71 ( V_52 -> V_54 ) ;
else if ( F_58 ( V_6 ) )
V_102 |= F_72 ( V_52 -> V_54 ) ;
else
V_102 |= F_73 ( V_52 -> V_54 ) ;
F_21 ( V_2 -> V_10 , V_102 ) ;
F_23 ( V_2 -> V_10 ) ;
}
static bool F_74 ( struct V_101 * V_12 ,
enum V_54 * V_54 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_113 V_114 ;
T_2 V_115 ;
bool V_68 ;
V_114 = F_75 ( V_12 ) ;
if ( ! F_76 ( V_6 , V_114 ) )
return false ;
V_68 = false ;
V_115 = F_7 ( V_2 -> V_10 ) ;
if ( ! ( V_115 & V_9 ) )
goto V_116;
if ( F_70 ( V_6 ) )
* V_54 = F_77 ( V_115 ) ;
else if ( F_58 ( V_6 ) )
* V_54 = F_78 ( V_115 ) ;
else
* V_54 = F_79 ( V_115 ) ;
V_68 = true ;
V_116:
F_80 ( V_6 , V_114 ) ;
return V_68 ;
}
static void F_81 ( struct V_101 * V_12 ,
struct V_35 * V_48 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_115 , V_92 = 0 ;
int V_117 ;
V_115 = F_7 ( V_2 -> V_10 ) ;
if ( V_115 & V_108 )
V_92 |= V_107 ;
else
V_92 |= V_118 ;
if ( V_115 & V_106 )
V_92 |= V_105 ;
else
V_92 |= V_119 ;
if ( V_115 & V_112 )
V_48 -> V_111 = true ;
if ( V_2 -> V_120 ( & V_12 -> V_3 , V_48 ) )
V_48 -> V_121 = true ;
if ( V_115 & V_122 )
V_48 -> V_123 = true ;
if ( ! F_60 ( V_6 ) &&
V_115 & V_104 )
V_48 -> V_70 = true ;
V_48 -> V_3 . V_67 . V_92 |= V_92 ;
if ( ( V_115 & V_124 ) == V_109 )
V_117 = V_48 -> V_125 * 2 / 3 ;
else
V_117 = V_48 -> V_125 ;
if ( V_48 -> V_126 )
V_117 /= V_48 -> V_126 ;
V_48 -> V_3 . V_67 . V_127 = V_117 ;
V_48 -> V_128 = 4 ;
}
static void F_82 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
F_83 ( ! V_48 -> V_111 ) ;
F_84 ( L_13 ,
F_85 ( V_52 -> V_54 ) ) ;
F_86 ( V_12 , V_48 , V_80 ) ;
}
static void F_87 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_129 ;
V_129 = F_7 ( V_2 -> V_10 ) ;
V_129 |= V_9 ;
if ( V_48 -> V_123 )
V_129 |= V_122 ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_123 )
F_82 ( V_12 , V_48 , V_80 ) ;
}
static void F_88 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_129 ;
V_129 = F_7 ( V_2 -> V_10 ) ;
V_129 |= V_9 ;
if ( V_48 -> V_123 )
V_129 |= V_122 ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_83 > 24 &&
V_48 -> V_126 > 1 ) {
F_21 ( V_2 -> V_10 , V_129 & ~ V_9 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
}
if ( V_48 -> V_123 )
F_82 ( V_12 , V_48 , V_80 ) ;
}
static void F_89 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_129 ;
V_129 = F_7 ( V_2 -> V_10 ) ;
V_129 |= V_9 ;
if ( V_48 -> V_123 )
V_129 |= V_122 ;
if ( V_48 -> V_83 > 24 ) {
F_21 ( F_90 ( V_54 ) ,
F_7 ( F_90 ( V_54 ) ) |
V_130 ) ;
V_129 &= ~ V_124 ;
V_129 |= V_110 ;
}
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_83 > 24 ) {
V_129 &= ~ V_124 ;
V_129 |= V_109 ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( F_90 ( V_54 ) ,
F_7 ( F_90 ( V_54 ) ) &
~ V_130 ) ;
}
if ( V_48 -> V_123 )
F_82 ( V_12 , V_48 , V_80 ) ;
}
static void F_91 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
}
static void F_92 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_131 -> V_3 . V_52 ) ;
T_2 V_129 ;
V_129 = F_7 ( V_2 -> V_10 ) ;
V_129 &= ~ ( V_9 | V_122 ) ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( F_93 ( V_6 ) && V_52 -> V_54 == V_133 ) {
F_94 ( V_6 , V_134 , false ) ;
F_95 ( V_6 , V_134 , false ) ;
V_129 &= ~ V_135 ;
V_129 |= V_9 ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
V_129 &= ~ V_9 ;
F_21 ( V_2 -> V_10 , V_129 ) ;
F_23 ( V_2 -> V_10 ) ;
F_96 ( V_6 , V_134 ) ;
F_94 ( V_6 , V_134 , true ) ;
F_95 ( V_6 , V_134 , true ) ;
}
V_2 -> V_136 ( & V_12 -> V_3 , false , V_131 , V_132 ) ;
F_66 ( V_2 , false ) ;
}
static void F_97 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
if ( V_131 -> V_123 )
F_98 ( V_12 ) ;
F_92 ( V_12 , V_131 , V_132 ) ;
}
static void F_99 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
if ( V_131 -> V_123 )
F_98 ( V_12 ) ;
}
static void F_100 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
F_92 ( V_12 , V_131 , V_132 ) ;
}
static int F_101 ( struct V_5 * V_6 )
{
if ( F_102 ( V_6 ) )
return 165000 ;
else if ( F_103 ( V_6 ) || F_104 ( V_6 ) -> V_137 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_105 ( struct V_2 * V_15 ,
bool V_138 )
{
struct V_1 * V_4 = F_1 ( V_15 ) ;
int V_139 = F_101 ( F_4 ( V_4 ) ) ;
if ( V_138 ) {
struct V_140 * V_17 = V_15 -> V_141 ;
const struct V_142 * V_143 = & V_17 -> V_3 . V_81 ;
if ( V_15 -> V_99 . V_139 )
V_139 = F_106 ( V_139 ,
V_15 -> V_99 . V_139 ) ;
if ( V_143 -> V_139 )
V_139 = F_106 ( V_139 ,
V_143 -> V_139 ) ;
else if ( ! V_15 -> V_111 )
V_139 = F_106 ( V_139 , 165000 ) ;
}
return V_139 ;
}
static enum V_144
F_107 ( struct V_2 * V_15 ,
int clock , bool V_138 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
if ( clock < 25000 )
return V_145 ;
if ( clock > F_105 ( V_15 , V_138 ) )
return V_146 ;
if ( F_108 ( V_6 ) && clock > 223333 && clock < 240000 )
return V_147 ;
if ( F_58 ( V_6 ) && clock > 216000 && clock < 240000 )
return V_147 ;
return V_148 ;
}
static enum V_144
F_109 ( struct V_16 * V_17 ,
struct V_66 * V_84 )
{
struct V_2 * V_15 = F_10 ( V_17 ) ;
struct V_1 * V_4 = F_1 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_144 V_149 ;
int clock ;
int V_150 = F_4 ( V_17 -> V_4 ) -> V_151 ;
if ( V_84 -> V_92 & V_152 )
return V_153 ;
clock = V_84 -> clock ;
if ( ( V_84 -> V_92 & V_154 ) == V_155 )
clock *= 2 ;
if ( clock > V_150 )
return V_146 ;
if ( V_84 -> V_92 & V_156 )
clock *= 2 ;
V_149 = F_107 ( V_15 , clock , true ) ;
if ( ! F_110 ( V_6 ) && V_149 != V_148 )
V_149 = F_107 ( V_15 , clock * 3 / 2 , true ) ;
return V_149 ;
}
static bool F_111 ( struct V_35 * V_36 )
{
struct V_5 * V_6 =
F_4 ( V_36 -> V_3 . V_52 -> V_4 ) ;
struct V_157 * V_158 = V_36 -> V_3 . V_158 ;
struct V_79 * V_159 ;
struct V_16 * V_17 ;
int V_33 ;
if ( F_110 ( V_6 ) )
return false ;
if ( V_36 -> V_160 != 1 << V_161 )
return false ;
F_112 (state, connector, connector_state, i) {
const struct V_142 * V_143 = & V_17 -> V_81 ;
if ( V_159 -> V_52 != V_36 -> V_3 . V_52 )
continue;
if ( ( V_143 -> V_162 & V_163 ) == 0 )
return false ;
}
return true ;
}
bool F_113 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_5 * V_6 = F_4 ( V_12 -> V_3 . V_4 ) ;
struct V_66 * V_67 = & V_48 -> V_3 . V_67 ;
int V_164 = V_48 -> V_3 . V_67 . V_127 ;
int V_165 = V_164 * 3 / 2 ;
int V_166 ;
V_48 -> V_111 = V_2 -> V_111 ;
if ( V_48 -> V_111 )
V_48 -> V_121 = true ;
if ( V_2 -> V_167 ) {
V_48 -> V_70 =
V_48 -> V_111 &&
F_114 ( V_67 ) ==
V_71 ;
} else {
V_48 -> V_70 =
V_2 -> V_70 ;
}
if ( V_67 -> V_92 & V_156 ) {
V_48 -> V_126 = 2 ;
V_164 *= 2 ;
V_165 *= 2 ;
}
if ( F_60 ( V_6 ) && ! F_5 ( V_6 ) )
V_48 -> V_168 = true ;
if ( V_48 -> V_111 && V_2 -> V_123 )
V_48 -> V_123 = true ;
if ( V_48 -> V_83 > 8 * 3 && V_48 -> V_111 &&
F_107 ( V_2 , V_165 , true ) == V_148 &&
F_111 ( V_48 ) ) {
F_52 ( L_14 ) ;
V_166 = 12 * 3 ;
V_48 -> V_125 = V_165 ;
} else {
F_52 ( L_15 ) ;
V_166 = 8 * 3 ;
V_48 -> V_125 = V_164 ;
}
if ( ! V_48 -> V_169 ) {
F_52 ( L_16 , V_166 ) ;
V_48 -> V_83 = V_166 ;
}
if ( F_107 ( V_2 , V_48 -> V_125 ,
false ) != V_148 ) {
F_52 ( L_17 ) ;
return false ;
}
V_67 -> V_170 = V_2 -> V_171 ;
V_48 -> V_128 = 4 ;
return true ;
}
static void
F_115 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
V_2 -> V_111 = false ;
V_2 -> V_123 = false ;
V_2 -> V_73 = false ;
V_2 -> V_99 . type = V_172 ;
V_2 -> V_99 . V_139 = 0 ;
F_116 ( F_117 ( V_17 ) -> V_173 ) ;
F_117 ( V_17 ) -> V_173 = NULL ;
}
static void
F_118 ( struct V_16 * V_17 , bool V_174 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_15 = F_10 ( V_17 ) ;
enum V_50 V_50 = F_2 ( V_15 ) -> V_50 ;
struct V_96 * V_97 =
F_67 ( V_6 , V_15 -> V_98 ) ;
enum V_175 type = F_119 ( V_97 ) ;
if ( type == V_176 ) {
if ( V_174 &&
F_120 ( V_6 , V_50 ) ) {
F_52 ( L_18 ) ;
type = V_177 ;
} else {
type = V_172 ;
}
}
if ( type == V_172 )
return;
V_15 -> V_99 . type = type ;
V_15 -> V_99 . V_139 =
F_121 ( type , V_97 ) ;
F_52 ( L_19 ,
F_122 ( type ) ,
V_15 -> V_99 . V_139 ) ;
}
static bool
F_123 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_178 * V_178 ;
bool V_179 = false ;
F_124 ( V_6 , V_180 ) ;
V_178 = F_125 ( V_17 ,
F_67 ( V_6 ,
V_2 -> V_98 ) ) ;
F_118 ( V_17 , V_178 != NULL ) ;
F_80 ( V_6 , V_180 ) ;
F_117 ( V_17 ) -> V_173 = V_178 ;
if ( V_178 && V_178 -> V_181 & V_182 ) {
V_2 -> V_73 =
F_126 ( V_178 ) ;
V_2 -> V_123 = F_127 ( V_178 ) ;
if ( V_2 -> V_183 != V_184 )
V_2 -> V_123 =
V_2 -> V_183 == V_185 ;
if ( V_2 -> V_183 != V_186 )
V_2 -> V_111 =
F_128 ( V_178 ) ;
V_179 = true ;
}
return V_179 ;
}
static enum V_187
F_129 ( struct V_16 * V_17 , bool V_188 )
{
enum V_187 V_149 ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
F_52 ( L_20 ,
V_17 -> V_3 . V_189 , V_17 -> V_190 ) ;
F_124 ( V_6 , V_180 ) ;
F_115 ( V_17 ) ;
if ( F_123 ( V_17 ) ) {
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_161 ;
V_149 = V_191 ;
} else
V_149 = V_192 ;
F_80 ( V_6 , V_180 ) ;
return V_149 ;
}
static void
F_130 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_52 ( L_20 ,
V_17 -> V_3 . V_189 , V_17 -> V_190 ) ;
F_115 ( V_17 ) ;
if ( V_17 -> V_149 != V_191 )
return;
F_123 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_161 ;
}
static int F_131 ( struct V_16 * V_17 )
{
struct V_178 * V_178 ;
V_178 = F_117 ( V_17 ) -> V_173 ;
if ( V_178 == NULL )
return 0 ;
return F_132 ( V_17 , V_178 ) ;
}
static bool
F_133 ( struct V_16 * V_17 )
{
bool V_123 = false ;
struct V_178 * V_178 ;
V_178 = F_117 ( V_17 ) -> V_173 ;
if ( V_178 && V_178 -> V_181 & V_182 )
V_123 = F_127 ( V_178 ) ;
return V_123 ;
}
static int
F_134 ( struct V_16 * V_17 ,
struct V_193 * V_194 ,
T_6 V_40 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_13 * V_14 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
int V_68 ;
V_68 = F_135 ( & V_17 -> V_3 , V_194 , V_40 ) ;
if ( V_68 )
return V_68 ;
if ( V_194 == V_6 -> V_195 ) {
enum V_196 V_33 = V_40 ;
bool V_123 ;
if ( V_33 == V_2 -> V_183 )
return 0 ;
V_2 -> V_183 = V_33 ;
if ( V_33 == V_184 )
V_123 = F_133 ( V_17 ) ;
else
V_123 = ( V_33 == V_185 ) ;
if ( V_33 == V_186 )
V_2 -> V_111 = 0 ;
V_2 -> V_123 = V_123 ;
goto V_197;
}
if ( V_194 == V_6 -> V_198 ) {
bool V_199 = V_2 -> V_167 ;
bool V_200 = V_2 -> V_70 ;
switch ( V_40 ) {
case V_201 :
V_2 -> V_167 = true ;
break;
case V_202 :
V_2 -> V_167 = false ;
V_2 -> V_70 = false ;
break;
case V_203 :
V_2 -> V_167 = false ;
V_2 -> V_70 = true ;
break;
default:
return - V_204 ;
}
if ( V_199 == V_2 -> V_167 &&
V_200 == V_2 -> V_70 )
return 0 ;
goto V_197;
}
if ( V_194 == V_17 -> V_4 -> V_205 . V_206 ) {
switch ( V_40 ) {
case V_207 :
V_2 -> V_171 = V_208 ;
break;
case V_209 :
V_2 -> V_171 = V_210 ;
break;
case V_211 :
V_2 -> V_171 = V_212 ;
break;
default:
return - V_204 ;
}
goto V_197;
}
return - V_204 ;
V_197:
if ( V_14 -> V_3 . V_3 . V_52 )
F_136 ( V_14 -> V_3 . V_3 . V_52 ) ;
return 0 ;
}
static void F_137 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
F_69 ( V_12 , V_48 ) ;
V_2 -> V_136 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
}
static void F_138 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_13 * V_213 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_213 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_139 ( V_12 ) ;
F_140 ( V_12 , 0x2b245f5f , 0x00002000 , 0x5578b83a ,
0x2b247878 ) ;
V_2 -> V_136 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
F_87 ( V_12 , V_48 , V_80 ) ;
F_141 ( V_6 , V_213 , 0x0 ) ;
}
static void F_142 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
F_69 ( V_12 , V_48 ) ;
F_143 ( V_12 ) ;
}
static void F_144 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
F_69 ( V_12 , V_48 ) ;
F_145 ( V_12 ) ;
}
static void F_146 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
F_147 ( V_12 ) ;
}
static void F_148 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
F_149 ( V_12 ) ;
}
static void F_150 ( struct V_101 * V_12 ,
struct V_35 * V_131 ,
struct V_79 * V_132 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_151 ( & V_6 -> V_214 ) ;
F_152 ( V_12 , true ) ;
F_153 ( & V_6 -> V_214 ) ;
}
static void F_154 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_13 * V_213 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_213 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_155 ( V_12 ) ;
F_156 ( V_12 , 128 , 102 , false ) ;
V_2 -> V_136 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
F_87 ( V_12 , V_48 , V_80 ) ;
F_141 ( V_6 , V_213 , 0x0 ) ;
F_157 ( V_12 ) ;
}
static void F_158 ( struct V_16 * V_17 )
{
F_116 ( F_117 ( V_17 ) -> V_173 ) ;
F_159 ( V_17 ) ;
F_116 ( V_17 ) ;
}
static void
F_160 ( struct V_2 * V_2 , struct V_16 * V_17 )
{
F_161 ( V_17 ) ;
F_162 ( V_17 ) ;
V_2 -> V_167 = true ;
F_163 ( V_17 ) ;
V_2 -> V_171 = V_208 ;
}
static T_7 F_164 ( struct V_5 * V_6 ,
enum V_50 V_50 )
{
const struct V_215 * V_143 =
& V_6 -> V_216 . V_217 [ V_50 ] ;
T_7 V_218 ;
if ( V_143 -> V_219 ) {
F_52 ( L_21 ,
V_143 -> V_219 , F_165 ( V_50 ) ) ;
return V_143 -> V_219 ;
}
switch ( V_50 ) {
case V_220 :
if ( F_108 ( V_6 ) )
V_218 = V_221 ;
else
V_218 = V_222 ;
break;
case V_223 :
if ( F_108 ( V_6 ) )
V_218 = V_224 ;
else
V_218 = V_225 ;
break;
case V_226 :
if ( F_58 ( V_6 ) )
V_218 = V_227 ;
else
V_218 = V_228 ;
break;
default:
F_13 ( V_50 ) ;
V_218 = V_222 ;
break;
}
F_52 ( L_22 ,
V_218 , F_165 ( V_50 ) ) ;
return V_218 ;
}
void F_166 ( struct V_13 * V_14 ,
struct V_140 * V_140 )
{
struct V_16 * V_17 = & V_140 -> V_3 ;
struct V_2 * V_2 = & V_14 -> V_15 ;
struct V_101 * V_101 = & V_14 -> V_3 ;
struct V_1 * V_4 = V_101 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_50 V_50 = V_14 -> V_50 ;
F_52 ( L_23 ,
F_165 ( V_50 ) ) ;
if ( F_6 ( V_14 -> V_229 < 4 ,
L_24 ,
V_14 -> V_229 , F_165 ( V_50 ) ) )
return;
F_167 ( V_4 , V_17 , & V_230 ,
V_231 ) ;
F_168 ( V_17 , & V_232 ) ;
V_17 -> V_233 = 1 ;
V_17 -> V_234 = 0 ;
V_17 -> V_235 = 1 ;
V_2 -> V_98 = F_164 ( V_6 , V_50 ) ;
switch ( V_50 ) {
case V_220 :
if ( F_169 ( V_6 , 0 , V_236 ) )
V_101 -> V_237 = V_238 ;
else
V_101 -> V_237 = V_239 ;
break;
case V_223 :
V_101 -> V_237 = V_240 ;
break;
case V_226 :
V_101 -> V_237 = V_241 ;
break;
case V_242 :
V_101 -> V_237 = V_243 ;
break;
default:
F_13 ( V_50 ) ;
return;
}
if ( F_57 ( V_6 ) || F_58 ( V_6 ) ) {
V_2 -> V_64 = F_34 ;
V_2 -> V_136 = F_64 ;
V_2 -> V_120 = F_37 ;
} else if ( F_102 ( V_6 ) ) {
V_2 -> V_64 = F_20 ;
V_2 -> V_136 = F_51 ;
V_2 -> V_120 = F_24 ;
} else if ( F_5 ( V_6 ) ) {
V_2 -> V_64 = F_38 ;
V_2 -> V_136 = F_65 ;
V_2 -> V_120 = F_40 ;
} else if ( F_93 ( V_6 ) ) {
V_2 -> V_64 = F_27 ;
V_2 -> V_136 = F_62 ;
V_2 -> V_120 = F_31 ;
} else {
V_2 -> V_64 = F_32 ;
V_2 -> V_136 = F_63 ;
V_2 -> V_120 = F_33 ;
}
if ( F_5 ( V_6 ) )
V_140 -> V_244 = V_245 ;
else
V_140 -> V_244 = V_246 ;
F_160 ( V_2 , V_17 ) ;
F_170 ( V_140 , V_101 ) ;
V_2 -> V_141 = V_140 ;
if ( F_102 ( V_6 ) && ! F_171 ( V_6 ) ) {
T_2 V_129 = F_7 ( V_247 ) ;
F_21 ( V_247 , ( V_129 & ~ 0xf ) | 0xd ) ;
}
}
void F_172 ( struct V_5 * V_6 ,
T_3 V_10 , enum V_50 V_50 )
{
struct V_13 * V_14 ;
struct V_101 * V_101 ;
struct V_140 * V_140 ;
V_14 = F_173 ( sizeof( * V_14 ) , V_248 ) ;
if ( ! V_14 )
return;
V_140 = F_174 () ;
if ( ! V_140 ) {
F_116 ( V_14 ) ;
return;
}
V_101 = & V_14 -> V_3 ;
F_175 ( & V_6 -> V_249 , & V_101 -> V_3 ,
& V_250 , V_251 ,
L_25 , F_165 ( V_50 ) ) ;
V_101 -> V_252 = F_113 ;
if ( F_60 ( V_6 ) ) {
V_101 -> V_253 = F_99 ;
V_101 -> V_254 = F_100 ;
} else {
V_101 -> V_253 = F_97 ;
}
V_101 -> V_244 = F_74 ;
V_101 -> V_255 = F_81 ;
if ( F_58 ( V_6 ) ) {
V_101 -> V_256 = F_144 ;
V_101 -> V_257 = F_154 ;
V_101 -> V_78 = F_91 ;
V_101 -> V_254 = F_150 ;
V_101 -> V_258 = F_146 ;
} else if ( F_57 ( V_6 ) ) {
V_101 -> V_256 = F_142 ;
V_101 -> V_257 = F_138 ;
V_101 -> V_78 = F_91 ;
V_101 -> V_254 = F_148 ;
} else {
V_101 -> V_257 = F_137 ;
if ( F_70 ( V_6 ) )
V_101 -> V_78 = F_89 ;
else if ( F_93 ( V_6 ) )
V_101 -> V_78 = F_88 ;
else
V_101 -> V_78 = F_87 ;
}
V_101 -> type = V_161 ;
V_101 -> V_50 = V_50 ;
if ( F_58 ( V_6 ) ) {
if ( V_50 == V_226 )
V_101 -> V_259 = 1 << 2 ;
else
V_101 -> V_259 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_101 -> V_259 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_101 -> V_260 = 1 << V_261 ;
if ( F_102 ( V_6 ) )
V_101 -> V_260 |= 1 << V_161 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_15 . V_10 = V_10 ;
V_14 -> V_262 . V_263 = V_34 ;
V_14 -> V_229 = 4 ;
F_166 ( V_14 , V_140 ) ;
}
