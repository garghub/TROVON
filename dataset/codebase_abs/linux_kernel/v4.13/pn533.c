static inline T_1 F_1 ( T_2 V_1 )
{
return ~ ( T_1 ) ( ( ( V_1 & 0xFF00 ) >> 8 ) + ( T_1 ) ( V_1 & 0xFF ) ) + 1 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return ~ V_1 + 1 ;
}
static T_1 F_3 ( T_1 * V_2 , int V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_4 += V_2 [ V_5 ] ;
return F_2 ( V_4 ) ;
}
static void F_4 ( void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_10 = 0 ;
V_9 -> V_11 = F_5 ( V_12 ) ;
F_6 ( V_9 ) = V_13 ;
F_7 ( V_9 ) = V_7 ;
V_9 -> V_3 = 2 ;
}
static void F_8 ( void * V_6 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_14 = F_2 ( V_9 -> V_3 ) ;
F_9 ( V_9 ) =
F_3 ( V_9 -> V_2 , V_9 -> V_3 ) ;
F_10 ( V_9 ) = 0 ;
}
static void F_11 ( void * V_6 , int V_15 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_3 += V_15 ;
}
static bool F_12 ( void * V_6 , struct V_16 * V_17 )
{
T_1 V_18 ;
struct V_8 * V_19 = V_6 ;
if ( V_19 -> V_11 != F_5 ( V_12 ) )
return false ;
if ( F_13 ( ! F_14 ( V_19 ) ) ) {
V_17 -> V_20 -> V_21 = V_22 ;
V_18 = F_2 ( V_19 -> V_3 ) ;
if ( V_18 != V_19 -> V_14 )
return false ;
V_18 = F_3 ( V_19 -> V_2 , V_19 -> V_3 ) ;
if ( V_18 != F_9 ( V_19 ) )
return false ;
} else {
struct V_23 * V_24 = V_6 ;
V_17 -> V_20 -> V_21 = V_25 ;
V_18 = F_1 ( F_15 ( V_24 -> V_3 ) ) ;
if ( V_18 != V_24 -> V_14 )
return false ;
V_18 = F_3 ( V_24 -> V_2 ,
F_15 ( V_24 -> V_3 ) ) ;
if ( V_18 != F_16 ( V_24 ) )
return false ;
}
return true ;
}
bool F_17 ( void * V_6 )
{
struct V_8 * V_9 = V_6 ;
if ( V_9 -> V_11 != F_5 ( V_12 ) )
return false ;
if ( V_9 -> V_3 != 0 || V_9 -> V_14 != 0xFF )
return false ;
return true ;
}
static inline int F_18 ( void * V_9 )
{
struct V_8 * V_26 = V_9 ;
if ( F_14 ( V_26 ) ) {
struct V_23 * V_24 = V_9 ;
return sizeof( struct V_23 )
+ F_15 ( V_24 -> V_3 ) + V_27 ;
}
return sizeof( struct V_8 ) + V_26 -> V_3 +
V_27 ;
}
static T_1 F_19 ( void * V_9 )
{
struct V_8 * V_26 = V_9 ;
struct V_23 * V_24 = V_9 ;
if ( F_14 ( V_26 ) )
return F_7 ( V_24 ) ;
else
return F_7 ( V_26 ) ;
}
bool F_20 ( struct V_16 * V_17 , void * V_9 )
{
return ( V_17 -> V_20 -> V_28 ( V_9 ) ==
F_21 ( V_17 -> V_29 -> V_30 ) ) ;
}
static void F_22 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_32 )
{
int V_33 = V_32 -> V_15 ;
struct V_34 * V_20 = V_17 -> V_20 ;
F_23 ( V_32 , V_20 -> V_35 ) ;
F_24 ( V_32 , V_20 -> V_36 ) ;
V_20 -> V_37 ( V_32 -> V_2 , V_7 ) ;
V_20 -> V_38 ( V_32 -> V_2 , V_33 ) ;
V_20 -> V_39 ( V_32 -> V_2 ) ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_40 * V_29 = V_17 -> V_29 ;
struct V_31 * V_41 ;
int V_42 , V_43 = 0 ;
if ( ! V_29 ) {
F_26 ( V_17 -> V_17 , L_1 , V_44 ) ;
goto V_45;
}
F_27 ( V_29 -> V_46 ) ;
V_42 = V_29 -> V_42 ;
V_41 = V_29 -> V_41 ;
if ( V_42 < 0 ) {
V_43 = V_29 -> V_47 ( V_17 , V_29 -> V_48 ,
F_28 ( V_42 ) ) ;
F_27 ( V_41 ) ;
goto V_45;
}
if ( ! V_41 )
V_41 = F_28 ( - V_49 ) ;
if ( ! F_29 ( V_41 ) ) {
F_30 ( V_41 , V_17 -> V_20 -> V_21 ) ;
F_31 ( V_41 , V_41 -> V_15 - V_17 -> V_20 -> V_50 ) ;
}
V_43 = V_29 -> V_47 ( V_17 , V_29 -> V_48 , V_41 ) ;
V_45:
F_32 ( V_29 ) ;
V_17 -> V_29 = NULL ;
return V_43 ;
}
static int F_33 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
struct V_40 * V_29 ;
int V_43 = 0 ;
F_26 ( V_17 -> V_17 , L_2 , V_7 ) ;
V_29 = F_34 ( sizeof( * V_29 ) , V_51 ) ;
if ( ! V_29 )
return - V_52 ;
V_29 -> V_30 = V_7 ;
V_29 -> V_46 = V_46 ;
V_29 -> V_47 = V_47 ;
V_29 -> V_48 = V_48 ;
F_22 ( V_17 , V_7 , V_46 ) ;
F_35 ( & V_17 -> V_53 ) ;
if ( ! V_17 -> V_54 ) {
V_17 -> V_29 = V_29 ;
V_43 = V_17 -> V_55 -> V_56 ( V_17 , V_46 ) ;
if ( V_43 ) {
V_17 -> V_29 = NULL ;
goto error;
}
V_17 -> V_54 = 1 ;
goto V_57;
}
F_26 ( V_17 -> V_17 , L_3 ,
V_44 , V_7 ) ;
F_36 ( & V_29 -> V_58 ) ;
F_37 ( & V_29 -> V_58 , & V_17 -> V_59 ) ;
goto V_57;
error:
F_32 ( V_29 ) ;
V_57:
F_38 ( & V_17 -> V_53 ) ;
return V_43 ;
}
static int F_39 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
int V_43 ;
V_43 = F_33 ( V_17 , V_7 , V_46 , V_47 ,
V_48 ) ;
return V_43 ;
}
static int F_40 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
int V_43 ;
V_43 = F_33 ( V_17 , V_7 , V_46 , V_47 ,
V_48 ) ;
return V_43 ;
}
static int F_41 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
struct V_40 * V_29 ;
int V_43 ;
V_29 = F_34 ( sizeof( * V_29 ) , V_51 ) ;
if ( ! V_29 )
return - V_52 ;
V_29 -> V_30 = V_7 ;
V_29 -> V_46 = V_46 ;
V_29 -> V_47 = V_47 ;
V_29 -> V_48 = V_48 ;
F_22 ( V_17 , V_7 , V_46 ) ;
V_17 -> V_29 = V_29 ;
V_43 = V_17 -> V_55 -> V_56 ( V_17 , V_46 ) ;
if ( V_43 < 0 ) {
V_17 -> V_29 = NULL ;
F_32 ( V_29 ) ;
}
return V_43 ;
}
static void F_42 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_62 ) ;
int V_43 ;
V_43 = F_25 ( V_17 ) ;
if ( V_43 != - V_63 )
F_44 ( V_17 -> V_64 , & V_17 -> V_65 ) ;
}
static void F_45 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_65 ) ;
struct V_40 * V_29 ;
int V_43 ;
F_35 ( & V_17 -> V_53 ) ;
if ( F_46 ( & V_17 -> V_59 ) ) {
V_17 -> V_54 = 0 ;
F_38 ( & V_17 -> V_53 ) ;
return;
}
V_29 = F_47 ( & V_17 -> V_59 , struct V_40 , V_58 ) ;
F_48 ( & V_29 -> V_58 ) ;
F_38 ( & V_17 -> V_53 ) ;
V_17 -> V_29 = V_29 ;
V_43 = V_17 -> V_55 -> V_56 ( V_17 , V_29 -> V_46 ) ;
if ( V_43 < 0 ) {
V_17 -> V_29 = NULL ;
F_27 ( V_29 -> V_46 ) ;
F_32 ( V_29 ) ;
return;
}
}
static int F_49 ( struct V_16 * V_17 , void * V_66 ,
struct V_31 * V_41 )
{
struct V_67 * V_68 = V_66 ;
V_68 -> V_41 = V_41 ;
F_50 ( & V_68 -> V_45 ) ;
return 0 ;
}
static struct V_31 * F_51 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_46 )
{
int V_43 ;
struct V_67 V_68 ;
F_52 ( & V_68 . V_45 ) ;
V_43 = F_40 ( V_17 , V_7 , V_46 ,
F_49 , & V_68 ) ;
if ( V_43 ) {
F_27 ( V_46 ) ;
return F_28 ( V_43 ) ;
}
F_53 ( & V_68 . V_45 ) ;
return V_68 . V_41 ;
}
static struct V_31 * F_54 ( struct V_16 * V_17 , unsigned int V_69 )
{
struct V_31 * V_32 ;
V_32 = F_55 ( V_17 -> V_20 -> V_35 +
V_69 +
V_17 -> V_20 -> V_36 , V_51 ) ;
if ( V_32 )
F_56 ( V_32 , V_17 -> V_20 -> V_35 ) ;
return V_32 ;
}
static bool F_57 ( struct V_70 * V_71 ,
int V_72 )
{
T_1 V_73 ;
T_1 V_74 ;
if ( V_72 < sizeof( struct V_70 ) )
return false ;
V_73 = F_58 ( V_71 -> V_75 ) ;
V_74 = F_59 ( V_71 -> V_75 ) ;
if ( ( V_73 == V_76 &&
V_74 != V_77 ) ||
( V_73 != V_76 &&
V_74 == V_77 ) )
return false ;
if ( F_60 ( V_71 -> V_78 ) != 0 )
return false ;
return true ;
}
static int F_61 ( struct V_79 * V_80 , T_1 * V_81 ,
int V_82 )
{
struct V_70 * V_83 ;
V_83 = (struct V_70 * ) V_81 ;
if ( ! F_57 ( V_83 , V_82 ) )
return - V_84 ;
switch ( F_62 ( V_83 -> V_78 ) ) {
case V_85 :
V_80 -> V_86 = V_87 ;
break;
case V_88 :
V_80 -> V_86 = V_89 ;
break;
case V_90 :
V_80 -> V_86 = V_91 ;
break;
case V_92 :
V_80 -> V_86 = V_89 |
V_91 ;
break;
}
V_80 -> V_75 = F_15 ( V_83 -> V_75 ) ;
V_80 -> V_78 = V_83 -> V_78 ;
V_80 -> V_93 = V_83 -> V_94 ;
memcpy ( V_80 -> V_95 , V_83 -> V_96 , V_80 -> V_93 ) ;
return 0 ;
}
static bool F_63 ( struct V_97 * V_98 ,
int V_72 )
{
if ( V_72 < sizeof( struct V_97 ) )
return false ;
if ( V_98 -> V_99 != V_100 )
return false ;
return true ;
}
static int F_64 ( struct V_79 * V_80 , T_1 * V_81 ,
int V_82 )
{
struct V_97 * V_101 ;
V_101 = (struct V_97 * ) V_81 ;
if ( ! F_63 ( V_101 , V_82 ) )
return - V_84 ;
if ( ( V_101 -> V_102 [ 0 ] == V_103 ) &&
( V_101 -> V_102 [ 1 ] == V_104 ) )
V_80 -> V_86 = V_91 ;
else
V_80 -> V_86 = V_105 ;
memcpy ( V_80 -> V_106 , & V_101 -> V_99 , 9 ) ;
V_80 -> V_107 = 9 ;
memcpy ( V_80 -> V_102 , V_101 -> V_102 , V_108 ) ;
V_80 -> V_109 = V_108 ;
return 0 ;
}
static bool F_65 ( struct V_110 * V_111 ,
int V_72 )
{
T_1 V_73 ;
T_1 V_74 ;
if ( V_72 < sizeof( struct V_110 ) )
return false ;
V_73 = F_58 ( V_111 -> V_75 ) ;
V_74 = F_59 ( V_111 -> V_75 ) ;
if ( ( V_73 == V_76 &&
V_74 != V_77 ) ||
( V_73 != V_76 &&
V_74 == V_77 ) )
return false ;
return true ;
}
static int F_66 ( struct V_79 * V_80 , T_1 * V_81 ,
int V_82 )
{
struct V_110 * V_112 ;
V_112 = (struct V_110 * ) V_81 ;
if ( ! F_65 ( V_112 , V_82 ) )
return - V_84 ;
V_80 -> V_86 = V_113 ;
V_80 -> V_75 = F_15 ( V_112 -> V_75 ) ;
V_80 -> V_93 = 4 ;
memcpy ( V_80 -> V_95 , V_112 -> V_114 , V_80 -> V_93 ) ;
return 0 ;
}
static bool F_67 ( struct V_115 * V_116 ,
int V_72 )
{
if ( V_72 < sizeof( struct V_115 ) )
return false ;
if ( V_116 -> V_117 . V_99 != V_118 )
return false ;
if ( F_68 ( V_116 -> V_117 . V_119 . V_120 ) &
V_121 )
return false ;
return true ;
}
static int F_69 ( struct V_79 * V_80 , T_1 * V_81 ,
int V_82 )
{
struct V_115 * V_122 ;
V_122 = (struct V_115 * ) V_81 ;
if ( ! F_67 ( V_122 , V_82 ) )
return - V_84 ;
V_80 -> V_86 = V_123 ;
return 0 ;
}
static int F_70 ( struct V_16 * V_17 , T_1 V_124 , T_1 * V_125 ,
int V_126 )
{
struct V_79 V_80 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_4 ,
V_44 , V_17 -> V_127 ) ;
if ( V_124 != 1 )
return - V_84 ;
memset ( & V_80 , 0 , sizeof( struct V_79 ) ) ;
switch ( V_17 -> V_127 ) {
case V_128 :
V_43 = F_61 ( & V_80 , V_125 , V_126 ) ;
break;
case V_129 :
case V_130 :
V_43 = F_64 ( & V_80 , V_125 , V_126 ) ;
break;
case V_131 :
V_43 = F_66 ( & V_80 , V_125 , V_126 ) ;
break;
case V_132 :
V_43 = F_69 ( & V_80 , V_125 , V_126 ) ;
break;
default:
F_71 ( V_17 -> V_17 ,
L_5 ) ;
return - V_84 ;
}
if ( V_43 )
return V_43 ;
if ( ! ( V_80 . V_86 & V_17 -> V_133 ) ) {
F_26 ( V_17 -> V_17 ,
L_6 ) ;
return - V_134 ;
}
F_26 ( V_17 -> V_17 ,
L_7 ,
V_80 . V_86 ) ;
V_17 -> V_135 = V_80 . V_86 ;
F_72 ( V_17 ) ;
F_73 ( V_17 -> V_136 , & V_80 , 1 ) ;
return 0 ;
}
static inline void F_74 ( struct V_16 * V_17 )
{
V_17 -> V_127 = ( V_17 -> V_127 + 1 ) % V_17 -> V_137 ;
}
static void F_72 ( struct V_16 * V_17 )
{
V_17 -> V_137 = 0 ;
}
static void F_75 ( struct V_16 * V_17 , T_1 V_138 )
{
V_17 -> V_139 [ V_17 -> V_137 ] =
(struct V_140 * ) & V_141 [ V_138 ] ;
V_17 -> V_137 ++ ;
}
static void F_76 ( struct V_16 * V_17 ,
T_4 V_142 , T_4 V_143 )
{
F_72 ( V_17 ) ;
if ( ( V_142 & V_87 ) ||
( V_142 & V_89 ) ||
( V_142 & V_91 ) )
F_75 ( V_17 , V_128 ) ;
if ( V_142 & V_105 ||
V_142 & V_91 ) {
F_75 ( V_17 , V_129 ) ;
F_75 ( V_17 , V_130 ) ;
}
if ( V_142 & V_113 )
F_75 ( V_17 , V_131 ) ;
if ( V_142 & V_123 )
F_75 ( V_17 , V_132 ) ;
if ( V_143 )
F_75 ( V_17 , V_144 ) ;
}
static int F_77 ( struct V_16 * V_17 , struct V_31 * V_41 )
{
T_1 V_145 , V_124 , * V_125 ;
int V_43 , V_126 ;
if ( V_17 -> V_133 & V_91 )
V_17 -> V_146 = 1 ;
V_145 = V_41 -> V_2 [ 0 ] ;
V_124 = V_41 -> V_2 [ 1 ] ;
V_125 = & V_41 -> V_2 [ 2 ] ;
V_126 = V_41 -> V_15 - 2 ;
if ( V_145 ) {
V_43 = F_70 ( V_17 , V_124 , V_125 , V_126 ) ;
if ( V_43 == 0 )
return 0 ;
}
return - V_134 ;
}
static struct V_31 * F_78 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
T_1 * V_98 , * V_147 ;
T_1 * V_148 = V_17 -> V_149 ;
T_5 V_150 = V_17 -> V_151 ;
T_1 V_152 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_153 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_154 = 36 +
V_150 +
1 ;
V_32 = F_54 ( V_17 , V_154 ) ;
if ( ! V_32 )
return NULL ;
F_79 ( V_32 , V_155 ) ;
F_80 ( V_32 , V_153 , 6 ) ;
V_98 = F_80 ( V_32 , V_152 , 18 ) ;
F_81 ( V_98 + 2 , 6 ) ;
V_147 = F_82 ( V_32 , 10 ) ;
memcpy ( V_147 , V_98 , 8 ) ;
F_79 ( V_32 , V_150 ) ;
F_80 ( V_32 , V_148 , V_150 ) ;
F_79 ( V_32 , 0 ) ;
return V_32 ;
}
static int F_83 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
struct V_31 * V_32 ;
T_1 V_42 , V_156 , V_157 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) ) {
F_84 ( & V_17 -> V_158 ) ;
return F_85 ( V_41 ) ;
}
V_42 = V_41 -> V_2 [ 0 ] ;
V_156 = V_42 & V_159 ;
V_157 = V_42 & V_160 ;
F_30 ( V_41 , sizeof( V_42 ) ) ;
if ( V_156 != V_161 ) {
V_43 = - V_162 ;
goto error;
}
F_86 ( & V_17 -> V_158 , V_41 ) ;
if ( V_157 ) {
F_44 ( V_17 -> V_64 , & V_17 -> V_163 ) ;
return - V_63 ;
}
V_32 = F_87 ( V_17 ) ;
if ( ! V_32 ) {
V_43 = - V_162 ;
goto error;
}
return F_88 ( V_17 -> V_136 , V_32 ) ;
error:
F_89 ( V_17 -> V_136 ) ;
V_17 -> V_164 = 0 ;
F_84 ( & V_17 -> V_158 ) ;
F_27 ( V_41 ) ;
return V_43 ;
}
static void F_90 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_163 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , 0 ) ;
if ( ! V_32 )
return;
V_43 = F_41 ( V_17 ,
V_165 ,
V_32 ,
F_83 ,
NULL ) ;
if ( V_43 < 0 )
F_27 ( V_32 ) ;
}
static void F_91 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_166 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_92 ( & V_17 -> V_167 ) ;
if ( V_32 == NULL ) {
F_93 ( & V_17 -> V_167 ) ;
goto error;
}
if ( F_94 ( & V_17 -> V_167 ) == 0 ) {
V_43 = F_41 ( V_17 , V_168 ,
V_32 , V_169 , NULL ) ;
} else
V_43 = F_41 ( V_17 ,
V_170 ,
V_32 , V_169 , NULL ) ;
if ( V_43 == 0 )
return;
F_95 ( V_17 -> V_17 ,
L_9 , V_43 ) ;
F_27 ( V_32 ) ;
error:
V_17 -> V_55 -> V_171 ( V_17 , V_51 ) ;
F_44 ( V_17 -> V_64 , & V_17 -> V_65 ) ;
}
static void F_96 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_172 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , 0 ) ;
if ( ! V_32 )
return;
V_43 = F_39 ( V_17 , V_165 , V_32 ,
F_83 , NULL ) ;
if ( V_43 < 0 )
F_27 ( V_32 ) ;
}
static int F_97 ( struct V_16 * V_17 , struct V_31 * V_41 )
{
T_1 V_173 , * V_29 , V_174 = V_175 , * V_149 ;
T_5 V_151 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( V_41 -> V_15 < V_176 + 1 )
return - V_177 ;
V_173 = V_41 -> V_2 [ 0 ] ;
V_29 = & V_41 -> V_2 [ 1 ] ;
F_26 ( V_17 -> V_17 , L_10 ,
V_173 , V_41 -> V_15 ) ;
if ( ( V_173 & V_178 ) ==
V_179 )
V_174 = V_180 ;
if ( ( V_173 & V_181 ) == 0 )
return - V_182 ;
V_149 = V_29 + V_176 ;
V_151 = V_41 -> V_15 - ( V_176 + 1 ) ;
V_43 = F_98 ( V_17 -> V_136 , V_91 ,
V_174 , V_149 , V_151 ) ;
if ( V_43 < 0 ) {
F_71 ( V_17 -> V_17 ,
L_11 ) ;
return V_43 ;
}
V_17 -> V_164 = 1 ;
F_44 ( V_17 -> V_64 , & V_17 -> V_172 ) ;
return 0 ;
}
static void F_99 ( unsigned long V_2 )
{
struct V_16 * V_17 = (struct V_16 * ) V_2 ;
F_26 ( V_17 -> V_17 , L_12 ) ;
V_17 -> V_183 = 1 ;
F_74 ( V_17 ) ;
F_100 ( V_17 -> V_64 , & V_17 -> V_184 ,
F_101 ( V_185 ) ) ;
}
static int F_102 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
int V_43 = 0 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) ) {
V_43 = F_85 ( V_41 ) ;
F_71 ( V_17 -> V_17 , L_13 , V_43 ) ;
return V_43 ;
}
F_100 ( V_17 -> V_64 , & V_17 -> V_184 ,
F_101 ( V_185 ) ) ;
F_27 ( V_41 ) ;
return V_43 ;
}
static void F_103 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_186 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , 2 ) ;
if ( ! V_32 )
return;
F_79 ( V_32 , V_187 ) ;
F_79 ( V_32 , V_188 ) ;
V_43 = F_40 ( V_17 , V_189 , V_32 ,
F_102 , NULL ) ;
if ( V_43 < 0 ) {
F_27 ( V_32 ) ;
F_71 ( V_17 -> V_17 , L_13 , V_43 ) ;
}
}
static int F_104 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
struct V_190 * V_191 ;
struct V_79 V_79 ;
T_1 V_192 ;
int V_43 ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
V_191 = (struct V_190 * ) V_41 -> V_2 ;
V_43 = V_191 -> V_42 & V_159 ;
if ( V_43 != V_161 ) {
F_44 ( V_17 -> V_64 , & V_17 -> V_186 ) ;
F_27 ( V_41 ) ;
return 0 ;
}
F_26 ( V_17 -> V_17 , L_14 ) ;
V_79 . V_86 = V_91 ;
V_79 . V_93 = 10 ;
memcpy ( V_79 . V_95 , V_191 -> V_193 , V_79 . V_93 ) ;
V_43 = F_73 ( V_17 -> V_136 , & V_79 , 1 ) ;
if ( V_43 )
goto error;
V_17 -> V_135 = 0 ;
V_17 -> V_194 = V_195 ;
V_192 = V_41 -> V_15 - 17 ;
V_43 = F_105 ( V_17 -> V_136 ,
V_191 -> V_196 , V_192 ) ;
if ( ! V_43 ) {
V_43 = F_106 ( V_17 -> V_136 ,
V_17 -> V_136 -> V_197 [ 0 ] . V_198 ,
0 , V_199 ) ;
if ( ! V_43 )
F_72 ( V_17 ) ;
}
error:
F_27 ( V_41 ) ;
return V_43 ;
}
static int F_107 ( struct V_136 * V_136 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_31 * V_32 ;
int V_43 , V_154 ;
T_1 * V_200 , V_147 [ V_201 ] ;
T_1 V_202 [ V_203 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_26 ( V_17 -> V_17 , L_15 , V_44 ) ;
if ( ! V_17 -> V_149 ) {
V_17 -> V_149 = F_109 ( V_136 , & V_17 -> V_151 ) ;
if ( ! V_17 -> V_149 || ! V_17 -> V_151 ) {
V_17 -> V_146 = 0 ;
F_44 ( V_17 -> V_64 , & V_17 -> V_186 ) ;
}
}
V_154 = 3 + V_17 -> V_151 ;
V_154 += V_203 ;
V_154 += V_201 ;
V_147 [ 0 ] = 0x1 ;
V_147 [ 1 ] = 0xfe ;
F_81 ( V_147 + 2 , 6 ) ;
V_32 = F_54 ( V_17 , V_154 ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , 0x01 ) ;
F_79 ( V_32 , 0x02 ) ;
V_200 = F_24 ( V_32 , 1 ) ;
* V_200 = 0 ;
F_80 ( V_32 , V_202 , V_203 ) ;
* V_200 |= 1 ;
F_80 ( V_32 , V_147 , V_201 ) ;
* V_200 |= 2 ;
F_80 ( V_32 , V_17 -> V_149 , V_17 -> V_151 ) ;
* V_200 |= 4 ;
V_43 = F_40 ( V_17 , V_204 , V_32 ,
F_104 , NULL ) ;
if ( V_43 < 0 )
F_27 ( V_32 ) ;
return V_43 ;
}
static int F_110 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
struct V_140 * V_205 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) ) {
V_43 = F_85 ( V_41 ) ;
F_71 ( V_17 -> V_17 , L_16 ,
V_44 , V_43 ) ;
if ( V_43 == - V_206 ) {
if ( V_17 -> V_137 != 0 )
return V_43 ;
goto V_207;
} else if ( V_43 < 0 ) {
F_71 ( V_17 -> V_17 ,
L_17 , V_43 ) ;
goto V_207;
}
}
V_205 = V_17 -> V_139 [ V_17 -> V_127 ] ;
if ( V_205 -> V_15 == 0 ) {
F_111 ( & V_17 -> V_208 ) ;
V_43 = F_97 ( V_17 , V_41 ) ;
goto V_45;
}
V_43 = F_77 ( V_17 , V_41 ) ;
if ( ! V_43 )
goto V_45;
if ( ! V_17 -> V_137 ) {
F_26 ( V_17 -> V_17 , L_18 ) ;
goto V_45;
}
F_74 ( V_17 ) ;
F_44 ( V_17 -> V_64 , & V_17 -> V_186 ) ;
V_45:
F_27 ( V_41 ) ;
return V_43 ;
V_207:
F_71 ( V_17 -> V_17 , L_19 ) ;
F_72 ( V_17 ) ;
V_17 -> V_133 = 0 ;
return V_43 ;
}
static struct V_31 * F_112 ( struct V_16 * V_17 ,
struct V_140 * V_209 )
{
struct V_31 * V_32 ;
V_32 = F_54 ( V_17 , V_209 -> V_15 ) ;
if ( ! V_32 )
return NULL ;
F_80 ( V_32 , & V_209 -> V_2 , V_209 -> V_15 ) ;
return V_32 ;
}
static int F_113 ( struct V_16 * V_17 )
{
struct V_140 * V_209 ;
struct V_31 * V_32 ;
int V_43 ;
T_1 V_7 ;
V_209 = V_17 -> V_139 [ V_17 -> V_127 ] ;
F_26 ( V_17 -> V_17 , L_20 ,
V_44 , V_209 -> V_15 ) ;
if ( ( V_17 -> V_133 & V_91 ) && V_17 -> V_146 ) {
V_17 -> V_146 = 0 ;
return F_107 ( V_17 -> V_136 ) ;
}
if ( V_209 -> V_15 == 0 ) {
V_7 = V_210 ;
V_32 = F_78 ( V_17 ) ;
} else {
V_7 = V_211 ;
V_32 = F_112 ( V_17 , V_209 ) ;
}
if ( ! V_32 ) {
F_71 ( V_17 -> V_17 , L_21 ) ;
return - V_52 ;
}
V_43 = F_40 ( V_17 , V_7 , V_32 , F_110 ,
NULL ) ;
if ( V_43 < 0 ) {
F_27 ( V_32 ) ;
F_71 ( V_17 -> V_17 , L_22 , V_43 ) ;
}
return V_43 ;
}
static void F_114 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_184 . V_61 ) ;
struct V_140 * V_205 ;
int V_43 ;
V_205 = V_17 -> V_139 [ V_17 -> V_127 ] ;
F_26 ( V_17 -> V_17 ,
L_23 ,
V_44 , V_17 -> V_183 , V_205 -> V_15 ) ;
if ( V_17 -> V_183 == 1 ) {
V_17 -> V_183 = 0 ;
V_17 -> V_55 -> V_212 ( V_17 , V_213 ) ;
}
V_43 = F_113 ( V_17 ) ;
if ( V_43 )
return;
if ( V_205 -> V_15 == 0 && V_17 -> V_137 > 1 )
F_115 ( & V_17 -> V_208 , V_214 + V_215 * V_216 ) ;
}
static int F_116 ( struct V_136 * V_136 ,
T_4 V_142 , T_4 V_143 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_140 * V_205 ;
T_1 V_217 ;
int V_43 ;
F_26 ( V_17 -> V_17 ,
L_24 ,
V_44 , V_142 , V_143 ) ;
if ( V_17 -> V_194 ) {
F_71 ( V_17 -> V_17 ,
L_25 ) ;
return - V_218 ;
}
if ( V_17 -> V_164 ) {
F_71 ( V_17 -> V_17 ,
L_26 ) ;
return - V_218 ;
}
if ( V_143 ) {
V_17 -> V_149 = F_109 ( V_136 , & V_17 -> V_151 ) ;
if ( V_17 -> V_149 == NULL )
V_143 = 0 ;
}
F_76 ( V_17 , V_142 , V_143 ) ;
V_17 -> V_133 = V_142 ;
V_17 -> V_219 = V_143 ;
F_81 ( & V_217 , sizeof( V_217 ) ) ;
V_217 %= V_17 -> V_137 ;
V_17 -> V_127 = V_217 ;
V_205 = V_17 -> V_139 [ V_17 -> V_127 ] ;
V_43 = F_113 ( V_17 ) ;
if ( ! V_43 && V_205 -> V_15 == 0 && V_17 -> V_137 > 1 )
F_115 ( & V_17 -> V_208 , V_214 + V_215 * V_216 ) ;
return V_43 ;
}
static void F_117 ( struct V_136 * V_136 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
F_111 ( & V_17 -> V_208 ) ;
if ( ! V_17 -> V_137 ) {
F_26 ( V_17 -> V_17 ,
L_27 ) ;
return;
}
V_17 -> V_55 -> V_212 ( V_17 , V_51 ) ;
F_118 ( & V_17 -> V_184 ) ;
F_72 ( V_17 ) ;
}
static int F_119 ( struct V_16 * V_17 )
{
struct V_220 * V_191 ;
T_2 V_221 ;
int V_43 ;
struct V_31 * V_32 ;
struct V_31 * V_41 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , sizeof( T_1 ) * 2 ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , 1 ) ;
F_79 ( V_32 , 0 ) ;
V_41 = F_51 ( V_17 , V_222 , V_32 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
V_191 = (struct V_220 * ) V_41 -> V_2 ;
V_43 = V_191 -> V_42 & V_159 ;
if ( V_43 != V_161 ) {
F_71 ( V_17 -> V_17 ,
L_28 , V_43 ) ;
F_27 ( V_41 ) ;
return - V_162 ;
}
V_221 = V_41 -> V_15 - 16 ;
V_43 = F_105 ( V_17 -> V_136 , V_191 -> V_196 , V_221 ) ;
F_27 ( V_41 ) ;
return V_43 ;
}
static int F_120 ( struct V_136 * V_136 ,
struct V_79 * V_223 , T_4 V_224 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_29 , V_44 , V_224 ) ;
if ( V_17 -> V_137 ) {
F_71 ( V_17 -> V_17 ,
L_30 ) ;
return - V_218 ;
}
if ( V_17 -> V_194 ) {
F_71 ( V_17 -> V_17 ,
L_31 ) ;
return - V_218 ;
}
if ( ! V_17 -> V_135 ) {
F_71 ( V_17 -> V_17 ,
L_32 ) ;
return - V_177 ;
}
if ( ! ( V_17 -> V_135 & ( 1 << V_224 ) ) ) {
F_71 ( V_17 -> V_17 ,
L_33 ,
V_224 ) ;
return - V_177 ;
}
if ( V_224 == V_195 ) {
V_43 = F_119 ( V_17 ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 ,
L_34 , V_43 ) ;
return V_43 ;
}
}
V_17 -> V_194 = V_224 ;
V_17 -> V_135 = 0 ;
return 0 ;
}
static int F_121 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
int V_43 = 0 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) ) {
V_43 = F_85 ( V_41 ) ;
F_71 ( V_17 -> V_17 , L_35 , V_43 ) ;
return V_43 ;
}
V_43 = V_41 -> V_2 [ 0 ] & V_159 ;
if ( V_43 != V_161 )
F_71 ( V_17 -> V_17 ,
L_36 , V_43 ) ;
F_27 ( V_41 ) ;
return V_43 ;
}
static void F_122 ( struct V_136 * V_136 ,
struct V_79 * V_223 , T_1 V_173 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( ! V_17 -> V_194 ) {
F_71 ( V_17 -> V_17 , L_37 ) ;
return;
}
V_17 -> V_194 = 0 ;
F_84 ( & V_17 -> V_158 ) ;
V_32 = F_54 ( V_17 , sizeof( T_1 ) ) ;
if ( ! V_32 )
return;
F_79 ( V_32 , 1 ) ;
V_43 = F_40 ( V_17 , V_225 , V_32 ,
F_121 , NULL ) ;
if ( V_43 < 0 ) {
F_27 ( V_32 ) ;
F_71 ( V_17 -> V_17 , L_35 , V_43 ) ;
}
}
static int F_123 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
struct V_190 * V_191 ;
T_1 V_192 ;
int V_43 ;
T_1 V_226 = * ( T_1 * ) V_68 ;
F_32 ( V_68 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
if ( V_17 -> V_135 &&
! ( V_17 -> V_135 & ( 1 << V_195 ) ) ) {
F_71 ( V_17 -> V_17 ,
L_38 ) ;
V_43 = - V_177 ;
goto error;
}
V_191 = (struct V_190 * ) V_41 -> V_2 ;
V_43 = V_191 -> V_42 & V_159 ;
if ( V_43 != V_161 ) {
F_71 ( V_17 -> V_17 ,
L_39 , V_43 ) ;
goto error;
}
if ( ! V_17 -> V_135 ) {
struct V_79 V_79 ;
F_26 ( V_17 -> V_17 , L_40 ) ;
V_79 . V_86 = V_91 ;
V_79 . V_93 = 10 ;
memcpy ( V_79 . V_95 , V_191 -> V_193 , V_79 . V_93 ) ;
V_43 = F_73 ( V_17 -> V_136 , & V_79 , 1 ) ;
if ( V_43 )
goto error;
V_17 -> V_135 = 0 ;
}
V_17 -> V_194 = V_195 ;
V_192 = V_41 -> V_15 - 17 ;
V_43 = F_105 ( V_17 -> V_136 ,
V_191 -> V_196 , V_192 ) ;
if ( V_43 == 0 )
V_43 = F_106 ( V_17 -> V_136 ,
V_17 -> V_136 -> V_197 [ 0 ] . V_198 ,
! V_226 , V_199 ) ;
error:
F_27 ( V_41 ) ;
return V_43 ;
}
static int F_124 ( struct V_136 * V_136 , struct V_79 * V_223 ,
T_1 V_174 , T_1 * V_149 , T_5 V_151 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_31 * V_32 ;
int V_43 , V_154 ;
T_1 * V_200 , * V_68 , V_147 [ V_201 ] ;
T_1 V_202 [ V_203 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( V_17 -> V_137 ) {
F_71 ( V_17 -> V_17 ,
L_41 ) ;
return - V_218 ;
}
if ( V_17 -> V_194 ) {
F_71 ( V_17 -> V_17 ,
L_31 ) ;
return - V_218 ;
}
V_154 = 3 + V_151 ;
V_154 += V_203 ;
V_154 += V_201 ;
if ( V_223 && ! V_223 -> V_109 ) {
V_147 [ 0 ] = 0x1 ;
V_147 [ 1 ] = 0xfe ;
F_81 ( V_147 + 2 , 6 ) ;
}
V_32 = F_54 ( V_17 , V_154 ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , ! V_174 ) ;
F_79 ( V_32 , 0x02 ) ;
V_200 = F_24 ( V_32 , 1 ) ;
* V_200 = 0 ;
F_80 ( V_32 , V_202 , V_203 ) ;
* V_200 |= 1 ;
if ( V_223 && V_223 -> V_109 )
memcpy ( F_24 ( V_32 , V_201 ) , V_223 -> V_102 ,
V_223 -> V_109 ) ;
else
F_80 ( V_32 , V_147 , V_201 ) ;
* V_200 |= 2 ;
if ( V_149 != NULL && V_151 > 0 ) {
F_80 ( V_32 , V_149 , V_151 ) ;
* V_200 |= 4 ;
} else {
* V_200 = 0 ;
}
V_68 = F_125 ( sizeof( * V_68 ) , V_51 ) ;
if ( ! V_68 ) {
F_27 ( V_32 ) ;
return - V_52 ;
}
* V_68 = ! V_174 ;
F_126 ( V_17 -> V_136 , 0 ) ;
V_43 = F_40 ( V_17 , V_204 , V_32 ,
F_123 , V_68 ) ;
if ( V_43 < 0 ) {
F_27 ( V_32 ) ;
F_32 ( V_68 ) ;
}
return V_43 ;
}
static int F_127 ( struct V_136 * V_136 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
F_72 ( V_17 ) ;
if ( V_17 -> V_164 || V_17 -> V_194 )
V_17 -> V_55 -> V_212 ( V_17 , V_51 ) ;
V_17 -> V_194 = 0 ;
V_17 -> V_164 = 0 ;
F_84 ( & V_17 -> V_158 ) ;
return 0 ;
}
static struct V_31 * F_87 ( struct V_16 * V_17 )
{
struct V_31 * V_32 , * V_227 , * V_228 ;
unsigned int V_154 = 0 , V_229 = 0 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_128 ( & V_17 -> V_158 ) )
return NULL ;
if ( F_94 ( & V_17 -> V_158 ) == 1 ) {
V_32 = F_92 ( & V_17 -> V_158 ) ;
goto V_230;
}
F_129 (&dev->resp_q, tmp, t)
V_154 += V_227 -> V_15 ;
F_26 ( V_17 -> V_17 , L_42 ,
V_44 , V_154 ) ;
V_32 = F_55 ( V_154 , V_51 ) ;
if ( V_32 == NULL )
goto V_230;
F_24 ( V_32 , V_154 ) ;
F_129 (&dev->resp_q, tmp, t) {
memcpy ( V_32 -> V_2 + V_229 , V_227 -> V_2 , V_227 -> V_15 ) ;
V_229 += V_227 -> V_15 ;
}
V_230:
F_84 ( & V_17 -> V_158 ) ;
return V_32 ;
}
static int F_130 ( struct V_16 * V_17 , void * V_66 ,
struct V_31 * V_41 )
{
struct V_231 * V_68 = V_66 ;
struct V_31 * V_32 ;
int V_43 = 0 ;
T_1 V_42 , V_156 , V_157 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) ) {
V_43 = F_85 ( V_41 ) ;
goto V_232;
}
V_42 = V_41 -> V_2 [ 0 ] ;
V_156 = V_42 & V_159 ;
V_157 = V_42 & V_160 ;
F_30 ( V_41 , sizeof( V_42 ) ) ;
if ( V_156 != V_161 ) {
F_71 ( V_17 -> V_17 ,
L_43 , V_156 ) ;
V_43 = - V_162 ;
goto error;
}
F_86 ( & V_17 -> V_158 , V_41 ) ;
if ( V_157 ) {
V_17 -> V_233 = V_68 ;
F_44 ( V_17 -> V_64 , & V_17 -> V_234 ) ;
return - V_63 ;
}
if ( F_94 ( & V_17 -> V_167 ) > 0 ) {
V_17 -> V_235 = V_68 ;
F_44 ( V_17 -> V_64 , & V_17 -> V_236 ) ;
return - V_63 ;
}
V_32 = F_87 ( V_17 ) ;
if ( ! V_32 ) {
V_43 = - V_52 ;
goto error;
}
V_68 -> V_237 ( V_68 -> V_238 , V_32 , 0 ) ;
F_32 ( V_68 ) ;
return 0 ;
error:
F_27 ( V_41 ) ;
V_232:
F_84 ( & V_17 -> V_158 ) ;
V_68 -> V_237 ( V_68 -> V_238 , NULL , V_43 ) ;
F_32 ( V_68 ) ;
return V_43 ;
}
void F_131 ( struct V_16 * V_17 , struct V_31 * V_32 , int V_42 )
{
if ( ! V_17 -> V_29 )
goto V_239;
V_17 -> V_29 -> V_42 = V_42 ;
if ( V_42 != 0 ) {
F_26 ( V_17 -> V_17 , L_44 , V_44 , V_42 ) ;
goto V_239;
}
if ( V_32 == NULL ) {
F_132 ( L_45 ) ;
goto V_239;
}
if ( F_17 ( V_32 -> V_2 ) ) {
F_26 ( V_17 -> V_17 , L_46 , V_44 ) ;
F_27 ( V_32 ) ;
return;
}
F_133 ( L_47 , V_240 , 16 , 1 , V_32 -> V_2 ,
V_17 -> V_20 -> V_241 ( V_32 -> V_2 ) , false ) ;
if ( ! V_17 -> V_20 -> V_242 ( V_32 -> V_2 , V_17 ) ) {
F_71 ( V_17 -> V_17 , L_48 ) ;
V_17 -> V_29 -> V_42 = - V_162 ;
} else if ( ! F_20 ( V_17 , V_32 -> V_2 ) ) {
F_71 ( V_17 -> V_17 , L_49 ) ;
V_17 -> V_29 -> V_42 = - V_162 ;
}
V_17 -> V_29 -> V_41 = V_32 ;
V_239:
F_44 ( V_17 -> V_64 , & V_17 -> V_62 ) ;
}
static int F_134 ( struct V_16 * V_17 , struct V_31 * V_32 )
{
struct V_31 * V_243 ;
int V_244 ;
do {
if ( V_32 -> V_15 > V_245 )
V_244 = V_245 ;
else
V_244 = V_32 -> V_15 ;
V_243 = F_54 ( V_17 , V_244 ) ;
if ( ! V_243 ) {
F_84 ( & V_17 -> V_167 ) ;
break;
}
if ( ! V_17 -> V_164 ) {
F_56 ( V_243 , 1 ) ;
if ( V_244 == V_245 )
* ( T_1 * ) F_23 ( V_243 , sizeof( T_1 ) ) =
( V_160 | 1 ) ;
else
* ( T_1 * ) F_23 ( V_243 , sizeof( T_1 ) ) = 1 ;
}
F_80 ( V_243 , V_32 -> V_2 , V_244 ) ;
F_30 ( V_32 , V_244 ) ;
F_86 ( & V_17 -> V_167 , V_243 ) ;
} while ( V_32 -> V_15 > 0 );
F_27 ( V_32 ) ;
return F_94 ( & V_17 -> V_167 ) ;
}
static int F_135 ( struct V_136 * V_136 ,
struct V_79 * V_223 , struct V_31 * V_32 ,
T_6 V_237 , void * V_238 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_231 * V_68 = NULL ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( ! V_17 -> V_194 ) {
F_71 ( V_17 -> V_17 ,
L_50 ) ;
V_43 = - V_177 ;
goto error;
}
V_68 = F_125 ( sizeof( * V_68 ) , V_51 ) ;
if ( ! V_68 ) {
V_43 = - V_52 ;
goto error;
}
V_68 -> V_237 = V_237 ;
V_68 -> V_238 = V_238 ;
switch ( V_17 -> V_246 ) {
case V_247 :
if ( V_17 -> V_194 == V_248 ) {
V_43 = F_39 ( V_17 , V_249 ,
V_32 ,
F_130 ,
V_68 ) ;
break;
}
default:
if ( V_32 -> V_15 > V_250 ) {
V_43 = F_134 ( V_17 , V_32 ) ;
if ( V_43 <= 0 )
goto error;
V_32 = F_92 ( & V_17 -> V_167 ) ;
if ( ! V_32 ) {
V_43 = - V_162 ;
goto error;
}
} else {
* ( T_1 * ) F_23 ( V_32 , sizeof( T_1 ) ) = 1 ;
}
V_43 = F_39 ( V_17 , V_251 ,
V_32 , F_130 ,
V_68 ) ;
break;
}
if ( V_43 < 0 )
goto error;
return 0 ;
error:
F_32 ( V_68 ) ;
F_27 ( V_32 ) ;
return V_43 ;
}
static int V_169 ( struct V_16 * V_17 , void * V_68 ,
struct V_31 * V_41 )
{
T_1 V_42 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
V_42 = V_41 -> V_2 [ 0 ] ;
if ( F_94 ( & V_17 -> V_167 ) > 0 ) {
F_44 ( V_17 -> V_64 , & V_17 -> V_166 ) ;
return - V_63 ;
}
F_27 ( V_41 ) ;
if ( V_42 != 0 ) {
F_89 ( V_17 -> V_136 ) ;
V_17 -> V_164 = 0 ;
return 0 ;
}
F_44 ( V_17 -> V_64 , & V_17 -> V_172 ) ;
return 0 ;
}
static int F_136 ( struct V_136 * V_136 , struct V_31 * V_32 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
if ( V_32 -> V_15 > V_250 ) {
V_43 = F_134 ( V_17 , V_32 ) ;
if ( V_43 <= 0 )
goto error;
V_32 = F_92 ( & V_17 -> V_167 ) ;
if ( ! V_32 ) {
V_43 = - V_162 ;
goto error;
}
V_43 = F_39 ( V_17 , V_170 , V_32 ,
V_169 , NULL ) ;
} else {
V_43 = F_39 ( V_17 , V_168 , V_32 ,
V_169 , NULL ) ;
}
error:
if ( V_43 < 0 ) {
F_27 ( V_32 ) ;
F_84 ( & V_17 -> V_167 ) ;
}
return V_43 ;
}
static void F_137 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_234 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , V_252 ) ;
if ( ! V_32 )
goto error;
switch ( V_17 -> V_246 ) {
case V_247 :
if ( V_17 -> V_194 == V_248 ) {
V_43 = F_41 ( V_17 ,
V_249 ,
V_32 ,
F_130 ,
V_17 -> V_233 ) ;
break;
}
default:
F_79 ( V_32 , 1 ) ;
V_43 = F_41 ( V_17 ,
V_251 ,
V_32 ,
F_130 ,
V_17 -> V_233 ) ;
break;
}
if ( V_43 == 0 )
return;
F_71 ( V_17 -> V_17 ,
L_51 , V_43 ) ;
F_27 ( V_32 ) ;
F_32 ( V_17 -> V_233 ) ;
error:
V_17 -> V_55 -> V_171 ( V_17 , V_51 ) ;
F_44 ( V_17 -> V_64 , & V_17 -> V_65 ) ;
}
static void F_138 ( struct V_60 * V_61 )
{
struct V_16 * V_17 = F_43 ( V_61 , struct V_16 , V_236 ) ;
struct V_31 * V_32 ;
int V_43 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_92 ( & V_17 -> V_167 ) ;
if ( V_32 == NULL ) {
F_93 ( & V_17 -> V_167 ) ;
goto error;
}
switch ( V_17 -> V_246 ) {
case V_247 :
if ( V_17 -> V_194 != V_248 ) {
V_43 = - V_162 ;
break;
}
V_43 = F_41 ( V_17 , V_249 ,
V_32 ,
F_130 ,
V_17 -> V_235 ) ;
break;
default:
V_43 = F_41 ( V_17 ,
V_251 ,
V_32 ,
F_130 ,
V_17 -> V_235 ) ;
break;
}
if ( V_43 == 0 )
return;
F_71 ( V_17 -> V_17 ,
L_51 , V_43 ) ;
F_27 ( V_32 ) ;
F_32 ( V_17 -> V_235 ) ;
error:
V_17 -> V_55 -> V_171 ( V_17 , V_51 ) ;
F_44 ( V_17 -> V_64 , & V_17 -> V_65 ) ;
}
static int F_139 ( struct V_16 * V_17 , T_1 V_253 , T_1 * V_254 ,
T_1 V_255 )
{
struct V_31 * V_32 ;
struct V_31 * V_41 ;
int V_154 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_154 = sizeof( V_253 ) + V_255 ;
V_32 = F_54 ( V_17 , V_154 ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , V_253 ) ;
F_80 ( V_32 , V_254 , V_255 ) ;
V_41 = F_51 ( V_17 , V_189 , V_32 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
F_27 ( V_41 ) ;
return 0 ;
}
static int F_140 ( struct V_16 * V_17 ,
struct V_256 * V_257 )
{
struct V_31 * V_32 ;
struct V_31 * V_41 ;
V_32 = F_54 ( V_17 , 0 ) ;
if ( ! V_32 )
return - V_52 ;
V_41 = F_51 ( V_17 , V_258 , V_32 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
V_257 -> V_259 = V_41 -> V_2 [ 0 ] ;
V_257 -> V_260 = V_41 -> V_2 [ 1 ] ;
V_257 -> V_261 = V_41 -> V_2 [ 2 ] ;
V_257 -> V_262 = V_41 -> V_2 [ 3 ] ;
F_27 ( V_41 ) ;
return 0 ;
}
static int F_141 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
struct V_31 * V_41 ;
F_26 ( V_17 -> V_17 , L_8 , V_44 ) ;
V_32 = F_54 ( V_17 , sizeof( T_1 ) ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , 0x1 ) ;
V_41 = F_51 ( V_17 , 0x18 , V_32 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
F_27 ( V_41 ) ;
return 0 ;
}
static int F_126 ( struct V_136 * V_136 , T_1 V_263 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
T_1 V_264 = ! ! V_263 ;
int V_43 ;
V_264 |= V_188 ;
V_43 = F_139 ( V_17 , V_187 ,
( T_1 * ) & V_264 , 1 ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 , L_52 ) ;
return V_43 ;
}
return V_43 ;
}
static int F_142 ( struct V_136 * V_136 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
struct V_31 * V_32 ;
struct V_31 * V_41 ;
V_32 = F_54 ( V_17 , 1 ) ;
if ( ! V_32 )
return - V_52 ;
F_79 ( V_32 , 0x01 ) ;
V_41 = F_51 ( V_17 , V_265 , V_32 ) ;
if ( F_29 ( V_41 ) )
return F_85 ( V_41 ) ;
F_27 ( V_41 ) ;
return 0 ;
}
static int F_143 ( struct V_136 * V_136 )
{
struct V_16 * V_17 = F_108 ( V_136 ) ;
if ( V_17 -> V_246 == V_266 ) {
int V_43 = F_142 ( V_136 ) ;
if ( V_43 )
return V_43 ;
}
return F_126 ( V_136 , 1 ) ;
}
static int F_144 ( struct V_136 * V_136 )
{
return F_126 ( V_136 , 0 ) ;
}
static int F_145 ( struct V_16 * V_17 )
{
struct V_267 V_268 ;
struct V_269 V_270 ;
T_1 V_271 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_43 ;
switch ( V_17 -> V_246 ) {
case V_272 :
case V_247 :
case V_273 :
case V_266 :
V_268 . V_274 = 0x2 ;
V_268 . V_275 = 0x1 ;
V_268 . V_276 =
V_277 ;
V_270 . V_278 = V_279 ;
V_270 . V_280 = V_279 ;
V_270 . V_281 = V_282 ;
break;
default:
F_71 ( V_17 -> V_17 , L_53 ,
V_17 -> V_246 ) ;
return - V_177 ;
}
V_43 = F_139 ( V_17 , V_283 ,
( T_1 * ) & V_268 , sizeof( V_268 ) ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 ,
L_54 ) ;
return V_43 ;
}
V_43 = F_139 ( V_17 , V_284 ,
( T_1 * ) & V_270 , sizeof( V_270 ) ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 , L_55 ) ;
return V_43 ;
}
switch ( V_17 -> V_246 ) {
case V_272 :
case V_266 :
break;
case V_247 :
F_141 ( V_17 ) ;
V_43 = F_139 ( V_17 , V_285 ,
V_271 , 3 ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 ,
L_56 ) ;
return V_43 ;
}
F_141 ( V_17 ) ;
break;
}
return 0 ;
}
int F_146 ( struct V_16 * V_17 )
{
struct V_256 V_286 ;
int V_43 ;
memset ( & V_286 , 0 , sizeof( V_286 ) ) ;
V_43 = F_140 ( V_17 , & V_286 ) ;
if ( V_43 ) {
F_71 ( V_17 -> V_17 , L_57 ) ;
return V_43 ;
}
F_147 ( V_17 -> V_17 , L_58 ,
V_286 . V_259 , V_286 . V_260 , V_286 . V_261 ) ;
V_43 = F_145 ( V_17 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
struct V_16 * F_148 ( T_4 V_246 ,
T_4 V_287 ,
enum V_288 V_289 ,
void * V_290 ,
struct V_291 * V_55 ,
struct V_34 * V_292 ,
struct V_293 * V_17 ,
struct V_293 * V_294 )
{
struct V_16 * V_295 ;
int V_43 = - V_52 ;
V_295 = F_34 ( sizeof( * V_295 ) , V_51 ) ;
if ( ! V_295 )
return F_28 ( - V_52 ) ;
V_295 -> V_290 = V_290 ;
V_295 -> V_55 = V_55 ;
V_295 -> V_17 = V_17 ;
if ( V_292 != NULL )
V_295 -> V_20 = V_292 ;
else
V_295 -> V_20 = & V_296 ;
V_295 -> V_289 = V_289 ;
V_295 -> V_246 = V_246 ;
F_149 ( & V_295 -> V_53 ) ;
F_150 ( & V_295 -> V_65 , F_45 ) ;
F_150 ( & V_295 -> V_62 , F_42 ) ;
F_150 ( & V_295 -> V_234 , F_137 ) ;
F_150 ( & V_295 -> V_236 , F_138 ) ;
F_150 ( & V_295 -> V_172 , F_96 ) ;
F_150 ( & V_295 -> V_163 , F_90 ) ;
F_150 ( & V_295 -> V_166 , F_91 ) ;
F_151 ( & V_295 -> V_184 , F_114 ) ;
F_150 ( & V_295 -> V_186 , F_103 ) ;
V_295 -> V_64 = F_152 ( L_59 , 0 ) ;
if ( V_295 -> V_64 == NULL )
goto error;
F_153 ( & V_295 -> V_208 ) ;
V_295 -> V_208 . V_2 = ( unsigned long ) V_295 ;
V_295 -> V_208 . V_297 = F_99 ;
F_93 ( & V_295 -> V_158 ) ;
F_93 ( & V_295 -> V_167 ) ;
F_36 ( & V_295 -> V_59 ) ;
V_295 -> V_136 = F_154 ( & V_298 , V_287 ,
V_295 -> V_20 -> V_35 +
V_252 ,
V_295 -> V_20 -> V_36 ) ;
if ( ! V_295 -> V_136 ) {
V_43 = - V_52 ;
goto V_299;
}
F_155 ( V_295 -> V_136 , V_294 ) ;
F_156 ( V_295 -> V_136 , V_295 ) ;
V_43 = F_157 ( V_295 -> V_136 ) ;
if ( V_43 )
goto V_300;
return V_295 ;
V_300:
F_158 ( V_295 -> V_136 ) ;
V_299:
F_159 ( V_295 -> V_64 ) ;
error:
F_32 ( V_295 ) ;
return F_28 ( V_43 ) ;
}
void F_160 ( struct V_16 * V_295 )
{
struct V_40 * V_29 , * V_301 ;
F_161 ( V_295 -> V_136 ) ;
F_158 ( V_295 -> V_136 ) ;
F_118 ( & V_295 -> V_184 ) ;
F_159 ( V_295 -> V_64 ) ;
F_84 ( & V_295 -> V_158 ) ;
F_111 ( & V_295 -> V_208 ) ;
F_162 (cmd, n, &priv->cmd_queue, queue) {
F_48 ( & V_29 -> V_58 ) ;
F_32 ( V_29 ) ;
}
F_32 ( V_295 ) ;
}
