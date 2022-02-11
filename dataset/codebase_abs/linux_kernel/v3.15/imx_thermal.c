static void F_1 ( struct V_1 * V_2 ,
signed long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_2 -> V_3 = V_3 ;
V_7 = ( V_2 -> V_8 - V_3 ) / V_2 -> V_9 ;
F_2 ( V_5 , V_10 + V_11 , V_12 ) ;
F_2 ( V_5 , V_10 + V_13 , V_7 <<
V_14 ) ;
}
static int F_3 ( struct V_15 * V_16 , unsigned long * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_19 ;
bool V_20 ;
T_1 V_21 ;
if ( V_2 -> V_22 == V_23 ) {
F_4 ( V_5 , V_10 , & V_21 ) ;
V_20 = ! ( V_21 & V_24 ) ;
} else {
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_13 , V_26 ) ;
V_20 = true ;
}
if ( V_20 )
F_5 ( 20 , 50 ) ;
F_4 ( V_5 , V_10 , & V_21 ) ;
if ( V_2 -> V_22 != V_23 ) {
F_2 ( V_5 , V_10 + V_11 , V_26 ) ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
}
if ( ( V_21 & V_24 ) == 0 ) {
F_6 ( & V_16 -> V_27 , L_1 ) ;
return - V_28 ;
}
V_19 = ( V_21 & V_29 ) >> V_30 ;
* V_17 = V_2 -> V_8 - V_19 * V_2 -> V_9 ;
if ( V_2 -> V_3 == V_2 -> V_31 && * V_17 >= V_2 -> V_31 )
F_1 ( V_2 , V_2 -> V_32 ) ;
if ( V_2 -> V_3 == V_2 -> V_32 && * V_17 < V_2 -> V_31 ) {
F_1 ( V_2 , V_2 -> V_31 ) ;
F_6 ( & V_16 -> V_27 , L_2 ,
V_2 -> V_3 / 1000 ) ;
}
if ( * V_17 != V_2 -> V_33 ) {
F_6 ( & V_16 -> V_27 , L_3 , * V_17 ) ;
V_2 -> V_33 = * V_17 ;
}
if ( ! V_2 -> V_34 && * V_17 < V_2 -> V_3 ) {
V_2 -> V_34 = true ;
F_7 ( V_2 -> V_35 ) ;
}
return 0 ;
}
static int F_8 ( struct V_15 * V_16 ,
enum V_36 * V_22 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
* V_22 = V_2 -> V_22 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 ,
enum V_36 V_22 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_22 == V_23 ) {
V_16 -> V_37 = V_38 ;
V_16 -> V_39 = V_40 ;
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_13 , V_26 ) ;
if ( ! V_2 -> V_34 ) {
V_2 -> V_34 = true ;
F_7 ( V_2 -> V_35 ) ;
}
} else {
F_2 ( V_5 , V_10 + V_11 , V_26 ) ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
V_16 -> V_37 = 0 ;
V_16 -> V_39 = 0 ;
if ( V_2 -> V_34 ) {
F_10 ( V_2 -> V_35 ) ;
V_2 -> V_34 = false ;
}
}
V_2 -> V_22 = V_22 ;
F_11 ( V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_16 , int V_41 ,
enum V_42 * type )
{
* type = ( V_41 == V_43 ) ? V_44 :
V_45 ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 ,
unsigned long * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
* V_17 = V_2 -> V_32 ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 , int V_41 ,
unsigned long * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
* V_17 = ( V_41 == V_43 ) ? V_2 -> V_31 :
V_2 -> V_32 ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 , int V_41 ,
unsigned long V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
if ( V_41 == V_46 )
return - V_47 ;
if ( V_17 > V_48 )
return - V_49 ;
V_2 -> V_31 = V_17 ;
F_1 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 ,
struct V_50 * V_51 )
{
int V_52 ;
V_52 = F_17 ( V_16 , V_43 , V_51 ,
V_53 ,
V_53 ) ;
if ( V_52 ) {
F_18 ( & V_16 -> V_27 ,
L_4 ,
V_16 -> type , V_51 -> type , V_52 ) ;
return V_52 ;
}
return 0 ;
}
static int F_19 ( struct V_15 * V_16 ,
struct V_50 * V_51 )
{
int V_52 ;
V_52 = F_20 ( V_16 , V_43 , V_51 ) ;
if ( V_52 ) {
F_18 ( & V_16 -> V_27 ,
L_5 ,
V_16 -> type , V_51 -> type , V_52 ) ;
return V_52 ;
}
return 0 ;
}
static int F_21 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
struct V_4 * V_5 ;
int V_56 , V_57 , V_58 , V_59 ;
int V_52 ;
T_1 V_21 ;
T_2 V_60 ;
V_5 = F_23 ( V_55 -> V_61 . V_62 ,
L_6 ) ;
if ( F_24 ( V_5 ) ) {
V_52 = F_25 ( V_5 ) ;
F_18 ( & V_55 -> V_61 , L_7 , V_52 ) ;
return V_52 ;
}
V_52 = F_4 ( V_5 , V_63 , & V_21 ) ;
if ( V_52 ) {
F_18 ( & V_55 -> V_61 , L_8 , V_52 ) ;
return V_52 ;
}
if ( V_21 == 0 || V_21 == ~ 0 ) {
F_18 ( & V_55 -> V_61 , L_9 ) ;
return - V_49 ;
}
V_58 = V_21 >> 20 ;
V_59 = ( V_21 & 0xfff00 ) >> 8 ;
V_57 = V_21 & 0xff ;
V_56 = 25 ;
V_60 = V_64 ;
V_60 *= 1000 ;
F_26 ( V_60 , V_65 * V_58 - V_66 ) ;
V_2 -> V_9 = V_60 ;
V_2 -> V_8 = V_58 * V_2 -> V_9 + 1000 * V_56 ;
V_2 -> V_31 = 1000 * ( V_57 - 20 ) ;
V_2 -> V_32 = 1000 * ( V_57 - 5 ) ;
return 0 ;
}
static T_3 F_27 ( int V_35 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
F_28 ( V_35 ) ;
V_2 -> V_34 = false ;
return V_67 ;
}
static T_3 F_29 ( int V_35 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
F_6 ( & V_2 -> V_16 -> V_27 , L_10 ,
V_2 -> V_3 / 1000 ) ;
F_11 ( V_2 -> V_16 ) ;
return V_68 ;
}
static int F_30 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_69 V_70 ;
struct V_4 * V_5 ;
int V_71 ;
int V_52 ;
V_2 = F_31 ( & V_55 -> V_61 , sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_5 = F_23 ( V_55 -> V_61 . V_62 , L_11 ) ;
if ( F_24 ( V_5 ) ) {
V_52 = F_25 ( V_5 ) ;
F_18 ( & V_55 -> V_61 , L_12 , V_52 ) ;
return V_52 ;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_35 = F_32 ( V_55 , 0 ) ;
if ( V_2 -> V_35 < 0 )
return V_2 -> V_35 ;
V_52 = F_33 ( & V_55 -> V_61 , V_2 -> V_35 ,
F_27 , F_29 ,
0 , L_13 , V_2 ) ;
if ( V_52 < 0 ) {
F_18 ( & V_55 -> V_61 , L_14 , V_52 ) ;
return V_52 ;
}
F_34 ( V_55 , V_2 ) ;
V_52 = F_21 ( V_55 ) ;
if ( V_52 ) {
F_18 ( & V_55 -> V_61 , L_15 ) ;
return V_52 ;
}
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_11 , V_26 ) ;
F_2 ( V_5 , V_74 + V_11 , V_75 ) ;
F_2 ( V_5 , V_76 + V_13 , V_77 ) ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
F_35 ( 0 , & V_70 ) ;
V_2 -> V_51 = F_36 ( & V_70 ) ;
if ( F_24 ( V_2 -> V_51 ) ) {
V_52 = F_25 ( V_2 -> V_51 ) ;
F_18 ( & V_55 -> V_61 ,
L_16 , V_52 ) ;
return V_52 ;
}
V_2 -> V_16 = F_37 ( L_17 ,
V_78 ,
F_38 ( V_43 ) , V_2 ,
& V_79 , NULL ,
V_40 ,
V_38 ) ;
if ( F_24 ( V_2 -> V_16 ) ) {
V_52 = F_25 ( V_2 -> V_16 ) ;
F_18 ( & V_55 -> V_61 ,
L_18 , V_52 ) ;
F_39 ( V_2 -> V_51 ) ;
return V_52 ;
}
V_2 -> V_80 = F_40 ( & V_55 -> V_61 , NULL ) ;
if ( F_24 ( V_2 -> V_80 ) ) {
F_41 ( & V_55 -> V_61 , L_19 ) ;
} else {
V_52 = F_42 ( V_2 -> V_80 ) ;
if ( V_52 )
F_41 ( & V_55 -> V_61 , L_20 , V_52 ) ;
}
F_2 ( V_5 , V_74 + V_11 , V_75 ) ;
V_71 = F_43 ( 32768 , 10 ) ;
F_2 ( V_5 , V_74 + V_13 , V_71 ) ;
F_1 ( V_2 , V_2 -> V_31 ) ;
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_13 , V_26 ) ;
V_2 -> V_34 = true ;
V_2 -> V_22 = V_23 ;
return 0 ;
}
static int F_44 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
if ( ! F_24 ( V_2 -> V_80 ) )
F_45 ( V_2 -> V_80 ) ;
F_46 ( V_2 -> V_16 ) ;
F_39 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_47 ( struct V_27 * V_61 )
{
struct V_1 * V_2 = F_48 ( V_61 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_10 + V_11 , V_26 ) ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
V_2 -> V_22 = V_81 ;
return 0 ;
}
static int F_49 ( struct V_27 * V_61 )
{
struct V_1 * V_2 = F_48 ( V_61 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_13 , V_26 ) ;
V_2 -> V_22 = V_23 ;
return 0 ;
}
