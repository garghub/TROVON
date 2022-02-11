static inline int F_1 ( T_1 V_1 )
{
return ( ( V_1 & ~ 0x01 ) * 1000 ) / 128 ;
}
static inline T_2 F_2 ( int V_1 )
{
return ( V_1 * 128 ) / 1000 ;
}
static struct V_2 * F_3 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_5 ( & V_2 -> V_7 ) ;
if ( F_6 ( V_8 , V_2 -> V_9 + V_10 / 3 ) ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_2 -> V_12 ) ; ++ V_11 ) {
int V_13 = F_8 ( V_6 ,
V_14 [ V_11 ] ) ;
if ( V_13 > - 1 )
V_2 -> V_12 [ V_11 ] = F_1 ( V_13 ) ;
}
V_2 -> V_9 = V_8 ;
V_2 -> V_15 = false ;
}
F_9 ( & V_2 -> V_7 ) ;
return V_2 ;
}
static int F_10 ( void * V_4 , int * V_12 )
{
struct V_2 * V_2 = F_3 ( V_4 ) ;
if ( V_2 -> V_15 ) {
F_11 ( V_4 , L_1 , V_16 ) ;
return - V_17 ;
}
* V_12 = V_2 -> V_12 [ 0 ] ;
return 0 ;
}
static T_3 F_12 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_2 * V_2 = F_3 ( V_4 ) ;
if ( V_2 -> V_15 )
return - V_17 ;
return sprintf ( V_20 , L_2 , V_2 -> V_12 [ V_22 -> V_23 ] ) ;
}
static T_3 F_14 ( struct V_3 * V_4 ,
struct V_18 * V_19 ,
const char * V_20 , T_4 V_24 )
{
struct V_21 * V_22 = F_13 ( V_19 ) ;
struct V_2 * V_2 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
long V_1 ;
int V_13 ;
if ( F_15 ( V_20 , 10 , & V_1 ) < 0 )
return - V_25 ;
V_1 = F_16 ( V_1 , - 256000 , 255000 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_12 [ V_22 -> V_23 ] = V_1 ;
V_13 = F_17 ( V_6 , V_14 [ V_22 -> V_23 ] ,
F_2 ( V_1 ) ) ;
F_9 ( & V_2 -> V_7 ) ;
return V_13 ? : V_24 ;
}
static int F_18 ( struct V_5 * V_6 ,
const struct V_26 * V_27 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_3 * V_28 ;
struct V_2 * V_2 ;
int V_13 ;
if ( ! F_19 ( V_6 -> V_29 ,
V_30 ) ) {
F_20 ( V_4 ,
L_3 ) ;
return - V_31 ;
}
V_2 = F_21 ( V_4 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
F_22 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_13 = F_8 ( V_6 , V_34 ) ;
if ( V_13 < 0 ) {
F_20 ( V_4 , L_4 ) ;
return V_13 ;
}
V_2 -> V_35 = V_13 ;
V_13 = F_17 ( V_6 , V_34 ,
V_36 ) ;
if ( V_13 < 0 ) {
F_20 ( V_4 , L_5 ) ;
goto V_37;
}
V_13 = F_8 ( V_6 , V_34 ) ;
if ( V_13 < 0 ) {
F_20 ( V_4 , L_4 ) ;
goto V_37;
}
V_13 &= ~ V_38 ;
if ( V_13 != V_36 ) {
F_20 ( V_4 , L_6 ) ;
V_13 = - V_31 ;
goto V_37;
}
V_2 -> V_9 = V_8 ;
V_2 -> V_15 = true ;
F_23 ( & V_2 -> V_7 ) ;
V_28 = F_24 ( V_4 , V_6 -> V_39 ,
V_2 , V_40 ) ;
if ( F_25 ( V_28 ) ) {
F_11 ( V_4 , L_7 ) ;
V_13 = F_26 ( V_28 ) ;
goto V_37;
}
V_2 -> V_28 = V_28 ;
F_27 ( V_28 , 0 , V_28 ,
& V_41 ) ;
F_28 ( V_4 , L_8 ) ;
return 0 ;
V_37:
F_17 ( V_6 , V_34 ,
V_2 -> V_35 ) ;
return V_13 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_2 * V_2 = F_30 ( V_6 ) ;
F_31 ( V_2 -> V_28 ) ;
if ( V_2 -> V_35 & V_42 ) {
int V_43 ;
V_43 = F_8 ( V_6 , V_34 ) ;
if ( V_43 >= 0 )
F_17 ( V_6 , V_34 ,
V_43 | V_42 ) ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_33 ( V_4 ) ;
int V_43 ;
V_43 = F_8 ( V_6 , V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 |= V_42 ;
return F_17 ( V_6 , V_34 , V_43 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_33 ( V_4 ) ;
int V_43 ;
V_43 = F_8 ( V_6 , V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 &= ~ V_42 ;
return F_17 ( V_6 , V_34 , V_43 ) ;
}
