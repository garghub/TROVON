static T_1 F_1 ( long V_1 , bool V_2 )
{
int V_3 = F_2 ( V_1 ,
V_2 ? V_4 :
V_5 , V_6 ) ;
return ( V_3 * 2 / 125 ) & 0x1fff ;
}
static int F_3 ( T_2 V_7 )
{
V_7 = F_4 ( V_7 , 12 ) ;
return V_7 * 125 / 2 ;
}
static struct V_8 * F_5 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_8 * V_14 = V_11 ;
int V_15 , V_16 ;
F_7 ( & V_11 -> V_17 ) ;
if ( F_8 ( V_18 , V_11 -> V_19 + V_20 ) || ! V_11 -> V_21 ) {
for ( V_15 = 0 ; V_15 < V_22 ; V_15 ++ ) {
V_16 = F_9 ( V_13 , V_23 [ V_15 ] ) ;
if ( V_16 < 0 ) {
V_14 = F_10 ( V_16 ) ;
goto abort;
}
V_11 -> V_1 [ V_15 ] = V_16 ;
}
V_11 -> V_19 = V_18 ;
V_11 -> V_21 = true ;
}
abort:
F_11 ( & V_11 -> V_17 ) ;
return V_14 ;
}
static int F_12 ( struct V_9 * V_10 , enum V_24 type ,
T_3 V_25 , int V_26 , long * V_16 )
{
struct V_8 * V_11 = F_5 ( V_10 ) ;
int V_1 , V_27 ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
switch ( V_25 ) {
case V_28 :
* V_16 = F_3 ( V_11 -> V_1 [ V_29 ] ) ;
return 0 ;
case V_30 :
* V_16 = F_3 ( V_11 -> V_1 [ V_31 ] ) ;
return 0 ;
case V_32 :
* V_16 = F_3 ( V_11 -> V_1 [ V_33 ] ) ;
return 0 ;
case V_34 :
* V_16 = F_3 ( V_11 -> V_1 [ V_35 ] ) ;
return 0 ;
case V_36 :
V_1 = F_3 ( V_11 -> V_1 [ V_33 ] ) ;
V_27 = V_37 [ ( V_11 -> V_38 & V_39 )
>> V_40 ] ;
* V_16 = V_1 - V_27 ;
return 0 ;
case V_41 :
V_1 = F_3 ( V_11 -> V_1 [ V_35 ] ) ;
V_27 = V_37 [ ( V_11 -> V_38 & V_39 )
>> V_40 ] ;
* V_16 = V_1 - V_27 ;
return 0 ;
case V_42 :
* V_16 = ( V_11 -> V_1 [ V_29 ] >> V_43 ) & 1 ;
return 0 ;
case V_44 :
* V_16 = ( V_11 -> V_1 [ V_29 ] >> V_45 ) & 1 ;
return 0 ;
case V_46 :
* V_16 = ( V_11 -> V_1 [ V_29 ] >> V_47 ) & 1 ;
return 0 ;
default:
return - V_48 ;
}
}
static int F_15 ( struct V_9 * V_10 , enum V_24 type ,
T_3 V_25 , int V_26 , long V_16 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
int V_49 , V_27 ;
int V_14 ;
F_7 ( & V_11 -> V_17 ) ;
switch ( V_25 ) {
case V_30 :
V_11 -> V_1 [ V_31 ] = F_1 ( V_16 , V_11 -> V_2 ) ;
V_14 = F_16 ( V_13 , V_23 [ V_31 ] ,
V_11 -> V_1 [ V_31 ] ) ;
break;
case V_32 :
V_11 -> V_1 [ V_33 ] = F_1 ( V_16 , V_11 -> V_2 ) ;
V_14 = F_16 ( V_13 , V_23 [ V_33 ] ,
V_11 -> V_1 [ V_33 ] ) ;
break;
case V_34 :
V_11 -> V_1 [ V_35 ] = F_1 ( V_16 , V_11 -> V_2 ) ;
V_14 = F_16 ( V_13 , V_23 [ V_35 ] ,
V_11 -> V_1 [ V_35 ] ) ;
break;
case V_41 :
V_16 = F_2 ( V_16 , ( V_11 -> V_2 ? V_4
: V_5 ) - 6000 ,
V_6 ) ;
V_49 = F_3 ( V_11 -> V_1 [ V_35 ] ) - V_16 ;
V_27 = 0 ;
if ( V_49 > 0 ) {
if ( V_49 < 2250 )
V_27 = 1 ;
else if ( V_49 < 4500 )
V_27 = 2 ;
else
V_27 = 3 ;
}
V_11 -> V_38 = ( V_11 -> V_38 & ~ V_39 ) |
( V_27 << V_40 ) ;
V_14 = F_16 ( V_11 -> V_13 ,
V_50 ,
V_11 -> V_38 ) ;
break;
default:
V_14 = - V_48 ;
break;
}
F_11 ( & V_11 -> V_17 ) ;
return V_14 ;
}
static T_4 F_17 ( const void * V_51 , enum V_24 type ,
T_3 V_25 , int V_26 )
{
const struct V_8 * V_11 = V_51 ;
unsigned int V_38 = V_11 -> V_38 ;
T_4 V_52 = V_53 ;
switch ( V_25 ) {
case V_30 :
case V_32 :
if ( ! ( V_38 & V_54 ) )
V_52 |= V_55 ;
break;
case V_34 :
if ( ! ( V_38 & V_56 ) )
V_52 |= V_55 ;
break;
case V_41 :
if ( ! ( V_38 & ( V_54 | V_56 ) ) )
V_52 |= V_55 ;
break;
case V_28 :
case V_36 :
case V_42 :
case V_44 :
case V_46 :
break;
default:
V_52 = 0 ;
break;
}
return V_52 ;
}
static int F_18 ( struct V_12 * V_13 , struct V_57 * V_58 )
{
struct V_59 * V_60 = V_13 -> V_60 ;
int V_15 , V_38 , V_61 , V_62 , V_63 ;
if ( ! F_19 ( V_60 , V_64 |
V_65 ) )
return - V_66 ;
V_61 = F_9 ( V_13 , V_67 ) ;
V_38 = F_9 ( V_13 , V_50 ) ;
V_62 = F_9 ( V_13 , V_68 ) ;
V_63 = F_9 ( V_13 , V_69 ) ;
if ( V_61 < 0 || V_38 < 0 || V_62 < 0 || V_63 < 0 )
return - V_66 ;
if ( ( V_61 & 0xff00 ) || ( V_38 & 0xf800 ) )
return - V_66 ;
for ( V_15 = 0 ; V_15 < F_20 ( V_70 ) ; V_15 ++ ) {
struct V_70 * V_71 = & V_70 [ V_15 ] ;
if ( V_62 == V_71 -> V_62 &&
( V_63 & V_71 -> V_72 ) == V_71 -> V_63 ) {
F_21 ( V_58 -> type , L_1 , V_73 ) ;
return 0 ;
}
}
return - V_66 ;
}
static int F_22 ( struct V_12 * V_13 , const struct V_74 * V_75 )
{
struct V_9 * V_10 = & V_13 -> V_10 ;
struct V_9 * V_76 ;
struct V_8 * V_11 ;
int V_38 , V_61 ;
V_11 = F_23 ( V_10 , sizeof( struct V_8 ) , V_77 ) ;
if ( ! V_11 )
return - V_78 ;
V_11 -> V_13 = V_13 ;
F_24 ( V_13 , V_11 ) ;
F_25 ( & V_11 -> V_17 ) ;
V_61 = F_9 ( V_13 , V_67 ) ;
if ( V_61 < 0 )
return V_61 ;
V_11 -> V_2 = ! ! ( V_61 & V_79 ) ;
V_38 = F_9 ( V_13 , V_50 ) ;
if ( V_38 < 0 )
return V_38 ;
V_11 -> V_80 = V_38 ;
if ( V_38 & V_81 ) {
V_38 &= ~ V_81 ;
F_16 ( V_13 , V_50 , V_38 ) ;
}
V_11 -> V_38 = V_38 ;
V_76 = F_26 ( V_10 , V_13 -> V_82 ,
V_11 , & V_83 ,
NULL ) ;
return F_27 ( V_76 ) ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_8 * V_11 = F_29 ( V_13 ) ;
if ( ( V_11 -> V_38 & ~ V_39 ) !=
( V_11 -> V_80 & ~ V_39 ) ) {
int V_38 ;
V_38 = ( V_11 -> V_80 & ~ V_39 )
| ( V_11 -> V_38 & V_39 ) ;
F_16 ( V_13 , V_50 , V_38 ) ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
V_11 -> V_38 |= V_81 ;
F_16 ( V_11 -> V_13 , V_50 ,
V_11 -> V_38 ) ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_6 ( V_10 ) ;
V_11 -> V_38 &= ~ V_81 ;
F_16 ( V_11 -> V_13 , V_50 ,
V_11 -> V_38 ) ;
return 0 ;
}
