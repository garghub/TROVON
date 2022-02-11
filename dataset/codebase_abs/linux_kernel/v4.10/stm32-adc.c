static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
F_6 ( V_7 , V_2 -> V_4 -> V_5 + V_2 -> V_6 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_9 ;
F_8 ( & V_2 -> V_10 , V_9 ) ;
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_8 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
unsigned long V_9 ;
F_8 ( & V_2 -> V_10 , V_9 ) ;
F_5 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_8 ) ;
F_9 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_11 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_11 , V_13 ) ;
F_7 ( V_2 , V_14 , V_15 | V_16 ) ;
F_14 ( 2 , 3 ) ;
if ( ! ( F_1 ( V_2 , V_14 ) & V_17 ) )
F_7 ( V_2 , V_14 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_14 , V_17 ) ;
F_10 ( V_2 , V_19 , V_20 ) ;
F_10 ( V_2 , V_11 , V_13 ) ;
F_10 ( V_2 , V_14 , V_16 ) ;
}
static int F_16 ( struct V_21 * V_22 ,
const struct V_23 * V_24 ,
int * V_25 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
long V_26 ;
T_1 V_7 ;
T_2 V_27 ;
int V_28 ;
F_18 ( & V_2 -> V_29 ) ;
V_2 -> V_30 = & V_27 ;
V_7 = F_1 ( V_2 , V_31 ) ;
V_7 &= ~ V_32 ;
V_7 |= V_24 -> V_33 << V_34 ;
F_5 ( V_2 , V_31 , V_7 ) ;
F_10 ( V_2 , V_35 , V_36 ) ;
F_10 ( V_2 , V_14 , V_17 ) ;
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
V_26 = F_19 (
& V_2 -> V_29 , V_37 ) ;
if ( V_26 == 0 ) {
V_28 = - V_38 ;
} else if ( V_26 < 0 ) {
V_28 = V_26 ;
} else {
* V_25 = V_27 ;
V_28 = V_39 ;
}
F_15 ( V_2 ) ;
F_12 ( V_2 ) ;
return V_28 ;
}
static int F_20 ( struct V_21 * V_22 ,
struct V_23 const * V_24 ,
int * V_7 , int * V_40 , long V_41 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
int V_28 ;
switch ( V_41 ) {
case V_42 :
V_28 = F_21 ( V_22 ) ;
if ( V_28 )
return V_28 ;
if ( V_24 -> type == V_43 )
V_28 = F_16 ( V_22 , V_24 , V_7 ) ;
else
V_28 = - V_44 ;
F_22 ( V_22 ) ;
return V_28 ;
case V_45 :
* V_7 = V_2 -> V_4 -> V_46 ;
* V_40 = V_24 -> V_47 . V_48 ;
return V_49 ;
default:
return - V_44 ;
}
}
static T_3 F_23 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
T_1 V_52 = F_1 ( V_2 , V_19 ) ;
if ( V_52 & V_53 ) {
* V_2 -> V_30 = F_3 ( V_2 , V_54 ) ;
F_24 ( & V_2 -> V_29 ) ;
return V_55 ;
}
return V_56 ;
}
static int F_25 ( struct V_21 * V_22 ,
const struct V_57 * V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_22 -> V_60 ; V_59 ++ )
if ( V_22 -> V_61 [ V_59 ] . V_33 == V_58 -> args [ 0 ] )
return V_59 ;
return - V_44 ;
}
static int F_26 ( struct V_21 * V_22 ,
unsigned V_3 , unsigned V_62 ,
unsigned * V_63 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
if ( ! V_63 )
F_5 ( V_2 , V_3 , V_62 ) ;
else
* V_63 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_27 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const struct V_64 * V_33 ,
int V_65 )
{
V_24 -> type = V_33 -> type ;
V_24 -> V_33 = V_33 -> V_33 ;
V_24 -> V_66 = V_33 -> V_67 ;
V_24 -> V_65 = V_65 ;
V_24 -> V_68 = 1 ;
V_24 -> V_69 = F_28 ( V_42 ) ;
V_24 -> V_70 = F_28 ( V_45 ) ;
V_24 -> V_47 . V_71 = 'u' ;
V_24 -> V_47 . V_48 = 12 ;
V_24 -> V_47 . V_72 = 16 ;
}
static int F_29 ( struct V_21 * V_22 )
{
struct V_73 * V_74 = V_22 -> V_75 . V_76 ;
struct V_77 * V_78 ;
const T_4 * V_79 ;
struct V_23 * V_61 ;
int V_65 = 0 , V_60 ;
T_1 V_7 ;
V_60 = F_30 ( V_74 , L_1 ) ;
if ( V_60 < 0 ||
V_60 >= F_31 ( V_80 ) ) {
F_32 ( & V_22 -> V_75 , L_2 ) ;
return V_60 < 0 ? V_60 : - V_44 ;
}
V_61 = F_33 ( & V_22 -> V_75 , V_60 ,
sizeof( struct V_23 ) , V_81 ) ;
if ( ! V_61 )
return - V_82 ;
F_34 (node, L_1 , prop, cur, val) {
if ( V_7 >= F_31 ( V_80 ) ) {
F_32 ( & V_22 -> V_75 , L_3 , V_7 ) ;
return - V_44 ;
}
F_27 ( V_22 , & V_61 [ V_65 ] ,
& V_80 [ V_7 ] ,
V_65 ) ;
V_65 ++ ;
}
V_22 -> V_60 = V_65 ;
V_22 -> V_61 = V_61 ;
return 0 ;
}
static int F_35 ( struct V_83 * V_84 )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_28 ;
if ( ! V_84 -> V_75 . V_76 )
return - V_85 ;
V_22 = F_36 ( & V_84 -> V_75 , sizeof( * V_2 ) ) ;
if ( ! V_22 )
return - V_82 ;
V_2 = F_17 ( V_22 ) ;
V_2 -> V_4 = F_37 ( V_84 -> V_75 . V_86 ) ;
F_38 ( & V_2 -> V_10 ) ;
F_39 ( & V_2 -> V_29 ) ;
V_22 -> V_67 = F_40 ( & V_84 -> V_75 ) ;
V_22 -> V_75 . V_86 = & V_84 -> V_75 ;
V_22 -> V_75 . V_76 = V_84 -> V_75 . V_76 ;
V_22 -> V_87 = & V_88 ;
V_22 -> V_89 = V_90 ;
F_41 ( V_84 , V_2 ) ;
V_28 = F_42 ( V_84 -> V_75 . V_76 , L_4 , & V_2 -> V_6 ) ;
if ( V_28 != 0 ) {
F_32 ( & V_84 -> V_75 , L_5 ) ;
return - V_44 ;
}
V_2 -> V_50 = F_43 ( V_84 , 0 ) ;
if ( V_2 -> V_50 < 0 ) {
F_32 ( & V_84 -> V_75 , L_6 ) ;
return V_2 -> V_50 ;
}
V_28 = F_44 ( & V_84 -> V_75 , V_2 -> V_50 , F_23 ,
0 , V_84 -> V_67 , V_2 ) ;
if ( V_28 ) {
F_32 ( & V_84 -> V_75 , L_7 ) ;
return V_28 ;
}
V_2 -> V_91 = F_45 ( & V_84 -> V_75 , NULL ) ;
if ( F_46 ( V_2 -> V_91 ) ) {
F_32 ( & V_84 -> V_75 , L_8 ) ;
return F_47 ( V_2 -> V_91 ) ;
}
V_28 = F_48 ( V_2 -> V_91 ) ;
if ( V_28 < 0 ) {
F_32 ( & V_84 -> V_75 , L_9 ) ;
return V_28 ;
}
V_28 = F_29 ( V_22 ) ;
if ( V_28 < 0 )
goto V_92;
V_28 = F_49 ( V_22 ) ;
if ( V_28 ) {
F_32 ( & V_84 -> V_75 , L_10 ) ;
goto V_92;
}
return 0 ;
V_92:
F_50 ( V_2 -> V_91 ) ;
return V_28 ;
}
static int F_51 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_52 ( V_84 ) ;
struct V_21 * V_22 = F_53 ( V_2 ) ;
F_54 ( V_22 ) ;
F_50 ( V_2 -> V_91 ) ;
return 0 ;
}
