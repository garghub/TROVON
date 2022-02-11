static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_3 * V_4 ,
enum V_7 V_8 )
{
const unsigned int V_9 = ( V_10 | V_11 ) ;
const unsigned int V_12 = V_8 ? V_9 : 0 ;
return F_4 ( V_4 -> V_13 , V_14 , V_9 , V_12 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_13 * V_13 = V_4 -> V_13 ;
const struct V_17 * V_18 = V_4 -> V_19 -> V_18 ;
V_4 -> V_20 = F_6 ( V_16 , V_13 ,
V_18 [ V_21 ] ) ;
V_4 -> V_22 = F_6 ( V_16 , V_13 ,
V_18 [ V_23 ] ) ;
if ( F_7 ( V_4 -> V_20 ) || F_7 ( V_4 -> V_22 ) ) {
F_8 ( V_16 , L_1 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_25 ;
V_25 = F_10 ( V_4 -> V_20 ,
V_4 -> V_19 -> V_26 -
V_4 -> V_19 -> V_27 ) ;
if ( V_25 )
return V_25 ;
return F_10 ( V_4 -> V_22 , 1 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_28 * V_29 = F_12 ( V_16 ) ;
int V_25 ;
V_4 -> V_1 = F_13 ( V_29 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_8 ( V_16 , L_2 ) ;
return V_4 -> V_1 ;
}
V_25 = F_14 ( V_16 , V_4 -> V_1 ,
NULL , F_1 ,
V_30 | V_31 ,
V_16 -> V_32 -> V_33 , V_4 ) ;
if ( V_25 ) {
F_8 ( V_16 , L_3 , V_4 -> V_1 ) ;
return V_25 ;
}
return F_9 ( V_4 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_28 * V_29 = F_12 ( V_16 ) ;
struct V_34 * V_35 ;
V_35 = F_16 ( V_29 , V_36 , 0 ) ;
if ( ! V_35 ) {
F_8 ( V_16 , L_4 ) ;
return - V_37 ;
}
V_4 -> V_38 = F_17 ( V_16 , V_35 ) ;
if ( F_7 ( V_4 -> V_38 ) ) {
F_8 ( V_16 , L_5 ) ;
return F_18 ( V_4 -> V_38 ) ;
}
V_4 -> V_13 = F_19 ( V_16 , V_4 -> V_38 ,
& V_39 ) ;
if ( F_7 ( V_4 -> V_13 ) ) {
F_8 ( V_16 , L_6 ) ;
return F_18 ( V_4 -> V_13 ) ;
}
return 0 ;
}
static int F_20 ( struct V_28 * V_29 )
{
return F_21 ( V_29 , V_40 ) ;
}
static int F_22 ( struct V_28 * V_29 )
{
return F_23 ( V_29 ) ;
}
