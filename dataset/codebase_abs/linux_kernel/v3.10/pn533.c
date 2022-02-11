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
return 0 ;
}
static bool F_79 ( struct V_143 * V_144 ,
int V_107 )
{
T_1 V_108 ;
T_1 V_109 ;
if ( V_107 < sizeof( struct V_143 ) )
return false ;
V_108 = F_71 ( V_144 -> V_110 ) ;
V_109 = F_72 ( V_144 -> V_110 ) ;
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
struct V_143 * V_145 ;
V_145 = (struct V_143 * ) V_116 ;
if ( ! F_79 ( V_145 , V_117 ) )
return - V_119 ;
V_115 -> V_121 = V_146 ;
V_115 -> V_110 = F_76 ( V_145 -> V_110 ) ;
V_115 -> V_128 = 4 ;
memcpy ( V_115 -> V_130 , V_145 -> V_147 , V_115 -> V_128 ) ;
return 0 ;
}
static bool F_81 ( struct V_148 * V_149 ,
int V_107 )
{
if ( V_107 < sizeof( struct V_148 ) )
return false ;
if ( V_149 -> V_150 . V_134 != V_151 )
return false ;
if ( F_82 ( V_149 -> V_150 . V_152 . V_153 ) &
V_154 )
return false ;
return true ;
}
static int F_83 ( struct V_114 * V_115 , T_1 * V_116 ,
int V_117 )
{
struct V_148 * V_155 ;
V_155 = (struct V_148 * ) V_116 ;
if ( ! F_81 ( V_155 , V_117 ) )
return - V_119 ;
V_115 -> V_121 = V_156 ;
return 0 ;
}
static int F_84 ( struct V_31 * V_32 , T_1 V_157 , T_1 * V_158 ,
int V_159 )
{
struct V_114 V_115 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_14 , V_61 ,
V_32 -> V_160 ) ;
if ( V_157 != 1 )
return - V_119 ;
memset ( & V_115 , 0 , sizeof( struct V_114 ) ) ;
switch ( V_32 -> V_160 ) {
case V_161 :
V_57 = F_74 ( & V_115 , V_158 , V_159 ) ;
break;
case V_162 :
case V_163 :
V_57 = F_78 ( & V_115 , V_158 , V_159 ) ;
break;
case V_164 :
V_57 = F_80 ( & V_115 , V_158 , V_159 ) ;
break;
case V_165 :
V_57 = F_83 ( & V_115 , V_158 , V_159 ) ;
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 ,
L_15 ) ;
return - V_119 ;
}
if ( V_57 )
return V_57 ;
if ( ! ( V_115 . V_121 & V_32 -> V_166 ) ) {
F_24 ( & V_32 -> V_44 -> V_32 ,
L_16 ) ;
return - V_167 ;
}
F_24 ( & V_32 -> V_44 -> V_32 ,
L_17 ,
V_115 . V_121 ) ;
V_32 -> V_168 = V_115 . V_121 ;
F_85 ( V_32 -> V_169 , & V_115 , 1 ) ;
return 0 ;
}
static inline void F_86 ( struct V_31 * V_32 )
{
V_32 -> V_160 = ( V_32 -> V_160 + 1 ) % V_32 -> V_170 ;
}
static void F_87 ( struct V_31 * V_32 )
{
V_32 -> V_170 = 0 ;
}
static void F_88 ( struct V_31 * V_32 , T_1 V_171 )
{
V_32 -> V_172 [ V_32 -> V_170 ] =
(struct V_173 * ) & V_174 [ V_171 ] ;
V_32 -> V_170 ++ ;
}
static void F_89 ( struct V_31 * V_32 ,
T_4 V_175 , T_4 V_176 )
{
F_87 ( V_32 ) ;
if ( ( V_175 & V_122 ) ||
( V_175 & V_124 ) ||
( V_175 & V_126 ) )
F_88 ( V_32 , V_161 ) ;
if ( V_175 & V_140 ||
V_175 & V_126 ) {
F_88 ( V_32 , V_162 ) ;
F_88 ( V_32 , V_163 ) ;
}
if ( V_175 & V_146 )
F_88 ( V_32 , V_164 ) ;
if ( V_175 & V_156 )
F_88 ( V_32 , V_165 ) ;
if ( V_176 )
F_88 ( V_32 , V_177 ) ;
}
static int F_90 ( struct V_31 * V_32 , struct V_64 * V_81 )
{
T_1 V_178 , V_157 , * V_158 ;
int V_57 , V_159 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_178 = V_81 -> V_12 [ 0 ] ;
V_157 = V_81 -> V_12 [ 1 ] ;
V_158 = & V_81 -> V_12 [ 2 ] ;
V_159 = V_81 -> V_18 - 2 ;
if ( V_178 ) {
V_57 = F_84 ( V_32 , V_157 , V_158 , V_159 ) ;
if ( V_57 == 0 ) {
F_87 ( V_32 ) ;
return 0 ;
}
}
return - V_167 ;
}
static struct V_64 * F_91 ( struct V_31 * V_32 )
{
struct V_64 * V_72 ;
T_1 * V_133 , * V_179 , * V_180 ;
T_1 * V_181 = V_32 -> V_180 ;
T_5 V_182 = V_32 -> V_183 ;
T_1 V_184 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_185 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_186 = 36 +
V_182 +
1 ;
V_72 = F_68 ( V_32 , V_186 ) ;
if ( ! V_72 )
return NULL ;
* F_37 ( V_72 , 1 ) = V_187 ;
memcpy ( F_37 ( V_72 , 6 ) , V_185 , 6 ) ;
V_133 = F_37 ( V_72 , 18 ) ;
memcpy ( V_133 , V_184 , 18 ) ;
F_92 ( V_133 + 2 , 6 ) ;
V_179 = F_37 ( V_72 , 10 ) ;
memset ( V_179 , 0 , 10 ) ;
memcpy ( V_179 , V_133 , 8 ) ;
* F_37 ( V_72 , 1 ) = V_182 ;
V_180 = F_37 ( V_72 , V_182 ) ;
memcpy ( V_180 , V_181 , V_182 ) ;
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
F_96 ( V_32 -> V_169 ) ;
V_32 -> V_188 = 0 ;
F_39 ( V_81 ) ;
return 0 ;
}
return F_97 ( V_32 -> V_169 , V_81 ) ;
}
static void F_98 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_189 ) ;
struct V_64 * V_72 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , 0 ) ;
if ( ! V_72 )
return;
V_57 = F_50 ( V_32 , V_190 , V_72 ,
F_93 , NULL ) ;
if ( V_57 < 0 )
F_39 ( V_72 ) ;
return;
}
static int F_99 ( struct V_31 * V_32 , struct V_64 * V_81 )
{
T_1 V_191 , * V_35 , V_192 = V_193 , * V_180 ;
T_5 V_183 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_81 -> V_18 < V_194 + 1 )
return - V_195 ;
V_191 = V_81 -> V_12 [ 0 ] ;
V_35 = & V_81 -> V_12 [ 1 ] ;
F_24 ( & V_32 -> V_44 -> V_32 , L_18 ,
V_191 , V_81 -> V_18 ) ;
if ( ( V_191 & V_196 ) ==
V_197 )
V_192 = V_198 ;
if ( ( V_191 & V_199 ) == 0 )
return - V_200 ;
V_180 = V_35 + V_194 ;
V_183 = V_81 -> V_18 - ( V_194 + 1 ) ;
V_57 = F_100 ( V_32 -> V_169 , V_126 ,
V_192 , V_180 , V_183 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_19 ) ;
return V_57 ;
}
V_32 -> V_188 = 1 ;
F_27 ( V_32 -> V_53 , & V_32 -> V_189 ) ;
return 0 ;
}
static void F_101 ( unsigned long V_12 )
{
struct V_31 * V_32 = (struct V_31 * ) V_12 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_20 ) ;
V_32 -> V_201 = 1 ;
F_86 ( V_32 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_202 ) ;
}
static int F_102 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
struct V_173 * V_203 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) ) {
V_57 = F_95 ( V_81 ) ;
F_25 ( & V_32 -> V_44 -> V_32 , L_21 ,
V_61 , V_57 ) ;
if ( V_57 == - V_43 ) {
if ( V_32 -> V_170 != 0 )
return V_57 ;
else
goto V_204;
} else if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_22 , V_57 ) ;
goto V_204;
}
}
V_203 = V_32 -> V_172 [ V_32 -> V_160 ] ;
if ( V_203 -> V_18 == 0 ) {
F_103 ( & V_32 -> V_205 ) ;
V_57 = F_99 ( V_32 , V_81 ) ;
goto V_84;
}
V_57 = F_90 ( V_32 , V_81 ) ;
if ( ! V_57 )
goto V_84;
if ( ! V_32 -> V_170 ) {
F_24 ( & V_32 -> V_44 -> V_32 , L_23 ) ;
goto V_84;
}
F_86 ( V_32 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_202 ) ;
V_84:
F_39 ( V_81 ) ;
return V_57 ;
V_204:
F_25 ( & V_32 -> V_44 -> V_32 , L_24 ) ;
F_87 ( V_32 ) ;
V_32 -> V_166 = 0 ;
return V_57 ;
}
static struct V_64 * F_104 ( struct V_31 * V_32 ,
struct V_173 * V_206 )
{
struct V_64 * V_72 ;
V_72 = F_68 ( V_32 , V_206 -> V_18 ) ;
if ( ! V_72 )
return NULL ;
memcpy ( F_37 ( V_72 , V_206 -> V_18 ) , & V_206 -> V_12 , V_206 -> V_18 ) ;
return V_72 ;
}
static int F_105 ( struct V_31 * V_32 )
{
struct V_173 * V_206 ;
struct V_64 * V_72 ;
int V_57 ;
T_1 V_2 ;
V_206 = V_32 -> V_172 [ V_32 -> V_160 ] ;
F_24 ( & V_32 -> V_44 -> V_32 , L_25 ,
V_61 , V_206 -> V_18 ) ;
if ( V_206 -> V_18 == 0 ) {
V_2 = V_207 ;
V_72 = F_91 ( V_32 ) ;
} else {
V_2 = V_208 ;
V_72 = F_104 ( V_32 , V_206 ) ;
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
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_202 ) ;
struct V_173 * V_203 ;
int V_57 ;
V_203 = V_32 -> V_172 [ V_32 -> V_160 ] ;
F_24 ( & V_32 -> V_44 -> V_32 ,
L_28 ,
V_61 , V_32 -> V_201 , V_203 -> V_18 ) ;
if ( V_32 -> V_201 == 1 ) {
V_32 -> V_201 = 0 ;
F_66 ( V_32 , V_58 ) ;
}
V_57 = F_105 ( V_32 ) ;
if ( V_57 )
return;
if ( V_203 -> V_18 == 0 && V_32 -> V_170 > 1 )
F_107 ( & V_32 -> V_205 , V_209 + V_210 * V_211 ) ;
return;
}
static int F_108 ( struct V_169 * V_169 ,
T_4 V_175 , T_4 V_176 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
F_24 ( & V_32 -> V_44 -> V_32 ,
L_29 ,
V_61 , V_175 , V_176 ) ;
if ( V_32 -> V_212 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_30 ) ;
return - V_213 ;
}
if ( V_32 -> V_188 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_31 ) ;
return - V_213 ;
}
if ( V_176 ) {
V_32 -> V_180 = F_110 ( V_169 , & V_32 -> V_183 ) ;
if ( V_32 -> V_180 == NULL )
V_176 = 0 ;
}
V_32 -> V_160 = 0 ;
F_89 ( V_32 , V_175 , V_176 ) ;
V_32 -> V_166 = V_175 ;
V_32 -> V_214 = V_176 ;
return F_105 ( V_32 ) ;
}
static void F_111 ( struct V_169 * V_169 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_103 ( & V_32 -> V_205 ) ;
if ( ! V_32 -> V_170 ) {
F_24 ( & V_32 -> V_44 -> V_32 ,
L_32 ) ;
return;
}
F_66 ( V_32 , V_68 ) ;
F_87 ( V_32 ) ;
}
static int F_112 ( struct V_31 * V_32 )
{
struct V_215 * V_216 ;
T_6 V_217 ;
int V_57 ;
struct V_64 * V_72 ;
struct V_64 * V_81 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , sizeof( T_1 ) * 2 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , sizeof( T_1 ) ) = 1 ;
* F_37 ( V_72 , sizeof( T_1 ) ) = 0 ;
V_81 = F_62 ( V_32 , V_218 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_216 = (struct V_215 * ) V_81 -> V_12 ;
V_57 = V_216 -> V_41 & V_219 ;
if ( V_57 != V_220 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_33 , V_57 ) ;
F_39 ( V_81 ) ;
return - V_52 ;
}
V_217 = V_81 -> V_18 - 16 ;
V_57 = F_113 ( V_32 -> V_169 , V_216 -> V_221 , V_217 ) ;
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_114 ( struct V_169 * V_169 ,
struct V_114 * V_222 , T_4 V_223 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_34 , V_61 ,
V_223 ) ;
if ( V_32 -> V_170 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_35 ) ;
return - V_213 ;
}
if ( V_32 -> V_212 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_36 ) ;
return - V_213 ;
}
if ( ! V_32 -> V_168 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_37 ) ;
return - V_195 ;
}
if ( ! ( V_32 -> V_168 & ( 1 << V_223 ) ) ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_38 ,
V_223 ) ;
return - V_195 ;
}
if ( V_223 == V_224 ) {
V_57 = F_112 ( V_32 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_39 , V_57 ) ;
return V_57 ;
}
}
V_32 -> V_212 = V_223 ;
V_32 -> V_168 = 0 ;
return 0 ;
}
static void F_115 ( struct V_169 * V_169 ,
struct V_114 * V_222 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
struct V_64 * V_72 ;
struct V_64 * V_81 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( ! V_32 -> V_212 ) {
F_25 ( & V_32 -> V_44 -> V_32 , L_40 ) ;
return;
}
V_32 -> V_212 = 0 ;
F_116 ( & V_32 -> V_225 ) ;
V_72 = F_68 ( V_32 , sizeof( T_1 ) ) ;
if ( ! V_72 )
return;
* F_37 ( V_72 , 1 ) = 1 ;
V_81 = F_62 ( V_32 , V_226 , V_72 ) ;
if ( F_94 ( V_81 ) )
return;
V_57 = V_81 -> V_12 [ 0 ] & V_219 ;
if ( V_57 != V_220 )
F_25 ( & V_32 -> V_44 -> V_32 ,
L_41 , V_57 ) ;
F_39 ( V_81 ) ;
return;
}
static int F_117 ( struct V_31 * V_32 , void * V_101 ,
struct V_64 * V_81 )
{
struct V_227 * V_216 ;
T_1 V_228 ;
int V_57 ;
T_1 V_229 = * ( T_1 * ) V_101 ;
F_43 ( V_101 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
if ( V_32 -> V_168 &&
! ( V_32 -> V_168 & ( 1 << V_224 ) ) ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_42 ) ;
V_57 = - V_195 ;
goto error;
}
V_216 = (struct V_227 * ) V_81 -> V_12 ;
V_57 = V_216 -> V_41 & V_219 ;
if ( V_57 != V_220 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_43 , V_57 ) ;
goto error;
}
if ( ! V_32 -> V_168 ) {
struct V_114 V_114 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_44 ) ;
V_114 . V_121 = V_126 ;
V_114 . V_128 = 10 ;
memcpy ( V_114 . V_130 , V_216 -> V_230 , V_114 . V_128 ) ;
V_57 = F_85 ( V_32 -> V_169 , & V_114 , 1 ) ;
if ( V_57 )
goto error;
V_32 -> V_168 = 0 ;
}
V_32 -> V_212 = V_224 ;
V_228 = V_81 -> V_18 - 17 ;
V_57 = F_113 ( V_32 -> V_169 ,
V_216 -> V_221 , V_228 ) ;
if ( V_57 == 0 )
V_57 = F_118 ( V_32 -> V_169 ,
V_32 -> V_169 -> V_231 [ 0 ] . V_232 ,
! V_229 , V_233 ) ;
error:
F_39 ( V_81 ) ;
return V_57 ;
}
static int F_119 ( struct V_31 * V_32 )
{
switch ( V_32 -> V_160 ) {
case V_161 :
return 0 ;
case V_162 :
return 1 ;
case V_163 :
return 2 ;
default:
return - V_195 ;
}
}
static int F_120 ( struct V_169 * V_169 , struct V_114 * V_222 ,
T_1 V_192 , T_1 * V_180 , T_5 V_183 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
struct V_64 * V_72 ;
int V_57 , V_234 , V_186 ;
T_1 * V_235 , * V_101 ;
T_1 V_236 [ V_237 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_32 -> V_170 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_45 ) ;
return - V_213 ;
}
if ( V_32 -> V_212 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_36 ) ;
return - V_213 ;
}
V_234 = F_119 ( V_32 ) ;
if ( V_234 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_46 , V_32 -> V_160 ) ;
return V_234 ;
}
V_186 = 3 + V_183 ;
if ( V_192 == V_193 )
V_186 += V_237 ;
V_72 = F_68 ( V_32 , V_186 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , 1 ) = ! V_192 ;
* F_37 ( V_72 , 1 ) = V_234 ;
V_235 = F_37 ( V_72 , 1 ) ;
* V_235 = 0 ;
if ( V_192 == V_193 && V_234 > 0 ) {
memcpy ( F_37 ( V_72 , V_237 ) , V_236 ,
V_237 ) ;
* V_235 |= 1 ;
}
if ( V_180 != NULL && V_183 > 0 ) {
memcpy ( F_37 ( V_72 , V_183 ) , V_180 , V_183 ) ;
* V_235 |= 4 ;
} else {
* V_235 = 0 ;
}
V_101 = F_121 ( sizeof( * V_101 ) , V_68 ) ;
if ( ! V_101 ) {
F_39 ( V_72 ) ;
return - V_88 ;
}
* V_101 = ! V_192 ;
V_57 = F_52 ( V_32 , V_238 , V_72 ,
F_117 , V_101 ) ;
if ( V_57 < 0 ) {
F_39 ( V_72 ) ;
F_43 ( V_101 ) ;
}
return V_57 ;
}
static int F_122 ( struct V_169 * V_169 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_87 ( V_32 ) ;
if ( V_32 -> V_188 || V_32 -> V_212 )
F_66 ( V_32 , V_68 ) ;
V_32 -> V_212 = 0 ;
V_32 -> V_188 = 0 ;
F_116 ( & V_32 -> V_225 ) ;
return 0 ;
}
static struct V_64 * F_123 ( struct V_31 * V_32 )
{
struct V_64 * V_72 , * V_239 , * V_240 ;
unsigned int V_186 = 0 , V_241 = 0 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_124 ( & V_32 -> V_225 ) )
return NULL ;
if ( F_125 ( & V_32 -> V_225 ) == 1 ) {
V_72 = F_126 ( & V_32 -> V_225 ) ;
goto V_65;
}
F_127 (&dev->resp_q, tmp, t)
V_186 += V_239 -> V_18 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_47 ,
V_61 , V_186 ) ;
V_72 = F_53 ( V_186 , V_68 ) ;
if ( V_72 == NULL )
goto V_65;
F_37 ( V_72 , V_186 ) ;
F_127 (&dev->resp_q, tmp, t) {
memcpy ( V_72 -> V_12 + V_241 , V_239 -> V_12 , V_239 -> V_18 ) ;
V_241 += V_239 -> V_18 ;
}
V_65:
F_116 ( & V_32 -> V_225 ) ;
return V_72 ;
}
static int F_128 ( struct V_31 * V_32 , void * V_99 ,
struct V_64 * V_81 )
{
struct V_242 * V_101 = V_99 ;
struct V_64 * V_72 ;
int V_57 = 0 ;
T_1 V_41 , V_243 , V_244 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( F_94 ( V_81 ) ) {
V_57 = F_95 ( V_81 ) ;
goto V_245;
}
V_41 = V_81 -> V_12 [ 0 ] ;
V_243 = V_41 & V_219 ;
V_244 = V_41 & V_246 ;
F_41 ( V_81 , sizeof( V_41 ) ) ;
if ( V_243 != V_220 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_48 , V_243 ) ;
V_57 = - V_52 ;
goto error;
}
F_129 ( & V_32 -> V_225 , V_81 ) ;
if ( V_244 ) {
V_32 -> V_247 = V_101 ;
F_27 ( V_32 -> V_53 , & V_32 -> V_248 ) ;
return - V_97 ;
}
V_72 = F_123 ( V_32 ) ;
if ( ! V_72 )
goto error;
V_101 -> V_249 ( V_101 -> V_250 , V_72 , 0 ) ;
F_43 ( V_101 ) ;
return 0 ;
error:
F_39 ( V_81 ) ;
V_245:
F_116 ( & V_32 -> V_225 ) ;
V_101 -> V_249 ( V_101 -> V_250 , NULL , V_57 ) ;
F_43 ( V_101 ) ;
return V_57 ;
}
static int F_130 ( struct V_169 * V_169 ,
struct V_114 * V_222 , struct V_64 * V_72 ,
T_7 V_249 , void * V_250 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
struct V_242 * V_101 = NULL ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_72 -> V_18 > V_251 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_49 ,
V_251 ) ;
V_57 = - V_252 ;
goto error;
}
if ( ! V_32 -> V_212 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_50 ) ;
V_57 = - V_195 ;
goto error;
}
V_101 = F_121 ( sizeof( * V_101 ) , V_68 ) ;
if ( ! V_101 ) {
V_57 = - V_88 ;
goto error;
}
V_101 -> V_249 = V_249 ;
V_101 -> V_250 = V_250 ;
switch ( V_32 -> V_102 ) {
case V_253 :
if ( V_32 -> V_212 == V_254 ) {
V_57 = F_50 ( V_32 , V_255 ,
V_72 ,
F_128 ,
V_101 ) ;
break;
}
default:
* F_36 ( V_72 , sizeof( T_1 ) ) = 1 ;
V_57 = F_50 ( V_32 , V_256 ,
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
F_96 ( V_32 -> V_169 ) ;
V_32 -> V_188 = 0 ;
return 0 ;
}
F_27 ( V_32 -> V_53 , & V_32 -> V_189 ) ;
return 0 ;
}
static int F_132 ( struct V_169 * V_169 , struct V_64 * V_72 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
if ( V_72 -> V_18 > V_251 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_49 ,
V_251 ) ;
return - V_252 ;
}
V_57 = F_50 ( V_32 , V_257 , V_72 ,
F_131 , NULL ) ;
if ( V_57 < 0 )
F_39 ( V_72 ) ;
return V_57 ;
}
static void F_133 ( struct V_95 * V_96 )
{
struct V_31 * V_32 = F_56 ( V_96 , struct V_31 , V_248 ) ;
struct V_64 * V_72 ;
int V_57 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_72 = F_68 ( V_32 , V_258 ) ;
if ( ! V_72 )
goto error;
switch ( V_32 -> V_102 ) {
case V_253 :
if ( V_32 -> V_212 == V_254 ) {
V_57 = F_54 ( V_32 ,
V_255 ,
V_72 ,
F_128 ,
V_32 -> V_247 ) ;
break;
}
default:
* F_37 ( V_72 , sizeof( T_1 ) ) = 1 ;
V_57 = F_54 ( V_32 ,
V_256 ,
V_72 ,
F_128 ,
V_32 -> V_247 ) ;
break;
}
if ( V_57 == 0 )
return;
F_25 ( & V_32 -> V_44 -> V_32 ,
L_51 , V_57 ) ;
F_39 ( V_72 ) ;
F_43 ( V_32 -> V_247 ) ;
error:
F_32 ( V_32 , V_68 ) ;
F_27 ( V_32 -> V_53 , & V_32 -> V_98 ) ;
}
static int F_134 ( struct V_31 * V_32 , T_1 V_259 , T_1 * V_260 ,
T_1 V_261 )
{
struct V_64 * V_72 ;
struct V_64 * V_81 ;
int V_186 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
V_186 = sizeof( V_259 ) + V_261 ;
V_72 = F_68 ( V_32 , V_186 ) ;
if ( ! V_72 )
return - V_88 ;
* F_37 ( V_72 , sizeof( V_259 ) ) = V_259 ;
memcpy ( F_37 ( V_72 , V_261 ) , V_260 , V_261 ) ;
V_81 = F_62 ( V_32 , V_262 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
F_39 ( V_81 ) ;
return 0 ;
}
static int F_135 ( struct V_31 * V_32 ,
struct V_263 * V_264 )
{
struct V_64 * V_72 ;
struct V_64 * V_81 ;
V_72 = F_68 ( V_32 , 0 ) ;
if ( ! V_72 )
return - V_88 ;
V_81 = F_62 ( V_32 , V_265 , V_72 ) ;
if ( F_94 ( V_81 ) )
return F_95 ( V_81 ) ;
V_264 -> V_266 = V_81 -> V_12 [ 0 ] ;
V_264 -> V_267 = V_81 -> V_12 [ 1 ] ;
V_264 -> V_268 = V_81 -> V_12 [ 2 ] ;
V_264 -> V_269 = V_81 -> V_12 [ 3 ] ;
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
struct V_270 * V_101 = V_37 -> V_38 ;
F_24 ( & V_37 -> V_32 -> V_32 , L_10 , V_61 ) ;
F_138 ( V_271 , L_52 , V_49 , 16 , 1 ,
V_37 -> V_48 , V_37 -> V_63 ,
false ) ;
V_101 -> V_57 = V_37 -> V_41 ;
V_56 ( & V_101 -> V_84 ) ;
}
static int F_139 ( struct V_31 * V_32 )
{
T_1 V_35 [ 10 ] = { V_272 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 } ;
T_1 V_273 [ 255 ] ;
int V_57 ;
void * V_274 ;
struct V_270 V_101 ;
F_24 ( & V_32 -> V_44 -> V_32 , L_10 , V_61 ) ;
F_63 ( & V_101 . V_84 ) ;
V_274 = V_32 -> V_47 -> V_38 ;
V_32 -> V_47 -> V_48 = V_273 ;
V_32 -> V_47 -> V_63 = 255 ;
V_32 -> V_47 -> V_56 = F_137 ;
V_32 -> V_47 -> V_38 = & V_101 ;
V_32 -> V_62 -> V_48 = V_35 ;
V_32 -> V_62 -> V_63 = sizeof( V_35 ) ;
F_138 ( V_271 , L_53 , V_49 , 16 , 1 ,
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
V_32 -> V_47 -> V_38 = V_274 ;
return V_101 . V_57 ;
}
static int F_140 ( struct V_169 * V_169 , T_1 V_275 )
{
struct V_31 * V_32 = F_109 ( V_169 ) ;
T_1 V_276 = ! ! V_275 ;
int V_57 ;
V_57 = F_134 ( V_32 , V_277 ,
( T_1 * ) & V_276 , 1 ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_56 ) ;
return V_57 ;
}
return V_57 ;
}
int F_141 ( struct V_169 * V_169 )
{
return F_140 ( V_169 , 1 ) ;
}
int F_142 ( struct V_169 * V_169 )
{
return F_140 ( V_169 , 0 ) ;
}
static int F_143 ( struct V_31 * V_32 )
{
struct V_278 V_279 ;
struct V_280 V_281 ;
T_1 V_282 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_57 ;
switch ( V_32 -> V_102 ) {
case V_283 :
V_279 . V_284 = V_285 ;
V_279 . V_286 = 2 ;
V_279 . V_287 =
V_288 ;
V_281 . V_289 = V_290 ;
V_281 . V_291 = V_292 ;
V_281 . V_293 = V_294 ;
break;
case V_253 :
case V_103 :
V_279 . V_284 = 0x2 ;
V_279 . V_286 = 0x1 ;
V_279 . V_287 =
V_288 ;
V_281 . V_289 = V_290 ;
V_281 . V_291 = V_290 ;
V_281 . V_293 = V_292 ;
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 , L_57 ,
V_32 -> V_102 ) ;
return - V_195 ;
}
V_57 = F_134 ( V_32 , V_295 ,
( T_1 * ) & V_279 , sizeof( V_279 ) ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_58 ) ;
return V_57 ;
}
V_57 = F_134 ( V_32 , V_296 ,
( T_1 * ) & V_281 , sizeof( V_281 ) ) ;
if ( V_57 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_59 ) ;
return V_57 ;
}
switch ( V_32 -> V_102 ) {
case V_283 :
break;
case V_253 :
F_136 ( V_32 ) ;
V_57 = F_134 ( V_32 , V_297 ,
V_282 , 3 ) ;
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
static int F_144 ( struct V_298 * V_44 ,
const struct V_299 * V_300 )
{
struct V_263 V_301 ;
struct V_31 * V_32 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
int V_306 = 0 ;
int V_307 = 0 ;
int V_57 = - V_88 ;
int V_23 ;
T_4 V_308 ;
V_32 = F_45 ( sizeof( * V_32 ) , V_68 ) ;
if ( ! V_32 )
return - V_88 ;
V_32 -> V_309 = F_145 ( F_146 ( V_44 ) ) ;
V_32 -> V_44 = V_44 ;
F_147 ( & V_32 -> V_89 ) ;
V_303 = V_44 -> V_310 ;
for ( V_23 = 0 ; V_23 < V_303 -> V_311 . V_312 ; ++ V_23 ) {
V_305 = & V_303 -> V_305 [ V_23 ] . V_311 ;
if ( ! V_306 && F_148 ( V_305 ) )
V_306 = V_305 -> V_313 ;
if ( ! V_307 && F_149 ( V_305 ) )
V_307 = V_305 -> V_313 ;
}
if ( ! V_306 || ! V_307 ) {
F_25 ( & V_44 -> V_32 ,
L_61 ) ;
V_57 = - V_314 ;
goto error;
}
V_32 -> V_47 = F_150 ( 0 , V_68 ) ;
V_32 -> V_62 = F_150 ( 0 , V_68 ) ;
if ( ! V_32 -> V_47 || ! V_32 -> V_62 )
goto error;
F_151 ( V_32 -> V_47 , V_32 -> V_309 ,
F_152 ( V_32 -> V_309 , V_306 ) ,
NULL , 0 , NULL , V_32 ) ;
F_151 ( V_32 -> V_62 , V_32 -> V_309 ,
F_153 ( V_32 -> V_309 , V_307 ) ,
NULL , 0 , F_65 , V_32 ) ;
F_154 ( & V_32 -> V_98 , F_57 ) ;
F_154 ( & V_32 -> V_54 , F_55 ) ;
F_154 ( & V_32 -> V_248 , F_133 ) ;
F_154 ( & V_32 -> V_189 , F_98 ) ;
F_154 ( & V_32 -> V_202 , F_106 ) ;
V_32 -> V_53 = F_155 ( L_62 , 0 ) ;
if ( V_32 -> V_53 == NULL )
goto error;
F_156 ( & V_32 -> V_205 ) ;
V_32 -> V_205 . V_12 = ( unsigned long ) V_32 ;
V_32 -> V_205 . V_315 = F_101 ;
F_157 ( & V_32 -> V_225 ) ;
F_47 ( & V_32 -> V_93 ) ;
F_158 ( V_44 , V_32 ) ;
V_32 -> V_33 = & V_316 ;
V_32 -> V_69 = V_71 ;
V_32 -> V_102 = V_300 -> V_317 ;
switch ( V_32 -> V_102 ) {
case V_283 :
V_308 = V_318 ;
break;
case V_253 :
V_308 = V_319 ;
break;
case V_103 :
V_308 = V_319 ;
V_32 -> V_33 = & V_320 ;
V_32 -> V_69 = V_70 ,
V_57 = F_139 ( V_32 ) ;
if ( V_57 < 0 ) {
F_25 ( & V_32 -> V_44 -> V_32 ,
L_63 ,
V_57 ) ;
goto V_321;
}
break;
default:
F_25 ( & V_32 -> V_44 -> V_32 , L_57 ,
V_32 -> V_102 ) ;
V_57 = - V_195 ;
goto V_321;
}
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
V_57 = F_135 ( V_32 , & V_301 ) ;
if ( V_57 < 0 )
goto V_321;
F_159 ( & V_32 -> V_44 -> V_32 ,
L_64 ,
V_301 . V_267 , V_301 . V_268 ) ;
V_32 -> V_169 = F_160 ( & V_322 , V_308 ,
V_323 ,
V_32 -> V_33 -> V_75 +
V_258 ,
V_32 -> V_33 -> V_76 ) ;
if ( ! V_32 -> V_169 )
goto V_321;
F_161 ( V_32 -> V_169 , & V_44 -> V_32 ) ;
F_162 ( V_32 -> V_169 , V_32 ) ;
V_57 = F_163 ( V_32 -> V_169 ) ;
if ( V_57 )
goto V_324;
V_57 = F_143 ( V_32 ) ;
if ( V_57 )
goto V_325;
return 0 ;
V_325:
F_164 ( V_32 -> V_169 ) ;
V_324:
F_165 ( V_32 -> V_169 ) ;
V_321:
F_166 ( V_32 -> V_53 ) ;
error:
F_167 ( V_32 -> V_47 ) ;
F_167 ( V_32 -> V_62 ) ;
F_168 ( V_32 -> V_309 ) ;
F_43 ( V_32 ) ;
return V_57 ;
}
static void F_169 ( struct V_298 * V_44 )
{
struct V_31 * V_32 ;
struct V_39 * V_35 , * V_326 ;
V_32 = F_170 ( V_44 ) ;
F_158 ( V_44 , NULL ) ;
F_164 ( V_32 -> V_169 ) ;
F_165 ( V_32 -> V_169 ) ;
F_67 ( V_32 -> V_47 ) ;
F_67 ( V_32 -> V_62 ) ;
F_166 ( V_32 -> V_53 ) ;
F_116 ( & V_32 -> V_225 ) ;
F_103 ( & V_32 -> V_205 ) ;
F_171 (cmd, n, &dev->cmd_queue, queue) {
F_60 ( & V_35 -> V_92 ) ;
F_43 ( V_35 ) ;
}
F_167 ( V_32 -> V_47 ) ;
F_167 ( V_32 -> V_62 ) ;
F_43 ( V_32 ) ;
F_159 ( & V_44 -> V_32 , L_65 ) ;
}
