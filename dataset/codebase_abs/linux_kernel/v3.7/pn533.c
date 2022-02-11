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
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 = 0 ;
V_7 -> V_9 = F_4 ( V_10 ) ;
V_7 -> V_3 = 0 ;
V_7 -> V_11 = 0xFF ;
V_7 -> V_2 [ 0 ] = 0 ;
}
static void F_5 ( struct V_6 * V_7 , T_1 V_12 )
{
V_7 -> V_8 = 0 ;
V_7 -> V_9 = F_4 ( V_10 ) ;
F_6 ( V_7 ) = V_13 ;
F_7 ( V_7 ) = V_12 ;
V_7 -> V_3 = 2 ;
}
static void F_8 ( struct V_6 * V_7 )
{
V_7 -> V_11 = F_1 ( V_7 -> V_3 ) ;
F_9 ( V_7 ) =
F_2 ( V_7 -> V_2 , V_7 -> V_3 ) ;
F_10 ( V_7 ) = 0 ;
}
static bool F_11 ( struct V_6 * V_7 )
{
T_1 V_14 ;
if ( V_7 -> V_9 != F_4 ( V_10 ) )
return false ;
V_14 = F_1 ( V_7 -> V_3 ) ;
if ( V_14 != V_7 -> V_11 )
return false ;
V_14 = F_2 ( V_7 -> V_2 , V_7 -> V_3 ) ;
if ( V_14 != F_9 ( V_7 ) )
return false ;
return true ;
}
static bool F_12 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 != F_4 ( V_10 ) )
return false ;
if ( V_7 -> V_3 != 0 || V_7 -> V_11 != 0xFF )
return false ;
return true ;
}
static bool F_13 ( struct V_6 * V_7 , T_1 V_12 )
{
return ( F_7 ( V_7 ) == F_14 ( V_12 ) ) ;
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_19 ) ;
struct V_6 * V_20 ;
int V_21 ;
V_20 = V_18 -> V_22 ;
if ( V_18 -> V_23 )
V_21 = V_18 -> V_24 ( V_18 , V_18 -> V_25 , NULL ,
V_18 -> V_23 ) ;
else
V_21 = V_18 -> V_24 ( V_18 , V_18 -> V_25 ,
F_17 ( V_20 ) ,
F_18 ( V_20 ) ) ;
if ( V_21 != - V_26 )
F_19 ( V_18 -> V_27 , & V_18 -> V_28 ) ;
}
static void F_20 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_30 ;
struct V_6 * V_20 ;
V_18 -> V_22 = NULL ;
switch ( V_29 -> V_31 ) {
case 0 :
break;
case - V_32 :
case - V_33 :
case - V_34 :
F_21 ( & V_18 -> V_35 -> V_18 , L_1
L_2 , V_29 -> V_31 ) ;
V_18 -> V_23 = V_29 -> V_31 ;
goto V_36;
default:
F_22 ( & V_18 -> V_35 -> V_18 , L_3
L_4 , V_29 -> V_31 ) ;
V_18 -> V_23 = V_29 -> V_31 ;
goto V_36;
}
V_20 = V_18 -> V_37 -> V_38 ;
if ( ! F_11 ( V_20 ) ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_5 ) ;
V_18 -> V_23 = - V_39 ;
goto V_36;
}
if ( ! F_13 ( V_20 , V_18 -> V_12 ) ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_6
L_7 ) ;
V_18 -> V_23 = - V_39 ;
goto V_36;
}
F_21 ( & V_18 -> V_35 -> V_18 , L_8 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_22 = V_20 ;
V_36:
F_19 ( V_18 -> V_27 , & V_18 -> V_19 ) ;
}
static int F_23 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_37 -> V_41 = F_20 ;
return F_24 ( V_18 -> V_37 , V_40 ) ;
}
static void F_25 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_30 ;
struct V_6 * V_20 ;
int V_21 ;
switch ( V_29 -> V_31 ) {
case 0 :
break;
case - V_32 :
case - V_33 :
case - V_34 :
F_21 ( & V_18 -> V_35 -> V_18 , L_1
L_2 , V_29 -> V_31 ) ;
V_18 -> V_23 = V_29 -> V_31 ;
goto V_36;
default:
F_22 ( & V_18 -> V_35 -> V_18 , L_3
L_4 , V_29 -> V_31 ) ;
V_18 -> V_23 = V_29 -> V_31 ;
goto V_36;
}
V_20 = V_18 -> V_37 -> V_38 ;
if ( ! F_12 ( V_20 ) ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_9 ) ;
V_18 -> V_23 = - V_39 ;
goto V_36;
}
F_21 ( & V_18 -> V_35 -> V_18 , L_10 ) ;
V_21 = F_23 ( V_18 , V_42 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_11
L_12 , V_21 ) ;
V_18 -> V_23 = V_21 ;
goto V_36;
}
return;
V_36:
V_18 -> V_22 = NULL ;
F_19 ( V_18 -> V_27 , & V_18 -> V_19 ) ;
}
static int F_26 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_37 -> V_41 = F_25 ;
return F_24 ( V_18 -> V_37 , V_40 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_3 ( V_18 -> V_44 ) ;
V_18 -> V_45 -> V_38 = V_18 -> V_44 ;
V_18 -> V_45 -> V_46 = V_47 ;
V_21 = F_24 ( V_18 -> V_45 , V_40 ) ;
return V_21 ;
}
static int F_28 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_14 ,
F_7 ( V_44 ) ) ;
V_18 -> V_12 = F_7 ( V_44 ) ;
V_18 -> V_24 = V_24 ;
V_18 -> V_25 = V_49 ;
V_18 -> V_45 -> V_38 = V_44 ;
V_18 -> V_45 -> V_46 =
F_29 ( V_44 ) ;
V_18 -> V_37 -> V_38 = V_20 ;
V_18 -> V_37 -> V_46 = V_48 ;
V_21 = F_24 ( V_18 -> V_45 , V_40 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_26 ( V_18 , V_40 ) ;
if ( V_21 )
goto error;
return 0 ;
error:
F_30 ( V_18 -> V_45 ) ;
return V_21 ;
}
static void F_31 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_28 ) ;
struct V_50 * V_12 ;
F_32 ( & V_18 -> V_51 ) ;
if ( F_33 ( & V_18 -> V_52 ) ) {
V_18 -> V_53 = 0 ;
F_34 ( & V_18 -> V_51 ) ;
return;
}
V_12 = F_35 ( & V_18 -> V_52 , struct V_50 , V_54 ) ;
F_36 ( & V_12 -> V_54 ) ;
F_34 ( & V_18 -> V_51 ) ;
F_28 ( V_18 , V_12 -> V_44 , V_12 -> V_20 ,
V_12 -> V_48 , V_12 -> V_24 ,
V_12 -> V_49 , V_12 -> V_40 ) ;
F_37 ( V_12 ) ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
struct V_50 * V_12 ;
int V_21 = 0 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_32 ( & V_18 -> V_51 ) ;
if ( ! V_18 -> V_53 ) {
V_21 = F_28 ( V_18 , V_44 , V_20 ,
V_48 , V_24 ,
V_49 , V_40 ) ;
if ( ! V_21 )
V_18 -> V_53 = 1 ;
goto V_55;
}
F_21 ( & V_18 -> V_35 -> V_18 , L_15 , V_43 ) ;
V_12 = F_39 ( sizeof( struct V_50 ) , V_40 ) ;
if ( ! V_12 ) {
V_21 = - V_56 ;
goto V_55;
}
F_40 ( & V_12 -> V_54 ) ;
V_12 -> V_44 = V_44 ;
V_12 -> V_20 = V_20 ;
V_12 -> V_48 = V_48 ;
V_12 -> V_24 = V_24 ;
V_12 -> V_49 = V_49 ;
V_12 -> V_40 = V_40 ;
F_41 ( & V_12 -> V_54 , & V_18 -> V_52 ) ;
V_55:
F_34 ( & V_18 -> V_51 ) ;
return V_21 ;
}
static int F_42 ( struct V_17 * V_18 , void * V_57 ,
T_1 * V_58 , int V_59 )
{
struct V_60 * V_49 = V_57 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
V_49 -> V_21 = 0 ;
if ( V_59 < 0 )
V_49 -> V_21 = V_59 ;
V_41 ( & V_49 -> V_61 ) ;
return 0 ;
}
static int F_43 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 )
{
int V_21 ;
struct V_60 V_49 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_44 ( & V_49 . V_61 ) ;
V_21 = F_38 ( V_18 , V_44 , V_20 , V_48 ,
F_42 , & V_49 , V_62 ) ;
if ( V_21 )
return V_21 ;
F_45 ( & V_49 . V_61 ) ;
return V_49 . V_21 ;
}
static void F_46 ( struct V_29 * V_29 )
{
struct V_17 * V_18 = V_29 -> V_30 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
switch ( V_29 -> V_31 ) {
case 0 :
break;
case - V_32 :
case - V_33 :
case - V_34 :
F_21 ( & V_18 -> V_35 -> V_18 , L_1
L_2 , V_29 -> V_31 ) ;
break;
default:
F_21 ( & V_18 -> V_35 -> V_18 , L_3
L_4 , V_29 -> V_31 ) ;
}
}
static bool F_47 ( struct V_63 * V_64 ,
int V_65 )
{
T_1 V_66 ;
T_1 V_67 ;
if ( V_65 < sizeof( struct V_63 ) )
return false ;
V_66 = F_48 ( V_64 -> V_68 ) ;
V_67 = F_49 ( V_64 -> V_68 ) ;
if ( ( V_66 == V_69 &&
V_67 != V_70 ) ||
( V_66 != V_69 &&
V_67 == V_70 ) )
return false ;
if ( F_50 ( V_64 -> V_71 ) != 0 )
return false ;
return true ;
}
static int F_51 ( struct V_72 * V_73 , T_1 * V_74 ,
int V_75 )
{
struct V_63 * V_76 ;
V_76 = (struct V_63 * ) V_74 ;
if ( ! F_47 ( V_76 , V_75 ) )
return - V_77 ;
switch ( F_52 ( V_76 -> V_71 ) ) {
case V_78 :
V_73 -> V_79 = V_80 ;
break;
case V_81 :
V_73 -> V_79 = V_82 ;
break;
case V_83 :
V_73 -> V_79 = V_84 ;
break;
case V_85 :
V_73 -> V_79 = V_82 |
V_84 ;
break;
}
V_73 -> V_68 = F_53 ( V_76 -> V_68 ) ;
V_73 -> V_71 = V_76 -> V_71 ;
V_73 -> V_86 = V_76 -> V_87 ;
memcpy ( V_73 -> V_88 , V_76 -> V_89 , V_73 -> V_86 ) ;
return 0 ;
}
static bool F_54 ( struct V_90 * V_91 ,
int V_65 )
{
if ( V_65 < sizeof( struct V_90 ) )
return false ;
if ( V_91 -> V_92 != V_93 )
return false ;
return true ;
}
static int F_55 ( struct V_72 * V_73 , T_1 * V_74 ,
int V_75 )
{
struct V_90 * V_94 ;
V_94 = (struct V_90 * ) V_74 ;
if ( ! F_54 ( V_94 , V_75 ) )
return - V_77 ;
if ( V_94 -> V_95 [ 0 ] == V_96 &&
V_94 -> V_95 [ 1 ] ==
V_97 )
V_73 -> V_79 = V_84 ;
else
V_73 -> V_79 = V_98 ;
memcpy ( V_73 -> V_99 , & V_94 -> V_92 , 9 ) ;
V_73 -> V_100 = 9 ;
return 0 ;
}
static bool F_56 ( struct V_101 * V_102 ,
int V_65 )
{
T_1 V_66 ;
T_1 V_67 ;
if ( V_65 < sizeof( struct V_101 ) )
return false ;
V_66 = F_48 ( V_102 -> V_68 ) ;
V_67 = F_49 ( V_102 -> V_68 ) ;
if ( ( V_66 == V_69 &&
V_67 != V_70 ) ||
( V_66 != V_69 &&
V_67 == V_70 ) )
return false ;
return true ;
}
static int F_57 ( struct V_72 * V_73 , T_1 * V_74 ,
int V_75 )
{
struct V_101 * V_103 ;
V_103 = (struct V_101 * ) V_74 ;
if ( ! F_56 ( V_103 , V_75 ) )
return - V_77 ;
V_73 -> V_79 = V_104 ;
V_73 -> V_68 = F_53 ( V_103 -> V_68 ) ;
V_73 -> V_86 = 4 ;
memcpy ( V_73 -> V_88 , V_103 -> V_105 , V_73 -> V_86 ) ;
return 0 ;
}
static bool F_58 ( struct V_106 * V_107 ,
int V_65 )
{
if ( V_65 < sizeof( struct V_106 ) )
return false ;
if ( V_107 -> V_108 . V_92 != V_109 )
return false ;
if ( F_59 ( V_107 -> V_108 . V_110 . V_111 ) &
V_112 )
return false ;
return true ;
}
static int F_60 ( struct V_72 * V_73 , T_1 * V_74 ,
int V_75 )
{
struct V_106 * V_113 ;
V_113 = (struct V_106 * ) V_74 ;
if ( ! F_58 ( V_113 , V_75 ) )
return - V_77 ;
V_73 -> V_79 = V_114 ;
return 0 ;
}
static int F_61 ( struct V_17 * V_18 ,
struct V_115 * V_116 , int V_117 )
{
int V_65 ;
struct V_72 V_73 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_16 , V_43 ,
V_18 -> V_118 ) ;
if ( V_116 -> V_119 != 1 )
return - V_77 ;
memset ( & V_73 , 0 , sizeof( struct V_72 ) ) ;
V_65 = V_117 - sizeof( struct V_115 ) ;
switch ( V_18 -> V_118 ) {
case V_120 :
V_21 = F_51 ( & V_73 , V_116 -> V_121 ,
V_65 ) ;
break;
case V_122 :
case V_123 :
V_21 = F_55 ( & V_73 , V_116 -> V_121 ,
V_65 ) ;
break;
case V_124 :
V_21 = F_57 ( & V_73 , V_116 -> V_121 ,
V_65 ) ;
break;
case V_125 :
V_21 = F_60 ( & V_73 , V_116 -> V_121 ,
V_65 ) ;
break;
default:
F_22 ( & V_18 -> V_35 -> V_18 , L_17
L_18 ) ;
return - V_77 ;
}
if ( V_21 )
return V_21 ;
if ( ! ( V_73 . V_79 & V_18 -> V_126 ) ) {
F_21 ( & V_18 -> V_35 -> V_18 , L_19
L_20 ) ;
return - V_127 ;
}
F_21 ( & V_18 -> V_35 -> V_18 , L_21
L_22 , V_73 . V_79 ) ;
V_18 -> V_128 = V_73 . V_79 ;
F_62 ( V_18 -> V_129 , & V_73 , 1 ) ;
return 0 ;
}
static inline void F_63 ( struct V_17 * V_18 )
{
V_18 -> V_118 = ( V_18 -> V_118 + 1 ) % V_18 -> V_130 ;
}
static void F_64 ( struct V_17 * V_18 )
{
V_18 -> V_130 = 0 ;
}
static void F_65 ( struct V_17 * V_18 , T_1 V_131 )
{
V_18 -> V_132 [ V_18 -> V_130 ] =
(struct V_133 * ) & V_134 [ V_131 ] ;
V_18 -> V_130 ++ ;
}
static void F_66 ( struct V_17 * V_18 ,
T_4 V_135 , T_4 V_136 )
{
F_64 ( V_18 ) ;
if ( V_135 & V_80
|| V_135 & V_82
|| V_135 & V_84 )
F_65 ( V_18 , V_120 ) ;
if ( V_135 & V_98
|| V_135 & V_84 ) {
F_65 ( V_18 , V_122 ) ;
F_65 ( V_18 , V_123 ) ;
}
if ( V_135 & V_104 )
F_65 ( V_18 , V_124 ) ;
if ( V_135 & V_114 )
F_65 ( V_18 , V_125 ) ;
if ( V_136 )
F_65 ( V_18 , V_137 ) ;
}
static int F_67 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_115 * V_116 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
V_116 = (struct V_115 * ) V_58 ;
if ( V_116 -> V_138 ) {
V_21 = F_61 ( V_18 , V_116 , V_59 ) ;
if ( V_21 == 0 ) {
F_64 ( V_18 ) ;
return 0 ;
}
}
return - V_127 ;
}
static int F_68 ( struct V_6 * V_7 ,
T_1 * V_139 , T_5 V_140 )
{
struct V_141 * V_12 ;
T_5 V_142 ;
T_1 V_143 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_144 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
V_142 = sizeof( struct V_141 ) + V_140 + 1 ;
V_12 = F_39 ( V_142 , V_62 ) ;
if ( V_12 == NULL )
return - V_56 ;
F_5 ( V_7 , V_145 ) ;
V_12 -> V_146 |= V_147 ;
memcpy ( V_12 -> V_91 , V_143 , 18 ) ;
F_69 ( V_12 -> V_91 + 2 , 6 ) ;
memset ( V_12 -> V_148 , 0 , 10 ) ;
memcpy ( V_12 -> V_148 , V_12 -> V_91 , 8 ) ;
memcpy ( V_12 -> V_149 , V_144 , 6 ) ;
V_12 -> V_140 = V_140 ;
memcpy ( V_12 -> V_139 , V_139 , V_140 ) ;
V_12 -> V_139 [ V_140 ] = 0 ;
memcpy ( F_17 ( V_7 ) , V_12 , V_142 ) ;
V_7 -> V_3 += V_142 ;
F_8 ( V_7 ) ;
F_37 ( V_12 ) ;
return 0 ;
}
static int F_70 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_150 * V_151 = V_49 ;
struct V_6 * V_20 = (struct V_6 * ) V_151 -> V_2 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( V_59 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_23 ,
V_59 ) ;
return V_59 ;
}
if ( V_59 > 0 && V_58 [ 0 ] != 0 ) {
F_71 ( V_18 -> V_129 ) ;
V_18 -> V_152 = 0 ;
F_72 ( V_151 ) ;
return 0 ;
}
F_73 ( V_151 , F_29 ( V_20 ) ) ;
F_74 ( V_151 , V_153 ) ;
F_75 ( V_151 , V_151 -> V_154 - V_155 ) ;
return F_76 ( V_18 -> V_129 , V_151 ) ;
}
static void F_77 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_156 ) ;
struct V_6 * V_20 ;
struct V_150 * V_151 ;
T_5 V_157 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
V_157 = V_153 +
V_158 +
V_155 ;
V_151 = F_78 ( V_157 , V_62 ) ;
if ( ! V_151 )
return;
V_20 = (struct V_6 * ) V_151 -> V_2 ;
F_5 ( V_18 -> V_44 , V_159 ) ;
F_8 ( V_18 -> V_44 ) ;
F_38 ( V_18 , V_18 -> V_44 , V_20 ,
V_157 ,
F_70 ,
V_151 , V_62 ) ;
return;
}
static int F_79 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_160 * V_116 ;
T_1 V_7 , V_161 = V_162 , * V_139 ;
T_5 V_140 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( V_59 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_23 ,
V_59 ) ;
return V_59 ;
}
if ( V_59 < V_163 + 1 )
return - V_164 ;
V_116 = (struct V_160 * ) V_58 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_24 ,
V_116 -> V_146 , V_59 ) ;
V_7 = V_116 -> V_146 & V_165 ;
if ( V_7 == V_166 )
V_161 = V_167 ;
if ( ( V_116 -> V_146 & V_168 ) == 0 )
return - V_169 ;
V_139 = V_116 -> V_12 + V_163 ;
V_140 = V_59 - ( V_163 + 1 ) ;
V_21 = F_80 ( V_18 -> V_129 , V_84 ,
V_161 , V_139 , V_140 ) ;
if ( V_21 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_25 ) ;
return V_21 ;
}
V_18 -> V_152 = 1 ;
F_19 ( V_18 -> V_27 , & V_18 -> V_156 ) ;
return 0 ;
}
static void F_81 ( unsigned long V_2 )
{
struct V_17 * V_18 = (struct V_17 * ) V_2 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_26 ) ;
F_27 ( V_18 , V_42 ) ;
V_18 -> V_170 = 1 ;
F_63 ( V_18 ) ;
F_19 ( V_18 -> V_27 , & V_18 -> V_171 ) ;
}
static int F_82 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_133 * V_172 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( V_59 == - V_33 ) {
if ( V_18 -> V_130 != 0 )
return 0 ;
F_22 ( & V_18 -> V_35 -> V_18 ,
L_27 ) ;
goto V_173;
}
if ( V_59 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_28 , V_59 ) ;
goto V_173;
}
V_172 = V_18 -> V_132 [ V_18 -> V_118 ] ;
if ( V_172 -> V_154 == 0 ) {
F_83 ( & V_18 -> V_174 ) ;
return F_79 ( V_18 , V_49 , V_58 , V_59 ) ;
} else {
V_21 = F_67 ( V_18 , V_49 , V_58 , V_59 ) ;
if ( ! V_21 )
return V_21 ;
}
F_63 ( V_18 ) ;
F_19 ( V_18 -> V_27 , & V_18 -> V_171 ) ;
return 0 ;
V_173:
F_64 ( V_18 ) ;
V_18 -> V_126 = 0 ;
return 0 ;
}
static void F_84 ( struct V_17 * V_18 ,
struct V_6 * V_7 ,
struct V_133 * V_175 )
{
F_21 ( & V_18 -> V_35 -> V_18 , L_29 , V_175 -> V_154 ) ;
if ( V_175 -> V_154 == 0 ) {
F_68 ( V_7 , V_18 -> V_139 , V_18 -> V_140 ) ;
} else {
F_5 ( V_7 , V_176 ) ;
memcpy ( F_17 ( V_7 ) , & V_175 -> V_2 , V_175 -> V_154 ) ;
V_7 -> V_3 += V_175 -> V_154 ;
F_8 ( V_7 ) ;
}
}
static int F_85 ( struct V_17 * V_18 )
{
struct V_133 * V_172 ;
int V_21 ;
V_172 = V_18 -> V_132 [ V_18 -> V_118 ] ;
F_84 ( V_18 , V_18 -> V_44 , V_172 ) ;
V_21 = F_38 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 , F_82 ,
NULL , V_62 ) ;
if ( V_21 )
F_22 ( & V_18 -> V_35 -> V_18 , L_30 , V_21 ) ;
return V_21 ;
}
static void F_86 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_171 ) ;
struct V_133 * V_172 ;
int V_21 ;
V_172 = V_18 -> V_132 [ V_18 -> V_118 ] ;
F_21 ( & V_18 -> V_35 -> V_18 ,
L_31 ,
V_43 , V_18 -> V_170 , V_172 -> V_154 ) ;
if ( V_18 -> V_170 == 1 ) {
V_18 -> V_170 = 0 ;
F_87 ( V_18 -> V_37 ) ;
}
V_21 = F_85 ( V_18 ) ;
if ( V_21 )
return;
if ( V_172 -> V_154 == 0 && V_18 -> V_130 > 1 )
F_88 ( & V_18 -> V_174 , V_178 + V_179 * V_180 ) ;
return;
}
static int F_89 ( struct V_129 * V_129 ,
T_4 V_135 , T_4 V_136 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
F_21 ( & V_18 -> V_35 -> V_18 ,
L_32 ,
V_43 , V_135 , V_136 ) ;
if ( V_18 -> V_181 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_33 ) ;
return - V_182 ;
}
if ( V_18 -> V_152 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_34 ) ;
return - V_182 ;
}
if ( V_136 ) {
V_18 -> V_139 = F_91 ( V_129 , & V_18 -> V_140 ) ;
if ( V_18 -> V_139 == NULL )
V_136 = 0 ;
}
V_18 -> V_118 = 0 ;
F_66 ( V_18 , V_135 , V_136 ) ;
V_18 -> V_126 = V_135 ;
V_18 -> V_183 = V_136 ;
return F_85 ( V_18 ) ;
}
static void F_92 ( struct V_129 * V_129 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_83 ( & V_18 -> V_174 ) ;
if ( ! V_18 -> V_130 ) {
F_21 ( & V_18 -> V_35 -> V_18 , L_35
L_36 ) ;
return;
}
F_27 ( V_18 , V_62 ) ;
F_87 ( V_18 -> V_37 ) ;
F_64 ( V_18 ) ;
}
static int F_93 ( struct V_17 * V_18 )
{
struct V_184 V_185 ;
struct V_186 * V_116 ;
T_6 V_187 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_188 ) ;
V_185 . V_119 = 1 ;
V_185 . V_189 = 0 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_185 ,
sizeof( struct V_184 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( struct V_184 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_43 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 ) ;
if ( V_21 )
return V_21 ;
V_116 = (struct V_186 * )
F_17 ( V_18 -> V_20 ) ;
V_21 = V_116 -> V_31 & V_190 ;
if ( V_21 != V_191 )
return - V_39 ;
V_187 = F_18 ( V_18 -> V_20 ) - 16 ;
V_21 = F_94 ( V_18 -> V_129 , V_116 -> V_192 , V_187 ) ;
return V_21 ;
}
static int F_95 ( struct V_129 * V_129 ,
struct V_72 * V_193 , T_4 V_194 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_37 , V_43 ,
V_194 ) ;
if ( V_18 -> V_130 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_38
L_39 ) ;
return - V_182 ;
}
if ( V_18 -> V_181 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_40
L_41 ) ;
return - V_182 ;
}
if ( ! V_18 -> V_128 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_42
L_43 ) ;
return - V_164 ;
}
if ( ! ( V_18 -> V_128 & ( 1 << V_194 ) ) ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_44
L_45 , V_194 ) ;
return - V_164 ;
}
if ( V_194 == V_195 ) {
V_21 = F_93 ( V_18 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_46
L_47
L_48 , V_21 ) ;
return V_21 ;
}
}
V_18 -> V_181 = V_194 ;
V_18 -> V_128 = 0 ;
return 0 ;
}
static void F_96 ( struct V_129 * V_129 ,
struct V_72 * V_193 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
T_1 V_119 ;
T_1 V_31 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_181 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_49 ) ;
return;
}
V_18 -> V_181 = 0 ;
F_97 ( & V_18 -> V_196 ) ;
F_5 ( V_18 -> V_44 , V_197 ) ;
V_119 = 1 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_119 , sizeof( T_1 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( T_1 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_43 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_50
L_51 ) ;
return;
}
V_31 = F_17 ( V_18 -> V_20 ) [ 0 ] ;
V_21 = V_31 & V_190 ;
if ( V_21 != V_191 )
F_22 ( & V_18 -> V_35 -> V_18 , L_52
L_53 , V_21 ) ;
return;
}
static int F_98 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_198 * V_116 ;
struct V_72 V_72 ;
T_1 V_199 ;
int V_21 ;
struct V_200 * V_12 = (struct V_200 * ) V_49 ;
T_1 V_201 = V_12 -> V_201 ;
F_37 ( V_49 ) ;
if ( V_59 == - V_33 ) {
F_21 ( & V_18 -> V_35 -> V_18 , L_54 ) ;
return 0 ;
}
if ( V_59 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_55 ,
V_59 ) ;
return 0 ;
}
if ( V_18 -> V_128 &&
! ( V_18 -> V_128 & ( 1 << V_195 ) ) ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_56 ) ;
return - V_164 ;
}
V_116 = (struct V_198 * ) V_58 ;
V_21 = V_116 -> V_31 & V_190 ;
if ( V_21 != V_191 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_57 , V_21 ) ;
return 0 ;
}
if ( ! V_18 -> V_128 ) {
F_21 ( & V_18 -> V_35 -> V_18 , L_58 ) ;
V_72 . V_79 = V_84 ;
V_72 . V_86 = 10 ;
memcpy ( V_72 . V_88 , V_116 -> V_202 , V_72 . V_86 ) ;
V_21 = F_62 ( V_18 -> V_129 , & V_72 , 1 ) ;
if ( V_21 )
return 0 ;
V_18 -> V_128 = 0 ;
}
V_18 -> V_181 = V_195 ;
V_199 = F_18 ( V_18 -> V_20 ) - 17 ;
V_21 = F_94 ( V_18 -> V_129 ,
V_116 -> V_192 , V_199 ) ;
if ( V_21 == 0 )
V_21 = F_99 ( V_18 -> V_129 ,
V_18 -> V_129 -> V_203 [ 0 ] . V_204 ,
! V_201 , V_205 ) ;
return 0 ;
}
static int F_100 ( struct V_17 * V_18 )
{
switch ( V_18 -> V_118 ) {
case V_120 :
return 0 ;
case V_122 :
return 1 ;
case V_123 :
return 2 ;
default:
return - V_164 ;
}
}
static int F_101 ( struct V_129 * V_129 , struct V_72 * V_193 ,
T_1 V_161 , T_1 * V_139 , T_5 V_140 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
struct V_200 * V_12 ;
T_1 V_142 , * V_206 ;
T_1 V_207 [ V_208 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
int V_21 , V_209 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( V_18 -> V_130 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_59 ) ;
return - V_182 ;
}
if ( V_18 -> V_181 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_60 ) ;
return - V_182 ;
}
V_209 = F_100 ( V_18 ) ;
if ( V_209 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_61 , V_18 -> V_118 ) ;
return V_209 ;
}
V_142 = sizeof( struct V_200 ) + V_140 ;
if ( V_161 == V_162 )
V_142 += V_208 ;
V_12 = F_39 ( V_142 , V_62 ) ;
if ( V_12 == NULL )
return - V_56 ;
F_5 ( V_18 -> V_44 , V_210 ) ;
V_12 -> V_201 = ! V_161 ;
V_12 -> V_189 = 0 ;
V_12 -> V_209 = V_209 ;
V_206 = V_12 -> V_2 ;
if ( V_161 == V_162 && V_12 -> V_209 > 0 ) {
memcpy ( V_206 , V_207 , V_208 ) ;
V_12 -> V_189 |= 1 ;
V_206 += V_208 ;
}
if ( V_139 != NULL && V_140 > 0 ) {
V_12 -> V_189 |= 4 ;
memcpy ( V_206 , V_139 , V_140 ) ;
} else {
V_12 -> V_189 = 0 ;
}
memcpy ( F_17 ( V_18 -> V_44 ) , V_12 , V_142 ) ;
V_18 -> V_44 -> V_3 += V_142 ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_38 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 , F_98 ,
V_12 , V_62 ) ;
if ( V_21 < 0 )
F_37 ( V_12 ) ;
return V_21 ;
}
static int F_102 ( struct V_129 * V_129 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
F_64 ( V_18 ) ;
if ( V_18 -> V_152 || V_18 -> V_181 ) {
F_27 ( V_18 , V_62 ) ;
F_87 ( V_18 -> V_37 ) ;
}
V_18 -> V_181 = 0 ;
V_18 -> V_152 = 0 ;
F_97 ( & V_18 -> V_196 ) ;
return 0 ;
}
static int F_103 ( struct V_17 * V_18 , struct V_150 * V_211 ,
bool V_193 )
{
int V_212 = V_211 -> V_154 ;
struct V_6 * V_44 ;
T_1 V_119 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_62 , V_43 ,
V_212 ) ;
if ( V_212 > V_158 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_63
L_64 ,
V_158 ) ;
return - V_213 ;
}
if ( V_193 == true ) {
switch ( V_18 -> V_214 ) {
case V_215 :
if ( V_18 -> V_181 == V_216 ) {
F_104 ( V_211 , V_153 - 1 ) ;
V_44 = (struct V_6 * ) V_211 -> V_2 ;
F_5 ( V_44 ,
V_217 ) ;
break;
}
default:
F_104 ( V_211 , V_153 ) ;
V_44 = (struct V_6 * ) V_211 -> V_2 ;
F_5 ( V_44 ,
V_218 ) ;
V_119 = 1 ;
memcpy ( F_17 ( V_44 ) ,
& V_119 , sizeof( T_1 ) ) ;
V_44 -> V_3 += sizeof( T_1 ) ;
break;
}
} else {
F_104 ( V_211 , V_153 - 1 ) ;
V_44 = (struct V_6 * ) V_211 -> V_2 ;
F_5 ( V_44 , V_219 ) ;
}
V_44 -> V_3 += V_212 ;
F_8 ( V_44 ) ;
F_73 ( V_211 , V_155 ) ;
return 0 ;
}
static struct V_150 * F_105 ( struct V_17 * V_18 )
{
struct V_150 * V_211 , * V_220 , * V_221 ;
unsigned int V_222 = 0 , V_223 = 0 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_65 , V_43 ) ;
if ( F_106 ( & V_18 -> V_196 ) )
return NULL ;
if ( F_107 ( & V_18 -> V_196 ) == 1 ) {
V_211 = F_108 ( & V_18 -> V_196 ) ;
goto V_224;
}
F_109 (&dev->resp_q, tmp, t)
V_222 += V_220 -> V_154 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_66 ,
V_43 , V_222 ) ;
V_211 = F_110 ( V_222 , V_62 ) ;
if ( V_211 == NULL )
goto V_224;
F_73 ( V_211 , V_222 ) ;
F_109 (&dev->resp_q, tmp, t) {
memcpy ( V_211 -> V_2 + V_223 , V_220 -> V_2 , V_220 -> V_154 ) ;
V_223 += V_220 -> V_154 ;
}
V_224:
F_97 ( & V_18 -> V_196 ) ;
return V_211 ;
}
static int F_111 ( struct V_17 * V_18 , void * V_57 ,
T_1 * V_58 , int V_59 )
{
struct V_225 * V_49 = V_57 ;
struct V_150 * V_211 = NULL , * V_151 = V_49 -> V_151 ;
struct V_6 * V_20 = (struct V_6 * ) V_151 -> V_2 ;
int V_226 = 0 ;
T_1 V_31 ;
T_1 V_227 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_112 ( V_49 -> V_228 ) ;
if ( V_59 < 0 ) {
V_226 = V_59 ;
goto error;
}
V_31 = V_58 [ 0 ] ;
V_227 = V_31 & V_190 ;
if ( V_227 != V_191 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_67
L_68 , V_227 ) ;
V_226 = - V_39 ;
goto error;
}
F_73 ( V_151 , F_29 ( V_20 ) ) ;
F_74 ( V_151 , V_153 ) ;
F_75 ( V_151 , V_151 -> V_154 - V_155 ) ;
F_113 ( & V_18 -> V_196 , V_151 ) ;
if ( V_31 & V_229 ) {
F_19 ( V_18 -> V_27 , & V_18 -> V_230 ) ;
return - V_26 ;
}
V_211 = F_105 ( V_18 ) ;
if ( V_211 == NULL )
goto error;
V_49 -> V_231 ( V_49 -> V_232 , V_211 , 0 ) ;
F_37 ( V_49 ) ;
return 0 ;
error:
F_97 ( & V_18 -> V_196 ) ;
F_112 ( V_151 ) ;
V_49 -> V_231 ( V_49 -> V_232 , NULL , V_226 ) ;
F_37 ( V_49 ) ;
return 0 ;
}
static int F_114 ( struct V_129 * V_129 ,
struct V_72 * V_193 , struct V_150 * V_211 ,
T_7 V_231 , void * V_232 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
struct V_6 * V_44 , * V_20 ;
struct V_225 * V_49 ;
struct V_150 * V_151 ;
int V_157 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_181 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_69
L_70 ) ;
V_21 = - V_164 ;
goto error;
}
V_21 = F_103 ( V_18 , V_211 , true ) ;
if ( V_21 )
goto error;
V_157 = V_153 +
V_158 +
V_155 ;
V_151 = F_78 ( V_157 , V_62 ) ;
if ( ! V_151 ) {
V_21 = - V_56 ;
goto error;
}
V_20 = (struct V_6 * ) V_151 -> V_2 ;
V_44 = (struct V_6 * ) V_211 -> V_2 ;
V_49 = F_115 ( sizeof( struct V_225 ) , V_62 ) ;
if ( ! V_49 ) {
V_21 = - V_56 ;
goto V_233;
}
V_49 -> V_151 = V_151 ;
V_49 -> V_228 = V_211 ;
V_49 -> V_231 = V_231 ;
V_49 -> V_232 = V_232 ;
V_21 = F_38 ( V_18 , V_44 , V_20 , V_157 ,
F_111 , V_49 ,
V_62 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 , L_71
L_72 , V_21 ) ;
goto V_234;
}
return 0 ;
V_234:
F_37 ( V_49 ) ;
V_233:
F_72 ( V_151 ) ;
error:
F_72 ( V_211 ) ;
return V_21 ;
}
static int F_116 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_58 , int V_59 )
{
struct V_150 * V_228 = V_49 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_112 ( V_228 ) ;
if ( V_59 < 0 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_73 ,
V_59 ) ;
return V_59 ;
}
if ( V_59 > 0 && V_58 [ 0 ] != 0 ) {
F_71 ( V_18 -> V_129 ) ;
V_18 -> V_152 = 0 ;
return 0 ;
}
F_19 ( V_18 -> V_27 , & V_18 -> V_156 ) ;
return 0 ;
}
static int F_117 ( struct V_129 * V_129 , struct V_150 * V_211 )
{
struct V_17 * V_18 = F_90 ( V_129 ) ;
struct V_6 * V_44 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
V_21 = F_103 ( V_18 , V_211 , false ) ;
if ( V_21 )
goto error;
V_44 = (struct V_6 * ) V_211 -> V_2 ;
V_21 = F_38 ( V_18 , V_44 , V_18 -> V_20 ,
V_18 -> V_177 , F_116 ,
V_211 , V_62 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_74 , V_21 ) ;
goto error;
}
return 0 ;
error:
F_72 ( V_211 ) ;
return V_21 ;
}
static void F_118 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_230 ) ;
struct V_150 * V_235 ;
struct V_225 * V_49 = V_18 -> V_25 ;
struct V_6 * V_44 , * V_20 ;
struct V_150 * V_151 ;
int V_157 ;
int V_21 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
V_235 = F_110 ( V_153 + V_155 ,
V_62 ) ;
if ( V_235 == NULL )
goto V_236;
F_119 ( V_235 , V_153 ) ;
V_21 = F_103 ( V_18 , V_235 , true ) ;
if ( V_21 )
goto V_237;
V_157 = V_153 +
V_158 +
V_155 ;
V_151 = F_110 ( V_157 , V_62 ) ;
if ( ! V_151 ) {
V_21 = - V_56 ;
goto V_237;
}
V_20 = (struct V_6 * ) V_151 -> V_2 ;
V_44 = (struct V_6 * ) V_235 -> V_2 ;
V_49 -> V_151 = V_151 ;
V_49 -> V_228 = V_235 ;
V_21 = F_28 ( V_18 , V_44 , V_20 ,
V_157 ,
F_111 ,
V_18 -> V_25 , V_62 ) ;
if ( ! V_21 )
return;
F_22 ( & V_18 -> V_35 -> V_18 , L_71
L_72 , V_21 ) ;
F_72 ( V_151 ) ;
V_237:
F_72 ( V_235 ) ;
V_236:
F_27 ( V_18 , V_62 ) ;
F_37 ( V_49 ) ;
F_19 ( V_18 -> V_27 , & V_18 -> V_28 ) ;
}
static int F_120 ( struct V_17 * V_18 , T_1 V_238 , T_1 * V_239 ,
T_1 V_240 )
{
int V_21 ;
T_1 * V_58 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_241 ) ;
V_58 = F_17 ( V_18 -> V_44 ) ;
V_58 [ 0 ] = V_238 ;
memcpy ( & V_58 [ 1 ] , V_239 , V_240 ) ;
V_18 -> V_44 -> V_3 += ( 1 + V_240 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_43 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 ) ;
return V_21 ;
}
static int F_121 ( struct V_17 * V_18 )
{
int V_21 ;
T_1 * V_58 ;
F_21 ( & V_18 -> V_35 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , 0x18 ) ;
V_58 = F_17 ( V_18 -> V_44 ) ;
V_58 [ 0 ] = 0x1 ;
V_18 -> V_44 -> V_3 += 1 ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_43 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 ) ;
return V_21 ;
}
static int F_122 ( struct V_17 * V_18 )
{
struct V_242 V_243 ;
struct V_244 V_245 ;
T_1 V_246 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_21 ;
switch ( V_18 -> V_214 ) {
case V_247 :
V_243 . V_248 = V_249 ;
V_243 . V_250 = 2 ;
V_243 . V_251 =
V_252 ;
V_245 . V_253 = V_254 ;
V_245 . V_255 = V_256 ;
V_245 . V_257 = V_258 ;
break;
case V_215 :
V_243 . V_248 = 0x2 ;
V_243 . V_250 = 0x1 ;
V_243 . V_251 =
V_252 ;
V_245 . V_253 = V_254 ;
V_245 . V_255 = V_254 ;
V_245 . V_257 = V_256 ;
break;
default:
F_22 ( & V_18 -> V_35 -> V_18 , L_75 ,
V_18 -> V_214 ) ;
return - V_164 ;
}
V_21 = F_120 ( V_18 , V_259 ,
( T_1 * ) & V_243 , sizeof( V_243 ) ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_76 ) ;
return V_21 ;
}
V_21 = F_120 ( V_18 , V_260 ,
( T_1 * ) & V_245 , sizeof( V_245 ) ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_77 ) ;
return V_21 ;
}
switch ( V_18 -> V_214 ) {
case V_247 :
break;
case V_215 :
F_121 ( V_18 ) ;
V_21 = F_120 ( V_18 , V_261 ,
V_246 , 3 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_35 -> V_18 ,
L_78 ) ;
return V_21 ;
}
F_121 ( V_18 ) ;
break;
}
return 0 ;
}
static int F_123 ( struct V_262 * V_35 ,
const struct V_263 * V_264 )
{
struct V_265 * V_266 ;
struct V_17 * V_18 ;
struct V_267 * V_268 ;
struct V_269 * V_270 ;
int V_271 = 0 ;
int V_272 = 0 ;
int V_21 = - V_56 ;
int V_5 ;
T_4 V_273 ;
V_18 = F_39 ( sizeof( * V_18 ) , V_62 ) ;
if ( ! V_18 )
return - V_56 ;
V_18 -> V_274 = F_124 ( F_125 ( V_35 ) ) ;
V_18 -> V_35 = V_35 ;
F_126 ( & V_18 -> V_51 ) ;
V_268 = V_35 -> V_275 ;
for ( V_5 = 0 ; V_5 < V_268 -> V_276 . V_277 ; ++ V_5 ) {
V_270 = & V_268 -> V_270 [ V_5 ] . V_276 ;
if ( ! V_271 && F_127 ( V_270 ) ) {
V_18 -> V_177 = F_128 ( V_270 -> V_278 ) ;
V_271 = V_270 -> V_279 ;
}
if ( ! V_272 && F_129 ( V_270 ) ) {
V_18 -> V_280 =
F_128 ( V_270 -> V_278 ) ;
V_272 = V_270 -> V_279 ;
}
}
if ( ! V_271 || ! V_272 ) {
F_22 ( & V_35 -> V_18 , L_79
L_80 ) ;
V_21 = - V_281 ;
goto error;
}
V_18 -> V_20 = F_115 ( V_18 -> V_177 , V_62 ) ;
V_18 -> V_37 = F_130 ( 0 , V_62 ) ;
V_18 -> V_44 = F_115 ( V_18 -> V_280 , V_62 ) ;
V_18 -> V_45 = F_130 ( 0 , V_62 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_44 ||
! V_18 -> V_37 || ! V_18 -> V_45 )
goto error;
F_131 ( V_18 -> V_37 , V_18 -> V_274 ,
F_132 ( V_18 -> V_274 , V_271 ) ,
NULL , 0 , NULL , V_18 ) ;
F_131 ( V_18 -> V_45 , V_18 -> V_274 ,
F_133 ( V_18 -> V_274 , V_272 ) ,
NULL , 0 ,
F_46 , V_18 ) ;
F_134 ( & V_18 -> V_28 , F_31 ) ;
F_134 ( & V_18 -> V_19 , F_15 ) ;
F_134 ( & V_18 -> V_230 , F_118 ) ;
F_134 ( & V_18 -> V_156 , F_77 ) ;
F_134 ( & V_18 -> V_171 , F_86 ) ;
V_18 -> V_27 = F_135 ( L_81 , 0 ) ;
if ( V_18 -> V_27 == NULL )
goto error;
F_136 ( & V_18 -> V_174 ) ;
V_18 -> V_174 . V_2 = ( unsigned long ) V_18 ;
V_18 -> V_174 . V_282 = F_81 ;
F_137 ( & V_18 -> V_196 ) ;
F_40 ( & V_18 -> V_52 ) ;
F_138 ( V_35 , V_18 ) ;
F_5 ( V_18 -> V_44 , V_283 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_43 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_177 ) ;
if ( V_21 )
goto V_284;
V_266 = (struct V_265 * )
F_17 ( V_18 -> V_20 ) ;
F_139 ( & V_18 -> V_35 -> V_18 , L_82
L_83 , V_266 -> V_285 , V_266 -> V_286 ) ;
V_18 -> V_214 = V_264 -> V_287 ;
switch ( V_18 -> V_214 ) {
case V_247 :
V_273 = V_288 ;
break;
case V_215 :
V_273 = V_289 ;
break;
default:
F_22 ( & V_18 -> V_35 -> V_18 , L_75 ,
V_18 -> V_214 ) ;
V_21 = - V_164 ;
goto V_284;
}
V_18 -> V_129 = F_140 ( & V_290 , V_273 ,
V_153 ,
V_155 ) ;
if ( ! V_18 -> V_129 )
goto V_284;
F_141 ( V_18 -> V_129 , & V_35 -> V_18 ) ;
F_142 ( V_18 -> V_129 , V_18 ) ;
V_21 = F_143 ( V_18 -> V_129 ) ;
if ( V_21 )
goto V_291;
V_21 = F_122 ( V_18 ) ;
if ( V_21 )
goto V_292;
return 0 ;
V_292:
F_144 ( V_18 -> V_129 ) ;
V_291:
F_145 ( V_18 -> V_129 ) ;
V_284:
F_146 ( V_18 -> V_27 ) ;
error:
F_37 ( V_18 -> V_20 ) ;
F_147 ( V_18 -> V_37 ) ;
F_37 ( V_18 -> V_44 ) ;
F_147 ( V_18 -> V_45 ) ;
F_37 ( V_18 ) ;
return V_21 ;
}
static void F_148 ( struct V_262 * V_35 )
{
struct V_17 * V_18 ;
struct V_50 * V_12 , * V_293 ;
V_18 = F_149 ( V_35 ) ;
F_138 ( V_35 , NULL ) ;
F_144 ( V_18 -> V_129 ) ;
F_145 ( V_18 -> V_129 ) ;
F_87 ( V_18 -> V_37 ) ;
F_87 ( V_18 -> V_45 ) ;
F_146 ( V_18 -> V_27 ) ;
F_97 ( & V_18 -> V_196 ) ;
F_83 ( & V_18 -> V_174 ) ;
F_150 (cmd, n, &dev->cmd_queue, queue) {
F_36 ( & V_12 -> V_54 ) ;
F_37 ( V_12 ) ;
}
F_37 ( V_18 -> V_20 ) ;
F_147 ( V_18 -> V_37 ) ;
F_37 ( V_18 -> V_44 ) ;
F_147 ( V_18 -> V_45 ) ;
F_37 ( V_18 ) ;
F_139 ( & V_35 -> V_18 , L_84 ) ;
}
