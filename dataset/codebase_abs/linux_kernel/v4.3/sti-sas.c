static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 ;
T_1 V_7 ;
V_6 = F_2 ( V_5 -> V_8 . V_9 , V_2 , & V_7 ) ;
* V_3 = ( unsigned int ) V_7 ;
return V_6 ;
}
static int F_3 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 ;
V_6 = F_4 ( V_5 -> V_8 . V_9 , V_2 , V_3 ) ;
return V_6 ;
}
static int F_5 ( struct V_10 * V_11 ,
struct V_4 * V_12 )
{
int V_13 ;
V_13 = F_6 ( V_11 , V_14 ,
V_15 , 0 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 , V_14 ,
V_16 , 0 ) ;
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_17 , L_1 ) ;
return V_13 ;
}
switch ( V_12 -> V_18 -> V_19 ) {
case V_20 :
V_13 = F_6 ( V_11 , V_21 ,
V_22 ,
V_22 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 , V_21 ,
V_23 ,
V_23 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 , V_21 ,
V_24 ,
V_24 ) ;
break;
case V_25 :
V_13 = F_6 ( V_11 , V_26 ,
V_27 , 0 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 ,
V_26 ,
V_28 , 0 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 ,
V_26 ,
V_29 ,
0 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 ,
V_26 ,
V_30 ,
V_30 ) ;
break;
default:
return - V_31 ;
}
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_17 , L_2 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_8 ( struct V_32 * V_33 , unsigned int V_34 )
{
if ( ( V_34 & V_35 ) != V_36 ) {
F_7 ( V_33 -> V_11 -> V_17 ,
L_3 ,
V_37 , V_34 & V_35 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_9 ( struct V_32 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_4 * V_5 = F_10 ( V_11 -> V_17 ) ;
struct V_38 * V_8 = & V_5 -> V_8 ;
V_8 -> V_39 = F_11 ( V_11 -> V_17 , L_4 ) ;
if ( F_12 ( V_8 -> V_39 ) ) {
F_7 ( V_33 -> V_11 -> V_17 ,
L_5 ,
V_37 ) ;
V_8 -> V_39 = NULL ;
return - V_40 ;
}
F_13 ( V_8 -> V_39 ) ;
return 0 ;
}
static int F_14 ( struct V_32 * V_33 , int V_41 , int V_42 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
if ( V_41 ) {
return F_6 ( V_11 , V_26 ,
V_30 ,
V_30 ) ;
} else {
return F_6 ( V_11 , V_26 ,
V_30 , 0 ) ;
}
}
static int F_15 ( struct V_32 * V_33 , int V_41 , int V_42 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
if ( V_41 ) {
return F_6 ( V_11 , V_21 ,
V_24 ,
V_24 ) ;
} else {
return F_6 ( V_11 , V_21 ,
V_24 ,
0 ) ;
}
}
static int F_16 ( struct V_32 * V_33 ,
unsigned int V_34 )
{
if ( ( V_34 & V_35 ) != V_36 ) {
F_7 ( V_33 -> V_11 -> V_17 ,
L_3 ,
V_37 , V_34 & V_35 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_17 ( struct V_43 * V_44 , int V_45 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
switch ( V_45 ) {
case V_46 :
case V_47 :
return F_6 ( V_11 , V_14 ,
V_15 ,
V_15 ) ;
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return F_6 ( V_11 , V_14 ,
V_15 ,
0 ) ;
default:
return - V_31 ;
}
}
static bool F_18 ( struct V_52 * V_17 , unsigned int V_2 )
{
if ( V_2 == V_14 )
return true ;
return false ;
}
static int F_19 ( struct V_32 * V_33 , int V_53 ,
unsigned int V_54 , int V_55 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_4 * V_5 = F_10 ( V_11 -> V_17 ) ;
if ( V_55 == V_56 )
return 0 ;
if ( V_53 != 0 )
return - V_31 ;
switch ( V_33 -> V_57 ) {
case V_58 :
V_5 -> V_59 . V_60 = V_54 ;
break;
case V_61 :
V_5 -> V_8 . V_60 = V_54 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = V_33 -> V_11 ;
struct V_4 * V_5 = F_10 ( V_11 -> V_17 ) ;
struct V_62 * V_63 = V_44 -> V_63 ;
switch ( V_33 -> V_57 ) {
case V_58 :
if ( ( V_5 -> V_59 . V_60 / V_63 -> V_64 ) != 128 ) {
F_7 ( V_11 -> V_17 , L_6 ) ;
return - V_31 ;
}
break;
case V_61 :
if ( ( V_5 -> V_8 . V_60 / V_63 -> V_64 ) != 256 ) {
F_7 ( V_11 -> V_17 , L_6 ) ;
return - V_31 ;
}
break;
}
return 0 ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_10 ( V_11 -> V_17 ) ;
return F_5 ( V_11 , V_5 ) ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_10 ( V_11 -> V_17 ) ;
int V_13 ;
V_13 = F_5 ( V_11 , V_5 ) ;
return V_13 ;
}
static int F_23 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_17 . V_69 ;
struct V_4 * V_5 ;
const struct V_70 * V_71 ;
V_5 = F_24 ( & V_66 -> V_17 , sizeof( struct V_4 ) ,
V_72 ) ;
if ( ! V_5 )
return - V_73 ;
V_71 = F_25 ( V_74 , V_68 ) ;
if ( ! V_71 -> V_12 ) {
F_7 ( & V_66 -> V_17 , L_7 ) ;
return - V_31 ;
}
V_5 -> V_18 = (struct V_75 * ) V_71 -> V_12 ;
V_5 -> V_17 = & V_66 -> V_17 ;
V_5 -> V_8 . V_76 = F_26 ( & V_66 -> V_17 , NULL , V_5 ,
V_5 -> V_18 -> V_9 ) ;
if ( F_12 ( V_5 -> V_8 . V_76 ) ) {
F_7 ( & V_66 -> V_17 , L_8 ) ;
return F_27 ( V_5 -> V_8 . V_76 ) ;
}
V_5 -> V_8 . V_9 =
F_28 ( V_68 , L_9 ) ;
if ( F_12 ( V_5 -> V_8 . V_9 ) ) {
F_7 ( & V_66 -> V_17 , L_10 ) ;
return F_27 ( V_5 -> V_8 . V_9 ) ;
}
V_5 -> V_59 . V_9 = V_5 -> V_8 . V_9 ;
if ( V_5 -> V_18 -> V_19 == V_25 )
V_77 [ V_61 ] . V_78 = F_9 ;
V_77 [ V_61 ] . V_79 = V_5 -> V_18 -> V_80 ;
V_81 . V_82 = V_5 -> V_18 -> V_82 ;
V_81 . V_83 = V_5 -> V_18 -> V_83 ;
V_81 . V_84 = V_5 -> V_18 -> V_84 ;
V_81 . V_85 = V_5 -> V_18 -> V_85 ;
F_29 ( & V_66 -> V_17 , V_5 ) ;
return F_30 ( & V_66 -> V_17 , & V_81 ,
V_77 ,
F_31 ( V_77 ) ) ;
}
static int F_32 ( struct V_65 * V_66 )
{
F_33 ( & V_66 -> V_17 ) ;
return 0 ;
}
