const char * F_1 ( unsigned int V_1 )
{
static char V_2 [ 20 ] ;
switch ( V_1 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
#ifdef F_2
case V_8 :
return L_6 ;
#endif
default:
sprintf ( V_2 , L_7 , V_1 ) ;
return V_2 ;
}
}
void F_3 ( struct V_9 * V_10 , int V_11 )
{
while ( -- V_11 >= 0 )
F_4 ( & V_10 [ V_11 ] ) ;
}
static inline void
F_5 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
struct V_18 * V_19 = F_6 ( F_7 ( V_15 ) ) ;
if ( V_17 && ( V_17 -> V_20 & V_21 ) ) {
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_8 ( V_17 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_29 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_31 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
F_11 () ;
V_25 = F_12 ( V_17 -> V_25 ) ;
V_23 = F_8 ( V_25 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_29 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_31 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
F_13 () ;
V_23 = F_8 ( V_19 -> V_33 . V_27 ) ;
V_23 -> V_28 . V_29 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_31 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
}
}
static inline void
F_14 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
struct V_18 * V_19 = F_6 ( F_7 ( V_15 ) ) ;
if ( V_17 && ( V_17 -> V_20 & V_21 ) ) {
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_8 ( V_17 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_34 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_35 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
F_11 () ;
V_25 = F_12 ( V_17 -> V_25 ) ;
V_23 = F_8 ( V_25 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_34 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_35 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
F_13 () ;
V_23 = F_8 ( V_19 -> V_33 . V_27 ) ;
V_23 -> V_28 . V_34 ++ ;
F_9 ( & V_23 -> V_30 ) ;
V_23 -> V_28 . V_35 += V_15 -> V_32 ;
F_10 ( & V_23 -> V_30 ) ;
}
}
static inline void
F_15 ( struct V_12 * V_13 , struct V_24 * V_25 )
{
struct V_18 * V_19 = F_6 ( V_25 -> V_36 ) ;
struct V_22 * V_23 ;
V_23 = F_8 ( V_13 -> V_17 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_37 ++ ;
V_23 = F_8 ( V_25 -> V_26 . V_27 ) ;
V_23 -> V_28 . V_37 ++ ;
V_23 = F_8 ( V_19 -> V_33 . V_27 ) ;
V_23 -> V_28 . V_37 ++ ;
}
static inline void
F_16 ( struct V_12 * V_13 , int V_38 ,
const struct V_14 * V_15 ,
struct V_39 * V_40 )
{
if ( F_17 ( V_40 -> V_41 -> V_42 ) )
V_40 -> V_41 -> V_42 ( V_13 , V_38 , V_15 , V_40 ) ;
}
static inline int
F_18 ( const struct V_24 * V_25 ,
struct V_14 * V_15 , int V_43 ,
const union V_44 * V_45 , T_1 V_46 ,
const union V_44 * V_47 , T_1 V_48 ,
struct V_49 * V_50 )
{
F_19 ( V_25 -> V_36 , V_25 -> V_51 , V_43 , V_45 , V_46 , V_47 ,
V_48 , V_50 ) ;
V_50 -> V_52 = F_12 ( V_25 -> V_52 ) ;
if ( V_50 -> V_52 && V_50 -> V_52 -> V_53 )
return V_50 -> V_52 -> V_53 ( V_50 , V_15 ) ;
return 0 ;
}
static struct V_12 *
F_20 ( struct V_24 * V_25 ,
struct V_14 * V_15 , T_1 V_54 , T_1 V_55 ,
int * V_56 , struct V_57 * V_58 )
{
struct V_12 * V_13 = NULL ;
struct V_16 * V_17 ;
struct V_12 * V_59 ;
T_1 V_60 = 0 ;
unsigned int V_20 ;
struct V_49 V_61 ;
const union V_44 V_62 = { . V_63 = F_21 (svc->fwmark) } ;
union V_44 V_64 ;
#ifdef F_2
if ( V_25 -> V_51 == V_65 )
F_22 ( & V_64 . V_66 , & V_58 -> V_67 . V_66 ,
( V_68 V_69 ) V_25 -> V_70 ) ;
else
#endif
V_64 . V_63 = V_58 -> V_67 . V_63 & V_25 -> V_70 ;
F_23 ( 6 , L_8
L_9 ,
F_24 ( V_25 -> V_51 , & V_58 -> V_67 ) , F_25 ( V_54 ) ,
F_24 ( V_25 -> V_51 , & V_58 -> V_71 ) , F_25 ( V_55 ) ,
F_24 ( V_25 -> V_51 , & V_64 ) ) ;
{
int V_43 = V_58 -> V_43 ;
const union V_44 * V_47 = & V_58 -> V_71 ;
T_1 V_48 = 0 ;
if ( V_55 == V_25 -> V_72 ) {
if ( V_25 -> V_72 != V_73 )
V_48 = V_55 ;
} else {
if ( V_25 -> V_62 ) {
V_43 = V_3 ;
V_47 = & V_62 ;
}
}
if ( F_18 ( V_25 , V_15 , V_43 , & V_64 , 0 ,
V_47 , V_48 , & V_61 ) < 0 ) {
* V_56 = - 1 ;
return NULL ;
}
}
V_59 = F_26 ( & V_61 ) ;
if ( ! V_59 || ! F_27 ( V_59 ) ) {
struct V_74 * V_75 ;
V_75 = F_12 ( V_25 -> V_76 ) ;
V_17 = V_75 -> V_77 ( V_25 , V_15 , V_58 ) ;
if ( ! V_17 ) {
F_28 ( 1 , L_10 ) ;
F_29 ( V_61 . V_78 ) ;
* V_56 = 0 ;
return NULL ;
}
if ( V_55 == V_25 -> V_72 && V_25 -> V_72 != V_73 )
V_60 = V_17 -> V_72 ;
V_59 = F_30 ( & V_61 , & V_17 -> V_79 , V_60 ,
V_80 , V_17 , V_15 -> V_81 ) ;
if ( V_59 == NULL ) {
F_29 ( V_61 . V_78 ) ;
* V_56 = - 1 ;
return NULL ;
}
V_59 -> V_82 = V_25 -> V_82 ;
} else {
V_17 = V_59 -> V_17 ;
F_29 ( V_61 . V_78 ) ;
}
V_60 = V_55 ;
if ( V_60 == V_25 -> V_72 && V_17 -> V_72 )
V_60 = V_17 -> V_72 ;
V_20 = ( V_25 -> V_20 & V_83
&& V_58 -> V_43 == V_4 ) ?
V_84 : 0 ;
F_19 ( V_25 -> V_36 , V_25 -> V_51 , V_58 -> V_43 , & V_58 -> V_67 ,
V_54 , & V_58 -> V_71 , V_55 , & V_61 ) ;
V_13 = F_30 ( & V_61 , & V_17 -> V_79 , V_60 , V_20 , V_17 , V_15 -> V_81 ) ;
if ( V_13 == NULL ) {
F_31 ( V_59 ) ;
* V_56 = - 1 ;
return NULL ;
}
F_32 ( V_13 , V_59 ) ;
F_31 ( V_59 ) ;
F_15 ( V_13 , V_25 ) ;
return V_13 ;
}
struct V_12 *
F_33 ( struct V_24 * V_25 , struct V_14 * V_15 ,
struct V_39 * V_40 , int * V_56 ,
struct V_57 * V_58 )
{
struct V_85 * V_41 = V_40 -> V_41 ;
struct V_12 * V_13 = NULL ;
struct V_74 * V_75 ;
struct V_16 * V_17 ;
T_1 V_86 [ 2 ] , * V_87 ;
unsigned int V_20 ;
* V_56 = 1 ;
V_87 = F_34 ( V_15 , V_58 -> V_32 , sizeof( V_86 ) , V_86 , V_58 ) ;
if ( V_87 == NULL )
return NULL ;
if ( V_87 [ 0 ] == V_88 ) {
F_35 ( 12 , V_25 -> V_51 , V_41 , V_15 , 0 ,
L_11 ) ;
return NULL ;
}
if ( ( ! V_15 -> V_89 || V_15 -> V_89 -> V_20 & V_90 ) &&
( V_13 = V_41 -> V_91 ( V_25 -> V_51 , V_15 , V_58 , 1 ) ) ) {
F_35 ( 12 , V_25 -> V_51 , V_41 , V_15 , 0 ,
L_12 ) ;
F_36 ( V_13 ) ;
return NULL ;
}
if ( V_25 -> V_20 & V_92 )
return F_20 ( V_25 , V_15 , V_87 [ 0 ] , V_87 [ 1 ] , V_56 ,
V_58 ) ;
* V_56 = 0 ;
if ( ! V_25 -> V_62 && V_87 [ 1 ] != V_25 -> V_72 ) {
if ( ! V_25 -> V_72 )
F_37 ( L_13
L_14
L_15 ) ;
return NULL ;
}
V_75 = F_12 ( V_25 -> V_76 ) ;
V_17 = V_75 -> V_77 ( V_25 , V_15 , V_58 ) ;
if ( V_17 == NULL ) {
F_28 ( 1 , L_16 ) ;
return NULL ;
}
V_20 = ( V_25 -> V_20 & V_83
&& V_58 -> V_43 == V_4 ) ?
V_84 : 0 ;
{
struct V_49 V_50 ;
F_19 ( V_25 -> V_36 , V_25 -> V_51 , V_58 -> V_43 ,
& V_58 -> V_67 , V_87 [ 0 ] , & V_58 -> V_71 ,
V_87 [ 1 ] , & V_50 ) ;
V_13 = F_30 ( & V_50 , & V_17 -> V_79 ,
V_17 -> V_72 ? V_17 -> V_72 : V_87 [ 1 ] ,
V_20 , V_17 , V_15 -> V_81 ) ;
if ( ! V_13 ) {
* V_56 = - 1 ;
return NULL ;
}
}
F_23 ( 6 , L_17
L_18 ,
F_38 ( V_13 ) ,
F_24 ( V_25 -> V_51 , & V_13 -> V_45 ) , F_25 ( V_13 -> V_46 ) ,
F_24 ( V_25 -> V_51 , & V_13 -> V_47 ) , F_25 ( V_13 -> V_48 ) ,
F_24 ( V_25 -> V_51 , & V_13 -> V_71 ) , F_25 ( V_13 -> V_60 ) ,
V_13 -> V_20 , F_39 ( & V_13 -> V_93 ) ) ;
F_15 ( V_13 , V_25 ) ;
return V_13 ;
}
int F_40 ( struct V_24 * V_25 , struct V_14 * V_15 ,
struct V_39 * V_40 , struct V_57 * V_58 )
{
T_1 V_86 [ 2 ] , * V_87 ;
#ifdef F_41
struct V_36 * V_36 ;
struct V_18 * V_19 ;
int V_94 ;
#endif
V_87 = F_34 ( V_15 , V_58 -> V_32 , sizeof( V_86 ) , V_86 , V_58 ) ;
if ( V_87 == NULL ) {
return V_95 ;
}
#ifdef F_41
V_36 = F_7 ( V_15 ) ;
#ifdef F_2
if ( V_25 -> V_51 == V_65 )
V_94 = F_42 ( & V_58 -> V_71 . V_66 ) & V_96 ;
else
#endif
V_94 = ( F_43 ( V_36 , V_58 -> V_71 . V_63 ) == V_97 ) ;
V_19 = F_6 ( V_36 ) ;
if ( V_19 -> V_98 && V_25 -> V_62 && V_94 ) {
int V_99 ;
struct V_12 * V_13 ;
unsigned int V_20 = ( V_25 -> V_20 & V_83 &&
V_58 -> V_43 == V_4 ) ?
V_84 : 0 ;
union V_44 V_71 = { . V_100 = { 0 , 0 , 0 , 0 } } ;
F_28 ( 6 , L_19 , V_101 ) ;
{
struct V_49 V_50 ;
F_19 ( V_25 -> V_36 , V_25 -> V_51 , V_58 -> V_43 ,
& V_58 -> V_67 , V_87 [ 0 ] ,
& V_58 -> V_71 , V_87 [ 1 ] , & V_50 ) ;
V_13 = F_30 ( & V_50 , & V_71 , 0 ,
V_102 | V_20 ,
NULL , V_15 -> V_81 ) ;
if ( ! V_13 )
return V_95 ;
}
F_5 ( V_13 , V_15 ) ;
F_16 ( V_13 , V_103 , V_15 , V_40 ) ;
V_99 = V_13 -> V_104 ( V_15 , V_13 , V_40 -> V_41 , V_58 ) ;
F_44 ( & V_13 -> V_105 ) ;
F_31 ( V_13 ) ;
return V_99 ;
}
#endif
if ( ( V_25 -> V_72 == V_73 ) && ( V_87 [ 1 ] != V_73 ) )
return V_106 ;
#ifdef F_2
if ( V_25 -> V_51 == V_65 ) {
if ( ! V_15 -> V_89 ) {
struct V_36 * V_107 = F_45 ( F_46 ( V_15 ) -> V_89 ) ;
V_15 -> V_89 = V_107 -> V_108 ;
}
F_47 ( V_15 , V_109 , V_110 , 0 ) ;
} else
#endif
F_48 ( V_15 , V_111 , V_112 , 0 ) ;
return V_95 ;
}
static int F_49 ( struct V_14 * V_15 )
{
struct V_18 * V_19 = F_6 ( F_7 ( V_15 ) ) ;
return V_19 -> F_49 ;
}
static int F_50 ( struct V_36 * V_36 )
{
struct V_18 * V_19 = F_6 ( V_36 ) ;
return V_19 -> F_50 ;
}
static int F_51 ( struct V_18 * V_19 )
{
return V_19 -> F_51 ;
}
static int F_49 ( struct V_14 * V_15 ) { return 0 ; }
static int F_50 ( struct V_36 * V_36 ) { return 0 ; }
static int F_51 ( struct V_18 * V_19 ) { return 0 ; }
T_2 F_52 ( struct V_14 * V_15 , int V_113 )
{
return F_53 ( F_54 ( V_15 , V_113 , V_15 -> V_32 - V_113 , 0 ) ) ;
}
static inline enum V_114 F_55 ( unsigned int V_115 )
{
if ( V_116 == V_115 )
return V_117 ;
if ( V_118 == V_115 )
return V_119 ;
return V_120 ;
}
static inline int F_56 ( struct V_14 * V_15 , T_3 V_121 )
{
int V_122 ;
F_57 () ;
V_122 = F_58 ( V_15 , V_121 ) ;
F_59 () ;
if ( ! V_122 )
F_60 ( F_61 ( V_15 ) ) ;
return V_122 ;
}
static int F_62 ( int V_51 , struct V_14 * V_15 )
{
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_49 ( V_15 ) && F_63 ( V_15 ) != 0 )
return 1 ;
} else
#endif
if ( ( F_49 ( V_15 ) ||
F_64 ( V_15 ) -> V_123 & V_124 ) &&
F_65 ( V_15 , V_125 ) != 0 )
return 1 ;
return 0 ;
}
void F_66 ( struct V_14 * V_15 , struct V_85 * V_41 ,
struct V_12 * V_13 , int V_126 )
{
struct V_127 * V_58 = F_61 ( V_15 ) ;
unsigned int V_128 = V_58 -> V_129 * 4 ;
struct V_130 * V_131 = (struct V_130 * ) ( F_67 ( V_15 ) +
V_128 ) ;
struct V_127 * V_132 = (struct V_127 * ) ( V_131 + 1 ) ;
if ( V_126 ) {
V_58 -> V_67 = V_13 -> V_47 . V_63 ;
F_60 ( V_58 ) ;
V_132 -> V_71 = V_13 -> V_47 . V_63 ;
F_60 ( V_132 ) ;
} else {
V_58 -> V_71 = V_13 -> V_71 . V_63 ;
F_60 ( V_58 ) ;
V_132 -> V_67 = V_13 -> V_71 . V_63 ;
F_60 ( V_132 ) ;
}
if ( V_5 == V_132 -> V_43 || V_4 == V_132 -> V_43 ||
V_6 == V_132 -> V_43 ) {
T_1 * V_133 = ( void * ) V_132 + V_132 -> V_129 * 4 ;
if ( V_126 )
V_133 [ 1 ] = V_13 -> V_48 ;
else
V_133 [ 0 ] = V_13 -> V_60 ;
}
V_131 -> V_134 = 0 ;
V_131 -> V_134 = F_52 ( V_15 , V_128 ) ;
V_15 -> V_135 = V_136 ;
if ( V_126 )
F_35 ( 11 , V_137 , V_41 , V_15 , ( void * ) V_132 - ( void * ) V_58 ,
L_20 ) ;
else
F_35 ( 11 , V_137 , V_41 , V_15 , ( void * ) V_132 - ( void * ) V_58 ,
L_21 ) ;
}
void F_68 ( struct V_14 * V_15 , struct V_85 * V_41 ,
struct V_12 * V_13 , int V_126 )
{
struct V_138 * V_58 = F_69 ( V_15 ) ;
unsigned int V_128 = 0 ;
unsigned int V_139 = 0 ;
int V_43 ;
struct V_140 * V_131 ;
struct V_138 * V_132 ;
unsigned short V_141 ;
F_70 ( V_15 , & V_128 , V_8 , & V_141 , NULL ) ;
V_131 = (struct V_140 * ) ( F_67 ( V_15 ) + V_128 ) ;
V_139 = V_128 + sizeof( struct V_140 ) ;
V_132 = (struct V_138 * ) ( F_67 ( V_15 ) + V_139 ) ;
V_43 = F_70 ( V_15 , & V_139 , - 1 , & V_141 , NULL ) ;
if ( V_126 ) {
V_58 -> V_67 = V_13 -> V_47 . V_66 ;
V_132 -> V_71 = V_13 -> V_47 . V_66 ;
} else {
V_58 -> V_71 = V_13 -> V_71 . V_66 ;
V_132 -> V_67 = V_13 -> V_71 . V_66 ;
}
if ( ! V_141 && ( V_5 == V_43 || V_4 == V_43 ||
V_6 == V_43 ) ) {
T_1 * V_133 = ( void * ) ( F_67 ( V_15 ) + V_139 ) ;
F_28 ( 11 , L_22 , V_101 ,
F_25 ( V_126 ? V_133 [ 1 ] : V_133 [ 0 ] ) ,
F_25 ( V_126 ? V_13 -> V_48 : V_13 -> V_60 ) ) ;
if ( V_126 )
V_133 [ 1 ] = V_13 -> V_48 ;
else
V_133 [ 0 ] = V_13 -> V_60 ;
}
V_131 -> V_142 = ~ F_71 ( & V_58 -> V_67 , & V_58 -> V_71 ,
V_15 -> V_32 - V_128 ,
V_8 , 0 ) ;
V_15 -> V_143 = F_67 ( V_15 ) - V_15 -> V_144 + V_128 ;
V_15 -> V_145 = F_72 ( struct V_140 , V_142 ) ;
V_15 -> V_135 = V_146 ;
if ( V_126 )
F_35 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_132 - ( void * ) V_58 ,
L_23 ) ;
else
F_35 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_132 - ( void * ) V_58 ,
L_24 ) ;
}
static int F_73 ( int V_51 , struct V_14 * V_15 ,
union V_44 * V_64 ,
T_4 V_43 , struct V_12 * V_13 ,
struct V_85 * V_41 ,
unsigned int V_113 , unsigned int V_129 )
{
unsigned int V_147 = V_95 ;
if ( F_74 ( V_13 ) != 0 ) {
F_37 ( L_25
L_26 ) ;
}
if ( ! F_75 ( V_15 ) && F_52 ( V_15 , V_129 ) ) {
F_23 ( 1 , L_27 ,
F_24 ( V_51 , V_64 ) ) ;
goto V_148;
}
if ( V_5 == V_43 || V_4 == V_43 ||
V_6 == V_43 )
V_113 += 2 * sizeof( V_149 ) ;
if ( ! F_76 ( V_15 , V_113 ) )
goto V_148;
#ifdef F_2
if ( V_51 == V_65 )
F_68 ( V_15 , V_41 , V_13 , 1 ) ;
else
#endif
F_66 ( V_15 , V_41 , V_13 , 1 ) ;
if ( F_62 ( V_51 , V_15 ) )
goto V_148;
F_14 ( V_13 , V_15 ) ;
V_15 -> V_150 = 1 ;
if ( ! ( V_13 -> V_20 & V_151 ) )
F_77 ( V_15 ) ;
else
F_78 ( V_15 , V_13 , 0 ) ;
V_147 = V_106 ;
V_148:
F_36 ( V_13 ) ;
return V_147 ;
}
static int F_79 ( struct V_14 * V_15 , int * V_152 ,
unsigned int V_115 )
{
struct V_127 * V_58 ;
struct V_130 V_153 , * V_154 ;
struct V_127 V_155 , * V_156 ;
struct V_57 V_132 ;
struct V_12 * V_13 ;
struct V_85 * V_41 ;
unsigned int V_113 , V_129 ;
union V_44 V_64 ;
* V_152 = 1 ;
if ( F_80 ( F_61 ( V_15 ) ) ) {
if ( F_56 ( V_15 , F_55 ( V_115 ) ) )
return V_157 ;
}
V_58 = F_61 ( V_15 ) ;
V_113 = V_129 = V_58 -> V_129 * 4 ;
V_154 = F_81 ( V_15 , V_113 , sizeof( V_153 ) , & V_153 ) ;
if ( V_154 == NULL )
return V_95 ;
F_28 ( 12 , L_28 ,
V_154 -> type , F_25 ( F_82 ( V_154 ) ) ,
& V_58 -> V_67 , & V_58 -> V_71 ) ;
if ( ( V_154 -> type != V_111 ) &&
( V_154 -> type != V_158 ) &&
( V_154 -> type != V_159 ) ) {
* V_152 = 0 ;
return V_106 ;
}
V_113 += sizeof( V_153 ) ;
V_156 = F_81 ( V_15 , V_113 , sizeof( V_155 ) , & V_155 ) ;
if ( V_156 == NULL )
return V_106 ;
V_41 = F_83 ( V_156 -> V_43 ) ;
if ( ! V_41 )
return V_106 ;
if ( F_84 ( V_156 -> V_160 & F_85 ( V_161 ) &&
V_41 -> V_162 ) )
return V_106 ;
F_35 ( 11 , V_137 , V_41 , V_15 , V_113 ,
L_29 ) ;
F_86 ( V_156 , & V_132 ) ;
V_132 . V_32 += V_113 ;
V_13 = V_41 -> V_163 ( V_137 , V_15 , & V_132 , 1 ) ;
if ( ! V_13 )
return V_106 ;
V_64 . V_63 = V_58 -> V_67 ;
return F_73 ( V_137 , V_15 , & V_64 , V_156 -> V_43 , V_13 ,
V_41 , V_132 . V_32 , V_129 ) ;
}
static int F_87 ( struct V_14 * V_15 , int * V_152 ,
unsigned int V_115 , struct V_57 * V_164 )
{
struct V_140 V_153 , * V_154 ;
struct V_138 V_165 , * V_166 ;
struct V_57 V_132 = { . V_20 = 0 , . V_141 = 0 } ;
struct V_12 * V_13 ;
struct V_85 * V_41 ;
union V_44 V_64 ;
unsigned int V_167 ;
* V_152 = 1 ;
V_154 = F_34 ( V_15 , V_164 -> V_32 , sizeof( V_153 ) , & V_153 , V_164 ) ;
if ( V_154 == NULL )
return V_95 ;
if ( V_154 -> V_168 & V_169 ) {
* V_152 = 0 ;
return V_106 ;
}
if ( V_164 -> V_20 & V_170 )
return V_95 ;
F_28 ( 8 , L_30 ,
V_154 -> V_168 , F_25 ( F_88 ( V_154 ) ) ,
& V_164 -> V_67 , & V_164 -> V_71 ) ;
V_132 . V_32 = V_164 -> V_32 + sizeof( V_153 ) ;
V_166 = F_81 ( V_15 , V_132 . V_32 , sizeof( V_165 ) , & V_165 ) ;
if ( V_166 == NULL )
return V_106 ;
V_132 . V_67 . V_66 = V_166 -> V_67 ;
V_132 . V_71 . V_66 = V_166 -> V_71 ;
V_132 . V_43 = F_70 ( V_15 , & V_132 . V_32 , - 1 , & V_132 . V_141 , NULL ) ;
if ( V_132 . V_43 < 0 )
return V_106 ;
V_41 = F_83 ( V_132 . V_43 ) ;
if ( ! V_41 )
return V_106 ;
V_13 = V_41 -> V_163 ( V_65 , V_15 , & V_132 , 1 ) ;
if ( ! V_13 )
return V_106 ;
V_64 . V_66 = V_132 . V_67 . V_66 ;
V_167 = V_132 . V_32 ;
return F_73 ( V_65 , V_15 , & V_64 , V_132 . V_43 , V_13 ,
V_41 , V_167 , sizeof( struct V_138 ) ) ;
}
static inline int F_89 ( const struct V_14 * V_15 , int V_171 )
{
T_5 * V_172 , V_173 ;
V_172 = F_81 ( V_15 , V_171 + sizeof( V_174 ) ,
sizeof( V_173 ) , & V_173 ) ;
if ( V_172 == NULL )
return 0 ;
if ( V_172 -> type == V_175 )
return 1 ;
return 0 ;
}
static inline int F_90 ( const struct V_14 * V_15 , int V_171 )
{
struct V_176 V_177 , * V_178 ;
V_178 = F_81 ( V_15 , V_171 , sizeof( V_177 ) , & V_177 ) ;
if ( V_178 == NULL )
return 0 ;
return V_178 -> V_179 ;
}
static inline bool F_91 ( const struct V_14 * V_15 ,
struct V_57 * V_58 )
{
switch ( V_58 -> V_43 ) {
case V_5 : {
struct V_176 V_177 , * V_178 ;
V_178 = F_81 ( V_15 , V_58 -> V_32 , sizeof( V_177 ) , & V_177 ) ;
if ( V_178 == NULL )
return false ;
return V_178 -> V_180 ;
}
case V_6 : {
T_5 * V_172 , V_173 ;
V_172 = F_81 ( V_15 , V_58 -> V_32 + sizeof( V_174 ) ,
sizeof( V_173 ) , & V_173 ) ;
if ( V_172 == NULL )
return false ;
return V_172 -> type == V_181 ;
}
default:
return false ;
}
}
static unsigned int
F_92 ( int V_51 , struct V_14 * V_15 , struct V_39 * V_40 ,
struct V_12 * V_13 , struct V_57 * V_58 )
{
struct V_85 * V_41 = V_40 -> V_41 ;
F_35 ( 11 , V_51 , V_41 , V_15 , 0 , L_31 ) ;
if ( ! F_76 ( V_15 , V_58 -> V_32 ) )
goto V_182;
if ( V_41 -> V_183 && ! V_41 -> V_183 ( V_15 , V_41 , V_13 , V_58 ) )
goto V_182;
#ifdef F_2
if ( V_51 == V_65 )
F_69 ( V_15 ) -> V_67 = V_13 -> V_47 . V_66 ;
else
#endif
{
F_61 ( V_15 ) -> V_67 = V_13 -> V_47 . V_63 ;
F_60 ( F_61 ( V_15 ) ) ;
}
if ( F_62 ( V_51 , V_15 ) )
goto V_182;
F_35 ( 10 , V_51 , V_41 , V_15 , 0 , L_32 ) ;
F_14 ( V_13 , V_15 ) ;
F_16 ( V_13 , V_184 , V_15 , V_40 ) ;
V_15 -> V_150 = 1 ;
if ( ! ( V_13 -> V_20 & V_151 ) )
F_77 ( V_15 ) ;
else
F_78 ( V_15 , V_13 , 0 ) ;
F_31 ( V_13 ) ;
F_93 ( 11 ) ;
return V_106 ;
V_182:
F_31 ( V_13 ) ;
F_94 ( V_15 ) ;
F_93 ( 11 ) ;
return V_157 ;
}
static unsigned int
F_95 ( unsigned int V_115 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 = NULL ;
struct V_57 V_58 ;
struct V_85 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
F_96 ( 11 ) ;
if ( V_15 -> V_150 )
return V_106 ;
if ( F_84 ( V_15 -> V_185 != NULL && V_115 == V_186 &&
V_51 == V_137 ) ) {
struct V_187 * V_185 = V_15 -> V_185 ;
struct V_188 * V_189 = F_97 ( V_15 -> V_185 ) ;
if ( V_189 && V_185 -> V_190 == V_191 && V_189 -> V_192 )
return V_106 ;
}
if ( F_84 ( ! F_46 ( V_15 ) ) )
return V_106 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_193 )
return V_106 ;
F_98 ( V_51 , V_15 , & V_58 ) ;
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_84 ( V_58 . V_43 == V_8 ) ) {
int V_152 ;
int V_147 = F_87 ( V_15 , & V_152 ,
V_115 , & V_58 ) ;
if ( V_152 )
return V_147 ;
}
} else
#endif
if ( F_84 ( V_58 . V_43 == V_7 ) ) {
int V_152 ;
int V_147 = F_79 ( V_15 , & V_152 , V_115 ) ;
if ( V_152 )
return V_147 ;
}
V_40 = F_99 ( V_36 , V_58 . V_43 ) ;
if ( F_84 ( ! V_40 ) )
return V_106 ;
V_41 = V_40 -> V_41 ;
#ifdef F_2
if ( V_51 == V_137 )
#endif
if ( F_84 ( F_80 ( F_61 ( V_15 ) ) && ! V_41 -> V_162 ) ) {
if ( F_56 ( V_15 ,
F_55 ( V_115 ) ) )
return V_157 ;
F_86 ( F_67 ( V_15 ) , & V_58 ) ;
}
V_13 = V_41 -> V_163 ( V_51 , V_15 , & V_58 , 0 ) ;
if ( F_17 ( V_13 ) )
return F_92 ( V_51 , V_15 , V_40 , V_13 , & V_58 ) ;
if ( F_50 ( V_36 ) &&
( V_41 -> V_43 == V_5 ||
V_41 -> V_43 == V_4 ||
V_41 -> V_43 == V_6 ) ) {
T_1 V_86 [ 2 ] , * V_87 ;
V_87 = F_34 ( V_15 , V_58 . V_32 ,
sizeof( V_86 ) , V_86 , & V_58 ) ;
if ( V_87 == NULL )
return V_106 ;
if ( F_100 ( V_36 , V_51 , V_58 . V_43 , & V_58 . V_67 ,
V_87 [ 0 ] ) ) {
if ( ( V_58 . V_43 != V_5 &&
V_58 . V_43 != V_6 )
|| ( ( V_58 . V_43 == V_5
&& ! F_90 ( V_15 , V_58 . V_32 ) )
|| ( V_58 . V_43 == V_6
&& ! F_89 ( V_15 ,
V_58 . V_32 ) ) ) ) {
#ifdef F_2
if ( V_51 == V_65 ) {
if ( ! V_15 -> V_89 )
V_15 -> V_89 = V_36 -> V_108 ;
F_47 ( V_15 ,
V_109 ,
V_110 ,
0 ) ;
} else
#endif
F_48 ( V_15 ,
V_111 ,
V_112 , 0 ) ;
return V_95 ;
}
}
}
F_35 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_33 ) ;
return V_106 ;
}
static unsigned int
F_101 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_95 ( V_195 -> V_115 , V_15 , V_137 ) ;
}
static unsigned int
F_103 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_95 ( V_195 -> V_115 , V_15 , V_137 ) ;
}
static unsigned int
F_104 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_95 ( V_195 -> V_115 , V_15 , V_65 ) ;
}
static unsigned int
F_105 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_95 ( V_195 -> V_115 , V_15 , V_65 ) ;
}
static int
F_106 ( struct V_14 * V_15 , int * V_152 , unsigned int V_115 )
{
struct V_36 * V_36 = NULL ;
struct V_127 * V_58 ;
struct V_130 V_153 , * V_154 ;
struct V_127 V_155 , * V_156 ;
struct V_57 V_132 ;
struct V_12 * V_13 ;
struct V_85 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_113 , V_198 , V_129 , V_147 ;
bool V_199 ;
* V_152 = 1 ;
if ( F_80 ( F_61 ( V_15 ) ) ) {
if ( F_56 ( V_15 , F_55 ( V_115 ) ) )
return V_157 ;
}
V_58 = F_61 ( V_15 ) ;
V_113 = V_129 = V_58 -> V_129 * 4 ;
V_154 = F_81 ( V_15 , V_113 , sizeof( V_153 ) , & V_153 ) ;
if ( V_154 == NULL )
return V_95 ;
F_28 ( 12 , L_34 ,
V_154 -> type , F_25 ( F_82 ( V_154 ) ) ,
& V_58 -> V_67 , & V_58 -> V_71 ) ;
if ( ( V_154 -> type != V_111 ) &&
( V_154 -> type != V_158 ) &&
( V_154 -> type != V_159 ) ) {
* V_152 = 0 ;
return V_106 ;
}
V_113 += sizeof( V_153 ) ;
V_156 = F_81 ( V_15 , V_113 , sizeof( V_155 ) , & V_155 ) ;
if ( V_156 == NULL )
return V_106 ;
V_36 = F_7 ( V_15 ) ;
V_199 = false ;
if ( V_156 -> V_43 == V_200 ) {
if ( F_84 ( V_156 -> V_160 & F_85 ( V_161 ) ) )
return V_106 ;
if ( ! ( F_64 ( V_15 ) -> V_123 & V_124 ) )
return V_106 ;
V_113 += V_156 -> V_129 * 4 ;
V_156 = F_81 ( V_15 , V_113 , sizeof( V_155 ) , & V_155 ) ;
if ( V_156 == NULL )
return V_106 ;
V_199 = true ;
}
V_40 = F_99 ( V_36 , V_156 -> V_43 ) ;
if ( ! V_40 )
return V_106 ;
V_41 = V_40 -> V_41 ;
if ( F_84 ( V_156 -> V_160 & F_85 ( V_161 ) &&
V_41 -> V_162 ) )
return V_106 ;
F_35 ( 11 , V_137 , V_41 , V_15 , V_113 ,
L_35 ) ;
V_198 = V_113 ;
F_86 ( V_156 , & V_132 ) ;
V_132 . V_32 += V_113 ;
V_113 = V_132 . V_32 ;
V_13 = V_41 -> V_91 ( V_137 , V_15 , & V_132 , V_199 ? 0 : 1 ) ;
if ( ! V_13 )
return V_106 ;
V_147 = V_95 ;
if ( ! F_75 ( V_15 ) && F_52 ( V_15 , V_129 ) ) {
F_28 ( 1 , L_36 ,
& V_58 -> V_67 ) ;
goto V_148;
}
if ( V_199 ) {
T_6 V_201 = V_154 -> V_202 . V_203 ;
if ( V_154 -> type == V_111 &&
V_154 -> V_204 == V_205 ) {
struct V_16 * V_17 = V_13 -> V_17 ;
T_7 V_206 = F_25 ( V_154 -> V_202 . V_207 . V_206 ) ;
F_107 ( V_15 , V_129 + sizeof( V_153 ) ) ;
V_198 -= V_129 + sizeof( V_153 ) ;
F_108 ( V_15 ) ;
F_28 ( 12 , L_37 ,
& F_61 ( V_15 ) -> V_67 , & F_61 ( V_15 ) -> V_71 , V_206 ) ;
F_109 ( V_15 , F_45 ( V_15 -> V_89 ) ,
V_206 , 0 , 0 , 0 , 0 ) ;
if ( ! ( V_156 -> V_160 & F_85 ( V_208 ) ) )
goto V_209;
if ( V_17 ) {
struct V_210 * V_211 ;
F_11 () ;
V_211 = F_12 ( V_17 -> V_211 ) ;
if ( V_211 )
V_206 = F_110 ( V_211 -> V_212 ) ;
F_13 () ;
}
if ( V_206 > 68 + sizeof( struct V_127 ) )
V_206 -= sizeof( struct V_127 ) ;
V_201 = F_21 ( V_206 ) ;
}
F_107 ( V_15 , V_198 ) ;
F_108 ( V_15 ) ;
F_28 ( 12 , L_38 ,
& F_61 ( V_15 ) -> V_67 , & F_61 ( V_15 ) -> V_71 ,
V_154 -> type , V_154 -> V_204 , F_111 ( V_201 ) ) ;
F_48 ( V_15 , V_154 -> type , V_154 -> V_204 , V_201 ) ;
F_14 ( V_13 , V_15 ) ;
V_209:
F_112 ( V_15 ) ;
V_147 = V_157 ;
goto V_148;
}
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_156 -> V_43 || V_4 == V_156 -> V_43 ||
V_6 == V_156 -> V_43 )
V_113 += 2 * sizeof( V_149 ) ;
V_147 = F_113 ( V_15 , V_13 , V_41 , V_113 , V_115 , & V_132 ) ;
V_148:
F_36 ( V_13 ) ;
return V_147 ;
}
static int F_114 ( struct V_14 * V_15 , int * V_152 ,
unsigned int V_115 , struct V_57 * V_58 )
{
struct V_36 * V_36 = NULL ;
struct V_138 V_165 , * V_166 ;
struct V_140 V_153 , * V_154 ;
struct V_57 V_132 = { . V_20 = 0 , . V_141 = 0 } ;
struct V_12 * V_13 ;
struct V_85 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_213 , V_167 , V_147 ;
* V_152 = 1 ;
V_154 = F_34 ( V_15 , V_58 -> V_32 , sizeof( V_153 ) , & V_153 , V_58 ) ;
if ( V_154 == NULL )
return V_95 ;
if ( V_154 -> V_168 & V_169 ) {
* V_152 = 0 ;
return V_106 ;
}
if ( V_58 -> V_20 & V_170 )
return V_95 ;
F_28 ( 8 , L_39 ,
V_154 -> V_168 , F_25 ( F_88 ( V_154 ) ) ,
& V_58 -> V_67 , & V_58 -> V_71 ) ;
V_132 . V_32 = V_58 -> V_32 + sizeof( V_153 ) ;
V_213 = V_132 . V_32 ;
V_166 = F_81 ( V_15 , V_132 . V_32 , sizeof( V_165 ) , & V_165 ) ;
if ( V_166 == NULL )
return V_106 ;
V_132 . V_67 . V_66 = V_166 -> V_67 ;
V_132 . V_71 . V_66 = V_166 -> V_71 ;
V_132 . V_43 = F_70 ( V_15 , & V_132 . V_32 , - 1 , & V_132 . V_141 , NULL ) ;
if ( V_132 . V_43 < 0 )
return V_106 ;
V_36 = F_7 ( V_15 ) ;
V_40 = F_99 ( V_36 , V_132 . V_43 ) ;
if ( ! V_40 )
return V_106 ;
V_41 = V_40 -> V_41 ;
if ( V_132 . V_141 )
return V_106 ;
F_35 ( 11 , V_65 , V_41 , V_15 , V_213 ,
L_40 ) ;
V_13 = V_41 -> V_91 ( V_65 , V_15 , & V_132 ,
( V_115 == V_186 ) ? 0 : 1 ) ;
if ( ! V_13 )
return V_106 ;
if ( ( V_115 == V_186 ) &&
( F_74 ( V_13 ) != V_214 ) ) {
F_36 ( V_13 ) ;
return V_106 ;
}
F_5 ( V_13 , V_15 ) ;
V_167 = V_132 . V_32 ;
if ( V_5 == V_132 . V_43 || V_4 == V_132 . V_43 ||
V_6 == V_132 . V_43 )
V_167 += 2 * sizeof( V_149 ) ;
V_147 = F_115 ( V_15 , V_13 , V_41 , V_167 , V_115 , & V_132 ) ;
F_36 ( V_13 ) ;
return V_147 ;
}
static unsigned int
F_116 ( unsigned int V_115 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 ;
struct V_57 V_58 ;
struct V_85 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
int V_99 , V_215 ;
struct V_18 * V_19 ;
if ( V_15 -> V_150 )
return V_106 ;
if ( F_84 ( ( V_15 -> V_216 != V_217 &&
V_115 != V_186 ) ||
! F_46 ( V_15 ) ) ) {
F_98 ( V_51 , V_15 , & V_58 ) ;
F_23 ( 12 , L_41
L_42 ,
V_15 -> V_216 , V_58 . V_43 ,
F_24 ( V_51 , & V_58 . V_71 ) , V_115 ) ;
return V_106 ;
}
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_84 ( F_117 ( V_19 ) || ! V_19 -> V_193 ) )
return V_106 ;
F_98 ( V_51 , V_15 , & V_58 ) ;
if ( F_84 ( V_15 -> V_185 != NULL && V_115 == V_186 &&
V_51 == V_137 ) ) {
struct V_187 * V_185 = V_15 -> V_185 ;
struct V_188 * V_189 = F_97 ( V_15 -> V_185 ) ;
if ( V_189 && V_185 -> V_190 == V_191 && V_189 -> V_192 )
return V_106 ;
}
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_84 ( V_58 . V_43 == V_8 ) ) {
int V_152 ;
int V_147 = F_114 ( V_15 , & V_152 , V_115 ,
& V_58 ) ;
if ( V_152 )
return V_147 ;
}
} else
#endif
if ( F_84 ( V_58 . V_43 == V_7 ) ) {
int V_152 ;
int V_147 = F_106 ( V_15 , & V_152 , V_115 ) ;
if ( V_152 )
return V_147 ;
}
V_40 = F_99 ( V_36 , V_58 . V_43 ) ;
if ( F_84 ( ! V_40 ) )
return V_106 ;
V_41 = V_40 -> V_41 ;
V_13 = V_41 -> V_91 ( V_51 , V_15 , & V_58 , 0 ) ;
if ( F_84 ( F_51 ( V_19 ) ) && V_13 && V_13 -> V_17 &&
F_84 ( ! F_39 ( & V_13 -> V_17 -> V_218 ) ) && ! V_58 . V_141 &&
F_91 ( V_15 , & V_58 ) ) {
F_118 ( V_13 ) ;
F_36 ( V_13 ) ;
V_13 = NULL ;
}
if ( F_84 ( ! V_13 ) && ! V_58 . V_141 ) {
int V_219 ;
if ( ! V_41 -> V_220 ( V_51 , V_15 , V_40 , & V_219 , & V_13 , & V_58 ) )
return V_219 ;
}
if ( F_84 ( ! V_13 ) ) {
F_35 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_43 ) ;
if ( V_58 . V_141 ) {
F_119 ( L_44 ) ;
F_35 ( 7 , V_51 , V_41 , V_15 , 0 , L_45 ) ;
}
return V_106 ;
}
F_35 ( 11 , V_51 , V_41 , V_15 , 0 , L_46 ) ;
if ( V_13 -> V_17 && ! ( V_13 -> V_17 -> V_20 & V_21 ) ) {
if ( F_51 ( V_19 ) ) {
F_118 ( V_13 ) ;
}
F_36 ( V_13 ) ;
return V_95 ;
}
F_5 ( V_13 , V_15 ) ;
F_16 ( V_13 , V_103 , V_15 , V_40 ) ;
if ( V_13 -> V_104 )
V_99 = V_13 -> V_104 ( V_15 , V_13 , V_41 , & V_58 ) ;
else {
F_119 ( L_47 ) ;
V_99 = V_106 ;
}
if ( V_13 -> V_20 & V_84 )
V_215 = F_120 ( V_19 ) ;
else
V_215 = F_121 ( 1 , & V_13 -> V_105 ) ;
if ( V_19 -> V_221 & V_222 )
F_122 ( V_36 , V_13 , V_215 ) ;
F_31 ( V_13 ) ;
return V_99 ;
}
static unsigned int
F_123 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 ,
const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_116 ( V_195 -> V_115 , V_15 , V_137 ) ;
}
static unsigned int
F_124 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_116 ( V_195 -> V_115 , V_15 , V_137 ) ;
}
static unsigned int
F_125 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 ,
const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_116 ( V_195 -> V_115 , V_15 , V_65 ) ;
}
static unsigned int
F_126 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
return F_116 ( V_195 -> V_115 , V_15 , V_65 ) ;
}
static unsigned int
F_127 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
int V_223 ;
struct V_36 * V_36 ;
struct V_18 * V_19 ;
if ( F_61 ( V_15 ) -> V_43 != V_7 )
return V_106 ;
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_84 ( F_117 ( V_19 ) || ! V_19 -> V_193 ) )
return V_106 ;
return F_106 ( V_15 , & V_223 , V_195 -> V_115 ) ;
}
static unsigned int
F_128 ( const struct V_194 * V_195 , struct V_14 * V_15 ,
const struct V_196 * V_197 , const struct V_196 * V_148 ,
int (* F_102)( struct V_14 * ) )
{
int V_223 ;
struct V_36 * V_36 ;
struct V_18 * V_19 ;
struct V_57 V_127 ;
F_98 ( V_65 , V_15 , & V_127 ) ;
if ( V_127 . V_43 != V_8 )
return V_106 ;
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_84 ( F_117 ( V_19 ) || ! V_19 -> V_193 ) )
return V_106 ;
return F_114 ( V_15 , & V_223 , V_195 -> V_115 , & V_127 ) ;
}
static int T_8 F_129 ( struct V_36 * V_36 )
{
struct V_18 * V_19 ;
V_19 = F_130 ( V_36 , V_224 ) ;
if ( V_19 == NULL )
return - V_225 ;
V_19 -> V_193 = 0 ;
V_19 -> V_36 = V_36 ;
V_19 -> V_226 = F_39 ( & V_227 ) ;
F_44 ( & V_227 ) ;
V_36 -> V_19 = V_19 ;
if ( F_131 ( V_36 ) < 0 )
goto V_228;
if ( F_132 ( V_36 ) < 0 )
goto V_229;
if ( F_133 ( V_36 ) < 0 )
goto V_230;
if ( F_134 ( V_36 ) < 0 )
goto V_231;
if ( F_135 ( V_36 ) < 0 )
goto V_232;
if ( F_136 ( V_36 ) < 0 )
goto V_233;
F_137 ( V_234 L_48 ,
sizeof( struct V_18 ) , V_19 -> V_226 ) ;
return 0 ;
V_233:
F_138 ( V_36 ) ;
V_232:
F_139 ( V_36 ) ;
V_231:
F_140 ( V_36 ) ;
V_230:
F_141 ( V_36 ) ;
V_229:
F_142 ( V_36 ) ;
V_228:
V_36 -> V_19 = NULL ;
return - V_225 ;
}
static void T_9 F_143 ( struct V_36 * V_36 )
{
F_144 ( V_36 ) ;
F_138 ( V_36 ) ;
F_139 ( V_36 ) ;
F_140 ( V_36 ) ;
F_141 ( V_36 ) ;
F_142 ( V_36 ) ;
F_28 ( 2 , L_49 , F_6 ( V_36 ) -> V_226 ) ;
V_36 -> V_19 = NULL ;
}
static void T_9 F_145 ( struct V_36 * V_36 )
{
F_96 ( 2 ) ;
F_6 ( V_36 ) -> V_193 = 0 ;
F_146 () ;
F_147 ( V_36 ) ;
F_93 ( 2 ) ;
}
static int T_10 F_148 ( void )
{
int V_99 ;
V_99 = F_149 () ;
if ( V_99 < 0 ) {
F_37 ( L_50 ) ;
goto exit;
}
F_150 () ;
V_99 = F_151 () ;
if ( V_99 < 0 ) {
F_37 ( L_51 ) ;
goto V_235;
}
V_99 = F_152 ( & V_236 ) ;
if ( V_99 < 0 )
goto V_237;
V_99 = F_153 ( & V_238 ) ;
if ( V_99 < 0 )
goto V_239;
V_99 = F_154 ( V_240 , F_155 ( V_240 ) ) ;
if ( V_99 < 0 ) {
F_37 ( L_52 ) ;
goto V_241;
}
V_99 = F_156 () ;
if ( V_99 < 0 ) {
F_37 ( L_53 ) ;
goto V_242;
}
F_157 ( L_54 ) ;
return V_99 ;
V_242:
F_158 ( V_240 , F_155 ( V_240 ) ) ;
V_241:
F_159 ( & V_238 ) ;
V_239:
F_160 ( & V_236 ) ;
V_237:
F_161 () ;
V_235:
F_162 () ;
F_163 () ;
exit:
return V_99 ;
}
static void T_11 F_164 ( void )
{
F_165 () ;
F_158 ( V_240 , F_155 ( V_240 ) ) ;
F_159 ( & V_238 ) ;
F_160 ( & V_236 ) ;
F_161 () ;
F_162 () ;
F_163 () ;
F_157 ( L_55 ) ;
}
