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
V_32 = (struct V_31 * ) ( V_28 -> V_33 + V_30 + sizeof( struct V_31 ) ) ;
return V_32 -> V_34 != V_29 -> V_25 . V_26 ;
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
int V_41 = 0 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_40 = (struct V_39 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
if ( ( V_40 -> V_42 >> 5 ) != V_15 )
return 1 ;
if ( V_40 -> type != V_43 )
return 1 ;
F_15 () ;
V_29 = F_6 ( V_8 , F_16 ( V_40 -> V_1 ) ) ;
if ( ! V_29 ) {
F_17 ( V_8 -> V_44 , L_1 , V_28 ) ;
V_41 = - 1 ;
goto V_45;
}
if ( ! F_12 ( V_28 , V_29 , V_30 ) ) {
F_17 ( V_8 -> V_44 , L_2 ) ;
V_41 = - 1 ;
goto V_45;
}
F_18 () ;
return F_19 ( V_28 , V_30 , V_28 -> V_35 , V_37 ) ;
V_45:
F_18 () ;
return V_41 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_27 * V_28 ,
bool V_37 )
{
unsigned int V_30 = sizeof( struct V_38 ) +
sizeof( struct V_46 ) ;
struct V_46 * V_47 ;
struct V_6 * V_29 ;
int V_41 = 0 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_47 = (struct V_46 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
if ( ( V_47 -> V_42 >> 5 ) != V_18 )
return 1 ;
if ( V_47 -> type != V_43 )
return 1 ;
if ( V_47 -> V_42 & V_48 )
V_30 += 4 ;
if ( ! F_11 ( V_28 , V_30 ) )
return - 1 ;
V_47 = (struct V_46 * ) ( V_28 -> V_33 + sizeof( struct V_38 ) ) ;
F_15 () ;
V_29 = F_8 ( V_8 , F_21 ( V_47 -> V_1 ) ) ;
if ( ! V_29 ) {
F_17 ( V_8 -> V_44 , L_1 , V_28 ) ;
V_41 = - 1 ;
goto V_45;
}
if ( ! F_12 ( V_28 , V_29 , V_30 ) ) {
F_17 ( V_8 -> V_44 , L_2 ) ;
V_41 = - 1 ;
goto V_45;
}
F_18 () ;
return F_19 ( V_28 , V_30 , V_28 -> V_35 , V_37 ) ;
V_45:
F_18 () ;
return V_41 ;
}
static void F_22 ( struct V_7 * V_8 )
{
if ( V_8 -> V_49 && V_8 -> V_49 -> V_50 ) {
F_23 ( V_8 -> V_49 -> V_50 ) -> V_51 = 0 ;
F_24 ( V_8 -> V_49 -> V_50 , NULL ) ;
}
if ( V_8 -> V_52 && V_8 -> V_52 -> V_50 ) {
F_23 ( V_8 -> V_52 -> V_50 ) -> V_51 = 0 ;
F_24 ( V_8 -> V_52 -> V_50 , NULL ) ;
}
V_8 -> V_49 = NULL ;
V_8 -> V_52 = NULL ;
}
static void F_25 ( struct V_53 * V_50 )
{
struct V_7 * V_8 ;
V_8 = F_26 ( V_50 ) ;
if ( V_8 )
F_22 ( V_8 ) ;
}
static int F_27 ( struct V_53 * V_50 , struct V_27 * V_28 )
{
struct V_54 * V_55 ;
struct V_7 * V_8 ;
bool V_37 ;
int V_41 ;
V_8 = F_26 ( V_50 ) ;
if ( ! V_8 )
return 1 ;
F_17 ( V_8 -> V_44 , L_3 , V_50 ) ;
V_37 = ! F_28 ( V_8 -> V_56 , F_29 ( V_8 -> V_44 ) ) ;
switch ( F_23 ( V_50 ) -> V_51 ) {
case V_57 :
F_17 ( V_8 -> V_44 , L_4 ) ;
V_41 = F_14 ( V_8 , V_28 , V_37 ) ;
break;
case V_58 :
F_17 ( V_8 -> V_44 , L_5 ) ;
V_41 = F_20 ( V_8 , V_28 , V_37 ) ;
break;
default:
V_41 = - 1 ;
}
switch ( V_41 ) {
case 1 :
F_17 ( V_8 -> V_44 , L_6 ) ;
return 1 ;
case 0 :
F_17 ( V_8 -> V_44 , L_7 ) ;
break;
case - 1 :
F_17 ( V_8 -> V_44 , L_8 ) ;
F_30 ( V_28 ) ;
return 0 ;
}
F_31 ( V_28 ) ;
V_28 -> V_44 = V_8 -> V_44 ;
V_55 = F_32 ( V_8 -> V_44 -> V_59 ) ;
F_33 ( & V_55 -> V_60 ) ;
V_55 -> V_61 ++ ;
V_55 -> V_62 += V_28 -> V_63 ;
F_34 ( & V_55 -> V_60 ) ;
F_35 ( V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_64 * V_44 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
V_8 -> V_44 = V_44 ;
V_44 -> V_59 = F_38 ( struct V_54 ) ;
if ( ! V_44 -> V_59 )
return - V_65 ;
return 0 ;
}
static void F_39 ( struct V_64 * V_44 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
F_22 ( V_8 ) ;
F_40 ( V_44 -> V_59 ) ;
}
static struct V_66 * F_41 ( struct V_56 * V_56 , struct V_67 * V_68 ,
const struct V_53 * V_50 , T_3 V_69 )
{
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_70 = V_50 -> V_71 ;
V_68 -> V_69 = V_69 ;
V_68 -> V_34 = F_42 ( V_50 ) -> V_72 ;
V_68 -> V_73 = F_43 ( V_50 ) ;
V_68 -> V_74 = V_50 -> V_75 ;
return F_44 ( V_56 , V_68 ) ;
}
static inline void F_45 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_76 = V_28 -> V_63 ;
struct V_39 * V_40 ;
V_40 = (struct V_39 * ) F_46 ( V_28 , sizeof( * V_40 ) ) ;
V_40 -> V_42 = 0x1e ;
V_40 -> type = V_43 ;
V_40 -> V_77 = F_47 ( V_76 ) ;
V_40 -> V_78 = F_47 ( ( F_48 ( & V_29 -> V_79 ) - 1 ) % 0xffff ) ;
V_40 -> V_80 = F_47 ( V_29 -> V_16 . V_17 . V_80 ) ;
V_40 -> V_81 = 0xff ;
V_40 -> V_82 [ 0 ] = V_40 -> V_82 [ 1 ] = V_40 -> V_82 [ 2 ] = 0xff ;
V_40 -> V_1 = F_49 ( V_29 -> V_16 . V_17 . V_1 ) ;
}
static inline void F_50 ( struct V_27 * V_28 , struct V_6 * V_29 )
{
int V_76 = V_28 -> V_63 ;
struct V_46 * V_47 ;
V_47 = (struct V_46 * ) F_46 ( V_28 , sizeof( * V_47 ) ) ;
V_47 -> V_42 = 0x38 ;
V_47 -> type = V_43 ;
V_47 -> V_77 = F_47 ( V_76 ) ;
V_47 -> V_1 = F_51 ( V_29 -> V_16 . V_19 . V_83 ) ;
}
static void F_52 ( struct V_27 * V_28 , struct V_84 * V_85 )
{
switch ( V_85 -> V_29 -> V_14 ) {
case V_15 :
V_85 -> V_86 = F_47 ( V_87 ) ;
F_45 ( V_28 , V_85 -> V_29 ) ;
break;
case V_18 :
V_85 -> V_86 = F_47 ( V_88 ) ;
F_50 ( V_28 , V_85 -> V_29 ) ;
break;
}
}
static inline void F_53 ( struct V_84 * V_85 ,
struct V_53 * V_50 , struct V_31 * V_32 ,
struct V_6 * V_29 , struct V_66 * V_89 ,
struct V_67 * V_68 ,
struct V_64 * V_44 )
{
V_85 -> V_50 = V_50 ;
V_85 -> V_32 = V_32 ;
V_85 -> V_29 = V_29 ;
V_85 -> V_89 = V_89 ;
V_85 -> V_68 = * V_68 ;
V_85 -> V_44 = V_44 ;
}
static int F_54 ( struct V_27 * V_28 , struct V_64 * V_44 ,
struct V_84 * V_85 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
struct V_6 * V_29 ;
struct V_66 * V_89 ;
struct V_67 V_68 ;
struct V_31 * V_32 ;
struct V_53 * V_50 ;
T_4 V_90 ;
int V_91 ;
V_32 = F_55 ( V_28 ) ;
V_29 = F_9 ( V_8 , V_32 -> V_69 ) ;
if ( ! V_29 ) {
F_17 ( V_44 , L_9 ,
& V_32 -> V_69 ) ;
return - V_92 ;
}
F_17 ( V_44 , L_10 , V_29 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
if ( V_8 -> V_49 )
V_50 = V_8 -> V_49 -> V_50 ;
else
V_50 = NULL ;
break;
case V_18 :
if ( V_8 -> V_52 )
V_50 = V_8 -> V_52 -> V_50 ;
else
V_50 = NULL ;
break;
default:
return - V_92 ;
}
if ( ! V_50 ) {
F_17 ( V_44 , L_11 ) ;
return - V_92 ;
}
V_89 = F_41 ( F_56 ( V_50 ) , & V_68 , V_8 -> V_49 -> V_50 ,
V_29 -> V_93 . V_26 ) ;
if ( F_57 ( V_89 ) ) {
F_17 ( V_44 , L_12 ,
& V_29 -> V_93 . V_26 ) ;
V_44 -> V_55 . V_94 ++ ;
goto V_95;
}
if ( V_89 -> V_96 . V_44 == V_44 ) {
F_17 ( V_44 , L_13 ,
& V_29 -> V_93 . V_26 ) ;
V_44 -> V_55 . V_97 ++ ;
goto V_98;
}
F_58 ( V_28 ) ;
V_90 = V_32 -> V_99 ;
if ( V_90 ) {
V_91 = F_59 ( & V_89 -> V_96 ) - V_44 -> V_100 -
sizeof( struct V_31 ) - sizeof( struct V_38 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_91 -= sizeof( struct V_39 ) ;
break;
case V_18 :
V_91 -= sizeof( struct V_46 ) ;
break;
}
} else {
V_91 = F_59 ( & V_89 -> V_96 ) ;
}
V_89 -> V_96 . V_101 -> V_102 ( & V_89 -> V_96 , NULL , V_28 , V_91 ) ;
if ( ! F_60 ( V_28 ) && ( V_32 -> V_99 & F_47 ( V_103 ) ) &&
V_91 < F_13 ( V_32 -> V_104 ) ) {
F_17 ( V_44 , L_14 ) ;
memset ( F_61 ( V_28 ) , 0 , sizeof( * F_61 ( V_28 ) ) ) ;
F_62 ( V_28 , V_105 , V_106 ,
F_51 ( V_91 ) ) ;
goto V_98;
}
F_53 ( V_85 , V_50 , V_32 , V_29 , V_89 , & V_68 , V_44 ) ;
F_52 ( V_28 , V_85 ) ;
return 0 ;
V_98:
F_63 ( V_89 ) ;
V_95:
return - V_107 ;
}
static T_5 F_64 ( struct V_27 * V_28 , struct V_64 * V_44 )
{
unsigned int V_108 = F_13 ( V_28 -> V_35 ) ;
struct V_84 V_85 ;
int V_95 ;
if ( F_65 ( V_28 , V_44 -> V_109 ) )
goto V_110;
F_66 ( V_28 ) ;
F_15 () ;
switch ( V_108 ) {
case V_36 :
V_95 = F_54 ( V_28 , V_44 , & V_85 ) ;
break;
default:
V_95 = - V_111 ;
break;
}
F_18 () ;
if ( V_95 < 0 )
goto V_110;
switch ( V_108 ) {
case V_36 :
F_17 ( V_85 . V_44 , L_15 ,
& V_85 . V_32 -> V_34 , & V_85 . V_32 -> V_69 ) ;
F_67 ( V_85 . V_89 , V_85 . V_50 , V_28 ,
V_85 . V_68 . V_34 , V_85 . V_68 . V_69 ,
V_85 . V_32 -> V_112 ,
F_68 ( & V_85 . V_89 -> V_96 ) ,
F_47 ( V_103 ) ,
V_85 . V_86 , V_85 . V_86 ,
true , false ) ;
break;
}
return V_113 ;
V_110:
V_44 -> V_55 . V_114 ++ ;
F_69 ( V_28 ) ;
return V_113 ;
}
static void F_70 ( struct V_64 * V_44 )
{
V_44 -> V_115 = & V_116 ;
V_44 -> V_117 = V_118 ;
V_44 -> V_100 = 0 ;
V_44 -> V_119 = 0 ;
V_44 -> type = V_120 ;
V_44 -> V_42 = V_121 | V_122 | V_123 ;
V_44 -> V_124 |= V_125 ;
V_44 -> V_126 |= V_127 ;
F_71 ( V_44 ) ;
V_44 -> V_109 = V_128 +
sizeof( struct V_31 ) +
sizeof( struct V_38 ) +
sizeof( struct V_39 ) ;
}
static int F_72 ( struct V_56 * V_129 , struct V_64 * V_44 ,
struct V_130 * V_131 [] , struct V_130 * V_33 [] )
{
int V_132 , V_95 , V_133 , V_134 ;
struct V_7 * V_8 ;
struct V_135 * V_136 ;
if ( ! V_33 [ V_137 ] || ! V_33 [ V_138 ] )
return - V_139 ;
V_8 = F_37 ( V_44 ) ;
V_133 = F_73 ( V_33 [ V_137 ] ) ;
V_134 = F_73 ( V_33 [ V_138 ] ) ;
V_95 = F_74 ( V_44 , V_8 , V_133 , V_134 , V_129 ) ;
if ( V_95 < 0 )
goto V_140;
if ( ! V_33 [ V_141 ] )
V_132 = 1024 ;
else
V_132 = F_73 ( V_33 [ V_141 ] ) ;
V_95 = F_75 ( V_8 , V_132 ) ;
if ( V_95 < 0 )
goto V_142;
V_95 = F_76 ( V_44 ) ;
if ( V_95 < 0 ) {
F_17 ( V_44 , L_16 , V_95 ) ;
goto V_143;
}
V_136 = F_77 ( F_29 ( V_44 ) , V_144 ) ;
F_78 ( & V_8 -> V_145 , & V_136 -> V_146 ) ;
F_17 ( V_44 , L_17 ) ;
return 0 ;
V_143:
F_79 ( V_8 ) ;
V_142:
F_22 ( V_8 ) ;
V_140:
return V_95 ;
}
static void F_80 ( struct V_64 * V_44 , struct V_147 * V_10 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
F_22 ( V_8 ) ;
F_79 ( V_8 ) ;
F_81 ( & V_8 -> V_145 ) ;
F_82 ( V_44 , V_10 ) ;
}
static int F_83 ( struct V_130 * V_131 [] , struct V_130 * V_33 [] )
{
if ( ! V_33 )
return - V_139 ;
return 0 ;
}
static T_6 F_84 ( const struct V_64 * V_44 )
{
return F_85 ( sizeof( V_148 ) ) ;
}
static int F_86 ( struct V_27 * V_28 , const struct V_64 * V_44 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
if ( F_87 ( V_28 , V_141 , V_8 -> V_13 ) )
goto V_149;
return 0 ;
V_149:
return - V_150 ;
}
static struct V_56 * F_88 ( struct V_56 * V_129 , struct V_130 * V_131 [] )
{
struct V_56 * V_56 ;
if ( V_131 [ V_151 ] )
V_56 = F_89 ( F_73 ( V_131 [ V_151 ] ) ) ;
else
V_56 = F_90 ( V_129 ) ;
return V_56 ;
}
static int F_75 ( struct V_7 * V_8 , int V_152 )
{
int V_153 ;
V_8 -> V_22 = F_91 ( sizeof( struct V_9 ) * V_152 , V_154 ) ;
if ( V_8 -> V_22 == NULL )
return - V_65 ;
V_8 -> V_12 = F_91 ( sizeof( struct V_9 ) * V_152 , V_154 ) ;
if ( V_8 -> V_12 == NULL )
goto V_155;
V_8 -> V_13 = V_152 ;
for ( V_153 = 0 ; V_153 < V_152 ; V_153 ++ ) {
F_92 ( & V_8 -> V_22 [ V_153 ] ) ;
F_92 ( & V_8 -> V_12 [ V_153 ] ) ;
}
return 0 ;
V_155:
F_93 ( V_8 -> V_22 ) ;
return - V_65 ;
}
static void F_79 ( struct V_7 * V_8 )
{
struct V_6 * V_29 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_8 -> V_13 ; V_153 ++ ) {
F_7 (pctx, &gtp->tid_hash[i], hlist_tid) {
F_94 ( & V_29 -> V_156 ) ;
F_94 ( & V_29 -> V_157 ) ;
F_95 ( V_29 , V_158 ) ;
}
}
F_96 () ;
F_93 ( V_8 -> V_22 ) ;
F_93 ( V_8 -> V_12 ) ;
}
static int F_74 ( struct V_64 * V_44 , struct V_7 * V_8 ,
int V_159 , int V_160 , struct V_56 * V_129 )
{
struct V_161 V_162 = { NULL } ;
struct V_163 * V_49 , * V_52 ;
int V_95 ;
F_17 ( V_44 , L_18 , V_159 , V_160 ) ;
V_49 = F_97 ( V_159 , & V_95 ) ;
if ( V_49 == NULL ) {
F_17 ( V_44 , L_19 , V_159 ) ;
return - V_92 ;
}
if ( V_49 -> V_50 -> V_75 != V_164 ) {
F_17 ( V_44 , L_20 , V_159 ) ;
V_95 = - V_139 ;
goto V_155;
}
V_52 = F_97 ( V_160 , & V_95 ) ;
if ( V_52 == NULL ) {
F_17 ( V_44 , L_21 , V_160 ) ;
V_95 = - V_92 ;
goto V_155;
}
if ( V_52 -> V_50 -> V_75 != V_164 ) {
F_17 ( V_44 , L_20 , V_160 ) ;
V_95 = - V_139 ;
goto V_165;
}
F_17 ( V_44 , L_22 , V_49 , V_52 ) ;
V_8 -> V_49 = V_49 ;
V_8 -> V_52 = V_52 ;
V_8 -> V_56 = V_129 ;
V_162 . V_166 = V_8 ;
V_162 . V_167 = F_27 ;
V_162 . V_168 = F_25 ;
V_162 . V_51 = V_57 ;
F_98 ( F_56 ( V_8 -> V_49 -> V_50 ) , V_8 -> V_49 , & V_162 ) ;
V_162 . V_51 = V_58 ;
F_98 ( F_56 ( V_8 -> V_52 -> V_50 ) , V_8 -> V_52 , & V_162 ) ;
V_95 = 0 ;
V_165:
F_99 ( V_52 ) ;
V_155:
F_99 ( V_49 ) ;
return V_95 ;
}
static struct V_64 * F_100 ( struct V_56 * V_56 , int V_169 )
{
struct V_135 * V_136 = F_77 ( V_56 , V_144 ) ;
struct V_7 * V_8 ;
F_101 (gtp, &gn->gtp_dev_list, list) {
if ( V_169 == V_8 -> V_44 -> V_169 )
return V_8 -> V_44 ;
}
return NULL ;
}
static void F_102 ( struct V_6 * V_29 , struct V_170 * V_171 )
{
V_29 -> V_14 = F_73 ( V_171 -> V_172 [ V_173 ] ) ;
V_29 -> V_23 = V_24 ;
V_29 -> V_93 . V_26 =
F_103 ( V_171 -> V_172 [ V_174 ] ) ;
V_29 -> V_25 . V_26 =
F_103 ( V_171 -> V_172 [ V_175 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_29 -> V_16 . V_17 . V_1 = F_104 ( V_171 -> V_172 [ V_176 ] ) ;
V_29 -> V_16 . V_17 . V_80 = F_105 ( V_171 -> V_172 [ V_177 ] ) ;
break;
case V_18 :
V_29 -> V_16 . V_19 . V_20 = F_73 ( V_171 -> V_172 [ V_178 ] ) ;
V_29 -> V_16 . V_19 . V_83 = F_73 ( V_171 -> V_172 [ V_179 ] ) ;
break;
default:
break;
}
}
static int F_106 ( struct V_64 * V_44 , struct V_170 * V_171 )
{
struct V_7 * V_8 = F_37 ( V_44 ) ;
T_1 V_180 , V_181 = 0 ;
struct V_6 * V_29 ;
bool V_182 = false ;
T_3 V_21 ;
V_21 = F_103 ( V_171 -> V_172 [ V_175 ] ) ;
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
return - V_111 ;
F_102 ( V_29 , V_171 ) ;
if ( V_29 -> V_14 == V_15 )
F_17 ( V_44 , L_23 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_17 ( V_44 , L_24 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_83 , V_29 ) ;
return 0 ;
}
V_29 = F_91 ( sizeof( struct V_6 ) , V_154 ) ;
if ( V_29 == NULL )
return - V_65 ;
F_102 ( V_29 , V_171 ) ;
F_107 ( & V_29 -> V_79 , 0 ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
V_181 = F_1 ( V_29 -> V_16 . V_17 . V_1 ) % V_8 -> V_13 ;
break;
case V_18 :
V_181 = F_3 ( V_29 -> V_16 . V_19 . V_20 ) % V_8 -> V_13 ;
break;
}
F_108 ( & V_29 -> V_157 , & V_8 -> V_22 [ V_180 ] ) ;
F_108 ( & V_29 -> V_156 , & V_8 -> V_12 [ V_181 ] ) ;
switch ( V_29 -> V_14 ) {
case V_15 :
F_17 ( V_44 , L_25 ,
V_29 -> V_16 . V_17 . V_1 , & V_29 -> V_93 ,
& V_29 -> V_25 , V_29 ) ;
break;
case V_18 :
F_17 ( V_44 , L_26 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_83 ,
& V_29 -> V_93 , & V_29 -> V_25 , V_29 ) ;
break;
}
return 0 ;
}
static int F_109 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
struct V_64 * V_44 ;
struct V_56 * V_56 ;
if ( ! V_171 -> V_172 [ V_173 ] ||
! V_171 -> V_172 [ V_188 ] ||
! V_171 -> V_172 [ V_174 ] ||
! V_171 -> V_172 [ V_175 ] )
return - V_139 ;
switch ( F_73 ( V_171 -> V_172 [ V_173 ] ) ) {
case V_15 :
if ( ! V_171 -> V_172 [ V_176 ] ||
! V_171 -> V_172 [ V_177 ] )
return - V_139 ;
break;
case V_18 :
if ( ! V_171 -> V_172 [ V_178 ] ||
! V_171 -> V_172 [ V_179 ] )
return - V_139 ;
break;
default:
return - V_139 ;
}
V_56 = F_88 ( F_56 ( V_28 -> V_50 ) , V_171 -> V_172 ) ;
if ( F_57 ( V_56 ) )
return F_110 ( V_56 ) ;
V_44 = F_100 ( V_56 , F_73 ( V_171 -> V_172 [ V_188 ] ) ) ;
if ( V_44 == NULL ) {
F_111 ( V_56 ) ;
return - V_189 ;
}
F_111 ( V_56 ) ;
return F_106 ( V_44 , V_171 ) ;
}
static int F_112 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
struct V_64 * V_44 ;
struct V_6 * V_29 ;
struct V_7 * V_8 ;
struct V_56 * V_56 ;
if ( ! V_171 -> V_172 [ V_173 ] ||
! V_171 -> V_172 [ V_188 ] )
return - V_139 ;
V_56 = F_88 ( F_56 ( V_28 -> V_50 ) , V_171 -> V_172 ) ;
if ( F_57 ( V_56 ) )
return F_110 ( V_56 ) ;
V_44 = F_100 ( V_56 , F_73 ( V_171 -> V_172 [ V_188 ] ) ) ;
if ( V_44 == NULL ) {
F_111 ( V_56 ) ;
return - V_189 ;
}
F_111 ( V_56 ) ;
V_8 = F_37 ( V_44 ) ;
switch ( F_73 ( V_171 -> V_172 [ V_173 ] ) ) {
case V_15 :
if ( ! V_171 -> V_172 [ V_176 ] )
return - V_139 ;
V_29 = F_6 ( V_8 , F_104 ( V_171 -> V_172 [ V_176 ] ) ) ;
break;
case V_18 :
if ( ! V_171 -> V_172 [ V_178 ] )
return - V_139 ;
V_29 = F_8 ( V_8 , F_104 ( V_171 -> V_172 [ V_178 ] ) ) ;
break;
default:
return - V_139 ;
}
if ( V_29 == NULL )
return - V_92 ;
if ( V_29 -> V_14 == V_15 )
F_17 ( V_44 , L_27 ,
V_29 -> V_16 . V_17 . V_1 , V_29 ) ;
else if ( V_29 -> V_14 == V_18 )
F_17 ( V_44 , L_28 ,
V_29 -> V_16 . V_19 . V_20 , V_29 -> V_16 . V_19 . V_83 , V_29 ) ;
F_94 ( & V_29 -> V_156 ) ;
F_94 ( & V_29 -> V_157 ) ;
F_95 ( V_29 , V_158 ) ;
return 0 ;
}
static int F_113 ( struct V_27 * V_28 , T_1 V_190 , T_1 V_191 ,
T_1 type , struct V_6 * V_29 )
{
void * V_192 ;
V_192 = F_114 ( V_28 , V_190 , V_191 , & V_193 , 0 ,
type ) ;
if ( V_192 == NULL )
goto V_194;
if ( F_87 ( V_28 , V_173 , V_29 -> V_14 ) ||
F_115 ( V_28 , V_174 , V_29 -> V_93 . V_26 ) ||
F_115 ( V_28 , V_175 , V_29 -> V_25 . V_26 ) )
goto V_149;
switch ( V_29 -> V_14 ) {
case V_15 :
if ( F_116 ( V_28 , V_176 , V_29 -> V_16 . V_17 . V_1 , V_195 ) ||
F_117 ( V_28 , V_177 , V_29 -> V_16 . V_17 . V_80 ) )
goto V_149;
break;
case V_18 :
if ( F_87 ( V_28 , V_178 , V_29 -> V_16 . V_19 . V_20 ) ||
F_87 ( V_28 , V_179 , V_29 -> V_16 . V_19 . V_83 ) )
goto V_149;
break;
}
F_118 ( V_28 , V_192 ) ;
return 0 ;
V_194:
V_149:
F_119 ( V_28 , V_192 ) ;
return - V_150 ;
}
static int F_120 ( struct V_27 * V_28 , struct V_170 * V_171 )
{
struct V_6 * V_29 = NULL ;
struct V_64 * V_44 ;
struct V_27 * V_196 ;
struct V_7 * V_8 ;
T_1 V_14 ;
struct V_56 * V_56 ;
int V_95 ;
if ( ! V_171 -> V_172 [ V_173 ] ||
! V_171 -> V_172 [ V_188 ] )
return - V_139 ;
V_14 = F_73 ( V_171 -> V_172 [ V_173 ] ) ;
switch ( V_14 ) {
case V_15 :
case V_18 :
break;
default:
return - V_139 ;
}
V_56 = F_88 ( F_56 ( V_28 -> V_50 ) , V_171 -> V_172 ) ;
if ( F_57 ( V_56 ) )
return F_110 ( V_56 ) ;
V_44 = F_100 ( V_56 , F_73 ( V_171 -> V_172 [ V_188 ] ) ) ;
if ( V_44 == NULL ) {
F_111 ( V_56 ) ;
return - V_189 ;
}
F_111 ( V_56 ) ;
V_8 = F_37 ( V_44 ) ;
F_15 () ;
if ( V_14 == V_15 &&
V_171 -> V_172 [ V_176 ] ) {
T_2 V_1 = F_104 ( V_171 -> V_172 [ V_176 ] ) ;
V_29 = F_6 ( V_8 , V_1 ) ;
} else if ( V_14 == V_18 &&
V_171 -> V_172 [ V_178 ] ) {
T_1 V_1 = F_73 ( V_171 -> V_172 [ V_178 ] ) ;
V_29 = F_8 ( V_8 , V_1 ) ;
} else if ( V_171 -> V_172 [ V_175 ] ) {
T_3 V_4 = F_103 ( V_171 -> V_172 [ V_175 ] ) ;
V_29 = F_9 ( V_8 , V_4 ) ;
}
if ( V_29 == NULL ) {
V_95 = - V_92 ;
goto V_197;
}
V_196 = F_121 ( V_198 , V_199 ) ;
if ( V_196 == NULL ) {
V_95 = - V_65 ;
goto V_197;
}
V_95 = F_113 ( V_196 , F_122 ( V_28 ) . V_200 ,
V_171 -> V_191 , V_171 -> V_183 -> V_201 , V_29 ) ;
if ( V_95 < 0 )
goto V_202;
F_18 () ;
return F_123 ( F_124 ( V_171 ) , V_196 , V_171 -> V_190 ) ;
V_202:
F_30 ( V_196 ) ;
V_197:
F_18 () ;
return V_95 ;
}
static int F_125 ( struct V_27 * V_28 ,
struct V_203 * V_204 )
{
struct V_7 * V_205 = (struct V_7 * ) V_204 -> args [ 2 ] , * V_8 ;
struct V_56 * V_56 = F_56 ( V_28 -> V_50 ) ;
struct V_135 * V_136 = F_77 ( V_56 , V_144 ) ;
unsigned long V_1 = V_204 -> args [ 1 ] ;
int V_153 , V_206 = V_204 -> args [ 0 ] , V_41 ;
struct V_6 * V_29 ;
if ( V_204 -> args [ 4 ] )
return 0 ;
F_101 (gtp, &gn->gtp_dev_list, list) {
if ( V_205 && V_205 != V_8 )
continue;
else
V_205 = NULL ;
for ( V_153 = V_206 ; V_153 < V_8 -> V_13 ; V_153 ++ ) {
F_7 (pctx, &gtp->tid_hash[i], hlist_tid) {
if ( V_1 && V_1 != V_29 -> V_16 . V_1 )
continue;
else
V_1 = 0 ;
V_41 = F_113 ( V_28 ,
F_122 ( V_204 -> V_28 ) . V_200 ,
V_204 -> V_207 -> V_208 ,
V_204 -> V_207 -> V_201 , V_29 ) ;
if ( V_41 < 0 ) {
V_204 -> args [ 0 ] = V_153 ;
V_204 -> args [ 1 ] = V_29 -> V_16 . V_1 ;
V_204 -> args [ 2 ] = ( unsigned long ) V_8 ;
goto V_209;
}
}
}
}
V_204 -> args [ 4 ] = 1 ;
V_209:
return V_28 -> V_63 ;
}
static int T_7 F_126 ( struct V_56 * V_56 )
{
struct V_135 * V_136 = F_77 ( V_56 , V_144 ) ;
F_127 ( & V_136 -> V_146 ) ;
return 0 ;
}
static void T_8 F_128 ( struct V_56 * V_56 )
{
struct V_135 * V_136 = F_77 ( V_56 , V_144 ) ;
struct V_7 * V_8 ;
F_129 ( V_145 ) ;
F_130 () ;
F_131 (gtp, &gn->gtp_dev_list, list)
F_80 ( V_8 -> V_44 , & V_145 ) ;
F_132 ( & V_145 ) ;
F_133 () ;
}
static int T_9 F_134 ( void )
{
int V_95 ;
F_135 ( & V_3 , sizeof( V_3 ) ) ;
V_95 = F_136 ( & V_210 ) ;
if ( V_95 < 0 )
goto V_211;
V_95 = F_137 ( & V_193 , V_212 ) ;
if ( V_95 < 0 )
goto V_213;
V_95 = F_138 ( & V_214 ) ;
if ( V_95 < 0 )
goto V_215;
F_139 ( L_29 ,
sizeof( struct V_6 ) ) ;
return 0 ;
V_215:
F_140 ( & V_193 ) ;
V_213:
F_141 ( & V_210 ) ;
V_211:
F_142 ( L_30 ) ;
return V_95 ;
}
static void T_10 F_143 ( void )
{
F_144 ( & V_214 ) ;
F_140 ( & V_193 ) ;
F_141 ( & V_210 ) ;
F_139 ( L_31 ) ;
}
