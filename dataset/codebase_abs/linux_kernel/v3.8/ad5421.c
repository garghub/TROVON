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
struct V_13 V_14 ;
int V_11 ;
struct V_15 V_16 [] = {
{
. V_17 = & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] ,
. V_18 = 3 ,
. V_19 = 1 ,
} , {
. V_20 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_18 = 3 ,
} ,
} ;
F_9 ( & V_14 ) ;
F_10 ( & V_16 [ 0 ] , & V_14 ) ;
F_10 ( & V_16 [ 1 ] , & V_14 ) ;
F_6 ( & V_2 -> V_12 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( ( 1 << 23 ) | ( V_3 << 16 ) ) ;
V_11 = F_11 ( V_6 -> V_9 , & V_14 ) ;
if ( V_11 >= 0 )
V_11 = F_12 ( V_6 -> V_7 [ 1 ] . V_8 ) & 0xffff ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_21 ,
unsigned int V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_11 ;
F_6 ( & V_2 -> V_12 ) ;
V_6 -> V_23 &= ~ V_22 ;
V_6 -> V_23 |= V_21 ;
V_11 = F_1 ( V_2 , V_24 , V_6 -> V_23 ) ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static T_1 F_14 ( int V_25 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_26 ;
unsigned int V_27 = 0 ;
unsigned int V_28 ;
V_26 = F_8 ( V_2 , V_29 ) ;
if ( ! V_26 )
return V_30 ;
F_13 ( V_2 , 0 , 0 ) ;
do {
if ( V_26 == 0xffff )
V_26 = 0 ;
V_28 = ( V_27 ^ V_26 ) & V_26 ;
V_28 &= V_6 -> V_31 ;
if ( V_28 & V_32 ) {
F_15 ( V_2 ,
F_16 ( V_33 ,
0 ,
V_34 ,
V_35 ) ,
F_17 () ) ;
}
if ( V_28 & V_36 ) {
F_15 ( V_2 ,
F_16 ( V_33 ,
0 ,
V_34 ,
V_37 ) ,
F_17 () ) ;
}
if ( V_28 & V_38 ) {
F_15 ( V_2 ,
F_16 ( V_39 ,
0 ,
V_40 ,
V_35 ) ,
F_17 () ) ;
}
V_27 = V_26 ;
V_26 = F_8 ( V_2 , V_29 ) ;
if ( V_26 & V_41 )
F_18 ( 1000 ) ;
} while ( V_26 & V_41 );
return V_42 ;
}
static void F_19 ( struct V_5 * V_6 ,
unsigned int * V_43 , unsigned int * V_44 )
{
switch ( V_6 -> V_45 ) {
case V_46 :
* V_43 = 4000 ;
* V_44 = 20000 ;
break;
case V_47 :
* V_43 = 3800 ;
* V_44 = 21000 ;
break;
case V_48 :
* V_43 = 3200 ;
* V_44 = 24000 ;
break;
default:
* V_43 = 0 ;
* V_44 = 1 ;
break;
}
}
static inline unsigned int F_20 ( struct V_5 * V_6 )
{
unsigned int V_43 , V_44 ;
F_19 ( V_6 , & V_43 , & V_44 ) ;
return ( V_43 * ( 1 << 16 ) ) / ( V_44 - V_43 ) ;
}
static inline unsigned int F_21 ( struct V_5 * V_6 )
{
unsigned int V_43 , V_44 ;
F_19 ( V_6 , & V_43 , & V_44 ) ;
return ( ( V_44 - V_43 ) * 1000 ) / ( 1 << 16 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_49 const * V_50 , int * V_4 , int * V_51 , long V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
if ( V_50 -> type != V_33 )
return - V_52 ;
switch ( V_14 ) {
case V_53 :
V_11 = F_8 ( V_2 , V_54 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
return V_55 ;
case V_56 :
* V_4 = 0 ;
* V_51 = F_21 ( V_6 ) ;
return V_57 ;
case V_58 :
* V_4 = F_20 ( V_6 ) ;
return V_55 ;
case V_59 :
V_11 = F_8 ( V_2 , V_60 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 - 32768 ;
return V_55 ;
case V_61 :
V_11 = F_8 ( V_2 , V_62 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
return V_55 ;
}
return - V_52 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_49 const * V_50 , int V_4 , int V_51 , long V_63 )
{
const unsigned int V_64 = 1 << 16 ;
switch ( V_63 ) {
case V_53 :
if ( V_4 >= V_64 || V_4 < 0 )
return - V_52 ;
return F_5 ( V_2 , V_54 , V_4 ) ;
case V_59 :
V_4 += 32768 ;
if ( V_4 >= V_64 || V_4 < 0 )
return - V_52 ;
return F_5 ( V_2 , V_60 , V_4 ) ;
case V_61 :
if ( V_4 >= V_64 || V_4 < 0 )
return - V_52 ;
return F_5 ( V_2 , V_62 , V_4 ) ;
default:
break;
}
return - V_52 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_2 V_65 , int V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_63 ;
switch ( F_25 ( V_65 ) ) {
case V_33 :
if ( F_26 ( V_65 ) ==
V_35 )
V_63 = V_32 ;
else
V_63 = V_36 ;
break;
case V_39 :
V_63 = V_38 ;
break;
default:
return - V_52 ;
}
F_6 ( & V_2 -> V_12 ) ;
if ( V_66 )
V_6 -> V_31 |= V_63 ;
else
V_6 -> V_31 &= ~ V_63 ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_2 V_65 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_63 ;
switch ( F_25 ( V_65 ) ) {
case V_33 :
if ( F_26 ( V_65 ) ==
V_35 )
V_63 = V_32 ;
else
V_63 = V_36 ;
break;
case V_39 :
V_63 = V_38 ;
break;
default:
return - V_52 ;
}
return ( bool ) ( V_6 -> V_31 & V_63 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_2 V_65 ,
int * V_4 )
{
int V_11 ;
switch ( F_25 ( V_65 ) ) {
case V_33 :
V_11 = F_8 ( V_2 , V_54 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_4 = V_11 ;
break;
case V_39 :
* V_4 = 140000 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_29 ( struct V_67 * V_9 )
{
struct V_68 * V_69 = F_30 ( & V_9 -> V_70 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_11 ;
V_2 = F_31 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_32 ( & V_9 -> V_70 , L_1 ) ;
return - V_71 ;
}
V_6 = F_2 ( V_2 ) ;
F_33 ( V_9 , V_2 ) ;
V_6 -> V_9 = V_9 ;
V_2 -> V_70 . V_72 = & V_9 -> V_70 ;
V_2 -> V_73 = L_2 ;
V_2 -> V_74 = & V_75 ;
V_2 -> V_76 = V_77 ;
V_2 -> V_78 = V_79 ;
V_2 -> V_80 = F_34 ( V_79 ) ;
V_6 -> V_23 = V_81 |
V_82 ;
if ( V_69 ) {
V_6 -> V_45 = V_69 -> V_45 ;
if ( V_69 -> V_83 )
V_6 -> V_23 |= V_84 ;
} else {
V_6 -> V_45 = V_46 ;
}
F_13 ( V_2 , 0 , 0 ) ;
if ( V_9 -> V_25 ) {
V_11 = F_35 ( V_9 -> V_25 ,
NULL ,
F_14 ,
V_85 | V_86 ,
L_3 ,
V_2 ) ;
if ( V_11 )
goto V_87;
}
V_11 = F_36 ( V_2 ) ;
if ( V_11 ) {
F_32 ( & V_9 -> V_70 , L_4 , V_11 ) ;
goto V_88;
}
return 0 ;
V_88:
if ( V_9 -> V_25 )
F_37 ( V_9 -> V_25 , V_2 ) ;
V_87:
F_38 ( V_2 ) ;
return V_11 ;
}
static int F_39 ( struct V_67 * V_9 )
{
struct V_1 * V_2 = F_40 ( V_9 ) ;
F_41 ( V_2 ) ;
if ( V_9 -> V_25 )
F_37 ( V_9 -> V_25 , V_2 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
