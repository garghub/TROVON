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
V_13 = F_6 ( V_11 , V_18 ,
V_19 ,
V_19 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 , V_18 ,
V_20 ,
V_20 ) ;
if ( ! V_13 )
V_13 = F_6 ( V_11 , V_18 ,
V_21 ,
V_21 ) ;
if ( V_13 < 0 ) {
F_7 ( V_11 -> V_17 , L_2 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_8 ( struct V_22 * V_23 , unsigned int V_24 )
{
if ( ( V_24 & V_25 ) != V_26 ) {
F_7 ( V_23 -> V_11 -> V_17 ,
L_3 ,
V_27 , V_24 & V_25 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_23 , int V_29 , int V_30 )
{
struct V_10 * V_11 = V_23 -> V_11 ;
if ( V_29 ) {
return F_6 ( V_11 , V_18 ,
V_21 ,
V_21 ) ;
} else {
return F_6 ( V_11 , V_18 ,
V_21 ,
0 ) ;
}
}
static int F_10 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
if ( ( V_24 & V_25 ) != V_26 ) {
F_7 ( V_23 -> V_11 -> V_17 ,
L_3 ,
V_27 , V_24 & V_25 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_11 ( struct V_31 * V_32 , int V_33 ,
struct V_22 * V_23 )
{
struct V_10 * V_11 = V_23 -> V_11 ;
switch ( V_33 ) {
case V_34 :
case V_35 :
return F_6 ( V_11 , V_14 ,
V_15 ,
V_15 ) ;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
return F_6 ( V_11 , V_14 ,
V_15 ,
0 ) ;
default:
return - V_28 ;
}
}
static bool F_12 ( struct V_40 * V_17 , unsigned int V_2 )
{
if ( V_2 == V_14 )
return true ;
return false ;
}
static int F_13 ( struct V_22 * V_23 , int V_41 ,
unsigned int V_42 , int V_43 )
{
struct V_10 * V_11 = V_23 -> V_11 ;
struct V_4 * V_5 = F_14 ( V_11 -> V_17 ) ;
if ( V_43 == V_44 )
return 0 ;
if ( V_41 != 0 )
return - V_28 ;
switch ( V_23 -> V_45 ) {
case V_46 :
V_5 -> V_47 . V_48 = V_42 ;
break;
case V_49 :
V_5 -> V_8 . V_48 = V_42 ;
break;
}
return 0 ;
}
static int F_15 ( struct V_31 * V_32 ,
struct V_22 * V_23 )
{
struct V_10 * V_11 = V_23 -> V_11 ;
struct V_4 * V_5 = F_14 ( V_11 -> V_17 ) ;
struct V_50 * V_51 = V_32 -> V_51 ;
switch ( V_23 -> V_45 ) {
case V_46 :
if ( ( V_5 -> V_47 . V_48 / V_51 -> V_52 ) != 128 ) {
F_7 ( V_11 -> V_17 , L_4 ) ;
return - V_28 ;
}
break;
case V_49 :
if ( ( V_5 -> V_8 . V_48 / V_51 -> V_52 ) != 256 ) {
F_7 ( V_11 -> V_17 , L_4 ) ;
return - V_28 ;
}
break;
}
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_14 ( V_11 -> V_17 ) ;
return F_5 ( V_11 , V_5 ) ;
}
static int F_17 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_14 ( V_11 -> V_17 ) ;
int V_13 ;
V_13 = F_5 ( V_11 , V_5 ) ;
return V_13 ;
}
static int F_18 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_17 . V_57 ;
struct V_4 * V_5 ;
const struct V_58 * V_59 ;
V_5 = F_19 ( & V_54 -> V_17 , sizeof( struct V_4 ) ,
V_60 ) ;
if ( ! V_5 )
return - V_61 ;
V_59 = F_20 ( V_62 , V_56 ) ;
if ( ! V_59 -> V_12 ) {
F_7 ( & V_54 -> V_17 , L_5 ) ;
return - V_28 ;
}
V_5 -> V_63 = (struct V_64 * ) V_59 -> V_12 ;
V_5 -> V_17 = & V_54 -> V_17 ;
V_5 -> V_8 . V_65 = F_21 ( & V_54 -> V_17 , NULL , V_5 ,
V_5 -> V_63 -> V_9 ) ;
if ( F_22 ( V_5 -> V_8 . V_65 ) ) {
F_7 ( & V_54 -> V_17 , L_6 ) ;
return F_23 ( V_5 -> V_8 . V_65 ) ;
}
V_5 -> V_8 . V_9 =
F_24 ( V_56 , L_7 ) ;
if ( F_22 ( V_5 -> V_8 . V_9 ) ) {
F_7 ( & V_54 -> V_17 , L_8 ) ;
return F_23 ( V_5 -> V_8 . V_9 ) ;
}
V_5 -> V_47 . V_9 = V_5 -> V_8 . V_9 ;
V_66 [ V_49 ] . V_67 = V_5 -> V_63 -> V_68 ;
V_69 . V_70 . V_71 = V_5 -> V_63 -> V_71 ;
V_69 . V_70 . V_72 = V_5 -> V_63 -> V_72 ;
V_69 . V_70 . V_73 = V_5 -> V_63 -> V_73 ;
V_69 . V_70 . V_74 = V_5 -> V_63 -> V_74 ;
F_25 ( & V_54 -> V_17 , V_5 ) ;
return F_26 ( & V_54 -> V_17 , & V_69 ,
V_66 ,
F_27 ( V_66 ) ) ;
}
static int F_28 ( struct V_53 * V_54 )
{
F_29 ( & V_54 -> V_17 ) ;
return 0 ;
}
