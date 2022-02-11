static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
if ( V_2 ) {
F_3 ( V_1 , V_5 ) ;
F_4 ( V_1 , V_6 ) ;
* V_7 = ( V_2 & ~ V_8 ) | V_9 ;
} else {
F_3 ( V_1 , V_10 ) ;
F_4 ( V_1 , V_11 ) ;
* V_7 = 0 ;
}
F_5 ( & V_4 , V_3 ) ;
}
static int F_6 ( struct V_12 * V_13 , unsigned int type , unsigned int V_14 , int V_15 )
{
unsigned int V_1 = ( unsigned int ) F_7 ( V_13 ) ;
unsigned int V_2 = 0 ;
if ( type != V_16 )
return - 1 ;
switch ( V_14 ) {
case V_17 :
if ( V_15 )
V_15 = 1000 ;
case V_18 :
break;
default:
return - 1 ;
}
if ( V_15 > 20 && V_15 < 32767 )
V_2 = ( V_19 / ( V_15 * 4 ) ) - 1 ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
static T_1 F_8 ( int V_20 , void * V_21 )
{
* V_22 = V_23 ;
* V_24 ^= ( 1 << ( unsigned int ) V_21 ) ;
return V_25 ;
}
static int T_2 F_9 ( struct V_26 * V_13 )
{
struct V_12 * V_12 ;
int V_27 ;
V_12 = F_10 () ;
if ( ! V_12 )
return - V_28 ;
F_11 ( V_12 , ( void * ) V_13 -> V_29 ) ;
V_12 -> V_30 = L_1 ,
V_12 -> V_31 = L_2 ;
V_12 -> V_29 . V_32 = V_33 ;
V_12 -> V_29 . V_34 = 0x001f ;
V_12 -> V_29 . V_35 = 0x0001 ;
V_12 -> V_29 . V_36 = 0x0100 ;
V_12 -> V_13 . V_37 = & V_13 -> V_13 ;
V_12 -> V_38 [ 0 ] = F_12 ( V_16 ) ;
V_12 -> V_39 [ 0 ] = F_12 ( V_17 ) | F_12 ( V_18 ) ;
V_12 -> V_40 = F_6 ;
V_27 = F_13 ( V_41 , & F_8 ,
V_42 | V_43 , L_3 ,
( void * ) V_13 -> V_29 ) ;
if ( V_27 )
goto V_44;
V_27 = F_14 ( V_12 ) ;
if ( V_27 )
goto V_45;
F_15 ( V_13 , V_12 ) ;
return 0 ;
V_45:
F_16 ( V_41 , V_13 ) ;
V_44:
F_17 ( V_12 ) ;
return V_27 ;
}
static int T_3 F_18 ( struct V_26 * V_13 )
{
struct V_12 * V_12 = F_19 ( V_13 ) ;
unsigned int V_1 = ( unsigned int ) F_7 ( V_12 ) ;
F_20 ( V_12 ) ;
F_15 ( V_13 , NULL ) ;
F_21 ( V_41 ) ;
F_1 ( V_1 , 0 ) ;
F_16 ( V_41 , V_13 ) ;
return 0 ;
}
static void F_22 ( struct V_26 * V_13 )
{
struct V_12 * V_12 = F_19 ( V_13 ) ;
unsigned int V_1 = ( unsigned int ) F_7 ( V_12 ) ;
F_21 ( V_41 ) ;
F_1 ( V_1 , 0 ) ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_46 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_46 ) ;
}
