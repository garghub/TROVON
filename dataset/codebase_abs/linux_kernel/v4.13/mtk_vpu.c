static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 . V_6 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 . V_6 + V_4 ) ;
}
static inline bool F_5 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_7 ) & F_6 ( 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_8 ) ;
if ( ! -- V_2 -> V_9 )
F_1 ( V_2 ,
F_3 ( V_2 , V_10 ) & ~ ( 1L << 31 ) ,
V_10 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_10 ( V_2 -> V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_12 ( V_2 -> V_11 ) ;
if ( V_12 )
return V_12 ;
F_8 ( & V_2 -> V_8 ) ;
if ( ! V_2 -> V_9 ++ )
F_1 ( V_2 ,
F_3 ( V_2 , V_10 ) | ( 1L << 31 ) ,
V_10 ) ;
F_9 ( & V_2 -> V_8 ) ;
return V_12 ;
}
int F_13 ( struct V_13 * V_14 ,
enum V_15 V_16 , T_2 V_17 ,
const char * V_18 , void * V_19 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_20 * V_21 ;
if ( ! V_2 ) {
F_15 ( & V_14 -> V_22 , L_1 ) ;
return - V_23 ;
}
if ( V_16 >= 0 && V_16 < V_24 && V_17 ) {
V_21 = V_2 -> V_21 ;
V_21 [ V_16 ] . V_18 = V_18 ;
V_21 [ V_16 ] . V_17 = V_17 ;
V_21 [ V_16 ] . V_19 = V_19 ;
return 0 ;
}
F_15 ( & V_14 -> V_22 , L_2 ,
V_16 ) ;
return - V_25 ;
}
int F_16 ( struct V_13 * V_14 ,
enum V_15 V_16 , void * V_26 ,
unsigned int V_27 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_28 * V_29 = V_2 -> V_30 ;
unsigned long V_31 ;
int V_12 = 0 ;
if ( V_16 <= V_32 || V_16 >= V_24 ||
V_27 > sizeof( V_29 -> V_33 ) || ! V_26 ) {
F_15 ( V_2 -> V_22 , L_3 ) ;
return - V_25 ;
}
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_4 ) ;
return V_12 ;
}
if ( ! F_5 ( V_2 ) ) {
F_15 ( V_2 -> V_22 , L_5 ) ;
V_12 = - V_25 ;
goto V_34;
}
F_8 ( & V_2 -> V_8 ) ;
V_31 = V_35 + F_17 ( V_36 ) ;
do {
if ( F_18 ( V_35 , V_31 ) ) {
F_15 ( V_2 -> V_22 , L_6 ) ;
V_12 = - V_37 ;
goto V_38;
}
} while ( F_3 ( V_2 , V_39 ) );
memcpy ( ( void * ) V_29 -> V_33 , V_26 , V_27 ) ;
V_29 -> V_27 = V_27 ;
V_29 -> V_16 = V_16 ;
V_2 -> V_40 [ V_16 ] = false ;
F_1 ( V_2 , 0x1 , V_39 ) ;
F_9 ( & V_2 -> V_8 ) ;
V_31 = F_17 ( V_36 ) ;
V_12 = F_19 ( V_2 -> V_41 , V_2 -> V_40 [ V_16 ] , V_31 ) ;
V_2 -> V_40 [ V_16 ] = false ;
if ( V_12 == 0 ) {
F_15 ( V_2 -> V_22 , L_7 , V_16 ) ;
V_12 = - V_37 ;
goto V_34;
}
F_7 ( V_2 ) ;
return 0 ;
V_38:
F_9 ( & V_2 -> V_8 ) ;
V_34:
F_7 ( V_2 ) ;
return V_12 ;
}
static void F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_21 ( V_43 , struct V_44 , V_43 ) ;
struct V_1 * V_2 = F_21 ( V_45 , struct V_1 , V_45 ) ;
struct V_46 * V_17 = V_45 -> V_17 ;
int V_47 , V_12 ;
F_22 ( V_2 -> V_22 , L_8 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_9 , V_12 ) ;
return;
}
F_8 ( & V_2 -> V_8 ) ;
F_1 ( V_2 , 0x0 , V_7 ) ;
V_2 -> V_48 = false ;
F_9 ( & V_2 -> V_8 ) ;
F_7 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_49 ; V_47 ++ ) {
if ( V_17 [ V_47 ] . V_50 ) {
V_17 [ V_47 ] . V_50 ( V_17 [ V_47 ] . V_19 ) ;
F_23 ( V_2 -> V_22 , L_10 , V_47 ) ;
}
}
}
int F_24 ( struct V_13 * V_14 ,
void F_25 ( void * ) ,
void * V_19 , enum V_51 V_16 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_46 * V_17 ;
if ( ! V_2 ) {
F_15 ( & V_14 -> V_22 , L_1 ) ;
return - V_23 ;
}
V_17 = V_2 -> V_45 . V_17 ;
if ( V_16 >= 0 && V_16 < V_49 && F_25 ) {
F_23 ( V_2 -> V_22 , L_11 , V_16 ) ;
F_8 ( & V_2 -> V_8 ) ;
V_17 [ V_16 ] . V_50 = F_25 ;
V_17 [ V_16 ] . V_19 = V_19 ;
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
F_15 ( V_2 -> V_22 , L_12 ) ;
return - V_25 ;
}
unsigned int F_26 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_52 . V_53 ;
}
unsigned int F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_52 . V_54 ;
}
void * F_28 ( struct V_13 * V_14 ,
T_1 V_55 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( ! V_55 ||
( V_55 > ( V_56 + V_57 ) ) ) {
F_15 ( V_2 -> V_22 , L_13 ) ;
return F_29 ( - V_25 ) ;
}
if ( V_55 < V_56 )
return ( V_58 void * ) ( V_55 + V_2 -> V_5 . V_59 +
V_60 ) ;
return V_2 -> V_61 [ V_62 ] . V_63 + ( V_55 - V_56 ) ;
}
struct V_13 * F_30 ( struct V_13 * V_14 )
{
struct V_64 * V_22 = & V_14 -> V_22 ;
struct V_65 * V_66 ;
struct V_13 * V_67 ;
V_66 = F_31 ( V_22 -> V_68 , L_14 , 0 ) ;
if ( ! V_66 ) {
F_15 ( V_22 , L_15 ) ;
return NULL ;
}
V_67 = F_32 ( V_66 ) ;
if ( F_33 ( ! V_67 ) ) {
F_15 ( V_22 , L_16 ) ;
F_34 ( V_66 ) ;
return NULL ;
}
return V_67 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_69 * V_70 ,
T_3 V_71 )
{
T_4 V_72 = V_71 ? V_56 : V_73 ;
T_4 V_74 = V_71 ? V_75 : V_76 ;
char * V_77 = V_71 ? V_78 : V_79 ;
T_4 V_80 = 0 ;
T_4 V_81 = 0 ;
void * V_82 ;
int V_12 ;
V_12 = F_36 ( & V_70 , V_77 , V_2 -> V_22 ) ;
if ( V_12 < 0 ) {
F_15 ( V_2 -> V_22 , L_17 , V_77 , V_12 ) ;
return V_12 ;
}
V_80 = V_70 -> V_83 ;
if ( V_80 > V_74 ) {
F_15 ( V_2 -> V_22 , L_18 , V_77 ,
V_80 ) ;
F_37 ( V_70 ) ;
return - V_84 ;
}
F_23 ( V_2 -> V_22 , L_19 ,
V_77 ,
V_80 ) ;
F_1 ( V_2 , 0x0 , V_7 ) ;
if ( V_80 > V_72 ) {
F_23 ( V_2 -> V_22 , L_20 ,
V_80 , V_72 ) ;
V_81 = V_80 - V_72 ;
F_23 ( V_2 -> V_22 , L_21 , V_81 ) ;
V_80 = V_72 ;
}
V_82 = ( V_58 void * ) V_2 -> V_5 . V_59 ;
if ( V_71 == V_62 )
V_82 += V_60 ;
memcpy ( V_82 , V_70 -> V_85 , V_80 ) ;
if ( V_81 > 0 ) {
V_82 = V_2 -> V_61 [ V_71 ] . V_63 ;
F_23 ( V_2 -> V_22 , L_22 ,
V_71 ) ;
memcpy ( V_82 , V_70 -> V_85 + V_72 , V_81 ) ;
}
F_37 ( V_70 ) ;
return 0 ;
}
int F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_64 * V_22 = & V_14 -> V_22 ;
struct V_86 * V_52 ;
const struct V_69 * V_70 = NULL ;
int V_12 ;
if ( ! V_14 ) {
F_15 ( V_22 , L_23 ) ;
return - V_25 ;
}
V_2 = F_14 ( V_14 ) ;
V_52 = & V_2 -> V_52 ;
F_8 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_48 ) {
F_9 ( & V_2 -> V_8 ) ;
return 0 ;
}
F_9 ( & V_2 -> V_8 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_24 , V_12 ) ;
return V_12 ;
}
F_8 ( & V_2 -> V_8 ) ;
V_52 -> V_87 = false ;
F_23 ( V_2 -> V_22 , L_25 ) ;
V_12 = F_35 ( V_2 , V_70 , V_88 ) ;
if ( V_12 < 0 ) {
F_15 ( V_22 , L_26 , V_79 , V_12 ) ;
goto V_89;
}
V_12 = F_35 ( V_2 , V_70 , V_62 ) ;
if ( V_12 < 0 ) {
F_15 ( V_22 , L_26 , V_78 , V_12 ) ;
goto V_89;
}
V_2 -> V_48 = true ;
F_1 ( V_2 , 0x1 , V_7 ) ;
V_12 = F_39 ( V_52 -> V_90 ,
V_52 -> V_87 ,
F_17 ( V_91 )
) ;
if ( V_12 == 0 ) {
V_12 = - V_92 ;
F_15 ( V_22 , L_27 ) ;
goto V_89;
} else if ( - V_93 == V_12 ) {
F_15 ( V_22 , L_28 ) ;
goto V_89;
}
V_12 = 0 ;
F_22 ( V_22 , L_29 , V_52 -> V_94 ) ;
V_89:
F_9 ( & V_2 -> V_8 ) ;
F_7 ( V_2 ) ;
return V_12 ;
}
static void F_40 ( void * V_85 , unsigned int V_27 , void * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
struct V_86 * V_52 = (struct V_86 * ) V_85 ;
V_2 -> V_52 . V_87 = V_52 -> V_87 ;
strncpy ( V_2 -> V_52 . V_94 , V_52 -> V_94 , V_95 ) ;
V_2 -> V_52 . V_53 = V_52 -> V_53 ;
V_2 -> V_52 . V_54 = V_52 -> V_54 ;
F_41 ( & V_2 -> V_52 . V_90 ) ;
}
static T_5 F_42 ( struct V_96 * V_96 , char T_6 * V_97 ,
T_4 V_98 , T_7 * V_99 )
{
char V_26 [ 256 ] ;
unsigned int V_27 ;
unsigned int V_100 , V_101 , V_102 , V_103 , V_45 ;
int V_12 ;
struct V_64 * V_22 = V_96 -> V_104 ;
struct V_1 * V_2 = F_43 ( V_22 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_30 , V_12 ) ;
return 0 ;
}
V_100 = F_5 ( V_2 ) ;
V_101 = F_3 ( V_2 , V_105 ) ;
V_45 = F_3 ( V_2 , V_10 ) ;
V_103 = F_3 ( V_2 , V_39 ) ;
V_102 = F_3 ( V_2 , V_106 ) ;
F_7 ( V_2 ) ;
if ( V_100 ) {
V_27 = snprintf ( V_26 , sizeof( V_26 ) , L_31
L_32
L_33
L_34
L_35
L_36 ,
V_2 -> V_52 . V_94 , V_101 , V_45 ,
V_103 , V_102 ) ;
} else {
V_27 = snprintf ( V_26 , sizeof( V_26 ) , L_37 ) ;
}
return F_44 ( V_97 , V_98 , V_99 , V_26 , V_27 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_3 V_71 )
{
struct V_64 * V_22 = V_2 -> V_22 ;
T_4 V_107 = V_71 ? V_57 : V_108 ;
F_46 ( V_22 , V_107 , V_2 -> V_61 [ V_71 ] . V_63 ,
V_2 -> V_61 [ V_71 ] . V_109 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_71 )
{
struct V_64 * V_22 = V_2 -> V_22 ;
T_4 V_107 = V_71 ? V_57 : V_108 ;
T_1 V_110 = V_71 ? V_111 : V_112 ;
T_1 V_113 = V_71 ? V_114 : V_115 ;
T_1 V_116 = V_2 -> V_117 ? 0x40000000 : 0 ;
V_2 -> V_61 [ V_71 ] . V_63 = F_48 ( V_22 ,
V_107 ,
& V_2 -> V_61 [ V_71 ] . V_109 ,
V_118 ) ;
if ( ! V_2 -> V_61 [ V_71 ] . V_63 ) {
F_15 ( V_22 , L_38 ) ;
return - V_119 ;
}
F_1 ( V_2 , 0x1 , V_110 ) ;
F_1 ( V_2 , ( V_2 -> V_61 [ V_71 ] . V_109 & 0xFFFFF000 ) + V_116 ,
V_113 ) ;
F_22 ( V_22 , L_39 ,
V_71 ? L_40 : L_41 ,
( unsigned long long ) V_2 -> V_61 [ V_71 ] . V_109 ,
V_2 -> V_61 [ V_71 ] . V_63 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_28 * V_120 = V_2 -> V_121 ;
struct V_20 * V_21 = V_2 -> V_21 ;
if ( V_120 -> V_16 < V_24 && V_21 [ V_120 -> V_16 ] . V_17 ) {
V_21 [ V_120 -> V_16 ] . V_17 ( V_120 -> V_33 ,
V_120 -> V_27 ,
V_21 [ V_120 -> V_16 ] . V_19 ) ;
if ( V_120 -> V_16 > V_32 ) {
V_2 -> V_40 [ V_120 -> V_16 ] = true ;
F_50 ( & V_2 -> V_41 ) ;
}
} else {
F_15 ( V_2 -> V_22 , L_42 , V_120 -> V_16 ) ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0 , V_106 ) ;
V_2 -> V_121 = ( V_58 struct V_28 * ) ( V_2 -> V_5 . V_59 +
V_60 ) ;
V_2 -> V_30 = V_2 -> V_121 + 1 ;
memset ( V_2 -> V_121 , 0 , sizeof( struct V_28 ) ) ;
memset ( V_2 -> V_30 , 0 , sizeof( struct V_28 ) ) ;
return 0 ;
}
static T_8 F_52 ( int V_122 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
T_1 V_102 ;
int V_12 ;
V_12 = F_12 ( V_2 -> V_11 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_30 , V_12 ) ;
return V_123 ;
}
V_102 = F_3 ( V_2 , V_106 ) ;
if ( V_102 & V_124 ) {
F_49 ( V_2 ) ;
} else {
F_15 ( V_2 -> V_22 , L_43 , V_102 ) ;
F_53 ( V_2 -> V_45 . V_90 , & V_2 -> V_45 . V_43 ) ;
}
F_1 ( V_2 , 0x0 , V_106 ) ;
F_10 ( V_2 -> V_11 ) ;
return V_125 ;
}
static int F_54 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_64 * V_22 ;
struct V_126 * V_127 ;
int V_12 = 0 ;
F_23 ( & V_14 -> V_22 , L_44 ) ;
V_22 = & V_14 -> V_22 ;
V_2 = F_55 ( V_22 , sizeof( * V_2 ) , V_118 ) ;
if ( ! V_2 )
return - V_119 ;
V_2 -> V_22 = & V_14 -> V_22 ;
V_127 = F_56 ( V_14 , V_128 , L_45 ) ;
V_2 -> V_5 . V_59 = F_57 ( V_22 , V_127 ) ;
if ( F_58 ( ( V_58 void * ) V_2 -> V_5 . V_59 ) )
return F_59 ( ( V_58 void * ) V_2 -> V_5 . V_59 ) ;
V_127 = F_56 ( V_14 , V_128 , L_46 ) ;
V_2 -> V_5 . V_6 = F_57 ( V_22 , V_127 ) ;
if ( F_58 ( ( V_58 void * ) V_2 -> V_5 . V_6 ) )
return F_59 ( ( V_58 void * ) V_2 -> V_5 . V_6 ) ;
V_2 -> V_11 = F_60 ( V_22 , L_47 ) ;
if ( F_58 ( V_2 -> V_11 ) ) {
F_15 ( V_22 , L_48 ) ;
return F_59 ( V_2 -> V_11 ) ;
}
F_61 ( V_14 , V_2 ) ;
V_12 = F_62 ( V_2 -> V_11 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_49 ) ;
return V_12 ;
}
V_2 -> V_45 . V_90 = F_63 ( L_50 ) ;
if ( ! V_2 -> V_45 . V_90 ) {
F_15 ( V_22 , L_51 ) ;
return - V_119 ;
}
F_64 ( & V_2 -> V_45 . V_43 , F_20 ) ;
F_65 ( & V_2 -> V_8 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_52 ) ;
goto V_129;
}
F_23 ( V_22 , L_53 ) ;
V_12 = F_51 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_54 ) ;
goto V_130;
}
V_12 = F_13 ( V_14 , V_32 , F_40 ,
L_55 , V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_56 ) ;
goto V_131;
}
#ifdef F_66
V_132 = F_67 ( L_57 , V_133 , NULL , ( void * ) V_22 ,
& V_134 ) ;
if ( ! V_132 ) {
V_12 = - V_119 ;
goto V_135;
}
#endif
F_1 ( V_2 , 0x2 , V_136 ) ;
V_2 -> V_117 = ! ! ( V_137 > ( V_138 >> V_139 ) ) ;
F_22 ( V_22 , L_58 , V_2 -> V_117 ) ;
if ( V_2 -> V_117 ) {
V_12 = F_68 ( V_22 ) ;
if ( V_12 )
F_22 ( V_22 , L_59 ) ;
}
V_12 = F_47 ( V_2 , V_62 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_60 ) ;
goto V_140;
}
V_12 = F_47 ( V_2 , V_88 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_61 ) ;
goto V_141;
}
F_69 ( & V_2 -> V_52 . V_90 ) ;
F_69 ( & V_2 -> V_41 ) ;
V_127 = F_70 ( V_14 , V_142 , 0 ) ;
if ( ! V_127 ) {
F_15 ( V_22 , L_62 ) ;
V_12 = - V_143 ;
goto V_144;
}
V_2 -> V_5 . V_122 = F_71 ( V_14 , 0 ) ;
V_12 = F_72 ( V_22 , V_2 -> V_5 . V_122 , F_52 , 0 ,
V_14 -> V_18 , V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_63 ) ;
goto V_144;
}
F_7 ( V_2 ) ;
F_23 ( V_22 , L_64 ) ;
return 0 ;
V_144:
F_45 ( V_2 , V_88 ) ;
V_141:
F_45 ( V_2 , V_62 ) ;
V_140:
F_73 ( V_22 ) ;
#ifdef F_66
F_74 ( V_132 ) ;
V_135:
#endif
memset ( V_2 -> V_21 , 0 , sizeof( struct V_20 ) * V_24 ) ;
V_131:
F_75 ( & V_2 -> V_8 ) ;
V_130:
F_7 ( V_2 ) ;
V_129:
F_76 ( V_2 -> V_45 . V_90 ) ;
return V_12 ;
}
static int F_77 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
#ifdef F_66
F_74 ( V_132 ) ;
#endif
if ( V_2 -> V_45 . V_90 ) {
F_78 ( V_2 -> V_45 . V_90 ) ;
F_76 ( V_2 -> V_45 . V_90 ) ;
}
F_45 ( V_2 , V_88 ) ;
F_45 ( V_2 , V_62 ) ;
F_75 ( & V_2 -> V_8 ) ;
F_79 ( V_2 -> V_11 ) ;
return 0 ;
}
