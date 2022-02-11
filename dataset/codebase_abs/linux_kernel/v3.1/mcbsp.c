static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( F_2 () ) {
( ( T_1 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_1 ) ] = ( T_1 ) V_4 ;
F_3 ( ( T_1 ) V_4 , V_2 -> V_6 + V_3 ) ;
} else if ( F_4 () ) {
( ( T_1 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_2 ) ] = ( T_1 ) V_4 ;
F_3 ( ( T_1 ) V_4 , V_2 -> V_6 + V_3 ) ;
} else {
( ( T_2 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_2 ) ] = V_4 ;
F_5 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , bool V_7 )
{
if ( F_2 () ) {
return ! V_7 ? F_7 ( V_2 -> V_6 + V_3 ) :
( ( T_1 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_1 ) ] ;
} else if ( F_4 () ) {
return ! V_7 ? F_7 ( V_2 -> V_6 + V_3 ) :
( ( T_1 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_2 ) ] ;
} else {
return ! V_7 ? F_8 ( V_2 -> V_6 + V_3 ) :
( ( T_2 * ) V_2 -> V_5 ) [ V_3 / sizeof( T_2 ) ] ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_5 ( V_4 , V_2 -> V_8 -> V_9 + V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_8 ( V_2 -> V_8 -> V_9 + V_3 ) ;
}
static void F_11 ( T_3 V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
F_13 ( V_2 -> V_11 , L_1 , V_2 -> V_10 ) ;
F_13 ( V_2 -> V_11 , L_2 ,
F_14 ( V_2 , V_12 ) ) ;
F_13 ( V_2 -> V_11 , L_3 ,
F_14 ( V_2 , V_13 ) ) ;
F_13 ( V_2 -> V_11 , L_4 ,
F_14 ( V_2 , V_14 ) ) ;
F_13 ( V_2 -> V_11 , L_5 ,
F_14 ( V_2 , V_15 ) ) ;
F_13 ( V_2 -> V_11 , L_6 ,
F_14 ( V_2 , V_16 ) ) ;
F_13 ( V_2 -> V_11 , L_7 ,
F_14 ( V_2 , V_17 ) ) ;
F_13 ( V_2 -> V_11 , L_8 ,
F_14 ( V_2 , V_18 ) ) ;
F_13 ( V_2 -> V_11 , L_9 ,
F_14 ( V_2 , V_19 ) ) ;
F_13 ( V_2 -> V_11 , L_10 ,
F_14 ( V_2 , V_20 ) ) ;
F_13 ( V_2 -> V_11 , L_11 ,
F_14 ( V_2 , V_21 ) ) ;
F_13 ( V_2 -> V_11 , L_12 ,
F_14 ( V_2 , V_22 ) ) ;
F_13 ( V_2 -> V_11 , L_13 ,
F_14 ( V_2 , V_23 ) ) ;
F_13 ( V_2 -> V_11 , L_14 ,
F_14 ( V_2 , V_24 ) ) ;
F_13 ( V_2 -> V_11 , L_15 ) ;
}
static T_4 F_15 ( int V_25 , void * V_26 )
{
struct V_1 * V_27 = V_26 ;
T_1 V_28 ;
V_28 = F_14 ( V_27 , V_16 ) ;
F_13 ( V_27 -> V_11 , L_16 , V_28 ) ;
if ( V_28 & V_29 ) {
F_16 ( V_27 -> V_11 , L_17 ,
V_28 ) ;
F_17 ( V_27 , V_16 , F_18 ( V_27 , V_16 ) ) ;
}
return V_30 ;
}
static T_4 F_19 ( int V_25 , void * V_26 )
{
struct V_1 * V_31 = V_26 ;
T_1 V_32 ;
V_32 = F_14 ( V_31 , V_17 ) ;
F_13 ( V_31 -> V_11 , L_18 , V_32 ) ;
if ( V_32 & V_33 ) {
F_16 ( V_31 -> V_11 , L_19 ,
V_32 ) ;
F_17 ( V_31 , V_17 , F_18 ( V_31 , V_17 ) ) ;
}
return V_30 ;
}
void F_20 ( unsigned int V_10 , const struct V_34 * V_35 )
{
struct V_1 * V_2 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
F_13 ( V_2 -> V_11 , L_21 ,
V_2 -> V_10 , V_2 -> V_38 ) ;
F_17 ( V_2 , V_16 , V_35 -> V_39 ) ;
F_17 ( V_2 , V_17 , V_35 -> V_40 ) ;
F_17 ( V_2 , V_18 , V_35 -> V_41 ) ;
F_17 ( V_2 , V_19 , V_35 -> V_42 ) ;
F_17 ( V_2 , V_20 , V_35 -> V_43 ) ;
F_17 ( V_2 , V_21 , V_35 -> V_44 ) ;
F_17 ( V_2 , V_22 , V_35 -> V_45 ) ;
F_17 ( V_2 , V_23 , V_35 -> V_46 ) ;
F_17 ( V_2 , V_47 , V_35 -> V_48 ) ;
F_17 ( V_2 , V_49 , V_35 -> V_50 ) ;
F_17 ( V_2 , V_24 , V_35 -> V_51 ) ;
if ( F_23 () || F_24 () || F_25 () ) {
F_17 ( V_2 , V_52 , V_35 -> V_53 ) ;
F_17 ( V_2 , V_54 , V_35 -> V_55 ) ;
}
}
int F_26 ( unsigned int V_10 , unsigned int V_56 )
{
struct V_1 * V_2 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
if ( V_56 )
return V_2 -> V_58 ;
else
return V_2 -> V_59 ;
}
int F_27 ( unsigned int V_10 , unsigned int V_56 )
{
struct V_1 * V_2 ;
int V_60 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_60 = V_2 -> V_61 ;
if ( V_2 -> V_62 < V_63 ) {
if ( V_56 )
V_60 += V_64 ;
else
V_60 += V_65 ;
} else {
if ( V_56 )
V_60 += V_66 ;
else
V_60 += V_67 ;
}
return V_60 ;
}
static struct V_68 * F_28 ( struct V_69 * V_11 )
{
struct V_70 * V_71 = F_29 ( V_11 ,
struct V_70 , V_11 ) ;
return F_29 ( V_71 , struct V_68 , V_71 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
V_72 = F_31 ( V_74 , V_75 ) ;
V_72 &= ~ ( 1 << ( V_2 -> V_10 - 2 ) ) ;
F_32 ( V_72 , V_74 , V_75 ) ;
V_72 = F_14 ( V_2 , V_76 ) ;
F_17 ( V_2 , V_76 , V_72 | V_77 ) ;
V_72 = F_33 ( V_2 , V_76 ) ;
F_34 ( V_2 , V_76 , V_72 | V_78 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
V_72 = F_33 ( V_2 , V_76 ) ;
F_34 ( V_2 , V_76 , V_72 & ~ ( V_78 ) ) ;
V_72 = F_14 ( V_2 , V_76 ) ;
F_17 ( V_2 , V_76 , V_72 & ~ ( V_77 ) ) ;
V_72 = F_31 ( V_74 , V_75 ) ;
V_72 |= 1 << ( V_2 -> V_10 - 2 ) ;
F_32 ( V_72 , V_74 , V_75 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_5 * V_79 )
{
T_1 V_4 , V_80 ;
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
V_4 = F_33 ( V_2 , V_76 ) ;
if ( V_4 & V_81 )
F_34 ( V_2 , V_76 , V_4 & ~ ( V_81 ) ) ;
F_34 ( V_2 , V_76 , V_4 | V_81 ) ;
for ( V_80 = 0 ; V_80 < 128 ; V_80 ++ )
F_34 ( V_2 , V_82 , V_79 [ V_80 ] ) ;
V_80 = 0 ;
V_4 = F_33 ( V_2 , V_76 ) ;
while ( ! ( V_4 & V_83 ) && ( ++ V_80 < 1000 ) )
V_4 = F_33 ( V_2 , V_76 ) ;
F_34 ( V_2 , V_76 , V_4 & ~ ( V_81 ) ) ;
if ( V_80 == 1000 )
F_16 ( V_2 -> V_11 , L_22 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_72 ;
struct V_84 * V_8 = V_2 -> V_8 ;
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
V_72 = F_33 ( V_2 , V_76 ) ;
F_34 ( V_2 , V_85 , F_38 ( V_8 -> V_86 ) | \
F_39 ( V_8 -> V_87 ) ) ;
}
int F_40 ( unsigned int V_10 , int V_88 , T_5 V_89 )
{
struct V_1 * V_2 ;
struct V_84 * V_8 ;
int V_90 = 0 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return - V_91 ;
F_41 ( & V_2 -> V_92 ) ;
if ( V_88 == 0 )
V_8 -> V_86 = V_89 ;
else if ( V_88 == 1 )
V_8 -> V_87 = V_89 ;
else
V_90 = - V_93 ;
if ( V_8 -> V_94 )
F_37 ( V_2 ) ;
F_42 ( & V_2 -> V_92 ) ;
return V_90 ;
}
int F_43 ( unsigned int V_10 , int V_88 , T_5 * V_89 )
{
struct V_1 * V_2 ;
struct V_84 * V_8 ;
int V_90 = 0 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return - V_91 ;
F_41 ( & V_2 -> V_92 ) ;
if ( V_88 == 0 )
* V_89 = V_8 -> V_86 ;
else if ( V_88 == 1 )
* V_89 = V_8 -> V_87 ;
else
V_90 = - V_93 ;
F_42 ( & V_2 -> V_92 ) ;
return V_90 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_84 * V_8 = V_2 -> V_8 ;
if ( V_8 && V_8 -> V_94 && ! V_8 -> V_95 ) {
F_36 ( V_2 , V_8 -> V_96 ) ;
F_37 ( V_2 ) ;
if ( ! V_2 -> free ) {
F_30 ( V_2 ) ;
V_8 -> V_95 = 1 ;
}
}
return 0 ;
}
int F_45 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_84 * V_8 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return - V_57 ;
F_41 ( & V_2 -> V_92 ) ;
V_8 -> V_94 = 1 ;
F_44 ( V_2 ) ;
F_42 ( & V_2 -> V_92 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_84 * V_8 = V_2 -> V_8 ;
if ( V_8 && V_8 -> V_95 ) {
if ( ! V_2 -> free ) {
F_35 ( V_2 ) ;
V_8 -> V_95 = 0 ;
}
}
return 0 ;
}
int F_47 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_84 * V_8 ;
int V_90 = 0 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return - V_57 ;
F_41 ( & V_2 -> V_92 ) ;
F_46 ( V_2 ) ;
V_8 -> V_94 = 0 ;
F_42 ( & V_2 -> V_92 ) ;
return V_90 ;
}
int F_48 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
struct V_84 * V_8 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_8 = V_2 -> V_8 ;
if ( ! V_8 )
return - V_57 ;
return V_8 -> V_94 ;
}
void F_49 ( unsigned int V_10 , T_1 V_97 )
{
struct V_1 * V_2 ;
if ( ! F_24 () && ! F_25 () )
return;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
if ( V_97 && V_97 <= V_2 -> V_98 )
F_17 ( V_2 , V_99 , V_97 - 1 ) ;
}
void F_50 ( unsigned int V_10 , T_1 V_97 )
{
struct V_1 * V_2 ;
if ( ! F_24 () && ! F_25 () )
return;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
if ( V_97 && V_97 <= V_2 -> V_100 )
F_17 ( V_2 , V_101 , V_97 - 1 ) ;
}
T_1 F_51 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
return V_2 -> V_98 ;
}
T_1 F_52 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
return V_2 -> V_100 ;
}
T_1 F_53 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
return V_2 -> V_102 -> V_103 ;
}
T_1 F_54 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
T_1 V_104 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_104 = F_14 ( V_2 , V_105 ) ;
return V_2 -> V_102 -> V_103 - V_104 ;
}
T_1 F_55 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
T_1 V_104 , V_97 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_104 = F_14 ( V_2 , V_106 ) ;
V_97 = F_14 ( V_2 , V_101 ) ;
if ( V_97 <= V_104 )
return 0 ;
else
return V_97 - V_104 ;
}
int F_56 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
int V_107 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_23 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_107 = V_2 -> V_107 ;
return V_107 ;
}
static inline void F_57 ( struct V_1 * V_2 )
{
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
if ( F_24 () || F_25 () ) {
F_17 ( V_2 , V_108 , V_109 | V_110 ) ;
}
}
static inline void F_58 ( struct V_1 * V_2 )
{
struct V_68 * V_73 ;
V_73 = F_28 ( V_2 -> V_11 ) ;
if ( F_24 () || F_25 () ) {
F_17 ( V_2 , V_108 , 0 ) ;
}
}
static inline void F_57 ( struct V_1 * V_2 ) {}
static inline void F_58 ( struct V_1 * V_2 ) {}
static inline void F_44 ( struct V_1 * V_2 ) {}
static inline void F_46 ( struct V_1 * V_2 ) {}
int F_59 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
void * V_5 ;
int V_111 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return - V_57 ;
}
V_2 = F_12 ( V_10 ) ;
V_5 = F_60 ( V_112 , V_113 ) ;
if ( ! V_5 ) {
return - V_114 ;
}
F_61 ( & V_2 -> V_92 ) ;
if ( ! V_2 -> free ) {
F_16 ( V_2 -> V_11 , L_24 ,
V_2 -> V_10 ) ;
V_111 = - V_115 ;
goto V_116;
}
V_2 -> free = false ;
V_2 -> V_5 = V_5 ;
F_62 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_102 && V_2 -> V_102 -> V_117 && V_2 -> V_102 -> V_117 -> V_118 )
V_2 -> V_102 -> V_117 -> V_118 ( V_10 ) ;
F_63 ( V_2 -> V_11 ) ;
F_57 ( V_2 ) ;
F_17 ( V_2 , V_17 , 0 ) ;
F_17 ( V_2 , V_16 , 0 ) ;
V_111 = F_64 ( V_2 -> V_119 , F_15 ,
0 , L_25 , ( void * ) V_2 ) ;
if ( V_111 != 0 ) {
F_16 ( V_2 -> V_11 , L_26
L_27 , V_2 -> V_119 ,
V_2 -> V_10 ) ;
goto V_120;
}
if ( V_2 -> V_121 ) {
V_111 = F_64 ( V_2 -> V_121 ,
F_19 ,
0 , L_25 , ( void * ) V_2 ) ;
if ( V_111 != 0 ) {
F_16 ( V_2 -> V_11 , L_28
L_27 , V_2 -> V_121 ,
V_2 -> V_10 ) ;
goto V_122;
}
}
return 0 ;
V_122:
F_65 ( V_2 -> V_119 , ( void * ) V_2 ) ;
V_120:
if ( V_2 -> V_102 && V_2 -> V_102 -> V_117 && V_2 -> V_102 -> V_117 -> free )
V_2 -> V_102 -> V_117 -> free ( V_10 ) ;
F_58 ( V_2 ) ;
F_66 ( V_2 -> V_11 ) ;
F_61 ( & V_2 -> V_92 ) ;
V_2 -> free = true ;
V_2 -> V_5 = NULL ;
V_116:
F_62 ( & V_2 -> V_92 ) ;
F_67 ( V_5 ) ;
return V_111 ;
}
void F_68 ( unsigned int V_10 )
{
struct V_1 * V_2 ;
void * V_5 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
if ( V_2 -> V_102 && V_2 -> V_102 -> V_117 && V_2 -> V_102 -> V_117 -> free )
V_2 -> V_102 -> V_117 -> free ( V_10 ) ;
F_58 ( V_2 ) ;
F_66 ( V_2 -> V_11 ) ;
if ( V_2 -> V_121 )
F_65 ( V_2 -> V_121 , ( void * ) V_2 ) ;
F_65 ( V_2 -> V_119 , ( void * ) V_2 ) ;
V_5 = V_2 -> V_5 ;
F_61 ( & V_2 -> V_92 ) ;
if ( V_2 -> free )
F_16 ( V_2 -> V_11 , L_29 , V_2 -> V_10 ) ;
else
V_2 -> free = true ;
V_2 -> V_5 = NULL ;
F_62 ( & V_2 -> V_92 ) ;
if ( V_5 )
F_67 ( V_5 ) ;
}
void F_69 ( unsigned int V_10 , int V_123 , int V_124 )
{
struct V_1 * V_2 ;
int V_125 = 0 ;
T_1 V_72 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
if ( F_24 () )
F_44 ( V_2 ) ;
V_72 = F_18 ( V_2 , V_24 ) ;
if ( V_72 & ( V_126 | V_127 | V_128 | V_129 ) )
V_125 = ! ( ( F_18 ( V_2 , V_16 ) |
F_18 ( V_2 , V_17 ) ) & 1 ) ;
if ( V_125 ) {
V_72 = F_18 ( V_2 , V_16 ) ;
F_17 ( V_2 , V_16 , V_72 | ( 1 << 6 ) ) ;
}
V_123 &= 1 ;
V_72 = F_18 ( V_2 , V_16 ) ;
F_17 ( V_2 , V_16 , V_72 | V_123 ) ;
V_124 &= 1 ;
V_72 = F_18 ( V_2 , V_17 ) ;
F_17 ( V_2 , V_17 , V_72 | V_124 ) ;
F_70 ( 500 ) ;
if ( V_125 ) {
V_72 = F_18 ( V_2 , V_16 ) ;
F_17 ( V_2 , V_16 , V_72 | ( 1 << 7 ) ) ;
}
if ( F_23 () || F_24 () || F_25 () ) {
V_72 = F_18 ( V_2 , V_52 ) ;
V_72 &= ~ ( V_123 ? V_130 : 0 ) ;
F_17 ( V_2 , V_52 , V_72 ) ;
V_72 = F_18 ( V_2 , V_54 ) ;
V_72 &= ~ ( V_124 ? V_131 : 0 ) ;
F_17 ( V_2 , V_54 , V_72 ) ;
}
F_11 ( V_10 ) ;
}
void F_71 ( unsigned int V_10 , int V_123 , int V_124 )
{
struct V_1 * V_2 ;
int V_132 ;
T_1 V_72 ;
if ( ! F_21 ( V_10 ) ) {
F_22 ( V_36 L_20 , V_37 , V_10 + 1 ) ;
return;
}
V_2 = F_12 ( V_10 ) ;
V_123 &= 1 ;
if ( F_23 () || F_24 () || F_25 () ) {
V_72 = F_18 ( V_2 , V_52 ) ;
V_72 |= ( V_123 ? V_130 : 0 ) ;
F_17 ( V_2 , V_52 , V_72 ) ;
}
V_72 = F_18 ( V_2 , V_16 ) ;
F_17 ( V_2 , V_16 , V_72 & ~ V_123 ) ;
V_124 &= 1 ;
if ( F_23 () || F_24 () || F_25 () ) {
V_72 = F_18 ( V_2 , V_54 ) ;
V_72 |= ( V_124 ? V_131 : 0 ) ;
F_17 ( V_2 , V_54 , V_72 ) ;
}
V_72 = F_18 ( V_2 , V_17 ) ;
F_17 ( V_2 , V_17 , V_72 & ~ V_124 ) ;
V_132 = ! ( ( F_18 ( V_2 , V_16 ) |
F_18 ( V_2 , V_17 ) ) & 1 ) ;
if ( V_132 ) {
V_72 = F_18 ( V_2 , V_16 ) ;
F_17 ( V_2 , V_16 , V_72 & ~ ( 1 << 6 ) ) ;
}
if ( F_24 () )
F_46 ( V_2 ) ;
}
int F_72 ( T_3 V_10 , T_3 V_133 )
{
F_73 ( 1 , L_30 ,
V_37 ) ;
return - V_93 ;
}
void F_74 ( T_3 V_134 )
{
F_73 ( 1 , L_30 ,
V_37 ) ;
return;
}
void F_75 ( T_3 V_134 )
{
F_73 ( 1 , L_30 ,
V_37 ) ;
return;
}
static T_6 F_76 ( struct V_69 * V_11 ,
struct V_135 * V_136 , char * V_137 )
{
struct V_1 * V_2 = F_77 ( V_11 ) ;
int V_107 , V_80 = 0 ;
T_6 V_138 = 0 ;
const char * const * V_139 ;
V_107 = V_2 -> V_107 ;
for ( V_139 = & V_140 [ V_80 ] ; V_80 < F_78 ( V_140 ) ; V_139 ++ , V_80 ++ ) {
if ( V_107 == V_80 )
V_138 += sprintf ( V_137 + V_138 , L_31 , * V_139 ) ;
else
V_138 += sprintf ( V_137 + V_138 , L_32 , * V_139 ) ;
}
V_138 += sprintf ( V_137 + V_138 , L_33 ) ;
return V_138 ;
}
static T_6 F_79 ( struct V_69 * V_11 ,
struct V_135 * V_136 ,
const char * V_137 , T_7 V_141 )
{
struct V_1 * V_2 = F_77 ( V_11 ) ;
const char * const * V_139 ;
int V_80 = 0 ;
for ( V_139 = & V_140 [ V_80 ] ; V_80 < F_78 ( V_140 ) ; V_139 ++ , V_80 ++ )
if ( F_80 ( V_137 , * V_139 ) )
break;
if ( V_80 == F_78 ( V_140 ) )
return - V_93 ;
F_41 ( & V_2 -> V_92 ) ;
if ( ! V_2 -> free ) {
V_141 = - V_115 ;
goto V_142;
}
V_2 -> V_107 = V_80 ;
V_142:
F_42 ( & V_2 -> V_92 ) ;
return V_141 ;
}
static T_6 F_81 ( struct V_69 * V_11 ,
struct V_135 * V_136 , char * V_137 )
{
struct V_1 * V_2 = F_77 ( V_11 ) ;
struct V_84 * V_8 = V_2 -> V_8 ;
T_6 V_143 = 0 ;
int V_80 ;
F_41 ( & V_2 -> V_92 ) ;
for ( V_80 = 0 ; V_80 < V_8 -> V_144 ; V_80 ++ )
V_143 += sprintf ( & V_137 [ V_143 ] , ( V_80 ? L_34 : L_35 ) ,
V_8 -> V_96 [ V_80 ] ) ;
if ( V_80 )
V_143 += sprintf ( & V_137 [ V_143 ] , L_33 ) ;
F_42 ( & V_2 -> V_92 ) ;
return V_143 ;
}
static T_6 F_82 ( struct V_69 * V_11 ,
struct V_135 * V_136 ,
const char * V_137 , T_7 V_141 )
{
struct V_1 * V_2 = F_77 ( V_11 ) ;
struct V_84 * V_8 = V_2 -> V_8 ;
int V_4 , V_145 , V_143 , V_80 = 0 ;
F_41 ( & V_2 -> V_92 ) ;
memset ( V_8 -> V_96 , 0 , sizeof( V_8 -> V_96 ) ) ;
V_8 -> V_144 = 0 ;
do {
V_143 = sscanf ( V_137 , L_36 , & V_4 , & V_145 ) ;
if ( V_143 < 0 || V_143 == 0 ) {
V_141 = - V_93 ;
goto V_146;
}
if ( V_4 < - 32768 || V_4 > 32767 ) {
V_141 = - V_93 ;
goto V_146;
}
V_8 -> V_96 [ V_80 ++ ] = V_4 ;
V_137 += V_145 ;
if ( * V_137 != ',' )
break;
V_137 ++ ;
} while ( 1 );
V_8 -> V_144 = V_80 ;
V_146:
F_42 ( & V_2 -> V_92 ) ;
return V_141 ;
}
static inline int T_8 F_83 ( struct V_69 * V_11 )
{
return F_84 ( & V_11 -> V_147 , & V_148 ) ;
}
static inline void T_9 F_85 ( struct V_69 * V_11 )
{
F_86 ( & V_11 -> V_147 , & V_148 ) ;
}
static int T_8 F_87 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
struct V_149 * V_150 ;
struct V_84 * V_8 ;
int V_111 ;
V_8 = F_60 ( sizeof( * V_2 -> V_8 ) , V_113 ) ;
if ( ! V_8 ) {
V_111 = - V_114 ;
goto V_151;
}
V_71 = F_29 ( V_2 -> V_11 , struct V_70 , V_11 ) ;
V_150 = F_88 ( V_71 , V_152 , L_37 ) ;
V_8 -> V_9 = F_89 ( V_150 -> V_153 , F_90 ( V_150 ) ) ;
if ( ! V_8 -> V_9 ) {
V_111 = - V_114 ;
goto V_154;
}
V_111 = F_84 ( & V_2 -> V_11 -> V_147 , & V_155 ) ;
if ( V_111 )
goto V_156;
V_2 -> V_8 = V_8 ;
return 0 ;
V_156:
F_91 ( V_8 -> V_9 ) ;
V_154:
F_67 ( V_8 ) ;
V_151:
return V_111 ;
}
static void T_9 F_92 ( struct V_1 * V_2 )
{
struct V_84 * V_8 = V_2 -> V_8 ;
if ( V_8 ) {
F_86 ( & V_2 -> V_11 -> V_147 , & V_155 ) ;
F_91 ( V_8 -> V_9 ) ;
F_67 ( V_8 ) ;
}
}
static inline void T_8 F_93 ( struct V_1 * V_2 )
{
V_2 -> V_107 = V_157 ;
if ( F_24 () ) {
V_2 -> V_98 = F_94 ( V_2 ) - 0x10 ;
V_2 -> V_100 = F_94 ( V_2 ) - 0x10 ;
if ( F_83 ( V_2 -> V_11 ) )
F_95 ( V_2 -> V_11 ,
L_38 ) ;
if ( V_2 -> V_10 == 2 || V_2 -> V_10 == 3 )
if ( F_87 ( V_2 ) )
F_95 ( V_2 -> V_11 ,
L_39 ) ;
} else {
V_2 -> V_98 = - V_93 ;
V_2 -> V_100 = - V_93 ;
}
}
static inline void T_9 F_96 ( struct V_1 * V_2 )
{
if ( F_24 () ) {
F_85 ( V_2 -> V_11 ) ;
if ( V_2 -> V_10 == 2 || V_2 -> V_10 == 3 )
F_92 ( V_2 ) ;
}
}
static inline void T_8 F_93 ( struct V_1 * V_2 ) {}
static inline void T_9 F_96 ( struct V_1 * V_2 ) {}
static int T_8 F_97 ( struct V_70 * V_71 )
{
struct V_158 * V_102 = V_71 -> V_11 . V_159 ;
struct V_1 * V_2 ;
int V_10 = V_71 -> V_10 - 1 ;
struct V_149 * V_150 ;
int V_90 = 0 ;
if ( ! V_102 ) {
F_16 ( & V_71 -> V_11 , L_40
L_41 ) ;
V_90 = - V_93 ;
goto exit;
}
F_13 ( & V_71 -> V_11 , L_42 , V_71 -> V_10 ) ;
if ( V_10 >= V_160 ) {
F_16 ( & V_71 -> V_11 , L_43 , V_10 ) ;
V_90 = - V_93 ;
goto exit;
}
V_2 = F_60 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 ) {
V_90 = - V_114 ;
goto exit;
}
F_98 ( & V_2 -> V_92 ) ;
V_2 -> V_10 = V_10 + 1 ;
V_2 -> free = true ;
V_150 = F_88 ( V_71 , V_152 , L_44 ) ;
if ( ! V_150 ) {
V_150 = F_99 ( V_71 , V_152 , 0 ) ;
if ( ! V_150 ) {
F_16 ( & V_71 -> V_11 , L_45
L_46 , V_37 , V_71 -> V_10 ) ;
V_90 = - V_114 ;
goto exit;
}
}
V_2 -> V_38 = V_150 -> V_153 ;
V_112 = F_90 ( V_150 ) ;
V_2 -> V_6 = F_89 ( V_150 -> V_153 , F_90 ( V_150 ) ) ;
if ( ! V_2 -> V_6 ) {
V_90 = - V_114 ;
goto V_161;
}
V_150 = F_88 ( V_71 , V_152 , L_47 ) ;
if ( ! V_150 )
V_2 -> V_61 = V_2 -> V_38 ;
else
V_2 -> V_61 = V_150 -> V_153 ;
V_2 -> V_119 = F_100 ( V_71 , L_48 ) ;
V_2 -> V_121 = F_100 ( V_71 , L_49 ) ;
if ( V_2 -> V_119 == - V_162 )
V_2 -> V_119 = F_101 ( V_71 , 0 ) ;
V_150 = F_88 ( V_71 , V_163 , L_49 ) ;
if ( ! V_150 ) {
F_16 ( & V_71 -> V_11 , L_50 ,
V_37 , V_71 -> V_10 ) ;
V_90 = - V_57 ;
goto V_164;
}
V_2 -> V_58 = V_150 -> V_153 ;
V_150 = F_88 ( V_71 , V_163 , L_48 ) ;
if ( ! V_150 ) {
F_16 ( & V_71 -> V_11 , L_51 ,
V_37 , V_71 -> V_10 ) ;
V_90 = - V_57 ;
goto V_164;
}
V_2 -> V_59 = V_150 -> V_153 ;
V_2 -> V_165 = F_102 ( & V_71 -> V_11 , L_52 ) ;
if ( F_103 ( V_2 -> V_165 ) ) {
V_90 = F_104 ( V_2 -> V_165 ) ;
F_16 ( & V_71 -> V_11 , L_53 , V_90 ) ;
goto V_164;
}
V_2 -> V_102 = V_102 ;
V_2 -> V_11 = & V_71 -> V_11 ;
V_166 [ V_10 ] = V_2 ;
V_2 -> V_62 = V_102 -> V_62 ;
F_105 ( V_71 , V_2 ) ;
F_106 ( V_2 -> V_11 ) ;
F_93 ( V_2 ) ;
return 0 ;
V_164:
F_91 ( V_2 -> V_6 ) ;
V_161:
F_67 ( V_2 ) ;
exit:
return V_90 ;
}
static int T_9 F_107 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_108 ( V_71 ) ;
F_105 ( V_71 , NULL ) ;
if ( V_2 ) {
if ( V_2 -> V_102 && V_2 -> V_102 -> V_117 &&
V_2 -> V_102 -> V_117 -> free )
V_2 -> V_102 -> V_117 -> free ( V_2 -> V_10 ) ;
F_96 ( V_2 ) ;
F_109 ( V_2 -> V_165 ) ;
F_91 ( V_2 -> V_6 ) ;
F_67 ( V_2 ) ;
}
return 0 ;
}
int T_10 F_110 ( void )
{
return F_111 ( & V_167 ) ;
}
