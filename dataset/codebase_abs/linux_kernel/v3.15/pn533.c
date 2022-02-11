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
if ( ! V_4 -> V_5 . V_7 )
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
V_20 -> V_67 -> V_54 = V_65 ;
V_20 -> V_67 -> V_68 = sizeof( V_65 ) ;
V_63 = F_34 ( V_20 -> V_67 , V_61 ) ;
return V_63 ;
}
static int F_38 ( struct V_19 * V_20 ,
struct V_69 * V_70 ,
struct V_69 * V_71 ,
int V_72 )
{
int V_63 ;
V_20 -> V_67 -> V_54 = V_70 -> V_12 ;
V_20 -> V_67 -> V_68 = V_70 -> V_18 ;
V_20 -> V_53 -> V_54 = V_71 -> V_12 ;
V_20 -> V_53 -> V_68 = V_72 ;
F_31 ( L_10 , V_55 , 16 , 1 ,
V_70 -> V_12 , V_70 -> V_18 , false ) ;
V_63 = F_34 ( V_20 -> V_67 , V_73 ) ;
if ( V_63 )
return V_63 ;
if ( V_20 -> V_74 == V_75 ) {
V_63 = F_33 ( V_20 , V_64 ) ;
if ( V_63 )
goto error;
} else if ( V_20 -> V_74 == V_76 ) {
V_63 = F_36 ( V_20 , V_73 ) ;
if ( V_63 )
goto error;
}
return 0 ;
error:
F_39 ( V_20 -> V_67 ) ;
return V_63 ;
}
static void F_40 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_77 )
{
int V_78 = V_77 -> V_18 ;
struct V_79 * V_33 = V_20 -> V_33 ;
F_41 ( V_77 , V_33 -> V_80 ) ;
F_42 ( V_77 , V_33 -> V_81 ) ;
V_33 -> V_82 ( V_77 -> V_12 , V_2 ) ;
V_33 -> V_83 ( V_77 -> V_12 , V_78 ) ;
V_33 -> V_84 ( V_77 -> V_12 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_45 * V_41 = V_20 -> V_41 ;
int V_47 = V_41 -> V_47 ;
struct V_69 * V_85 = V_41 -> V_85 ;
struct V_69 * V_86 = V_41 -> V_86 ;
int V_63 ;
F_44 ( V_85 ) ;
if ( V_47 < 0 ) {
V_63 = V_41 -> V_87 ( V_20 , V_41 -> V_88 ,
F_45 ( V_47 ) ) ;
F_44 ( V_86 ) ;
goto V_89;
}
F_42 ( V_86 , V_20 -> V_33 -> V_56 ( V_86 -> V_12 ) ) ;
F_46 ( V_86 , V_20 -> V_33 -> V_34 ) ;
F_47 ( V_86 , V_86 -> V_18 - V_20 -> V_33 -> V_90 ) ;
V_63 = V_41 -> V_87 ( V_20 , V_41 -> V_88 , V_86 ) ;
V_89:
F_48 ( V_41 ) ;
V_20 -> V_41 = NULL ;
return V_63 ;
}
static int F_49 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_85 , struct V_69 * V_86 ,
int V_91 ,
T_4 V_87 ,
void * V_88 )
{
struct V_45 * V_41 ;
int V_63 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_11 , V_2 ) ;
V_41 = F_50 ( sizeof( * V_41 ) , V_73 ) ;
if ( ! V_41 )
return - V_92 ;
V_41 -> V_42 = V_2 ;
V_41 -> V_85 = V_85 ;
V_41 -> V_86 = V_86 ;
V_41 -> V_91 = V_91 ;
V_41 -> V_87 = V_87 ;
V_41 -> V_88 = V_88 ;
F_40 ( V_20 , V_2 , V_85 ) ;
F_51 ( & V_20 -> V_93 ) ;
if ( ! V_20 -> V_94 ) {
V_63 = F_38 ( V_20 , V_85 , V_86 , V_91 ) ;
if ( V_63 )
goto error;
V_20 -> V_94 = 1 ;
V_20 -> V_41 = V_41 ;
goto V_95;
}
F_29 ( & V_20 -> V_50 -> V_20 , L_12 ,
V_96 , V_2 ) ;
F_52 ( & V_41 -> V_97 ) ;
F_53 ( & V_41 -> V_97 , & V_20 -> V_98 ) ;
goto V_95;
error:
F_48 ( V_41 ) ;
V_95:
F_54 ( & V_20 -> V_93 ) ;
return V_63 ;
}
static int F_55 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_85 ,
T_4 V_87 ,
void * V_88 )
{
struct V_69 * V_86 ;
int V_63 ;
int V_91 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_90 ;
V_86 = F_56 ( V_91 , V_73 ) ;
if ( ! V_86 )
return - V_92 ;
V_63 = F_49 ( V_20 , V_2 , V_85 , V_86 , V_91 , V_87 ,
V_88 ) ;
if ( V_63 )
F_44 ( V_86 ) ;
return V_63 ;
}
static int F_57 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_85 ,
T_4 V_87 ,
void * V_88 )
{
struct V_69 * V_86 ;
int V_63 ;
int V_91 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_90 ;
V_86 = F_58 ( V_91 , V_73 ) ;
if ( ! V_86 )
return - V_92 ;
V_63 = F_49 ( V_20 , V_2 , V_85 , V_86 , V_91 , V_87 ,
V_88 ) ;
if ( V_63 )
F_44 ( V_86 ) ;
return V_63 ;
}
static int F_59 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_85 ,
T_4 V_87 ,
void * V_88 )
{
struct V_69 * V_86 ;
struct V_45 * V_41 ;
int V_63 ;
int V_91 = V_20 -> V_33 -> V_34 +
V_20 -> V_33 -> V_99 +
V_20 -> V_33 -> V_90 ;
V_86 = F_58 ( V_91 , V_73 ) ;
if ( ! V_86 )
return - V_92 ;
V_41 = F_50 ( sizeof( * V_41 ) , V_73 ) ;
if ( ! V_41 ) {
F_44 ( V_86 ) ;
return - V_92 ;
}
V_41 -> V_42 = V_2 ;
V_41 -> V_85 = V_85 ;
V_41 -> V_86 = V_86 ;
V_41 -> V_91 = V_91 ;
V_41 -> V_87 = V_87 ;
V_41 -> V_88 = V_88 ;
F_40 ( V_20 , V_2 , V_85 ) ;
V_63 = F_38 ( V_20 , V_85 , V_86 , V_91 ) ;
if ( V_63 < 0 ) {
F_44 ( V_86 ) ;
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
F_51 ( & V_20 -> V_93 ) ;
if ( F_63 ( & V_20 -> V_98 ) ) {
V_20 -> V_94 = 0 ;
F_54 ( & V_20 -> V_93 ) ;
return;
}
V_41 = F_64 ( & V_20 -> V_98 , struct V_45 , V_97 ) ;
F_65 ( & V_41 -> V_97 ) ;
F_54 ( & V_20 -> V_93 ) ;
V_63 = F_38 ( V_20 , V_41 -> V_85 , V_41 -> V_86 , V_41 -> V_91 ) ;
if ( V_63 < 0 ) {
F_44 ( V_41 -> V_85 ) ;
F_44 ( V_41 -> V_86 ) ;
F_48 ( V_41 ) ;
return;
}
V_20 -> V_41 = V_41 ;
}
static int F_66 ( struct V_19 * V_20 , void * V_104 ,
struct V_69 * V_86 )
{
struct V_105 * V_106 = V_104 ;
V_106 -> V_86 = V_86 ;
V_62 ( & V_106 -> V_89 ) ;
return 0 ;
}
static struct V_69 * F_67 ( struct V_19 * V_20 , T_1 V_2 ,
struct V_69 * V_85 )
{
int V_63 ;
struct V_105 V_106 ;
F_68 ( & V_106 . V_89 ) ;
V_63 = F_57 ( V_20 , V_2 , V_85 ,
F_66 , & V_106 ) ;
if ( V_63 ) {
F_44 ( V_85 ) ;
return F_45 ( V_63 ) ;
}
F_69 ( & V_106 . V_89 ) ;
return V_106 . V_86 ;
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
F_30 ( & V_20 -> V_50 -> V_20 , L_2 ,
V_43 -> V_47 ) ;
}
}
static void F_71 ( struct V_19 * V_20 , T_3 V_61 )
{
if ( V_20 -> V_107 == V_108 )
return;
F_37 ( V_20 , V_61 ) ;
F_72 ( V_20 -> V_53 ) ;
}
static struct V_69 * F_73 ( struct V_19 * V_20 , unsigned int V_109 )
{
struct V_69 * V_77 ;
V_77 = F_58 ( V_20 -> V_33 -> V_80 +
V_109 +
V_20 -> V_33 -> V_81 , V_73 ) ;
if ( V_77 )
F_74 ( V_77 , V_20 -> V_33 -> V_80 ) ;
return V_77 ;
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
F_29 ( & V_20 -> V_50 -> V_20 , L_13 ,
V_96 , V_20 -> V_167 ) ;
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
L_14 ) ;
return - V_124 ;
}
if ( V_63 )
return V_63 ;
if ( ! ( V_120 . V_126 & V_20 -> V_173 ) ) {
F_29 ( & V_20 -> V_50 -> V_20 ,
L_15 ) ;
return - V_174 ;
}
F_29 ( & V_20 -> V_50 -> V_20 ,
L_16 ,
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
static int F_94 ( struct V_19 * V_20 , struct V_69 * V_86 )
{
T_1 V_185 , V_164 , * V_165 ;
int V_63 , V_166 ;
V_20 -> V_186 = 1 ;
V_185 = V_86 -> V_12 [ 0 ] ;
V_164 = V_86 -> V_12 [ 1 ] ;
V_165 = & V_86 -> V_12 [ 2 ] ;
V_166 = V_86 -> V_18 - 2 ;
if ( V_185 ) {
V_63 = F_88 ( V_20 , V_164 , V_165 , V_166 ) ;
if ( V_63 == 0 ) {
F_91 ( V_20 ) ;
return 0 ;
}
}
return - V_174 ;
}
static struct V_69 * F_95 ( struct V_19 * V_20 )
{
struct V_69 * V_77 ;
T_1 * V_138 , * V_187 , * V_188 ;
T_1 * V_189 = V_20 -> V_188 ;
T_6 V_190 = V_20 -> V_191 ;
T_1 V_192 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_193 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
unsigned int V_194 = 36 +
V_190 +
1 ;
V_77 = F_73 ( V_20 , V_194 ) ;
if ( ! V_77 )
return NULL ;
* F_42 ( V_77 , 1 ) = V_195 ;
memcpy ( F_42 ( V_77 , 6 ) , V_193 , 6 ) ;
V_138 = F_42 ( V_77 , 18 ) ;
memcpy ( V_138 , V_192 , 18 ) ;
F_96 ( V_138 + 2 , 6 ) ;
V_187 = F_42 ( V_77 , 10 ) ;
memset ( V_187 , 0 , 10 ) ;
memcpy ( V_187 , V_138 , 8 ) ;
* F_42 ( V_77 , 1 ) = V_190 ;
V_188 = F_42 ( V_77 , V_190 ) ;
memcpy ( V_188 , V_189 , V_190 ) ;
* F_42 ( V_77 , 1 ) = 0 ;
return V_77 ;
}
static int F_97 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
struct V_69 * V_77 ;
T_1 V_47 , V_196 , V_197 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_98 ( V_86 ) ) {
F_99 ( & V_20 -> V_198 ) ;
return F_100 ( V_86 ) ;
}
V_47 = V_86 -> V_12 [ 0 ] ;
V_196 = V_47 & V_199 ;
V_197 = V_47 & V_200 ;
F_46 ( V_86 , sizeof( V_47 ) ) ;
if ( V_196 != V_201 ) {
V_63 = - V_58 ;
goto error;
}
F_101 ( & V_20 -> V_198 , V_86 ) ;
if ( V_197 ) {
F_32 ( V_20 -> V_59 , & V_20 -> V_202 ) ;
return - V_102 ;
}
V_77 = F_102 ( V_20 ) ;
if ( ! V_77 ) {
V_63 = - V_58 ;
goto error;
}
return F_103 ( V_20 -> V_176 , V_77 ) ;
error:
F_104 ( V_20 -> V_176 ) ;
V_20 -> V_203 = 0 ;
F_99 ( & V_20 -> V_198 ) ;
F_44 ( V_86 ) ;
return V_63 ;
}
static void F_105 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_202 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , 0 ) ;
if ( ! V_77 )
return;
V_63 = F_59 ( V_20 ,
V_204 ,
V_77 ,
F_97 ,
NULL ) ;
if ( V_63 < 0 )
F_44 ( V_77 ) ;
return;
}
static void F_106 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_205 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_107 ( & V_20 -> V_206 ) ;
if ( V_77 == NULL ) {
F_108 ( & V_20 -> V_206 ) ;
goto error;
}
if ( F_109 ( & V_20 -> V_206 ) == 0 ) {
V_63 = F_59 ( V_20 , V_207 ,
V_77 , V_208 , NULL ) ;
} else
V_63 = F_59 ( V_20 ,
V_209 ,
V_77 , V_208 , NULL ) ;
if ( V_63 == 0 )
return;
F_110 ( & V_20 -> V_50 -> V_20 ,
L_18 , V_63 ) ;
F_44 ( V_77 ) ;
error:
F_37 ( V_20 , V_73 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static void F_111 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_210 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , 0 ) ;
if ( ! V_77 )
return;
V_63 = F_55 ( V_20 , V_204 , V_77 ,
F_97 , NULL ) ;
if ( V_63 < 0 )
F_44 ( V_77 ) ;
return;
}
static int F_112 ( struct V_19 * V_20 , struct V_69 * V_86 )
{
T_1 V_211 , * V_41 , V_212 = V_213 , * V_188 ;
T_6 V_191 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( V_86 -> V_18 < V_214 + 1 )
return - V_215 ;
V_211 = V_86 -> V_12 [ 0 ] ;
V_41 = & V_86 -> V_12 [ 1 ] ;
F_29 ( & V_20 -> V_50 -> V_20 , L_19 ,
V_211 , V_86 -> V_18 ) ;
if ( ( V_211 & V_216 ) ==
V_217 )
V_212 = V_218 ;
if ( ( V_211 & V_219 ) == 0 )
return - V_220 ;
V_188 = V_41 + V_214 ;
V_191 = V_86 -> V_18 - ( V_214 + 1 ) ;
V_63 = F_113 ( V_20 -> V_176 , V_131 ,
V_212 , V_188 , V_191 ) ;
if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_20 ) ;
return V_63 ;
}
V_20 -> V_203 = 1 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_210 ) ;
return 0 ;
}
static void F_114 ( unsigned long V_12 )
{
struct V_19 * V_20 = (struct V_19 * ) V_12 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_21 ) ;
V_20 -> V_221 = 1 ;
F_90 ( V_20 ) ;
F_115 ( V_20 -> V_59 , & V_20 -> V_222 ,
F_116 ( V_223 ) ) ;
}
static int F_117 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
int V_63 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_98 ( V_86 ) ) {
V_63 = F_100 ( V_86 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_22 , V_63 ) ;
return V_63 ;
}
F_115 ( V_20 -> V_59 , & V_20 -> V_222 ,
F_116 ( V_223 ) ) ;
F_44 ( V_86 ) ;
return V_63 ;
}
static void F_118 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_224 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , 2 ) ;
if ( ! V_77 )
return;
* F_42 ( V_77 , 1 ) = V_225 ;
* F_42 ( V_77 , 1 ) = V_226 ;
V_63 = F_57 ( V_20 , V_227 , V_77 ,
F_117 , NULL ) ;
if ( V_63 < 0 ) {
F_44 ( V_77 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_23 , V_63 ) ;
}
return;
}
static int F_119 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
struct V_228 * V_229 ;
struct V_119 V_119 ;
T_1 V_230 ;
int V_63 ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
V_229 = (struct V_228 * ) V_86 -> V_12 ;
V_63 = V_229 -> V_47 & V_199 ;
if ( V_63 != V_201 ) {
F_32 ( V_20 -> V_59 , & V_20 -> V_224 ) ;
F_44 ( V_86 ) ;
return 0 ;
}
F_29 ( & V_20 -> V_50 -> V_20 , L_24 ) ;
V_119 . V_126 = V_131 ;
V_119 . V_133 = 10 ;
memcpy ( V_119 . V_135 , V_229 -> V_231 , V_119 . V_133 ) ;
V_63 = F_89 ( V_20 -> V_176 , & V_119 , 1 ) ;
if ( V_63 )
goto error;
V_20 -> V_175 = 0 ;
V_20 -> V_232 = V_233 ;
V_230 = V_86 -> V_18 - 17 ;
V_63 = F_120 ( V_20 -> V_176 ,
V_229 -> V_234 , V_230 ) ;
if ( ! V_63 ) {
V_63 = F_121 ( V_20 -> V_176 ,
V_20 -> V_176 -> V_235 [ 0 ] . V_236 ,
0 , V_237 ) ;
if ( ! V_63 )
F_91 ( V_20 ) ;
}
error:
F_44 ( V_86 ) ;
return V_63 ;
}
static int F_122 ( struct V_176 * V_176 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
struct V_69 * V_77 ;
int V_63 , V_194 ;
T_1 * V_238 , V_187 [ V_239 ] ;
T_1 V_240 [ V_241 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_29 ( & V_20 -> V_50 -> V_20 , L_25 , V_96 ) ;
if ( ! V_20 -> V_188 ) {
V_20 -> V_188 = F_124 ( V_176 , & V_20 -> V_191 ) ;
if ( ! V_20 -> V_188 || ! V_20 -> V_191 ) {
V_20 -> V_186 = 0 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_224 ) ;
}
}
V_194 = 3 + V_20 -> V_191 ;
V_194 += V_241 ;
V_194 += V_239 ;
V_187 [ 0 ] = 0x1 ;
V_187 [ 1 ] = 0xfe ;
F_96 ( V_187 + 2 , 6 ) ;
V_77 = F_73 ( V_20 , V_194 ) ;
if ( ! V_77 )
return - V_92 ;
* F_42 ( V_77 , 1 ) = 0x01 ;
* F_42 ( V_77 , 1 ) = 0x02 ;
V_238 = F_42 ( V_77 , 1 ) ;
* V_238 = 0 ;
memcpy ( F_42 ( V_77 , V_241 ) , V_240 , V_241 ) ;
* V_238 |= 1 ;
memcpy ( F_42 ( V_77 , V_239 ) , V_187 ,
V_239 ) ;
* V_238 |= 2 ;
memcpy ( F_42 ( V_77 , V_20 -> V_191 ) , V_20 -> V_188 , V_20 -> V_191 ) ;
* V_238 |= 4 ;
V_63 = F_57 ( V_20 , V_242 , V_77 ,
F_119 , NULL ) ;
if ( V_63 < 0 )
F_44 ( V_77 ) ;
return V_63 ;
}
static int F_125 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
struct V_180 * V_243 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_98 ( V_86 ) ) {
V_63 = F_100 ( V_86 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_26 ,
V_96 , V_63 ) ;
if ( V_63 == - V_49 ) {
if ( V_20 -> V_177 != 0 )
return V_63 ;
else
goto V_244;
} else if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_27 , V_63 ) ;
goto V_244;
}
}
V_243 = V_20 -> V_179 [ V_20 -> V_167 ] ;
if ( V_243 -> V_18 == 0 ) {
F_126 ( & V_20 -> V_245 ) ;
V_63 = F_112 ( V_20 , V_86 ) ;
goto V_89;
}
V_63 = F_94 ( V_20 , V_86 ) ;
if ( ! V_63 )
goto V_89;
if ( ! V_20 -> V_177 ) {
F_29 ( & V_20 -> V_50 -> V_20 , L_28 ) ;
goto V_89;
}
F_90 ( V_20 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_224 ) ;
V_89:
F_44 ( V_86 ) ;
return V_63 ;
V_244:
F_30 ( & V_20 -> V_50 -> V_20 , L_29 ) ;
F_91 ( V_20 ) ;
V_20 -> V_173 = 0 ;
return V_63 ;
}
static struct V_69 * F_127 ( struct V_19 * V_20 ,
struct V_180 * V_246 )
{
struct V_69 * V_77 ;
V_77 = F_73 ( V_20 , V_246 -> V_18 ) ;
if ( ! V_77 )
return NULL ;
memcpy ( F_42 ( V_77 , V_246 -> V_18 ) , & V_246 -> V_12 , V_246 -> V_18 ) ;
return V_77 ;
}
static int F_128 ( struct V_19 * V_20 )
{
struct V_180 * V_246 ;
struct V_69 * V_77 ;
int V_63 ;
T_1 V_2 ;
V_246 = V_20 -> V_179 [ V_20 -> V_167 ] ;
F_29 ( & V_20 -> V_50 -> V_20 , L_30 ,
V_96 , V_246 -> V_18 ) ;
if ( V_20 -> V_186 ) {
V_20 -> V_186 = 0 ;
return F_122 ( V_20 -> V_176 ) ;
}
if ( V_246 -> V_18 == 0 ) {
V_2 = V_247 ;
V_77 = F_95 ( V_20 ) ;
} else {
V_2 = V_248 ;
V_77 = F_127 ( V_20 , V_246 ) ;
}
if ( ! V_77 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_31 ) ;
return - V_92 ;
}
V_63 = F_57 ( V_20 , V_2 , V_77 , F_125 ,
NULL ) ;
if ( V_63 < 0 ) {
F_44 ( V_77 ) ;
F_30 ( & V_20 -> V_50 -> V_20 , L_32 , V_63 ) ;
}
return V_63 ;
}
static void F_129 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_222 . V_101 ) ;
struct V_180 * V_243 ;
int V_63 ;
V_243 = V_20 -> V_179 [ V_20 -> V_167 ] ;
F_29 ( & V_20 -> V_50 -> V_20 ,
L_33 ,
V_96 , V_20 -> V_221 , V_243 -> V_18 ) ;
if ( V_20 -> V_221 == 1 ) {
V_20 -> V_221 = 0 ;
F_71 ( V_20 , V_64 ) ;
}
V_63 = F_128 ( V_20 ) ;
if ( V_63 )
return;
if ( V_243 -> V_18 == 0 && V_20 -> V_177 > 1 )
F_130 ( & V_20 -> V_245 , V_249 + V_250 * V_251 ) ;
return;
}
static int F_131 ( struct V_176 * V_176 ,
T_5 V_182 , T_5 V_183 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
struct V_180 * V_243 ;
T_1 V_252 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 ,
L_34 ,
V_96 , V_182 , V_183 ) ;
if ( V_20 -> V_232 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_35 ) ;
return - V_253 ;
}
if ( V_20 -> V_203 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_36 ) ;
return - V_253 ;
}
if ( V_183 ) {
V_20 -> V_188 = F_124 ( V_176 , & V_20 -> V_191 ) ;
if ( V_20 -> V_188 == NULL )
V_183 = 0 ;
}
F_93 ( V_20 , V_182 , V_183 ) ;
V_20 -> V_173 = V_182 ;
V_20 -> V_254 = V_183 ;
F_96 ( & V_252 , sizeof( V_252 ) ) ;
V_252 %= V_20 -> V_177 ;
V_20 -> V_167 = V_252 ;
V_243 = V_20 -> V_179 [ V_20 -> V_167 ] ;
V_63 = F_128 ( V_20 ) ;
if ( ! V_63 && V_243 -> V_18 == 0 && V_20 -> V_177 > 1 )
F_130 ( & V_20 -> V_245 , V_249 + V_250 * V_251 ) ;
return V_63 ;
}
static void F_132 ( struct V_176 * V_176 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
F_126 ( & V_20 -> V_245 ) ;
if ( ! V_20 -> V_177 ) {
F_29 ( & V_20 -> V_50 -> V_20 ,
L_37 ) ;
return;
}
F_71 ( V_20 , V_73 ) ;
F_133 ( & V_20 -> V_222 ) ;
F_91 ( V_20 ) ;
}
static int F_134 ( struct V_19 * V_20 )
{
struct V_255 * V_229 ;
T_2 V_256 ;
int V_63 ;
struct V_69 * V_77 ;
struct V_69 * V_86 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , sizeof( T_1 ) * 2 ) ;
if ( ! V_77 )
return - V_92 ;
* F_42 ( V_77 , sizeof( T_1 ) ) = 1 ;
* F_42 ( V_77 , sizeof( T_1 ) ) = 0 ;
V_86 = F_67 ( V_20 , V_257 , V_77 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
V_229 = (struct V_255 * ) V_86 -> V_12 ;
V_63 = V_229 -> V_47 & V_199 ;
if ( V_63 != V_201 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_38 , V_63 ) ;
F_44 ( V_86 ) ;
return - V_58 ;
}
V_256 = V_86 -> V_18 - 16 ;
V_63 = F_120 ( V_20 -> V_176 , V_229 -> V_234 , V_256 ) ;
F_44 ( V_86 ) ;
return V_63 ;
}
static int F_135 ( struct V_176 * V_176 ,
struct V_119 * V_258 , T_5 V_259 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_39 , V_96 , V_259 ) ;
if ( V_20 -> V_177 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_40 ) ;
return - V_253 ;
}
if ( V_20 -> V_232 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_41 ) ;
return - V_253 ;
}
if ( ! V_20 -> V_175 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_42 ) ;
return - V_215 ;
}
if ( ! ( V_20 -> V_175 & ( 1 << V_259 ) ) ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_43 ,
V_259 ) ;
return - V_215 ;
}
if ( V_259 == V_233 ) {
V_63 = F_134 ( V_20 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_44 , V_63 ) ;
return V_63 ;
}
}
V_20 -> V_232 = V_259 ;
V_20 -> V_175 = 0 ;
return 0 ;
}
static void F_136 ( struct V_176 * V_176 ,
struct V_119 * V_258 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
struct V_69 * V_77 ;
struct V_69 * V_86 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( ! V_20 -> V_232 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_45 ) ;
return;
}
V_20 -> V_232 = 0 ;
F_99 ( & V_20 -> V_198 ) ;
V_77 = F_73 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_77 )
return;
* F_42 ( V_77 , 1 ) = 1 ;
V_86 = F_67 ( V_20 , V_260 , V_77 ) ;
if ( F_98 ( V_86 ) )
return;
V_63 = V_86 -> V_12 [ 0 ] & V_199 ;
if ( V_63 != V_201 )
F_30 ( & V_20 -> V_50 -> V_20 ,
L_46 , V_63 ) ;
F_44 ( V_86 ) ;
return;
}
static int F_137 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
struct V_228 * V_229 ;
T_1 V_230 ;
int V_63 ;
T_1 V_261 = * ( T_1 * ) V_106 ;
F_48 ( V_106 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
if ( V_20 -> V_175 &&
! ( V_20 -> V_175 & ( 1 << V_233 ) ) ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_47 ) ;
V_63 = - V_215 ;
goto error;
}
V_229 = (struct V_228 * ) V_86 -> V_12 ;
V_63 = V_229 -> V_47 & V_199 ;
if ( V_63 != V_201 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_48 , V_63 ) ;
goto error;
}
if ( ! V_20 -> V_175 ) {
struct V_119 V_119 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_49 ) ;
V_119 . V_126 = V_131 ;
V_119 . V_133 = 10 ;
memcpy ( V_119 . V_135 , V_229 -> V_231 , V_119 . V_133 ) ;
V_63 = F_89 ( V_20 -> V_176 , & V_119 , 1 ) ;
if ( V_63 )
goto error;
V_20 -> V_175 = 0 ;
}
V_20 -> V_232 = V_233 ;
V_230 = V_86 -> V_18 - 17 ;
V_63 = F_120 ( V_20 -> V_176 ,
V_229 -> V_234 , V_230 ) ;
if ( V_63 == 0 )
V_63 = F_121 ( V_20 -> V_176 ,
V_20 -> V_176 -> V_235 [ 0 ] . V_236 ,
! V_261 , V_237 ) ;
error:
F_44 ( V_86 ) ;
return V_63 ;
}
static int F_138 ( struct V_176 * V_176 , struct V_119 * V_258 ,
T_1 V_212 , T_1 * V_188 , T_6 V_191 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
struct V_69 * V_77 ;
int V_63 , V_194 ;
T_1 * V_238 , * V_106 , V_187 [ V_239 ] ;
T_1 V_240 [ V_241 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( V_20 -> V_177 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_50 ) ;
return - V_253 ;
}
if ( V_20 -> V_232 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_41 ) ;
return - V_253 ;
}
V_194 = 3 + V_191 ;
V_194 += V_241 ;
V_194 += V_239 ;
if ( V_258 && ! V_258 -> V_149 ) {
V_187 [ 0 ] = 0x1 ;
V_187 [ 1 ] = 0xfe ;
F_96 ( V_187 + 2 , 6 ) ;
}
V_77 = F_73 ( V_20 , V_194 ) ;
if ( ! V_77 )
return - V_92 ;
* F_42 ( V_77 , 1 ) = ! V_212 ;
* F_42 ( V_77 , 1 ) = 0x02 ;
V_238 = F_42 ( V_77 , 1 ) ;
* V_238 = 0 ;
memcpy ( F_42 ( V_77 , V_241 ) , V_240 , V_241 ) ;
* V_238 |= 1 ;
if ( V_258 && V_258 -> V_149 )
memcpy ( F_42 ( V_77 , V_239 ) , V_258 -> V_142 ,
V_258 -> V_149 ) ;
else
memcpy ( F_42 ( V_77 , V_239 ) , V_187 ,
V_239 ) ;
* V_238 |= 2 ;
if ( V_188 != NULL && V_191 > 0 ) {
memcpy ( F_42 ( V_77 , V_191 ) , V_188 , V_191 ) ;
* V_238 |= 4 ;
} else {
* V_238 = 0 ;
}
V_106 = F_139 ( sizeof( * V_106 ) , V_73 ) ;
if ( ! V_106 ) {
F_44 ( V_77 ) ;
return - V_92 ;
}
* V_106 = ! V_212 ;
F_140 ( V_20 -> V_176 , 0 ) ;
V_63 = F_57 ( V_20 , V_242 , V_77 ,
F_137 , V_106 ) ;
if ( V_63 < 0 ) {
F_44 ( V_77 ) ;
F_48 ( V_106 ) ;
}
return V_63 ;
}
static int F_141 ( struct V_176 * V_176 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
F_91 ( V_20 ) ;
if ( V_20 -> V_203 || V_20 -> V_232 )
F_71 ( V_20 , V_73 ) ;
V_20 -> V_232 = 0 ;
V_20 -> V_203 = 0 ;
F_99 ( & V_20 -> V_198 ) ;
return 0 ;
}
static struct V_69 * F_102 ( struct V_19 * V_20 )
{
struct V_69 * V_77 , * V_262 , * V_263 ;
unsigned int V_194 = 0 , V_264 = 0 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_142 ( & V_20 -> V_198 ) )
return NULL ;
if ( F_109 ( & V_20 -> V_198 ) == 1 ) {
V_77 = F_107 ( & V_20 -> V_198 ) ;
goto V_70;
}
F_143 (&dev->resp_q, tmp, t)
V_194 += V_262 -> V_18 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_51 ,
V_96 , V_194 ) ;
V_77 = F_58 ( V_194 , V_73 ) ;
if ( V_77 == NULL )
goto V_70;
F_42 ( V_77 , V_194 ) ;
F_143 (&dev->resp_q, tmp, t) {
memcpy ( V_77 -> V_12 + V_264 , V_262 -> V_12 , V_262 -> V_18 ) ;
V_264 += V_262 -> V_18 ;
}
V_70:
F_99 ( & V_20 -> V_198 ) ;
return V_77 ;
}
static int F_144 ( struct V_19 * V_20 , void * V_104 ,
struct V_69 * V_86 )
{
struct V_265 * V_106 = V_104 ;
struct V_69 * V_77 ;
int V_63 = 0 ;
T_1 V_47 , V_196 , V_197 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_98 ( V_86 ) ) {
V_63 = F_100 ( V_86 ) ;
goto V_266;
}
V_47 = V_86 -> V_12 [ 0 ] ;
V_196 = V_47 & V_199 ;
V_197 = V_47 & V_200 ;
F_46 ( V_86 , sizeof( V_47 ) ) ;
if ( V_196 != V_201 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_52 , V_196 ) ;
V_63 = - V_58 ;
goto error;
}
F_101 ( & V_20 -> V_198 , V_86 ) ;
if ( V_197 ) {
V_20 -> V_267 = V_106 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_268 ) ;
return - V_102 ;
}
if ( F_109 ( & V_20 -> V_206 ) > 0 ) {
V_20 -> V_269 = V_106 ;
F_32 ( V_20 -> V_59 , & V_20 -> V_270 ) ;
return - V_102 ;
}
V_77 = F_102 ( V_20 ) ;
if ( ! V_77 )
goto error;
V_106 -> V_271 ( V_106 -> V_272 , V_77 , 0 ) ;
F_48 ( V_106 ) ;
return 0 ;
error:
F_44 ( V_86 ) ;
V_266:
F_99 ( & V_20 -> V_198 ) ;
V_106 -> V_271 ( V_106 -> V_272 , NULL , V_63 ) ;
F_48 ( V_106 ) ;
return V_63 ;
}
static int F_145 ( struct V_19 * V_20 , struct V_69 * V_77 )
{
struct V_69 * V_273 ;
int V_274 ;
do {
if ( V_77 -> V_18 > V_275 )
V_274 = V_275 ;
else
V_274 = V_77 -> V_18 ;
V_273 = F_73 ( V_20 , V_274 ) ;
if ( ! V_273 ) {
F_99 ( & V_20 -> V_206 ) ;
break;
}
if ( ! V_20 -> V_203 ) {
F_74 ( V_273 , 1 ) ;
if ( V_274 == V_275 )
* F_41 ( V_273 , sizeof( T_1 ) ) =
( V_200 | 1 ) ;
else
* F_41 ( V_273 , sizeof( T_1 ) ) = 1 ;
}
memcpy ( F_42 ( V_273 , V_274 ) , V_77 -> V_12 , V_274 ) ;
F_46 ( V_77 , V_274 ) ;
F_101 ( & V_20 -> V_206 , V_273 ) ;
} while ( V_77 -> V_18 > 0 );
F_44 ( V_77 ) ;
return F_109 ( & V_20 -> V_206 ) ;
}
static int F_146 ( struct V_176 * V_176 ,
struct V_119 * V_258 , struct V_69 * V_77 ,
T_7 V_271 , void * V_272 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
struct V_265 * V_106 = NULL ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( ! V_20 -> V_232 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_53 ) ;
V_63 = - V_215 ;
goto error;
}
V_106 = F_139 ( sizeof( * V_106 ) , V_73 ) ;
if ( ! V_106 ) {
V_63 = - V_92 ;
goto error;
}
V_106 -> V_271 = V_271 ;
V_106 -> V_272 = V_272 ;
switch ( V_20 -> V_107 ) {
case V_276 :
if ( V_20 -> V_232 == V_277 ) {
V_63 = F_55 ( V_20 , V_278 ,
V_77 ,
F_144 ,
V_106 ) ;
break;
}
default:
if ( V_77 -> V_18 > V_279 ) {
V_63 = F_145 ( V_20 , V_77 ) ;
if ( V_63 <= 0 )
goto error;
V_77 = F_107 ( & V_20 -> V_206 ) ;
if ( ! V_77 ) {
V_63 = - V_58 ;
goto error;
}
} else {
* F_41 ( V_77 , sizeof( T_1 ) ) = 1 ;
}
V_63 = F_55 ( V_20 , V_280 ,
V_77 , F_144 ,
V_106 ) ;
break;
}
if ( V_63 < 0 )
goto error;
return 0 ;
error:
F_48 ( V_106 ) ;
F_44 ( V_77 ) ;
return V_63 ;
}
static int V_208 ( struct V_19 * V_20 , void * V_106 ,
struct V_69 * V_86 )
{
T_1 V_47 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
V_47 = V_86 -> V_12 [ 0 ] ;
if ( F_109 ( & V_20 -> V_206 ) > 0 ) {
F_32 ( V_20 -> V_59 , & V_20 -> V_205 ) ;
return - V_102 ;
}
F_44 ( V_86 ) ;
if ( V_47 != 0 ) {
F_104 ( V_20 -> V_176 ) ;
V_20 -> V_203 = 0 ;
return 0 ;
}
F_32 ( V_20 -> V_59 , & V_20 -> V_210 ) ;
return 0 ;
}
static int F_147 ( struct V_176 * V_176 , struct V_69 * V_77 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
if ( V_77 -> V_18 > V_279 ) {
V_63 = F_145 ( V_20 , V_77 ) ;
if ( V_63 <= 0 )
goto error;
V_77 = F_107 ( & V_20 -> V_206 ) ;
if ( ! V_77 ) {
V_63 = - V_58 ;
goto error;
}
V_63 = F_55 ( V_20 , V_209 , V_77 ,
V_208 , NULL ) ;
} else {
V_63 = F_55 ( V_20 , V_207 , V_77 ,
V_208 , NULL ) ;
}
error:
if ( V_63 < 0 ) {
F_44 ( V_77 ) ;
F_99 ( & V_20 -> V_206 ) ;
}
return V_63 ;
}
static void F_148 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_268 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , V_281 ) ;
if ( ! V_77 )
goto error;
switch ( V_20 -> V_107 ) {
case V_276 :
if ( V_20 -> V_232 == V_277 ) {
V_63 = F_59 ( V_20 ,
V_278 ,
V_77 ,
F_144 ,
V_20 -> V_267 ) ;
break;
}
default:
* F_42 ( V_77 , sizeof( T_1 ) ) = 1 ;
V_63 = F_59 ( V_20 ,
V_280 ,
V_77 ,
F_144 ,
V_20 -> V_267 ) ;
break;
}
if ( V_63 == 0 )
return;
F_30 ( & V_20 -> V_50 -> V_20 ,
L_54 , V_63 ) ;
F_44 ( V_77 ) ;
F_48 ( V_20 -> V_267 ) ;
error:
F_37 ( V_20 , V_73 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static void F_149 ( struct V_100 * V_101 )
{
struct V_19 * V_20 = F_61 ( V_101 , struct V_19 , V_270 ) ;
struct V_69 * V_77 ;
int V_63 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_107 ( & V_20 -> V_206 ) ;
if ( V_77 == NULL ) {
F_108 ( & V_20 -> V_206 ) ;
goto error;
}
switch ( V_20 -> V_107 ) {
case V_276 :
if ( V_20 -> V_232 != V_277 ) {
V_63 = - V_58 ;
break;
}
V_63 = F_59 ( V_20 , V_278 ,
V_77 ,
F_144 ,
V_20 -> V_269 ) ;
break;
default:
V_63 = F_59 ( V_20 , V_280 ,
V_77 ,
F_144 ,
V_20 -> V_269 ) ;
break;
}
if ( V_63 == 0 )
return;
F_30 ( & V_20 -> V_50 -> V_20 ,
L_54 , V_63 ) ;
F_44 ( V_77 ) ;
F_48 ( V_20 -> V_269 ) ;
error:
F_37 ( V_20 , V_73 ) ;
F_32 ( V_20 -> V_59 , & V_20 -> V_103 ) ;
}
static int F_150 ( struct V_19 * V_20 , T_1 V_282 , T_1 * V_283 ,
T_1 V_284 )
{
struct V_69 * V_77 ;
struct V_69 * V_86 ;
int V_194 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_194 = sizeof( V_282 ) + V_284 ;
V_77 = F_73 ( V_20 , V_194 ) ;
if ( ! V_77 )
return - V_92 ;
* F_42 ( V_77 , sizeof( V_282 ) ) = V_282 ;
memcpy ( F_42 ( V_77 , V_284 ) , V_283 , V_284 ) ;
V_86 = F_67 ( V_20 , V_227 , V_77 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
F_44 ( V_86 ) ;
return 0 ;
}
static int F_151 ( struct V_19 * V_20 ,
struct V_285 * V_286 )
{
struct V_69 * V_77 ;
struct V_69 * V_86 ;
V_77 = F_73 ( V_20 , 0 ) ;
if ( ! V_77 )
return - V_92 ;
V_86 = F_67 ( V_20 , V_287 , V_77 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
V_286 -> V_288 = V_86 -> V_12 [ 0 ] ;
V_286 -> V_289 = V_86 -> V_12 [ 1 ] ;
V_286 -> V_290 = V_86 -> V_12 [ 2 ] ;
V_286 -> V_291 = V_86 -> V_12 [ 3 ] ;
F_44 ( V_86 ) ;
return 0 ;
}
static int F_152 ( struct V_19 * V_20 )
{
struct V_69 * V_77 ;
struct V_69 * V_86 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
V_77 = F_73 ( V_20 , sizeof( T_1 ) ) ;
if ( ! V_77 )
return - V_92 ;
* F_42 ( V_77 , sizeof( T_1 ) ) = 0x1 ;
V_86 = F_67 ( V_20 , 0x18 , V_77 ) ;
if ( F_98 ( V_86 ) )
return F_100 ( V_86 ) ;
F_44 ( V_86 ) ;
return 0 ;
}
static void F_153 ( struct V_43 * V_43 )
{
struct V_292 * V_106 = V_43 -> V_44 ;
F_29 ( & V_43 -> V_20 -> V_20 , L_17 , V_96 ) ;
F_31 ( L_55 , V_55 , 16 , 1 ,
V_43 -> V_54 , V_43 -> V_68 ,
false ) ;
V_106 -> V_63 = V_43 -> V_47 ;
V_62 ( & V_106 -> V_89 ) ;
}
static int F_154 ( struct V_19 * V_20 )
{
T_1 V_41 [ 10 ] = { V_293 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 } ;
T_1 V_294 [ 255 ] ;
int V_63 ;
void * V_295 ;
struct V_292 V_106 ;
F_29 ( & V_20 -> V_50 -> V_20 , L_17 , V_96 ) ;
F_68 ( & V_106 . V_89 ) ;
V_295 = V_20 -> V_53 -> V_44 ;
V_20 -> V_53 -> V_54 = V_294 ;
V_20 -> V_53 -> V_68 = 255 ;
V_20 -> V_53 -> V_62 = F_153 ;
V_20 -> V_53 -> V_44 = & V_106 ;
V_20 -> V_67 -> V_54 = V_41 ;
V_20 -> V_67 -> V_68 = sizeof( V_41 ) ;
F_31 ( L_56 , V_55 , 16 , 1 ,
V_41 , sizeof( V_41 ) , false ) ;
V_63 = F_34 ( V_20 -> V_67 , V_73 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_57 , V_63 ) ;
return V_63 ;
}
V_63 = F_34 ( V_20 -> V_53 , V_73 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_58 , V_63 ) ;
return V_63 ;
}
F_69 ( & V_106 . V_89 ) ;
V_20 -> V_53 -> V_44 = V_295 ;
return V_106 . V_63 ;
}
static int F_140 ( struct V_176 * V_176 , T_1 V_296 )
{
struct V_19 * V_20 = F_123 ( V_176 ) ;
T_1 V_297 = ! ! V_296 ;
int V_63 ;
V_297 |= V_226 ;
V_63 = F_150 ( V_20 , V_225 ,
( T_1 * ) & V_297 , 1 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_59 ) ;
return V_63 ;
}
return V_63 ;
}
static int F_155 ( struct V_176 * V_176 )
{
return F_140 ( V_176 , 1 ) ;
}
static int F_156 ( struct V_176 * V_176 )
{
return F_140 ( V_176 , 0 ) ;
}
static int F_157 ( struct V_19 * V_20 )
{
struct V_298 V_299 ;
struct V_300 V_301 ;
T_1 V_302 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_63 ;
switch ( V_20 -> V_107 ) {
case V_303 :
case V_276 :
case V_108 :
V_299 . V_304 = 0x2 ;
V_299 . V_305 = 0x1 ;
V_299 . V_306 =
V_307 ;
V_301 . V_308 = V_309 ;
V_301 . V_310 = V_309 ;
V_301 . V_311 = V_312 ;
break;
default:
F_30 ( & V_20 -> V_50 -> V_20 , L_60 ,
V_20 -> V_107 ) ;
return - V_215 ;
}
V_63 = F_150 ( V_20 , V_313 ,
( T_1 * ) & V_299 , sizeof( V_299 ) ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_61 ) ;
return V_63 ;
}
V_63 = F_150 ( V_20 , V_314 ,
( T_1 * ) & V_301 , sizeof( V_301 ) ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 , L_62 ) ;
return V_63 ;
}
switch ( V_20 -> V_107 ) {
case V_303 :
break;
case V_276 :
F_152 ( V_20 ) ;
V_63 = F_150 ( V_20 , V_315 ,
V_302 , 3 ) ;
if ( V_63 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_63 ) ;
return V_63 ;
}
F_152 ( V_20 ) ;
break;
}
return 0 ;
}
static int F_158 ( struct V_316 * V_50 ,
const struct V_317 * V_318 )
{
struct V_285 V_319 ;
struct V_19 * V_20 ;
struct V_320 * V_321 ;
struct V_322 * V_323 ;
int V_324 = 0 ;
int V_325 = 0 ;
int V_63 = - V_92 ;
int V_25 ;
T_5 V_326 ;
V_20 = F_50 ( sizeof( * V_20 ) , V_73 ) ;
if ( ! V_20 )
return - V_92 ;
V_20 -> V_327 = F_159 ( F_160 ( V_50 ) ) ;
V_20 -> V_50 = V_50 ;
F_161 ( & V_20 -> V_93 ) ;
V_321 = V_50 -> V_328 ;
for ( V_25 = 0 ; V_25 < V_321 -> V_329 . V_330 ; ++ V_25 ) {
V_323 = & V_321 -> V_323 [ V_25 ] . V_329 ;
if ( ! V_324 && F_162 ( V_323 ) )
V_324 = V_323 -> V_331 ;
if ( ! V_325 && F_163 ( V_323 ) )
V_325 = V_323 -> V_331 ;
}
if ( ! V_324 || ! V_325 ) {
F_30 ( & V_50 -> V_20 ,
L_64 ) ;
V_63 = - V_332 ;
goto error;
}
V_20 -> V_53 = F_164 ( 0 , V_73 ) ;
V_20 -> V_67 = F_164 ( 0 , V_73 ) ;
if ( ! V_20 -> V_53 || ! V_20 -> V_67 )
goto error;
F_165 ( V_20 -> V_53 , V_20 -> V_327 ,
F_166 ( V_20 -> V_327 , V_324 ) ,
NULL , 0 , NULL , V_20 ) ;
F_165 ( V_20 -> V_67 , V_20 -> V_327 ,
F_167 ( V_20 -> V_327 , V_325 ) ,
NULL , 0 , F_70 , V_20 ) ;
F_168 ( & V_20 -> V_103 , F_62 ) ;
F_168 ( & V_20 -> V_60 , F_60 ) ;
F_168 ( & V_20 -> V_268 , F_148 ) ;
F_168 ( & V_20 -> V_270 , F_149 ) ;
F_168 ( & V_20 -> V_210 , F_111 ) ;
F_168 ( & V_20 -> V_202 , F_105 ) ;
F_168 ( & V_20 -> V_205 , F_106 ) ;
F_169 ( & V_20 -> V_222 , F_129 ) ;
F_168 ( & V_20 -> V_224 , F_118 ) ;
V_20 -> V_59 = F_170 ( L_65 , 0 ) ;
if ( V_20 -> V_59 == NULL )
goto error;
F_171 ( & V_20 -> V_245 ) ;
V_20 -> V_245 . V_12 = ( unsigned long ) V_20 ;
V_20 -> V_245 . V_333 = F_114 ;
F_108 ( & V_20 -> V_198 ) ;
F_108 ( & V_20 -> V_206 ) ;
F_52 ( & V_20 -> V_98 ) ;
F_172 ( V_50 , V_20 ) ;
V_20 -> V_33 = & V_334 ;
V_20 -> V_74 = V_76 ;
V_20 -> V_107 = V_318 -> V_335 ;
switch ( V_20 -> V_107 ) {
case V_303 :
V_326 = V_336 ;
break;
case V_276 :
V_326 = V_337 ;
break;
case V_108 :
V_326 = V_337 ;
V_20 -> V_33 = & V_338 ;
V_20 -> V_74 = V_75 ,
V_63 = F_154 ( V_20 ) ;
if ( V_63 < 0 ) {
F_30 ( & V_20 -> V_50 -> V_20 ,
L_66 , V_63 ) ;
goto V_339;
}
break;
default:
F_30 ( & V_20 -> V_50 -> V_20 , L_60 ,
V_20 -> V_107 ) ;
V_63 = - V_215 ;
goto V_339;
}
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
V_63 = F_151 ( V_20 , & V_319 ) ;
if ( V_63 < 0 )
goto V_339;
F_173 ( & V_20 -> V_50 -> V_20 ,
L_67 ,
V_319 . V_288 , V_319 . V_289 , V_319 . V_290 ) ;
V_20 -> V_176 = F_174 ( & V_340 , V_326 ,
V_20 -> V_33 -> V_80 +
V_281 ,
V_20 -> V_33 -> V_81 ) ;
if ( ! V_20 -> V_176 ) {
V_63 = - V_92 ;
goto V_339;
}
F_175 ( V_20 -> V_176 , & V_50 -> V_20 ) ;
F_176 ( V_20 -> V_176 , V_20 ) ;
V_63 = F_177 ( V_20 -> V_176 ) ;
if ( V_63 )
goto V_341;
V_63 = F_157 ( V_20 ) ;
if ( V_63 )
goto V_342;
return 0 ;
V_342:
F_178 ( V_20 -> V_176 ) ;
V_341:
F_179 ( V_20 -> V_176 ) ;
V_339:
F_180 ( V_20 -> V_59 ) ;
error:
F_181 ( V_20 -> V_53 ) ;
F_181 ( V_20 -> V_67 ) ;
F_182 ( V_20 -> V_327 ) ;
F_48 ( V_20 ) ;
return V_63 ;
}
static void F_183 ( struct V_316 * V_50 )
{
struct V_19 * V_20 ;
struct V_45 * V_41 , * V_343 ;
V_20 = F_184 ( V_50 ) ;
F_172 ( V_50 , NULL ) ;
F_178 ( V_20 -> V_176 ) ;
F_179 ( V_20 -> V_176 ) ;
F_72 ( V_20 -> V_53 ) ;
F_72 ( V_20 -> V_67 ) ;
F_133 ( & V_20 -> V_222 ) ;
F_180 ( V_20 -> V_59 ) ;
F_99 ( & V_20 -> V_198 ) ;
F_126 ( & V_20 -> V_245 ) ;
F_185 (cmd, n, &dev->cmd_queue, queue) {
F_65 ( & V_41 -> V_97 ) ;
F_48 ( V_41 ) ;
}
F_181 ( V_20 -> V_53 ) ;
F_181 ( V_20 -> V_67 ) ;
F_48 ( V_20 ) ;
F_173 ( & V_50 -> V_20 , L_68 ) ;
}
