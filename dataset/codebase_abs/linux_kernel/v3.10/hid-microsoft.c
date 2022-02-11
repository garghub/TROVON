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
if ( ( V_5 & V_7 ) && * V_4 == 106 && V_3 [ 94 ] == 0x19 &&
V_3 [ 95 ] == 0x00 && V_3 [ 96 ] == 0x29 &&
V_3 [ 97 ] == 0xff ) {
V_3 [ 94 ] = 0x35 ;
V_3 [ 96 ] = 0x45 ;
}
return V_3 ;
}
static int F_4 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
struct V_14 * V_15 = V_9 -> V_15 ;
switch ( V_11 -> V_16 & V_17 ) {
case 0xfd06 : F_5 ( V_18 ) ; break;
case 0xfd07 : F_5 ( V_19 ) ; break;
case 0xff05 :
F_6 ( V_20 , V_15 -> V_21 ) ;
F_5 ( V_22 ) ;
F_6 ( V_23 , V_15 -> V_24 ) ;
F_6 ( V_25 , V_15 -> V_24 ) ;
F_6 ( V_26 , V_15 -> V_24 ) ;
F_6 ( V_27 , V_15 -> V_24 ) ;
F_6 ( V_28 , V_15 -> V_24 ) ;
default:
return 0 ;
}
return 1 ;
}
static int F_7 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
F_6 ( V_20 , V_9 -> V_15 -> V_21 ) ;
switch ( V_11 -> V_16 & V_17 ) {
case 0xfd08 : F_5 ( V_29 ) ; break;
case 0xfd09 : F_5 ( V_30 ) ; break;
case 0xfd0b : F_5 ( V_31 ) ; break;
case 0xfd0e : F_5 ( V_32 ) ; break;
case 0xfd0f : F_5 ( V_33 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_34 * V_35 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_11 -> V_16 & V_36 ) != V_37 )
return 0 ;
if ( V_5 & V_38 ) {
int V_39 = F_4 ( V_9 , V_11 , V_12 , V_13 ) ;
if ( V_39 )
return V_39 ;
}
if ( ( V_5 & V_40 ) &&
F_7 ( V_9 , V_11 , V_12 , V_13 ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_34 * V_35 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_5 & V_41 )
F_10 ( V_11 -> V_42 , * V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_10 * V_11 , T_2 V_43 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_44 & V_45 ) || ! V_35 -> V_46 ||
! V_11 -> type )
return 0 ;
if ( V_5 & V_38 && V_11 -> V_16 == ( V_37 | 0xff05 ) ) {
struct V_14 * V_15 = V_35 -> V_46 -> V_15 ;
static unsigned int V_47 = 0 ;
unsigned int V_48 = 0 ;
switch ( V_43 ) {
case 0x01 : V_48 = V_23 ; break;
case 0x02 : V_48 = V_25 ; break;
case 0x04 : V_48 = V_26 ; break;
case 0x08 : V_48 = V_27 ; break;
case 0x10 : V_48 = V_28 ; break;
}
if ( V_48 ) {
F_12 ( V_15 , V_11 -> type , V_48 , 1 ) ;
V_47 = V_48 ;
} else
F_12 ( V_15 , V_11 -> type , V_47 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const struct V_49 * V_50 )
{
unsigned long V_5 = V_50 -> V_51 ;
int V_39 ;
F_14 ( V_2 , ( void * ) V_5 ) ;
if ( V_5 & V_52 )
V_2 -> V_5 |= V_53 ;
V_39 = F_15 ( V_2 ) ;
if ( V_39 ) {
F_16 ( V_2 , L_2 ) ;
goto V_54;
}
V_39 = F_17 ( V_2 , V_55 | ( ( V_5 & V_56 ) ?
V_57 : 0 ) ) ;
if ( V_39 ) {
F_16 ( V_2 , L_3 ) ;
goto V_54;
}
return 0 ;
V_54:
return V_39 ;
}
