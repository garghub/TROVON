static void F_1 ( unsigned long V_1 , const char * V_2 )
{
unsigned long V_3 ;
if ( ! V_4 )
return;
V_3 = F_2 ( V_1 , F_3 ( V_2 ) ) ;
if ( V_3 ) {
F_4 ( V_5 L_1
L_2 ,
V_1 , V_2 , V_3 ) ;
}
}
static int F_5 ( struct V_6 * V_7 , unsigned long type , void * V_8 )
{
const char * V_2 ;
switch ( type ) {
case V_9 :
default:
V_2 = V_10 ;
break;
case V_11 :
V_2 = V_12 ;
break;
case V_13 :
V_2 = V_14 ;
break;
}
F_1 ( V_15 , V_2 ) ;
return V_16 ;
}
static int F_6 ( struct V_6 * V_17 , unsigned long V_18 , void * V_19 )
{
F_1 ( V_15 , V_20 ) ;
return V_21 ;
}
static int T_1 F_7 ( void )
{
unsigned long V_22 , V_23 ;
if ( V_24 != V_25 )
return 0 ;
V_22 = 1 ;
V_23 = 0 ;
if ( F_8 ( V_26 , V_22 , & V_23 ) )
return 0 ;
V_4 = 1 ;
F_9 () ;
F_1 ( V_15 , V_27 ) ;
F_10 ( & V_28 ,
& V_29 ) ;
F_11 ( & V_30 ) ;
return 0 ;
}
static int T_1 F_12 ( void )
{
F_1 ( V_31 , V_32 ) ;
return 0 ;
}
