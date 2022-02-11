static inline T_1 F_1 ( T_2 V_1 )
{
T_1 * V_2 = ( T_1 * ) & V_1 ;
return F_2 ( V_2 [ 0 ] , V_2 [ 1 ] , V_3 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return F_4 ( V_1 , V_3 ) ;
}
static inline T_1 F_5 ( T_3 V_4 )
{
return F_4 ( ( V_5 T_1 ) V_4 , V_3 ) ;
}
static struct V_6 * F_6 ( struct V_7 * V_8 , T_2 V_1 )
{
struct V_9 * V_10 ;
struct V_6 * V_11 ;
V_10 = & V_8 -> V_12 [ F_1 ( V_1 ) % V_8 -> V_13 ] ;
F_7 (pdp, head, hlist_tid) {
if ( V_11 -> V_14 == V_15 &&
V_11 -> V_16 . V_17 . V_1 == V_1 )
return V_11 ;
}
return NULL ;
}
static struct V_6 * F_8 ( struct V_7 * V_8 , T_1 V_1 )
{
struct V_9 * V_10 ;
struct V_6 * V_11 ;
V_10 = & V_8 -> V_12 [ F_3 ( V_1 ) % V_8 -> V_13 ] ;
F_7 (pdp, head, hlist_tid) {
if ( V_11 -> V_14 == V_18 &&
V_11 -> V_16 . V_19 . V_20 == V_1 )
return V_11 ;
}
return NULL ;
}
static struct V_6 * F_9 ( struct V_7 * V_8 , T_3 V_21 )
{
struct V_9 * V_10 ;
struct V_6 * V_11 ;
V_10 = & V_8 -> V_22 [ F_5 ( V_21 ) % V_8 -> V_13 ] ;
F_7 (pdp, head, hlist_addr) {
if ( V_11 -> V_23 == V_24 &&
V_11 -> V_25 . V_26 == V_21 )
return V_11 ;
}
return NULL ;
}
static bool F_10 ( struct V_27 * V_28 , struct V_6 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_32 * V_33 ;
if ( ! F_11 ( V_28 , V_30 + sizeof( struct V_32 ) ) )
return false ;
V_33 = (struct V_32 * ) ( V_28 -> V_34 + V_30 ) ;
if ( V_31 == V_35 )
return V_33 -> V_36 == V_29 -> V_25 . V_26 ;
else
return V_33 -> V_37 == V_29 -> V_25 . V_26 ;
}
static bool F_12 ( struct V_27 * V_28 , struct V_6 * V_29 ,
unsigned int V_30 , unsigned int V_31 )
{
switch ( F_13 ( V_28 -> V_38 ) ) {
case V_39 :
return F_10 ( V_28 , V_29 , V_30 , V_31 ) ;
}
return false ;
}
static int F_14 ( struct V_6 * V_29 , struct V_27 * V_28 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_40 * V_41 ;
if ( ! F_12 ( V_28 , V_29 , V_30 , V_31 ) ) {
F_15 ( V_29 -> V_42 , L_1 ) ;
return 1 ;
}
if ( F_16 ( V_28 , V_30 , V_28 -> V_38 ,
! F_17 ( F_18 ( V_29 -> V_43 ) , F_19 ( V_29 -> V_42 ) ) ) )
return - 1 ;
F_15 ( V_29 -> V_42 , L_2 ) ;
F_20 ( V_28 ) ;
V_28 -> V_42 = V_29 -> V_42 ;
V_41 = F_21 ( V_29 -> V_42 -> V_44 ) ;
F_22 ( & V_41 -> V_45 ) ;
V_41 -> V_46 ++ ;
V_41 -> V_47 += V_28 -> V_48 ;
F_23 ( & V_41 -> V_45 ) ;
F_24 ( V_28 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
unsigned int V_30 = sizeof( struct V_49 ) +
sizeof( struct V_50 ) ;
struct V_50 * V_51 ;
struct V_6 * V_29 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_51 = (struct V_50 * ) ( V_28 -> V_34 + sizeof( struct V_49 ) ) ;
if ( ( V_51 -> V_52 >> 5 ) != V_15 )
return 1 ;
if ( V_51 -> type != V_53 )
return 1 ;
V_29 = F_6 ( V_8 , F_26 ( V_51 -> V_1 ) ) ;
if ( ! V_29 ) {
F_15 ( V_8 -> V_42 , L_3 , V_28 ) ;
return 1 ;
}
return F_14 ( V_29 , V_28 , V_30 , V_8 -> V_31 ) ;
}
static int F_27 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
unsigned int V_30 = sizeof( struct V_49 ) +
sizeof( struct V_54 ) ;
struct V_54 * V_55 ;
struct V_6 * V_29 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_55 = (struct V_54 * ) ( V_28 -> V_34 + sizeof( struct V_49 ) ) ;
if ( ( V_55 -> V_52 >> 5 ) != V_18 )
return 1 ;
if ( V_55 -> type != V_53 )
return 1 ;
if ( V_55 -> V_52 & V_56 )
V_30 += 4 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_55 = (struct V_54 * ) ( V_28 -> V_34 + sizeof( struct V_49 ) ) ;
V_29 = F_8 ( V_8 , F_28 ( V_55 -> V_1 ) ) ;
if ( ! V_29 ) {
F_15 ( V_8 -> V_42 , L_3 , V_28 ) ;
return 1 ;
}
return F_14 ( V_29 , V_28 , V_30 , V_8 -> V_31 ) ;
}
static void F_29 ( struct V_57 * V_43 )
{
struct V_7 * V_8 ;
V_8 = F_30 ( V_43 ) ;
if ( V_8 ) {
F_31 ( V_43 ) -> V_58 = 0 ;
F_32 ( V_43 , NULL ) ;
F_33 ( V_43 ) ;
}
}
static void F_34 ( struct V_57 * V_43 )
{
if ( ! V_43 )
return;
F_29 ( V_43 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
F_34 ( V_8 -> V_59 ) ;
F_34 ( V_8 -> V_60 ) ;
}
static int F_36 ( struct V_57 * V_43 , struct V_27 * V_28 )
{
struct V_7 * V_8 ;
int V_61 = 0 ;
V_8 = F_30 ( V_43 ) ;
if ( ! V_8 )
return 1 ;
F_15 ( V_8 -> V_42 , L_4 , V_43 ) ;
switch ( F_31 ( V_43 ) -> V_58 ) {
case V_62 :
F_15 ( V_8 -> V_42 , L_5 ) ;
V_61 = F_25 ( V_8 , V_28 ) ;
break;
case V_63 :
F_15 ( V_8 -> V_42 , L_6 ) ;
V_61 = F_27 ( V_8 , V_28 ) ;
break;
default:
V_61 = - 1 ;
}
switch ( V_61 ) {
case 1 :
F_15 ( V_8 -> V_42 , L_7 ) ;
break;
case 0 :
break;
case - 1 :
F_15 ( V_8 -> V_42 , L_8 ) ;
F_37 ( V_28 ) ;
V_61 = 0 ;
break;
}
return V_61 ;
}
static int F_38 ( struct V_64 * V_42 )
{
struct V_7 * V_8 = F_39 ( V_42 ) ;
V_8 -> V_42 = V_42 ;
V_42 -> V_44 = F_40 ( struct V_40 ) ;
if ( ! V_42 -> V_44 )
return - V_65 ;
return 0 ;
}
static void F_41 ( struct V_64 * V_42 )
{
struct V_7 * V_8 = F_39 ( V_42 ) ;
F_35 ( V_8 ) ;
F_42 ( V_42 -> V_44 ) ;
}
static struct V_66 * F_43 ( struct V_67 * V_68 ,
const struct V_57 * V_43 ,
T_3 V_36 )
{
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_69 = V_43 -> V_70 ;
V_68 -> V_36 = V_36 ;
V_68 -> V_37 = F_44 ( V_43 ) -> V_71 ;
V_68 -> V_72 = F_45 ( V_43 ) ;
V_68 -> V_73 = V_43 -> V_74 ;
return F_46 ( F_18 ( V_43 ) , V_68 ) ;
}
static inline void F_47 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_75 = V_28 -> V_48 ;
struct V_50 * V_51 ;
V_51 = F_48 ( V_28 , sizeof( * V_51 ) ) ;
V_51 -> V_52 = 0x1e ;
V_51 -> type = V_53 ;
V_51 -> V_76 = F_49 ( V_75 ) ;
V_51 -> V_77 = F_49 ( ( F_50 ( & V_29 -> V_78 ) - 1 ) % 0xffff ) ;
V_51 -> V_79 = F_49 ( V_29 -> V_16 . V_17 . V_79 ) ;
V_51 -> V_80 = 0xff ;
V_51 -> V_81 [ 0 ] = V_51 -> V_81 [ 1 ] = V_51 -> V_81 [ 2 ] = 0xff ;
V_51 -> V_1 = F_51 ( V_29 -> V_16 . V_17 . V_1 ) ;
}
static inline void F_52 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_75 = V_28 -> V_48 ;
struct V_54 * V_55 ;
V_55 = F_48 ( V_28 , sizeof( * V_55 ) ) ;
V_55 -> V_52 = 0x30 ;
V_55 -> type = V_53 ;
V_55 -> V_76 = F_49 ( V_75 ) ;
V_55 -> V_1 = F_53 ( V_29 -> V_16 . V_19 . V_82 ) ;
}
static void F_54 ( struct V_27 * V_28 , struct V_83 * V_84 )
{
switch ( V_84 -> V_29 -> V_14 ) {
case V_15 :
V_84 -> V_85 = F_49 ( V_86 ) ;
F_47 ( V_28 , V_84 -> V_29 ) ;
break;
case V_18 :
V_84 -> V_85 = F_49 ( V_87 ) ;
F_52 ( V_28 , V_84 -> V_29 ) ;
break;
}
}
static inline void F_55 ( struct V_83 * V_84 ,
struct V_57 * V_43 , struct V_32 * V_33 ,
struct V_6 * V_29 , struct V_66 * V_88 ,
struct V_67 * V_68 ,
struct V_64 * V_42 )
{
V_84 -> V_43 = V_43 ;
V_84 -> V_33 = V_33 ;
V_84 -> V_29 = V_29 ;
V_84 -> V_88 = V_88 ;
V_84 -> V_68 = * V_68 ;
V_84 -> V_42 = V_42 ;
}
static int F_56 ( struct V_27 * V_28 , struct V_64 * V_42 ,
struct V_83 * V_84 )
{
struct V_7 * V_8 = F_39 ( V_42 ) ;
struct V_6 * V_29 ;
struct V_66 * V_88 ;
struct V_67 V_68 ;
struct V_32 * V_33 ;
T_4 V_89 ;
int V_90 ;
V_33 = F_57 ( V_28 ) ;
if ( V_8 -> V_31 == V_35 )
V_29 = F_9 ( V_8 , V_33 -> V_37 ) ;
else
V_29 = F_9 ( V_8 , V_33 -> V_36 ) ;
if ( ! V_29 ) {
F_15 ( V_42 , L_9 ,
& V_33 -> V_36 ) ;
return - V_91 ;
}
F_15 ( V_42 , L_10 , V_29 ) ;
V_88 = F_43 ( & V_68 , V_29 -> V_43 , V_29 -> V_92 . V_26 ) ;
if ( F_58 ( V_88 ) ) {
F_15 ( V_42 , L_11 ,
& V_29 -> V_92 . V_26 ) ;
V_42 -> V_41 . V_93 ++ ;
goto V_94;
}
if ( V_88 -> V_95 . V_42 == V_42 ) {
F_15 ( V_42 , L_12 ,
& V_29 -> V_92 . V_26 ) ;
V_42 -> V_41 . V_96 ++ ;
goto V_97;
}
F_59 ( V_28 ) ;
V_89 = V_33 -> V_98 ;
if ( V_89 ) {
V_90 = F_60 ( & V_88 -> V_95 ) - V_42 -> V_99 -
sizeof( struct V_32 ) - sizeof( struct V_49 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_90 -= sizeof( struct V_50 ) ;
break;
case V_18 :
V_90 -= sizeof( struct V_54 ) ;
break;
}
} else {
V_90 = F_60 ( & V_88 -> V_95 ) ;
}
V_88 -> V_95 . V_100 -> V_101 ( & V_88 -> V_95 , NULL , V_28 , V_90 ) ;
if ( ! F_61 ( V_28 ) && ( V_33 -> V_98 & F_49 ( V_102 ) ) &&
V_90 < F_13 ( V_33 -> V_103 ) ) {
F_15 ( V_42 , L_13 ) ;
memset ( F_62 ( V_28 ) , 0 , sizeof( * F_62 ( V_28 ) ) ) ;
F_63 ( V_28 , V_104 , V_105 ,
F_53 ( V_90 ) ) ;
goto V_97;
}
F_55 ( V_84 , V_29 -> V_43 , V_33 , V_29 , V_88 , & V_68 , V_42 ) ;
F_54 ( V_28 , V_84 ) ;
return 0 ;
V_97:
F_64 ( V_88 ) ;
V_94:
return - V_106 ;
}
static T_5 F_65 ( struct V_27 * V_28 , struct V_64 * V_42 )
{
unsigned int V_107 = F_13 ( V_28 -> V_38 ) ;
struct V_83 V_84 ;
int V_94 ;
if ( F_66 ( V_28 , V_42 -> V_108 ) )
goto V_109;
F_67 ( V_28 ) ;
F_68 () ;
switch ( V_107 ) {
case V_39 :
V_94 = F_56 ( V_28 , V_42 , & V_84 ) ;
break;
default:
V_94 = - V_110 ;
break;
}
F_69 () ;
if ( V_94 < 0 )
goto V_109;
switch ( V_107 ) {
case V_39 :
F_15 ( V_84 . V_42 , L_14 ,
& V_84 . V_33 -> V_37 , & V_84 . V_33 -> V_36 ) ;
F_70 ( V_84 . V_88 , V_84 . V_43 , V_28 ,
V_84 . V_68 . V_37 , V_84 . V_68 . V_36 ,
V_84 . V_33 -> V_111 ,
F_71 ( & V_84 . V_88 -> V_95 ) ,
0 ,
V_84 . V_85 , V_84 . V_85 ,
true , false ) ;
break;
}
return V_112 ;
V_109:
V_42 -> V_41 . V_113 ++ ;
F_72 ( V_28 ) ;
return V_112 ;
}
static void F_73 ( struct V_64 * V_42 )
{
V_42 -> V_114 = & V_115 ;
V_42 -> V_116 = true ;
V_42 -> V_99 = 0 ;
V_42 -> V_117 = 0 ;
V_42 -> type = V_118 ;
V_42 -> V_52 = V_119 | V_120 | V_121 ;
V_42 -> V_122 |= V_123 ;
V_42 -> V_124 |= V_125 ;
F_74 ( V_42 ) ;
V_42 -> V_108 = V_126 +
sizeof( struct V_32 ) +
sizeof( struct V_49 ) +
sizeof( struct V_50 ) ;
}
static int F_75 ( struct V_127 * V_128 , struct V_64 * V_42 ,
struct V_129 * V_130 [] , struct V_129 * V_34 [] ,
struct V_131 * V_132 )
{
struct V_7 * V_8 ;
struct V_133 * V_134 ;
int V_135 , V_94 ;
if ( ! V_34 [ V_136 ] && ! V_34 [ V_137 ] )
return - V_138 ;
V_8 = F_39 ( V_42 ) ;
V_94 = F_76 ( V_8 , V_34 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! V_34 [ V_139 ] )
V_135 = 1024 ;
else
V_135 = F_77 ( V_34 [ V_139 ] ) ;
V_94 = F_78 ( V_8 , V_135 ) ;
if ( V_94 < 0 )
goto V_140;
V_94 = F_79 ( V_42 ) ;
if ( V_94 < 0 ) {
F_15 ( V_42 , L_15 , V_94 ) ;
goto V_141;
}
V_134 = F_80 ( F_19 ( V_42 ) , V_142 ) ;
F_81 ( & V_8 -> V_143 , & V_134 -> V_144 ) ;
F_15 ( V_42 , L_16 ) ;
return 0 ;
V_141:
F_82 ( V_8 ) ;
V_140:
F_35 ( V_8 ) ;
return V_94 ;
}
static void F_83 ( struct V_64 * V_42 , struct V_145 * V_10 )
{
struct V_7 * V_8 = F_39 ( V_42 ) ;
F_35 ( V_8 ) ;
F_82 ( V_8 ) ;
F_84 ( & V_8 -> V_143 ) ;
F_85 ( V_42 , V_10 ) ;
}
static int F_86 ( struct V_129 * V_130 [] , struct V_129 * V_34 [] ,
struct V_131 * V_132 )
{
if ( ! V_34 )
return - V_138 ;
return 0 ;
}
static T_6 F_87 ( const struct V_64 * V_42 )
{
return F_88 ( sizeof( V_146 ) ) ;
}
static int F_89 ( struct V_27 * V_28 , const struct V_64 * V_42 )
{
struct V_7 * V_8 = F_39 ( V_42 ) ;
if ( F_90 ( V_28 , V_139 , V_8 -> V_13 ) )
goto V_147;
return 0 ;
V_147:
return - V_148 ;
}
static int F_78 ( struct V_7 * V_8 , int V_149 )
{
int V_150 ;
V_8 -> V_22 = F_91 ( sizeof( struct V_9 ) * V_149 , V_151 ) ;
if ( V_8 -> V_22 == NULL )
return - V_65 ;
V_8 -> V_12 = F_91 ( sizeof( struct V_9 ) * V_149 , V_151 ) ;
if ( V_8 -> V_12 == NULL )
goto V_152;
V_8 -> V_13 = V_149 ;
for ( V_150 = 0 ; V_150 < V_149 ; V_150 ++ ) {
F_92 ( & V_8 -> V_22 [ V_150 ] ) ;
F_92 ( & V_8 -> V_12 [ V_150 ] ) ;
}
return 0 ;
V_152:
F_93 ( V_8 -> V_22 ) ;
return - V_65 ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_6 * V_29 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_8 -> V_13 ; V_150 ++ )
F_7 (pctx, &gtp->tid_hash[i], hlist_tid)
F_94 ( V_29 ) ;
F_95 () ;
F_93 ( V_8 -> V_22 ) ;
F_93 ( V_8 -> V_12 ) ;
}
static struct V_57 * F_96 ( int V_153 , int type ,
struct V_7 * V_8 )
{
struct V_154 V_155 = { NULL } ;
struct V_156 * V_57 ;
struct V_57 * V_43 ;
int V_94 ;
F_97 ( L_17 , V_153 , type ) ;
V_57 = F_98 ( V_153 , & V_94 ) ;
if ( ! V_57 ) {
F_97 ( L_18 , V_153 ) ;
return NULL ;
}
if ( V_57 -> V_43 -> V_74 != V_157 ) {
F_97 ( L_19 , V_153 ) ;
V_43 = F_99 ( - V_138 ) ;
goto V_158;
}
if ( F_30 ( V_57 -> V_43 ) ) {
V_43 = F_99 ( - V_159 ) ;
goto V_158;
}
V_43 = V_57 -> V_43 ;
F_100 ( V_43 ) ;
V_155 . V_160 = V_8 ;
V_155 . V_58 = type ;
V_155 . V_161 = F_36 ;
V_155 . V_162 = F_29 ;
F_101 ( F_18 ( V_57 -> V_43 ) , V_57 , & V_155 ) ;
V_158:
F_102 ( V_57 ) ;
return V_43 ;
}
static int F_76 ( struct V_7 * V_8 , struct V_129 * V_34 [] )
{
struct V_57 * V_60 = NULL ;
struct V_57 * V_59 = NULL ;
unsigned int V_31 = V_163 ;
if ( V_34 [ V_136 ] ) {
T_1 V_164 = F_77 ( V_34 [ V_136 ] ) ;
V_59 = F_96 ( V_164 , V_62 , V_8 ) ;
if ( F_58 ( V_59 ) )
return F_103 ( V_59 ) ;
}
if ( V_34 [ V_137 ] ) {
T_1 V_165 = F_77 ( V_34 [ V_137 ] ) ;
V_60 = F_96 ( V_165 , V_63 , V_8 ) ;
if ( F_58 ( V_60 ) ) {
if ( V_59 )
F_34 ( V_59 ) ;
return F_103 ( V_60 ) ;
}
}
if ( V_34 [ V_166 ] ) {
V_31 = F_77 ( V_34 [ V_166 ] ) ;
if ( V_31 > V_35 )
return - V_138 ;
}
V_8 -> V_59 = V_59 ;
V_8 -> V_60 = V_60 ;
V_8 -> V_31 = V_31 ;
return 0 ;
}
static struct V_7 * F_104 ( struct V_127 * V_128 , struct V_129 * V_167 [] )
{
struct V_7 * V_8 = NULL ;
struct V_64 * V_42 ;
struct V_127 * V_127 ;
if ( V_167 [ V_168 ] )
V_127 = F_105 ( F_77 ( V_167 [ V_168 ] ) ) ;
else
V_127 = F_106 ( V_128 ) ;
if ( F_58 ( V_127 ) )
return NULL ;
V_42 = F_107 ( V_127 , F_77 ( V_167 [ V_169 ] ) ) ;
if ( V_42 && V_42 -> V_114 == & V_115 )
V_8 = F_39 ( V_42 ) ;
F_108 ( V_127 ) ;
return V_8 ;
}
static void F_109 ( struct V_6 * V_29 , struct V_170 * V_171 )
{
V_29 -> V_14 = F_77 ( V_171 -> V_172 [ V_173 ] ) ;
V_29 -> V_23 = V_24 ;
V_29 -> V_92 . V_26 =
F_110 ( V_171 -> V_172 [ V_174 ] ) ;
V_29 -> V_25 . V_26 =
F_110 ( V_171 -> V_172 [ V_175 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_29 -> V_16 . V_17 . V_1 = F_111 ( V_171 -> V_172 [ V_176 ] ) ;
V_29 -> V_16 . V_17 . V_79 = F_112 ( V_171 -> V_172 [ V_177 ] ) ;
break;
case V_18 :
V_29 -> V_16 . V_19 . V_20 = F_77 ( V_171 -> V_172 [ V_178 ] ) ;
V_29 -> V_16 . V_19 . V_82 = F_77 ( V_171 -> V_172 [ V_179 ] ) ;
break;
default:
break;
}
}
static int F_113 ( struct V_7 * V_8 , struct V_57 * V_43 ,
struct V_170 * V_171 )
{
struct V_64 * V_42 = V_8 -> V_42 ;
T_1 V_180 , V_181 = 0 ;
struct V_6 * V_29 ;
bool V_182 = false ;
T_3 V_21 ;
V_21 = F_110 ( V_171 -> V_172 [ V_175 ] ) ;
V_180 = F_5 ( V_21 ) % V_8 -> V_13 ;
F_7 (pctx, &gtp->addr_hash[hash_ms], hlist_addr) {
if ( V_29 -> V_25 . V_26 == V_21 ) {
V_182 = true ;
break;
}
}
if ( V_182 ) {
if ( V_171 -> V_183 -> V_184 & V_185 )
return - V_186 ;
if ( V_171 -> V_183 -> V_184 & V_187 )
return - V_110 ;
F_109 ( V_29 , V_171 ) ;
if ( V_29 -> V_14 == V_15 )
F_15 ( V_42 , L_20 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_15 ( V_42 , L_21 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 , V_29 ) ;
return 0 ;
}
V_29 = F_91 ( sizeof( struct V_6 ) , V_151 ) ;
if ( V_29 == NULL )
return - V_65 ;
F_100 ( V_43 ) ;
V_29 -> V_43 = V_43 ;
V_29 -> V_42 = V_8 -> V_42 ;
F_109 ( V_29 , V_171 ) ;
F_114 ( & V_29 -> V_78 , 0 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_181 = F_1 ( V_29 -> V_16 . V_17 . V_1 ) % V_8 -> V_13 ;
break;
case V_18 :
V_181 = F_3 ( V_29 -> V_16 . V_19 . V_20 ) % V_8 -> V_13 ;
break;
}
F_115 ( & V_29 -> V_188 , & V_8 -> V_22 [ V_180 ] ) ;
F_115 ( & V_29 -> V_189 , & V_8 -> V_12 [ V_181 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
F_15 ( V_42 , L_22 ,
V_29 -> V_16 . V_17 . V_1 , & V_29 -> V_92 ,
& V_29 -> V_25 , V_29 ) ;
break;
case V_18 :
F_15 ( V_42 , L_23 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 ,
& V_29 -> V_92 , & V_29 -> V_25 , V_29 ) ;
break;
}
return 0 ;
}
static void F_116 ( struct V_190 * V_10 )
{
struct V_6 * V_29 = F_117 ( V_10 , struct V_6 , V_190 ) ;
F_33 ( V_29 -> V_43 ) ;
F_93 ( V_29 ) ;
}
static void F_94 ( struct V_6 * V_29 )
{
F_118 ( & V_29 -> V_189 ) ;
F_118 ( & V_29 -> V_188 ) ;
F_119 ( & V_29 -> V_190 , F_116 ) ;
}
static int F_120 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
unsigned int V_191 ;
struct V_7 * V_8 ;
struct V_57 * V_43 ;
int V_94 ;
if ( ! V_171 -> V_172 [ V_173 ] ||
! V_171 -> V_172 [ V_169 ] ||
! V_171 -> V_172 [ V_174 ] ||
! V_171 -> V_172 [ V_175 ] )
return - V_138 ;
V_191 = F_77 ( V_171 -> V_172 [ V_173 ] ) ;
switch ( V_191 ) {
case V_15 :
if ( ! V_171 -> V_172 [ V_176 ] ||
! V_171 -> V_172 [ V_177 ] )
return - V_138 ;
break;
case V_18 :
if ( ! V_171 -> V_172 [ V_178 ] ||
! V_171 -> V_172 [ V_179 ] )
return - V_138 ;
break;
default:
return - V_138 ;
}
F_68 () ;
V_8 = F_104 ( F_18 ( V_28 -> V_43 ) , V_171 -> V_172 ) ;
if ( ! V_8 ) {
V_94 = - V_192 ;
goto V_193;
}
if ( V_191 == V_15 )
V_43 = V_8 -> V_59 ;
else if ( V_191 == V_18 )
V_43 = V_8 -> V_60 ;
else
V_43 = NULL ;
if ( ! V_43 ) {
V_94 = - V_192 ;
goto V_193;
}
V_94 = F_113 ( V_8 , V_43 , V_171 ) ;
V_193:
F_69 () ;
return V_94 ;
}
static struct V_6 * F_121 ( struct V_127 * V_127 ,
struct V_129 * V_167 [] )
{
struct V_7 * V_8 ;
V_8 = F_104 ( V_127 , V_167 ) ;
if ( ! V_8 )
return F_99 ( - V_192 ) ;
if ( V_167 [ V_175 ] ) {
T_3 V_4 = F_110 ( V_167 [ V_175 ] ) ;
return F_9 ( V_8 , V_4 ) ;
} else if ( V_167 [ V_173 ] ) {
T_1 V_14 = F_77 ( V_167 [ V_173 ] ) ;
if ( V_14 == V_15 && V_167 [ V_176 ] )
return F_6 ( V_8 , F_111 ( V_167 [ V_176 ] ) ) ;
else if ( V_14 == V_18 && V_167 [ V_178 ] )
return F_8 ( V_8 , F_77 ( V_167 [ V_178 ] ) ) ;
}
return F_99 ( - V_138 ) ;
}
static struct V_6 * F_122 ( struct V_127 * V_127 , struct V_129 * V_167 [] )
{
struct V_6 * V_29 ;
if ( V_167 [ V_169 ] )
V_29 = F_121 ( V_127 , V_167 ) ;
else
V_29 = F_99 ( - V_138 ) ;
if ( ! V_29 )
V_29 = F_99 ( - V_91 ) ;
return V_29 ;
}
static int F_123 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
struct V_6 * V_29 ;
int V_94 = 0 ;
if ( ! V_171 -> V_172 [ V_173 ] )
return - V_138 ;
F_68 () ;
V_29 = F_122 ( F_18 ( V_28 -> V_43 ) , V_171 -> V_172 ) ;
if ( F_58 ( V_29 ) ) {
V_94 = F_103 ( V_29 ) ;
goto V_193;
}
if ( V_29 -> V_14 == V_15 )
F_15 ( V_29 -> V_42 , L_24 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_15 ( V_29 -> V_42 , L_25 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 , V_29 ) ;
F_94 ( V_29 ) ;
V_193:
F_69 () ;
return V_94 ;
}
static int F_124 ( struct V_27 * V_28 , T_1 V_194 , T_1 V_195 ,
T_1 type , struct V_6 * V_29 )
{
void * V_196 ;
V_196 = F_125 ( V_28 , V_194 , V_195 , & V_197 , 0 ,
type ) ;
if ( V_196 == NULL )
goto V_198;
if ( F_90 ( V_28 , V_173 , V_29 -> V_14 ) ||
F_126 ( V_28 , V_174 , V_29 -> V_92 . V_26 ) ||
F_126 ( V_28 , V_175 , V_29 -> V_25 . V_26 ) )
goto V_147;
switch ( V_29 -> V_14 ) {
case V_15 :
if ( F_127 ( V_28 , V_176 , V_29 -> V_16 . V_17 . V_1 , V_199 ) ||
F_128 ( V_28 , V_177 , V_29 -> V_16 . V_17 . V_79 ) )
goto V_147;
break;
case V_18 :
if ( F_90 ( V_28 , V_178 , V_29 -> V_16 . V_19 . V_20 ) ||
F_90 ( V_28 , V_179 , V_29 -> V_16 . V_19 . V_82 ) )
goto V_147;
break;
}
F_129 ( V_28 , V_196 ) ;
return 0 ;
V_198:
V_147:
F_130 ( V_28 , V_196 ) ;
return - V_148 ;
}
static int F_131 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
struct V_6 * V_29 = NULL ;
struct V_27 * V_200 ;
int V_94 ;
if ( ! V_171 -> V_172 [ V_173 ] )
return - V_138 ;
F_68 () ;
V_29 = F_122 ( F_18 ( V_28 -> V_43 ) , V_171 -> V_172 ) ;
if ( F_58 ( V_29 ) ) {
V_94 = F_103 ( V_29 ) ;
goto V_201;
}
V_200 = F_132 ( V_202 , V_203 ) ;
if ( V_200 == NULL ) {
V_94 = - V_65 ;
goto V_201;
}
V_94 = F_124 ( V_200 , F_133 ( V_28 ) . V_204 ,
V_171 -> V_195 , V_171 -> V_183 -> V_205 , V_29 ) ;
if ( V_94 < 0 )
goto V_206;
F_69 () ;
return F_134 ( F_135 ( V_171 ) , V_200 , V_171 -> V_194 ) ;
V_206:
F_37 ( V_200 ) ;
V_201:
F_69 () ;
return V_94 ;
}
static int F_136 ( struct V_27 * V_28 ,
struct V_207 * V_208 )
{
struct V_7 * V_209 = (struct V_7 * ) V_208 -> args [ 2 ] , * V_8 ;
struct V_127 * V_127 = F_18 ( V_28 -> V_43 ) ;
struct V_133 * V_134 = F_80 ( V_127 , V_142 ) ;
unsigned long V_1 = V_208 -> args [ 1 ] ;
int V_150 , V_210 = V_208 -> args [ 0 ] , V_61 ;
struct V_6 * V_29 ;
if ( V_208 -> args [ 4 ] )
return 0 ;
F_137 (gtp, &gn->gtp_dev_list, list) {
if ( V_209 && V_209 != V_8 )
continue;
else
V_209 = NULL ;
for ( V_150 = V_210 ; V_150 < V_8 -> V_13 ; V_150 ++ ) {
F_7 (pctx, &gtp->tid_hash[i], hlist_tid) {
if ( V_1 && V_1 != V_29 -> V_16 . V_1 )
continue;
else
V_1 = 0 ;
V_61 = F_124 ( V_28 ,
F_133 ( V_208 -> V_28 ) . V_204 ,
V_208 -> V_211 -> V_212 ,
V_208 -> V_211 -> V_205 , V_29 ) ;
if ( V_61 < 0 ) {
V_208 -> args [ 0 ] = V_150 ;
V_208 -> args [ 1 ] = V_29 -> V_16 . V_1 ;
V_208 -> args [ 2 ] = ( unsigned long ) V_8 ;
goto V_213;
}
}
}
}
V_208 -> args [ 4 ] = 1 ;
V_213:
return V_28 -> V_48 ;
}
static int T_7 F_138 ( struct V_127 * V_127 )
{
struct V_133 * V_134 = F_80 ( V_127 , V_142 ) ;
F_139 ( & V_134 -> V_144 ) ;
return 0 ;
}
static void T_8 F_140 ( struct V_127 * V_127 )
{
struct V_133 * V_134 = F_80 ( V_127 , V_142 ) ;
struct V_7 * V_8 ;
F_141 ( V_143 ) ;
F_142 () ;
F_143 (gtp, &gn->gtp_dev_list, list)
F_83 ( V_8 -> V_42 , & V_143 ) ;
F_144 ( & V_143 ) ;
F_145 () ;
}
static int T_9 F_146 ( void )
{
int V_94 ;
F_147 ( & V_3 , sizeof( V_3 ) ) ;
V_94 = F_148 ( & V_214 ) ;
if ( V_94 < 0 )
goto V_215;
V_94 = F_149 ( & V_197 ) ;
if ( V_94 < 0 )
goto V_216;
V_94 = F_150 ( & V_217 ) ;
if ( V_94 < 0 )
goto V_218;
F_151 ( L_26 ,
sizeof( struct V_6 ) ) ;
return 0 ;
V_218:
F_152 ( & V_197 ) ;
V_216:
F_153 ( & V_214 ) ;
V_215:
F_154 ( L_27 ) ;
return V_94 ;
}
static void T_10 F_155 ( void )
{
F_156 ( & V_217 ) ;
F_152 ( & V_197 ) ;
F_153 ( & V_214 ) ;
F_151 ( L_28 ) ;
}
