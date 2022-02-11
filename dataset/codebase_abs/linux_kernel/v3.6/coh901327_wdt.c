static void F_1 ( T_1 V_1 )
{
T_1 V_2 ;
unsigned long V_3 ;
unsigned long V_4 ;
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
if ( V_2 == V_8 )
F_4 ( V_9 ,
V_6 + V_10 ) ;
F_4 ( V_11 ,
V_6 + V_12 ) ;
V_3 = F_5 ( V_5 ) ;
V_4 = F_6 ( 1000000000 , V_3 ) ;
V_4 = 3 * V_4 ;
F_7 ( V_4 ) ;
F_4 ( V_13 , V_6 + V_14 ) ;
F_4 ( V_1 , V_6 + V_15 ) ;
F_4 ( V_16 , V_6 + V_17 ) ;
( void ) F_3 ( V_6 + V_18 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
F_8 ( V_5 ) ;
if ( V_2 != V_19 )
F_9 ( V_20 ,
L_1 ,
V_21 , V_2 ) ;
}
static void F_10 ( void )
{
T_1 V_2 ;
F_2 ( V_5 ) ;
F_4 ( 0x0000U , V_6 + V_14 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
if ( V_2 != V_8 ) {
F_4 ( V_22 ,
V_6 + V_23 ) ;
F_4 ( V_24 ,
V_6 + V_7 ) ;
F_4 ( V_24 ,
V_6 + V_7 ) ;
}
V_2 = F_3 ( V_6 + V_7 ) ;
F_8 ( V_5 ) ;
if ( V_2 != V_8 )
F_9 ( V_20 ,
L_2 ,
V_21 , V_2 ) ;
}
static int F_11 ( struct V_25 * V_26 )
{
F_1 ( V_26 -> V_1 * 100 ) ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 )
{
F_10 () ;
return 0 ;
}
static int F_13 ( struct V_25 * V_27 )
{
F_2 ( V_5 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_25 * V_26 ,
unsigned int time )
{
V_26 -> V_1 = time ;
F_2 ( V_5 ) ;
F_4 ( time * 100 , V_6 + V_15 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static unsigned int F_15 ( struct V_25 * V_26 )
{
T_1 V_2 ;
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_18 ) ;
while ( V_2 & V_28 )
V_2 = F_3 ( V_6 + V_18 ) ;
V_2 &= V_29 ;
F_8 ( V_5 ) ;
if ( V_2 != 0 )
V_2 /= 100 ;
return V_2 ;
}
static T_2 F_16 ( int V_30 , void * V_31 )
{
T_1 V_2 ;
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_12 ) ;
if ( V_2 == V_32 )
F_4 ( V_11 ,
V_6 + V_12 ) ;
F_4 ( 0x0000U , V_6 + V_14 ) ;
F_8 ( V_5 ) ;
F_17 ( V_20 , L_3 ) ;
return V_33 ;
}
static int T_3 F_18 ( struct V_34 * V_35 )
{
F_19 ( & V_36 ) ;
F_10 () ;
F_20 ( V_30 , V_35 ) ;
F_21 ( V_5 ) ;
F_22 ( V_5 ) ;
F_23 ( V_6 ) ;
F_24 ( V_37 , V_38 ) ;
return 0 ;
}
static int T_4 F_25 ( struct V_34 * V_35 )
{
int V_39 ;
T_1 V_2 ;
struct V_40 * V_41 ;
V_41 = F_26 ( V_35 , V_42 , 0 ) ;
if ( ! V_41 )
return - V_43 ;
V_20 = & V_35 -> V_44 ;
V_38 = F_27 ( V_41 ) ;
V_37 = V_41 -> V_45 ;
if ( F_28 ( V_37 , V_38 , V_46 ) == NULL ) {
V_39 = - V_47 ;
goto V_48;
}
V_6 = F_29 ( V_37 , V_38 ) ;
if ( ! V_6 ) {
V_39 = - V_49 ;
goto V_50;
}
V_5 = F_30 ( & V_35 -> V_44 , NULL ) ;
if ( F_31 ( V_5 ) ) {
V_39 = F_32 ( V_5 ) ;
F_9 ( & V_35 -> V_44 , L_4 ) ;
goto V_51;
}
V_39 = F_33 ( V_5 ) ;
if ( V_39 ) {
F_9 ( & V_35 -> V_44 , L_5 ) ;
goto V_52;
}
V_2 = F_3 ( V_6 + V_53 ) ;
switch ( V_2 ) {
case V_54 :
F_34 ( & V_35 -> V_44 ,
L_6 ) ;
V_36 . V_55 |= V_56 ;
break;
case V_57 :
F_34 ( & V_35 -> V_44 ,
L_7 ) ;
break;
default:
F_34 ( & V_35 -> V_44 ,
L_8 , V_2 ) ;
break;
}
V_2 = F_3 ( V_6 + V_7 ) ;
switch ( V_2 ) {
case V_8 :
F_34 ( & V_35 -> V_44 , L_9 ) ;
break;
case V_19 :
F_34 ( & V_35 -> V_44 ,
L_10 ) ;
F_10 () ;
break;
default:
F_9 ( & V_35 -> V_44 ,
L_11 ,
V_2 ) ;
break;
}
F_4 ( V_58 , V_6 + V_53 ) ;
V_30 = F_35 ( V_35 , 0 ) ;
if ( F_36 ( V_30 , F_16 , 0 ,
V_46 L_12 , V_35 ) ) {
V_39 = - V_59 ;
goto V_60;
}
F_8 ( V_5 ) ;
if ( V_61 < 1 || V_61 > 327 )
V_61 = 60 ;
V_36 . V_1 = V_61 ;
V_39 = F_37 ( & V_36 ) ;
if ( V_39 == 0 )
F_34 ( & V_35 -> V_44 ,
L_13 , V_61 ) ;
else
goto V_62;
return 0 ;
V_62:
F_20 ( V_30 , V_35 ) ;
V_60:
F_38 ( V_5 ) ;
V_52:
F_22 ( V_5 ) ;
V_51:
F_23 ( V_6 ) ;
V_50:
F_24 ( V_37 , V_63 ) ;
V_48:
return V_39 ;
}
static int F_39 ( struct V_34 * V_35 , T_5 V_64 )
{
V_65 = F_3 ( V_6 + V_14 ) & 0x0001U ;
V_66 = F_3 ( V_6 + V_7 ) ;
if ( V_66 == V_19 )
F_10 () ;
return 0 ;
}
static int F_40 ( struct V_34 * V_35 )
{
F_4 ( V_65 , V_6 + V_14 ) ;
if ( V_66 == V_19 ) {
F_4 ( V_9 ,
V_6 + V_10 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
}
return 0 ;
}
void F_41 ( void )
{
F_4 ( V_67 ,
V_6 + V_68 ) ;
F_1 ( 500 ) ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_69 , F_25 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_69 ) ;
}
