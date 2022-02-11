static unsigned long F_1 ( void )
{
return ( 0xffffffffUL / F_2 () ) ;
}
static int F_3 ( void )
{
int V_1 ;
if ( V_2 != V_3 )
V_1 = 1 ;
else
V_1 = 0 ;
return V_1 ;
}
static void F_4 ( void )
{
F_5 ( & V_4 ) ;
F_6 ( V_2 ) ;
F_6 ( V_5 ) ;
F_7 ( & V_4 ) ;
}
static int F_8 ( void )
{
if ( F_3 () ) {
F_5 ( & V_4 ) ;
F_6 ( V_3 ) ;
F_6 ( V_6 ) ;
F_9 ( V_7 , & V_8 ) ;
F_7 ( & V_4 ) ;
F_10 ( V_9 L_1 ) ;
return 0 ;
} else
return 1 ;
}
static int F_11 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_12 ( V_12 , & V_8 ) )
return - V_13 ;
F_9 ( V_14 , & V_8 ) ;
F_4 () ;
F_13 ( V_7 , & V_8 ) ;
return F_14 ( V_10 , V_11 ) ;
}
static T_1 F_15 ( struct V_11 * V_11 , const char * V_15 , T_2 V_16 ,
T_3 * V_17 )
{
if ( V_16 ) {
if ( ! V_18 ) {
T_2 V_19 ;
F_9 ( V_14 , & V_8 ) ;
for ( V_19 = 0 ; V_19 != V_16 ; V_19 ++ ) {
char V_20 ;
if ( F_16 ( V_20 , V_15 + V_19 ) )
return - V_21 ;
if ( V_20 == 'V' )
F_13 ( V_14 , & V_8 ) ;
}
}
F_4 () ;
}
return V_16 ;
}
static long F_17 ( struct V_11 * V_11 ,
unsigned int V_22 , unsigned long V_23 )
{
int V_24 ;
int V_25 = - V_26 ;
int T_4 * V_27 = ( int T_4 * ) V_23 ;
switch ( V_22 ) {
case V_28 :
if ( F_18 ( V_27 , & V_29 , sizeof( V_29 ) ) )
V_25 = - V_21 ;
else
V_25 = 0 ;
break;
case V_30 :
V_25 = F_19 ( 0 , V_27 ) ;
break;
case V_31 :
V_25 = F_19 ( V_32 , V_27 ) ;
break;
case V_33 :
if ( F_16 ( V_24 , ( int * ) V_23 ) )
return - V_21 ;
if ( V_24 & V_34 ) {
if ( ! V_18 ) {
if ( F_8 () == 0 ) {
F_13 ( V_14 , & V_8 ) ;
V_25 = 0 ;
} else
V_25 = - V_35 ;
} else
V_25 = 0 ;
}
if ( V_24 & V_36 ) {
F_4 () ;
V_25 = 0 ;
}
break;
case V_37 :
F_4 () ;
V_25 = 0 ;
break;
case V_38 :
V_25 = F_19 ( F_1 () , V_27 ) ;
break;
}
return V_25 ;
}
static int F_20 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
int V_39 = 1 ;
if ( F_21 ( V_14 , & V_8 ) )
if ( F_21 ( V_7 , & V_8 ) )
V_39 = F_8 () ;
if ( V_39 != 0 ) {
F_4 () ;
F_10 ( V_40 L_2
L_3 , F_1 () ) ;
}
F_9 ( V_12 , & V_8 ) ;
F_9 ( V_14 , & V_8 ) ;
return 0 ;
}
static int T_5 F_22 ( void )
{
int V_25 ;
F_23 ( & V_4 ) ;
V_32 = ( F_24 () & V_41 ) ? V_42 : 0 ;
F_25 ( V_43 ) ;
V_25 = F_26 ( & V_44 ) ;
if ( V_25 == 0 )
F_10 ( V_9 L_4 ,
F_1 () ) ;
return V_25 ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_44 ) ;
}
