static void F_1 ( struct V_1 * V_2 ,
signed long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_2 -> V_3 = V_3 ;
V_7 = ( V_3 - V_2 -> V_8 ) / V_2 -> V_9 ;
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
* V_17 = V_2 -> V_8 + V_2 -> V_9 * V_19 ;
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
V_5 = F_23 ( V_55 -> V_60 . V_61 ,
L_6 ) ;
if ( F_24 ( V_5 ) ) {
V_52 = F_25 ( V_5 ) ;
F_18 ( & V_55 -> V_60 , L_7 , V_52 ) ;
return V_52 ;
}
V_52 = F_4 ( V_5 , V_62 , & V_21 ) ;
if ( V_52 ) {
F_18 ( & V_55 -> V_60 , L_8 , V_52 ) ;
return V_52 ;
}
if ( V_21 == 0 || V_21 == ~ 0 ) {
F_18 ( & V_55 -> V_60 , L_9 ) ;
return - V_49 ;
}
V_58 = V_21 >> 20 ;
V_59 = ( V_21 & 0xfff00 ) >> 8 ;
V_57 = V_21 & 0xff ;
V_56 = 25 ;
V_2 -> V_9 = 1000 * ( V_56 - V_57 ) / ( V_58 - V_59 ) ;
V_2 -> V_8 = 1000 * V_57 - V_2 -> V_9 * V_59 ;
V_2 -> V_31 = 1000 * ( V_57 - 20 ) ;
V_2 -> V_32 = 1000 * ( V_57 - 5 ) ;
return 0 ;
}
static T_2 F_26 ( int V_35 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
F_27 ( V_35 ) ;
V_2 -> V_34 = false ;
return V_63 ;
}
static T_2 F_28 ( int V_35 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
F_6 ( & V_2 -> V_16 -> V_27 , L_10 ,
V_2 -> V_3 / 1000 ) ;
F_11 ( V_2 -> V_16 ) ;
return V_64 ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_65 V_66 ;
struct V_4 * V_5 ;
int V_67 ;
int V_52 ;
V_2 = F_30 ( & V_55 -> V_60 , sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_5 = F_23 ( V_55 -> V_60 . V_61 , L_11 ) ;
if ( F_24 ( V_5 ) ) {
V_52 = F_25 ( V_5 ) ;
F_18 ( & V_55 -> V_60 , L_12 , V_52 ) ;
return V_52 ;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_35 = F_31 ( V_55 , 0 ) ;
if ( V_2 -> V_35 < 0 )
return V_2 -> V_35 ;
V_52 = F_32 ( & V_55 -> V_60 , V_2 -> V_35 ,
F_26 , F_28 ,
0 , L_13 , V_2 ) ;
if ( V_52 < 0 ) {
F_18 ( & V_55 -> V_60 , L_14 , V_52 ) ;
return V_52 ;
}
F_33 ( V_55 , V_2 ) ;
V_52 = F_21 ( V_55 ) ;
if ( V_52 ) {
F_18 ( & V_55 -> V_60 , L_15 ) ;
return V_52 ;
}
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_11 , V_26 ) ;
F_2 ( V_5 , V_70 + V_11 , V_71 ) ;
F_2 ( V_5 , V_72 + V_13 , V_73 ) ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
F_34 ( 0 , & V_66 ) ;
V_2 -> V_51 = F_35 ( & V_66 ) ;
if ( F_24 ( V_2 -> V_51 ) ) {
V_52 = F_25 ( V_2 -> V_51 ) ;
F_18 ( & V_55 -> V_60 ,
L_16 , V_52 ) ;
return V_52 ;
}
V_2 -> V_16 = F_36 ( L_17 ,
V_74 ,
F_37 ( V_43 ) , V_2 ,
& V_75 , NULL ,
V_40 ,
V_38 ) ;
if ( F_24 ( V_2 -> V_16 ) ) {
V_52 = F_25 ( V_2 -> V_16 ) ;
F_18 ( & V_55 -> V_60 ,
L_18 , V_52 ) ;
F_38 ( V_2 -> V_51 ) ;
return V_52 ;
}
F_2 ( V_5 , V_70 + V_11 , V_71 ) ;
V_67 = F_39 ( 32768 , 10 ) ;
F_2 ( V_5 , V_70 + V_13 , V_67 ) ;
F_1 ( V_2 , V_2 -> V_31 ) ;
F_2 ( V_5 , V_10 + V_11 , V_25 ) ;
F_2 ( V_5 , V_10 + V_13 , V_26 ) ;
V_2 -> V_34 = true ;
V_2 -> V_22 = V_23 ;
return 0 ;
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_5 , V_10 + V_13 , V_25 ) ;
F_41 ( V_2 -> V_16 ) ;
F_38 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_42 ( struct V_27 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_21 ;
F_4 ( V_5 , V_10 , & V_21 ) ;
if ( ( V_21 & V_25 ) == 0 ) {
F_44 ( 50 ) ;
F_4 ( V_5 , V_10 , & V_21 ) ;
if ( ( V_21 & V_25 ) == 0 )
return - V_76 ;
}
return 0 ;
}
static int F_45 ( struct V_27 * V_60 )
{
return 0 ;
}
