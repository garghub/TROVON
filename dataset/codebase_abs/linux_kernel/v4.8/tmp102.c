static inline int F_1 ( T_1 V_1 )
{
return ( ( V_1 & ~ 0x01 ) * 1000 ) / 128 ;
}
static inline T_2 F_2 ( int V_1 )
{
return ( V_1 * 128 ) / 1000 ;
}
static int F_3 ( void * V_2 , int * V_3 )
{
struct V_4 * V_4 = F_4 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
if ( F_5 ( V_7 , V_4 -> V_8 ) ) {
F_6 ( V_2 , L_1 , V_9 ) ;
return - V_10 ;
}
V_6 = F_7 ( V_4 -> V_11 , V_12 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_3 = F_1 ( V_5 ) ;
return 0 ;
}
static T_3 F_8 ( struct V_13 * V_2 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_4 * V_4 = F_4 ( V_2 ) ;
int V_19 = V_18 -> V_20 ;
unsigned int V_5 ;
int V_21 ;
if ( V_19 == V_12 &&
F_5 ( V_7 , V_4 -> V_8 ) )
return - V_10 ;
V_21 = F_7 ( V_4 -> V_11 , V_19 , & V_5 ) ;
if ( V_21 < 0 )
return V_21 ;
return sprintf ( V_16 , L_2 , F_1 ( V_5 ) ) ;
}
static T_3 F_10 ( struct V_13 * V_2 ,
struct V_14 * V_15 ,
const char * V_16 , T_4 V_22 )
{
struct V_17 * V_18 = F_9 ( V_15 ) ;
struct V_4 * V_4 = F_4 ( V_2 ) ;
int V_5 = V_18 -> V_20 ;
long V_1 ;
int V_21 ;
if ( F_11 ( V_16 , 10 , & V_1 ) < 0 )
return - V_23 ;
V_1 = F_12 ( V_1 , - 256000 , 255000 ) ;
V_21 = F_13 ( V_4 -> V_11 , V_5 , F_2 ( V_1 ) ) ;
return V_21 ? : V_22 ;
}
static void F_14 ( void * V_24 )
{
struct V_4 * V_4 = V_24 ;
F_13 ( V_4 -> V_11 , V_25 , V_4 -> V_26 ) ;
}
static bool F_15 ( struct V_13 * V_2 , unsigned int V_5 )
{
return V_5 != V_12 ;
}
static bool F_16 ( struct V_13 * V_2 , unsigned int V_5 )
{
return V_5 == V_12 ;
}
static int F_17 ( struct V_27 * V_28 ,
const struct V_29 * V_30 )
{
struct V_13 * V_2 = & V_28 -> V_2 ;
struct V_13 * V_31 ;
struct V_4 * V_4 ;
unsigned int V_32 ;
int V_21 ;
if ( ! F_18 ( V_28 -> V_33 ,
V_34 ) ) {
F_19 ( V_2 ,
L_3 ) ;
return - V_35 ;
}
V_4 = F_20 ( V_2 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
F_21 ( V_28 , V_4 ) ;
V_4 -> V_11 = F_22 ( V_28 , & V_38 ) ;
if ( F_23 ( V_4 -> V_11 ) )
return F_24 ( V_4 -> V_11 ) ;
V_21 = F_7 ( V_4 -> V_11 , V_25 , & V_32 ) ;
if ( V_21 < 0 ) {
F_19 ( V_2 , L_4 ) ;
return V_21 ;
}
if ( ( V_32 & ~ V_39 ) !=
( V_40 | V_41 ) ) {
F_19 ( V_2 , L_5 ) ;
return - V_35 ;
}
V_4 -> V_26 = V_32 ;
V_21 = F_25 ( V_2 , F_14 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_32 &= ~ V_42 ;
V_32 |= V_43 ;
V_21 = F_13 ( V_4 -> V_11 , V_25 , V_32 ) ;
if ( V_21 < 0 ) {
F_19 ( V_2 , L_6 ) ;
return V_21 ;
}
V_4 -> V_8 = V_7 ;
if ( V_4 -> V_26 & V_44 ) {
V_4 -> V_8 += F_26 ( V_45 ) ;
}
V_31 = F_27 ( V_2 , V_28 -> V_46 ,
V_4 ,
V_47 ) ;
if ( F_23 ( V_31 ) ) {
F_6 ( V_2 , L_7 ) ;
return F_24 ( V_31 ) ;
}
F_28 ( V_31 , 0 , V_31 ,
& V_48 ) ;
F_29 ( V_2 , L_8 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_2 )
{
struct V_27 * V_28 = F_31 ( V_2 ) ;
struct V_4 * V_4 = F_32 ( V_28 ) ;
return F_33 ( V_4 -> V_11 , V_25 ,
V_44 , V_44 ) ;
}
static int F_34 ( struct V_13 * V_2 )
{
struct V_27 * V_28 = F_31 ( V_2 ) ;
struct V_4 * V_4 = F_32 ( V_28 ) ;
int V_21 ;
V_21 = F_33 ( V_4 -> V_11 , V_25 ,
V_44 , 0 ) ;
V_4 -> V_8 = V_7 + F_26 ( V_45 ) ;
return V_21 ;
}
