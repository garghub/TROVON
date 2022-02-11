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
void * F_27 ( struct V_13 * V_14 ,
T_1 V_54 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
if ( ! V_54 ||
( V_54 > ( V_55 + V_56 ) ) ) {
F_15 ( V_2 -> V_22 , L_13 ) ;
return F_28 ( - V_25 ) ;
}
if ( V_54 < V_55 )
return ( V_57 void * ) ( V_54 + V_2 -> V_5 . V_58 +
V_59 ) ;
return V_2 -> V_60 [ V_61 ] . V_62 + ( V_54 - V_55 ) ;
}
struct V_13 * F_29 ( struct V_13 * V_14 )
{
struct V_63 * V_22 = & V_14 -> V_22 ;
struct V_64 * V_65 ;
struct V_13 * V_66 ;
V_65 = F_30 ( V_22 -> V_67 , L_14 , 0 ) ;
if ( ! V_65 ) {
F_15 ( V_22 , L_15 ) ;
return NULL ;
}
V_66 = F_31 ( V_65 ) ;
if ( F_32 ( ! V_66 ) ) {
F_15 ( V_22 , L_16 ) ;
F_33 ( V_65 ) ;
return NULL ;
}
return V_66 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_68 * V_69 ,
T_3 V_70 )
{
T_4 V_71 = V_70 ? V_55 : V_72 ;
T_4 V_73 = V_70 ? V_74 : V_75 ;
char * V_76 = V_70 ? V_77 : V_78 ;
T_4 V_79 = 0 ;
T_4 V_80 = 0 ;
void * V_81 ;
int V_12 ;
V_12 = F_35 ( & V_69 , V_76 , V_2 -> V_22 ) ;
if ( V_12 < 0 ) {
F_15 ( V_2 -> V_22 , L_17 , V_76 , V_12 ) ;
return V_12 ;
}
V_79 = V_69 -> V_82 ;
if ( V_79 > V_73 ) {
F_15 ( V_2 -> V_22 , L_18 , V_76 ,
V_79 ) ;
F_36 ( V_69 ) ;
return - V_83 ;
}
F_23 ( V_2 -> V_22 , L_19 ,
V_76 ,
V_79 ) ;
F_1 ( V_2 , 0x0 , V_7 ) ;
if ( V_79 > V_71 ) {
F_23 ( V_2 -> V_22 , L_20 ,
V_79 , V_71 ) ;
V_80 = V_79 - V_71 ;
F_23 ( V_2 -> V_22 , L_21 , V_80 ) ;
V_79 = V_71 ;
}
V_81 = ( V_57 void * ) V_2 -> V_5 . V_58 ;
if ( V_70 == V_61 )
V_81 += V_59 ;
memcpy ( V_81 , V_69 -> V_84 , V_79 ) ;
if ( V_80 > 0 ) {
V_81 = V_2 -> V_60 [ V_70 ] . V_62 ;
F_23 ( V_2 -> V_22 , L_22 ,
V_70 ) ;
memcpy ( V_81 , V_69 -> V_84 + V_71 , V_80 ) ;
}
F_36 ( V_69 ) ;
return 0 ;
}
int F_37 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
struct V_63 * V_22 = & V_14 -> V_22 ;
struct V_85 * V_52 = & V_2 -> V_52 ;
const struct V_68 * V_69 = NULL ;
int V_12 ;
if ( ! V_14 ) {
F_15 ( V_22 , L_23 ) ;
return - V_25 ;
}
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
V_52 -> V_86 = false ;
F_23 ( V_2 -> V_22 , L_25 ) ;
V_12 = F_34 ( V_2 , V_69 , V_87 ) ;
if ( V_12 < 0 ) {
F_15 ( V_22 , L_26 , V_78 , V_12 ) ;
goto V_88;
}
V_12 = F_34 ( V_2 , V_69 , V_61 ) ;
if ( V_12 < 0 ) {
F_15 ( V_22 , L_26 , V_77 , V_12 ) ;
goto V_88;
}
V_2 -> V_48 = true ;
F_1 ( V_2 , 0x1 , V_7 ) ;
V_12 = F_38 ( V_52 -> V_89 ,
V_52 -> V_86 ,
F_17 ( V_90 )
) ;
if ( V_12 == 0 ) {
V_12 = - V_91 ;
F_15 ( V_22 , L_27 ) ;
goto V_88;
} else if ( - V_92 == V_12 ) {
F_15 ( V_22 , L_28 ) ;
goto V_88;
}
V_12 = 0 ;
F_22 ( V_22 , L_29 , V_52 -> V_93 ) ;
V_88:
F_9 ( & V_2 -> V_8 ) ;
F_7 ( V_2 ) ;
return V_12 ;
}
static void F_39 ( void * V_84 , unsigned int V_27 , void * V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_19 ;
struct V_85 * V_52 = (struct V_85 * ) V_84 ;
V_2 -> V_52 . V_86 = V_52 -> V_86 ;
strncpy ( V_2 -> V_52 . V_93 , V_52 -> V_93 , V_94 ) ;
V_2 -> V_52 . V_53 = V_52 -> V_53 ;
F_40 ( & V_2 -> V_52 . V_89 ) ;
}
static T_5 F_41 ( struct V_95 * V_95 , char T_6 * V_96 ,
T_4 V_97 , T_7 * V_98 )
{
char V_26 [ 256 ] ;
unsigned int V_27 ;
unsigned int V_99 , V_100 , V_101 , V_102 , V_45 ;
int V_12 ;
struct V_63 * V_22 = V_95 -> V_103 ;
struct V_1 * V_2 = F_42 ( V_22 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_30 , V_12 ) ;
return 0 ;
}
V_99 = F_5 ( V_2 ) ;
V_100 = F_3 ( V_2 , V_104 ) ;
V_45 = F_3 ( V_2 , V_10 ) ;
V_102 = F_3 ( V_2 , V_39 ) ;
V_101 = F_3 ( V_2 , V_105 ) ;
F_7 ( V_2 ) ;
if ( V_99 ) {
V_27 = snprintf ( V_26 , sizeof( V_26 ) , L_31
L_32
L_33
L_34
L_35
L_36 ,
V_2 -> V_52 . V_93 , V_100 , V_45 ,
V_102 , V_101 ) ;
} else {
V_27 = snprintf ( V_26 , sizeof( V_26 ) , L_37 ) ;
}
return F_43 ( V_96 , V_97 , V_98 , V_26 , V_27 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_3 V_70 )
{
struct V_63 * V_22 = V_2 -> V_22 ;
T_4 V_106 = V_70 ? V_56 : V_107 ;
F_45 ( V_22 , V_106 , V_2 -> V_60 [ V_70 ] . V_62 ,
V_2 -> V_60 [ V_70 ] . V_108 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_70 )
{
struct V_63 * V_22 = V_2 -> V_22 ;
T_4 V_106 = V_70 ? V_56 : V_107 ;
T_1 V_109 = V_70 ? V_110 : V_111 ;
T_1 V_112 = V_70 ? V_113 : V_114 ;
T_1 V_115 = V_2 -> V_116 ? 0x40000000 : 0 ;
V_2 -> V_60 [ V_70 ] . V_62 = F_47 ( V_22 ,
V_106 ,
& V_2 -> V_60 [ V_70 ] . V_108 ,
V_117 ) ;
if ( ! V_2 -> V_60 [ V_70 ] . V_62 ) {
F_15 ( V_22 , L_38 ) ;
return F_48 ( V_2 -> V_60 [ V_70 ] . V_62 ) ;
}
F_1 ( V_2 , 0x1 , V_109 ) ;
F_1 ( V_2 , ( V_2 -> V_60 [ V_70 ] . V_108 & 0xFFFFF000 ) + V_115 ,
V_112 ) ;
F_22 ( V_22 , L_39 ,
V_70 ? L_40 : L_41 ,
( unsigned long long ) V_2 -> V_60 [ V_70 ] . V_108 ,
V_2 -> V_60 [ V_70 ] . V_62 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_28 * V_118 = V_2 -> V_119 ;
struct V_20 * V_21 = V_2 -> V_21 ;
if ( V_118 -> V_16 < V_24 && V_21 [ V_118 -> V_16 ] . V_17 ) {
V_21 [ V_118 -> V_16 ] . V_17 ( V_118 -> V_33 ,
V_118 -> V_27 ,
V_21 [ V_118 -> V_16 ] . V_19 ) ;
if ( V_118 -> V_16 > V_32 ) {
V_2 -> V_40 [ V_118 -> V_16 ] = true ;
F_50 ( & V_2 -> V_41 ) ;
}
} else {
F_15 ( V_2 -> V_22 , L_42 , V_118 -> V_16 ) ;
}
}
static int F_51 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x0 , V_105 ) ;
V_2 -> V_119 = ( V_57 struct V_28 * ) ( V_2 -> V_5 . V_58 +
V_59 ) ;
V_2 -> V_30 = V_2 -> V_119 + 1 ;
memset ( V_2 -> V_119 , 0 , sizeof( struct V_28 ) ) ;
memset ( V_2 -> V_30 , 0 , sizeof( struct V_28 ) ) ;
return 0 ;
}
static T_8 F_52 ( int V_120 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
T_1 V_101 ;
int V_12 ;
V_12 = F_12 ( V_2 -> V_11 ) ;
if ( V_12 ) {
F_15 ( V_2 -> V_22 , L_30 , V_12 ) ;
return V_121 ;
}
V_101 = F_3 ( V_2 , V_105 ) ;
if ( V_101 & V_122 ) {
F_49 ( V_2 ) ;
} else {
F_15 ( V_2 -> V_22 , L_43 , V_101 ) ;
F_53 ( V_2 -> V_45 . V_89 , & V_2 -> V_45 . V_43 ) ;
}
F_1 ( V_2 , 0x0 , V_105 ) ;
F_10 ( V_2 -> V_11 ) ;
return V_123 ;
}
static int F_54 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_63 * V_22 ;
struct V_124 * V_125 ;
int V_12 = 0 ;
F_23 ( & V_14 -> V_22 , L_44 ) ;
V_22 = & V_14 -> V_22 ;
V_2 = F_55 ( V_22 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_126 ;
V_2 -> V_22 = & V_14 -> V_22 ;
V_125 = F_56 ( V_14 , V_127 , L_45 ) ;
V_2 -> V_5 . V_58 = F_57 ( V_22 , V_125 ) ;
if ( F_58 ( ( V_57 void * ) V_2 -> V_5 . V_58 ) )
return F_48 ( ( V_57 void * ) V_2 -> V_5 . V_58 ) ;
V_125 = F_56 ( V_14 , V_127 , L_46 ) ;
V_2 -> V_5 . V_6 = F_57 ( V_22 , V_125 ) ;
if ( F_58 ( ( V_57 void * ) V_2 -> V_5 . V_6 ) )
return F_48 ( ( V_57 void * ) V_2 -> V_5 . V_6 ) ;
V_2 -> V_11 = F_59 ( V_22 , L_47 ) ;
if ( F_58 ( V_2 -> V_11 ) ) {
F_15 ( V_22 , L_48 ) ;
return F_48 ( V_2 -> V_11 ) ;
}
F_60 ( V_14 , V_2 ) ;
V_12 = F_61 ( V_2 -> V_11 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_49 ) ;
return V_12 ;
}
V_2 -> V_45 . V_89 = F_62 ( L_50 ) ;
if ( ! V_2 -> V_45 . V_89 ) {
F_15 ( V_22 , L_51 ) ;
return - V_126 ;
}
F_63 ( & V_2 -> V_45 . V_43 , F_20 ) ;
F_64 ( & V_2 -> V_8 ) ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_52 ) ;
goto V_128;
}
F_23 ( V_22 , L_53 ) ;
V_12 = F_51 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_54 ) ;
goto V_129;
}
V_12 = F_13 ( V_14 , V_32 , F_39 ,
L_55 , V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_56 ) ;
goto V_130;
}
#ifdef F_65
V_131 = F_66 ( L_57 , V_132 , NULL , ( void * ) V_22 ,
& V_133 ) ;
if ( ! V_131 ) {
V_12 = - V_126 ;
goto V_134;
}
#endif
F_1 ( V_2 , 0x2 , V_135 ) ;
V_2 -> V_116 = ! ! ( V_136 > ( V_137 >> V_138 ) ) ;
F_22 ( V_22 , L_58 , V_2 -> V_116 ) ;
if ( V_2 -> V_116 ) {
V_12 = F_67 ( V_22 ) ;
if ( V_12 )
F_22 ( V_22 , L_59 ) ;
}
V_12 = F_46 ( V_2 , V_61 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_60 ) ;
goto V_139;
}
V_12 = F_46 ( V_2 , V_87 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_61 ) ;
goto V_140;
}
F_68 ( & V_2 -> V_52 . V_89 ) ;
F_68 ( & V_2 -> V_41 ) ;
V_125 = F_69 ( V_14 , V_141 , 0 ) ;
if ( ! V_125 ) {
F_15 ( V_22 , L_62 ) ;
V_12 = - V_142 ;
goto V_143;
}
V_2 -> V_5 . V_120 = F_70 ( V_14 , 0 ) ;
V_12 = F_71 ( V_22 , V_2 -> V_5 . V_120 , F_52 , 0 ,
V_14 -> V_18 , V_2 ) ;
if ( V_12 ) {
F_15 ( V_22 , L_63 ) ;
goto V_143;
}
F_7 ( V_2 ) ;
F_23 ( V_22 , L_64 ) ;
return 0 ;
V_143:
F_44 ( V_2 , V_87 ) ;
V_140:
F_44 ( V_2 , V_61 ) ;
V_139:
F_72 ( V_22 ) ;
#ifdef F_65
F_73 ( V_131 ) ;
V_134:
#endif
memset ( V_2 -> V_21 , 0 , sizeof( struct V_20 ) * V_24 ) ;
V_130:
F_74 ( & V_2 -> V_8 ) ;
V_129:
F_7 ( V_2 ) ;
V_128:
F_75 ( V_2 -> V_45 . V_89 ) ;
return V_12 ;
}
static int F_76 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
#ifdef F_65
F_73 ( V_131 ) ;
#endif
if ( V_2 -> V_45 . V_89 ) {
F_77 ( V_2 -> V_45 . V_89 ) ;
F_75 ( V_2 -> V_45 . V_89 ) ;
}
F_44 ( V_2 , V_87 ) ;
F_44 ( V_2 , V_61 ) ;
F_74 ( & V_2 -> V_8 ) ;
F_78 ( V_2 -> V_11 ) ;
return 0 ;
}
