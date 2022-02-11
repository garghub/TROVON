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
V_23 = F_8 ( V_17 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_27 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_29 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
V_23 = F_8 ( V_17 -> V_31 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_27 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_29 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
V_23 = F_8 ( V_19 -> V_32 . V_25 ) ;
V_23 -> V_26 . V_27 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_29 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
}
}
static inline void
F_11 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
struct V_18 * V_19 = F_6 ( F_7 ( V_15 ) ) ;
if ( V_17 && ( V_17 -> V_20 & V_21 ) ) {
struct V_22 * V_23 ;
V_23 = F_8 ( V_17 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_33 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_34 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
V_23 = F_8 ( V_17 -> V_31 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_33 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_34 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
V_23 = F_8 ( V_19 -> V_32 . V_25 ) ;
V_23 -> V_26 . V_33 ++ ;
F_9 ( & V_23 -> V_28 ) ;
V_23 -> V_26 . V_34 += V_15 -> V_30 ;
F_10 ( & V_23 -> V_28 ) ;
}
}
static inline void
F_12 ( struct V_12 * V_13 , struct V_35 * V_31 )
{
struct V_18 * V_19 = F_6 ( V_31 -> V_36 ) ;
struct V_22 * V_23 ;
V_23 = F_8 ( V_13 -> V_17 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_37 ++ ;
V_23 = F_8 ( V_31 -> V_24 . V_25 ) ;
V_23 -> V_26 . V_37 ++ ;
V_23 = F_8 ( V_19 -> V_32 . V_25 ) ;
V_23 -> V_26 . V_37 ++ ;
}
static inline void
F_13 ( struct V_12 * V_13 , int V_38 ,
const struct V_14 * V_15 ,
struct V_39 * V_40 )
{
if ( F_14 ( V_40 -> V_41 -> V_42 ) )
V_40 -> V_41 -> V_42 ( V_13 , V_38 , V_15 , V_40 ) ;
}
static inline int
F_15 ( const struct V_35 * V_31 ,
struct V_14 * V_15 , int V_43 ,
const union V_44 * V_45 , T_1 V_46 ,
const union V_44 * V_47 , T_1 V_48 ,
struct V_49 * V_50 )
{
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_43 , V_45 , V_46 , V_47 ,
V_48 , V_50 ) ;
V_50 -> V_52 = V_31 -> V_52 ;
if ( V_50 -> V_52 && V_50 -> V_52 -> V_53 )
return V_50 -> V_52 -> V_53 ( V_50 , V_15 ) ;
return 0 ;
}
static struct V_12 *
F_17 ( struct V_35 * V_31 ,
struct V_14 * V_15 , T_1 V_54 , T_1 V_55 ,
int * V_56 , struct V_57 * V_58 )
{
struct V_12 * V_13 = NULL ;
struct V_16 * V_17 ;
struct V_12 * V_59 ;
T_1 V_60 = 0 ;
unsigned int V_20 ;
struct V_49 V_61 ;
const union V_44 V_62 = { . V_63 = F_18 (svc->fwmark) } ;
union V_44 V_64 ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 )
F_19 ( & V_64 . V_66 , & V_58 -> V_67 . V_66 , V_31 -> V_68 ) ;
else
#endif
V_64 . V_63 = V_58 -> V_67 . V_63 & V_31 -> V_68 ;
F_20 ( 6 , L_8
L_9 ,
F_21 ( V_31 -> V_51 , & V_58 -> V_67 ) , F_22 ( V_54 ) ,
F_21 ( V_31 -> V_51 , & V_58 -> V_69 ) , F_22 ( V_55 ) ,
F_21 ( V_31 -> V_51 , & V_64 ) ) ;
{
int V_43 = V_58 -> V_43 ;
const union V_44 * V_47 = & V_58 -> V_69 ;
T_1 V_48 = 0 ;
if ( V_55 == V_31 -> V_70 ) {
if ( V_31 -> V_70 != V_71 )
V_48 = V_55 ;
} else {
if ( V_31 -> V_62 ) {
V_43 = V_3 ;
V_47 = & V_62 ;
}
}
if ( F_15 ( V_31 , V_15 , V_43 , & V_64 , 0 ,
V_47 , V_48 , & V_61 ) < 0 ) {
* V_56 = - 1 ;
return NULL ;
}
}
V_59 = F_23 ( & V_61 ) ;
if ( ! V_59 || ! F_24 ( V_59 ) ) {
V_17 = V_31 -> V_72 -> V_73 ( V_31 , V_15 ) ;
if ( ! V_17 ) {
F_25 ( 1 , L_10 ) ;
F_26 ( V_61 . V_74 ) ;
* V_56 = 0 ;
return NULL ;
}
if ( V_55 == V_31 -> V_70 && V_31 -> V_70 != V_71 )
V_60 = V_17 -> V_70 ;
V_59 = F_27 ( & V_61 , & V_17 -> V_75 , V_60 ,
V_76 , V_17 , V_15 -> V_77 ) ;
if ( V_59 == NULL ) {
F_26 ( V_61 . V_74 ) ;
* V_56 = - 1 ;
return NULL ;
}
V_59 -> V_78 = V_31 -> V_78 ;
} else {
V_17 = V_59 -> V_17 ;
F_26 ( V_61 . V_74 ) ;
}
V_60 = V_55 ;
if ( V_60 == V_31 -> V_70 && V_17 -> V_70 )
V_60 = V_17 -> V_70 ;
V_20 = ( V_31 -> V_20 & V_79
&& V_58 -> V_43 == V_4 ) ?
V_80 : 0 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 -> V_43 , & V_58 -> V_67 ,
V_54 , & V_58 -> V_69 , V_55 , & V_61 ) ;
V_13 = F_27 ( & V_61 , & V_17 -> V_75 , V_60 , V_20 , V_17 , V_15 -> V_77 ) ;
if ( V_13 == NULL ) {
F_28 ( V_59 ) ;
* V_56 = - 1 ;
return NULL ;
}
F_29 ( V_13 , V_59 ) ;
F_28 ( V_59 ) ;
F_12 ( V_13 , V_31 ) ;
return V_13 ;
}
struct V_12 *
F_30 ( struct V_35 * V_31 , struct V_14 * V_15 ,
struct V_39 * V_40 , int * V_56 ,
struct V_57 * V_58 )
{
struct V_81 * V_41 = V_40 -> V_41 ;
struct V_12 * V_13 = NULL ;
struct V_16 * V_17 ;
T_1 V_82 [ 2 ] , * V_83 ;
unsigned int V_20 ;
* V_56 = 1 ;
V_83 = F_31 ( V_15 , V_58 -> V_30 , sizeof( V_82 ) , V_82 , V_58 ) ;
if ( V_83 == NULL )
return NULL ;
if ( V_83 [ 0 ] == V_84 ) {
F_32 ( 12 , V_31 -> V_51 , V_41 , V_15 , 0 ,
L_11 ) ;
return NULL ;
}
if ( ( ! V_15 -> V_85 || V_15 -> V_85 -> V_20 & V_86 ) &&
( V_13 = V_41 -> V_87 ( V_31 -> V_51 , V_15 , V_58 , 1 ) ) ) {
F_32 ( 12 , V_31 -> V_51 , V_41 , V_15 , 0 ,
L_12 ) ;
F_33 ( V_13 ) ;
return NULL ;
}
if ( V_31 -> V_20 & V_88 )
return F_17 ( V_31 , V_15 , V_83 [ 0 ] , V_83 [ 1 ] , V_56 ,
V_58 ) ;
* V_56 = 0 ;
if ( ! V_31 -> V_62 && V_83 [ 1 ] != V_31 -> V_70 ) {
if ( ! V_31 -> V_70 )
F_34 ( L_13
L_14
L_15 ) ;
return NULL ;
}
V_17 = V_31 -> V_72 -> V_73 ( V_31 , V_15 ) ;
if ( V_17 == NULL ) {
F_25 ( 1 , L_16 ) ;
return NULL ;
}
V_20 = ( V_31 -> V_20 & V_79
&& V_58 -> V_43 == V_4 ) ?
V_80 : 0 ;
{
struct V_49 V_50 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 -> V_43 ,
& V_58 -> V_67 , V_83 [ 0 ] , & V_58 -> V_69 ,
V_83 [ 1 ] , & V_50 ) ;
V_13 = F_27 ( & V_50 , & V_17 -> V_75 ,
V_17 -> V_70 ? V_17 -> V_70 : V_83 [ 1 ] ,
V_20 , V_17 , V_15 -> V_77 ) ;
if ( ! V_13 ) {
* V_56 = - 1 ;
return NULL ;
}
}
F_20 ( 6 , L_17
L_18 ,
F_35 ( V_13 ) ,
F_21 ( V_31 -> V_51 , & V_13 -> V_45 ) , F_22 ( V_13 -> V_46 ) ,
F_21 ( V_31 -> V_51 , & V_13 -> V_47 ) , F_22 ( V_13 -> V_48 ) ,
F_21 ( V_31 -> V_51 , & V_13 -> V_69 ) , F_22 ( V_13 -> V_60 ) ,
V_13 -> V_20 , F_36 ( & V_13 -> V_89 ) ) ;
F_12 ( V_13 , V_31 ) ;
return V_13 ;
}
int F_37 ( struct V_35 * V_31 , struct V_14 * V_15 ,
struct V_39 * V_40 , struct V_57 * V_58 )
{
T_1 V_82 [ 2 ] , * V_83 ;
#ifdef F_38
struct V_36 * V_36 ;
struct V_18 * V_19 ;
int V_90 ;
#endif
V_83 = F_31 ( V_15 , V_58 -> V_30 , sizeof( V_82 ) , V_82 , V_58 ) ;
if ( V_83 == NULL ) {
F_39 ( V_31 ) ;
return V_91 ;
}
#ifdef F_38
V_36 = F_7 ( V_15 ) ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 )
V_90 = F_40 ( & V_58 -> V_69 . V_66 ) & V_92 ;
else
#endif
V_90 = ( F_41 ( V_36 , V_58 -> V_69 . V_63 ) == V_93 ) ;
V_19 = F_6 ( V_36 ) ;
if ( V_19 -> V_94 && V_31 -> V_62 && V_90 ) {
int V_95 ;
struct V_12 * V_13 ;
unsigned int V_20 = ( V_31 -> V_20 & V_79 &&
V_58 -> V_43 == V_4 ) ?
V_80 : 0 ;
union V_44 V_69 = { . V_96 = { 0 , 0 , 0 , 0 } } ;
F_39 ( V_31 ) ;
F_25 ( 6 , L_19 , V_97 ) ;
{
struct V_49 V_50 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 -> V_43 ,
& V_58 -> V_67 , V_83 [ 0 ] ,
& V_58 -> V_69 , V_83 [ 1 ] , & V_50 ) ;
V_13 = F_27 ( & V_50 , & V_69 , 0 ,
V_98 | V_20 ,
NULL , V_15 -> V_77 ) ;
if ( ! V_13 )
return V_91 ;
}
F_5 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_99 , V_15 , V_40 ) ;
V_95 = V_13 -> V_100 ( V_15 , V_13 , V_40 -> V_41 , V_58 ) ;
F_42 ( & V_13 -> V_101 ) ;
F_28 ( V_13 ) ;
return V_95 ;
}
#endif
if ( ( V_31 -> V_70 == V_71 ) && ( V_83 [ 1 ] != V_71 ) ) {
F_39 ( V_31 ) ;
return V_102 ;
}
F_39 ( V_31 ) ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 ) {
if ( ! V_15 -> V_85 ) {
struct V_36 * V_36 = F_43 ( F_44 ( V_15 ) -> V_85 ) ;
V_15 -> V_85 = V_36 -> V_103 ;
}
F_45 ( V_15 , V_104 , V_105 , 0 ) ;
} else
#endif
F_46 ( V_15 , V_106 , V_107 , 0 ) ;
return V_91 ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_18 * V_19 = F_6 ( F_7 ( V_15 ) ) ;
return V_19 -> F_47 ;
}
static int F_48 ( struct V_36 * V_36 )
{
struct V_18 * V_19 = F_6 ( V_36 ) ;
return V_19 -> F_48 ;
}
static int F_49 ( struct V_18 * V_19 )
{
return V_19 -> F_49 ;
}
static int F_47 ( struct V_14 * V_15 ) { return 0 ; }
static int F_48 ( struct V_36 * V_36 ) { return 0 ; }
static int F_49 ( struct V_18 * V_19 ) { return 0 ; }
T_2 F_50 ( struct V_14 * V_15 , int V_108 )
{
return F_51 ( F_52 ( V_15 , V_108 , V_15 -> V_30 - V_108 , 0 ) ) ;
}
static inline enum V_109 F_53 ( unsigned int V_110 )
{
if ( V_111 == V_110 )
return V_112 ;
if ( V_113 == V_110 )
return V_114 ;
return V_115 ;
}
static inline int F_54 ( struct V_14 * V_15 , T_3 V_116 )
{
int V_117 = F_55 ( V_15 , V_116 ) ;
if ( ! V_117 )
F_56 ( F_57 ( V_15 ) ) ;
return V_117 ;
}
static int F_58 ( int V_51 , struct V_14 * V_15 )
{
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_47 ( V_15 ) && F_59 ( V_15 ) != 0 )
return 1 ;
} else
#endif
if ( ( F_47 ( V_15 ) ||
F_60 ( V_15 ) -> V_118 & V_119 ) &&
F_61 ( V_15 , V_120 ) != 0 )
return 1 ;
return 0 ;
}
void F_62 ( struct V_14 * V_15 , struct V_81 * V_41 ,
struct V_12 * V_13 , int V_121 )
{
struct V_122 * V_58 = F_57 ( V_15 ) ;
unsigned int V_123 = V_58 -> V_124 * 4 ;
struct V_125 * V_126 = (struct V_125 * ) ( F_63 ( V_15 ) +
V_123 ) ;
struct V_122 * V_127 = (struct V_122 * ) ( V_126 + 1 ) ;
if ( V_121 ) {
V_58 -> V_67 = V_13 -> V_47 . V_63 ;
F_56 ( V_58 ) ;
V_127 -> V_69 = V_13 -> V_47 . V_63 ;
F_56 ( V_127 ) ;
} else {
V_58 -> V_69 = V_13 -> V_69 . V_63 ;
F_56 ( V_58 ) ;
V_127 -> V_67 = V_13 -> V_69 . V_63 ;
F_56 ( V_127 ) ;
}
if ( V_5 == V_127 -> V_43 || V_4 == V_127 -> V_43 ||
V_6 == V_127 -> V_43 ) {
T_1 * V_128 = ( void * ) V_127 + V_127 -> V_124 * 4 ;
if ( V_121 )
V_128 [ 1 ] = V_13 -> V_48 ;
else
V_128 [ 0 ] = V_13 -> V_60 ;
}
V_126 -> V_129 = 0 ;
V_126 -> V_129 = F_50 ( V_15 , V_123 ) ;
V_15 -> V_130 = V_131 ;
if ( V_121 )
F_32 ( 11 , V_132 , V_41 , V_15 , ( void * ) V_127 - ( void * ) V_58 ,
L_20 ) ;
else
F_32 ( 11 , V_132 , V_41 , V_15 , ( void * ) V_127 - ( void * ) V_58 ,
L_21 ) ;
}
void F_64 ( struct V_14 * V_15 , struct V_81 * V_41 ,
struct V_12 * V_13 , int V_121 )
{
struct V_133 * V_58 = F_65 ( V_15 ) ;
unsigned int V_123 = 0 ;
unsigned int V_134 = 0 ;
int V_43 ;
struct V_135 * V_126 ;
struct V_133 * V_127 ;
unsigned short V_136 ;
F_66 ( V_15 , & V_123 , V_8 , & V_136 , NULL ) ;
V_126 = (struct V_135 * ) ( F_63 ( V_15 ) + V_123 ) ;
V_134 = V_123 + sizeof( struct V_135 ) ;
V_127 = (struct V_133 * ) ( F_63 ( V_15 ) + V_134 ) ;
V_43 = F_66 ( V_15 , & V_134 , - 1 , & V_136 , NULL ) ;
if ( V_121 ) {
V_58 -> V_67 = V_13 -> V_47 . V_66 ;
V_127 -> V_69 = V_13 -> V_47 . V_66 ;
} else {
V_58 -> V_69 = V_13 -> V_69 . V_66 ;
V_127 -> V_67 = V_13 -> V_69 . V_66 ;
}
if ( ! V_136 && ( V_5 == V_43 || V_4 == V_43 ||
V_6 == V_43 ) ) {
T_1 * V_128 = ( void * ) ( F_63 ( V_15 ) + V_134 ) ;
F_25 ( 11 , L_22 , V_97 ,
F_22 ( V_121 ? V_128 [ 1 ] : V_128 [ 0 ] ) ,
F_22 ( V_121 ? V_13 -> V_48 : V_13 -> V_60 ) ) ;
if ( V_121 )
V_128 [ 1 ] = V_13 -> V_48 ;
else
V_128 [ 0 ] = V_13 -> V_60 ;
}
V_126 -> V_137 = ~ F_67 ( & V_58 -> V_67 , & V_58 -> V_69 ,
V_15 -> V_30 - V_123 ,
V_8 , 0 ) ;
V_15 -> V_138 = F_63 ( V_15 ) - V_15 -> V_139 + V_123 ;
V_15 -> V_140 = F_68 ( struct V_135 , V_137 ) ;
V_15 -> V_130 = V_141 ;
if ( V_121 )
F_32 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_127 - ( void * ) V_58 ,
L_23 ) ;
else
F_32 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_127 - ( void * ) V_58 ,
L_24 ) ;
}
static int F_69 ( int V_51 , struct V_14 * V_15 ,
union V_44 * V_64 ,
T_4 V_43 , struct V_12 * V_13 ,
struct V_81 * V_41 ,
unsigned int V_108 , unsigned int V_124 )
{
unsigned int V_142 = V_91 ;
if ( F_70 ( V_13 ) != 0 ) {
F_34 ( L_25
L_26 ) ;
}
if ( ! F_71 ( V_15 ) && F_50 ( V_15 , V_124 ) ) {
F_20 ( 1 , L_27 ,
F_21 ( V_51 , V_64 ) ) ;
goto V_143;
}
if ( V_5 == V_43 || V_4 == V_43 ||
V_6 == V_43 )
V_108 += 2 * sizeof( V_144 ) ;
if ( ! F_72 ( V_15 , V_108 ) )
goto V_143;
#ifdef F_2
if ( V_51 == V_65 )
F_64 ( V_15 , V_41 , V_13 , 1 ) ;
else
#endif
F_62 ( V_15 , V_41 , V_13 , 1 ) ;
if ( F_58 ( V_51 , V_15 ) )
goto V_143;
F_11 ( V_13 , V_15 ) ;
V_15 -> V_145 = 1 ;
if ( ! ( V_13 -> V_20 & V_146 ) )
F_73 ( V_15 ) ;
else
F_74 ( V_15 , V_13 , 0 ) ;
V_142 = V_102 ;
V_143:
F_33 ( V_13 ) ;
return V_142 ;
}
static int F_75 ( struct V_14 * V_15 , int * V_147 ,
unsigned int V_110 )
{
struct V_122 * V_58 ;
struct V_125 V_148 , * V_149 ;
struct V_122 V_150 , * V_151 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
unsigned int V_108 , V_124 ;
union V_44 V_64 ;
* V_147 = 1 ;
if ( F_76 ( F_57 ( V_15 ) ) ) {
if ( F_54 ( V_15 , F_53 ( V_110 ) ) )
return V_152 ;
}
V_58 = F_57 ( V_15 ) ;
V_108 = V_124 = V_58 -> V_124 * 4 ;
V_149 = F_77 ( V_15 , V_108 , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == NULL )
return V_91 ;
F_25 ( 12 , L_28 ,
V_149 -> type , F_22 ( F_78 ( V_149 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_149 -> type != V_106 ) &&
( V_149 -> type != V_153 ) &&
( V_149 -> type != V_154 ) ) {
* V_147 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_148 ) ;
V_151 = F_77 ( V_15 , V_108 , sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == NULL )
return V_102 ;
V_41 = F_79 ( V_151 -> V_43 ) ;
if ( ! V_41 )
return V_102 ;
if ( F_80 ( V_151 -> V_155 & F_81 ( V_156 ) &&
V_41 -> V_157 ) )
return V_102 ;
F_32 ( 11 , V_132 , V_41 , V_15 , V_108 ,
L_29 ) ;
F_82 ( V_151 , & V_127 ) ;
V_127 . V_30 += V_108 ;
V_13 = V_41 -> V_158 ( V_132 , V_15 , & V_127 , 1 ) ;
if ( ! V_13 )
return V_102 ;
V_64 . V_63 = V_58 -> V_67 ;
return F_69 ( V_132 , V_15 , & V_64 , V_151 -> V_43 , V_13 ,
V_41 , V_127 . V_30 , V_124 ) ;
}
static int F_83 ( struct V_14 * V_15 , int * V_147 ,
unsigned int V_110 , struct V_57 * V_159 )
{
struct V_135 V_148 , * V_149 ;
struct V_133 V_160 , * V_161 ;
struct V_57 V_127 = { . V_20 = 0 , . V_136 = 0 } ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
union V_44 V_64 ;
unsigned int V_162 ;
* V_147 = 1 ;
V_149 = F_31 ( V_15 , V_159 -> V_30 , sizeof( V_148 ) , & V_148 , V_159 ) ;
if ( V_149 == NULL )
return V_91 ;
if ( V_149 -> V_163 & V_164 ) {
* V_147 = 0 ;
return V_102 ;
}
if ( V_159 -> V_20 & V_165 )
return V_91 ;
F_25 ( 8 , L_30 ,
V_149 -> V_163 , F_22 ( F_84 ( V_149 ) ) ,
& V_159 -> V_67 , & V_159 -> V_69 ) ;
V_127 . V_30 = V_159 -> V_30 + sizeof( V_148 ) ;
V_161 = F_77 ( V_15 , V_127 . V_30 , sizeof( V_160 ) , & V_160 ) ;
if ( V_161 == NULL )
return V_102 ;
V_127 . V_67 . V_66 = V_161 -> V_67 ;
V_127 . V_69 . V_66 = V_161 -> V_69 ;
V_127 . V_43 = F_66 ( V_15 , & V_127 . V_30 , - 1 , & V_127 . V_136 , NULL ) ;
if ( V_127 . V_43 < 0 )
return V_102 ;
V_41 = F_79 ( V_127 . V_43 ) ;
if ( ! V_41 )
return V_102 ;
V_13 = V_41 -> V_158 ( V_65 , V_15 , & V_127 , 1 ) ;
if ( ! V_13 )
return V_102 ;
V_64 . V_66 = V_127 . V_67 . V_66 ;
V_162 = V_127 . V_30 ;
return F_69 ( V_65 , V_15 , & V_64 , V_127 . V_43 , V_13 ,
V_41 , V_162 , sizeof( struct V_133 ) ) ;
}
static inline int F_85 ( const struct V_14 * V_15 , int V_166 )
{
T_5 * V_167 , V_168 ;
V_167 = F_77 ( V_15 , V_166 + sizeof( V_169 ) ,
sizeof( V_168 ) , & V_168 ) ;
if ( V_167 == NULL )
return 0 ;
if ( V_167 -> type == V_170 )
return 1 ;
return 0 ;
}
static inline int F_86 ( const struct V_14 * V_15 , int V_166 )
{
struct V_171 V_172 , * V_173 ;
V_173 = F_77 ( V_15 , V_166 , sizeof( V_172 ) , & V_172 ) ;
if ( V_173 == NULL )
return 0 ;
return V_173 -> V_174 ;
}
static unsigned int
F_87 ( int V_51 , struct V_14 * V_15 , struct V_39 * V_40 ,
struct V_12 * V_13 , struct V_57 * V_58 )
{
struct V_81 * V_41 = V_40 -> V_41 ;
F_32 ( 11 , V_51 , V_41 , V_15 , 0 , L_31 ) ;
if ( ! F_72 ( V_15 , V_58 -> V_30 ) )
goto V_175;
if ( V_41 -> V_176 && ! V_41 -> V_176 ( V_15 , V_41 , V_13 , V_58 ) )
goto V_175;
#ifdef F_2
if ( V_51 == V_65 )
F_65 ( V_15 ) -> V_67 = V_13 -> V_47 . V_66 ;
else
#endif
{
F_57 ( V_15 ) -> V_67 = V_13 -> V_47 . V_63 ;
F_56 ( F_57 ( V_15 ) ) ;
}
if ( F_58 ( V_51 , V_15 ) )
goto V_175;
F_32 ( 10 , V_51 , V_41 , V_15 , 0 , L_32 ) ;
F_11 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_177 , V_15 , V_40 ) ;
V_15 -> V_145 = 1 ;
if ( ! ( V_13 -> V_20 & V_146 ) )
F_73 ( V_15 ) ;
else
F_74 ( V_15 , V_13 , 0 ) ;
F_28 ( V_13 ) ;
F_88 ( 11 ) ;
return V_102 ;
V_175:
F_28 ( V_13 ) ;
F_89 ( V_15 ) ;
F_88 ( 11 ) ;
return V_152 ;
}
static unsigned int
F_90 ( unsigned int V_110 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 = NULL ;
struct V_57 V_58 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
F_91 ( 11 ) ;
if ( V_15 -> V_145 )
return V_102 ;
if ( F_80 ( V_15 -> V_178 != NULL && V_110 == V_179 &&
V_51 == V_132 ) ) {
struct V_180 * V_178 = V_15 -> V_178 ;
struct V_181 * V_182 = F_92 ( V_15 -> V_178 ) ;
if ( V_182 && V_178 -> V_183 == V_184 && V_182 -> V_185 )
return V_102 ;
}
if ( F_80 ( ! F_44 ( V_15 ) ) )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_186 )
return V_102 ;
F_93 ( V_51 , V_15 , & V_58 ) ;
#ifdef F_2
if ( V_51 == V_65 ) {
if ( ! V_58 . V_136 && F_94 ( V_15 ) ) {
struct V_14 * V_187 = F_94 ( V_15 ) ;
V_187 -> V_145 = 1 ;
V_187 -> V_77 = V_15 -> V_77 ;
}
if ( F_80 ( V_58 . V_43 == V_8 ) ) {
int V_147 ;
int V_142 = F_83 ( V_15 , & V_147 ,
V_110 , & V_58 ) ;
if ( V_147 )
return V_142 ;
}
} else
#endif
if ( F_80 ( V_58 . V_43 == V_7 ) ) {
int V_147 ;
int V_142 = F_75 ( V_15 , & V_147 , V_110 ) ;
if ( V_147 )
return V_142 ;
}
V_40 = F_95 ( V_36 , V_58 . V_43 ) ;
if ( F_80 ( ! V_40 ) )
return V_102 ;
V_41 = V_40 -> V_41 ;
#ifdef F_2
if ( V_51 == V_132 )
#endif
if ( F_80 ( F_76 ( F_57 ( V_15 ) ) && ! V_41 -> V_157 ) ) {
if ( F_54 ( V_15 ,
F_53 ( V_110 ) ) )
return V_152 ;
F_82 ( F_63 ( V_15 ) , & V_58 ) ;
}
V_13 = V_41 -> V_158 ( V_51 , V_15 , & V_58 , 0 ) ;
if ( F_14 ( V_13 ) )
return F_87 ( V_51 , V_15 , V_40 , V_13 , & V_58 ) ;
if ( F_48 ( V_36 ) &&
( V_41 -> V_43 == V_5 ||
V_41 -> V_43 == V_4 ||
V_41 -> V_43 == V_6 ) ) {
T_1 V_82 [ 2 ] , * V_83 ;
V_83 = F_31 ( V_15 , V_58 . V_30 ,
sizeof( V_82 ) , V_82 , & V_58 ) ;
if ( V_83 == NULL )
return V_102 ;
if ( F_96 ( V_36 , V_51 , V_58 . V_43 ,
& V_58 . V_67 ,
V_83 [ 0 ] ) ) {
if ( ( V_58 . V_43 != V_5 &&
V_58 . V_43 != V_6 )
|| ( ( V_58 . V_43 == V_5
&& ! F_86 ( V_15 , V_58 . V_30 ) )
|| ( V_58 . V_43 == V_6
&& ! F_85 ( V_15 ,
V_58 . V_30 ) ) ) ) {
#ifdef F_2
if ( V_51 == V_65 ) {
struct V_36 * V_36 =
F_43 ( F_44 ( V_15 ) -> V_85 ) ;
if ( ! V_15 -> V_85 )
V_15 -> V_85 = V_36 -> V_103 ;
F_45 ( V_15 ,
V_104 ,
V_105 ,
0 ) ;
} else
#endif
F_46 ( V_15 ,
V_106 ,
V_107 , 0 ) ;
return V_91 ;
}
}
}
F_32 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_33 ) ;
return V_102 ;
}
static unsigned int
F_97 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
return F_90 ( V_110 , V_15 , V_132 ) ;
}
static unsigned int
F_99 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
unsigned int V_142 ;
F_100 () ;
V_142 = F_90 ( V_110 , V_15 , V_132 ) ;
F_101 () ;
return V_142 ;
}
static unsigned int
F_102 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
return F_90 ( V_110 , V_15 , V_65 ) ;
}
static unsigned int
F_103 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
unsigned int V_142 ;
F_100 () ;
V_142 = F_90 ( V_110 , V_15 , V_65 ) ;
F_101 () ;
return V_142 ;
}
static int
F_104 ( struct V_14 * V_15 , int * V_147 , unsigned int V_110 )
{
struct V_36 * V_36 = NULL ;
struct V_122 * V_58 ;
struct V_125 V_148 , * V_149 ;
struct V_122 V_150 , * V_151 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_108 , V_190 , V_124 , V_142 ;
bool V_191 ;
* V_147 = 1 ;
if ( F_76 ( F_57 ( V_15 ) ) ) {
if ( F_54 ( V_15 , F_53 ( V_110 ) ) )
return V_152 ;
}
V_58 = F_57 ( V_15 ) ;
V_108 = V_124 = V_58 -> V_124 * 4 ;
V_149 = F_77 ( V_15 , V_108 , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == NULL )
return V_91 ;
F_25 ( 12 , L_34 ,
V_149 -> type , F_22 ( F_78 ( V_149 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_149 -> type != V_106 ) &&
( V_149 -> type != V_153 ) &&
( V_149 -> type != V_154 ) ) {
* V_147 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_148 ) ;
V_151 = F_77 ( V_15 , V_108 , sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == NULL )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_191 = false ;
if ( V_151 -> V_43 == V_192 ) {
if ( F_80 ( V_151 -> V_155 & F_81 ( V_156 ) ) )
return V_102 ;
if ( ! ( F_60 ( V_15 ) -> V_118 & V_119 ) )
return V_102 ;
V_108 += V_151 -> V_124 * 4 ;
V_151 = F_77 ( V_15 , V_108 , sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == NULL )
return V_102 ;
V_191 = true ;
}
V_40 = F_95 ( V_36 , V_151 -> V_43 ) ;
if ( ! V_40 )
return V_102 ;
V_41 = V_40 -> V_41 ;
if ( F_80 ( V_151 -> V_155 & F_81 ( V_156 ) &&
V_41 -> V_157 ) )
return V_102 ;
F_32 ( 11 , V_132 , V_41 , V_15 , V_108 ,
L_35 ) ;
V_190 = V_108 ;
F_82 ( V_151 , & V_127 ) ;
V_127 . V_30 += V_108 ;
V_108 = V_127 . V_30 ;
V_13 = V_41 -> V_87 ( V_132 , V_15 , & V_127 , V_191 ? 0 : 1 ) ;
if ( ! V_13 )
return V_102 ;
V_142 = V_91 ;
if ( ! F_71 ( V_15 ) && F_50 ( V_15 , V_124 ) ) {
F_25 ( 1 , L_36 ,
& V_58 -> V_67 ) ;
goto V_143;
}
if ( V_191 ) {
T_6 V_193 = V_149 -> V_194 . V_195 ;
if ( V_149 -> type == V_106 &&
V_149 -> V_196 == V_197 ) {
struct V_16 * V_17 = V_13 -> V_17 ;
T_7 V_198 = F_22 ( V_149 -> V_194 . V_199 . V_198 ) ;
F_105 ( V_15 , V_124 + sizeof( V_148 ) ) ;
V_190 -= V_124 + sizeof( V_148 ) ;
F_106 ( V_15 ) ;
F_25 ( 12 , L_37 ,
& F_57 ( V_15 ) -> V_67 , & F_57 ( V_15 ) -> V_69 , V_198 ) ;
F_107 ( V_15 , F_43 ( V_15 -> V_85 ) ,
V_198 , 0 , 0 , 0 , 0 ) ;
if ( ! ( V_151 -> V_155 & F_81 ( V_200 ) ) )
goto V_201;
if ( V_17 ) {
F_108 ( & V_17 -> V_202 ) ;
if ( V_17 -> V_203 )
V_198 = F_109 ( V_17 -> V_203 ) ;
F_110 ( & V_17 -> V_202 ) ;
}
if ( V_198 > 68 + sizeof( struct V_122 ) )
V_198 -= sizeof( struct V_122 ) ;
V_193 = F_18 ( V_198 ) ;
}
F_105 ( V_15 , V_190 ) ;
F_106 ( V_15 ) ;
F_25 ( 12 , L_38 ,
& F_57 ( V_15 ) -> V_67 , & F_57 ( V_15 ) -> V_69 ,
V_149 -> type , V_149 -> V_196 , F_111 ( V_193 ) ) ;
F_46 ( V_15 , V_149 -> type , V_149 -> V_196 , V_193 ) ;
F_11 ( V_13 , V_15 ) ;
V_201:
F_112 ( V_15 ) ;
V_142 = V_152 ;
goto V_143;
}
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_151 -> V_43 || V_4 == V_151 -> V_43 )
V_108 += 2 * sizeof( V_144 ) ;
V_142 = F_113 ( V_15 , V_13 , V_41 , V_108 , V_110 , & V_127 ) ;
V_143:
F_33 ( V_13 ) ;
return V_142 ;
}
static int F_114 ( struct V_14 * V_15 , int * V_147 ,
unsigned int V_110 , struct V_57 * V_58 )
{
struct V_36 * V_36 = NULL ;
struct V_133 V_160 , * V_161 ;
struct V_135 V_148 , * V_149 ;
struct V_57 V_127 = { . V_20 = 0 , . V_136 = 0 } ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_204 , V_162 , V_142 ;
* V_147 = 1 ;
V_149 = F_31 ( V_15 , V_58 -> V_30 , sizeof( V_148 ) , & V_148 , V_58 ) ;
if ( V_149 == NULL )
return V_91 ;
if ( V_149 -> V_163 & V_164 ) {
* V_147 = 0 ;
return V_102 ;
}
if ( V_58 -> V_20 & V_165 )
return V_91 ;
F_25 ( 8 , L_39 ,
V_149 -> V_163 , F_22 ( F_84 ( V_149 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
V_127 . V_30 = V_58 -> V_30 + sizeof( V_148 ) ;
V_204 = V_127 . V_30 ;
V_161 = F_77 ( V_15 , V_127 . V_30 , sizeof( V_160 ) , & V_160 ) ;
if ( V_161 == NULL )
return V_102 ;
V_127 . V_67 . V_66 = V_161 -> V_67 ;
V_127 . V_69 . V_66 = V_161 -> V_69 ;
V_127 . V_43 = F_66 ( V_15 , & V_127 . V_30 , - 1 , & V_127 . V_136 , NULL ) ;
if ( V_127 . V_43 < 0 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_40 = F_95 ( V_36 , V_127 . V_43 ) ;
if ( ! V_40 )
return V_102 ;
V_41 = V_40 -> V_41 ;
if ( V_127 . V_136 )
return V_102 ;
F_32 ( 11 , V_65 , V_41 , V_15 , V_204 ,
L_40 ) ;
V_13 = V_41 -> V_87 ( V_65 , V_15 , & V_127 ,
( V_110 == V_179 ) ? 0 : 1 ) ;
if ( ! V_13 )
return V_102 ;
if ( ( V_110 == V_179 ) &&
( F_70 ( V_13 ) != V_205 ) ) {
F_33 ( V_13 ) ;
return V_102 ;
}
F_5 ( V_13 , V_15 ) ;
V_162 = V_127 . V_30 ;
if ( V_5 == V_127 . V_43 || V_4 == V_127 . V_43 ||
V_6 == V_127 . V_43 )
V_162 += 2 * sizeof( V_144 ) ;
V_142 = F_115 ( V_15 , V_13 , V_41 , V_162 , V_110 , & V_127 ) ;
F_33 ( V_13 ) ;
return V_142 ;
}
static unsigned int
F_116 ( unsigned int V_110 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 ;
struct V_57 V_58 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
int V_95 , V_206 ;
struct V_18 * V_19 ;
if ( V_15 -> V_145 )
return V_102 ;
if ( F_80 ( ( V_15 -> V_207 != V_208 &&
V_110 != V_179 ) ||
! F_44 ( V_15 ) ) ) {
F_93 ( V_51 , V_15 , & V_58 ) ;
F_20 ( 12 , L_41
L_42 ,
V_15 -> V_207 , V_58 . V_43 ,
F_21 ( V_51 , & V_58 . V_69 ) , V_110 ) ;
return V_102 ;
}
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_80 ( F_117 ( V_19 ) || ! V_19 -> V_186 ) )
return V_102 ;
F_93 ( V_51 , V_15 , & V_58 ) ;
if ( F_80 ( V_15 -> V_178 != NULL && V_110 == V_179 &&
V_51 == V_132 ) ) {
struct V_180 * V_178 = V_15 -> V_178 ;
struct V_181 * V_182 = F_92 ( V_15 -> V_178 ) ;
if ( V_182 && V_178 -> V_183 == V_184 && V_182 -> V_185 )
return V_102 ;
}
#ifdef F_2
if ( V_51 == V_65 ) {
if ( ! V_58 . V_136 && F_94 ( V_15 ) ) {
struct V_14 * V_187 = F_94 ( V_15 ) ;
V_187 -> V_145 = 1 ;
V_187 -> V_77 = V_15 -> V_77 ;
}
if ( F_80 ( V_58 . V_43 == V_8 ) ) {
int V_147 ;
int V_142 = F_114 ( V_15 , & V_147 , V_110 ,
& V_58 ) ;
if ( V_147 )
return V_142 ;
}
} else
#endif
if ( F_80 ( V_58 . V_43 == V_7 ) ) {
int V_147 ;
int V_142 = F_104 ( V_15 , & V_147 , V_110 ) ;
if ( V_147 )
return V_142 ;
}
V_40 = F_95 ( V_36 , V_58 . V_43 ) ;
if ( F_80 ( ! V_40 ) )
return V_102 ;
V_41 = V_40 -> V_41 ;
V_13 = V_41 -> V_87 ( V_51 , V_15 , & V_58 , 0 ) ;
if ( F_80 ( ! V_13 ) && ! V_58 . V_136 ) {
int V_209 ;
if ( ! V_41 -> V_210 ( V_51 , V_15 , V_40 , & V_209 , & V_13 , & V_58 ) )
return V_209 ;
}
if ( F_80 ( ! V_13 ) ) {
F_32 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_43 ) ;
if ( V_58 . V_136 && ! F_94 ( V_15 ) ) {
F_118 ( L_44 ) ;
F_32 ( 7 , V_51 , V_41 , V_15 , 0 , L_45 ) ;
}
return V_102 ;
}
F_32 ( 11 , V_51 , V_41 , V_15 , 0 , L_46 ) ;
if ( V_13 -> V_17 && ! ( V_13 -> V_17 -> V_20 & V_21 ) ) {
if ( F_49 ( V_19 ) ) {
F_119 ( V_13 ) ;
}
F_33 ( V_13 ) ;
return V_91 ;
}
F_5 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_99 , V_15 , V_40 ) ;
if ( V_13 -> V_100 )
V_95 = V_13 -> V_100 ( V_15 , V_13 , V_41 , & V_58 ) ;
else {
F_118 ( L_47 ) ;
V_95 = V_102 ;
}
if ( V_13 -> V_20 & V_80 )
V_206 = F_120 ( V_19 ) ;
else
V_206 = F_121 ( 1 , & V_13 -> V_101 ) ;
if ( V_19 -> V_211 & V_212 )
F_122 ( V_36 , V_13 , V_206 ) ;
F_28 ( V_13 ) ;
return V_95 ;
}
static unsigned int
F_123 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 ,
const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
return F_116 ( V_110 , V_15 , V_132 ) ;
}
static unsigned int
F_124 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
unsigned int V_142 ;
F_100 () ;
V_142 = F_116 ( V_110 , V_15 , V_132 ) ;
F_101 () ;
return V_142 ;
}
static unsigned int
F_125 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 ,
const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
struct V_14 * V_187 = F_94 ( V_15 ) ;
struct V_36 * V_36 ;
if ( V_187 )
F_25 ( 2 , L_48 , V_187 -> V_145 ) ;
if ( ! V_187 || ! V_187 -> V_145 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_186 )
return V_102 ;
V_15 -> V_77 = V_187 -> V_77 ;
return V_102 ;
}
static unsigned int
F_126 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 ,
const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
return F_116 ( V_110 , V_15 , V_65 ) ;
}
static unsigned int
F_127 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
unsigned int V_142 ;
F_100 () ;
V_142 = F_116 ( V_110 , V_15 , V_65 ) ;
F_101 () ;
return V_142 ;
}
static unsigned int
F_128 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
int V_213 ;
struct V_36 * V_36 ;
struct V_18 * V_19 ;
if ( F_57 ( V_15 ) -> V_43 != V_7 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_80 ( F_117 ( V_19 ) || ! V_19 -> V_186 ) )
return V_102 ;
return F_104 ( V_15 , & V_213 , V_110 ) ;
}
static unsigned int
F_129 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_188 * V_189 , const struct V_188 * V_143 ,
int (* F_98)( struct V_14 * ) )
{
int V_213 ;
struct V_36 * V_36 ;
struct V_18 * V_19 ;
struct V_57 V_122 ;
F_93 ( V_65 , V_15 , & V_122 ) ;
if ( V_122 . V_43 != V_8 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_19 = F_6 ( V_36 ) ;
if ( F_80 ( F_117 ( V_19 ) || ! V_19 -> V_186 ) )
return V_102 ;
return F_114 ( V_15 , & V_213 , V_110 , & V_122 ) ;
}
static int T_8 F_130 ( struct V_36 * V_36 )
{
struct V_18 * V_19 ;
V_19 = F_131 ( V_36 , V_214 ) ;
if ( V_19 == NULL )
return - V_215 ;
V_19 -> V_186 = 0 ;
V_19 -> V_36 = V_36 ;
V_19 -> V_216 = F_36 ( & V_217 ) ;
F_42 ( & V_217 ) ;
V_36 -> V_19 = V_19 ;
if ( F_132 ( V_36 ) < 0 )
goto V_218;
if ( F_133 ( V_36 ) < 0 )
goto V_219;
if ( F_134 ( V_36 ) < 0 )
goto V_220;
if ( F_135 ( V_36 ) < 0 )
goto V_221;
if ( F_136 ( V_36 ) < 0 )
goto V_222;
if ( F_137 ( V_36 ) < 0 )
goto V_223;
F_138 ( V_224 L_49 ,
sizeof( struct V_18 ) , V_19 -> V_216 ) ;
return 0 ;
V_223:
F_139 ( V_36 ) ;
V_222:
F_140 ( V_36 ) ;
V_221:
F_141 ( V_36 ) ;
V_220:
F_142 ( V_36 ) ;
V_219:
F_143 ( V_36 ) ;
V_218:
V_36 -> V_19 = NULL ;
return - V_215 ;
}
static void T_9 F_144 ( struct V_36 * V_36 )
{
F_145 ( V_36 ) ;
F_139 ( V_36 ) ;
F_140 ( V_36 ) ;
F_141 ( V_36 ) ;
F_142 ( V_36 ) ;
F_143 ( V_36 ) ;
F_25 ( 2 , L_50 , F_6 ( V_36 ) -> V_216 ) ;
V_36 -> V_19 = NULL ;
}
static void T_9 F_146 ( struct V_36 * V_36 )
{
F_91 ( 2 ) ;
F_6 ( V_36 ) -> V_186 = 0 ;
F_147 () ;
F_148 ( V_36 ) ;
F_88 ( 2 ) ;
}
static int T_10 F_149 ( void )
{
int V_95 ;
V_95 = F_150 () ;
if ( V_95 < 0 ) {
F_34 ( L_51 ) ;
goto exit;
}
F_151 () ;
V_95 = F_152 () ;
if ( V_95 < 0 ) {
F_34 ( L_52 ) ;
goto V_225;
}
V_95 = F_153 ( & V_226 ) ;
if ( V_95 < 0 )
goto V_227;
V_95 = F_154 ( & V_228 ) ;
if ( V_95 < 0 )
goto V_229;
V_95 = F_155 ( V_230 , F_156 ( V_230 ) ) ;
if ( V_95 < 0 ) {
F_34 ( L_53 ) ;
goto V_231;
}
V_95 = F_157 () ;
if ( V_95 < 0 ) {
F_34 ( L_54 ) ;
goto V_232;
}
F_158 ( L_55 ) ;
return V_95 ;
V_232:
F_159 ( V_230 , F_156 ( V_230 ) ) ;
V_231:
F_160 ( & V_228 ) ;
V_229:
F_161 ( & V_226 ) ;
V_227:
F_162 () ;
V_225:
F_163 () ;
F_164 () ;
exit:
return V_95 ;
}
static void T_11 F_165 ( void )
{
F_166 () ;
F_159 ( V_230 , F_156 ( V_230 ) ) ;
F_160 ( & V_228 ) ;
F_161 ( & V_226 ) ;
F_162 () ;
F_163 () ;
F_164 () ;
F_158 ( L_56 ) ;
}
