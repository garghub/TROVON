static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_4 ( V_9 -> V_11 , V_7 -> V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_13 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_10 ;
V_10 = F_4 ( V_9 -> V_11 , V_7 -> V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_5 , L_2 , ! ! ( V_10 & V_7 -> V_12 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
unsigned long V_16 ;
int V_10 ;
if ( F_8 ( V_5 , 10 , & V_16 ) )
return - V_17 ;
V_10 = F_9 ( V_9 -> V_11 , V_7 -> V_12 ,
F_10 ( V_16 , 1000 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return V_15 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_15 )
{
struct V_13 * V_7 = F_6 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_11 = V_9 -> V_11 ;
unsigned long V_16 ;
int V_10 ;
if ( F_8 ( V_5 , 10 , & V_16 ) )
return - V_17 ;
F_12 ( & V_9 -> V_19 ) ;
V_10 = F_4 ( V_11 , V_7 -> V_14 ) ;
if ( V_10 < 0 )
goto V_20;
V_10 &= ~ V_7 -> V_12 ;
if ( V_16 )
V_10 |= V_7 -> V_12 ;
V_10 = F_9 ( V_11 , V_7 -> V_12 , V_10 ) ;
if ( V_10 == 0 )
V_10 = V_15 ;
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_10 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_11 = V_9 -> V_11 ;
int V_10 ;
int V_21 ;
V_10 = F_4 ( V_11 , V_7 -> V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_15 ( V_22 , V_9 -> V_23 ) ) {
V_21 = F_4 ( V_11 , 0x21 ) ;
if ( V_21 < 0 )
return V_10 ;
V_9 -> V_24 = V_21 ;
V_9 -> V_23 = V_22 + V_25 ;
}
return sprintf ( V_5 , L_1 , V_10 - V_9 -> V_24 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_18 * V_11 = V_9 -> V_11 ;
int V_10 ;
int V_21 ;
unsigned long V_16 ;
if ( F_8 ( V_5 , 10 , & V_16 ) )
return - V_17 ;
F_12 ( & V_9 -> V_19 ) ;
V_10 = F_4 ( V_11 , V_7 -> V_12 ) ;
if ( V_10 < 0 )
goto V_20;
V_21 = V_16 - V_10 * 1000 ;
V_21 = F_10 ( V_21 , 1000 ) ;
if ( V_21 < 0 || V_21 > 255 ) {
V_10 = - V_26 ;
goto V_20;
}
V_10 = F_9 ( V_11 , 0x21 , V_21 ) ;
if ( V_10 == 0 ) {
V_10 = V_15 ;
V_9 -> V_24 = V_21 ;
V_9 -> V_23 = V_22 + V_25 ;
}
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_10 ;
}
static int F_17 ( struct V_18 * V_11 ,
struct V_27 * V_28 )
{
int V_29 ;
V_29 = F_4 ( V_11 , V_30 ) ;
if ( V_29 != 0x5d )
return - V_31 ;
V_29 = F_4 ( V_11 , V_32 ) ;
switch ( V_29 ) {
case 0x21 :
F_18 ( V_28 -> type , L_3 , V_33 ) ;
break;
case 0x23 :
F_18 ( V_28 -> type , L_4 , V_33 ) ;
break;
case 0x25 :
F_18 ( V_28 -> type , L_5 , V_33 ) ;
break;
case 0x27 :
F_18 ( V_28 -> type , L_6 , V_33 ) ;
break;
default:
return - V_31 ;
}
V_29 = F_4 ( V_11 , V_34 ) ;
if ( V_29 != 0x01 )
return - V_31 ;
return 0 ;
}
static int F_19 ( struct V_18 * V_11 ,
const struct V_35 * V_29 )
{
struct V_8 * V_9 ;
struct V_1 * V_36 ;
V_9 = F_20 ( & V_11 -> V_2 , sizeof( struct V_8 ) ,
V_37 ) ;
if ( V_9 == NULL )
return - V_38 ;
V_9 -> V_11 = V_11 ;
F_21 ( & V_9 -> V_19 ) ;
V_9 -> V_23 = V_22 - 1 ;
V_9 -> V_39 [ 0 ] = & V_40 ;
if ( V_29 -> V_41 )
V_9 -> V_39 [ 1 ] = & V_42 ;
V_36 = F_22 ( & V_11 -> V_2 ,
V_11 -> V_43 , V_9 ,
V_9 -> V_39 ) ;
if ( F_23 ( V_36 ) )
return F_24 ( V_36 ) ;
F_25 ( & V_11 -> V_2 , L_7 , V_29 -> V_43 ) ;
return 0 ;
}
