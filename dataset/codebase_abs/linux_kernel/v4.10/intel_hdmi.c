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
enum V_18 type ,
const void * V_35 , T_4 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_38 = F_7 ( V_39 ) ;
int V_33 ;
F_6 ( ! ( V_38 & V_40 ) , L_2 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( type ) ;
V_38 &= ~ F_14 ( type ) ;
F_21 ( V_39 , V_38 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 += 4 ) {
F_21 ( V_42 , * V_37 ) ;
V_37 ++ ;
}
for (; V_33 < V_43 ; V_33 += 4 )
F_21 ( V_42 , 0 ) ;
F_22 () ;
V_38 |= F_14 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_21 ( V_39 , V_38 ) ;
F_23 ( V_39 ) ;
}
static bool F_24 ( struct V_11 * V_12 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
T_2 V_38 = F_7 ( V_39 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_48 ) != F_26 ( V_14 -> V_49 ) )
return false ;
return V_38 & ( V_25 |
V_27 | V_26 ) ;
}
static void F_27 ( struct V_11 * V_12 ,
enum V_18 type ,
const void * V_35 , T_4 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
T_3 V_52 = F_29 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
int V_33 ;
F_6 ( ! ( V_38 & V_40 ) , L_2 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( type ) ;
V_38 &= ~ F_14 ( type ) ;
F_21 ( V_52 , V_38 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 += 4 ) {
F_21 ( F_30 ( V_50 -> V_53 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_33 < V_43 ; V_33 += 4 )
F_21 ( F_30 ( V_50 -> V_53 ) , 0 ) ;
F_22 () ;
V_38 |= F_14 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
}
static bool F_31 ( struct V_11 * V_12 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_53 V_53 = F_28 ( V_47 -> V_3 . V_51 ) -> V_53 ;
T_3 V_52 = F_29 ( V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_48 ) != F_26 ( V_14 -> V_49 ) )
return false ;
return V_38 & ( V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
}
static void F_32 ( struct V_11 * V_12 ,
enum V_18 type ,
const void * V_35 , T_4 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
T_3 V_52 = F_29 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
int V_33 ;
F_6 ( ! ( V_38 & V_40 ) , L_2 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( type ) ;
if ( type != V_19 )
V_38 &= ~ F_14 ( type ) ;
F_21 ( V_52 , V_38 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 += 4 ) {
F_21 ( F_30 ( V_50 -> V_53 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_33 < V_43 ; V_33 += 4 )
F_21 ( F_30 ( V_50 -> V_53 ) , 0 ) ;
F_22 () ;
V_38 |= F_14 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
}
static bool F_33 ( struct V_11 * V_12 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
enum V_53 V_53 = F_28 ( V_47 -> V_3 . V_51 ) -> V_53 ;
T_2 V_38 = F_7 ( F_29 ( V_53 ) ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
return V_38 & ( V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
}
static void F_34 ( struct V_11 * V_12 ,
enum V_18 type ,
const void * V_35 , T_4 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
T_3 V_52 = F_35 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
int V_33 ;
F_6 ( ! ( V_38 & V_40 ) , L_2 ) ;
V_38 &= ~ ( V_41 | 0xf ) ;
V_38 |= F_12 ( type ) ;
V_38 &= ~ F_14 ( type ) ;
F_21 ( V_52 , V_38 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 += 4 ) {
F_21 ( F_36 ( V_50 -> V_53 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_33 < V_43 ; V_33 += 4 )
F_21 ( F_36 ( V_50 -> V_53 ) , 0 ) ;
F_22 () ;
V_38 |= F_14 ( type ) ;
V_38 &= ~ V_44 ;
V_38 |= V_45 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
}
static bool F_37 ( struct V_11 * V_12 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
enum V_53 V_53 = F_28 ( V_47 -> V_3 . V_51 ) -> V_53 ;
T_2 V_38 = F_7 ( F_35 ( V_53 ) ) ;
if ( ( V_38 & V_40 ) == 0 )
return false ;
if ( ( V_38 & V_48 ) != F_26 ( V_14 -> V_49 ) )
return false ;
return V_38 & ( V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
}
static void F_38 ( struct V_11 * V_12 ,
enum V_18 type ,
const void * V_35 , T_4 V_36 )
{
const T_1 * V_37 = V_35 ;
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
enum V_31 V_32 = V_50 -> V_56 -> V_32 ;
T_3 V_57 = F_39 ( V_32 ) ;
T_3 V_58 ;
int V_33 ;
T_2 V_38 = F_7 ( V_57 ) ;
V_58 = F_16 ( V_6 , V_32 , type , 0 ) ;
V_38 &= ~ F_15 ( type ) ;
F_21 ( V_57 , V_38 ) ;
F_22 () ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 += 4 ) {
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , * V_37 ) ;
V_37 ++ ;
}
for (; V_33 < V_43 ; V_33 += 4 )
F_21 ( F_16 ( V_6 , V_32 ,
type , V_33 >> 2 ) , 0 ) ;
F_22 () ;
V_38 |= F_15 ( type ) ;
F_21 ( V_57 , V_38 ) ;
F_23 ( V_57 ) ;
}
static bool F_40 ( struct V_11 * V_12 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
T_2 V_38 = F_7 ( F_39 ( V_47 -> V_32 ) ) ;
return V_38 & ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
}
static void F_41 ( struct V_11 * V_12 ,
union V_62 * V_35 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_5 V_63 [ V_43 ] ;
T_4 V_36 ;
V_36 = F_42 ( V_35 , V_63 + 1 , sizeof( V_63 ) - 1 ) ;
if ( V_36 < 0 )
return;
V_63 [ 0 ] = V_63 [ 1 ] ;
V_63 [ 1 ] = V_63 [ 2 ] ;
V_63 [ 2 ] = V_63 [ 3 ] ;
V_63 [ 3 ] = 0 ;
V_36 ++ ;
V_2 -> V_64 ( V_12 , V_35 -> V_65 . type , V_63 , V_36 ) ;
}
static void F_43 ( struct V_11 * V_12 ,
const struct V_66 * V_67 )
{
struct V_2 * V_2 = F_8 ( V_12 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
union V_62 V_35 ;
int V_68 ;
V_68 = F_44 ( & V_35 . V_69 ,
V_67 ) ;
if ( V_68 < 0 ) {
F_45 ( L_3 ) ;
return;
}
if ( V_2 -> V_70 ) {
if ( V_50 -> V_56 -> V_71 )
V_35 . V_69 . V_72 =
V_73 ;
else
V_35 . V_69 . V_72 =
V_74 ;
}
F_41 ( V_12 , & V_35 ) ;
}
static void F_46 ( struct V_11 * V_12 )
{
union V_62 V_35 ;
int V_68 ;
V_68 = F_47 ( & V_35 . V_75 , L_4 , L_5 ) ;
if ( V_68 < 0 ) {
F_45 ( L_6 ) ;
return;
}
V_35 . V_75 . V_76 = V_77 ;
F_41 ( V_12 , & V_35 ) ;
}
static void
F_48 ( struct V_11 * V_12 ,
const struct V_66 * V_67 )
{
union V_62 V_35 ;
int V_68 ;
V_68 = F_49 ( & V_35 . V_78 . V_15 ,
V_67 ) ;
if ( V_68 < 0 )
return;
F_41 ( V_12 , & V_35 ) ;
}
static void F_50 ( struct V_11 * V_12 ,
bool V_79 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_52 = V_39 ;
T_2 V_38 = F_7 ( V_52 ) ;
T_2 V_49 = F_26 ( V_14 -> V_49 ) ;
F_3 ( V_2 ) ;
V_38 |= V_20 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_38 & V_40 ) )
return;
if ( V_49 != ( V_38 & V_48 ) ) {
F_51 ( L_7 ,
( V_38 & V_48 ) >> 29 ) ;
return;
}
V_38 &= ~ ( V_40 | V_25 |
V_27 | V_26 ) ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
return;
}
if ( V_49 != ( V_38 & V_48 ) ) {
if ( V_38 & V_40 ) {
F_51 ( L_8 ,
( V_38 & V_48 ) >> 29 ) ;
return;
}
V_38 &= ~ V_48 ;
V_38 |= V_49 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_25 |
V_27 | V_26 ) ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
F_43 ( V_12 , V_67 ) ;
F_46 ( V_12 ) ;
F_48 ( V_12 , V_67 ) ;
}
static bool F_52 ( struct V_11 * V_12 )
{
struct V_1 * V_4 = V_12 -> V_4 ;
struct V_16 * V_17 ;
F_53 ( ! F_54 ( & V_4 -> V_80 . V_81 ) ) ;
F_55 (connector, &dev->mode_config.connector_list, head)
if ( V_17 -> V_12 == V_12 )
return V_17 -> V_82 . V_83 > 8 ;
return false ;
}
static bool F_56 ( int V_84 ,
const struct V_66 * V_85 )
{
unsigned int V_86 ;
switch ( V_84 ) {
case 30 :
V_86 = 4 ;
break;
case 36 :
V_86 = 2 ;
break;
case 48 :
V_86 = 1 ;
break;
default:
return false ;
}
return V_85 -> V_87 % V_86 == 0 &&
V_85 -> V_88 % V_86 == 0 &&
V_85 -> V_89 % V_86 == 0 &&
V_85 -> V_90 % V_86 == 0 &&
V_85 -> V_91 % V_86 == 0 &&
V_85 -> V_92 % V_86 == 0 &&
( ( V_85 -> V_93 & V_94 ) == 0 ||
V_85 -> V_88 / 2 % V_86 == 0 ) ;
}
static bool F_57 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_50 * V_51 = F_28 ( V_12 -> V_51 ) ;
T_3 V_52 ;
T_2 V_38 = 0 ;
if ( F_5 ( V_6 ) )
V_52 = F_58 ( V_51 -> V_56 -> V_32 ) ;
else if ( F_59 ( V_6 ) || F_60 ( V_6 ) )
V_52 = F_61 ( V_51 -> V_53 ) ;
else if ( F_62 ( V_6 ) )
V_52 = F_63 ( V_51 -> V_53 ) ;
else
return false ;
if ( F_52 ( V_12 ) )
V_38 |= V_95 ;
if ( F_56 ( V_51 -> V_56 -> V_84 ,
& V_51 -> V_56 -> V_3 . V_67 ) )
V_38 |= V_96 ;
F_21 ( V_52 , V_38 ) ;
return V_38 != 0 ;
}
static void F_64 ( struct V_11 * V_12 ,
bool V_79 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_2 * V_2 = & V_14 -> V_15 ;
T_3 V_52 = F_29 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
T_2 V_49 = F_26 ( V_14 -> V_49 ) ;
F_3 ( V_2 ) ;
V_38 |= V_20 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
return;
}
if ( V_49 != ( V_38 & V_48 ) ) {
F_6 ( V_38 & V_40 ,
L_9 ,
( V_38 & V_48 ) >> 29 ) ;
V_38 &= ~ V_48 ;
V_38 |= V_49 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
if ( F_57 ( V_12 ) )
V_38 |= V_55 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
F_43 ( V_12 , V_67 ) ;
F_46 ( V_12 ) ;
F_48 ( V_12 , V_67 ) ;
}
static void F_65 ( struct V_11 * V_12 ,
bool V_79 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_52 = F_29 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
F_3 ( V_2 ) ;
V_38 |= V_20 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
return;
}
V_38 |= V_40 | V_25 ;
V_38 &= ~ ( V_27 | V_54 |
V_26 | V_55 ) ;
if ( F_57 ( V_12 ) )
V_38 |= V_55 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
F_43 ( V_12 , V_67 ) ;
F_46 ( V_12 ) ;
F_48 ( V_12 , V_67 ) ;
}
static void F_66 ( struct V_11 * V_12 ,
bool V_79 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_13 * V_14 = F_25 ( V_12 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_52 = F_35 ( V_50 -> V_53 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
T_2 V_49 = F_26 ( V_14 -> V_49 ) ;
F_3 ( V_2 ) ;
V_38 |= V_20 | V_45 ;
if ( ! V_79 ) {
if ( ! ( V_38 & V_40 ) )
return;
V_38 &= ~ ( V_40 | V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
return;
}
if ( V_49 != ( V_38 & V_48 ) ) {
F_6 ( V_38 & V_40 ,
L_9 ,
( V_38 & V_48 ) >> 29 ) ;
V_38 &= ~ V_48 ;
V_38 |= V_49 ;
}
V_38 |= V_40 ;
V_38 &= ~ ( V_25 |
V_27 | V_54 |
V_26 | V_55 ) ;
if ( F_57 ( V_12 ) )
V_38 |= V_55 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
F_43 ( V_12 , V_67 ) ;
F_46 ( V_12 ) ;
F_48 ( V_12 , V_67 ) ;
}
static void F_67 ( struct V_11 * V_12 ,
bool V_79 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_4 ( V_12 -> V_4 ) ;
struct V_50 * V_50 = F_28 ( V_12 -> V_51 ) ;
struct V_2 * V_2 = F_8 ( V_12 ) ;
T_3 V_52 = F_39 ( V_50 -> V_56 -> V_32 ) ;
T_2 V_38 = F_7 ( V_52 ) ;
F_3 ( V_2 ) ;
V_38 &= ~ ( V_59 | V_28 |
V_60 | V_30 |
V_61 | V_29 ) ;
if ( ! V_79 ) {
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
return;
}
if ( F_57 ( V_12 ) )
V_38 |= V_60 ;
F_21 ( V_52 , V_38 ) ;
F_23 ( V_52 ) ;
F_43 ( V_12 , V_67 ) ;
F_46 ( V_12 ) ;
F_48 ( V_12 , V_67 ) ;
}
void F_68 ( struct V_2 * V_15 , bool V_79 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
struct V_97 * V_98 =
F_69 ( V_6 , V_15 -> V_99 ) ;
if ( V_15 -> V_100 . type < V_101 )
return;
F_51 ( L_10 ,
V_79 ? L_11 : L_12 ) ;
F_70 ( V_15 -> V_100 . type ,
V_98 , V_79 ) ;
}
static void F_71 ( struct V_102 * V_12 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_51 = F_28 ( V_12 -> V_3 . V_51 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
const struct V_66 * V_67 = & V_51 -> V_56 -> V_3 . V_67 ;
T_2 V_103 ;
F_68 ( V_2 , true ) ;
V_103 = V_104 ;
if ( ! F_62 ( V_6 ) && V_51 -> V_56 -> V_71 )
V_103 |= V_105 ;
if ( V_67 -> V_93 & V_106 )
V_103 |= V_107 ;
if ( V_67 -> V_93 & V_108 )
V_103 |= V_109 ;
if ( V_51 -> V_56 -> V_84 > 24 )
V_103 |= V_110 ;
else
V_103 |= V_111 ;
if ( V_51 -> V_56 -> V_112 )
V_103 |= V_113 ;
if ( F_72 ( V_6 ) )
V_103 |= F_73 ( V_51 -> V_53 ) ;
else if ( F_60 ( V_6 ) )
V_103 |= F_74 ( V_51 -> V_53 ) ;
else
V_103 |= F_75 ( V_51 -> V_53 ) ;
F_21 ( V_2 -> V_10 , V_103 ) ;
F_23 ( V_2 -> V_10 ) ;
}
static bool F_76 ( struct V_102 * V_12 ,
enum V_53 * V_53 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_114 V_115 ;
T_2 V_116 ;
bool V_68 ;
V_115 = F_77 ( V_12 ) ;
if ( ! F_78 ( V_6 , V_115 ) )
return false ;
V_68 = false ;
V_116 = F_7 ( V_2 -> V_10 ) ;
if ( ! ( V_116 & V_9 ) )
goto V_117;
if ( F_72 ( V_6 ) )
* V_53 = F_79 ( V_116 ) ;
else if ( F_60 ( V_6 ) )
* V_53 = F_80 ( V_116 ) ;
else
* V_53 = F_81 ( V_116 ) ;
V_68 = true ;
V_117:
F_82 ( V_6 , V_115 ) ;
return V_68 ;
}
static void F_83 ( struct V_102 * V_12 ,
struct V_46 * V_47 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
T_2 V_116 , V_93 = 0 ;
int V_118 ;
V_116 = F_7 ( V_2 -> V_10 ) ;
if ( V_116 & V_109 )
V_93 |= V_108 ;
else
V_93 |= V_119 ;
if ( V_116 & V_107 )
V_93 |= V_106 ;
else
V_93 |= V_120 ;
if ( V_116 & V_113 )
V_47 -> V_112 = true ;
if ( V_2 -> V_121 ( & V_12 -> V_3 , V_47 ) )
V_47 -> V_122 = true ;
if ( V_116 & V_123 )
V_47 -> V_124 = true ;
if ( ! F_62 ( V_6 ) &&
V_116 & V_105 )
V_47 -> V_71 = true ;
V_47 -> V_3 . V_67 . V_93 |= V_93 ;
if ( ( V_116 & V_125 ) == V_110 )
V_118 = V_47 -> V_126 * 2 / 3 ;
else
V_118 = V_47 -> V_126 ;
if ( V_47 -> V_127 )
V_118 /= V_47 -> V_127 ;
V_47 -> V_3 . V_67 . V_128 = V_118 ;
V_47 -> V_129 = 4 ;
}
static void F_84 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_50 * V_51 = F_28 ( V_12 -> V_3 . V_51 ) ;
F_53 ( ! V_51 -> V_56 -> V_112 ) ;
F_85 ( L_13 ,
F_86 ( V_51 -> V_53 ) ) ;
F_87 ( V_12 , V_47 , V_131 ) ;
}
static void F_88 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_132 ;
V_132 = F_7 ( V_2 -> V_10 ) ;
V_132 |= V_9 ;
if ( V_47 -> V_124 )
V_132 |= V_123 ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_47 -> V_124 )
F_84 ( V_12 , V_47 , V_131 ) ;
}
static void F_89 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_51 = F_28 ( V_12 -> V_3 . V_51 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
T_2 V_132 ;
V_132 = F_7 ( V_2 -> V_10 ) ;
V_132 |= V_9 ;
if ( V_51 -> V_56 -> V_124 )
V_132 |= V_123 ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_47 -> V_84 > 24 &&
V_47 -> V_127 > 1 ) {
F_21 ( V_2 -> V_10 , V_132 & ~ V_9 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
}
if ( V_47 -> V_124 )
F_84 ( V_12 , V_47 , V_131 ) ;
}
static void F_90 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_51 = F_28 ( V_12 -> V_3 . V_51 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
enum V_53 V_53 = V_51 -> V_53 ;
T_2 V_132 ;
V_132 = F_7 ( V_2 -> V_10 ) ;
V_132 |= V_9 ;
if ( V_47 -> V_124 )
V_132 |= V_123 ;
if ( V_47 -> V_84 > 24 ) {
F_21 ( F_91 ( V_53 ) ,
F_7 ( F_91 ( V_53 ) ) |
V_133 ) ;
V_132 &= ~ V_125 ;
V_132 |= V_111 ;
}
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( V_47 -> V_84 > 24 ) {
V_132 &= ~ V_125 ;
V_132 |= V_110 ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( F_91 ( V_53 ) ,
F_7 ( F_91 ( V_53 ) ) &
~ V_133 ) ;
}
if ( V_47 -> V_124 )
F_84 ( V_12 , V_47 , V_131 ) ;
}
static void F_92 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
}
static void F_93 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_50 * V_51 = F_28 ( V_12 -> V_3 . V_51 ) ;
T_2 V_132 ;
V_132 = F_7 ( V_2 -> V_10 ) ;
V_132 &= ~ ( V_9 | V_123 ) ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
if ( F_94 ( V_6 ) && V_51 -> V_53 == V_136 ) {
F_95 ( V_6 , V_137 , false ) ;
F_96 ( V_6 , V_137 , false ) ;
V_132 &= ~ V_138 ;
V_132 |= V_9 ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
V_132 &= ~ V_9 ;
F_21 ( V_2 -> V_10 , V_132 ) ;
F_23 ( V_2 -> V_10 ) ;
F_97 ( V_6 , V_137 ) ;
F_95 ( V_6 , V_137 , true ) ;
F_96 ( V_6 , V_137 , true ) ;
}
V_2 -> V_139 ( & V_12 -> V_3 , false , NULL ) ;
F_68 ( V_2 , false ) ;
}
static void F_98 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
if ( V_134 -> V_124 )
F_99 ( V_12 ) ;
F_93 ( V_12 , V_134 , V_135 ) ;
}
static void F_100 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
if ( V_134 -> V_124 )
F_99 ( V_12 ) ;
}
static void F_101 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
F_93 ( V_12 , V_134 , V_135 ) ;
}
static int F_102 ( struct V_5 * V_6 )
{
if ( F_103 ( V_6 ) )
return 165000 ;
else if ( F_104 ( V_6 ) || F_105 ( V_6 ) -> V_140 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_106 ( struct V_2 * V_15 ,
bool V_141 )
{
struct V_1 * V_4 = F_1 ( V_15 ) ;
int V_142 = F_102 ( F_4 ( V_4 ) ) ;
if ( V_141 ) {
struct V_143 * V_17 = V_15 -> V_144 ;
const struct V_145 * V_146 = & V_17 -> V_3 . V_82 ;
if ( V_15 -> V_100 . V_142 )
V_142 = F_107 ( V_142 ,
V_15 -> V_100 . V_142 ) ;
if ( V_146 -> V_142 )
V_142 = F_107 ( V_142 ,
V_146 -> V_142 ) ;
else if ( ! V_15 -> V_112 )
V_142 = F_107 ( V_142 , 165000 ) ;
}
return V_142 ;
}
static enum V_147
F_108 ( struct V_2 * V_15 ,
int clock , bool V_141 )
{
struct V_5 * V_6 = F_4 ( F_1 ( V_15 ) ) ;
if ( clock < 25000 )
return V_148 ;
if ( clock > F_106 ( V_15 , V_141 ) )
return V_149 ;
if ( F_109 ( V_6 ) && clock > 223333 && clock < 240000 )
return V_150 ;
if ( F_60 ( V_6 ) && clock > 216000 && clock < 240000 )
return V_150 ;
return V_151 ;
}
static enum V_147
F_110 ( struct V_16 * V_17 ,
struct V_66 * V_85 )
{
struct V_2 * V_15 = F_10 ( V_17 ) ;
struct V_1 * V_4 = F_1 ( V_15 ) ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_147 V_152 ;
int clock ;
int V_153 = F_4 ( V_17 -> V_4 ) -> V_154 ;
if ( V_85 -> V_93 & V_155 )
return V_156 ;
clock = V_85 -> clock ;
if ( ( V_85 -> V_93 & V_157 ) == V_158 )
clock *= 2 ;
if ( clock > V_153 )
return V_149 ;
if ( V_85 -> V_93 & V_159 )
clock *= 2 ;
V_152 = F_108 ( V_15 , clock , true ) ;
if ( ! F_111 ( V_6 ) && V_152 != V_151 )
V_152 = F_108 ( V_15 , clock * 3 / 2 , true ) ;
return V_152 ;
}
static bool F_112 ( struct V_46 * V_160 )
{
struct V_1 * V_4 = V_160 -> V_3 . V_51 -> V_4 ;
if ( F_111 ( F_4 ( V_4 ) ) )
return false ;
return V_160 -> V_161 == 1 << V_162 ;
}
bool F_113 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
struct V_5 * V_6 = F_4 ( V_12 -> V_3 . V_4 ) ;
struct V_66 * V_67 = & V_47 -> V_3 . V_67 ;
int V_163 = V_47 -> V_3 . V_67 . V_128 ;
int V_164 = V_163 * 3 / 2 ;
int V_165 ;
V_47 -> V_112 = V_2 -> V_112 ;
if ( V_47 -> V_112 )
V_47 -> V_122 = true ;
if ( V_2 -> V_166 ) {
V_47 -> V_71 =
V_47 -> V_112 &&
F_114 ( V_67 ) > 1 ;
} else {
V_47 -> V_71 =
V_2 -> V_71 ;
}
if ( V_67 -> V_93 & V_159 ) {
V_47 -> V_127 = 2 ;
V_163 *= 2 ;
V_164 *= 2 ;
}
if ( F_62 ( V_6 ) && ! F_5 ( V_6 ) )
V_47 -> V_167 = true ;
if ( V_47 -> V_112 && V_2 -> V_124 )
V_47 -> V_124 = true ;
if ( V_47 -> V_84 > 8 * 3 && V_47 -> V_112 &&
F_108 ( V_2 , V_164 , true ) == V_151 &&
F_112 ( V_47 ) ) {
F_51 ( L_14 ) ;
V_165 = 12 * 3 ;
V_47 -> V_126 = V_164 ;
} else {
F_51 ( L_15 ) ;
V_165 = 8 * 3 ;
V_47 -> V_126 = V_163 ;
}
if ( ! V_47 -> V_168 ) {
F_51 ( L_16 , V_165 ) ;
V_47 -> V_84 = V_165 ;
}
if ( F_108 ( V_2 , V_47 -> V_126 ,
false ) != V_151 ) {
F_51 ( L_17 ) ;
return false ;
}
V_67 -> V_169 = V_2 -> V_170 ;
V_47 -> V_129 = 4 ;
return true ;
}
static void
F_115 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
V_2 -> V_112 = false ;
V_2 -> V_124 = false ;
V_2 -> V_70 = false ;
V_2 -> V_100 . type = V_171 ;
V_2 -> V_100 . V_142 = 0 ;
F_116 ( F_117 ( V_17 ) -> V_172 ) ;
F_117 ( V_17 ) -> V_172 = NULL ;
}
static void
F_118 ( struct V_16 * V_17 , bool V_173 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_15 = F_10 ( V_17 ) ;
enum V_49 V_49 = F_2 ( V_15 ) -> V_49 ;
struct V_97 * V_98 =
F_69 ( V_6 , V_15 -> V_99 ) ;
enum V_174 type = F_119 ( V_98 ) ;
if ( type == V_175 ) {
if ( V_173 &&
F_120 ( V_6 , V_49 ) ) {
F_51 ( L_18 ) ;
type = V_176 ;
} else {
type = V_171 ;
}
}
if ( type == V_171 )
return;
V_15 -> V_100 . type = type ;
V_15 -> V_100 . V_142 =
F_121 ( type , V_98 ) ;
F_51 ( L_19 ,
F_122 ( type ) ,
V_15 -> V_100 . V_142 ) ;
}
static bool
F_123 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_177 * V_177 ;
bool V_178 = false ;
F_124 ( V_6 , V_179 ) ;
V_177 = F_125 ( V_17 ,
F_69 ( V_6 ,
V_2 -> V_99 ) ) ;
F_118 ( V_17 , V_177 != NULL ) ;
F_82 ( V_6 , V_179 ) ;
F_117 ( V_17 ) -> V_172 = V_177 ;
if ( V_177 && V_177 -> V_180 & V_181 ) {
V_2 -> V_70 =
F_126 ( V_177 ) ;
V_2 -> V_124 = F_127 ( V_177 ) ;
if ( V_2 -> V_182 != V_183 )
V_2 -> V_124 =
V_2 -> V_182 == V_184 ;
if ( V_2 -> V_182 != V_185 )
V_2 -> V_112 =
F_128 ( V_177 ) ;
V_178 = true ;
}
return V_178 ;
}
static enum V_186
F_129 ( struct V_16 * V_17 , bool V_187 )
{
enum V_186 V_152 ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
F_51 ( L_20 ,
V_17 -> V_3 . V_188 , V_17 -> V_189 ) ;
F_124 ( V_6 , V_179 ) ;
F_115 ( V_17 ) ;
if ( F_123 ( V_17 ) ) {
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_162 ;
V_152 = V_190 ;
} else
V_152 = V_191 ;
F_82 ( V_6 , V_179 ) ;
return V_152 ;
}
static void
F_130 ( struct V_16 * V_17 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
F_51 ( L_20 ,
V_17 -> V_3 . V_188 , V_17 -> V_189 ) ;
F_115 ( V_17 ) ;
if ( V_17 -> V_152 != V_190 )
return;
F_123 ( V_17 ) ;
F_2 ( V_2 ) -> V_3 . type = V_162 ;
}
static int F_131 ( struct V_16 * V_17 )
{
struct V_177 * V_177 ;
V_177 = F_117 ( V_17 ) -> V_172 ;
if ( V_177 == NULL )
return 0 ;
return F_132 ( V_17 , V_177 ) ;
}
static bool
F_133 ( struct V_16 * V_17 )
{
bool V_124 = false ;
struct V_177 * V_177 ;
V_177 = F_117 ( V_17 ) -> V_172 ;
if ( V_177 && V_177 -> V_180 & V_181 )
V_124 = F_127 ( V_177 ) ;
return V_124 ;
}
static int
F_134 ( struct V_16 * V_17 ,
struct V_192 * V_193 ,
T_6 V_38 )
{
struct V_2 * V_2 = F_10 ( V_17 ) ;
struct V_13 * V_14 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = F_4 ( V_17 -> V_4 ) ;
int V_68 ;
V_68 = F_135 ( & V_17 -> V_3 , V_193 , V_38 ) ;
if ( V_68 )
return V_68 ;
if ( V_193 == V_6 -> V_194 ) {
enum V_195 V_33 = V_38 ;
bool V_124 ;
if ( V_33 == V_2 -> V_182 )
return 0 ;
V_2 -> V_182 = V_33 ;
if ( V_33 == V_183 )
V_124 = F_133 ( V_17 ) ;
else
V_124 = ( V_33 == V_184 ) ;
if ( V_33 == V_185 )
V_2 -> V_112 = 0 ;
V_2 -> V_124 = V_124 ;
goto V_196;
}
if ( V_193 == V_6 -> V_197 ) {
bool V_198 = V_2 -> V_166 ;
bool V_199 = V_2 -> V_71 ;
switch ( V_38 ) {
case V_200 :
V_2 -> V_166 = true ;
break;
case V_201 :
V_2 -> V_166 = false ;
V_2 -> V_71 = false ;
break;
case V_202 :
V_2 -> V_166 = false ;
V_2 -> V_71 = true ;
break;
default:
return - V_203 ;
}
if ( V_198 == V_2 -> V_166 &&
V_199 == V_2 -> V_71 )
return 0 ;
goto V_196;
}
if ( V_193 == V_17 -> V_4 -> V_80 . V_204 ) {
switch ( V_38 ) {
case V_205 :
V_2 -> V_170 = V_206 ;
break;
case V_207 :
V_2 -> V_170 = V_208 ;
break;
case V_209 :
V_2 -> V_170 = V_210 ;
break;
default:
return - V_203 ;
}
goto V_196;
}
return - V_203 ;
V_196:
if ( V_14 -> V_3 . V_3 . V_51 )
F_136 ( V_14 -> V_3 . V_3 . V_51 ) ;
return 0 ;
}
static void F_137 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_2 * V_2 = F_8 ( & V_12 -> V_3 ) ;
const struct V_66 * V_67 = & V_47 -> V_3 . V_67 ;
F_71 ( V_12 ) ;
V_2 -> V_139 ( & V_12 -> V_3 ,
V_47 -> V_112 ,
V_67 ) ;
}
static void F_138 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_13 * V_211 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_211 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
const struct V_66 * V_67 = & V_47 -> V_3 . V_67 ;
F_139 ( V_12 ) ;
F_140 ( V_12 , 0x2b245f5f , 0x00002000 , 0x5578b83a ,
0x2b247878 ) ;
V_2 -> V_139 ( & V_12 -> V_3 ,
V_47 -> V_112 ,
V_67 ) ;
F_88 ( V_12 , V_47 , V_131 ) ;
F_141 ( V_6 , V_211 , 0x0 ) ;
}
static void F_142 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
F_71 ( V_12 ) ;
F_143 ( V_12 ) ;
}
static void F_144 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
F_71 ( V_12 ) ;
F_145 ( V_12 ) ;
}
static void F_146 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
F_147 ( V_12 ) ;
}
static void F_148 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
F_149 ( V_12 ) ;
}
static void F_150 ( struct V_102 * V_12 ,
struct V_46 * V_134 ,
struct V_130 * V_135 )
{
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_151 ( & V_6 -> V_212 ) ;
F_152 ( V_12 , true ) ;
F_153 ( & V_6 -> V_212 ) ;
}
static void F_154 ( struct V_102 * V_12 ,
struct V_46 * V_47 ,
struct V_130 * V_131 )
{
struct V_13 * V_211 = F_25 ( & V_12 -> V_3 ) ;
struct V_2 * V_2 = & V_211 -> V_15 ;
struct V_1 * V_4 = V_12 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_50 * V_50 =
F_28 ( V_12 -> V_3 . V_51 ) ;
const struct V_66 * V_67 = & V_50 -> V_56 -> V_3 . V_67 ;
F_155 ( V_12 ) ;
F_156 ( V_12 , 128 , 102 , false ) ;
V_2 -> V_139 ( & V_12 -> V_3 ,
V_50 -> V_56 -> V_112 ,
V_67 ) ;
F_88 ( V_12 , V_47 , V_131 ) ;
F_141 ( V_6 , V_211 , 0x0 ) ;
F_157 ( V_12 ) ;
}
static void F_158 ( struct V_16 * V_17 )
{
F_116 ( F_117 ( V_17 ) -> V_172 ) ;
F_159 ( V_17 ) ;
F_116 ( V_17 ) ;
}
static void
F_160 ( struct V_2 * V_2 , struct V_16 * V_17 )
{
F_161 ( V_17 ) ;
F_162 ( V_17 ) ;
V_2 -> V_166 = true ;
F_163 ( V_17 ) ;
V_2 -> V_170 = V_206 ;
}
static T_7 F_164 ( struct V_5 * V_6 ,
enum V_49 V_49 )
{
const struct V_213 * V_146 =
& V_6 -> V_214 . V_215 [ V_49 ] ;
T_7 V_216 ;
if ( V_146 -> V_217 ) {
F_51 ( L_21 ,
V_146 -> V_217 , F_165 ( V_49 ) ) ;
return V_146 -> V_217 ;
}
switch ( V_49 ) {
case V_218 :
if ( F_109 ( V_6 ) )
V_216 = V_219 ;
else
V_216 = V_220 ;
break;
case V_221 :
if ( F_109 ( V_6 ) )
V_216 = V_222 ;
else
V_216 = V_223 ;
break;
case V_224 :
if ( F_60 ( V_6 ) )
V_216 = V_225 ;
else
V_216 = V_226 ;
break;
default:
F_13 ( V_49 ) ;
V_216 = V_220 ;
break;
}
F_51 ( L_22 ,
V_216 , F_165 ( V_49 ) ) ;
return V_216 ;
}
void F_166 ( struct V_13 * V_14 ,
struct V_143 * V_143 )
{
struct V_16 * V_17 = & V_143 -> V_3 ;
struct V_2 * V_2 = & V_14 -> V_15 ;
struct V_102 * V_102 = & V_14 -> V_3 ;
struct V_1 * V_4 = V_102 -> V_3 . V_4 ;
struct V_5 * V_6 = F_4 ( V_4 ) ;
enum V_49 V_49 = V_14 -> V_49 ;
F_51 ( L_23 ,
F_165 ( V_49 ) ) ;
if ( F_6 ( V_14 -> V_227 < 4 ,
L_24 ,
V_14 -> V_227 , F_165 ( V_49 ) ) )
return;
F_167 ( V_4 , V_17 , & V_228 ,
V_229 ) ;
F_168 ( V_17 , & V_230 ) ;
V_17 -> V_231 = 1 ;
V_17 -> V_232 = 0 ;
V_17 -> V_233 = 1 ;
V_2 -> V_99 = F_164 ( V_6 , V_49 ) ;
switch ( V_49 ) {
case V_218 :
if ( F_169 ( V_6 , 0 , V_234 ) )
V_102 -> V_235 = V_236 ;
else
V_102 -> V_235 = V_237 ;
break;
case V_221 :
V_102 -> V_235 = V_238 ;
break;
case V_224 :
V_102 -> V_235 = V_239 ;
break;
case V_240 :
V_102 -> V_235 = V_241 ;
break;
default:
F_13 ( V_49 ) ;
return;
}
if ( F_59 ( V_6 ) || F_60 ( V_6 ) ) {
V_2 -> V_64 = F_34 ;
V_2 -> V_139 = F_66 ;
V_2 -> V_121 = F_37 ;
} else if ( F_103 ( V_6 ) ) {
V_2 -> V_64 = F_20 ;
V_2 -> V_139 = F_50 ;
V_2 -> V_121 = F_24 ;
} else if ( F_5 ( V_6 ) ) {
V_2 -> V_64 = F_38 ;
V_2 -> V_139 = F_67 ;
V_2 -> V_121 = F_40 ;
} else if ( F_94 ( V_6 ) ) {
V_2 -> V_64 = F_27 ;
V_2 -> V_139 = F_64 ;
V_2 -> V_121 = F_31 ;
} else {
V_2 -> V_64 = F_32 ;
V_2 -> V_139 = F_65 ;
V_2 -> V_121 = F_33 ;
}
if ( F_5 ( V_6 ) )
V_143 -> V_242 = V_243 ;
else
V_143 -> V_242 = V_244 ;
F_160 ( V_2 , V_17 ) ;
F_170 ( V_143 , V_102 ) ;
V_2 -> V_144 = V_143 ;
if ( F_103 ( V_6 ) && ! F_171 ( V_6 ) ) {
T_2 V_132 = F_7 ( V_245 ) ;
F_21 ( V_245 , ( V_132 & ~ 0xf ) | 0xd ) ;
}
}
void F_172 ( struct V_1 * V_4 ,
T_3 V_10 , enum V_49 V_49 )
{
struct V_5 * V_6 = F_4 ( V_4 ) ;
struct V_13 * V_14 ;
struct V_102 * V_102 ;
struct V_143 * V_143 ;
V_14 = F_173 ( sizeof( * V_14 ) , V_246 ) ;
if ( ! V_14 )
return;
V_143 = F_174 () ;
if ( ! V_143 ) {
F_116 ( V_14 ) ;
return;
}
V_102 = & V_14 -> V_3 ;
F_175 ( V_4 , & V_102 -> V_3 , & V_247 ,
V_248 , L_25 , F_165 ( V_49 ) ) ;
V_102 -> V_249 = F_113 ;
if ( F_62 ( V_6 ) ) {
V_102 -> V_250 = F_100 ;
V_102 -> V_251 = F_101 ;
} else {
V_102 -> V_250 = F_98 ;
}
V_102 -> V_242 = F_76 ;
V_102 -> V_252 = F_83 ;
if ( F_60 ( V_6 ) ) {
V_102 -> V_253 = F_144 ;
V_102 -> V_254 = F_154 ;
V_102 -> V_79 = F_92 ;
V_102 -> V_251 = F_150 ;
V_102 -> V_255 = F_146 ;
} else if ( F_59 ( V_6 ) ) {
V_102 -> V_253 = F_142 ;
V_102 -> V_254 = F_138 ;
V_102 -> V_79 = F_92 ;
V_102 -> V_251 = F_148 ;
} else {
V_102 -> V_254 = F_137 ;
if ( F_72 ( V_6 ) )
V_102 -> V_79 = F_90 ;
else if ( F_94 ( V_6 ) )
V_102 -> V_79 = F_89 ;
else
V_102 -> V_79 = F_88 ;
}
V_102 -> type = V_162 ;
V_102 -> V_49 = V_49 ;
if ( F_60 ( V_6 ) ) {
if ( V_49 == V_224 )
V_102 -> V_256 = 1 << 2 ;
else
V_102 -> V_256 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_102 -> V_256 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_102 -> V_257 = 1 << V_258 ;
if ( F_103 ( V_6 ) )
V_102 -> V_257 |= 1 << V_162 ;
V_14 -> V_49 = V_49 ;
V_14 -> V_15 . V_10 = V_10 ;
V_14 -> V_259 . V_260 = V_34 ;
V_14 -> V_227 = 4 ;
F_166 ( V_14 , V_143 ) ;
}
