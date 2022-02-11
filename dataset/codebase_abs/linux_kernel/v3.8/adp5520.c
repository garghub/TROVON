static int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_2 ,
V_4 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_7 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_2 , V_3 , & V_10 ) ;
if ( ! V_5 ) {
V_10 |= V_7 ;
V_5 = F_4 ( V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
int F_10 ( struct V_12 * V_6 , int V_3 , T_1 V_4 )
{
return F_4 ( F_11 ( V_6 ) , V_3 , V_4 ) ;
}
int F_12 ( struct V_12 * V_6 , int V_3 , T_1 * V_4 )
{
return F_1 ( F_11 ( V_6 ) , V_3 , V_4 ) ;
}
int F_13 ( struct V_12 * V_6 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( ( V_10 & V_7 ) != V_7 ) ) {
V_10 |= V_7 ;
V_5 = F_4 ( V_9 -> V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
int F_15 ( struct V_12 * V_6 , int V_3 , T_1 V_7 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
T_1 V_10 ;
int V_5 ;
F_8 ( & V_9 -> V_11 ) ;
V_5 = F_1 ( V_9 -> V_2 , V_3 , & V_10 ) ;
if ( ! V_5 && ( V_10 & V_7 ) ) {
V_10 &= ~ V_7 ;
V_5 = F_4 ( V_9 -> V_2 , V_3 , V_10 ) ;
}
F_9 ( & V_9 -> V_11 ) ;
return V_5 ;
}
int F_16 ( struct V_12 * V_6 , struct V_13 * V_14 ,
unsigned int V_15 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
if ( V_9 -> V_16 ) {
F_13 ( V_9 -> V_6 , V_17 ,
V_15 & ( V_18 | V_19 |
V_20 | V_21 ) ) ;
return F_17 ( & V_9 -> V_22 ,
V_14 ) ;
}
return - V_23 ;
}
int F_18 ( struct V_12 * V_6 , struct V_13 * V_14 ,
unsigned int V_15 )
{
struct V_8 * V_9 = F_14 ( V_6 ) ;
F_15 ( V_9 -> V_6 , V_17 ,
V_15 & ( V_18 | V_19 |
V_20 | V_21 ) ) ;
return F_19 ( & V_9 -> V_22 , V_14 ) ;
}
static T_2 F_20 ( int V_16 , void * V_24 )
{
struct V_8 * V_9 = V_24 ;
unsigned int V_15 ;
T_1 V_10 ;
int V_5 ;
V_5 = F_1 ( V_9 -> V_2 , V_25 , & V_10 ) ;
if ( V_5 )
goto V_26;
V_15 = V_10 & ( V_27 | V_28 |
V_29 | V_30 | V_31 ) ;
F_21 ( & V_9 -> V_22 , V_15 , NULL ) ;
F_6 ( V_9 -> V_2 , V_25 , V_15 ) ;
V_26:
return V_32 ;
}
static int F_22 ( struct V_12 * V_6 , void * V_33 )
{
F_23 ( F_24 ( V_6 ) ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
return F_26 ( V_9 -> V_6 , NULL , F_22 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 = V_2 -> V_6 . V_38 ;
struct V_39 * V_40 ;
struct V_8 * V_9 ;
int V_5 ;
if ( ! F_28 ( V_2 -> V_41 ,
V_42 ) ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
return - V_43 ;
}
if ( V_37 == NULL ) {
F_3 ( & V_2 -> V_6 , L_4 ) ;
return - V_23 ;
}
V_9 = F_29 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return - V_45 ;
F_30 ( V_2 , V_9 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = & V_2 -> V_6 ;
V_9 -> V_16 = V_2 -> V_16 ;
V_9 -> V_35 = V_35 -> V_46 ;
F_31 ( & V_9 -> V_11 ) ;
if ( V_9 -> V_16 ) {
F_32 ( & V_9 -> V_22 ) ;
V_5 = F_33 ( V_9 -> V_16 , NULL , F_20 ,
V_47 | V_48 ,
L_5 , V_9 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_6 ,
V_9 -> V_16 ) ;
goto V_49;
}
}
V_5 = F_10 ( V_9 -> V_6 , V_25 , V_50 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
goto V_51;
}
if ( V_37 -> V_52 ) {
V_40 = F_34 ( V_9 -> V_6 , L_8 ,
V_9 -> V_35 , V_37 -> V_52 , sizeof( * V_37 -> V_52 ) ) ;
if ( F_35 ( V_40 ) ) {
V_5 = F_36 ( V_40 ) ;
goto V_53;
}
}
if ( V_37 -> V_54 ) {
V_40 = F_34 ( V_9 -> V_6 , L_9 ,
V_9 -> V_35 , V_37 -> V_54 , sizeof( * V_37 -> V_54 ) ) ;
if ( F_35 ( V_40 ) ) {
V_5 = F_36 ( V_40 ) ;
goto V_53;
}
}
if ( V_37 -> V_55 ) {
V_40 = F_34 ( V_9 -> V_6 , L_10 ,
V_9 -> V_35 , V_37 -> V_55 , sizeof( * V_37 -> V_55 ) ) ;
if ( F_35 ( V_40 ) ) {
V_5 = F_36 ( V_40 ) ;
goto V_53;
}
}
if ( V_37 -> V_56 ) {
V_40 = F_34 ( V_9 -> V_6 ,
L_11 ,
V_9 -> V_35 ,
V_37 -> V_56 ,
sizeof( * V_37 -> V_56 ) ) ;
if ( F_35 ( V_40 ) ) {
V_5 = F_36 ( V_40 ) ;
goto V_53;
}
}
return 0 ;
V_53:
F_25 ( V_9 ) ;
V_51:
if ( V_9 -> V_16 )
F_37 ( V_9 -> V_16 , V_9 ) ;
V_49:
F_38 ( V_9 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_14 ( & V_2 -> V_6 ) ;
if ( V_9 -> V_16 )
F_37 ( V_9 -> V_16 , V_9 ) ;
F_25 ( V_9 ) ;
F_10 ( V_9 -> V_6 , V_25 , 0 ) ;
F_38 ( V_9 ) ;
return 0 ;
}
static int F_40 ( struct V_12 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_8 * V_9 = F_14 ( & V_2 -> V_6 ) ;
F_15 ( V_9 -> V_6 , V_25 , V_50 ) ;
return 0 ;
}
static int F_41 ( struct V_12 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_8 * V_9 = F_14 ( & V_2 -> V_6 ) ;
F_13 ( V_9 -> V_6 , V_25 , V_50 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_57 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_57 ) ;
}
