static int F_1 ( T_1 V_1 , T_1 V_2 )
{
T_2 V_3 = ( V_1 << 8 ) | V_2 ;
return V_3 * 1000 / 256 ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 )
{
T_3 V_3 = ( V_1 << 8 ) | V_2 ;
return V_3 * 1000 / 256 ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
struct V_4 * V_7 = F_4 ( V_6 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_5 ( & V_7 -> V_10 ) ;
if ( F_6 ( V_11 , V_7 -> V_12
+ F_7 ( V_7 -> V_13 ) ) ||
! V_7 -> V_14 ) {
int V_15 ;
F_8 ( V_6 , L_1 ) ;
for ( V_15 = 0 ; V_15 < F_9 ( V_16 ) ; V_15 ++ )
V_7 -> V_17 [ V_15 ]
= F_10 ( V_9 ,
V_16 [ V_15 ] ) ;
V_7 -> V_18 = F_10 ( V_9 ,
V_19 ) ;
V_7 -> V_12 = V_11 ;
V_7 -> V_14 = 1 ;
}
F_11 ( & V_7 -> V_10 ) ;
return V_7 ;
}
static int F_12 ( struct V_5 * V_6 , T_4 V_20 , int V_21 ,
long * V_22 )
{
struct V_4 * V_7 = F_4 ( V_6 ) ;
switch ( V_20 ) {
case V_23 :
* V_22 = V_7 -> V_13 ;
return 0 ;
default:
return - V_24 ;
}
}
static int F_13 ( struct V_5 * V_6 , T_4 V_20 , int V_21 ,
long * V_22 )
{
struct V_4 * V_7 = F_3 ( V_6 ) ;
switch ( V_20 ) {
case V_25 :
if ( ! V_21 || ( V_7 -> V_26 & F_14 ( V_21 - 1 ) ) )
* V_22 = F_1 ( V_7 -> V_17 [ V_21 * 2 ] ,
V_7 -> V_17 [ V_21 * 2 + 1 ] ) ;
else
* V_22 = F_2 ( V_7 -> V_17 [ V_21 * 2 ] ,
V_7 -> V_17 [ V_21 * 2 + 1 ] ) ;
return 0 ;
case V_27 :
if ( V_21 == 1 )
* V_22 = ( V_7 -> V_26 & V_28 ) ? - 128000 : 0 ;
else
* V_22 = ( V_7 -> V_26 & V_29 ) ? - 128000 : 0 ;
return 0 ;
case V_30 :
if ( V_21 == 1 )
* V_22 = ( V_7 -> V_26 & V_28 ) ? 127875 : 255875 ;
else
* V_22 = ( V_7 -> V_26 & V_29 ) ? 127875 : 255875 ;
return 0 ;
case V_31 :
if ( V_21 == 1 )
* V_22 = ( V_7 -> V_32 & V_33 ) ? 1 : 2 ;
else
* V_22 = ( V_7 -> V_32 & V_34 ) ? 1 : 2 ;
return 0 ;
case V_35 :
if ( V_21 == 1 )
* V_22 = ! ! ( V_7 -> V_18 & V_36 ) ;
else
* V_22 = ! ! ( V_7 -> V_18 & V_37 ) ;
return 0 ;
default:
return - V_24 ;
}
}
static int F_15 ( struct V_5 * V_6 , enum V_38 type ,
T_4 V_20 , int V_21 , long * V_22 )
{
switch ( type ) {
case V_39 :
return F_12 ( V_6 , V_20 , V_21 , V_22 ) ;
case V_40 :
return F_13 ( V_6 , V_20 , V_21 , V_22 ) ;
default:
return - V_24 ;
}
}
static int F_16 ( struct V_5 * V_6 , T_4 V_20 , int V_21 ,
long V_22 )
{
struct V_4 * V_7 = F_4 ( V_6 ) ;
int V_41 ;
T_1 V_26 ;
int V_42 ;
F_5 ( & V_7 -> V_10 ) ;
switch ( V_20 ) {
case V_23 :
V_26 = V_7 -> V_26 & ~ V_43 ;
if ( V_22 < 130 ) {
V_41 = 76 ;
V_26 |= V_44 ;
} else if ( V_22 < 590 ) {
V_41 = 182 ;
V_26 |= V_45 ;
} else if ( V_22 < 1850 ) {
V_41 = 1000 ;
V_26 |= V_46 ;
} else {
V_41 = 2700 ;
V_26 |= V_47 ;
}
V_7 -> V_13 = V_41 ;
V_7 -> V_26 = V_26 ;
V_42 = F_17 ( V_7 -> V_9 ,
V_48 , V_26 ) ;
break;
default:
V_42 = - V_24 ;
break;
}
F_11 ( & V_7 -> V_10 ) ;
return V_42 ;
}
static int F_18 ( struct V_5 * V_6 , T_4 V_20 , int V_21 ,
long V_22 )
{
struct V_4 * V_7 = F_4 ( V_6 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_42 ;
F_5 ( & V_7 -> V_10 ) ;
switch ( V_20 ) {
case V_27 :
if ( V_21 == 1 ) {
if ( V_22 < 0 )
V_7 -> V_26 |= V_28 ;
else
V_7 -> V_26 &= ~ V_28 ;
} else {
if ( V_22 < 0 )
V_7 -> V_26 |= V_29 ;
else
V_7 -> V_26 &= ~ V_29 ;
}
V_7 -> V_14 = 0 ;
V_42 = F_17 ( V_9 , V_48 ,
V_7 -> V_26 ) ;
break;
case V_30 :
if ( V_21 == 1 ) {
if ( V_22 <= 127875 )
V_7 -> V_26 |= V_28 ;
else
V_7 -> V_26 &= ~ V_28 ;
} else {
if ( V_22 <= 127875 )
V_7 -> V_26 |= V_29 ;
else
V_7 -> V_26 &= ~ V_29 ;
}
V_7 -> V_14 = 0 ;
V_42 = F_17 ( V_9 , V_48 ,
V_7 -> V_26 ) ;
break;
case V_31 :
if ( V_22 != 1 && V_22 != 2 ) {
V_42 = - V_49 ;
break;
}
if ( V_21 == 1 ) {
V_7 -> V_50 &= ~ ( V_51 << V_52 ) ;
if ( V_22 == 1 ) {
V_7 -> V_32 |= V_33 ;
V_7 -> V_50 |= ( V_53 << V_52 ) ;
} else {
V_7 -> V_32 &= ~ V_33 ;
V_7 -> V_50 |= ( V_54 << V_52 ) ;
}
} else {
V_7 -> V_50 &= ~ ( V_51 << V_55 ) ;
if ( V_22 == 1 ) {
V_7 -> V_32 |= V_34 ;
V_7 -> V_50 |= ( V_53 << V_55 ) ;
} else {
V_7 -> V_32 &= ~ V_34 ;
V_7 -> V_50 |= ( V_54 << V_55 ) ;
}
}
V_42 = F_17 ( V_9 ,
V_56 ,
V_7 -> V_32 ) ;
if ( V_42 < 0 )
break;
V_42 = F_17 ( V_9 , V_57 ,
V_7 -> V_50 ) ;
break;
default:
V_42 = - V_24 ;
break;
}
F_11 ( & V_7 -> V_10 ) ;
return V_42 ;
}
static int F_19 ( struct V_5 * V_6 , enum V_38 type ,
T_4 V_20 , int V_21 , long V_22 )
{
switch ( type ) {
case V_39 :
return F_16 ( V_6 , V_20 , V_21 , V_22 ) ;
case V_40 :
return F_18 ( V_6 , V_20 , V_21 , V_22 ) ;
default:
return - V_24 ;
}
}
static T_5 F_20 ( const void * V_7 ,
enum V_38 type ,
T_4 V_20 , int V_21 )
{
switch ( type ) {
case V_39 :
switch ( V_20 ) {
case V_23 :
return V_58 | V_59 ;
}
break;
case V_40 :
switch ( V_20 ) {
case V_25 :
return V_58 ;
case V_35 :
return V_58 ;
case V_27 :
case V_30 :
case V_31 :
return V_58 | V_59 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_8 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_60 -> V_64 ;
const char * V_65 ;
int V_66 , V_67 ;
if ( ! F_22 ( V_64 , V_68 ) )
return - V_69 ;
V_66 = F_10 ( V_60 , V_70 ) ;
if ( V_66 != V_71 )
return - V_69 ;
V_67 = F_10 ( V_60 , V_72 ) ;
switch ( V_67 ) {
case V_73 :
V_65 = L_2 ;
break;
case V_74 :
V_65 = L_3 ;
break;
default:
return - V_69 ;
}
F_23 ( V_62 -> type , V_65 , V_75 ) ;
return 0 ;
}
static void F_24 ( struct V_8 * V_9 ,
struct V_4 * V_7 )
{
V_7 -> V_13 = 1000 ;
V_7 -> V_26 = V_46 ;
V_7 -> V_50 = ( V_54 << V_52 ) | ( V_54 << V_55 ) ;
F_17 ( V_9 , V_48 , V_7 -> V_26 ) ;
F_17 ( V_9 , V_76 ,
V_77 | V_78 ) ;
F_17 ( V_9 , V_57 ,
V_7 -> V_50 ) ;
F_17 ( V_9 , V_56 ,
V_7 -> V_32 ) ;
}
static int F_25 ( struct V_8 * V_9 ,
const struct V_79 * V_80 )
{
struct V_5 * V_6 = & V_9 -> V_6 ;
struct V_4 * V_7 ;
struct V_5 * V_81 ;
V_7 = F_26 ( V_6 , sizeof( struct V_4 ) , V_82 ) ;
if ( ! V_7 )
return - V_83 ;
V_7 -> V_9 = V_9 ;
F_27 ( & V_7 -> V_10 ) ;
F_24 ( V_9 , V_7 ) ;
V_81 = F_28 ( V_6 , V_9 -> V_65 ,
V_7 ,
& V_84 ,
NULL ) ;
return F_29 ( V_81 ) ;
}
