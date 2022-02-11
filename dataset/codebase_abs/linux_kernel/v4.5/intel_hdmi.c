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
F_12 ( type ) ;
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
F_12 ( type ) ;
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
F_12 ( type ) ;
return 0 ;
}
}
static T_3
F_15 ( struct V_5 * V_6 ,
enum V_32 V_33 ,
enum V_19 type ,
int V_34 )
{
switch ( type ) {
case V_20 :
return F_16 ( V_33 , V_34 ) ;
case V_22 :
return F_17 ( V_33 , V_34 ) ;
case V_24 :
return F_18 ( V_33 , V_34 ) ;
default:
F_12 ( type ) ;
return V_35 ;
}
}
static void F_19 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_39 = F_6 ( V_40 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_40 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( V_43 , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( V_43 , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_40 , V_39 ) ;
F_22 ( V_40 ) ;
}
static bool F_23 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
T_2 V_39 = F_6 ( V_40 ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_27 ) ;
}
static void F_27 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_30 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_31 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_3 V_53 = F_29 ( V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_32 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
if ( type != V_20 )
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_30 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_30 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_33 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 = F_6 ( F_29 ( V_54 ) ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_34 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
int V_34 ;
F_5 ( ! ( V_39 & V_41 ) , L_2 ) ;
V_39 &= ~ ( V_42 | 0xf ) ;
V_39 |= F_11 ( type ) ;
V_39 &= ~ F_13 ( type ) ;
F_20 ( V_53 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_36 ( V_51 -> V_54 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_36 ( V_51 -> V_54 ) , 0 ) ;
F_21 () ;
V_39 |= F_13 ( type ) ;
V_39 &= ~ V_45 ;
V_39 |= V_46 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
}
static bool F_37 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
enum V_54 V_54 = F_28 ( V_48 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 = F_6 ( F_35 ( V_54 ) ) ;
if ( ( V_39 & V_41 ) == 0 )
return false ;
if ( ( V_39 & V_49 ) != F_26 ( V_15 -> V_50 ) )
return false ;
return V_39 & ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
}
static void F_38 ( struct V_12 * V_13 ,
enum V_19 type ,
const void * V_36 , T_4 V_37 )
{
const T_1 * V_38 = V_36 ;
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
enum V_32 V_33 = V_51 -> V_57 -> V_33 ;
T_3 V_58 = F_39 ( V_33 ) ;
T_3 V_59 ;
int V_34 ;
T_2 V_39 = F_6 ( V_58 ) ;
V_59 = F_15 ( V_6 , V_33 , type , 0 ) ;
V_39 &= ~ F_14 ( type ) ;
F_20 ( V_58 , V_39 ) ;
F_21 () ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 += 4 ) {
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , * V_38 ) ;
V_38 ++ ;
}
for (; V_34 < V_44 ; V_34 += 4 )
F_20 ( F_15 ( V_6 , V_33 ,
type , V_34 >> 2 ) , 0 ) ;
F_21 () ;
V_39 |= F_14 ( type ) ;
F_20 ( V_58 , V_39 ) ;
F_22 ( V_58 ) ;
}
static bool F_40 ( struct V_12 * V_13 ,
const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_4 ) ;
T_2 V_39 = F_6 ( F_39 ( V_48 -> V_33 ) ) ;
return V_39 & ( V_60 | V_29 |
V_61 | V_31 |
V_62 | V_30 ) ;
}
static void F_41 ( struct V_12 * V_13 ,
union V_63 * V_36 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_5 V_64 [ V_44 ] ;
T_4 V_37 ;
V_37 = F_42 ( V_36 , V_64 + 1 , sizeof( V_64 ) - 1 ) ;
if ( V_37 < 0 )
return;
V_64 [ 0 ] = V_64 [ 1 ] ;
V_64 [ 1 ] = V_64 [ 2 ] ;
V_64 [ 2 ] = V_64 [ 3 ] ;
V_64 [ 3 ] = 0 ;
V_37 ++ ;
V_2 -> V_65 ( V_13 , V_36 -> V_66 . type , V_64 , V_37 ) ;
}
static void F_43 ( struct V_12 * V_13 ,
const struct V_67 * V_68 )
{
struct V_2 * V_2 = F_7 ( V_13 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
union V_63 V_36 ;
int V_69 ;
V_69 = F_44 ( & V_36 . V_70 ,
V_68 ) ;
if ( V_69 < 0 ) {
F_45 ( L_3 ) ;
return;
}
if ( V_2 -> V_71 ) {
if ( V_51 -> V_57 -> V_72 )
V_36 . V_70 . V_73 =
V_74 ;
else
V_36 . V_70 . V_73 =
V_75 ;
}
F_41 ( V_13 , & V_36 ) ;
}
static void F_46 ( struct V_12 * V_13 )
{
union V_63 V_36 ;
int V_69 ;
V_69 = F_47 ( & V_36 . V_76 , L_4 , L_5 ) ;
if ( V_69 < 0 ) {
F_45 ( L_6 ) ;
return;
}
V_36 . V_76 . V_77 = V_78 ;
F_41 ( V_13 , & V_36 ) ;
}
static void
F_48 ( struct V_12 * V_13 ,
const struct V_67 * V_68 )
{
union V_63 V_36 ;
int V_69 ;
V_69 = F_49 ( & V_36 . V_79 . V_16 ,
V_68 ) ;
if ( V_69 < 0 )
return;
F_41 ( V_13 , & V_36 ) ;
}
static void F_50 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_53 = V_40 ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
if ( V_50 != ( V_39 & V_49 ) ) {
F_51 ( L_7 ,
( V_39 & V_49 ) >> 29 ) ;
return;
}
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_27 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
if ( V_39 & V_41 ) {
F_51 ( L_8 ,
( V_39 & V_49 ) >> 29 ) ;
return;
}
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_27 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static bool F_52 ( struct V_12 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_4 ;
struct V_17 * V_18 ;
F_53 ( ! F_54 ( & V_4 -> V_81 . V_82 ) ) ;
F_55 (connector, &dev->mode_config.connector_list, head)
if ( V_18 -> V_13 == V_13 )
return V_18 -> V_83 . V_84 > 8 ;
return false ;
}
static bool F_56 ( int V_85 ,
const struct V_67 * V_86 )
{
unsigned int V_87 ;
switch ( V_85 ) {
case 30 :
V_87 = 4 ;
break;
case 36 :
V_87 = 2 ;
break;
case 48 :
V_87 = 1 ;
break;
default:
return false ;
}
return V_86 -> V_88 % V_87 == 0 &&
V_86 -> V_89 % V_87 == 0 &&
V_86 -> V_90 % V_87 == 0 &&
V_86 -> V_91 % V_87 == 0 &&
V_86 -> V_92 % V_87 == 0 &&
V_86 -> V_93 % V_87 == 0 &&
( ( V_86 -> V_94 & V_95 ) == 0 ||
V_86 -> V_89 / 2 % V_87 == 0 ) ;
}
static bool F_57 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_52 ) ;
T_3 V_53 ;
T_2 V_39 = 0 ;
if ( F_4 ( V_6 ) )
V_53 = F_58 ( V_52 -> V_57 -> V_33 ) ;
else if ( F_59 ( V_6 ) || F_60 ( V_6 ) )
V_53 = F_61 ( V_52 -> V_54 ) ;
else if ( F_62 ( V_6 -> V_4 ) )
V_53 = F_63 ( V_52 -> V_54 ) ;
else
return false ;
if ( F_52 ( V_13 ) )
V_39 |= V_96 ;
if ( F_56 ( V_52 -> V_57 -> V_85 ,
& V_52 -> V_57 -> V_3 . V_68 ) )
V_39 |= V_97 ;
F_20 ( V_53 , V_39 ) ;
return V_39 != 0 ;
}
static void F_64 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_2 * V_2 = & V_15 -> V_16 ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
F_5 ( V_39 & V_41 ,
L_9 ,
( V_39 & V_49 ) >> 29 ) ;
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_65 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_29 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
V_39 |= V_41 | V_26 ;
V_39 &= ~ ( V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_66 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_14 * V_15 = F_25 ( V_13 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_35 ( V_51 -> V_54 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
T_2 V_50 = F_26 ( V_15 -> V_50 ) ;
F_3 ( V_2 ) ;
V_39 |= V_21 | V_46 ;
if ( ! V_80 ) {
if ( ! ( V_39 & V_41 ) )
return;
V_39 &= ~ ( V_41 | V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( V_50 != ( V_39 & V_49 ) ) {
F_5 ( V_39 & V_41 ,
L_9 ,
( V_39 & V_49 ) >> 29 ) ;
V_39 &= ~ V_49 ;
V_39 |= V_50 ;
}
V_39 |= V_41 ;
V_39 &= ~ ( V_26 |
V_28 | V_55 |
V_27 | V_56 ) ;
if ( F_57 ( V_13 ) )
V_39 |= V_56 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_67 ( struct V_12 * V_13 ,
bool V_80 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = V_13 -> V_4 -> V_7 ;
struct V_51 * V_51 = F_28 ( V_13 -> V_52 ) ;
struct V_2 * V_2 = F_7 ( V_13 ) ;
T_3 V_53 = F_39 ( V_51 -> V_57 -> V_33 ) ;
T_2 V_39 = F_6 ( V_53 ) ;
F_3 ( V_2 ) ;
V_39 &= ~ ( V_60 | V_29 |
V_61 | V_31 |
V_62 | V_30 ) ;
if ( ! V_80 ) {
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
return;
}
if ( F_57 ( V_13 ) )
V_39 |= V_61 ;
F_20 ( V_53 , V_39 ) ;
F_22 ( V_53 ) ;
F_43 ( V_13 , V_68 ) ;
F_46 ( V_13 ) ;
F_48 ( V_13 , V_68 ) ;
}
static void F_68 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
const struct V_67 * V_68 = & V_52 -> V_57 -> V_3 . V_68 ;
T_2 V_99 ;
V_99 = V_100 ;
if ( ! F_62 ( V_4 ) && V_52 -> V_57 -> V_72 )
V_99 |= V_101 ;
if ( V_68 -> V_94 & V_102 )
V_99 |= V_103 ;
if ( V_68 -> V_94 & V_104 )
V_99 |= V_105 ;
if ( V_52 -> V_57 -> V_85 > 24 )
V_99 |= V_106 ;
else
V_99 |= V_107 ;
if ( V_52 -> V_57 -> V_108 )
V_99 |= V_109 ;
if ( F_69 ( V_4 ) )
V_99 |= F_70 ( V_52 -> V_54 ) ;
else if ( F_60 ( V_4 ) )
V_99 |= F_71 ( V_52 -> V_54 ) ;
else
V_99 |= F_72 ( V_52 -> V_54 ) ;
F_20 ( V_2 -> V_11 , V_99 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_73 ( struct V_98 * V_13 ,
enum V_54 * V_54 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_110 V_111 ;
T_2 V_112 ;
bool V_69 ;
V_111 = F_74 ( V_13 ) ;
if ( ! F_75 ( V_6 , V_111 ) )
return false ;
V_69 = false ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_112 & V_10 ) )
goto V_113;
if ( F_69 ( V_4 ) )
* V_54 = F_76 ( V_112 ) ;
else if ( F_60 ( V_4 ) )
* V_54 = F_77 ( V_112 ) ;
else
* V_54 = F_78 ( V_112 ) ;
V_69 = true ;
V_113:
F_79 ( V_6 , V_111 ) ;
return V_69 ;
}
static void F_80 ( struct V_98 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_112 , V_94 = 0 ;
int V_114 ;
V_112 = F_6 ( V_2 -> V_11 ) ;
if ( V_112 & V_105 )
V_94 |= V_104 ;
else
V_94 |= V_115 ;
if ( V_112 & V_103 )
V_94 |= V_102 ;
else
V_94 |= V_116 ;
if ( V_112 & V_109 )
V_48 -> V_108 = true ;
if ( V_2 -> V_117 ( & V_13 -> V_3 , V_48 ) )
V_48 -> V_118 = true ;
if ( V_112 & V_119 )
V_48 -> V_120 = true ;
if ( ! F_62 ( V_4 ) &&
V_112 & V_101 )
V_48 -> V_72 = true ;
V_48 -> V_3 . V_68 . V_94 |= V_94 ;
if ( ( V_112 & V_121 ) == V_106 )
V_114 = V_48 -> V_122 * 2 / 3 ;
else
V_114 = V_48 -> V_122 ;
if ( V_48 -> V_123 )
V_114 /= V_48 -> V_123 ;
if ( F_62 ( V_6 -> V_4 ) )
F_81 ( V_48 , V_114 ) ;
V_48 -> V_3 . V_68 . V_124 = V_114 ;
}
static void F_82 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
F_53 ( ! V_52 -> V_57 -> V_108 ) ;
F_83 ( L_10 ,
F_84 ( V_52 -> V_54 ) ) ;
F_85 ( V_13 ) ;
}
static void F_86 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_87 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 &&
V_52 -> V_57 -> V_123 > 1 ) {
F_20 ( V_2 -> V_11 , V_125 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_88 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 |= V_10 ;
if ( V_52 -> V_57 -> V_120 )
V_125 |= V_119 ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
F_20 ( F_89 ( V_54 ) ,
F_6 ( F_89 ( V_54 ) ) |
V_126 ) ;
V_125 &= ~ V_121 ;
V_125 |= V_107 ;
}
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
V_125 &= ~ V_121 ;
V_125 |= V_106 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( F_89 ( V_54 ) ,
F_6 ( F_89 ( V_54 ) ) &
~ V_126 ) ;
}
if ( V_52 -> V_57 -> V_120 )
F_82 ( V_13 ) ;
}
static void F_90 ( struct V_98 * V_13 )
{
}
static void F_91 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
T_2 V_125 ;
V_125 = F_6 ( V_2 -> V_11 ) ;
V_125 &= ~ ( V_10 | V_119 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_92 ( V_4 ) && V_52 -> V_54 == V_127 ) {
F_93 ( V_6 , V_128 , false ) ;
F_94 ( V_6 , V_128 , false ) ;
V_125 &= ~ V_129 ;
V_125 |= V_10 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
V_125 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_125 ) ;
F_22 ( V_2 -> V_11 ) ;
F_95 ( V_6 -> V_4 , V_128 ) ;
F_93 ( V_6 , V_128 , true ) ;
F_94 ( V_6 , V_128 , true ) ;
}
V_2 -> V_130 ( & V_13 -> V_3 , false , NULL ) ;
}
static void F_96 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_120 )
F_97 ( V_13 ) ;
F_91 ( V_13 ) ;
}
static void F_98 ( struct V_98 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_120 )
F_97 ( V_13 ) ;
}
static void F_99 ( struct V_98 * V_13 )
{
F_91 ( V_13 ) ;
}
static int F_100 ( struct V_2 * V_16 , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( ( V_131 && ! V_16 -> V_108 ) || F_101 ( V_4 ) )
return 165000 ;
else if ( F_102 ( V_4 ) || F_103 ( V_4 ) -> V_132 >= 8 )
return 300000 ;
else
return 225000 ;
}
static enum V_133
F_104 ( struct V_2 * V_16 ,
int clock , bool V_131 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( clock < 25000 )
return V_134 ;
if ( clock > F_100 ( V_16 , V_131 ) )
return V_135 ;
if ( F_105 ( V_4 ) && clock > 223333 && clock < 240000 )
return V_136 ;
if ( F_60 ( V_4 ) && clock > 216000 && clock < 240000 )
return V_136 ;
return V_137 ;
}
static enum V_133
F_106 ( struct V_17 * V_18 ,
struct V_67 * V_86 )
{
struct V_2 * V_16 = F_9 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_16 ) ;
enum V_133 V_138 ;
int clock ;
if ( V_86 -> V_94 & V_139 )
return V_140 ;
clock = V_86 -> clock ;
if ( V_86 -> V_94 & V_141 )
clock *= 2 ;
V_138 = F_104 ( V_16 , clock , true ) ;
if ( ! F_107 ( V_4 ) && V_138 != V_137 )
V_138 = F_104 ( V_16 , clock * 3 / 2 , true ) ;
return V_138 ;
}
static bool F_108 ( struct V_47 * V_142 )
{
struct V_1 * V_4 = V_142 -> V_3 . V_52 -> V_4 ;
struct V_143 * V_144 ;
struct V_98 * V_13 ;
struct V_17 * V_18 ;
struct V_145 * V_146 ;
int V_147 = 0 , V_148 = 0 ;
int V_34 ;
if ( F_107 ( V_4 ) )
return false ;
V_144 = V_142 -> V_3 . V_144 ;
F_109 (state, connector, connector_state, i) {
if ( V_146 -> V_52 != V_142 -> V_3 . V_52 )
continue;
V_13 = F_110 ( V_146 -> V_149 ) ;
V_148 += V_13 -> type == V_150 ;
V_147 ++ ;
}
return V_148 > 0 && V_148 == V_147 ;
}
bool F_111 ( struct V_98 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_67 * V_68 = & V_48 -> V_3 . V_68 ;
int V_151 = V_48 -> V_3 . V_68 . V_124 ;
int V_152 = V_151 * 3 / 2 ;
int V_153 ;
V_48 -> V_108 = V_2 -> V_108 ;
if ( V_48 -> V_108 )
V_48 -> V_118 = true ;
if ( V_2 -> V_154 ) {
V_48 -> V_72 =
V_48 -> V_108 &&
F_112 ( V_68 ) > 1 ;
} else {
V_48 -> V_72 =
V_2 -> V_72 ;
}
if ( V_68 -> V_94 & V_141 ) {
V_48 -> V_123 = 2 ;
V_151 *= 2 ;
V_152 *= 2 ;
}
if ( F_62 ( V_4 ) && ! F_4 ( V_4 ) )
V_48 -> V_155 = true ;
if ( V_48 -> V_108 && V_2 -> V_120 )
V_48 -> V_120 = true ;
if ( V_48 -> V_85 > 8 * 3 && V_48 -> V_108 &&
F_104 ( V_2 , V_152 , false ) == V_137 &&
F_108 ( V_48 ) ) {
F_51 ( L_11 ) ;
V_153 = 12 * 3 ;
V_48 -> V_122 = V_152 ;
} else {
F_51 ( L_12 ) ;
V_153 = 8 * 3 ;
V_48 -> V_122 = V_151 ;
}
if ( ! V_48 -> V_156 ) {
F_51 ( L_13 , V_153 ) ;
V_48 -> V_85 = V_153 ;
}
if ( F_104 ( V_2 , V_48 -> V_122 ,
false ) != V_137 ) {
F_51 ( L_14 ) ;
return false ;
}
V_68 -> V_157 = V_2 -> V_158 ;
return true ;
}
static void
F_113 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_108 = false ;
V_2 -> V_120 = false ;
V_2 -> V_71 = false ;
F_114 ( F_115 ( V_18 ) -> V_159 ) ;
F_115 ( V_18 ) -> V_159 = NULL ;
}
static bool
F_116 ( struct V_17 * V_18 , bool V_160 )
{
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_161 * V_161 = NULL ;
bool V_162 = false ;
if ( V_160 ) {
F_117 ( V_6 , V_163 ) ;
V_161 = F_118 ( V_18 ,
F_119 ( V_6 ,
V_2 -> V_164 ) ) ;
F_79 ( V_6 , V_163 ) ;
}
F_115 ( V_18 ) -> V_159 = V_161 ;
if ( V_161 && V_161 -> V_165 & V_166 ) {
V_2 -> V_71 =
F_120 ( V_161 ) ;
V_2 -> V_120 = F_121 ( V_161 ) ;
if ( V_2 -> V_167 != V_168 )
V_2 -> V_120 =
V_2 -> V_167 == V_169 ;
if ( V_2 -> V_167 != V_170 )
V_2 -> V_108 =
F_122 ( V_161 ) ;
V_162 = true ;
}
return V_162 ;
}
static enum V_171
F_123 ( struct V_17 * V_18 , bool V_160 )
{
enum V_171 V_138 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
bool V_172 = false ;
unsigned int V_173 ;
F_51 ( L_15 ,
V_18 -> V_3 . V_174 , V_18 -> V_175 ) ;
F_117 ( V_6 , V_163 ) ;
for ( V_173 = 0 ; ! V_172 && V_173 < 9 ; V_173 ++ ) {
if ( V_173 )
F_124 ( 10 ) ;
V_172 = F_125 ( V_6 ,
F_2 ( V_2 ) ) ;
}
if ( ! V_172 )
F_51 ( L_16 ) ;
F_113 ( V_18 ) ;
if ( F_116 ( V_18 , V_172 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_150 ;
V_138 = V_176 ;
} else
V_138 = V_177 ;
F_79 ( V_6 , V_163 ) ;
return V_138 ;
}
static void
F_126 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_51 ( L_15 ,
V_18 -> V_3 . V_174 , V_18 -> V_175 ) ;
F_113 ( V_18 ) ;
if ( V_18 -> V_138 != V_176 )
return;
F_116 ( V_18 , true ) ;
F_2 ( V_2 ) -> V_3 . type = V_150 ;
}
static int F_127 ( struct V_17 * V_18 )
{
struct V_161 * V_161 ;
V_161 = F_115 ( V_18 ) -> V_159 ;
if ( V_161 == NULL )
return 0 ;
return F_128 ( V_18 , V_161 ) ;
}
static bool
F_129 ( struct V_17 * V_18 )
{
bool V_120 = false ;
struct V_161 * V_161 ;
V_161 = F_115 ( V_18 ) -> V_159 ;
if ( V_161 && V_161 -> V_165 & V_166 )
V_120 = F_121 ( V_161 ) ;
return V_120 ;
}
static int
F_130 ( struct V_17 * V_18 ,
struct V_178 * V_179 ,
T_6 V_39 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_69 ;
V_69 = F_131 ( & V_18 -> V_3 , V_179 , V_39 ) ;
if ( V_69 )
return V_69 ;
if ( V_179 == V_6 -> V_180 ) {
enum V_181 V_34 = V_39 ;
bool V_120 ;
if ( V_34 == V_2 -> V_167 )
return 0 ;
V_2 -> V_167 = V_34 ;
if ( V_34 == V_168 )
V_120 = F_129 ( V_18 ) ;
else
V_120 = ( V_34 == V_169 ) ;
if ( V_34 == V_170 )
V_2 -> V_108 = 0 ;
V_2 -> V_120 = V_120 ;
goto V_182;
}
if ( V_179 == V_6 -> V_183 ) {
bool V_184 = V_2 -> V_154 ;
bool V_185 = V_2 -> V_72 ;
switch ( V_39 ) {
case V_186 :
V_2 -> V_154 = true ;
break;
case V_187 :
V_2 -> V_154 = false ;
V_2 -> V_72 = false ;
break;
case V_188 :
V_2 -> V_154 = false ;
V_2 -> V_72 = true ;
break;
default:
return - V_189 ;
}
if ( V_184 == V_2 -> V_154 &&
V_185 == V_2 -> V_72 )
return 0 ;
goto V_182;
}
if ( V_179 == V_18 -> V_4 -> V_81 . V_190 ) {
switch ( V_39 ) {
case V_191 :
V_2 -> V_158 = V_192 ;
break;
case V_193 :
V_2 -> V_158 = V_194 ;
break;
case V_195 :
V_2 -> V_158 = V_196 ;
break;
default:
return - V_189 ;
}
goto V_182;
}
return - V_189 ;
V_182:
if ( V_15 -> V_3 . V_3 . V_52 )
F_132 ( V_15 -> V_3 . V_3 . V_52 ) ;
return 0 ;
}
static void F_133 ( struct V_98 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
F_68 ( V_13 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
}
static void F_134 ( struct V_98 * V_13 )
{
struct V_14 * V_197 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_197 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_198 V_50 = F_135 ( V_197 ) ;
int V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_136 ( & V_6 -> V_199 ) ;
V_39 = F_137 ( V_6 , V_54 , F_138 ( V_50 ) ) ;
V_39 = 0 ;
if ( V_54 )
V_39 |= ( 1 << 21 ) ;
else
V_39 &= ~ ( 1 << 21 ) ;
V_39 |= 0x001000c4 ;
F_139 ( V_6 , V_54 , F_140 ( V_50 ) , V_39 ) ;
F_139 ( V_6 , V_54 , F_141 ( V_50 ) , 0 ) ;
F_139 ( V_6 , V_54 , F_142 ( V_50 ) , 0x2b245f5f ) ;
F_139 ( V_6 , V_54 , F_143 ( V_50 ) , 0x5578b83a ) ;
F_139 ( V_6 , V_54 , F_144 ( V_50 ) , 0x0c782040 ) ;
F_139 ( V_6 , V_54 , F_145 ( V_50 ) , 0x2b247878 ) ;
F_139 ( V_6 , V_54 , F_146 ( V_50 ) , 0x00030000 ) ;
F_139 ( V_6 , V_54 , F_147 ( V_50 ) , 0x00002000 ) ;
F_139 ( V_6 , V_54 , F_141 ( V_50 ) , V_200 ) ;
F_139 ( V_6 , V_54 , F_148 ( V_50 ) , 0x00760018 ) ;
F_139 ( V_6 , V_54 , F_149 ( V_50 ) , 0x00400888 ) ;
F_150 ( & V_6 -> V_199 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
F_86 ( V_13 ) ;
F_151 ( V_6 , V_197 , 0x0 ) ;
}
static void F_152 ( struct V_98 * V_13 )
{
struct V_14 * V_197 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_198 V_50 = F_135 ( V_197 ) ;
int V_54 = V_51 -> V_54 ;
F_68 ( V_13 ) ;
F_136 ( & V_6 -> V_199 ) ;
F_139 ( V_6 , V_54 , F_153 ( V_50 ) ,
V_201 |
V_202 ) ;
F_139 ( V_6 , V_54 , F_154 ( V_50 ) ,
V_203 |
V_204 |
( 1 << V_205 ) |
V_206 ) ;
F_139 ( V_6 , V_54 , F_155 ( V_50 ) , 0x00750f00 ) ;
F_139 ( V_6 , V_54 , F_156 ( V_50 ) , 0x00001500 ) ;
F_139 ( V_6 , V_54 , F_157 ( V_50 ) , 0x40400000 ) ;
F_139 ( V_6 , V_54 , F_147 ( V_50 ) , 0x00002000 ) ;
F_139 ( V_6 , V_54 , F_141 ( V_50 ) , V_200 ) ;
F_150 ( & V_6 -> V_199 ) ;
}
static void F_158 ( struct V_98 * V_13 ,
bool V_207 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_198 V_208 = F_135 ( F_25 ( & V_13 -> V_3 ) ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_1 V_39 ;
V_39 = F_137 ( V_6 , V_54 , F_159 ( V_208 ) ) ;
if ( V_207 )
V_39 &= ~ ( V_201 | V_202 ) ;
else
V_39 |= V_201 | V_202 ;
F_139 ( V_6 , V_54 , F_159 ( V_208 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_209 > 2 ) {
V_39 = F_137 ( V_6 , V_54 , F_160 ( V_208 ) ) ;
if ( V_207 )
V_39 &= ~ ( V_201 | V_202 ) ;
else
V_39 |= V_201 | V_202 ;
F_139 ( V_6 , V_54 , F_160 ( V_208 ) , V_39 ) ;
}
V_39 = F_137 ( V_6 , V_54 , F_161 ( V_208 ) ) ;
V_39 |= V_210 ;
if ( V_207 )
V_39 &= ~ V_206 ;
else
V_39 |= V_206 ;
F_139 ( V_6 , V_54 , F_161 ( V_208 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_209 > 2 ) {
V_39 = F_137 ( V_6 , V_54 , F_162 ( V_208 ) ) ;
V_39 |= V_210 ;
if ( V_207 )
V_39 &= ~ V_206 ;
else
V_39 |= V_206 ;
F_139 ( V_6 , V_54 , F_162 ( V_208 ) , V_39 ) ;
}
}
static void F_163 ( struct V_98 * V_13 )
{
struct V_14 * V_197 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_198 V_208 = F_135 ( V_197 ) ;
enum V_54 V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_68 ( V_13 ) ;
if ( V_208 == V_211 && V_54 == V_127 )
V_197 -> V_212 =
! F_164 ( V_6 , V_213 , V_214 , true ) ;
F_165 ( V_13 , true , 0x0 ) ;
F_136 ( & V_6 -> V_199 ) ;
F_158 ( V_13 , true ) ;
if ( V_54 != V_127 ) {
V_39 = F_137 ( V_6 , V_54 , V_215 ) ;
V_39 &= ~ ( V_216 | V_217 ) ;
if ( V_208 == V_211 )
V_39 |= V_218 ;
if ( V_208 == V_214 )
V_39 |= V_219 ;
F_139 ( V_6 , V_54 , V_215 , V_39 ) ;
} else {
V_39 = F_137 ( V_6 , V_54 , V_220 ) ;
V_39 &= ~ ( V_221 | V_222 ) ;
if ( V_208 == V_211 )
V_39 |= V_223 ;
if ( V_208 == V_214 )
V_39 |= V_224 ;
F_139 ( V_6 , V_54 , V_220 , V_39 ) ;
}
V_39 = F_137 ( V_6 , V_54 , F_138 ( V_208 ) ) ;
V_39 |= V_225 ;
if ( V_54 != V_127 )
V_39 &= ~ V_226 ;
else
V_39 |= V_226 ;
F_139 ( V_6 , V_54 , F_138 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_166 ( V_208 ) ) ;
V_39 |= V_225 ;
if ( V_54 != V_127 )
V_39 &= ~ V_226 ;
else
V_39 |= V_226 ;
F_139 ( V_6 , V_54 , F_166 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_167 ( V_208 ) ) ;
if ( V_54 != V_127 )
V_39 &= ~ V_227 ;
else
V_39 |= V_227 ;
F_139 ( V_6 , V_54 , F_167 ( V_208 ) , V_39 ) ;
F_150 ( & V_6 -> V_199 ) ;
}
static void F_168 ( struct V_98 * V_13 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_54 V_54 = F_28 ( V_13 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 ;
F_136 ( & V_6 -> V_199 ) ;
if ( V_54 != V_127 ) {
V_39 = F_137 ( V_6 , V_54 , V_215 ) ;
V_39 &= ~ ( V_216 | V_217 ) ;
F_139 ( V_6 , V_54 , V_215 , V_39 ) ;
} else {
V_39 = F_137 ( V_6 , V_54 , V_220 ) ;
V_39 &= ~ ( V_221 | V_222 ) ;
F_139 ( V_6 , V_54 , V_220 , V_39 ) ;
}
F_150 ( & V_6 -> V_199 ) ;
F_165 ( V_13 , false , 0x0 ) ;
}
static void F_169 ( struct V_98 * V_13 )
{
struct V_14 * V_197 = F_25 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_198 V_50 = F_135 ( V_197 ) ;
int V_54 = V_51 -> V_54 ;
F_136 ( & V_6 -> V_199 ) ;
F_139 ( V_6 , V_54 , F_153 ( V_50 ) , 0x00000000 ) ;
F_139 ( V_6 , V_54 , F_154 ( V_50 ) , 0x00e00060 ) ;
F_150 ( & V_6 -> V_199 ) ;
}
static void F_170 ( struct V_98 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_136 ( & V_6 -> V_199 ) ;
F_158 ( V_13 , true ) ;
F_150 ( & V_6 -> V_199 ) ;
}
static void F_171 ( struct V_98 * V_13 )
{
struct V_14 * V_197 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_197 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_198 V_208 = F_135 ( V_197 ) ;
int V_54 = V_51 -> V_54 ;
int V_38 , V_34 , V_228 ;
T_2 V_39 ;
F_136 ( & V_6 -> V_199 ) ;
V_39 = F_137 ( V_6 , V_54 , F_172 ( V_208 ) ) ;
V_39 &= ~ V_229 ;
F_139 ( V_6 , V_54 , F_172 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_173 ( V_208 ) ) ;
V_39 &= ~ V_229 ;
F_139 ( V_6 , V_54 , F_173 ( V_208 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = ( V_34 == 1 ) ? 0x0 : 0x1 ;
F_139 ( V_6 , V_54 , F_174 ( V_208 , V_34 ) ,
V_38 << V_230 ) ;
}
if ( V_51 -> V_57 -> V_122 > 270000 )
V_228 = 0x18 ;
else if ( V_51 -> V_57 -> V_122 > 135000 )
V_228 = 0xd ;
else if ( V_51 -> V_57 -> V_122 > 67500 )
V_228 = 0x7 ;
else if ( V_51 -> V_57 -> V_122 > 33750 )
V_228 = 0x4 ;
else
V_228 = 0x2 ;
V_39 = F_137 ( V_6 , V_54 , F_172 ( V_208 ) ) ;
V_39 |= F_175 ( 0x1f ) ;
F_139 ( V_6 , V_54 , F_172 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_173 ( V_208 ) ) ;
V_39 |= F_175 ( 0x1f ) ;
F_139 ( V_6 , V_54 , F_173 ( V_208 ) , V_39 ) ;
F_139 ( V_6 , V_54 , F_176 ( V_208 ) ,
F_177 ( V_228 ) |
V_231 |
F_178 ( 0x1f ) |
F_179 ( 6 ) |
F_180 ( 0 ) ) ;
F_139 ( V_6 , V_54 , F_181 ( V_208 ) ,
F_177 ( V_228 ) |
V_231 |
F_178 ( 0x1f ) |
F_179 ( 7 ) |
F_180 ( 5 ) ) ;
F_158 ( V_13 , false ) ;
V_39 = F_137 ( V_6 , V_54 , F_182 ( V_208 ) ) ;
V_39 &= ~ ( V_232 | V_233 ) ;
V_39 &= ~ ( V_234 | V_235 ) ;
V_39 |= V_236 | V_237 ;
F_139 ( V_6 , V_54 , F_182 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_183 ( V_208 ) ) ;
V_39 &= ~ ( V_232 | V_233 ) ;
V_39 &= ~ ( V_234 | V_235 ) ;
V_39 |= V_236 | V_237 ;
F_139 ( V_6 , V_54 , F_183 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_184 ( V_208 ) ) ;
V_39 &= ~ ( V_238 | V_239 ) ;
V_39 |= V_240 | V_241 ;
F_139 ( V_6 , V_54 , F_184 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_185 ( V_208 ) ) ;
V_39 &= ~ ( V_238 | V_239 ) ;
V_39 |= V_240 | V_241 ;
F_139 ( V_6 , V_54 , F_185 ( V_208 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_137 ( V_6 , V_54 , F_186 ( V_208 , V_34 ) ) ;
V_39 &= ~ V_242 ;
V_39 |= 128 << V_243 ;
F_139 ( V_6 , V_54 , F_186 ( V_208 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_137 ( V_6 , V_54 , F_187 ( V_208 , V_34 ) ) ;
V_39 &= ~ V_244 ;
V_39 |= 102 << V_245 ;
V_39 &= ~ ( 0xff << V_246 ) ;
V_39 |= 0x9a << V_246 ;
F_139 ( V_6 , V_54 , F_187 ( V_208 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_137 ( V_6 , V_54 , F_188 ( V_208 , V_34 ) ) ;
V_39 &= ~ V_247 ;
F_139 ( V_6 , V_54 , F_188 ( V_208 , V_34 ) , V_39 ) ;
}
V_39 = F_137 ( V_6 , V_54 , F_182 ( V_208 ) ) ;
V_39 |= V_232 | V_233 ;
F_139 ( V_6 , V_54 , F_182 ( V_208 ) , V_39 ) ;
V_39 = F_137 ( V_6 , V_54 , F_183 ( V_208 ) ) ;
V_39 |= V_232 | V_233 ;
F_139 ( V_6 , V_54 , F_183 ( V_208 ) , V_39 ) ;
F_150 ( & V_6 -> V_199 ) ;
V_2 -> V_130 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_108 ,
V_68 ) ;
F_86 ( V_13 ) ;
F_151 ( V_6 , V_197 , 0x0 ) ;
if ( V_197 -> V_212 ) {
F_164 ( V_6 , V_213 , V_214 , false ) ;
V_197 -> V_212 = false ;
}
}
static void F_189 ( struct V_17 * V_18 )
{
F_114 ( F_115 ( V_18 ) -> V_159 ) ;
F_190 ( V_18 ) ;
F_114 ( V_18 ) ;
}
static void
F_191 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_192 ( V_18 ) ;
F_193 ( V_18 ) ;
V_2 -> V_154 = true ;
F_194 ( V_18 ) ;
V_2 -> V_158 = V_192 ;
}
void F_195 ( struct V_14 * V_15 ,
struct V_248 * V_248 )
{
struct V_17 * V_18 = & V_248 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_98 * V_98 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_98 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_50 V_50 = V_15 -> V_50 ;
T_5 V_249 ;
F_196 ( V_4 , V_18 , & V_250 ,
V_251 ) ;
F_197 ( V_18 , & V_252 ) ;
V_18 -> V_253 = 1 ;
V_18 -> V_254 = 0 ;
V_18 -> V_255 = 1 ;
switch ( V_50 ) {
case V_256 :
if ( F_105 ( V_6 ) )
V_2 -> V_164 = V_257 ;
else
V_2 -> V_164 = V_258 ;
if ( F_198 ( V_6 , 0 , V_259 ) )
V_98 -> V_260 = V_261 ;
else
V_98 -> V_260 = V_262 ;
break;
case V_263 :
if ( F_105 ( V_6 ) )
V_2 -> V_164 = V_264 ;
else
V_2 -> V_164 = V_265 ;
V_98 -> V_260 = V_266 ;
break;
case V_267 :
if ( F_53 ( F_105 ( V_6 ) ) )
V_2 -> V_164 = V_268 ;
else if ( F_60 ( V_6 ) )
V_2 -> V_164 = V_269 ;
else
V_2 -> V_164 = V_270 ;
V_98 -> V_260 = V_271 ;
break;
case V_272 :
V_249 =
V_6 -> V_273 . V_274 [ V_272 ] . V_249 ;
switch ( V_249 ) {
case V_275 :
V_2 -> V_164 = V_258 ;
break;
case V_276 :
V_2 -> V_164 = V_265 ;
break;
case V_277 :
V_2 -> V_164 = V_270 ;
break;
default:
F_12 ( V_249 ) ;
}
V_98 -> V_260 = V_278 ;
break;
case V_279 :
V_98 -> V_260 = V_261 ;
default:
F_199 () ;
}
if ( F_59 ( V_4 ) || F_60 ( V_4 ) ) {
V_2 -> V_65 = F_34 ;
V_2 -> V_130 = F_66 ;
V_2 -> V_117 = F_37 ;
} else if ( F_101 ( V_4 ) ) {
V_2 -> V_65 = F_19 ;
V_2 -> V_130 = F_50 ;
V_2 -> V_117 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_65 = F_38 ;
V_2 -> V_130 = F_67 ;
V_2 -> V_117 = F_40 ;
} else if ( F_92 ( V_4 ) ) {
V_2 -> V_65 = F_27 ;
V_2 -> V_130 = F_64 ;
V_2 -> V_117 = F_31 ;
} else {
V_2 -> V_65 = F_32 ;
V_2 -> V_130 = F_65 ;
V_2 -> V_117 = F_33 ;
}
if ( F_4 ( V_4 ) )
V_248 -> V_280 = V_281 ;
else
V_248 -> V_280 = V_282 ;
V_248 -> V_283 = V_284 ;
F_191 ( V_2 , V_18 ) ;
F_200 ( V_248 , V_98 ) ;
F_201 ( V_18 ) ;
V_2 -> V_285 = V_248 ;
if ( F_101 ( V_4 ) && ! F_202 ( V_4 ) ) {
T_2 V_125 = F_6 ( V_286 ) ;
F_20 ( V_286 , ( V_125 & ~ 0xf ) | 0xd ) ;
}
}
void F_203 ( struct V_1 * V_4 ,
T_3 V_11 , enum V_50 V_50 )
{
struct V_14 * V_15 ;
struct V_98 * V_98 ;
struct V_248 * V_248 ;
V_15 = F_204 ( sizeof( * V_15 ) , V_287 ) ;
if ( ! V_15 )
return;
V_248 = F_205 () ;
if ( ! V_248 ) {
F_114 ( V_15 ) ;
return;
}
V_98 = & V_15 -> V_3 ;
F_206 ( V_4 , & V_98 -> V_3 , & V_288 ,
V_289 , NULL ) ;
V_98 -> V_290 = F_111 ;
if ( F_62 ( V_4 ) ) {
V_98 -> V_291 = F_98 ;
V_98 -> V_292 = F_99 ;
} else {
V_98 -> V_291 = F_96 ;
}
V_98 -> V_280 = F_73 ;
V_98 -> V_293 = F_80 ;
if ( F_60 ( V_4 ) ) {
V_98 -> V_294 = F_163 ;
V_98 -> V_295 = F_171 ;
V_98 -> V_80 = F_90 ;
V_98 -> V_292 = F_170 ;
V_98 -> V_296 = F_168 ;
} else if ( F_59 ( V_4 ) ) {
V_98 -> V_294 = F_152 ;
V_98 -> V_295 = F_134 ;
V_98 -> V_80 = F_90 ;
V_98 -> V_292 = F_169 ;
} else {
V_98 -> V_295 = F_133 ;
if ( F_69 ( V_4 ) )
V_98 -> V_80 = F_88 ;
else if ( F_92 ( V_4 ) )
V_98 -> V_80 = F_87 ;
else
V_98 -> V_80 = F_86 ;
}
V_98 -> type = V_150 ;
if ( F_60 ( V_4 ) ) {
if ( V_50 == V_267 )
V_98 -> V_297 = 1 << 2 ;
else
V_98 -> V_297 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_98 -> V_297 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_98 -> V_298 = 1 << V_299 ;
if ( F_101 ( V_4 ) )
V_98 -> V_298 |= 1 << V_150 ;
V_15 -> V_50 = V_50 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_300 . V_301 = V_35 ;
F_195 ( V_15 , V_248 ) ;
}
