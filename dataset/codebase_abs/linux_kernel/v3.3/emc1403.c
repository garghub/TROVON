static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
int V_10 = F_4 ( V_7 , V_9 -> V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_5 , L_1 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_12 * V_9 = F_6 ( V_4 ) ;
int V_10 = F_4 ( V_7 , V_9 -> V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= V_9 -> V_11 ;
return sprintf ( V_5 , L_2 , V_10 ? 1 : 0 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_15 ;
int V_10 ;
if ( F_8 ( V_5 , 10 , & V_15 ) )
return - V_16 ;
V_10 = F_9 ( V_7 , V_9 -> V_11 ,
F_10 ( V_15 , 1000 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return V_14 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_12 ( V_7 ) ;
struct V_12 * V_9 = F_6 ( V_4 ) ;
unsigned long V_15 ;
int V_10 ;
if ( F_8 ( V_5 , 10 , & V_15 ) )
return - V_16 ;
F_13 ( & V_18 -> V_19 ) ;
V_10 = F_4 ( V_7 , V_9 -> V_13 ) ;
if ( V_10 < 0 )
goto V_20;
V_10 &= ~ V_9 -> V_11 ;
if ( V_15 )
V_10 |= V_9 -> V_11 ;
V_10 = F_9 ( V_7 , V_9 -> V_11 , V_10 ) ;
if ( V_10 == 0 )
V_10 = V_14 ;
V_20:
F_14 ( & V_18 -> V_19 ) ;
return V_10 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_12 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
int V_10 ;
int V_21 ;
V_10 = F_4 ( V_7 , V_9 -> V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_16 ( V_22 , V_18 -> V_23 ) ) {
V_21 = F_4 ( V_7 , 0x21 ) ;
if ( V_21 < 0 )
return V_10 ;
V_18 -> V_24 = V_21 ;
V_18 -> V_23 = V_22 + V_25 ;
}
return sprintf ( V_5 , L_1 , V_10 - V_18 -> V_24 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_17 * V_18 = F_12 ( V_7 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
int V_10 ;
int V_21 ;
unsigned long V_15 ;
if ( F_8 ( V_5 , 10 , & V_15 ) )
return - V_16 ;
F_13 ( & V_18 -> V_19 ) ;
V_10 = F_4 ( V_7 , V_9 -> V_11 ) ;
if ( V_10 < 0 )
goto V_20;
V_21 = V_15 - V_10 * 1000 ;
V_21 = F_10 ( V_21 , 1000 ) ;
if ( V_21 < 0 || V_21 > 255 ) {
V_10 = - V_26 ;
goto V_20;
}
V_10 = F_9 ( V_7 , 0x21 , V_21 ) ;
if ( V_10 == 0 ) {
V_10 = V_14 ;
V_18 -> V_24 = V_21 ;
V_18 -> V_23 = V_22 + V_25 ;
}
V_20:
F_14 ( & V_18 -> V_19 ) ;
return V_10 ;
}
static int F_18 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
int V_29 ;
V_29 = F_4 ( V_7 , V_30 ) ;
if ( V_29 != 0x5d )
return - V_31 ;
V_29 = F_4 ( V_7 , V_32 ) ;
switch ( V_29 ) {
case 0x21 :
F_19 ( V_28 -> type , L_3 , V_33 ) ;
break;
case 0x23 :
F_19 ( V_28 -> type , L_4 , V_33 ) ;
break;
default:
return - V_31 ;
}
V_29 = F_4 ( V_7 , V_34 ) ;
if ( V_29 != 0x01 )
return - V_31 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
const struct V_35 * V_29 )
{
int V_36 ;
struct V_17 * V_18 ;
V_18 = F_21 ( sizeof( struct V_17 ) , V_37 ) ;
if ( V_18 == NULL ) {
F_22 ( & V_7 -> V_2 , L_5 ) ;
return - V_38 ;
}
F_23 ( V_7 , V_18 ) ;
F_24 ( & V_18 -> V_19 ) ;
V_18 -> V_23 = V_22 - 1 ;
V_36 = F_25 ( & V_7 -> V_2 . V_39 , & V_40 ) ;
if ( V_36 ) {
F_22 ( & V_7 -> V_2 , L_6 ) ;
goto V_41;
}
V_18 -> V_42 = F_26 ( & V_7 -> V_2 ) ;
if ( F_27 ( V_18 -> V_42 ) ) {
V_36 = F_28 ( V_18 -> V_42 ) ;
F_22 ( & V_7 -> V_2 , L_7 ) ;
goto V_43;
}
F_29 ( & V_7 -> V_2 , L_8 ) ;
return V_36 ;
V_43:
F_30 ( & V_7 -> V_2 . V_39 , & V_40 ) ;
V_41:
F_31 ( V_18 ) ;
return V_36 ;
}
static int F_32 ( struct V_6 * V_7 )
{
struct V_17 * V_18 = F_12 ( V_7 ) ;
F_33 ( V_18 -> V_42 ) ;
F_30 ( & V_7 -> V_2 . V_39 , & V_40 ) ;
F_31 ( V_18 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_44 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_44 ) ;
}
