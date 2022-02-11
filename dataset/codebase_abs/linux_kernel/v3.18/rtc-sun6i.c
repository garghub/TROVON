static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_2 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
if ( V_5 & V_8 ) {
V_5 |= V_8 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_4 ( V_4 -> V_9 , 1 , V_10 | V_11 ) ;
return V_12 ;
}
return V_13 ;
}
static void F_5 ( int V_14 , struct V_3 * V_4 )
{
T_2 V_15 = 0 ;
T_2 V_16 = 0 ;
T_2 V_17 = 0 ;
if ( V_14 ) {
V_15 = V_18 ;
V_16 = V_19 ;
V_17 = V_20 ;
} else {
F_3 ( V_8 ,
V_4 -> V_6 + V_7 ) ;
}
F_3 ( V_15 , V_4 -> V_6 + V_21 ) ;
F_3 ( V_16 , V_4 -> V_6 + V_22 ) ;
F_3 ( V_17 , V_4 -> V_6 + V_23 ) ;
}
static int F_6 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_28 , time ;
do {
V_28 = F_2 ( V_4 -> V_6 + V_29 ) ;
time = F_2 ( V_4 -> V_6 + V_30 ) ;
} while ( ( V_28 != F_2 ( V_4 -> V_6 + V_29 ) ) ||
( time != F_2 ( V_4 -> V_6 + V_30 ) ) );
V_27 -> V_31 = F_8 ( time ) ;
V_27 -> V_32 = F_9 ( time ) ;
V_27 -> V_33 = F_10 ( time ) ;
V_27 -> V_34 = F_11 ( V_28 ) ;
V_27 -> V_35 = F_12 ( V_28 ) ;
V_27 -> V_36 = F_13 ( V_28 ) ;
V_27 -> V_35 -= 1 ;
V_27 -> V_36 += V_37 ;
return F_14 ( V_27 ) ;
}
static int F_15 ( struct V_24 * V_25 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_40 ;
T_2 V_41 ;
V_41 = F_2 ( V_4 -> V_6 + V_22 ) ;
V_40 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_39 -> V_42 = ! ! ( V_41 & V_18 ) ;
V_39 -> V_43 = ! ! ( V_40 & V_18 ) ;
F_16 ( V_4 -> V_44 , & V_39 -> time ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_25 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
struct V_26 * V_45 = & V_39 -> time ;
struct V_26 V_46 ;
unsigned long V_47 = 0 ;
unsigned long V_48 = 0 ;
unsigned long V_49 = 0 ;
int V_50 = 0 ;
V_50 = F_6 ( V_25 , & V_46 ) ;
if ( V_50 < 0 ) {
F_18 ( V_25 , L_1 ) ;
return - V_51 ;
}
F_19 ( V_45 , & V_48 ) ;
F_19 ( & V_46 , & V_47 ) ;
if ( V_48 <= V_47 ) {
F_18 ( V_25 , L_2 ) ;
return - V_51 ;
}
V_49 = V_48 - V_47 ;
if ( V_49 > V_52 ) {
F_18 ( V_25 , L_3 ) ;
return - V_51 ;
}
F_5 ( 0 , V_4 ) ;
F_3 ( 0 , V_4 -> V_6 + V_53 ) ;
F_20 ( 100 , 300 ) ;
F_3 ( V_49 , V_4 -> V_6 + V_53 ) ;
V_4 -> V_44 = V_48 ;
F_5 ( V_39 -> V_42 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 , int V_54 ,
unsigned int V_55 , unsigned int V_56 )
{
const unsigned long V_57 = V_58 + F_22 ( V_56 ) ;
T_2 V_59 ;
do {
V_59 = F_2 ( V_4 -> V_6 + V_54 ) ;
V_59 &= V_55 ;
if ( ! V_59 )
return 0 ;
} while ( F_23 ( V_58 , V_57 ) );
return - V_60 ;
}
static int F_24 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_28 = 0 ;
T_2 time = 0 ;
int V_61 ;
V_61 = V_27 -> V_36 + 1900 ;
if ( V_61 < V_62 || V_61 > V_63 ) {
F_18 ( V_25 , L_4 ,
V_62 , V_63 ) ;
return - V_51 ;
}
V_27 -> V_36 -= V_37 ;
V_27 -> V_35 += 1 ;
V_28 = F_25 ( V_27 -> V_34 ) |
F_26 ( V_27 -> V_35 ) |
F_27 ( V_27 -> V_36 ) ;
if ( F_28 ( V_61 ) )
V_28 |= F_29 ( 1 ) ;
time = F_30 ( V_27 -> V_31 ) |
F_31 ( V_27 -> V_32 ) |
F_32 ( V_27 -> V_33 ) ;
if ( F_21 ( V_4 , V_64 ,
V_65 , 50 ) ) {
F_18 ( V_25 , L_5 ) ;
return - V_66 ;
}
F_3 ( time , V_4 -> V_6 + V_30 ) ;
if ( F_21 ( V_4 , V_64 ,
V_67 , 50 ) ) {
F_18 ( V_25 , L_6 ) ;
return - V_60 ;
}
F_3 ( V_28 , V_4 -> V_6 + V_29 ) ;
if ( F_21 ( V_4 , V_64 ,
V_68 , 50 ) ) {
F_18 ( V_25 , L_6 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_33 ( struct V_24 * V_25 , unsigned int V_42 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
if ( ! V_42 )
F_5 ( V_42 , V_4 ) ;
return 0 ;
}
static int F_34 ( struct V_69 * V_70 )
{
struct V_3 * V_4 ;
struct V_71 * V_72 ;
int V_50 ;
V_4 = F_35 ( & V_70 -> V_25 , sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 )
return - V_74 ;
F_36 ( V_70 , V_4 ) ;
V_4 -> V_25 = & V_70 -> V_25 ;
V_72 = F_37 ( V_70 , V_75 , 0 ) ;
V_4 -> V_6 = F_38 ( & V_70 -> V_25 , V_72 ) ;
if ( F_39 ( V_4 -> V_6 ) )
return F_40 ( V_4 -> V_6 ) ;
V_4 -> V_1 = F_41 ( V_70 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_18 ( & V_70 -> V_25 , L_7 ) ;
return V_4 -> V_1 ;
}
V_50 = F_42 ( & V_70 -> V_25 , V_4 -> V_1 , F_1 ,
0 , F_43 ( & V_70 -> V_25 ) , V_4 ) ;
if ( V_50 ) {
F_18 ( & V_70 -> V_25 , L_8 ) ;
return V_50 ;
}
F_3 ( 0 , V_4 -> V_6 + V_53 ) ;
F_3 ( 0 , V_4 -> V_6 + V_21 ) ;
F_3 ( 0 , V_4 -> V_6 + V_22 ) ;
F_3 ( 0 , V_4 -> V_6 + V_76 ) ;
F_3 ( 0 , V_4 -> V_6 + V_77 ) ;
F_3 ( V_8 ,
V_4 -> V_6 + V_7 ) ;
F_3 ( V_78 ,
V_4 -> V_6 + V_79 ) ;
F_3 ( 0 , V_4 -> V_6 + V_23 ) ;
V_4 -> V_9 = F_44 ( L_9 , & V_70 -> V_25 ,
& V_80 , V_81 ) ;
if ( F_39 ( V_4 -> V_9 ) ) {
F_18 ( & V_70 -> V_25 , L_10 ) ;
return F_40 ( V_4 -> V_9 ) ;
}
F_45 ( & V_70 -> V_25 , L_11 ) ;
return 0 ;
}
static int F_46 ( struct V_69 * V_70 )
{
struct V_3 * V_4 = F_47 ( V_70 ) ;
F_48 ( V_4 -> V_9 ) ;
return 0 ;
}
