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
V_8 = F_35 ( sizeof ( * V_23 ) , V_56 , V_60 ) ;
if ( V_8 == NULL )
goto V_61;
F_36 ( V_8 , V_34 ) ;
V_23 = F_28 ( V_8 ) ;
V_23 -> V_40 = * V_47 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_54 = F_27 ( V_8 ) ;
if ( V_54 < 0 )
goto V_62;
return V_23 ;
V_62:
F_24 ( V_8 ) ;
V_61:
return NULL ;
}
static struct V_22 * F_37 ( struct V_34 * V_34 ,
struct V_46 * V_47 , int V_63 )
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
F_16 ( V_35 , & V_23 -> V_40 . V_42 ) )
return V_23 ;
}
if ( ! V_63 )
return NULL ;
return F_33 ( V_34 , V_47 ) ;
}
static void
F_38 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_64 )
F_39 ( V_38 -> V_45 [ 0 ] , NULL ) ;
else
F_23 ( V_38 , V_23 ) ;
F_11 ( V_23 ) ;
F_40 ( V_8 ) ;
}
T_3 F_41 ( struct V_65 * V_66 , T_4 * V_67 )
{
const struct V_68 * V_69 = ( const struct V_68 * ) V_67 ;
T_4 V_70 = V_69 -> V_70 ;
T_3 V_71 = sizeof ( * V_69 ) ;
while ( F_42 ( V_70 ) && V_70 != V_72 ) {
T_3 V_73 = 0 ;
struct V_74 * V_75 ;
if ( V_67 + V_71 + sizeof ( * V_75 ) > V_66 -> V_76 &&
! F_43 ( V_66 , V_67 - V_66 -> V_76 + V_71 + sizeof ( * V_75 ) ) )
break;
V_75 = (struct V_74 * ) ( V_67 + V_71 ) ;
if ( V_70 == V_77 ) {
struct V_78 * V_78 = (struct V_78 * ) V_75 ;
if ( V_78 -> V_79 )
break;
V_73 = 8 ;
} else if ( V_70 == V_80 ) {
V_73 = ( V_75 -> V_81 + 2 ) << 2 ;
} else {
V_73 = F_44 ( V_75 ) ;
}
if ( V_70 == V_82 ) {
T_3 V_12 = V_71 + 2 ;
while ( 1 ) {
struct V_83 * V_84 ;
if ( V_12 + sizeof ( * V_84 ) > V_71 + V_73 )
break;
V_84 = (struct V_83 * ) & V_67 [ V_12 ] ;
if ( V_84 -> type == V_85 &&
V_84 -> V_86 == 1 )
return V_12 ;
if ( V_84 -> type )
V_12 += V_84 -> V_86 + 2 ;
else
V_12 ++ ;
}
}
V_70 = V_75 -> V_70 ;
V_71 += V_73 ;
}
return 0 ;
}
static int
F_45 ( struct V_65 * V_66 , T_4 V_87 , struct V_88 * V_89 ,
T_5 * type , T_5 * V_90 , int * V_91 , T_6 * V_92 , int V_93 )
{
const struct V_68 * V_69 = ( const struct V_68 * ) V_66 -> V_76 ;
struct V_22 * V_23 ;
int V_94 = 0 ;
T_5 V_95 = V_96 ;
T_5 V_97 = V_98 ;
T_6 V_99 = 0 ;
T_3 V_100 ;
int V_54 = - V_101 ;
F_46 () ;
if ( ( V_23 = F_13 ( F_29 ( V_66 -> V_8 ) , & V_69 -> V_102 ,
& V_69 -> V_103 ) ) == NULL )
goto V_55;
if ( V_23 -> V_40 . V_104 != V_87 && V_23 -> V_40 . V_104 != 0 )
goto V_55;
V_54 = 0 ;
switch ( * type ) {
T_6 V_105 ;
struct V_83 * V_84 ;
T_6 V_106 ;
case V_96 :
F_47 ( L_2 ,
V_23 -> V_40 . V_56 ) ;
V_94 = 1 ;
break;
case V_107 :
if ( ( * V_90 ) == V_108 ) {
F_47 ( L_3 ,
V_23 -> V_40 . V_56 ) ;
V_94 = 1 ;
}
break;
case V_109 :
V_105 = 0 ;
if ( ( * V_90 ) == V_110 )
V_105 = F_41 ( V_66 , V_66 -> V_76 ) ;
if ( V_105 && V_105 == * V_92 - 2 ) {
V_84 = (struct V_83 * ) & V_66 -> V_76 [ V_105 ] ;
if ( V_84 -> V_111 == 0 ) {
F_47 ( L_4 ,
V_23 -> V_40 . V_56 ) ;
V_94 = 1 ;
}
} else {
F_47 ( L_5 ,
V_23 -> V_40 . V_56 ) ;
}
break;
case V_112 :
V_106 = * V_92 - V_93 ;
if ( V_106 < V_113 )
V_106 = V_113 ;
V_23 -> V_8 -> V_106 = V_106 ;
if ( ( V_100 = sizeof ( * V_69 ) + F_48 ( V_69 -> V_114 ) ) > V_106 ) {
V_95 = V_112 ;
V_97 = 0 ;
V_99 = V_106 ;
V_94 = 1 ;
}
break;
}
* type = V_95 ;
* V_90 = V_97 ;
* V_92 = V_99 ;
* V_91 = V_94 ;
V_55:
F_49 () ;
return V_54 ;
}
static int
F_50 ( struct V_65 * V_66 , struct V_88 * V_89 ,
T_5 type , T_5 V_90 , int V_93 , T_7 V_92 )
{
int V_94 = 0 ;
T_5 V_95 = type ;
T_5 V_97 = V_90 ;
T_6 V_99 = F_51 ( V_92 ) ;
int V_54 ;
struct V_65 * V_115 ;
const struct V_116 * V_117 ;
struct V_118 * V_31 ;
struct V_119 V_120 ;
V_54 = F_45 ( V_66 , V_121 , V_89 , & V_95 , & V_97 ,
& V_94 , & V_99 , V_93 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_94 == 0 )
return 0 ;
switch ( V_95 ) {
case V_96 :
if ( V_97 != V_98 )
return 0 ;
V_95 = V_122 ;
V_97 = V_123 ;
break;
case V_112 :
if ( V_97 != 0 )
return 0 ;
V_95 = V_122 ;
V_97 = V_124 ;
break;
case V_125 :
V_95 = V_126 ;
V_97 = V_127 ;
default:
return 0 ;
}
if ( ! F_43 ( V_66 , V_93 + sizeof( struct V_116 ) ) )
return 0 ;
V_115 = F_52 ( V_66 , V_128 ) ;
if ( ! V_115 )
return 0 ;
F_53 ( V_115 ) ;
F_54 ( V_115 , V_93 ) ;
F_55 ( V_115 ) ;
V_117 = F_56 ( V_115 ) ;
V_31 = F_57 ( F_29 ( V_66 -> V_8 ) , & V_120 , NULL ,
V_117 -> V_103 , 0 ,
0 , 0 ,
V_121 , F_58 ( V_117 -> V_129 ) , 0 ) ;
if ( F_59 ( V_31 ) )
goto V_55;
V_115 -> V_8 = V_31 -> V_24 . V_8 ;
if ( V_31 -> V_130 & V_131 ) {
F_60 ( V_31 ) ;
V_31 = NULL ;
V_31 = F_57 ( F_29 ( V_66 -> V_8 ) , & V_120 , NULL ,
V_117 -> V_102 , V_117 -> V_103 ,
0 , 0 ,
V_121 ,
F_58 ( V_117 -> V_129 ) , 0 ) ;
if ( F_59 ( V_31 ) ||
V_31 -> V_24 . V_8 -> type != V_132 ) {
if ( ! F_59 ( V_31 ) )
F_60 ( V_31 ) ;
goto V_55;
}
F_61 ( V_115 , & V_31 -> V_24 ) ;
} else {
F_60 ( V_31 ) ;
if ( F_62 ( V_115 , V_117 -> V_102 , V_117 -> V_103 , V_117 -> V_129 ,
V_115 -> V_8 ) ||
F_63 ( V_115 ) -> V_8 -> type != V_132 )
goto V_55;
}
if ( V_95 == V_122 && V_97 == V_124 ) {
if ( V_99 > F_64 ( F_63 ( V_115 ) ) )
goto V_55;
F_63 ( V_115 ) -> V_27 -> V_133 ( F_63 ( V_115 ) , NULL , V_115 , V_99 ) ;
}
if ( V_95 == V_126 )
F_63 ( V_115 ) -> V_27 -> V_134 ( F_63 ( V_115 ) , NULL , V_115 ) ;
F_65 ( V_115 , V_95 , V_97 , F_66 ( V_99 ) ) ;
V_55:
F_67 ( V_115 ) ;
return 0 ;
}
static int
F_68 ( struct V_65 * V_66 , struct V_88 * V_89 ,
T_5 type , T_5 V_90 , int V_93 , T_7 V_92 )
{
int V_94 = 0 ;
T_5 V_95 = type ;
T_5 V_97 = V_90 ;
T_6 V_99 = F_51 ( V_92 ) ;
int V_54 ;
V_54 = F_45 ( V_66 , V_135 , V_89 , & V_95 , & V_97 ,
& V_94 , & V_99 , V_93 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_94 && F_43 ( V_66 , V_93 + sizeof( struct V_68 ) ) ) {
struct V_30 * V_31 ;
struct V_65 * V_115 = F_52 ( V_66 , V_128 ) ;
if ( ! V_115 )
return 0 ;
F_53 ( V_115 ) ;
F_54 ( V_115 , V_93 ) ;
F_55 ( V_115 ) ;
V_31 = F_69 ( F_29 ( V_66 -> V_8 ) , & F_70 ( V_115 ) -> V_103 ,
NULL , 0 , 0 ) ;
if ( V_31 && V_31 -> V_24 . V_8 )
V_115 -> V_8 = V_31 -> V_24 . V_8 ;
F_71 ( V_115 , V_95 , V_97 , V_99 ) ;
F_72 ( V_31 ) ;
F_67 ( V_115 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_22 * V_23 ,
const struct V_68 * V_69 ,
struct V_65 * V_66 )
{
T_4 V_136 = F_74 ( V_69 ) & ~ V_137 ;
if ( V_23 -> V_40 . V_43 & V_138 )
F_75 ( F_56 ( V_66 ) , V_137 , V_136 ) ;
return F_76 ( V_69 , V_66 ) ;
}
static int F_77 ( const struct V_22 * V_23 ,
const struct V_68 * V_69 ,
struct V_65 * V_66 )
{
if ( V_23 -> V_40 . V_43 & V_138 )
F_78 ( F_74 ( V_69 ) , F_70 ( V_66 ) ) ;
return F_76 ( V_69 , V_66 ) ;
}
T_6 F_79 ( struct V_22 * V_23 ,
const struct V_1 * V_41 ,
const struct V_1 * V_42 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_139 = F_80 ( V_41 ) ;
int V_140 = F_80 ( V_42 ) ;
T_6 V_43 = 0 ;
if ( V_139 == V_141 || V_140 == V_141 ) {
V_43 = V_142 ;
} else if ( V_139 & ( V_143 | V_144 ) &&
V_140 & ( V_143 | V_144 ) &&
! ( ( V_139 | V_140 ) & V_145 ) &&
( ! ( ( V_139 | V_140 ) & V_146 ) || V_47 -> V_147 ) ) {
if ( V_139 & V_143 )
V_43 |= V_148 ;
if ( V_140 & V_143 )
V_43 |= V_149 ;
}
return V_43 ;
}
int F_81 ( struct V_22 * V_23 ,
const struct V_1 * V_41 ,
const struct V_1 * V_42 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_150 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_47 -> V_43 & V_149 ) ||
( ( V_47 -> V_43 & V_142 ) &&
( F_79 ( V_23 , V_41 , V_42 ) & V_149 ) ) ) {
struct V_7 * V_151 = NULL ;
if ( V_47 -> V_147 )
V_151 = F_82 ( V_34 , V_47 -> V_147 ) ;
if ( ( F_83 ( V_41 ) ||
F_84 ( F_85 ( V_34 , V_41 , V_151 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_34 , V_42 , NULL , 0 ) ) )
V_150 = 1 ;
}
return V_150 ;
}
static int F_86 ( struct V_65 * V_66 , T_3 V_152 ,
T_4 V_87 ,
int (* F_87)( const struct V_22 * V_23 ,
const struct V_68 * V_69 ,
struct V_65 * V_66 ) )
{
struct V_22 * V_23 ;
const struct V_68 * V_69 = F_70 ( V_66 ) ;
int V_54 ;
F_46 () ;
if ( ( V_23 = F_13 ( F_29 ( V_66 -> V_8 ) , & V_69 -> V_103 ,
& V_69 -> V_102 ) ) != NULL ) {
struct V_9 * V_14 ;
if ( V_23 -> V_40 . V_104 != V_87 && V_23 -> V_40 . V_104 != 0 ) {
F_49 () ;
goto V_153;
}
if ( ! F_88 ( NULL , V_154 , V_66 ) ) {
F_49 () ;
goto V_153;
}
if ( ! F_81 ( V_23 , & V_69 -> V_102 , & V_69 -> V_103 ) ) {
V_23 -> V_8 -> V_20 . V_155 ++ ;
F_49 () ;
goto V_153;
}
V_66 -> V_156 = V_66 -> V_157 ;
F_55 ( V_66 ) ;
V_66 -> V_152 = F_89 ( V_152 ) ;
memset ( V_66 -> V_158 , 0 , sizeof( struct V_88 ) ) ;
F_90 ( V_66 , V_23 -> V_8 , V_23 -> V_34 ) ;
V_54 = F_87 ( V_23 , V_69 , V_66 ) ;
if ( F_91 ( V_54 ) ) {
if ( V_159 )
F_92 ( L_6 ,
& V_69 -> V_103 ,
F_74 ( V_69 ) ) ;
if ( V_54 > 1 ) {
++ V_23 -> V_8 -> V_20 . V_160 ;
++ V_23 -> V_8 -> V_20 . V_161 ;
F_49 () ;
goto V_153;
}
}
V_14 = F_93 ( V_23 -> V_8 -> V_14 ) ;
F_94 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_66 -> V_100 ;
F_95 ( & V_14 -> V_15 ) ;
F_96 ( V_66 ) ;
F_49 () ;
return 0 ;
}
F_49 () ;
return 1 ;
V_153:
F_67 ( V_66 ) ;
return 0 ;
}
static int F_97 ( struct V_65 * V_66 )
{
return F_86 ( V_66 , V_162 , V_121 ,
F_73 ) ;
}
static int F_98 ( struct V_65 * V_66 )
{
return F_86 ( V_66 , V_163 , V_135 ,
F_77 ) ;
}
static void F_99 ( struct V_164 * V_89 , T_4 V_111 )
{
memset ( V_89 , 0 , sizeof( struct V_164 ) ) ;
V_89 -> V_165 [ 2 ] = V_85 ;
V_89 -> V_165 [ 3 ] = 1 ;
V_89 -> V_165 [ 4 ] = V_111 ;
V_89 -> V_165 [ 5 ] = V_166 ;
V_89 -> V_165 [ 6 ] = 1 ;
V_89 -> V_27 . V_167 = (struct V_74 * ) V_89 -> V_165 ;
V_89 -> V_27 . V_168 = 8 ;
}
static inline bool
F_100 ( const struct V_22 * V_23 , const struct V_68 * V_75 )
{
return F_16 ( & V_23 -> V_40 . V_42 , & V_75 -> V_103 ) ;
}
int F_101 ( struct V_22 * V_23 )
{
struct V_46 * V_47 = & V_23 -> V_40 ;
int V_150 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( V_47 -> V_43 & V_148 ) {
struct V_7 * V_151 = NULL ;
F_46 () ;
if ( V_47 -> V_147 )
V_151 = F_82 ( V_34 , V_47 -> V_147 ) ;
if ( F_91 ( ! F_85 ( V_34 , & V_47 -> V_41 , V_151 , 0 ) ) )
F_102 ( L_7 ,
V_47 -> V_56 ) ;
else if ( ! F_83 ( & V_47 -> V_42 ) &&
F_91 ( F_85 ( V_34 , & V_47 -> V_42 , NULL , 0 ) ) )
F_102 ( L_8 ,
V_47 -> V_56 ) ;
else
V_150 = 1 ;
F_49 () ;
}
return V_150 ;
}
static int F_103 ( struct V_65 * V_66 ,
struct V_7 * V_8 ,
T_4 V_136 ,
struct V_169 * V_170 ,
int V_111 ,
T_6 * V_171 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
struct V_68 * V_69 = F_70 ( V_66 ) ;
struct V_164 V_89 ;
struct V_21 * V_24 = NULL , * V_172 = NULL ;
struct V_7 * V_173 ;
int V_106 ;
unsigned int V_174 = sizeof( struct V_68 ) ;
T_5 V_104 ;
int V_54 = - 1 ;
if ( ! V_170 -> V_175 )
V_24 = F_9 ( V_23 ) ;
if ( ! V_24 ) {
V_172 = F_104 ( V_34 , NULL , V_170 ) ;
if ( V_172 -> error )
goto V_176;
V_172 = F_105 ( V_34 , V_172 , F_106 ( V_170 ) , NULL , 0 ) ;
if ( F_59 ( V_172 ) ) {
V_54 = F_107 ( V_172 ) ;
V_172 = NULL ;
goto V_176;
}
V_24 = V_172 ;
}
V_173 = V_24 -> V_8 ;
if ( V_173 == V_8 ) {
V_20 -> V_177 ++ ;
F_47 ( L_9 ,
V_23 -> V_40 . V_56 ) ;
goto V_178;
}
V_106 = F_64 ( V_24 ) - sizeof ( * V_69 ) ;
if ( V_111 >= 0 ) {
V_174 += 8 ;
V_106 -= 8 ;
}
if ( V_106 < V_113 )
V_106 = V_113 ;
if ( F_63 ( V_66 ) )
F_63 ( V_66 ) -> V_27 -> V_133 ( F_63 ( V_66 ) , NULL , V_66 , V_106 ) ;
if ( V_66 -> V_100 > V_106 ) {
* V_171 = V_106 ;
V_54 = - V_179 ;
goto V_178;
}
F_108 ( V_66 , ! F_109 ( V_23 -> V_34 , F_29 ( V_8 ) ) ) ;
V_174 += F_110 ( V_173 ) ;
if ( F_111 ( V_66 ) < V_174 || F_112 ( V_66 ) ||
( F_113 ( V_66 ) && ! F_114 ( V_66 , 0 ) ) ) {
struct V_65 * V_180 ;
if ( ! ( V_180 = F_115 ( V_66 , V_174 ) ) )
goto V_178;
if ( V_66 -> V_181 )
F_116 ( V_180 , V_66 -> V_181 ) ;
F_117 ( V_66 ) ;
V_66 = V_180 ;
}
if ( V_170 -> V_175 ) {
F_61 ( V_66 , V_24 ) ;
V_172 = NULL ;
} else {
F_118 ( V_66 , V_24 ) ;
}
V_66 -> V_182 = V_66 -> V_157 ;
V_104 = V_170 -> V_183 ;
if ( V_111 >= 0 ) {
F_99 ( & V_89 , V_111 ) ;
F_119 ( V_66 , & V_89 . V_27 , & V_104 , NULL ) ;
}
if ( F_84 ( ! V_66 -> V_184 ) ) {
F_120 ( V_66 ) ;
V_66 -> V_184 = 1 ;
}
F_121 ( V_66 , sizeof( struct V_68 ) ) ;
F_55 ( V_66 ) ;
V_69 = F_70 ( V_66 ) ;
F_122 ( V_69 , F_123 ( 0 , V_136 ) , V_170 -> V_185 ) ;
V_69 -> V_186 = V_23 -> V_40 . V_186 ;
V_69 -> V_70 = V_104 ;
V_69 -> V_103 = V_170 -> V_103 ;
V_69 -> V_102 = V_170 -> V_102 ;
F_124 ( V_66 , V_8 ) ;
if ( V_172 )
F_12 ( V_23 , V_172 ) ;
return 0 ;
V_176:
V_20 -> V_187 ++ ;
F_125 ( V_66 ) ;
V_178:
F_10 ( V_172 ) ;
return V_54 ;
}
static inline int
F_126 ( struct V_65 * V_66 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
const struct V_116 * V_188 = F_56 ( V_66 ) ;
int V_111 = - 1 ;
struct V_169 V_170 ;
T_4 V_136 ;
T_6 V_106 ;
int V_54 ;
if ( ( V_23 -> V_40 . V_104 != V_121 && V_23 -> V_40 . V_104 != 0 ) ||
! F_101 ( V_23 ) )
return - 1 ;
if ( ! ( V_23 -> V_40 . V_43 & V_189 ) )
V_111 = V_23 -> V_40 . V_111 ;
memcpy ( & V_170 , & V_23 -> V_190 . V_191 . V_192 , sizeof ( V_170 ) ) ;
V_170 . V_183 = V_121 ;
V_136 = F_127 ( V_188 ) ;
if ( V_23 -> V_40 . V_43 & V_193 )
V_170 . V_185 |= F_66 ( ( T_6 ) V_188 -> V_129 << V_194 )
& V_195 ;
if ( V_23 -> V_40 . V_43 & V_196 )
V_170 . V_175 = V_66 -> V_197 ;
V_54 = F_103 ( V_66 , V_8 , V_136 , & V_170 , V_111 , & V_106 ) ;
if ( V_54 != 0 ) {
if ( V_54 == - V_179 )
F_65 ( V_66 , V_122 , V_124 ,
F_66 ( V_106 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_128 ( struct V_65 * V_66 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_68 * V_69 = F_70 ( V_66 ) ;
int V_111 = - 1 ;
T_3 V_93 ;
struct V_169 V_170 ;
T_4 V_136 ;
T_6 V_106 ;
int V_54 ;
if ( ( V_23 -> V_40 . V_104 != V_135 && V_23 -> V_40 . V_104 != 0 ) ||
! F_101 ( V_23 ) || F_100 ( V_23 , V_69 ) )
return - 1 ;
V_93 = F_41 ( V_66 , F_129 ( V_66 ) ) ;
if ( V_93 > 0 ) {
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) & F_129 ( V_66 ) [ V_93 ] ;
if ( V_84 -> V_111 == 0 ) {
F_71 ( V_66 , V_109 ,
V_110 , V_93 + 2 ) ;
return - 1 ;
}
V_111 = V_84 -> V_111 - 1 ;
} else if ( ! ( V_23 -> V_40 . V_43 & V_189 ) )
V_111 = V_23 -> V_40 . V_111 ;
memcpy ( & V_170 , & V_23 -> V_190 . V_191 . V_192 , sizeof ( V_170 ) ) ;
V_170 . V_183 = V_135 ;
V_136 = F_74 ( V_69 ) ;
if ( V_23 -> V_40 . V_43 & V_193 )
V_170 . V_185 |= ( * ( T_7 * ) V_69 & V_195 ) ;
if ( V_23 -> V_40 . V_43 & V_198 )
V_170 . V_185 |= F_130 ( V_69 ) ;
if ( V_23 -> V_40 . V_43 & V_196 )
V_170 . V_175 = V_66 -> V_197 ;
V_54 = F_103 ( V_66 , V_8 , V_136 , & V_170 , V_111 , & V_106 ) ;
if ( V_54 != 0 ) {
if ( V_54 == - V_179 )
F_71 ( V_66 , V_112 , 0 , V_106 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_131 ( struct V_65 * V_66 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
int V_150 ;
switch ( V_66 -> V_152 ) {
case F_89 ( V_162 ) :
V_150 = F_126 ( V_66 , V_8 ) ;
break;
case F_89 ( V_163 ) :
V_150 = F_128 ( V_66 , V_8 ) ;
break;
default:
goto V_199;
}
if ( V_150 < 0 )
goto V_199;
return V_200 ;
V_199:
V_20 -> V_201 ++ ;
V_20 -> V_202 ++ ;
F_67 ( V_66 ) ;
return V_200 ;
}
static void F_132 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_46 * V_47 = & V_23 -> V_40 ;
struct V_169 * V_170 = & V_23 -> V_190 . V_191 . V_192 ;
memcpy ( V_8 -> V_203 , & V_47 -> V_41 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_204 , & V_47 -> V_42 , sizeof( struct V_1 ) ) ;
V_170 -> V_103 = V_47 -> V_41 ;
V_170 -> V_102 = V_47 -> V_42 ;
V_170 -> V_205 = V_47 -> V_147 ;
V_170 -> V_185 = 0 ;
if ( ! ( V_47 -> V_43 & V_193 ) )
V_170 -> V_185 |= V_195 & V_47 -> V_206 ;
if ( ! ( V_47 -> V_43 & V_198 ) )
V_170 -> V_185 |= V_207 & V_47 -> V_206 ;
V_47 -> V_43 &= ~ ( V_148 | V_149 | V_142 ) ;
V_47 -> V_43 |= F_79 ( V_23 , & V_47 -> V_41 , & V_47 -> V_42 ) ;
if ( V_47 -> V_43 & V_148 && V_47 -> V_43 & V_149 )
V_8 -> V_43 |= V_208 ;
else
V_8 -> V_43 &= ~ V_208 ;
V_8 -> V_209 = V_47 -> V_147 ;
if ( V_47 -> V_43 & V_148 ) {
int V_210 = ( F_80 ( & V_47 -> V_42 ) &
( V_144 | V_146 ) ) ;
struct V_30 * V_31 = F_69 ( V_23 -> V_34 ,
& V_47 -> V_42 , & V_47 -> V_41 ,
V_47 -> V_147 , V_210 ) ;
if ( V_31 == NULL )
return;
if ( V_31 -> V_24 . V_8 ) {
V_8 -> V_211 = V_31 -> V_24 . V_8 -> V_211 +
sizeof ( struct V_68 ) ;
V_8 -> V_106 = V_31 -> V_24 . V_8 -> V_106 - sizeof ( struct V_68 ) ;
if ( ! ( V_23 -> V_40 . V_43 & V_189 ) )
V_8 -> V_106 -= 8 ;
if ( V_8 -> V_106 < V_113 )
V_8 -> V_106 = V_113 ;
}
F_72 ( V_31 ) ;
}
}
static int
F_133 ( struct V_22 * V_23 , const struct V_46 * V_47 )
{
V_23 -> V_40 . V_41 = V_47 -> V_41 ;
V_23 -> V_40 . V_42 = V_47 -> V_42 ;
V_23 -> V_40 . V_43 = V_47 -> V_43 ;
V_23 -> V_40 . V_186 = V_47 -> V_186 ;
V_23 -> V_40 . V_111 = V_47 -> V_111 ;
V_23 -> V_40 . V_206 = V_47 -> V_206 ;
V_23 -> V_40 . V_147 = V_47 -> V_147 ;
V_23 -> V_40 . V_104 = V_47 -> V_104 ;
F_11 ( V_23 ) ;
F_132 ( V_23 ) ;
return 0 ;
}
static int F_134 ( struct V_22 * V_23 , struct V_46 * V_47 )
{
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_54 ;
F_23 ( V_38 , V_23 ) ;
F_135 () ;
V_54 = F_133 ( V_23 , V_47 ) ;
F_20 ( V_38 , V_23 ) ;
F_136 ( V_23 -> V_8 ) ;
return V_54 ;
}
static void
F_137 ( struct V_46 * V_47 , const struct V_212 * V_191 )
{
V_47 -> V_41 = V_191 -> V_41 ;
V_47 -> V_42 = V_191 -> V_42 ;
V_47 -> V_43 = V_191 -> V_43 ;
V_47 -> V_186 = V_191 -> V_186 ;
V_47 -> V_111 = V_191 -> V_111 ;
V_47 -> V_206 = V_191 -> V_206 ;
V_47 -> V_147 = V_191 -> V_147 ;
V_47 -> V_104 = V_191 -> V_104 ;
memcpy ( V_47 -> V_56 , V_191 -> V_56 , sizeof( V_191 -> V_56 ) ) ;
}
static void
F_138 ( struct V_212 * V_191 , const struct V_46 * V_47 )
{
V_191 -> V_41 = V_47 -> V_41 ;
V_191 -> V_42 = V_47 -> V_42 ;
V_191 -> V_43 = V_47 -> V_43 ;
V_191 -> V_186 = V_47 -> V_186 ;
V_191 -> V_111 = V_47 -> V_111 ;
V_191 -> V_206 = V_47 -> V_206 ;
V_191 -> V_147 = V_47 -> V_147 ;
V_191 -> V_104 = V_47 -> V_104 ;
memcpy ( V_191 -> V_56 , V_47 -> V_56 , sizeof( V_191 -> V_56 ) ) ;
}
static int
F_139 ( struct V_7 * V_8 , struct V_213 * V_214 , int V_215 )
{
int V_54 = 0 ;
struct V_212 V_47 ;
struct V_46 V_216 ;
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
switch ( V_215 ) {
case V_217 :
if ( V_8 == V_38 -> V_64 ) {
if ( F_140 ( & V_47 , V_214 -> V_218 . V_219 , sizeof ( V_47 ) ) ) {
V_54 = - V_220 ;
break;
}
F_137 ( & V_216 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_216 , 0 ) ;
if ( V_23 == NULL )
V_23 = F_28 ( V_8 ) ;
} else {
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
}
F_138 ( & V_47 , & V_23 -> V_40 ) ;
if ( F_141 ( V_214 -> V_218 . V_219 , & V_47 , sizeof ( V_47 ) ) ) {
V_54 = - V_220 ;
}
break;
case V_221 :
case V_222 :
V_54 = - V_223 ;
if ( ! F_142 ( V_34 -> V_224 , V_225 ) )
break;
V_54 = - V_220 ;
if ( F_140 ( & V_47 , V_214 -> V_218 . V_219 , sizeof ( V_47 ) ) )
break;
V_54 = - V_226 ;
if ( V_47 . V_104 != V_135 && V_47 . V_104 != V_121 &&
V_47 . V_104 != 0 )
break;
F_137 ( & V_216 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_216 , V_215 == V_221 ) ;
if ( V_8 != V_38 -> V_64 && V_215 == V_222 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_8 != V_8 ) {
V_54 = - V_227 ;
break;
}
} else
V_23 = F_28 ( V_8 ) ;
V_54 = F_134 ( V_23 , & V_216 ) ;
}
if ( V_23 ) {
V_54 = 0 ;
F_138 ( & V_47 , & V_23 -> V_40 ) ;
if ( F_141 ( V_214 -> V_218 . V_219 , & V_47 , sizeof( V_47 ) ) )
V_54 = - V_220 ;
} else
V_54 = ( V_215 == V_221 ? - V_228 : - V_101 ) ;
break;
case V_229 :
V_54 = - V_223 ;
if ( ! F_142 ( V_34 -> V_224 , V_225 ) )
break;
if ( V_8 == V_38 -> V_64 ) {
V_54 = - V_220 ;
if ( F_140 ( & V_47 , V_214 -> V_218 . V_219 , sizeof ( V_47 ) ) )
break;
V_54 = - V_101 ;
F_137 ( & V_216 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_216 , 0 ) ;
if ( V_23 == NULL )
break;
V_54 = - V_223 ;
if ( V_23 -> V_8 == V_38 -> V_64 )
break;
V_8 = V_23 -> V_8 ;
}
V_54 = 0 ;
F_143 ( V_8 ) ;
break;
default:
V_54 = - V_226 ;
}
return V_54 ;
}
static int
F_144 ( struct V_7 * V_8 , int V_230 )
{
struct V_22 * V_231 = F_28 ( V_8 ) ;
if ( V_231 -> V_40 . V_104 == V_121 ) {
if ( V_230 < 68 )
return - V_226 ;
} else {
if ( V_230 < V_113 )
return - V_226 ;
}
if ( V_230 > 0xFFF8 - V_8 -> V_211 )
return - V_226 ;
V_8 -> V_106 = V_230 ;
return 0 ;
}
static void V_60 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_8 -> V_232 = & V_233 ;
V_8 -> V_234 = F_24 ;
V_8 -> type = V_235 ;
V_8 -> V_211 = V_236 + sizeof ( struct V_68 ) ;
V_8 -> V_106 = V_237 - sizeof ( struct V_68 ) ;
V_23 = F_28 ( V_8 ) ;
if ( ! ( V_23 -> V_40 . V_43 & V_189 ) )
V_8 -> V_106 -= 8 ;
V_8 -> V_43 |= V_238 ;
V_8 -> V_239 = sizeof( struct V_1 ) ;
V_8 -> V_240 &= ~ V_241 ;
V_8 -> V_242 = V_243 ;
F_145 ( V_8 -> V_244 ) ;
}
static inline int
F_146 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_8 -> V_14 = F_147 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_245 ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
int V_54 = F_146 ( V_8 ) ;
if ( V_54 )
return V_54 ;
F_132 ( V_23 ) ;
return 0 ;
}
static int T_9 F_148 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_54 = F_146 ( V_8 ) ;
if ( V_54 )
return V_54 ;
V_23 -> V_40 . V_104 = V_135 ;
F_32 ( V_8 ) ;
F_132 ( V_23 ) ;
F_21 ( V_38 -> V_45 [ 0 ] , V_23 ) ;
return 0 ;
}
static int F_149 ( struct V_246 * V_247 [] , struct V_246 * V_76 [] )
{
T_5 V_104 ;
if ( ! V_76 || ! V_76 [ V_248 ] )
return 0 ;
V_104 = F_150 ( V_76 [ V_248 ] ) ;
if ( V_104 != V_135 &&
V_104 != V_121 &&
V_104 != 0 )
return - V_226 ;
return 0 ;
}
static void F_151 ( struct V_246 * V_76 [] ,
struct V_46 * V_40 )
{
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
if ( ! V_76 )
return;
if ( V_76 [ V_249 ] )
V_40 -> V_147 = F_152 ( V_76 [ V_249 ] ) ;
if ( V_76 [ V_250 ] )
F_153 ( & V_40 -> V_41 , V_76 [ V_250 ] ,
sizeof( struct V_1 ) ) ;
if ( V_76 [ V_251 ] )
F_153 ( & V_40 -> V_42 , V_76 [ V_251 ] ,
sizeof( struct V_1 ) ) ;
if ( V_76 [ V_252 ] )
V_40 -> V_186 = F_150 ( V_76 [ V_252 ] ) ;
if ( V_76 [ V_253 ] )
V_40 -> V_111 = F_150 ( V_76 [ V_253 ] ) ;
if ( V_76 [ V_254 ] )
V_40 -> V_206 = F_154 ( V_76 [ V_254 ] ) ;
if ( V_76 [ V_255 ] )
V_40 -> V_43 = F_152 ( V_76 [ V_255 ] ) ;
if ( V_76 [ V_248 ] )
V_40 -> V_104 = F_150 ( V_76 [ V_248 ] ) ;
}
static int F_155 ( struct V_34 * V_256 , struct V_7 * V_8 ,
struct V_246 * V_247 [] , struct V_246 * V_76 [] )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_22 * V_257 ;
V_257 = F_28 ( V_8 ) ;
F_151 ( V_76 , & V_257 -> V_40 ) ;
if ( F_37 ( V_34 , & V_257 -> V_40 , 0 ) )
return - V_227 ;
return F_27 ( V_8 ) ;
}
static int F_156 ( struct V_7 * V_8 , struct V_246 * V_247 [] ,
struct V_246 * V_76 [] )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_46 V_47 ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_64 )
return - V_226 ;
F_151 ( V_76 , & V_47 ) ;
V_23 = F_37 ( V_34 , & V_47 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_8 != V_8 )
return - V_227 ;
} else
V_23 = F_28 ( V_8 ) ;
return F_134 ( V_23 , & V_47 ) ;
}
static void F_157 ( struct V_7 * V_8 , struct V_258 * V_259 )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 != V_38 -> V_64 )
F_158 ( V_8 , V_259 ) ;
}
static T_10 F_159 ( const struct V_7 * V_8 )
{
return
F_160 ( 4 ) +
F_160 ( sizeof( struct V_1 ) ) +
F_160 ( sizeof( struct V_1 ) ) +
F_160 ( 1 ) +
F_160 ( 1 ) +
F_160 ( 4 ) +
F_160 ( 4 ) +
F_160 ( 1 ) +
0 ;
}
static int F_161 ( struct V_65 * V_66 , const struct V_7 * V_8 )
{
struct V_22 * V_260 = F_28 ( V_8 ) ;
struct V_46 * V_261 = & V_260 -> V_40 ;
if ( F_162 ( V_66 , V_249 , V_261 -> V_147 ) ||
F_163 ( V_66 , V_250 , sizeof( struct V_1 ) ,
& V_261 -> V_41 ) ||
F_163 ( V_66 , V_251 , sizeof( struct V_1 ) ,
& V_261 -> V_42 ) ||
F_164 ( V_66 , V_252 , V_261 -> V_186 ) ||
F_164 ( V_66 , V_253 , V_261 -> V_111 ) ||
F_165 ( V_66 , V_254 , V_261 -> V_206 ) ||
F_162 ( V_66 , V_255 , V_261 -> V_43 ) ||
F_164 ( V_66 , V_248 , V_261 -> V_104 ) )
goto V_262;
return 0 ;
V_262:
return - V_179 ;
}
static void T_11 F_166 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_7 * V_8 , * V_263 ;
int V_48 ;
struct V_22 * V_23 ;
F_167 ( V_264 ) ;
F_168 (net, dev, aux)
if ( V_8 -> V_57 == & V_58 )
F_158 ( V_8 , & V_264 ) ;
for ( V_48 = 0 ; V_48 < V_265 ; V_48 ++ ) {
V_23 = F_22 ( V_38 -> V_266 [ V_48 ] ) ;
while ( V_23 != NULL ) {
if ( ! F_109 ( F_29 ( V_23 -> V_8 ) , V_34 ) )
F_158 ( V_23 -> V_8 , & V_264 ) ;
V_23 = F_22 ( V_23 -> V_52 ) ;
}
}
F_169 ( & V_264 ) ;
}
static int T_9 F_170 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_22 * V_23 = NULL ;
int V_54 ;
V_38 -> V_50 [ 0 ] = V_38 -> V_45 ;
V_38 -> V_50 [ 1 ] = V_38 -> V_266 ;
V_54 = - V_245 ;
V_38 -> V_64 = F_35 ( sizeof( struct V_22 ) , L_10 ,
V_60 ) ;
if ( ! V_38 -> V_64 )
goto V_267;
F_36 ( V_38 -> V_64 , V_34 ) ;
V_38 -> V_64 -> V_57 = & V_58 ;
V_38 -> V_64 -> V_268 |= V_269 ;
V_54 = F_148 ( V_38 -> V_64 ) ;
if ( V_54 < 0 )
goto V_270;
V_54 = F_171 ( V_38 -> V_64 ) ;
if ( V_54 < 0 )
goto V_270;
V_23 = F_28 ( V_38 -> V_64 ) ;
strcpy ( V_23 -> V_40 . V_56 , V_38 -> V_64 -> V_56 ) ;
return 0 ;
V_270:
F_24 ( V_38 -> V_64 ) ;
V_267:
return V_54 ;
}
static void T_11 F_172 ( struct V_34 * V_34 )
{
F_173 () ;
F_166 ( V_34 ) ;
F_174 () ;
}
static int T_12 F_175 ( void )
{
int V_54 ;
V_54 = F_176 ( & V_271 ) ;
if ( V_54 < 0 )
goto V_272;
V_54 = F_177 ( & V_273 , V_274 ) ;
if ( V_54 < 0 ) {
F_178 ( L_11 , V_275 ) ;
goto V_276;
}
V_54 = F_177 ( & V_277 , V_278 ) ;
if ( V_54 < 0 ) {
F_178 ( L_12 , V_275 ) ;
goto V_279;
}
V_54 = F_179 ( & V_58 ) ;
if ( V_54 < 0 )
goto V_280;
return 0 ;
V_280:
F_180 ( & V_277 , V_278 ) ;
V_279:
F_180 ( & V_273 , V_274 ) ;
V_276:
F_181 ( & V_271 ) ;
V_272:
return V_54 ;
}
static void T_13 F_182 ( void )
{
F_183 ( & V_58 ) ;
if ( F_180 ( & V_273 , V_274 ) )
F_184 ( L_13 , V_275 ) ;
if ( F_180 ( & V_277 , V_278 ) )
F_184 ( L_14 , V_275 ) ;
F_181 ( & V_271 ) ;
}
