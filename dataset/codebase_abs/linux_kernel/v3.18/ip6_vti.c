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
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) &&
( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
}
V_10 = F_8 ( V_12 -> V_20 [ 0 ] ) ;
if ( V_10 && ( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
return NULL ;
}
static struct V_6 T_2 * *
F_9 ( struct V_11 * V_12 , const struct V_21 * V_22 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
unsigned int V_23 = 0 ;
int V_24 = 0 ;
if ( ! F_10 ( V_8 ) || ! F_10 ( V_9 ) ) {
V_24 = 1 ;
V_23 = F_1 ( V_8 , V_9 ) ;
}
return & V_12 -> V_25 [ V_24 ] [ V_23 ] ;
}
static void
F_11 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
F_12 ( V_10 -> V_27 , F_13 ( * V_26 ) ) ;
F_12 ( * V_26 , V_10 ) ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 ;
struct V_6 * V_28 ;
for ( V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
( V_28 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_28 -> V_27 ) {
if ( V_10 == V_28 ) {
F_12 ( * V_26 , V_10 -> V_27 ) ;
break;
}
}
}
static void F_15 ( struct V_29 * V_17 )
{
F_16 ( V_17 -> V_30 ) ;
F_17 ( V_17 ) ;
}
static int F_18 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
V_31 = F_21 ( V_17 ) ;
if ( V_31 < 0 )
goto V_32;
strcpy ( V_10 -> V_14 . V_33 , V_17 -> V_33 ) ;
V_17 -> V_34 = & V_35 ;
F_22 ( V_17 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_32:
return V_31 ;
}
static struct V_6 * F_23 ( struct V_7 * V_7 , struct V_21 * V_22 )
{
struct V_29 * V_17 ;
struct V_6 * V_10 ;
char V_33 [ V_36 ] ;
int V_31 ;
if ( V_22 -> V_33 [ 0 ] )
F_24 ( V_33 , V_22 -> V_33 , V_36 ) ;
else
sprintf ( V_33 , L_1 ) ;
V_17 = F_25 ( sizeof( * V_10 ) , V_33 , V_37 , V_38 ) ;
if ( V_17 == NULL )
goto V_39;
F_26 ( V_17 , V_7 ) ;
V_10 = F_19 ( V_17 ) ;
V_10 -> V_14 = * V_22 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_31 = F_18 ( V_17 ) ;
if ( V_31 < 0 )
goto V_40;
return V_10 ;
V_40:
F_15 ( V_17 ) ;
V_39:
return NULL ;
}
static struct V_6 * F_27 ( struct V_7 * V_7 , struct V_21 * V_22 ,
int V_41 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
struct V_6 T_2 * * V_26 ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
for ( V_26 = F_9 ( V_12 , V_22 ) ;
( V_10 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_10 -> V_27 ) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) ) {
if ( V_41 )
return NULL ;
return V_10 ;
}
}
if ( ! V_41 )
return NULL ;
return F_23 ( V_7 , V_22 ) ;
}
static void F_28 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_42 )
F_29 ( V_12 -> V_20 [ 0 ] , NULL ) ;
else
F_14 ( V_12 , V_10 ) ;
F_30 ( V_17 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_6 * V_10 ;
const struct V_45 * V_46 = F_32 ( V_44 ) ;
F_33 () ;
if ( ( V_10 = F_4 ( F_20 ( V_44 -> V_17 ) , & V_46 -> V_47 ,
& V_46 -> V_48 ) ) != NULL ) {
if ( V_10 -> V_14 . V_49 != V_50 && V_10 -> V_14 . V_49 != 0 ) {
F_34 () ;
goto V_51;
}
if ( ! F_35 ( NULL , V_52 , V_44 ) ) {
F_34 () ;
return 0 ;
}
if ( ! F_36 ( V_10 , & V_46 -> V_48 , & V_46 -> V_47 ) ) {
V_10 -> V_17 -> V_53 . V_54 ++ ;
F_34 () ;
goto V_51;
}
F_37 ( V_44 ) -> V_55 . V_56 = V_10 ;
V_44 -> V_57 = F_38 ( V_10 -> V_14 . V_58 ) ;
F_34 () ;
return F_39 ( V_44 ) ;
}
F_34 () ;
return - V_59 ;
V_51:
F_40 ( V_44 ) ;
return 0 ;
}
static int F_41 ( struct V_43 * V_44 , int V_31 )
{
unsigned short V_60 ;
struct V_29 * V_17 ;
struct V_61 * V_30 ;
struct V_62 * V_63 ;
struct V_6 * V_10 = F_37 ( V_44 ) -> V_55 . V_56 ;
if ( ! V_10 )
return 1 ;
V_17 = V_10 -> V_17 ;
if ( V_31 ) {
V_17 -> V_53 . V_64 ++ ;
V_17 -> V_53 . V_54 ++ ;
return 0 ;
}
V_63 = F_42 ( V_44 ) ;
V_60 = V_63 -> V_65 -> V_66 -> V_60 ;
if ( ! F_43 ( NULL , V_52 , V_44 , V_60 ) )
return - V_67 ;
F_44 ( V_44 , ! F_45 ( V_10 -> V_7 , F_20 ( V_44 -> V_17 ) ) ) ;
V_44 -> V_17 = V_17 ;
V_30 = F_46 ( V_17 -> V_30 ) ;
F_47 ( & V_30 -> V_68 ) ;
V_30 -> V_69 ++ ;
V_30 -> V_70 += V_44 -> V_71 ;
F_48 ( & V_30 -> V_68 ) ;
return 0 ;
}
static inline bool
F_49 ( const struct V_6 * V_10 , const struct V_45 * V_72 )
{
return F_7 ( & V_10 -> V_14 . V_16 , & V_72 -> V_47 ) ;
}
static bool F_50 ( const struct V_62 * V_63 ,
const struct V_1 * V_73 ,
const struct V_1 * V_74 )
{
T_3 * V_48 = ( T_3 * ) V_73 ;
T_3 * V_47 = ( T_3 * ) V_74 ;
if ( ! V_63 || V_63 -> V_75 . V_76 != V_77 ||
V_63 -> V_75 . V_60 != V_78 )
return false ;
if ( F_10 ( V_73 ) )
return F_51 ( V_47 , & V_63 -> V_75 . V_47 , V_78 ) ;
if ( ! F_52 ( V_63 , V_48 , V_47 , V_78 ) )
return false ;
return true ;
}
static int
F_53 ( struct V_43 * V_44 , struct V_29 * V_17 , struct V_79 * V_80 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_81 * V_53 = & V_10 -> V_17 -> V_53 ;
struct V_82 * V_73 = F_54 ( V_44 ) ;
struct V_29 * V_83 ;
int V_31 = - 1 ;
if ( ! V_73 )
goto V_84;
F_55 ( V_73 ) ;
V_73 = F_56 ( V_10 -> V_7 , V_73 , V_80 , NULL , 0 ) ;
if ( F_57 ( V_73 ) ) {
V_31 = F_58 ( V_73 ) ;
V_73 = NULL ;
goto V_84;
}
if ( ! F_50 ( V_73 -> V_85 , & V_10 -> V_14 . V_16 , & V_10 -> V_14 . V_15 ) )
goto V_84;
V_83 = V_73 -> V_17 ;
if ( V_83 == V_17 ) {
V_53 -> V_86 ++ ;
F_59 ( L_2 ,
V_10 -> V_14 . V_33 ) ;
goto V_87;
}
F_44 ( V_44 , ! F_45 ( V_10 -> V_7 , F_20 ( V_17 ) ) ) ;
F_60 ( V_44 , V_73 ) ;
V_44 -> V_17 = F_54 ( V_44 ) -> V_17 ;
V_31 = F_61 ( V_44 ) ;
if ( F_62 ( V_31 ) == 0 ) {
struct V_61 * V_30 = F_46 ( V_17 -> V_30 ) ;
F_47 ( & V_30 -> V_68 ) ;
V_30 -> V_88 += V_44 -> V_71 ;
V_30 -> V_89 ++ ;
F_48 ( & V_30 -> V_68 ) ;
} else {
V_53 -> V_90 ++ ;
V_53 -> V_91 ++ ;
}
return 0 ;
V_84:
V_53 -> V_92 ++ ;
F_63 ( V_44 ) ;
V_87:
F_64 ( V_73 ) ;
return V_31 ;
}
static T_4
F_65 ( struct V_43 * V_44 , struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_81 * V_53 = & V_10 -> V_17 -> V_53 ;
struct V_45 * V_46 ;
struct V_79 V_80 ;
int V_93 ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_44 -> V_57 = F_38 ( V_10 -> V_14 . V_94 ) ;
switch ( V_44 -> V_95 ) {
case F_66 ( V_96 ) :
V_46 = F_32 ( V_44 ) ;
if ( ( V_10 -> V_14 . V_49 != V_50 && V_10 -> V_14 . V_49 != 0 ) ||
! F_67 ( V_10 ) || F_49 ( V_10 , V_46 ) )
goto V_97;
F_68 ( V_44 , & V_80 , V_78 ) ;
memset ( F_69 ( V_44 ) , 0 , sizeof( * F_69 ( V_44 ) ) ) ;
break;
case F_66 ( V_98 ) :
F_68 ( V_44 , & V_80 , V_99 ) ;
memset ( F_70 ( V_44 ) , 0 , sizeof( * F_70 ( V_44 ) ) ) ;
break;
default:
goto V_97;
}
V_93 = F_53 ( V_44 , V_17 , & V_80 ) ;
if ( V_93 < 0 )
goto V_97;
return V_100 ;
V_97:
V_53 -> V_90 ++ ;
V_53 -> V_101 ++ ;
F_40 ( V_44 ) ;
return V_100 ;
}
static int F_71 ( struct V_43 * V_44 , struct V_102 * V_103 ,
T_5 type , T_5 V_104 , int V_105 , T_6 V_106 )
{
T_6 V_107 ;
T_7 V_57 ;
struct V_62 * V_63 ;
struct V_6 * V_10 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_7 * V_7 = F_20 ( V_44 -> V_17 ) ;
const struct V_45 * V_114 = ( const struct V_45 * ) V_44 -> V_115 ;
int V_95 = V_114 -> V_116 ;
V_10 = F_4 ( F_20 ( V_44 -> V_17 ) , & V_114 -> V_48 , & V_114 -> V_47 ) ;
if ( ! V_10 )
return - 1 ;
V_57 = F_38 ( V_10 -> V_14 . V_94 ) ;
switch ( V_95 ) {
case V_117 :
V_109 = (struct V_108 * ) ( V_44 -> V_115 + V_105 ) ;
V_107 = V_109 -> V_107 ;
break;
case V_118 :
V_111 = (struct V_110 * ) ( V_44 -> V_115 + V_105 ) ;
V_107 = V_111 -> V_107 ;
break;
case V_119 :
V_113 = (struct V_112 * ) ( V_44 -> V_115 + V_105 ) ;
V_107 = F_72 ( F_73 ( V_113 -> V_120 ) ) ;
break;
default:
return 0 ;
}
if ( type != V_121 &&
type != V_122 )
return 0 ;
V_63 = F_74 ( V_7 , V_57 , ( const T_3 * ) & V_114 -> V_48 ,
V_107 , V_95 , V_78 ) ;
if ( ! V_63 )
return 0 ;
if ( type == V_122 )
F_75 ( V_44 , V_7 , V_44 -> V_17 -> V_123 , 0 ) ;
else
F_76 ( V_44 , V_7 , V_106 , 0 , 0 ) ;
F_77 ( V_63 ) ;
return 0 ;
}
static void F_78 ( struct V_6 * V_10 )
{
struct V_29 * V_17 = V_10 -> V_17 ;
struct V_21 * V_22 = & V_10 -> V_14 ;
memcpy ( V_17 -> V_124 , & V_22 -> V_15 , sizeof( struct V_1 ) ) ;
memcpy ( V_17 -> V_125 , & V_22 -> V_16 , sizeof( struct V_1 ) ) ;
V_22 -> V_18 &= ~ ( V_126 | V_127 |
V_128 ) ;
V_22 -> V_18 |= F_79 ( V_10 , & V_22 -> V_15 , & V_22 -> V_16 ) ;
if ( V_22 -> V_18 & V_126 && V_22 -> V_18 & V_127 )
V_17 -> V_18 |= V_129 ;
else
V_17 -> V_18 &= ~ V_129 ;
V_17 -> V_130 = V_22 -> V_131 ;
}
static int
F_80 ( struct V_6 * V_10 , const struct V_21 * V_22 )
{
V_10 -> V_14 . V_15 = V_22 -> V_15 ;
V_10 -> V_14 . V_16 = V_22 -> V_16 ;
V_10 -> V_14 . V_131 = V_22 -> V_131 ;
V_10 -> V_14 . V_58 = V_22 -> V_58 ;
V_10 -> V_14 . V_94 = V_22 -> V_94 ;
V_10 -> V_14 . V_49 = V_22 -> V_49 ;
F_81 ( V_10 ) ;
F_78 ( V_10 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_10 , struct V_21 * V_22 )
{
struct V_7 * V_7 = F_20 ( V_10 -> V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
F_14 ( V_12 , V_10 ) ;
F_83 () ;
V_31 = F_80 ( V_10 , V_22 ) ;
F_11 ( V_12 , V_10 ) ;
F_84 ( V_10 -> V_17 ) ;
return V_31 ;
}
static void
F_85 ( struct V_21 * V_22 , const struct V_132 * V_133 )
{
V_22 -> V_15 = V_133 -> V_15 ;
V_22 -> V_16 = V_133 -> V_16 ;
V_22 -> V_131 = V_133 -> V_131 ;
V_22 -> V_58 = V_133 -> V_58 ;
V_22 -> V_94 = V_133 -> V_94 ;
V_22 -> V_49 = V_133 -> V_49 ;
memcpy ( V_22 -> V_33 , V_133 -> V_33 , sizeof( V_133 -> V_33 ) ) ;
}
static void
F_86 ( struct V_132 * V_133 , const struct V_21 * V_22 )
{
V_133 -> V_15 = V_22 -> V_15 ;
V_133 -> V_16 = V_22 -> V_16 ;
V_133 -> V_131 = V_22 -> V_131 ;
V_133 -> V_58 = V_22 -> V_58 ;
V_133 -> V_94 = V_22 -> V_94 ;
V_133 -> V_49 = V_22 -> V_49 ;
memcpy ( V_133 -> V_33 , V_22 -> V_33 , sizeof( V_133 -> V_33 ) ) ;
}
static int
F_87 ( struct V_29 * V_17 , struct V_134 * V_135 , int V_136 )
{
int V_31 = 0 ;
struct V_132 V_22 ;
struct V_21 V_137 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_136 ) {
case V_138 :
if ( V_17 == V_12 -> V_42 ) {
if ( F_88 ( & V_22 , V_135 -> V_139 . V_140 , sizeof( V_22 ) ) ) {
V_31 = - V_141 ;
break;
}
F_85 ( & V_137 , & V_22 ) ;
V_10 = F_27 ( V_7 , & V_137 , 0 ) ;
} else {
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
}
if ( V_10 == NULL )
V_10 = F_19 ( V_17 ) ;
F_86 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_89 ( V_135 -> V_139 . V_140 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_141 ;
break;
case V_142 :
case V_143 :
V_31 = - V_67 ;
if ( ! F_90 ( V_7 -> V_144 , V_145 ) )
break;
V_31 = - V_141 ;
if ( F_88 ( & V_22 , V_135 -> V_139 . V_140 , sizeof( V_22 ) ) )
break;
V_31 = - V_59 ;
if ( V_22 . V_49 != V_50 && V_22 . V_49 != 0 )
break;
F_85 ( & V_137 , & V_22 ) ;
V_10 = F_27 ( V_7 , & V_137 , V_136 == V_142 ) ;
if ( V_17 != V_12 -> V_42 && V_136 == V_143 ) {
if ( V_10 != NULL ) {
if ( V_10 -> V_17 != V_17 ) {
V_31 = - V_146 ;
break;
}
} else
V_10 = F_19 ( V_17 ) ;
V_31 = F_82 ( V_10 , & V_137 ) ;
}
if ( V_10 ) {
V_31 = 0 ;
F_86 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_89 ( V_135 -> V_139 . V_140 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_141 ;
} else
V_31 = ( V_136 == V_142 ? - V_147 : - V_148 ) ;
break;
case V_149 :
V_31 = - V_67 ;
if ( ! F_90 ( V_7 -> V_144 , V_145 ) )
break;
if ( V_17 == V_12 -> V_42 ) {
V_31 = - V_141 ;
if ( F_88 ( & V_22 , V_135 -> V_139 . V_140 , sizeof( V_22 ) ) )
break;
V_31 = - V_148 ;
F_85 ( & V_137 , & V_22 ) ;
V_10 = F_27 ( V_7 , & V_137 , 0 ) ;
if ( V_10 == NULL )
break;
V_31 = - V_67 ;
if ( V_10 -> V_17 == V_12 -> V_42 )
break;
V_17 = V_10 -> V_17 ;
}
V_31 = 0 ;
F_91 ( V_17 ) ;
break;
default:
V_31 = - V_59 ;
}
return V_31 ;
}
static int F_92 ( struct V_29 * V_17 , int V_150 )
{
if ( V_150 < V_151 )
return - V_59 ;
V_17 -> V_152 = V_150 ;
return 0 ;
}
static void V_38 ( struct V_29 * V_17 )
{
V_17 -> V_153 = & V_154 ;
V_17 -> V_155 = F_15 ;
V_17 -> type = V_156 ;
V_17 -> V_157 = V_158 + sizeof( struct V_45 ) ;
V_17 -> V_152 = V_159 ;
V_17 -> V_18 |= V_160 ;
V_17 -> V_161 = sizeof( struct V_1 ) ;
F_93 ( V_17 ) ;
}
static inline int F_94 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
V_10 -> V_17 = V_17 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_17 -> V_30 = F_95 ( struct V_61 ) ;
if ( ! V_17 -> V_30 )
return - V_162 ;
return 0 ;
}
static int F_96 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
int V_31 = F_94 ( V_17 ) ;
if ( V_31 )
return V_31 ;
F_78 ( V_10 ) ;
return 0 ;
}
static int T_8 F_97 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
V_10 -> V_14 . V_49 = V_50 ;
F_22 ( V_17 ) ;
F_12 ( V_12 -> V_20 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_98 ( struct V_163 * V_164 [] , struct V_163 * V_115 [] )
{
return 0 ;
}
static void F_99 ( struct V_163 * V_115 [] ,
struct V_21 * V_14 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( ! V_115 )
return;
if ( V_115 [ V_165 ] )
V_14 -> V_131 = F_100 ( V_115 [ V_165 ] ) ;
if ( V_115 [ V_166 ] )
F_101 ( & V_14 -> V_15 , V_115 [ V_166 ] ,
sizeof( struct V_1 ) ) ;
if ( V_115 [ V_167 ] )
F_101 ( & V_14 -> V_16 , V_115 [ V_167 ] ,
sizeof( struct V_1 ) ) ;
if ( V_115 [ V_168 ] )
V_14 -> V_58 = F_102 ( V_115 [ V_168 ] ) ;
if ( V_115 [ V_169 ] )
V_14 -> V_94 = F_102 ( V_115 [ V_169 ] ) ;
}
static int F_103 ( struct V_7 * V_170 , struct V_29 * V_17 ,
struct V_163 * V_164 [] , struct V_163 * V_115 [] )
{
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_6 * V_171 ;
V_171 = F_19 ( V_17 ) ;
F_99 ( V_115 , & V_171 -> V_14 ) ;
V_171 -> V_14 . V_49 = V_50 ;
if ( F_27 ( V_7 , & V_171 -> V_14 , 0 ) )
return - V_146 ;
return F_18 ( V_17 ) ;
}
static void F_104 ( struct V_29 * V_17 , struct V_172 * V_173 )
{
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 != V_12 -> V_42 )
F_105 ( V_17 , V_173 ) ;
}
static int F_106 ( struct V_29 * V_17 , struct V_163 * V_164 [] ,
struct V_163 * V_115 [] )
{
struct V_6 * V_10 ;
struct V_21 V_22 ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_42 )
return - V_59 ;
F_99 ( V_115 , & V_22 ) ;
V_10 = F_27 ( V_7 , & V_22 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_17 != V_17 )
return - V_146 ;
} else
V_10 = F_19 ( V_17 ) ;
return F_82 ( V_10 , & V_22 ) ;
}
static T_9 F_107 ( const struct V_29 * V_17 )
{
return
F_108 ( 4 ) +
F_108 ( sizeof( struct V_1 ) ) +
F_108 ( sizeof( struct V_1 ) ) +
F_108 ( 4 ) +
F_108 ( 4 ) +
0 ;
}
static int F_109 ( struct V_43 * V_44 , const struct V_29 * V_17 )
{
struct V_6 * V_55 = F_19 ( V_17 ) ;
struct V_21 * V_174 = & V_55 -> V_14 ;
if ( F_110 ( V_44 , V_165 , V_174 -> V_131 ) ||
F_111 ( V_44 , V_166 , sizeof( struct V_1 ) ,
& V_174 -> V_15 ) ||
F_111 ( V_44 , V_167 , sizeof( struct V_1 ) ,
& V_174 -> V_16 ) ||
F_112 ( V_44 , V_168 , V_174 -> V_58 ) ||
F_112 ( V_44 , V_169 , V_174 -> V_94 ) )
goto V_175;
return 0 ;
V_175:
return - V_176 ;
}
static void T_10 F_113 ( struct V_11 * V_12 )
{
int V_23 ;
struct V_6 * V_10 ;
F_114 ( V_177 ) ;
for ( V_23 = 0 ; V_23 < V_178 ; V_23 ++ ) {
V_10 = F_13 ( V_12 -> V_179 [ V_23 ] ) ;
while ( V_10 != NULL ) {
F_105 ( V_10 -> V_17 , & V_177 ) ;
V_10 = F_13 ( V_10 -> V_27 ) ;
}
}
V_10 = F_13 ( V_12 -> V_20 [ 0 ] ) ;
F_105 ( V_10 -> V_17 , & V_177 ) ;
F_115 ( & V_177 ) ;
}
static int T_8 F_116 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_31 ;
V_12 -> V_25 [ 0 ] = V_12 -> V_20 ;
V_12 -> V_25 [ 1 ] = V_12 -> V_179 ;
V_31 = - V_162 ;
V_12 -> V_42 = F_25 ( sizeof( struct V_6 ) , L_3 ,
V_37 , V_38 ) ;
if ( ! V_12 -> V_42 )
goto V_180;
F_26 ( V_12 -> V_42 , V_7 ) ;
V_12 -> V_42 -> V_34 = & V_35 ;
V_31 = F_97 ( V_12 -> V_42 ) ;
if ( V_31 < 0 )
goto V_181;
V_31 = F_117 ( V_12 -> V_42 ) ;
if ( V_31 < 0 )
goto V_181;
V_10 = F_19 ( V_12 -> V_42 ) ;
strcpy ( V_10 -> V_14 . V_33 , V_12 -> V_42 -> V_33 ) ;
return 0 ;
V_181:
F_15 ( V_12 -> V_42 ) ;
V_180:
return V_31 ;
}
static void T_10 F_118 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_119 () ;
F_113 ( V_12 ) ;
F_120 () ;
}
static int T_11 F_121 ( void )
{
const char * V_182 ;
int V_31 ;
V_182 = L_4 ;
V_31 = F_122 ( & V_183 ) ;
if ( V_31 < 0 )
goto V_184;
V_182 = L_5 ;
V_31 = F_123 ( & V_185 , V_117 ) ;
if ( V_31 < 0 )
goto V_186;
V_31 = F_123 ( & V_187 , V_118 ) ;
if ( V_31 < 0 )
goto V_188;
V_31 = F_123 ( & V_189 , V_119 ) ;
if ( V_31 < 0 )
goto V_190;
V_182 = L_6 ;
V_31 = F_124 ( & V_35 ) ;
if ( V_31 < 0 )
goto V_191;
return 0 ;
V_191:
F_125 ( & V_189 , V_119 ) ;
V_190:
F_125 ( & V_187 , V_118 ) ;
V_188:
F_125 ( & V_185 , V_117 ) ;
V_186:
F_126 ( & V_183 ) ;
V_184:
F_127 ( L_7 , V_182 ) ;
return V_31 ;
}
static void T_12 F_128 ( void )
{
F_129 ( & V_35 ) ;
F_125 ( & V_189 , V_119 ) ;
F_125 ( & V_187 , V_118 ) ;
F_125 ( & V_185 , V_117 ) ;
F_126 ( & V_183 ) ;
}
