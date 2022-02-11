static void F_1 ( int V_1 , void * V_2 )
{
F_2 ( L_1 ) ;
* V_3 = 0 ;
* V_4 = 0 ;
}
static void F_3 ( void )
{
* V_5 = V_6 ;
}
static int F_4 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
int V_9 ;
if ( * V_10 & ( 1 << 13 ) )
return - V_11 ;
if ( F_5 ( 1 , & V_12 ) )
return - V_11 ;
V_6 = V_13 * ( V_14 / 256 ) ;
* V_4 = 0 ;
F_3 () ;
* V_3 = V_15 | V_16
| V_17 ;
#ifdef F_6
V_9 = F_7 ( V_18 , F_1 , 0 , L_2 , NULL ) ;
if ( V_9 ) {
* V_3 = 0 ;
F_8 ( 1 , & V_12 ) ;
}
#else
* V_10 |= 1 << 13 ;
V_9 = 0 ;
#endif
F_9 ( V_7 , V_8 ) ;
return V_9 ;
}
static int F_10 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
#ifdef F_6
F_11 ( V_18 , NULL ) ;
F_8 ( 1 , & V_12 ) ;
#endif
return 0 ;
}
static T_1 F_12 ( struct V_8 * V_8 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
if ( V_20 )
F_3 () ;
return V_20 ;
}
static long F_13 ( struct V_8 * V_8 , unsigned int V_22 ,
unsigned long V_23 )
{
unsigned int V_24 ;
int T_2 * V_25 = ( int T_2 * ) V_23 ;
int V_9 = - V_26 ;
switch ( V_22 ) {
case V_27 :
V_9 = 0 ;
if ( F_14 ( ( void T_2 * ) V_23 , & V_28 , sizeof( V_28 ) ) )
V_9 = - V_29 ;
break;
case V_30 :
case V_31 :
V_9 = F_15 ( 0 , V_25 ) ;
break;
case V_32 :
F_3 () ;
V_9 = 0 ;
break;
case V_33 :
V_9 = F_16 ( V_24 , V_25 ) ;
if ( V_9 )
break;
if ( V_24 < 0 || V_24 > 60 ) {
V_9 = - V_34 ;
break;
}
V_13 = V_24 ;
V_6 = V_13 * ( V_14 / 256 ) ;
F_3 () ;
case V_35 :
V_9 = F_15 ( V_13 , V_25 ) ;
break;
}
return V_9 ;
}
static int T_5 F_17 ( void )
{
int V_36 ;
if ( F_18 () )
return - V_37 ;
V_36 = F_19 ( & V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
F_20 ( L_3 ,
V_13 ) ;
if ( F_21 () )
F_22 ( L_4 ) ;
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( & V_38 ) ;
}
