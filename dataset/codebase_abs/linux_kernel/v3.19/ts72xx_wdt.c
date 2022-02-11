static int F_1 ( int V_1 )
{
int V_2 ;
V_1 = F_2 ( V_1 , 1 , 8 ) ;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_4 >= V_1 )
return V_3 [ V_2 ] . V_5 ;
}
return - V_6 ;
}
static int F_4 ( int V_5 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_3 ( V_3 ) ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_5 == V_5 )
return V_3 [ V_2 ] . V_4 ;
}
return - V_6 ;
}
static inline void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_9 , V_8 -> V_10 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
F_5 ( V_8 ) ;
F_6 ( ( V_11 ) V_8 -> V_5 , V_8 -> V_12 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_5 ( V_8 ) ;
F_6 ( 0 , V_8 -> V_12 ) ;
}
static int F_9 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_7 * V_8 = F_10 ( V_15 ) ;
int V_5 ;
V_5 = F_1 ( V_4 ) ;
if ( V_5 < 0 ) {
F_11 ( & V_8 -> V_16 -> V_17 ,
L_1 ,
V_4 ) ;
return V_5 ;
}
if ( F_12 ( & V_8 -> V_18 ) )
return - V_19 ;
if ( ( V_8 -> V_20 & V_21 ) != 0 ) {
F_13 ( & V_8 -> V_18 ) ;
return - V_22 ;
}
V_8 -> V_20 = V_21 ;
V_8 -> V_5 = V_5 ;
V_14 -> V_23 = V_8 ;
F_7 ( V_8 ) ;
F_13 ( & V_8 -> V_18 ) ;
return F_14 ( V_13 , V_14 ) ;
}
static int F_15 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_23 ;
if ( F_12 ( & V_8 -> V_18 ) )
return - V_19 ;
if ( ( V_8 -> V_20 & V_24 ) != 0 ) {
F_8 ( V_8 ) ;
} else {
F_16 ( & V_8 -> V_16 -> V_17 ,
L_2
L_3 ) ;
F_5 ( V_8 ) ;
}
V_8 -> V_20 = 0 ;
F_13 ( & V_8 -> V_18 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_14 * V_14 ,
const char T_2 * V_25 ,
T_3 V_26 ,
T_4 * V_27 )
{
struct V_7 * V_8 = V_14 -> V_23 ;
if ( ! V_26 )
return 0 ;
if ( F_12 ( & V_8 -> V_18 ) )
return - V_19 ;
F_5 ( V_8 ) ;
if ( ! V_28 ) {
int V_2 ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ ) {
char V_29 ;
V_8 -> V_20 &= ~ V_24 ;
if ( F_18 ( V_29 , V_25 + V_2 ) ) {
F_13 ( & V_8 -> V_18 ) ;
return - V_30 ;
}
if ( V_29 == 'V' ) {
V_8 -> V_20 |= V_24 ;
break;
}
}
}
F_13 ( & V_8 -> V_18 ) ;
return V_26 ;
}
static long F_19 ( struct V_14 * V_14 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_7 * V_8 = V_14 -> V_23 ;
void T_2 * V_33 = ( void T_2 * ) V_32 ;
int T_2 * V_34 = ( int T_2 * ) V_33 ;
int error = 0 ;
if ( F_12 ( & V_8 -> V_18 ) )
return - V_19 ;
switch ( V_31 ) {
case V_35 :
if ( F_20 ( V_33 , & V_36 , sizeof( V_36 ) ) )
error = - V_30 ;
break;
case V_37 :
case V_38 :
error = F_21 ( 0 , V_34 ) ;
break;
case V_39 :
F_5 ( V_8 ) ;
break;
case V_40 : {
int V_41 ;
error = F_18 ( V_41 , V_34 ) ;
if ( error )
break;
error = - V_6 ;
if ( ( V_41 & V_42 ) != 0 ) {
F_8 ( V_8 ) ;
error = 0 ;
}
if ( ( V_41 & V_43 ) != 0 ) {
F_7 ( V_8 ) ;
error = 0 ;
}
break;
}
case V_44 : {
int V_1 ;
int V_5 ;
error = F_18 ( V_1 , V_34 ) ;
if ( error )
break;
V_5 = F_1 ( V_1 ) ;
if ( V_5 < 0 ) {
error = V_5 ;
break;
}
F_8 ( V_8 ) ;
V_8 -> V_5 = V_5 ;
F_7 ( V_8 ) ;
}
case V_45 :
error = F_21 ( F_4 ( V_8 -> V_5 ) , V_34 ) ;
break;
default:
error = - V_46 ;
break;
}
F_13 ( & V_8 -> V_18 ) ;
return error ;
}
static int F_22 ( struct V_47 * V_16 )
{
struct V_7 * V_8 ;
struct V_48 * V_49 , * V_50 ;
int error = 0 ;
V_8 = F_23 ( & V_16 -> V_17 , sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 )
return - V_52 ;
V_49 = F_24 ( V_16 , V_53 , 0 ) ;
V_8 -> V_12 = F_25 ( & V_16 -> V_17 , V_49 ) ;
if ( F_26 ( V_8 -> V_12 ) )
return F_27 ( V_8 -> V_12 ) ;
V_50 = F_24 ( V_16 , V_53 , 1 ) ;
V_8 -> V_10 = F_25 ( & V_16 -> V_17 , V_50 ) ;
if ( F_26 ( V_8 -> V_10 ) )
return F_27 ( V_8 -> V_10 ) ;
F_28 ( V_16 , V_8 ) ;
V_15 = V_16 ;
V_8 -> V_16 = V_16 ;
F_29 ( & V_8 -> V_18 ) ;
F_8 ( V_8 ) ;
error = F_30 ( & V_54 ) ;
if ( error ) {
F_11 ( & V_16 -> V_17 , L_4 ) ;
return error ;
}
F_31 ( & V_16 -> V_17 , L_5 ) ;
return 0 ;
}
static int F_32 ( struct V_47 * V_16 )
{
return F_33 ( & V_54 ) ;
}
