static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 , V_9 ;
F_3 ( & V_7 -> V_10 ) ;
V_8 = F_4 ( V_2 , V_3 ) ;
if ( V_8 < 0 )
goto V_11;
V_9 = ( V_8 >> V_5 ) & 3 ;
V_8 = F_4 ( V_2 , V_4 ) ;
if ( V_8 >= 0 )
V_8 = ( V_8 << 2 ) | V_9 ;
V_11:
F_5 ( & V_7 -> V_10 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
bool V_14 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_15 , V_8 ;
F_3 ( & V_7 -> V_10 ) ;
V_15 = F_4 ( V_2 , V_12 ) ;
if ( V_15 < 0 )
goto V_11;
if ( V_14 )
V_8 = V_15 | V_13 ;
else
V_8 = V_15 & ~ V_13 ;
V_15 = F_7 ( V_2 , V_12 , V_8 ) ;
V_11:
F_5 ( & V_7 -> V_10 ) ;
return V_15 ;
}
static T_2 F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_15 = F_1 ( V_2 , V_21 ,
V_22 , 2 ) ;
return V_15 < 0 ? V_15 : sprintf ( V_20 , L_1 , V_15 * 7000 / 1024 ) ;
}
static T_2 F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_8 = F_1 ( V_2 , V_21 ,
V_23 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = V_8 & 0x200 ? V_8 - 0x400 : V_8 ;
return sprintf ( V_20 , L_2 , V_8 * 250 ) ;
}
static T_2 F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
int V_24 = F_12 ( V_19 ) -> V_25 ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
T_1 V_3 , V_5 ;
F_3 ( & V_7 -> V_26 ) ;
if ( F_13 ( V_27 , V_7 -> V_28 ) ) {
V_8 = F_4 ( V_2 , V_29 ) ;
if ( V_8 < 0 )
goto V_11;
if ( V_8 & V_30 ) {
V_8 = F_1 ( V_2 ,
V_21 ,
V_22 , 2 ) ;
if ( V_8 < 0 )
goto V_11;
V_7 -> V_31 = V_8 * 7000 / 1024 ;
} else {
V_7 -> V_31 = 2250 ;
}
V_7 -> V_28 = V_27 + V_32 ;
}
V_3 = V_33 + ( V_24 >> 2 ) ;
V_5 = 2 * ( V_24 & 0x03 ) ;
V_8 = F_1 ( V_2 , V_3 ,
V_34 + V_24 , V_5 ) ;
if ( V_8 < 0 )
goto V_11;
V_8 = sprintf ( V_20 , L_1 , V_8 * V_7 -> V_31 / 1024 ) ;
V_11:
F_5 ( & V_7 -> V_26 ) ;
return V_8 ;
}
static T_2 F_14 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_35 * V_36 = F_15 ( V_19 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
int V_15 = F_4 ( V_2 , V_36 -> V_25 ) ;
return V_15 < 0 ? V_15 : sprintf ( V_20 , L_1 , ! ! ( V_15 & V_36 -> V_24 ) ) ;
}
static T_2 F_16 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 ,
T_3 V_37 )
{
struct V_35 * V_38 = F_15 ( V_19 ) ;
struct V_1 * V_2 = F_9 ( V_17 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_15 ;
unsigned long V_14 ;
V_15 = F_17 ( V_20 , 0 , & V_14 ) ;
if ( V_15 || V_14 > 1 )
return - V_39 ;
V_15 = F_6 ( V_2 , V_38 -> V_25 , V_38 -> V_24 , V_14 ) ;
F_3 ( & V_7 -> V_26 ) ;
V_7 -> V_28 = V_27 ;
F_5 ( & V_7 -> V_26 ) ;
return V_15 < 0 ? V_15 : V_37 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
int V_8 ;
if ( ! F_19 ( V_2 -> V_42 , V_43 ) )
return - V_44 ;
V_8 = F_4 ( V_2 , V_45 ) ;
if ( V_8 < 0 || V_8 != V_46 ) {
F_20 ( & V_2 -> V_17 , L_3
L_4 , V_8 , V_46 ) ;
return - V_44 ;
}
V_8 = F_4 ( V_2 , V_47 ) ;
if ( V_8 < 0 || V_8 != V_48 ) {
F_20 ( & V_2 -> V_17 , L_5
L_4 , V_8 , V_48 ) ;
return - V_44 ;
}
F_21 ( V_41 -> type , L_6 , V_49 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_6 * V_7 ;
int V_15 ;
V_7 = F_23 ( & V_2 -> V_17 , sizeof( * V_7 ) , V_52 ) ;
if ( ! V_7 )
return - V_53 ;
F_24 ( V_2 , V_7 ) ;
F_25 ( & V_7 -> V_10 ) ;
F_25 ( & V_7 -> V_26 ) ;
V_15 = F_6 ( V_2 , V_54 ,
V_55 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_7 -> V_28 = V_27 ;
V_15 = F_26 ( & V_2 -> V_17 . V_56 , & V_57 ) ;
if ( V_15 )
return V_15 ;
V_7 -> V_58 = F_27 ( & V_2 -> V_17 ) ;
if ( F_28 ( V_7 -> V_58 ) ) {
V_15 = F_29 ( V_7 -> V_58 ) ;
goto V_59;
}
F_30 ( & V_2 -> V_17 , L_7 ) ;
return 0 ;
V_59:
F_31 ( & V_2 -> V_17 . V_56 , & V_57 ) ;
return V_15 ;
}
static int T_5 F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_33 ( V_7 -> V_58 ) ;
F_31 ( & V_2 -> V_17 . V_56 , & V_57 ) ;
return 0 ;
}
