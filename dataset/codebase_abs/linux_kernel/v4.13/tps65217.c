static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 , V_7 , V_8 ,
V_4 -> V_9 , V_10 ) ;
if ( V_6 != 0 )
F_6 ( V_4 -> V_11 , L_1 ) ;
F_7 ( & V_4 -> V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 = F_9 ( V_2 -> V_13 ) << V_14 ;
V_4 -> V_9 &= ~ V_12 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_12 = F_9 ( V_2 -> V_13 ) << V_14 ;
V_4 -> V_9 |= V_12 ;
}
static T_2 F_11 ( int V_15 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_16 ;
bool V_17 = false ;
int V_18 ;
int V_6 ;
V_6 = F_12 ( V_4 , V_7 , & V_16 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_11 , L_2 ,
V_6 ) ;
return V_19 ;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_16 & F_9 ( V_18 ) ) {
F_13 ( F_14 ( V_4 -> V_21 , V_18 ) ) ;
V_17 = true ;
}
}
if ( V_17 )
return V_22 ;
return V_19 ;
}
static int F_15 ( struct V_21 * V_23 , unsigned int V_24 ,
T_3 V_25 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
F_16 ( V_24 , V_4 ) ;
F_17 ( V_24 , & V_27 , V_28 ) ;
F_18 ( V_24 , 1 ) ;
F_19 ( V_24 , V_4 -> V_15 ) ;
F_20 ( V_24 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 , int V_15 )
{
int V_6 ;
F_22 ( & V_4 -> V_5 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_9 = V_8 ;
F_5 ( V_4 , V_7 , V_8 ,
V_8 , V_10 ) ;
V_4 -> V_21 = F_23 ( V_4 -> V_11 -> V_29 ,
V_20 , & V_30 , V_4 ) ;
if ( ! V_4 -> V_21 ) {
F_6 ( V_4 -> V_11 , L_3 ) ;
return - V_31 ;
}
V_6 = F_24 ( V_4 -> V_11 , V_15 , NULL ,
F_11 , V_32 ,
L_4 , V_4 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_11 , L_5 ,
V_15 , V_6 ) ;
return V_6 ;
}
F_25 ( V_15 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 , unsigned int V_33 ,
unsigned int * V_34 )
{
return F_26 ( V_4 -> V_35 , V_33 , V_34 ) ;
}
int F_27 ( struct V_3 * V_4 , unsigned int V_33 ,
unsigned int V_34 , unsigned int V_36 )
{
int V_6 ;
unsigned int V_37 ;
switch ( V_36 ) {
case V_10 :
return F_28 ( V_4 -> V_35 , V_33 , V_34 ) ;
case V_38 :
V_37 = V_33 ^ V_39 ;
V_6 = F_28 ( V_4 -> V_35 , V_40 ,
V_37 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_28 ( V_4 -> V_35 , V_33 , V_34 ) ;
case V_41 :
V_37 = V_33 ^ V_39 ;
V_6 = F_28 ( V_4 -> V_35 , V_40 ,
V_37 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_28 ( V_4 -> V_35 , V_33 , V_34 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_28 ( V_4 -> V_35 , V_40 ,
V_37 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_28 ( V_4 -> V_35 , V_33 , V_34 ) ;
default:
return - V_42 ;
}
}
static int F_29 ( struct V_3 * V_4 , unsigned int V_33 ,
unsigned int V_12 , unsigned int V_34 , unsigned int V_36 )
{
int V_6 ;
unsigned int V_2 ;
V_6 = F_12 ( V_4 , V_33 , & V_2 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_11 , L_6 , V_33 ) ;
return V_6 ;
}
V_2 &= ~ V_12 ;
V_2 |= V_34 & V_12 ;
V_6 = F_27 ( V_4 , V_33 , V_2 , V_36 ) ;
if ( V_6 )
F_6 ( V_4 -> V_11 , L_7 , V_33 ) ;
return V_6 ;
}
int F_5 ( struct V_3 * V_4 , unsigned int V_33 ,
unsigned int V_12 , unsigned int V_34 , unsigned int V_36 )
{
return F_29 ( V_4 , V_33 , V_12 , V_34 , V_36 ) ;
}
int F_30 ( struct V_3 * V_4 , unsigned int V_33 ,
unsigned int V_12 , unsigned int V_36 )
{
return F_29 ( V_4 , V_33 , V_12 , 0 , V_36 ) ;
}
static bool F_31 ( struct V_43 * V_11 , unsigned int V_33 )
{
switch ( V_33 ) {
case V_7 :
return true ;
default:
return false ;
}
}
static int F_32 ( struct V_44 * V_45 ,
const struct V_46 * V_47 )
{
struct V_3 * V_4 ;
unsigned int V_48 ;
unsigned long V_49 = V_47 -> V_50 ;
const struct V_51 * V_52 ;
bool V_53 = false ;
int V_6 ;
if ( V_45 -> V_11 . V_29 ) {
V_52 = F_33 ( V_54 , & V_45 -> V_11 ) ;
if ( ! V_52 ) {
F_6 ( & V_45 -> V_11 ,
L_8 ) ;
return - V_42 ;
}
V_49 = ( unsigned long ) V_52 -> V_2 ;
V_53 = F_34 ( V_45 -> V_11 . V_29 ,
L_9 ) ;
}
if ( ! V_49 ) {
F_6 ( & V_45 -> V_11 , L_10 ) ;
return - V_55 ;
}
V_4 = F_35 ( & V_45 -> V_11 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return - V_31 ;
F_36 ( V_45 , V_4 ) ;
V_4 -> V_11 = & V_45 -> V_11 ;
V_4 -> V_57 = V_49 ;
V_4 -> V_35 = F_37 ( V_45 , & V_58 ) ;
if ( F_38 ( V_4 -> V_35 ) ) {
V_6 = F_39 ( V_4 -> V_35 ) ;
F_6 ( V_4 -> V_11 , L_11 ,
V_6 ) ;
return V_6 ;
}
if ( V_45 -> V_15 ) {
F_21 ( V_4 , V_45 -> V_15 ) ;
} else {
int V_18 ;
for ( V_18 = 0 ; V_18 < F_40 ( V_59 ) ; V_18 ++ )
V_59 [ V_18 ] . V_60 = 0 ;
}
V_6 = F_41 ( V_4 -> V_11 , - 1 , V_59 ,
F_40 ( V_59 ) , NULL , 0 ,
V_4 -> V_21 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_11 , L_12 , V_6 ) ;
return V_6 ;
}
V_6 = F_12 ( V_4 , V_61 , & V_48 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_11 , L_13 ,
V_6 ) ;
return V_6 ;
}
if ( V_53 ) {
V_6 = F_5 ( V_4 , V_62 ,
V_63 , V_63 ,
V_10 ) ;
if ( V_6 )
F_42 ( V_4 -> V_11 , L_14 ) ;
}
F_43 ( V_4 -> V_11 , L_15 ,
( V_48 & V_64 ) >> 4 ,
V_48 & V_65 ) ;
return 0 ;
}
static int F_44 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_45 ( V_45 ) ;
unsigned int V_24 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_24 = F_14 ( V_4 -> V_21 , V_18 ) ;
if ( V_24 )
F_46 ( V_24 ) ;
}
F_47 ( V_4 -> V_21 ) ;
V_4 -> V_21 = NULL ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_66 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_66 ) ;
}
