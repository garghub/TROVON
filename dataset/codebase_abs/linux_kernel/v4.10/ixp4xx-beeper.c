static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_2 ) {
F_3 ( V_1 , 0 ) ;
* V_5 = ( V_2 & ~ V_6 ) | V_7 ;
} else {
F_3 ( V_1 , 1 ) ;
F_4 ( V_1 ) ;
* V_5 = 0 ;
}
F_5 ( & V_4 , V_3 ) ;
}
static int F_6 ( struct V_8 * V_9 , unsigned int type , unsigned int V_10 , int V_11 )
{
unsigned int V_1 = ( unsigned int ) F_7 ( V_9 ) ;
unsigned int V_2 = 0 ;
if ( type != V_12 )
return - 1 ;
switch ( V_10 ) {
case V_13 :
if ( V_11 )
V_11 = 1000 ;
case V_14 :
break;
default:
return - 1 ;
}
if ( V_11 > 20 && V_11 < 32767 )
V_2 = ( V_15 / ( V_11 * 4 ) ) - 1 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
static T_1 F_8 ( int V_16 , void * V_17 )
{
unsigned int V_1 = ( unsigned int ) V_17 ;
* V_18 = V_19 ;
F_9 ( V_1 , ! F_10 ( V_1 ) ) ;
return V_20 ;
}
static int F_11 ( struct V_21 * V_9 )
{
struct V_8 * V_8 ;
int V_22 ;
V_8 = F_12 () ;
if ( ! V_8 )
return - V_23 ;
F_13 ( V_8 , ( void * ) V_9 -> V_24 ) ;
V_8 -> V_25 = L_1 ,
V_8 -> V_26 = L_2 ;
V_8 -> V_24 . V_27 = V_28 ;
V_8 -> V_24 . V_29 = 0x001f ;
V_8 -> V_24 . V_30 = 0x0001 ;
V_8 -> V_24 . V_31 = 0x0100 ;
V_8 -> V_9 . V_32 = & V_9 -> V_9 ;
V_8 -> V_33 [ 0 ] = F_14 ( V_12 ) ;
V_8 -> V_34 [ 0 ] = F_14 ( V_13 ) | F_14 ( V_14 ) ;
V_8 -> V_35 = F_6 ;
V_22 = F_15 ( V_9 -> V_24 , L_3 ) ;
if ( V_22 )
goto V_36;
V_22 = F_16 ( V_37 , & F_8 ,
V_38 , L_4 ,
( void * ) V_9 -> V_24 ) ;
if ( V_22 )
goto V_39;
V_22 = F_17 ( V_8 ) ;
if ( V_22 )
goto V_40;
F_18 ( V_9 , V_8 ) ;
return 0 ;
V_40:
F_19 ( V_37 , ( void * ) V_9 -> V_24 ) ;
V_39:
F_20 ( V_9 -> V_24 ) ;
V_36:
F_21 ( V_8 ) ;
return V_22 ;
}
static int F_22 ( struct V_21 * V_9 )
{
struct V_8 * V_8 = F_23 ( V_9 ) ;
unsigned int V_1 = ( unsigned int ) F_7 ( V_8 ) ;
F_24 ( V_8 ) ;
F_25 ( V_37 ) ;
F_1 ( V_1 , 0 ) ;
F_19 ( V_37 , ( void * ) V_9 -> V_24 ) ;
F_20 ( V_9 -> V_24 ) ;
return 0 ;
}
static void F_26 ( struct V_21 * V_9 )
{
struct V_8 * V_8 = F_23 ( V_9 ) ;
unsigned int V_1 = ( unsigned int ) F_7 ( V_8 ) ;
F_25 ( V_37 ) ;
F_1 ( V_1 , 0 ) ;
}
