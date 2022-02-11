static void F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_2 ) ;
V_4 |= V_3 ;
F_3 ( V_4 , V_1 -> V_4 + V_2 ) ;
}
static void F_4 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_2 ) ;
V_4 &= ~ V_3 ;
F_3 ( V_4 , V_1 -> V_4 + V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_7 V_8 )
{
V_6 -> V_9 = V_8 . V_9 ;
V_6 -> type = V_8 . type ;
}
static int F_6 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_9 )
return 0 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 ,
T_1 V_6 )
{
T_1 V_12 = F_2 ( V_1 -> V_4 + F_8 ( V_6 ) ) ;
V_12 &= ~ V_13 ;
V_12 |= F_9 ( V_14 ) ;
F_3 ( V_12 , V_1 -> V_4 + F_8 ( V_6 ) ) ;
}
static void F_10 ( struct V_1 * V_1 ,
T_2 V_6 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_6 ) ) ;
T_1 V_15 = V_1 -> V_16 * V_14 ;
V_4 &= ~ V_17 ;
V_4 |= F_11 ( V_15 ) ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_6 ) ) ;
if ( V_1 -> V_16 == V_18 ) {
V_1 -> V_16 = 0 ;
V_1 -> V_19 = 0 ;
F_12 ( L_1 ) ;
} else
V_1 -> V_16 ++ ;
}
static void F_13 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_14 ( V_8 . V_9 ) ) ;
V_4 &= ~ V_20 ;
V_4 |= F_15 ( V_1 -> V_19 ) ;
F_3 ( V_4 , V_1 -> V_4 + F_14 ( V_8 . V_9 ) ) ;
V_1 -> V_19 += ( V_8 . V_21 + 7 ) / 8 * V_14 ;
}
static void F_16 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
F_7 ( V_1 , V_8 . V_9 ) ;
F_10 ( V_1 , V_8 . V_9 ) ;
F_13 ( V_1 , V_8 ) ;
}
static void F_17 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
V_4 &= ~ V_22 ;
V_4 |= F_18 ( V_8 . type ) ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
}
static void F_19 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 ;
if ( ! V_8 . V_23 )
return;
V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
V_4 &= ~ V_24 ;
V_4 |= V_25 ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
}
static void F_20 ( struct V_1 * V_1 ,
T_2 V_6 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_6 ) ) ;
V_4 |= V_26 ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_6 ) ) ;
}
static void F_21 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_14 ( V_8 . V_9 ) ) ;
V_4 &= ~ V_27 ;
V_4 |= F_22 ( V_8 . V_21 ) ;
F_3 ( V_4 , V_1 -> V_4 + F_14 ( V_8 . V_9 ) ) ;
}
static void F_23 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
V_4 &= ~ F_24 ( 0x7 ) ;
V_4 |= F_24 ( V_8 . V_28 ) ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
}
static void F_25 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
V_4 &= ~ F_26 ( 0x3 ) ;
V_4 |= F_26 ( V_8 . V_29 ) ;
F_3 ( V_4 , V_1 -> V_4 + F_8 ( V_8 . V_9 ) ) ;
}
static void F_27 ( struct V_1 * V_1 ,
struct V_7 V_8 )
{
F_17 ( V_1 , V_8 ) ;
F_19 ( V_1 , V_8 ) ;
F_21 ( V_1 , V_8 ) ;
if ( V_8 . V_28 )
F_23 ( V_1 , V_8 ) ;
if ( V_8 . V_29 )
F_25 ( V_1 , V_8 ) ;
F_20 ( V_1 , V_8 . V_9 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
const struct V_30 * V_31 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
struct V_7 V_8 ;
V_6 -> V_6 . V_31 = V_31 ;
V_8 . V_28 = 0 ;
V_8 . V_19 = 0 ;
V_8 . V_29 = 0 ;
V_8 . type = V_31 -> V_32 & V_33 ;
V_8 . V_23 = ( V_31 -> V_34 & V_35 ) ? 1 : 0 ;
V_8 . V_21 = F_29 ( V_31 ) ;
V_8 . V_9 = V_31 -> V_34 & V_36 ;
if ( ( V_8 . type == V_37 ) ||
( V_8 . type == V_38 ) ) {
V_8 . V_28 = V_31 -> V_39 ;
if ( V_8 . type == V_38 )
V_8 . V_29 = F_30 ( V_31 ) ;
}
F_16 ( V_1 , V_8 ) ;
F_27 ( V_1 , V_8 ) ;
F_5 ( V_6 , V_8 ) ;
V_1 -> V_6 [ V_8 . V_9 ] = V_6 ;
return 0 ;
}
static int F_31 ( struct V_40 * V_41 ,
const struct V_30 * V_31 )
{
struct V_5 * V_6 ;
V_6 = F_32 ( V_41 , struct V_5 , V_6 ) ;
if ( V_6 -> V_1 -> V_42 ) {
V_6 -> V_1 -> V_16 = 0 ;
V_6 -> V_1 -> V_19 = 0 ;
V_6 -> V_1 -> V_42 = 0 ;
}
return F_28 ( V_6 , V_31 ) ;
}
static int F_33 ( struct V_40 * V_41 )
{
struct V_5 * V_6 ;
struct V_43 * V_44 ;
unsigned long V_45 ;
V_6 = F_32 ( V_41 , struct V_5 , V_6 ) ;
F_34 ( ! V_6 ) ;
while ( ! F_35 ( & V_6 -> V_46 ) ) {
V_44 = F_36 ( V_6 -> V_46 . V_47 , struct V_43 , V_46 ) ;
F_37 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
F_38 ( V_6 , V_44 , - V_49 ) ;
F_39 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
}
return F_6 ( V_6 ) ;
}
static struct V_50 * F_40 ( struct V_40 * V_41 ,
T_3 V_51 )
{
struct V_43 * V_44 ;
V_44 = F_41 ( sizeof( struct V_43 ) , V_51 ) ;
if ( ! V_44 )
return NULL ;
F_42 ( & V_44 -> V_46 ) ;
return & V_44 -> V_44 ;
}
static void F_43 ( struct V_40 * V_41 , struct V_50 * V_52 )
{
struct V_43 * V_44 ;
V_44 = F_32 ( V_52 , struct V_43 , V_44 ) ;
F_44 ( V_44 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
if ( V_6 -> V_9 ) {
F_1 ( V_1 , V_53 ,
F_46 ( V_6 -> V_9 ) ) ;
} else {
F_12 ( L_2 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
if ( V_6 -> V_9 ) {
F_4 ( V_1 , V_53 ,
F_46 ( V_6 -> V_9 ) ) ;
} else {
F_12 ( L_3 ) ;
return - V_54 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_1 , T_1 V_55 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_56 ) ;
V_4 &= ~ V_57 ;
V_4 |= F_49 ( V_55 ) ;
F_3 ( V_4 , V_1 -> V_4 + V_56 ) ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_43 * V_44 )
{
int V_58 = 0 ;
T_2 * V_59 ;
T_1 V_60 ;
struct V_1 * V_1 = V_6 -> V_1 ;
T_1 V_55 = V_44 -> V_44 . V_55 - V_44 -> V_44 . V_61 ;
V_59 = V_44 -> V_44 . V_62 + V_44 -> V_44 . V_61 ;
if ( V_55 > V_63 ) {
F_48 ( V_1 , V_63 ) ;
for ( V_58 = ( V_63 >> 2 ) ; V_58 > 0 ; V_58 -- ) {
V_60 = * V_59 | * ( V_59 + 1 ) << 8 | * ( V_59 + 2 ) << 16 |
* ( V_59 + 3 ) << 24 ;
F_3 ( V_60 , V_1 -> V_4 + V_64 ) ;
V_59 += 4 ;
}
V_44 -> V_44 . V_61 += V_63 ;
} else {
F_48 ( V_1 , V_55 ) ;
for ( V_58 = V_55 >> 2 ; V_58 > 0 ; V_58 -- ) {
V_60 = * V_59 | * ( V_59 + 1 ) << 8 | * ( V_59 + 2 ) << 16 |
* ( V_59 + 3 ) << 24 ;
F_51 ( V_65 L_4 , V_60 ) ;
F_3 ( V_60 , V_1 -> V_4 + V_64 ) ;
V_59 = V_59 + 4 ;
}
switch ( V_55 % 4 ) {
case 1 :
V_60 = * V_59 ;
F_51 ( V_65 L_4 , V_60 ) ;
F_3 ( V_60 , V_1 -> V_4 + V_64 ) ;
break;
case 2 :
V_60 = * V_59 | * ( V_59 + 1 ) << 8 ;
F_51 ( V_65 L_4 , V_60 ) ;
F_3 ( V_60 , V_1 -> V_4 + V_64 ) ;
break;
case 3 :
V_60 = * V_59 | * ( V_59 + 1 ) << 8 | * ( V_59 + 2 ) << 16 ;
F_51 ( V_65 L_4 , V_60 ) ;
F_3 ( V_60 , V_1 -> V_4 + V_64 ) ;
break;
default:
break;
}
V_44 -> V_44 . V_61 += V_55 ;
}
}
static void F_52 ( struct V_1 * V_1 , T_2 V_6 )
{
F_1 ( V_1 , F_53 ( V_6 ) ,
V_66 ) ;
}
static void F_54 ( struct V_1 * V_1 , T_2 V_6 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_53 ( V_6 ) ) ;
if ( V_4 & V_66 ) {
F_51 ( V_65 L_5 , V_6 ) ;
V_4 |= V_67 ;
F_3 ( V_4 , V_1 -> V_4 + F_53 ( V_6 ) ) ;
}
}
static void F_55 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
if ( V_6 -> V_1 -> V_68 ) {
if ( V_44 -> V_44 . V_55 ) {
F_50 ( V_6 , V_44 ) ;
} else
F_51 ( V_65 L_6 ,
V_69 , V_44 -> V_44 . V_55 ) ;
if ( ( V_44 -> V_44 . V_55 == V_44 -> V_44 . V_61 ) ||
( V_44 -> V_44 . V_61 < V_6 -> V_6 . V_21 ) )
F_38 ( V_6 , V_44 , 0 ) ;
} else {
if ( ! V_44 -> V_44 . V_55 )
F_38 ( V_6 , V_44 , 0 ) ;
else
F_1 ( V_6 -> V_1 , V_70 ,
V_71 ) ;
}
}
static int F_56 ( struct V_40 * V_41 , struct V_50 * V_52 ,
T_3 V_51 )
{
struct V_5 * V_6 ;
struct V_43 * V_44 ;
unsigned long V_45 ;
int V_72 = 0 ;
V_6 = F_32 ( V_41 , struct V_5 , V_6 ) ;
V_44 = F_32 ( V_52 , struct V_43 , V_44 ) ;
if ( V_6 -> V_1 -> V_73 . V_74 == V_75 )
return - V_76 ;
F_37 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
if ( F_35 ( & V_6 -> V_46 ) )
V_72 = 1 ;
F_57 ( & V_44 -> V_46 , & V_6 -> V_46 ) ;
V_44 -> V_44 . V_61 = 0 ;
V_44 -> V_44 . V_77 = - V_78 ;
if ( V_6 -> V_6 . V_31 == NULL )
F_55 ( V_6 , V_44 ) ;
else if ( V_72 && ! V_6 -> V_10 )
F_45 ( V_6 ) ;
F_39 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
return 0 ;
}
static int F_58 ( struct V_40 * V_41 , struct V_50 * V_52 )
{
struct V_5 * V_6 ;
struct V_43 * V_44 ;
unsigned long V_45 ;
V_6 = F_32 ( V_41 , struct V_5 , V_6 ) ;
V_44 = F_32 ( V_52 , struct V_43 , V_44 ) ;
F_37 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
if ( ! F_35 ( & V_6 -> V_46 ) )
F_38 ( V_6 , V_44 , - V_49 ) ;
F_39 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
return 0 ;
}
static int F_59 ( struct V_40 * V_41 , int V_3 , int V_79 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_45 ;
int V_80 = 0 ;
V_6 = F_32 ( V_41 , struct V_5 , V_6 ) ;
V_1 = V_6 -> V_1 ;
F_37 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
if ( ! F_35 ( & V_6 -> V_46 ) ) {
V_80 = - V_81 ;
goto V_82;
}
if ( V_3 ) {
F_52 ( V_1 , V_6 -> V_9 ) ;
V_6 -> V_10 = 1 ;
if ( V_79 )
V_6 -> V_11 = 1 ;
} else {
F_54 ( V_1 , V_6 -> V_9 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
}
V_82:
F_39 ( & V_6 -> V_1 -> V_48 , V_45 ) ;
return V_80 ;
}
static int F_60 ( struct V_40 * V_41 , int V_3 )
{
return F_59 ( V_41 , V_3 , 0 ) ;
}
static int F_61 ( struct V_40 * V_41 )
{
return F_59 ( V_41 , 1 , 1 ) ;
}
static void F_62 ( struct V_40 * V_41 )
{
}
static void F_63 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
F_3 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static void F_64 ( void )
{
}
static void F_65 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_56 ,
V_83 ) ;
}
static void F_66 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_56 ,
V_84 ) ;
}
static void F_67 ( struct V_1 * V_1 ,
T_2 * V_85 , T_1 V_55 )
{
int V_58 = 0 ;
T_2 * V_59 ;
T_1 V_60 ;
V_59 = V_85 ;
for ( V_58 = ( V_55 >> 2 ) ; V_58 > 0 ; V_58 -- ) {
V_60 = F_2 ( V_1 -> V_4 + V_64 ) ;
F_51 ( V_65 L_4 , V_60 ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
* ( V_59 + 2 ) = ( V_60 >> 16 ) & 0xFF ;
* ( V_59 + 3 ) = ( V_60 >> 24 ) & 0xFF ;
V_59 = V_59 + 4 ;
}
switch ( V_55 % 4 ) {
case 1 :
V_60 = F_2 ( V_1 -> V_4 + V_64 ) ;
F_51 ( V_65 L_4 , V_60 ) ;
* V_59 = V_60 & 0xFF ;
break;
case 2 :
V_60 = F_2 ( V_1 -> V_4 + V_64 ) ;
F_51 ( V_65 L_4 , V_60 ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
break;
case 3 :
V_60 = F_2 ( V_1 -> V_4 + V_64 ) ;
F_51 ( V_65 L_4 , V_60 ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
* ( V_59 + 2 ) = ( V_60 >> 16 ) & 0xFF ;
break;
default:
break;
}
}
static void F_68 ( struct V_5 * V_6 ,
struct V_43 * V_44 ,
T_1 V_55 )
{
int V_58 = 0 ;
T_2 * V_59 ;
T_1 V_60 , V_4 ;
struct V_1 * V_1 = V_6 -> V_1 ;
V_59 = V_44 -> V_44 . V_62 + V_44 -> V_44 . V_61 ;
V_44 -> V_44 . V_61 += V_55 ;
if ( V_44 -> V_44 . V_61 > V_44 -> V_44 . V_55 )
F_51 ( V_65 L_7 ) ;
for ( V_58 = ( V_55 >> 2 ) ; V_58 > 0 ; V_58 -- ) {
V_60 = F_2 ( V_1 -> V_4 +
F_69 ( V_6 -> V_9 ) ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
* ( V_59 + 2 ) = ( V_60 >> 16 ) & 0xFF ;
* ( V_59 + 3 ) = ( V_60 >> 24 ) & 0xFF ;
V_59 = V_59 + 4 ;
}
switch ( V_55 % 4 ) {
case 1 :
V_60 = F_2 ( V_1 -> V_4 +
F_69 ( V_6 -> V_9 ) ) ;
* V_59 = V_60 & 0xFF ;
break;
case 2 :
V_60 = F_2 ( V_1 -> V_4 +
F_69 ( V_6 -> V_9 ) ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
break;
case 3 :
V_60 = F_2 ( V_1 -> V_4 +
F_69 ( V_6 -> V_9 ) ) ;
* V_59 = V_60 & 0xFF ;
* ( V_59 + 1 ) = ( V_60 >> 8 ) & 0xFF ;
* ( V_59 + 2 ) = ( V_60 >> 16 ) & 0xFF ;
break;
default:
break;
}
do {
V_4 = F_2 ( V_1 -> V_4 + V_86 ) ;
V_4 &= V_87 ;
if ( V_58 )
F_51 ( V_88 L_8 ) ;
V_58 ++ ;
} while ( ! V_4 );
}
static T_2 F_70 ( struct V_1 * V_1 , T_2 V_6 )
{
T_2 V_3 ;
T_1 V_4 = F_2 ( V_1 -> V_4 + F_53 ( V_6 ) ) ;
V_3 = V_4 & V_66 ;
return V_3 ;
}
static T_2 F_71 ( struct V_1 * V_1 )
{
T_2 V_3 ;
T_1 V_4 = F_2 ( V_1 -> V_4 + V_56 ) ;
V_3 = ( V_4 & V_83 ) >> 1 ;
return V_3 ;
}
static void F_72 ( struct V_1 * V_1 )
{
F_65 ( V_1 ) ;
F_51 ( V_65 L_9 ) ;
}
static void F_73 ( struct V_1 * V_1 , struct V_89 * V_90 )
__releases( V_1 -> V_48 )
__acquires( V_1 -> V_48 )
{
T_2 V_6 ;
T_4 V_77 = 0 ;
T_4 V_91 = V_90 -> V_92 ;
switch ( V_90 -> V_93 & V_94 ) {
case V_95 :
V_77 = 1 << V_96 ;
break;
case V_97 :
V_77 = 0 ;
break;
case V_98 :
V_6 = V_91 & V_36 ;
if ( V_6 ) {
if ( F_70 ( V_1 , V_6 ) )
V_77 = 1 << V_99 ;
} else {
if ( F_71 ( V_1 ) )
V_77 = 0 ;
}
break;
default:
F_72 ( V_1 ) ;
return;
}
V_1 -> V_100 = F_74 ( V_77 ) ;
V_1 -> V_101 -> V_62 = & V_1 -> V_100 ;
V_1 -> V_101 -> V_55 = 2 ;
F_75 ( & V_1 -> V_48 ) ;
F_56 ( V_1 -> V_73 . V_102 , V_1 -> V_101 , V_103 ) ;
F_76 ( & V_1 -> V_48 ) ;
}
static void F_77 ( struct V_1 * V_1 , struct V_89 * V_90 )
{
T_2 V_6 ;
switch ( V_90 -> V_93 & V_94 ) {
case V_95 :
F_66 ( V_1 ) ;
break;
case V_97 :
F_66 ( V_1 ) ;
break;
case V_98 : {
T_4 V_91 = F_78 ( V_90 -> V_92 ) ;
V_6 = V_91 & V_36 ;
if ( V_6 )
F_52 ( V_1 , V_6 ) ;
else
F_65 ( V_1 ) ;
F_66 ( V_1 ) ;
}
break;
default:
F_72 ( V_1 ) ;
break;
}
}
static void F_79 ( struct V_1 * V_1 , T_2 V_6 )
{
F_1 ( V_1 , F_53 ( V_6 ) ,
V_104 ) ;
}
static void F_80 ( struct V_1 * V_1 , struct V_89 * V_90 )
{
struct V_5 * V_6 =
V_1 -> V_6 [ V_90 -> V_92 & V_36 ] ;
switch ( V_90 -> V_93 & V_94 ) {
case V_95 :
F_66 ( V_1 ) ;
break;
case V_97 :
F_66 ( V_1 ) ;
break;
case V_98 :
if ( V_90 -> V_92 & V_36 ) {
if ( V_6 -> V_11 ) {
F_66 ( V_1 ) ;
break;
}
if ( V_6 -> V_10 ) {
V_6 -> V_10 = 0 ;
F_79 ( V_1 , V_6 -> V_9 ) ;
F_54 ( V_1 , V_6 -> V_9 ) ;
if ( ! F_35 ( & V_6 -> V_46 ) )
F_45 ( V_6 ) ;
}
}
F_66 ( V_1 ) ;
break;
default:
F_72 ( V_1 ) ;
break;
}
}
static void F_81 ( struct V_1 * V_1 , T_4 V_105 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_106 ) ;
V_4 &= ~ V_107 ;
V_4 |= F_82 ( V_105 ) ;
F_3 ( V_4 , V_1 -> V_4 + V_106 ) ;
}
static void F_83 ( struct V_1 * V_1 , struct V_89 * V_90 )
{
if ( V_90 -> V_108 >= 0x0100 )
F_72 ( V_1 ) ;
else {
F_81 ( V_1 , V_90 -> V_108 ) ;
F_66 ( V_1 ) ;
}
}
static int F_84 ( struct V_1 * V_1 , struct V_89 * V_90 )
{
T_2 * V_109 = ( T_2 * ) V_90 ;
T_2 V_80 = 0 ;
T_2 V_58 = 0 ;
F_67 ( V_1 , V_109 , 8 ) ;
V_1 -> V_68 = V_90 -> V_93 & V_110 ;
V_1 -> V_111 = V_90 -> V_112 ;
if ( ( V_90 -> V_93 & V_113 ) == V_114 ) {
switch ( V_90 -> V_115 ) {
case V_116 :
F_73 ( V_1 , V_90 ) ;
break;
case V_117 :
F_80 ( V_1 , V_90 ) ;
break;
case V_118 :
F_77 ( V_1 , V_90 ) ;
break;
case V_119 :
F_83 ( V_1 , V_90 ) ;
break;
case V_120 :
F_1 ( V_1 , V_106 ,
V_121 ) ;
for ( V_58 = 1 ; V_58 <= V_122 ; V_58 ++ )
F_79 ( V_1 , V_58 ) ;
V_1 -> V_42 = 1 ;
V_80 = 1 ;
break;
default:
V_80 = 1 ;
break;
}
} else
V_80 = 1 ;
return V_80 ;
}
static void F_38 ( struct V_5 * V_6 , struct V_43 * V_44 ,
int V_77 )
{
F_85 ( & V_44 -> V_46 ) ;
if ( V_6 -> V_1 -> V_73 . V_74 == V_75 )
V_44 -> V_44 . V_77 = - V_76 ;
else
V_44 -> V_44 . V_77 = V_77 ;
F_75 ( & V_6 -> V_1 -> V_48 ) ;
F_86 ( & V_6 -> V_6 , & V_44 -> V_44 ) ;
F_76 ( & V_6 -> V_1 -> V_48 ) ;
if ( V_6 -> V_9 ) {
F_47 ( V_6 ) ;
if ( ! F_35 ( & V_6 -> V_46 ) )
F_45 ( V_6 ) ;
} else
F_66 ( V_6 -> V_1 ) ;
}
static void F_87 ( struct V_5 * V_6 , T_5 V_123 ,
T_1 V_124 )
{
T_1 V_3 ;
T_1 V_4 ;
do {
V_4 = F_2 ( V_6 -> V_1 -> V_4 +
F_88 ( V_6 -> V_9 ) ) ;
V_4 &= V_125 ;
} while ( V_4 );
F_3 ( V_123 , V_6 -> V_1 -> V_4 + F_89 ( V_6 -> V_9 ) ) ;
V_3 = F_90 ( V_124 ) | V_125 |
V_126 | V_127 | V_128 ;
F_3 ( V_3 , V_6 -> V_1 -> V_4 + F_88 ( V_6 -> V_9 ) ) ;
F_3 ( 0x0 , V_6 -> V_1 -> V_4 + F_91 ( V_6 -> V_9 ) ) ;
F_1 ( V_6 -> V_1 , V_129 ,
F_92 ( V_6 -> V_9 ) ) ;
}
static void F_93 ( struct V_5 * V_6 )
{
T_1 V_4 ;
do {
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_86 ) ;
if ( ( V_4 & V_130 ) ||
( V_4 & V_131 ) ||
( V_4 & V_132 ) ||
( V_4 & V_133 )
)
goto V_134;
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_135 ) ;
V_4 &= F_94 ( V_6 -> V_9 ) ;
} while ( ! V_4 );
F_63 ( V_6 -> V_1 , V_135 ,
F_94 ( V_6 -> V_9 ) ) ;
return;
V_134:
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_53 ) ;
V_4 &= ~ F_95 ( V_6 -> V_9 ) ;
F_3 ( V_4 , V_6 -> V_1 -> V_4 + V_53 ) ;
}
static void F_96 ( struct V_5 * V_6 ,
struct V_43 * V_44 )
{
int V_80 ;
V_80 = F_97 ( & V_6 -> V_1 -> V_73 ,
& V_44 -> V_44 , V_136 ) ;
if ( V_80 )
return;
F_1 ( V_6 -> V_1 , V_53 ,
F_95 ( V_6 -> V_9 ) ) ;
F_87 ( V_6 , V_44 -> V_44 . V_137 , V_44 -> V_44 . V_55 ) ;
F_93 ( V_6 ) ;
F_98 ( & V_6 -> V_1 -> V_73 ,
& V_44 -> V_44 , V_136 ) ;
}
static void F_99 ( struct V_5 * V_6 )
{
struct V_43 * V_44 = F_36 ( V_6 -> V_46 . V_47 ,
struct V_43 , V_46 ) ;
if ( V_44 -> V_44 . V_55 )
F_96 ( V_6 , V_44 ) ;
F_38 ( V_6 , V_44 , 0 ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
struct V_43 * V_44 = F_36 ( V_6 -> V_46 . V_47 ,
struct V_43 , V_46 ) ;
T_1 V_4 = F_2 ( V_1 -> V_4 + F_101 ( V_6 -> V_9 ) ) ;
T_1 V_55 = V_4 & V_138 ;
F_68 ( V_6 , V_44 , V_55 ) ;
if ( ( V_44 -> V_44 . V_55 == V_44 -> V_44 . V_61 ) || ( V_55 < V_6 -> V_6 . V_21 ) )
F_38 ( V_6 , V_44 , 0 ) ;
}
static void F_102 ( struct V_1 * V_1 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_139 ) ;
switch ( V_4 & V_140 ) {
case V_141 :
V_1 -> V_73 . V_74 = V_142 ;
break;
case V_143 :
V_1 -> V_73 . V_74 = V_144 ;
break;
case V_145 :
V_1 -> V_73 . V_74 = V_146 ;
break;
default:
V_1 -> V_73 . V_74 = V_75 ;
break;
}
F_51 ( V_88 L_10 , ( V_4 & V_140 ) ) ;
}
static void F_103 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_6 [ 0 ] ;
T_1 V_4 ;
if ( ! F_35 ( & V_6 -> V_46 ) ) {
struct V_43 * V_44 ;
V_44 = F_104 ( & V_6 -> V_46 ,
struct V_43 , V_46 ) ;
if ( V_44 -> V_44 . V_55 )
F_67 ( V_6 -> V_1 , V_44 -> V_44 . V_62 ,
V_44 -> V_44 . V_55 ) ;
F_38 ( V_6 , V_44 , 0 ) ;
V_4 = F_2 ( V_1 -> V_4 + V_70 ) ;
V_4 &= ~ V_71 ;
F_3 ( V_4 , V_1 -> V_4 + V_70 ) ;
} else
F_12 ( L_11 , V_69 ) ;
}
static void F_105 ( struct V_1 * V_1 )
{
struct V_43 * V_44 ;
struct V_5 * V_6 = V_1 -> V_6 [ 0 ] ;
if ( ( ! F_35 ( & V_6 -> V_46 ) ) && ( V_1 -> V_68 ) ) {
V_44 = F_36 ( V_6 -> V_46 . V_47 ,
struct V_43 , V_46 ) ;
if ( V_44 -> V_44 . V_55 )
F_50 ( V_6 , V_44 ) ;
if ( ( V_44 -> V_44 . V_55 - V_44 -> V_44 . V_61 ) < V_6 -> V_6 . V_21 )
F_38 ( V_6 , V_44 , 0 ) ;
} else
F_66 ( V_1 ) ;
}
static void F_106 ( void )
{
}
static void F_107 ( void )
{
}
static void F_108 ( void )
{
}
static void F_109 ( void )
{
}
static T_6 F_110 ( int V_147 , void * V_148 )
{
struct V_1 * V_1 = V_148 ;
T_1 V_149 = F_2 ( V_1 -> V_4 + V_86 ) ;
T_1 V_150 = F_2 ( V_1 -> V_4 + V_70 ) ;
T_1 V_151 = F_2 ( V_1 -> V_4 + V_135 ) ;
T_1 V_152 = F_2 ( V_1 -> V_4 + V_53 ) ;
struct V_89 V_90 ;
T_2 V_153 ;
T_1 V_4 ;
int V_58 ;
F_76 ( & V_1 -> V_48 ) ;
V_149 &= V_150 ;
V_151 &= V_152 ;
if ( V_149 & V_131 ) {
F_63 ( V_1 , V_86 ,
V_131 ) ;
F_51 ( V_88 L_12 ) ;
F_64 () ;
}
if ( V_149 & V_132 ) {
F_63 ( V_1 , V_86 ,
V_132 ) ;
F_51 ( V_88 L_13 ) ;
F_64 () ;
}
if ( V_149 & V_133 ) {
F_63 ( V_1 , V_86 ,
V_133 ) ;
F_64 () ;
}
if ( V_149 & V_154 ) {
F_63 ( V_1 , V_86 ,
V_154 ) ;
F_51 ( V_88 L_14 ) ;
}
if ( V_149 & V_130 ) {
F_63 ( V_1 , V_86 ,
V_130 ) ;
F_51 ( V_88 L_15 ) ;
}
if ( V_149 & V_155 ) {
F_63 ( V_1 , V_86 ,
V_155 ) ;
}
if ( V_149 & V_156 ) {
F_63 ( V_1 , V_86 ,
V_156 ) ;
}
if ( V_149 & V_157 ) {
F_63 ( V_1 , V_86 ,
V_157 ) ;
}
if ( V_149 & V_158 ) {
F_63 ( V_1 , V_86 ,
V_158 ) ;
}
if ( V_149 & V_159 ) {
F_63 ( V_1 , V_86 ,
V_159 ) ;
}
if ( V_149 & V_160 ) {
F_63 ( V_1 , V_86 ,
V_160 ) ;
F_51 ( V_88 L_16 ) ;
}
if ( V_149 & V_161 ) {
F_63 ( V_1 , V_86 ,
V_161 ) ;
F_51 ( V_88 L_17 ) ;
}
if ( V_149 & V_162 ) {
F_63 ( V_1 , V_86 ,
V_162 ) ;
F_51 ( V_88 L_18 ) ;
}
if ( V_149 & V_163 ) {
F_63 ( V_1 , V_86 ,
V_163 ) ;
F_51 ( V_88 L_19 ) ;
F_1 ( V_1 , V_164 ,
V_165 ) ;
}
if ( V_149 & V_166 ) {
F_63 ( V_1 , V_86 ,
V_166 ) ;
F_51 ( V_88 L_20 ) ;
}
if ( V_149 & V_167 ) {
F_63 ( V_1 , V_86 ,
V_167 ) ;
F_51 ( V_88 L_21 ) ;
}
if ( V_149 & V_168 ) {
F_63 ( V_1 , V_86 ,
V_168 ) ;
F_51 ( V_88 L_22 ) ;
}
if ( V_149 & V_169 ) {
F_63 ( V_1 , V_86 ,
V_169 ) ;
F_51 ( V_88 L_23 ) ;
}
if ( V_149 & V_170 ) {
F_63 ( V_1 , V_86 ,
V_170 ) ;
F_51 ( V_88 L_24 ) ;
}
if ( V_149 & V_171 ) {
F_63 ( V_1 , V_86 ,
V_171 ) ;
F_102 ( V_1 ) ;
}
if ( V_149 & V_172 ) {
F_65 ( V_1 ) ;
F_51 ( V_88 L_25 ) ;
}
if ( V_149 & V_173 ) {
F_51 ( V_88 L_26 ) ;
if ( F_84 ( V_1 , & V_90 ) ) {
F_75 ( & V_1 -> V_48 ) ;
if ( V_1 -> V_174 -> V_175 ( & V_1 -> V_73 , & V_90 ) < 0 )
F_65 ( V_1 ) ;
F_76 ( & V_1 -> V_48 ) ;
}
}
if ( V_149 & V_176 )
F_51 ( V_88 L_27 ) ;
if ( V_149 & V_177 ) {
F_51 ( V_88 L_28 ) ;
F_103 ( V_1 ) ;
}
if ( V_149 & V_178 ) {
F_51 ( V_88 L_29 ) ;
F_105 ( V_1 ) ;
}
if ( V_149 & V_179 )
F_109 () ;
if ( V_149 & V_180 )
F_108 () ;
if ( V_149 & V_181 )
F_107 () ;
if ( V_149 & V_182 )
F_106 () ;
if ( V_151 ) {
for ( V_58 = 1 ; V_58 < V_122 ; V_58 ++ ) {
if ( V_151 & F_111 ( V_58 ) ) {
V_4 = F_2 ( V_1 -> V_4 +
F_8 ( V_58 ) ) ;
V_153 = ( V_4 & V_25 ) ? 1 : 0 ;
if ( V_153 )
F_99 ( V_1 -> V_6 [ V_58 ] ) ;
else
F_100 ( V_1 -> V_6 [ V_58 ] ) ;
}
}
}
F_75 ( & V_1 -> V_48 ) ;
return V_183 ;
}
static void F_112 ( struct V_1 * V_1 ,
T_1 time )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_184 ) ;
V_4 &= ~ 0xff ;
V_4 |= F_113 ( time ) ;
F_3 ( V_4 , V_1 -> V_4 + V_184 ) ;
}
static void F_114 ( struct V_1 * V_1 ,
T_1 time )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_184 ) ;
V_4 &= ~ ( 0xff << 8 ) ;
V_4 |= F_115 ( time ) ;
F_3 ( V_4 , V_1 -> V_4 + V_184 ) ;
}
static void F_116 ( struct V_1 * V_1 )
{
T_1 V_4 ;
T_1 V_185 = 0 ;
T_1 V_12 = 0 ;
V_185 = V_12 = V_186 | V_187 ;
V_4 = F_2 ( V_1 -> V_4 + V_188 ) ;
V_4 &= ~ V_185 ;
V_4 |= V_12 ;
F_3 ( V_4 , V_1 -> V_4 + V_188 ) ;
V_185 = V_12 = V_189 ;
V_4 = F_2 ( V_1 -> V_4 + V_190 ) ;
V_4 &= ~ V_185 ;
V_4 |= V_12 ;
F_3 ( V_4 , V_1 -> V_4 + V_190 ) ;
F_112 ( V_1 , 0xff ) ;
F_114 ( V_1 , 0xff ) ;
F_3 ( 0xcfffff9f , V_1 -> V_4 + V_70 ) ;
}
static int F_117 ( struct V_191 * V_192 ,
struct V_193 * V_174 )
{
struct V_1 * V_1 = F_118 ( V_192 ) ;
V_174 -> V_174 . V_194 = NULL ;
V_1 -> V_174 = V_174 ;
return 0 ;
}
static int F_119 ( struct V_191 * V_192 )
{
struct V_1 * V_1 = F_118 ( V_192 ) ;
F_116 ( V_1 ) ;
V_1 -> V_174 = NULL ;
return 0 ;
}
static int F_120 ( struct V_191 * V_195 , int V_196 )
{
return 0 ;
}
static int F_121 ( struct V_197 * V_198 )
{
struct V_1 * V_1 = F_122 ( V_198 ) ;
F_123 ( & V_1 -> V_73 ) ;
F_124 ( V_1 -> V_4 ) ;
F_125 ( F_126 ( V_198 , 0 ) , V_1 ) ;
F_43 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_1 -> V_101 ) ;
F_44 ( V_1 ) ;
return 0 ;
}
static int F_127 ( struct V_197 * V_198 )
{
struct V_199 * V_200 , * V_201 , * V_202 ;
void T_7 * V_4 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_5 * V_41 [ V_122 ] ;
int V_80 = 0 ;
int V_58 ;
V_200 = F_128 ( V_198 , V_203 , 0 ) ;
if ( ! V_200 ) {
V_80 = - V_204 ;
F_12 ( L_30 ) ;
goto V_205;
}
V_201 = F_128 ( V_198 , V_206 , 0 ) ;
if ( ! V_201 ) {
V_80 = - V_204 ;
F_129 ( & V_198 -> V_207 ,
L_31 ) ;
goto V_205;
}
V_202 = F_128 ( V_198 , V_206 , 1 ) ;
if ( ! V_202 ) {
V_80 = - V_204 ;
F_129 ( & V_198 -> V_207 ,
L_32 ) ;
goto V_205;
}
V_4 = F_130 ( V_200 -> V_208 , F_131 ( V_200 ) ) ;
if ( V_4 == NULL ) {
V_80 = - V_209 ;
F_12 ( L_33 ) ;
goto V_205;
}
V_1 = F_41 ( sizeof( struct V_1 ) , V_103 ) ;
if ( V_1 == NULL ) {
V_80 = - V_209 ;
goto V_205;
}
for ( V_58 = 0 ; V_58 < V_122 ; V_58 ++ ) {
V_41 [ V_58 ] = F_41 ( sizeof( struct V_5 ) , V_103 ) ;
if ( V_41 [ V_58 ] == NULL ) {
V_80 = - V_209 ;
goto V_205;
}
V_1 -> V_6 [ V_58 ] = V_41 [ V_58 ] ;
}
F_132 ( & V_1 -> V_48 ) ;
F_133 ( V_198 , V_1 ) ;
V_1 -> V_73 . V_210 = & V_211 ;
V_1 -> V_73 . V_212 = V_144 ;
V_1 -> V_73 . V_213 = V_214 ;
V_1 -> V_4 = V_4 ;
V_80 = F_134 ( V_201 -> V_208 , F_110 , V_215 ,
V_214 , V_1 ) ;
if ( V_80 < 0 ) {
F_12 ( L_34 , V_80 ) ;
goto V_205;
}
V_80 = F_134 ( V_202 -> V_208 , F_110 ,
V_215 , V_214 , V_1 ) ;
if ( V_80 < 0 ) {
F_12 ( L_35 , V_80 ) ;
goto V_205;
}
F_42 ( & V_1 -> V_73 . V_216 ) ;
for ( V_58 = 0 ; V_58 < V_122 ; V_58 ++ ) {
struct V_5 * V_6 = V_1 -> V_6 [ V_58 ] ;
if ( V_58 != 0 ) {
F_42 ( & V_1 -> V_6 [ V_58 ] -> V_6 . V_216 ) ;
F_57 ( & V_1 -> V_6 [ V_58 ] -> V_6 . V_216 ,
& V_1 -> V_73 . V_216 ) ;
}
V_6 -> V_1 = V_1 ;
F_42 ( & V_6 -> V_46 ) ;
V_6 -> V_6 . V_213 = V_217 [ V_58 ] ;
V_6 -> V_6 . V_210 = & V_218 ;
F_135 ( & V_6 -> V_6 , V_219 ) ;
if ( V_58 == 0 ) {
V_6 -> V_6 . V_220 . V_221 = true ;
} else {
V_6 -> V_6 . V_220 . V_222 = true ;
V_6 -> V_6 . V_220 . V_223 = true ;
V_6 -> V_6 . V_220 . V_224 = true ;
}
V_6 -> V_6 . V_220 . V_23 = true ;
V_6 -> V_6 . V_220 . V_225 = true ;
}
F_135 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_226 ) ;
V_1 -> V_6 [ 0 ] -> V_9 = 0 ;
V_1 -> V_73 . V_102 = & V_1 -> V_6 [ 0 ] -> V_6 ;
F_42 ( & V_1 -> V_73 . V_102 -> V_216 ) ;
V_1 -> V_101 = F_40 ( & V_1 -> V_6 [ 0 ] -> V_6 ,
V_103 ) ;
if ( V_1 -> V_101 == NULL ) {
V_80 = - V_209 ;
goto V_227;
}
F_116 ( V_1 ) ;
V_80 = F_136 ( & V_198 -> V_207 , & V_1 -> V_73 ) ;
if ( V_80 )
goto V_228;
F_137 ( & V_198 -> V_207 , L_36 , V_229 ) ;
return 0 ;
V_228:
F_43 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_1 -> V_101 ) ;
V_227:
F_125 ( V_201 -> V_208 , V_1 ) ;
V_205:
if ( V_1 ) {
if ( V_1 -> V_101 )
F_43 ( & V_1 -> V_6 [ 0 ] -> V_6 ,
V_1 -> V_101 ) ;
F_44 ( V_1 ) ;
}
if ( V_4 )
F_124 ( V_4 ) ;
return V_80 ;
}
