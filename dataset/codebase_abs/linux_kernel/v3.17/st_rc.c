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
if ( V_10 -> V_37 )
F_14 ( V_10 -> V_37 ) ;
F_15 ( V_10 -> V_38 ) ;
V_32 = F_16 ( V_10 -> V_38 ) ;
F_10 ( 1 , V_10 -> V_14 + V_39 ) ;
V_36 = V_32 / V_40 ;
F_10 ( V_36 , V_10 -> V_41 + V_42 ) ;
V_33 = V_32 - ( V_36 * V_40 ) ;
if ( V_33 ) {
V_10 -> V_25 = true ;
V_10 -> V_26 = 1000 ;
V_10 -> V_27 = V_32 / ( 10000 * V_36 ) ;
V_34 = ( V_34 * 1000 ) / V_10 -> V_27 ;
}
F_10 ( V_34 , V_10 -> V_14 + V_43 ) ;
}
static int F_17 ( struct V_44 * V_45 )
{
struct V_9 * V_1 = F_18 ( V_45 ) ;
F_19 ( V_1 -> V_38 ) ;
F_20 ( V_1 -> V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_46 ;
unsigned long V_47 ;
F_22 ( V_47 ) ;
F_10 ( V_30 , V_10 -> V_14 + V_48 ) ;
F_10 ( 0x01 , V_10 -> V_14 + V_49 ) ;
F_23 ( V_47 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_46 ;
F_10 ( 0x00 , V_10 -> V_14 + V_49 ) ;
F_10 ( 0x00 , V_10 -> V_14 + V_48 ) ;
}
static int F_25 ( struct V_44 * V_45 )
{
int V_50 = - V_51 ;
struct V_1 * V_2 ;
struct V_52 * V_10 = & V_45 -> V_10 ;
struct V_53 * V_54 ;
struct V_9 * V_1 ;
struct V_55 * V_56 = V_45 -> V_10 . V_57 ;
const char * V_58 ;
V_1 = F_26 ( V_10 , sizeof( struct V_9 ) , V_59 ) ;
if ( ! V_1 )
return - V_60 ;
V_2 = F_27 () ;
if ( ! V_2 )
return - V_60 ;
if ( V_56 && ! F_28 ( V_56 , L_2 , & V_58 ) ) {
if ( ! strcmp ( V_58 , L_3 ) ) {
V_1 -> V_61 = true ;
} else if ( ! strcmp ( V_58 , L_4 ) ) {
V_1 -> V_61 = false ;
} else {
F_29 ( V_10 , L_5 , V_58 ) ;
goto V_62;
}
} else {
goto V_62;
}
V_1 -> V_38 = F_30 ( V_10 , NULL ) ;
if ( F_31 ( V_1 -> V_38 ) ) {
F_29 ( V_10 , L_6 ) ;
V_50 = F_32 ( V_1 -> V_38 ) ;
goto V_62;
}
V_1 -> V_5 = F_33 ( V_45 , 0 ) ;
if ( V_1 -> V_5 < 0 ) {
V_50 = V_1 -> V_5 ;
goto V_62;
}
V_54 = F_34 ( V_45 , V_63 , 0 ) ;
V_1 -> V_41 = F_35 ( V_10 , V_54 ) ;
if ( F_31 ( V_1 -> V_41 ) ) {
V_50 = F_32 ( V_1 -> V_41 ) ;
goto V_62;
}
if ( V_1 -> V_61 )
V_1 -> V_14 = V_1 -> V_41 + 0x40 ;
else
V_1 -> V_14 = V_1 -> V_41 ;
V_1 -> V_37 = F_36 ( V_10 , NULL ) ;
if ( F_31 ( V_1 -> V_37 ) )
V_1 -> V_37 = NULL ;
V_1 -> V_10 = V_10 ;
F_37 ( V_45 , V_1 ) ;
F_13 ( V_1 ) ;
V_2 -> V_64 = V_65 ;
V_2 -> V_66 = V_67 ;
V_2 -> V_68 = 100 ;
V_2 -> V_4 = F_11 ( V_35 ) ;
V_2 -> V_46 = V_1 ;
V_2 -> V_69 = F_21 ;
V_2 -> V_70 = F_24 ;
V_2 -> V_71 = V_72 ;
V_2 -> V_73 = V_74 ;
V_2 -> V_75 = L_7 ;
F_38 ( V_10 , true ) ;
F_39 ( V_10 , true ) ;
V_50 = F_40 ( V_2 ) ;
if ( V_50 < 0 )
goto V_76;
V_1 -> V_2 = V_2 ;
if ( F_41 ( V_10 , V_1 -> V_5 , F_4 ,
V_77 , V_72 , V_1 ) < 0 ) {
F_29 ( V_10 , L_8 , V_1 -> V_5 ) ;
V_50 = - V_51 ;
goto V_78;
}
F_1 ( V_2 ) ;
F_9 ( V_10 , L_9 , V_1 -> V_61 ? L_10 : L_11 ) ;
return V_50 ;
V_78:
F_20 ( V_2 ) ;
V_2 = NULL ;
V_76:
F_19 ( V_1 -> V_38 ) ;
V_62:
F_42 ( V_2 ) ;
F_29 ( V_10 , L_12 , V_50 ) ;
return V_50 ;
}
static int F_43 ( struct V_52 * V_10 )
{
struct V_9 * V_1 = F_44 ( V_10 ) ;
if ( F_45 ( V_10 ) ) {
if ( ! F_46 ( V_1 -> V_5 ) )
V_1 -> V_13 = 1 ;
else
return - V_51 ;
} else {
F_47 ( V_10 ) ;
F_10 ( 0x00 , V_1 -> V_14 + V_49 ) ;
F_10 ( 0x00 , V_1 -> V_14 + V_48 ) ;
F_19 ( V_1 -> V_38 ) ;
if ( V_1 -> V_37 )
F_48 ( V_1 -> V_37 ) ;
}
return 0 ;
}
static int F_49 ( struct V_52 * V_10 )
{
struct V_9 * V_1 = F_44 ( V_10 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_1 -> V_13 ) {
F_50 ( V_1 -> V_5 ) ;
V_1 -> V_13 = 0 ;
} else {
F_51 ( V_10 ) ;
F_13 ( V_1 ) ;
if ( V_2 -> V_79 ) {
F_10 ( V_30 , V_1 -> V_14 + V_48 ) ;
F_10 ( 0x01 , V_1 -> V_14 + V_49 ) ;
}
}
return 0 ;
}
