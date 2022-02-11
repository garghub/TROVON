static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_9 V_10 = { 0 } ;
int V_11 ;
F_5 (i) {
const struct V_9 * V_12 = F_6 ( V_8 -> V_12 , V_11 ) ;
V_10 . V_13 += V_12 -> V_13 ;
V_10 . V_14 += V_12 -> V_14 ;
V_10 . V_15 += V_12 -> V_15 ;
V_10 . V_16 += V_12 -> V_16 ;
}
V_8 -> V_17 . V_13 = V_10 . V_13 ;
V_8 -> V_17 . V_14 = V_10 . V_14 ;
V_8 -> V_17 . V_15 = V_10 . V_15 ;
V_8 -> V_17 . V_16 = V_10 . V_16 ;
return & V_8 -> V_17 ;
}
static inline struct V_18 * F_7 ( struct V_19 * V_20 )
{
struct V_18 * V_21 = V_20 -> V_22 ;
if ( V_21 && V_21 -> V_23 &&
V_21 -> V_24 -> V_25 ( V_21 , V_20 -> V_26 ) == NULL ) {
V_20 -> V_22 = NULL ;
F_8 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
static inline void F_9 ( struct V_19 * V_20 )
{
F_8 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
}
static inline void F_10 ( struct V_19 * V_20 , struct V_18 * V_21 )
{
struct V_27 * V_28 = (struct V_27 * ) V_21 ;
V_20 -> V_26 = V_28 -> V_29 ? V_28 -> V_29 -> V_30 : 0 ;
F_8 ( V_20 -> V_22 ) ;
V_20 -> V_22 = V_21 ;
}
static struct V_19 *
F_11 ( struct V_31 * V_31 , const struct V_1 * V_32 , const struct V_1 * V_33 )
{
unsigned int V_4 = F_1 ( V_32 , V_33 ) ;
struct V_19 * V_20 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
F_13 (ip6n->tnls_r_l[hash]) {
if ( F_14 ( V_33 , & V_20 -> V_37 . V_38 ) &&
F_14 ( V_32 , & V_20 -> V_37 . V_39 ) &&
( V_20 -> V_8 -> V_40 & V_41 ) )
return V_20 ;
}
V_20 = F_15 ( V_35 -> V_42 [ 0 ] ) ;
if ( V_20 && ( V_20 -> V_8 -> V_40 & V_41 ) )
return V_20 ;
return NULL ;
}
static struct V_19 T_2 * *
F_16 ( struct V_34 * V_35 , const struct V_43 * V_44 )
{
const struct V_1 * V_32 = & V_44 -> V_39 ;
const struct V_1 * V_33 = & V_44 -> V_38 ;
unsigned int V_45 = 0 ;
int V_46 = 0 ;
if ( ! F_17 ( V_32 ) || ! F_17 ( V_33 ) ) {
V_46 = 1 ;
V_45 = F_1 ( V_32 , V_33 ) ;
}
return & V_35 -> V_47 [ V_46 ] [ V_45 ] ;
}
static void
F_18 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_19 T_2 * * V_48 = F_16 ( V_35 , & V_20 -> V_37 ) ;
F_19 ( V_20 -> V_49 , F_20 ( * V_48 ) ) ;
F_19 ( * V_48 , V_20 ) ;
}
static void
F_21 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_19 T_2 * * V_48 ;
struct V_19 * V_50 ;
for ( V_48 = F_16 ( V_35 , & V_20 -> V_37 ) ;
( V_50 = F_20 ( * V_48 ) ) != NULL ;
V_48 = & V_50 -> V_49 ) {
if ( V_20 == V_50 ) {
F_19 ( * V_48 , V_20 -> V_49 ) ;
break;
}
}
}
static void F_22 ( struct V_7 * V_8 )
{
F_23 ( V_8 -> V_12 ) ;
F_24 ( V_8 ) ;
}
static struct V_19 * F_25 ( struct V_31 * V_31 , struct V_43 * V_44 )
{
struct V_7 * V_8 ;
struct V_19 * V_20 ;
char V_51 [ V_52 ] ;
int V_53 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
if ( V_44 -> V_51 [ 0 ] )
F_26 ( V_51 , V_44 -> V_51 , V_52 ) ;
else
sprintf ( V_51 , L_1 ) ;
V_8 = F_27 ( sizeof ( * V_20 ) , V_51 , V_54 ) ;
if ( V_8 == NULL )
goto V_55;
F_28 ( V_8 , V_31 ) ;
V_20 = F_29 ( V_8 ) ;
V_20 -> V_37 = * V_44 ;
V_53 = F_30 ( V_8 ) ;
if ( V_53 < 0 )
goto V_56;
if ( ( V_53 = F_31 ( V_8 ) ) < 0 )
goto V_56;
strcpy ( V_20 -> V_37 . V_51 , V_8 -> V_51 ) ;
F_32 ( V_8 ) ;
F_18 ( V_35 , V_20 ) ;
return V_20 ;
V_56:
F_22 ( V_8 ) ;
V_55:
return NULL ;
}
static struct V_19 * F_33 ( struct V_31 * V_31 ,
struct V_43 * V_44 , int V_57 )
{
const struct V_1 * V_32 = & V_44 -> V_39 ;
const struct V_1 * V_33 = & V_44 -> V_38 ;
struct V_19 T_2 * * V_48 ;
struct V_19 * V_20 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
for ( V_48 = F_16 ( V_35 , V_44 ) ;
( V_20 = F_20 ( * V_48 ) ) != NULL ;
V_48 = & V_20 -> V_49 ) {
if ( F_14 ( V_33 , & V_20 -> V_37 . V_38 ) &&
F_14 ( V_32 , & V_20 -> V_37 . V_39 ) )
return V_20 ;
}
if ( ! V_57 )
return NULL ;
return F_25 ( V_31 , V_44 ) ;
}
static void
F_34 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
struct V_31 * V_31 = F_35 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
if ( V_8 == V_35 -> V_58 )
F_36 ( V_35 -> V_42 [ 0 ] , NULL ) ;
else
F_21 ( V_35 , V_20 ) ;
F_9 ( V_20 ) ;
F_37 ( V_8 ) ;
}
static T_3
F_38 ( struct V_59 * V_60 , T_4 * V_61 )
{
const struct V_62 * V_63 = ( const struct V_62 * ) V_61 ;
T_4 V_64 = V_63 -> V_64 ;
T_3 V_65 = sizeof ( * V_63 ) ;
while ( F_39 ( V_64 ) && V_64 != V_66 ) {
T_3 V_67 = 0 ;
struct V_68 * V_69 ;
if ( V_61 + V_65 + sizeof ( * V_69 ) > V_60 -> V_70 &&
! F_40 ( V_60 , V_61 - V_60 -> V_70 + V_65 + sizeof ( * V_69 ) ) )
break;
V_69 = (struct V_68 * ) ( V_61 + V_65 ) ;
if ( V_64 == V_71 ) {
struct V_72 * V_72 = (struct V_72 * ) V_69 ;
if ( V_72 -> V_73 )
break;
V_67 = 8 ;
} else if ( V_64 == V_74 ) {
V_67 = ( V_69 -> V_75 + 2 ) << 2 ;
} else {
V_67 = F_41 ( V_69 ) ;
}
if ( V_64 == V_76 ) {
T_3 V_11 = V_65 + 2 ;
while ( 1 ) {
struct V_77 * V_78 ;
if ( V_11 + sizeof ( * V_78 ) > V_65 + V_67 )
break;
V_78 = (struct V_77 * ) & V_61 [ V_11 ] ;
if ( V_78 -> type == V_79 &&
V_78 -> V_80 == 1 )
return V_11 ;
if ( V_78 -> type )
V_11 += V_78 -> V_80 + 2 ;
else
V_11 ++ ;
}
}
V_64 = V_69 -> V_64 ;
V_65 += V_67 ;
}
return 0 ;
}
static int
F_42 ( struct V_59 * V_60 , T_4 V_81 , struct V_82 * V_83 ,
T_5 * type , T_5 * V_84 , int * V_85 , T_6 * V_86 , int V_87 )
{
const struct V_62 * V_63 = ( const struct V_62 * ) V_60 -> V_70 ;
struct V_19 * V_20 ;
int V_88 = 0 ;
T_5 V_89 = V_90 ;
T_5 V_91 = V_92 ;
T_6 V_93 = 0 ;
T_3 V_94 ;
int V_53 = - V_95 ;
F_43 () ;
if ( ( V_20 = F_11 ( F_35 ( V_60 -> V_8 ) , & V_63 -> V_96 ,
& V_63 -> V_97 ) ) == NULL )
goto V_98;
if ( V_20 -> V_37 . V_99 != V_81 && V_20 -> V_37 . V_99 != 0 )
goto V_98;
V_53 = 0 ;
switch ( * type ) {
T_6 V_100 ;
struct V_77 * V_78 ;
T_6 V_101 ;
case V_90 :
F_44 ( L_2 ,
V_20 -> V_37 . V_51 ) ;
V_88 = 1 ;
break;
case V_102 :
if ( ( * V_84 ) == V_103 ) {
F_44 ( L_3 ,
V_20 -> V_37 . V_51 ) ;
V_88 = 1 ;
}
break;
case V_104 :
V_100 = 0 ;
if ( ( * V_84 ) == V_105 )
V_100 = F_38 ( V_60 , V_60 -> V_70 ) ;
if ( V_100 && V_100 == * V_86 - 2 ) {
V_78 = (struct V_77 * ) & V_60 -> V_70 [ V_100 ] ;
if ( V_78 -> V_106 == 0 ) {
F_44 ( L_4 ,
V_20 -> V_37 . V_51 ) ;
V_88 = 1 ;
}
} else {
F_44 ( L_5 ,
V_20 -> V_37 . V_51 ) ;
}
break;
case V_107 :
V_101 = * V_86 - V_87 ;
if ( V_101 < V_108 )
V_101 = V_108 ;
V_20 -> V_8 -> V_101 = V_101 ;
if ( ( V_94 = sizeof ( * V_63 ) + F_45 ( V_63 -> V_109 ) ) > V_101 ) {
V_89 = V_107 ;
V_91 = 0 ;
V_93 = V_101 ;
V_88 = 1 ;
}
break;
}
* type = V_89 ;
* V_84 = V_91 ;
* V_86 = V_93 ;
* V_85 = V_88 ;
V_98:
F_46 () ;
return V_53 ;
}
static int
F_47 ( struct V_59 * V_60 , struct V_82 * V_83 ,
T_5 type , T_5 V_84 , int V_87 , T_7 V_86 )
{
int V_88 = 0 ;
T_5 V_89 = type ;
T_5 V_91 = V_84 ;
T_6 V_93 = F_48 ( V_86 ) ;
int V_53 ;
struct V_59 * V_110 ;
const struct V_111 * V_112 ;
struct V_113 * V_28 ;
struct V_114 V_115 ;
V_53 = F_42 ( V_60 , V_116 , V_83 , & V_89 , & V_91 ,
& V_88 , & V_93 , V_87 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_88 == 0 )
return 0 ;
switch ( V_89 ) {
case V_90 :
if ( V_91 != V_92 )
return 0 ;
V_89 = V_117 ;
V_91 = V_118 ;
break;
case V_107 :
if ( V_91 != 0 )
return 0 ;
V_89 = V_117 ;
V_91 = V_119 ;
break;
case V_120 :
V_89 = V_121 ;
V_91 = V_122 ;
default:
return 0 ;
}
if ( ! F_40 ( V_60 , V_87 + sizeof( struct V_111 ) ) )
return 0 ;
V_110 = F_49 ( V_60 , V_123 ) ;
if ( ! V_110 )
return 0 ;
F_50 ( V_110 ) ;
F_51 ( V_110 , V_87 ) ;
F_52 ( V_110 ) ;
V_112 = F_53 ( V_110 ) ;
V_28 = F_54 ( F_35 ( V_60 -> V_8 ) , & V_115 , NULL ,
V_112 -> V_97 , 0 ,
0 , 0 ,
V_116 , F_55 ( V_112 -> V_124 ) , 0 ) ;
if ( F_56 ( V_28 ) )
goto V_98;
V_110 -> V_8 = V_28 -> V_21 . V_8 ;
if ( V_28 -> V_125 & V_126 ) {
F_57 ( V_28 ) ;
V_28 = NULL ;
V_28 = F_54 ( F_35 ( V_60 -> V_8 ) , & V_115 , NULL ,
V_112 -> V_96 , V_112 -> V_97 ,
0 , 0 ,
V_116 ,
F_55 ( V_112 -> V_124 ) , 0 ) ;
if ( F_56 ( V_28 ) ||
V_28 -> V_21 . V_8 -> type != V_127 ) {
if ( ! F_56 ( V_28 ) )
F_57 ( V_28 ) ;
goto V_98;
}
F_58 ( V_110 , & V_28 -> V_21 ) ;
} else {
F_57 ( V_28 ) ;
if ( F_59 ( V_110 , V_112 -> V_96 , V_112 -> V_97 , V_112 -> V_124 ,
V_110 -> V_8 ) ||
F_60 ( V_110 ) -> V_8 -> type != V_127 )
goto V_98;
}
if ( V_89 == V_117 && V_91 == V_119 ) {
if ( V_93 > F_61 ( F_60 ( V_110 ) ) )
goto V_98;
F_60 ( V_110 ) -> V_24 -> V_128 ( F_60 ( V_110 ) , NULL , V_110 , V_93 ) ;
}
if ( V_89 == V_121 )
F_60 ( V_110 ) -> V_24 -> V_129 ( F_60 ( V_110 ) , NULL , V_110 ) ;
F_62 ( V_110 , V_89 , V_91 , F_63 ( V_93 ) ) ;
V_98:
F_64 ( V_110 ) ;
return 0 ;
}
static int
F_65 ( struct V_59 * V_60 , struct V_82 * V_83 ,
T_5 type , T_5 V_84 , int V_87 , T_7 V_86 )
{
int V_88 = 0 ;
T_5 V_89 = type ;
T_5 V_91 = V_84 ;
T_6 V_93 = F_48 ( V_86 ) ;
int V_53 ;
V_53 = F_42 ( V_60 , V_130 , V_83 , & V_89 , & V_91 ,
& V_88 , & V_93 , V_87 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_88 && F_40 ( V_60 , V_87 + sizeof( struct V_62 ) ) ) {
struct V_27 * V_28 ;
struct V_59 * V_110 = F_49 ( V_60 , V_123 ) ;
if ( ! V_110 )
return 0 ;
F_50 ( V_110 ) ;
F_51 ( V_110 , V_87 ) ;
F_52 ( V_110 ) ;
V_28 = F_66 ( F_35 ( V_60 -> V_8 ) , & F_67 ( V_110 ) -> V_97 ,
NULL , 0 , 0 ) ;
if ( V_28 && V_28 -> V_21 . V_8 )
V_110 -> V_8 = V_28 -> V_21 . V_8 ;
F_68 ( V_110 , V_89 , V_91 , V_93 ) ;
if ( V_28 )
F_8 ( & V_28 -> V_21 ) ;
F_64 ( V_110 ) ;
}
return 0 ;
}
static void F_69 ( const struct V_19 * V_20 ,
const struct V_62 * V_63 ,
struct V_59 * V_60 )
{
T_4 V_131 = F_70 ( V_63 ) & ~ V_132 ;
if ( V_20 -> V_37 . V_40 & V_133 )
F_71 ( F_53 ( V_60 ) , V_132 , V_131 ) ;
if ( F_72 ( V_131 ) )
F_73 ( F_53 ( V_60 ) ) ;
}
static void F_74 ( const struct V_19 * V_20 ,
const struct V_62 * V_63 ,
struct V_59 * V_60 )
{
if ( V_20 -> V_37 . V_40 & V_133 )
F_75 ( F_70 ( V_63 ) , F_67 ( V_60 ) ) ;
if ( F_72 ( F_70 ( V_63 ) ) )
F_76 ( F_67 ( V_60 ) ) ;
}
static T_6 F_77 ( struct V_19 * V_20 ,
const struct V_1 * V_38 ,
const struct V_1 * V_39 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_134 = F_78 ( V_38 ) ;
int V_135 = F_78 ( V_39 ) ;
T_6 V_40 = 0 ;
if ( V_134 == V_136 || V_135 == V_136 ) {
V_40 = V_137 ;
} else if ( V_134 & ( V_138 | V_139 ) &&
V_135 & ( V_138 | V_139 ) &&
! ( ( V_134 | V_135 ) & V_140 ) &&
( ! ( ( V_134 | V_135 ) & V_141 ) || V_44 -> V_142 ) ) {
if ( V_134 & V_138 )
V_40 |= V_143 ;
if ( V_135 & V_138 )
V_40 |= V_144 ;
}
return V_40 ;
}
static inline int F_79 ( struct V_19 * V_20 ,
const struct V_1 * V_38 ,
const struct V_1 * V_39 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_145 = 0 ;
struct V_31 * V_31 = F_35 ( V_20 -> V_8 ) ;
if ( ( V_44 -> V_40 & V_144 ) ||
( ( V_44 -> V_40 & V_137 ) &&
( F_77 ( V_20 , V_38 , V_39 ) & V_144 ) ) ) {
struct V_7 * V_146 = NULL ;
if ( V_44 -> V_142 )
V_146 = F_80 ( V_31 , V_44 -> V_142 ) ;
if ( ( F_81 ( V_38 ) ||
F_82 ( F_83 ( V_31 , V_38 , V_146 , 0 ) ) ) &&
F_82 ( ! F_83 ( V_31 , V_39 , NULL , 0 ) ) )
V_145 = 1 ;
}
return V_145 ;
}
static int F_84 ( struct V_59 * V_60 , T_3 V_147 ,
T_4 V_81 ,
void (* F_85)( const struct V_19 * V_20 ,
const struct V_62 * V_63 ,
struct V_59 * V_60 ) )
{
struct V_19 * V_20 ;
const struct V_62 * V_63 = F_67 ( V_60 ) ;
F_43 () ;
if ( ( V_20 = F_11 ( F_35 ( V_60 -> V_8 ) , & V_63 -> V_97 ,
& V_63 -> V_96 ) ) != NULL ) {
struct V_9 * V_12 ;
if ( V_20 -> V_37 . V_99 != V_81 && V_20 -> V_37 . V_99 != 0 ) {
F_46 () ;
goto V_148;
}
if ( ! F_86 ( NULL , V_149 , V_60 ) ) {
F_46 () ;
goto V_148;
}
if ( ! F_79 ( V_20 , & V_63 -> V_96 , & V_63 -> V_97 ) ) {
V_20 -> V_8 -> V_17 . V_150 ++ ;
F_46 () ;
goto V_148;
}
F_87 ( V_60 ) ;
V_60 -> V_151 = V_60 -> V_152 ;
F_52 ( V_60 ) ;
V_60 -> V_147 = F_88 ( V_147 ) ;
V_60 -> V_153 = V_154 ;
memset ( V_60 -> V_155 , 0 , sizeof( struct V_82 ) ) ;
V_12 = F_89 ( V_20 -> V_8 -> V_12 ) ;
V_12 -> V_13 ++ ;
V_12 -> V_14 += V_60 -> V_94 ;
F_90 ( V_60 , V_20 -> V_8 ) ;
F_85 ( V_20 , V_63 , V_60 ) ;
F_91 ( V_60 ) ;
F_46 () ;
return 0 ;
}
F_46 () ;
return 1 ;
V_148:
F_64 ( V_60 ) ;
return 0 ;
}
static int F_92 ( struct V_59 * V_60 )
{
return F_84 ( V_60 , V_156 , V_116 ,
F_69 ) ;
}
static int F_93 ( struct V_59 * V_60 )
{
return F_84 ( V_60 , V_157 , V_130 ,
F_74 ) ;
}
static void F_94 ( struct V_158 * V_83 , T_4 V_106 )
{
memset ( V_83 , 0 , sizeof( struct V_158 ) ) ;
V_83 -> V_159 [ 2 ] = V_79 ;
V_83 -> V_159 [ 3 ] = 1 ;
V_83 -> V_159 [ 4 ] = V_106 ;
V_83 -> V_159 [ 5 ] = V_160 ;
V_83 -> V_159 [ 6 ] = 1 ;
V_83 -> V_24 . V_161 = (struct V_68 * ) V_83 -> V_159 ;
V_83 -> V_24 . V_162 = 8 ;
}
static inline bool
F_95 ( const struct V_19 * V_20 , const struct V_62 * V_69 )
{
return F_14 ( & V_20 -> V_37 . V_39 , & V_69 -> V_97 ) ;
}
static inline int F_96 ( struct V_19 * V_20 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_145 = 0 ;
struct V_31 * V_31 = F_35 ( V_20 -> V_8 ) ;
if ( V_44 -> V_40 & V_143 ) {
struct V_7 * V_146 = NULL ;
F_43 () ;
if ( V_44 -> V_142 )
V_146 = F_80 ( V_31 , V_44 -> V_142 ) ;
if ( F_97 ( ! F_83 ( V_31 , & V_44 -> V_38 , V_146 , 0 ) ) )
F_98 ( L_6 ,
V_44 -> V_51 ) ;
else if ( ! F_81 ( & V_44 -> V_39 ) &&
F_97 ( F_83 ( V_31 , & V_44 -> V_39 , NULL , 0 ) ) )
F_98 ( L_7 ,
V_44 -> V_51 ) ;
else
V_145 = 1 ;
F_46 () ;
}
return V_145 ;
}
static int F_99 ( struct V_59 * V_60 ,
struct V_7 * V_8 ,
T_4 V_131 ,
struct V_163 * V_164 ,
int V_106 ,
T_6 * V_165 )
{
struct V_31 * V_31 = F_35 ( V_8 ) ;
struct V_19 * V_20 = F_29 ( V_8 ) ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
struct V_62 * V_63 = F_67 ( V_60 ) ;
struct V_158 V_83 ;
struct V_18 * V_21 = NULL , * V_166 = NULL ;
struct V_7 * V_167 ;
int V_101 ;
unsigned int V_168 = sizeof( struct V_62 ) ;
T_5 V_99 ;
int V_53 = - 1 ;
int V_169 ;
if ( ! V_164 -> V_170 )
V_21 = F_7 ( V_20 ) ;
if ( ! V_21 ) {
V_166 = F_100 ( V_31 , NULL , V_164 ) ;
if ( V_166 -> error )
goto V_171;
V_166 = F_101 ( V_31 , V_166 , F_102 ( V_164 ) , NULL , 0 ) ;
if ( F_56 ( V_166 ) ) {
V_53 = F_103 ( V_166 ) ;
V_166 = NULL ;
goto V_171;
}
V_21 = V_166 ;
}
V_167 = V_21 -> V_8 ;
if ( V_167 == V_8 ) {
V_17 -> V_172 ++ ;
F_44 ( L_8 ,
V_20 -> V_37 . V_51 ) ;
goto V_173;
}
V_101 = F_61 ( V_21 ) - sizeof ( * V_63 ) ;
if ( V_106 >= 0 ) {
V_168 += 8 ;
V_101 -= 8 ;
}
if ( V_101 < V_108 )
V_101 = V_108 ;
if ( F_60 ( V_60 ) )
F_60 ( V_60 ) -> V_24 -> V_128 ( F_60 ( V_60 ) , NULL , V_60 , V_101 ) ;
if ( V_60 -> V_94 > V_101 ) {
* V_165 = V_101 ;
V_53 = - V_174 ;
goto V_173;
}
V_168 += F_104 ( V_167 ) ;
if ( F_105 ( V_60 ) < V_168 || F_106 ( V_60 ) ||
( F_107 ( V_60 ) && ! F_108 ( V_60 , 0 ) ) ) {
struct V_59 * V_175 ;
if ( ! ( V_175 = F_109 ( V_60 , V_168 ) ) )
goto V_173;
if ( V_60 -> V_176 )
F_110 ( V_175 , V_60 -> V_176 ) ;
F_111 ( V_60 ) ;
V_60 = V_175 ;
}
F_50 ( V_60 ) ;
if ( V_164 -> V_170 ) {
F_58 ( V_60 , V_21 ) ;
V_166 = NULL ;
} else {
F_112 ( V_60 , V_21 ) ;
}
V_60 -> V_177 = V_60 -> V_152 ;
V_99 = V_164 -> V_178 ;
if ( V_106 >= 0 ) {
F_94 ( & V_83 , V_106 ) ;
F_113 ( V_60 , & V_83 . V_24 , & V_99 , NULL ) ;
}
F_114 ( V_60 , sizeof( struct V_62 ) ) ;
F_52 ( V_60 ) ;
V_63 = F_67 ( V_60 ) ;
* ( T_7 * ) V_63 = V_164 -> V_179 | F_63 ( 0x60000000 ) ;
V_131 = F_115 ( 0 , V_131 ) ;
F_116 ( V_63 , ~ V_132 , V_131 ) ;
V_63 -> V_180 = V_20 -> V_37 . V_180 ;
V_63 -> V_64 = V_99 ;
V_63 -> V_97 = V_164 -> V_97 ;
V_63 -> V_96 = V_164 -> V_96 ;
F_117 ( V_60 ) ;
V_169 = V_60 -> V_94 ;
V_53 = F_118 ( V_60 ) ;
if ( F_119 ( V_53 ) == 0 ) {
struct V_9 * V_12 = F_89 ( V_20 -> V_8 -> V_12 ) ;
V_12 -> V_16 += V_169 ;
V_12 -> V_15 ++ ;
} else {
V_17 -> V_181 ++ ;
V_17 -> V_182 ++ ;
}
if ( V_166 )
F_10 ( V_20 , V_166 ) ;
return 0 ;
V_171:
V_17 -> V_183 ++ ;
F_120 ( V_60 ) ;
V_173:
F_8 ( V_166 ) ;
return V_53 ;
}
static inline int
F_121 ( struct V_59 * V_60 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
const struct V_111 * V_184 = F_53 ( V_60 ) ;
int V_106 = - 1 ;
struct V_163 V_164 ;
T_4 V_131 ;
T_6 V_101 ;
int V_53 ;
if ( ( V_20 -> V_37 . V_99 != V_116 && V_20 -> V_37 . V_99 != 0 ) ||
! F_96 ( V_20 ) )
return - 1 ;
if ( ! ( V_20 -> V_37 . V_40 & V_185 ) )
V_106 = V_20 -> V_37 . V_106 ;
memcpy ( & V_164 , & V_20 -> V_186 . V_187 . V_188 , sizeof ( V_164 ) ) ;
V_164 . V_178 = V_116 ;
V_131 = F_122 ( V_184 ) ;
if ( V_20 -> V_37 . V_40 & V_189 )
V_164 . V_179 |= F_63 ( ( T_6 ) V_184 -> V_124 << V_190 )
& V_191 ;
if ( V_20 -> V_37 . V_40 & V_192 )
V_164 . V_170 = V_60 -> V_193 ;
V_53 = F_99 ( V_60 , V_8 , V_131 , & V_164 , V_106 , & V_101 ) ;
if ( V_53 != 0 ) {
if ( V_53 == - V_174 )
F_62 ( V_60 , V_117 , V_119 ,
F_63 ( V_101 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_123 ( struct V_59 * V_60 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
struct V_62 * V_63 = F_67 ( V_60 ) ;
int V_106 = - 1 ;
T_3 V_87 ;
struct V_163 V_164 ;
T_4 V_131 ;
T_6 V_101 ;
int V_53 ;
if ( ( V_20 -> V_37 . V_99 != V_130 && V_20 -> V_37 . V_99 != 0 ) ||
! F_96 ( V_20 ) || F_95 ( V_20 , V_63 ) )
return - 1 ;
V_87 = F_38 ( V_60 , F_124 ( V_60 ) ) ;
if ( V_87 > 0 ) {
struct V_77 * V_78 ;
V_78 = (struct V_77 * ) & F_124 ( V_60 ) [ V_87 ] ;
if ( V_78 -> V_106 == 0 ) {
F_68 ( V_60 , V_104 ,
V_105 , V_87 + 2 ) ;
return - 1 ;
}
V_106 = V_78 -> V_106 - 1 ;
} else if ( ! ( V_20 -> V_37 . V_40 & V_185 ) )
V_106 = V_20 -> V_37 . V_106 ;
memcpy ( & V_164 , & V_20 -> V_186 . V_187 . V_188 , sizeof ( V_164 ) ) ;
V_164 . V_178 = V_130 ;
V_131 = F_70 ( V_63 ) ;
if ( V_20 -> V_37 . V_40 & V_189 )
V_164 . V_179 |= ( * ( T_7 * ) V_63 & V_191 ) ;
if ( V_20 -> V_37 . V_40 & V_194 )
V_164 . V_179 |= ( * ( T_7 * ) V_63 & V_195 ) ;
if ( V_20 -> V_37 . V_40 & V_192 )
V_164 . V_170 = V_60 -> V_193 ;
V_53 = F_99 ( V_60 , V_8 , V_131 , & V_164 , V_106 , & V_101 ) ;
if ( V_53 != 0 ) {
if ( V_53 == - V_174 )
F_68 ( V_60 , V_107 , 0 , V_101 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_125 ( struct V_59 * V_60 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
int V_145 ;
switch ( V_60 -> V_147 ) {
case F_88 ( V_156 ) :
V_145 = F_121 ( V_60 , V_8 ) ;
break;
case F_88 ( V_157 ) :
V_145 = F_123 ( V_60 , V_8 ) ;
break;
default:
goto V_196;
}
if ( V_145 < 0 )
goto V_196;
return V_197 ;
V_196:
V_17 -> V_181 ++ ;
V_17 -> V_198 ++ ;
F_64 ( V_60 ) ;
return V_197 ;
}
static void F_126 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_43 * V_44 = & V_20 -> V_37 ;
struct V_163 * V_164 = & V_20 -> V_186 . V_187 . V_188 ;
memcpy ( V_8 -> V_199 , & V_44 -> V_38 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_200 , & V_44 -> V_39 , sizeof( struct V_1 ) ) ;
V_164 -> V_97 = V_44 -> V_38 ;
V_164 -> V_96 = V_44 -> V_39 ;
V_164 -> V_201 = V_44 -> V_142 ;
V_164 -> V_179 = 0 ;
if ( ! ( V_44 -> V_40 & V_189 ) )
V_164 -> V_179 |= V_191 & V_44 -> V_202 ;
if ( ! ( V_44 -> V_40 & V_194 ) )
V_164 -> V_179 |= V_195 & V_44 -> V_202 ;
V_44 -> V_40 &= ~ ( V_143 | V_144 | V_137 ) ;
V_44 -> V_40 |= F_77 ( V_20 , & V_44 -> V_38 , & V_44 -> V_39 ) ;
if ( V_44 -> V_40 & V_143 && V_44 -> V_40 & V_144 )
V_8 -> V_40 |= V_203 ;
else
V_8 -> V_40 &= ~ V_203 ;
V_8 -> V_204 = V_44 -> V_142 ;
if ( V_44 -> V_40 & V_143 ) {
int V_205 = ( F_78 ( & V_44 -> V_39 ) &
( V_139 | V_141 ) ) ;
struct V_27 * V_28 = F_66 ( F_35 ( V_8 ) ,
& V_44 -> V_39 , & V_44 -> V_38 ,
V_44 -> V_142 , V_205 ) ;
if ( V_28 == NULL )
return;
if ( V_28 -> V_21 . V_8 ) {
V_8 -> V_206 = V_28 -> V_21 . V_8 -> V_206 +
sizeof ( struct V_62 ) ;
V_8 -> V_101 = V_28 -> V_21 . V_8 -> V_101 - sizeof ( struct V_62 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_185 ) )
V_8 -> V_101 -= 8 ;
if ( V_8 -> V_101 < V_108 )
V_8 -> V_101 = V_108 ;
}
F_8 ( & V_28 -> V_21 ) ;
}
}
static int
F_127 ( struct V_19 * V_20 , struct V_43 * V_44 )
{
V_20 -> V_37 . V_38 = V_44 -> V_38 ;
V_20 -> V_37 . V_39 = V_44 -> V_39 ;
V_20 -> V_37 . V_40 = V_44 -> V_40 ;
V_20 -> V_37 . V_180 = V_44 -> V_180 ;
V_20 -> V_37 . V_106 = V_44 -> V_106 ;
V_20 -> V_37 . V_202 = V_44 -> V_202 ;
V_20 -> V_37 . V_142 = V_44 -> V_142 ;
V_20 -> V_37 . V_99 = V_44 -> V_99 ;
F_9 ( V_20 ) ;
F_126 ( V_20 ) ;
return 0 ;
}
static int
F_128 ( struct V_7 * V_8 , struct V_207 * V_208 , int V_209 )
{
int V_53 = 0 ;
struct V_43 V_44 ;
struct V_19 * V_20 = NULL ;
struct V_31 * V_31 = F_35 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
switch ( V_209 ) {
case V_210 :
if ( V_8 == V_35 -> V_58 ) {
if ( F_129 ( & V_44 , V_208 -> V_211 . V_212 , sizeof ( V_44 ) ) ) {
V_53 = - V_213 ;
break;
}
V_20 = F_33 ( V_31 , & V_44 , 0 ) ;
}
if ( V_20 == NULL )
V_20 = F_29 ( V_8 ) ;
memcpy ( & V_44 , & V_20 -> V_37 , sizeof ( V_44 ) ) ;
if ( F_130 ( V_208 -> V_211 . V_212 , & V_44 , sizeof ( V_44 ) ) ) {
V_53 = - V_213 ;
}
break;
case V_214 :
case V_215 :
V_53 = - V_216 ;
if ( ! F_131 ( V_217 ) )
break;
V_53 = - V_213 ;
if ( F_129 ( & V_44 , V_208 -> V_211 . V_212 , sizeof ( V_44 ) ) )
break;
V_53 = - V_218 ;
if ( V_44 . V_99 != V_130 && V_44 . V_99 != V_116 &&
V_44 . V_99 != 0 )
break;
V_20 = F_33 ( V_31 , & V_44 , V_209 == V_214 ) ;
if ( V_8 != V_35 -> V_58 && V_209 == V_215 ) {
if ( V_20 != NULL ) {
if ( V_20 -> V_8 != V_8 ) {
V_53 = - V_219 ;
break;
}
} else
V_20 = F_29 ( V_8 ) ;
F_21 ( V_35 , V_20 ) ;
F_132 () ;
V_53 = F_127 ( V_20 , & V_44 ) ;
F_18 ( V_35 , V_20 ) ;
F_133 ( V_8 ) ;
}
if ( V_20 ) {
V_53 = 0 ;
if ( F_130 ( V_208 -> V_211 . V_212 , & V_20 -> V_37 , sizeof ( V_44 ) ) )
V_53 = - V_213 ;
} else
V_53 = ( V_209 == V_214 ? - V_220 : - V_95 ) ;
break;
case V_221 :
V_53 = - V_216 ;
if ( ! F_131 ( V_217 ) )
break;
if ( V_8 == V_35 -> V_58 ) {
V_53 = - V_213 ;
if ( F_129 ( & V_44 , V_208 -> V_211 . V_212 , sizeof ( V_44 ) ) )
break;
V_53 = - V_95 ;
if ( ( V_20 = F_33 ( V_31 , & V_44 , 0 ) ) == NULL )
break;
V_53 = - V_216 ;
if ( V_20 -> V_8 == V_35 -> V_58 )
break;
V_8 = V_20 -> V_8 ;
}
V_53 = 0 ;
F_134 ( V_8 ) ;
break;
default:
V_53 = - V_218 ;
}
return V_53 ;
}
static int
F_135 ( struct V_7 * V_8 , int V_222 )
{
if ( V_222 < V_108 ) {
return - V_218 ;
}
V_8 -> V_101 = V_222 ;
return 0 ;
}
static void V_54 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
V_8 -> V_223 = & V_224 ;
V_8 -> V_225 = F_22 ;
V_8 -> type = V_226 ;
V_8 -> V_206 = V_227 + sizeof ( struct V_62 ) ;
V_8 -> V_101 = V_228 - sizeof ( struct V_62 ) ;
V_20 = F_29 ( V_8 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_185 ) )
V_8 -> V_101 -= 8 ;
V_8 -> V_40 |= V_229 ;
V_8 -> V_230 = sizeof( struct V_1 ) ;
V_8 -> V_231 |= V_232 ;
V_8 -> V_233 &= ~ V_234 ;
}
static inline int
F_136 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
V_20 -> V_8 = V_8 ;
V_8 -> V_12 = F_137 ( struct V_9 ) ;
if ( ! V_8 -> V_12 )
return - V_235 ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
int V_53 = F_136 ( V_8 ) ;
if ( V_53 )
return V_53 ;
F_126 ( V_20 ) ;
return 0 ;
}
static int T_9 F_138 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_29 ( V_8 ) ;
struct V_31 * V_31 = F_35 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_53 = F_136 ( V_8 ) ;
if ( V_53 )
return V_53 ;
V_20 -> V_37 . V_99 = V_130 ;
F_32 ( V_8 ) ;
F_126 ( V_20 ) ;
F_19 ( V_35 -> V_42 [ 0 ] , V_20 ) ;
return 0 ;
}
static void T_10 F_139 ( struct V_34 * V_35 )
{
int V_45 ;
struct V_19 * V_20 ;
F_140 ( V_236 ) ;
for ( V_45 = 0 ; V_45 < V_237 ; V_45 ++ ) {
V_20 = F_20 ( V_35 -> V_238 [ V_45 ] ) ;
while ( V_20 != NULL ) {
F_141 ( V_20 -> V_8 , & V_236 ) ;
V_20 = F_20 ( V_20 -> V_49 ) ;
}
}
V_20 = F_20 ( V_35 -> V_42 [ 0 ] ) ;
F_141 ( V_20 -> V_8 , & V_236 ) ;
F_142 ( & V_236 ) ;
}
static int T_9 F_143 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
struct V_19 * V_20 = NULL ;
int V_53 ;
V_35 -> V_47 [ 0 ] = V_35 -> V_42 ;
V_35 -> V_47 [ 1 ] = V_35 -> V_238 ;
V_53 = - V_235 ;
V_35 -> V_58 = F_27 ( sizeof( struct V_19 ) , L_9 ,
V_54 ) ;
if ( ! V_35 -> V_58 )
goto V_239;
F_28 ( V_35 -> V_58 , V_31 ) ;
V_53 = F_138 ( V_35 -> V_58 ) ;
if ( V_53 < 0 )
goto V_240;
V_53 = F_144 ( V_35 -> V_58 ) ;
if ( V_53 < 0 )
goto V_240;
V_20 = F_29 ( V_35 -> V_58 ) ;
strcpy ( V_20 -> V_37 . V_51 , V_35 -> V_58 -> V_51 ) ;
return 0 ;
V_240:
F_22 ( V_35 -> V_58 ) ;
V_239:
return V_53 ;
}
static void T_10 F_145 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
F_146 () ;
F_139 ( V_35 ) ;
F_147 () ;
}
static int T_11 F_148 ( void )
{
int V_53 ;
V_53 = F_149 ( & V_241 ) ;
if ( V_53 < 0 )
goto V_242;
V_53 = F_150 ( & V_243 , V_244 ) ;
if ( V_53 < 0 ) {
F_151 ( L_10 , V_245 ) ;
goto V_246;
}
V_53 = F_150 ( & V_247 , V_248 ) ;
if ( V_53 < 0 ) {
F_151 ( L_11 , V_245 ) ;
goto V_249;
}
return 0 ;
V_249:
F_152 ( & V_243 , V_244 ) ;
V_246:
F_153 ( & V_241 ) ;
V_242:
return V_53 ;
}
static void T_12 F_154 ( void )
{
if ( F_152 ( & V_243 , V_244 ) )
F_155 ( L_12 , V_245 ) ;
if ( F_152 ( & V_247 , V_248 ) )
F_155 ( L_13 , V_245 ) ;
F_153 ( & V_241 ) ;
}
