static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_2 += V_1 -> V_4 ;
break;
case 2 :
V_2 += V_5 ;
break;
default:
V_2 = - 1 ;
}
if ( V_2 < 0 )
return - V_6 ;
V_1 -> V_4 = V_2 ;
return V_1 -> V_4 ;
}
static T_2 F_2 ( struct V_1 * V_1 , char T_3 * V_7 ,
T_4 V_8 , T_1 * V_9 )
{
unsigned int V_10 ;
char T_3 * V_11 = V_7 ;
if ( ! F_3 ( V_12 , V_7 , V_8 ) )
return - V_13 ;
if ( * V_9 >= V_5 )
return 0 ;
for ( V_10 = * V_9 ; V_8 > 0 && V_10 < V_5 ; ++ V_10 , ++ V_11 , -- V_8 )
if ( F_4 ( F_5 ( V_10 ) , V_11 ) )
return - V_13 ;
* V_9 = V_10 ;
return V_11 - V_7 ;
}
static T_2 F_6 ( struct V_1 * V_1 , const char T_3 * V_7 ,
T_4 V_8 , T_1 * V_9 )
{
unsigned int V_10 ;
const char T_3 * V_11 = V_7 ;
char V_14 ;
if ( ! F_3 ( V_15 , V_7 , V_8 ) )
return - V_13 ;
if ( * V_9 >= V_5 )
return 0 ;
for ( V_10 = * V_9 ; V_8 > 0 && V_10 < V_5 ; ++ V_10 , ++ V_11 , -- V_8 ) {
if ( F_7 ( V_14 , V_11 ) )
return - V_13 ;
F_8 ( V_14 , V_10 ) ;
}
* V_9 = V_10 ;
return V_11 - V_7 ;
}
static int F_9 ( struct V_1 * V_1 , unsigned int V_16 , unsigned long V_17 )
{
switch( V_16 ) {
#ifdef F_10
case V_18 :
F_11 ( V_19 L_1 ) ;
case V_20 : {
int V_21 , V_2 ;
if ( ! F_12 ( V_22 ) )
return - V_6 ;
if ( F_13 ( & V_21 , ( void T_3 * ) V_17 , sizeof( V_21 ) ) != 0 )
return - V_13 ;
if ( V_21 < V_23 || V_21 > V_24 )
return - V_6 ;
V_2 = F_14 ( V_21 ) ;
if ( F_15 ( ( void T_3 * ) V_17 , & V_2 , sizeof( V_2 ) ) != 0 )
return - V_13 ;
break;
}
#endif
case V_25 :
F_16 () ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static long F_17 ( struct V_1 * V_1 , unsigned int V_16 , unsigned long V_17 )
{
int V_26 ;
F_18 ( & V_27 ) ;
V_26 = F_9 ( V_1 , V_16 , V_17 ) ;
F_19 ( & V_27 ) ;
return V_26 ;
}
int T_5 F_20 ( void )
{
int V_26 = 0 ;
F_11 ( V_28 L_2 ,
V_29 ) ;
V_26 = F_21 ( & V_30 ) ;
if ( V_26 != 0 )
goto V_31;
V_5 = F_22 () ;
if ( V_5 < 0 )
V_5 = V_32 ;
V_31:
return V_26 ;
}
void T_6 F_23 ( void )
{
F_24 ( & V_30 ) ;
}
