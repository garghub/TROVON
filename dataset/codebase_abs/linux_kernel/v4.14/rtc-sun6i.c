static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_6 ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
if ( V_6 & V_9 )
return V_3 ;
V_6 = F_3 ( V_5 -> V_7 + V_10 ) ;
V_6 &= F_4 ( 4 , 0 ) ;
return V_3 / ( V_6 + 1 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
return F_3 ( V_5 -> V_7 + V_8 ) & V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_12 ;
T_1 V_6 ;
if ( V_11 > 1 )
return - V_13 ;
F_7 ( & V_5 -> V_14 , V_12 ) ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
V_6 &= ~ V_9 ;
V_6 |= V_15 ;
V_6 |= V_11 ? V_9 : 0 ;
F_8 ( V_6 , V_5 -> V_7 + V_8 ) ;
F_9 ( & V_5 -> V_14 , V_12 ) ;
return 0 ;
}
static void T_3 F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_4 * V_5 ;
struct V_20 V_21 = {
. V_22 = & V_23 ,
} ;
const char * V_24 = L_1 ;
const char * V_25 [ 2 ] ;
V_5 = F_11 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return;
V_19 = F_11 ( sizeof( * V_19 ) + ( sizeof( * V_19 -> V_27 ) * 2 ) ,
V_26 ) ;
if ( ! V_19 )
return;
F_12 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = F_13 ( V_17 , 0 , F_14 ( V_17 ) ) ;
if ( F_15 ( V_5 -> V_7 ) ) {
F_16 ( L_2 ) ;
goto V_28;
}
F_8 ( V_15 | V_9 ,
V_5 -> V_7 + V_8 ) ;
V_29 = V_5 ;
if ( ! F_17 ( V_17 , L_3 , NULL ) )
goto V_28;
V_5 -> V_30 = F_18 ( NULL ,
L_4 ,
NULL , 0 ,
667000 ,
300000000 ) ;
if ( F_15 ( V_5 -> V_30 ) ) {
F_16 ( L_5 ) ;
return;
}
V_25 [ 0 ] = F_19 ( V_5 -> V_30 ) ;
V_25 [ 1 ] = F_20 ( V_17 , 0 ) ;
V_5 -> V_2 . V_21 = & V_21 ;
V_21 . V_31 = V_25 ;
V_21 . V_32 = F_21 ( V_17 ) + 1 ;
F_22 ( V_17 , L_6 , 0 ,
& V_21 . V_33 ) ;
V_5 -> V_34 = F_23 ( NULL , & V_5 -> V_2 ) ;
if ( F_15 ( V_5 -> V_34 ) ) {
F_16 ( L_7 ) ;
return;
}
F_22 ( V_17 , L_6 , 1 ,
& V_24 ) ;
V_5 -> V_35 = F_24 ( NULL , V_24 , V_5 -> V_2 . V_21 -> V_33 ,
0 , V_5 -> V_7 + V_36 ,
V_37 , 0 ,
& V_5 -> V_14 ) ;
if ( F_15 ( V_5 -> V_35 ) ) {
F_16 ( L_8 ) ;
return;
}
V_19 -> V_38 = 2 ;
V_19 -> V_27 [ 0 ] = & V_5 -> V_2 ;
V_19 -> V_27 [ 1 ] = F_25 ( V_5 -> V_35 ) ;
F_26 ( V_17 , V_39 , V_19 ) ;
return;
V_28:
F_27 ( V_19 ) ;
}
static T_4 F_28 ( int V_40 , void * V_41 )
{
struct V_4 * V_42 = (struct V_4 * ) V_41 ;
T_4 V_43 = V_44 ;
T_1 V_6 ;
F_29 ( & V_42 -> V_14 ) ;
V_6 = F_3 ( V_42 -> V_7 + V_45 ) ;
if ( V_6 & V_46 ) {
V_6 |= V_46 ;
F_8 ( V_6 , V_42 -> V_7 + V_45 ) ;
F_30 ( V_42 -> V_5 , 1 , V_47 | V_48 ) ;
V_43 = V_49 ;
}
F_31 ( & V_42 -> V_14 ) ;
return V_43 ;
}
static void F_32 ( int V_50 , struct V_4 * V_42 )
{
T_1 V_51 = 0 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
unsigned long V_12 ;
if ( V_50 ) {
V_51 = V_54 ;
V_52 = V_55 ;
V_53 = V_56 ;
} else {
F_8 ( V_46 ,
V_42 -> V_7 + V_45 ) ;
}
F_7 ( & V_42 -> V_14 , V_12 ) ;
F_8 ( V_51 , V_42 -> V_7 + V_57 ) ;
F_8 ( V_52 , V_42 -> V_7 + V_58 ) ;
F_8 ( V_53 , V_42 -> V_7 + V_59 ) ;
F_9 ( & V_42 -> V_14 , V_12 ) ;
}
static int F_33 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_4 * V_42 = F_34 ( V_61 ) ;
T_1 V_64 , time ;
do {
V_64 = F_3 ( V_42 -> V_7 + V_65 ) ;
time = F_3 ( V_42 -> V_7 + V_66 ) ;
} while ( ( V_64 != F_3 ( V_42 -> V_7 + V_65 ) ) ||
( time != F_3 ( V_42 -> V_7 + V_66 ) ) );
V_63 -> V_67 = F_35 ( time ) ;
V_63 -> V_68 = F_36 ( time ) ;
V_63 -> V_69 = F_37 ( time ) ;
V_63 -> V_70 = F_38 ( V_64 ) ;
V_63 -> V_71 = F_39 ( V_64 ) ;
V_63 -> V_72 = F_40 ( V_64 ) ;
V_63 -> V_71 -= 1 ;
V_63 -> V_72 += V_73 ;
return F_41 ( V_63 ) ;
}
static int F_42 ( struct V_60 * V_61 , struct V_74 * V_75 )
{
struct V_4 * V_42 = F_34 ( V_61 ) ;
unsigned long V_12 ;
T_1 V_76 ;
T_1 V_77 ;
F_7 ( & V_42 -> V_14 , V_12 ) ;
V_77 = F_3 ( V_42 -> V_7 + V_58 ) ;
V_76 = F_3 ( V_42 -> V_7 + V_45 ) ;
F_9 ( & V_42 -> V_14 , V_12 ) ;
V_75 -> V_78 = ! ! ( V_77 & V_54 ) ;
V_75 -> V_79 = ! ! ( V_76 & V_54 ) ;
F_43 ( V_42 -> V_80 , & V_75 -> time ) ;
return 0 ;
}
static int F_44 ( struct V_60 * V_61 , struct V_74 * V_75 )
{
struct V_4 * V_42 = F_34 ( V_61 ) ;
struct V_62 * V_81 = & V_75 -> time ;
struct V_62 V_82 ;
unsigned long V_83 = 0 ;
unsigned long V_84 = 0 ;
unsigned long V_85 = 0 ;
int V_43 = 0 ;
V_43 = F_33 ( V_61 , & V_82 ) ;
if ( V_43 < 0 ) {
F_45 ( V_61 , L_9 ) ;
return - V_13 ;
}
F_46 ( V_81 , & V_84 ) ;
F_46 ( & V_82 , & V_83 ) ;
if ( V_84 <= V_83 ) {
F_45 ( V_61 , L_10 ) ;
return - V_13 ;
}
V_85 = V_84 - V_83 ;
if ( V_85 > V_86 ) {
F_45 ( V_61 , L_11 ) ;
return - V_13 ;
}
F_32 ( 0 , V_42 ) ;
F_8 ( 0 , V_42 -> V_7 + V_87 ) ;
F_47 ( 100 , 300 ) ;
F_8 ( V_85 , V_42 -> V_7 + V_87 ) ;
V_42 -> V_80 = V_84 ;
F_32 ( V_75 -> V_78 , V_42 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_42 , int V_88 ,
unsigned int V_89 , unsigned int V_90 )
{
const unsigned long V_91 = V_92 + F_49 ( V_90 ) ;
T_1 V_93 ;
do {
V_93 = F_3 ( V_42 -> V_7 + V_88 ) ;
V_93 &= V_89 ;
if ( ! V_93 )
return 0 ;
} while ( F_50 ( V_92 , V_91 ) );
return - V_94 ;
}
static int F_51 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_4 * V_42 = F_34 ( V_61 ) ;
T_1 V_64 = 0 ;
T_1 time = 0 ;
int V_95 ;
V_95 = V_63 -> V_72 + 1900 ;
if ( V_95 < V_96 || V_95 > V_97 ) {
F_45 ( V_61 , L_12 ,
V_96 , V_97 ) ;
return - V_13 ;
}
V_63 -> V_72 -= V_73 ;
V_63 -> V_71 += 1 ;
V_64 = F_52 ( V_63 -> V_70 ) |
F_53 ( V_63 -> V_71 ) |
F_54 ( V_63 -> V_72 ) ;
if ( F_55 ( V_95 ) )
V_64 |= F_56 ( 1 ) ;
time = F_57 ( V_63 -> V_67 ) |
F_58 ( V_63 -> V_68 ) |
F_59 ( V_63 -> V_69 ) ;
if ( F_48 ( V_42 , V_8 ,
V_98 , 50 ) ) {
F_45 ( V_61 , L_13 ) ;
return - V_99 ;
}
F_8 ( time , V_42 -> V_7 + V_66 ) ;
if ( F_48 ( V_42 , V_8 ,
V_100 , 50 ) ) {
F_45 ( V_61 , L_14 ) ;
return - V_94 ;
}
F_8 ( V_64 , V_42 -> V_7 + V_65 ) ;
if ( F_48 ( V_42 , V_8 ,
V_101 , 50 ) ) {
F_45 ( V_61 , L_14 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_60 ( struct V_60 * V_61 , unsigned int V_78 )
{
struct V_4 * V_42 = F_34 ( V_61 ) ;
if ( ! V_78 )
F_32 ( V_78 , V_42 ) ;
return 0 ;
}
static int F_61 ( struct V_102 * V_103 )
{
struct V_4 * V_42 = V_29 ;
int V_43 ;
if ( ! V_42 )
return - V_104 ;
F_62 ( V_103 , V_42 ) ;
V_42 -> V_61 = & V_103 -> V_61 ;
V_42 -> V_40 = F_63 ( V_103 , 0 ) ;
if ( V_42 -> V_40 < 0 ) {
F_45 ( & V_103 -> V_61 , L_15 ) ;
return V_42 -> V_40 ;
}
V_43 = F_64 ( & V_103 -> V_61 , V_42 -> V_40 , F_28 ,
0 , F_65 ( & V_103 -> V_61 ) , V_42 ) ;
if ( V_43 ) {
F_45 ( & V_103 -> V_61 , L_16 ) ;
return V_43 ;
}
F_8 ( 0 , V_42 -> V_7 + V_87 ) ;
F_8 ( 0 , V_42 -> V_7 + V_57 ) ;
F_8 ( 0 , V_42 -> V_7 + V_58 ) ;
F_8 ( 0 , V_42 -> V_7 + V_105 ) ;
F_8 ( 0 , V_42 -> V_7 + V_106 ) ;
F_8 ( V_46 ,
V_42 -> V_7 + V_45 ) ;
F_8 ( V_107 ,
V_42 -> V_7 + V_108 ) ;
F_8 ( 0 , V_42 -> V_7 + V_59 ) ;
F_66 ( V_42 -> V_34 ) ;
V_42 -> V_5 = F_67 ( & V_103 -> V_61 , L_17 ,
& V_109 , V_110 ) ;
if ( F_15 ( V_42 -> V_5 ) ) {
F_45 ( & V_103 -> V_61 , L_18 ) ;
return F_68 ( V_42 -> V_5 ) ;
}
F_69 ( & V_103 -> V_61 , L_19 ) ;
return 0 ;
}
