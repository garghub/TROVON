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
T_2 V_113 ;
bool V_68 ;
if ( ! F_75 ( V_6 ,
V_12 -> V_114 ) )
return false ;
V_68 = false ;
V_113 = F_7 ( V_2 -> V_10 ) ;
if ( ! ( V_113 & V_9 ) )
goto V_115;
if ( F_70 ( V_6 ) )
* V_54 = F_76 ( V_113 ) ;
else if ( F_58 ( V_6 ) )
* V_54 = F_77 ( V_113 ) ;
else
* V_54 = F_78 ( V_113 ) ;
V_68 = true ;
V_115:
F_79 ( V_6 , V_12 -> V_114 ) ;
return V_68 ;
}
static void F_80 ( struct V_101 * V_12 ,
struct V_35 * V_48 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_113 , V_92 = 0 ;
int V_116 ;
V_113 = F_7 ( V_2 -> V_10 ) ;
if ( V_113 & V_108 )
V_92 |= V_107 ;
else
V_92 |= V_117 ;
if ( V_113 & V_106 )
V_92 |= V_105 ;
else
V_92 |= V_118 ;
if ( V_113 & V_112 )
V_48 -> V_111 = true ;
if ( V_2 -> V_119 ( & V_12 -> V_3 , V_48 ) )
V_48 -> V_120 = true ;
if ( V_113 & V_121 )
V_48 -> V_122 = true ;
if ( ! F_60 ( V_6 ) &&
V_113 & V_104 )
V_48 -> V_70 = true ;
V_48 -> V_3 . V_67 . V_92 |= V_92 ;
if ( ( V_113 & V_123 ) == V_109 )
V_116 = V_48 -> V_124 * 2 / 3 ;
else
V_116 = V_48 -> V_124 ;
if ( V_48 -> V_125 )
V_116 /= V_48 -> V_125 ;
V_48 -> V_3 . V_67 . V_126 = V_116 ;
V_48 -> V_127 = 4 ;
}
static void F_81 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
F_82 ( ! V_48 -> V_111 ) ;
F_83 ( L_13 ,
F_84 ( V_52 -> V_54 ) ) ;
F_85 ( V_12 , V_48 , V_80 ) ;
}
static void F_86 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_128 ;
V_128 = F_7 ( V_2 -> V_10 ) ;
V_128 |= V_9 ;
if ( V_48 -> V_122 )
V_128 |= V_121 ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_122 )
F_81 ( V_12 , V_48 , V_80 ) ;
}
static void F_87 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_128 ;
V_128 = F_7 ( V_2 -> V_10 ) ;
V_128 |= V_9 ;
if ( V_48 -> V_122 )
V_128 |= V_121 ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_83 > 24 &&
V_48 -> V_125 > 1 ) {
F_21 ( V_2 -> V_10 , V_128 & ~ V_9 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
}
if ( V_48 -> V_122 )
F_81 ( V_12 , V_48 , V_80 ) ;
}
static void F_88 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_51 * V_52 = F_28 ( V_48 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_128 ;
V_128 = F_7 ( V_2 -> V_10 ) ;
V_128 |= V_9 ;
if ( V_48 -> V_122 )
V_128 |= V_121 ;
if ( V_48 -> V_83 > 24 ) {
F_21 ( F_89 ( V_54 ) ,
F_7 ( F_89 ( V_54 ) ) |
V_129 ) ;
V_128 &= ~ V_123 ;
V_128 |= V_110 ;
}
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_48 -> V_83 > 24 ) {
V_128 &= ~ V_123 ;
V_128 |= V_109 ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( F_89 ( V_54 ) ,
F_7 ( F_89 ( V_54 ) ) &
~ V_129 ) ;
}
if ( V_48 -> V_122 )
F_81 ( V_12 , V_48 , V_80 ) ;
}
static void F_90 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
}
static void F_91 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_130 -> V_3 . V_52 ) ;
T_2 V_128 ;
V_128 = F_7 ( V_2 -> V_10 ) ;
V_128 &= ~ ( V_9 | V_121 ) ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( F_92 ( V_6 ) && V_52 -> V_54 == V_132 ) {
F_93 ( V_6 , V_133 , false ) ;
F_94 ( V_6 , V_133 , false ) ;
V_128 &= ~ V_134 ;
V_128 |= V_9 ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
V_128 &= ~ V_9 ;
F_21 ( V_2 -> V_10 , V_128 ) ;
F_23 ( V_2 -> V_10 ) ;
F_95 ( V_6 , V_133 ) ;
F_93 ( V_6 , V_133 , true ) ;
F_94 ( V_6 , V_133 , true ) ;
}
V_2 -> V_135 ( & V_12 -> V_3 , false , V_130 , V_131 ) ;
F_66 ( V_2 , false ) ;
}
static void F_96 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
if ( V_130 -> V_122 )
F_97 ( V_12 ) ;
F_91 ( V_12 , V_130 , V_131 ) ;
}
static void F_98 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
if ( V_130 -> V_122 )
F_97 ( V_12 ) ;
}
static void F_99 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
F_91 ( V_12 , V_130 , V_131 ) ;
}
static int F_100 ( struct V_5 * V_6 )
{
if ( F_101 ( V_6 ) )
return 165000 ;
else if ( F_102 ( V_6 ) )
return 594000 ;
else if ( F_103 ( V_6 ) || F_104 ( V_6 ) -> V_136 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_105 ( struct V_2 * V_15 ,
bool V_137 )
{
struct V_1 * V_4 = F_1 ( V_15 ) ;
int V_138 = F_100 ( F_4 ( V_4 ) ) ;
if ( V_137 ) {
struct V_139 * V_17 = V_15 -> V_140 ;
const struct V_141 * V_142 = & V_17 -> V_3 . V_81 ;
if ( V_15 -> V_99 . V_138 )
V_138 = F_106 ( V_138 ,
V_15 -> V_99 . V_138 ) ;
if ( V_142 -> V_138 )
V_138 = F_106 ( V_138 ,
V_142 -> V_138 ) ;
else if ( ! V_15 -> V_111 )
V_138 = F_106 ( V_138 , 165000 ) ;
}
return V_138 ;
}
static enum V_143
F_107 ( struct V_2 * V_15 ,
int clock , bool V_137 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
if ( clock < 25000 )
return V_144 ;
if ( clock > F_105 ( V_15 , V_137 ) )
return V_145 ;
if ( F_108 ( V_6 ) && clock > 223333 && clock < 240000 )
return V_146 ;
if ( F_58 ( V_6 ) && clock > 216000 && clock < 240000 )
return V_146 ;
return V_147 ;
}
static enum V_143
F_109 ( struct V_16 * V_17 ,
struct V_66 * V_84 )
{
struct V_2 * V_15 = F_10 ( V_17 ) ;
struct V_1 * V_4 = F_1 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_143 V_148 ;
int clock ;
int V_149 = F_4 ( V_17 -> V_4 ) -> V_150 ;
if ( V_84 -> V_92 & V_151 )
return V_152 ;
clock = V_84 -> clock ;
if ( ( V_84 -> V_92 & V_153 ) == V_154 )
clock *= 2 ;
if ( clock > V_149 )
return V_145 ;
if ( V_84 -> V_92 & V_155 )
clock *= 2 ;
V_148 = F_107 ( V_15 , clock , true ) ;
if ( ! F_110 ( V_6 ) && V_148 != V_147 )
V_148 = F_107 ( V_15 , clock * 3 / 2 , true ) ;
return V_148 ;
}
static bool F_111 ( struct V_35 * V_36 )
{
struct V_5 * V_6 =
F_4 ( V_36 -> V_3 . V_52 -> V_4 ) ;
struct V_156 * V_157 = V_36 -> V_3 . V_157 ;
struct V_79 * V_158 ;
struct V_16 * V_17 ;
int V_33 ;
if ( F_110 ( V_6 ) )
return false ;
if ( V_36 -> V_159 != 1 << V_160 )
return false ;
F_112 (state, connector, connector_state, i) {
const struct V_141 * V_142 = & V_17 -> V_81 ;
if ( V_158 -> V_52 != V_36 -> V_3 . V_52 )
continue;
if ( ( V_142 -> V_161 & V_162 ) == 0 )
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
struct V_163 * V_164 = & V_80 -> V_17 -> V_81 . V_15 . V_164 ;
int V_165 = V_48 -> V_3 . V_67 . V_126 ;
int V_166 = V_165 * 3 / 2 ;
int V_167 ;
V_48 -> V_111 = V_2 -> V_111 ;
if ( V_48 -> V_111 )
V_48 -> V_120 = true ;
if ( V_2 -> V_168 ) {
V_48 -> V_70 =
V_48 -> V_111 &&
F_114 ( V_67 ) ==
V_71 ;
} else {
V_48 -> V_70 =
V_2 -> V_70 ;
}
if ( V_67 -> V_92 & V_155 ) {
V_48 -> V_125 = 2 ;
V_165 *= 2 ;
V_166 *= 2 ;
}
if ( F_60 ( V_6 ) && ! F_5 ( V_6 ) )
V_48 -> V_169 = true ;
if ( V_48 -> V_111 && V_2 -> V_122 )
V_48 -> V_122 = true ;
if ( V_48 -> V_83 > 8 * 3 && V_48 -> V_111 &&
F_107 ( V_2 , V_166 , true ) == V_147 &&
F_111 ( V_48 ) ) {
F_52 ( L_14 ) ;
V_167 = 12 * 3 ;
V_48 -> V_124 = V_166 ;
} else {
F_52 ( L_15 ) ;
V_167 = 8 * 3 ;
V_48 -> V_124 = V_165 ;
}
if ( ! V_48 -> V_170 ) {
F_52 ( L_16 , V_167 ) ;
V_48 -> V_83 = V_167 ;
}
if ( F_107 ( V_2 , V_48 -> V_124 ,
false ) != V_147 ) {
F_52 ( L_17 ) ;
return false ;
}
V_67 -> V_171 = V_2 -> V_172 ;
V_48 -> V_127 = 4 ;
if ( V_164 -> V_173 . V_174 && F_102 ( V_6 ) ) {
if ( V_164 -> V_173 . V_175 )
V_48 -> V_176 = true ;
if ( V_48 -> V_124 > 340000 ) {
V_48 -> V_176 = true ;
V_48 -> V_177 = true ;
}
}
return true ;
}
static void
F_115 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
V_2 -> V_111 = false ;
V_2 -> V_122 = false ;
V_2 -> V_73 = false ;
V_2 -> V_99 . type = V_178 ;
V_2 -> V_99 . V_138 = 0 ;
F_116 ( F_117 ( V_17 ) -> V_179 ) ;
F_117 ( V_17 ) -> V_179 = NULL ;
}
static void
F_118 ( struct V_16 * V_17 , bool V_180 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_15 = F_10 ( V_17 ) ;
enum V_50 V_50 = F_2 ( V_15 ) -> V_50 ;
struct V_96 * V_97 =
F_67 ( V_6 , V_15 -> V_98 ) ;
enum V_181 type = F_119 ( V_97 ) ;
if ( type == V_182 ) {
if ( V_180 &&
F_120 ( V_6 , V_50 ) ) {
F_52 ( L_18 ) ;
type = V_183 ;
} else {
type = V_178 ;
}
}
if ( type == V_178 )
return;
V_15 -> V_99 . type = type ;
V_15 -> V_99 . V_138 =
F_121 ( type , V_97 ) ;
F_52 ( L_19 ,
F_122 ( type ) ,
V_15 -> V_99 . V_138 ) ;
}
static bool
F_123 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_184 * V_184 ;
bool V_185 = false ;
F_124 ( V_6 , V_186 ) ;
V_184 = F_125 ( V_17 ,
F_67 ( V_6 ,
V_2 -> V_98 ) ) ;
F_118 ( V_17 , V_184 != NULL ) ;
F_79 ( V_6 , V_186 ) ;
F_117 ( V_17 ) -> V_179 = V_184 ;
if ( V_184 && V_184 -> V_187 & V_188 ) {
V_2 -> V_73 =
F_126 ( V_184 ) ;
V_2 -> V_122 = F_127 ( V_184 ) ;
if ( V_2 -> V_189 != V_190 )
V_2 -> V_122 =
V_2 -> V_189 == V_191 ;
if ( V_2 -> V_189 != V_192 )
V_2 -> V_111 =
F_128 ( V_184 ) ;
V_185 = true ;
}
return V_185 ;
}
static enum V_193
F_129 ( struct V_16 * V_17 , bool V_194 )
{
enum V_193 V_148 ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
F_52 ( L_20 ,
V_17 -> V_3 . V_195 , V_17 -> V_196 ) ;
F_124 ( V_6 , V_186 ) ;
F_115 ( V_17 ) ;
if ( F_123 ( V_17 ) ) {
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_160 ;
V_148 = V_197 ;
} else
V_148 = V_198 ;
F_79 ( V_6 , V_186 ) ;
return V_148 ;
}
static void
F_130 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_52 ( L_20 ,
V_17 -> V_3 . V_195 , V_17 -> V_196 ) ;
F_115 ( V_17 ) ;
if ( V_17 -> V_148 != V_197 )
return;
F_123 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_160 ;
}
static int F_131 ( struct V_16 * V_17 )
{
struct V_184 * V_184 ;
V_184 = F_117 ( V_17 ) -> V_179 ;
if ( V_184 == NULL )
return 0 ;
return F_132 ( V_17 , V_184 ) ;
}
static bool
F_133 ( struct V_16 * V_17 )
{
bool V_122 = false ;
struct V_184 * V_184 ;
V_184 = F_117 ( V_17 ) -> V_179 ;
if ( V_184 && V_184 -> V_187 & V_188 )
V_122 = F_127 ( V_184 ) ;
return V_122 ;
}
static int
F_134 ( struct V_16 * V_17 ,
struct V_199 * V_200 ,
T_6 V_40 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_13 * V_14 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
int V_68 ;
V_68 = F_135 ( & V_17 -> V_3 , V_200 , V_40 ) ;
if ( V_68 )
return V_68 ;
if ( V_200 == V_6 -> V_201 ) {
enum V_202 V_33 = V_40 ;
bool V_122 ;
if ( V_33 == V_2 -> V_189 )
return 0 ;
V_2 -> V_189 = V_33 ;
if ( V_33 == V_190 )
V_122 = F_133 ( V_17 ) ;
else
V_122 = ( V_33 == V_191 ) ;
if ( V_33 == V_192 )
V_2 -> V_111 = 0 ;
V_2 -> V_122 = V_122 ;
goto V_203;
}
if ( V_200 == V_6 -> V_204 ) {
bool V_205 = V_2 -> V_168 ;
bool V_206 = V_2 -> V_70 ;
switch ( V_40 ) {
case V_207 :
V_2 -> V_168 = true ;
break;
case V_208 :
V_2 -> V_168 = false ;
V_2 -> V_70 = false ;
break;
case V_209 :
V_2 -> V_168 = false ;
V_2 -> V_70 = true ;
break;
default:
return - V_210 ;
}
if ( V_205 == V_2 -> V_168 &&
V_206 == V_2 -> V_70 )
return 0 ;
goto V_203;
}
if ( V_200 == V_17 -> V_4 -> V_211 . V_212 ) {
switch ( V_40 ) {
case V_213 :
V_2 -> V_172 = V_214 ;
break;
case V_215 :
V_2 -> V_172 = V_216 ;
break;
case V_217 :
V_2 -> V_172 = V_218 ;
break;
default:
return - V_210 ;
}
goto V_203;
}
return - V_210 ;
V_203:
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
V_2 -> V_135 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
}
static void F_138 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_13 * V_219 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_219 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_139 ( V_12 ) ;
F_140 ( V_12 , 0x2b245f5f , 0x00002000 , 0x5578b83a ,
0x2b247878 ) ;
V_2 -> V_135 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
F_86 ( V_12 , V_48 , V_80 ) ;
F_141 ( V_6 , V_219 , 0x0 ) ;
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
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
F_147 ( V_12 ) ;
}
static void F_148 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
F_149 ( V_12 ) ;
}
static void F_150 ( struct V_101 * V_12 ,
struct V_35 * V_130 ,
struct V_79 * V_131 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_151 ( & V_6 -> V_220 ) ;
F_152 ( V_12 , true ) ;
F_153 ( & V_6 -> V_220 ) ;
}
static void F_154 ( struct V_101 * V_12 ,
struct V_35 * V_48 ,
struct V_79 * V_80 )
{
struct V_13 * V_219 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_219 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_155 ( V_12 ) ;
F_156 ( V_12 , 128 , 102 , false ) ;
V_2 -> V_135 ( & V_12 -> V_3 ,
V_48 -> V_111 ,
V_48 , V_80 ) ;
F_86 ( V_12 , V_48 , V_80 ) ;
F_141 ( V_6 , V_219 , 0x0 ) ;
F_157 ( V_12 ) ;
}
static void F_158 ( struct V_16 * V_17 )
{
F_116 ( F_117 ( V_17 ) -> V_179 ) ;
F_159 ( V_17 ) ;
F_116 ( V_17 ) ;
}
static void
F_160 ( struct V_2 * V_2 , struct V_16 * V_17 )
{
F_161 ( V_17 ) ;
F_162 ( V_17 ) ;
V_2 -> V_168 = true ;
F_163 ( V_17 ) ;
V_2 -> V_172 = V_214 ;
}
void F_164 ( struct V_101 * V_12 ,
struct V_16 * V_17 ,
bool V_221 ,
bool V_173 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_5 * V_6 = V_17 -> V_4 -> V_222 ;
struct V_223 * V_224 =
& V_17 -> V_81 . V_15 . V_164 . V_173 ;
struct V_96 * V_225 = F_67 ( V_6 ,
V_2 -> V_98 ) ;
bool V_68 ;
if ( ! V_224 -> V_174 )
return;
F_52 ( L_21 ,
V_12 -> V_3 . V_196 , V_17 -> V_196 ) ;
V_68 = F_165 ( V_225 , V_221 ) ;
if ( ! V_68 ) {
F_45 ( L_22 ) ;
return;
}
V_68 = F_166 ( V_225 , V_173 ) ;
if ( ! V_68 ) {
F_45 ( L_23 ) ;
return;
}
F_52 ( L_24 ) ;
}
static T_7 F_167 ( struct V_5 * V_6 ,
enum V_50 V_50 )
{
const struct V_226 * V_142 =
& V_6 -> V_227 . V_228 [ V_50 ] ;
T_7 V_229 ;
if ( V_142 -> V_230 ) {
F_52 ( L_25 ,
V_142 -> V_230 , F_168 ( V_50 ) ) ;
return V_142 -> V_230 ;
}
switch ( V_50 ) {
case V_231 :
if ( F_108 ( V_6 ) )
V_229 = V_232 ;
else
V_229 = V_233 ;
break;
case V_234 :
if ( F_108 ( V_6 ) )
V_229 = V_235 ;
else
V_229 = V_236 ;
break;
case V_237 :
if ( F_58 ( V_6 ) )
V_229 = V_238 ;
else
V_229 = V_239 ;
break;
default:
F_13 ( V_50 ) ;
V_229 = V_233 ;
break;
}
F_52 ( L_26 ,
V_229 , F_168 ( V_50 ) ) ;
return V_229 ;
}
void F_169 ( struct V_13 * V_14 ,
struct V_139 * V_139 )
{
struct V_16 * V_17 = & V_139 -> V_3 ;
struct V_2 * V_2 = & V_14 -> V_15 ;
struct V_101 * V_101 = & V_14 -> V_3 ;
struct V_1 * V_4 = V_101 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_50 V_50 = V_14 -> V_50 ;
F_52 ( L_27 ,
F_168 ( V_50 ) ) ;
if ( F_6 ( V_14 -> V_240 < 4 ,
L_28 ,
V_14 -> V_240 , F_168 ( V_50 ) ) )
return;
F_170 ( V_4 , V_17 , & V_241 ,
V_242 ) ;
F_171 ( V_17 , & V_243 ) ;
V_17 -> V_244 = 1 ;
V_17 -> V_245 = 0 ;
V_17 -> V_246 = 1 ;
V_2 -> V_98 = F_167 ( V_6 , V_50 ) ;
switch ( V_50 ) {
case V_231 :
V_101 -> V_247 = V_248 ;
break;
case V_234 :
V_101 -> V_247 = V_249 ;
break;
case V_237 :
V_101 -> V_247 = V_250 ;
break;
case V_251 :
V_101 -> V_247 = V_252 ;
break;
default:
F_13 ( V_50 ) ;
return;
}
if ( F_57 ( V_6 ) || F_58 ( V_6 ) ) {
V_2 -> V_64 = F_34 ;
V_2 -> V_135 = F_64 ;
V_2 -> V_119 = F_37 ;
} else if ( F_101 ( V_6 ) ) {
V_2 -> V_64 = F_20 ;
V_2 -> V_135 = F_51 ;
V_2 -> V_119 = F_24 ;
} else if ( F_5 ( V_6 ) ) {
V_2 -> V_64 = F_38 ;
V_2 -> V_135 = F_65 ;
V_2 -> V_119 = F_40 ;
} else if ( F_92 ( V_6 ) ) {
V_2 -> V_64 = F_27 ;
V_2 -> V_135 = F_62 ;
V_2 -> V_119 = F_31 ;
} else {
V_2 -> V_64 = F_32 ;
V_2 -> V_135 = F_63 ;
V_2 -> V_119 = F_33 ;
}
if ( F_5 ( V_6 ) )
V_139 -> V_253 = V_254 ;
else
V_139 -> V_253 = V_255 ;
F_160 ( V_2 , V_17 ) ;
F_172 ( V_139 , V_101 ) ;
V_2 -> V_140 = V_139 ;
if ( F_101 ( V_6 ) && ! F_173 ( V_6 ) ) {
T_2 V_128 = F_7 ( V_256 ) ;
F_21 ( V_256 , ( V_128 & ~ 0xf ) | 0xd ) ;
}
}
void F_174 ( struct V_5 * V_6 ,
T_3 V_10 , enum V_50 V_50 )
{
struct V_13 * V_14 ;
struct V_101 * V_101 ;
struct V_139 * V_139 ;
V_14 = F_175 ( sizeof( * V_14 ) , V_257 ) ;
if ( ! V_14 )
return;
V_139 = F_176 () ;
if ( ! V_139 ) {
F_116 ( V_14 ) ;
return;
}
V_101 = & V_14 -> V_3 ;
F_177 ( & V_6 -> V_258 , & V_101 -> V_3 ,
& V_259 , V_260 ,
L_29 , F_168 ( V_50 ) ) ;
V_101 -> V_261 = F_113 ;
if ( F_60 ( V_6 ) ) {
V_101 -> V_262 = F_98 ;
V_101 -> V_263 = F_99 ;
} else {
V_101 -> V_262 = F_96 ;
}
V_101 -> V_253 = F_74 ;
V_101 -> V_264 = F_80 ;
if ( F_58 ( V_6 ) ) {
V_101 -> V_265 = F_144 ;
V_101 -> V_266 = F_154 ;
V_101 -> V_78 = F_90 ;
V_101 -> V_263 = F_150 ;
V_101 -> V_267 = F_146 ;
} else if ( F_57 ( V_6 ) ) {
V_101 -> V_265 = F_142 ;
V_101 -> V_266 = F_138 ;
V_101 -> V_78 = F_90 ;
V_101 -> V_263 = F_148 ;
} else {
V_101 -> V_266 = F_137 ;
if ( F_70 ( V_6 ) )
V_101 -> V_78 = F_88 ;
else if ( F_92 ( V_6 ) )
V_101 -> V_78 = F_87 ;
else
V_101 -> V_78 = F_86 ;
}
V_101 -> type = V_160 ;
V_101 -> V_114 = F_178 ( V_50 ) ;
V_101 -> V_50 = V_50 ;
if ( F_58 ( V_6 ) ) {
if ( V_50 == V_237 )
V_101 -> V_268 = 1 << 2 ;
else
V_101 -> V_268 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_101 -> V_268 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_101 -> V_269 = 1 << V_270 ;
if ( F_101 ( V_6 ) )
V_101 -> V_269 |= 1 << V_160 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_15 . V_10 = V_10 ;
V_14 -> V_271 . V_272 = V_34 ;
V_14 -> V_240 = 4 ;
F_169 ( V_14 , V_139 ) ;
}
