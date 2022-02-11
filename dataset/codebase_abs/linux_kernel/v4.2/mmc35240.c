static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ )
if ( V_6 [ V_5 ] . V_3 == V_3 &&
V_6 [ V_5 ] . V_4 == V_4 )
return V_5 ;
return - V_7 ;
}
static int F_3 ( struct V_1 * V_2 , bool V_8 )
{
int V_9 ;
T_1 V_10 ;
V_9 = F_4 ( V_2 -> V_11 , V_12 ,
V_13 ,
V_13 ) ;
if ( V_9 < 0 )
return V_9 ;
F_5 ( V_14 , V_14 + 1 ) ;
if ( V_8 )
V_10 = V_15 ;
else
V_10 = V_16 ;
return F_4 ( V_2 -> V_11 , V_12 ,
V_10 , V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 , V_17 , V_18 ;
unsigned int V_19 ;
T_1 V_20 [ 6 ] ;
V_9 = F_7 ( V_2 -> V_11 , V_21 , & V_19 ) ;
if ( V_9 < 0 ) {
F_8 ( & V_2 -> V_22 -> V_23 , L_1 ) ;
return V_9 ;
}
F_9 ( & V_2 -> V_22 -> V_23 , L_2 , V_19 ) ;
V_9 = F_3 ( V_2 , true ) ;
if ( V_9 < 0 )
return V_9 ;
F_5 ( V_24 , V_24 + 1 ) ;
V_9 = F_3 ( V_2 , false ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_4 ( V_2 -> V_11 , V_25 ,
V_26 ,
V_2 -> V_27 << V_28 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_10 ( V_2 -> V_11 , V_29 ,
( T_1 * ) V_20 , sizeof( V_20 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_17 = F_11 ( ( ( V_20 [ 1 ] & 0x03 ) << 4 ) |
( V_20 [ 2 ] >> 4 ) ) ;
V_18 = F_12 ( V_20 [ 3 ] & 0x3f ) ;
V_2 -> V_30 [ 0 ] = F_13 ( 1 ) ;
V_2 -> V_30 [ 1 ] = F_14 ( V_17 ) ;
V_2 -> V_30 [ 2 ] = F_15 ( V_18 ) ;
V_2 -> V_31 [ 0 ] = 1 ;
V_2 -> V_31 [ 1 ] = 1000 ;
V_2 -> V_31 [ 2 ] = 10000 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_9 , V_32 = 100 ;
unsigned int V_33 ;
V_9 = F_17 ( V_2 -> V_11 , V_12 ,
V_34 ) ;
if ( V_9 < 0 )
return V_9 ;
while ( V_32 -- > 0 ) {
V_9 = F_7 ( V_2 -> V_11 , V_35 ,
& V_33 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_33 & V_36 )
break;
F_5 ( 10000 , 11000 ) ;
}
if ( V_32 < 0 ) {
F_8 ( & V_2 -> V_22 -> V_23 , L_3 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_38 [ 3 ] )
{
int V_9 ;
V_9 = F_16 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_10 ( V_2 -> V_11 , V_39 , ( T_1 * ) V_38 ,
3 * sizeof( T_2 ) ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_40 ,
T_2 V_38 [] , int * V_3 )
{
int V_41 , V_42 , V_43 ;
int V_44 , V_45 , V_46 ;
int V_47 ;
V_41 = F_20 ( V_38 [ V_48 ] ) ;
V_42 = F_20 ( V_38 [ V_49 ] ) ;
V_43 = F_20 ( V_38 [ V_50 ] ) ;
V_44 = V_51 [ V_2 -> V_27 ] . V_52 [ V_48 ] ;
V_45 = V_51 [ V_2 -> V_27 ] . V_52 [ V_49 ] ;
V_46 = V_51 [ V_2 -> V_27 ] . V_52 [ V_50 ] ;
V_47 = V_51 [ V_2 -> V_27 ] . V_47 ;
switch ( V_40 ) {
case V_48 :
* V_3 = ( V_41 - V_47 ) * 1000 / V_44 ;
break;
case V_49 :
* V_3 = ( V_42 - V_47 ) * 1000 / V_45 -
( V_43 - V_47 ) * 1000 / V_46 ;
break;
case V_50 :
* V_3 = ( V_42 - V_47 ) * 1000 / V_45 +
( V_43 - V_47 ) * 1000 / V_46 ;
break;
default:
return - V_7 ;
}
* V_3 = ( * V_3 ) * V_2 -> V_30 [ V_40 ] / V_2 -> V_31 [ V_40 ] ;
return 0 ;
}
static int F_21 ( struct V_53 * V_54 ,
struct V_55 const * V_56 , int * V_3 ,
int * V_4 , long V_57 )
{
struct V_1 * V_2 = F_22 ( V_54 ) ;
int V_9 , V_5 ;
unsigned int V_58 ;
T_2 V_38 [ 3 ] ;
switch ( V_57 ) {
case V_59 :
F_23 ( & V_2 -> V_60 ) ;
V_9 = F_18 ( V_2 , V_38 ) ;
F_24 ( & V_2 -> V_60 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_19 ( V_2 , V_56 -> V_61 , V_38 , V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_62 ;
case V_63 :
* V_3 = 0 ;
* V_4 = 1000 ;
return V_64 ;
case V_65 :
F_23 ( & V_2 -> V_60 ) ;
V_9 = F_7 ( V_2 -> V_11 , V_25 , & V_58 ) ;
F_24 ( & V_2 -> V_60 ) ;
if ( V_9 < 0 )
return V_9 ;
V_5 = ( V_58 & V_26 ) >> V_28 ;
if ( V_5 < 0 || V_5 >= F_2 ( V_6 ) )
return - V_7 ;
* V_3 = V_6 [ V_5 ] . V_3 ;
* V_4 = V_6 [ V_5 ] . V_4 ;
return V_64 ;
default:
return - V_7 ;
}
}
static int F_25 ( struct V_53 * V_54 ,
struct V_55 const * V_56 , int V_3 ,
int V_4 , long V_57 )
{
struct V_1 * V_2 = F_22 ( V_54 ) ;
int V_5 , V_9 ;
switch ( V_57 ) {
case V_65 :
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return - V_7 ;
F_23 ( & V_2 -> V_60 ) ;
V_9 = F_4 ( V_2 -> V_11 , V_25 ,
V_26 ,
V_5 << V_28 ) ;
F_24 ( & V_2 -> V_60 ) ;
return V_9 ;
default:
return - V_7 ;
}
}
static bool F_26 ( struct V_66 * V_23 , unsigned int V_58 )
{
switch ( V_58 ) {
case V_12 :
case V_25 :
return true ;
default:
return false ;
}
}
static bool F_27 ( struct V_66 * V_23 , unsigned int V_58 )
{
switch ( V_58 ) {
case V_39 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_35 :
case V_21 :
return true ;
default:
return false ;
}
}
static bool F_28 ( struct V_66 * V_23 , unsigned int V_58 )
{
switch ( V_58 ) {
case V_12 :
case V_25 :
return false ;
default:
return true ;
}
}
static int F_29 ( struct V_72 * V_22 ,
const struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_11 * V_11 ;
int V_9 ;
V_54 = F_30 ( & V_22 -> V_23 , sizeof( * V_2 ) ) ;
if ( ! V_54 )
return - V_75 ;
V_11 = F_31 ( V_22 , & V_76 ) ;
if ( F_32 ( V_11 ) ) {
F_8 ( & V_22 -> V_23 , L_4 ) ;
return F_33 ( V_11 ) ;
}
V_2 = F_22 ( V_54 ) ;
F_34 ( V_22 , V_54 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_27 = V_77 ;
F_35 ( & V_2 -> V_60 ) ;
V_54 -> V_23 . V_78 = & V_22 -> V_23 ;
V_54 -> V_79 = & V_80 ;
V_54 -> V_81 = V_82 ;
V_54 -> V_83 = V_84 ;
V_54 -> V_85 = F_2 ( V_84 ) ;
V_54 -> V_86 = V_87 ;
V_9 = F_6 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( & V_22 -> V_23 , L_5 ) ;
return V_9 ;
}
return F_36 ( & V_22 -> V_23 , V_54 ) ;
}
static int F_37 ( struct V_66 * V_23 )
{
struct V_53 * V_54 = F_38 ( F_39 ( V_23 ) ) ;
struct V_1 * V_2 = F_22 ( V_54 ) ;
F_40 ( V_2 -> V_11 , true ) ;
return 0 ;
}
static int F_41 ( struct V_66 * V_23 )
{
struct V_53 * V_54 = F_38 ( F_39 ( V_23 ) ) ;
struct V_1 * V_2 = F_22 ( V_54 ) ;
int V_9 ;
F_42 ( V_2 -> V_11 ) ;
V_9 = F_43 ( V_2 -> V_11 , V_12 ,
V_25 ) ;
if ( V_9 < 0 )
F_8 ( V_23 , L_6 ) ;
F_40 ( V_2 -> V_11 , false ) ;
return 0 ;
}
