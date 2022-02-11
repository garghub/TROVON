static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const char * V_9 = F_4 ( V_2 -> V_10 , L_2 , NULL ) ;
return snprintf ( V_5 , V_11 , L_1 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
T_2 V_13 ;
V_12 = F_6 ( V_7 -> V_14 , 0 , & V_13 ) ;
if ( V_12 )
return V_12 ;
return snprintf ( V_5 , V_11 , L_3 , V_13 /
F_7 ( V_4 ) -> V_15 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
T_2 V_16 , V_17 ;
V_12 = F_6 ( V_7 -> V_14 , 0 , & V_17 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_7 -> V_14 , 1 , & V_16 ) ;
if ( V_12 )
return V_12 ;
return snprintf ( V_5 , V_11 , L_4 ,
F_9 ( ( ( V_18 ) V_16 << 32 ) | V_17 ,
F_7 ( V_4 ) -> V_15 ) ) ;
}
static T_3 F_10 ( struct V_19 * V_20 ,
struct V_21 * V_22 , int V_15 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
struct V_3 * V_4 = F_12 ( V_22 ,
struct V_3 , V_22 ) ;
if ( V_4 -> V_23 == F_3 &&
! F_4 ( V_2 -> V_10 , L_2 , NULL ) )
return 0 ;
return V_22 -> V_24 ;
}
static int F_13 ( struct V_25 * V_26 )
{
int V_12 ;
const struct V_27 * V_28 ;
struct V_6 * V_7 ;
const struct V_29 * type ;
V_7 = F_14 ( & V_26 -> V_2 , sizeof( * V_7 ) , V_30 ) ;
if ( ! V_7 )
return - V_31 ;
F_15 ( V_26 , V_7 ) ;
V_28 = F_16 ( V_32 , & V_26 -> V_2 ) ;
if ( ! V_28 )
return - V_33 ;
type = V_28 -> V_7 ;
V_7 -> V_8 = type -> V_8 ;
V_7 -> V_14 = F_17 ( & V_26 -> V_2 ) ;
if ( ! V_7 -> V_14 )
return - V_33 ;
V_12 = F_18 ( & V_26 -> V_2 . V_20 , type -> V_34 ) ;
if ( V_12 )
goto error;
V_7 -> V_35 = F_19 ( & V_26 -> V_2 ) ;
if ( F_20 ( V_7 -> V_35 ) ) {
V_12 = F_21 ( V_7 -> V_35 ) ;
goto error;
}
return 0 ;
error:
F_22 ( & V_26 -> V_2 . V_20 , V_28 -> V_7 ) ;
F_23 ( V_7 -> V_14 ) ;
return V_12 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = F_25 ( V_26 ) ;
const struct V_27 * V_28 ;
F_26 ( V_7 -> V_35 ) ;
V_28 = F_16 ( V_32 , & V_26 -> V_2 ) ;
F_22 ( & V_26 -> V_2 . V_20 , V_28 -> V_7 ) ;
F_23 ( V_7 -> V_14 ) ;
return 0 ;
}
