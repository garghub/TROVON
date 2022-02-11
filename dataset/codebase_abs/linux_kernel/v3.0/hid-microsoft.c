static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_5 & V_6 ) && * V_4 == 571 && V_3 [ 557 ] == 0x19 &&
V_3 [ 559 ] == 0x29 ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 557 ] = 0x35 ;
V_3 [ 559 ] = 0x45 ;
}
return V_3 ;
}
static int F_4 ( struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
struct V_13 * V_14 = V_8 -> V_14 ;
switch ( V_10 -> V_15 & V_16 ) {
case 0xfd06 : F_5 ( V_17 ) ; break;
case 0xfd07 : F_5 ( V_18 ) ; break;
case 0xff05 :
F_6 ( V_19 , V_14 -> V_20 ) ;
F_5 ( V_21 ) ;
F_6 ( V_22 , V_14 -> V_23 ) ;
F_6 ( V_24 , V_14 -> V_23 ) ;
F_6 ( V_25 , V_14 -> V_23 ) ;
F_6 ( V_26 , V_14 -> V_23 ) ;
F_6 ( V_27 , V_14 -> V_23 ) ;
default:
return 0 ;
}
return 1 ;
}
static int F_7 ( struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
F_6 ( V_19 , V_8 -> V_14 -> V_20 ) ;
switch ( V_10 -> V_15 & V_16 ) {
case 0xfd08 : F_5 ( V_28 ) ; break;
case 0xfd09 : F_5 ( V_29 ) ; break;
case 0xfd0b : F_5 ( V_30 ) ; break;
case 0xfd0e : F_5 ( V_31 ) ; break;
case 0xfd0f : F_5 ( V_32 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_33 * V_34 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_10 -> V_15 & V_35 ) != V_36 )
return 0 ;
if ( V_5 & V_37 ) {
int V_38 = F_4 ( V_8 , V_10 , V_11 , V_12 ) ;
if ( V_38 )
return V_38 ;
}
if ( ( V_5 & V_39 ) &&
F_7 ( V_8 , V_10 , V_11 , V_12 ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_9 * V_10 , T_2 V_40 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_41 & V_42 ) || ! V_34 -> V_43 ||
! V_10 -> type )
return 0 ;
if ( V_5 & V_37 && V_10 -> V_15 == ( V_36 | 0xff05 ) ) {
struct V_13 * V_14 = V_34 -> V_43 -> V_14 ;
static unsigned int V_44 = 0 ;
unsigned int V_45 = 0 ;
switch ( V_40 ) {
case 0x01 : V_45 = V_22 ; break;
case 0x02 : V_45 = V_24 ; break;
case 0x04 : V_45 = V_25 ; break;
case 0x08 : V_45 = V_26 ; break;
case 0x10 : V_45 = V_27 ; break;
}
if ( V_45 ) {
F_10 ( V_14 , V_10 -> type , V_45 , 1 ) ;
V_44 = V_45 ;
} else
F_10 ( V_14 , V_10 -> type , V_44 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , const struct V_46 * V_47 )
{
unsigned long V_5 = V_47 -> V_48 ;
int V_38 ;
F_12 ( V_2 , ( void * ) V_5 ) ;
if ( V_5 & V_49 )
V_2 -> V_5 |= V_50 ;
V_38 = F_13 ( V_2 ) ;
if ( V_38 ) {
F_14 ( V_2 , L_2 ) ;
goto V_51;
}
V_38 = F_15 ( V_2 , V_52 | ( ( V_5 & V_53 ) ?
V_54 : 0 ) ) ;
if ( V_38 ) {
F_14 ( V_2 , L_3 ) ;
goto V_51;
}
return 0 ;
V_51:
return V_38 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_55 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_55 ) ;
}
