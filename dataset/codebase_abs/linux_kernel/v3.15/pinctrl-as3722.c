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
return F_12 ( V_24 , F_9 ( V_51 ) ,
V_33 , V_53 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_54 , unsigned long * V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_56 V_57 = F_18 ( * V_55 ) ;
int V_58 = 0 ;
T_2 V_59 ;
switch ( V_57 ) {
case V_60 :
V_59 = V_41 |
V_45 ;
if ( ! ( V_4 -> V_26 [ V_54 ] . V_35 & V_59 ) )
V_58 = 1 ;
V_59 = 0 ;
break;
case V_61 :
V_59 = V_41 ;
break;
case V_62 :
V_59 = V_45 ;
break;
case V_63 :
V_59 = V_40 ;
break;
case V_64 :
V_59 = V_38 ;
break;
default:
F_13 ( V_4 -> V_22 , L_7 ) ;
return - V_65 ;
}
if ( V_4 -> V_26 [ V_54 ] . V_35 & V_59 )
V_58 = 1 ;
* V_55 = F_19 ( V_57 , ( T_2 ) V_58 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned V_54 , unsigned long * V_66 ,
unsigned V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_56 V_57 ;
int V_35 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
V_57 = F_18 ( V_66 [ V_68 ] ) ;
V_35 = V_4 -> V_26 [ V_54 ] . V_35 ;
switch ( V_57 ) {
case V_69 :
break;
case V_60 :
V_35 &= ~ ( V_41 |
V_45 ) ;
break;
case V_61 :
V_35 |= V_41 ;
break;
case V_62 :
V_35 |= V_45 ;
break;
case V_64 :
V_35 |= V_38 ;
break;
case V_63 :
V_35 |= V_40 ;
break;
default:
F_13 ( V_4 -> V_22 , L_7 ) ;
return - V_65 ;
}
V_4 -> V_26 [ V_54 ] . V_35 = V_35 ;
}
return 0 ;
}
static inline struct V_3 * F_21 ( struct V_70 * V_71 )
{
return F_22 ( V_71 , struct V_3 , V_70 ) ;
}
static int F_23 ( struct V_70 * V_71 , unsigned V_51 )
{
struct V_3 * V_4 = F_21 ( V_71 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_21 ;
T_3 V_72 ;
T_3 V_73 ;
T_3 V_19 ;
int V_53 ;
int V_74 ;
V_21 = F_24 ( V_24 , F_9 ( V_51 ) , & V_73 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_8 , V_51 , V_21 ) ;
return V_21 ;
}
V_74 = ! ! ( V_73 & V_75 ) ;
V_53 = V_73 & V_33 ;
switch ( V_53 ) {
case V_47 :
case V_44 :
case V_46 :
case V_43 :
case V_42 :
V_72 = V_76 ;
break;
case V_34 :
case V_48 :
V_72 = V_77 ;
break;
default:
return - V_39 ;
}
V_21 = F_24 ( V_24 , V_72 , & V_19 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_9 , V_21 ) ;
return V_21 ;
}
V_19 = ! ! ( V_19 & F_25 ( V_51 ) ) ;
return ( V_74 ) ? ! V_19 : V_19 ;
}
static void F_26 ( struct V_70 * V_71 , unsigned V_51 ,
int V_78 )
{
struct V_3 * V_4 = F_21 ( V_71 ) ;
struct V_24 * V_24 = V_4 -> V_24 ;
int V_79 ;
T_3 V_19 ;
int V_21 ;
V_21 = F_24 ( V_24 , F_9 ( V_51 ) , & V_19 ) ;
if ( V_21 < 0 ) {
F_13 ( V_4 -> V_22 ,
L_8 , V_51 , V_21 ) ;
return;
}
V_79 = ! ! ( V_19 & V_75 ) ;
if ( V_78 )
V_19 = ( V_79 ) ? 0 : F_25 ( V_51 ) ;
else
V_19 = ( V_79 ) ? F_25 ( V_51 ) : 0 ;
V_21 = F_12 ( V_24 , V_77 ,
F_25 ( V_51 ) , V_19 ) ;
if ( V_21 < 0 )
F_13 ( V_4 -> V_22 ,
L_10 , V_21 ) ;
}
static int F_27 ( struct V_70 * V_71 , unsigned V_51 )
{
return F_28 ( V_71 -> V_80 + V_51 ) ;
}
static int F_29 ( struct V_70 * V_71 ,
unsigned V_51 , int V_78 )
{
F_26 ( V_71 , V_51 , V_78 ) ;
return F_30 ( V_71 -> V_80 + V_51 ) ;
}
static int F_31 ( struct V_70 * V_71 , unsigned V_51 )
{
struct V_3 * V_4 = F_21 ( V_71 ) ;
return F_32 ( V_4 -> V_24 , V_51 ) ;
}
static int F_33 ( struct V_70 * V_71 , unsigned V_51 )
{
return F_34 ( V_71 -> V_80 + V_51 ) ;
}
static void F_35 ( struct V_70 * V_71 , unsigned V_51 )
{
F_36 ( V_71 -> V_80 + V_51 ) ;
}
static int F_37 ( struct V_81 * V_82 )
{
struct V_3 * V_4 ;
int V_21 ;
int V_83 ;
V_4 = F_38 ( & V_82 -> V_22 , sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return - V_85 ;
V_4 -> V_22 = & V_82 -> V_22 ;
V_4 -> V_22 -> V_86 = V_82 -> V_22 . V_87 -> V_86 ;
V_4 -> V_24 = F_39 ( V_82 -> V_22 . V_87 ) ;
F_40 ( V_82 , V_4 ) ;
V_4 -> V_9 = V_88 ;
V_4 -> V_10 = F_41 ( V_88 ) ;
V_4 -> V_14 = V_89 ;
V_4 -> V_12 = F_41 ( V_89 ) ;
V_4 -> V_7 = V_90 ;
V_4 -> V_5 = F_41 ( V_90 ) ;
V_91 . V_8 = F_42 ( & V_82 -> V_22 ) ;
V_91 . V_9 = V_88 ;
V_91 . V_11 = F_41 ( V_88 ) ;
V_4 -> V_92 = F_43 ( & V_91 ,
& V_82 -> V_22 , V_4 ) ;
if ( ! V_4 -> V_92 ) {
F_13 ( & V_82 -> V_22 , L_11 ) ;
return - V_39 ;
}
V_4 -> V_70 = V_93 ;
V_4 -> V_70 . V_22 = & V_82 -> V_22 ;
V_4 -> V_70 . V_86 = V_82 -> V_22 . V_87 -> V_86 ;
V_21 = F_44 ( & V_4 -> V_70 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_82 -> V_22 , L_12 , V_21 ) ;
goto V_94;
}
V_21 = F_45 ( & V_4 -> V_70 , F_42 ( & V_82 -> V_22 ) ,
0 , 0 , V_95 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_82 -> V_22 , L_13 , V_21 ) ;
goto V_96;
}
return 0 ;
V_96:
V_83 = F_46 ( & V_4 -> V_70 ) ;
if ( V_83 < 0 )
F_47 ( & V_82 -> V_22 , L_14 , V_83 ) ;
V_94:
F_48 ( V_4 -> V_92 ) ;
return V_21 ;
}
static int F_49 ( struct V_81 * V_82 )
{
struct V_3 * V_4 = F_50 ( V_82 ) ;
int V_21 ;
V_21 = F_46 ( & V_4 -> V_70 ) ;
if ( V_21 < 0 )
return V_21 ;
F_48 ( V_4 -> V_92 ) ;
return 0 ;
}
