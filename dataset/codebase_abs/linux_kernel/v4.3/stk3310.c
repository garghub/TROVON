static int F_1 ( const int V_1 [] [ 2 ] , int V_2 ,
int V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
if ( V_3 == V_1 [ V_5 ] [ 0 ] && V_4 == V_1 [ V_5 ] [ 1 ] )
return V_5 ;
}
return - V_6 ;
}
static int F_2 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
enum V_11 type ,
enum V_12 V_13 ,
enum V_14 V_15 ,
int * V_3 , int * V_4 )
{
T_1 V_16 ;
T_2 V_17 ;
int V_18 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
if ( V_15 != V_21 )
return - V_6 ;
if ( V_13 == V_22 )
V_16 = V_23 ;
else if ( V_13 == V_24 )
V_16 = V_25 ;
else
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
V_18 = F_5 ( V_20 -> V_27 , V_16 , & V_17 , 2 ) ;
F_6 ( & V_20 -> V_26 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_20 -> V_28 -> V_29 , L_1 ) ;
return V_18 ;
}
* V_3 = F_8 ( V_17 ) ;
return V_30 ;
}
static int F_9 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
enum V_11 type ,
enum V_12 V_13 ,
enum V_14 V_15 ,
int V_3 , int V_4 )
{
T_1 V_16 ;
T_2 V_17 ;
int V_18 ;
unsigned int V_31 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
struct V_32 * V_28 = V_20 -> V_28 ;
F_10 ( V_20 -> V_33 , & V_31 ) ;
if ( V_3 > V_34 [ V_31 ] )
return - V_6 ;
if ( V_13 == V_22 )
V_16 = V_23 ;
else if ( V_13 == V_24 )
V_16 = V_25 ;
else
return - V_6 ;
V_17 = F_11 ( V_3 ) ;
V_18 = F_12 ( V_20 -> V_27 , V_16 , & V_17 , 2 ) ;
if ( V_18 < 0 )
F_7 ( & V_28 -> V_29 , L_2 ) ;
return V_18 ;
}
static int F_13 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
enum V_11 type ,
enum V_12 V_13 )
{
unsigned int V_35 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
F_10 ( V_20 -> V_36 , & V_35 ) ;
return V_35 ;
}
static int F_14 ( struct V_7 * V_8 ,
const struct V_9 * V_10 ,
enum V_11 type ,
enum V_12 V_13 ,
int V_37 )
{
int V_18 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
struct V_32 * V_28 = V_20 -> V_28 ;
if ( V_37 < 0 || V_37 > 7 )
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
V_18 = F_15 ( V_20 -> V_36 , V_37 ) ;
if ( V_18 < 0 )
F_7 ( & V_28 -> V_29 , L_3 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_3 , int * V_4 , long V_38 )
{
T_1 V_16 ;
T_2 V_17 ;
int V_18 ;
unsigned int V_31 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
struct V_32 * V_28 = V_20 -> V_28 ;
switch ( V_38 ) {
case V_39 :
if ( V_10 -> type == V_40 )
V_16 = V_41 ;
else if ( V_10 -> type == V_42 )
V_16 = V_43 ;
else
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
V_18 = F_5 ( V_20 -> V_27 , V_16 , & V_17 , 2 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_28 -> V_29 , L_1 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
}
* V_3 = F_8 ( V_17 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_30 ;
case V_44 :
if ( V_10 -> type == V_40 )
F_10 ( V_20 -> V_45 , & V_31 ) ;
else
F_10 ( V_20 -> V_46 , & V_31 ) ;
* V_3 = V_47 [ V_31 ] [ 0 ] ;
* V_4 = V_47 [ V_31 ] [ 1 ] ;
return V_48 ;
case V_49 :
if ( V_10 -> type == V_40 )
F_10 ( V_20 -> V_50 , & V_31 ) ;
else
F_10 ( V_20 -> V_33 , & V_31 ) ;
* V_3 = V_51 [ V_31 ] [ 0 ] ;
* V_4 = V_51 [ V_31 ] [ 1 ] ;
return V_48 ;
}
return - V_6 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int V_3 , int V_4 , long V_38 )
{
int V_18 ;
int V_31 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
switch ( V_38 ) {
case V_44 :
V_31 = F_1 ( V_47 ,
F_18 ( V_47 ) ,
V_3 , V_4 ) ;
if ( V_31 < 0 )
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
if ( V_10 -> type == V_40 )
V_18 = F_15 ( V_20 -> V_45 , V_31 ) ;
else
V_18 = F_15 ( V_20 -> V_46 , V_31 ) ;
if ( V_18 < 0 )
F_7 ( & V_20 -> V_28 -> V_29 ,
L_4 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
case V_49 :
V_31 = F_1 ( V_51 ,
F_18 ( V_51 ) ,
V_3 , V_4 ) ;
if ( V_31 < 0 )
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
if ( V_10 -> type == V_40 )
V_18 = F_15 ( V_20 -> V_50 , V_31 ) ;
else
V_18 = F_15 ( V_20 -> V_33 , V_31 ) ;
if ( V_18 < 0 )
F_7 ( & V_20 -> V_28 -> V_29 ,
L_4 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
}
return - V_6 ;
}
static int F_19 ( struct V_19 * V_20 , T_1 V_37 )
{
int V_18 ;
struct V_32 * V_28 = V_20 -> V_28 ;
if ( V_37 > 7 || V_37 == 4 )
return - V_6 ;
F_4 ( & V_20 -> V_26 ) ;
V_18 = F_15 ( V_20 -> V_52 , V_37 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_28 -> V_29 , L_5 ) ;
} else if ( V_37 != V_53 ) {
V_20 -> V_54 = ! ! ( V_37 & 0x01 ) ;
V_20 -> V_55 = ! ! ( V_37 & 0x02 ) ;
}
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
}
static int F_20 ( struct V_7 * V_8 )
{
int V_18 ;
int V_56 ;
T_1 V_37 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
struct V_32 * V_28 = V_20 -> V_28 ;
F_21 ( V_20 -> V_27 , V_57 , & V_56 ) ;
if ( V_56 != V_58 &&
V_56 != V_59 ) {
F_7 ( & V_28 -> V_29 , L_6 , V_56 ) ;
return - V_60 ;
}
V_37 = V_61 | V_62 ;
V_18 = F_19 ( V_20 , V_37 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_28 -> V_29 , L_7 ) ;
return V_18 ;
}
V_18 = F_15 ( V_20 -> V_36 , V_63 ) ;
if ( V_18 < 0 )
F_7 ( & V_28 -> V_29 , L_8 ) ;
return V_18 ;
}
static int F_22 ( struct V_32 * V_28 )
{
struct V_64 * V_29 ;
struct V_65 * V_66 ;
int V_18 ;
if ( ! V_28 )
return - V_6 ;
V_29 = & V_28 -> V_29 ;
V_66 = F_23 ( V_29 , V_67 , 0 , V_68 ) ;
if ( F_24 ( V_66 ) ) {
F_7 ( V_29 , L_9 ) ;
return F_25 ( V_66 ) ;
}
V_18 = F_26 ( V_66 ) ;
F_27 ( V_29 , L_10 , F_28 ( V_66 ) , V_18 ) ;
return V_18 ;
}
static bool F_29 ( struct V_64 * V_29 , unsigned int V_16 )
{
switch ( V_16 ) {
case V_41 :
case V_69 :
case V_70 :
case V_43 :
case V_71 :
return true ;
default:
return false ;
}
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_27 * V_27 ;
struct V_32 * V_28 ;
V_28 = V_20 -> V_28 ;
V_27 = F_31 ( V_28 , & V_72 ) ;
if ( F_24 ( V_27 ) ) {
F_7 ( & V_28 -> V_29 , L_11 ) ;
return F_25 ( V_27 ) ;
}
V_20 -> V_27 = V_27 ;
F_32 ( V_37 ) ;
F_32 ( V_73 ) ;
F_32 ( V_74 ) ;
F_32 ( V_75 ) ;
F_32 ( V_76 ) ;
F_32 ( V_77 ) ;
F_32 ( V_78 ) ;
F_32 ( V_79 ) ;
return 0 ;
}
static T_3 F_33 ( int V_80 , void * V_81 )
{
struct V_7 * V_8 = V_81 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
V_20 -> V_82 = F_34 () ;
return V_83 ;
}
static T_3 F_35 ( int V_80 , void * V_81 )
{
int V_18 ;
unsigned int V_13 ;
T_4 V_84 ;
struct V_7 * V_8 = V_81 ;
struct V_19 * V_20 = F_3 ( V_8 ) ;
F_4 ( & V_20 -> V_26 ) ;
V_18 = F_10 ( V_20 -> V_85 , & V_13 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_20 -> V_28 -> V_29 , L_1 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_18 ;
}
V_84 = F_36 ( V_42 , 1 ,
V_86 ,
( V_13 ? V_24 :
V_22 ) ) ;
F_37 ( V_8 , V_84 , V_20 -> V_82 ) ;
V_18 = F_15 ( V_20 -> V_87 , 0 ) ;
if ( V_18 < 0 )
F_7 ( & V_20 -> V_28 -> V_29 , L_12 ) ;
F_6 ( & V_20 -> V_26 ) ;
return V_88 ;
}
static int F_38 ( struct V_32 * V_28 ,
const struct V_89 * V_90 )
{
int V_18 ;
struct V_7 * V_8 ;
struct V_19 * V_20 ;
V_8 = F_39 ( & V_28 -> V_29 , sizeof( * V_20 ) ) ;
if ( ! V_8 ) {
F_7 ( & V_28 -> V_29 , L_13 ) ;
return - V_91 ;
}
V_20 = F_3 ( V_8 ) ;
V_20 -> V_28 = V_28 ;
F_40 ( V_28 , V_8 ) ;
F_41 ( & V_20 -> V_26 ) ;
V_18 = F_30 ( V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 -> V_29 . V_92 = & V_28 -> V_29 ;
V_8 -> V_15 = & V_93 ;
V_8 -> V_94 = V_95 ;
V_8 -> V_96 = V_97 ;
V_8 -> V_98 = V_99 ;
V_8 -> V_100 = F_18 ( V_99 ) ;
V_18 = F_20 ( V_8 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_28 -> V_80 < 0 )
V_28 -> V_80 = F_22 ( V_28 ) ;
if ( V_28 -> V_80 >= 0 ) {
V_18 = F_42 ( & V_28 -> V_29 , V_28 -> V_80 ,
F_33 ,
F_35 ,
V_101 |
V_102 ,
V_103 , V_8 ) ;
if ( V_18 < 0 )
F_7 ( & V_28 -> V_29 , L_14 ,
V_28 -> V_80 ) ;
}
V_18 = F_43 ( V_8 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_28 -> V_29 , L_15 ) ;
F_19 ( V_20 , V_53 ) ;
}
return V_18 ;
}
static int F_44 ( struct V_32 * V_28 )
{
struct V_7 * V_8 = F_45 ( V_28 ) ;
F_46 ( V_8 ) ;
return F_19 ( F_3 ( V_8 ) , V_53 ) ;
}
static int F_47 ( struct V_64 * V_29 )
{
struct V_19 * V_20 ;
V_20 = F_3 ( F_45 ( F_48 ( V_29 ) ) ) ;
return F_19 ( V_20 , V_53 ) ;
}
static int F_49 ( struct V_64 * V_29 )
{
int V_37 = 0 ;
struct V_19 * V_20 ;
V_20 = F_3 ( F_45 ( F_48 ( V_29 ) ) ) ;
if ( V_20 -> V_54 )
V_37 |= V_62 ;
if ( V_20 -> V_55 )
V_37 |= V_61 ;
return F_19 ( V_20 , V_37 ) ;
}
