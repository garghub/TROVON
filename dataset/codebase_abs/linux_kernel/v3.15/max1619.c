static int F_1 ( int V_1 )
{
return ( V_1 & 0x80 ? V_1 - 0x100 : V_1 ) * 1000 ;
}
static int F_2 ( int V_1 )
{
return ( V_1 < 0 ? V_1 + 0x100 * 1000 : V_1 ) / 1000 ;
}
static T_1 F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
struct V_7 * V_8 = F_4 ( V_3 ) ;
return sprintf ( V_6 , L_1 , V_8 -> V_9 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
char * V_6 )
{
int V_10 = F_6 ( V_5 ) -> V_11 ;
struct V_7 * V_8 = F_4 ( V_3 ) ;
return sprintf ( V_6 , L_1 , ( V_8 -> V_9 >> V_10 ) & 1 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
T_2 V_18 , V_19 , V_20 , V_21 , V_22 ;
if ( ! F_8 ( V_17 , V_23 ) )
return - V_24 ;
V_18 = F_9 ( V_13 , V_25 ) ;
V_19 = F_9 ( V_13 , V_26 ) ;
V_20 = F_9 ( V_13 , V_27 ) ;
if ( ( V_18 & 0x03 ) != 0x00
|| V_19 > 0x07 || ( V_20 & 0x61 ) != 0x00 ) {
F_10 ( & V_17 -> V_3 , L_2 ,
V_13 -> V_28 ) ;
return - V_24 ;
}
V_21 = F_9 ( V_13 , V_29 ) ;
V_22 = F_9 ( V_13 , V_30 ) ;
if ( V_21 != 0x4D || V_22 != 0x04 ) {
F_11 ( & V_17 -> V_3 ,
L_3 ,
V_21 , V_22 ) ;
return - V_24 ;
}
F_12 ( V_15 -> type , L_4 , V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_32 ,
const struct V_33 * V_34 )
{
struct V_7 * V_8 ;
int V_35 ;
V_8 = F_14 ( & V_32 -> V_3 , sizeof( struct V_7 ) ,
V_36 ) ;
if ( ! V_8 )
return - V_37 ;
F_15 ( V_32 , V_8 ) ;
F_16 ( & V_8 -> V_38 ) ;
F_17 ( V_32 ) ;
V_35 = F_18 ( & V_32 -> V_3 . V_39 , & V_40 ) ;
if ( V_35 )
return V_35 ;
V_8 -> V_41 = F_19 ( & V_32 -> V_3 ) ;
if ( F_20 ( V_8 -> V_41 ) ) {
V_35 = F_21 ( V_8 -> V_41 ) ;
goto V_42;
}
return 0 ;
V_42:
F_22 ( & V_32 -> V_3 . V_39 , & V_40 ) ;
return V_35 ;
}
static void F_17 ( struct V_12 * V_13 )
{
T_2 V_43 ;
F_23 ( V_13 , V_44 ,
5 ) ;
V_43 = F_9 ( V_13 , V_25 ) ;
if ( V_43 & 0x40 )
F_23 ( V_13 , V_45 ,
V_43 & 0xBF ) ;
}
static int F_24 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = F_25 ( V_13 ) ;
F_26 ( V_8 -> V_41 ) ;
F_22 ( & V_13 -> V_3 . V_39 , & V_40 ) ;
return 0 ;
}
static struct V_7 * F_4 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_27 ( V_3 ) ;
struct V_7 * V_8 = F_25 ( V_13 ) ;
F_28 ( & V_8 -> V_38 ) ;
if ( F_29 ( V_46 , V_8 -> V_47 + V_48 * 2 ) || ! V_8 -> V_49 ) {
F_10 ( & V_13 -> V_3 , L_5 ) ;
V_8 -> V_50 = F_9 ( V_13 ,
V_51 ) ;
V_8 -> V_52 = F_9 ( V_13 ,
V_53 ) ;
V_8 -> V_54 = F_9 ( V_13 ,
V_55 ) ;
V_8 -> V_56 = F_9 ( V_13 ,
V_57 ) ;
V_8 -> V_58 = F_9 ( V_13 ,
V_59 ) ;
V_8 -> V_60 = F_9 ( V_13 ,
V_61 ) ;
V_8 -> V_9 = F_9 ( V_13 ,
V_27 ) ;
V_8 -> V_47 = V_46 ;
V_8 -> V_49 = 1 ;
}
F_30 ( & V_8 -> V_38 ) ;
return V_8 ;
}
