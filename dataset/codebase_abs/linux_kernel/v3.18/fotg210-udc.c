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
F_11 ( & V_2 -> V_2 , & V_13 -> V_13 ) ;
F_12 ( & V_2 -> V_4 -> V_20 ) ;
if ( V_2 -> V_8 ) {
if ( F_13 ( & V_2 -> V_15 ) )
F_1 ( V_2 ) ;
} else {
F_7 ( V_2 -> V_4 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 V_8 ,
T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_21 ;
V_21 = F_2 ( V_4 -> V_5 + V_22 ) ;
V_21 &= ~ F_15 ( V_8 , V_7 ) ;
V_21 |= F_16 ( V_8 , V_7 ) ;
F_5 ( V_21 , V_4 -> V_5 + V_22 ) ;
V_21 = F_2 ( V_4 -> V_5 + V_23 ) ;
V_21 &= ~ F_17 ( V_8 ) ;
V_21 |= F_18 ( V_8 ) ;
F_5 ( V_21 , V_4 -> V_5 + V_23 ) ;
V_21 = F_2 ( V_4 -> V_5 + V_24 ) ;
V_21 |= F_19 ( V_8 - 1 ) ;
F_5 ( V_21 , V_4 -> V_5 + V_24 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_21 ;
V_21 = F_2 ( V_4 -> V_5 + V_23 ) ;
V_21 |= ( V_7 ? F_21 ( V_8 - 1 ) : F_22 ( V_8 - 1 ) ) ;
F_5 ( V_21 , V_4 -> V_5 + V_23 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_8 , T_1 type )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_21 ;
V_21 = F_2 ( V_4 -> V_5 + V_24 ) ;
V_21 |= F_24 ( type , V_8 - 1 ) ;
F_5 ( V_21 , V_4 -> V_5 + V_24 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_25 ,
T_1 V_7 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_21 ;
T_1 V_26 = V_7 ? F_26 ( V_8 ) :
F_27 ( V_8 ) ;
V_21 = F_2 ( V_4 -> V_5 + V_26 ) ;
V_21 |= F_28 ( V_25 ) ;
F_5 ( V_21 , V_4 -> V_5 + V_26 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
F_20 ( V_2 , V_2 -> V_8 , V_2 -> V_7 ) ;
F_23 ( V_2 , V_2 -> V_8 , V_2 -> type ) ;
F_25 ( V_2 , V_2 -> V_8 , V_2 -> V_2 . V_29 , V_2 -> V_7 ) ;
F_14 ( V_2 , V_2 -> V_8 , V_2 -> V_7 ) ;
V_4 -> V_2 [ V_2 -> V_8 ] = V_2 ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_31 , struct V_1 , V_2 ) ;
V_2 -> V_28 = V_28 ;
V_2 -> V_8 = F_32 ( V_28 ) ;
V_2 -> type = F_33 ( V_28 ) ;
V_2 -> V_7 = F_34 ( V_28 ) ;
V_2 -> V_2 . V_29 = F_35 ( V_28 ) ;
return F_29 ( V_2 , V_28 ) ;
}
static void F_36 ( struct V_9 * V_4 , T_2 V_8 )
{
struct V_1 * V_2 = V_4 -> V_2 [ V_8 ] ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_26 ( V_8 ) :
V_4 -> V_5 + F_27 ( V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_32 ;
F_5 ( V_3 , V_5 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_32 ;
F_5 ( V_3 , V_5 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_8 )
return 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
F_36 ( V_2 -> V_4 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_38 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_35 ;
F_39 ( ! V_31 ) ;
V_2 = F_31 ( V_31 , struct V_1 , V_2 ) ;
while ( ! F_13 ( & V_2 -> V_15 ) ) {
V_13 = F_40 ( V_2 -> V_15 . V_36 ,
struct V_12 , V_15 ) ;
F_41 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
F_8 ( V_2 , V_13 , - V_37 ) ;
F_42 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
}
return F_37 ( V_2 ) ;
}
static struct V_38 * F_43 ( struct V_30 * V_31 ,
T_4 V_39 )
{
struct V_12 * V_13 ;
V_13 = F_44 ( sizeof( struct V_12 ) , V_39 ) ;
if ( ! V_13 )
return NULL ;
F_45 ( & V_13 -> V_15 ) ;
return & V_13 -> V_13 ;
}
static void F_46 ( struct V_30 * V_31 ,
struct V_38 * V_40 )
{
struct V_12 * V_13 ;
V_13 = F_31 ( V_40 , struct V_12 , V_13 ) ;
F_47 ( V_13 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
T_5 V_41 , T_1 V_42 )
{
T_1 V_3 ;
struct V_9 * V_4 = V_2 -> V_4 ;
V_3 = F_2 ( V_4 -> V_5 + V_43 ) ;
V_3 &= ~ ( F_49 ( 0xFFFF ) | F_50 ( 1 ) ) ;
V_3 |= F_49 ( V_42 ) | F_50 ( V_2 -> V_7 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_43 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_44 ) ;
if ( V_2 -> V_8 )
V_3 |= F_51 ( V_2 -> V_8 - 1 ) ;
else
V_3 |= V_45 ;
F_5 ( V_3 , V_4 -> V_5 + V_44 ) ;
F_5 ( V_41 , V_4 -> V_5 + V_46 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_47 ) ;
V_3 &= ~ ( V_48 | V_49 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_47 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_43 ) ;
V_3 |= V_50 ;
F_5 ( V_3 , V_4 -> V_5 + V_43 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_5 ( V_51 , V_2 -> V_4 -> V_5 + V_44 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
T_1 V_3 ;
do {
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_52 ) ;
if ( ( V_3 & V_53 ) ||
( V_3 & V_54 ) )
goto V_55;
} while ( ! ( V_3 & V_56 ) );
V_3 &= ~ V_56 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_52 ) ;
return;
V_55:
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_43 ) ;
V_3 |= V_57 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_43 ) ;
if ( V_2 -> V_8 ) {
V_3 = F_2 ( V_2 -> V_4 -> V_5 +
F_54 ( V_2 -> V_8 - 1 ) ) ;
V_3 |= V_58 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 +
F_54 ( V_2 -> V_8 - 1 ) ) ;
} else {
V_3 = F_2 ( V_2 -> V_4 -> V_5 + V_10 ) ;
V_3 |= V_59 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_10 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
T_5 V_41 ;
T_2 * V_60 ;
T_1 V_61 ;
if ( V_2 -> V_8 ) {
if ( V_2 -> V_7 ) {
V_60 = V_13 -> V_13 . V_62 ;
V_61 = V_13 -> V_13 . V_61 ;
} else {
V_60 = V_13 -> V_13 . V_62 + V_13 -> V_13 . V_63 ;
V_61 = F_2 ( V_2 -> V_4 -> V_5 +
F_54 ( V_2 -> V_8 - 1 ) ) ;
V_61 &= V_64 ;
}
} else {
V_60 = V_13 -> V_13 . V_62 + V_13 -> V_13 . V_63 ;
if ( V_13 -> V_13 . V_61 - V_13 -> V_13 . V_63 > V_2 -> V_2 . V_29 )
V_61 = V_2 -> V_2 . V_29 ;
else
V_61 = V_13 -> V_13 . V_61 ;
}
V_41 = F_56 ( NULL , V_60 , V_61 ,
V_2 -> V_7 ? V_65 : V_66 ) ;
if ( F_57 ( NULL , V_41 ) ) {
F_58 ( L_1 ) ;
return;
}
F_59 ( NULL , V_41 , V_61 ,
V_2 -> V_7 ? V_65 :
V_66 ) ;
F_48 ( V_2 , V_41 , V_61 ) ;
F_53 ( V_2 ) ;
F_52 ( V_2 ) ;
V_13 -> V_13 . V_63 += V_61 ;
F_60 ( NULL , V_41 , V_61 , V_65 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( ! V_13 -> V_13 . V_61 ) {
F_8 ( V_2 , V_13 , 0 ) ;
return;
}
if ( V_2 -> V_7 ) {
if ( V_13 -> V_13 . V_61 ) {
F_55 ( V_2 , V_13 ) ;
} else {
F_58 ( L_2 ,
V_67 , V_13 -> V_13 . V_61 ) ;
}
if ( ( V_13 -> V_13 . V_61 == V_13 -> V_13 . V_63 ) ||
( V_13 -> V_13 . V_63 < V_2 -> V_2 . V_29 ) )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
if ( ! V_13 -> V_13 . V_61 ) {
F_8 ( V_2 , V_13 , 0 ) ;
} else {
T_1 V_3 = F_2 ( V_2 -> V_4 -> V_5 +
V_68 ) ;
V_3 &= ~ V_69 ;
F_5 ( V_3 , V_2 -> V_4 -> V_5 + V_68 ) ;
}
}
}
static int F_62 ( struct V_30 * V_31 , struct V_38 * V_40 ,
T_4 V_39 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_35 ;
int V_70 = 0 ;
V_2 = F_31 ( V_31 , struct V_1 , V_2 ) ;
V_13 = F_31 ( V_40 , struct V_12 , V_13 ) ;
if ( V_2 -> V_4 -> V_16 . V_17 == V_18 )
return - V_19 ;
F_41 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
if ( F_13 ( & V_2 -> V_15 ) )
V_70 = 1 ;
F_63 ( & V_13 -> V_15 , & V_2 -> V_15 ) ;
V_13 -> V_13 . V_63 = 0 ;
V_13 -> V_13 . V_14 = - V_71 ;
if ( ! V_2 -> V_8 )
F_61 ( V_2 , V_13 ) ;
else if ( V_70 && ! V_2 -> V_33 )
F_6 ( V_2 ) ;
F_42 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
return 0 ;
}
static int F_64 ( struct V_30 * V_31 , struct V_38 * V_40 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
unsigned long V_35 ;
V_2 = F_31 ( V_31 , struct V_1 , V_2 ) ;
V_13 = F_31 ( V_40 , struct V_12 , V_13 ) ;
F_41 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
if ( ! F_13 ( & V_2 -> V_15 ) )
F_8 ( V_2 , V_13 , - V_37 ) ;
F_42 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
if ( V_2 -> V_7 ) {
do {
V_3 = F_2 ( V_4 -> V_5 + V_10 ) ;
} while ( ! ( V_3 & F_66 ( V_2 -> V_8 - 1 ) ) );
}
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_27 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 |= V_72 ;
F_5 ( V_3 , V_5 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_27 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_72 ;
F_5 ( V_3 , V_5 ) ;
}
static int F_68 ( struct V_30 * V_31 , int V_3 , int V_73 )
{
struct V_1 * V_2 ;
struct V_9 * V_4 ;
unsigned long V_35 ;
int V_74 = 0 ;
V_2 = F_31 ( V_31 , struct V_1 , V_2 ) ;
V_4 = V_2 -> V_4 ;
F_41 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
if ( V_3 ) {
F_65 ( V_2 ) ;
V_2 -> V_33 = 1 ;
if ( V_73 )
V_2 -> V_34 = 1 ;
} else {
F_36 ( V_4 , V_2 -> V_8 ) ;
F_67 ( V_2 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
if ( ! F_13 ( & V_2 -> V_15 ) )
F_6 ( V_2 ) ;
}
F_42 ( & V_2 -> V_4 -> V_20 , V_35 ) ;
return V_74 ;
}
static int F_69 ( struct V_30 * V_31 , int V_3 )
{
return F_68 ( V_31 , V_3 , 0 ) ;
}
static int F_70 ( struct V_30 * V_31 )
{
return F_68 ( V_31 , 1 , 1 ) ;
}
static void F_71 ( struct V_30 * V_31 )
{
}
static void F_72 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_75 ) ;
V_3 &= ~ ( V_76 | V_77 | V_78
| V_79 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_75 ) ;
}
static void F_73 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_80 ) ;
V_3 &= ~ ( V_81 | V_82 | V_83
| V_84 ) ;
F_5 ( V_3 , V_4 -> V_5 + V_80 ) ;
}
static void F_74 ( struct V_9 * V_4 ,
T_2 * V_60 )
{
int V_85 = 0 ;
T_2 * V_86 = V_60 ;
T_1 V_87 ;
T_1 V_61 = 8 ;
F_5 ( V_45 , V_4 -> V_5 + V_44 ) ;
for ( V_85 = ( V_61 >> 2 ) ; V_85 > 0 ; V_85 -- ) {
V_87 = F_2 ( V_4 -> V_5 + V_88 ) ;
* V_86 = V_87 & 0xFF ;
* ( V_86 + 1 ) = ( V_87 >> 8 ) & 0xFF ;
* ( V_86 + 2 ) = ( V_87 >> 16 ) & 0xFF ;
* ( V_86 + 3 ) = ( V_87 >> 24 ) & 0xFF ;
V_86 = V_86 + 4 ;
}
switch ( V_61 % 4 ) {
case 1 :
V_87 = F_2 ( V_4 -> V_5 + V_88 ) ;
* V_86 = V_87 & 0xFF ;
break;
case 2 :
V_87 = F_2 ( V_4 -> V_5 + V_88 ) ;
* V_86 = V_87 & 0xFF ;
* ( V_86 + 1 ) = ( V_87 >> 8 ) & 0xFF ;
break;
case 3 :
V_87 = F_2 ( V_4 -> V_5 + V_88 ) ;
* V_86 = V_87 & 0xFF ;
* ( V_86 + 1 ) = ( V_87 >> 8 ) & 0xFF ;
* ( V_86 + 2 ) = ( V_87 >> 16 ) & 0xFF ;
break;
default:
break;
}
F_5 ( V_51 , V_4 -> V_5 + V_44 ) ;
}
static void F_75 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_89 ) ;
V_3 |= V_90 ;
F_5 ( V_3 , V_4 -> V_5 + V_89 ) ;
}
static void F_76 ( struct V_9 * V_4 , T_1 V_91 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_89 ) ;
V_3 |= ( V_91 & 0x7F ) ;
F_5 ( V_3 , V_4 -> V_5 + V_89 ) ;
}
static void F_77 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_10 ) ;
V_3 |= V_92 ;
F_5 ( V_3 , V_4 -> V_5 + V_10 ) ;
}
static void F_78 ( struct V_9 * V_4 )
{
F_77 ( V_4 ) ;
F_58 ( L_3 ) ;
}
static void F_79 ( struct V_9 * V_4 ,
struct V_93 * V_94 )
{
if ( V_94 -> V_95 >= 0x0100 ) {
F_78 ( V_4 ) ;
} else {
F_76 ( V_4 , V_94 -> V_95 ) ;
F_7 ( V_4 ) ;
}
}
static void F_80 ( struct V_9 * V_4 ,
struct V_93 * V_94 )
{
switch ( V_94 -> V_96 & V_97 ) {
case V_98 :
F_7 ( V_4 ) ;
break;
case V_99 :
F_7 ( V_4 ) ;
break;
case V_100 : {
T_2 V_8 ;
V_8 = F_81 ( V_94 -> V_101 ) & V_102 ;
if ( V_8 )
F_65 ( V_4 -> V_2 [ V_8 ] ) ;
else
F_77 ( V_4 ) ;
F_7 ( V_4 ) ;
}
break;
default:
F_78 ( V_4 ) ;
break;
}
}
static void F_82 ( struct V_9 * V_4 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 =
V_4 -> V_2 [ V_94 -> V_101 & V_102 ] ;
switch ( V_94 -> V_96 & V_97 ) {
case V_98 :
F_7 ( V_4 ) ;
break;
case V_99 :
F_7 ( V_4 ) ;
break;
case V_100 :
if ( V_94 -> V_101 & V_102 ) {
if ( V_2 -> V_34 ) {
F_7 ( V_4 ) ;
break;
}
if ( V_2 -> V_33 )
F_68 ( & V_2 -> V_2 , 0 , 0 ) ;
}
F_7 ( V_4 ) ;
break;
default:
F_78 ( V_4 ) ;
break;
}
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_9 * V_4 = V_2 -> V_4 ;
T_1 V_3 ;
void T_3 * V_5 ;
V_5 = ( V_2 -> V_7 ) ?
V_4 -> V_5 + F_26 ( V_2 -> V_8 ) :
V_4 -> V_5 + F_27 ( V_2 -> V_8 ) ;
V_3 = F_2 ( V_5 ) ;
return V_3 & V_72 ? 1 : 0 ;
}
static void F_84 ( struct V_9 * V_4 ,
struct V_93 * V_94 )
{
T_2 V_8 ;
switch ( V_94 -> V_96 & V_97 ) {
case V_98 :
V_4 -> V_103 = 1 << V_104 ;
break;
case V_99 :
V_4 -> V_103 = 0 ;
break;
case V_100 :
V_8 = V_94 -> V_101 & V_102 ;
if ( V_8 )
V_4 -> V_103 =
F_83 ( V_4 -> V_2 [ V_8 ] )
<< V_105 ;
else
F_78 ( V_4 ) ;
break;
default:
F_78 ( V_4 ) ;
return;
}
V_4 -> V_106 -> V_62 = & V_4 -> V_103 ;
V_4 -> V_106 -> V_61 = 2 ;
F_10 ( & V_4 -> V_20 ) ;
F_62 ( V_4 -> V_16 . V_107 , V_4 -> V_106 , V_108 ) ;
F_12 ( & V_4 -> V_20 ) ;
}
static int F_85 ( struct V_9 * V_4 ,
struct V_93 * V_94 )
{
T_2 * V_109 = ( T_2 * ) V_94 ;
T_2 V_74 = 0 ;
F_74 ( V_4 , V_109 ) ;
V_4 -> V_2 [ 0 ] -> V_7 = V_94 -> V_96 & V_110 ;
if ( V_4 -> V_16 . V_17 == V_18 ) {
T_1 V_3 = F_2 ( V_4 -> V_5 + V_111 ) ;
V_4 -> V_16 . V_17 = V_3 & V_112 ?
V_113 : V_114 ;
}
if ( ( V_94 -> V_96 & V_115 ) == V_116 ) {
switch ( V_94 -> V_117 ) {
case V_118 :
F_84 ( V_4 , V_94 ) ;
break;
case V_119 :
F_82 ( V_4 , V_94 ) ;
break;
case V_120 :
F_80 ( V_4 , V_94 ) ;
break;
case V_121 :
F_79 ( V_4 , V_94 ) ;
break;
case V_122 :
F_75 ( V_4 ) ;
V_74 = 1 ;
break;
default:
V_74 = 1 ;
break;
}
} else {
V_74 = 1 ;
}
return V_74 ;
}
static void F_86 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 [ 0 ] ;
if ( ! F_13 ( & V_2 -> V_15 ) && ! V_2 -> V_7 ) {
struct V_12 * V_13 ;
V_13 = F_87 ( & V_2 -> V_15 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_61 )
F_55 ( V_2 , V_13 ) ;
if ( ( V_13 -> V_13 . V_61 - V_13 -> V_13 . V_63 ) < V_2 -> V_2 . V_29 )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
F_58 ( L_4 , V_67 ) ;
}
}
static void F_88 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 [ 0 ] ;
if ( ( ! F_13 ( & V_2 -> V_15 ) ) && ( V_2 -> V_7 ) ) {
struct V_12 * V_13 ;
V_13 = F_40 ( V_2 -> V_15 . V_36 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_61 )
F_55 ( V_2 , V_13 ) ;
if ( ( V_13 -> V_13 . V_61 - V_13 -> V_13 . V_63 ) < V_2 -> V_2 . V_29 )
F_8 ( V_2 , V_13 , 0 ) ;
} else {
F_7 ( V_4 ) ;
}
}
static void F_89 ( struct V_9 * V_4 )
{
T_1 V_3 = F_2 ( V_4 -> V_5 + V_123 ) ;
V_3 &= ~ V_124 ;
F_5 ( V_3 , V_4 -> V_5 + V_123 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_40 ( V_2 -> V_15 . V_36 ,
struct V_12 , V_15 ) ;
if ( V_13 -> V_13 . V_61 )
F_55 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_13 , 0 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_40 ( V_2 -> V_15 . V_36 ,
struct V_12 , V_15 ) ;
F_55 ( V_2 , V_13 ) ;
if ( V_13 -> V_13 . V_61 == V_13 -> V_13 . V_63 ||
V_13 -> V_13 . V_63 < V_2 -> V_2 . V_29 )
F_8 ( V_2 , V_13 , 0 ) ;
}
static T_6 F_92 ( int V_125 , void * V_126 )
{
struct V_9 * V_4 = V_126 ;
T_1 V_127 = F_2 ( V_4 -> V_5 + V_128 ) ;
T_1 V_129 = F_2 ( V_4 -> V_5 + V_130 ) ;
V_127 &= ~ V_129 ;
F_12 ( & V_4 -> V_20 ) ;
if ( V_127 & V_131 ) {
void T_3 * V_5 = V_4 -> V_5 + V_52 ;
T_1 V_132 = F_2 ( V_5 ) ;
T_1 V_133 = F_2 ( V_4 -> V_5 + V_47 ) ;
T_1 V_3 ;
V_132 &= ~ V_133 ;
if ( V_132 & V_53 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_53 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_5 ) ;
}
if ( V_132 & V_134 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_134 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_6 ) ;
}
if ( V_132 & V_135 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_135 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_7 ) ;
}
if ( V_132 & V_136 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_136 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_8 ) ;
}
if ( V_132 & V_137 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_137 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_9 ) ;
}
if ( V_132 & V_138 ) {
F_72 ( V_4 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_138 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_10 ) ;
}
if ( V_132 & V_139 ) {
F_73 ( V_4 ) ;
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_139 ;
F_5 ( V_3 , V_5 ) ;
F_93 ( L_11 ) ;
}
if ( V_132 & V_54 ) {
V_3 = F_2 ( V_5 ) ;
V_3 &= ~ V_54 ;
F_5 ( V_3 , V_5 ) ;
}
}
if ( V_127 & V_140 ) {
void T_3 * V_5 = V_4 -> V_5 + V_123 ;
T_1 V_141 = F_2 ( V_5 ) ;
T_1 V_142 = F_2 ( V_4 -> V_5 + V_68 ) ;
struct V_93 V_94 ;
V_141 &= ~ V_142 ;
if ( V_141 & V_124 ) {
F_89 ( V_4 ) ;
F_93 ( L_12 ) ;
}
if ( V_141 & V_143 ) {
if ( F_85 ( V_4 , & V_94 ) ) {
F_10 ( & V_4 -> V_20 ) ;
if ( V_4 -> V_144 -> V_145 ( & V_4 -> V_16 ,
& V_94 ) < 0 )
F_77 ( V_4 ) ;
F_12 ( & V_4 -> V_20 ) ;
}
}
if ( V_141 & V_146 )
F_93 ( L_13 ) ;
if ( V_141 & V_147 )
F_88 ( V_4 ) ;
if ( V_141 & V_148 )
F_86 ( V_4 ) ;
if ( V_141 & V_149 ) {
F_77 ( V_4 ) ;
F_93 ( L_14 ) ;
}
}
if ( V_127 & V_150 ) {
void T_3 * V_5 = V_4 -> V_5 + V_151 ;
T_1 V_152 = F_2 ( V_5 ) ;
T_1 V_153 = F_2 ( V_4 -> V_5 + V_6 ) ;
int V_154 ;
V_152 &= ~ V_153 ;
for ( V_154 = 0 ; V_154 < V_155 ; V_154 ++ ) {
if ( V_152 & F_94 ( V_154 ) )
F_90 ( V_4 -> V_2 [ V_154 + 1 ] ) ;
if ( ( V_152 & F_95 ( V_154 ) ) ||
( V_152 & F_96 ( V_154 ) ) )
F_91 ( V_4 -> V_2 [ V_154 + 1 ] ) ;
}
}
F_10 ( & V_4 -> V_20 ) ;
return V_156 ;
}
static void F_97 ( struct V_9 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_5 + V_157 ) ;
V_5 &= ~ V_158 ;
F_5 ( V_5 , V_4 -> V_5 + V_157 ) ;
}
static int F_98 ( struct V_159 * V_160 ,
struct V_161 * V_144 )
{
struct V_9 * V_4 = F_99 ( V_160 ) ;
T_1 V_3 ;
V_144 -> V_144 . V_162 = NULL ;
V_4 -> V_144 = V_144 ;
V_3 = F_2 ( V_4 -> V_5 + V_111 ) ;
V_3 |= V_163 ;
F_5 ( V_3 , V_4 -> V_5 + V_111 ) ;
return 0 ;
}
static void F_100 ( struct V_9 * V_4 )
{
T_1 V_3 ;
F_5 ( V_164 | V_165 | V_166 ,
V_4 -> V_5 + V_167 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_111 ) ;
V_3 &= ~ V_163 ;
F_5 ( V_3 , V_4 -> V_5 + V_111 ) ;
F_5 ( ~ ( T_1 ) 0 , V_4 -> V_5 + V_6 ) ;
V_3 = F_2 ( V_4 -> V_5 + V_68 ) ;
V_3 |= V_168 ;
F_5 ( V_3 , V_4 -> V_5 + V_68 ) ;
}
static int F_101 ( struct V_159 * V_160 ,
struct V_161 * V_144 )
{
struct V_9 * V_4 = F_99 ( V_160 ) ;
unsigned long V_35 ;
F_41 ( & V_4 -> V_20 , V_35 ) ;
F_100 ( V_4 ) ;
V_4 -> V_144 = NULL ;
F_42 ( & V_4 -> V_20 , V_35 ) ;
return 0 ;
}
static int F_102 ( struct V_169 * V_170 )
{
struct V_9 * V_4 = F_103 ( V_170 ) ;
F_104 ( & V_4 -> V_16 ) ;
F_105 ( V_4 -> V_5 ) ;
F_106 ( F_107 ( V_170 , 0 ) , V_4 ) ;
F_46 ( & V_4 -> V_2 [ 0 ] -> V_2 , V_4 -> V_106 ) ;
F_47 ( V_4 ) ;
return 0 ;
}
static int F_108 ( struct V_169 * V_170 )
{
struct V_171 * V_172 , * V_173 ;
struct V_9 * V_4 = NULL ;
struct V_1 * V_31 [ V_174 ] ;
int V_74 = 0 ;
int V_85 ;
V_172 = F_109 ( V_170 , V_175 , 0 ) ;
if ( ! V_172 ) {
F_58 ( L_15 ) ;
return - V_176 ;
}
V_173 = F_109 ( V_170 , V_177 , 0 ) ;
if ( ! V_173 ) {
F_58 ( L_16 ) ;
return - V_176 ;
}
V_74 = - V_178 ;
V_4 = F_44 ( sizeof( struct V_9 ) , V_108 ) ;
if ( V_4 == NULL )
goto V_179;
for ( V_85 = 0 ; V_85 < V_174 ; V_85 ++ ) {
V_31 [ V_85 ] = F_44 ( sizeof( struct V_1 ) , V_108 ) ;
if ( V_31 [ V_85 ] == NULL )
goto V_179;
V_4 -> V_2 [ V_85 ] = V_31 [ V_85 ] ;
}
V_4 -> V_5 = F_110 ( V_172 -> V_180 , F_111 ( V_172 ) ) ;
if ( V_4 -> V_5 == NULL ) {
F_58 ( L_17 ) ;
goto V_181;
}
F_112 ( & V_4 -> V_20 ) ;
F_113 ( V_170 , V_4 ) ;
V_4 -> V_16 . V_182 = & V_183 ;
V_4 -> V_16 . V_184 = V_113 ;
V_4 -> V_16 . V_185 . V_186 = & V_170 -> V_185 ;
V_4 -> V_16 . V_185 . V_187 = V_170 -> V_185 . V_187 ;
V_4 -> V_16 . V_188 = V_189 ;
F_45 ( & V_4 -> V_16 . V_190 ) ;
for ( V_85 = 0 ; V_85 < V_174 ; V_85 ++ ) {
struct V_1 * V_2 = V_4 -> V_2 [ V_85 ] ;
if ( V_85 ) {
F_45 ( & V_4 -> V_2 [ V_85 ] -> V_2 . V_190 ) ;
F_63 ( & V_4 -> V_2 [ V_85 ] -> V_2 . V_190 ,
& V_4 -> V_16 . V_190 ) ;
}
V_2 -> V_4 = V_4 ;
F_45 ( & V_2 -> V_15 ) ;
V_2 -> V_2 . V_188 = V_191 [ V_85 ] ;
V_2 -> V_2 . V_182 = & V_192 ;
F_114 ( & V_2 -> V_2 , ( unsigned short ) ~ 0 ) ;
}
F_114 ( & V_4 -> V_2 [ 0 ] -> V_2 , 0x40 ) ;
V_4 -> V_16 . V_107 = & V_4 -> V_2 [ 0 ] -> V_2 ;
F_45 ( & V_4 -> V_16 . V_107 -> V_190 ) ;
V_4 -> V_106 = F_43 ( & V_4 -> V_2 [ 0 ] -> V_2 ,
V_108 ) ;
if ( V_4 -> V_106 == NULL )
goto V_193;
F_100 ( V_4 ) ;
F_97 ( V_4 ) ;
V_74 = F_115 ( V_173 -> V_180 , F_92 , V_194 ,
V_189 , V_4 ) ;
if ( V_74 < 0 ) {
F_58 ( L_18 , V_74 ) ;
goto V_195;
}
V_74 = F_116 ( & V_170 -> V_185 , & V_4 -> V_16 ) ;
if ( V_74 )
goto V_196;
F_117 ( & V_170 -> V_185 , L_19 , V_197 ) ;
return 0 ;
V_196:
V_195:
F_106 ( V_173 -> V_180 , V_4 ) ;
V_193:
F_46 ( & V_4 -> V_2 [ 0 ] -> V_2 , V_4 -> V_106 ) ;
V_181:
if ( V_4 -> V_5 )
F_105 ( V_4 -> V_5 ) ;
V_179:
F_47 ( V_4 ) ;
return V_74 ;
}
