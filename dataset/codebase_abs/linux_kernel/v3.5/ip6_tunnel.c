static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
F_2 (i) {
const struct V_4 * V_7 = F_3 ( V_3 -> V_7 , V_6 ) ;
V_5 . V_8 += V_7 -> V_8 ;
V_5 . V_9 += V_7 -> V_9 ;
V_5 . V_10 += V_7 -> V_10 ;
V_5 . V_11 += V_7 -> V_11 ;
}
V_3 -> V_12 . V_8 = V_5 . V_8 ;
V_3 -> V_12 . V_9 = V_5 . V_9 ;
V_3 -> V_12 . V_10 = V_5 . V_10 ;
V_3 -> V_12 . V_11 = V_5 . V_11 ;
return & V_3 -> V_12 ;
}
static inline struct V_13 * F_4 ( struct V_14 * V_15 )
{
struct V_13 * V_16 = V_15 -> V_17 ;
if ( V_16 && V_16 -> V_18 &&
V_16 -> V_19 -> V_20 ( V_16 , V_15 -> V_21 ) == NULL ) {
V_15 -> V_17 = NULL ;
F_5 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
static inline void F_6 ( struct V_14 * V_15 )
{
F_5 ( V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
}
static inline void F_7 ( struct V_14 * V_15 , struct V_13 * V_16 )
{
struct V_22 * V_23 = (struct V_22 * ) V_16 ;
V_15 -> V_21 = V_23 -> V_24 ? V_23 -> V_24 -> V_25 : 0 ;
F_5 ( V_15 -> V_17 ) ;
V_15 -> V_17 = V_16 ;
}
static struct V_14 *
F_8 ( struct V_26 * V_26 , const struct V_27 * V_28 , const struct V_27 * V_29 )
{
unsigned int V_30 = F_9 ( V_28 ) ;
unsigned int V_31 = F_9 ( V_29 ) ;
struct V_14 * V_15 ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
F_11 (ip6n->tnls_r_l[h0 ^ h1]) {
if ( F_12 ( V_29 , & V_15 -> V_35 . V_36 ) &&
F_12 ( V_28 , & V_15 -> V_35 . V_37 ) &&
( V_15 -> V_3 -> V_38 & V_39 ) )
return V_15 ;
}
V_15 = F_13 ( V_33 -> V_40 [ 0 ] ) ;
if ( V_15 && ( V_15 -> V_3 -> V_38 & V_39 ) )
return V_15 ;
return NULL ;
}
static struct V_14 T_1 * *
F_14 ( struct V_32 * V_33 , const struct V_41 * V_42 )
{
const struct V_27 * V_28 = & V_42 -> V_37 ;
const struct V_27 * V_29 = & V_42 -> V_36 ;
unsigned int V_43 = 0 ;
int V_44 = 0 ;
if ( ! F_15 ( V_28 ) || ! F_15 ( V_29 ) ) {
V_44 = 1 ;
V_43 = F_9 ( V_28 ) ^ F_9 ( V_29 ) ;
}
return & V_33 -> V_45 [ V_44 ] [ V_43 ] ;
}
static void
F_16 ( struct V_32 * V_33 , struct V_14 * V_15 )
{
struct V_14 T_1 * * V_46 = F_14 ( V_33 , & V_15 -> V_35 ) ;
F_17 ( V_15 -> V_47 , F_18 ( * V_46 ) ) ;
F_17 ( * V_46 , V_15 ) ;
}
static void
F_19 ( struct V_32 * V_33 , struct V_14 * V_15 )
{
struct V_14 T_1 * * V_46 ;
struct V_14 * V_48 ;
for ( V_46 = F_14 ( V_33 , & V_15 -> V_35 ) ;
( V_48 = F_18 ( * V_46 ) ) != NULL ;
V_46 = & V_48 -> V_47 ) {
if ( V_15 == V_48 ) {
F_17 ( * V_46 , V_15 -> V_47 ) ;
break;
}
}
}
static void F_20 ( struct V_2 * V_3 )
{
F_21 ( V_3 -> V_7 ) ;
F_22 ( V_3 ) ;
}
static struct V_14 * F_23 ( struct V_26 * V_26 , struct V_41 * V_42 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
char V_49 [ V_50 ] ;
int V_51 ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
if ( V_42 -> V_49 [ 0 ] )
F_24 ( V_49 , V_42 -> V_49 , V_50 ) ;
else
sprintf ( V_49 , L_1 ) ;
V_3 = F_25 ( sizeof ( * V_15 ) , V_49 , V_52 ) ;
if ( V_3 == NULL )
goto V_53;
F_26 ( V_3 , V_26 ) ;
V_15 = F_27 ( V_3 ) ;
V_15 -> V_35 = * V_42 ;
V_51 = F_28 ( V_3 ) ;
if ( V_51 < 0 )
goto V_54;
if ( ( V_51 = F_29 ( V_3 ) ) < 0 )
goto V_54;
strcpy ( V_15 -> V_35 . V_49 , V_3 -> V_49 ) ;
F_30 ( V_3 ) ;
F_16 ( V_33 , V_15 ) ;
return V_15 ;
V_54:
F_20 ( V_3 ) ;
V_53:
return NULL ;
}
static struct V_14 * F_31 ( struct V_26 * V_26 ,
struct V_41 * V_42 , int V_55 )
{
const struct V_27 * V_28 = & V_42 -> V_37 ;
const struct V_27 * V_29 = & V_42 -> V_36 ;
struct V_14 T_1 * * V_46 ;
struct V_14 * V_15 ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
for ( V_46 = F_14 ( V_33 , V_42 ) ;
( V_15 = F_18 ( * V_46 ) ) != NULL ;
V_46 = & V_15 -> V_47 ) {
if ( F_12 ( V_29 , & V_15 -> V_35 . V_36 ) &&
F_12 ( V_28 , & V_15 -> V_35 . V_37 ) )
return V_15 ;
}
if ( ! V_55 )
return NULL ;
return F_23 ( V_26 , V_42 ) ;
}
static void
F_32 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
struct V_26 * V_26 = F_33 ( V_3 ) ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
if ( V_3 == V_33 -> V_56 )
F_34 ( V_33 -> V_40 [ 0 ] , NULL ) ;
else
F_19 ( V_33 , V_15 ) ;
F_6 ( V_15 ) ;
F_35 ( V_3 ) ;
}
static T_2
F_36 ( struct V_57 * V_58 , T_3 * V_59 )
{
const struct V_60 * V_61 = ( const struct V_60 * ) V_59 ;
T_3 V_62 = V_61 -> V_62 ;
T_2 V_63 = sizeof ( * V_61 ) ;
while ( F_37 ( V_62 ) && V_62 != V_64 ) {
T_2 V_65 = 0 ;
struct V_66 * V_67 ;
if ( V_59 + V_63 + sizeof ( * V_67 ) > V_58 -> V_68 &&
! F_38 ( V_58 , V_59 - V_58 -> V_68 + V_63 + sizeof ( * V_67 ) ) )
break;
V_67 = (struct V_66 * ) ( V_59 + V_63 ) ;
if ( V_62 == V_69 ) {
struct V_70 * V_70 = (struct V_70 * ) V_67 ;
if ( V_70 -> V_71 )
break;
V_65 = 8 ;
} else if ( V_62 == V_72 ) {
V_65 = ( V_67 -> V_73 + 2 ) << 2 ;
} else {
V_65 = F_39 ( V_67 ) ;
}
if ( V_62 == V_74 ) {
T_2 V_6 = V_63 + 2 ;
while ( 1 ) {
struct V_75 * V_76 ;
if ( V_6 + sizeof ( * V_76 ) > V_63 + V_65 )
break;
V_76 = (struct V_75 * ) & V_59 [ V_6 ] ;
if ( V_76 -> type == V_77 &&
V_76 -> V_78 == 1 )
return V_6 ;
if ( V_76 -> type )
V_6 += V_76 -> V_78 + 2 ;
else
V_6 ++ ;
}
}
V_62 = V_67 -> V_62 ;
V_63 += V_65 ;
}
return 0 ;
}
static int
F_40 ( struct V_57 * V_58 , T_3 V_79 , struct V_80 * V_81 ,
T_4 * type , T_4 * V_82 , int * V_83 , T_5 * V_84 , int V_85 )
{
const struct V_60 * V_61 = ( const struct V_60 * ) V_58 -> V_68 ;
struct V_14 * V_15 ;
int V_86 = 0 ;
T_4 V_87 = V_88 ;
T_4 V_89 = V_90 ;
T_5 V_91 = 0 ;
T_2 V_92 ;
int V_51 = - V_93 ;
F_41 () ;
if ( ( V_15 = F_8 ( F_33 ( V_58 -> V_3 ) , & V_61 -> V_94 ,
& V_61 -> V_95 ) ) == NULL )
goto V_96;
if ( V_15 -> V_35 . V_97 != V_79 && V_15 -> V_35 . V_97 != 0 )
goto V_96;
V_51 = 0 ;
switch ( * type ) {
T_5 V_98 ;
struct V_75 * V_76 ;
T_5 V_99 ;
case V_88 :
F_42 ( L_2 ,
V_15 -> V_35 . V_49 ) ;
V_86 = 1 ;
break;
case V_100 :
if ( ( * V_82 ) == V_101 ) {
F_42 ( L_3 ,
V_15 -> V_35 . V_49 ) ;
V_86 = 1 ;
}
break;
case V_102 :
V_98 = 0 ;
if ( ( * V_82 ) == V_103 )
V_98 = F_36 ( V_58 , V_58 -> V_68 ) ;
if ( V_98 && V_98 == * V_84 - 2 ) {
V_76 = (struct V_75 * ) & V_58 -> V_68 [ V_98 ] ;
if ( V_76 -> V_104 == 0 ) {
F_42 ( L_4 ,
V_15 -> V_35 . V_49 ) ;
V_86 = 1 ;
}
} else {
F_42 ( L_5 ,
V_15 -> V_35 . V_49 ) ;
}
break;
case V_105 :
V_99 = * V_84 - V_85 ;
if ( V_99 < V_106 )
V_99 = V_106 ;
V_15 -> V_3 -> V_99 = V_99 ;
if ( ( V_92 = sizeof ( * V_61 ) + F_43 ( V_61 -> V_107 ) ) > V_99 ) {
V_87 = V_105 ;
V_89 = 0 ;
V_91 = V_99 ;
V_86 = 1 ;
}
break;
}
* type = V_87 ;
* V_82 = V_89 ;
* V_84 = V_91 ;
* V_83 = V_86 ;
V_96:
F_44 () ;
return V_51 ;
}
static int
F_45 ( struct V_57 * V_58 , struct V_80 * V_81 ,
T_4 type , T_4 V_82 , int V_85 , T_6 V_84 )
{
int V_86 = 0 ;
T_4 V_87 = type ;
T_4 V_89 = V_82 ;
T_5 V_91 = F_46 ( V_84 ) ;
int V_51 ;
struct V_57 * V_108 ;
const struct V_109 * V_110 ;
struct V_111 * V_23 ;
struct V_112 V_113 ;
V_51 = F_40 ( V_58 , V_114 , V_81 , & V_87 , & V_89 ,
& V_86 , & V_91 , V_85 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_86 == 0 )
return 0 ;
switch ( V_87 ) {
case V_88 :
if ( V_89 != V_90 )
return 0 ;
V_87 = V_115 ;
V_89 = V_116 ;
break;
case V_105 :
if ( V_89 != 0 )
return 0 ;
V_87 = V_115 ;
V_89 = V_117 ;
break;
default:
return 0 ;
}
if ( ! F_38 ( V_58 , V_85 + sizeof( struct V_109 ) ) )
return 0 ;
V_108 = F_47 ( V_58 , V_118 ) ;
if ( ! V_108 )
return 0 ;
F_48 ( V_108 ) ;
F_49 ( V_108 , V_85 ) ;
F_50 ( V_108 ) ;
V_110 = F_51 ( V_108 ) ;
V_23 = F_52 ( F_33 ( V_58 -> V_3 ) , & V_113 , NULL ,
V_110 -> V_95 , 0 ,
0 , 0 ,
V_114 , F_53 ( V_110 -> V_119 ) , 0 ) ;
if ( F_54 ( V_23 ) )
goto V_96;
V_108 -> V_3 = V_23 -> V_16 . V_3 ;
if ( V_23 -> V_120 & V_121 ) {
F_55 ( V_23 ) ;
V_23 = NULL ;
V_23 = F_52 ( F_33 ( V_58 -> V_3 ) , & V_113 , NULL ,
V_110 -> V_94 , V_110 -> V_95 ,
0 , 0 ,
V_114 ,
F_53 ( V_110 -> V_119 ) , 0 ) ;
if ( F_54 ( V_23 ) ||
V_23 -> V_16 . V_3 -> type != V_122 ) {
if ( ! F_54 ( V_23 ) )
F_55 ( V_23 ) ;
goto V_96;
}
F_56 ( V_108 , & V_23 -> V_16 ) ;
} else {
F_55 ( V_23 ) ;
if ( F_57 ( V_108 , V_110 -> V_94 , V_110 -> V_95 , V_110 -> V_119 ,
V_108 -> V_3 ) ||
F_58 ( V_108 ) -> V_3 -> type != V_122 )
goto V_96;
}
if ( V_87 == V_115 && V_89 == V_117 ) {
if ( V_91 > F_59 ( F_58 ( V_108 ) ) )
goto V_96;
F_58 ( V_108 ) -> V_19 -> V_123 ( F_58 ( V_108 ) , V_91 ) ;
}
F_60 ( V_108 , V_87 , V_89 , F_61 ( V_91 ) ) ;
V_96:
F_62 ( V_108 ) ;
return 0 ;
}
static int
F_63 ( struct V_57 * V_58 , struct V_80 * V_81 ,
T_4 type , T_4 V_82 , int V_85 , T_6 V_84 )
{
int V_86 = 0 ;
T_4 V_87 = type ;
T_4 V_89 = V_82 ;
T_5 V_91 = F_46 ( V_84 ) ;
int V_51 ;
V_51 = F_40 ( V_58 , V_124 , V_81 , & V_87 , & V_89 ,
& V_86 , & V_91 , V_85 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_86 && F_38 ( V_58 , V_85 + sizeof( struct V_60 ) ) ) {
struct V_22 * V_23 ;
struct V_57 * V_108 = F_47 ( V_58 , V_118 ) ;
if ( ! V_108 )
return 0 ;
F_48 ( V_108 ) ;
F_49 ( V_108 , V_85 ) ;
F_50 ( V_108 ) ;
V_23 = F_64 ( F_33 ( V_58 -> V_3 ) , & F_65 ( V_108 ) -> V_95 ,
NULL , 0 , 0 ) ;
if ( V_23 && V_23 -> V_16 . V_3 )
V_108 -> V_3 = V_23 -> V_16 . V_3 ;
F_66 ( V_108 , V_87 , V_89 , V_91 ) ;
if ( V_23 )
F_5 ( & V_23 -> V_16 ) ;
F_62 ( V_108 ) ;
}
return 0 ;
}
static void F_67 ( const struct V_14 * V_15 ,
const struct V_60 * V_61 ,
struct V_57 * V_58 )
{
T_3 V_125 = F_68 ( V_61 ) & ~ V_126 ;
if ( V_15 -> V_35 . V_38 & V_127 )
F_69 ( F_51 ( V_58 ) , V_126 , V_125 ) ;
if ( F_70 ( V_125 ) )
F_71 ( F_51 ( V_58 ) ) ;
}
static void F_72 ( const struct V_14 * V_15 ,
const struct V_60 * V_61 ,
struct V_57 * V_58 )
{
if ( V_15 -> V_35 . V_38 & V_127 )
F_73 ( F_68 ( V_61 ) , F_65 ( V_58 ) ) ;
if ( F_70 ( F_68 ( V_61 ) ) )
F_74 ( F_65 ( V_58 ) ) ;
}
static inline int F_75 ( struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_15 -> V_35 ;
int V_128 = 0 ;
struct V_26 * V_26 = F_33 ( V_15 -> V_3 ) ;
if ( V_42 -> V_38 & V_129 ) {
struct V_2 * V_130 = NULL ;
if ( V_42 -> V_131 )
V_130 = F_76 ( V_26 , V_42 -> V_131 ) ;
if ( ( F_77 ( & V_42 -> V_36 ) ||
F_78 ( F_79 ( V_26 , & V_42 -> V_36 , V_130 , 0 ) ) ) &&
F_78 ( ! F_79 ( V_26 , & V_42 -> V_37 , NULL , 0 ) ) )
V_128 = 1 ;
}
return V_128 ;
}
static int F_80 ( struct V_57 * V_58 , T_2 V_132 ,
T_3 V_79 ,
void (* F_81)( const struct V_14 * V_15 ,
const struct V_60 * V_61 ,
struct V_57 * V_58 ) )
{
struct V_14 * V_15 ;
const struct V_60 * V_61 = F_65 ( V_58 ) ;
F_41 () ;
if ( ( V_15 = F_8 ( F_33 ( V_58 -> V_3 ) , & V_61 -> V_95 ,
& V_61 -> V_94 ) ) != NULL ) {
struct V_4 * V_7 ;
if ( V_15 -> V_35 . V_97 != V_79 && V_15 -> V_35 . V_97 != 0 ) {
F_44 () ;
goto V_133;
}
if ( ! F_82 ( NULL , V_134 , V_58 ) ) {
F_44 () ;
goto V_133;
}
if ( ! F_75 ( V_15 ) ) {
V_15 -> V_3 -> V_12 . V_135 ++ ;
F_44 () ;
goto V_133;
}
F_83 ( V_58 ) ;
V_58 -> V_136 = V_58 -> V_137 ;
F_50 ( V_58 ) ;
V_58 -> V_132 = F_84 ( V_132 ) ;
V_58 -> V_138 = V_139 ;
memset ( V_58 -> V_140 , 0 , sizeof( struct V_80 ) ) ;
V_7 = F_85 ( V_15 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_58 -> V_92 ;
F_86 ( V_58 , V_15 -> V_3 ) ;
F_81 ( V_15 , V_61 , V_58 ) ;
F_87 ( V_58 ) ;
F_44 () ;
return 0 ;
}
F_44 () ;
return 1 ;
V_133:
F_62 ( V_58 ) ;
return 0 ;
}
static int F_88 ( struct V_57 * V_58 )
{
return F_80 ( V_58 , V_141 , V_114 ,
F_67 ) ;
}
static int F_89 ( struct V_57 * V_58 )
{
return F_80 ( V_58 , V_142 , V_124 ,
F_72 ) ;
}
static void F_90 ( struct V_143 * V_81 , T_3 V_104 )
{
memset ( V_81 , 0 , sizeof( struct V_143 ) ) ;
V_81 -> V_144 [ 2 ] = V_77 ;
V_81 -> V_144 [ 3 ] = 1 ;
V_81 -> V_144 [ 4 ] = V_104 ;
V_81 -> V_144 [ 5 ] = V_145 ;
V_81 -> V_144 [ 6 ] = 1 ;
V_81 -> V_19 . V_146 = (struct V_66 * ) V_81 -> V_144 ;
V_81 -> V_19 . V_147 = 8 ;
}
static inline bool
F_91 ( const struct V_14 * V_15 , const struct V_60 * V_67 )
{
return F_12 ( & V_15 -> V_35 . V_37 , & V_67 -> V_95 ) ;
}
static inline int F_92 ( struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_15 -> V_35 ;
int V_128 = 0 ;
struct V_26 * V_26 = F_33 ( V_15 -> V_3 ) ;
if ( V_42 -> V_38 & V_148 ) {
struct V_2 * V_130 = NULL ;
F_41 () ;
if ( V_42 -> V_131 )
V_130 = F_76 ( V_26 , V_42 -> V_131 ) ;
if ( F_93 ( ! F_79 ( V_26 , & V_42 -> V_36 , V_130 , 0 ) ) )
F_94 ( L_6 ,
V_42 -> V_49 ) ;
else if ( ! F_77 ( & V_42 -> V_37 ) &&
F_93 ( F_79 ( V_26 , & V_42 -> V_37 , NULL , 0 ) ) )
F_94 ( L_7 ,
V_42 -> V_49 ) ;
else
V_128 = 1 ;
F_44 () ;
}
return V_128 ;
}
static int F_95 ( struct V_57 * V_58 ,
struct V_2 * V_3 ,
T_3 V_125 ,
struct V_149 * V_150 ,
int V_104 ,
T_5 * V_151 )
{
struct V_26 * V_26 = F_33 ( V_3 ) ;
struct V_14 * V_15 = F_27 ( V_3 ) ;
struct V_1 * V_12 = & V_15 -> V_3 -> V_12 ;
struct V_60 * V_61 = F_65 ( V_58 ) ;
struct V_143 V_81 ;
struct V_13 * V_16 = NULL , * V_152 = NULL ;
struct V_2 * V_153 ;
int V_99 ;
unsigned int V_154 = sizeof( struct V_60 ) ;
T_4 V_97 ;
int V_51 = - 1 ;
int V_155 ;
if ( ! V_150 -> V_156 )
V_16 = F_4 ( V_15 ) ;
if ( ! V_16 ) {
V_152 = F_96 ( V_26 , NULL , V_150 ) ;
if ( V_152 -> error )
goto V_157;
V_152 = F_97 ( V_26 , V_152 , F_98 ( V_150 ) , NULL , 0 ) ;
if ( F_54 ( V_152 ) ) {
V_51 = F_99 ( V_152 ) ;
V_152 = NULL ;
goto V_157;
}
V_16 = V_152 ;
}
V_153 = V_16 -> V_3 ;
if ( V_153 == V_3 ) {
V_12 -> V_158 ++ ;
F_42 ( L_8 ,
V_15 -> V_35 . V_49 ) ;
goto V_159;
}
V_99 = F_59 ( V_16 ) - sizeof ( * V_61 ) ;
if ( V_104 >= 0 ) {
V_154 += 8 ;
V_99 -= 8 ;
}
if ( V_99 < V_106 )
V_99 = V_106 ;
if ( F_58 ( V_58 ) )
F_58 ( V_58 ) -> V_19 -> V_123 ( F_58 ( V_58 ) , V_99 ) ;
if ( V_58 -> V_92 > V_99 ) {
* V_151 = V_99 ;
V_51 = - V_160 ;
goto V_159;
}
V_154 += F_100 ( V_153 ) ;
if ( F_101 ( V_58 ) < V_154 || F_102 ( V_58 ) ||
( F_103 ( V_58 ) && ! F_104 ( V_58 , 0 ) ) ) {
struct V_57 * V_161 ;
if ( ! ( V_161 = F_105 ( V_58 , V_154 ) ) )
goto V_159;
if ( V_58 -> V_162 )
F_106 ( V_161 , V_58 -> V_162 ) ;
F_107 ( V_58 ) ;
V_58 = V_161 ;
}
F_48 ( V_58 ) ;
if ( V_150 -> V_156 ) {
F_56 ( V_58 , V_16 ) ;
V_152 = NULL ;
} else {
F_108 ( V_58 , V_16 ) ;
}
V_58 -> V_163 = V_58 -> V_137 ;
V_97 = V_150 -> V_164 ;
if ( V_104 >= 0 ) {
F_90 ( & V_81 , V_104 ) ;
F_109 ( V_58 , & V_81 . V_19 , & V_97 , NULL ) ;
}
F_110 ( V_58 , sizeof( struct V_60 ) ) ;
F_50 ( V_58 ) ;
V_61 = F_65 ( V_58 ) ;
* ( T_6 * ) V_61 = V_150 -> V_165 | F_61 ( 0x60000000 ) ;
V_125 = F_111 ( 0 , V_125 ) ;
F_112 ( V_61 , ~ V_126 , V_125 ) ;
V_61 -> V_166 = V_15 -> V_35 . V_166 ;
V_61 -> V_62 = V_97 ;
V_61 -> V_95 = V_150 -> V_95 ;
V_61 -> V_94 = V_150 -> V_94 ;
F_113 ( V_58 ) ;
V_155 = V_58 -> V_92 ;
V_51 = F_114 ( V_58 ) ;
if ( F_115 ( V_51 ) == 0 ) {
struct V_4 * V_7 = F_85 ( V_15 -> V_3 -> V_7 ) ;
V_7 -> V_11 += V_155 ;
V_7 -> V_10 ++ ;
} else {
V_12 -> V_167 ++ ;
V_12 -> V_168 ++ ;
}
if ( V_152 )
F_7 ( V_15 , V_152 ) ;
return 0 ;
V_157:
V_12 -> V_169 ++ ;
F_116 ( V_58 ) ;
V_159:
F_5 ( V_152 ) ;
return V_51 ;
}
static inline int
F_117 ( struct V_57 * V_58 , struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
const struct V_109 * V_170 = F_51 ( V_58 ) ;
int V_104 = - 1 ;
struct V_149 V_150 ;
T_3 V_125 ;
T_5 V_99 ;
int V_51 ;
if ( ( V_15 -> V_35 . V_97 != V_114 && V_15 -> V_35 . V_97 != 0 ) ||
! F_92 ( V_15 ) )
return - 1 ;
if ( ! ( V_15 -> V_35 . V_38 & V_171 ) )
V_104 = V_15 -> V_35 . V_104 ;
memcpy ( & V_150 , & V_15 -> V_172 . V_173 . V_174 , sizeof ( V_150 ) ) ;
V_150 . V_164 = V_114 ;
V_125 = F_118 ( V_170 ) ;
if ( V_15 -> V_35 . V_38 & V_175 )
V_150 . V_165 |= F_61 ( ( T_5 ) V_170 -> V_119 << V_176 )
& V_177 ;
if ( V_15 -> V_35 . V_38 & V_178 )
V_150 . V_156 = V_58 -> V_179 ;
V_51 = F_95 ( V_58 , V_3 , V_125 , & V_150 , V_104 , & V_99 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_160 )
F_60 ( V_58 , V_115 , V_117 ,
F_61 ( V_99 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_119 ( struct V_57 * V_58 , struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
struct V_60 * V_61 = F_65 ( V_58 ) ;
int V_104 = - 1 ;
T_2 V_85 ;
struct V_149 V_150 ;
T_3 V_125 ;
T_5 V_99 ;
int V_51 ;
if ( ( V_15 -> V_35 . V_97 != V_124 && V_15 -> V_35 . V_97 != 0 ) ||
! F_92 ( V_15 ) || F_91 ( V_15 , V_61 ) )
return - 1 ;
V_85 = F_36 ( V_58 , F_120 ( V_58 ) ) ;
if ( V_85 > 0 ) {
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) & F_120 ( V_58 ) [ V_85 ] ;
if ( V_76 -> V_104 == 0 ) {
F_66 ( V_58 , V_102 ,
V_103 , V_85 + 2 ) ;
return - 1 ;
}
V_104 = V_76 -> V_104 - 1 ;
} else if ( ! ( V_15 -> V_35 . V_38 & V_171 ) )
V_104 = V_15 -> V_35 . V_104 ;
memcpy ( & V_150 , & V_15 -> V_172 . V_173 . V_174 , sizeof ( V_150 ) ) ;
V_150 . V_164 = V_124 ;
V_125 = F_68 ( V_61 ) ;
if ( V_15 -> V_35 . V_38 & V_175 )
V_150 . V_165 |= ( * ( T_6 * ) V_61 & V_177 ) ;
if ( V_15 -> V_35 . V_38 & V_180 )
V_150 . V_165 |= ( * ( T_6 * ) V_61 & V_181 ) ;
if ( V_15 -> V_35 . V_38 & V_178 )
V_150 . V_156 = V_58 -> V_179 ;
V_51 = F_95 ( V_58 , V_3 , V_125 , & V_150 , V_104 , & V_99 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_160 )
F_66 ( V_58 , V_105 , 0 , V_99 ) ;
return - 1 ;
}
return 0 ;
}
static T_7
F_121 ( struct V_57 * V_58 , struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
struct V_1 * V_12 = & V_15 -> V_3 -> V_12 ;
int V_128 ;
switch ( V_58 -> V_132 ) {
case F_84 ( V_141 ) :
V_128 = F_117 ( V_58 , V_3 ) ;
break;
case F_84 ( V_142 ) :
V_128 = F_119 ( V_58 , V_3 ) ;
break;
default:
goto V_182;
}
if ( V_128 < 0 )
goto V_182;
return V_183 ;
V_182:
V_12 -> V_167 ++ ;
V_12 -> V_184 ++ ;
F_62 ( V_58 ) ;
return V_183 ;
}
static void F_122 ( struct V_14 * V_15 )
{
struct V_41 * V_42 = & V_15 -> V_35 ;
int V_185 = F_123 ( & V_42 -> V_36 ) ;
int V_186 = F_123 ( & V_42 -> V_37 ) ;
V_42 -> V_38 &= ~ ( V_148 | V_129 ) ;
if ( V_185 & ( V_187 | V_188 ) &&
V_186 & ( V_187 | V_188 ) &&
! ( ( V_185 | V_186 ) & V_189 ) &&
( ! ( ( V_185 | V_186 ) & V_190 ) || V_42 -> V_131 ) ) {
if ( V_185 & V_187 )
V_42 -> V_38 |= V_148 ;
if ( V_186 & V_187 )
V_42 -> V_38 |= V_129 ;
}
}
static void F_124 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_41 * V_42 = & V_15 -> V_35 ;
struct V_149 * V_150 = & V_15 -> V_172 . V_173 . V_174 ;
memcpy ( V_3 -> V_191 , & V_42 -> V_36 , sizeof( struct V_27 ) ) ;
memcpy ( V_3 -> V_192 , & V_42 -> V_37 , sizeof( struct V_27 ) ) ;
V_150 -> V_95 = V_42 -> V_36 ;
V_150 -> V_94 = V_42 -> V_37 ;
V_150 -> V_193 = V_42 -> V_131 ;
V_150 -> V_165 = 0 ;
if ( ! ( V_42 -> V_38 & V_175 ) )
V_150 -> V_165 |= V_177 & V_42 -> V_194 ;
if ( ! ( V_42 -> V_38 & V_180 ) )
V_150 -> V_165 |= V_181 & V_42 -> V_194 ;
F_122 ( V_15 ) ;
if ( V_42 -> V_38 & V_148 && V_42 -> V_38 & V_129 )
V_3 -> V_38 |= V_195 ;
else
V_3 -> V_38 &= ~ V_195 ;
V_3 -> V_196 = V_42 -> V_131 ;
if ( V_42 -> V_38 & V_148 ) {
int V_197 = ( F_123 ( & V_42 -> V_37 ) &
( V_188 | V_190 ) ) ;
struct V_22 * V_23 = F_64 ( F_33 ( V_3 ) ,
& V_42 -> V_37 , & V_42 -> V_36 ,
V_42 -> V_131 , V_197 ) ;
if ( V_23 == NULL )
return;
if ( V_23 -> V_16 . V_3 ) {
V_3 -> V_198 = V_23 -> V_16 . V_3 -> V_198 +
sizeof ( struct V_60 ) ;
V_3 -> V_99 = V_23 -> V_16 . V_3 -> V_99 - sizeof ( struct V_60 ) ;
if ( ! ( V_15 -> V_35 . V_38 & V_171 ) )
V_3 -> V_99 -= 8 ;
if ( V_3 -> V_99 < V_106 )
V_3 -> V_99 = V_106 ;
}
F_5 ( & V_23 -> V_16 ) ;
}
}
static int
F_125 ( struct V_14 * V_15 , struct V_41 * V_42 )
{
V_15 -> V_35 . V_36 = V_42 -> V_36 ;
V_15 -> V_35 . V_37 = V_42 -> V_37 ;
V_15 -> V_35 . V_38 = V_42 -> V_38 ;
V_15 -> V_35 . V_166 = V_42 -> V_166 ;
V_15 -> V_35 . V_104 = V_42 -> V_104 ;
V_15 -> V_35 . V_194 = V_42 -> V_194 ;
V_15 -> V_35 . V_131 = V_42 -> V_131 ;
V_15 -> V_35 . V_97 = V_42 -> V_97 ;
F_6 ( V_15 ) ;
F_124 ( V_15 ) ;
return 0 ;
}
static int
F_126 ( struct V_2 * V_3 , struct V_199 * V_200 , int V_201 )
{
int V_51 = 0 ;
struct V_41 V_42 ;
struct V_14 * V_15 = NULL ;
struct V_26 * V_26 = F_33 ( V_3 ) ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
switch ( V_201 ) {
case V_202 :
if ( V_3 == V_33 -> V_56 ) {
if ( F_127 ( & V_42 , V_200 -> V_203 . V_204 , sizeof ( V_42 ) ) ) {
V_51 = - V_205 ;
break;
}
V_15 = F_31 ( V_26 , & V_42 , 0 ) ;
}
if ( V_15 == NULL )
V_15 = F_27 ( V_3 ) ;
memcpy ( & V_42 , & V_15 -> V_35 , sizeof ( V_42 ) ) ;
if ( F_128 ( V_200 -> V_203 . V_204 , & V_42 , sizeof ( V_42 ) ) ) {
V_51 = - V_205 ;
}
break;
case V_206 :
case V_207 :
V_51 = - V_208 ;
if ( ! F_129 ( V_209 ) )
break;
V_51 = - V_205 ;
if ( F_127 ( & V_42 , V_200 -> V_203 . V_204 , sizeof ( V_42 ) ) )
break;
V_51 = - V_210 ;
if ( V_42 . V_97 != V_124 && V_42 . V_97 != V_114 &&
V_42 . V_97 != 0 )
break;
V_15 = F_31 ( V_26 , & V_42 , V_201 == V_206 ) ;
if ( V_3 != V_33 -> V_56 && V_201 == V_207 ) {
if ( V_15 != NULL ) {
if ( V_15 -> V_3 != V_3 ) {
V_51 = - V_211 ;
break;
}
} else
V_15 = F_27 ( V_3 ) ;
F_19 ( V_33 , V_15 ) ;
F_130 () ;
V_51 = F_125 ( V_15 , & V_42 ) ;
F_16 ( V_33 , V_15 ) ;
F_131 ( V_3 ) ;
}
if ( V_15 ) {
V_51 = 0 ;
if ( F_128 ( V_200 -> V_203 . V_204 , & V_15 -> V_35 , sizeof ( V_42 ) ) )
V_51 = - V_205 ;
} else
V_51 = ( V_201 == V_206 ? - V_212 : - V_93 ) ;
break;
case V_213 :
V_51 = - V_208 ;
if ( ! F_129 ( V_209 ) )
break;
if ( V_3 == V_33 -> V_56 ) {
V_51 = - V_205 ;
if ( F_127 ( & V_42 , V_200 -> V_203 . V_204 , sizeof ( V_42 ) ) )
break;
V_51 = - V_93 ;
if ( ( V_15 = F_31 ( V_26 , & V_42 , 0 ) ) == NULL )
break;
V_51 = - V_208 ;
if ( V_15 -> V_3 == V_33 -> V_56 )
break;
V_3 = V_15 -> V_3 ;
}
V_51 = 0 ;
F_132 ( V_3 ) ;
break;
default:
V_51 = - V_210 ;
}
return V_51 ;
}
static int
F_133 ( struct V_2 * V_3 , int V_214 )
{
if ( V_214 < V_106 ) {
return - V_210 ;
}
V_3 -> V_99 = V_214 ;
return 0 ;
}
static void V_52 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_3 -> V_215 = & V_216 ;
V_3 -> V_217 = F_20 ;
V_3 -> type = V_218 ;
V_3 -> V_198 = V_219 + sizeof ( struct V_60 ) ;
V_3 -> V_99 = V_220 - sizeof ( struct V_60 ) ;
V_15 = F_27 ( V_3 ) ;
if ( ! ( V_15 -> V_35 . V_38 & V_171 ) )
V_3 -> V_99 -= 8 ;
V_3 -> V_38 |= V_221 ;
V_3 -> V_222 = sizeof( struct V_27 ) ;
V_3 -> V_223 |= V_224 ;
V_3 -> V_225 &= ~ V_226 ;
}
static inline int
F_134 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
V_15 -> V_3 = V_3 ;
V_3 -> V_7 = F_135 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_227 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
int V_51 = F_134 ( V_3 ) ;
if ( V_51 )
return V_51 ;
F_124 ( V_15 ) ;
return 0 ;
}
static int T_8 F_136 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = F_27 ( V_3 ) ;
struct V_26 * V_26 = F_33 ( V_3 ) ;
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
int V_51 = F_134 ( V_3 ) ;
if ( V_51 )
return V_51 ;
V_15 -> V_35 . V_97 = V_124 ;
F_30 ( V_3 ) ;
F_17 ( V_33 -> V_40 [ 0 ] , V_15 ) ;
return 0 ;
}
static void T_9 F_137 ( struct V_32 * V_33 )
{
int V_43 ;
struct V_14 * V_15 ;
F_138 ( V_228 ) ;
for ( V_43 = 0 ; V_43 < V_229 ; V_43 ++ ) {
V_15 = F_18 ( V_33 -> V_230 [ V_43 ] ) ;
while ( V_15 != NULL ) {
F_139 ( V_15 -> V_3 , & V_228 ) ;
V_15 = F_18 ( V_15 -> V_47 ) ;
}
}
V_15 = F_18 ( V_33 -> V_40 [ 0 ] ) ;
F_139 ( V_15 -> V_3 , & V_228 ) ;
F_140 ( & V_228 ) ;
}
static int T_8 F_141 ( struct V_26 * V_26 )
{
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
struct V_14 * V_15 = NULL ;
int V_51 ;
V_33 -> V_45 [ 0 ] = V_33 -> V_40 ;
V_33 -> V_45 [ 1 ] = V_33 -> V_230 ;
V_51 = - V_227 ;
V_33 -> V_56 = F_25 ( sizeof( struct V_14 ) , L_9 ,
V_52 ) ;
if ( ! V_33 -> V_56 )
goto V_231;
F_26 ( V_33 -> V_56 , V_26 ) ;
V_51 = F_136 ( V_33 -> V_56 ) ;
if ( V_51 < 0 )
goto V_232;
V_51 = F_142 ( V_33 -> V_56 ) ;
if ( V_51 < 0 )
goto V_232;
V_15 = F_27 ( V_33 -> V_56 ) ;
strcpy ( V_15 -> V_35 . V_49 , V_33 -> V_56 -> V_49 ) ;
return 0 ;
V_232:
F_20 ( V_33 -> V_56 ) ;
V_231:
return V_51 ;
}
static void T_9 F_143 ( struct V_26 * V_26 )
{
struct V_32 * V_33 = F_10 ( V_26 , V_34 ) ;
F_144 () ;
F_137 ( V_33 ) ;
F_145 () ;
}
static int T_10 F_146 ( void )
{
int V_51 ;
V_51 = F_147 ( & V_233 ) ;
if ( V_51 < 0 )
goto V_234;
V_51 = F_148 ( & V_235 , V_236 ) ;
if ( V_51 < 0 ) {
F_149 ( L_10 , V_237 ) ;
goto V_238;
}
V_51 = F_148 ( & V_239 , V_240 ) ;
if ( V_51 < 0 ) {
F_149 ( L_11 , V_237 ) ;
goto V_241;
}
return 0 ;
V_241:
F_150 ( & V_235 , V_236 ) ;
V_238:
F_151 ( & V_233 ) ;
V_234:
return V_51 ;
}
static void T_11 F_152 ( void )
{
if ( F_150 ( & V_235 , V_236 ) )
F_153 ( L_12 , V_237 ) ;
if ( F_150 ( & V_239 , V_240 ) )
F_153 ( L_13 , V_237 ) ;
F_151 ( & V_233 ) ;
}
