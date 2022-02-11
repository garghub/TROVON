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
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_17 && ( V_17 -> V_20 & V_21 ) ) {
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_6 ( V_17 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_30 ++ ;
V_23 -> V_29 . V_31 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
F_9 () ;
V_25 = F_10 ( V_17 -> V_25 ) ;
V_23 = F_6 ( V_25 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_30 ++ ;
V_23 -> V_29 . V_31 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
F_11 () ;
V_23 = F_6 ( V_19 -> V_33 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_30 ++ ;
V_23 -> V_29 . V_31 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
}
}
static inline void
F_12 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_17 ;
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_17 && ( V_17 -> V_20 & V_21 ) ) {
struct V_22 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_6 ( V_17 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_34 ++ ;
V_23 -> V_29 . V_35 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
F_9 () ;
V_25 = F_10 ( V_17 -> V_25 ) ;
V_23 = F_6 ( V_25 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_34 ++ ;
V_23 -> V_29 . V_35 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
F_11 () ;
V_23 = F_6 ( V_19 -> V_33 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_34 ++ ;
V_23 -> V_29 . V_35 += V_15 -> V_32 ;
F_8 ( & V_23 -> V_28 ) ;
}
}
static inline void
F_13 ( struct V_12 * V_13 , struct V_24 * V_25 )
{
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_22 * V_23 ;
V_23 = F_6 ( V_13 -> V_17 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_36 ++ ;
F_8 ( & V_23 -> V_28 ) ;
V_23 = F_6 ( V_25 -> V_26 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_36 ++ ;
F_8 ( & V_23 -> V_28 ) ;
V_23 = F_6 ( V_19 -> V_33 . V_27 ) ;
F_7 ( & V_23 -> V_28 ) ;
V_23 -> V_29 . V_36 ++ ;
F_8 ( & V_23 -> V_28 ) ;
}
static inline void
F_14 ( struct V_12 * V_13 , int V_37 ,
const struct V_14 * V_15 ,
struct V_38 * V_39 )
{
if ( F_15 ( V_39 -> V_40 -> V_41 ) )
V_39 -> V_40 -> V_41 ( V_13 , V_37 , V_15 , V_39 ) ;
}
static inline int
F_16 ( const struct V_24 * V_25 ,
struct V_14 * V_15 , int V_42 ,
const union V_43 * V_44 , T_1 V_45 ,
const union V_43 * V_46 , T_1 V_47 ,
struct V_48 * V_49 )
{
F_17 ( V_25 -> V_19 , V_25 -> V_50 , V_42 , V_44 , V_45 , V_46 ,
V_47 , V_49 ) ;
V_49 -> V_51 = F_10 ( V_25 -> V_51 ) ;
if ( V_49 -> V_51 && V_49 -> V_51 -> V_52 )
return V_49 -> V_51 -> V_52 ( V_49 , V_15 ) ;
return 0 ;
}
static struct V_12 *
F_18 ( struct V_24 * V_25 ,
struct V_14 * V_15 , T_1 V_53 , T_1 V_54 ,
int * V_55 , struct V_56 * V_57 )
{
struct V_12 * V_13 = NULL ;
struct V_16 * V_17 ;
struct V_12 * V_58 ;
T_1 V_59 = 0 ;
unsigned int V_20 ;
struct V_48 V_60 ;
const union V_43 V_61 = { . V_62 = F_19 (svc->fwmark) } ;
union V_43 V_63 ;
const union V_43 * V_64 , * V_65 ;
if ( F_15 ( ! F_20 ( V_57 ) ) ) {
V_64 = & V_57 -> V_66 ;
V_65 = & V_57 -> V_67 ;
} else {
V_64 = & V_57 -> V_67 ;
V_65 = & V_57 -> V_66 ;
}
#ifdef F_2
if ( V_25 -> V_50 == V_68 )
F_21 ( & V_63 . V_69 , & V_64 -> V_69 ,
( V_70 V_71 ) V_25 -> V_72 ) ;
else
#endif
V_63 . V_62 = V_64 -> V_62 & V_25 -> V_72 ;
F_22 ( 6 , L_8
L_9 ,
F_23 ( V_25 -> V_50 , V_64 ) , F_24 ( V_53 ) ,
F_23 ( V_25 -> V_50 , V_65 ) , F_24 ( V_54 ) ,
F_23 ( V_25 -> V_50 , & V_63 ) ) ;
{
int V_42 = V_57 -> V_42 ;
const union V_43 * V_46 = V_65 ;
T_1 V_47 = 0 ;
if ( V_54 == V_25 -> V_73 ) {
if ( V_25 -> V_73 != V_74 )
V_47 = V_54 ;
} else {
if ( V_25 -> V_61 ) {
V_42 = V_3 ;
V_46 = & V_61 ;
}
}
if ( F_16 ( V_25 , V_15 , V_42 , & V_63 , 0 ,
V_46 , V_47 , & V_60 ) < 0 ) {
* V_55 = - 1 ;
return NULL ;
}
}
V_58 = F_25 ( & V_60 ) ;
if ( ! V_58 || ! F_26 ( V_58 , NULL ) ) {
struct V_75 * V_76 ;
V_76 = F_10 ( V_25 -> V_77 ) ;
if ( V_76 ) {
F_27 () ;
V_17 = V_76 -> V_78 ( V_25 , V_15 , V_57 ) ;
} else {
V_17 = NULL ;
}
if ( ! V_17 ) {
F_28 ( 1 , L_10 ) ;
F_29 ( V_60 . V_79 ) ;
* V_55 = 0 ;
return NULL ;
}
if ( V_54 == V_25 -> V_73 && V_25 -> V_73 != V_74 )
V_59 = V_17 -> V_73 ;
V_58 = F_30 ( & V_60 , V_17 -> V_50 , & V_17 -> V_80 , V_59 ,
V_81 , V_17 , V_15 -> V_82 ) ;
if ( V_58 == NULL ) {
F_29 ( V_60 . V_79 ) ;
* V_55 = - 1 ;
return NULL ;
}
V_58 -> V_83 = V_25 -> V_83 ;
} else {
V_17 = V_58 -> V_17 ;
F_29 ( V_60 . V_79 ) ;
}
V_59 = V_54 ;
if ( V_59 == V_25 -> V_73 && V_17 -> V_73 )
V_59 = V_17 -> V_73 ;
V_20 = ( V_25 -> V_20 & V_84
&& V_57 -> V_42 == V_4 ) ?
V_85 : 0 ;
F_17 ( V_25 -> V_19 , V_25 -> V_50 , V_57 -> V_42 , V_64 ,
V_53 , V_65 , V_54 , & V_60 ) ;
V_13 = F_30 ( & V_60 , V_17 -> V_50 , & V_17 -> V_80 , V_59 , V_20 , V_17 ,
V_15 -> V_82 ) ;
if ( V_13 == NULL ) {
F_31 ( V_58 ) ;
* V_55 = - 1 ;
return NULL ;
}
F_32 ( V_13 , V_58 ) ;
F_31 ( V_58 ) ;
F_13 ( V_13 , V_25 ) ;
return V_13 ;
}
struct V_12 *
F_33 ( struct V_24 * V_25 , struct V_14 * V_15 ,
struct V_38 * V_39 , int * V_55 ,
struct V_56 * V_57 )
{
struct V_86 * V_40 = V_39 -> V_40 ;
struct V_12 * V_13 = NULL ;
struct V_75 * V_76 ;
struct V_16 * V_17 ;
T_1 V_87 [ 2 ] , * V_88 , V_45 , V_47 ;
const void * V_44 , * V_46 ;
unsigned int V_20 ;
* V_55 = 1 ;
V_88 = F_34 ( V_15 , V_57 -> V_32 , sizeof( V_87 ) , V_87 , V_57 ) ;
if ( V_88 == NULL )
return NULL ;
if ( F_15 ( ! F_20 ( V_57 ) ) ) {
V_45 = V_88 [ 0 ] ;
V_44 = & V_57 -> V_66 ;
V_47 = V_88 [ 1 ] ;
V_46 = & V_57 -> V_67 ;
} else {
V_45 = V_88 [ 1 ] ;
V_44 = & V_57 -> V_67 ;
V_47 = V_88 [ 0 ] ;
V_46 = & V_57 -> V_66 ;
}
if ( V_45 == V_89 ) {
F_35 ( 12 , V_25 -> V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_11 ) ;
return NULL ;
}
if ( ( ! V_15 -> V_91 || V_15 -> V_91 -> V_20 & V_92 ) ) {
V_57 -> V_93 ^= V_94 ;
V_13 = V_40 -> V_95 ( V_25 -> V_19 , V_25 -> V_50 , V_15 , V_57 ) ;
V_57 -> V_93 ^= V_94 ;
if ( V_13 ) {
F_35 ( 12 , V_25 -> V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_12
L_13 ) ;
F_36 ( V_13 ) ;
return NULL ;
}
}
if ( V_25 -> V_20 & V_96 )
return F_18 ( V_25 , V_15 , V_45 , V_47 , V_55 ,
V_57 ) ;
* V_55 = 0 ;
if ( ! V_25 -> V_61 && V_47 != V_25 -> V_73 ) {
if ( ! V_25 -> V_73 )
F_37 ( L_14
L_15
L_16 ) ;
return NULL ;
}
V_76 = F_10 ( V_25 -> V_77 ) ;
if ( V_76 ) {
F_27 () ;
V_17 = V_76 -> V_78 ( V_25 , V_15 , V_57 ) ;
} else {
V_17 = NULL ;
}
if ( V_17 == NULL ) {
F_28 ( 1 , L_17 ) ;
return NULL ;
}
V_20 = ( V_25 -> V_20 & V_84
&& V_57 -> V_42 == V_4 ) ?
V_85 : 0 ;
{
struct V_48 V_49 ;
F_17 ( V_25 -> V_19 , V_25 -> V_50 , V_57 -> V_42 ,
V_44 , V_45 , V_46 , V_47 , & V_49 ) ;
V_13 = F_30 ( & V_49 , V_17 -> V_50 , & V_17 -> V_80 ,
V_17 -> V_73 ? V_17 -> V_73 : V_47 ,
V_20 , V_17 , V_15 -> V_82 ) ;
if ( ! V_13 ) {
* V_55 = - 1 ;
return NULL ;
}
}
F_22 ( 6 , L_18
L_19 ,
F_38 ( V_13 ) ,
F_23 ( V_13 -> V_50 , & V_13 -> V_44 ) , F_24 ( V_13 -> V_45 ) ,
F_23 ( V_13 -> V_50 , & V_13 -> V_46 ) , F_24 ( V_13 -> V_47 ) ,
F_23 ( V_13 -> V_97 , & V_13 -> V_67 ) , F_24 ( V_13 -> V_59 ) ,
V_13 -> V_20 , F_39 ( & V_13 -> V_98 ) ) ;
F_13 ( V_13 , V_25 ) ;
return V_13 ;
}
static inline int F_40 ( struct V_99 * V_99 , int V_50 ,
union V_43 * V_80 )
{
#ifdef F_2
if ( V_50 == V_68 )
return F_41 ( & V_80 -> V_69 ) & V_100 ;
#endif
return ( F_42 ( V_99 , V_80 -> V_62 ) == V_101 ) ;
}
int F_43 ( struct V_24 * V_25 , struct V_14 * V_15 ,
struct V_38 * V_39 , struct V_56 * V_57 )
{
T_1 V_87 [ 2 ] , * V_88 , V_59 ;
struct V_18 * V_19 = V_25 -> V_19 ;
struct V_99 * V_99 = V_19 -> V_99 ;
V_88 = F_34 ( V_15 , V_57 -> V_32 , sizeof( V_87 ) , V_87 , V_57 ) ;
if ( ! V_88 )
return V_102 ;
V_59 = F_15 ( ! F_20 ( V_57 ) ) ? V_88 [ 1 ] : V_88 [ 0 ] ;
if ( F_44 ( V_19 ) && V_25 -> V_61 &&
! ( V_57 -> V_93 & ( V_94 | V_103 ) ) &&
F_40 ( V_99 , V_25 -> V_50 , & V_57 -> V_67 ) ) {
int V_104 ;
struct V_12 * V_13 ;
unsigned int V_20 = ( V_25 -> V_20 & V_84 &&
V_57 -> V_42 == V_4 ) ?
V_85 : 0 ;
union V_43 V_67 = { . V_105 = { 0 , 0 , 0 , 0 } } ;
F_28 ( 6 , L_20 , V_106 ) ;
{
struct V_48 V_49 ;
F_17 ( V_25 -> V_19 , V_25 -> V_50 , V_57 -> V_42 ,
& V_57 -> V_66 , V_88 [ 0 ] ,
& V_57 -> V_67 , V_88 [ 1 ] , & V_49 ) ;
V_13 = F_30 ( & V_49 , V_25 -> V_50 , & V_67 , 0 ,
V_107 | V_20 ,
NULL , V_15 -> V_82 ) ;
if ( ! V_13 )
return V_102 ;
}
F_5 ( V_13 , V_15 ) ;
F_14 ( V_13 , V_108 , V_15 , V_39 ) ;
V_104 = V_13 -> V_109 ( V_15 , V_13 , V_39 -> V_40 , V_57 ) ;
if ( ( V_13 -> V_20 & V_85 ) && V_13 -> V_110 )
F_45 ( & V_13 -> V_110 -> V_111 ) ;
else
F_45 ( & V_13 -> V_111 ) ;
F_31 ( V_13 ) ;
return V_104 ;
}
if ( V_25 -> V_73 == V_74 && V_59 != V_74 )
return V_112 ;
if ( F_46 ( F_47 ( V_57 ) ) )
return V_102 ;
#ifdef F_2
if ( V_25 -> V_50 == V_68 ) {
if ( ! V_15 -> V_91 )
V_15 -> V_91 = V_99 -> V_113 ;
F_48 ( V_15 , V_114 , V_115 , 0 ) ;
} else
#endif
F_49 ( V_15 , V_116 , V_117 , 0 ) ;
return V_102 ;
}
static int F_50 ( struct V_18 * V_19 )
{
return V_19 -> F_50 ;
}
static int F_51 ( struct V_18 * V_19 )
{
return V_19 -> F_51 ;
}
static int F_52 ( struct V_18 * V_19 )
{
return V_19 -> F_52 ;
}
static int F_50 ( struct V_18 * V_19 ) { return 0 ; }
static int F_51 ( struct V_18 * V_19 ) { return 0 ; }
static int F_52 ( struct V_18 * V_19 ) { return 0 ; }
T_2 F_53 ( struct V_14 * V_15 , int V_118 )
{
return F_54 ( F_55 ( V_15 , V_118 , V_15 -> V_32 - V_118 , 0 ) ) ;
}
static inline enum V_119 F_56 ( unsigned int V_120 )
{
if ( V_121 == V_120 )
return V_122 ;
if ( V_123 == V_120 )
return V_124 ;
return V_125 ;
}
static inline int F_57 ( struct V_18 * V_19 ,
struct V_14 * V_15 , T_3 V_126 )
{
int V_127 ;
F_58 () ;
V_127 = F_59 ( V_19 -> V_99 , V_15 , V_126 ) ;
F_60 () ;
if ( ! V_127 )
F_61 ( F_62 ( V_15 ) ) ;
return V_127 ;
}
static int F_63 ( struct V_18 * V_19 , int V_50 ,
struct V_14 * V_15 , unsigned int V_120 )
{
if ( ! F_50 ( V_19 ) )
return 0 ;
if ( V_121 == V_120 )
return 0 ;
#ifdef F_2
if ( V_50 == V_68 ) {
struct V_128 * V_129 = F_64 ( V_15 ) ;
if ( V_129 -> V_91 && ! ( V_129 -> V_91 -> V_20 & V_92 ) &&
F_65 ( V_19 -> V_99 , V_15 ) != 0 )
return 1 ;
} else
#endif
if ( ! ( F_66 ( V_15 ) -> V_130 & V_131 ) &&
F_67 ( V_19 -> V_99 , V_15 , V_132 ) != 0 )
return 1 ;
return 0 ;
}
void F_68 ( struct V_14 * V_15 , struct V_86 * V_40 ,
struct V_12 * V_13 , int V_133 )
{
struct V_134 * V_57 = F_62 ( V_15 ) ;
unsigned int V_135 = V_57 -> V_136 * 4 ;
struct V_137 * V_138 = (struct V_137 * ) ( F_69 ( V_15 ) +
V_135 ) ;
struct V_134 * V_139 = (struct V_134 * ) ( V_138 + 1 ) ;
if ( V_133 ) {
V_57 -> V_66 = V_13 -> V_46 . V_62 ;
F_61 ( V_57 ) ;
V_139 -> V_67 = V_13 -> V_46 . V_62 ;
F_61 ( V_139 ) ;
} else {
V_57 -> V_67 = V_13 -> V_67 . V_62 ;
F_61 ( V_57 ) ;
V_139 -> V_66 = V_13 -> V_67 . V_62 ;
F_61 ( V_139 ) ;
}
if ( V_5 == V_139 -> V_42 || V_4 == V_139 -> V_42 ||
V_6 == V_139 -> V_42 ) {
T_1 * V_140 = ( void * ) V_139 + V_139 -> V_136 * 4 ;
if ( V_133 )
V_140 [ 1 ] = V_13 -> V_47 ;
else
V_140 [ 0 ] = V_13 -> V_59 ;
}
V_138 -> V_141 = 0 ;
V_138 -> V_141 = F_53 ( V_15 , V_135 ) ;
V_15 -> V_142 = V_143 ;
if ( V_133 )
F_35 ( 11 , V_144 , V_40 , V_15 , ( void * ) V_139 - ( void * ) V_57 ,
L_21 ) ;
else
F_35 ( 11 , V_144 , V_40 , V_15 , ( void * ) V_139 - ( void * ) V_57 ,
L_22 ) ;
}
void F_70 ( struct V_14 * V_15 , struct V_86 * V_40 ,
struct V_12 * V_13 , int V_133 )
{
struct V_145 * V_57 = F_71 ( V_15 ) ;
unsigned int V_135 = 0 ;
unsigned int V_146 = 0 ;
int V_42 ;
struct V_147 * V_138 ;
struct V_145 * V_139 ;
unsigned short V_148 ;
F_72 ( V_15 , & V_135 , V_8 , & V_148 , NULL ) ;
V_138 = (struct V_147 * ) ( F_69 ( V_15 ) + V_135 ) ;
V_146 = V_135 + sizeof( struct V_147 ) ;
V_139 = (struct V_145 * ) ( F_69 ( V_15 ) + V_146 ) ;
V_42 = F_72 ( V_15 , & V_146 , - 1 , & V_148 , NULL ) ;
if ( V_133 ) {
V_57 -> V_66 = V_13 -> V_46 . V_69 ;
V_139 -> V_67 = V_13 -> V_46 . V_69 ;
} else {
V_57 -> V_67 = V_13 -> V_67 . V_69 ;
V_139 -> V_66 = V_13 -> V_67 . V_69 ;
}
if ( ! V_148 && ( V_5 == V_42 || V_4 == V_42 ||
V_6 == V_42 ) ) {
T_1 * V_140 = ( void * ) ( F_69 ( V_15 ) + V_146 ) ;
F_28 ( 11 , L_23 , V_106 ,
F_24 ( V_133 ? V_140 [ 1 ] : V_140 [ 0 ] ) ,
F_24 ( V_133 ? V_13 -> V_47 : V_13 -> V_59 ) ) ;
if ( V_133 )
V_140 [ 1 ] = V_13 -> V_47 ;
else
V_140 [ 0 ] = V_13 -> V_59 ;
}
V_138 -> V_149 = ~ F_73 ( & V_57 -> V_66 , & V_57 -> V_67 ,
V_15 -> V_32 - V_135 ,
V_8 , 0 ) ;
V_15 -> V_150 = F_69 ( V_15 ) - V_15 -> V_151 + V_135 ;
V_15 -> V_152 = F_74 ( struct V_147 , V_149 ) ;
V_15 -> V_142 = V_153 ;
if ( V_133 )
F_35 ( 11 , V_68 , V_40 , V_15 ,
( void * ) V_139 - ( void * ) V_57 ,
L_24 ) ;
else
F_35 ( 11 , V_68 , V_40 , V_15 ,
( void * ) V_139 - ( void * ) V_57 ,
L_25 ) ;
}
static int F_75 ( int V_50 , struct V_14 * V_15 ,
union V_43 * V_63 ,
T_4 V_42 , struct V_12 * V_13 ,
struct V_86 * V_40 ,
unsigned int V_118 , unsigned int V_136 ,
unsigned int V_120 )
{
unsigned int V_154 = V_102 ;
if ( F_76 ( V_13 ) != 0 ) {
F_37 ( L_26
L_27 ) ;
}
if ( ! F_77 ( V_15 ) && F_53 ( V_15 , V_136 ) ) {
F_22 ( 1 , L_28 ,
F_23 ( V_50 , V_63 ) ) ;
goto V_155;
}
if ( V_5 == V_42 || V_4 == V_42 ||
V_6 == V_42 )
V_118 += 2 * sizeof( V_156 ) ;
if ( ! F_78 ( V_15 , V_118 ) )
goto V_155;
#ifdef F_2
if ( V_50 == V_68 )
F_70 ( V_15 , V_40 , V_13 , 1 ) ;
else
#endif
F_68 ( V_15 , V_40 , V_13 , 1 ) ;
if ( F_63 ( V_13 -> V_19 , V_50 , V_15 , V_120 ) )
goto V_155;
F_12 ( V_13 , V_15 ) ;
V_15 -> V_157 = 1 ;
if ( ! ( V_13 -> V_20 & V_158 ) )
F_79 ( V_15 ) ;
else
F_80 ( V_15 , V_13 , 0 ) ;
V_154 = V_112 ;
V_155:
F_36 ( V_13 ) ;
return V_154 ;
}
static int F_81 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_159 , unsigned int V_120 )
{
struct V_134 * V_57 ;
struct V_137 V_160 , * V_161 ;
struct V_134 V_162 , * V_163 ;
struct V_56 V_139 ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
unsigned int V_118 , V_136 ;
union V_43 V_63 ;
* V_159 = 1 ;
if ( F_82 ( F_62 ( V_15 ) ) ) {
if ( F_57 ( V_19 , V_15 , F_56 ( V_120 ) ) )
return V_164 ;
}
V_57 = F_62 ( V_15 ) ;
V_118 = V_136 = V_57 -> V_136 * 4 ;
V_161 = F_83 ( V_15 , V_118 , sizeof( V_160 ) , & V_160 ) ;
if ( V_161 == NULL )
return V_102 ;
F_28 ( 12 , L_29 ,
V_161 -> type , F_24 ( F_84 ( V_161 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
if ( ( V_161 -> type != V_116 ) &&
( V_161 -> type != V_165 ) &&
( V_161 -> type != V_166 ) ) {
* V_159 = 0 ;
return V_112 ;
}
V_118 += sizeof( V_160 ) ;
V_163 = F_83 ( V_15 , V_118 , sizeof( V_162 ) , & V_162 ) ;
if ( V_163 == NULL )
return V_112 ;
V_40 = F_85 ( V_163 -> V_42 ) ;
if ( ! V_40 )
return V_112 ;
if ( F_46 ( V_163 -> V_167 & F_86 ( V_168 ) &&
V_40 -> V_169 ) )
return V_112 ;
F_35 ( 11 , V_144 , V_40 , V_15 , V_118 ,
L_30 ) ;
F_87 ( V_144 , V_15 , V_118 , true , & V_139 ) ;
V_13 = V_40 -> V_170 ( V_19 , V_144 , V_15 , & V_139 ) ;
if ( ! V_13 )
return V_112 ;
V_63 . V_62 = V_57 -> V_66 ;
return F_75 ( V_144 , V_15 , & V_63 , V_163 -> V_42 , V_13 ,
V_40 , V_139 . V_32 , V_136 , V_120 ) ;
}
static int F_88 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_159 , unsigned int V_120 ,
struct V_56 * V_171 )
{
struct V_147 V_160 , * V_161 ;
struct V_56 V_139 = { . V_20 = 0 , . V_148 = 0 } ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
union V_43 V_63 ;
unsigned int V_118 ;
* V_159 = 1 ;
V_161 = F_34 ( V_15 , V_171 -> V_32 , sizeof( V_160 ) , & V_160 , V_171 ) ;
if ( V_161 == NULL )
return V_102 ;
if ( V_161 -> V_172 & V_173 ) {
* V_159 = 0 ;
return V_112 ;
}
if ( V_171 -> V_20 & V_174 )
return V_102 ;
F_28 ( 8 , L_31 ,
V_161 -> V_172 , F_24 ( F_89 ( V_161 ) ) ,
& V_171 -> V_66 , & V_171 -> V_67 ) ;
if ( ! F_87 ( V_68 , V_15 , V_171 -> V_32 + sizeof( V_160 ) ,
true , & V_139 ) )
return V_112 ;
V_40 = F_85 ( V_139 . V_42 ) ;
if ( ! V_40 )
return V_112 ;
V_13 = V_40 -> V_170 ( V_19 , V_68 , V_15 , & V_139 ) ;
if ( ! V_13 )
return V_112 ;
V_63 . V_69 = V_139 . V_66 . V_69 ;
V_118 = V_139 . V_32 ;
return F_75 ( V_68 , V_15 , & V_63 , V_139 . V_42 , V_13 ,
V_40 , V_118 , sizeof( struct V_145 ) ,
V_120 ) ;
}
static inline int F_90 ( const struct V_14 * V_15 , int V_175 )
{
T_5 * V_176 , V_177 ;
V_176 = F_83 ( V_15 , V_175 + sizeof( V_178 ) ,
sizeof( V_177 ) , & V_177 ) ;
if ( V_176 == NULL )
return 0 ;
if ( V_176 -> type == V_179 )
return 1 ;
return 0 ;
}
static inline int F_91 ( const struct V_14 * V_15 , int V_175 )
{
struct V_180 V_181 , * V_182 ;
V_182 = F_83 ( V_15 , V_175 , sizeof( V_181 ) , & V_181 ) ;
if ( V_182 == NULL )
return 0 ;
return V_182 -> V_183 ;
}
static inline bool F_92 ( const struct V_14 * V_15 ,
struct V_56 * V_57 )
{
switch ( V_57 -> V_42 ) {
case V_5 : {
struct V_180 V_181 , * V_182 ;
V_182 = F_83 ( V_15 , V_57 -> V_32 , sizeof( V_181 ) , & V_181 ) ;
if ( V_182 == NULL )
return false ;
return V_182 -> V_184 ;
}
case V_6 : {
T_5 * V_176 , V_177 ;
V_176 = F_83 ( V_15 , V_57 -> V_32 + sizeof( V_178 ) ,
sizeof( V_177 ) , & V_177 ) ;
if ( V_176 == NULL )
return false ;
return V_176 -> type == V_185 ;
}
default:
return false ;
}
}
static inline bool F_93 ( const struct V_12 * V_13 ,
int V_186 )
{
if ( V_13 -> V_110 )
return false ;
switch ( V_13 -> V_42 ) {
case V_5 :
return ( V_13 -> V_187 == V_188 ) ||
( V_13 -> V_187 == V_189 ) ||
( ( V_186 & 2 ) &&
( V_13 -> V_187 == V_190 ) &&
( V_13 -> V_20 & V_191 ) ) ;
case V_6 :
return V_13 -> V_187 == V_192 ;
default:
return false ;
}
}
struct V_12 * F_94 ( struct V_24 * V_25 ,
struct V_16 * V_17 ,
struct V_14 * V_15 ,
const struct V_56 * V_57 ,
T_1 V_59 ,
T_1 V_45 )
{
struct V_48 V_60 ;
struct V_12 * V_58 = NULL , * V_13 = NULL ;
const union V_43 * V_46 , * V_67 , * V_44 ;
union V_43 V_63 ;
T_1 V_47 ;
unsigned int V_20 ;
F_95 ( 12 ) ;
V_46 = & V_25 -> V_80 ;
V_47 = V_25 -> V_73 ;
V_67 = & V_57 -> V_66 ;
V_44 = & V_57 -> V_67 ;
if ( V_25 -> V_61 )
return NULL ;
if ( ! V_47 || ! V_59 )
return NULL ;
if ( V_25 -> V_20 & V_96 ) {
#ifdef F_2
if ( V_25 -> V_50 == V_68 )
F_21 ( & V_63 . V_69 , & V_44 -> V_69 ,
( V_70 V_71 ) V_25 -> V_72 ) ;
else
#endif
V_63 . V_62 = V_44 -> V_62 & V_25 -> V_72 ;
if ( F_16 ( V_25 , V_15 , V_57 -> V_42 ,
& V_63 , 0 , V_46 ,
V_47 , & V_60 ) < 0 )
return NULL ;
V_58 = F_25 ( & V_60 ) ;
if ( ! V_58 || ! F_26 ( V_58 , V_17 ) ) {
V_58 = F_30 ( & V_60 , V_17 -> V_50 , V_67 , V_59 ,
V_81 , V_17 , 0 ) ;
if ( ! V_58 ) {
F_29 ( V_60 . V_79 ) ;
return NULL ;
}
V_58 -> V_83 = V_25 -> V_83 ;
} else {
F_29 ( V_60 . V_79 ) ;
}
}
V_20 = ( ( V_25 -> V_20 & V_84 ) &&
V_57 -> V_42 == V_4 ) ? V_85 : 0 ;
F_17 ( V_25 -> V_19 , V_25 -> V_50 , V_57 -> V_42 ,
V_44 , V_45 , V_46 , V_47 , & V_60 ) ;
V_13 = F_30 ( & V_60 , V_17 -> V_50 , V_67 , V_59 , V_20 , V_17 , 0 ) ;
if ( ! V_13 ) {
if ( V_58 )
F_31 ( V_58 ) ;
return NULL ;
}
if ( V_58 ) {
F_32 ( V_13 , V_58 ) ;
F_31 ( V_58 ) ;
}
F_13 ( V_13 , V_25 ) ;
F_22 ( 6 , L_32
L_19 ,
F_38 ( V_13 ) ,
F_23 ( V_13 -> V_50 , & V_13 -> V_44 ) , F_24 ( V_13 -> V_45 ) ,
F_23 ( V_13 -> V_50 , & V_13 -> V_46 ) , F_24 ( V_13 -> V_47 ) ,
F_23 ( V_13 -> V_50 , & V_13 -> V_67 ) , F_24 ( V_13 -> V_59 ) ,
V_13 -> V_20 , F_39 ( & V_13 -> V_98 ) ) ;
F_96 ( 12 ) ;
return V_13 ;
}
static struct V_12 * F_97 ( unsigned int V_120 ,
struct V_18 * V_19 ,
int V_50 , struct V_14 * V_15 ,
const struct V_56 * V_57 )
{
struct V_16 * V_17 ;
struct V_12 * V_13 = NULL ;
T_1 V_87 [ 2 ] , * V_88 ;
if ( V_120 == V_121 )
return NULL ;
V_88 = F_34 ( V_15 , V_57 -> V_32 ,
sizeof( V_87 ) , V_87 , V_57 ) ;
if ( ! V_88 )
return NULL ;
F_9 () ;
V_17 = F_98 ( V_19 , V_50 , V_57 -> V_42 ,
& V_57 -> V_66 , V_88 [ 0 ] ) ;
if ( V_17 ) {
struct V_24 * V_25 ;
struct V_193 * V_51 ;
V_25 = F_10 ( V_17 -> V_25 ) ;
if ( V_25 ) {
V_51 = F_10 ( V_25 -> V_51 ) ;
if ( V_51 && V_51 -> V_194 )
V_13 = V_51 -> V_194 ( V_25 , V_17 , V_15 , V_57 ,
V_88 [ 0 ] , V_88 [ 1 ] ) ;
}
}
F_11 () ;
return V_13 ;
}
static unsigned int
F_99 ( int V_50 , struct V_14 * V_15 , struct V_38 * V_39 ,
struct V_12 * V_13 , struct V_56 * V_57 ,
unsigned int V_120 )
{
struct V_86 * V_40 = V_39 -> V_40 ;
F_35 ( 11 , V_50 , V_40 , V_15 , V_57 -> V_90 , L_33 ) ;
if ( ! F_78 ( V_15 , V_57 -> V_32 ) )
goto V_195;
if ( V_40 -> V_196 && ! V_40 -> V_196 ( V_15 , V_40 , V_13 , V_57 ) )
goto V_195;
#ifdef F_2
if ( V_50 == V_68 )
F_71 ( V_15 ) -> V_66 = V_13 -> V_46 . V_69 ;
else
#endif
{
F_62 ( V_15 ) -> V_66 = V_13 -> V_46 . V_62 ;
F_61 ( F_62 ( V_15 ) ) ;
}
if ( F_63 ( V_13 -> V_19 , V_50 , V_15 , V_120 ) )
goto V_195;
F_35 ( 10 , V_50 , V_40 , V_15 , V_57 -> V_90 , L_34 ) ;
F_12 ( V_13 , V_15 ) ;
F_14 ( V_13 , V_197 , V_15 , V_39 ) ;
V_15 -> V_157 = 1 ;
if ( ! ( V_13 -> V_20 & V_158 ) )
F_79 ( V_15 ) ;
else
F_80 ( V_15 , V_13 , 0 ) ;
F_31 ( V_13 ) ;
F_96 ( 11 ) ;
return V_112 ;
V_195:
F_31 ( V_13 ) ;
F_100 ( V_15 ) ;
F_96 ( 11 ) ;
return V_164 ;
}
static unsigned int
F_101 ( struct V_18 * V_19 , unsigned int V_120 , struct V_14 * V_15 , int V_50 )
{
struct V_56 V_57 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
struct V_12 * V_13 ;
struct V_198 * V_199 ;
F_95 ( 11 ) ;
if ( V_15 -> V_157 )
return V_112 ;
V_199 = F_102 ( V_15 ) ;
if ( F_46 ( V_199 && V_120 == V_200 &&
V_50 == V_144 ) ) {
if ( V_199 -> V_201 == V_202 && F_103 ( V_199 ) -> V_203 )
return V_112 ;
}
if ( F_46 ( ! F_64 ( V_15 ) ) )
return V_112 ;
if ( ! V_19 -> V_204 )
return V_112 ;
F_104 ( V_50 , V_15 , false , & V_57 ) ;
#ifdef F_2
if ( V_50 == V_68 ) {
if ( F_46 ( V_57 . V_42 == V_8 ) ) {
int V_159 ;
int V_154 = F_88 ( V_19 , V_15 , & V_159 ,
V_120 , & V_57 ) ;
if ( V_159 )
return V_154 ;
}
} else
#endif
if ( F_46 ( V_57 . V_42 == V_7 ) ) {
int V_159 ;
int V_154 = F_81 ( V_19 , V_15 , & V_159 , V_120 ) ;
if ( V_159 )
return V_154 ;
}
V_39 = F_105 ( V_19 , V_57 . V_42 ) ;
if ( F_46 ( ! V_39 ) )
return V_112 ;
V_40 = V_39 -> V_40 ;
#ifdef F_2
if ( V_50 == V_144 )
#endif
if ( F_46 ( F_82 ( F_62 ( V_15 ) ) && ! V_40 -> V_169 ) ) {
if ( F_57 ( V_19 , V_15 ,
F_56 ( V_120 ) ) )
return V_164 ;
F_104 ( V_144 , V_15 , false , & V_57 ) ;
}
V_13 = V_40 -> V_170 ( V_19 , V_50 , V_15 , & V_57 ) ;
if ( F_15 ( V_13 ) )
return F_99 ( V_50 , V_15 , V_39 , V_13 , & V_57 , V_120 ) ;
if ( F_39 ( & V_19 -> V_205 ) ) {
if ( V_40 -> V_42 == V_4 ) {
V_13 = F_97 ( V_120 , V_19 , V_50 , V_15 , & V_57 ) ;
if ( F_15 ( V_13 ) )
return F_99 ( V_50 , V_15 , V_39 , V_13 , & V_57 ,
V_120 ) ;
}
}
if ( F_51 ( V_19 ) &&
( V_40 -> V_42 == V_5 ||
V_40 -> V_42 == V_4 ||
V_40 -> V_42 == V_6 ) ) {
T_1 V_87 [ 2 ] , * V_88 ;
V_88 = F_34 ( V_15 , V_57 . V_32 ,
sizeof( V_87 ) , V_87 , & V_57 ) ;
if ( V_88 == NULL )
return V_112 ;
if ( F_106 ( V_19 , V_50 , V_57 . V_42 , & V_57 . V_66 ,
V_88 [ 0 ] ) ) {
if ( ( V_57 . V_42 != V_5 &&
V_57 . V_42 != V_6 )
|| ( ( V_57 . V_42 == V_5
&& ! F_91 ( V_15 , V_57 . V_32 ) )
|| ( V_57 . V_42 == V_6
&& ! F_90 ( V_15 ,
V_57 . V_32 ) ) ) ) {
#ifdef F_2
if ( V_50 == V_68 ) {
if ( ! V_15 -> V_91 )
V_15 -> V_91 = V_19 -> V_99 -> V_113 ;
F_48 ( V_15 ,
V_114 ,
V_115 ,
0 ) ;
} else
#endif
F_49 ( V_15 ,
V_116 ,
V_117 , 0 ) ;
return V_102 ;
}
}
}
F_35 ( 12 , V_50 , V_40 , V_15 , V_57 . V_90 ,
L_35 ) ;
return V_112 ;
}
static unsigned int
F_107 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_101 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_144 ) ;
}
static unsigned int
F_109 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_101 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_144 ) ;
}
static unsigned int
F_110 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_101 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_68 ) ;
}
static unsigned int
F_111 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_101 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_68 ) ;
}
static unsigned int
F_112 ( struct V_18 * V_19 , int V_50 , struct V_14 * V_15 ,
struct V_38 * V_39 ,
int * V_154 , struct V_12 * * V_209 ,
struct V_56 * V_57 )
{
struct V_86 * V_40 = V_39 -> V_40 ;
if ( ! V_57 -> V_148 ) {
if ( ! V_40 -> V_210 ( V_19 , V_50 , V_15 , V_39 , V_154 , V_209 , V_57 ) )
return 0 ;
}
if ( F_46 ( ! * V_209 ) ) {
F_35 ( 12 , V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_36 ) ;
if ( V_57 -> V_148 ) {
F_113 ( L_37 ) ;
F_35 ( 7 , V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_38 ) ;
}
* V_154 = V_112 ;
return 0 ;
}
return 1 ;
}
static int
F_114 ( struct V_18 * V_19 , struct V_14 * V_15 , int * V_159 ,
unsigned int V_120 )
{
struct V_134 * V_57 ;
struct V_137 V_160 , * V_161 ;
struct V_134 V_162 , * V_163 ;
struct V_56 V_139 ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
unsigned int V_118 , V_211 , V_136 , V_154 ;
bool V_212 , V_213 = false ;
* V_159 = 1 ;
if ( F_82 ( F_62 ( V_15 ) ) ) {
if ( F_57 ( V_19 , V_15 , F_56 ( V_120 ) ) )
return V_164 ;
}
V_57 = F_62 ( V_15 ) ;
V_118 = V_136 = V_57 -> V_136 * 4 ;
V_161 = F_83 ( V_15 , V_118 , sizeof( V_160 ) , & V_160 ) ;
if ( V_161 == NULL )
return V_102 ;
F_28 ( 12 , L_39 ,
V_161 -> type , F_24 ( F_84 ( V_161 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
if ( ( V_161 -> type != V_116 ) &&
( V_161 -> type != V_165 ) &&
( V_161 -> type != V_166 ) ) {
* V_159 = 0 ;
return V_112 ;
}
V_118 += sizeof( V_160 ) ;
V_163 = F_83 ( V_15 , V_118 , sizeof( V_162 ) , & V_162 ) ;
if ( V_163 == NULL )
return V_112 ;
V_212 = false ;
if ( V_163 -> V_42 == V_214 ) {
if ( F_46 ( V_163 -> V_167 & F_86 ( V_168 ) ) )
return V_112 ;
if ( ! ( F_66 ( V_15 ) -> V_130 & V_131 ) )
return V_112 ;
V_118 += V_163 -> V_136 * 4 ;
V_163 = F_83 ( V_15 , V_118 , sizeof( V_162 ) , & V_162 ) ;
if ( V_163 == NULL )
return V_112 ;
V_212 = true ;
}
V_39 = F_105 ( V_19 , V_163 -> V_42 ) ;
if ( ! V_39 )
return V_112 ;
V_40 = V_39 -> V_40 ;
if ( F_46 ( V_163 -> V_167 & F_86 ( V_168 ) &&
V_40 -> V_169 ) )
return V_112 ;
F_35 ( 11 , V_144 , V_40 , V_15 , V_118 ,
L_40 ) ;
V_211 = V_118 ;
F_87 ( V_144 , V_15 , V_118 , ! V_212 , & V_139 ) ;
V_118 = V_139 . V_32 ;
V_13 = V_40 -> V_95 ( V_19 , V_144 , V_15 , & V_139 ) ;
if ( ! V_13 ) {
int V_215 ;
if ( ! F_115 ( V_19 ) )
return V_112 ;
if ( ! F_112 ( V_19 , V_144 , V_15 , V_39 , & V_215 , & V_13 , & V_139 ) )
return V_215 ;
V_213 = true ;
}
V_154 = V_102 ;
if ( ! F_77 ( V_15 ) && F_53 ( V_15 , V_136 ) ) {
F_28 ( 1 , L_41 ,
& V_57 -> V_66 ) ;
goto V_155;
}
if ( V_212 ) {
T_6 V_216 = V_161 -> V_217 . V_218 ;
T_4 type = V_161 -> type ;
T_4 V_219 = V_161 -> V_219 ;
if ( V_161 -> type == V_116 &&
V_161 -> V_219 == V_220 ) {
struct V_16 * V_17 = V_13 -> V_17 ;
T_7 V_221 = F_24 ( V_161 -> V_217 . V_222 . V_221 ) ;
T_1 V_167 = V_163 -> V_167 ;
if ( F_116 ( V_15 , V_136 + sizeof( V_160 ) ) == NULL )
goto V_223;
V_211 -= V_136 + sizeof( V_160 ) ;
F_117 ( V_15 ) ;
F_28 ( 12 , L_42 ,
& F_62 ( V_15 ) -> V_66 , & F_62 ( V_15 ) -> V_67 , V_221 ) ;
F_118 ( V_15 , V_19 -> V_99 ,
V_221 , 0 , 0 , 0 , 0 ) ;
if ( ! ( V_167 & F_86 ( V_224 ) ) )
goto V_223;
if ( V_17 ) {
struct V_225 * V_226 ;
F_9 () ;
V_226 = F_10 ( V_17 -> V_226 ) ;
if ( V_226 )
V_221 = F_119 ( V_226 -> V_227 ) ;
F_11 () ;
}
if ( V_221 > 68 + sizeof( struct V_134 ) )
V_221 -= sizeof( struct V_134 ) ;
V_216 = F_19 ( V_221 ) ;
}
if ( F_116 ( V_15 , V_211 ) == NULL )
goto V_223;
F_117 ( V_15 ) ;
F_28 ( 12 , L_43 ,
& F_62 ( V_15 ) -> V_66 , & F_62 ( V_15 ) -> V_67 ,
type , V_219 , F_120 ( V_216 ) ) ;
F_49 ( V_15 , type , V_219 , V_216 ) ;
F_12 ( V_13 , V_15 ) ;
V_223:
F_121 ( V_15 ) ;
V_154 = V_164 ;
goto V_155;
}
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_163 -> V_42 || V_4 == V_163 -> V_42 ||
V_6 == V_163 -> V_42 )
V_118 += 2 * sizeof( V_156 ) ;
V_154 = F_122 ( V_15 , V_13 , V_40 , V_118 , V_120 , & V_139 ) ;
V_155:
if ( F_15 ( ! V_213 ) )
F_36 ( V_13 ) ;
else
F_31 ( V_13 ) ;
return V_154 ;
}
static int F_123 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_159 , unsigned int V_120 ,
struct V_56 * V_57 )
{
struct V_147 V_160 , * V_161 ;
struct V_56 V_139 = { . V_20 = 0 , . V_148 = 0 } ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
unsigned int V_118 , V_154 ;
bool V_213 = false ;
* V_159 = 1 ;
V_161 = F_34 ( V_15 , V_57 -> V_32 , sizeof( V_160 ) , & V_160 , V_57 ) ;
if ( V_161 == NULL )
return V_102 ;
if ( V_161 -> V_172 & V_173 ) {
* V_159 = 0 ;
return V_112 ;
}
if ( V_57 -> V_20 & V_174 )
return V_102 ;
F_28 ( 8 , L_44 ,
V_161 -> V_172 , F_24 ( F_89 ( V_161 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
V_118 = V_57 -> V_32 + sizeof( V_160 ) ;
if ( ! F_87 ( V_68 , V_15 , V_118 , true , & V_139 ) )
return V_112 ;
V_39 = F_105 ( V_19 , V_139 . V_42 ) ;
if ( ! V_39 )
return V_112 ;
V_40 = V_39 -> V_40 ;
if ( V_139 . V_148 )
return V_112 ;
F_35 ( 11 , V_68 , V_40 , V_15 , V_118 ,
L_45 ) ;
V_13 = V_40 -> V_95 ( V_19 , V_68 , V_15 , & V_139 ) ;
if ( ! V_13 ) {
int V_215 ;
if ( ! F_115 ( V_19 ) )
return V_112 ;
if ( ! F_112 ( V_19 , V_68 , V_15 , V_39 , & V_215 , & V_13 , & V_139 ) )
return V_215 ;
V_213 = true ;
}
if ( ( V_120 == V_200 ) &&
( F_76 ( V_13 ) != V_228 ) ) {
V_154 = V_112 ;
goto V_155;
}
F_5 ( V_13 , V_15 ) ;
V_118 = V_139 . V_32 ;
if ( V_5 == V_139 . V_42 || V_4 == V_139 . V_42 ||
V_6 == V_139 . V_42 )
V_118 += 2 * sizeof( V_156 ) ;
V_154 = F_124 ( V_15 , V_13 , V_40 , V_118 , V_120 , & V_139 ) ;
V_155:
if ( F_15 ( ! V_213 ) )
F_36 ( V_13 ) ;
else
F_31 ( V_13 ) ;
return V_154 ;
}
static unsigned int
F_125 ( struct V_18 * V_19 , unsigned int V_120 , struct V_14 * V_15 , int V_50 )
{
struct V_56 V_57 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
struct V_12 * V_13 ;
int V_104 , V_229 ;
int V_186 ;
struct V_198 * V_199 ;
if ( V_15 -> V_157 )
return V_112 ;
if ( F_46 ( ( V_15 -> V_230 != V_231 &&
V_120 != V_200 ) ||
! F_64 ( V_15 ) ) ) {
F_104 ( V_50 , V_15 , false , & V_57 ) ;
F_22 ( 12 , L_46
L_47 ,
V_15 -> V_230 , V_57 . V_42 ,
F_23 ( V_50 , & V_57 . V_67 ) , V_120 ) ;
return V_112 ;
}
if ( F_46 ( F_126 ( V_19 ) || ! V_19 -> V_204 ) )
return V_112 ;
F_104 ( V_50 , V_15 , false , & V_57 ) ;
V_199 = F_102 ( V_15 ) ;
if ( F_46 ( V_199 && V_120 == V_200 &&
V_50 == V_144 ) ) {
if ( V_199 -> V_201 == V_202 && F_103 ( V_199 ) -> V_203 )
return V_112 ;
}
#ifdef F_2
if ( V_50 == V_68 ) {
if ( F_46 ( V_57 . V_42 == V_8 ) ) {
int V_159 ;
int V_154 = F_123 ( V_19 , V_15 , & V_159 ,
V_120 , & V_57 ) ;
if ( V_159 )
return V_154 ;
}
} else
#endif
if ( F_46 ( V_57 . V_42 == V_7 ) ) {
int V_159 ;
int V_154 = F_114 ( V_19 , V_15 , & V_159 ,
V_120 ) ;
if ( V_159 )
return V_154 ;
}
V_39 = F_105 ( V_19 , V_57 . V_42 ) ;
if ( F_46 ( ! V_39 ) ) {
if ( F_127 ( V_19 ) )
V_15 -> V_157 = 1 ;
return V_112 ;
}
V_40 = V_39 -> V_40 ;
V_13 = V_40 -> V_95 ( V_19 , V_50 , V_15 , & V_57 ) ;
V_186 = F_128 ( V_19 ) ;
if ( V_186 && ! V_57 . V_148 && F_92 ( V_15 , & V_57 ) && V_13 ) {
bool V_232 = false , V_233 = false ;
if ( F_46 ( F_52 ( V_19 ) ) && V_13 -> V_17 &&
F_46 ( ! F_39 ( & V_13 -> V_17 -> V_234 ) ) ) {
V_233 = true ;
V_232 = F_129 ( V_13 , V_15 ) ;
} else if ( F_93 ( V_13 , V_186 ) ) {
V_232 = F_129 ( V_13 , V_15 ) ;
if ( ! F_39 ( & V_13 -> V_235 ) ) {
V_233 = true ;
} else {
V_233 = ! V_232 ;
}
}
if ( V_233 ) {
if ( ! F_39 ( & V_13 -> V_235 ) )
F_130 ( V_13 ) ;
F_36 ( V_13 ) ;
if ( V_232 )
return V_102 ;
V_13 = NULL ;
}
}
if ( F_46 ( ! V_13 ) ) {
int V_215 ;
if ( ! F_112 ( V_19 , V_50 , V_15 , V_39 , & V_215 , & V_13 , & V_57 ) )
return V_215 ;
}
F_35 ( 11 , V_50 , V_40 , V_15 , V_57 . V_90 , L_48 ) ;
if ( V_13 -> V_17 && ! ( V_13 -> V_17 -> V_20 & V_21 ) ) {
if ( F_52 ( V_19 ) ) {
F_130 ( V_13 ) ;
}
F_36 ( V_13 ) ;
return V_102 ;
}
F_5 ( V_13 , V_15 ) ;
F_14 ( V_13 , V_108 , V_15 , V_39 ) ;
if ( V_13 -> V_109 )
V_104 = V_13 -> V_109 ( V_15 , V_13 , V_40 , & V_57 ) ;
else {
F_113 ( L_49 ) ;
V_104 = V_112 ;
}
if ( V_13 -> V_20 & V_85 )
V_229 = F_131 ( V_19 ) ;
else
V_229 = F_132 ( 1 , & V_13 -> V_111 ) ;
if ( V_19 -> V_236 & V_237 )
F_133 ( V_19 , V_13 , V_229 ) ;
else if ( ( V_13 -> V_20 & V_85 ) && V_13 -> V_110 )
F_45 ( & V_13 -> V_110 -> V_111 ) ;
F_31 ( V_13 ) ;
return V_104 ;
}
static unsigned int
F_134 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_125 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_144 ) ;
}
static unsigned int
F_135 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_125 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_144 ) ;
}
static unsigned int
F_136 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_125 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_68 ) ;
}
static unsigned int
F_137 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
return F_125 ( F_108 ( V_187 -> V_99 ) , V_187 -> V_208 , V_15 , V_68 ) ;
}
static unsigned int
F_138 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
int V_238 ;
struct V_18 * V_19 = F_108 ( V_187 -> V_99 ) ;
if ( F_62 ( V_15 ) -> V_42 != V_7 )
return V_112 ;
if ( F_46 ( F_126 ( V_19 ) || ! V_19 -> V_204 ) )
return V_112 ;
return F_114 ( V_19 , V_15 , & V_238 , V_187 -> V_208 ) ;
}
static unsigned int
F_139 ( void * V_206 , struct V_14 * V_15 ,
const struct V_207 * V_187 )
{
int V_238 ;
struct V_18 * V_19 = F_108 ( V_187 -> V_99 ) ;
struct V_56 V_134 ;
F_104 ( V_68 , V_15 , false , & V_134 ) ;
if ( V_134 . V_42 != V_8 )
return V_112 ;
if ( F_46 ( F_126 ( V_19 ) || ! V_19 -> V_204 ) )
return V_112 ;
return F_123 ( V_19 , V_15 , & V_238 , V_187 -> V_208 , & V_134 ) ;
}
static int T_8 F_140 ( struct V_99 * V_99 )
{
struct V_18 * V_19 ;
V_19 = F_141 ( V_99 , V_239 ) ;
if ( V_19 == NULL )
return - V_240 ;
V_19 -> V_204 = 0 ;
V_19 -> V_99 = V_99 ;
V_19 -> V_241 = F_39 ( & V_242 ) ;
F_45 ( & V_242 ) ;
V_99 -> V_19 = V_19 ;
if ( F_142 ( V_19 ) < 0 )
goto V_243;
if ( F_143 ( V_19 ) < 0 )
goto V_244;
if ( F_144 ( V_19 ) < 0 )
goto V_245;
if ( F_145 ( V_19 ) < 0 )
goto V_246;
if ( F_146 ( V_19 ) < 0 )
goto V_247;
if ( F_147 ( V_19 ) < 0 )
goto V_248;
F_148 ( V_249 L_50 ,
sizeof( struct V_18 ) , V_19 -> V_241 ) ;
return 0 ;
V_248:
F_149 ( V_19 ) ;
V_247:
F_150 ( V_19 ) ;
V_246:
F_151 ( V_19 ) ;
V_245:
F_152 ( V_19 ) ;
V_244:
F_153 ( V_19 ) ;
V_243:
V_99 -> V_19 = NULL ;
return - V_240 ;
}
static void T_9 F_154 ( struct V_99 * V_99 )
{
struct V_18 * V_19 = F_108 ( V_99 ) ;
F_155 ( V_19 ) ;
F_149 ( V_19 ) ;
F_150 ( V_19 ) ;
F_151 ( V_19 ) ;
F_152 ( V_19 ) ;
F_153 ( V_19 ) ;
F_28 ( 2 , L_51 , V_19 -> V_241 ) ;
V_99 -> V_19 = NULL ;
}
static void T_9 F_156 ( struct V_99 * V_99 )
{
struct V_18 * V_19 = F_108 ( V_99 ) ;
F_95 ( 2 ) ;
V_19 -> V_204 = 0 ;
F_157 () ;
F_158 ( V_19 ) ;
F_96 ( 2 ) ;
}
static int T_10 F_159 ( void )
{
int V_104 ;
V_104 = F_160 () ;
if ( V_104 < 0 ) {
F_37 ( L_52 ) ;
goto exit;
}
F_161 () ;
V_104 = F_162 () ;
if ( V_104 < 0 ) {
F_37 ( L_53 ) ;
goto V_250;
}
V_104 = F_163 ( & V_251 ) ;
if ( V_104 < 0 )
goto V_252;
V_104 = F_164 ( & V_253 ) ;
if ( V_104 < 0 )
goto V_254;
V_104 = F_165 ( V_255 , F_166 ( V_255 ) ) ;
if ( V_104 < 0 ) {
F_37 ( L_54 ) ;
goto V_256;
}
V_104 = F_167 () ;
if ( V_104 < 0 ) {
F_37 ( L_55 ) ;
goto V_257;
}
F_168 ( L_56 ) ;
return V_104 ;
V_257:
F_169 ( V_255 , F_166 ( V_255 ) ) ;
V_256:
F_170 ( & V_253 ) ;
V_254:
F_171 ( & V_251 ) ;
V_252:
F_172 () ;
V_250:
F_173 () ;
F_174 () ;
exit:
return V_104 ;
}
static void T_11 F_175 ( void )
{
F_176 () ;
F_169 ( V_255 , F_166 ( V_255 ) ) ;
F_170 ( & V_253 ) ;
F_171 ( & V_251 ) ;
F_172 () ;
F_173 () ;
F_174 () ;
F_168 ( L_57 ) ;
}
