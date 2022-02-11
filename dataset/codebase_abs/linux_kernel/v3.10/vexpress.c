static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const char * V_6 = F_2 ( V_2 -> V_7 , L_1 ,
NULL ) ;
return sprintf ( V_5 , L_2 , V_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
const char * V_8 = F_2 ( V_2 -> V_7 , L_3 , NULL ) ;
if ( ! V_8 )
return - V_9 ;
return snprintf ( V_5 , V_10 , L_2 , V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
int V_13 ;
T_2 V_14 ;
V_13 = F_6 ( V_12 -> V_15 , 0 , & V_14 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_5 , V_10 , L_4 , V_14 /
F_7 ( V_4 ) -> V_16 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
int V_13 ;
T_2 V_17 , V_18 ;
V_13 = F_6 ( V_12 -> V_15 , 0 , & V_18 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_6 ( V_12 -> V_15 , 1 , & V_17 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_5 , V_10 , L_5 ,
F_9 ( ( ( V_19 ) V_17 << 32 ) | V_18 ,
F_7 ( V_4 ) -> V_16 ) ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
int V_13 ;
const struct V_22 * V_23 ;
struct V_11 * V_12 ;
V_12 = F_11 ( & V_21 -> V_2 , sizeof( * V_12 ) , V_24 ) ;
if ( ! V_12 )
return - V_25 ;
F_12 ( V_21 , V_12 ) ;
V_23 = F_13 ( V_26 , & V_21 -> V_2 ) ;
if ( ! V_23 )
return - V_27 ;
V_12 -> V_15 = F_14 ( & V_21 -> V_2 ) ;
if ( ! V_12 -> V_15 )
return - V_27 ;
V_13 = F_15 ( & V_21 -> V_2 . V_28 , V_23 -> V_12 ) ;
if ( V_13 )
goto error;
V_12 -> V_29 = F_16 ( & V_21 -> V_2 ) ;
if ( F_17 ( V_12 -> V_29 ) ) {
V_13 = F_18 ( V_12 -> V_29 ) ;
goto error;
}
return 0 ;
error:
F_19 ( & V_21 -> V_2 . V_28 , V_23 -> V_12 ) ;
F_20 ( V_12 -> V_15 ) ;
return V_13 ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_11 * V_12 = F_22 ( V_21 ) ;
const struct V_22 * V_23 ;
F_23 ( V_12 -> V_29 ) ;
V_23 = F_13 ( V_26 , & V_21 -> V_2 ) ;
F_19 ( & V_21 -> V_2 . V_28 , V_23 -> V_12 ) ;
F_20 ( V_12 -> V_15 ) ;
return 0 ;
}
