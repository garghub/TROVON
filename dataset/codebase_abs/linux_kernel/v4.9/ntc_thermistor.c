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
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_15 )
return NULL ;
V_2 = F_6 ( V_12 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return F_7 ( - V_18 ) ;
V_5 = F_8 ( V_12 , NULL ) ;
if ( F_9 ( V_5 ) )
return F_10 ( V_5 ) ;
V_8 = F_11 ( V_5 , & type ) ;
if ( V_8 < 0 )
return F_7 ( V_8 ) ;
if ( type != V_19 )
return F_7 ( - V_20 ) ;
if ( F_12 ( V_15 , L_2 , & V_2 -> V_9 ) )
return F_7 ( - V_21 ) ;
if ( F_12 ( V_15 , L_3 , & V_2 -> V_22 ) )
return F_7 ( - V_21 ) ;
if ( F_12 ( V_15 , L_4 , & V_2 -> V_23 ) )
return F_7 ( - V_21 ) ;
if ( F_13 ( V_15 , L_5 , NULL ) )
V_2 -> V_24 = V_25 ;
else
V_2 -> V_24 = V_26 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_27 = F_1 ;
return V_2 ;
}
static struct V_1 *
F_5 ( struct V_11 * V_12 )
{
return NULL ;
}
static inline T_1 F_14 ( T_1 V_28 , T_1 V_29 )
{
if ( V_29 == 0 && V_28 == 0 )
return 0 ;
if ( V_29 == 0 )
return V_30 ;
return F_15 ( V_28 , V_29 ) ;
}
static int F_16 ( struct V_31 * V_32 , unsigned int V_7 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_2 V_33 = V_2 -> V_9 ;
T_1 V_34 , V_35 , V_36 ;
V_35 = V_2 -> V_22 ;
V_36 = V_2 -> V_23 ;
if ( V_7 == 0 )
return ( V_2 -> V_24 == V_25 ) ?
V_37 : 0 ;
if ( V_7 >= V_33 )
return ( V_2 -> V_24 == V_25 ) ?
0 : V_37 ;
if ( V_2 -> V_24 == V_25 && V_35 == 0 )
V_34 = F_17 ( V_36 * ( V_33 - V_7 ) , V_7 ) ;
else if ( V_2 -> V_24 == V_26 && V_36 == 0 )
V_34 = F_17 ( V_35 * V_7 , V_33 - V_7 ) ;
else if ( V_2 -> V_24 == V_25 )
V_34 = F_14 ( V_36 * V_35 * ( V_33 - V_7 ) ,
V_35 * V_7 - V_36 * ( V_33 - V_7 ) ) ;
else
V_34 = F_14 ( V_36 * V_35 * V_7 , V_36 * ( V_33 - V_7 ) - V_35 * V_7 ) ;
if ( V_34 > V_37 )
V_34 = V_37 ;
return V_34 ;
}
static void F_18 ( struct V_31 * V_32 , unsigned int V_38 ,
int * V_39 , int * V_40 )
{
int V_41 , V_42 , V_43 ;
if ( V_38 >= V_32 -> V_44 [ 0 ] . V_38 ) {
* V_39 = 0 ;
* V_40 = 0 ;
return;
}
if ( V_38 <= V_32 -> V_44 [ V_32 -> V_45 - 1 ] . V_38 ) {
* V_39 = V_32 -> V_45 - 1 ;
* V_40 = V_32 -> V_45 - 1 ;
return;
}
V_41 = 0 ;
V_42 = V_32 -> V_45 ;
while ( V_41 < V_42 ) {
V_43 = V_41 + ( V_42 - V_41 ) / 2 ;
if ( V_38 >= V_32 -> V_44 [ V_43 ] . V_38 ) {
V_42 = V_43 ;
} else {
V_41 = V_43 + 1 ;
if ( V_38 >= V_32 -> V_44 [ V_41 ] . V_38 )
V_42 = V_41 ;
}
}
* V_39 = V_42 ;
if ( V_38 == V_32 -> V_44 [ V_42 ] . V_38 )
* V_40 = V_42 ;
else
* V_40 = V_42 - 1 ;
}
static int F_19 ( struct V_31 * V_32 , unsigned int V_38 )
{
int V_46 , V_47 ;
int V_48 ;
F_18 ( V_32 , V_38 , & V_46 , & V_47 ) ;
if ( V_46 == V_47 ) {
V_48 = V_32 -> V_44 [ V_46 ] . V_49 * 1000 ;
} else {
V_48 = V_32 -> V_44 [ V_46 ] . V_49 * 1000 +
( ( V_32 -> V_44 [ V_47 ] . V_49 - V_32 -> V_44 [ V_46 ] . V_49 ) *
1000 * ( ( int ) V_38 - ( int ) V_32 -> V_44 [ V_46 ] . V_38 ) ) /
( ( int ) V_32 -> V_44 [ V_47 ] . V_38 - ( int ) V_32 -> V_44 [ V_46 ] . V_38 ) ;
}
return V_48 ;
}
static int F_20 ( struct V_31 * V_32 )
{
int V_27 ;
if ( V_32 -> V_2 -> V_50 )
return V_32 -> V_2 -> V_50 () ;
if ( V_32 -> V_2 -> V_27 ) {
V_27 = V_32 -> V_2 -> V_27 ( V_32 -> V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_16 ( V_32 , V_27 ) ;
}
return - V_20 ;
}
static int F_21 ( void * V_32 , int * V_48 )
{
int V_38 ;
V_38 = F_20 ( V_32 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_48 = F_19 ( V_32 , V_38 ) ;
return 0 ;
}
static T_3 F_22 ( struct V_11 * V_12 ,
struct V_51 * V_52 , char * V_53 )
{
return sprintf ( V_53 , L_6 ) ;
}
static T_3 F_23 ( struct V_11 * V_12 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_31 * V_32 = F_24 ( V_12 ) ;
int V_38 ;
V_38 = F_20 ( V_32 ) ;
if ( V_38 < 0 )
return V_38 ;
return sprintf ( V_53 , L_7 , F_19 ( V_32 , V_38 ) ) ;
}
static int F_25 ( struct V_54 * V_55 )
{
struct V_56 * V_57 ;
struct V_11 * V_12 = & V_55 -> V_12 ;
const struct V_58 * V_59 =
F_26 ( F_27 ( V_60 ) , V_12 ) ;
const struct V_61 * V_62 ;
struct V_1 * V_2 ;
struct V_11 * V_63 ;
struct V_31 * V_32 ;
V_2 = F_5 ( V_12 ) ;
if ( F_9 ( V_2 ) )
return F_28 ( V_2 ) ;
else if ( V_2 == NULL )
V_2 = F_29 ( V_12 ) ;
if ( ! V_2 ) {
F_30 ( V_12 , L_8 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_27 && ! V_2 -> V_50 ) {
F_30 ( V_12 ,
L_9 ) ;
return - V_20 ;
}
if ( V_2 -> V_27 && V_2 -> V_50 ) {
F_31 ( V_12 ,
L_10 ) ;
V_2 -> V_27 = NULL ;
}
if ( V_2 -> V_27 && ( V_2 -> V_9 == 0 ||
( V_2 -> V_22 == 0 && V_2 -> V_24 ==
V_26 ) ||
( V_2 -> V_23 == 0 && V_2 -> V_24 ==
V_25 ) ||
( V_2 -> V_24 != V_25 &&
V_2 -> V_24 != V_26 ) ) ) {
F_30 ( V_12 , L_11 ) ;
return - V_20 ;
}
V_32 = F_6 ( V_12 , sizeof( struct V_31 ) , V_17 ) ;
if ( ! V_32 )
return - V_18 ;
V_62 = V_59 ? V_59 -> V_32 : F_32 ( V_55 ) ;
V_32 -> V_2 = V_2 ;
switch ( V_62 -> V_64 ) {
case V_65 :
V_32 -> V_44 = V_66 ;
V_32 -> V_45 = F_33 ( V_66 ) ;
break;
case V_67 :
V_32 -> V_44 = V_68 ;
V_32 -> V_45 = F_33 ( V_68 ) ;
break;
case V_69 :
V_32 -> V_44 = V_70 ;
V_32 -> V_45 = F_33 ( V_70 ) ;
break;
case V_71 :
V_32 -> V_44 = V_72 ;
V_32 -> V_45 = F_33 ( V_72 ) ;
break;
case V_73 :
V_32 -> V_44 = V_74 ;
V_32 -> V_45 = F_33 ( V_74 ) ;
break;
default:
F_30 ( V_12 , L_12 ,
V_62 -> V_64 , V_62 -> V_75 ) ;
return - V_20 ;
}
V_63 = F_34 ( V_12 , V_62 -> V_75 ,
V_32 , V_76 ) ;
if ( F_9 ( V_63 ) ) {
F_30 ( V_12 , L_13 ) ;
return F_28 ( V_63 ) ;
}
F_35 ( V_12 , L_14 ,
V_62 -> V_75 ) ;
V_57 = F_36 ( V_12 , 0 , V_32 ,
& V_77 ) ;
if ( F_9 ( V_57 ) )
F_37 ( V_12 , L_15 ) ;
return 0 ;
}
