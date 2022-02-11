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
int V_40 , V_28 ;
if ( F_10 ( V_11 ) )
V_39 = F_11 ( V_41 ) ;
else
V_39 = V_36 -> V_42 ;
if ( V_32 -> V_43 & V_44 ) {
if ( F_12 ( F_13 ( V_39 ) >= V_45 , V_46 ) )
return 1 ;
} else if ( ! ( V_32 -> V_43 & V_47 ) &&
F_12 ( V_32 -> V_39 != V_39 , V_46 ) )
return 1 ;
if ( F_12 ( F_7 ( V_32 -> V_33 , V_33 ) , V_48 ) )
return 1 ;
if ( F_12 ( F_7 ( V_32 -> V_34 , V_34 ) , V_49 ) )
return 1 ;
if ( V_33 && ( V_38 = F_14 ( V_33 ) ) != NULL &&
F_12 ( F_7 ( V_32 -> V_50 , V_38 -> V_51 -> V_52 ) , V_53 ) )
return 1 ;
if ( V_34 && ( V_38 = F_14 ( V_34 ) ) != NULL &&
F_12 ( F_7 ( V_32 -> V_54 , V_38 -> V_51 -> V_52 ) , V_55 ) )
return 1 ;
if ( V_32 -> V_43 & V_56 ) {
V_40 = 0 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ )
V_40 |= ( V_36 -> V_57 [ V_28 ] ^ V_32 -> V_58 [ V_28 ] ) &
V_32 -> V_59 [ V_28 ] ;
if ( F_12 ( V_40 != 0 , V_60 ) )
return 1 ;
}
if ( V_32 -> V_43 & V_61 ) {
V_40 = 0 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ )
V_40 |= ( V_36 -> V_62 [ V_28 ] ^ V_32 -> V_63 [ V_28 ] ) &
V_32 -> V_64 [ V_28 ] ;
if ( F_12 ( V_40 != 0 , V_65 ) )
return 1 ;
}
return 0 ;
}
unsigned int F_15 ( unsigned int V_66 , struct V_10 * V_11 ,
const struct V_26 * V_33 , const struct V_26 * V_34 ,
struct V_67 * V_68 )
{
int V_28 , V_69 ;
struct V_31 * V_70 ;
struct V_71 * V_72 , * V_73 ;
const struct V_74 * V_75 ;
int V_40 , V_76 = 0 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
const char * V_81 ;
const struct V_82 * V_83 ;
struct V_12 V_84 ;
V_84 . V_85 = V_5 ;
V_84 . V_33 = V_33 ;
V_84 . V_34 = V_34 ;
V_84 . V_86 = false ;
V_84 . V_87 = V_66 ;
F_16 ( & V_68 -> V_88 ) ;
V_83 = V_68 -> V_83 ;
V_73 = F_17 ( V_83 -> V_89 , V_83 -> V_69 ,
F_18 () ) ;
if ( V_83 -> V_90 )
V_78 = V_83 -> V_90 [ F_18 () ] ;
else
V_78 = NULL ;
V_80 = V_83 -> V_91 [ V_66 ] ;
V_69 = V_83 -> V_91 [ V_66 ] -> V_69 ;
V_70 = (struct V_31 * ) ( V_83 -> V_91 [ V_66 ] -> V_18 ) ;
V_72 = V_73 + V_83 -> V_91 [ V_66 ] -> V_92 ;
V_81 = V_83 -> V_93 ;
V_28 = 0 ;
while ( V_28 < V_69 ) {
if ( F_8 ( V_70 , V_11 , V_33 , V_34 ) )
goto V_94;
if ( F_19 ( V_70 , F_6 , V_11 , & V_84 ) != 0 )
goto V_94;
if ( V_84 . V_86 ) {
F_20 ( & V_68 -> V_88 ) ;
return V_95 ;
}
( * ( V_72 + V_28 ) ) . V_96 ++ ;
( * ( V_72 + V_28 ) ) . V_97 += V_11 -> V_98 ;
F_21 ( V_70 , F_5 , V_11 , & V_84 ) ;
V_75 = (struct V_74 * )
( ( ( char * ) V_70 ) + V_70 -> V_99 ) ;
if ( ! V_75 -> V_15 . V_14 -> V_14 )
V_40 = ( (struct V_100 * ) V_75 ) -> V_40 ;
else {
V_84 . V_14 = V_75 -> V_15 . V_14 ;
V_84 . V_17 = V_75 -> V_18 ;
V_40 = V_75 -> V_15 . V_14 -> V_14 ( V_11 , & V_84 ) ;
}
if ( V_40 == V_101 ) {
F_20 ( & V_68 -> V_88 ) ;
return V_102 ;
}
if ( V_40 == V_103 ) {
F_20 ( & V_68 -> V_88 ) ;
return V_95 ;
}
if ( V_40 == V_104 ) {
V_105:
#ifdef F_22
if ( V_76 == 0 ) {
F_23 ( L_1 ) ;
goto V_94;
}
#endif
V_76 -- ;
V_28 = V_78 [ V_76 ] . V_106 ;
V_80 = V_78 [ V_76 ] . V_80 ;
V_69 = V_80 -> V_69 ;
V_70 = V_78 [ V_76 ] . V_32 ;
V_72 = V_73 +
V_80 -> V_92 ;
continue;
}
if ( V_40 == V_107 )
goto V_94;
#ifdef F_22
if ( V_40 < 0 ) {
F_23 ( L_2 ) ;
F_20 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_78 [ V_76 ] . V_106 = V_28 + 1 ;
V_78 [ V_76 ] . V_80 = V_80 ;
V_78 [ V_76 ] . V_32 = F_24 ( V_70 ) ;
V_28 = 0 ;
V_80 = (struct V_79 * ) ( V_81 + V_40 ) ;
#ifdef F_22
if ( V_80 -> V_108 ) {
F_23 ( L_3 ) ;
F_20 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_69 = V_80 -> V_69 ;
V_70 = (struct V_31 * ) V_80 -> V_18 ;
V_72 = V_73 + V_80 -> V_92 ;
V_76 ++ ;
continue;
V_94:
V_70 = F_24 ( V_70 ) ;
V_28 ++ ;
}
if ( V_80 -> V_109 == V_104 )
goto V_105;
if ( V_80 -> V_109 == V_101 ) {
F_20 ( & V_68 -> V_88 ) ;
return V_102 ;
}
F_20 ( & V_68 -> V_88 ) ;
return V_95 ;
}
static inline void *
F_25 ( struct V_110 * V_111 , const char * V_30 , int * error ,
struct V_112 * V_112 )
{
struct {
struct V_110 V_113 ;
char V_30 [ V_114 ] ;
} * V_32 ;
F_26 ( V_112 ) ;
F_27 (e, head, list) {
if ( strcmp ( V_32 -> V_30 , V_30 ) == 0 )
return V_32 ;
}
* error = - V_115 ;
F_28 ( V_112 ) ;
return NULL ;
}
static void *
F_29 ( struct V_110 * V_111 , const char * V_30 , const char * V_116 ,
int * error , struct V_112 * V_112 )
{
return F_30 (
F_25 ( V_111 , V_30 , error , V_112 ) ,
L_4 , V_116 , V_30 ) ;
}
static inline struct V_67 *
F_31 ( struct V_117 * V_117 , const char * V_30 , int * error ,
struct V_112 * V_112 )
{
return F_29 ( & V_117 -> V_118 . V_119 [ V_5 ] , V_30 ,
L_5 , error , V_112 ) ;
}
static inline int
F_32 ( struct V_19 * V_20 , struct V_120 * V_13 ,
unsigned int * V_121 )
{
const struct V_31 * V_32 = V_13 -> V_122 ;
struct V_123 * V_21 ;
T_3 V_124 = ( ( char * ) V_32 + V_32 -> V_125 ) - ( char * ) V_20 ;
int V_126 ;
if ( V_124 < sizeof( struct V_19 ) ||
V_124 - sizeof( struct V_19 ) < V_20 -> V_127 )
return - V_128 ;
V_21 = F_33 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_20 -> V_15 . V_21 = V_21 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_20 -> V_18 ;
V_126 = F_36 ( V_13 , V_20 -> V_127 ,
V_32 -> V_39 , V_32 -> V_129 & V_46 ) ;
if ( V_126 < 0 ) {
F_37 ( V_21 -> V_130 ) ;
return V_126 ;
}
( * V_121 ) ++ ;
return 0 ;
}
static inline int
F_38 ( struct V_8 * V_9 , struct V_131 * V_13 ,
unsigned int * V_121 )
{
const struct V_31 * V_32 = V_13 -> V_122 ;
struct V_132 * V_16 ;
T_3 V_124 = ( ( char * ) V_32 + V_32 -> V_99 ) - ( char * ) V_9 ;
int V_126 ;
if ( V_124 < sizeof( struct V_8 ) ||
V_124 - sizeof( struct V_8 ) < V_9 -> V_133 )
return - V_128 ;
V_16 = F_39 ( V_5 , V_9 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_16 ) )
return F_35 ( V_16 ) ;
V_9 -> V_15 . V_16 = V_16 ;
V_13 -> V_14 = V_16 ;
V_13 -> V_17 = V_9 -> V_18 ;
V_126 = F_40 ( V_13 , V_9 -> V_133 ,
V_32 -> V_39 , V_32 -> V_129 & V_46 ) ;
if ( V_126 < 0 ) {
F_37 ( V_16 -> V_130 ) ;
return V_126 ;
}
( * V_121 ) ++ ;
return 0 ;
}
static int F_41 ( const struct V_134 * V_135 ,
struct V_82 * V_136 )
{
unsigned int V_137 = V_135 -> V_138 ;
unsigned int V_139 = V_135 -> V_139 ;
unsigned int V_140 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
V_136 -> V_91 [ V_28 ] = NULL ;
V_136 -> V_138 = V_135 -> V_138 ;
V_136 -> V_69 = V_135 -> V_69 ;
while ( V_140 < V_137 ) {
T_3 V_124 = V_137 - V_140 ;
struct V_31 * V_32 = ( void * ) V_136 -> V_93 + V_140 ;
if ( V_124 < sizeof( unsigned int ) )
break;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ( V_139 & ( 1 << V_28 ) ) == 0 )
continue;
if ( ( char T_1 * ) V_135 -> V_91 [ V_28 ] ==
V_135 -> V_93 + V_140 )
break;
}
if ( V_28 != V_141 || ! ( V_32 -> V_43 & V_142 ) ) {
if ( V_32 -> V_43 != 0 ) {
F_23 ( L_6
L_7 ) ;
return - V_128 ;
}
if ( V_28 != V_141 )
V_136 -> V_91 [ V_28 ] = (struct V_79 * ) V_32 ;
if ( V_124 < sizeof( struct V_79 ) )
break;
V_140 += sizeof( struct V_79 ) ;
} else {
if ( V_124 < sizeof( struct V_31 ) )
break;
if ( V_124 < V_32 -> V_143 )
break;
if ( V_32 -> V_143 < sizeof( struct V_31 ) )
return - V_128 ;
V_140 += V_32 -> V_143 ;
}
}
if ( V_140 != V_137 ) {
F_23 ( L_8 ) ;
return - V_128 ;
}
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ! V_136 -> V_91 [ V_28 ] &&
( V_139 & ( 1 << V_28 ) ) ) {
F_23 ( L_9 ) ;
return - V_128 ;
}
}
return 0 ;
}
static inline int
F_42 ( const struct V_31 * V_32 ,
const struct V_82 * V_136 ,
unsigned int * V_106 , unsigned int * V_121 ,
unsigned int * V_144 , unsigned int * V_145 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ( void * ) V_32 == ( void * ) V_136 -> V_91 [ V_28 ] )
break;
}
if ( V_28 != V_141 || ! V_32 -> V_43 ) {
if ( * V_106 != * V_121 ) {
F_23 ( L_10
L_11 ) ;
return - V_128 ;
}
if ( ( (struct V_79 * ) V_32 ) -> V_109 != V_103 &&
( (struct V_79 * ) V_32 ) -> V_109 != V_101 ) {
if ( V_28 != V_141 ||
( (struct V_79 * ) V_32 ) -> V_109 != V_104 ) {
F_23 ( L_12 ) ;
return - V_128 ;
}
}
if ( V_28 == V_141 )
( * V_145 ) ++ ;
if ( ( (struct V_79 * ) V_32 ) -> V_92 != * V_144 ) {
F_23 ( L_13 ) ;
return - V_128 ;
}
* V_106 = ( (struct V_79 * ) V_32 ) -> V_69 ;
* V_121 = 0 ;
return 0 ;
}
if ( sizeof( struct V_31 ) > V_32 -> V_125 ||
V_32 -> V_125 > V_32 -> V_99 ||
V_32 -> V_99 >= V_32 -> V_143 ) {
F_23 ( L_14 ) ;
return - V_128 ;
}
if ( V_32 -> V_143 - V_32 -> V_99 < sizeof( struct V_74 ) ) {
F_23 ( L_15 ) ;
return - V_128 ;
}
( * V_121 ) ++ ;
( * V_144 ) ++ ;
return 0 ;
}
static inline int
F_43 ( struct V_31 * V_32 , struct V_82 * V_136 ,
unsigned int * V_106 , struct V_146 * V_147 )
{
int V_28 ;
if ( V_32 -> V_43 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( V_136 -> V_91 [ V_28 ] == (struct V_79 * ) V_32 )
break;
}
if ( V_28 != V_141 )
return 0 ;
V_147 [ * V_106 ] . V_78 . V_80 = (struct V_79 * ) V_32 ;
V_147 [ * V_106 ] . V_78 . V_106 = 0 ;
V_147 [ * V_106 ] . V_148 = 0 ;
( * V_106 ) ++ ;
return 0 ;
}
static inline int
F_44 ( struct V_19 * V_20 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_149 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_21 = V_20 -> V_15 . V_21 ;
V_13 . V_22 = V_20 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_21 -> V_150 != NULL )
V_13 . V_21 -> V_150 ( & V_13 ) ;
F_37 ( V_13 . V_21 -> V_130 ) ;
return 0 ;
}
static inline int
F_45 ( struct V_8 * V_9 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_151 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_9 -> V_15 . V_16 ;
V_13 . V_17 = V_9 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_14 -> V_150 != NULL )
V_13 . V_14 -> V_150 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_46 ( struct V_31 * V_32 , struct V_117 * V_117 , unsigned int * V_121 )
{
struct V_151 V_13 ;
struct V_74 * V_75 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_121 && ( * V_121 ) -- == 0 )
return 1 ;
F_21 ( V_32 , F_45 , V_117 , NULL ) ;
F_19 ( V_32 , F_44 , V_117 , NULL ) ;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_75 -> V_15 . V_14 ;
V_13 . V_17 = V_75 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_14 -> V_150 != NULL )
V_13 . V_14 -> V_150 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_47 ( struct V_31 * V_32 , struct V_117 * V_117 ,
const struct V_82 * V_136 ,
const char * V_30 , unsigned int * V_121 ,
struct V_146 * V_152 , unsigned int V_145 )
{
struct V_74 * V_75 ;
struct V_132 * V_14 ;
unsigned int V_28 , V_153 , V_66 = 0 , V_148 = 0 ;
T_3 V_154 ;
int V_126 ;
struct V_120 V_155 ;
struct V_131 V_156 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_32 -> V_43 & ~ V_157 ) {
F_23 ( L_16 ) ;
return - V_128 ;
}
if ( V_32 -> V_129 & ~ V_158 ) {
F_23 ( L_17 ) ;
return - V_128 ;
}
if ( ( V_32 -> V_43 & V_47 ) && ( V_32 -> V_43 & V_44 ) ) {
F_23 ( L_18 ) ;
return - V_128 ;
}
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ! V_136 -> V_91 [ V_28 ] )
continue;
if ( ( char * ) V_136 -> V_91 [ V_28 ] < ( char * ) V_32 )
V_66 = V_28 ;
else
break;
}
if ( V_28 < V_141 )
V_148 = ( 1 << V_66 ) | ( 1 << V_141 ) ;
else {
for ( V_28 = 0 ; V_28 < V_145 ; V_28 ++ )
if ( ( char * ) ( V_152 [ V_28 ] . V_78 . V_80 ) > ( char * ) V_32 )
break;
if ( V_28 == 0 )
V_148 = ( 1 << V_66 ) | ( 1 << V_141 ) ;
else
V_148 = V_152 [ V_28 - 1 ] . V_148 ;
}
V_28 = 0 ;
V_155 . V_117 = V_156 . V_117 = V_117 ;
V_155 . V_68 = V_156 . V_68 = V_30 ;
V_155 . V_122 = V_156 . V_122 = V_32 ;
V_155 . V_159 = V_156 . V_159 = V_148 ;
V_155 . V_85 = V_156 . V_85 = V_5 ;
V_126 = F_19 ( V_32 , F_32 , & V_155 , & V_28 ) ;
if ( V_126 != 0 )
goto V_160;
V_153 = 0 ;
V_126 = F_21 ( V_32 , F_38 , & V_156 , & V_153 ) ;
if ( V_126 != 0 )
goto V_161;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_154 = V_32 -> V_143 - V_32 -> V_99 ;
V_14 = F_39 ( V_5 , V_75 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_14 ) ) {
V_126 = F_35 ( V_14 ) ;
goto V_161;
}
V_75 -> V_15 . V_14 = V_14 ;
if ( V_75 -> V_15 . V_14 == & V_100 ) {
if ( V_154 < sizeof( struct V_100 ) ) {
F_23 ( L_19 ) ;
V_126 = - V_7 ;
goto V_161;
}
if ( ( (struct V_100 * ) V_75 ) -> V_40 <
- V_162 ) {
F_23 ( L_20 ) ;
V_126 = - V_7 ;
goto V_161;
}
} else if ( V_75 -> V_163 > V_154 - sizeof( struct V_74 ) ) {
F_37 ( V_75 -> V_15 . V_14 -> V_130 ) ;
V_126 = - V_7 ;
goto V_161;
}
V_156 . V_14 = V_14 ;
V_156 . V_17 = V_75 -> V_18 ;
V_126 = F_40 ( & V_156 , V_75 -> V_163 ,
V_32 -> V_39 , V_32 -> V_129 & V_46 ) ;
if ( V_126 < 0 ) {
F_37 ( V_14 -> V_130 ) ;
goto V_161;
}
( * V_121 ) ++ ;
return 0 ;
V_161:
F_21 ( V_32 , F_45 , V_117 , & V_153 ) ;
V_160:
F_19 ( V_32 , F_44 , V_117 , & V_28 ) ;
return V_126 ;
}
static int F_48 ( const struct V_79 * V_164 , struct V_146 * V_152 ,
unsigned int V_145 , unsigned int V_165 , char * V_81 )
{
int V_28 , V_166 = - 1 , V_167 = 0 , V_69 = V_164 -> V_69 , V_40 ;
const struct V_31 * V_32 = (struct V_31 * ) V_164 -> V_18 ;
const struct V_74 * V_75 ;
while ( V_167 < V_69 || V_166 != - 1 ) {
if ( V_167 == V_69 ) {
V_32 = V_152 [ V_166 ] . V_78 . V_32 ;
if ( V_152 [ V_166 ] . V_168 != - 1 )
V_69 =
V_152 [ V_152 [ V_166 ] . V_168 ] . V_78 . V_80 -> V_69 ;
else
V_69 = V_164 -> V_69 ;
V_167 = V_152 [ V_166 ] . V_78 . V_106 ;
V_152 [ V_166 ] . V_78 . V_106 = 0 ;
V_166 = V_152 [ V_166 ] . V_168 ;
if ( V_167 == V_69 )
continue;
}
V_75 = (struct V_74 * )
( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
if ( strcmp ( V_75 -> V_15 . V_30 , V_169 ) )
goto V_94;
if ( V_32 -> V_99 + sizeof( struct V_100 ) >
V_32 -> V_143 ) {
F_23 ( L_19 ) ;
return - 1 ;
}
V_40 = ( (struct V_100 * ) V_75 ) -> V_40 ;
if ( V_40 >= 0 ) {
struct V_79 * V_170 =
(struct V_79 * ) ( V_81 + V_40 ) ;
for ( V_28 = 0 ; V_28 < V_145 ; V_28 ++ )
if ( V_170 == V_152 [ V_28 ] . V_78 . V_80 )
break;
if ( V_28 == V_145 ) {
F_23 ( L_21 ) ;
return - 1 ;
}
if ( V_152 [ V_28 ] . V_78 . V_106 ) {
F_23 ( L_22 ) ;
return - 1 ;
}
if ( V_152 [ V_28 ] . V_148 & ( 1 << V_165 ) )
goto V_94;
V_152 [ V_28 ] . V_78 . V_106 = V_167 + 1 ;
V_167 = 0 ;
V_152 [ V_28 ] . V_78 . V_32 = F_24 ( V_32 ) ;
V_32 = (struct V_31 * ) ( V_170 -> V_18 ) ;
V_69 = V_170 -> V_69 ;
V_152 [ V_28 ] . V_168 = V_166 ;
V_166 = V_28 ;
V_152 [ V_28 ] . V_148 |= ( 1 << V_165 ) ;
continue;
}
V_94:
V_32 = F_24 ( V_32 ) ;
V_167 ++ ;
}
return 0 ;
}
static int F_49 ( struct V_117 * V_117 , const char * V_30 ,
struct V_82 * V_136 )
{
unsigned int V_28 , V_153 , V_171 , V_145 ;
int V_126 ;
struct V_146 * V_152 = NULL ;
V_28 = 0 ;
while ( V_28 < V_141 && ! V_136 -> V_91 [ V_28 ] )
V_28 ++ ;
if ( V_28 == V_141 ) {
F_23 ( L_23 ) ;
return - V_128 ;
}
if ( V_136 -> V_91 [ V_28 ] != (struct V_79 * ) V_136 -> V_93 ) {
F_23 ( L_24 ) ;
return - V_128 ;
}
for ( V_153 = V_28 + 1 ; V_153 < V_141 ; V_153 ++ ) {
if ( ! V_136 -> V_91 [ V_153 ] )
continue;
if ( V_136 -> V_91 [ V_153 ] <= V_136 -> V_91 [ V_28 ] ) {
F_23 ( L_25 ) ;
return - V_128 ;
}
V_28 = V_153 ;
}
V_28 = 0 ;
V_153 = 0 ;
V_171 = 0 ;
V_145 = 0 ;
V_126 = F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_42 , V_136 ,
& V_28 , & V_153 , & V_171 , & V_145 ) ;
if ( V_126 != 0 )
return V_126 ;
if ( V_28 != V_153 ) {
F_23 ( L_26
L_27 ) ;
return - V_128 ;
}
if ( V_171 != V_136 -> V_69 ) {
F_23 ( L_28 ) ;
return - V_128 ;
}
if ( V_145 ) {
V_136 -> V_90 =
F_51 ( V_172 * sizeof( * ( V_136 -> V_90 ) ) ) ;
if ( ! V_136 -> V_90 )
return - V_173 ;
F_52 (i) {
V_136 -> V_90 [ V_28 ] =
F_51 ( V_145 * sizeof( * ( V_136 -> V_90 [ 0 ] ) ) ) ;
if ( ! V_136 -> V_90 [ V_28 ] ) {
while ( V_28 )
F_53 ( V_136 -> V_90 [ -- V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
V_136 -> V_90 = NULL ;
return - V_173 ;
}
}
V_152 = F_51 ( V_145 * sizeof( * V_152 ) ) ;
if ( ! V_152 )
return - V_173 ;
V_28 = 0 ;
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_43 , V_136 , & V_28 , V_152 ) ;
if ( V_28 != V_145 ) {
F_23 ( L_29 ) ;
F_53 ( V_152 ) ;
return - V_7 ;
}
}
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
if ( V_136 -> V_91 [ V_28 ] )
if ( F_48 ( V_136 -> V_91 [ V_28 ] ,
V_152 , V_145 , V_28 , V_136 -> V_93 ) ) {
F_53 ( V_152 ) ;
return - V_128 ;
}
V_28 = 0 ;
V_126 = F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_47 , V_117 , V_136 , V_30 , & V_28 , V_152 , V_145 ) ;
if ( V_126 != 0 ) {
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_46 , V_117 , & V_28 ) ;
}
F_53 ( V_152 ) ;
return V_126 ;
}
static void F_54 ( const struct V_71 * V_174 ,
struct V_71 * V_89 , unsigned int V_69 )
{
int V_28 , V_175 ;
struct V_71 * V_72 ;
memcpy ( V_89 , V_174 ,
sizeof( struct V_71 ) * V_69 ) ;
F_52 (cpu) {
if ( V_175 == 0 )
continue;
V_72 = F_17 ( V_174 , V_69 , V_175 ) ;
for ( V_28 = 0 ; V_28 < V_69 ; V_28 ++ ) {
V_89 [ V_28 ] . V_96 += V_72 [ V_28 ] . V_96 ;
V_89 [ V_28 ] . V_97 += V_72 [ V_28 ] . V_97 ;
}
}
}
static int F_55 ( struct V_117 * V_117 , struct V_134 * V_135 ,
struct V_82 * V_136 )
{
int V_126 , V_28 ;
struct V_71 * V_176 = NULL ;
struct V_82 * V_68 ;
struct V_67 * V_75 ;
if ( V_135 -> V_177 ) {
unsigned long V_178 = V_135 -> V_177 * sizeof( * V_176 ) ;
V_176 = F_51 ( V_178 ) ;
if ( ! V_176 )
return - V_173 ;
}
V_136 -> V_90 = NULL ;
V_126 = F_41 ( V_135 , V_136 ) ;
if ( V_126 != 0 )
goto V_179;
V_126 = F_49 ( V_117 , V_135 -> V_30 , V_136 ) ;
if ( V_126 != 0 )
goto V_179;
V_75 = F_31 ( V_117 , V_135 -> V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 ) {
V_126 = - V_115 ;
goto V_181;
}
if ( V_75 -> V_182 && ( V_126 = V_75 -> V_182 ( V_136 , V_135 -> V_139 ) ) )
goto V_183;
if ( V_135 -> V_177 && V_135 -> V_177 != V_75 -> V_83 -> V_69 ) {
F_23 ( L_30 ) ;
V_126 = - V_128 ;
goto V_183;
}
V_68 = V_75 -> V_83 ;
if ( ! V_68 -> V_69 && V_136 -> V_69 && ! F_56 ( V_75 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_183;
} else if ( V_68 -> V_69 && ! V_136 -> V_69 )
F_37 ( V_75 -> V_130 ) ;
F_57 ( & V_75 -> V_88 ) ;
if ( V_135 -> V_177 )
F_54 ( V_75 -> V_83 -> V_89 , V_176 ,
V_75 -> V_83 -> V_69 ) ;
V_75 -> V_83 = V_136 ;
F_58 ( & V_75 -> V_88 ) ;
F_28 ( & V_180 ) ;
if ( V_135 -> V_177 &&
F_4 ( V_135 -> V_89 , V_176 ,
V_135 -> V_177 * sizeof( struct V_71 ) ) ) {
F_59 ( L_31 ) ;
}
F_50 ( V_68 -> V_93 , V_68 -> V_138 ,
F_46 , V_117 , NULL ) ;
F_53 ( V_68 -> V_93 ) ;
if ( V_68 -> V_90 ) {
F_52 (i)
F_53 ( V_68 -> V_90 [ V_28 ] ) ;
F_53 ( V_68 -> V_90 ) ;
}
F_53 ( V_68 ) ;
F_53 ( V_176 ) ;
#ifdef F_60
if ( V_184 ) {
struct V_185 * V_186 ;
V_186 = F_61 ( V_187 -> V_188 , V_189 ,
V_190 ) ;
if ( V_186 ) {
F_62 ( V_186 , L_32 ,
V_135 -> V_30 , V_191 , V_135 -> V_69 ) ;
F_63 ( V_186 ) ;
}
}
#endif
return V_126 ;
V_183:
F_28 ( & V_180 ) ;
V_181:
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_46 , V_117 , NULL ) ;
V_179:
F_53 ( V_176 ) ;
if ( V_136 -> V_90 ) {
F_52 (i)
F_53 ( V_136 -> V_90 [ V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
}
return V_126 ;
}
static int F_64 ( struct V_117 * V_117 , const void T_1 * V_192 ,
unsigned int V_98 )
{
int V_126 , V_193 ;
struct V_82 * V_136 ;
struct V_134 V_194 ;
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) != 0 )
return - V_7 ;
if ( V_98 != sizeof( V_194 ) + V_194 . V_138 ) {
F_23 ( L_33 ) ;
return - V_128 ;
}
if ( V_194 . V_138 == 0 ) {
F_23 ( L_34 ) ;
return - V_128 ;
}
if ( V_194 . V_69 >= ( ( V_195 - sizeof( struct V_82 ) ) /
V_196 - V_197 ) / sizeof( struct V_71 ) )
return - V_173 ;
if ( V_194 . V_177 >= V_195 / sizeof( struct V_71 ) )
return - V_173 ;
V_194 . V_30 [ sizeof( V_194 . V_30 ) - 1 ] = 0 ;
V_193 = F_66 ( V_194 . V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_193 ) ;
if ( ! V_136 )
return - V_173 ;
if ( V_193 )
memset ( V_136 -> V_89 , 0 , V_193 ) ;
V_136 -> V_93 = F_51 ( V_194 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_173 ;
goto V_198;
}
if ( F_65 (
V_136 -> V_93 , V_194 . V_93 , V_194 . V_138 ) != 0 ) {
F_23 ( L_35 ) ;
V_126 = - V_7 ;
goto V_199;
}
V_126 = F_55 ( V_117 , & V_194 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_199:
F_53 ( V_136 -> V_93 ) ;
V_198:
F_53 ( V_136 ) ;
return V_126 ;
}
struct V_67 *
F_67 ( struct V_117 * V_117 , const struct V_67 * V_200 )
{
struct V_82 * V_136 ;
struct V_67 * V_75 , * V_68 ;
struct V_201 * V_135 ;
int V_126 , V_28 , V_193 ;
void * V_38 ;
if ( V_200 == NULL || ( V_135 = V_200 -> V_68 ) == NULL ||
V_135 -> V_93 == NULL || V_135 -> V_138 == 0 ||
V_135 -> V_89 != NULL || V_200 -> V_83 != NULL ) {
F_23 ( L_36 ) ;
return F_68 ( - V_128 ) ;
}
V_68 = F_69 ( V_200 , sizeof( struct V_67 ) , V_189 ) ;
if ( ! V_68 ) {
V_126 = - V_173 ;
goto V_34;
}
V_193 = F_66 ( V_135 -> V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_193 ) ;
V_126 = - V_173 ;
if ( ! V_136 )
goto V_202;
V_38 = F_51 ( V_135 -> V_138 ) ;
if ( ! V_38 )
goto V_198;
memcpy ( V_38 , V_135 -> V_93 , V_135 -> V_138 ) ;
V_136 -> V_93 = V_38 ;
V_136 -> V_138 = V_135 -> V_138 ;
V_136 -> V_69 = V_135 -> V_69 ;
if ( V_193 )
memset ( V_136 -> V_89 , 0 , V_193 ) ;
V_136 -> V_90 = NULL ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ( V_135 -> V_139 & ( 1 << V_28 ) ) == 0 )
V_136 -> V_91 [ V_28 ] = NULL ;
else
V_136 -> V_91 [ V_28 ] = V_38 +
( ( char * ) V_135 -> V_91 [ V_28 ] - V_135 -> V_93 ) ;
}
V_126 = F_49 ( V_117 , V_135 -> V_30 , V_136 ) ;
if ( V_126 != 0 ) {
F_23 ( L_37 ) ;
goto V_203;
}
if ( V_68 -> V_182 && V_68 -> V_182 ( V_136 , V_68 -> V_139 ) ) {
F_23 ( L_38 ) ;
V_126 = - V_128 ;
goto V_203;
}
V_68 -> V_83 = V_136 ;
F_70 ( & V_68 -> V_88 ) ;
F_26 ( & V_180 ) ;
F_27 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_75 -> V_30 , V_68 -> V_30 ) == 0 ) {
V_126 = - V_204 ;
F_23 ( L_39 ) ;
goto V_183;
}
}
if ( V_136 -> V_69 && ! F_56 ( V_68 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_183;
}
F_71 ( & V_68 -> V_113 , & V_117 -> V_118 . V_119 [ V_5 ] ) ;
F_28 ( & V_180 ) ;
return V_68 ;
V_183:
F_28 ( & V_180 ) ;
V_203:
if ( V_136 -> V_90 ) {
F_52 (i)
F_53 ( V_136 -> V_90 [ V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
}
F_53 ( V_136 -> V_93 ) ;
V_198:
F_53 ( V_136 ) ;
V_202:
F_72 ( V_68 ) ;
V_34:
return F_68 ( V_126 ) ;
}
void F_73 ( struct V_117 * V_117 , struct V_67 * V_68 )
{
int V_28 ;
if ( ! V_68 ) {
F_23 ( L_40 ) ;
return;
}
F_26 ( & V_180 ) ;
F_74 ( & V_68 -> V_113 ) ;
F_28 ( & V_180 ) ;
F_50 ( V_68 -> V_83 -> V_93 , V_68 -> V_83 -> V_138 ,
F_46 , V_117 , NULL ) ;
if ( V_68 -> V_83 -> V_69 )
F_37 ( V_68 -> V_130 ) ;
F_53 ( V_68 -> V_83 -> V_93 ) ;
if ( V_68 -> V_83 -> V_90 ) {
F_52 (i)
F_53 ( V_68 -> V_83 -> V_90 [ V_28 ] ) ;
F_53 ( V_68 -> V_83 -> V_90 ) ;
}
F_53 ( V_68 -> V_83 ) ;
F_72 ( V_68 ) ;
}
static int F_75 ( struct V_117 * V_117 , const char * V_30 ,
struct V_71 T_1 * V_89 ,
unsigned int V_177 ,
const void T_1 * V_192 , unsigned int V_98 )
{
int V_28 , V_126 ;
struct V_71 * V_194 ;
struct V_67 * V_75 ;
if ( V_177 == 0 )
return - V_128 ;
V_194 = F_51 ( V_177 * sizeof( * V_194 ) ) ;
if ( ! V_194 )
return - V_173 ;
V_75 = F_31 ( V_117 , V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
goto V_205;
if ( V_177 != V_75 -> V_83 -> V_69 ) {
F_23 ( L_41 ) ;
V_126 = - V_128 ;
goto V_206;
}
if ( F_65 ( V_194 , V_89 , V_177 * sizeof( * V_89 ) ) ) {
V_126 = - V_7 ;
goto V_206;
}
F_57 ( & V_75 -> V_88 ) ;
for ( V_28 = 0 ; V_28 < V_177 ; V_28 ++ ) {
V_75 -> V_83 -> V_89 [ V_28 ] . V_96 += V_194 [ V_28 ] . V_96 ;
V_75 -> V_83 -> V_89 [ V_28 ] . V_97 += V_194 [ V_28 ] . V_97 ;
}
F_58 ( & V_75 -> V_88 ) ;
V_126 = 0 ;
V_206:
F_28 ( & V_180 ) ;
V_205:
F_53 ( V_194 ) ;
return V_126 ;
}
static int F_76 ( struct V_117 * V_117 , const void T_1 * V_192 ,
unsigned int V_98 )
{
struct V_134 V_207 ;
if ( F_65 ( & V_207 , V_192 , sizeof( V_207 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_207 ) + V_207 . V_177 * sizeof( struct V_71 ) )
return - V_128 ;
return F_75 ( V_117 , V_207 . V_30 , V_207 . V_89 ,
V_207 . V_177 , V_192 , V_98 ) ;
}
static inline int F_77 ( const struct V_19 * V_20 ,
const char * V_81 , char T_1 * V_208 )
{
char T_1 * V_207 = V_208 + ( ( char * ) V_20 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
F_78 ( V_30 , V_20 -> V_15 . V_21 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_207 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int F_79 ( const struct V_8 * V_9 ,
const char * V_81 , char T_1 * V_208 )
{
char T_1 * V_207 = V_208 + ( ( char * ) V_9 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
F_78 ( V_30 , V_9 -> V_15 . V_16 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_207 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int
F_80 ( struct V_31 * V_32 , const char * V_81 , char T_1 * V_208 )
{
int V_126 ;
char T_1 * V_207 ;
const struct V_74 * V_75 ;
char V_30 [ V_114 ] = {} ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_207 = V_208 + ( ( ( char * ) V_32 + V_32 -> V_99 ) - V_81 ) ;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_126 = F_19 ( V_32 , F_77 , V_81 , V_208 ) ;
if ( V_126 != 0 )
return V_126 ;
V_126 = F_21 ( V_32 , F_79 , V_81 , V_208 ) ;
if ( V_126 != 0 )
return V_126 ;
F_78 ( V_30 , V_75 -> V_15 . V_14 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_207 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static int F_81 ( struct V_67 * V_75 ,
const struct V_71 * V_174 ,
void T_1 * V_192 , unsigned int V_177 ,
unsigned int V_69 )
{
struct V_71 * V_176 ;
int V_126 = 0 ;
if ( V_177 == 0 )
return 0 ;
if ( V_177 != V_69 ) {
F_23 ( L_42 ) ;
return - V_128 ;
}
V_176 = F_51 ( V_69 * sizeof( * V_176 ) ) ;
if ( ! V_176 )
return - V_173 ;
F_57 ( & V_75 -> V_88 ) ;
F_54 ( V_174 , V_176 , V_69 ) ;
F_58 ( & V_75 -> V_88 ) ;
if ( F_4 ( V_192 , V_176 ,
V_69 * sizeof( struct V_71 ) ) )
V_126 = - V_7 ;
F_53 ( V_176 ) ;
return V_126 ;
}
static int F_82 ( struct V_67 * V_75 , void T_1 * V_192 ,
const int * V_98 , int V_209 )
{
struct V_134 V_194 ;
const struct V_71 * V_174 ;
unsigned int V_138 , V_69 ;
int V_126 ;
char * V_93 ;
if ( V_209 == V_210 ) {
V_138 = V_75 -> V_83 -> V_138 ;
V_69 = V_75 -> V_83 -> V_69 ;
V_93 = V_75 -> V_83 -> V_93 ;
V_174 = V_75 -> V_83 -> V_89 ;
} else {
V_138 = V_75 -> V_68 -> V_138 ;
V_69 = V_75 -> V_68 -> V_69 ;
V_93 = V_75 -> V_68 -> V_93 ;
V_174 = V_75 -> V_68 -> V_89 ;
}
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( * V_98 != sizeof( struct V_134 ) + V_138 +
( V_194 . V_177 ? V_69 * sizeof( struct V_71 ) : 0 ) )
return - V_128 ;
if ( V_194 . V_69 != V_69 ) {
F_23 ( L_43 ) ;
return - V_128 ;
}
if ( V_194 . V_138 != V_138 ) {
F_23 ( L_44 ) ;
return - V_128 ;
}
V_126 = F_81 ( V_75 , V_174 , V_194 . V_89 ,
V_194 . V_177 , V_69 ) ;
if ( V_126 )
return V_126 ;
if ( F_4 ( V_194 . V_93 , V_93 , V_138 ) ) {
F_23 ( L_45 ) ;
return - V_7 ;
}
return F_50 ( V_93 , V_138 ,
F_80 , V_93 , V_194 . V_93 ) ;
}
static int F_83 ( struct V_211 * V_212 ,
int V_209 , void T_1 * V_192 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_84 ( V_212 ) ;
if ( ! F_85 ( V_117 -> V_213 , V_214 ) )
return - V_215 ;
switch ( V_209 ) {
case V_216 :
V_126 = F_64 ( V_117 , V_192 , V_98 ) ;
break;
case V_217 :
V_126 = F_76 ( V_117 , V_192 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_86 ( struct V_211 * V_212 , int V_209 , void T_1 * V_192 , int * V_98 )
{
int V_126 ;
struct V_134 V_194 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_84 ( V_212 ) ;
if ( ! F_85 ( V_117 -> V_213 , V_214 ) )
return - V_215 ;
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_194 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
return V_126 ;
switch ( V_209 ) {
case V_218 :
case V_219 :
if ( * V_98 != sizeof( struct V_134 ) ) {
V_126 = - V_128 ;
F_28 ( & V_180 ) ;
break;
}
if ( V_209 == V_218 ) {
V_194 . V_69 = V_75 -> V_83 -> V_69 ;
V_194 . V_138 = V_75 -> V_83 -> V_138 ;
V_194 . V_139 = V_75 -> V_139 ;
} else {
V_194 . V_69 = V_75 -> V_68 -> V_69 ;
V_194 . V_138 = V_75 -> V_68 -> V_138 ;
V_194 . V_139 = V_75 -> V_68 -> V_139 ;
}
F_28 ( & V_180 ) ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
F_23 ( L_46 ) ;
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_210 :
case V_220 :
V_126 = F_82 ( V_75 , V_192 , V_98 , V_209 ) ;
F_28 ( & V_180 ) ;
break;
default:
F_28 ( & V_180 ) ;
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_87 ( void )
{
F_88 ( F_89 ( sizeof( struct V_19 ) ) <
F_90 ( sizeof( struct V_221 ) ) ) ;
return ( int ) F_89 ( sizeof( struct V_19 ) ) -
F_90 ( sizeof( struct V_221 ) ) ;
}
static int F_91 ( const struct V_123 * V_21 ,
unsigned int V_222 )
{
if ( F_92 ( V_21 -> V_223 == - 1 ) )
return F_89 ( V_222 ) - F_90 ( V_222 ) ;
return F_93 ( V_21 ) ;
}
static int F_94 ( struct V_19 * V_20 , void T_1 * * V_224 ,
unsigned int * V_178 )
{
const struct V_123 * V_21 = V_20 -> V_15 . V_21 ;
struct V_221 T_1 * V_225 = * V_224 ;
int V_226 = F_91 ( V_21 , V_20 -> V_127 ) ;
T_4 V_227 = V_20 -> V_127 - V_226 ;
F_95 ( V_226 >= V_20 -> V_127 ) ;
if ( F_4 ( V_225 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_96 ( V_227 , & V_225 -> V_127 ) )
return - V_7 ;
if ( V_21 -> V_228 ) {
if ( V_21 -> V_228 ( V_225 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_225 -> V_18 , V_20 -> V_18 , V_227 ) )
return - V_7 ;
* V_178 -= F_87 () + V_226 ;
* V_224 = V_225 -> V_18 ;
* V_224 += V_227 ;
return 0 ;
}
static int F_97 ( struct V_74 * V_75 ,
void T_1 * * V_224 ,
unsigned int * V_178 )
{
const struct V_132 * V_14 = V_75 -> V_15 . V_14 ;
struct V_221 T_1 * V_225 = * V_224 ;
int V_226 = F_98 ( V_14 ) ;
T_4 V_229 = V_75 -> V_163 - V_226 ;
F_95 ( V_226 >= V_75 -> V_163 ) ;
if ( F_4 ( V_225 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_96 ( V_229 , & V_225 -> V_127 ) )
return - V_7 ;
if ( V_14 -> V_228 ) {
if ( V_14 -> V_228 ( V_225 -> V_18 , V_75 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_225 -> V_18 , V_75 -> V_18 , V_229 ) )
return - V_7 ;
* V_178 -= F_87 () + V_226 ;
* V_224 = V_225 -> V_18 ;
* V_224 += V_229 ;
return 0 ;
}
static int F_99 ( struct V_8 * V_9 ,
void T_1 * * V_224 ,
unsigned int * V_178 )
{
return F_97 ( (struct V_74 * ) V_9 ,
V_224 , V_178 ) ;
}
static int F_100 ( struct V_31 * V_32 , void T_1 * * V_224 ,
unsigned int * V_178 )
{
struct V_74 * V_75 ;
struct V_31 T_1 * V_230 ;
T_5 V_125 , V_99 , V_143 ;
T_4 V_231 ;
int V_126 ;
if ( V_32 -> V_43 == 0 ) {
if ( * V_178 < sizeof( struct V_79 ) )
return - V_128 ;
if ( F_4 ( * V_224 , V_32 , sizeof( struct V_79 ) ) )
return - V_7 ;
* V_224 += sizeof( struct V_79 ) ;
* V_178 -= sizeof( struct V_79 ) ;
return 0 ;
}
if ( * V_178 < sizeof( * V_230 ) )
return - V_128 ;
V_230 = (struct V_31 T_1 * ) * V_224 ;
if ( F_4 ( V_230 , V_32 , sizeof( * V_230 ) ) )
return - V_7 ;
V_231 = * V_178 ;
* V_224 += sizeof( * V_230 ) ;
V_126 = F_19 ( V_32 , F_94 , V_224 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_125 = V_32 -> V_125 - ( V_231 - * V_178 ) ;
V_126 = F_21 ( V_32 , F_99 , V_224 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_99 = V_32 -> V_99 - ( V_231 - * V_178 ) ;
V_75 = (struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_126 = F_97 ( V_75 , V_224 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_143 = V_32 -> V_143 - ( V_231 - * V_178 ) ;
if ( F_96 ( V_125 , & V_230 -> V_125 ) ||
F_96 ( V_99 , & V_230 -> V_99 ) ||
F_96 ( V_143 , & V_230 -> V_143 ) )
return - V_7 ;
* V_178 -= sizeof( * V_230 ) ;
return 0 ;
}
static int F_101 ( struct V_19 * V_20 , int * V_226 )
{
* V_226 += F_91 ( V_20 -> V_15 . V_21 , V_20 -> V_127 ) ;
* V_226 += F_87 () ;
return 0 ;
}
static int F_102 ( struct V_8 * V_9 , int * V_226 )
{
* V_226 += F_98 ( V_9 -> V_15 . V_16 ) ;
* V_226 += F_87 () ;
return 0 ;
}
static int F_103 ( const struct V_31 * V_32 ,
const struct V_82 * V_232 ,
const void * V_81 ,
struct V_233 * V_136 )
{
const struct V_74 * V_75 ;
unsigned int V_234 ;
int V_226 , V_126 , V_28 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_226 = 0 ;
V_234 = ( void * ) V_32 - V_81 ;
F_19 ( V_32 , F_101 , & V_226 ) ;
F_21 ( V_32 , F_102 , & V_226 ) ;
V_75 = ( const struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_226 += F_98 ( V_75 -> V_15 . V_14 ) ;
V_226 += F_87 () ;
V_136 -> V_138 -= V_226 ;
V_126 = F_104 ( V_5 , V_234 , V_226 ) ;
if ( V_126 )
return V_126 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
const void * V_235 = V_232 -> V_91 [ V_28 ] ;
if ( V_232 -> V_91 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_81 - V_235 ) ) ) {
V_136 -> V_91 [ V_28 ] -= V_226 ;
F_105 ( L_47 ,
V_136 -> V_91 [ V_28 ] + V_226 ,
V_136 -> V_91 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_106 ( const struct V_82 * V_232 ,
struct V_233 * V_136 )
{
unsigned int V_178 = V_232 -> V_138 ;
const void * V_93 = V_232 -> V_93 ;
V_136 -> V_138 = V_178 ;
F_107 ( V_5 , V_232 -> V_69 ) ;
return F_50 ( V_93 , V_178 , F_103 , V_232 ,
V_93 , V_136 ) ;
}
static int F_108 ( struct V_67 * V_75 ,
void T_1 * V_192 , int * V_98 , int V_209 )
{
struct V_233 V_135 , V_194 ;
struct V_71 * V_174 ;
struct V_82 V_236 ;
int V_126 ;
void T_1 * V_167 ;
memset ( & V_236 , 0 , sizeof( V_236 ) ) ;
if ( V_209 == V_210 ) {
V_236 . V_138 = V_75 -> V_83 -> V_138 ;
V_236 . V_69 = V_75 -> V_83 -> V_69 ;
V_236 . V_93 = V_75 -> V_83 -> V_93 ;
V_174 = V_75 -> V_83 -> V_89 ;
} else {
V_236 . V_138 = V_75 -> V_68 -> V_138 ;
V_236 . V_69 = V_75 -> V_68 -> V_69 ;
V_236 . V_93 = V_75 -> V_68 -> V_93 ;
V_174 = V_75 -> V_68 -> V_89 ;
}
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( V_194 . V_69 != V_236 . V_69 ||
( V_194 . V_177 && V_194 . V_177 != V_236 . V_69 ) )
return - V_128 ;
memcpy ( & V_135 , & V_194 , sizeof( V_135 ) ) ;
if ( V_209 == V_210 )
V_126 = F_106 ( V_75 -> V_83 , & V_135 ) ;
else
V_126 = F_106 ( & V_236 , & V_135 ) ;
if ( V_126 )
return V_126 ;
if ( * V_98 != sizeof( V_194 ) + V_135 . V_138 +
( V_194 . V_177 ? V_236 . V_69 * sizeof( struct V_71 ) : 0 ) ) {
F_109 ( L_48 ,
* V_98 , V_236 . V_138 , V_135 . V_138 ) ;
return - V_128 ;
}
V_126 = F_81 ( V_75 , V_174 , F_110 ( V_194 . V_89 ) ,
V_194 . V_177 , V_236 . V_69 ) ;
if ( V_126 )
return V_126 ;
V_167 = F_110 ( V_194 . V_93 ) ;
return F_50 ( V_236 . V_93 , V_236 . V_138 ,
F_100 , & V_167 , & V_194 . V_138 ) ;
}
static int F_111 ( struct V_237 * V_238 , unsigned int V_239 )
{
V_238 -> V_240 += V_239 ;
return V_238 -> V_240 >= V_239 ? 0 : - V_128 ;
}
static int F_112 ( struct V_237 * V_238 ,
void * V_18 , unsigned int V_239 )
{
if ( V_238 -> V_241 == NULL )
goto V_242;
F_95 ( V_238 -> V_240 + V_239 > V_238 -> V_243 ) ;
memcpy ( V_238 -> V_241 + V_238 -> V_240 , V_18 , V_239 ) ;
V_242:
V_238 -> V_244 += V_239 ;
return F_111 ( V_238 , V_239 ) ;
}
static int F_113 ( struct V_237 * V_238 , unsigned int V_239 )
{
char * V_245 = V_238 -> V_241 ;
F_95 ( V_245 && V_238 -> V_240 > V_238 -> V_243 ) ;
if ( V_245 != NULL && V_239 > 0 )
memset ( V_245 + V_238 -> V_240 , 0 , V_239 ) ;
return F_111 ( V_238 , V_239 ) ;
}
static int F_114 ( struct V_221 * V_246 ,
enum V_247 V_247 ,
struct V_237 * V_238 ,
const unsigned char * V_81 )
{
char V_30 [ V_114 ] ;
struct V_123 * V_21 ;
struct V_132 * V_248 ;
void * V_1 = NULL ;
int V_226 , V_249 = 0 ;
unsigned int V_250 , V_127 = V_246 -> V_127 ;
F_78 ( V_30 , V_246 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_238 -> V_241 )
V_1 = V_238 -> V_241 + V_238 -> V_240 ;
switch ( V_247 ) {
case V_251 :
V_21 = F_33 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_226 = F_91 ( V_21 , V_127 ) ;
if ( V_1 ) {
if ( V_21 -> V_252 )
V_21 -> V_252 ( V_1 , V_246 -> V_18 ) ;
else
memcpy ( V_1 , V_246 -> V_18 , V_127 ) ;
}
V_250 = V_21 -> V_223 ;
if ( F_92 ( V_250 == - 1 ) )
V_250 = V_127 ;
F_37 ( V_21 -> V_130 ) ;
break;
case V_253 :
case V_254 :
V_248 = F_39 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_248 ) )
return F_35 ( V_248 ) ;
V_226 = F_98 ( V_248 ) ;
if ( V_1 ) {
if ( V_248 -> V_252 )
V_248 -> V_252 ( V_1 , V_246 -> V_18 ) ;
else
memcpy ( V_1 , V_246 -> V_18 , V_127 ) ;
}
V_250 = V_248 -> V_255 ;
F_37 ( V_248 -> V_130 ) ;
break;
default:
return - V_128 ;
}
V_238 -> V_240 += V_127 + V_226 ;
V_238 -> V_244 += V_127 ;
V_249 = F_89 ( V_250 ) - V_250 ;
if ( V_249 > 0 && V_1 ) {
F_95 ( V_238 -> V_243 <= V_249 ) ;
F_95 ( V_238 -> V_240 - ( V_127 + V_226 ) + V_250 > V_238 -> V_243 - V_249 ) ;
memset ( V_1 + V_250 , 0 , V_249 ) ;
}
return V_226 + V_127 ;
}
static int F_115 ( struct V_221 * V_256 ,
unsigned int V_257 , enum V_247 type ,
struct V_237 * V_238 , const void * V_81 )
{
int V_258 = 0 ;
char * V_259 ;
if ( V_257 == 0 )
return 0 ;
V_259 = ( char * ) V_256 ;
while ( V_257 >= sizeof( * V_256 ) ) {
struct V_19 * V_260 ;
int V_126 ;
V_260 = (struct V_19 * ) V_238 -> V_241 ;
if ( V_260 ) {
char * V_194 ;
V_194 = V_238 -> V_241 + V_238 -> V_240 ;
V_260 = (struct V_19 * ) V_194 ;
}
V_126 = F_112 ( V_238 , V_259 , sizeof( * V_256 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_257 -= sizeof( * V_256 ) ;
V_126 = F_113 ( V_238 , F_87 () ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_256 -> V_127 > V_257 )
return - V_128 ;
V_257 -= V_256 -> V_127 ;
V_126 = F_114 ( V_256 , type , V_238 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
F_95 ( V_126 < V_256 -> V_127 ) ;
V_258 += V_126 - V_256 -> V_127 ;
V_258 += F_87 () ;
V_259 += sizeof( * V_256 ) ;
V_259 += V_256 -> V_127 ;
if ( V_260 )
V_260 -> V_127 = V_126 ;
F_116 ( type == V_254 && V_257 ) ;
V_256 = (struct V_221 * ) V_259 ;
}
return V_258 ;
}
static int F_117 ( struct V_31 * V_25 , const unsigned char * V_81 ,
unsigned int * V_261 ,
struct V_237 * V_238 )
{
unsigned int V_28 , V_153 , V_262 , V_263 = 0 ;
unsigned int V_264 [ 4 ] ;
unsigned int * V_265 = NULL ;
int V_126 ;
char * V_266 ;
if ( * V_261 < sizeof( struct V_79 ) )
return - V_128 ;
if ( ! V_25 -> V_43 ) {
* V_261 -= sizeof( struct V_79 ) ;
return F_112 ( V_238 , V_25 , sizeof( struct V_79 ) ) ;
}
if ( * V_261 < sizeof( * V_25 ) || V_25 -> V_143 < sizeof( * V_25 ) )
return - V_128 ;
V_262 = V_238 -> V_244 ;
V_126 = F_112 ( V_238 , V_25 ,
F_118 ( struct V_31 , V_125 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_264 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_264 [ 1 ] , & V_25 -> V_125 ,
sizeof( V_264 ) - sizeof( V_264 [ 0 ] ) ) ;
if ( V_238 -> V_241 ) {
V_266 = V_238 -> V_241 + V_238 -> V_240 ;
V_265 = ( unsigned int * ) V_266 ;
}
V_126 = F_112 ( V_238 , & V_264 [ 1 ] ,
sizeof( V_264 ) - sizeof( V_264 [ 0 ] ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_266 = ( char * ) V_25 ;
for ( V_28 = 0 , V_153 = 1 ; V_153 < 4 ; V_153 ++ , V_28 ++ ) {
struct V_221 * V_256 ;
unsigned int V_178 ;
char * V_259 = V_266 ;
V_259 = V_266 + V_264 [ V_28 ] ;
if ( V_264 [ V_28 ] > V_264 [ V_153 ] )
return - V_128 ;
V_256 = (struct V_221 * ) V_259 ;
V_178 = V_264 [ V_153 ] - V_264 [ V_28 ] ;
V_126 = F_115 ( V_256 , V_178 , V_28 , V_238 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
V_263 += V_126 ;
if ( V_265 && V_263 ) {
F_105 ( L_49 ,
V_265 [ V_28 ] , V_264 [ V_153 ] + V_263 ) ;
V_265 [ V_28 ] = V_264 [ V_153 ] + V_263 ;
}
}
if ( V_238 -> V_241 == NULL ) {
unsigned int V_140 = V_266 - ( char * ) V_81 ;
V_126 = F_104 ( V_5 , V_140 , V_263 ) ;
if ( V_126 < 0 )
return V_126 ;
}
V_262 = V_238 -> V_244 - V_262 ;
F_95 ( * V_261 < V_262 ) ;
* V_261 -= V_262 ;
return 0 ;
}
static int F_119 ( unsigned char * V_18 , unsigned int V_267 ,
struct V_237 * V_238 )
{
unsigned int V_268 = V_267 ;
int V_126 ;
V_126 = F_50 ( V_18 , V_267 , F_117 , V_18 ,
& V_268 , V_238 ) ;
if ( V_126 < 0 )
return V_126 ;
F_116 ( V_268 ) ;
return V_238 -> V_240 ;
}
static int F_120 ( struct V_134 * V_135 ,
void T_1 * V_192 , unsigned int V_98 )
{
struct V_233 V_194 ;
int V_28 ;
if ( V_98 < sizeof( V_194 ) )
return - V_128 ;
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_194 ) + V_194 . V_138 )
return - V_128 ;
if ( V_194 . V_138 == 0 )
return - V_128 ;
if ( V_194 . V_69 >= ( ( V_195 - sizeof( struct V_82 ) ) /
V_196 - V_197 ) / sizeof( struct V_71 ) )
return - V_173 ;
if ( V_194 . V_177 >= V_195 / sizeof( struct V_71 ) )
return - V_173 ;
memcpy ( V_135 , & V_194 , F_118 ( struct V_134 , V_91 ) ) ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
V_135 -> V_91 [ V_28 ] = F_110 ( V_194 . V_91 [ V_28 ] ) ;
V_135 -> V_177 = V_194 . V_177 ;
V_135 -> V_89 = F_110 ( V_194 . V_89 ) ;
V_135 -> V_93 = F_110 ( V_194 . V_93 ) ;
return 0 ;
}
static int F_121 ( struct V_117 * V_117 , void T_1 * V_192 ,
unsigned int V_98 )
{
int V_126 , V_28 , V_193 , V_269 ;
struct V_82 * V_136 ;
struct V_134 V_194 ;
struct V_237 V_238 ;
void * V_270 ;
V_126 = F_120 ( & V_194 , V_192 , V_98 ) ;
if ( V_126 ) {
if ( V_126 == - V_128 && F_64 ( V_117 , V_192 , V_98 ) == 0 )
V_126 = 0 ;
return V_126 ;
}
V_193 = F_66 ( V_194 . V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_193 ) ;
if ( ! V_136 )
return - V_173 ;
if ( V_193 )
memset ( V_136 -> V_89 , 0 , V_193 ) ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_136 -> V_93 = F_51 ( V_194 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_173 ;
goto V_198;
}
if ( F_65 (
V_136 -> V_93 , V_194 . V_93 , V_194 . V_138 ) != 0 ) {
V_126 = - V_7 ;
goto V_199;
}
V_270 = V_136 -> V_93 ;
F_122 ( V_5 ) ;
F_107 ( V_5 , V_194 . V_69 ) ;
V_126 = F_119 ( V_270 , V_194 . V_138 , & V_238 ) ;
if ( V_126 < 0 )
goto V_271;
F_105 ( L_50 ,
V_194 . V_138 , V_238 . V_240 , V_238 . V_244 ,
F_2 ( V_5 , V_194 . V_138 ) ) ;
V_269 = V_126 ;
V_136 -> V_93 = F_51 ( V_269 ) ;
if ( ! V_136 -> V_93 ) {
F_53 ( V_270 ) ;
V_126 = - V_173 ;
goto V_271;
}
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_241 = V_136 -> V_93 ;
V_238 . V_243 = V_269 ;
V_126 = F_119 ( V_270 , V_194 . V_138 , & V_238 ) ;
F_95 ( V_126 < 0 ) ;
F_53 ( V_270 ) ;
V_194 . V_138 = V_269 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
char T_1 * V_272 ;
if ( V_194 . V_91 [ V_28 ] ) {
unsigned int V_273 ;
V_272 = ( char T_1 * ) V_194 . V_91 [ V_28 ] ;
V_273 = V_272 - V_194 . V_93 ;
V_272 += F_2 ( V_5 , V_273 ) ;
V_194 . V_91 [ V_28 ] = (struct V_79 T_1 * ) V_272 ;
}
}
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
V_126 = F_55 ( V_117 , & V_194 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_199:
F_53 ( V_136 -> V_93 ) ;
V_198:
F_53 ( V_136 ) ;
return V_126 ;
V_271:
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
goto V_199;
}
static int F_125 ( struct V_117 * V_117 , void T_1 * V_192 ,
unsigned int V_98 )
{
struct V_233 V_207 ;
if ( F_65 ( & V_207 , V_192 , sizeof( V_207 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_207 ) + V_207 . V_177 * sizeof( struct V_71 ) )
return F_76 ( V_117 , V_192 , V_98 ) ;
return F_75 ( V_117 , V_207 . V_30 , F_110 ( V_207 . V_89 ) ,
V_207 . V_177 , V_192 , V_98 ) ;
}
static int F_126 ( struct V_211 * V_212 ,
int V_209 , void T_1 * V_192 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_84 ( V_212 ) ;
if ( ! F_85 ( V_117 -> V_213 , V_214 ) )
return - V_215 ;
switch ( V_209 ) {
case V_216 :
V_126 = F_121 ( V_117 , V_192 , V_98 ) ;
break;
case V_217 :
V_126 = F_125 ( V_117 , V_192 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_127 ( struct V_211 * V_212 , int V_209 ,
void T_1 * V_192 , int * V_98 )
{
int V_126 ;
struct V_233 V_194 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_84 ( V_212 ) ;
if ( ! F_85 ( V_117 -> V_213 , V_214 ) )
return - V_215 ;
if ( ( V_209 == V_218 ||
V_209 == V_219 ) && * V_98 != sizeof( V_194 ) )
return F_86 ( V_212 , V_209 , V_192 , V_98 ) ;
if ( F_65 ( & V_194 , V_192 , sizeof( V_194 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_194 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
return V_126 ;
F_122 ( V_5 ) ;
switch ( V_209 ) {
case V_218 :
V_194 . V_69 = V_75 -> V_83 -> V_69 ;
V_126 = F_106 ( V_75 -> V_83 , & V_194 ) ;
if ( V_126 )
goto V_34;
V_194 . V_139 = V_75 -> V_139 ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_219 :
V_194 . V_69 = V_75 -> V_68 -> V_69 ;
V_194 . V_138 = V_75 -> V_68 -> V_138 ;
V_194 . V_139 = V_75 -> V_68 -> V_139 ;
if ( F_4 ( V_192 , & V_194 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_210 :
case V_220 :
if ( F_82 ( V_75 , V_192 , V_98 , V_209 ) == 0 )
V_126 = 0 ;
else
V_126 = F_108 ( V_75 , V_192 , V_98 , V_209 ) ;
break;
default:
V_126 = - V_128 ;
}
V_34:
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
F_28 ( & V_180 ) ;
return V_126 ;
}
static int T_6 F_128 ( void )
{
int V_126 ;
V_126 = F_129 ( & V_100 ) ;
if ( V_126 < 0 )
return V_126 ;
V_126 = F_130 ( & V_274 ) ;
if ( V_126 < 0 ) {
F_131 ( & V_100 ) ;
return V_126 ;
}
F_132 ( V_275 L_51 ) ;
return 0 ;
}
static void T_7 F_133 ( void )
{
F_134 ( & V_274 ) ;
F_131 ( & V_100 ) ;
F_132 ( V_275 L_52 ) ;
}
