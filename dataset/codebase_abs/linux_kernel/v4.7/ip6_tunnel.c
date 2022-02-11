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
static struct V_21 *
F_9 ( struct V_22 * V_22 , const struct V_1 * V_23 , const struct V_1 * V_24 )
{
unsigned int V_4 = F_1 ( V_23 , V_24 ) ;
struct V_21 * V_25 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_1 V_29 ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_12 ( V_23 , & V_25 -> V_30 . V_32 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_4 = F_1 ( & V_29 , V_24 ) ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_4 = F_1 ( V_23 , & V_29 ) ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_23 , & V_25 -> V_30 . V_32 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_25 = F_13 ( V_27 -> V_35 [ 0 ] ) ;
if ( V_25 && ( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
return NULL ;
}
static struct V_21 T_2 * *
F_14 ( struct V_26 * V_27 , const struct V_36 * V_37 )
{
const struct V_1 * V_23 = & V_37 -> V_32 ;
const struct V_1 * V_24 = & V_37 -> V_31 ;
unsigned int V_38 = 0 ;
int V_39 = 0 ;
if ( ! F_15 ( V_23 ) || ! F_15 ( V_24 ) ) {
V_39 = 1 ;
V_38 = F_1 ( V_23 , V_24 ) ;
}
return & V_27 -> V_40 [ V_39 ] [ V_38 ] ;
}
static void
F_16 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_41 = F_14 ( V_27 , & V_25 -> V_30 ) ;
F_17 ( V_25 -> V_42 , F_18 ( * V_41 ) ) ;
F_17 ( * V_41 , V_25 ) ;
}
static void
F_19 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_41 ;
struct V_21 * V_43 ;
for ( V_41 = F_14 ( V_27 , & V_25 -> V_30 ) ;
( V_43 = F_18 ( * V_41 ) ) != NULL ;
V_41 = & V_43 -> V_42 ) {
if ( V_25 == V_43 ) {
F_17 ( * V_41 , V_25 -> V_42 ) ;
break;
}
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
F_22 ( & V_25 -> V_44 ) ;
F_23 ( & V_25 -> V_45 ) ;
F_24 ( V_8 -> V_14 ) ;
F_25 ( V_8 ) ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_46 ;
V_25 = F_21 ( V_8 ) ;
V_8 -> V_47 = & V_48 ;
V_46 = F_28 ( V_8 ) ;
if ( V_46 < 0 )
goto V_49;
strcpy ( V_25 -> V_30 . V_50 , V_8 -> V_50 ) ;
F_29 ( V_8 ) ;
F_16 ( V_27 , V_25 ) ;
return 0 ;
V_49:
return V_46 ;
}
static struct V_21 * F_30 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
struct V_7 * V_8 ;
struct V_21 * V_25 ;
char V_50 [ V_51 ] ;
int V_46 = - V_52 ;
if ( V_37 -> V_50 [ 0 ] )
F_31 ( V_50 , V_37 -> V_50 , V_51 ) ;
else
sprintf ( V_50 , L_1 ) ;
V_8 = F_32 ( sizeof( * V_25 ) , V_50 , V_53 ,
V_54 ) ;
if ( ! V_8 )
goto V_55;
F_33 ( V_8 , V_22 ) ;
V_25 = F_21 ( V_8 ) ;
V_25 -> V_30 = * V_37 ;
V_25 -> V_22 = F_27 ( V_8 ) ;
V_46 = F_26 ( V_8 ) ;
if ( V_46 < 0 )
goto V_56;
return V_25 ;
V_56:
F_20 ( V_8 ) ;
V_55:
return F_34 ( V_46 ) ;
}
static struct V_21 * F_35 ( struct V_22 * V_22 ,
struct V_36 * V_37 , int V_57 )
{
const struct V_1 * V_23 = & V_37 -> V_32 ;
const struct V_1 * V_24 = & V_37 -> V_31 ;
struct V_21 T_2 * * V_41 ;
struct V_21 * V_25 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
for ( V_41 = F_14 ( V_27 , V_37 ) ;
( V_25 = F_18 ( * V_41 ) ) != NULL ;
V_41 = & V_25 -> V_42 ) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_12 ( V_23 , & V_25 -> V_30 . V_32 ) ) {
if ( V_57 )
return F_34 ( - V_58 ) ;
return V_25 ;
}
}
if ( ! V_57 )
return F_34 ( - V_59 ) ;
return F_30 ( V_22 , V_37 ) ;
}
static void
F_36 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 == V_27 -> V_60 )
F_37 ( V_27 -> V_35 [ 0 ] , NULL ) ;
else
F_19 ( V_27 , V_25 ) ;
F_38 ( & V_25 -> V_45 ) ;
F_39 ( V_8 ) ;
}
T_3 F_40 ( struct V_61 * V_62 , T_4 * V_63 )
{
const struct V_64 * V_65 = ( const struct V_64 * ) V_63 ;
T_4 V_66 = V_65 -> V_66 ;
T_3 V_67 = sizeof( * V_65 ) ;
while ( F_41 ( V_66 ) && V_66 != V_68 ) {
T_3 V_69 = 0 ;
struct V_70 * V_71 ;
if ( V_63 + V_67 + sizeof( * V_71 ) > V_62 -> V_72 &&
! F_42 ( V_62 , V_63 - V_62 -> V_72 + V_67 + sizeof ( * V_71 ) ) )
break;
V_71 = (struct V_70 * ) ( V_63 + V_67 ) ;
if ( V_66 == V_73 ) {
struct V_74 * V_74 = (struct V_74 * ) V_71 ;
if ( V_74 -> V_75 )
break;
V_69 = 8 ;
} else if ( V_66 == V_76 ) {
V_69 = ( V_71 -> V_77 + 2 ) << 2 ;
} else {
V_69 = F_43 ( V_71 ) ;
}
if ( V_66 == V_78 ) {
T_3 V_12 = V_67 + 2 ;
while ( 1 ) {
struct V_79 * V_80 ;
if ( V_12 + sizeof ( * V_80 ) > V_67 + V_69 )
break;
V_80 = (struct V_79 * ) & V_63 [ V_12 ] ;
if ( V_80 -> type == V_81 &&
V_80 -> V_82 == 1 )
return V_12 ;
if ( V_80 -> type )
V_12 += V_80 -> V_82 + 2 ;
else
V_12 ++ ;
}
}
V_66 = V_71 -> V_66 ;
V_67 += V_69 ;
}
return 0 ;
}
static int
F_44 ( struct V_61 * V_62 , T_4 V_83 , struct V_84 * V_85 ,
T_5 * type , T_5 * V_86 , int * V_87 , T_6 * V_88 , int V_89 )
{
const struct V_64 * V_65 = ( const struct V_64 * ) V_62 -> V_72 ;
struct V_21 * V_25 ;
int V_90 = 0 ;
T_5 V_91 = V_92 ;
T_5 V_93 = V_94 ;
T_5 V_95 ;
T_6 V_96 = 0 ;
T_3 V_97 ;
int V_46 = - V_98 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_62 -> V_8 ) , & V_65 -> V_99 , & V_65 -> V_100 ) ;
if ( ! V_25 )
goto V_49;
V_95 = F_46 ( V_25 -> V_30 . V_101 ) ;
if ( V_95 != V_83 && V_95 != 0 )
goto V_49;
V_46 = 0 ;
switch ( * type ) {
T_6 V_102 ;
struct V_79 * V_80 ;
T_6 V_103 ;
case V_92 :
F_47 ( L_2 ,
V_25 -> V_30 . V_50 ) ;
V_90 = 1 ;
break;
case V_104 :
if ( ( * V_86 ) == V_105 ) {
F_47 ( L_3 ,
V_25 -> V_30 . V_50 ) ;
V_90 = 1 ;
}
break;
case V_106 :
V_102 = 0 ;
if ( ( * V_86 ) == V_107 )
V_102 = F_40 ( V_62 , V_62 -> V_72 ) ;
if ( V_102 && V_102 == * V_88 - 2 ) {
V_80 = (struct V_79 * ) & V_62 -> V_72 [ V_102 ] ;
if ( V_80 -> V_108 == 0 ) {
F_47 ( L_4 ,
V_25 -> V_30 . V_50 ) ;
V_90 = 1 ;
}
} else {
F_47 ( L_5 ,
V_25 -> V_30 . V_50 ) ;
}
break;
case V_109 :
V_103 = * V_88 - V_89 ;
if ( V_103 < V_110 )
V_103 = V_110 ;
V_25 -> V_8 -> V_103 = V_103 ;
V_97 = sizeof( * V_65 ) + F_48 ( V_65 -> V_111 ) ;
if ( V_97 > V_103 ) {
V_91 = V_109 ;
V_93 = 0 ;
V_96 = V_103 ;
V_90 = 1 ;
}
break;
}
* type = V_91 ;
* V_86 = V_93 ;
* V_88 = V_96 ;
* V_87 = V_90 ;
V_49:
F_49 () ;
return V_46 ;
}
static int
F_50 ( struct V_61 * V_62 , struct V_84 * V_85 ,
T_5 type , T_5 V_86 , int V_89 , T_7 V_88 )
{
int V_90 = 0 ;
T_5 V_91 = type ;
T_5 V_93 = V_86 ;
T_6 V_96 = F_51 ( V_88 ) ;
int V_46 ;
struct V_61 * V_112 ;
const struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_117 V_118 ;
V_46 = F_44 ( V_62 , V_119 , V_85 , & V_91 , & V_93 ,
& V_90 , & V_96 , V_89 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_90 == 0 )
return 0 ;
switch ( V_91 ) {
case V_92 :
if ( V_93 != V_94 )
return 0 ;
V_91 = V_120 ;
V_93 = V_121 ;
break;
case V_109 :
if ( V_93 != 0 )
return 0 ;
V_91 = V_120 ;
V_93 = V_122 ;
break;
case V_123 :
V_91 = V_124 ;
V_93 = V_125 ;
default:
return 0 ;
}
if ( ! F_42 ( V_62 , V_89 + sizeof( struct V_113 ) ) )
return 0 ;
V_112 = F_52 ( V_62 , V_126 ) ;
if ( ! V_112 )
return 0 ;
F_53 ( V_112 ) ;
F_54 ( V_112 , V_89 ) ;
F_55 ( V_112 ) ;
V_114 = F_56 ( V_112 ) ;
V_116 = F_57 ( F_27 ( V_62 -> V_8 ) , & V_118 , NULL ,
V_114 -> V_100 , 0 ,
0 , 0 ,
V_119 , F_58 ( V_114 -> V_127 ) , 0 ) ;
if ( F_59 ( V_116 ) )
goto V_49;
V_112 -> V_8 = V_116 -> V_128 . V_8 ;
if ( V_116 -> V_129 & V_130 ) {
F_60 ( V_116 ) ;
V_116 = NULL ;
V_116 = F_57 ( F_27 ( V_62 -> V_8 ) , & V_118 , NULL ,
V_114 -> V_99 , V_114 -> V_100 ,
0 , 0 ,
V_119 ,
F_58 ( V_114 -> V_127 ) , 0 ) ;
if ( F_59 ( V_116 ) ||
V_116 -> V_128 . V_8 -> type != V_131 ) {
if ( ! F_59 ( V_116 ) )
F_60 ( V_116 ) ;
goto V_49;
}
F_61 ( V_112 , & V_116 -> V_128 ) ;
} else {
F_60 ( V_116 ) ;
if ( F_62 ( V_112 , V_114 -> V_99 , V_114 -> V_100 , V_114 -> V_127 ,
V_112 -> V_8 ) ||
F_63 ( V_112 ) -> V_8 -> type != V_131 )
goto V_49;
}
if ( V_91 == V_120 && V_93 == V_122 ) {
if ( V_96 > F_64 ( F_63 ( V_112 ) ) )
goto V_49;
F_63 ( V_112 ) -> V_132 -> V_133 ( F_63 ( V_112 ) , NULL , V_112 , V_96 ) ;
}
if ( V_91 == V_124 )
F_63 ( V_112 ) -> V_132 -> V_134 ( F_63 ( V_112 ) , NULL , V_112 ) ;
F_65 ( V_112 , V_91 , V_93 , F_66 ( V_96 ) ) ;
V_49:
F_67 ( V_112 ) ;
return 0 ;
}
static int
F_68 ( struct V_61 * V_62 , struct V_84 * V_85 ,
T_5 type , T_5 V_86 , int V_89 , T_7 V_88 )
{
int V_90 = 0 ;
T_5 V_91 = type ;
T_5 V_93 = V_86 ;
T_6 V_96 = F_51 ( V_88 ) ;
int V_46 ;
V_46 = F_44 ( V_62 , V_135 , V_85 , & V_91 , & V_93 ,
& V_90 , & V_96 , V_89 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_90 && F_42 ( V_62 , V_89 + sizeof( struct V_64 ) ) ) {
struct V_136 * V_116 ;
struct V_61 * V_112 = F_52 ( V_62 , V_126 ) ;
if ( ! V_112 )
return 0 ;
F_53 ( V_112 ) ;
F_54 ( V_112 , V_89 ) ;
F_55 ( V_112 ) ;
V_116 = F_69 ( F_27 ( V_62 -> V_8 ) , & F_70 ( V_112 ) -> V_100 ,
NULL , 0 , 0 ) ;
if ( V_116 && V_116 -> V_128 . V_8 )
V_112 -> V_8 = V_116 -> V_128 . V_8 ;
F_71 ( V_112 , V_91 , V_93 , V_96 ) ;
F_72 ( V_116 ) ;
F_67 ( V_112 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_21 * V_25 ,
const struct V_64 * V_65 ,
struct V_61 * V_62 )
{
T_4 V_137 = F_74 ( V_65 ) & ~ V_138 ;
if ( V_25 -> V_30 . V_33 & V_139 )
F_75 ( F_56 ( V_62 ) , V_138 , V_137 ) ;
return F_76 ( V_65 , V_62 ) ;
}
static int F_77 ( const struct V_21 * V_25 ,
const struct V_64 * V_65 ,
struct V_61 * V_62 )
{
if ( V_25 -> V_30 . V_33 & V_139 )
F_78 ( F_74 ( V_65 ) , F_70 ( V_62 ) ) ;
return F_76 ( V_65 , V_62 ) ;
}
T_6 F_79 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_140 = F_80 ( V_31 ) ;
int V_141 = F_80 ( V_32 ) ;
T_6 V_33 = 0 ;
if ( V_140 == V_142 || V_141 == V_142 ) {
V_33 = V_143 ;
} else if ( V_140 & ( V_144 | V_145 ) &&
V_141 & ( V_144 | V_145 ) &&
! ( ( V_140 | V_141 ) & V_146 ) &&
( ! ( ( V_140 | V_141 ) & V_147 ) || V_37 -> V_148 ) ) {
if ( V_140 & V_144 )
V_33 |= V_149 ;
if ( V_141 & V_144 )
V_33 |= V_150 ;
}
return V_33 ;
}
int F_81 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_151 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_37 -> V_33 & V_150 ) ||
( ( V_37 -> V_33 & V_143 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_150 ) ) ) {
struct V_7 * V_152 = NULL ;
if ( V_37 -> V_148 )
V_152 = F_82 ( V_22 , V_37 -> V_148 ) ;
if ( ( F_83 ( V_31 ) ||
F_84 ( F_85 ( V_22 , V_31 , V_152 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_22 , V_32 , NULL , 0 ) ) )
V_151 = 1 ;
}
return V_151 ;
}
static int F_86 ( struct V_21 * V_153 , struct V_61 * V_62 ,
const struct V_154 * V_155 ,
struct V_156 * V_157 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_64 * V_65 ,
struct V_61 * V_62 ) ,
bool V_158 )
{
struct V_9 * V_14 ;
const struct V_64 * V_65 = F_70 ( V_62 ) ;
int V_46 ;
if ( ( ! ( V_155 -> V_33 & V_159 ) &&
( V_153 -> V_30 . V_160 & V_159 ) ) ||
( ( V_155 -> V_33 & V_159 ) &&
! ( V_153 -> V_30 . V_160 & V_159 ) ) ) {
V_153 -> V_8 -> V_20 . V_161 ++ ;
V_153 -> V_8 -> V_20 . V_162 ++ ;
goto V_163;
}
if ( V_153 -> V_30 . V_160 & V_164 ) {
if ( ! ( V_155 -> V_33 & V_164 ) ||
( V_153 -> V_165 &&
( V_166 ) ( F_51 ( V_155 -> V_167 ) - V_153 -> V_165 ) < 0 ) ) {
V_153 -> V_8 -> V_20 . V_168 ++ ;
V_153 -> V_8 -> V_20 . V_162 ++ ;
goto V_163;
}
V_153 -> V_165 = F_51 ( V_155 -> V_167 ) + 1 ;
}
V_62 -> V_169 = V_155 -> V_101 ;
if ( V_153 -> V_8 -> type == V_170 ) {
if ( ! F_42 ( V_62 , V_171 ) ) {
V_153 -> V_8 -> V_20 . V_172 ++ ;
V_153 -> V_8 -> V_20 . V_162 ++ ;
goto V_163;
}
V_65 = F_70 ( V_62 ) ;
V_62 -> V_169 = F_88 ( V_62 , V_153 -> V_8 ) ;
F_89 ( V_62 , F_90 ( V_62 ) , V_171 ) ;
} else {
V_62 -> V_8 = V_153 -> V_8 ;
}
F_55 ( V_62 ) ;
memset ( V_62 -> V_173 , 0 , sizeof( struct V_84 ) ) ;
F_91 ( V_62 , V_153 -> V_8 , V_153 -> V_22 ) ;
V_46 = F_87 ( V_153 , V_65 , V_62 ) ;
if ( F_92 ( V_46 ) ) {
if ( V_158 )
F_93 ( L_6 ,
& V_65 -> V_100 ,
F_74 ( V_65 ) ) ;
if ( V_46 > 1 ) {
++ V_153 -> V_8 -> V_20 . V_174 ;
++ V_153 -> V_8 -> V_20 . V_162 ;
goto V_163;
}
}
V_14 = F_94 ( V_153 -> V_8 -> V_14 ) ;
F_95 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_62 -> V_97 ;
F_96 ( & V_14 -> V_15 ) ;
F_97 ( V_62 , ! F_98 ( V_153 -> V_22 , F_27 ( V_153 -> V_8 ) ) ) ;
F_99 ( & V_153 -> V_44 , V_62 ) ;
return 0 ;
V_163:
F_67 ( V_62 ) ;
return 0 ;
}
int F_100 ( struct V_21 * V_25 , struct V_61 * V_62 ,
const struct V_154 * V_155 ,
struct V_156 * V_157 ,
bool V_158 )
{
return F_86 ( V_25 , V_62 , V_155 , NULL , F_77 ,
V_158 ) ;
}
static int F_101 ( struct V_61 * V_62 , T_5 V_83 ,
const struct V_154 * V_155 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_64 * V_65 ,
struct V_61 * V_62 ) )
{
struct V_21 * V_25 ;
const struct V_64 * V_65 = F_70 ( V_62 ) ;
int V_151 = - 1 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_62 -> V_8 ) , & V_65 -> V_100 , & V_65 -> V_99 ) ;
if ( V_25 ) {
T_5 V_95 = F_46 ( V_25 -> V_30 . V_101 ) ;
if ( V_95 != V_83 && V_95 != 0 )
goto V_163;
if ( ! F_102 ( NULL , V_175 , V_62 ) )
goto V_163;
if ( ! F_81 ( V_25 , & V_65 -> V_99 , & V_65 -> V_100 ) )
goto V_163;
if ( F_103 ( V_62 , 0 , V_155 -> V_101 , false ) )
goto V_163;
V_151 = F_86 ( V_25 , V_62 , V_155 , NULL , F_87 ,
V_176 ) ;
}
F_49 () ;
return V_151 ;
V_163:
F_49 () ;
F_67 ( V_62 ) ;
return 0 ;
}
static int F_104 ( struct V_61 * V_62 )
{
return F_101 ( V_62 , V_119 , & V_177 ,
F_73 ) ;
}
static int F_105 ( struct V_61 * V_62 )
{
return F_101 ( V_62 , V_135 , & V_178 ,
F_77 ) ;
}
static void F_106 ( struct V_179 * V_85 , T_4 V_108 )
{
memset ( V_85 , 0 , sizeof( struct V_179 ) ) ;
V_85 -> V_180 [ 2 ] = V_81 ;
V_85 -> V_180 [ 3 ] = 1 ;
V_85 -> V_180 [ 4 ] = V_108 ;
V_85 -> V_180 [ 5 ] = V_181 ;
V_85 -> V_180 [ 6 ] = 1 ;
V_85 -> V_132 . V_182 = (struct V_70 * ) V_85 -> V_180 ;
V_85 -> V_132 . V_183 = 8 ;
}
static inline bool
F_107 ( const struct V_21 * V_25 , const struct V_64 * V_71 )
{
return F_12 ( & V_25 -> V_30 . V_32 , & V_71 -> V_100 ) ;
}
int F_108 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_151 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_37 -> V_33 & V_149 ) ||
( ( V_37 -> V_33 & V_143 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_149 ) ) ) {
struct V_7 * V_152 = NULL ;
F_45 () ;
if ( V_37 -> V_148 )
V_152 = F_82 ( V_22 , V_37 -> V_148 ) ;
if ( F_92 ( ! F_85 ( V_22 , V_31 , V_152 , 0 ) ) )
F_109 ( L_7 ,
V_37 -> V_50 ) ;
else if ( ! F_83 ( V_32 ) &&
F_92 ( F_85 ( V_22 , V_32 , NULL , 0 ) ) )
F_109 ( L_8 ,
V_37 -> V_50 ) ;
else
V_151 = 1 ;
F_49 () ;
}
return V_151 ;
}
int F_110 ( struct V_61 * V_62 , struct V_7 * V_8 , T_4 V_137 ,
struct V_184 * V_185 , int V_108 , T_6 * V_186 ,
T_4 V_101 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
struct V_64 * V_65 = F_70 ( V_62 ) ;
struct V_179 V_85 ;
struct V_187 * V_128 = NULL , * V_188 = NULL ;
struct V_7 * V_189 ;
int V_103 ;
unsigned int V_190 = sizeof( struct V_64 ) + V_25 -> V_191 ;
unsigned int V_192 = V_190 ;
int V_46 = - 1 ;
if ( F_15 ( & V_25 -> V_30 . V_32 ) ) {
struct V_1 * V_193 ;
struct V_194 * V_195 ;
int V_196 ;
if ( ! F_63 ( V_62 ) )
goto V_197;
V_195 = F_111 ( F_63 ( V_62 ) ,
& F_70 ( V_62 ) -> V_99 ) ;
if ( ! V_195 )
goto V_197;
V_193 = (struct V_1 * ) & V_195 -> V_198 ;
V_196 = F_80 ( V_193 ) ;
if ( V_196 == V_142 )
V_193 = & F_70 ( V_62 ) -> V_99 ;
memcpy ( & V_185 -> V_99 , V_193 , sizeof( V_185 -> V_99 ) ) ;
F_112 ( V_195 ) ;
} else if ( ! V_185 -> V_199 )
V_128 = F_113 ( & V_25 -> V_45 ) ;
if ( ! F_108 ( V_25 , & V_185 -> V_100 , & V_185 -> V_99 ) )
goto V_197;
if ( ! V_128 ) {
V_128 = F_114 ( V_22 , NULL , V_185 ) ;
if ( V_128 -> error )
goto V_197;
V_128 = F_115 ( V_22 , V_128 , F_116 ( V_185 ) , NULL , 0 ) ;
if ( F_59 ( V_128 ) ) {
V_46 = F_117 ( V_128 ) ;
V_128 = NULL ;
goto V_197;
}
V_188 = V_128 ;
}
V_189 = V_128 -> V_8 ;
if ( V_189 == V_8 ) {
V_20 -> V_200 ++ ;
F_118 ( L_9 ,
V_25 -> V_30 . V_50 ) ;
goto V_201;
}
V_103 = F_64 ( V_128 ) - V_190 ;
if ( V_108 >= 0 ) {
V_192 += 8 ;
V_103 -= 8 ;
}
if ( V_103 < V_110 )
V_103 = V_110 ;
if ( F_63 ( V_62 ) )
F_63 ( V_62 ) -> V_132 -> V_133 ( F_63 ( V_62 ) , NULL , V_62 , V_103 ) ;
if ( V_62 -> V_97 > V_103 && ! F_119 ( V_62 ) ) {
* V_186 = V_103 ;
V_46 = - V_202 ;
goto V_201;
}
if ( V_25 -> V_203 > 0 ) {
if ( F_120 ( V_204 ,
V_25 -> V_205 + V_206 ) ) {
V_25 -> V_203 -- ;
F_121 ( V_62 ) ;
} else {
V_25 -> V_203 = 0 ;
}
}
F_97 ( V_62 , ! F_98 ( V_25 -> V_22 , F_27 ( V_8 ) ) ) ;
V_192 += F_122 ( V_189 ) ;
if ( F_123 ( V_62 ) < V_192 || F_124 ( V_62 ) ||
( F_125 ( V_62 ) && ! F_126 ( V_62 , 0 ) ) ) {
struct V_61 * V_207 ;
V_207 = F_127 ( V_62 , V_192 ) ;
if ( ! V_207 )
goto V_201;
if ( V_62 -> V_208 )
F_128 ( V_207 , V_62 -> V_208 ) ;
F_129 ( V_62 ) ;
V_62 = V_207 ;
}
if ( ! V_185 -> V_199 && V_188 )
F_130 ( & V_25 -> V_45 , V_188 , & V_185 -> V_100 ) ;
F_61 ( V_62 , V_128 ) ;
if ( V_108 >= 0 ) {
F_106 ( & V_85 , V_108 ) ;
F_131 ( V_62 , & V_85 . V_132 , & V_101 , NULL ) ;
}
V_192 = F_122 ( V_128 -> V_8 ) + sizeof( struct V_64 )
+ V_128 -> V_209 + V_25 -> V_210 ;
if ( V_192 > V_8 -> V_211 )
V_8 -> V_211 = V_192 ;
V_46 = F_132 ( V_62 , V_25 , & V_101 , V_185 ) ;
if ( V_46 )
return V_46 ;
F_133 ( V_62 , sizeof( struct V_64 ) ) ;
F_55 ( V_62 ) ;
V_65 = F_70 ( V_62 ) ;
F_134 ( V_65 , F_135 ( 0 , V_137 ) ,
F_136 ( V_22 , V_62 , V_185 -> V_212 , true , V_185 ) ) ;
V_65 -> V_213 = V_25 -> V_30 . V_213 ;
V_65 -> V_66 = V_101 ;
V_65 -> V_100 = V_185 -> V_100 ;
V_65 -> V_99 = V_185 -> V_99 ;
F_137 ( NULL , V_62 , V_8 ) ;
return 0 ;
V_197:
V_20 -> V_214 ++ ;
F_121 ( V_62 ) ;
V_201:
F_138 ( V_128 ) ;
return V_46 ;
}
static inline int
F_139 ( struct V_61 * V_62 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
const struct V_113 * V_215 = F_56 ( V_62 ) ;
int V_108 = - 1 ;
struct V_184 V_185 ;
T_4 V_137 ;
T_6 V_103 ;
T_5 V_95 ;
int V_46 ;
memset ( & ( F_140 ( V_62 ) -> V_85 ) , 0 , sizeof( F_140 ( V_62 ) -> V_85 ) ) ;
V_95 = F_46 ( V_25 -> V_30 . V_101 ) ;
if ( V_95 != V_119 && V_95 != 0 )
return - 1 ;
if ( ! ( V_25 -> V_30 . V_33 & V_216 ) )
V_108 = V_25 -> V_30 . V_108 ;
memcpy ( & V_185 , & V_25 -> V_217 . V_218 . V_219 , sizeof( V_185 ) ) ;
V_137 = F_141 ( V_215 ) ;
if ( V_25 -> V_30 . V_33 & V_220 )
V_185 . V_212 |= F_66 ( ( T_6 ) V_215 -> V_127 << V_221 )
& V_222 ;
if ( V_25 -> V_30 . V_33 & V_223 )
V_185 . V_199 = V_62 -> V_224 ;
if ( F_142 ( V_62 , V_225 ) )
return - 1 ;
F_143 ( V_62 , V_119 ) ;
V_46 = F_110 ( V_62 , V_8 , V_137 , & V_185 , V_108 , & V_103 ,
V_119 ) ;
if ( V_46 != 0 ) {
if ( V_46 == - V_202 )
F_65 ( V_62 , V_120 , V_122 ,
F_66 ( V_103 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_144 ( struct V_61 * V_62 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_64 * V_65 = F_70 ( V_62 ) ;
int V_108 = - 1 ;
T_3 V_89 ;
struct V_184 V_185 ;
T_4 V_137 ;
T_6 V_103 ;
T_5 V_95 ;
int V_46 ;
V_95 = F_46 ( V_25 -> V_30 . V_101 ) ;
if ( ( V_95 != V_135 && V_95 != 0 ) ||
F_107 ( V_25 , V_65 ) )
return - 1 ;
V_89 = F_40 ( V_62 , F_145 ( V_62 ) ) ;
if ( V_89 > 0 ) {
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) & F_145 ( V_62 ) [ V_89 ] ;
if ( V_80 -> V_108 == 0 ) {
F_71 ( V_62 , V_106 ,
V_107 , V_89 + 2 ) ;
return - 1 ;
}
V_108 = V_80 -> V_108 - 1 ;
} else if ( ! ( V_25 -> V_30 . V_33 & V_216 ) )
V_108 = V_25 -> V_30 . V_108 ;
memcpy ( & V_185 , & V_25 -> V_217 . V_218 . V_219 , sizeof( V_185 ) ) ;
V_137 = F_74 ( V_65 ) ;
if ( V_25 -> V_30 . V_33 & V_220 )
V_185 . V_212 |= ( * ( T_7 * ) V_65 & V_222 ) ;
if ( V_25 -> V_30 . V_33 & V_226 )
V_185 . V_212 |= F_146 ( V_65 ) ;
if ( V_25 -> V_30 . V_33 & V_223 )
V_185 . V_199 = V_62 -> V_224 ;
if ( F_142 ( V_62 , V_225 ) )
return - 1 ;
F_143 ( V_62 , V_135 ) ;
V_46 = F_110 ( V_62 , V_8 , V_137 , & V_185 , V_108 , & V_103 ,
V_135 ) ;
if ( V_46 != 0 ) {
if ( V_46 == - V_202 )
F_71 ( V_62 , V_109 , 0 , V_103 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_147 ( struct V_61 * V_62 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
int V_151 ;
switch ( V_62 -> V_169 ) {
case F_148 ( V_227 ) :
V_151 = F_139 ( V_62 , V_8 ) ;
break;
case F_148 ( V_228 ) :
V_151 = F_144 ( V_62 , V_8 ) ;
break;
default:
goto V_229;
}
if ( V_151 < 0 )
goto V_229;
return V_230 ;
V_229:
V_20 -> V_231 ++ ;
V_20 -> V_232 ++ ;
F_67 ( V_62 ) ;
return V_230 ;
}
static void F_149 ( struct V_21 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_36 * V_37 = & V_25 -> V_30 ;
struct V_184 * V_185 = & V_25 -> V_217 . V_218 . V_219 ;
int V_233 ;
memcpy ( V_8 -> V_234 , & V_37 -> V_31 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_235 , & V_37 -> V_32 , sizeof( struct V_1 ) ) ;
V_185 -> V_100 = V_37 -> V_31 ;
V_185 -> V_99 = V_37 -> V_32 ;
V_185 -> V_236 = V_37 -> V_148 ;
V_185 -> V_212 = 0 ;
if ( ! ( V_37 -> V_33 & V_220 ) )
V_185 -> V_212 |= V_222 & V_37 -> V_237 ;
if ( ! ( V_37 -> V_33 & V_226 ) )
V_185 -> V_212 |= V_238 & V_37 -> V_237 ;
V_37 -> V_33 &= ~ ( V_149 | V_150 | V_143 ) ;
V_37 -> V_33 |= F_79 ( V_25 , & V_37 -> V_31 , & V_37 -> V_32 ) ;
if ( V_37 -> V_33 & V_149 && V_37 -> V_33 & V_150 )
V_8 -> V_33 |= V_239 ;
else
V_8 -> V_33 &= ~ V_239 ;
V_25 -> V_240 = 0 ;
V_25 -> V_210 = V_25 -> V_191 + V_25 -> V_240 ;
V_233 = V_25 -> V_210 + sizeof( struct V_64 ) ;
if ( V_37 -> V_33 & V_149 ) {
int V_241 = ( F_80 ( & V_37 -> V_32 ) &
( V_145 | V_147 ) ) ;
struct V_136 * V_116 = F_69 ( V_25 -> V_22 ,
& V_37 -> V_32 , & V_37 -> V_31 ,
V_37 -> V_148 , V_241 ) ;
if ( ! V_116 )
return;
if ( V_116 -> V_128 . V_8 ) {
V_8 -> V_242 = V_116 -> V_128 . V_8 -> V_242 +
V_233 ;
V_8 -> V_103 = V_116 -> V_128 . V_8 -> V_103 - V_233 ;
if ( ! ( V_25 -> V_30 . V_33 & V_216 ) )
V_8 -> V_103 -= 8 ;
if ( V_8 -> V_103 < V_110 )
V_8 -> V_103 = V_110 ;
}
F_72 ( V_116 ) ;
}
}
static int
F_150 ( struct V_21 * V_25 , const struct V_36 * V_37 )
{
V_25 -> V_30 . V_31 = V_37 -> V_31 ;
V_25 -> V_30 . V_32 = V_37 -> V_32 ;
V_25 -> V_30 . V_33 = V_37 -> V_33 ;
V_25 -> V_30 . V_213 = V_37 -> V_213 ;
V_25 -> V_30 . V_108 = V_37 -> V_108 ;
V_25 -> V_30 . V_237 = V_37 -> V_237 ;
V_25 -> V_30 . V_148 = V_37 -> V_148 ;
V_25 -> V_30 . V_101 = V_37 -> V_101 ;
F_38 ( & V_25 -> V_45 ) ;
F_149 ( V_25 ) ;
return 0 ;
}
static int F_151 ( struct V_21 * V_25 , struct V_36 * V_37 )
{
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_46 ;
F_19 ( V_27 , V_25 ) ;
F_152 () ;
V_46 = F_150 ( V_25 , V_37 ) ;
F_16 ( V_27 , V_25 ) ;
F_153 ( V_25 -> V_8 ) ;
return V_46 ;
}
static int F_154 ( struct V_21 * V_25 , struct V_36 * V_37 )
{
V_25 -> V_30 . V_101 = V_37 -> V_101 ;
F_153 ( V_25 -> V_8 ) ;
return 0 ;
}
static void
F_155 ( struct V_36 * V_37 , const struct V_243 * V_218 )
{
V_37 -> V_31 = V_218 -> V_31 ;
V_37 -> V_32 = V_218 -> V_32 ;
V_37 -> V_33 = V_218 -> V_33 ;
V_37 -> V_213 = V_218 -> V_213 ;
V_37 -> V_108 = V_218 -> V_108 ;
V_37 -> V_237 = V_218 -> V_237 ;
V_37 -> V_148 = V_218 -> V_148 ;
V_37 -> V_101 = V_218 -> V_101 ;
memcpy ( V_37 -> V_50 , V_218 -> V_50 , sizeof( V_218 -> V_50 ) ) ;
}
static void
F_156 ( struct V_243 * V_218 , const struct V_36 * V_37 )
{
V_218 -> V_31 = V_37 -> V_31 ;
V_218 -> V_32 = V_37 -> V_32 ;
V_218 -> V_33 = V_37 -> V_33 ;
V_218 -> V_213 = V_37 -> V_213 ;
V_218 -> V_108 = V_37 -> V_108 ;
V_218 -> V_237 = V_37 -> V_237 ;
V_218 -> V_148 = V_37 -> V_148 ;
V_218 -> V_101 = V_37 -> V_101 ;
memcpy ( V_218 -> V_50 , V_37 -> V_50 , sizeof( V_218 -> V_50 ) ) ;
}
static int
F_157 ( struct V_7 * V_8 , struct V_244 * V_245 , int V_246 )
{
int V_46 = 0 ;
struct V_243 V_37 ;
struct V_36 V_247 ;
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
switch ( V_246 ) {
case V_248 :
if ( V_8 == V_27 -> V_60 ) {
if ( F_158 ( & V_37 , V_245 -> V_249 . V_250 , sizeof( V_37 ) ) ) {
V_46 = - V_251 ;
break;
}
F_155 ( & V_247 , & V_37 ) ;
V_25 = F_35 ( V_22 , & V_247 , 0 ) ;
if ( F_59 ( V_25 ) )
V_25 = F_21 ( V_8 ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
F_156 ( & V_37 , & V_25 -> V_30 ) ;
if ( F_159 ( V_245 -> V_249 . V_250 , & V_37 , sizeof( V_37 ) ) ) {
V_46 = - V_251 ;
}
break;
case V_252 :
case V_253 :
V_46 = - V_254 ;
if ( ! F_160 ( V_22 -> V_255 , V_256 ) )
break;
V_46 = - V_251 ;
if ( F_158 ( & V_37 , V_245 -> V_249 . V_250 , sizeof( V_37 ) ) )
break;
V_46 = - V_257 ;
if ( V_37 . V_101 != V_135 && V_37 . V_101 != V_119 &&
V_37 . V_101 != 0 )
break;
F_155 ( & V_247 , & V_37 ) ;
V_25 = F_35 ( V_22 , & V_247 , V_246 == V_252 ) ;
if ( V_246 == V_253 ) {
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 ) {
V_46 = - V_58 ;
break;
}
} else
V_25 = F_21 ( V_8 ) ;
if ( V_8 == V_27 -> V_60 )
V_46 = F_154 ( V_25 , & V_247 ) ;
else
V_46 = F_151 ( V_25 , & V_247 ) ;
}
if ( ! F_59 ( V_25 ) ) {
V_46 = 0 ;
F_156 ( & V_37 , & V_25 -> V_30 ) ;
if ( F_159 ( V_245 -> V_249 . V_250 , & V_37 , sizeof( V_37 ) ) )
V_46 = - V_251 ;
} else {
V_46 = F_117 ( V_25 ) ;
}
break;
case V_258 :
V_46 = - V_254 ;
if ( ! F_160 ( V_22 -> V_255 , V_256 ) )
break;
if ( V_8 == V_27 -> V_60 ) {
V_46 = - V_251 ;
if ( F_158 ( & V_37 , V_245 -> V_249 . V_250 , sizeof( V_37 ) ) )
break;
V_46 = - V_98 ;
F_155 ( & V_247 , & V_37 ) ;
V_25 = F_35 ( V_22 , & V_247 , 0 ) ;
if ( F_59 ( V_25 ) )
break;
V_46 = - V_254 ;
if ( V_25 -> V_8 == V_27 -> V_60 )
break;
V_8 = V_25 -> V_8 ;
}
V_46 = 0 ;
F_161 ( V_8 ) ;
break;
default:
V_46 = - V_257 ;
}
return V_46 ;
}
int F_162 ( struct V_7 * V_8 , int V_259 )
{
struct V_21 * V_260 = F_21 ( V_8 ) ;
if ( V_260 -> V_30 . V_101 == V_119 ) {
if ( V_259 < 68 )
return - V_257 ;
} else {
if ( V_259 < V_110 )
return - V_257 ;
}
if ( V_259 > 0xFFF8 - V_8 -> V_242 )
return - V_257 ;
V_8 -> V_103 = V_259 ;
return 0 ;
}
int F_163 ( const struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
return V_25 -> V_30 . V_148 ;
}
int F_164 ( const struct V_261 * V_132 ,
unsigned int V_262 )
{
if ( V_262 >= V_263 )
return - V_264 ;
return ! F_165 ( ( const struct V_261 * * )
& V_265 [ V_262 ] ,
NULL , V_132 ) ? 0 : - 1 ;
}
int F_166 ( const struct V_261 * V_132 ,
unsigned int V_262 )
{
int V_151 ;
if ( V_262 >= V_263 )
return - V_264 ;
V_151 = ( F_165 ( ( const struct V_261 * * )
& V_265 [ V_262 ] ,
V_132 , NULL ) == V_132 ) ? 0 : - 1 ;
F_152 () ;
return V_151 ;
}
int F_167 ( struct V_21 * V_25 ,
struct V_266 * V_267 )
{
int V_210 ;
memset ( & V_25 -> V_268 , 0 , sizeof( V_25 -> V_268 ) ) ;
V_210 = F_168 ( V_267 ) ;
if ( V_210 < 0 )
return V_210 ;
V_25 -> V_268 . type = V_267 -> type ;
V_25 -> V_268 . V_269 = V_267 -> V_269 ;
V_25 -> V_268 . V_270 = V_267 -> V_270 ;
V_25 -> V_268 . V_33 = V_267 -> V_33 ;
V_25 -> V_191 = V_210 ;
V_25 -> V_210 = V_25 -> V_191 + V_25 -> V_240 ;
return 0 ;
}
static void V_54 ( struct V_7 * V_8 )
{
V_8 -> V_271 = & V_272 ;
V_8 -> V_273 = F_20 ;
V_8 -> type = V_274 ;
V_8 -> V_33 |= V_275 ;
V_8 -> V_276 = sizeof( struct V_1 ) ;
V_8 -> V_277 |= V_278 ;
F_169 ( V_8 ) ;
V_8 -> V_277 |= V_279 ;
V_8 -> V_280 |= V_279 ;
V_8 -> V_281 = V_282 ;
F_170 ( V_8 -> V_283 ) ;
}
static inline int
F_171 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_151 ;
int V_233 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_22 = F_27 ( V_8 ) ;
V_8 -> V_14 = F_172 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_52 ;
V_151 = F_173 ( & V_25 -> V_45 , V_284 ) ;
if ( V_151 )
goto V_285;
V_151 = F_174 ( & V_25 -> V_44 , V_8 ) ;
if ( V_151 )
goto V_286;
V_25 -> V_240 = 0 ;
V_25 -> V_210 = V_25 -> V_191 + V_25 -> V_240 ;
V_233 = V_25 -> V_210 + sizeof( struct V_64 ) ;
V_8 -> type = V_274 ;
V_8 -> V_242 = V_287 + V_233 ;
V_8 -> V_103 = V_288 - V_233 ;
if ( ! ( V_25 -> V_30 . V_33 & V_216 ) )
V_8 -> V_103 -= 8 ;
return 0 ;
V_286:
F_23 ( & V_25 -> V_45 ) ;
V_285:
F_24 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
return V_151 ;
}
static int F_175 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_46 = F_171 ( V_8 ) ;
if ( V_46 )
return V_46 ;
F_149 ( V_25 ) ;
return 0 ;
}
static int T_9 F_176 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
V_25 -> V_30 . V_101 = V_135 ;
F_29 ( V_8 ) ;
F_17 ( V_27 -> V_35 [ 0 ] , V_25 ) ;
return 0 ;
}
static int F_177 ( struct V_289 * V_290 [] , struct V_289 * V_72 [] )
{
T_5 V_101 ;
if ( ! V_72 || ! V_72 [ V_291 ] )
return 0 ;
V_101 = F_178 ( V_72 [ V_291 ] ) ;
if ( V_101 != V_135 &&
V_101 != V_119 &&
V_101 != 0 )
return - V_257 ;
return 0 ;
}
static void F_179 ( struct V_289 * V_72 [] ,
struct V_36 * V_30 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_72 )
return;
if ( V_72 [ V_292 ] )
V_30 -> V_148 = F_180 ( V_72 [ V_292 ] ) ;
if ( V_72 [ V_293 ] )
V_30 -> V_31 = F_181 ( V_72 [ V_293 ] ) ;
if ( V_72 [ V_294 ] )
V_30 -> V_32 = F_181 ( V_72 [ V_294 ] ) ;
if ( V_72 [ V_295 ] )
V_30 -> V_213 = F_178 ( V_72 [ V_295 ] ) ;
if ( V_72 [ V_296 ] )
V_30 -> V_108 = F_178 ( V_72 [ V_296 ] ) ;
if ( V_72 [ V_297 ] )
V_30 -> V_237 = F_182 ( V_72 [ V_297 ] ) ;
if ( V_72 [ V_298 ] )
V_30 -> V_33 = F_180 ( V_72 [ V_298 ] ) ;
if ( V_72 [ V_291 ] )
V_30 -> V_101 = F_178 ( V_72 [ V_291 ] ) ;
}
static bool F_183 ( struct V_289 * V_72 [] ,
struct V_266 * V_267 )
{
bool V_151 = false ;
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
if ( ! V_72 )
return V_151 ;
if ( V_72 [ V_299 ] ) {
V_151 = true ;
V_267 -> type = F_184 ( V_72 [ V_299 ] ) ;
}
if ( V_72 [ V_300 ] ) {
V_151 = true ;
V_267 -> V_33 = F_184 ( V_72 [ V_300 ] ) ;
}
if ( V_72 [ V_301 ] ) {
V_151 = true ;
V_267 -> V_269 = F_185 ( V_72 [ V_301 ] ) ;
}
if ( V_72 [ V_302 ] ) {
V_151 = true ;
V_267 -> V_270 = F_185 ( V_72 [ V_302 ] ) ;
}
return V_151 ;
}
static int F_186 ( struct V_22 * V_303 , struct V_7 * V_8 ,
struct V_289 * V_290 [] , struct V_289 * V_72 [] )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_21 * V_304 , * V_25 ;
struct V_266 V_267 ;
V_304 = F_21 ( V_8 ) ;
if ( F_183 ( V_72 , & V_267 ) ) {
int V_46 = F_167 ( V_304 , & V_267 ) ;
if ( V_46 < 0 )
return V_46 ;
}
F_179 ( V_72 , & V_304 -> V_30 ) ;
V_25 = F_35 ( V_22 , & V_304 -> V_30 , 0 ) ;
if ( ! F_59 ( V_25 ) )
return - V_58 ;
return F_26 ( V_8 ) ;
}
static int F_187 ( struct V_7 * V_8 , struct V_289 * V_290 [] ,
struct V_289 * V_72 [] )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_36 V_37 ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_266 V_267 ;
if ( V_8 == V_27 -> V_60 )
return - V_257 ;
if ( F_183 ( V_72 , & V_267 ) ) {
int V_46 = F_167 ( V_25 , & V_267 ) ;
if ( V_46 < 0 )
return V_46 ;
}
F_179 ( V_72 , & V_37 ) ;
V_25 = F_35 ( V_22 , & V_37 , 0 ) ;
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 )
return - V_58 ;
} else
V_25 = F_21 ( V_8 ) ;
return F_151 ( V_25 , & V_37 ) ;
}
static void F_188 ( struct V_7 * V_8 , struct V_305 * V_306 )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 != V_27 -> V_60 )
F_189 ( V_8 , V_306 ) ;
}
static T_10 F_190 ( const struct V_7 * V_8 )
{
return
F_191 ( 4 ) +
F_191 ( sizeof( struct V_1 ) ) +
F_191 ( sizeof( struct V_1 ) ) +
F_191 ( 1 ) +
F_191 ( 1 ) +
F_191 ( 4 ) +
F_191 ( 4 ) +
F_191 ( 1 ) +
F_191 ( 2 ) +
F_191 ( 2 ) +
F_191 ( 2 ) +
F_191 ( 2 ) +
0 ;
}
static int F_192 ( struct V_61 * V_62 , const struct V_7 * V_8 )
{
struct V_21 * V_153 = F_21 ( V_8 ) ;
struct V_36 * V_307 = & V_153 -> V_30 ;
if ( F_193 ( V_62 , V_292 , V_307 -> V_148 ) ||
F_194 ( V_62 , V_293 , & V_307 -> V_31 ) ||
F_194 ( V_62 , V_294 , & V_307 -> V_32 ) ||
F_195 ( V_62 , V_295 , V_307 -> V_213 ) ||
F_195 ( V_62 , V_296 , V_307 -> V_108 ) ||
F_196 ( V_62 , V_297 , V_307 -> V_237 ) ||
F_193 ( V_62 , V_298 , V_307 -> V_33 ) ||
F_195 ( V_62 , V_291 , V_307 -> V_101 ) )
goto V_308;
if ( F_197 ( V_62 , V_299 ,
V_153 -> V_268 . type ) ||
F_198 ( V_62 , V_301 ,
V_153 -> V_268 . V_269 ) ||
F_198 ( V_62 , V_302 ,
V_153 -> V_268 . V_270 ) ||
F_197 ( V_62 , V_300 ,
V_153 -> V_268 . V_33 ) )
goto V_308;
return 0 ;
V_308:
return - V_202 ;
}
struct V_22 * F_199 ( const struct V_7 * V_8 )
{
struct V_21 * V_153 = F_21 ( V_8 ) ;
return V_153 -> V_22 ;
}
static void T_11 F_200 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_7 * V_8 , * V_309 ;
int V_38 ;
struct V_21 * V_25 ;
F_201 ( V_310 ) ;
F_202 (net, dev, aux)
if ( V_8 -> V_47 == & V_48 )
F_189 ( V_8 , & V_310 ) ;
for ( V_38 = 0 ; V_38 < V_311 ; V_38 ++ ) {
V_25 = F_18 ( V_27 -> V_312 [ V_38 ] ) ;
while ( V_25 ) {
if ( ! F_98 ( F_27 ( V_25 -> V_8 ) , V_22 ) )
F_189 ( V_25 -> V_8 , & V_310 ) ;
V_25 = F_18 ( V_25 -> V_42 ) ;
}
}
F_203 ( & V_310 ) ;
}
static int T_9 F_204 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_25 = NULL ;
int V_46 ;
V_27 -> V_40 [ 0 ] = V_27 -> V_35 ;
V_27 -> V_40 [ 1 ] = V_27 -> V_312 ;
V_46 = - V_52 ;
V_27 -> V_60 = F_32 ( sizeof( struct V_21 ) , L_10 ,
V_53 , V_54 ) ;
if ( ! V_27 -> V_60 )
goto V_313;
F_33 ( V_27 -> V_60 , V_22 ) ;
V_27 -> V_60 -> V_47 = & V_48 ;
V_27 -> V_60 -> V_277 |= V_314 ;
V_46 = F_176 ( V_27 -> V_60 ) ;
if ( V_46 < 0 )
goto V_315;
V_46 = F_205 ( V_27 -> V_60 ) ;
if ( V_46 < 0 )
goto V_315;
V_25 = F_21 ( V_27 -> V_60 ) ;
strcpy ( V_25 -> V_30 . V_50 , V_27 -> V_60 -> V_50 ) ;
return 0 ;
V_315:
F_20 ( V_27 -> V_60 ) ;
V_313:
return V_46 ;
}
static void T_11 F_206 ( struct V_22 * V_22 )
{
F_207 () ;
F_200 ( V_22 ) ;
F_208 () ;
}
static int T_12 F_209 ( void )
{
int V_46 ;
V_46 = F_210 ( & V_316 ) ;
if ( V_46 < 0 )
goto V_317;
V_46 = F_211 ( & V_318 , V_319 ) ;
if ( V_46 < 0 ) {
F_212 ( L_11 , V_320 ) ;
goto V_321;
}
V_46 = F_211 ( & V_322 , V_323 ) ;
if ( V_46 < 0 ) {
F_212 ( L_12 , V_320 ) ;
goto V_324;
}
V_46 = F_213 ( & V_48 ) ;
if ( V_46 < 0 )
goto V_325;
return 0 ;
V_325:
F_214 ( & V_322 , V_323 ) ;
V_324:
F_214 ( & V_318 , V_319 ) ;
V_321:
F_215 ( & V_316 ) ;
V_317:
return V_46 ;
}
static void T_13 F_216 ( void )
{
F_217 ( & V_48 ) ;
if ( F_214 ( & V_318 , V_319 ) )
F_218 ( L_13 , V_320 ) ;
if ( F_214 ( & V_322 , V_323 ) )
F_218 ( L_14 , V_320 ) ;
F_215 ( & V_316 ) ;
}
