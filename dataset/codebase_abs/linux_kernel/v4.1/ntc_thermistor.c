static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
int V_7 , V_8 ;
V_8 = F_2 ( V_4 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 , V_8 ) ;
return V_8 ;
}
V_6 = V_2 -> V_9 * ( T_1 ) V_7 ;
V_6 >>= 12 ;
return ( int ) V_6 ;
}
static struct V_1 *
F_4 ( struct V_10 * V_11 )
{
struct V_3 * V_5 ;
enum V_12 type ;
struct V_13 * V_14 = V_11 -> V_15 . V_16 ;
struct V_1 * V_2 ;
int V_8 ;
if ( ! V_14 )
return NULL ;
V_2 = F_5 ( & V_11 -> V_15 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return F_6 ( - V_18 ) ;
V_5 = F_7 ( & V_11 -> V_15 , NULL ) ;
if ( F_8 ( V_5 ) )
return F_9 ( V_5 ) ;
V_8 = F_10 ( V_5 , & type ) ;
if ( V_8 < 0 )
return F_6 ( V_8 ) ;
if ( type != V_19 )
return F_6 ( - V_20 ) ;
if ( F_11 ( V_14 , L_2 , & V_2 -> V_9 ) )
return F_6 ( - V_21 ) ;
if ( F_11 ( V_14 , L_3 , & V_2 -> V_22 ) )
return F_6 ( - V_21 ) ;
if ( F_11 ( V_14 , L_4 , & V_2 -> V_23 ) )
return F_6 ( - V_21 ) ;
if ( F_12 ( V_14 , L_5 , NULL ) )
V_2 -> V_24 = V_25 ;
else
V_2 -> V_24 = V_26 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_27 = F_1 ;
return V_2 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_14 ( V_2 -> V_5 ) ;
}
static struct V_1 *
F_4 ( struct V_10 * V_11 )
{
return NULL ;
}
static void F_13 ( struct V_1 * V_2 )
{ }
static inline T_2 F_15 ( T_2 V_28 , T_2 V_29 )
{
if ( V_29 == 0 && V_28 == 0 )
return 0 ;
if ( V_29 == 0 )
return V_30 ;
return F_16 ( V_28 , V_29 ) ;
}
static int F_17 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_1 * V_2 = V_32 -> V_2 ;
T_2 V_34 = V_33 / 1000 ;
T_2 V_35 = V_2 -> V_9 / 1000 ;
T_2 V_36 , V_37 , V_38 ;
V_37 = V_2 -> V_22 ;
V_38 = V_2 -> V_23 ;
if ( V_34 == 0 ) {
if ( V_2 -> V_24 == V_25 )
return V_39 ;
return 0 ;
}
if ( V_34 >= V_35 )
return ( V_2 -> V_24 == V_25 ) ?
0 : V_39 ;
if ( V_2 -> V_24 == V_25 && V_37 == 0 )
V_36 = F_15 ( V_38 * ( V_35 - V_34 ) , V_34 ) ;
else if ( V_2 -> V_24 == V_26 && V_38 == 0 )
V_36 = F_15 ( V_37 * V_34 , V_35 - V_34 ) ;
else if ( V_2 -> V_24 == V_25 )
V_36 = F_15 ( V_38 * V_37 * ( V_35 - V_34 ) ,
V_37 * V_34 - V_38 * ( V_35 - V_34 ) ) ;
else
V_36 = F_15 ( V_38 * V_37 * V_34 , V_38 * ( V_35 - V_34 ) - V_37 * V_34 ) ;
if ( V_36 > V_39 )
V_36 = V_39 ;
return V_36 ;
}
static void F_18 ( struct V_31 * V_32 , unsigned int V_40 ,
int * V_41 , int * V_42 )
{
int V_43 , V_44 , V_45 ;
if ( V_40 >= V_32 -> V_46 [ 0 ] . V_40 ) {
* V_41 = 0 ;
* V_42 = 0 ;
return;
}
if ( V_40 <= V_32 -> V_46 [ V_32 -> V_47 - 1 ] . V_40 ) {
* V_41 = V_32 -> V_47 - 1 ;
* V_42 = V_32 -> V_47 - 1 ;
return;
}
V_43 = 0 ;
V_44 = V_32 -> V_47 ;
while ( V_43 < V_44 ) {
V_45 = V_43 + ( V_44 - V_43 ) / 2 ;
if ( V_40 >= V_32 -> V_46 [ V_45 ] . V_40 ) {
V_44 = V_45 ;
} else {
V_43 = V_45 + 1 ;
if ( V_40 >= V_32 -> V_46 [ V_43 ] . V_40 )
V_44 = V_43 ;
}
}
* V_41 = V_44 ;
if ( V_40 == V_32 -> V_46 [ V_44 ] . V_40 )
* V_42 = V_44 ;
else
* V_42 = V_44 - 1 ;
}
static int F_19 ( struct V_31 * V_32 , unsigned int V_40 )
{
int V_48 , V_49 ;
int V_50 ;
F_18 ( V_32 , V_40 , & V_48 , & V_49 ) ;
if ( V_48 == V_49 ) {
V_50 = V_32 -> V_46 [ V_48 ] . V_51 * 1000 ;
} else {
V_50 = V_32 -> V_46 [ V_48 ] . V_51 * 1000 +
( ( V_32 -> V_46 [ V_49 ] . V_51 - V_32 -> V_46 [ V_48 ] . V_51 ) *
1000 * ( ( int ) V_40 - ( int ) V_32 -> V_46 [ V_48 ] . V_40 ) ) /
( ( int ) V_32 -> V_46 [ V_49 ] . V_40 - ( int ) V_32 -> V_46 [ V_48 ] . V_40 ) ;
}
return V_50 ;
}
static int F_20 ( struct V_31 * V_32 )
{
int V_27 ;
if ( V_32 -> V_2 -> V_52 )
return V_32 -> V_2 -> V_52 () ;
if ( V_32 -> V_2 -> V_27 ) {
V_27 = V_32 -> V_2 -> V_27 ( V_32 -> V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_17 ( V_32 , V_27 ) ;
}
return - V_20 ;
}
static int F_21 ( void * V_15 , long * V_50 )
{
struct V_31 * V_32 = F_22 ( V_15 ) ;
int V_40 ;
V_40 = F_20 ( V_32 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_50 = F_19 ( V_32 , V_40 ) ;
return 0 ;
}
static T_3 F_23 ( struct V_53 * V_15 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_31 * V_32 = F_22 ( V_15 ) ;
return sprintf ( V_56 , L_6 , V_32 -> V_57 ) ;
}
static T_3 F_24 ( struct V_53 * V_15 ,
struct V_54 * V_55 , char * V_56 )
{
return sprintf ( V_56 , L_7 ) ;
}
static T_3 F_25 ( struct V_53 * V_15 ,
struct V_54 * V_55 , char * V_56 )
{
struct V_31 * V_32 = F_22 ( V_15 ) ;
int V_40 ;
V_40 = F_20 ( V_32 ) ;
if ( V_40 < 0 )
return V_40 ;
return sprintf ( V_56 , L_8 , F_19 ( V_32 , V_40 ) ) ;
}
static int F_26 ( struct V_10 * V_11 )
{
const struct V_58 * V_59 =
F_27 ( F_28 ( V_60 ) , & V_11 -> V_15 ) ;
const struct V_61 * V_62 ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_8 ;
V_2 = F_4 ( V_11 ) ;
if ( F_8 ( V_2 ) )
return F_29 ( V_2 ) ;
else if ( V_2 == NULL )
V_2 = F_30 ( & V_11 -> V_15 ) ;
if ( ! V_2 ) {
F_31 ( & V_11 -> V_15 , L_9 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_27 && ! V_2 -> V_52 ) {
F_31 ( & V_11 -> V_15 ,
L_10 ) ;
return - V_20 ;
}
if ( V_2 -> V_27 && V_2 -> V_52 ) {
F_32 ( & V_11 -> V_15 ,
L_11 ) ;
V_2 -> V_27 = NULL ;
}
if ( V_2 -> V_27 && ( V_2 -> V_9 == 0 ||
( V_2 -> V_22 == 0 && V_2 -> V_24 ==
V_26 ) ||
( V_2 -> V_23 == 0 && V_2 -> V_24 ==
V_25 ) ||
( V_2 -> V_24 != V_25 &&
V_2 -> V_24 != V_26 ) ) ) {
F_31 ( & V_11 -> V_15 ,
L_12 ) ;
return - V_20 ;
}
V_32 = F_5 ( & V_11 -> V_15 , sizeof( struct V_31 ) , V_17 ) ;
if ( ! V_32 )
return - V_18 ;
V_62 = V_59 ? V_59 -> V_32 : F_33 ( V_11 ) ;
V_32 -> V_15 = & V_11 -> V_15 ;
V_32 -> V_2 = V_2 ;
F_34 ( V_32 -> V_57 , V_62 -> V_57 , sizeof( V_32 -> V_57 ) ) ;
switch ( V_62 -> V_63 ) {
case V_64 :
V_32 -> V_46 = V_65 ;
V_32 -> V_47 = F_35 ( V_65 ) ;
break;
case V_66 :
V_32 -> V_46 = V_67 ;
V_32 -> V_47 = F_35 ( V_67 ) ;
break;
case V_68 :
V_32 -> V_46 = V_69 ;
V_32 -> V_47 = F_35 ( V_69 ) ;
break;
default:
F_31 ( & V_11 -> V_15 , L_13 ,
V_62 -> V_63 , V_62 -> V_57 ) ;
return - V_20 ;
}
F_36 ( V_11 , V_32 ) ;
V_8 = F_37 ( & V_32 -> V_15 -> V_70 , & V_71 ) ;
if ( V_8 ) {
F_31 ( V_32 -> V_15 , L_14 ) ;
return V_8 ;
}
V_32 -> V_72 = F_38 ( V_32 -> V_15 ) ;
if ( F_8 ( V_32 -> V_72 ) ) {
F_31 ( V_32 -> V_15 , L_15 ) ;
V_8 = F_29 ( V_32 -> V_72 ) ;
goto V_73;
}
F_39 ( & V_11 -> V_15 , L_16 ,
V_62 -> V_57 ) ;
V_32 -> V_74 = F_40 ( V_32 -> V_15 , 0 , V_32 -> V_15 ,
& V_75 ) ;
if ( F_8 ( V_32 -> V_74 ) ) {
F_41 ( & V_11 -> V_15 , L_17 ) ;
V_32 -> V_74 = NULL ;
}
return 0 ;
V_73:
F_42 ( & V_32 -> V_15 -> V_70 , & V_71 ) ;
F_13 ( V_2 ) ;
return V_8 ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_31 * V_32 = F_44 ( V_11 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
F_45 ( V_32 -> V_72 ) ;
F_42 ( & V_32 -> V_15 -> V_70 , & V_71 ) ;
F_13 ( V_2 ) ;
F_46 ( V_32 -> V_15 , V_32 -> V_74 ) ;
return 0 ;
}
