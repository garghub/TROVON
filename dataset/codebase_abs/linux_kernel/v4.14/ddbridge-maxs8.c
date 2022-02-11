static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 , V_7 = 0 , V_8 = F_2 ( V_3 ) ;
V_7 = V_9 & ( V_2 -> V_3 [ V_3 ] . V_4 . V_10 << ( 15 - V_4 ) ) ;
F_3 ( V_2 , V_5 | V_7 , V_8 | F_4 ( V_4 ) ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
V_7 = F_5 ( V_2 , V_8 | F_4 ( V_4 ) ) ;
if ( ( V_7 & V_11 ) == 0 )
break;
F_6 ( 20 ) ;
}
if ( V_6 == 10 )
F_7 ( V_2 -> V_2 , L_1 ,
V_12 , V_4 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_5 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_22 [ V_17 -> V_23 & 1 ] ;
T_1 V_8 = F_2 ( V_20 -> V_24 ) ;
int V_25 ;
T_1 V_26 = V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_26 ;
if ( V_26 == 2 || V_26 == 1 )
return 0 ;
if ( V_22 -> V_27 )
V_22 -> V_27 ( V_14 , V_5 ) ;
F_9 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
F_3 ( V_2 , 0 , V_8 | F_10 ( V_22 -> V_17 ) ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_29 ; V_25 ++ )
F_3 ( V_2 , V_5 -> V_30 [ V_25 ] , V_8 | F_11 ( V_22 -> V_17 ) ) ;
F_1 ( V_2 , V_20 -> V_24 , V_22 -> V_17 , V_31 ) ;
F_12 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 ,
struct V_15 * V_5 )
{
T_1 V_8 = F_2 ( V_3 ) ;
int V_25 ;
F_3 ( V_2 , 0 , V_8 | F_10 ( V_17 ) ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_29 ; V_25 ++ )
F_3 ( V_2 , V_5 -> V_30 [ V_25 ] , V_8 | F_11 ( V_17 ) ) ;
F_1 ( V_2 , V_3 , V_17 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 V_32 , T_1 V_33 ,
T_1 V_34 )
{
struct V_15 V_5 = {
. V_30 = { 0xe0 , 0x10 , 0x38 , 0xf0 , 0x00 , 0x00 } ,
. V_29 = 4
} ;
V_5 . V_30 [ 3 ] = 0xf0 | ( ( ( V_32 << 2 ) & 0x0c ) | ( V_33 ? 1 : 0 ) |
( V_34 ? 2 : 0 ) ) ;
return F_13 ( V_2 , V_3 , V_17 , & V_5 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 ,
enum V_35 V_10 )
{
int V_36 = 0 ;
T_1 V_37 = ( 1ULL << V_17 ) ;
switch ( V_10 ) {
case V_38 :
if ( ! ( V_2 -> V_3 [ V_3 ] . V_4 . V_10 & V_37 ) )
return 0 ;
V_2 -> V_3 [ V_3 ] . V_4 . V_10 &= ~ ( 1ULL << V_17 ) ;
break;
case V_39 :
if ( V_2 -> V_3 [ V_3 ] . V_4 . V_10 & V_37 )
return 0 ;
V_2 -> V_3 [ V_3 ] . V_4 . V_10 |= ( 1ULL << V_17 ) ;
break;
default:
V_36 = - V_40 ;
break;
}
if ( ! V_36 )
V_36 = F_1 ( V_2 , V_3 , V_17 , V_41 ) ;
return V_36 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 ,
enum V_42 V_43 )
{
int V_36 = 0 ;
if ( V_2 -> V_3 [ V_3 ] . V_4 . V_44 [ V_17 ] == V_43 )
return 0 ;
switch ( V_43 ) {
case V_45 :
if ( V_2 -> V_3 [ V_3 ] . V_4 . V_43 [ V_17 ] )
return 0 ;
F_1 ( V_2 , V_3 , V_17 , V_46 ) ;
break;
case V_47 :
F_1 ( V_2 , V_3 , V_17 , V_48 ) ;
break;
case V_49 :
F_1 ( V_2 , V_3 , V_17 , V_50 ) ;
break;
default:
V_36 = - V_40 ;
break;
}
V_2 -> V_3 [ V_3 ] . V_4 . V_44 [ V_17 ] = V_43 ;
return V_36 ;
}
static int F_17 ( struct V_13 * V_14 , int V_51 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_22 [ V_17 -> V_23 & 1 ] ;
int V_52 = 0 ;
if ( V_51 > 3 )
return - V_40 ;
if ( V_22 -> V_17 != V_51 ) {
T_1 V_53 = ( 1ULL << V_17 -> V_23 ) ;
T_1 V_54 =
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_43 [ V_22 -> V_17 & 3 ] & V_53 ;
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_43 [ V_22 -> V_17 & 3 ] &= ~ V_53 ;
V_22 -> V_17 = V_51 ;
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_43 [ V_22 -> V_17 & 3 ] |= V_54 ;
}
V_52 = V_22 -> V_55 ( V_14 , V_51 ) ;
return V_52 ;
}
static int F_18 ( struct V_13 * V_14 , enum V_35 V_10 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_22 [ V_17 -> V_23 & 1 ] ;
int V_56 = 0 ;
int V_52 = 0 ;
T_1 V_26 = V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_26 ;
F_9 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
V_22 -> V_10 = V_10 ;
switch ( V_26 ) {
default:
case 0 :
case 3 :
V_52 = F_15 ( V_2 , V_20 -> V_24 , V_22 -> V_17 , V_10 ) ;
break;
case 1 :
case 2 :
if ( V_57 ) {
if ( V_22 -> V_10 == V_39 )
V_56 |= 2 ;
if ( V_22 -> V_43 == V_49 )
V_56 |= 1 ;
} else {
if ( V_22 -> V_10 == V_39 )
V_56 |= 1 ;
if ( V_22 -> V_43 == V_49 )
V_56 |= 2 ;
}
V_52 = F_17 ( V_14 , V_56 ) ;
break;
}
F_12 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
return V_52 ;
}
static int F_19 ( struct V_13 * V_14 , enum V_42 V_43 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_21 * V_22 = & V_20 -> V_22 [ V_17 -> V_23 & 1 ] ;
int V_56 = 0 ;
T_1 V_58 , V_59 = V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_60 ;
int V_52 = 0 ;
T_1 V_26 = V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_26 ;
F_9 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
V_22 -> V_43 = V_43 ;
switch ( V_26 ) {
case 3 :
default:
case 0 :
if ( V_26 == 3 )
F_17 ( V_14 , 0 ) ;
if ( V_43 == V_45 )
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_43 [ V_22 -> V_17 ] &=
~ ( 1ULL << V_17 -> V_23 ) ;
else
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_43 [ V_22 -> V_17 ] |=
( 1ULL << V_17 -> V_23 ) ;
V_52 = F_16 ( V_2 , V_20 -> V_24 , V_22 -> V_17 , V_43 ) ;
break;
case 1 :
case 2 :
if ( V_43 == V_45 )
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_60 &=
~ ( 1ULL << V_17 -> V_23 ) ;
else
V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_60 |=
( 1ULL << V_17 -> V_23 ) ;
V_58 = V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_60 ;
if ( V_57 ) {
if ( V_22 -> V_10 == V_39 )
V_56 |= 2 ;
if ( V_22 -> V_43 == V_49 )
V_56 |= 1 ;
} else {
if ( V_22 -> V_10 == V_39 )
V_56 |= 1 ;
if ( V_22 -> V_43 == V_49 )
V_56 |= 2 ;
}
V_52 = F_17 ( V_14 , V_56 ) ;
if ( V_58 != V_59 ) {
if ( V_58 ) {
F_16 ( V_2 ,
V_20 -> V_24 , 0 , V_47 ) ;
if ( V_26 == 1 ) {
F_16 ( V_2 , V_20 -> V_24 ,
0 , V_47 ) ;
if ( V_57 ) {
F_16 ( V_2 , V_20 -> V_24 ,
1 , V_49 ) ;
F_16 ( V_2 , V_20 -> V_24 ,
2 , V_47 ) ;
} else {
F_16 ( V_2 , V_20 -> V_24 ,
1 , V_47 ) ;
F_16 ( V_2 , V_20 -> V_24 ,
2 , V_49 ) ;
}
F_16 ( V_2 , V_20 -> V_24 ,
3 , V_49 ) ;
}
} else {
F_16 ( V_2 , V_20 -> V_24 ,
0 , V_45 ) ;
if ( V_26 == 1 ) {
F_16 ( V_2 , V_20 -> V_24 ,
1 , V_45 ) ;
F_16 ( V_2 , V_20 -> V_24 ,
2 , V_45 ) ;
F_16 ( V_2 , V_20 -> V_24 ,
3 , V_45 ) ;
}
}
}
break;
}
F_12 ( & V_2 -> V_3 [ V_20 -> V_24 ] . V_4 . V_28 ) ;
return V_52 ;
}
static int F_20 ( struct V_13 * V_14 , long V_61 )
{
return 0 ;
}
static int F_21 ( struct V_13 * V_14 , enum V_62 V_63 )
{
return 0 ;
}
static int F_22 ( void * V_64 , T_2 * V_65 , T_1 V_66 )
{
struct V_67 * V_3 = V_64 ;
struct V_1 * V_2 = V_3 -> V_2 ;
F_7 ( V_2 -> V_2 , L_2 , V_3 -> V_23 ) ;
return F_23 ( V_2 , V_3 -> V_23 , V_65 , 0xc0000 , V_66 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_67 * V_3 , T_1 V_68 )
{
T_1 V_69 = V_3 -> V_23 ;
if ( V_3 -> V_4 . V_26 == V_68 )
return 0 ;
F_7 ( V_2 -> V_2 , L_3 , V_69 , V_68 ) ;
F_9 ( & V_3 -> V_4 . V_28 ) ;
if ( V_68 == 2 || V_68 == 1 ) {
if ( V_70 >= 0 ) {
F_14 ( V_2 , V_69 , 0 , V_70 , 0 , 0 ) ;
if ( V_57 ) {
F_14 ( V_2 , V_69 , 1 , V_70 , 0 , 1 ) ;
F_14 ( V_2 , V_69 , 2 , V_70 , 1 , 0 ) ;
} else {
F_14 ( V_2 , V_69 , 1 , V_70 , 1 , 0 ) ;
F_14 ( V_2 , V_69 , 2 , V_70 , 0 , 1 ) ;
}
F_14 ( V_2 , V_69 , 3 , V_70 , 1 , 1 ) ;
}
F_15 ( V_2 , V_69 , 0 , V_38 ) ;
if ( V_57 ) {
F_15 ( V_2 , V_69 , 1 , V_38 ) ;
F_15 ( V_2 , V_69 , 2 , V_39 ) ;
} else {
F_15 ( V_2 , V_69 , 1 , V_39 ) ;
F_15 ( V_2 , V_69 , 2 , V_38 ) ;
}
F_15 ( V_2 , V_69 , 3 , V_39 ) ;
}
V_3 -> V_4 . V_26 = V_68 ;
F_12 ( & V_3 -> V_4 . V_28 ) ;
return 0 ;
}
int F_25 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 -> V_2 ;
struct V_71 * V_72 = & V_17 -> V_20 -> V_72 -> V_73 ;
struct V_21 * V_22 = & V_17 -> V_20 -> V_22 [ V_17 -> V_23 & 1 ] ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_67 * V_3 = & V_2 -> V_3 [ V_20 -> V_24 ] ;
struct V_74 V_75 ;
int V_76 , V_56 ;
V_75 = V_77 ;
V_75 . V_78 = V_3 ;
V_22 -> V_55 = NULL ;
V_76 = V_17 -> V_23 ;
V_56 = V_76 & 3 ;
if ( V_26 == 3 )
V_56 = 0 ;
V_22 -> V_14 = F_26 ( V_79 , V_72 , & V_75 ,
V_76 , V_56 , & V_22 -> V_55 ) ;
if ( ! V_22 -> V_14 ) {
F_27 ( V_2 -> V_2 , L_4 ) ;
return - V_80 ;
}
if ( ! V_22 -> V_55 ) {
F_27 ( V_2 -> V_2 , L_5 ) ;
return - V_80 ;
}
if ( V_17 -> V_23 < 4 ) {
F_1 ( V_2 , V_20 -> V_24 , V_17 -> V_23 , V_81 ) ;
F_16 ( V_2 , V_20 -> V_24 , V_17 -> V_23 , V_45 ) ;
}
F_24 ( V_2 , V_3 , V_26 ) ;
V_22 -> V_14 -> V_82 . V_83 = F_19 ;
V_22 -> V_14 -> V_82 . V_84 = F_20 ;
V_22 -> V_14 -> V_82 . V_85 = F_18 ;
V_22 -> V_27 = V_22 -> V_14 -> V_82 . V_27 ;
V_22 -> V_14 -> V_82 . V_27 = F_8 ;
V_22 -> V_14 -> V_82 . V_86 = F_21 ;
V_22 -> V_14 -> V_18 = V_17 ;
V_22 -> V_17 = V_56 ;
return 0 ;
}
