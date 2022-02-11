static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
T_2 V_4 ;
unsigned long V_5 = 0 ;
F_2 ( & V_3 -> V_6 ) ;
V_4 = F_3 ( V_3 -> V_7 + V_8 ) ;
F_4 ( V_4 , V_3 -> V_7 + V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( V_4 & 1 )
V_5 |= V_9 | V_10 ;
F_6 ( V_3 -> V_11 , 1 , V_5 ) ;
return V_12 ;
}
static int F_7 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_3 * V_3 = F_8 ( V_14 ) ;
T_2 V_17 , time ;
V_17 = F_3 ( V_3 -> V_7 + V_18 ) ;
time = F_3 ( V_3 -> V_7 + V_19 ) ;
V_16 -> V_20 = F_9 ( time & V_21 ) ;
V_16 -> V_22 = F_9 ( ( time & V_23 ) >> V_24 ) ;
V_16 -> V_25 = F_9 ( ( time & V_26 ) >> V_27 ) ;
V_16 -> V_28 = F_9 ( V_17 & V_29 ) ;
V_16 -> V_30 = F_9 ( ( V_17 & V_31 ) >> V_32 ) ;
V_16 -> V_33 = F_9 ( ( V_17 & V_34 ) >> V_35 )
+ ( ( V_17 >> V_36 ) & 1 ? 200 : 100 ) ;
V_16 -> V_37 = ( time & V_38 ) >> V_39 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_3 * V_3 = F_8 ( V_14 ) ;
if ( V_16 -> V_33 < 100 ) {
F_11 ( V_14 , L_1
L_2 ) ;
return - V_40 ;
}
F_4 ( ( F_12 ( V_16 -> V_33 - 100 ) << V_35 )
| ( F_12 ( V_16 -> V_30 ) << V_32 )
| ( F_12 ( V_16 -> V_28 ) ) ,
V_3 -> V_7 + V_41 ) ;
F_4 ( ( F_12 ( V_16 -> V_37 ) << V_39 )
| ( F_12 ( V_16 -> V_25 ) << V_27 )
| ( F_12 ( V_16 -> V_22 ) << V_24 )
| ( F_12 ( V_16 -> V_20 ) ) ,
V_3 -> V_7 + V_42 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_43 * V_44 )
{
struct V_3 * V_3 = F_8 ( V_14 ) ;
T_2 V_4 , V_45 ;
V_45 = F_3 ( V_3 -> V_7 + V_46 ) ;
V_4 = F_3 ( V_3 -> V_7 + V_8 ) ;
V_44 -> time . V_28 = F_9 ( ( V_45 & V_47 ) >> V_48 ) ;
V_44 -> time . V_25 = F_9 ( ( V_45 & V_26 ) >> V_27 ) ;
V_44 -> time . V_22 = F_9 ( ( V_45 & V_23 ) >> V_24 ) ;
V_44 -> time . V_20 = F_9 ( ( V_45 & V_21 ) ) ;
V_44 -> V_49 = ( V_45 & V_50 ) ? 1 : 0 ;
V_44 -> V_51 = ( V_4 & 1 ) ? 1 : 0 ;
return F_14 ( & V_44 -> time ) ;
}
static int F_15 ( struct V_13 * V_14 , struct V_43 * V_44 )
{
struct V_3 * V_3 = F_8 ( V_14 ) ;
F_4 ( ( V_44 -> V_49 ? V_50 : 0 )
| ( F_12 ( V_44 -> time . V_28 ) << V_48 )
| ( F_12 ( V_44 -> time . V_25 ) << V_27 )
| ( F_12 ( V_44 -> time . V_22 ) << V_24 )
| ( F_12 ( V_44 -> time . V_20 ) ) ,
V_3 -> V_7 + V_46 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , unsigned int V_49 )
{
struct V_3 * V_3 = F_8 ( V_14 ) ;
unsigned long V_52 = F_3 ( V_3 -> V_7 + V_46 ) ;
if ( V_49 )
V_52 |= V_50 ;
else
V_52 &= ~ V_50 ;
F_4 ( V_52 , V_3 -> V_7 + V_46 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_53 * V_54 )
{
struct V_3 * V_3 ;
int V_55 ;
V_3 = F_18 ( sizeof( struct V_3 ) , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
F_19 ( & V_3 -> V_6 ) ;
F_20 ( V_54 , V_3 ) ;
V_3 -> V_58 = F_21 ( V_54 , V_59 , 0 ) ;
if ( ! V_3 -> V_58 ) {
F_22 ( & V_54 -> V_14 , L_3 ) ;
V_55 = - V_60 ;
goto V_61;
}
V_3 -> V_62 = F_23 ( V_54 , 0 ) ;
if ( V_3 -> V_62 < 0 ) {
F_22 ( & V_54 -> V_14 , L_4 ) ;
V_55 = - V_60 ;
goto V_61;
}
V_3 -> V_58 = F_24 ( V_3 -> V_58 -> V_63 ,
F_25 ( V_3 -> V_58 ) ,
L_5 ) ;
if ( V_3 -> V_58 == NULL ) {
F_22 ( & V_54 -> V_14 , L_6 ) ;
V_55 = - V_64 ;
goto V_61;
}
V_3 -> V_7 = F_26 ( V_3 -> V_58 -> V_63 ,
F_25 ( V_3 -> V_58 ) ) ;
if ( ! V_3 -> V_7 ) {
F_22 ( & V_54 -> V_14 , L_7 ) ;
V_55 = - V_64 ;
goto V_65;
}
F_4 ( V_66 | V_67 ,
V_3 -> V_7 + V_68 ) ;
V_3 -> V_11 = F_27 ( L_5 , & V_54 -> V_14 ,
& V_69 , V_70 ) ;
if ( F_28 ( V_3 -> V_11 ) ) {
V_55 = F_29 ( V_3 -> V_11 ) ;
F_22 ( & V_54 -> V_14 ,
L_8 , V_55 ) ;
goto V_71;
}
V_55 = F_30 ( V_3 -> V_62 , F_1 , 0 ,
L_9 , V_3 ) ;
if ( V_55 < 0 ) {
F_22 ( & V_54 -> V_14 , L_10 ,
V_3 -> V_62 , V_55 ) ;
goto V_72;
}
return 0 ;
V_72:
F_31 ( V_3 -> V_11 ) ;
V_71:
F_32 ( V_3 -> V_7 ) ;
V_65:
F_33 ( V_3 -> V_58 -> V_63 ,
F_25 ( V_3 -> V_58 ) ) ;
V_61:
F_34 ( V_3 ) ;
return V_55 ;
}
static int T_4 F_35 ( struct V_53 * V_54 )
{
struct V_3 * V_3 = F_36 ( V_54 ) ;
F_37 ( V_3 -> V_62 , V_3 ) ;
F_31 ( V_3 -> V_11 ) ;
F_4 ( 0 , V_3 -> V_7 + V_8 ) ;
F_32 ( V_3 -> V_7 ) ;
F_33 ( V_3 -> V_58 -> V_63 ,
F_25 ( V_3 -> V_58 ) ) ;
F_34 ( V_3 ) ;
F_20 ( V_54 , NULL ) ;
return 0 ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_73 ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_73 ) ;
}
