static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = ( V_2 -> V_8 - V_3 ) / V_2 -> V_9 ;
F_2 ( V_5 , V_10 + V_11 , V_12 ) ;
F_2 ( V_5 , V_10 + V_13 , V_7 <<
V_14 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
int V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_16 ;
V_2 -> V_15 = V_15 ;
V_16 = ( V_2 -> V_8 - V_15 ) / V_2 -> V_9 ;
F_2 ( V_5 , V_17 + V_11 , V_18 ) ;
F_2 ( V_5 , V_17 + V_13 , V_16 <<
V_19 ) ;
}
static int F_4 ( struct V_20 * V_21 , int * V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_24 ;
bool V_25 ;
T_1 V_26 ;
if ( V_2 -> V_27 == V_28 ) {
F_5 ( V_5 , V_17 , & V_26 ) ;
V_25 = ! ( V_26 & V_29 ) ;
} else {
F_2 ( V_5 , V_17 + V_11 , V_30 ) ;
F_2 ( V_5 , V_17 + V_13 , V_31 ) ;
V_25 = true ;
}
if ( V_25 )
F_6 ( 20 , 50 ) ;
F_5 ( V_5 , V_17 , & V_26 ) ;
if ( V_2 -> V_27 != V_28 ) {
F_2 ( V_5 , V_17 + V_11 , V_31 ) ;
F_2 ( V_5 , V_17 + V_13 , V_30 ) ;
}
if ( ( V_26 & V_29 ) == 0 ) {
F_7 ( & V_21 -> V_32 , L_1 ) ;
return - V_33 ;
}
V_24 = ( V_26 & V_34 ) >> V_35 ;
* V_22 = V_2 -> V_8 - V_24 * V_2 -> V_9 ;
if ( V_2 -> V_36 -> V_37 == V_38 ) {
if ( V_2 -> V_15 == V_2 -> V_39 &&
* V_22 >= V_2 -> V_39 )
F_3 ( V_2 , V_2 -> V_40 ) ;
if ( V_2 -> V_15 == V_2 -> V_40 &&
* V_22 < V_2 -> V_39 ) {
F_3 ( V_2 , V_2 -> V_39 ) ;
F_7 ( & V_21 -> V_32 , L_2 ,
V_2 -> V_15 / 1000 ) ;
}
}
if ( * V_22 != V_2 -> V_41 ) {
F_7 ( & V_21 -> V_32 , L_3 , * V_22 ) ;
V_2 -> V_41 = * V_22 ;
}
if ( ! V_2 -> V_42 && * V_22 < V_2 -> V_15 ) {
V_2 -> V_42 = true ;
F_8 ( V_2 -> V_43 ) ;
}
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
enum V_44 * V_27 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
* V_27 = V_2 -> V_27 ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 ,
enum V_44 V_27 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_27 == V_28 ) {
V_21 -> V_45 = V_46 ;
V_21 -> V_47 = V_48 ;
F_2 ( V_5 , V_17 + V_11 , V_30 ) ;
F_2 ( V_5 , V_17 + V_13 , V_31 ) ;
if ( ! V_2 -> V_42 ) {
V_2 -> V_42 = true ;
F_8 ( V_2 -> V_43 ) ;
}
} else {
F_2 ( V_5 , V_17 + V_11 , V_31 ) ;
F_2 ( V_5 , V_17 + V_13 , V_30 ) ;
V_21 -> V_45 = 0 ;
V_21 -> V_47 = 0 ;
if ( V_2 -> V_42 ) {
F_11 ( V_2 -> V_43 ) ;
V_2 -> V_42 = false ;
}
}
V_2 -> V_27 = V_27 ;
F_12 ( V_21 ) ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , int V_49 ,
enum V_50 * type )
{
* type = ( V_49 == V_51 ) ? V_52 :
V_53 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 , int * V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
* V_22 = V_2 -> V_40 ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , int V_49 ,
int * V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
* V_22 = ( V_49 == V_51 ) ? V_2 -> V_39 :
V_2 -> V_40 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 , int V_49 ,
int V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( V_49 == V_54 )
return - V_55 ;
if ( V_22 < 0 || V_22 > V_2 -> V_40 )
return - V_56 ;
V_2 -> V_39 = V_22 ;
F_3 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 ,
struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_18 ( V_21 , V_51 , V_58 ,
V_60 ,
V_60 ,
V_61 ) ;
if ( V_59 ) {
F_19 ( & V_21 -> V_32 ,
L_4 ,
V_21 -> type , V_58 -> type , V_59 ) ;
return V_59 ;
}
return 0 ;
}
static int F_20 ( struct V_20 * V_21 ,
struct V_57 * V_58 )
{
int V_59 ;
V_59 = F_21 ( V_21 , V_51 , V_58 ) ;
if ( V_59 ) {
F_19 ( & V_21 -> V_32 ,
L_5 ,
V_21 -> type , V_58 -> type , V_59 ) ;
return V_59 ;
}
return 0 ;
}
static int F_22 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_23 ( V_63 ) ;
struct V_4 * V_5 ;
int V_64 , V_65 ;
int V_59 ;
T_1 V_26 ;
T_2 V_66 ;
V_5 = F_24 ( V_63 -> V_67 . V_68 ,
L_6 ) ;
if ( F_25 ( V_5 ) ) {
V_59 = F_26 ( V_5 ) ;
F_19 ( & V_63 -> V_67 , L_7 , V_59 ) ;
return V_59 ;
}
V_59 = F_5 ( V_5 , V_69 , & V_26 ) ;
if ( V_59 ) {
F_19 ( & V_63 -> V_67 , L_8 , V_59 ) ;
return V_59 ;
}
if ( V_26 == 0 || V_26 == ~ 0 ) {
F_19 ( & V_63 -> V_67 , L_9 ) ;
return - V_56 ;
}
V_65 = V_26 >> 20 ;
V_64 = 25 ;
V_66 = V_70 ;
V_66 *= 1000 ;
F_27 ( V_66 , V_71 * V_65 - V_72 ) ;
V_2 -> V_9 = V_66 ;
V_2 -> V_8 = V_65 * V_2 -> V_9 + 1000 * V_64 ;
V_59 = F_5 ( V_5 , V_73 , & V_26 ) ;
if ( V_59 ) {
F_19 ( & V_63 -> V_67 , L_10 , V_59 ) ;
return V_59 ;
}
switch ( ( V_26 >> 6 ) & 0x3 ) {
case 0 :
V_2 -> V_74 = L_11 ;
V_2 -> V_75 = 95000 ;
break;
case 1 :
V_2 -> V_74 = L_12 ;
V_2 -> V_75 = 105000 ;
break;
case 2 :
V_2 -> V_74 = L_13 ;
V_2 -> V_75 = 105000 ;
break;
case 3 :
V_2 -> V_74 = L_14 ;
V_2 -> V_75 = 125000 ;
break;
}
V_2 -> V_40 = V_2 -> V_75 - ( 1000 * 5 ) ;
V_2 -> V_39 = V_2 -> V_75 - ( 1000 * 10 ) ;
return 0 ;
}
static T_3 F_28 ( int V_43 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
F_29 ( V_43 ) ;
V_2 -> V_42 = false ;
return V_76 ;
}
static T_3 F_30 ( int V_43 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
F_7 ( & V_2 -> V_21 -> V_32 , L_15 ,
V_2 -> V_15 / 1000 ) ;
F_12 ( V_2 -> V_21 ) ;
return V_77 ;
}
static int F_31 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_78 ;
int V_59 ;
V_2 = F_32 ( & V_63 -> V_67 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return - V_80 ;
V_5 = F_24 ( V_63 -> V_67 . V_68 , L_16 ) ;
if ( F_25 ( V_5 ) ) {
V_59 = F_26 ( V_5 ) ;
F_19 ( & V_63 -> V_67 , L_17 , V_59 ) ;
return V_59 ;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_36 = F_33 ( & V_63 -> V_67 ) ;
if ( V_2 -> V_36 -> V_37 == V_81 ) {
F_2 ( V_5 , V_82 + V_11 , V_83 |
V_84 | V_85 ) ;
F_2 ( V_5 , V_10 + V_13 ,
V_86 ) ;
}
V_2 -> V_43 = F_34 ( V_63 , 0 ) ;
if ( V_2 -> V_43 < 0 )
return V_2 -> V_43 ;
F_35 ( V_63 , V_2 ) ;
V_59 = F_22 ( V_63 ) ;
if ( V_59 ) {
F_19 ( & V_63 -> V_67 , L_18 ) ;
return V_59 ;
}
F_2 ( V_5 , V_17 + V_11 , V_30 ) ;
F_2 ( V_5 , V_17 + V_11 , V_31 ) ;
F_2 ( V_5 , V_87 + V_11 , V_88 ) ;
F_2 ( V_5 , V_89 + V_13 , V_90 ) ;
F_2 ( V_5 , V_17 + V_13 , V_30 ) ;
V_2 -> V_58 = F_36 ( V_91 ) ;
if ( F_25 ( V_2 -> V_58 ) ) {
V_59 = F_26 ( V_2 -> V_58 ) ;
if ( V_59 != - V_92 )
F_19 ( & V_63 -> V_67 ,
L_19 ,
V_59 ) ;
return V_59 ;
}
V_2 -> V_93 = F_37 ( & V_63 -> V_67 , NULL ) ;
if ( F_25 ( V_2 -> V_93 ) ) {
V_59 = F_26 ( V_2 -> V_93 ) ;
if ( V_59 != - V_92 )
F_19 ( & V_63 -> V_67 ,
L_20 , V_59 ) ;
F_38 ( V_2 -> V_58 ) ;
return V_59 ;
}
V_59 = F_39 ( V_2 -> V_93 ) ;
if ( V_59 ) {
F_19 ( & V_63 -> V_67 , L_21 , V_59 ) ;
F_38 ( V_2 -> V_58 ) ;
return V_59 ;
}
V_2 -> V_21 = F_40 ( L_22 ,
V_94 ,
F_41 ( V_51 ) , V_2 ,
& V_95 , NULL ,
V_48 ,
V_46 ) ;
if ( F_25 ( V_2 -> V_21 ) ) {
V_59 = F_26 ( V_2 -> V_21 ) ;
F_19 ( & V_63 -> V_67 ,
L_23 , V_59 ) ;
F_42 ( V_2 -> V_93 ) ;
F_38 ( V_2 -> V_58 ) ;
return V_59 ;
}
F_43 ( & V_63 -> V_67 , L_24
L_25 , V_2 -> V_74 ,
V_2 -> V_75 / 1000 , V_2 -> V_40 / 1000 ,
V_2 -> V_39 / 1000 ) ;
F_2 ( V_5 , V_87 + V_11 , V_88 ) ;
V_78 = F_44 ( 32768 , 10 ) ;
F_2 ( V_5 , V_87 + V_13 , V_78 ) ;
F_3 ( V_2 , V_2 -> V_39 ) ;
if ( V_2 -> V_36 -> V_37 == V_81 )
F_1 ( V_2 , V_2 -> V_40 ) ;
F_2 ( V_5 , V_17 + V_11 , V_30 ) ;
F_2 ( V_5 , V_17 + V_13 , V_31 ) ;
V_59 = F_45 ( & V_63 -> V_67 , V_2 -> V_43 ,
F_28 , F_30 ,
0 , L_26 , V_2 ) ;
if ( V_59 < 0 ) {
F_19 ( & V_63 -> V_67 , L_27 , V_59 ) ;
F_42 ( V_2 -> V_93 ) ;
F_46 ( V_2 -> V_21 ) ;
F_38 ( V_2 -> V_58 ) ;
return V_59 ;
}
V_2 -> V_42 = true ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
static int F_47 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_23 ( V_63 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_17 + V_13 , V_30 ) ;
if ( ! F_25 ( V_2 -> V_93 ) )
F_42 ( V_2 -> V_93 ) ;
F_46 ( V_2 -> V_21 ) ;
F_38 ( V_2 -> V_58 ) ;
return 0 ;
}
static int F_48 ( struct V_32 * V_67 )
{
struct V_1 * V_2 = F_49 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_17 + V_11 , V_31 ) ;
F_2 ( V_5 , V_17 + V_13 , V_30 ) ;
V_2 -> V_27 = V_96 ;
F_42 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_50 ( struct V_32 * V_67 )
{
struct V_1 * V_2 = F_49 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_39 ( V_2 -> V_93 ) ;
F_2 ( V_5 , V_17 + V_11 , V_30 ) ;
F_2 ( V_5 , V_17 + V_13 , V_31 ) ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
