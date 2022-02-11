static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
T_2 V_6 ;
unsigned char V_7 ;
unsigned int V_8 = 0 ;
T_2 V_9 ;
F_2 ( & V_4 -> V_10 ) ;
V_5 = F_3 ( V_4 -> V_11 + V_12 ) ;
V_6 = F_3 ( V_4 -> V_11 + V_13 ) ;
if ( V_5 & V_14 ) {
V_8 = ( V_5 & V_14 ) ? V_15 : 0 ;
V_8 |= ( V_5 & V_16 ) ? V_17 : 0 ;
V_8 |= ( V_5 & V_16 ) ? V_18 : 0 ;
V_9 = V_19 | V_20 | V_21 |
V_16 | V_22 ;
F_4 ( V_9 , V_4 -> V_11 + V_12 ) ;
}
if ( V_6 & V_23 ) {
V_9 = V_24 | V_25 | V_26 |
V_27 | V_28 | V_29 ;
F_4 ( V_9 , V_4 -> V_11 + V_13 ) ;
}
V_9 = ( V_6 >> 16 ) & 0x3 ;
while ( V_9 -- ) {
V_7 = F_3 ( V_4 -> V_11 + V_30 ) & 0xff ;
F_5 ( V_4 -> V_31 , V_7 , V_8 ) ;
}
F_4 ( V_5 , V_4 -> V_11 + V_12 ) ;
F_4 ( V_6 , V_4 -> V_11 + V_13 ) ;
F_6 ( & V_4 -> V_10 ) ;
return V_32 ;
}
static int F_7 ( struct V_31 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_33 ;
T_2 V_34 = 0 ;
T_2 V_35 ;
T_2 V_36 ;
T_2 V_9 ;
unsigned long V_37 ;
V_9 = V_38 | V_39
| V_40 | V_41 ;
F_4 ( V_9 , V_4 -> V_11 + V_42 ) ;
V_9 = V_43 | V_44 | V_45
| V_46 | V_47
| V_48 | V_49 ;
F_4 ( V_9 , V_4 -> V_11 + V_50 ) ;
V_34 = F_8 ( V_4 -> V_51 ) ;
V_35 = V_34 / V_52 - 1 ;
V_36 = V_52 / V_53 - 1 ;
V_9 = ( V_35 << 8 ) | V_36 ;
F_4 ( V_9 , V_4 -> V_11 + V_54 ) ;
V_9 = V_55 | V_56 | V_57
| V_58 ;
F_9 ( & V_4 -> V_10 , V_37 ) ;
F_4 ( V_9 , V_4 -> V_11 + V_59 ) ;
F_10 ( & V_4 -> V_10 , V_37 ) ;
return 0 ;
}
static void F_11 ( struct V_31 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_33 ;
T_2 V_9 ;
V_9 = F_3 ( V_4 -> V_11 + V_59 ) ;
F_4 ( V_9 & ~ ( V_56 ) , V_4 -> V_11 + V_59 ) ;
F_12 ( V_4 -> V_1 ) ;
}
static int F_13 ( struct V_31 * V_31 , unsigned char V_60 )
{
unsigned long V_61 = V_62 + F_14 ( 10000 ) ;
struct V_3 * V_4 = V_31 -> V_33 ;
do {
if ( F_3 ( V_4 -> V_11 + V_13 ) & V_26 ) {
F_4 ( V_60 , V_4 -> V_11 + V_30 ) ;
return 0 ;
}
} while ( F_15 ( V_62 , V_61 ) );
return V_18 ;
}
static int F_16 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_3 * V_4 ;
struct V_31 * V_31 ;
struct V_67 * V_68 = & V_64 -> V_68 ;
unsigned int V_1 ;
int error ;
V_4 = F_17 ( sizeof( struct V_3 ) , V_69 ) ;
V_31 = F_17 ( sizeof( struct V_31 ) , V_69 ) ;
if ( ! V_4 || ! V_31 ) {
error = - V_70 ;
goto V_71;
}
F_18 ( & V_4 -> V_10 ) ;
V_66 = F_19 ( V_64 , V_72 , 0 ) ;
if ( ! V_66 ) {
F_20 ( V_68 , L_1 ) ;
error = - V_73 ;
goto V_71;
}
V_4 -> V_11 = F_21 ( V_66 -> V_74 , F_22 ( V_66 ) ) ;
if ( ! V_4 -> V_11 ) {
F_20 ( V_68 , L_2 ) ;
error = - V_70 ;
goto V_71;
}
V_4 -> V_51 = F_23 ( V_68 , NULL ) ;
if ( F_24 ( V_4 -> V_51 ) ) {
error = F_25 ( V_4 -> V_51 ) ;
F_20 ( V_68 , L_3 , error ) ;
goto V_75;
}
error = F_26 ( V_4 -> V_51 ) ;
if ( error ) {
F_20 ( V_68 , L_4 , error ) ;
goto V_76;
}
V_31 -> V_77 . type = V_78 ;
V_31 -> V_79 = F_13 ;
V_31 -> V_80 = F_7 ;
V_31 -> V_81 = F_11 ;
V_31 -> V_33 = V_4 ;
V_31 -> V_68 . V_82 = V_68 ;
F_27 ( V_31 -> V_83 , F_28 ( V_68 ) , sizeof( V_31 -> V_83 ) ) ;
F_27 ( V_31 -> V_84 , F_28 ( V_68 ) , sizeof( V_31 -> V_84 ) ) ;
F_4 ( 0 , V_4 -> V_11 + V_59 ) ;
V_1 = F_29 ( V_64 , 0 ) ;
if ( ! V_1 ) {
F_20 ( V_68 , L_5 ) ;
error = - V_73 ;
goto V_85;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_68 = V_68 ;
error = F_30 ( V_4 -> V_1 , F_1 , 0 ,
V_86 , V_4 ) ;
if ( error ) {
F_20 ( V_4 -> V_68 , L_6 ,
V_4 -> V_1 , error ) ;
goto V_85;
}
F_31 ( V_31 ) ;
F_32 ( V_64 , V_4 ) ;
return 0 ;
V_85:
F_33 ( V_4 -> V_51 ) ;
V_76:
F_34 ( V_4 -> V_51 ) ;
V_75:
F_35 ( V_4 -> V_11 ) ;
V_71:
F_36 ( V_31 ) ;
F_36 ( V_4 ) ;
return error ;
}
static int F_37 ( struct V_63 * V_64 )
{
struct V_3 * V_4 = F_38 ( V_64 ) ;
F_39 ( V_4 -> V_31 ) ;
F_40 ( V_4 -> V_1 , V_4 ) ;
F_33 ( V_4 -> V_51 ) ;
F_34 ( V_4 -> V_51 ) ;
F_35 ( V_4 -> V_11 ) ;
F_36 ( V_4 ) ;
return 0 ;
}
