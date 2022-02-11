static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( ! F_2 ( V_5 -> V_7 ) )
return V_8 ;
return V_9 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
const char * V_12 , T_1 V_13 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
const T_1 V_14 = 7500 ;
const T_1 V_15 = 1 ;
if ( V_11 -> V_16 & V_17 ) {
F_4 ( & V_3 -> V_18 , L_1 ) ;
return - V_19 ;
}
F_5 ( V_5 -> V_20 , 1 ) ;
F_6 ( V_15 ) ;
F_5 ( V_5 -> V_20 , 0 ) ;
if ( F_2 ( V_5 -> V_7 ) ) {
F_4 ( & V_3 -> V_18 , L_2 ) ;
return - V_21 ;
}
F_7 ( V_14 , V_14 + 100 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , const char * V_12 ,
T_1 V_13 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
const char * V_22 = V_12 ;
const char * V_23 = V_22 + V_13 ;
while ( V_22 < V_23 ) {
T_1 V_24 , V_25 ;
int V_26 ;
V_24 = V_23 - V_22 ;
V_25 = F_9 ( T_1 , V_24 , V_27 ) ;
V_26 = F_10 ( V_5 -> V_28 , V_22 , V_25 ) ;
if ( V_26 ) {
F_4 ( & V_3 -> V_18 , L_3 ,
V_26 ) ;
return V_26 ;
}
V_22 += V_25 ;
}
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_29 * V_28 = V_5 -> V_28 ;
const T_2 V_30 [ 1 ] = { 0xff } ;
int V_26 ;
V_26 = F_10 ( V_5 -> V_28 , V_30 , sizeof( V_30 ) ) ;
if ( V_26 )
F_4 ( & V_28 -> V_18 , L_4 , V_26 ) ;
return V_26 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_31 ;
int V_26 ;
if ( F_2 ( V_5 -> V_7 ) )
return F_11 ( V_5 ) ;
V_31 = V_32 + F_13 ( V_11 -> V_33 ) ;
while ( F_14 ( V_32 , V_31 ) ) {
V_26 = F_11 ( V_5 ) ;
if ( V_26 )
return V_26 ;
if ( F_2 ( V_5 -> V_7 ) )
return F_11 ( V_5 ) ;
}
F_4 ( & V_3 -> V_18 , L_5 ) ;
return - V_34 ;
}
static int F_15 ( struct V_29 * V_28 )
{
struct V_4 * V_5 ;
V_5 = F_16 ( & V_28 -> V_18 , sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 )
return - V_36 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_20 = F_17 ( & V_28 -> V_18 , L_6 , V_37 ) ;
if ( F_18 ( V_5 -> V_20 ) ) {
F_4 ( & V_28 -> V_18 , L_7 ,
F_19 ( V_5 -> V_20 ) ) ;
return F_19 ( V_5 -> V_20 ) ;
}
V_5 -> V_7 = F_17 ( & V_28 -> V_18 , L_8 , V_38 ) ;
if ( F_18 ( V_5 -> V_7 ) ) {
F_4 ( & V_28 -> V_18 , L_9 ,
F_19 ( V_5 -> V_7 ) ) ;
return F_19 ( V_5 -> V_7 ) ;
}
return F_20 ( & V_28 -> V_18 , L_10 ,
& V_39 , V_5 ) ;
}
static int F_21 ( struct V_29 * V_28 )
{
F_22 ( & V_28 -> V_18 ) ;
return 0 ;
}
