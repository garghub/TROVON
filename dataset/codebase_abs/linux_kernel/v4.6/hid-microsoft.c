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
if ( ( V_11 -> V_16 & V_17 ) == V_18 ) {
switch ( V_11 -> V_16 & V_19 ) {
case 0x29d :
F_5 ( V_20 ) ;
return 1 ;
case 0x29e :
F_5 ( V_21 ) ;
return 1 ;
}
return 0 ;
}
if ( ( V_11 -> V_16 & V_17 ) != V_22 )
return 0 ;
switch ( V_11 -> V_16 & V_19 ) {
case 0xfd06 : F_5 ( V_23 ) ; break;
case 0xfd07 : F_5 ( V_24 ) ; break;
case 0xff00 :
F_5 ( V_25 ) ;
F_6 ( V_26 , V_15 -> V_27 ) ;
F_6 ( V_28 , V_15 -> V_27 ) ;
break;
case 0xff01 :
F_7 ( V_9 , V_11 , V_12 , V_13 , V_29 , V_30 ) ;
break;
case 0xff02 :
return - 1 ;
case 0xff05 :
F_6 ( V_31 , V_15 -> V_32 ) ;
F_5 ( V_33 ) ;
F_6 ( V_34 , V_15 -> V_27 ) ;
F_6 ( V_35 , V_15 -> V_27 ) ;
F_6 ( V_36 , V_15 -> V_27 ) ;
F_6 ( V_37 , V_15 -> V_27 ) ;
F_6 ( V_38 , V_15 -> V_27 ) ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
if ( ( V_11 -> V_16 & V_17 ) != V_22 )
return 0 ;
F_6 ( V_31 , V_9 -> V_15 -> V_32 ) ;
switch ( V_11 -> V_16 & V_19 ) {
case 0xfd08 : F_5 ( V_39 ) ; break;
case 0xfd09 : F_5 ( V_40 ) ; break;
case 0xfd0b : F_5 ( V_41 ) ; break;
case 0xfd0e : F_5 ( V_42 ) ; break;
case 0xfd0f : F_5 ( V_43 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_44 * V_45 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_5 & V_46 ) {
int V_47 = F_4 ( V_9 , V_11 , V_12 , V_13 ) ;
if ( V_47 )
return V_47 ;
}
if ( ( V_5 & V_48 ) &&
F_8 ( V_9 , V_11 , V_12 , V_13 ) )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_44 * V_45 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( V_5 & V_49 )
F_11 ( V_11 -> V_50 , * V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_10 * V_11 , T_2 V_51 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
struct V_14 * V_15 ;
if ( ! ( V_2 -> V_52 & V_53 ) || ! V_45 -> V_54 ||
! V_11 -> type )
return 0 ;
V_15 = V_45 -> V_54 -> V_15 ;
if ( V_5 & V_46 && V_11 -> V_16 == ( V_22 | 0xff00 ) ) {
F_13 ( V_15 , V_25 , V_51 & 0x01 ) ;
F_13 ( V_15 , V_26 , V_51 & 0x02 ) ;
F_13 ( V_15 , V_28 , V_51 & 0x04 ) ;
return 1 ;
}
if ( V_5 & V_46 && V_11 -> V_16 == ( V_22 | 0xff01 ) ) {
int V_55 = ( ( V_51 & 0x60 ) >> 5 ) + 1 ;
switch ( V_51 & 0x1f ) {
case 0x01 :
F_14 ( V_15 , V_30 , V_55 ) ;
break;
case 0x1f :
F_14 ( V_15 , V_30 , - V_55 ) ;
break;
}
return 1 ;
}
if ( V_5 & V_46 && V_11 -> V_16 == ( V_22 | 0xff05 ) ) {
static unsigned int V_56 = 0 ;
unsigned int V_57 = 0 ;
switch ( V_51 ) {
case 0x01 : V_57 = V_34 ; break;
case 0x02 : V_57 = V_35 ; break;
case 0x04 : V_57 = V_36 ; break;
case 0x08 : V_57 = V_37 ; break;
case 0x10 : V_57 = V_38 ; break;
}
if ( V_57 ) {
F_15 ( V_15 , V_11 -> type , V_57 , 1 ) ;
V_56 = V_57 ;
} else
F_15 ( V_15 , V_11 -> type , V_56 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const struct V_58 * V_59 )
{
unsigned long V_5 = V_59 -> V_60 ;
int V_47 ;
F_17 ( V_2 , ( void * ) V_5 ) ;
if ( V_5 & V_61 )
V_2 -> V_5 |= V_62 ;
V_47 = F_18 ( V_2 ) ;
if ( V_47 ) {
F_19 ( V_2 , L_2 ) ;
goto V_63;
}
V_47 = F_20 ( V_2 , V_64 | ( ( V_5 & V_65 ) ?
V_66 : 0 ) ) ;
if ( V_47 ) {
F_19 ( V_2 , L_3 ) ;
goto V_63;
}
return 0 ;
V_63:
return V_47 ;
}
