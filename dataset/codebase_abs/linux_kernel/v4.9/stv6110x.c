static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
const struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 [] = { V_3 } ;
T_1 V_9 [] = { 0 } ;
struct V_10 V_11 [] = {
{ . V_12 = V_7 -> V_12 , . V_13 = 0 , . V_14 = V_8 , . V_15 = 1 } ,
{ . V_12 = V_7 -> V_12 , . V_13 = V_16 , . V_14 = V_9 , . V_15 = 1 }
} ;
V_5 = F_2 ( V_2 -> V_17 , V_11 , 2 ) ;
if ( V_5 != 2 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_19 ;
}
* V_4 = V_9 [ 0 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_20 , T_1 V_4 [] , int V_15 )
{
int V_5 ;
const struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_14 [ V_21 ] ;
struct V_10 V_11 = {
. V_12 = V_7 -> V_12 ,
. V_13 = 0 ,
. V_14 = V_14 ,
. V_15 = V_15 + 1
} ;
if ( 1 + V_15 > sizeof( V_14 ) ) {
F_5 ( V_22
L_2 ,
V_23 , V_15 ) ;
return - V_24 ;
}
if ( V_20 + V_15 > 8 )
return - V_24 ;
V_14 [ 0 ] = V_20 ;
memcpy ( & V_14 [ 1 ] , V_4 , V_15 ) ;
V_5 = F_2 ( V_2 -> V_17 , & V_11 , 1 ) ;
if ( V_5 != 1 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_7 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_5 ;
V_5 = F_4 ( V_2 , 0 , V_2 -> V_28 ,
F_8 ( V_2 -> V_28 ) ) ;
if ( V_5 < 0 ) {
F_3 ( V_18 , 1 , L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_25 * V_26 , T_2 V_29 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
T_2 V_30 , V_31 ;
T_3 V_32 , V_33 , V_34 = 0 , V_35 = 1000 ;
T_1 V_36 ;
F_10 ( V_2 -> V_28 [ V_37 ] , V_38 , ( V_39 - 16 ) ) ;
if ( V_29 <= 1023000 ) {
F_10 ( V_2 -> V_28 [ V_40 ] , V_41 , 1 ) ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_42 , 0 ) ;
V_32 = 40 ;
} else if ( V_29 <= 1300000 ) {
F_10 ( V_2 -> V_28 [ V_40 ] , V_41 , 1 ) ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_42 , 1 ) ;
V_32 = 40 ;
} else if ( V_29 <= 2046000 ) {
F_10 ( V_2 -> V_28 [ V_40 ] , V_41 , 0 ) ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_42 , 0 ) ;
V_32 = 20 ;
} else {
F_10 ( V_2 -> V_28 [ V_40 ] , V_41 , 0 ) ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_42 , 1 ) ;
V_32 = 20 ;
}
for ( V_30 = 0 ; V_30 <= 3 ; V_30 ++ ) {
V_33 = ( V_43 / 100 ) / F_11 ( V_30 ) ;
if ( ( abs ( ( T_3 ) ( V_33 - V_32 ) ) ) < ( abs ( ( T_3 ) ( V_35 - V_32 ) ) ) )
V_34 = V_30 ;
V_35 = ( V_43 / 100 ) / F_11 ( V_34 ) ;
}
V_31 = ( V_29 * F_11 ( V_34 ) * V_32 ) / V_43 ;
V_31 = ( V_31 + 5 ) / 10 ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_44 , V_34 ) ;
F_10 ( V_2 -> V_28 [ V_40 ] , V_45 , F_12 ( V_31 ) ) ;
F_10 ( V_2 -> V_28 [ V_46 ] , V_47 , F_13 ( V_31 ) ) ;
F_10 ( V_2 -> V_28 [ V_48 ] , V_49 , 1 ) ;
F_6 ( V_2 , V_37 , V_2 -> V_28 [ V_37 ] ) ;
F_6 ( V_2 , V_40 , V_2 -> V_28 [ V_40 ] ) ;
F_6 ( V_2 , V_46 , V_2 -> V_28 [ V_46 ] ) ;
F_6 ( V_2 , V_48 , V_2 -> V_28 [ V_48 ] ) ;
for ( V_36 = 0 ; V_36 < V_50 ; V_36 ++ ) {
F_1 ( V_2 , V_48 , & V_2 -> V_28 [ V_48 ] ) ;
if ( ! F_14 ( V_49 , V_2 -> V_28 [ V_48 ] ) )
break;
F_15 ( 1 ) ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_26 , T_2 * V_29 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_1 ( V_2 , V_40 , & V_2 -> V_28 [ V_40 ] ) ;
F_1 ( V_2 , V_46 , & V_2 -> V_28 [ V_46 ] ) ;
* V_29 = ( F_17 ( F_14 ( V_45 , V_2 -> V_28 [ V_40 ] ) ,
F_14 ( V_47 , V_2 -> V_28 [ V_46 ] ) ) ) * V_43 ;
* V_29 /= ( 1 << ( F_14 ( V_44 , V_2 -> V_28 [ V_40 ] ) +
F_14 ( V_41 , V_2 -> V_28 [ V_40 ] ) ) ) ;
* V_29 >>= 2 ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 , T_2 V_51 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
T_2 V_52 ;
T_1 V_36 ;
V_52 = V_51 >> 1 ;
if ( V_52 > 36000000 )
F_10 ( V_2 -> V_28 [ V_53 ] , V_54 , 31 ) ;
else if ( V_52 < 5000000 )
F_10 ( V_2 -> V_28 [ V_53 ] , V_54 , 0 ) ;
else
F_10 ( V_2 -> V_28 [ V_53 ] , V_54 , ( ( V_52 / 1000000 ) - 5 ) ) ;
F_10 ( V_2 -> V_28 [ V_53 ] , V_55 , 0x0 ) ;
F_10 ( V_2 -> V_28 [ V_48 ] , V_56 , 0x1 ) ;
F_6 ( V_2 , V_53 , V_2 -> V_28 [ V_53 ] ) ;
F_6 ( V_2 , V_48 , V_2 -> V_28 [ V_48 ] ) ;
for ( V_36 = 0 ; V_36 < V_50 ; V_36 ++ ) {
F_1 ( V_2 , V_48 , & V_2 -> V_28 [ V_48 ] ) ;
if ( ! F_14 ( V_56 , V_2 -> V_28 [ V_48 ] ) )
break;
F_15 ( 1 ) ;
}
F_10 ( V_2 -> V_28 [ V_53 ] , V_55 , 0x1 ) ;
F_6 ( V_2 , V_53 , V_2 -> V_28 [ V_53 ] ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 , T_2 * V_51 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_1 ( V_2 , V_53 , & V_2 -> V_28 [ V_53 ] ) ;
* V_51 = ( F_14 ( V_54 , V_2 -> V_28 [ V_53 ] ) + 5 ) * 2000000 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_26 , T_2 V_57 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
switch ( V_57 ) {
default:
case 1 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 0 ) ;
break;
case 2 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 1 ) ;
break;
case 4 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 2 ) ;
break;
case 8 :
case 0 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 3 ) ;
break;
}
F_6 ( V_2 , V_58 , V_2 -> V_28 [ V_58 ] ) ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 , T_2 * V_60 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_1 ( V_2 , V_58 , & V_2 -> V_28 [ V_58 ] ) ;
* V_60 = 2 * F_14 ( V_61 , V_2 -> V_28 [ V_58 ] ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 , T_2 V_60 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_10 ( V_2 -> V_28 [ V_58 ] , V_61 , V_60 / 2 ) ;
F_6 ( V_2 , V_58 , V_2 -> V_28 [ V_58 ] ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_26 , enum V_62 V_63 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_5 ;
switch ( V_63 ) {
case V_64 :
F_10 ( V_2 -> V_28 [ V_37 ] , V_65 , 0 ) ;
F_10 ( V_2 -> V_28 [ V_37 ] , V_66 , 0 ) ;
F_10 ( V_2 -> V_28 [ V_37 ] , V_67 , 0 ) ;
break;
case V_68 :
F_10 ( V_2 -> V_28 [ V_37 ] , V_65 , 1 ) ;
F_10 ( V_2 -> V_28 [ V_37 ] , V_66 , 1 ) ;
F_10 ( V_2 -> V_28 [ V_37 ] , V_67 , 1 ) ;
break;
}
V_5 = F_6 ( V_2 , V_37 , V_2 -> V_28 [ V_37 ] ) ;
if ( V_5 < 0 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_24 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 )
return F_23 ( V_26 , V_64 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 , T_2 * V_70 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_1 ( V_2 , V_48 , & V_2 -> V_28 [ V_48 ] ) ;
if ( F_14 ( V_71 , V_2 -> V_28 [ V_48 ] ) )
* V_70 = V_72 ;
else
* V_70 = 0 ;
return 0 ;
}
static int F_26 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
V_26 -> V_27 = NULL ;
F_27 ( V_2 ) ;
return 0 ;
}
const struct V_73 * F_28 ( struct V_25 * V_26 ,
const struct V_6 * V_7 ,
struct V_74 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_75 [] = { 0x07 , 0x11 , 0xdc , 0x85 , 0x17 , 0x01 , 0xe6 , 0x1e } ;
V_2 = F_29 ( sizeof ( struct V_1 ) , V_76 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_17 = V_17 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_77 = & V_78 ;
memcpy ( V_2 -> V_28 , V_75 , 8 ) ;
switch ( V_2 -> V_7 -> V_79 ) {
default:
case 1 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 0 ) ;
break;
case 2 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 1 ) ;
break;
case 4 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 2 ) ;
break;
case 8 :
case 0 :
F_10 ( V_2 -> V_28 [ V_58 ] , V_59 , 3 ) ;
break;
}
V_26 -> V_27 = V_2 ;
V_26 -> V_80 . V_81 = V_82 ;
F_5 ( V_83 L_4 , V_84 ) ;
return V_2 -> V_77 ;
}
