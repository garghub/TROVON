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
F_10 ( L_1 ) ;
return 0 ;
} else
return 1 ;
}
static int F_11 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
if ( F_12 ( V_11 , & V_8 ) )
return - V_12 ;
F_9 ( V_13 , & V_8 ) ;
F_4 () ;
F_13 ( V_7 , & V_8 ) ;
return F_14 ( V_9 , V_10 ) ;
}
static T_1 F_15 ( struct V_10 * V_10 , const char * V_14 , T_2 V_15 ,
T_3 * V_16 )
{
if ( V_15 ) {
if ( ! V_17 ) {
T_2 V_18 ;
F_9 ( V_13 , & V_8 ) ;
for ( V_18 = 0 ; V_18 != V_15 ; V_18 ++ ) {
char V_19 ;
if ( F_16 ( V_19 , V_14 + V_18 ) )
return - V_20 ;
if ( V_19 == 'V' )
F_13 ( V_13 , & V_8 ) ;
}
}
F_4 () ;
}
return V_15 ;
}
static long F_17 ( struct V_10 * V_10 ,
unsigned int V_21 , unsigned long V_22 )
{
int V_23 ;
int V_24 = - V_25 ;
int T_4 * V_26 = ( int T_4 * ) V_22 ;
switch ( V_21 ) {
case V_27 :
if ( F_18 ( V_26 , & V_28 , sizeof( V_28 ) ) )
V_24 = - V_20 ;
else
V_24 = 0 ;
break;
case V_29 :
V_24 = F_19 ( 0 , V_26 ) ;
break;
case V_30 :
V_24 = F_19 ( V_31 , V_26 ) ;
break;
case V_32 :
if ( F_16 ( V_23 , ( int * ) V_22 ) )
return - V_20 ;
if ( V_23 & V_33 ) {
if ( ! V_17 ) {
if ( F_8 () == 0 ) {
F_13 ( V_13 , & V_8 ) ;
V_24 = 0 ;
} else
V_24 = - V_34 ;
} else
V_24 = 0 ;
}
if ( V_23 & V_35 ) {
F_4 () ;
V_24 = 0 ;
}
break;
case V_36 :
F_4 () ;
V_24 = 0 ;
break;
case V_37 :
V_24 = F_19 ( F_1 () , V_26 ) ;
break;
}
return V_24 ;
}
static int F_20 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
int V_38 = 1 ;
if ( F_21 ( V_13 , & V_8 ) )
if ( F_21 ( V_7 , & V_8 ) )
V_38 = F_8 () ;
if ( V_38 != 0 ) {
F_4 () ;
F_22 ( L_2 ,
F_1 () ) ;
}
F_9 ( V_11 , & V_8 ) ;
F_9 ( V_13 , & V_8 ) ;
return 0 ;
}
static int T_5 F_23 ( void )
{
int V_24 ;
V_31 = ( F_24 () & V_39 ) ? V_40 : 0 ;
F_25 ( V_41 ) ;
V_24 = F_26 ( & V_42 ) ;
if ( V_24 == 0 )
F_10 ( L_3 , F_1 () ) ;
return V_24 ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_42 ) ;
}
