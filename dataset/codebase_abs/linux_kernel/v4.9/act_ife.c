int F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , const void * V_4 )
{
T_2 * V_5 = ( T_2 * ) ( V_1 ) ;
T_1 V_6 = F_2 ( V_3 ) ;
char * V_7 = ( char * ) V_5 + V_8 ;
T_2 V_9 = V_2 << 16 | ( V_3 + V_8 ) ;
* V_5 = F_3 ( V_9 ) ;
memset ( V_7 , 0 , V_6 - V_8 ) ;
memcpy ( V_7 , V_4 , V_3 ) ;
return V_6 ;
}
int F_4 ( T_1 V_10 , void * V_1 , struct V_11 * V_12 )
{
T_1 V_13 = 0 ;
if ( V_12 -> V_10 )
V_13 = * ( T_1 * ) V_12 -> V_10 ;
else if ( V_10 )
V_13 = V_10 ;
if ( ! V_13 )
return 0 ;
V_13 = F_5 ( V_13 ) ;
return F_1 ( V_1 , V_12 -> V_14 , 2 , & V_13 ) ;
}
int F_6 ( struct V_15 * V_16 , struct V_11 * V_12 )
{
if ( V_12 -> V_10 )
return F_7 ( V_16 , V_12 -> V_14 , * ( T_2 * ) V_12 -> V_10 ) ;
else
return F_8 ( V_16 , V_12 -> V_14 , 0 , NULL ) ;
}
int F_9 ( T_2 V_10 , struct V_11 * V_12 )
{
if ( V_10 || V_12 -> V_10 )
return 8 ;
return 0 ;
}
int F_10 ( T_1 V_10 , struct V_11 * V_12 )
{
if ( V_10 || V_12 -> V_10 )
return 8 ;
return 0 ;
}
int F_11 ( T_2 V_10 , void * V_1 , struct V_11 * V_12 )
{
T_2 V_13 = V_10 ;
if ( V_12 -> V_10 )
V_13 = * ( T_2 * ) V_12 -> V_10 ;
else if ( V_10 )
V_13 = V_10 ;
if ( ! V_13 )
return 0 ;
V_13 = F_3 ( V_13 ) ;
return F_1 ( V_1 , V_12 -> V_14 , 4 , & V_13 ) ;
}
int F_12 ( struct V_15 * V_16 , struct V_11 * V_12 )
{
if ( V_12 -> V_10 )
return F_13 ( V_16 , V_12 -> V_14 , * ( T_1 * ) V_12 -> V_10 ) ;
else
return F_8 ( V_16 , V_12 -> V_14 , 0 , NULL ) ;
}
int F_14 ( struct V_11 * V_12 , void * V_10 , T_3 V_17 )
{
V_12 -> V_10 = F_15 ( V_10 , sizeof( T_2 ) , V_17 ) ;
if ( ! V_12 -> V_10 )
return - V_18 ;
return 0 ;
}
int F_16 ( struct V_11 * V_12 , void * V_10 , T_3 V_17 )
{
V_12 -> V_10 = F_15 ( V_10 , sizeof( T_1 ) , V_17 ) ;
if ( ! V_12 -> V_10 )
return - V_18 ;
return 0 ;
}
void F_17 ( struct V_11 * V_12 )
{
F_18 ( V_12 -> V_10 ) ;
}
int F_19 ( void * V_19 , int V_20 )
{
if ( V_20 == sizeof( T_2 ) )
return 0 ;
return - V_21 ;
}
int F_20 ( void * V_19 , int V_20 )
{
if ( V_20 == sizeof( T_1 ) )
return 0 ;
return - V_21 ;
}
static struct V_22 * F_21 ( T_1 V_14 )
{
struct V_22 * V_23 ;
F_22 ( & V_24 ) ;
F_23 (o, &ifeoplist, list) {
if ( V_23 -> V_14 == V_14 ) {
if ( ! F_24 ( V_23 -> V_25 ) )
V_23 = NULL ;
F_25 ( & V_24 ) ;
return V_23 ;
}
}
F_25 ( & V_24 ) ;
return NULL ;
}
int F_26 ( struct V_22 * V_26 )
{
struct V_22 * V_27 ;
if ( ! V_26 -> V_14 || ! V_26 -> V_28 || ! V_26 -> V_29 ||
! V_26 -> V_30 || ! V_26 -> V_31 || ! V_26 -> V_32 ||
! V_26 -> V_33 || ! V_26 -> V_34 )
return - V_21 ;
F_27 ( & V_24 ) ;
F_23 (m, &ifeoplist, list) {
if ( V_27 -> V_14 == V_26 -> V_14 ||
( strcmp ( V_26 -> V_29 , V_27 -> V_29 ) == 0 ) ) {
F_28 ( & V_24 ) ;
return - V_35 ;
}
}
if ( ! V_26 -> V_36 )
V_26 -> V_36 = F_17 ;
F_29 ( & V_26 -> V_37 , & V_38 ) ;
F_28 ( & V_24 ) ;
return 0 ;
}
int F_30 ( struct V_22 * V_26 )
{
struct V_22 * V_27 ;
int V_39 = - V_40 ;
F_27 ( & V_24 ) ;
F_23 (m, &ifeoplist, list) {
if ( V_27 -> V_14 == V_26 -> V_14 ) {
F_31 ( & V_26 -> V_37 ) ;
V_39 = 0 ;
break;
}
}
F_28 ( & V_24 ) ;
return V_39 ;
}
static int F_32 ( struct V_22 * V_41 , void * V_19 , int V_20 )
{
int V_42 = 0 ;
if ( V_41 -> V_43 )
return V_41 -> V_43 ( V_19 , V_20 ) ;
if ( V_41 -> V_28 == V_44 )
V_42 = F_19 ( V_19 , V_20 ) ;
else if ( V_41 -> V_28 == V_45 )
V_42 = F_20 ( V_19 , V_20 ) ;
return V_42 ;
}
static int F_33 ( struct V_46 * V_47 , T_2 V_14 ,
void * V_19 , int V_20 , bool V_48 )
{
struct V_22 * V_41 = F_21 ( V_14 ) ;
int V_42 = 0 ;
if ( ! V_41 ) {
V_42 = - V_40 ;
#ifdef F_34
if ( V_48 )
F_35 ( & V_47 -> V_49 ) ;
F_36 () ;
F_37 ( L_1 , V_14 ) ;
F_38 () ;
if ( V_48 )
F_39 ( & V_47 -> V_49 ) ;
V_41 = F_21 ( V_14 ) ;
#endif
}
if ( V_41 ) {
V_42 = 0 ;
if ( V_20 )
V_42 = F_32 ( V_41 , V_19 , V_20 ) ;
F_40 ( V_41 -> V_25 ) ;
}
return V_42 ;
}
static int F_41 ( struct V_46 * V_47 , T_2 V_14 , void * V_10 ,
int V_20 , bool V_50 )
{
struct V_11 * V_12 = NULL ;
struct V_22 * V_41 = F_21 ( V_14 ) ;
int V_42 = 0 ;
if ( ! V_41 )
return - V_40 ;
V_12 = F_42 ( sizeof( * V_12 ) , V_50 ? V_51 : V_52 ) ;
if ( ! V_12 ) {
F_40 ( V_41 -> V_25 ) ;
return - V_18 ;
}
V_12 -> V_14 = V_14 ;
V_12 -> V_41 = V_41 ;
if ( V_20 > 0 ) {
V_42 = V_41 -> V_34 ( V_12 , V_10 , V_50 ? V_51 : V_52 ) ;
if ( V_42 != 0 ) {
F_18 ( V_12 ) ;
F_40 ( V_41 -> V_25 ) ;
return V_42 ;
}
}
F_29 ( & V_12 -> V_53 , & V_47 -> V_53 ) ;
return V_42 ;
}
static int F_43 ( struct V_46 * V_47 )
{
struct V_22 * V_23 ;
int V_54 = 0 ;
int V_55 = 0 ;
F_22 ( & V_24 ) ;
F_23 (o, &ifeoplist, list) {
V_54 = F_41 ( V_47 , V_23 -> V_14 , NULL , 0 , true ) ;
if ( V_54 == 0 )
V_55 += 1 ;
}
F_25 ( & V_24 ) ;
if ( V_55 )
return 0 ;
else
return - V_21 ;
}
static int F_44 ( struct V_15 * V_16 , struct V_46 * V_47 )
{
struct V_11 * V_56 ;
struct V_57 * V_58 ;
unsigned char * V_59 = F_45 ( V_16 ) ;
int V_60 = 0 ;
if ( F_46 ( & V_47 -> V_53 ) )
return 0 ;
V_58 = F_47 ( V_16 , V_61 ) ;
if ( ! V_58 )
goto V_62;
F_23 (e, &ife->metalist, metalist) {
if ( ! V_56 -> V_41 -> V_33 ( V_16 , V_56 ) )
V_60 += 1 ;
}
if ( ! V_60 )
goto V_62;
F_48 ( V_16 , V_58 ) ;
return 0 ;
V_62:
F_49 ( V_16 , V_59 ) ;
return - 1 ;
}
static void F_50 ( struct V_63 * V_64 , int V_65 )
{
struct V_46 * V_47 = F_51 ( V_64 ) ;
struct V_11 * V_56 , * V_66 ;
F_52 (e, n, &ife->metalist, metalist) {
F_40 ( V_56 -> V_41 -> V_25 ) ;
F_31 ( & V_56 -> V_53 ) ;
if ( V_56 -> V_10 ) {
if ( V_56 -> V_41 -> V_36 )
V_56 -> V_41 -> V_36 ( V_56 ) ;
else
F_18 ( V_56 -> V_10 ) ;
}
F_18 ( V_56 ) ;
}
}
static void F_53 ( struct V_63 * V_64 , int V_65 )
{
struct V_46 * V_47 = F_51 ( V_64 ) ;
F_39 ( & V_47 -> V_49 ) ;
F_50 ( V_64 , V_65 ) ;
F_35 ( & V_47 -> V_49 ) ;
}
static int F_54 ( struct V_46 * V_47 , struct V_57 * * V_67 ,
bool V_48 )
{
int V_20 = 0 ;
int V_54 = 0 ;
int V_68 = 0 ;
void * V_19 ;
for ( V_68 = 1 ; V_68 < V_69 ; V_68 ++ ) {
if ( V_67 [ V_68 ] ) {
V_19 = F_55 ( V_67 [ V_68 ] ) ;
V_20 = F_56 ( V_67 [ V_68 ] ) ;
V_54 = F_33 ( V_47 , V_68 , V_19 , V_20 , V_48 ) ;
if ( V_54 != 0 )
return V_54 ;
V_54 = F_41 ( V_47 , V_68 , V_19 , V_20 , V_48 ) ;
if ( V_54 )
return V_54 ;
}
}
return V_54 ;
}
static int F_57 ( struct V_70 * V_70 , struct V_57 * V_71 ,
struct V_57 * V_72 , struct V_63 * * V_64 ,
int V_73 , int V_65 )
{
struct V_74 * V_75 = F_58 ( V_70 , V_76 ) ;
struct V_57 * V_67 [ V_77 + 1 ] ;
struct V_57 * V_78 [ V_79 + 1 ] ;
struct V_46 * V_47 ;
struct V_80 * V_81 ;
T_1 V_82 = 0 ;
T_4 * V_83 = NULL ;
T_4 * V_84 = NULL ;
bool V_48 = false ;
int V_42 = 0 ;
int V_39 ;
V_39 = F_59 ( V_67 , V_77 , V_71 , V_85 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ! V_67 [ V_86 ] )
return - V_21 ;
V_81 = F_55 ( V_67 [ V_86 ] ) ;
V_48 = F_60 ( V_75 , V_81 -> V_87 , V_64 , V_65 ) ;
if ( V_48 && V_65 )
return 0 ;
if ( V_81 -> V_88 & V_89 ) {
if ( ! V_67 [ V_90 ] ) {
if ( V_48 )
F_61 ( * V_64 , V_65 ) ;
F_62 ( L_2 ) ;
return - V_21 ;
}
}
if ( ! V_48 ) {
V_42 = F_63 ( V_75 , V_81 -> V_87 , V_72 , V_64 , & V_91 ,
V_65 , false ) ;
if ( V_42 )
return V_42 ;
V_42 = V_92 ;
} else {
F_61 ( * V_64 , V_65 ) ;
if ( ! V_73 )
return - V_35 ;
}
V_47 = F_51 ( * V_64 ) ;
V_47 -> V_88 = V_81 -> V_88 ;
if ( V_81 -> V_88 & V_89 ) {
V_82 = F_64 ( V_67 [ V_90 ] ) ;
if ( V_67 [ V_93 ] )
V_83 = F_55 ( V_67 [ V_93 ] ) ;
if ( V_67 [ V_94 ] )
V_84 = F_55 ( V_67 [ V_94 ] ) ;
}
if ( V_48 )
F_39 ( & V_47 -> V_49 ) ;
V_47 -> V_95 = V_81 -> V_96 ;
if ( V_81 -> V_88 & V_89 ) {
if ( V_83 )
F_65 ( V_47 -> V_97 , V_83 ) ;
else
F_66 ( V_47 -> V_97 ) ;
if ( V_84 )
F_65 ( V_47 -> V_98 , V_84 ) ;
else
F_66 ( V_47 -> V_98 ) ;
V_47 -> V_99 = V_82 ;
}
if ( V_42 == V_92 )
F_67 ( & V_47 -> V_53 ) ;
if ( V_67 [ V_61 ] ) {
V_39 = F_59 ( V_78 , V_79 , V_67 [ V_61 ] ,
NULL ) ;
if ( V_39 ) {
V_100:
if ( V_48 )
F_61 ( * V_64 , V_65 ) ;
if ( V_42 == V_92 )
F_50 ( * V_64 , V_65 ) ;
if ( V_48 )
F_35 ( & V_47 -> V_49 ) ;
return V_39 ;
}
V_39 = F_54 ( V_47 , V_78 , V_48 ) ;
if ( V_39 )
goto V_100;
} else {
V_39 = F_43 ( V_47 ) ;
if ( V_39 ) {
if ( V_42 == V_92 )
F_50 ( * V_64 , V_65 ) ;
if ( V_48 )
F_35 ( & V_47 -> V_49 ) ;
return V_39 ;
}
}
if ( V_48 )
F_35 ( & V_47 -> V_49 ) ;
if ( V_42 == V_92 )
F_68 ( V_75 , * V_64 ) ;
return V_42 ;
}
static int F_69 ( struct V_15 * V_16 , struct V_63 * V_64 , int V_65 ,
int V_101 )
{
unsigned char * V_59 = F_45 ( V_16 ) ;
struct V_46 * V_47 = F_51 ( V_64 ) ;
struct V_80 V_102 = {
. V_87 = V_47 -> V_103 ,
. V_104 = V_47 -> V_105 - V_101 ,
. V_106 = V_47 -> V_107 - V_65 ,
. V_96 = V_47 -> V_95 ,
. V_88 = V_47 -> V_88 ,
} ;
struct V_108 V_109 ;
if ( F_8 ( V_16 , V_86 , sizeof( V_102 ) , & V_102 ) )
goto V_110;
F_70 ( & V_109 , & V_47 -> V_111 ) ;
if ( F_71 ( V_16 , V_112 , sizeof( V_109 ) , & V_109 , V_113 ) )
goto V_110;
if ( ! F_72 ( V_47 -> V_97 ) ) {
if ( F_8 ( V_16 , V_93 , V_114 , V_47 -> V_97 ) )
goto V_110;
}
if ( ! F_72 ( V_47 -> V_98 ) ) {
if ( F_8 ( V_16 , V_94 , V_114 , V_47 -> V_98 ) )
goto V_110;
}
if ( F_8 ( V_16 , V_90 , 2 , & V_47 -> V_99 ) )
goto V_110;
if ( F_44 ( V_16 , V_47 ) ) {
F_62 ( L_3 ) ;
}
return V_16 -> V_20 ;
V_110:
F_49 ( V_16 , V_59 ) ;
return - 1 ;
}
int F_73 ( struct V_15 * V_16 , struct V_46 * V_47 ,
T_1 V_14 , T_1 V_115 , void * V_116 )
{
struct V_11 * V_56 ;
F_23 (e, &ife->metalist, metalist) {
if ( V_14 == V_56 -> V_14 ) {
if ( V_56 -> V_41 ) {
return V_56 -> V_41 -> V_32 ( V_16 , V_116 , V_115 ) ;
}
}
}
return 0 ;
}
static int F_74 ( struct V_15 * V_16 , const struct V_63 * V_64 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = F_51 ( V_64 ) ;
int V_96 = V_47 -> V_95 ;
struct V_119 * V_120 = (struct V_119 * ) V_16 -> V_121 ;
int V_122 = ( int ) V_120 -> V_123 ;
struct V_124 * V_5 = (struct V_124 * ) ( V_120 -> V_125 ) ;
F_75 ( & V_47 -> V_49 ) ;
F_76 ( & V_47 -> V_126 , V_16 ) ;
F_77 ( & V_47 -> V_111 ) ;
F_78 ( & V_47 -> V_49 ) ;
V_122 = F_79 ( V_122 ) ;
if ( F_80 ( ! F_81 ( V_16 , V_122 ) ) ) {
F_75 ( & V_47 -> V_49 ) ;
V_47 -> V_127 . V_128 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_129 ;
}
F_82 ( V_16 , V_122 ) ;
F_83 ( V_16 , V_122 ) ;
V_16 -> V_130 = F_84 ( V_16 , V_16 -> V_131 ) ;
V_122 -= V_132 ;
while ( V_122 > 0 ) {
T_4 * V_133 = ( T_4 * ) V_5 ;
T_1 V_134 = V_5 -> type ;
T_1 V_115 = V_5 -> V_20 ;
T_1 V_135 ;
V_134 = F_79 ( V_134 ) ;
V_115 = F_79 ( V_115 ) ;
V_135 = F_85 ( V_115 ) ;
if ( F_73 ( V_16 , V_47 , V_134 , ( V_115 - V_8 ) ,
( void * ) ( V_133 + V_8 ) ) ) {
F_86 ( L_4 ,
V_134 , V_115 ) ;
V_47 -> V_127 . V_136 ++ ;
}
V_133 += V_135 ;
V_122 -= V_135 ;
V_5 = (struct V_124 * ) V_133 ;
}
F_87 ( V_16 ) ;
return V_96 ;
}
static int F_88 ( struct V_15 * V_16 , struct V_46 * V_47 )
{
struct V_11 * V_56 , * V_66 ;
int V_137 = 0 , V_138 = 0 ;
F_52 (e, n, &ife->metalist, metalist) {
if ( V_56 -> V_41 -> V_30 ) {
V_138 = V_56 -> V_41 -> V_30 ( V_16 , V_56 ) ;
V_137 += V_138 ;
}
}
return V_137 ;
}
static int F_89 ( struct V_15 * V_16 , const struct V_63 * V_64 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = F_51 ( V_64 ) ;
int V_96 = V_47 -> V_95 ;
struct V_139 * V_140 ;
struct V_139 * V_141 ;
struct V_11 * V_56 ;
T_1 V_123 = F_88 ( V_16 , V_47 ) ;
int V_142 = V_123 + V_16 -> V_131 -> V_143 + V_132 ;
unsigned int V_144 = V_16 -> V_131 -> V_143 ;
T_2 V_145 = F_90 ( V_16 -> V_146 ) ;
int V_147 = V_16 -> V_20 + V_142 ;
bool V_148 = false ;
int V_39 ;
if ( V_145 & V_149 ) {
if ( V_147 > V_16 -> V_131 -> V_150 )
V_148 = true ;
}
F_75 ( & V_47 -> V_49 ) ;
F_76 ( & V_47 -> V_126 , V_16 ) ;
F_77 ( & V_47 -> V_111 ) ;
if ( ! V_123 ) {
V_47 -> V_127 . V_136 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_96 ;
}
if ( ( V_96 == V_129 ) || V_148 ) {
V_47 -> V_127 . V_128 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_129 ;
}
V_39 = F_91 ( V_16 , V_142 ) ;
if ( F_80 ( V_39 ) ) {
V_47 -> V_127 . V_128 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_129 ;
}
if ( ! ( V_145 & V_149 ) )
F_92 ( V_16 , V_16 -> V_131 -> V_143 ) ;
V_141 = (struct V_139 * ) V_16 -> V_121 ;
F_93 ( V_16 , V_142 ) ;
memcpy ( V_16 -> V_121 , V_141 , V_16 -> V_151 ) ;
F_94 ( V_16 ) ;
V_140 = F_95 ( V_16 ) ;
V_123 += V_132 ;
V_123 = F_5 ( V_123 ) ;
memcpy ( ( V_16 -> V_121 + V_144 ) , & V_123 , V_132 ) ;
V_144 += V_132 ;
F_23 (e, &ife->metalist, metalist) {
if ( V_56 -> V_41 -> V_31 ) {
V_39 = V_56 -> V_41 -> V_31 ( V_16 , ( void * ) ( V_16 -> V_121 + V_144 ) ,
V_56 ) ;
}
if ( V_39 < 0 ) {
V_47 -> V_127 . V_128 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_129 ;
}
V_144 += V_39 ;
}
if ( ! F_72 ( V_47 -> V_98 ) )
F_65 ( V_140 -> V_152 , V_47 -> V_98 ) ;
else
F_65 ( V_140 -> V_152 , V_141 -> V_152 ) ;
if ( ! F_72 ( V_47 -> V_97 ) )
F_65 ( V_140 -> V_153 , V_47 -> V_97 ) ;
else
F_65 ( V_140 -> V_153 , V_141 -> V_153 ) ;
V_140 -> V_154 = F_5 ( V_47 -> V_99 ) ;
if ( ! ( V_145 & V_149 ) )
F_96 ( V_16 , V_16 -> V_131 -> V_143 ) ;
F_78 ( & V_47 -> V_49 ) ;
return V_96 ;
}
static int F_97 ( struct V_15 * V_16 , const struct V_63 * V_64 ,
struct V_117 * V_118 )
{
struct V_46 * V_47 = F_51 ( V_64 ) ;
if ( V_47 -> V_88 & V_89 )
return F_89 ( V_16 , V_64 , V_118 ) ;
if ( ! ( V_47 -> V_88 & V_89 ) )
return F_74 ( V_16 , V_64 , V_118 ) ;
F_86 ( L_5 ) ;
F_75 ( & V_47 -> V_49 ) ;
F_76 ( & V_47 -> V_126 , V_16 ) ;
F_77 ( & V_47 -> V_111 ) ;
V_47 -> V_127 . V_128 ++ ;
F_78 ( & V_47 -> V_49 ) ;
return V_129 ;
}
static int F_98 ( struct V_70 * V_70 , struct V_15 * V_16 ,
struct V_155 * V_156 , int type ,
const struct V_157 * V_41 )
{
struct V_74 * V_75 = F_58 ( V_70 , V_76 ) ;
return F_99 ( V_75 , V_16 , V_156 , type , V_41 ) ;
}
static int F_100 ( struct V_70 * V_70 , struct V_63 * * V_64 , T_2 V_87 )
{
struct V_74 * V_75 = F_58 ( V_70 , V_76 ) ;
return F_101 ( V_75 , V_64 , V_87 ) ;
}
static T_5 int F_102 ( struct V_70 * V_70 )
{
struct V_74 * V_75 = F_58 ( V_70 , V_76 ) ;
return F_103 ( V_75 , & V_91 , V_158 ) ;
}
static void T_6 F_104 ( struct V_70 * V_70 )
{
struct V_74 * V_75 = F_58 ( V_70 , V_76 ) ;
F_105 ( V_75 ) ;
}
static int T_7 F_106 ( void )
{
return F_107 ( & V_91 , & V_159 ) ;
}
static void T_8 F_108 ( void )
{
F_109 ( & V_91 , & V_159 ) ;
}
