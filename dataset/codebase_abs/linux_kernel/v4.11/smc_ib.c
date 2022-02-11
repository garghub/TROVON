int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
if ( * V_5 )
return 0 ;
* V_5 = V_2 -> V_7 -> V_8 ( V_2 , V_3 ) ;
V_6 = F_2 ( * V_5 ) ;
if ( F_3 ( * V_5 ) )
* V_5 = NULL ;
return V_6 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 = V_14 ;
V_12 . V_15 = 0 ;
V_12 . V_16 = V_10 -> V_17 ;
V_12 . V_18 = V_19
| V_20 ;
return F_5 ( V_10 -> V_21 , & V_12 ,
V_22 | V_23 |
V_24 | V_25 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
enum V_26 V_27 =
V_22 | V_28 | V_29 | V_30 |
V_31 | V_32 | V_33 ;
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 = V_34 ;
V_12 . V_35 = F_7 ( V_10 -> V_35 , V_10 -> V_36 ) ;
V_12 . V_37 . V_16 = V_10 -> V_17 ;
V_12 . V_37 . V_38 = V_39 ;
V_12 . V_37 . V_40 . V_41 = 1 ;
memcpy ( & V_12 . V_37 . V_40 . V_42 , V_10 -> V_43 ,
sizeof( V_10 -> V_43 ) ) ;
memcpy ( & V_12 . V_37 . V_44 , V_10 -> V_45 ,
sizeof( V_10 -> V_45 ) ) ;
V_12 . V_46 = V_10 -> V_47 ;
V_12 . V_48 = V_10 -> V_49 ;
V_12 . V_50 = 1 ;
V_12 . V_51 = V_52 ;
return F_5 ( V_10 -> V_21 , & V_12 , V_27 ) ;
}
int F_8 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 = V_53 ;
V_12 . V_54 = V_55 ;
V_12 . V_56 = V_57 ;
V_12 . V_58 = V_59 ;
V_12 . V_60 = V_10 -> V_61 ;
V_12 . V_62 = 1 ;
return F_5 ( V_10 -> V_21 , & V_12 ,
V_22 | V_63 | V_64 |
V_65 | V_66 |
V_67 ) ;
}
int F_9 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_13 = V_68 ;
return F_5 ( V_10 -> V_21 , & V_12 , V_22 ) ;
}
int F_10 ( struct V_9 * V_10 )
{
struct V_69 * V_70 =
F_11 ( V_10 , struct V_69 , V_10 [ 0 ] ) ;
int V_6 = 0 ;
V_6 = F_4 ( V_10 ) ;
if ( V_6 )
goto V_71;
V_6 = F_6 ( V_10 ) ;
if ( V_6 )
goto V_71;
F_12 ( V_10 ) ;
V_6 = F_13 ( V_10 -> V_72 -> V_73 ,
V_74 ) ;
if ( V_6 )
goto V_71;
V_6 = F_14 ( V_10 ) ;
if ( V_6 )
goto V_71;
F_12 ( V_10 ) ;
if ( V_70 -> V_75 == V_76 ) {
V_6 = F_8 ( V_10 ) ;
if ( V_6 )
goto V_71;
F_12 ( V_10 ) ;
}
V_71:
return V_6 ;
}
static void F_15 ( struct V_77 * V_78 )
{
struct V_79 * V_72 = F_11 (
V_78 , struct V_79 , V_80 ) ;
T_1 V_81 ;
F_16 (port_idx, &smcibdev->port_event_mask, SMC_MAX_PORTS) {
F_17 ( V_72 , V_81 + 1 ) ;
F_18 ( V_81 , & V_72 -> V_82 ) ;
}
}
static void F_19 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_79 * V_72 ;
T_1 V_81 ;
V_72 = F_11 ( V_84 , struct V_79 , V_87 ) ;
if ( ! F_20 ( V_72 -> V_88 -> V_89 ) )
return;
switch ( V_86 -> V_90 ) {
case V_91 :
V_81 = V_86 -> V_92 . V_16 - 1 ;
F_21 ( V_81 , & V_72 -> V_82 ) ;
F_22 ( & V_72 -> V_80 ) ;
case V_93 :
break;
case V_94 :
V_81 = V_86 -> V_92 . V_16 - 1 ;
F_21 ( V_81 , & V_72 -> V_82 ) ;
F_22 ( & V_72 -> V_80 ) ;
break;
default:
break;
}
}
void F_23 ( struct V_9 * V_10 )
{
F_24 ( V_10 -> V_95 ) ;
V_10 -> V_95 = NULL ;
}
int F_25 ( struct V_9 * V_10 )
{
int V_6 ;
V_10 -> V_95 = F_26 ( V_10 -> V_72 -> V_88 , 0 ) ;
V_6 = F_2 ( V_10 -> V_95 ) ;
if ( F_3 ( V_10 -> V_95 ) )
V_10 -> V_95 = NULL ;
return V_6 ;
}
static void F_27 ( struct V_85 * V_86 , void * V_96 )
{
switch ( V_86 -> V_90 ) {
case V_93 :
case V_97 :
case V_91 :
case V_98 :
break;
default:
break;
}
}
void F_28 ( struct V_9 * V_10 )
{
F_29 ( V_10 -> V_21 ) ;
V_10 -> V_21 = NULL ;
}
int F_30 ( struct V_9 * V_10 )
{
struct V_99 V_12 = {
. V_87 = F_27 ,
. V_100 = V_10 ,
. V_101 = V_10 -> V_72 -> V_102 ,
. V_103 = V_10 -> V_72 -> V_73 ,
. V_104 = NULL ,
. V_105 = {
. V_106 = V_107 ,
. V_108 = V_107 * 3 ,
. V_109 = V_110 ,
. V_111 = 1 ,
. V_112 = V_113 ,
} ,
. V_114 = V_115 ,
. V_116 = V_117 ,
} ;
int V_6 ;
V_10 -> V_21 = F_31 ( V_10 -> V_95 , & V_12 ) ;
V_6 = F_2 ( V_10 -> V_21 ) ;
if ( F_3 ( V_10 -> V_21 ) )
V_10 -> V_21 = NULL ;
else
F_12 ( V_10 ) ;
return V_6 ;
}
int F_32 ( struct V_79 * V_72 , int V_118 ,
struct V_119 * V_120 ,
enum V_121 V_122 )
{
int V_6 = 0 ;
if ( V_120 -> V_123 [ V_124 ] )
return V_6 ;
V_120 -> V_123 [ V_124 ] =
F_33 ( V_72 -> V_88 , V_120 -> V_125 ,
V_118 , V_122 ) ;
if ( F_34 ( V_72 -> V_88 ,
V_120 -> V_123 [ V_124 ] ) )
V_6 = - V_126 ;
return V_6 ;
}
void F_35 ( struct V_79 * V_72 , int V_118 ,
struct V_119 * V_120 ,
enum V_121 V_122 )
{
if ( ! V_120 -> V_123 [ V_124 ] )
return;
F_36 ( V_72 -> V_88 , * V_120 -> V_123 , V_118 ,
V_122 ) ;
V_120 -> V_123 [ V_124 ] = 0 ;
}
static int F_37 ( struct V_79 * V_72 , T_1 V_17 )
{
struct V_127 * V_128 ;
int V_6 ;
V_6 = F_38 ( V_72 -> V_88 , V_17 , 0 ,
& V_72 -> V_129 [ V_17 - 1 ] , NULL ) ;
V_128 = V_72 -> V_88 -> V_130 ( V_72 -> V_88 , V_17 ) ;
if ( V_128 ) {
memcpy ( & V_72 -> V_131 , V_128 -> V_132 , V_133 ) ;
} else if ( ! V_6 ) {
memcpy ( & V_72 -> V_131 [ V_17 - 1 ] [ 0 ] ,
& V_72 -> V_129 [ V_17 - 1 ] . V_134 [ 8 ] , 3 ) ;
memcpy ( & V_72 -> V_131 [ V_17 - 1 ] [ 3 ] ,
& V_72 -> V_129 [ V_17 - 1 ] . V_134 [ 13 ] , 3 ) ;
V_72 -> V_131 [ V_17 - 1 ] [ 0 ] &= ~ 0x02 ;
}
return V_6 ;
}
static inline void F_39 ( struct V_79 * V_72 ,
T_1 V_17 )
{
memcpy ( & V_135 [ 2 ] , & V_72 -> V_131 [ V_17 - 1 ] ,
sizeof( V_72 -> V_131 [ V_17 - 1 ] ) ) ;
F_40 ( & V_135 [ 0 ] , 2 ) ;
}
bool F_41 ( struct V_79 * V_72 , T_1 V_17 )
{
return V_72 -> V_136 [ V_17 - 1 ] . V_137 == V_138 ;
}
int F_17 ( struct V_79 * V_72 , T_1 V_17 )
{
int V_6 ;
memset ( & V_72 -> V_136 [ V_17 - 1 ] , 0 ,
sizeof( V_72 -> V_136 [ V_17 - 1 ] ) ) ;
V_6 = F_42 ( V_72 -> V_88 , V_17 ,
& V_72 -> V_136 [ V_17 - 1 ] ) ;
if ( V_6 )
goto V_71;
V_6 = F_37 ( V_72 , V_17 ) ;
if ( V_6 )
goto V_71;
if ( ! strncmp ( V_135 , V_139 ,
sizeof( V_135 ) ) &&
F_41 ( V_72 , V_17 ) )
F_39 ( V_72 , V_17 ) ;
V_71:
return V_6 ;
}
long F_43 ( struct V_79 * V_72 )
{
struct V_140 V_141 = {
. V_142 = V_143 , . V_144 = 0 } ;
long V_6 ;
V_72 -> V_102 = F_44 ( V_72 -> V_88 ,
V_145 , NULL ,
V_72 , & V_141 ) ;
V_6 = F_2 ( V_72 -> V_102 ) ;
if ( F_3 ( V_72 -> V_102 ) ) {
V_72 -> V_102 = NULL ;
return V_6 ;
}
V_72 -> V_73 = F_44 ( V_72 -> V_88 ,
V_146 , NULL ,
V_72 , & V_141 ) ;
V_6 = F_2 ( V_72 -> V_73 ) ;
if ( F_3 ( V_72 -> V_73 ) ) {
V_72 -> V_73 = NULL ;
goto V_147;
}
F_45 ( & V_72 -> V_87 , V_72 -> V_88 ,
F_19 ) ;
F_46 ( & V_72 -> V_87 ) ;
F_47 ( V_72 ) ;
V_72 -> V_148 = 1 ;
return V_6 ;
V_147:
F_48 ( V_72 -> V_102 ) ;
return V_6 ;
}
static void F_49 ( struct V_79 * V_72 )
{
if ( ! V_72 -> V_148 )
return;
F_50 ( V_72 ) ;
F_51 ( & V_72 -> V_87 ) ;
F_48 ( V_72 -> V_73 ) ;
F_48 ( V_72 -> V_102 ) ;
}
static void F_52 ( struct V_149 * V_88 )
{
struct V_79 * V_72 ;
if ( V_88 -> V_150 != V_151 )
return;
V_72 = F_53 ( sizeof( * V_72 ) , V_152 ) ;
if ( ! V_72 )
return;
V_72 -> V_88 = V_88 ;
F_54 ( & V_72 -> V_80 , F_15 ) ;
F_55 ( & V_153 . V_154 ) ;
F_56 ( & V_72 -> V_155 , & V_153 . V_155 ) ;
F_57 ( & V_153 . V_154 ) ;
F_58 ( V_88 , & V_156 , V_72 ) ;
}
static void F_59 ( struct V_149 * V_88 , void * V_157 )
{
struct V_79 * V_72 ;
V_72 = F_60 ( V_88 , & V_156 ) ;
F_58 ( V_88 , & V_156 , NULL ) ;
F_55 ( & V_153 . V_154 ) ;
F_61 ( & V_72 -> V_155 ) ;
F_57 ( & V_153 . V_154 ) ;
F_62 ( V_72 ) ;
F_49 ( V_72 ) ;
F_63 ( V_72 ) ;
}
int T_2 F_64 ( void )
{
return F_65 ( & V_156 ) ;
}
void F_66 ( void )
{
F_67 ( & V_156 ) ;
}
