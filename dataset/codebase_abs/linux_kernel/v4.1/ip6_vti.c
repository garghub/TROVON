static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_7 * V_7 , const struct V_1 * V_8 ,
const struct V_1 * V_9 )
{
unsigned int V_4 = F_1 ( V_8 , V_9 ) ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_1 V_14 ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
F_7 ( V_8 , & V_10 -> V_15 . V_17 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_4 = F_1 ( & V_14 , V_9 ) ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
V_4 = F_1 ( V_8 , & V_14 ) ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_8 , & V_10 -> V_15 . V_17 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
V_10 = F_8 ( V_12 -> V_21 [ 0 ] ) ;
if ( V_10 && ( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
return NULL ;
}
static struct V_6 T_2 * *
F_9 ( struct V_11 * V_12 , const struct V_22 * V_23 )
{
const struct V_1 * V_8 = & V_23 -> V_17 ;
const struct V_1 * V_9 = & V_23 -> V_16 ;
unsigned int V_24 = 0 ;
int V_25 = 0 ;
if ( ! F_10 ( V_8 ) || ! F_10 ( V_9 ) ) {
V_25 = 1 ;
V_24 = F_1 ( V_8 , V_9 ) ;
}
return & V_12 -> V_26 [ V_25 ] [ V_24 ] ;
}
static void
F_11 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_27 = F_9 ( V_12 , & V_10 -> V_15 ) ;
F_12 ( V_10 -> V_28 , F_13 ( * V_27 ) ) ;
F_12 ( * V_27 , V_10 ) ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_27 ;
struct V_6 * V_29 ;
for ( V_27 = F_9 ( V_12 , & V_10 -> V_15 ) ;
( V_29 = F_13 ( * V_27 ) ) != NULL ;
V_27 = & V_29 -> V_28 ) {
if ( V_10 == V_29 ) {
F_12 ( * V_27 , V_10 -> V_28 ) ;
break;
}
}
}
static void F_15 ( struct V_30 * V_18 )
{
F_16 ( V_18 -> V_31 ) ;
F_17 ( V_18 ) ;
}
static int F_18 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
V_32 = F_21 ( V_18 ) ;
if ( V_32 < 0 )
goto V_33;
strcpy ( V_10 -> V_15 . V_34 , V_18 -> V_34 ) ;
V_18 -> V_35 = & V_36 ;
F_22 ( V_18 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_33:
return V_32 ;
}
static struct V_6 * F_23 ( struct V_7 * V_7 , struct V_22 * V_23 )
{
struct V_30 * V_18 ;
struct V_6 * V_10 ;
char V_34 [ V_37 ] ;
int V_32 ;
if ( V_23 -> V_34 [ 0 ] )
F_24 ( V_34 , V_23 -> V_34 , V_37 ) ;
else
sprintf ( V_34 , L_1 ) ;
V_18 = F_25 ( sizeof( * V_10 ) , V_34 , V_38 , V_39 ) ;
if ( ! V_18 )
goto V_40;
F_26 ( V_18 , V_7 ) ;
V_10 = F_19 ( V_18 ) ;
V_10 -> V_15 = * V_23 ;
V_10 -> V_7 = F_20 ( V_18 ) ;
V_32 = F_18 ( V_18 ) ;
if ( V_32 < 0 )
goto V_41;
return V_10 ;
V_41:
F_15 ( V_18 ) ;
V_40:
return NULL ;
}
static struct V_6 * F_27 ( struct V_7 * V_7 , struct V_22 * V_23 ,
int V_42 )
{
const struct V_1 * V_8 = & V_23 -> V_17 ;
const struct V_1 * V_9 = & V_23 -> V_16 ;
struct V_6 T_2 * * V_27 ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
for ( V_27 = F_9 ( V_12 , V_23 ) ;
( V_10 = F_13 ( * V_27 ) ) != NULL ;
V_27 = & V_10 -> V_28 ) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
F_7 ( V_8 , & V_10 -> V_15 . V_17 ) ) {
if ( V_42 )
return NULL ;
return V_10 ;
}
}
if ( ! V_42 )
return NULL ;
return F_23 ( V_7 , V_23 ) ;
}
static void F_28 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_10 -> V_7 , V_13 ) ;
if ( V_18 == V_12 -> V_43 )
F_29 ( V_12 -> V_21 [ 0 ] , NULL ) ;
else
F_14 ( V_12 , V_10 ) ;
F_30 ( V_18 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
struct V_6 * V_10 ;
const struct V_46 * V_47 = F_32 ( V_45 ) ;
F_33 () ;
V_10 = F_4 ( F_20 ( V_45 -> V_18 ) , & V_47 -> V_48 , & V_47 -> V_49 ) ;
if ( V_10 ) {
if ( V_10 -> V_15 . V_50 != V_51 && V_10 -> V_15 . V_50 != 0 ) {
F_34 () ;
goto V_52;
}
if ( ! F_35 ( NULL , V_53 , V_45 ) ) {
F_34 () ;
return 0 ;
}
if ( ! F_36 ( V_10 , & V_47 -> V_49 , & V_47 -> V_48 ) ) {
V_10 -> V_18 -> V_54 . V_55 ++ ;
F_34 () ;
goto V_52;
}
F_37 ( V_45 ) -> V_56 . V_57 = V_10 ;
F_34 () ;
return F_38 ( V_45 ) ;
}
F_34 () ;
return - V_58 ;
V_52:
F_39 ( V_45 ) ;
return 0 ;
}
static int F_40 ( struct V_44 * V_45 , int V_32 )
{
unsigned short V_59 ;
struct V_30 * V_18 ;
struct V_60 * V_31 ;
struct V_61 * V_62 ;
struct V_6 * V_10 = F_37 ( V_45 ) -> V_56 . V_57 ;
T_1 V_63 = V_45 -> V_64 ;
int V_65 ;
if ( ! V_10 )
return 1 ;
V_18 = V_10 -> V_18 ;
if ( V_32 ) {
V_18 -> V_54 . V_66 ++ ;
V_18 -> V_54 . V_55 ++ ;
return 0 ;
}
V_62 = F_41 ( V_45 ) ;
V_59 = V_62 -> V_67 -> V_68 -> V_59 ;
V_45 -> V_64 = F_42 ( V_10 -> V_15 . V_69 ) ;
V_65 = F_43 ( NULL , V_53 , V_45 , V_59 ) ;
V_45 -> V_64 = V_63 ;
if ( ! V_65 )
return - V_70 ;
F_44 ( V_45 , ! F_45 ( V_10 -> V_7 , F_20 ( V_45 -> V_18 ) ) ) ;
V_45 -> V_18 = V_18 ;
V_31 = F_46 ( V_18 -> V_31 ) ;
F_47 ( & V_31 -> V_71 ) ;
V_31 -> V_72 ++ ;
V_31 -> V_73 += V_45 -> V_74 ;
F_48 ( & V_31 -> V_71 ) ;
return 0 ;
}
static inline bool
F_49 ( const struct V_6 * V_10 , const struct V_46 * V_75 )
{
return F_7 ( & V_10 -> V_15 . V_17 , & V_75 -> V_48 ) ;
}
static bool F_50 ( const struct V_61 * V_62 ,
const struct V_1 * V_76 ,
const struct V_1 * V_77 )
{
T_3 * V_49 = ( T_3 * ) V_76 ;
T_3 * V_48 = ( T_3 * ) V_77 ;
if ( ! V_62 || V_62 -> V_78 . V_79 != V_80 ||
V_62 -> V_78 . V_59 != V_81 )
return false ;
if ( F_10 ( V_76 ) )
return F_51 ( V_48 , & V_62 -> V_78 . V_48 , V_81 ) ;
if ( ! F_52 ( V_62 , V_49 , V_48 , V_81 ) )
return false ;
return true ;
}
static int
F_53 ( struct V_44 * V_45 , struct V_30 * V_18 , struct V_82 * V_83 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_84 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_85 * V_76 = F_54 ( V_45 ) ;
struct V_30 * V_86 ;
struct V_61 * V_62 ;
int V_32 = - 1 ;
int V_87 ;
if ( ! V_76 )
goto V_88;
F_55 ( V_76 ) ;
V_76 = F_56 ( V_10 -> V_7 , V_76 , V_83 , NULL , 0 ) ;
if ( F_57 ( V_76 ) ) {
V_32 = F_58 ( V_76 ) ;
V_76 = NULL ;
goto V_88;
}
V_62 = V_76 -> V_89 ;
if ( ! F_50 ( V_62 , & V_10 -> V_15 . V_17 , & V_10 -> V_15 . V_16 ) )
goto V_88;
if ( ! F_59 ( V_10 , ( const struct V_1 * ) & V_62 -> V_78 . V_48 ,
( const struct V_1 * ) & V_62 -> V_90 . V_49 ) )
goto V_88;
V_86 = V_76 -> V_18 ;
if ( V_86 == V_18 ) {
V_54 -> V_91 ++ ;
F_60 ( L_2 ,
V_10 -> V_15 . V_34 ) ;
goto V_92;
}
F_44 ( V_45 , ! F_45 ( V_10 -> V_7 , F_20 ( V_18 ) ) ) ;
F_61 ( V_45 , V_76 ) ;
V_45 -> V_18 = F_54 ( V_45 ) -> V_18 ;
V_87 = F_62 ( V_76 ) ;
if ( ! V_45 -> V_93 && V_45 -> V_74 > V_87 ) {
F_54 ( V_45 ) -> V_94 -> V_95 ( V_76 , NULL , V_45 , V_87 ) ;
if ( V_45 -> V_96 == F_63 ( V_97 ) )
F_64 ( V_45 , V_98 , 0 , V_87 ) ;
else
F_65 ( V_45 , V_99 , V_100 ,
F_66 ( V_87 ) ) ;
return - V_101 ;
}
V_32 = F_67 ( V_45 ) ;
if ( F_68 ( V_32 ) == 0 ) {
struct V_60 * V_31 = F_46 ( V_18 -> V_31 ) ;
F_47 ( & V_31 -> V_71 ) ;
V_31 -> V_102 += V_45 -> V_74 ;
V_31 -> V_103 ++ ;
F_48 ( & V_31 -> V_71 ) ;
} else {
V_54 -> V_104 ++ ;
V_54 -> V_105 ++ ;
}
return 0 ;
V_88:
V_54 -> V_106 ++ ;
F_69 ( V_45 ) ;
V_92:
F_70 ( V_76 ) ;
return V_32 ;
}
static T_4
F_71 ( struct V_44 * V_45 , struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_84 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_46 * V_47 ;
struct V_82 V_83 ;
int V_65 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
switch ( V_45 -> V_96 ) {
case F_63 ( V_97 ) :
V_47 = F_32 ( V_45 ) ;
if ( ( V_10 -> V_15 . V_50 != V_51 && V_10 -> V_15 . V_50 != 0 ) ||
F_49 ( V_10 , V_47 ) )
goto V_107;
F_72 ( V_45 , & V_83 , V_81 ) ;
memset ( F_73 ( V_45 ) , 0 , sizeof( * F_73 ( V_45 ) ) ) ;
break;
case F_63 ( V_108 ) :
F_72 ( V_45 , & V_83 , V_109 ) ;
memset ( F_74 ( V_45 ) , 0 , sizeof( * F_74 ( V_45 ) ) ) ;
break;
default:
goto V_107;
}
V_83 . V_110 = F_42 ( V_10 -> V_15 . V_111 ) ;
V_65 = F_53 ( V_45 , V_18 , & V_83 ) ;
if ( V_65 < 0 )
goto V_107;
return V_112 ;
V_107:
V_54 -> V_104 ++ ;
V_54 -> V_113 ++ ;
F_39 ( V_45 ) ;
return V_112 ;
}
static int F_75 ( struct V_44 * V_45 , struct V_114 * V_115 ,
T_5 type , T_5 V_116 , int V_117 , T_6 V_118 )
{
T_6 V_119 ;
T_7 V_64 ;
struct V_61 * V_62 ;
struct V_6 * V_10 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_7 * V_7 = F_20 ( V_45 -> V_18 ) ;
const struct V_46 * V_126 = ( const struct V_46 * ) V_45 -> V_127 ;
int V_96 = V_126 -> V_128 ;
V_10 = F_4 ( F_20 ( V_45 -> V_18 ) , & V_126 -> V_49 , & V_126 -> V_48 ) ;
if ( ! V_10 )
return - 1 ;
V_64 = F_42 ( V_10 -> V_15 . V_111 ) ;
switch ( V_96 ) {
case V_129 :
V_121 = (struct V_120 * ) ( V_45 -> V_127 + V_117 ) ;
V_119 = V_121 -> V_119 ;
break;
case V_130 :
V_123 = (struct V_122 * ) ( V_45 -> V_127 + V_117 ) ;
V_119 = V_123 -> V_119 ;
break;
case V_131 :
V_125 = (struct V_124 * ) ( V_45 -> V_127 + V_117 ) ;
V_119 = F_66 ( F_76 ( V_125 -> V_132 ) ) ;
break;
default:
return 0 ;
}
if ( type != V_98 &&
type != V_133 )
return 0 ;
V_62 = F_77 ( V_7 , V_64 , ( const T_3 * ) & V_126 -> V_49 ,
V_119 , V_96 , V_81 ) ;
if ( ! V_62 )
return 0 ;
if ( type == V_133 )
F_78 ( V_45 , V_7 , V_45 -> V_18 -> V_134 , 0 ) ;
else
F_79 ( V_45 , V_7 , V_118 , 0 , 0 ) ;
F_80 ( V_62 ) ;
return 0 ;
}
static void F_81 ( struct V_6 * V_10 )
{
struct V_30 * V_18 = V_10 -> V_18 ;
struct V_22 * V_23 = & V_10 -> V_15 ;
memcpy ( V_18 -> V_135 , & V_23 -> V_16 , sizeof( struct V_1 ) ) ;
memcpy ( V_18 -> V_136 , & V_23 -> V_17 , sizeof( struct V_1 ) ) ;
V_23 -> V_19 &= ~ ( V_137 | V_138 |
V_139 ) ;
V_23 -> V_19 |= F_82 ( V_10 , & V_23 -> V_16 , & V_23 -> V_17 ) ;
if ( V_23 -> V_19 & V_137 && V_23 -> V_19 & V_138 )
V_18 -> V_19 |= V_140 ;
else
V_18 -> V_19 &= ~ V_140 ;
}
static int
F_83 ( struct V_6 * V_10 , const struct V_22 * V_23 )
{
V_10 -> V_15 . V_16 = V_23 -> V_16 ;
V_10 -> V_15 . V_17 = V_23 -> V_17 ;
V_10 -> V_15 . V_141 = V_23 -> V_141 ;
V_10 -> V_15 . V_69 = V_23 -> V_69 ;
V_10 -> V_15 . V_111 = V_23 -> V_111 ;
V_10 -> V_15 . V_50 = V_23 -> V_50 ;
F_84 ( V_10 ) ;
F_81 ( V_10 ) ;
return 0 ;
}
static int F_85 ( struct V_6 * V_10 , struct V_22 * V_23 )
{
struct V_7 * V_7 = F_20 ( V_10 -> V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
F_14 ( V_12 , V_10 ) ;
F_86 () ;
V_32 = F_83 ( V_10 , V_23 ) ;
F_11 ( V_12 , V_10 ) ;
F_87 ( V_10 -> V_18 ) ;
return V_32 ;
}
static void
F_88 ( struct V_22 * V_23 , const struct V_142 * V_143 )
{
V_23 -> V_16 = V_143 -> V_16 ;
V_23 -> V_17 = V_143 -> V_17 ;
V_23 -> V_141 = V_143 -> V_141 ;
V_23 -> V_69 = V_143 -> V_69 ;
V_23 -> V_111 = V_143 -> V_111 ;
V_23 -> V_50 = V_143 -> V_50 ;
memcpy ( V_23 -> V_34 , V_143 -> V_34 , sizeof( V_143 -> V_34 ) ) ;
}
static void
F_89 ( struct V_142 * V_143 , const struct V_22 * V_23 )
{
V_143 -> V_16 = V_23 -> V_16 ;
V_143 -> V_17 = V_23 -> V_17 ;
V_143 -> V_141 = V_23 -> V_141 ;
V_143 -> V_69 = V_23 -> V_69 ;
V_143 -> V_111 = V_23 -> V_111 ;
V_143 -> V_50 = V_23 -> V_50 ;
memcpy ( V_143 -> V_34 , V_23 -> V_34 , sizeof( V_143 -> V_34 ) ) ;
}
static int
F_90 ( struct V_30 * V_18 , struct V_144 * V_145 , int V_146 )
{
int V_32 = 0 ;
struct V_142 V_23 ;
struct V_22 V_147 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_146 ) {
case V_148 :
if ( V_18 == V_12 -> V_43 ) {
if ( F_91 ( & V_23 , V_145 -> V_149 . V_150 , sizeof( V_23 ) ) ) {
V_32 = - V_151 ;
break;
}
F_88 ( & V_147 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_147 , 0 ) ;
} else {
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
}
if ( ! V_10 )
V_10 = F_19 ( V_18 ) ;
F_89 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_92 ( V_145 -> V_149 . V_150 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_151 ;
break;
case V_152 :
case V_153 :
V_32 = - V_70 ;
if ( ! F_93 ( V_7 -> V_154 , V_155 ) )
break;
V_32 = - V_151 ;
if ( F_91 ( & V_23 , V_145 -> V_149 . V_150 , sizeof( V_23 ) ) )
break;
V_32 = - V_58 ;
if ( V_23 . V_50 != V_51 && V_23 . V_50 != 0 )
break;
F_88 ( & V_147 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_147 , V_146 == V_152 ) ;
if ( V_18 != V_12 -> V_43 && V_146 == V_153 ) {
if ( V_10 ) {
if ( V_10 -> V_18 != V_18 ) {
V_32 = - V_156 ;
break;
}
} else
V_10 = F_19 ( V_18 ) ;
V_32 = F_85 ( V_10 , & V_147 ) ;
}
if ( V_10 ) {
V_32 = 0 ;
F_89 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_92 ( V_145 -> V_149 . V_150 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_151 ;
} else
V_32 = ( V_146 == V_152 ? - V_157 : - V_158 ) ;
break;
case V_159 :
V_32 = - V_70 ;
if ( ! F_93 ( V_7 -> V_154 , V_155 ) )
break;
if ( V_18 == V_12 -> V_43 ) {
V_32 = - V_151 ;
if ( F_91 ( & V_23 , V_145 -> V_149 . V_150 , sizeof( V_23 ) ) )
break;
V_32 = - V_158 ;
F_88 ( & V_147 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_147 , 0 ) ;
if ( ! V_10 )
break;
V_32 = - V_70 ;
if ( V_10 -> V_18 == V_12 -> V_43 )
break;
V_18 = V_10 -> V_18 ;
}
V_32 = 0 ;
F_94 ( V_18 ) ;
break;
default:
V_32 = - V_58 ;
}
return V_32 ;
}
static int F_95 ( struct V_30 * V_18 , int V_160 )
{
if ( V_160 < V_161 )
return - V_58 ;
V_18 -> V_87 = V_160 ;
return 0 ;
}
static void V_39 ( struct V_30 * V_18 )
{
V_18 -> V_162 = & V_163 ;
V_18 -> V_164 = F_15 ;
V_18 -> type = V_165 ;
V_18 -> V_166 = V_167 + sizeof( struct V_46 ) ;
V_18 -> V_87 = V_168 ;
V_18 -> V_19 |= V_169 ;
V_18 -> V_170 = sizeof( struct V_1 ) ;
F_96 ( V_18 ) ;
}
static inline int F_97 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_7 = F_20 ( V_18 ) ;
V_18 -> V_31 = F_98 ( struct V_60 ) ;
if ( ! V_18 -> V_31 )
return - V_171 ;
return 0 ;
}
static int F_99 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
int V_32 = F_97 ( V_18 ) ;
if ( V_32 )
return V_32 ;
F_81 ( V_10 ) ;
return 0 ;
}
static int T_8 F_100 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
V_10 -> V_15 . V_50 = V_51 ;
F_22 ( V_18 ) ;
F_12 ( V_12 -> V_21 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_101 ( struct V_172 * V_173 [] , struct V_172 * V_127 [] )
{
return 0 ;
}
static void F_102 ( struct V_172 * V_127 [] ,
struct V_22 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( ! V_127 )
return;
if ( V_127 [ V_174 ] )
V_15 -> V_141 = F_103 ( V_127 [ V_174 ] ) ;
if ( V_127 [ V_175 ] )
V_15 -> V_16 = F_104 ( V_127 [ V_175 ] ) ;
if ( V_127 [ V_176 ] )
V_15 -> V_17 = F_104 ( V_127 [ V_176 ] ) ;
if ( V_127 [ V_177 ] )
V_15 -> V_69 = F_105 ( V_127 [ V_177 ] ) ;
if ( V_127 [ V_178 ] )
V_15 -> V_111 = F_105 ( V_127 [ V_178 ] ) ;
}
static int F_106 ( struct V_7 * V_179 , struct V_30 * V_18 ,
struct V_172 * V_173 [] , struct V_172 * V_127 [] )
{
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_6 * V_180 ;
V_180 = F_19 ( V_18 ) ;
F_102 ( V_127 , & V_180 -> V_15 ) ;
V_180 -> V_15 . V_50 = V_51 ;
if ( F_27 ( V_7 , & V_180 -> V_15 , 0 ) )
return - V_156 ;
return F_18 ( V_18 ) ;
}
static void F_107 ( struct V_30 * V_18 , struct V_181 * V_182 )
{
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 != V_12 -> V_43 )
F_108 ( V_18 , V_182 ) ;
}
static int F_109 ( struct V_30 * V_18 , struct V_172 * V_173 [] ,
struct V_172 * V_127 [] )
{
struct V_6 * V_10 ;
struct V_22 V_23 ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 == V_12 -> V_43 )
return - V_58 ;
F_102 ( V_127 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_23 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_18 != V_18 )
return - V_156 ;
} else
V_10 = F_19 ( V_18 ) ;
return F_85 ( V_10 , & V_23 ) ;
}
static T_9 F_110 ( const struct V_30 * V_18 )
{
return
F_111 ( 4 ) +
F_111 ( sizeof( struct V_1 ) ) +
F_111 ( sizeof( struct V_1 ) ) +
F_111 ( 4 ) +
F_111 ( 4 ) +
0 ;
}
static int F_112 ( struct V_44 * V_45 , const struct V_30 * V_18 )
{
struct V_6 * V_56 = F_19 ( V_18 ) ;
struct V_22 * V_183 = & V_56 -> V_15 ;
if ( F_113 ( V_45 , V_174 , V_183 -> V_141 ) ||
F_114 ( V_45 , V_175 , & V_183 -> V_16 ) ||
F_114 ( V_45 , V_176 , & V_183 -> V_17 ) ||
F_115 ( V_45 , V_177 , V_183 -> V_69 ) ||
F_115 ( V_45 , V_178 , V_183 -> V_111 ) )
goto V_184;
return 0 ;
V_184:
return - V_101 ;
}
static void T_10 F_116 ( struct V_11 * V_12 )
{
int V_24 ;
struct V_6 * V_10 ;
F_117 ( V_185 ) ;
for ( V_24 = 0 ; V_24 < V_186 ; V_24 ++ ) {
V_10 = F_13 ( V_12 -> V_187 [ V_24 ] ) ;
while ( V_10 ) {
F_108 ( V_10 -> V_18 , & V_185 ) ;
V_10 = F_13 ( V_10 -> V_28 ) ;
}
}
V_10 = F_13 ( V_12 -> V_21 [ 0 ] ) ;
F_108 ( V_10 -> V_18 , & V_185 ) ;
F_118 ( & V_185 ) ;
}
static int T_8 F_119 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_32 ;
V_12 -> V_26 [ 0 ] = V_12 -> V_21 ;
V_12 -> V_26 [ 1 ] = V_12 -> V_187 ;
V_32 = - V_171 ;
V_12 -> V_43 = F_25 ( sizeof( struct V_6 ) , L_3 ,
V_38 , V_39 ) ;
if ( ! V_12 -> V_43 )
goto V_188;
F_26 ( V_12 -> V_43 , V_7 ) ;
V_12 -> V_43 -> V_35 = & V_36 ;
V_32 = F_100 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_189;
V_32 = F_120 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_189;
V_10 = F_19 ( V_12 -> V_43 ) ;
strcpy ( V_10 -> V_15 . V_34 , V_12 -> V_43 -> V_34 ) ;
return 0 ;
V_189:
F_15 ( V_12 -> V_43 ) ;
V_188:
return V_32 ;
}
static void T_10 F_121 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_122 () ;
F_116 ( V_12 ) ;
F_123 () ;
}
static int T_11 F_124 ( void )
{
const char * V_190 ;
int V_32 ;
V_190 = L_4 ;
V_32 = F_125 ( & V_191 ) ;
if ( V_32 < 0 )
goto V_192;
V_190 = L_5 ;
V_32 = F_126 ( & V_193 , V_129 ) ;
if ( V_32 < 0 )
goto V_194;
V_32 = F_126 ( & V_195 , V_130 ) ;
if ( V_32 < 0 )
goto V_196;
V_32 = F_126 ( & V_197 , V_131 ) ;
if ( V_32 < 0 )
goto V_198;
V_190 = L_6 ;
V_32 = F_127 ( & V_36 ) ;
if ( V_32 < 0 )
goto V_199;
return 0 ;
V_199:
F_128 ( & V_197 , V_131 ) ;
V_198:
F_128 ( & V_195 , V_130 ) ;
V_196:
F_128 ( & V_193 , V_129 ) ;
V_194:
F_129 ( & V_191 ) ;
V_192:
F_130 ( L_7 , V_190 ) ;
return V_32 ;
}
static void T_12 F_131 ( void )
{
F_132 ( & V_36 ) ;
F_128 ( & V_197 , V_131 ) ;
F_128 ( & V_195 , V_130 ) ;
F_128 ( & V_193 , V_129 ) ;
F_129 ( & V_191 ) ;
}
