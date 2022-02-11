static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( ( V_3 << 16 ) | V_4 ) ;
return F_4 ( V_6 -> V_9 , & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
int V_11 ;
F_6 ( & V_2 -> V_12 ) ;
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] ,
. V_16 = 3 ,
. V_17 = 1 ,
} , {
. V_18 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_16 = 3 ,
} ,
} ;
F_6 ( & V_2 -> V_12 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( ( 1 << 23 ) | ( V_3 << 16 ) ) ;
V_11 = F_9 ( V_6 -> V_9 , V_14 , F_10 ( V_14 ) ) ;
if ( V_11 >= 0 )
V_11 = F_11 ( V_6 -> V_7 [ 1 ] . V_8 ) & 0xffff ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_19 ,
unsigned int V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_11 ;
F_6 ( & V_2 -> V_12 ) ;
V_6 -> V_21 &= ~ V_20 ;
V_6 -> V_21 |= V_19 ;
V_11 = F_1 ( V_2 , V_22 , V_6 -> V_21 ) ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static T_1 F_13 ( int V_23 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_24 ;
unsigned int V_25 = 0 ;
unsigned int V_26 ;
V_24 = F_8 ( V_2 , V_27 ) ;
if ( ! V_24 )
return V_28 ;
F_12 ( V_2 , 0 , 0 ) ;
do {
if ( V_24 == 0xffff )
V_24 = 0 ;
V_26 = ( V_25 ^ V_24 ) & V_24 ;
V_26 &= V_6 -> V_29 ;
if ( V_26 & V_30 ) {
F_14 ( V_2 ,
F_15 ( V_31 ,
0 ,
V_32 ,
V_33 ) ,
F_16 () ) ;
}
if ( V_26 & V_34 ) {
F_14 ( V_2 ,
F_15 ( V_31 ,
0 ,
V_32 ,
V_35 ) ,
F_16 () ) ;
}
if ( V_26 & V_36 ) {
F_14 ( V_2 ,
F_15 ( V_37 ,
0 ,
V_38 ,
V_33 ) ,
F_16 () ) ;
}
V_25 = V_24 ;
V_24 = F_8 ( V_2 , V_27 ) ;
if ( V_24 & V_39 )
F_17 ( 1000 ) ;
} while ( V_24 & V_39 );
return V_40 ;
}
static void F_18 ( struct V_5 * V_6 ,
unsigned int * V_41 , unsigned int * V_42 )
{
switch ( V_6 -> V_43 ) {
case V_44 :
* V_41 = 4000 ;
* V_42 = 20000 ;
break;
case V_45 :
* V_41 = 3800 ;
* V_42 = 21000 ;
break;
case V_46 :
* V_41 = 3200 ;
* V_42 = 24000 ;
break;
default:
* V_41 = 0 ;
* V_42 = 1 ;
break;
}
}
static inline unsigned int F_19 ( struct V_5 * V_6 )
{
unsigned int V_41 , V_42 ;
F_18 ( V_6 , & V_41 , & V_42 ) ;
return ( V_41 * ( 1 << 16 ) ) / ( V_42 - V_41 ) ;
}
static inline unsigned int F_20 ( struct V_5 * V_6 )
{
unsigned int V_41 , V_42 ;
F_18 ( V_6 , & V_41 , & V_42 ) ;
return ( ( V_42 - V_41 ) * 1000 ) / ( 1 << 16 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_47 const * V_48 , int * V_4 , int * V_49 , long V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_48 -> type != V_31 )
return - V_51 ;
switch ( V_50 ) {
case V_52 :
V_11 = F_8 ( V_2 , V_53 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
return V_54 ;
case V_55 :
* V_4 = 0 ;
* V_49 = F_20 ( V_6 ) ;
return V_56 ;
case V_57 :
* V_4 = F_19 ( V_6 ) ;
return V_54 ;
case V_58 :
V_11 = F_8 ( V_2 , V_59 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 - 32768 ;
return V_54 ;
case V_60 :
V_11 = F_8 ( V_2 , V_61 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
return V_54 ;
}
return - V_51 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_47 const * V_48 , int V_4 , int V_49 , long V_62 )
{
const unsigned int V_63 = 1 << 16 ;
switch ( V_62 ) {
case V_52 :
if ( V_4 >= V_63 || V_4 < 0 )
return - V_51 ;
return F_5 ( V_2 , V_53 , V_4 ) ;
case V_58 :
V_4 += 32768 ;
if ( V_4 >= V_63 || V_4 < 0 )
return - V_51 ;
return F_5 ( V_2 , V_59 , V_4 ) ;
case V_60 :
if ( V_4 >= V_63 || V_4 < 0 )
return - V_51 ;
return F_5 ( V_2 , V_61 , V_4 ) ;
default:
break;
}
return - V_51 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_2 V_64 , int V_65 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_62 ;
switch ( F_24 ( V_64 ) ) {
case V_31 :
if ( F_25 ( V_64 ) ==
V_33 )
V_62 = V_30 ;
else
V_62 = V_34 ;
break;
case V_37 :
V_62 = V_36 ;
break;
default:
return - V_51 ;
}
F_6 ( & V_2 -> V_12 ) ;
if ( V_65 )
V_6 -> V_29 |= V_62 ;
else
V_6 -> V_29 &= ~ V_62 ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
T_2 V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_62 ;
switch ( F_24 ( V_64 ) ) {
case V_31 :
if ( F_25 ( V_64 ) ==
V_33 )
V_62 = V_30 ;
else
V_62 = V_34 ;
break;
case V_37 :
V_62 = V_36 ;
break;
default:
return - V_51 ;
}
return ( bool ) ( V_6 -> V_29 & V_62 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_64 ,
int * V_4 )
{
int V_11 ;
switch ( F_24 ( V_64 ) ) {
case V_31 :
V_11 = F_8 ( V_2 , V_53 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
break;
case V_37 :
* V_4 = 140000 ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_28 ( struct V_66 * V_9 )
{
struct V_67 * V_68 = F_29 ( & V_9 -> V_69 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_11 ;
V_2 = F_30 ( & V_9 -> V_69 , sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_31 ( & V_9 -> V_69 , L_1 ) ;
return - V_70 ;
}
V_6 = F_2 ( V_2 ) ;
F_32 ( V_9 , V_2 ) ;
V_6 -> V_9 = V_9 ;
V_2 -> V_69 . V_71 = & V_9 -> V_69 ;
V_2 -> V_72 = L_2 ;
V_2 -> V_73 = & V_74 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = V_78 ;
V_2 -> V_79 = F_10 ( V_78 ) ;
V_6 -> V_21 = V_80 |
V_81 ;
if ( V_68 ) {
V_6 -> V_43 = V_68 -> V_43 ;
if ( V_68 -> V_82 )
V_6 -> V_21 |= V_83 ;
} else {
V_6 -> V_43 = V_44 ;
}
F_12 ( V_2 , 0 , 0 ) ;
if ( V_9 -> V_23 ) {
V_11 = F_33 ( & V_9 -> V_69 , V_9 -> V_23 ,
NULL ,
F_13 ,
V_84 | V_85 ,
L_3 ,
V_2 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_34 ( V_2 ) ;
if ( V_11 ) {
F_31 ( & V_9 -> V_69 , L_4 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_35 ( struct V_66 * V_9 )
{
struct V_1 * V_2 = F_36 ( V_9 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
