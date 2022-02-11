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
if ( F_12 ( F_13 ( V_39 ) >= 1536 , V_45 ) )
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
unsigned int F_15 ( unsigned int V_65 , struct V_10 * V_11 ,
const struct V_26 * V_33 , const struct V_26 * V_34 ,
struct V_66 * V_67 )
{
int V_28 , V_68 ;
struct V_31 * V_69 ;
struct V_70 * V_71 , * V_72 ;
const struct V_73 * V_74 ;
int V_40 , V_75 = 0 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
const char * V_80 ;
const struct V_81 * V_82 ;
struct V_12 V_83 ;
V_83 . V_84 = V_5 ;
V_83 . V_33 = V_33 ;
V_83 . V_34 = V_34 ;
V_83 . V_85 = false ;
V_83 . V_86 = V_65 ;
F_16 ( & V_67 -> V_87 ) ;
V_82 = V_67 -> V_82 ;
V_72 = F_17 ( V_82 -> V_88 , V_82 -> V_68 ,
F_18 () ) ;
if ( V_82 -> V_89 )
V_77 = V_82 -> V_89 [ F_18 () ] ;
else
V_77 = NULL ;
V_79 = V_82 -> V_90 [ V_65 ] ;
V_68 = V_82 -> V_90 [ V_65 ] -> V_68 ;
V_69 = (struct V_31 * ) ( V_82 -> V_90 [ V_65 ] -> V_18 ) ;
V_71 = V_72 + V_82 -> V_90 [ V_65 ] -> V_91 ;
V_80 = V_82 -> V_92 ;
V_28 = 0 ;
while ( V_28 < V_68 ) {
if ( F_8 ( V_69 , V_11 , V_33 , V_34 ) )
goto V_93;
if ( F_19 ( V_69 , F_6 , V_11 , & V_83 ) != 0 )
goto V_93;
if ( V_83 . V_85 ) {
F_20 ( & V_67 -> V_87 ) ;
return V_94 ;
}
( * ( V_71 + V_28 ) ) . V_95 ++ ;
( * ( V_71 + V_28 ) ) . V_96 += V_11 -> V_97 ;
F_21 ( V_69 , F_5 , V_11 , & V_83 ) ;
V_74 = (struct V_73 * )
( ( ( char * ) V_69 ) + V_69 -> V_98 ) ;
if ( ! V_74 -> V_15 . V_14 -> V_14 )
V_40 = ( (struct V_99 * ) V_74 ) -> V_40 ;
else {
V_83 . V_14 = V_74 -> V_15 . V_14 ;
V_83 . V_17 = V_74 -> V_18 ;
V_40 = V_74 -> V_15 . V_14 -> V_14 ( V_11 , & V_83 ) ;
}
if ( V_40 == V_100 ) {
F_20 ( & V_67 -> V_87 ) ;
return V_101 ;
}
if ( V_40 == V_102 ) {
F_20 ( & V_67 -> V_87 ) ;
return V_94 ;
}
if ( V_40 == V_103 ) {
V_104:
#ifdef F_22
if ( V_75 == 0 ) {
F_23 ( L_1 ) ;
goto V_93;
}
#endif
V_75 -- ;
V_28 = V_77 [ V_75 ] . V_105 ;
V_79 = V_77 [ V_75 ] . V_79 ;
V_68 = V_79 -> V_68 ;
V_69 = V_77 [ V_75 ] . V_32 ;
V_71 = V_72 +
V_79 -> V_91 ;
continue;
}
if ( V_40 == V_106 )
goto V_93;
#ifdef F_22
if ( V_40 < 0 ) {
F_23 ( L_2 ) ;
F_20 ( & V_67 -> V_87 ) ;
return V_94 ;
}
#endif
V_77 [ V_75 ] . V_105 = V_28 + 1 ;
V_77 [ V_75 ] . V_79 = V_79 ;
V_77 [ V_75 ] . V_32 = F_24 ( V_69 ) ;
V_28 = 0 ;
V_79 = (struct V_78 * ) ( V_80 + V_40 ) ;
#ifdef F_22
if ( V_79 -> V_107 ) {
F_23 ( L_3 ) ;
F_20 ( & V_67 -> V_87 ) ;
return V_94 ;
}
#endif
V_68 = V_79 -> V_68 ;
V_69 = (struct V_31 * ) V_79 -> V_18 ;
V_71 = V_72 + V_79 -> V_91 ;
V_75 ++ ;
continue;
V_93:
V_69 = F_24 ( V_69 ) ;
V_28 ++ ;
}
if ( V_79 -> V_108 == V_103 )
goto V_104;
if ( V_79 -> V_108 == V_100 ) {
F_20 ( & V_67 -> V_87 ) ;
return V_101 ;
}
F_20 ( & V_67 -> V_87 ) ;
return V_94 ;
}
static inline void *
F_25 ( struct V_109 * V_110 , const char * V_30 , int * error ,
struct V_111 * V_111 )
{
struct {
struct V_109 V_112 ;
char V_30 [ V_113 ] ;
} * V_32 ;
* error = F_26 ( V_111 ) ;
if ( * error != 0 )
return NULL ;
F_27 (e, head, list) {
if ( strcmp ( V_32 -> V_30 , V_30 ) == 0 )
return V_32 ;
}
* error = - V_114 ;
F_28 ( V_111 ) ;
return NULL ;
}
static void *
F_29 ( struct V_109 * V_110 , const char * V_30 , const char * V_115 ,
int * error , struct V_111 * V_111 )
{
return F_30 (
F_25 ( V_110 , V_30 , error , V_111 ) ,
L_4 , V_115 , V_30 ) ;
}
static inline struct V_66 *
F_31 ( struct V_116 * V_116 , const char * V_30 , int * error ,
struct V_111 * V_111 )
{
return F_29 ( & V_116 -> V_117 . V_118 [ V_5 ] , V_30 ,
L_5 , error , V_111 ) ;
}
static inline int
F_32 ( struct V_19 * V_20 , struct V_119 * V_13 ,
unsigned int * V_120 )
{
const struct V_31 * V_32 = V_13 -> V_121 ;
struct V_122 * V_21 ;
T_3 V_123 = ( ( char * ) V_32 + V_32 -> V_124 ) - ( char * ) V_20 ;
int V_125 ;
if ( V_123 < sizeof( struct V_19 ) ||
V_123 - sizeof( struct V_19 ) < V_20 -> V_126 )
return - V_127 ;
V_21 = F_33 ( V_5 , V_20 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_20 -> V_15 . V_21 = V_21 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_20 -> V_18 ;
V_125 = F_36 ( V_13 , V_20 -> V_126 ,
V_32 -> V_39 , V_32 -> V_128 & V_45 ) ;
if ( V_125 < 0 ) {
F_37 ( V_21 -> V_129 ) ;
return V_125 ;
}
( * V_120 ) ++ ;
return 0 ;
}
static inline int
F_38 ( struct V_8 * V_9 , struct V_130 * V_13 ,
unsigned int * V_120 )
{
const struct V_31 * V_32 = V_13 -> V_121 ;
struct V_131 * V_16 ;
T_3 V_123 = ( ( char * ) V_32 + V_32 -> V_98 ) - ( char * ) V_9 ;
int V_125 ;
if ( V_123 < sizeof( struct V_8 ) ||
V_123 - sizeof( struct V_8 ) < V_9 -> V_132 )
return - V_127 ;
V_16 = F_39 ( V_5 , V_9 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_16 ) )
return F_35 ( V_16 ) ;
V_9 -> V_15 . V_16 = V_16 ;
V_13 -> V_14 = V_16 ;
V_13 -> V_17 = V_9 -> V_18 ;
V_125 = F_40 ( V_13 , V_9 -> V_132 ,
V_32 -> V_39 , V_32 -> V_128 & V_45 ) ;
if ( V_125 < 0 ) {
F_37 ( V_16 -> V_129 ) ;
return V_125 ;
}
( * V_120 ) ++ ;
return 0 ;
}
static int F_41 ( const struct V_133 * V_134 ,
struct V_81 * V_135 )
{
unsigned int V_136 = V_134 -> V_137 ;
unsigned int V_138 = V_134 -> V_138 ;
unsigned int V_139 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ )
V_135 -> V_90 [ V_28 ] = NULL ;
V_135 -> V_137 = V_134 -> V_137 ;
V_135 -> V_68 = V_134 -> V_68 ;
while ( V_139 < V_136 ) {
T_3 V_123 = V_136 - V_139 ;
struct V_31 * V_32 = ( void * ) V_135 -> V_92 + V_139 ;
if ( V_123 < sizeof( unsigned int ) )
break;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( ( V_138 & ( 1 << V_28 ) ) == 0 )
continue;
if ( ( char T_1 * ) V_134 -> V_90 [ V_28 ] ==
V_134 -> V_92 + V_139 )
break;
}
if ( V_28 != V_140 || ! ( V_32 -> V_43 & V_141 ) ) {
if ( V_32 -> V_43 != 0 ) {
F_23 ( L_6
L_7 ) ;
return - V_127 ;
}
if ( V_28 != V_140 )
V_135 -> V_90 [ V_28 ] = (struct V_78 * ) V_32 ;
if ( V_123 < sizeof( struct V_78 ) )
break;
V_139 += sizeof( struct V_78 ) ;
} else {
if ( V_123 < sizeof( struct V_31 ) )
break;
if ( V_123 < V_32 -> V_142 )
break;
if ( V_32 -> V_142 < sizeof( struct V_31 ) )
return - V_127 ;
V_139 += V_32 -> V_142 ;
}
}
if ( V_139 != V_136 ) {
F_23 ( L_8 ) ;
return - V_127 ;
}
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( ! V_135 -> V_90 [ V_28 ] &&
( V_138 & ( 1 << V_28 ) ) ) {
F_23 ( L_9 ) ;
return - V_127 ;
}
}
return 0 ;
}
static inline int
F_42 ( const struct V_31 * V_32 ,
const struct V_81 * V_135 ,
unsigned int * V_105 , unsigned int * V_120 ,
unsigned int * V_143 , unsigned int * V_144 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( ( void * ) V_32 == ( void * ) V_135 -> V_90 [ V_28 ] )
break;
}
if ( V_28 != V_140 || ! V_32 -> V_43 ) {
if ( * V_105 != * V_120 ) {
F_23 ( L_10
L_11 ) ;
return - V_127 ;
}
if ( ( (struct V_78 * ) V_32 ) -> V_108 != V_102 &&
( (struct V_78 * ) V_32 ) -> V_108 != V_100 ) {
if ( V_28 != V_140 ||
( (struct V_78 * ) V_32 ) -> V_108 != V_103 ) {
F_23 ( L_12 ) ;
return - V_127 ;
}
}
if ( V_28 == V_140 )
( * V_144 ) ++ ;
if ( ( (struct V_78 * ) V_32 ) -> V_91 != * V_143 ) {
F_23 ( L_13 ) ;
return - V_127 ;
}
* V_105 = ( (struct V_78 * ) V_32 ) -> V_68 ;
* V_120 = 0 ;
return 0 ;
}
if ( sizeof( struct V_31 ) > V_32 -> V_124 ||
V_32 -> V_124 > V_32 -> V_98 ||
V_32 -> V_98 >= V_32 -> V_142 ) {
F_23 ( L_14 ) ;
return - V_127 ;
}
if ( V_32 -> V_142 - V_32 -> V_98 < sizeof( struct V_73 ) ) {
F_23 ( L_15 ) ;
return - V_127 ;
}
( * V_120 ) ++ ;
( * V_143 ) ++ ;
return 0 ;
}
static inline int
F_43 ( struct V_31 * V_32 , struct V_81 * V_135 ,
unsigned int * V_105 , struct V_145 * V_146 )
{
int V_28 ;
if ( V_32 -> V_43 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( V_135 -> V_90 [ V_28 ] == (struct V_78 * ) V_32 )
break;
}
if ( V_28 != V_140 )
return 0 ;
V_146 [ * V_105 ] . V_77 . V_79 = (struct V_78 * ) V_32 ;
V_146 [ * V_105 ] . V_77 . V_105 = 0 ;
V_146 [ * V_105 ] . V_147 = 0 ;
( * V_105 ) ++ ;
return 0 ;
}
static inline int
F_44 ( struct V_19 * V_20 , struct V_116 * V_116 , unsigned int * V_28 )
{
struct V_148 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_116 = V_116 ;
V_13 . V_21 = V_20 -> V_15 . V_21 ;
V_13 . V_22 = V_20 -> V_18 ;
V_13 . V_84 = V_5 ;
if ( V_13 . V_21 -> V_149 != NULL )
V_13 . V_21 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_21 -> V_129 ) ;
return 0 ;
}
static inline int
F_45 ( struct V_8 * V_9 , struct V_116 * V_116 , unsigned int * V_28 )
{
struct V_150 V_13 ;
if ( V_28 && ( * V_28 ) -- == 0 )
return 1 ;
V_13 . V_116 = V_116 ;
V_13 . V_14 = V_9 -> V_15 . V_16 ;
V_13 . V_17 = V_9 -> V_18 ;
V_13 . V_84 = V_5 ;
if ( V_13 . V_14 -> V_149 != NULL )
V_13 . V_14 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_129 ) ;
return 0 ;
}
static inline int
F_46 ( struct V_31 * V_32 , struct V_116 * V_116 , unsigned int * V_120 )
{
struct V_150 V_13 ;
struct V_73 * V_74 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_120 && ( * V_120 ) -- == 0 )
return 1 ;
F_21 ( V_32 , F_45 , V_116 , NULL ) ;
F_19 ( V_32 , F_44 , V_116 , NULL ) ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_32 ) + V_32 -> V_98 ) ;
V_13 . V_116 = V_116 ;
V_13 . V_14 = V_74 -> V_15 . V_14 ;
V_13 . V_17 = V_74 -> V_18 ;
V_13 . V_84 = V_5 ;
if ( V_13 . V_14 -> V_149 != NULL )
V_13 . V_14 -> V_149 ( & V_13 ) ;
F_37 ( V_13 . V_14 -> V_129 ) ;
return 0 ;
}
static inline int
F_47 ( struct V_31 * V_32 , struct V_116 * V_116 ,
const struct V_81 * V_135 ,
const char * V_30 , unsigned int * V_120 ,
struct V_145 * V_151 , unsigned int V_144 )
{
struct V_73 * V_74 ;
struct V_131 * V_14 ;
unsigned int V_28 , V_152 , V_65 = 0 , V_147 = 0 ;
T_3 V_153 ;
int V_125 ;
struct V_119 V_154 ;
struct V_130 V_155 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
if ( V_32 -> V_43 & ~ V_156 ) {
F_23 ( L_16 ) ;
return - V_127 ;
}
if ( V_32 -> V_128 & ~ V_157 ) {
F_23 ( L_17 ) ;
return - V_127 ;
}
if ( ( V_32 -> V_43 & V_46 ) && ( V_32 -> V_43 & V_44 ) ) {
F_23 ( L_18 ) ;
return - V_127 ;
}
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( ! V_135 -> V_90 [ V_28 ] )
continue;
if ( ( char * ) V_135 -> V_90 [ V_28 ] < ( char * ) V_32 )
V_65 = V_28 ;
else
break;
}
if ( V_28 < V_140 )
V_147 = ( 1 << V_65 ) | ( 1 << V_140 ) ;
else {
for ( V_28 = 0 ; V_28 < V_144 ; V_28 ++ )
if ( ( char * ) ( V_151 [ V_28 ] . V_77 . V_79 ) > ( char * ) V_32 )
break;
if ( V_28 == 0 )
V_147 = ( 1 << V_65 ) | ( 1 << V_140 ) ;
else
V_147 = V_151 [ V_28 - 1 ] . V_147 ;
}
V_28 = 0 ;
V_154 . V_116 = V_155 . V_116 = V_116 ;
V_154 . V_67 = V_155 . V_67 = V_30 ;
V_154 . V_121 = V_155 . V_121 = V_32 ;
V_154 . V_158 = V_155 . V_158 = V_147 ;
V_154 . V_84 = V_155 . V_84 = V_5 ;
V_125 = F_19 ( V_32 , F_32 , & V_154 , & V_28 ) ;
if ( V_125 != 0 )
goto V_159;
V_152 = 0 ;
V_125 = F_21 ( V_32 , F_38 , & V_155 , & V_152 ) ;
if ( V_125 != 0 )
goto V_160;
V_74 = (struct V_73 * ) ( ( ( char * ) V_32 ) + V_32 -> V_98 ) ;
V_153 = V_32 -> V_142 - V_32 -> V_98 ;
V_14 = F_39 ( V_5 , V_74 -> V_15 . V_30 , 0 ) ;
if ( F_34 ( V_14 ) ) {
V_125 = F_35 ( V_14 ) ;
goto V_160;
}
V_74 -> V_15 . V_14 = V_14 ;
if ( V_74 -> V_15 . V_14 == & V_99 ) {
if ( V_153 < sizeof( struct V_99 ) ) {
F_23 ( L_19 ) ;
V_125 = - V_7 ;
goto V_160;
}
if ( ( (struct V_99 * ) V_74 ) -> V_40 <
- V_161 ) {
F_23 ( L_20 ) ;
V_125 = - V_7 ;
goto V_160;
}
} else if ( V_74 -> V_162 > V_153 - sizeof( struct V_73 ) ) {
F_37 ( V_74 -> V_15 . V_14 -> V_129 ) ;
V_125 = - V_7 ;
goto V_160;
}
V_155 . V_14 = V_14 ;
V_155 . V_17 = V_74 -> V_18 ;
V_125 = F_40 ( & V_155 , V_74 -> V_162 ,
V_32 -> V_39 , V_32 -> V_128 & V_45 ) ;
if ( V_125 < 0 ) {
F_37 ( V_14 -> V_129 ) ;
goto V_160;
}
( * V_120 ) ++ ;
return 0 ;
V_160:
F_21 ( V_32 , F_45 , V_116 , & V_152 ) ;
V_159:
F_19 ( V_32 , F_44 , V_116 , & V_28 ) ;
return V_125 ;
}
static int F_48 ( const struct V_78 * V_163 , struct V_145 * V_151 ,
unsigned int V_144 , unsigned int V_164 , char * V_80 )
{
int V_28 , V_165 = - 1 , V_166 = 0 , V_68 = V_163 -> V_68 , V_40 ;
const struct V_31 * V_32 = (struct V_31 * ) V_163 -> V_18 ;
const struct V_73 * V_74 ;
while ( V_166 < V_68 || V_165 != - 1 ) {
if ( V_166 == V_68 ) {
V_32 = V_151 [ V_165 ] . V_77 . V_32 ;
if ( V_151 [ V_165 ] . V_167 != - 1 )
V_68 =
V_151 [ V_151 [ V_165 ] . V_167 ] . V_77 . V_79 -> V_68 ;
else
V_68 = V_163 -> V_68 ;
V_166 = V_151 [ V_165 ] . V_77 . V_105 ;
V_151 [ V_165 ] . V_77 . V_105 = 0 ;
V_165 = V_151 [ V_165 ] . V_167 ;
if ( V_166 == V_68 )
continue;
}
V_74 = (struct V_73 * )
( ( ( char * ) V_32 ) + V_32 -> V_98 ) ;
if ( strcmp ( V_74 -> V_15 . V_30 , V_168 ) )
goto V_93;
if ( V_32 -> V_98 + sizeof( struct V_99 ) >
V_32 -> V_142 ) {
F_23 ( L_19 ) ;
return - 1 ;
}
V_40 = ( (struct V_99 * ) V_74 ) -> V_40 ;
if ( V_40 >= 0 ) {
struct V_78 * V_169 =
(struct V_78 * ) ( V_80 + V_40 ) ;
for ( V_28 = 0 ; V_28 < V_144 ; V_28 ++ )
if ( V_169 == V_151 [ V_28 ] . V_77 . V_79 )
break;
if ( V_28 == V_144 ) {
F_23 ( L_21 ) ;
return - 1 ;
}
if ( V_151 [ V_28 ] . V_77 . V_105 ) {
F_23 ( L_22 ) ;
return - 1 ;
}
if ( V_151 [ V_28 ] . V_147 & ( 1 << V_164 ) )
goto V_93;
V_151 [ V_28 ] . V_77 . V_105 = V_166 + 1 ;
V_166 = 0 ;
V_151 [ V_28 ] . V_77 . V_32 = F_24 ( V_32 ) ;
V_32 = (struct V_31 * ) ( V_169 -> V_18 ) ;
V_68 = V_169 -> V_68 ;
V_151 [ V_28 ] . V_167 = V_165 ;
V_165 = V_28 ;
V_151 [ V_28 ] . V_147 |= ( 1 << V_164 ) ;
continue;
}
V_93:
V_32 = F_24 ( V_32 ) ;
V_166 ++ ;
}
return 0 ;
}
static int F_49 ( struct V_116 * V_116 , const char * V_30 ,
struct V_81 * V_135 )
{
unsigned int V_28 , V_152 , V_170 , V_144 ;
int V_125 ;
struct V_145 * V_151 = NULL ;
V_28 = 0 ;
while ( V_28 < V_140 && ! V_135 -> V_90 [ V_28 ] )
V_28 ++ ;
if ( V_28 == V_140 ) {
F_23 ( L_23 ) ;
return - V_127 ;
}
if ( V_135 -> V_90 [ V_28 ] != (struct V_78 * ) V_135 -> V_92 ) {
F_23 ( L_24 ) ;
return - V_127 ;
}
for ( V_152 = V_28 + 1 ; V_152 < V_140 ; V_152 ++ ) {
if ( ! V_135 -> V_90 [ V_152 ] )
continue;
if ( V_135 -> V_90 [ V_152 ] <= V_135 -> V_90 [ V_28 ] ) {
F_23 ( L_25 ) ;
return - V_127 ;
}
V_28 = V_152 ;
}
V_28 = 0 ;
V_152 = 0 ;
V_170 = 0 ;
V_144 = 0 ;
V_125 = F_50 ( V_135 -> V_92 , V_135 -> V_137 ,
F_42 , V_135 ,
& V_28 , & V_152 , & V_170 , & V_144 ) ;
if ( V_125 != 0 )
return V_125 ;
if ( V_28 != V_152 ) {
F_23 ( L_26
L_27 ) ;
return - V_127 ;
}
if ( V_170 != V_135 -> V_68 ) {
F_23 ( L_28 ) ;
return - V_127 ;
}
if ( V_144 ) {
V_135 -> V_89 =
F_51 ( V_171 * sizeof( * ( V_135 -> V_89 ) ) ) ;
if ( ! V_135 -> V_89 )
return - V_172 ;
F_52 (i) {
V_135 -> V_89 [ V_28 ] =
F_51 ( V_144 * sizeof( * ( V_135 -> V_89 [ 0 ] ) ) ) ;
if ( ! V_135 -> V_89 [ V_28 ] ) {
while ( V_28 )
F_53 ( V_135 -> V_89 [ -- V_28 ] ) ;
F_53 ( V_135 -> V_89 ) ;
V_135 -> V_89 = NULL ;
return - V_172 ;
}
}
V_151 = F_51 ( V_144 * sizeof( * V_151 ) ) ;
if ( ! V_151 )
return - V_172 ;
V_28 = 0 ;
F_50 ( V_135 -> V_92 , V_135 -> V_137 ,
F_43 , V_135 , & V_28 , V_151 ) ;
if ( V_28 != V_144 ) {
F_23 ( L_29 ) ;
F_53 ( V_151 ) ;
return - V_7 ;
}
}
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ )
if ( V_135 -> V_90 [ V_28 ] )
if ( F_48 ( V_135 -> V_90 [ V_28 ] ,
V_151 , V_144 , V_28 , V_135 -> V_92 ) ) {
F_53 ( V_151 ) ;
return - V_127 ;
}
V_28 = 0 ;
V_125 = F_50 ( V_135 -> V_92 , V_135 -> V_137 ,
F_47 , V_116 , V_135 , V_30 , & V_28 , V_151 , V_144 ) ;
if ( V_125 != 0 ) {
F_50 ( V_135 -> V_92 , V_135 -> V_137 ,
F_46 , V_116 , & V_28 ) ;
}
F_53 ( V_151 ) ;
return V_125 ;
}
static void F_54 ( const struct V_70 * V_173 ,
struct V_70 * V_88 , unsigned int V_68 )
{
int V_28 , V_174 ;
struct V_70 * V_71 ;
memcpy ( V_88 , V_173 ,
sizeof( struct V_70 ) * V_68 ) ;
F_52 (cpu) {
if ( V_174 == 0 )
continue;
V_71 = F_17 ( V_173 , V_68 , V_174 ) ;
for ( V_28 = 0 ; V_28 < V_68 ; V_28 ++ ) {
V_88 [ V_28 ] . V_95 += V_71 [ V_28 ] . V_95 ;
V_88 [ V_28 ] . V_96 += V_71 [ V_28 ] . V_96 ;
}
}
}
static int F_55 ( struct V_116 * V_116 , struct V_133 * V_134 ,
struct V_81 * V_135 )
{
int V_125 , V_28 ;
struct V_70 * V_175 = NULL ;
struct V_81 * V_67 ;
struct V_66 * V_74 ;
if ( V_134 -> V_176 ) {
unsigned long V_177 = V_134 -> V_176 * sizeof( * V_175 ) ;
V_175 = F_51 ( V_177 ) ;
if ( ! V_175 )
return - V_172 ;
}
V_135 -> V_89 = NULL ;
V_125 = F_41 ( V_134 , V_135 ) ;
if ( V_125 != 0 )
goto V_178;
V_125 = F_49 ( V_116 , V_134 -> V_30 , V_135 ) ;
if ( V_125 != 0 )
goto V_178;
V_74 = F_31 ( V_116 , V_134 -> V_30 , & V_125 , & V_179 ) ;
if ( ! V_74 ) {
V_125 = - V_114 ;
goto V_180;
}
if ( V_74 -> V_181 && ( V_125 = V_74 -> V_181 ( V_135 , V_134 -> V_138 ) ) )
goto V_182;
if ( V_134 -> V_176 && V_134 -> V_176 != V_74 -> V_82 -> V_68 ) {
F_23 ( L_30 ) ;
V_125 = - V_127 ;
goto V_182;
}
V_67 = V_74 -> V_82 ;
if ( ! V_67 -> V_68 && V_135 -> V_68 && ! F_56 ( V_74 -> V_129 ) ) {
V_125 = - V_114 ;
goto V_182;
} else if ( V_67 -> V_68 && ! V_135 -> V_68 )
F_37 ( V_74 -> V_129 ) ;
F_57 ( & V_74 -> V_87 ) ;
if ( V_134 -> V_176 )
F_54 ( V_74 -> V_82 -> V_88 , V_175 ,
V_74 -> V_82 -> V_68 ) ;
V_74 -> V_82 = V_135 ;
F_58 ( & V_74 -> V_87 ) ;
F_28 ( & V_179 ) ;
if ( V_134 -> V_176 &&
F_4 ( V_134 -> V_88 , V_175 ,
V_134 -> V_176 * sizeof( struct V_70 ) ) ) {
V_125 = - V_7 ;
}
else
V_125 = 0 ;
F_50 ( V_67 -> V_92 , V_67 -> V_137 ,
F_46 , V_116 , NULL ) ;
F_53 ( V_67 -> V_92 ) ;
if ( V_67 -> V_89 ) {
F_52 (i)
F_53 ( V_67 -> V_89 [ V_28 ] ) ;
F_53 ( V_67 -> V_89 ) ;
}
F_53 ( V_67 ) ;
F_53 ( V_175 ) ;
return V_125 ;
V_182:
F_28 ( & V_179 ) ;
V_180:
F_50 ( V_135 -> V_92 , V_135 -> V_137 ,
F_46 , V_116 , NULL ) ;
V_178:
F_53 ( V_175 ) ;
if ( V_135 -> V_89 ) {
F_52 (i)
F_53 ( V_135 -> V_89 [ V_28 ] ) ;
F_53 ( V_135 -> V_89 ) ;
}
return V_125 ;
}
static int F_59 ( struct V_116 * V_116 , const void T_1 * V_183 ,
unsigned int V_97 )
{
int V_125 , V_184 ;
struct V_81 * V_135 ;
struct V_133 V_185 ;
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) != 0 )
return - V_7 ;
if ( V_97 != sizeof( V_185 ) + V_185 . V_137 ) {
F_23 ( L_31 ) ;
return - V_127 ;
}
if ( V_185 . V_137 == 0 ) {
F_23 ( L_32 ) ;
return - V_127 ;
}
if ( V_185 . V_68 >= ( ( V_186 - sizeof( struct V_81 ) ) /
V_187 - V_188 ) / sizeof( struct V_70 ) )
return - V_172 ;
if ( V_185 . V_176 >= V_186 / sizeof( struct V_70 ) )
return - V_172 ;
V_185 . V_30 [ sizeof( V_185 . V_30 ) - 1 ] = 0 ;
V_184 = F_61 ( V_185 . V_68 ) * V_171 ;
V_135 = F_51 ( sizeof( * V_135 ) + V_184 ) ;
if ( ! V_135 )
return - V_172 ;
if ( V_184 )
memset ( V_135 -> V_88 , 0 , V_184 ) ;
V_135 -> V_92 = F_51 ( V_185 . V_137 ) ;
if ( ! V_135 -> V_92 ) {
V_125 = - V_172 ;
goto V_189;
}
if ( F_60 (
V_135 -> V_92 , V_185 . V_92 , V_185 . V_137 ) != 0 ) {
F_23 ( L_33 ) ;
V_125 = - V_7 ;
goto V_190;
}
V_125 = F_55 ( V_116 , & V_185 , V_135 ) ;
if ( V_125 == 0 )
return V_125 ;
V_190:
F_53 ( V_135 -> V_92 ) ;
V_189:
F_53 ( V_135 ) ;
return V_125 ;
}
struct V_66 *
F_62 ( struct V_116 * V_116 , const struct V_66 * V_191 )
{
struct V_81 * V_135 ;
struct V_66 * V_74 , * V_67 ;
struct V_192 * V_134 ;
int V_125 , V_28 , V_184 ;
void * V_38 ;
if ( V_191 == NULL || ( V_134 = V_191 -> V_67 ) == NULL ||
V_134 -> V_92 == NULL || V_134 -> V_137 == 0 ||
V_134 -> V_88 != NULL || V_191 -> V_82 != NULL ) {
F_23 ( L_34 ) ;
return F_63 ( - V_127 ) ;
}
V_67 = F_64 ( V_191 , sizeof( struct V_66 ) , V_193 ) ;
if ( ! V_67 ) {
V_125 = - V_172 ;
goto V_34;
}
V_184 = F_61 ( V_134 -> V_68 ) * V_171 ;
V_135 = F_51 ( sizeof( * V_135 ) + V_184 ) ;
V_125 = - V_172 ;
if ( ! V_135 )
goto V_194;
V_38 = F_51 ( V_134 -> V_137 ) ;
if ( ! V_38 )
goto V_189;
memcpy ( V_38 , V_134 -> V_92 , V_134 -> V_137 ) ;
V_135 -> V_92 = V_38 ;
V_135 -> V_137 = V_134 -> V_137 ;
V_135 -> V_68 = V_134 -> V_68 ;
if ( V_184 )
memset ( V_135 -> V_88 , 0 , V_184 ) ;
V_135 -> V_89 = NULL ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
if ( ( V_134 -> V_138 & ( 1 << V_28 ) ) == 0 )
V_135 -> V_90 [ V_28 ] = NULL ;
else
V_135 -> V_90 [ V_28 ] = V_38 +
( ( char * ) V_134 -> V_90 [ V_28 ] - V_134 -> V_92 ) ;
}
V_125 = F_49 ( V_116 , V_134 -> V_30 , V_135 ) ;
if ( V_125 != 0 ) {
F_23 ( L_35 ) ;
goto V_195;
}
if ( V_67 -> V_181 && V_67 -> V_181 ( V_135 , V_67 -> V_138 ) ) {
F_23 ( L_36 ) ;
V_125 = - V_127 ;
goto V_195;
}
V_67 -> V_82 = V_135 ;
F_65 ( & V_67 -> V_87 ) ;
V_125 = F_26 ( & V_179 ) ;
if ( V_125 != 0 )
goto V_195;
F_27 (t, &net->xt.tables[NFPROTO_BRIDGE], list) {
if ( strcmp ( V_74 -> V_30 , V_67 -> V_30 ) == 0 ) {
V_125 = - V_196 ;
F_23 ( L_37 ) ;
goto V_182;
}
}
if ( V_135 -> V_68 && ! F_56 ( V_67 -> V_129 ) ) {
V_125 = - V_114 ;
goto V_182;
}
F_66 ( & V_67 -> V_112 , & V_116 -> V_117 . V_118 [ V_5 ] ) ;
F_28 ( & V_179 ) ;
return V_67 ;
V_182:
F_28 ( & V_179 ) ;
V_195:
if ( V_135 -> V_89 ) {
F_52 (i)
F_53 ( V_135 -> V_89 [ V_28 ] ) ;
F_53 ( V_135 -> V_89 ) ;
}
F_53 ( V_135 -> V_92 ) ;
V_189:
F_53 ( V_135 ) ;
V_194:
F_67 ( V_67 ) ;
V_34:
return F_63 ( V_125 ) ;
}
void F_68 ( struct V_116 * V_116 , struct V_66 * V_67 )
{
int V_28 ;
if ( ! V_67 ) {
F_23 ( L_38 ) ;
return;
}
F_69 ( & V_179 ) ;
F_70 ( & V_67 -> V_112 ) ;
F_28 ( & V_179 ) ;
F_50 ( V_67 -> V_82 -> V_92 , V_67 -> V_82 -> V_137 ,
F_46 , V_116 , NULL ) ;
if ( V_67 -> V_82 -> V_68 )
F_37 ( V_67 -> V_129 ) ;
F_53 ( V_67 -> V_82 -> V_92 ) ;
if ( V_67 -> V_82 -> V_89 ) {
F_52 (i)
F_53 ( V_67 -> V_82 -> V_89 [ V_28 ] ) ;
F_53 ( V_67 -> V_82 -> V_89 ) ;
}
F_53 ( V_67 -> V_82 ) ;
F_67 ( V_67 ) ;
}
static int F_71 ( struct V_116 * V_116 , const char * V_30 ,
struct V_70 T_1 * V_88 ,
unsigned int V_176 ,
const void T_1 * V_183 , unsigned int V_97 )
{
int V_28 , V_125 ;
struct V_70 * V_185 ;
struct V_66 * V_74 ;
if ( V_176 == 0 )
return - V_127 ;
V_185 = F_51 ( V_176 * sizeof( * V_185 ) ) ;
if ( ! V_185 )
return - V_172 ;
V_74 = F_31 ( V_116 , V_30 , & V_125 , & V_179 ) ;
if ( ! V_74 )
goto V_197;
if ( V_176 != V_74 -> V_82 -> V_68 ) {
F_23 ( L_39 ) ;
V_125 = - V_127 ;
goto V_198;
}
if ( F_60 ( V_185 , V_88 , V_176 * sizeof( * V_88 ) ) ) {
V_125 = - V_7 ;
goto V_198;
}
F_57 ( & V_74 -> V_87 ) ;
for ( V_28 = 0 ; V_28 < V_176 ; V_28 ++ ) {
V_74 -> V_82 -> V_88 [ V_28 ] . V_95 += V_185 [ V_28 ] . V_95 ;
V_74 -> V_82 -> V_88 [ V_28 ] . V_96 += V_185 [ V_28 ] . V_96 ;
}
F_58 ( & V_74 -> V_87 ) ;
V_125 = 0 ;
V_198:
F_28 ( & V_179 ) ;
V_197:
F_53 ( V_185 ) ;
return V_125 ;
}
static int F_72 ( struct V_116 * V_116 , const void T_1 * V_183 ,
unsigned int V_97 )
{
struct V_133 V_199 ;
if ( F_60 ( & V_199 , V_183 , sizeof( V_199 ) ) )
return - V_7 ;
if ( V_97 != sizeof( V_199 ) + V_199 . V_176 * sizeof( struct V_70 ) )
return - V_127 ;
return F_71 ( V_116 , V_199 . V_30 , V_199 . V_88 ,
V_199 . V_176 , V_183 , V_97 ) ;
}
static inline int F_73 ( const struct V_19 * V_20 ,
const char * V_80 , char T_1 * V_200 )
{
char T_1 * V_199 = V_200 + ( ( char * ) V_20 - V_80 ) ;
if ( F_4 ( V_199 , V_20 -> V_15 . V_21 -> V_30 , V_113 ) )
return - V_7 ;
return 0 ;
}
static inline int F_74 ( const struct V_8 * V_9 ,
const char * V_80 , char T_1 * V_200 )
{
char T_1 * V_199 = V_200 + ( ( char * ) V_9 - V_80 ) ;
if ( F_4 ( V_199 , V_9 -> V_15 . V_16 -> V_30 , V_113 ) )
return - V_7 ;
return 0 ;
}
static inline int
F_75 ( struct V_31 * V_32 , const char * V_80 , char T_1 * V_200 )
{
int V_125 ;
char T_1 * V_199 ;
const struct V_73 * V_74 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_199 = V_200 + ( ( ( char * ) V_32 + V_32 -> V_98 ) - V_80 ) ;
V_74 = (struct V_73 * ) ( ( ( char * ) V_32 ) + V_32 -> V_98 ) ;
V_125 = F_19 ( V_32 , F_73 , V_80 , V_200 ) ;
if ( V_125 != 0 )
return V_125 ;
V_125 = F_21 ( V_32 , F_74 , V_80 , V_200 ) ;
if ( V_125 != 0 )
return V_125 ;
if ( F_4 ( V_199 , V_74 -> V_15 . V_14 -> V_30 , V_113 ) )
return - V_7 ;
return 0 ;
}
static int F_76 ( struct V_66 * V_74 ,
const struct V_70 * V_173 ,
void T_1 * V_183 , unsigned int V_176 ,
unsigned int V_68 )
{
struct V_70 * V_175 ;
int V_125 = 0 ;
if ( V_176 == 0 )
return 0 ;
if ( V_176 != V_68 ) {
F_23 ( L_40 ) ;
return - V_127 ;
}
V_175 = F_51 ( V_68 * sizeof( * V_175 ) ) ;
if ( ! V_175 )
return - V_172 ;
F_57 ( & V_74 -> V_87 ) ;
F_54 ( V_173 , V_175 , V_68 ) ;
F_58 ( & V_74 -> V_87 ) ;
if ( F_4 ( V_183 , V_175 ,
V_68 * sizeof( struct V_70 ) ) )
V_125 = - V_7 ;
F_53 ( V_175 ) ;
return V_125 ;
}
static int F_77 ( struct V_66 * V_74 , void T_1 * V_183 ,
const int * V_97 , int V_201 )
{
struct V_133 V_185 ;
const struct V_70 * V_173 ;
unsigned int V_137 , V_68 ;
int V_125 ;
char * V_92 ;
if ( V_201 == V_202 ) {
V_137 = V_74 -> V_82 -> V_137 ;
V_68 = V_74 -> V_82 -> V_68 ;
V_92 = V_74 -> V_82 -> V_92 ;
V_173 = V_74 -> V_82 -> V_88 ;
} else {
V_137 = V_74 -> V_67 -> V_137 ;
V_68 = V_74 -> V_67 -> V_68 ;
V_92 = V_74 -> V_67 -> V_92 ;
V_173 = V_74 -> V_67 -> V_88 ;
}
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) )
return - V_7 ;
if ( * V_97 != sizeof( struct V_133 ) + V_137 +
( V_185 . V_176 ? V_68 * sizeof( struct V_70 ) : 0 ) )
return - V_127 ;
if ( V_185 . V_68 != V_68 ) {
F_23 ( L_41 ) ;
return - V_127 ;
}
if ( V_185 . V_137 != V_137 ) {
F_23 ( L_42 ) ;
return - V_127 ;
}
V_125 = F_76 ( V_74 , V_173 , V_185 . V_88 ,
V_185 . V_176 , V_68 ) ;
if ( V_125 )
return V_125 ;
if ( F_4 ( V_185 . V_92 , V_92 , V_137 ) ) {
F_23 ( L_43 ) ;
return - V_7 ;
}
return F_50 ( V_92 , V_137 ,
F_75 , V_92 , V_185 . V_92 ) ;
}
static int F_78 ( struct V_203 * V_204 ,
int V_201 , void T_1 * V_183 , unsigned int V_97 )
{
int V_125 ;
if ( ! F_79 ( V_205 ) )
return - V_206 ;
switch( V_201 ) {
case V_207 :
V_125 = F_59 ( F_80 ( V_204 ) , V_183 , V_97 ) ;
break;
case V_208 :
V_125 = F_72 ( F_80 ( V_204 ) , V_183 , V_97 ) ;
break;
default:
V_125 = - V_127 ;
}
return V_125 ;
}
static int F_81 ( struct V_203 * V_204 , int V_201 , void T_1 * V_183 , int * V_97 )
{
int V_125 ;
struct V_133 V_185 ;
struct V_66 * V_74 ;
if ( ! F_79 ( V_205 ) )
return - V_206 ;
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) )
return - V_7 ;
V_74 = F_31 ( F_80 ( V_204 ) , V_185 . V_30 , & V_125 , & V_179 ) ;
if ( ! V_74 )
return V_125 ;
switch( V_201 ) {
case V_209 :
case V_210 :
if ( * V_97 != sizeof( struct V_133 ) ) {
V_125 = - V_127 ;
F_28 ( & V_179 ) ;
break;
}
if ( V_201 == V_209 ) {
V_185 . V_68 = V_74 -> V_82 -> V_68 ;
V_185 . V_137 = V_74 -> V_82 -> V_137 ;
V_185 . V_138 = V_74 -> V_138 ;
} else {
V_185 . V_68 = V_74 -> V_67 -> V_68 ;
V_185 . V_137 = V_74 -> V_67 -> V_137 ;
V_185 . V_138 = V_74 -> V_67 -> V_138 ;
}
F_28 ( & V_179 ) ;
if ( F_4 ( V_183 , & V_185 , * V_97 ) != 0 ) {
F_23 ( L_44 ) ;
V_125 = - V_7 ;
break;
}
V_125 = 0 ;
break;
case V_202 :
case V_211 :
V_125 = F_77 ( V_74 , V_183 , V_97 , V_201 ) ;
F_28 ( & V_179 ) ;
break;
default:
F_28 ( & V_179 ) ;
V_125 = - V_127 ;
}
return V_125 ;
}
static int F_82 ( void )
{
F_83 ( F_84 ( sizeof( struct V_19 ) ) <
F_85 ( sizeof( struct V_212 ) ) ) ;
return ( int ) F_84 ( sizeof( struct V_19 ) ) -
F_85 ( sizeof( struct V_212 ) ) ;
}
static int F_86 ( const struct V_122 * V_21 ,
unsigned int V_213 )
{
if ( F_87 ( V_21 -> V_214 == - 1 ) )
return F_84 ( V_213 ) - F_85 ( V_213 ) ;
return F_88 ( V_21 ) ;
}
static int F_89 ( struct V_19 * V_20 , void T_1 * * V_215 ,
unsigned int * V_177 )
{
const struct V_122 * V_21 = V_20 -> V_15 . V_21 ;
struct V_212 T_1 * V_216 = * V_215 ;
int V_217 = F_86 ( V_21 , V_20 -> V_126 ) ;
T_4 V_218 = V_20 -> V_126 - V_217 ;
F_90 ( V_217 >= V_20 -> V_126 ) ;
if ( F_4 ( V_216 -> V_15 . V_30 , V_21 -> V_30 ,
strlen ( V_21 -> V_30 ) + 1 ) || F_91 ( V_218 , & V_216 -> V_126 ) )
return - V_7 ;
if ( V_21 -> V_219 ) {
if ( V_21 -> V_219 ( V_216 -> V_18 , V_20 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_216 -> V_18 , V_20 -> V_18 , V_218 ) )
return - V_7 ;
* V_177 -= F_82 () + V_217 ;
* V_215 = V_216 -> V_18 ;
* V_215 += V_218 ;
return 0 ;
}
static int F_92 ( struct V_73 * V_74 ,
void T_1 * * V_215 ,
unsigned int * V_177 )
{
const struct V_131 * V_14 = V_74 -> V_15 . V_14 ;
struct V_212 T_1 * V_216 = * V_215 ;
int V_217 = F_93 ( V_14 ) ;
T_4 V_220 = V_74 -> V_162 - V_217 ;
F_90 ( V_217 >= V_74 -> V_162 ) ;
if ( F_4 ( V_216 -> V_15 . V_30 , V_14 -> V_30 ,
strlen ( V_14 -> V_30 ) + 1 ) || F_91 ( V_220 , & V_216 -> V_126 ) )
return - V_7 ;
if ( V_14 -> V_219 ) {
if ( V_14 -> V_219 ( V_216 -> V_18 , V_74 -> V_18 ) )
return - V_7 ;
} else if ( F_4 ( V_216 -> V_18 , V_74 -> V_18 , V_220 ) )
return - V_7 ;
* V_177 -= F_82 () + V_217 ;
* V_215 = V_216 -> V_18 ;
* V_215 += V_220 ;
return 0 ;
}
static int F_94 ( struct V_8 * V_9 ,
void T_1 * * V_215 ,
unsigned int * V_177 )
{
return F_92 ( (struct V_73 * ) V_9 ,
V_215 , V_177 ) ;
}
static int F_95 ( struct V_31 * V_32 , void T_1 * * V_215 ,
unsigned int * V_177 )
{
struct V_73 * V_74 ;
struct V_31 T_1 * V_221 ;
T_5 V_124 , V_98 , V_142 ;
T_4 V_222 ;
int V_125 ;
if ( V_32 -> V_43 == 0 ) {
if ( * V_177 < sizeof( struct V_78 ) )
return - V_127 ;
if ( F_4 ( * V_215 , V_32 , sizeof( struct V_78 ) ) )
return - V_7 ;
* V_215 += sizeof( struct V_78 ) ;
* V_177 -= sizeof( struct V_78 ) ;
return 0 ;
}
if ( * V_177 < sizeof( * V_221 ) )
return - V_127 ;
V_221 = (struct V_31 T_1 * ) * V_215 ;
if ( F_4 ( V_221 , V_32 , sizeof( * V_221 ) ) )
return - V_7 ;
V_222 = * V_177 ;
* V_215 += sizeof( * V_221 ) ;
V_125 = F_19 ( V_32 , F_89 , V_215 , V_177 ) ;
if ( V_125 )
return V_125 ;
V_124 = V_32 -> V_124 - ( V_222 - * V_177 ) ;
V_125 = F_21 ( V_32 , F_94 , V_215 , V_177 ) ;
if ( V_125 )
return V_125 ;
V_98 = V_32 -> V_98 - ( V_222 - * V_177 ) ;
V_74 = (struct V_73 * ) ( ( char * ) V_32 + V_32 -> V_98 ) ;
V_125 = F_92 ( V_74 , V_215 , V_177 ) ;
if ( V_125 )
return V_125 ;
V_142 = V_32 -> V_142 - ( V_222 - * V_177 ) ;
if ( F_91 ( V_124 , & V_221 -> V_124 ) ||
F_91 ( V_98 , & V_221 -> V_98 ) ||
F_91 ( V_142 , & V_221 -> V_142 ) )
return - V_7 ;
* V_177 -= sizeof( * V_221 ) ;
return 0 ;
}
static int F_96 ( struct V_19 * V_20 , int * V_217 )
{
* V_217 += F_86 ( V_20 -> V_15 . V_21 , V_20 -> V_126 ) ;
* V_217 += F_82 () ;
return 0 ;
}
static int F_97 ( struct V_8 * V_9 , int * V_217 )
{
* V_217 += F_93 ( V_9 -> V_15 . V_16 ) ;
* V_217 += F_82 () ;
return 0 ;
}
static int F_98 ( const struct V_31 * V_32 ,
const struct V_81 * V_223 ,
const void * V_80 ,
struct V_224 * V_135 )
{
const struct V_73 * V_74 ;
unsigned int V_225 ;
int V_217 , V_125 , V_28 ;
if ( V_32 -> V_43 == 0 )
return 0 ;
V_217 = 0 ;
V_225 = ( void * ) V_32 - V_80 ;
F_19 ( V_32 , F_96 , & V_217 ) ;
F_21 ( V_32 , F_97 , & V_217 ) ;
V_74 = ( const struct V_73 * ) ( ( char * ) V_32 + V_32 -> V_98 ) ;
V_217 += F_93 ( V_74 -> V_15 . V_14 ) ;
V_217 += F_82 () ;
V_135 -> V_137 -= V_217 ;
V_125 = F_99 ( V_5 , V_225 , V_217 ) ;
if ( V_125 )
return V_125 ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
const void * V_226 = V_223 -> V_90 [ V_28 ] ;
if ( V_223 -> V_90 [ V_28 ] &&
( V_32 < (struct V_31 * ) ( V_80 - V_226 ) ) ) {
V_135 -> V_90 [ V_28 ] -= V_217 ;
F_100 ( L_45 ,
V_135 -> V_90 [ V_28 ] + V_217 ,
V_135 -> V_90 [ V_28 ] ) ;
}
}
return 0 ;
}
static int F_101 ( const struct V_81 * V_223 ,
struct V_224 * V_135 )
{
unsigned int V_177 = V_223 -> V_137 ;
const void * V_92 = V_223 -> V_92 ;
V_135 -> V_137 = V_177 ;
F_102 ( V_5 , V_223 -> V_68 ) ;
return F_50 ( V_92 , V_177 , F_98 , V_223 ,
V_92 , V_135 ) ;
}
static int F_103 ( struct V_66 * V_74 ,
void T_1 * V_183 , int * V_97 , int V_201 )
{
struct V_224 V_134 , V_185 ;
struct V_70 * V_173 ;
struct V_81 V_227 ;
int V_125 ;
void T_1 * V_166 ;
memset ( & V_227 , 0 , sizeof( V_227 ) ) ;
if ( V_201 == V_202 ) {
V_227 . V_137 = V_74 -> V_82 -> V_137 ;
V_227 . V_68 = V_74 -> V_82 -> V_68 ;
V_227 . V_92 = V_74 -> V_82 -> V_92 ;
V_173 = V_74 -> V_82 -> V_88 ;
} else {
V_227 . V_137 = V_74 -> V_67 -> V_137 ;
V_227 . V_68 = V_74 -> V_67 -> V_68 ;
V_227 . V_92 = V_74 -> V_67 -> V_92 ;
V_173 = V_74 -> V_67 -> V_88 ;
}
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) )
return - V_7 ;
if ( V_185 . V_68 != V_227 . V_68 ||
( V_185 . V_176 && V_185 . V_176 != V_227 . V_68 ) )
return - V_127 ;
memcpy ( & V_134 , & V_185 , sizeof( V_134 ) ) ;
if ( V_201 == V_202 )
V_125 = F_101 ( V_74 -> V_82 , & V_134 ) ;
else
V_125 = F_101 ( & V_227 , & V_134 ) ;
if ( V_125 )
return V_125 ;
if ( * V_97 != sizeof( V_185 ) + V_134 . V_137 +
( V_185 . V_176 ? V_227 . V_68 * sizeof( struct V_70 ) : 0 ) ) {
F_104 ( L_46 ,
* V_97 , V_227 . V_137 , V_134 . V_137 ) ;
return - V_127 ;
}
V_125 = F_76 ( V_74 , V_173 , F_105 ( V_185 . V_88 ) ,
V_185 . V_176 , V_227 . V_68 ) ;
if ( V_125 )
return V_125 ;
V_166 = F_105 ( V_185 . V_92 ) ;
return F_50 ( V_227 . V_92 , V_227 . V_137 ,
F_95 , & V_166 , & V_185 . V_137 ) ;
}
static int F_106 ( struct V_228 * V_229 , unsigned int V_230 )
{
V_229 -> V_231 += V_230 ;
return V_229 -> V_231 >= V_230 ? 0 : - V_127 ;
}
static int F_107 ( struct V_228 * V_229 ,
void * V_18 , unsigned int V_230 )
{
if ( V_229 -> V_232 == NULL )
goto V_233;
F_90 ( V_229 -> V_231 + V_230 > V_229 -> V_234 ) ;
memcpy ( V_229 -> V_232 + V_229 -> V_231 , V_18 , V_230 ) ;
V_233:
V_229 -> V_235 += V_230 ;
return F_106 ( V_229 , V_230 ) ;
}
static int F_108 ( struct V_228 * V_229 , unsigned int V_230 )
{
char * V_236 = V_229 -> V_232 ;
F_90 ( V_236 && V_229 -> V_231 > V_229 -> V_234 ) ;
if ( V_236 != NULL && V_230 > 0 )
memset ( V_236 + V_229 -> V_231 , 0 , V_230 ) ;
return F_106 ( V_229 , V_230 ) ;
}
static int F_109 ( struct V_212 * V_237 ,
enum V_238 V_238 ,
struct V_228 * V_229 ,
const unsigned char * V_80 )
{
char V_30 [ V_113 ] ;
struct V_122 * V_21 ;
struct V_131 * V_239 ;
void * V_1 = NULL ;
int V_217 , V_240 = 0 ;
unsigned int V_241 , V_126 = V_237 -> V_126 ;
F_110 ( V_30 , V_237 -> V_15 . V_30 , sizeof( V_30 ) ) ;
if ( V_229 -> V_232 )
V_1 = V_229 -> V_232 + V_229 -> V_231 ;
switch ( V_238 ) {
case V_242 :
V_21 = F_30 ( F_111 ( V_5 ,
V_30 , 0 ) , L_47 , V_30 ) ;
if ( V_21 == NULL )
return - V_114 ;
if ( F_34 ( V_21 ) )
return F_35 ( V_21 ) ;
V_217 = F_86 ( V_21 , V_126 ) ;
if ( V_1 ) {
if ( V_21 -> V_243 )
V_21 -> V_243 ( V_1 , V_237 -> V_18 ) ;
else
memcpy ( V_1 , V_237 -> V_18 , V_126 ) ;
}
V_241 = V_21 -> V_214 ;
if ( F_87 ( V_241 == - 1 ) )
V_241 = V_126 ;
F_37 ( V_21 -> V_129 ) ;
break;
case V_244 :
case V_245 :
V_239 = F_30 ( F_112 ( V_5 ,
V_30 , 0 ) , L_47 , V_30 ) ;
if ( V_239 == NULL )
return - V_114 ;
if ( F_34 ( V_239 ) )
return F_35 ( V_239 ) ;
V_217 = F_93 ( V_239 ) ;
if ( V_1 ) {
if ( V_239 -> V_243 )
V_239 -> V_243 ( V_1 , V_237 -> V_18 ) ;
else
memcpy ( V_1 , V_237 -> V_18 , V_126 ) ;
}
V_241 = V_239 -> V_246 ;
F_37 ( V_239 -> V_129 ) ;
break;
default:
return - V_127 ;
}
V_229 -> V_231 += V_126 + V_217 ;
V_229 -> V_235 += V_126 ;
V_240 = F_84 ( V_241 ) - V_241 ;
if ( V_240 > 0 && V_1 ) {
F_90 ( V_229 -> V_234 <= V_240 ) ;
F_90 ( V_229 -> V_231 - ( V_126 + V_217 ) + V_241 > V_229 -> V_234 - V_240 ) ;
memset ( V_1 + V_241 , 0 , V_240 ) ;
}
return V_217 + V_126 ;
}
static int F_113 ( struct V_212 * V_247 ,
unsigned int V_248 , enum V_238 type ,
struct V_228 * V_229 , const void * V_80 )
{
int V_249 = 0 ;
char * V_250 ;
if ( V_248 == 0 )
return 0 ;
V_250 = ( char * ) V_247 ;
while ( V_248 >= sizeof( * V_247 ) ) {
struct V_19 * V_251 ;
int V_125 ;
V_251 = (struct V_19 * ) V_229 -> V_232 ;
if ( V_251 ) {
char * V_185 ;
V_185 = V_229 -> V_232 + V_229 -> V_231 ;
V_251 = (struct V_19 * ) V_185 ;
}
V_125 = F_107 ( V_229 , V_250 , sizeof( * V_247 ) ) ;
if ( V_125 < 0 )
return V_125 ;
V_248 -= sizeof( * V_247 ) ;
V_125 = F_108 ( V_229 , F_82 () ) ;
if ( V_125 < 0 )
return V_125 ;
if ( V_247 -> V_126 > V_248 )
return - V_127 ;
V_248 -= V_247 -> V_126 ;
V_125 = F_109 ( V_247 , type , V_229 , V_80 ) ;
if ( V_125 < 0 )
return V_125 ;
F_90 ( V_125 < V_247 -> V_126 ) ;
V_249 += V_125 - V_247 -> V_126 ;
V_249 += F_82 () ;
V_250 += sizeof( * V_247 ) ;
V_250 += V_247 -> V_126 ;
if ( V_251 )
V_251 -> V_126 = V_125 ;
F_114 ( type == V_245 && V_248 ) ;
V_247 = (struct V_212 * ) V_250 ;
}
return V_249 ;
}
static int F_115 ( struct V_31 * V_25 , const unsigned char * V_80 ,
unsigned int * V_252 ,
struct V_228 * V_229 )
{
unsigned int V_28 , V_152 , V_253 , V_254 = 0 ;
unsigned int V_255 [ 4 ] ;
unsigned int * V_256 = NULL ;
int V_125 ;
char * V_257 ;
if ( * V_252 < sizeof( struct V_78 ) )
return - V_127 ;
if ( ! V_25 -> V_43 ) {
* V_252 -= sizeof( struct V_78 ) ;
return F_107 ( V_229 , V_25 , sizeof( struct V_78 ) ) ;
}
if ( * V_252 < sizeof( * V_25 ) || V_25 -> V_142 < sizeof( * V_25 ) )
return - V_127 ;
V_253 = V_229 -> V_235 ;
V_125 = F_107 ( V_229 , V_25 ,
F_116 ( struct V_31 , V_124 ) ) ;
if ( V_125 < 0 )
return V_125 ;
V_255 [ 0 ] = sizeof( struct V_31 ) ;
memcpy ( & V_255 [ 1 ] , & V_25 -> V_124 ,
sizeof( V_255 ) - sizeof( V_255 [ 0 ] ) ) ;
if ( V_229 -> V_232 ) {
V_257 = V_229 -> V_232 + V_229 -> V_231 ;
V_256 = ( unsigned int * ) V_257 ;
}
V_125 = F_107 ( V_229 , & V_255 [ 1 ] ,
sizeof( V_255 ) - sizeof( V_255 [ 0 ] ) ) ;
if ( V_125 < 0 )
return V_125 ;
V_257 = ( char * ) V_25 ;
for ( V_28 = 0 , V_152 = 1 ; V_152 < 4 ; V_152 ++ , V_28 ++ ) {
struct V_212 * V_247 ;
unsigned int V_177 ;
char * V_250 = V_257 ;
V_250 = V_257 + V_255 [ V_28 ] ;
if ( V_255 [ V_28 ] > V_255 [ V_152 ] )
return - V_127 ;
V_247 = (struct V_212 * ) V_250 ;
V_177 = V_255 [ V_152 ] - V_255 [ V_28 ] ;
V_125 = F_113 ( V_247 , V_177 , V_28 , V_229 , V_80 ) ;
if ( V_125 < 0 )
return V_125 ;
V_254 += V_125 ;
if ( V_256 && V_254 ) {
F_100 ( L_48 ,
V_256 [ V_28 ] , V_255 [ V_152 ] + V_254 ) ;
V_256 [ V_28 ] = V_255 [ V_152 ] + V_254 ;
}
}
if ( V_229 -> V_232 == NULL ) {
unsigned int V_139 = V_257 - ( char * ) V_80 ;
V_125 = F_99 ( V_5 , V_139 , V_254 ) ;
if ( V_125 < 0 )
return V_125 ;
}
V_253 = V_229 -> V_235 - V_253 ;
F_90 ( * V_252 < V_253 ) ;
* V_252 -= V_253 ;
return 0 ;
}
static int F_117 ( unsigned char * V_18 , unsigned int V_258 ,
struct V_228 * V_229 )
{
unsigned int V_259 = V_258 ;
int V_125 ;
V_125 = F_50 ( V_18 , V_258 , F_115 , V_18 ,
& V_259 , V_229 ) ;
if ( V_125 < 0 )
return V_125 ;
F_114 ( V_259 ) ;
return V_229 -> V_231 ;
}
static int F_118 ( struct V_133 * V_134 ,
void T_1 * V_183 , unsigned int V_97 )
{
struct V_224 V_185 ;
int V_28 ;
if ( V_97 < sizeof( V_185 ) )
return - V_127 ;
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) )
return - V_7 ;
if ( V_97 != sizeof( V_185 ) + V_185 . V_137 )
return - V_127 ;
if ( V_185 . V_137 == 0 )
return - V_127 ;
if ( V_185 . V_68 >= ( ( V_186 - sizeof( struct V_81 ) ) /
V_187 - V_188 ) / sizeof( struct V_70 ) )
return - V_172 ;
if ( V_185 . V_176 >= V_186 / sizeof( struct V_70 ) )
return - V_172 ;
memcpy ( V_134 , & V_185 , F_116 ( struct V_133 , V_90 ) ) ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ )
V_134 -> V_90 [ V_28 ] = F_105 ( V_185 . V_90 [ V_28 ] ) ;
V_134 -> V_176 = V_185 . V_176 ;
V_134 -> V_88 = F_105 ( V_185 . V_88 ) ;
V_134 -> V_92 = F_105 ( V_185 . V_92 ) ;
return 0 ;
}
static int F_119 ( struct V_116 * V_116 , void T_1 * V_183 ,
unsigned int V_97 )
{
int V_125 , V_28 , V_184 , V_260 ;
struct V_81 * V_135 ;
struct V_133 V_185 ;
struct V_228 V_229 ;
void * V_261 ;
V_125 = F_118 ( & V_185 , V_183 , V_97 ) ;
if ( V_125 ) {
if ( V_125 == - V_127 && F_59 ( V_116 , V_183 , V_97 ) == 0 )
V_125 = 0 ;
return V_125 ;
}
V_184 = F_61 ( V_185 . V_68 ) * V_171 ;
V_135 = F_51 ( sizeof( * V_135 ) + V_184 ) ;
if ( ! V_135 )
return - V_172 ;
if ( V_184 )
memset ( V_135 -> V_88 , 0 , V_184 ) ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
V_135 -> V_92 = F_51 ( V_185 . V_137 ) ;
if ( ! V_135 -> V_92 ) {
V_125 = - V_172 ;
goto V_189;
}
if ( F_60 (
V_135 -> V_92 , V_185 . V_92 , V_185 . V_137 ) != 0 ) {
V_125 = - V_7 ;
goto V_190;
}
V_261 = V_135 -> V_92 ;
F_120 ( V_5 ) ;
F_102 ( V_5 , V_185 . V_68 ) ;
V_125 = F_117 ( V_261 , V_185 . V_137 , & V_229 ) ;
if ( V_125 < 0 )
goto V_262;
F_100 ( L_49 ,
V_185 . V_137 , V_229 . V_231 , V_229 . V_235 ,
F_2 ( V_5 , V_185 . V_137 ) ) ;
V_260 = V_125 ;
V_135 -> V_92 = F_51 ( V_260 ) ;
if ( ! V_135 -> V_92 ) {
F_53 ( V_261 ) ;
V_125 = - V_172 ;
goto V_262;
}
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
V_229 . V_232 = V_135 -> V_92 ;
V_229 . V_234 = V_260 ;
V_125 = F_117 ( V_261 , V_185 . V_137 , & V_229 ) ;
F_90 ( V_125 < 0 ) ;
F_53 ( V_261 ) ;
V_185 . V_137 = V_260 ;
for ( V_28 = 0 ; V_28 < V_140 ; V_28 ++ ) {
char T_1 * V_263 ;
if ( V_185 . V_90 [ V_28 ] ) {
unsigned int V_264 ;
V_263 = ( char T_1 * ) V_185 . V_90 [ V_28 ] ;
V_264 = V_263 - V_185 . V_92 ;
V_263 += F_2 ( V_5 , V_264 ) ;
V_185 . V_90 [ V_28 ] = (struct V_78 T_1 * ) V_263 ;
}
}
F_121 ( V_5 ) ;
F_122 ( V_5 ) ;
V_125 = F_55 ( V_116 , & V_185 , V_135 ) ;
if ( V_125 == 0 )
return V_125 ;
V_190:
F_53 ( V_135 -> V_92 ) ;
V_189:
F_53 ( V_135 ) ;
return V_125 ;
V_262:
F_121 ( V_5 ) ;
F_122 ( V_5 ) ;
goto V_190;
}
static int F_123 ( struct V_116 * V_116 , void T_1 * V_183 ,
unsigned int V_97 )
{
struct V_224 V_199 ;
if ( F_60 ( & V_199 , V_183 , sizeof( V_199 ) ) )
return - V_7 ;
if ( V_97 != sizeof( V_199 ) + V_199 . V_176 * sizeof( struct V_70 ) )
return F_72 ( V_116 , V_183 , V_97 ) ;
return F_71 ( V_116 , V_199 . V_30 , F_105 ( V_199 . V_88 ) ,
V_199 . V_176 , V_183 , V_97 ) ;
}
static int F_124 ( struct V_203 * V_204 ,
int V_201 , void T_1 * V_183 , unsigned int V_97 )
{
int V_125 ;
if ( ! F_79 ( V_205 ) )
return - V_206 ;
switch ( V_201 ) {
case V_207 :
V_125 = F_119 ( F_80 ( V_204 ) , V_183 , V_97 ) ;
break;
case V_208 :
V_125 = F_123 ( F_80 ( V_204 ) , V_183 , V_97 ) ;
break;
default:
V_125 = - V_127 ;
}
return V_125 ;
}
static int F_125 ( struct V_203 * V_204 , int V_201 ,
void T_1 * V_183 , int * V_97 )
{
int V_125 ;
struct V_224 V_185 ;
struct V_66 * V_74 ;
if ( ! F_79 ( V_205 ) )
return - V_206 ;
if ( ( V_201 == V_209 ||
V_201 == V_210 ) && * V_97 != sizeof( V_185 ) )
return F_81 ( V_204 , V_201 , V_183 , V_97 ) ;
if ( F_60 ( & V_185 , V_183 , sizeof( V_185 ) ) )
return - V_7 ;
V_74 = F_31 ( F_80 ( V_204 ) , V_185 . V_30 , & V_125 , & V_179 ) ;
if ( ! V_74 )
return V_125 ;
F_120 ( V_5 ) ;
switch ( V_201 ) {
case V_209 :
V_185 . V_68 = V_74 -> V_82 -> V_68 ;
V_125 = F_101 ( V_74 -> V_82 , & V_185 ) ;
if ( V_125 )
goto V_34;
V_185 . V_138 = V_74 -> V_138 ;
if ( F_4 ( V_183 , & V_185 , * V_97 ) != 0 ) {
V_125 = - V_7 ;
break;
}
V_125 = 0 ;
break;
case V_210 :
V_185 . V_68 = V_74 -> V_67 -> V_68 ;
V_185 . V_137 = V_74 -> V_67 -> V_137 ;
V_185 . V_138 = V_74 -> V_67 -> V_138 ;
if ( F_4 ( V_183 , & V_185 , * V_97 ) != 0 ) {
V_125 = - V_7 ;
break;
}
V_125 = 0 ;
break;
case V_202 :
case V_211 :
if ( F_77 ( V_74 , V_183 , V_97 , V_201 ) == 0 )
V_125 = 0 ;
else
V_125 = F_103 ( V_74 , V_183 , V_97 , V_201 ) ;
break;
default:
V_125 = - V_127 ;
}
V_34:
F_121 ( V_5 ) ;
F_122 ( V_5 ) ;
F_28 ( & V_179 ) ;
return V_125 ;
}
static int T_6 F_126 ( void )
{
int V_125 ;
V_125 = F_127 ( & V_99 ) ;
if ( V_125 < 0 )
return V_125 ;
V_125 = F_128 ( & V_265 ) ;
if ( V_125 < 0 ) {
F_129 ( & V_99 ) ;
return V_125 ;
}
F_130 ( V_266 L_50 ) ;
return 0 ;
}
static void T_7 F_131 ( void )
{
F_132 ( & V_265 ) ;
F_129 ( & V_99 ) ;
F_130 ( V_266 L_51 ) ;
}
