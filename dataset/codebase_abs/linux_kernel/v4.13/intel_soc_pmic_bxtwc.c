static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 [ 2 ] ;
T_1 V_7 [ 4 ] ;
struct V_8 * V_9 = V_1 ;
if ( ! V_9 )
return - V_10 ;
if ( V_2 & V_11 )
V_5 = ( V_2 & V_11 ) >> V_12 ;
else
V_5 = V_13 ;
V_2 &= V_14 ;
V_6 [ 0 ] = V_2 ;
V_6 [ 1 ] = V_5 ;
V_4 = F_2 ( V_15 ,
V_16 ,
V_6 , sizeof( V_6 ) , ( V_17 * ) V_7 , 1 ) ;
if ( V_4 ) {
F_3 ( V_9 -> V_18 , L_1 ) ;
return V_4 ;
}
* V_3 = V_7 [ 0 ] ;
return 0 ;
}
static int F_4 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 [ 3 ] ;
struct V_8 * V_9 = V_1 ;
if ( ! V_9 )
return - V_10 ;
if ( V_2 & V_11 )
V_5 = ( V_2 & V_11 ) >> V_12 ;
else
V_5 = V_13 ;
V_2 &= V_14 ;
V_6 [ 0 ] = V_2 ;
V_6 [ 1 ] = V_5 ;
V_6 [ 2 ] = V_3 ;
V_4 = F_2 ( V_15 ,
V_19 ,
V_6 , sizeof( V_6 ) , NULL , 0 ) ;
if ( V_4 ) {
F_3 ( V_9 -> V_18 , L_2 ) ;
return V_4 ;
}
return 0 ;
}
static T_2 F_5 ( struct V_20 * V_18 ,
struct V_21 * V_22 , char * V_23 )
{
return sprintf ( V_23 , L_3 , V_24 ) ;
}
static T_2 F_6 ( struct V_20 * V_18 ,
struct V_21 * V_22 , const char * V_23 , T_3 V_25 )
{
if ( F_7 ( V_23 , 0 , & V_24 ) ) {
F_3 ( V_18 , L_4 ) ;
return - V_10 ;
}
return ( T_2 ) V_25 ;
}
static T_2 F_8 ( struct V_20 * V_18 ,
struct V_21 * V_22 , char * V_23 )
{
int V_4 ;
unsigned int V_3 ;
struct V_8 * V_9 = F_9 ( V_18 ) ;
V_4 = F_10 ( V_9 -> V_26 , V_24 , & V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_18 , L_5 , V_24 ) ;
return - V_27 ;
}
return sprintf ( V_23 , L_6 , V_3 ) ;
}
static T_2 F_11 ( struct V_20 * V_18 ,
struct V_21 * V_22 , const char * V_23 , T_3 V_25 )
{
int V_4 ;
unsigned int V_3 ;
struct V_8 * V_9 = F_9 ( V_18 ) ;
V_4 = F_12 ( V_23 , 0 , & V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_13 ( V_9 -> V_26 , V_24 , V_3 ) ;
if ( V_4 ) {
F_3 ( V_18 , L_7 ,
V_3 , V_24 ) ;
return - V_27 ;
}
return V_25 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_28 * V_29 ,
int V_30 , int V_31 ,
const struct V_32 * V_33 ,
struct V_28 * * V_34 )
{
int V_35 ;
V_35 = F_15 ( V_29 , V_30 ) ;
if ( V_35 < 0 ) {
F_3 ( V_9 -> V_18 ,
L_8 ,
V_30 , V_33 -> V_36 , V_35 ) ;
return V_35 ;
}
return F_16 ( V_9 -> V_18 , V_9 -> V_26 , V_35 , V_31 ,
0 , V_33 , V_34 ) ;
}
static int F_17 ( struct V_37 * V_38 )
{
int V_4 ;
T_4 V_39 ;
T_5 V_40 ;
unsigned long long V_41 ;
struct V_8 * V_9 ;
V_39 = F_18 ( & V_38 -> V_18 ) ;
V_40 = F_19 ( V_39 , L_9 , NULL , & V_41 ) ;
if ( F_20 ( V_40 ) ) {
F_3 ( & V_38 -> V_18 , L_10 ) ;
return - V_42 ;
}
if ( V_41 != V_43 ) {
F_3 ( & V_38 -> V_18 , L_11 ,
V_41 ) ;
return - V_42 ;
}
V_9 = F_21 ( & V_38 -> V_18 , sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return - V_45 ;
V_4 = F_22 ( V_38 , 0 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_38 -> V_18 , L_12 ) ;
return V_4 ;
}
V_9 -> V_35 = V_4 ;
F_23 ( & V_38 -> V_18 , V_9 ) ;
V_9 -> V_18 = & V_38 -> V_18 ;
V_9 -> V_26 = F_24 ( & V_38 -> V_18 , NULL , V_9 ,
& V_46 ) ;
if ( F_25 ( V_9 -> V_26 ) ) {
V_4 = F_26 ( V_9 -> V_26 ) ;
F_3 ( & V_38 -> V_18 , L_13 , V_4 ) ;
return V_4 ;
}
V_4 = F_16 ( & V_38 -> V_18 , V_9 -> V_26 , V_9 -> V_35 ,
V_47 | V_48 ,
0 , & V_49 ,
& V_9 -> V_50 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_14 ) ;
return V_4 ;
}
V_4 = F_14 ( V_9 , V_9 -> V_50 ,
V_51 ,
V_47 ,
& V_52 ,
& V_9 -> V_53 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_15 ) ;
return V_4 ;
}
V_4 = F_14 ( V_9 , V_9 -> V_50 ,
V_54 ,
V_47 ,
& V_55 ,
& V_9 -> V_56 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_16 ) ;
return V_4 ;
}
V_4 = F_14 ( V_9 , V_9 -> V_50 ,
V_57 ,
V_47 ,
& V_58 ,
& V_9 -> V_59 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_17 ) ;
return V_4 ;
}
V_4 = F_14 ( V_9 , V_9 -> V_50 ,
V_60 ,
V_47 ,
& V_61 ,
& V_9 -> V_62 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_18 ) ;
return V_4 ;
}
V_4 = F_14 ( V_9 , V_9 -> V_50 ,
V_63 ,
V_47 ,
& V_64 ,
& V_9 -> V_65 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_19 ) ;
return V_4 ;
}
V_4 = F_27 ( & V_38 -> V_18 , V_66 , V_67 ,
F_28 ( V_67 ) , NULL , 0 , NULL ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_20 ) ;
return V_4 ;
}
V_4 = F_29 ( & V_38 -> V_18 . V_68 , & V_69 ) ;
if ( V_4 ) {
F_3 ( & V_38 -> V_18 , L_21 , V_4 ) ;
return V_4 ;
}
F_30 ( V_9 -> V_26 , V_70 ,
V_71 , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
F_32 ( & V_38 -> V_18 . V_68 , & V_69 ) ;
return 0 ;
}
static void F_33 ( struct V_37 * V_38 )
{
struct V_8 * V_9 = F_9 ( & V_38 -> V_18 ) ;
F_34 ( V_9 -> V_35 ) ;
}
static int F_35 ( struct V_20 * V_18 )
{
struct V_8 * V_9 = F_9 ( V_18 ) ;
F_34 ( V_9 -> V_35 ) ;
return 0 ;
}
static int F_36 ( struct V_20 * V_18 )
{
struct V_8 * V_9 = F_9 ( V_18 ) ;
F_37 ( V_9 -> V_35 ) ;
return 0 ;
}
