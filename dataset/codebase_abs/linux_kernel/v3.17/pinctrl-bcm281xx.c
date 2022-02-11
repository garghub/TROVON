static inline enum V_1 F_1 ( struct V_2 * V_3 ,
unsigned V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( V_4 >= V_6 -> V_7 )
return V_8 ;
return * (enum V_1 * ) ( V_6 -> V_9 [ V_4 ] . V_10 ) ;
}
static inline void F_3 ( T_1 * V_11 , T_1 * V_12 ,
T_1 V_13 , T_1 V_14 ,
T_1 V_15 )
{
* V_11 &= ~ V_15 ;
* V_11 |= ( V_13 << V_14 ) & V_15 ;
* V_12 |= V_15 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_7 ;
}
static const char * F_5 ( struct V_2 * V_3 ,
unsigned V_16 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_9 [ V_16 ] . V_17 ;
}
static int F_6 ( struct V_2 * V_3 ,
unsigned V_16 ,
const unsigned * * V_9 ,
unsigned * V_18 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
* V_9 = & V_6 -> V_9 [ V_16 ] . V_19 ;
* V_18 = 1 ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
unsigned V_22 )
{
F_8 ( V_21 , L_1 , F_9 ( V_3 -> V_23 ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_24 ;
}
static const char * F_11 ( struct V_2 * V_3 ,
unsigned V_25 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
return V_6 -> V_26 [ V_25 ] . V_17 ;
}
static int F_12 ( struct V_2 * V_3 ,
unsigned V_25 ,
const char * const * * V_27 ,
unsigned * const V_28 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
* V_27 = V_6 -> V_26 [ V_25 ] . V_27 ;
* V_28 = V_6 -> V_26 [ V_25 ] . V_29 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
unsigned V_25 ,
unsigned V_16 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
const struct V_30 * V_31 = & V_6 -> V_26 [ V_25 ] ;
T_1 V_22 = 4 * V_6 -> V_9 [ V_16 ] . V_19 ;
int V_32 = 0 ;
F_14 ( V_3 -> V_23 ,
L_2 ,
V_33 , V_31 -> V_17 , V_25 , V_6 -> V_9 [ V_16 ] . V_17 ,
V_6 -> V_9 [ V_16 ] . V_19 , V_22 ) ;
V_32 = F_15 ( V_6 -> V_34 , V_22 ,
V_35 ,
V_25 << V_36 ) ;
if ( V_32 )
F_16 ( V_3 -> V_23 ,
L_3 ,
V_6 -> V_9 [ V_16 ] . V_17 , V_6 -> V_9 [ V_16 ] . V_19 ) ;
return V_32 ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_37 )
{
return - V_38 ;
}
static int F_18 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_39 ,
unsigned V_40 ,
T_1 * V_41 ,
T_1 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_43 ;
enum V_44 V_45 ;
T_2 V_46 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
V_45 = F_19 ( V_39 [ V_43 ] ) ;
V_46 = F_20 ( V_39 [ V_43 ] ) ;
switch ( V_45 ) {
case V_47 :
V_46 = ( V_46 >= 1 ? 1 : 0 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_48 , V_49 ) ,
F_22 ( V_48 , V_49 ) ) ;
break;
case V_50 :
F_3 ( V_41 , V_42 , 0 ,
F_21 ( V_48 , V_51 ) ,
F_22 ( V_48 , V_51 ) ) ;
F_3 ( V_41 , V_42 , 0 ,
F_21 ( V_48 , V_52 ) ,
F_22 ( V_48 , V_52 ) ) ;
break;
case V_53 :
F_3 ( V_41 , V_42 , 1 ,
F_21 ( V_48 , V_51 ) ,
F_22 ( V_48 , V_51 ) ) ;
F_3 ( V_41 , V_42 , 0 ,
F_21 ( V_48 , V_52 ) ,
F_22 ( V_48 , V_52 ) ) ;
break;
case V_54 :
F_3 ( V_41 , V_42 , 0 ,
F_21 ( V_48 , V_51 ) ,
F_22 ( V_48 , V_51 ) ) ;
F_3 ( V_41 , V_42 , 1 ,
F_21 ( V_48 , V_52 ) ,
F_22 ( V_48 , V_52 ) ) ;
break;
case V_55 :
V_46 = ( V_46 >= 1 ? 1 : 0 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_48 , V_56 ) ,
F_22 ( V_48 , V_56 ) ) ;
break;
case V_57 :
V_46 = ( V_46 >= 1 ? 0 : 1 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_48 , V_58 ) ,
F_22 ( V_48 , V_58 ) ) ;
break;
case V_59 :
if ( ( V_46 < 2 ) || ( V_46 > 16 ) || ( V_46 % 2 ) ) {
F_16 ( V_3 -> V_23 ,
L_4
L_5
L_6 ,
V_46 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
F_3 ( V_41 , V_42 , ( V_46 / 2 ) - 1 ,
F_21 ( V_48 , V_61 ) ,
F_22 ( V_48 , V_61 ) ) ;
break;
default:
F_16 ( V_3 -> V_23 ,
L_7 ,
V_45 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_39 ,
unsigned V_40 ,
T_1 * V_41 ,
T_1 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_43 , V_62 ;
enum V_44 V_45 ;
T_2 V_46 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
V_45 = F_19 ( V_39 [ V_43 ] ) ;
V_46 = F_20 ( V_39 [ V_43 ] ) ;
switch ( V_45 ) {
case V_53 :
for ( V_62 = 0 ; V_62 < F_24 ( V_63 ) ; V_62 ++ )
if ( V_63 [ V_62 ] == V_46 )
break;
if ( V_62 == F_24 ( V_63 ) ) {
F_16 ( V_3 -> V_23 ,
L_8
L_9
L_10 ,
V_46 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
F_3 ( V_41 , V_42 , V_62 + 1 ,
F_21 ( V_64 , V_65 ) ,
F_22 ( V_64 , V_65 ) ) ;
break;
case V_50 :
F_3 ( V_41 , V_42 , 0 ,
F_21 ( V_64 , V_65 ) ,
F_22 ( V_64 , V_65 ) ) ;
break;
case V_55 :
V_46 = ( V_46 >= 1 ? 1 : 0 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_64 , V_56 ) ,
F_22 ( V_64 , V_56 ) ) ;
break;
case V_57 :
V_46 = ( V_46 >= 1 ? 0 : 1 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_64 , V_58 ) ,
F_22 ( V_64 , V_58 ) ) ;
break;
default:
F_16 ( V_3 -> V_23 ,
L_7 ,
V_45 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_39 ,
unsigned V_40 ,
T_1 * V_41 ,
T_1 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_43 ;
enum V_44 V_45 ;
T_2 V_46 ;
for ( V_43 = 0 ; V_43 < V_40 ; V_43 ++ ) {
V_45 = F_19 ( V_39 [ V_43 ] ) ;
V_46 = F_20 ( V_39 [ V_43 ] ) ;
switch ( V_45 ) {
case V_55 :
V_46 = ( V_46 >= 1 ? 1 : 0 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_66 , V_67 ) ,
F_22 ( V_66 , V_67 ) ) ;
break;
case V_57 :
V_46 = ( V_46 >= 1 ? 0 : 1 ) ;
F_3 ( V_41 , V_42 , V_46 ,
F_21 ( V_66 , V_58 ) ,
F_22 ( V_66 , V_58 ) ) ;
break;
default:
F_16 ( V_3 -> V_23 ,
L_7 ,
V_45 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned V_4 ,
unsigned long * V_39 ,
unsigned V_40 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
enum V_1 V_68 ;
T_1 V_22 = 4 * V_4 ;
T_1 V_69 , V_70 ;
int V_32 ;
V_69 = 0 ;
V_70 = 0 ;
V_68 = F_1 ( V_3 , V_4 ) ;
switch ( V_68 ) {
case V_71 :
V_32 = F_18 ( V_3 , V_4 , V_39 ,
V_40 , & V_69 , & V_70 ) ;
break;
case V_72 :
V_32 = F_23 ( V_3 , V_4 , V_39 ,
V_40 , & V_69 , & V_70 ) ;
break;
case V_73 :
V_32 = F_25 ( V_3 , V_4 , V_39 ,
V_40 , & V_69 , & V_70 ) ;
break;
default:
F_16 ( V_3 -> V_23 , L_11 ,
V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return - V_60 ;
}
if ( V_32 )
return V_32 ;
F_14 ( V_3 -> V_23 ,
L_12 ,
V_33 , V_6 -> V_9 [ V_4 ] . V_17 , V_4 , V_69 , V_70 ) ;
V_32 = F_15 ( V_6 -> V_34 , V_22 , V_70 , V_69 ) ;
if ( V_32 ) {
F_16 ( V_3 -> V_23 ,
L_3 ,
V_6 -> V_9 [ V_4 ] . V_17 , V_4 ) ;
return V_32 ;
}
return 0 ;
}
static int T_3 F_27 ( struct V_74 * V_75 )
{
struct V_5 * V_6 = & V_76 ;
struct V_77 * V_78 ;
struct V_2 * V_79 ;
V_78 = F_28 ( V_75 , V_80 , 0 ) ;
if ( ! V_78 ) {
F_16 ( & V_75 -> V_23 , L_13 ) ;
return - V_81 ;
}
V_6 -> V_82 = F_29 ( & V_75 -> V_23 , V_78 ) ;
if ( F_30 ( V_6 -> V_82 ) ) {
F_16 ( & V_75 -> V_23 , L_14 ) ;
return - V_81 ;
}
V_6 -> V_34 = F_31 ( & V_75 -> V_23 , V_6 -> V_82 ,
& V_83 ) ;
if ( F_30 ( V_6 -> V_34 ) ) {
F_16 ( & V_75 -> V_23 , L_15 ) ;
return - V_81 ;
}
V_84 . V_17 = F_9 ( & V_75 -> V_23 ) ;
V_84 . V_9 = V_76 . V_9 ;
V_84 . V_7 = V_76 . V_7 ;
V_79 = F_32 ( & V_84 ,
& V_75 -> V_23 ,
V_6 ) ;
if ( ! V_79 ) {
F_16 ( & V_75 -> V_23 , L_16 ) ;
return - V_81 ;
}
F_33 ( V_75 , V_6 ) ;
return 0 ;
}
