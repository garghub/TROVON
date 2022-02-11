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
struct V_14 * V_15 ,
T_1 V_54 , T_1 V_55 , int * V_56 )
{
struct V_12 * V_13 = NULL ;
struct V_57 V_58 ;
struct V_16 * V_17 ;
struct V_12 * V_59 ;
T_1 V_60 = 0 ;
unsigned int V_20 ;
struct V_49 V_61 ;
const union V_44 V_62 = { . V_63 = F_18 (svc->fwmark) } ;
union V_44 V_64 ;
F_19 ( V_31 -> V_51 , F_20 ( V_15 ) , & V_58 ) ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 )
F_21 ( & V_64 . V_66 , & V_58 . V_67 . V_66 , V_31 -> V_68 ) ;
else
#endif
V_64 . V_63 = V_58 . V_67 . V_63 & V_31 -> V_68 ;
F_22 ( 6 , L_8
L_9 ,
F_23 ( V_31 -> V_51 , & V_58 . V_67 ) , F_24 ( V_54 ) ,
F_23 ( V_31 -> V_51 , & V_58 . V_69 ) , F_24 ( V_55 ) ,
F_23 ( V_31 -> V_51 , & V_64 ) ) ;
{
int V_43 = V_58 . V_43 ;
const union V_44 * V_47 = & V_58 . V_69 ;
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
V_59 = F_25 ( & V_61 ) ;
if ( ! V_59 || ! F_26 ( V_59 ) ) {
V_17 = V_31 -> V_72 -> V_73 ( V_31 , V_15 ) ;
if ( ! V_17 ) {
F_27 ( 1 , L_10 ) ;
F_28 ( V_61 . V_74 ) ;
* V_56 = 0 ;
return NULL ;
}
if ( V_55 == V_31 -> V_70 && V_31 -> V_70 != V_71 )
V_60 = V_17 -> V_70 ;
V_59 = F_29 ( & V_61 , & V_17 -> V_75 , V_60 ,
V_76 , V_17 , V_15 -> V_77 ) ;
if ( V_59 == NULL ) {
F_28 ( V_61 . V_74 ) ;
* V_56 = - 1 ;
return NULL ;
}
V_59 -> V_78 = V_31 -> V_78 ;
} else {
V_17 = V_59 -> V_17 ;
F_28 ( V_61 . V_74 ) ;
}
V_60 = V_55 ;
if ( V_60 == V_31 -> V_70 && V_17 -> V_70 )
V_60 = V_17 -> V_70 ;
V_20 = ( V_31 -> V_20 & V_79
&& V_58 . V_43 == V_4 ) ?
V_80 : 0 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 . V_43 , & V_58 . V_67 ,
V_54 , & V_58 . V_69 , V_55 , & V_61 ) ;
V_13 = F_29 ( & V_61 , & V_17 -> V_75 , V_60 , V_20 , V_17 , V_15 -> V_77 ) ;
if ( V_13 == NULL ) {
F_30 ( V_59 ) ;
* V_56 = - 1 ;
return NULL ;
}
F_31 ( V_13 , V_59 ) ;
F_30 ( V_59 ) ;
F_12 ( V_13 , V_31 ) ;
return V_13 ;
}
struct V_12 *
F_32 ( struct V_35 * V_31 , struct V_14 * V_15 ,
struct V_39 * V_40 , int * V_56 )
{
struct V_81 * V_41 = V_40 -> V_41 ;
struct V_12 * V_13 = NULL ;
struct V_57 V_58 ;
struct V_16 * V_17 ;
T_1 V_82 [ 2 ] , * V_83 ;
unsigned int V_20 ;
* V_56 = 1 ;
F_19 ( V_31 -> V_51 , F_20 ( V_15 ) , & V_58 ) ;
V_83 = F_33 ( V_15 , V_58 . V_30 , sizeof( V_82 ) , V_82 ) ;
if ( V_83 == NULL )
return NULL ;
if ( V_83 [ 0 ] == V_84 ) {
F_34 ( 12 , V_31 -> V_51 , V_41 , V_15 , 0 ,
L_11 ) ;
return NULL ;
}
if ( ( ! V_15 -> V_85 || V_15 -> V_85 -> V_20 & V_86 ) &&
( V_13 = V_41 -> V_87 ( V_31 -> V_51 , V_15 , & V_58 , V_58 . V_30 , 1 ) ) ) {
F_34 ( 12 , V_31 -> V_51 , V_41 , V_15 , 0 ,
L_12 ) ;
F_35 ( V_13 ) ;
return NULL ;
}
if ( V_31 -> V_20 & V_88 )
return F_17 ( V_31 , V_15 , V_83 [ 0 ] , V_83 [ 1 ] , V_56 ) ;
* V_56 = 0 ;
if ( ! V_31 -> V_62 && V_83 [ 1 ] != V_31 -> V_70 ) {
if ( ! V_31 -> V_70 )
F_36 ( L_13
L_14
L_15 ) ;
return NULL ;
}
V_17 = V_31 -> V_72 -> V_73 ( V_31 , V_15 ) ;
if ( V_17 == NULL ) {
F_27 ( 1 , L_16 ) ;
return NULL ;
}
V_20 = ( V_31 -> V_20 & V_79
&& V_58 . V_43 == V_4 ) ?
V_80 : 0 ;
{
struct V_49 V_50 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 . V_43 ,
& V_58 . V_67 , V_83 [ 0 ] , & V_58 . V_69 , V_83 [ 1 ] ,
& V_50 ) ;
V_13 = F_29 ( & V_50 , & V_17 -> V_75 ,
V_17 -> V_70 ? V_17 -> V_70 : V_83 [ 1 ] ,
V_20 , V_17 , V_15 -> V_77 ) ;
if ( ! V_13 ) {
* V_56 = - 1 ;
return NULL ;
}
}
F_22 ( 6 , L_17
L_18 ,
F_37 ( V_13 ) ,
F_23 ( V_31 -> V_51 , & V_13 -> V_45 ) , F_24 ( V_13 -> V_46 ) ,
F_23 ( V_31 -> V_51 , & V_13 -> V_47 ) , F_24 ( V_13 -> V_48 ) ,
F_23 ( V_31 -> V_51 , & V_13 -> V_69 ) , F_24 ( V_13 -> V_60 ) ,
V_13 -> V_20 , F_38 ( & V_13 -> V_89 ) ) ;
F_12 ( V_13 , V_31 ) ;
return V_13 ;
}
int F_39 ( struct V_35 * V_31 , struct V_14 * V_15 ,
struct V_39 * V_40 )
{
T_1 V_82 [ 2 ] , * V_83 ;
struct V_57 V_58 ;
#ifdef F_40
struct V_36 * V_36 ;
struct V_18 * V_19 ;
int V_90 ;
#endif
F_19 ( V_31 -> V_51 , F_20 ( V_15 ) , & V_58 ) ;
V_83 = F_33 ( V_15 , V_58 . V_30 , sizeof( V_82 ) , V_82 ) ;
if ( V_83 == NULL ) {
F_41 ( V_31 ) ;
return V_91 ;
}
#ifdef F_40
V_36 = F_7 ( V_15 ) ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 )
V_90 = F_42 ( & V_58 . V_69 . V_66 ) & V_92 ;
else
#endif
V_90 = ( F_43 ( V_36 , V_58 . V_69 . V_63 ) == V_93 ) ;
V_19 = F_6 ( V_36 ) ;
if ( V_19 -> V_94 && V_31 -> V_62 && V_90 ) {
int V_95 ;
struct V_12 * V_13 ;
unsigned int V_20 = ( V_31 -> V_20 & V_79 &&
V_58 . V_43 == V_4 ) ?
V_80 : 0 ;
union V_44 V_69 = { . V_96 = { 0 , 0 , 0 , 0 } } ;
F_41 ( V_31 ) ;
F_27 ( 6 , L_19 , V_97 ) ;
{
struct V_49 V_50 ;
F_16 ( V_31 -> V_36 , V_31 -> V_51 , V_58 . V_43 ,
& V_58 . V_67 , V_83 [ 0 ] ,
& V_58 . V_69 , V_83 [ 1 ] , & V_50 ) ;
V_13 = F_29 ( & V_50 , & V_69 , 0 ,
V_98 | V_20 ,
NULL , V_15 -> V_77 ) ;
if ( ! V_13 )
return V_91 ;
}
F_5 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_99 , V_15 , V_40 ) ;
V_95 = V_13 -> V_100 ( V_15 , V_13 , V_40 -> V_41 ) ;
F_44 ( & V_13 -> V_101 ) ;
F_30 ( V_13 ) ;
return V_95 ;
}
#endif
if ( ( V_31 -> V_70 == V_71 ) && ( V_83 [ 1 ] != V_71 ) ) {
F_41 ( V_31 ) ;
return V_102 ;
}
F_41 ( V_31 ) ;
#ifdef F_2
if ( V_31 -> V_51 == V_65 ) {
if ( ! V_15 -> V_85 ) {
struct V_36 * V_36 = F_45 ( F_46 ( V_15 ) -> V_85 ) ;
V_15 -> V_85 = V_36 -> V_103 ;
}
F_47 ( V_15 , V_104 , V_105 , 0 ) ;
} else
#endif
F_48 ( V_15 , V_106 , V_107 , 0 ) ;
return V_91 ;
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
T_2 F_52 ( struct V_14 * V_15 , int V_108 )
{
return F_53 ( F_54 ( V_15 , V_108 , V_15 -> V_30 - V_108 , 0 ) ) ;
}
static inline enum V_109 F_55 ( unsigned int V_110 )
{
if ( V_111 == V_110 )
return V_112 ;
if ( V_113 == V_110 )
return V_114 ;
return V_115 ;
}
static inline int F_56 ( struct V_14 * V_15 , T_3 V_116 )
{
int V_117 = F_57 ( V_15 , V_116 ) ;
if ( ! V_117 )
F_58 ( F_59 ( V_15 ) ) ;
return V_117 ;
}
static inline int F_60 ( struct V_14 * V_15 , T_3 V_116 )
{
return 0 ;
}
static int F_61 ( int V_51 , struct V_14 * V_15 )
{
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_49 ( V_15 ) && F_62 ( V_15 ) != 0 )
return 1 ;
} else
#endif
if ( ( F_49 ( V_15 ) ||
F_63 ( V_15 ) -> V_118 & V_119 ) &&
F_64 ( V_15 , V_120 ) != 0 )
return 1 ;
return 0 ;
}
void F_65 ( struct V_14 * V_15 , struct V_81 * V_41 ,
struct V_12 * V_13 , int V_121 )
{
struct V_122 * V_58 = F_59 ( V_15 ) ;
unsigned int V_123 = V_58 -> V_124 * 4 ;
struct V_125 * V_126 = (struct V_125 * ) ( F_20 ( V_15 ) +
V_123 ) ;
struct V_122 * V_127 = (struct V_122 * ) ( V_126 + 1 ) ;
if ( V_121 ) {
V_58 -> V_67 = V_13 -> V_47 . V_63 ;
F_58 ( V_58 ) ;
V_127 -> V_69 = V_13 -> V_47 . V_63 ;
F_58 ( V_127 ) ;
} else {
V_58 -> V_69 = V_13 -> V_69 . V_63 ;
F_58 ( V_58 ) ;
V_127 -> V_67 = V_13 -> V_69 . V_63 ;
F_58 ( V_127 ) ;
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
V_126 -> V_129 = F_52 ( V_15 , V_123 ) ;
V_15 -> V_130 = V_131 ;
if ( V_121 )
F_34 ( 11 , V_132 , V_41 , V_15 , ( void * ) V_127 - ( void * ) V_58 ,
L_20 ) ;
else
F_34 ( 11 , V_132 , V_41 , V_15 , ( void * ) V_127 - ( void * ) V_58 ,
L_21 ) ;
}
void F_66 ( struct V_14 * V_15 , struct V_81 * V_41 ,
struct V_12 * V_13 , int V_121 )
{
struct V_133 * V_58 = F_67 ( V_15 ) ;
unsigned int V_123 = sizeof( struct V_133 ) ;
struct V_134 * V_126 = (struct V_134 * ) ( F_20 ( V_15 ) +
V_123 ) ;
struct V_133 * V_127 = (struct V_133 * ) ( V_126 + 1 ) ;
if ( V_121 ) {
V_58 -> V_67 = V_13 -> V_47 . V_66 ;
V_127 -> V_69 = V_13 -> V_47 . V_66 ;
} else {
V_58 -> V_69 = V_13 -> V_69 . V_66 ;
V_127 -> V_67 = V_13 -> V_69 . V_66 ;
}
if ( V_5 == V_127 -> V_135 || V_4 == V_127 -> V_135 ||
V_6 == V_127 -> V_135 ) {
T_1 * V_128 = ( void * ) V_127 + sizeof( struct V_133 ) ;
if ( V_121 )
V_128 [ 1 ] = V_13 -> V_48 ;
else
V_128 [ 0 ] = V_13 -> V_60 ;
}
V_126 -> V_136 = ~ F_68 ( & V_58 -> V_67 , & V_58 -> V_69 ,
V_15 -> V_30 - V_123 ,
V_8 , 0 ) ;
V_15 -> V_137 = F_20 ( V_15 ) - V_15 -> V_138 + V_123 ;
V_15 -> V_139 = F_69 ( struct V_134 , V_136 ) ;
V_15 -> V_130 = V_140 ;
if ( V_121 )
F_34 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_127 - ( void * ) V_58 ,
L_22 ) ;
else
F_34 ( 11 , V_65 , V_41 , V_15 ,
( void * ) V_127 - ( void * ) V_58 ,
L_23 ) ;
}
static int F_70 ( int V_51 , struct V_14 * V_15 ,
union V_44 * V_64 ,
T_4 V_43 , struct V_12 * V_13 ,
struct V_81 * V_41 ,
unsigned int V_108 , unsigned int V_124 )
{
unsigned int V_141 = V_91 ;
if ( F_71 ( V_13 ) != 0 ) {
F_36 ( L_24
L_25 ) ;
}
if ( ! F_72 ( V_15 ) && F_52 ( V_15 , V_124 ) ) {
F_22 ( 1 , L_26 ,
F_23 ( V_51 , V_64 ) ) ;
goto V_142;
}
if ( V_5 == V_43 || V_4 == V_43 ||
V_6 == V_43 )
V_108 += 2 * sizeof( V_143 ) ;
if ( ! F_73 ( V_15 , V_108 ) )
goto V_142;
#ifdef F_2
if ( V_51 == V_65 )
F_66 ( V_15 , V_41 , V_13 , 1 ) ;
else
#endif
F_65 ( V_15 , V_41 , V_13 , 1 ) ;
if ( F_61 ( V_51 , V_15 ) )
goto V_142;
F_11 ( V_13 , V_15 ) ;
V_15 -> V_144 = 1 ;
if ( ! ( V_13 -> V_20 & V_145 ) )
F_74 ( V_15 ) ;
else
F_75 ( V_15 , V_13 , 0 ) ;
V_141 = V_102 ;
V_142:
F_35 ( V_13 ) ;
return V_141 ;
}
static int F_76 ( struct V_14 * V_15 , int * V_146 ,
unsigned int V_110 )
{
struct V_122 * V_58 ;
struct V_125 V_147 , * V_148 ;
struct V_122 V_149 , * V_150 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
unsigned int V_108 , V_124 ;
union V_44 V_64 ;
* V_146 = 1 ;
if ( F_77 ( F_59 ( V_15 ) ) ) {
if ( F_56 ( V_15 , F_55 ( V_110 ) ) )
return V_151 ;
}
V_58 = F_59 ( V_15 ) ;
V_108 = V_124 = V_58 -> V_124 * 4 ;
V_148 = F_33 ( V_15 , V_108 , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
return V_91 ;
F_27 ( 12 , L_27 ,
V_148 -> type , F_24 ( F_78 ( V_148 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_148 -> type != V_106 ) &&
( V_148 -> type != V_152 ) &&
( V_148 -> type != V_153 ) ) {
* V_146 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_147 ) ;
V_150 = F_33 ( V_15 , V_108 , sizeof( V_149 ) , & V_149 ) ;
if ( V_150 == NULL )
return V_102 ;
V_41 = F_79 ( V_150 -> V_43 ) ;
if ( ! V_41 )
return V_102 ;
if ( F_80 ( V_150 -> V_154 & F_81 ( V_155 ) &&
V_41 -> V_156 ) )
return V_102 ;
F_34 ( 11 , V_132 , V_41 , V_15 , V_108 ,
L_28 ) ;
V_108 += V_150 -> V_124 * 4 ;
F_19 ( V_132 , V_150 , & V_127 ) ;
V_13 = V_41 -> V_157 ( V_132 , V_15 , & V_127 , V_108 , 1 ) ;
if ( ! V_13 )
return V_102 ;
V_64 . V_63 = V_58 -> V_67 ;
return F_70 ( V_132 , V_15 , & V_64 , V_150 -> V_43 , V_13 ,
V_41 , V_108 , V_124 ) ;
}
static int F_82 ( struct V_14 * V_15 , int * V_146 ,
unsigned int V_110 )
{
struct V_133 * V_58 ;
struct V_134 V_147 , * V_148 ;
struct V_133 V_149 , * V_150 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
unsigned int V_108 ;
union V_44 V_64 ;
* V_146 = 1 ;
if ( F_67 ( V_15 ) -> V_135 == V_158 ) {
if ( F_60 ( V_15 , F_55 ( V_110 ) ) )
return V_151 ;
}
V_58 = F_67 ( V_15 ) ;
V_108 = sizeof( struct V_133 ) ;
V_148 = F_33 ( V_15 , V_108 , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
return V_91 ;
F_27 ( 12 , L_29 ,
V_148 -> V_159 , F_24 ( F_83 ( V_148 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_148 -> V_159 != V_104 ) &&
( V_148 -> V_159 != V_160 ) &&
( V_148 -> V_159 != V_161 ) ) {
* V_146 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_147 ) ;
V_150 = F_33 ( V_15 , V_108 , sizeof( V_149 ) , & V_149 ) ;
if ( V_150 == NULL )
return V_102 ;
V_41 = F_79 ( V_150 -> V_135 ) ;
if ( ! V_41 )
return V_102 ;
if ( F_80 ( V_150 -> V_135 == V_158 && V_41 -> V_156 ) )
return V_102 ;
F_34 ( 11 , V_65 , V_41 , V_15 , V_108 ,
L_30 ) ;
V_108 += sizeof( struct V_133 ) ;
F_19 ( V_65 , V_150 , & V_127 ) ;
V_13 = V_41 -> V_157 ( V_65 , V_15 , & V_127 , V_108 , 1 ) ;
if ( ! V_13 )
return V_102 ;
V_64 . V_66 = V_58 -> V_67 ;
return F_70 ( V_65 , V_15 , & V_64 , V_150 -> V_135 , V_13 ,
V_41 , V_108 , sizeof( struct V_133 ) ) ;
}
static inline int F_84 ( const struct V_14 * V_15 , int V_162 )
{
T_5 * V_163 , V_164 ;
V_163 = F_33 ( V_15 , V_162 + sizeof( V_165 ) ,
sizeof( V_164 ) , & V_164 ) ;
if ( V_163 == NULL )
return 0 ;
if ( V_163 -> type == V_166 )
return 1 ;
return 0 ;
}
static inline int F_85 ( const struct V_14 * V_15 , int V_162 )
{
struct V_167 V_168 , * V_169 ;
V_169 = F_33 ( V_15 , V_162 , sizeof( V_168 ) , & V_168 ) ;
if ( V_169 == NULL )
return 0 ;
return V_169 -> V_170 ;
}
static unsigned int
F_86 ( int V_51 , struct V_14 * V_15 , struct V_39 * V_40 ,
struct V_12 * V_13 , int V_124 )
{
struct V_81 * V_41 = V_40 -> V_41 ;
F_34 ( 11 , V_51 , V_41 , V_15 , 0 , L_31 ) ;
if ( ! F_73 ( V_15 , V_124 ) )
goto V_171;
if ( V_41 -> V_172 && ! V_41 -> V_172 ( V_15 , V_41 , V_13 ) )
goto V_171;
#ifdef F_2
if ( V_51 == V_65 )
F_67 ( V_15 ) -> V_67 = V_13 -> V_47 . V_66 ;
else
#endif
{
F_59 ( V_15 ) -> V_67 = V_13 -> V_47 . V_63 ;
F_58 ( F_59 ( V_15 ) ) ;
}
if ( F_61 ( V_51 , V_15 ) )
goto V_171;
F_34 ( 10 , V_51 , V_41 , V_15 , 0 , L_32 ) ;
F_11 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_173 , V_15 , V_40 ) ;
V_15 -> V_144 = 1 ;
if ( ! ( V_13 -> V_20 & V_145 ) )
F_74 ( V_15 ) ;
else
F_75 ( V_15 , V_13 , 0 ) ;
F_30 ( V_13 ) ;
F_87 ( 11 ) ;
return V_102 ;
V_171:
F_30 ( V_13 ) ;
F_88 ( V_15 ) ;
F_87 ( 11 ) ;
return V_151 ;
}
static unsigned int
F_89 ( unsigned int V_110 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 = NULL ;
struct V_57 V_58 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
F_90 ( 11 ) ;
if ( V_15 -> V_144 )
return V_102 ;
if ( F_80 ( V_15 -> V_174 != NULL && V_110 == V_175 &&
V_51 == V_132 ) ) {
struct V_176 * V_174 = V_15 -> V_174 ;
struct V_177 * V_178 = F_91 ( V_15 -> V_174 ) ;
if ( V_178 && V_174 -> V_179 == V_180 && V_178 -> V_181 )
return V_102 ;
}
if ( F_80 ( ! F_46 ( V_15 ) ) )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_182 )
return V_102 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_80 ( V_58 . V_43 == V_8 ) ) {
int V_146 ;
int V_141 = F_82 ( V_15 , & V_146 ,
V_110 ) ;
if ( V_146 )
return V_141 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
}
} else
#endif
if ( F_80 ( V_58 . V_43 == V_7 ) ) {
int V_146 ;
int V_141 = F_76 ( V_15 , & V_146 , V_110 ) ;
if ( V_146 )
return V_141 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
}
V_40 = F_92 ( V_36 , V_58 . V_43 ) ;
if ( F_80 ( ! V_40 ) )
return V_102 ;
V_41 = V_40 -> V_41 ;
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_67 ( V_15 ) -> V_135 == V_158 ) {
if ( F_60 ( V_15 ,
F_55 ( V_110 ) ) )
return V_151 ;
}
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
} else
#endif
if ( F_80 ( F_77 ( F_59 ( V_15 ) ) && ! V_41 -> V_156 ) ) {
if ( F_56 ( V_15 ,
F_55 ( V_110 ) ) )
return V_151 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
}
V_13 = V_41 -> V_157 ( V_51 , V_15 , & V_58 , V_58 . V_30 , 0 ) ;
if ( F_14 ( V_13 ) )
return F_86 ( V_51 , V_15 , V_40 , V_13 , V_58 . V_30 ) ;
if ( F_50 ( V_36 ) &&
( V_41 -> V_43 == V_5 ||
V_41 -> V_43 == V_4 ||
V_41 -> V_43 == V_6 ) ) {
T_1 V_82 [ 2 ] , * V_83 ;
V_83 = F_33 ( V_15 , V_58 . V_30 ,
sizeof( V_82 ) , V_82 ) ;
if ( V_83 == NULL )
return V_102 ;
if ( F_93 ( V_36 , V_51 , V_58 . V_43 ,
& V_58 . V_67 ,
V_83 [ 0 ] ) ) {
if ( ( V_58 . V_43 != V_5 &&
V_58 . V_43 != V_6 )
|| ( ( V_58 . V_43 == V_5
&& ! F_85 ( V_15 , V_58 . V_30 ) )
|| ( V_58 . V_43 == V_6
&& ! F_84 ( V_15 ,
V_58 . V_30 ) ) ) ) {
#ifdef F_2
if ( V_51 == V_65 ) {
struct V_36 * V_36 =
F_45 ( F_46 ( V_15 ) -> V_85 ) ;
if ( ! V_15 -> V_85 )
V_15 -> V_85 = V_36 -> V_103 ;
F_47 ( V_15 ,
V_104 ,
V_105 ,
0 ) ;
} else
#endif
F_48 ( V_15 ,
V_106 ,
V_107 , 0 ) ;
return V_91 ;
}
}
}
F_34 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_33 ) ;
return V_102 ;
}
static unsigned int
F_94 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
return F_89 ( V_110 , V_15 , V_132 ) ;
}
static unsigned int
F_96 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
unsigned int V_141 ;
F_97 () ;
V_141 = F_89 ( V_110 , V_15 , V_132 ) ;
F_98 () ;
return V_141 ;
}
static unsigned int
F_99 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
return F_89 ( V_110 , V_15 , V_65 ) ;
}
static unsigned int
F_100 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
unsigned int V_141 ;
F_97 () ;
V_141 = F_89 ( V_110 , V_15 , V_65 ) ;
F_98 () ;
return V_141 ;
}
static int
F_101 ( struct V_14 * V_15 , int * V_146 , unsigned int V_110 )
{
struct V_36 * V_36 = NULL ;
struct V_122 * V_58 ;
struct V_125 V_147 , * V_148 ;
struct V_122 V_149 , * V_150 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_108 , V_124 , V_141 ;
* V_146 = 1 ;
if ( F_77 ( F_59 ( V_15 ) ) ) {
if ( F_56 ( V_15 , F_55 ( V_110 ) ) )
return V_151 ;
}
V_58 = F_59 ( V_15 ) ;
V_108 = V_124 = V_58 -> V_124 * 4 ;
V_148 = F_33 ( V_15 , V_108 , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
return V_91 ;
F_27 ( 12 , L_34 ,
V_148 -> type , F_24 ( F_78 ( V_148 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_148 -> type != V_106 ) &&
( V_148 -> type != V_152 ) &&
( V_148 -> type != V_153 ) ) {
* V_146 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_147 ) ;
V_150 = F_33 ( V_15 , V_108 , sizeof( V_149 ) , & V_149 ) ;
if ( V_150 == NULL )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_40 = F_92 ( V_36 , V_150 -> V_43 ) ;
if ( ! V_40 )
return V_102 ;
V_41 = V_40 -> V_41 ;
if ( F_80 ( V_150 -> V_154 & F_81 ( V_155 ) &&
V_41 -> V_156 ) )
return V_102 ;
F_34 ( 11 , V_132 , V_41 , V_15 , V_108 ,
L_35 ) ;
V_108 += V_150 -> V_124 * 4 ;
F_19 ( V_132 , V_150 , & V_127 ) ;
V_13 = V_41 -> V_87 ( V_132 , V_15 , & V_127 , V_108 , 1 ) ;
if ( ! V_13 )
return V_102 ;
V_141 = V_91 ;
if ( ! F_72 ( V_15 ) && F_52 ( V_15 , V_124 ) ) {
F_27 ( 1 , L_36 ,
& V_58 -> V_67 ) ;
goto V_142;
}
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_150 -> V_43 || V_4 == V_150 -> V_43 )
V_108 += 2 * sizeof( V_143 ) ;
V_141 = F_102 ( V_15 , V_13 , V_41 , V_108 , V_110 ) ;
V_142:
F_35 ( V_13 ) ;
return V_141 ;
}
static int
F_103 ( struct V_14 * V_15 , int * V_146 , unsigned int V_110 )
{
struct V_36 * V_36 = NULL ;
struct V_133 * V_58 ;
struct V_134 V_147 , * V_148 ;
struct V_133 V_149 , * V_150 ;
struct V_57 V_127 ;
struct V_12 * V_13 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
unsigned int V_108 , V_141 ;
* V_146 = 1 ;
if ( F_67 ( V_15 ) -> V_135 == V_158 ) {
if ( F_60 ( V_15 , F_55 ( V_110 ) ) )
return V_151 ;
}
V_58 = F_67 ( V_15 ) ;
V_108 = sizeof( struct V_133 ) ;
V_148 = F_33 ( V_15 , V_108 , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
return V_91 ;
F_27 ( 12 , L_37 ,
V_148 -> V_159 , F_24 ( F_83 ( V_148 ) ) ,
& V_58 -> V_67 , & V_58 -> V_69 ) ;
if ( ( V_148 -> V_159 != V_104 ) &&
( V_148 -> V_159 != V_160 ) &&
( V_148 -> V_159 != V_161 ) ) {
* V_146 = 0 ;
return V_102 ;
}
V_108 += sizeof( V_147 ) ;
V_150 = F_33 ( V_15 , V_108 , sizeof( V_149 ) , & V_149 ) ;
if ( V_150 == NULL )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
V_40 = F_92 ( V_36 , V_150 -> V_135 ) ;
if ( ! V_40 )
return V_102 ;
V_41 = V_40 -> V_41 ;
if ( F_80 ( V_150 -> V_135 == V_158 && V_41 -> V_156 ) )
return V_102 ;
F_34 ( 11 , V_65 , V_41 , V_15 , V_108 ,
L_38 ) ;
V_108 += sizeof( struct V_133 ) ;
F_19 ( V_65 , V_150 , & V_127 ) ;
V_13 = V_41 -> V_87 ( V_65 , V_15 , & V_127 , V_108 , 1 ) ;
if ( ! V_13 )
return V_102 ;
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_150 -> V_135 || V_4 == V_150 -> V_135 ||
V_6 == V_150 -> V_135 )
V_108 += 2 * sizeof( V_143 ) ;
V_141 = F_104 ( V_15 , V_13 , V_41 , V_108 , V_110 ) ;
F_35 ( V_13 ) ;
return V_141 ;
}
static unsigned int
F_105 ( unsigned int V_110 , struct V_14 * V_15 , int V_51 )
{
struct V_36 * V_36 ;
struct V_57 V_58 ;
struct V_81 * V_41 ;
struct V_39 * V_40 ;
struct V_12 * V_13 ;
int V_95 , V_185 ;
struct V_18 * V_19 ;
if ( V_15 -> V_144 )
return V_102 ;
if ( F_80 ( ( V_15 -> V_186 != V_187 &&
V_110 != V_175 ) ||
! F_46 ( V_15 ) ) ) {
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
F_22 ( 12 , L_39
L_40 ,
V_15 -> V_186 , V_58 . V_43 ,
F_23 ( V_51 , & V_58 . V_69 ) , V_110 ) ;
return V_102 ;
}
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_182 )
return V_102 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
if ( F_80 ( V_15 -> V_174 != NULL && V_110 == V_175 &&
V_51 == V_132 ) ) {
struct V_176 * V_174 = V_15 -> V_174 ;
struct V_177 * V_178 = F_91 ( V_15 -> V_174 ) ;
if ( V_178 && V_174 -> V_179 == V_180 && V_178 -> V_181 )
return V_102 ;
}
#ifdef F_2
if ( V_51 == V_65 ) {
if ( F_80 ( V_58 . V_43 == V_8 ) ) {
int V_146 ;
int V_141 = F_103 ( V_15 , & V_146 , V_110 ) ;
if ( V_146 )
return V_141 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
}
} else
#endif
if ( F_80 ( V_58 . V_43 == V_7 ) ) {
int V_146 ;
int V_141 = F_101 ( V_15 , & V_146 , V_110 ) ;
if ( V_146 )
return V_141 ;
F_19 ( V_51 , F_20 ( V_15 ) , & V_58 ) ;
}
V_40 = F_92 ( V_36 , V_58 . V_43 ) ;
if ( F_80 ( ! V_40 ) )
return V_102 ;
V_41 = V_40 -> V_41 ;
V_13 = V_41 -> V_87 ( V_51 , V_15 , & V_58 , V_58 . V_30 , 0 ) ;
if ( F_80 ( ! V_13 ) ) {
int V_188 ;
if ( ! V_41 -> V_189 ( V_51 , V_15 , V_40 , & V_188 , & V_13 ) )
return V_188 ;
}
if ( F_80 ( ! V_13 ) ) {
F_34 ( 12 , V_51 , V_41 , V_15 , 0 ,
L_41 ) ;
return V_102 ;
}
F_34 ( 11 , V_51 , V_41 , V_15 , 0 , L_42 ) ;
V_19 = F_6 ( V_36 ) ;
if ( V_13 -> V_17 && ! ( V_13 -> V_17 -> V_20 & V_21 ) ) {
if ( F_51 ( V_19 ) ) {
F_106 ( V_13 ) ;
}
F_35 ( V_13 ) ;
return V_91 ;
}
F_5 ( V_13 , V_15 ) ;
F_13 ( V_13 , V_99 , V_15 , V_40 ) ;
if ( V_13 -> V_100 )
V_95 = V_13 -> V_100 ( V_15 , V_13 , V_41 ) ;
else {
F_107 ( L_43 ) ;
V_95 = V_102 ;
}
if ( V_13 -> V_20 & V_80 )
V_185 = F_108 ( V_19 ) ;
else
V_185 = F_109 ( 1 , & V_13 -> V_101 ) ;
if ( V_19 -> V_190 & V_191 )
F_110 ( V_36 , V_13 , V_185 ) ;
F_30 ( V_13 ) ;
return V_95 ;
}
static unsigned int
F_111 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 ,
const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
return F_105 ( V_110 , V_15 , V_132 ) ;
}
static unsigned int
F_112 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
unsigned int V_141 ;
F_97 () ;
V_141 = F_105 ( V_110 , V_15 , V_132 ) ;
F_98 () ;
return V_141 ;
}
static unsigned int
F_113 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 ,
const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
return F_105 ( V_110 , V_15 , V_65 ) ;
}
static unsigned int
F_114 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
unsigned int V_141 ;
F_97 () ;
V_141 = F_105 ( V_110 , V_15 , V_65 ) ;
F_98 () ;
return V_141 ;
}
static unsigned int
F_115 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
int V_192 ;
struct V_36 * V_36 ;
if ( F_59 ( V_15 ) -> V_43 != V_7 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_182 )
return V_102 ;
return F_101 ( V_15 , & V_192 , V_110 ) ;
}
static unsigned int
F_116 ( unsigned int V_110 , struct V_14 * V_15 ,
const struct V_183 * V_184 , const struct V_183 * V_142 ,
int (* F_95)( struct V_14 * ) )
{
int V_192 ;
struct V_36 * V_36 ;
if ( F_67 ( V_15 ) -> V_135 != V_8 )
return V_102 ;
V_36 = F_7 ( V_15 ) ;
if ( ! F_6 ( V_36 ) -> V_182 )
return V_102 ;
return F_103 ( V_15 , & V_192 , V_110 ) ;
}
static int T_6 F_117 ( struct V_36 * V_36 )
{
struct V_18 * V_19 ;
V_19 = F_118 ( V_36 , V_193 ) ;
if ( V_19 == NULL )
return - V_194 ;
V_19 -> V_182 = 0 ;
V_19 -> V_36 = V_36 ;
V_19 -> V_195 = F_38 ( & V_196 ) ;
F_44 ( & V_196 ) ;
V_36 -> V_19 = V_19 ;
if ( F_119 ( V_36 ) < 0 )
goto V_197;
if ( F_120 ( V_36 ) < 0 )
goto V_198;
if ( F_121 ( V_36 ) < 0 )
goto V_199;
if ( F_122 ( V_36 ) < 0 )
goto V_200;
if ( F_123 ( V_36 ) < 0 )
goto V_201;
if ( F_124 ( V_36 ) < 0 )
goto V_202;
F_125 ( V_203 L_44 ,
sizeof( struct V_18 ) , V_19 -> V_195 ) ;
return 0 ;
V_202:
F_126 ( V_36 ) ;
V_201:
F_127 ( V_36 ) ;
V_200:
F_128 ( V_36 ) ;
V_199:
F_129 ( V_36 ) ;
V_198:
F_130 ( V_36 ) ;
V_197:
V_36 -> V_19 = NULL ;
return - V_194 ;
}
static void T_7 F_131 ( struct V_36 * V_36 )
{
F_132 ( V_36 ) ;
F_126 ( V_36 ) ;
F_127 ( V_36 ) ;
F_128 ( V_36 ) ;
F_129 ( V_36 ) ;
F_130 ( V_36 ) ;
F_27 ( 2 , L_45 , F_6 ( V_36 ) -> V_195 ) ;
V_36 -> V_19 = NULL ;
}
static void T_7 F_133 ( struct V_36 * V_36 )
{
F_90 ( 2 ) ;
F_6 ( V_36 ) -> V_182 = 0 ;
F_134 () ;
F_135 ( V_36 ) ;
F_87 ( 2 ) ;
}
static int T_8 F_136 ( void )
{
int V_95 ;
V_95 = F_137 () ;
if ( V_95 < 0 ) {
F_36 ( L_46 ) ;
goto exit;
}
F_138 () ;
V_95 = F_139 () ;
if ( V_95 < 0 ) {
F_36 ( L_47 ) ;
goto V_204;
}
V_95 = F_140 ( & V_205 ) ;
if ( V_95 < 0 )
goto V_206;
V_95 = F_141 ( & V_207 ) ;
if ( V_95 < 0 )
goto V_208;
V_95 = F_142 ( V_209 , F_143 ( V_209 ) ) ;
if ( V_95 < 0 ) {
F_36 ( L_48 ) ;
goto V_210;
}
V_95 = F_144 () ;
if ( V_95 < 0 ) {
F_36 ( L_49 ) ;
goto V_211;
}
F_145 ( L_50 ) ;
return V_95 ;
V_211:
F_146 ( V_209 , F_143 ( V_209 ) ) ;
V_210:
F_147 ( & V_207 ) ;
V_208:
F_148 ( & V_205 ) ;
V_206:
F_149 () ;
V_204:
F_150 () ;
F_151 () ;
exit:
return V_95 ;
}
static void T_9 F_152 ( void )
{
F_153 () ;
F_146 ( V_209 , F_143 ( V_209 ) ) ;
F_147 ( & V_207 ) ;
F_148 ( & V_205 ) ;
F_149 () ;
F_150 () ;
F_151 () ;
F_145 ( L_51 ) ;
}
