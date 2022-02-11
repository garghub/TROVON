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
V_86 . V_66 = V_66 ;
V_86 . V_87 = false ;
F_18 ( & V_68 -> V_88 ) ;
V_85 = V_68 -> V_85 ;
V_74 = F_19 ( V_85 -> V_89 , V_85 -> V_70 ,
F_20 () ) ;
if ( V_85 -> V_90 )
V_80 = V_85 -> V_90 [ F_20 () ] ;
else
V_80 = NULL ;
V_82 = V_85 -> V_91 [ V_69 ] ;
V_70 = V_85 -> V_91 [ V_69 ] -> V_70 ;
V_71 = (struct V_31 * ) ( V_85 -> V_91 [ V_69 ] -> V_18 ) ;
V_73 = V_74 + V_85 -> V_91 [ V_69 ] -> V_92 ;
V_83 = V_85 -> V_93 ;
V_28 = 0 ;
while ( V_28 < V_70 ) {
if ( F_8 ( V_71 , V_11 , V_66 -> V_33 , V_66 -> V_34 ) )
goto V_94;
if ( F_21 ( V_71 , F_6 , V_11 , & V_86 ) != 0 )
goto V_94;
if ( V_86 . V_87 ) {
F_22 ( & V_68 -> V_88 ) ;
return V_95 ;
}
( * ( V_73 + V_28 ) ) . V_96 ++ ;
( * ( V_73 + V_28 ) ) . V_97 += V_11 -> V_98 ;
F_23 ( V_71 , F_5 , V_11 , & V_86 ) ;
V_76 = (struct V_75 * )
( ( ( char * ) V_71 ) + V_71 -> V_99 ) ;
if ( ! V_76 -> V_15 . V_14 -> V_14 )
V_77 = ( (struct V_100 * ) V_76 ) -> V_77 ;
else {
V_86 . V_14 = V_76 -> V_15 . V_14 ;
V_86 . V_17 = V_76 -> V_18 ;
V_77 = V_76 -> V_15 . V_14 -> V_14 ( V_11 , & V_86 ) ;
}
if ( V_77 == V_101 ) {
F_22 ( & V_68 -> V_88 ) ;
return V_102 ;
}
if ( V_77 == V_103 ) {
F_22 ( & V_68 -> V_88 ) ;
return V_95 ;
}
if ( V_77 == V_104 ) {
V_105:
#ifdef F_24
if ( V_78 == 0 ) {
F_25 ( L_1 ) ;
goto V_94;
}
#endif
V_78 -- ;
V_28 = V_80 [ V_78 ] . V_106 ;
V_82 = V_80 [ V_78 ] . V_82 ;
V_70 = V_82 -> V_70 ;
V_71 = V_80 [ V_78 ] . V_32 ;
V_73 = V_74 +
V_82 -> V_92 ;
continue;
}
if ( V_77 == V_107 )
goto V_94;
#ifdef F_24
if ( V_77 < 0 ) {
F_25 ( L_2 ) ;
F_22 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_80 [ V_78 ] . V_106 = V_28 + 1 ;
V_80 [ V_78 ] . V_82 = V_82 ;
V_80 [ V_78 ] . V_32 = F_16 ( V_71 ) ;
V_28 = 0 ;
V_82 = (struct V_81 * ) ( V_83 + V_77 ) ;
#ifdef F_24
if ( V_82 -> V_108 ) {
F_25 ( L_3 ) ;
F_22 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_70 = V_82 -> V_70 ;
V_71 = (struct V_31 * ) V_82 -> V_18 ;
V_73 = V_74 + V_82 -> V_92 ;
V_78 ++ ;
continue;
V_94:
V_71 = F_16 ( V_71 ) ;
V_28 ++ ;
}
if ( V_82 -> V_109 == V_104 )
goto V_105;
if ( V_82 -> V_109 == V_101 ) {
F_22 ( & V_68 -> V_88 ) ;
return V_102 ;
}
F_22 ( & V_68 -> V_88 ) ;
return V_95 ;
}
static inline void *
F_26 ( struct V_110 * V_111 , const char * V_30 , int * error ,
struct V_112 * V_112 )
{
struct {
struct V_110 V_113 ;
char V_30 [ V_114 ] ;
} * V_32 ;
F_27 ( V_112 ) ;
F_28 (e, head, list) {
if ( strcmp ( V_32 -> V_30 , V_30 ) == 0 )
return V_32 ;
}
* error = - V_115 ;
F_29 ( V_112 ) ;
return NULL ;
}
static void *
F_30 ( struct V_110 * V_111 , const char * V_30 , const char * V_116 ,
int * error , struct V_112 * V_112 )
{
return F_31 (
F_26 ( V_111 , V_30 , error , V_112 ) ,
L_4 , V_116 , V_30 ) ;
}
static inline struct V_67 *
F_32 ( struct V_117 * V_117 , const char * V_30 , int * error ,
struct V_112 * V_112 )
{
return F_30 ( & V_117 -> V_118 . V_119 [ V_5 ] , V_30 ,
L_5 , error , V_112 ) ;
}
static inline int
F_33 ( struct V_19 * V_20 , struct V_120 * V_13 ,
unsigned int * V_121 )
{
const struct V_31 * V_32 = V_13 -> V_122 ;
struct V_123 * V_21 ;
T_3 V_124 = ( ( char * ) V_32 + V_32 -> V_125 ) - ( char * ) V_20 ;
int V_126 ;
if ( V_124 < sizeof( struct V_19 ) ||
V_124 - sizeof( struct V_19 ) < V_20 -> V_127 )
return - V_128 ;
V_21 = F_34 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_21 ) || V_21 -> V_129 != V_5 ) {
if ( ! F_35 ( V_21 ) )
F_36 ( V_21 -> V_130 ) ;
F_37 ( L_6 , V_20 -> V_15 . V_30 ) ;
V_21 = F_34 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
}
if ( F_35 ( V_21 ) )
return F_38 ( V_21 ) ;
V_20 -> V_15 . V_21 = V_21 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_20 -> V_18 ;
V_126 = F_39 ( V_13 , V_20 -> V_127 ,
V_32 -> V_39 , V_32 -> V_131 & V_44 ) ;
if ( V_126 < 0 ) {
F_36 ( V_21 -> V_130 ) ;
return V_126 ;
}
( * V_121 ) ++ ;
return 0 ;
}
static inline int
F_40 ( struct V_8 * V_9 , struct V_132 * V_13 ,
unsigned int * V_121 )
{
const struct V_31 * V_32 = V_13 -> V_122 ;
struct V_133 * V_16 ;
T_3 V_124 = ( ( char * ) V_32 + V_32 -> V_99 ) - ( char * ) V_9 ;
int V_126 ;
if ( V_124 < sizeof( struct V_8 ) ||
V_124 - sizeof( struct V_8 ) < V_9 -> V_134 )
return - V_128 ;
V_16 = F_41 ( V_5 , V_9 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_16 ) )
return F_38 ( V_16 ) ;
V_9 -> V_15 . V_16 = V_16 ;
V_13 -> V_14 = V_16 ;
V_13 -> V_17 = V_9 -> V_18 ;
V_126 = F_42 ( V_13 , V_9 -> V_134 ,
V_32 -> V_39 , V_32 -> V_131 & V_44 ) ;
if ( V_126 < 0 ) {
F_36 ( V_16 -> V_130 ) ;
return V_126 ;
}
( * V_121 ) ++ ;
return 0 ;
}
static int F_43 ( const struct V_135 * V_136 ,
struct V_84 * V_137 )
{
unsigned int V_138 = V_136 -> V_139 ;
unsigned int V_140 = V_136 -> V_140 ;
unsigned int V_141 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ )
V_137 -> V_91 [ V_28 ] = NULL ;
V_137 -> V_139 = V_136 -> V_139 ;
V_137 -> V_70 = V_136 -> V_70 ;
while ( V_141 < V_138 ) {
T_3 V_124 = V_138 - V_141 ;
struct V_31 * V_32 = ( void * ) V_137 -> V_93 + V_141 ;
if ( V_124 < sizeof( unsigned int ) )
break;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( ( V_140 & ( 1 << V_28 ) ) == 0 )
continue;
if ( ( char T_1 * ) V_136 -> V_91 [ V_28 ] ==
V_136 -> V_93 + V_141 )
break;
}
if ( V_28 != V_142 || ! ( V_32 -> V_42 & V_143 ) ) {
if ( V_32 -> V_42 != 0 ) {
F_25 ( L_7
L_8 ) ;
return - V_128 ;
}
if ( V_28 != V_142 )
V_137 -> V_91 [ V_28 ] = (struct V_81 * ) V_32 ;
if ( V_124 < sizeof( struct V_81 ) )
break;
V_141 += sizeof( struct V_81 ) ;
} else {
if ( V_124 < sizeof( struct V_31 ) )
break;
if ( V_124 < V_32 -> V_64 )
break;
if ( V_32 -> V_64 < sizeof( struct V_31 ) )
return - V_128 ;
V_141 += V_32 -> V_64 ;
}
}
if ( V_141 != V_138 ) {
F_25 ( L_9 ) ;
return - V_128 ;
}
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( ! V_137 -> V_91 [ V_28 ] &&
( V_140 & ( 1 << V_28 ) ) ) {
F_25 ( L_10 ) ;
return - V_128 ;
}
}
return 0 ;
}
static inline int
F_44 ( const struct V_31 * V_32 ,
const struct V_84 * V_137 ,
unsigned int * V_106 , unsigned int * V_121 ,
unsigned int * V_144 , unsigned int * V_145 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( ( void * ) V_32 == ( void * ) V_137 -> V_91 [ V_28 ] )
break;
}
if ( V_28 != V_142 || ! V_32 -> V_42 ) {
if ( * V_106 != * V_121 ) {
F_25 ( L_11
L_12 ) ;
return - V_128 ;
}
if ( ( (struct V_81 * ) V_32 ) -> V_109 != V_103 &&
( (struct V_81 * ) V_32 ) -> V_109 != V_101 ) {
if ( V_28 != V_142 ||
( (struct V_81 * ) V_32 ) -> V_109 != V_104 ) {
F_25 ( L_13 ) ;
return - V_128 ;
}
}
if ( V_28 == V_142 )
( * V_145 ) ++ ;
if ( ( (struct V_81 * ) V_32 ) -> V_92 != * V_144 ) {
F_25 ( L_14 ) ;
return - V_128 ;
}
* V_106 = ( (struct V_81 * ) V_32 ) -> V_70 ;
* V_121 = 0 ;
return 0 ;
}
if ( sizeof( struct V_31 ) > V_32 -> V_125 ||
V_32 -> V_125 > V_32 -> V_99 ||
V_32 -> V_99 >= V_32 -> V_64 ) {
F_25 ( L_15 ) ;
return - V_128 ;
}
if ( V_32 -> V_64 - V_32 -> V_99 < sizeof( struct V_75 ) ) {
F_25 ( L_16 ) ;
return - V_128 ;
}
( * V_121 ) ++ ;
( * V_144 ) ++ ;
return 0 ;
}
static inline int
F_45 ( struct V_31 * V_32 , struct V_84 * V_137 ,
unsigned int * V_106 , struct V_146 * V_147 )
{
int V_28 ;
if ( V_32 -> V_42 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( V_137 -> V_91 [ V_28 ] == (struct V_81 * ) V_32 )
break;
}
if ( V_28 != V_142 )
return 0 ;
V_147 [ * V_106 ] . V_80 . V_82 = (struct V_81 * ) V_32 ;
V_147 [ * V_106 ] . V_80 . V_106 = 0 ;
V_147 [ * V_106 ] . V_148 = 0 ;
( * V_106 ) ++ ;
return 0 ;
}
static inline int
F_46 ( struct V_19 * V_20 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_149 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_21 = V_20 -> V_15 . V_21 ;
V_13 . V_22 = V_20 -> V_18 ;
V_13 . V_129 = V_5 ;
if ( V_13 . V_21 -> V_150 != NULL )
V_13 . V_21 -> V_150 ( & V_13 ) ;
F_36 ( V_13 . V_21 -> V_130 ) ;
return 0 ;
}
static inline int
F_47 ( struct V_8 * V_9 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_151 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_9 -> V_15 . V_16 ;
V_13 . V_17 = V_9 -> V_18 ;
V_13 . V_129 = V_5 ;
if ( V_13 . V_14 -> V_150 != NULL )
V_13 . V_14 -> V_150 ( & V_13 ) ;
F_36 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_48 ( struct V_31 * V_32 , struct V_117 * V_117 , unsigned int * V_121 )
{
struct V_151 V_13 ;
struct V_75 * V_76 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
if ( V_121 && ( * V_121 ) -- == 0 )
return 1 ;
F_23 ( V_32 , F_47 , V_117 , NULL ) ;
F_21 ( V_32 , F_46 , V_117 , NULL ) ;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_76 -> V_15 . V_14 ;
V_13 . V_17 = V_76 -> V_18 ;
V_13 . V_129 = V_5 ;
if ( V_13 . V_14 -> V_150 != NULL )
V_13 . V_14 -> V_150 ( & V_13 ) ;
F_36 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_49 ( struct V_31 * V_32 , struct V_117 * V_117 ,
const struct V_84 * V_137 ,
const char * V_30 , unsigned int * V_121 ,
struct V_146 * V_152 , unsigned int V_145 )
{
struct V_75 * V_76 ;
struct V_133 * V_14 ;
unsigned int V_28 , V_153 , V_69 = 0 , V_148 = 0 ;
T_3 V_154 ;
int V_126 ;
struct V_120 V_155 ;
struct V_132 V_156 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
if ( V_32 -> V_42 & ~ V_157 ) {
F_25 ( L_17 ) ;
return - V_128 ;
}
if ( V_32 -> V_131 & ~ V_158 ) {
F_25 ( L_18 ) ;
return - V_128 ;
}
if ( ( V_32 -> V_42 & V_45 ) && ( V_32 -> V_42 & V_43 ) ) {
F_25 ( L_19 ) ;
return - V_128 ;
}
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( ! V_137 -> V_91 [ V_28 ] )
continue;
if ( ( char * ) V_137 -> V_91 [ V_28 ] < ( char * ) V_32 )
V_69 = V_28 ;
else
break;
}
if ( V_28 < V_142 )
V_148 = ( 1 << V_69 ) | ( 1 << V_142 ) ;
else {
for ( V_28 = 0 ; V_28 < V_145 ; V_28 ++ )
if ( ( char * ) ( V_152 [ V_28 ] . V_80 . V_82 ) > ( char * ) V_32 )
break;
if ( V_28 == 0 )
V_148 = ( 1 << V_69 ) | ( 1 << V_142 ) ;
else
V_148 = V_152 [ V_28 - 1 ] . V_148 ;
}
V_28 = 0 ;
V_155 . V_117 = V_156 . V_117 = V_117 ;
V_155 . V_68 = V_156 . V_68 = V_30 ;
V_155 . V_122 = V_156 . V_122 = V_32 ;
V_155 . V_159 = V_156 . V_159 = V_148 ;
V_155 . V_129 = V_156 . V_129 = V_5 ;
V_126 = F_21 ( V_32 , F_33 , & V_155 , & V_28 ) ;
if ( V_126 != 0 )
goto V_160;
V_153 = 0 ;
V_126 = F_23 ( V_32 , F_40 , & V_156 , & V_153 ) ;
if ( V_126 != 0 )
goto V_161;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_154 = V_32 -> V_64 - V_32 -> V_99 ;
V_14 = F_41 ( V_5 , V_76 -> V_15 . V_30 , 0 ) ;
if ( F_35 ( V_14 ) ) {
V_126 = F_38 ( V_14 ) ;
goto V_161;
}
V_76 -> V_15 . V_14 = V_14 ;
if ( V_76 -> V_15 . V_14 == & V_100 ) {
if ( V_154 < sizeof( struct V_100 ) ) {
F_25 ( L_20 ) ;
V_126 = - V_7 ;
goto V_161;
}
if ( ( (struct V_100 * ) V_76 ) -> V_77 <
- V_162 ) {
F_25 ( L_21 ) ;
V_126 = - V_7 ;
goto V_161;
}
} else if ( V_76 -> V_163 > V_154 - sizeof( struct V_75 ) ) {
F_36 ( V_76 -> V_15 . V_14 -> V_130 ) ;
V_126 = - V_7 ;
goto V_161;
}
V_156 . V_14 = V_14 ;
V_156 . V_17 = V_76 -> V_18 ;
V_126 = F_42 ( & V_156 , V_76 -> V_163 ,
V_32 -> V_39 , V_32 -> V_131 & V_44 ) ;
if ( V_126 < 0 ) {
F_36 ( V_14 -> V_130 ) ;
goto V_161;
}
( * V_121 ) ++ ;
return 0 ;
V_161:
F_23 ( V_32 , F_47 , V_117 , & V_153 ) ;
V_160:
F_21 ( V_32 , F_46 , V_117 , & V_28 ) ;
return V_126 ;
}
static int F_50 ( const struct V_81 * V_164 , struct V_146 * V_152 ,
unsigned int V_145 , unsigned int V_165 , char * V_83 )
{
int V_28 , V_166 = - 1 , V_167 = 0 , V_70 = V_164 -> V_70 , V_77 ;
const struct V_31 * V_32 = (struct V_31 * ) V_164 -> V_18 ;
const struct V_75 * V_76 ;
while ( V_167 < V_70 || V_166 != - 1 ) {
if ( V_167 == V_70 ) {
V_32 = V_152 [ V_166 ] . V_80 . V_32 ;
if ( V_152 [ V_166 ] . V_168 != - 1 )
V_70 =
V_152 [ V_152 [ V_166 ] . V_168 ] . V_80 . V_82 -> V_70 ;
else
V_70 = V_164 -> V_70 ;
V_167 = V_152 [ V_166 ] . V_80 . V_106 ;
V_152 [ V_166 ] . V_80 . V_106 = 0 ;
V_166 = V_152 [ V_166 ] . V_168 ;
if ( V_167 == V_70 )
continue;
}
V_76 = (struct V_75 * )
( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
if ( strcmp ( V_76 -> V_15 . V_30 , V_169 ) )
goto V_94;
if ( V_32 -> V_99 + sizeof( struct V_100 ) >
V_32 -> V_64 ) {
F_25 ( L_20 ) ;
return - 1 ;
}
V_77 = ( (struct V_100 * ) V_76 ) -> V_77 ;
if ( V_77 >= 0 ) {
struct V_81 * V_170 =
(struct V_81 * ) ( V_83 + V_77 ) ;
for ( V_28 = 0 ; V_28 < V_145 ; V_28 ++ )
if ( V_170 == V_152 [ V_28 ] . V_80 . V_82 )
break;
if ( V_28 == V_145 ) {
F_25 ( L_22 ) ;
return - 1 ;
}
if ( V_152 [ V_28 ] . V_80 . V_106 ) {
F_25 ( L_23 ) ;
return - 1 ;
}
if ( V_152 [ V_28 ] . V_148 & ( 1 << V_165 ) )
goto V_94;
V_152 [ V_28 ] . V_80 . V_106 = V_167 + 1 ;
V_167 = 0 ;
V_152 [ V_28 ] . V_80 . V_32 = F_16 ( V_32 ) ;
V_32 = (struct V_31 * ) ( V_170 -> V_18 ) ;
V_70 = V_170 -> V_70 ;
V_152 [ V_28 ] . V_168 = V_166 ;
V_166 = V_28 ;
V_152 [ V_28 ] . V_148 |= ( 1 << V_165 ) ;
continue;
}
V_94:
V_32 = F_16 ( V_32 ) ;
V_167 ++ ;
}
return 0 ;
}
static int F_51 ( struct V_117 * V_117 , const char * V_30 ,
struct V_84 * V_137 )
{
unsigned int V_28 , V_153 , V_171 , V_145 ;
int V_126 ;
struct V_146 * V_152 = NULL ;
V_28 = 0 ;
while ( V_28 < V_142 && ! V_137 -> V_91 [ V_28 ] )
V_28 ++ ;
if ( V_28 == V_142 ) {
F_25 ( L_24 ) ;
return - V_128 ;
}
if ( V_137 -> V_91 [ V_28 ] != (struct V_81 * ) V_137 -> V_93 ) {
F_25 ( L_25 ) ;
return - V_128 ;
}
for ( V_153 = V_28 + 1 ; V_153 < V_142 ; V_153 ++ ) {
if ( ! V_137 -> V_91 [ V_153 ] )
continue;
if ( V_137 -> V_91 [ V_153 ] <= V_137 -> V_91 [ V_28 ] ) {
F_25 ( L_26 ) ;
return - V_128 ;
}
V_28 = V_153 ;
}
V_28 = 0 ;
V_153 = 0 ;
V_171 = 0 ;
V_145 = 0 ;
V_126 = F_52 ( V_137 -> V_93 , V_137 -> V_139 ,
F_44 , V_137 ,
& V_28 , & V_153 , & V_171 , & V_145 ) ;
if ( V_126 != 0 )
return V_126 ;
if ( V_28 != V_153 ) {
F_25 ( L_27
L_28 ) ;
return - V_128 ;
}
if ( V_171 != V_137 -> V_70 ) {
F_25 ( L_29 ) ;
return - V_128 ;
}
if ( V_145 ) {
V_137 -> V_90 =
F_53 ( V_172 * sizeof( * ( V_137 -> V_90 ) ) ) ;
if ( ! V_137 -> V_90 )
return - V_173 ;
F_54 (i) {
V_137 -> V_90 [ V_28 ] =
F_53 ( V_145 * sizeof( * ( V_137 -> V_90 [ 0 ] ) ) ) ;
if ( ! V_137 -> V_90 [ V_28 ] ) {
while ( V_28 )
F_55 ( V_137 -> V_90 [ -- V_28 ] ) ;
F_55 ( V_137 -> V_90 ) ;
V_137 -> V_90 = NULL ;
return - V_173 ;
}
}
V_152 = F_53 ( V_145 * sizeof( * V_152 ) ) ;
if ( ! V_152 )
return - V_173 ;
V_28 = 0 ;
F_52 ( V_137 -> V_93 , V_137 -> V_139 ,
F_45 , V_137 , & V_28 , V_152 ) ;
if ( V_28 != V_145 ) {
F_25 ( L_30 ) ;
F_55 ( V_152 ) ;
return - V_7 ;
}
}
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ )
if ( V_137 -> V_91 [ V_28 ] )
if ( F_50 ( V_137 -> V_91 [ V_28 ] ,
V_152 , V_145 , V_28 , V_137 -> V_93 ) ) {
F_55 ( V_152 ) ;
return - V_128 ;
}
V_28 = 0 ;
V_126 = F_52 ( V_137 -> V_93 , V_137 -> V_139 ,
F_49 , V_117 , V_137 , V_30 , & V_28 , V_152 , V_145 ) ;
if ( V_126 != 0 ) {
F_52 ( V_137 -> V_93 , V_137 -> V_139 ,
F_48 , V_117 , & V_28 ) ;
}
F_55 ( V_152 ) ;
return V_126 ;
}
static void F_56 ( const struct V_72 * V_174 ,
struct V_72 * V_89 , unsigned int V_70 )
{
int V_28 , V_175 ;
struct V_72 * V_73 ;
memcpy ( V_89 , V_174 ,
sizeof( struct V_72 ) * V_70 ) ;
F_54 (cpu) {
if ( V_175 == 0 )
continue;
V_73 = F_19 ( V_174 , V_70 , V_175 ) ;
for ( V_28 = 0 ; V_28 < V_70 ; V_28 ++ ) {
V_89 [ V_28 ] . V_96 += V_73 [ V_28 ] . V_96 ;
V_89 [ V_28 ] . V_97 += V_73 [ V_28 ] . V_97 ;
}
}
}
static int F_57 ( struct V_117 * V_117 , struct V_135 * V_136 ,
struct V_84 * V_137 )
{
int V_126 , V_28 ;
struct V_72 * V_176 = NULL ;
struct V_84 * V_68 ;
struct V_67 * V_76 ;
if ( V_136 -> V_177 ) {
unsigned long V_178 = V_136 -> V_177 * sizeof( * V_176 ) ;
V_176 = F_53 ( V_178 ) ;
if ( ! V_176 )
return - V_173 ;
}
V_137 -> V_90 = NULL ;
V_126 = F_43 ( V_136 , V_137 ) ;
if ( V_126 != 0 )
goto V_179;
V_126 = F_51 ( V_117 , V_136 -> V_30 , V_137 ) ;
if ( V_126 != 0 )
goto V_179;
V_76 = F_32 ( V_117 , V_136 -> V_30 , & V_126 , & V_180 ) ;
if ( ! V_76 ) {
V_126 = - V_115 ;
goto V_181;
}
if ( V_76 -> V_182 && ( V_126 = V_76 -> V_182 ( V_137 , V_136 -> V_140 ) ) )
goto V_183;
if ( V_136 -> V_177 && V_136 -> V_177 != V_76 -> V_85 -> V_70 ) {
F_25 ( L_31 ) ;
V_126 = - V_128 ;
goto V_183;
}
V_68 = V_76 -> V_85 ;
if ( ! V_68 -> V_70 && V_137 -> V_70 && ! F_58 ( V_76 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_183;
} else if ( V_68 -> V_70 && ! V_137 -> V_70 )
F_36 ( V_76 -> V_130 ) ;
F_59 ( & V_76 -> V_88 ) ;
if ( V_136 -> V_177 )
F_56 ( V_76 -> V_85 -> V_89 , V_176 ,
V_76 -> V_85 -> V_70 ) ;
V_76 -> V_85 = V_137 ;
F_60 ( & V_76 -> V_88 ) ;
F_29 ( & V_180 ) ;
if ( V_136 -> V_177 &&
F_4 ( V_136 -> V_89 , V_176 ,
V_136 -> V_177 * sizeof( struct V_72 ) ) ) {
F_61 ( L_32 ) ;
}
F_52 ( V_68 -> V_93 , V_68 -> V_139 ,
F_48 , V_117 , NULL ) ;
F_55 ( V_68 -> V_93 ) ;
if ( V_68 -> V_90 ) {
F_54 (i)
F_55 ( V_68 -> V_90 [ V_28 ] ) ;
F_55 ( V_68 -> V_90 ) ;
}
F_55 ( V_68 ) ;
F_55 ( V_176 ) ;
#ifdef F_62
if ( V_184 ) {
struct V_185 * V_186 ;
V_186 = F_63 ( V_187 -> V_188 , V_189 ,
V_190 ) ;
if ( V_186 ) {
F_64 ( V_186 , L_33 ,
V_136 -> V_30 , V_191 , V_136 -> V_70 ) ;
F_65 ( V_186 ) ;
}
}
#endif
return V_126 ;
V_183:
F_29 ( & V_180 ) ;
V_181:
F_52 ( V_137 -> V_93 , V_137 -> V_139 ,
F_48 , V_117 , NULL ) ;
V_179:
F_55 ( V_176 ) ;
if ( V_137 -> V_90 ) {
F_54 (i)
F_55 ( V_137 -> V_90 [ V_28 ] ) ;
F_55 ( V_137 -> V_90 ) ;
}
return V_126 ;
}
static int F_66 ( struct V_117 * V_117 , const void T_1 * V_192 ,
unsigned int V_98 )
{
int V_126 , V_193 ;
struct V_84 * V_137 ;
struct V_135 V_194 ;
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) != 0 )
return - V_7 ;
if ( V_98 != sizeof( V_194 ) + V_194 . V_139 ) {
F_25 ( L_34 ) ;
return - V_128 ;
}
if ( V_194 . V_139 == 0 ) {
F_25 ( L_35 ) ;
return - V_128 ;
}
if ( V_194 . V_70 >= ( ( V_195 - sizeof( struct V_84 ) ) /
V_196 - V_197 ) / sizeof( struct V_72 ) )
return - V_173 ;
if ( V_194 . V_177 >= V_195 / sizeof( struct V_72 ) )
return - V_173 ;
V_194 . V_30 [ sizeof( V_194 . V_30 ) - 1 ] = 0 ;
V_193 = F_68 ( V_194 . V_70 ) * V_172 ;
V_137 = F_53 ( sizeof( * V_137 ) + V_193 ) ;
if ( ! V_137 )
return - V_173 ;
if ( V_193 )
memset ( V_137 -> V_89 , 0 , V_193 ) ;
V_137 -> V_93 = F_53 ( V_194 . V_139 ) ;
if ( ! V_137 -> V_93 ) {
V_126 = - V_173 ;
goto V_198;
}
if ( F_67 (
V_137 -> V_93 , V_194 . V_93 , V_194 . V_139 ) != 0 ) {
F_25 ( L_36 ) ;
V_126 = - V_7 ;
goto V_199;
}
V_126 = F_57 ( V_117 , & V_194 , V_137 ) ;
if ( V_126 == 0 )
return V_126 ;
V_199:
F_55 ( V_137 -> V_93 ) ;
V_198:
F_55 ( V_137 ) ;
return V_126 ;
}
static void F_69 ( struct V_117 * V_117 , struct V_67 * V_68 )
{
int V_28 ;
F_27 ( & V_180 ) ;
F_70 ( & V_68 -> V_113 ) ;
F_29 ( & V_180 ) ;
F_52 ( V_68 -> V_85 -> V_93 , V_68 -> V_85 -> V_139 ,
F_48 , V_117 , NULL ) ;
if ( V_68 -> V_85 -> V_70 )
F_36 ( V_68 -> V_130 ) ;
F_55 ( V_68 -> V_85 -> V_93 ) ;
if ( V_68 -> V_85 -> V_90 ) {
F_54 (i)
F_55 ( V_68 -> V_85 -> V_90 [ V_28 ] ) ;
F_55 ( V_68 -> V_85 -> V_90 ) ;
}
F_55 ( V_68 -> V_85 ) ;
F_71 ( V_68 ) ;
}
struct V_67 *
F_72 ( struct V_117 * V_117 , const struct V_67 * V_200 ,
const struct V_201 * V_202 )
{
struct V_84 * V_137 ;
struct V_67 * V_76 , * V_68 ;
struct V_203 * V_136 ;
int V_126 , V_28 , V_193 ;
void * V_38 ;
if ( V_200 == NULL || ( V_136 = V_200 -> V_68 ) == NULL ||
V_136 -> V_93 == NULL || V_136 -> V_139 == 0 ||
V_136 -> V_89 != NULL || V_200 -> V_85 != NULL ) {
F_25 ( L_37 ) ;
return F_73 ( - V_128 ) ;
}
V_68 = F_74 ( V_200 , sizeof( struct V_67 ) , V_189 ) ;
if ( ! V_68 ) {
V_126 = - V_173 ;
goto V_34;
}
V_193 = F_68 ( V_136 -> V_70 ) * V_172 ;
V_137 = F_53 ( sizeof( * V_137 ) + V_193 ) ;
V_126 = - V_173 ;
if ( ! V_137 )
goto V_204;
V_38 = F_53 ( V_136 -> V_139 ) ;
if ( ! V_38 )
goto V_198;
memcpy ( V_38 , V_136 -> V_93 , V_136 -> V_139 ) ;
V_137 -> V_93 = V_38 ;
V_137 -> V_139 = V_136 -> V_139 ;
V_137 -> V_70 = V_136 -> V_70 ;
if ( V_193 )
memset ( V_137 -> V_89 , 0 , V_193 ) ;
V_137 -> V_90 = NULL ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
if ( ( V_136 -> V_140 & ( 1 << V_28 ) ) == 0 )
V_137 -> V_91 [ V_28 ] = NULL ;
else
V_137 -> V_91 [ V_28 ] = V_38 +
( ( char * ) V_136 -> V_91 [ V_28 ] - V_136 -> V_93 ) ;
}
V_126 = F_51 ( V_117 , V_136 -> V_30 , V_137 ) ;
if ( V_126 != 0 ) {
F_25 ( L_38 ) ;
goto V_205;
}
if ( V_68 -> V_182 && V_68 -> V_182 ( V_137 , V_68 -> V_140 ) ) {
F_25 ( L_39 ) ;
V_126 = - V_128 ;
goto V_205;
}
V_68 -> V_85 = V_137 ;
F_75 ( & V_68 -> V_88 ) ;
F_27 ( & V_180 ) ;
F_28 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_76 -> V_30 , V_68 -> V_30 ) == 0 ) {
V_126 = - V_206 ;
F_25 ( L_40 ) ;
goto V_183;
}
}
if ( V_137 -> V_70 && ! F_58 ( V_68 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_183;
}
F_76 ( & V_68 -> V_113 , & V_117 -> V_118 . V_119 [ V_5 ] ) ;
F_29 ( & V_180 ) ;
if ( ! V_202 )
return V_68 ;
V_126 = F_77 ( V_117 , V_202 , F_78 ( V_68 -> V_140 ) ) ;
if ( V_126 ) {
F_69 ( V_117 , V_68 ) ;
return F_73 ( V_126 ) ;
}
return V_68 ;
V_183:
F_29 ( & V_180 ) ;
V_205:
if ( V_137 -> V_90 ) {
F_54 (i)
F_55 ( V_137 -> V_90 [ V_28 ] ) ;
F_55 ( V_137 -> V_90 ) ;
}
F_55 ( V_137 -> V_93 ) ;
V_198:
F_55 ( V_137 ) ;
V_204:
F_71 ( V_68 ) ;
V_34:
return F_73 ( V_126 ) ;
}
void F_79 ( struct V_117 * V_117 , struct V_67 * V_68 ,
const struct V_201 * V_202 )
{
if ( V_202 )
F_80 ( V_117 , V_202 , F_78 ( V_68 -> V_140 ) ) ;
F_69 ( V_117 , V_68 ) ;
}
static int F_81 ( struct V_117 * V_117 , const char * V_30 ,
struct V_72 T_1 * V_89 ,
unsigned int V_177 ,
const void T_1 * V_192 , unsigned int V_98 )
{
int V_28 , V_126 ;
struct V_72 * V_194 ;
struct V_67 * V_76 ;
if ( V_177 == 0 )
return - V_128 ;
V_194 = F_53 ( V_177 * sizeof( * V_194 ) ) ;
if ( ! V_194 )
return - V_173 ;
V_76 = F_32 ( V_117 , V_30 , & V_126 , & V_180 ) ;
if ( ! V_76 )
goto V_207;
if ( V_177 != V_76 -> V_85 -> V_70 ) {
F_25 ( L_41 ) ;
V_126 = - V_128 ;
goto V_208;
}
if ( F_67 ( V_194 , V_89 , V_177 * sizeof( * V_89 ) ) ) {
V_126 = - V_7 ;
goto V_208;
}
F_59 ( & V_76 -> V_88 ) ;
for ( V_28 = 0 ; V_28 < V_177 ; V_28 ++ ) {
V_76 -> V_85 -> V_89 [ V_28 ] . V_96 += V_194 [ V_28 ] . V_96 ;
V_76 -> V_85 -> V_89 [ V_28 ] . V_97 += V_194 [ V_28 ] . V_97 ;
}
F_60 ( & V_76 -> V_88 ) ;
V_126 = 0 ;
V_208:
F_29 ( & V_180 ) ;
V_207:
F_55 ( V_194 ) ;
return V_126 ;
}
static int F_82 ( struct V_117 * V_117 , const void T_1 * V_192 ,
unsigned int V_98 )
{
struct V_135 V_209 ;
if ( F_67 ( & V_209 , V_192 , sizeof( V_209 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_209 ) + V_209 . V_177 * sizeof( struct V_72 ) )
return - V_128 ;
return F_81 ( V_117 , V_209 . V_30 , V_209 . V_89 ,
V_209 . V_177 , V_192 , V_98 ) ;
}
static inline int F_83 ( char T_1 * V_210 , const char * V_211 ,
const char * V_18 , int V_212 ,
int V_213 , int V_214 )
{
char V_30 [ V_114 ] = { 0 } ;
F_84 ( V_30 , V_211 , sizeof( V_30 ) ) ;
if ( F_4 ( V_210 , V_30 , V_114 ) ||
F_85 ( V_214 , ( int T_1 * ) ( V_210 + V_114 ) ) ||
F_86 ( V_210 + V_212 , V_18 , V_213 , V_214 ,
F_87 ( V_214 ) ) )
return - V_7 ;
return 0 ;
}
static inline int F_88 ( const struct V_19 * V_20 ,
const char * V_83 , char T_1 * V_215 )
{
return F_83 ( V_215 + ( ( char * ) V_20 - V_83 ) ,
V_20 -> V_15 . V_21 -> V_30 , V_20 -> V_18 , sizeof( * V_20 ) ,
V_20 -> V_15 . V_21 -> V_213 , V_20 -> V_127 ) ;
}
static inline int F_89 ( const struct V_8 * V_9 ,
const char * V_83 , char T_1 * V_215 )
{
return F_83 ( V_215 + ( ( char * ) V_9 - V_83 ) ,
V_9 -> V_15 . V_16 -> V_30 , V_9 -> V_18 , sizeof( * V_9 ) ,
V_9 -> V_15 . V_16 -> V_213 , V_9 -> V_134 ) ;
}
static inline int F_90 ( struct V_31 * V_32 , const char * V_83 ,
char T_1 * V_215 )
{
int V_126 ;
char T_1 * V_209 ;
const struct V_75 * V_76 ;
if ( V_32 -> V_42 == 0 ) {
if ( F_4 ( V_215 + ( ( char * ) V_32 - V_83 ) , V_32 ,
sizeof( struct V_81 ) ) )
return - V_7 ;
return 0 ;
}
if ( F_4 ( V_215 + ( ( char * ) V_32 - V_83 ) , V_32 , sizeof( * V_32 ) ) )
return - V_7 ;
V_209 = V_215 + ( ( ( char * ) V_32 + V_32 -> V_99 ) - V_83 ) ;
V_76 = (struct V_75 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_126 = F_21 ( V_32 , F_88 , V_83 , V_215 ) ;
if ( V_126 != 0 )
return V_126 ;
V_126 = F_23 ( V_32 , F_89 , V_83 , V_215 ) ;
if ( V_126 != 0 )
return V_126 ;
V_126 = F_83 ( V_209 , V_76 -> V_15 . V_14 -> V_30 , V_76 -> V_18 , sizeof( * V_76 ) ,
V_76 -> V_15 . V_14 -> V_213 , V_76 -> V_163 ) ;
if ( V_126 != 0 )
return V_126 ;
return 0 ;
}
static int F_91 ( struct V_67 * V_76 ,
const struct V_72 * V_174 ,
void T_1 * V_192 , unsigned int V_177 ,
unsigned int V_70 )
{
struct V_72 * V_176 ;
int V_126 = 0 ;
if ( V_177 == 0 )
return 0 ;
if ( V_177 != V_70 ) {
F_25 ( L_42 ) ;
return - V_128 ;
}
V_176 = F_53 ( V_70 * sizeof( * V_176 ) ) ;
if ( ! V_176 )
return - V_173 ;
F_59 ( & V_76 -> V_88 ) ;
F_56 ( V_174 , V_176 , V_70 ) ;
F_60 ( & V_76 -> V_88 ) ;
if ( F_4 ( V_192 , V_176 ,
V_70 * sizeof( struct V_72 ) ) )
V_126 = - V_7 ;
F_55 ( V_176 ) ;
return V_126 ;
}
static int F_92 ( struct V_67 * V_76 , void T_1 * V_192 ,
const int * V_98 , int V_216 )
{
struct V_135 V_194 ;
const struct V_72 * V_174 ;
unsigned int V_139 , V_70 ;
int V_126 ;
char * V_93 ;
if ( V_216 == V_217 ) {
V_139 = V_76 -> V_85 -> V_139 ;
V_70 = V_76 -> V_85 -> V_70 ;
V_93 = V_76 -> V_85 -> V_93 ;
V_174 = V_76 -> V_85 -> V_89 ;
} else {
V_139 = V_76 -> V_68 -> V_139 ;
V_70 = V_76 -> V_68 -> V_70 ;
V_93 = V_76 -> V_68 -> V_93 ;
V_174 = V_76 -> V_68 -> V_89 ;
}
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( * V_98 != sizeof( struct V_135 ) + V_139 +
( V_194 . V_177 ? V_70 * sizeof( struct V_72 ) : 0 ) )
return - V_128 ;
if ( V_194 . V_70 != V_70 ) {
F_25 ( L_43 ) ;
return - V_128 ;
}
if ( V_194 . V_139 != V_139 ) {
F_25 ( L_44 ) ;
return - V_128 ;
}
V_126 = F_91 ( V_76 , V_174 , V_194 . V_89 ,
V_194 . V_177 , V_70 ) ;
if ( V_126 )
return V_126 ;
return F_52 ( V_93 , V_139 ,
F_90 , V_93 , V_194 . V_93 ) ;
}
static int F_93 ( struct V_218 * V_219 ,
int V_216 , void T_1 * V_192 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_94 ( V_219 ) ;
if ( ! F_95 ( V_117 -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_216 ) {
case V_223 :
V_126 = F_66 ( V_117 , V_192 , V_98 ) ;
break;
case V_224 :
V_126 = F_82 ( V_117 , V_192 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_96 ( struct V_218 * V_219 , int V_216 , void T_1 * V_192 , int * V_98 )
{
int V_126 ;
struct V_135 V_194 ;
struct V_67 * V_76 ;
struct V_117 * V_117 = F_94 ( V_219 ) ;
if ( ! F_95 ( V_117 -> V_220 , V_221 ) )
return - V_222 ;
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
V_194 . V_30 [ sizeof( V_194 . V_30 ) - 1 ] = '\0' ;
V_76 = F_32 ( V_117 , V_194 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_76 )
return V_126 ;
switch ( V_216 ) {
case V_225 :
case V_226 :
if ( * V_98 != sizeof( struct V_135 ) ) {
V_126 = - V_128 ;
F_29 ( & V_180 ) ;
break;
}
if ( V_216 == V_225 ) {
V_194 . V_70 = V_76 -> V_85 -> V_70 ;
V_194 . V_139 = V_76 -> V_85 -> V_139 ;
V_194 . V_140 = V_76 -> V_140 ;
} else {
V_194 . V_70 = V_76 -> V_68 -> V_70 ;
V_194 . V_139 = V_76 -> V_68 -> V_139 ;
V_194 . V_140 = V_76 -> V_68 -> V_140 ;
}
F_29 ( & V_180 ) ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
F_25 ( L_45 ) ;
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_217 :
case V_227 :
V_126 = F_92 ( V_76 , V_192 , V_98 , V_216 ) ;
F_29 ( & V_180 ) ;
break;
default:
F_29 ( & V_180 ) ;
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_97 ( void )
{
F_98 ( F_87 ( sizeof( struct V_19 ) ) <
F_99 ( sizeof( struct V_228 ) ) ) ;
return ( int ) F_87 ( sizeof( struct V_19 ) ) -
F_99 ( sizeof( struct V_228 ) ) ;
}
static int F_100 ( const struct V_123 * V_21 ,
unsigned int V_229 )
{
if ( F_101 ( V_21 -> V_230 == - 1 ) )
return F_87 ( V_229 ) - F_99 ( V_229 ) ;
return F_102 ( V_21 ) ;
}
static int F_103 ( struct V_19 * V_20 , void T_1 * * V_231 ,
unsigned int * V_178 )
{
const struct V_123 * V_21 = V_20 -> V_15 . V_21 ;
struct V_228 T_1 * V_232 = * V_231 ;
int V_233 = F_100 ( V_21 , V_20 -> V_127 ) ;
T_4 V_234 = V_20 -> V_127 - V_233 ;
F_104 ( V_233 >= V_20 -> V_127 ) ;
if ( F_4 ( V_232 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_85 ( V_234 , & V_232 -> V_127 ) )
return - V_7 ;
if ( V_21 -> V_235 ) {
if ( V_21 -> V_235 ( V_232 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else {
if ( F_86 ( V_232 -> V_18 , V_20 -> V_18 , V_21 -> V_213 , V_234 ,
F_99 ( V_234 ) ) )
return - V_7 ;
}
* V_178 -= F_97 () + V_233 ;
* V_231 = V_232 -> V_18 ;
* V_231 += V_234 ;
return 0 ;
}
static int F_105 ( struct V_75 * V_76 ,
void T_1 * * V_231 ,
unsigned int * V_178 )
{
const struct V_133 * V_14 = V_76 -> V_15 . V_14 ;
struct V_228 T_1 * V_232 = * V_231 ;
int V_233 = F_106 ( V_14 ) ;
T_4 V_236 = V_76 -> V_163 - V_233 ;
F_104 ( V_233 >= V_76 -> V_163 ) ;
if ( F_4 ( V_232 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_85 ( V_236 , & V_232 -> V_127 ) )
return - V_7 ;
if ( V_14 -> V_235 ) {
if ( V_14 -> V_235 ( V_232 -> V_18 , V_76 -> V_18 ) )
return - V_7 ;
} else {
if ( F_86 ( V_232 -> V_18 , V_76 -> V_18 , V_14 -> V_213 , V_236 ,
F_99 ( V_236 ) ) )
return - V_7 ;
}
* V_178 -= F_97 () + V_233 ;
* V_231 = V_232 -> V_18 ;
* V_231 += V_236 ;
return 0 ;
}
static int F_107 ( struct V_8 * V_9 ,
void T_1 * * V_231 ,
unsigned int * V_178 )
{
return F_105 ( (struct V_75 * ) V_9 ,
V_231 , V_178 ) ;
}
static int F_108 ( struct V_31 * V_32 , void T_1 * * V_231 ,
unsigned int * V_178 )
{
struct V_75 * V_76 ;
struct V_31 T_1 * V_237 ;
T_5 V_125 , V_99 , V_64 ;
T_4 V_238 ;
int V_126 ;
if ( V_32 -> V_42 == 0 ) {
if ( * V_178 < sizeof( struct V_81 ) )
return - V_128 ;
if ( F_4 ( * V_231 , V_32 , sizeof( struct V_81 ) ) )
return - V_7 ;
* V_231 += sizeof( struct V_81 ) ;
* V_178 -= sizeof( struct V_81 ) ;
return 0 ;
}
if ( * V_178 < sizeof( * V_237 ) )
return - V_128 ;
V_237 = * V_231 ;
if ( F_4 ( V_237 , V_32 , sizeof( * V_237 ) ) )
return - V_7 ;
V_238 = * V_178 ;
* V_231 += sizeof( * V_237 ) ;
V_126 = F_21 ( V_32 , F_103 , V_231 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_125 = V_32 -> V_125 - ( V_238 - * V_178 ) ;
V_126 = F_23 ( V_32 , F_107 , V_231 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_99 = V_32 -> V_99 - ( V_238 - * V_178 ) ;
V_76 = (struct V_75 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_126 = F_105 ( V_76 , V_231 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_64 = V_32 -> V_64 - ( V_238 - * V_178 ) ;
if ( F_85 ( V_125 , & V_237 -> V_125 ) ||
F_85 ( V_99 , & V_237 -> V_99 ) ||
F_85 ( V_64 , & V_237 -> V_64 ) )
return - V_7 ;
* V_178 -= sizeof( * V_237 ) ;
return 0 ;
}
static int F_109 ( struct V_19 * V_20 , int * V_233 )
{
* V_233 += F_100 ( V_20 -> V_15 . V_21 , V_20 -> V_127 ) ;
* V_233 += F_97 () ;
return 0 ;
}
static int F_110 ( struct V_8 * V_9 , int * V_233 )
{
* V_233 += F_106 ( V_9 -> V_15 . V_16 ) ;
* V_233 += F_97 () ;
return 0 ;
}
static int F_111 ( const struct V_31 * V_32 ,
const struct V_84 * V_239 ,
const void * V_83 ,
struct V_240 * V_137 )
{
const struct V_75 * V_76 ;
unsigned int V_241 ;
int V_233 , V_126 , V_28 ;
if ( V_32 -> V_42 == 0 )
return 0 ;
V_233 = 0 ;
V_241 = ( void * ) V_32 - V_83 ;
F_21 ( V_32 , F_109 , & V_233 ) ;
F_23 ( V_32 , F_110 , & V_233 ) ;
V_76 = ( const struct V_75 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_233 += F_106 ( V_76 -> V_15 . V_14 ) ;
V_233 += F_97 () ;
V_137 -> V_139 -= V_233 ;
V_126 = F_112 ( V_5 , V_241 , V_233 ) ;
if ( V_126 )
return V_126 ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
const void * V_242 = V_239 -> V_91 [ V_28 ] ;
if ( V_239 -> V_91 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_83 - V_242 ) ) ) {
V_137 -> V_91 [ V_28 ] -= V_233 ;
F_113 ( L_46 ,
V_137 -> V_91 [ V_28 ] + V_233 ,
V_137 -> V_91 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_114 ( const struct V_84 * V_239 ,
struct V_240 * V_137 )
{
unsigned int V_178 = V_239 -> V_139 ;
const void * V_93 = V_239 -> V_93 ;
V_137 -> V_139 = V_178 ;
F_115 ( V_5 , V_239 -> V_70 ) ;
return F_52 ( V_93 , V_178 , F_111 , V_239 ,
V_93 , V_137 ) ;
}
static int F_116 ( struct V_67 * V_76 ,
void T_1 * V_192 , int * V_98 , int V_216 )
{
struct V_240 V_136 , V_194 ;
struct V_72 * V_174 ;
struct V_84 V_243 ;
int V_126 ;
void T_1 * V_167 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
if ( V_216 == V_217 ) {
V_243 . V_139 = V_76 -> V_85 -> V_139 ;
V_243 . V_70 = V_76 -> V_85 -> V_70 ;
V_243 . V_93 = V_76 -> V_85 -> V_93 ;
V_174 = V_76 -> V_85 -> V_89 ;
} else {
V_243 . V_139 = V_76 -> V_68 -> V_139 ;
V_243 . V_70 = V_76 -> V_68 -> V_70 ;
V_243 . V_93 = V_76 -> V_68 -> V_93 ;
V_174 = V_76 -> V_68 -> V_89 ;
}
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( V_194 . V_70 != V_243 . V_70 ||
( V_194 . V_177 && V_194 . V_177 != V_243 . V_70 ) )
return - V_128 ;
memcpy ( & V_136 , & V_194 , sizeof( V_136 ) ) ;
if ( V_216 == V_217 )
V_126 = F_114 ( V_76 -> V_85 , & V_136 ) ;
else
V_126 = F_114 ( & V_243 , & V_136 ) ;
if ( V_126 )
return V_126 ;
if ( * V_98 != sizeof( V_194 ) + V_136 . V_139 +
( V_194 . V_177 ? V_243 . V_70 * sizeof( struct V_72 ) : 0 ) ) {
F_117 ( L_47 ,
* V_98 , V_243 . V_139 , V_136 . V_139 ) ;
return - V_128 ;
}
V_126 = F_91 ( V_76 , V_174 , F_118 ( V_194 . V_89 ) ,
V_194 . V_177 , V_243 . V_70 ) ;
if ( V_126 )
return V_126 ;
V_167 = F_118 ( V_194 . V_93 ) ;
return F_52 ( V_243 . V_93 , V_243 . V_139 ,
F_108 , & V_167 , & V_194 . V_139 ) ;
}
static int F_119 ( struct V_244 * V_66 , unsigned int V_245 )
{
V_66 -> V_246 += V_245 ;
return V_66 -> V_246 >= V_245 ? 0 : - V_128 ;
}
static int F_120 ( struct V_244 * V_66 ,
void * V_18 , unsigned int V_245 )
{
if ( V_66 -> V_247 == NULL )
goto V_248;
F_104 ( V_66 -> V_246 + V_245 > V_66 -> V_249 ) ;
memcpy ( V_66 -> V_247 + V_66 -> V_246 , V_18 , V_245 ) ;
V_248:
V_66 -> V_250 += V_245 ;
return F_119 ( V_66 , V_245 ) ;
}
static int F_121 ( struct V_244 * V_66 , unsigned int V_245 )
{
char * V_251 = V_66 -> V_247 ;
F_104 ( V_251 && V_66 -> V_246 > V_66 -> V_249 ) ;
if ( V_251 != NULL && V_245 > 0 )
memset ( V_251 + V_66 -> V_246 , 0 , V_245 ) ;
return F_119 ( V_66 , V_245 ) ;
}
static int F_122 ( struct V_228 * V_252 ,
enum V_253 V_253 ,
struct V_244 * V_66 ,
const unsigned char * V_83 )
{
char V_30 [ V_114 ] ;
struct V_123 * V_21 ;
struct V_133 * V_254 ;
void * V_1 = NULL ;
int V_233 , V_255 = 0 ;
unsigned int V_256 , V_127 = V_252 -> V_127 ;
F_84 ( V_30 , V_252 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_66 -> V_247 )
V_1 = V_66 -> V_247 + V_66 -> V_246 ;
switch ( V_253 ) {
case V_257 :
V_21 = F_123 ( V_5 , V_30 , 0 ) ;
if ( F_35 ( V_21 ) )
return F_38 ( V_21 ) ;
V_233 = F_100 ( V_21 , V_127 ) ;
if ( V_1 ) {
if ( V_21 -> V_258 )
V_21 -> V_258 ( V_1 , V_252 -> V_18 ) ;
else
memcpy ( V_1 , V_252 -> V_18 , V_127 ) ;
}
V_256 = V_21 -> V_230 ;
if ( F_101 ( V_256 == - 1 ) )
V_256 = V_127 ;
F_36 ( V_21 -> V_130 ) ;
break;
case V_259 :
case V_260 :
V_254 = F_41 ( V_5 , V_30 , 0 ) ;
if ( F_35 ( V_254 ) )
return F_38 ( V_254 ) ;
V_233 = F_106 ( V_254 ) ;
if ( V_1 ) {
if ( V_254 -> V_258 )
V_254 -> V_258 ( V_1 , V_252 -> V_18 ) ;
else
memcpy ( V_1 , V_252 -> V_18 , V_127 ) ;
}
V_256 = V_254 -> V_261 ;
F_36 ( V_254 -> V_130 ) ;
break;
default:
return - V_128 ;
}
V_66 -> V_246 += V_127 + V_233 ;
V_66 -> V_250 += V_127 ;
V_255 = F_87 ( V_256 ) - V_256 ;
if ( V_255 > 0 && V_1 ) {
F_104 ( V_66 -> V_249 <= V_255 ) ;
F_104 ( V_66 -> V_246 - ( V_127 + V_233 ) + V_256 > V_66 -> V_249 - V_255 ) ;
memset ( V_1 + V_256 , 0 , V_255 ) ;
}
return V_233 + V_127 ;
}
static int F_124 ( struct V_228 * V_262 ,
unsigned int V_263 , enum V_253 type ,
struct V_244 * V_66 , const void * V_83 )
{
int V_264 = 0 ;
char * V_265 ;
if ( V_263 == 0 )
return 0 ;
V_265 = ( char * ) V_262 ;
while ( V_263 >= sizeof( * V_262 ) ) {
struct V_19 * V_266 ;
int V_126 ;
V_266 = (struct V_19 * ) V_66 -> V_247 ;
if ( V_266 ) {
char * V_194 ;
V_194 = V_66 -> V_247 + V_66 -> V_246 ;
V_266 = (struct V_19 * ) V_194 ;
}
V_126 = F_120 ( V_66 , V_265 , sizeof( * V_262 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_263 -= sizeof( * V_262 ) ;
V_126 = F_121 ( V_66 , F_97 () ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_262 -> V_127 > V_263 )
return - V_128 ;
V_263 -= V_262 -> V_127 ;
V_126 = F_122 ( V_262 , type , V_66 , V_83 ) ;
if ( V_126 < 0 )
return V_126 ;
F_104 ( V_126 < V_262 -> V_127 ) ;
V_264 += V_126 - V_262 -> V_127 ;
V_264 += F_97 () ;
V_265 += sizeof( * V_262 ) ;
V_265 += V_262 -> V_127 ;
if ( V_266 )
V_266 -> V_127 = V_126 ;
F_125 ( type == V_260 && V_263 ) ;
V_262 = (struct V_228 * ) V_265 ;
}
return V_264 ;
}
static int F_126 ( struct V_31 * V_25 , const unsigned char * V_83 ,
unsigned int * V_267 ,
struct V_244 * V_66 )
{
unsigned int V_28 , V_153 , V_268 , V_269 = 0 ;
unsigned int V_270 [ 4 ] ;
unsigned int * V_271 = NULL ;
int V_126 ;
char * V_272 ;
if ( * V_267 < sizeof( struct V_81 ) )
return - V_128 ;
if ( ! V_25 -> V_42 ) {
* V_267 -= sizeof( struct V_81 ) ;
return F_120 ( V_66 , V_25 , sizeof( struct V_81 ) ) ;
}
if ( * V_267 < sizeof( * V_25 ) || V_25 -> V_64 < sizeof( * V_25 ) )
return - V_128 ;
V_268 = V_66 -> V_250 ;
V_126 = F_120 ( V_66 , V_25 ,
F_127 ( struct V_31 , V_125 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_270 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_270 [ 1 ] , & V_25 -> V_125 ,
sizeof( V_270 ) - sizeof( V_270 [ 0 ] ) ) ;
if ( V_66 -> V_247 ) {
V_272 = V_66 -> V_247 + V_66 -> V_246 ;
V_271 = ( unsigned int * ) V_272 ;
}
V_126 = F_120 ( V_66 , & V_270 [ 1 ] ,
sizeof( V_270 ) - sizeof( V_270 [ 0 ] ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_272 = ( char * ) V_25 ;
for ( V_28 = 0 , V_153 = 1 ; V_153 < 4 ; V_153 ++ , V_28 ++ ) {
struct V_228 * V_262 ;
unsigned int V_178 ;
char * V_265 = V_272 ;
V_265 = V_272 + V_270 [ V_28 ] ;
if ( V_270 [ V_28 ] > V_270 [ V_153 ] )
return - V_128 ;
V_262 = (struct V_228 * ) V_265 ;
V_178 = V_270 [ V_153 ] - V_270 [ V_28 ] ;
V_126 = F_124 ( V_262 , V_178 , V_28 , V_66 , V_83 ) ;
if ( V_126 < 0 )
return V_126 ;
V_269 += V_126 ;
if ( V_271 && V_269 ) {
F_113 ( L_48 ,
V_271 [ V_28 ] , V_270 [ V_153 ] + V_269 ) ;
V_271 [ V_28 ] = V_270 [ V_153 ] + V_269 ;
}
}
if ( V_66 -> V_247 == NULL ) {
unsigned int V_141 = V_272 - ( char * ) V_83 ;
V_126 = F_112 ( V_5 , V_141 , V_269 ) ;
if ( V_126 < 0 )
return V_126 ;
}
V_268 = V_66 -> V_250 - V_268 ;
F_104 ( * V_267 < V_268 ) ;
* V_267 -= V_268 ;
return 0 ;
}
static int F_128 ( unsigned char * V_18 , unsigned int V_273 ,
struct V_244 * V_66 )
{
unsigned int V_274 = V_273 ;
int V_126 ;
V_126 = F_52 ( V_18 , V_273 , F_126 , V_18 ,
& V_274 , V_66 ) ;
if ( V_126 < 0 )
return V_126 ;
F_125 ( V_274 ) ;
return V_66 -> V_246 ;
}
static int F_129 ( struct V_135 * V_136 ,
void T_1 * V_192 , unsigned int V_98 )
{
struct V_240 V_194 ;
int V_28 ;
if ( V_98 < sizeof( V_194 ) )
return - V_128 ;
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_194 ) + V_194 . V_139 )
return - V_128 ;
if ( V_194 . V_139 == 0 )
return - V_128 ;
if ( V_194 . V_70 >= ( ( V_195 - sizeof( struct V_84 ) ) /
V_196 - V_197 ) / sizeof( struct V_72 ) )
return - V_173 ;
if ( V_194 . V_177 >= V_195 / sizeof( struct V_72 ) )
return - V_173 ;
memcpy ( V_136 , & V_194 , F_127 ( struct V_135 , V_91 ) ) ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ )
V_136 -> V_91 [ V_28 ] = F_118 ( V_194 . V_91 [ V_28 ] ) ;
V_136 -> V_177 = V_194 . V_177 ;
V_136 -> V_89 = F_118 ( V_194 . V_89 ) ;
V_136 -> V_93 = F_118 ( V_194 . V_93 ) ;
return 0 ;
}
static int F_130 ( struct V_117 * V_117 , void T_1 * V_192 ,
unsigned int V_98 )
{
int V_126 , V_28 , V_193 , V_275 ;
struct V_84 * V_137 ;
struct V_135 V_194 ;
struct V_244 V_66 ;
void * V_276 ;
V_126 = F_129 ( & V_194 , V_192 , V_98 ) ;
if ( V_126 ) {
if ( V_126 == - V_128 && F_66 ( V_117 , V_192 , V_98 ) == 0 )
V_126 = 0 ;
return V_126 ;
}
V_193 = F_68 ( V_194 . V_70 ) * V_172 ;
V_137 = F_53 ( sizeof( * V_137 ) + V_193 ) ;
if ( ! V_137 )
return - V_173 ;
if ( V_193 )
memset ( V_137 -> V_89 , 0 , V_193 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_137 -> V_93 = F_53 ( V_194 . V_139 ) ;
if ( ! V_137 -> V_93 ) {
V_126 = - V_173 ;
goto V_198;
}
if ( F_67 (
V_137 -> V_93 , V_194 . V_93 , V_194 . V_139 ) != 0 ) {
V_126 = - V_7 ;
goto V_199;
}
V_276 = V_137 -> V_93 ;
F_131 ( V_5 ) ;
F_115 ( V_5 , V_194 . V_70 ) ;
V_126 = F_128 ( V_276 , V_194 . V_139 , & V_66 ) ;
if ( V_126 < 0 )
goto V_277;
F_113 ( L_49 ,
V_194 . V_139 , V_66 . V_246 , V_66 . V_250 ,
F_2 ( V_5 , V_194 . V_139 ) ) ;
V_275 = V_126 ;
V_137 -> V_93 = F_53 ( V_275 ) ;
if ( ! V_137 -> V_93 ) {
F_55 ( V_276 ) ;
V_126 = - V_173 ;
goto V_277;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_247 = V_137 -> V_93 ;
V_66 . V_249 = V_275 ;
V_126 = F_128 ( V_276 , V_194 . V_139 , & V_66 ) ;
F_104 ( V_126 < 0 ) ;
F_55 ( V_276 ) ;
V_194 . V_139 = V_275 ;
for ( V_28 = 0 ; V_28 < V_142 ; V_28 ++ ) {
char T_1 * V_278 ;
if ( V_194 . V_91 [ V_28 ] ) {
unsigned int V_279 ;
V_278 = ( char T_1 * ) V_194 . V_91 [ V_28 ] ;
V_279 = V_278 - V_194 . V_93 ;
V_278 += F_2 ( V_5 , V_279 ) ;
V_194 . V_91 [ V_28 ] = (struct V_81 T_1 * ) V_278 ;
}
}
F_132 ( V_5 ) ;
F_133 ( V_5 ) ;
V_126 = F_57 ( V_117 , & V_194 , V_137 ) ;
if ( V_126 == 0 )
return V_126 ;
V_199:
F_55 ( V_137 -> V_93 ) ;
V_198:
F_55 ( V_137 ) ;
return V_126 ;
V_277:
F_132 ( V_5 ) ;
F_133 ( V_5 ) ;
goto V_199;
}
static int F_134 ( struct V_117 * V_117 , void T_1 * V_192 ,
unsigned int V_98 )
{
struct V_240 V_209 ;
if ( F_67 ( & V_209 , V_192 , sizeof( V_209 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_209 ) + V_209 . V_177 * sizeof( struct V_72 ) )
return F_82 ( V_117 , V_192 , V_98 ) ;
return F_81 ( V_117 , V_209 . V_30 , F_118 ( V_209 . V_89 ) ,
V_209 . V_177 , V_192 , V_98 ) ;
}
static int F_135 ( struct V_218 * V_219 ,
int V_216 , void T_1 * V_192 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_94 ( V_219 ) ;
if ( ! F_95 ( V_117 -> V_220 , V_221 ) )
return - V_222 ;
switch ( V_216 ) {
case V_223 :
V_126 = F_130 ( V_117 , V_192 , V_98 ) ;
break;
case V_224 :
V_126 = F_134 ( V_117 , V_192 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_136 ( struct V_218 * V_219 , int V_216 ,
void T_1 * V_192 , int * V_98 )
{
int V_126 ;
struct V_240 V_194 ;
struct V_67 * V_76 ;
struct V_117 * V_117 = F_94 ( V_219 ) ;
if ( ! F_95 ( V_117 -> V_220 , V_221 ) )
return - V_222 ;
if ( ( V_216 == V_225 ||
V_216 == V_226 ) && * V_98 != sizeof( V_194 ) )
return F_96 ( V_219 , V_216 , V_192 , V_98 ) ;
if ( F_67 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
V_194 . V_30 [ sizeof( V_194 . V_30 ) - 1 ] = '\0' ;
V_76 = F_32 ( V_117 , V_194 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_76 )
return V_126 ;
F_131 ( V_5 ) ;
switch ( V_216 ) {
case V_225 :
V_194 . V_70 = V_76 -> V_85 -> V_70 ;
V_126 = F_114 ( V_76 -> V_85 , & V_194 ) ;
if ( V_126 )
goto V_34;
V_194 . V_140 = V_76 -> V_140 ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_226 :
V_194 . V_70 = V_76 -> V_68 -> V_70 ;
V_194 . V_139 = V_76 -> V_68 -> V_139 ;
V_194 . V_140 = V_76 -> V_68 -> V_140 ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_217 :
case V_227 :
if ( F_92 ( V_76 , V_192 , V_98 , V_216 ) == 0 )
V_126 = 0 ;
else
V_126 = F_116 ( V_76 , V_192 , V_98 , V_216 ) ;
break;
default:
V_126 = - V_128 ;
}
V_34:
F_132 ( V_5 ) ;
F_133 ( V_5 ) ;
F_29 ( & V_180 ) ;
return V_126 ;
}
static int T_6 F_137 ( void )
{
int V_126 ;
V_126 = F_138 ( & V_100 ) ;
if ( V_126 < 0 )
return V_126 ;
V_126 = F_139 ( & V_280 ) ;
if ( V_126 < 0 ) {
F_140 ( & V_100 ) ;
return V_126 ;
}
F_141 ( V_281 L_50 ) ;
return 0 ;
}
static void T_7 F_142 ( void )
{
F_143 ( & V_280 ) ;
F_140 ( & V_100 ) ;
F_141 ( V_281 L_51 ) ;
}
