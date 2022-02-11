static int F_1 ( struct V_1 * V_2 , char V_3 ,
T_1 * V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , & V_3 , 1 ) ;
if ( V_6 <= 0 ) {
F_3 ( L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_4 ( V_2 -> V_7 , V_4 , V_5 ) ;
if ( V_6 <= 0 ) {
F_3 ( L_2 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , char V_3 ,
char V_8 )
{
int V_6 ;
char V_4 [ 2 ] ;
V_4 [ 0 ] = V_3 ;
V_4 [ 1 ] = V_8 ;
V_6 = F_2 ( V_2 -> V_7 , V_4 , F_6 ( V_4 ) ) ;
if ( V_6 <= 0 ) {
F_3 ( L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_6 ;
char V_8 ;
V_6 = F_5 ( V_2 , V_9 ,
V_2 -> V_10 ) ;
if ( V_6 ) {
F_3 ( L_3 , V_6 ) ;
return V_6 ;
}
V_8 = 1 << V_11 |
V_2 -> V_10 << V_12 ;
V_6 = F_5 ( V_2 , V_13 , V_8 ) ;
if ( V_6 ) {
F_3 ( L_4 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_6 ;
if ( V_2 -> V_17 )
return;
if ( F_9 ( V_2 -> V_18 ) )
F_10 ( V_2 -> V_18 , 1 ) ;
if ( F_9 ( V_2 -> V_19 ) ) {
F_10 ( V_2 -> V_19 , 0 ) ;
F_11 ( 10 ) ;
F_10 ( V_2 -> V_19 , 1 ) ;
}
F_12 ( 90 ) ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
F_3 ( L_5 , V_6 ) ;
V_2 -> V_17 = true ;
}
static void F_13 ( struct V_14 * V_15 )
{
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( ! V_2 -> V_17 )
return;
V_2 -> V_17 = false ;
if ( F_9 ( V_2 -> V_19 ) )
F_10 ( V_2 -> V_19 , 1 ) ;
if ( F_9 ( V_2 -> V_18 ) )
F_10 ( V_2 -> V_18 , 0 ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
}
void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_17 ( V_15 ) ;
if ( F_9 ( V_2 -> V_18 ) )
F_18 ( V_2 -> V_18 ) ;
if ( F_9 ( V_2 -> V_19 ) )
F_18 ( V_2 -> V_19 ) ;
}
int F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
T_1 * V_22 ;
int V_6 , V_23 ;
bool V_24 ;
V_2 = F_20 ( V_21 , struct V_1 , V_21 ) ;
if ( V_2 -> V_22 )
return F_21 ( V_21 , V_2 -> V_22 ) ;
V_24 = ! V_2 -> V_17 ;
F_8 ( V_2 -> V_15 ) ;
V_22 = F_22 ( V_25 , V_26 ) ;
if ( ! V_22 ) {
F_3 ( L_6 ) ;
return 0 ;
}
V_6 = F_1 ( V_2 , V_27 , V_22 ,
V_25 ) ;
if ( V_6 ) {
F_23 ( V_22 ) ;
V_23 = 0 ;
goto V_28;
}
V_2 -> V_22 = (struct V_22 * ) V_22 ;
F_24 ( V_21 , V_2 -> V_22 ) ;
V_23 = F_21 ( V_21 , V_2 -> V_22 ) ;
V_28:
if ( V_24 )
F_14 ( V_2 -> V_15 ) ;
return V_23 ;
}
static int F_25 ( struct V_20 * V_21 ,
struct V_29 * V_30 )
{
return V_31 ;
}
struct V_32 * F_26 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
V_2 = F_20 ( V_21 , struct V_1 , V_21 ) ;
return V_2 -> V_33 ;
}
enum V_34 F_27 ( struct V_20 * V_21 ,
bool V_35 )
{
return V_36 ;
}
void F_28 ( struct V_20 * V_21 )
{
F_29 ( V_21 ) ;
}
int F_30 ( struct V_37 * V_38 , struct V_32 * V_33 ,
struct V_39 * V_7 , struct V_40 * V_41 )
{
int V_6 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = F_31 ( V_38 -> V_38 , sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 ) {
F_3 ( L_7 ) ;
return - V_42 ;
}
V_2 = F_31 ( V_38 -> V_38 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_3 ( L_8 ) ;
return - V_42 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_18 = F_32 ( V_41 , L_9 , 0 ) ;
if ( F_9 ( V_2 -> V_18 ) ) {
V_6 = F_33 ( V_2 -> V_18 ,
V_43 , L_10 ) ;
if ( V_6 ) {
F_3 ( L_11 , V_6 ) ;
return V_6 ;
}
}
V_2 -> V_19 = F_32 ( V_41 , L_12 , 0 ) ;
if ( F_9 ( V_2 -> V_19 ) ) {
V_6 = F_33 ( V_2 -> V_19 ,
V_44 , L_13 ) ;
if ( V_6 ) {
F_3 ( L_14 , V_6 ) ;
F_18 ( V_2 -> V_18 ) ;
return V_6 ;
}
}
V_6 = F_34 ( V_41 , L_15 ,
& V_2 -> V_10 ) ;
if ( V_6 ) {
F_3 ( L_16 ) ;
goto V_45;
}
V_6 = F_35 ( V_38 , V_15 , & V_46 ) ;
if ( V_6 ) {
F_3 ( L_17 ) ;
goto V_45;
}
V_15 -> V_16 = V_2 ;
V_33 -> V_15 = V_15 ;
V_6 = F_36 ( V_38 , & V_2 -> V_21 ,
& V_47 , V_48 ) ;
if ( V_6 ) {
F_3 ( L_18 ) ;
goto V_45;
}
F_37 ( & V_2 -> V_21 ,
& V_49 ) ;
F_38 ( & V_2 -> V_21 ) ;
F_39 ( & V_2 -> V_21 , V_33 ) ;
return 0 ;
V_45:
if ( F_9 ( V_2 -> V_18 ) )
F_18 ( V_2 -> V_18 ) ;
if ( F_9 ( V_2 -> V_19 ) )
F_18 ( V_2 -> V_19 ) ;
return V_6 ;
}
