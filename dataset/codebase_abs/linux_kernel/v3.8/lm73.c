static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
long V_11 ;
short V_12 ;
T_3 V_13 ;
int V_14 = F_4 ( V_5 , 10 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_12 = ( short ) F_5 ( V_11 / 250 , ( V_15 * 4 ) ,
( V_16 * 4 ) ) << 5 ;
V_13 = F_6 ( V_10 , V_8 -> V_17 , V_12 ) ;
return ( V_13 < 0 ) ? V_13 : V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_11 ;
T_3 V_13 = F_8 ( V_10 , V_8 -> V_17 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = ( ( ( V_18 ) V_13 ) * 250 ) / 32 ;
return F_9 ( V_5 , V_19 , L_1 , V_11 ) ;
}
static int
F_10 ( struct V_9 * V_10 , const struct V_20 * V_21 )
{
struct V_1 * V_22 ;
int V_14 ;
V_14 = F_11 ( & V_10 -> V_2 . V_23 , & V_24 ) ;
if ( V_14 )
return V_14 ;
V_22 = F_12 ( & V_10 -> V_2 ) ;
if ( F_13 ( V_22 ) ) {
V_14 = F_14 ( V_22 ) ;
goto V_25;
}
F_15 ( V_10 , V_22 ) ;
F_16 ( & V_10 -> V_2 , L_2 ,
F_17 ( V_22 ) , V_10 -> V_26 ) ;
return 0 ;
V_25:
F_18 ( & V_10 -> V_2 . V_23 , & V_24 ) ;
return V_14 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_22 = F_20 ( V_10 ) ;
F_21 ( V_22 ) ;
F_18 ( & V_10 -> V_2 . V_23 , & V_24 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
int V_21 , V_32 , V_33 ;
if ( ! F_23 ( V_31 , V_34 |
V_35 ) )
return - V_36 ;
V_32 = F_24 ( V_27 , V_37 ) ;
if ( V_32 < 0 || ( V_32 & 0x10 ) )
return - V_36 ;
V_33 = F_24 ( V_27 , V_38 ) ;
if ( V_33 < 0 || ( V_33 & 0x0c ) )
return - V_36 ;
V_21 = F_24 ( V_27 , V_39 ) ;
if ( V_21 < 0 || V_21 != ( V_40 & 0xff ) )
return - V_36 ;
V_21 = F_25 ( V_27 , V_39 ) ;
if ( V_21 < 0 || V_21 != V_40 )
return - V_36 ;
F_26 ( V_29 -> type , L_3 , V_41 ) ;
return 0 ;
}
