static int
F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 ;
V_8 -> V_9 = F_2 ( sizeof( struct V_7 ) - 4 + 2 ) ;
V_8 -> V_10 = V_11 ;
V_8 -> V_12 = 0 ;
F_3 ( 0 , V_8 ) ;
F_4 ( & V_2 -> V_13 ) ;
V_6 = F_5 ( V_8 , V_2 , & V_5 -> V_14 ) ;
if ( V_6 ) {
F_6 ( & V_2 -> V_13 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 , V_8 , F_8 ( V_8 -> V_9 ) ) ;
F_6 ( & V_2 -> V_13 ) ;
F_9 ( 1 , L_1 ,
V_8 -> V_15 , V_6 ) ;
return V_6 ;
}
static bool
F_10 ( struct V_16 * V_17 , struct V_16 * V_18 )
{
return V_17 -> V_19 == V_18 -> V_19 ;
}
static unsigned int
F_11 ( char * V_3 )
{
T_1 * V_20 = ( T_1 * ) V_3 ;
return F_12 ( V_20 -> V_21 ) ;
}
static unsigned int
F_13 ( char * V_3 )
{
T_1 * V_20 = ( T_1 * ) V_3 ;
return ( F_12 ( V_20 -> V_22 ) << 16 ) +
F_12 ( V_20 -> V_23 ) ;
}
static struct V_4 *
F_14 ( struct V_1 * V_2 , char * V_24 )
{
struct V_7 * V_3 = (struct V_7 * ) V_24 ;
struct V_4 * V_5 ;
F_15 ( & V_25 ) ;
F_16 (mid, &server->pending_mid_q, qhead) {
if ( V_5 -> V_5 == V_3 -> V_15 &&
V_5 -> V_26 == V_27 &&
F_12 ( V_5 -> V_28 ) == V_3 -> V_10 ) {
F_17 ( & V_25 ) ;
return V_5 ;
}
}
F_17 ( & V_25 ) ;
return NULL ;
}
static void
F_18 ( struct V_1 * V_2 , const unsigned int V_29 ,
const int V_30 )
{
F_15 ( & V_2 -> V_31 ) ;
V_2 -> V_32 += V_29 ;
V_2 -> V_33 -- ;
F_17 ( & V_2 -> V_31 ) ;
F_19 ( & V_2 -> V_34 ) ;
}
static void
F_20 ( struct V_1 * V_2 , const int V_35 )
{
F_15 ( & V_2 -> V_31 ) ;
V_2 -> V_32 = V_35 ;
V_2 -> V_36 = V_35 > 1 ? V_37 : false ;
F_17 ( & V_2 -> V_31 ) ;
}
static int *
F_21 ( struct V_1 * V_2 , const int V_30 )
{
return & V_2 -> V_32 ;
}
static unsigned int
F_22 ( struct V_4 * V_5 )
{
return 1 ;
}
static T_2
F_23 ( struct V_1 * V_2 )
{
T_2 V_5 = 0 ;
T_3 V_38 , V_39 ;
bool V_40 ;
F_15 ( & V_25 ) ;
V_39 = ( T_3 ) ( ( V_2 -> V_41 ) & 0xffff ) ;
V_38 = V_39 ;
V_39 ++ ;
while ( V_39 != V_38 ) {
struct V_4 * V_42 ;
unsigned int V_43 ;
V_40 = false ;
if ( V_39 == 0 )
V_39 ++ ;
V_43 = 0 ;
F_16 (mid_entry, &server->pending_mid_q, qhead) {
++ V_43 ;
if ( V_42 -> V_5 == V_39 &&
V_42 -> V_26 == V_27 ) {
V_40 = true ;
break;
}
}
if ( V_43 > 32768 )
V_2 -> V_44 = V_45 ;
if ( ! V_40 ) {
V_5 = ( T_2 ) V_39 ;
V_2 -> V_41 = V_5 ;
break;
}
V_39 ++ ;
}
F_17 ( & V_25 ) ;
return V_5 ;
}
static int
F_24 ( char * V_3 )
{
struct V_7 * V_46 = (struct V_7 * ) V_3 ;
struct V_47 * V_48 ;
int V_49 ;
T_3 V_50 , V_51 ;
if ( V_46 -> V_10 != V_52 )
return 0 ;
if ( V_46 -> V_12 != 10 ) {
F_9 ( 1 , L_2 ) ;
return - V_53 ;
}
V_48 = (struct V_47 * ) V_46 ;
V_50 = F_25 ( & V_48 -> V_54 . V_55 ) ;
V_51 = F_25 ( & V_48 -> V_54 . V_56 ) ;
if ( V_50 == V_51 )
return 0 ;
else if ( V_50 < V_51 ) {
F_9 ( 1 , L_3 ,
V_50 , V_51 ) ;
return - V_53 ;
}
V_49 = V_50 - V_51 ;
F_9 ( 1 , L_4 ,
V_49 ) ;
if ( V_50 > V_57 ) {
F_26 ( 1 , L_5 ,
V_50 , V_57 ) ;
return - V_53 ;
}
return V_49 ;
}
static int
F_27 ( char * V_58 , struct V_7 * V_59 )
{
struct V_47 * V_60 = (struct V_47 * ) V_58 ;
struct V_47 * V_48 = (struct V_47 * ) V_59 ;
char * V_61 ;
char * V_62 ;
int V_49 ;
unsigned int V_63 , V_64 ;
T_3 V_65 , V_66 , V_67 ;
V_66 = F_25 ( & V_60 -> V_54 . V_55 ) ;
V_65 = F_25 ( & V_48 -> V_54 . V_55 ) ;
if ( V_65 != V_66 )
F_9 ( 1 , L_6
L_7 , V_66 , V_65 ) ;
V_64 = F_25 ( & V_48 -> V_54 . V_56 ) ;
V_49 = V_65 - V_64 ;
if ( V_49 < 0 ) {
F_9 ( 1 , L_8
L_9 , V_65 , V_64 ) ;
return - V_68 ;
}
if ( V_49 == 0 ) {
F_9 ( 1 , L_10 ) ;
return 0 ;
}
V_67 = F_25 ( & V_60 -> V_54 . V_56 ) ;
if ( V_49 < V_67 )
F_9 ( 1 , L_11 ) ;
V_61 = ( char * ) & V_48 -> V_69 . V_70 +
F_25 ( & V_48 -> V_54 . V_21 ) ;
V_62 = ( char * ) & V_60 -> V_69 . V_70 +
F_25 ( & V_60 -> V_54 . V_21 ) ;
V_61 += V_64 ;
V_64 += V_67 ;
if ( V_64 > V_71 ) {
F_9 ( 1 , L_12 , V_64 ) ;
return - V_68 ;
}
F_28 ( V_64 , & V_48 -> V_54 . V_56 ) ;
V_63 = F_29 ( V_59 ) ;
V_63 += V_67 ;
if ( V_63 > V_71 ) {
F_9 ( 1 , L_13 , V_63 ) ;
return - V_68 ;
}
F_3 ( V_63 , V_59 ) ;
V_63 = F_8 ( V_59 -> V_9 ) ;
V_63 += V_67 ;
if ( V_63 > V_57 + V_72 - 4 ) {
F_9 ( 1 , L_14 , V_63 ) ;
return - V_73 ;
}
V_59 -> V_9 = F_2 ( V_63 ) ;
memcpy ( V_61 , V_62 , V_67 ) ;
if ( V_49 != V_67 ) {
F_9 ( 1 , L_15 ) ;
return 1 ;
}
F_9 ( 1 , L_16 ) ;
return 0 ;
}
static bool
F_30 ( struct V_4 * V_5 , struct V_1 * V_2 ,
char * V_3 , int V_74 )
{
if ( V_74 )
return false ;
if ( F_24 ( V_3 ) <= 0 )
return false ;
V_5 -> V_75 = true ;
if ( V_5 -> V_76 ) {
V_74 = F_27 ( V_3 , V_5 -> V_76 ) ;
if ( V_74 > 0 )
return true ;
V_5 -> V_77 = true ;
F_31 ( V_5 , V_74 ) ;
return true ;
}
if ( ! V_2 -> V_78 ) {
F_26 ( 1 , L_17 ) ;
} else {
V_5 -> V_76 = V_3 ;
V_5 -> V_78 = true ;
V_2 -> V_79 = NULL ;
}
return true ;
}
static bool
F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_80 == 0 ;
}
static int
F_33 ( const unsigned int V_81 , struct V_82 * V_83 )
{
int V_6 ;
V_6 = F_34 ( V_81 , V_83 ) ;
if ( V_6 == - V_84 ) {
F_35 ( V_83 -> V_2 , 1 ) ;
V_6 = F_34 ( V_81 , V_83 ) ;
if ( V_6 == - V_84 )
V_6 = - V_85 ;
}
return V_6 ;
}
static void
F_36 ( const unsigned int V_81 , struct V_86 * V_87 )
{
F_37 ( V_81 , V_87 ) ;
F_38 ( V_81 , V_87 ) ;
}
static int
F_39 ( const unsigned int V_81 , struct V_86 * V_87 ,
struct V_88 * V_89 , const char * V_90 )
{
int V_6 ;
T_4 * V_91 ;
V_91 = F_40 ( sizeof( T_4 ) , V_92 ) ;
if ( V_91 == NULL )
return - V_93 ;
V_6 = F_41 ( V_81 , V_87 , V_90 , V_91 ,
0 , V_89 -> V_94 ,
V_89 -> V_95 &
V_96 ) ;
if ( V_6 == - V_97 || V_6 == - V_53 )
V_6 = F_42 ( V_81 , V_87 , V_90 , V_91 ,
V_89 -> V_94 , V_89 -> V_95 &
V_96 ) ;
F_43 ( V_91 ) ;
return V_6 ;
}
static int
F_44 ( const unsigned int V_81 , struct V_86 * V_87 ,
struct V_88 * V_89 , const char * V_90 ,
T_4 * V_98 , bool * V_99 )
{
int V_6 ;
V_6 = F_41 ( V_81 , V_87 , V_90 , V_98 , 0 ,
V_89 -> V_94 , V_89 -> V_95 &
V_96 ) ;
if ( ( V_6 == - V_97 ) || ( V_6 == - V_53 ) ) {
V_6 = F_42 ( V_81 , V_87 , V_90 , V_98 ,
V_89 -> V_94 ,
V_89 -> V_95 &
V_96 ) ;
* V_99 = true ;
}
return V_6 ;
}
static int
F_45 ( const unsigned int V_81 , struct V_86 * V_87 ,
struct V_88 * V_89 , const char * V_90 ,
T_5 * V_100 , T_4 * V_98 )
{
return F_46 ( V_81 , V_87 , V_90 , V_100 ,
V_89 -> V_94 ,
V_89 -> V_95 &
V_96 ) ;
}
static char *
F_47 ( struct V_101 * V_102 , struct V_88 * V_89 ,
struct V_86 * V_87 )
{
int V_103 = V_102 -> V_104 ? strlen ( V_102 -> V_104 ) : 0 ;
int V_105 ;
char * V_90 = NULL ;
if ( V_103 == 0 ) {
V_90 = F_48 ( 1 , V_92 ) ;
return V_90 ;
}
if ( V_87 -> V_106 & V_107 )
V_105 = F_49 ( V_87 -> V_108 , V_109 + 1 ) ;
else
V_105 = 0 ;
V_90 = F_40 ( V_105 + V_103 + 1 , V_92 ) ;
if ( V_90 == NULL )
return V_90 ;
if ( V_105 )
strncpy ( V_90 , V_87 -> V_108 , V_105 ) ;
strncpy ( V_90 + V_105 , V_102 -> V_104 , V_103 ) ;
F_50 ( V_90 , F_51 ( V_89 ) ) ;
V_90 [ V_105 + V_103 ] = 0 ;
return V_90 ;
}
static void
F_52 ( struct V_86 * V_87 )
{
#ifdef F_53
F_54 ( & V_87 -> V_110 . V_111 . V_112 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_113 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_114 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_115 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_116 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_117 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_118 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_119 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_120 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_121 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_122 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_123 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_124 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_125 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_126 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_127 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_128 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_129 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_130 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_131 , 0 ) ;
F_54 ( & V_87 -> V_110 . V_111 . V_132 , 0 ) ;
#endif
}
static void
F_55 ( struct V_133 * V_134 , struct V_86 * V_87 )
{
#ifdef F_53
F_56 ( V_134 , L_18 ,
F_57 ( & V_87 -> V_110 . V_111 . V_115 ) ) ;
F_56 ( V_134 , L_19 ,
F_57 ( & V_87 -> V_110 . V_111 . V_113 ) ,
( long long ) ( V_87 -> V_135 ) ) ;
F_56 ( V_134 , L_20 ,
F_57 ( & V_87 -> V_110 . V_111 . V_112 ) ,
( long long ) ( V_87 -> V_136 ) ) ;
F_56 ( V_134 , L_21 ,
F_57 ( & V_87 -> V_110 . V_111 . V_114 ) ) ;
F_56 ( V_134 , L_22 ,
F_57 ( & V_87 -> V_110 . V_111 . V_130 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_128 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_129 ) ) ;
F_56 ( V_134 , L_23 ,
F_57 ( & V_87 -> V_110 . V_111 . V_116 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_119 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_120 ) ) ;
F_56 ( V_134 , L_24 ,
F_57 ( & V_87 -> V_110 . V_111 . V_117 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_118 ) ) ;
F_56 ( V_134 , L_25 ,
F_57 ( & V_87 -> V_110 . V_111 . V_121 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_122 ) ) ;
F_56 ( V_134 , L_26 ,
F_57 ( & V_87 -> V_110 . V_111 . V_123 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_124 ) ) ;
F_56 ( V_134 , L_27 ,
F_57 ( & V_87 -> V_110 . V_111 . V_125 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_126 ) ,
F_57 ( & V_87 -> V_110 . V_111 . V_127 ) ) ;
#endif
}
static void
F_58 ( struct V_137 * V_137 , const char * V_90 ,
struct V_88 * V_89 , struct V_86 * V_87 ,
const unsigned int V_81 )
{
T_6 V_138 ;
struct V_139 * V_140 ;
T_7 V_141 ;
int V_6 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
V_140 = F_59 ( V_137 ) ;
V_141 = V_140 -> V_142 | V_143 ;
V_138 . V_144 = F_60 ( V_141 ) ;
V_6 = F_61 ( V_81 , V_87 , V_90 , & V_138 , V_89 -> V_94 ,
V_89 -> V_95 &
V_96 ) ;
if ( V_6 == 0 )
V_140 -> V_142 = V_141 ;
}
