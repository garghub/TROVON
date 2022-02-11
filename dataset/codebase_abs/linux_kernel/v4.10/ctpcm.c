static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 ;
if ( ! V_3 -> V_4 )
return;
F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_3 = V_6 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_3 -> V_4 ) ;
V_9 -> V_10 ( V_9 , V_3 ) ;
F_5 ( V_3 -> V_11 ) ;
F_6 ( V_3 ) ;
V_6 -> V_7 = NULL ;
}
static int F_7 ( struct V_12 * V_4 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 ;
int V_13 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_14 ) ;
if ( ! V_3 )
return - V_15 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_16 = F_1 ;
if ( V_17 == V_4 -> V_18 -> V_19 ) {
V_6 -> V_20 = V_21 ;
V_9 -> V_22 ( V_9 , 1 ) ;
} else {
V_6 -> V_20 = V_23 ;
if ( V_24 == V_4 -> V_18 -> V_19 )
V_6 -> V_20 . V_25 = 8 ;
}
V_13 = F_9 ( V_6 ,
V_26 ) ;
if ( V_13 < 0 ) {
F_6 ( V_3 ) ;
return V_13 ;
}
V_13 = F_10 ( V_6 ,
V_27 ,
1024 , V_28 ) ;
if ( V_13 < 0 ) {
F_6 ( V_3 ) ;
return V_13 ;
}
V_3 -> V_11 = F_11 ( V_9 -> V_11 , V_3 ) ;
if ( ! V_3 -> V_11 ) {
F_6 ( V_3 ) ;
return - V_15 ;
}
V_6 -> V_7 = V_3 ;
V_6 -> V_29 = F_3 ;
return 0 ;
}
static int F_12 ( struct V_12 * V_4 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
if ( V_17 == V_4 -> V_18 -> V_19 )
V_9 -> V_22 ( V_9 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_4 ,
struct V_30 * V_31 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_1 * V_3 = V_4 -> V_6 -> V_7 ;
int V_13 ;
V_13 = F_14 ( V_4 ,
F_15 ( V_31 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_9 -> V_10 ( V_9 , V_3 ) ;
return V_13 ;
}
static int F_16 ( struct V_12 * V_4 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_1 * V_3 = V_4 -> V_6 -> V_7 ;
V_9 -> V_10 ( V_9 , V_3 ) ;
return F_17 ( V_4 ) ;
}
static int F_18 ( struct V_12 * V_4 )
{
int V_13 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
if ( V_17 == V_4 -> V_18 -> V_19 )
V_13 = V_9 -> V_32 ( V_9 , V_3 ) ;
else
V_13 = V_9 -> V_33 ( V_9 , V_3 ) ;
if ( V_13 < 0 ) {
F_19 ( V_9 -> V_34 -> V_35 ,
L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int
F_20 ( struct V_12 * V_4 , int V_36 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
V_9 -> V_40 ( V_9 , V_3 ) ;
break;
case V_41 :
case V_42 :
case V_43 :
V_9 -> V_44 ( V_9 , V_3 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1
F_21 ( struct V_12 * V_4 )
{
unsigned long V_45 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
V_45 = V_9 -> V_46 ( V_9 , V_3 ) ;
V_45 = F_22 ( V_6 , V_45 ) ;
if ( V_45 >= V_6 -> V_47 )
V_45 = 0 ;
return V_45 ;
}
static int F_23 ( struct V_12 * V_4 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 ;
int V_13 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_14 ) ;
if ( ! V_3 )
return - V_15 ;
V_3 -> V_48 = 0 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_16 = F_1 ;
V_6 -> V_20 = V_49 ;
V_6 -> V_20 . V_50 = V_9 -> V_51 * V_9 -> V_52 ;
V_13 = F_9 ( V_6 ,
V_26 ) ;
if ( V_13 < 0 ) {
F_6 ( V_3 ) ;
return V_13 ;
}
V_13 = F_10 ( V_6 ,
V_27 ,
1024 , V_28 ) ;
if ( V_13 < 0 ) {
F_6 ( V_3 ) ;
return V_13 ;
}
V_3 -> V_11 = F_11 ( V_9 -> V_11 , V_3 ) ;
if ( ! V_3 -> V_11 ) {
F_6 ( V_3 ) ;
return - V_15 ;
}
V_6 -> V_7 = V_3 ;
V_6 -> V_29 = F_3 ;
return 0 ;
}
static int F_24 ( struct V_12 * V_4 )
{
return 0 ;
}
static int F_25 ( struct V_12 * V_4 )
{
int V_13 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
V_13 = V_9 -> V_53 ( V_9 , V_3 ) ;
if ( V_13 < 0 ) {
F_19 ( V_9 -> V_34 -> V_35 ,
L_2 ) ;
return V_13 ;
}
return 0 ;
}
static int
F_26 ( struct V_12 * V_4 , int V_36 )
{
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
switch ( V_36 ) {
case V_37 :
V_9 -> V_54 ( V_9 , V_3 ) ;
break;
case V_41 :
V_9 -> V_55 ( V_9 , V_3 ) ;
break;
default:
V_9 -> V_55 ( V_9 , V_3 ) ;
break;
}
return 0 ;
}
static T_1
F_27 ( struct V_12 * V_4 )
{
unsigned long V_45 ;
struct V_8 * V_9 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_3 = V_6 -> V_7 ;
V_45 = V_9 -> V_56 ( V_9 , V_3 ) ;
V_45 = F_22 ( V_6 , V_45 ) ;
if ( V_45 >= V_6 -> V_47 )
V_45 = 0 ;
return V_45 ;
}
int F_28 ( struct V_8 * V_9 ,
enum V_57 V_19 ,
const char * V_58 )
{
struct V_59 * V_18 ;
const struct V_60 * V_61 ;
int V_62 ;
int V_13 ;
int V_63 , V_64 ;
V_63 = ( V_17 == V_19 ) ? 1 : 256 ;
V_64 = ( V_24 == V_19 ) ? 1 : 0 ;
V_13 = F_29 ( V_9 -> V_34 , L_3 , V_19 ,
V_63 , V_64 , & V_18 ) ;
if ( V_13 < 0 ) {
F_19 ( V_9 -> V_34 -> V_35 , L_4 ,
V_13 ) ;
return V_13 ;
}
V_18 -> V_7 = V_9 ;
V_18 -> V_65 = 0 ;
V_18 -> V_66 = V_67 ;
F_30 ( V_18 -> V_68 , V_58 , sizeof( V_18 -> V_68 ) ) ;
F_31 ( V_18 , V_69 , & V_70 ) ;
if ( V_24 == V_19 )
F_31 ( V_18 ,
V_71 , & V_72 ) ;
F_32 ( V_18 , V_73 ,
F_33 ( V_9 -> V_74 ) , 128 * 1024 , 128 * 1024 ) ;
V_62 = 2 ;
switch ( V_19 ) {
case V_24 :
V_62 = 8 ;
V_61 = V_75 ;
break;
case V_76 :
V_61 = V_77 ;
break;
case V_78 :
V_61 = V_79 ;
break;
case V_80 :
V_61 = V_81 ;
break;
default:
V_61 = V_75 ;
break;
}
V_13 = F_34 ( V_18 , V_69 , V_61 , V_62 ,
0 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
#ifdef F_35
V_9 -> V_82 [ V_19 ] = V_18 ;
#endif
return 0 ;
}
