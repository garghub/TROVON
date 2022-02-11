static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_7 , V_8 ;
V_8 = F_2 ( V_4 , & V_6 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 , V_8 ) ;
return V_8 ;
}
V_8 = F_4 ( V_4 , V_6 , & V_7 , 1000 ) ;
if ( V_8 < 0 ) {
V_7 = ( V_2 -> V_9 * ( V_10 ) V_6 ) >> 12 ;
}
return V_7 ;
}
static struct V_1 *
F_5 ( struct V_11 * V_12 )
{
struct V_3 * V_5 ;
enum V_13 type ;
struct V_14 * V_15 = V_12 -> V_16 . V_17 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_15 )
return NULL ;
V_2 = F_6 ( & V_12 -> V_16 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_7 ( - V_19 ) ;
V_5 = F_8 ( & V_12 -> V_16 , NULL ) ;
if ( F_9 ( V_5 ) )
return F_10 ( V_5 ) ;
V_8 = F_11 ( V_5 , & type ) ;
if ( V_8 < 0 )
return F_7 ( V_8 ) ;
if ( type != V_20 )
return F_7 ( - V_21 ) ;
if ( F_12 ( V_15 , L_2 , & V_2 -> V_9 ) )
return F_7 ( - V_22 ) ;
if ( F_12 ( V_15 , L_3 , & V_2 -> V_23 ) )
return F_7 ( - V_22 ) ;
if ( F_12 ( V_15 , L_4 , & V_2 -> V_24 ) )
return F_7 ( - V_22 ) ;
if ( F_13 ( V_15 , L_5 , NULL ) )
V_2 -> V_25 = V_26 ;
else
V_2 -> V_25 = V_27 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_28 = F_1 ;
return V_2 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_15 ( V_2 -> V_5 ) ;
}
static struct V_1 *
F_5 ( struct V_11 * V_12 )
{
return NULL ;
}
static void F_14 ( struct V_1 * V_2 )
{ }
static inline T_1 F_16 ( T_1 V_29 , T_1 V_30 )
{
if ( V_30 == 0 && V_29 == 0 )
return 0 ;
if ( V_30 == 0 )
return V_31 ;
return F_17 ( V_29 , V_30 ) ;
}
static int F_18 ( struct V_32 * V_33 , unsigned int V_7 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_2 V_34 = V_2 -> V_9 ;
T_1 V_35 , V_36 , V_37 ;
V_36 = V_2 -> V_23 ;
V_37 = V_2 -> V_24 ;
if ( V_7 == 0 )
return ( V_2 -> V_25 == V_26 ) ?
V_38 : 0 ;
if ( V_7 >= V_34 )
return ( V_2 -> V_25 == V_26 ) ?
0 : V_38 ;
if ( V_2 -> V_25 == V_26 && V_36 == 0 )
V_35 = F_19 ( V_37 * ( V_34 - V_7 ) , V_7 ) ;
else if ( V_2 -> V_25 == V_27 && V_37 == 0 )
V_35 = F_19 ( V_36 * V_7 , V_34 - V_7 ) ;
else if ( V_2 -> V_25 == V_26 )
V_35 = F_16 ( V_37 * V_36 * ( V_34 - V_7 ) ,
V_36 * V_7 - V_37 * ( V_34 - V_7 ) ) ;
else
V_35 = F_16 ( V_37 * V_36 * V_7 , V_37 * ( V_34 - V_7 ) - V_36 * V_7 ) ;
if ( V_35 > V_38 )
V_35 = V_38 ;
return V_35 ;
}
static void F_20 ( struct V_32 * V_33 , unsigned int V_39 ,
int * V_40 , int * V_41 )
{
int V_42 , V_43 , V_44 ;
if ( V_39 >= V_33 -> V_45 [ 0 ] . V_39 ) {
* V_40 = 0 ;
* V_41 = 0 ;
return;
}
if ( V_39 <= V_33 -> V_45 [ V_33 -> V_46 - 1 ] . V_39 ) {
* V_40 = V_33 -> V_46 - 1 ;
* V_41 = V_33 -> V_46 - 1 ;
return;
}
V_42 = 0 ;
V_43 = V_33 -> V_46 ;
while ( V_42 < V_43 ) {
V_44 = V_42 + ( V_43 - V_42 ) / 2 ;
if ( V_39 >= V_33 -> V_45 [ V_44 ] . V_39 ) {
V_43 = V_44 ;
} else {
V_42 = V_44 + 1 ;
if ( V_39 >= V_33 -> V_45 [ V_42 ] . V_39 )
V_43 = V_42 ;
}
}
* V_40 = V_43 ;
if ( V_39 == V_33 -> V_45 [ V_43 ] . V_39 )
* V_41 = V_43 ;
else
* V_41 = V_43 - 1 ;
}
static int F_21 ( struct V_32 * V_33 , unsigned int V_39 )
{
int V_47 , V_48 ;
int V_49 ;
F_20 ( V_33 , V_39 , & V_47 , & V_48 ) ;
if ( V_47 == V_48 ) {
V_49 = V_33 -> V_45 [ V_47 ] . V_50 * 1000 ;
} else {
V_49 = V_33 -> V_45 [ V_47 ] . V_50 * 1000 +
( ( V_33 -> V_45 [ V_48 ] . V_50 - V_33 -> V_45 [ V_47 ] . V_50 ) *
1000 * ( ( int ) V_39 - ( int ) V_33 -> V_45 [ V_47 ] . V_39 ) ) /
( ( int ) V_33 -> V_45 [ V_48 ] . V_39 - ( int ) V_33 -> V_45 [ V_47 ] . V_39 ) ;
}
return V_49 ;
}
static int F_22 ( struct V_32 * V_33 )
{
int V_28 ;
if ( V_33 -> V_2 -> V_51 )
return V_33 -> V_2 -> V_51 () ;
if ( V_33 -> V_2 -> V_28 ) {
V_28 = V_33 -> V_2 -> V_28 ( V_33 -> V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_18 ( V_33 , V_28 ) ;
}
return - V_21 ;
}
static int F_23 ( void * V_16 , long * V_49 )
{
struct V_32 * V_33 = F_24 ( V_16 ) ;
int V_39 ;
V_39 = F_22 ( V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
* V_49 = F_21 ( V_33 , V_39 ) ;
return 0 ;
}
static T_3 F_25 ( struct V_52 * V_16 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_32 * V_33 = F_24 ( V_16 ) ;
return sprintf ( V_55 , L_6 , V_33 -> V_56 ) ;
}
static T_3 F_26 ( struct V_52 * V_16 ,
struct V_53 * V_54 , char * V_55 )
{
return sprintf ( V_55 , L_7 ) ;
}
static T_3 F_27 ( struct V_52 * V_16 ,
struct V_53 * V_54 , char * V_55 )
{
struct V_32 * V_33 = F_24 ( V_16 ) ;
int V_39 ;
V_39 = F_22 ( V_33 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_55 , L_8 , F_21 ( V_33 , V_39 ) ) ;
}
static int F_28 ( struct V_11 * V_12 )
{
const struct V_57 * V_58 =
F_29 ( F_30 ( V_59 ) , & V_12 -> V_16 ) ;
const struct V_60 * V_61 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_8 ;
V_2 = F_5 ( V_12 ) ;
if ( F_9 ( V_2 ) )
return F_31 ( V_2 ) ;
else if ( V_2 == NULL )
V_2 = F_32 ( & V_12 -> V_16 ) ;
if ( ! V_2 ) {
F_33 ( & V_12 -> V_16 , L_9 ) ;
return - V_22 ;
}
if ( ! V_2 -> V_28 && ! V_2 -> V_51 ) {
F_33 ( & V_12 -> V_16 ,
L_10 ) ;
return - V_21 ;
}
if ( V_2 -> V_28 && V_2 -> V_51 ) {
F_34 ( & V_12 -> V_16 ,
L_11 ) ;
V_2 -> V_28 = NULL ;
}
if ( V_2 -> V_28 && ( V_2 -> V_9 == 0 ||
( V_2 -> V_23 == 0 && V_2 -> V_25 ==
V_27 ) ||
( V_2 -> V_24 == 0 && V_2 -> V_25 ==
V_26 ) ||
( V_2 -> V_25 != V_26 &&
V_2 -> V_25 != V_27 ) ) ) {
F_33 ( & V_12 -> V_16 ,
L_12 ) ;
return - V_21 ;
}
V_33 = F_6 ( & V_12 -> V_16 , sizeof( struct V_32 ) , V_18 ) ;
if ( ! V_33 )
return - V_19 ;
V_61 = V_58 ? V_58 -> V_33 : F_35 ( V_12 ) ;
V_33 -> V_16 = & V_12 -> V_16 ;
V_33 -> V_2 = V_2 ;
F_36 ( V_33 -> V_56 , V_61 -> V_56 , sizeof( V_33 -> V_56 ) ) ;
switch ( V_61 -> V_62 ) {
case V_63 :
V_33 -> V_45 = V_64 ;
V_33 -> V_46 = F_37 ( V_64 ) ;
break;
case V_65 :
V_33 -> V_45 = V_66 ;
V_33 -> V_46 = F_37 ( V_66 ) ;
break;
case V_67 :
V_33 -> V_45 = V_68 ;
V_33 -> V_46 = F_37 ( V_68 ) ;
break;
case V_69 :
V_33 -> V_45 = V_70 ;
V_33 -> V_46 = F_37 ( V_70 ) ;
break;
default:
F_33 ( & V_12 -> V_16 , L_13 ,
V_61 -> V_62 , V_61 -> V_56 ) ;
return - V_21 ;
}
F_38 ( V_12 , V_33 ) ;
V_8 = F_39 ( & V_33 -> V_16 -> V_71 , & V_72 ) ;
if ( V_8 ) {
F_33 ( V_33 -> V_16 , L_14 ) ;
return V_8 ;
}
V_33 -> V_73 = F_40 ( V_33 -> V_16 ) ;
if ( F_9 ( V_33 -> V_73 ) ) {
F_33 ( V_33 -> V_16 , L_15 ) ;
V_8 = F_31 ( V_33 -> V_73 ) ;
goto V_74;
}
F_41 ( & V_12 -> V_16 , L_16 ,
V_61 -> V_56 ) ;
V_33 -> V_75 = F_42 ( V_33 -> V_16 , 0 , V_33 -> V_16 ,
& V_76 ) ;
if ( F_9 ( V_33 -> V_75 ) ) {
F_43 ( & V_12 -> V_16 , L_17 ) ;
V_33 -> V_75 = NULL ;
}
return 0 ;
V_74:
F_44 ( & V_33 -> V_16 -> V_71 , & V_72 ) ;
F_14 ( V_2 ) ;
return V_8 ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_32 * V_33 = F_46 ( V_12 ) ;
struct V_1 * V_2 = V_33 -> V_2 ;
F_47 ( V_33 -> V_73 ) ;
F_44 ( & V_33 -> V_16 -> V_71 , & V_72 ) ;
F_14 ( V_2 ) ;
F_48 ( V_33 -> V_16 , V_33 -> V_75 ) ;
return 0 ;
}
