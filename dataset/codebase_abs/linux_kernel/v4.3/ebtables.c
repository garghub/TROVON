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
if ( F_12 ( F_13 ( V_39 ) , V_45 ) )
return 1 ;
} else if ( ! ( V_32 -> V_43 & V_46 ) &&
F_12 ( V_32 -> V_39 != V_39 , V_45 ) )
return 1 ;
if ( F_12 ( F_7 ( V_32 -> V_33 , V_33 ) , V_47 ) )
return 1 ;
if ( F_12 ( F_7 ( V_32 -> V_34 , V_34 ) , V_48 ) )
return 1 ;
if ( V_33 && ( V_38 = F_14 ( V_33 ) ) != NULL &&
F_12 ( F_7 ( V_32 -> V_49 , V_38 -> V_50 -> V_51 ) , V_52 ) )
return 1 ;
if ( V_34 && ( V_38 = F_14 ( V_34 ) ) != NULL &&
F_12 ( F_7 ( V_32 -> V_53 , V_38 -> V_50 -> V_51 ) , V_54 ) )
return 1 ;
if ( V_32 -> V_43 & V_55 ) {
V_40 = 0 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ )
V_40 |= ( V_36 -> V_56 [ V_28 ] ^ V_32 -> V_57 [ V_28 ] ) &
V_32 -> V_58 [ V_28 ] ;
if ( F_12 ( V_40 != 0 , V_59 ) )
return 1 ;
}
if ( V_32 -> V_43 & V_60 ) {
V_40 = 0 ;
for ( V_28 = 0 ; V_28 < 6 ; V_28 ++ )
V_40 |= ( V_36 -> V_61 [ V_28 ] ^ V_32 -> V_62 [ V_28 ] ) &
V_32 -> V_63 [ V_28 ] ;
if ( F_12 ( V_40 != 0 , V_64 ) )
return 1 ;
}
return 0 ;
}
static inline
struct V_31 * F_15 ( const struct V_31 * V_25 )
{
return ( void * ) V_25 + V_25 -> V_65 ;
}
unsigned int F_16 ( unsigned int V_66 , struct V_10 * V_11 ,
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
F_17 ( & V_68 -> V_88 ) ;
V_83 = V_68 -> V_83 ;
V_73 = F_18 ( V_83 -> V_89 , V_83 -> V_69 ,
F_19 () ) ;
if ( V_83 -> V_90 )
V_78 = V_83 -> V_90 [ F_19 () ] ;
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
if ( F_20 ( V_70 , F_6 , V_11 , & V_84 ) != 0 )
goto V_94;
if ( V_84 . V_86 ) {
F_21 ( & V_68 -> V_88 ) ;
return V_95 ;
}
( * ( V_72 + V_28 ) ) . V_96 ++ ;
( * ( V_72 + V_28 ) ) . V_97 += V_11 -> V_98 ;
F_22 ( V_70 , F_5 , V_11 , & V_84 ) ;
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
F_21 ( & V_68 -> V_88 ) ;
return V_102 ;
}
if ( V_40 == V_103 ) {
F_21 ( & V_68 -> V_88 ) ;
return V_95 ;
}
if ( V_40 == V_104 ) {
V_105:
#ifdef F_23
if ( V_76 == 0 ) {
F_24 ( L_1 ) ;
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
#ifdef F_23
if ( V_40 < 0 ) {
F_24 ( L_2 ) ;
F_21 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_78 [ V_76 ] . V_106 = V_28 + 1 ;
V_78 [ V_76 ] . V_80 = V_80 ;
V_78 [ V_76 ] . V_32 = F_15 ( V_70 ) ;
V_28 = 0 ;
V_80 = (struct V_79 * ) ( V_81 + V_40 ) ;
#ifdef F_23
if ( V_80 -> V_108 ) {
F_24 ( L_3 ) ;
F_21 ( & V_68 -> V_88 ) ;
return V_95 ;
}
#endif
V_69 = V_80 -> V_69 ;
V_70 = (struct V_31 * ) V_80 -> V_18 ;
V_72 = V_73 + V_80 -> V_92 ;
V_76 ++ ;
continue;
V_94:
V_70 = F_15 ( V_70 ) ;
V_28 ++ ;
}
if ( V_80 -> V_109 == V_104 )
goto V_105;
if ( V_80 -> V_109 == V_101 ) {
F_21 ( & V_68 -> V_88 ) ;
return V_102 ;
}
F_21 ( & V_68 -> V_88 ) ;
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
V_32 -> V_39 , V_32 -> V_129 & V_45 ) ;
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
V_32 -> V_39 , V_32 -> V_129 & V_45 ) ;
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
F_24 ( L_6
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
if ( V_124 < V_32 -> V_65 )
break;
if ( V_32 -> V_65 < sizeof( struct V_31 ) )
return - V_128 ;
V_140 += V_32 -> V_65 ;
}
}
if ( V_140 != V_137 ) {
F_24 ( L_8 ) ;
return - V_128 ;
}
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ! V_136 -> V_91 [ V_28 ] &&
( V_139 & ( 1 << V_28 ) ) ) {
F_24 ( L_9 ) ;
return - V_128 ;
}
}
return 0 ;
}
static inline int
F_42 ( const struct V_31 * V_32 ,
const struct V_82 * V_136 ,
unsigned int * V_106 , unsigned int * V_121 ,
unsigned int * V_143 , unsigned int * V_144 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
if ( ( void * ) V_32 == ( void * ) V_136 -> V_91 [ V_28 ] )
break;
}
if ( V_28 != V_141 || ! V_32 -> V_43 ) {
if ( * V_106 != * V_121 ) {
F_24 ( L_10
L_11 ) ;
return - V_128 ;
}
if ( ( (struct V_79 * ) V_32 ) -> V_109 != V_103 &&
( (struct V_79 * ) V_32 ) -> V_109 != V_101 ) {
if ( V_28 != V_141 ||
( (struct V_79 * ) V_32 ) -> V_109 != V_104 ) {
F_24 ( L_12 ) ;
return - V_128 ;
}
}
if ( V_28 == V_141 )
( * V_144 ) ++ ;
if ( ( (struct V_79 * ) V_32 ) -> V_92 != * V_143 ) {
F_24 ( L_13 ) ;
return - V_128 ;
}
* V_106 = ( (struct V_79 * ) V_32 ) -> V_69 ;
* V_121 = 0 ;
return 0 ;
}
if ( sizeof( struct V_31 ) > V_32 -> V_125 ||
V_32 -> V_125 > V_32 -> V_99 ||
V_32 -> V_99 >= V_32 -> V_65 ) {
F_24 ( L_14 ) ;
return - V_128 ;
}
if ( V_32 -> V_65 - V_32 -> V_99 < sizeof( struct V_74 ) ) {
F_24 ( L_15 ) ;
return - V_128 ;
}
( * V_121 ) ++ ;
( * V_143 ) ++ ;
return 0 ;
}
static inline int
F_43 ( struct V_31 * V_32 , struct V_82 * V_136 ,
unsigned int * V_106 , struct V_145 * V_146 )
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
V_146 [ * V_106 ] . V_78 . V_80 = (struct V_79 * ) V_32 ;
V_146 [ * V_106 ] . V_78 . V_106 = 0 ;
V_146 [ * V_106 ] . V_147 = 0 ;
( * V_106 ) ++ ;
return 0 ;
}
static inline int
F_44 ( struct V_19 * V_20 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_148 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_21 = V_20 -> V_15 . V_21 ;
V_13 . V_22 = V_20 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_21 -> V_149 != NULL )
V_13 . V_21 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_21 -> V_130 ) ;
return 0 ;
}
static inline int
F_45 ( struct V_8 * V_9 , struct V_117 * V_117 , unsigned int * V_28 )
{
struct V_150 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_9 -> V_15 . V_16 ;
V_13 . V_17 = V_9 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_14 -> V_149 != NULL )
V_13 . V_14 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_46 ( struct V_31 * V_32 , struct V_117 * V_117 , unsigned int * V_121 )
{
struct V_150 V_13 ;
struct V_74 * V_75 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_121 && ( * V_121 ) -- == 0 )
return 1 ;
F_22 ( V_32 , F_45 , V_117 , NULL ) ;
F_20 ( V_32 , F_44 , V_117 , NULL ) ;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_13 . V_117 = V_117 ;
V_13 . V_14 = V_75 -> V_15 . V_14 ;
V_13 . V_17 = V_75 -> V_18 ;
V_13 . V_85 = V_5 ;
if ( V_13 . V_14 -> V_149 != NULL )
V_13 . V_14 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_130 ) ;
return 0 ;
}
static inline int
F_47 ( struct V_31 * V_32 , struct V_117 * V_117 ,
const struct V_82 * V_136 ,
const char * V_30 , unsigned int * V_121 ,
struct V_145 * V_151 , unsigned int V_144 )
{
struct V_74 * V_75 ;
struct V_132 * V_14 ;
unsigned int V_28 , V_152 , V_66 = 0 , V_147 = 0 ;
T_3 V_153 ;
int V_126 ;
struct V_120 V_154 ;
struct V_131 V_155 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_32 -> V_43 & ~ V_156 ) {
F_24 ( L_16 ) ;
return - V_128 ;
}
if ( V_32 -> V_129 & ~ V_157 ) {
F_24 ( L_17 ) ;
return - V_128 ;
}
if ( ( V_32 -> V_43 & V_46 ) && ( V_32 -> V_43 & V_44 ) ) {
F_24 ( L_18 ) ;
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
V_147 = ( 1 << V_66 ) | ( 1 << V_141 ) ;
else {
for ( V_28 = 0 ; V_28 < V_144 ; V_28 ++ )
if ( ( char * ) ( V_151 [ V_28 ] . V_78 . V_80 ) > ( char * ) V_32 )
break;
if ( V_28 == 0 )
V_147 = ( 1 << V_66 ) | ( 1 << V_141 ) ;
else
V_147 = V_151 [ V_28 - 1 ] . V_147 ;
}
V_28 = 0 ;
V_154 . V_117 = V_155 . V_117 = V_117 ;
V_154 . V_68 = V_155 . V_68 = V_30 ;
V_154 . V_122 = V_155 . V_122 = V_32 ;
V_154 . V_158 = V_155 . V_158 = V_147 ;
V_154 . V_85 = V_155 . V_85 = V_5 ;
V_126 = F_20 ( V_32 , F_32 , & V_154 , & V_28 ) ;
if ( V_126 != 0 )
goto V_159;
V_152 = 0 ;
V_126 = F_22 ( V_32 , F_38 , & V_155 , & V_152 ) ;
if ( V_126 != 0 )
goto V_160;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_153 = V_32 -> V_65 - V_32 -> V_99 ;
V_14 = F_39 ( V_5 , V_75 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_14 ) ) {
V_126 = F_35 ( V_14 ) ;
goto V_160;
}
V_75 -> V_15 . V_14 = V_14 ;
if ( V_75 -> V_15 . V_14 == & V_100 ) {
if ( V_153 < sizeof( struct V_100 ) ) {
F_24 ( L_19 ) ;
V_126 = - V_7 ;
goto V_160;
}
if ( ( (struct V_100 * ) V_75 ) -> V_40 <
- V_161 ) {
F_24 ( L_20 ) ;
V_126 = - V_7 ;
goto V_160;
}
} else if ( V_75 -> V_162 > V_153 - sizeof( struct V_74 ) ) {
F_37 ( V_75 -> V_15 . V_14 -> V_130 ) ;
V_126 = - V_7 ;
goto V_160;
}
V_155 . V_14 = V_14 ;
V_155 . V_17 = V_75 -> V_18 ;
V_126 = F_40 ( & V_155 , V_75 -> V_162 ,
V_32 -> V_39 , V_32 -> V_129 & V_45 ) ;
if ( V_126 < 0 ) {
F_37 ( V_14 -> V_130 ) ;
goto V_160;
}
( * V_121 ) ++ ;
return 0 ;
V_160:
F_22 ( V_32 , F_45 , V_117 , & V_152 ) ;
V_159:
F_20 ( V_32 , F_44 , V_117 , & V_28 ) ;
return V_126 ;
}
static int F_48 ( const struct V_79 * V_163 , struct V_145 * V_151 ,
unsigned int V_144 , unsigned int V_164 , char * V_81 )
{
int V_28 , V_165 = - 1 , V_166 = 0 , V_69 = V_163 -> V_69 , V_40 ;
const struct V_31 * V_32 = (struct V_31 * ) V_163 -> V_18 ;
const struct V_74 * V_75 ;
while ( V_166 < V_69 || V_165 != - 1 ) {
if ( V_166 == V_69 ) {
V_32 = V_151 [ V_165 ] . V_78 . V_32 ;
if ( V_151 [ V_165 ] . V_167 != - 1 )
V_69 =
V_151 [ V_151 [ V_165 ] . V_167 ] . V_78 . V_80 -> V_69 ;
else
V_69 = V_163 -> V_69 ;
V_166 = V_151 [ V_165 ] . V_78 . V_106 ;
V_151 [ V_165 ] . V_78 . V_106 = 0 ;
V_165 = V_151 [ V_165 ] . V_167 ;
if ( V_166 == V_69 )
continue;
}
V_75 = (struct V_74 * )
( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
if ( strcmp ( V_75 -> V_15 . V_30 , V_168 ) )
goto V_94;
if ( V_32 -> V_99 + sizeof( struct V_100 ) >
V_32 -> V_65 ) {
F_24 ( L_19 ) ;
return - 1 ;
}
V_40 = ( (struct V_100 * ) V_75 ) -> V_40 ;
if ( V_40 >= 0 ) {
struct V_79 * V_169 =
(struct V_79 * ) ( V_81 + V_40 ) ;
for ( V_28 = 0 ; V_28 < V_144 ; V_28 ++ )
if ( V_169 == V_151 [ V_28 ] . V_78 . V_80 )
break;
if ( V_28 == V_144 ) {
F_24 ( L_21 ) ;
return - 1 ;
}
if ( V_151 [ V_28 ] . V_78 . V_106 ) {
F_24 ( L_22 ) ;
return - 1 ;
}
if ( V_151 [ V_28 ] . V_147 & ( 1 << V_164 ) )
goto V_94;
V_151 [ V_28 ] . V_78 . V_106 = V_166 + 1 ;
V_166 = 0 ;
V_151 [ V_28 ] . V_78 . V_32 = F_15 ( V_32 ) ;
V_32 = (struct V_31 * ) ( V_169 -> V_18 ) ;
V_69 = V_169 -> V_69 ;
V_151 [ V_28 ] . V_167 = V_165 ;
V_165 = V_28 ;
V_151 [ V_28 ] . V_147 |= ( 1 << V_164 ) ;
continue;
}
V_94:
V_32 = F_15 ( V_32 ) ;
V_166 ++ ;
}
return 0 ;
}
static int F_49 ( struct V_117 * V_117 , const char * V_30 ,
struct V_82 * V_136 )
{
unsigned int V_28 , V_152 , V_170 , V_144 ;
int V_126 ;
struct V_145 * V_151 = NULL ;
V_28 = 0 ;
while ( V_28 < V_141 && ! V_136 -> V_91 [ V_28 ] )
V_28 ++ ;
if ( V_28 == V_141 ) {
F_24 ( L_23 ) ;
return - V_128 ;
}
if ( V_136 -> V_91 [ V_28 ] != (struct V_79 * ) V_136 -> V_93 ) {
F_24 ( L_24 ) ;
return - V_128 ;
}
for ( V_152 = V_28 + 1 ; V_152 < V_141 ; V_152 ++ ) {
if ( ! V_136 -> V_91 [ V_152 ] )
continue;
if ( V_136 -> V_91 [ V_152 ] <= V_136 -> V_91 [ V_28 ] ) {
F_24 ( L_25 ) ;
return - V_128 ;
}
V_28 = V_152 ;
}
V_28 = 0 ;
V_152 = 0 ;
V_170 = 0 ;
V_144 = 0 ;
V_126 = F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_42 , V_136 ,
& V_28 , & V_152 , & V_170 , & V_144 ) ;
if ( V_126 != 0 )
return V_126 ;
if ( V_28 != V_152 ) {
F_24 ( L_26
L_27 ) ;
return - V_128 ;
}
if ( V_170 != V_136 -> V_69 ) {
F_24 ( L_28 ) ;
return - V_128 ;
}
if ( V_144 ) {
V_136 -> V_90 =
F_51 ( V_171 * sizeof( * ( V_136 -> V_90 ) ) ) ;
if ( ! V_136 -> V_90 )
return - V_172 ;
F_52 (i) {
V_136 -> V_90 [ V_28 ] =
F_51 ( V_144 * sizeof( * ( V_136 -> V_90 [ 0 ] ) ) ) ;
if ( ! V_136 -> V_90 [ V_28 ] ) {
while ( V_28 )
F_53 ( V_136 -> V_90 [ -- V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
V_136 -> V_90 = NULL ;
return - V_172 ;
}
}
V_151 = F_51 ( V_144 * sizeof( * V_151 ) ) ;
if ( ! V_151 )
return - V_172 ;
V_28 = 0 ;
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_43 , V_136 , & V_28 , V_151 ) ;
if ( V_28 != V_144 ) {
F_24 ( L_29 ) ;
F_53 ( V_151 ) ;
return - V_7 ;
}
}
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
if ( V_136 -> V_91 [ V_28 ] )
if ( F_48 ( V_136 -> V_91 [ V_28 ] ,
V_151 , V_144 , V_28 , V_136 -> V_93 ) ) {
F_53 ( V_151 ) ;
return - V_128 ;
}
V_28 = 0 ;
V_126 = F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_47 , V_117 , V_136 , V_30 , & V_28 , V_151 , V_144 ) ;
if ( V_126 != 0 ) {
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_46 , V_117 , & V_28 ) ;
}
F_53 ( V_151 ) ;
return V_126 ;
}
static void F_54 ( const struct V_71 * V_173 ,
struct V_71 * V_89 , unsigned int V_69 )
{
int V_28 , V_174 ;
struct V_71 * V_72 ;
memcpy ( V_89 , V_173 ,
sizeof( struct V_71 ) * V_69 ) ;
F_52 (cpu) {
if ( V_174 == 0 )
continue;
V_72 = F_18 ( V_173 , V_69 , V_174 ) ;
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
struct V_71 * V_175 = NULL ;
struct V_82 * V_68 ;
struct V_67 * V_75 ;
if ( V_135 -> V_176 ) {
unsigned long V_177 = V_135 -> V_176 * sizeof( * V_175 ) ;
V_175 = F_51 ( V_177 ) ;
if ( ! V_175 )
return - V_172 ;
}
V_136 -> V_90 = NULL ;
V_126 = F_41 ( V_135 , V_136 ) ;
if ( V_126 != 0 )
goto V_178;
V_126 = F_49 ( V_117 , V_135 -> V_30 , V_136 ) ;
if ( V_126 != 0 )
goto V_178;
V_75 = F_31 ( V_117 , V_135 -> V_30 , & V_126 , & V_179 ) ;
if ( ! V_75 ) {
V_126 = - V_115 ;
goto V_180;
}
if ( V_75 -> V_181 && ( V_126 = V_75 -> V_181 ( V_136 , V_135 -> V_139 ) ) )
goto V_182;
if ( V_135 -> V_176 && V_135 -> V_176 != V_75 -> V_83 -> V_69 ) {
F_24 ( L_30 ) ;
V_126 = - V_128 ;
goto V_182;
}
V_68 = V_75 -> V_83 ;
if ( ! V_68 -> V_69 && V_136 -> V_69 && ! F_56 ( V_75 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_182;
} else if ( V_68 -> V_69 && ! V_136 -> V_69 )
F_37 ( V_75 -> V_130 ) ;
F_57 ( & V_75 -> V_88 ) ;
if ( V_135 -> V_176 )
F_54 ( V_75 -> V_83 -> V_89 , V_175 ,
V_75 -> V_83 -> V_69 ) ;
V_75 -> V_83 = V_136 ;
F_58 ( & V_75 -> V_88 ) ;
F_28 ( & V_179 ) ;
if ( V_135 -> V_176 &&
F_4 ( V_135 -> V_89 , V_175 ,
V_135 -> V_176 * sizeof( struct V_71 ) ) ) {
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
F_53 ( V_175 ) ;
#ifdef F_60
if ( V_183 ) {
struct V_184 * V_185 ;
V_185 = F_61 ( V_186 -> V_187 , V_188 ,
V_189 ) ;
if ( V_185 ) {
F_62 ( V_185 , L_32 ,
V_135 -> V_30 , V_190 , V_135 -> V_69 ) ;
F_63 ( V_185 ) ;
}
}
#endif
return V_126 ;
V_182:
F_28 ( & V_179 ) ;
V_180:
F_50 ( V_136 -> V_93 , V_136 -> V_138 ,
F_46 , V_117 , NULL ) ;
V_178:
F_53 ( V_175 ) ;
if ( V_136 -> V_90 ) {
F_52 (i)
F_53 ( V_136 -> V_90 [ V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
}
return V_126 ;
}
static int F_64 ( struct V_117 * V_117 , const void T_1 * V_191 ,
unsigned int V_98 )
{
int V_126 , V_192 ;
struct V_82 * V_136 ;
struct V_134 V_193 ;
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) != 0 )
return - V_7 ;
if ( V_98 != sizeof( V_193 ) + V_193 . V_138 ) {
F_24 ( L_33 ) ;
return - V_128 ;
}
if ( V_193 . V_138 == 0 ) {
F_24 ( L_34 ) ;
return - V_128 ;
}
if ( V_193 . V_69 >= ( ( V_194 - sizeof( struct V_82 ) ) /
V_195 - V_196 ) / sizeof( struct V_71 ) )
return - V_172 ;
if ( V_193 . V_176 >= V_194 / sizeof( struct V_71 ) )
return - V_172 ;
V_193 . V_30 [ sizeof( V_193 . V_30 ) - 1 ] = 0 ;
V_192 = F_66 ( V_193 . V_69 ) * V_171 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_192 ) ;
if ( ! V_136 )
return - V_172 ;
if ( V_192 )
memset ( V_136 -> V_89 , 0 , V_192 ) ;
V_136 -> V_93 = F_51 ( V_193 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_172 ;
goto V_197;
}
if ( F_65 (
V_136 -> V_93 , V_193 . V_93 , V_193 . V_138 ) != 0 ) {
F_24 ( L_35 ) ;
V_126 = - V_7 ;
goto V_198;
}
V_126 = F_55 ( V_117 , & V_193 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_198:
F_53 ( V_136 -> V_93 ) ;
V_197:
F_53 ( V_136 ) ;
return V_126 ;
}
struct V_67 *
F_67 ( struct V_117 * V_117 , const struct V_67 * V_199 )
{
struct V_82 * V_136 ;
struct V_67 * V_75 , * V_68 ;
struct V_200 * V_135 ;
int V_126 , V_28 , V_192 ;
void * V_38 ;
if ( V_199 == NULL || ( V_135 = V_199 -> V_68 ) == NULL ||
V_135 -> V_93 == NULL || V_135 -> V_138 == 0 ||
V_135 -> V_89 != NULL || V_199 -> V_83 != NULL ) {
F_24 ( L_36 ) ;
return F_68 ( - V_128 ) ;
}
V_68 = F_69 ( V_199 , sizeof( struct V_67 ) , V_188 ) ;
if ( ! V_68 ) {
V_126 = - V_172 ;
goto V_34;
}
V_192 = F_66 ( V_135 -> V_69 ) * V_171 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_192 ) ;
V_126 = - V_172 ;
if ( ! V_136 )
goto V_201;
V_38 = F_51 ( V_135 -> V_138 ) ;
if ( ! V_38 )
goto V_197;
memcpy ( V_38 , V_135 -> V_93 , V_135 -> V_138 ) ;
V_136 -> V_93 = V_38 ;
V_136 -> V_138 = V_135 -> V_138 ;
V_136 -> V_69 = V_135 -> V_69 ;
if ( V_192 )
memset ( V_136 -> V_89 , 0 , V_192 ) ;
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
F_24 ( L_37 ) ;
goto V_202;
}
if ( V_68 -> V_181 && V_68 -> V_181 ( V_136 , V_68 -> V_139 ) ) {
F_24 ( L_38 ) ;
V_126 = - V_128 ;
goto V_202;
}
V_68 -> V_83 = V_136 ;
F_70 ( & V_68 -> V_88 ) ;
F_26 ( & V_179 ) ;
F_27 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_75 -> V_30 , V_68 -> V_30 ) == 0 ) {
V_126 = - V_203 ;
F_24 ( L_39 ) ;
goto V_182;
}
}
if ( V_136 -> V_69 && ! F_56 ( V_68 -> V_130 ) ) {
V_126 = - V_115 ;
goto V_182;
}
F_71 ( & V_68 -> V_113 , & V_117 -> V_118 . V_119 [ V_5 ] ) ;
F_28 ( & V_179 ) ;
return V_68 ;
V_182:
F_28 ( & V_179 ) ;
V_202:
if ( V_136 -> V_90 ) {
F_52 (i)
F_53 ( V_136 -> V_90 [ V_28 ] ) ;
F_53 ( V_136 -> V_90 ) ;
}
F_53 ( V_136 -> V_93 ) ;
V_197:
F_53 ( V_136 ) ;
V_201:
F_72 ( V_68 ) ;
V_34:
return F_68 ( V_126 ) ;
}
void F_73 ( struct V_117 * V_117 , struct V_67 * V_68 )
{
int V_28 ;
if ( ! V_68 ) {
F_24 ( L_40 ) ;
return;
}
F_26 ( & V_179 ) ;
F_74 ( & V_68 -> V_113 ) ;
F_28 ( & V_179 ) ;
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
unsigned int V_176 ,
const void T_1 * V_191 , unsigned int V_98 )
{
int V_28 , V_126 ;
struct V_71 * V_193 ;
struct V_67 * V_75 ;
if ( V_176 == 0 )
return - V_128 ;
V_193 = F_51 ( V_176 * sizeof( * V_193 ) ) ;
if ( ! V_193 )
return - V_172 ;
V_75 = F_31 ( V_117 , V_30 , & V_126 , & V_179 ) ;
if ( ! V_75 )
goto V_204;
if ( V_176 != V_75 -> V_83 -> V_69 ) {
F_24 ( L_41 ) ;
V_126 = - V_128 ;
goto V_205;
}
if ( F_65 ( V_193 , V_89 , V_176 * sizeof( * V_89 ) ) ) {
V_126 = - V_7 ;
goto V_205;
}
F_57 ( & V_75 -> V_88 ) ;
for ( V_28 = 0 ; V_28 < V_176 ; V_28 ++ ) {
V_75 -> V_83 -> V_89 [ V_28 ] . V_96 += V_193 [ V_28 ] . V_96 ;
V_75 -> V_83 -> V_89 [ V_28 ] . V_97 += V_193 [ V_28 ] . V_97 ;
}
F_58 ( & V_75 -> V_88 ) ;
V_126 = 0 ;
V_205:
F_28 ( & V_179 ) ;
V_204:
F_53 ( V_193 ) ;
return V_126 ;
}
static int F_76 ( struct V_117 * V_117 , const void T_1 * V_191 ,
unsigned int V_98 )
{
struct V_134 V_206 ;
if ( F_65 ( & V_206 , V_191 , sizeof( V_206 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_206 ) + V_206 . V_176 * sizeof( struct V_71 ) )
return - V_128 ;
return F_75 ( V_117 , V_206 . V_30 , V_206 . V_89 ,
V_206 . V_176 , V_191 , V_98 ) ;
}
static inline int F_77 ( const struct V_19 * V_20 ,
const char * V_81 , char T_1 * V_207 )
{
char T_1 * V_206 = V_207 + ( ( char * ) V_20 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
F_78 ( V_30 , V_20 -> V_15 . V_21 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_206 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int F_79 ( const struct V_8 * V_9 ,
const char * V_81 , char T_1 * V_207 )
{
char T_1 * V_206 = V_207 + ( ( char * ) V_9 - V_81 ) ;
char V_30 [ V_114 ] = {} ;
F_78 ( V_30 , V_9 -> V_15 . V_16 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_206 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static inline int
F_80 ( struct V_31 * V_32 , const char * V_81 , char T_1 * V_207 )
{
int V_126 ;
char T_1 * V_206 ;
const struct V_74 * V_75 ;
char V_30 [ V_114 ] = {} ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_206 = V_207 + ( ( ( char * ) V_32 + V_32 -> V_99 ) - V_81 ) ;
V_75 = (struct V_74 * ) ( ( ( char * ) V_32 ) + V_32 -> V_99 ) ;
V_126 = F_20 ( V_32 , F_77 , V_81 , V_207 ) ;
if ( V_126 != 0 )
return V_126 ;
V_126 = F_22 ( V_32 , F_79 , V_81 , V_207 ) ;
if ( V_126 != 0 )
return V_126 ;
F_78 ( V_30 , V_75 -> V_15 . V_14 -> V_30 , sizeof( V_30 ) ) ;
if ( F_4 ( V_206 , V_30 , V_114 ) )
return - V_7 ;
return 0 ;
}
static int F_81 ( struct V_67 * V_75 ,
const struct V_71 * V_173 ,
void T_1 * V_191 , unsigned int V_176 ,
unsigned int V_69 )
{
struct V_71 * V_175 ;
int V_126 = 0 ;
if ( V_176 == 0 )
return 0 ;
if ( V_176 != V_69 ) {
F_24 ( L_42 ) ;
return - V_128 ;
}
V_175 = F_51 ( V_69 * sizeof( * V_175 ) ) ;
if ( ! V_175 )
return - V_172 ;
F_57 ( & V_75 -> V_88 ) ;
F_54 ( V_173 , V_175 , V_69 ) ;
F_58 ( & V_75 -> V_88 ) ;
if ( F_4 ( V_191 , V_175 ,
V_69 * sizeof( struct V_71 ) ) )
V_126 = - V_7 ;
F_53 ( V_175 ) ;
return V_126 ;
}
static int F_82 ( struct V_67 * V_75 , void T_1 * V_191 ,
const int * V_98 , int V_208 )
{
struct V_134 V_193 ;
const struct V_71 * V_173 ;
unsigned int V_138 , V_69 ;
int V_126 ;
char * V_93 ;
if ( V_208 == V_209 ) {
V_138 = V_75 -> V_83 -> V_138 ;
V_69 = V_75 -> V_83 -> V_69 ;
V_93 = V_75 -> V_83 -> V_93 ;
V_173 = V_75 -> V_83 -> V_89 ;
} else {
V_138 = V_75 -> V_68 -> V_138 ;
V_69 = V_75 -> V_68 -> V_69 ;
V_93 = V_75 -> V_68 -> V_93 ;
V_173 = V_75 -> V_68 -> V_89 ;
}
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) )
return - V_7 ;
if ( * V_98 != sizeof( struct V_134 ) + V_138 +
( V_193 . V_176 ? V_69 * sizeof( struct V_71 ) : 0 ) )
return - V_128 ;
if ( V_193 . V_69 != V_69 ) {
F_24 ( L_43 ) ;
return - V_128 ;
}
if ( V_193 . V_138 != V_138 ) {
F_24 ( L_44 ) ;
return - V_128 ;
}
V_126 = F_81 ( V_75 , V_173 , V_193 . V_89 ,
V_193 . V_176 , V_69 ) ;
if ( V_126 )
return V_126 ;
if ( F_4 ( V_193 . V_93 , V_93 , V_138 ) ) {
F_24 ( L_45 ) ;
return - V_7 ;
}
return F_50 ( V_93 , V_138 ,
F_80 , V_93 , V_193 . V_93 ) ;
}
static int F_83 ( struct V_210 * V_211 ,
int V_208 , void T_1 * V_191 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_84 ( V_211 ) ;
if ( ! F_85 ( V_117 -> V_212 , V_213 ) )
return - V_214 ;
switch ( V_208 ) {
case V_215 :
V_126 = F_64 ( V_117 , V_191 , V_98 ) ;
break;
case V_216 :
V_126 = F_76 ( V_117 , V_191 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_86 ( struct V_210 * V_211 , int V_208 , void T_1 * V_191 , int * V_98 )
{
int V_126 ;
struct V_134 V_193 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_84 ( V_211 ) ;
if ( ! F_85 ( V_117 -> V_212 , V_213 ) )
return - V_214 ;
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_193 . V_30 , & V_126 , & V_179 ) ;
if ( ! V_75 )
return V_126 ;
switch ( V_208 ) {
case V_217 :
case V_218 :
if ( * V_98 != sizeof( struct V_134 ) ) {
V_126 = - V_128 ;
F_28 ( & V_179 ) ;
break;
}
if ( V_208 == V_217 ) {
V_193 . V_69 = V_75 -> V_83 -> V_69 ;
V_193 . V_138 = V_75 -> V_83 -> V_138 ;
V_193 . V_139 = V_75 -> V_139 ;
} else {
V_193 . V_69 = V_75 -> V_68 -> V_69 ;
V_193 . V_138 = V_75 -> V_68 -> V_138 ;
V_193 . V_139 = V_75 -> V_68 -> V_139 ;
}
F_28 ( & V_179 ) ;
if ( F_4 ( V_191 , & V_193 , * V_98 ) != 0 ) {
F_24 ( L_46 ) ;
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_209 :
case V_219 :
V_126 = F_82 ( V_75 , V_191 , V_98 , V_208 ) ;
F_28 ( & V_179 ) ;
break;
default:
F_28 ( & V_179 ) ;
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_87 ( void )
{
F_88 ( F_89 ( sizeof( struct V_19 ) ) <
F_90 ( sizeof( struct V_220 ) ) ) ;
return ( int ) F_89 ( sizeof( struct V_19 ) ) -
F_90 ( sizeof( struct V_220 ) ) ;
}
static int F_91 ( const struct V_123 * V_21 ,
unsigned int V_221 )
{
if ( F_92 ( V_21 -> V_222 == - 1 ) )
return F_89 ( V_221 ) - F_90 ( V_221 ) ;
return F_93 ( V_21 ) ;
}
static int F_94 ( struct V_19 * V_20 , void T_1 * * V_223 ,
unsigned int * V_177 )
{
const struct V_123 * V_21 = V_20 -> V_15 . V_21 ;
struct V_220 T_1 * V_224 = * V_223 ;
int V_225 = F_91 ( V_21 , V_20 -> V_127 ) ;
T_4 V_226 = V_20 -> V_127 - V_225 ;
F_95 ( V_225 >= V_20 -> V_127 ) ;
if ( F_4 ( V_224 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_96 ( V_226 , & V_224 -> V_127 ) )
return - V_7 ;
if ( V_21 -> V_227 ) {
if ( V_21 -> V_227 ( V_224 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_224 -> V_18 , V_20 -> V_18 , V_226 ) )
return - V_7 ;
* V_177 -= F_87 () + V_225 ;
* V_223 = V_224 -> V_18 ;
* V_223 += V_226 ;
return 0 ;
}
static int F_97 ( struct V_74 * V_75 ,
void T_1 * * V_223 ,
unsigned int * V_177 )
{
const struct V_132 * V_14 = V_75 -> V_15 . V_14 ;
struct V_220 T_1 * V_224 = * V_223 ;
int V_225 = F_98 ( V_14 ) ;
T_4 V_228 = V_75 -> V_162 - V_225 ;
F_95 ( V_225 >= V_75 -> V_162 ) ;
if ( F_4 ( V_224 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_96 ( V_228 , & V_224 -> V_127 ) )
return - V_7 ;
if ( V_14 -> V_227 ) {
if ( V_14 -> V_227 ( V_224 -> V_18 , V_75 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_224 -> V_18 , V_75 -> V_18 , V_228 ) )
return - V_7 ;
* V_177 -= F_87 () + V_225 ;
* V_223 = V_224 -> V_18 ;
* V_223 += V_228 ;
return 0 ;
}
static int F_99 ( struct V_8 * V_9 ,
void T_1 * * V_223 ,
unsigned int * V_177 )
{
return F_97 ( (struct V_74 * ) V_9 ,
V_223 , V_177 ) ;
}
static int F_100 ( struct V_31 * V_32 , void T_1 * * V_223 ,
unsigned int * V_177 )
{
struct V_74 * V_75 ;
struct V_31 T_1 * V_229 ;
T_5 V_125 , V_99 , V_65 ;
T_4 V_230 ;
int V_126 ;
if ( V_32 -> V_43 == 0 ) {
if ( * V_177 < sizeof( struct V_79 ) )
return - V_128 ;
if ( F_4 ( * V_223 , V_32 , sizeof( struct V_79 ) ) )
return - V_7 ;
* V_223 += sizeof( struct V_79 ) ;
* V_177 -= sizeof( struct V_79 ) ;
return 0 ;
}
if ( * V_177 < sizeof( * V_229 ) )
return - V_128 ;
V_229 = (struct V_31 T_1 * ) * V_223 ;
if ( F_4 ( V_229 , V_32 , sizeof( * V_229 ) ) )
return - V_7 ;
V_230 = * V_177 ;
* V_223 += sizeof( * V_229 ) ;
V_126 = F_20 ( V_32 , F_94 , V_223 , V_177 ) ;
if ( V_126 )
return V_126 ;
V_125 = V_32 -> V_125 - ( V_230 - * V_177 ) ;
V_126 = F_22 ( V_32 , F_99 , V_223 , V_177 ) ;
if ( V_126 )
return V_126 ;
V_99 = V_32 -> V_99 - ( V_230 - * V_177 ) ;
V_75 = (struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_126 = F_97 ( V_75 , V_223 , V_177 ) ;
if ( V_126 )
return V_126 ;
V_65 = V_32 -> V_65 - ( V_230 - * V_177 ) ;
if ( F_96 ( V_125 , & V_229 -> V_125 ) ||
F_96 ( V_99 , & V_229 -> V_99 ) ||
F_96 ( V_65 , & V_229 -> V_65 ) )
return - V_7 ;
* V_177 -= sizeof( * V_229 ) ;
return 0 ;
}
static int F_101 ( struct V_19 * V_20 , int * V_225 )
{
* V_225 += F_91 ( V_20 -> V_15 . V_21 , V_20 -> V_127 ) ;
* V_225 += F_87 () ;
return 0 ;
}
static int F_102 ( struct V_8 * V_9 , int * V_225 )
{
* V_225 += F_98 ( V_9 -> V_15 . V_16 ) ;
* V_225 += F_87 () ;
return 0 ;
}
static int F_103 ( const struct V_31 * V_32 ,
const struct V_82 * V_231 ,
const void * V_81 ,
struct V_232 * V_136 )
{
const struct V_74 * V_75 ;
unsigned int V_233 ;
int V_225 , V_126 , V_28 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_225 = 0 ;
V_233 = ( void * ) V_32 - V_81 ;
F_20 ( V_32 , F_101 , & V_225 ) ;
F_22 ( V_32 , F_102 , & V_225 ) ;
V_75 = ( const struct V_74 * ) ( ( char * ) V_32 + V_32 -> V_99 ) ;
V_225 += F_98 ( V_75 -> V_15 . V_14 ) ;
V_225 += F_87 () ;
V_136 -> V_138 -= V_225 ;
V_126 = F_104 ( V_5 , V_233 , V_225 ) ;
if ( V_126 )
return V_126 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
const void * V_234 = V_231 -> V_91 [ V_28 ] ;
if ( V_231 -> V_91 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_81 - V_234 ) ) ) {
V_136 -> V_91 [ V_28 ] -= V_225 ;
F_105 ( L_47 ,
V_136 -> V_91 [ V_28 ] + V_225 ,
V_136 -> V_91 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_106 ( const struct V_82 * V_231 ,
struct V_232 * V_136 )
{
unsigned int V_177 = V_231 -> V_138 ;
const void * V_93 = V_231 -> V_93 ;
V_136 -> V_138 = V_177 ;
F_107 ( V_5 , V_231 -> V_69 ) ;
return F_50 ( V_93 , V_177 , F_103 , V_231 ,
V_93 , V_136 ) ;
}
static int F_108 ( struct V_67 * V_75 ,
void T_1 * V_191 , int * V_98 , int V_208 )
{
struct V_232 V_135 , V_193 ;
struct V_71 * V_173 ;
struct V_82 V_235 ;
int V_126 ;
void T_1 * V_166 ;
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
if ( V_208 == V_209 ) {
V_235 . V_138 = V_75 -> V_83 -> V_138 ;
V_235 . V_69 = V_75 -> V_83 -> V_69 ;
V_235 . V_93 = V_75 -> V_83 -> V_93 ;
V_173 = V_75 -> V_83 -> V_89 ;
} else {
V_235 . V_138 = V_75 -> V_68 -> V_138 ;
V_235 . V_69 = V_75 -> V_68 -> V_69 ;
V_235 . V_93 = V_75 -> V_68 -> V_93 ;
V_173 = V_75 -> V_68 -> V_89 ;
}
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) )
return - V_7 ;
if ( V_193 . V_69 != V_235 . V_69 ||
( V_193 . V_176 && V_193 . V_176 != V_235 . V_69 ) )
return - V_128 ;
memcpy ( & V_135 , & V_193 , sizeof( V_135 ) ) ;
if ( V_208 == V_209 )
V_126 = F_106 ( V_75 -> V_83 , & V_135 ) ;
else
V_126 = F_106 ( & V_235 , & V_135 ) ;
if ( V_126 )
return V_126 ;
if ( * V_98 != sizeof( V_193 ) + V_135 . V_138 +
( V_193 . V_176 ? V_235 . V_69 * sizeof( struct V_71 ) : 0 ) ) {
F_109 ( L_48 ,
* V_98 , V_235 . V_138 , V_135 . V_138 ) ;
return - V_128 ;
}
V_126 = F_81 ( V_75 , V_173 , F_110 ( V_193 . V_89 ) ,
V_193 . V_176 , V_235 . V_69 ) ;
if ( V_126 )
return V_126 ;
V_166 = F_110 ( V_193 . V_93 ) ;
return F_50 ( V_235 . V_93 , V_235 . V_138 ,
F_100 , & V_166 , & V_193 . V_138 ) ;
}
static int F_111 ( struct V_236 * V_237 , unsigned int V_238 )
{
V_237 -> V_239 += V_238 ;
return V_237 -> V_239 >= V_238 ? 0 : - V_128 ;
}
static int F_112 ( struct V_236 * V_237 ,
void * V_18 , unsigned int V_238 )
{
if ( V_237 -> V_240 == NULL )
goto V_241;
F_95 ( V_237 -> V_239 + V_238 > V_237 -> V_242 ) ;
memcpy ( V_237 -> V_240 + V_237 -> V_239 , V_18 , V_238 ) ;
V_241:
V_237 -> V_243 += V_238 ;
return F_111 ( V_237 , V_238 ) ;
}
static int F_113 ( struct V_236 * V_237 , unsigned int V_238 )
{
char * V_244 = V_237 -> V_240 ;
F_95 ( V_244 && V_237 -> V_239 > V_237 -> V_242 ) ;
if ( V_244 != NULL && V_238 > 0 )
memset ( V_244 + V_237 -> V_239 , 0 , V_238 ) ;
return F_111 ( V_237 , V_238 ) ;
}
static int F_114 ( struct V_220 * V_245 ,
enum V_246 V_246 ,
struct V_236 * V_237 ,
const unsigned char * V_81 )
{
char V_30 [ V_114 ] ;
struct V_123 * V_21 ;
struct V_132 * V_247 ;
void * V_1 = NULL ;
int V_225 , V_248 = 0 ;
unsigned int V_249 , V_127 = V_245 -> V_127 ;
F_78 ( V_30 , V_245 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_237 -> V_240 )
V_1 = V_237 -> V_240 + V_237 -> V_239 ;
switch ( V_246 ) {
case V_250 :
V_21 = F_33 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_225 = F_91 ( V_21 , V_127 ) ;
if ( V_1 ) {
if ( V_21 -> V_251 )
V_21 -> V_251 ( V_1 , V_245 -> V_18 ) ;
else
memcpy ( V_1 , V_245 -> V_18 , V_127 ) ;
}
V_249 = V_21 -> V_222 ;
if ( F_92 ( V_249 == - 1 ) )
V_249 = V_127 ;
F_37 ( V_21 -> V_130 ) ;
break;
case V_252 :
case V_253 :
V_247 = F_39 ( V_5 , V_30 , 0 ) ;
if ( F_34 ( V_247 ) )
return F_35 ( V_247 ) ;
V_225 = F_98 ( V_247 ) ;
if ( V_1 ) {
if ( V_247 -> V_251 )
V_247 -> V_251 ( V_1 , V_245 -> V_18 ) ;
else
memcpy ( V_1 , V_245 -> V_18 , V_127 ) ;
}
V_249 = V_247 -> V_254 ;
F_37 ( V_247 -> V_130 ) ;
break;
default:
return - V_128 ;
}
V_237 -> V_239 += V_127 + V_225 ;
V_237 -> V_243 += V_127 ;
V_248 = F_89 ( V_249 ) - V_249 ;
if ( V_248 > 0 && V_1 ) {
F_95 ( V_237 -> V_242 <= V_248 ) ;
F_95 ( V_237 -> V_239 - ( V_127 + V_225 ) + V_249 > V_237 -> V_242 - V_248 ) ;
memset ( V_1 + V_249 , 0 , V_248 ) ;
}
return V_225 + V_127 ;
}
static int F_115 ( struct V_220 * V_255 ,
unsigned int V_256 , enum V_246 type ,
struct V_236 * V_237 , const void * V_81 )
{
int V_257 = 0 ;
char * V_258 ;
if ( V_256 == 0 )
return 0 ;
V_258 = ( char * ) V_255 ;
while ( V_256 >= sizeof( * V_255 ) ) {
struct V_19 * V_259 ;
int V_126 ;
V_259 = (struct V_19 * ) V_237 -> V_240 ;
if ( V_259 ) {
char * V_193 ;
V_193 = V_237 -> V_240 + V_237 -> V_239 ;
V_259 = (struct V_19 * ) V_193 ;
}
V_126 = F_112 ( V_237 , V_258 , sizeof( * V_255 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_256 -= sizeof( * V_255 ) ;
V_126 = F_113 ( V_237 , F_87 () ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_255 -> V_127 > V_256 )
return - V_128 ;
V_256 -= V_255 -> V_127 ;
V_126 = F_114 ( V_255 , type , V_237 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
F_95 ( V_126 < V_255 -> V_127 ) ;
V_257 += V_126 - V_255 -> V_127 ;
V_257 += F_87 () ;
V_258 += sizeof( * V_255 ) ;
V_258 += V_255 -> V_127 ;
if ( V_259 )
V_259 -> V_127 = V_126 ;
F_116 ( type == V_253 && V_256 ) ;
V_255 = (struct V_220 * ) V_258 ;
}
return V_257 ;
}
static int F_117 ( struct V_31 * V_25 , const unsigned char * V_81 ,
unsigned int * V_260 ,
struct V_236 * V_237 )
{
unsigned int V_28 , V_152 , V_261 , V_262 = 0 ;
unsigned int V_263 [ 4 ] ;
unsigned int * V_264 = NULL ;
int V_126 ;
char * V_265 ;
if ( * V_260 < sizeof( struct V_79 ) )
return - V_128 ;
if ( ! V_25 -> V_43 ) {
* V_260 -= sizeof( struct V_79 ) ;
return F_112 ( V_237 , V_25 , sizeof( struct V_79 ) ) ;
}
if ( * V_260 < sizeof( * V_25 ) || V_25 -> V_65 < sizeof( * V_25 ) )
return - V_128 ;
V_261 = V_237 -> V_243 ;
V_126 = F_112 ( V_237 , V_25 ,
F_118 ( struct V_31 , V_125 ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_263 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_263 [ 1 ] , & V_25 -> V_125 ,
sizeof( V_263 ) - sizeof( V_263 [ 0 ] ) ) ;
if ( V_237 -> V_240 ) {
V_265 = V_237 -> V_240 + V_237 -> V_239 ;
V_264 = ( unsigned int * ) V_265 ;
}
V_126 = F_112 ( V_237 , & V_263 [ 1 ] ,
sizeof( V_263 ) - sizeof( V_263 [ 0 ] ) ) ;
if ( V_126 < 0 )
return V_126 ;
V_265 = ( char * ) V_25 ;
for ( V_28 = 0 , V_152 = 1 ; V_152 < 4 ; V_152 ++ , V_28 ++ ) {
struct V_220 * V_255 ;
unsigned int V_177 ;
char * V_258 = V_265 ;
V_258 = V_265 + V_263 [ V_28 ] ;
if ( V_263 [ V_28 ] > V_263 [ V_152 ] )
return - V_128 ;
V_255 = (struct V_220 * ) V_258 ;
V_177 = V_263 [ V_152 ] - V_263 [ V_28 ] ;
V_126 = F_115 ( V_255 , V_177 , V_28 , V_237 , V_81 ) ;
if ( V_126 < 0 )
return V_126 ;
V_262 += V_126 ;
if ( V_264 && V_262 ) {
F_105 ( L_49 ,
V_264 [ V_28 ] , V_263 [ V_152 ] + V_262 ) ;
V_264 [ V_28 ] = V_263 [ V_152 ] + V_262 ;
}
}
if ( V_237 -> V_240 == NULL ) {
unsigned int V_140 = V_265 - ( char * ) V_81 ;
V_126 = F_104 ( V_5 , V_140 , V_262 ) ;
if ( V_126 < 0 )
return V_126 ;
}
V_261 = V_237 -> V_243 - V_261 ;
F_95 ( * V_260 < V_261 ) ;
* V_260 -= V_261 ;
return 0 ;
}
static int F_119 ( unsigned char * V_18 , unsigned int V_266 ,
struct V_236 * V_237 )
{
unsigned int V_267 = V_266 ;
int V_126 ;
V_126 = F_50 ( V_18 , V_266 , F_117 , V_18 ,
& V_267 , V_237 ) ;
if ( V_126 < 0 )
return V_126 ;
F_116 ( V_267 ) ;
return V_237 -> V_239 ;
}
static int F_120 ( struct V_134 * V_135 ,
void T_1 * V_191 , unsigned int V_98 )
{
struct V_232 V_193 ;
int V_28 ;
if ( V_98 < sizeof( V_193 ) )
return - V_128 ;
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_193 ) + V_193 . V_138 )
return - V_128 ;
if ( V_193 . V_138 == 0 )
return - V_128 ;
if ( V_193 . V_69 >= ( ( V_194 - sizeof( struct V_82 ) ) /
V_195 - V_196 ) / sizeof( struct V_71 ) )
return - V_172 ;
if ( V_193 . V_176 >= V_194 / sizeof( struct V_71 ) )
return - V_172 ;
memcpy ( V_135 , & V_193 , F_118 ( struct V_134 , V_91 ) ) ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ )
V_135 -> V_91 [ V_28 ] = F_110 ( V_193 . V_91 [ V_28 ] ) ;
V_135 -> V_176 = V_193 . V_176 ;
V_135 -> V_89 = F_110 ( V_193 . V_89 ) ;
V_135 -> V_93 = F_110 ( V_193 . V_93 ) ;
return 0 ;
}
static int F_121 ( struct V_117 * V_117 , void T_1 * V_191 ,
unsigned int V_98 )
{
int V_126 , V_28 , V_192 , V_268 ;
struct V_82 * V_136 ;
struct V_134 V_193 ;
struct V_236 V_237 ;
void * V_269 ;
V_126 = F_120 ( & V_193 , V_191 , V_98 ) ;
if ( V_126 ) {
if ( V_126 == - V_128 && F_64 ( V_117 , V_191 , V_98 ) == 0 )
V_126 = 0 ;
return V_126 ;
}
V_192 = F_66 ( V_193 . V_69 ) * V_171 ;
V_136 = F_51 ( sizeof( * V_136 ) + V_192 ) ;
if ( ! V_136 )
return - V_172 ;
if ( V_192 )
memset ( V_136 -> V_89 , 0 , V_192 ) ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_136 -> V_93 = F_51 ( V_193 . V_138 ) ;
if ( ! V_136 -> V_93 ) {
V_126 = - V_172 ;
goto V_197;
}
if ( F_65 (
V_136 -> V_93 , V_193 . V_93 , V_193 . V_138 ) != 0 ) {
V_126 = - V_7 ;
goto V_198;
}
V_269 = V_136 -> V_93 ;
F_122 ( V_5 ) ;
F_107 ( V_5 , V_193 . V_69 ) ;
V_126 = F_119 ( V_269 , V_193 . V_138 , & V_237 ) ;
if ( V_126 < 0 )
goto V_270;
F_105 ( L_50 ,
V_193 . V_138 , V_237 . V_239 , V_237 . V_243 ,
F_2 ( V_5 , V_193 . V_138 ) ) ;
V_268 = V_126 ;
V_136 -> V_93 = F_51 ( V_268 ) ;
if ( ! V_136 -> V_93 ) {
F_53 ( V_269 ) ;
V_126 = - V_172 ;
goto V_270;
}
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_240 = V_136 -> V_93 ;
V_237 . V_242 = V_268 ;
V_126 = F_119 ( V_269 , V_193 . V_138 , & V_237 ) ;
F_95 ( V_126 < 0 ) ;
F_53 ( V_269 ) ;
V_193 . V_138 = V_268 ;
for ( V_28 = 0 ; V_28 < V_141 ; V_28 ++ ) {
char T_1 * V_271 ;
if ( V_193 . V_91 [ V_28 ] ) {
unsigned int V_272 ;
V_271 = ( char T_1 * ) V_193 . V_91 [ V_28 ] ;
V_272 = V_271 - V_193 . V_93 ;
V_271 += F_2 ( V_5 , V_272 ) ;
V_193 . V_91 [ V_28 ] = (struct V_79 T_1 * ) V_271 ;
}
}
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
V_126 = F_55 ( V_117 , & V_193 , V_136 ) ;
if ( V_126 == 0 )
return V_126 ;
V_198:
F_53 ( V_136 -> V_93 ) ;
V_197:
F_53 ( V_136 ) ;
return V_126 ;
V_270:
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
goto V_198;
}
static int F_125 ( struct V_117 * V_117 , void T_1 * V_191 ,
unsigned int V_98 )
{
struct V_232 V_206 ;
if ( F_65 ( & V_206 , V_191 , sizeof( V_206 ) ) )
return - V_7 ;
if ( V_98 != sizeof( V_206 ) + V_206 . V_176 * sizeof( struct V_71 ) )
return F_76 ( V_117 , V_191 , V_98 ) ;
return F_75 ( V_117 , V_206 . V_30 , F_110 ( V_206 . V_89 ) ,
V_206 . V_176 , V_191 , V_98 ) ;
}
static int F_126 ( struct V_210 * V_211 ,
int V_208 , void T_1 * V_191 , unsigned int V_98 )
{
int V_126 ;
struct V_117 * V_117 = F_84 ( V_211 ) ;
if ( ! F_85 ( V_117 -> V_212 , V_213 ) )
return - V_214 ;
switch ( V_208 ) {
case V_215 :
V_126 = F_121 ( V_117 , V_191 , V_98 ) ;
break;
case V_216 :
V_126 = F_125 ( V_117 , V_191 , V_98 ) ;
break;
default:
V_126 = - V_128 ;
}
return V_126 ;
}
static int F_127 ( struct V_210 * V_211 , int V_208 ,
void T_1 * V_191 , int * V_98 )
{
int V_126 ;
struct V_232 V_193 ;
struct V_67 * V_75 ;
struct V_117 * V_117 = F_84 ( V_211 ) ;
if ( ! F_85 ( V_117 -> V_212 , V_213 ) )
return - V_214 ;
if ( ( V_208 == V_217 ||
V_208 == V_218 ) && * V_98 != sizeof( V_193 ) )
return F_86 ( V_211 , V_208 , V_191 , V_98 ) ;
if ( F_65 ( & V_193 , V_191 , sizeof( V_193 ) ) )
return - V_7 ;
V_75 = F_31 ( V_117 , V_193 . V_30 , & V_126 , & V_179 ) ;
if ( ! V_75 )
return V_126 ;
F_122 ( V_5 ) ;
switch ( V_208 ) {
case V_217 :
V_193 . V_69 = V_75 -> V_83 -> V_69 ;
V_126 = F_106 ( V_75 -> V_83 , & V_193 ) ;
if ( V_126 )
goto V_34;
V_193 . V_139 = V_75 -> V_139 ;
if ( F_4 ( V_191 , & V_193 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_218 :
V_193 . V_69 = V_75 -> V_68 -> V_69 ;
V_193 . V_138 = V_75 -> V_68 -> V_138 ;
V_193 . V_139 = V_75 -> V_68 -> V_139 ;
if ( F_4 ( V_191 , & V_193 , * V_98 ) != 0 ) {
V_126 = - V_7 ;
break;
}
V_126 = 0 ;
break;
case V_209 :
case V_219 :
if ( F_82 ( V_75 , V_191 , V_98 , V_208 ) == 0 )
V_126 = 0 ;
else
V_126 = F_108 ( V_75 , V_191 , V_98 , V_208 ) ;
break;
default:
V_126 = - V_128 ;
}
V_34:
F_123 ( V_5 ) ;
F_124 ( V_5 ) ;
F_28 ( & V_179 ) ;
return V_126 ;
}
static int T_6 F_128 ( void )
{
int V_126 ;
V_126 = F_129 ( & V_100 ) ;
if ( V_126 < 0 )
return V_126 ;
V_126 = F_130 ( & V_273 ) ;
if ( V_126 < 0 ) {
F_131 ( & V_100 ) ;
return V_126 ;
}
F_132 ( V_274 L_51 ) ;
return 0 ;
}
static void T_7 F_133 ( void )
{
F_134 ( & V_273 ) ;
F_131 ( & V_100 ) ;
F_132 ( V_274 L_52 ) ;
}
