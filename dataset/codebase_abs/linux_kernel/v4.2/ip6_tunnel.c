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
! V_24 -> V_27 -> V_28 ( V_24 , V_23 -> V_29 ) ) {
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
V_23 -> V_29 = F_13 ( V_31 ) ;
F_10 ( V_23 -> V_25 ) ;
V_23 -> V_25 = V_24 ;
}
static struct V_22 *
F_14 ( struct V_32 * V_32 , const struct V_1 * V_33 , const struct V_1 * V_34 )
{
unsigned int V_4 = F_1 ( V_33 , V_34 ) ;
struct V_22 * V_23 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
struct V_1 V_38 ;
F_16 (ip6n->tnls_r_l[hash]) {
if ( F_17 ( V_34 , & V_23 -> V_39 . V_40 ) &&
F_17 ( V_33 , & V_23 -> V_39 . V_41 ) &&
( V_23 -> V_8 -> V_42 & V_43 ) )
return V_23 ;
}
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_4 = F_1 ( & V_38 , V_34 ) ;
F_16 (ip6n->tnls_r_l[hash]) {
if ( F_17 ( V_34 , & V_23 -> V_39 . V_40 ) &&
( V_23 -> V_8 -> V_42 & V_43 ) )
return V_23 ;
}
V_4 = F_1 ( V_33 , & V_38 ) ;
F_16 (ip6n->tnls_r_l[hash]) {
if ( F_17 ( V_33 , & V_23 -> V_39 . V_41 ) &&
( V_23 -> V_8 -> V_42 & V_43 ) )
return V_23 ;
}
V_23 = F_18 ( V_36 -> V_44 [ 0 ] ) ;
if ( V_23 && ( V_23 -> V_8 -> V_42 & V_43 ) )
return V_23 ;
return NULL ;
}
static struct V_22 T_2 * *
F_19 ( struct V_35 * V_36 , const struct V_45 * V_46 )
{
const struct V_1 * V_33 = & V_46 -> V_41 ;
const struct V_1 * V_34 = & V_46 -> V_40 ;
unsigned int V_47 = 0 ;
int V_48 = 0 ;
if ( ! F_20 ( V_33 ) || ! F_20 ( V_34 ) ) {
V_48 = 1 ;
V_47 = F_1 ( V_33 , V_34 ) ;
}
return & V_36 -> V_49 [ V_48 ] [ V_47 ] ;
}
static void
F_21 ( struct V_35 * V_36 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_50 = F_19 ( V_36 , & V_23 -> V_39 ) ;
F_22 ( V_23 -> V_51 , F_23 ( * V_50 ) ) ;
F_22 ( * V_50 , V_23 ) ;
}
static void
F_24 ( struct V_35 * V_36 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_50 ;
struct V_22 * V_52 ;
for ( V_50 = F_19 ( V_36 , & V_23 -> V_39 ) ;
( V_52 = F_23 ( * V_50 ) ) != NULL ;
V_50 = & V_52 -> V_51 ) {
if ( V_23 == V_52 ) {
F_22 ( * V_50 , V_23 -> V_51 ) ;
break;
}
}
}
static void F_25 ( struct V_7 * V_8 )
{
F_26 ( V_8 -> V_14 ) ;
F_27 ( V_8 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_32 * V_32 = F_30 ( V_8 ) ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
int V_53 ;
V_23 = F_29 ( V_8 ) ;
V_53 = F_31 ( V_8 ) ;
if ( V_53 < 0 )
goto V_54;
strcpy ( V_23 -> V_39 . V_55 , V_8 -> V_55 ) ;
V_8 -> V_56 = & V_57 ;
F_32 ( V_8 ) ;
F_21 ( V_36 , V_23 ) ;
return 0 ;
V_54:
return V_53 ;
}
static struct V_22 * F_33 ( struct V_32 * V_32 , struct V_45 * V_46 )
{
struct V_7 * V_8 ;
struct V_22 * V_23 ;
char V_55 [ V_58 ] ;
int V_53 = - V_59 ;
if ( V_46 -> V_55 [ 0 ] )
F_34 ( V_55 , V_46 -> V_55 , V_58 ) ;
else
sprintf ( V_55 , L_1 ) ;
V_8 = F_35 ( sizeof( * V_23 ) , V_55 , V_60 ,
V_61 ) ;
if ( ! V_8 )
goto V_62;
F_36 ( V_8 , V_32 ) ;
V_23 = F_29 ( V_8 ) ;
V_23 -> V_39 = * V_46 ;
V_23 -> V_32 = F_30 ( V_8 ) ;
V_53 = F_28 ( V_8 ) ;
if ( V_53 < 0 )
goto V_63;
return V_23 ;
V_63:
F_25 ( V_8 ) ;
V_62:
return F_37 ( V_53 ) ;
}
static struct V_22 * F_38 ( struct V_32 * V_32 ,
struct V_45 * V_46 , int V_64 )
{
const struct V_1 * V_33 = & V_46 -> V_41 ;
const struct V_1 * V_34 = & V_46 -> V_40 ;
struct V_22 T_2 * * V_50 ;
struct V_22 * V_23 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
for ( V_50 = F_19 ( V_36 , V_46 ) ;
( V_23 = F_23 ( * V_50 ) ) != NULL ;
V_50 = & V_23 -> V_51 ) {
if ( F_17 ( V_34 , & V_23 -> V_39 . V_40 ) &&
F_17 ( V_33 , & V_23 -> V_39 . V_41 ) ) {
if ( V_64 )
return F_37 ( - V_65 ) ;
return V_23 ;
}
}
if ( ! V_64 )
return F_37 ( - V_66 ) ;
return F_33 ( V_32 , V_46 ) ;
}
static void
F_39 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_32 * V_32 = V_23 -> V_32 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
if ( V_8 == V_36 -> V_67 )
F_40 ( V_36 -> V_44 [ 0 ] , NULL ) ;
else
F_24 ( V_36 , V_23 ) ;
F_11 ( V_23 ) ;
F_41 ( V_8 ) ;
}
T_3 F_42 ( struct V_68 * V_69 , T_4 * V_70 )
{
const struct V_71 * V_72 = ( const struct V_71 * ) V_70 ;
T_4 V_73 = V_72 -> V_73 ;
T_3 V_74 = sizeof( * V_72 ) ;
while ( F_43 ( V_73 ) && V_73 != V_75 ) {
T_3 V_76 = 0 ;
struct V_77 * V_78 ;
if ( V_70 + V_74 + sizeof( * V_78 ) > V_69 -> V_79 &&
! F_44 ( V_69 , V_70 - V_69 -> V_79 + V_74 + sizeof ( * V_78 ) ) )
break;
V_78 = (struct V_77 * ) ( V_70 + V_74 ) ;
if ( V_73 == V_80 ) {
struct V_81 * V_81 = (struct V_81 * ) V_78 ;
if ( V_81 -> V_82 )
break;
V_76 = 8 ;
} else if ( V_73 == V_83 ) {
V_76 = ( V_78 -> V_84 + 2 ) << 2 ;
} else {
V_76 = F_45 ( V_78 ) ;
}
if ( V_73 == V_85 ) {
T_3 V_12 = V_74 + 2 ;
while ( 1 ) {
struct V_86 * V_87 ;
if ( V_12 + sizeof ( * V_87 ) > V_74 + V_76 )
break;
V_87 = (struct V_86 * ) & V_70 [ V_12 ] ;
if ( V_87 -> type == V_88 &&
V_87 -> V_89 == 1 )
return V_12 ;
if ( V_87 -> type )
V_12 += V_87 -> V_89 + 2 ;
else
V_12 ++ ;
}
}
V_73 = V_78 -> V_73 ;
V_74 += V_76 ;
}
return 0 ;
}
static int
F_46 ( struct V_68 * V_69 , T_4 V_90 , struct V_91 * V_92 ,
T_5 * type , T_5 * V_93 , int * V_94 , T_6 * V_95 , int V_96 )
{
const struct V_71 * V_72 = ( const struct V_71 * ) V_69 -> V_79 ;
struct V_22 * V_23 ;
int V_97 = 0 ;
T_5 V_98 = V_99 ;
T_5 V_100 = V_101 ;
T_5 V_102 ;
T_6 V_103 = 0 ;
T_3 V_104 ;
int V_53 = - V_105 ;
F_47 () ;
V_23 = F_14 ( F_30 ( V_69 -> V_8 ) , & V_72 -> V_106 , & V_72 -> V_107 ) ;
if ( ! V_23 )
goto V_54;
V_102 = F_48 ( V_23 -> V_39 . V_108 ) ;
if ( V_102 != V_90 && V_102 != 0 )
goto V_54;
V_53 = 0 ;
switch ( * type ) {
T_6 V_109 ;
struct V_86 * V_87 ;
T_6 V_110 ;
case V_99 :
F_49 ( L_2 ,
V_23 -> V_39 . V_55 ) ;
V_97 = 1 ;
break;
case V_111 :
if ( ( * V_93 ) == V_112 ) {
F_49 ( L_3 ,
V_23 -> V_39 . V_55 ) ;
V_97 = 1 ;
}
break;
case V_113 :
V_109 = 0 ;
if ( ( * V_93 ) == V_114 )
V_109 = F_42 ( V_69 , V_69 -> V_79 ) ;
if ( V_109 && V_109 == * V_95 - 2 ) {
V_87 = (struct V_86 * ) & V_69 -> V_79 [ V_109 ] ;
if ( V_87 -> V_115 == 0 ) {
F_49 ( L_4 ,
V_23 -> V_39 . V_55 ) ;
V_97 = 1 ;
}
} else {
F_49 ( L_5 ,
V_23 -> V_39 . V_55 ) ;
}
break;
case V_116 :
V_110 = * V_95 - V_96 ;
if ( V_110 < V_117 )
V_110 = V_117 ;
V_23 -> V_8 -> V_110 = V_110 ;
V_104 = sizeof( * V_72 ) + F_50 ( V_72 -> V_118 ) ;
if ( V_104 > V_110 ) {
V_98 = V_116 ;
V_100 = 0 ;
V_103 = V_110 ;
V_97 = 1 ;
}
break;
}
* type = V_98 ;
* V_93 = V_100 ;
* V_95 = V_103 ;
* V_94 = V_97 ;
V_54:
F_51 () ;
return V_53 ;
}
static int
F_52 ( struct V_68 * V_69 , struct V_91 * V_92 ,
T_5 type , T_5 V_93 , int V_96 , T_7 V_95 )
{
int V_97 = 0 ;
T_5 V_98 = type ;
T_5 V_100 = V_93 ;
T_6 V_103 = F_53 ( V_95 ) ;
int V_53 ;
struct V_68 * V_119 ;
const struct V_120 * V_121 ;
struct V_122 * V_31 ;
struct V_123 V_124 ;
V_53 = F_46 ( V_69 , V_125 , V_92 , & V_98 , & V_100 ,
& V_97 , & V_103 , V_96 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_97 == 0 )
return 0 ;
switch ( V_98 ) {
case V_99 :
if ( V_100 != V_101 )
return 0 ;
V_98 = V_126 ;
V_100 = V_127 ;
break;
case V_116 :
if ( V_100 != 0 )
return 0 ;
V_98 = V_126 ;
V_100 = V_128 ;
break;
case V_129 :
V_98 = V_130 ;
V_100 = V_131 ;
default:
return 0 ;
}
if ( ! F_44 ( V_69 , V_96 + sizeof( struct V_120 ) ) )
return 0 ;
V_119 = F_54 ( V_69 , V_132 ) ;
if ( ! V_119 )
return 0 ;
F_55 ( V_119 ) ;
F_56 ( V_119 , V_96 ) ;
F_57 ( V_119 ) ;
V_121 = F_58 ( V_119 ) ;
V_31 = F_59 ( F_30 ( V_69 -> V_8 ) , & V_124 , NULL ,
V_121 -> V_107 , 0 ,
0 , 0 ,
V_125 , F_60 ( V_121 -> V_133 ) , 0 ) ;
if ( F_61 ( V_31 ) )
goto V_54;
V_119 -> V_8 = V_31 -> V_24 . V_8 ;
if ( V_31 -> V_134 & V_135 ) {
F_62 ( V_31 ) ;
V_31 = NULL ;
V_31 = F_59 ( F_30 ( V_69 -> V_8 ) , & V_124 , NULL ,
V_121 -> V_106 , V_121 -> V_107 ,
0 , 0 ,
V_125 ,
F_60 ( V_121 -> V_133 ) , 0 ) ;
if ( F_61 ( V_31 ) ||
V_31 -> V_24 . V_8 -> type != V_136 ) {
if ( ! F_61 ( V_31 ) )
F_62 ( V_31 ) ;
goto V_54;
}
F_63 ( V_119 , & V_31 -> V_24 ) ;
} else {
F_62 ( V_31 ) ;
if ( F_64 ( V_119 , V_121 -> V_106 , V_121 -> V_107 , V_121 -> V_133 ,
V_119 -> V_8 ) ||
F_65 ( V_119 ) -> V_8 -> type != V_136 )
goto V_54;
}
if ( V_98 == V_126 && V_100 == V_128 ) {
if ( V_103 > F_66 ( F_65 ( V_119 ) ) )
goto V_54;
F_65 ( V_119 ) -> V_27 -> V_137 ( F_65 ( V_119 ) , NULL , V_119 , V_103 ) ;
}
if ( V_98 == V_130 )
F_65 ( V_119 ) -> V_27 -> V_138 ( F_65 ( V_119 ) , NULL , V_119 ) ;
F_67 ( V_119 , V_98 , V_100 , F_68 ( V_103 ) ) ;
V_54:
F_69 ( V_119 ) ;
return 0 ;
}
static int
F_70 ( struct V_68 * V_69 , struct V_91 * V_92 ,
T_5 type , T_5 V_93 , int V_96 , T_7 V_95 )
{
int V_97 = 0 ;
T_5 V_98 = type ;
T_5 V_100 = V_93 ;
T_6 V_103 = F_53 ( V_95 ) ;
int V_53 ;
V_53 = F_46 ( V_69 , V_139 , V_92 , & V_98 , & V_100 ,
& V_97 , & V_103 , V_96 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_97 && F_44 ( V_69 , V_96 + sizeof( struct V_71 ) ) ) {
struct V_30 * V_31 ;
struct V_68 * V_119 = F_54 ( V_69 , V_132 ) ;
if ( ! V_119 )
return 0 ;
F_55 ( V_119 ) ;
F_56 ( V_119 , V_96 ) ;
F_57 ( V_119 ) ;
V_31 = F_71 ( F_30 ( V_69 -> V_8 ) , & F_72 ( V_119 ) -> V_107 ,
NULL , 0 , 0 ) ;
if ( V_31 && V_31 -> V_24 . V_8 )
V_119 -> V_8 = V_31 -> V_24 . V_8 ;
F_73 ( V_119 , V_98 , V_100 , V_103 ) ;
F_74 ( V_31 ) ;
F_69 ( V_119 ) ;
}
return 0 ;
}
static int F_75 ( const struct V_22 * V_23 ,
const struct V_71 * V_72 ,
struct V_68 * V_69 )
{
T_4 V_140 = F_76 ( V_72 ) & ~ V_141 ;
if ( V_23 -> V_39 . V_42 & V_142 )
F_77 ( F_58 ( V_69 ) , V_141 , V_140 ) ;
return F_78 ( V_72 , V_69 ) ;
}
static int F_79 ( const struct V_22 * V_23 ,
const struct V_71 * V_72 ,
struct V_68 * V_69 )
{
if ( V_23 -> V_39 . V_42 & V_142 )
F_80 ( F_76 ( V_72 ) , F_72 ( V_69 ) ) ;
return F_78 ( V_72 , V_69 ) ;
}
T_6 F_81 ( struct V_22 * V_23 ,
const struct V_1 * V_40 ,
const struct V_1 * V_41 )
{
struct V_45 * V_46 = & V_23 -> V_39 ;
int V_143 = F_82 ( V_40 ) ;
int V_144 = F_82 ( V_41 ) ;
T_6 V_42 = 0 ;
if ( V_143 == V_145 || V_144 == V_145 ) {
V_42 = V_146 ;
} else if ( V_143 & ( V_147 | V_148 ) &&
V_144 & ( V_147 | V_148 ) &&
! ( ( V_143 | V_144 ) & V_149 ) &&
( ! ( ( V_143 | V_144 ) & V_150 ) || V_46 -> V_151 ) ) {
if ( V_143 & V_147 )
V_42 |= V_152 ;
if ( V_144 & V_147 )
V_42 |= V_153 ;
}
return V_42 ;
}
int F_83 ( struct V_22 * V_23 ,
const struct V_1 * V_40 ,
const struct V_1 * V_41 )
{
struct V_45 * V_46 = & V_23 -> V_39 ;
int V_154 = 0 ;
struct V_32 * V_32 = V_23 -> V_32 ;
if ( ( V_46 -> V_42 & V_153 ) ||
( ( V_46 -> V_42 & V_146 ) &&
( F_81 ( V_23 , V_40 , V_41 ) & V_153 ) ) ) {
struct V_7 * V_155 = NULL ;
if ( V_46 -> V_151 )
V_155 = F_84 ( V_32 , V_46 -> V_151 ) ;
if ( ( F_85 ( V_40 ) ||
F_86 ( F_87 ( V_32 , V_40 , V_155 , 0 ) ) ) &&
F_86 ( ! F_87 ( V_32 , V_41 , NULL , 0 ) ) )
V_154 = 1 ;
}
return V_154 ;
}
static int F_88 ( struct V_68 * V_69 , T_3 V_156 ,
T_4 V_90 ,
int (* F_89)( const struct V_22 * V_23 ,
const struct V_71 * V_72 ,
struct V_68 * V_69 ) )
{
struct V_22 * V_23 ;
const struct V_71 * V_72 = F_72 ( V_69 ) ;
T_5 V_102 ;
int V_53 ;
F_47 () ;
V_23 = F_14 ( F_30 ( V_69 -> V_8 ) , & V_72 -> V_107 , & V_72 -> V_106 ) ;
if ( V_23 ) {
struct V_9 * V_14 ;
V_102 = F_48 ( V_23 -> V_39 . V_108 ) ;
if ( V_102 != V_90 && V_102 != 0 ) {
F_51 () ;
goto V_157;
}
if ( ! F_90 ( NULL , V_158 , V_69 ) ) {
F_51 () ;
goto V_157;
}
if ( ! F_83 ( V_23 , & V_72 -> V_106 , & V_72 -> V_107 ) ) {
V_23 -> V_8 -> V_20 . V_159 ++ ;
F_51 () ;
goto V_157;
}
V_69 -> V_160 = V_69 -> V_161 ;
F_57 ( V_69 ) ;
V_69 -> V_156 = F_91 ( V_156 ) ;
memset ( V_69 -> V_162 , 0 , sizeof( struct V_91 ) ) ;
F_92 ( V_69 , V_23 -> V_8 , V_23 -> V_32 ) ;
V_53 = F_89 ( V_23 , V_72 , V_69 ) ;
if ( F_93 ( V_53 ) ) {
if ( V_163 )
F_94 ( L_6 ,
& V_72 -> V_107 ,
F_76 ( V_72 ) ) ;
if ( V_53 > 1 ) {
++ V_23 -> V_8 -> V_20 . V_164 ;
++ V_23 -> V_8 -> V_20 . V_165 ;
F_51 () ;
goto V_157;
}
}
V_14 = F_95 ( V_23 -> V_8 -> V_14 ) ;
F_96 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_69 -> V_104 ;
F_97 ( & V_14 -> V_15 ) ;
F_98 ( V_69 ) ;
F_51 () ;
return 0 ;
}
F_51 () ;
return 1 ;
V_157:
F_69 ( V_69 ) ;
return 0 ;
}
static int F_99 ( struct V_68 * V_69 )
{
return F_88 ( V_69 , V_166 , V_125 ,
F_75 ) ;
}
static int F_100 ( struct V_68 * V_69 )
{
return F_88 ( V_69 , V_167 , V_139 ,
F_79 ) ;
}
static void F_101 ( struct V_168 * V_92 , T_4 V_115 )
{
memset ( V_92 , 0 , sizeof( struct V_168 ) ) ;
V_92 -> V_169 [ 2 ] = V_88 ;
V_92 -> V_169 [ 3 ] = 1 ;
V_92 -> V_169 [ 4 ] = V_115 ;
V_92 -> V_169 [ 5 ] = V_170 ;
V_92 -> V_169 [ 6 ] = 1 ;
V_92 -> V_27 . V_171 = (struct V_77 * ) V_92 -> V_169 ;
V_92 -> V_27 . V_172 = 8 ;
}
static inline bool
F_102 ( const struct V_22 * V_23 , const struct V_71 * V_78 )
{
return F_17 ( & V_23 -> V_39 . V_41 , & V_78 -> V_107 ) ;
}
int F_103 ( struct V_22 * V_23 ,
const struct V_1 * V_40 ,
const struct V_1 * V_41 )
{
struct V_45 * V_46 = & V_23 -> V_39 ;
int V_154 = 0 ;
struct V_32 * V_32 = V_23 -> V_32 ;
if ( ( V_46 -> V_42 & V_152 ) ||
( ( V_46 -> V_42 & V_146 ) &&
( F_81 ( V_23 , V_40 , V_41 ) & V_152 ) ) ) {
struct V_7 * V_155 = NULL ;
F_47 () ;
if ( V_46 -> V_151 )
V_155 = F_84 ( V_32 , V_46 -> V_151 ) ;
if ( F_93 ( ! F_87 ( V_32 , V_40 , V_155 , 0 ) ) )
F_104 ( L_7 ,
V_46 -> V_55 ) ;
else if ( ! F_85 ( V_41 ) &&
F_93 ( F_87 ( V_32 , V_41 , NULL , 0 ) ) )
F_104 ( L_8 ,
V_46 -> V_55 ) ;
else
V_154 = 1 ;
F_51 () ;
}
return V_154 ;
}
static int F_105 ( struct V_68 * V_69 ,
struct V_7 * V_8 ,
T_4 V_140 ,
struct V_173 * V_174 ,
int V_115 ,
T_6 * V_175 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_32 * V_32 = V_23 -> V_32 ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
struct V_71 * V_72 = F_72 ( V_69 ) ;
struct V_168 V_92 ;
struct V_21 * V_24 = NULL , * V_176 = NULL ;
struct V_7 * V_177 ;
int V_110 ;
unsigned int V_178 = sizeof( struct V_71 ) ;
T_5 V_108 ;
int V_53 = - 1 ;
if ( F_20 ( & V_23 -> V_39 . V_41 ) ) {
struct V_1 * V_179 ;
struct V_180 * V_181 ;
int V_182 ;
if ( ! F_65 ( V_69 ) )
goto V_183;
V_181 = F_106 ( F_65 ( V_69 ) ,
& F_72 ( V_69 ) -> V_106 ) ;
if ( ! V_181 )
goto V_183;
V_179 = (struct V_1 * ) & V_181 -> V_184 ;
V_182 = F_82 ( V_179 ) ;
if ( V_182 == V_145 )
V_179 = & F_72 ( V_69 ) -> V_106 ;
memcpy ( & V_174 -> V_106 , V_179 , sizeof( V_174 -> V_106 ) ) ;
F_107 ( V_181 ) ;
} else if ( ! V_174 -> V_185 )
V_24 = F_9 ( V_23 ) ;
if ( ! F_103 ( V_23 , & V_174 -> V_107 , & V_174 -> V_106 ) )
goto V_183;
if ( ! V_24 ) {
V_176 = F_108 ( V_32 , NULL , V_174 ) ;
if ( V_176 -> error )
goto V_183;
V_176 = F_109 ( V_32 , V_176 , F_110 ( V_174 ) , NULL , 0 ) ;
if ( F_61 ( V_176 ) ) {
V_53 = F_111 ( V_176 ) ;
V_176 = NULL ;
goto V_183;
}
V_24 = V_176 ;
}
V_177 = V_24 -> V_8 ;
if ( V_177 == V_8 ) {
V_20 -> V_186 ++ ;
F_49 ( L_9 ,
V_23 -> V_39 . V_55 ) ;
goto V_187;
}
V_110 = F_66 ( V_24 ) - sizeof( * V_72 ) ;
if ( V_115 >= 0 ) {
V_178 += 8 ;
V_110 -= 8 ;
}
if ( V_110 < V_117 )
V_110 = V_117 ;
if ( F_65 ( V_69 ) )
F_65 ( V_69 ) -> V_27 -> V_137 ( F_65 ( V_69 ) , NULL , V_69 , V_110 ) ;
if ( V_69 -> V_104 > V_110 ) {
* V_175 = V_110 ;
V_53 = - V_188 ;
goto V_187;
}
F_112 ( V_69 , ! F_113 ( V_23 -> V_32 , F_30 ( V_8 ) ) ) ;
V_178 += F_114 ( V_177 ) ;
if ( F_115 ( V_69 ) < V_178 || F_116 ( V_69 ) ||
( F_117 ( V_69 ) && ! F_118 ( V_69 , 0 ) ) ) {
struct V_68 * V_189 ;
V_189 = F_119 ( V_69 , V_178 ) ;
if ( ! V_189 )
goto V_187;
if ( V_69 -> V_190 )
F_120 ( V_189 , V_69 -> V_190 ) ;
F_121 ( V_69 ) ;
V_69 = V_189 ;
}
if ( V_174 -> V_185 ) {
F_63 ( V_69 , V_24 ) ;
V_176 = NULL ;
} else {
F_122 ( V_69 , V_24 ) ;
}
V_69 -> V_191 = V_69 -> V_161 ;
V_108 = V_174 -> V_192 ;
if ( V_115 >= 0 ) {
F_101 ( & V_92 , V_115 ) ;
F_123 ( V_69 , & V_92 . V_27 , & V_108 , NULL ) ;
}
if ( F_86 ( ! V_69 -> V_193 ) ) {
F_124 ( V_69 ) ;
V_69 -> V_193 = 1 ;
}
F_125 ( V_69 , sizeof( struct V_71 ) ) ;
F_57 ( V_69 ) ;
V_72 = F_72 ( V_69 ) ;
F_126 ( V_72 , F_127 ( 0 , V_140 ) ,
F_128 ( V_32 , V_69 , V_174 -> V_194 , false ) ) ;
V_72 -> V_195 = V_23 -> V_39 . V_195 ;
V_72 -> V_73 = V_108 ;
V_72 -> V_107 = V_174 -> V_107 ;
V_72 -> V_106 = V_174 -> V_106 ;
F_129 ( NULL , V_69 , V_8 ) ;
if ( V_176 )
F_12 ( V_23 , V_176 ) ;
return 0 ;
V_183:
V_20 -> V_196 ++ ;
F_130 ( V_69 ) ;
V_187:
F_10 ( V_176 ) ;
return V_53 ;
}
static inline int
F_131 ( struct V_68 * V_69 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
const struct V_120 * V_197 = F_58 ( V_69 ) ;
int V_115 = - 1 ;
struct V_173 V_174 ;
T_4 V_140 ;
T_6 V_110 ;
T_5 V_102 ;
int V_53 ;
V_102 = F_48 ( V_23 -> V_39 . V_108 ) ;
if ( V_102 != V_125 && V_102 != 0 )
return - 1 ;
if ( ! ( V_23 -> V_39 . V_42 & V_198 ) )
V_115 = V_23 -> V_39 . V_115 ;
memcpy ( & V_174 , & V_23 -> V_199 . V_200 . V_201 , sizeof( V_174 ) ) ;
V_174 . V_192 = V_125 ;
V_140 = F_132 ( V_197 ) ;
if ( V_23 -> V_39 . V_42 & V_202 )
V_174 . V_194 |= F_68 ( ( T_6 ) V_197 -> V_133 << V_203 )
& V_204 ;
if ( V_23 -> V_39 . V_42 & V_205 )
V_174 . V_185 = V_69 -> V_206 ;
V_53 = F_105 ( V_69 , V_8 , V_140 , & V_174 , V_115 , & V_110 ) ;
if ( V_53 != 0 ) {
if ( V_53 == - V_188 )
F_67 ( V_69 , V_126 , V_128 ,
F_68 ( V_110 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_133 ( struct V_68 * V_69 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_71 * V_72 = F_72 ( V_69 ) ;
int V_115 = - 1 ;
T_3 V_96 ;
struct V_173 V_174 ;
T_4 V_140 ;
T_6 V_110 ;
T_5 V_102 ;
int V_53 ;
V_102 = F_48 ( V_23 -> V_39 . V_108 ) ;
if ( ( V_102 != V_139 && V_102 != 0 ) ||
F_102 ( V_23 , V_72 ) )
return - 1 ;
V_96 = F_42 ( V_69 , F_134 ( V_69 ) ) ;
if ( V_96 > 0 ) {
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) & F_134 ( V_69 ) [ V_96 ] ;
if ( V_87 -> V_115 == 0 ) {
F_73 ( V_69 , V_113 ,
V_114 , V_96 + 2 ) ;
return - 1 ;
}
V_115 = V_87 -> V_115 - 1 ;
} else if ( ! ( V_23 -> V_39 . V_42 & V_198 ) )
V_115 = V_23 -> V_39 . V_115 ;
memcpy ( & V_174 , & V_23 -> V_199 . V_200 . V_201 , sizeof( V_174 ) ) ;
V_174 . V_192 = V_139 ;
V_140 = F_76 ( V_72 ) ;
if ( V_23 -> V_39 . V_42 & V_202 )
V_174 . V_194 |= ( * ( T_7 * ) V_72 & V_204 ) ;
if ( V_23 -> V_39 . V_42 & V_207 )
V_174 . V_194 |= F_135 ( V_72 ) ;
if ( V_23 -> V_39 . V_42 & V_205 )
V_174 . V_185 = V_69 -> V_206 ;
V_53 = F_105 ( V_69 , V_8 , V_140 , & V_174 , V_115 , & V_110 ) ;
if ( V_53 != 0 ) {
if ( V_53 == - V_188 )
F_73 ( V_69 , V_116 , 0 , V_110 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_136 ( struct V_68 * V_69 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
int V_154 ;
switch ( V_69 -> V_156 ) {
case F_91 ( V_166 ) :
V_154 = F_131 ( V_69 , V_8 ) ;
break;
case F_91 ( V_167 ) :
V_154 = F_133 ( V_69 , V_8 ) ;
break;
default:
goto V_208;
}
if ( V_154 < 0 )
goto V_208;
return V_209 ;
V_208:
V_20 -> V_210 ++ ;
V_20 -> V_211 ++ ;
F_69 ( V_69 ) ;
return V_209 ;
}
static void F_137 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_45 * V_46 = & V_23 -> V_39 ;
struct V_173 * V_174 = & V_23 -> V_199 . V_200 . V_201 ;
memcpy ( V_8 -> V_212 , & V_46 -> V_40 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_213 , & V_46 -> V_41 , sizeof( struct V_1 ) ) ;
V_174 -> V_107 = V_46 -> V_40 ;
V_174 -> V_106 = V_46 -> V_41 ;
V_174 -> V_214 = V_46 -> V_151 ;
V_174 -> V_194 = 0 ;
if ( ! ( V_46 -> V_42 & V_202 ) )
V_174 -> V_194 |= V_204 & V_46 -> V_215 ;
if ( ! ( V_46 -> V_42 & V_207 ) )
V_174 -> V_194 |= V_216 & V_46 -> V_215 ;
V_46 -> V_42 &= ~ ( V_152 | V_153 | V_146 ) ;
V_46 -> V_42 |= F_81 ( V_23 , & V_46 -> V_40 , & V_46 -> V_41 ) ;
if ( V_46 -> V_42 & V_152 && V_46 -> V_42 & V_153 )
V_8 -> V_42 |= V_217 ;
else
V_8 -> V_42 &= ~ V_217 ;
if ( V_46 -> V_42 & V_152 ) {
int V_218 = ( F_82 ( & V_46 -> V_41 ) &
( V_148 | V_150 ) ) ;
struct V_30 * V_31 = F_71 ( V_23 -> V_32 ,
& V_46 -> V_41 , & V_46 -> V_40 ,
V_46 -> V_151 , V_218 ) ;
if ( ! V_31 )
return;
if ( V_31 -> V_24 . V_8 ) {
V_8 -> V_219 = V_31 -> V_24 . V_8 -> V_219 +
sizeof( struct V_71 ) ;
V_8 -> V_110 = V_31 -> V_24 . V_8 -> V_110 - sizeof( struct V_71 ) ;
if ( ! ( V_23 -> V_39 . V_42 & V_198 ) )
V_8 -> V_110 -= 8 ;
if ( V_8 -> V_110 < V_117 )
V_8 -> V_110 = V_117 ;
}
F_74 ( V_31 ) ;
}
}
static int
F_138 ( struct V_22 * V_23 , const struct V_45 * V_46 )
{
V_23 -> V_39 . V_40 = V_46 -> V_40 ;
V_23 -> V_39 . V_41 = V_46 -> V_41 ;
V_23 -> V_39 . V_42 = V_46 -> V_42 ;
V_23 -> V_39 . V_195 = V_46 -> V_195 ;
V_23 -> V_39 . V_115 = V_46 -> V_115 ;
V_23 -> V_39 . V_215 = V_46 -> V_215 ;
V_23 -> V_39 . V_151 = V_46 -> V_151 ;
V_23 -> V_39 . V_108 = V_46 -> V_108 ;
F_11 ( V_23 ) ;
F_137 ( V_23 ) ;
return 0 ;
}
static int F_139 ( struct V_22 * V_23 , struct V_45 * V_46 )
{
struct V_32 * V_32 = V_23 -> V_32 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
int V_53 ;
F_24 ( V_36 , V_23 ) ;
F_140 () ;
V_53 = F_138 ( V_23 , V_46 ) ;
F_21 ( V_36 , V_23 ) ;
F_141 ( V_23 -> V_8 ) ;
return V_53 ;
}
static int F_142 ( struct V_22 * V_23 , struct V_45 * V_46 )
{
V_23 -> V_39 . V_108 = V_46 -> V_108 ;
F_141 ( V_23 -> V_8 ) ;
return 0 ;
}
static void
F_143 ( struct V_45 * V_46 , const struct V_220 * V_200 )
{
V_46 -> V_40 = V_200 -> V_40 ;
V_46 -> V_41 = V_200 -> V_41 ;
V_46 -> V_42 = V_200 -> V_42 ;
V_46 -> V_195 = V_200 -> V_195 ;
V_46 -> V_115 = V_200 -> V_115 ;
V_46 -> V_215 = V_200 -> V_215 ;
V_46 -> V_151 = V_200 -> V_151 ;
V_46 -> V_108 = V_200 -> V_108 ;
memcpy ( V_46 -> V_55 , V_200 -> V_55 , sizeof( V_200 -> V_55 ) ) ;
}
static void
F_144 ( struct V_220 * V_200 , const struct V_45 * V_46 )
{
V_200 -> V_40 = V_46 -> V_40 ;
V_200 -> V_41 = V_46 -> V_41 ;
V_200 -> V_42 = V_46 -> V_42 ;
V_200 -> V_195 = V_46 -> V_195 ;
V_200 -> V_115 = V_46 -> V_115 ;
V_200 -> V_215 = V_46 -> V_215 ;
V_200 -> V_151 = V_46 -> V_151 ;
V_200 -> V_108 = V_46 -> V_108 ;
memcpy ( V_200 -> V_55 , V_46 -> V_55 , sizeof( V_200 -> V_55 ) ) ;
}
static int
F_145 ( struct V_7 * V_8 , struct V_221 * V_222 , int V_223 )
{
int V_53 = 0 ;
struct V_220 V_46 ;
struct V_45 V_224 ;
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_32 * V_32 = V_23 -> V_32 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
switch ( V_223 ) {
case V_225 :
if ( V_8 == V_36 -> V_67 ) {
if ( F_146 ( & V_46 , V_222 -> V_226 . V_227 , sizeof( V_46 ) ) ) {
V_53 = - V_228 ;
break;
}
F_143 ( & V_224 , & V_46 ) ;
V_23 = F_38 ( V_32 , & V_224 , 0 ) ;
if ( F_61 ( V_23 ) )
V_23 = F_29 ( V_8 ) ;
} else {
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
}
F_144 ( & V_46 , & V_23 -> V_39 ) ;
if ( F_147 ( V_222 -> V_226 . V_227 , & V_46 , sizeof( V_46 ) ) ) {
V_53 = - V_228 ;
}
break;
case V_229 :
case V_230 :
V_53 = - V_231 ;
if ( ! F_148 ( V_32 -> V_232 , V_233 ) )
break;
V_53 = - V_228 ;
if ( F_146 ( & V_46 , V_222 -> V_226 . V_227 , sizeof( V_46 ) ) )
break;
V_53 = - V_234 ;
if ( V_46 . V_108 != V_139 && V_46 . V_108 != V_125 &&
V_46 . V_108 != 0 )
break;
F_143 ( & V_224 , & V_46 ) ;
V_23 = F_38 ( V_32 , & V_224 , V_223 == V_229 ) ;
if ( V_223 == V_230 ) {
if ( ! F_61 ( V_23 ) ) {
if ( V_23 -> V_8 != V_8 ) {
V_53 = - V_65 ;
break;
}
} else
V_23 = F_29 ( V_8 ) ;
if ( V_8 == V_36 -> V_67 )
V_53 = F_142 ( V_23 , & V_224 ) ;
else
V_53 = F_139 ( V_23 , & V_224 ) ;
}
if ( ! F_61 ( V_23 ) ) {
V_53 = 0 ;
F_144 ( & V_46 , & V_23 -> V_39 ) ;
if ( F_147 ( V_222 -> V_226 . V_227 , & V_46 , sizeof( V_46 ) ) )
V_53 = - V_228 ;
} else {
V_53 = F_111 ( V_23 ) ;
}
break;
case V_235 :
V_53 = - V_231 ;
if ( ! F_148 ( V_32 -> V_232 , V_233 ) )
break;
if ( V_8 == V_36 -> V_67 ) {
V_53 = - V_228 ;
if ( F_146 ( & V_46 , V_222 -> V_226 . V_227 , sizeof( V_46 ) ) )
break;
V_53 = - V_105 ;
F_143 ( & V_224 , & V_46 ) ;
V_23 = F_38 ( V_32 , & V_224 , 0 ) ;
if ( F_61 ( V_23 ) )
break;
V_53 = - V_231 ;
if ( V_23 -> V_8 == V_36 -> V_67 )
break;
V_8 = V_23 -> V_8 ;
}
V_53 = 0 ;
F_149 ( V_8 ) ;
break;
default:
V_53 = - V_234 ;
}
return V_53 ;
}
static int
F_150 ( struct V_7 * V_8 , int V_236 )
{
struct V_22 * V_237 = F_29 ( V_8 ) ;
if ( V_237 -> V_39 . V_108 == V_125 ) {
if ( V_236 < 68 )
return - V_234 ;
} else {
if ( V_236 < V_117 )
return - V_234 ;
}
if ( V_236 > 0xFFF8 - V_8 -> V_219 )
return - V_234 ;
V_8 -> V_110 = V_236 ;
return 0 ;
}
int F_151 ( const struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
return V_23 -> V_39 . V_151 ;
}
static void V_61 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_8 -> V_238 = & V_239 ;
V_8 -> V_240 = F_25 ;
V_8 -> type = V_241 ;
V_8 -> V_219 = V_242 + sizeof( struct V_71 ) ;
V_8 -> V_110 = V_243 - sizeof( struct V_71 ) ;
V_23 = F_29 ( V_8 ) ;
if ( ! ( V_23 -> V_39 . V_42 & V_198 ) )
V_8 -> V_110 -= 8 ;
V_8 -> V_42 |= V_244 ;
V_8 -> V_245 = sizeof( struct V_1 ) ;
F_152 ( V_8 ) ;
V_8 -> V_246 = V_247 ;
F_153 ( V_8 -> V_248 ) ;
}
static inline int
F_154 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_32 = F_30 ( V_8 ) ;
V_8 -> V_14 = F_155 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_59 ;
return 0 ;
}
static int F_156 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
int V_53 = F_154 ( V_8 ) ;
if ( V_53 )
return V_53 ;
F_137 ( V_23 ) ;
return 0 ;
}
static int T_9 F_157 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_32 * V_32 = F_30 ( V_8 ) ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
V_23 -> V_39 . V_108 = V_139 ;
F_32 ( V_8 ) ;
F_22 ( V_36 -> V_44 [ 0 ] , V_23 ) ;
return 0 ;
}
static int F_158 ( struct V_249 * V_250 [] , struct V_249 * V_79 [] )
{
T_5 V_108 ;
if ( ! V_79 || ! V_79 [ V_251 ] )
return 0 ;
V_108 = F_159 ( V_79 [ V_251 ] ) ;
if ( V_108 != V_139 &&
V_108 != V_125 &&
V_108 != 0 )
return - V_234 ;
return 0 ;
}
static void F_160 ( struct V_249 * V_79 [] ,
struct V_45 * V_39 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
if ( ! V_79 )
return;
if ( V_79 [ V_252 ] )
V_39 -> V_151 = F_161 ( V_79 [ V_252 ] ) ;
if ( V_79 [ V_253 ] )
V_39 -> V_40 = F_162 ( V_79 [ V_253 ] ) ;
if ( V_79 [ V_254 ] )
V_39 -> V_41 = F_162 ( V_79 [ V_254 ] ) ;
if ( V_79 [ V_255 ] )
V_39 -> V_195 = F_159 ( V_79 [ V_255 ] ) ;
if ( V_79 [ V_256 ] )
V_39 -> V_115 = F_159 ( V_79 [ V_256 ] ) ;
if ( V_79 [ V_257 ] )
V_39 -> V_215 = F_163 ( V_79 [ V_257 ] ) ;
if ( V_79 [ V_258 ] )
V_39 -> V_42 = F_161 ( V_79 [ V_258 ] ) ;
if ( V_79 [ V_251 ] )
V_39 -> V_108 = F_159 ( V_79 [ V_251 ] ) ;
}
static int F_164 ( struct V_32 * V_259 , struct V_7 * V_8 ,
struct V_249 * V_250 [] , struct V_249 * V_79 [] )
{
struct V_32 * V_32 = F_30 ( V_8 ) ;
struct V_22 * V_260 , * V_23 ;
V_260 = F_29 ( V_8 ) ;
F_160 ( V_79 , & V_260 -> V_39 ) ;
V_23 = F_38 ( V_32 , & V_260 -> V_39 , 0 ) ;
if ( ! F_61 ( V_23 ) )
return - V_65 ;
return F_28 ( V_8 ) ;
}
static int F_165 ( struct V_7 * V_8 , struct V_249 * V_250 [] ,
struct V_249 * V_79 [] )
{
struct V_22 * V_23 = F_29 ( V_8 ) ;
struct V_45 V_46 ;
struct V_32 * V_32 = V_23 -> V_32 ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
if ( V_8 == V_36 -> V_67 )
return - V_234 ;
F_160 ( V_79 , & V_46 ) ;
V_23 = F_38 ( V_32 , & V_46 , 0 ) ;
if ( ! F_61 ( V_23 ) ) {
if ( V_23 -> V_8 != V_8 )
return - V_65 ;
} else
V_23 = F_29 ( V_8 ) ;
return F_139 ( V_23 , & V_46 ) ;
}
static void F_166 ( struct V_7 * V_8 , struct V_261 * V_262 )
{
struct V_32 * V_32 = F_30 ( V_8 ) ;
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
if ( V_8 != V_36 -> V_67 )
F_167 ( V_8 , V_262 ) ;
}
static T_10 F_168 ( const struct V_7 * V_8 )
{
return
F_169 ( 4 ) +
F_169 ( sizeof( struct V_1 ) ) +
F_169 ( sizeof( struct V_1 ) ) +
F_169 ( 1 ) +
F_169 ( 1 ) +
F_169 ( 4 ) +
F_169 ( 4 ) +
F_169 ( 1 ) +
0 ;
}
static int F_170 ( struct V_68 * V_69 , const struct V_7 * V_8 )
{
struct V_22 * V_263 = F_29 ( V_8 ) ;
struct V_45 * V_264 = & V_263 -> V_39 ;
if ( F_171 ( V_69 , V_252 , V_264 -> V_151 ) ||
F_172 ( V_69 , V_253 , & V_264 -> V_40 ) ||
F_172 ( V_69 , V_254 , & V_264 -> V_41 ) ||
F_173 ( V_69 , V_255 , V_264 -> V_195 ) ||
F_173 ( V_69 , V_256 , V_264 -> V_115 ) ||
F_174 ( V_69 , V_257 , V_264 -> V_215 ) ||
F_171 ( V_69 , V_258 , V_264 -> V_42 ) ||
F_173 ( V_69 , V_251 , V_264 -> V_108 ) )
goto V_265;
return 0 ;
V_265:
return - V_188 ;
}
struct V_32 * F_175 ( const struct V_7 * V_8 )
{
struct V_22 * V_263 = F_29 ( V_8 ) ;
return V_263 -> V_32 ;
}
static void T_11 F_176 ( struct V_32 * V_32 )
{
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
struct V_7 * V_8 , * V_266 ;
int V_47 ;
struct V_22 * V_23 ;
F_177 ( V_267 ) ;
F_178 (net, dev, aux)
if ( V_8 -> V_56 == & V_57 )
F_167 ( V_8 , & V_267 ) ;
for ( V_47 = 0 ; V_47 < V_268 ; V_47 ++ ) {
V_23 = F_23 ( V_36 -> V_269 [ V_47 ] ) ;
while ( V_23 ) {
if ( ! F_113 ( F_30 ( V_23 -> V_8 ) , V_32 ) )
F_167 ( V_23 -> V_8 , & V_267 ) ;
V_23 = F_23 ( V_23 -> V_51 ) ;
}
}
F_179 ( & V_267 ) ;
}
static int T_9 F_180 ( struct V_32 * V_32 )
{
struct V_35 * V_36 = F_15 ( V_32 , V_37 ) ;
struct V_22 * V_23 = NULL ;
int V_53 ;
V_36 -> V_49 [ 0 ] = V_36 -> V_44 ;
V_36 -> V_49 [ 1 ] = V_36 -> V_269 ;
V_53 = - V_59 ;
V_36 -> V_67 = F_35 ( sizeof( struct V_22 ) , L_10 ,
V_60 , V_61 ) ;
if ( ! V_36 -> V_67 )
goto V_270;
F_36 ( V_36 -> V_67 , V_32 ) ;
V_36 -> V_67 -> V_56 = & V_57 ;
V_36 -> V_67 -> V_271 |= V_272 ;
V_53 = F_157 ( V_36 -> V_67 ) ;
if ( V_53 < 0 )
goto V_273;
V_53 = F_181 ( V_36 -> V_67 ) ;
if ( V_53 < 0 )
goto V_273;
V_23 = F_29 ( V_36 -> V_67 ) ;
strcpy ( V_23 -> V_39 . V_55 , V_36 -> V_67 -> V_55 ) ;
return 0 ;
V_273:
F_25 ( V_36 -> V_67 ) ;
V_270:
return V_53 ;
}
static void T_11 F_182 ( struct V_32 * V_32 )
{
F_183 () ;
F_176 ( V_32 ) ;
F_184 () ;
}
static int T_12 F_185 ( void )
{
int V_53 ;
V_53 = F_186 ( & V_274 ) ;
if ( V_53 < 0 )
goto V_275;
V_53 = F_187 ( & V_276 , V_277 ) ;
if ( V_53 < 0 ) {
F_188 ( L_11 , V_278 ) ;
goto V_279;
}
V_53 = F_187 ( & V_280 , V_281 ) ;
if ( V_53 < 0 ) {
F_188 ( L_12 , V_278 ) ;
goto V_282;
}
V_53 = F_189 ( & V_57 ) ;
if ( V_53 < 0 )
goto V_283;
return 0 ;
V_283:
F_190 ( & V_280 , V_281 ) ;
V_282:
F_190 ( & V_276 , V_277 ) ;
V_279:
F_191 ( & V_274 ) ;
V_275:
return V_53 ;
}
static void T_13 F_192 ( void )
{
F_193 ( & V_57 ) ;
if ( F_190 ( & V_276 , V_277 ) )
F_194 ( L_13 , V_278 ) ;
if ( F_190 ( & V_280 , V_281 ) )
F_194 ( L_14 , V_278 ) ;
F_191 ( & V_274 ) ;
}
