static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_5 . type = V_6 ;
V_4 -> V_5 . V_7 = sizeof( V_4 -> V_8 ) + 1 ;
V_4 -> V_5 . V_9 = 0 ;
V_4 -> V_5 . V_10 = 0 ;
V_4 -> V_5 . V_11 [ 0 ] = 0 ;
V_4 -> V_5 . V_11 [ 1 ] = 0 ;
V_4 -> V_5 . V_11 [ 2 ] = 0 ;
V_4 -> V_12 [ 0 ] = V_13 ;
V_4 -> V_12 [ 1 ] = V_2 ;
V_4 -> V_7 = 2 ;
V_4 -> V_8 . V_14 = 0xFF ;
V_4 -> V_8 . V_15 = 0 ;
V_4 -> V_8 . V_16 = 0 ;
V_4 -> V_8 . V_17 = 0 ;
}
static void F_2 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_5 . V_7 += V_4 -> V_7 ;
}
static void F_3 ( void * V_1 , int V_18 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_7 += V_18 ;
}
static bool F_4 ( void * V_1 )
{
struct V_19 * V_4 = V_1 ;
if ( V_4 -> V_5 . type != 0x83 )
return false ;
if ( V_4 -> V_12 [ V_4 -> V_5 . V_7 - 2 ] == 0x63 )
return false ;
return true ;
}
static int F_5 ( void * V_4 )
{
struct V_19 * V_20 = V_4 ;
return sizeof( struct V_19 ) + V_20 -> V_5 . V_7 ;
}
static T_1 F_6 ( void * V_4 )
{
struct V_19 * V_20 = V_4 ;
return F_7 ( V_20 ) ;
}
static inline T_1 F_8 ( T_1 V_21 )
{
return ~ V_21 + 1 ;
}
static T_1 F_9 ( T_1 * V_12 , int V_7 )
{
T_1 V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_7 ; V_23 ++ )
V_22 += V_12 [ V_23 ] ;
return F_8 ( V_22 ) ;
}
static void F_10 ( void * V_1 , T_1 V_2 )
{
struct V_24 * V_4 = V_1 ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = F_11 ( V_27 ) ;
F_12 ( V_4 ) = V_13 ;
F_7 ( V_4 ) = V_2 ;
V_4 -> V_7 = 2 ;
}
static void F_13 ( void * V_1 )
{
struct V_24 * V_4 = V_1 ;
V_4 -> V_28 = F_8 ( V_4 -> V_7 ) ;
F_14 ( V_4 ) =
F_9 ( V_4 -> V_12 , V_4 -> V_7 ) ;
F_15 ( V_4 ) = 0 ;
}
static void F_16 ( void * V_1 , int V_18 )
{
struct V_24 * V_4 = V_1 ;
V_4 -> V_7 += V_18 ;
}
static bool F_17 ( void * V_1 )
{
T_1 V_29 ;
struct V_24 * V_4 = V_1 ;
if ( V_4 -> V_26 != F_11 ( V_27 ) )
return false ;
V_29 = F_8 ( V_4 -> V_7 ) ;
if ( V_29 != V_4 -> V_28 )
return false ;
V_29 = F_9 ( V_4 -> V_12 , V_4 -> V_7 ) ;
if ( V_29 != F_14 ( V_4 ) )
return false ;
return true ;
}
static bool F_18 ( struct V_24 * V_4 )
{
if ( V_4 -> V_26 != F_11 ( V_27 ) )
return false ;
if ( V_4 -> V_7 != 0 || V_4 -> V_28 != 0xFF )
return false ;
return true ;
}
static inline int F_19 ( void * V_4 )
{
struct V_24 * V_20 = V_4 ;
return sizeof( struct V_24 ) + V_20 -> V_7 +
V_30 ;
}
static T_1 F_20 ( void * V_4 )
{
struct V_24 * V_20 = V_4 ;
return F_7 ( V_20 ) ;
}
static bool F_21 ( struct V_31 * V_32 , void * V_4 )
{
return ( V_32 -> V_33 -> V_34 ( V_4 ) ==
F_22 ( V_32 -> V_35 -> V_36 ) ) ;
}
static void F_23 ( struct V_37 * V_37 )
{
struct V_31 * V_32 = V_37 -> V_38 ;
struct V_39 * V_35 = V_32 -> V_35 ;
T_1 * V_40 ;
V_35 -> V_41 = V_37 -> V_41 ;
switch ( V_37 -> V_41 ) {
case 0 :
break;
case - V_42 :
case - V_43 :
F_24 ( & V_32 -> V_44 -> V_32 ,
L_1 ,
V_37 -> V_41 ) ;
goto V_45;
case - V_46 :
default:
F_25 ( & V_32 -> V_44 -> V_32 ,
L_2 , V_37 -> V_41 ) ;
goto V_45;
}
V_40 = V_32 -> V_47 -> V_48 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_3 ) ;
F_26 ( L_4 , V_49 , 16 , 1 , V_40 ,
V_32 -> V_33 -> V_50 ( V_40 ) , false ) ;
if ( ! V_32 -> V_33 -> V_51 ( V_40 ) ) {
F_25 ( & V_32 -> V_44 -> V_32 , L_5 ) ;
V_35 -> V_41 = - V_52 ;
goto V_45;
}
if ( ! F_21 ( V_32 , V_40 ) ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_6 ) ;
V_35 -> V_41 = - V_52 ;
goto V_45;
}
V_45:
F_27 ( V_32 -> V_53 , & V_32 -> V_54 ) ;
}
static int F_28 ( struct V_31 * V_32 , T_2 V_55 )
{
V_32 -> V_47 -> V_56 = F_23 ;
return F_29 ( V_32 -> V_47 , V_55 ) ;
}
static void F_30 ( struct V_37 * V_37 )
{
struct V_31 * V_32 = V_37 -> V_38 ;
struct V_39 * V_35 = V_32 -> V_35 ;
struct V_24 * V_40 ;
int V_57 ;
V_35 -> V_41 = V_37 -> V_41 ;
switch ( V_37 -> V_41 ) {
case 0 :
break;
case - V_42 :
case - V_43 :
F_24 ( & V_32 -> V_44 -> V_32 ,
L_7 ,
V_37 -> V_41 ) ;
goto V_45;
case - V_46 :
default:
F_25 ( & V_32 -> V_44 -> V_32 ,
L_2 , V_37 -> V_41 ) ;
goto V_45;
}
V_40 = V_32 -> V_47 -> V_48 ;
if ( ! F_18 ( V_40 ) ) {
F_25 ( & V_32 -> V_44 -> V_32 , L_8 ) ;
V_35 -> V_41 = - V_52 ;
goto V_45;
}
V_57 = F_28 ( V_32 , V_58 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_9 , V_57 ) ;
V_35 -> V_41 = V_57 ;
goto V_45;
}
return;
V_45:
F_27 ( V_32 -> V_53 , & V_32 -> V_54 ) ;
}
static int F_31 ( struct V_31 * V_32 , T_2 V_55 )
{
V_32 -> V_47 -> V_56 = F_30 ;
return F_29 ( V_32 -> V_47 , V_55 ) ;
}
static int F_32 ( struct V_31 * V_32 , T_2 V_55 )
{
T_1 V_59 [ V_60 ] = { 0x00 , 0x00 , 0xff , 0x00 , 0xff , 0x00 } ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_32 -> V_62 -> V_48 = V_59 ;
V_32 -> V_62 -> V_63 = sizeof( V_59 ) ;
V_57 = F_29 ( V_32 -> V_62 , V_55 ) ;
return V_57 ;
}
static int F_33 ( struct V_31 * V_32 ,
struct V_64 * V_65 ,
struct V_64 * V_66 ,
int V_67 )
{
int V_57 ;
V_32 -> V_62 -> V_48 = V_65 -> V_12 ;
V_32 -> V_62 -> V_63 = V_65 -> V_18 ;
V_32 -> V_47 -> V_48 = V_66 -> V_12 ;
V_32 -> V_47 -> V_63 = V_67 ;
F_26 ( L_11 , V_49 , 16 , 1 ,
V_65 -> V_12 , V_65 -> V_18 , false ) ;
V_57 = F_29 ( V_32 -> V_62 , V_68 ) ;
if ( V_57 )
return V_57 ;
if ( V_32 -> V_69 == V_70 ) {
V_57 = F_28 ( V_32 , V_58 ) ;
if ( V_57 )
goto error;
} else if ( V_32 -> V_69 == V_71 ) {
V_57 = F_31 ( V_32 , V_68 ) ;
if ( V_57 )
goto error;
}
return 0 ;
error:
F_34 ( V_32 -> V_62 ) ;
return V_57 ;
}
static void F_35 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_72 )
{
int V_73 = V_72 -> V_18 ;
struct V_74 * V_33 = V_32 -> V_33 ;
F_36 ( V_72 , V_33 -> V_75 ) ;
F_37 ( V_72 , V_33 -> V_76 ) ;
V_33 -> V_77 ( V_72 -> V_12 , V_2 ) ;
V_33 -> V_78 ( V_72 -> V_12 , V_73 ) ;
V_33 -> V_79 ( V_72 -> V_12 ) ;
}
static int F_38 ( struct V_31 * V_32 )
{
struct V_39 * V_35 = V_32 -> V_35 ;
int V_41 = V_35 -> V_41 ;
struct V_64 * V_80 = V_35 -> V_80 ;
struct V_64 * V_81 = V_35 -> V_81 ;
int V_57 ;
F_39 ( V_80 ) ;
if ( V_41 < 0 ) {
V_57 = V_35 -> V_82 ( V_32 , V_35 -> V_83 ,
F_40 ( V_41 ) ) ;
F_39 ( V_81 ) ;
goto V_84;
}
F_37 ( V_81 , V_32 -> V_33 -> V_50 ( V_81 -> V_12 ) ) ;
F_41 ( V_81 , V_32 -> V_33 -> V_85 ) ;
F_42 ( V_81 , V_81 -> V_18 - V_32 -> V_33 -> V_86 ) ;
V_57 = V_35 -> V_82 ( V_32 , V_35 -> V_83 , V_81 ) ;
V_84:
F_43 ( V_35 ) ;
V_32 -> V_35 = NULL ;
return V_57 ;
}
static int F_44 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_80 , struct V_64 * V_81 ,
int V_87 ,
T_3 V_82 ,
void * V_83 )
{
struct V_39 * V_35 ;
int V_57 = 0 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_12 , V_2 ) ;
V_35 = F_45 ( sizeof( * V_35 ) , V_68 ) ;
if ( ! V_35 )
return - V_88 ;
V_35 -> V_36 = V_2 ;
V_35 -> V_80 = V_80 ;
V_35 -> V_81 = V_81 ;
V_35 -> V_87 = V_87 ;
V_35 -> V_82 = V_82 ;
V_35 -> V_83 = V_83 ;
F_35 ( V_32 , V_2 , V_80 ) ;
F_46 ( & V_32 -> V_89 ) ;
if ( ! V_32 -> V_90 ) {
V_57 = F_33 ( V_32 , V_80 , V_81 , V_87 ) ;
if ( V_57 )
goto error;
V_32 -> V_90 = 1 ;
V_32 -> V_35 = V_35 ;
goto V_91;
}
F_24 ( & V_32 -> V_44 -> V_32 , L_13 , V_61 ,
V_2 ) ;
F_47 ( & V_35 -> V_92 ) ;
F_48 ( & V_35 -> V_92 , & V_32 -> V_93 ) ;
goto V_91;
error:
F_43 ( V_35 ) ;
V_91:
F_49 ( & V_32 -> V_89 ) ;
return V_57 ;
}
static int F_50 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_80 ,
T_3 V_82 ,
void * V_83 )
{
struct V_64 * V_81 ;
int V_57 ;
int V_87 = V_32 -> V_33 -> V_85 +
V_32 -> V_33 -> V_94 +
V_32 -> V_33 -> V_86 ;
V_81 = F_51 ( V_87 , V_68 ) ;
if ( ! V_81 )
return - V_88 ;
V_57 = F_44 ( V_32 , V_2 , V_80 , V_81 , V_87 , V_82 ,
V_83 ) ;
if ( V_57 )
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_52 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_80 ,
T_3 V_82 ,
void * V_83 )
{
struct V_64 * V_81 ;
int V_57 ;
int V_87 = V_32 -> V_33 -> V_85 +
V_32 -> V_33 -> V_94 +
V_32 -> V_33 -> V_86 ;
V_81 = F_53 ( V_87 , V_68 ) ;
if ( ! V_81 )
return - V_88 ;
V_57 = F_44 ( V_32 , V_2 , V_80 , V_81 , V_87 , V_82 ,
V_83 ) ;
if ( V_57 )
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_54 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_80 ,
T_3 V_82 ,
void * V_83 )
{
struct V_64 * V_81 ;
struct V_39 * V_35 ;
int V_57 ;
int V_87 = V_32 -> V_33 -> V_85 +
V_32 -> V_33 -> V_94 +
V_32 -> V_33 -> V_86 ;
V_81 = F_53 ( V_87 , V_68 ) ;
if ( ! V_81 )
return - V_88 ;
V_35 = F_45 ( sizeof( * V_35 ) , V_68 ) ;
if ( ! V_35 ) {
F_39 ( V_81 ) ;
return - V_88 ;
}
V_35 -> V_36 = V_2 ;
V_35 -> V_80 = V_80 ;
V_35 -> V_81 = V_81 ;
V_35 -> V_87 = V_87 ;
V_35 -> V_82 = V_82 ;
V_35 -> V_83 = V_83 ;
F_35 ( V_32 , V_2 , V_80 ) ;
V_57 = F_33 ( V_32 , V_80 , V_81 , V_87 ) ;
if ( V_57 < 0 ) {
F_39 ( V_81 ) ;
F_43 ( V_35 ) ;
} else {
V_32 -> V_35 = V_35 ;
}
return V_57 ;
}
static void F_55 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_54 ) ;
int V_57 ;
V_57 = F_38 ( V_32 ) ;
if ( V_57 != - V_97 )
F_27 ( V_32 -> V_53 , & V_32 -> V_98 ) ;
}
static void F_57 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_98 ) ;
struct V_39 * V_35 ;
int V_57 ;
F_46 ( & V_32 -> V_89 ) ;
if ( F_58 ( & V_32 -> V_93 ) ) {
V_32 -> V_90 = 0 ;
F_49 ( & V_32 -> V_89 ) ;
return;
}
V_35 = F_59 ( & V_32 -> V_93 , struct V_39 , V_92 ) ;
F_60 ( & V_35 -> V_92 ) ;
F_49 ( & V_32 -> V_89 ) ;
V_57 = F_33 ( V_32 , V_35 -> V_80 , V_35 -> V_81 , V_35 -> V_87 ) ;
if ( V_57 < 0 ) {
F_39 ( V_35 -> V_80 ) ;
F_39 ( V_35 -> V_81 ) ;
F_43 ( V_35 ) ;
return;
}
V_32 -> V_35 = V_35 ;
}
static int F_61 ( struct V_31 * V_32 , void * V_99 ,
struct V_64 * V_81 )
{
struct V_100 * V_101 = V_99 ;
V_101 -> V_81 = V_81 ;
V_56 ( & V_101 -> V_84 ) ;
return 0 ;
}
static struct V_64 * F_62 ( struct V_31 * V_32 , T_1 V_2 ,
struct V_64 * V_80 )
{
int V_57 ;
struct V_100 V_101 ;
F_63 ( & V_101 . V_84 ) ;
V_57 = F_52 ( V_32 , V_2 , V_80 ,
F_61 , & V_101 ) ;
if ( V_57 ) {
F_39 ( V_80 ) ;
return F_40 ( V_57 ) ;
}
F_64 ( & V_101 . V_84 ) ;
return V_101 . V_81 ;
}
static void F_65 ( struct V_37 * V_37 )
{
struct V_31 * V_32 = V_37 -> V_38 ;
switch ( V_37 -> V_41 ) {
case 0 :
break;
case - V_42 :
case - V_43 :
F_24 ( & V_32 -> V_44 -> V_32 ,
L_7 ,
V_37 -> V_41 ) ;
break;
case - V_46 :
default:
F_25 ( & V_32 -> V_44 -> V_32 ,
L_2 , V_37 -> V_41 ) ;
}
}
static void F_66 ( struct V_31 * V_32 , T_2 V_55 )
{
if ( V_32 -> V_102 == V_103 )
return;
F_32 ( V_32 , V_55 ) ;
F_67 ( V_32 -> V_47 ) ;
}
static struct V_64 * F_68 ( struct V_31 * V_32 , unsigned int V_104 )
{
struct V_64 * V_72 ;
V_72 = F_53 ( V_32 -> V_33 -> V_75 +
V_104 +
V_32 -> V_33 -> V_76 , V_68 ) ;
if ( V_72 )
F_69 ( V_72 , V_32 -> V_33 -> V_75 ) ;
return V_72 ;
}
static bool F_70 ( struct V_105 * V_106 ,
int V_107 )
{
T_1 V_108 ;
T_1 V_109 ;
if ( V_107 < sizeof( struct V_105 ) )
return false ;
V_108 = F_71 ( V_106 -> V_110 ) ;
V_109 = F_72 ( V_106 -> V_110 ) ;
if ( ( V_108 == V_111 &&
V_109 != V_112 ) ||
( V_108 != V_111 &&
V_109 == V_112 ) )
return false ;
if ( F_73 ( V_106 -> V_113 ) != 0 )
return false ;
return true ;
}
static int F_74 ( struct V_114 * V_115 , T_1 * V_116 ,
int V_117 )
{
struct V_105 * V_118 ;
V_118 = (struct V_105 * ) V_116 ;
if ( ! F_70 ( V_118 , V_117 ) )
return - V_119 ;
switch ( F_75 ( V_118 -> V_113 ) ) {
case V_120 :
V_115 -> V_121 = V_122 ;
break;
case V_123 :
V_115 -> V_121 = V_124 ;
break;
case V_125 :
V_115 -> V_121 = V_126 ;
break;
case V_127 :
V_115 -> V_121 = V_124 |
V_126 ;
break;
}
V_115 -> V_110 = F_76 ( V_118 -> V_110 ) ;
V_115 -> V_113 = V_118 -> V_113 ;
V_115 -> V_128 = V_118 -> V_129 ;
memcpy ( V_115 -> V_130 , V_118 -> V_131 , V_115 -> V_128 ) ;
return 0 ;
}
static bool F_77 ( struct V_132 * V_133 ,
int V_107 )
{
if ( V_107 < sizeof( struct V_132 ) )
return false ;
if ( V_133 -> V_134 != V_135 )
return false ;
return true ;
}
static int F_78 ( struct V_114 * V_115 , T_1 * V_116 ,
int V_117 )
{
struct V_132 * V_136 ;
V_136 = (struct V_132 * ) V_116 ;
if ( ! F_77 ( V_136 , V_117 ) )
return - V_119 ;
if ( ( V_136 -> V_137 [ 0 ] == V_138 ) &&
( V_136 -> V_137 [ 1 ] == V_139 ) )
V_115 -> V_121 = V_126 ;
else
V_115 -> V_121 = V_140 ;
memcpy ( V_115 -> V_141 , & V_136 -> V_134 , 9 ) ;
V_115 -> V_142 = 9 ;
memcpy ( V_115 -> V_137 , V_136 -> V_137 , V_143 ) ;
V_115 -> V_144 = V_143 ;
return 0 ;
}
static bool F_79 ( struct V_145 * V_146 ,
int V_107 )
{
T_1 V_108 ;
T_1 V_109 ;
if ( V_107 < sizeof( struct V_145 ) )
return false ;
V_108 = F_71 ( V_146 -> V_110 ) ;
V_109 = F_72 ( V_146 -> V_110 ) ;
if ( ( V_108 == V_111 &&
V_109 != V_112 ) ||
( V_108 != V_111 &&
V_109 == V_112 ) )
return false ;
return true ;
}
static int F_80 ( struct V_114 * V_115 , T_1 * V_116 ,
int V_117 )
{
struct V_145 * V_147 ;
V_147 = (struct V_145 * ) V_116 ;
if ( ! F_79 ( V_147 , V_117 ) )
return - V_119 ;
V_115 -> V_121 = V_148 ;
V_115 -> V_110 = F_76 ( V_147 -> V_110 ) ;
V_115 -> V_128 = 4 ;
memcpy ( V_115 -> V_130 , V_147 -> V_149 , V_115 -> V_128 ) ;
return 0 ;
}
static bool F_81 ( struct V_150 * V_151 ,
int V_107 )
{
if ( V_107 < sizeof( struct V_150 ) )
return false ;
if ( V_151 -> V_152 . V_134 != V_153 )
return false ;
if ( F_82 ( V_151 -> V_152 . V_154 . V_155 ) &
V_156 )
return false ;
return true ;
}
static int F_83 ( struct V_114 * V_115 , T_1 * V_116 ,
int V_117 )
{
struct V_150 * V_157 ;
V_157 = (struct V_150 * ) V_116 ;
if ( ! F_81 ( V_157 , V_117 ) )
return - V_119 ;
V_115 -> V_121 = V_158 ;
return 0 ;
}
static int F_84 ( struct V_31 * V_32 , T_1 V_159 , T_1 * V_160 ,
int V_161 )
{
struct V_114 V_115 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_14 , V_61 ,
V_32 -> V_162 ) ;
if ( V_159 != 1 )
return - V_119 ;
memset ( & V_115 , 0 , sizeof( struct V_114 ) ) ;
switch ( V_32 -> V_162 ) {
case V_163 :
V_57 = F_74 ( & V_115 , V_160 , V_161 ) ;
break;
case V_164 :
case V_165 :
V_57 = F_78 ( & V_115 , V_160 , V_161 ) ;
break;
case V_166 :
V_57 = F_80 ( & V_115 , V_160 , V_161 ) ;
break;
case V_167 :
V_57 = F_83 ( & V_115 , V_160 , V_161 ) ;
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 ,
L_15 ) ;
return - V_119 ;
}
if ( V_57 )
return V_57 ;
if ( ! ( V_115 . V_121 & V_32 -> V_168 ) ) {
F_24 ( & V_32 -> V_44 -> V_32 ,
L_16 ) ;
return - V_169 ;
}
F_24 ( & V_32 -> V_44 -> V_32 ,
L_17 ,
V_115 . V_121 ) ;
V_32 -> V_170 = V_115 . V_121 ;
F_85 ( V_32 -> V_171 , & V_115 , 1 ) ;
return 0 ;
}
static inline void F_86 ( struct V_31 * V_32 )
{
V_32 -> V_162 = ( V_32 -> V_162 + 1 ) % V_32 -> V_172 ;
}
static void F_87 ( struct V_31 * V_32 )
{
V_32 -> V_172 = 0 ;
}
static void F_88 ( struct V_31 * V_32 , T_1 V_173 )
{
V_32 -> V_174 [ V_32 -> V_172 ] =
(struct V_175 * ) & V_176 [ V_173 ] ;
V_32 -> V_172 ++ ;
}
static void F_89 ( struct V_31 * V_32 ,
T_4 V_177 , T_4 V_178 )
{
F_87 ( V_32 ) ;
if ( ( V_177 & V_122 ) ||
( V_177 & V_124 ) ||
( V_177 & V_126 ) )
F_88 ( V_32 , V_163 ) ;
if ( V_177 & V_140 ||
V_177 & V_126 ) {
F_88 ( V_32 , V_164 ) ;
F_88 ( V_32 , V_165 ) ;
}
if ( V_177 & V_148 )
F_88 ( V_32 , V_166 ) ;
if ( V_177 & V_158 )
F_88 ( V_32 , V_167 ) ;
if ( V_178 )
F_88 ( V_32 , V_179 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_64 * V_81 )
{
T_1 V_180 , V_159 , * V_160 ;
int V_57 , V_161 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_180 = V_81 -> V_12 [ 0 ] ;
V_159 = V_81 -> V_12 [ 1 ] ;
V_160 = & V_81 -> V_12 [ 2 ] ;
V_161 = V_81 -> V_18 - 2 ;
if ( V_180 ) {
V_57 = F_84 ( V_32 , V_159 , V_160 , V_161 ) ;
if ( V_57 == 0 ) {
F_87 ( V_32 ) ;
return 0 ;
}
}
return - V_169 ;
}
static struct V_64 * F_91 ( struct V_31 * V_32 )
{
struct V_64 * V_72 ;
T_1 * V_133 , * V_181 , * V_182 ;
T_1 * V_183 = V_32 -> V_182 ;
T_5 V_184 = V_32 -> V_185 ;
T_1 V_186 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_187 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_188 = 36 +
V_184 +
1 ;
V_72 = F_68 ( V_32 , V_188 ) ;
if ( ! V_72 )
return NULL ;
* F_37 ( V_72 , 1 ) = V_189 ;
memcpy ( F_37 ( V_72 , 6 ) , V_187 , 6 ) ;
V_133 = F_37 ( V_72 , 18 ) ;
memcpy ( V_133 , V_186 , 18 ) ;
F_92 ( V_133 + 2 , 6 ) ;
V_181 = F_37 ( V_72 , 10 ) ;
memset ( V_181 , 0 , 10 ) ;
memcpy ( V_181 , V_133 , 8 ) ;
* F_37 ( V_72 , 1 ) = V_184 ;
V_182 = F_37 ( V_72 , V_184 ) ;
memcpy ( V_182 , V_183 , V_184 ) ;
* F_37 ( V_72 , 1 ) = 0 ;
return V_72 ;
}
static int F_93 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
T_1 V_41 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_41 = V_81 -> V_12 [ 0 ] ;
F_41 ( V_81 , sizeof( V_41 ) ) ;
if ( V_41 != 0 ) {
F_96 ( V_32 -> V_171 ) ;
V_32 -> V_190 = 0 ;
F_39 ( V_81 ) ;
return 0 ;
}
return F_97 ( V_32 -> V_171 , V_81 ) ;
}
static void F_98 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_191 ) ;
struct V_64 * V_72 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , 0 ) ;
if ( ! V_72 )
return;
V_57 = F_50 ( V_32 , V_192 , V_72 ,
F_93 , NULL ) ;
if ( V_57 < 0 )
F_39 ( V_72 ) ;
return;
}
static int F_99 ( struct V_31 * V_32 , struct V_64 * V_81 )
{
T_1 V_193 , * V_35 , V_194 = V_195 , * V_182 ;
T_5 V_185 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_81 -> V_18 < V_196 + 1 )
return - V_197 ;
V_193 = V_81 -> V_12 [ 0 ] ;
V_35 = & V_81 -> V_12 [ 1 ] ;
F_24 ( & V_32 -> V_44 -> V_32 , L_18 ,
V_193 , V_81 -> V_18 ) ;
if ( ( V_193 & V_198 ) ==
V_199 )
V_194 = V_200 ;
if ( ( V_193 & V_201 ) == 0 )
return - V_202 ;
V_182 = V_35 + V_196 ;
V_185 = V_81 -> V_18 - ( V_196 + 1 ) ;
V_57 = F_100 ( V_32 -> V_171 , V_126 ,
V_194 , V_182 , V_185 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_19 ) ;
return V_57 ;
}
V_32 -> V_190 = 1 ;
F_27 ( V_32 -> V_53 , & V_32 -> V_191 ) ;
return 0 ;
}
static void F_101 ( unsigned long V_12 )
{
struct V_31 * V_32 = (struct V_31 * ) V_12 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_20 ) ;
V_32 -> V_203 = 1 ;
F_86 ( V_32 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_204 ) ;
}
static int F_102 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
struct V_175 * V_205 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) ) {
V_57 = F_95 ( V_81 ) ;
F_25 ( & V_32 -> V_44 -> V_32 , L_21 ,
V_61 , V_57 ) ;
if ( V_57 == - V_43 ) {
if ( V_32 -> V_172 != 0 )
return V_57 ;
else
goto V_206;
} else if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_22 , V_57 ) ;
goto V_206;
}
}
V_205 = V_32 -> V_174 [ V_32 -> V_162 ] ;
if ( V_205 -> V_18 == 0 ) {
F_103 ( & V_32 -> V_207 ) ;
V_57 = F_99 ( V_32 , V_81 ) ;
goto V_84;
}
V_57 = F_90 ( V_32 , V_81 ) ;
if ( ! V_57 )
goto V_84;
if ( ! V_32 -> V_172 ) {
F_24 ( & V_32 -> V_44 -> V_32 , L_23 ) ;
goto V_84;
}
F_86 ( V_32 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_204 ) ;
V_84:
F_39 ( V_81 ) ;
return V_57 ;
V_206:
F_25 ( & V_32 -> V_44 -> V_32 , L_24 ) ;
F_87 ( V_32 ) ;
V_32 -> V_168 = 0 ;
return V_57 ;
}
static struct V_64 * F_104 ( struct V_31 * V_32 ,
struct V_175 * V_208 )
{
struct V_64 * V_72 ;
V_72 = F_68 ( V_32 , V_208 -> V_18 ) ;
if ( ! V_72 )
return NULL ;
memcpy ( F_37 ( V_72 , V_208 -> V_18 ) , & V_208 -> V_12 , V_208 -> V_18 ) ;
return V_72 ;
}
static int F_105 ( struct V_31 * V_32 )
{
struct V_175 * V_208 ;
struct V_64 * V_72 ;
int V_57 ;
T_1 V_2 ;
V_208 = V_32 -> V_174 [ V_32 -> V_162 ] ;
F_24 ( & V_32 -> V_44 -> V_32 , L_25 ,
V_61 , V_208 -> V_18 ) ;
if ( V_208 -> V_18 == 0 ) {
V_2 = V_209 ;
V_72 = F_91 ( V_32 ) ;
} else {
V_2 = V_210 ;
V_72 = F_104 ( V_32 , V_208 ) ;
}
if ( ! V_72 ) {
F_25 ( & V_32 -> V_44 -> V_32 , L_26 ) ;
return - V_88 ;
}
V_57 = F_52 ( V_32 , V_2 , V_72 , F_102 ,
NULL ) ;
if ( V_57 < 0 ) {
F_39 ( V_72 ) ;
F_25 ( & V_32 -> V_44 -> V_32 , L_27 , V_57 ) ;
}
return V_57 ;
}
static void F_106 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_204 ) ;
struct V_175 * V_205 ;
int V_57 ;
V_205 = V_32 -> V_174 [ V_32 -> V_162 ] ;
F_24 ( & V_32 -> V_44 -> V_32 ,
L_28 ,
V_61 , V_32 -> V_203 , V_205 -> V_18 ) ;
if ( V_32 -> V_203 == 1 ) {
V_32 -> V_203 = 0 ;
F_66 ( V_32 , V_58 ) ;
}
V_57 = F_105 ( V_32 ) ;
if ( V_57 )
return;
if ( V_205 -> V_18 == 0 && V_32 -> V_172 > 1 )
F_107 ( & V_32 -> V_207 , V_211 + V_212 * V_213 ) ;
return;
}
static int F_108 ( struct V_171 * V_171 ,
T_4 V_177 , T_4 V_178 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
F_24 ( & V_32 -> V_44 -> V_32 ,
L_29 ,
V_61 , V_177 , V_178 ) ;
if ( V_32 -> V_214 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_30 ) ;
return - V_215 ;
}
if ( V_32 -> V_190 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_31 ) ;
return - V_215 ;
}
if ( V_178 ) {
V_32 -> V_182 = F_110 ( V_171 , & V_32 -> V_185 ) ;
if ( V_32 -> V_182 == NULL )
V_178 = 0 ;
}
V_32 -> V_162 = 0 ;
F_89 ( V_32 , V_177 , V_178 ) ;
V_32 -> V_168 = V_177 ;
V_32 -> V_216 = V_178 ;
return F_105 ( V_32 ) ;
}
static void F_111 ( struct V_171 * V_171 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_103 ( & V_32 -> V_207 ) ;
if ( ! V_32 -> V_172 ) {
F_24 ( & V_32 -> V_44 -> V_32 ,
L_32 ) ;
return;
}
F_66 ( V_32 , V_68 ) ;
F_87 ( V_32 ) ;
}
static int F_112 ( struct V_31 * V_32 )
{
struct V_217 * V_218 ;
T_6 V_219 ;
int V_57 ;
struct V_64 * V_72 ;
struct V_64 * V_81 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , sizeof( T_1 ) * 2 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , sizeof( T_1 ) ) = 1 ;
* F_37 ( V_72 , sizeof( T_1 ) ) = 0 ;
V_81 = F_62 ( V_32 , V_220 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_218 = (struct V_217 * ) V_81 -> V_12 ;
V_57 = V_218 -> V_41 & V_221 ;
if ( V_57 != V_222 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_33 , V_57 ) ;
F_39 ( V_81 ) ;
return - V_52 ;
}
V_219 = V_81 -> V_18 - 16 ;
V_57 = F_113 ( V_32 -> V_171 , V_218 -> V_223 , V_219 ) ;
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_114 ( struct V_171 * V_171 ,
struct V_114 * V_224 , T_4 V_225 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_34 , V_61 ,
V_225 ) ;
if ( V_32 -> V_172 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_35 ) ;
return - V_215 ;
}
if ( V_32 -> V_214 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_36 ) ;
return - V_215 ;
}
if ( ! V_32 -> V_170 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_37 ) ;
return - V_197 ;
}
if ( ! ( V_32 -> V_170 & ( 1 << V_225 ) ) ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_38 ,
V_225 ) ;
return - V_197 ;
}
if ( V_225 == V_226 ) {
V_57 = F_112 ( V_32 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_39 , V_57 ) ;
return V_57 ;
}
}
V_32 -> V_214 = V_225 ;
V_32 -> V_170 = 0 ;
return 0 ;
}
static void F_115 ( struct V_171 * V_171 ,
struct V_114 * V_224 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
struct V_64 * V_72 ;
struct V_64 * V_81 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( ! V_32 -> V_214 ) {
F_25 ( & V_32 -> V_44 -> V_32 , L_40 ) ;
return;
}
V_32 -> V_214 = 0 ;
F_116 ( & V_32 -> V_227 ) ;
V_72 = F_68 ( V_32 , sizeof( T_1 ) ) ;
if ( ! V_72 )
return;
* F_37 ( V_72 , 1 ) = 1 ;
V_81 = F_62 ( V_32 , V_228 , V_72 ) ;
if ( F_94 ( V_81 ) )
return;
V_57 = V_81 -> V_12 [ 0 ] & V_221 ;
if ( V_57 != V_222 )
F_25 ( & V_32 -> V_44 -> V_32 ,
L_41 , V_57 ) ;
F_39 ( V_81 ) ;
return;
}
static int F_117 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
struct V_229 * V_218 ;
T_1 V_230 ;
int V_57 ;
T_1 V_231 = * ( T_1 * ) V_101 ;
F_43 ( V_101 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
if ( V_32 -> V_170 &&
! ( V_32 -> V_170 & ( 1 << V_226 ) ) ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_42 ) ;
V_57 = - V_197 ;
goto error;
}
V_218 = (struct V_229 * ) V_81 -> V_12 ;
V_57 = V_218 -> V_41 & V_221 ;
if ( V_57 != V_222 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_43 , V_57 ) ;
goto error;
}
if ( ! V_32 -> V_170 ) {
struct V_114 V_114 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_44 ) ;
V_114 . V_121 = V_126 ;
V_114 . V_128 = 10 ;
memcpy ( V_114 . V_130 , V_218 -> V_232 , V_114 . V_128 ) ;
V_57 = F_85 ( V_32 -> V_171 , & V_114 , 1 ) ;
if ( V_57 )
goto error;
V_32 -> V_170 = 0 ;
}
V_32 -> V_214 = V_226 ;
V_230 = V_81 -> V_18 - 17 ;
V_57 = F_113 ( V_32 -> V_171 ,
V_218 -> V_223 , V_230 ) ;
if ( V_57 == 0 )
V_57 = F_118 ( V_32 -> V_171 ,
V_32 -> V_171 -> V_233 [ 0 ] . V_234 ,
! V_231 , V_235 ) ;
error:
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_119 ( struct V_31 * V_32 )
{
switch ( V_32 -> V_162 ) {
case V_163 :
return 0 ;
case V_164 :
return 1 ;
case V_165 :
return 2 ;
default:
return - V_197 ;
}
}
static int F_120 ( struct V_171 * V_171 , struct V_114 * V_224 ,
T_1 V_194 , T_1 * V_182 , T_5 V_185 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
struct V_64 * V_72 ;
int V_57 , V_236 , V_188 ;
T_1 * V_237 , * V_101 ;
T_1 V_238 [ V_239 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_32 -> V_172 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_45 ) ;
return - V_215 ;
}
if ( V_32 -> V_214 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_36 ) ;
return - V_215 ;
}
V_236 = F_119 ( V_32 ) ;
if ( V_236 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_46 , V_32 -> V_162 ) ;
return V_236 ;
}
V_188 = 3 + V_185 ;
if ( V_194 == V_195 )
V_188 += V_239 ;
if ( V_224 && V_224 -> V_144 )
V_188 += V_240 ;
V_72 = F_68 ( V_32 , V_188 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , 1 ) = ! V_194 ;
* F_37 ( V_72 , 1 ) = V_236 ;
V_237 = F_37 ( V_72 , 1 ) ;
* V_237 = 0 ;
if ( V_194 == V_195 && V_236 > 0 ) {
memcpy ( F_37 ( V_72 , V_239 ) , V_238 ,
V_239 ) ;
* V_237 |= 1 ;
}
if ( V_224 && V_224 -> V_144 ) {
memcpy ( F_37 ( V_72 , V_240 ) , V_224 -> V_137 ,
V_224 -> V_144 ) ;
* V_237 |= 2 ;
}
if ( V_182 != NULL && V_185 > 0 ) {
memcpy ( F_37 ( V_72 , V_185 ) , V_182 , V_185 ) ;
* V_237 |= 4 ;
} else {
* V_237 = 0 ;
}
V_101 = F_121 ( sizeof( * V_101 ) , V_68 ) ;
if ( ! V_101 ) {
F_39 ( V_72 ) ;
return - V_88 ;
}
* V_101 = ! V_194 ;
V_57 = F_52 ( V_32 , V_241 , V_72 ,
F_117 , V_101 ) ;
if ( V_57 < 0 ) {
F_39 ( V_72 ) ;
F_43 ( V_101 ) ;
}
return V_57 ;
}
static int F_122 ( struct V_171 * V_171 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_87 ( V_32 ) ;
if ( V_32 -> V_190 || V_32 -> V_214 )
F_66 ( V_32 , V_68 ) ;
V_32 -> V_214 = 0 ;
V_32 -> V_190 = 0 ;
F_116 ( & V_32 -> V_227 ) ;
return 0 ;
}
static struct V_64 * F_123 ( struct V_31 * V_32 )
{
struct V_64 * V_72 , * V_242 , * V_243 ;
unsigned int V_188 = 0 , V_244 = 0 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_124 ( & V_32 -> V_227 ) )
return NULL ;
if ( F_125 ( & V_32 -> V_227 ) == 1 ) {
V_72 = F_126 ( & V_32 -> V_227 ) ;
goto V_65;
}
F_127 (&dev->resp_q, tmp, t)
V_188 += V_242 -> V_18 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_47 ,
V_61 , V_188 ) ;
V_72 = F_53 ( V_188 , V_68 ) ;
if ( V_72 == NULL )
goto V_65;
F_37 ( V_72 , V_188 ) ;
F_127 (&dev->resp_q, tmp, t) {
memcpy ( V_72 -> V_12 + V_244 , V_242 -> V_12 , V_242 -> V_18 ) ;
V_244 += V_242 -> V_18 ;
}
V_65:
F_116 ( & V_32 -> V_227 ) ;
return V_72 ;
}
static int F_128 ( struct V_31 * V_32 , void * V_99 ,
struct V_64 * V_81 )
{
struct V_245 * V_101 = V_99 ;
struct V_64 * V_72 ;
int V_57 = 0 ;
T_1 V_41 , V_246 , V_247 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) ) {
V_57 = F_95 ( V_81 ) ;
goto V_248;
}
V_41 = V_81 -> V_12 [ 0 ] ;
V_246 = V_41 & V_221 ;
V_247 = V_41 & V_249 ;
F_41 ( V_81 , sizeof( V_41 ) ) ;
if ( V_246 != V_222 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_48 , V_246 ) ;
V_57 = - V_52 ;
goto error;
}
F_129 ( & V_32 -> V_227 , V_81 ) ;
if ( V_247 ) {
V_32 -> V_250 = V_101 ;
F_27 ( V_32 -> V_53 , & V_32 -> V_251 ) ;
return - V_97 ;
}
V_72 = F_123 ( V_32 ) ;
if ( ! V_72 )
goto error;
V_101 -> V_252 ( V_101 -> V_253 , V_72 , 0 ) ;
F_43 ( V_101 ) ;
return 0 ;
error:
F_39 ( V_81 ) ;
V_248:
F_116 ( & V_32 -> V_227 ) ;
V_101 -> V_252 ( V_101 -> V_253 , NULL , V_57 ) ;
F_43 ( V_101 ) ;
return V_57 ;
}
static int F_130 ( struct V_171 * V_171 ,
struct V_114 * V_224 , struct V_64 * V_72 ,
T_7 V_252 , void * V_253 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
struct V_245 * V_101 = NULL ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_72 -> V_18 > V_254 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_49 ,
V_254 ) ;
V_57 = - V_255 ;
goto error;
}
if ( ! V_32 -> V_214 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_50 ) ;
V_57 = - V_197 ;
goto error;
}
V_101 = F_121 ( sizeof( * V_101 ) , V_68 ) ;
if ( ! V_101 ) {
V_57 = - V_88 ;
goto error;
}
V_101 -> V_252 = V_252 ;
V_101 -> V_253 = V_253 ;
switch ( V_32 -> V_102 ) {
case V_256 :
if ( V_32 -> V_214 == V_257 ) {
V_57 = F_50 ( V_32 , V_258 ,
V_72 ,
F_128 ,
V_101 ) ;
break;
}
default:
* F_36 ( V_72 , sizeof( T_1 ) ) = 1 ;
V_57 = F_50 ( V_32 , V_259 ,
V_72 , F_128 ,
V_101 ) ;
break;
}
if ( V_57 < 0 )
goto error;
return 0 ;
error:
F_43 ( V_101 ) ;
F_39 ( V_72 ) ;
return V_57 ;
}
static int F_131 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
T_1 V_41 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_41 = V_81 -> V_12 [ 0 ] ;
F_39 ( V_81 ) ;
if ( V_41 != 0 ) {
F_96 ( V_32 -> V_171 ) ;
V_32 -> V_190 = 0 ;
return 0 ;
}
F_27 ( V_32 -> V_53 , & V_32 -> V_191 ) ;
return 0 ;
}
static int F_132 ( struct V_171 * V_171 , struct V_64 * V_72 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_72 -> V_18 > V_254 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_49 ,
V_254 ) ;
return - V_255 ;
}
V_57 = F_50 ( V_32 , V_260 , V_72 ,
F_131 , NULL ) ;
if ( V_57 < 0 )
F_39 ( V_72 ) ;
return V_57 ;
}
static void F_133 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_251 ) ;
struct V_64 * V_72 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , V_261 ) ;
if ( ! V_72 )
goto error;
switch ( V_32 -> V_102 ) {
case V_256 :
if ( V_32 -> V_214 == V_257 ) {
V_57 = F_54 ( V_32 ,
V_258 ,
V_72 ,
F_128 ,
V_32 -> V_250 ) ;
break;
}
default:
* F_37 ( V_72 , sizeof( T_1 ) ) = 1 ;
V_57 = F_54 ( V_32 ,
V_259 ,
V_72 ,
F_128 ,
V_32 -> V_250 ) ;
break;
}
if ( V_57 == 0 )
return;
F_25 ( & V_32 -> V_44 -> V_32 ,
L_51 , V_57 ) ;
F_39 ( V_72 ) ;
F_43 ( V_32 -> V_250 ) ;
error:
F_32 ( V_32 , V_68 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_98 ) ;
}
static int F_134 ( struct V_31 * V_32 , T_1 V_262 , T_1 * V_263 ,
T_1 V_264 )
{
struct V_64 * V_72 ;
struct V_64 * V_81 ;
int V_188 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_188 = sizeof( V_262 ) + V_264 ;
V_72 = F_68 ( V_32 , V_188 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , sizeof( V_262 ) ) = V_262 ;
memcpy ( F_37 ( V_72 , V_264 ) , V_263 , V_264 ) ;
V_81 = F_62 ( V_32 , V_265 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
F_39 ( V_81 ) ;
return 0 ;
}
static int F_135 ( struct V_31 * V_32 ,
struct V_266 * V_267 )
{
struct V_64 * V_72 ;
struct V_64 * V_81 ;
V_72 = F_68 ( V_32 , 0 ) ;
if ( ! V_72 )
return - V_88 ;
V_81 = F_62 ( V_32 , V_268 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_267 -> V_269 = V_81 -> V_12 [ 0 ] ;
V_267 -> V_270 = V_81 -> V_12 [ 1 ] ;
V_267 -> V_271 = V_81 -> V_12 [ 2 ] ;
V_267 -> V_272 = V_81 -> V_12 [ 3 ] ;
F_39 ( V_81 ) ;
return 0 ;
}
static int F_136 ( struct V_31 * V_32 )
{
struct V_64 * V_72 ;
struct V_64 * V_81 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , sizeof( T_1 ) ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , sizeof( T_1 ) ) = 0x1 ;
V_81 = F_62 ( V_32 , 0x18 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
F_39 ( V_81 ) ;
return 0 ;
}
static void F_137 ( struct V_37 * V_37 )
{
struct V_273 * V_101 = V_37 -> V_38 ;
F_24 ( & V_37 -> V_32 -> V_32 , L_10 , V_61 ) ;
F_26 ( L_52 , V_49 , 16 , 1 ,
V_37 -> V_48 , V_37 -> V_63 ,
false ) ;
V_101 -> V_57 = V_37 -> V_41 ;
V_56 ( & V_101 -> V_84 ) ;
}
static int F_138 ( struct V_31 * V_32 )
{
T_1 V_35 [ 10 ] = { V_274 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 } ;
T_1 V_275 [ 255 ] ;
int V_57 ;
void * V_276 ;
struct V_273 V_101 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_63 ( & V_101 . V_84 ) ;
V_276 = V_32 -> V_47 -> V_38 ;
V_32 -> V_47 -> V_48 = V_275 ;
V_32 -> V_47 -> V_63 = 255 ;
V_32 -> V_47 -> V_56 = F_137 ;
V_32 -> V_47 -> V_38 = & V_101 ;
V_32 -> V_62 -> V_48 = V_35 ;
V_32 -> V_62 -> V_63 = sizeof( V_35 ) ;
F_26 ( L_53 , V_49 , 16 , 1 ,
V_35 , sizeof( V_35 ) , false ) ;
V_57 = F_29 ( V_32 -> V_62 , V_68 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_54 , V_57 ) ;
return V_57 ;
}
V_57 = F_29 ( V_32 -> V_47 , V_68 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_55 ,
V_57 ) ;
return V_57 ;
}
F_64 ( & V_101 . V_84 ) ;
V_32 -> V_47 -> V_38 = V_276 ;
return V_101 . V_57 ;
}
static int F_139 ( struct V_171 * V_171 , T_1 V_277 )
{
struct V_31 * V_32 = F_109 ( V_171 ) ;
T_1 V_278 = ! ! V_277 ;
int V_57 ;
V_57 = F_134 ( V_32 , V_279 ,
( T_1 * ) & V_278 , 1 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_56 ) ;
return V_57 ;
}
return V_57 ;
}
int F_140 ( struct V_171 * V_171 )
{
return F_139 ( V_171 , 1 ) ;
}
int F_141 ( struct V_171 * V_171 )
{
return F_139 ( V_171 , 0 ) ;
}
static int F_142 ( struct V_31 * V_32 )
{
struct V_280 V_281 ;
struct V_282 V_283 ;
T_1 V_284 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_57 ;
switch ( V_32 -> V_102 ) {
case V_285 :
V_281 . V_286 = V_287 ;
V_281 . V_288 = 2 ;
V_281 . V_289 =
V_290 ;
V_283 . V_291 = V_292 ;
V_283 . V_293 = V_294 ;
V_283 . V_295 = V_296 ;
break;
case V_256 :
case V_103 :
V_281 . V_286 = 0x2 ;
V_281 . V_288 = 0x1 ;
V_281 . V_289 =
V_290 ;
V_283 . V_291 = V_292 ;
V_283 . V_293 = V_292 ;
V_283 . V_295 = V_294 ;
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 , L_57 ,
V_32 -> V_102 ) ;
return - V_197 ;
}
V_57 = F_134 ( V_32 , V_297 ,
( T_1 * ) & V_281 , sizeof( V_281 ) ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_58 ) ;
return V_57 ;
}
V_57 = F_134 ( V_32 , V_298 ,
( T_1 * ) & V_283 , sizeof( V_283 ) ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_59 ) ;
return V_57 ;
}
switch ( V_32 -> V_102 ) {
case V_285 :
break;
case V_256 :
F_136 ( V_32 ) ;
V_57 = F_134 ( V_32 , V_299 ,
V_284 , 3 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_60 ) ;
return V_57 ;
}
F_136 ( V_32 ) ;
break;
}
return 0 ;
}
static int F_143 ( struct V_300 * V_44 ,
const struct V_301 * V_302 )
{
struct V_266 V_303 ;
struct V_31 * V_32 ;
struct V_304 * V_305 ;
struct V_306 * V_307 ;
int V_308 = 0 ;
int V_309 = 0 ;
int V_57 = - V_88 ;
int V_23 ;
T_4 V_310 ;
V_32 = F_45 ( sizeof( * V_32 ) , V_68 ) ;
if ( ! V_32 )
return - V_88 ;
V_32 -> V_311 = F_144 ( F_145 ( V_44 ) ) ;
V_32 -> V_44 = V_44 ;
F_146 ( & V_32 -> V_89 ) ;
V_305 = V_44 -> V_312 ;
for ( V_23 = 0 ; V_23 < V_305 -> V_313 . V_314 ; ++ V_23 ) {
V_307 = & V_305 -> V_307 [ V_23 ] . V_313 ;
if ( ! V_308 && F_147 ( V_307 ) )
V_308 = V_307 -> V_315 ;
if ( ! V_309 && F_148 ( V_307 ) )
V_309 = V_307 -> V_315 ;
}
if ( ! V_308 || ! V_309 ) {
F_25 ( & V_44 -> V_32 ,
L_61 ) ;
V_57 = - V_316 ;
goto error;
}
V_32 -> V_47 = F_149 ( 0 , V_68 ) ;
V_32 -> V_62 = F_149 ( 0 , V_68 ) ;
if ( ! V_32 -> V_47 || ! V_32 -> V_62 )
goto error;
F_150 ( V_32 -> V_47 , V_32 -> V_311 ,
F_151 ( V_32 -> V_311 , V_308 ) ,
NULL , 0 , NULL , V_32 ) ;
F_150 ( V_32 -> V_62 , V_32 -> V_311 ,
F_152 ( V_32 -> V_311 , V_309 ) ,
NULL , 0 , F_65 , V_32 ) ;
F_153 ( & V_32 -> V_98 , F_57 ) ;
F_153 ( & V_32 -> V_54 , F_55 ) ;
F_153 ( & V_32 -> V_251 , F_133 ) ;
F_153 ( & V_32 -> V_191 , F_98 ) ;
F_153 ( & V_32 -> V_204 , F_106 ) ;
V_32 -> V_53 = F_154 ( L_62 , 0 ) ;
if ( V_32 -> V_53 == NULL )
goto error;
F_155 ( & V_32 -> V_207 ) ;
V_32 -> V_207 . V_12 = ( unsigned long ) V_32 ;
V_32 -> V_207 . V_317 = F_101 ;
F_156 ( & V_32 -> V_227 ) ;
F_47 ( & V_32 -> V_93 ) ;
F_157 ( V_44 , V_32 ) ;
V_32 -> V_33 = & V_318 ;
V_32 -> V_69 = V_71 ;
V_32 -> V_102 = V_302 -> V_319 ;
switch ( V_32 -> V_102 ) {
case V_285 :
V_310 = V_320 ;
break;
case V_256 :
V_310 = V_321 ;
break;
case V_103 :
V_310 = V_321 ;
V_32 -> V_33 = & V_322 ;
V_32 -> V_69 = V_70 ,
V_57 = F_138 ( V_32 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_63 ,
V_57 ) ;
goto V_323;
}
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 , L_57 ,
V_32 -> V_102 ) ;
V_57 = - V_197 ;
goto V_323;
}
memset ( & V_303 , 0 , sizeof( V_303 ) ) ;
V_57 = F_135 ( V_32 , & V_303 ) ;
if ( V_57 < 0 )
goto V_323;
F_158 ( & V_32 -> V_44 -> V_32 ,
L_64 ,
V_303 . V_269 , V_303 . V_270 , V_303 . V_271 ) ;
V_32 -> V_171 = F_159 ( & V_324 , V_310 ,
V_32 -> V_33 -> V_75 +
V_261 ,
V_32 -> V_33 -> V_76 ) ;
if ( ! V_32 -> V_171 ) {
V_57 = - V_88 ;
goto V_323;
}
F_160 ( V_32 -> V_171 , & V_44 -> V_32 ) ;
F_161 ( V_32 -> V_171 , V_32 ) ;
V_57 = F_162 ( V_32 -> V_171 ) ;
if ( V_57 )
goto V_325;
V_57 = F_142 ( V_32 ) ;
if ( V_57 )
goto V_326;
return 0 ;
V_326:
F_163 ( V_32 -> V_171 ) ;
V_325:
F_164 ( V_32 -> V_171 ) ;
V_323:
F_165 ( V_32 -> V_53 ) ;
error:
F_166 ( V_32 -> V_47 ) ;
F_166 ( V_32 -> V_62 ) ;
F_167 ( V_32 -> V_311 ) ;
F_43 ( V_32 ) ;
return V_57 ;
}
static void F_168 ( struct V_300 * V_44 )
{
struct V_31 * V_32 ;
struct V_39 * V_35 , * V_327 ;
V_32 = F_169 ( V_44 ) ;
F_157 ( V_44 , NULL ) ;
F_163 ( V_32 -> V_171 ) ;
F_164 ( V_32 -> V_171 ) ;
F_67 ( V_32 -> V_47 ) ;
F_67 ( V_32 -> V_62 ) ;
F_165 ( V_32 -> V_53 ) ;
F_116 ( & V_32 -> V_227 ) ;
F_103 ( & V_32 -> V_207 ) ;
F_170 (cmd, n, &dev->cmd_queue, queue) {
F_60 ( & V_35 -> V_92 ) ;
F_43 ( V_35 ) ;
}
F_166 ( V_32 -> V_47 ) ;
F_166 ( V_32 -> V_62 ) ;
F_43 ( V_32 ) ;
F_158 ( & V_44 -> V_32 , L_65 ) ;
}
