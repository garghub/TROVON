static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ,
V_6 ) ;
return V_7 ;
}
static int F_3 ( struct V_3 * V_4 ,
enum V_8 V_9 )
{
const unsigned int V_10 = ( V_11 | V_12 ) ;
const unsigned int V_13 = V_9 ? V_10 : 0 ;
return F_4 ( V_4 -> V_14 , V_15 , V_10 , V_13 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_14 * V_14 = V_4 -> V_14 ;
const struct V_18 * V_19 = V_4 -> V_20 -> V_19 ;
V_4 -> V_21 = F_6 ( V_17 , V_14 ,
V_19 [ V_22 ] ) ;
V_4 -> V_23 = F_6 ( V_17 , V_14 ,
V_19 [ V_24 ] ) ;
if ( F_7 ( V_4 -> V_21 ) || F_7 ( V_4 -> V_23 ) ) {
F_8 ( V_17 , L_1 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_26 ;
V_26 = F_10 ( V_4 -> V_21 ,
V_4 -> V_20 -> V_27 -
V_4 -> V_20 -> V_28 ) ;
if ( V_26 )
return V_26 ;
return F_10 ( V_4 -> V_23 , 1 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_29 * V_30 = F_12 ( V_17 ) ;
int V_26 ;
V_4 -> V_1 = F_13 ( V_30 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_8 ( V_17 , L_2 ) ;
return V_4 -> V_1 ;
}
V_26 = F_14 ( V_17 , V_4 -> V_1 ,
NULL , F_1 ,
V_31 | V_32 ,
V_17 -> V_33 -> V_34 , V_4 ) ;
if ( V_26 ) {
F_8 ( V_17 , L_3 , V_4 -> V_1 ) ;
return V_26 ;
}
return F_9 ( V_4 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_17 ;
struct V_29 * V_30 = F_12 ( V_17 ) ;
struct V_35 * V_36 ;
V_36 = F_16 ( V_30 , V_37 , 0 ) ;
if ( ! V_36 ) {
F_8 ( V_17 , L_4 ) ;
return - V_38 ;
}
V_4 -> V_39 = F_17 ( V_17 , V_36 ) ;
if ( F_7 ( V_4 -> V_39 ) ) {
F_8 ( V_17 , L_5 ) ;
return F_18 ( V_4 -> V_39 ) ;
}
V_4 -> V_14 = F_19 ( V_17 , V_4 -> V_39 ,
& V_40 ) ;
if ( F_7 ( V_4 -> V_14 ) ) {
F_8 ( V_17 , L_6 ) ;
return F_18 ( V_4 -> V_14 ) ;
}
return 0 ;
}
static int F_20 ( struct V_29 * V_30 )
{
return F_21 ( V_30 , V_41 ) ;
}
static int F_22 ( struct V_29 * V_30 )
{
return F_23 ( V_30 ) ;
}
