static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 ... V_7 :
case V_8 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_9 ... V_6 :
case V_10 :
case V_11 ... V_12 :
return true ;
default:
return false ;
}
}
static void F_4 ( struct V_13 * V_13 )
{
unsigned int V_14 ;
int V_15 = 0 ;
if ( ! V_13 -> V_16 )
return;
if ( V_13 -> V_17 )
V_15 = V_18 ;
if ( V_13 -> V_19 )
V_15 |= V_20 ;
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
if ( V_13 -> V_22 & ( 1 << V_14 ) )
V_15 |= V_23 [ V_14 ] ;
}
F_5 ( V_13 -> V_16 , V_15 , V_24 ) ;
}
static void F_6 ( struct V_13 * V_13 , unsigned V_25 )
{
bool V_17 , V_19 ;
V_17 = ! ! ( V_25 & V_26 ) ;
V_19 = V_17 && ! ! ( V_25 & V_27 ) ;
V_13 -> V_17 = V_17 ;
if ( V_19 != V_13 -> V_19 ) {
V_13 -> V_19 = V_19 ;
V_13 -> V_22 = 0 ;
if ( V_19 ) {
F_7 ( V_13 -> V_28 ,
V_10 ,
V_29 , V_29 ) ;
}
}
}
static T_1 F_8 ( int V_30 , void * V_31 )
{
struct V_13 * V_13 = (struct V_13 * ) V_31 ;
struct V_28 * V_28 = V_13 -> V_28 ;
unsigned int V_32 , V_33 , V_25 , V_14 ;
F_9 ( V_28 , V_9 , & V_32 ) ;
if ( V_32 & ( V_34 | V_35 ) ) {
F_9 ( V_28 , V_36 , & V_25 ) ;
F_6 ( V_13 , V_25 ) ;
}
F_9 ( V_28 , V_37 , & V_33 ) ;
for ( V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
if ( V_33 & F_10 ( V_14 ) )
V_13 -> V_22 |= ( 1 << V_14 ) ;
if ( V_33 & F_11 ( V_14 ) )
V_13 -> V_22 &= ~ ( 1 << V_14 ) ;
}
F_4 ( V_13 ) ;
return V_38 ;
}
int F_12 ( struct V_39 * V_40 ,
struct V_41 * V_16 )
{
struct V_13 * V_13 = F_13 ( V_40 ) ;
F_14 ( V_16 -> V_16 , V_42 , V_43 ) ;
F_14 ( V_16 -> V_16 , V_44 , V_45 ) ;
F_14 ( V_16 -> V_16 , V_46 , V_47 ) ;
F_14 ( V_16 -> V_16 , V_48 , V_49 ) ;
V_13 -> V_16 = V_16 ;
F_4 ( V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
T_2 V_50 ;
int V_51 ;
V_51 = F_16 ( V_2 , L_1 , & V_50 ) ;
if ( ! V_51 ) {
F_7 ( V_13 -> V_28 , V_52 ,
V_53 ,
( V_50 & 0x07 ) << V_54 ) ;
}
return 0 ;
}
static int F_17 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_13 * V_13 ;
struct V_1 * V_2 = & V_56 -> V_2 ;
int V_59 ;
unsigned int V_25 ;
V_13 = F_18 ( & V_56 -> V_2 , sizeof( * V_13 ) , V_60 ) ;
if ( V_13 == NULL )
return - V_61 ;
F_19 ( V_56 , V_13 ) ;
V_13 -> V_28 = F_20 ( V_56 , & V_62 ) ;
if ( F_21 ( V_13 -> V_28 ) )
return F_22 ( V_13 -> V_28 ) ;
V_59 = F_15 ( V_13 , V_2 ) ;
if ( V_59 ) {
F_23 ( V_2 , L_2 , V_59 ) ;
return V_59 ;
}
V_59 = F_24 ( V_2 , V_56 -> V_30 , NULL , F_8 ,
V_63 | V_64 ,
L_3 , V_13 ) ;
if ( V_59 ) {
F_23 ( V_2 , L_4 , V_56 -> V_30 , V_59 ) ;
return V_59 ;
}
V_59 = F_25 ( & V_56 -> V_2 , & V_65 ,
NULL , 0 ) ;
if ( V_59 )
return V_59 ;
F_7 ( V_13 -> V_28 , V_6 ,
V_66 | V_67 ,
V_67 ) ;
F_9 ( V_13 -> V_28 , V_36 , & V_25 ) ;
F_6 ( V_13 , V_25 ) ;
F_4 ( V_13 ) ;
return 0 ;
}
