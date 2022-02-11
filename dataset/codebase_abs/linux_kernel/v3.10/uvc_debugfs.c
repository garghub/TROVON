static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL )
return - V_9 ;
V_7 -> V_10 = F_3 ( V_4 , V_7 -> V_11 , sizeof( V_7 -> V_11 ) ) ;
V_2 -> V_12 = V_7 ;
return 0 ;
}
static T_1 F_4 ( struct V_2 * V_2 , char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
struct V_6 * V_7 = V_2 -> V_12 ;
return F_5 ( V_13 , V_14 , V_15 , V_7 -> V_11 ,
V_7 -> V_10 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
return 0 ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = V_4 -> V_18 -> V_17 ;
struct V_19 * V_20 ;
char V_21 [ 32 ] ;
if ( V_22 == NULL )
return - V_23 ;
sprintf ( V_21 , L_1 , V_17 -> V_24 -> V_25 , V_17 -> V_26 ) ;
V_20 = F_9 ( V_21 , V_22 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_27 , L_2
L_3 , V_21 ) ;
return - V_23 ;
}
V_4 -> V_28 = V_20 ;
V_20 = F_12 ( L_4 , 0444 , V_4 -> V_28 ,
V_4 , & V_29 ) ;
if ( F_10 ( V_20 ) ) {
F_11 ( V_27 , L_5 ) ;
F_13 ( V_4 ) ;
return - V_23 ;
}
return 0 ;
}
void F_13 ( struct V_3 * V_4 )
{
if ( V_4 -> V_28 == NULL )
return;
F_14 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
int F_15 ( void )
{
struct V_19 * V_30 ;
V_30 = F_9 ( L_6 , V_31 ) ;
if ( F_10 ( V_30 ) ) {
F_11 ( V_27 , L_7 ) ;
return - V_32 ;
}
V_22 = V_30 ;
return 0 ;
}
void F_16 ( void )
{
if ( V_22 != NULL )
F_14 ( V_22 ) ;
}
