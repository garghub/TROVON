static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
long V_11 ;
short V_12 ;
int V_13 = F_4 ( V_5 , 10 , & V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = ( short ) F_5 ( V_11 / 250 , ( V_14 * 4 ) ,
( V_15 * 4 ) ) << 5 ;
F_6 ( V_10 , V_8 -> V_16 , V_12 ) ;
return V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_11 = ( ( V_17 ) ( F_8 ( V_10 ,
V_8 -> V_16 ) ) * 250 ) / 32 ;
return sprintf ( V_5 , L_1 , V_11 ) ;
}
static int
F_9 ( struct V_9 * V_10 , const struct V_18 * V_19 )
{
struct V_1 * V_20 ;
int V_13 ;
V_13 = F_10 ( & V_10 -> V_2 . V_21 , & V_22 ) ;
if ( V_13 )
return V_13 ;
V_20 = F_11 ( & V_10 -> V_2 ) ;
if ( F_12 ( V_20 ) ) {
V_13 = F_13 ( V_20 ) ;
goto V_23;
}
F_14 ( V_10 , V_20 ) ;
F_15 ( & V_10 -> V_2 , L_2 ,
F_16 ( V_20 ) , V_10 -> V_24 ) ;
return 0 ;
V_23:
F_17 ( & V_10 -> V_2 . V_21 , & V_22 ) ;
return V_13 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_20 = F_19 ( V_10 ) ;
F_20 ( V_20 ) ;
F_17 ( & V_10 -> V_2 . V_21 , & V_22 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_25 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
int V_19 , V_30 , V_31 ;
if ( ! F_22 ( V_29 , V_32 |
V_33 ) )
return - V_34 ;
V_30 = F_23 ( V_25 , V_35 ) ;
if ( V_30 < 0 || ( V_30 & 0x10 ) )
return - V_34 ;
V_31 = F_23 ( V_25 , V_36 ) ;
if ( V_31 < 0 || ( V_31 & 0x0c ) )
return - V_34 ;
V_19 = F_23 ( V_25 , V_37 ) ;
if ( V_19 < 0 || V_19 != ( V_38 & 0xff ) )
return - V_34 ;
V_19 = F_24 ( V_25 , V_37 ) ;
if ( V_19 < 0 || V_19 != V_38 )
return - V_34 ;
F_25 ( V_27 -> type , L_3 , V_39 ) ;
return 0 ;
}
