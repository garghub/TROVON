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
int V_19 = V_4 -> V_19 ;
void T_4 * V_20 = V_4 -> V_21 ;
if ( V_17 >= V_19 ) {
V_18 = 0 ;
} else {
if ( V_17 + V_18 > V_19 )
V_18 = V_19 - V_17 ;
F_7 ( V_5 , V_20 + V_17 , V_18 ) ;
}
return V_18 ;
}
static int T_5 F_8 ( void )
{
T_6 V_9 ;
int V_22 ;
void T_4 * V_23 ;
if ( V_24 )
return - V_25 ;
V_9 = F_9 ( L_2 , 0 ,
(struct V_26 * * ) & V_7 ) ;
if ( F_10 ( V_9 ) )
return - V_25 ;
F_11 ( & V_27 ) ;
V_23 = F_12 ( V_7 -> V_28 , sizeof( struct V_29 ) ) ;
if ( ! V_23 ) {
V_22 = - V_30 ;
goto V_31;
}
F_7 ( & V_29 , V_23 , sizeof( V_29 ) ) ;
V_27 . V_19 = V_29 . V_19 ;
F_13 ( V_23 ) ;
V_27 . V_21 = F_12 ( V_7 -> V_28 , V_27 . V_19 ) ;
if ( ! V_27 . V_21 ) {
V_22 = - V_30 ;
goto V_31;
}
V_32 = F_14 ( L_3 , V_33 ) ;
if ( ! V_32 ) {
V_22 = - V_30 ;
goto V_34;
}
V_22 = F_15 ( V_32 , & V_35 ) ;
if ( V_22 )
goto V_36;
V_22 = F_16 ( V_32 , & V_27 ) ;
if ( V_22 )
goto V_37;
return 0 ;
V_37:
F_17 ( V_32 , & V_35 ) ;
V_36:
F_18 ( V_32 ) ;
V_34:
F_13 ( V_27 . V_21 ) ;
V_31:
return V_22 ;
}
static void T_7 F_19 ( void )
{
F_13 ( V_27 . V_21 ) ;
F_17 ( V_32 , & V_35 ) ;
F_20 ( V_32 , & V_27 ) ;
}
