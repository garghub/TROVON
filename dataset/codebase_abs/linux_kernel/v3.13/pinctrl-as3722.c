static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 , const unsigned * * V_9 , unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_11 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 [ V_13 ] . V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_13 , const char * const * * V_15 ,
unsigned * const V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_15 = V_4 -> V_14 [ V_13 ] . V_15 ;
* V_16 = V_4 -> V_14 [ V_13 ] . V_17 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_13 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_18 = F_9 ( V_6 ) ;
T_1 V_19 = F_10 ( V_4 -> V_14 [ V_13 ] . V_20 ) ;
int V_21 ;
F_11 ( V_4 -> V_22 , L_1 ,
V_23 , V_6 , V_13 , V_19 ) ;
V_21 = F_12 ( V_4 -> V_24 , V_18 ,
V_25 , V_19 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 , L_2 ,
V_6 , V_21 ) ;
return V_21 ;
}
V_4 -> V_26 [ V_6 ] . V_27 = V_13 ;
return V_21 ;
}
static int F_14 ( unsigned V_28 , bool V_29 )
{
if ( V_28 & V_30 )
return - V_31 ;
if ( V_28 & V_32 ) {
if ( V_28 & V_33 )
return V_34 ;
return V_35 ;
}
if ( V_29 ) {
if ( V_28 & V_33 )
return V_36 ;
else if ( V_28 & V_37 )
return V_38 ;
return V_39 ;
}
if ( V_28 & V_37 )
return V_40 ;
return V_41 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_42 * V_43 , unsigned V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_26 [ V_44 ] . V_27 )
return - V_45 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_42 * V_43 , unsigned V_44 , bool V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_46 ;
V_46 = F_14 (
V_4 -> V_26 [ V_44 ] . V_47 , V_29 ) ;
if ( V_46 < 0 ) {
F_13 ( V_4 -> V_22 , L_3 ,
( V_29 ) ? L_4 : L_5 , V_44 ) ;
return V_46 ;
}
if ( V_4 -> V_26 [ V_44 ] . V_48 )
V_46 |= V_49 ;
return F_17 ( V_24 , F_9 ( V_44 ) , V_46 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_50 , unsigned long * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_52 V_53 = F_19 ( * V_51 ) ;
int V_54 = 0 ;
T_2 V_55 ;
switch ( V_53 ) {
case V_56 :
V_55 = V_33 |
V_37 ;
if ( ! ( V_4 -> V_26 [ V_50 ] . V_47 & V_55 ) )
V_54 = 1 ;
V_55 = 0 ;
break;
case V_57 :
V_55 = V_33 ;
break;
case V_58 :
V_55 = V_37 ;
break;
case V_59 :
V_55 = V_32 ;
break;
case V_60 :
V_55 = V_30 ;
break;
default:
F_13 ( V_4 -> V_22 , L_6 ) ;
return - V_61 ;
}
if ( V_4 -> V_26 [ V_50 ] . V_47 & V_55 )
V_54 = 1 ;
* V_51 = F_20 ( V_53 , ( T_2 ) V_54 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_50 , unsigned long * V_62 ,
unsigned V_63 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_52 V_53 ;
int V_47 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_53 = F_19 ( V_62 [ V_64 ] ) ;
V_47 = V_4 -> V_26 [ V_50 ] . V_47 ;
switch ( V_53 ) {
case V_65 :
break;
case V_56 :
V_47 &= ~ ( V_33 |
V_37 ) ;
break;
case V_57 :
V_47 |= V_33 ;
break;
case V_58 :
V_47 |= V_37 ;
break;
case V_60 :
V_47 |= V_30 ;
break;
case V_59 :
V_47 |= V_32 ;
break;
default:
F_13 ( V_4 -> V_22 , L_6 ) ;
return - V_61 ;
}
V_4 -> V_26 [ V_50 ] . V_47 = V_47 ;
}
return 0 ;
}
static inline struct V_3 * F_22 ( struct V_66 * V_67 )
{
return F_23 ( V_67 , struct V_3 , V_66 ) ;
}
static int F_24 ( struct V_66 * V_67 , unsigned V_44 )
{
struct V_3 * V_4 = F_22 ( V_67 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_21 ;
T_3 V_68 ;
T_3 V_69 ;
T_3 V_19 ;
int V_46 ;
int V_70 ;
V_21 = F_25 ( V_24 , F_9 ( V_44 ) , & V_69 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_7 , V_44 , V_21 ) ;
return V_21 ;
}
V_70 = ! ! ( V_69 & V_49 ) ;
V_46 = V_69 & V_71 ;
switch ( V_46 ) {
case V_39 :
case V_36 :
case V_38 :
case V_35 :
case V_34 :
V_68 = V_72 ;
break;
case V_41 :
case V_40 :
V_68 = V_73 ;
break;
default:
return - V_31 ;
}
V_21 = F_25 ( V_24 , V_68 , & V_19 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_8 , V_21 ) ;
return V_21 ;
}
V_19 = ! ! ( V_19 & F_26 ( V_44 ) ) ;
return ( V_70 ) ? ! V_19 : V_19 ;
}
static void F_27 ( struct V_66 * V_67 , unsigned V_44 ,
int V_74 )
{
struct V_3 * V_4 = F_22 ( V_67 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_75 = V_4 -> V_26 [ V_44 ] . V_48 ;
T_3 V_19 ;
int V_21 ;
if ( V_74 )
V_19 = ( V_75 ) ? 0 : F_26 ( V_44 ) ;
else
V_19 = ( V_75 ) ? F_26 ( V_44 ) : 0 ;
V_21 = F_12 ( V_24 , V_73 ,
F_26 ( V_44 ) , V_19 ) ;
if ( V_21 < 0 )
F_13 ( V_4 -> V_22 ,
L_9 , V_21 ) ;
}
static int F_28 ( struct V_66 * V_67 , unsigned V_44 )
{
return F_29 ( V_67 -> V_76 + V_44 ) ;
}
static int F_30 ( struct V_66 * V_67 ,
unsigned V_44 , int V_74 )
{
F_27 ( V_67 , V_44 , V_74 ) ;
return F_31 ( V_67 -> V_76 + V_44 ) ;
}
static int F_32 ( struct V_66 * V_67 , unsigned V_44 )
{
struct V_3 * V_4 = F_22 ( V_67 ) ;
return F_33 ( V_4 -> V_24 , V_44 ) ;
}
static int F_34 ( struct V_66 * V_67 , unsigned V_44 )
{
return F_35 ( V_67 -> V_76 + V_44 ) ;
}
static void F_36 ( struct V_66 * V_67 , unsigned V_44 )
{
F_37 ( V_67 -> V_76 + V_44 ) ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_79 ;
V_4 = F_39 ( & V_78 -> V_22 , sizeof( * V_4 ) , V_80 ) ;
if ( ! V_4 )
return - V_81 ;
V_4 -> V_22 = & V_78 -> V_22 ;
V_4 -> V_22 -> V_82 = V_78 -> V_22 . V_83 -> V_82 ;
V_4 -> V_24 = F_40 ( V_78 -> V_22 . V_83 ) ;
F_41 ( V_78 , V_4 ) ;
V_4 -> V_9 = V_84 ;
V_4 -> V_10 = F_42 ( V_84 ) ;
V_4 -> V_14 = V_85 ;
V_4 -> V_12 = F_42 ( V_85 ) ;
V_4 -> V_7 = V_86 ;
V_4 -> V_5 = F_42 ( V_86 ) ;
V_87 . V_8 = F_43 ( & V_78 -> V_22 ) ;
V_87 . V_9 = V_84 ;
V_87 . V_11 = F_42 ( V_84 ) ;
V_4 -> V_88 = F_44 ( & V_87 ,
& V_78 -> V_22 , V_4 ) ;
if ( ! V_4 -> V_88 ) {
F_13 ( & V_78 -> V_22 , L_10 ) ;
return - V_31 ;
}
V_4 -> V_66 = V_89 ;
V_4 -> V_66 . V_22 = & V_78 -> V_22 ;
V_4 -> V_66 . V_82 = V_78 -> V_22 . V_83 -> V_82 ;
V_21 = F_45 ( & V_4 -> V_66 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_78 -> V_22 , L_11 , V_21 ) ;
goto V_90;
}
V_21 = F_46 ( & V_4 -> V_66 , F_43 ( & V_78 -> V_22 ) ,
0 , 0 , V_91 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_78 -> V_22 , L_12 , V_21 ) ;
goto V_92;
}
return 0 ;
V_92:
V_79 = F_47 ( & V_4 -> V_66 ) ;
if ( V_79 < 0 )
F_48 ( & V_78 -> V_22 , L_13 , V_79 ) ;
V_90:
F_49 ( V_4 -> V_88 ) ;
return V_21 ;
}
static int F_50 ( struct V_77 * V_78 )
{
struct V_3 * V_4 = F_51 ( V_78 ) ;
int V_21 ;
V_21 = F_47 ( & V_4 -> V_66 ) ;
if ( V_21 < 0 )
return V_21 ;
F_49 ( V_4 -> V_88 ) ;
return 0 ;
}
