static void F_1 ( void )
{
F_2 ( 1 , V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( 0 , V_1 ) ;
F_4 ( L_1 ) ;
}
static void F_5 ( void )
{
F_2 ( 1 , V_2 ) ;
}
static int F_6 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
if ( V_5 )
return - V_6 ;
if ( V_7 )
F_7 ( V_8 ) ;
F_1 () ;
F_5 () ;
V_5 = 1 ;
F_4 ( L_2 ) ;
return F_8 ( V_3 , V_4 ) ;
}
static int F_9 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
if ( ! V_7 )
F_3 () ;
V_5 = 0 ;
return 0 ;
}
static T_1 F_10 ( struct V_4 * V_4 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
if ( V_10 )
F_5 () ;
return V_10 ;
}
static long F_11 ( struct V_4 * V_4 , unsigned int V_12 ,
unsigned long V_13 )
{
int V_14 , V_15 = - V_16 ;
int T_2 * V_17 = ( void T_2 * ) V_13 ;
static const struct V_18 V_19 = {
. V_14 = V_20 ,
. V_21 = 0 ,
. V_22 = L_3 ,
} ;
switch ( V_12 ) {
case V_23 :
if ( F_12 ( V_17 , & V_19 , sizeof( V_19 ) ) )
return - V_24 ;
return 0 ;
case V_25 :
case V_26 :
return F_13 ( 0 , V_17 ) ;
case V_27 :
if ( F_14 ( V_14 , V_17 ) )
return - V_24 ;
if ( V_14 & V_28 ) {
F_3 () ;
V_15 = 0 ;
}
if ( V_14 & V_29 ) {
F_1 () ;
V_15 = 0 ;
}
return V_15 ;
case V_30 :
F_5 () ;
return 0 ;
case V_31 :
return F_13 ( V_32 , V_17 ) ;
default:
return - V_33 ;
}
}
static int F_15 ( struct V_34 * V_35 , unsigned long V_36 ,
void * V_37 )
{
if ( V_36 == V_38 || V_36 == V_39 )
F_3 () ;
return V_40 ;
}
static int T_5 F_16 ( void )
{
int V_41 ;
if ( ! F_17 ( V_1 , 2 , L_4 ) )
return - V_6 ;
V_41 = F_18 ( & V_42 ) ;
if ( V_41 ) {
F_19 ( L_5 , V_41 ) ;
goto V_43;
}
V_41 = F_20 ( & V_44 ) ;
if ( V_41 ) {
F_19 ( L_6 ,
V_45 , V_41 ) ;
F_21 ( & V_42 ) ;
goto V_43;
}
F_4 ( L_7 ) ;
return 0 ;
V_43:
F_22 ( V_1 , 2 ) ;
return V_41 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_44 ) ;
F_21 ( & V_42 ) ;
F_22 ( V_1 , 2 ) ;
}
