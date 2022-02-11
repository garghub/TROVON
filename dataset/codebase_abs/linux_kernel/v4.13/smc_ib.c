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
V_2 -> V_83 = F_25 ( V_2 -> V_62 -> V_84 ,
V_85 ) ;
V_60 = F_26 ( V_2 -> V_83 ) ;
if ( F_27 ( V_2 -> V_83 ) )
V_2 -> V_83 = NULL ;
return V_60 ;
}
static void F_28 ( struct V_75 * V_76 , void * V_86 )
{
switch ( V_76 -> V_78 ) {
case V_81 :
case V_87 :
case V_79 :
case V_88 :
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
struct V_89 V_4 = {
. V_77 = F_28 ,
. V_90 = V_2 ,
. V_91 = V_2 -> V_62 -> V_92 ,
. V_93 = V_2 -> V_62 -> V_63 ,
. V_94 = NULL ,
. V_95 = {
. V_96 = V_97 ,
. V_98 = V_97 * 3 ,
. V_99 = V_100 ,
. V_101 = 1 ,
} ,
. V_102 = V_103 ,
. V_104 = V_105 ,
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
int F_33 ( struct V_69 * V_62 , int V_106 ,
struct V_107 * V_108 ,
enum V_109 V_110 )
{
int V_60 = 0 ;
if ( V_108 -> V_111 [ V_112 ] )
return V_60 ;
V_108 -> V_111 [ V_112 ] =
F_34 ( V_62 -> V_84 , V_108 -> V_113 ,
V_106 , V_110 ) ;
if ( F_35 ( V_62 -> V_84 ,
V_108 -> V_111 [ V_112 ] ) )
V_60 = - V_114 ;
return V_60 ;
}
void F_36 ( struct V_69 * V_62 , int V_106 ,
struct V_107 * V_108 ,
enum V_109 V_110 )
{
if ( ! V_108 -> V_111 [ V_112 ] )
return;
F_37 ( V_62 -> V_84 , * V_108 -> V_111 , V_106 ,
V_110 ) ;
V_108 -> V_111 [ V_112 ] = 0 ;
}
static int F_38 ( struct V_69 * V_62 , T_1 V_9 )
{
struct V_115 * V_116 ;
int V_60 ;
V_60 = F_39 ( V_62 -> V_84 , V_9 , 0 ,
& V_62 -> V_117 [ V_9 - 1 ] , NULL ) ;
V_116 = V_62 -> V_84 -> V_118 ( V_62 -> V_84 , V_9 ) ;
if ( V_116 ) {
memcpy ( & V_62 -> V_119 , V_116 -> V_120 , V_121 ) ;
} else if ( ! V_60 ) {
memcpy ( & V_62 -> V_119 [ V_9 - 1 ] [ 0 ] ,
& V_62 -> V_117 [ V_9 - 1 ] . V_122 [ 8 ] , 3 ) ;
memcpy ( & V_62 -> V_119 [ V_9 - 1 ] [ 3 ] ,
& V_62 -> V_117 [ V_9 - 1 ] . V_122 [ 13 ] , 3 ) ;
V_62 -> V_119 [ V_9 - 1 ] [ 0 ] &= ~ 0x02 ;
}
return V_60 ;
}
static inline void F_40 ( struct V_69 * V_62 ,
T_1 V_9 )
{
memcpy ( & V_123 [ 2 ] , & V_62 -> V_119 [ V_9 - 1 ] ,
sizeof( V_62 -> V_119 [ V_9 - 1 ] ) ) ;
F_41 ( & V_123 [ 0 ] , 2 ) ;
}
bool F_42 ( struct V_69 * V_62 , T_1 V_9 )
{
return V_62 -> V_124 [ V_9 - 1 ] . V_125 == V_126 ;
}
int F_17 ( struct V_69 * V_62 , T_1 V_9 )
{
int V_60 ;
memset ( & V_62 -> V_124 [ V_9 - 1 ] , 0 ,
sizeof( V_62 -> V_124 [ V_9 - 1 ] ) ) ;
V_60 = F_43 ( V_62 -> V_84 , V_9 ,
& V_62 -> V_124 [ V_9 - 1 ] ) ;
if ( V_60 )
goto V_61;
V_60 = F_38 ( V_62 , V_9 ) ;
if ( V_60 )
goto V_61;
if ( ! strncmp ( V_123 , V_127 ,
sizeof( V_123 ) ) &&
F_42 ( V_62 , V_9 ) )
F_40 ( V_62 , V_9 ) ;
V_61:
return V_60 ;
}
long F_44 ( struct V_69 * V_62 )
{
struct V_128 V_129 = {
. V_130 = V_131 , . V_132 = 0 } ;
long V_60 ;
V_62 -> V_92 = F_45 ( V_62 -> V_84 ,
V_133 , NULL ,
V_62 , & V_129 ) ;
V_60 = F_26 ( V_62 -> V_92 ) ;
if ( F_27 ( V_62 -> V_92 ) ) {
V_62 -> V_92 = NULL ;
return V_60 ;
}
V_62 -> V_63 = F_45 ( V_62 -> V_84 ,
V_134 , NULL ,
V_62 , & V_129 ) ;
V_60 = F_26 ( V_62 -> V_63 ) ;
if ( F_27 ( V_62 -> V_63 ) ) {
V_62 -> V_63 = NULL ;
goto V_135;
}
F_46 ( & V_62 -> V_77 , V_62 -> V_84 ,
F_19 ) ;
F_47 ( & V_62 -> V_77 ) ;
F_48 ( V_62 ) ;
V_62 -> V_136 = 1 ;
return V_60 ;
V_135:
F_49 ( V_62 -> V_92 ) ;
return V_60 ;
}
static void F_50 ( struct V_69 * V_62 )
{
if ( ! V_62 -> V_136 )
return;
F_51 ( V_62 ) ;
F_52 ( & V_62 -> V_77 ) ;
F_49 ( V_62 -> V_63 ) ;
F_49 ( V_62 -> V_92 ) ;
}
static void F_53 ( struct V_137 * V_84 )
{
struct V_69 * V_62 ;
if ( V_84 -> V_138 != V_139 )
return;
V_62 = F_54 ( sizeof( * V_62 ) , V_140 ) ;
if ( ! V_62 )
return;
V_62 -> V_84 = V_84 ;
F_55 ( & V_62 -> V_70 , F_15 ) ;
F_56 ( & V_141 . V_142 ) ;
F_57 ( & V_62 -> V_143 , & V_141 . V_143 ) ;
F_58 ( & V_141 . V_142 ) ;
F_59 ( V_84 , & V_144 , V_62 ) ;
}
static void F_60 ( struct V_137 * V_84 , void * V_145 )
{
struct V_69 * V_62 ;
V_62 = F_61 ( V_84 , & V_144 ) ;
F_59 ( V_84 , & V_144 , NULL ) ;
F_56 ( & V_141 . V_142 ) ;
F_62 ( & V_62 -> V_143 ) ;
F_58 ( & V_141 . V_142 ) ;
F_63 ( V_62 ) ;
F_50 ( V_62 ) ;
F_64 ( V_62 ) ;
}
int T_2 F_65 ( void )
{
return F_66 ( & V_144 ) ;
}
void F_67 ( void )
{
F_68 ( & V_144 ) ;
}
