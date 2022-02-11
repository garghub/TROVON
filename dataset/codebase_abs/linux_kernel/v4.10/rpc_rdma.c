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
struct V_13 * V_14 = & V_9 -> V_15 ;
return V_22 -> V_23 . V_24 <= V_14 -> V_17 ;
}
static bool F_6 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = & V_9 -> V_15 ;
return V_22 -> V_25 . V_26 <= V_14 -> V_19 ;
}
static int
F_7 ( struct V_27 * V_28 , struct V_29 * V_30 , int V_31 )
{
T_1 V_32 ;
T_2 V_33 ;
char * V_34 ;
V_34 = V_28 -> V_35 ;
V_32 = F_8 ( V_34 ) ;
V_33 = V_28 -> V_36 ;
while ( V_33 && V_31 < V_37 ) {
V_30 [ V_31 ] . V_38 = NULL ;
V_30 [ V_31 ] . V_39 = V_34 ;
V_30 [ V_31 ] . V_40 = F_9 ( T_2 , V_41 - V_32 , V_33 ) ;
V_33 -= V_30 [ V_31 ] . V_40 ;
V_34 += V_30 [ V_31 ] . V_40 ;
++ V_31 ;
V_32 = 0 ;
}
return V_31 ;
}
static int
F_10 ( struct V_42 * V_43 , unsigned int V_44 ,
enum V_45 type , struct V_29 * V_30 ,
bool V_46 )
{
int V_24 , V_31 , V_47 , V_48 ;
struct V_49 * * V_50 ;
V_31 = 0 ;
if ( V_44 == 0 ) {
V_31 = F_7 ( & V_43 -> V_51 [ 0 ] , V_30 , V_31 ) ;
if ( V_31 == V_37 )
goto V_52;
}
V_24 = V_43 -> V_53 ;
V_50 = V_43 -> V_54 + ( V_43 -> V_48 >> V_55 ) ;
V_48 = V_43 -> V_48 & ~ V_56 ;
V_47 = 0 ;
while ( V_24 && V_31 < V_37 ) {
if ( ! V_50 [ V_47 ] ) {
V_50 [ V_47 ] = F_11 ( V_57 ) ;
if ( ! V_50 [ V_47 ] )
return - V_58 ;
}
V_30 [ V_31 ] . V_38 = V_50 [ V_47 ] ;
V_30 [ V_31 ] . V_39 = ( void * ) ( unsigned long ) V_48 ;
V_30 [ V_31 ] . V_40 = F_9 ( T_2 , V_41 - V_48 , V_24 ) ;
if ( V_30 [ V_31 ] . V_40 > V_41 )
goto V_52;
V_24 -= V_30 [ V_31 ] . V_40 ;
++ V_31 ;
++ V_47 ;
V_48 = 0 ;
}
if ( V_24 && V_31 == V_37 )
goto V_52;
if ( type == V_59 )
return V_31 ;
if ( type == V_60 && V_46 )
return V_31 ;
if ( V_43 -> V_61 [ 0 ] . V_36 ) {
if ( V_43 -> V_61 [ 0 ] . V_36 < 4 && V_62 )
return V_31 ;
V_31 = F_7 ( & V_43 -> V_61 [ 0 ] , V_30 , V_31 ) ;
if ( V_31 == V_37 )
goto V_52;
}
return V_31 ;
V_52:
F_12 ( L_3 ) ;
return - V_63 ;
}
static inline V_5 *
F_13 ( V_5 * V_64 , struct V_65 * V_66 )
{
* V_64 ++ = F_14 ( V_66 -> V_67 ) ;
* V_64 ++ = F_14 ( V_66 -> V_68 ) ;
return F_15 ( V_64 , V_66 -> V_69 ) ;
}
static V_5 *
F_16 ( struct V_8 * V_9 ,
struct V_70 * V_71 , struct V_21 * V_22 ,
V_5 * V_64 , enum V_45 V_72 )
{
struct V_29 * V_30 ;
struct V_65 * V_66 ;
unsigned int V_44 ;
int V_31 , V_73 ;
if ( V_72 == V_74 ) {
* V_64 ++ = V_75 ;
return V_64 ;
}
V_44 = V_22 -> V_23 . V_51 [ 0 ] . V_36 ;
if ( V_72 == V_76 )
V_44 = 0 ;
V_30 = V_71 -> V_77 ;
V_73 = F_10 ( & V_22 -> V_23 , V_44 , V_72 , V_30 , false ) ;
if ( V_73 < 0 )
return F_17 ( V_73 ) ;
do {
V_31 = V_9 -> V_15 . V_78 -> V_79 ( V_9 , V_30 , V_73 ,
false , & V_66 ) ;
if ( V_31 < 0 )
return F_17 ( V_31 ) ;
F_18 ( & V_66 -> V_80 , & V_71 -> V_81 ) ;
* V_64 ++ = V_82 ;
* V_64 ++ = F_14 ( V_44 ) ;
V_64 = F_13 ( V_64 , V_66 ) ;
F_2 ( L_4 ,
V_22 -> V_83 -> V_84 , V_7 , V_44 ,
V_66 -> V_68 , ( unsigned long long ) V_66 -> V_69 ,
V_66 -> V_67 , V_31 < V_73 ? L_5 : L_6 ) ;
V_9 -> V_85 . V_86 ++ ;
V_30 += V_31 ;
V_73 -= V_31 ;
} while ( V_73 );
* V_64 ++ = V_75 ;
return V_64 ;
}
static V_5 *
F_19 ( struct V_8 * V_9 , struct V_70 * V_71 ,
struct V_21 * V_22 , V_5 * V_64 ,
enum V_45 V_87 )
{
struct V_29 * V_30 ;
struct V_65 * V_66 ;
int V_31 , V_73 , V_88 ;
V_5 * V_89 ;
if ( V_87 != V_60 ) {
* V_64 ++ = V_75 ;
return V_64 ;
}
V_30 = V_71 -> V_77 ;
V_73 = F_10 ( & V_22 -> V_25 ,
V_22 -> V_25 . V_51 [ 0 ] . V_36 ,
V_87 , V_30 ,
V_9 -> V_15 . V_90 ) ;
if ( V_73 < 0 )
return F_17 ( V_73 ) ;
* V_64 ++ = V_82 ;
V_89 = V_64 ++ ;
V_88 = 0 ;
do {
V_31 = V_9 -> V_15 . V_78 -> V_79 ( V_9 , V_30 , V_73 ,
true , & V_66 ) ;
if ( V_31 < 0 )
return F_17 ( V_31 ) ;
F_18 ( & V_66 -> V_80 , & V_71 -> V_81 ) ;
V_64 = F_13 ( V_64 , V_66 ) ;
F_2 ( L_7 ,
V_22 -> V_83 -> V_84 , V_7 ,
V_66 -> V_68 , ( unsigned long long ) V_66 -> V_69 ,
V_66 -> V_67 , V_31 < V_73 ? L_5 : L_6 ) ;
V_9 -> V_85 . V_91 ++ ;
V_9 -> V_85 . V_92 += V_30 -> V_40 ;
V_88 ++ ;
V_30 += V_31 ;
V_73 -= V_31 ;
} while ( V_73 );
* V_89 = F_14 ( V_88 ) ;
* V_64 ++ = V_75 ;
return V_64 ;
}
static V_5 *
F_20 ( struct V_8 * V_9 ,
struct V_70 * V_71 , struct V_21 * V_22 ,
V_5 * V_64 , enum V_45 V_87 )
{
struct V_29 * V_30 ;
struct V_65 * V_66 ;
int V_31 , V_73 , V_88 ;
V_5 * V_89 ;
if ( V_87 != V_93 ) {
* V_64 ++ = V_75 ;
return V_64 ;
}
V_30 = V_71 -> V_77 ;
V_73 = F_10 ( & V_22 -> V_25 , 0 , V_87 , V_30 ,
V_9 -> V_15 . V_90 ) ;
if ( V_73 < 0 )
return F_17 ( V_73 ) ;
* V_64 ++ = V_82 ;
V_89 = V_64 ++ ;
V_88 = 0 ;
do {
V_31 = V_9 -> V_15 . V_78 -> V_79 ( V_9 , V_30 , V_73 ,
true , & V_66 ) ;
if ( V_31 < 0 )
return F_17 ( V_31 ) ;
F_18 ( & V_66 -> V_80 , & V_71 -> V_81 ) ;
V_64 = F_13 ( V_64 , V_66 ) ;
F_2 ( L_8 ,
V_22 -> V_83 -> V_84 , V_7 ,
V_66 -> V_68 , ( unsigned long long ) V_66 -> V_69 ,
V_66 -> V_67 , V_31 < V_73 ? L_5 : L_6 ) ;
V_9 -> V_85 . V_94 ++ ;
V_9 -> V_85 . V_92 += V_30 -> V_40 ;
V_88 ++ ;
V_30 += V_31 ;
V_73 -= V_31 ;
} while ( V_73 );
* V_89 = F_14 ( V_88 ) ;
return V_64 ;
}
static bool
F_21 ( struct V_13 * V_14 , struct V_70 * V_71 ,
T_2 V_24 )
{
struct V_95 * V_96 = V_71 -> V_97 ;
struct V_98 * V_99 = & V_71 -> V_100 [ 0 ] ;
if ( F_22 ( ! F_23 ( V_96 ) ) ) {
if ( ! F_24 ( V_14 , V_96 ) )
return false ;
V_99 -> V_101 = F_25 ( V_96 ) ;
V_99 -> V_102 = F_26 ( V_96 ) ;
}
V_99 -> V_103 = V_24 ;
F_27 ( V_14 -> V_104 , V_99 -> V_101 ,
V_99 -> V_103 , V_105 ) ;
V_71 -> V_106 . V_107 ++ ;
return true ;
}
static bool
F_28 ( struct V_13 * V_14 , struct V_70 * V_71 ,
struct V_42 * V_108 , enum V_45 V_72 )
{
unsigned int V_109 , V_48 , V_24 , V_33 ;
struct V_95 * V_96 = V_71 -> V_110 ;
struct V_111 * V_112 = V_14 -> V_104 ;
struct V_98 * V_99 = V_71 -> V_100 ;
T_2 V_102 = V_14 -> V_113 -> V_114 ;
struct V_49 * V_49 , * * V_50 ;
if ( ! F_29 ( V_14 , V_96 ) )
return false ;
V_109 = 1 ;
V_99 [ V_109 ] . V_101 = F_25 ( V_96 ) ;
V_99 [ V_109 ] . V_103 = V_108 -> V_51 [ 0 ] . V_36 ;
V_99 [ V_109 ] . V_102 = F_26 ( V_96 ) ;
F_27 ( V_112 , V_99 [ V_109 ] . V_101 ,
V_99 [ V_109 ] . V_103 , V_105 ) ;
if ( V_72 == V_59 ) {
V_24 = V_108 -> V_61 [ 0 ] . V_36 ;
if ( V_24 < 4 )
goto V_115;
V_49 = F_30 ( V_108 -> V_61 [ 0 ] . V_35 ) ;
V_48 = ( unsigned long ) V_108 -> V_61 [ 0 ] . V_35 & ~ V_56 ;
V_48 += V_24 & 3 ;
V_24 -= V_24 & 3 ;
goto V_116;
}
if ( V_108 -> V_53 ) {
V_50 = V_108 -> V_54 + ( V_108 -> V_48 >> V_55 ) ;
V_48 = V_108 -> V_48 & ~ V_56 ;
V_33 = V_108 -> V_53 ;
while ( V_33 ) {
V_109 ++ ;
if ( V_109 > V_117 - 2 )
goto V_118;
V_24 = F_9 ( T_2 , V_41 - V_48 , V_33 ) ;
V_99 [ V_109 ] . V_101 = F_31 ( V_112 , * V_50 ,
V_48 , V_24 ,
V_105 ) ;
if ( F_32 ( V_112 , V_99 [ V_109 ] . V_101 ) )
goto V_119;
V_99 [ V_109 ] . V_103 = V_24 ;
V_99 [ V_109 ] . V_102 = V_102 ;
V_71 -> V_120 ++ ;
V_50 ++ ;
V_33 -= V_24 ;
V_48 = 0 ;
}
}
if ( V_108 -> V_61 [ 0 ] . V_36 ) {
V_49 = F_30 ( V_108 -> V_61 [ 0 ] . V_35 ) ;
V_48 = ( unsigned long ) V_108 -> V_61 [ 0 ] . V_35 & ~ V_56 ;
V_24 = V_108 -> V_61 [ 0 ] . V_36 ;
V_116:
V_109 ++ ;
V_99 [ V_109 ] . V_101 = F_31 ( V_112 , V_49 ,
V_48 , V_24 ,
V_105 ) ;
if ( F_32 ( V_112 , V_99 [ V_109 ] . V_101 ) )
goto V_119;
V_99 [ V_109 ] . V_103 = V_24 ;
V_99 [ V_109 ] . V_102 = V_102 ;
V_71 -> V_120 ++ ;
}
V_115:
V_71 -> V_106 . V_107 = V_109 + 1 ;
return true ;
V_118:
F_12 ( L_9 , V_109 ) ;
return false ;
V_119:
F_12 ( L_10 ) ;
return false ;
}
bool
F_33 ( struct V_13 * V_14 , struct V_70 * V_71 ,
T_2 V_121 , struct V_42 * V_108 ,
enum V_45 V_72 )
{
V_71 -> V_106 . V_107 = 0 ;
V_71 -> V_120 = 0 ;
if ( ! F_21 ( V_14 , V_71 , V_121 ) )
goto V_122;
if ( V_72 != V_76 )
if ( ! F_28 ( V_14 , V_71 , V_108 , V_72 ) )
goto V_122;
return true ;
V_122:
F_12 ( L_11 ) ;
return false ;
}
void
F_34 ( struct V_13 * V_14 , struct V_70 * V_71 )
{
struct V_111 * V_112 = V_14 -> V_104 ;
struct V_98 * V_99 ;
int V_123 ;
V_99 = & V_71 -> V_100 [ 2 ] ;
for ( V_123 = V_71 -> V_120 ; V_123 -- ; V_99 ++ )
F_35 ( V_112 , V_99 -> V_101 , V_99 -> V_103 ,
V_105 ) ;
V_71 -> V_120 = 0 ;
}
int
F_36 ( struct V_21 * V_22 )
{
struct V_124 * V_125 = V_22 -> V_126 ;
struct V_8 * V_9 = F_37 ( V_125 ) ;
struct V_70 * V_71 = F_38 ( V_22 ) ;
enum V_45 V_72 , V_87 ;
struct V_127 * V_128 ;
bool V_129 ;
T_3 V_121 ;
T_1 V_130 ;
V_5 * V_64 ;
#if F_39 ( V_131 )
if ( F_40 ( V_132 , & V_22 -> V_133 ) )
return F_41 ( V_22 ) ;
#endif
V_128 = F_42 ( V_71 -> V_97 ) ;
V_128 -> V_134 = V_22 -> V_135 ;
V_128 -> V_136 = V_137 ;
V_128 -> V_138 = F_14 ( V_9 -> V_139 . V_140 ) ;
V_128 -> V_141 = V_142 ;
V_129 = ! ( V_22 -> V_143 -> V_144 -> V_145 &
V_146 ) ;
if ( F_6 ( V_9 , V_22 ) )
V_87 = V_74 ;
else if ( V_129 && V_22 -> V_25 . V_147 & V_148 )
V_87 = V_60 ;
else
V_87 = V_93 ;
if ( F_5 ( V_9 , V_22 ) ) {
V_72 = V_74 ;
V_130 = V_22 -> V_23 . V_24 ;
} else if ( V_129 && V_22 -> V_23 . V_147 & V_149 ) {
V_72 = V_59 ;
V_130 = V_22 -> V_23 . V_51 [ 0 ] . V_36 +
V_22 -> V_23 . V_61 [ 0 ] . V_36 ;
} else {
V_9 -> V_85 . V_150 ++ ;
V_128 -> V_141 = F_43 ( V_151 ) ;
V_72 = V_76 ;
V_130 = 0 ;
}
V_64 = V_128 -> V_152 . V_153 ;
V_64 = F_16 ( V_9 , V_71 , V_22 , V_64 , V_72 ) ;
if ( F_44 ( V_64 ) )
goto V_154;
V_64 = F_19 ( V_9 , V_71 , V_22 , V_64 , V_87 ) ;
if ( F_44 ( V_64 ) )
goto V_154;
V_64 = F_20 ( V_9 , V_71 , V_22 , V_64 , V_87 ) ;
if ( F_44 ( V_64 ) )
goto V_154;
V_121 = ( unsigned char * ) V_64 - ( unsigned char * ) V_128 ;
F_2 ( L_12 ,
V_22 -> V_83 -> V_84 , V_7 ,
V_155 [ V_72 ] , V_155 [ V_87 ] ,
V_121 , V_130 ) ;
if ( ! F_33 ( & V_9 -> V_15 , V_71 , V_121 ,
& V_22 -> V_23 , V_72 ) ) {
V_64 = F_17 ( - V_63 ) ;
goto V_154;
}
return 0 ;
V_154:
V_9 -> V_15 . V_78 -> V_156 ( V_9 , V_71 , false ) ;
return F_45 ( V_64 ) ;
}
static int
F_46 ( struct V_157 * V_158 , int V_159 , V_5 * * V_160 )
{
unsigned int V_161 , V_162 ;
struct V_163 * V_164 ;
char * V_34 = ( char * ) F_42 ( V_158 -> V_165 ) ;
V_161 = F_47 ( * * V_160 ) ;
V_164 = (struct V_163 * ) ( * V_160 + 1 ) ;
V_162 = 0 ;
while ( V_161 -- ) {
struct V_6 * V_30 = & V_164 -> V_166 ;
F_48 (FACILITY) {
T_4 V_167 ;
F_49 ( ( V_5 * ) & V_30 -> V_168 , & V_167 ) ;
F_2 ( L_13 ,
V_7 ,
F_47 ( V_30 -> V_169 ) ,
( unsigned long long ) V_167 ,
F_47 ( V_30 -> V_170 ) ) ;
}
V_162 += F_47 ( V_30 -> V_169 ) ;
++ V_164 ;
}
if ( V_159 ) {
V_5 * V_171 = ( V_5 * ) V_164 ;
if ( * V_171 ++ != V_75 )
return - 1 ;
V_164 = (struct V_163 * ) V_171 ;
}
if ( ( char * ) V_164 > V_34 + V_158 -> V_172 )
return - 1 ;
* V_160 = ( V_5 * ) V_164 ;
return V_162 ;
}
static unsigned long
F_50 ( struct V_21 * V_22 , char * V_173 , int V_174 , int V_175 )
{
unsigned long V_176 ;
int V_161 , V_177 , V_178 ;
char * V_179 ;
struct V_49 * * V_50 ;
int V_48 ;
V_22 -> V_25 . V_51 [ 0 ] . V_35 = V_173 ;
V_22 -> V_180 . V_51 [ 0 ] . V_35 = V_173 ;
V_178 = V_22 -> V_25 . V_51 [ 0 ] . V_36 ;
if ( V_178 > V_174 )
V_178 = V_174 ;
F_2 ( L_14 ,
V_7 , V_173 , V_174 , V_178 ) ;
V_173 += V_178 ;
V_174 -= V_178 ;
V_48 = V_22 -> V_25 . V_48 ;
V_50 = V_22 -> V_25 . V_54 + ( V_48 >> V_55 ) ;
V_48 &= ~ V_56 ;
V_176 = 0 ;
if ( V_174 && V_22 -> V_25 . V_53 ) {
int V_181 ;
V_181 = V_22 -> V_25 . V_53 ;
if ( V_181 > V_174 )
V_181 = V_174 ;
V_177 = F_51 ( V_48 + V_181 ) >> V_55 ;
for ( V_161 = 0 ; V_161 < V_177 ; V_161 ++ ) {
V_178 = V_41 - V_48 ;
if ( V_178 > V_181 )
V_178 = V_181 ;
F_2 ( L_15
L_16 ,
V_7 , V_161 , V_173 , V_174 , V_178 ) ;
V_179 = F_52 ( V_50 [ V_161 ] ) ;
memcpy ( V_179 + V_48 , V_173 , V_178 ) ;
F_53 ( V_50 [ V_161 ] ) ;
F_54 ( V_179 ) ;
V_173 += V_178 ;
V_174 -= V_178 ;
V_176 += V_178 ;
V_181 -= V_178 ;
if ( ! V_181 )
break;
V_48 = 0 ;
}
if ( V_175 )
V_173 -= V_175 ;
}
if ( V_174 || V_175 ) {
V_22 -> V_25 . V_61 [ 0 ] . V_35 = V_173 ;
V_22 -> V_180 . V_61 [ 0 ] . V_35 = V_173 ;
}
return V_176 ;
}
static bool
F_55 ( struct V_127 * V_128 )
{
V_5 * V_47 = ( V_5 * ) V_128 ;
if ( V_128 -> V_141 != V_142 )
return false ;
if ( V_128 -> V_152 . V_153 [ 0 ] != V_75 )
return false ;
if ( V_128 -> V_152 . V_153 [ 1 ] != V_75 )
return false ;
if ( V_128 -> V_152 . V_153 [ 2 ] != V_75 )
return false ;
if ( V_47 [ 7 ] != V_128 -> V_134 )
return false ;
if ( V_47 [ 8 ] != F_14 ( V_182 ) )
return false ;
return true ;
}
void
F_56 ( struct V_183 * V_184 )
{
struct V_157 * V_158 =
F_57 ( V_184 , struct V_157 , V_185 ) ;
struct V_127 * V_128 ;
struct V_70 * V_71 ;
struct V_21 * V_22 ;
struct V_8 * V_9 = V_158 -> V_186 ;
struct V_124 * V_125 = & V_9 -> V_187 ;
V_5 * V_64 ;
int V_188 , V_189 , V_190 ;
unsigned long V_191 ;
F_2 ( L_17 , V_7 , V_158 ) ;
if ( V_158 -> V_172 == V_192 )
goto V_193;
if ( V_158 -> V_172 < V_194 )
goto V_195;
V_128 = F_42 ( V_158 -> V_165 ) ;
#if F_39 ( V_131 )
if ( F_55 ( V_128 ) )
goto V_196;
#endif
F_58 ( & V_125 -> V_197 ) ;
V_22 = F_59 ( V_125 , V_128 -> V_134 ) ;
if ( ! V_22 )
goto V_198;
V_71 = F_38 ( V_22 ) ;
if ( V_71 -> V_199 )
goto V_200;
F_60 ( & V_22 -> V_201 ) ;
F_61 ( & V_125 -> V_197 ) ;
F_2 ( L_18 ,
V_7 , V_158 , V_71 , F_47 ( V_128 -> V_134 ) ) ;
V_71 -> V_199 = V_158 ;
V_125 -> V_202 = 0 ;
if ( V_128 -> V_136 != V_137 )
goto V_203;
switch ( V_128 -> V_141 ) {
case V_142 :
if ( V_128 -> V_152 . V_153 [ 0 ] != V_75 ||
( V_128 -> V_152 . V_153 [ 1 ] == V_75 &&
V_128 -> V_152 . V_153 [ 2 ] != V_75 ) ||
( V_128 -> V_152 . V_153 [ 1 ] != V_75 &&
F_62 ( & V_71 -> V_81 ) ) )
goto V_204;
if ( V_128 -> V_152 . V_153 [ 1 ] != V_75 ) {
V_64 = & V_128 -> V_152 . V_153 [ 2 ] ;
V_188 = F_46 ( V_158 , 1 , & V_64 ) ;
if ( V_188 < 0 || * V_64 ++ != V_75 )
goto V_204;
V_158 -> V_172 -=
( ( unsigned char * ) V_64 - ( unsigned char * ) V_128 ) ;
V_189 = V_158 -> V_172 + V_188 ;
V_9 -> V_85 . V_205 += V_188 ;
if ( V_188 &= 3 ) {
V_188 = 4 - V_188 ;
V_189 += V_188 ;
}
} else {
V_188 = 0 ;
V_64 = ( V_5 * ) ( ( unsigned char * ) V_128 +
V_3 ) ;
V_158 -> V_172 -= V_3 ;
V_189 = V_158 -> V_172 ;
}
V_9 -> V_85 . V_176 +=
F_50 ( V_22 , ( char * ) V_64 , V_158 -> V_172 ,
V_188 ) ;
break;
case V_206 :
if ( V_128 -> V_152 . V_153 [ 0 ] != V_75 ||
V_128 -> V_152 . V_153 [ 1 ] != V_75 ||
V_128 -> V_152 . V_153 [ 2 ] != V_82 ||
F_62 ( & V_71 -> V_81 ) )
goto V_204;
V_64 = ( V_5 * ) ( ( unsigned char * ) V_128 +
V_3 ) ;
V_188 = F_46 ( V_158 , 0 , & V_64 ) ;
if ( V_188 < 0 )
goto V_204;
V_9 -> V_85 . V_205 += V_188 ;
V_189 = V_188 ;
break;
case V_207 :
goto V_208;
V_204:
default:
F_2 ( L_19 ,
V_22 -> V_83 -> V_84 , V_7 ,
F_47 ( V_128 -> V_141 ) ) ;
V_189 = - V_63 ;
V_9 -> V_85 . V_209 ++ ;
break;
}
V_115:
if ( ! F_62 ( & V_71 -> V_81 ) )
V_9 -> V_15 . V_78 -> V_210 ( V_9 , V_71 ) ;
F_58 ( & V_125 -> V_197 ) ;
V_191 = V_125 -> V_191 ;
V_125 -> V_191 = F_63 ( & V_9 -> V_139 . V_211 ) << V_212 ;
if ( V_125 -> V_191 > V_191 )
F_64 ( V_22 -> V_83 ) ;
F_65 ( V_22 -> V_83 , V_189 ) ;
F_61 ( & V_125 -> V_197 ) ;
F_2 ( L_20 ,
V_7 , V_125 , V_22 , V_189 ) ;
return;
V_193:
F_66 ( V_158 ) ;
if ( V_9 -> V_213 . V_214 == 1 ) {
V_9 -> V_213 . V_214 = - V_63 ;
F_67 ( & V_9 -> V_213 ) ;
}
return;
#if F_39 ( V_131 )
V_196:
F_68 ( V_9 , V_158 ) ;
return;
#endif
V_203:
F_2 ( L_21 ,
V_7 , F_47 ( V_128 -> V_136 ) ) ;
V_189 = - V_63 ;
V_9 -> V_85 . V_209 ++ ;
goto V_115;
V_208:
V_190 = F_47 ( V_128 -> V_152 . V_215 . V_216 ) ;
switch ( V_190 ) {
case V_217 :
F_12 ( L_22 ,
V_7 ,
F_47 ( V_128 -> V_152 . V_215 . V_218 ) ,
F_47 ( V_128 -> V_152 . V_215 . V_219 ) ) ;
break;
case V_220 :
F_12 ( L_23 ,
V_7 ) ;
break;
default:
F_12 ( L_24 ,
V_7 , V_190 ) ;
}
V_189 = - V_221 ;
V_9 -> V_85 . V_209 ++ ;
goto V_115;
V_195:
F_2 ( L_25 , V_7 ) ;
goto V_222;
V_198:
F_61 ( & V_125 -> V_197 ) ;
F_2 ( L_26 ,
V_7 , F_47 ( V_128 -> V_134 ) ,
V_158 -> V_172 ) ;
goto V_222;
V_200:
F_61 ( & V_125 -> V_197 ) ;
F_2 ( L_27
L_28 ,
V_7 , V_158 , V_71 , F_47 ( V_128 -> V_134 ) ) ;
V_222:
V_9 -> V_85 . V_209 ++ ;
if ( F_69 ( & V_9 -> V_15 , V_158 ) )
F_66 ( V_158 ) ;
}
