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
struct V_12 * V_13 = V_11 -> V_14 . V_15 ;
struct V_1 * V_2 ;
if ( ! V_13 )
return NULL ;
V_2 = F_5 ( & V_11 -> V_14 , sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_6 ( - V_17 ) ;
V_5 = F_7 ( & V_11 -> V_14 , NULL ) ;
if ( F_8 ( V_5 ) )
return F_9 ( V_5 ) ;
if ( F_10 ( V_13 , L_2 , & V_2 -> V_9 ) )
return F_6 ( - V_18 ) ;
if ( F_10 ( V_13 , L_3 , & V_2 -> V_19 ) )
return F_6 ( - V_18 ) ;
if ( F_10 ( V_13 , L_4 , & V_2 -> V_20 ) )
return F_6 ( - V_18 ) ;
if ( F_11 ( V_13 , L_5 , NULL ) )
V_2 -> V_21 = V_22 ;
else
V_2 -> V_21 = V_23 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_24 = F_1 ;
return V_2 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_13 ( V_2 -> V_5 ) ;
}
static struct V_1 *
F_4 ( struct V_10 * V_11 )
{
return NULL ;
}
static void F_12 ( struct V_1 * V_2 )
{ }
static inline T_2 F_14 ( T_2 V_25 , T_2 V_26 )
{
if ( V_26 == 0 && V_25 == 0 )
return 0 ;
if ( V_26 == 0 )
return V_27 ;
return F_15 ( V_25 , V_26 ) ;
}
static int F_16 ( struct V_28 * V_29 , unsigned int V_30 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
T_2 V_31 = V_30 / 1000 ;
T_2 V_32 = V_2 -> V_9 / 1000 ;
T_2 V_33 , V_34 , V_35 ;
V_34 = V_2 -> V_19 ;
V_35 = V_2 -> V_20 ;
if ( V_31 == 0 ) {
if ( V_2 -> V_21 == V_22 )
return V_36 ;
return 0 ;
}
if ( V_31 >= V_32 )
return ( V_2 -> V_21 == V_22 ) ?
0 : V_36 ;
if ( V_2 -> V_21 == V_22 && V_34 == 0 )
V_33 = F_14 ( V_35 * ( V_32 - V_31 ) , V_31 ) ;
else if ( V_2 -> V_21 == V_23 && V_35 == 0 )
V_33 = F_14 ( V_34 * V_31 , V_32 - V_31 ) ;
else if ( V_2 -> V_21 == V_22 )
V_33 = F_14 ( V_35 * V_34 * ( V_32 - V_31 ) ,
V_34 * V_31 - V_35 * ( V_32 - V_31 ) ) ;
else
V_33 = F_14 ( V_35 * V_34 * V_31 , V_35 * ( V_32 - V_31 ) - V_34 * V_31 ) ;
if ( V_33 > V_36 )
V_33 = V_36 ;
return V_33 ;
}
static void F_17 ( struct V_28 * V_29 , unsigned int V_37 ,
int * V_38 , int * V_39 )
{
int V_40 , V_41 , V_42 ;
if ( V_37 >= V_29 -> V_43 [ 0 ] . V_37 ) {
* V_38 = 0 ;
* V_39 = 0 ;
return;
}
if ( V_37 <= V_29 -> V_43 [ V_29 -> V_44 - 1 ] . V_37 ) {
* V_38 = V_29 -> V_44 - 1 ;
* V_39 = V_29 -> V_44 - 1 ;
return;
}
V_40 = 0 ;
V_41 = V_29 -> V_44 ;
while ( V_40 < V_41 ) {
V_42 = V_40 + ( V_41 - V_40 ) / 2 ;
if ( V_37 >= V_29 -> V_43 [ V_42 ] . V_37 ) {
V_41 = V_42 ;
} else {
V_40 = V_42 + 1 ;
if ( V_37 >= V_29 -> V_43 [ V_40 ] . V_37 )
V_41 = V_40 ;
}
}
* V_38 = V_41 ;
if ( V_37 == V_29 -> V_43 [ V_41 ] . V_37 )
* V_39 = V_41 ;
else
* V_39 = V_41 - 1 ;
}
static int F_18 ( struct V_28 * V_29 , unsigned int V_37 )
{
int V_45 , V_46 ;
int V_47 ;
F_17 ( V_29 , V_37 , & V_45 , & V_46 ) ;
if ( V_45 == V_46 ) {
V_47 = V_29 -> V_43 [ V_45 ] . V_48 * 1000 ;
} else {
V_47 = V_29 -> V_43 [ V_45 ] . V_48 * 1000 +
( ( V_29 -> V_43 [ V_46 ] . V_48 - V_29 -> V_43 [ V_45 ] . V_48 ) *
1000 * ( ( int ) V_37 - ( int ) V_29 -> V_43 [ V_45 ] . V_37 ) ) /
( ( int ) V_29 -> V_43 [ V_46 ] . V_37 - ( int ) V_29 -> V_43 [ V_45 ] . V_37 ) ;
}
return V_47 ;
}
static int F_19 ( struct V_28 * V_29 )
{
int V_24 ;
if ( V_29 -> V_2 -> V_49 )
return V_29 -> V_2 -> V_49 () ;
if ( V_29 -> V_2 -> V_24 ) {
V_24 = V_29 -> V_2 -> V_24 ( V_29 -> V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
return F_16 ( V_29 , V_24 ) ;
}
return - V_50 ;
}
static int F_20 ( void * V_14 , long * V_47 )
{
struct V_28 * V_29 = F_21 ( V_14 ) ;
int V_37 ;
V_37 = F_19 ( V_29 ) ;
if ( V_37 < 0 )
return V_37 ;
* V_47 = F_18 ( V_29 , V_37 ) ;
return 0 ;
}
static T_3 F_22 ( struct V_51 * V_14 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_28 * V_29 = F_21 ( V_14 ) ;
return sprintf ( V_54 , L_6 , V_29 -> V_55 ) ;
}
static T_3 F_23 ( struct V_51 * V_14 ,
struct V_52 * V_53 , char * V_54 )
{
return sprintf ( V_54 , L_7 ) ;
}
static T_3 F_24 ( struct V_51 * V_14 ,
struct V_52 * V_53 , char * V_54 )
{
struct V_28 * V_29 = F_21 ( V_14 ) ;
int V_37 ;
V_37 = F_19 ( V_29 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_54 , L_8 , F_18 ( V_29 , V_37 ) ) ;
}
static int F_25 ( struct V_10 * V_11 )
{
const struct V_56 * V_57 =
F_26 ( F_27 ( V_58 ) , & V_11 -> V_14 ) ;
const struct V_59 * V_60 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_8 ;
V_2 = F_4 ( V_11 ) ;
if ( F_8 ( V_2 ) )
return F_28 ( V_2 ) ;
else if ( V_2 == NULL )
V_2 = F_29 ( & V_11 -> V_14 ) ;
if ( ! V_2 ) {
F_30 ( & V_11 -> V_14 , L_9 ) ;
return - V_18 ;
}
if ( ! V_2 -> V_24 && ! V_2 -> V_49 ) {
F_30 ( & V_11 -> V_14 ,
L_10 ) ;
return - V_50 ;
}
if ( V_2 -> V_24 && V_2 -> V_49 ) {
F_31 ( & V_11 -> V_14 ,
L_11 ) ;
V_2 -> V_24 = NULL ;
}
if ( V_2 -> V_24 && ( V_2 -> V_9 == 0 ||
( V_2 -> V_19 == 0 && V_2 -> V_21 ==
V_23 ) ||
( V_2 -> V_20 == 0 && V_2 -> V_21 ==
V_22 ) ||
( V_2 -> V_21 != V_22 &&
V_2 -> V_21 != V_23 ) ) ) {
F_30 ( & V_11 -> V_14 ,
L_12 ) ;
return - V_50 ;
}
V_29 = F_5 ( & V_11 -> V_14 , sizeof( struct V_28 ) , V_16 ) ;
if ( ! V_29 )
return - V_17 ;
V_60 = V_57 ? V_57 -> V_29 : F_32 ( V_11 ) ;
V_29 -> V_14 = & V_11 -> V_14 ;
V_29 -> V_2 = V_2 ;
F_33 ( V_29 -> V_55 , V_60 -> V_55 , sizeof( V_29 -> V_55 ) ) ;
switch ( V_60 -> V_61 ) {
case V_62 :
V_29 -> V_43 = V_63 ;
V_29 -> V_44 = F_34 ( V_63 ) ;
break;
case V_64 :
V_29 -> V_43 = V_65 ;
V_29 -> V_44 = F_34 ( V_65 ) ;
break;
case V_66 :
V_29 -> V_43 = V_67 ;
V_29 -> V_44 = F_34 ( V_67 ) ;
break;
default:
F_30 ( & V_11 -> V_14 , L_13 ,
V_60 -> V_61 , V_60 -> V_55 ) ;
return - V_50 ;
}
F_35 ( V_11 , V_29 ) ;
V_8 = F_36 ( & V_29 -> V_14 -> V_68 , & V_69 ) ;
if ( V_8 ) {
F_30 ( V_29 -> V_14 , L_14 ) ;
return V_8 ;
}
V_29 -> V_70 = F_37 ( V_29 -> V_14 ) ;
if ( F_8 ( V_29 -> V_70 ) ) {
F_30 ( V_29 -> V_14 , L_15 ) ;
V_8 = F_28 ( V_29 -> V_70 ) ;
goto V_71;
}
F_38 ( & V_11 -> V_14 , L_16 ,
V_60 -> V_55 ) ;
V_29 -> V_72 = F_39 ( V_29 -> V_14 , 0 , V_29 -> V_14 ,
F_20 , NULL ) ;
if ( F_8 ( V_29 -> V_72 ) ) {
F_40 ( & V_11 -> V_14 , L_17 ) ;
V_29 -> V_72 = NULL ;
}
return 0 ;
V_71:
F_41 ( & V_29 -> V_14 -> V_68 , & V_69 ) ;
F_12 ( V_2 ) ;
return V_8 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_28 * V_29 = F_43 ( V_11 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
F_44 ( V_29 -> V_70 ) ;
F_41 ( & V_29 -> V_14 -> V_68 , & V_69 ) ;
F_12 ( V_2 ) ;
F_45 ( V_29 -> V_14 , V_29 -> V_72 ) ;
return 0 ;
}
