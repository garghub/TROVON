static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
void * V_4 = V_2 -> V_5 -> V_6 ;
V_3 = F_2 ( V_4 , F_3 ( V_2 -> V_5 ) ) ;
if ( V_3 )
goto V_7;
V_2 -> V_8 = F_4 ( NULL , L_1 ) ;
if ( F_5 ( V_2 -> V_8 ) ) {
V_3 = F_6 ( V_2 -> V_8 ) ;
goto V_9;
}
F_7 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_10 , false ) ;
F_9 ( V_2 -> V_11 ) ;
return 0 ;
V_9:
F_10 ( V_4 , F_3 ( V_2 -> V_5 ) ) ;
V_7:
return V_3 ;
}
static void F_11 ( struct V_1 * V_2 )
{
void * V_4 = V_2 -> V_5 -> V_6 ;
if ( V_2 -> V_8 && ! F_5 ( V_2 -> V_8 ) ) {
F_12 ( V_2 -> V_8 ) ;
F_13 ( V_2 -> V_8 ) ;
}
F_10 ( V_4 , F_3 ( V_2 -> V_5 ) ) ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
T_1 V_16 ;
T_2 V_17 ;
struct V_1 * V_2 = F_15 ( V_13 -> V_18 ) ;
T_3 V_19 ;
V_16 = V_13 -> V_16 ;
if ( V_15 && V_15 -> V_16 )
V_16 = V_15 -> V_16 ;
V_17 = 1000 * V_2 -> V_20 / V_2 -> V_21 ;
if ( V_13 -> V_22 )
V_17 = F_16 ( V_17 , V_13 -> V_22 ) ;
if ( V_15 && V_15 -> V_23 )
V_17 = F_16 ( V_17 , V_15 -> V_23 ) ;
if ( V_17 == 0 ) {
F_17 ( & V_13 -> V_24 , L_2 ) ;
return - V_25 ;
}
if ( V_16 != 8 ) {
F_17 ( & V_13 -> V_24 , L_3 ,
V_26 , V_16 ) ;
return - V_25 ;
}
F_18 ( & V_13 -> V_24 , L_4 ,
V_17 , V_2 -> V_20 , V_2 -> V_21 ,
V_2 -> V_20 * 1000 / V_2 -> V_21 ) ;
if ( V_2 -> V_20 * 1000 / V_2 -> V_21 < V_17 ) {
F_17 ( & V_13 -> V_24 , L_5 ,
V_26 , V_17 ) ;
return - V_25 ;
}
V_19 = 1000 * V_2 -> V_20 / V_2 -> V_21 / V_17 ;
F_19 ( F_20 ( V_2 -> V_21 , V_27 ) |
F_20 ( V_19 - 1 , V_28 ) ,
V_29 + V_2 -> V_10 ) ;
F_19 ( F_20 ( 1 , V_30 ) |
F_20 ( 4 , V_31 ) |
( ( V_13 -> V_32 & V_33 ) ? V_34 : 0 ) |
( ( V_13 -> V_32 & V_35 ) ? V_36 : 0 ) |
( V_37 ? 0 : V_38 ) ,
V_2 -> V_10 + V_39 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
if ( V_13 -> V_16 != 8 ) {
F_17 ( & V_13 -> V_24 , L_3 ,
V_26 , V_13 -> V_16 ) ;
return - V_25 ;
}
return 0 ;
}
static inline T_2 F_22 ( unsigned V_40 )
{
return ( ( V_40 & 1 ) ? V_41 : 0 ) |
( ( V_40 & 2 ) ? V_42 : 0 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_40 ,
unsigned char * V_43 , T_4 V_44 , int V_45 ,
int V_46 , int V_47 , bool V_48 )
{
T_2 V_49 = 0 ;
T_4 V_50 = V_44 ;
int V_51 = 0 ;
enum V_52 V_53 = V_48 ? V_54 : V_55 ;
V_49 |= ( V_46 ? V_56 : 0 ) ;
V_49 |= ( V_47 ? V_57 : 0 ) ;
V_49 |= ( V_48 ? 0 : V_58 ) ;
V_49 |= V_59 ;
V_49 |= F_22 ( V_40 ) ;
V_49 |= F_20 ( V_45 , V_60 ) ;
if ( ! V_44 )
V_50 = F_24 ( V_2 -> V_5 , V_43 , V_45 , V_53 ) ;
V_2 -> V_61 . V_62 -> V_63 =
F_20 ( V_45 , V_64 ) |
F_20 ( 1 , V_65 ) |
V_66 |
V_67 |
F_20 ( V_48 ? V_68 :
V_69 ,
V_70 ) ;
V_2 -> V_61 . V_62 -> V_71 [ 0 ] = V_49 ;
V_2 -> V_61 . V_62 -> V_72 = V_50 ;
F_9 ( V_2 -> V_11 ) ;
F_25 ( V_2 -> V_11 ) ;
F_26 ( V_2 -> V_11 ) ;
F_27 ( & V_2 -> V_73 ) ;
F_28 ( V_2 -> V_11 , & V_2 -> V_61 , 1 ) ;
F_29 ( & V_2 -> V_73 ) ;
if ( ! F_30 ( F_31 ( V_2 -> V_10 + V_74 ) & V_75 ) )
V_51 = - V_76 ;
if ( ! V_44 )
F_32 ( V_2 -> V_5 , V_50 , V_45 , V_53 ) ;
return V_51 ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_56 , V_2 -> V_10 + V_74 ) ;
F_35 ( V_57 , V_2 -> V_10 + V_74 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
F_35 ( V_56 , V_2 -> V_10 + V_74 ) ;
F_34 ( V_57 , V_2 -> V_10 + V_74 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_40 ,
unsigned char * V_43 , int V_45 ,
bool V_46 , bool V_47 , bool V_48 )
{
if ( V_46 )
F_33 ( V_2 ) ;
F_34 ( F_22 ( V_40 ) , V_2 -> V_10 + V_74 ) ;
while ( V_45 -- ) {
if ( V_47 && V_45 <= 0 )
F_36 ( V_2 ) ;
F_35 ( V_77 ,
V_2 -> V_10 + V_74 ) ;
F_34 ( 1 , V_2 -> V_10 + V_74 ) ;
if ( V_48 )
F_35 ( V_58 ,
V_2 -> V_10 + V_74 ) ;
else
F_34 ( V_58 ,
V_2 -> V_10 + V_74 ) ;
F_34 ( V_75 , V_2 -> V_10 + V_74 ) ;
if ( ! F_30 ( F_31 ( V_2 -> V_10 + V_74 ) &
V_75 ) )
break;
if ( V_48 )
F_19 ( * V_43 , V_2 -> V_10 + V_78 ) ;
F_34 ( V_59 , V_2 -> V_10 + V_74 ) ;
if ( ! V_48 ) {
if ( F_30 ( ( F_31 ( V_2 -> V_10 + V_79 ) &
V_80 ) ) )
break;
* V_43 = F_31 ( V_2 -> V_10 + V_78 ) & 0xFF ;
}
if ( ! F_30 ( F_31 ( V_2 -> V_10 + V_74 ) &
V_75 ) )
break;
V_43 ++ ;
}
return V_45 < 0 ? 0 : - V_76 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
bool V_46 , V_47 ;
struct V_14 * V_15 , * V_83 ;
int V_51 = 0 ;
int V_40 ;
V_40 = V_82 -> V_13 -> V_84 ;
F_39 (t, tmp_t, &m->transfers, transfer_list) {
V_46 = ( & V_15 -> V_85 == V_82 -> V_86 . V_87 ) ;
V_47 = ( & V_15 -> V_85 == V_82 -> V_86 . V_88 ) ;
if ( V_46 || V_15 -> V_23 || V_15 -> V_16 )
F_14 ( V_82 -> V_13 , V_15 ) ;
if ( V_15 -> V_89 && ! V_47 ) {
F_17 ( & V_82 -> V_13 -> V_24 ,
L_6 ) ;
continue;
}
if ( V_15 -> V_90 ) {
V_51 = V_37 ?
F_37 ( V_2 , V_40 , ( void * ) V_15 -> V_90 ,
V_15 -> V_45 , V_46 , V_47 , true ) :
F_23 ( V_2 , V_40 , ( void * ) V_15 -> V_90 ,
V_15 -> V_91 , V_15 -> V_45 , V_46 , V_47 , true ) ;
#ifdef F_40
if ( V_15 -> V_45 < 0x10 )
F_41 ( L_7 ,
V_92 ,
V_15 -> V_90 , V_15 -> V_45 ) ;
else
F_42 ( L_8 , V_15 -> V_45 ) ;
#endif
}
if ( V_15 -> V_93 ) {
V_51 = V_37 ?
F_37 ( V_2 , V_40 , V_15 -> V_93 ,
V_15 -> V_45 , V_46 , V_47 , false ) :
F_23 ( V_2 , V_40 , V_15 -> V_93 ,
V_15 -> V_94 , V_15 -> V_45 , V_46 , V_47 , false ) ;
#ifdef F_40
if ( V_15 -> V_45 < 0x10 )
F_41 ( L_9 ,
V_92 ,
V_15 -> V_93 , V_15 -> V_45 ) ;
else
F_42 ( L_10 , V_15 -> V_45 ) ;
#endif
}
if ( V_15 -> V_95 )
F_43 ( V_15 -> V_95 ) ;
if ( V_51 )
break;
}
return V_51 ;
}
static void F_44 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_45 ( V_97 , struct V_1 , V_98 ) ;
unsigned long V_99 ;
struct V_81 * V_82 ;
F_46 ( & V_2 -> V_100 , V_99 ) ;
while ( ! F_47 ( & V_2 -> V_101 ) ) {
V_82 = F_48 ( V_2 -> V_101 . V_87 , struct V_81 , V_101 ) ;
F_49 ( & V_82 -> V_101 ) ;
F_50 ( & V_2 -> V_100 , V_99 ) ;
V_82 -> V_51 = F_38 ( V_2 , V_82 ) ;
V_82 -> V_102 ( V_82 -> V_103 ) ;
F_46 ( & V_2 -> V_100 , V_99 ) ;
}
F_50 ( & V_2 -> V_100 , V_99 ) ;
return;
}
static int F_51 ( struct V_12 * V_13 , struct V_81 * V_82 )
{
struct V_1 * V_2 = F_15 ( V_13 -> V_18 ) ;
unsigned long V_99 ;
V_82 -> V_51 = - V_104 ;
F_46 ( & V_2 -> V_100 , V_99 ) ;
F_52 ( & V_82 -> V_101 , & V_2 -> V_101 ) ;
F_53 ( V_2 -> V_105 , & V_2 -> V_98 ) ;
F_50 ( & V_2 -> V_100 , V_99 ) ;
return 0 ;
}
static T_5 F_54 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
F_25 ( V_2 -> V_11 ) ;
V_102 ( & V_2 -> V_73 ) ;
return V_108 ;
}
static T_5 F_55 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
T_2 V_109 , V_110 ;
V_109 = F_31 ( V_2 -> V_10 + V_39 ) ;
V_110 = F_31 ( V_2 -> V_10 + V_79 ) ;
F_17 ( V_2 -> V_5 , L_11 ,
V_26 , V_110 , V_109 ) ;
F_35 ( V_109 & 0xCCCC0000 , V_2 -> V_10 + V_39 ) ;
return V_108 ;
}
static int T_6 F_56 ( struct V_111 * V_24 )
{
int V_3 = 0 ;
struct V_112 * V_18 ;
struct V_1 * V_2 ;
struct V_113 * V_114 ;
V_18 = F_57 ( & V_24 -> V_24 , sizeof( struct V_1 ) ) ;
if ( V_18 == NULL ) {
V_3 = - V_115 ;
goto V_116;
}
V_18 -> V_99 = V_117 ;
V_2 = F_15 ( V_18 ) ;
F_58 ( V_24 , V_18 ) ;
V_114 = F_59 ( V_24 , V_118 , 0 ) ;
if ( V_114 == NULL ) {
V_3 = - V_119 ;
goto V_120;
}
V_2 -> V_10 = F_60 ( V_114 -> V_121 , F_61 ( V_114 ) ) ;
if ( ! V_2 -> V_10 ) {
V_3 = - V_25 ;
goto V_120;
}
V_2 -> V_5 = & V_24 -> V_24 ;
V_2 -> V_122 = V_24 -> V_122 ;
F_62 ( & V_2 -> V_98 , F_44 ) ;
F_63 ( & V_2 -> V_101 ) ;
F_64 ( & V_2 -> V_100 ) ;
V_2 -> V_105 = F_65 ( F_3 ( & V_24 -> V_24 ) ) ;
if ( ! V_2 -> V_105 ) {
V_3 = - V_123 ;
goto V_120;
}
V_18 -> V_124 = F_51 ;
V_18 -> V_125 = F_21 ;
V_18 -> V_126 = V_33 | V_35 ;
V_2 -> V_106 = F_66 ( V_24 , 0 ) ;
if ( V_2 -> V_106 < 0 ) {
V_3 = V_2 -> V_106 ;
goto V_120;
}
V_2 -> V_127 = F_66 ( V_24 , 1 ) ;
if ( V_2 -> V_127 < 0 ) {
V_3 = V_2 -> V_127 ;
goto V_120;
}
V_114 = F_59 ( V_24 , V_128 , 0 ) ;
if ( V_114 == NULL ) {
V_3 = - V_119 ;
goto V_120;
}
V_2 -> V_11 = V_114 -> V_121 ;
V_3 = F_67 ( V_2 -> V_11 , & V_24 -> V_24 , F_3 ( & V_24 -> V_24 ) ) ;
if ( V_3 )
goto V_120;
V_3 = F_68 ( V_2 -> V_11 , & V_2 -> V_61 ) ;
if ( V_3 )
goto V_129;
V_18 -> V_130 = V_24 -> V_122 ;
V_18 -> V_131 = 1 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_18 ( & V_24 -> V_24 , L_12 ) ;
goto V_132;
}
if ( clock ) {
F_69 ( & V_24 -> V_24 , L_13 , clock ) ;
F_70 ( V_2 -> V_8 , clock ) ;
}
V_2 -> V_20 = F_71 ( V_2 -> V_8 ) ;
V_2 -> V_21 = 2 ;
F_69 ( & V_24 -> V_24 , L_14 ,
V_2 -> V_20 , F_71 ( V_2 -> V_8 ) , V_2 -> V_21 ) ;
V_3 = F_72 ( V_2 -> V_106 , F_54 , 0 ,
F_3 ( & V_24 -> V_24 ) , V_2 ) ;
if ( V_3 ) {
F_18 ( & V_24 -> V_24 , L_15 , V_3 ) ;
goto V_133;
}
V_3 = F_72 ( V_2 -> V_127 , F_55 , V_134 ,
F_3 ( & V_24 -> V_24 ) , V_2 ) ;
if ( V_3 ) {
F_18 ( & V_24 -> V_24 , L_16 , V_3 ) ;
goto V_135;
}
V_3 = F_73 ( V_18 ) ;
if ( V_3 ) {
F_18 ( & V_24 -> V_24 , L_17 , V_3 ) ;
goto V_136;
}
F_69 ( & V_24 -> V_24 , L_18 ,
( T_2 ) V_2 -> V_10 , V_2 -> V_106 , V_18 -> V_130 ,
V_37 ? L_19 : L_20 ) ;
return 0 ;
V_136:
F_74 ( V_2 -> V_127 , V_2 ) ;
V_135:
F_74 ( V_2 -> V_106 , V_2 ) ;
V_132:
F_75 ( V_2 -> V_11 , & V_2 -> V_61 ) ;
V_129:
F_76 ( V_2 -> V_11 ) ;
V_133:
F_11 ( V_2 ) ;
V_120:
if ( V_2 -> V_105 )
F_77 ( V_2 -> V_105 ) ;
if ( V_2 -> V_10 )
F_78 ( V_2 -> V_10 ) ;
F_58 ( V_24 , NULL ) ;
F_79 ( V_18 ) ;
V_116:
return V_3 ;
}
static int T_7 F_80 ( struct V_111 * V_24 )
{
struct V_1 * V_2 ;
struct V_112 * V_18 ;
V_18 = F_81 ( V_24 ) ;
if ( V_18 == NULL )
goto V_116;
V_2 = F_15 ( V_18 ) ;
F_82 ( V_18 ) ;
F_74 ( V_2 -> V_127 , V_2 ) ;
F_74 ( V_2 -> V_106 , V_2 ) ;
F_75 ( V_2 -> V_11 , & V_2 -> V_61 ) ;
F_76 ( V_2 -> V_11 ) ;
F_11 ( V_2 ) ;
F_77 ( V_2 -> V_105 ) ;
F_78 ( V_2 -> V_10 ) ;
F_79 ( V_18 ) ;
F_58 ( V_24 , NULL ) ;
V_116:
return 0 ;
}
static int F_83 ( struct V_111 * V_137 , T_8 V_138 )
{
struct V_1 * V_2 ;
struct V_112 * V_18 ;
V_18 = F_81 ( V_137 ) ;
V_2 = F_15 ( V_18 ) ;
V_2 -> V_139 = F_31 ( V_29 + V_2 -> V_10 ) ;
F_12 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_111 * V_137 )
{
struct V_1 * V_2 ;
struct V_112 * V_18 ;
V_18 = F_81 ( V_137 ) ;
V_2 = F_15 ( V_18 ) ;
F_7 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_10 , false ) ;
F_19 ( V_2 -> V_139 , V_2 -> V_10 + V_29 ) ;
return 0 ;
}
static int T_9 F_85 ( void )
{
return F_86 ( & V_140 ) ;
}
static void T_10 F_87 ( void )
{
F_88 ( & V_140 ) ;
}
