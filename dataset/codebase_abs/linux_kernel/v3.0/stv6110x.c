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
T_1 V_14 [ V_15 + 1 ] ;
struct V_10 V_11 = {
. V_12 = V_7 -> V_12 ,
. V_13 = 0 ,
. V_14 = V_14 ,
. V_15 = V_15 + 1
} ;
if ( V_20 + V_15 > 8 )
return - V_21 ;
V_14 [ 0 ] = V_20 ;
memcpy ( & V_14 [ 1 ] , V_4 , V_15 ) ;
V_5 = F_2 ( V_2 -> V_17 , & V_11 , 1 ) ;
if ( V_5 != 1 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_5 ;
V_5 = F_4 ( V_2 , 0 , V_2 -> V_25 ,
F_7 ( V_2 -> V_25 ) ) ;
if ( V_5 < 0 ) {
F_3 ( V_18 , 1 , L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_8 ( struct V_22 * V_23 , T_2 V_26 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_27 , V_28 ;
T_3 V_29 , V_30 , V_31 = 0 , V_32 = 1000 ;
T_1 V_33 ;
F_9 ( V_2 -> V_25 [ V_34 ] , V_35 , ( V_36 - 16 ) ) ;
if ( V_26 <= 1023000 ) {
F_9 ( V_2 -> V_25 [ V_37 ] , V_38 , 1 ) ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_39 , 0 ) ;
V_29 = 40 ;
} else if ( V_26 <= 1300000 ) {
F_9 ( V_2 -> V_25 [ V_37 ] , V_38 , 1 ) ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_39 , 1 ) ;
V_29 = 40 ;
} else if ( V_26 <= 2046000 ) {
F_9 ( V_2 -> V_25 [ V_37 ] , V_38 , 0 ) ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_39 , 0 ) ;
V_29 = 20 ;
} else {
F_9 ( V_2 -> V_25 [ V_37 ] , V_38 , 0 ) ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_39 , 1 ) ;
V_29 = 20 ;
}
for ( V_27 = 0 ; V_27 <= 3 ; V_27 ++ ) {
V_30 = ( V_40 / 100 ) / F_10 ( V_27 ) ;
if ( ( abs ( ( T_3 ) ( V_30 - V_29 ) ) ) < ( abs ( ( T_3 ) ( V_32 - V_29 ) ) ) )
V_31 = V_27 ;
V_32 = ( V_40 / 100 ) / F_10 ( V_31 ) ;
}
V_28 = ( V_26 * F_10 ( V_31 ) * V_29 ) / V_40 ;
V_28 = ( V_28 + 5 ) / 10 ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_41 , V_31 ) ;
F_9 ( V_2 -> V_25 [ V_37 ] , V_42 , F_11 ( V_28 ) ) ;
F_9 ( V_2 -> V_25 [ V_43 ] , V_44 , F_12 ( V_28 ) ) ;
F_9 ( V_2 -> V_25 [ V_45 ] , V_46 , 1 ) ;
F_5 ( V_2 , V_34 , V_2 -> V_25 [ V_34 ] ) ;
F_5 ( V_2 , V_37 , V_2 -> V_25 [ V_37 ] ) ;
F_5 ( V_2 , V_43 , V_2 -> V_25 [ V_43 ] ) ;
F_5 ( V_2 , V_45 , V_2 -> V_25 [ V_45 ] ) ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
F_1 ( V_2 , V_45 , & V_2 -> V_25 [ V_45 ] ) ;
if ( ! F_13 ( V_46 , V_2 -> V_25 [ V_45 ] ) )
break;
F_14 ( 1 ) ;
}
return 0 ;
}
static int F_15 ( struct V_22 * V_23 , T_2 * V_26 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_1 ( V_2 , V_37 , & V_2 -> V_25 [ V_37 ] ) ;
F_1 ( V_2 , V_43 , & V_2 -> V_25 [ V_43 ] ) ;
* V_26 = ( F_16 ( F_13 ( V_42 , V_2 -> V_25 [ V_37 ] ) ,
F_13 ( V_44 , V_2 -> V_25 [ V_43 ] ) ) ) * V_40 ;
* V_26 /= ( 1 << ( F_13 ( V_41 , V_2 -> V_25 [ V_37 ] ) +
F_13 ( V_38 , V_2 -> V_25 [ V_37 ] ) ) ) ;
* V_26 >>= 2 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , T_2 V_48 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
T_2 V_49 ;
T_1 V_33 ;
V_49 = V_48 >> 1 ;
if ( V_49 > 36000000 )
F_9 ( V_2 -> V_25 [ V_50 ] , V_51 , 31 ) ;
else if ( V_49 < 5000000 )
F_9 ( V_2 -> V_25 [ V_50 ] , V_51 , 0 ) ;
else
F_9 ( V_2 -> V_25 [ V_50 ] , V_51 , ( ( V_49 / 1000000 ) - 5 ) ) ;
F_9 ( V_2 -> V_25 [ V_50 ] , V_52 , 0x0 ) ;
F_9 ( V_2 -> V_25 [ V_45 ] , V_53 , 0x1 ) ;
F_5 ( V_2 , V_50 , V_2 -> V_25 [ V_50 ] ) ;
F_5 ( V_2 , V_45 , V_2 -> V_25 [ V_45 ] ) ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
F_1 ( V_2 , V_45 , & V_2 -> V_25 [ V_45 ] ) ;
if ( ! F_13 ( V_53 , V_2 -> V_25 [ V_45 ] ) )
break;
F_14 ( 1 ) ;
}
F_9 ( V_2 -> V_25 [ V_50 ] , V_52 , 0x1 ) ;
F_5 ( V_2 , V_50 , V_2 -> V_25 [ V_50 ] ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_23 , T_2 * V_48 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_1 ( V_2 , V_50 , & V_2 -> V_25 [ V_50 ] ) ;
* V_48 = ( F_13 ( V_51 , V_2 -> V_25 [ V_50 ] ) + 5 ) * 2000000 ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 , T_2 V_54 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
switch ( V_54 ) {
default:
case 1 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 0 ) ;
break;
case 2 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 1 ) ;
break;
case 4 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 2 ) ;
break;
case 8 :
case 0 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 3 ) ;
break;
}
F_5 ( V_2 , V_55 , V_2 -> V_25 [ V_55 ] ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 , T_2 * V_57 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_1 ( V_2 , V_55 , & V_2 -> V_25 [ V_55 ] ) ;
* V_57 = 2 * F_13 ( V_58 , V_2 -> V_25 [ V_55 ] ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 , T_2 V_57 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_9 ( V_2 -> V_25 [ V_55 ] , V_58 , V_57 / 2 ) ;
F_5 ( V_2 , V_55 , V_2 -> V_25 [ V_55 ] ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 , enum V_59 V_60 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_5 ;
switch ( V_60 ) {
case V_61 :
F_9 ( V_2 -> V_25 [ V_34 ] , V_62 , 0 ) ;
F_9 ( V_2 -> V_25 [ V_34 ] , V_63 , 0 ) ;
F_9 ( V_2 -> V_25 [ V_34 ] , V_64 , 0 ) ;
break;
case V_65 :
F_9 ( V_2 -> V_25 [ V_34 ] , V_62 , 1 ) ;
F_9 ( V_2 -> V_25 [ V_34 ] , V_63 , 1 ) ;
F_9 ( V_2 -> V_25 [ V_34 ] , V_64 , 1 ) ;
break;
}
V_5 = F_5 ( V_2 , V_34 , V_2 -> V_25 [ V_34 ] ) ;
if ( V_5 < 0 ) {
F_3 ( V_18 , 1 , L_1 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_23 ( struct V_22 * V_23 )
{
if ( V_23 -> V_24 )
return F_22 ( V_23 , V_61 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 , T_2 * V_67 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_1 ( V_2 , V_45 , & V_2 -> V_25 [ V_45 ] ) ;
if ( F_13 ( V_68 , V_2 -> V_25 [ V_45 ] ) )
* V_67 = V_69 ;
else
* V_67 = 0 ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
V_23 -> V_24 = NULL ;
F_26 ( V_2 ) ;
return 0 ;
}
struct V_70 * F_27 ( struct V_22 * V_23 ,
const struct V_6 * V_7 ,
struct V_71 * V_17 )
{
struct V_1 * V_2 ;
T_1 V_72 [] = { 0x07 , 0x11 , 0xdc , 0x85 , 0x17 , 0x01 , 0xe6 , 0x1e } ;
V_2 = F_28 ( sizeof ( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_17 = V_17 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_74 = & V_75 ;
memcpy ( V_2 -> V_25 , V_72 , 8 ) ;
switch ( V_2 -> V_7 -> V_76 ) {
default:
case 1 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 0 ) ;
break;
case 2 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 1 ) ;
break;
case 4 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 2 ) ;
break;
case 8 :
case 0 :
F_9 ( V_2 -> V_25 [ V_55 ] , V_56 , 3 ) ;
break;
}
V_23 -> V_24 = V_2 ;
V_23 -> V_77 . V_78 = V_79 ;
F_29 ( V_80 L_3 , V_81 ) ;
return V_2 -> V_74 ;
}
