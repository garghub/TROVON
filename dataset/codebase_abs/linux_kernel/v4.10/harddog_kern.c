static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 = - V_4 ;
char * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 ( & V_7 ) ;
if( V_8 )
goto V_3;
#ifdef F_4
F_5 ( V_9 ) ;
#endif
#ifdef F_6
V_5 = F_7 () ;
#endif
V_3 = F_8 ( & V_10 , & V_11 , V_5 ) ;
if( V_3 )
goto V_3;
V_8 = 1 ;
F_9 ( & V_7 ) ;
F_10 ( & V_6 ) ;
return F_11 ( V_1 , V_2 ) ;
V_3:
F_9 ( & V_7 ) ;
F_10 ( & V_6 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_3 ( & V_7 ) ;
F_13 ( V_10 , V_11 ) ;
V_10 = - 1 ;
V_11 = - 1 ;
V_8 = 0 ;
F_9 ( & V_7 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_2 * V_2 , const char T_2 * V_12 , T_3 V_13 ,
T_4 * V_14 )
{
if( V_13 )
return F_15 ( V_11 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_2 ,
unsigned int V_15 , unsigned long V_16 )
{
void T_2 * V_17 = ( void T_2 * ) V_16 ;
static struct V_18 V_19 = {
V_20 ,
0 ,
L_1
} ;
switch ( V_15 ) {
default:
return - V_21 ;
case V_22 :
if( F_17 ( V_17 , & V_19 , sizeof( V_19 ) ) )
return - V_23 ;
return 0 ;
case V_24 :
case V_25 :
return F_18 ( 0 , ( int T_2 * ) V_17 ) ;
case V_26 :
return F_15 ( V_11 ) ;
}
}
static long F_19 ( struct V_2 * V_2 ,
unsigned int V_15 , unsigned long V_16 )
{
long V_27 ;
F_2 ( & V_6 ) ;
V_27 = F_16 ( V_2 , V_15 , V_16 ) ;
F_10 ( & V_6 ) ;
return V_27 ;
}
