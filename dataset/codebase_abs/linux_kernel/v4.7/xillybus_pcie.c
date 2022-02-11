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
static void F_6 ( void * V_12 )
{
struct V_13 * V_14 = V_12 ;
F_7 ( V_14 -> V_15 , V_14 -> V_16 ,
V_14 -> V_10 , V_14 -> V_1 ) ;
F_8 ( V_12 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
void * V_12 ,
T_2 V_10 ,
int V_1 ,
T_1 * V_17
)
{
int V_18 ;
T_1 V_19 ;
struct V_13 * V_20 ;
V_20 = F_10 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return - V_22 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_11 ( V_8 -> V_11 , V_12 , V_10 , V_18 ) ;
if ( F_12 ( V_8 -> V_11 , V_19 ) ) {
F_8 ( V_20 ) ;
return - V_23 ;
}
V_20 -> V_15 = V_8 -> V_11 ;
V_20 -> V_16 = V_19 ;
V_20 -> V_10 = V_10 ;
V_20 -> V_1 = V_18 ;
* V_17 = V_19 ;
return F_13 ( V_8 -> V_24 , F_6 , V_20 ) ;
}
static int F_14 ( struct V_25 * V_11 ,
const struct V_26 * V_27 )
{
struct V_7 * V_28 ;
int V_29 ;
V_28 = F_15 ( V_11 , & V_11 -> V_24 , & V_30 ) ;
if ( ! V_28 )
return - V_22 ;
F_16 ( V_11 , V_28 ) ;
V_29 = F_17 ( V_11 ) ;
if ( V_29 ) {
F_18 ( V_28 -> V_24 ,
L_1 ) ;
return V_29 ;
}
F_19 ( V_11 , V_31 ) ;
if ( ! ( F_20 ( V_11 , 0 ) & V_32 ) ) {
F_18 ( V_28 -> V_24 ,
L_2 ) ;
return - V_23 ;
}
V_29 = F_21 ( V_11 , 0x01 , V_33 ) ;
if ( V_29 ) {
F_18 ( V_28 -> V_24 ,
L_3 ) ;
return V_29 ;
}
V_28 -> V_34 = F_22 ( V_11 ) [ 0 ] ;
F_23 ( V_11 ) ;
if ( F_24 ( V_11 ) ) {
F_18 ( V_28 -> V_24 ,
L_4 ) ;
return - V_23 ;
}
V_29 = F_25 ( & V_11 -> V_24 , V_11 -> V_35 , V_36 , 0 ,
V_33 , V_28 ) ;
if ( V_29 ) {
F_18 ( V_28 -> V_24 ,
L_5 ) ;
return - V_23 ;
}
if ( ! F_26 ( V_11 , F_27 ( 32 ) ) ) {
V_28 -> V_37 = 0 ;
} else if ( ! F_26 ( V_11 , F_27 ( 64 ) ) ) {
V_28 -> V_37 = 1 ;
} else {
F_18 ( V_28 -> V_24 , L_6 ) ;
return - V_23 ;
}
return F_28 ( V_28 ) ;
}
static void F_29 ( struct V_25 * V_11 )
{
struct V_7 * V_28 = F_30 ( V_11 ) ;
F_31 ( V_28 ) ;
}
