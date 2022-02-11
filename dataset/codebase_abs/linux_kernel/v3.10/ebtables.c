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
return ( V_29 [ V_28 ] != V_25 [ V_28 ] && V_25 [ V_28 ] != 1 ) ;
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
* error = F_26 ( V_112 ) ;
if ( * error != 0 )
return NULL ;
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
V_126 = - V_7 ;
}
else
V_126 = 0 ;
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
static int F_59 ( struct V_117 * V_117 , const void T_1 * V_184 ,
unsigned int V_98 )
{
int V_126 , V_185 ;
struct V_82 * V_136 ;
struct V_134 V_186 ;
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) != 0 )
return - V_7 ;
if ( V_98 != sizeof( V_186 ) + V_186 . V_138 ) {
F_23 ( L_31 ) ;
return - V_128 ;
}
if ( V_186 . V_138 == 0 ) {
F_23 ( L_32 ) ;
return - V_128 ;
}
if ( V_186 . V_69 >= ( ( V_187 - sizeof( struct V_82 ) ) /
V_188 - V_189 ) / sizeof( struct V_71 ) )
return - V_173 ;
if ( V_186 . V_177 >= V_187 / sizeof( struct V_71 ) )
return - V_173 ;
V_186 . V_30 [ sizeof( V_186 . V_30 ) - 1 ] = 0 ;
V_185 = F_61 ( V_186 . V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_185 ) ;
if ( ! V_136 )
return - V_173 ;
if ( V_185 )
memset ( V_136 -> V_89 , 0 , V_185 ) ;
V_136 -> V_93 = F_51 ( V_186 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_173 ;
goto V_190;
}
if ( F_60 (
V_136 -> V_93 , V_186 . V_93 , V_186 . V_138 ) != 0 ) {
F_23 ( L_33 ) ;
V_126 = - V_7 ;
goto V_191;
}
V_126 = F_55 ( V_117 , & V_186 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_191:
F_53 ( V_136 -> V_93 ) ;
V_190:
F_53 ( V_136 ) ;
return V_126 ;
}
struct V_67 *
F_62 ( struct V_117 * V_117 , const struct V_67 * V_192 )
{
struct V_82 * V_136 ;
struct V_67 * V_75 , * V_68 ;
struct V_193 * V_135 ;
int V_126 , V_28 , V_185 ;
void * V_38 ;
if ( V_192 == NULL || ( V_135 = V_192 -> V_68 ) == NULL ||
V_135 -> V_93 == NULL || V_135 -> V_138 == 0 ||
V_135 -> V_89 != NULL || V_192 -> V_83 != NULL ) {
F_23 ( L_34 ) ;
return F_63 ( - V_128 ) ;
}
V_68 = F_64 ( V_192 , sizeof( struct V_67 ) , V_194 ) ;
if ( ! V_68 ) {
V_126 = - V_173 ;
goto V_34;
}
V_185 = F_61 ( V_135 -> V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_185 ) ;
V_126 = - V_173 ;
if ( ! V_136 )
goto V_195;
V_38 = F_51 ( V_135 -> V_138 ) ;
if ( ! V_38 )
goto V_190;
memcpy ( V_38 , V_135 -> V_93 , V_135 -> V_138 ) ;
V_136 -> V_93 = V_38 ;
V_136 -> V_138 = V_135 -> V_138 ;
V_136 -> V_69 = V_135 -> V_69 ;
if ( V_185 )
memset ( V_136 -> V_89 , 0 , V_185 ) ;
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
F_23 ( L_35 ) ;
goto V_196;
}
if ( V_68 -> V_182 && V_68 -> V_182 ( V_136 , V_68 -> V_139 ) ) {
F_23 ( L_36 ) ;
V_126 = - V_128 ;
goto V_196;
}
V_68 -> V_83 = V_136 ;
F_65 ( & V_68 -> V_88 ) ;
V_126 = F_26 ( & V_180 ) ;
if ( V_126 != 0 )
goto V_196;
F_27 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_75 -> V_30 , V_68 -> V_30 ) == 0 ) {
V_126 = - V_197 ;
F_23 ( L_37 ) ;
goto V_183;
}
}
if ( V_136 -> V_69 && ! F_56 ( V_68 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_183;
}
F_66 ( & V_68 -> V_113 , & V_117 -> V_118 . V_119 [ V_5 ] ) ;
F_28 ( & V_180 ) ;
return V_68 ;
V_183:
F_28 ( & V_180 ) ;
V_196:
if ( V_136 -> V_90 ) {
F_52 (i)
F_53 ( V_136 -> V_90 [ V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
}
F_53 ( V_136 -> V_93 ) ;
V_190:
F_53 ( V_136 ) ;
V_195:
F_67 ( V_68 ) ;
V_34:
return F_63 ( V_126 ) ;
}
void F_68 ( struct V_117 * V_117 , struct V_67 * V_68 )
{
int V_28 ;
if ( ! V_68 ) {
F_23 ( L_38 ) ;
return;
}
F_69 ( & V_180 ) ;
F_70 ( & V_68 -> V_113 ) ;
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
F_67 ( V_68 ) ;
}
static int F_71 ( struct V_117 * V_117 , const char * V_30 ,
struct V_71 T_1 * V_89 ,
unsigned int V_177 ,
const void T_1 * V_184 , unsigned int V_98 )
{
int V_28 , V_126 ;
struct V_71 * V_186 ;
struct V_67 * V_75 ;
if ( V_177 == 0 )
return - V_128 ;
V_186 = F_51 ( V_177 * sizeof( * V_186 ) ) ;
if ( ! V_186 )
return - V_173 ;
V_75 = F_31 ( V_117 , V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
goto V_198;
if ( V_177 != V_75 -> V_83 -> V_69 ) {
F_23 ( L_39 ) ;
V_126 = - V_128 ;
goto V_199;
}
if ( F_60 ( V_186 , V_89 , V_177 * sizeof( * V_89 ) ) ) {
V_126 = - V_7 ;
goto V_199;
}
F_57 ( & V_75 -> V_88 ) ;
for ( V_28 = 0 ; V_28 < V_177 ; V_28 ++ ) {
V_75 -> V_83 -> V_89 [ V_28 ] . V_96 += V_186 [ V_28 ] . V_96 ;
V_75 -> V_83 -> V_89 [ V_28 ] . V_97 += V_186 [ V_28 ] . V_97 ;
}
F_58 ( & V_75 -> V_88 ) ;
V_126 = 0 ;
V_199:
F_28 ( & V_180 ) ;
V_198:
F_53 ( V_186 ) ;
return V_126 ;
}
static int F_72 ( struct V_117 * V_117 , const void T_1 * V_184 ,
unsigned int V_98 )
{
struct V_134 V_200 ;
if ( F_60 ( & V_200 , V_184 , sizeof( V_200 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_200 ) + V_200 . V_177 * sizeof( struct V_71 ) )
return - V_128 ;
return F_71 ( V_117 , V_200 . V_30 , V_200 . V_89 ,
V_200 . V_177 , V_184 , V_98 ) ;
}
static inline int F_73 ( const struct V_19 * V_20 ,
const char * V_81 , char T_1 * V_201 )
{
char T_1 * V_200 = V_201 + ( ( char * ) V_20 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
strncpy ( V_30 , V_20 -> V_15 . V_21 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_200 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int F_74 ( const struct V_8 * V_9 ,
const char * V_81 , char T_1 * V_201 )
{
char T_1 * V_200 = V_201 + ( ( char * ) V_9 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
strncpy ( V_30 , V_9 -> V_15 . V_16 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_200 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int
F_75 ( struct V_31 * V_32 , const char * V_81 , char T_1 * V_201 )
{
int V_126 ;
char T_1 * V_200 ;
const struct V_74 * V_75 ;
char V_30 [ V_114 ] = {} ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_200 = V_201 + ( ( ( char * ) V_32 + V_32 -> V_99 ) - V_81 ) ;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_126 = F_19 ( V_32 , F_73 , V_81 , V_201 ) ;
if ( V_126 != 0 )
return V_126 ;
V_126 = F_21 ( V_32 , F_74 , V_81 , V_201 ) ;
if ( V_126 != 0 )
return V_126 ;
strncpy ( V_30 , V_75 -> V_15 . V_14 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_200 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static int F_76 ( struct V_67 * V_75 ,
const struct V_71 * V_174 ,
void T_1 * V_184 , unsigned int V_177 ,
unsigned int V_69 )
{
struct V_71 * V_176 ;
int V_126 = 0 ;
if ( V_177 == 0 )
return 0 ;
if ( V_177 != V_69 ) {
F_23 ( L_40 ) ;
return - V_128 ;
}
V_176 = F_51 ( V_69 * sizeof( * V_176 ) ) ;
if ( ! V_176 )
return - V_173 ;
F_57 ( & V_75 -> V_88 ) ;
F_54 ( V_174 , V_176 , V_69 ) ;
F_58 ( & V_75 -> V_88 ) ;
if ( F_4 ( V_184 , V_176 ,
V_69 * sizeof( struct V_71 ) ) )
V_126 = - V_7 ;
F_53 ( V_176 ) ;
return V_126 ;
}
static int F_77 ( struct V_67 * V_75 , void T_1 * V_184 ,
const int * V_98 , int V_202 )
{
struct V_134 V_186 ;
const struct V_71 * V_174 ;
unsigned int V_138 , V_69 ;
int V_126 ;
char * V_93 ;
if ( V_202 == V_203 ) {
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
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_7 ;
if ( * V_98 != sizeof( struct V_134 ) + V_138 +
( V_186 . V_177 ? V_69 * sizeof( struct V_71 ) : 0 ) )
return - V_128 ;
if ( V_186 . V_69 != V_69 ) {
F_23 ( L_41 ) ;
return - V_128 ;
}
if ( V_186 . V_138 != V_138 ) {
F_23 ( L_42 ) ;
return - V_128 ;
}
V_126 = F_76 ( V_75 , V_174 , V_186 . V_89 ,
V_186 . V_177 , V_69 ) ;
if ( V_126 )
return V_126 ;
if ( F_4 ( V_186 . V_93 , V_93 , V_138 ) ) {
F_23 ( L_43 ) ;
return - V_7 ;
}
return F_50 ( V_93 , V_138 ,
F_75 , V_93 , V_186 . V_93 ) ;
}
static int F_78 ( struct V_204 * V_205 ,
int V_202 , void T_1 * V_184 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_79 ( V_205 ) ;
if ( ! F_80 ( V_117 -> V_206 , V_207 ) )
return - V_208 ;
switch( V_202 ) {
case V_209 :
V_126 = F_59 ( V_117 , V_184 , V_98 ) ;
break;
case V_210 :
V_126 = F_72 ( V_117 , V_184 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_81 ( struct V_204 * V_205 , int V_202 , void T_1 * V_184 , int * V_98 )
{
int V_126 ;
struct V_134 V_186 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_79 ( V_205 ) ;
if ( ! F_80 ( V_117 -> V_206 , V_207 ) )
return - V_208 ;
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_186 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
return V_126 ;
switch( V_202 ) {
case V_211 :
case V_212 :
if ( * V_98 != sizeof( struct V_134 ) ) {
V_126 = - V_128 ;
F_28 ( & V_180 ) ;
break;
}
if ( V_202 == V_211 ) {
V_186 . V_69 = V_75 -> V_83 -> V_69 ;
V_186 . V_138 = V_75 -> V_83 -> V_138 ;
V_186 . V_139 = V_75 -> V_139 ;
} else {
V_186 . V_69 = V_75 -> V_68 -> V_69 ;
V_186 . V_138 = V_75 -> V_68 -> V_138 ;
V_186 . V_139 = V_75 -> V_68 -> V_139 ;
}
F_28 ( & V_180 ) ;
if ( F_4 ( V_184 , & V_186 , * V_98 ) != 0 ) {
F_23 ( L_44 ) ;
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_203 :
case V_213 :
V_126 = F_77 ( V_75 , V_184 , V_98 , V_202 ) ;
F_28 ( & V_180 ) ;
break;
default:
F_28 ( & V_180 ) ;
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_82 ( void )
{
F_83 ( F_84 ( sizeof( struct V_19 ) ) <
F_85 ( sizeof( struct V_214 ) ) ) ;
return ( int ) F_84 ( sizeof( struct V_19 ) ) -
F_85 ( sizeof( struct V_214 ) ) ;
}
static int F_86 ( const struct V_123 * V_21 ,
unsigned int V_215 )
{
if ( F_87 ( V_21 -> V_216 == - 1 ) )
return F_84 ( V_215 ) - F_85 ( V_215 ) ;
return F_88 ( V_21 ) ;
}
static int F_89 ( struct V_19 * V_20 , void T_1 * * V_217 ,
unsigned int * V_178 )
{
const struct V_123 * V_21 = V_20 -> V_15 . V_21 ;
struct V_214 T_1 * V_218 = * V_217 ;
int V_219 = F_86 ( V_21 , V_20 -> V_127 ) ;
T_4 V_220 = V_20 -> V_127 - V_219 ;
F_90 ( V_219 >= V_20 -> V_127 ) ;
if ( F_4 ( V_218 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_91 ( V_220 , & V_218 -> V_127 ) )
return - V_7 ;
if ( V_21 -> V_221 ) {
if ( V_21 -> V_221 ( V_218 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_218 -> V_18 , V_20 -> V_18 , V_220 ) )
return - V_7 ;
* V_178 -= F_82 () + V_219 ;
* V_217 = V_218 -> V_18 ;
* V_217 += V_220 ;
return 0 ;
}
static int F_92 ( struct V_74 * V_75 ,
void T_1 * * V_217 ,
unsigned int * V_178 )
{
const struct V_132 * V_14 = V_75 -> V_15 . V_14 ;
struct V_214 T_1 * V_218 = * V_217 ;
int V_219 = F_93 ( V_14 ) ;
T_4 V_222 = V_75 -> V_163 - V_219 ;
F_90 ( V_219 >= V_75 -> V_163 ) ;
if ( F_4 ( V_218 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_91 ( V_222 , & V_218 -> V_127 ) )
return - V_7 ;
if ( V_14 -> V_221 ) {
if ( V_14 -> V_221 ( V_218 -> V_18 , V_75 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_218 -> V_18 , V_75 -> V_18 , V_222 ) )
return - V_7 ;
* V_178 -= F_82 () + V_219 ;
* V_217 = V_218 -> V_18 ;
* V_217 += V_222 ;
return 0 ;
}
static int F_94 ( struct V_8 * V_9 ,
void T_1 * * V_217 ,
unsigned int * V_178 )
{
return F_92 ( (struct V_74 * ) V_9 ,
V_217 , V_178 ) ;
}
static int F_95 ( struct V_31 * V_32 , void T_1 * * V_217 ,
unsigned int * V_178 )
{
struct V_74 * V_75 ;
struct V_31 T_1 * V_223 ;
T_5 V_125 , V_99 , V_143 ;
T_4 V_224 ;
int V_126 ;
if ( V_32 -> V_43 == 0 ) {
if ( * V_178 < sizeof( struct V_79 ) )
return - V_128 ;
if ( F_4 ( * V_217 , V_32 , sizeof( struct V_79 ) ) )
return - V_7 ;
* V_217 += sizeof( struct V_79 ) ;
* V_178 -= sizeof( struct V_79 ) ;
return 0 ;
}
if ( * V_178 < sizeof( * V_223 ) )
return - V_128 ;
V_223 = (struct V_31 T_1 * ) * V_217 ;
if ( F_4 ( V_223 , V_32 , sizeof( * V_223 ) ) )
return - V_7 ;
V_224 = * V_178 ;
* V_217 += sizeof( * V_223 ) ;
V_126 = F_19 ( V_32 , F_89 , V_217 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_125 = V_32 -> V_125 - ( V_224 - * V_178 ) ;
V_126 = F_21 ( V_32 , F_94 , V_217 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_99 = V_32 -> V_99 - ( V_224 - * V_178 ) ;
V_75 = (struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_126 = F_92 ( V_75 , V_217 , V_178 ) ;
if ( V_126 )
return V_126 ;
V_143 = V_32 -> V_143 - ( V_224 - * V_178 ) ;
if ( F_91 ( V_125 , & V_223 -> V_125 ) ||
F_91 ( V_99 , & V_223 -> V_99 ) ||
F_91 ( V_143 , & V_223 -> V_143 ) )
return - V_7 ;
* V_178 -= sizeof( * V_223 ) ;
return 0 ;
}
static int F_96 ( struct V_19 * V_20 , int * V_219 )
{
* V_219 += F_86 ( V_20 -> V_15 . V_21 , V_20 -> V_127 ) ;
* V_219 += F_82 () ;
return 0 ;
}
static int F_97 ( struct V_8 * V_9 , int * V_219 )
{
* V_219 += F_93 ( V_9 -> V_15 . V_16 ) ;
* V_219 += F_82 () ;
return 0 ;
}
static int F_98 ( const struct V_31 * V_32 ,
const struct V_82 * V_225 ,
const void * V_81 ,
struct V_226 * V_136 )
{
const struct V_74 * V_75 ;
unsigned int V_227 ;
int V_219 , V_126 , V_28 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_219 = 0 ;
V_227 = ( void * ) V_32 - V_81 ;
F_19 ( V_32 , F_96 , & V_219 ) ;
F_21 ( V_32 , F_97 , & V_219 ) ;
V_75 = ( const struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_219 += F_93 ( V_75 -> V_15 . V_14 ) ;
V_219 += F_82 () ;
V_136 -> V_138 -= V_219 ;
V_126 = F_99 ( V_5 , V_227 , V_219 ) ;
if ( V_126 )
return V_126 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
const void * V_228 = V_225 -> V_91 [ V_28 ] ;
if ( V_225 -> V_91 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_81 - V_228 ) ) ) {
V_136 -> V_91 [ V_28 ] -= V_219 ;
F_100 ( L_45 ,
V_136 -> V_91 [ V_28 ] + V_219 ,
V_136 -> V_91 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_101 ( const struct V_82 * V_225 ,
struct V_226 * V_136 )
{
unsigned int V_178 = V_225 -> V_138 ;
const void * V_93 = V_225 -> V_93 ;
V_136 -> V_138 = V_178 ;
F_102 ( V_5 , V_225 -> V_69 ) ;
return F_50 ( V_93 , V_178 , F_98 , V_225 ,
V_93 , V_136 ) ;
}
static int F_103 ( struct V_67 * V_75 ,
void T_1 * V_184 , int * V_98 , int V_202 )
{
struct V_226 V_135 , V_186 ;
struct V_71 * V_174 ;
struct V_82 V_229 ;
int V_126 ;
void T_1 * V_167 ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
if ( V_202 == V_203 ) {
V_229 . V_138 = V_75 -> V_83 -> V_138 ;
V_229 . V_69 = V_75 -> V_83 -> V_69 ;
V_229 . V_93 = V_75 -> V_83 -> V_93 ;
V_174 = V_75 -> V_83 -> V_89 ;
} else {
V_229 . V_138 = V_75 -> V_68 -> V_138 ;
V_229 . V_69 = V_75 -> V_68 -> V_69 ;
V_229 . V_93 = V_75 -> V_68 -> V_93 ;
V_174 = V_75 -> V_68 -> V_89 ;
}
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_7 ;
if ( V_186 . V_69 != V_229 . V_69 ||
( V_186 . V_177 && V_186 . V_177 != V_229 . V_69 ) )
return - V_128 ;
memcpy ( & V_135 , & V_186 , sizeof( V_135 ) ) ;
if ( V_202 == V_203 )
V_126 = F_101 ( V_75 -> V_83 , & V_135 ) ;
else
V_126 = F_101 ( & V_229 , & V_135 ) ;
if ( V_126 )
return V_126 ;
if ( * V_98 != sizeof( V_186 ) + V_135 . V_138 +
( V_186 . V_177 ? V_229 . V_69 * sizeof( struct V_71 ) : 0 ) ) {
F_104 ( L_46 ,
* V_98 , V_229 . V_138 , V_135 . V_138 ) ;
return - V_128 ;
}
V_126 = F_76 ( V_75 , V_174 , F_105 ( V_186 . V_89 ) ,
V_186 . V_177 , V_229 . V_69 ) ;
if ( V_126 )
return V_126 ;
V_167 = F_105 ( V_186 . V_93 ) ;
return F_50 ( V_229 . V_93 , V_229 . V_138 ,
F_95 , & V_167 , & V_186 . V_138 ) ;
}
static int F_106 ( struct V_230 * V_231 , unsigned int V_232 )
{
V_231 -> V_233 += V_232 ;
return V_231 -> V_233 >= V_232 ? 0 : - V_128 ;
}
static int F_107 ( struct V_230 * V_231 ,
void * V_18 , unsigned int V_232 )
{
if ( V_231 -> V_234 == NULL )
goto V_235;
F_90 ( V_231 -> V_233 + V_232 > V_231 -> V_236 ) ;
memcpy ( V_231 -> V_234 + V_231 -> V_233 , V_18 , V_232 ) ;
V_235:
V_231 -> V_237 += V_232 ;
return F_106 ( V_231 , V_232 ) ;
}
static int F_108 ( struct V_230 * V_231 , unsigned int V_232 )
{
char * V_238 = V_231 -> V_234 ;
F_90 ( V_238 && V_231 -> V_233 > V_231 -> V_236 ) ;
if ( V_238 != NULL && V_232 > 0 )
memset ( V_238 + V_231 -> V_233 , 0 , V_232 ) ;
return F_106 ( V_231 , V_232 ) ;
}
static int F_109 ( struct V_214 * V_239 ,
enum V_240 V_240 ,
struct V_230 * V_231 ,
const unsigned char * V_81 )
{
char V_30 [ V_114 ] ;
struct V_123 * V_21 ;
struct V_132 * V_241 ;
void * V_1 = NULL ;
int V_219 , V_242 = 0 ;
unsigned int V_243 , V_127 = V_239 -> V_127 ;
F_110 ( V_30 , V_239 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_231 -> V_234 )
V_1 = V_231 -> V_234 + V_231 -> V_233 ;
switch ( V_240 ) {
case V_244 :
V_21 = F_33 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_219 = F_86 ( V_21 , V_127 ) ;
if ( V_1 ) {
if ( V_21 -> V_245 )
V_21 -> V_245 ( V_1 , V_239 -> V_18 ) ;
else
memcpy ( V_1 , V_239 -> V_18 , V_127 ) ;
}
V_243 = V_21 -> V_216 ;
if ( F_87 ( V_243 == - 1 ) )
V_243 = V_127 ;
F_37 ( V_21 -> V_130 ) ;
break;
case V_246 :
case V_247 :
V_241 = F_39 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_241 ) )
return F_35 ( V_241 ) ;
V_219 = F_93 ( V_241 ) ;
if ( V_1 ) {
if ( V_241 -> V_245 )
V_241 -> V_245 ( V_1 , V_239 -> V_18 ) ;
else
memcpy ( V_1 , V_239 -> V_18 , V_127 ) ;
}
V_243 = V_241 -> V_248 ;
F_37 ( V_241 -> V_130 ) ;
break;
default:
return - V_128 ;
}
V_231 -> V_233 += V_127 + V_219 ;
V_231 -> V_237 += V_127 ;
V_242 = F_84 ( V_243 ) - V_243 ;
if ( V_242 > 0 && V_1 ) {
F_90 ( V_231 -> V_236 <= V_242 ) ;
F_90 ( V_231 -> V_233 - ( V_127 + V_219 ) + V_243 > V_231 -> V_236 - V_242 ) ;
memset ( V_1 + V_243 , 0 , V_242 ) ;
}
return V_219 + V_127 ;
}
static int F_111 ( struct V_214 * V_249 ,
unsigned int V_250 , enum V_240 type ,
struct V_230 * V_231 , const void * V_81 )
{
int V_251 = 0 ;
char * V_252 ;
if ( V_250 == 0 )
return 0 ;
V_252 = ( char * ) V_249 ;
while ( V_250 >= sizeof( * V_249 ) ) {
struct V_19 * V_253 ;
int V_126 ;
V_253 = (struct V_19 * ) V_231 -> V_234 ;
if ( V_253 ) {
char * V_186 ;
V_186 = V_231 -> V_234 + V_231 -> V_233 ;
V_253 = (struct V_19 * ) V_186 ;
}
V_126 = F_107 ( V_231 , V_252 , sizeof( * V_249 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_250 -= sizeof( * V_249 ) ;
V_126 = F_108 ( V_231 , F_82 () ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_249 -> V_127 > V_250 )
return - V_128 ;
V_250 -= V_249 -> V_127 ;
V_126 = F_109 ( V_249 , type , V_231 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
F_90 ( V_126 < V_249 -> V_127 ) ;
V_251 += V_126 - V_249 -> V_127 ;
V_251 += F_82 () ;
V_252 += sizeof( * V_249 ) ;
V_252 += V_249 -> V_127 ;
if ( V_253 )
V_253 -> V_127 = V_126 ;
F_112 ( type == V_247 && V_250 ) ;
V_249 = (struct V_214 * ) V_252 ;
}
return V_251 ;
}
static int F_113 ( struct V_31 * V_25 , const unsigned char * V_81 ,
unsigned int * V_254 ,
struct V_230 * V_231 )
{
unsigned int V_28 , V_153 , V_255 , V_256 = 0 ;
unsigned int V_257 [ 4 ] ;
unsigned int * V_258 = NULL ;
int V_126 ;
char * V_259 ;
if ( * V_254 < sizeof( struct V_79 ) )
return - V_128 ;
if ( ! V_25 -> V_43 ) {
* V_254 -= sizeof( struct V_79 ) ;
return F_107 ( V_231 , V_25 , sizeof( struct V_79 ) ) ;
}
if ( * V_254 < sizeof( * V_25 ) || V_25 -> V_143 < sizeof( * V_25 ) )
return - V_128 ;
V_255 = V_231 -> V_237 ;
V_126 = F_107 ( V_231 , V_25 ,
F_114 ( struct V_31 , V_125 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_257 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_257 [ 1 ] , & V_25 -> V_125 ,
sizeof( V_257 ) - sizeof( V_257 [ 0 ] ) ) ;
if ( V_231 -> V_234 ) {
V_259 = V_231 -> V_234 + V_231 -> V_233 ;
V_258 = ( unsigned int * ) V_259 ;
}
V_126 = F_107 ( V_231 , & V_257 [ 1 ] ,
sizeof( V_257 ) - sizeof( V_257 [ 0 ] ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_259 = ( char * ) V_25 ;
for ( V_28 = 0 , V_153 = 1 ; V_153 < 4 ; V_153 ++ , V_28 ++ ) {
struct V_214 * V_249 ;
unsigned int V_178 ;
char * V_252 = V_259 ;
V_252 = V_259 + V_257 [ V_28 ] ;
if ( V_257 [ V_28 ] > V_257 [ V_153 ] )
return - V_128 ;
V_249 = (struct V_214 * ) V_252 ;
V_178 = V_257 [ V_153 ] - V_257 [ V_28 ] ;
V_126 = F_111 ( V_249 , V_178 , V_28 , V_231 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
V_256 += V_126 ;
if ( V_258 && V_256 ) {
F_100 ( L_47 ,
V_258 [ V_28 ] , V_257 [ V_153 ] + V_256 ) ;
V_258 [ V_28 ] = V_257 [ V_153 ] + V_256 ;
}
}
if ( V_231 -> V_234 == NULL ) {
unsigned int V_140 = V_259 - ( char * ) V_81 ;
V_126 = F_99 ( V_5 , V_140 , V_256 ) ;
if ( V_126 < 0 )
return V_126 ;
}
V_255 = V_231 -> V_237 - V_255 ;
F_90 ( * V_254 < V_255 ) ;
* V_254 -= V_255 ;
return 0 ;
}
static int F_115 ( unsigned char * V_18 , unsigned int V_260 ,
struct V_230 * V_231 )
{
unsigned int V_261 = V_260 ;
int V_126 ;
V_126 = F_50 ( V_18 , V_260 , F_113 , V_18 ,
& V_261 , V_231 ) ;
if ( V_126 < 0 )
return V_126 ;
F_112 ( V_261 ) ;
return V_231 -> V_233 ;
}
static int F_116 ( struct V_134 * V_135 ,
void T_1 * V_184 , unsigned int V_98 )
{
struct V_226 V_186 ;
int V_28 ;
if ( V_98 < sizeof( V_186 ) )
return - V_128 ;
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_186 ) + V_186 . V_138 )
return - V_128 ;
if ( V_186 . V_138 == 0 )
return - V_128 ;
if ( V_186 . V_69 >= ( ( V_187 - sizeof( struct V_82 ) ) /
V_188 - V_189 ) / sizeof( struct V_71 ) )
return - V_173 ;
if ( V_186 . V_177 >= V_187 / sizeof( struct V_71 ) )
return - V_173 ;
memcpy ( V_135 , & V_186 , F_114 ( struct V_134 , V_91 ) ) ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
V_135 -> V_91 [ V_28 ] = F_105 ( V_186 . V_91 [ V_28 ] ) ;
V_135 -> V_177 = V_186 . V_177 ;
V_135 -> V_89 = F_105 ( V_186 . V_89 ) ;
V_135 -> V_93 = F_105 ( V_186 . V_93 ) ;
return 0 ;
}
static int F_117 ( struct V_117 * V_117 , void T_1 * V_184 ,
unsigned int V_98 )
{
int V_126 , V_28 , V_185 , V_262 ;
struct V_82 * V_136 ;
struct V_134 V_186 ;
struct V_230 V_231 ;
void * V_263 ;
V_126 = F_116 ( & V_186 , V_184 , V_98 ) ;
if ( V_126 ) {
if ( V_126 == - V_128 && F_59 ( V_117 , V_184 , V_98 ) == 0 )
V_126 = 0 ;
return V_126 ;
}
V_185 = F_61 ( V_186 . V_69 ) * V_172 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_185 ) ;
if ( ! V_136 )
return - V_173 ;
if ( V_185 )
memset ( V_136 -> V_89 , 0 , V_185 ) ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_136 -> V_93 = F_51 ( V_186 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_173 ;
goto V_190;
}
if ( F_60 (
V_136 -> V_93 , V_186 . V_93 , V_186 . V_138 ) != 0 ) {
V_126 = - V_7 ;
goto V_191;
}
V_263 = V_136 -> V_93 ;
F_118 ( V_5 ) ;
F_102 ( V_5 , V_186 . V_69 ) ;
V_126 = F_115 ( V_263 , V_186 . V_138 , & V_231 ) ;
if ( V_126 < 0 )
goto V_264;
F_100 ( L_48 ,
V_186 . V_138 , V_231 . V_233 , V_231 . V_237 ,
F_2 ( V_5 , V_186 . V_138 ) ) ;
V_262 = V_126 ;
V_136 -> V_93 = F_51 ( V_262 ) ;
if ( ! V_136 -> V_93 ) {
F_53 ( V_263 ) ;
V_126 = - V_173 ;
goto V_264;
}
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . V_234 = V_136 -> V_93 ;
V_231 . V_236 = V_262 ;
V_126 = F_115 ( V_263 , V_186 . V_138 , & V_231 ) ;
F_90 ( V_126 < 0 ) ;
F_53 ( V_263 ) ;
V_186 . V_138 = V_262 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
char T_1 * V_265 ;
if ( V_186 . V_91 [ V_28 ] ) {
unsigned int V_266 ;
V_265 = ( char T_1 * ) V_186 . V_91 [ V_28 ] ;
V_266 = V_265 - V_186 . V_93 ;
V_265 += F_2 ( V_5 , V_266 ) ;
V_186 . V_91 [ V_28 ] = (struct V_79 T_1 * ) V_265 ;
}
}
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
V_126 = F_55 ( V_117 , & V_186 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_191:
F_53 ( V_136 -> V_93 ) ;
V_190:
F_53 ( V_136 ) ;
return V_126 ;
V_264:
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
goto V_191;
}
static int F_121 ( struct V_117 * V_117 , void T_1 * V_184 ,
unsigned int V_98 )
{
struct V_226 V_200 ;
if ( F_60 ( & V_200 , V_184 , sizeof( V_200 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_200 ) + V_200 . V_177 * sizeof( struct V_71 ) )
return F_72 ( V_117 , V_184 , V_98 ) ;
return F_71 ( V_117 , V_200 . V_30 , F_105 ( V_200 . V_89 ) ,
V_200 . V_177 , V_184 , V_98 ) ;
}
static int F_122 ( struct V_204 * V_205 ,
int V_202 , void T_1 * V_184 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_79 ( V_205 ) ;
if ( ! F_80 ( V_117 -> V_206 , V_207 ) )
return - V_208 ;
switch ( V_202 ) {
case V_209 :
V_126 = F_117 ( V_117 , V_184 , V_98 ) ;
break;
case V_210 :
V_126 = F_121 ( V_117 , V_184 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_123 ( struct V_204 * V_205 , int V_202 ,
void T_1 * V_184 , int * V_98 )
{
int V_126 ;
struct V_226 V_186 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_79 ( V_205 ) ;
if ( ! F_80 ( V_117 -> V_206 , V_207 ) )
return - V_208 ;
if ( ( V_202 == V_211 ||
V_202 == V_212 ) && * V_98 != sizeof( V_186 ) )
return F_81 ( V_205 , V_202 , V_184 , V_98 ) ;
if ( F_60 ( & V_186 , V_184 , sizeof( V_186 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_186 . V_30 , & V_126 , & V_180 ) ;
if ( ! V_75 )
return V_126 ;
F_118 ( V_5 ) ;
switch ( V_202 ) {
case V_211 :
V_186 . V_69 = V_75 -> V_83 -> V_69 ;
V_126 = F_101 ( V_75 -> V_83 , & V_186 ) ;
if ( V_126 )
goto V_34;
V_186 . V_139 = V_75 -> V_139 ;
if ( F_4 ( V_184 , & V_186 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_212 :
V_186 . V_69 = V_75 -> V_68 -> V_69 ;
V_186 . V_138 = V_75 -> V_68 -> V_138 ;
V_186 . V_139 = V_75 -> V_68 -> V_139 ;
if ( F_4 ( V_184 , & V_186 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_203 :
case V_213 :
if ( F_77 ( V_75 , V_184 , V_98 , V_202 ) == 0 )
V_126 = 0 ;
else
V_126 = F_103 ( V_75 , V_184 , V_98 , V_202 ) ;
break;
default:
V_126 = - V_128 ;
}
V_34:
F_119 ( V_5 ) ;
F_120 ( V_5 ) ;
F_28 ( & V_180 ) ;
return V_126 ;
}
static int T_6 F_124 ( void )
{
int V_126 ;
V_126 = F_125 ( & V_100 ) ;
if ( V_126 < 0 )
return V_126 ;
V_126 = F_126 ( & V_267 ) ;
if ( V_126 < 0 ) {
F_127 ( & V_100 ) ;
return V_126 ;
}
F_128 ( V_268 L_49 ) ;
return 0 ;
}
static void T_7 F_129 ( void )
{
F_130 ( & V_267 ) ;
F_127 ( & V_100 ) ;
F_128 ( V_268 L_50 ) ;
}
