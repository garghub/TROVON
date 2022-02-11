static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 2 ] = { V_3 , V_4 } ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = sizeof( V_6 ) ,
. V_6 = V_6 ,
}
} ;
V_5 = F_2 ( V_2 -> V_12 , V_8 , 1 ) ;
if ( V_5 != 1 )
return V_5 ;
return 0 ;
}
static int F_3 ( struct V_13 * V_14 , void * V_15 ,
T_2 V_16 )
{
struct V_1 * V_2 = V_15 ;
struct V_17 * V_18 = F_4 ( & V_2 -> V_19 ) ;
struct V_20 * V_21 = F_5 ( V_18 ) ;
int V_5 = 0 ;
F_6 ( & V_18 -> V_22 ) ;
if ( ! V_21 -> V_23 ) {
V_5 = F_1 ( V_2 ,
V_21 -> V_3 -> V_24 , 0 ) ;
if ( V_5 )
goto V_25;
F_7 ( V_26 ,
V_27 ) ;
}
if ( ! V_5 ) {
V_21 -> V_23 ++ ;
V_5 = F_1 ( V_2 ,
V_21 -> V_3 -> V_28 ,
V_29 |
V_30 ) ;
}
V_25:
F_8 ( & V_18 -> V_22 ) ;
return V_5 ;
}
static int F_9 ( struct V_13 * V_14 ,
void * V_15 , T_2 V_16 )
{
struct V_1 * V_2 = V_15 ;
struct V_17 * V_18 = F_4 ( & V_2 -> V_19 ) ;
struct V_20 * V_21 = F_5 ( V_18 ) ;
F_6 ( & V_18 -> V_22 ) ;
F_1 ( V_2 , V_21 -> V_3 -> V_28 ,
V_29 ) ;
V_21 -> V_23 -- ;
if ( ! V_21 -> V_23 )
F_1 ( V_2 , V_21 -> V_3 -> V_24 ,
V_31 ) ;
F_8 ( & V_18 -> V_22 ) ;
return 0 ;
}
static const char * F_10 ( struct V_32 * V_19 , int * V_33 )
{
const struct V_34 * V_35 ;
V_35 = F_11 ( V_19 -> V_36 -> V_37 , V_19 ) ;
if ( ! V_35 )
return NULL ;
* V_33 = ( int ) V_35 -> V_38 ;
return F_12 ( V_19 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_39 * V_35 )
{
struct V_20 * V_21 ;
int V_40 , V_41 ;
struct V_42 * V_42 ;
const char * V_43 ;
if ( ! F_14 ( V_2 -> V_12 ,
V_44 ) )
return - V_45 ;
if ( V_35 ) {
V_41 = ( int ) V_35 -> V_38 ;
V_43 = V_35 -> V_43 ;
} else if ( F_15 ( & V_2 -> V_19 ) ) {
V_43 = F_10 ( & V_2 -> V_19 , & V_41 ) ;
if ( ! V_43 )
return - V_46 ;
} else {
return - V_47 ;
}
V_42 = F_16 ( V_2 , & V_48 ) ;
if ( F_17 ( V_42 ) ) {
F_18 ( & V_2 -> V_19 , L_1 ,
( int ) F_19 ( V_42 ) ) ;
return F_19 ( V_42 ) ;
}
V_40 = F_20 ( V_42 , V_2 -> V_49 , V_43 ,
NULL , V_41 ) ;
if ( V_40 < 0 )
return V_40 ;
V_21 = F_5 ( F_4 ( & V_2 -> V_19 ) ) ;
V_21 -> V_50 = F_21 ( V_2 -> V_12 ,
& V_2 -> V_19 ,
V_2 ,
0 , 0 , 0 ,
F_3 ,
F_9 ) ;
if ( ! V_21 -> V_50 ) {
V_40 = - V_46 ;
goto V_51;
}
V_40 = F_22 ( V_2 ) ;
if ( V_40 )
goto V_52;
return 0 ;
V_52:
F_23 ( V_21 -> V_50 ) ;
V_51:
F_24 ( & V_2 -> V_19 ) ;
return V_40 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_26 ( V_2 ) ;
struct V_20 * V_21 = F_5 ( V_18 ) ;
F_27 ( V_2 ) ;
F_23 ( V_21 -> V_50 ) ;
return F_24 ( & V_2 -> V_19 ) ;
}
