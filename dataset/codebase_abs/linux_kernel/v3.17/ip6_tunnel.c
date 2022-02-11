static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_9 V_10 , V_11 = { 0 } ;
int V_12 ;
F_5 (i) {
unsigned int V_13 ;
const struct V_9 * V_14 =
F_6 ( V_8 -> V_14 , V_12 ) ;
do {
V_13 = F_7 ( & V_14 -> V_15 ) ;
V_10 . V_16 = V_14 -> V_16 ;
V_10 . V_17 = V_14 -> V_17 ;
V_10 . V_18 = V_14 -> V_18 ;
V_10 . V_19 = V_14 -> V_19 ;
} while ( F_8 ( & V_14 -> V_15 , V_13 ) );
V_11 . V_16 += V_10 . V_16 ;
V_11 . V_17 += V_10 . V_17 ;
V_11 . V_18 += V_10 . V_18 ;
V_11 . V_19 += V_10 . V_19 ;
}
V_8 -> V_20 . V_16 = V_11 . V_16 ;
V_8 -> V_20 . V_17 = V_11 . V_17 ;
V_8 -> V_20 . V_18 = V_11 . V_18 ;
V_8 -> V_20 . V_19 = V_11 . V_19 ;
return & V_8 -> V_20 ;
}
struct V_21 * F_9 ( struct V_22 * V_23 )
{
struct V_21 * V_24 = V_23 -> V_25 ;
if ( V_24 && V_24 -> V_26 &&
V_24 -> V_27 -> V_28 ( V_24 , V_23 -> V_29 ) == NULL ) {
V_23 -> V_25 = NULL ;
F_10 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
void F_11 ( struct V_22 * V_23 )
{
F_10 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
}
void F_12 ( struct V_22 * V_23 , struct V_21 * V_24 )
{
struct V_30 * V_31 = (struct V_30 * ) V_24 ;
V_23 -> V_29 = V_31 -> V_32 ? V_31 -> V_32 -> V_33 : 0 ;
F_10 ( V_23 -> V_25 ) ;
V_23 -> V_25 = V_24 ;
}
static struct V_22 *
F_13 ( struct V_34 * V_34 , const struct V_1 * V_35 , const struct V_1 * V_36 )
{
unsigned int V_4 = F_1 ( V_35 , V_36 ) ;
struct V_22 * V_23 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
F_15 (ip6n->tnls_r_l[hash]) {
if ( F_16 ( V_36 , & V_23 -> V_40 . V_41 ) &&
F_16 ( V_35 , & V_23 -> V_40 . V_42 ) &&
( V_23 -> V_8 -> V_43 & V_44 ) )
return V_23 ;
}
V_23 = F_17 ( V_38 -> V_45 [ 0 ] ) ;
if ( V_23 && ( V_23 -> V_8 -> V_43 & V_44 ) )
return V_23 ;
return NULL ;
}
static struct V_22 T_2 * *
F_18 ( struct V_37 * V_38 , const struct V_46 * V_47 )
{
const struct V_1 * V_35 = & V_47 -> V_42 ;
const struct V_1 * V_36 = & V_47 -> V_41 ;
unsigned int V_48 = 0 ;
int V_49 = 0 ;
if ( ! F_19 ( V_35 ) || ! F_19 ( V_36 ) ) {
V_49 = 1 ;
V_48 = F_1 ( V_35 , V_36 ) ;
}
return & V_38 -> V_50 [ V_49 ] [ V_48 ] ;
}
static void
F_20 ( struct V_37 * V_38 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_51 = F_18 ( V_38 , & V_23 -> V_40 ) ;
F_21 ( V_23 -> V_52 , F_22 ( * V_51 ) ) ;
F_21 ( * V_51 , V_23 ) ;
}
static void
F_23 ( struct V_37 * V_38 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_51 ;
struct V_22 * V_53 ;
for ( V_51 = F_18 ( V_38 , & V_23 -> V_40 ) ;
( V_53 = F_22 ( * V_51 ) ) != NULL ;
V_51 = & V_53 -> V_52 ) {
if ( V_23 == V_53 ) {
F_21 ( * V_51 , V_23 -> V_52 ) ;
break;
}
}
}
static void F_24 ( struct V_7 * V_8 )
{
F_25 ( V_8 -> V_14 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_54 ;
V_23 = F_28 ( V_8 ) ;
V_54 = F_30 ( V_8 ) ;
if ( V_54 < 0 )
goto V_55;
V_54 = F_31 ( V_8 ) ;
if ( V_54 < 0 )
goto V_55;
strcpy ( V_23 -> V_40 . V_56 , V_8 -> V_56 ) ;
V_8 -> V_57 = & V_58 ;
F_32 ( V_8 ) ;
F_20 ( V_38 , V_23 ) ;
return 0 ;
V_55:
return V_54 ;
}
static struct V_22 * F_33 ( struct V_34 * V_34 , struct V_46 * V_47 )
{
struct V_7 * V_8 ;
struct V_22 * V_23 ;
char V_56 [ V_59 ] ;
int V_54 ;
if ( V_47 -> V_56 [ 0 ] )
F_34 ( V_56 , V_47 -> V_56 , V_59 ) ;
else
sprintf ( V_56 , L_1 ) ;
V_8 = F_35 ( sizeof( * V_23 ) , V_56 , V_60 ,
V_61 ) ;
if ( V_8 == NULL )
goto V_62;
F_36 ( V_8 , V_34 ) ;
V_23 = F_28 ( V_8 ) ;
V_23 -> V_40 = * V_47 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_54 = F_27 ( V_8 ) ;
if ( V_54 < 0 )
goto V_63;
return V_23 ;
V_63:
F_24 ( V_8 ) ;
V_62:
return NULL ;
}
static struct V_22 * F_37 ( struct V_34 * V_34 ,
struct V_46 * V_47 , int V_64 )
{
const struct V_1 * V_35 = & V_47 -> V_42 ;
const struct V_1 * V_36 = & V_47 -> V_41 ;
struct V_22 T_2 * * V_51 ;
struct V_22 * V_23 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
for ( V_51 = F_18 ( V_38 , V_47 ) ;
( V_23 = F_22 ( * V_51 ) ) != NULL ;
V_51 = & V_23 -> V_52 ) {
if ( F_16 ( V_36 , & V_23 -> V_40 . V_41 ) &&
F_16 ( V_35 , & V_23 -> V_40 . V_42 ) ) {
if ( V_64 )
return NULL ;
return V_23 ;
}
}
if ( ! V_64 )
return NULL ;
return F_33 ( V_34 , V_47 ) ;
}
static void
F_38 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_65 )
F_39 ( V_38 -> V_45 [ 0 ] , NULL ) ;
else
F_23 ( V_38 , V_23 ) ;
F_11 ( V_23 ) ;
F_40 ( V_8 ) ;
}
T_3 F_41 ( struct V_66 * V_67 , T_4 * V_68 )
{
const struct V_69 * V_70 = ( const struct V_69 * ) V_68 ;
T_4 V_71 = V_70 -> V_71 ;
T_3 V_72 = sizeof ( * V_70 ) ;
while ( F_42 ( V_71 ) && V_71 != V_73 ) {
T_3 V_74 = 0 ;
struct V_75 * V_76 ;
if ( V_68 + V_72 + sizeof ( * V_76 ) > V_67 -> V_77 &&
! F_43 ( V_67 , V_68 - V_67 -> V_77 + V_72 + sizeof ( * V_76 ) ) )
break;
V_76 = (struct V_75 * ) ( V_68 + V_72 ) ;
if ( V_71 == V_78 ) {
struct V_79 * V_79 = (struct V_79 * ) V_76 ;
if ( V_79 -> V_80 )
break;
V_74 = 8 ;
} else if ( V_71 == V_81 ) {
V_74 = ( V_76 -> V_82 + 2 ) << 2 ;
} else {
V_74 = F_44 ( V_76 ) ;
}
if ( V_71 == V_83 ) {
T_3 V_12 = V_72 + 2 ;
while ( 1 ) {
struct V_84 * V_85 ;
if ( V_12 + sizeof ( * V_85 ) > V_72 + V_74 )
break;
V_85 = (struct V_84 * ) & V_68 [ V_12 ] ;
if ( V_85 -> type == V_86 &&
V_85 -> V_87 == 1 )
return V_12 ;
if ( V_85 -> type )
V_12 += V_85 -> V_87 + 2 ;
else
V_12 ++ ;
}
}
V_71 = V_76 -> V_71 ;
V_72 += V_74 ;
}
return 0 ;
}
static int
F_45 ( struct V_66 * V_67 , T_4 V_88 , struct V_89 * V_90 ,
T_5 * type , T_5 * V_91 , int * V_92 , T_6 * V_93 , int V_94 )
{
const struct V_69 * V_70 = ( const struct V_69 * ) V_67 -> V_77 ;
struct V_22 * V_23 ;
int V_95 = 0 ;
T_5 V_96 = V_97 ;
T_5 V_98 = V_99 ;
T_6 V_100 = 0 ;
T_3 V_101 ;
int V_54 = - V_102 ;
F_46 () ;
if ( ( V_23 = F_13 ( F_29 ( V_67 -> V_8 ) , & V_70 -> V_103 ,
& V_70 -> V_104 ) ) == NULL )
goto V_55;
if ( V_23 -> V_40 . V_105 != V_88 && V_23 -> V_40 . V_105 != 0 )
goto V_55;
V_54 = 0 ;
switch ( * type ) {
T_6 V_106 ;
struct V_84 * V_85 ;
T_6 V_107 ;
case V_97 :
F_47 ( L_2 ,
V_23 -> V_40 . V_56 ) ;
V_95 = 1 ;
break;
case V_108 :
if ( ( * V_91 ) == V_109 ) {
F_47 ( L_3 ,
V_23 -> V_40 . V_56 ) ;
V_95 = 1 ;
}
break;
case V_110 :
V_106 = 0 ;
if ( ( * V_91 ) == V_111 )
V_106 = F_41 ( V_67 , V_67 -> V_77 ) ;
if ( V_106 && V_106 == * V_93 - 2 ) {
V_85 = (struct V_84 * ) & V_67 -> V_77 [ V_106 ] ;
if ( V_85 -> V_112 == 0 ) {
F_47 ( L_4 ,
V_23 -> V_40 . V_56 ) ;
V_95 = 1 ;
}
} else {
F_47 ( L_5 ,
V_23 -> V_40 . V_56 ) ;
}
break;
case V_113 :
V_107 = * V_93 - V_94 ;
if ( V_107 < V_114 )
V_107 = V_114 ;
V_23 -> V_8 -> V_107 = V_107 ;
if ( ( V_101 = sizeof ( * V_70 ) + F_48 ( V_70 -> V_115 ) ) > V_107 ) {
V_96 = V_113 ;
V_98 = 0 ;
V_100 = V_107 ;
V_95 = 1 ;
}
break;
}
* type = V_96 ;
* V_91 = V_98 ;
* V_93 = V_100 ;
* V_92 = V_95 ;
V_55:
F_49 () ;
return V_54 ;
}
static int
F_50 ( struct V_66 * V_67 , struct V_89 * V_90 ,
T_5 type , T_5 V_91 , int V_94 , T_7 V_93 )
{
int V_95 = 0 ;
T_5 V_96 = type ;
T_5 V_98 = V_91 ;
T_6 V_100 = F_51 ( V_93 ) ;
int V_54 ;
struct V_66 * V_116 ;
const struct V_117 * V_118 ;
struct V_119 * V_31 ;
struct V_120 V_121 ;
V_54 = F_45 ( V_67 , V_122 , V_90 , & V_96 , & V_98 ,
& V_95 , & V_100 , V_94 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_95 == 0 )
return 0 ;
switch ( V_96 ) {
case V_97 :
if ( V_98 != V_99 )
return 0 ;
V_96 = V_123 ;
V_98 = V_124 ;
break;
case V_113 :
if ( V_98 != 0 )
return 0 ;
V_96 = V_123 ;
V_98 = V_125 ;
break;
case V_126 :
V_96 = V_127 ;
V_98 = V_128 ;
default:
return 0 ;
}
if ( ! F_43 ( V_67 , V_94 + sizeof( struct V_117 ) ) )
return 0 ;
V_116 = F_52 ( V_67 , V_129 ) ;
if ( ! V_116 )
return 0 ;
F_53 ( V_116 ) ;
F_54 ( V_116 , V_94 ) ;
F_55 ( V_116 ) ;
V_118 = F_56 ( V_116 ) ;
V_31 = F_57 ( F_29 ( V_67 -> V_8 ) , & V_121 , NULL ,
V_118 -> V_104 , 0 ,
0 , 0 ,
V_122 , F_58 ( V_118 -> V_130 ) , 0 ) ;
if ( F_59 ( V_31 ) )
goto V_55;
V_116 -> V_8 = V_31 -> V_24 . V_8 ;
if ( V_31 -> V_131 & V_132 ) {
F_60 ( V_31 ) ;
V_31 = NULL ;
V_31 = F_57 ( F_29 ( V_67 -> V_8 ) , & V_121 , NULL ,
V_118 -> V_103 , V_118 -> V_104 ,
0 , 0 ,
V_122 ,
F_58 ( V_118 -> V_130 ) , 0 ) ;
if ( F_59 ( V_31 ) ||
V_31 -> V_24 . V_8 -> type != V_133 ) {
if ( ! F_59 ( V_31 ) )
F_60 ( V_31 ) ;
goto V_55;
}
F_61 ( V_116 , & V_31 -> V_24 ) ;
} else {
F_60 ( V_31 ) ;
if ( F_62 ( V_116 , V_118 -> V_103 , V_118 -> V_104 , V_118 -> V_130 ,
V_116 -> V_8 ) ||
F_63 ( V_116 ) -> V_8 -> type != V_133 )
goto V_55;
}
if ( V_96 == V_123 && V_98 == V_125 ) {
if ( V_100 > F_64 ( F_63 ( V_116 ) ) )
goto V_55;
F_63 ( V_116 ) -> V_27 -> V_134 ( F_63 ( V_116 ) , NULL , V_116 , V_100 ) ;
}
if ( V_96 == V_127 )
F_63 ( V_116 ) -> V_27 -> V_135 ( F_63 ( V_116 ) , NULL , V_116 ) ;
F_65 ( V_116 , V_96 , V_98 , F_66 ( V_100 ) ) ;
V_55:
F_67 ( V_116 ) ;
return 0 ;
}
static int
F_68 ( struct V_66 * V_67 , struct V_89 * V_90 ,
T_5 type , T_5 V_91 , int V_94 , T_7 V_93 )
{
int V_95 = 0 ;
T_5 V_96 = type ;
T_5 V_98 = V_91 ;
T_6 V_100 = F_51 ( V_93 ) ;
int V_54 ;
V_54 = F_45 ( V_67 , V_136 , V_90 , & V_96 , & V_98 ,
& V_95 , & V_100 , V_94 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_95 && F_43 ( V_67 , V_94 + sizeof( struct V_69 ) ) ) {
struct V_30 * V_31 ;
struct V_66 * V_116 = F_52 ( V_67 , V_129 ) ;
if ( ! V_116 )
return 0 ;
F_53 ( V_116 ) ;
F_54 ( V_116 , V_94 ) ;
F_55 ( V_116 ) ;
V_31 = F_69 ( F_29 ( V_67 -> V_8 ) , & F_70 ( V_116 ) -> V_104 ,
NULL , 0 , 0 ) ;
if ( V_31 && V_31 -> V_24 . V_8 )
V_116 -> V_8 = V_31 -> V_24 . V_8 ;
F_71 ( V_116 , V_96 , V_98 , V_100 ) ;
F_72 ( V_31 ) ;
F_67 ( V_116 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_22 * V_23 ,
const struct V_69 * V_70 ,
struct V_66 * V_67 )
{
T_4 V_137 = F_74 ( V_70 ) & ~ V_138 ;
if ( V_23 -> V_40 . V_43 & V_139 )
F_75 ( F_56 ( V_67 ) , V_138 , V_137 ) ;
return F_76 ( V_70 , V_67 ) ;
}
static int F_77 ( const struct V_22 * V_23 ,
const struct V_69 * V_70 ,
struct V_66 * V_67 )
{
if ( V_23 -> V_40 . V_43 & V_139 )
F_78 ( F_74 ( V_70 ) , F_70 ( V_67 ) ) ;
return F_76 ( V_70 , V_67 ) ;
}
T_6 F_79 ( struct V_22 * V_23 ,
const struct V_1 * V_41 ,
const struct V_1 * V_42 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_140 = F_80 ( V_41 ) ;
int V_141 = F_80 ( V_42 ) ;
T_6 V_43 = 0 ;
if ( V_140 == V_142 || V_141 == V_142 ) {
V_43 = V_143 ;
} else if ( V_140 & ( V_144 | V_145 ) &&
V_141 & ( V_144 | V_145 ) &&
! ( ( V_140 | V_141 ) & V_146 ) &&
( ! ( ( V_140 | V_141 ) & V_147 ) || V_47 -> V_148 ) ) {
if ( V_140 & V_144 )
V_43 |= V_149 ;
if ( V_141 & V_144 )
V_43 |= V_150 ;
}
return V_43 ;
}
int F_81 ( struct V_22 * V_23 ,
const struct V_1 * V_41 ,
const struct V_1 * V_42 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_151 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_47 -> V_43 & V_150 ) ||
( ( V_47 -> V_43 & V_143 ) &&
( F_79 ( V_23 , V_41 , V_42 ) & V_150 ) ) ) {
struct V_7 * V_152 = NULL ;
if ( V_47 -> V_148 )
V_152 = F_82 ( V_34 , V_47 -> V_148 ) ;
if ( ( F_83 ( V_41 ) ||
F_84 ( F_85 ( V_34 , V_41 , V_152 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_34 , V_42 , NULL , 0 ) ) )
V_151 = 1 ;
}
return V_151 ;
}
static int F_86 ( struct V_66 * V_67 , T_3 V_153 ,
T_4 V_88 ,
int (* F_87)( const struct V_22 * V_23 ,
const struct V_69 * V_70 ,
struct V_66 * V_67 ) )
{
struct V_22 * V_23 ;
const struct V_69 * V_70 = F_70 ( V_67 ) ;
int V_54 ;
F_46 () ;
if ( ( V_23 = F_13 ( F_29 ( V_67 -> V_8 ) , & V_70 -> V_104 ,
& V_70 -> V_103 ) ) != NULL ) {
struct V_9 * V_14 ;
if ( V_23 -> V_40 . V_105 != V_88 && V_23 -> V_40 . V_105 != 0 ) {
F_49 () ;
goto V_154;
}
if ( ! F_88 ( NULL , V_155 , V_67 ) ) {
F_49 () ;
goto V_154;
}
if ( ! F_81 ( V_23 , & V_70 -> V_103 , & V_70 -> V_104 ) ) {
V_23 -> V_8 -> V_20 . V_156 ++ ;
F_49 () ;
goto V_154;
}
V_67 -> V_157 = V_67 -> V_158 ;
F_55 ( V_67 ) ;
V_67 -> V_153 = F_89 ( V_153 ) ;
memset ( V_67 -> V_159 , 0 , sizeof( struct V_89 ) ) ;
F_90 ( V_67 , V_23 -> V_8 , V_23 -> V_34 ) ;
V_54 = F_87 ( V_23 , V_70 , V_67 ) ;
if ( F_91 ( V_54 ) ) {
if ( V_160 )
F_92 ( L_6 ,
& V_70 -> V_104 ,
F_74 ( V_70 ) ) ;
if ( V_54 > 1 ) {
++ V_23 -> V_8 -> V_20 . V_161 ;
++ V_23 -> V_8 -> V_20 . V_162 ;
F_49 () ;
goto V_154;
}
}
V_14 = F_93 ( V_23 -> V_8 -> V_14 ) ;
F_94 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_67 -> V_101 ;
F_95 ( & V_14 -> V_15 ) ;
F_96 ( V_67 ) ;
F_49 () ;
return 0 ;
}
F_49 () ;
return 1 ;
V_154:
F_67 ( V_67 ) ;
return 0 ;
}
static int F_97 ( struct V_66 * V_67 )
{
return F_86 ( V_67 , V_163 , V_122 ,
F_73 ) ;
}
static int F_98 ( struct V_66 * V_67 )
{
return F_86 ( V_67 , V_164 , V_136 ,
F_77 ) ;
}
static void F_99 ( struct V_165 * V_90 , T_4 V_112 )
{
memset ( V_90 , 0 , sizeof( struct V_165 ) ) ;
V_90 -> V_166 [ 2 ] = V_86 ;
V_90 -> V_166 [ 3 ] = 1 ;
V_90 -> V_166 [ 4 ] = V_112 ;
V_90 -> V_166 [ 5 ] = V_167 ;
V_90 -> V_166 [ 6 ] = 1 ;
V_90 -> V_27 . V_168 = (struct V_75 * ) V_90 -> V_166 ;
V_90 -> V_27 . V_169 = 8 ;
}
static inline bool
F_100 ( const struct V_22 * V_23 , const struct V_69 * V_76 )
{
return F_16 ( & V_23 -> V_40 . V_42 , & V_76 -> V_104 ) ;
}
int F_101 ( struct V_22 * V_23 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_151 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( V_47 -> V_43 & V_149 ) {
struct V_7 * V_152 = NULL ;
F_46 () ;
if ( V_47 -> V_148 )
V_152 = F_82 ( V_34 , V_47 -> V_148 ) ;
if ( F_91 ( ! F_85 ( V_34 , & V_47 -> V_41 , V_152 , 0 ) ) )
F_102 ( L_7 ,
V_47 -> V_56 ) ;
else if ( ! F_83 ( & V_47 -> V_42 ) &&
F_91 ( F_85 ( V_34 , & V_47 -> V_42 , NULL , 0 ) ) )
F_102 ( L_8 ,
V_47 -> V_56 ) ;
else
V_151 = 1 ;
F_49 () ;
}
return V_151 ;
}
static int F_103 ( struct V_66 * V_67 ,
struct V_7 * V_8 ,
T_4 V_137 ,
struct V_170 * V_171 ,
int V_112 ,
T_6 * V_172 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
struct V_69 * V_70 = F_70 ( V_67 ) ;
struct V_165 V_90 ;
struct V_21 * V_24 = NULL , * V_173 = NULL ;
struct V_7 * V_174 ;
int V_107 ;
unsigned int V_175 = sizeof( struct V_69 ) ;
T_5 V_105 ;
int V_54 = - 1 ;
if ( ! V_171 -> V_176 )
V_24 = F_9 ( V_23 ) ;
if ( ! V_24 ) {
V_173 = F_104 ( V_34 , NULL , V_171 ) ;
if ( V_173 -> error )
goto V_177;
V_173 = F_105 ( V_34 , V_173 , F_106 ( V_171 ) , NULL , 0 ) ;
if ( F_59 ( V_173 ) ) {
V_54 = F_107 ( V_173 ) ;
V_173 = NULL ;
goto V_177;
}
V_24 = V_173 ;
}
V_174 = V_24 -> V_8 ;
if ( V_174 == V_8 ) {
V_20 -> V_178 ++ ;
F_47 ( L_9 ,
V_23 -> V_40 . V_56 ) ;
goto V_179;
}
V_107 = F_64 ( V_24 ) - sizeof ( * V_70 ) ;
if ( V_112 >= 0 ) {
V_175 += 8 ;
V_107 -= 8 ;
}
if ( V_107 < V_114 )
V_107 = V_114 ;
if ( F_63 ( V_67 ) )
F_63 ( V_67 ) -> V_27 -> V_134 ( F_63 ( V_67 ) , NULL , V_67 , V_107 ) ;
if ( V_67 -> V_101 > V_107 ) {
* V_172 = V_107 ;
V_54 = - V_180 ;
goto V_179;
}
F_108 ( V_67 , ! F_109 ( V_23 -> V_34 , F_29 ( V_8 ) ) ) ;
V_175 += F_110 ( V_174 ) ;
if ( F_111 ( V_67 ) < V_175 || F_112 ( V_67 ) ||
( F_113 ( V_67 ) && ! F_114 ( V_67 , 0 ) ) ) {
struct V_66 * V_181 ;
if ( ! ( V_181 = F_115 ( V_67 , V_175 ) ) )
goto V_179;
if ( V_67 -> V_182 )
F_116 ( V_181 , V_67 -> V_182 ) ;
F_117 ( V_67 ) ;
V_67 = V_181 ;
}
if ( V_171 -> V_176 ) {
F_61 ( V_67 , V_24 ) ;
V_173 = NULL ;
} else {
F_118 ( V_67 , V_24 ) ;
}
V_67 -> V_183 = V_67 -> V_158 ;
V_105 = V_171 -> V_184 ;
if ( V_112 >= 0 ) {
F_99 ( & V_90 , V_112 ) ;
F_119 ( V_67 , & V_90 . V_27 , & V_105 , NULL ) ;
}
if ( F_84 ( ! V_67 -> V_185 ) ) {
F_120 ( V_67 ) ;
V_67 -> V_185 = 1 ;
}
F_121 ( V_67 , sizeof( struct V_69 ) ) ;
F_55 ( V_67 ) ;
V_70 = F_70 ( V_67 ) ;
F_122 ( V_70 , F_123 ( 0 , V_137 ) ,
F_124 ( V_34 , V_67 , V_171 -> V_186 , false ) ) ;
V_70 -> V_187 = V_23 -> V_40 . V_187 ;
V_70 -> V_71 = V_105 ;
V_70 -> V_104 = V_171 -> V_104 ;
V_70 -> V_103 = V_171 -> V_103 ;
F_125 ( V_67 , V_8 ) ;
if ( V_173 )
F_12 ( V_23 , V_173 ) ;
return 0 ;
V_177:
V_20 -> V_188 ++ ;
F_126 ( V_67 ) ;
V_179:
F_10 ( V_173 ) ;
return V_54 ;
}
static inline int
F_127 ( struct V_66 * V_67 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
const struct V_117 * V_189 = F_56 ( V_67 ) ;
int V_112 = - 1 ;
struct V_170 V_171 ;
T_4 V_137 ;
T_6 V_107 ;
int V_54 ;
if ( ( V_23 -> V_40 . V_105 != V_122 && V_23 -> V_40 . V_105 != 0 ) ||
! F_101 ( V_23 ) )
return - 1 ;
if ( ! ( V_23 -> V_40 . V_43 & V_190 ) )
V_112 = V_23 -> V_40 . V_112 ;
memcpy ( & V_171 , & V_23 -> V_191 . V_192 . V_193 , sizeof ( V_171 ) ) ;
V_171 . V_184 = V_122 ;
V_137 = F_128 ( V_189 ) ;
if ( V_23 -> V_40 . V_43 & V_194 )
V_171 . V_186 |= F_66 ( ( T_6 ) V_189 -> V_130 << V_195 )
& V_196 ;
if ( V_23 -> V_40 . V_43 & V_197 )
V_171 . V_176 = V_67 -> V_198 ;
V_54 = F_103 ( V_67 , V_8 , V_137 , & V_171 , V_112 , & V_107 ) ;
if ( V_54 != 0 ) {
if ( V_54 == - V_180 )
F_65 ( V_67 , V_123 , V_125 ,
F_66 ( V_107 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_129 ( struct V_66 * V_67 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_69 * V_70 = F_70 ( V_67 ) ;
int V_112 = - 1 ;
T_3 V_94 ;
struct V_170 V_171 ;
T_4 V_137 ;
T_6 V_107 ;
int V_54 ;
if ( ( V_23 -> V_40 . V_105 != V_136 && V_23 -> V_40 . V_105 != 0 ) ||
! F_101 ( V_23 ) || F_100 ( V_23 , V_70 ) )
return - 1 ;
V_94 = F_41 ( V_67 , F_130 ( V_67 ) ) ;
if ( V_94 > 0 ) {
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) & F_130 ( V_67 ) [ V_94 ] ;
if ( V_85 -> V_112 == 0 ) {
F_71 ( V_67 , V_110 ,
V_111 , V_94 + 2 ) ;
return - 1 ;
}
V_112 = V_85 -> V_112 - 1 ;
} else if ( ! ( V_23 -> V_40 . V_43 & V_190 ) )
V_112 = V_23 -> V_40 . V_112 ;
memcpy ( & V_171 , & V_23 -> V_191 . V_192 . V_193 , sizeof ( V_171 ) ) ;
V_171 . V_184 = V_136 ;
V_137 = F_74 ( V_70 ) ;
if ( V_23 -> V_40 . V_43 & V_194 )
V_171 . V_186 |= ( * ( T_7 * ) V_70 & V_196 ) ;
if ( V_23 -> V_40 . V_43 & V_199 )
V_171 . V_186 |= F_131 ( V_70 ) ;
if ( V_23 -> V_40 . V_43 & V_197 )
V_171 . V_176 = V_67 -> V_198 ;
V_54 = F_103 ( V_67 , V_8 , V_137 , & V_171 , V_112 , & V_107 ) ;
if ( V_54 != 0 ) {
if ( V_54 == - V_180 )
F_71 ( V_67 , V_113 , 0 , V_107 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_132 ( struct V_66 * V_67 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
int V_151 ;
switch ( V_67 -> V_153 ) {
case F_89 ( V_163 ) :
V_151 = F_127 ( V_67 , V_8 ) ;
break;
case F_89 ( V_164 ) :
V_151 = F_129 ( V_67 , V_8 ) ;
break;
default:
goto V_200;
}
if ( V_151 < 0 )
goto V_200;
return V_201 ;
V_200:
V_20 -> V_202 ++ ;
V_20 -> V_203 ++ ;
F_67 ( V_67 ) ;
return V_201 ;
}
static void F_133 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_46 * V_47 = & V_23 -> V_40 ;
struct V_170 * V_171 = & V_23 -> V_191 . V_192 . V_193 ;
memcpy ( V_8 -> V_204 , & V_47 -> V_41 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_205 , & V_47 -> V_42 , sizeof( struct V_1 ) ) ;
V_171 -> V_104 = V_47 -> V_41 ;
V_171 -> V_103 = V_47 -> V_42 ;
V_171 -> V_206 = V_47 -> V_148 ;
V_171 -> V_186 = 0 ;
if ( ! ( V_47 -> V_43 & V_194 ) )
V_171 -> V_186 |= V_196 & V_47 -> V_207 ;
if ( ! ( V_47 -> V_43 & V_199 ) )
V_171 -> V_186 |= V_208 & V_47 -> V_207 ;
V_47 -> V_43 &= ~ ( V_149 | V_150 | V_143 ) ;
V_47 -> V_43 |= F_79 ( V_23 , & V_47 -> V_41 , & V_47 -> V_42 ) ;
if ( V_47 -> V_43 & V_149 && V_47 -> V_43 & V_150 )
V_8 -> V_43 |= V_209 ;
else
V_8 -> V_43 &= ~ V_209 ;
V_8 -> V_210 = V_47 -> V_148 ;
if ( V_47 -> V_43 & V_149 ) {
int V_211 = ( F_80 ( & V_47 -> V_42 ) &
( V_145 | V_147 ) ) ;
struct V_30 * V_31 = F_69 ( V_23 -> V_34 ,
& V_47 -> V_42 , & V_47 -> V_41 ,
V_47 -> V_148 , V_211 ) ;
if ( V_31 == NULL )
return;
if ( V_31 -> V_24 . V_8 ) {
V_8 -> V_212 = V_31 -> V_24 . V_8 -> V_212 +
sizeof ( struct V_69 ) ;
V_8 -> V_107 = V_31 -> V_24 . V_8 -> V_107 - sizeof ( struct V_69 ) ;
if ( ! ( V_23 -> V_40 . V_43 & V_190 ) )
V_8 -> V_107 -= 8 ;
if ( V_8 -> V_107 < V_114 )
V_8 -> V_107 = V_114 ;
}
F_72 ( V_31 ) ;
}
}
static int
F_134 ( struct V_22 * V_23 , const struct V_46 * V_47 )
{
V_23 -> V_40 . V_41 = V_47 -> V_41 ;
V_23 -> V_40 . V_42 = V_47 -> V_42 ;
V_23 -> V_40 . V_43 = V_47 -> V_43 ;
V_23 -> V_40 . V_187 = V_47 -> V_187 ;
V_23 -> V_40 . V_112 = V_47 -> V_112 ;
V_23 -> V_40 . V_207 = V_47 -> V_207 ;
V_23 -> V_40 . V_148 = V_47 -> V_148 ;
V_23 -> V_40 . V_105 = V_47 -> V_105 ;
F_11 ( V_23 ) ;
F_133 ( V_23 ) ;
return 0 ;
}
static int F_135 ( struct V_22 * V_23 , struct V_46 * V_47 )
{
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_54 ;
F_23 ( V_38 , V_23 ) ;
F_136 () ;
V_54 = F_134 ( V_23 , V_47 ) ;
F_20 ( V_38 , V_23 ) ;
F_137 ( V_23 -> V_8 ) ;
return V_54 ;
}
static void
F_138 ( struct V_46 * V_47 , const struct V_213 * V_192 )
{
V_47 -> V_41 = V_192 -> V_41 ;
V_47 -> V_42 = V_192 -> V_42 ;
V_47 -> V_43 = V_192 -> V_43 ;
V_47 -> V_187 = V_192 -> V_187 ;
V_47 -> V_112 = V_192 -> V_112 ;
V_47 -> V_207 = V_192 -> V_207 ;
V_47 -> V_148 = V_192 -> V_148 ;
V_47 -> V_105 = V_192 -> V_105 ;
memcpy ( V_47 -> V_56 , V_192 -> V_56 , sizeof( V_192 -> V_56 ) ) ;
}
static void
F_139 ( struct V_213 * V_192 , const struct V_46 * V_47 )
{
V_192 -> V_41 = V_47 -> V_41 ;
V_192 -> V_42 = V_47 -> V_42 ;
V_192 -> V_43 = V_47 -> V_43 ;
V_192 -> V_187 = V_47 -> V_187 ;
V_192 -> V_112 = V_47 -> V_112 ;
V_192 -> V_207 = V_47 -> V_207 ;
V_192 -> V_148 = V_47 -> V_148 ;
V_192 -> V_105 = V_47 -> V_105 ;
memcpy ( V_192 -> V_56 , V_47 -> V_56 , sizeof( V_192 -> V_56 ) ) ;
}
static int
F_140 ( struct V_7 * V_8 , struct V_214 * V_215 , int V_216 )
{
int V_54 = 0 ;
struct V_213 V_47 ;
struct V_46 V_217 ;
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
switch ( V_216 ) {
case V_218 :
if ( V_8 == V_38 -> V_65 ) {
if ( F_141 ( & V_47 , V_215 -> V_219 . V_220 , sizeof ( V_47 ) ) ) {
V_54 = - V_221 ;
break;
}
F_138 ( & V_217 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_217 , 0 ) ;
if ( V_23 == NULL )
V_23 = F_28 ( V_8 ) ;
} else {
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
}
F_139 ( & V_47 , & V_23 -> V_40 ) ;
if ( F_142 ( V_215 -> V_219 . V_220 , & V_47 , sizeof ( V_47 ) ) ) {
V_54 = - V_221 ;
}
break;
case V_222 :
case V_223 :
V_54 = - V_224 ;
if ( ! F_143 ( V_34 -> V_225 , V_226 ) )
break;
V_54 = - V_221 ;
if ( F_141 ( & V_47 , V_215 -> V_219 . V_220 , sizeof ( V_47 ) ) )
break;
V_54 = - V_227 ;
if ( V_47 . V_105 != V_136 && V_47 . V_105 != V_122 &&
V_47 . V_105 != 0 )
break;
F_138 ( & V_217 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_217 , V_216 == V_222 ) ;
if ( V_8 != V_38 -> V_65 && V_216 == V_223 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_8 != V_8 ) {
V_54 = - V_228 ;
break;
}
} else
V_23 = F_28 ( V_8 ) ;
V_54 = F_135 ( V_23 , & V_217 ) ;
}
if ( V_23 ) {
V_54 = 0 ;
F_139 ( & V_47 , & V_23 -> V_40 ) ;
if ( F_142 ( V_215 -> V_219 . V_220 , & V_47 , sizeof( V_47 ) ) )
V_54 = - V_221 ;
} else
V_54 = ( V_216 == V_222 ? - V_229 : - V_102 ) ;
break;
case V_230 :
V_54 = - V_224 ;
if ( ! F_143 ( V_34 -> V_225 , V_226 ) )
break;
if ( V_8 == V_38 -> V_65 ) {
V_54 = - V_221 ;
if ( F_141 ( & V_47 , V_215 -> V_219 . V_220 , sizeof ( V_47 ) ) )
break;
V_54 = - V_102 ;
F_138 ( & V_217 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_217 , 0 ) ;
if ( V_23 == NULL )
break;
V_54 = - V_224 ;
if ( V_23 -> V_8 == V_38 -> V_65 )
break;
V_8 = V_23 -> V_8 ;
}
V_54 = 0 ;
F_144 ( V_8 ) ;
break;
default:
V_54 = - V_227 ;
}
return V_54 ;
}
static int
F_145 ( struct V_7 * V_8 , int V_231 )
{
struct V_22 * V_232 = F_28 ( V_8 ) ;
if ( V_232 -> V_40 . V_105 == V_122 ) {
if ( V_231 < 68 )
return - V_227 ;
} else {
if ( V_231 < V_114 )
return - V_227 ;
}
if ( V_231 > 0xFFF8 - V_8 -> V_212 )
return - V_227 ;
V_8 -> V_107 = V_231 ;
return 0 ;
}
static void V_61 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_8 -> V_233 = & V_234 ;
V_8 -> V_235 = F_24 ;
V_8 -> type = V_236 ;
V_8 -> V_212 = V_237 + sizeof ( struct V_69 ) ;
V_8 -> V_107 = V_238 - sizeof ( struct V_69 ) ;
V_23 = F_28 ( V_8 ) ;
if ( ! ( V_23 -> V_40 . V_43 & V_190 ) )
V_8 -> V_107 -= 8 ;
V_8 -> V_43 |= V_239 ;
V_8 -> V_240 = sizeof( struct V_1 ) ;
V_8 -> V_241 &= ~ V_242 ;
V_8 -> V_243 = V_244 ;
F_146 ( V_8 -> V_245 ) ;
}
static inline int
F_147 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_8 -> V_14 = F_148 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_246 ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
int V_54 = F_147 ( V_8 ) ;
if ( V_54 )
return V_54 ;
F_133 ( V_23 ) ;
return 0 ;
}
static int T_9 F_149 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_54 = F_147 ( V_8 ) ;
if ( V_54 )
return V_54 ;
V_23 -> V_40 . V_105 = V_136 ;
F_32 ( V_8 ) ;
F_133 ( V_23 ) ;
F_21 ( V_38 -> V_45 [ 0 ] , V_23 ) ;
return 0 ;
}
static int F_150 ( struct V_247 * V_248 [] , struct V_247 * V_77 [] )
{
T_5 V_105 ;
if ( ! V_77 || ! V_77 [ V_249 ] )
return 0 ;
V_105 = F_151 ( V_77 [ V_249 ] ) ;
if ( V_105 != V_136 &&
V_105 != V_122 &&
V_105 != 0 )
return - V_227 ;
return 0 ;
}
static void F_152 ( struct V_247 * V_77 [] ,
struct V_46 * V_40 )
{
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
if ( ! V_77 )
return;
if ( V_77 [ V_250 ] )
V_40 -> V_148 = F_153 ( V_77 [ V_250 ] ) ;
if ( V_77 [ V_251 ] )
F_154 ( & V_40 -> V_41 , V_77 [ V_251 ] ,
sizeof( struct V_1 ) ) ;
if ( V_77 [ V_252 ] )
F_154 ( & V_40 -> V_42 , V_77 [ V_252 ] ,
sizeof( struct V_1 ) ) ;
if ( V_77 [ V_253 ] )
V_40 -> V_187 = F_151 ( V_77 [ V_253 ] ) ;
if ( V_77 [ V_254 ] )
V_40 -> V_112 = F_151 ( V_77 [ V_254 ] ) ;
if ( V_77 [ V_255 ] )
V_40 -> V_207 = F_155 ( V_77 [ V_255 ] ) ;
if ( V_77 [ V_256 ] )
V_40 -> V_43 = F_153 ( V_77 [ V_256 ] ) ;
if ( V_77 [ V_249 ] )
V_40 -> V_105 = F_151 ( V_77 [ V_249 ] ) ;
}
static int F_156 ( struct V_34 * V_257 , struct V_7 * V_8 ,
struct V_247 * V_248 [] , struct V_247 * V_77 [] )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_22 * V_258 ;
V_258 = F_28 ( V_8 ) ;
F_152 ( V_77 , & V_258 -> V_40 ) ;
if ( F_37 ( V_34 , & V_258 -> V_40 , 0 ) )
return - V_228 ;
return F_27 ( V_8 ) ;
}
static int F_157 ( struct V_7 * V_8 , struct V_247 * V_248 [] ,
struct V_247 * V_77 [] )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_46 V_47 ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_65 )
return - V_227 ;
F_152 ( V_77 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_47 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_8 != V_8 )
return - V_228 ;
} else
V_23 = F_28 ( V_8 ) ;
return F_135 ( V_23 , & V_47 ) ;
}
static void F_158 ( struct V_7 * V_8 , struct V_259 * V_260 )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 != V_38 -> V_65 )
F_159 ( V_8 , V_260 ) ;
}
static T_10 F_160 ( const struct V_7 * V_8 )
{
return
F_161 ( 4 ) +
F_161 ( sizeof( struct V_1 ) ) +
F_161 ( sizeof( struct V_1 ) ) +
F_161 ( 1 ) +
F_161 ( 1 ) +
F_161 ( 4 ) +
F_161 ( 4 ) +
F_161 ( 1 ) +
0 ;
}
static int F_162 ( struct V_66 * V_67 , const struct V_7 * V_8 )
{
struct V_22 * V_261 = F_28 ( V_8 ) ;
struct V_46 * V_262 = & V_261 -> V_40 ;
if ( F_163 ( V_67 , V_250 , V_262 -> V_148 ) ||
F_164 ( V_67 , V_251 , sizeof( struct V_1 ) ,
& V_262 -> V_41 ) ||
F_164 ( V_67 , V_252 , sizeof( struct V_1 ) ,
& V_262 -> V_42 ) ||
F_165 ( V_67 , V_253 , V_262 -> V_187 ) ||
F_165 ( V_67 , V_254 , V_262 -> V_112 ) ||
F_166 ( V_67 , V_255 , V_262 -> V_207 ) ||
F_163 ( V_67 , V_256 , V_262 -> V_43 ) ||
F_165 ( V_67 , V_249 , V_262 -> V_105 ) )
goto V_263;
return 0 ;
V_263:
return - V_180 ;
}
static void T_11 F_167 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_7 * V_8 , * V_264 ;
int V_48 ;
struct V_22 * V_23 ;
F_168 ( V_265 ) ;
F_169 (net, dev, aux)
if ( V_8 -> V_57 == & V_58 )
F_159 ( V_8 , & V_265 ) ;
for ( V_48 = 0 ; V_48 < V_266 ; V_48 ++ ) {
V_23 = F_22 ( V_38 -> V_267 [ V_48 ] ) ;
while ( V_23 != NULL ) {
if ( ! F_109 ( F_29 ( V_23 -> V_8 ) , V_34 ) )
F_159 ( V_23 -> V_8 , & V_265 ) ;
V_23 = F_22 ( V_23 -> V_52 ) ;
}
}
F_170 ( & V_265 ) ;
}
static int T_9 F_171 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_22 * V_23 = NULL ;
int V_54 ;
V_38 -> V_50 [ 0 ] = V_38 -> V_45 ;
V_38 -> V_50 [ 1 ] = V_38 -> V_267 ;
V_54 = - V_246 ;
V_38 -> V_65 = F_35 ( sizeof( struct V_22 ) , L_10 ,
V_60 , V_61 ) ;
if ( ! V_38 -> V_65 )
goto V_268;
F_36 ( V_38 -> V_65 , V_34 ) ;
V_38 -> V_65 -> V_57 = & V_58 ;
V_38 -> V_65 -> V_269 |= V_270 ;
V_54 = F_149 ( V_38 -> V_65 ) ;
if ( V_54 < 0 )
goto V_271;
V_54 = F_172 ( V_38 -> V_65 ) ;
if ( V_54 < 0 )
goto V_271;
V_23 = F_28 ( V_38 -> V_65 ) ;
strcpy ( V_23 -> V_40 . V_56 , V_38 -> V_65 -> V_56 ) ;
return 0 ;
V_271:
F_24 ( V_38 -> V_65 ) ;
V_268:
return V_54 ;
}
static void T_11 F_173 ( struct V_34 * V_34 )
{
F_174 () ;
F_167 ( V_34 ) ;
F_175 () ;
}
static int T_12 F_176 ( void )
{
int V_54 ;
V_54 = F_177 ( & V_272 ) ;
if ( V_54 < 0 )
goto V_273;
V_54 = F_178 ( & V_274 , V_275 ) ;
if ( V_54 < 0 ) {
F_179 ( L_11 , V_276 ) ;
goto V_277;
}
V_54 = F_178 ( & V_278 , V_279 ) ;
if ( V_54 < 0 ) {
F_179 ( L_12 , V_276 ) ;
goto V_280;
}
V_54 = F_180 ( & V_58 ) ;
if ( V_54 < 0 )
goto V_281;
return 0 ;
V_281:
F_181 ( & V_278 , V_279 ) ;
V_280:
F_181 ( & V_274 , V_275 ) ;
V_277:
F_182 ( & V_272 ) ;
V_273:
return V_54 ;
}
static void T_13 F_183 ( void )
{
F_184 ( & V_58 ) ;
if ( F_181 ( & V_274 , V_275 ) )
F_185 ( L_13 , V_276 ) ;
if ( F_181 ( & V_278 , V_279 ) )
F_185 ( L_14 , V_276 ) ;
F_182 ( & V_272 ) ;
}
