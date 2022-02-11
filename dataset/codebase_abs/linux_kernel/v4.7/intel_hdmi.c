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
else if ( F_62 ( V_6 ) )
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
void F_68 ( struct V_2 * V_16 , bool V_80 )
{
struct V_5 * V_6 = F_24 ( F_1 ( V_16 ) ) ;
struct V_98 * V_99 =
F_69 ( V_6 , V_16 -> V_100 ) ;
if ( V_16 -> V_101 . type < V_102 )
return;
F_51 ( L_10 ,
V_80 ? L_11 : L_12 ) ;
F_70 ( V_16 -> V_101 . type ,
V_99 , V_80 ) ;
}
static void F_71 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
const struct V_67 * V_68 = & V_52 -> V_57 -> V_3 . V_68 ;
T_2 V_104 ;
F_68 ( V_2 , true ) ;
V_104 = V_105 ;
if ( ! F_62 ( V_4 ) && V_52 -> V_57 -> V_72 )
V_104 |= V_106 ;
if ( V_68 -> V_94 & V_107 )
V_104 |= V_108 ;
if ( V_68 -> V_94 & V_109 )
V_104 |= V_110 ;
if ( V_52 -> V_57 -> V_85 > 24 )
V_104 |= V_111 ;
else
V_104 |= V_112 ;
if ( V_52 -> V_57 -> V_113 )
V_104 |= V_114 ;
if ( F_72 ( V_4 ) )
V_104 |= F_73 ( V_52 -> V_54 ) ;
else if ( F_60 ( V_4 ) )
V_104 |= F_74 ( V_52 -> V_54 ) ;
else
V_104 |= F_75 ( V_52 -> V_54 ) ;
F_20 ( V_2 -> V_11 , V_104 ) ;
F_22 ( V_2 -> V_11 ) ;
}
static bool F_76 ( struct V_103 * V_13 ,
enum V_54 * V_54 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_115 V_116 ;
T_2 V_117 ;
bool V_69 ;
V_116 = F_77 ( V_13 ) ;
if ( ! F_78 ( V_6 , V_116 ) )
return false ;
V_69 = false ;
V_117 = F_6 ( V_2 -> V_11 ) ;
if ( ! ( V_117 & V_10 ) )
goto V_118;
if ( F_72 ( V_4 ) )
* V_54 = F_79 ( V_117 ) ;
else if ( F_60 ( V_4 ) )
* V_54 = F_80 ( V_117 ) ;
else
* V_54 = F_81 ( V_117 ) ;
V_69 = true ;
V_118:
F_82 ( V_6 , V_116 ) ;
return V_69 ;
}
static void F_83 ( struct V_103 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_117 , V_94 = 0 ;
int V_119 ;
V_117 = F_6 ( V_2 -> V_11 ) ;
if ( V_117 & V_110 )
V_94 |= V_109 ;
else
V_94 |= V_120 ;
if ( V_117 & V_108 )
V_94 |= V_107 ;
else
V_94 |= V_121 ;
if ( V_117 & V_114 )
V_48 -> V_113 = true ;
if ( V_2 -> V_122 ( & V_13 -> V_3 , V_48 ) )
V_48 -> V_123 = true ;
if ( V_117 & V_124 )
V_48 -> V_125 = true ;
if ( ! F_62 ( V_4 ) &&
V_117 & V_106 )
V_48 -> V_72 = true ;
V_48 -> V_3 . V_68 . V_94 |= V_94 ;
if ( ( V_117 & V_126 ) == V_111 )
V_119 = V_48 -> V_127 * 2 / 3 ;
else
V_119 = V_48 -> V_127 ;
if ( V_48 -> V_128 )
V_119 /= V_48 -> V_128 ;
V_48 -> V_3 . V_68 . V_129 = V_119 ;
V_48 -> V_130 = 4 ;
}
static void F_84 ( struct V_103 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
F_53 ( ! V_52 -> V_57 -> V_113 ) ;
F_85 ( L_13 ,
F_86 ( V_52 -> V_54 ) ) ;
F_87 ( V_13 ) ;
}
static void F_88 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_131 ;
V_131 = F_6 ( V_2 -> V_11 ) ;
V_131 |= V_10 ;
if ( V_52 -> V_57 -> V_125 )
V_131 |= V_124 ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_125 )
F_84 ( V_13 ) ;
}
static void F_89 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
T_2 V_131 ;
V_131 = F_6 ( V_2 -> V_11 ) ;
V_131 |= V_10 ;
if ( V_52 -> V_57 -> V_125 )
V_131 |= V_124 ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 &&
V_52 -> V_57 -> V_128 > 1 ) {
F_20 ( V_2 -> V_11 , V_131 & ~ V_10 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
}
if ( V_52 -> V_57 -> V_125 )
F_84 ( V_13 ) ;
}
static void F_90 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_2 V_131 ;
V_131 = F_6 ( V_2 -> V_11 ) ;
V_131 |= V_10 ;
if ( V_52 -> V_57 -> V_125 )
V_131 |= V_124 ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
F_20 ( F_91 ( V_54 ) ,
F_6 ( F_91 ( V_54 ) ) |
V_132 ) ;
V_131 &= ~ V_126 ;
V_131 |= V_112 ;
}
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( V_52 -> V_57 -> V_85 > 24 ) {
V_131 &= ~ V_126 ;
V_131 |= V_111 ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( F_91 ( V_54 ) ,
F_6 ( F_91 ( V_54 ) ) &
~ V_132 ) ;
}
if ( V_52 -> V_57 -> V_125 )
F_84 ( V_13 ) ;
}
static void F_92 ( struct V_103 * V_13 )
{
}
static void F_93 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
T_2 V_131 ;
V_131 = F_6 ( V_2 -> V_11 ) ;
V_131 &= ~ ( V_10 | V_124 ) ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
if ( F_94 ( V_4 ) && V_52 -> V_54 == V_133 ) {
F_95 ( V_6 , V_134 , false ) ;
F_96 ( V_6 , V_134 , false ) ;
V_131 &= ~ V_135 ;
V_131 |= V_10 ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
V_131 &= ~ V_10 ;
F_20 ( V_2 -> V_11 , V_131 ) ;
F_22 ( V_2 -> V_11 ) ;
F_97 ( V_6 -> V_4 , V_134 ) ;
F_95 ( V_6 , V_134 , true ) ;
F_96 ( V_6 , V_134 , true ) ;
}
V_2 -> V_136 ( & V_13 -> V_3 , false , NULL ) ;
F_68 ( V_2 , false ) ;
}
static void F_98 ( struct V_103 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_125 )
F_99 ( V_13 ) ;
F_93 ( V_13 ) ;
}
static void F_100 ( struct V_103 * V_13 )
{
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
if ( V_52 -> V_57 -> V_125 )
F_99 ( V_13 ) ;
}
static void F_101 ( struct V_103 * V_13 )
{
F_93 ( V_13 ) ;
}
static int F_102 ( struct V_5 * V_6 )
{
if ( F_103 ( V_6 ) )
return 165000 ;
else if ( F_104 ( V_6 ) || F_105 ( V_6 ) -> V_137 >= 8 )
return 300000 ;
else
return 225000 ;
}
static int F_106 ( struct V_2 * V_16 ,
bool V_138 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
int V_139 = F_102 ( F_24 ( V_4 ) ) ;
if ( V_138 ) {
if ( V_16 -> V_101 . V_139 )
V_139 = F_107 ( V_139 ,
V_16 -> V_101 . V_139 ) ;
if ( ! V_16 -> V_113 )
V_139 = F_107 ( V_139 , 165000 ) ;
}
return V_139 ;
}
static enum V_140
F_108 ( struct V_2 * V_16 ,
int clock , bool V_138 )
{
struct V_1 * V_4 = F_1 ( V_16 ) ;
if ( clock < 25000 )
return V_141 ;
if ( clock > F_106 ( V_16 , V_138 ) )
return V_142 ;
if ( F_109 ( V_4 ) && clock > 223333 && clock < 240000 )
return V_143 ;
if ( F_60 ( V_4 ) && clock > 216000 && clock < 240000 )
return V_143 ;
return V_144 ;
}
static enum V_140
F_110 ( struct V_17 * V_18 ,
struct V_67 * V_86 )
{
struct V_2 * V_16 = F_9 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_16 ) ;
enum V_140 V_145 ;
int clock ;
int V_146 = F_24 ( V_18 -> V_4 ) -> V_147 ;
if ( V_86 -> V_94 & V_148 )
return V_149 ;
clock = V_86 -> clock ;
if ( ( V_86 -> V_94 & V_150 ) == V_151 )
clock *= 2 ;
if ( clock > V_146 )
return V_142 ;
if ( V_86 -> V_94 & V_152 )
clock *= 2 ;
V_145 = F_108 ( V_16 , clock , true ) ;
if ( ! F_111 ( V_4 ) && V_145 != V_144 )
V_145 = F_108 ( V_16 , clock * 3 / 2 , true ) ;
return V_145 ;
}
static bool F_112 ( struct V_47 * V_153 )
{
struct V_1 * V_4 = V_153 -> V_3 . V_52 -> V_4 ;
struct V_154 * V_155 ;
struct V_103 * V_13 ;
struct V_17 * V_18 ;
struct V_156 * V_157 ;
int V_158 = 0 , V_159 = 0 ;
int V_34 ;
if ( F_111 ( V_4 ) )
return false ;
V_155 = V_153 -> V_3 . V_155 ;
F_113 (state, connector, connector_state, i) {
if ( V_157 -> V_52 != V_153 -> V_3 . V_52 )
continue;
V_13 = F_114 ( V_157 -> V_160 ) ;
V_159 += V_13 -> type == V_161 ;
V_158 ++ ;
}
return V_159 > 0 && V_159 == V_158 ;
}
bool F_115 ( struct V_103 * V_13 ,
struct V_47 * V_48 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_67 * V_68 = & V_48 -> V_3 . V_68 ;
int V_162 = V_48 -> V_3 . V_68 . V_129 ;
int V_163 = V_162 * 3 / 2 ;
int V_164 ;
V_48 -> V_113 = V_2 -> V_113 ;
if ( V_48 -> V_113 )
V_48 -> V_123 = true ;
if ( V_2 -> V_165 ) {
V_48 -> V_72 =
V_48 -> V_113 &&
F_116 ( V_68 ) > 1 ;
} else {
V_48 -> V_72 =
V_2 -> V_72 ;
}
if ( V_68 -> V_94 & V_152 ) {
V_48 -> V_128 = 2 ;
V_162 *= 2 ;
V_163 *= 2 ;
}
if ( F_62 ( V_4 ) && ! F_4 ( V_4 ) )
V_48 -> V_166 = true ;
if ( V_48 -> V_113 && V_2 -> V_125 )
V_48 -> V_125 = true ;
if ( V_48 -> V_85 > 8 * 3 && V_48 -> V_113 &&
F_108 ( V_2 , V_163 , true ) == V_144 &&
F_112 ( V_48 ) ) {
F_51 ( L_14 ) ;
V_164 = 12 * 3 ;
V_48 -> V_127 = V_163 ;
} else {
F_51 ( L_15 ) ;
V_164 = 8 * 3 ;
V_48 -> V_127 = V_162 ;
}
if ( ! V_48 -> V_167 ) {
F_51 ( L_16 , V_164 ) ;
V_48 -> V_85 = V_164 ;
}
if ( F_108 ( V_2 , V_48 -> V_127 ,
false ) != V_144 ) {
F_51 ( L_17 ) ;
return false ;
}
V_68 -> V_168 = V_2 -> V_169 ;
V_48 -> V_130 = 4 ;
return true ;
}
static void
F_117 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
V_2 -> V_113 = false ;
V_2 -> V_125 = false ;
V_2 -> V_71 = false ;
V_2 -> V_101 . type = V_170 ;
V_2 -> V_101 . V_139 = 0 ;
F_118 ( F_119 ( V_18 ) -> V_171 ) ;
F_119 ( V_18 ) -> V_171 = NULL ;
}
static void
F_120 ( struct V_17 * V_18 , bool V_172 )
{
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
struct V_2 * V_16 = F_9 ( V_18 ) ;
enum V_50 V_50 = F_2 ( V_16 ) -> V_50 ;
struct V_98 * V_99 =
F_69 ( V_6 , V_16 -> V_100 ) ;
enum V_173 type = F_121 ( V_99 ) ;
if ( type == V_174 ) {
if ( V_172 &&
F_122 ( V_6 , V_50 ) ) {
F_51 ( L_18 ) ;
type = V_175 ;
} else {
type = V_170 ;
}
}
if ( type == V_170 )
return;
V_16 -> V_101 . type = type ;
V_16 -> V_101 . V_139 =
F_123 ( type , V_99 ) ;
F_51 ( L_19 ,
F_124 ( type ) ,
V_16 -> V_101 . V_139 ) ;
}
static bool
F_125 ( struct V_17 * V_18 , bool V_176 )
{
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_177 * V_177 = NULL ;
bool V_178 = false ;
if ( V_176 ) {
F_126 ( V_6 , V_179 ) ;
V_177 = F_127 ( V_18 ,
F_69 ( V_6 ,
V_2 -> V_100 ) ) ;
F_120 ( V_18 , V_177 != NULL ) ;
F_82 ( V_6 , V_179 ) ;
}
F_119 ( V_18 ) -> V_171 = V_177 ;
if ( V_177 && V_177 -> V_180 & V_181 ) {
V_2 -> V_71 =
F_128 ( V_177 ) ;
V_2 -> V_125 = F_129 ( V_177 ) ;
if ( V_2 -> V_182 != V_183 )
V_2 -> V_125 =
V_2 -> V_182 == V_184 ;
if ( V_2 -> V_182 != V_185 )
V_2 -> V_113 =
F_130 ( V_177 ) ;
V_178 = true ;
}
return V_178 ;
}
static enum V_186
F_131 ( struct V_17 * V_18 , bool V_176 )
{
enum V_186 V_145 ;
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_5 * V_6 = F_24 ( V_18 -> V_4 ) ;
bool V_187 = false ;
unsigned int V_188 ;
F_51 ( L_20 ,
V_18 -> V_3 . V_189 , V_18 -> V_190 ) ;
F_126 ( V_6 , V_179 ) ;
for ( V_188 = 0 ; ! V_187 && V_188 < 9 ; V_188 ++ ) {
if ( V_188 )
F_132 ( 10 ) ;
V_187 = F_133 ( V_6 ,
F_2 ( V_2 ) ) ;
}
if ( ! V_187 ) {
F_51 ( L_21 ) ;
if ( F_105 ( V_6 ) -> V_137 < 7 || F_134 ( V_6 ) )
V_187 = true ;
}
F_117 ( V_18 ) ;
if ( F_125 ( V_18 , V_187 ) ) {
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_2 ( V_2 ) -> V_3 . type = V_161 ;
V_145 = V_191 ;
} else
V_145 = V_192 ;
F_82 ( V_6 , V_179 ) ;
return V_145 ;
}
static void
F_135 ( struct V_17 * V_18 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
F_51 ( L_20 ,
V_18 -> V_3 . V_189 , V_18 -> V_190 ) ;
F_117 ( V_18 ) ;
if ( V_18 -> V_145 != V_191 )
return;
F_125 ( V_18 , true ) ;
F_2 ( V_2 ) -> V_3 . type = V_161 ;
}
static int F_136 ( struct V_17 * V_18 )
{
struct V_177 * V_177 ;
V_177 = F_119 ( V_18 ) -> V_171 ;
if ( V_177 == NULL )
return 0 ;
return F_137 ( V_18 , V_177 ) ;
}
static bool
F_138 ( struct V_17 * V_18 )
{
bool V_125 = false ;
struct V_177 * V_177 ;
V_177 = F_119 ( V_18 ) -> V_171 ;
if ( V_177 && V_177 -> V_180 & V_181 )
V_125 = F_129 ( V_177 ) ;
return V_125 ;
}
static int
F_139 ( struct V_17 * V_18 ,
struct V_193 * V_194 ,
T_6 V_39 )
{
struct V_2 * V_2 = F_9 ( V_18 ) ;
struct V_14 * V_15 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = V_18 -> V_4 -> V_7 ;
int V_69 ;
V_69 = F_140 ( & V_18 -> V_3 , V_194 , V_39 ) ;
if ( V_69 )
return V_69 ;
if ( V_194 == V_6 -> V_195 ) {
enum V_196 V_34 = V_39 ;
bool V_125 ;
if ( V_34 == V_2 -> V_182 )
return 0 ;
V_2 -> V_182 = V_34 ;
if ( V_34 == V_183 )
V_125 = F_138 ( V_18 ) ;
else
V_125 = ( V_34 == V_184 ) ;
if ( V_34 == V_185 )
V_2 -> V_113 = 0 ;
V_2 -> V_125 = V_125 ;
goto V_197;
}
if ( V_194 == V_6 -> V_198 ) {
bool V_199 = V_2 -> V_165 ;
bool V_200 = V_2 -> V_72 ;
switch ( V_39 ) {
case V_201 :
V_2 -> V_165 = true ;
break;
case V_202 :
V_2 -> V_165 = false ;
V_2 -> V_72 = false ;
break;
case V_203 :
V_2 -> V_165 = false ;
V_2 -> V_72 = true ;
break;
default:
return - V_204 ;
}
if ( V_199 == V_2 -> V_165 &&
V_200 == V_2 -> V_72 )
return 0 ;
goto V_197;
}
if ( V_194 == V_18 -> V_4 -> V_81 . V_205 ) {
switch ( V_39 ) {
case V_206 :
V_2 -> V_169 = V_207 ;
break;
case V_208 :
V_2 -> V_169 = V_209 ;
break;
case V_210 :
V_2 -> V_169 = V_211 ;
break;
default:
return - V_204 ;
}
goto V_197;
}
return - V_204 ;
V_197:
if ( V_15 -> V_3 . V_3 . V_52 )
F_141 ( V_15 -> V_3 . V_3 . V_52 ) ;
return 0 ;
}
static void F_142 ( struct V_103 * V_13 )
{
struct V_2 * V_2 = F_7 ( & V_13 -> V_3 ) ;
struct V_51 * V_51 = F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
F_71 ( V_13 ) ;
V_2 -> V_136 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_113 ,
V_68 ) ;
}
static void F_143 ( struct V_103 * V_13 )
{
struct V_14 * V_212 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_212 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_213 V_50 = F_144 ( V_212 ) ;
int V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_145 ( & V_6 -> V_214 ) ;
V_39 = F_146 ( V_6 , V_54 , F_147 ( V_50 ) ) ;
V_39 = 0 ;
if ( V_54 )
V_39 |= ( 1 << 21 ) ;
else
V_39 &= ~ ( 1 << 21 ) ;
V_39 |= 0x001000c4 ;
F_148 ( V_6 , V_54 , F_149 ( V_50 ) , V_39 ) ;
F_148 ( V_6 , V_54 , F_150 ( V_50 ) , 0 ) ;
F_148 ( V_6 , V_54 , F_151 ( V_50 ) , 0x2b245f5f ) ;
F_148 ( V_6 , V_54 , F_152 ( V_50 ) , 0x5578b83a ) ;
F_148 ( V_6 , V_54 , F_153 ( V_50 ) , 0x0c782040 ) ;
F_148 ( V_6 , V_54 , F_154 ( V_50 ) , 0x2b247878 ) ;
F_148 ( V_6 , V_54 , F_155 ( V_50 ) , 0x00030000 ) ;
F_148 ( V_6 , V_54 , F_156 ( V_50 ) , 0x00002000 ) ;
F_148 ( V_6 , V_54 , F_150 ( V_50 ) , V_215 ) ;
F_148 ( V_6 , V_54 , F_157 ( V_50 ) , 0x00760018 ) ;
F_148 ( V_6 , V_54 , F_158 ( V_50 ) , 0x00400888 ) ;
F_159 ( & V_6 -> V_214 ) ;
V_2 -> V_136 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_113 ,
V_68 ) ;
F_88 ( V_13 ) ;
F_160 ( V_6 , V_212 , 0x0 ) ;
}
static void F_161 ( struct V_103 * V_13 )
{
struct V_14 * V_212 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_213 V_50 = F_144 ( V_212 ) ;
int V_54 = V_51 -> V_54 ;
F_71 ( V_13 ) ;
F_145 ( & V_6 -> V_214 ) ;
F_148 ( V_6 , V_54 , F_162 ( V_50 ) ,
V_216 |
V_217 ) ;
F_148 ( V_6 , V_54 , F_163 ( V_50 ) ,
V_218 |
V_219 |
( 1 << V_220 ) |
V_221 ) ;
F_148 ( V_6 , V_54 , F_164 ( V_50 ) , 0x00750f00 ) ;
F_148 ( V_6 , V_54 , F_165 ( V_50 ) , 0x00001500 ) ;
F_148 ( V_6 , V_54 , F_166 ( V_50 ) , 0x40400000 ) ;
F_148 ( V_6 , V_54 , F_156 ( V_50 ) , 0x00002000 ) ;
F_148 ( V_6 , V_54 , F_150 ( V_50 ) , V_215 ) ;
F_159 ( & V_6 -> V_214 ) ;
}
static void F_167 ( struct V_103 * V_13 ,
bool V_222 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_213 V_223 = F_144 ( F_25 ( & V_13 -> V_3 ) ) ;
struct V_51 * V_52 = F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_54 V_54 = V_52 -> V_54 ;
T_1 V_39 ;
V_39 = F_146 ( V_6 , V_54 , F_168 ( V_223 ) ) ;
if ( V_222 )
V_39 &= ~ ( V_216 | V_217 ) ;
else
V_39 |= V_216 | V_217 ;
F_148 ( V_6 , V_54 , F_168 ( V_223 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_130 > 2 ) {
V_39 = F_146 ( V_6 , V_54 , F_169 ( V_223 ) ) ;
if ( V_222 )
V_39 &= ~ ( V_216 | V_217 ) ;
else
V_39 |= V_216 | V_217 ;
F_148 ( V_6 , V_54 , F_169 ( V_223 ) , V_39 ) ;
}
V_39 = F_146 ( V_6 , V_54 , F_170 ( V_223 ) ) ;
V_39 |= V_224 ;
if ( V_222 )
V_39 &= ~ V_221 ;
else
V_39 |= V_221 ;
F_148 ( V_6 , V_54 , F_170 ( V_223 ) , V_39 ) ;
if ( V_52 -> V_57 -> V_130 > 2 ) {
V_39 = F_146 ( V_6 , V_54 , F_171 ( V_223 ) ) ;
V_39 |= V_224 ;
if ( V_222 )
V_39 &= ~ V_221 ;
else
V_39 |= V_221 ;
F_148 ( V_6 , V_54 , F_171 ( V_223 ) , V_39 ) ;
}
}
static void F_172 ( struct V_103 * V_13 )
{
struct V_14 * V_212 = F_25 ( & V_13 -> V_3 ) ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_213 V_223 = F_144 ( V_212 ) ;
enum V_54 V_54 = V_51 -> V_54 ;
T_2 V_39 ;
F_71 ( V_13 ) ;
if ( V_223 == V_225 && V_54 == V_133 )
V_212 -> V_226 =
! F_173 ( V_6 , V_227 , V_228 , true ) ;
F_174 ( V_13 , true , 0x0 ) ;
F_145 ( & V_6 -> V_214 ) ;
F_167 ( V_13 , true ) ;
if ( V_54 != V_133 ) {
V_39 = F_146 ( V_6 , V_54 , V_229 ) ;
V_39 &= ~ ( V_230 | V_231 ) ;
if ( V_223 == V_225 )
V_39 |= V_232 ;
if ( V_223 == V_228 )
V_39 |= V_233 ;
F_148 ( V_6 , V_54 , V_229 , V_39 ) ;
} else {
V_39 = F_146 ( V_6 , V_54 , V_234 ) ;
V_39 &= ~ ( V_235 | V_236 ) ;
if ( V_223 == V_225 )
V_39 |= V_237 ;
if ( V_223 == V_228 )
V_39 |= V_238 ;
F_148 ( V_6 , V_54 , V_234 , V_39 ) ;
}
V_39 = F_146 ( V_6 , V_54 , F_147 ( V_223 ) ) ;
V_39 |= V_239 ;
if ( V_54 != V_133 )
V_39 &= ~ V_240 ;
else
V_39 |= V_240 ;
F_148 ( V_6 , V_54 , F_147 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_175 ( V_223 ) ) ;
V_39 |= V_239 ;
if ( V_54 != V_133 )
V_39 &= ~ V_240 ;
else
V_39 |= V_240 ;
F_148 ( V_6 , V_54 , F_175 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_176 ( V_223 ) ) ;
if ( V_54 != V_133 )
V_39 &= ~ V_241 ;
else
V_39 |= V_241 ;
F_148 ( V_6 , V_54 , F_176 ( V_223 ) , V_39 ) ;
F_159 ( & V_6 -> V_214 ) ;
}
static void F_177 ( struct V_103 * V_13 )
{
struct V_5 * V_6 = F_24 ( V_13 -> V_3 . V_4 ) ;
enum V_54 V_54 = F_28 ( V_13 -> V_3 . V_52 ) -> V_54 ;
T_2 V_39 ;
F_145 ( & V_6 -> V_214 ) ;
if ( V_54 != V_133 ) {
V_39 = F_146 ( V_6 , V_54 , V_229 ) ;
V_39 &= ~ ( V_230 | V_231 ) ;
F_148 ( V_6 , V_54 , V_229 , V_39 ) ;
} else {
V_39 = F_146 ( V_6 , V_54 , V_234 ) ;
V_39 &= ~ ( V_235 | V_236 ) ;
F_148 ( V_6 , V_54 , V_234 , V_39 ) ;
}
F_159 ( & V_6 -> V_214 ) ;
F_174 ( V_13 , false , 0x0 ) ;
}
static void F_178 ( struct V_103 * V_13 )
{
struct V_14 * V_212 = F_25 ( & V_13 -> V_3 ) ;
struct V_5 * V_6 = V_13 -> V_3 . V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
enum V_213 V_50 = F_144 ( V_212 ) ;
int V_54 = V_51 -> V_54 ;
F_145 ( & V_6 -> V_214 ) ;
F_148 ( V_6 , V_54 , F_162 ( V_50 ) , 0x00000000 ) ;
F_148 ( V_6 , V_54 , F_163 ( V_50 ) , 0x00e00060 ) ;
F_159 ( & V_6 -> V_214 ) ;
}
static void F_179 ( struct V_103 * V_13 )
{
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_145 ( & V_6 -> V_214 ) ;
F_167 ( V_13 , true ) ;
F_159 ( & V_6 -> V_214 ) ;
}
static void F_180 ( struct V_103 * V_13 )
{
struct V_14 * V_212 = F_25 ( & V_13 -> V_3 ) ;
struct V_2 * V_2 = & V_212 -> V_16 ;
struct V_1 * V_4 = V_13 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_51 * V_51 =
F_28 ( V_13 -> V_3 . V_52 ) ;
const struct V_67 * V_68 = & V_51 -> V_57 -> V_3 . V_68 ;
enum V_213 V_223 = F_144 ( V_212 ) ;
int V_54 = V_51 -> V_54 ;
int V_38 , V_34 , V_242 ;
T_2 V_39 ;
F_145 ( & V_6 -> V_214 ) ;
V_39 = F_146 ( V_6 , V_54 , F_181 ( V_223 ) ) ;
V_39 &= ~ V_243 ;
F_148 ( V_6 , V_54 , F_181 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_182 ( V_223 ) ) ;
V_39 &= ~ V_243 ;
F_148 ( V_6 , V_54 , F_182 ( V_223 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_38 = ( V_34 == 1 ) ? 0x0 : 0x1 ;
F_148 ( V_6 , V_54 , F_183 ( V_223 , V_34 ) ,
V_38 << V_244 ) ;
}
if ( V_51 -> V_57 -> V_127 > 270000 )
V_242 = 0x18 ;
else if ( V_51 -> V_57 -> V_127 > 135000 )
V_242 = 0xd ;
else if ( V_51 -> V_57 -> V_127 > 67500 )
V_242 = 0x7 ;
else if ( V_51 -> V_57 -> V_127 > 33750 )
V_242 = 0x4 ;
else
V_242 = 0x2 ;
V_39 = F_146 ( V_6 , V_54 , F_181 ( V_223 ) ) ;
V_39 |= F_184 ( 0x1f ) ;
F_148 ( V_6 , V_54 , F_181 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_182 ( V_223 ) ) ;
V_39 |= F_184 ( 0x1f ) ;
F_148 ( V_6 , V_54 , F_182 ( V_223 ) , V_39 ) ;
F_148 ( V_6 , V_54 , F_185 ( V_223 ) ,
F_186 ( V_242 ) |
V_245 |
F_187 ( 0x1f ) |
F_188 ( 6 ) |
F_189 ( 0 ) ) ;
F_148 ( V_6 , V_54 , F_190 ( V_223 ) ,
F_186 ( V_242 ) |
V_245 |
F_187 ( 0x1f ) |
F_188 ( 7 ) |
F_189 ( 5 ) ) ;
F_167 ( V_13 , false ) ;
V_39 = F_146 ( V_6 , V_54 , F_191 ( V_223 ) ) ;
V_39 &= ~ ( V_246 | V_247 ) ;
V_39 &= ~ ( V_248 | V_249 ) ;
V_39 |= V_250 | V_251 ;
F_148 ( V_6 , V_54 , F_191 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_192 ( V_223 ) ) ;
V_39 &= ~ ( V_246 | V_247 ) ;
V_39 &= ~ ( V_248 | V_249 ) ;
V_39 |= V_250 | V_251 ;
F_148 ( V_6 , V_54 , F_192 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_193 ( V_223 ) ) ;
V_39 &= ~ ( V_252 | V_253 ) ;
V_39 |= V_254 | V_255 ;
F_148 ( V_6 , V_54 , F_193 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_194 ( V_223 ) ) ;
V_39 &= ~ ( V_252 | V_253 ) ;
V_39 |= V_254 | V_255 ;
F_148 ( V_6 , V_54 , F_194 ( V_223 ) , V_39 ) ;
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_146 ( V_6 , V_54 , F_195 ( V_223 , V_34 ) ) ;
V_39 &= ~ V_256 ;
V_39 |= 128 << V_257 ;
F_148 ( V_6 , V_54 , F_195 ( V_223 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_146 ( V_6 , V_54 , F_196 ( V_223 , V_34 ) ) ;
V_39 &= ~ V_258 ;
V_39 |= 102 << V_259 ;
V_39 &= ~ ( 0xff << V_260 ) ;
V_39 |= 0x9a << V_260 ;
F_148 ( V_6 , V_54 , F_196 ( V_223 , V_34 ) , V_39 ) ;
}
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_39 = F_146 ( V_6 , V_54 , F_197 ( V_223 , V_34 ) ) ;
V_39 &= ~ V_261 ;
F_148 ( V_6 , V_54 , F_197 ( V_223 , V_34 ) , V_39 ) ;
}
V_39 = F_146 ( V_6 , V_54 , F_191 ( V_223 ) ) ;
V_39 |= V_246 | V_247 ;
F_148 ( V_6 , V_54 , F_191 ( V_223 ) , V_39 ) ;
V_39 = F_146 ( V_6 , V_54 , F_192 ( V_223 ) ) ;
V_39 |= V_246 | V_247 ;
F_148 ( V_6 , V_54 , F_192 ( V_223 ) , V_39 ) ;
F_159 ( & V_6 -> V_214 ) ;
V_2 -> V_136 ( & V_13 -> V_3 ,
V_51 -> V_57 -> V_113 ,
V_68 ) ;
F_88 ( V_13 ) ;
F_160 ( V_6 , V_212 , 0x0 ) ;
if ( V_212 -> V_226 ) {
F_173 ( V_6 , V_227 , V_228 , false ) ;
V_212 -> V_226 = false ;
}
}
static void F_198 ( struct V_17 * V_18 )
{
F_118 ( F_119 ( V_18 ) -> V_171 ) ;
F_199 ( V_18 ) ;
F_118 ( V_18 ) ;
}
static void
F_200 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
F_201 ( V_18 ) ;
F_202 ( V_18 ) ;
V_2 -> V_165 = true ;
F_203 ( V_18 ) ;
V_2 -> V_169 = V_207 ;
}
void F_204 ( struct V_14 * V_15 ,
struct V_262 * V_262 )
{
struct V_17 * V_18 = & V_262 -> V_3 ;
struct V_2 * V_2 = & V_15 -> V_16 ;
struct V_103 * V_103 = & V_15 -> V_3 ;
struct V_1 * V_4 = V_103 -> V_3 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
enum V_50 V_50 = V_15 -> V_50 ;
T_5 V_263 ;
F_51 ( L_22 ,
F_205 ( V_50 ) ) ;
if ( F_5 ( V_15 -> V_264 < 4 ,
L_23 ,
V_15 -> V_264 , F_205 ( V_50 ) ) )
return;
F_206 ( V_4 , V_18 , & V_265 ,
V_266 ) ;
F_207 ( V_18 , & V_267 ) ;
V_18 -> V_268 = 1 ;
V_18 -> V_269 = 0 ;
V_18 -> V_270 = 1 ;
switch ( V_50 ) {
case V_271 :
if ( F_109 ( V_6 ) )
V_2 -> V_100 = V_272 ;
else
V_2 -> V_100 = V_273 ;
if ( F_208 ( V_6 , 0 , V_274 ) )
V_103 -> V_275 = V_276 ;
else
V_103 -> V_275 = V_277 ;
break;
case V_278 :
if ( F_109 ( V_6 ) )
V_2 -> V_100 = V_279 ;
else
V_2 -> V_100 = V_280 ;
V_103 -> V_275 = V_281 ;
break;
case V_282 :
if ( F_53 ( F_109 ( V_6 ) ) )
V_2 -> V_100 = V_283 ;
else if ( F_60 ( V_6 ) )
V_2 -> V_100 = V_284 ;
else
V_2 -> V_100 = V_285 ;
V_103 -> V_275 = V_286 ;
break;
case V_287 :
V_263 =
V_6 -> V_288 . V_289 [ V_287 ] . V_263 ;
switch ( V_263 ) {
case V_290 :
V_2 -> V_100 = V_273 ;
break;
case V_291 :
V_2 -> V_100 = V_280 ;
break;
case V_292 :
V_2 -> V_100 = V_285 ;
break;
default:
F_12 ( V_263 ) ;
}
V_103 -> V_275 = V_293 ;
break;
case V_294 :
V_103 -> V_275 = V_276 ;
default:
F_209 () ;
}
if ( F_59 ( V_4 ) || F_60 ( V_4 ) ) {
V_2 -> V_65 = F_34 ;
V_2 -> V_136 = F_66 ;
V_2 -> V_122 = F_37 ;
} else if ( F_103 ( V_4 ) ) {
V_2 -> V_65 = F_19 ;
V_2 -> V_136 = F_50 ;
V_2 -> V_122 = F_23 ;
} else if ( F_4 ( V_4 ) ) {
V_2 -> V_65 = F_38 ;
V_2 -> V_136 = F_67 ;
V_2 -> V_122 = F_40 ;
} else if ( F_94 ( V_4 ) ) {
V_2 -> V_65 = F_27 ;
V_2 -> V_136 = F_64 ;
V_2 -> V_122 = F_31 ;
} else {
V_2 -> V_65 = F_32 ;
V_2 -> V_136 = F_65 ;
V_2 -> V_122 = F_33 ;
}
if ( F_4 ( V_4 ) )
V_262 -> V_295 = V_296 ;
else
V_262 -> V_295 = V_297 ;
V_262 -> V_298 = V_299 ;
F_200 ( V_2 , V_18 ) ;
F_210 ( V_262 , V_103 ) ;
F_211 ( V_18 ) ;
V_2 -> V_300 = V_262 ;
if ( F_103 ( V_4 ) && ! F_212 ( V_4 ) ) {
T_2 V_131 = F_6 ( V_301 ) ;
F_20 ( V_301 , ( V_131 & ~ 0xf ) | 0xd ) ;
}
}
void F_213 ( struct V_1 * V_4 ,
T_3 V_11 , enum V_50 V_50 )
{
struct V_14 * V_15 ;
struct V_103 * V_103 ;
struct V_262 * V_262 ;
V_15 = F_214 ( sizeof( * V_15 ) , V_302 ) ;
if ( ! V_15 )
return;
V_262 = F_215 () ;
if ( ! V_262 ) {
F_118 ( V_15 ) ;
return;
}
V_103 = & V_15 -> V_3 ;
F_216 ( V_4 , & V_103 -> V_3 , & V_303 ,
V_304 , NULL ) ;
V_103 -> V_305 = F_115 ;
if ( F_62 ( V_4 ) ) {
V_103 -> V_306 = F_100 ;
V_103 -> V_307 = F_101 ;
} else {
V_103 -> V_306 = F_98 ;
}
V_103 -> V_295 = F_76 ;
V_103 -> V_308 = F_83 ;
if ( F_60 ( V_4 ) ) {
V_103 -> V_309 = F_172 ;
V_103 -> V_310 = F_180 ;
V_103 -> V_80 = F_92 ;
V_103 -> V_307 = F_179 ;
V_103 -> V_311 = F_177 ;
} else if ( F_59 ( V_4 ) ) {
V_103 -> V_309 = F_161 ;
V_103 -> V_310 = F_143 ;
V_103 -> V_80 = F_92 ;
V_103 -> V_307 = F_178 ;
} else {
V_103 -> V_310 = F_142 ;
if ( F_72 ( V_4 ) )
V_103 -> V_80 = F_90 ;
else if ( F_94 ( V_4 ) )
V_103 -> V_80 = F_89 ;
else
V_103 -> V_80 = F_88 ;
}
V_103 -> type = V_161 ;
if ( F_60 ( V_4 ) ) {
if ( V_50 == V_282 )
V_103 -> V_312 = 1 << 2 ;
else
V_103 -> V_312 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_103 -> V_312 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_103 -> V_313 = 1 << V_314 ;
if ( F_103 ( V_4 ) )
V_103 -> V_313 |= 1 << V_161 ;
V_15 -> V_50 = V_50 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_315 . V_316 = V_35 ;
V_15 -> V_264 = 4 ;
F_204 ( V_15 , V_262 ) ;
}
