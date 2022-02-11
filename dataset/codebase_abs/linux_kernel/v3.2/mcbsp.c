static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
void T_3 * V_5 = V_2 -> V_6 + V_3 * V_2 -> V_7 -> V_8 ;
if ( V_2 -> V_7 -> V_9 == 2 ) {
( ( T_1 * ) V_2 -> V_10 ) [ V_3 ] = ( T_1 ) V_4 ;
F_2 ( ( T_1 ) V_4 , V_5 ) ;
} else {
( ( T_2 * ) V_2 -> V_10 ) [ V_3 ] = V_4 ;
F_3 ( V_4 , V_5 ) ;
}
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , bool V_11 )
{
void T_3 * V_5 = V_2 -> V_6 + V_3 * V_2 -> V_7 -> V_8 ;
if ( V_2 -> V_7 -> V_9 == 2 ) {
return ! V_11 ? F_5 ( V_5 ) :
( ( T_1 * ) V_2 -> V_10 ) [ V_3 ] ;
} else {
return ! V_11 ? F_6 ( V_5 ) :
( ( T_2 * ) V_2 -> V_10 ) [ V_3 ] ;
}
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_3 ( V_4 , V_2 -> V_12 -> V_13 + V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 -> V_12 -> V_13 + V_3 ) ;
}
static void F_9 ( T_4 V_14 )
{
struct V_1 * V_2 = F_10 ( V_14 ) ;
F_11 ( V_2 -> V_15 , L_1 , V_2 -> V_14 ) ;
F_11 ( V_2 -> V_15 , L_2 ,
F_12 ( V_2 , V_16 ) ) ;
F_11 ( V_2 -> V_15 , L_3 ,
F_12 ( V_2 , V_17 ) ) ;
F_11 ( V_2 -> V_15 , L_4 ,
F_12 ( V_2 , V_18 ) ) ;
F_11 ( V_2 -> V_15 , L_5 ,
F_12 ( V_2 , V_19 ) ) ;
F_11 ( V_2 -> V_15 , L_6 ,
F_12 ( V_2 , V_20 ) ) ;
F_11 ( V_2 -> V_15 , L_7 ,
F_12 ( V_2 , V_21 ) ) ;
F_11 ( V_2 -> V_15 , L_8 ,
F_12 ( V_2 , V_22 ) ) ;
F_11 ( V_2 -> V_15 , L_9 ,
F_12 ( V_2 , V_23 ) ) ;
F_11 ( V_2 -> V_15 , L_10 ,
F_12 ( V_2 , V_24 ) ) ;
F_11 ( V_2 -> V_15 , L_11 ,
F_12 ( V_2 , V_25 ) ) ;
F_11 ( V_2 -> V_15 , L_12 ,
F_12 ( V_2 , V_26 ) ) ;
F_11 ( V_2 -> V_15 , L_13 ,
F_12 ( V_2 , V_27 ) ) ;
F_11 ( V_2 -> V_15 , L_14 ,
F_12 ( V_2 , V_28 ) ) ;
F_11 ( V_2 -> V_15 , L_15 ) ;
}
static T_5 F_13 ( int V_29 , void * V_30 )
{
struct V_1 * V_31 = V_30 ;
T_1 V_32 ;
V_32 = F_12 ( V_31 , V_20 ) ;
F_11 ( V_31 -> V_15 , L_16 , V_32 ) ;
if ( V_32 & V_33 ) {
F_14 ( V_31 -> V_15 , L_17 ,
V_32 ) ;
F_15 ( V_31 , V_20 , F_16 ( V_31 , V_20 ) ) ;
}
return V_34 ;
}
static T_5 F_17 ( int V_29 , void * V_30 )
{
struct V_1 * V_35 = V_30 ;
T_1 V_36 ;
V_36 = F_12 ( V_35 , V_21 ) ;
F_11 ( V_35 -> V_15 , L_18 , V_36 ) ;
if ( V_36 & V_37 ) {
F_14 ( V_35 -> V_15 , L_19 ,
V_36 ) ;
F_15 ( V_35 , V_21 , F_16 ( V_35 , V_21 ) ) ;
}
return V_34 ;
}
void F_18 ( unsigned int V_14 , const struct V_38 * V_39 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
F_11 ( V_2 -> V_15 , L_21 ,
V_2 -> V_14 , V_2 -> V_42 ) ;
F_15 ( V_2 , V_20 , V_39 -> V_43 ) ;
F_15 ( V_2 , V_21 , V_39 -> V_44 ) ;
F_15 ( V_2 , V_22 , V_39 -> V_45 ) ;
F_15 ( V_2 , V_23 , V_39 -> V_46 ) ;
F_15 ( V_2 , V_24 , V_39 -> V_47 ) ;
F_15 ( V_2 , V_25 , V_39 -> V_48 ) ;
F_15 ( V_2 , V_26 , V_39 -> V_49 ) ;
F_15 ( V_2 , V_27 , V_39 -> V_50 ) ;
F_15 ( V_2 , V_51 , V_39 -> V_52 ) ;
F_15 ( V_2 , V_53 , V_39 -> V_54 ) ;
F_15 ( V_2 , V_28 , V_39 -> V_55 ) ;
if ( V_2 -> V_7 -> V_56 ) {
F_15 ( V_2 , V_57 , V_39 -> V_58 ) ;
F_15 ( V_2 , V_59 , V_39 -> V_60 ) ;
}
}
int F_21 ( unsigned int V_14 , unsigned int V_61 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
if ( V_61 )
return V_2 -> V_63 ;
else
return V_2 -> V_64 ;
}
int F_22 ( unsigned int V_14 , unsigned int V_61 )
{
struct V_1 * V_2 ;
int V_65 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 -> V_9 == 2 ) {
if ( V_61 )
V_65 = V_66 ;
else
V_65 = V_67 ;
} else {
if ( V_61 )
V_65 = V_68 ;
else
V_65 = V_69 ;
}
return V_2 -> V_70 + V_65 * V_2 -> V_7 -> V_8 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
if ( V_2 -> V_7 -> V_72 )
V_2 -> V_7 -> V_72 ( V_2 -> V_14 , 1 ) ;
V_71 = F_12 ( V_2 , V_73 ) ;
F_15 ( V_2 , V_73 , V_71 | V_74 ) ;
V_71 = F_24 ( V_2 , V_73 ) ;
F_25 ( V_2 , V_73 , V_71 | V_75 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_71 ;
V_71 = F_24 ( V_2 , V_73 ) ;
F_25 ( V_2 , V_73 , V_71 & ~ ( V_75 ) ) ;
V_71 = F_12 ( V_2 , V_73 ) ;
F_15 ( V_2 , V_73 , V_71 & ~ ( V_74 ) ) ;
if ( V_2 -> V_7 -> V_72 )
V_2 -> V_7 -> V_72 ( V_2 -> V_14 , 0 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_6 * V_76 )
{
T_1 V_4 , V_77 ;
V_4 = F_24 ( V_2 , V_73 ) ;
if ( V_4 & V_78 )
F_25 ( V_2 , V_73 , V_4 & ~ ( V_78 ) ) ;
F_25 ( V_2 , V_73 , V_4 | V_78 ) ;
for ( V_77 = 0 ; V_77 < 128 ; V_77 ++ )
F_25 ( V_2 , V_79 , V_76 [ V_77 ] ) ;
V_77 = 0 ;
V_4 = F_24 ( V_2 , V_73 ) ;
while ( ! ( V_4 & V_80 ) && ( ++ V_77 < 1000 ) )
V_4 = F_24 ( V_2 , V_73 ) ;
F_25 ( V_2 , V_73 , V_4 & ~ ( V_78 ) ) ;
if ( V_77 == 1000 )
F_14 ( V_2 -> V_15 , L_22 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_71 ;
struct V_81 * V_12 = V_2 -> V_12 ;
V_71 = F_24 ( V_2 , V_73 ) ;
F_25 ( V_2 , V_82 , F_29 ( V_12 -> V_83 ) | \
F_30 ( V_12 -> V_84 ) ) ;
}
int F_31 ( unsigned int V_14 , int V_85 , T_6 V_86 )
{
struct V_1 * V_2 ;
struct V_81 * V_12 ;
int V_87 = 0 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return - V_88 ;
F_32 ( & V_2 -> V_89 ) ;
if ( V_85 == 0 )
V_12 -> V_83 = V_86 ;
else if ( V_85 == 1 )
V_12 -> V_84 = V_86 ;
else
V_87 = - V_90 ;
if ( V_12 -> V_91 )
F_28 ( V_2 ) ;
F_33 ( & V_2 -> V_89 ) ;
return V_87 ;
}
int F_34 ( unsigned int V_14 , int V_85 , T_6 * V_86 )
{
struct V_1 * V_2 ;
struct V_81 * V_12 ;
int V_87 = 0 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return - V_88 ;
F_32 ( & V_2 -> V_89 ) ;
if ( V_85 == 0 )
* V_86 = V_12 -> V_83 ;
else if ( V_85 == 1 )
* V_86 = V_12 -> V_84 ;
else
V_87 = - V_90 ;
F_33 ( & V_2 -> V_89 ) ;
return V_87 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_81 * V_12 = V_2 -> V_12 ;
if ( V_12 && V_12 -> V_91 && ! V_12 -> V_92 ) {
F_27 ( V_2 , V_12 -> V_93 ) ;
F_28 ( V_2 ) ;
if ( ! V_2 -> free ) {
F_23 ( V_2 ) ;
V_12 -> V_92 = 1 ;
}
}
return 0 ;
}
int F_36 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
struct V_81 * V_12 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return - V_62 ;
F_32 ( & V_2 -> V_89 ) ;
V_12 -> V_91 = 1 ;
F_35 ( V_2 ) ;
F_33 ( & V_2 -> V_89 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_81 * V_12 = V_2 -> V_12 ;
if ( V_12 && V_12 -> V_92 ) {
if ( ! V_2 -> free ) {
F_26 ( V_2 ) ;
V_12 -> V_92 = 0 ;
}
}
return 0 ;
}
int F_38 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
struct V_81 * V_12 ;
int V_87 = 0 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return - V_62 ;
F_32 ( & V_2 -> V_89 ) ;
F_37 ( V_2 ) ;
V_12 -> V_91 = 0 ;
F_33 ( & V_2 -> V_89 ) ;
return V_87 ;
}
int F_39 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
struct V_81 * V_12 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_12 = V_2 -> V_12 ;
if ( ! V_12 )
return - V_62 ;
return V_12 -> V_91 ;
}
void F_40 ( unsigned int V_14 , T_1 V_94 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 -> V_95 == 0 )
return;
if ( V_94 && V_94 <= V_2 -> V_96 )
F_15 ( V_2 , V_97 , V_94 - 1 ) ;
}
void F_41 ( unsigned int V_14 , T_1 V_94 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 -> V_95 == 0 )
return;
if ( V_94 && V_94 <= V_2 -> V_98 )
F_15 ( V_2 , V_99 , V_94 - 1 ) ;
}
T_1 F_42 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
return V_2 -> V_96 ;
}
T_1 F_43 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
return V_2 -> V_98 ;
}
T_1 F_44 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
return V_2 -> V_7 -> V_95 ;
}
T_1 F_45 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
T_1 V_100 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 -> V_95 == 0 )
return 0 ;
V_100 = F_12 ( V_2 , V_101 ) ;
return V_2 -> V_7 -> V_95 - V_100 ;
}
T_1 F_46 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
T_1 V_100 , V_94 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 -> V_95 == 0 )
return 0 ;
V_100 = F_12 ( V_2 , V_102 ) ;
V_94 = F_12 ( V_2 , V_99 ) ;
if ( V_94 <= V_100 )
return 0 ;
else
return V_94 - V_100 ;
}
int F_47 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
int V_103 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_23 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_103 = V_2 -> V_103 ;
return V_103 ;
}
int F_48 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
void * V_10 ;
int V_104 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return - V_62 ;
}
V_2 = F_10 ( V_14 ) ;
V_10 = F_49 ( V_2 -> V_105 , V_106 ) ;
if ( ! V_10 ) {
return - V_107 ;
}
F_50 ( & V_2 -> V_89 ) ;
if ( ! V_2 -> free ) {
F_14 ( V_2 -> V_15 , L_24 ,
V_2 -> V_14 ) ;
V_104 = - V_108 ;
goto V_109;
}
V_2 -> free = false ;
V_2 -> V_10 = V_10 ;
F_51 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_110 && V_2 -> V_7 -> V_110 -> V_111 )
V_2 -> V_7 -> V_110 -> V_111 ( V_14 ) ;
F_52 ( V_2 -> V_15 ) ;
if ( V_2 -> V_7 -> V_112 )
F_15 ( V_2 , V_113 , V_114 | V_115 ) ;
F_15 ( V_2 , V_21 , 0 ) ;
F_15 ( V_2 , V_20 , 0 ) ;
V_104 = F_53 ( V_2 -> V_116 , F_13 ,
0 , L_25 , ( void * ) V_2 ) ;
if ( V_104 != 0 ) {
F_14 ( V_2 -> V_15 , L_26
L_27 , V_2 -> V_116 ,
V_2 -> V_14 ) ;
goto V_117;
}
if ( V_2 -> V_118 ) {
V_104 = F_53 ( V_2 -> V_118 ,
F_17 ,
0 , L_25 , ( void * ) V_2 ) ;
if ( V_104 != 0 ) {
F_14 ( V_2 -> V_15 , L_28
L_27 , V_2 -> V_118 ,
V_2 -> V_14 ) ;
goto V_119;
}
}
return 0 ;
V_119:
F_54 ( V_2 -> V_116 , ( void * ) V_2 ) ;
V_117:
if ( V_2 -> V_7 && V_2 -> V_7 -> V_110 && V_2 -> V_7 -> V_110 -> free )
V_2 -> V_7 -> V_110 -> free ( V_14 ) ;
if ( V_2 -> V_7 -> V_112 )
F_15 ( V_2 , V_113 , 0 ) ;
F_55 ( V_2 -> V_15 ) ;
F_50 ( & V_2 -> V_89 ) ;
V_2 -> free = true ;
V_2 -> V_10 = NULL ;
V_109:
F_51 ( & V_2 -> V_89 ) ;
F_56 ( V_10 ) ;
return V_104 ;
}
void F_57 ( unsigned int V_14 )
{
struct V_1 * V_2 ;
void * V_10 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_110 && V_2 -> V_7 -> V_110 -> free )
V_2 -> V_7 -> V_110 -> free ( V_14 ) ;
if ( V_2 -> V_7 -> V_112 )
F_15 ( V_2 , V_113 , 0 ) ;
F_55 ( V_2 -> V_15 ) ;
if ( V_2 -> V_118 )
F_54 ( V_2 -> V_118 , ( void * ) V_2 ) ;
F_54 ( V_2 -> V_116 , ( void * ) V_2 ) ;
V_10 = V_2 -> V_10 ;
F_50 ( & V_2 -> V_89 ) ;
if ( V_2 -> free )
F_14 ( V_2 -> V_15 , L_29 , V_2 -> V_14 ) ;
else
V_2 -> free = true ;
V_2 -> V_10 = NULL ;
F_51 ( & V_2 -> V_89 ) ;
if ( V_10 )
F_56 ( V_10 ) ;
}
void F_58 ( unsigned int V_14 , int V_120 , int V_121 )
{
struct V_1 * V_2 ;
int V_122 = 0 ;
T_1 V_71 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
if ( V_2 -> V_12 )
F_35 ( V_2 ) ;
V_71 = F_16 ( V_2 , V_28 ) ;
if ( V_71 & ( V_123 | V_124 | V_125 | V_126 ) )
V_122 = ! ( ( F_16 ( V_2 , V_20 ) |
F_16 ( V_2 , V_21 ) ) & 1 ) ;
if ( V_122 ) {
V_71 = F_16 ( V_2 , V_20 ) ;
F_15 ( V_2 , V_20 , V_71 | ( 1 << 6 ) ) ;
}
V_120 &= 1 ;
V_71 = F_16 ( V_2 , V_20 ) ;
F_15 ( V_2 , V_20 , V_71 | V_120 ) ;
V_121 &= 1 ;
V_71 = F_16 ( V_2 , V_21 ) ;
F_15 ( V_2 , V_21 , V_71 | V_121 ) ;
F_59 ( 500 ) ;
if ( V_122 ) {
V_71 = F_16 ( V_2 , V_20 ) ;
F_15 ( V_2 , V_20 , V_71 | ( 1 << 7 ) ) ;
}
if ( V_2 -> V_7 -> V_56 ) {
V_71 = F_16 ( V_2 , V_57 ) ;
V_71 &= ~ ( V_120 ? V_127 : 0 ) ;
F_15 ( V_2 , V_57 , V_71 ) ;
V_71 = F_16 ( V_2 , V_59 ) ;
V_71 &= ~ ( V_121 ? V_128 : 0 ) ;
F_15 ( V_2 , V_59 , V_71 ) ;
}
F_9 ( V_14 ) ;
}
void F_60 ( unsigned int V_14 , int V_120 , int V_121 )
{
struct V_1 * V_2 ;
int V_129 ;
T_1 V_71 ;
if ( ! F_19 ( V_14 ) ) {
F_20 ( V_40 L_20 , V_41 , V_14 + 1 ) ;
return;
}
V_2 = F_10 ( V_14 ) ;
V_120 &= 1 ;
if ( V_2 -> V_7 -> V_56 ) {
V_71 = F_16 ( V_2 , V_57 ) ;
V_71 |= ( V_120 ? V_127 : 0 ) ;
F_15 ( V_2 , V_57 , V_71 ) ;
}
V_71 = F_16 ( V_2 , V_20 ) ;
F_15 ( V_2 , V_20 , V_71 & ~ V_120 ) ;
V_121 &= 1 ;
if ( V_2 -> V_7 -> V_56 ) {
V_71 = F_16 ( V_2 , V_59 ) ;
V_71 |= ( V_121 ? V_128 : 0 ) ;
F_15 ( V_2 , V_59 , V_71 ) ;
}
V_71 = F_16 ( V_2 , V_21 ) ;
F_15 ( V_2 , V_21 , V_71 & ~ V_121 ) ;
V_129 = ! ( ( F_16 ( V_2 , V_20 ) |
F_16 ( V_2 , V_21 ) ) & 1 ) ;
if ( V_129 ) {
V_71 = F_16 ( V_2 , V_20 ) ;
F_15 ( V_2 , V_20 , V_71 & ~ ( 1 << 6 ) ) ;
}
if ( V_2 -> V_12 )
F_37 ( V_2 ) ;
}
int F_61 ( T_4 V_14 , T_4 V_130 )
{
struct V_1 * V_2 ;
const char * V_131 ;
if ( ! F_19 ( V_14 ) ) {
F_62 ( L_20 , V_41 , V_14 + 1 ) ;
return - V_90 ;
}
V_2 = F_10 ( V_14 ) ;
if ( V_130 == V_132 )
V_131 = L_30 ;
else if ( V_130 == V_133 )
V_131 = L_31 ;
else
return - V_90 ;
if ( V_2 -> V_7 -> V_134 )
return V_2 -> V_7 -> V_134 ( V_2 -> V_15 , V_2 -> V_135 , V_131 ) ;
else
return - V_90 ;
}
void F_63 ( T_4 V_136 )
{
struct V_1 * V_2 ;
const char * V_131 ;
if ( V_136 == V_137 )
V_131 = L_32 ;
else if ( V_136 == V_138 )
V_131 = L_33 ;
else
return;
V_2 = F_10 ( 0 ) ;
if ( V_2 -> V_7 -> V_139 )
V_2 -> V_7 -> V_139 ( V_2 -> V_15 , L_32 , V_131 ) ;
}
void F_64 ( T_4 V_136 )
{
struct V_1 * V_2 ;
const char * V_131 ;
if ( V_136 == V_140 )
V_131 = L_34 ;
else if ( V_136 == V_141 )
V_131 = L_35 ;
else
return;
V_2 = F_10 ( 0 ) ;
if ( V_2 -> V_7 -> V_139 )
V_2 -> V_7 -> V_139 ( V_2 -> V_15 , L_34 , V_131 ) ;
}
static T_7 F_65 ( struct V_142 * V_15 ,
struct V_143 * V_144 , char * V_145 )
{
struct V_1 * V_2 = F_66 ( V_15 ) ;
int V_103 , V_77 = 0 ;
T_7 V_146 = 0 ;
const char * const * V_147 ;
V_103 = V_2 -> V_103 ;
for ( V_147 = & V_148 [ V_77 ] ; V_77 < F_67 ( V_148 ) ; V_147 ++ , V_77 ++ ) {
if ( V_103 == V_77 )
V_146 += sprintf ( V_145 + V_146 , L_36 , * V_147 ) ;
else
V_146 += sprintf ( V_145 + V_146 , L_37 , * V_147 ) ;
}
V_146 += sprintf ( V_145 + V_146 , L_38 ) ;
return V_146 ;
}
static T_7 F_68 ( struct V_142 * V_15 ,
struct V_143 * V_144 ,
const char * V_145 , T_8 V_149 )
{
struct V_1 * V_2 = F_66 ( V_15 ) ;
const char * const * V_147 ;
int V_77 = 0 ;
for ( V_147 = & V_148 [ V_77 ] ; V_77 < F_67 ( V_148 ) ; V_147 ++ , V_77 ++ )
if ( F_69 ( V_145 , * V_147 ) )
break;
if ( V_77 == F_67 ( V_148 ) )
return - V_90 ;
F_32 ( & V_2 -> V_89 ) ;
if ( ! V_2 -> free ) {
V_149 = - V_108 ;
goto V_150;
}
V_2 -> V_103 = V_77 ;
V_150:
F_33 ( & V_2 -> V_89 ) ;
return V_149 ;
}
static T_7 F_70 ( struct V_142 * V_15 ,
struct V_143 * V_144 , char * V_145 )
{
struct V_1 * V_2 = F_66 ( V_15 ) ;
struct V_81 * V_12 = V_2 -> V_12 ;
T_7 V_151 = 0 ;
int V_77 ;
F_32 ( & V_2 -> V_89 ) ;
for ( V_77 = 0 ; V_77 < V_12 -> V_152 ; V_77 ++ )
V_151 += sprintf ( & V_145 [ V_151 ] , ( V_77 ? L_39 : L_40 ) ,
V_12 -> V_93 [ V_77 ] ) ;
if ( V_77 )
V_151 += sprintf ( & V_145 [ V_151 ] , L_38 ) ;
F_33 ( & V_2 -> V_89 ) ;
return V_151 ;
}
static T_7 F_71 ( struct V_142 * V_15 ,
struct V_143 * V_144 ,
const char * V_145 , T_8 V_149 )
{
struct V_1 * V_2 = F_66 ( V_15 ) ;
struct V_81 * V_12 = V_2 -> V_12 ;
int V_4 , V_153 , V_151 , V_77 = 0 ;
F_32 ( & V_2 -> V_89 ) ;
memset ( V_12 -> V_93 , 0 , sizeof( V_12 -> V_93 ) ) ;
V_12 -> V_152 = 0 ;
do {
V_151 = sscanf ( V_145 , L_41 , & V_4 , & V_153 ) ;
if ( V_151 < 0 || V_151 == 0 ) {
V_149 = - V_90 ;
goto V_154;
}
if ( V_4 < - 32768 || V_4 > 32767 ) {
V_149 = - V_90 ;
goto V_154;
}
V_12 -> V_93 [ V_77 ++ ] = V_4 ;
V_145 += V_153 ;
if ( * V_145 != ',' )
break;
V_145 ++ ;
} while ( 1 );
V_12 -> V_152 = V_77 ;
V_154:
F_33 ( & V_2 -> V_89 ) ;
return V_149 ;
}
static int T_9 F_72 ( struct V_1 * V_2 ,
struct V_155 * V_156 )
{
struct V_81 * V_12 ;
int V_104 ;
V_12 = F_49 ( sizeof( * V_2 -> V_12 ) , V_106 ) ;
if ( ! V_12 ) {
V_104 = - V_107 ;
goto V_157;
}
V_12 -> V_13 = F_73 ( V_156 -> V_158 , F_74 ( V_156 ) ) ;
if ( ! V_12 -> V_13 ) {
V_104 = - V_107 ;
goto V_159;
}
V_104 = F_75 ( & V_2 -> V_15 -> V_160 , & V_161 ) ;
if ( V_104 )
goto V_162;
V_2 -> V_12 = V_12 ;
return 0 ;
V_162:
F_76 ( V_12 -> V_13 ) ;
V_159:
F_56 ( V_12 ) ;
V_157:
return V_104 ;
}
static void T_10 F_77 ( struct V_1 * V_2 )
{
struct V_81 * V_12 = V_2 -> V_12 ;
F_78 ( & V_2 -> V_15 -> V_160 , & V_161 ) ;
F_76 ( V_12 -> V_13 ) ;
F_56 ( V_12 ) ;
}
static int T_9 F_79 ( struct V_163 * V_164 )
{
struct V_165 * V_7 = V_164 -> V_15 . V_166 ;
struct V_1 * V_2 ;
int V_14 = V_164 -> V_14 - 1 ;
struct V_155 * V_156 ;
int V_87 = 0 ;
if ( ! V_7 ) {
F_14 ( & V_164 -> V_15 , L_42
L_43 ) ;
V_87 = - V_90 ;
goto exit;
}
F_11 ( & V_164 -> V_15 , L_44 , V_164 -> V_14 ) ;
if ( V_14 >= V_167 ) {
F_14 ( & V_164 -> V_15 , L_45 , V_14 ) ;
V_87 = - V_90 ;
goto exit;
}
V_2 = F_49 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 ) {
V_87 = - V_107 ;
goto exit;
}
F_80 ( & V_2 -> V_89 ) ;
V_2 -> V_14 = V_14 + 1 ;
V_2 -> free = true ;
V_156 = F_81 ( V_164 , V_168 , L_46 ) ;
if ( ! V_156 ) {
V_156 = F_82 ( V_164 , V_168 , 0 ) ;
if ( ! V_156 ) {
F_14 ( & V_164 -> V_15 , L_47
L_48 , V_41 , V_164 -> V_14 ) ;
V_87 = - V_107 ;
goto exit;
}
}
V_2 -> V_42 = V_156 -> V_158 ;
V_2 -> V_105 = F_74 ( V_156 ) ;
V_2 -> V_6 = F_73 ( V_156 -> V_158 , F_74 ( V_156 ) ) ;
if ( ! V_2 -> V_6 ) {
V_87 = - V_107 ;
goto V_169;
}
V_156 = F_81 ( V_164 , V_168 , L_49 ) ;
if ( ! V_156 )
V_2 -> V_70 = V_2 -> V_42 ;
else
V_2 -> V_70 = V_156 -> V_158 ;
V_2 -> V_116 = F_83 ( V_164 , L_50 ) ;
V_2 -> V_118 = F_83 ( V_164 , L_51 ) ;
if ( V_2 -> V_116 == - V_170 )
V_2 -> V_116 = F_84 ( V_164 , 0 ) ;
V_156 = F_81 ( V_164 , V_171 , L_51 ) ;
if ( ! V_156 ) {
F_14 ( & V_164 -> V_15 , L_52 ,
V_41 , V_164 -> V_14 ) ;
V_87 = - V_62 ;
goto V_172;
}
V_2 -> V_63 = V_156 -> V_158 ;
V_156 = F_81 ( V_164 , V_171 , L_50 ) ;
if ( ! V_156 ) {
F_14 ( & V_164 -> V_15 , L_53 ,
V_41 , V_164 -> V_14 ) ;
V_87 = - V_62 ;
goto V_172;
}
V_2 -> V_64 = V_156 -> V_158 ;
V_2 -> V_135 = F_85 ( & V_164 -> V_15 , L_54 ) ;
if ( F_86 ( V_2 -> V_135 ) ) {
V_87 = F_87 ( V_2 -> V_135 ) ;
F_14 ( & V_164 -> V_15 , L_55 , V_87 ) ;
goto V_172;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = & V_164 -> V_15 ;
V_173 [ V_14 ] = V_2 ;
F_88 ( V_164 , V_2 ) ;
F_89 ( V_2 -> V_15 ) ;
V_2 -> V_103 = V_174 ;
if ( V_2 -> V_7 -> V_95 ) {
V_2 -> V_96 = F_90 ( V_2 ) - 0x10 ;
V_2 -> V_98 = F_90 ( V_2 ) - 0x10 ;
V_87 = F_75 ( & V_2 -> V_15 -> V_160 ,
& V_175 ) ;
if ( V_87 ) {
F_14 ( V_2 -> V_15 ,
L_56 ) ;
goto V_176;
}
} else {
V_2 -> V_96 = - V_90 ;
V_2 -> V_98 = - V_90 ;
}
V_156 = F_81 ( V_164 , V_168 , L_57 ) ;
if ( V_156 ) {
V_87 = F_72 ( V_2 , V_156 ) ;
if ( V_87 ) {
F_14 ( V_2 -> V_15 ,
L_58 ) ;
goto V_177;
}
}
return 0 ;
V_177:
if ( V_2 -> V_7 -> V_95 )
F_78 ( & V_2 -> V_15 -> V_160 ,
& V_175 ) ;
V_176:
F_91 ( V_2 -> V_135 ) ;
V_172:
F_76 ( V_2 -> V_6 ) ;
V_169:
F_56 ( V_2 ) ;
exit:
return V_87 ;
}
static int T_10 F_92 ( struct V_163 * V_164 )
{
struct V_1 * V_2 = F_93 ( V_164 ) ;
F_88 ( V_164 , NULL ) ;
if ( V_2 ) {
if ( V_2 -> V_7 && V_2 -> V_7 -> V_110 &&
V_2 -> V_7 -> V_110 -> free )
V_2 -> V_7 -> V_110 -> free ( V_2 -> V_14 ) ;
if ( V_2 -> V_7 -> V_95 )
F_78 ( & V_2 -> V_15 -> V_160 ,
& V_175 ) ;
if ( V_2 -> V_12 )
F_77 ( V_2 ) ;
F_91 ( V_2 -> V_135 ) ;
F_76 ( V_2 -> V_6 ) ;
F_56 ( V_2 ) ;
}
return 0 ;
}
int T_11 F_94 ( void )
{
return F_95 ( & V_178 ) ;
}
