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
unsigned int V_30 )
{
struct V_31 * V_32 ;
if ( ! F_11 ( V_28 , V_30 + sizeof( struct V_31 ) ) )
return false ;
V_32 = (struct V_31 * ) ( V_28 -> V_33 + V_30 ) ;
return V_32 -> V_34 == V_29 -> V_25 . V_26 ;
}
static bool F_12 ( struct V_27 * V_28 , struct V_6 * V_29 ,
unsigned int V_30 )
{
switch ( F_13 ( V_28 -> V_35 ) ) {
case V_36 :
return F_10 ( V_28 , V_29 , V_30 ) ;
}
return false ;
}
static int F_14 ( struct V_7 * V_8 , struct V_27 * V_28 ,
bool V_37 )
{
unsigned int V_30 = sizeof( struct V_38 ) +
sizeof( struct V_39 ) ;
struct V_39 * V_40 ;
struct V_6 * V_29 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_40 = (struct V_39 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
if ( ( V_40 -> V_41 >> 5 ) != V_15 )
return 1 ;
if ( V_40 -> type != V_42 )
return 1 ;
V_29 = F_6 ( V_8 , F_15 ( V_40 -> V_1 ) ) ;
if ( ! V_29 ) {
F_16 ( V_8 -> V_43 , L_1 , V_28 ) ;
return 1 ;
}
if ( ! F_12 ( V_28 , V_29 , V_30 ) ) {
F_16 ( V_8 -> V_43 , L_2 ) ;
return 1 ;
}
return F_17 ( V_28 , V_30 , V_28 -> V_35 , V_37 ) ;
}
static int F_18 ( struct V_7 * V_8 , struct V_27 * V_28 ,
bool V_37 )
{
unsigned int V_30 = sizeof( struct V_38 ) +
sizeof( struct V_44 ) ;
struct V_44 * V_45 ;
struct V_6 * V_29 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_45 = (struct V_44 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
if ( ( V_45 -> V_41 >> 5 ) != V_18 )
return 1 ;
if ( V_45 -> type != V_42 )
return 1 ;
if ( V_45 -> V_41 & V_46 )
V_30 += 4 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_45 = (struct V_44 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
V_29 = F_8 ( V_8 , F_19 ( V_45 -> V_1 ) ) ;
if ( ! V_29 ) {
F_16 ( V_8 -> V_43 , L_1 , V_28 ) ;
return 1 ;
}
if ( ! F_12 ( V_28 , V_29 , V_30 ) ) {
F_16 ( V_8 -> V_43 , L_2 ) ;
return 1 ;
}
return F_17 ( V_28 , V_30 , V_28 -> V_35 , V_37 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
if ( V_8 -> V_47 && V_8 -> V_47 -> V_48 ) {
F_21 ( V_8 -> V_47 -> V_48 ) -> V_49 = 0 ;
F_22 ( V_8 -> V_47 -> V_48 , NULL ) ;
}
if ( V_8 -> V_50 && V_8 -> V_50 -> V_48 ) {
F_21 ( V_8 -> V_50 -> V_48 ) -> V_49 = 0 ;
F_22 ( V_8 -> V_50 -> V_48 , NULL ) ;
}
V_8 -> V_47 = NULL ;
V_8 -> V_50 = NULL ;
}
static void F_23 ( struct V_51 * V_48 )
{
struct V_7 * V_8 ;
V_8 = F_24 ( V_48 ) ;
if ( V_8 )
F_20 ( V_8 ) ;
}
static int F_25 ( struct V_51 * V_48 , struct V_27 * V_28 )
{
struct V_52 * V_53 ;
struct V_7 * V_8 ;
bool V_37 ;
int V_54 ;
V_8 = F_24 ( V_48 ) ;
if ( ! V_8 )
return 1 ;
F_16 ( V_8 -> V_43 , L_3 , V_48 ) ;
V_37 = ! F_26 ( F_27 ( V_48 ) , F_28 ( V_8 -> V_43 ) ) ;
switch ( F_21 ( V_48 ) -> V_49 ) {
case V_55 :
F_16 ( V_8 -> V_43 , L_4 ) ;
V_54 = F_14 ( V_8 , V_28 , V_37 ) ;
break;
case V_56 :
F_16 ( V_8 -> V_43 , L_5 ) ;
V_54 = F_18 ( V_8 , V_28 , V_37 ) ;
break;
default:
V_54 = - 1 ;
}
switch ( V_54 ) {
case 1 :
F_16 ( V_8 -> V_43 , L_6 ) ;
return 1 ;
case 0 :
F_16 ( V_8 -> V_43 , L_7 ) ;
break;
case - 1 :
F_16 ( V_8 -> V_43 , L_8 ) ;
F_29 ( V_28 ) ;
return 0 ;
}
F_30 ( V_28 ) ;
V_28 -> V_43 = V_8 -> V_43 ;
V_53 = F_31 ( V_8 -> V_43 -> V_57 ) ;
F_32 ( & V_53 -> V_58 ) ;
V_53 -> V_59 ++ ;
V_53 -> V_60 += V_28 -> V_61 ;
F_33 ( & V_53 -> V_58 ) ;
F_34 ( V_28 ) ;
return 0 ;
}
static int F_35 ( struct V_62 * V_43 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
V_8 -> V_43 = V_43 ;
V_43 -> V_57 = F_37 ( struct V_52 ) ;
if ( ! V_43 -> V_57 )
return - V_63 ;
return 0 ;
}
static void F_38 ( struct V_62 * V_43 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
F_20 ( V_8 ) ;
F_39 ( V_43 -> V_57 ) ;
}
static struct V_64 * F_40 ( struct V_65 * V_65 , struct V_66 * V_67 ,
const struct V_51 * V_48 , T_3 V_68 )
{
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_69 = V_48 -> V_70 ;
V_67 -> V_68 = V_68 ;
V_67 -> V_34 = F_41 ( V_48 ) -> V_71 ;
V_67 -> V_72 = F_42 ( V_48 ) ;
V_67 -> V_73 = V_48 -> V_74 ;
return F_43 ( V_65 , V_67 ) ;
}
static inline void F_44 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_75 = V_28 -> V_61 ;
struct V_39 * V_40 ;
V_40 = (struct V_39 * ) F_45 ( V_28 , sizeof( * V_40 ) ) ;
V_40 -> V_41 = 0x1e ;
V_40 -> type = V_42 ;
V_40 -> V_76 = F_46 ( V_75 ) ;
V_40 -> V_77 = F_46 ( ( F_47 ( & V_29 -> V_78 ) - 1 ) % 0xffff ) ;
V_40 -> V_79 = F_46 ( V_29 -> V_16 . V_17 . V_79 ) ;
V_40 -> V_80 = 0xff ;
V_40 -> V_81 [ 0 ] = V_40 -> V_81 [ 1 ] = V_40 -> V_81 [ 2 ] = 0xff ;
V_40 -> V_1 = F_48 ( V_29 -> V_16 . V_17 . V_1 ) ;
}
static inline void F_49 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_75 = V_28 -> V_61 ;
struct V_44 * V_45 ;
V_45 = (struct V_44 * ) F_45 ( V_28 , sizeof( * V_45 ) ) ;
V_45 -> V_41 = 0x30 ;
V_45 -> type = V_42 ;
V_45 -> V_76 = F_46 ( V_75 ) ;
V_45 -> V_1 = F_50 ( V_29 -> V_16 . V_19 . V_82 ) ;
}
static void F_51 ( struct V_27 * V_28 , struct V_83 * V_84 )
{
switch ( V_84 -> V_29 -> V_14 ) {
case V_15 :
V_84 -> V_85 = F_46 ( V_86 ) ;
F_44 ( V_28 , V_84 -> V_29 ) ;
break;
case V_18 :
V_84 -> V_85 = F_46 ( V_87 ) ;
F_49 ( V_28 , V_84 -> V_29 ) ;
break;
}
}
static inline void F_52 ( struct V_83 * V_84 ,
struct V_51 * V_48 , struct V_31 * V_32 ,
struct V_6 * V_29 , struct V_64 * V_88 ,
struct V_66 * V_67 ,
struct V_62 * V_43 )
{
V_84 -> V_48 = V_48 ;
V_84 -> V_32 = V_32 ;
V_84 -> V_29 = V_29 ;
V_84 -> V_88 = V_88 ;
V_84 -> V_67 = * V_67 ;
V_84 -> V_43 = V_43 ;
}
static int F_53 ( struct V_27 * V_28 , struct V_62 * V_43 ,
struct V_83 * V_84 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
struct V_6 * V_29 ;
struct V_64 * V_88 ;
struct V_66 V_67 ;
struct V_31 * V_32 ;
struct V_51 * V_48 ;
T_4 V_89 ;
int V_90 ;
V_32 = F_54 ( V_28 ) ;
V_29 = F_9 ( V_8 , V_32 -> V_68 ) ;
if ( ! V_29 ) {
F_16 ( V_43 , L_9 ,
& V_32 -> V_68 ) ;
return - V_91 ;
}
F_16 ( V_43 , L_10 , V_29 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
if ( V_8 -> V_47 )
V_48 = V_8 -> V_47 -> V_48 ;
else
V_48 = NULL ;
break;
case V_18 :
if ( V_8 -> V_50 )
V_48 = V_8 -> V_50 -> V_48 ;
else
V_48 = NULL ;
break;
default:
return - V_91 ;
}
if ( ! V_48 ) {
F_16 ( V_43 , L_11 ) ;
return - V_91 ;
}
V_88 = F_40 ( F_27 ( V_48 ) , & V_67 , V_8 -> V_47 -> V_48 ,
V_29 -> V_92 . V_26 ) ;
if ( F_55 ( V_88 ) ) {
F_16 ( V_43 , L_12 ,
& V_29 -> V_92 . V_26 ) ;
V_43 -> V_53 . V_93 ++ ;
goto V_94;
}
if ( V_88 -> V_95 . V_43 == V_43 ) {
F_16 ( V_43 , L_13 ,
& V_29 -> V_92 . V_26 ) ;
V_43 -> V_53 . V_96 ++ ;
goto V_97;
}
F_56 ( V_28 ) ;
V_89 = V_32 -> V_98 ;
if ( V_89 ) {
V_90 = F_57 ( & V_88 -> V_95 ) - V_43 -> V_99 -
sizeof( struct V_31 ) - sizeof( struct V_38 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_90 -= sizeof( struct V_39 ) ;
break;
case V_18 :
V_90 -= sizeof( struct V_44 ) ;
break;
}
} else {
V_90 = F_57 ( & V_88 -> V_95 ) ;
}
V_88 -> V_95 . V_100 -> V_101 ( & V_88 -> V_95 , NULL , V_28 , V_90 ) ;
if ( ! F_58 ( V_28 ) && ( V_32 -> V_98 & F_46 ( V_102 ) ) &&
V_90 < F_13 ( V_32 -> V_103 ) ) {
F_16 ( V_43 , L_14 ) ;
memset ( F_59 ( V_28 ) , 0 , sizeof( * F_59 ( V_28 ) ) ) ;
F_60 ( V_28 , V_104 , V_105 ,
F_50 ( V_90 ) ) ;
goto V_97;
}
F_52 ( V_84 , V_48 , V_32 , V_29 , V_88 , & V_67 , V_43 ) ;
F_51 ( V_28 , V_84 ) ;
return 0 ;
V_97:
F_61 ( V_88 ) ;
V_94:
return - V_106 ;
}
static T_5 F_62 ( struct V_27 * V_28 , struct V_62 * V_43 )
{
unsigned int V_107 = F_13 ( V_28 -> V_35 ) ;
struct V_83 V_84 ;
int V_94 ;
if ( F_63 ( V_28 , V_43 -> V_108 ) )
goto V_109;
F_64 ( V_28 ) ;
F_65 () ;
switch ( V_107 ) {
case V_36 :
V_94 = F_53 ( V_28 , V_43 , & V_84 ) ;
break;
default:
V_94 = - V_110 ;
break;
}
F_66 () ;
if ( V_94 < 0 )
goto V_109;
switch ( V_107 ) {
case V_36 :
F_16 ( V_84 . V_43 , L_15 ,
& V_84 . V_32 -> V_34 , & V_84 . V_32 -> V_68 ) ;
F_67 ( V_84 . V_88 , V_84 . V_48 , V_28 ,
V_84 . V_67 . V_34 , V_84 . V_67 . V_68 ,
V_84 . V_32 -> V_111 ,
F_68 ( & V_84 . V_88 -> V_95 ) ,
0 ,
V_84 . V_85 , V_84 . V_85 ,
true , false ) ;
break;
}
return V_112 ;
V_109:
V_43 -> V_53 . V_113 ++ ;
F_69 ( V_28 ) ;
return V_112 ;
}
static void F_70 ( struct V_62 * V_43 )
{
V_43 -> V_114 = & V_115 ;
V_43 -> V_116 = V_117 ;
V_43 -> V_99 = 0 ;
V_43 -> V_118 = 0 ;
V_43 -> type = V_119 ;
V_43 -> V_41 = V_120 | V_121 | V_122 ;
V_43 -> V_123 |= V_124 ;
V_43 -> V_125 |= V_126 ;
F_71 ( V_43 ) ;
V_43 -> V_108 = V_127 +
sizeof( struct V_31 ) +
sizeof( struct V_38 ) +
sizeof( struct V_39 ) ;
}
static int F_72 ( struct V_65 * V_128 , struct V_62 * V_43 ,
struct V_129 * V_130 [] , struct V_129 * V_33 [] )
{
int V_131 , V_94 , V_132 , V_133 ;
struct V_7 * V_8 ;
struct V_134 * V_135 ;
if ( ! V_33 [ V_136 ] || ! V_33 [ V_137 ] )
return - V_138 ;
V_8 = F_36 ( V_43 ) ;
V_132 = F_73 ( V_33 [ V_136 ] ) ;
V_133 = F_73 ( V_33 [ V_137 ] ) ;
V_94 = F_74 ( V_43 , V_8 , V_132 , V_133 ) ;
if ( V_94 < 0 )
goto V_139;
if ( ! V_33 [ V_140 ] )
V_131 = 1024 ;
else
V_131 = F_73 ( V_33 [ V_140 ] ) ;
V_94 = F_75 ( V_8 , V_131 ) ;
if ( V_94 < 0 )
goto V_141;
V_94 = F_76 ( V_43 ) ;
if ( V_94 < 0 ) {
F_16 ( V_43 , L_16 , V_94 ) ;
goto V_142;
}
V_135 = F_77 ( F_28 ( V_43 ) , V_143 ) ;
F_78 ( & V_8 -> V_144 , & V_135 -> V_145 ) ;
F_16 ( V_43 , L_17 ) ;
return 0 ;
V_142:
F_79 ( V_8 ) ;
V_141:
F_20 ( V_8 ) ;
V_139:
return V_94 ;
}
static void F_80 ( struct V_62 * V_43 , struct V_146 * V_10 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
F_20 ( V_8 ) ;
F_79 ( V_8 ) ;
F_81 ( & V_8 -> V_144 ) ;
F_82 ( V_43 , V_10 ) ;
}
static int F_83 ( struct V_129 * V_130 [] , struct V_129 * V_33 [] )
{
if ( ! V_33 )
return - V_138 ;
return 0 ;
}
static T_6 F_84 ( const struct V_62 * V_43 )
{
return F_85 ( sizeof( V_147 ) ) ;
}
static int F_86 ( struct V_27 * V_28 , const struct V_62 * V_43 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
if ( F_87 ( V_28 , V_140 , V_8 -> V_13 ) )
goto V_148;
return 0 ;
V_148:
return - V_149 ;
}
static struct V_65 * F_88 ( struct V_65 * V_128 , struct V_129 * V_130 [] )
{
struct V_65 * V_65 ;
if ( V_130 [ V_150 ] )
V_65 = F_89 ( F_73 ( V_130 [ V_150 ] ) ) ;
else
V_65 = F_90 ( V_128 ) ;
return V_65 ;
}
static int F_75 ( struct V_7 * V_8 , int V_151 )
{
int V_152 ;
V_8 -> V_22 = F_91 ( sizeof( struct V_9 ) * V_151 , V_153 ) ;
if ( V_8 -> V_22 == NULL )
return - V_63 ;
V_8 -> V_12 = F_91 ( sizeof( struct V_9 ) * V_151 , V_153 ) ;
if ( V_8 -> V_12 == NULL )
goto V_154;
V_8 -> V_13 = V_151 ;
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ ) {
F_92 ( & V_8 -> V_22 [ V_152 ] ) ;
F_92 ( & V_8 -> V_12 [ V_152 ] ) ;
}
return 0 ;
V_154:
F_93 ( V_8 -> V_22 ) ;
return - V_63 ;
}
static void F_79 ( struct V_7 * V_8 )
{
struct V_6 * V_29 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < V_8 -> V_13 ; V_152 ++ ) {
F_7 (pctx, &gtp->tid_hash[i], hlist_tid) {
F_94 ( & V_29 -> V_155 ) ;
F_94 ( & V_29 -> V_156 ) ;
F_95 ( V_29 , V_157 ) ;
}
}
F_96 () ;
F_93 ( V_8 -> V_22 ) ;
F_93 ( V_8 -> V_12 ) ;
}
static int F_74 ( struct V_62 * V_43 , struct V_7 * V_8 ,
int V_158 , int V_159 )
{
struct V_160 V_161 = { NULL } ;
struct V_162 * V_47 , * V_50 ;
int V_94 ;
F_16 ( V_43 , L_18 , V_158 , V_159 ) ;
V_47 = F_97 ( V_158 , & V_94 ) ;
if ( V_47 == NULL ) {
F_16 ( V_43 , L_19 , V_158 ) ;
return - V_91 ;
}
if ( V_47 -> V_48 -> V_74 != V_163 ) {
F_16 ( V_43 , L_20 , V_158 ) ;
V_94 = - V_138 ;
goto V_154;
}
V_50 = F_97 ( V_159 , & V_94 ) ;
if ( V_50 == NULL ) {
F_16 ( V_43 , L_21 , V_159 ) ;
V_94 = - V_91 ;
goto V_154;
}
if ( V_50 -> V_48 -> V_74 != V_163 ) {
F_16 ( V_43 , L_20 , V_159 ) ;
V_94 = - V_138 ;
goto V_164;
}
F_16 ( V_43 , L_22 , V_47 , V_50 ) ;
V_8 -> V_47 = V_47 ;
V_8 -> V_50 = V_50 ;
V_161 . V_165 = V_8 ;
V_161 . V_166 = F_25 ;
V_161 . V_167 = F_23 ;
V_161 . V_49 = V_55 ;
F_98 ( F_27 ( V_8 -> V_47 -> V_48 ) , V_8 -> V_47 , & V_161 ) ;
V_161 . V_49 = V_56 ;
F_98 ( F_27 ( V_8 -> V_50 -> V_48 ) , V_8 -> V_50 , & V_161 ) ;
V_94 = 0 ;
V_164:
F_99 ( V_50 ) ;
V_154:
F_99 ( V_47 ) ;
return V_94 ;
}
static struct V_62 * F_100 ( struct V_65 * V_65 , int V_168 )
{
struct V_134 * V_135 = F_77 ( V_65 , V_143 ) ;
struct V_7 * V_8 ;
F_101 (gtp, &gn->gtp_dev_list, list) {
if ( V_168 == V_8 -> V_43 -> V_168 )
return V_8 -> V_43 ;
}
return NULL ;
}
static void F_102 ( struct V_6 * V_29 , struct V_169 * V_170 )
{
V_29 -> V_14 = F_73 ( V_170 -> V_171 [ V_172 ] ) ;
V_29 -> V_23 = V_24 ;
V_29 -> V_92 . V_26 =
F_103 ( V_170 -> V_171 [ V_173 ] ) ;
V_29 -> V_25 . V_26 =
F_103 ( V_170 -> V_171 [ V_174 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_29 -> V_16 . V_17 . V_1 = F_104 ( V_170 -> V_171 [ V_175 ] ) ;
V_29 -> V_16 . V_17 . V_79 = F_105 ( V_170 -> V_171 [ V_176 ] ) ;
break;
case V_18 :
V_29 -> V_16 . V_19 . V_20 = F_73 ( V_170 -> V_171 [ V_177 ] ) ;
V_29 -> V_16 . V_19 . V_82 = F_73 ( V_170 -> V_171 [ V_178 ] ) ;
break;
default:
break;
}
}
static int F_106 ( struct V_62 * V_43 , struct V_169 * V_170 )
{
struct V_7 * V_8 = F_36 ( V_43 ) ;
T_1 V_179 , V_180 = 0 ;
struct V_6 * V_29 ;
bool V_181 = false ;
T_3 V_21 ;
V_21 = F_103 ( V_170 -> V_171 [ V_174 ] ) ;
V_179 = F_5 ( V_21 ) % V_8 -> V_13 ;
F_7 (pctx, &gtp->addr_hash[hash_ms], hlist_addr) {
if ( V_29 -> V_25 . V_26 == V_21 ) {
V_181 = true ;
break;
}
}
if ( V_181 ) {
if ( V_170 -> V_182 -> V_183 & V_184 )
return - V_185 ;
if ( V_170 -> V_182 -> V_183 & V_186 )
return - V_110 ;
F_102 ( V_29 , V_170 ) ;
if ( V_29 -> V_14 == V_15 )
F_16 ( V_43 , L_23 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_16 ( V_43 , L_24 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 , V_29 ) ;
return 0 ;
}
V_29 = F_91 ( sizeof( struct V_6 ) , V_153 ) ;
if ( V_29 == NULL )
return - V_63 ;
F_102 ( V_29 , V_170 ) ;
F_107 ( & V_29 -> V_78 , 0 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_180 = F_1 ( V_29 -> V_16 . V_17 . V_1 ) % V_8 -> V_13 ;
break;
case V_18 :
V_180 = F_3 ( V_29 -> V_16 . V_19 . V_20 ) % V_8 -> V_13 ;
break;
}
F_108 ( & V_29 -> V_156 , & V_8 -> V_22 [ V_179 ] ) ;
F_108 ( & V_29 -> V_155 , & V_8 -> V_12 [ V_180 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
F_16 ( V_43 , L_25 ,
V_29 -> V_16 . V_17 . V_1 , & V_29 -> V_92 ,
& V_29 -> V_25 , V_29 ) ;
break;
case V_18 :
F_16 ( V_43 , L_26 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 ,
& V_29 -> V_92 , & V_29 -> V_25 , V_29 ) ;
break;
}
return 0 ;
}
static int F_109 ( struct V_27 * V_28 , struct V_169 * V_170 )
{
struct V_62 * V_43 ;
struct V_65 * V_65 ;
if ( ! V_170 -> V_171 [ V_172 ] ||
! V_170 -> V_171 [ V_187 ] ||
! V_170 -> V_171 [ V_173 ] ||
! V_170 -> V_171 [ V_174 ] )
return - V_138 ;
switch ( F_73 ( V_170 -> V_171 [ V_172 ] ) ) {
case V_15 :
if ( ! V_170 -> V_171 [ V_175 ] ||
! V_170 -> V_171 [ V_176 ] )
return - V_138 ;
break;
case V_18 :
if ( ! V_170 -> V_171 [ V_177 ] ||
! V_170 -> V_171 [ V_178 ] )
return - V_138 ;
break;
default:
return - V_138 ;
}
V_65 = F_88 ( F_27 ( V_28 -> V_48 ) , V_170 -> V_171 ) ;
if ( F_55 ( V_65 ) )
return F_110 ( V_65 ) ;
V_43 = F_100 ( V_65 , F_73 ( V_170 -> V_171 [ V_187 ] ) ) ;
if ( V_43 == NULL ) {
F_111 ( V_65 ) ;
return - V_188 ;
}
F_111 ( V_65 ) ;
return F_106 ( V_43 , V_170 ) ;
}
static int F_112 ( struct V_27 * V_28 , struct V_169 * V_170 )
{
struct V_62 * V_43 ;
struct V_6 * V_29 ;
struct V_7 * V_8 ;
struct V_65 * V_65 ;
if ( ! V_170 -> V_171 [ V_172 ] ||
! V_170 -> V_171 [ V_187 ] )
return - V_138 ;
V_65 = F_88 ( F_27 ( V_28 -> V_48 ) , V_170 -> V_171 ) ;
if ( F_55 ( V_65 ) )
return F_110 ( V_65 ) ;
V_43 = F_100 ( V_65 , F_73 ( V_170 -> V_171 [ V_187 ] ) ) ;
if ( V_43 == NULL ) {
F_111 ( V_65 ) ;
return - V_188 ;
}
F_111 ( V_65 ) ;
V_8 = F_36 ( V_43 ) ;
switch ( F_73 ( V_170 -> V_171 [ V_172 ] ) ) {
case V_15 :
if ( ! V_170 -> V_171 [ V_175 ] )
return - V_138 ;
V_29 = F_6 ( V_8 , F_104 ( V_170 -> V_171 [ V_175 ] ) ) ;
break;
case V_18 :
if ( ! V_170 -> V_171 [ V_177 ] )
return - V_138 ;
V_29 = F_8 ( V_8 , F_104 ( V_170 -> V_171 [ V_177 ] ) ) ;
break;
default:
return - V_138 ;
}
if ( V_29 == NULL )
return - V_91 ;
if ( V_29 -> V_14 == V_15 )
F_16 ( V_43 , L_27 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_16 ( V_43 , L_28 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_82 , V_29 ) ;
F_94 ( & V_29 -> V_155 ) ;
F_94 ( & V_29 -> V_156 ) ;
F_95 ( V_29 , V_157 ) ;
return 0 ;
}
static int F_113 ( struct V_27 * V_28 , T_1 V_189 , T_1 V_190 ,
T_1 type , struct V_6 * V_29 )
{
void * V_191 ;
V_191 = F_114 ( V_28 , V_189 , V_190 , & V_192 , 0 ,
type ) ;
if ( V_191 == NULL )
goto V_193;
if ( F_87 ( V_28 , V_172 , V_29 -> V_14 ) ||
F_115 ( V_28 , V_173 , V_29 -> V_92 . V_26 ) ||
F_115 ( V_28 , V_174 , V_29 -> V_25 . V_26 ) )
goto V_148;
switch ( V_29 -> V_14 ) {
case V_15 :
if ( F_116 ( V_28 , V_175 , V_29 -> V_16 . V_17 . V_1 , V_194 ) ||
F_117 ( V_28 , V_176 , V_29 -> V_16 . V_17 . V_79 ) )
goto V_148;
break;
case V_18 :
if ( F_87 ( V_28 , V_177 , V_29 -> V_16 . V_19 . V_20 ) ||
F_87 ( V_28 , V_178 , V_29 -> V_16 . V_19 . V_82 ) )
goto V_148;
break;
}
F_118 ( V_28 , V_191 ) ;
return 0 ;
V_193:
V_148:
F_119 ( V_28 , V_191 ) ;
return - V_149 ;
}
static int F_120 ( struct V_27 * V_28 , struct V_169 * V_170 )
{
struct V_6 * V_29 = NULL ;
struct V_62 * V_43 ;
struct V_27 * V_195 ;
struct V_7 * V_8 ;
T_1 V_14 ;
struct V_65 * V_65 ;
int V_94 ;
if ( ! V_170 -> V_171 [ V_172 ] ||
! V_170 -> V_171 [ V_187 ] )
return - V_138 ;
V_14 = F_73 ( V_170 -> V_171 [ V_172 ] ) ;
switch ( V_14 ) {
case V_15 :
case V_18 :
break;
default:
return - V_138 ;
}
V_65 = F_88 ( F_27 ( V_28 -> V_48 ) , V_170 -> V_171 ) ;
if ( F_55 ( V_65 ) )
return F_110 ( V_65 ) ;
V_43 = F_100 ( V_65 , F_73 ( V_170 -> V_171 [ V_187 ] ) ) ;
if ( V_43 == NULL ) {
F_111 ( V_65 ) ;
return - V_188 ;
}
F_111 ( V_65 ) ;
V_8 = F_36 ( V_43 ) ;
F_65 () ;
if ( V_14 == V_15 &&
V_170 -> V_171 [ V_175 ] ) {
T_2 V_1 = F_104 ( V_170 -> V_171 [ V_175 ] ) ;
V_29 = F_6 ( V_8 , V_1 ) ;
} else if ( V_14 == V_18 &&
V_170 -> V_171 [ V_177 ] ) {
T_1 V_1 = F_73 ( V_170 -> V_171 [ V_177 ] ) ;
V_29 = F_8 ( V_8 , V_1 ) ;
} else if ( V_170 -> V_171 [ V_174 ] ) {
T_3 V_4 = F_103 ( V_170 -> V_171 [ V_174 ] ) ;
V_29 = F_9 ( V_8 , V_4 ) ;
}
if ( V_29 == NULL ) {
V_94 = - V_91 ;
goto V_196;
}
V_195 = F_121 ( V_197 , V_198 ) ;
if ( V_195 == NULL ) {
V_94 = - V_63 ;
goto V_196;
}
V_94 = F_113 ( V_195 , F_122 ( V_28 ) . V_199 ,
V_170 -> V_190 , V_170 -> V_182 -> V_200 , V_29 ) ;
if ( V_94 < 0 )
goto V_201;
F_66 () ;
return F_123 ( F_124 ( V_170 ) , V_195 , V_170 -> V_189 ) ;
V_201:
F_29 ( V_195 ) ;
V_196:
F_66 () ;
return V_94 ;
}
static int F_125 ( struct V_27 * V_28 ,
struct V_202 * V_203 )
{
struct V_7 * V_204 = (struct V_7 * ) V_203 -> args [ 2 ] , * V_8 ;
struct V_65 * V_65 = F_27 ( V_28 -> V_48 ) ;
struct V_134 * V_135 = F_77 ( V_65 , V_143 ) ;
unsigned long V_1 = V_203 -> args [ 1 ] ;
int V_152 , V_205 = V_203 -> args [ 0 ] , V_54 ;
struct V_6 * V_29 ;
if ( V_203 -> args [ 4 ] )
return 0 ;
F_101 (gtp, &gn->gtp_dev_list, list) {
if ( V_204 && V_204 != V_8 )
continue;
else
V_204 = NULL ;
for ( V_152 = V_205 ; V_152 < V_8 -> V_13 ; V_152 ++ ) {
F_7 (pctx, &gtp->tid_hash[i], hlist_tid) {
if ( V_1 && V_1 != V_29 -> V_16 . V_1 )
continue;
else
V_1 = 0 ;
V_54 = F_113 ( V_28 ,
F_122 ( V_203 -> V_28 ) . V_199 ,
V_203 -> V_206 -> V_207 ,
V_203 -> V_206 -> V_200 , V_29 ) ;
if ( V_54 < 0 ) {
V_203 -> args [ 0 ] = V_152 ;
V_203 -> args [ 1 ] = V_29 -> V_16 . V_1 ;
V_203 -> args [ 2 ] = ( unsigned long ) V_8 ;
goto V_208;
}
}
}
}
V_203 -> args [ 4 ] = 1 ;
V_208:
return V_28 -> V_61 ;
}
static int T_7 F_126 ( struct V_65 * V_65 )
{
struct V_134 * V_135 = F_77 ( V_65 , V_143 ) ;
F_127 ( & V_135 -> V_145 ) ;
return 0 ;
}
static void T_8 F_128 ( struct V_65 * V_65 )
{
struct V_134 * V_135 = F_77 ( V_65 , V_143 ) ;
struct V_7 * V_8 ;
F_129 ( V_144 ) ;
F_130 () ;
F_131 (gtp, &gn->gtp_dev_list, list)
F_80 ( V_8 -> V_43 , & V_144 ) ;
F_132 ( & V_144 ) ;
F_133 () ;
}
static int T_9 F_134 ( void )
{
int V_94 ;
F_135 ( & V_3 , sizeof( V_3 ) ) ;
V_94 = F_136 ( & V_209 ) ;
if ( V_94 < 0 )
goto V_210;
V_94 = F_137 ( & V_192 ) ;
if ( V_94 < 0 )
goto V_211;
V_94 = F_138 ( & V_212 ) ;
if ( V_94 < 0 )
goto V_213;
F_139 ( L_29 ,
sizeof( struct V_6 ) ) ;
return 0 ;
V_213:
F_140 ( & V_192 ) ;
V_211:
F_141 ( & V_209 ) ;
V_210:
F_142 ( L_30 ) ;
return V_94 ;
}
static void T_10 F_143 ( void )
{
F_144 ( & V_212 ) ;
F_140 ( & V_192 ) ;
F_141 ( & V_209 ) ;
F_139 ( L_31 ) ;
}
