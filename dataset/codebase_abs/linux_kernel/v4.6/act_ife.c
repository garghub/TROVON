int F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , const void * V_4 )
{
T_2 * V_5 = ( T_2 * ) ( V_1 ) ;
T_1 V_6 = F_2 ( V_3 ) ;
char * V_7 = ( char * ) V_5 + V_8 ;
T_2 V_9 = V_2 << 16 | V_6 ;
* V_5 = F_3 ( V_9 ) ;
memset ( V_7 , 0 , V_6 - V_8 ) ;
memcpy ( V_7 , V_4 , V_3 ) ;
return V_6 ;
}
int F_4 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( V_13 -> V_14 )
return F_5 ( V_11 , V_13 -> V_15 , * ( T_2 * ) V_13 -> V_14 ) ;
else
return F_6 ( V_11 , V_13 -> V_15 , 0 , NULL ) ;
}
int F_7 ( T_2 V_14 , struct V_12 * V_13 )
{
if ( V_14 || V_13 -> V_14 )
return 8 ;
return 0 ;
}
int F_8 ( T_2 V_14 , void * V_1 , struct V_12 * V_13 )
{
T_2 V_16 = V_14 ;
if ( V_13 -> V_14 )
V_16 = * ( T_2 * ) V_13 -> V_14 ;
else if ( V_14 )
V_16 = V_14 ;
if ( ! V_16 )
return 0 ;
V_16 = F_3 ( V_16 ) ;
return F_1 ( V_1 , V_13 -> V_15 , 4 , & V_16 ) ;
}
int F_9 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( V_13 -> V_14 )
return F_10 ( V_11 , V_13 -> V_15 , * ( T_1 * ) V_13 -> V_14 ) ;
else
return F_6 ( V_11 , V_13 -> V_15 , 0 , NULL ) ;
}
int F_11 ( struct V_12 * V_13 , void * V_14 )
{
V_13 -> V_14 = F_12 ( V_14 , sizeof( T_2 ) , V_17 ) ;
if ( ! V_13 -> V_14 )
return - V_18 ;
return 0 ;
}
int F_13 ( struct V_12 * V_13 , void * V_14 )
{
V_13 -> V_14 = F_12 ( V_14 , sizeof( T_1 ) , V_17 ) ;
if ( ! V_13 -> V_14 )
return - V_18 ;
return 0 ;
}
void F_14 ( struct V_12 * V_13 )
{
F_15 ( V_13 -> V_14 ) ;
}
int F_16 ( void * V_19 , int V_20 )
{
if ( V_20 == 4 )
return 0 ;
return - V_21 ;
}
int F_17 ( void * V_19 , int V_20 )
{
if ( V_20 == F_18 ( 2 ) )
return 0 ;
return - V_21 ;
}
static struct V_22 * F_19 ( T_1 V_15 )
{
struct V_22 * V_23 ;
F_20 ( & V_24 ) ;
F_21 (o, &ifeoplist, list) {
if ( V_23 -> V_15 == V_15 ) {
if ( ! F_22 ( V_23 -> V_25 ) )
V_23 = NULL ;
F_23 ( & V_24 ) ;
return V_23 ;
}
}
F_23 ( & V_24 ) ;
return NULL ;
}
int F_24 ( struct V_22 * V_26 )
{
struct V_22 * V_27 ;
if ( ! V_26 -> V_15 || ! V_26 -> V_28 || ! V_26 -> V_29 ||
! V_26 -> V_30 || ! V_26 -> V_31 || ! V_26 -> V_32 ||
! V_26 -> V_33 || ! V_26 -> V_34 )
return - V_21 ;
F_25 ( & V_24 ) ;
F_21 (m, &ifeoplist, list) {
if ( V_27 -> V_15 == V_26 -> V_15 ||
( strcmp ( V_26 -> V_29 , V_27 -> V_29 ) == 0 ) ) {
F_26 ( & V_24 ) ;
return - V_35 ;
}
}
if ( ! V_26 -> V_36 )
V_26 -> V_36 = F_14 ;
F_27 ( & V_26 -> V_37 , & V_38 ) ;
F_26 ( & V_24 ) ;
return 0 ;
}
int F_28 ( struct V_22 * V_26 )
{
struct V_22 * V_27 ;
int V_39 = - V_40 ;
F_25 ( & V_24 ) ;
F_21 (m, &ifeoplist, list) {
if ( V_27 -> V_15 == V_26 -> V_15 ) {
F_29 ( & V_26 -> V_37 ) ;
V_39 = 0 ;
break;
}
}
F_26 ( & V_24 ) ;
return V_39 ;
}
static int F_30 ( struct V_22 * V_41 , void * V_19 , int V_20 )
{
int V_42 = 0 ;
if ( V_41 -> V_43 )
return V_41 -> V_43 ( V_19 , V_20 ) ;
if ( V_41 -> V_28 == V_44 )
V_42 = F_16 ( V_19 , V_20 ) ;
else if ( V_41 -> V_28 == V_45 )
V_42 = F_17 ( V_19 , V_20 ) ;
return V_42 ;
}
static int F_31 ( struct V_46 * V_47 , T_2 V_15 ,
void * V_19 , int V_20 )
{
struct V_22 * V_41 = F_19 ( V_15 ) ;
int V_42 = 0 ;
if ( ! V_41 ) {
V_42 = - V_40 ;
#ifdef F_32
F_33 ( & V_47 -> V_48 ) ;
F_34 () ;
F_35 ( L_1 , V_15 ) ;
F_36 () ;
F_37 ( & V_47 -> V_48 ) ;
V_41 = F_19 ( V_15 ) ;
#endif
}
if ( V_41 ) {
V_42 = 0 ;
if ( V_20 )
V_42 = F_30 ( V_41 , V_19 , V_20 ) ;
F_38 ( V_41 -> V_25 ) ;
}
return V_42 ;
}
static int F_39 ( struct V_46 * V_47 , T_2 V_15 , void * V_14 ,
int V_20 )
{
struct V_12 * V_13 = NULL ;
struct V_22 * V_41 = F_19 ( V_15 ) ;
int V_42 = 0 ;
if ( ! V_41 )
return - V_40 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 ) {
F_38 ( V_41 -> V_25 ) ;
return - V_18 ;
}
V_13 -> V_15 = V_15 ;
V_13 -> V_41 = V_41 ;
if ( V_20 > 0 ) {
V_42 = V_41 -> V_34 ( V_13 , V_14 ) ;
if ( V_42 != 0 ) {
F_15 ( V_13 ) ;
F_38 ( V_41 -> V_25 ) ;
return V_42 ;
}
}
F_27 ( & V_13 -> V_49 , & V_47 -> V_49 ) ;
return V_42 ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_22 * V_23 ;
int V_50 = 0 ;
int V_51 = 0 ;
F_21 (o, &ifeoplist, list) {
V_50 = F_39 ( V_47 , V_23 -> V_15 , NULL , 0 ) ;
if ( V_50 == 0 )
V_51 += 1 ;
}
if ( V_51 )
return 0 ;
else
return - V_21 ;
}
static int F_42 ( struct V_10 * V_11 , struct V_46 * V_47 )
{
struct V_12 * V_52 ;
struct V_53 * V_54 ;
unsigned char * V_55 = F_43 ( V_11 ) ;
int V_56 = 0 ;
if ( F_44 ( & V_47 -> V_49 ) )
return 0 ;
V_54 = F_45 ( V_11 , V_57 ) ;
if ( ! V_54 )
goto V_58;
F_21 (e, &ife->metalist, metalist) {
if ( ! V_52 -> V_41 -> V_33 ( V_11 , V_52 ) )
V_56 += 1 ;
}
if ( ! V_56 )
goto V_58;
F_46 ( V_11 , V_54 ) ;
return 0 ;
V_58:
F_47 ( V_11 , V_55 ) ;
return - 1 ;
}
static void F_48 ( struct V_59 * V_60 , int V_61 )
{
struct V_46 * V_47 = V_60 -> V_62 ;
struct V_12 * V_52 , * V_63 ;
F_49 (e, n, &ife->metalist, metalist) {
F_38 ( V_52 -> V_41 -> V_25 ) ;
F_29 ( & V_52 -> V_49 ) ;
if ( V_52 -> V_14 ) {
if ( V_52 -> V_41 -> V_36 )
V_52 -> V_41 -> V_36 ( V_52 ) ;
else
F_15 ( V_52 -> V_14 ) ;
}
F_15 ( V_52 ) ;
}
}
static void F_50 ( struct V_59 * V_60 , int V_61 )
{
struct V_46 * V_47 = V_60 -> V_62 ;
F_37 ( & V_47 -> V_48 ) ;
F_48 ( V_60 , V_61 ) ;
F_33 ( & V_47 -> V_48 ) ;
}
static int F_51 ( struct V_46 * V_47 , struct V_53 * * V_64 )
{
int V_20 = 0 ;
int V_50 = 0 ;
int V_65 = 0 ;
void * V_19 ;
for ( V_65 = 1 ; V_65 < V_66 ; V_65 ++ ) {
if ( V_64 [ V_65 ] ) {
V_19 = F_52 ( V_64 [ V_65 ] ) ;
V_20 = F_53 ( V_64 [ V_65 ] ) ;
V_50 = F_31 ( V_47 , V_65 , V_19 , V_20 ) ;
if ( V_50 != 0 )
return V_50 ;
V_50 = F_39 ( V_47 , V_65 , V_19 , V_20 ) ;
if ( V_50 )
return V_50 ;
}
}
return V_50 ;
}
static int F_54 ( struct V_67 * V_67 , struct V_53 * V_68 ,
struct V_53 * V_69 , struct V_59 * V_60 ,
int V_70 , int V_61 )
{
struct V_71 * V_72 = F_55 ( V_67 , V_73 ) ;
struct V_53 * V_64 [ V_74 + 1 ] ;
struct V_53 * V_75 [ V_76 + 1 ] ;
struct V_46 * V_47 ;
struct V_77 * V_78 ;
T_1 V_79 = 0 ;
T_3 * V_80 = NULL ;
T_3 * V_81 = NULL ;
int V_42 = 0 , V_82 = 0 ;
int V_39 ;
V_39 = F_56 ( V_64 , V_74 , V_68 , V_83 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ! V_64 [ V_84 ] )
return - V_21 ;
V_78 = F_52 ( V_64 [ V_84 ] ) ;
V_82 = F_57 ( V_72 , V_78 -> V_85 , V_60 , V_61 ) ;
if ( V_82 && V_61 )
return 0 ;
if ( V_78 -> V_86 & V_87 ) {
if ( ! V_64 [ V_88 ] ) {
if ( V_82 )
F_58 ( V_60 , V_61 ) ;
F_59 ( L_2 ) ;
return - V_21 ;
}
}
if ( ! V_82 ) {
V_42 = F_60 ( V_72 , V_78 -> V_85 , V_69 , V_60 , sizeof( * V_47 ) ,
V_61 , false ) ;
if ( V_42 )
return V_42 ;
V_42 = V_89 ;
} else {
F_58 ( V_60 , V_61 ) ;
if ( ! V_70 )
return - V_35 ;
}
V_47 = F_61 ( V_60 ) ;
V_47 -> V_86 = V_78 -> V_86 ;
if ( V_78 -> V_86 & V_87 ) {
V_79 = F_62 ( V_64 [ V_88 ] ) ;
if ( V_64 [ V_90 ] )
V_80 = F_52 ( V_64 [ V_90 ] ) ;
if ( V_64 [ V_91 ] )
V_81 = F_52 ( V_64 [ V_91 ] ) ;
}
F_37 ( & V_47 -> V_48 ) ;
V_47 -> V_92 = V_78 -> V_93 ;
if ( V_78 -> V_86 & V_87 ) {
if ( V_80 )
F_63 ( V_47 -> V_94 , V_80 ) ;
else
F_64 ( V_47 -> V_94 ) ;
if ( V_81 )
F_63 ( V_47 -> V_95 , V_81 ) ;
else
F_64 ( V_47 -> V_95 ) ;
V_47 -> V_96 = V_79 ;
}
if ( V_42 == V_89 )
F_65 ( & V_47 -> V_49 ) ;
if ( V_64 [ V_57 ] ) {
V_39 = F_56 ( V_75 , V_76 , V_64 [ V_57 ] ,
NULL ) ;
if ( V_39 ) {
V_97:
if ( V_82 )
F_58 ( V_60 , V_61 ) ;
if ( V_42 == V_89 )
F_48 ( V_60 , V_61 ) ;
F_33 ( & V_47 -> V_48 ) ;
return V_39 ;
}
V_39 = F_51 ( V_47 , V_75 ) ;
if ( V_39 )
goto V_97;
} else {
V_39 = F_41 ( V_47 ) ;
if ( V_39 ) {
if ( V_42 == V_89 )
F_48 ( V_60 , V_61 ) ;
F_33 ( & V_47 -> V_48 ) ;
return V_39 ;
}
}
F_33 ( & V_47 -> V_48 ) ;
if ( V_42 == V_89 )
F_66 ( V_72 , V_60 ) ;
return V_42 ;
}
static int F_67 ( struct V_10 * V_11 , struct V_59 * V_60 , int V_61 ,
int V_98 )
{
unsigned char * V_55 = F_43 ( V_11 ) ;
struct V_46 * V_47 = V_60 -> V_62 ;
struct V_77 V_99 = {
. V_85 = V_47 -> V_100 ,
. V_101 = V_47 -> V_102 - V_98 ,
. V_103 = V_47 -> V_104 - V_61 ,
. V_93 = V_47 -> V_92 ,
. V_86 = V_47 -> V_86 ,
} ;
struct V_105 V_106 ;
if ( F_6 ( V_11 , V_84 , sizeof( V_99 ) , & V_99 ) )
goto V_107;
V_106 . V_108 = F_68 ( V_109 - V_47 -> V_110 . V_108 ) ;
V_106 . V_111 = F_68 ( V_109 - V_47 -> V_110 . V_111 ) ;
V_106 . V_112 = F_68 ( V_47 -> V_110 . V_112 ) ;
if ( F_6 ( V_11 , V_113 , sizeof( V_106 ) , & V_106 ) )
goto V_107;
if ( ! F_69 ( V_47 -> V_94 ) ) {
if ( F_6 ( V_11 , V_90 , V_114 , V_47 -> V_94 ) )
goto V_107;
}
if ( ! F_69 ( V_47 -> V_95 ) ) {
if ( F_6 ( V_11 , V_91 , V_114 , V_47 -> V_95 ) )
goto V_107;
}
if ( F_6 ( V_11 , V_88 , 2 , & V_47 -> V_96 ) )
goto V_107;
if ( F_42 ( V_11 , V_47 ) ) {
F_59 ( L_3 ) ;
}
return V_11 -> V_20 ;
V_107:
F_47 ( V_11 , V_55 ) ;
return - 1 ;
}
int F_70 ( struct V_10 * V_11 , struct V_46 * V_47 ,
T_1 V_15 , T_1 V_115 , void * V_116 )
{
struct V_12 * V_52 ;
F_21 (e, &ife->metalist, metalist) {
if ( V_15 == V_52 -> V_15 ) {
if ( V_52 -> V_41 ) {
return V_52 -> V_41 -> V_32 ( V_11 , V_116 , V_115 ) ;
}
}
}
return 0 ;
}
static int F_71 ( struct V_10 * V_11 , const struct V_59 * V_60 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = V_60 -> V_62 ;
int V_93 = V_47 -> V_92 ;
struct V_119 * V_120 = (struct V_119 * ) V_11 -> V_121 ;
T_1 V_122 = V_120 -> V_123 ;
struct V_124 * V_5 = (struct V_124 * ) ( V_120 -> V_125 ) ;
F_72 ( & V_47 -> V_48 ) ;
F_73 ( & V_47 -> V_126 , V_11 ) ;
V_47 -> V_110 . V_111 = V_109 ;
F_74 ( & V_47 -> V_48 ) ;
V_122 = F_75 ( V_122 ) ;
if ( F_76 ( ! F_77 ( V_11 , V_122 ) ) ) {
F_72 ( & V_47 -> V_48 ) ;
V_47 -> V_127 . V_128 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_129 ;
}
F_78 ( V_11 , V_122 ) ;
F_79 ( V_11 , V_122 ) ;
V_11 -> V_130 = F_80 ( V_11 , V_11 -> V_131 ) ;
V_122 -= V_132 ;
while ( V_122 > 0 ) {
T_3 * V_133 = ( T_3 * ) V_5 ;
T_1 V_134 = V_5 -> type ;
T_1 V_115 = V_5 -> V_20 ;
V_134 = F_75 ( V_134 ) ;
V_115 = F_75 ( V_115 ) ;
if ( F_70 ( V_11 , V_47 , V_134 , ( V_115 - 4 ) ,
( void * ) ( V_133 + 4 ) ) ) {
F_81 ( L_4 ,
V_134 , V_115 ) ;
V_47 -> V_127 . V_135 ++ ;
}
V_133 += V_115 ;
V_122 -= V_115 ;
V_5 = (struct V_124 * ) V_133 ;
}
F_82 ( V_11 ) ;
return V_93 ;
}
static int F_83 ( struct V_10 * V_11 , struct V_46 * V_47 )
{
struct V_12 * V_52 , * V_63 ;
int V_136 = 0 , V_137 = 0 ;
F_49 (e, n, &ife->metalist, metalist) {
if ( V_52 -> V_41 -> V_30 ) {
V_137 = V_52 -> V_41 -> V_30 ( V_11 , V_52 ) ;
V_136 += V_137 ;
}
}
return V_136 ;
}
static int F_84 ( struct V_10 * V_11 , const struct V_59 * V_60 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = V_60 -> V_62 ;
int V_93 = V_47 -> V_92 ;
struct V_138 * V_139 ;
struct V_138 * V_140 ;
struct V_12 * V_52 ;
T_1 V_123 = F_83 ( V_11 , V_47 ) ;
int V_141 = V_123 + V_11 -> V_131 -> V_142 + V_132 ;
unsigned int V_143 = V_11 -> V_131 -> V_142 ;
T_2 V_144 = F_85 ( V_11 -> V_145 ) ;
int V_146 = V_11 -> V_20 + V_141 ;
bool V_147 = false ;
int V_39 ;
if ( V_144 & V_148 ) {
if ( V_146 > V_11 -> V_131 -> V_149 )
V_147 = true ;
}
F_72 ( & V_47 -> V_48 ) ;
F_73 ( & V_47 -> V_126 , V_11 ) ;
V_47 -> V_110 . V_111 = V_109 ;
if ( ! V_123 ) {
V_47 -> V_127 . V_135 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_93 ;
}
if ( ( V_93 == V_129 ) || V_147 ) {
V_47 -> V_127 . V_128 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_129 ;
}
V_140 = F_86 ( V_11 ) ;
V_39 = F_87 ( V_11 , V_141 ) ;
if ( F_76 ( V_39 ) ) {
V_47 -> V_127 . V_128 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_129 ;
}
if ( ! ( V_144 & V_148 ) )
F_88 ( V_11 , V_11 -> V_131 -> V_142 ) ;
F_89 ( V_11 , V_141 ) ;
memcpy ( V_11 -> V_121 , V_140 , V_11 -> V_150 ) ;
F_90 ( V_11 ) ;
V_139 = F_86 ( V_11 ) ;
V_123 += V_132 ;
V_123 = F_91 ( V_123 ) ;
memcpy ( ( V_11 -> V_121 + V_143 ) , & V_123 , V_132 ) ;
V_143 += V_132 ;
F_21 (e, &ife->metalist, metalist) {
if ( V_52 -> V_41 -> V_31 ) {
V_39 = V_52 -> V_41 -> V_31 ( V_11 , ( void * ) ( V_11 -> V_121 + V_143 ) ,
V_52 ) ;
}
if ( V_39 < 0 ) {
V_47 -> V_127 . V_128 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_129 ;
}
V_143 += V_39 ;
}
if ( ! F_69 ( V_47 -> V_95 ) )
F_63 ( V_139 -> V_151 , V_47 -> V_95 ) ;
else
F_63 ( V_139 -> V_151 , V_140 -> V_151 ) ;
if ( ! F_69 ( V_47 -> V_94 ) )
F_63 ( V_139 -> V_152 , V_47 -> V_94 ) ;
else
F_63 ( V_139 -> V_152 , V_140 -> V_152 ) ;
V_139 -> V_153 = F_91 ( V_47 -> V_96 ) ;
if ( ! ( V_144 & V_148 ) )
F_92 ( V_11 , V_11 -> V_131 -> V_142 ) ;
F_74 ( & V_47 -> V_48 ) ;
return V_93 ;
}
static int F_93 ( struct V_10 * V_11 , const struct V_59 * V_60 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = V_60 -> V_62 ;
if ( V_47 -> V_86 & V_87 )
return F_84 ( V_11 , V_60 , V_118 ) ;
if ( ! ( V_47 -> V_86 & V_87 ) )
return F_71 ( V_11 , V_60 , V_118 ) ;
F_81 ( L_5 ) ;
F_72 ( & V_47 -> V_48 ) ;
F_73 ( & V_47 -> V_126 , V_11 ) ;
V_47 -> V_110 . V_111 = V_109 ;
V_47 -> V_127 . V_128 ++ ;
F_74 ( & V_47 -> V_48 ) ;
return V_129 ;
}
static int F_94 ( struct V_67 * V_67 , struct V_10 * V_11 ,
struct V_154 * V_155 , int type ,
struct V_59 * V_60 )
{
struct V_71 * V_72 = F_55 ( V_67 , V_73 ) ;
return F_95 ( V_72 , V_11 , V_155 , type , V_60 ) ;
}
static int F_96 ( struct V_67 * V_67 , struct V_59 * V_60 , T_2 V_85 )
{
struct V_71 * V_72 = F_55 ( V_67 , V_73 ) ;
return F_97 ( V_72 , V_60 , V_85 ) ;
}
static T_4 int F_98 ( struct V_67 * V_67 )
{
struct V_71 * V_72 = F_55 ( V_67 , V_73 ) ;
return F_99 ( V_72 , & V_156 , V_157 ) ;
}
static void T_5 F_100 ( struct V_67 * V_67 )
{
struct V_71 * V_72 = F_55 ( V_67 , V_73 ) ;
F_101 ( V_72 ) ;
}
static int T_6 F_102 ( void )
{
return F_103 ( & V_156 , & V_158 ) ;
}
static void T_7 F_104 ( void )
{
F_105 ( & V_156 , & V_158 ) ;
}
