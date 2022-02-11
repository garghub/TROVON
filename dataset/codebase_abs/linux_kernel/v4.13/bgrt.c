static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 . V_8 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 . V_9 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 . V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 . V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , V_7 . V_12 ) ;
}
static T_1 F_6 ( struct V_13 * V_13 , struct V_14 * V_15 ,
struct V_16 * V_4 , char * V_5 , T_2 V_17 , T_3 V_18 )
{
memcpy ( V_5 , V_4 -> V_19 + V_17 , V_18 ) ;
return V_18 ;
}
int T_4 F_7 ( struct V_20 * V_21 )
{
F_8 ( V_21 ) ;
return 0 ;
}
static int T_4 F_9 ( void )
{
int V_22 ;
if ( ! V_7 . V_23 )
return - V_24 ;
V_25 = F_10 ( V_7 . V_23 , V_26 ,
V_27 ) ;
if ( ! V_25 ) {
F_11 ( L_2 ) ;
return - V_28 ;
}
V_29 . V_19 = V_25 ;
V_29 . V_30 = V_26 ;
V_31 = F_12 ( L_3 , V_32 ) ;
if ( ! V_31 ) {
V_22 = - V_33 ;
goto V_34;
}
V_22 = F_13 ( V_31 , & V_35 ) ;
if ( V_22 )
goto V_36;
return 0 ;
V_36:
F_14 ( V_31 ) ;
V_34:
F_15 ( V_25 ) ;
return V_22 ;
}
