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
struct V_1 * V_2 = V_18 ;
unsigned long V_4 , V_19 = 0 ;
unsigned int V_20 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_20 = F_3 ( V_2 -> V_6 + V_7 ) ;
F_5 ( & V_2 -> V_5 , V_4 ) ;
if ( ( V_20 & V_8 ) ) {
F_1 ( V_2 ) ;
V_19 = V_21 | V_22 ;
F_12 ( V_2 -> V_23 , 1 , V_19 ) ;
return V_24 ;
} else
return V_25 ;
}
static int F_13 ( struct V_26 * V_27 )
{
if ( F_14 ( V_27 ) != 0 )
return - V_28 ;
V_27 -> V_29 = F_15 ( V_27 -> V_29 ) ;
V_27 -> V_30 = F_15 ( V_27 -> V_30 ) ;
V_27 -> V_31 = F_15 ( V_27 -> V_31 ) ;
V_27 -> V_32 = F_15 ( V_27 -> V_32 ) ;
V_27 -> V_33 = F_15 ( V_27 -> V_33 + 1 ) ;
V_27 -> V_34 = F_15 ( V_27 -> V_34 ) ;
return 0 ;
}
static void F_16 ( struct V_26 * V_27 )
{
V_27 -> V_29 = F_17 ( V_27 -> V_29 ) ;
V_27 -> V_30 = F_17 ( V_27 -> V_30 ) ;
V_27 -> V_31 = F_17 ( V_27 -> V_31 ) ;
V_27 -> V_32 = F_17 ( V_27 -> V_32 ) ;
V_27 -> V_33 = F_17 ( V_27 -> V_33 ) - 1 ;
V_27 -> V_34 = F_17 ( V_27 -> V_34 ) ;
}
static int F_18 ( struct V_35 * V_36 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int time , V_37 ;
F_9 ( V_2 ) ;
time = F_3 ( V_2 -> V_6 + V_38 ) ;
V_37 = F_3 ( V_2 -> V_6 + V_39 ) ;
V_27 -> V_29 = ( time >> V_40 ) & V_41 ;
V_27 -> V_30 = ( time >> V_42 ) & V_43 ;
V_27 -> V_31 = ( time >> V_44 ) & V_45 ;
V_27 -> V_32 = ( V_37 >> V_46 ) & V_47 ;
V_27 -> V_33 = ( V_37 >> V_48 ) & V_49 ;
V_27 -> V_34 = ( V_37 >> V_50 ) & V_51 ;
F_16 ( V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , struct V_26 * V_27 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int time , V_37 , V_52 = 0 ;
if ( F_13 ( V_27 ) < 0 )
return - V_28 ;
F_9 ( V_2 ) ;
time = ( V_27 -> V_29 << V_40 ) | ( V_27 -> V_30 << V_42 ) |
( V_27 -> V_31 << V_44 ) ;
V_37 = ( V_27 -> V_32 << V_46 ) | ( V_27 -> V_33 << V_48 ) |
( V_27 -> V_34 << V_50 ) ;
F_4 ( time , V_2 -> V_6 + V_38 ) ;
F_4 ( V_37 , V_2 -> V_6 + V_39 ) ;
V_52 = F_8 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_53 * V_54 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int time , V_37 ;
F_9 ( V_2 ) ;
time = F_3 ( V_2 -> V_6 + V_55 ) ;
V_37 = F_3 ( V_2 -> V_6 + V_56 ) ;
V_54 -> time . V_29 = ( time >> V_40 ) & V_41 ;
V_54 -> time . V_30 = ( time >> V_42 ) & V_43 ;
V_54 -> time . V_31 = ( time >> V_44 ) & V_45 ;
V_54 -> time . V_32 = ( V_37 >> V_46 ) & V_47 ;
V_54 -> time . V_33 = ( V_37 >> V_48 ) & V_49 ;
V_54 -> time . V_34 = ( V_37 >> V_50 ) & V_51 ;
F_16 ( & V_54 -> time ) ;
V_54 -> V_57 = F_3 ( V_2 -> V_6 + V_9 ) & V_10 ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 , struct V_53 * V_54 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
unsigned int time , V_37 , V_52 = 0 ;
if ( F_13 ( & V_54 -> time ) < 0 )
return - V_28 ;
F_9 ( V_2 ) ;
time = ( V_54 -> time . V_29 << V_40 ) | ( V_54 -> time . V_30 <<
V_42 ) | ( V_54 -> time . V_31 << V_44 ) ;
V_37 = ( V_54 -> time . V_32 << V_46 ) | ( V_54 -> time . V_33 <<
V_48 ) | ( V_54 -> time . V_34 << V_50 ) ;
F_4 ( time , V_2 -> V_6 + V_55 ) ;
F_4 ( V_37 , V_2 -> V_6 + V_56 ) ;
V_52 = F_8 ( V_2 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_54 -> V_57 )
F_6 ( V_2 ) ;
else
F_7 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 , unsigned int V_57 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
int V_11 = 0 ;
F_1 ( V_2 ) ;
switch ( V_57 ) {
case 0 :
F_7 ( V_2 ) ;
break;
case 1 :
F_6 ( V_2 ) ;
break;
default:
V_11 = - V_28 ;
break;
}
return V_11 ;
}
static int T_2 F_24 ( struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_1 * V_2 ;
unsigned int V_14 = 0 ;
int V_17 ;
V_61 = F_25 ( V_59 , V_62 , 0 ) ;
if ( ! V_61 ) {
F_26 ( & V_59 -> V_36 , L_1 ) ;
return - V_63 ;
}
if ( ! F_27 ( V_61 -> V_64 , F_28 ( V_61 ) , V_59 -> V_65 ) ) {
F_26 ( & V_59 -> V_36 , L_2 ) ;
return - V_63 ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 ) {
F_26 ( & V_59 -> V_36 , L_3 ) ;
V_14 = - V_67 ;
goto V_68;
}
V_2 -> V_69 = F_30 ( & V_59 -> V_36 , NULL ) ;
if ( F_31 ( V_2 -> V_69 ) ) {
V_14 = F_32 ( V_2 -> V_69 ) ;
goto V_70;
}
V_14 = F_33 ( V_2 -> V_69 ) ;
if ( V_14 < 0 )
goto V_71;
V_2 -> V_6 = F_34 ( V_61 -> V_64 , F_28 ( V_61 ) ) ;
if ( ! V_2 -> V_6 ) {
F_26 ( & V_59 -> V_36 , L_4 ) ;
V_14 = - V_67 ;
goto V_72;
}
F_35 ( & V_2 -> V_5 ) ;
F_36 ( V_59 , V_2 ) ;
V_2 -> V_23 = F_37 ( V_59 -> V_65 , & V_59 -> V_36 ,
& V_73 , V_74 ) ;
if ( F_31 ( V_2 -> V_23 ) ) {
F_26 ( & V_59 -> V_36 , L_5 ,
F_32 ( V_2 -> V_23 ) ) ;
V_14 = F_32 ( V_2 -> V_23 ) ;
goto V_75;
}
V_17 = F_38 ( V_59 , 0 ) ;
if ( V_17 < 0 ) {
F_26 ( & V_59 -> V_36 , L_6 ) ;
V_14 = V_17 ;
goto V_76;
}
V_14 = F_39 ( V_17 , F_11 , 0 , V_59 -> V_65 , V_2 ) ;
if ( V_14 ) {
F_26 ( & V_59 -> V_36 , L_7 , V_17 ) ;
goto V_76;
}
if ( ! F_40 ( & V_59 -> V_36 ) )
F_41 ( & V_59 -> V_36 , 1 ) ;
return 0 ;
V_76:
F_36 ( V_59 , NULL ) ;
F_42 ( V_2 -> V_23 ) ;
V_75:
F_43 ( V_2 -> V_6 ) ;
V_72:
F_44 ( V_2 -> V_69 ) ;
V_71:
F_45 ( V_2 -> V_69 ) ;
V_70:
F_46 ( V_2 ) ;
V_68:
F_47 ( V_61 -> V_64 , F_28 ( V_61 ) ) ;
return V_14 ;
}
static int T_3 F_48 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_49 ( V_59 ) ;
int V_17 ;
struct V_60 * V_61 ;
F_7 ( V_2 ) ;
F_41 ( & V_59 -> V_36 , 0 ) ;
V_17 = F_38 ( V_59 , 0 ) ;
if ( V_17 )
F_50 ( V_17 , V_59 ) ;
F_44 ( V_2 -> V_69 ) ;
F_45 ( V_2 -> V_69 ) ;
F_43 ( V_2 -> V_6 ) ;
V_61 = F_25 ( V_59 , V_62 , 0 ) ;
if ( V_61 )
F_47 ( V_61 -> V_64 , F_28 ( V_61 ) ) ;
F_36 ( V_59 , NULL ) ;
F_42 ( V_2 -> V_23 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_58 * V_59 , T_4 V_77 )
{
struct V_1 * V_2 = F_49 ( V_59 ) ;
int V_17 ;
V_17 = F_38 ( V_59 , 0 ) ;
if ( F_52 ( & V_59 -> V_36 ) ) {
if ( ! F_53 ( V_17 ) )
V_2 -> V_78 = 1 ;
} else {
F_7 ( V_2 ) ;
F_44 ( V_2 -> V_69 ) ;
}
return 0 ;
}
static int F_54 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_49 ( V_59 ) ;
int V_17 ;
V_17 = F_38 ( V_59 , 0 ) ;
if ( F_52 ( & V_59 -> V_36 ) ) {
if ( V_2 -> V_78 ) {
F_55 ( V_17 ) ;
V_2 -> V_78 = 0 ;
}
} else {
F_33 ( V_2 -> V_69 ) ;
F_6 ( V_2 ) ;
}
return 0 ;
}
static void F_56 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_49 ( V_59 ) ;
F_7 ( V_2 ) ;
F_44 ( V_2 -> V_69 ) ;
}
