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
switch ( V_19 ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_21 = F_12 ( V_4 -> V_24 , V_18 ,
V_33 , V_34 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 , L_3 ,
V_6 , V_21 ) ;
return V_21 ;
}
V_4 -> V_26 [ V_6 ] . V_35 =
V_34 ;
break;
default:
break;
}
return V_21 ;
}
static int F_14 ( unsigned V_36 , bool V_37 )
{
if ( V_36 & V_38 )
return - V_39 ;
if ( V_36 & V_40 ) {
if ( V_36 & V_41 )
return V_42 ;
return V_43 ;
}
if ( V_37 ) {
if ( V_36 & V_41 )
return V_44 ;
else if ( V_36 & V_45 )
return V_46 ;
return V_47 ;
}
if ( V_36 & V_45 )
return V_48 ;
return V_34 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_49 * V_50 , unsigned V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_26 [ V_51 ] . V_27 )
return - V_52 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_49 * V_50 , unsigned V_51 , bool V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_53 ;
V_53 = F_14 (
V_4 -> V_26 [ V_51 ] . V_35 , V_37 ) ;
if ( V_53 < 0 ) {
F_13 ( V_4 -> V_22 , L_4 ,
( V_37 ) ? L_5 : L_6 , V_51 ) ;
return V_53 ;
}
if ( V_4 -> V_26 [ V_51 ] . V_54 )
V_53 |= V_55 ;
return F_17 ( V_24 , F_9 ( V_51 ) , V_53 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_56 , unsigned long * V_57 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_58 V_59 = F_19 ( * V_57 ) ;
int V_60 = 0 ;
T_2 V_61 ;
switch ( V_59 ) {
case V_62 :
V_61 = V_41 |
V_45 ;
if ( ! ( V_4 -> V_26 [ V_56 ] . V_35 & V_61 ) )
V_60 = 1 ;
V_61 = 0 ;
break;
case V_63 :
V_61 = V_41 ;
break;
case V_64 :
V_61 = V_45 ;
break;
case V_65 :
V_61 = V_40 ;
break;
case V_66 :
V_61 = V_38 ;
break;
default:
F_13 ( V_4 -> V_22 , L_7 ) ;
return - V_67 ;
}
if ( V_4 -> V_26 [ V_56 ] . V_35 & V_61 )
V_60 = 1 ;
* V_57 = F_20 ( V_59 , ( T_2 ) V_60 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_56 , unsigned long * V_68 ,
unsigned V_69 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_58 V_59 ;
int V_35 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_59 = F_19 ( V_68 [ V_70 ] ) ;
V_35 = V_4 -> V_26 [ V_56 ] . V_35 ;
switch ( V_59 ) {
case V_71 :
break;
case V_62 :
V_35 &= ~ ( V_41 |
V_45 ) ;
break;
case V_63 :
V_35 |= V_41 ;
break;
case V_64 :
V_35 |= V_45 ;
break;
case V_66 :
V_35 |= V_38 ;
break;
case V_65 :
V_35 |= V_40 ;
break;
default:
F_13 ( V_4 -> V_22 , L_7 ) ;
return - V_67 ;
}
V_4 -> V_26 [ V_56 ] . V_35 = V_35 ;
}
return 0 ;
}
static inline struct V_3 * F_22 ( struct V_72 * V_73 )
{
return F_23 ( V_73 , struct V_3 , V_72 ) ;
}
static int F_24 ( struct V_72 * V_73 , unsigned V_51 )
{
struct V_3 * V_4 = F_22 ( V_73 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_21 ;
T_3 V_74 ;
T_3 V_75 ;
T_3 V_19 ;
int V_53 ;
int V_76 ;
V_21 = F_25 ( V_24 , F_9 ( V_51 ) , & V_75 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_8 , V_51 , V_21 ) ;
return V_21 ;
}
V_76 = ! ! ( V_75 & V_55 ) ;
V_53 = V_75 & V_33 ;
switch ( V_53 ) {
case V_47 :
case V_44 :
case V_46 :
case V_43 :
case V_42 :
V_74 = V_77 ;
break;
case V_34 :
case V_48 :
V_74 = V_78 ;
break;
default:
return - V_39 ;
}
V_21 = F_25 ( V_24 , V_74 , & V_19 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_9 , V_21 ) ;
return V_21 ;
}
V_19 = ! ! ( V_19 & F_26 ( V_51 ) ) ;
return ( V_76 ) ? ! V_19 : V_19 ;
}
static void F_27 ( struct V_72 * V_73 , unsigned V_51 ,
int V_79 )
{
struct V_3 * V_4 = F_22 ( V_73 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_80 = V_4 -> V_26 [ V_51 ] . V_54 ;
T_3 V_19 ;
int V_21 ;
if ( V_79 )
V_19 = ( V_80 ) ? 0 : F_26 ( V_51 ) ;
else
V_19 = ( V_80 ) ? F_26 ( V_51 ) : 0 ;
V_21 = F_12 ( V_24 , V_78 ,
F_26 ( V_51 ) , V_19 ) ;
if ( V_21 < 0 )
F_13 ( V_4 -> V_22 ,
L_10 , V_21 ) ;
}
static int F_28 ( struct V_72 * V_73 , unsigned V_51 )
{
return F_29 ( V_73 -> V_81 + V_51 ) ;
}
static int F_30 ( struct V_72 * V_73 ,
unsigned V_51 , int V_79 )
{
F_27 ( V_73 , V_51 , V_79 ) ;
return F_31 ( V_73 -> V_81 + V_51 ) ;
}
static int F_32 ( struct V_72 * V_73 , unsigned V_51 )
{
struct V_3 * V_4 = F_22 ( V_73 ) ;
return F_33 ( V_4 -> V_24 , V_51 ) ;
}
static int F_34 ( struct V_72 * V_73 , unsigned V_51 )
{
return F_35 ( V_73 -> V_81 + V_51 ) ;
}
static void F_36 ( struct V_72 * V_73 , unsigned V_51 )
{
F_37 ( V_73 -> V_81 + V_51 ) ;
}
static int F_38 ( struct V_82 * V_83 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_84 ;
V_4 = F_39 ( & V_83 -> V_22 , sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
return - V_86 ;
V_4 -> V_22 = & V_83 -> V_22 ;
V_4 -> V_22 -> V_87 = V_83 -> V_22 . V_88 -> V_87 ;
V_4 -> V_24 = F_40 ( V_83 -> V_22 . V_88 ) ;
F_41 ( V_83 , V_4 ) ;
V_4 -> V_9 = V_89 ;
V_4 -> V_10 = F_42 ( V_89 ) ;
V_4 -> V_14 = V_90 ;
V_4 -> V_12 = F_42 ( V_90 ) ;
V_4 -> V_7 = V_91 ;
V_4 -> V_5 = F_42 ( V_91 ) ;
V_92 . V_8 = F_43 ( & V_83 -> V_22 ) ;
V_92 . V_9 = V_89 ;
V_92 . V_11 = F_42 ( V_89 ) ;
V_4 -> V_93 = F_44 ( & V_92 ,
& V_83 -> V_22 , V_4 ) ;
if ( ! V_4 -> V_93 ) {
F_13 ( & V_83 -> V_22 , L_11 ) ;
return - V_39 ;
}
V_4 -> V_72 = V_94 ;
V_4 -> V_72 . V_22 = & V_83 -> V_22 ;
V_4 -> V_72 . V_87 = V_83 -> V_22 . V_88 -> V_87 ;
V_21 = F_45 ( & V_4 -> V_72 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_83 -> V_22 , L_12 , V_21 ) ;
goto V_95;
}
V_21 = F_46 ( & V_4 -> V_72 , F_43 ( & V_83 -> V_22 ) ,
0 , 0 , V_96 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_83 -> V_22 , L_13 , V_21 ) ;
goto V_97;
}
return 0 ;
V_97:
V_84 = F_47 ( & V_4 -> V_72 ) ;
if ( V_84 < 0 )
F_48 ( & V_83 -> V_22 , L_14 , V_84 ) ;
V_95:
F_49 ( V_4 -> V_93 ) ;
return V_21 ;
}
static int F_50 ( struct V_82 * V_83 )
{
struct V_3 * V_4 = F_51 ( V_83 ) ;
int V_21 ;
V_21 = F_47 ( & V_4 -> V_72 ) ;
if ( V_21 < 0 )
return V_21 ;
F_49 ( V_4 -> V_93 ) ;
return 0 ;
}
