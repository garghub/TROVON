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
F_27 ( V_1 , V_9 -> V_28 -> V_34 ) ;
V_1 -> V_17 . V_18 = F_7 ( V_9 -> V_16 , V_11 ) + F_8 ( V_12 ) ;
F_10 ( & V_4 -> V_19 ) ;
F_11 ( V_1 ) ;
if ( F_28 ( V_11 ) )
V_11 -> V_33 += V_13 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_1 * V_1 ,
T_2 V_12 ,
unsigned int V_13 )
{
struct V_35 * V_36 = V_9 -> V_16 ;
struct V_10 * V_31 = V_11 -> V_31 ;
int V_32 ;
if ( F_30 ( V_11 ) )
return - V_37 ;
F_26 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
V_32 = F_31 ( V_36 , V_11 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_31 )
V_32 = F_32 ( V_36 , V_31 , V_12 , V_13 ) ;
return V_32 ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_1 * V_1 ,
T_2 V_12 ,
unsigned int V_13 )
{
struct V_35 * V_36 = V_9 -> V_16 ;
struct V_10 * V_31 ;
int V_32 ;
V_31 = F_34 ( V_36 , V_11 ) ;
if ( ! V_31 )
return - V_38 ;
if ( F_30 ( V_31 ) )
return - V_37 ;
F_26 ( V_9 , V_31 , V_1 , V_12 , V_13 ) ;
V_32 = F_31 ( V_36 , V_31 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_12 < V_11 -> V_33 )
V_32 = F_32 ( V_36 , V_11 , V_12 , V_13 ) ;
return V_32 ;
}
static int F_35 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 )
{
T_2 V_12 = F_18 ( V_9 -> V_28 , F_19 ( V_1 ) ) ;
unsigned int V_13 = F_9 ( V_1 ) ;
if ( ! V_11 )
return - V_38 ;
F_20 ( V_9 -> V_28 , L_4 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
( F_22 ( V_11 ) ? L_2 : L_3 ) ,
F_23 ( V_9 -> V_16 , V_11 ) ,
( unsigned long long ) V_12 , V_13 ) ;
if ( F_22 ( V_11 ) || V_12 == V_11 -> V_33 ) {
return F_29 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
}
return F_33 ( V_9 , V_11 , V_1 , V_12 , V_13 ) ;
}
static int F_36 ( struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_1 * V_1 )
{
struct V_35 * V_36 = V_9 -> V_16 ;
T_2 V_39 = F_19 ( V_1 ) ;
unsigned int V_13 = F_9 ( V_1 ) ;
T_2 V_12 = F_18 ( V_9 -> V_28 , V_39 ) ;
int V_32 = 0 ;
if ( ! V_11 )
return 0 ;
if ( F_30 ( V_11 ) )
return - V_37 ;
F_20 ( V_9 -> V_28 , L_5 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
F_23 ( V_36 , V_11 ) ,
( unsigned long long ) V_12 , V_13 ) ;
if ( F_22 ( V_11 ) || V_12 < V_11 -> V_33 )
V_32 = F_32 ( V_36 , V_11 , V_12 , V_13 ) ;
if ( V_32 == 0 && V_11 -> V_31 )
V_32 = F_32 ( V_36 , V_11 -> V_31 ,
V_12 , V_13 ) ;
return V_32 ;
}
static void F_37 ( struct V_8 * V_9 , struct V_40 * V_41 ,
struct V_1 * V_1 )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
struct V_35 * V_36 = V_9 -> V_16 ;
struct V_10 * V_11 ;
int V_32 ;
if ( F_38 ( V_1 ) == V_42 )
F_39 ( V_9 -> V_43 ) ;
F_40 ( V_36 ) ;
V_11 = F_41 ( V_36 , F_21 ( V_9 -> V_28 , V_1 ) ,
F_38 ( V_1 ) ) ;
if ( F_42 ( V_11 ) ) {
V_32 = F_43 ( V_11 ) ;
goto V_44;
}
if ( V_11 ) {
F_44 ( V_11 ) ;
V_4 -> V_11 = V_11 ;
}
switch ( F_38 ( V_1 ) ) {
case V_45 :
V_32 = F_17 ( V_9 , V_11 , V_1 ) ;
break;
case V_42 :
V_32 = F_35 ( V_9 , V_11 , V_1 ) ;
break;
case V_46 :
case V_47 :
V_32 = F_36 ( V_9 , V_11 , V_1 ) ;
break;
default:
F_45 ( V_9 -> V_28 , L_6 ,
F_38 ( V_1 ) ) ;
V_32 = - V_48 ;
}
if ( V_11 )
F_46 ( V_36 , V_11 ) ;
V_44:
F_1 ( V_1 , F_47 ( V_32 ) ) ;
F_48 ( V_36 ) ;
}
static inline void F_49 ( struct V_40 * V_41 )
{
F_10 ( & V_41 -> V_49 ) ;
}
static void F_50 ( struct V_40 * V_41 )
{
if ( F_51 ( & V_41 -> V_49 ) ) {
F_52 ( ! F_53 ( & V_41 -> V_50 ) ) ;
F_54 ( & V_41 -> V_51 -> V_52 , V_41 -> V_53 ) ;
F_55 ( V_41 ) ;
}
}
static void F_56 ( struct V_54 * V_55 )
{
struct V_40 * V_41 = F_57 ( V_55 , struct V_40 , V_55 ) ;
struct V_8 * V_9 = V_41 -> V_51 ;
struct V_1 * V_1 ;
F_58 ( & V_9 -> V_56 ) ;
while ( ( V_1 = F_59 ( & V_41 -> V_50 ) ) ) {
F_60 ( & V_9 -> V_56 ) ;
F_37 ( V_9 , V_41 , V_1 ) ;
F_58 ( & V_9 -> V_56 ) ;
F_50 ( V_41 ) ;
}
F_50 ( V_41 ) ;
F_60 ( & V_9 -> V_56 ) ;
}
static void F_61 ( struct V_54 * V_55 )
{
struct V_8 * V_9 = F_57 ( V_55 , struct V_8 , V_57 . V_55 ) ;
struct V_1 * V_1 ;
int V_32 ;
V_32 = F_62 ( V_9 -> V_16 ) ;
while ( 1 ) {
F_63 ( & V_9 -> V_58 ) ;
V_1 = F_59 ( & V_9 -> V_59 ) ;
F_64 ( & V_9 -> V_58 ) ;
if ( ! V_1 )
break;
F_1 ( V_1 , F_47 ( V_32 ) ) ;
}
F_65 ( V_9 -> V_60 , & V_9 -> V_57 , V_61 ) ;
}
static void F_66 ( struct V_8 * V_9 , struct V_1 * V_1 )
{
unsigned int V_53 = F_21 ( V_9 -> V_28 , V_1 ) ;
struct V_40 * V_41 ;
F_58 ( & V_9 -> V_56 ) ;
V_41 = F_67 ( & V_9 -> V_52 , V_53 ) ;
if ( ! V_41 ) {
int V_32 ;
V_41 = F_68 ( sizeof( struct V_40 ) , V_20 ) ;
if ( ! V_41 )
goto V_44;
F_69 ( & V_41 -> V_55 , F_56 ) ;
F_70 ( & V_41 -> V_49 , 0 ) ;
V_41 -> V_51 = V_9 ;
V_41 -> V_53 = V_53 ;
F_71 ( & V_41 -> V_50 ) ;
V_32 = F_72 ( & V_9 -> V_52 , V_53 , V_41 ) ;
if ( F_73 ( V_32 ) ) {
F_55 ( V_41 ) ;
V_41 = NULL ;
goto V_44;
}
}
F_74 ( & V_41 -> V_50 , V_1 ) ;
F_49 ( V_41 ) ;
if ( F_75 ( V_9 -> V_62 , & V_41 -> V_55 ) )
F_49 ( V_41 ) ;
V_44:
F_60 ( & V_9 -> V_56 ) ;
}
static int F_76 ( struct V_63 * V_64 , struct V_1 * V_1 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
struct V_66 * V_28 = V_9 -> V_28 ;
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
T_2 V_14 = V_1 -> V_17 . V_18 ;
unsigned int V_67 = F_77 ( V_1 ) ;
T_2 V_68 ;
F_20 ( V_28 , L_7 ,
F_38 ( V_1 ) , ( unsigned long long ) V_14 , V_67 ,
( unsigned long long ) F_21 ( V_9 -> V_28 , V_1 ) ,
( unsigned long long ) F_18 ( V_9 -> V_28 , F_19 ( V_1 ) ) ,
( unsigned int ) F_9 ( V_1 ) ) ;
F_27 ( V_1 , V_28 -> V_34 ) ;
if ( ! V_67 && F_38 ( V_1 ) != V_42 )
return V_69 ;
if ( ( V_67 & V_70 ) || ( V_14 & V_70 ) )
return V_71 ;
V_4 -> V_51 = V_9 ;
V_4 -> V_11 = NULL ;
V_4 -> V_1 = V_1 ;
F_70 ( & V_4 -> V_19 , 1 ) ;
V_4 -> V_2 = V_5 ;
if ( ! V_67 && F_38 ( V_1 ) == V_42 ) {
F_63 ( & V_9 -> V_58 ) ;
F_74 ( & V_9 -> V_59 , V_1 ) ;
F_64 ( & V_9 -> V_58 ) ;
F_78 ( V_9 -> V_60 , & V_9 -> V_57 , 0 ) ;
return V_72 ;
}
V_68 = V_14 & ( V_28 -> V_73 - 1 ) ;
if ( V_68 + V_67 > V_28 -> V_73 )
F_79 ( V_1 , V_28 -> V_73 - V_68 ) ;
F_80 ( V_9 -> V_43 ) ;
F_66 ( V_9 , V_1 ) ;
return V_72 ;
}
static int F_81 ( struct V_63 * V_64 , struct V_1 * V_1 , T_1 * error )
{
struct V_3 * V_4 = F_2 ( V_1 , sizeof( struct V_3 ) ) ;
if ( V_4 -> V_2 == V_5 && * error )
V_4 -> V_2 = * error ;
if ( ! F_51 ( & V_4 -> V_19 ) )
return V_74 ;
V_1 -> V_7 = V_4 -> V_2 ;
if ( V_4 -> V_11 ) {
struct V_10 * V_11 = V_4 -> V_11 ;
if ( * error && F_38 ( V_1 ) == V_42 ) {
if ( F_28 ( V_11 ) )
F_82 ( V_75 , & V_11 -> V_76 ) ;
}
F_83 ( V_11 ) ;
}
return V_77 ;
}
static int F_84 ( struct V_63 * V_64 , char * V_78 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
struct V_79 * V_80 ;
struct V_66 * V_28 ;
int V_32 ;
V_32 = F_85 ( V_64 , V_78 , F_86 ( V_64 -> V_81 ) , & V_9 -> V_82 ) ;
if ( V_32 ) {
V_64 -> error = L_8 ;
V_9 -> V_82 = NULL ;
return V_32 ;
}
V_28 = F_87 ( sizeof( struct V_66 ) , V_83 ) ;
if ( ! V_28 ) {
V_32 = - V_22 ;
goto V_84;
}
V_28 -> V_34 = V_9 -> V_82 -> V_34 ;
( void ) F_88 ( V_28 -> V_34 , V_28 -> V_85 ) ;
if ( F_89 ( V_28 -> V_34 ) == V_86 ) {
V_64 -> error = L_9 ;
V_32 = - V_87 ;
goto V_84;
}
V_28 -> V_88 = F_90 ( V_28 -> V_34 -> V_89 ) >> V_24 ;
if ( V_64 -> V_90 || ( V_64 -> V_91 != V_28 -> V_88 ) ) {
V_64 -> error = L_10 ;
V_32 = - V_87 ;
goto V_84;
}
V_80 = F_91 ( V_28 -> V_34 ) ;
V_28 -> V_73 = V_80 -> V_92 . V_93 ;
V_28 -> V_94 = F_92 ( V_28 -> V_73 ) ;
V_28 -> V_95 = F_93 ( V_28 -> V_73 ) ;
V_28 -> V_96 = F_92 ( V_28 -> V_95 ) ;
V_28 -> V_97 = ( V_28 -> V_88 + V_28 -> V_73 - 1 )
>> V_28 -> V_94 ;
V_9 -> V_28 = V_28 ;
return 0 ;
V_84:
F_94 ( V_64 , V_9 -> V_82 ) ;
F_55 ( V_28 ) ;
return V_32 ;
}
static void F_95 ( struct V_63 * V_64 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
F_94 ( V_64 , V_9 -> V_82 ) ;
F_55 ( V_9 -> V_28 ) ;
V_9 -> V_28 = NULL ;
}
static int F_96 ( struct V_63 * V_64 , unsigned int V_98 , char * * V_99 )
{
struct V_8 * V_9 ;
struct V_66 * V_28 ;
int V_32 ;
if ( V_98 != 1 ) {
V_64 -> error = L_11 ;
return - V_87 ;
}
V_9 = F_87 ( sizeof( struct V_8 ) , V_83 ) ;
if ( ! V_9 ) {
V_64 -> error = L_12 ;
return - V_22 ;
}
V_64 -> V_65 = V_9 ;
V_32 = F_84 ( V_64 , V_99 [ 0 ] ) ;
if ( V_32 ) {
V_9 -> V_82 = NULL ;
goto V_84;
}
V_28 = V_9 -> V_28 ;
V_32 = F_97 ( V_28 , & V_9 -> V_16 ) ;
if ( V_32 ) {
V_64 -> error = L_13 ;
goto V_100;
}
V_64 -> V_101 = V_28 -> V_73 << 9 ;
V_64 -> V_102 = 1 ;
V_64 -> V_103 = 1 ;
V_64 -> V_104 = 1 ;
V_64 -> V_105 = sizeof( struct V_3 ) ;
V_64 -> V_106 = true ;
V_64 -> V_107 = true ;
V_64 -> V_108 = true ;
V_64 -> V_91 = ( T_2 ) F_98 ( V_9 -> V_16 ) << V_28 -> V_94 ;
V_9 -> V_21 = F_99 ( V_109 , 0 , 0 ) ;
if ( ! V_9 -> V_21 ) {
V_64 -> error = L_14 ;
V_32 = - V_22 ;
goto V_110;
}
F_100 ( & V_9 -> V_56 ) ;
F_101 ( & V_9 -> V_52 , V_83 ) ;
V_9 -> V_62 = F_102 ( L_15 , V_111 | V_112 ,
0 , V_28 -> V_85 ) ;
if ( ! V_9 -> V_62 ) {
V_64 -> error = L_16 ;
V_32 = - V_22 ;
goto V_113;
}
F_103 ( & V_9 -> V_58 ) ;
F_71 ( & V_9 -> V_59 ) ;
F_104 ( & V_9 -> V_57 , F_61 ) ;
V_9 -> V_60 = F_105 ( L_17 , V_111 ,
V_28 -> V_85 ) ;
if ( ! V_9 -> V_60 ) {
V_64 -> error = L_18 ;
V_32 = - V_22 ;
goto V_114;
}
F_78 ( V_9 -> V_60 , & V_9 -> V_57 , V_61 ) ;
V_32 = F_106 ( V_28 , V_9 -> V_16 , & V_9 -> V_43 ) ;
if ( V_32 ) {
V_64 -> error = L_19 ;
goto V_115;
}
F_107 ( V_28 , L_20 ,
( unsigned long long ) V_64 -> V_91 ,
( unsigned long long ) F_93 ( V_64 -> V_91 ) ) ;
return 0 ;
V_115:
F_108 ( V_9 -> V_60 ) ;
V_114:
F_108 ( V_9 -> V_62 ) ;
V_113:
F_109 ( V_9 -> V_21 ) ;
V_110:
F_110 ( V_9 -> V_16 ) ;
V_100:
F_95 ( V_64 ) ;
V_84:
F_55 ( V_9 ) ;
return V_32 ;
}
static void F_111 ( struct V_63 * V_64 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
F_112 ( V_9 -> V_62 ) ;
F_108 ( V_9 -> V_62 ) ;
F_113 ( V_9 -> V_43 ) ;
F_114 ( & V_9 -> V_57 ) ;
F_108 ( V_9 -> V_60 ) ;
( void ) F_62 ( V_9 -> V_16 ) ;
F_110 ( V_9 -> V_16 ) ;
F_109 ( V_9 -> V_21 ) ;
F_95 ( V_64 ) ;
F_55 ( V_9 ) ;
}
static void F_115 ( struct V_63 * V_64 , struct V_116 * V_92 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
unsigned int V_93 = V_9 -> V_28 -> V_73 ;
V_92 -> V_117 = V_118 ;
V_92 -> V_119 = V_118 ;
F_116 ( V_92 , V_118 ) ;
F_117 ( V_92 , V_118 ) ;
V_92 -> V_120 = V_118 ;
V_92 -> V_121 = V_118 ;
V_92 -> V_122 = V_93 ;
V_92 -> V_123 = V_93 ;
V_92 -> V_124 = V_93 ;
V_92 -> V_93 = V_93 ;
V_92 -> V_125 = V_93 ;
V_92 -> V_126 = V_86 ;
}
static int F_118 ( struct V_63 * V_64 ,
struct V_127 * * V_34 , T_3 * V_128 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
* V_34 = V_9 -> V_28 -> V_34 ;
return 0 ;
}
static void F_119 ( struct V_63 * V_64 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
F_112 ( V_9 -> V_62 ) ;
F_120 ( V_9 -> V_43 ) ;
F_114 ( & V_9 -> V_57 ) ;
}
static void F_121 ( struct V_63 * V_64 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
F_65 ( V_9 -> V_60 , & V_9 -> V_57 , V_61 ) ;
F_122 ( V_9 -> V_43 ) ;
}
static int F_123 ( struct V_63 * V_64 ,
T_4 V_129 , void * V_130 )
{
struct V_8 * V_9 = V_64 -> V_65 ;
return V_129 ( V_64 , V_9 -> V_82 , 0 , V_9 -> V_28 -> V_88 , V_130 ) ;
}
static int T_5 F_124 ( void )
{
return F_125 ( & V_131 ) ;
}
static void T_6 F_126 ( void )
{
F_127 ( & V_131 ) ;
}
