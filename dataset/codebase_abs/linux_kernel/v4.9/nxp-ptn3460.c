static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_6 , char V_7 ,
T_1 * V_8 , int V_9 )
{
int V_10 ;
V_10 = F_5 ( V_6 -> V_11 , & V_7 , 1 ) ;
if ( V_10 <= 0 ) {
F_6 ( L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_7 ( V_6 -> V_11 , V_8 , V_9 ) ;
if ( V_10 <= 0 ) {
F_6 ( L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_6 , char V_7 ,
char V_12 )
{
int V_10 ;
char V_8 [ 2 ] ;
V_8 [ 0 ] = V_7 ;
V_8 [ 1 ] = V_12 ;
V_10 = F_5 ( V_6 -> V_11 , V_8 , F_9 ( V_8 ) ) ;
if ( V_10 <= 0 ) {
F_6 ( L_1 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_6 )
{
int V_10 ;
char V_12 ;
V_10 = F_8 ( V_6 , V_13 ,
V_6 -> V_14 ) ;
if ( V_10 ) {
F_6 ( L_3 , V_10 ) ;
return V_10 ;
}
V_12 = 1 << V_15 |
V_6 -> V_14 << V_16 ;
V_10 = F_8 ( V_6 , V_17 , V_12 ) ;
if ( V_10 ) {
F_6 ( L_4 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_10 ;
if ( V_6 -> V_18 )
return;
F_12 ( V_6 -> V_19 , 1 ) ;
F_12 ( V_6 -> V_20 , 0 ) ;
F_13 ( 10 , 20 ) ;
F_12 ( V_6 -> V_20 , 1 ) ;
if ( F_14 ( V_6 -> V_21 ) ) {
F_6 ( L_5 ) ;
return;
}
F_15 ( 90 ) ;
V_10 = F_10 ( V_6 ) ;
if ( V_10 )
F_6 ( L_6 , V_10 ) ;
V_6 -> V_18 = true ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_17 ( V_6 -> V_21 ) ) {
F_6 ( L_7 ) ;
return;
}
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( ! V_6 -> V_18 )
return;
V_6 -> V_18 = false ;
if ( F_19 ( V_6 -> V_21 ) ) {
F_6 ( L_8 ) ;
return;
}
F_12 ( V_6 -> V_20 , 1 ) ;
F_12 ( V_6 -> V_19 , 0 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_21 ( V_6 -> V_21 ) ) {
F_6 ( L_9 ) ;
return;
}
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_6 ;
T_1 * V_22 ;
int V_10 , V_23 = 0 ;
bool V_24 ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 -> V_22 )
return F_23 ( V_5 , V_6 -> V_22 ) ;
V_24 = ! V_6 -> V_18 ;
F_11 ( & V_6 -> V_3 ) ;
V_22 = F_24 ( V_25 , V_26 ) ;
if ( ! V_22 ) {
F_6 ( L_10 ) ;
return 0 ;
}
V_10 = F_4 ( V_6 , V_27 , V_22 ,
V_25 ) ;
if ( V_10 ) {
F_25 ( V_22 ) ;
goto V_28;
}
V_6 -> V_22 = (struct V_22 * ) V_22 ;
F_26 ( V_5 , V_6 -> V_22 ) ;
V_23 = F_23 ( V_5 , V_6 -> V_22 ) ;
V_28:
if ( V_24 )
F_18 ( & V_6 -> V_3 ) ;
return V_23 ;
}
static enum V_29 F_27 ( struct V_4 * V_5 ,
bool V_30 )
{
return V_31 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_10 ;
if ( ! V_3 -> V_32 ) {
F_6 ( L_11 ) ;
return - V_33 ;
}
V_6 -> V_5 . V_34 = V_35 ;
V_10 = F_29 ( V_3 -> V_36 , & V_6 -> V_5 ,
& V_37 , V_38 ) ;
if ( V_10 ) {
F_6 ( L_12 ) ;
return V_10 ;
}
F_30 ( & V_6 -> V_5 ,
& V_39 ) ;
F_31 ( & V_6 -> V_5 ) ;
F_32 ( & V_6 -> V_5 ,
V_3 -> V_32 ) ;
if ( V_6 -> V_21 )
F_33 ( V_6 -> V_21 , & V_6 -> V_5 ) ;
F_34 ( V_6 -> V_5 . V_36 ) ;
return V_10 ;
}
static int F_35 ( struct V_40 * V_11 ,
const struct V_41 * V_42 )
{
struct V_43 * V_36 = & V_11 -> V_36 ;
struct V_1 * V_6 ;
struct V_44 * V_45 , * V_46 ;
int V_10 ;
V_6 = F_36 ( V_36 , sizeof( * V_6 ) , V_26 ) ;
if ( ! V_6 ) {
return - V_47 ;
}
V_45 = F_37 ( V_36 -> V_48 , NULL ) ;
if ( V_45 ) {
V_46 = F_38 ( V_45 ) ;
if ( V_46 ) {
V_6 -> V_21 = F_39 ( V_46 ) ;
F_40 ( V_46 ) ;
if ( ! V_6 -> V_21 )
return - V_49 ;
}
}
V_6 -> V_11 = V_11 ;
V_6 -> V_19 = F_41 ( & V_11 -> V_36 , L_13 ,
V_50 ) ;
if ( F_42 ( V_6 -> V_19 ) ) {
V_10 = F_43 ( V_6 -> V_19 ) ;
F_44 ( V_36 , L_14 , V_10 ) ;
return V_10 ;
}
V_6 -> V_20 = F_41 ( & V_11 -> V_36 , L_15 ,
V_51 ) ;
if ( F_42 ( V_6 -> V_20 ) ) {
V_10 = F_43 ( V_6 -> V_20 ) ;
F_6 ( L_16 , V_10 ) ;
return V_10 ;
}
V_10 = F_45 ( V_36 -> V_48 , L_17 ,
& V_6 -> V_14 ) ;
if ( V_10 ) {
F_44 ( V_36 , L_18 ) ;
return V_10 ;
}
V_6 -> V_3 . V_52 = & V_53 ;
V_6 -> V_3 . V_48 = V_36 -> V_48 ;
V_10 = F_46 ( & V_6 -> V_3 ) ;
if ( V_10 ) {
F_6 ( L_19 ) ;
return V_10 ;
}
F_47 ( V_11 , V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_40 * V_11 )
{
struct V_1 * V_6 = F_49 ( V_11 ) ;
F_50 ( & V_6 -> V_3 ) ;
return 0 ;
}
