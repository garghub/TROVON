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
const char * V_24 [ 2 ] ;
V_5 = F_11 ( sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return;
F_12 ( & V_5 -> V_14 ) ;
V_19 = F_11 ( sizeof( * V_19 ) + sizeof( * V_19 -> V_26 ) ,
V_25 ) ;
if ( ! V_19 )
return;
F_12 ( & V_5 -> V_14 ) ;
V_5 -> V_7 = F_13 ( V_17 , 0 , F_14 ( V_17 ) ) ;
if ( F_15 ( V_5 -> V_7 ) ) {
F_16 ( L_1 ) ;
return;
}
F_8 ( V_15 | V_9 ,
V_5 -> V_7 + V_8 ) ;
V_27 = V_5 ;
if ( ! F_17 ( V_17 , L_2 , NULL ) )
return;
V_5 -> V_28 = F_18 ( NULL ,
L_3 ,
NULL , 0 ,
667000 ,
300000000 ) ;
if ( F_15 ( V_5 -> V_28 ) ) {
F_16 ( L_4 ) ;
return;
}
V_24 [ 0 ] = F_19 ( V_5 -> V_28 ) ;
V_24 [ 1 ] = F_20 ( V_17 , 0 ) ;
V_5 -> V_2 . V_21 = & V_21 ;
V_21 . V_29 = V_24 ;
V_21 . V_30 = F_21 ( V_17 ) + 1 ;
F_22 ( V_17 , L_5 , & V_21 . V_31 ) ;
V_5 -> V_32 = F_23 ( NULL , & V_5 -> V_2 ) ;
if ( F_15 ( V_5 -> V_32 ) ) {
F_16 ( L_6 ) ;
return;
}
V_19 -> V_33 = 1 ;
V_19 -> V_26 [ 0 ] = & V_5 -> V_2 ;
F_24 ( V_17 , V_34 , V_19 ) ;
}
static T_4 F_25 ( int V_35 , void * V_36 )
{
struct V_4 * V_37 = (struct V_4 * ) V_36 ;
T_4 V_38 = V_39 ;
T_1 V_6 ;
F_26 ( & V_37 -> V_14 ) ;
V_6 = F_3 ( V_37 -> V_7 + V_40 ) ;
if ( V_6 & V_41 ) {
V_6 |= V_41 ;
F_8 ( V_6 , V_37 -> V_7 + V_40 ) ;
F_27 ( V_37 -> V_5 , 1 , V_42 | V_43 ) ;
V_38 = V_44 ;
}
F_28 ( & V_37 -> V_14 ) ;
return V_38 ;
}
static void F_29 ( int V_45 , struct V_4 * V_37 )
{
T_1 V_46 = 0 ;
T_1 V_47 = 0 ;
T_1 V_48 = 0 ;
unsigned long V_12 ;
if ( V_45 ) {
V_46 = V_49 ;
V_47 = V_50 ;
V_48 = V_51 ;
} else {
F_8 ( V_41 ,
V_37 -> V_7 + V_40 ) ;
}
F_7 ( & V_37 -> V_14 , V_12 ) ;
F_8 ( V_46 , V_37 -> V_7 + V_52 ) ;
F_8 ( V_47 , V_37 -> V_7 + V_53 ) ;
F_8 ( V_48 , V_37 -> V_7 + V_54 ) ;
F_9 ( & V_37 -> V_14 , V_12 ) ;
}
static int F_30 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_4 * V_37 = F_31 ( V_56 ) ;
T_1 V_59 , time ;
do {
V_59 = F_3 ( V_37 -> V_7 + V_60 ) ;
time = F_3 ( V_37 -> V_7 + V_61 ) ;
} while ( ( V_59 != F_3 ( V_37 -> V_7 + V_60 ) ) ||
( time != F_3 ( V_37 -> V_7 + V_61 ) ) );
V_58 -> V_62 = F_32 ( time ) ;
V_58 -> V_63 = F_33 ( time ) ;
V_58 -> V_64 = F_34 ( time ) ;
V_58 -> V_65 = F_35 ( V_59 ) ;
V_58 -> V_66 = F_36 ( V_59 ) ;
V_58 -> V_67 = F_37 ( V_59 ) ;
V_58 -> V_66 -= 1 ;
V_58 -> V_67 += V_68 ;
return F_38 ( V_58 ) ;
}
static int F_39 ( struct V_55 * V_56 , struct V_69 * V_70 )
{
struct V_4 * V_37 = F_31 ( V_56 ) ;
unsigned long V_12 ;
T_1 V_71 ;
T_1 V_72 ;
F_7 ( & V_37 -> V_14 , V_12 ) ;
V_72 = F_3 ( V_37 -> V_7 + V_53 ) ;
V_71 = F_3 ( V_37 -> V_7 + V_40 ) ;
F_9 ( & V_37 -> V_14 , V_12 ) ;
V_70 -> V_73 = ! ! ( V_72 & V_49 ) ;
V_70 -> V_74 = ! ! ( V_71 & V_49 ) ;
F_40 ( V_37 -> V_75 , & V_70 -> time ) ;
return 0 ;
}
static int F_41 ( struct V_55 * V_56 , struct V_69 * V_70 )
{
struct V_4 * V_37 = F_31 ( V_56 ) ;
struct V_57 * V_76 = & V_70 -> time ;
struct V_57 V_77 ;
unsigned long V_78 = 0 ;
unsigned long V_79 = 0 ;
unsigned long V_80 = 0 ;
int V_38 = 0 ;
V_38 = F_30 ( V_56 , & V_77 ) ;
if ( V_38 < 0 ) {
F_42 ( V_56 , L_7 ) ;
return - V_13 ;
}
F_43 ( V_76 , & V_79 ) ;
F_43 ( & V_77 , & V_78 ) ;
if ( V_79 <= V_78 ) {
F_42 ( V_56 , L_8 ) ;
return - V_13 ;
}
V_80 = V_79 - V_78 ;
if ( V_80 > V_81 ) {
F_42 ( V_56 , L_9 ) ;
return - V_13 ;
}
F_29 ( 0 , V_37 ) ;
F_8 ( 0 , V_37 -> V_7 + V_82 ) ;
F_44 ( 100 , 300 ) ;
F_8 ( V_80 , V_37 -> V_7 + V_82 ) ;
V_37 -> V_75 = V_79 ;
F_29 ( V_70 -> V_73 , V_37 ) ;
return 0 ;
}
static int F_45 ( struct V_4 * V_37 , int V_83 ,
unsigned int V_84 , unsigned int V_85 )
{
const unsigned long V_86 = V_87 + F_46 ( V_85 ) ;
T_1 V_88 ;
do {
V_88 = F_3 ( V_37 -> V_7 + V_83 ) ;
V_88 &= V_84 ;
if ( ! V_88 )
return 0 ;
} while ( F_47 ( V_87 , V_86 ) );
return - V_89 ;
}
static int F_48 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_4 * V_37 = F_31 ( V_56 ) ;
T_1 V_59 = 0 ;
T_1 time = 0 ;
int V_90 ;
V_90 = V_58 -> V_67 + 1900 ;
if ( V_90 < V_91 || V_90 > V_92 ) {
F_42 ( V_56 , L_10 ,
V_91 , V_92 ) ;
return - V_13 ;
}
V_58 -> V_67 -= V_68 ;
V_58 -> V_66 += 1 ;
V_59 = F_49 ( V_58 -> V_65 ) |
F_50 ( V_58 -> V_66 ) |
F_51 ( V_58 -> V_67 ) ;
if ( F_52 ( V_90 ) )
V_59 |= F_53 ( 1 ) ;
time = F_54 ( V_58 -> V_62 ) |
F_55 ( V_58 -> V_63 ) |
F_56 ( V_58 -> V_64 ) ;
if ( F_45 ( V_37 , V_8 ,
V_93 , 50 ) ) {
F_42 ( V_56 , L_11 ) ;
return - V_94 ;
}
F_8 ( time , V_37 -> V_7 + V_61 ) ;
if ( F_45 ( V_37 , V_8 ,
V_95 , 50 ) ) {
F_42 ( V_56 , L_12 ) ;
return - V_89 ;
}
F_8 ( V_59 , V_37 -> V_7 + V_60 ) ;
if ( F_45 ( V_37 , V_8 ,
V_96 , 50 ) ) {
F_42 ( V_56 , L_12 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_57 ( struct V_55 * V_56 , unsigned int V_73 )
{
struct V_4 * V_37 = F_31 ( V_56 ) ;
if ( ! V_73 )
F_29 ( V_73 , V_37 ) ;
return 0 ;
}
static int F_58 ( struct V_97 * V_98 )
{
struct V_4 * V_37 = V_27 ;
int V_38 ;
if ( ! V_37 )
return - V_99 ;
F_59 ( V_98 , V_37 ) ;
V_37 -> V_56 = & V_98 -> V_56 ;
V_37 -> V_35 = F_60 ( V_98 , 0 ) ;
if ( V_37 -> V_35 < 0 ) {
F_42 ( & V_98 -> V_56 , L_13 ) ;
return V_37 -> V_35 ;
}
V_38 = F_61 ( & V_98 -> V_56 , V_37 -> V_35 , F_25 ,
0 , F_62 ( & V_98 -> V_56 ) , V_37 ) ;
if ( V_38 ) {
F_42 ( & V_98 -> V_56 , L_14 ) ;
return V_38 ;
}
F_8 ( 0 , V_37 -> V_7 + V_82 ) ;
F_8 ( 0 , V_37 -> V_7 + V_52 ) ;
F_8 ( 0 , V_37 -> V_7 + V_53 ) ;
F_8 ( 0 , V_37 -> V_7 + V_100 ) ;
F_8 ( 0 , V_37 -> V_7 + V_101 ) ;
F_8 ( V_41 ,
V_37 -> V_7 + V_40 ) ;
F_8 ( V_102 ,
V_37 -> V_7 + V_103 ) ;
F_8 ( 0 , V_37 -> V_7 + V_54 ) ;
F_63 ( V_37 -> V_32 ) ;
V_37 -> V_5 = F_64 ( & V_98 -> V_56 , L_15 ,
& V_104 , V_105 ) ;
if ( F_15 ( V_37 -> V_5 ) ) {
F_42 ( & V_98 -> V_56 , L_16 ) ;
return F_65 ( V_37 -> V_5 ) ;
}
F_66 ( & V_98 -> V_56 , L_17 ) ;
return 0 ;
}
