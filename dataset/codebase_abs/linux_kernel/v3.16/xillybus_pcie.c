static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
default:
return V_6 ;
}
}
static void F_2 ( struct V_7 * V_8 ,
T_1 V_9 ,
T_2 V_10 ,
int V_1 )
{
F_3 ( V_8 -> V_11 ,
V_9 ,
V_10 ,
F_1 ( V_1 ) ) ;
}
static void F_4 ( struct V_7 * V_8 ,
T_1 V_9 ,
T_2 V_10 ,
int V_1 )
{
F_5 ( V_8 -> V_11 ,
V_9 ,
V_10 ,
F_1 ( V_1 ) ) ;
}
static T_1 F_6 ( struct V_12 * V_13 ,
struct V_7 * V_8 ,
void * V_14 ,
T_2 V_10 ,
int V_1
)
{
T_1 V_15 = 0 ;
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_7 ( sizeof( struct V_16 ) , V_19 ) ;
if ( ! V_17 )
return 0 ;
V_18 = F_1 ( V_1 ) ;
V_15 = F_8 ( V_8 -> V_11 , V_14 , V_10 , V_18 ) ;
V_17 -> V_1 = V_18 ;
if ( F_9 ( V_8 -> V_11 , V_15 ) ) {
F_10 ( V_17 ) ;
return 0 ;
}
V_17 -> V_20 = V_15 ;
V_17 -> V_11 = V_8 -> V_11 ;
V_17 -> V_10 = V_10 ;
F_11 ( & V_17 -> V_21 , & V_13 -> V_22 ) ;
return V_15 ;
}
static void F_12 ( struct V_16 * V_23 )
{
F_13 ( V_23 -> V_11 ,
V_23 -> V_20 ,
V_23 -> V_10 ,
V_23 -> V_1 ) ;
}
static int F_14 ( struct V_24 * V_11 ,
const struct V_25 * V_26 )
{
struct V_7 * V_27 ;
int V_28 = 0 ;
V_27 = F_15 ( V_11 , & V_11 -> V_29 , & V_30 ) ;
if ( ! V_27 )
return - V_31 ;
F_16 ( V_11 , V_27 ) ;
V_28 = F_17 ( V_11 ) ;
if ( V_28 ) {
F_18 ( V_27 -> V_29 ,
L_1 ) ;
return V_28 ;
}
F_19 ( V_11 , V_32 ) ;
if ( ! ( F_20 ( V_11 , 0 ) & V_33 ) ) {
F_18 ( V_27 -> V_29 ,
L_2 ) ;
return - V_34 ;
}
V_28 = F_21 ( V_11 , 0x01 , V_35 ) ;
if ( V_28 ) {
F_18 ( V_27 -> V_29 ,
L_3 ) ;
return V_28 ;
}
V_27 -> V_36 = F_22 ( V_11 ) [ 0 ] ;
F_23 ( V_11 ) ;
if ( F_24 ( V_11 ) ) {
F_18 ( V_27 -> V_29 ,
L_4 ) ;
return - V_34 ;
}
V_28 = F_25 ( & V_11 -> V_29 , V_11 -> V_37 , V_38 , 0 ,
V_35 , V_27 ) ;
if ( V_28 ) {
F_18 ( V_27 -> V_29 ,
L_5 ) ;
return - V_34 ;
}
if ( ! F_26 ( V_11 , F_27 ( 32 ) ) )
V_27 -> V_39 = 0 ;
else {
F_18 ( V_27 -> V_29 , L_6 ) ;
return - V_34 ;
}
V_28 = F_28 ( V_27 ) ;
if ( ! V_28 )
return 0 ;
F_29 ( & V_27 -> V_40 , V_27 ) ;
return V_28 ;
}
static void F_30 ( struct V_24 * V_11 )
{
struct V_7 * V_27 = F_31 ( V_11 ) ;
F_32 ( V_27 ) ;
F_29 ( & V_27 -> V_40 , V_27 ) ;
}
