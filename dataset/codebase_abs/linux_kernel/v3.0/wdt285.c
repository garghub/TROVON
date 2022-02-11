static void F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_3 L_1 ) ;
* V_4 = 0 ;
* V_5 = 0 ;
}
static void F_3 ( void )
{
* V_6 = V_7 ;
}
static int F_4 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
int V_10 ;
if ( * V_11 & ( 1 << 13 ) )
return - V_12 ;
if ( F_5 ( 1 , & V_13 ) )
return - V_12 ;
V_7 = V_14 * ( V_15 / 256 ) ;
* V_5 = 0 ;
F_3 () ;
* V_4 = V_16 | V_17
| V_18 ;
#ifdef F_6
V_10 = F_7 ( V_19 , F_1 , 0 , L_2 , NULL ) ;
if ( V_10 ) {
* V_4 = 0 ;
F_8 ( 1 , & V_13 ) ;
}
#else
* V_11 |= 1 << 13 ;
V_10 = 0 ;
#endif
F_9 ( V_8 , V_9 ) ;
return V_10 ;
}
static int F_10 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
#ifdef F_6
F_11 ( V_19 , NULL ) ;
F_8 ( 1 , & V_13 ) ;
#endif
return 0 ;
}
static T_1 F_12 ( struct V_9 * V_9 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
if ( V_21 )
F_3 () ;
return V_21 ;
}
static long F_13 ( struct V_9 * V_9 , unsigned int V_23 ,
unsigned long V_24 )
{
unsigned int V_25 ;
int T_2 * V_26 = ( int T_2 * ) V_24 ;
int V_10 = - V_27 ;
switch ( V_23 ) {
case V_28 :
V_10 = 0 ;
if ( F_14 ( ( void T_2 * ) V_24 , & V_29 , sizeof( V_29 ) ) )
V_10 = - V_30 ;
break;
case V_31 :
case V_32 :
V_10 = F_15 ( 0 , V_26 ) ;
break;
case V_33 :
F_3 () ;
V_10 = 0 ;
break;
case V_34 :
V_10 = F_16 ( V_25 , V_26 ) ;
if ( V_10 )
break;
if ( V_25 < 0 || V_25 > 60 ) {
V_10 = - V_35 ;
break;
}
V_14 = V_25 ;
V_7 = V_14 * ( V_15 / 256 ) ;
F_3 () ;
case V_36 :
V_10 = F_15 ( V_14 , V_26 ) ;
break;
}
return V_10 ;
}
static int T_5 F_17 ( void )
{
int V_37 ;
if ( F_18 () )
return - V_38 ;
V_37 = F_19 ( & V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
F_2 ( V_40
L_3 ,
V_14 ) ;
if ( F_20 () )
F_2 ( V_41
L_4 ) ;
return 0 ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_39 ) ;
}
