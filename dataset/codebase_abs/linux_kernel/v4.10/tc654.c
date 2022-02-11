static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = 0 ;
F_3 ( & V_4 -> V_8 ) ;
if ( F_4 ( V_9 , V_4 -> V_10 + V_11 ) &&
F_5 ( V_4 -> V_12 ) )
goto V_13;
V_7 = F_6 ( V_6 , F_7 ( 0 ) ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_14 [ 0 ] = V_7 ;
V_7 = F_6 ( V_6 , F_7 ( 1 ) ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_14 [ 1 ] = V_7 ;
V_7 = F_6 ( V_6 , F_8 ( 0 ) ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_15 [ 0 ] = V_7 ;
V_7 = F_6 ( V_6 , F_8 ( 1 ) ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_15 [ 1 ] = V_7 ;
V_7 = F_6 ( V_6 , V_16 ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_17 = V_7 ;
V_7 = F_6 ( V_6 , V_18 ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_19 = V_7 ;
V_7 = F_6 ( V_6 , V_20 ) ;
if ( V_7 < 0 )
goto V_13;
V_4 -> V_21 = V_7 & 0x0f ;
V_4 -> V_10 = V_9 ;
V_4 -> V_12 = true ;
V_13:
F_9 ( & V_4 -> V_8 ) ;
if ( V_7 < 0 )
V_4 = F_10 ( V_7 ) ;
return V_4 ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_27 ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
if ( V_4 -> V_17 & V_28 )
V_27 = V_4 -> V_14 [ V_25 ] * V_29 ;
else
V_27 = V_4 -> V_14 [ V_25 ] * V_30 ;
return sprintf ( V_24 , L_1 , V_27 ) ;
}
static T_1 F_15 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
return sprintf ( V_24 , L_1 ,
F_16 ( V_4 -> V_15 [ V_25 ] ) ) ;
}
static T_1 F_17 ( struct V_2 * V_3 , struct V_22 * V_23 ,
const char * V_24 , T_2 V_31 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_27 ;
int V_7 ;
if ( F_18 ( V_24 , 10 , & V_27 ) )
return - V_32 ;
V_27 = F_19 ( V_27 , 0 , 12750 ) ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_15 [ V_25 ] = F_20 ( V_27 ) ;
V_7 = F_21 ( V_6 , F_8 ( V_25 ) ,
V_4 -> V_15 [ V_25 ] ) ;
F_9 ( & V_4 -> V_8 ) ;
return V_7 < 0 ? V_7 : V_31 ;
}
static T_1 F_22 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_27 ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
if ( V_25 == 0 )
V_27 = ! ! ( V_4 -> V_19 & V_33 ) ;
else
V_27 = ! ! ( V_4 -> V_19 & V_34 ) ;
return sprintf ( V_24 , L_1 , V_27 ) ;
}
static T_1 F_23 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_27 ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
V_27 = F_24 ( ( V_4 -> V_17 >> V_35 [ V_25 ] ) & 0x03 ) ;
return sprintf ( V_24 , L_1 , V_27 ) ;
}
static T_1 F_25 ( struct V_2 * V_3 , struct V_22 * V_23 ,
const char * V_24 , T_2 V_31 )
{
int V_25 = F_12 ( V_23 ) -> V_26 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_3 V_17 ;
unsigned long V_27 ;
int V_7 ;
if ( F_18 ( V_24 , 10 , & V_27 ) )
return - V_32 ;
switch ( V_27 ) {
case 1 :
V_17 = 0 ;
break;
case 2 :
V_17 = 1 ;
break;
case 4 :
V_17 = 2 ;
break;
case 8 :
V_17 = 3 ;
break;
default:
return - V_32 ;
}
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_17 &= ~ ( 0x03 << V_35 [ V_25 ] ) ;
V_4 -> V_17 |= ( V_17 << V_35 [ V_25 ] ) ;
V_7 = F_21 ( V_6 , V_16 , V_4 -> V_17 ) ;
F_9 ( & V_4 -> V_8 ) ;
return V_7 < 0 ? V_7 : V_31 ;
}
static T_1 F_26 ( struct V_2 * V_3 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
return sprintf ( V_24 , L_1 , ! ! ( V_4 -> V_17 & V_36 ) ) ;
}
static T_1 F_27 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
const char * V_24 , T_2 V_31 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_27 ;
int V_7 ;
if ( F_18 ( V_24 , 10 , & V_27 ) )
return - V_32 ;
if ( V_27 != 0 && V_27 != 1 )
return - V_32 ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_27 )
V_4 -> V_17 |= V_36 ;
else
V_4 -> V_17 &= ~ V_36 ;
V_7 = F_21 ( V_6 , V_16 , V_4 -> V_17 ) ;
F_9 ( & V_4 -> V_8 ) ;
return V_7 < 0 ? V_7 : V_31 ;
}
static T_1 F_28 ( struct V_2 * V_3 , struct V_22 * V_23 ,
char * V_24 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_37 ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
if ( V_4 -> V_17 & V_38 )
V_37 = 0 ;
else
V_37 = V_39 [ V_4 -> V_21 ] ;
return sprintf ( V_24 , L_1 , V_37 ) ;
}
static T_1 F_29 ( struct V_2 * V_3 , struct V_22 * V_23 ,
const char * V_24 , T_2 V_31 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned long V_27 ;
int V_7 ;
if ( F_18 ( V_24 , 10 , & V_27 ) )
return - V_32 ;
if ( V_27 > 255 )
return - V_32 ;
F_3 ( & V_4 -> V_8 ) ;
if ( V_27 == 0 )
V_4 -> V_17 |= V_38 ;
else
V_4 -> V_17 &= ~ V_38 ;
V_4 -> V_21 = F_30 ( V_27 , V_39 ,
F_31 ( V_39 ) ) ;
V_7 = F_21 ( V_6 , V_16 , V_4 -> V_17 ) ;
if ( V_7 < 0 )
goto V_13;
V_7 = F_21 ( V_6 , V_20 ,
V_4 -> V_21 ) ;
V_13:
F_9 ( & V_4 -> V_8 ) ;
return V_7 < 0 ? V_7 : V_31 ;
}
static int F_32 ( struct V_5 * V_6 ,
const struct V_40 * V_41 )
{
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_42 ;
int V_7 ;
if ( ! F_33 ( V_6 -> V_43 , V_44 ) )
return - V_45 ;
V_4 = F_34 ( V_3 , sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_6 = V_6 ;
F_35 ( & V_4 -> V_8 ) ;
V_7 = F_6 ( V_6 , V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
V_4 -> V_17 = V_7 ;
V_42 =
F_36 ( V_3 , V_6 -> V_48 , V_4 ,
V_49 ) ;
return F_37 ( V_42 ) ;
}
