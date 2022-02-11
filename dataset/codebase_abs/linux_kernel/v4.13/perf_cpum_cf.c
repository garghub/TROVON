static void F_1 ( T_1 * V_1 , int V_2 )
{
* V_1 |= V_3 [ V_2 ] << V_4 ;
}
static void F_2 ( T_1 * V_1 , int V_2 )
{
* V_1 &= ~ ( V_3 [ V_2 ] << V_4 ) ;
}
static void F_3 ( T_1 * V_1 , int V_2 )
{
* V_1 |= V_3 [ V_2 ] << V_5 ;
}
static void F_4 ( T_1 * V_1 , int V_2 )
{
* V_1 &= ~ ( V_3 [ V_2 ] << V_5 ) ;
}
static enum V_6 F_5 ( T_1 V_7 )
{
int V_8 = V_9 ;
if ( V_7 < 32 )
V_8 = V_10 ;
else if ( V_7 < 64 )
V_8 = V_11 ;
else if ( V_7 < 128 )
V_8 = V_12 ;
else if ( V_7 < 256 )
V_8 = V_13 ;
else if ( V_7 >= 448 && V_7 < 496 )
V_8 = V_14 ;
return V_8 ;
}
static int F_6 ( const struct V_15 * V_16 )
{
struct V_17 * V_18 ;
int V_19 = 0 ;
T_2 V_20 ;
V_18 = & F_7 ( V_17 ) ;
switch ( V_16 -> V_21 ) {
case V_10 :
case V_11 :
if ( V_18 -> V_22 . V_23 < 1 )
V_19 = - V_24 ;
break;
case V_12 :
case V_13 :
if ( V_18 -> V_22 . V_25 < 1 )
V_19 = - V_24 ;
if ( ( V_18 -> V_22 . V_25 == 1 && V_16 -> V_26 > 159 ) ||
( V_18 -> V_22 . V_25 == 2 && V_16 -> V_26 > 175 ) ||
( V_18 -> V_22 . V_25 > 2 && V_16 -> V_26 > 255 ) )
V_19 = - V_24 ;
break;
case V_14 :
if ( V_18 -> V_22 . V_25 <= 3 )
V_19 = - V_24 ;
V_20 = V_3 [ V_14 ] ;
if ( ! ( ( V_18 -> V_22 . V_27 & V_20 ) &&
( V_18 -> V_22 . V_28 & V_20 ) &&
( V_18 -> V_22 . V_29 & V_20 ) ) )
V_19 = - V_24 ;
break;
}
F_8 ( V_17 ) ;
return V_19 ;
}
static int F_9 ( const struct V_15 * V_16 )
{
struct V_17 * V_18 ;
T_1 V_30 ;
int V_19 = 0 ;
V_18 = & F_7 ( V_17 ) ;
V_30 = V_3 [ V_16 -> V_21 ] ;
if ( ! ( V_30 & V_18 -> V_22 . V_27 ) )
V_19 = - V_31 ;
F_8 ( V_17 ) ;
return V_19 ;
}
static void F_10 ( struct V_32 * V_32 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
int V_19 ;
if ( V_18 -> V_33 & V_34 )
return;
V_19 = F_12 ( V_18 -> V_1 ) ;
if ( V_19 ) {
F_13 ( L_1
L_2 , V_19 ) ;
return;
}
V_18 -> V_33 |= V_34 ;
}
static void F_14 ( struct V_32 * V_32 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
int V_19 ;
T_1 V_35 ;
if ( ! ( V_18 -> V_33 & V_34 ) )
return;
V_35 = V_18 -> V_1 & ~ ( ( 1 << V_4 ) - 1 ) ;
V_19 = F_12 ( V_35 ) ;
if ( V_19 ) {
F_13 ( L_3
L_2 , V_19 ) ;
return;
}
V_18 -> V_33 &= ~ V_34 ;
}
static void F_15 ( struct V_36 V_36 ,
unsigned int V_37 , unsigned long V_38 )
{
struct V_17 * V_18 ;
if ( ! ( V_37 & V_39 ) )
return;
F_16 ( V_40 ) ;
V_18 = F_11 ( & V_17 ) ;
if ( ! ( V_18 -> V_33 & V_41 ) )
return;
if ( V_37 & V_42 )
F_17 ( & V_18 -> V_22 ) ;
if ( V_37 & V_43 )
F_13 ( L_4 , F_18 () ) ;
if ( V_37 & V_44 )
F_19 ( L_5 ,
F_18 () ) ;
}
static void F_20 ( void * V_33 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
switch ( * ( ( int * ) V_33 ) ) {
case V_45 :
memset ( & V_18 -> V_22 , 0 , sizeof( V_18 -> V_22 ) ) ;
F_17 ( & V_18 -> V_22 ) ;
V_18 -> V_33 |= V_41 ;
break;
case V_46 :
V_18 -> V_33 &= ~ V_41 ;
break;
}
F_12 ( 0 ) ;
}
static int F_21 ( void )
{
int V_33 = V_45 ;
F_22 ( F_20 , & V_33 , 1 ) ;
F_23 ( V_47 ) ;
return 0 ;
}
static void F_24 ( void )
{
int V_33 = V_46 ;
F_22 ( F_20 , & V_33 , 1 ) ;
F_25 ( V_47 ) ;
}
static void F_26 ( struct V_48 * V_7 )
{
if ( ! F_27 ( & V_49 , - 1 , 1 ) ) {
F_28 ( & V_50 ) ;
if ( F_29 ( & V_49 ) == 0 )
F_24 () ;
F_30 ( & V_50 ) ;
}
}
static int F_31 ( struct V_48 * V_7 )
{
struct V_51 * V_52 = & V_7 -> V_52 ;
struct V_15 * V_16 = & V_7 -> V_53 ;
enum V_6 V_8 ;
int V_19 ;
T_1 V_54 ;
switch ( V_52 -> type ) {
case V_55 :
if ( V_52 -> V_56 || V_52 -> V_57 ||
V_52 -> V_58 )
return - V_24 ;
V_54 = V_52 -> V_26 ;
break;
case V_59 :
V_54 = V_52 -> V_26 ;
if ( ! V_52 -> V_57 && V_52 -> V_56 ) {
if ( V_54 >= F_32 ( V_60 ) )
return - V_24 ;
V_54 = V_60 [ V_54 ] ;
} else if ( ! V_52 -> V_56 && V_52 -> V_57 ) {
return - V_24 ;
} else {
if ( V_54 >= F_32 ( V_61 ) )
return - V_24 ;
V_54 = V_61 [ V_54 ] ;
}
break;
default:
return - V_31 ;
}
if ( V_54 == - 1 )
return - V_31 ;
if ( V_54 > V_62 )
return - V_63 ;
V_8 = F_5 ( V_54 ) ;
switch ( V_8 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_16 -> V_26 = V_54 ;
V_16 -> V_21 = V_8 ;
break;
case V_9 :
return - V_63 ;
} ;
if ( ! F_33 ( & V_49 ) ) {
F_28 ( & V_50 ) ;
if ( F_34 ( & V_49 ) == 0 && F_21 () )
V_19 = - V_64 ;
else
F_35 ( & V_49 ) ;
F_30 ( & V_50 ) ;
}
V_7 -> V_65 = F_26 ;
V_19 = F_9 ( V_16 ) ;
if ( ! V_19 )
V_19 = F_6 ( V_16 ) ;
return V_19 ;
}
static int F_36 ( struct V_48 * V_7 )
{
int V_19 ;
switch ( V_7 -> V_52 . type ) {
case V_59 :
case V_66 :
case V_55 :
V_19 = F_31 ( V_7 ) ;
break;
default:
return - V_31 ;
}
if ( F_37 ( V_19 ) && V_7 -> V_65 )
V_7 -> V_65 ( V_7 ) ;
return V_19 ;
}
static int F_38 ( struct V_48 * V_7 )
{
T_1 V_67 , V_68 ;
int V_19 ;
do {
V_67 = F_39 ( & V_7 -> V_53 . V_69 ) ;
V_19 = F_40 ( V_7 -> V_53 . V_26 , & V_68 ) ;
if ( V_19 ) {
if ( V_19 != 3 )
break;
V_68 = 0 ;
}
} while ( F_41 ( & V_7 -> V_53 . V_69 , V_67 , V_68 ) != V_67 );
return V_19 ;
}
static void F_42 ( struct V_48 * V_7 )
{
T_1 V_67 , V_68 , V_70 ;
int V_19 ;
do {
V_67 = F_39 ( & V_7 -> V_53 . V_69 ) ;
V_19 = F_40 ( V_7 -> V_53 . V_26 , & V_68 ) ;
if ( V_19 )
return;
} while ( F_41 ( & V_7 -> V_53 . V_69 , V_67 , V_68 ) != V_67 );
V_70 = ( V_67 <= V_68 ) ? V_68 - V_67
: ( - 1ULL - V_67 ) + V_68 + 1 ;
F_43 ( V_70 , & V_7 -> V_71 ) ;
}
static void F_44 ( struct V_48 * V_7 )
{
if ( V_7 -> V_53 . V_1 & V_72 )
return;
F_42 ( V_7 ) ;
}
static void F_45 ( struct V_48 * V_7 , int V_33 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
struct V_15 * V_16 = & V_7 -> V_53 ;
if ( F_46 ( ! ( V_16 -> V_1 & V_72 ) ) )
return;
if ( F_46 ( V_16 -> V_26 == - 1 ) )
return;
if ( V_33 & V_73 )
F_46 ( ! ( V_16 -> V_1 & V_74 ) ) ;
V_16 -> V_1 = 0 ;
F_1 ( & V_18 -> V_1 , V_16 -> V_21 ) ;
F_3 ( & V_18 -> V_1 , V_16 -> V_21 ) ;
F_38 ( V_7 ) ;
F_35 ( & V_18 -> V_2 [ V_16 -> V_21 ] ) ;
}
static void F_47 ( struct V_48 * V_7 , int V_33 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
struct V_15 * V_16 = & V_7 -> V_53 ;
if ( ! ( V_16 -> V_1 & V_72 ) ) {
if ( ! F_29 ( & V_18 -> V_2 [ V_16 -> V_21 ] ) )
F_4 ( & V_18 -> V_1 , V_16 -> V_21 ) ;
V_7 -> V_53 . V_1 |= V_72 ;
}
if ( ( V_33 & V_75 ) && ! ( V_16 -> V_1 & V_74 ) ) {
F_42 ( V_7 ) ;
V_7 -> V_53 . V_1 |= V_74 ;
}
}
static int F_48 ( struct V_48 * V_7 , int V_33 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
if ( ! ( V_18 -> V_76 & V_77 ) )
if ( F_9 ( & V_7 -> V_53 ) )
return - V_31 ;
F_1 ( & V_18 -> V_1 , V_7 -> V_53 . V_21 ) ;
V_7 -> V_53 . V_1 = V_74 | V_72 ;
if ( V_33 & V_78 )
F_45 ( V_7 , V_73 ) ;
F_49 ( V_7 ) ;
return 0 ;
}
static void F_50 ( struct V_48 * V_7 , int V_33 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
F_47 ( V_7 , V_75 ) ;
if ( ! F_34 ( & V_18 -> V_2 [ V_7 -> V_53 . V_21 ] ) )
F_2 ( & V_18 -> V_1 , V_7 -> V_53 . V_21 ) ;
F_49 ( V_7 ) ;
}
static void F_51 ( struct V_32 * V_32 , unsigned int V_76 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
F_46 ( V_18 -> V_76 ) ;
V_18 -> V_76 = V_76 ;
if ( V_76 & ~ V_77 )
return;
F_52 ( V_32 ) ;
V_18 -> V_79 = V_18 -> V_1 ;
}
static void F_53 ( struct V_32 * V_32 )
{
unsigned int V_76 ;
struct V_17 * V_18 = F_11 ( & V_17 ) ;
F_46 ( ! V_18 -> V_76 ) ;
V_76 = V_18 -> V_76 ;
V_18 -> V_76 = 0 ;
if ( V_76 & ~ V_77 )
return;
F_54 ( V_18 -> V_79 != V_18 -> V_1 ) ;
F_55 ( V_32 ) ;
}
static int F_56 ( struct V_32 * V_32 )
{
struct V_17 * V_18 = F_11 ( & V_17 ) ;
T_1 V_1 ;
F_46 ( ! V_18 -> V_76 ) ;
if ( V_18 -> V_76 & ~ V_77 ) {
V_18 -> V_76 = 0 ;
return 0 ;
}
V_1 = V_18 -> V_1 & ~ ( ( 1 << V_4 ) - 1 ) ;
V_1 >>= V_4 ;
if ( ( V_1 & V_18 -> V_22 . V_27 ) != V_1 )
return - V_31 ;
V_18 -> V_76 = 0 ;
F_55 ( V_32 ) ;
return 0 ;
}
static int F_57 ( unsigned int V_80 , int V_33 )
{
F_58 () ;
F_20 ( & V_33 ) ;
F_59 () ;
return 0 ;
}
static int F_60 ( unsigned int V_80 )
{
return F_57 ( V_80 , V_45 ) ;
}
static int F_61 ( unsigned int V_80 )
{
return F_57 ( V_80 , V_46 ) ;
}
static int T_3 F_62 ( void )
{
int V_81 ;
if ( ! F_63 () )
return - V_82 ;
F_64 ( 0 , 48 ) ;
V_81 = F_65 ( V_83 ,
F_15 ) ;
if ( V_81 ) {
F_13 ( L_6
L_7 , V_81 ) ;
return V_81 ;
}
V_84 . V_85 = F_66 () ;
V_81 = F_67 ( & V_84 , L_8 , V_55 ) ;
if ( V_81 ) {
F_13 ( L_9 , V_81 ) ;
F_68 ( V_83 ,
F_15 ) ;
return V_81 ;
}
return F_69 ( V_86 ,
L_10 ,
F_60 , F_61 ) ;
}
