static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( 10 , 20 ) ;
F_4 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_6 ;
V_6 = F_7 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_2 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_10 ( V_2 -> V_7 ) ;
return 0 ;
}
static bool
F_11 ( struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_11 * V_13 )
{
return true ;
}
static void F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_11 * V_14 )
{
}
static void F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_6 ;
T_1 V_15 ;
V_6 = F_14 ( V_2 -> V_8 -> V_16 , V_10 ) ;
if ( V_6 < 0 )
return;
if ( V_6 )
V_15 = V_17 | ( V_18 << 16 ) ;
else
V_15 = V_19 | ( V_18 << 16 ) ;
F_15 ( V_2 -> V_8 , L_3 , ( V_6 ) ? L_4 : L_5 ) ;
V_6 = F_16 ( V_2 -> V_20 , V_21 , V_15 ) ;
if ( V_6 != 0 ) {
F_8 ( V_2 -> V_8 , L_6 , V_6 ) ;
return;
}
}
static void F_17 ( struct V_9 * V_10 )
{
}
static int
F_18 ( struct V_9 * V_10 ,
struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_19 ( V_23 ) ;
V_27 -> V_28 = V_29 ;
V_27 -> V_30 = V_31 ;
return 0 ;
}
static void F_20 ( struct V_9 * V_10 )
{
F_21 ( V_10 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_8 = V_2 -> V_8 ;
struct V_33 * V_34 = V_8 -> V_16 ;
int V_6 ;
V_2 -> V_20 = F_23 ( V_34 , L_7 ) ;
if ( F_24 ( V_2 -> V_20 ) ) {
F_8 ( V_8 , L_8 ) ;
return F_25 ( V_2 -> V_20 ) ;
}
V_2 -> V_7 = F_26 ( V_8 , L_9 ) ;
if ( F_24 ( V_2 -> V_7 ) ) {
F_8 ( V_8 , L_10 ) ;
return F_25 ( V_2 -> V_7 ) ;
}
V_2 -> V_3 = F_27 ( V_8 , L_11 ) ;
if ( F_24 ( V_2 -> V_3 ) ) {
F_8 ( V_8 , L_12 ) ;
return F_25 ( V_2 -> V_3 ) ;
}
V_6 = F_7 ( V_2 -> V_7 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_2 -> V_8 , L_13 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_32 * V_8 = V_2 -> V_8 ;
int V_6 ;
V_10 -> V_37 = F_29 ( V_36 ,
V_8 -> V_16 ) ;
F_30 ( L_14 , V_10 -> V_37 ) ;
V_6 = F_31 ( V_36 , V_10 , & V_38 ,
V_39 , NULL ) ;
if ( V_6 ) {
F_32 ( L_15 ) ;
return V_6 ;
}
F_33 ( V_10 , & V_40 ) ;
return 0 ;
}
static int F_34 ( struct V_32 * V_8 , struct V_32 * V_41 ,
void * V_42 )
{
struct V_1 * V_2 = F_35 ( V_8 ) ;
struct V_35 * V_36 = V_42 ;
int V_6 ;
F_36 ( V_8 , NULL ) ;
V_6 = F_22 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_36 = V_36 ;
V_6 = F_28 ( V_2 ) ;
if ( V_6 ) {
F_32 ( L_16 ) ;
return V_6 ;
}
V_2 -> V_5 . V_10 = & V_2 -> V_10 ;
V_2 -> V_5 . V_43 = V_44 ;
V_2 -> V_5 . V_45 = F_5 ;
V_2 -> V_5 . V_46 = F_9 ;
return F_37 ( V_8 , V_2 -> V_36 , & V_2 -> V_5 ) ;
}
static void F_38 ( struct V_32 * V_8 , struct V_32 * V_41 ,
void * V_42 )
{
return F_39 ( V_8 , V_41 , V_42 ) ;
}
static int F_40 ( struct V_47 * V_48 )
{
struct V_32 * V_8 = & V_48 -> V_8 ;
struct V_33 * V_49 , * V_50 , * V_51 ;
struct V_1 * V_2 ;
struct V_52 * V_53 ;
V_50 = F_41 ( V_8 -> V_16 , 1 ) ;
if ( ! V_50 ) {
F_8 ( V_8 , L_17 ) ;
return - V_54 ;
}
V_51 = F_42 ( V_50 , L_18 ) ;
F_43 ( V_50 ) ;
if ( ! V_51 ) {
F_8 ( V_8 , L_19 ) ;
return - V_54 ;
}
V_49 = F_44 ( V_51 ) ;
F_43 ( V_51 ) ;
if ( ! V_49 ) {
F_8 ( V_8 , L_20 ) ;
return - V_54 ;
}
V_53 = F_45 ( V_49 ) ;
if ( ! V_53 ) {
F_32 ( L_21 ) ;
F_43 ( V_49 ) ;
return - V_55 ;
}
F_43 ( V_49 ) ;
V_2 = F_46 ( V_8 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_5 . V_53 = V_53 ;
F_47 ( V_48 , V_2 ) ;
return F_48 ( V_8 , & V_58 ) ;
}
static int F_49 ( struct V_47 * V_48 )
{
F_50 ( & V_48 -> V_8 , & V_58 ) ;
return 0 ;
}
static int F_51 ( struct V_32 * V_8 )
{
return F_52 ( V_8 ) ;
}
static int F_53 ( struct V_32 * V_8 )
{
return F_54 ( V_8 ) ;
}
