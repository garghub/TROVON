static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( 1 , V_4 -> V_6 + V_7 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
F_5 ( V_4 -> V_9 , 1 , V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
if ( F_8 ( V_4 -> V_6 + V_16 ) ) {
F_9 ( F_8 ( V_4 -> V_6 + V_17 ) , V_15 ) ;
F_4 ( V_4 -> V_5 ) ;
return F_10 ( V_15 ) ;
}
F_4 ( V_4 -> V_5 ) ;
return - V_18 ;
}
static int F_11 ( struct V_12 * V_13 , unsigned long V_19 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_19 , V_4 -> V_6 + V_20 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_9 ( F_8 ( V_4 -> V_6 + V_23 ) , & V_22 -> time ) ;
V_22 -> V_24 = F_8 ( V_4 -> V_6 + V_7 ) & 1U ;
V_22 -> V_25 = F_8 ( V_4 -> V_6 + V_8 ) & 1U ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
unsigned long time ;
F_14 ( & V_22 -> time , & time ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( time , V_4 -> V_6 + V_23 ) ;
F_3 ( V_22 -> V_25 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , unsigned int V_25 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
if ( V_25 )
F_3 ( 1 , V_4 -> V_6 + V_8 ) ;
else
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
if ( V_4 ) {
F_17 ( V_4 -> V_1 , V_4 ) ;
F_18 ( V_4 -> V_9 ) ;
F_19 ( V_4 -> V_5 ) ;
F_20 ( V_4 -> V_6 ) ;
F_21 ( V_4 -> V_28 , V_4 -> V_29 ) ;
F_22 ( V_27 , NULL ) ;
F_23 ( V_4 ) ;
}
return 0 ;
}
static int T_3 F_24 ( struct V_26 * V_27 )
{
int V_30 ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
V_4 = F_25 ( sizeof( struct V_3 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_32 = F_26 ( V_27 , V_35 , 0 ) ;
if ( ! V_32 ) {
V_30 = - V_36 ;
goto V_37;
}
V_4 -> V_28 = V_32 -> V_38 ;
V_4 -> V_29 = F_27 ( V_32 ) ;
if ( F_28 ( V_4 -> V_28 , V_4 -> V_29 ,
L_1 ) == NULL ) {
V_30 = - V_39 ;
goto V_40;
}
V_4 -> V_6 = F_29 ( V_4 -> V_28 , V_4 -> V_29 ) ;
if ( ! V_4 -> V_6 ) {
V_30 = - V_34 ;
goto V_41;
}
V_4 -> V_1 = F_30 ( V_27 , 0 ) ;
if ( F_31 ( V_4 -> V_1 , F_1 , V_42 ,
L_2 , V_4 ) ) {
V_30 = - V_43 ;
goto V_44;
}
V_4 -> V_5 = F_32 ( & V_27 -> V_13 , NULL ) ;
if ( F_33 ( V_4 -> V_5 ) ) {
V_30 = F_34 ( V_4 -> V_5 ) ;
F_35 ( & V_27 -> V_13 , L_3 ) ;
goto V_45;
}
V_30 = F_2 ( V_4 -> V_5 ) ;
if ( V_30 ) {
F_35 ( & V_27 -> V_13 , L_4 ) ;
goto V_46;
}
F_4 ( V_4 -> V_5 ) ;
F_22 ( V_27 , V_4 ) ;
V_4 -> V_9 = F_36 ( L_5 , & V_27 -> V_13 , & V_47 ,
V_48 ) ;
if ( F_33 ( V_4 -> V_9 ) ) {
V_30 = F_34 ( V_4 -> V_9 ) ;
goto V_49;
}
return 0 ;
V_49:
F_22 ( V_27 , NULL ) ;
V_46:
F_19 ( V_4 -> V_5 ) ;
V_45:
F_17 ( V_4 -> V_1 , V_4 ) ;
V_44:
F_20 ( V_4 -> V_6 ) ;
V_41:
F_22 ( V_27 , NULL ) ;
V_40:
F_21 ( V_4 -> V_28 , V_50 ) ;
V_37:
F_23 ( V_4 ) ;
return V_30 ;
}
static int F_37 ( struct V_26 * V_27 , T_4 V_51 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
if ( F_38 ( & V_27 -> V_13 ) ) {
F_39 ( V_4 -> V_1 ) ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_52 = F_8 ( V_4 -> V_6 + V_8 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static int F_40 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
if ( F_38 ( & V_27 -> V_13 ) ) {
F_41 ( V_4 -> V_1 ) ;
} else {
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_52 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static void F_42 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_53 , F_24 ) ;
}
static void T_2 F_45 ( void )
{
F_46 ( & V_53 ) ;
}
