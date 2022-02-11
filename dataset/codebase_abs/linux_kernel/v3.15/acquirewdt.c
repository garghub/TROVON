static void F_1 ( void )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static T_1 F_4 ( struct V_3 * V_3 , const char T_2 * V_4 ,
T_3 V_5 , T_4 * V_6 )
{
if ( V_5 ) {
if ( ! V_7 ) {
T_3 V_8 ;
V_9 = 0 ;
for ( V_8 = 0 ; V_8 != V_5 ; V_8 ++ ) {
char V_10 ;
if ( F_5 ( V_10 , V_4 + V_8 ) )
return - V_11 ;
if ( V_10 == 'V' )
V_9 = 42 ;
}
}
F_1 () ;
}
return V_5 ;
}
static long F_6 ( struct V_3 * V_3 , unsigned int V_12 , unsigned long V_13 )
{
int V_14 , V_15 = - V_16 ;
void T_2 * V_17 = ( void T_2 * ) V_13 ;
int T_2 * V_18 = V_17 ;
static const struct V_19 V_20 = {
. V_14 = V_21 | V_22 ,
. V_23 = 1 ,
. V_24 = V_25 ,
} ;
switch ( V_12 ) {
case V_26 :
return F_7 ( V_17 , & V_20 , sizeof( V_20 ) ) ? - V_11 : 0 ;
case V_27 :
case V_28 :
return F_8 ( 0 , V_18 ) ;
case V_29 :
{
if ( F_5 ( V_14 , V_18 ) )
return - V_11 ;
if ( V_14 & V_30 ) {
F_3 () ;
V_15 = 0 ;
}
if ( V_14 & V_31 ) {
F_1 () ;
V_15 = 0 ;
}
return V_15 ;
}
case V_32 :
F_1 () ;
return 0 ;
case V_33 :
return F_8 ( V_34 , V_18 ) ;
default:
return - V_35 ;
}
}
static int F_9 ( struct V_36 * V_36 , struct V_3 * V_3 )
{
if ( F_10 ( 0 , & V_37 ) )
return - V_38 ;
if ( V_7 )
F_11 ( V_39 ) ;
F_1 () ;
return F_12 ( V_36 , V_3 ) ;
}
static int F_13 ( struct V_36 * V_36 , struct V_3 * V_3 )
{
if ( V_9 == 42 ) {
F_3 () ;
} else {
F_14 ( L_1 ) ;
F_1 () ;
}
F_15 ( 0 , & V_37 ) ;
V_9 = 0 ;
return 0 ;
}
static int T_5 F_16 ( struct V_40 * V_41 )
{
int V_42 ;
if ( V_2 != V_1 ) {
if ( ! F_17 ( V_2 , 1 , V_25 ) ) {
F_18 ( L_2 , V_2 ) ;
V_42 = - V_43 ;
goto V_44;
}
}
if ( ! F_17 ( V_1 , 1 , V_25 ) ) {
F_18 ( L_2 , V_1 ) ;
V_42 = - V_43 ;
goto V_45;
}
V_42 = F_19 ( & V_46 ) ;
if ( V_42 != 0 ) {
F_18 ( L_3 ,
V_47 , V_42 ) ;
goto V_48;
}
F_20 ( L_4 , V_7 ) ;
return 0 ;
V_48:
F_21 ( V_1 , 1 ) ;
V_45:
if ( V_2 != V_1 )
F_21 ( V_2 , 1 ) ;
V_44:
return V_42 ;
}
static int F_22 ( struct V_40 * V_41 )
{
F_23 ( & V_46 ) ;
F_21 ( V_1 , 1 ) ;
if ( V_2 != V_1 )
F_21 ( V_2 , 1 ) ;
return 0 ;
}
static void F_24 ( struct V_40 * V_41 )
{
F_3 () ;
}
static int T_5 F_25 ( void )
{
int V_49 ;
F_20 ( L_5 ) ;
V_50 = F_26 ( V_51 ,
- 1 , NULL , 0 ) ;
if ( F_27 ( V_50 ) )
return F_28 ( V_50 ) ;
V_49 = F_29 ( & V_52 , F_16 ) ;
if ( V_49 )
goto V_53;
return 0 ;
V_53:
F_30 ( V_50 ) ;
return V_49 ;
}
static void T_6 F_31 ( void )
{
F_30 ( V_50 ) ;
F_32 ( & V_52 ) ;
F_20 ( L_6 ) ;
}
