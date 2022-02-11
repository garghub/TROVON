static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
if ( V_4 -> V_2 == V_5 && V_2 != V_5 )
V_4 -> V_2 = V_2 ;
F_3 ( V_1 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_6 ;
T_1 V_2 = V_1 -> V_7 ;
F_5 ( V_1 ) ;
F_1 ( V_4 -> V_1 , V_2 ) ;
}
static int F_6 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 , T_2 V_12 ,
unsigned int V_13 )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
T_2 V_14 ;
struct V_1 * V_15 ;
V_14 = F_7 ( V_9 -> V_16 , V_11 ) + F_8 ( V_12 ) ;
if ( V_13 == F_9 ( V_1 ) ) {
V_1 -> V_17 . V_18 = V_14 ;
F_10 ( & V_4 -> V_19 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
V_15 = F_12 ( V_1 , V_20 , V_9 -> V_21 ) ;
if ( ! V_15 )
return - V_22 ;
V_15 -> V_17 . V_18 = V_14 ;
V_15 -> V_17 . V_23 = F_8 ( V_13 ) << V_24 ;
V_15 -> V_25 = F_4 ;
V_15 -> V_6 = V_4 ;
F_13 ( V_1 , V_15 -> V_17 . V_23 ) ;
F_10 ( & V_4 -> V_19 ) ;
F_11 ( V_15 ) ;
return 0 ;
}
static void F_14 ( struct V_8 * V_9 , struct V_1 * V_1 ,
T_2 V_12 , unsigned int V_13 )
{
unsigned int V_26 = V_13 << V_27 ;
F_15 ( V_1 -> V_17 . V_23 , V_26 ) ;
F_16 ( V_1 ) ;
F_15 ( V_1 -> V_17 . V_23 , V_26 ) ;
F_13 ( V_1 , V_26 ) ;
}
static int F_17 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 )
{
T_2 V_12 = F_18 ( V_9 -> V_28 , F_19 ( V_1 ) ) ;
unsigned int V_13 = F_9 ( V_1 ) ;
T_2 V_29 = V_12 + V_13 ;
struct V_10 * V_30 , * V_31 ;
int V_32 ;
if ( ! V_11 ) {
F_16 ( V_1 ) ;
return 0 ;
}
F_20 ( V_9 -> V_28 , L_1 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
( F_22 ( V_11 ) ? L_2 : L_3 ) ,
F_23 ( V_9 -> V_16 , V_11 ) ,
( unsigned long long ) V_12 , V_13 ) ;
V_31 = V_11 -> V_31 ;
while ( V_12 < V_29 ) {
V_13 = 0 ;
if ( F_22 ( V_11 ) || V_12 < V_11 -> V_33 ) {
V_32 = F_24 ( V_9 -> V_16 , V_11 , V_12 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 > 0 ) {
V_13 = V_32 ;
V_30 = V_11 ;
}
}
if ( ! V_13 && V_31 ) {
V_32 = F_24 ( V_9 -> V_16 , V_31 , V_12 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_32 > 0 ) {
V_13 = V_32 ;
V_30 = V_31 ;
}
}
if ( V_13 ) {
V_13 = F_25 (unsigned int, nr_blocks, end_block - chunk_block) ;
V_32 = F_6 ( V_9 , V_30 , V_1 , V_12 , V_13 ) ;
if ( V_32 )
return V_32 ;
V_12 += V_13 ;
} else {
F_14 ( V_9 , V_1 , V_12 , 1 ) ;
V_12 ++ ;
}
}
return 0 ;
}
static void F_26 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 , T_2 V_12 ,
unsigned int V_13 )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
V_1 -> V_34 = V_9 -> V_28 -> V_35 ;
V_1 -> V_17 . V_18 = F_7 ( V_9 -> V_16 , V_11 ) + F_8 ( V_12 ) ;
F_10 ( & V_4 -> V_19 ) ;
F_11 ( V_1 ) ;
if ( F_27 ( V_11 ) )
V_11 -> V_33 += V_13 ;
}
static int F_28 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_1 * V_1 ,
T_2 V_12 ,
unsigned int V_13 )
{
struct V_36 * V_37 = V_9 -> V_16 ;
struct V_10 * V_31 = V_11 -> V_31 ;
int V_32 ;
if ( F_29 ( V_11 ) )
return - V_38 ;
F_26 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
V_32 = F_30 ( V_37 , V_11 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_31 )
V_32 = F_31 ( V_37 , V_31 , V_12 , V_13 ) ;
return V_32 ;
}
static int F_32 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_1 * V_1 ,
T_2 V_12 ,
unsigned int V_13 )
{
struct V_36 * V_37 = V_9 -> V_16 ;
struct V_10 * V_31 ;
int V_32 ;
V_31 = F_33 ( V_37 , V_11 ) ;
if ( ! V_31 )
return - V_39 ;
if ( F_29 ( V_31 ) )
return - V_38 ;
F_26 ( V_9 , V_31 , V_1 , V_12 , V_13 ) ;
V_32 = F_30 ( V_37 , V_31 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_12 < V_11 -> V_33 )
V_32 = F_31 ( V_37 , V_11 , V_12 , V_13 ) ;
return V_32 ;
}
static int F_34 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 )
{
T_2 V_12 = F_18 ( V_9 -> V_28 , F_19 ( V_1 ) ) ;
unsigned int V_13 = F_9 ( V_1 ) ;
if ( ! V_11 )
return - V_39 ;
F_20 ( V_9 -> V_28 , L_4 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
( F_22 ( V_11 ) ? L_2 : L_3 ) ,
F_23 ( V_9 -> V_16 , V_11 ) ,
( unsigned long long ) V_12 , V_13 ) ;
if ( F_22 ( V_11 ) || V_12 == V_11 -> V_33 ) {
return F_28 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
}
return F_32 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
}
static int F_35 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 )
{
struct V_36 * V_37 = V_9 -> V_16 ;
T_2 V_40 = F_19 ( V_1 ) ;
unsigned int V_13 = F_9 ( V_1 ) ;
T_2 V_12 = F_18 ( V_9 -> V_28 , V_40 ) ;
int V_32 = 0 ;
if ( ! V_11 )
return 0 ;
if ( F_29 ( V_11 ) )
return - V_38 ;
F_20 ( V_9 -> V_28 , L_5 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
F_23 ( V_37 , V_11 ) ,
( unsigned long long ) V_12 , V_13 ) ;
if ( F_22 ( V_11 ) || V_12 < V_11 -> V_33 )
V_32 = F_31 ( V_37 , V_11 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_11 -> V_31 )
V_32 = F_31 ( V_37 , V_11 -> V_31 ,
V_12 , V_13 ) ;
return V_32 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_41 * V_42 ,
struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
struct V_36 * V_37 = V_9 -> V_16 ;
struct V_10 * V_11 ;
int V_32 ;
if ( F_37 ( V_1 ) == V_43 )
F_38 ( V_9 -> V_44 ) ;
F_39 ( V_37 ) ;
V_11 = F_40 ( V_37 , F_21 ( V_9 -> V_28 , V_1 ) ,
F_37 ( V_1 ) ) ;
if ( F_41 ( V_11 ) ) {
V_32 = F_42 ( V_11 ) ;
goto V_45;
}
if ( V_11 ) {
F_43 ( V_11 ) ;
V_4 -> V_11 = V_11 ;
}
switch ( F_37 ( V_1 ) ) {
case V_46 :
V_32 = F_17 ( V_9 , V_11 , V_1 ) ;
break;
case V_43 :
V_32 = F_34 ( V_9 , V_11 , V_1 ) ;
break;
case V_47 :
case V_48 :
V_32 = F_35 ( V_9 , V_11 , V_1 ) ;
break;
default:
F_44 ( V_9 -> V_28 , L_6 ,
F_37 ( V_1 ) ) ;
V_32 = - V_49 ;
}
if ( V_11 )
F_45 ( V_37 , V_11 ) ;
V_45:
F_1 ( V_1 , F_46 ( V_32 ) ) ;
F_47 ( V_37 ) ;
}
static inline void F_48 ( struct V_41 * V_42 )
{
F_10 ( & V_42 -> V_50 ) ;
}
static void F_49 ( struct V_41 * V_42 )
{
if ( F_50 ( & V_42 -> V_50 ) ) {
F_51 ( ! F_52 ( & V_42 -> V_51 ) ) ;
F_53 ( & V_42 -> V_52 -> V_53 , V_42 -> V_54 ) ;
F_54 ( V_42 ) ;
}
}
static void F_55 ( struct V_55 * V_56 )
{
struct V_41 * V_42 = F_56 ( V_56 , struct V_41 , V_56 ) ;
struct V_8 * V_9 = V_42 -> V_52 ;
struct V_1 * V_1 ;
F_57 ( & V_9 -> V_57 ) ;
while ( ( V_1 = F_58 ( & V_42 -> V_51 ) ) ) {
F_59 ( & V_9 -> V_57 ) ;
F_36 ( V_9 , V_42 , V_1 ) ;
F_57 ( & V_9 -> V_57 ) ;
F_49 ( V_42 ) ;
}
F_49 ( V_42 ) ;
F_59 ( & V_9 -> V_57 ) ;
}
static void F_60 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_56 ( V_56 , struct V_8 , V_58 . V_56 ) ;
struct V_1 * V_1 ;
int V_32 ;
V_32 = F_61 ( V_9 -> V_16 ) ;
while ( 1 ) {
F_62 ( & V_9 -> V_59 ) ;
V_1 = F_58 ( & V_9 -> V_60 ) ;
F_63 ( & V_9 -> V_59 ) ;
if ( ! V_1 )
break;
F_1 ( V_1 , F_46 ( V_32 ) ) ;
}
F_64 ( V_9 -> V_61 , & V_9 -> V_58 , V_62 ) ;
}
static void F_65 ( struct V_8 * V_9 , struct V_1 * V_1 )
{
unsigned int V_54 = F_21 ( V_9 -> V_28 , V_1 ) ;
struct V_41 * V_42 ;
F_57 ( & V_9 -> V_57 ) ;
V_42 = F_66 ( & V_9 -> V_53 , V_54 ) ;
if ( ! V_42 ) {
int V_32 ;
V_42 = F_67 ( sizeof( struct V_41 ) , V_20 ) ;
if ( ! V_42 )
goto V_45;
F_68 ( & V_42 -> V_56 , F_55 ) ;
F_69 ( & V_42 -> V_50 , 0 ) ;
V_42 -> V_52 = V_9 ;
V_42 -> V_54 = V_54 ;
F_70 ( & V_42 -> V_51 ) ;
V_32 = F_71 ( & V_9 -> V_53 , V_54 , V_42 ) ;
if ( F_72 ( V_32 ) ) {
F_54 ( V_42 ) ;
V_42 = NULL ;
goto V_45;
}
}
F_73 ( & V_42 -> V_51 , V_1 ) ;
F_48 ( V_42 ) ;
if ( F_74 ( V_9 -> V_63 , & V_42 -> V_56 ) )
F_48 ( V_42 ) ;
V_45:
F_59 ( & V_9 -> V_57 ) ;
}
static int F_75 ( struct V_64 * V_65 , struct V_1 * V_1 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
struct V_67 * V_28 = V_9 -> V_28 ;
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
T_2 V_14 = V_1 -> V_17 . V_18 ;
unsigned int V_68 = F_76 ( V_1 ) ;
T_2 V_69 ;
F_20 ( V_28 , L_7 ,
F_37 ( V_1 ) , ( unsigned long long ) V_14 , V_68 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
( unsigned long long ) F_18 ( V_9 -> V_28 , F_19 ( V_1 ) ) ,
( unsigned int ) F_9 ( V_1 ) ) ;
V_1 -> V_34 = V_28 -> V_35 ;
if ( ! V_68 && F_37 ( V_1 ) != V_43 )
return V_70 ;
if ( ( V_68 & V_71 ) || ( V_14 & V_71 ) )
return V_72 ;
V_4 -> V_52 = V_9 ;
V_4 -> V_11 = NULL ;
V_4 -> V_1 = V_1 ;
F_69 ( & V_4 -> V_19 , 1 ) ;
V_4 -> V_2 = V_5 ;
if ( ! V_68 && F_37 ( V_1 ) == V_43 ) {
F_62 ( & V_9 -> V_59 ) ;
F_73 ( & V_9 -> V_60 , V_1 ) ;
F_63 ( & V_9 -> V_59 ) ;
F_77 ( V_9 -> V_61 , & V_9 -> V_58 , 0 ) ;
return V_73 ;
}
V_69 = V_14 & ( V_28 -> V_74 - 1 ) ;
if ( V_69 + V_68 > V_28 -> V_74 )
F_78 ( V_1 , V_28 -> V_74 - V_69 ) ;
F_79 ( V_9 -> V_44 ) ;
F_65 ( V_9 , V_1 ) ;
return V_73 ;
}
static int F_80 ( struct V_64 * V_65 , struct V_1 * V_1 , T_1 * error )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
if ( V_4 -> V_2 == V_5 && * error )
V_4 -> V_2 = * error ;
if ( ! F_50 ( & V_4 -> V_19 ) )
return V_75 ;
V_1 -> V_7 = V_4 -> V_2 ;
if ( V_4 -> V_11 ) {
struct V_10 * V_11 = V_4 -> V_11 ;
if ( * error && F_37 ( V_1 ) == V_43 ) {
if ( F_27 ( V_11 ) )
F_81 ( V_76 , & V_11 -> V_77 ) ;
}
F_82 ( V_11 ) ;
}
return V_78 ;
}
static int F_83 ( struct V_64 * V_65 , char * V_79 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
struct V_80 * V_81 ;
struct V_67 * V_28 ;
int V_32 ;
V_32 = F_84 ( V_65 , V_79 , F_85 ( V_65 -> V_82 ) , & V_9 -> V_83 ) ;
if ( V_32 ) {
V_65 -> error = L_8 ;
V_9 -> V_83 = NULL ;
return V_32 ;
}
V_28 = F_86 ( sizeof( struct V_67 ) , V_84 ) ;
if ( ! V_28 ) {
V_32 = - V_22 ;
goto V_85;
}
V_28 -> V_35 = V_9 -> V_83 -> V_35 ;
( void ) F_87 ( V_28 -> V_35 , V_28 -> V_86 ) ;
if ( F_88 ( V_28 -> V_35 ) == V_87 ) {
V_65 -> error = L_9 ;
V_32 = - V_88 ;
goto V_85;
}
V_28 -> V_89 = F_89 ( V_28 -> V_35 -> V_90 ) >> V_24 ;
if ( V_65 -> V_91 || ( V_65 -> V_92 != V_28 -> V_89 ) ) {
V_65 -> error = L_10 ;
V_32 = - V_88 ;
goto V_85;
}
V_81 = F_90 ( V_28 -> V_35 ) ;
V_28 -> V_74 = V_81 -> V_93 . V_94 ;
V_28 -> V_95 = F_91 ( V_28 -> V_74 ) ;
V_28 -> V_96 = F_92 ( V_28 -> V_74 ) ;
V_28 -> V_97 = F_91 ( V_28 -> V_96 ) ;
V_28 -> V_98 = ( V_28 -> V_89 + V_28 -> V_74 - 1 )
>> V_28 -> V_95 ;
V_9 -> V_28 = V_28 ;
return 0 ;
V_85:
F_93 ( V_65 , V_9 -> V_83 ) ;
F_54 ( V_28 ) ;
return V_32 ;
}
static void F_94 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
F_93 ( V_65 , V_9 -> V_83 ) ;
F_54 ( V_9 -> V_28 ) ;
V_9 -> V_28 = NULL ;
}
static int F_95 ( struct V_64 * V_65 , unsigned int V_99 , char * * V_100 )
{
struct V_8 * V_9 ;
struct V_67 * V_28 ;
int V_32 ;
if ( V_99 != 1 ) {
V_65 -> error = L_11 ;
return - V_88 ;
}
V_9 = F_86 ( sizeof( struct V_8 ) , V_84 ) ;
if ( ! V_9 ) {
V_65 -> error = L_12 ;
return - V_22 ;
}
V_65 -> V_66 = V_9 ;
V_32 = F_83 ( V_65 , V_100 [ 0 ] ) ;
if ( V_32 ) {
V_9 -> V_83 = NULL ;
goto V_85;
}
V_28 = V_9 -> V_28 ;
V_32 = F_96 ( V_28 , & V_9 -> V_16 ) ;
if ( V_32 ) {
V_65 -> error = L_13 ;
goto V_101;
}
V_65 -> V_102 = V_28 -> V_74 << 9 ;
V_65 -> V_103 = 1 ;
V_65 -> V_104 = 1 ;
V_65 -> V_105 = 1 ;
V_65 -> V_106 = sizeof( struct V_3 ) ;
V_65 -> V_107 = true ;
V_65 -> V_108 = true ;
V_65 -> V_109 = true ;
V_65 -> V_92 = ( T_2 ) F_97 ( V_9 -> V_16 ) << V_28 -> V_95 ;
V_9 -> V_21 = F_98 ( V_110 , 0 , 0 ) ;
if ( ! V_9 -> V_21 ) {
V_65 -> error = L_14 ;
V_32 = - V_22 ;
goto V_111;
}
F_99 ( & V_9 -> V_57 ) ;
F_100 ( & V_9 -> V_53 , V_84 ) ;
V_9 -> V_63 = F_101 ( L_15 , V_112 | V_113 ,
0 , V_28 -> V_86 ) ;
if ( ! V_9 -> V_63 ) {
V_65 -> error = L_16 ;
V_32 = - V_22 ;
goto V_114;
}
F_102 ( & V_9 -> V_59 ) ;
F_70 ( & V_9 -> V_60 ) ;
F_103 ( & V_9 -> V_58 , F_60 ) ;
V_9 -> V_61 = F_104 ( L_17 , V_112 ,
V_28 -> V_86 ) ;
if ( ! V_9 -> V_61 ) {
V_65 -> error = L_18 ;
V_32 = - V_22 ;
goto V_115;
}
F_77 ( V_9 -> V_61 , & V_9 -> V_58 , V_62 ) ;
V_32 = F_105 ( V_28 , V_9 -> V_16 , & V_9 -> V_44 ) ;
if ( V_32 ) {
V_65 -> error = L_19 ;
goto V_116;
}
F_106 ( V_28 , L_20 ,
( unsigned long long ) V_65 -> V_92 ,
( unsigned long long ) F_92 ( V_65 -> V_92 ) ) ;
return 0 ;
V_116:
F_107 ( V_9 -> V_61 ) ;
V_115:
F_107 ( V_9 -> V_63 ) ;
V_114:
F_108 ( V_9 -> V_21 ) ;
V_111:
F_109 ( V_9 -> V_16 ) ;
V_101:
F_94 ( V_65 ) ;
V_85:
F_54 ( V_9 ) ;
return V_32 ;
}
static void F_110 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
F_111 ( V_9 -> V_63 ) ;
F_107 ( V_9 -> V_63 ) ;
F_112 ( V_9 -> V_44 ) ;
F_113 ( & V_9 -> V_58 ) ;
F_107 ( V_9 -> V_61 ) ;
( void ) F_61 ( V_9 -> V_16 ) ;
F_109 ( V_9 -> V_16 ) ;
F_108 ( V_9 -> V_21 ) ;
F_94 ( V_65 ) ;
F_54 ( V_9 ) ;
}
static void F_114 ( struct V_64 * V_65 , struct V_117 * V_93 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
unsigned int V_94 = V_9 -> V_28 -> V_74 ;
V_93 -> V_118 = V_119 ;
V_93 -> V_120 = V_119 ;
F_115 ( V_93 , V_119 ) ;
F_116 ( V_93 , V_119 ) ;
V_93 -> V_121 = V_119 ;
V_93 -> V_122 = V_119 ;
V_93 -> V_123 = V_94 ;
V_93 -> V_124 = V_94 ;
V_93 -> V_125 = V_94 ;
V_93 -> V_94 = V_94 ;
V_93 -> V_126 = V_94 ;
V_93 -> V_127 = V_87 ;
}
static int F_117 ( struct V_64 * V_65 ,
struct V_128 * * V_35 , T_3 * V_129 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
* V_35 = V_9 -> V_28 -> V_35 ;
return 0 ;
}
static void F_118 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
F_111 ( V_9 -> V_63 ) ;
F_119 ( V_9 -> V_44 ) ;
F_113 ( & V_9 -> V_58 ) ;
}
static void F_120 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
F_64 ( V_9 -> V_61 , & V_9 -> V_58 , V_62 ) ;
F_121 ( V_9 -> V_44 ) ;
}
static int F_122 ( struct V_64 * V_65 ,
T_4 V_130 , void * V_131 )
{
struct V_8 * V_9 = V_65 -> V_66 ;
return V_130 ( V_65 , V_9 -> V_83 , 0 , V_9 -> V_28 -> V_89 , V_131 ) ;
}
static int T_5 F_123 ( void )
{
return F_124 ( & V_132 ) ;
}
static void T_6 F_125 ( void )
{
F_126 ( & V_132 ) ;
}
