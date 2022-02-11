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
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
if ( ! V_21 -> V_34 [ V_25 ] )
continue;
V_27 = V_21 -> V_34 [ V_25 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_35 ; V_32 ++ ) {
V_31 = & V_27 -> V_36 [ V_32 ] ;
if ( F_8 ( V_31 -> V_20 ) ||
( V_31 -> V_37 & V_38 ) )
continue;
if ( V_23 == V_39 ) {
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( F_11 ( V_29 ) )
continue;
if ( ! ( V_29 -> V_37 &
V_40 ) )
V_31 -> V_37 &=
~ V_41 ;
if ( ! ( V_29 -> V_37 &
V_42 ) )
V_31 -> V_37 &=
~ V_43 ;
} else {
if ( V_31 -> V_44 )
V_31 -> V_37 &= ~ ( V_41 |
V_43 ) ;
}
}
}
}
static void
F_12 ( struct V_21 * V_21 ,
enum V_22 V_23 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
const struct V_28 * V_29 ;
V_27 = V_21 -> V_34 [ V_45 ] ;
if ( ! V_27 )
return;
if ( V_23 != V_39 ) {
V_31 = & V_27 -> V_36 [ 11 ] ;
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
V_31 = & V_27 -> V_36 [ 12 ] ;
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
return;
}
V_31 = & V_27 -> V_36 [ 11 ] ;
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( ! F_11 ( V_29 ) ) {
if ( ! ( V_29 -> V_37 & V_42 ) )
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
}
V_31 = & V_27 -> V_36 [ 12 ] ;
V_29 = F_10 ( V_21 , V_31 -> V_20 ) ;
if ( ! F_11 ( V_29 ) ) {
if ( ! ( V_29 -> V_37 & V_42 ) )
if ( V_31 -> V_37 & V_43 )
V_31 -> V_37 &= ~ V_43 ;
}
}
static void F_13 ( struct V_21 * V_21 )
{
struct V_26 * V_27 ;
struct V_30 * V_31 ;
unsigned int V_32 ;
if ( ! V_21 -> V_34 [ V_46 ] )
return;
V_27 = V_21 -> V_34 [ V_46 ] ;
for ( V_32 = 0 ; V_32 < V_27 -> V_35 ; V_32 ++ ) {
V_31 = & V_27 -> V_36 [ V_32 ] ;
if ( ! F_8 ( V_31 -> V_20 ) )
continue;
if ( ! ( V_31 -> V_37 & V_47 ) )
V_31 -> V_37 |= V_38 |
V_41 |
V_43 ;
}
}
static void F_14 ( struct V_21 * V_21 ,
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
F_12 ( V_21 , V_23 ) ;
break;
}
}
static T_1 F_15 ( char * V_48 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( ! memcmp ( V_49 [ V_32 ] . V_50 , V_48 , 2 ) )
return V_49 [ V_32 ] . V_51 ;
}
return - 1 ;
}
void F_17 ( struct V_21 * V_21 ,
struct V_52 * V_53 ,
struct V_6 * V_7 )
{
struct V_54 * V_55 = F_18 ( V_7 , struct V_54 ,
V_56 ) ;
T_1 V_57 ;
F_13 ( V_21 ) ;
if ( ! V_53 )
return;
switch ( V_53 -> V_23 ) {
case V_58 :
if ( ! F_3 ( & V_55 -> V_59 ) )
break;
memcpy ( V_7 , & V_55 -> V_59 ,
sizeof( struct V_6 ) ) ;
break;
case V_60 :
case V_61 :
break;
case V_39 :
if ( ! F_3 ( V_7 ) )
break;
V_57 = F_15 ( V_53 -> V_48 ) ;
if ( V_57 == ( T_1 ) - 1 )
break;
V_7 -> V_8 = V_2 ;
V_7 -> V_8 |= V_57 ;
F_19 ( V_62 L_1 ,
V_7 -> V_8 ) ;
F_20 ( V_7 ) ;
F_14 ( V_21 , V_53 -> V_23 , V_7 ) ;
break;
}
}
static bool F_21 ( struct V_6 * V_7 )
{
T_1 V_63 = F_2 ( V_7 ) ;
int V_32 ;
if ( V_63 & V_2 ) {
T_1 V_64 = V_63 & ~ V_2 ;
F_19 ( V_62
L_2
L_3 ) ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ )
if ( V_49 [ V_32 ] . V_51 == V_64 )
return true ;
} else {
if ( V_63 != V_65 )
F_19 ( V_62 L_4
L_5 ) ;
for ( V_32 = 0 ; V_32 < F_16 ( V_66 ) ; V_32 ++ )
if ( V_66 [ V_32 ] . V_13 == V_63 )
return true ;
}
F_19 ( V_62
L_6 , V_63 ) ;
return false ;
}
static struct V_67 *
F_22 ( T_1 V_51 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( V_49 [ V_32 ] . V_51 == V_51 )
return & V_49 [ V_32 ] ;
}
return NULL ;
}
static struct V_67 *
F_23 ( int V_68 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_49 ) ; V_32 ++ ) {
if ( V_49 [ V_32 ] . V_13 == V_68 )
return & V_49 [ V_32 ] ;
}
return NULL ;
}
static T_1 F_24 ( T_1 V_63 )
{
if ( V_63 & V_2 ) {
struct V_67 * V_69 = NULL ;
T_1 V_64 = V_63 & ~ V_2 ;
V_69 = F_22 ( V_64 ) ;
if ( V_69 != NULL )
return V_64 ;
}
return V_65 ;
}
static struct V_70 *
F_25 ( int V_68 )
{
int V_32 ;
if ( V_68 == V_71 )
return NULL ;
for ( V_32 = 0 ; V_32 < F_16 ( V_66 ) ; V_32 ++ ) {
if ( V_66 [ V_32 ] . V_13 == V_68 )
return & V_66 [ V_32 ] ;
}
return NULL ;
}
static int
F_26 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
void (* F_27)( struct V_21 * V_21 ,
struct V_52 * V_53 ) )
{
const struct V_10 * V_1 ;
V_21 -> F_27 = F_27 ;
V_21 -> V_37 |= V_72 ;
if ( F_3 ( V_7 ) ) {
V_1 = F_5 ( V_7 ) ;
V_21 -> V_37 |= V_73 ;
} else {
V_1 = F_4 () ;
}
F_28 ( V_21 , V_1 ) ;
F_13 ( V_21 ) ;
F_14 ( V_21 , V_60 , V_7 ) ;
return 0 ;
}
static void F_29 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 != V_2 )
return;
F_19 ( V_62 L_7 ) ;
V_7 -> V_8 = 0x64 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_67 * V_69 = NULL ;
T_1 V_68 ;
if ( ! V_7 )
return - V_74 ;
F_29 ( V_7 ) ;
F_19 ( V_62 L_8 , V_7 -> V_8 ) ;
if ( ! F_21 ( V_7 ) ) {
F_30 ( L_9 ) ;
return - V_74 ;
}
V_68 = F_2 ( V_7 ) ;
V_7 -> V_57 = F_24 ( V_68 ) ;
if ( V_7 -> V_57 == V_65 &&
V_68 == V_65 ) {
F_19 ( V_62 L_10
L_11 ) ;
V_7 -> V_57 = V_75 ;
}
if ( V_7 -> V_57 == V_65 ) {
V_69 = NULL ;
} else {
F_19 ( V_62 L_12
L_13 ) ;
V_69 = F_22 ( V_7 -> V_57 ) ;
if ( V_69 == NULL ) {
F_19 ( V_62
L_14
L_15 ,
V_7 -> V_57 ) ;
return - V_74 ;
} else {
V_68 = V_69 -> V_13 ;
F_19 ( V_62 L_16
L_17 ,
V_68 ) ;
}
}
V_7 -> V_12 = F_25 ( V_68 ) ;
if ( ! V_7 -> V_12 ) {
F_19 ( V_62 L_18
L_19 ) ;
return - V_74 ;
}
if ( ! V_69 )
V_69 = F_23 ( V_68 ) ;
if ( V_69 ) {
V_7 -> V_48 [ 0 ] = V_69 -> V_50 [ 0 ] ;
V_7 -> V_48 [ 1 ] = V_69 -> V_50 [ 1 ] ;
} else {
V_7 -> V_48 [ 0 ] = '0' ;
V_7 -> V_48 [ 1 ] = '0' ;
}
F_19 ( V_62 L_20 ,
V_7 -> V_48 [ 0 ] , V_7 -> V_48 [ 1 ] ) ;
F_19 ( V_62 L_21 ,
V_7 -> V_12 -> V_13 ) ;
return 0 ;
}
int
F_31 ( struct V_6 * V_7 ,
struct V_21 * V_21 ,
void (* F_27)( struct V_21 * V_21 ,
struct V_52 * V_53 ) )
{
struct V_54 * V_55 = F_18 ( V_7 , struct V_54 ,
V_56 ) ;
int V_76 ;
V_76 = F_20 ( V_7 ) ;
if ( V_76 )
return V_76 ;
if ( F_3 ( V_7 ) )
memcpy ( & V_55 -> V_59 , V_7 ,
sizeof( struct V_6 ) ) ;
F_26 ( V_7 , V_21 , F_27 ) ;
return 0 ;
}
T_2 F_32 ( struct V_6 * V_7 ,
enum V_24 V_25 )
{
if ( ! V_7 -> V_12 ||
( V_7 -> V_57 == V_65 &&
F_1 ( F_2 ( V_7 ) ) ) ) {
return V_77 ;
}
switch ( V_25 ) {
case V_45 :
return V_7 -> V_12 -> V_78 ;
case V_46 :
return V_7 -> V_12 -> V_79 ;
default:
return V_80 ;
}
}
