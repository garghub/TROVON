static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = 0 ;
V_4 . V_8 = V_2 -> V_9 ;
V_4 . V_10 = V_11
| V_12 ;
return F_2 ( V_2 -> V_13 , & V_4 ,
V_14 | V_15 |
V_16 | V_17 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
enum V_18 V_19 =
V_14 | V_20 | V_21 | V_22 |
V_23 | V_24 | V_25 ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = V_26 ;
V_4 . V_27 = F_4 ( V_2 -> V_27 , V_2 -> V_28 ) ;
V_4 . V_29 . type = V_30 ;
F_5 ( & V_4 . V_29 , V_2 -> V_9 ) ;
F_6 ( & V_4 . V_29 , NULL , 0 , 0 , 1 , 0 ) ;
F_7 ( & V_4 . V_29 , V_2 -> V_31 ) ;
memcpy ( & V_4 . V_29 . V_32 . V_33 , V_2 -> V_34 ,
sizeof( V_2 -> V_34 ) ) ;
V_4 . V_35 = V_2 -> V_36 ;
V_4 . V_37 = V_2 -> V_38 ;
V_4 . V_39 = 1 ;
V_4 . V_40 = V_41 ;
return F_2 ( V_2 -> V_13 , & V_4 , V_19 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = V_42 ;
V_4 . V_43 = V_44 ;
V_4 . V_45 = V_46 ;
V_4 . V_47 = V_48 ;
V_4 . V_49 = V_2 -> V_50 ;
V_4 . V_51 = 1 ;
return F_2 ( V_2 -> V_13 , & V_4 ,
V_14 | V_52 | V_53 |
V_54 | V_55 |
V_56 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = V_57 ;
return F_2 ( V_2 -> V_13 , & V_4 , V_14 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_58 * V_59 =
F_11 ( V_2 , struct V_58 , V_2 [ 0 ] ) ;
int V_60 = 0 ;
V_60 = F_1 ( V_2 ) ;
if ( V_60 )
goto V_61;
V_60 = F_3 ( V_2 ) ;
if ( V_60 )
goto V_61;
F_12 ( V_2 ) ;
V_60 = F_13 ( V_2 -> V_62 -> V_63 ,
V_64 ) ;
if ( V_60 )
goto V_61;
V_60 = F_14 ( V_2 ) ;
if ( V_60 )
goto V_61;
F_12 ( V_2 ) ;
if ( V_59 -> V_65 == V_66 ) {
V_60 = F_8 ( V_2 ) ;
if ( V_60 )
goto V_61;
F_12 ( V_2 ) ;
}
V_61:
return V_60 ;
}
static void F_15 ( struct V_67 * V_68 )
{
struct V_69 * V_62 = F_11 (
V_68 , struct V_69 , V_70 ) ;
T_1 V_71 ;
F_16 (port_idx, &smcibdev->port_event_mask, SMC_MAX_PORTS) {
F_17 ( V_62 , V_71 + 1 ) ;
F_18 ( V_71 , & V_62 -> V_72 ) ;
}
}
static void F_19 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_69 * V_62 ;
T_1 V_71 ;
V_62 = F_11 ( V_74 , struct V_69 , V_77 ) ;
switch ( V_76 -> V_78 ) {
case V_79 :
V_71 = V_76 -> V_80 . V_8 - 1 ;
F_20 ( V_71 , & V_62 -> V_72 ) ;
F_21 ( & V_62 -> V_70 ) ;
case V_81 :
break;
case V_82 :
V_71 = V_76 -> V_80 . V_8 - 1 ;
F_20 ( V_71 , & V_62 -> V_72 ) ;
F_21 ( & V_62 -> V_70 ) ;
break;
default:
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_60 ;
V_2 -> V_83 = F_25 ( V_2 -> V_62 -> V_84 , 0 ) ;
V_60 = F_26 ( V_2 -> V_83 ) ;
if ( F_27 ( V_2 -> V_83 ) )
V_2 -> V_83 = NULL ;
return V_60 ;
}
static void F_28 ( struct V_75 * V_76 , void * V_85 )
{
switch ( V_76 -> V_78 ) {
case V_81 :
case V_86 :
case V_79 :
case V_87 :
break;
default:
break;
}
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_88 V_4 = {
. V_77 = F_28 ,
. V_89 = V_2 ,
. V_90 = V_2 -> V_62 -> V_91 ,
. V_92 = V_2 -> V_62 -> V_63 ,
. V_93 = NULL ,
. V_94 = {
. V_95 = V_96 * 3 ,
. V_97 = V_96 * 3 ,
. V_98 = V_99 ,
. V_100 = 1 ,
} ,
. V_101 = V_102 ,
. V_103 = V_104 ,
} ;
int V_60 ;
V_2 -> V_13 = F_32 ( V_2 -> V_83 , & V_4 ) ;
V_60 = F_26 ( V_2 -> V_13 ) ;
if ( F_27 ( V_2 -> V_13 ) )
V_2 -> V_13 = NULL ;
else
F_12 ( V_2 ) ;
return V_60 ;
}
void F_33 ( struct V_105 * V_106 )
{
F_34 ( V_106 ) ;
}
static int F_35 ( struct V_107 * V_108 )
{
unsigned int V_109 = 0 ;
int V_110 ;
V_110 = F_36 ( V_108 -> V_111 [ V_112 ] ,
V_108 -> V_113 [ V_112 ] . V_114 ,
V_108 -> V_113 [ V_112 ] . V_115 ,
& V_109 , V_116 ) ;
return V_110 ;
}
int F_37 ( struct V_117 * V_118 , int V_119 ,
struct V_107 * V_108 )
{
if ( V_108 -> V_111 [ V_112 ] )
return 0 ;
V_108 -> V_111 [ V_112 ] =
F_38 ( V_118 , V_120 , 1 << V_108 -> V_121 ) ;
if ( F_27 ( V_108 -> V_111 [ V_112 ] ) ) {
int V_60 ;
V_60 = F_39 ( V_108 -> V_111 [ V_112 ] ) ;
V_108 -> V_111 [ V_112 ] = NULL ;
return V_60 ;
}
if ( F_35 ( V_108 ) != 1 )
return - V_122 ;
return 0 ;
}
void F_40 ( struct V_69 * V_62 ,
struct V_107 * V_108 ,
enum V_123 V_124 )
{
struct V_125 * V_126 ;
unsigned int V_127 ;
F_41 (buf_slot->sgt[SMC_SINGLE_LINK].sgl, sg,
buf_slot->sgt[SMC_SINGLE_LINK].nents, i) {
if ( ! F_42 ( V_126 ) )
break;
F_43 ( V_62 -> V_84 ,
F_44 ( V_126 ) ,
F_42 ( V_126 ) ,
V_124 ) ;
}
}
void F_45 ( struct V_69 * V_62 ,
struct V_107 * V_108 ,
enum V_123 V_124 )
{
struct V_125 * V_126 ;
unsigned int V_127 ;
F_41 (buf_slot->sgt[SMC_SINGLE_LINK].sgl, sg,
buf_slot->sgt[SMC_SINGLE_LINK].nents, i) {
if ( ! F_42 ( V_126 ) )
break;
F_46 ( V_62 -> V_84 ,
F_44 ( V_126 ) ,
F_42 ( V_126 ) ,
V_124 ) ;
}
}
int F_47 ( struct V_69 * V_62 ,
struct V_107 * V_108 ,
enum V_123 V_124 )
{
int V_128 ;
V_128 = F_48 ( V_62 -> V_84 ,
V_108 -> V_113 [ V_112 ] . V_114 ,
V_108 -> V_113 [ V_112 ] . V_115 ,
V_124 ) ;
if ( ! V_128 )
return - V_129 ;
return V_128 ;
}
void F_49 ( struct V_69 * V_62 ,
struct V_107 * V_108 ,
enum V_123 V_124 )
{
if ( ! V_108 -> V_113 [ V_112 ] . V_114 -> V_130 )
return;
F_50 ( V_62 -> V_84 ,
V_108 -> V_113 [ V_112 ] . V_114 ,
V_108 -> V_113 [ V_112 ] . V_115 ,
V_124 ) ;
V_108 -> V_113 [ V_112 ] . V_114 -> V_130 = 0 ;
}
static int F_51 ( struct V_69 * V_62 , T_1 V_9 )
{
struct V_131 * V_132 ;
int V_60 ;
V_60 = F_52 ( V_62 -> V_84 , V_9 , 0 ,
& V_62 -> V_133 [ V_9 - 1 ] , NULL ) ;
V_132 = V_62 -> V_84 -> V_134 ( V_62 -> V_84 , V_9 ) ;
if ( V_132 ) {
memcpy ( & V_62 -> V_135 , V_132 -> V_136 , V_137 ) ;
F_53 ( V_132 ) ;
} else if ( ! V_60 ) {
memcpy ( & V_62 -> V_135 [ V_9 - 1 ] [ 0 ] ,
& V_62 -> V_133 [ V_9 - 1 ] . V_138 [ 8 ] , 3 ) ;
memcpy ( & V_62 -> V_135 [ V_9 - 1 ] [ 3 ] ,
& V_62 -> V_133 [ V_9 - 1 ] . V_138 [ 13 ] , 3 ) ;
V_62 -> V_135 [ V_9 - 1 ] [ 0 ] &= ~ 0x02 ;
}
return V_60 ;
}
static inline void F_54 ( struct V_69 * V_62 ,
T_1 V_9 )
{
memcpy ( & V_139 [ 2 ] , & V_62 -> V_135 [ V_9 - 1 ] ,
sizeof( V_62 -> V_135 [ V_9 - 1 ] ) ) ;
F_55 ( & V_139 [ 0 ] , 2 ) ;
}
bool F_56 ( struct V_69 * V_62 , T_1 V_9 )
{
return V_62 -> V_140 [ V_9 - 1 ] . V_141 == V_142 ;
}
int F_17 ( struct V_69 * V_62 , T_1 V_9 )
{
int V_60 ;
memset ( & V_62 -> V_140 [ V_9 - 1 ] , 0 ,
sizeof( V_62 -> V_140 [ V_9 - 1 ] ) ) ;
V_60 = F_57 ( V_62 -> V_84 , V_9 ,
& V_62 -> V_140 [ V_9 - 1 ] ) ;
if ( V_60 )
goto V_61;
V_60 = F_51 ( V_62 , V_9 ) ;
if ( V_60 )
goto V_61;
if ( ! strncmp ( V_139 , V_143 ,
sizeof( V_139 ) ) &&
F_56 ( V_62 , V_9 ) )
F_54 ( V_62 , V_9 ) ;
V_61:
return V_60 ;
}
long F_58 ( struct V_69 * V_62 )
{
struct V_144 V_145 = {
. V_146 = V_147 , . V_148 = 0 } ;
long V_60 ;
V_62 -> V_91 = F_59 ( V_62 -> V_84 ,
V_149 , NULL ,
V_62 , & V_145 ) ;
V_60 = F_26 ( V_62 -> V_91 ) ;
if ( F_27 ( V_62 -> V_91 ) ) {
V_62 -> V_91 = NULL ;
return V_60 ;
}
V_62 -> V_63 = F_59 ( V_62 -> V_84 ,
V_150 , NULL ,
V_62 , & V_145 ) ;
V_60 = F_26 ( V_62 -> V_63 ) ;
if ( F_27 ( V_62 -> V_63 ) ) {
V_62 -> V_63 = NULL ;
goto V_151;
}
F_60 ( & V_62 -> V_77 , V_62 -> V_84 ,
F_19 ) ;
F_61 ( & V_62 -> V_77 ) ;
F_62 ( V_62 ) ;
V_62 -> V_152 = 1 ;
return V_60 ;
V_151:
F_63 ( V_62 -> V_91 ) ;
return V_60 ;
}
static void F_64 ( struct V_69 * V_62 )
{
if ( ! V_62 -> V_152 )
return;
F_65 ( V_62 ) ;
F_66 ( & V_62 -> V_77 ) ;
F_63 ( V_62 -> V_63 ) ;
F_63 ( V_62 -> V_91 ) ;
}
static void F_67 ( struct V_153 * V_84 )
{
struct V_69 * V_62 ;
if ( V_84 -> V_154 != V_155 )
return;
V_62 = F_68 ( sizeof( * V_62 ) , V_156 ) ;
if ( ! V_62 )
return;
V_62 -> V_84 = V_84 ;
F_69 ( & V_62 -> V_70 , F_15 ) ;
F_70 ( & V_157 . V_158 ) ;
F_71 ( & V_62 -> V_159 , & V_157 . V_159 ) ;
F_72 ( & V_157 . V_158 ) ;
F_73 ( V_84 , & V_160 , V_62 ) ;
}
static void F_74 ( struct V_153 * V_84 , void * V_161 )
{
struct V_69 * V_62 ;
V_62 = F_75 ( V_84 , & V_160 ) ;
F_73 ( V_84 , & V_160 , NULL ) ;
F_70 ( & V_157 . V_158 ) ;
F_76 ( & V_62 -> V_159 ) ;
F_72 ( & V_157 . V_158 ) ;
F_77 ( V_62 ) ;
F_64 ( V_62 ) ;
F_78 ( V_62 ) ;
}
int T_2 F_79 ( void )
{
return F_80 ( & V_160 ) ;
}
void F_81 ( void )
{
F_82 ( & V_160 ) ;
}
