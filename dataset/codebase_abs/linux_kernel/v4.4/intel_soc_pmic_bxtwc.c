static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 [ 2 ] ;
T_1 V_7 [ 4 ] ;
struct V_8 * V_9 = V_1 ;
if ( V_2 & V_10 )
V_5 = ( V_2 & V_10 ) >> V_11 ;
else {
V_5 = V_12 ;
if ( ! V_5 ) {
F_2 ( V_9 -> V_13 , L_1 ) ;
return - V_14 ;
}
}
V_2 &= V_15 ;
V_6 [ 0 ] = V_2 ;
V_6 [ 1 ] = V_5 ;
V_4 = F_3 ( V_16 ,
V_17 ,
V_6 , sizeof( V_6 ) , ( V_18 * ) V_7 , 1 ) ;
if ( V_4 ) {
F_2 ( V_9 -> V_13 , L_2 ) ;
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
if ( V_2 & V_10 )
V_5 = ( V_2 & V_10 ) >> V_11 ;
else {
V_5 = V_12 ;
if ( ! V_5 ) {
F_2 ( V_9 -> V_13 , L_1 ) ;
return - V_14 ;
}
}
V_2 &= V_15 ;
V_6 [ 0 ] = V_2 ;
V_6 [ 1 ] = V_5 ;
V_6 [ 2 ] = V_3 ;
V_4 = F_3 ( V_16 ,
V_19 ,
V_6 , sizeof( V_6 ) , NULL , 0 ) ;
if ( V_4 ) {
F_2 ( V_9 -> V_13 , L_3 ) ;
return V_4 ;
}
return 0 ;
}
static T_2 F_5 ( struct V_20 * V_13 ,
struct V_21 * V_22 , char * V_23 )
{
return sprintf ( V_23 , L_4 , V_24 ) ;
}
static T_2 F_6 ( struct V_20 * V_13 ,
struct V_21 * V_22 , const char * V_23 , T_3 V_25 )
{
if ( F_7 ( V_23 , 0 , & V_24 ) ) {
F_2 ( V_13 , L_5 ) ;
return - V_14 ;
}
return ( T_2 ) V_25 ;
}
static T_2 F_8 ( struct V_20 * V_13 ,
struct V_21 * V_22 , char * V_23 )
{
int V_4 ;
unsigned int V_3 ;
struct V_8 * V_9 = F_9 ( V_13 ) ;
V_4 = F_10 ( V_9 -> V_26 , V_24 , & V_3 ) ;
if ( V_4 < 0 ) {
F_2 ( V_13 , L_6 , V_24 ) ;
return - V_27 ;
}
return sprintf ( V_23 , L_7 , V_3 ) ;
}
static T_2 F_11 ( struct V_20 * V_13 ,
struct V_21 * V_22 , const char * V_23 , T_3 V_25 )
{
int V_4 ;
unsigned int V_3 ;
struct V_8 * V_9 = F_9 ( V_13 ) ;
V_4 = F_12 ( V_23 , 0 , & V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_13 ( V_9 -> V_26 , V_24 , V_3 ) ;
if ( V_4 ) {
F_2 ( V_13 , L_8 ,
V_3 , V_24 ) ;
return - V_27 ;
}
return V_25 ;
}
static int F_14 ( struct V_28 * V_29 )
{
int V_4 ;
T_4 V_30 ;
T_5 V_31 ;
unsigned long long V_32 ;
struct V_8 * V_9 ;
V_30 = F_15 ( & V_29 -> V_13 ) ;
V_31 = F_16 ( V_30 , L_9 , NULL , & V_32 ) ;
if ( F_17 ( V_31 ) ) {
F_2 ( & V_29 -> V_13 , L_10 ) ;
return - V_33 ;
}
if ( V_32 != V_34 ) {
F_2 ( & V_29 -> V_13 , L_11 ,
V_32 ) ;
return - V_33 ;
}
V_9 = F_18 ( & V_29 -> V_13 , sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_4 = F_19 ( V_29 , 0 ) ;
if ( V_4 < 0 ) {
F_2 ( & V_29 -> V_13 , L_12 ) ;
return V_4 ;
}
V_9 -> V_37 = V_4 ;
F_20 ( & V_29 -> V_13 , V_9 ) ;
V_9 -> V_13 = & V_29 -> V_13 ;
V_9 -> V_26 = F_21 ( & V_29 -> V_13 , NULL , V_9 ,
& V_38 ) ;
if ( F_22 ( V_9 -> V_26 ) ) {
V_4 = F_23 ( V_9 -> V_26 ) ;
F_2 ( & V_29 -> V_13 , L_13 , V_4 ) ;
return V_4 ;
}
V_4 = F_24 ( V_9 -> V_26 , V_9 -> V_37 ,
V_39 | V_40 ,
0 , & V_41 ,
& V_9 -> V_42 ) ;
if ( V_4 ) {
F_2 ( & V_29 -> V_13 , L_14 ) ;
return V_4 ;
}
V_4 = F_24 ( V_9 -> V_26 , V_9 -> V_37 ,
V_39 | V_40 ,
0 , & V_43 ,
& V_9 -> V_44 ) ;
if ( V_4 ) {
F_2 ( & V_29 -> V_13 , L_15 ) ;
goto V_45;
}
V_4 = F_25 ( & V_29 -> V_13 , V_46 , V_47 ,
F_26 ( V_47 ) , NULL , 0 ,
NULL ) ;
if ( V_4 ) {
F_2 ( & V_29 -> V_13 , L_16 ) ;
goto V_48;
}
V_4 = F_27 ( & V_29 -> V_13 . V_49 , & V_50 ) ;
if ( V_4 ) {
F_2 ( & V_29 -> V_13 , L_17 , V_4 ) ;
goto V_51;
}
return 0 ;
V_51:
F_28 ( & V_29 -> V_13 ) ;
V_48:
F_29 ( V_9 -> V_37 , V_9 -> V_44 ) ;
V_45:
F_29 ( V_9 -> V_37 , V_9 -> V_42 ) ;
return V_4 ;
}
static int F_30 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_9 ( & V_29 -> V_13 ) ;
F_31 ( & V_29 -> V_13 . V_49 , & V_50 ) ;
F_28 ( & V_29 -> V_13 ) ;
F_29 ( V_9 -> V_37 , V_9 -> V_42 ) ;
F_29 ( V_9 -> V_37 , V_9 -> V_44 ) ;
return 0 ;
}
static void F_32 ( struct V_28 * V_29 )
{
struct V_8 * V_9 = F_9 ( & V_29 -> V_13 ) ;
F_33 ( V_9 -> V_37 ) ;
}
static int F_34 ( struct V_20 * V_13 )
{
struct V_8 * V_9 = F_9 ( V_13 ) ;
F_33 ( V_9 -> V_37 ) ;
return 0 ;
}
static int F_35 ( struct V_20 * V_13 )
{
struct V_8 * V_9 = F_9 ( V_13 ) ;
F_36 ( V_9 -> V_37 ) ;
return 0 ;
}
