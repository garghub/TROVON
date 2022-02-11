static void F_1 ( T_1 V_1 )
{
T_1 V_2 ;
unsigned long V_3 ;
unsigned long V_4 ;
V_2 = F_2 ( V_5 + V_6 ) ;
if ( V_2 == V_7 )
F_3 ( V_8 ,
V_5 + V_9 ) ;
F_3 ( V_10 ,
V_5 + V_11 ) ;
V_3 = F_4 ( V_12 ) ;
V_4 = F_5 ( 1000000000 , V_3 ) ;
V_4 = 3 * V_4 ;
F_6 ( V_4 ) ;
F_3 ( V_13 , V_5 + V_14 ) ;
F_3 ( V_1 , V_5 + V_15 ) ;
F_3 ( V_16 , V_5 + V_17 ) ;
( void ) F_2 ( V_5 + V_18 ) ;
V_2 = F_2 ( V_5 + V_6 ) ;
if ( V_2 != V_19 )
F_7 ( V_20 ,
L_1 ,
V_21 , V_2 ) ;
}
static void F_8 ( void )
{
T_1 V_2 ;
F_3 ( 0x0000U , V_5 + V_14 ) ;
V_2 = F_2 ( V_5 + V_6 ) ;
if ( V_2 != V_7 ) {
F_3 ( V_22 ,
V_5 + V_23 ) ;
F_3 ( V_24 ,
V_5 + V_6 ) ;
F_3 ( V_24 ,
V_5 + V_6 ) ;
}
V_2 = F_2 ( V_5 + V_6 ) ;
if ( V_2 != V_7 )
F_7 ( V_20 ,
L_2 ,
V_21 , V_2 ) ;
}
static int F_9 ( struct V_25 * V_26 )
{
F_1 ( V_26 -> V_1 * 100 ) ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
F_8 () ;
return 0 ;
}
static int F_11 ( struct V_25 * V_27 )
{
F_3 ( V_16 ,
V_5 + V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 ,
unsigned int time )
{
V_26 -> V_1 = time ;
F_3 ( time * 100 , V_5 + V_15 ) ;
F_3 ( V_16 ,
V_5 + V_17 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_25 * V_26 )
{
T_1 V_2 ;
V_2 = F_2 ( V_5 + V_18 ) ;
while ( V_2 & V_28 )
V_2 = F_2 ( V_5 + V_18 ) ;
V_2 &= V_29 ;
if ( V_2 != 0 )
V_2 /= 100 ;
return V_2 ;
}
static T_2 F_14 ( int V_30 , void * V_31 )
{
T_1 V_2 ;
V_2 = F_2 ( V_5 + V_11 ) ;
if ( V_2 == V_32 )
F_3 ( V_10 ,
V_5 + V_11 ) ;
F_3 ( 0x0000U , V_5 + V_14 ) ;
F_15 ( V_20 , L_3 ) ;
return V_33 ;
}
static int T_3 F_16 ( struct V_34 * V_35 )
{
F_17 ( & V_36 ) ;
F_8 () ;
F_18 ( V_30 , V_35 ) ;
F_19 ( V_12 ) ;
F_20 ( V_12 ) ;
return 0 ;
}
static int T_4 F_21 ( struct V_34 * V_35 )
{
struct V_37 * V_38 = & V_35 -> V_38 ;
int V_39 ;
T_1 V_2 ;
struct V_40 * V_41 ;
V_20 = V_38 ;
V_41 = F_22 ( V_35 , V_42 , 0 ) ;
V_5 = F_23 ( V_38 , V_41 ) ;
if ( F_24 ( V_5 ) )
return F_25 ( V_5 ) ;
V_12 = F_26 ( V_38 , NULL ) ;
if ( F_24 ( V_12 ) ) {
V_39 = F_25 ( V_12 ) ;
F_7 ( V_38 , L_4 ) ;
return V_39 ;
}
V_39 = F_27 ( V_12 ) ;
if ( V_39 ) {
F_7 ( V_38 , L_5 ) ;
goto V_43;
}
V_2 = F_2 ( V_5 + V_44 ) ;
switch ( V_2 ) {
case V_45 :
F_28 ( V_38 , L_6 ) ;
V_36 . V_46 |= V_47 ;
break;
case V_48 :
F_28 ( V_38 , L_7 ) ;
break;
default:
F_28 ( V_38 , L_8 , V_2 ) ;
break;
}
V_2 = F_2 ( V_5 + V_6 ) ;
switch ( V_2 ) {
case V_7 :
F_28 ( V_38 , L_9 ) ;
break;
case V_19 :
F_28 ( V_38 , L_10 ) ;
F_8 () ;
break;
default:
F_7 ( V_38 , L_11 ,
V_2 ) ;
break;
}
F_3 ( V_49 , V_5 + V_44 ) ;
V_30 = F_29 ( V_35 , 0 ) ;
if ( F_30 ( V_30 , F_14 , 0 ,
V_50 L_12 , V_35 ) ) {
V_39 = - V_51 ;
goto V_52;
}
V_39 = F_31 ( & V_36 , V_53 , V_38 ) ;
if ( V_39 < 0 )
V_36 . V_1 = 60 ;
V_36 . V_20 = V_38 ;
V_39 = F_32 ( & V_36 ) ;
if ( V_39 )
goto V_54;
F_28 ( V_38 , L_13 , V_53 ) ;
return 0 ;
V_54:
F_18 ( V_30 , V_35 ) ;
V_52:
F_19 ( V_12 ) ;
V_43:
F_20 ( V_12 ) ;
return V_39 ;
}
static int F_33 ( struct V_34 * V_35 , T_5 V_55 )
{
V_56 = F_2 ( V_5 + V_14 ) & 0x0001U ;
V_57 = F_2 ( V_5 + V_6 ) ;
if ( V_57 == V_19 )
F_8 () ;
return 0 ;
}
static int F_34 ( struct V_34 * V_35 )
{
F_3 ( V_56 , V_5 + V_14 ) ;
if ( V_57 == V_19 ) {
F_3 ( V_8 ,
V_5 + V_9 ) ;
F_3 ( V_16 ,
V_5 + V_17 ) ;
}
return 0 ;
}
void F_35 ( void )
{
F_3 ( V_58 ,
V_5 + V_59 ) ;
F_1 ( 500 ) ;
}
