void T_1 F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
}
static int F_2 ( struct V_4 * V_5 ,
unsigned int V_6 ,
void * V_7 , int V_8 )
{
return F_3 ( V_5 -> V_9 , V_7 , V_6 , V_8 ) ;
}
static int F_4 ( struct V_4 * V_5 ,
unsigned int V_6 ,
const void * V_10 , int V_8 )
{
return F_5 ( V_5 -> V_9 , V_6 , ( void * ) V_10 , V_8 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
F_7 ( V_5 -> V_9 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_9 ( V_5 -> V_9 ) ;
}
static void F_10 ( struct V_11 * V_9 )
{
struct V_4 * V_5 = F_11 ( V_9 ) ;
if ( V_5 -> V_12 )
F_12 ( V_5 -> V_12 ) ;
}
static T_2 F_13 ( int V_13 , void * V_14 )
{
return V_15 ;
}
static T_2 F_14 ( int V_13 , void * V_14 )
{
struct V_4 * V_5 = V_14 ;
if ( V_5 -> V_12 ) {
F_6 ( V_5 ) ;
F_12 ( V_5 -> V_12 ) ;
F_8 ( V_5 ) ;
return V_16 ;
} else {
return V_17 ;
}
}
static int F_15 ( struct V_4 * V_5 )
{
int V_18 ;
T_3 V_19 ;
V_19 = F_16 ( V_5 -> V_9 , V_20 , & V_18 ) ;
if ( F_17 ( V_18 ) )
goto V_21;
V_19 |= F_18 ( 0 ) ;
V_19 |= F_18 ( V_5 -> V_9 -> V_22 ) ;
F_19 ( V_5 -> V_9 , V_19 , V_20 , & V_18 ) ;
if ( F_17 ( V_18 ) )
goto V_21;
V_18 = F_20 ( V_5 -> V_2 -> V_13 ) ;
if ( F_17 ( V_18 ) )
goto V_21;
V_18 = F_21 ( V_5 -> V_2 -> V_13 , F_13 ,
F_14 ,
V_23 | V_24 ,
L_1 , V_5 ) ;
if ( F_17 ( V_18 ) )
goto V_21;
return 0 ;
V_21:
return V_18 ;
}
static int F_22 ( struct V_4 * V_5 )
{
int V_18 = 0 ;
F_23 ( L_2 ) ;
F_7 ( V_5 -> V_9 ) ;
if ( V_5 -> V_2 -> V_13 )
V_18 = F_15 ( V_5 ) ;
else
V_18 = F_24 ( V_5 -> V_9 , F_10 ) ;
F_9 ( V_5 -> V_9 ) ;
return V_18 ;
}
static int F_25 ( struct V_4 * V_5 )
{
int V_18 = 0 ;
F_23 ( L_3 ) ;
if ( V_5 -> V_2 -> V_13 ) {
F_26 ( V_5 -> V_2 -> V_13 ) ;
F_27 ( V_5 -> V_2 -> V_13 , V_5 ) ;
} else {
F_7 ( V_5 -> V_9 ) ;
V_18 = F_28 ( V_5 -> V_9 ) ;
F_9 ( V_5 -> V_9 ) ;
}
return V_18 ;
}
static int F_29 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_25 ) {
F_30 ( V_2 -> V_25 , 0 ) ;
F_31 ( 30 ) ;
F_32 ( V_2 -> V_25 ) ;
}
if ( V_2 -> V_26 )
V_2 -> V_26 ( V_2 , false ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 , false ) ;
return 0 ;
}
static int F_33 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_25 ) {
F_34 ( V_2 -> V_25 , L_4 ) ;
F_35 ( V_2 -> V_25 , 0 ) ;
}
if ( V_2 -> V_28 ) {
F_34 ( V_2 -> V_28 , L_5 ) ;
F_35 ( V_2 -> V_28 , 0 ) ;
}
if ( V_2 -> V_25 || V_2 -> V_28 )
F_31 ( 10 ) ;
if ( V_2 -> V_26 ) {
if ( V_2 -> V_26 ( V_2 , true ) ) {
F_36 ( L_6 ) ;
return - 1 ;
}
}
if ( V_2 -> V_27 ) {
if ( V_2 -> V_27 ( V_2 , true ) ) {
F_36 ( L_7 ) ;
return - 1 ;
}
F_31 ( 10 ) ;
}
if ( V_2 -> V_28 ) {
F_30 ( V_2 -> V_28 , 1 ) ;
F_31 ( 250 ) ;
}
if ( V_2 -> V_25 ) {
F_30 ( V_2 -> V_25 , 1 ) ;
F_31 ( 50 ) ;
}
return 0 ;
}
static T_4 F_37 ( struct V_4 * V_5 , T_4 V_29 )
{
if ( V_5 -> V_2 -> V_30 )
V_29 = F_38 ( V_29 , V_31 ) ;
else
V_29 = F_39 ( V_5 -> V_9 , V_29 ) ;
return V_29 ;
}
static int F_40 ( struct V_4 * V_5 , bool V_32 )
{
int V_18 = 0 ;
if ( V_5 -> V_2 -> V_13 )
V_18 = F_41 ( V_5 -> V_2 -> V_13 , V_32 ) ;
return V_18 ;
}
static int F_42 ( struct V_11 * V_9 ,
const struct V_33 * V_34 )
{
struct V_4 * V_5 ;
int V_35 ;
F_43 ( L_8 ) ;
if ( V_9 -> V_22 != 0x01 )
return - V_36 ;
V_5 = F_44 ( sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 ) {
F_36 ( L_9 ) ;
return - V_38 ;
}
V_9 -> V_39 -> V_40 |= V_41 ;
V_5 -> V_2 = V_3 ;
V_5 -> V_9 = V_9 ;
F_45 ( V_9 , V_5 ) ;
F_7 ( V_9 ) ;
F_46 ( V_9 ) ;
F_9 ( V_9 ) ;
V_35 = F_22 ( V_5 ) ;
V_35 = F_47 ( & V_42 ,
V_5 , & V_9 -> V_43 , & V_5 -> V_12 ,
V_5 -> V_2 -> V_44 ,
V_5 -> V_2 -> V_45 ,
V_5 -> V_2 -> V_46 ,
V_5 -> V_2 -> V_47 ) ;
if ( V_35 ) {
F_25 ( V_5 ) ;
F_7 ( V_9 ) ;
F_48 ( V_9 ) ;
F_9 ( V_9 ) ;
F_45 ( V_9 , NULL ) ;
F_49 ( V_5 ) ;
}
return V_35 ;
}
static void F_50 ( struct V_11 * V_9 )
{
struct V_4 * V_5 = F_11 ( V_9 ) ;
if ( V_5 ) {
F_25 ( V_5 ) ;
if ( V_5 -> V_12 ) {
F_51 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
}
F_7 ( V_9 ) ;
F_48 ( V_9 ) ;
F_9 ( V_9 ) ;
F_45 ( V_9 , NULL ) ;
F_49 ( V_5 ) ;
}
}
static int F_52 ( struct V_48 * V_43 )
{
int V_18 ;
struct V_11 * V_9 = F_53 ( V_43 ) ;
struct V_4 * V_5 = F_11 ( V_9 ) ;
if ( ! F_54 ( V_5 -> V_12 ) )
return - V_49 ;
V_18 = F_55 ( V_9 , V_50 ) ;
if ( V_18 )
F_36 ( L_10 , V_18 ) ;
return V_18 ;
}
static int F_56 ( struct V_48 * V_43 )
{
return 0 ;
}
static int T_1 F_57 ( void )
{
const struct V_1 * V_2 ;
int V_18 ;
V_2 = V_3 ;
if ( F_33 ( V_2 ) ) {
V_18 = - 1 ;
goto V_21;
}
V_18 = F_58 ( & V_51 ) ;
if ( V_18 )
goto V_21;
return 0 ;
V_21:
F_29 ( V_2 ) ;
return V_18 ;
}
static void T_5 F_59 ( void )
{
const struct V_1 * V_2 ;
V_2 = V_3 ;
F_60 ( & V_51 ) ;
F_29 ( V_2 ) ;
}
