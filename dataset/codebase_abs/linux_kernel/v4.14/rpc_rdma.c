static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 ;
V_1 += 2 ;
V_2 = V_1 * sizeof( struct V_4 ) ;
V_2 += sizeof( V_5 ) ;
V_2 += sizeof( struct V_6 ) ;
V_2 += sizeof( V_5 ) ;
F_2 ( L_1 ,
V_7 , V_2 ) ;
return V_2 ;
}
static unsigned int F_3 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 ;
V_1 += 2 ;
V_2 = sizeof( V_5 ) ;
V_2 += V_1 * sizeof( struct V_6 ) ;
V_2 += sizeof( V_5 ) ;
F_2 ( L_2 ,
V_7 , V_2 ) ;
return V_2 ;
}
void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = & V_9 -> V_15 ;
unsigned int V_1 = V_14 -> V_16 ;
V_14 -> V_17 = V_11 -> V_18 -
F_1 ( V_1 ) ;
V_14 -> V_19 = V_11 -> V_20 -
F_3 ( V_1 ) ;
}
static bool F_5 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
unsigned int V_26 , V_27 , V_28 ;
if ( V_24 -> V_29 > V_9 -> V_15 . V_17 )
return false ;
if ( V_24 -> V_30 ) {
V_27 = V_24 -> V_30 ;
V_28 = F_6 ( V_24 -> V_31 ) ;
V_26 = 0 ;
while ( V_27 ) {
V_27 -= F_7 (unsigned int,
PAGE_SIZE - offset, remaining) ;
V_28 = 0 ;
if ( ++ V_26 > V_9 -> V_15 . V_32 )
return false ;
}
}
return true ;
}
static bool F_8 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = & V_9 -> V_15 ;
return V_22 -> V_33 . V_34 <= V_14 -> V_19 ;
}
static struct V_35 *
F_9 ( struct V_36 * V_37 , struct V_35 * V_38 ,
unsigned int * V_39 )
{
T_1 V_27 , V_40 ;
char * V_41 ;
V_41 = V_37 -> V_42 ;
V_40 = F_6 ( V_41 ) ;
V_27 = V_37 -> V_43 ;
while ( V_27 ) {
V_38 -> V_44 = NULL ;
V_38 -> V_45 = V_41 ;
V_38 -> V_46 = F_7 ( T_1 , V_47 - V_40 , V_27 ) ;
V_27 -= V_38 -> V_46 ;
V_41 += V_38 -> V_46 ;
++ V_38 ;
++ ( * V_39 ) ;
V_40 = 0 ;
}
return V_38 ;
}
static int
F_10 ( struct V_8 * V_9 , struct V_23 * V_48 ,
unsigned int V_49 , enum V_50 type ,
struct V_35 * V_38 )
{
unsigned long V_31 ;
unsigned int V_29 , V_39 ;
struct V_51 * * V_52 ;
V_39 = 0 ;
if ( V_49 == 0 )
V_38 = F_9 ( & V_48 -> V_53 [ 0 ] , V_38 , & V_39 ) ;
V_29 = V_48 -> V_30 ;
V_52 = V_48 -> V_54 + ( V_48 -> V_31 >> V_55 ) ;
V_31 = F_6 ( V_48 -> V_31 ) ;
while ( V_29 ) {
if ( F_11 ( ! * V_52 ) ) {
* V_52 = F_12 ( V_56 ) ;
if ( ! * V_52 )
return - V_57 ;
}
V_38 -> V_44 = * V_52 ;
V_38 -> V_45 = ( char * ) V_31 ;
V_38 -> V_46 = F_7 ( T_1 , V_47 - V_31 , V_29 ) ;
V_29 -= V_38 -> V_46 ;
++ V_52 ;
++ V_38 ;
++ V_39 ;
V_31 = 0 ;
}
if ( type == V_58 && V_9 -> V_15 . V_59 )
goto V_60;
if ( type == V_61 && V_9 -> V_15 . V_59 )
goto V_60;
if ( V_48 -> V_62 [ 0 ] . V_43 )
V_38 = F_9 ( & V_48 -> V_62 [ 0 ] , V_38 , & V_39 ) ;
V_60:
if ( F_11 ( V_39 > V_63 ) )
return - V_64 ;
return V_39 ;
}
static inline int
F_13 ( struct V_65 * V_24 )
{
V_5 * V_66 ;
V_66 = F_14 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_67 ;
* V_66 = V_68 ;
return 0 ;
}
static inline int
F_15 ( struct V_65 * V_24 )
{
V_5 * V_66 ;
V_66 = F_14 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_67 ;
* V_66 = V_69 ;
return 0 ;
}
static void
F_16 ( V_5 * V_70 , struct V_71 * V_72 )
{
* V_70 ++ = F_17 ( V_72 -> V_73 ) ;
* V_70 ++ = F_17 ( V_72 -> V_74 ) ;
F_18 ( V_70 , V_72 -> V_75 ) ;
}
static int
F_19 ( struct V_65 * V_24 , struct V_71 * V_72 )
{
V_5 * V_66 ;
V_66 = F_14 ( V_24 , 4 * sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_67 ;
F_16 ( V_66 , V_72 ) ;
return 0 ;
}
static int
F_20 ( struct V_65 * V_24 , struct V_71 * V_72 ,
T_1 V_76 )
{
V_5 * V_66 ;
V_66 = F_14 ( V_24 , 6 * sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_67 ;
* V_66 ++ = V_68 ;
* V_66 ++ = F_17 ( V_76 ) ;
F_16 ( V_66 , V_72 ) ;
return 0 ;
}
static T_2 int
F_21 ( struct V_8 * V_9 , struct V_77 * V_78 ,
struct V_21 * V_22 , enum V_50 V_79 )
{
struct V_65 * V_24 = & V_78 -> V_80 ;
struct V_35 * V_38 ;
struct V_71 * V_72 ;
unsigned int V_49 ;
int V_81 ;
V_49 = V_22 -> V_25 . V_53 [ 0 ] . V_43 ;
if ( V_79 == V_82 )
V_49 = 0 ;
V_38 = V_78 -> V_83 ;
V_81 = F_10 ( V_9 , & V_22 -> V_25 , V_49 ,
V_79 , V_38 ) ;
if ( V_81 < 0 )
return V_81 ;
do {
V_38 = V_9 -> V_15 . V_84 -> V_85 ( V_9 , V_38 , V_81 ,
false , & V_72 ) ;
if ( F_22 ( V_38 ) )
return F_23 ( V_38 ) ;
F_24 ( V_72 , & V_78 -> V_86 ) ;
if ( F_20 ( V_24 , V_72 , V_49 ) < 0 )
return - V_67 ;
F_2 ( L_3 ,
V_22 -> V_87 -> V_88 , V_7 , V_49 ,
V_72 -> V_74 , ( unsigned long long ) V_72 -> V_75 ,
V_72 -> V_73 , V_72 -> V_89 < V_81 ? L_4 : L_5 ) ;
V_9 -> V_90 . V_91 ++ ;
V_81 -= V_72 -> V_89 ;
} while ( V_81 );
return 0 ;
}
static T_2 int
F_25 ( struct V_8 * V_9 , struct V_77 * V_78 ,
struct V_21 * V_22 , enum V_50 V_92 )
{
struct V_65 * V_24 = & V_78 -> V_80 ;
struct V_35 * V_38 ;
struct V_71 * V_72 ;
int V_81 , V_93 ;
V_5 * V_94 ;
V_38 = V_78 -> V_83 ;
V_81 = F_10 ( V_9 , & V_22 -> V_33 ,
V_22 -> V_33 . V_53 [ 0 ] . V_43 ,
V_92 , V_38 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( F_13 ( V_24 ) < 0 )
return - V_67 ;
V_94 = F_14 ( V_24 , sizeof( * V_94 ) ) ;
if ( F_11 ( ! V_94 ) )
return - V_67 ;
V_93 = 0 ;
do {
V_38 = V_9 -> V_15 . V_84 -> V_85 ( V_9 , V_38 , V_81 ,
true , & V_72 ) ;
if ( F_22 ( V_38 ) )
return F_23 ( V_38 ) ;
F_24 ( V_72 , & V_78 -> V_86 ) ;
if ( F_19 ( V_24 , V_72 ) < 0 )
return - V_67 ;
F_2 ( L_6 ,
V_22 -> V_87 -> V_88 , V_7 ,
V_72 -> V_74 , ( unsigned long long ) V_72 -> V_75 ,
V_72 -> V_73 , V_72 -> V_89 < V_81 ? L_4 : L_5 ) ;
V_9 -> V_90 . V_95 ++ ;
V_9 -> V_90 . V_96 += V_38 -> V_46 ;
V_93 ++ ;
V_81 -= V_72 -> V_89 ;
} while ( V_81 );
* V_94 = F_17 ( V_93 ) ;
return 0 ;
}
static T_2 int
F_26 ( struct V_8 * V_9 , struct V_77 * V_78 ,
struct V_21 * V_22 , enum V_50 V_92 )
{
struct V_65 * V_24 = & V_78 -> V_80 ;
struct V_35 * V_38 ;
struct V_71 * V_72 ;
int V_81 , V_93 ;
V_5 * V_94 ;
V_38 = V_78 -> V_83 ;
V_81 = F_10 ( V_9 , & V_22 -> V_33 , 0 , V_92 , V_38 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( F_13 ( V_24 ) < 0 )
return - V_67 ;
V_94 = F_14 ( V_24 , sizeof( * V_94 ) ) ;
if ( F_11 ( ! V_94 ) )
return - V_67 ;
V_93 = 0 ;
do {
V_38 = V_9 -> V_15 . V_84 -> V_85 ( V_9 , V_38 , V_81 ,
true , & V_72 ) ;
if ( F_22 ( V_38 ) )
return F_23 ( V_38 ) ;
F_24 ( V_72 , & V_78 -> V_86 ) ;
if ( F_19 ( V_24 , V_72 ) < 0 )
return - V_67 ;
F_2 ( L_7 ,
V_22 -> V_87 -> V_88 , V_7 ,
V_72 -> V_74 , ( unsigned long long ) V_72 -> V_75 ,
V_72 -> V_73 , V_72 -> V_89 < V_81 ? L_4 : L_5 ) ;
V_9 -> V_90 . V_97 ++ ;
V_9 -> V_90 . V_96 += V_38 -> V_46 ;
V_93 ++ ;
V_81 -= V_72 -> V_89 ;
} while ( V_81 );
* V_94 = F_17 ( V_93 ) ;
return 0 ;
}
static bool
F_27 ( struct V_13 * V_14 , struct V_77 * V_78 ,
T_1 V_29 )
{
struct V_98 * V_99 = V_78 -> V_100 ;
struct V_101 * V_102 = & V_78 -> V_103 [ 0 ] ;
if ( F_11 ( ! F_28 ( V_99 ) ) ) {
if ( ! F_29 ( V_14 , V_99 ) )
return false ;
V_102 -> V_104 = F_30 ( V_99 ) ;
V_102 -> V_105 = F_31 ( V_99 ) ;
}
V_102 -> V_106 = V_29 ;
F_32 ( F_33 ( V_99 ) , V_102 -> V_104 ,
V_102 -> V_106 , V_107 ) ;
V_78 -> V_108 . V_109 ++ ;
return true ;
}
static bool
F_34 ( struct V_13 * V_14 , struct V_77 * V_78 ,
struct V_23 * V_24 , enum V_50 V_79 )
{
unsigned int V_110 , V_31 , V_29 , V_27 ;
struct V_98 * V_99 = V_78 -> V_111 ;
struct V_112 * V_113 = V_14 -> V_114 ;
struct V_101 * V_102 = V_78 -> V_103 ;
T_1 V_105 = V_14 -> V_115 -> V_116 ;
struct V_51 * V_51 , * * V_52 ;
if ( ! F_35 ( V_14 , V_99 ) )
return false ;
V_110 = 1 ;
V_102 [ V_110 ] . V_104 = F_30 ( V_99 ) ;
V_102 [ V_110 ] . V_106 = V_24 -> V_53 [ 0 ] . V_43 ;
V_102 [ V_110 ] . V_105 = F_31 ( V_99 ) ;
F_32 ( F_33 ( V_99 ) , V_102 [ V_110 ] . V_104 ,
V_102 [ V_110 ] . V_106 , V_107 ) ;
if ( V_79 == V_58 ) {
V_29 = V_24 -> V_62 [ 0 ] . V_43 ;
if ( V_29 < 4 )
goto V_60;
V_51 = F_36 ( V_24 -> V_62 [ 0 ] . V_42 ) ;
V_31 = F_6 ( V_24 -> V_62 [ 0 ] . V_42 ) ;
V_31 += V_29 & 3 ;
V_29 -= V_29 & 3 ;
goto V_117;
}
if ( V_24 -> V_30 ) {
V_52 = V_24 -> V_54 + ( V_24 -> V_31 >> V_55 ) ;
V_31 = F_6 ( V_24 -> V_31 ) ;
V_27 = V_24 -> V_30 ;
while ( V_27 ) {
V_110 ++ ;
if ( V_110 > V_118 - 2 )
goto V_119;
V_29 = F_7 ( T_1 , V_47 - V_31 , V_27 ) ;
V_102 [ V_110 ] . V_104 = F_37 ( V_113 , * V_52 ,
V_31 , V_29 ,
V_107 ) ;
if ( F_38 ( V_113 , V_102 [ V_110 ] . V_104 ) )
goto V_120;
V_102 [ V_110 ] . V_106 = V_29 ;
V_102 [ V_110 ] . V_105 = V_105 ;
V_78 -> V_121 ++ ;
V_52 ++ ;
V_27 -= V_29 ;
V_31 = 0 ;
}
}
if ( V_24 -> V_62 [ 0 ] . V_43 ) {
V_51 = F_36 ( V_24 -> V_62 [ 0 ] . V_42 ) ;
V_31 = F_6 ( V_24 -> V_62 [ 0 ] . V_42 ) ;
V_29 = V_24 -> V_62 [ 0 ] . V_43 ;
V_117:
V_110 ++ ;
V_102 [ V_110 ] . V_104 = F_37 ( V_113 , V_51 ,
V_31 , V_29 ,
V_107 ) ;
if ( F_38 ( V_113 , V_102 [ V_110 ] . V_104 ) )
goto V_120;
V_102 [ V_110 ] . V_106 = V_29 ;
V_102 [ V_110 ] . V_105 = V_105 ;
V_78 -> V_121 ++ ;
}
V_60:
V_78 -> V_108 . V_109 = V_110 + 1 ;
return true ;
V_119:
F_39 ( L_8 , V_110 ) ;
return false ;
V_120:
F_39 ( L_9 ) ;
return false ;
}
bool
F_40 ( struct V_13 * V_14 , struct V_77 * V_78 ,
T_1 V_122 , struct V_23 * V_24 ,
enum V_50 V_79 )
{
V_78 -> V_108 . V_109 = 0 ;
V_78 -> V_121 = 0 ;
if ( ! F_27 ( V_14 , V_78 , V_122 ) )
goto V_123;
if ( V_79 != V_82 )
if ( ! F_34 ( V_14 , V_78 , V_24 , V_79 ) )
goto V_123;
return true ;
V_123:
F_39 ( L_10 ) ;
return false ;
}
void
F_41 ( struct V_13 * V_14 , struct V_77 * V_78 )
{
struct V_112 * V_113 = V_14 -> V_114 ;
struct V_101 * V_102 ;
int V_26 ;
V_102 = & V_78 -> V_103 [ 2 ] ;
for ( V_26 = V_78 -> V_121 ; V_26 -- ; V_102 ++ )
F_42 ( V_113 , V_102 -> V_104 , V_102 -> V_106 ,
V_107 ) ;
V_78 -> V_121 = 0 ;
}
int
F_43 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
struct V_77 * V_78 = F_44 ( V_22 ) ;
struct V_65 * V_24 = & V_78 -> V_80 ;
enum V_50 V_79 , V_92 ;
bool V_124 ;
V_5 * V_66 ;
int V_125 ;
#if F_45 ( V_126 )
if ( F_46 ( V_127 , & V_22 -> V_128 ) )
return F_47 ( V_22 ) ;
#endif
F_48 ( & V_78 -> V_129 , 0 ) ;
F_49 ( V_24 , & V_78 -> V_129 ,
V_78 -> V_100 -> V_130 ) ;
V_125 = - V_67 ;
V_66 = F_14 ( V_24 , 4 * sizeof( * V_66 ) ) ;
if ( ! V_66 )
goto V_131;
* V_66 ++ = V_22 -> V_132 ;
* V_66 ++ = V_133 ;
* V_66 ++ = F_17 ( V_9 -> V_134 . V_135 ) ;
V_124 = ! ( V_22 -> V_136 -> V_137 -> V_138 &
V_139 ) ;
if ( F_8 ( V_9 , V_22 ) )
V_92 = V_140 ;
else if ( V_124 && V_22 -> V_33 . V_141 & V_142 )
V_92 = V_61 ;
else
V_92 = V_143 ;
if ( F_5 ( V_9 , V_22 ) ) {
* V_66 ++ = V_144 ;
V_79 = V_140 ;
} else if ( V_124 && V_22 -> V_25 . V_141 & V_145 ) {
* V_66 ++ = V_144 ;
V_79 = V_58 ;
} else {
V_9 -> V_90 . V_146 ++ ;
* V_66 ++ = V_147 ;
V_79 = V_82 ;
}
if ( V_79 != V_140 ) {
V_125 = F_21 ( V_9 , V_78 , V_22 , V_79 ) ;
if ( V_125 )
goto V_131;
}
V_125 = F_15 ( V_24 ) ;
if ( V_125 )
goto V_131;
if ( V_92 == V_61 ) {
V_125 = F_25 ( V_9 , V_78 , V_22 , V_92 ) ;
if ( V_125 )
goto V_131;
}
V_125 = F_15 ( V_24 ) ;
if ( V_125 )
goto V_131;
if ( V_92 != V_143 )
V_125 = F_15 ( V_24 ) ;
else
V_125 = F_26 ( V_9 , V_78 , V_22 , V_92 ) ;
if ( V_125 )
goto V_131;
F_2 ( L_11 ,
V_22 -> V_87 -> V_88 , V_7 ,
V_148 [ V_79 ] , V_148 [ V_92 ] ,
F_50 ( V_24 ) ) ;
if ( ! F_40 ( & V_9 -> V_15 , V_78 ,
F_50 ( V_24 ) ,
& V_22 -> V_25 , V_79 ) ) {
V_125 = - V_64 ;
goto V_131;
}
return 0 ;
V_131:
if ( V_125 != - V_149 ) {
F_39 ( L_12 , V_125 ) ;
V_9 -> V_90 . V_150 ++ ;
}
return V_125 ;
}
static unsigned long
F_51 ( struct V_21 * V_22 , char * V_151 , int V_152 , int V_153 )
{
unsigned long V_154 ;
int V_155 , V_156 , V_157 ;
char * V_158 ;
struct V_51 * * V_52 ;
int V_31 ;
V_22 -> V_33 . V_53 [ 0 ] . V_42 = V_151 ;
V_22 -> V_159 . V_53 [ 0 ] . V_42 = V_151 ;
V_157 = V_22 -> V_33 . V_53 [ 0 ] . V_43 ;
if ( V_157 > V_152 )
V_157 = V_152 ;
F_2 ( L_13 ,
V_7 , V_151 , V_152 , V_157 ) ;
V_151 += V_157 ;
V_152 -= V_157 ;
V_52 = V_22 -> V_33 . V_54 +
( V_22 -> V_33 . V_31 >> V_55 ) ;
V_31 = F_6 ( V_22 -> V_33 . V_31 ) ;
V_154 = 0 ;
if ( V_152 && V_22 -> V_33 . V_30 ) {
int V_160 ;
V_160 = V_22 -> V_33 . V_30 ;
if ( V_160 > V_152 )
V_160 = V_152 ;
V_156 = F_52 ( V_31 + V_160 ) >> V_55 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ ) {
V_157 = V_47 - V_31 ;
if ( V_157 > V_160 )
V_157 = V_160 ;
F_2 ( L_14
L_15 ,
V_7 , V_155 , V_151 , V_152 , V_157 ) ;
V_158 = F_53 ( V_52 [ V_155 ] ) ;
memcpy ( V_158 + V_31 , V_151 , V_157 ) ;
F_54 ( V_52 [ V_155 ] ) ;
F_55 ( V_158 ) ;
V_151 += V_157 ;
V_152 -= V_157 ;
V_154 += V_157 ;
V_160 -= V_157 ;
if ( ! V_160 )
break;
V_31 = 0 ;
}
if ( V_153 )
V_151 -= V_153 ;
}
if ( V_152 || V_153 ) {
V_22 -> V_33 . V_62 [ 0 ] . V_42 = V_151 ;
V_22 -> V_159 . V_62 [ 0 ] . V_42 = V_151 ;
}
return V_154 ;
}
static void
F_56 ( struct V_161 * V_162 ,
struct V_163 * V_164 )
{
struct V_71 * V_72 ;
if ( ! ( V_164 -> V_165 & V_166 ) )
return;
F_57 (mw, mws, mw_list)
if ( V_72 -> V_73 == V_164 -> V_167 ) {
V_72 -> V_168 = V_169 ;
break;
}
}
static bool
F_58 ( struct V_8 * V_9 , struct V_163 * V_164 ,
V_5 V_170 , V_5 V_171 )
#if F_45 ( V_126 )
{
struct V_65 * V_24 = & V_164 -> V_172 ;
V_5 * V_66 ;
if ( V_171 != V_144 )
return false ;
V_66 = F_59 ( V_24 , 0 ) ;
if ( * V_66 ++ != V_69 )
return false ;
if ( * V_66 ++ != V_69 )
return false ;
if ( * V_66 ++ != V_69 )
return false ;
if ( * V_66 ++ != V_170 )
return false ;
if ( * V_66 != F_17 ( V_173 ) )
return false ;
V_66 = F_59 ( V_24 , 3 * sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
goto V_174;
F_60 ( V_9 , V_164 ) ;
return true ;
V_174:
F_61 ( L_16 ) ;
if ( F_62 ( & V_9 -> V_15 , V_164 ) )
F_63 ( & V_9 -> V_175 ) ;
return true ;
}
static int F_64 ( struct V_65 * V_24 , T_1 * V_106 )
{
V_5 * V_66 ;
V_66 = F_59 ( V_24 , 4 * sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
F_65 (FACILITY) {
T_3 V_28 ;
T_1 V_176 ;
V_176 = F_66 ( V_66 ++ ) ;
* V_106 = F_66 ( V_66 ++ ) ;
F_67 ( V_66 , & V_28 ) ;
F_2 ( L_17 ,
V_7 , * V_106 , ( unsigned long long ) V_28 ,
V_176 ) ;
} else {
* V_106 = F_66 ( V_66 + 1 ) ;
}
return 0 ;
}
static int F_68 ( struct V_65 * V_24 , T_1 * V_106 )
{
T_1 V_94 , V_177 ;
V_5 * V_66 ;
V_66 = F_59 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
* V_106 = 0 ;
V_94 = F_66 ( V_66 ) ;
while ( V_94 -- ) {
if ( F_64 ( V_24 , & V_177 ) )
return - V_64 ;
* V_106 += V_177 ;
}
F_2 ( L_18 ,
V_7 , F_66 ( V_66 ) , * V_106 ) ;
return 0 ;
}
static int F_69 ( struct V_65 * V_24 )
{
V_5 * V_66 ;
V_66 = F_59 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
if ( F_11 ( * V_66 != V_69 ) )
return - V_64 ;
return 0 ;
}
static int F_70 ( struct V_65 * V_24 , T_1 * V_106 )
{
T_1 V_178 ;
bool V_179 ;
V_5 * V_66 ;
* V_106 = 0 ;
V_179 = true ;
do {
V_66 = F_59 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
if ( * V_66 == V_69 )
break;
if ( ! V_179 )
return - V_64 ;
if ( F_68 ( V_24 , & V_178 ) )
return - V_64 ;
* V_106 += V_178 ;
V_179 = false ;
} while ( true );
return 0 ;
}
static int F_71 ( struct V_65 * V_24 , T_1 * V_106 )
{
V_5 * V_66 ;
V_66 = F_59 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
* V_106 = 0 ;
if ( * V_66 != V_69 )
if ( F_68 ( V_24 , V_106 ) )
return - V_64 ;
return 0 ;
}
static int
F_72 ( struct V_8 * V_9 , struct V_163 * V_164 ,
struct V_21 * V_22 )
{
struct V_65 * V_24 = & V_164 -> V_172 ;
T_1 V_180 , V_181 , V_182 ;
char * V_41 ;
if ( F_69 ( V_24 ) )
return - V_64 ;
if ( F_70 ( V_24 , & V_180 ) )
return - V_64 ;
if ( F_71 ( V_24 , & V_181 ) )
return - V_64 ;
if ( F_11 ( V_181 ) )
return - V_64 ;
V_41 = ( char * ) F_59 ( V_24 , 0 ) ;
V_182 = F_73 ( V_24 ) ;
V_9 -> V_90 . V_154 +=
F_51 ( V_22 , V_41 , V_182 , V_180 & 3 ) ;
V_9 -> V_90 . V_183 += V_180 ;
return V_182 + F_74 ( V_180 ) ;
}
static T_2 int
F_75 ( struct V_8 * V_9 , struct V_163 * V_164 )
{
struct V_65 * V_24 = & V_164 -> V_172 ;
T_1 V_180 , V_181 ;
if ( F_69 ( V_24 ) )
return - V_64 ;
if ( F_70 ( V_24 , & V_180 ) )
return - V_64 ;
if ( F_71 ( V_24 , & V_181 ) )
return - V_64 ;
if ( F_11 ( V_180 ) )
return - V_64 ;
if ( F_11 ( ! V_181 ) )
return - V_64 ;
V_9 -> V_90 . V_183 += V_181 ;
return V_181 ;
}
static T_2 int
F_76 ( struct V_8 * V_9 , struct V_163 * V_164 ,
struct V_21 * V_22 )
{
struct V_65 * V_24 = & V_164 -> V_172 ;
V_5 * V_66 ;
V_66 = F_59 ( V_24 , sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
return - V_64 ;
switch ( * V_66 ) {
case V_184 :
V_66 = F_59 ( V_24 , 2 * sizeof( * V_66 ) ) ;
if ( ! V_66 )
break;
F_2 ( L_19 ,
V_22 -> V_87 -> V_88 , V_7 ,
F_66 ( V_66 ) , F_77 ( * ( V_66 + 1 ) ) ) ;
break;
case V_185 :
F_2 ( L_20 ,
V_22 -> V_87 -> V_88 , V_7 ) ;
break;
default:
F_2 ( L_21 ,
V_22 -> V_87 -> V_88 , V_7 , F_66 ( V_66 ) ) ;
}
V_9 -> V_90 . V_186 ++ ;
return - V_187 ;
}
void
F_78 ( struct V_188 * V_189 )
{
struct V_163 * V_164 =
F_79 ( V_189 , struct V_163 , V_190 ) ;
struct V_8 * V_9 = V_164 -> V_191 ;
struct V_192 * V_193 = & V_9 -> V_175 ;
struct V_65 * V_24 = & V_164 -> V_172 ;
struct V_77 * V_78 ;
struct V_21 * V_22 ;
V_5 * V_66 , V_170 , V_194 , V_171 ;
unsigned long V_195 ;
int V_196 ;
F_2 ( L_22 , V_7 , V_164 ) ;
if ( V_164 -> V_197 . V_53 [ 0 ] . V_43 == 0 )
goto V_198;
F_80 ( V_24 , & V_164 -> V_197 ,
V_164 -> V_197 . V_53 [ 0 ] . V_42 ) ;
V_66 = F_59 ( V_24 , 4 * sizeof( * V_66 ) ) ;
if ( F_11 ( ! V_66 ) )
goto V_199;
V_170 = * V_66 ++ ;
V_194 = * V_66 ++ ;
V_66 ++ ;
V_171 = * V_66 ++ ;
if ( F_58 ( V_9 , V_164 , V_170 , V_171 ) )
return;
F_81 ( & V_193 -> V_200 ) ;
V_22 = F_82 ( V_193 , V_170 ) ;
if ( ! V_22 )
goto V_201;
F_83 ( V_22 ) ;
F_84 ( & V_193 -> V_200 ) ;
V_78 = F_44 ( V_22 ) ;
V_78 -> V_202 = V_164 ;
F_2 ( L_23 ,
V_7 , V_164 , V_78 , F_77 ( V_170 ) ) ;
if ( ! F_85 ( & V_78 -> V_86 ) ) {
F_56 ( & V_78 -> V_86 , V_164 ) ;
V_9 -> V_15 . V_84 -> V_203 ( V_9 ,
& V_78 -> V_86 ) ;
}
V_193 -> V_204 = 0 ;
if ( V_194 != V_133 )
goto V_205;
switch ( V_171 ) {
case V_144 :
V_196 = F_72 ( V_9 , V_164 , V_22 ) ;
break;
case V_147 :
V_196 = F_75 ( V_9 , V_164 ) ;
break;
case V_206 :
V_196 = F_76 ( V_9 , V_164 , V_22 ) ;
break;
default:
V_196 = - V_64 ;
}
if ( V_196 < 0 )
goto V_207;
V_60:
F_81 ( & V_193 -> V_200 ) ;
V_195 = V_193 -> V_195 ;
V_193 -> V_195 = F_86 ( & V_9 -> V_134 . V_208 ) << V_209 ;
if ( V_193 -> V_195 > V_195 )
F_87 ( V_22 -> V_87 ) ;
F_88 ( V_22 -> V_87 , V_196 ) ;
F_89 ( V_22 ) ;
F_84 ( & V_193 -> V_200 ) ;
F_2 ( L_24 ,
V_7 , V_193 , V_22 , V_196 ) ;
return;
V_198:
F_90 ( V_164 ) ;
if ( V_9 -> V_210 . V_211 == 1 ) {
V_9 -> V_210 . V_211 = - V_64 ;
F_91 ( & V_9 -> V_210 ) ;
}
return;
V_205:
F_2 ( L_25 ,
V_7 , F_77 ( V_194 ) ) ;
V_196 = - V_64 ;
V_9 -> V_90 . V_186 ++ ;
goto V_60;
V_207:
F_2 ( L_26 ,
V_22 -> V_87 -> V_88 , V_7 , F_77 ( V_171 ) ) ;
V_9 -> V_90 . V_186 ++ ;
V_196 = - V_64 ;
goto V_60;
V_201:
F_84 ( & V_193 -> V_200 ) ;
F_2 ( L_27 ,
V_7 , F_77 ( V_170 ) ) ;
goto V_212;
V_199:
F_2 ( L_28 , V_7 ) ;
goto V_212;
V_212:
V_9 -> V_90 . V_186 ++ ;
if ( F_62 ( & V_9 -> V_15 , V_164 ) )
F_90 ( V_164 ) ;
}
