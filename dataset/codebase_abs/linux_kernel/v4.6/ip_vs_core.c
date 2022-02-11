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
if ( ! V_58 || ! F_26 ( V_58 ) ) {
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
F_45 ( & V_13 -> V_110 ) ;
F_31 ( V_13 ) ;
return V_104 ;
}
if ( V_25 -> V_73 == V_74 && V_59 != V_74 )
return V_111 ;
if ( F_46 ( F_47 ( V_57 ) ) )
return V_102 ;
#ifdef F_2
if ( V_25 -> V_50 == V_68 ) {
if ( ! V_15 -> V_91 )
V_15 -> V_91 = V_99 -> V_112 ;
F_48 ( V_15 , V_113 , V_114 , 0 ) ;
} else
#endif
F_49 ( V_15 , V_115 , V_116 , 0 ) ;
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
T_2 F_53 ( struct V_14 * V_15 , int V_117 )
{
return F_54 ( F_55 ( V_15 , V_117 , V_15 -> V_32 - V_117 , 0 ) ) ;
}
static inline enum V_118 F_56 ( unsigned int V_119 )
{
if ( V_120 == V_119 )
return V_121 ;
if ( V_122 == V_119 )
return V_123 ;
return V_124 ;
}
static inline int F_57 ( struct V_18 * V_19 ,
struct V_14 * V_15 , T_3 V_125 )
{
int V_126 ;
F_58 () ;
V_126 = F_59 ( V_19 -> V_99 , V_15 , V_125 ) ;
F_60 () ;
if ( ! V_126 )
F_61 ( F_62 ( V_15 ) ) ;
return V_126 ;
}
static int F_63 ( struct V_18 * V_19 , int V_50 ,
struct V_14 * V_15 , unsigned int V_119 )
{
if ( ! F_50 ( V_19 ) )
return 0 ;
if ( V_120 == V_119 )
return 0 ;
#ifdef F_2
if ( V_50 == V_68 ) {
struct V_127 * V_128 = F_64 ( V_15 ) ;
if ( V_128 -> V_91 && ! ( V_128 -> V_91 -> V_20 & V_92 ) &&
F_65 ( V_19 -> V_99 , V_15 ) != 0 )
return 1 ;
} else
#endif
if ( ! ( F_66 ( V_15 ) -> V_129 & V_130 ) &&
F_67 ( V_19 -> V_99 , V_15 , V_131 ) != 0 )
return 1 ;
return 0 ;
}
void F_68 ( struct V_14 * V_15 , struct V_86 * V_40 ,
struct V_12 * V_13 , int V_132 )
{
struct V_133 * V_57 = F_62 ( V_15 ) ;
unsigned int V_134 = V_57 -> V_135 * 4 ;
struct V_136 * V_137 = (struct V_136 * ) ( F_69 ( V_15 ) +
V_134 ) ;
struct V_133 * V_138 = (struct V_133 * ) ( V_137 + 1 ) ;
if ( V_132 ) {
V_57 -> V_66 = V_13 -> V_46 . V_62 ;
F_61 ( V_57 ) ;
V_138 -> V_67 = V_13 -> V_46 . V_62 ;
F_61 ( V_138 ) ;
} else {
V_57 -> V_67 = V_13 -> V_67 . V_62 ;
F_61 ( V_57 ) ;
V_138 -> V_66 = V_13 -> V_67 . V_62 ;
F_61 ( V_138 ) ;
}
if ( V_5 == V_138 -> V_42 || V_4 == V_138 -> V_42 ||
V_6 == V_138 -> V_42 ) {
T_1 * V_139 = ( void * ) V_138 + V_138 -> V_135 * 4 ;
if ( V_132 )
V_139 [ 1 ] = V_13 -> V_47 ;
else
V_139 [ 0 ] = V_13 -> V_59 ;
}
V_137 -> V_140 = 0 ;
V_137 -> V_140 = F_53 ( V_15 , V_134 ) ;
V_15 -> V_141 = V_142 ;
if ( V_132 )
F_35 ( 11 , V_143 , V_40 , V_15 , ( void * ) V_138 - ( void * ) V_57 ,
L_21 ) ;
else
F_35 ( 11 , V_143 , V_40 , V_15 , ( void * ) V_138 - ( void * ) V_57 ,
L_22 ) ;
}
void F_70 ( struct V_14 * V_15 , struct V_86 * V_40 ,
struct V_12 * V_13 , int V_132 )
{
struct V_144 * V_57 = F_71 ( V_15 ) ;
unsigned int V_134 = 0 ;
unsigned int V_145 = 0 ;
int V_42 ;
struct V_146 * V_137 ;
struct V_144 * V_138 ;
unsigned short V_147 ;
F_72 ( V_15 , & V_134 , V_8 , & V_147 , NULL ) ;
V_137 = (struct V_146 * ) ( F_69 ( V_15 ) + V_134 ) ;
V_145 = V_134 + sizeof( struct V_146 ) ;
V_138 = (struct V_144 * ) ( F_69 ( V_15 ) + V_145 ) ;
V_42 = F_72 ( V_15 , & V_145 , - 1 , & V_147 , NULL ) ;
if ( V_132 ) {
V_57 -> V_66 = V_13 -> V_46 . V_69 ;
V_138 -> V_67 = V_13 -> V_46 . V_69 ;
} else {
V_57 -> V_67 = V_13 -> V_67 . V_69 ;
V_138 -> V_66 = V_13 -> V_67 . V_69 ;
}
if ( ! V_147 && ( V_5 == V_42 || V_4 == V_42 ||
V_6 == V_42 ) ) {
T_1 * V_139 = ( void * ) ( F_69 ( V_15 ) + V_145 ) ;
F_28 ( 11 , L_23 , V_106 ,
F_24 ( V_132 ? V_139 [ 1 ] : V_139 [ 0 ] ) ,
F_24 ( V_132 ? V_13 -> V_47 : V_13 -> V_59 ) ) ;
if ( V_132 )
V_139 [ 1 ] = V_13 -> V_47 ;
else
V_139 [ 0 ] = V_13 -> V_59 ;
}
V_137 -> V_148 = ~ F_73 ( & V_57 -> V_66 , & V_57 -> V_67 ,
V_15 -> V_32 - V_134 ,
V_8 , 0 ) ;
V_15 -> V_149 = F_69 ( V_15 ) - V_15 -> V_150 + V_134 ;
V_15 -> V_151 = F_74 ( struct V_146 , V_148 ) ;
V_15 -> V_141 = V_152 ;
if ( V_132 )
F_35 ( 11 , V_68 , V_40 , V_15 ,
( void * ) V_138 - ( void * ) V_57 ,
L_24 ) ;
else
F_35 ( 11 , V_68 , V_40 , V_15 ,
( void * ) V_138 - ( void * ) V_57 ,
L_25 ) ;
}
static int F_75 ( int V_50 , struct V_14 * V_15 ,
union V_43 * V_63 ,
T_4 V_42 , struct V_12 * V_13 ,
struct V_86 * V_40 ,
unsigned int V_117 , unsigned int V_135 ,
unsigned int V_119 )
{
unsigned int V_153 = V_102 ;
if ( F_76 ( V_13 ) != 0 ) {
F_37 ( L_26
L_27 ) ;
}
if ( ! F_77 ( V_15 ) && F_53 ( V_15 , V_135 ) ) {
F_22 ( 1 , L_28 ,
F_23 ( V_50 , V_63 ) ) ;
goto V_154;
}
if ( V_5 == V_42 || V_4 == V_42 ||
V_6 == V_42 )
V_117 += 2 * sizeof( V_155 ) ;
if ( ! F_78 ( V_15 , V_117 ) )
goto V_154;
#ifdef F_2
if ( V_50 == V_68 )
F_70 ( V_15 , V_40 , V_13 , 1 ) ;
else
#endif
F_68 ( V_15 , V_40 , V_13 , 1 ) ;
if ( F_63 ( V_13 -> V_19 , V_50 , V_15 , V_119 ) )
goto V_154;
F_12 ( V_13 , V_15 ) ;
V_15 -> V_156 = 1 ;
if ( ! ( V_13 -> V_20 & V_157 ) )
F_79 ( V_15 ) ;
else
F_80 ( V_15 , V_13 , 0 ) ;
V_153 = V_111 ;
V_154:
F_36 ( V_13 ) ;
return V_153 ;
}
static int F_81 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_158 , unsigned int V_119 )
{
struct V_133 * V_57 ;
struct V_136 V_159 , * V_160 ;
struct V_133 V_161 , * V_162 ;
struct V_56 V_138 ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
unsigned int V_117 , V_135 ;
union V_43 V_63 ;
* V_158 = 1 ;
if ( F_82 ( F_62 ( V_15 ) ) ) {
if ( F_57 ( V_19 , V_15 , F_56 ( V_119 ) ) )
return V_163 ;
}
V_57 = F_62 ( V_15 ) ;
V_117 = V_135 = V_57 -> V_135 * 4 ;
V_160 = F_83 ( V_15 , V_117 , sizeof( V_159 ) , & V_159 ) ;
if ( V_160 == NULL )
return V_102 ;
F_28 ( 12 , L_29 ,
V_160 -> type , F_24 ( F_84 ( V_160 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
if ( ( V_160 -> type != V_115 ) &&
( V_160 -> type != V_164 ) &&
( V_160 -> type != V_165 ) ) {
* V_158 = 0 ;
return V_111 ;
}
V_117 += sizeof( V_159 ) ;
V_162 = F_83 ( V_15 , V_117 , sizeof( V_161 ) , & V_161 ) ;
if ( V_162 == NULL )
return V_111 ;
V_40 = F_85 ( V_162 -> V_42 ) ;
if ( ! V_40 )
return V_111 ;
if ( F_46 ( V_162 -> V_166 & F_86 ( V_167 ) &&
V_40 -> V_168 ) )
return V_111 ;
F_35 ( 11 , V_143 , V_40 , V_15 , V_117 ,
L_30 ) ;
F_87 ( V_143 , V_15 , V_117 , true , & V_138 ) ;
V_13 = V_40 -> V_169 ( V_19 , V_143 , V_15 , & V_138 ) ;
if ( ! V_13 )
return V_111 ;
V_63 . V_62 = V_57 -> V_66 ;
return F_75 ( V_143 , V_15 , & V_63 , V_162 -> V_42 , V_13 ,
V_40 , V_138 . V_32 , V_135 , V_119 ) ;
}
static int F_88 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_158 , unsigned int V_119 ,
struct V_56 * V_170 )
{
struct V_146 V_159 , * V_160 ;
struct V_56 V_138 = { . V_20 = 0 , . V_147 = 0 } ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
union V_43 V_63 ;
unsigned int V_117 ;
* V_158 = 1 ;
V_160 = F_34 ( V_15 , V_170 -> V_32 , sizeof( V_159 ) , & V_159 , V_170 ) ;
if ( V_160 == NULL )
return V_102 ;
if ( V_160 -> V_171 & V_172 ) {
* V_158 = 0 ;
return V_111 ;
}
if ( V_170 -> V_20 & V_173 )
return V_102 ;
F_28 ( 8 , L_31 ,
V_160 -> V_171 , F_24 ( F_89 ( V_160 ) ) ,
& V_170 -> V_66 , & V_170 -> V_67 ) ;
if ( ! F_87 ( V_68 , V_15 , V_170 -> V_32 + sizeof( V_159 ) ,
true , & V_138 ) )
return V_111 ;
V_40 = F_85 ( V_138 . V_42 ) ;
if ( ! V_40 )
return V_111 ;
V_13 = V_40 -> V_169 ( V_19 , V_68 , V_15 , & V_138 ) ;
if ( ! V_13 )
return V_111 ;
V_63 . V_69 = V_138 . V_66 . V_69 ;
V_117 = V_138 . V_32 ;
return F_75 ( V_68 , V_15 , & V_63 , V_138 . V_42 , V_13 ,
V_40 , V_117 , sizeof( struct V_144 ) ,
V_119 ) ;
}
static inline int F_90 ( const struct V_14 * V_15 , int V_174 )
{
T_5 * V_175 , V_176 ;
V_175 = F_83 ( V_15 , V_174 + sizeof( V_177 ) ,
sizeof( V_176 ) , & V_176 ) ;
if ( V_175 == NULL )
return 0 ;
if ( V_175 -> type == V_178 )
return 1 ;
return 0 ;
}
static inline int F_91 ( const struct V_14 * V_15 , int V_174 )
{
struct V_179 V_180 , * V_181 ;
V_181 = F_83 ( V_15 , V_174 , sizeof( V_180 ) , & V_180 ) ;
if ( V_181 == NULL )
return 0 ;
return V_181 -> V_182 ;
}
static inline bool F_92 ( const struct V_14 * V_15 ,
struct V_56 * V_57 )
{
switch ( V_57 -> V_42 ) {
case V_5 : {
struct V_179 V_180 , * V_181 ;
V_181 = F_83 ( V_15 , V_57 -> V_32 , sizeof( V_180 ) , & V_180 ) ;
if ( V_181 == NULL )
return false ;
return V_181 -> V_183 ;
}
case V_6 : {
T_5 * V_175 , V_176 ;
V_175 = F_83 ( V_15 , V_57 -> V_32 + sizeof( V_177 ) ,
sizeof( V_176 ) , & V_176 ) ;
if ( V_175 == NULL )
return false ;
return V_175 -> type == V_184 ;
}
default:
return false ;
}
}
static inline bool F_93 ( const struct V_12 * V_13 ,
int V_185 )
{
if ( V_13 -> V_186 )
return false ;
switch ( V_13 -> V_42 ) {
case V_5 :
return ( V_13 -> V_187 == V_188 ) ||
( V_13 -> V_187 == V_189 ) ||
( ( V_185 & 2 ) &&
( V_13 -> V_187 == V_190 ) &&
( V_13 -> V_20 & V_191 ) ) ;
case V_6 :
return V_13 -> V_187 == V_192 ;
default:
return false ;
}
}
static unsigned int
F_94 ( int V_50 , struct V_14 * V_15 , struct V_38 * V_39 ,
struct V_12 * V_13 , struct V_56 * V_57 ,
unsigned int V_119 )
{
struct V_86 * V_40 = V_39 -> V_40 ;
F_35 ( 11 , V_50 , V_40 , V_15 , V_57 -> V_90 , L_32 ) ;
if ( ! F_78 ( V_15 , V_57 -> V_32 ) )
goto V_193;
if ( V_40 -> V_194 && ! V_40 -> V_194 ( V_15 , V_40 , V_13 , V_57 ) )
goto V_193;
#ifdef F_2
if ( V_50 == V_68 )
F_71 ( V_15 ) -> V_66 = V_13 -> V_46 . V_69 ;
else
#endif
{
F_62 ( V_15 ) -> V_66 = V_13 -> V_46 . V_62 ;
F_61 ( F_62 ( V_15 ) ) ;
}
if ( F_63 ( V_13 -> V_19 , V_50 , V_15 , V_119 ) )
goto V_193;
F_35 ( 10 , V_50 , V_40 , V_15 , V_57 -> V_90 , L_33 ) ;
F_12 ( V_13 , V_15 ) ;
F_14 ( V_13 , V_195 , V_15 , V_39 ) ;
V_15 -> V_156 = 1 ;
if ( ! ( V_13 -> V_20 & V_157 ) )
F_79 ( V_15 ) ;
else
F_80 ( V_15 , V_13 , 0 ) ;
F_31 ( V_13 ) ;
F_95 ( 11 ) ;
return V_111 ;
V_193:
F_31 ( V_13 ) ;
F_96 ( V_15 ) ;
F_95 ( 11 ) ;
return V_163 ;
}
static unsigned int
F_97 ( struct V_18 * V_19 , unsigned int V_119 , struct V_14 * V_15 , int V_50 )
{
struct V_56 V_57 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
struct V_12 * V_13 ;
struct V_196 * V_197 ;
F_98 ( 11 ) ;
if ( V_15 -> V_156 )
return V_111 ;
V_197 = F_99 ( V_15 ) ;
if ( F_46 ( V_197 && V_119 == V_198 &&
V_50 == V_143 ) ) {
if ( V_197 -> V_199 == V_200 && F_100 ( V_197 ) -> V_201 )
return V_111 ;
}
if ( F_46 ( ! F_64 ( V_15 ) ) )
return V_111 ;
if ( ! V_19 -> V_202 )
return V_111 ;
F_101 ( V_50 , V_15 , false , & V_57 ) ;
#ifdef F_2
if ( V_50 == V_68 ) {
if ( F_46 ( V_57 . V_42 == V_8 ) ) {
int V_158 ;
int V_153 = F_88 ( V_19 , V_15 , & V_158 ,
V_119 , & V_57 ) ;
if ( V_158 )
return V_153 ;
}
} else
#endif
if ( F_46 ( V_57 . V_42 == V_7 ) ) {
int V_158 ;
int V_153 = F_81 ( V_19 , V_15 , & V_158 , V_119 ) ;
if ( V_158 )
return V_153 ;
}
V_39 = F_102 ( V_19 , V_57 . V_42 ) ;
if ( F_46 ( ! V_39 ) )
return V_111 ;
V_40 = V_39 -> V_40 ;
#ifdef F_2
if ( V_50 == V_143 )
#endif
if ( F_46 ( F_82 ( F_62 ( V_15 ) ) && ! V_40 -> V_168 ) ) {
if ( F_57 ( V_19 , V_15 ,
F_56 ( V_119 ) ) )
return V_163 ;
F_101 ( V_143 , V_15 , false , & V_57 ) ;
}
V_13 = V_40 -> V_169 ( V_19 , V_50 , V_15 , & V_57 ) ;
if ( F_15 ( V_13 ) )
return F_94 ( V_50 , V_15 , V_39 , V_13 , & V_57 , V_119 ) ;
if ( F_51 ( V_19 ) &&
( V_40 -> V_42 == V_5 ||
V_40 -> V_42 == V_4 ||
V_40 -> V_42 == V_6 ) ) {
T_1 V_87 [ 2 ] , * V_88 ;
V_88 = F_34 ( V_15 , V_57 . V_32 ,
sizeof( V_87 ) , V_87 , & V_57 ) ;
if ( V_88 == NULL )
return V_111 ;
if ( F_103 ( V_19 , V_50 , V_57 . V_42 , & V_57 . V_66 ,
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
V_15 -> V_91 = V_19 -> V_99 -> V_112 ;
F_48 ( V_15 ,
V_113 ,
V_114 ,
0 ) ;
} else
#endif
F_49 ( V_15 ,
V_115 ,
V_116 , 0 ) ;
return V_102 ;
}
}
}
F_35 ( 12 , V_50 , V_40 , V_15 , V_57 . V_90 ,
L_34 ) ;
return V_111 ;
}
static unsigned int
F_104 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_97 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_143 ) ;
}
static unsigned int
F_106 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_97 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_143 ) ;
}
static unsigned int
F_107 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_97 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_68 ) ;
}
static unsigned int
F_108 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_97 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_68 ) ;
}
static unsigned int
F_109 ( struct V_18 * V_19 , int V_50 , struct V_14 * V_15 ,
struct V_38 * V_39 ,
int * V_153 , struct V_12 * * V_206 ,
struct V_56 * V_57 )
{
struct V_86 * V_40 = V_39 -> V_40 ;
if ( ! V_57 -> V_147 ) {
if ( ! V_40 -> V_207 ( V_19 , V_50 , V_15 , V_39 , V_153 , V_206 , V_57 ) )
return 0 ;
}
if ( F_46 ( ! * V_206 ) ) {
F_35 ( 12 , V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_35 ) ;
if ( V_57 -> V_147 ) {
F_110 ( L_36 ) ;
F_35 ( 7 , V_50 , V_40 , V_15 , V_57 -> V_90 ,
L_37 ) ;
}
* V_153 = V_111 ;
return 0 ;
}
return 1 ;
}
static int
F_111 ( struct V_18 * V_19 , struct V_14 * V_15 , int * V_158 ,
unsigned int V_119 )
{
struct V_133 * V_57 ;
struct V_136 V_159 , * V_160 ;
struct V_133 V_161 , * V_162 ;
struct V_56 V_138 ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
unsigned int V_117 , V_208 , V_135 , V_153 ;
bool V_209 , V_210 = false ;
* V_158 = 1 ;
if ( F_82 ( F_62 ( V_15 ) ) ) {
if ( F_57 ( V_19 , V_15 , F_56 ( V_119 ) ) )
return V_163 ;
}
V_57 = F_62 ( V_15 ) ;
V_117 = V_135 = V_57 -> V_135 * 4 ;
V_160 = F_83 ( V_15 , V_117 , sizeof( V_159 ) , & V_159 ) ;
if ( V_160 == NULL )
return V_102 ;
F_28 ( 12 , L_38 ,
V_160 -> type , F_24 ( F_84 ( V_160 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
if ( ( V_160 -> type != V_115 ) &&
( V_160 -> type != V_164 ) &&
( V_160 -> type != V_165 ) ) {
* V_158 = 0 ;
return V_111 ;
}
V_117 += sizeof( V_159 ) ;
V_162 = F_83 ( V_15 , V_117 , sizeof( V_161 ) , & V_161 ) ;
if ( V_162 == NULL )
return V_111 ;
V_209 = false ;
if ( V_162 -> V_42 == V_211 ) {
if ( F_46 ( V_162 -> V_166 & F_86 ( V_167 ) ) )
return V_111 ;
if ( ! ( F_66 ( V_15 ) -> V_129 & V_130 ) )
return V_111 ;
V_117 += V_162 -> V_135 * 4 ;
V_162 = F_83 ( V_15 , V_117 , sizeof( V_161 ) , & V_161 ) ;
if ( V_162 == NULL )
return V_111 ;
V_209 = true ;
}
V_39 = F_102 ( V_19 , V_162 -> V_42 ) ;
if ( ! V_39 )
return V_111 ;
V_40 = V_39 -> V_40 ;
if ( F_46 ( V_162 -> V_166 & F_86 ( V_167 ) &&
V_40 -> V_168 ) )
return V_111 ;
F_35 ( 11 , V_143 , V_40 , V_15 , V_117 ,
L_39 ) ;
V_208 = V_117 ;
F_87 ( V_143 , V_15 , V_117 , ! V_209 , & V_138 ) ;
V_117 = V_138 . V_32 ;
V_13 = V_40 -> V_95 ( V_19 , V_143 , V_15 , & V_138 ) ;
if ( ! V_13 ) {
int V_212 ;
if ( ! F_112 ( V_19 ) )
return V_111 ;
if ( ! F_109 ( V_19 , V_143 , V_15 , V_39 , & V_212 , & V_13 , & V_138 ) )
return V_212 ;
V_210 = true ;
}
V_153 = V_102 ;
if ( ! F_77 ( V_15 ) && F_53 ( V_15 , V_135 ) ) {
F_28 ( 1 , L_40 ,
& V_57 -> V_66 ) ;
goto V_154;
}
if ( V_209 ) {
T_6 V_213 = V_160 -> V_214 . V_215 ;
T_4 type = V_160 -> type ;
T_4 V_216 = V_160 -> V_216 ;
if ( V_160 -> type == V_115 &&
V_160 -> V_216 == V_217 ) {
struct V_16 * V_17 = V_13 -> V_17 ;
T_7 V_218 = F_24 ( V_160 -> V_214 . V_219 . V_218 ) ;
T_1 V_166 = V_162 -> V_166 ;
if ( F_113 ( V_15 , V_135 + sizeof( V_159 ) ) == NULL )
goto V_220;
V_208 -= V_135 + sizeof( V_159 ) ;
F_114 ( V_15 ) ;
F_28 ( 12 , L_41 ,
& F_62 ( V_15 ) -> V_66 , & F_62 ( V_15 ) -> V_67 , V_218 ) ;
F_115 ( V_15 , V_19 -> V_99 ,
V_218 , 0 , 0 , 0 , 0 ) ;
if ( ! ( V_166 & F_86 ( V_221 ) ) )
goto V_220;
if ( V_17 ) {
struct V_222 * V_223 ;
F_9 () ;
V_223 = F_10 ( V_17 -> V_223 ) ;
if ( V_223 )
V_218 = F_116 ( V_223 -> V_224 ) ;
F_11 () ;
}
if ( V_218 > 68 + sizeof( struct V_133 ) )
V_218 -= sizeof( struct V_133 ) ;
V_213 = F_19 ( V_218 ) ;
}
if ( F_113 ( V_15 , V_208 ) == NULL )
goto V_220;
F_114 ( V_15 ) ;
F_28 ( 12 , L_42 ,
& F_62 ( V_15 ) -> V_66 , & F_62 ( V_15 ) -> V_67 ,
type , V_216 , F_117 ( V_213 ) ) ;
F_49 ( V_15 , type , V_216 , V_213 ) ;
F_12 ( V_13 , V_15 ) ;
V_220:
F_118 ( V_15 ) ;
V_153 = V_163 ;
goto V_154;
}
F_5 ( V_13 , V_15 ) ;
if ( V_5 == V_162 -> V_42 || V_4 == V_162 -> V_42 ||
V_6 == V_162 -> V_42 )
V_117 += 2 * sizeof( V_155 ) ;
V_153 = F_119 ( V_15 , V_13 , V_40 , V_117 , V_119 , & V_138 ) ;
V_154:
if ( F_15 ( ! V_210 ) )
F_36 ( V_13 ) ;
else
F_31 ( V_13 ) ;
return V_153 ;
}
static int F_120 ( struct V_18 * V_19 , struct V_14 * V_15 ,
int * V_158 , unsigned int V_119 ,
struct V_56 * V_57 )
{
struct V_146 V_159 , * V_160 ;
struct V_56 V_138 = { . V_20 = 0 , . V_147 = 0 } ;
struct V_12 * V_13 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
unsigned int V_117 , V_153 ;
bool V_210 = false ;
* V_158 = 1 ;
V_160 = F_34 ( V_15 , V_57 -> V_32 , sizeof( V_159 ) , & V_159 , V_57 ) ;
if ( V_160 == NULL )
return V_102 ;
if ( V_160 -> V_171 & V_172 ) {
* V_158 = 0 ;
return V_111 ;
}
if ( V_57 -> V_20 & V_173 )
return V_102 ;
F_28 ( 8 , L_43 ,
V_160 -> V_171 , F_24 ( F_89 ( V_160 ) ) ,
& V_57 -> V_66 , & V_57 -> V_67 ) ;
V_117 = V_57 -> V_32 + sizeof( V_159 ) ;
if ( ! F_87 ( V_68 , V_15 , V_117 , true , & V_138 ) )
return V_111 ;
V_39 = F_102 ( V_19 , V_138 . V_42 ) ;
if ( ! V_39 )
return V_111 ;
V_40 = V_39 -> V_40 ;
if ( V_138 . V_147 )
return V_111 ;
F_35 ( 11 , V_68 , V_40 , V_15 , V_117 ,
L_44 ) ;
V_13 = V_40 -> V_95 ( V_19 , V_68 , V_15 , & V_138 ) ;
if ( ! V_13 ) {
int V_212 ;
if ( ! F_112 ( V_19 ) )
return V_111 ;
if ( ! F_109 ( V_19 , V_68 , V_15 , V_39 , & V_212 , & V_13 , & V_138 ) )
return V_212 ;
V_210 = true ;
}
if ( ( V_119 == V_198 ) &&
( F_76 ( V_13 ) != V_225 ) ) {
V_153 = V_111 ;
goto V_154;
}
F_5 ( V_13 , V_15 ) ;
V_117 = V_138 . V_32 ;
if ( V_5 == V_138 . V_42 || V_4 == V_138 . V_42 ||
V_6 == V_138 . V_42 )
V_117 += 2 * sizeof( V_155 ) ;
V_153 = F_121 ( V_15 , V_13 , V_40 , V_117 , V_119 , & V_138 ) ;
V_154:
if ( F_15 ( ! V_210 ) )
F_36 ( V_13 ) ;
else
F_31 ( V_13 ) ;
return V_153 ;
}
static unsigned int
F_122 ( struct V_18 * V_19 , unsigned int V_119 , struct V_14 * V_15 , int V_50 )
{
struct V_56 V_57 ;
struct V_86 * V_40 ;
struct V_38 * V_39 ;
struct V_12 * V_13 ;
int V_104 , V_226 ;
int V_185 ;
struct V_196 * V_197 ;
if ( V_15 -> V_156 )
return V_111 ;
if ( F_46 ( ( V_15 -> V_227 != V_228 &&
V_119 != V_198 ) ||
! F_64 ( V_15 ) ) ) {
F_101 ( V_50 , V_15 , false , & V_57 ) ;
F_22 ( 12 , L_45
L_46 ,
V_15 -> V_227 , V_57 . V_42 ,
F_23 ( V_50 , & V_57 . V_67 ) , V_119 ) ;
return V_111 ;
}
if ( F_46 ( F_123 ( V_19 ) || ! V_19 -> V_202 ) )
return V_111 ;
F_101 ( V_50 , V_15 , false , & V_57 ) ;
V_197 = F_99 ( V_15 ) ;
if ( F_46 ( V_197 && V_119 == V_198 &&
V_50 == V_143 ) ) {
if ( V_197 -> V_199 == V_200 && F_100 ( V_197 ) -> V_201 )
return V_111 ;
}
#ifdef F_2
if ( V_50 == V_68 ) {
if ( F_46 ( V_57 . V_42 == V_8 ) ) {
int V_158 ;
int V_153 = F_120 ( V_19 , V_15 , & V_158 ,
V_119 , & V_57 ) ;
if ( V_158 )
return V_153 ;
}
} else
#endif
if ( F_46 ( V_57 . V_42 == V_7 ) ) {
int V_158 ;
int V_153 = F_111 ( V_19 , V_15 , & V_158 ,
V_119 ) ;
if ( V_158 )
return V_153 ;
}
V_39 = F_102 ( V_19 , V_57 . V_42 ) ;
if ( F_46 ( ! V_39 ) ) {
if ( F_124 ( V_19 ) )
V_15 -> V_156 = 1 ;
return V_111 ;
}
V_40 = V_39 -> V_40 ;
V_13 = V_40 -> V_95 ( V_19 , V_50 , V_15 , & V_57 ) ;
V_185 = F_125 ( V_19 ) ;
if ( V_185 && ! V_57 . V_147 && F_92 ( V_15 , & V_57 ) && V_13 ) {
bool V_229 = false , V_230 = false ;
if ( F_46 ( F_52 ( V_19 ) ) && V_13 -> V_17 &&
F_46 ( ! F_39 ( & V_13 -> V_17 -> V_231 ) ) ) {
V_230 = true ;
V_229 = F_126 ( V_13 , V_15 ) ;
} else if ( F_93 ( V_13 , V_185 ) ) {
V_229 = F_126 ( V_13 , V_15 ) ;
if ( ! F_39 ( & V_13 -> V_232 ) ) {
V_230 = true ;
} else {
V_230 = ! V_229 ;
}
}
if ( V_230 ) {
if ( ! F_39 ( & V_13 -> V_232 ) )
F_127 ( V_13 ) ;
F_36 ( V_13 ) ;
if ( V_229 )
return V_102 ;
V_13 = NULL ;
}
}
if ( F_46 ( ! V_13 ) ) {
int V_212 ;
if ( ! F_109 ( V_19 , V_50 , V_15 , V_39 , & V_212 , & V_13 , & V_57 ) )
return V_212 ;
}
F_35 ( 11 , V_50 , V_40 , V_15 , V_57 . V_90 , L_47 ) ;
if ( V_13 -> V_17 && ! ( V_13 -> V_17 -> V_20 & V_21 ) ) {
if ( F_52 ( V_19 ) ) {
F_127 ( V_13 ) ;
}
F_36 ( V_13 ) ;
return V_102 ;
}
F_5 ( V_13 , V_15 ) ;
F_14 ( V_13 , V_108 , V_15 , V_39 ) ;
if ( V_13 -> V_109 )
V_104 = V_13 -> V_109 ( V_15 , V_13 , V_40 , & V_57 ) ;
else {
F_110 ( L_48 ) ;
V_104 = V_111 ;
}
if ( V_13 -> V_20 & V_85 )
V_226 = F_128 ( V_19 ) ;
else
V_226 = F_129 ( 1 , & V_13 -> V_110 ) ;
if ( V_19 -> V_233 & V_234 )
F_130 ( V_19 , V_13 , V_226 ) ;
F_31 ( V_13 ) ;
return V_104 ;
}
static unsigned int
F_131 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_122 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_143 ) ;
}
static unsigned int
F_132 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_122 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_143 ) ;
}
static unsigned int
F_133 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_122 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_68 ) ;
}
static unsigned int
F_134 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
return F_122 ( F_105 ( V_187 -> V_99 ) , V_187 -> V_205 , V_15 , V_68 ) ;
}
static unsigned int
F_135 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
int V_235 ;
struct V_18 * V_19 = F_105 ( V_187 -> V_99 ) ;
if ( F_62 ( V_15 ) -> V_42 != V_7 )
return V_111 ;
if ( F_46 ( F_123 ( V_19 ) || ! V_19 -> V_202 ) )
return V_111 ;
return F_111 ( V_19 , V_15 , & V_235 , V_187 -> V_205 ) ;
}
static unsigned int
F_136 ( void * V_203 , struct V_14 * V_15 ,
const struct V_204 * V_187 )
{
int V_235 ;
struct V_18 * V_19 = F_105 ( V_187 -> V_99 ) ;
struct V_56 V_133 ;
F_101 ( V_68 , V_15 , false , & V_133 ) ;
if ( V_133 . V_42 != V_8 )
return V_111 ;
if ( F_46 ( F_123 ( V_19 ) || ! V_19 -> V_202 ) )
return V_111 ;
return F_120 ( V_19 , V_15 , & V_235 , V_187 -> V_205 , & V_133 ) ;
}
static int T_8 F_137 ( struct V_99 * V_99 )
{
struct V_18 * V_19 ;
V_19 = F_138 ( V_99 , V_236 ) ;
if ( V_19 == NULL )
return - V_237 ;
V_19 -> V_202 = 0 ;
V_19 -> V_99 = V_99 ;
V_19 -> V_238 = F_39 ( & V_239 ) ;
F_45 ( & V_239 ) ;
V_99 -> V_19 = V_19 ;
if ( F_139 ( V_19 ) < 0 )
goto V_240;
if ( F_140 ( V_19 ) < 0 )
goto V_241;
if ( F_141 ( V_19 ) < 0 )
goto V_242;
if ( F_142 ( V_19 ) < 0 )
goto V_243;
if ( F_143 ( V_19 ) < 0 )
goto V_244;
if ( F_144 ( V_19 ) < 0 )
goto V_245;
F_145 ( V_246 L_49 ,
sizeof( struct V_18 ) , V_19 -> V_238 ) ;
return 0 ;
V_245:
F_146 ( V_19 ) ;
V_244:
F_147 ( V_19 ) ;
V_243:
F_148 ( V_19 ) ;
V_242:
F_149 ( V_19 ) ;
V_241:
F_150 ( V_19 ) ;
V_240:
V_99 -> V_19 = NULL ;
return - V_237 ;
}
static void T_9 F_151 ( struct V_99 * V_99 )
{
struct V_18 * V_19 = F_105 ( V_99 ) ;
F_152 ( V_19 ) ;
F_146 ( V_19 ) ;
F_147 ( V_19 ) ;
F_148 ( V_19 ) ;
F_149 ( V_19 ) ;
F_150 ( V_19 ) ;
F_28 ( 2 , L_50 , V_19 -> V_238 ) ;
V_99 -> V_19 = NULL ;
}
static void T_9 F_153 ( struct V_99 * V_99 )
{
struct V_18 * V_19 = F_105 ( V_99 ) ;
F_98 ( 2 ) ;
V_19 -> V_202 = 0 ;
F_154 () ;
F_155 ( V_19 ) ;
F_95 ( 2 ) ;
}
static int T_10 F_156 ( void )
{
int V_104 ;
V_104 = F_157 () ;
if ( V_104 < 0 ) {
F_37 ( L_51 ) ;
goto exit;
}
F_158 () ;
V_104 = F_159 () ;
if ( V_104 < 0 ) {
F_37 ( L_52 ) ;
goto V_247;
}
V_104 = F_160 ( & V_248 ) ;
if ( V_104 < 0 )
goto V_249;
V_104 = F_161 ( & V_250 ) ;
if ( V_104 < 0 )
goto V_251;
V_104 = F_162 ( V_252 , F_163 ( V_252 ) ) ;
if ( V_104 < 0 ) {
F_37 ( L_53 ) ;
goto V_253;
}
V_104 = F_164 () ;
if ( V_104 < 0 ) {
F_37 ( L_54 ) ;
goto V_254;
}
F_165 ( L_55 ) ;
return V_104 ;
V_254:
F_166 ( V_252 , F_163 ( V_252 ) ) ;
V_253:
F_167 ( & V_250 ) ;
V_251:
F_168 ( & V_248 ) ;
V_249:
F_169 () ;
V_247:
F_170 () ;
F_171 () ;
exit:
return V_104 ;
}
static void T_11 F_172 ( void )
{
F_173 () ;
F_166 ( V_252 , F_163 ( V_252 ) ) ;
F_167 ( & V_250 ) ;
F_168 ( & V_248 ) ;
F_169 () ;
F_170 () ;
F_171 () ;
F_165 ( L_56 ) ;
}
