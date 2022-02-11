static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
V_3 . V_4 = true ;
F_3 ( V_2 , & V_3 ) ;
}
static T_1 F_4 ( int V_5 , void * V_6 )
{
unsigned int V_7 , V_8 = 0 ;
struct V_9 * V_10 = V_6 ;
int V_11 = 0 ;
T_2 V_12 ;
F_2 ( V_3 ) ;
if ( V_10 -> V_13 )
F_5 ( V_10 -> V_10 , 0 ) ;
V_12 = F_6 ( V_10 -> V_14 + V_15 ) ;
while ( V_12 & ( V_16 | V_17 ) ) {
T_2 V_18 = F_6 ( V_10 -> V_14 + V_19 ) ;
if ( F_7 ( V_18 & V_20 ) ) {
F_8 ( V_10 -> V_2 ) ;
F_9 ( V_10 -> V_10 , L_1 ) ;
F_10 ( V_20 ,
V_10 -> V_14 + V_21 ) ;
continue;
}
V_7 = F_6 ( V_10 -> V_14 + V_22 ) ;
V_8 = F_6 ( V_10 -> V_14 + V_23 ) ;
if ( V_7 == V_24 )
V_11 = 1 ;
if ( ( V_8 > 2 ) && ( V_7 > 1 ) ) {
V_7 -= V_8 ;
if ( V_10 -> V_25 ) {
V_7 *= V_10 -> V_26 ;
V_7 /= V_10 -> V_27 ;
V_8 *= V_10 -> V_26 ;
V_8 /= V_10 -> V_27 ;
}
V_3 . V_28 = F_11 ( V_8 ) ;
V_3 . V_29 = true ;
F_3 ( V_10 -> V_2 , & V_3 ) ;
if ( ! V_11 ) {
V_3 . V_28 = F_11 ( V_7 ) ;
V_3 . V_29 = false ;
F_3 ( V_10 -> V_2 , & V_3 ) ;
} else {
F_1 ( V_10 -> V_2 ) ;
}
}
V_11 = 0 ;
V_12 = F_6 ( V_10 -> V_14 + V_15 ) ;
}
F_10 ( V_30 , V_10 -> V_14 + V_21 ) ;
F_12 ( V_10 -> V_2 ) ;
return V_31 ;
}
static void F_13 ( struct V_9 * V_10 )
{
int V_32 , V_33 ;
unsigned int V_34 = V_35 ;
unsigned int V_36 ;
F_14 ( V_10 -> V_37 ) ;
V_32 = F_15 ( V_10 -> V_37 ) ;
F_10 ( 1 , V_10 -> V_14 + V_38 ) ;
V_36 = V_32 / V_39 ;
F_10 ( V_36 , V_10 -> V_40 + V_41 ) ;
V_33 = V_32 - ( V_36 * V_39 ) ;
if ( V_33 ) {
V_10 -> V_25 = true ;
V_10 -> V_26 = 1000 ;
V_10 -> V_27 = V_32 / ( 10000 * V_36 ) ;
V_34 = ( V_34 * 1000 ) / V_10 -> V_27 ;
}
F_10 ( V_34 , V_10 -> V_14 + V_42 ) ;
}
static int F_16 ( struct V_43 * V_44 )
{
struct V_9 * V_1 = F_17 ( V_44 ) ;
F_18 ( V_1 -> V_37 ) ;
F_19 ( V_1 -> V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_45 ;
unsigned long V_46 ;
F_21 ( V_46 ) ;
F_10 ( V_30 , V_10 -> V_14 + V_47 ) ;
F_10 ( 0x01 , V_10 -> V_14 + V_48 ) ;
F_22 ( V_46 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_45 ;
F_10 ( 0x00 , V_10 -> V_14 + V_48 ) ;
F_10 ( 0x00 , V_10 -> V_14 + V_47 ) ;
}
static int F_24 ( struct V_43 * V_44 )
{
int V_49 = - V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_10 = & V_44 -> V_10 ;
struct V_52 * V_53 ;
struct V_9 * V_1 ;
struct V_54 * V_55 = V_44 -> V_10 . V_56 ;
const char * V_57 ;
V_1 = F_25 ( V_10 , sizeof( struct V_9 ) , V_58 ) ;
if ( ! V_1 )
return - V_59 ;
V_2 = F_26 () ;
if ( ! V_2 )
return - V_59 ;
if ( V_55 && ! F_27 ( V_55 , L_2 , & V_57 ) ) {
if ( ! strcmp ( V_57 , L_3 ) ) {
V_1 -> V_60 = true ;
} else if ( ! strcmp ( V_57 , L_4 ) ) {
V_1 -> V_60 = false ;
} else {
F_28 ( V_10 , L_5 , V_57 ) ;
goto V_61;
}
} else {
goto V_61;
}
V_1 -> V_37 = F_29 ( V_10 , NULL ) ;
if ( F_30 ( V_1 -> V_37 ) ) {
F_28 ( V_10 , L_6 ) ;
V_49 = F_31 ( V_1 -> V_37 ) ;
goto V_61;
}
V_1 -> V_5 = F_32 ( V_44 , 0 ) ;
if ( V_1 -> V_5 < 0 ) {
V_49 = V_1 -> V_5 ;
goto V_61;
}
V_53 = F_33 ( V_44 , V_62 , 0 ) ;
V_1 -> V_40 = F_34 ( V_10 , V_53 ) ;
if ( F_30 ( V_1 -> V_40 ) ) {
V_49 = F_31 ( V_1 -> V_40 ) ;
goto V_61;
}
if ( V_1 -> V_60 )
V_1 -> V_14 = V_1 -> V_40 + 0x40 ;
else
V_1 -> V_14 = V_1 -> V_40 ;
V_1 -> V_10 = V_10 ;
F_35 ( V_44 , V_1 ) ;
F_13 ( V_1 ) ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = 100 ;
V_2 -> V_4 = F_11 ( V_35 ) ;
V_2 -> V_45 = V_1 ;
V_2 -> V_68 = F_20 ;
V_2 -> V_69 = F_23 ;
V_2 -> V_70 = V_71 ;
V_2 -> V_72 = V_73 ;
V_2 -> V_74 = L_7 ;
F_36 ( V_10 , true ) ;
F_37 ( V_10 , true ) ;
V_49 = F_38 ( V_2 ) ;
if ( V_49 < 0 )
goto V_75;
V_1 -> V_2 = V_2 ;
if ( F_39 ( V_10 , V_1 -> V_5 , F_4 ,
V_76 , V_71 , V_1 ) < 0 ) {
F_28 ( V_10 , L_8 , V_1 -> V_5 ) ;
V_49 = - V_50 ;
goto V_77;
}
F_1 ( V_2 ) ;
F_9 ( V_10 , L_9 , V_1 -> V_60 ? L_10 : L_11 ) ;
return V_49 ;
V_77:
F_19 ( V_2 ) ;
V_2 = NULL ;
V_75:
F_18 ( V_1 -> V_37 ) ;
V_61:
F_40 ( V_2 ) ;
F_28 ( V_10 , L_12 , V_49 ) ;
return V_49 ;
}
static int F_41 ( struct V_51 * V_10 )
{
struct V_9 * V_1 = F_42 ( V_10 ) ;
if ( F_43 ( V_10 ) ) {
if ( ! F_44 ( V_1 -> V_5 ) )
V_1 -> V_13 = 1 ;
else
return - V_50 ;
} else {
F_45 ( V_10 ) ;
F_10 ( 0x00 , V_1 -> V_14 + V_48 ) ;
F_10 ( 0x00 , V_1 -> V_14 + V_47 ) ;
F_18 ( V_1 -> V_37 ) ;
}
return 0 ;
}
static int F_46 ( struct V_51 * V_10 )
{
struct V_9 * V_1 = F_42 ( V_10 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_1 -> V_13 ) {
F_47 ( V_1 -> V_5 ) ;
V_1 -> V_13 = 0 ;
} else {
F_48 ( V_10 ) ;
F_13 ( V_1 ) ;
if ( V_2 -> V_78 ) {
F_10 ( V_30 , V_1 -> V_14 + V_47 ) ;
F_10 ( 0x01 , V_1 -> V_14 + V_48 ) ;
}
}
return 0 ;
}
