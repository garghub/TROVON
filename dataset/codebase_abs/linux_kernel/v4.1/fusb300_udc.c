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
V_8 . V_29 = ( ( V_31 -> V_40 & 0x1800 ) >> 11 ) ;
}
F_16 ( V_1 , V_8 ) ;
F_27 ( V_1 , V_8 ) ;
F_5 ( V_6 , V_8 ) ;
V_1 -> V_6 [ V_8 . V_9 ] = V_6 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 ,
const struct V_30 * V_31 )
{
struct V_5 * V_6 ;
V_6 = F_31 ( V_42 , struct V_5 , V_6 ) ;
if ( V_6 -> V_1 -> V_43 ) {
V_6 -> V_1 -> V_16 = 0 ;
V_6 -> V_1 -> V_19 = 0 ;
V_6 -> V_1 -> V_43 = 0 ;
}
return F_28 ( V_6 , V_31 ) ;
}
static int F_32 ( struct V_41 * V_42 )
{
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
V_6 = F_31 ( V_42 , struct V_5 , V_6 ) ;
F_33 ( ! V_6 ) ;
while ( ! F_34 ( & V_6 -> V_47 ) ) {
V_45 = F_35 ( V_6 -> V_47 . V_48 , struct V_44 , V_47 ) ;
F_36 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
F_37 ( V_6 , V_45 , - V_50 ) ;
F_38 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
}
return F_6 ( V_6 ) ;
}
static struct V_51 * F_39 ( struct V_41 * V_42 ,
T_3 V_52 )
{
struct V_44 * V_45 ;
V_45 = F_40 ( sizeof( struct V_44 ) , V_52 ) ;
if ( ! V_45 )
return NULL ;
F_41 ( & V_45 -> V_47 ) ;
return & V_45 -> V_45 ;
}
static void F_42 ( struct V_41 * V_42 , struct V_51 * V_53 )
{
struct V_44 * V_45 ;
V_45 = F_31 ( V_53 , struct V_44 , V_45 ) ;
F_43 ( V_45 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
if ( V_6 -> V_9 ) {
F_1 ( V_1 , V_54 ,
F_45 ( V_6 -> V_9 ) ) ;
} else {
F_12 ( L_2 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
if ( V_6 -> V_9 ) {
F_4 ( V_1 , V_54 ,
F_45 ( V_6 -> V_9 ) ) ;
} else {
F_12 ( L_3 ) ;
return - V_55 ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_1 , T_1 V_56 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_57 ) ;
V_4 &= ~ V_58 ;
V_4 |= F_48 ( V_56 ) ;
F_3 ( V_4 , V_1 -> V_4 + V_57 ) ;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
int V_59 = 0 ;
T_2 * V_60 ;
T_1 V_61 ;
struct V_1 * V_1 = V_6 -> V_1 ;
T_1 V_56 = V_45 -> V_45 . V_56 - V_45 -> V_45 . V_62 ;
V_60 = V_45 -> V_45 . V_63 + V_45 -> V_45 . V_62 ;
if ( V_56 > V_64 ) {
F_47 ( V_1 , V_64 ) ;
for ( V_59 = ( V_64 >> 2 ) ; V_59 > 0 ; V_59 -- ) {
V_61 = * V_60 | * ( V_60 + 1 ) << 8 | * ( V_60 + 2 ) << 16 |
* ( V_60 + 3 ) << 24 ;
F_3 ( V_61 , V_1 -> V_4 + V_65 ) ;
V_60 += 4 ;
}
V_45 -> V_45 . V_62 += V_64 ;
} else {
F_47 ( V_1 , V_56 ) ;
for ( V_59 = V_56 >> 2 ; V_59 > 0 ; V_59 -- ) {
V_61 = * V_60 | * ( V_60 + 1 ) << 8 | * ( V_60 + 2 ) << 16 |
* ( V_60 + 3 ) << 24 ;
F_50 ( V_66 L_4 , V_61 ) ;
F_3 ( V_61 , V_1 -> V_4 + V_65 ) ;
V_60 = V_60 + 4 ;
}
switch ( V_56 % 4 ) {
case 1 :
V_61 = * V_60 ;
F_50 ( V_66 L_4 , V_61 ) ;
F_3 ( V_61 , V_1 -> V_4 + V_65 ) ;
break;
case 2 :
V_61 = * V_60 | * ( V_60 + 1 ) << 8 ;
F_50 ( V_66 L_4 , V_61 ) ;
F_3 ( V_61 , V_1 -> V_4 + V_65 ) ;
break;
case 3 :
V_61 = * V_60 | * ( V_60 + 1 ) << 8 | * ( V_60 + 2 ) << 16 ;
F_50 ( V_66 L_4 , V_61 ) ;
F_3 ( V_61 , V_1 -> V_4 + V_65 ) ;
break;
default:
break;
}
V_45 -> V_45 . V_62 += V_56 ;
}
}
static void F_51 ( struct V_1 * V_1 , T_2 V_6 )
{
F_1 ( V_1 , F_52 ( V_6 ) ,
V_67 ) ;
}
static void F_53 ( struct V_1 * V_1 , T_2 V_6 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + F_52 ( V_6 ) ) ;
if ( V_4 & V_67 ) {
F_50 ( V_66 L_5 , V_6 ) ;
V_4 |= V_68 ;
F_3 ( V_4 , V_1 -> V_4 + F_52 ( V_6 ) ) ;
}
}
static void F_54 ( struct V_5 * V_6 , struct V_44 * V_45 )
{
if ( V_6 -> V_1 -> V_69 ) {
if ( V_45 -> V_45 . V_56 ) {
F_49 ( V_6 , V_45 ) ;
} else
F_50 ( V_66 L_6 ,
V_70 , V_45 -> V_45 . V_56 ) ;
if ( ( V_45 -> V_45 . V_56 == V_45 -> V_45 . V_62 ) ||
( V_45 -> V_45 . V_62 < V_6 -> V_6 . V_21 ) )
F_37 ( V_6 , V_45 , 0 ) ;
} else {
if ( ! V_45 -> V_45 . V_56 )
F_37 ( V_6 , V_45 , 0 ) ;
else
F_1 ( V_6 -> V_1 , V_71 ,
V_72 ) ;
}
}
static int F_55 ( struct V_41 * V_42 , struct V_51 * V_53 ,
T_3 V_52 )
{
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
int V_73 = 0 ;
V_6 = F_31 ( V_42 , struct V_5 , V_6 ) ;
V_45 = F_31 ( V_53 , struct V_44 , V_45 ) ;
if ( V_6 -> V_1 -> V_74 . V_75 == V_76 )
return - V_77 ;
F_36 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
if ( F_34 ( & V_6 -> V_47 ) )
V_73 = 1 ;
F_56 ( & V_45 -> V_47 , & V_6 -> V_47 ) ;
V_45 -> V_45 . V_62 = 0 ;
V_45 -> V_45 . V_78 = - V_79 ;
if ( V_6 -> V_6 . V_31 == NULL )
F_54 ( V_6 , V_45 ) ;
else if ( V_73 && ! V_6 -> V_10 )
F_44 ( V_6 ) ;
F_38 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_57 ( struct V_41 * V_42 , struct V_51 * V_53 )
{
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
V_6 = F_31 ( V_42 , struct V_5 , V_6 ) ;
V_45 = F_31 ( V_53 , struct V_44 , V_45 ) ;
F_36 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
if ( ! F_34 ( & V_6 -> V_47 ) )
F_37 ( V_6 , V_45 , - V_50 ) ;
F_38 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
return 0 ;
}
static int F_58 ( struct V_41 * V_42 , int V_3 , int V_80 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_46 ;
int V_81 = 0 ;
V_6 = F_31 ( V_42 , struct V_5 , V_6 ) ;
V_1 = V_6 -> V_1 ;
F_36 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
if ( ! F_34 ( & V_6 -> V_47 ) ) {
V_81 = - V_82 ;
goto V_83;
}
if ( V_3 ) {
F_51 ( V_1 , V_6 -> V_9 ) ;
V_6 -> V_10 = 1 ;
if ( V_80 )
V_6 -> V_11 = 1 ;
} else {
F_53 ( V_1 , V_6 -> V_9 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
}
V_83:
F_38 ( & V_6 -> V_1 -> V_49 , V_46 ) ;
return V_81 ;
}
static int F_59 ( struct V_41 * V_42 , int V_3 )
{
return F_58 ( V_42 , V_3 , 0 ) ;
}
static int F_60 ( struct V_41 * V_42 )
{
return F_58 ( V_42 , 1 , 1 ) ;
}
static void F_61 ( struct V_41 * V_42 )
{
}
static void F_62 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 )
{
F_3 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static void F_63 ( void )
{
}
static void F_64 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_57 ,
V_84 ) ;
}
static void F_65 ( struct V_1 * V_1 )
{
F_1 ( V_1 , V_57 ,
V_85 ) ;
}
static void F_66 ( struct V_1 * V_1 ,
T_2 * V_86 , T_1 V_56 )
{
int V_59 = 0 ;
T_2 * V_60 ;
T_1 V_61 ;
V_60 = V_86 ;
for ( V_59 = ( V_56 >> 2 ) ; V_59 > 0 ; V_59 -- ) {
V_61 = F_2 ( V_1 -> V_4 + V_65 ) ;
F_50 ( V_66 L_4 , V_61 ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
* ( V_60 + 2 ) = ( V_61 >> 16 ) & 0xFF ;
* ( V_60 + 3 ) = ( V_61 >> 24 ) & 0xFF ;
V_60 = V_60 + 4 ;
}
switch ( V_56 % 4 ) {
case 1 :
V_61 = F_2 ( V_1 -> V_4 + V_65 ) ;
F_50 ( V_66 L_4 , V_61 ) ;
* V_60 = V_61 & 0xFF ;
break;
case 2 :
V_61 = F_2 ( V_1 -> V_4 + V_65 ) ;
F_50 ( V_66 L_4 , V_61 ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
break;
case 3 :
V_61 = F_2 ( V_1 -> V_4 + V_65 ) ;
F_50 ( V_66 L_4 , V_61 ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
* ( V_60 + 2 ) = ( V_61 >> 16 ) & 0xFF ;
break;
default:
break;
}
}
static void F_67 ( struct V_5 * V_6 ,
struct V_44 * V_45 ,
T_1 V_56 )
{
int V_59 = 0 ;
T_2 * V_60 ;
T_1 V_61 , V_4 ;
struct V_1 * V_1 = V_6 -> V_1 ;
V_60 = V_45 -> V_45 . V_63 + V_45 -> V_45 . V_62 ;
V_45 -> V_45 . V_62 += V_56 ;
if ( V_45 -> V_45 . V_62 > V_45 -> V_45 . V_56 )
F_50 ( V_66 L_7 ) ;
for ( V_59 = ( V_56 >> 2 ) ; V_59 > 0 ; V_59 -- ) {
V_61 = F_2 ( V_1 -> V_4 +
F_68 ( V_6 -> V_9 ) ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
* ( V_60 + 2 ) = ( V_61 >> 16 ) & 0xFF ;
* ( V_60 + 3 ) = ( V_61 >> 24 ) & 0xFF ;
V_60 = V_60 + 4 ;
}
switch ( V_56 % 4 ) {
case 1 :
V_61 = F_2 ( V_1 -> V_4 +
F_68 ( V_6 -> V_9 ) ) ;
* V_60 = V_61 & 0xFF ;
break;
case 2 :
V_61 = F_2 ( V_1 -> V_4 +
F_68 ( V_6 -> V_9 ) ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
break;
case 3 :
V_61 = F_2 ( V_1 -> V_4 +
F_68 ( V_6 -> V_9 ) ) ;
* V_60 = V_61 & 0xFF ;
* ( V_60 + 1 ) = ( V_61 >> 8 ) & 0xFF ;
* ( V_60 + 2 ) = ( V_61 >> 16 ) & 0xFF ;
break;
default:
break;
}
do {
V_4 = F_2 ( V_1 -> V_4 + V_87 ) ;
V_4 &= V_88 ;
if ( V_59 )
F_50 ( V_89 L_8 ) ;
V_59 ++ ;
} while ( ! V_4 );
}
static T_2 F_69 ( struct V_1 * V_1 , T_2 V_6 )
{
T_2 V_3 ;
T_1 V_4 = F_2 ( V_1 -> V_4 + F_52 ( V_6 ) ) ;
V_3 = V_4 & V_67 ;
return V_3 ;
}
static T_2 F_70 ( struct V_1 * V_1 )
{
T_2 V_3 ;
T_1 V_4 = F_2 ( V_1 -> V_4 + V_57 ) ;
V_3 = ( V_4 & V_84 ) >> 1 ;
return V_3 ;
}
static void F_71 ( struct V_1 * V_1 )
{
F_64 ( V_1 ) ;
F_50 ( V_66 L_9 ) ;
}
static void F_72 ( struct V_1 * V_1 , struct V_90 * V_91 )
__releases( V_1 -> V_49 )
__acquires( V_1 -> V_49 )
{
T_2 V_6 ;
T_4 V_78 = 0 ;
T_4 V_92 = V_91 -> V_93 ;
switch ( V_91 -> V_94 & V_95 ) {
case V_96 :
V_78 = 1 << V_97 ;
break;
case V_98 :
V_78 = 0 ;
break;
case V_99 :
V_6 = V_92 & V_36 ;
if ( V_6 ) {
if ( F_69 ( V_1 , V_6 ) )
V_78 = 1 << V_100 ;
} else {
if ( F_70 ( V_1 ) )
V_78 = 0 ;
}
break;
default:
F_71 ( V_1 ) ;
return;
}
V_1 -> V_101 = F_73 ( V_78 ) ;
V_1 -> V_102 -> V_63 = & V_1 -> V_101 ;
V_1 -> V_102 -> V_56 = 2 ;
F_74 ( & V_1 -> V_49 ) ;
F_55 ( V_1 -> V_74 . V_103 , V_1 -> V_102 , V_104 ) ;
F_75 ( & V_1 -> V_49 ) ;
}
static void F_76 ( struct V_1 * V_1 , struct V_90 * V_91 )
{
T_2 V_6 ;
switch ( V_91 -> V_94 & V_95 ) {
case V_96 :
F_65 ( V_1 ) ;
break;
case V_98 :
F_65 ( V_1 ) ;
break;
case V_99 : {
T_4 V_92 = F_77 ( V_91 -> V_93 ) ;
V_6 = V_92 & V_36 ;
if ( V_6 )
F_51 ( V_1 , V_6 ) ;
else
F_64 ( V_1 ) ;
F_65 ( V_1 ) ;
}
break;
default:
F_71 ( V_1 ) ;
break;
}
}
static void F_78 ( struct V_1 * V_1 , T_2 V_6 )
{
F_1 ( V_1 , F_52 ( V_6 ) ,
V_105 ) ;
}
static void F_79 ( struct V_1 * V_1 , struct V_90 * V_91 )
{
struct V_5 * V_6 =
V_1 -> V_6 [ V_91 -> V_93 & V_36 ] ;
switch ( V_91 -> V_94 & V_95 ) {
case V_96 :
F_65 ( V_1 ) ;
break;
case V_98 :
F_65 ( V_1 ) ;
break;
case V_99 :
if ( V_91 -> V_93 & V_36 ) {
if ( V_6 -> V_11 ) {
F_65 ( V_1 ) ;
break;
}
if ( V_6 -> V_10 ) {
V_6 -> V_10 = 0 ;
F_78 ( V_1 , V_6 -> V_9 ) ;
F_53 ( V_1 , V_6 -> V_9 ) ;
if ( ! F_34 ( & V_6 -> V_47 ) )
F_44 ( V_6 ) ;
}
}
F_65 ( V_1 ) ;
break;
default:
F_71 ( V_1 ) ;
break;
}
}
static void F_80 ( struct V_1 * V_1 , T_4 V_106 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_107 ) ;
V_4 &= ~ V_108 ;
V_4 |= F_81 ( V_106 ) ;
F_3 ( V_4 , V_1 -> V_4 + V_107 ) ;
}
static void F_82 ( struct V_1 * V_1 , struct V_90 * V_91 )
{
if ( V_91 -> V_109 >= 0x0100 )
F_71 ( V_1 ) ;
else {
F_80 ( V_1 , V_91 -> V_109 ) ;
F_65 ( V_1 ) ;
}
}
static int F_83 ( struct V_1 * V_1 , struct V_90 * V_91 )
{
T_2 * V_110 = ( T_2 * ) V_91 ;
T_2 V_81 = 0 ;
T_2 V_59 = 0 ;
F_66 ( V_1 , V_110 , 8 ) ;
V_1 -> V_69 = V_91 -> V_94 & V_111 ;
V_1 -> V_112 = V_91 -> V_113 ;
if ( ( V_91 -> V_94 & V_114 ) == V_115 ) {
switch ( V_91 -> V_116 ) {
case V_117 :
F_72 ( V_1 , V_91 ) ;
break;
case V_118 :
F_79 ( V_1 , V_91 ) ;
break;
case V_119 :
F_76 ( V_1 , V_91 ) ;
break;
case V_120 :
F_82 ( V_1 , V_91 ) ;
break;
case V_121 :
F_1 ( V_1 , V_107 ,
V_122 ) ;
for ( V_59 = 1 ; V_59 <= V_123 ; V_59 ++ )
F_78 ( V_1 , V_59 ) ;
V_1 -> V_43 = 1 ;
V_81 = 1 ;
break;
default:
V_81 = 1 ;
break;
}
} else
V_81 = 1 ;
return V_81 ;
}
static void F_37 ( struct V_5 * V_6 , struct V_44 * V_45 ,
int V_78 )
{
F_84 ( & V_45 -> V_47 ) ;
if ( V_6 -> V_1 -> V_74 . V_75 == V_76 )
V_45 -> V_45 . V_78 = - V_77 ;
else
V_45 -> V_45 . V_78 = V_78 ;
F_74 ( & V_6 -> V_1 -> V_49 ) ;
F_85 ( & V_6 -> V_6 , & V_45 -> V_45 ) ;
F_75 ( & V_6 -> V_1 -> V_49 ) ;
if ( V_6 -> V_9 ) {
F_46 ( V_6 ) ;
if ( ! F_34 ( & V_6 -> V_47 ) )
F_44 ( V_6 ) ;
} else
F_65 ( V_6 -> V_1 ) ;
}
static void F_86 ( struct V_5 * V_6 , T_5 V_124 ,
T_1 V_125 )
{
T_1 V_3 ;
T_1 V_4 ;
do {
V_4 = F_2 ( V_6 -> V_1 -> V_4 +
F_87 ( V_6 -> V_9 ) ) ;
V_4 &= V_126 ;
} while ( V_4 );
F_3 ( V_124 , V_6 -> V_1 -> V_4 + F_88 ( V_6 -> V_9 ) ) ;
V_3 = F_89 ( V_125 ) | V_126 |
V_127 | V_128 | V_129 ;
F_3 ( V_3 , V_6 -> V_1 -> V_4 + F_87 ( V_6 -> V_9 ) ) ;
F_3 ( 0x0 , V_6 -> V_1 -> V_4 + F_90 ( V_6 -> V_9 ) ) ;
F_1 ( V_6 -> V_1 , V_130 ,
F_91 ( V_6 -> V_9 ) ) ;
}
static void F_92 ( struct V_5 * V_6 )
{
T_1 V_4 ;
do {
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_87 ) ;
if ( ( V_4 & V_131 ) ||
( V_4 & V_132 ) ||
( V_4 & V_133 ) ||
( V_4 & V_134 )
)
goto V_135;
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_136 ) ;
V_4 &= F_93 ( V_6 -> V_9 ) ;
} while ( ! V_4 );
F_62 ( V_6 -> V_1 , V_136 ,
F_93 ( V_6 -> V_9 ) ) ;
return;
V_135:
V_4 = F_2 ( V_6 -> V_1 -> V_4 + V_54 ) ;
V_4 &= ~ F_94 ( V_6 -> V_9 ) ;
F_3 ( V_4 , V_6 -> V_1 -> V_4 + V_54 ) ;
}
static void F_95 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
int V_81 ;
V_81 = F_96 ( & V_6 -> V_1 -> V_74 ,
& V_45 -> V_45 , V_137 ) ;
if ( V_81 )
return;
F_1 ( V_6 -> V_1 , V_54 ,
F_94 ( V_6 -> V_9 ) ) ;
F_86 ( V_6 , V_45 -> V_45 . V_138 , V_45 -> V_45 . V_56 ) ;
F_92 ( V_6 ) ;
F_97 ( & V_6 -> V_1 -> V_74 ,
& V_45 -> V_45 , V_137 ) ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_44 * V_45 = F_35 ( V_6 -> V_47 . V_48 ,
struct V_44 , V_47 ) ;
if ( V_45 -> V_45 . V_56 )
F_95 ( V_6 , V_45 ) ;
F_37 ( V_6 , V_45 , 0 ) ;
}
static void F_99 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = V_6 -> V_1 ;
struct V_44 * V_45 = F_35 ( V_6 -> V_47 . V_48 ,
struct V_44 , V_47 ) ;
T_1 V_4 = F_2 ( V_1 -> V_4 + F_100 ( V_6 -> V_9 ) ) ;
T_1 V_56 = V_4 & V_139 ;
F_67 ( V_6 , V_45 , V_56 ) ;
if ( ( V_45 -> V_45 . V_56 == V_45 -> V_45 . V_62 ) || ( V_56 < V_6 -> V_6 . V_21 ) )
F_37 ( V_6 , V_45 , 0 ) ;
}
static void F_101 ( struct V_1 * V_1 )
{
T_1 V_4 = F_2 ( V_1 -> V_4 + V_140 ) ;
switch ( V_4 & V_141 ) {
case V_142 :
V_1 -> V_74 . V_75 = V_143 ;
break;
case V_144 :
V_1 -> V_74 . V_75 = V_145 ;
break;
case V_146 :
V_1 -> V_74 . V_75 = V_147 ;
break;
default:
V_1 -> V_74 . V_75 = V_76 ;
break;
}
F_50 ( V_89 L_10 , ( V_4 & V_141 ) ) ;
}
static void F_102 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_6 [ 0 ] ;
T_1 V_4 ;
if ( ! F_34 ( & V_6 -> V_47 ) ) {
struct V_44 * V_45 ;
V_45 = F_103 ( & V_6 -> V_47 ,
struct V_44 , V_47 ) ;
if ( V_45 -> V_45 . V_56 )
F_66 ( V_6 -> V_1 , V_45 -> V_45 . V_63 ,
V_45 -> V_45 . V_56 ) ;
F_37 ( V_6 , V_45 , 0 ) ;
V_4 = F_2 ( V_1 -> V_4 + V_71 ) ;
V_4 &= ~ V_72 ;
F_3 ( V_4 , V_1 -> V_4 + V_71 ) ;
} else
F_12 ( L_11 , V_70 ) ;
}
static void F_104 ( struct V_1 * V_1 )
{
struct V_44 * V_45 ;
struct V_5 * V_6 = V_1 -> V_6 [ 0 ] ;
if ( ( ! F_34 ( & V_6 -> V_47 ) ) && ( V_1 -> V_69 ) ) {
V_45 = F_35 ( V_6 -> V_47 . V_48 ,
struct V_44 , V_47 ) ;
if ( V_45 -> V_45 . V_56 )
F_49 ( V_6 , V_45 ) ;
if ( ( V_45 -> V_45 . V_56 - V_45 -> V_45 . V_62 ) < V_6 -> V_6 . V_21 )
F_37 ( V_6 , V_45 , 0 ) ;
} else
F_65 ( V_1 ) ;
}
static void F_105 ( void )
{
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
static T_6 F_109 ( int V_148 , void * V_149 )
{
struct V_1 * V_1 = V_149 ;
T_1 V_150 = F_2 ( V_1 -> V_4 + V_87 ) ;
T_1 V_151 = F_2 ( V_1 -> V_4 + V_71 ) ;
T_1 V_152 = F_2 ( V_1 -> V_4 + V_136 ) ;
T_1 V_153 = F_2 ( V_1 -> V_4 + V_54 ) ;
struct V_90 V_91 ;
T_2 V_154 ;
T_1 V_4 ;
int V_59 ;
F_75 ( & V_1 -> V_49 ) ;
V_150 &= V_151 ;
V_152 &= V_153 ;
if ( V_150 & V_132 ) {
F_62 ( V_1 , V_87 ,
V_132 ) ;
F_50 ( V_89 L_12 ) ;
F_63 () ;
}
if ( V_150 & V_133 ) {
F_62 ( V_1 , V_87 ,
V_133 ) ;
F_50 ( V_89 L_13 ) ;
F_63 () ;
}
if ( V_150 & V_134 ) {
F_62 ( V_1 , V_87 ,
V_134 ) ;
F_63 () ;
}
if ( V_150 & V_155 ) {
F_62 ( V_1 , V_87 ,
V_155 ) ;
F_50 ( V_89 L_14 ) ;
}
if ( V_150 & V_131 ) {
F_62 ( V_1 , V_87 ,
V_131 ) ;
F_50 ( V_89 L_15 ) ;
}
if ( V_150 & V_156 ) {
F_62 ( V_1 , V_87 ,
V_156 ) ;
}
if ( V_150 & V_157 ) {
F_62 ( V_1 , V_87 ,
V_157 ) ;
}
if ( V_150 & V_158 ) {
F_62 ( V_1 , V_87 ,
V_158 ) ;
}
if ( V_150 & V_159 ) {
F_62 ( V_1 , V_87 ,
V_159 ) ;
}
if ( V_150 & V_160 ) {
F_62 ( V_1 , V_87 ,
V_160 ) ;
}
if ( V_150 & V_161 ) {
F_62 ( V_1 , V_87 ,
V_161 ) ;
F_50 ( V_89 L_16 ) ;
}
if ( V_150 & V_162 ) {
F_62 ( V_1 , V_87 ,
V_162 ) ;
F_50 ( V_89 L_17 ) ;
}
if ( V_150 & V_163 ) {
F_62 ( V_1 , V_87 ,
V_163 ) ;
F_50 ( V_89 L_18 ) ;
}
if ( V_150 & V_164 ) {
F_62 ( V_1 , V_87 ,
V_164 ) ;
F_50 ( V_89 L_19 ) ;
F_1 ( V_1 , V_165 ,
V_166 ) ;
}
if ( V_150 & V_167 ) {
F_62 ( V_1 , V_87 ,
V_167 ) ;
F_50 ( V_89 L_20 ) ;
}
if ( V_150 & V_168 ) {
F_62 ( V_1 , V_87 ,
V_168 ) ;
F_50 ( V_89 L_21 ) ;
}
if ( V_150 & V_169 ) {
F_62 ( V_1 , V_87 ,
V_169 ) ;
F_50 ( V_89 L_22 ) ;
}
if ( V_150 & V_170 ) {
F_62 ( V_1 , V_87 ,
V_170 ) ;
F_50 ( V_89 L_23 ) ;
}
if ( V_150 & V_171 ) {
F_62 ( V_1 , V_87 ,
V_171 ) ;
F_50 ( V_89 L_24 ) ;
}
if ( V_150 & V_172 ) {
F_62 ( V_1 , V_87 ,
V_172 ) ;
F_101 ( V_1 ) ;
}
if ( V_150 & V_173 ) {
F_64 ( V_1 ) ;
F_50 ( V_89 L_25 ) ;
}
if ( V_150 & V_174 ) {
F_50 ( V_89 L_26 ) ;
if ( F_83 ( V_1 , & V_91 ) ) {
F_74 ( & V_1 -> V_49 ) ;
if ( V_1 -> V_175 -> V_176 ( & V_1 -> V_74 , & V_91 ) < 0 )
F_64 ( V_1 ) ;
F_75 ( & V_1 -> V_49 ) ;
}
}
if ( V_150 & V_177 )
F_50 ( V_89 L_27 ) ;
if ( V_150 & V_178 ) {
F_50 ( V_89 L_28 ) ;
F_102 ( V_1 ) ;
}
if ( V_150 & V_179 ) {
F_50 ( V_89 L_29 ) ;
F_104 ( V_1 ) ;
}
if ( V_150 & V_180 )
F_108 () ;
if ( V_150 & V_181 )
F_107 () ;
if ( V_150 & V_182 )
F_106 () ;
if ( V_150 & V_183 )
F_105 () ;
if ( V_152 ) {
for ( V_59 = 1 ; V_59 < V_123 ; V_59 ++ ) {
if ( V_152 & F_110 ( V_59 ) ) {
V_4 = F_2 ( V_1 -> V_4 +
F_8 ( V_59 ) ) ;
V_154 = ( V_4 & V_25 ) ? 1 : 0 ;
if ( V_154 )
F_98 ( V_1 -> V_6 [ V_59 ] ) ;
else
F_99 ( V_1 -> V_6 [ V_59 ] ) ;
}
}
}
F_74 ( & V_1 -> V_49 ) ;
return V_184 ;
}
static void F_111 ( struct V_1 * V_1 ,
T_1 time )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_185 ) ;
V_4 &= ~ 0xff ;
V_4 |= F_112 ( time ) ;
F_3 ( V_4 , V_1 -> V_4 + V_185 ) ;
}
static void F_113 ( struct V_1 * V_1 ,
T_1 time )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 -> V_4 + V_185 ) ;
V_4 &= ~ ( 0xff << 8 ) ;
V_4 |= F_114 ( time ) ;
F_3 ( V_4 , V_1 -> V_4 + V_185 ) ;
}
static void F_115 ( struct V_1 * V_1 )
{
T_1 V_4 ;
T_1 V_186 = 0 ;
T_1 V_12 = 0 ;
V_186 = V_12 = V_187 | V_188 ;
V_4 = F_2 ( V_1 -> V_4 + V_189 ) ;
V_4 &= ~ V_186 ;
V_4 |= V_12 ;
F_3 ( V_4 , V_1 -> V_4 + V_189 ) ;
V_186 = V_12 = V_190 ;
V_4 = F_2 ( V_1 -> V_4 + V_191 ) ;
V_4 &= ~ V_186 ;
V_4 |= V_12 ;
F_3 ( V_4 , V_1 -> V_4 + V_191 ) ;
F_111 ( V_1 , 0xff ) ;
F_113 ( V_1 , 0xff ) ;
F_3 ( 0xcfffff9f , V_1 -> V_4 + V_71 ) ;
}
static int F_116 ( struct V_192 * V_193 ,
struct V_194 * V_175 )
{
struct V_1 * V_1 = F_117 ( V_193 ) ;
V_175 -> V_175 . V_195 = NULL ;
V_1 -> V_175 = V_175 ;
return 0 ;
}
static int F_118 ( struct V_192 * V_193 )
{
struct V_1 * V_1 = F_117 ( V_193 ) ;
F_115 ( V_1 ) ;
V_1 -> V_175 = NULL ;
return 0 ;
}
static int F_119 ( struct V_192 * V_196 , int V_197 )
{
return 0 ;
}
static int F_120 ( struct V_198 * V_199 )
{
struct V_1 * V_1 = F_121 ( V_199 ) ;
F_122 ( & V_1 -> V_74 ) ;
F_123 ( V_1 -> V_4 ) ;
F_124 ( F_125 ( V_199 , 0 ) , V_1 ) ;
F_42 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_1 -> V_102 ) ;
F_43 ( V_1 ) ;
return 0 ;
}
static int F_126 ( struct V_198 * V_199 )
{
struct V_200 * V_201 , * V_202 , * V_203 ;
void T_7 * V_4 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_5 * V_42 [ V_123 ] ;
int V_81 = 0 ;
int V_59 ;
V_201 = F_127 ( V_199 , V_204 , 0 ) ;
if ( ! V_201 ) {
V_81 = - V_205 ;
F_12 ( L_30 ) ;
goto V_206;
}
V_202 = F_127 ( V_199 , V_207 , 0 ) ;
if ( ! V_202 ) {
V_81 = - V_205 ;
F_128 ( & V_199 -> V_208 ,
L_31 ) ;
goto V_206;
}
V_203 = F_127 ( V_199 , V_207 , 1 ) ;
if ( ! V_203 ) {
V_81 = - V_205 ;
F_128 ( & V_199 -> V_208 ,
L_32 ) ;
goto V_206;
}
V_4 = F_129 ( V_201 -> V_209 , F_130 ( V_201 ) ) ;
if ( V_4 == NULL ) {
V_81 = - V_210 ;
F_12 ( L_33 ) ;
goto V_206;
}
V_1 = F_40 ( sizeof( struct V_1 ) , V_104 ) ;
if ( V_1 == NULL ) {
V_81 = - V_210 ;
goto V_206;
}
for ( V_59 = 0 ; V_59 < V_123 ; V_59 ++ ) {
V_42 [ V_59 ] = F_40 ( sizeof( struct V_5 ) , V_104 ) ;
if ( V_42 [ V_59 ] == NULL ) {
V_81 = - V_210 ;
goto V_206;
}
V_1 -> V_6 [ V_59 ] = V_42 [ V_59 ] ;
}
F_131 ( & V_1 -> V_49 ) ;
F_132 ( V_199 , V_1 ) ;
V_1 -> V_74 . V_211 = & V_212 ;
V_1 -> V_74 . V_213 = V_145 ;
V_1 -> V_74 . V_214 = V_215 ;
V_1 -> V_4 = V_4 ;
V_81 = F_133 ( V_202 -> V_209 , F_109 , V_216 ,
V_215 , V_1 ) ;
if ( V_81 < 0 ) {
F_12 ( L_34 , V_81 ) ;
goto V_206;
}
V_81 = F_133 ( V_203 -> V_209 , F_109 ,
V_216 , V_215 , V_1 ) ;
if ( V_81 < 0 ) {
F_12 ( L_35 , V_81 ) ;
goto V_206;
}
F_41 ( & V_1 -> V_74 . V_217 ) ;
for ( V_59 = 0 ; V_59 < V_123 ; V_59 ++ ) {
struct V_5 * V_6 = V_1 -> V_6 [ V_59 ] ;
if ( V_59 != 0 ) {
F_41 ( & V_1 -> V_6 [ V_59 ] -> V_6 . V_217 ) ;
F_56 ( & V_1 -> V_6 [ V_59 ] -> V_6 . V_217 ,
& V_1 -> V_74 . V_217 ) ;
}
V_6 -> V_1 = V_1 ;
F_41 ( & V_6 -> V_47 ) ;
V_6 -> V_6 . V_214 = V_218 [ V_59 ] ;
V_6 -> V_6 . V_211 = & V_219 ;
F_134 ( & V_6 -> V_6 , V_220 ) ;
}
F_134 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_221 ) ;
V_1 -> V_6 [ 0 ] -> V_9 = 0 ;
V_1 -> V_74 . V_103 = & V_1 -> V_6 [ 0 ] -> V_6 ;
F_41 ( & V_1 -> V_74 . V_103 -> V_217 ) ;
V_1 -> V_102 = F_39 ( & V_1 -> V_6 [ 0 ] -> V_6 ,
V_104 ) ;
if ( V_1 -> V_102 == NULL ) {
V_81 = - V_210 ;
goto V_222;
}
F_115 ( V_1 ) ;
V_81 = F_135 ( & V_199 -> V_208 , & V_1 -> V_74 ) ;
if ( V_81 )
goto V_223;
F_136 ( & V_199 -> V_208 , L_36 , V_224 ) ;
return 0 ;
V_223:
F_42 ( & V_1 -> V_6 [ 0 ] -> V_6 , V_1 -> V_102 ) ;
V_222:
F_124 ( V_202 -> V_209 , V_1 ) ;
V_206:
if ( V_1 ) {
if ( V_1 -> V_102 )
F_42 ( & V_1 -> V_6 [ 0 ] -> V_6 ,
V_1 -> V_102 ) ;
F_43 ( V_1 ) ;
}
if ( V_4 )
F_123 ( V_4 ) ;
return V_81 ;
}
