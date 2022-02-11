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
int F_11 ( struct V_12 * V_13 , void * V_14 , T_3 V_17 )
{
V_13 -> V_14 = F_12 ( V_14 , sizeof( T_2 ) , V_17 ) ;
if ( ! V_13 -> V_14 )
return - V_18 ;
return 0 ;
}
int F_13 ( struct V_12 * V_13 , void * V_14 , T_3 V_17 )
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
void * V_19 , int V_20 , bool V_48 )
{
struct V_22 * V_41 = F_19 ( V_15 ) ;
int V_42 = 0 ;
if ( ! V_41 ) {
V_42 = - V_40 ;
#ifdef F_32
if ( V_48 )
F_33 ( & V_47 -> V_49 ) ;
F_34 () ;
F_35 ( L_1 , V_15 ) ;
F_36 () ;
if ( V_48 )
F_37 ( & V_47 -> V_49 ) ;
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
int V_20 , bool V_50 )
{
struct V_12 * V_13 = NULL ;
struct V_22 * V_41 = F_19 ( V_15 ) ;
int V_42 = 0 ;
if ( ! V_41 )
return - V_40 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_50 ? V_51 : V_52 ) ;
if ( ! V_13 ) {
F_38 ( V_41 -> V_25 ) ;
return - V_18 ;
}
V_13 -> V_15 = V_15 ;
V_13 -> V_41 = V_41 ;
if ( V_20 > 0 ) {
V_42 = V_41 -> V_34 ( V_13 , V_14 , V_50 ? V_51 : V_52 ) ;
if ( V_42 != 0 ) {
F_15 ( V_13 ) ;
F_38 ( V_41 -> V_25 ) ;
return V_42 ;
}
}
F_27 ( & V_13 -> V_53 , & V_47 -> V_53 ) ;
return V_42 ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_22 * V_23 ;
int V_54 = 0 ;
int V_55 = 0 ;
F_20 ( & V_24 ) ;
F_21 (o, &ifeoplist, list) {
V_54 = F_39 ( V_47 , V_23 -> V_15 , NULL , 0 , true ) ;
if ( V_54 == 0 )
V_55 += 1 ;
}
F_23 ( & V_24 ) ;
if ( V_55 )
return 0 ;
else
return - V_21 ;
}
static int F_42 ( struct V_10 * V_11 , struct V_46 * V_47 )
{
struct V_12 * V_56 ;
struct V_57 * V_58 ;
unsigned char * V_59 = F_43 ( V_11 ) ;
int V_60 = 0 ;
if ( F_44 ( & V_47 -> V_53 ) )
return 0 ;
V_58 = F_45 ( V_11 , V_61 ) ;
if ( ! V_58 )
goto V_62;
F_21 (e, &ife->metalist, metalist) {
if ( ! V_56 -> V_41 -> V_33 ( V_11 , V_56 ) )
V_60 += 1 ;
}
if ( ! V_60 )
goto V_62;
F_46 ( V_11 , V_58 ) ;
return 0 ;
V_62:
F_47 ( V_11 , V_59 ) ;
return - 1 ;
}
static void F_48 ( struct V_63 * V_64 , int V_65 )
{
struct V_46 * V_47 = V_64 -> V_66 ;
struct V_12 * V_56 , * V_67 ;
F_49 (e, n, &ife->metalist, metalist) {
F_38 ( V_56 -> V_41 -> V_25 ) ;
F_29 ( & V_56 -> V_53 ) ;
if ( V_56 -> V_14 ) {
if ( V_56 -> V_41 -> V_36 )
V_56 -> V_41 -> V_36 ( V_56 ) ;
else
F_15 ( V_56 -> V_14 ) ;
}
F_15 ( V_56 ) ;
}
}
static void F_50 ( struct V_63 * V_64 , int V_65 )
{
struct V_46 * V_47 = V_64 -> V_66 ;
F_37 ( & V_47 -> V_49 ) ;
F_48 ( V_64 , V_65 ) ;
F_33 ( & V_47 -> V_49 ) ;
}
static int F_51 ( struct V_46 * V_47 , struct V_57 * * V_68 ,
bool V_48 )
{
int V_20 = 0 ;
int V_54 = 0 ;
int V_69 = 0 ;
void * V_19 ;
for ( V_69 = 1 ; V_69 < V_70 ; V_69 ++ ) {
if ( V_68 [ V_69 ] ) {
V_19 = F_52 ( V_68 [ V_69 ] ) ;
V_20 = F_53 ( V_68 [ V_69 ] ) ;
V_54 = F_31 ( V_47 , V_69 , V_19 , V_20 , V_48 ) ;
if ( V_54 != 0 )
return V_54 ;
V_54 = F_39 ( V_47 , V_69 , V_19 , V_20 , V_48 ) ;
if ( V_54 )
return V_54 ;
}
}
return V_54 ;
}
static int F_54 ( struct V_71 * V_71 , struct V_57 * V_72 ,
struct V_57 * V_73 , struct V_63 * V_64 ,
int V_74 , int V_65 )
{
struct V_75 * V_76 = F_55 ( V_71 , V_77 ) ;
struct V_57 * V_68 [ V_78 + 1 ] ;
struct V_57 * V_79 [ V_80 + 1 ] ;
struct V_46 * V_47 ;
struct V_81 * V_82 ;
T_1 V_83 = 0 ;
T_4 * V_84 = NULL ;
T_4 * V_85 = NULL ;
int V_42 = 0 , V_48 = 0 ;
int V_39 ;
V_39 = F_56 ( V_68 , V_78 , V_72 , V_86 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ! V_68 [ V_87 ] )
return - V_21 ;
V_82 = F_52 ( V_68 [ V_87 ] ) ;
V_48 = F_57 ( V_76 , V_82 -> V_88 , V_64 , V_65 ) ;
if ( V_48 && V_65 )
return 0 ;
if ( V_82 -> V_89 & V_90 ) {
if ( ! V_68 [ V_91 ] ) {
if ( V_48 )
F_58 ( V_64 , V_65 ) ;
F_59 ( L_2 ) ;
return - V_21 ;
}
}
if ( ! V_48 ) {
V_42 = F_60 ( V_76 , V_82 -> V_88 , V_73 , V_64 , sizeof( * V_47 ) ,
V_65 , false ) ;
if ( V_42 )
return V_42 ;
V_42 = V_92 ;
} else {
F_58 ( V_64 , V_65 ) ;
if ( ! V_74 )
return - V_35 ;
}
V_47 = F_61 ( V_64 ) ;
V_47 -> V_89 = V_82 -> V_89 ;
if ( V_82 -> V_89 & V_90 ) {
V_83 = F_62 ( V_68 [ V_91 ] ) ;
if ( V_68 [ V_93 ] )
V_84 = F_52 ( V_68 [ V_93 ] ) ;
if ( V_68 [ V_94 ] )
V_85 = F_52 ( V_68 [ V_94 ] ) ;
}
if ( V_48 )
F_37 ( & V_47 -> V_49 ) ;
V_47 -> V_95 = V_82 -> V_96 ;
if ( V_82 -> V_89 & V_90 ) {
if ( V_84 )
F_63 ( V_47 -> V_97 , V_84 ) ;
else
F_64 ( V_47 -> V_97 ) ;
if ( V_85 )
F_63 ( V_47 -> V_98 , V_85 ) ;
else
F_64 ( V_47 -> V_98 ) ;
V_47 -> V_99 = V_83 ;
}
if ( V_42 == V_92 )
F_65 ( & V_47 -> V_53 ) ;
if ( V_68 [ V_61 ] ) {
V_39 = F_56 ( V_79 , V_80 , V_68 [ V_61 ] ,
NULL ) ;
if ( V_39 ) {
V_100:
if ( V_48 )
F_58 ( V_64 , V_65 ) ;
if ( V_42 == V_92 )
F_48 ( V_64 , V_65 ) ;
if ( V_48 )
F_33 ( & V_47 -> V_49 ) ;
return V_39 ;
}
V_39 = F_51 ( V_47 , V_79 , V_48 ) ;
if ( V_39 )
goto V_100;
} else {
V_39 = F_41 ( V_47 ) ;
if ( V_39 ) {
if ( V_42 == V_92 )
F_48 ( V_64 , V_65 ) ;
if ( V_48 )
F_33 ( & V_47 -> V_49 ) ;
return V_39 ;
}
}
if ( V_48 )
F_33 ( & V_47 -> V_49 ) ;
if ( V_42 == V_92 )
F_66 ( V_76 , V_64 ) ;
return V_42 ;
}
static int F_67 ( struct V_10 * V_11 , struct V_63 * V_64 , int V_65 ,
int V_101 )
{
unsigned char * V_59 = F_43 ( V_11 ) ;
struct V_46 * V_47 = V_64 -> V_66 ;
struct V_81 V_102 = {
. V_88 = V_47 -> V_103 ,
. V_104 = V_47 -> V_105 - V_101 ,
. V_106 = V_47 -> V_107 - V_65 ,
. V_96 = V_47 -> V_95 ,
. V_89 = V_47 -> V_89 ,
} ;
struct V_108 V_109 ;
if ( F_6 ( V_11 , V_87 , sizeof( V_102 ) , & V_102 ) )
goto V_110;
V_109 . V_111 = F_68 ( V_112 - V_47 -> V_113 . V_111 ) ;
V_109 . V_114 = F_68 ( V_112 - V_47 -> V_113 . V_114 ) ;
V_109 . V_115 = F_68 ( V_47 -> V_113 . V_115 ) ;
if ( F_69 ( V_11 , V_116 , sizeof( V_109 ) , & V_109 , V_117 ) )
goto V_110;
if ( ! F_70 ( V_47 -> V_97 ) ) {
if ( F_6 ( V_11 , V_93 , V_118 , V_47 -> V_97 ) )
goto V_110;
}
if ( ! F_70 ( V_47 -> V_98 ) ) {
if ( F_6 ( V_11 , V_94 , V_118 , V_47 -> V_98 ) )
goto V_110;
}
if ( F_6 ( V_11 , V_91 , 2 , & V_47 -> V_99 ) )
goto V_110;
if ( F_42 ( V_11 , V_47 ) ) {
F_59 ( L_3 ) ;
}
return V_11 -> V_20 ;
V_110:
F_47 ( V_11 , V_59 ) ;
return - 1 ;
}
int F_71 ( struct V_10 * V_11 , struct V_46 * V_47 ,
T_1 V_15 , T_1 V_119 , void * V_120 )
{
struct V_12 * V_56 ;
F_21 (e, &ife->metalist, metalist) {
if ( V_15 == V_56 -> V_15 ) {
if ( V_56 -> V_41 ) {
return V_56 -> V_41 -> V_32 ( V_11 , V_120 , V_119 ) ;
}
}
}
return 0 ;
}
static int F_72 ( struct V_10 * V_11 , const struct V_63 * V_64 ,
struct V_121 * V_122 )
{
struct V_46 * V_47 = V_64 -> V_66 ;
int V_96 = V_47 -> V_95 ;
struct V_123 * V_124 = (struct V_123 * ) V_11 -> V_125 ;
T_1 V_126 = V_124 -> V_127 ;
struct V_128 * V_5 = (struct V_128 * ) ( V_124 -> V_129 ) ;
F_73 ( & V_47 -> V_49 ) ;
F_74 ( & V_47 -> V_130 , V_11 ) ;
V_47 -> V_113 . V_114 = V_112 ;
F_75 ( & V_47 -> V_49 ) ;
V_126 = F_76 ( V_126 ) ;
if ( F_77 ( ! F_78 ( V_11 , V_126 ) ) ) {
F_73 ( & V_47 -> V_49 ) ;
V_47 -> V_131 . V_132 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_133 ;
}
F_79 ( V_11 , V_126 ) ;
F_80 ( V_11 , V_126 ) ;
V_11 -> V_134 = F_81 ( V_11 , V_11 -> V_135 ) ;
V_126 -= V_136 ;
while ( V_126 > 0 ) {
T_4 * V_137 = ( T_4 * ) V_5 ;
T_1 V_138 = V_5 -> type ;
T_1 V_119 = V_5 -> V_20 ;
V_138 = F_76 ( V_138 ) ;
V_119 = F_76 ( V_119 ) ;
if ( F_71 ( V_11 , V_47 , V_138 , ( V_119 - 4 ) ,
( void * ) ( V_137 + 4 ) ) ) {
F_82 ( L_4 ,
V_138 , V_119 ) ;
V_47 -> V_131 . V_139 ++ ;
}
V_137 += V_119 ;
V_126 -= V_119 ;
V_5 = (struct V_128 * ) V_137 ;
}
F_83 ( V_11 ) ;
return V_96 ;
}
static int F_84 ( struct V_10 * V_11 , struct V_46 * V_47 )
{
struct V_12 * V_56 , * V_67 ;
int V_140 = 0 , V_141 = 0 ;
F_49 (e, n, &ife->metalist, metalist) {
if ( V_56 -> V_41 -> V_30 ) {
V_141 = V_56 -> V_41 -> V_30 ( V_11 , V_56 ) ;
V_140 += V_141 ;
}
}
return V_140 ;
}
static int F_85 ( struct V_10 * V_11 , const struct V_63 * V_64 ,
struct V_121 * V_122 )
{
struct V_46 * V_47 = V_64 -> V_66 ;
int V_96 = V_47 -> V_95 ;
struct V_142 * V_143 ;
struct V_142 * V_144 ;
struct V_12 * V_56 ;
T_1 V_127 = F_84 ( V_11 , V_47 ) ;
int V_145 = V_127 + V_11 -> V_135 -> V_146 + V_136 ;
unsigned int V_147 = V_11 -> V_135 -> V_146 ;
T_2 V_148 = F_86 ( V_11 -> V_149 ) ;
int V_150 = V_11 -> V_20 + V_145 ;
bool V_151 = false ;
int V_39 ;
if ( V_148 & V_152 ) {
if ( V_150 > V_11 -> V_135 -> V_153 )
V_151 = true ;
}
F_73 ( & V_47 -> V_49 ) ;
F_74 ( & V_47 -> V_130 , V_11 ) ;
V_47 -> V_113 . V_114 = V_112 ;
if ( ! V_127 ) {
V_47 -> V_131 . V_139 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_96 ;
}
if ( ( V_96 == V_133 ) || V_151 ) {
V_47 -> V_131 . V_132 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_133 ;
}
V_144 = F_87 ( V_11 ) ;
V_39 = F_88 ( V_11 , V_145 ) ;
if ( F_77 ( V_39 ) ) {
V_47 -> V_131 . V_132 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_133 ;
}
if ( ! ( V_148 & V_152 ) )
F_89 ( V_11 , V_11 -> V_135 -> V_146 ) ;
F_90 ( V_11 , V_145 ) ;
memcpy ( V_11 -> V_125 , V_144 , V_11 -> V_154 ) ;
F_91 ( V_11 ) ;
V_143 = F_87 ( V_11 ) ;
V_127 += V_136 ;
V_127 = F_92 ( V_127 ) ;
memcpy ( ( V_11 -> V_125 + V_147 ) , & V_127 , V_136 ) ;
V_147 += V_136 ;
F_21 (e, &ife->metalist, metalist) {
if ( V_56 -> V_41 -> V_31 ) {
V_39 = V_56 -> V_41 -> V_31 ( V_11 , ( void * ) ( V_11 -> V_125 + V_147 ) ,
V_56 ) ;
}
if ( V_39 < 0 ) {
V_47 -> V_131 . V_132 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_133 ;
}
V_147 += V_39 ;
}
if ( ! F_70 ( V_47 -> V_98 ) )
F_63 ( V_143 -> V_155 , V_47 -> V_98 ) ;
else
F_63 ( V_143 -> V_155 , V_144 -> V_155 ) ;
if ( ! F_70 ( V_47 -> V_97 ) )
F_63 ( V_143 -> V_156 , V_47 -> V_97 ) ;
else
F_63 ( V_143 -> V_156 , V_144 -> V_156 ) ;
V_143 -> V_157 = F_92 ( V_47 -> V_99 ) ;
if ( ! ( V_148 & V_152 ) )
F_93 ( V_11 , V_11 -> V_135 -> V_146 ) ;
F_75 ( & V_47 -> V_49 ) ;
return V_96 ;
}
static int F_94 ( struct V_10 * V_11 , const struct V_63 * V_64 ,
struct V_121 * V_122 )
{
struct V_46 * V_47 = V_64 -> V_66 ;
if ( V_47 -> V_89 & V_90 )
return F_85 ( V_11 , V_64 , V_122 ) ;
if ( ! ( V_47 -> V_89 & V_90 ) )
return F_72 ( V_11 , V_64 , V_122 ) ;
F_82 ( L_5 ) ;
F_73 ( & V_47 -> V_49 ) ;
F_74 ( & V_47 -> V_130 , V_11 ) ;
V_47 -> V_113 . V_114 = V_112 ;
V_47 -> V_131 . V_132 ++ ;
F_75 ( & V_47 -> V_49 ) ;
return V_133 ;
}
static int F_95 ( struct V_71 * V_71 , struct V_10 * V_11 ,
struct V_158 * V_159 , int type ,
struct V_63 * V_64 )
{
struct V_75 * V_76 = F_55 ( V_71 , V_77 ) ;
return F_96 ( V_76 , V_11 , V_159 , type , V_64 ) ;
}
static int F_97 ( struct V_71 * V_71 , struct V_63 * V_64 , T_2 V_88 )
{
struct V_75 * V_76 = F_55 ( V_71 , V_77 ) ;
return F_98 ( V_76 , V_64 , V_88 ) ;
}
static T_5 int F_99 ( struct V_71 * V_71 )
{
struct V_75 * V_76 = F_55 ( V_71 , V_77 ) ;
return F_100 ( V_76 , & V_160 , V_161 ) ;
}
static void T_6 F_101 ( struct V_71 * V_71 )
{
struct V_75 * V_76 = F_55 ( V_71 , V_77 ) ;
F_102 ( V_76 ) ;
}
static int T_7 F_103 ( void )
{
return F_104 ( & V_160 , & V_162 ) ;
}
static void T_8 F_105 ( void )
{
F_106 ( & V_160 , & V_162 ) ;
}
