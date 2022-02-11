static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_6 ) ;
if ( V_2 -> V_7 )
V_3 |= F_3 ( V_2 -> V_8 - 1 ) ;
else
V_3 |= F_4 ( V_2 -> V_8 - 1 ) ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_6 ) ;
if ( V_2 -> V_7 )
V_3 &= ~ F_3 ( V_2 -> V_8 - 1 ) ;
else
V_3 &= ~ F_4 ( V_2 -> V_8 - 1 ) ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_6 ) ;
}
static void F_7 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_10 ) ;
V_3 |= V_11 ;
F_5 ( V_3 , V_4 -> V_5 + V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 )
{
F_9 ( & V_13 -> V_15 ) ;
if ( V_2 -> V_4 -> V_16 . V_17 == V_18 )
V_13 -> V_13 . V_14 = - V_19 ;
else
V_13 -> V_13 . V_14 = V_14 ;
F_10 ( & V_2 -> V_4 -> V_20 ) ;
V_13 -> V_13 . V_21 ( & V_2 -> V_2 , & V_13 -> V_13 ) ;
F_11 ( & V_2 -> V_4 -> V_20 ) ;
if ( V_2 -> V_8 ) {
if ( F_12 ( & V_2 -> V_15 ) )
F_1 ( V_2 ) ;
} else {
F_7 ( V_2 -> V_4 ) ;
}
}
static void F_13 ( struct V_1 * V_2 , T_1 V_8 ,
T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
V_22 = F_2 ( V_4 -> V_5 + V_23 ) ;
V_22 &= ~ F_14 ( V_8 , V_7 ) ;
V_22 |= F_15 ( V_8 , V_7 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_23 ) ;
V_22 = F_2 ( V_4 -> V_5 + V_24 ) ;
V_22 &= ~ F_16 ( V_8 ) ;
V_22 |= F_17 ( V_8 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_24 ) ;
V_22 = F_2 ( V_4 -> V_5 + V_25 ) ;
V_22 |= F_18 ( V_8 - 1 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_25 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
V_22 = F_2 ( V_4 -> V_5 + V_24 ) ;
V_22 |= ( V_7 ? F_20 ( V_8 - 1 ) : F_21 ( V_8 - 1 ) ) ;
F_5 ( V_22 , V_4 -> V_5 + V_24 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_8 , T_1 type )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
V_22 = F_2 ( V_4 -> V_5 + V_25 ) ;
V_22 |= F_23 ( type , V_8 - 1 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_25 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_26 ,
T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_22 ;
T_1 V_27 = V_7 ? F_25 ( V_8 ) :
F_26 ( V_8 ) ;
V_22 = F_2 ( V_4 -> V_5 + V_27 ) ;
V_22 |= F_27 ( V_26 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_27 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
F_19 ( V_2 , V_2 -> V_8 , V_2 -> V_7 ) ;
F_22 ( V_2 , V_2 -> V_8 , V_2 -> type ) ;
F_24 ( V_2 , V_2 -> V_8 , V_2 -> V_2 . V_30 , V_2 -> V_7 ) ;
F_13 ( V_2 , V_2 -> V_8 , V_2 -> V_7 ) ;
V_4 -> V_2 [ V_2 -> V_8 ] = V_2 ;
return 0 ;
}
static int F_29 ( struct V_31 * V_32 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( V_32 , struct V_1 , V_2 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_8 = F_31 ( V_29 ) ;
V_2 -> type = F_32 ( V_29 ) ;
V_2 -> V_7 = F_33 ( V_29 ) ;
V_2 -> V_2 . V_30 = F_34 ( V_29 ) ;
return F_28 ( V_2 , V_29 ) ;
}
static void F_35 ( struct V_9 * V_4 , T_2 V_8 )
{
struct V_1 * V_2 = V_4 -> V_2 [ V_8 ] ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_25 ( V_8 ) :
V_4 -> V_5 + F_26 ( V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_33 ;
F_5 ( V_3 , V_5 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_33 ;
F_5 ( V_3 , V_5 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 )
return 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
F_35 ( V_2 -> V_4 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_37 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
F_38 ( ! V_32 ) ;
V_2 = F_30 ( V_32 , struct V_1 , V_2 ) ;
while ( ! F_12 ( & V_2 -> V_15 ) ) {
V_13 = F_39 ( V_2 -> V_15 . V_37 ,
struct V_12 , V_15 ) ;
F_40 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
F_8 ( V_2 , V_13 , - V_38 ) ;
F_41 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
}
return F_36 ( V_2 ) ;
}
static struct V_39 * F_42 ( struct V_31 * V_32 ,
T_4 V_40 )
{
struct V_12 * V_13 ;
V_13 = F_43 ( sizeof( struct V_12 ) , V_40 ) ;
if ( ! V_13 )
return NULL ;
F_44 ( & V_13 -> V_15 ) ;
return & V_13 -> V_13 ;
}
static void F_45 ( struct V_31 * V_32 ,
struct V_39 * V_41 )
{
struct V_12 * V_13 ;
V_13 = F_30 ( V_41 , struct V_12 , V_13 ) ;
F_46 ( V_13 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
T_5 V_42 , T_1 V_43 )
{
T_1 V_3 ;
struct V_9 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( V_4 -> V_5 + V_44 ) ;
V_3 &= ~ ( F_48 ( 0xFFFF ) | F_49 ( 1 ) ) ;
V_3 |= F_48 ( V_43 ) | F_49 ( V_2 -> V_7 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_44 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_45 ) ;
if ( V_2 -> V_8 )
V_3 |= F_50 ( V_2 -> V_8 - 1 ) ;
else
V_3 |= V_46 ;
F_5 ( V_3 , V_4 -> V_5 + V_45 ) ;
F_5 ( V_42 , V_4 -> V_5 + V_47 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_48 ) ;
V_3 &= ~ ( V_49 | V_50 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_48 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_44 ) ;
V_3 |= V_51 ;
F_5 ( V_3 , V_4 -> V_5 + V_44 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_5 ( V_52 , V_2 -> V_4 -> V_5 + V_45 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_1 V_3 ;
do {
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_53 ) ;
if ( ( V_3 & V_54 ) ||
( V_3 & V_55 ) )
goto V_56;
} while ( ! ( V_3 & V_57 ) );
V_3 &= ~ V_57 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_53 ) ;
return;
V_56:
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_44 ) ;
V_3 |= V_58 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_44 ) ;
if ( V_2 -> V_8 ) {
V_3 = F_2 ( V_2 -> V_4 -> V_5 +
F_53 ( V_2 -> V_8 - 1 ) ) ;
V_3 |= V_59 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 +
F_53 ( V_2 -> V_8 - 1 ) ) ;
} else {
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_10 ) ;
V_3 |= V_60 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_10 ) ;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
T_5 V_42 ;
T_2 * V_61 ;
T_1 V_62 ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_7 ) {
V_61 = V_13 -> V_13 . V_63 ;
V_62 = V_13 -> V_13 . V_62 ;
} else {
V_61 = V_13 -> V_13 . V_63 + V_13 -> V_13 . V_64 ;
V_62 = F_2 ( V_2 -> V_4 -> V_5 +
F_53 ( V_2 -> V_8 - 1 ) ) ;
V_62 &= V_65 ;
}
} else {
V_61 = V_13 -> V_13 . V_63 + V_13 -> V_13 . V_64 ;
if ( V_13 -> V_13 . V_62 - V_13 -> V_13 . V_64 > V_2 -> V_2 . V_30 )
V_62 = V_2 -> V_2 . V_30 ;
else
V_62 = V_13 -> V_13 . V_62 ;
}
V_42 = F_55 ( NULL , V_61 , V_62 ,
V_2 -> V_7 ? V_66 : V_67 ) ;
if ( F_56 ( NULL , V_42 ) ) {
F_57 ( L_1 ) ;
return;
}
F_58 ( NULL , V_42 , V_62 ,
V_2 -> V_7 ? V_66 :
V_67 ) ;
F_47 ( V_2 , V_42 , V_62 ) ;
F_52 ( V_2 ) ;
F_51 ( V_2 ) ;
V_13 -> V_13 . V_64 += V_62 ;
F_59 ( NULL , V_42 , V_62 , V_66 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( ! V_13 -> V_13 . V_62 ) {
F_8 ( V_2 , V_13 , 0 ) ;
return;
}
if ( V_2 -> V_7 ) {
if ( V_13 -> V_13 . V_62 ) {
F_54 ( V_2 , V_13 ) ;
} else {
F_57 ( L_2 ,
V_68 , V_13 -> V_13 . V_62 ) ;
}
if ( ( V_13 -> V_13 . V_62 == V_13 -> V_13 . V_64 ) ||
( V_13 -> V_13 . V_64 < V_2 -> V_2 . V_30 ) )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
if ( ! V_13 -> V_13 . V_62 ) {
F_8 ( V_2 , V_13 , 0 ) ;
} else {
T_1 V_3 = F_2 ( V_2 -> V_4 -> V_5 +
V_69 ) ;
V_3 &= ~ V_70 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_69 ) ;
}
}
}
static int F_61 ( struct V_31 * V_32 , struct V_39 * V_41 ,
T_4 V_40 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
int V_71 = 0 ;
V_2 = F_30 ( V_32 , struct V_1 , V_2 ) ;
V_13 = F_30 ( V_41 , struct V_12 , V_13 ) ;
if ( V_2 -> V_4 -> V_16 . V_17 == V_18 )
return - V_19 ;
F_40 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
if ( F_12 ( & V_2 -> V_15 ) )
V_71 = 1 ;
F_62 ( & V_13 -> V_15 , & V_2 -> V_15 ) ;
V_13 -> V_13 . V_64 = 0 ;
V_13 -> V_13 . V_14 = - V_72 ;
if ( ! V_2 -> V_8 )
F_60 ( V_2 , V_13 ) ;
else if ( V_71 && ! V_2 -> V_34 )
F_6 ( V_2 ) ;
F_41 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
return 0 ;
}
static int F_63 ( struct V_31 * V_32 , struct V_39 * V_41 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_36 ;
V_2 = F_30 ( V_32 , struct V_1 , V_2 ) ;
V_13 = F_30 ( V_41 , struct V_12 , V_13 ) ;
F_40 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
if ( ! F_12 ( & V_2 -> V_15 ) )
F_8 ( V_2 , V_13 , - V_38 ) ;
F_41 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
if ( V_2 -> V_7 ) {
do {
V_3 = F_2 ( V_4 -> V_5 + V_10 ) ;
} while ( ! ( V_3 & F_65 ( V_2 -> V_8 - 1 ) ) );
}
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_25 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_73 ;
F_5 ( V_3 , V_5 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_25 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_73 ;
F_5 ( V_3 , V_5 ) ;
}
static int F_67 ( struct V_31 * V_32 , int V_3 , int V_74 )
{
struct V_1 * V_2 ;
struct V_9 * V_4 ;
unsigned long V_36 ;
int V_75 = 0 ;
V_2 = F_30 ( V_32 , struct V_1 , V_2 ) ;
V_4 = V_2 -> V_4 ;
F_40 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
if ( V_3 ) {
F_64 ( V_2 ) ;
V_2 -> V_34 = 1 ;
if ( V_74 )
V_2 -> V_35 = 1 ;
} else {
F_35 ( V_4 , V_2 -> V_8 ) ;
F_66 ( V_2 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
if ( ! F_12 ( & V_2 -> V_15 ) )
F_6 ( V_2 ) ;
}
F_41 ( & V_2 -> V_4 -> V_20 , V_36 ) ;
return V_75 ;
}
static int F_68 ( struct V_31 * V_32 , int V_3 )
{
return F_67 ( V_32 , V_3 , 0 ) ;
}
static int F_69 ( struct V_31 * V_32 )
{
return F_67 ( V_32 , 1 , 1 ) ;
}
static void F_70 ( struct V_31 * V_32 )
{
}
static void F_71 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_76 ) ;
V_3 &= ~ ( V_77 | V_78 | V_79
| V_80 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_76 ) ;
}
static void F_72 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_81 ) ;
V_3 &= ~ ( V_82 | V_83 | V_84
| V_85 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_81 ) ;
}
static void F_73 ( struct V_9 * V_4 ,
T_2 * V_61 )
{
int V_86 = 0 ;
T_2 * V_87 = V_61 ;
T_1 V_88 ;
T_1 V_62 = 8 ;
F_5 ( V_46 , V_4 -> V_5 + V_45 ) ;
for ( V_86 = ( V_62 >> 2 ) ; V_86 > 0 ; V_86 -- ) {
V_88 = F_2 ( V_4 -> V_5 + V_89 ) ;
* V_87 = V_88 & 0xFF ;
* ( V_87 + 1 ) = ( V_88 >> 8 ) & 0xFF ;
* ( V_87 + 2 ) = ( V_88 >> 16 ) & 0xFF ;
* ( V_87 + 3 ) = ( V_88 >> 24 ) & 0xFF ;
V_87 = V_87 + 4 ;
}
switch ( V_62 % 4 ) {
case 1 :
V_88 = F_2 ( V_4 -> V_5 + V_89 ) ;
* V_87 = V_88 & 0xFF ;
break;
case 2 :
V_88 = F_2 ( V_4 -> V_5 + V_89 ) ;
* V_87 = V_88 & 0xFF ;
* ( V_87 + 1 ) = ( V_88 >> 8 ) & 0xFF ;
break;
case 3 :
V_88 = F_2 ( V_4 -> V_5 + V_89 ) ;
* V_87 = V_88 & 0xFF ;
* ( V_87 + 1 ) = ( V_88 >> 8 ) & 0xFF ;
* ( V_87 + 2 ) = ( V_88 >> 16 ) & 0xFF ;
break;
default:
break;
}
F_5 ( V_52 , V_4 -> V_5 + V_45 ) ;
}
static void F_74 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_90 ) ;
V_3 |= V_91 ;
F_5 ( V_3 , V_4 -> V_5 + V_90 ) ;
}
static void F_75 ( struct V_9 * V_4 , T_1 V_92 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_90 ) ;
V_3 |= ( V_92 & 0x7F ) ;
F_5 ( V_3 , V_4 -> V_5 + V_90 ) ;
}
static void F_76 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_10 ) ;
V_3 |= V_93 ;
F_5 ( V_3 , V_4 -> V_5 + V_10 ) ;
}
static void F_77 ( struct V_9 * V_4 )
{
F_76 ( V_4 ) ;
F_57 ( L_3 ) ;
}
static void F_78 ( struct V_9 * V_4 ,
struct V_94 * V_95 )
{
if ( V_95 -> V_96 >= 0x0100 ) {
F_77 ( V_4 ) ;
} else {
F_75 ( V_4 , V_95 -> V_96 ) ;
F_7 ( V_4 ) ;
}
}
static void F_79 ( struct V_9 * V_4 ,
struct V_94 * V_95 )
{
switch ( V_95 -> V_97 & V_98 ) {
case V_99 :
F_7 ( V_4 ) ;
break;
case V_100 :
F_7 ( V_4 ) ;
break;
case V_101 : {
T_2 V_8 ;
V_8 = F_80 ( V_95 -> V_102 ) & V_103 ;
if ( V_8 )
F_64 ( V_4 -> V_2 [ V_8 ] ) ;
else
F_76 ( V_4 ) ;
F_7 ( V_4 ) ;
}
break;
default:
F_77 ( V_4 ) ;
break;
}
}
static void F_81 ( struct V_9 * V_4 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 =
V_4 -> V_2 [ V_95 -> V_102 & V_103 ] ;
switch ( V_95 -> V_97 & V_98 ) {
case V_99 :
F_7 ( V_4 ) ;
break;
case V_100 :
F_7 ( V_4 ) ;
break;
case V_101 :
if ( V_95 -> V_102 & V_103 ) {
if ( V_2 -> V_35 ) {
F_7 ( V_4 ) ;
break;
}
if ( V_2 -> V_34 )
F_67 ( & V_2 -> V_2 , 0 , 0 ) ;
}
F_7 ( V_4 ) ;
break;
default:
F_77 ( V_4 ) ;
break;
}
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_25 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
return V_3 & V_73 ? 1 : 0 ;
}
static void F_83 ( struct V_9 * V_4 ,
struct V_94 * V_95 )
{
T_2 V_8 ;
switch ( V_95 -> V_97 & V_98 ) {
case V_99 :
V_4 -> V_104 = 1 << V_105 ;
break;
case V_100 :
V_4 -> V_104 = 0 ;
break;
case V_101 :
V_8 = V_95 -> V_102 & V_103 ;
if ( V_8 )
V_4 -> V_104 =
F_82 ( V_4 -> V_2 [ V_8 ] )
<< V_106 ;
else
F_77 ( V_4 ) ;
break;
default:
F_77 ( V_4 ) ;
return;
}
V_4 -> V_107 -> V_63 = & V_4 -> V_104 ;
V_4 -> V_107 -> V_62 = 2 ;
F_10 ( & V_4 -> V_20 ) ;
F_61 ( V_4 -> V_16 . V_108 , V_4 -> V_107 , V_109 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
static int F_84 ( struct V_9 * V_4 ,
struct V_94 * V_95 )
{
T_2 * V_110 = ( T_2 * ) V_95 ;
T_2 V_75 = 0 ;
F_73 ( V_4 , V_110 ) ;
V_4 -> V_2 [ 0 ] -> V_7 = V_95 -> V_97 & V_111 ;
if ( V_4 -> V_16 . V_17 == V_18 ) {
T_1 V_3 = F_2 ( V_4 -> V_5 + V_112 ) ;
V_4 -> V_16 . V_17 = V_3 & V_113 ?
V_114 : V_115 ;
}
if ( ( V_95 -> V_97 & V_116 ) == V_117 ) {
switch ( V_95 -> V_118 ) {
case V_119 :
F_83 ( V_4 , V_95 ) ;
break;
case V_120 :
F_81 ( V_4 , V_95 ) ;
break;
case V_121 :
F_79 ( V_4 , V_95 ) ;
break;
case V_122 :
F_78 ( V_4 , V_95 ) ;
break;
case V_123 :
F_74 ( V_4 ) ;
V_75 = 1 ;
break;
default:
V_75 = 1 ;
break;
}
} else {
V_75 = 1 ;
}
return V_75 ;
}
static void F_85 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 [ 0 ] ;
if ( ! F_12 ( & V_2 -> V_15 ) && ! V_2 -> V_7 ) {
struct V_12 * V_13 ;
V_13 = F_86 ( & V_2 -> V_15 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_62 )
F_54 ( V_2 , V_13 ) ;
if ( ( V_13 -> V_13 . V_62 - V_13 -> V_13 . V_64 ) < V_2 -> V_2 . V_30 )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
F_57 ( L_4 , V_68 ) ;
}
}
static void F_87 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 [ 0 ] ;
if ( ( ! F_12 ( & V_2 -> V_15 ) ) && ( V_2 -> V_7 ) ) {
struct V_12 * V_13 ;
V_13 = F_39 ( V_2 -> V_15 . V_37 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_62 )
F_54 ( V_2 , V_13 ) ;
if ( ( V_13 -> V_13 . V_62 - V_13 -> V_13 . V_64 ) < V_2 -> V_2 . V_30 )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
F_7 ( V_4 ) ;
}
}
static void F_88 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_124 ) ;
V_3 &= ~ V_125 ;
F_5 ( V_3 , V_4 -> V_5 + V_124 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_39 ( V_2 -> V_15 . V_37 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_62 )
F_54 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_13 , 0 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_39 ( V_2 -> V_15 . V_37 ,
struct V_12 , V_15 ) ;
F_54 ( V_2 , V_13 ) ;
if ( V_13 -> V_13 . V_62 == V_13 -> V_13 . V_64 ||
V_13 -> V_13 . V_64 < V_2 -> V_2 . V_30 )
F_8 ( V_2 , V_13 , 0 ) ;
}
static T_6 F_91 ( int V_126 , void * V_127 )
{
struct V_9 * V_4 = V_127 ;
T_1 V_128 = F_2 ( V_4 -> V_5 + V_129 ) ;
T_1 V_130 = F_2 ( V_4 -> V_5 + V_131 ) ;
V_128 &= ~ V_130 ;
F_11 ( & V_4 -> V_20 ) ;
if ( V_128 & V_132 ) {
void T_3 * V_5 = V_4 -> V_5 + V_53 ;
T_1 V_133 = F_2 ( V_5 ) ;
T_1 V_134 = F_2 ( V_4 -> V_5 + V_48 ) ;
T_1 V_3 ;
V_133 &= ~ V_134 ;
if ( V_133 & V_54 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_54 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_5 ) ;
}
if ( V_133 & V_135 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_135 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_6 ) ;
}
if ( V_133 & V_136 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_136 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_7 ) ;
}
if ( V_133 & V_137 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_137 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_8 ) ;
}
if ( V_133 & V_138 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_138 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_9 ) ;
}
if ( V_133 & V_139 ) {
F_71 ( V_4 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_139 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_10 ) ;
}
if ( V_133 & V_140 ) {
F_72 ( V_4 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_140 ;
F_5 ( V_3 , V_5 ) ;
F_92 ( L_11 ) ;
}
if ( V_133 & V_55 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_55 ;
F_5 ( V_3 , V_5 ) ;
}
}
if ( V_128 & V_141 ) {
void T_3 * V_5 = V_4 -> V_5 + V_124 ;
T_1 V_142 = F_2 ( V_5 ) ;
T_1 V_143 = F_2 ( V_4 -> V_5 + V_69 ) ;
struct V_94 V_95 ;
V_142 &= ~ V_143 ;
if ( V_142 & V_125 ) {
F_88 ( V_4 ) ;
F_92 ( L_12 ) ;
}
if ( V_142 & V_144 ) {
if ( F_84 ( V_4 , & V_95 ) ) {
F_10 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_145 -> V_146 ( & V_4 -> V_16 ,
& V_95 ) < 0 )
F_76 ( V_4 ) ;
F_11 ( & V_4 -> V_20 ) ;
}
}
if ( V_142 & V_147 )
F_92 ( L_13 ) ;
if ( V_142 & V_148 )
F_87 ( V_4 ) ;
if ( V_142 & V_149 )
F_85 ( V_4 ) ;
if ( V_142 & V_150 ) {
F_76 ( V_4 ) ;
F_92 ( L_14 ) ;
}
}
if ( V_128 & V_151 ) {
void T_3 * V_5 = V_4 -> V_5 + V_152 ;
T_1 V_153 = F_2 ( V_5 ) ;
T_1 V_154 = F_2 ( V_4 -> V_5 + V_6 ) ;
int V_155 ;
V_153 &= ~ V_154 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ ) {
if ( V_153 & F_93 ( V_155 ) )
F_89 ( V_4 -> V_2 [ V_155 + 1 ] ) ;
if ( ( V_153 & F_94 ( V_155 ) ) ||
( V_153 & F_95 ( V_155 ) ) )
F_90 ( V_4 -> V_2 [ V_155 + 1 ] ) ;
}
}
F_10 ( & V_4 -> V_20 ) ;
return V_157 ;
}
static void F_96 ( struct V_9 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_5 + V_158 ) ;
V_5 &= ~ V_159 ;
F_5 ( V_5 , V_4 -> V_5 + V_158 ) ;
}
static int F_97 ( struct V_160 * V_161 ,
struct V_162 * V_145 )
{
struct V_9 * V_4 = F_98 ( V_161 ) ;
T_1 V_3 ;
V_145 -> V_145 . V_163 = NULL ;
V_4 -> V_145 = V_145 ;
V_3 = F_2 ( V_4 -> V_5 + V_112 ) ;
V_3 |= V_164 ;
F_5 ( V_3 , V_4 -> V_5 + V_112 ) ;
return 0 ;
}
static void F_99 ( struct V_9 * V_4 )
{
T_1 V_3 ;
F_5 ( V_165 | V_166 | V_167 ,
V_4 -> V_5 + V_168 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_112 ) ;
V_3 &= ~ V_164 ;
F_5 ( V_3 , V_4 -> V_5 + V_112 ) ;
F_5 ( ~ ( T_1 ) 0 , V_4 -> V_5 + V_6 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_69 ) ;
V_3 |= V_169 ;
F_5 ( V_3 , V_4 -> V_5 + V_69 ) ;
}
static int F_100 ( struct V_160 * V_161 ,
struct V_162 * V_145 )
{
struct V_9 * V_4 = F_98 ( V_161 ) ;
unsigned long V_36 ;
F_40 ( & V_4 -> V_20 , V_36 ) ;
F_99 ( V_4 ) ;
V_4 -> V_145 = NULL ;
F_41 ( & V_4 -> V_20 , V_36 ) ;
return 0 ;
}
static int F_101 ( struct V_170 * V_171 )
{
struct V_9 * V_4 = F_102 ( V_171 ) ;
F_103 ( & V_4 -> V_16 ) ;
F_104 ( V_4 -> V_5 ) ;
F_105 ( F_106 ( V_171 , 0 ) , V_4 ) ;
F_45 ( & V_4 -> V_2 [ 0 ] -> V_2 , V_4 -> V_107 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static int F_107 ( struct V_170 * V_171 )
{
struct V_172 * V_173 , * V_174 ;
struct V_9 * V_4 = NULL ;
struct V_1 * V_32 [ V_175 ] ;
int V_75 = 0 ;
int V_86 ;
V_173 = F_108 ( V_171 , V_176 , 0 ) ;
if ( ! V_173 ) {
F_57 ( L_15 ) ;
return - V_177 ;
}
V_174 = F_108 ( V_171 , V_178 , 0 ) ;
if ( ! V_174 ) {
F_57 ( L_16 ) ;
return - V_177 ;
}
V_75 = - V_179 ;
V_4 = F_43 ( sizeof( struct V_9 ) , V_109 ) ;
if ( V_4 == NULL ) {
F_57 ( L_17 ) ;
goto V_180;
}
for ( V_86 = 0 ; V_86 < V_175 ; V_86 ++ ) {
V_32 [ V_86 ] = F_43 ( sizeof( struct V_1 ) , V_109 ) ;
if ( V_32 [ V_86 ] == NULL ) {
F_57 ( L_18 ) ;
goto V_180;
}
V_4 -> V_2 [ V_86 ] = V_32 [ V_86 ] ;
}
V_4 -> V_5 = F_109 ( V_173 -> V_181 , F_110 ( V_173 ) ) ;
if ( V_4 -> V_5 == NULL ) {
F_57 ( L_19 ) ;
goto V_182;
}
F_111 ( & V_4 -> V_20 ) ;
F_112 ( V_171 , V_4 ) ;
V_4 -> V_16 . V_183 = & V_184 ;
V_4 -> V_16 . V_185 = V_114 ;
V_4 -> V_16 . V_186 . V_187 = & V_171 -> V_186 ;
V_4 -> V_16 . V_186 . V_188 = V_171 -> V_186 . V_188 ;
V_4 -> V_16 . V_189 = V_190 ;
F_44 ( & V_4 -> V_16 . V_191 ) ;
for ( V_86 = 0 ; V_86 < V_175 ; V_86 ++ ) {
struct V_1 * V_2 = V_4 -> V_2 [ V_86 ] ;
if ( V_86 ) {
F_44 ( & V_4 -> V_2 [ V_86 ] -> V_2 . V_191 ) ;
F_62 ( & V_4 -> V_2 [ V_86 ] -> V_2 . V_191 ,
& V_4 -> V_16 . V_191 ) ;
}
V_2 -> V_4 = V_4 ;
F_44 ( & V_2 -> V_15 ) ;
V_2 -> V_2 . V_189 = V_192 [ V_86 ] ;
V_2 -> V_2 . V_183 = & V_193 ;
}
V_4 -> V_2 [ 0 ] -> V_2 . V_30 = 0x40 ;
V_4 -> V_16 . V_108 = & V_4 -> V_2 [ 0 ] -> V_2 ;
F_44 ( & V_4 -> V_16 . V_108 -> V_191 ) ;
V_4 -> V_107 = F_42 ( & V_4 -> V_2 [ 0 ] -> V_2 ,
V_109 ) ;
if ( V_4 -> V_107 == NULL )
goto V_194;
F_99 ( V_4 ) ;
F_96 ( V_4 ) ;
V_75 = F_113 ( V_174 -> V_181 , F_91 , V_195 ,
V_190 , V_4 ) ;
if ( V_75 < 0 ) {
F_57 ( L_20 , V_75 ) ;
goto V_196;
}
V_75 = F_114 ( & V_171 -> V_186 , & V_4 -> V_16 ) ;
if ( V_75 )
goto V_197;
F_115 ( & V_171 -> V_186 , L_21 , V_198 ) ;
return 0 ;
V_197:
V_196:
F_105 ( V_174 -> V_181 , V_4 ) ;
V_194:
F_45 ( & V_4 -> V_2 [ 0 ] -> V_2 , V_4 -> V_107 ) ;
V_182:
if ( V_4 -> V_5 )
F_104 ( V_4 -> V_5 ) ;
V_180:
F_46 ( V_4 ) ;
return V_75 ;
}
