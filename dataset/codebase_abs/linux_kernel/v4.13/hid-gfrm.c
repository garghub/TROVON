static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
unsigned long V_11 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_11 == V_12 ) {
if ( V_8 -> V_13 == ( V_14 | 0x4 ) ) {
F_3 ( V_4 , V_8 , V_9 , V_10 , V_15 , V_16 ) ;
return 1 ;
}
if ( V_8 -> V_13 == ( V_14 | 0x41 ) ) {
F_3 ( V_4 , V_8 , V_9 , V_10 , V_15 , V_17 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_18 * V_19 ,
T_1 * V_20 , int V_21 )
{
unsigned long V_11 = ( unsigned long ) F_2 ( V_2 ) ;
int V_22 = 0 ;
if ( V_11 != V_12 )
return 0 ;
if ( V_21 < 2 || V_20 [ 0 ] != V_23 )
return 0 ;
switch ( V_20 [ 1 ] ) {
case V_24 :
V_22 = F_5 ( V_2 , V_25 , V_26 ,
sizeof( V_26 ) , 1 ) ;
break;
case V_27 :
break;
case V_28 :
V_22 = F_5 ( V_2 , V_25 , V_29 ,
sizeof( V_29 ) , 1 ) ;
break;
default:
break;
}
return ( V_22 < 0 ) ? V_22 : - 1 ;
}
static int F_6 ( struct V_1 * V_13 , struct V_3 * V_30 )
{
F_7 ( V_30 -> V_31 , 400 , 100 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const struct V_32 * V_33 )
{
int V_22 ;
F_9 ( V_2 , ( void * ) V_33 -> V_34 ) ;
V_22 = F_10 ( V_2 ) ;
if ( V_22 )
goto V_35;
if ( V_33 -> V_34 == V_12 ) {
if ( ! F_11 ( V_2 , V_25 ,
V_23 ) ) {
V_22 = - V_36 ;
goto V_35;
}
}
V_22 = F_12 ( V_2 , V_37 ) ;
V_35:
return V_22 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_9 ( V_2 , NULL ) ;
}
