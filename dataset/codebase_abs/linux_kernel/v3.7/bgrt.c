static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 -> V_9 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 -> V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 -> V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 -> V_12 ) ;
}
static T_1 F_6 ( struct V_13 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_4 , char * V_5 , T_2 V_17 , T_3 V_18 )
{
memcpy ( V_5 , V_4 -> V_19 + V_17 , V_18 ) ;
return V_18 ;
}
static int T_4 F_7 ( void )
{
int V_20 ;
if ( ! V_21 )
return - V_22 ;
F_8 ( & V_23 ) ;
V_23 . V_19 = V_21 ;
V_23 . V_24 = V_25 ;
V_26 = F_9 ( L_2 , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_20 = F_10 ( V_26 , & V_29 ) ;
if ( V_20 )
goto V_30;
V_20 = F_11 ( V_26 , & V_23 ) ;
if ( V_20 )
goto V_31;
return 0 ;
V_31:
F_12 ( V_26 , & V_29 ) ;
V_30:
F_13 ( V_26 ) ;
return V_20 ;
}
