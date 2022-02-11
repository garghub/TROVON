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
V_28 = V_24 -> V_31 & ~ V_32 ;
V_26 = 0 ;
while ( V_27 ) {
V_27 -= F_6 (unsigned int,
PAGE_SIZE - offset, remaining) ;
V_28 = 0 ;
if ( ++ V_26 > V_9 -> V_15 . V_33 )
return false ;
}
}
return true ;
}
static bool F_7 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = & V_9 -> V_15 ;
return V_22 -> V_34 . V_35 <= V_14 -> V_19 ;
}
static int
F_8 ( struct V_36 * V_37 , struct V_38 * V_39 , int V_40 )
{
T_1 V_41 ;
T_2 V_27 ;
char * V_42 ;
V_42 = V_37 -> V_43 ;
V_41 = F_9 ( V_42 ) ;
V_27 = V_37 -> V_44 ;
while ( V_27 && V_40 < V_45 ) {
V_39 [ V_40 ] . V_46 = NULL ;
V_39 [ V_40 ] . V_47 = V_42 ;
V_39 [ V_40 ] . V_48 = F_6 ( T_2 , V_49 - V_41 , V_27 ) ;
V_27 -= V_39 [ V_40 ] . V_48 ;
V_42 += V_39 [ V_40 ] . V_48 ;
++ V_40 ;
V_41 = 0 ;
}
return V_40 ;
}
static int
F_10 ( struct V_8 * V_9 , struct V_23 * V_50 ,
unsigned int V_51 , enum V_52 type ,
struct V_38 * V_39 )
{
int V_29 , V_40 , V_53 , V_31 ;
struct V_54 * * V_55 ;
V_40 = 0 ;
if ( V_51 == 0 ) {
V_40 = F_8 ( & V_50 -> V_56 [ 0 ] , V_39 , V_40 ) ;
if ( V_40 == V_45 )
goto V_57;
}
V_29 = V_50 -> V_30 ;
V_55 = V_50 -> V_58 + ( V_50 -> V_31 >> V_59 ) ;
V_31 = V_50 -> V_31 & ~ V_32 ;
V_53 = 0 ;
while ( V_29 && V_40 < V_45 ) {
if ( ! V_55 [ V_53 ] ) {
V_55 [ V_53 ] = F_11 ( V_60 ) ;
if ( ! V_55 [ V_53 ] )
return - V_61 ;
}
V_39 [ V_40 ] . V_46 = V_55 [ V_53 ] ;
V_39 [ V_40 ] . V_47 = ( void * ) ( unsigned long ) V_31 ;
V_39 [ V_40 ] . V_48 = F_6 ( T_2 , V_49 - V_31 , V_29 ) ;
if ( V_39 [ V_40 ] . V_48 > V_49 )
goto V_57;
V_29 -= V_39 [ V_40 ] . V_48 ;
++ V_40 ;
++ V_53 ;
V_31 = 0 ;
}
if ( V_29 && V_40 == V_45 )
goto V_57;
if ( type == V_62 && V_9 -> V_15 . V_63 )
return V_40 ;
if ( type == V_64 && V_9 -> V_15 . V_63 )
return V_40 ;
if ( V_50 -> V_65 [ 0 ] . V_44 ) {
V_40 = F_8 ( & V_50 -> V_65 [ 0 ] , V_39 , V_40 ) ;
if ( V_40 == V_45 )
goto V_57;
}
return V_40 ;
V_57:
F_12 ( L_3 ) ;
return - V_66 ;
}
static inline V_5 *
F_13 ( V_5 * V_67 , struct V_68 * V_69 )
{
* V_67 ++ = F_14 ( V_69 -> V_70 ) ;
* V_67 ++ = F_14 ( V_69 -> V_71 ) ;
return F_15 ( V_67 , V_69 -> V_72 ) ;
}
static V_5 *
F_16 ( struct V_8 * V_9 ,
struct V_73 * V_74 , struct V_21 * V_22 ,
V_5 * V_67 , enum V_52 V_75 )
{
struct V_38 * V_39 ;
struct V_68 * V_69 ;
unsigned int V_51 ;
int V_40 , V_76 ;
if ( V_75 == V_77 ) {
* V_67 ++ = V_78 ;
return V_67 ;
}
V_51 = V_22 -> V_25 . V_56 [ 0 ] . V_44 ;
if ( V_75 == V_79 )
V_51 = 0 ;
V_39 = V_74 -> V_80 ;
V_76 = F_10 ( V_9 , & V_22 -> V_25 , V_51 ,
V_75 , V_39 ) ;
if ( V_76 < 0 )
return F_17 ( V_76 ) ;
do {
V_40 = V_9 -> V_15 . V_81 -> V_82 ( V_9 , V_39 , V_76 ,
false , & V_69 ) ;
if ( V_40 < 0 )
return F_17 ( V_40 ) ;
F_18 ( V_69 , & V_74 -> V_83 ) ;
* V_67 ++ = V_84 ;
* V_67 ++ = F_14 ( V_51 ) ;
V_67 = F_13 ( V_67 , V_69 ) ;
F_2 ( L_4 ,
V_22 -> V_85 -> V_86 , V_7 , V_51 ,
V_69 -> V_71 , ( unsigned long long ) V_69 -> V_72 ,
V_69 -> V_70 , V_40 < V_76 ? L_5 : L_6 ) ;
V_9 -> V_87 . V_88 ++ ;
V_39 += V_40 ;
V_76 -= V_40 ;
} while ( V_76 );
* V_67 ++ = V_78 ;
return V_67 ;
}
static V_5 *
F_19 ( struct V_8 * V_9 , struct V_73 * V_74 ,
struct V_21 * V_22 , V_5 * V_67 ,
enum V_52 V_89 )
{
struct V_38 * V_39 ;
struct V_68 * V_69 ;
int V_40 , V_76 , V_90 ;
V_5 * V_91 ;
if ( V_89 != V_64 ) {
* V_67 ++ = V_78 ;
return V_67 ;
}
V_39 = V_74 -> V_80 ;
V_76 = F_10 ( V_9 , & V_22 -> V_34 ,
V_22 -> V_34 . V_56 [ 0 ] . V_44 ,
V_89 , V_39 ) ;
if ( V_76 < 0 )
return F_17 ( V_76 ) ;
* V_67 ++ = V_84 ;
V_91 = V_67 ++ ;
V_90 = 0 ;
do {
V_40 = V_9 -> V_15 . V_81 -> V_82 ( V_9 , V_39 , V_76 ,
true , & V_69 ) ;
if ( V_40 < 0 )
return F_17 ( V_40 ) ;
F_18 ( V_69 , & V_74 -> V_83 ) ;
V_67 = F_13 ( V_67 , V_69 ) ;
F_2 ( L_7 ,
V_22 -> V_85 -> V_86 , V_7 ,
V_69 -> V_71 , ( unsigned long long ) V_69 -> V_72 ,
V_69 -> V_70 , V_40 < V_76 ? L_5 : L_6 ) ;
V_9 -> V_87 . V_92 ++ ;
V_9 -> V_87 . V_93 += V_39 -> V_48 ;
V_90 ++ ;
V_39 += V_40 ;
V_76 -= V_40 ;
} while ( V_76 );
* V_91 = F_14 ( V_90 ) ;
* V_67 ++ = V_78 ;
return V_67 ;
}
static V_5 *
F_20 ( struct V_8 * V_9 ,
struct V_73 * V_74 , struct V_21 * V_22 ,
V_5 * V_67 , enum V_52 V_89 )
{
struct V_38 * V_39 ;
struct V_68 * V_69 ;
int V_40 , V_76 , V_90 ;
V_5 * V_91 ;
if ( V_89 != V_94 ) {
* V_67 ++ = V_78 ;
return V_67 ;
}
V_39 = V_74 -> V_80 ;
V_76 = F_10 ( V_9 , & V_22 -> V_34 , 0 , V_89 , V_39 ) ;
if ( V_76 < 0 )
return F_17 ( V_76 ) ;
* V_67 ++ = V_84 ;
V_91 = V_67 ++ ;
V_90 = 0 ;
do {
V_40 = V_9 -> V_15 . V_81 -> V_82 ( V_9 , V_39 , V_76 ,
true , & V_69 ) ;
if ( V_40 < 0 )
return F_17 ( V_40 ) ;
F_18 ( V_69 , & V_74 -> V_83 ) ;
V_67 = F_13 ( V_67 , V_69 ) ;
F_2 ( L_8 ,
V_22 -> V_85 -> V_86 , V_7 ,
V_69 -> V_71 , ( unsigned long long ) V_69 -> V_72 ,
V_69 -> V_70 , V_40 < V_76 ? L_5 : L_6 ) ;
V_9 -> V_87 . V_95 ++ ;
V_9 -> V_87 . V_93 += V_39 -> V_48 ;
V_90 ++ ;
V_39 += V_40 ;
V_76 -= V_40 ;
} while ( V_76 );
* V_91 = F_14 ( V_90 ) ;
return V_67 ;
}
static bool
F_21 ( struct V_13 * V_14 , struct V_73 * V_74 ,
T_2 V_29 )
{
struct V_96 * V_97 = V_74 -> V_98 ;
struct V_99 * V_100 = & V_74 -> V_101 [ 0 ] ;
if ( F_22 ( ! F_23 ( V_97 ) ) ) {
if ( ! F_24 ( V_14 , V_97 ) )
return false ;
V_100 -> V_102 = F_25 ( V_97 ) ;
V_100 -> V_103 = F_26 ( V_97 ) ;
}
V_100 -> V_104 = V_29 ;
F_27 ( V_14 -> V_105 , V_100 -> V_102 ,
V_100 -> V_104 , V_106 ) ;
V_74 -> V_107 . V_108 ++ ;
return true ;
}
static bool
F_28 ( struct V_13 * V_14 , struct V_73 * V_74 ,
struct V_23 * V_24 , enum V_52 V_75 )
{
unsigned int V_109 , V_31 , V_29 , V_27 ;
struct V_96 * V_97 = V_74 -> V_110 ;
struct V_111 * V_112 = V_14 -> V_105 ;
struct V_99 * V_100 = V_74 -> V_101 ;
T_2 V_103 = V_14 -> V_113 -> V_114 ;
struct V_54 * V_54 , * * V_55 ;
if ( ! F_29 ( V_14 , V_97 ) )
return false ;
V_109 = 1 ;
V_100 [ V_109 ] . V_102 = F_25 ( V_97 ) ;
V_100 [ V_109 ] . V_104 = V_24 -> V_56 [ 0 ] . V_44 ;
V_100 [ V_109 ] . V_103 = F_26 ( V_97 ) ;
F_27 ( V_112 , V_100 [ V_109 ] . V_102 ,
V_100 [ V_109 ] . V_104 , V_106 ) ;
if ( V_75 == V_62 ) {
V_29 = V_24 -> V_65 [ 0 ] . V_44 ;
if ( V_29 < 4 )
goto V_115;
V_54 = F_30 ( V_24 -> V_65 [ 0 ] . V_43 ) ;
V_31 = ( unsigned long ) V_24 -> V_65 [ 0 ] . V_43 & ~ V_32 ;
V_31 += V_29 & 3 ;
V_29 -= V_29 & 3 ;
goto V_116;
}
if ( V_24 -> V_30 ) {
V_55 = V_24 -> V_58 + ( V_24 -> V_31 >> V_59 ) ;
V_31 = V_24 -> V_31 & ~ V_32 ;
V_27 = V_24 -> V_30 ;
while ( V_27 ) {
V_109 ++ ;
if ( V_109 > V_117 - 2 )
goto V_118;
V_29 = F_6 ( T_2 , V_49 - V_31 , V_27 ) ;
V_100 [ V_109 ] . V_102 = F_31 ( V_112 , * V_55 ,
V_31 , V_29 ,
V_106 ) ;
if ( F_32 ( V_112 , V_100 [ V_109 ] . V_102 ) )
goto V_119;
V_100 [ V_109 ] . V_104 = V_29 ;
V_100 [ V_109 ] . V_103 = V_103 ;
V_74 -> V_120 ++ ;
V_55 ++ ;
V_27 -= V_29 ;
V_31 = 0 ;
}
}
if ( V_24 -> V_65 [ 0 ] . V_44 ) {
V_54 = F_30 ( V_24 -> V_65 [ 0 ] . V_43 ) ;
V_31 = ( unsigned long ) V_24 -> V_65 [ 0 ] . V_43 & ~ V_32 ;
V_29 = V_24 -> V_65 [ 0 ] . V_44 ;
V_116:
V_109 ++ ;
V_100 [ V_109 ] . V_102 = F_31 ( V_112 , V_54 ,
V_31 , V_29 ,
V_106 ) ;
if ( F_32 ( V_112 , V_100 [ V_109 ] . V_102 ) )
goto V_119;
V_100 [ V_109 ] . V_104 = V_29 ;
V_100 [ V_109 ] . V_103 = V_103 ;
V_74 -> V_120 ++ ;
}
V_115:
V_74 -> V_107 . V_108 = V_109 + 1 ;
return true ;
V_118:
F_12 ( L_9 , V_109 ) ;
return false ;
V_119:
F_12 ( L_10 ) ;
return false ;
}
bool
F_33 ( struct V_13 * V_14 , struct V_73 * V_74 ,
T_2 V_121 , struct V_23 * V_24 ,
enum V_52 V_75 )
{
V_74 -> V_107 . V_108 = 0 ;
V_74 -> V_120 = 0 ;
if ( ! F_21 ( V_14 , V_74 , V_121 ) )
goto V_122;
if ( V_75 != V_79 )
if ( ! F_28 ( V_14 , V_74 , V_24 , V_75 ) )
goto V_122;
return true ;
V_122:
F_12 ( L_11 ) ;
return false ;
}
void
F_34 ( struct V_13 * V_14 , struct V_73 * V_74 )
{
struct V_111 * V_112 = V_14 -> V_105 ;
struct V_99 * V_100 ;
int V_26 ;
V_100 = & V_74 -> V_101 [ 2 ] ;
for ( V_26 = V_74 -> V_120 ; V_26 -- ; V_100 ++ )
F_35 ( V_112 , V_100 -> V_102 , V_100 -> V_104 ,
V_106 ) ;
V_74 -> V_120 = 0 ;
}
int
F_36 ( struct V_21 * V_22 )
{
struct V_123 * V_124 = V_22 -> V_125 ;
struct V_8 * V_9 = F_37 ( V_124 ) ;
struct V_73 * V_74 = F_38 ( V_22 ) ;
enum V_52 V_75 , V_89 ;
struct V_126 * V_127 ;
bool V_128 ;
T_3 V_121 ;
T_1 V_129 ;
V_5 * V_67 ;
#if F_39 ( V_130 )
if ( F_40 ( V_131 , & V_22 -> V_132 ) )
return F_41 ( V_22 ) ;
#endif
V_127 = F_42 ( V_74 -> V_98 ) ;
V_127 -> V_133 = V_22 -> V_134 ;
V_127 -> V_135 = V_136 ;
V_127 -> V_137 = F_14 ( V_9 -> V_138 . V_139 ) ;
V_127 -> V_140 = V_141 ;
V_128 = ! ( V_22 -> V_142 -> V_143 -> V_144 &
V_145 ) ;
if ( F_7 ( V_9 , V_22 ) )
V_89 = V_77 ;
else if ( V_128 && V_22 -> V_34 . V_146 & V_147 )
V_89 = V_64 ;
else
V_89 = V_94 ;
if ( F_5 ( V_9 , V_22 ) ) {
V_75 = V_77 ;
V_129 = V_22 -> V_25 . V_29 ;
} else if ( V_128 && V_22 -> V_25 . V_146 & V_148 ) {
V_75 = V_62 ;
V_129 = V_22 -> V_25 . V_56 [ 0 ] . V_44 +
V_22 -> V_25 . V_65 [ 0 ] . V_44 ;
} else {
V_9 -> V_87 . V_149 ++ ;
V_127 -> V_140 = F_43 ( V_150 ) ;
V_75 = V_79 ;
V_129 = 0 ;
}
V_67 = V_127 -> V_151 . V_152 ;
V_67 = F_16 ( V_9 , V_74 , V_22 , V_67 , V_75 ) ;
if ( F_44 ( V_67 ) )
goto V_153;
V_67 = F_19 ( V_9 , V_74 , V_22 , V_67 , V_89 ) ;
if ( F_44 ( V_67 ) )
goto V_153;
V_67 = F_20 ( V_9 , V_74 , V_22 , V_67 , V_89 ) ;
if ( F_44 ( V_67 ) )
goto V_153;
V_121 = ( unsigned char * ) V_67 - ( unsigned char * ) V_127 ;
F_2 ( L_12 ,
V_22 -> V_85 -> V_86 , V_7 ,
V_154 [ V_75 ] , V_154 [ V_89 ] ,
V_121 , V_129 ) ;
if ( ! F_33 ( & V_9 -> V_15 , V_74 , V_121 ,
& V_22 -> V_25 , V_75 ) ) {
V_67 = F_17 ( - V_66 ) ;
goto V_153;
}
return 0 ;
V_153:
F_12 ( L_13 ,
F_45 ( V_67 ) ) ;
V_9 -> V_87 . V_155 ++ ;
return F_45 ( V_67 ) ;
}
static int
F_46 ( struct V_156 * V_157 , int V_158 , V_5 * * V_159 )
{
unsigned int V_160 , V_161 ;
struct V_162 * V_163 ;
char * V_42 = ( char * ) F_42 ( V_157 -> V_164 ) ;
V_160 = F_47 ( * * V_159 ) ;
V_163 = (struct V_162 * ) ( * V_159 + 1 ) ;
V_161 = 0 ;
while ( V_160 -- ) {
struct V_6 * V_39 = & V_163 -> V_165 ;
F_48 (FACILITY) {
T_4 V_166 ;
F_49 ( ( V_5 * ) & V_39 -> V_167 , & V_166 ) ;
F_2 ( L_14 ,
V_7 ,
F_47 ( V_39 -> V_168 ) ,
( unsigned long long ) V_166 ,
F_47 ( V_39 -> V_169 ) ) ;
}
V_161 += F_47 ( V_39 -> V_168 ) ;
++ V_163 ;
}
if ( V_158 ) {
V_5 * V_170 = ( V_5 * ) V_163 ;
if ( * V_170 ++ != V_78 )
return - 1 ;
V_163 = (struct V_162 * ) V_170 ;
}
if ( ( char * ) V_163 > V_42 + V_157 -> V_171 )
return - 1 ;
* V_159 = ( V_5 * ) V_163 ;
return V_161 ;
}
static unsigned long
F_50 ( struct V_21 * V_22 , char * V_172 , int V_173 , int V_174 )
{
unsigned long V_175 ;
int V_160 , V_176 , V_177 ;
char * V_178 ;
struct V_54 * * V_55 ;
int V_31 ;
V_22 -> V_34 . V_56 [ 0 ] . V_43 = V_172 ;
V_22 -> V_179 . V_56 [ 0 ] . V_43 = V_172 ;
V_177 = V_22 -> V_34 . V_56 [ 0 ] . V_44 ;
if ( V_177 > V_173 )
V_177 = V_173 ;
F_2 ( L_15 ,
V_7 , V_172 , V_173 , V_177 ) ;
V_172 += V_177 ;
V_173 -= V_177 ;
V_31 = V_22 -> V_34 . V_31 ;
V_55 = V_22 -> V_34 . V_58 + ( V_31 >> V_59 ) ;
V_31 &= ~ V_32 ;
V_175 = 0 ;
if ( V_173 && V_22 -> V_34 . V_30 ) {
int V_180 ;
V_180 = V_22 -> V_34 . V_30 ;
if ( V_180 > V_173 )
V_180 = V_173 ;
V_176 = F_51 ( V_31 + V_180 ) >> V_59 ;
for ( V_160 = 0 ; V_160 < V_176 ; V_160 ++ ) {
V_177 = V_49 - V_31 ;
if ( V_177 > V_180 )
V_177 = V_180 ;
F_2 ( L_16
L_17 ,
V_7 , V_160 , V_172 , V_173 , V_177 ) ;
V_178 = F_52 ( V_55 [ V_160 ] ) ;
memcpy ( V_178 + V_31 , V_172 , V_177 ) ;
F_53 ( V_55 [ V_160 ] ) ;
F_54 ( V_178 ) ;
V_172 += V_177 ;
V_173 -= V_177 ;
V_175 += V_177 ;
V_180 -= V_177 ;
if ( ! V_180 )
break;
V_31 = 0 ;
}
if ( V_174 )
V_172 -= V_174 ;
}
if ( V_173 || V_174 ) {
V_22 -> V_34 . V_65 [ 0 ] . V_43 = V_172 ;
V_22 -> V_179 . V_65 [ 0 ] . V_43 = V_172 ;
}
return V_175 ;
}
static bool
F_55 ( struct V_126 * V_127 )
{
V_5 * V_53 = ( V_5 * ) V_127 ;
if ( V_127 -> V_140 != V_141 )
return false ;
if ( V_127 -> V_151 . V_152 [ 0 ] != V_78 )
return false ;
if ( V_127 -> V_151 . V_152 [ 1 ] != V_78 )
return false ;
if ( V_127 -> V_151 . V_152 [ 2 ] != V_78 )
return false ;
if ( V_53 [ 7 ] != V_127 -> V_133 )
return false ;
if ( V_53 [ 8 ] != F_14 ( V_181 ) )
return false ;
return true ;
}
void
F_56 ( struct V_182 * V_183 )
{
struct V_156 * V_157 =
F_57 ( V_183 , struct V_156 , V_184 ) ;
struct V_126 * V_127 ;
struct V_73 * V_74 ;
struct V_21 * V_22 ;
struct V_8 * V_9 = V_157 -> V_185 ;
struct V_123 * V_124 = & V_9 -> V_186 ;
V_5 * V_67 ;
int V_187 , V_188 , V_189 ;
unsigned long V_190 ;
F_2 ( L_18 , V_7 , V_157 ) ;
if ( V_157 -> V_171 == V_191 )
goto V_192;
if ( V_157 -> V_171 < V_193 )
goto V_194;
V_127 = F_42 ( V_157 -> V_164 ) ;
#if F_39 ( V_130 )
if ( F_55 ( V_127 ) )
goto V_195;
#endif
F_58 ( & V_124 -> V_196 ) ;
V_22 = F_59 ( V_124 , V_127 -> V_133 ) ;
if ( ! V_22 )
goto V_197;
V_74 = F_38 ( V_22 ) ;
if ( V_74 -> V_198 )
goto V_199;
F_60 ( & V_22 -> V_200 ) ;
F_61 ( & V_124 -> V_196 ) ;
F_2 ( L_19 ,
V_7 , V_157 , V_74 , F_47 ( V_127 -> V_133 ) ) ;
V_74 -> V_198 = V_157 ;
V_124 -> V_201 = 0 ;
if ( V_127 -> V_135 != V_136 )
goto V_202;
switch ( V_127 -> V_140 ) {
case V_141 :
if ( V_127 -> V_151 . V_152 [ 0 ] != V_78 ||
( V_127 -> V_151 . V_152 [ 1 ] == V_78 &&
V_127 -> V_151 . V_152 [ 2 ] != V_78 ) ||
( V_127 -> V_151 . V_152 [ 1 ] != V_78 &&
F_62 ( & V_74 -> V_83 ) ) )
goto V_203;
if ( V_127 -> V_151 . V_152 [ 1 ] != V_78 ) {
V_67 = & V_127 -> V_151 . V_152 [ 2 ] ;
V_187 = F_46 ( V_157 , 1 , & V_67 ) ;
if ( V_187 < 0 || * V_67 ++ != V_78 )
goto V_203;
V_157 -> V_171 -=
( ( unsigned char * ) V_67 - ( unsigned char * ) V_127 ) ;
V_188 = V_157 -> V_171 + V_187 ;
V_9 -> V_87 . V_204 += V_187 ;
if ( V_187 &= 3 ) {
V_187 = 4 - V_187 ;
V_188 += V_187 ;
}
} else {
V_187 = 0 ;
V_67 = ( V_5 * ) ( ( unsigned char * ) V_127 +
V_3 ) ;
V_157 -> V_171 -= V_3 ;
V_188 = V_157 -> V_171 ;
}
V_9 -> V_87 . V_175 +=
F_50 ( V_22 , ( char * ) V_67 , V_157 -> V_171 ,
V_187 ) ;
break;
case V_205 :
if ( V_127 -> V_151 . V_152 [ 0 ] != V_78 ||
V_127 -> V_151 . V_152 [ 1 ] != V_78 ||
V_127 -> V_151 . V_152 [ 2 ] != V_84 ||
F_62 ( & V_74 -> V_83 ) )
goto V_203;
V_67 = ( V_5 * ) ( ( unsigned char * ) V_127 +
V_3 ) ;
V_187 = F_46 ( V_157 , 0 , & V_67 ) ;
if ( V_187 < 0 )
goto V_203;
V_9 -> V_87 . V_204 += V_187 ;
V_188 = V_187 ;
break;
case V_206 :
goto V_207;
V_203:
default:
F_2 ( L_20 ,
V_22 -> V_85 -> V_86 , V_7 ,
F_47 ( V_127 -> V_140 ) ) ;
V_188 = - V_66 ;
V_9 -> V_87 . V_208 ++ ;
break;
}
V_115:
if ( ! F_62 ( & V_74 -> V_83 ) )
V_9 -> V_15 . V_81 -> V_209 ( V_9 , V_74 ) ;
F_58 ( & V_124 -> V_196 ) ;
V_190 = V_124 -> V_190 ;
V_124 -> V_190 = F_63 ( & V_9 -> V_138 . V_210 ) << V_211 ;
if ( V_124 -> V_190 > V_190 )
F_64 ( V_22 -> V_85 ) ;
F_65 ( V_22 -> V_85 , V_188 ) ;
F_61 ( & V_124 -> V_196 ) ;
F_2 ( L_21 ,
V_7 , V_124 , V_22 , V_188 ) ;
return;
V_192:
F_66 ( V_157 ) ;
if ( V_9 -> V_212 . V_213 == 1 ) {
V_9 -> V_212 . V_213 = - V_66 ;
F_67 ( & V_9 -> V_212 ) ;
}
return;
#if F_39 ( V_130 )
V_195:
F_68 ( V_9 , V_157 ) ;
return;
#endif
V_202:
F_2 ( L_22 ,
V_7 , F_47 ( V_127 -> V_135 ) ) ;
V_188 = - V_66 ;
V_9 -> V_87 . V_208 ++ ;
goto V_115;
V_207:
V_189 = F_47 ( V_127 -> V_151 . V_214 . V_215 ) ;
switch ( V_189 ) {
case V_216 :
F_12 ( L_23 ,
V_7 ,
F_47 ( V_127 -> V_151 . V_214 . V_217 ) ,
F_47 ( V_127 -> V_151 . V_214 . V_218 ) ) ;
break;
case V_219 :
F_12 ( L_24 ,
V_7 ) ;
break;
default:
F_12 ( L_25 ,
V_7 , V_189 ) ;
}
V_188 = - V_220 ;
V_9 -> V_87 . V_208 ++ ;
goto V_115;
V_194:
F_2 ( L_26 , V_7 ) ;
goto V_221;
V_197:
F_61 ( & V_124 -> V_196 ) ;
F_2 ( L_27 ,
V_7 , F_47 ( V_127 -> V_133 ) ,
V_157 -> V_171 ) ;
goto V_221;
V_199:
F_61 ( & V_124 -> V_196 ) ;
F_2 ( L_28
L_29 ,
V_7 , V_157 , V_74 , F_47 ( V_127 -> V_133 ) ) ;
V_221:
V_9 -> V_87 . V_208 ++ ;
if ( F_69 ( & V_9 -> V_15 , V_157 ) )
F_66 ( V_157 ) ;
}
