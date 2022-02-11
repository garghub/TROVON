static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_5 [ 0 ] . V_6 = F_2 ( F_3 ( V_3 ) | V_4 ) ;
return F_4 ( V_2 -> V_7 , & V_2 -> V_5 [ 0 ] . V_8 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_9 * V_10 , T_1 V_3 , T_2 V_4 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_11 ;
F_7 ( & V_10 -> V_12 ) ;
V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_10 -> V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_11 ;
struct V_13 V_14 [] = {
{
. V_15 = & V_2 -> V_5 [ 0 ] . V_8 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
. V_18 = true ,
} , {
. V_15 = & V_2 -> V_5 [ 1 ] . V_8 [ 1 ] ,
. V_19 = & V_2 -> V_5 [ 2 ] . V_8 [ 1 ] ,
. V_16 = 8 ,
. V_17 = 3 ,
} ,
} ;
V_2 -> V_5 [ 0 ] . V_6 = F_2 ( F_3 ( V_3 ) ) ;
V_2 -> V_5 [ 1 ] . V_6 = F_2 ( F_3 ( V_20 ) ) ;
V_11 = F_10 ( V_2 -> V_7 , V_14 , F_11 ( V_14 ) ) ;
* V_4 = F_12 ( V_2 -> V_5 [ 2 ] . V_6 ) ;
return V_11 ;
}
static int F_13 ( struct V_9 * V_10 , T_1 V_3 , T_2 * V_4 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_11 ;
F_7 ( & V_10 -> V_12 ) ;
V_11 = F_9 ( V_2 , V_3 , V_4 ) ;
F_8 ( & V_10 -> V_12 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_21 V_22 )
{
T_2 V_23 ;
int V_11 ;
V_23 = ( V_22 & 0x7 ) | V_24 ;
if ( V_2 -> V_25 )
V_23 |= V_26 ;
V_11 = F_1 ( V_2 , V_27 , 0 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_2 , V_28 , V_23 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_29 const * V_30 ,
int * V_4 ,
int * V_31 ,
long V_32 )
{
struct V_1 * V_2 ;
int V_11 ;
T_2 V_23 ;
switch ( V_32 ) {
case V_33 :
V_11 = F_13 ( V_10 , V_34 , & V_23 ) ;
if ( V_11 )
return V_11 ;
* V_4 = V_23 >> V_30 -> V_35 . V_36 ;
return V_37 ;
case V_38 :
V_2 = F_6 ( V_10 ) ;
* V_4 = V_2 -> V_39 * V_40 [ V_2 -> V_22 ] . V_41 ;
* V_4 /= 10 ;
* V_31 = V_30 -> V_35 . V_42 ;
return V_43 ;
case V_44 :
V_2 = F_6 ( V_10 ) ;
* V_4 = - ( 1 << V_30 -> V_35 . V_42 ) ;
* V_4 *= V_40 [ V_2 -> V_22 ] . V_45 ;
* V_4 /= V_40 [ V_2 -> V_22 ] . V_41 ;
return V_37 ;
default:
return - V_46 ;
}
}
static int F_16 ( struct V_9 * V_10 ,
struct V_29 const * V_30 ,
int V_4 ,
int V_31 ,
long V_32 )
{
T_2 V_23 ;
if ( V_32 != V_33 )
return - V_46 ;
if ( V_31 || ( V_4 << V_30 -> V_35 . V_36 ) > 0xffff || V_4 < 0 )
return - V_46 ;
V_23 = V_4 << V_30 -> V_35 . V_36 ;
return F_5 ( V_10 , V_47 , V_23 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
int V_11 ;
V_2 -> V_50 = F_18 ( & V_2 -> V_7 -> V_51 , L_1 ) ;
if ( F_19 ( V_2 -> V_50 ) == - V_52 ) {
if ( ! V_49 -> V_53 ) {
F_20 ( & V_2 -> V_7 -> V_51 ,
L_2 ) ;
return - V_54 ;
}
V_2 -> V_25 = true ;
V_2 -> V_39 = V_49 -> V_53 ;
return 0 ;
}
if ( F_21 ( V_2 -> V_50 ) ) {
F_20 ( & V_2 -> V_7 -> V_51 ,
L_3 ) ;
return F_19 ( V_2 -> V_50 ) ;
}
V_11 = F_22 ( V_2 -> V_50 ) ;
if ( V_11 ) {
F_20 ( & V_2 -> V_7 -> V_51 ,
L_4 ) ;
return V_11 ;
}
V_11 = F_23 ( V_2 -> V_50 ) ;
if ( V_11 < 0 ) {
F_20 ( & V_2 -> V_7 -> V_51 ,
L_5 ) ;
goto V_55;
}
if ( V_11 < 2000000 || V_11 > 3000000 ) {
F_24 ( & V_2 -> V_7 -> V_51 ,
L_6 , V_11 ) ;
V_11 = - V_54 ;
goto V_55;
}
V_2 -> V_39 = V_11 / 1000 ;
V_2 -> V_25 = false ;
return 0 ;
V_55:
F_25 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
return V_11 ;
}
static int F_26 ( struct V_56 * V_7 )
{
struct V_9 * V_9 ;
struct V_1 * V_2 ;
int V_11 ;
const struct V_48 * V_49 =
& V_57 [ F_27 ( V_7 ) -> V_58 ] ;
enum V_21 V_59 = V_60 ;
struct V_61 * V_62 = F_28 ( & V_7 -> V_51 ) ;
V_9 = F_29 ( & V_7 -> V_51 , sizeof( * V_2 ) ) ;
if ( ! V_9 )
return - V_63 ;
V_2 = F_6 ( V_9 ) ;
V_2 -> V_7 = V_7 ;
F_30 ( V_7 , V_9 ) ;
V_11 = F_17 ( V_2 , V_49 ) ;
if ( V_11 )
return V_11 ;
if ( V_62 )
V_59 = V_62 -> V_59 ;
V_11 = F_14 ( V_2 , V_59 ) ;
if ( V_11 )
goto V_64;
V_9 -> V_51 . V_65 = & V_7 -> V_51 ;
V_9 -> V_66 = & V_67 ;
V_9 -> V_68 = V_69 ;
V_9 -> V_70 = & V_49 -> V_71 ;
V_9 -> V_72 = 1 ;
V_9 -> V_73 = F_27 ( V_2 -> V_7 ) -> V_73 ;
V_11 = F_31 ( V_9 ) ;
if ( V_11 )
goto V_64;
return 0 ;
V_64:
if ( ! F_32 ( V_2 -> V_50 ) )
F_25 ( V_2 -> V_50 ) ;
return V_11 ;
}
static int F_33 ( struct V_56 * V_7 )
{
struct V_9 * V_9 = F_34 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_35 ( V_9 ) ;
if ( ! F_32 ( V_2 -> V_50 ) )
F_25 ( V_2 -> V_50 ) ;
return 0 ;
}
