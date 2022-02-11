static inline bool F_1 ( T_1 V_1 )
{
return ( ( V_1 & V_2 ) != V_2 ) &&
( ( ( V_1 & V_3 ) == V_4 ) ||
( V_1 == V_5 ) ) ;
}
static T_1 F_2 ( struct V_6 * V_7 )
{
return V_7 -> V_8 & ~ V_9 ;
}
bool F_3 ( struct V_6 * V_7 )
{
return F_1 ( F_2 ( V_7 ) ) ;
}
static const struct V_10 * F_4 ( void )
{
return & V_11 ;
}
static const struct
V_10 * F_5 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_12 -> V_13 ) {
case 0x60 :
case 0x61 :
case 0x62 :
return & V_14 ;
case 0x63 :
case 0x65 :
return & V_15 ;
case 0x64 :
return & V_11 ;
case 0x66 :
case 0x69 :
return & V_16 ;
case 0x67 :
case 0x68 :
case 0x6A :
case 0x6C :
return & V_17 ;
default:
F_6 ( 1 ) ;
return F_4 () ;
}
}
bool F_7 ( T_1 V_18 )
{
return V_18 == V_19 ;
}
static bool F_8 ( T_1 V_20 )
{
return ( V_20 >= 5260 && V_20 <= 5700 ) ;
}
static void
F_9 ( struct V_21 * V_21 ,
enum V_22 V_23 )
{
enum V_24 V_25 ;
struct V_26 * V_27 ;
const struct V_28 * V_29 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
T_2 V_33 = 0 ;
int V_34 ;
for ( V_25 = 0 ; V_25 < V_35 ; V_25 ++ ) {
if ( ! V_21 -> V_36 [ V_25 ] )
continue;
V_27 = V_21 -> V_36 [ V_25 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_37 ; V_32 ++ ) {
V_31 = & V_27 -> V_38 [ V_32 ] ;
if ( F_8 ( V_31 -> V_20 ) ||
( V_31 -> V_39 & V_40 ) )
continue;
if ( V_23 == V_41 ) {
V_34 = F_10 ( V_21 ,
V_31 -> V_20 ,
V_33 ,
& V_29 ) ;
if ( V_34 )
continue;
if ( ! ( V_29 -> V_39 &
V_42 ) )
V_31 -> V_39 &=
~ V_43 ;
if ( ! ( V_29 -> V_39 &
V_44 ) )
V_31 -> V_39 &=
~ V_45 ;
} else {
if ( V_31 -> V_46 )
V_31 -> V_39 &= ~ ( V_43 |
V_45 ) ;
}
}
}
}
static void
F_11 ( struct V_21 * V_21 ,
enum V_22 V_23 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
const struct V_28 * V_29 ;
T_2 V_33 = 0 ;
int V_34 ;
V_27 = V_21 -> V_36 [ V_47 ] ;
if ( ! V_27 )
return;
if ( V_23 != V_41 ) {
V_31 = & V_27 -> V_38 [ 11 ] ;
if ( V_31 -> V_39 & V_45 )
V_31 -> V_39 &= ~ V_45 ;
V_31 = & V_27 -> V_38 [ 12 ] ;
if ( V_31 -> V_39 & V_45 )
V_31 -> V_39 &= ~ V_45 ;
return;
}
V_31 = & V_27 -> V_38 [ 11 ] ;
V_34 = F_10 ( V_21 , V_31 -> V_20 , V_33 , & V_29 ) ;
if ( ! V_34 ) {
if ( ! ( V_29 -> V_39 & V_44 ) )
if ( V_31 -> V_39 & V_45 )
V_31 -> V_39 &= ~ V_45 ;
}
V_31 = & V_27 -> V_38 [ 12 ] ;
V_34 = F_10 ( V_21 , V_31 -> V_20 , V_33 , & V_29 ) ;
if ( ! V_34 ) {
if ( ! ( V_29 -> V_39 & V_44 ) )
if ( V_31 -> V_39 & V_45 )
V_31 -> V_39 &= ~ V_45 ;
}
}
static void F_12 ( struct V_21 * V_21 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
if ( ! V_21 -> V_36 [ V_48 ] )
return;
V_27 = V_21 -> V_36 [ V_48 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_37 ; V_32 ++ ) {
V_31 = & V_27 -> V_38 [ V_32 ] ;
if ( ! F_8 ( V_31 -> V_20 ) )
continue;
if ( ! ( V_31 -> V_39 & V_49 ) )
V_31 -> V_39 |= V_40 |
V_43 |
V_45 ;
}
}
static void F_13 ( struct V_21 * V_21 ,
enum V_22 V_23 ,
struct V_6 * V_7 )
{
switch ( V_7 -> V_12 -> V_13 ) {
case 0x60 :
case 0x63 :
case 0x66 :
case 0x67 :
case 0x6C :
F_9 ( V_21 , V_23 ) ;
break;
case 0x68 :
F_9 ( V_21 , V_23 ) ;
F_11 ( V_21 , V_23 ) ;
break;
}
}
int F_14 ( struct V_21 * V_21 ,
struct V_50 * V_51 ,
struct V_6 * V_7 )
{
F_12 ( V_21 ) ;
if ( ! V_51 )
return 0 ;
switch ( V_51 -> V_23 ) {
case V_52 :
case V_53 :
case V_54 :
break;
case V_41 :
if ( F_3 ( V_7 ) )
F_13 ( V_21 , V_51 -> V_23 ,
V_7 ) ;
break;
}
return 0 ;
}
static bool F_15 ( struct V_6 * V_7 )
{
T_1 V_55 = F_2 ( V_7 ) ;
int V_32 ;
if ( V_55 & V_2 ) {
T_1 V_56 = V_55 & ~ V_2 ;
F_16 ( V_57
L_1
L_2 ) ;
for ( V_32 = 0 ; V_32 < F_17 ( V_58 ) ; V_32 ++ )
if ( V_58 [ V_32 ] . V_59 == V_56 )
return true ;
} else {
if ( V_55 != V_60 )
F_16 ( V_57 L_3
L_4 ) ;
for ( V_32 = 0 ; V_32 < F_17 ( V_61 ) ; V_32 ++ )
if ( V_61 [ V_32 ] . V_13 == V_55 )
return true ;
}
F_16 ( V_57
L_5 , V_55 ) ;
return false ;
}
static struct V_62 *
F_18 ( T_1 V_59 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_58 ) ; V_32 ++ ) {
if ( V_58 [ V_32 ] . V_59 == V_59 )
return & V_58 [ V_32 ] ;
}
return NULL ;
}
static struct V_62 *
F_19 ( int V_63 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_58 ) ; V_32 ++ ) {
if ( V_58 [ V_32 ] . V_13 == V_63 )
return & V_58 [ V_32 ] ;
}
return NULL ;
}
static T_1 F_20 ( T_1 V_55 )
{
if ( V_55 & V_2 ) {
struct V_62 * V_64 = NULL ;
T_1 V_56 = V_55 & ~ V_2 ;
V_64 = F_18 ( V_56 ) ;
if ( V_64 != NULL )
return V_56 ;
}
return V_60 ;
}
static struct V_65 *
F_21 ( int V_63 )
{
int V_32 ;
if ( V_63 == V_66 )
return NULL ;
for ( V_32 = 0 ; V_32 < F_17 ( V_61 ) ; V_32 ++ ) {
if ( V_61 [ V_32 ] . V_13 == V_63 )
return & V_61 [ V_32 ] ;
}
return NULL ;
}
static int
F_22 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
int (* F_23)( struct V_21 * V_21 ,
struct V_50 * V_51 ) )
{
const struct V_10 * V_1 ;
V_21 -> F_23 = F_23 ;
V_21 -> V_39 |= V_67 ;
if ( F_3 ( V_7 ) ) {
V_1 = F_5 ( V_7 ) ;
V_21 -> V_39 |= V_68 ;
} else {
V_1 = F_4 () ;
}
F_24 ( V_21 , V_1 ) ;
F_12 ( V_21 ) ;
F_13 ( V_21 , V_52 , V_7 ) ;
return 0 ;
}
static void F_25 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 != V_2 )
return;
F_16 ( V_57 L_6 ) ;
V_7 -> V_8 = 0x64 ;
}
int
F_26 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
int (* F_23)( struct V_21 * V_21 ,
struct V_50 * V_51 ) )
{
struct V_62 * V_64 = NULL ;
T_1 V_63 ;
if ( ! V_7 )
return - V_69 ;
F_25 ( V_7 ) ;
F_16 ( V_57 L_7 , V_7 -> V_8 ) ;
if ( ! F_15 ( V_7 ) ) {
F_16 ( V_70 L_8 ) ;
return - V_69 ;
}
V_63 = F_2 ( V_7 ) ;
V_7 -> V_71 = F_20 ( V_63 ) ;
if ( V_7 -> V_71 == V_60 &&
V_63 == V_60 ) {
F_16 ( V_57 L_9
L_10 ) ;
V_7 -> V_71 = V_72 ;
}
if ( V_7 -> V_71 == V_60 ) {
V_64 = NULL ;
} else {
F_16 ( V_57 L_11
L_12 ) ;
V_64 = F_18 ( V_7 -> V_71 ) ;
if ( V_64 == NULL ) {
F_16 ( V_57
L_13
L_14 ,
V_7 -> V_71 ) ;
return - V_69 ;
} else {
V_63 = V_64 -> V_13 ;
F_16 ( V_57 L_15
L_16 ,
V_63 ) ;
}
}
V_7 -> V_12 = F_21 ( V_63 ) ;
if ( ! V_7 -> V_12 ) {
F_16 ( V_57 L_17
L_18 ) ;
return - V_69 ;
}
if ( ! V_64 )
V_64 = F_19 ( V_63 ) ;
if ( V_64 ) {
V_7 -> V_73 [ 0 ] = V_64 -> V_74 [ 0 ] ;
V_7 -> V_73 [ 1 ] = V_64 -> V_74 [ 1 ] ;
} else {
V_7 -> V_73 [ 0 ] = '0' ;
V_7 -> V_73 [ 1 ] = '0' ;
}
F_16 ( V_57 L_19 ,
V_7 -> V_73 [ 0 ] , V_7 -> V_73 [ 1 ] ) ;
F_16 ( V_57 L_20 ,
V_7 -> V_12 -> V_13 ) ;
F_22 ( V_7 , V_21 , F_23 ) ;
return 0 ;
}
T_2 F_27 ( struct V_6 * V_7 ,
enum V_24 V_25 )
{
if ( ! V_7 -> V_12 ||
( V_7 -> V_71 == V_60 &&
F_1 ( F_2 ( V_7 ) ) ) ) {
return V_75 ;
}
switch ( V_25 ) {
case V_47 :
return V_7 -> V_12 -> V_76 ;
case V_48 :
return V_7 -> V_12 -> V_77 ;
default:
return V_78 ;
}
}
