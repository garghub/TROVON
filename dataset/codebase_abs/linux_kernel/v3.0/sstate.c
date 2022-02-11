static unsigned long F_1 ( const char * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
return V_3 + ( V_2 - V_4 ) ;
}
static void F_2 ( unsigned long V_5 , const char * V_6 )
{
unsigned long V_7 ;
if ( ! V_8 )
return;
V_7 = F_3 ( V_5 , F_1 ( V_6 ) ) ;
if ( V_7 ) {
F_4 ( V_9 L_1
L_2 ,
V_5 , V_6 , V_7 ) ;
}
}
static int F_5 ( struct V_10 * V_11 , unsigned long type , void * V_12 )
{
const char * V_6 ;
switch ( type ) {
case V_13 :
default:
V_6 = V_14 ;
break;
case V_15 :
V_6 = V_16 ;
break;
case V_17 :
V_6 = V_18 ;
break;
}
F_2 ( V_19 , V_6 ) ;
return V_20 ;
}
static int F_6 ( struct V_10 * V_21 , unsigned long V_22 , void * V_23 )
{
F_2 ( V_19 , V_24 ) ;
return V_25 ;
}
static int T_1 F_7 ( void )
{
unsigned long V_26 , V_27 ;
if ( V_28 != V_29 )
return 0 ;
V_26 = 1 ;
V_27 = 0 ;
if ( F_8 ( V_30 , V_26 , & V_27 ) )
return 0 ;
V_8 = 1 ;
F_9 () ;
F_2 ( V_19 , V_31 ) ;
F_10 ( & V_32 ,
& V_33 ) ;
F_11 ( & V_34 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
F_2 ( V_35 , V_36 ) ;
return 0 ;
}
