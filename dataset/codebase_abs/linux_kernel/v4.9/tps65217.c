static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 , V_7 , V_4 -> V_8 ,
V_9 ) ;
if ( V_6 != 0 )
F_6 ( V_4 -> V_10 , L_1 ) ;
F_7 ( & V_4 -> V_5 ) ;
}
static inline const struct V_11 *
F_8 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return & V_12 [ V_2 -> V_13 ] ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_11 * V_1 = F_8 ( V_4 , V_2 ) ;
V_4 -> V_8 &= ~ V_1 -> V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_11 * V_1 = F_8 ( V_4 , V_2 ) ;
V_4 -> V_8 |= V_1 -> V_14 ;
}
static T_1 F_11 ( int V_15 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_16 ;
bool V_17 = false ;
int V_18 ;
int V_6 ;
V_6 = F_12 ( V_4 , V_7 , & V_16 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_10 , L_2 ,
V_6 ) ;
return V_19 ;
}
for ( V_18 = 0 ; V_18 < F_13 ( V_12 ) ; V_18 ++ ) {
if ( V_16 & V_12 [ V_18 ] . V_20 ) {
F_14 ( F_15 ( V_4 -> V_21 , V_18 ) ) ;
V_17 = true ;
}
}
if ( V_17 )
return V_22 ;
return V_19 ;
}
static int F_16 ( struct V_21 * V_23 , unsigned int V_24 ,
T_2 V_25 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
F_17 ( V_24 , V_4 ) ;
F_18 ( V_24 , & V_27 , V_28 ) ;
F_19 ( V_24 , 1 ) ;
F_20 ( V_24 , V_4 -> V_15 ) ;
F_21 ( V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , int V_15 )
{
int V_6 ;
F_23 ( & V_4 -> V_5 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_8 = ( V_29 | V_30
| V_31 | V_32 ) ;
F_5 ( V_4 , V_7 , V_4 -> V_8 ,
V_9 ) ;
V_4 -> V_21 = F_24 ( V_4 -> V_10 -> V_33 ,
V_34 , & V_35 , V_4 ) ;
if ( ! V_4 -> V_21 ) {
F_6 ( V_4 -> V_10 , L_3 ) ;
return - V_36 ;
}
V_6 = F_25 ( V_4 -> V_10 , V_15 , NULL ,
F_11 , V_37 ,
L_4 , V_4 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_10 , L_5 ,
V_15 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
int F_12 ( struct V_3 * V_4 , unsigned int V_38 ,
unsigned int * V_39 )
{
return F_26 ( V_4 -> V_40 , V_38 , V_39 ) ;
}
int F_5 ( struct V_3 * V_4 , unsigned int V_38 ,
unsigned int V_39 , unsigned int V_41 )
{
int V_6 ;
unsigned int V_42 ;
switch ( V_41 ) {
case V_9 :
return F_27 ( V_4 -> V_40 , V_38 , V_39 ) ;
case V_43 :
V_42 = V_38 ^ V_44 ;
V_6 = F_27 ( V_4 -> V_40 , V_45 ,
V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_27 ( V_4 -> V_40 , V_38 , V_39 ) ;
case V_46 :
V_42 = V_38 ^ V_44 ;
V_6 = F_27 ( V_4 -> V_40 , V_45 ,
V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_27 ( V_4 -> V_40 , V_38 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_27 ( V_4 -> V_40 , V_45 ,
V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_27 ( V_4 -> V_40 , V_38 , V_39 ) ;
default:
return - V_47 ;
}
}
static int F_28 ( struct V_3 * V_4 , unsigned int V_38 ,
unsigned int V_14 , unsigned int V_39 , unsigned int V_41 )
{
int V_6 ;
unsigned int V_2 ;
V_6 = F_12 ( V_4 , V_38 , & V_2 ) ;
if ( V_6 ) {
F_6 ( V_4 -> V_10 , L_6 , V_38 ) ;
return V_6 ;
}
V_2 &= ~ V_14 ;
V_2 |= V_39 & V_14 ;
V_6 = F_5 ( V_4 , V_38 , V_2 , V_41 ) ;
if ( V_6 )
F_6 ( V_4 -> V_10 , L_7 , V_38 ) ;
return V_6 ;
}
int F_29 ( struct V_3 * V_4 , unsigned int V_38 ,
unsigned int V_14 , unsigned int V_39 , unsigned int V_41 )
{
return F_28 ( V_4 , V_38 , V_14 , V_39 , V_41 ) ;
}
int F_30 ( struct V_3 * V_4 , unsigned int V_38 ,
unsigned int V_14 , unsigned int V_41 )
{
return F_28 ( V_4 , V_38 , V_14 , 0 , V_41 ) ;
}
static bool F_31 ( struct V_48 * V_10 , unsigned int V_38 )
{
switch ( V_38 ) {
case V_7 :
return true ;
default:
return false ;
}
}
static int F_32 ( struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
struct V_3 * V_4 ;
unsigned int V_53 ;
unsigned long V_54 = V_52 -> V_55 ;
const struct V_56 * V_57 ;
bool V_58 = false ;
int V_6 ;
if ( V_50 -> V_10 . V_33 ) {
V_57 = F_33 ( V_59 , & V_50 -> V_10 ) ;
if ( ! V_57 ) {
F_6 ( & V_50 -> V_10 ,
L_8 ) ;
return - V_47 ;
}
V_54 = ( unsigned long ) V_57 -> V_2 ;
V_58 = F_34 ( V_50 -> V_10 . V_33 ,
L_9 ) ;
}
if ( ! V_54 ) {
F_6 ( & V_50 -> V_10 , L_10 ) ;
return - V_60 ;
}
V_4 = F_35 ( & V_50 -> V_10 , sizeof( * V_4 ) , V_61 ) ;
if ( ! V_4 )
return - V_36 ;
F_36 ( V_50 , V_4 ) ;
V_4 -> V_10 = & V_50 -> V_10 ;
V_4 -> V_62 = V_54 ;
V_4 -> V_40 = F_37 ( V_50 , & V_63 ) ;
if ( F_38 ( V_4 -> V_40 ) ) {
V_6 = F_39 ( V_4 -> V_40 ) ;
F_6 ( V_4 -> V_10 , L_11 ,
V_6 ) ;
return V_6 ;
}
if ( V_50 -> V_15 ) {
F_22 ( V_4 , V_50 -> V_15 ) ;
} else {
int V_18 ;
for ( V_18 = 0 ; V_18 < F_13 ( V_64 ) ; V_18 ++ )
V_64 [ V_18 ] . V_65 = 0 ;
}
V_6 = F_40 ( V_4 -> V_10 , - 1 , V_64 ,
F_13 ( V_64 ) , NULL , 0 ,
V_4 -> V_21 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_10 , L_12 , V_6 ) ;
return V_6 ;
}
V_6 = F_12 ( V_4 , V_66 , & V_53 ) ;
if ( V_6 < 0 ) {
F_6 ( V_4 -> V_10 , L_13 ,
V_6 ) ;
return V_6 ;
}
if ( V_58 ) {
V_6 = F_29 ( V_4 , V_67 ,
V_68 , V_68 ,
V_9 ) ;
if ( V_6 )
F_41 ( V_4 -> V_10 , L_14 ) ;
}
F_42 ( V_4 -> V_10 , L_15 ,
( V_53 & V_69 ) >> 4 ,
V_53 & V_70 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_71 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_71 ) ;
}
