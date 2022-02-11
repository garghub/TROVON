static inline void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_3 = F_3 ( V_2 -> V_6 + V_7 ) ;
V_3 |= V_8 ;
F_4 ( V_3 , V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_3 ( V_2 -> V_6 + V_9 ) ;
if ( ! ( V_3 & V_10 ) ) {
F_1 ( V_2 ) ;
V_3 |= V_10 ;
F_4 ( V_3 , V_2 -> V_6 + V_9 ) ;
}
}
static inline void F_7 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_3 ( V_2 -> V_6 + V_9 ) ;
if ( V_3 & V_10 ) {
V_3 &= ~ V_10 ;
F_4 ( V_3 , V_2 -> V_6 + V_9 ) ;
}
}
static inline int F_8 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
if ( ( F_3 ( V_2 -> V_6 + V_7 ) ) & V_12 )
V_11 = - V_13 ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_14 , V_15 = 0 ;
unsigned long V_4 ;
for ( V_15 = 0 ; V_15 < 80 ; V_15 ++ ) {
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_14 = F_3 ( V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
if ( ( V_14 & V_16 ) == 0 )
break;
F_10 ( 1 ) ;
}
}
static T_1 F_11 ( int V_17 , void * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
unsigned long V_4 , V_22 = 0 ;
unsigned int V_23 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_23 = F_3 ( V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
if ( ( V_23 & V_8 ) ) {
F_1 ( V_2 ) ;
V_22 = V_24 | V_25 ;
F_13 ( V_20 , 1 , V_22 ) ;
return V_26 ;
} else
return V_27 ;
}
static int F_14 ( struct V_28 * V_29 )
{
if ( F_15 ( V_29 ) != 0 )
return - V_30 ;
V_29 -> V_31 = F_16 ( V_29 -> V_31 ) ;
V_29 -> V_32 = F_16 ( V_29 -> V_32 ) ;
V_29 -> V_33 = F_16 ( V_29 -> V_33 ) ;
V_29 -> V_34 = F_16 ( V_29 -> V_34 ) ;
V_29 -> V_35 = F_16 ( V_29 -> V_35 + 1 ) ;
V_29 -> V_36 = F_16 ( V_29 -> V_36 ) ;
return 0 ;
}
static void F_17 ( struct V_28 * V_29 )
{
V_29 -> V_31 = F_18 ( V_29 -> V_31 ) ;
V_29 -> V_32 = F_18 ( V_29 -> V_32 ) ;
V_29 -> V_33 = F_18 ( V_29 -> V_33 ) ;
V_29 -> V_34 = F_18 ( V_29 -> V_34 ) ;
V_29 -> V_35 = F_18 ( V_29 -> V_35 ) - 1 ;
V_29 -> V_36 = F_18 ( V_29 -> V_36 ) ;
}
static int F_19 ( struct V_37 * V_21 , struct V_28 * V_29 )
{
struct V_38 * V_39 = F_20 ( V_21 ) ;
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
unsigned int time , V_40 ;
F_9 ( V_2 ) ;
time = F_3 ( V_2 -> V_6 + V_41 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_42 ) ;
V_29 -> V_31 = ( time >> V_43 ) & V_44 ;
V_29 -> V_32 = ( time >> V_45 ) & V_46 ;
V_29 -> V_33 = ( time >> V_47 ) & V_48 ;
V_29 -> V_34 = ( V_40 >> V_49 ) & V_50 ;
V_29 -> V_35 = ( V_40 >> V_51 ) & V_52 ;
V_29 -> V_36 = ( V_40 >> V_53 ) & V_54 ;
F_17 ( V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_21 , struct V_28 * V_29 )
{
struct V_38 * V_39 = F_20 ( V_21 ) ;
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
unsigned int time , V_40 , V_55 = 0 ;
if ( F_14 ( V_29 ) < 0 )
return - V_30 ;
F_9 ( V_2 ) ;
time = ( V_29 -> V_31 << V_43 ) | ( V_29 -> V_32 << V_45 ) |
( V_29 -> V_33 << V_47 ) ;
V_40 = ( V_29 -> V_34 << V_49 ) | ( V_29 -> V_35 << V_51 ) |
( V_29 -> V_36 << V_53 ) ;
F_4 ( time , V_2 -> V_6 + V_41 ) ;
F_4 ( V_40 , V_2 -> V_6 + V_42 ) ;
V_55 = F_8 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static int F_23 ( struct V_37 * V_21 , struct V_56 * V_57 )
{
struct V_38 * V_39 = F_20 ( V_21 ) ;
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
unsigned int time , V_40 ;
F_9 ( V_2 ) ;
time = F_3 ( V_2 -> V_6 + V_58 ) ;
V_40 = F_3 ( V_2 -> V_6 + V_59 ) ;
V_57 -> time . V_31 = ( time >> V_43 ) & V_44 ;
V_57 -> time . V_32 = ( time >> V_45 ) & V_46 ;
V_57 -> time . V_33 = ( time >> V_47 ) & V_48 ;
V_57 -> time . V_34 = ( V_40 >> V_49 ) & V_50 ;
V_57 -> time . V_35 = ( V_40 >> V_51 ) & V_52 ;
V_57 -> time . V_36 = ( V_40 >> V_53 ) & V_54 ;
F_17 ( & V_57 -> time ) ;
V_57 -> V_60 = F_3 ( V_2 -> V_6 + V_9 ) & V_10 ;
return 0 ;
}
static int F_24 ( struct V_37 * V_21 , struct V_56 * V_57 )
{
struct V_38 * V_39 = F_20 ( V_21 ) ;
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
unsigned int time , V_40 , V_55 = 0 ;
if ( F_14 ( & V_57 -> time ) < 0 )
return - V_30 ;
F_9 ( V_2 ) ;
time = ( V_57 -> time . V_31 << V_43 ) | ( V_57 -> time . V_32 <<
V_45 ) | ( V_57 -> time . V_33 << V_47 ) ;
V_40 = ( V_57 -> time . V_34 << V_49 ) | ( V_57 -> time . V_35 <<
V_51 ) | ( V_57 -> time . V_36 << V_53 ) ;
F_4 ( time , V_2 -> V_6 + V_58 ) ;
F_4 ( V_40 , V_2 -> V_6 + V_59 ) ;
V_55 = F_8 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_57 -> V_60 )
F_6 ( V_2 ) ;
else
F_7 ( V_2 ) ;
return 0 ;
}
static int T_2 F_25 ( struct V_38 * V_39 )
{
struct V_61 * V_62 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
unsigned int V_14 = 0 ;
int V_17 ;
V_62 = F_26 ( V_39 , V_63 , 0 ) ;
if ( ! V_62 ) {
F_27 ( & V_39 -> V_21 , L_1 ) ;
return - V_64 ;
}
if ( ! F_28 ( V_62 -> V_65 , F_29 ( V_62 ) , V_39 -> V_66 ) ) {
F_27 ( & V_39 -> V_21 , L_2 ) ;
return - V_64 ;
}
V_2 = F_30 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 ) {
F_27 ( & V_39 -> V_21 , L_3 ) ;
V_14 = - V_68 ;
goto V_69;
}
V_2 -> V_70 = F_31 ( & V_39 -> V_21 , NULL ) ;
if ( F_32 ( V_2 -> V_70 ) ) {
V_14 = F_33 ( V_2 -> V_70 ) ;
goto V_71;
}
V_14 = F_34 ( V_2 -> V_70 ) ;
if ( V_14 < 0 )
goto V_72;
V_2 -> V_6 = F_35 ( V_62 -> V_65 , F_29 ( V_62 ) ) ;
if ( ! V_2 -> V_6 ) {
F_27 ( & V_39 -> V_21 , L_4 ) ;
V_14 = - V_68 ;
goto V_73;
}
F_36 ( & V_2 -> V_5 ) ;
V_20 = F_37 ( V_39 -> V_66 , & V_39 -> V_21 , & V_74 ,
V_75 ) ;
if ( F_32 ( V_20 ) ) {
F_27 ( & V_39 -> V_21 , L_5 ,
F_33 ( V_20 ) ) ;
V_14 = F_33 ( V_20 ) ;
goto V_76;
}
F_38 ( V_39 , V_20 ) ;
F_39 ( & V_20 -> V_21 , V_2 ) ;
V_17 = F_40 ( V_39 , 0 ) ;
if ( V_17 < 0 ) {
F_27 ( & V_39 -> V_21 , L_6 ) ;
V_14 = V_17 ;
goto V_77;
}
V_14 = F_41 ( V_17 , F_11 , 0 , V_39 -> V_66 , V_20 ) ;
if ( V_14 ) {
F_27 ( & V_39 -> V_21 , L_7 , V_17 ) ;
goto V_77;
}
if ( ! F_42 ( & V_39 -> V_21 ) )
F_43 ( & V_39 -> V_21 , 1 ) ;
return 0 ;
V_77:
F_38 ( V_39 , NULL ) ;
F_39 ( & V_20 -> V_21 , NULL ) ;
F_44 ( V_20 ) ;
V_76:
F_45 ( V_2 -> V_6 ) ;
V_73:
F_46 ( V_2 -> V_70 ) ;
V_72:
F_47 ( V_2 -> V_70 ) ;
V_71:
F_48 ( V_2 ) ;
V_69:
F_49 ( V_62 -> V_65 , F_29 ( V_62 ) ) ;
return V_14 ;
}
static int T_3 F_50 ( struct V_38 * V_39 )
{
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
int V_17 ;
struct V_61 * V_62 ;
F_7 ( V_2 ) ;
F_43 ( & V_39 -> V_21 , 0 ) ;
V_17 = F_40 ( V_39 , 0 ) ;
if ( V_17 )
F_51 ( V_17 , V_39 ) ;
F_46 ( V_2 -> V_70 ) ;
F_47 ( V_2 -> V_70 ) ;
F_45 ( V_2 -> V_6 ) ;
F_48 ( V_2 ) ;
V_62 = F_26 ( V_39 , V_63 , 0 ) ;
if ( V_62 )
F_49 ( V_62 -> V_65 , F_29 ( V_62 ) ) ;
F_38 ( V_39 , NULL ) ;
F_39 ( & V_20 -> V_21 , NULL ) ;
F_44 ( V_20 ) ;
return 0 ;
}
static int F_52 ( struct V_38 * V_39 , T_4 V_78 )
{
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
int V_17 ;
V_17 = F_40 ( V_39 , 0 ) ;
if ( F_53 ( & V_39 -> V_21 ) )
F_54 ( V_17 ) ;
else {
F_7 ( V_2 ) ;
F_46 ( V_2 -> V_70 ) ;
}
return 0 ;
}
static int F_55 ( struct V_38 * V_39 )
{
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
int V_17 ;
V_17 = F_40 ( V_39 , 0 ) ;
if ( F_53 ( & V_39 -> V_21 ) )
F_56 ( V_17 ) ;
else {
F_34 ( V_2 -> V_70 ) ;
F_6 ( V_2 ) ;
}
return 0 ;
}
static void F_57 ( struct V_38 * V_39 )
{
struct V_19 * V_20 = F_21 ( V_39 ) ;
struct V_1 * V_2 = F_12 ( & V_20 -> V_21 ) ;
F_7 ( V_2 ) ;
F_46 ( V_2 -> V_70 ) ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_79 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_79 ) ;
}
