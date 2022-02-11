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
static int F_5 ( T_1 V_6 )
{
int V_7 = - 1 ;
if ( V_6 < 32 )
V_7 = V_8 ;
else if ( V_6 < 64 )
V_7 = V_9 ;
else if ( V_6 < 128 )
V_7 = V_10 ;
else if ( V_6 < 160 )
V_7 = V_11 ;
return V_7 ;
}
static int F_6 ( const struct V_12 * V_13 )
{
switch ( V_13 -> V_14 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
if ( ( V_13 -> V_15 >= 6 && V_13 -> V_15 <= 31 ) ||
( V_13 -> V_15 >= 38 && V_13 -> V_15 <= 63 ) ||
( V_13 -> V_15 >= 80 && V_13 -> V_15 <= 127 ) )
return - V_16 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_7 ( const struct V_12 * V_13 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
V_19 = & F_8 ( V_18 ) ;
switch ( V_13 -> V_14 ) {
case V_8 :
case V_9 :
if ( V_19 -> V_21 . V_22 < 1 )
V_20 = - V_16 ;
break;
case V_10 :
case V_11 :
if ( V_19 -> V_21 . V_23 < 1 )
V_20 = - V_16 ;
break;
}
F_9 ( V_18 ) ;
return V_20 ;
}
static int F_10 ( const struct V_12 * V_13 )
{
struct V_18 * V_19 ;
T_1 V_24 ;
int V_20 = 0 ;
V_19 = & F_8 ( V_18 ) ;
V_24 = V_3 [ V_13 -> V_14 ] ;
if ( ! ( V_24 & V_19 -> V_21 . V_25 ) )
V_20 = - V_26 ;
F_9 ( V_18 ) ;
return V_20 ;
}
static void F_11 ( struct V_27 * V_27 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
int V_20 ;
if ( V_19 -> V_28 & V_29 )
return;
V_20 = F_13 ( V_19 -> V_1 ) ;
if ( V_20 ) {
F_14 ( L_1
L_2 , V_20 ) ;
return;
}
V_19 -> V_28 |= V_29 ;
}
static void F_15 ( struct V_27 * V_27 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
int V_20 ;
T_1 V_30 ;
if ( ! ( V_19 -> V_28 & V_29 ) )
return;
V_30 = V_19 -> V_1 & ~ ( ( 1 << V_4 ) - 1 ) ;
V_20 = F_13 ( V_30 ) ;
if ( V_20 ) {
F_14 ( L_3
L_2 , V_20 ) ;
return;
}
V_19 -> V_28 &= ~ V_29 ;
}
static void F_16 ( struct V_31 V_31 ,
unsigned int V_32 , unsigned long V_33 )
{
struct V_18 * V_19 ;
if ( ! ( V_32 & V_34 ) )
return;
F_17 ( F_18 () ) . V_35 [ V_36 ] ++ ;
V_19 = & F_12 ( V_18 ) ;
if ( ! ( V_19 -> V_28 & V_37 ) )
return;
if ( V_32 & V_38 )
F_19 ( & V_19 -> V_21 ) ;
if ( V_32 & V_39 )
F_14 ( L_4 , F_18 () ) ;
}
static void F_20 ( void * V_28 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
switch ( * ( ( int * ) V_28 ) ) {
case V_40 :
memset ( & V_19 -> V_21 , 0 , sizeof( V_19 -> V_21 ) ) ;
F_19 ( & V_19 -> V_21 ) ;
V_19 -> V_28 |= V_37 ;
break;
case V_41 :
V_19 -> V_28 &= ~ V_37 ;
break;
}
F_13 ( 0 ) ;
}
static int F_21 ( void )
{
int V_28 = V_40 ;
F_22 ( F_20 , & V_28 , 1 ) ;
F_23 () ;
return 0 ;
}
static void F_24 ( void )
{
int V_28 = V_41 ;
F_22 ( F_20 , & V_28 , 1 ) ;
F_25 () ;
}
static void F_26 ( struct V_42 * V_6 )
{
if ( ! F_27 ( & V_43 , - 1 , 1 ) ) {
F_28 ( & V_44 ) ;
if ( F_29 ( & V_43 ) == 0 )
F_24 () ;
F_30 ( & V_44 ) ;
}
}
static int F_31 ( struct V_42 * V_6 )
{
struct V_45 * V_46 = & V_6 -> V_46 ;
struct V_12 * V_13 = & V_6 -> V_47 ;
int V_20 ;
T_1 V_48 ;
switch ( V_46 -> type ) {
case V_49 :
if ( V_46 -> V_50 || V_46 -> V_51 ||
V_46 -> V_52 )
return - V_16 ;
V_48 = V_46 -> V_15 ;
break;
case V_53 :
V_48 = V_46 -> V_15 ;
if ( ! V_46 -> V_51 && V_46 -> V_50 ) {
if ( V_48 >= F_32 ( V_54 ) )
return - V_16 ;
V_48 = V_54 [ V_48 ] ;
} else if ( ! V_46 -> V_50 && V_46 -> V_51 ) {
return - V_16 ;
} else {
if ( V_48 >= F_32 ( V_55 ) )
return - V_16 ;
V_48 = V_55 [ V_48 ] ;
}
break;
default:
return - V_56 ;
}
if ( V_48 == - 1 )
return - V_56 ;
if ( V_48 >= V_57 )
return - V_17 ;
if ( V_13 -> V_58 )
return - V_17 ;
V_13 -> V_15 = V_48 ;
V_13 -> V_14 = F_5 ( V_48 ) ;
V_20 = F_6 ( V_13 ) ;
if ( V_20 )
return V_20 ;
if ( ! F_33 ( & V_43 ) ) {
F_28 ( & V_44 ) ;
if ( F_34 ( & V_43 ) == 0 && F_21 () )
V_20 = - V_59 ;
else
F_35 ( & V_43 ) ;
F_30 ( & V_44 ) ;
}
V_6 -> V_60 = F_26 ;
V_20 = F_10 ( V_13 ) ;
if ( ! V_20 )
V_20 = F_7 ( V_13 ) ;
return V_20 ;
}
static int F_36 ( struct V_42 * V_6 )
{
int V_20 ;
switch ( V_6 -> V_46 . type ) {
case V_53 :
case V_61 :
case V_49 :
V_20 = F_31 ( V_6 ) ;
break;
default:
return - V_56 ;
}
if ( F_37 ( V_20 ) && V_6 -> V_60 )
V_6 -> V_60 ( V_6 ) ;
return V_20 ;
}
static int F_38 ( struct V_42 * V_6 )
{
T_1 V_62 , V_63 ;
int V_20 ;
do {
V_62 = F_39 ( & V_6 -> V_47 . V_64 ) ;
V_20 = F_40 ( V_6 -> V_47 . V_15 , & V_63 ) ;
if ( V_20 ) {
if ( V_20 != 3 )
break;
V_63 = 0 ;
}
} while ( F_41 ( & V_6 -> V_47 . V_64 , V_62 , V_63 ) != V_62 );
return V_20 ;
}
static int F_42 ( struct V_42 * V_6 )
{
T_1 V_62 , V_63 , V_65 ;
int V_20 ;
do {
V_62 = F_39 ( & V_6 -> V_47 . V_64 ) ;
V_20 = F_40 ( V_6 -> V_47 . V_15 , & V_63 ) ;
if ( V_20 )
goto V_66;
} while ( F_41 ( & V_6 -> V_47 . V_64 , V_62 , V_63 ) != V_62 );
V_65 = ( V_62 <= V_63 ) ? V_63 - V_62
: ( - 1ULL - V_62 ) + V_63 + 1 ;
F_43 ( V_65 , & V_6 -> V_67 ) ;
V_66:
return V_20 ;
}
static void F_44 ( struct V_42 * V_6 )
{
if ( V_6 -> V_47 . V_1 & V_68 )
return;
F_42 ( V_6 ) ;
}
static void F_45 ( struct V_42 * V_6 , int V_28 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
struct V_12 * V_13 = & V_6 -> V_47 ;
if ( F_46 ( ! ( V_13 -> V_1 & V_68 ) ) )
return;
if ( F_46 ( V_13 -> V_15 == - 1 ) )
return;
if ( V_28 & V_69 )
F_46 ( ! ( V_13 -> V_1 & V_70 ) ) ;
V_13 -> V_1 = 0 ;
F_1 ( & V_19 -> V_1 , V_13 -> V_14 ) ;
F_3 ( & V_19 -> V_1 , V_13 -> V_14 ) ;
F_38 ( V_6 ) ;
F_35 ( & V_19 -> V_2 [ V_13 -> V_14 ] ) ;
}
static void F_47 ( struct V_42 * V_6 , int V_28 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
struct V_12 * V_13 = & V_6 -> V_47 ;
if ( ! ( V_13 -> V_1 & V_68 ) ) {
if ( ! F_29 ( & V_19 -> V_2 [ V_13 -> V_14 ] ) )
F_4 ( & V_19 -> V_1 , V_13 -> V_14 ) ;
V_6 -> V_47 . V_1 |= V_68 ;
}
if ( ( V_28 & V_71 ) && ! ( V_13 -> V_1 & V_70 ) ) {
F_42 ( V_6 ) ;
V_6 -> V_47 . V_1 |= V_70 ;
}
}
static int F_48 ( struct V_42 * V_6 , int V_28 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
if ( ! ( V_19 -> V_28 & V_72 ) )
if ( F_10 ( & V_6 -> V_47 ) )
return - V_26 ;
F_1 ( & V_19 -> V_1 , V_6 -> V_47 . V_14 ) ;
V_6 -> V_47 . V_1 = V_70 | V_68 ;
if ( V_28 & V_73 )
F_45 ( V_6 , V_69 ) ;
F_49 ( V_6 ) ;
return 0 ;
}
static void F_50 ( struct V_42 * V_6 , int V_28 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
F_47 ( V_6 , V_71 ) ;
if ( ! F_34 ( & V_19 -> V_2 [ V_6 -> V_47 . V_14 ] ) )
F_2 ( & V_19 -> V_1 , V_6 -> V_47 . V_14 ) ;
F_49 ( V_6 ) ;
}
static void F_51 ( struct V_27 * V_27 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
F_52 ( V_27 ) ;
V_19 -> V_28 |= V_72 ;
V_19 -> V_74 = V_19 -> V_1 ;
}
static void F_53 ( struct V_27 * V_27 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
F_54 ( V_19 -> V_74 != V_19 -> V_1 ) ;
V_19 -> V_28 &= ~ V_72 ;
F_55 ( V_27 ) ;
}
static int F_56 ( struct V_27 * V_27 )
{
struct V_18 * V_19 = & F_12 ( V_18 ) ;
T_1 V_1 ;
V_1 = V_19 -> V_1 & ~ ( ( 1 << V_4 ) - 1 ) ;
V_1 >>= V_4 ;
if ( ( V_1 & V_19 -> V_21 . V_25 ) != V_1 )
return - V_26 ;
V_19 -> V_28 &= ~ V_72 ;
F_55 ( V_27 ) ;
return 0 ;
}
static int T_2 F_57 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
unsigned int V_79 = ( long ) V_78 ;
int V_28 ;
switch ( V_77 & ~ V_80 ) {
case V_81 :
V_28 = V_40 ;
F_58 ( V_79 , F_20 , & V_28 , 1 ) ;
break;
case V_82 :
V_28 = V_41 ;
F_58 ( V_79 , F_20 , & V_28 , 1 ) ;
break;
default:
break;
}
return V_83 ;
}
static int T_3 F_59 ( void )
{
int V_84 ;
if ( ! F_60 () )
return - V_85 ;
F_61 ( 0 , 48 ) ;
V_84 = F_62 ( 0x1407 , F_16 ) ;
if ( V_84 ) {
F_14 ( L_5
L_6 , V_84 ) ;
goto V_66;
}
V_84 = F_63 ( & V_86 , L_7 , V_49 ) ;
if ( V_84 ) {
F_14 ( L_8 , V_84 ) ;
F_64 ( 0x1407 , F_16 ) ;
goto V_66;
}
F_65 ( F_57 ) ;
V_66:
return V_84 ;
}
