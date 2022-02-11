static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
return F_3 ( V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( V_7 , V_2 -> V_4 + V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 ,
T_1 V_7 )
{
T_1 V_9 ;
V_9 = ( F_1 ( V_2 , V_3 ) & ~ V_8 ) | ( V_8 & V_7 ) ;
F_4 ( V_2 , V_3 , V_9 ) ;
}
static int F_6 ( T_2 V_4 , T_1 V_10 )
{
if ( ! F_7 ( V_4 , 2 , L_1 ) )
return - V_11 ;
F_2 ( V_10 , V_4 + V_5 ) ;
F_2 ( V_10 , V_4 + V_5 ) ;
return 0 ;
}
static void F_8 ( T_2 V_4 )
{
F_2 ( V_12 , V_4 + V_5 ) ;
F_9 ( V_4 + V_5 , 2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_2 V_13 ;
if ( F_1 ( V_2 , V_14 ) != V_15 )
return - V_16 ;
if ( F_1 ( V_2 , V_17 ) != V_18 )
return - V_16 ;
V_13 = F_1 ( V_2 , V_19 ) ;
V_13 |= F_1 ( V_2 , V_20 ) << 8 ;
switch ( V_13 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
break;
default:
return - V_16 ;
}
V_2 -> V_26 = V_13 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int * V_27 ,
int * V_28 )
{
switch ( V_2 -> V_26 ) {
case V_21 :
case V_22 :
* V_27 = V_29 ;
* V_28 = V_30 ;
return 0 ;
case V_23 :
case V_24 :
case V_25 :
* V_27 = V_31 ;
* V_28 = V_32 ;
return 0 ;
}
return - V_16 ;
}
static int F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
T_3 V_37 = 0 ;
struct V_1 * V_2 = V_34 -> V_38 ;
if ( ! V_2 )
return - V_39 ;
if ( V_36 -> V_40 & V_41 )
memset ( V_36 -> V_42 , 0 , sizeof( V_36 -> V_42 ) ) ;
else
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_40 &= V_41 | V_43 |
V_44 ;
if ( V_36 -> V_45 ) {
V_36 -> V_45 = 1 ;
V_37 |= V_46 ;
}
if ( V_36 -> V_47 ) {
V_36 -> V_47 = 1 ;
V_37 |= V_48 ;
}
if ( ( ! ! ( V_36 -> V_40 & V_43 ) ) ==
( ! ! ( V_36 -> V_40 & V_44 ) ) )
V_36 -> V_40 &= V_41 ;
else
V_37 |= V_49 ;
if ( V_36 -> V_40 & V_43 )
V_37 |= V_50 ;
if ( F_6 ( V_2 -> V_4 , V_2 -> V_10 ) )
return - V_11 ;
F_4 ( V_2 , V_51 , V_2 -> V_52 ) ;
F_4 ( V_2 , V_53 , V_37 ) ;
F_8 ( V_2 -> V_4 ) ;
V_34 -> V_36 = * V_36 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , bool V_54 )
{
F_4 ( V_2 , V_51 , V_2 -> V_52 ) ;
switch ( V_2 -> V_26 ) {
case V_22 :
F_5 ( V_2 , V_55 , V_56 ,
0 ) ;
case V_21 :
F_5 ( V_2 , V_57 , V_58 ,
V_58 ) ;
F_5 ( V_2 , V_57 , V_59 ,
V_54 ? 0 : V_59 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
F_5 ( V_2 , V_60 , V_61 ,
V_61 ) ;
F_5 ( V_2 , V_60 , V_62 ,
V_54 ? V_63 : V_64 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_26 ) {
case V_24 :
case V_22 :
F_5 ( V_2 , V_65 ,
V_66 | V_67 ,
V_68 | V_69 ) ;
break;
default:
break;
}
}
static int F_15 ( struct V_1 * V_2 , T_2 V_70 ,
unsigned int V_71 )
{
static const T_2 V_72 [] = { 0x4e , 0x2e } ;
static const T_1 V_73 [] = { 0x77 , 0xa0 , 0x87 , 0x67 } ;
struct V_74 * V_74 ;
bool V_75 = false ;
int V_76 , V_77 , V_78 , V_27 , V_28 ;
for ( V_76 = 0 ; V_76 < F_16 ( V_72 ) ; V_76 ++ ) {
for ( V_77 = 0 ; V_77 < F_16 ( V_73 ) ; V_77 ++ ) {
V_2 -> V_4 = V_72 [ V_76 ] ;
V_2 -> V_10 = V_73 [ V_77 ] ;
if ( F_6 ( V_72 [ V_76 ] , V_73 [ V_77 ] ) )
continue;
if ( F_10 ( V_2 ) ||
F_11 ( V_2 , & V_27 , & V_28 ) ) {
F_8 ( V_72 [ V_76 ] ) ;
continue;
}
for ( V_78 = V_27 ; V_78 < V_28 ; V_78 ++ ) {
T_2 V_79 ;
F_4 ( V_2 , V_51 , V_78 ) ;
V_79 = F_1 ( V_2 , V_80 ) ;
V_79 |= F_1 ( V_2 , V_81 ) << 8 ;
if ( V_79 != V_70 )
continue;
V_2 -> V_52 = V_78 ;
V_74 = F_17 ( V_71 ) ;
if ( V_74 )
V_75 =
F_18 ( V_74 ) ;
F_13 ( V_2 , V_75 ) ;
F_14 ( V_2 ) ;
F_8 ( V_72 [ V_76 ] ) ;
return 0 ;
}
F_8 ( V_72 [ V_76 ] ) ;
}
}
return - V_16 ;
}
static void F_19 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = V_83 -> V_34 . V_38 ;
switch ( V_2 -> V_26 ) {
case V_23 :
case V_24 :
case V_22 :
case V_21 :
V_83 -> V_34 . V_84 = F_12 ;
break;
default:
break;
}
}
int F_20 ( struct V_82 * V_83 )
{
struct V_1 * V_2 ;
struct V_1 V_85 ;
if ( F_15 ( & V_85 , V_83 -> V_34 . V_86 , V_83 -> V_34 . V_71 ) )
return - V_16 ;
V_2 = F_21 ( V_83 -> V_34 . V_87 , sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
memcpy ( V_2 , & V_85 , sizeof( V_85 ) ) ;
V_83 -> V_34 . V_38 = V_2 ;
F_19 ( V_83 ) ;
return 0 ;
}
