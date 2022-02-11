static inline T_1 F_1 ( T_1 V_1 )
{
return ~ V_1 + 1 ;
}
static T_1 F_2 ( T_1 * V_2 , int V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
V_4 += V_2 [ V_5 ] ;
return F_1 ( V_4 ) ;
}
static void F_3 ( void * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_10 = 0 ;
V_9 -> V_11 = F_4 ( V_12 ) ;
F_5 ( V_9 ) = V_13 ;
F_6 ( V_9 ) = V_7 ;
V_9 -> V_3 = 2 ;
}
static void F_7 ( void * V_6 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_14 = F_1 ( V_9 -> V_3 ) ;
F_8 ( V_9 ) =
F_2 ( V_9 -> V_2 , V_9 -> V_3 ) ;
F_9 ( V_9 ) = 0 ;
}
static void F_10 ( void * V_6 , int V_15 )
{
struct V_8 * V_9 = V_6 ;
V_9 -> V_3 += V_15 ;
}
static bool F_11 ( void * V_6 )
{
T_1 V_16 ;
struct V_8 * V_9 = V_6 ;
if ( V_9 -> V_11 != F_4 ( V_12 ) )
return false ;
V_16 = F_1 ( V_9 -> V_3 ) ;
if ( V_16 != V_9 -> V_14 )
return false ;
V_16 = F_2 ( V_9 -> V_2 , V_9 -> V_3 ) ;
if ( V_16 != F_8 ( V_9 ) )
return false ;
return true ;
}
static bool F_12 ( struct V_8 * V_9 )
{
if ( V_9 -> V_11 != F_4 ( V_12 ) )
return false ;
if ( V_9 -> V_3 != 0 || V_9 -> V_14 != 0xFF )
return false ;
return true ;
}
static inline int F_13 ( void * V_9 )
{
struct V_8 * V_17 = V_9 ;
return sizeof( struct V_8 ) + V_17 -> V_3 + V_18 ;
}
static T_1 F_14 ( void * V_9 )
{
struct V_8 * V_17 = V_9 ;
return F_6 ( V_17 ) ;
}
static bool F_15 ( struct V_19 * V_20 , void * V_9 )
{
return ( V_20 -> V_21 -> V_22 ( V_9 ) == F_16 ( V_20 -> V_23 ) ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = F_18 ( V_25 , struct V_19 , V_26 ) ;
int V_27 ;
V_27 = V_20 -> V_28 ( V_20 , V_20 -> V_29 , V_20 -> V_30 ) ;
if ( V_27 != - V_31 )
F_19 ( V_20 -> V_32 , & V_20 -> V_33 ) ;
}
static void F_20 ( struct V_34 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_35 ;
T_1 * V_36 ;
switch ( V_34 -> V_37 ) {
case 0 :
break;
case - V_38 :
case - V_39 :
F_21 ( & V_20 -> V_40 -> V_20 ,
L_1 ,
V_34 -> V_37 ) ;
V_20 -> V_30 = V_34 -> V_37 ;
goto V_41;
case - V_42 :
default:
F_22 ( & V_20 -> V_40 -> V_20 ,
L_2 , V_34 -> V_37 ) ;
V_20 -> V_30 = V_34 -> V_37 ;
goto V_41;
}
V_36 = V_20 -> V_43 -> V_44 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_3 ) ;
F_23 ( V_45 , L_4 , V_46 , 16 , 1 ,
V_36 , V_20 -> V_21 -> V_47 ( V_36 ) , false ) ;
if ( ! V_20 -> V_21 -> V_48 ( V_36 ) ) {
F_22 ( & V_20 -> V_40 -> V_20 , L_5 ) ;
V_20 -> V_30 = - V_49 ;
goto V_41;
}
if ( ! F_15 ( V_20 , V_36 ) ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_6 ) ;
V_20 -> V_30 = - V_49 ;
goto V_41;
}
V_20 -> V_30 = 0 ;
V_41:
F_19 ( V_20 -> V_32 , & V_20 -> V_26 ) ;
}
static int F_24 ( struct V_19 * V_20 , T_2 V_50 )
{
V_20 -> V_43 -> V_51 = F_20 ;
return F_25 ( V_20 -> V_43 , V_50 ) ;
}
static void F_26 ( struct V_34 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_35 ;
struct V_8 * V_36 ;
int V_27 ;
switch ( V_34 -> V_37 ) {
case 0 :
break;
case - V_38 :
case - V_39 :
F_21 ( & V_20 -> V_40 -> V_20 ,
L_7 ,
V_34 -> V_37 ) ;
V_20 -> V_30 = V_34 -> V_37 ;
goto V_41;
case - V_42 :
default:
F_22 ( & V_20 -> V_40 -> V_20 ,
L_2 , V_34 -> V_37 ) ;
V_20 -> V_30 = V_34 -> V_37 ;
goto V_41;
}
V_36 = V_20 -> V_43 -> V_44 ;
if ( ! F_12 ( V_36 ) ) {
F_22 ( & V_20 -> V_40 -> V_20 , L_8 ) ;
V_20 -> V_30 = - V_49 ;
goto V_41;
}
V_27 = F_24 ( V_20 , V_52 ) ;
if ( V_27 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_9 , V_27 ) ;
V_20 -> V_30 = V_27 ;
goto V_41;
}
return;
V_41:
F_19 ( V_20 -> V_32 , & V_20 -> V_26 ) ;
}
static int F_27 ( struct V_19 * V_20 , T_2 V_50 )
{
V_20 -> V_43 -> V_51 = F_26 ;
return F_25 ( V_20 -> V_43 , V_50 ) ;
}
static int F_28 ( struct V_19 * V_20 , T_2 V_50 )
{
T_1 V_53 [ V_54 ] = { 0x00 , 0x00 , 0xff , 0x00 , 0xff , 0x00 } ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_20 -> V_56 -> V_44 = V_53 ;
V_20 -> V_56 -> V_57 = sizeof( V_53 ) ;
V_27 = F_25 ( V_20 -> V_56 , V_50 ) ;
return V_27 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_58 * V_59 ,
struct V_58 * V_60 ,
int V_61 ,
T_3 V_28 ,
void * V_62 )
{
int V_27 ;
V_20 -> V_23 = V_20 -> V_21 -> V_22 ( V_59 -> V_2 ) ;
V_20 -> V_28 = V_28 ;
V_20 -> V_29 = V_62 ;
V_20 -> V_56 -> V_44 = V_59 -> V_2 ;
V_20 -> V_56 -> V_57 = V_59 -> V_15 ;
V_20 -> V_43 -> V_44 = V_60 -> V_2 ;
V_20 -> V_43 -> V_57 = V_61 ;
F_23 ( V_45 , L_11 , V_46 , 16 , 1 ,
V_59 -> V_2 , V_59 -> V_15 , false ) ;
V_27 = F_25 ( V_20 -> V_56 , V_63 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_27 ( V_20 , V_63 ) ;
if ( V_27 )
goto error;
return 0 ;
error:
F_30 ( V_20 -> V_56 ) ;
return V_27 ;
}
static void F_31 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_64 )
{
int V_65 = V_64 -> V_15 ;
struct V_66 * V_21 = V_20 -> V_21 ;
F_32 ( V_64 , V_21 -> V_67 ) ;
F_33 ( V_64 , V_21 -> V_68 ) ;
V_21 -> V_69 ( V_64 -> V_2 , V_7 ) ;
V_21 -> V_70 ( V_64 -> V_2 , V_65 ) ;
V_21 -> V_71 ( V_64 -> V_2 ) ;
}
static int F_34 ( struct V_19 * V_20 , void * V_72 , int V_37 )
{
struct V_73 * V_62 = V_72 ;
struct V_58 * V_74 = V_62 -> V_74 ;
struct V_58 * V_75 = V_62 -> V_75 ;
int V_27 ;
F_35 ( V_74 ) ;
if ( V_37 < 0 ) {
V_62 -> V_76 ( V_20 , V_62 -> V_77 ,
F_36 ( V_37 ) ) ;
F_35 ( V_75 ) ;
F_37 ( V_62 ) ;
return V_37 ;
}
F_33 ( V_75 , V_20 -> V_21 -> V_47 ( V_75 -> V_2 ) ) ;
F_38 ( V_75 , V_20 -> V_21 -> V_78 ) ;
F_39 ( V_75 , V_75 -> V_15 - V_20 -> V_21 -> V_79 ) ;
V_27 = V_62 -> V_76 ( V_20 , V_62 -> V_77 , V_75 ) ;
F_37 ( V_62 ) ;
return V_27 ;
}
static int F_40 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_74 , struct V_58 * V_75 ,
int V_80 ,
T_4 V_76 ,
void * V_77 )
{
struct V_81 * V_23 ;
struct V_73 * V_62 ;
int V_27 = 0 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_12 , V_7 ) ;
V_62 = F_41 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 )
return - V_82 ;
V_62 -> V_76 = V_76 ;
V_62 -> V_77 = V_77 ;
V_62 -> V_75 = V_75 ;
V_62 -> V_74 = V_74 ;
F_31 ( V_20 , V_7 , V_74 ) ;
F_42 ( & V_20 -> V_83 ) ;
if ( ! V_20 -> V_84 ) {
V_27 = F_29 ( V_20 , V_74 , V_75 , V_80 ,
F_34 , V_62 ) ;
if ( V_27 )
goto error;
V_20 -> V_84 = 1 ;
goto V_85;
}
F_21 ( & V_20 -> V_40 -> V_20 , L_13 , V_55 ,
V_7 ) ;
V_23 = F_41 ( sizeof( struct V_81 ) , V_63 ) ;
if ( ! V_23 ) {
V_27 = - V_82 ;
goto error;
}
F_43 ( & V_23 -> V_86 ) ;
V_23 -> V_7 = V_7 ;
V_23 -> V_74 = V_74 ;
V_23 -> V_75 = V_75 ;
V_23 -> V_80 = V_80 ;
V_23 -> V_62 = V_62 ;
F_44 ( & V_23 -> V_86 , & V_20 -> V_87 ) ;
goto V_85;
error:
F_37 ( V_62 ) ;
V_85:
F_45 ( & V_20 -> V_83 ) ;
return V_27 ;
}
static int F_46 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_74 ,
T_4 V_76 ,
void * V_77 )
{
struct V_58 * V_75 ;
int V_27 ;
int V_80 = V_20 -> V_21 -> V_78 +
V_20 -> V_21 -> V_88 +
V_20 -> V_21 -> V_79 ;
V_75 = F_47 ( V_80 , V_63 ) ;
if ( ! V_75 )
return - V_82 ;
V_27 = F_40 ( V_20 , V_7 , V_74 , V_75 , V_80 , V_76 ,
V_77 ) ;
if ( V_27 )
F_35 ( V_75 ) ;
return V_27 ;
}
static int F_48 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_74 ,
T_4 V_76 ,
void * V_77 )
{
struct V_58 * V_75 ;
int V_27 ;
int V_80 = V_20 -> V_21 -> V_78 +
V_20 -> V_21 -> V_88 +
V_20 -> V_21 -> V_79 ;
V_75 = F_49 ( V_80 , V_63 ) ;
if ( ! V_75 )
return - V_82 ;
V_27 = F_40 ( V_20 , V_7 , V_74 , V_75 , V_80 , V_76 ,
V_77 ) ;
if ( V_27 )
F_35 ( V_75 ) ;
return V_27 ;
}
static int F_50 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_74 ,
T_4 V_76 ,
void * V_77 )
{
struct V_73 * V_62 ;
struct V_58 * V_75 ;
int V_27 ;
int V_80 = V_20 -> V_21 -> V_78 +
V_20 -> V_21 -> V_88 +
V_20 -> V_21 -> V_79 ;
V_75 = F_49 ( V_80 , V_63 ) ;
if ( ! V_75 )
return - V_82 ;
V_62 = F_41 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 ) {
F_35 ( V_75 ) ;
return - V_82 ;
}
V_62 -> V_76 = V_76 ;
V_62 -> V_77 = V_77 ;
V_62 -> V_75 = V_75 ;
V_62 -> V_74 = V_74 ;
F_31 ( V_20 , V_7 , V_74 ) ;
V_27 = F_29 ( V_20 , V_74 , V_75 , V_80 ,
F_34 , V_62 ) ;
if ( V_27 < 0 ) {
F_35 ( V_75 ) ;
F_37 ( V_62 ) ;
}
return V_27 ;
}
static void F_51 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = F_18 ( V_25 , struct V_19 , V_33 ) ;
struct V_81 * V_23 ;
F_42 ( & V_20 -> V_83 ) ;
if ( F_52 ( & V_20 -> V_87 ) ) {
V_20 -> V_84 = 0 ;
F_45 ( & V_20 -> V_83 ) ;
return;
}
V_23 = F_53 ( & V_20 -> V_87 , struct V_81 , V_86 ) ;
F_54 ( & V_23 -> V_86 ) ;
F_45 ( & V_20 -> V_83 ) ;
F_29 ( V_20 , V_23 -> V_74 , V_23 -> V_75 , V_23 -> V_80 ,
F_34 , V_23 -> V_62 ) ;
F_37 ( V_23 ) ;
}
static int F_55 ( struct V_19 * V_20 , void * V_72 ,
struct V_58 * V_75 )
{
struct V_89 * V_62 = V_72 ;
V_62 -> V_75 = V_75 ;
V_51 ( & V_62 -> V_90 ) ;
return 0 ;
}
static struct V_58 * F_56 ( struct V_19 * V_20 , T_1 V_7 ,
struct V_58 * V_74 )
{
int V_27 ;
struct V_89 V_62 ;
F_57 ( & V_62 . V_90 ) ;
V_27 = F_48 ( V_20 , V_7 , V_74 ,
F_55 , & V_62 ) ;
if ( V_27 ) {
F_35 ( V_74 ) ;
return F_36 ( V_27 ) ;
}
F_58 ( & V_62 . V_90 ) ;
return V_62 . V_75 ;
}
static void F_59 ( struct V_34 * V_34 )
{
struct V_19 * V_20 = V_34 -> V_35 ;
switch ( V_34 -> V_37 ) {
case 0 :
break;
case - V_38 :
case - V_39 :
F_21 ( & V_20 -> V_40 -> V_20 ,
L_7 ,
V_34 -> V_37 ) ;
break;
case - V_42 :
default:
F_22 ( & V_20 -> V_40 -> V_20 ,
L_2 , V_34 -> V_37 ) ;
}
}
static struct V_58 * F_60 ( struct V_19 * V_20 , unsigned int V_91 )
{
struct V_58 * V_64 ;
V_64 = F_49 ( V_20 -> V_21 -> V_67 +
V_91 +
V_20 -> V_21 -> V_68 , V_63 ) ;
if ( V_64 )
F_61 ( V_64 , V_20 -> V_21 -> V_67 ) ;
return V_64 ;
}
static bool F_62 ( struct V_92 * V_93 ,
int V_94 )
{
T_1 V_95 ;
T_1 V_96 ;
if ( V_94 < sizeof( struct V_92 ) )
return false ;
V_95 = F_63 ( V_93 -> V_97 ) ;
V_96 = F_64 ( V_93 -> V_97 ) ;
if ( ( V_95 == V_98 &&
V_96 != V_99 ) ||
( V_95 != V_98 &&
V_96 == V_99 ) )
return false ;
if ( F_65 ( V_93 -> V_100 ) != 0 )
return false ;
return true ;
}
static int F_66 ( struct V_101 * V_102 , T_1 * V_103 ,
int V_104 )
{
struct V_92 * V_105 ;
V_105 = (struct V_92 * ) V_103 ;
if ( ! F_62 ( V_105 , V_104 ) )
return - V_106 ;
switch ( F_67 ( V_105 -> V_100 ) ) {
case V_107 :
V_102 -> V_108 = V_109 ;
break;
case V_110 :
V_102 -> V_108 = V_111 ;
break;
case V_112 :
V_102 -> V_108 = V_113 ;
break;
case V_114 :
V_102 -> V_108 = V_111 |
V_113 ;
break;
}
V_102 -> V_97 = F_68 ( V_105 -> V_97 ) ;
V_102 -> V_100 = V_105 -> V_100 ;
V_102 -> V_115 = V_105 -> V_116 ;
memcpy ( V_102 -> V_117 , V_105 -> V_118 , V_102 -> V_115 ) ;
return 0 ;
}
static bool F_69 ( struct V_119 * V_120 ,
int V_94 )
{
if ( V_94 < sizeof( struct V_119 ) )
return false ;
if ( V_120 -> V_121 != V_122 )
return false ;
return true ;
}
static int F_70 ( struct V_101 * V_102 , T_1 * V_103 ,
int V_104 )
{
struct V_119 * V_123 ;
V_123 = (struct V_119 * ) V_103 ;
if ( ! F_69 ( V_123 , V_104 ) )
return - V_106 ;
if ( ( V_123 -> V_124 [ 0 ] == V_125 ) &&
( V_123 -> V_124 [ 1 ] == V_126 ) )
V_102 -> V_108 = V_113 ;
else
V_102 -> V_108 = V_127 ;
memcpy ( V_102 -> V_128 , & V_123 -> V_121 , 9 ) ;
V_102 -> V_129 = 9 ;
return 0 ;
}
static bool F_71 ( struct V_130 * V_131 ,
int V_94 )
{
T_1 V_95 ;
T_1 V_96 ;
if ( V_94 < sizeof( struct V_130 ) )
return false ;
V_95 = F_63 ( V_131 -> V_97 ) ;
V_96 = F_64 ( V_131 -> V_97 ) ;
if ( ( V_95 == V_98 &&
V_96 != V_99 ) ||
( V_95 != V_98 &&
V_96 == V_99 ) )
return false ;
return true ;
}
static int F_72 ( struct V_101 * V_102 , T_1 * V_103 ,
int V_104 )
{
struct V_130 * V_132 ;
V_132 = (struct V_130 * ) V_103 ;
if ( ! F_71 ( V_132 , V_104 ) )
return - V_106 ;
V_102 -> V_108 = V_133 ;
V_102 -> V_97 = F_68 ( V_132 -> V_97 ) ;
V_102 -> V_115 = 4 ;
memcpy ( V_102 -> V_117 , V_132 -> V_134 , V_102 -> V_115 ) ;
return 0 ;
}
static bool F_73 ( struct V_135 * V_136 ,
int V_94 )
{
if ( V_94 < sizeof( struct V_135 ) )
return false ;
if ( V_136 -> V_137 . V_121 != V_138 )
return false ;
if ( F_74 ( V_136 -> V_137 . V_139 . V_140 ) &
V_141 )
return false ;
return true ;
}
static int F_75 ( struct V_101 * V_102 , T_1 * V_103 ,
int V_104 )
{
struct V_135 * V_142 ;
V_142 = (struct V_135 * ) V_103 ;
if ( ! F_73 ( V_142 , V_104 ) )
return - V_106 ;
V_102 -> V_108 = V_143 ;
return 0 ;
}
static int F_76 ( struct V_19 * V_20 , T_1 V_144 , T_1 * V_145 ,
int V_146 )
{
struct V_101 V_102 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_14 , V_55 ,
V_20 -> V_147 ) ;
if ( V_144 != 1 )
return - V_106 ;
memset ( & V_102 , 0 , sizeof( struct V_101 ) ) ;
switch ( V_20 -> V_147 ) {
case V_148 :
V_27 = F_66 ( & V_102 , V_145 , V_146 ) ;
break;
case V_149 :
case V_150 :
V_27 = F_70 ( & V_102 , V_145 , V_146 ) ;
break;
case V_151 :
V_27 = F_72 ( & V_102 , V_145 , V_146 ) ;
break;
case V_152 :
V_27 = F_75 ( & V_102 , V_145 , V_146 ) ;
break;
default:
F_22 ( & V_20 -> V_40 -> V_20 ,
L_15 ) ;
return - V_106 ;
}
if ( V_27 )
return V_27 ;
if ( ! ( V_102 . V_108 & V_20 -> V_153 ) ) {
F_21 ( & V_20 -> V_40 -> V_20 ,
L_16 ) ;
return - V_154 ;
}
F_21 ( & V_20 -> V_40 -> V_20 ,
L_17 ,
V_102 . V_108 ) ;
V_20 -> V_155 = V_102 . V_108 ;
F_77 ( V_20 -> V_156 , & V_102 , 1 ) ;
return 0 ;
}
static inline void F_78 ( struct V_19 * V_20 )
{
V_20 -> V_147 = ( V_20 -> V_147 + 1 ) % V_20 -> V_157 ;
}
static void F_79 ( struct V_19 * V_20 )
{
V_20 -> V_157 = 0 ;
}
static void F_80 ( struct V_19 * V_20 , T_1 V_158 )
{
V_20 -> V_159 [ V_20 -> V_157 ] =
(struct V_160 * ) & V_161 [ V_158 ] ;
V_20 -> V_157 ++ ;
}
static void F_81 ( struct V_19 * V_20 ,
T_5 V_162 , T_5 V_163 )
{
F_79 ( V_20 ) ;
if ( ( V_162 & V_109 ) ||
( V_162 & V_111 ) ||
( V_162 & V_113 ) )
F_80 ( V_20 , V_148 ) ;
if ( V_162 & V_127 ||
V_162 & V_113 ) {
F_80 ( V_20 , V_149 ) ;
F_80 ( V_20 , V_150 ) ;
}
if ( V_162 & V_133 )
F_80 ( V_20 , V_151 ) ;
if ( V_162 & V_143 )
F_80 ( V_20 , V_152 ) ;
if ( V_163 )
F_80 ( V_20 , V_164 ) ;
}
static int F_82 ( struct V_19 * V_20 , struct V_58 * V_75 )
{
T_1 V_165 , V_144 , * V_145 ;
int V_27 , V_146 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_165 = V_75 -> V_2 [ 0 ] ;
V_144 = V_75 -> V_2 [ 1 ] ;
V_145 = & V_75 -> V_2 [ 2 ] ;
V_146 = V_75 -> V_15 - 2 ;
if ( V_165 ) {
V_27 = F_76 ( V_20 , V_144 , V_145 , V_146 ) ;
if ( V_27 == 0 ) {
F_79 ( V_20 ) ;
return 0 ;
}
}
return - V_154 ;
}
static struct V_58 * F_83 ( struct V_19 * V_20 )
{
struct V_58 * V_64 ;
T_1 * V_120 , * V_166 , * V_167 ;
T_1 * V_168 = V_20 -> V_167 ;
T_6 V_169 = V_20 -> V_170 ;
T_1 V_171 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_172 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_173 = 36 +
V_169 +
1 ;
V_64 = F_60 ( V_20 , V_173 ) ;
if ( ! V_64 )
return NULL ;
* F_33 ( V_64 , 1 ) = V_174 ;
memcpy ( F_33 ( V_64 , 6 ) , V_172 , 6 ) ;
V_120 = F_33 ( V_64 , 18 ) ;
memcpy ( V_120 , V_171 , 18 ) ;
F_84 ( V_120 + 2 , 6 ) ;
V_166 = F_33 ( V_64 , 10 ) ;
memset ( V_166 , 0 , 10 ) ;
memcpy ( V_166 , V_120 , 8 ) ;
* F_33 ( V_64 , 1 ) = V_169 ;
V_167 = F_33 ( V_64 , V_169 ) ;
memcpy ( V_167 , V_168 , V_169 ) ;
* F_33 ( V_64 , 1 ) = 0 ;
return V_64 ;
}
static int F_85 ( struct V_19 * V_20 , void * V_62 ,
struct V_58 * V_75 )
{
T_1 V_37 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
V_37 = V_75 -> V_2 [ 0 ] ;
F_38 ( V_75 , sizeof( V_37 ) ) ;
if ( V_37 != 0 ) {
F_88 ( V_20 -> V_156 ) ;
V_20 -> V_175 = 0 ;
F_35 ( V_75 ) ;
return 0 ;
}
return F_89 ( V_20 -> V_156 , V_75 ) ;
}
static void F_90 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = F_18 ( V_25 , struct V_19 , V_176 ) ;
struct V_58 * V_64 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_64 = F_60 ( V_20 , 0 ) ;
if ( ! V_64 )
return;
V_27 = F_46 ( V_20 , V_177 , V_64 ,
F_85 , NULL ) ;
if ( V_27 < 0 )
F_35 ( V_64 ) ;
return;
}
static int F_91 ( struct V_19 * V_20 , struct V_58 * V_75 )
{
T_1 V_178 , * V_23 , V_179 = V_180 , * V_167 ;
T_6 V_170 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( V_75 -> V_15 < V_181 + 1 )
return - V_182 ;
V_178 = V_75 -> V_2 [ 0 ] ;
V_23 = & V_75 -> V_2 [ 1 ] ;
F_21 ( & V_20 -> V_40 -> V_20 , L_18 ,
V_178 , V_75 -> V_15 ) ;
if ( ( V_178 & V_183 ) ==
V_184 )
V_179 = V_185 ;
if ( ( V_178 & V_186 ) == 0 )
return - V_187 ;
V_167 = V_23 + V_181 ;
V_170 = V_75 -> V_15 - ( V_181 + 1 ) ;
V_27 = F_92 ( V_20 -> V_156 , V_113 ,
V_179 , V_167 , V_170 ) ;
if ( V_27 < 0 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_19 ) ;
return V_27 ;
}
V_20 -> V_175 = 1 ;
F_19 ( V_20 -> V_32 , & V_20 -> V_176 ) ;
return 0 ;
}
static void F_93 ( unsigned long V_2 )
{
struct V_19 * V_20 = (struct V_19 * ) V_2 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_20 ) ;
F_28 ( V_20 , V_52 ) ;
V_20 -> V_188 = 1 ;
F_78 ( V_20 ) ;
F_19 ( V_20 -> V_32 , & V_20 -> V_189 ) ;
}
static int F_94 ( struct V_19 * V_20 , void * V_62 ,
struct V_58 * V_75 )
{
struct V_160 * V_190 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( F_86 ( V_75 ) ) {
V_27 = F_87 ( V_75 ) ;
F_22 ( & V_20 -> V_40 -> V_20 , L_21 ,
V_55 , V_27 ) ;
if ( V_27 == - V_39 ) {
if ( V_20 -> V_157 != 0 )
return V_27 ;
else
goto V_191;
} else if ( V_27 < 0 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_22 , V_27 ) ;
goto V_191;
}
}
V_190 = V_20 -> V_159 [ V_20 -> V_147 ] ;
if ( V_190 -> V_15 == 0 ) {
F_95 ( & V_20 -> V_192 ) ;
V_27 = F_91 ( V_20 , V_75 ) ;
goto V_90;
}
V_27 = F_82 ( V_20 , V_75 ) ;
if ( ! V_27 )
goto V_90;
F_78 ( V_20 ) ;
F_19 ( V_20 -> V_32 , & V_20 -> V_189 ) ;
V_90:
F_35 ( V_75 ) ;
return V_27 ;
V_191:
F_22 ( & V_20 -> V_40 -> V_20 , L_23 ) ;
F_79 ( V_20 ) ;
V_20 -> V_153 = 0 ;
return V_27 ;
}
static struct V_58 * F_96 ( struct V_19 * V_20 ,
struct V_160 * V_193 )
{
struct V_58 * V_64 ;
V_64 = F_60 ( V_20 , V_193 -> V_15 ) ;
if ( ! V_64 )
return NULL ;
memcpy ( F_33 ( V_64 , V_193 -> V_15 ) , & V_193 -> V_2 , V_193 -> V_15 ) ;
return V_64 ;
}
static int F_97 ( struct V_19 * V_20 )
{
struct V_160 * V_193 ;
struct V_58 * V_64 ;
int V_27 ;
T_1 V_7 ;
V_193 = V_20 -> V_159 [ V_20 -> V_147 ] ;
F_21 ( & V_20 -> V_40 -> V_20 , L_24 ,
V_55 , V_193 -> V_15 ) ;
if ( V_193 -> V_15 == 0 ) {
V_7 = V_194 ;
V_64 = F_83 ( V_20 ) ;
} else {
V_7 = V_195 ;
V_64 = F_96 ( V_20 , V_193 ) ;
}
if ( ! V_64 ) {
F_22 ( & V_20 -> V_40 -> V_20 , L_25 ) ;
return - V_82 ;
}
V_27 = F_48 ( V_20 , V_7 , V_64 , F_94 ,
NULL ) ;
if ( V_27 < 0 ) {
F_35 ( V_64 ) ;
F_22 ( & V_20 -> V_40 -> V_20 , L_26 , V_27 ) ;
}
return V_27 ;
}
static void F_98 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = F_18 ( V_25 , struct V_19 , V_189 ) ;
struct V_160 * V_190 ;
int V_27 ;
V_190 = V_20 -> V_159 [ V_20 -> V_147 ] ;
F_21 ( & V_20 -> V_40 -> V_20 ,
L_27 ,
V_55 , V_20 -> V_188 , V_190 -> V_15 ) ;
if ( V_20 -> V_188 == 1 ) {
V_20 -> V_188 = 0 ;
F_99 ( V_20 -> V_43 ) ;
}
V_27 = F_97 ( V_20 ) ;
if ( V_27 )
return;
if ( V_190 -> V_15 == 0 && V_20 -> V_157 > 1 )
F_100 ( & V_20 -> V_192 , V_196 + V_197 * V_198 ) ;
return;
}
static int F_101 ( struct V_156 * V_156 ,
T_5 V_162 , T_5 V_163 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
F_21 ( & V_20 -> V_40 -> V_20 ,
L_28 ,
V_55 , V_162 , V_163 ) ;
if ( V_20 -> V_199 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_29 ) ;
return - V_200 ;
}
if ( V_20 -> V_175 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_30 ) ;
return - V_200 ;
}
if ( V_163 ) {
V_20 -> V_167 = F_103 ( V_156 , & V_20 -> V_170 ) ;
if ( V_20 -> V_167 == NULL )
V_163 = 0 ;
}
V_20 -> V_147 = 0 ;
F_81 ( V_20 , V_162 , V_163 ) ;
V_20 -> V_153 = V_162 ;
V_20 -> V_201 = V_163 ;
return F_97 ( V_20 ) ;
}
static void F_104 ( struct V_156 * V_156 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
F_95 ( & V_20 -> V_192 ) ;
if ( ! V_20 -> V_157 ) {
F_21 ( & V_20 -> V_40 -> V_20 ,
L_31 ) ;
return;
}
F_28 ( V_20 , V_63 ) ;
F_99 ( V_20 -> V_43 ) ;
F_79 ( V_20 ) ;
}
static int F_105 ( struct V_19 * V_20 )
{
struct V_202 * V_203 ;
T_7 V_204 ;
int V_27 ;
struct V_58 * V_64 ;
struct V_58 * V_75 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_64 = F_60 ( V_20 , sizeof( T_1 ) * 2 ) ;
if ( ! V_64 )
return - V_82 ;
* F_33 ( V_64 , sizeof( T_1 ) ) = 1 ;
* F_33 ( V_64 , sizeof( T_1 ) ) = 0 ;
V_75 = F_56 ( V_20 , V_205 , V_64 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
V_203 = (struct V_202 * ) V_75 -> V_2 ;
V_27 = V_203 -> V_37 & V_206 ;
if ( V_27 != V_207 ) {
F_35 ( V_75 ) ;
return - V_49 ;
}
V_204 = V_75 -> V_15 - 16 ;
V_27 = F_106 ( V_20 -> V_156 , V_203 -> V_208 , V_204 ) ;
F_35 ( V_75 ) ;
return V_27 ;
}
static int F_107 ( struct V_156 * V_156 ,
struct V_101 * V_209 , T_5 V_210 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_32 , V_55 ,
V_210 ) ;
if ( V_20 -> V_157 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_33 ) ;
return - V_200 ;
}
if ( V_20 -> V_199 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_34 ) ;
return - V_200 ;
}
if ( ! V_20 -> V_155 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_35 ) ;
return - V_182 ;
}
if ( ! ( V_20 -> V_155 & ( 1 << V_210 ) ) ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_36 ,
V_210 ) ;
return - V_182 ;
}
if ( V_210 == V_211 ) {
V_27 = F_105 ( V_20 ) ;
if ( V_27 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_37 , V_27 ) ;
return V_27 ;
}
}
V_20 -> V_199 = V_210 ;
V_20 -> V_155 = 0 ;
return 0 ;
}
static void F_108 ( struct V_156 * V_156 ,
struct V_101 * V_209 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
struct V_58 * V_64 ;
struct V_58 * V_75 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( ! V_20 -> V_199 ) {
F_22 ( & V_20 -> V_40 -> V_20 , L_38 ) ;
return;
}
V_20 -> V_199 = 0 ;
F_109 ( & V_20 -> V_212 ) ;
V_64 = F_60 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_64 )
return;
* F_33 ( V_64 , 1 ) = 1 ;
V_75 = F_56 ( V_20 , V_213 , V_64 ) ;
if ( F_86 ( V_75 ) )
return;
V_27 = V_75 -> V_2 [ 0 ] & V_206 ;
if ( V_27 != V_207 )
F_22 ( & V_20 -> V_40 -> V_20 ,
L_39 , V_27 ) ;
F_35 ( V_75 ) ;
return;
}
static int F_110 ( struct V_19 * V_20 , void * V_62 ,
struct V_58 * V_75 )
{
struct V_214 * V_203 ;
T_1 V_215 ;
int V_27 ;
T_1 V_216 = * ( T_1 * ) V_62 ;
F_37 ( V_62 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
if ( V_20 -> V_155 &&
! ( V_20 -> V_155 & ( 1 << V_211 ) ) ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_40 ) ;
V_27 = - V_182 ;
goto error;
}
V_203 = (struct V_214 * ) V_75 -> V_2 ;
V_27 = V_203 -> V_37 & V_206 ;
if ( V_27 != V_207 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_41 , V_27 ) ;
goto error;
}
if ( ! V_20 -> V_155 ) {
struct V_101 V_101 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_42 ) ;
V_101 . V_108 = V_113 ;
V_101 . V_115 = 10 ;
memcpy ( V_101 . V_117 , V_203 -> V_217 , V_101 . V_115 ) ;
V_27 = F_77 ( V_20 -> V_156 , & V_101 , 1 ) ;
if ( V_27 )
goto error;
V_20 -> V_155 = 0 ;
}
V_20 -> V_199 = V_211 ;
V_215 = V_75 -> V_15 - 17 ;
V_27 = F_106 ( V_20 -> V_156 ,
V_203 -> V_208 , V_215 ) ;
if ( V_27 == 0 )
V_27 = F_111 ( V_20 -> V_156 ,
V_20 -> V_156 -> V_218 [ 0 ] . V_219 ,
! V_216 , V_220 ) ;
error:
F_35 ( V_75 ) ;
return V_27 ;
}
static int F_112 ( struct V_19 * V_20 )
{
switch ( V_20 -> V_147 ) {
case V_148 :
return 0 ;
case V_149 :
return 1 ;
case V_150 :
return 2 ;
default:
return - V_182 ;
}
}
static int F_113 ( struct V_156 * V_156 , struct V_101 * V_209 ,
T_1 V_179 , T_1 * V_167 , T_6 V_170 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
struct V_58 * V_64 ;
int V_27 , V_221 , V_173 ;
T_1 * V_222 , * V_62 ;
T_1 V_223 [ V_224 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( V_20 -> V_157 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_43 ) ;
return - V_200 ;
}
if ( V_20 -> V_199 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_34 ) ;
return - V_200 ;
}
V_221 = F_112 ( V_20 ) ;
if ( V_221 < 0 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_44 , V_20 -> V_147 ) ;
return V_221 ;
}
V_173 = 3 + V_170 ;
if ( V_179 == V_180 )
V_173 += V_224 ;
V_64 = F_60 ( V_20 , V_173 ) ;
if ( ! V_64 )
return - V_82 ;
* F_33 ( V_64 , 1 ) = ! V_179 ;
* F_33 ( V_64 , 1 ) = V_221 ;
V_222 = F_33 ( V_64 , 1 ) ;
* V_222 = 0 ;
if ( V_179 == V_180 && V_221 > 0 ) {
memcpy ( F_33 ( V_64 , V_224 ) , V_223 ,
V_224 ) ;
* V_222 |= 1 ;
}
if ( V_167 != NULL && V_170 > 0 ) {
memcpy ( F_33 ( V_64 , V_170 ) , V_167 , V_170 ) ;
* V_222 |= 4 ;
} else {
* V_222 = 0 ;
}
V_62 = F_114 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 ) {
F_35 ( V_64 ) ;
return - V_82 ;
}
* V_62 = ! V_179 ;
V_27 = F_48 ( V_20 , V_225 , V_64 ,
F_110 , V_62 ) ;
if ( V_27 < 0 ) {
F_35 ( V_64 ) ;
F_37 ( V_62 ) ;
}
return V_27 ;
}
static int F_115 ( struct V_156 * V_156 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
F_79 ( V_20 ) ;
if ( V_20 -> V_175 || V_20 -> V_199 ) {
F_28 ( V_20 , V_63 ) ;
F_99 ( V_20 -> V_43 ) ;
}
V_20 -> V_199 = 0 ;
V_20 -> V_175 = 0 ;
F_109 ( & V_20 -> V_212 ) ;
return 0 ;
}
static struct V_58 * F_116 ( struct V_19 * V_20 )
{
struct V_58 * V_64 , * V_226 , * V_227 ;
unsigned int V_173 = 0 , V_228 = 0 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( F_117 ( & V_20 -> V_212 ) )
return NULL ;
if ( F_118 ( & V_20 -> V_212 ) == 1 ) {
V_64 = F_119 ( & V_20 -> V_212 ) ;
goto V_59;
}
F_120 (&dev->resp_q, tmp, t)
V_173 += V_226 -> V_15 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_45 ,
V_55 , V_173 ) ;
V_64 = F_49 ( V_173 , V_63 ) ;
if ( V_64 == NULL )
goto V_59;
F_33 ( V_64 , V_173 ) ;
F_120 (&dev->resp_q, tmp, t) {
memcpy ( V_64 -> V_2 + V_228 , V_226 -> V_2 , V_226 -> V_15 ) ;
V_228 += V_226 -> V_15 ;
}
V_59:
F_109 ( & V_20 -> V_212 ) ;
return V_64 ;
}
static int F_121 ( struct V_19 * V_20 , void * V_72 ,
struct V_58 * V_75 )
{
struct V_229 * V_62 = V_72 ;
struct V_58 * V_64 ;
int V_27 = 0 ;
T_1 V_37 , V_230 , V_231 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( F_86 ( V_75 ) ) {
V_27 = F_87 ( V_75 ) ;
goto V_232;
}
V_37 = V_75 -> V_2 [ 0 ] ;
V_230 = V_37 & V_206 ;
V_231 = V_37 & V_233 ;
F_38 ( V_75 , sizeof( V_37 ) ) ;
if ( V_230 != V_207 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_46 ,
V_230 ) ;
V_27 = - V_49 ;
goto error;
}
F_122 ( & V_20 -> V_212 , V_75 ) ;
if ( V_231 ) {
V_20 -> V_234 = V_62 ;
F_19 ( V_20 -> V_32 , & V_20 -> V_235 ) ;
return - V_31 ;
}
V_64 = F_116 ( V_20 ) ;
if ( ! V_64 )
goto error;
V_62 -> V_236 ( V_62 -> V_237 , V_64 , 0 ) ;
F_37 ( V_62 ) ;
return 0 ;
error:
F_35 ( V_75 ) ;
V_232:
F_109 ( & V_20 -> V_212 ) ;
V_62 -> V_236 ( V_62 -> V_237 , NULL , V_27 ) ;
F_37 ( V_62 ) ;
return V_27 ;
}
static int F_123 ( struct V_156 * V_156 ,
struct V_101 * V_209 , struct V_58 * V_64 ,
T_8 V_236 , void * V_237 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
struct V_229 * V_62 = NULL ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( V_64 -> V_15 > V_238 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_47 ,
V_238 ) ;
V_27 = - V_239 ;
goto error;
}
if ( ! V_20 -> V_199 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_48 ) ;
V_27 = - V_182 ;
goto error;
}
V_62 = F_114 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 ) {
V_27 = - V_82 ;
goto error;
}
V_62 -> V_236 = V_236 ;
V_62 -> V_237 = V_237 ;
switch ( V_20 -> V_240 ) {
case V_241 :
if ( V_20 -> V_199 == V_242 ) {
V_27 = F_46 ( V_20 , V_243 ,
V_64 ,
F_121 ,
V_62 ) ;
break;
}
default:
* F_32 ( V_64 , sizeof( T_1 ) ) = 1 ;
V_27 = F_46 ( V_20 , V_244 ,
V_64 , F_121 ,
V_62 ) ;
break;
}
if ( V_27 < 0 )
goto error;
return 0 ;
error:
F_37 ( V_62 ) ;
F_35 ( V_64 ) ;
return V_27 ;
}
static int F_124 ( struct V_19 * V_20 , void * V_62 ,
struct V_58 * V_75 )
{
T_1 V_37 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
V_37 = V_75 -> V_2 [ 0 ] ;
F_35 ( V_75 ) ;
if ( V_37 != 0 ) {
F_88 ( V_20 -> V_156 ) ;
V_20 -> V_175 = 0 ;
return 0 ;
}
F_19 ( V_20 -> V_32 , & V_20 -> V_176 ) ;
return 0 ;
}
static int F_125 ( struct V_156 * V_156 , struct V_58 * V_64 )
{
struct V_19 * V_20 = F_102 ( V_156 ) ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
if ( V_64 -> V_15 > V_238 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_47 ,
V_238 ) ;
return - V_239 ;
}
V_27 = F_46 ( V_20 , V_245 , V_64 ,
F_124 , NULL ) ;
if ( V_27 < 0 )
F_35 ( V_64 ) ;
return V_27 ;
}
static void F_126 ( struct V_24 * V_25 )
{
struct V_19 * V_20 = F_18 ( V_25 , struct V_19 , V_235 ) ;
struct V_58 * V_64 ;
int V_27 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_64 = F_60 ( V_20 , V_246 ) ;
if ( ! V_64 )
goto error;
switch ( V_20 -> V_240 ) {
case V_241 :
if ( V_20 -> V_199 == V_242 ) {
V_27 = F_50 ( V_20 ,
V_243 ,
V_64 ,
F_121 ,
V_20 -> V_234 ) ;
break;
}
default:
* F_33 ( V_64 , sizeof( T_1 ) ) = 1 ;
V_27 = F_50 ( V_20 ,
V_244 ,
V_64 ,
F_121 ,
V_20 -> V_234 ) ;
break;
}
if ( V_27 == 0 )
return;
F_22 ( & V_20 -> V_40 -> V_20 ,
L_49 , V_27 ) ;
F_35 ( V_64 ) ;
F_37 ( V_20 -> V_29 ) ;
error:
F_28 ( V_20 , V_63 ) ;
F_19 ( V_20 -> V_32 , & V_20 -> V_33 ) ;
}
static int F_127 ( struct V_19 * V_20 , T_1 V_247 , T_1 * V_248 ,
T_1 V_249 )
{
struct V_58 * V_64 ;
struct V_58 * V_75 ;
int V_173 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_173 = sizeof( V_247 ) + V_249 ;
V_64 = F_60 ( V_20 , V_173 ) ;
if ( ! V_64 )
return - V_82 ;
* F_33 ( V_64 , sizeof( V_247 ) ) = V_247 ;
memcpy ( F_33 ( V_64 , V_249 ) , V_248 , V_249 ) ;
V_75 = F_56 ( V_20 , V_250 , V_64 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
F_35 ( V_75 ) ;
return 0 ;
}
static int F_128 ( struct V_19 * V_20 ,
struct V_251 * V_252 )
{
struct V_58 * V_64 ;
struct V_58 * V_75 ;
V_64 = F_60 ( V_20 , 0 ) ;
if ( ! V_64 )
return - V_82 ;
V_75 = F_56 ( V_20 , V_253 , V_64 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
V_252 -> V_254 = V_75 -> V_2 [ 0 ] ;
V_252 -> V_255 = V_75 -> V_2 [ 1 ] ;
V_252 -> V_256 = V_75 -> V_2 [ 2 ] ;
V_252 -> V_257 = V_75 -> V_2 [ 3 ] ;
F_35 ( V_75 ) ;
return 0 ;
}
static int F_129 ( struct V_19 * V_20 )
{
struct V_58 * V_64 ;
struct V_58 * V_75 ;
F_21 ( & V_20 -> V_40 -> V_20 , L_10 , V_55 ) ;
V_64 = F_60 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_64 )
return - V_82 ;
* F_33 ( V_64 , sizeof( T_1 ) ) = 0x1 ;
V_75 = F_56 ( V_20 , 0x18 , V_64 ) ;
if ( F_86 ( V_75 ) )
return F_87 ( V_75 ) ;
F_35 ( V_75 ) ;
return 0 ;
}
static int F_130 ( struct V_19 * V_20 )
{
struct V_258 V_259 ;
struct V_260 V_261 ;
T_1 V_262 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_27 ;
switch ( V_20 -> V_240 ) {
case V_263 :
V_259 . V_264 = V_265 ;
V_259 . V_266 = 2 ;
V_259 . V_267 =
V_268 ;
V_261 . V_269 = V_270 ;
V_261 . V_271 = V_272 ;
V_261 . V_273 = V_274 ;
break;
case V_241 :
V_259 . V_264 = 0x2 ;
V_259 . V_266 = 0x1 ;
V_259 . V_267 =
V_268 ;
V_261 . V_269 = V_270 ;
V_261 . V_271 = V_270 ;
V_261 . V_273 = V_272 ;
break;
default:
F_22 ( & V_20 -> V_40 -> V_20 , L_50 ,
V_20 -> V_240 ) ;
return - V_182 ;
}
V_27 = F_127 ( V_20 , V_275 ,
( T_1 * ) & V_259 , sizeof( V_259 ) ) ;
if ( V_27 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_51 ) ;
return V_27 ;
}
V_27 = F_127 ( V_20 , V_276 ,
( T_1 * ) & V_261 , sizeof( V_261 ) ) ;
if ( V_27 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_52 ) ;
return V_27 ;
}
switch ( V_20 -> V_240 ) {
case V_263 :
break;
case V_241 :
F_129 ( V_20 ) ;
V_27 = F_127 ( V_20 , V_277 ,
V_262 , 3 ) ;
if ( V_27 ) {
F_22 ( & V_20 -> V_40 -> V_20 ,
L_53 ) ;
return V_27 ;
}
F_129 ( V_20 ) ;
break;
}
return 0 ;
}
static int F_131 ( struct V_278 * V_40 ,
const struct V_279 * V_280 )
{
struct V_251 V_281 ;
struct V_19 * V_20 ;
struct V_282 * V_283 ;
struct V_284 * V_285 ;
int V_286 = 0 ;
int V_287 = 0 ;
int V_27 = - V_82 ;
int V_5 ;
T_5 V_288 ;
V_20 = F_41 ( sizeof( * V_20 ) , V_63 ) ;
if ( ! V_20 )
return - V_82 ;
V_20 -> V_289 = F_132 ( F_133 ( V_40 ) ) ;
V_20 -> V_40 = V_40 ;
F_134 ( & V_20 -> V_83 ) ;
V_283 = V_40 -> V_290 ;
for ( V_5 = 0 ; V_5 < V_283 -> V_291 . V_292 ; ++ V_5 ) {
V_285 = & V_283 -> V_285 [ V_5 ] . V_291 ;
if ( ! V_286 && F_135 ( V_285 ) )
V_286 = V_285 -> V_293 ;
if ( ! V_287 && F_136 ( V_285 ) )
V_287 = V_285 -> V_293 ;
}
if ( ! V_286 || ! V_287 ) {
F_22 ( & V_40 -> V_20 ,
L_54 ) ;
V_27 = - V_294 ;
goto error;
}
V_20 -> V_43 = F_137 ( 0 , V_63 ) ;
V_20 -> V_56 = F_137 ( 0 , V_63 ) ;
if ( ! V_20 -> V_43 || ! V_20 -> V_56 )
goto error;
F_138 ( V_20 -> V_43 , V_20 -> V_289 ,
F_139 ( V_20 -> V_289 , V_286 ) ,
NULL , 0 , NULL , V_20 ) ;
F_138 ( V_20 -> V_56 , V_20 -> V_289 ,
F_140 ( V_20 -> V_289 , V_287 ) ,
NULL , 0 , F_59 , V_20 ) ;
F_141 ( & V_20 -> V_33 , F_51 ) ;
F_141 ( & V_20 -> V_26 , F_17 ) ;
F_141 ( & V_20 -> V_235 , F_126 ) ;
F_141 ( & V_20 -> V_176 , F_90 ) ;
F_141 ( & V_20 -> V_189 , F_98 ) ;
V_20 -> V_32 = F_142 ( L_55 , 0 ) ;
if ( V_20 -> V_32 == NULL )
goto error;
F_143 ( & V_20 -> V_192 ) ;
V_20 -> V_192 . V_2 = ( unsigned long ) V_20 ;
V_20 -> V_192 . V_295 = F_93 ;
F_144 ( & V_20 -> V_212 ) ;
F_43 ( & V_20 -> V_87 ) ;
F_145 ( V_40 , V_20 ) ;
V_20 -> V_21 = & V_296 ;
V_20 -> V_240 = V_280 -> V_297 ;
switch ( V_20 -> V_240 ) {
case V_263 :
V_288 = V_298 ;
break;
case V_241 :
V_288 = V_299 ;
break;
default:
F_22 ( & V_20 -> V_40 -> V_20 , L_50 ,
V_20 -> V_240 ) ;
V_27 = - V_182 ;
goto V_300;
}
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_27 = F_128 ( V_20 , & V_281 ) ;
if ( V_27 < 0 )
goto V_300;
F_146 ( & V_20 -> V_40 -> V_20 ,
L_56 ,
V_281 . V_255 , V_281 . V_256 ) ;
V_20 -> V_156 = F_147 ( & V_301 , V_288 ,
V_302 ,
V_20 -> V_21 -> V_67 +
V_246 ,
V_20 -> V_21 -> V_68 ) ;
if ( ! V_20 -> V_156 )
goto V_300;
F_148 ( V_20 -> V_156 , & V_40 -> V_20 ) ;
F_149 ( V_20 -> V_156 , V_20 ) ;
V_27 = F_150 ( V_20 -> V_156 ) ;
if ( V_27 )
goto V_303;
V_27 = F_130 ( V_20 ) ;
if ( V_27 )
goto V_304;
return 0 ;
V_304:
F_151 ( V_20 -> V_156 ) ;
V_303:
F_152 ( V_20 -> V_156 ) ;
V_300:
F_153 ( V_20 -> V_32 ) ;
error:
F_154 ( V_20 -> V_43 ) ;
F_154 ( V_20 -> V_56 ) ;
F_37 ( V_20 ) ;
return V_27 ;
}
static void F_155 ( struct V_278 * V_40 )
{
struct V_19 * V_20 ;
struct V_81 * V_23 , * V_305 ;
V_20 = F_156 ( V_40 ) ;
F_145 ( V_40 , NULL ) ;
F_151 ( V_20 -> V_156 ) ;
F_152 ( V_20 -> V_156 ) ;
F_99 ( V_20 -> V_43 ) ;
F_99 ( V_20 -> V_56 ) ;
F_153 ( V_20 -> V_32 ) ;
F_109 ( & V_20 -> V_212 ) ;
F_95 ( & V_20 -> V_192 ) ;
F_157 (cmd, n, &dev->cmd_queue, queue) {
F_54 ( & V_23 -> V_86 ) ;
F_37 ( V_23 ) ;
}
F_154 ( V_20 -> V_43 ) ;
F_154 ( V_20 -> V_56 ) ;
F_37 ( V_20 ) ;
F_146 ( & V_40 -> V_20 , L_57 ) ;
}
