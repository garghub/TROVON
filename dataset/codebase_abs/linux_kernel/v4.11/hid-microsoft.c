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
if ( ( V_10 -> V_15 & V_16 ) == V_17 ) {
switch ( V_10 -> V_15 & V_18 ) {
case 0x29d :
F_5 ( V_19 ) ;
return 1 ;
case 0x29e :
F_5 ( V_20 ) ;
return 1 ;
}
return 0 ;
}
if ( ( V_10 -> V_15 & V_16 ) != V_21 )
return 0 ;
switch ( V_10 -> V_15 & V_18 ) {
case 0xfd06 : F_5 ( V_22 ) ; break;
case 0xfd07 : F_5 ( V_23 ) ; break;
case 0xff00 :
F_5 ( V_24 ) ;
F_6 ( V_25 , V_14 -> V_26 ) ;
F_6 ( V_27 , V_14 -> V_26 ) ;
break;
case 0xff01 :
F_7 ( V_8 , V_10 , V_11 , V_12 , V_28 , V_29 ) ;
break;
case 0xff02 :
return - 1 ;
case 0xff05 :
F_6 ( V_30 , V_14 -> V_31 ) ;
F_5 ( V_32 ) ;
F_6 ( V_33 , V_14 -> V_26 ) ;
F_6 ( V_34 , V_14 -> V_26 ) ;
F_6 ( V_35 , V_14 -> V_26 ) ;
F_6 ( V_36 , V_14 -> V_26 ) ;
F_6 ( V_37 , V_14 -> V_26 ) ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
if ( ( V_10 -> V_15 & V_16 ) != V_21 )
return 0 ;
F_6 ( V_30 , V_8 -> V_14 -> V_31 ) ;
switch ( V_10 -> V_15 & V_18 ) {
case 0xfd08 : F_5 ( V_38 ) ; break;
case 0xfd09 : F_5 ( V_39 ) ; break;
case 0xfd0b : F_5 ( V_40 ) ; break;
case 0xfd0e : F_5 ( V_41 ) ; break;
case 0xfd0f : F_5 ( V_42 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_43 * V_44 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_5 & V_45 ) {
int V_46 = F_4 ( V_8 , V_10 , V_11 , V_12 ) ;
if ( V_46 )
return V_46 ;
}
if ( ( V_5 & V_47 ) &&
F_8 ( V_8 , V_10 , V_11 , V_12 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_43 * V_44 , struct V_9 * V_10 ,
unsigned long * * V_11 , int * V_12 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_5 & V_48 )
F_11 ( V_10 -> V_49 , * V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_9 * V_10 , T_2 V_50 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
struct V_13 * V_14 ;
if ( ! ( V_2 -> V_51 & V_52 ) || ! V_44 -> V_53 ||
! V_10 -> type )
return 0 ;
V_14 = V_44 -> V_53 -> V_14 ;
if ( V_5 & V_45 && V_10 -> V_15 == ( V_21 | 0xff00 ) ) {
F_13 ( V_14 , V_24 , V_50 & 0x01 ) ;
F_13 ( V_14 , V_25 , V_50 & 0x02 ) ;
F_13 ( V_14 , V_27 , V_50 & 0x04 ) ;
return 1 ;
}
if ( V_5 & V_45 && V_10 -> V_15 == ( V_21 | 0xff01 ) ) {
int V_54 = ( ( V_50 & 0x60 ) >> 5 ) + 1 ;
switch ( V_50 & 0x1f ) {
case 0x01 :
F_14 ( V_14 , V_29 , V_54 ) ;
break;
case 0x1f :
F_14 ( V_14 , V_29 , - V_54 ) ;
break;
}
return 1 ;
}
if ( V_5 & V_45 && V_10 -> V_15 == ( V_21 | 0xff05 ) ) {
static unsigned int V_55 = 0 ;
unsigned int V_56 = 0 ;
switch ( V_50 ) {
case 0x01 : V_56 = V_33 ; break;
case 0x02 : V_56 = V_34 ; break;
case 0x04 : V_56 = V_35 ; break;
case 0x08 : V_56 = V_36 ; break;
case 0x10 : V_56 = V_37 ; break;
}
if ( V_56 ) {
F_15 ( V_14 , V_10 -> type , V_56 , 1 ) ;
V_55 = V_56 ;
} else
F_15 ( V_14 , V_10 -> type , V_55 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_57 * V_58 )
{
unsigned long V_5 = V_58 -> V_59 ;
int V_46 ;
F_17 ( V_2 , ( void * ) V_5 ) ;
if ( V_5 & V_60 )
V_2 -> V_5 |= V_61 ;
V_46 = F_18 ( V_2 ) ;
if ( V_46 ) {
F_19 ( V_2 , L_2 ) ;
goto V_62;
}
V_46 = F_20 ( V_2 , V_63 | ( ( V_5 & V_64 ) ?
V_65 : 0 ) ) ;
if ( V_46 ) {
F_19 ( V_2 , L_3 ) ;
goto V_62;
}
return 0 ;
V_62:
return V_46 ;
}
