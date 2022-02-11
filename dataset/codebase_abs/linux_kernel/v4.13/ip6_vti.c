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
}
static int F_17 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
V_18 -> V_33 = & V_34 ;
V_32 = F_20 ( V_18 ) ;
if ( V_32 < 0 )
goto V_35;
strcpy ( V_10 -> V_15 . V_36 , V_18 -> V_36 ) ;
F_21 ( V_18 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_35:
return V_32 ;
}
static struct V_6 * F_22 ( struct V_7 * V_7 , struct V_22 * V_23 )
{
struct V_30 * V_18 ;
struct V_6 * V_10 ;
char V_36 [ V_37 ] ;
int V_32 ;
if ( V_23 -> V_36 [ 0 ] )
F_23 ( V_36 , V_23 -> V_36 , V_37 ) ;
else
sprintf ( V_36 , L_1 ) ;
V_18 = F_24 ( sizeof( * V_10 ) , V_36 , V_38 , V_39 ) ;
if ( ! V_18 )
goto V_40;
F_25 ( V_18 , V_7 ) ;
V_10 = F_18 ( V_18 ) ;
V_10 -> V_15 = * V_23 ;
V_10 -> V_7 = F_19 ( V_18 ) ;
V_32 = F_17 ( V_18 ) ;
if ( V_32 < 0 )
goto V_41;
return V_10 ;
V_41:
F_26 ( V_18 ) ;
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
return F_22 ( V_7 , V_23 ) ;
}
static void F_28 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
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
V_10 = F_4 ( F_19 ( V_45 -> V_18 ) , & V_47 -> V_48 , & V_47 -> V_49 ) ;
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
F_34 () ;
return F_37 ( V_45 , V_10 ) ;
}
F_34 () ;
return - V_56 ;
V_52:
F_38 ( V_45 ) ;
return 0 ;
}
static int F_39 ( struct V_44 * V_45 , int V_32 )
{
unsigned short V_57 ;
struct V_30 * V_18 ;
struct V_58 * V_31 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_6 * V_10 = F_40 ( V_45 ) -> V_63 . V_64 ;
T_1 V_65 = V_45 -> V_66 ;
int V_67 ;
if ( ! V_10 )
return 1 ;
V_18 = V_10 -> V_18 ;
if ( V_32 ) {
V_18 -> V_54 . V_68 ++ ;
V_18 -> V_54 . V_55 ++ ;
return 0 ;
}
V_60 = F_41 ( V_45 ) ;
V_62 = V_60 -> V_62 ;
if ( V_60 -> V_69 . V_57 == V_70 ) {
V_62 = F_42 ( V_60 , F_43 ( V_45 ) -> V_71 ) ;
if ( V_62 == NULL ) {
F_44 ( F_19 ( V_45 -> V_18 ) ,
V_72 ) ;
return - V_56 ;
}
}
V_57 = V_62 -> V_73 -> V_57 ;
V_45 -> V_66 = F_45 ( V_10 -> V_15 . V_74 ) ;
V_67 = F_46 ( NULL , V_53 , V_45 , V_57 ) ;
V_45 -> V_66 = V_65 ;
if ( ! V_67 )
return - V_75 ;
F_47 ( V_45 , ! F_48 ( V_10 -> V_7 , F_19 ( V_45 -> V_18 ) ) ) ;
V_45 -> V_18 = V_18 ;
V_31 = F_49 ( V_18 -> V_31 ) ;
F_50 ( & V_31 -> V_76 ) ;
V_31 -> V_77 ++ ;
V_31 -> V_78 += V_45 -> V_79 ;
F_51 ( & V_31 -> V_76 ) ;
return 0 ;
}
static inline bool
F_52 ( const struct V_6 * V_10 , const struct V_46 * V_80 )
{
return F_7 ( & V_10 -> V_15 . V_17 , & V_80 -> V_48 ) ;
}
static bool F_53 ( const struct V_59 * V_60 ,
const struct V_1 * V_81 ,
const struct V_1 * V_82 )
{
T_3 * V_49 = ( T_3 * ) V_81 ;
T_3 * V_48 = ( T_3 * ) V_82 ;
if ( ! V_60 || V_60 -> V_83 . V_84 != V_85 ||
V_60 -> V_83 . V_57 != V_86 )
return false ;
if ( F_10 ( V_81 ) )
return F_54 ( V_48 , & V_60 -> V_83 . V_48 , V_86 ) ;
if ( ! F_55 ( V_60 , V_49 , V_48 , V_86 ) )
return false ;
return true ;
}
static int
F_56 ( struct V_44 * V_45 , struct V_30 * V_18 , struct V_87 * V_88 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
struct V_89 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_90 * V_81 = F_57 ( V_45 ) ;
struct V_30 * V_91 ;
struct V_59 * V_60 ;
int V_32 = - 1 ;
int V_92 ;
if ( ! V_81 )
goto V_93;
F_58 ( V_81 ) ;
V_81 = F_59 ( V_10 -> V_7 , V_81 , V_88 , NULL , 0 ) ;
if ( F_60 ( V_81 ) ) {
V_32 = F_61 ( V_81 ) ;
V_81 = NULL ;
goto V_93;
}
V_60 = V_81 -> V_94 ;
if ( ! F_53 ( V_60 , & V_10 -> V_15 . V_17 , & V_10 -> V_15 . V_16 ) )
goto V_93;
if ( ! F_62 ( V_10 , ( const struct V_1 * ) & V_60 -> V_83 . V_48 ,
( const struct V_1 * ) & V_60 -> V_95 . V_49 ) )
goto V_93;
V_91 = V_81 -> V_18 ;
if ( V_91 == V_18 ) {
V_54 -> V_96 ++ ;
F_63 ( L_2 ,
V_10 -> V_15 . V_36 ) ;
goto V_97;
}
F_47 ( V_45 , ! F_48 ( V_10 -> V_7 , F_19 ( V_18 ) ) ) ;
F_64 ( V_45 , V_81 ) ;
V_45 -> V_18 = F_57 ( V_45 ) -> V_18 ;
V_92 = F_65 ( V_81 ) ;
if ( ! V_45 -> V_98 && V_45 -> V_79 > V_92 ) {
F_57 ( V_45 ) -> V_99 -> V_100 ( V_81 , NULL , V_45 , V_92 ) ;
if ( V_45 -> V_71 == F_66 ( V_101 ) ) {
if ( V_92 < V_102 )
V_92 = V_102 ;
F_67 ( V_45 , V_103 , 0 , V_92 ) ;
} else {
F_68 ( V_45 , V_104 , V_105 ,
F_69 ( V_92 ) ) ;
}
return - V_106 ;
}
V_32 = F_70 ( V_10 -> V_7 , V_45 -> V_107 , V_45 ) ;
if ( F_71 ( V_32 ) == 0 ) {
struct V_58 * V_31 = F_49 ( V_18 -> V_31 ) ;
F_50 ( & V_31 -> V_76 ) ;
V_31 -> V_108 += V_45 -> V_79 ;
V_31 -> V_109 ++ ;
F_51 ( & V_31 -> V_76 ) ;
} else {
V_54 -> V_110 ++ ;
V_54 -> V_111 ++ ;
}
return 0 ;
V_93:
V_54 -> V_112 ++ ;
F_72 ( V_45 ) ;
V_97:
F_73 ( V_81 ) ;
return V_32 ;
}
static T_4
F_74 ( struct V_44 * V_45 , struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
struct V_89 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_46 * V_47 ;
struct V_87 V_88 ;
int V_67 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
switch ( V_45 -> V_71 ) {
case F_66 ( V_101 ) :
V_47 = F_32 ( V_45 ) ;
if ( ( V_10 -> V_15 . V_50 != V_51 && V_10 -> V_15 . V_50 != 0 ) ||
F_52 ( V_10 , V_47 ) )
goto V_113;
F_75 ( V_45 , & V_88 , V_86 ) ;
memset ( F_76 ( V_45 ) , 0 , sizeof( * F_76 ( V_45 ) ) ) ;
break;
case F_66 ( V_114 ) :
F_75 ( V_45 , & V_88 , V_115 ) ;
memset ( F_77 ( V_45 ) , 0 , sizeof( * F_77 ( V_45 ) ) ) ;
break;
default:
goto V_113;
}
V_88 . V_116 = F_45 ( V_10 -> V_15 . V_117 ) ;
V_67 = F_56 ( V_45 , V_18 , & V_88 ) ;
if ( V_67 < 0 )
goto V_113;
return V_118 ;
V_113:
V_54 -> V_110 ++ ;
V_54 -> V_119 ++ ;
F_38 ( V_45 ) ;
return V_118 ;
}
static int F_78 ( struct V_44 * V_45 , struct V_120 * V_121 ,
T_5 type , T_5 V_122 , int V_123 , T_6 V_124 )
{
T_6 V_125 ;
T_7 V_66 ;
struct V_59 * V_60 ;
struct V_6 * V_10 ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_7 * V_7 = F_19 ( V_45 -> V_18 ) ;
const struct V_46 * V_132 = ( const struct V_46 * ) V_45 -> V_133 ;
int V_71 = V_132 -> V_134 ;
V_10 = F_4 ( F_19 ( V_45 -> V_18 ) , & V_132 -> V_49 , & V_132 -> V_48 ) ;
if ( ! V_10 )
return - 1 ;
V_66 = F_45 ( V_10 -> V_15 . V_117 ) ;
switch ( V_71 ) {
case V_135 :
V_127 = (struct V_126 * ) ( V_45 -> V_133 + V_123 ) ;
V_125 = V_127 -> V_125 ;
break;
case V_136 :
V_129 = (struct V_128 * ) ( V_45 -> V_133 + V_123 ) ;
V_125 = V_129 -> V_125 ;
break;
case V_137 :
V_131 = (struct V_130 * ) ( V_45 -> V_133 + V_123 ) ;
V_125 = F_69 ( F_79 ( V_131 -> V_138 ) ) ;
break;
default:
return 0 ;
}
if ( type != V_103 &&
type != V_139 )
return 0 ;
V_60 = F_80 ( V_7 , V_66 , ( const T_3 * ) & V_132 -> V_49 ,
V_125 , V_71 , V_86 ) ;
if ( ! V_60 )
return 0 ;
if ( type == V_139 )
F_81 ( V_45 , V_7 , V_45 -> V_18 -> V_140 , 0 ,
F_82 ( V_7 , NULL ) ) ;
else
F_83 ( V_45 , V_7 , V_124 , 0 , 0 , F_82 ( V_7 , NULL ) ) ;
F_84 ( V_60 ) ;
return 0 ;
}
static void F_85 ( struct V_6 * V_10 )
{
struct V_30 * V_18 = V_10 -> V_18 ;
struct V_22 * V_23 = & V_10 -> V_15 ;
memcpy ( V_18 -> V_141 , & V_23 -> V_16 , sizeof( struct V_1 ) ) ;
memcpy ( V_18 -> V_142 , & V_23 -> V_17 , sizeof( struct V_1 ) ) ;
V_23 -> V_19 &= ~ ( V_143 | V_144 |
V_145 ) ;
V_23 -> V_19 |= F_86 ( V_10 , & V_23 -> V_16 , & V_23 -> V_17 ) ;
if ( V_23 -> V_19 & V_143 && V_23 -> V_19 & V_144 )
V_18 -> V_19 |= V_146 ;
else
V_18 -> V_19 &= ~ V_146 ;
}
static int
F_87 ( struct V_6 * V_10 , const struct V_22 * V_23 )
{
V_10 -> V_15 . V_16 = V_23 -> V_16 ;
V_10 -> V_15 . V_17 = V_23 -> V_17 ;
V_10 -> V_15 . V_147 = V_23 -> V_147 ;
V_10 -> V_15 . V_74 = V_23 -> V_74 ;
V_10 -> V_15 . V_117 = V_23 -> V_117 ;
V_10 -> V_15 . V_50 = V_23 -> V_50 ;
V_10 -> V_15 . V_148 = V_23 -> V_148 ;
F_88 ( & V_10 -> V_149 ) ;
F_85 ( V_10 ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_10 , struct V_22 * V_23 )
{
struct V_7 * V_7 = F_19 ( V_10 -> V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
F_14 ( V_12 , V_10 ) ;
F_90 () ;
V_32 = F_87 ( V_10 , V_23 ) ;
F_11 ( V_12 , V_10 ) ;
F_91 ( V_10 -> V_18 ) ;
return V_32 ;
}
static void
F_92 ( struct V_22 * V_23 , const struct V_150 * V_151 )
{
V_23 -> V_16 = V_151 -> V_16 ;
V_23 -> V_17 = V_151 -> V_17 ;
V_23 -> V_147 = V_151 -> V_147 ;
V_23 -> V_74 = V_151 -> V_74 ;
V_23 -> V_117 = V_151 -> V_117 ;
V_23 -> V_50 = V_151 -> V_50 ;
memcpy ( V_23 -> V_36 , V_151 -> V_36 , sizeof( V_151 -> V_36 ) ) ;
}
static void
F_93 ( struct V_150 * V_151 , const struct V_22 * V_23 )
{
V_151 -> V_16 = V_23 -> V_16 ;
V_151 -> V_17 = V_23 -> V_17 ;
V_151 -> V_147 = V_23 -> V_147 ;
V_151 -> V_74 = V_23 -> V_74 ;
V_151 -> V_117 = V_23 -> V_117 ;
if ( V_151 -> V_74 )
V_151 -> V_152 |= V_153 ;
if ( V_151 -> V_117 )
V_151 -> V_154 |= V_153 ;
V_151 -> V_50 = V_23 -> V_50 ;
memcpy ( V_151 -> V_36 , V_23 -> V_36 , sizeof( V_151 -> V_36 ) ) ;
}
static int
F_94 ( struct V_30 * V_18 , struct V_155 * V_156 , int V_157 )
{
int V_32 = 0 ;
struct V_150 V_23 ;
struct V_22 V_158 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_157 ) {
case V_159 :
if ( V_18 == V_12 -> V_43 ) {
if ( F_95 ( & V_23 , V_156 -> V_160 . V_161 , sizeof( V_23 ) ) ) {
V_32 = - V_162 ;
break;
}
F_92 ( & V_158 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_158 , 0 ) ;
} else {
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
}
if ( ! V_10 )
V_10 = F_18 ( V_18 ) ;
F_93 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_96 ( V_156 -> V_160 . V_161 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_162 ;
break;
case V_163 :
case V_164 :
V_32 = - V_75 ;
if ( ! F_97 ( V_7 -> V_165 , V_166 ) )
break;
V_32 = - V_162 ;
if ( F_95 ( & V_23 , V_156 -> V_160 . V_161 , sizeof( V_23 ) ) )
break;
V_32 = - V_56 ;
if ( V_23 . V_50 != V_51 && V_23 . V_50 != 0 )
break;
F_92 ( & V_158 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_158 , V_157 == V_163 ) ;
if ( V_18 != V_12 -> V_43 && V_157 == V_164 ) {
if ( V_10 ) {
if ( V_10 -> V_18 != V_18 ) {
V_32 = - V_167 ;
break;
}
} else
V_10 = F_18 ( V_18 ) ;
V_32 = F_89 ( V_10 , & V_158 ) ;
}
if ( V_10 ) {
V_32 = 0 ;
F_93 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_96 ( V_156 -> V_160 . V_161 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_162 ;
} else
V_32 = ( V_157 == V_163 ? - V_168 : - V_169 ) ;
break;
case V_170 :
V_32 = - V_75 ;
if ( ! F_97 ( V_7 -> V_165 , V_166 ) )
break;
if ( V_18 == V_12 -> V_43 ) {
V_32 = - V_162 ;
if ( F_95 ( & V_23 , V_156 -> V_160 . V_161 , sizeof( V_23 ) ) )
break;
V_32 = - V_169 ;
F_92 ( & V_158 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_158 , 0 ) ;
if ( ! V_10 )
break;
V_32 = - V_75 ;
if ( V_10 -> V_18 == V_12 -> V_43 )
break;
V_18 = V_10 -> V_18 ;
}
V_32 = 0 ;
F_98 ( V_18 ) ;
break;
default:
V_32 = - V_56 ;
}
return V_32 ;
}
static void V_39 ( struct V_30 * V_18 )
{
V_18 -> V_171 = & V_172 ;
V_18 -> V_173 = true ;
V_18 -> V_174 = F_15 ;
V_18 -> type = V_175 ;
V_18 -> V_176 = V_177 + sizeof( struct V_46 ) ;
V_18 -> V_92 = V_178 ;
V_18 -> V_179 = V_102 ;
V_18 -> V_180 = V_181 ;
V_18 -> V_19 |= V_182 ;
V_18 -> V_183 = sizeof( struct V_1 ) ;
F_99 ( V_18 ) ;
V_18 -> V_184 = V_185 ;
F_100 ( V_18 -> V_186 ) ;
}
static inline int F_101 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_7 = F_19 ( V_18 ) ;
V_18 -> V_31 = F_102 ( struct V_58 ) ;
if ( ! V_18 -> V_31 )
return - V_187 ;
return 0 ;
}
static int F_103 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
int V_32 = F_101 ( V_18 ) ;
if ( V_32 )
return V_32 ;
F_85 ( V_10 ) ;
return 0 ;
}
static int T_8 F_104 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_18 ( V_18 ) ;
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
V_10 -> V_15 . V_50 = V_51 ;
F_21 ( V_18 ) ;
F_12 ( V_12 -> V_21 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_105 ( struct V_188 * V_189 [] , struct V_188 * V_133 [] ,
struct V_190 * V_191 )
{
return 0 ;
}
static void F_106 ( struct V_188 * V_133 [] ,
struct V_22 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( ! V_133 )
return;
if ( V_133 [ V_192 ] )
V_15 -> V_147 = F_107 ( V_133 [ V_192 ] ) ;
if ( V_133 [ V_193 ] )
V_15 -> V_16 = F_108 ( V_133 [ V_193 ] ) ;
if ( V_133 [ V_194 ] )
V_15 -> V_17 = F_108 ( V_133 [ V_194 ] ) ;
if ( V_133 [ V_195 ] )
V_15 -> V_74 = F_109 ( V_133 [ V_195 ] ) ;
if ( V_133 [ V_196 ] )
V_15 -> V_117 = F_109 ( V_133 [ V_196 ] ) ;
if ( V_133 [ V_197 ] )
V_15 -> V_148 = F_107 ( V_133 [ V_197 ] ) ;
}
static int F_110 ( struct V_7 * V_198 , struct V_30 * V_18 ,
struct V_188 * V_189 [] , struct V_188 * V_133 [] ,
struct V_190 * V_191 )
{
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_6 * V_199 ;
V_199 = F_18 ( V_18 ) ;
F_106 ( V_133 , & V_199 -> V_15 ) ;
V_199 -> V_15 . V_50 = V_51 ;
if ( F_27 ( V_7 , & V_199 -> V_15 , 0 ) )
return - V_167 ;
return F_17 ( V_18 ) ;
}
static void F_111 ( struct V_30 * V_18 , struct V_200 * V_201 )
{
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 != V_12 -> V_43 )
F_112 ( V_18 , V_201 ) ;
}
static int F_113 ( struct V_30 * V_18 , struct V_188 * V_189 [] ,
struct V_188 * V_133 [] ,
struct V_190 * V_191 )
{
struct V_6 * V_10 ;
struct V_22 V_23 ;
struct V_7 * V_7 = F_19 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 == V_12 -> V_43 )
return - V_56 ;
F_106 ( V_133 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_23 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_18 != V_18 )
return - V_167 ;
} else
V_10 = F_18 ( V_18 ) ;
return F_89 ( V_10 , & V_23 ) ;
}
static T_9 F_114 ( const struct V_30 * V_18 )
{
return
F_115 ( 4 ) +
F_115 ( sizeof( struct V_1 ) ) +
F_115 ( sizeof( struct V_1 ) ) +
F_115 ( 4 ) +
F_115 ( 4 ) +
F_115 ( 4 ) +
0 ;
}
static int F_116 ( struct V_44 * V_45 , const struct V_30 * V_18 )
{
struct V_6 * V_63 = F_18 ( V_18 ) ;
struct V_22 * V_202 = & V_63 -> V_15 ;
if ( F_117 ( V_45 , V_192 , V_202 -> V_147 ) ||
F_118 ( V_45 , V_193 , & V_202 -> V_16 ) ||
F_118 ( V_45 , V_194 , & V_202 -> V_17 ) ||
F_119 ( V_45 , V_195 , V_202 -> V_74 ) ||
F_119 ( V_45 , V_196 , V_202 -> V_117 ) ||
F_117 ( V_45 , V_197 , V_202 -> V_148 ) )
goto V_203;
return 0 ;
V_203:
return - V_106 ;
}
static void T_10 F_120 ( struct V_11 * V_12 )
{
int V_24 ;
struct V_6 * V_10 ;
F_121 ( V_204 ) ;
for ( V_24 = 0 ; V_24 < V_205 ; V_24 ++ ) {
V_10 = F_13 ( V_12 -> V_206 [ V_24 ] ) ;
while ( V_10 ) {
F_112 ( V_10 -> V_18 , & V_204 ) ;
V_10 = F_13 ( V_10 -> V_28 ) ;
}
}
V_10 = F_13 ( V_12 -> V_21 [ 0 ] ) ;
F_112 ( V_10 -> V_18 , & V_204 ) ;
F_122 ( & V_204 ) ;
}
static int T_8 F_123 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_32 ;
V_12 -> V_26 [ 0 ] = V_12 -> V_21 ;
V_12 -> V_26 [ 1 ] = V_12 -> V_206 ;
V_32 = - V_187 ;
V_12 -> V_43 = F_24 ( sizeof( struct V_6 ) , L_3 ,
V_38 , V_39 ) ;
if ( ! V_12 -> V_43 )
goto V_207;
F_25 ( V_12 -> V_43 , V_7 ) ;
V_12 -> V_43 -> V_33 = & V_34 ;
V_32 = F_104 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_208;
V_32 = F_124 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_208;
V_10 = F_18 ( V_12 -> V_43 ) ;
strcpy ( V_10 -> V_15 . V_36 , V_12 -> V_43 -> V_36 ) ;
return 0 ;
V_208:
F_26 ( V_12 -> V_43 ) ;
V_207:
return V_32 ;
}
static void T_10 F_125 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_126 () ;
F_120 ( V_12 ) ;
F_127 () ;
}
static bool F_128 ( const struct V_30 * V_18 )
{
return V_18 -> V_171 == & V_172 ;
}
static int F_129 ( struct V_209 * V_210 ,
unsigned long V_211 , void * V_212 )
{
struct V_30 * V_18 = F_130 ( V_212 ) ;
struct V_6 * V_10 = F_18 ( V_18 ) ;
if ( ! F_128 ( V_18 ) )
return V_213 ;
switch ( V_211 ) {
case V_214 :
if ( ! F_48 ( V_10 -> V_7 , F_19 ( V_18 ) ) )
F_131 ( V_10 -> V_7 ) ;
break;
}
return V_213 ;
}
static int T_11 F_132 ( void )
{
const char * V_215 ;
int V_32 ;
F_133 ( & V_216 ) ;
V_215 = L_4 ;
V_32 = F_134 ( & V_217 ) ;
if ( V_32 < 0 )
goto V_218;
V_215 = L_5 ;
V_32 = F_135 ( & V_219 , V_135 ) ;
if ( V_32 < 0 )
goto V_220;
V_32 = F_135 ( & V_221 , V_136 ) ;
if ( V_32 < 0 )
goto V_222;
V_32 = F_135 ( & V_223 , V_137 ) ;
if ( V_32 < 0 )
goto V_224;
V_215 = L_6 ;
V_32 = F_136 ( & V_34 ) ;
if ( V_32 < 0 )
goto V_225;
return 0 ;
V_225:
F_137 ( & V_223 , V_137 ) ;
V_224:
F_137 ( & V_221 , V_136 ) ;
V_222:
F_137 ( & V_219 , V_135 ) ;
V_220:
F_138 ( & V_217 ) ;
V_218:
F_139 ( & V_216 ) ;
F_140 ( L_7 , V_215 ) ;
return V_32 ;
}
static void T_12 F_141 ( void )
{
F_142 ( & V_34 ) ;
F_137 ( & V_223 , V_137 ) ;
F_137 ( & V_221 , V_136 ) ;
F_137 ( & V_219 , V_135 ) ;
F_138 ( & V_217 ) ;
F_139 ( & V_216 ) ;
}
