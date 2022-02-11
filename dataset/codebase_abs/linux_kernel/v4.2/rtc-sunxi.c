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
if ( V_14 ) {
V_15 = F_2 ( V_4 -> V_6 + V_17 ) ;
V_15 |= V_18 ;
V_16 = F_2 ( V_4 -> V_6 + V_19 ) ;
V_16 |= V_20 ;
} else {
F_3 ( V_8 ,
V_4 -> V_6 + V_7 ) ;
}
F_3 ( V_15 , V_4 -> V_6 + V_17 ) ;
F_3 ( V_16 , V_4 -> V_6 + V_19 ) ;
}
static int F_6 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_3 * V_4 = F_7 ( V_22 ) ;
struct V_25 * V_26 = & V_24 -> time ;
T_2 V_27 ;
T_2 V_28 ;
T_2 V_29 ;
V_27 = F_2 ( V_4 -> V_6 + V_30 ) ;
V_29 = F_2 ( V_4 -> V_6 + V_31 ) ;
V_26 -> V_32 = F_8 ( V_27 ) ;
V_26 -> V_33 = F_9 ( V_27 ) ;
V_26 -> V_34 = F_10 ( V_27 ) ;
V_26 -> V_35 = F_11 ( V_29 ) ;
V_26 -> V_36 = F_12 ( V_29 ) ;
V_26 -> V_37 = F_13 ( V_29 ,
V_4 -> V_38 -> V_39 ) ;
V_26 -> V_36 -= 1 ;
V_26 -> V_37 += F_14 ( V_4 -> V_38 ) ;
V_28 = F_2 ( V_4 -> V_6 + V_19 ) ;
if ( V_28 & V_18 )
V_24 -> V_40 = 1 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_25 * V_41 )
{
struct V_3 * V_4 = F_7 ( V_22 ) ;
T_2 V_29 , time ;
do {
V_29 = F_2 ( V_4 -> V_6 + V_31 ) ;
time = F_2 ( V_4 -> V_6 + V_42 ) ;
} while ( ( V_29 != F_2 ( V_4 -> V_6 + V_31 ) ) ||
( time != F_2 ( V_4 -> V_6 + V_42 ) ) );
V_41 -> V_32 = F_16 ( time ) ;
V_41 -> V_33 = F_17 ( time ) ;
V_41 -> V_34 = F_18 ( time ) ;
V_41 -> V_35 = F_11 ( V_29 ) ;
V_41 -> V_36 = F_12 ( V_29 ) ;
V_41 -> V_37 = F_13 ( V_29 ,
V_4 -> V_38 -> V_39 ) ;
V_41 -> V_36 -= 1 ;
V_41 -> V_37 += F_14 ( V_4 -> V_38 ) ;
return F_19 ( V_41 ) ;
}
static int F_20 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_3 * V_4 = F_7 ( V_22 ) ;
struct V_25 * V_26 = & V_24 -> time ;
struct V_25 V_43 ;
T_2 V_27 ;
T_3 V_44 ;
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long V_48 ;
int V_49 ;
V_49 = F_15 ( V_22 , & V_43 ) ;
if ( V_49 < 0 ) {
F_21 ( V_22 , L_1 ) ;
return - V_50 ;
}
V_44 = F_22 ( V_26 , & V_43 ) ;
if ( V_44 <= 0 ) {
F_21 ( V_22 , L_2 ) ;
return - V_50 ;
}
if ( V_44 > 255 * V_51 ) {
F_21 ( V_22 , L_3 ) ;
return - V_50 ;
}
V_45 = V_44 ;
V_46 = V_45 / V_51 ;
V_45 -= V_46 * V_51 ;
V_47 = V_45 / V_52 ;
V_45 -= V_47 * V_52 ;
V_48 = V_45 / V_53 ;
V_45 -= V_48 * V_53 ;
F_5 ( 0 , V_4 ) ;
F_3 ( 0 , V_4 -> V_6 + V_30 ) ;
F_23 ( 100 , 300 ) ;
V_27 = F_24 ( V_45 ) |
F_25 ( V_48 ) |
F_26 ( V_47 ) |
F_27 ( V_46 ) ;
F_3 ( V_27 , V_4 -> V_6 + V_30 ) ;
F_3 ( 0 , V_4 -> V_6 + V_19 ) ;
F_3 ( V_20 , V_4 -> V_6 + V_19 ) ;
F_5 ( V_24 -> V_40 , V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , int V_54 ,
unsigned int V_39 , unsigned int V_55 )
{
const unsigned long V_56 = V_57 + F_29 ( V_55 ) ;
T_2 V_58 ;
do {
V_58 = F_2 ( V_4 -> V_6 + V_54 ) ;
V_58 &= V_39 ;
if ( V_58 == V_39 )
return 0 ;
} while ( F_30 ( V_57 , V_56 ) );
return - V_59 ;
}
static int F_31 ( struct V_21 * V_22 , struct V_25 * V_41 )
{
struct V_3 * V_4 = F_7 ( V_22 ) ;
T_2 V_29 = 0 ;
T_2 time = 0 ;
int V_60 ;
V_60 = V_41 -> V_37 + 1900 ;
if ( V_60 < V_4 -> V_38 -> V_61 || V_60 > V_4 -> V_38 -> V_62 ) {
F_21 ( V_22 , L_4 ,
V_4 -> V_38 -> V_61 , V_4 -> V_38 -> V_62 ) ;
return - V_50 ;
}
V_41 -> V_37 -= F_14 ( V_4 -> V_38 ) ;
V_41 -> V_36 += 1 ;
V_29 = F_32 ( V_41 -> V_35 ) |
F_33 ( V_41 -> V_36 ) |
F_34 ( V_41 -> V_37 ,
V_4 -> V_38 -> V_39 ) ;
if ( F_35 ( V_60 ) )
V_29 |= F_36 ( 1 , V_4 -> V_38 -> V_63 ) ;
time = F_37 ( V_41 -> V_32 ) |
F_38 ( V_41 -> V_33 ) |
F_39 ( V_41 -> V_34 ) ;
F_3 ( 0 , V_4 -> V_6 + V_42 ) ;
F_3 ( 0 , V_4 -> V_6 + V_31 ) ;
F_3 ( time , V_4 -> V_6 + V_42 ) ;
if ( F_28 ( V_4 , V_64 ,
V_65 , 50 ) ) {
F_21 ( V_22 , L_5 ) ;
return - 1 ;
}
F_3 ( V_29 , V_4 -> V_6 + V_31 ) ;
if ( F_28 ( V_4 , V_64 ,
V_66 , 50 ) ) {
F_21 ( V_22 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_40 ( struct V_21 * V_22 , unsigned int V_40 )
{
struct V_3 * V_4 = F_7 ( V_22 ) ;
if ( ! V_40 )
F_5 ( V_40 , V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_67 * V_68 )
{
struct V_3 * V_4 ;
struct V_69 * V_70 ;
const struct V_71 * V_72 ;
int V_49 ;
V_4 = F_42 ( & V_68 -> V_22 , sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 )
return - V_74 ;
F_43 ( V_68 , V_4 ) ;
V_4 -> V_22 = & V_68 -> V_22 ;
V_70 = F_44 ( V_68 , V_75 , 0 ) ;
V_4 -> V_6 = F_45 ( & V_68 -> V_22 , V_70 ) ;
if ( F_46 ( V_4 -> V_6 ) )
return F_47 ( V_4 -> V_6 ) ;
V_4 -> V_1 = F_48 ( V_68 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_21 ( & V_68 -> V_22 , L_6 ) ;
return V_4 -> V_1 ;
}
V_49 = F_49 ( & V_68 -> V_22 , V_4 -> V_1 , F_1 ,
0 , F_50 ( & V_68 -> V_22 ) , V_4 ) ;
if ( V_49 ) {
F_21 ( & V_68 -> V_22 , L_7 ) ;
return V_49 ;
}
V_72 = F_51 ( V_76 , & V_68 -> V_22 ) ;
if ( ! V_72 ) {
F_21 ( & V_68 -> V_22 , L_8 ) ;
return - V_77 ;
}
V_4 -> V_38 = (struct V_78 * ) V_72 -> V_79 ;
F_3 ( 0 , V_4 -> V_6 + V_30 ) ;
F_3 ( 0 , V_4 -> V_6 + V_17 ) ;
F_3 ( 0 , V_4 -> V_6 + V_19 ) ;
F_3 ( V_8 , V_4 -> V_6 +
V_7 ) ;
V_4 -> V_9 = F_52 ( L_9 , & V_68 -> V_22 ,
& V_80 , V_81 ) ;
if ( F_46 ( V_4 -> V_9 ) ) {
F_21 ( & V_68 -> V_22 , L_10 ) ;
return F_47 ( V_4 -> V_9 ) ;
}
F_53 ( & V_68 -> V_22 , L_11 ) ;
return 0 ;
}
static int F_54 ( struct V_67 * V_68 )
{
struct V_3 * V_4 = F_55 ( V_68 ) ;
F_56 ( V_4 -> V_9 ) ;
return 0 ;
}
