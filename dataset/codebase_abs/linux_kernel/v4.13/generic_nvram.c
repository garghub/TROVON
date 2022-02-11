static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 ,
V_4 , V_5 ) ;
}
static T_2 F_3 ( struct V_1 * V_1 , char T_3 * V_6 ,
T_4 V_7 , T_1 * V_8 )
{
unsigned int V_9 ;
char T_3 * V_10 = V_6 ;
if ( ! F_4 ( V_11 , V_6 , V_7 ) )
return - V_12 ;
if ( * V_8 >= V_5 )
return 0 ;
for ( V_9 = * V_8 ; V_7 > 0 && V_9 < V_5 ; ++ V_9 , ++ V_10 , -- V_7 )
if ( F_5 ( F_6 ( V_9 ) , V_10 ) )
return - V_12 ;
* V_8 = V_9 ;
return V_10 - V_6 ;
}
static T_2 F_7 ( struct V_1 * V_1 , const char T_3 * V_6 ,
T_4 V_7 , T_1 * V_8 )
{
unsigned int V_9 ;
const char T_3 * V_10 = V_6 ;
char V_13 ;
if ( ! F_4 ( V_14 , V_6 , V_7 ) )
return - V_12 ;
if ( * V_8 >= V_5 )
return 0 ;
for ( V_9 = * V_8 ; V_7 > 0 && V_9 < V_5 ; ++ V_9 , ++ V_10 , -- V_7 ) {
if ( F_8 ( V_13 , V_10 ) )
return - V_12 ;
F_9 ( V_13 , V_9 ) ;
}
* V_8 = V_9 ;
return V_10 - V_6 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_15 , unsigned long V_16 )
{
switch( V_15 ) {
#ifdef F_11
case V_17 :
F_12 ( V_18 L_1 ) ;
case V_19 : {
int V_20 , V_2 ;
if ( ! F_13 ( V_21 ) )
return - V_22 ;
if ( F_14 ( & V_20 , ( void T_3 * ) V_16 , sizeof( V_20 ) ) != 0 )
return - V_12 ;
if ( V_20 < V_23 || V_20 > V_24 )
return - V_22 ;
V_2 = F_15 ( V_20 ) ;
if ( F_16 ( ( void T_3 * ) V_16 , & V_2 , sizeof( V_2 ) ) != 0 )
return - V_12 ;
break;
}
#endif
case V_25 :
F_17 () ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static long F_18 ( struct V_1 * V_1 , unsigned int V_15 , unsigned long V_16 )
{
int V_26 ;
F_19 ( & V_27 ) ;
V_26 = F_10 ( V_1 , V_15 , V_16 ) ;
F_20 ( & V_27 ) ;
return V_26 ;
}
int T_5 F_21 ( void )
{
int V_26 = 0 ;
F_12 ( V_28 L_2 ,
V_29 ) ;
V_26 = F_22 ( & V_30 ) ;
if ( V_26 != 0 )
goto V_31;
V_5 = F_23 () ;
if ( V_5 < 0 )
V_5 = V_32 ;
V_31:
return V_26 ;
}
void T_6 F_24 ( void )
{
F_25 ( & V_30 ) ;
}
