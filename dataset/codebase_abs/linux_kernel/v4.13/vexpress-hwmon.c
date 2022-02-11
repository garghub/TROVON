static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const char * V_6 = F_2 ( V_2 -> V_7 , L_1 , NULL ) ;
return snprintf ( V_5 , V_8 , L_2 , V_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_11 ;
T_2 V_12 ;
V_11 = F_5 ( V_10 -> V_13 , 0 , & V_12 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_5 , V_8 , L_3 , V_12 /
F_6 ( V_4 ) -> V_14 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_11 ;
T_2 V_15 , V_16 ;
V_11 = F_5 ( V_10 -> V_13 , 0 , & V_16 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 -> V_13 , 1 , & V_15 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_5 , V_8 , L_4 ,
F_8 ( ( ( V_17 ) V_15 << 32 ) | V_16 ,
F_6 ( V_4 ) -> V_14 ) ) ;
}
static T_3 F_9 ( struct V_18 * V_19 ,
struct V_20 * V_21 , int V_14 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
struct V_3 * V_4 = F_11 ( V_21 ,
struct V_3 , V_21 ) ;
if ( V_4 -> V_22 == F_1 &&
! F_2 ( V_2 -> V_7 , L_1 , NULL ) )
return 0 ;
return V_21 -> V_23 ;
}
static int F_12 ( struct V_24 * V_25 )
{
const struct V_26 * V_27 ;
struct V_9 * V_10 ;
const struct V_28 * type ;
V_10 = F_13 ( & V_25 -> V_2 , sizeof( * V_10 ) , V_29 ) ;
if ( ! V_10 )
return - V_30 ;
F_14 ( V_25 , V_10 ) ;
V_27 = F_15 ( V_31 , & V_25 -> V_2 ) ;
if ( ! V_27 )
return - V_32 ;
type = V_27 -> V_10 ;
V_10 -> V_13 = F_16 ( & V_25 -> V_2 ) ;
if ( F_17 ( V_10 -> V_13 ) )
return F_18 ( V_10 -> V_13 ) ;
V_10 -> V_33 = F_19 ( & V_25 -> V_2 ,
type -> V_34 , V_10 , type -> V_35 ) ;
return F_20 ( V_10 -> V_33 ) ;
}
