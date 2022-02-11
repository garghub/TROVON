static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_5 ;
F_2 (i) {
const struct V_6 * V_7 = F_3 ( V_3 -> V_7 , V_5 ) ;
T_1 V_8 , V_9 , V_10 , V_11 ;
unsigned int V_12 ;
do {
V_12 = F_4 ( & V_7 -> V_13 ) ;
V_8 = V_7 -> V_8 ;
V_10 = V_7 -> V_10 ;
V_9 = V_7 -> V_9 ;
V_11 = V_7 -> V_11 ;
} while ( F_5 ( & V_7 -> V_13 , V_12 ) );
V_4 -> V_8 += V_8 ;
V_4 -> V_10 += V_10 ;
V_4 -> V_9 += V_9 ;
V_4 -> V_11 += V_11 ;
}
V_4 -> V_14 = V_3 -> V_15 . V_14 ;
V_4 -> V_16 = V_3 -> V_15 . V_16 ;
V_4 -> V_17 = V_3 -> V_15 . V_17 ;
V_4 -> V_18 = V_3 -> V_15 . V_18 ;
V_4 -> V_19 = V_3 -> V_15 . V_19 ;
V_4 -> V_20 = V_3 -> V_15 . V_20 ;
return V_4 ;
}
static struct V_21 * F_6 ( struct V_22 * V_22 ,
T_2 V_23 , T_2 V_24 )
{
unsigned int V_25 = F_7 ( V_23 ) ;
unsigned int V_26 = F_7 ( V_24 ) ;
struct V_21 * V_27 ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_9 (t, ipn->tunnels_r_l[h0 ^ h1])
if ( V_24 == V_27 -> V_31 . V_32 . V_33 &&
V_23 == V_27 -> V_31 . V_32 . V_34 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
F_9 (t, ipn->tunnels_r[h0])
if ( V_23 == V_27 -> V_31 . V_32 . V_34 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
F_9 (t, ipn->tunnels_l[h1])
if ( V_24 == V_27 -> V_31 . V_32 . V_33 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
V_27 = F_10 ( V_29 -> V_37 [ 0 ] ) ;
if ( V_27 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
return NULL ;
}
static struct V_21 T_3 * * F_11 ( struct V_28 * V_29 ,
struct V_38 * V_31 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
if ( V_23 ) {
V_40 |= 2 ;
V_39 ^= F_7 ( V_23 ) ;
}
if ( V_24 ) {
V_40 |= 1 ;
V_39 ^= F_7 ( V_24 ) ;
}
return & V_29 -> V_41 [ V_40 ] [ V_39 ] ;
}
static inline struct V_21 T_3 * * F_12 ( struct V_28 * V_29 ,
struct V_21 * V_27 )
{
return F_11 ( V_29 , & V_27 -> V_31 ) ;
}
static void F_13 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_42 ;
struct V_21 * V_43 ;
for ( V_42 = F_12 ( V_29 , V_27 ) ;
( V_43 = F_14 ( * V_42 ) ) != NULL ;
V_42 = & V_43 -> V_44 ) {
if ( V_27 == V_43 ) {
F_15 ( * V_42 , V_27 -> V_44 ) ;
break;
}
}
}
static void F_16 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_42 = F_12 ( V_29 , V_27 ) ;
F_15 ( V_27 -> V_44 , F_14 ( * V_42 ) ) ;
F_15 ( * V_42 , V_27 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_21 * V_27 = F_18 ( V_3 ) ;
struct V_22 * V_22 = F_19 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
int V_45 ;
V_45 = F_20 ( V_3 ) ;
if ( V_45 < 0 )
goto V_46;
V_45 = F_21 ( V_3 ) ;
if ( V_45 < 0 )
goto V_46;
strcpy ( V_27 -> V_31 . V_47 , V_3 -> V_47 ) ;
V_3 -> V_48 = & V_49 ;
F_22 ( V_3 ) ;
F_16 ( V_29 , V_27 ) ;
return 0 ;
V_46:
return V_45 ;
}
static struct V_21 * F_23 ( struct V_22 * V_22 ,
struct V_38 * V_31 , int V_50 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
struct V_21 * V_27 , * V_51 ;
struct V_21 T_3 * * V_42 ;
struct V_2 * V_3 ;
char V_47 [ V_52 ] ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
for ( V_42 = F_11 ( V_29 , V_31 ) ;
( V_27 = F_14 ( * V_42 ) ) != NULL ;
V_42 = & V_27 -> V_44 ) {
if ( V_24 == V_27 -> V_31 . V_32 . V_33 && V_23 == V_27 -> V_31 . V_32 . V_34 )
return V_27 ;
}
if ( ! V_50 )
return NULL ;
if ( V_31 -> V_47 [ 0 ] )
F_24 ( V_47 , V_31 -> V_47 , V_52 ) ;
else
strcpy ( V_47 , L_1 ) ;
V_3 = F_25 ( sizeof( * V_27 ) , V_47 , V_53 ) ;
if ( V_3 == NULL )
return NULL ;
F_26 ( V_3 , V_22 ) ;
V_51 = F_18 ( V_3 ) ;
V_51 -> V_31 = * V_31 ;
if ( F_17 ( V_3 ) < 0 )
goto V_54;
return V_51 ;
V_54:
F_27 ( V_3 ) ;
return NULL ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_22 * V_22 = F_19 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
if ( V_3 == V_29 -> V_55 )
F_29 ( V_29 -> V_37 [ 0 ] , NULL ) ;
else
F_13 ( V_29 , F_18 ( V_3 ) ) ;
F_30 ( V_3 ) ;
}
static int F_31 ( struct V_56 * V_57 , T_4 V_58 )
{
const struct V_59 * V_32 = ( const struct V_59 * ) V_57 -> V_60 ;
const int type = F_32 ( V_57 ) -> type ;
const int V_61 = F_32 ( V_57 ) -> V_61 ;
struct V_21 * V_27 ;
int V_45 ;
switch ( type ) {
default:
case V_62 :
return 0 ;
case V_63 :
switch ( V_61 ) {
case V_64 :
case V_65 :
return 0 ;
default:
break;
}
break;
case V_66 :
if ( V_61 != V_67 )
return 0 ;
break;
case V_68 :
break;
}
V_45 = - V_69 ;
V_27 = F_6 ( F_19 ( V_57 -> V_3 ) , V_32 -> V_34 , V_32 -> V_33 ) ;
if ( V_27 == NULL )
goto V_46;
if ( type == V_63 && V_61 == V_70 ) {
F_33 ( V_57 , F_19 ( V_57 -> V_3 ) , V_58 ,
V_27 -> V_3 -> V_71 , 0 , V_72 , 0 ) ;
V_45 = 0 ;
goto V_46;
}
if ( type == V_68 ) {
F_34 ( V_57 , F_19 ( V_57 -> V_3 ) , V_27 -> V_3 -> V_71 , 0 ,
V_72 , 0 ) ;
V_45 = 0 ;
goto V_46;
}
if ( V_27 -> V_31 . V_32 . V_34 == 0 )
goto V_46;
V_45 = 0 ;
if ( V_27 -> V_31 . V_32 . V_73 == 0 && type == V_66 )
goto V_46;
if ( F_35 ( V_74 , V_27 -> V_75 + V_76 ) )
V_27 -> V_77 ++ ;
else
V_27 -> V_77 = 1 ;
V_27 -> V_75 = V_74 ;
V_46:
return V_45 ;
}
static int F_36 ( struct V_56 * V_57 )
{
struct V_21 * V_78 ;
const struct V_59 * V_32 = F_37 ( V_57 ) ;
int V_45 ;
V_78 = F_6 ( F_19 ( V_57 -> V_3 ) , V_32 -> V_33 , V_32 -> V_34 ) ;
if ( V_78 != NULL ) {
struct V_6 * V_7 ;
if ( ! F_38 ( NULL , V_79 , V_57 ) )
goto V_80;
F_39 ( V_57 ) ;
V_57 -> V_81 = V_57 -> V_82 ;
F_40 ( V_57 ) ;
V_57 -> V_83 = F_41 ( V_84 ) ;
V_57 -> V_85 = V_86 ;
F_42 ( V_57 , V_78 -> V_3 ) ;
V_45 = F_43 ( V_32 , V_57 ) ;
if ( F_44 ( V_45 ) ) {
if ( V_87 )
F_45 ( L_2 ,
& V_32 -> V_33 , V_32 -> V_88 ) ;
if ( V_45 > 1 ) {
++ V_78 -> V_3 -> V_15 . V_89 ;
++ V_78 -> V_3 -> V_15 . V_90 ;
goto V_80;
}
}
V_7 = F_46 ( V_78 -> V_3 -> V_7 ) ;
F_47 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_57 -> V_91 ;
F_48 ( & V_7 -> V_13 ) ;
F_49 ( V_57 ) ;
return 0 ;
}
return - 1 ;
V_80:
F_50 ( V_57 ) ;
return 0 ;
}
static T_5 F_51 ( struct V_56 * V_57 , struct V_2 * V_3 )
{
struct V_21 * V_78 = F_18 ( V_3 ) ;
const struct V_59 * V_92 = & V_78 -> V_31 . V_32 ;
T_6 V_88 = V_78 -> V_31 . V_32 . V_88 ;
T_7 V_93 = V_92 -> V_94 ;
struct V_95 * V_96 ;
struct V_2 * V_97 ;
const struct V_59 * V_98 ;
struct V_59 * V_32 ;
unsigned int V_99 ;
T_2 V_100 = V_92 -> V_34 ;
struct V_101 V_102 ;
int V_103 ;
if ( V_57 -> V_83 != F_41 ( V_84 ) )
goto V_104;
if ( V_57 -> V_105 == V_106 &&
F_52 ( V_57 ) )
goto V_104;
V_98 = F_37 ( V_57 ) ;
if ( V_88 & 1 )
V_88 = V_98 -> V_88 ;
if ( ! V_100 ) {
if ( ( V_96 = F_53 ( V_57 ) ) == NULL ) {
V_3 -> V_15 . V_14 ++ ;
goto V_104;
}
V_100 = F_54 ( V_96 , V_98 -> V_34 ) ;
}
V_96 = F_55 ( F_19 ( V_3 ) , & V_102 , NULL ,
V_100 , V_92 -> V_33 ,
0 , 0 ,
V_72 , F_56 ( V_88 ) ,
V_78 -> V_31 . V_107 ) ;
if ( F_57 ( V_96 ) ) {
V_3 -> V_15 . V_16 ++ ;
goto V_108;
}
V_97 = V_96 -> V_100 . V_3 ;
if ( V_97 == V_3 ) {
F_58 ( V_96 ) ;
V_3 -> V_15 . V_20 ++ ;
goto V_104;
}
V_93 |= V_98 -> V_94 & F_41 ( V_109 ) ;
if ( V_93 ) {
V_103 = F_59 ( & V_96 -> V_100 ) - sizeof( struct V_59 ) ;
if ( V_103 < 68 ) {
V_3 -> V_15 . V_20 ++ ;
F_58 ( V_96 ) ;
goto V_104;
}
if ( F_60 ( V_57 ) )
F_60 ( V_57 ) -> V_110 -> V_111 ( F_60 ( V_57 ) , NULL , V_57 , V_103 ) ;
if ( ( V_98 -> V_94 & F_41 ( V_109 ) ) &&
V_103 < F_61 ( V_98 -> V_112 ) ) {
F_62 ( V_57 , V_63 , V_70 ,
F_63 ( V_103 ) ) ;
F_58 ( V_96 ) ;
goto V_104;
}
}
if ( V_78 -> V_77 > 0 ) {
if ( F_35 ( V_74 ,
V_78 -> V_75 + V_76 ) ) {
V_78 -> V_77 -- ;
F_64 ( V_57 ) ;
} else
V_78 -> V_77 = 0 ;
}
V_99 = ( F_65 ( V_97 ) + sizeof( struct V_59 ) ) ;
if ( F_66 ( V_57 ) < V_99 || F_67 ( V_57 ) ||
( F_68 ( V_57 ) && ! F_69 ( V_57 , 0 ) ) ) {
struct V_56 * V_113 = F_70 ( V_57 , V_99 ) ;
if ( ! V_113 ) {
F_58 ( V_96 ) ;
V_3 -> V_15 . V_17 ++ ;
F_71 ( V_57 ) ;
return V_114 ;
}
if ( V_57 -> V_115 )
F_72 ( V_113 , V_57 -> V_115 ) ;
F_71 ( V_57 ) ;
V_57 = V_113 ;
V_98 = F_37 ( V_57 ) ;
}
V_57 -> V_116 = V_57 -> V_82 ;
F_73 ( V_57 , sizeof( struct V_59 ) ) ;
F_40 ( V_57 ) ;
memset ( & ( F_74 ( V_57 ) -> V_117 ) , 0 , sizeof( F_74 ( V_57 ) -> V_117 ) ) ;
F_74 ( V_57 ) -> V_35 &= ~ ( V_118 | V_119 |
V_120 ) ;
F_75 ( V_57 ) ;
F_76 ( V_57 , & V_96 -> V_100 ) ;
V_32 = F_37 ( V_57 ) ;
V_32 -> V_121 = 4 ;
V_32 -> V_122 = sizeof( struct V_59 ) >> 2 ;
V_32 -> V_94 = V_93 ;
V_32 -> V_83 = V_72 ;
V_32 -> V_88 = F_77 ( V_88 , V_98 -> V_88 ) ;
V_32 -> V_34 = V_102 . V_34 ;
V_32 -> V_33 = V_102 . V_33 ;
if ( ( V_32 -> V_73 = V_92 -> V_73 ) == 0 )
V_32 -> V_73 = V_98 -> V_73 ;
F_78 ( V_57 , V_3 ) ;
return V_114 ;
V_108:
F_64 ( V_57 ) ;
V_104:
V_3 -> V_15 . V_19 ++ ;
F_71 ( V_57 ) ;
return V_114 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_2 * V_97 = NULL ;
struct V_21 * V_78 ;
const struct V_59 * V_32 ;
V_78 = F_18 ( V_3 ) ;
V_32 = & V_78 -> V_31 . V_32 ;
if ( V_32 -> V_34 ) {
struct V_95 * V_96 ;
struct V_101 V_102 ;
V_96 = F_55 ( F_19 ( V_3 ) , & V_102 , NULL ,
V_32 -> V_34 , V_32 -> V_33 ,
0 , 0 ,
V_72 ,
F_56 ( V_32 -> V_88 ) ,
V_78 -> V_31 . V_107 ) ;
if ( ! F_57 ( V_96 ) ) {
V_97 = V_96 -> V_100 . V_3 ;
F_58 ( V_96 ) ;
}
V_3 -> V_35 |= V_123 ;
}
if ( ! V_97 && V_78 -> V_31 . V_107 )
V_97 = F_80 ( F_19 ( V_3 ) , V_78 -> V_31 . V_107 ) ;
if ( V_97 ) {
V_3 -> V_124 = V_97 -> V_124 + sizeof( struct V_59 ) ;
V_3 -> V_103 = V_97 -> V_103 - sizeof( struct V_59 ) ;
}
V_3 -> V_125 = V_78 -> V_31 . V_107 ;
}
static void F_81 ( struct V_21 * V_27 , struct V_38 * V_126 )
{
struct V_22 * V_22 = F_19 ( V_27 -> V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_13 ( V_29 , V_27 ) ;
F_82 () ;
V_27 -> V_31 . V_32 . V_33 = V_126 -> V_32 . V_33 ;
V_27 -> V_31 . V_32 . V_34 = V_126 -> V_32 . V_34 ;
memcpy ( V_27 -> V_3 -> V_127 , & V_126 -> V_32 . V_33 , 4 ) ;
memcpy ( V_27 -> V_3 -> V_128 , & V_126 -> V_32 . V_34 , 4 ) ;
F_16 ( V_29 , V_27 ) ;
V_27 -> V_31 . V_32 . V_73 = V_126 -> V_32 . V_73 ;
V_27 -> V_31 . V_32 . V_88 = V_126 -> V_32 . V_88 ;
V_27 -> V_31 . V_32 . V_94 = V_126 -> V_32 . V_94 ;
if ( V_27 -> V_31 . V_107 != V_126 -> V_107 ) {
V_27 -> V_31 . V_107 = V_126 -> V_107 ;
F_79 ( V_27 -> V_3 ) ;
}
F_83 ( V_27 -> V_3 ) ;
}
static int
F_84 ( struct V_2 * V_3 , struct V_129 * V_130 , int V_131 )
{
int V_45 = 0 ;
struct V_38 V_126 ;
struct V_21 * V_27 ;
struct V_22 * V_22 = F_19 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
switch ( V_131 ) {
case V_132 :
V_27 = NULL ;
if ( V_3 == V_29 -> V_55 ) {
if ( F_85 ( & V_126 , V_130 -> V_133 . V_134 , sizeof( V_126 ) ) ) {
V_45 = - V_135 ;
break;
}
V_27 = F_23 ( V_22 , & V_126 , 0 ) ;
}
if ( V_27 == NULL )
V_27 = F_18 ( V_3 ) ;
memcpy ( & V_126 , & V_27 -> V_31 , sizeof( V_126 ) ) ;
if ( F_86 ( V_130 -> V_133 . V_134 , & V_126 , sizeof( V_126 ) ) )
V_45 = - V_135 ;
break;
case V_136 :
case V_137 :
V_45 = - V_138 ;
if ( ! F_87 ( V_22 -> V_139 , V_140 ) )
goto V_141;
V_45 = - V_135 ;
if ( F_85 ( & V_126 , V_130 -> V_133 . V_134 , sizeof( V_126 ) ) )
goto V_141;
V_45 = - V_142 ;
if ( V_126 . V_32 . V_121 != 4 || V_126 . V_32 . V_83 != V_72 ||
V_126 . V_32 . V_122 != 5 || ( V_126 . V_32 . V_94 & F_41 ( ~ V_109 ) ) )
goto V_141;
if ( V_126 . V_32 . V_73 )
V_126 . V_32 . V_94 |= F_41 ( V_109 ) ;
V_27 = F_23 ( V_22 , & V_126 , V_131 == V_136 ) ;
if ( V_3 != V_29 -> V_55 && V_131 == V_137 ) {
if ( V_27 != NULL ) {
if ( V_27 -> V_3 != V_3 ) {
V_45 = - V_143 ;
break;
}
} else {
if ( ( ( V_3 -> V_35 & V_123 ) && ! V_126 . V_32 . V_34 ) ||
( ! ( V_3 -> V_35 & V_123 ) && V_126 . V_32 . V_34 ) ) {
V_45 = - V_142 ;
break;
}
V_27 = F_18 ( V_3 ) ;
}
F_81 ( V_27 , & V_126 ) ;
}
if ( V_27 ) {
V_45 = 0 ;
if ( F_86 ( V_130 -> V_133 . V_134 , & V_27 -> V_31 , sizeof( V_126 ) ) )
V_45 = - V_135 ;
} else
V_45 = ( V_131 == V_136 ? - V_144 : - V_69 ) ;
break;
case V_145 :
V_45 = - V_138 ;
if ( ! F_87 ( V_22 -> V_139 , V_140 ) )
goto V_141;
if ( V_3 == V_29 -> V_55 ) {
V_45 = - V_135 ;
if ( F_85 ( & V_126 , V_130 -> V_133 . V_134 , sizeof( V_126 ) ) )
goto V_141;
V_45 = - V_69 ;
if ( ( V_27 = F_23 ( V_22 , & V_126 , 0 ) ) == NULL )
goto V_141;
V_45 = - V_138 ;
if ( V_27 -> V_3 == V_29 -> V_55 )
goto V_141;
V_3 = V_27 -> V_3 ;
}
F_88 ( V_3 ) ;
V_45 = 0 ;
break;
default:
V_45 = - V_142 ;
}
V_141:
return V_45 ;
}
static int F_89 ( struct V_2 * V_3 , int V_146 )
{
if ( V_146 < 68 || V_146 > 0xFFF8 - sizeof( struct V_59 ) )
return - V_142 ;
V_3 -> V_103 = V_146 ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_90 ( V_3 -> V_7 ) ;
F_91 ( V_3 ) ;
}
static void V_53 ( struct V_2 * V_3 )
{
V_3 -> V_147 = & V_148 ;
V_3 -> V_149 = F_27 ;
V_3 -> type = V_150 ;
V_3 -> V_124 = V_151 + sizeof( struct V_59 ) ;
V_3 -> V_103 = V_152 - sizeof( struct V_59 ) ;
V_3 -> V_35 = V_153 ;
V_3 -> V_125 = 0 ;
V_3 -> V_154 = 4 ;
V_3 -> V_155 |= V_156 ;
V_3 -> V_155 |= V_157 ;
V_3 -> V_158 &= ~ V_159 ;
V_3 -> V_155 |= V_160 ;
V_3 -> V_161 |= V_160 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_21 * V_78 = F_18 ( V_3 ) ;
V_78 -> V_3 = V_3 ;
memcpy ( V_3 -> V_127 , & V_78 -> V_31 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_128 , & V_78 -> V_31 . V_32 . V_34 , 4 ) ;
F_79 ( V_3 ) ;
V_3 -> V_7 = F_92 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_162 ;
return 0 ;
}
static int T_8 F_93 ( struct V_2 * V_3 )
{
struct V_21 * V_78 = F_18 ( V_3 ) ;
struct V_59 * V_32 = & V_78 -> V_31 . V_32 ;
struct V_28 * V_29 = F_8 ( F_19 ( V_3 ) , V_30 ) ;
V_78 -> V_3 = V_3 ;
strcpy ( V_78 -> V_31 . V_47 , V_3 -> V_47 ) ;
V_32 -> V_121 = 4 ;
V_32 -> V_83 = V_72 ;
V_32 -> V_122 = 5 ;
V_3 -> V_7 = F_92 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_162 ;
F_22 ( V_3 ) ;
F_15 ( V_29 -> V_37 [ 0 ] , V_78 ) ;
return 0 ;
}
static void F_94 ( struct V_163 * V_60 [] ,
struct V_38 * V_31 )
{
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_32 . V_121 = 4 ;
V_31 -> V_32 . V_83 = V_72 ;
V_31 -> V_32 . V_122 = 5 ;
if ( ! V_60 )
return;
if ( V_60 [ V_164 ] )
V_31 -> V_107 = F_95 ( V_60 [ V_164 ] ) ;
if ( V_60 [ V_165 ] )
V_31 -> V_32 . V_33 = F_96 ( V_60 [ V_165 ] ) ;
if ( V_60 [ V_166 ] )
V_31 -> V_32 . V_34 = F_96 ( V_60 [ V_166 ] ) ;
if ( V_60 [ V_167 ] ) {
V_31 -> V_32 . V_73 = F_97 ( V_60 [ V_167 ] ) ;
if ( V_31 -> V_32 . V_73 )
V_31 -> V_32 . V_94 = F_41 ( V_109 ) ;
}
if ( V_60 [ V_168 ] )
V_31 -> V_32 . V_88 = F_97 ( V_60 [ V_168 ] ) ;
if ( ! V_60 [ V_169 ] || F_97 ( V_60 [ V_169 ] ) )
V_31 -> V_32 . V_94 = F_41 ( V_109 ) ;
}
static int F_98 ( struct V_22 * V_170 , struct V_2 * V_3 ,
struct V_163 * V_171 [] , struct V_163 * V_60 [] )
{
struct V_22 * V_22 = F_19 ( V_3 ) ;
struct V_21 * V_51 ;
V_51 = F_18 ( V_3 ) ;
F_94 ( V_60 , & V_51 -> V_31 ) ;
if ( F_23 ( V_22 , & V_51 -> V_31 , 0 ) )
return - V_143 ;
return F_17 ( V_3 ) ;
}
static int F_99 ( struct V_2 * V_3 , struct V_163 * V_171 [] ,
struct V_163 * V_60 [] )
{
struct V_21 * V_27 ;
struct V_38 V_126 ;
struct V_22 * V_22 = F_19 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
if ( V_3 == V_29 -> V_55 )
return - V_142 ;
F_94 ( V_60 , & V_126 ) ;
if ( ( ( V_3 -> V_35 & V_123 ) && ! V_126 . V_32 . V_34 ) ||
( ! ( V_3 -> V_35 & V_123 ) && V_126 . V_32 . V_34 ) )
return - V_142 ;
V_27 = F_23 ( V_22 , & V_126 , 0 ) ;
if ( V_27 ) {
if ( V_27 -> V_3 != V_3 )
return - V_143 ;
} else
V_27 = F_18 ( V_3 ) ;
F_81 ( V_27 , & V_126 ) ;
return 0 ;
}
static T_9 F_100 ( const struct V_2 * V_3 )
{
return
F_101 ( 4 ) +
F_101 ( 4 ) +
F_101 ( 4 ) +
F_101 ( 1 ) +
F_101 ( 1 ) +
F_101 ( 1 ) +
0 ;
}
static int F_102 ( struct V_56 * V_57 , const struct V_2 * V_3 )
{
struct V_21 * V_78 = F_18 ( V_3 ) ;
struct V_38 * V_172 = & V_78 -> V_31 ;
if ( F_103 ( V_57 , V_164 , V_172 -> V_107 ) ||
F_104 ( V_57 , V_165 , V_172 -> V_32 . V_33 ) ||
F_104 ( V_57 , V_166 , V_172 -> V_32 . V_34 ) ||
F_105 ( V_57 , V_167 , V_172 -> V_32 . V_73 ) ||
F_105 ( V_57 , V_168 , V_172 -> V_32 . V_88 ) ||
F_105 ( V_57 , V_169 ,
! ! ( V_172 -> V_32 . V_94 & F_41 ( V_109 ) ) ) )
goto V_173;
return 0 ;
V_173:
return - V_174 ;
}
static void F_106 ( struct V_28 * V_29 , struct V_175 * V_176 )
{
int V_40 ;
for ( V_40 = 1 ; V_40 < 4 ; V_40 ++ ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_177 ; V_39 ++ ) {
struct V_21 * V_27 ;
V_27 = F_14 ( V_29 -> V_41 [ V_40 ] [ V_39 ] ) ;
while ( V_27 != NULL ) {
F_107 ( V_27 -> V_3 , V_176 ) ;
V_27 = F_14 ( V_27 -> V_44 ) ;
}
}
}
}
static int T_8 F_108 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
struct V_21 * V_27 ;
int V_45 ;
V_29 -> V_41 [ 0 ] = V_29 -> V_37 ;
V_29 -> V_41 [ 1 ] = V_29 -> V_178 ;
V_29 -> V_41 [ 2 ] = V_29 -> V_179 ;
V_29 -> V_41 [ 3 ] = V_29 -> V_180 ;
V_29 -> V_55 = F_25 ( sizeof( struct V_21 ) ,
L_3 ,
V_53 ) ;
if ( ! V_29 -> V_55 ) {
V_45 = - V_162 ;
goto V_181;
}
F_26 ( V_29 -> V_55 , V_22 ) ;
V_45 = F_93 ( V_29 -> V_55 ) ;
if ( V_45 )
goto V_182;
if ( ( V_45 = F_109 ( V_29 -> V_55 ) ) )
goto V_182;
V_27 = F_18 ( V_29 -> V_55 ) ;
strcpy ( V_27 -> V_31 . V_47 , V_29 -> V_55 -> V_47 ) ;
return 0 ;
V_182:
F_27 ( V_29 -> V_55 ) ;
V_181:
return V_45 ;
}
static void T_10 F_110 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_111 ( V_183 ) ;
F_112 () ;
F_106 ( V_29 , & V_183 ) ;
F_107 ( V_29 -> V_55 , & V_183 ) ;
F_113 ( & V_183 ) ;
F_114 () ;
}
static int T_11 F_115 ( void )
{
int V_45 ;
F_116 ( V_184 ) ;
V_45 = F_117 ( & V_185 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_118 ( & V_186 , V_187 ) ;
if ( V_45 < 0 ) {
F_119 ( L_4 , V_188 ) ;
goto V_189;
}
V_45 = F_120 ( & V_49 ) ;
if ( V_45 < 0 )
goto V_190;
V_46:
return V_45 ;
V_190:
F_121 ( & V_186 , V_187 ) ;
V_189:
F_122 ( & V_185 ) ;
goto V_46;
}
static void T_12 F_123 ( void )
{
F_124 ( & V_49 ) ;
if ( F_121 ( & V_186 , V_187 ) )
F_119 ( L_5 , V_188 ) ;
F_122 ( & V_185 ) ;
}
