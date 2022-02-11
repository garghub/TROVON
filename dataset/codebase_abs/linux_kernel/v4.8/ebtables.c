static void F_1 ( void * V_1 , const void * V_2 )
{
int V_3 = * ( V_4 * ) V_2 ;
if ( V_3 >= 0 )
V_3 += F_2 ( V_5 , V_3 ) ;
memcpy ( V_1 , & V_3 , sizeof( V_3 ) ) ;
}
static int F_3 ( void T_1 * V_1 , const void * V_2 )
{
V_4 V_6 = * ( int * ) V_2 ;
if ( V_6 >= 0 )
V_6 -= F_2 ( V_5 , V_6 ) ;
return F_4 ( V_1 , & V_6 , sizeof( V_6 ) ) ? - V_7 : 0 ;
}
static inline int
F_5 ( const struct V_8 * V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 )
{
V_13 -> V_14 = V_9 -> V_15 . V_16 ;
V_13 -> V_17 = V_9 -> V_18 ;
V_9 -> V_15 . V_16 -> V_14 ( V_11 , V_13 ) ;
return 0 ;
}
static inline int
F_6 ( struct V_19 * V_20 , const struct V_10 * V_11 ,
struct V_12 * V_13 )
{
V_13 -> V_21 = V_20 -> V_15 . V_21 ;
V_13 -> V_22 = V_20 -> V_18 ;
return V_20 -> V_15 . V_21 -> V_21 ( V_11 , V_13 ) ? V_23 : V_24 ;
}
static inline int
F_7 ( const char * V_25 , const struct V_26 * V_27 )
{
int V_28 = 0 ;
const char * V_29 ;
if ( * V_25 == '\0' )
return 0 ;
if ( ! V_27 )
return 1 ;
V_29 = V_27 -> V_30 ;
while ( V_25 [ V_28 ] != '\0' && V_25 [ V_28 ] != 1 && V_25 [ V_28 ] == V_29 [ V_28 ] )
V_28 ++ ;
return V_29 [ V_28 ] != V_25 [ V_28 ] && V_25 [ V_28 ] != 1 ;
}
static inline int
F_8 ( const struct V_31 * V_32 , const struct V_10 * V_11 ,
const struct V_26 * V_33 , const struct V_26 * V_34 )
{
const struct V_35 * V_36 = F_9 ( V_11 ) ;
const struct V_37 * V_38 ;
T_2 V_39 ;
if ( F_10 ( V_11 ) )
V_39 = F_11 ( V_40 ) ;
else
V_39 = V_36 -> V_41 ;
if ( V_32 -> V_42 & V_43 ) {
if ( F_12 ( V_32 , V_44 , F_13 ( V_39 ) ) )
return 1 ;
} else if ( ! ( V_32 -> V_42 & V_45 ) &&
F_12 ( V_32 , V_44 , V_32 -> V_39 != V_39 ) )
return 1 ;
if ( F_12 ( V_32 , V_46 , F_7 ( V_32 -> V_33 , V_33 ) ) )
return 1 ;
if ( F_12 ( V_32 , V_47 , F_7 ( V_32 -> V_34 , V_34 ) ) )
return 1 ;
if ( V_33 && ( V_38 = F_14 ( V_33 ) ) != NULL &&
F_12 ( V_32 , V_48 ,
F_7 ( V_32 -> V_49 , V_38 -> V_50 -> V_51 ) ) )
return 1 ;
if ( V_34 && ( V_38 = F_14 ( V_34 ) ) != NULL &&
F_12 ( V_32 , V_52 ,
F_7 ( V_32 -> V_53 , V_38 -> V_50 -> V_51 ) ) )
return 1 ;
if ( V_32 -> V_42 & V_54 ) {
if ( F_12 ( V_32 , V_55 ,
! F_15 ( V_36 -> V_56 , V_32 -> V_57 ,
V_32 -> V_58 ) ) )
return 1 ;
}
if ( V_32 -> V_42 & V_59 ) {
if ( F_12 ( V_32 , V_60 ,
! F_15 ( V_36 -> V_61 , V_32 -> V_62 ,
V_32 -> V_63 ) ) )
return 1 ;
}
return 0 ;
}
static inline
struct V_31 * F_16 ( const struct V_31 * V_25 )
{
return ( void * ) V_25 + V_25 -> V_64 ;
}
unsigned int F_17 ( struct V_10 * V_11 ,
const struct V_65 * V_66 ,
struct V_67 * V_68 )
{
unsigned int V_69 = V_66 -> V_69 ;
int V_28 , V_70 ;
struct V_31 * V_71 ;
struct V_72 * V_73 , * V_74 ;
const struct V_75 * V_76 ;
int V_77 , V_78 = 0 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
const char * V_83 ;
const struct V_84 * V_85 ;
struct V_12 V_86 ;
V_86 . V_87 = V_5 ;
V_86 . V_88 = V_66 -> V_88 ;
V_86 . V_33 = V_66 -> V_33 ;
V_86 . V_34 = V_66 -> V_34 ;
V_86 . V_89 = false ;
V_86 . V_90 = V_69 ;
F_18 ( & V_68 -> V_91 ) ;
V_85 = V_68 -> V_85 ;
V_74 = F_19 ( V_85 -> V_92 , V_85 -> V_70 ,
F_20 () ) ;
if ( V_85 -> V_93 )
V_80 = V_85 -> V_93 [ F_20 () ] ;
else
V_80 = NULL ;
V_82 = V_85 -> V_94 [ V_69 ] ;
V_70 = V_85 -> V_94 [ V_69 ] -> V_70 ;
V_71 = (struct V_31 * ) ( V_85 -> V_94 [ V_69 ] -> V_18 ) ;
V_73 = V_74 + V_85 -> V_94 [ V_69 ] -> V_95 ;
V_83 = V_85 -> V_96 ;
V_28 = 0 ;
while ( V_28 < V_70 ) {
if ( F_8 ( V_71 , V_11 , V_66 -> V_33 , V_66 -> V_34 ) )
goto V_97;
if ( F_21 ( V_71 , F_6 , V_11 , & V_86 ) != 0 )
goto V_97;
if ( V_86 . V_89 ) {
F_22 ( & V_68 -> V_91 ) ;
return V_98 ;
}
( * ( V_73 + V_28 ) ) . V_99 ++ ;
( * ( V_73 + V_28 ) ) . V_100 += V_11 -> V_101 ;
F_23 ( V_71 , F_5 , V_11 , & V_86 ) ;
V_76 = (struct V_75 * )
( ( ( char * ) V_71 ) + V_71 -> V_102 ) ;
if ( ! V_76 -> V_15 . V_14 -> V_14 )
V_77 = ( (struct V_103 * ) V_76 ) -> V_77 ;
else {
V_86 . V_14 = V_76 -> V_15 . V_14 ;
V_86 . V_17 = V_76 -> V_18 ;
V_77 = V_76 -> V_15 . V_14 -> V_14 ( V_11 , & V_86 ) ;
}
if ( V_77 == V_104 ) {
F_22 ( & V_68 -> V_91 ) ;
return V_105 ;
}
if ( V_77 == V_106 ) {
F_22 ( & V_68 -> V_91 ) ;
return V_98 ;
}
if ( V_77 == V_107 ) {
V_108:
#ifdef F_24
if ( V_78 == 0 ) {
F_25 ( L_1 ) ;
goto V_97;
}
#endif
V_78 -- ;
V_28 = V_80 [ V_78 ] . V_109 ;
V_82 = V_80 [ V_78 ] . V_82 ;
V_70 = V_82 -> V_70 ;
V_71 = V_80 [ V_78 ] . V_32 ;
V_73 = V_74 +
V_82 -> V_95 ;
continue;
}
if ( V_77 == V_110 )
goto V_97;
#ifdef F_24
if ( V_77 < 0 ) {
F_25 ( L_2 ) ;
F_22 ( & V_68 -> V_91 ) ;
return V_98 ;
}
#endif
V_80 [ V_78 ] . V_109 = V_28 + 1 ;
V_80 [ V_78 ] . V_82 = V_82 ;
V_80 [ V_78 ] . V_32 = F_16 ( V_71 ) ;
V_28 = 0 ;
V_82 = (struct V_81 * ) ( V_83 + V_77 ) ;
#ifdef F_24
if ( V_82 -> V_111 ) {
F_25 ( L_3 ) ;
F_22 ( & V_68 -> V_91 ) ;
return V_98 ;
}
#endif
V_70 = V_82 -> V_70 ;
V_71 = (struct V_31 * ) V_82 -> V_18 ;
V_73 = V_74 + V_82 -> V_95 ;
V_78 ++ ;
continue;
V_97:
V_71 = F_16 ( V_71 ) ;
V_28 ++ ;
}
if ( V_82 -> V_112 == V_107 )
goto V_108;
if ( V_82 -> V_112 == V_104 ) {
F_22 ( & V_68 -> V_91 ) ;
return V_105 ;
}
F_22 ( & V_68 -> V_91 ) ;
return V_98 ;
}
static inline void *
F_26 ( struct V_113 * V_114 , const char * V_30 , int * error ,
struct V_115 * V_115 )
{
struct {
struct V_113 V_116 ;
char V_30 [ V_117 ] ;
} * V_32 ;
F_27 ( V_115 ) ;
F_28 (e, head, list) {
if ( strcmp ( V_32 -> V_30 , V_30 ) == 0 )
return V_32 ;
}
* error = - V_118 ;
F_29 ( V_115 ) ;
return NULL ;
}
static void *
F_30 ( struct V_113 * V_114 , const char * V_30 , const char * V_119 ,
int * error , struct V_115 * V_115 )
{
return F_31 (
F_26 ( V_114 , V_30 , error , V_115 ) ,
L_4 , V_119 , V_30 ) ;
}
static inline struct V_67 *
F_32 ( struct V_88 * V_88 , const char * V_30 , int * error ,
struct V_115 * V_115 )
{
return F_30 ( & V_88 -> V_120 . V_121 [ V_5 ] , V_30 ,
L_5 , error , V_115 ) ;
}
static inline int
F_33 ( struct V_19 * V_20 , struct V_122 * V_13 ,
unsigned int * V_123 )
{
const struct V_31 * V_32 = V_13 -> V_124 ;
struct V_125 * V_21 ;
T_3 V_126 = ( ( char * ) V_32 + V_32 -> V_127 ) - ( char * ) V_20 ;
int V_128 ;
if ( V_126 < sizeof( struct V_19 ) ||
V_126 - sizeof( struct V_19 ) < V_20 -> V_129 )
return - V_130 ;
V_21 = F_34 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_21 ) || V_21 -> V_87 != V_5 ) {
if ( ! F_35 ( V_21 ) )
F_36 ( V_21 -> V_131 ) ;
F_37 ( L_6 , V_20 -> V_15 . V_30 ) ;
V_21 = F_34 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
}
if ( F_35 ( V_21 ) )
return F_38 ( V_21 ) ;
V_20 -> V_15 . V_21 = V_21 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_20 -> V_18 ;
V_128 = F_39 ( V_13 , V_20 -> V_129 ,
V_32 -> V_39 , V_32 -> V_132 & V_44 ) ;
if ( V_128 < 0 ) {
F_36 ( V_21 -> V_131 ) ;
return V_128 ;
}
( * V_123 ) ++ ;
return 0 ;
}
static inline int
F_40 ( struct V_8 * V_9 , struct V_133 * V_13 ,
unsigned int * V_123 )
{
const struct V_31 * V_32 = V_13 -> V_124 ;
struct V_134 * V_16 ;
T_3 V_126 = ( ( char * ) V_32 + V_32 -> V_102 ) - ( char * ) V_9 ;
int V_128 ;
if ( V_126 < sizeof( struct V_8 ) ||
V_126 - sizeof( struct V_8 ) < V_9 -> V_135 )
return - V_130 ;
V_16 = F_41 ( V_5 , V_9 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_16 ) )
return F_38 ( V_16 ) ;
V_9 -> V_15 . V_16 = V_16 ;
V_13 -> V_14 = V_16 ;
V_13 -> V_17 = V_9 -> V_18 ;
V_128 = F_42 ( V_13 , V_9 -> V_135 ,
V_32 -> V_39 , V_32 -> V_132 & V_44 ) ;
if ( V_128 < 0 ) {
F_36 ( V_16 -> V_131 ) ;
return V_128 ;
}
( * V_123 ) ++ ;
return 0 ;
}
static int F_43 ( const struct V_136 * V_137 ,
struct V_84 * V_138 )
{
unsigned int V_139 = V_137 -> V_140 ;
unsigned int V_141 = V_137 -> V_141 ;
unsigned int V_142 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ )
V_138 -> V_94 [ V_28 ] = NULL ;
V_138 -> V_140 = V_137 -> V_140 ;
V_138 -> V_70 = V_137 -> V_70 ;
while ( V_142 < V_139 ) {
T_3 V_126 = V_139 - V_142 ;
struct V_31 * V_32 = ( void * ) V_138 -> V_96 + V_142 ;
if ( V_126 < sizeof( unsigned int ) )
break;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( ( V_141 & ( 1 << V_28 ) ) == 0 )
continue;
if ( ( char T_1 * ) V_137 -> V_94 [ V_28 ] ==
V_137 -> V_96 + V_142 )
break;
}
if ( V_28 != V_143 || ! ( V_32 -> V_42 & V_144 ) ) {
if ( V_32 -> V_42 != 0 ) {
F_25 ( L_7
L_8 ) ;
return - V_130 ;
}
if ( V_28 != V_143 )
V_138 -> V_94 [ V_28 ] = (struct V_81 * ) V_32 ;
if ( V_126 < sizeof( struct V_81 ) )
break;
V_142 += sizeof( struct V_81 ) ;
} else {
if ( V_126 < sizeof( struct V_31 ) )
break;
if ( V_126 < V_32 -> V_64 )
break;
if ( V_32 -> V_64 < sizeof( struct V_31 ) )
return - V_130 ;
V_142 += V_32 -> V_64 ;
}
}
if ( V_142 != V_139 ) {
F_25 ( L_9 ) ;
return - V_130 ;
}
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( ! V_138 -> V_94 [ V_28 ] &&
( V_141 & ( 1 << V_28 ) ) ) {
F_25 ( L_10 ) ;
return - V_130 ;
}
}
return 0 ;
}
static inline int
F_44 ( const struct V_31 * V_32 ,
const struct V_84 * V_138 ,
unsigned int * V_109 , unsigned int * V_123 ,
unsigned int * V_145 , unsigned int * V_146 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( ( void * ) V_32 == ( void * ) V_138 -> V_94 [ V_28 ] )
break;
}
if ( V_28 != V_143 || ! V_32 -> V_42 ) {
if ( * V_109 != * V_123 ) {
F_25 ( L_11
L_12 ) ;
return - V_130 ;
}
if ( ( (struct V_81 * ) V_32 ) -> V_112 != V_106 &&
( (struct V_81 * ) V_32 ) -> V_112 != V_104 ) {
if ( V_28 != V_143 ||
( (struct V_81 * ) V_32 ) -> V_112 != V_107 ) {
F_25 ( L_13 ) ;
return - V_130 ;
}
}
if ( V_28 == V_143 )
( * V_146 ) ++ ;
if ( ( (struct V_81 * ) V_32 ) -> V_95 != * V_145 ) {
F_25 ( L_14 ) ;
return - V_130 ;
}
* V_109 = ( (struct V_81 * ) V_32 ) -> V_70 ;
* V_123 = 0 ;
return 0 ;
}
if ( sizeof( struct V_31 ) > V_32 -> V_127 ||
V_32 -> V_127 > V_32 -> V_102 ||
V_32 -> V_102 >= V_32 -> V_64 ) {
F_25 ( L_15 ) ;
return - V_130 ;
}
if ( V_32 -> V_64 - V_32 -> V_102 < sizeof( struct V_75 ) ) {
F_25 ( L_16 ) ;
return - V_130 ;
}
( * V_123 ) ++ ;
( * V_145 ) ++ ;
return 0 ;
}
static inline int
F_45 ( struct V_31 * V_32 , struct V_84 * V_138 ,
unsigned int * V_109 , struct V_147 * V_148 )
{
int V_28 ;
if ( V_32 -> V_42 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( V_138 -> V_94 [ V_28 ] == (struct V_81 * ) V_32 )
break;
}
if ( V_28 != V_143 )
return 0 ;
V_148 [ * V_109 ] . V_80 . V_82 = (struct V_81 * ) V_32 ;
V_148 [ * V_109 ] . V_80 . V_109 = 0 ;
V_148 [ * V_109 ] . V_149 = 0 ;
( * V_109 ) ++ ;
return 0 ;
}
static inline int
F_46 ( struct V_19 * V_20 , struct V_88 * V_88 , unsigned int * V_28 )
{
struct V_150 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_88 = V_88 ;
V_13 . V_21 = V_20 -> V_15 . V_21 ;
V_13 . V_22 = V_20 -> V_18 ;
V_13 . V_87 = V_5 ;
if ( V_13 . V_21 -> V_151 != NULL )
V_13 . V_21 -> V_151 ( & V_13 ) ;
F_36 ( V_13 . V_21 -> V_131 ) ;
return 0 ;
}
static inline int
F_47 ( struct V_8 * V_9 , struct V_88 * V_88 , unsigned int * V_28 )
{
struct V_152 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_88 = V_88 ;
V_13 . V_14 = V_9 -> V_15 . V_16 ;
V_13 . V_17 = V_9 -> V_18 ;
V_13 . V_87 = V_5 ;
if ( V_13 . V_14 -> V_151 != NULL )
V_13 . V_14 -> V_151 ( & V_13 ) ;
F_36 ( V_13 . V_14 -> V_131 ) ;
return 0 ;
}
static inline int
F_48 ( struct V_31 * V_32 , struct V_88 * V_88 , unsigned int * V_123 )
{
struct V_152 V_13 ;
struct V_75 * V_76 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
if ( V_123 && ( * V_123 ) -- == 0 )
return 1 ;
F_23 ( V_32 , F_47 , V_88 , NULL ) ;
F_21 ( V_32 , F_46 , V_88 , NULL ) ;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_102 ) ;
V_13 . V_88 = V_88 ;
V_13 . V_14 = V_76 -> V_15 . V_14 ;
V_13 . V_17 = V_76 -> V_18 ;
V_13 . V_87 = V_5 ;
if ( V_13 . V_14 -> V_151 != NULL )
V_13 . V_14 -> V_151 ( & V_13 ) ;
F_36 ( V_13 . V_14 -> V_131 ) ;
return 0 ;
}
static inline int
F_49 ( struct V_31 * V_32 , struct V_88 * V_88 ,
const struct V_84 * V_138 ,
const char * V_30 , unsigned int * V_123 ,
struct V_147 * V_153 , unsigned int V_146 )
{
struct V_75 * V_76 ;
struct V_134 * V_14 ;
unsigned int V_28 , V_154 , V_69 = 0 , V_149 = 0 ;
T_3 V_155 ;
int V_128 ;
struct V_122 V_156 ;
struct V_133 V_157 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
if ( V_32 -> V_42 & ~ V_158 ) {
F_25 ( L_17 ) ;
return - V_130 ;
}
if ( V_32 -> V_132 & ~ V_159 ) {
F_25 ( L_18 ) ;
return - V_130 ;
}
if ( ( V_32 -> V_42 & V_45 ) && ( V_32 -> V_42 & V_43 ) ) {
F_25 ( L_19 ) ;
return - V_130 ;
}
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( ! V_138 -> V_94 [ V_28 ] )
continue;
if ( ( char * ) V_138 -> V_94 [ V_28 ] < ( char * ) V_32 )
V_69 = V_28 ;
else
break;
}
if ( V_28 < V_143 )
V_149 = ( 1 << V_69 ) | ( 1 << V_143 ) ;
else {
for ( V_28 = 0 ; V_28 < V_146 ; V_28 ++ )
if ( ( char * ) ( V_153 [ V_28 ] . V_80 . V_82 ) > ( char * ) V_32 )
break;
if ( V_28 == 0 )
V_149 = ( 1 << V_69 ) | ( 1 << V_143 ) ;
else
V_149 = V_153 [ V_28 - 1 ] . V_149 ;
}
V_28 = 0 ;
V_156 . V_88 = V_157 . V_88 = V_88 ;
V_156 . V_68 = V_157 . V_68 = V_30 ;
V_156 . V_124 = V_157 . V_124 = V_32 ;
V_156 . V_160 = V_157 . V_160 = V_149 ;
V_156 . V_87 = V_157 . V_87 = V_5 ;
V_128 = F_21 ( V_32 , F_33 , & V_156 , & V_28 ) ;
if ( V_128 != 0 )
goto V_161;
V_154 = 0 ;
V_128 = F_23 ( V_32 , F_40 , & V_157 , & V_154 ) ;
if ( V_128 != 0 )
goto V_162;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_102 ) ;
V_155 = V_32 -> V_64 - V_32 -> V_102 ;
V_14 = F_41 ( V_5 , V_76 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_14 ) ) {
V_128 = F_38 ( V_14 ) ;
goto V_162;
}
V_76 -> V_15 . V_14 = V_14 ;
if ( V_76 -> V_15 . V_14 == & V_103 ) {
if ( V_155 < sizeof( struct V_103 ) ) {
F_25 ( L_20 ) ;
V_128 = - V_7 ;
goto V_162;
}
if ( ( (struct V_103 * ) V_76 ) -> V_77 <
- V_163 ) {
F_25 ( L_21 ) ;
V_128 = - V_7 ;
goto V_162;
}
} else if ( V_76 -> V_164 > V_155 - sizeof( struct V_75 ) ) {
F_36 ( V_76 -> V_15 . V_14 -> V_131 ) ;
V_128 = - V_7 ;
goto V_162;
}
V_157 . V_14 = V_14 ;
V_157 . V_17 = V_76 -> V_18 ;
V_128 = F_42 ( & V_157 , V_76 -> V_164 ,
V_32 -> V_39 , V_32 -> V_132 & V_44 ) ;
if ( V_128 < 0 ) {
F_36 ( V_14 -> V_131 ) ;
goto V_162;
}
( * V_123 ) ++ ;
return 0 ;
V_162:
F_23 ( V_32 , F_47 , V_88 , & V_154 ) ;
V_161:
F_21 ( V_32 , F_46 , V_88 , & V_28 ) ;
return V_128 ;
}
static int F_50 ( const struct V_81 * V_165 , struct V_147 * V_153 ,
unsigned int V_146 , unsigned int V_166 , char * V_83 )
{
int V_28 , V_167 = - 1 , V_168 = 0 , V_70 = V_165 -> V_70 , V_77 ;
const struct V_31 * V_32 = (struct V_31 * ) V_165 -> V_18 ;
const struct V_75 * V_76 ;
while ( V_168 < V_70 || V_167 != - 1 ) {
if ( V_168 == V_70 ) {
V_32 = V_153 [ V_167 ] . V_80 . V_32 ;
if ( V_153 [ V_167 ] . V_169 != - 1 )
V_70 =
V_153 [ V_153 [ V_167 ] . V_169 ] . V_80 . V_82 -> V_70 ;
else
V_70 = V_165 -> V_70 ;
V_168 = V_153 [ V_167 ] . V_80 . V_109 ;
V_153 [ V_167 ] . V_80 . V_109 = 0 ;
V_167 = V_153 [ V_167 ] . V_169 ;
if ( V_168 == V_70 )
continue;
}
V_76 = (struct V_75 * )
( ( ( char * ) V_32 ) + V_32 -> V_102 ) ;
if ( strcmp ( V_76 -> V_15 . V_30 , V_170 ) )
goto V_97;
if ( V_32 -> V_102 + sizeof( struct V_103 ) >
V_32 -> V_64 ) {
F_25 ( L_20 ) ;
return - 1 ;
}
V_77 = ( (struct V_103 * ) V_76 ) -> V_77 ;
if ( V_77 >= 0 ) {
struct V_81 * V_171 =
(struct V_81 * ) ( V_83 + V_77 ) ;
for ( V_28 = 0 ; V_28 < V_146 ; V_28 ++ )
if ( V_171 == V_153 [ V_28 ] . V_80 . V_82 )
break;
if ( V_28 == V_146 ) {
F_25 ( L_22 ) ;
return - 1 ;
}
if ( V_153 [ V_28 ] . V_80 . V_109 ) {
F_25 ( L_23 ) ;
return - 1 ;
}
if ( V_153 [ V_28 ] . V_149 & ( 1 << V_166 ) )
goto V_97;
V_153 [ V_28 ] . V_80 . V_109 = V_168 + 1 ;
V_168 = 0 ;
V_153 [ V_28 ] . V_80 . V_32 = F_16 ( V_32 ) ;
V_32 = (struct V_31 * ) ( V_171 -> V_18 ) ;
V_70 = V_171 -> V_70 ;
V_153 [ V_28 ] . V_169 = V_167 ;
V_167 = V_28 ;
V_153 [ V_28 ] . V_149 |= ( 1 << V_166 ) ;
continue;
}
V_97:
V_32 = F_16 ( V_32 ) ;
V_168 ++ ;
}
return 0 ;
}
static int F_51 ( struct V_88 * V_88 , const char * V_30 ,
struct V_84 * V_138 )
{
unsigned int V_28 , V_154 , V_172 , V_146 ;
int V_128 ;
struct V_147 * V_153 = NULL ;
V_28 = 0 ;
while ( V_28 < V_143 && ! V_138 -> V_94 [ V_28 ] )
V_28 ++ ;
if ( V_28 == V_143 ) {
F_25 ( L_24 ) ;
return - V_130 ;
}
if ( V_138 -> V_94 [ V_28 ] != (struct V_81 * ) V_138 -> V_96 ) {
F_25 ( L_25 ) ;
return - V_130 ;
}
for ( V_154 = V_28 + 1 ; V_154 < V_143 ; V_154 ++ ) {
if ( ! V_138 -> V_94 [ V_154 ] )
continue;
if ( V_138 -> V_94 [ V_154 ] <= V_138 -> V_94 [ V_28 ] ) {
F_25 ( L_26 ) ;
return - V_130 ;
}
V_28 = V_154 ;
}
V_28 = 0 ;
V_154 = 0 ;
V_172 = 0 ;
V_146 = 0 ;
V_128 = F_52 ( V_138 -> V_96 , V_138 -> V_140 ,
F_44 , V_138 ,
& V_28 , & V_154 , & V_172 , & V_146 ) ;
if ( V_128 != 0 )
return V_128 ;
if ( V_28 != V_154 ) {
F_25 ( L_27
L_28 ) ;
return - V_130 ;
}
if ( V_172 != V_138 -> V_70 ) {
F_25 ( L_29 ) ;
return - V_130 ;
}
if ( V_146 ) {
V_138 -> V_93 =
F_53 ( V_173 * sizeof( * ( V_138 -> V_93 ) ) ) ;
if ( ! V_138 -> V_93 )
return - V_174 ;
F_54 (i) {
V_138 -> V_93 [ V_28 ] =
F_53 ( V_146 * sizeof( * ( V_138 -> V_93 [ 0 ] ) ) ) ;
if ( ! V_138 -> V_93 [ V_28 ] ) {
while ( V_28 )
F_55 ( V_138 -> V_93 [ -- V_28 ] ) ;
F_55 ( V_138 -> V_93 ) ;
V_138 -> V_93 = NULL ;
return - V_174 ;
}
}
V_153 = F_53 ( V_146 * sizeof( * V_153 ) ) ;
if ( ! V_153 )
return - V_174 ;
V_28 = 0 ;
F_52 ( V_138 -> V_96 , V_138 -> V_140 ,
F_45 , V_138 , & V_28 , V_153 ) ;
if ( V_28 != V_146 ) {
F_25 ( L_30 ) ;
F_55 ( V_153 ) ;
return - V_7 ;
}
}
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ )
if ( V_138 -> V_94 [ V_28 ] )
if ( F_50 ( V_138 -> V_94 [ V_28 ] ,
V_153 , V_146 , V_28 , V_138 -> V_96 ) ) {
F_55 ( V_153 ) ;
return - V_130 ;
}
V_28 = 0 ;
V_128 = F_52 ( V_138 -> V_96 , V_138 -> V_140 ,
F_49 , V_88 , V_138 , V_30 , & V_28 , V_153 , V_146 ) ;
if ( V_128 != 0 ) {
F_52 ( V_138 -> V_96 , V_138 -> V_140 ,
F_48 , V_88 , & V_28 ) ;
}
F_55 ( V_153 ) ;
return V_128 ;
}
static void F_56 ( const struct V_72 * V_175 ,
struct V_72 * V_92 , unsigned int V_70 )
{
int V_28 , V_176 ;
struct V_72 * V_73 ;
memcpy ( V_92 , V_175 ,
sizeof( struct V_72 ) * V_70 ) ;
F_54 (cpu) {
if ( V_176 == 0 )
continue;
V_73 = F_19 ( V_175 , V_70 , V_176 ) ;
for ( V_28 = 0 ; V_28 < V_70 ; V_28 ++ ) {
V_92 [ V_28 ] . V_99 += V_73 [ V_28 ] . V_99 ;
V_92 [ V_28 ] . V_100 += V_73 [ V_28 ] . V_100 ;
}
}
}
static int F_57 ( struct V_88 * V_88 , struct V_136 * V_137 ,
struct V_84 * V_138 )
{
int V_128 , V_28 ;
struct V_72 * V_177 = NULL ;
struct V_84 * V_68 ;
struct V_67 * V_76 ;
if ( V_137 -> V_178 ) {
unsigned long V_179 = V_137 -> V_178 * sizeof( * V_177 ) ;
V_177 = F_53 ( V_179 ) ;
if ( ! V_177 )
return - V_174 ;
}
V_138 -> V_93 = NULL ;
V_128 = F_43 ( V_137 , V_138 ) ;
if ( V_128 != 0 )
goto V_180;
V_128 = F_51 ( V_88 , V_137 -> V_30 , V_138 ) ;
if ( V_128 != 0 )
goto V_180;
V_76 = F_32 ( V_88 , V_137 -> V_30 , & V_128 , & V_181 ) ;
if ( ! V_76 ) {
V_128 = - V_118 ;
goto V_182;
}
if ( V_76 -> V_183 && ( V_128 = V_76 -> V_183 ( V_138 , V_137 -> V_141 ) ) )
goto V_184;
if ( V_137 -> V_178 && V_137 -> V_178 != V_76 -> V_85 -> V_70 ) {
F_25 ( L_31 ) ;
V_128 = - V_130 ;
goto V_184;
}
V_68 = V_76 -> V_85 ;
if ( ! V_68 -> V_70 && V_138 -> V_70 && ! F_58 ( V_76 -> V_131 ) ) {
V_128 = - V_118 ;
goto V_184;
} else if ( V_68 -> V_70 && ! V_138 -> V_70 )
F_36 ( V_76 -> V_131 ) ;
F_59 ( & V_76 -> V_91 ) ;
if ( V_137 -> V_178 )
F_56 ( V_76 -> V_85 -> V_92 , V_177 ,
V_76 -> V_85 -> V_70 ) ;
V_76 -> V_85 = V_138 ;
F_60 ( & V_76 -> V_91 ) ;
F_29 ( & V_181 ) ;
if ( V_137 -> V_178 &&
F_4 ( V_137 -> V_92 , V_177 ,
V_137 -> V_178 * sizeof( struct V_72 ) ) ) {
F_61 ( L_32 ) ;
}
F_52 ( V_68 -> V_96 , V_68 -> V_140 ,
F_48 , V_88 , NULL ) ;
F_55 ( V_68 -> V_96 ) ;
if ( V_68 -> V_93 ) {
F_54 (i)
F_55 ( V_68 -> V_93 [ V_28 ] ) ;
F_55 ( V_68 -> V_93 ) ;
}
F_55 ( V_68 ) ;
F_55 ( V_177 ) ;
#ifdef F_62
if ( V_185 ) {
struct V_186 * V_187 ;
V_187 = F_63 ( V_188 -> V_189 , V_190 ,
V_191 ) ;
if ( V_187 ) {
F_64 ( V_187 , L_33 ,
V_137 -> V_30 , V_192 , V_137 -> V_70 ) ;
F_65 ( V_187 ) ;
}
}
#endif
return V_128 ;
V_184:
F_29 ( & V_181 ) ;
V_182:
F_52 ( V_138 -> V_96 , V_138 -> V_140 ,
F_48 , V_88 , NULL ) ;
V_180:
F_55 ( V_177 ) ;
if ( V_138 -> V_93 ) {
F_54 (i)
F_55 ( V_138 -> V_93 [ V_28 ] ) ;
F_55 ( V_138 -> V_93 ) ;
}
return V_128 ;
}
static int F_66 ( struct V_88 * V_88 , const void T_1 * V_193 ,
unsigned int V_101 )
{
int V_128 , V_194 ;
struct V_84 * V_138 ;
struct V_136 V_195 ;
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) != 0 )
return - V_7 ;
if ( V_101 != sizeof( V_195 ) + V_195 . V_140 ) {
F_25 ( L_34 ) ;
return - V_130 ;
}
if ( V_195 . V_140 == 0 ) {
F_25 ( L_35 ) ;
return - V_130 ;
}
if ( V_195 . V_70 >= ( ( V_196 - sizeof( struct V_84 ) ) /
V_197 - V_198 ) / sizeof( struct V_72 ) )
return - V_174 ;
if ( V_195 . V_178 >= V_196 / sizeof( struct V_72 ) )
return - V_174 ;
V_195 . V_30 [ sizeof( V_195 . V_30 ) - 1 ] = 0 ;
V_194 = F_68 ( V_195 . V_70 ) * V_173 ;
V_138 = F_53 ( sizeof( * V_138 ) + V_194 ) ;
if ( ! V_138 )
return - V_174 ;
if ( V_194 )
memset ( V_138 -> V_92 , 0 , V_194 ) ;
V_138 -> V_96 = F_53 ( V_195 . V_140 ) ;
if ( ! V_138 -> V_96 ) {
V_128 = - V_174 ;
goto V_199;
}
if ( F_67 (
V_138 -> V_96 , V_195 . V_96 , V_195 . V_140 ) != 0 ) {
F_25 ( L_36 ) ;
V_128 = - V_7 ;
goto V_200;
}
V_128 = F_57 ( V_88 , & V_195 , V_138 ) ;
if ( V_128 == 0 )
return V_128 ;
V_200:
F_55 ( V_138 -> V_96 ) ;
V_199:
F_55 ( V_138 ) ;
return V_128 ;
}
struct V_67 *
F_69 ( struct V_88 * V_88 , const struct V_67 * V_201 )
{
struct V_84 * V_138 ;
struct V_67 * V_76 , * V_68 ;
struct V_202 * V_137 ;
int V_128 , V_28 , V_194 ;
void * V_38 ;
if ( V_201 == NULL || ( V_137 = V_201 -> V_68 ) == NULL ||
V_137 -> V_96 == NULL || V_137 -> V_140 == 0 ||
V_137 -> V_92 != NULL || V_201 -> V_85 != NULL ) {
F_25 ( L_37 ) ;
return F_70 ( - V_130 ) ;
}
V_68 = F_71 ( V_201 , sizeof( struct V_67 ) , V_190 ) ;
if ( ! V_68 ) {
V_128 = - V_174 ;
goto V_34;
}
V_194 = F_68 ( V_137 -> V_70 ) * V_173 ;
V_138 = F_53 ( sizeof( * V_138 ) + V_194 ) ;
V_128 = - V_174 ;
if ( ! V_138 )
goto V_203;
V_38 = F_53 ( V_137 -> V_140 ) ;
if ( ! V_38 )
goto V_199;
memcpy ( V_38 , V_137 -> V_96 , V_137 -> V_140 ) ;
V_138 -> V_96 = V_38 ;
V_138 -> V_140 = V_137 -> V_140 ;
V_138 -> V_70 = V_137 -> V_70 ;
if ( V_194 )
memset ( V_138 -> V_92 , 0 , V_194 ) ;
V_138 -> V_93 = NULL ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
if ( ( V_137 -> V_141 & ( 1 << V_28 ) ) == 0 )
V_138 -> V_94 [ V_28 ] = NULL ;
else
V_138 -> V_94 [ V_28 ] = V_38 +
( ( char * ) V_137 -> V_94 [ V_28 ] - V_137 -> V_96 ) ;
}
V_128 = F_51 ( V_88 , V_137 -> V_30 , V_138 ) ;
if ( V_128 != 0 ) {
F_25 ( L_38 ) ;
goto V_204;
}
if ( V_68 -> V_183 && V_68 -> V_183 ( V_138 , V_68 -> V_141 ) ) {
F_25 ( L_39 ) ;
V_128 = - V_130 ;
goto V_204;
}
V_68 -> V_85 = V_138 ;
F_72 ( & V_68 -> V_91 ) ;
F_27 ( & V_181 ) ;
F_28 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_76 -> V_30 , V_68 -> V_30 ) == 0 ) {
V_128 = - V_205 ;
F_25 ( L_40 ) ;
goto V_184;
}
}
if ( V_138 -> V_70 && ! F_58 ( V_68 -> V_131 ) ) {
V_128 = - V_118 ;
goto V_184;
}
F_73 ( & V_68 -> V_116 , & V_88 -> V_120 . V_121 [ V_5 ] ) ;
F_29 ( & V_181 ) ;
return V_68 ;
V_184:
F_29 ( & V_181 ) ;
V_204:
if ( V_138 -> V_93 ) {
F_54 (i)
F_55 ( V_138 -> V_93 [ V_28 ] ) ;
F_55 ( V_138 -> V_93 ) ;
}
F_55 ( V_138 -> V_96 ) ;
V_199:
F_55 ( V_138 ) ;
V_203:
F_74 ( V_68 ) ;
V_34:
return F_70 ( V_128 ) ;
}
void F_75 ( struct V_88 * V_88 , struct V_67 * V_68 )
{
int V_28 ;
if ( ! V_68 ) {
F_25 ( L_41 ) ;
return;
}
F_27 ( & V_181 ) ;
F_76 ( & V_68 -> V_116 ) ;
F_29 ( & V_181 ) ;
F_52 ( V_68 -> V_85 -> V_96 , V_68 -> V_85 -> V_140 ,
F_48 , V_88 , NULL ) ;
if ( V_68 -> V_85 -> V_70 )
F_36 ( V_68 -> V_131 ) ;
F_55 ( V_68 -> V_85 -> V_96 ) ;
if ( V_68 -> V_85 -> V_93 ) {
F_54 (i)
F_55 ( V_68 -> V_85 -> V_93 [ V_28 ] ) ;
F_55 ( V_68 -> V_85 -> V_93 ) ;
}
F_55 ( V_68 -> V_85 ) ;
F_74 ( V_68 ) ;
}
static int F_77 ( struct V_88 * V_88 , const char * V_30 ,
struct V_72 T_1 * V_92 ,
unsigned int V_178 ,
const void T_1 * V_193 , unsigned int V_101 )
{
int V_28 , V_128 ;
struct V_72 * V_195 ;
struct V_67 * V_76 ;
if ( V_178 == 0 )
return - V_130 ;
V_195 = F_53 ( V_178 * sizeof( * V_195 ) ) ;
if ( ! V_195 )
return - V_174 ;
V_76 = F_32 ( V_88 , V_30 , & V_128 , & V_181 ) ;
if ( ! V_76 )
goto V_206;
if ( V_178 != V_76 -> V_85 -> V_70 ) {
F_25 ( L_42 ) ;
V_128 = - V_130 ;
goto V_207;
}
if ( F_67 ( V_195 , V_92 , V_178 * sizeof( * V_92 ) ) ) {
V_128 = - V_7 ;
goto V_207;
}
F_59 ( & V_76 -> V_91 ) ;
for ( V_28 = 0 ; V_28 < V_178 ; V_28 ++ ) {
V_76 -> V_85 -> V_92 [ V_28 ] . V_99 += V_195 [ V_28 ] . V_99 ;
V_76 -> V_85 -> V_92 [ V_28 ] . V_100 += V_195 [ V_28 ] . V_100 ;
}
F_60 ( & V_76 -> V_91 ) ;
V_128 = 0 ;
V_207:
F_29 ( & V_181 ) ;
V_206:
F_55 ( V_195 ) ;
return V_128 ;
}
static int F_78 ( struct V_88 * V_88 , const void T_1 * V_193 ,
unsigned int V_101 )
{
struct V_136 V_208 ;
if ( F_67 ( & V_208 , V_193 , sizeof( V_208 ) ) )
return - V_7 ;
if ( V_101 != sizeof( V_208 ) + V_208 . V_178 * sizeof( struct V_72 ) )
return - V_130 ;
return F_77 ( V_88 , V_208 . V_30 , V_208 . V_92 ,
V_208 . V_178 , V_193 , V_101 ) ;
}
static inline int F_79 ( const struct V_19 * V_20 ,
const char * V_83 , char T_1 * V_209 )
{
char T_1 * V_208 = V_209 + ( ( char * ) V_20 - V_83 ) ;
char V_30 [ V_117 ] = {} ;
F_80 ( V_30 , V_20 -> V_15 . V_21 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_208 , V_30 , V_117 ) )
return - V_7 ;
return 0 ;
}
static inline int F_81 ( const struct V_8 * V_9 ,
const char * V_83 , char T_1 * V_209 )
{
char T_1 * V_208 = V_209 + ( ( char * ) V_9 - V_83 ) ;
char V_30 [ V_117 ] = {} ;
F_80 ( V_30 , V_9 -> V_15 . V_16 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_208 , V_30 , V_117 ) )
return - V_7 ;
return 0 ;
}
static inline int F_82 ( struct V_31 * V_32 , const char * V_83 ,
char T_1 * V_209 )
{
int V_128 ;
char T_1 * V_208 ;
const struct V_75 * V_76 ;
char V_30 [ V_117 ] = {} ;
if ( V_32 -> V_42 == 0 )
return 0 ;
V_208 = V_209 + ( ( ( char * ) V_32 + V_32 -> V_102 ) - V_83 ) ;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_102 ) ;
V_128 = F_21 ( V_32 , F_79 , V_83 , V_209 ) ;
if ( V_128 != 0 )
return V_128 ;
V_128 = F_23 ( V_32 , F_81 , V_83 , V_209 ) ;
if ( V_128 != 0 )
return V_128 ;
F_80 ( V_30 , V_76 -> V_15 . V_14 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_208 , V_30 , V_117 ) )
return - V_7 ;
return 0 ;
}
static int F_83 ( struct V_67 * V_76 ,
const struct V_72 * V_175 ,
void T_1 * V_193 , unsigned int V_178 ,
unsigned int V_70 )
{
struct V_72 * V_177 ;
int V_128 = 0 ;
if ( V_178 == 0 )
return 0 ;
if ( V_178 != V_70 ) {
F_25 ( L_43 ) ;
return - V_130 ;
}
V_177 = F_53 ( V_70 * sizeof( * V_177 ) ) ;
if ( ! V_177 )
return - V_174 ;
F_59 ( & V_76 -> V_91 ) ;
F_56 ( V_175 , V_177 , V_70 ) ;
F_60 ( & V_76 -> V_91 ) ;
if ( F_4 ( V_193 , V_177 ,
V_70 * sizeof( struct V_72 ) ) )
V_128 = - V_7 ;
F_55 ( V_177 ) ;
return V_128 ;
}
static int F_84 ( struct V_67 * V_76 , void T_1 * V_193 ,
const int * V_101 , int V_210 )
{
struct V_136 V_195 ;
const struct V_72 * V_175 ;
unsigned int V_140 , V_70 ;
int V_128 ;
char * V_96 ;
if ( V_210 == V_211 ) {
V_140 = V_76 -> V_85 -> V_140 ;
V_70 = V_76 -> V_85 -> V_70 ;
V_96 = V_76 -> V_85 -> V_96 ;
V_175 = V_76 -> V_85 -> V_92 ;
} else {
V_140 = V_76 -> V_68 -> V_140 ;
V_70 = V_76 -> V_68 -> V_70 ;
V_96 = V_76 -> V_68 -> V_96 ;
V_175 = V_76 -> V_68 -> V_92 ;
}
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) )
return - V_7 ;
if ( * V_101 != sizeof( struct V_136 ) + V_140 +
( V_195 . V_178 ? V_70 * sizeof( struct V_72 ) : 0 ) )
return - V_130 ;
if ( V_195 . V_70 != V_70 ) {
F_25 ( L_44 ) ;
return - V_130 ;
}
if ( V_195 . V_140 != V_140 ) {
F_25 ( L_45 ) ;
return - V_130 ;
}
V_128 = F_83 ( V_76 , V_175 , V_195 . V_92 ,
V_195 . V_178 , V_70 ) ;
if ( V_128 )
return V_128 ;
if ( F_4 ( V_195 . V_96 , V_96 , V_140 ) ) {
F_25 ( L_46 ) ;
return - V_7 ;
}
return F_52 ( V_96 , V_140 ,
F_82 , V_96 , V_195 . V_96 ) ;
}
static int F_85 ( struct V_212 * V_213 ,
int V_210 , void T_1 * V_193 , unsigned int V_101 )
{
int V_128 ;
struct V_88 * V_88 = F_86 ( V_213 ) ;
if ( ! F_87 ( V_88 -> V_214 , V_215 ) )
return - V_216 ;
switch ( V_210 ) {
case V_217 :
V_128 = F_66 ( V_88 , V_193 , V_101 ) ;
break;
case V_218 :
V_128 = F_78 ( V_88 , V_193 , V_101 ) ;
break;
default:
V_128 = - V_130 ;
}
return V_128 ;
}
static int F_88 ( struct V_212 * V_213 , int V_210 , void T_1 * V_193 , int * V_101 )
{
int V_128 ;
struct V_136 V_195 ;
struct V_67 * V_76 ;
struct V_88 * V_88 = F_86 ( V_213 ) ;
if ( ! F_87 ( V_88 -> V_214 , V_215 ) )
return - V_216 ;
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) )
return - V_7 ;
V_195 . V_30 [ sizeof( V_195 . V_30 ) - 1 ] = '\0' ;
V_76 = F_32 ( V_88 , V_195 . V_30 , & V_128 , & V_181 ) ;
if ( ! V_76 )
return V_128 ;
switch ( V_210 ) {
case V_219 :
case V_220 :
if ( * V_101 != sizeof( struct V_136 ) ) {
V_128 = - V_130 ;
F_29 ( & V_181 ) ;
break;
}
if ( V_210 == V_219 ) {
V_195 . V_70 = V_76 -> V_85 -> V_70 ;
V_195 . V_140 = V_76 -> V_85 -> V_140 ;
V_195 . V_141 = V_76 -> V_141 ;
} else {
V_195 . V_70 = V_76 -> V_68 -> V_70 ;
V_195 . V_140 = V_76 -> V_68 -> V_140 ;
V_195 . V_141 = V_76 -> V_68 -> V_141 ;
}
F_29 ( & V_181 ) ;
if ( F_4 ( V_193 , & V_195 , * V_101 ) != 0 ) {
F_25 ( L_47 ) ;
V_128 = - V_7 ;
break;
}
V_128 = 0 ;
break;
case V_211 :
case V_221 :
V_128 = F_84 ( V_76 , V_193 , V_101 , V_210 ) ;
F_29 ( & V_181 ) ;
break;
default:
F_29 ( & V_181 ) ;
V_128 = - V_130 ;
}
return V_128 ;
}
static int F_89 ( void )
{
F_90 ( F_91 ( sizeof( struct V_19 ) ) <
F_92 ( sizeof( struct V_222 ) ) ) ;
return ( int ) F_91 ( sizeof( struct V_19 ) ) -
F_92 ( sizeof( struct V_222 ) ) ;
}
static int F_93 ( const struct V_125 * V_21 ,
unsigned int V_223 )
{
if ( F_94 ( V_21 -> V_224 == - 1 ) )
return F_91 ( V_223 ) - F_92 ( V_223 ) ;
return F_95 ( V_21 ) ;
}
static int F_96 ( struct V_19 * V_20 , void T_1 * * V_225 ,
unsigned int * V_179 )
{
const struct V_125 * V_21 = V_20 -> V_15 . V_21 ;
struct V_222 T_1 * V_226 = * V_225 ;
int V_227 = F_93 ( V_21 , V_20 -> V_129 ) ;
T_4 V_228 = V_20 -> V_129 - V_227 ;
F_97 ( V_227 >= V_20 -> V_129 ) ;
if ( F_4 ( V_226 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_98 ( V_228 , & V_226 -> V_129 ) )
return - V_7 ;
if ( V_21 -> V_229 ) {
if ( V_21 -> V_229 ( V_226 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_226 -> V_18 , V_20 -> V_18 , V_228 ) )
return - V_7 ;
* V_179 -= F_89 () + V_227 ;
* V_225 = V_226 -> V_18 ;
* V_225 += V_228 ;
return 0 ;
}
static int F_99 ( struct V_75 * V_76 ,
void T_1 * * V_225 ,
unsigned int * V_179 )
{
const struct V_134 * V_14 = V_76 -> V_15 . V_14 ;
struct V_222 T_1 * V_226 = * V_225 ;
int V_227 = F_100 ( V_14 ) ;
T_4 V_230 = V_76 -> V_164 - V_227 ;
F_97 ( V_227 >= V_76 -> V_164 ) ;
if ( F_4 ( V_226 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_98 ( V_230 , & V_226 -> V_129 ) )
return - V_7 ;
if ( V_14 -> V_229 ) {
if ( V_14 -> V_229 ( V_226 -> V_18 , V_76 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_226 -> V_18 , V_76 -> V_18 , V_230 ) )
return - V_7 ;
* V_179 -= F_89 () + V_227 ;
* V_225 = V_226 -> V_18 ;
* V_225 += V_230 ;
return 0 ;
}
static int F_101 ( struct V_8 * V_9 ,
void T_1 * * V_225 ,
unsigned int * V_179 )
{
return F_99 ( (struct V_75 * ) V_9 ,
V_225 , V_179 ) ;
}
static int F_102 ( struct V_31 * V_32 , void T_1 * * V_225 ,
unsigned int * V_179 )
{
struct V_75 * V_76 ;
struct V_31 T_1 * V_231 ;
T_5 V_127 , V_102 , V_64 ;
T_4 V_232 ;
int V_128 ;
if ( V_32 -> V_42 == 0 ) {
if ( * V_179 < sizeof( struct V_81 ) )
return - V_130 ;
if ( F_4 ( * V_225 , V_32 , sizeof( struct V_81 ) ) )
return - V_7 ;
* V_225 += sizeof( struct V_81 ) ;
* V_179 -= sizeof( struct V_81 ) ;
return 0 ;
}
if ( * V_179 < sizeof( * V_231 ) )
return - V_130 ;
V_231 = (struct V_31 T_1 * ) * V_225 ;
if ( F_4 ( V_231 , V_32 , sizeof( * V_231 ) ) )
return - V_7 ;
V_232 = * V_179 ;
* V_225 += sizeof( * V_231 ) ;
V_128 = F_21 ( V_32 , F_96 , V_225 , V_179 ) ;
if ( V_128 )
return V_128 ;
V_127 = V_32 -> V_127 - ( V_232 - * V_179 ) ;
V_128 = F_23 ( V_32 , F_101 , V_225 , V_179 ) ;
if ( V_128 )
return V_128 ;
V_102 = V_32 -> V_102 - ( V_232 - * V_179 ) ;
V_76 = (struct V_75 * ) ( ( char * ) V_32 + V_32 -> V_102 ) ;
V_128 = F_99 ( V_76 , V_225 , V_179 ) ;
if ( V_128 )
return V_128 ;
V_64 = V_32 -> V_64 - ( V_232 - * V_179 ) ;
if ( F_98 ( V_127 , & V_231 -> V_127 ) ||
F_98 ( V_102 , & V_231 -> V_102 ) ||
F_98 ( V_64 , & V_231 -> V_64 ) )
return - V_7 ;
* V_179 -= sizeof( * V_231 ) ;
return 0 ;
}
static int F_103 ( struct V_19 * V_20 , int * V_227 )
{
* V_227 += F_93 ( V_20 -> V_15 . V_21 , V_20 -> V_129 ) ;
* V_227 += F_89 () ;
return 0 ;
}
static int F_104 ( struct V_8 * V_9 , int * V_227 )
{
* V_227 += F_100 ( V_9 -> V_15 . V_16 ) ;
* V_227 += F_89 () ;
return 0 ;
}
static int F_105 ( const struct V_31 * V_32 ,
const struct V_84 * V_233 ,
const void * V_83 ,
struct V_234 * V_138 )
{
const struct V_75 * V_76 ;
unsigned int V_235 ;
int V_227 , V_128 , V_28 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
V_227 = 0 ;
V_235 = ( void * ) V_32 - V_83 ;
F_21 ( V_32 , F_103 , & V_227 ) ;
F_23 ( V_32 , F_104 , & V_227 ) ;
V_76 = ( const struct V_75 * ) ( ( char * ) V_32 + V_32 -> V_102 ) ;
V_227 += F_100 ( V_76 -> V_15 . V_14 ) ;
V_227 += F_89 () ;
V_138 -> V_140 -= V_227 ;
V_128 = F_106 ( V_5 , V_235 , V_227 ) ;
if ( V_128 )
return V_128 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
const void * V_236 = V_233 -> V_94 [ V_28 ] ;
if ( V_233 -> V_94 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_83 - V_236 ) ) ) {
V_138 -> V_94 [ V_28 ] -= V_227 ;
F_107 ( L_48 ,
V_138 -> V_94 [ V_28 ] + V_227 ,
V_138 -> V_94 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_108 ( const struct V_84 * V_233 ,
struct V_234 * V_138 )
{
unsigned int V_179 = V_233 -> V_140 ;
const void * V_96 = V_233 -> V_96 ;
V_138 -> V_140 = V_179 ;
F_109 ( V_5 , V_233 -> V_70 ) ;
return F_52 ( V_96 , V_179 , F_105 , V_233 ,
V_96 , V_138 ) ;
}
static int F_110 ( struct V_67 * V_76 ,
void T_1 * V_193 , int * V_101 , int V_210 )
{
struct V_234 V_137 , V_195 ;
struct V_72 * V_175 ;
struct V_84 V_237 ;
int V_128 ;
void T_1 * V_168 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
if ( V_210 == V_211 ) {
V_237 . V_140 = V_76 -> V_85 -> V_140 ;
V_237 . V_70 = V_76 -> V_85 -> V_70 ;
V_237 . V_96 = V_76 -> V_85 -> V_96 ;
V_175 = V_76 -> V_85 -> V_92 ;
} else {
V_237 . V_140 = V_76 -> V_68 -> V_140 ;
V_237 . V_70 = V_76 -> V_68 -> V_70 ;
V_237 . V_96 = V_76 -> V_68 -> V_96 ;
V_175 = V_76 -> V_68 -> V_92 ;
}
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) )
return - V_7 ;
if ( V_195 . V_70 != V_237 . V_70 ||
( V_195 . V_178 && V_195 . V_178 != V_237 . V_70 ) )
return - V_130 ;
memcpy ( & V_137 , & V_195 , sizeof( V_137 ) ) ;
if ( V_210 == V_211 )
V_128 = F_108 ( V_76 -> V_85 , & V_137 ) ;
else
V_128 = F_108 ( & V_237 , & V_137 ) ;
if ( V_128 )
return V_128 ;
if ( * V_101 != sizeof( V_195 ) + V_137 . V_140 +
( V_195 . V_178 ? V_237 . V_70 * sizeof( struct V_72 ) : 0 ) ) {
F_111 ( L_49 ,
* V_101 , V_237 . V_140 , V_137 . V_140 ) ;
return - V_130 ;
}
V_128 = F_83 ( V_76 , V_175 , F_112 ( V_195 . V_92 ) ,
V_195 . V_178 , V_237 . V_70 ) ;
if ( V_128 )
return V_128 ;
V_168 = F_112 ( V_195 . V_96 ) ;
return F_52 ( V_237 . V_96 , V_237 . V_140 ,
F_102 , & V_168 , & V_195 . V_140 ) ;
}
static int F_113 ( struct V_238 * V_66 , unsigned int V_239 )
{
V_66 -> V_240 += V_239 ;
return V_66 -> V_240 >= V_239 ? 0 : - V_130 ;
}
static int F_114 ( struct V_238 * V_66 ,
void * V_18 , unsigned int V_239 )
{
if ( V_66 -> V_241 == NULL )
goto V_242;
F_97 ( V_66 -> V_240 + V_239 > V_66 -> V_243 ) ;
memcpy ( V_66 -> V_241 + V_66 -> V_240 , V_18 , V_239 ) ;
V_242:
V_66 -> V_244 += V_239 ;
return F_113 ( V_66 , V_239 ) ;
}
static int F_115 ( struct V_238 * V_66 , unsigned int V_239 )
{
char * V_245 = V_66 -> V_241 ;
F_97 ( V_245 && V_66 -> V_240 > V_66 -> V_243 ) ;
if ( V_245 != NULL && V_239 > 0 )
memset ( V_245 + V_66 -> V_240 , 0 , V_239 ) ;
return F_113 ( V_66 , V_239 ) ;
}
static int F_116 ( struct V_222 * V_246 ,
enum V_247 V_247 ,
struct V_238 * V_66 ,
const unsigned char * V_83 )
{
char V_30 [ V_117 ] ;
struct V_125 * V_21 ;
struct V_134 * V_248 ;
void * V_1 = NULL ;
int V_227 , V_249 = 0 ;
unsigned int V_250 , V_129 = V_246 -> V_129 ;
F_80 ( V_30 , V_246 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_66 -> V_241 )
V_1 = V_66 -> V_241 + V_66 -> V_240 ;
switch ( V_247 ) {
case V_251 :
V_21 = F_117 ( V_5 , V_30 , 0 ) ;
if ( F_35 ( V_21 ) )
return F_38 ( V_21 ) ;
V_227 = F_93 ( V_21 , V_129 ) ;
if ( V_1 ) {
if ( V_21 -> V_252 )
V_21 -> V_252 ( V_1 , V_246 -> V_18 ) ;
else
memcpy ( V_1 , V_246 -> V_18 , V_129 ) ;
}
V_250 = V_21 -> V_224 ;
if ( F_94 ( V_250 == - 1 ) )
V_250 = V_129 ;
F_36 ( V_21 -> V_131 ) ;
break;
case V_253 :
case V_254 :
V_248 = F_41 ( V_5 , V_30 , 0 ) ;
if ( F_35 ( V_248 ) )
return F_38 ( V_248 ) ;
V_227 = F_100 ( V_248 ) ;
if ( V_1 ) {
if ( V_248 -> V_252 )
V_248 -> V_252 ( V_1 , V_246 -> V_18 ) ;
else
memcpy ( V_1 , V_246 -> V_18 , V_129 ) ;
}
V_250 = V_248 -> V_255 ;
F_36 ( V_248 -> V_131 ) ;
break;
default:
return - V_130 ;
}
V_66 -> V_240 += V_129 + V_227 ;
V_66 -> V_244 += V_129 ;
V_249 = F_91 ( V_250 ) - V_250 ;
if ( V_249 > 0 && V_1 ) {
F_97 ( V_66 -> V_243 <= V_249 ) ;
F_97 ( V_66 -> V_240 - ( V_129 + V_227 ) + V_250 > V_66 -> V_243 - V_249 ) ;
memset ( V_1 + V_250 , 0 , V_249 ) ;
}
return V_227 + V_129 ;
}
static int F_118 ( struct V_222 * V_256 ,
unsigned int V_257 , enum V_247 type ,
struct V_238 * V_66 , const void * V_83 )
{
int V_258 = 0 ;
char * V_259 ;
if ( V_257 == 0 )
return 0 ;
V_259 = ( char * ) V_256 ;
while ( V_257 >= sizeof( * V_256 ) ) {
struct V_19 * V_260 ;
int V_128 ;
V_260 = (struct V_19 * ) V_66 -> V_241 ;
if ( V_260 ) {
char * V_195 ;
V_195 = V_66 -> V_241 + V_66 -> V_240 ;
V_260 = (struct V_19 * ) V_195 ;
}
V_128 = F_114 ( V_66 , V_259 , sizeof( * V_256 ) ) ;
if ( V_128 < 0 )
return V_128 ;
V_257 -= sizeof( * V_256 ) ;
V_128 = F_115 ( V_66 , F_89 () ) ;
if ( V_128 < 0 )
return V_128 ;
if ( V_256 -> V_129 > V_257 )
return - V_130 ;
V_257 -= V_256 -> V_129 ;
V_128 = F_116 ( V_256 , type , V_66 , V_83 ) ;
if ( V_128 < 0 )
return V_128 ;
F_97 ( V_128 < V_256 -> V_129 ) ;
V_258 += V_128 - V_256 -> V_129 ;
V_258 += F_89 () ;
V_259 += sizeof( * V_256 ) ;
V_259 += V_256 -> V_129 ;
if ( V_260 )
V_260 -> V_129 = V_128 ;
F_119 ( type == V_254 && V_257 ) ;
V_256 = (struct V_222 * ) V_259 ;
}
return V_258 ;
}
static int F_120 ( struct V_31 * V_25 , const unsigned char * V_83 ,
unsigned int * V_261 ,
struct V_238 * V_66 )
{
unsigned int V_28 , V_154 , V_262 , V_263 = 0 ;
unsigned int V_264 [ 4 ] ;
unsigned int * V_265 = NULL ;
int V_128 ;
char * V_266 ;
if ( * V_261 < sizeof( struct V_81 ) )
return - V_130 ;
if ( ! V_25 -> V_42 ) {
* V_261 -= sizeof( struct V_81 ) ;
return F_114 ( V_66 , V_25 , sizeof( struct V_81 ) ) ;
}
if ( * V_261 < sizeof( * V_25 ) || V_25 -> V_64 < sizeof( * V_25 ) )
return - V_130 ;
V_262 = V_66 -> V_244 ;
V_128 = F_114 ( V_66 , V_25 ,
F_121 ( struct V_31 , V_127 ) ) ;
if ( V_128 < 0 )
return V_128 ;
V_264 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_264 [ 1 ] , & V_25 -> V_127 ,
sizeof( V_264 ) - sizeof( V_264 [ 0 ] ) ) ;
if ( V_66 -> V_241 ) {
V_266 = V_66 -> V_241 + V_66 -> V_240 ;
V_265 = ( unsigned int * ) V_266 ;
}
V_128 = F_114 ( V_66 , & V_264 [ 1 ] ,
sizeof( V_264 ) - sizeof( V_264 [ 0 ] ) ) ;
if ( V_128 < 0 )
return V_128 ;
V_266 = ( char * ) V_25 ;
for ( V_28 = 0 , V_154 = 1 ; V_154 < 4 ; V_154 ++ , V_28 ++ ) {
struct V_222 * V_256 ;
unsigned int V_179 ;
char * V_259 = V_266 ;
V_259 = V_266 + V_264 [ V_28 ] ;
if ( V_264 [ V_28 ] > V_264 [ V_154 ] )
return - V_130 ;
V_256 = (struct V_222 * ) V_259 ;
V_179 = V_264 [ V_154 ] - V_264 [ V_28 ] ;
V_128 = F_118 ( V_256 , V_179 , V_28 , V_66 , V_83 ) ;
if ( V_128 < 0 )
return V_128 ;
V_263 += V_128 ;
if ( V_265 && V_263 ) {
F_107 ( L_50 ,
V_265 [ V_28 ] , V_264 [ V_154 ] + V_263 ) ;
V_265 [ V_28 ] = V_264 [ V_154 ] + V_263 ;
}
}
if ( V_66 -> V_241 == NULL ) {
unsigned int V_142 = V_266 - ( char * ) V_83 ;
V_128 = F_106 ( V_5 , V_142 , V_263 ) ;
if ( V_128 < 0 )
return V_128 ;
}
V_262 = V_66 -> V_244 - V_262 ;
F_97 ( * V_261 < V_262 ) ;
* V_261 -= V_262 ;
return 0 ;
}
static int F_122 ( unsigned char * V_18 , unsigned int V_267 ,
struct V_238 * V_66 )
{
unsigned int V_268 = V_267 ;
int V_128 ;
V_128 = F_52 ( V_18 , V_267 , F_120 , V_18 ,
& V_268 , V_66 ) ;
if ( V_128 < 0 )
return V_128 ;
F_119 ( V_268 ) ;
return V_66 -> V_240 ;
}
static int F_123 ( struct V_136 * V_137 ,
void T_1 * V_193 , unsigned int V_101 )
{
struct V_234 V_195 ;
int V_28 ;
if ( V_101 < sizeof( V_195 ) )
return - V_130 ;
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) )
return - V_7 ;
if ( V_101 != sizeof( V_195 ) + V_195 . V_140 )
return - V_130 ;
if ( V_195 . V_140 == 0 )
return - V_130 ;
if ( V_195 . V_70 >= ( ( V_196 - sizeof( struct V_84 ) ) /
V_197 - V_198 ) / sizeof( struct V_72 ) )
return - V_174 ;
if ( V_195 . V_178 >= V_196 / sizeof( struct V_72 ) )
return - V_174 ;
memcpy ( V_137 , & V_195 , F_121 ( struct V_136 , V_94 ) ) ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ )
V_137 -> V_94 [ V_28 ] = F_112 ( V_195 . V_94 [ V_28 ] ) ;
V_137 -> V_178 = V_195 . V_178 ;
V_137 -> V_92 = F_112 ( V_195 . V_92 ) ;
V_137 -> V_96 = F_112 ( V_195 . V_96 ) ;
return 0 ;
}
static int F_124 ( struct V_88 * V_88 , void T_1 * V_193 ,
unsigned int V_101 )
{
int V_128 , V_28 , V_194 , V_269 ;
struct V_84 * V_138 ;
struct V_136 V_195 ;
struct V_238 V_66 ;
void * V_270 ;
V_128 = F_123 ( & V_195 , V_193 , V_101 ) ;
if ( V_128 ) {
if ( V_128 == - V_130 && F_66 ( V_88 , V_193 , V_101 ) == 0 )
V_128 = 0 ;
return V_128 ;
}
V_194 = F_68 ( V_195 . V_70 ) * V_173 ;
V_138 = F_53 ( sizeof( * V_138 ) + V_194 ) ;
if ( ! V_138 )
return - V_174 ;
if ( V_194 )
memset ( V_138 -> V_92 , 0 , V_194 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_138 -> V_96 = F_53 ( V_195 . V_140 ) ;
if ( ! V_138 -> V_96 ) {
V_128 = - V_174 ;
goto V_199;
}
if ( F_67 (
V_138 -> V_96 , V_195 . V_96 , V_195 . V_140 ) != 0 ) {
V_128 = - V_7 ;
goto V_200;
}
V_270 = V_138 -> V_96 ;
F_125 ( V_5 ) ;
F_109 ( V_5 , V_195 . V_70 ) ;
V_128 = F_122 ( V_270 , V_195 . V_140 , & V_66 ) ;
if ( V_128 < 0 )
goto V_271;
F_107 ( L_51 ,
V_195 . V_140 , V_66 . V_240 , V_66 . V_244 ,
F_2 ( V_5 , V_195 . V_140 ) ) ;
V_269 = V_128 ;
V_138 -> V_96 = F_53 ( V_269 ) ;
if ( ! V_138 -> V_96 ) {
F_55 ( V_270 ) ;
V_128 = - V_174 ;
goto V_271;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_241 = V_138 -> V_96 ;
V_66 . V_243 = V_269 ;
V_128 = F_122 ( V_270 , V_195 . V_140 , & V_66 ) ;
F_97 ( V_128 < 0 ) ;
F_55 ( V_270 ) ;
V_195 . V_140 = V_269 ;
for ( V_28 = 0 ; V_28 < V_143 ; V_28 ++ ) {
char T_1 * V_272 ;
if ( V_195 . V_94 [ V_28 ] ) {
unsigned int V_273 ;
V_272 = ( char T_1 * ) V_195 . V_94 [ V_28 ] ;
V_273 = V_272 - V_195 . V_96 ;
V_272 += F_2 ( V_5 , V_273 ) ;
V_195 . V_94 [ V_28 ] = (struct V_81 T_1 * ) V_272 ;
}
}
F_126 ( V_5 ) ;
F_127 ( V_5 ) ;
V_128 = F_57 ( V_88 , & V_195 , V_138 ) ;
if ( V_128 == 0 )
return V_128 ;
V_200:
F_55 ( V_138 -> V_96 ) ;
V_199:
F_55 ( V_138 ) ;
return V_128 ;
V_271:
F_126 ( V_5 ) ;
F_127 ( V_5 ) ;
goto V_200;
}
static int F_128 ( struct V_88 * V_88 , void T_1 * V_193 ,
unsigned int V_101 )
{
struct V_234 V_208 ;
if ( F_67 ( & V_208 , V_193 , sizeof( V_208 ) ) )
return - V_7 ;
if ( V_101 != sizeof( V_208 ) + V_208 . V_178 * sizeof( struct V_72 ) )
return F_78 ( V_88 , V_193 , V_101 ) ;
return F_77 ( V_88 , V_208 . V_30 , F_112 ( V_208 . V_92 ) ,
V_208 . V_178 , V_193 , V_101 ) ;
}
static int F_129 ( struct V_212 * V_213 ,
int V_210 , void T_1 * V_193 , unsigned int V_101 )
{
int V_128 ;
struct V_88 * V_88 = F_86 ( V_213 ) ;
if ( ! F_87 ( V_88 -> V_214 , V_215 ) )
return - V_216 ;
switch ( V_210 ) {
case V_217 :
V_128 = F_124 ( V_88 , V_193 , V_101 ) ;
break;
case V_218 :
V_128 = F_128 ( V_88 , V_193 , V_101 ) ;
break;
default:
V_128 = - V_130 ;
}
return V_128 ;
}
static int F_130 ( struct V_212 * V_213 , int V_210 ,
void T_1 * V_193 , int * V_101 )
{
int V_128 ;
struct V_234 V_195 ;
struct V_67 * V_76 ;
struct V_88 * V_88 = F_86 ( V_213 ) ;
if ( ! F_87 ( V_88 -> V_214 , V_215 ) )
return - V_216 ;
if ( ( V_210 == V_219 ||
V_210 == V_220 ) && * V_101 != sizeof( V_195 ) )
return F_88 ( V_213 , V_210 , V_193 , V_101 ) ;
if ( F_67 ( & V_195 , V_193 , sizeof( V_195 ) ) )
return - V_7 ;
V_195 . V_30 [ sizeof( V_195 . V_30 ) - 1 ] = '\0' ;
V_76 = F_32 ( V_88 , V_195 . V_30 , & V_128 , & V_181 ) ;
if ( ! V_76 )
return V_128 ;
F_125 ( V_5 ) ;
switch ( V_210 ) {
case V_219 :
V_195 . V_70 = V_76 -> V_85 -> V_70 ;
V_128 = F_108 ( V_76 -> V_85 , & V_195 ) ;
if ( V_128 )
goto V_34;
V_195 . V_141 = V_76 -> V_141 ;
if ( F_4 ( V_193 , & V_195 , * V_101 ) != 0 ) {
V_128 = - V_7 ;
break;
}
V_128 = 0 ;
break;
case V_220 :
V_195 . V_70 = V_76 -> V_68 -> V_70 ;
V_195 . V_140 = V_76 -> V_68 -> V_140 ;
V_195 . V_141 = V_76 -> V_68 -> V_141 ;
if ( F_4 ( V_193 , & V_195 , * V_101 ) != 0 ) {
V_128 = - V_7 ;
break;
}
V_128 = 0 ;
break;
case V_211 :
case V_221 :
if ( F_84 ( V_76 , V_193 , V_101 , V_210 ) == 0 )
V_128 = 0 ;
else
V_128 = F_110 ( V_76 , V_193 , V_101 , V_210 ) ;
break;
default:
V_128 = - V_130 ;
}
V_34:
F_126 ( V_5 ) ;
F_127 ( V_5 ) ;
F_29 ( & V_181 ) ;
return V_128 ;
}
static int T_6 F_131 ( void )
{
int V_128 ;
V_128 = F_132 ( & V_103 ) ;
if ( V_128 < 0 )
return V_128 ;
V_128 = F_133 ( & V_274 ) ;
if ( V_128 < 0 ) {
F_134 ( & V_103 ) ;
return V_128 ;
}
F_135 ( V_275 L_52 ) ;
return 0 ;
}
static void T_7 F_136 ( void )
{
F_137 ( & V_274 ) ;
F_134 ( & V_103 ) ;
F_135 ( V_275 L_53 ) ;
}
