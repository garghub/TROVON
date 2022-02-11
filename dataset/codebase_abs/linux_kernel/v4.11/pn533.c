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
int V_41 = V_29 -> V_41 ;
struct V_31 * V_42 = V_29 -> V_42 ;
struct V_31 * V_43 = V_29 -> V_43 ;
int V_44 ;
F_26 ( V_42 ) ;
if ( V_41 < 0 ) {
V_44 = V_29 -> V_45 ( V_17 , V_29 -> V_46 ,
F_27 ( V_41 ) ) ;
F_26 ( V_43 ) ;
goto V_47;
}
F_28 ( V_43 , V_17 -> V_20 -> V_21 ) ;
F_29 ( V_43 , V_43 -> V_15 - V_17 -> V_20 -> V_48 ) ;
V_44 = V_29 -> V_45 ( V_17 , V_29 -> V_46 , V_43 ) ;
V_47:
F_30 ( V_29 ) ;
V_17 -> V_29 = NULL ;
return V_44 ;
}
static int F_31 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_42 ,
T_3 V_45 ,
void * V_46 )
{
struct V_40 * V_29 ;
int V_44 = 0 ;
F_32 ( V_17 -> V_17 , L_1 , V_7 ) ;
V_29 = F_33 ( sizeof( * V_29 ) , V_49 ) ;
if ( ! V_29 )
return - V_50 ;
V_29 -> V_30 = V_7 ;
V_29 -> V_42 = V_42 ;
V_29 -> V_45 = V_45 ;
V_29 -> V_46 = V_46 ;
F_22 ( V_17 , V_7 , V_42 ) ;
F_34 ( & V_17 -> V_51 ) ;
if ( ! V_17 -> V_52 ) {
V_44 = V_17 -> V_53 -> V_54 ( V_17 , V_42 ) ;
if ( V_44 )
goto error;
V_17 -> V_52 = 1 ;
V_17 -> V_29 = V_29 ;
goto V_55;
}
F_32 ( V_17 -> V_17 , L_2 ,
V_56 , V_7 ) ;
F_35 ( & V_29 -> V_57 ) ;
F_36 ( & V_29 -> V_57 , & V_17 -> V_58 ) ;
goto V_55;
error:
F_30 ( V_29 ) ;
V_55:
F_37 ( & V_17 -> V_51 ) ;
return V_44 ;
}
static int F_38 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_42 ,
T_3 V_45 ,
void * V_46 )
{
int V_44 ;
V_44 = F_31 ( V_17 , V_7 , V_42 , V_45 ,
V_46 ) ;
return V_44 ;
}
static int F_39 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_42 ,
T_3 V_45 ,
void * V_46 )
{
int V_44 ;
V_44 = F_31 ( V_17 , V_7 , V_42 , V_45 ,
V_46 ) ;
return V_44 ;
}
static int F_40 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_42 ,
T_3 V_45 ,
void * V_46 )
{
struct V_40 * V_29 ;
int V_44 ;
V_29 = F_33 ( sizeof( * V_29 ) , V_49 ) ;
if ( ! V_29 )
return - V_50 ;
V_29 -> V_30 = V_7 ;
V_29 -> V_42 = V_42 ;
V_29 -> V_45 = V_45 ;
V_29 -> V_46 = V_46 ;
F_22 ( V_17 , V_7 , V_42 ) ;
V_44 = V_17 -> V_53 -> V_54 ( V_17 , V_42 ) ;
if ( V_44 < 0 )
F_30 ( V_29 ) ;
else
V_17 -> V_29 = V_29 ;
return V_44 ;
}
static void F_41 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_61 ) ;
int V_44 ;
V_44 = F_25 ( V_17 ) ;
if ( V_44 != - V_62 )
F_43 ( V_17 -> V_63 , & V_17 -> V_64 ) ;
}
static void F_44 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_64 ) ;
struct V_40 * V_29 ;
int V_44 ;
F_34 ( & V_17 -> V_51 ) ;
if ( F_45 ( & V_17 -> V_58 ) ) {
V_17 -> V_52 = 0 ;
F_37 ( & V_17 -> V_51 ) ;
return;
}
V_29 = F_46 ( & V_17 -> V_58 , struct V_40 , V_57 ) ;
F_47 ( & V_29 -> V_57 ) ;
F_37 ( & V_17 -> V_51 ) ;
V_44 = V_17 -> V_53 -> V_54 ( V_17 , V_29 -> V_42 ) ;
if ( V_44 < 0 ) {
F_26 ( V_29 -> V_42 ) ;
F_30 ( V_29 ) ;
return;
}
V_17 -> V_29 = V_29 ;
}
static int F_48 ( struct V_16 * V_17 , void * V_65 ,
struct V_31 * V_43 )
{
struct V_66 * V_67 = V_65 ;
V_67 -> V_43 = V_43 ;
F_49 ( & V_67 -> V_47 ) ;
return 0 ;
}
static struct V_31 * F_50 ( struct V_16 * V_17 , T_1 V_7 ,
struct V_31 * V_42 )
{
int V_44 ;
struct V_66 V_67 ;
F_51 ( & V_67 . V_47 ) ;
V_44 = F_39 ( V_17 , V_7 , V_42 ,
F_48 , & V_67 ) ;
if ( V_44 ) {
F_26 ( V_42 ) ;
return F_27 ( V_44 ) ;
}
F_52 ( & V_67 . V_47 ) ;
return V_67 . V_43 ;
}
static struct V_31 * F_53 ( struct V_16 * V_17 , unsigned int V_68 )
{
struct V_31 * V_32 ;
V_32 = F_54 ( V_17 -> V_20 -> V_35 +
V_68 +
V_17 -> V_20 -> V_36 , V_49 ) ;
if ( V_32 )
F_55 ( V_32 , V_17 -> V_20 -> V_35 ) ;
return V_32 ;
}
static bool F_56 ( struct V_69 * V_70 ,
int V_71 )
{
T_1 V_72 ;
T_1 V_73 ;
if ( V_71 < sizeof( struct V_69 ) )
return false ;
V_72 = F_57 ( V_70 -> V_74 ) ;
V_73 = F_58 ( V_70 -> V_74 ) ;
if ( ( V_72 == V_75 &&
V_73 != V_76 ) ||
( V_72 != V_75 &&
V_73 == V_76 ) )
return false ;
if ( F_59 ( V_70 -> V_77 ) != 0 )
return false ;
return true ;
}
static int F_60 ( struct V_78 * V_79 , T_1 * V_80 ,
int V_81 )
{
struct V_69 * V_82 ;
V_82 = (struct V_69 * ) V_80 ;
if ( ! F_56 ( V_82 , V_81 ) )
return - V_83 ;
switch ( F_61 ( V_82 -> V_77 ) ) {
case V_84 :
V_79 -> V_85 = V_86 ;
break;
case V_87 :
V_79 -> V_85 = V_88 ;
break;
case V_89 :
V_79 -> V_85 = V_90 ;
break;
case V_91 :
V_79 -> V_85 = V_88 |
V_90 ;
break;
}
V_79 -> V_74 = F_15 ( V_82 -> V_74 ) ;
V_79 -> V_77 = V_82 -> V_77 ;
V_79 -> V_92 = V_82 -> V_93 ;
memcpy ( V_79 -> V_94 , V_82 -> V_95 , V_79 -> V_92 ) ;
return 0 ;
}
static bool F_62 ( struct V_96 * V_97 ,
int V_71 )
{
if ( V_71 < sizeof( struct V_96 ) )
return false ;
if ( V_97 -> V_98 != V_99 )
return false ;
return true ;
}
static int F_63 ( struct V_78 * V_79 , T_1 * V_80 ,
int V_81 )
{
struct V_96 * V_100 ;
V_100 = (struct V_96 * ) V_80 ;
if ( ! F_62 ( V_100 , V_81 ) )
return - V_83 ;
if ( ( V_100 -> V_101 [ 0 ] == V_102 ) &&
( V_100 -> V_101 [ 1 ] == V_103 ) )
V_79 -> V_85 = V_90 ;
else
V_79 -> V_85 = V_104 ;
memcpy ( V_79 -> V_105 , & V_100 -> V_98 , 9 ) ;
V_79 -> V_106 = 9 ;
memcpy ( V_79 -> V_101 , V_100 -> V_101 , V_107 ) ;
V_79 -> V_108 = V_107 ;
return 0 ;
}
static bool F_64 ( struct V_109 * V_110 ,
int V_71 )
{
T_1 V_72 ;
T_1 V_73 ;
if ( V_71 < sizeof( struct V_109 ) )
return false ;
V_72 = F_57 ( V_110 -> V_74 ) ;
V_73 = F_58 ( V_110 -> V_74 ) ;
if ( ( V_72 == V_75 &&
V_73 != V_76 ) ||
( V_72 != V_75 &&
V_73 == V_76 ) )
return false ;
return true ;
}
static int F_65 ( struct V_78 * V_79 , T_1 * V_80 ,
int V_81 )
{
struct V_109 * V_111 ;
V_111 = (struct V_109 * ) V_80 ;
if ( ! F_64 ( V_111 , V_81 ) )
return - V_83 ;
V_79 -> V_85 = V_112 ;
V_79 -> V_74 = F_15 ( V_111 -> V_74 ) ;
V_79 -> V_92 = 4 ;
memcpy ( V_79 -> V_94 , V_111 -> V_113 , V_79 -> V_92 ) ;
return 0 ;
}
static bool F_66 ( struct V_114 * V_115 ,
int V_71 )
{
if ( V_71 < sizeof( struct V_114 ) )
return false ;
if ( V_115 -> V_116 . V_98 != V_117 )
return false ;
if ( F_67 ( V_115 -> V_116 . V_118 . V_119 ) &
V_120 )
return false ;
return true ;
}
static int F_68 ( struct V_78 * V_79 , T_1 * V_80 ,
int V_81 )
{
struct V_114 * V_121 ;
V_121 = (struct V_114 * ) V_80 ;
if ( ! F_66 ( V_121 , V_81 ) )
return - V_83 ;
V_79 -> V_85 = V_122 ;
return 0 ;
}
static int F_69 ( struct V_16 * V_17 , T_1 V_123 , T_1 * V_124 ,
int V_125 )
{
struct V_78 V_79 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_3 ,
V_56 , V_17 -> V_126 ) ;
if ( V_123 != 1 )
return - V_83 ;
memset ( & V_79 , 0 , sizeof( struct V_78 ) ) ;
switch ( V_17 -> V_126 ) {
case V_127 :
V_44 = F_60 ( & V_79 , V_124 , V_125 ) ;
break;
case V_128 :
case V_129 :
V_44 = F_63 ( & V_79 , V_124 , V_125 ) ;
break;
case V_130 :
V_44 = F_65 ( & V_79 , V_124 , V_125 ) ;
break;
case V_131 :
V_44 = F_68 ( & V_79 , V_124 , V_125 ) ;
break;
default:
F_70 ( V_17 -> V_17 ,
L_4 ) ;
return - V_83 ;
}
if ( V_44 )
return V_44 ;
if ( ! ( V_79 . V_85 & V_17 -> V_132 ) ) {
F_32 ( V_17 -> V_17 ,
L_5 ) ;
return - V_133 ;
}
F_32 ( V_17 -> V_17 ,
L_6 ,
V_79 . V_85 ) ;
V_17 -> V_134 = V_79 . V_85 ;
F_71 ( V_17 ) ;
F_72 ( V_17 -> V_135 , & V_79 , 1 ) ;
return 0 ;
}
static inline void F_73 ( struct V_16 * V_17 )
{
V_17 -> V_126 = ( V_17 -> V_126 + 1 ) % V_17 -> V_136 ;
}
static void F_71 ( struct V_16 * V_17 )
{
V_17 -> V_136 = 0 ;
}
static void F_74 ( struct V_16 * V_17 , T_1 V_137 )
{
V_17 -> V_138 [ V_17 -> V_136 ] =
(struct V_139 * ) & V_140 [ V_137 ] ;
V_17 -> V_136 ++ ;
}
static void F_75 ( struct V_16 * V_17 ,
T_4 V_141 , T_4 V_142 )
{
F_71 ( V_17 ) ;
if ( ( V_141 & V_86 ) ||
( V_141 & V_88 ) ||
( V_141 & V_90 ) )
F_74 ( V_17 , V_127 ) ;
if ( V_141 & V_104 ||
V_141 & V_90 ) {
F_74 ( V_17 , V_128 ) ;
F_74 ( V_17 , V_129 ) ;
}
if ( V_141 & V_112 )
F_74 ( V_17 , V_130 ) ;
if ( V_141 & V_122 )
F_74 ( V_17 , V_131 ) ;
if ( V_142 )
F_74 ( V_17 , V_143 ) ;
}
static int F_76 ( struct V_16 * V_17 , struct V_31 * V_43 )
{
T_1 V_144 , V_123 , * V_124 ;
int V_44 , V_125 ;
if ( V_17 -> V_132 & V_90 )
V_17 -> V_145 = 1 ;
V_144 = V_43 -> V_2 [ 0 ] ;
V_123 = V_43 -> V_2 [ 1 ] ;
V_124 = & V_43 -> V_2 [ 2 ] ;
V_125 = V_43 -> V_15 - 2 ;
if ( V_144 ) {
V_44 = F_69 ( V_17 , V_123 , V_124 , V_125 ) ;
if ( V_44 == 0 )
return 0 ;
}
return - V_133 ;
}
static struct V_31 * F_77 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
T_1 * V_97 , * V_146 , * V_147 ;
T_1 * V_148 = V_17 -> V_147 ;
T_5 V_149 = V_17 -> V_150 ;
T_1 V_151 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_152 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_153 = 36 +
V_149 +
1 ;
V_32 = F_53 ( V_17 , V_153 ) ;
if ( ! V_32 )
return NULL ;
* F_24 ( V_32 , 1 ) = V_154 ;
memcpy ( F_24 ( V_32 , 6 ) , V_152 , 6 ) ;
V_97 = F_24 ( V_32 , 18 ) ;
memcpy ( V_97 , V_151 , 18 ) ;
F_78 ( V_97 + 2 , 6 ) ;
V_146 = F_24 ( V_32 , 10 ) ;
memset ( V_146 , 0 , 10 ) ;
memcpy ( V_146 , V_97 , 8 ) ;
* F_24 ( V_32 , 1 ) = V_149 ;
V_147 = F_24 ( V_32 , V_149 ) ;
memcpy ( V_147 , V_148 , V_149 ) ;
* F_24 ( V_32 , 1 ) = 0 ;
return V_32 ;
}
static int F_79 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
struct V_31 * V_32 ;
T_1 V_41 , V_155 , V_156 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) ) {
F_81 ( & V_17 -> V_157 ) ;
return F_82 ( V_43 ) ;
}
V_41 = V_43 -> V_2 [ 0 ] ;
V_155 = V_41 & V_158 ;
V_156 = V_41 & V_159 ;
F_28 ( V_43 , sizeof( V_41 ) ) ;
if ( V_155 != V_160 ) {
V_44 = - V_161 ;
goto error;
}
F_83 ( & V_17 -> V_157 , V_43 ) ;
if ( V_156 ) {
F_43 ( V_17 -> V_63 , & V_17 -> V_162 ) ;
return - V_62 ;
}
V_32 = F_84 ( V_17 ) ;
if ( ! V_32 ) {
V_44 = - V_161 ;
goto error;
}
return F_85 ( V_17 -> V_135 , V_32 ) ;
error:
F_86 ( V_17 -> V_135 ) ;
V_17 -> V_163 = 0 ;
F_81 ( & V_17 -> V_157 ) ;
F_26 ( V_43 ) ;
return V_44 ;
}
static void F_87 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_162 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , 0 ) ;
if ( ! V_32 )
return;
V_44 = F_40 ( V_17 ,
V_164 ,
V_32 ,
F_79 ,
NULL ) ;
if ( V_44 < 0 )
F_26 ( V_32 ) ;
}
static void F_88 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_165 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_89 ( & V_17 -> V_166 ) ;
if ( V_32 == NULL ) {
F_90 ( & V_17 -> V_166 ) ;
goto error;
}
if ( F_91 ( & V_17 -> V_166 ) == 0 ) {
V_44 = F_40 ( V_17 , V_167 ,
V_32 , V_168 , NULL ) ;
} else
V_44 = F_40 ( V_17 ,
V_169 ,
V_32 , V_168 , NULL ) ;
if ( V_44 == 0 )
return;
F_92 ( V_17 -> V_17 ,
L_8 , V_44 ) ;
F_26 ( V_32 ) ;
error:
V_17 -> V_53 -> V_170 ( V_17 , V_49 ) ;
F_43 ( V_17 -> V_63 , & V_17 -> V_64 ) ;
}
static void F_93 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_171 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , 0 ) ;
if ( ! V_32 )
return;
V_44 = F_38 ( V_17 , V_164 , V_32 ,
F_79 , NULL ) ;
if ( V_44 < 0 )
F_26 ( V_32 ) ;
}
static int F_94 ( struct V_16 * V_17 , struct V_31 * V_43 )
{
T_1 V_172 , * V_29 , V_173 = V_174 , * V_147 ;
T_5 V_150 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( V_43 -> V_15 < V_175 + 1 )
return - V_176 ;
V_172 = V_43 -> V_2 [ 0 ] ;
V_29 = & V_43 -> V_2 [ 1 ] ;
F_32 ( V_17 -> V_17 , L_9 ,
V_172 , V_43 -> V_15 ) ;
if ( ( V_172 & V_177 ) ==
V_178 )
V_173 = V_179 ;
if ( ( V_172 & V_180 ) == 0 )
return - V_181 ;
V_147 = V_29 + V_175 ;
V_150 = V_43 -> V_15 - ( V_175 + 1 ) ;
V_44 = F_95 ( V_17 -> V_135 , V_90 ,
V_173 , V_147 , V_150 ) ;
if ( V_44 < 0 ) {
F_70 ( V_17 -> V_17 ,
L_10 ) ;
return V_44 ;
}
V_17 -> V_163 = 1 ;
F_43 ( V_17 -> V_63 , & V_17 -> V_171 ) ;
return 0 ;
}
static void F_96 ( unsigned long V_2 )
{
struct V_16 * V_17 = (struct V_16 * ) V_2 ;
F_32 ( V_17 -> V_17 , L_11 ) ;
V_17 -> V_182 = 1 ;
F_73 ( V_17 ) ;
F_97 ( V_17 -> V_63 , & V_17 -> V_183 ,
F_98 ( V_184 ) ) ;
}
static int F_99 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
int V_44 = 0 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) ) {
V_44 = F_82 ( V_43 ) ;
F_70 ( V_17 -> V_17 , L_12 , V_44 ) ;
return V_44 ;
}
F_97 ( V_17 -> V_63 , & V_17 -> V_183 ,
F_98 ( V_184 ) ) ;
F_26 ( V_43 ) ;
return V_44 ;
}
static void F_100 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_185 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , 2 ) ;
if ( ! V_32 )
return;
* F_24 ( V_32 , 1 ) = V_186 ;
* F_24 ( V_32 , 1 ) = V_187 ;
V_44 = F_39 ( V_17 , V_188 , V_32 ,
F_99 , NULL ) ;
if ( V_44 < 0 ) {
F_26 ( V_32 ) ;
F_70 ( V_17 -> V_17 , L_12 , V_44 ) ;
}
}
static int F_101 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
struct V_189 * V_190 ;
struct V_78 V_78 ;
T_1 V_191 ;
int V_44 ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
V_190 = (struct V_189 * ) V_43 -> V_2 ;
V_44 = V_190 -> V_41 & V_158 ;
if ( V_44 != V_160 ) {
F_43 ( V_17 -> V_63 , & V_17 -> V_185 ) ;
F_26 ( V_43 ) ;
return 0 ;
}
F_32 ( V_17 -> V_17 , L_13 ) ;
V_78 . V_85 = V_90 ;
V_78 . V_92 = 10 ;
memcpy ( V_78 . V_94 , V_190 -> V_192 , V_78 . V_92 ) ;
V_44 = F_72 ( V_17 -> V_135 , & V_78 , 1 ) ;
if ( V_44 )
goto error;
V_17 -> V_134 = 0 ;
V_17 -> V_193 = V_194 ;
V_191 = V_43 -> V_15 - 17 ;
V_44 = F_102 ( V_17 -> V_135 ,
V_190 -> V_195 , V_191 ) ;
if ( ! V_44 ) {
V_44 = F_103 ( V_17 -> V_135 ,
V_17 -> V_135 -> V_196 [ 0 ] . V_197 ,
0 , V_198 ) ;
if ( ! V_44 )
F_71 ( V_17 ) ;
}
error:
F_26 ( V_43 ) ;
return V_44 ;
}
static int F_104 ( struct V_135 * V_135 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_31 * V_32 ;
int V_44 , V_153 ;
T_1 * V_199 , V_146 [ V_200 ] ;
T_1 V_201 [ V_202 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_32 ( V_17 -> V_17 , L_14 , V_56 ) ;
if ( ! V_17 -> V_147 ) {
V_17 -> V_147 = F_106 ( V_135 , & V_17 -> V_150 ) ;
if ( ! V_17 -> V_147 || ! V_17 -> V_150 ) {
V_17 -> V_145 = 0 ;
F_43 ( V_17 -> V_63 , & V_17 -> V_185 ) ;
}
}
V_153 = 3 + V_17 -> V_150 ;
V_153 += V_202 ;
V_153 += V_200 ;
V_146 [ 0 ] = 0x1 ;
V_146 [ 1 ] = 0xfe ;
F_78 ( V_146 + 2 , 6 ) ;
V_32 = F_53 ( V_17 , V_153 ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , 1 ) = 0x01 ;
* F_24 ( V_32 , 1 ) = 0x02 ;
V_199 = F_24 ( V_32 , 1 ) ;
* V_199 = 0 ;
memcpy ( F_24 ( V_32 , V_202 ) , V_201 , V_202 ) ;
* V_199 |= 1 ;
memcpy ( F_24 ( V_32 , V_200 ) , V_146 ,
V_200 ) ;
* V_199 |= 2 ;
memcpy ( F_24 ( V_32 , V_17 -> V_150 ) , V_17 -> V_147 , V_17 -> V_150 ) ;
* V_199 |= 4 ;
V_44 = F_39 ( V_17 , V_203 , V_32 ,
F_101 , NULL ) ;
if ( V_44 < 0 )
F_26 ( V_32 ) ;
return V_44 ;
}
static int F_107 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
struct V_139 * V_204 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) ) {
V_44 = F_82 ( V_43 ) ;
F_70 ( V_17 -> V_17 , L_15 ,
V_56 , V_44 ) ;
if ( V_44 == - V_205 ) {
if ( V_17 -> V_136 != 0 )
return V_44 ;
goto V_206;
} else if ( V_44 < 0 ) {
F_70 ( V_17 -> V_17 ,
L_16 , V_44 ) ;
goto V_206;
}
}
V_204 = V_17 -> V_138 [ V_17 -> V_126 ] ;
if ( V_204 -> V_15 == 0 ) {
F_108 ( & V_17 -> V_207 ) ;
V_44 = F_94 ( V_17 , V_43 ) ;
goto V_47;
}
V_44 = F_76 ( V_17 , V_43 ) ;
if ( ! V_44 )
goto V_47;
if ( ! V_17 -> V_136 ) {
F_32 ( V_17 -> V_17 , L_17 ) ;
goto V_47;
}
F_73 ( V_17 ) ;
F_43 ( V_17 -> V_63 , & V_17 -> V_185 ) ;
V_47:
F_26 ( V_43 ) ;
return V_44 ;
V_206:
F_70 ( V_17 -> V_17 , L_18 ) ;
F_71 ( V_17 ) ;
V_17 -> V_132 = 0 ;
return V_44 ;
}
static struct V_31 * F_109 ( struct V_16 * V_17 ,
struct V_139 * V_208 )
{
struct V_31 * V_32 ;
V_32 = F_53 ( V_17 , V_208 -> V_15 ) ;
if ( ! V_32 )
return NULL ;
memcpy ( F_24 ( V_32 , V_208 -> V_15 ) , & V_208 -> V_2 , V_208 -> V_15 ) ;
return V_32 ;
}
static int F_110 ( struct V_16 * V_17 )
{
struct V_139 * V_208 ;
struct V_31 * V_32 ;
int V_44 ;
T_1 V_7 ;
V_208 = V_17 -> V_138 [ V_17 -> V_126 ] ;
F_32 ( V_17 -> V_17 , L_19 ,
V_56 , V_208 -> V_15 ) ;
if ( ( V_17 -> V_132 & V_90 ) && V_17 -> V_145 ) {
V_17 -> V_145 = 0 ;
return F_104 ( V_17 -> V_135 ) ;
}
if ( V_208 -> V_15 == 0 ) {
V_7 = V_209 ;
V_32 = F_77 ( V_17 ) ;
} else {
V_7 = V_210 ;
V_32 = F_109 ( V_17 , V_208 ) ;
}
if ( ! V_32 ) {
F_70 ( V_17 -> V_17 , L_20 ) ;
return - V_50 ;
}
V_44 = F_39 ( V_17 , V_7 , V_32 , F_107 ,
NULL ) ;
if ( V_44 < 0 ) {
F_26 ( V_32 ) ;
F_70 ( V_17 -> V_17 , L_21 , V_44 ) ;
}
return V_44 ;
}
static void F_111 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_183 . V_60 ) ;
struct V_139 * V_204 ;
int V_44 ;
V_204 = V_17 -> V_138 [ V_17 -> V_126 ] ;
F_32 ( V_17 -> V_17 ,
L_22 ,
V_56 , V_17 -> V_182 , V_204 -> V_15 ) ;
if ( V_17 -> V_182 == 1 ) {
V_17 -> V_182 = 0 ;
V_17 -> V_53 -> V_211 ( V_17 , V_212 ) ;
}
V_44 = F_110 ( V_17 ) ;
if ( V_44 )
return;
if ( V_204 -> V_15 == 0 && V_17 -> V_136 > 1 )
F_112 ( & V_17 -> V_207 , V_213 + V_214 * V_215 ) ;
}
static int F_113 ( struct V_135 * V_135 ,
T_4 V_141 , T_4 V_142 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_139 * V_204 ;
T_1 V_216 ;
int V_44 ;
F_32 ( V_17 -> V_17 ,
L_23 ,
V_56 , V_141 , V_142 ) ;
if ( V_17 -> V_193 ) {
F_70 ( V_17 -> V_17 ,
L_24 ) ;
return - V_217 ;
}
if ( V_17 -> V_163 ) {
F_70 ( V_17 -> V_17 ,
L_25 ) ;
return - V_217 ;
}
if ( V_142 ) {
V_17 -> V_147 = F_106 ( V_135 , & V_17 -> V_150 ) ;
if ( V_17 -> V_147 == NULL )
V_142 = 0 ;
}
F_75 ( V_17 , V_141 , V_142 ) ;
V_17 -> V_132 = V_141 ;
V_17 -> V_218 = V_142 ;
F_78 ( & V_216 , sizeof( V_216 ) ) ;
V_216 %= V_17 -> V_136 ;
V_17 -> V_126 = V_216 ;
V_204 = V_17 -> V_138 [ V_17 -> V_126 ] ;
V_44 = F_110 ( V_17 ) ;
if ( ! V_44 && V_204 -> V_15 == 0 && V_17 -> V_136 > 1 )
F_112 ( & V_17 -> V_207 , V_213 + V_214 * V_215 ) ;
return V_44 ;
}
static void F_114 ( struct V_135 * V_135 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
F_108 ( & V_17 -> V_207 ) ;
if ( ! V_17 -> V_136 ) {
F_32 ( V_17 -> V_17 ,
L_26 ) ;
return;
}
V_17 -> V_53 -> V_211 ( V_17 , V_49 ) ;
F_115 ( & V_17 -> V_183 ) ;
F_71 ( V_17 ) ;
}
static int F_116 ( struct V_16 * V_17 )
{
struct V_219 * V_190 ;
T_2 V_220 ;
int V_44 ;
struct V_31 * V_32 ;
struct V_31 * V_43 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , sizeof( T_1 ) * 2 ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , sizeof( T_1 ) ) = 1 ;
* F_24 ( V_32 , sizeof( T_1 ) ) = 0 ;
V_43 = F_50 ( V_17 , V_221 , V_32 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
V_190 = (struct V_219 * ) V_43 -> V_2 ;
V_44 = V_190 -> V_41 & V_158 ;
if ( V_44 != V_160 ) {
F_70 ( V_17 -> V_17 ,
L_27 , V_44 ) ;
F_26 ( V_43 ) ;
return - V_161 ;
}
V_220 = V_43 -> V_15 - 16 ;
V_44 = F_102 ( V_17 -> V_135 , V_190 -> V_195 , V_220 ) ;
F_26 ( V_43 ) ;
return V_44 ;
}
static int F_117 ( struct V_135 * V_135 ,
struct V_78 * V_222 , T_4 V_223 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_28 , V_56 , V_223 ) ;
if ( V_17 -> V_136 ) {
F_70 ( V_17 -> V_17 ,
L_29 ) ;
return - V_217 ;
}
if ( V_17 -> V_193 ) {
F_70 ( V_17 -> V_17 ,
L_30 ) ;
return - V_217 ;
}
if ( ! V_17 -> V_134 ) {
F_70 ( V_17 -> V_17 ,
L_31 ) ;
return - V_176 ;
}
if ( ! ( V_17 -> V_134 & ( 1 << V_223 ) ) ) {
F_70 ( V_17 -> V_17 ,
L_32 ,
V_223 ) ;
return - V_176 ;
}
if ( V_223 == V_194 ) {
V_44 = F_116 ( V_17 ) ;
if ( V_44 ) {
F_70 ( V_17 -> V_17 ,
L_33 , V_44 ) ;
return V_44 ;
}
}
V_17 -> V_193 = V_223 ;
V_17 -> V_134 = 0 ;
return 0 ;
}
static int F_118 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
int V_44 = 0 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) ) {
V_44 = F_82 ( V_43 ) ;
F_70 ( V_17 -> V_17 , L_34 , V_44 ) ;
return V_44 ;
}
V_44 = V_43 -> V_2 [ 0 ] & V_158 ;
if ( V_44 != V_160 )
F_70 ( V_17 -> V_17 ,
L_35 , V_44 ) ;
F_26 ( V_43 ) ;
return V_44 ;
}
static void F_119 ( struct V_135 * V_135 ,
struct V_78 * V_222 , T_1 V_172 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( ! V_17 -> V_193 ) {
F_70 ( V_17 -> V_17 , L_36 ) ;
return;
}
V_17 -> V_193 = 0 ;
F_81 ( & V_17 -> V_157 ) ;
V_32 = F_53 ( V_17 , sizeof( T_1 ) ) ;
if ( ! V_32 )
return;
* F_24 ( V_32 , 1 ) = 1 ;
V_44 = F_39 ( V_17 , V_224 , V_32 ,
F_118 , NULL ) ;
if ( V_44 < 0 ) {
F_26 ( V_32 ) ;
F_70 ( V_17 -> V_17 , L_34 , V_44 ) ;
}
}
static int F_120 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
struct V_189 * V_190 ;
T_1 V_191 ;
int V_44 ;
T_1 V_225 = * ( T_1 * ) V_67 ;
F_30 ( V_67 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
if ( V_17 -> V_134 &&
! ( V_17 -> V_134 & ( 1 << V_194 ) ) ) {
F_70 ( V_17 -> V_17 ,
L_37 ) ;
V_44 = - V_176 ;
goto error;
}
V_190 = (struct V_189 * ) V_43 -> V_2 ;
V_44 = V_190 -> V_41 & V_158 ;
if ( V_44 != V_160 ) {
F_70 ( V_17 -> V_17 ,
L_38 , V_44 ) ;
goto error;
}
if ( ! V_17 -> V_134 ) {
struct V_78 V_78 ;
F_32 ( V_17 -> V_17 , L_39 ) ;
V_78 . V_85 = V_90 ;
V_78 . V_92 = 10 ;
memcpy ( V_78 . V_94 , V_190 -> V_192 , V_78 . V_92 ) ;
V_44 = F_72 ( V_17 -> V_135 , & V_78 , 1 ) ;
if ( V_44 )
goto error;
V_17 -> V_134 = 0 ;
}
V_17 -> V_193 = V_194 ;
V_191 = V_43 -> V_15 - 17 ;
V_44 = F_102 ( V_17 -> V_135 ,
V_190 -> V_195 , V_191 ) ;
if ( V_44 == 0 )
V_44 = F_103 ( V_17 -> V_135 ,
V_17 -> V_135 -> V_196 [ 0 ] . V_197 ,
! V_225 , V_198 ) ;
error:
F_26 ( V_43 ) ;
return V_44 ;
}
static int F_121 ( struct V_135 * V_135 , struct V_78 * V_222 ,
T_1 V_173 , T_1 * V_147 , T_5 V_150 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_31 * V_32 ;
int V_44 , V_153 ;
T_1 * V_199 , * V_67 , V_146 [ V_200 ] ;
T_1 V_201 [ V_202 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( V_17 -> V_136 ) {
F_70 ( V_17 -> V_17 ,
L_40 ) ;
return - V_217 ;
}
if ( V_17 -> V_193 ) {
F_70 ( V_17 -> V_17 ,
L_30 ) ;
return - V_217 ;
}
V_153 = 3 + V_150 ;
V_153 += V_202 ;
V_153 += V_200 ;
if ( V_222 && ! V_222 -> V_108 ) {
V_146 [ 0 ] = 0x1 ;
V_146 [ 1 ] = 0xfe ;
F_78 ( V_146 + 2 , 6 ) ;
}
V_32 = F_53 ( V_17 , V_153 ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , 1 ) = ! V_173 ;
* F_24 ( V_32 , 1 ) = 0x02 ;
V_199 = F_24 ( V_32 , 1 ) ;
* V_199 = 0 ;
memcpy ( F_24 ( V_32 , V_202 ) , V_201 , V_202 ) ;
* V_199 |= 1 ;
if ( V_222 && V_222 -> V_108 )
memcpy ( F_24 ( V_32 , V_200 ) , V_222 -> V_101 ,
V_222 -> V_108 ) ;
else
memcpy ( F_24 ( V_32 , V_200 ) , V_146 ,
V_200 ) ;
* V_199 |= 2 ;
if ( V_147 != NULL && V_150 > 0 ) {
memcpy ( F_24 ( V_32 , V_150 ) , V_147 , V_150 ) ;
* V_199 |= 4 ;
} else {
* V_199 = 0 ;
}
V_67 = F_122 ( sizeof( * V_67 ) , V_49 ) ;
if ( ! V_67 ) {
F_26 ( V_32 ) ;
return - V_50 ;
}
* V_67 = ! V_173 ;
F_123 ( V_17 -> V_135 , 0 ) ;
V_44 = F_39 ( V_17 , V_203 , V_32 ,
F_120 , V_67 ) ;
if ( V_44 < 0 ) {
F_26 ( V_32 ) ;
F_30 ( V_67 ) ;
}
return V_44 ;
}
static int F_124 ( struct V_135 * V_135 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
F_71 ( V_17 ) ;
if ( V_17 -> V_163 || V_17 -> V_193 )
V_17 -> V_53 -> V_211 ( V_17 , V_49 ) ;
V_17 -> V_193 = 0 ;
V_17 -> V_163 = 0 ;
F_81 ( & V_17 -> V_157 ) ;
return 0 ;
}
static struct V_31 * F_84 ( struct V_16 * V_17 )
{
struct V_31 * V_32 , * V_226 , * V_227 ;
unsigned int V_153 = 0 , V_228 = 0 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_125 ( & V_17 -> V_157 ) )
return NULL ;
if ( F_91 ( & V_17 -> V_157 ) == 1 ) {
V_32 = F_89 ( & V_17 -> V_157 ) ;
goto V_229;
}
F_126 (&dev->resp_q, tmp, t)
V_153 += V_226 -> V_15 ;
F_32 ( V_17 -> V_17 , L_41 ,
V_56 , V_153 ) ;
V_32 = F_54 ( V_153 , V_49 ) ;
if ( V_32 == NULL )
goto V_229;
F_24 ( V_32 , V_153 ) ;
F_126 (&dev->resp_q, tmp, t) {
memcpy ( V_32 -> V_2 + V_228 , V_226 -> V_2 , V_226 -> V_15 ) ;
V_228 += V_226 -> V_15 ;
}
V_229:
F_81 ( & V_17 -> V_157 ) ;
return V_32 ;
}
static int F_127 ( struct V_16 * V_17 , void * V_65 ,
struct V_31 * V_43 )
{
struct V_230 * V_67 = V_65 ;
struct V_31 * V_32 ;
int V_44 = 0 ;
T_1 V_41 , V_155 , V_156 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) ) {
V_44 = F_82 ( V_43 ) ;
goto V_231;
}
V_41 = V_43 -> V_2 [ 0 ] ;
V_155 = V_41 & V_158 ;
V_156 = V_41 & V_159 ;
F_28 ( V_43 , sizeof( V_41 ) ) ;
if ( V_155 != V_160 ) {
F_70 ( V_17 -> V_17 ,
L_42 , V_155 ) ;
V_44 = - V_161 ;
goto error;
}
F_83 ( & V_17 -> V_157 , V_43 ) ;
if ( V_156 ) {
V_17 -> V_232 = V_67 ;
F_43 ( V_17 -> V_63 , & V_17 -> V_233 ) ;
return - V_62 ;
}
if ( F_91 ( & V_17 -> V_166 ) > 0 ) {
V_17 -> V_234 = V_67 ;
F_43 ( V_17 -> V_63 , & V_17 -> V_235 ) ;
return - V_62 ;
}
V_32 = F_84 ( V_17 ) ;
if ( ! V_32 ) {
V_44 = - V_50 ;
goto error;
}
V_67 -> V_236 ( V_67 -> V_237 , V_32 , 0 ) ;
F_30 ( V_67 ) ;
return 0 ;
error:
F_26 ( V_43 ) ;
V_231:
F_81 ( & V_17 -> V_157 ) ;
V_67 -> V_236 ( V_67 -> V_237 , NULL , V_44 ) ;
F_30 ( V_67 ) ;
return V_44 ;
}
void F_128 ( struct V_16 * V_17 , struct V_31 * V_32 , int V_41 )
{
if ( ! V_17 -> V_29 )
goto V_238;
V_17 -> V_29 -> V_41 = V_41 ;
if ( V_41 != 0 ) {
F_32 ( V_17 -> V_17 , L_43 , V_56 , V_41 ) ;
goto V_238;
}
if ( V_32 == NULL ) {
F_129 ( L_44 ) ;
goto V_238;
}
if ( F_17 ( V_32 -> V_2 ) ) {
F_32 ( V_17 -> V_17 , L_45 , V_56 ) ;
F_26 ( V_32 ) ;
return;
}
F_130 ( L_46 , V_239 , 16 , 1 , V_32 -> V_2 ,
V_17 -> V_20 -> V_240 ( V_32 -> V_2 ) , false ) ;
if ( ! V_17 -> V_20 -> V_241 ( V_32 -> V_2 , V_17 ) ) {
F_70 ( V_17 -> V_17 , L_47 ) ;
V_17 -> V_29 -> V_41 = - V_161 ;
} else if ( ! F_20 ( V_17 , V_32 -> V_2 ) ) {
F_70 ( V_17 -> V_17 , L_48 ) ;
V_17 -> V_29 -> V_41 = - V_161 ;
}
V_17 -> V_29 -> V_43 = V_32 ;
V_238:
F_43 ( V_17 -> V_63 , & V_17 -> V_61 ) ;
}
static int F_131 ( struct V_16 * V_17 , struct V_31 * V_32 )
{
struct V_31 * V_242 ;
int V_243 ;
do {
if ( V_32 -> V_15 > V_244 )
V_243 = V_244 ;
else
V_243 = V_32 -> V_15 ;
V_242 = F_53 ( V_17 , V_243 ) ;
if ( ! V_242 ) {
F_81 ( & V_17 -> V_166 ) ;
break;
}
if ( ! V_17 -> V_163 ) {
F_55 ( V_242 , 1 ) ;
if ( V_243 == V_244 )
* F_23 ( V_242 , sizeof( T_1 ) ) =
( V_159 | 1 ) ;
else
* F_23 ( V_242 , sizeof( T_1 ) ) = 1 ;
}
memcpy ( F_24 ( V_242 , V_243 ) , V_32 -> V_2 , V_243 ) ;
F_28 ( V_32 , V_243 ) ;
F_83 ( & V_17 -> V_166 , V_242 ) ;
} while ( V_32 -> V_15 > 0 );
F_26 ( V_32 ) ;
return F_91 ( & V_17 -> V_166 ) ;
}
static int F_132 ( struct V_135 * V_135 ,
struct V_78 * V_222 , struct V_31 * V_32 ,
T_6 V_236 , void * V_237 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_230 * V_67 = NULL ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( ! V_17 -> V_193 ) {
F_70 ( V_17 -> V_17 ,
L_49 ) ;
V_44 = - V_176 ;
goto error;
}
V_67 = F_122 ( sizeof( * V_67 ) , V_49 ) ;
if ( ! V_67 ) {
V_44 = - V_50 ;
goto error;
}
V_67 -> V_236 = V_236 ;
V_67 -> V_237 = V_237 ;
switch ( V_17 -> V_245 ) {
case V_246 :
if ( V_17 -> V_193 == V_247 ) {
V_44 = F_38 ( V_17 , V_248 ,
V_32 ,
F_127 ,
V_67 ) ;
break;
}
default:
if ( V_32 -> V_15 > V_249 ) {
V_44 = F_131 ( V_17 , V_32 ) ;
if ( V_44 <= 0 )
goto error;
V_32 = F_89 ( & V_17 -> V_166 ) ;
if ( ! V_32 ) {
V_44 = - V_161 ;
goto error;
}
} else {
* F_23 ( V_32 , sizeof( T_1 ) ) = 1 ;
}
V_44 = F_38 ( V_17 , V_250 ,
V_32 , F_127 ,
V_67 ) ;
break;
}
if ( V_44 < 0 )
goto error;
return 0 ;
error:
F_30 ( V_67 ) ;
F_26 ( V_32 ) ;
return V_44 ;
}
static int V_168 ( struct V_16 * V_17 , void * V_67 ,
struct V_31 * V_43 )
{
T_1 V_41 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
V_41 = V_43 -> V_2 [ 0 ] ;
if ( F_91 ( & V_17 -> V_166 ) > 0 ) {
F_43 ( V_17 -> V_63 , & V_17 -> V_165 ) ;
return - V_62 ;
}
F_26 ( V_43 ) ;
if ( V_41 != 0 ) {
F_86 ( V_17 -> V_135 ) ;
V_17 -> V_163 = 0 ;
return 0 ;
}
F_43 ( V_17 -> V_63 , & V_17 -> V_171 ) ;
return 0 ;
}
static int F_133 ( struct V_135 * V_135 , struct V_31 * V_32 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
if ( V_32 -> V_15 > V_249 ) {
V_44 = F_131 ( V_17 , V_32 ) ;
if ( V_44 <= 0 )
goto error;
V_32 = F_89 ( & V_17 -> V_166 ) ;
if ( ! V_32 ) {
V_44 = - V_161 ;
goto error;
}
V_44 = F_38 ( V_17 , V_169 , V_32 ,
V_168 , NULL ) ;
} else {
V_44 = F_38 ( V_17 , V_167 , V_32 ,
V_168 , NULL ) ;
}
error:
if ( V_44 < 0 ) {
F_26 ( V_32 ) ;
F_81 ( & V_17 -> V_166 ) ;
}
return V_44 ;
}
static void F_134 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_233 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , V_251 ) ;
if ( ! V_32 )
goto error;
switch ( V_17 -> V_245 ) {
case V_246 :
if ( V_17 -> V_193 == V_247 ) {
V_44 = F_40 ( V_17 ,
V_248 ,
V_32 ,
F_127 ,
V_17 -> V_232 ) ;
break;
}
default:
* F_24 ( V_32 , sizeof( T_1 ) ) = 1 ;
V_44 = F_40 ( V_17 ,
V_250 ,
V_32 ,
F_127 ,
V_17 -> V_232 ) ;
break;
}
if ( V_44 == 0 )
return;
F_70 ( V_17 -> V_17 ,
L_50 , V_44 ) ;
F_26 ( V_32 ) ;
F_30 ( V_17 -> V_232 ) ;
error:
V_17 -> V_53 -> V_170 ( V_17 , V_49 ) ;
F_43 ( V_17 -> V_63 , & V_17 -> V_64 ) ;
}
static void F_135 ( struct V_59 * V_60 )
{
struct V_16 * V_17 = F_42 ( V_60 , struct V_16 , V_235 ) ;
struct V_31 * V_32 ;
int V_44 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_89 ( & V_17 -> V_166 ) ;
if ( V_32 == NULL ) {
F_90 ( & V_17 -> V_166 ) ;
goto error;
}
switch ( V_17 -> V_245 ) {
case V_246 :
if ( V_17 -> V_193 != V_247 ) {
V_44 = - V_161 ;
break;
}
V_44 = F_40 ( V_17 , V_248 ,
V_32 ,
F_127 ,
V_17 -> V_234 ) ;
break;
default:
V_44 = F_40 ( V_17 ,
V_250 ,
V_32 ,
F_127 ,
V_17 -> V_234 ) ;
break;
}
if ( V_44 == 0 )
return;
F_70 ( V_17 -> V_17 ,
L_50 , V_44 ) ;
F_26 ( V_32 ) ;
F_30 ( V_17 -> V_234 ) ;
error:
V_17 -> V_53 -> V_170 ( V_17 , V_49 ) ;
F_43 ( V_17 -> V_63 , & V_17 -> V_64 ) ;
}
static int F_136 ( struct V_16 * V_17 , T_1 V_252 , T_1 * V_253 ,
T_1 V_254 )
{
struct V_31 * V_32 ;
struct V_31 * V_43 ;
int V_153 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_153 = sizeof( V_252 ) + V_254 ;
V_32 = F_53 ( V_17 , V_153 ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , sizeof( V_252 ) ) = V_252 ;
memcpy ( F_24 ( V_32 , V_254 ) , V_253 , V_254 ) ;
V_43 = F_50 ( V_17 , V_188 , V_32 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
F_26 ( V_43 ) ;
return 0 ;
}
static int F_137 ( struct V_16 * V_17 ,
struct V_255 * V_256 )
{
struct V_31 * V_32 ;
struct V_31 * V_43 ;
V_32 = F_53 ( V_17 , 0 ) ;
if ( ! V_32 )
return - V_50 ;
V_43 = F_50 ( V_17 , V_257 , V_32 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
V_256 -> V_258 = V_43 -> V_2 [ 0 ] ;
V_256 -> V_259 = V_43 -> V_2 [ 1 ] ;
V_256 -> V_260 = V_43 -> V_2 [ 2 ] ;
V_256 -> V_261 = V_43 -> V_2 [ 3 ] ;
F_26 ( V_43 ) ;
return 0 ;
}
static int F_138 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
struct V_31 * V_43 ;
F_32 ( V_17 -> V_17 , L_7 , V_56 ) ;
V_32 = F_53 ( V_17 , sizeof( T_1 ) ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , sizeof( T_1 ) ) = 0x1 ;
V_43 = F_50 ( V_17 , 0x18 , V_32 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
F_26 ( V_43 ) ;
return 0 ;
}
static int F_123 ( struct V_135 * V_135 , T_1 V_262 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
T_1 V_263 = ! ! V_262 ;
int V_44 ;
V_263 |= V_187 ;
V_44 = F_136 ( V_17 , V_186 ,
( T_1 * ) & V_263 , 1 ) ;
if ( V_44 ) {
F_70 ( V_17 -> V_17 , L_51 ) ;
return V_44 ;
}
return V_44 ;
}
static int F_139 ( struct V_135 * V_135 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
struct V_31 * V_32 ;
struct V_31 * V_43 ;
V_32 = F_53 ( V_17 , 1 ) ;
if ( ! V_32 )
return - V_50 ;
* F_24 ( V_32 , 1 ) = 0x01 ;
V_43 = F_50 ( V_17 , V_264 , V_32 ) ;
if ( F_80 ( V_43 ) )
return F_82 ( V_43 ) ;
F_26 ( V_43 ) ;
return 0 ;
}
static int F_140 ( struct V_135 * V_135 )
{
struct V_16 * V_17 = F_105 ( V_135 ) ;
if ( V_17 -> V_245 == V_265 ) {
int V_44 = F_139 ( V_135 ) ;
if ( V_44 )
return V_44 ;
}
return F_123 ( V_135 , 1 ) ;
}
static int F_141 ( struct V_135 * V_135 )
{
return F_123 ( V_135 , 0 ) ;
}
static int F_142 ( struct V_16 * V_17 )
{
struct V_266 V_267 ;
struct V_268 V_269 ;
T_1 V_270 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_44 ;
switch ( V_17 -> V_245 ) {
case V_271 :
case V_246 :
case V_272 :
case V_265 :
V_267 . V_273 = 0x2 ;
V_267 . V_274 = 0x1 ;
V_267 . V_275 =
V_276 ;
V_269 . V_277 = V_278 ;
V_269 . V_279 = V_278 ;
V_269 . V_280 = V_281 ;
break;
default:
F_70 ( V_17 -> V_17 , L_52 ,
V_17 -> V_245 ) ;
return - V_176 ;
}
V_44 = F_136 ( V_17 , V_282 ,
( T_1 * ) & V_267 , sizeof( V_267 ) ) ;
if ( V_44 ) {
F_70 ( V_17 -> V_17 ,
L_53 ) ;
return V_44 ;
}
V_44 = F_136 ( V_17 , V_283 ,
( T_1 * ) & V_269 , sizeof( V_269 ) ) ;
if ( V_44 ) {
F_70 ( V_17 -> V_17 , L_54 ) ;
return V_44 ;
}
switch ( V_17 -> V_245 ) {
case V_271 :
case V_265 :
break;
case V_246 :
F_138 ( V_17 ) ;
V_44 = F_136 ( V_17 , V_284 ,
V_270 , 3 ) ;
if ( V_44 ) {
F_70 ( V_17 -> V_17 ,
L_55 ) ;
return V_44 ;
}
F_138 ( V_17 ) ;
break;
}
return 0 ;
}
struct V_16 * F_143 ( T_4 V_245 ,
T_4 V_285 ,
enum V_286 V_287 ,
void * V_288 ,
struct V_289 * V_53 ,
struct V_34 * V_290 ,
struct V_291 * V_17 ,
struct V_291 * V_292 )
{
struct V_255 V_293 ;
struct V_16 * V_294 ;
int V_44 = - V_50 ;
V_294 = F_33 ( sizeof( * V_294 ) , V_49 ) ;
if ( ! V_294 )
return F_27 ( - V_50 ) ;
V_294 -> V_288 = V_288 ;
V_294 -> V_53 = V_53 ;
V_294 -> V_17 = V_17 ;
if ( V_290 != NULL )
V_294 -> V_20 = V_290 ;
else
V_294 -> V_20 = & V_295 ;
V_294 -> V_287 = V_287 ;
V_294 -> V_245 = V_245 ;
F_144 ( & V_294 -> V_51 ) ;
F_145 ( & V_294 -> V_64 , F_44 ) ;
F_145 ( & V_294 -> V_61 , F_41 ) ;
F_145 ( & V_294 -> V_233 , F_134 ) ;
F_145 ( & V_294 -> V_235 , F_135 ) ;
F_145 ( & V_294 -> V_171 , F_93 ) ;
F_145 ( & V_294 -> V_162 , F_87 ) ;
F_145 ( & V_294 -> V_165 , F_88 ) ;
F_146 ( & V_294 -> V_183 , F_111 ) ;
F_145 ( & V_294 -> V_185 , F_100 ) ;
V_294 -> V_63 = F_147 ( L_56 , 0 ) ;
if ( V_294 -> V_63 == NULL )
goto error;
F_148 ( & V_294 -> V_207 ) ;
V_294 -> V_207 . V_2 = ( unsigned long ) V_294 ;
V_294 -> V_207 . V_296 = F_96 ;
F_90 ( & V_294 -> V_157 ) ;
F_90 ( & V_294 -> V_166 ) ;
F_35 ( & V_294 -> V_58 ) ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
V_44 = F_137 ( V_294 , & V_293 ) ;
if ( V_44 < 0 )
goto V_297;
F_149 ( V_17 , L_57 ,
V_293 . V_258 , V_293 . V_259 , V_293 . V_260 ) ;
V_294 -> V_135 = F_150 ( & V_298 , V_285 ,
V_294 -> V_20 -> V_35 +
V_251 ,
V_294 -> V_20 -> V_36 ) ;
if ( ! V_294 -> V_135 ) {
V_44 = - V_50 ;
goto V_297;
}
F_151 ( V_294 -> V_135 , V_292 ) ;
F_152 ( V_294 -> V_135 , V_294 ) ;
V_44 = F_153 ( V_294 -> V_135 ) ;
if ( V_44 )
goto V_299;
V_44 = F_142 ( V_294 ) ;
if ( V_44 )
goto V_300;
return V_294 ;
V_300:
F_154 ( V_294 -> V_135 ) ;
V_299:
F_155 ( V_294 -> V_135 ) ;
V_297:
F_156 ( V_294 -> V_63 ) ;
error:
F_30 ( V_294 ) ;
return F_27 ( V_44 ) ;
}
void F_157 ( struct V_16 * V_294 )
{
struct V_40 * V_29 , * V_301 ;
F_154 ( V_294 -> V_135 ) ;
F_155 ( V_294 -> V_135 ) ;
F_115 ( & V_294 -> V_183 ) ;
F_156 ( V_294 -> V_63 ) ;
F_81 ( & V_294 -> V_157 ) ;
F_108 ( & V_294 -> V_207 ) ;
F_158 (cmd, n, &priv->cmd_queue, queue) {
F_47 ( & V_29 -> V_57 ) ;
F_30 ( V_29 ) ;
}
F_30 ( V_294 ) ;
}
