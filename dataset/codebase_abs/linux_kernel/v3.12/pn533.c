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
static bool F_4 ( void * V_1 , struct V_19 * V_20 )
{
struct V_21 * V_4 = V_1 ;
if ( V_4 -> V_5 . type != 0x83 )
return false ;
if ( V_4 -> V_12 [ V_4 -> V_5 . V_7 - 2 ] == 0x63 )
return false ;
return true ;
}
static int F_5 ( void * V_4 )
{
struct V_21 * V_22 = V_4 ;
return sizeof( struct V_21 ) + V_22 -> V_5 . V_7 ;
}
static T_1 F_6 ( void * V_4 )
{
struct V_21 * V_22 = V_4 ;
return F_7 ( V_22 ) ;
}
static inline T_1 F_8 ( T_2 V_23 )
{
return ~ ( T_1 ) ( ( ( V_23 & 0xFF00 ) >> 8 ) + ( T_1 ) ( V_23 & 0xFF ) ) + 1 ;
}
static inline T_1 F_9 ( T_1 V_23 )
{
return ~ V_23 + 1 ;
}
static T_1 F_10 ( T_1 * V_12 , int V_7 )
{
T_1 V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_7 ; V_25 ++ )
V_24 += V_12 [ V_25 ] ;
return F_9 ( V_24 ) ;
}
static void F_11 ( void * V_1 , T_1 V_2 )
{
struct V_26 * V_4 = V_1 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = F_12 ( V_29 ) ;
F_13 ( V_4 ) = V_13 ;
F_7 ( V_4 ) = V_2 ;
V_4 -> V_7 = 2 ;
}
static void F_14 ( void * V_1 )
{
struct V_26 * V_4 = V_1 ;
V_4 -> V_30 = F_9 ( V_4 -> V_7 ) ;
F_15 ( V_4 ) =
F_10 ( V_4 -> V_12 , V_4 -> V_7 ) ;
F_16 ( V_4 ) = 0 ;
}
static void F_17 ( void * V_1 , int V_18 )
{
struct V_26 * V_4 = V_1 ;
V_4 -> V_7 += V_18 ;
}
static bool F_18 ( void * V_1 , struct V_19 * V_20 )
{
T_1 V_31 ;
struct V_26 * V_32 = V_1 ;
if ( V_32 -> V_28 != F_12 ( V_29 ) )
return false ;
if ( F_19 ( ! F_20 ( V_32 ) ) ) {
V_20 -> V_33 -> V_34 = V_35 ;
V_31 = F_9 ( V_32 -> V_7 ) ;
if ( V_31 != V_32 -> V_30 )
return false ;
V_31 = F_10 ( V_32 -> V_12 , V_32 -> V_7 ) ;
if ( V_31 != F_15 ( V_32 ) )
return false ;
} else {
struct V_36 * V_37 = V_1 ;
V_20 -> V_33 -> V_34 = V_38 ;
V_31 = F_8 ( F_21 ( V_37 -> V_7 ) ) ;
if ( V_31 != V_37 -> V_30 )
return false ;
V_31 = F_10 ( V_37 -> V_12 ,
F_21 ( V_37 -> V_7 ) ) ;
if ( V_31 != F_22 ( V_37 ) )
return false ;
}
return true ;
}
static bool F_23 ( struct V_26 * V_4 )
{
if ( V_4 -> V_28 != F_12 ( V_29 ) )
return false ;
if ( V_4 -> V_7 != 0 || V_4 -> V_30 != 0xFF )
return false ;
return true ;
}
static inline int F_24 ( void * V_4 )
{
struct V_26 * V_22 = V_4 ;
if ( F_20 ( V_22 ) ) {
struct V_36 * V_37 = V_4 ;
return sizeof( struct V_36 )
+ F_21 ( V_37 -> V_7 ) + V_39 ;
}
return sizeof( struct V_26 ) + V_22 -> V_7 +
V_39 ;
}
static T_1 F_25 ( void * V_4 )
{
struct V_26 * V_22 = V_4 ;
struct V_36 * V_37 = V_4 ;
if ( F_20 ( V_22 ) )
return F_7 ( V_37 ) ;
else
return F_7 ( V_22 ) ;
}
static bool F_26 ( struct V_19 * V_20 , void * V_4 )
{
return ( V_20 -> V_33 -> V_40 ( V_4 ) ==
F_27 ( V_20 -> V_41 -> V_42 ) ) ;
}
static void F_28 ( struct V_43 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_44 ;
struct V_45 * V_41 = V_20 -> V_41 ;
T_1 * V_46 ;
V_41 -> V_47 = V_43 -> V_47 ;
switch ( V_43 -> V_47 ) {
case 0 :
break;
case - V_48 :
case - V_49 :
F_29 ( & V_20 -> V_50 -> V_20 ,
L_1 ,
V_43 -> V_47 ) ;
goto V_51;
case - V_52 :
default:
F_30 ( & V_20 -> V_50 -> V_20 ,
L_2 , V_43 -> V_47 ) ;
goto V_51;
}
V_46 = V_20 -> V_53 -> V_54 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_3 ) ;
F_31 ( L_4 , V_55 , 16 , 1 , V_46 ,
V_20 -> V_33 -> V_56 ( V_46 ) , false ) ;
if ( ! V_20 -> V_33 -> V_57 ( V_46 , V_20 ) ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_5 ) ;
V_41 -> V_47 = - V_58 ;
goto V_51;
}
if ( ! F_26 ( V_20 , V_46 ) ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_6 ) ;
V_41 -> V_47 = - V_58 ;
goto V_51;
}
V_51:
F_32 ( V_20 -> V_59 , & V_20 -> V_60 ) ;
}
static int F_33 ( struct V_19 * V_20 , T_3 V_61 )
{
V_20 -> V_53 -> V_62 = F_28 ;
return F_34 ( V_20 -> V_53 , V_61 ) ;
}
static void F_35 ( struct V_43 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_44 ;
struct V_45 * V_41 = V_20 -> V_41 ;
struct V_26 * V_46 ;
int V_63 ;
V_41 -> V_47 = V_43 -> V_47 ;
switch ( V_43 -> V_47 ) {
case 0 :
break;
case - V_48 :
case - V_49 :
F_29 ( & V_20 -> V_50 -> V_20 ,
L_7 ,
V_43 -> V_47 ) ;
goto V_51;
case - V_52 :
default:
F_30 ( & V_20 -> V_50 -> V_20 ,
L_2 , V_43 -> V_47 ) ;
goto V_51;
}
V_46 = V_20 -> V_53 -> V_54 ;
if ( ! F_23 ( V_46 ) ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_8 ) ;
V_41 -> V_47 = - V_58 ;
goto V_51;
}
V_63 = F_33 ( V_20 , V_64 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_9 , V_63 ) ;
V_41 -> V_47 = V_63 ;
goto V_51;
}
return;
V_51:
F_32 ( V_20 -> V_59 , & V_20 -> V_60 ) ;
}
static int F_36 ( struct V_19 * V_20 , T_3 V_61 )
{
V_20 -> V_53 -> V_62 = F_35 ;
return F_34 ( V_20 -> V_53 , V_61 ) ;
}
static int F_37 ( struct V_19 * V_20 , T_3 V_61 )
{
T_1 V_65 [ V_66 ] = { 0x00 , 0x00 , 0xff , 0x00 , 0xff , 0x00 } ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_20 -> V_68 -> V_54 = V_65 ;
V_20 -> V_68 -> V_69 = sizeof( V_65 ) ;
V_63 = F_34 ( V_20 -> V_68 , V_61 ) ;
return V_63 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_70 * V_71 ,
struct V_70 * V_72 ,
int V_73 )
{
int V_63 ;
V_20 -> V_68 -> V_54 = V_71 -> V_12 ;
V_20 -> V_68 -> V_69 = V_71 -> V_18 ;
V_20 -> V_53 -> V_54 = V_72 -> V_12 ;
V_20 -> V_53 -> V_69 = V_73 ;
F_31 ( L_11 , V_55 , 16 , 1 ,
V_71 -> V_12 , V_71 -> V_18 , false ) ;
V_63 = F_34 ( V_20 -> V_68 , V_74 ) ;
if ( V_63 )
return V_63 ;
if ( V_20 -> V_75 == V_76 ) {
V_63 = F_33 ( V_20 , V_64 ) ;
if ( V_63 )
goto error;
} else if ( V_20 -> V_75 == V_77 ) {
V_63 = F_36 ( V_20 , V_74 ) ;
if ( V_63 )
goto error;
}
return 0 ;
error:
F_39 ( V_20 -> V_68 ) ;
return V_63 ;
}
static void F_40 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_78 )
{
int V_79 = V_78 -> V_18 ;
struct V_80 * V_33 = V_20 -> V_33 ;
F_41 ( V_78 , V_33 -> V_81 ) ;
F_42 ( V_78 , V_33 -> V_82 ) ;
V_33 -> V_83 ( V_78 -> V_12 , V_2 ) ;
V_33 -> V_84 ( V_78 -> V_12 , V_79 ) ;
V_33 -> V_85 ( V_78 -> V_12 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_45 * V_41 = V_20 -> V_41 ;
int V_47 = V_41 -> V_47 ;
struct V_70 * V_86 = V_41 -> V_86 ;
struct V_70 * V_87 = V_41 -> V_87 ;
int V_63 ;
F_44 ( V_86 ) ;
if ( V_47 < 0 ) {
V_63 = V_41 -> V_88 ( V_20 , V_41 -> V_89 ,
F_45 ( V_47 ) ) ;
F_44 ( V_87 ) ;
goto V_90;
}
F_42 ( V_87 , V_20 -> V_33 -> V_56 ( V_87 -> V_12 ) ) ;
F_46 ( V_87 , V_20 -> V_33 -> V_34 ) ;
F_47 ( V_87 , V_87 -> V_18 - V_20 -> V_33 -> V_91 ) ;
V_63 = V_41 -> V_88 ( V_20 , V_41 -> V_89 , V_87 ) ;
V_90:
F_48 ( V_41 ) ;
V_20 -> V_41 = NULL ;
return V_63 ;
}
static int F_49 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_86 , struct V_70 * V_87 ,
int V_92 ,
T_4 V_88 ,
void * V_89 )
{
struct V_45 * V_41 ;
int V_63 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_12 , V_2 ) ;
V_41 = F_50 ( sizeof( * V_41 ) , V_74 ) ;
if ( ! V_41 )
return - V_93 ;
V_41 -> V_42 = V_2 ;
V_41 -> V_86 = V_86 ;
V_41 -> V_87 = V_87 ;
V_41 -> V_92 = V_92 ;
V_41 -> V_88 = V_88 ;
V_41 -> V_89 = V_89 ;
F_40 ( V_20 , V_2 , V_86 ) ;
F_51 ( & V_20 -> V_94 ) ;
if ( ! V_20 -> V_95 ) {
V_63 = F_38 ( V_20 , V_86 , V_87 , V_92 ) ;
if ( V_63 )
goto error;
V_20 -> V_95 = 1 ;
V_20 -> V_41 = V_41 ;
goto V_96;
}
F_29 ( & V_20 -> V_50 -> V_20 , L_13 , V_67 ,
V_2 ) ;
F_52 ( & V_41 -> V_97 ) ;
F_53 ( & V_41 -> V_97 , & V_20 -> V_98 ) ;
goto V_96;
error:
F_48 ( V_41 ) ;
V_96:
F_54 ( & V_20 -> V_94 ) ;
return V_63 ;
}
static int F_55 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_86 ,
T_4 V_88 ,
void * V_89 )
{
struct V_70 * V_87 ;
int V_63 ;
int V_92 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_91 ;
V_87 = F_56 ( V_92 , V_74 ) ;
if ( ! V_87 )
return - V_93 ;
V_63 = F_49 ( V_20 , V_2 , V_86 , V_87 , V_92 , V_88 ,
V_89 ) ;
if ( V_63 )
F_44 ( V_87 ) ;
return V_63 ;
}
static int F_57 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_86 ,
T_4 V_88 ,
void * V_89 )
{
struct V_70 * V_87 ;
int V_63 ;
int V_92 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_91 ;
V_87 = F_58 ( V_92 , V_74 ) ;
if ( ! V_87 )
return - V_93 ;
V_63 = F_49 ( V_20 , V_2 , V_86 , V_87 , V_92 , V_88 ,
V_89 ) ;
if ( V_63 )
F_44 ( V_87 ) ;
return V_63 ;
}
static int F_59 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_86 ,
T_4 V_88 ,
void * V_89 )
{
struct V_70 * V_87 ;
struct V_45 * V_41 ;
int V_63 ;
int V_92 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_91 ;
V_87 = F_58 ( V_92 , V_74 ) ;
if ( ! V_87 )
return - V_93 ;
V_41 = F_50 ( sizeof( * V_41 ) , V_74 ) ;
if ( ! V_41 ) {
F_44 ( V_87 ) ;
return - V_93 ;
}
V_41 -> V_42 = V_2 ;
V_41 -> V_86 = V_86 ;
V_41 -> V_87 = V_87 ;
V_41 -> V_92 = V_92 ;
V_41 -> V_88 = V_88 ;
V_41 -> V_89 = V_89 ;
F_40 ( V_20 , V_2 , V_86 ) ;
V_63 = F_38 ( V_20 , V_86 , V_87 , V_92 ) ;
if ( V_63 < 0 ) {
F_44 ( V_87 ) ;
F_48 ( V_41 ) ;
} else {
V_20 -> V_41 = V_41 ;
}
return V_63 ;
}
static void F_60 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_60 ) ;
int V_63 ;
V_63 = F_43 ( V_20 ) ;
if ( V_63 != - V_102 )
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static void F_62 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_103 ) ;
struct V_45 * V_41 ;
int V_63 ;
F_51 ( & V_20 -> V_94 ) ;
if ( F_63 ( & V_20 -> V_98 ) ) {
V_20 -> V_95 = 0 ;
F_54 ( & V_20 -> V_94 ) ;
return;
}
V_41 = F_64 ( & V_20 -> V_98 , struct V_45 , V_97 ) ;
F_65 ( & V_41 -> V_97 ) ;
F_54 ( & V_20 -> V_94 ) ;
V_63 = F_38 ( V_20 , V_41 -> V_86 , V_41 -> V_87 , V_41 -> V_92 ) ;
if ( V_63 < 0 ) {
F_44 ( V_41 -> V_86 ) ;
F_44 ( V_41 -> V_87 ) ;
F_48 ( V_41 ) ;
return;
}
V_20 -> V_41 = V_41 ;
}
static int F_66 ( struct V_19 * V_20 , void * V_104 ,
struct V_70 * V_87 )
{
struct V_105 * V_106 = V_104 ;
V_106 -> V_87 = V_87 ;
V_62 ( & V_106 -> V_90 ) ;
return 0 ;
}
static struct V_70 * F_67 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_70 * V_86 )
{
int V_63 ;
struct V_105 V_106 ;
F_68 ( & V_106 . V_90 ) ;
V_63 = F_57 ( V_20 , V_2 , V_86 ,
F_66 , & V_106 ) ;
if ( V_63 ) {
F_44 ( V_86 ) ;
return F_45 ( V_63 ) ;
}
F_69 ( & V_106 . V_90 ) ;
return V_106 . V_87 ;
}
static void F_70 ( struct V_43 * V_43 )
{
struct V_19 * V_20 = V_43 -> V_44 ;
switch ( V_43 -> V_47 ) {
case 0 :
break;
case - V_48 :
case - V_49 :
F_29 ( & V_20 -> V_50 -> V_20 ,
L_7 ,
V_43 -> V_47 ) ;
break;
case - V_52 :
default:
F_30 ( & V_20 -> V_50 -> V_20 ,
L_2 , V_43 -> V_47 ) ;
}
}
static void F_71 ( struct V_19 * V_20 , T_3 V_61 )
{
if ( V_20 -> V_107 == V_108 )
return;
F_37 ( V_20 , V_61 ) ;
F_72 ( V_20 -> V_53 ) ;
}
static struct V_70 * F_73 ( struct V_19 * V_20 , unsigned int V_109 )
{
struct V_70 * V_78 ;
V_78 = F_58 ( V_20 -> V_33 -> V_81 +
V_109 +
V_20 -> V_33 -> V_82 , V_74 ) ;
if ( V_78 )
F_74 ( V_78 , V_20 -> V_33 -> V_81 ) ;
return V_78 ;
}
static bool F_75 ( struct V_110 * V_111 ,
int V_112 )
{
T_1 V_113 ;
T_1 V_114 ;
if ( V_112 < sizeof( struct V_110 ) )
return false ;
V_113 = F_76 ( V_111 -> V_115 ) ;
V_114 = F_77 ( V_111 -> V_115 ) ;
if ( ( V_113 == V_116 &&
V_114 != V_117 ) ||
( V_113 != V_116 &&
V_114 == V_117 ) )
return false ;
if ( F_78 ( V_111 -> V_118 ) != 0 )
return false ;
return true ;
}
static int F_79 ( struct V_119 * V_120 , T_1 * V_121 ,
int V_122 )
{
struct V_110 * V_123 ;
V_123 = (struct V_110 * ) V_121 ;
if ( ! F_75 ( V_123 , V_122 ) )
return - V_124 ;
switch ( F_80 ( V_123 -> V_118 ) ) {
case V_125 :
V_120 -> V_126 = V_127 ;
break;
case V_128 :
V_120 -> V_126 = V_129 ;
break;
case V_130 :
V_120 -> V_126 = V_131 ;
break;
case V_132 :
V_120 -> V_126 = V_129 |
V_131 ;
break;
}
V_120 -> V_115 = F_21 ( V_123 -> V_115 ) ;
V_120 -> V_118 = V_123 -> V_118 ;
V_120 -> V_133 = V_123 -> V_134 ;
memcpy ( V_120 -> V_135 , V_123 -> V_136 , V_120 -> V_133 ) ;
return 0 ;
}
static bool F_81 ( struct V_137 * V_138 ,
int V_112 )
{
if ( V_112 < sizeof( struct V_137 ) )
return false ;
if ( V_138 -> V_139 != V_140 )
return false ;
return true ;
}
static int F_82 ( struct V_119 * V_120 , T_1 * V_121 ,
int V_122 )
{
struct V_137 * V_141 ;
V_141 = (struct V_137 * ) V_121 ;
if ( ! F_81 ( V_141 , V_122 ) )
return - V_124 ;
if ( ( V_141 -> V_142 [ 0 ] == V_143 ) &&
( V_141 -> V_142 [ 1 ] == V_144 ) )
V_120 -> V_126 = V_131 ;
else
V_120 -> V_126 = V_145 ;
memcpy ( V_120 -> V_146 , & V_141 -> V_139 , 9 ) ;
V_120 -> V_147 = 9 ;
memcpy ( V_120 -> V_142 , V_141 -> V_142 , V_148 ) ;
V_120 -> V_149 = V_148 ;
return 0 ;
}
static bool F_83 ( struct V_150 * V_151 ,
int V_112 )
{
T_1 V_113 ;
T_1 V_114 ;
if ( V_112 < sizeof( struct V_150 ) )
return false ;
V_113 = F_76 ( V_151 -> V_115 ) ;
V_114 = F_77 ( V_151 -> V_115 ) ;
if ( ( V_113 == V_116 &&
V_114 != V_117 ) ||
( V_113 != V_116 &&
V_114 == V_117 ) )
return false ;
return true ;
}
static int F_84 ( struct V_119 * V_120 , T_1 * V_121 ,
int V_122 )
{
struct V_150 * V_152 ;
V_152 = (struct V_150 * ) V_121 ;
if ( ! F_83 ( V_152 , V_122 ) )
return - V_124 ;
V_120 -> V_126 = V_153 ;
V_120 -> V_115 = F_21 ( V_152 -> V_115 ) ;
V_120 -> V_133 = 4 ;
memcpy ( V_120 -> V_135 , V_152 -> V_154 , V_120 -> V_133 ) ;
return 0 ;
}
static bool F_85 ( struct V_155 * V_156 ,
int V_112 )
{
if ( V_112 < sizeof( struct V_155 ) )
return false ;
if ( V_156 -> V_157 . V_139 != V_158 )
return false ;
if ( F_86 ( V_156 -> V_157 . V_159 . V_160 ) &
V_161 )
return false ;
return true ;
}
static int F_87 ( struct V_119 * V_120 , T_1 * V_121 ,
int V_122 )
{
struct V_155 * V_162 ;
V_162 = (struct V_155 * ) V_121 ;
if ( ! F_85 ( V_162 , V_122 ) )
return - V_124 ;
V_120 -> V_126 = V_163 ;
return 0 ;
}
static int F_88 ( struct V_19 * V_20 , T_1 V_164 , T_1 * V_165 ,
int V_166 )
{
struct V_119 V_120 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_14 , V_67 ,
V_20 -> V_167 ) ;
if ( V_164 != 1 )
return - V_124 ;
memset ( & V_120 , 0 , sizeof( struct V_119 ) ) ;
switch ( V_20 -> V_167 ) {
case V_168 :
V_63 = F_79 ( & V_120 , V_165 , V_166 ) ;
break;
case V_169 :
case V_170 :
V_63 = F_82 ( & V_120 , V_165 , V_166 ) ;
break;
case V_171 :
V_63 = F_84 ( & V_120 , V_165 , V_166 ) ;
break;
case V_172 :
V_63 = F_87 ( & V_120 , V_165 , V_166 ) ;
break;
default:
F_30 ( & V_20 -> V_50 -> V_20 ,
L_15 ) ;
return - V_124 ;
}
if ( V_63 )
return V_63 ;
if ( ! ( V_120 . V_126 & V_20 -> V_173 ) ) {
F_29 ( & V_20 -> V_50 -> V_20 ,
L_16 ) ;
return - V_174 ;
}
F_29 ( & V_20 -> V_50 -> V_20 ,
L_17 ,
V_120 . V_126 ) ;
V_20 -> V_175 = V_120 . V_126 ;
F_89 ( V_20 -> V_176 , & V_120 , 1 ) ;
return 0 ;
}
static inline void F_90 ( struct V_19 * V_20 )
{
V_20 -> V_167 = ( V_20 -> V_167 + 1 ) % V_20 -> V_177 ;
}
static void F_91 ( struct V_19 * V_20 )
{
V_20 -> V_177 = 0 ;
}
static void F_92 ( struct V_19 * V_20 , T_1 V_178 )
{
V_20 -> V_179 [ V_20 -> V_177 ] =
(struct V_180 * ) & V_181 [ V_178 ] ;
V_20 -> V_177 ++ ;
}
static void F_93 ( struct V_19 * V_20 ,
T_5 V_182 , T_5 V_183 )
{
F_91 ( V_20 ) ;
if ( ( V_182 & V_127 ) ||
( V_182 & V_129 ) ||
( V_182 & V_131 ) )
F_92 ( V_20 , V_168 ) ;
if ( V_182 & V_145 ||
V_182 & V_131 ) {
F_92 ( V_20 , V_169 ) ;
F_92 ( V_20 , V_170 ) ;
}
if ( V_182 & V_153 )
F_92 ( V_20 , V_171 ) ;
if ( V_182 & V_163 )
F_92 ( V_20 , V_172 ) ;
if ( V_183 )
F_92 ( V_20 , V_184 ) ;
}
static int F_94 ( struct V_19 * V_20 , struct V_70 * V_87 )
{
T_1 V_185 , V_164 , * V_165 ;
int V_63 , V_166 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_185 = V_87 -> V_12 [ 0 ] ;
V_164 = V_87 -> V_12 [ 1 ] ;
V_165 = & V_87 -> V_12 [ 2 ] ;
V_166 = V_87 -> V_18 - 2 ;
if ( V_185 ) {
V_63 = F_88 ( V_20 , V_164 , V_165 , V_166 ) ;
if ( V_63 == 0 ) {
F_91 ( V_20 ) ;
return 0 ;
}
}
return - V_174 ;
}
static struct V_70 * F_95 ( struct V_19 * V_20 )
{
struct V_70 * V_78 ;
T_1 * V_138 , * V_186 , * V_187 ;
T_1 * V_188 = V_20 -> V_187 ;
T_6 V_189 = V_20 -> V_190 ;
T_1 V_191 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_192 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_193 = 36 +
V_189 +
1 ;
V_78 = F_73 ( V_20 , V_193 ) ;
if ( ! V_78 )
return NULL ;
* F_42 ( V_78 , 1 ) = V_194 ;
memcpy ( F_42 ( V_78 , 6 ) , V_192 , 6 ) ;
V_138 = F_42 ( V_78 , 18 ) ;
memcpy ( V_138 , V_191 , 18 ) ;
F_96 ( V_138 + 2 , 6 ) ;
V_186 = F_42 ( V_78 , 10 ) ;
memset ( V_186 , 0 , 10 ) ;
memcpy ( V_186 , V_138 , 8 ) ;
* F_42 ( V_78 , 1 ) = V_189 ;
V_187 = F_42 ( V_78 , V_189 ) ;
memcpy ( V_187 , V_188 , V_189 ) ;
* F_42 ( V_78 , 1 ) = 0 ;
return V_78 ;
}
static int F_97 ( struct V_19 * V_20 , void * V_106 ,
struct V_70 * V_87 )
{
T_1 V_47 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
V_47 = V_87 -> V_12 [ 0 ] ;
F_46 ( V_87 , sizeof( V_47 ) ) ;
if ( V_47 != 0 ) {
F_100 ( V_20 -> V_176 ) ;
V_20 -> V_195 = 0 ;
F_44 ( V_87 ) ;
return 0 ;
}
return F_101 ( V_20 -> V_176 , V_87 ) ;
}
static void F_102 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_196 ) ;
struct V_70 * V_78 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_73 ( V_20 , 0 ) ;
if ( ! V_78 )
return;
V_63 = F_55 ( V_20 , V_197 , V_78 ,
F_97 , NULL ) ;
if ( V_63 < 0 )
F_44 ( V_78 ) ;
return;
}
static int F_103 ( struct V_19 * V_20 , struct V_70 * V_87 )
{
T_1 V_198 , * V_41 , V_199 = V_200 , * V_187 ;
T_6 V_190 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( V_87 -> V_18 < V_201 + 1 )
return - V_202 ;
V_198 = V_87 -> V_12 [ 0 ] ;
V_41 = & V_87 -> V_12 [ 1 ] ;
F_29 ( & V_20 -> V_50 -> V_20 , L_18 ,
V_198 , V_87 -> V_18 ) ;
if ( ( V_198 & V_203 ) ==
V_204 )
V_199 = V_205 ;
if ( ( V_198 & V_206 ) == 0 )
return - V_207 ;
V_187 = V_41 + V_201 ;
V_190 = V_87 -> V_18 - ( V_201 + 1 ) ;
V_63 = F_104 ( V_20 -> V_176 , V_131 ,
V_199 , V_187 , V_190 ) ;
if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_19 ) ;
return V_63 ;
}
V_20 -> V_195 = 1 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_196 ) ;
return 0 ;
}
static void F_105 ( unsigned long V_12 )
{
struct V_19 * V_20 = (struct V_19 * ) V_12 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_20 ) ;
V_20 -> V_208 = 1 ;
F_90 ( V_20 ) ;
F_106 ( V_20 -> V_59 , & V_20 -> V_209 ,
F_107 ( V_210 ) ) ;
}
static int F_108 ( struct V_19 * V_20 , void * V_106 ,
struct V_70 * V_87 )
{
int V_63 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_98 ( V_87 ) ) {
V_63 = F_99 ( V_87 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_21 ,
V_67 , V_63 ) ;
return V_63 ;
}
F_106 ( V_20 -> V_59 , & V_20 -> V_209 ,
F_107 ( V_210 ) ) ;
F_44 ( V_87 ) ;
return V_63 ;
}
static void F_109 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_211 ) ;
struct V_70 * V_78 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_73 ( V_20 , 2 ) ;
if ( ! V_78 )
return;
* F_42 ( V_78 , 1 ) = V_212 ;
* F_42 ( V_78 , 1 ) = V_213 ;
V_63 = F_57 ( V_20 , V_214 , V_78 ,
F_108 , NULL ) ;
if ( V_63 < 0 ) {
F_44 ( V_78 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_22 , V_63 ) ;
}
return;
}
static int F_110 ( struct V_19 * V_20 , void * V_106 ,
struct V_70 * V_87 )
{
struct V_180 * V_215 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_98 ( V_87 ) ) {
V_63 = F_99 ( V_87 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_23 ,
V_67 , V_63 ) ;
if ( V_63 == - V_49 ) {
if ( V_20 -> V_177 != 0 )
return V_63 ;
else
goto V_216;
} else if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_24 , V_63 ) ;
goto V_216;
}
}
V_215 = V_20 -> V_179 [ V_20 -> V_167 ] ;
if ( V_215 -> V_18 == 0 ) {
F_111 ( & V_20 -> V_217 ) ;
V_63 = F_103 ( V_20 , V_87 ) ;
goto V_90;
}
V_63 = F_94 ( V_20 , V_87 ) ;
if ( ! V_63 )
goto V_90;
if ( ! V_20 -> V_177 ) {
F_29 ( & V_20 -> V_50 -> V_20 , L_25 ) ;
goto V_90;
}
F_90 ( V_20 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_211 ) ;
V_90:
F_44 ( V_87 ) ;
return V_63 ;
V_216:
F_30 ( & V_20 -> V_50 -> V_20 , L_26 ) ;
F_91 ( V_20 ) ;
V_20 -> V_173 = 0 ;
return V_63 ;
}
static struct V_70 * F_112 ( struct V_19 * V_20 ,
struct V_180 * V_218 )
{
struct V_70 * V_78 ;
V_78 = F_73 ( V_20 , V_218 -> V_18 ) ;
if ( ! V_78 )
return NULL ;
memcpy ( F_42 ( V_78 , V_218 -> V_18 ) , & V_218 -> V_12 , V_218 -> V_18 ) ;
return V_78 ;
}
static int F_113 ( struct V_19 * V_20 )
{
struct V_180 * V_218 ;
struct V_70 * V_78 ;
int V_63 ;
T_1 V_2 ;
V_218 = V_20 -> V_179 [ V_20 -> V_167 ] ;
F_29 ( & V_20 -> V_50 -> V_20 , L_27 ,
V_67 , V_218 -> V_18 ) ;
if ( V_218 -> V_18 == 0 ) {
V_2 = V_219 ;
V_78 = F_95 ( V_20 ) ;
} else {
V_2 = V_220 ;
V_78 = F_112 ( V_20 , V_218 ) ;
}
if ( ! V_78 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_28 ) ;
return - V_93 ;
}
V_63 = F_57 ( V_20 , V_2 , V_78 , F_110 ,
NULL ) ;
if ( V_63 < 0 ) {
F_44 ( V_78 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_29 , V_63 ) ;
}
return V_63 ;
}
static void F_114 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_209 . V_101 ) ;
struct V_180 * V_215 ;
int V_63 ;
V_215 = V_20 -> V_179 [ V_20 -> V_167 ] ;
F_29 ( & V_20 -> V_50 -> V_20 ,
L_30 ,
V_67 , V_20 -> V_208 , V_215 -> V_18 ) ;
if ( V_20 -> V_208 == 1 ) {
V_20 -> V_208 = 0 ;
F_71 ( V_20 , V_64 ) ;
}
V_63 = F_113 ( V_20 ) ;
if ( V_63 )
return;
if ( V_215 -> V_18 == 0 && V_20 -> V_177 > 1 )
F_115 ( & V_20 -> V_217 , V_221 + V_222 * V_223 ) ;
return;
}
static int F_116 ( struct V_176 * V_176 ,
T_5 V_182 , T_5 V_183 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
T_1 V_224 ;
F_29 ( & V_20 -> V_50 -> V_20 ,
L_31 ,
V_67 , V_182 , V_183 ) ;
if ( V_20 -> V_225 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_32 ) ;
return - V_226 ;
}
if ( V_20 -> V_195 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_33 ) ;
return - V_226 ;
}
if ( V_183 ) {
V_20 -> V_187 = F_118 ( V_176 , & V_20 -> V_190 ) ;
if ( V_20 -> V_187 == NULL )
V_183 = 0 ;
}
F_93 ( V_20 , V_182 , V_183 ) ;
V_20 -> V_173 = V_182 ;
V_20 -> V_227 = V_183 ;
F_96 ( & V_224 , sizeof( V_224 ) ) ;
V_224 %= V_20 -> V_177 ;
V_20 -> V_167 = V_224 ;
return F_113 ( V_20 ) ;
}
static void F_119 ( struct V_176 * V_176 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
F_111 ( & V_20 -> V_217 ) ;
if ( ! V_20 -> V_177 ) {
F_29 ( & V_20 -> V_50 -> V_20 ,
L_34 ) ;
return;
}
F_71 ( V_20 , V_74 ) ;
F_120 ( & V_20 -> V_209 ) ;
F_91 ( V_20 ) ;
}
static int F_121 ( struct V_19 * V_20 )
{
struct V_228 * V_229 ;
T_2 V_230 ;
int V_63 ;
struct V_70 * V_78 ;
struct V_70 * V_87 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_73 ( V_20 , sizeof( T_1 ) * 2 ) ;
if ( ! V_78 )
return - V_93 ;
* F_42 ( V_78 , sizeof( T_1 ) ) = 1 ;
* F_42 ( V_78 , sizeof( T_1 ) ) = 0 ;
V_87 = F_67 ( V_20 , V_231 , V_78 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
V_229 = (struct V_228 * ) V_87 -> V_12 ;
V_63 = V_229 -> V_47 & V_232 ;
if ( V_63 != V_233 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_35 , V_63 ) ;
F_44 ( V_87 ) ;
return - V_58 ;
}
V_230 = V_87 -> V_18 - 16 ;
V_63 = F_122 ( V_20 -> V_176 , V_229 -> V_234 , V_230 ) ;
F_44 ( V_87 ) ;
return V_63 ;
}
static int F_123 ( struct V_176 * V_176 ,
struct V_119 * V_235 , T_5 V_236 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_36 , V_67 ,
V_236 ) ;
if ( V_20 -> V_177 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_37 ) ;
return - V_226 ;
}
if ( V_20 -> V_225 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_38 ) ;
return - V_226 ;
}
if ( ! V_20 -> V_175 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_39 ) ;
return - V_202 ;
}
if ( ! ( V_20 -> V_175 & ( 1 << V_236 ) ) ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_40 ,
V_236 ) ;
return - V_202 ;
}
if ( V_236 == V_237 ) {
V_63 = F_121 ( V_20 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_41 , V_63 ) ;
return V_63 ;
}
}
V_20 -> V_225 = V_236 ;
V_20 -> V_175 = 0 ;
return 0 ;
}
static void F_124 ( struct V_176 * V_176 ,
struct V_119 * V_235 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
struct V_70 * V_78 ;
struct V_70 * V_87 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( ! V_20 -> V_225 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_42 ) ;
return;
}
V_20 -> V_225 = 0 ;
F_125 ( & V_20 -> V_238 ) ;
V_78 = F_73 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_78 )
return;
* F_42 ( V_78 , 1 ) = 1 ;
V_87 = F_67 ( V_20 , V_239 , V_78 ) ;
if ( F_98 ( V_87 ) )
return;
V_63 = V_87 -> V_12 [ 0 ] & V_232 ;
if ( V_63 != V_233 )
F_30 ( & V_20 -> V_50 -> V_20 ,
L_43 , V_63 ) ;
F_44 ( V_87 ) ;
return;
}
static int F_126 ( struct V_19 * V_20 , void * V_106 ,
struct V_70 * V_87 )
{
struct V_240 * V_229 ;
T_1 V_241 ;
int V_63 ;
T_1 V_242 = * ( T_1 * ) V_106 ;
F_48 ( V_106 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
if ( V_20 -> V_175 &&
! ( V_20 -> V_175 & ( 1 << V_237 ) ) ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_44 ) ;
V_63 = - V_202 ;
goto error;
}
V_229 = (struct V_240 * ) V_87 -> V_12 ;
V_63 = V_229 -> V_47 & V_232 ;
if ( V_63 != V_233 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_45 , V_63 ) ;
goto error;
}
if ( ! V_20 -> V_175 ) {
struct V_119 V_119 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_46 ) ;
V_119 . V_126 = V_131 ;
V_119 . V_133 = 10 ;
memcpy ( V_119 . V_135 , V_229 -> V_243 , V_119 . V_133 ) ;
V_63 = F_89 ( V_20 -> V_176 , & V_119 , 1 ) ;
if ( V_63 )
goto error;
V_20 -> V_175 = 0 ;
}
V_20 -> V_225 = V_237 ;
V_241 = V_87 -> V_18 - 17 ;
V_63 = F_122 ( V_20 -> V_176 ,
V_229 -> V_234 , V_241 ) ;
if ( V_63 == 0 )
V_63 = F_127 ( V_20 -> V_176 ,
V_20 -> V_176 -> V_244 [ 0 ] . V_245 ,
! V_242 , V_246 ) ;
error:
F_44 ( V_87 ) ;
return V_63 ;
}
static int F_128 ( struct V_176 * V_176 , struct V_119 * V_235 ,
T_1 V_199 , T_1 * V_187 , T_6 V_190 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
struct V_70 * V_78 ;
int V_63 , V_193 ;
T_1 * V_247 , * V_106 , V_186 [ V_248 ] ;
T_1 V_249 [ V_250 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( V_20 -> V_177 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_47 ) ;
return - V_226 ;
}
if ( V_20 -> V_225 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_38 ) ;
return - V_226 ;
}
V_193 = 3 + V_190 ;
V_193 += V_250 ;
V_193 += V_248 ;
if ( V_235 && ! V_235 -> V_149 ) {
V_186 [ 0 ] = 0x1 ;
V_186 [ 1 ] = 0xfe ;
F_96 ( V_186 + 2 , 6 ) ;
}
V_78 = F_73 ( V_20 , V_193 ) ;
if ( ! V_78 )
return - V_93 ;
* F_42 ( V_78 , 1 ) = ! V_199 ;
* F_42 ( V_78 , 1 ) = 0x02 ;
V_247 = F_42 ( V_78 , 1 ) ;
* V_247 = 0 ;
memcpy ( F_42 ( V_78 , V_250 ) , V_249 , V_250 ) ;
* V_247 |= 1 ;
if ( V_235 && V_235 -> V_149 )
memcpy ( F_42 ( V_78 , V_248 ) , V_235 -> V_142 ,
V_235 -> V_149 ) ;
else
memcpy ( F_42 ( V_78 , V_248 ) , V_186 ,
V_248 ) ;
* V_247 |= 2 ;
if ( V_187 != NULL && V_190 > 0 ) {
memcpy ( F_42 ( V_78 , V_190 ) , V_187 , V_190 ) ;
* V_247 |= 4 ;
} else {
* V_247 = 0 ;
}
V_106 = F_129 ( sizeof( * V_106 ) , V_74 ) ;
if ( ! V_106 ) {
F_44 ( V_78 ) ;
return - V_93 ;
}
* V_106 = ! V_199 ;
F_130 ( V_20 -> V_176 , 0 ) ;
V_63 = F_57 ( V_20 , V_251 , V_78 ,
F_126 , V_106 ) ;
if ( V_63 < 0 ) {
F_44 ( V_78 ) ;
F_48 ( V_106 ) ;
}
return V_63 ;
}
static int F_131 ( struct V_176 * V_176 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
F_91 ( V_20 ) ;
if ( V_20 -> V_195 || V_20 -> V_225 )
F_71 ( V_20 , V_74 ) ;
V_20 -> V_225 = 0 ;
V_20 -> V_195 = 0 ;
F_125 ( & V_20 -> V_238 ) ;
return 0 ;
}
static struct V_70 * F_132 ( struct V_19 * V_20 )
{
struct V_70 * V_78 , * V_252 , * V_253 ;
unsigned int V_193 = 0 , V_254 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_133 ( & V_20 -> V_238 ) )
return NULL ;
if ( F_134 ( & V_20 -> V_238 ) == 1 ) {
V_78 = F_135 ( & V_20 -> V_238 ) ;
goto V_71;
}
F_136 (&dev->resp_q, tmp, t)
V_193 += V_252 -> V_18 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_48 ,
V_67 , V_193 ) ;
V_78 = F_58 ( V_193 , V_74 ) ;
if ( V_78 == NULL )
goto V_71;
F_42 ( V_78 , V_193 ) ;
F_136 (&dev->resp_q, tmp, t) {
memcpy ( V_78 -> V_12 + V_254 , V_252 -> V_12 , V_252 -> V_18 ) ;
V_254 += V_252 -> V_18 ;
}
V_71:
F_125 ( & V_20 -> V_238 ) ;
return V_78 ;
}
static int F_137 ( struct V_19 * V_20 , void * V_104 ,
struct V_70 * V_87 )
{
struct V_255 * V_106 = V_104 ;
struct V_70 * V_78 ;
int V_63 = 0 ;
T_1 V_47 , V_256 , V_257 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_98 ( V_87 ) ) {
V_63 = F_99 ( V_87 ) ;
goto V_258;
}
V_47 = V_87 -> V_12 [ 0 ] ;
V_256 = V_47 & V_232 ;
V_257 = V_47 & V_259 ;
F_46 ( V_87 , sizeof( V_47 ) ) ;
if ( V_256 != V_233 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_49 , V_256 ) ;
V_63 = - V_58 ;
goto error;
}
F_138 ( & V_20 -> V_238 , V_87 ) ;
if ( V_257 ) {
V_20 -> V_260 = V_106 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_261 ) ;
return - V_102 ;
}
if ( F_134 ( & V_20 -> V_262 ) > 0 ) {
V_20 -> V_263 = V_106 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_264 ) ;
return - V_102 ;
}
V_78 = F_132 ( V_20 ) ;
if ( ! V_78 )
goto error;
V_106 -> V_265 ( V_106 -> V_266 , V_78 , 0 ) ;
F_48 ( V_106 ) ;
return 0 ;
error:
F_44 ( V_87 ) ;
V_258:
F_125 ( & V_20 -> V_238 ) ;
V_106 -> V_265 ( V_106 -> V_266 , NULL , V_63 ) ;
F_48 ( V_106 ) ;
return V_63 ;
}
static int F_139 ( struct V_19 * V_20 , struct V_70 * V_78 )
{
struct V_70 * V_267 ;
int V_268 ;
do {
if ( V_78 -> V_18 > V_269 )
V_268 = V_269 ;
else
V_268 = V_78 -> V_18 ;
V_267 = F_73 ( V_20 , V_268 ) ;
if ( ! V_267 ) {
F_125 ( & V_20 -> V_262 ) ;
break;
}
F_74 ( V_267 , 1 ) ;
if ( V_268 == V_269 )
* F_41 ( V_267 , sizeof( T_1 ) ) = ( V_259 | 1 ) ;
else
* F_41 ( V_267 , sizeof( T_1 ) ) = 1 ;
memcpy ( F_42 ( V_267 , V_268 ) , V_78 -> V_12 , V_268 ) ;
F_46 ( V_78 , V_268 ) ;
F_138 ( & V_20 -> V_262 , V_267 ) ;
} while ( V_78 -> V_18 > 0 );
F_44 ( V_78 ) ;
return F_134 ( & V_20 -> V_262 ) ;
}
static int F_140 ( struct V_176 * V_176 ,
struct V_119 * V_235 , struct V_70 * V_78 ,
T_7 V_265 , void * V_266 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
struct V_255 * V_106 = NULL ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( ! V_20 -> V_225 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_50 ) ;
V_63 = - V_202 ;
goto error;
}
V_106 = F_129 ( sizeof( * V_106 ) , V_74 ) ;
if ( ! V_106 ) {
V_63 = - V_93 ;
goto error;
}
V_106 -> V_265 = V_265 ;
V_106 -> V_266 = V_266 ;
switch ( V_20 -> V_107 ) {
case V_270 :
if ( V_20 -> V_225 == V_271 ) {
V_63 = F_55 ( V_20 , V_272 ,
V_78 ,
F_137 ,
V_106 ) ;
break;
}
default:
if ( V_78 -> V_18 > V_273 ) {
V_63 = F_139 ( V_20 , V_78 ) ;
if ( V_63 <= 0 )
goto error;
V_78 = F_135 ( & V_20 -> V_262 ) ;
if ( ! V_78 ) {
V_63 = - V_58 ;
goto error;
}
} else {
* F_41 ( V_78 , sizeof( T_1 ) ) = 1 ;
}
V_63 = F_55 ( V_20 , V_274 ,
V_78 , F_137 ,
V_106 ) ;
break;
}
if ( V_63 < 0 )
goto error;
return 0 ;
error:
F_48 ( V_106 ) ;
F_44 ( V_78 ) ;
return V_63 ;
}
static int F_141 ( struct V_19 * V_20 , void * V_106 ,
struct V_70 * V_87 )
{
T_1 V_47 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
V_47 = V_87 -> V_12 [ 0 ] ;
F_44 ( V_87 ) ;
if ( V_47 != 0 ) {
F_100 ( V_20 -> V_176 ) ;
V_20 -> V_195 = 0 ;
return 0 ;
}
F_32 ( V_20 -> V_59 , & V_20 -> V_196 ) ;
return 0 ;
}
static int F_142 ( struct V_176 * V_176 , struct V_70 * V_78 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
if ( V_78 -> V_18 > V_273 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_51 ,
V_273 ) ;
return - V_275 ;
}
V_63 = F_55 ( V_20 , V_276 , V_78 ,
F_141 , NULL ) ;
if ( V_63 < 0 )
F_44 ( V_78 ) ;
return V_63 ;
}
static void F_143 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_261 ) ;
struct V_70 * V_78 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_73 ( V_20 , V_277 ) ;
if ( ! V_78 )
goto error;
switch ( V_20 -> V_107 ) {
case V_270 :
if ( V_20 -> V_225 == V_271 ) {
V_63 = F_59 ( V_20 ,
V_272 ,
V_78 ,
F_137 ,
V_20 -> V_260 ) ;
break;
}
default:
* F_42 ( V_78 , sizeof( T_1 ) ) = 1 ;
V_63 = F_59 ( V_20 ,
V_274 ,
V_78 ,
F_137 ,
V_20 -> V_260 ) ;
break;
}
if ( V_63 == 0 )
return;
F_30 ( & V_20 -> V_50 -> V_20 ,
L_52 , V_63 ) ;
F_44 ( V_78 ) ;
F_48 ( V_20 -> V_260 ) ;
error:
F_37 ( V_20 , V_74 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static void F_144 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_264 ) ;
struct V_70 * V_78 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_135 ( & V_20 -> V_262 ) ;
if ( V_78 == NULL ) {
F_145 ( & V_20 -> V_262 ) ;
goto error;
}
switch ( V_20 -> V_107 ) {
case V_270 :
if ( V_20 -> V_225 != V_271 ) {
V_63 = - V_58 ;
break;
}
V_63 = F_59 ( V_20 , V_272 ,
V_78 ,
F_137 ,
V_20 -> V_263 ) ;
break;
default:
V_63 = F_59 ( V_20 , V_274 ,
V_78 ,
F_137 ,
V_20 -> V_263 ) ;
break;
}
if ( V_63 == 0 )
return;
F_30 ( & V_20 -> V_50 -> V_20 ,
L_52 , V_63 ) ;
F_44 ( V_78 ) ;
F_48 ( V_20 -> V_263 ) ;
error:
F_37 ( V_20 , V_74 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static int F_146 ( struct V_19 * V_20 , T_1 V_278 , T_1 * V_279 ,
T_1 V_280 )
{
struct V_70 * V_78 ;
struct V_70 * V_87 ;
int V_193 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_193 = sizeof( V_278 ) + V_280 ;
V_78 = F_73 ( V_20 , V_193 ) ;
if ( ! V_78 )
return - V_93 ;
* F_42 ( V_78 , sizeof( V_278 ) ) = V_278 ;
memcpy ( F_42 ( V_78 , V_280 ) , V_279 , V_280 ) ;
V_87 = F_67 ( V_20 , V_214 , V_78 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
F_44 ( V_87 ) ;
return 0 ;
}
static int F_147 ( struct V_19 * V_20 ,
struct V_281 * V_282 )
{
struct V_70 * V_78 ;
struct V_70 * V_87 ;
V_78 = F_73 ( V_20 , 0 ) ;
if ( ! V_78 )
return - V_93 ;
V_87 = F_67 ( V_20 , V_283 , V_78 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
V_282 -> V_284 = V_87 -> V_12 [ 0 ] ;
V_282 -> V_285 = V_87 -> V_12 [ 1 ] ;
V_282 -> V_286 = V_87 -> V_12 [ 2 ] ;
V_282 -> V_287 = V_87 -> V_12 [ 3 ] ;
F_44 ( V_87 ) ;
return 0 ;
}
static int F_148 ( struct V_19 * V_20 )
{
struct V_70 * V_78 ;
struct V_70 * V_87 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
V_78 = F_73 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_78 )
return - V_93 ;
* F_42 ( V_78 , sizeof( T_1 ) ) = 0x1 ;
V_87 = F_67 ( V_20 , 0x18 , V_78 ) ;
if ( F_98 ( V_87 ) )
return F_99 ( V_87 ) ;
F_44 ( V_87 ) ;
return 0 ;
}
static void F_149 ( struct V_43 * V_43 )
{
struct V_288 * V_106 = V_43 -> V_44 ;
F_29 ( & V_43 -> V_20 -> V_20 , L_10 , V_67 ) ;
F_31 ( L_53 , V_55 , 16 , 1 ,
V_43 -> V_54 , V_43 -> V_69 ,
false ) ;
V_106 -> V_63 = V_43 -> V_47 ;
V_62 ( & V_106 -> V_90 ) ;
}
static int F_150 ( struct V_19 * V_20 )
{
T_1 V_41 [ 10 ] = { V_289 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 } ;
T_1 V_290 [ 255 ] ;
int V_63 ;
void * V_291 ;
struct V_288 V_106 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_10 , V_67 ) ;
F_68 ( & V_106 . V_90 ) ;
V_291 = V_20 -> V_53 -> V_44 ;
V_20 -> V_53 -> V_54 = V_290 ;
V_20 -> V_53 -> V_69 = 255 ;
V_20 -> V_53 -> V_62 = F_149 ;
V_20 -> V_53 -> V_44 = & V_106 ;
V_20 -> V_68 -> V_54 = V_41 ;
V_20 -> V_68 -> V_69 = sizeof( V_41 ) ;
F_31 ( L_54 , V_55 , 16 , 1 ,
V_41 , sizeof( V_41 ) , false ) ;
V_63 = F_34 ( V_20 -> V_68 , V_74 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_55 , V_63 ) ;
return V_63 ;
}
V_63 = F_34 ( V_20 -> V_53 , V_74 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_56 ,
V_63 ) ;
return V_63 ;
}
F_69 ( & V_106 . V_90 ) ;
V_20 -> V_53 -> V_44 = V_291 ;
return V_106 . V_63 ;
}
static int F_130 ( struct V_176 * V_176 , T_1 V_292 )
{
struct V_19 * V_20 = F_117 ( V_176 ) ;
T_1 V_293 = ! ! V_292 ;
int V_63 ;
V_293 |= V_213 ;
V_63 = F_146 ( V_20 , V_212 ,
( T_1 * ) & V_293 , 1 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_57 ) ;
return V_63 ;
}
return V_63 ;
}
int F_151 ( struct V_176 * V_176 )
{
return F_130 ( V_176 , 1 ) ;
}
int F_152 ( struct V_176 * V_176 )
{
return F_130 ( V_176 , 0 ) ;
}
static int F_153 ( struct V_19 * V_20 )
{
struct V_294 V_295 ;
struct V_296 V_297 ;
T_1 V_298 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_63 ;
switch ( V_20 -> V_107 ) {
case V_299 :
case V_270 :
case V_108 :
V_295 . V_300 = 0x2 ;
V_295 . V_301 = 0x1 ;
V_295 . V_302 =
V_303 ;
V_297 . V_304 = V_305 ;
V_297 . V_306 = V_305 ;
V_297 . V_307 = V_308 ;
break;
default:
F_30 ( & V_20 -> V_50 -> V_20 , L_58 ,
V_20 -> V_107 ) ;
return - V_202 ;
}
V_63 = F_146 ( V_20 , V_309 ,
( T_1 * ) & V_295 , sizeof( V_295 ) ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_59 ) ;
return V_63 ;
}
V_63 = F_146 ( V_20 , V_310 ,
( T_1 * ) & V_297 , sizeof( V_297 ) ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_60 ) ;
return V_63 ;
}
switch ( V_20 -> V_107 ) {
case V_299 :
break;
case V_270 :
F_148 ( V_20 ) ;
V_63 = F_146 ( V_20 , V_311 ,
V_298 , 3 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_61 ) ;
return V_63 ;
}
F_148 ( V_20 ) ;
break;
}
return 0 ;
}
static int F_154 ( struct V_312 * V_50 ,
const struct V_313 * V_314 )
{
struct V_281 V_315 ;
struct V_19 * V_20 ;
struct V_316 * V_317 ;
struct V_318 * V_319 ;
int V_320 = 0 ;
int V_321 = 0 ;
int V_63 = - V_93 ;
int V_25 ;
T_5 V_322 ;
V_20 = F_50 ( sizeof( * V_20 ) , V_74 ) ;
if ( ! V_20 )
return - V_93 ;
V_20 -> V_323 = F_155 ( F_156 ( V_50 ) ) ;
V_20 -> V_50 = V_50 ;
F_157 ( & V_20 -> V_94 ) ;
V_317 = V_50 -> V_324 ;
for ( V_25 = 0 ; V_25 < V_317 -> V_325 . V_326 ; ++ V_25 ) {
V_319 = & V_317 -> V_319 [ V_25 ] . V_325 ;
if ( ! V_320 && F_158 ( V_319 ) )
V_320 = V_319 -> V_327 ;
if ( ! V_321 && F_159 ( V_319 ) )
V_321 = V_319 -> V_327 ;
}
if ( ! V_320 || ! V_321 ) {
F_30 ( & V_50 -> V_20 ,
L_62 ) ;
V_63 = - V_328 ;
goto error;
}
V_20 -> V_53 = F_160 ( 0 , V_74 ) ;
V_20 -> V_68 = F_160 ( 0 , V_74 ) ;
if ( ! V_20 -> V_53 || ! V_20 -> V_68 )
goto error;
F_161 ( V_20 -> V_53 , V_20 -> V_323 ,
F_162 ( V_20 -> V_323 , V_320 ) ,
NULL , 0 , NULL , V_20 ) ;
F_161 ( V_20 -> V_68 , V_20 -> V_323 ,
F_163 ( V_20 -> V_323 , V_321 ) ,
NULL , 0 , F_70 , V_20 ) ;
F_164 ( & V_20 -> V_103 , F_62 ) ;
F_164 ( & V_20 -> V_60 , F_60 ) ;
F_164 ( & V_20 -> V_261 , F_143 ) ;
F_164 ( & V_20 -> V_264 , F_144 ) ;
F_164 ( & V_20 -> V_196 , F_102 ) ;
F_165 ( & V_20 -> V_209 , F_114 ) ;
F_164 ( & V_20 -> V_211 , F_109 ) ;
V_20 -> V_59 = F_166 ( L_63 , 0 ) ;
if ( V_20 -> V_59 == NULL )
goto error;
F_167 ( & V_20 -> V_217 ) ;
V_20 -> V_217 . V_12 = ( unsigned long ) V_20 ;
V_20 -> V_217 . V_329 = F_105 ;
F_145 ( & V_20 -> V_238 ) ;
F_145 ( & V_20 -> V_262 ) ;
F_52 ( & V_20 -> V_98 ) ;
F_168 ( V_50 , V_20 ) ;
V_20 -> V_33 = & V_330 ;
V_20 -> V_75 = V_77 ;
V_20 -> V_107 = V_314 -> V_331 ;
switch ( V_20 -> V_107 ) {
case V_299 :
V_322 = V_332 ;
break;
case V_270 :
V_322 = V_333 ;
break;
case V_108 :
V_322 = V_333 ;
V_20 -> V_33 = & V_334 ;
V_20 -> V_75 = V_76 ,
V_63 = F_150 ( V_20 ) ;
if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_64 ,
V_63 ) ;
goto V_335;
}
break;
default:
F_30 ( & V_20 -> V_50 -> V_20 , L_58 ,
V_20 -> V_107 ) ;
V_63 = - V_202 ;
goto V_335;
}
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
V_63 = F_147 ( V_20 , & V_315 ) ;
if ( V_63 < 0 )
goto V_335;
F_169 ( & V_20 -> V_50 -> V_20 ,
L_65 ,
V_315 . V_284 , V_315 . V_285 , V_315 . V_286 ) ;
V_20 -> V_176 = F_170 ( & V_336 , V_322 ,
V_20 -> V_33 -> V_81 +
V_277 ,
V_20 -> V_33 -> V_82 ) ;
if ( ! V_20 -> V_176 ) {
V_63 = - V_93 ;
goto V_335;
}
F_171 ( V_20 -> V_176 , & V_50 -> V_20 ) ;
F_172 ( V_20 -> V_176 , V_20 ) ;
V_63 = F_173 ( V_20 -> V_176 ) ;
if ( V_63 )
goto V_337;
V_63 = F_153 ( V_20 ) ;
if ( V_63 )
goto V_338;
return 0 ;
V_338:
F_174 ( V_20 -> V_176 ) ;
V_337:
F_175 ( V_20 -> V_176 ) ;
V_335:
F_176 ( V_20 -> V_59 ) ;
error:
F_177 ( V_20 -> V_53 ) ;
F_177 ( V_20 -> V_68 ) ;
F_178 ( V_20 -> V_323 ) ;
F_48 ( V_20 ) ;
return V_63 ;
}
static void F_179 ( struct V_312 * V_50 )
{
struct V_19 * V_20 ;
struct V_45 * V_41 , * V_339 ;
V_20 = F_180 ( V_50 ) ;
F_168 ( V_50 , NULL ) ;
F_174 ( V_20 -> V_176 ) ;
F_175 ( V_20 -> V_176 ) ;
F_72 ( V_20 -> V_53 ) ;
F_72 ( V_20 -> V_68 ) ;
F_120 ( & V_20 -> V_209 ) ;
F_176 ( V_20 -> V_59 ) ;
F_125 ( & V_20 -> V_238 ) ;
F_111 ( & V_20 -> V_217 ) ;
F_181 (cmd, n, &dev->cmd_queue, queue) {
F_65 ( & V_41 -> V_97 ) ;
F_48 ( V_41 ) ;
}
F_177 ( V_20 -> V_53 ) ;
F_177 ( V_20 -> V_68 ) ;
F_48 ( V_20 ) ;
F_169 ( & V_50 -> V_20 , L_66 ) ;
}
