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
F_19 ( & V_18 -> V_27 ) ;
}
static void F_20 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
struct V_6 * V_20 ;
V_18 -> V_22 = NULL ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
}
V_20 = V_18 -> V_36 -> V_37 ;
if ( ! F_11 ( V_20 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_5 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
if ( ! F_13 ( V_20 , V_18 -> V_12 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_6
L_7 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_8 ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_22 = V_20 ;
V_35:
F_23 ( V_18 -> V_39 , & V_18 -> V_19 ) ;
}
static int F_24 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_36 -> V_41 = F_20 ;
return F_25 ( V_18 -> V_36 , V_40 ) ;
}
static void F_26 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
struct V_6 * V_20 ;
int V_21 ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
V_18 -> V_23 = V_28 -> V_30 ;
goto V_35;
}
V_20 = V_18 -> V_36 -> V_37 ;
if ( ! F_12 ( V_20 ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_9 ) ;
V_18 -> V_23 = - V_38 ;
goto V_35;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_10 ) ;
V_21 = F_24 ( V_18 , V_42 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_11
L_12 , V_21 ) ;
V_18 -> V_23 = V_21 ;
goto V_35;
}
return;
V_35:
V_18 -> V_22 = NULL ;
F_23 ( V_18 -> V_39 , & V_18 -> V_19 ) ;
}
static int F_27 ( struct V_17 * V_18 , T_2 V_40 )
{
V_18 -> V_36 -> V_41 = F_26 ;
return F_25 ( V_18 -> V_36 , V_40 ) ;
}
static int F_28 ( struct V_17 * V_18 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_3 ( V_18 -> V_44 ) ;
V_18 -> V_45 -> V_37 = V_18 -> V_44 ;
V_18 -> V_45 -> V_46 = V_47 ;
V_21 = F_25 ( V_18 -> V_45 , V_40 ) ;
return V_21 ;
}
static int F_29 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_14 ,
F_7 ( V_44 ) ) ;
V_18 -> V_12 = F_7 ( V_44 ) ;
V_18 -> V_24 = V_24 ;
V_18 -> V_25 = V_49 ;
V_18 -> V_45 -> V_37 = V_44 ;
V_18 -> V_45 -> V_46 =
F_30 ( V_44 ) ;
V_18 -> V_36 -> V_37 = V_20 ;
V_18 -> V_36 -> V_46 = V_48 ;
V_21 = F_25 ( V_18 -> V_45 , V_40 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_27 ( V_18 , V_40 ) ;
if ( V_21 )
goto error;
return 0 ;
error:
F_31 ( V_18 -> V_45 ) ;
return V_21 ;
}
static int F_32 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 ,
T_3 V_24 ,
void * V_49 , T_2 V_40 )
{
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! F_33 ( & V_18 -> V_27 ) )
return - V_50 ;
V_21 = F_29 ( V_18 , V_44 , V_20 ,
V_48 , V_24 , V_49 , V_40 ) ;
if ( V_21 )
goto error;
return 0 ;
error:
F_19 ( & V_18 -> V_27 ) ;
return V_21 ;
}
static int F_34 ( struct V_17 * V_18 , void * V_51 ,
T_1 * V_52 , int V_53 )
{
struct V_54 * V_49 = V_51 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_49 -> V_21 = 0 ;
if ( V_53 < 0 )
V_49 -> V_21 = V_53 ;
V_41 ( & V_49 -> V_55 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 ,
struct V_6 * V_44 ,
struct V_6 * V_20 ,
int V_48 )
{
int V_21 ;
struct V_54 V_49 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_36 ( & V_49 . V_55 ) ;
V_21 = F_32 ( V_18 , V_44 , V_20 , V_48 ,
F_34 , & V_49 , V_56 ) ;
if ( V_21 )
return V_21 ;
F_37 ( & V_49 . V_55 ) ;
return V_49 . V_21 ;
}
static void F_38 ( struct V_28 * V_28 )
{
struct V_17 * V_18 = V_28 -> V_29 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
switch ( V_28 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_21 ( & V_18 -> V_34 -> V_18 , L_1
L_2 , V_28 -> V_30 ) ;
break;
default:
F_21 ( & V_18 -> V_34 -> V_18 , L_3
L_4 , V_28 -> V_30 ) ;
}
}
static bool F_39 ( struct V_57 * V_58 ,
int V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_59 < sizeof( struct V_57 ) )
return false ;
V_60 = F_40 ( V_58 -> V_62 ) ;
V_61 = F_41 ( V_58 -> V_62 ) ;
if ( ( V_60 == V_63 &&
V_61 != V_64 ) ||
( V_60 != V_63 &&
V_61 == V_64 ) )
return false ;
if ( F_42 ( V_58 -> V_65 ) != 0 )
return false ;
return true ;
}
static int F_43 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_57 * V_70 ;
V_70 = (struct V_57 * ) V_68 ;
if ( ! F_39 ( V_70 , V_69 ) )
return - V_71 ;
switch ( F_44 ( V_70 -> V_65 ) ) {
case V_72 :
V_67 -> V_73 = V_74 ;
break;
case V_75 :
V_67 -> V_73 = V_76 ;
break;
case V_77 :
V_67 -> V_73 = V_78 ;
break;
case V_79 :
V_67 -> V_73 = V_76 |
V_78 ;
break;
}
V_67 -> V_62 = F_45 ( V_70 -> V_62 ) ;
V_67 -> V_65 = V_70 -> V_65 ;
V_67 -> V_80 = V_70 -> V_81 ;
memcpy ( V_67 -> V_82 , V_70 -> V_83 , V_67 -> V_80 ) ;
return 0 ;
}
static bool F_46 ( struct V_84 * V_85 ,
int V_59 )
{
if ( V_59 < sizeof( struct V_84 ) )
return false ;
if ( V_85 -> V_86 != V_87 )
return false ;
return true ;
}
static int F_47 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_84 * V_88 ;
V_88 = (struct V_84 * ) V_68 ;
if ( ! F_46 ( V_88 , V_69 ) )
return - V_71 ;
if ( V_88 -> V_89 [ 0 ] == V_90 &&
V_88 -> V_89 [ 1 ] ==
V_91 )
V_67 -> V_73 = V_78 ;
else
V_67 -> V_73 = V_92 ;
memcpy ( V_67 -> V_93 , & V_88 -> V_86 , 9 ) ;
V_67 -> V_94 = 9 ;
return 0 ;
}
static bool F_48 ( struct V_95 * V_96 ,
int V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_59 < sizeof( struct V_95 ) )
return false ;
V_60 = F_40 ( V_96 -> V_62 ) ;
V_61 = F_41 ( V_96 -> V_62 ) ;
if ( ( V_60 == V_63 &&
V_61 != V_64 ) ||
( V_60 != V_63 &&
V_61 == V_64 ) )
return false ;
return true ;
}
static int F_49 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_95 * V_97 ;
V_97 = (struct V_95 * ) V_68 ;
if ( ! F_48 ( V_97 , V_69 ) )
return - V_71 ;
V_67 -> V_73 = V_98 ;
V_67 -> V_62 = F_45 ( V_97 -> V_62 ) ;
V_67 -> V_80 = 4 ;
memcpy ( V_67 -> V_82 , V_97 -> V_99 , V_67 -> V_80 ) ;
return 0 ;
}
static bool F_50 ( struct V_100 * V_101 ,
int V_59 )
{
if ( V_59 < sizeof( struct V_100 ) )
return false ;
if ( V_101 -> V_102 . V_86 != V_103 )
return false ;
if ( F_51 ( V_101 -> V_102 . V_104 . V_105 ) &
V_106 )
return false ;
return true ;
}
static int F_52 ( struct V_66 * V_67 , T_1 * V_68 ,
int V_69 )
{
struct V_100 * V_107 ;
V_107 = (struct V_100 * ) V_68 ;
if ( ! F_50 ( V_107 , V_69 ) )
return - V_71 ;
V_67 -> V_73 = V_108 ;
return 0 ;
}
static int F_53 ( struct V_17 * V_18 ,
struct V_109 * V_110 , int V_111 )
{
int V_59 ;
struct V_66 V_67 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_15 , V_43 ,
V_18 -> V_112 ) ;
if ( V_110 -> V_113 != 1 )
return - V_71 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_59 = V_111 - sizeof( struct V_109 ) ;
switch ( V_18 -> V_112 ) {
case V_114 :
V_21 = F_43 ( & V_67 , V_110 -> V_115 ,
V_59 ) ;
break;
case V_116 :
case V_117 :
V_21 = F_47 ( & V_67 , V_110 -> V_115 ,
V_59 ) ;
break;
case V_118 :
V_21 = F_49 ( & V_67 , V_110 -> V_115 ,
V_59 ) ;
break;
case V_119 :
V_21 = F_52 ( & V_67 , V_110 -> V_115 ,
V_59 ) ;
break;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_16
L_17 ) ;
return - V_71 ;
}
if ( V_21 )
return V_21 ;
if ( ! ( V_67 . V_73 & V_18 -> V_120 ) ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_18
L_19 ) ;
return - V_121 ;
}
F_21 ( & V_18 -> V_34 -> V_18 , L_20
L_21 , V_67 . V_73 ) ;
V_18 -> V_122 = V_67 . V_73 ;
F_54 ( V_18 -> V_123 , & V_67 , 1 ) ;
return 0 ;
}
static inline void F_55 ( struct V_17 * V_18 )
{
V_18 -> V_112 = ( V_18 -> V_112 + 1 ) % V_18 -> V_124 ;
}
static void F_56 ( struct V_17 * V_18 )
{
V_18 -> V_124 = 0 ;
}
static void F_57 ( struct V_17 * V_18 , T_1 V_125 )
{
V_18 -> V_126 [ V_18 -> V_124 ] =
(struct V_127 * ) & V_128 [ V_125 ] ;
V_18 -> V_124 ++ ;
}
static void F_58 ( struct V_17 * V_18 ,
T_4 V_129 , T_4 V_130 )
{
F_56 ( V_18 ) ;
if ( V_129 & V_74
|| V_129 & V_76
|| V_129 & V_78 )
F_57 ( V_18 , V_114 ) ;
if ( V_129 & V_92
|| V_129 & V_78 ) {
F_57 ( V_18 , V_116 ) ;
F_57 ( V_18 , V_117 ) ;
}
if ( V_129 & V_98 )
F_57 ( V_18 , V_118 ) ;
if ( V_129 & V_108 )
F_57 ( V_18 , V_119 ) ;
if ( V_130 )
F_57 ( V_18 , V_131 ) ;
}
static int F_59 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_109 * V_110 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_110 = (struct V_109 * ) V_52 ;
if ( V_110 -> V_132 ) {
V_21 = F_53 ( V_18 , V_110 , V_53 ) ;
if ( V_21 == 0 ) {
F_56 ( V_18 ) ;
return 0 ;
}
}
return - V_121 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_1 * V_133 , T_5 V_134 )
{
struct V_135 * V_12 ;
T_5 V_136 ;
T_1 V_137 [ 18 ] = { 0x1 , 0xfe ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x0 ,
0xff , 0xff } ;
T_1 V_138 [ 6 ] = { 0x1 , 0x1 ,
0x0 , 0x0 , 0x0 ,
0x40 } ;
V_136 = sizeof( struct V_135 ) + V_134 + 1 ;
V_12 = F_61 ( V_136 , V_56 ) ;
if ( V_12 == NULL )
return - V_139 ;
F_5 ( V_7 , V_140 ) ;
V_12 -> V_141 |= V_142 ;
memcpy ( V_12 -> V_85 , V_137 , 18 ) ;
F_62 ( V_12 -> V_85 + 2 , 6 ) ;
memset ( V_12 -> V_143 , 0 , 10 ) ;
memcpy ( V_12 -> V_143 , V_12 -> V_85 , 8 ) ;
memcpy ( V_12 -> V_144 , V_138 , 6 ) ;
V_12 -> V_134 = V_134 ;
memcpy ( V_12 -> V_133 , V_133 , V_134 ) ;
V_12 -> V_133 [ V_134 ] = 0 ;
memcpy ( F_17 ( V_7 ) , V_12 , V_136 ) ;
V_7 -> V_3 += V_136 ;
F_8 ( V_7 ) ;
F_63 ( V_12 ) ;
return 0 ;
}
static int F_64 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_145 * V_146 = V_49 ;
struct V_6 * V_20 = (struct V_6 * ) V_146 -> V_2 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_22 ,
V_53 ) ;
return V_53 ;
}
if ( V_53 > 0 && V_52 [ 0 ] != 0 ) {
F_65 ( V_18 -> V_123 ) ;
V_18 -> V_147 = 0 ;
F_66 ( V_146 ) ;
return 0 ;
}
F_67 ( V_146 , F_30 ( V_20 ) ) ;
F_68 ( V_146 , V_148 ) ;
F_69 ( V_146 , V_146 -> V_149 - V_150 ) ;
return F_70 ( V_18 -> V_123 , V_146 ) ;
}
static void F_71 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_151 ) ;
struct V_6 * V_20 ;
struct V_145 * V_146 ;
T_5 V_152 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_152 = V_148 +
V_153 +
V_150 ;
V_146 = F_72 ( V_152 , V_56 ) ;
if ( ! V_146 )
return;
V_20 = (struct V_6 * ) V_146 -> V_2 ;
F_5 ( V_18 -> V_44 , V_154 ) ;
F_8 ( V_18 -> V_44 ) ;
F_32 ( V_18 , V_18 -> V_44 , V_20 ,
V_152 ,
F_64 ,
V_146 , V_56 ) ;
return;
}
static int F_73 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_155 * V_110 ;
T_1 V_7 , V_156 = V_157 , * V_133 ;
T_5 V_134 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_22 ,
V_53 ) ;
return V_53 ;
}
if ( V_53 < V_158 + 1 )
return - V_159 ;
V_110 = (struct V_155 * ) V_52 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_23 ,
V_110 -> V_141 , V_53 ) ;
V_7 = V_110 -> V_141 & V_160 ;
if ( V_7 == V_161 )
V_156 = V_162 ;
if ( ( V_110 -> V_141 & V_163 ) == 0 )
return - V_164 ;
V_133 = V_110 -> V_12 + V_158 ;
V_134 = V_53 - ( V_158 + 1 ) ;
V_21 = F_74 ( V_18 -> V_123 , V_78 ,
V_156 , V_133 , V_134 ) ;
if ( V_21 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_24 ) ;
return V_21 ;
}
V_18 -> V_147 = 1 ;
F_23 ( V_18 -> V_39 , & V_18 -> V_151 ) ;
return 0 ;
}
static void F_75 ( unsigned long V_2 )
{
struct V_17 * V_18 = (struct V_17 * ) V_2 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_25 ) ;
F_28 ( V_18 , V_42 ) ;
V_18 -> V_165 = 1 ;
F_19 ( & V_18 -> V_27 ) ;
F_55 ( V_18 ) ;
F_23 ( V_18 -> V_39 , & V_18 -> V_166 ) ;
}
static int F_76 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_127 * V_167 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_53 == - V_32 ) {
if ( V_18 -> V_124 != 0 )
return 0 ;
F_22 ( & V_18 -> V_34 -> V_18 ,
L_26 ) ;
goto V_168;
}
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_27 , V_53 ) ;
goto V_168;
}
V_167 = V_18 -> V_126 [ V_18 -> V_112 ] ;
if ( V_167 -> V_149 == 0 ) {
F_77 ( & V_18 -> V_169 ) ;
return F_73 ( V_18 , V_49 , V_52 , V_53 ) ;
} else {
V_21 = F_59 ( V_18 , V_49 , V_52 , V_53 ) ;
if ( ! V_21 )
return V_21 ;
}
F_55 ( V_18 ) ;
F_23 ( V_18 -> V_39 , & V_18 -> V_166 ) ;
return 0 ;
V_168:
F_56 ( V_18 ) ;
V_18 -> V_120 = 0 ;
return 0 ;
}
static void F_78 ( struct V_17 * V_18 ,
struct V_6 * V_7 ,
struct V_127 * V_170 )
{
F_21 ( & V_18 -> V_34 -> V_18 , L_28 , V_170 -> V_149 ) ;
if ( V_170 -> V_149 == 0 ) {
F_60 ( V_7 , V_18 -> V_133 , V_18 -> V_134 ) ;
} else {
F_5 ( V_7 , V_171 ) ;
memcpy ( F_17 ( V_7 ) , & V_170 -> V_2 , V_170 -> V_149 ) ;
V_7 -> V_3 += V_170 -> V_149 ;
F_8 ( V_7 ) ;
}
}
static int F_79 ( struct V_17 * V_18 )
{
struct V_127 * V_167 ;
int V_21 ;
V_167 = V_18 -> V_126 [ V_18 -> V_112 ] ;
F_78 ( V_18 , V_18 -> V_44 , V_167 ) ;
V_21 = F_32 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 , F_76 ,
NULL , V_56 ) ;
if ( V_21 )
F_22 ( & V_18 -> V_34 -> V_18 , L_29 , V_21 ) ;
return V_21 ;
}
static void F_80 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_166 ) ;
struct V_127 * V_167 ;
int V_21 ;
V_167 = V_18 -> V_126 [ V_18 -> V_112 ] ;
F_21 ( & V_18 -> V_34 -> V_18 ,
L_30 ,
V_43 , V_18 -> V_165 , V_167 -> V_149 ) ;
if ( V_18 -> V_165 == 1 ) {
V_18 -> V_165 = 0 ;
F_81 ( V_18 -> V_36 ) ;
}
V_21 = F_79 ( V_18 ) ;
if ( V_21 )
return;
if ( V_167 -> V_149 == 0 && V_18 -> V_124 > 1 )
F_82 ( & V_18 -> V_169 , V_173 + V_174 * V_175 ) ;
return;
}
static int F_83 ( struct V_123 * V_123 ,
T_4 V_129 , T_4 V_130 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
F_21 ( & V_18 -> V_34 -> V_18 ,
L_31 ,
V_43 , V_129 , V_130 ) ;
if ( V_18 -> V_176 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_32 ) ;
return - V_50 ;
}
if ( V_18 -> V_147 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_33 ) ;
return - V_50 ;
}
if ( V_130 ) {
V_18 -> V_133 = F_85 ( V_123 , & V_18 -> V_134 ) ;
if ( V_18 -> V_133 == NULL )
V_130 = 0 ;
}
V_18 -> V_112 = 0 ;
F_58 ( V_18 , V_129 , V_130 ) ;
V_18 -> V_120 = V_129 ;
V_18 -> V_177 = V_130 ;
return F_79 ( V_18 ) ;
}
static void F_86 ( struct V_123 * V_123 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_77 ( & V_18 -> V_169 ) ;
if ( ! V_18 -> V_124 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_34
L_35 ) ;
return;
}
F_28 ( V_18 , V_56 ) ;
F_81 ( V_18 -> V_36 ) ;
F_56 ( V_18 ) ;
}
static int F_87 ( struct V_17 * V_18 )
{
struct V_178 V_179 ;
struct V_180 * V_110 ;
T_6 V_181 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_182 ) ;
V_179 . V_113 = 1 ;
V_179 . V_183 = 0 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_179 ,
sizeof( struct V_178 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( struct V_178 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 ) ;
if ( V_21 )
return V_21 ;
V_110 = (struct V_180 * )
F_17 ( V_18 -> V_20 ) ;
V_21 = V_110 -> V_30 & V_184 ;
if ( V_21 != V_185 )
return - V_38 ;
V_181 = F_18 ( V_18 -> V_20 ) - 16 ;
V_21 = F_88 ( V_18 -> V_123 , V_110 -> V_186 , V_181 ) ;
return V_21 ;
}
static int F_89 ( struct V_123 * V_123 ,
struct V_66 * V_187 , T_4 V_188 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_36 , V_43 ,
V_188 ) ;
if ( V_18 -> V_124 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_37
L_38 ) ;
return - V_50 ;
}
if ( V_18 -> V_176 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_39
L_40 ) ;
return - V_50 ;
}
if ( ! V_18 -> V_122 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_41
L_42 ) ;
return - V_159 ;
}
if ( ! ( V_18 -> V_122 & ( 1 << V_188 ) ) ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_43
L_44 , V_188 ) ;
return - V_159 ;
}
if ( V_188 == V_189 ) {
V_21 = F_87 ( V_18 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_45
L_46
L_47 , V_21 ) ;
return V_21 ;
}
}
V_18 -> V_176 = V_188 ;
V_18 -> V_122 = 0 ;
return 0 ;
}
static void F_90 ( struct V_123 * V_123 ,
struct V_66 * V_187 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
T_1 V_113 ;
T_1 V_30 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_176 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_48 ) ;
return;
}
V_18 -> V_176 = 0 ;
F_91 ( & V_18 -> V_190 ) ;
F_5 ( V_18 -> V_44 , V_191 ) ;
V_113 = 1 ;
memcpy ( F_17 ( V_18 -> V_44 ) , & V_113 , sizeof( T_1 ) ) ;
V_18 -> V_44 -> V_3 += sizeof( T_1 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_49
L_50 ) ;
return;
}
V_30 = F_17 ( V_18 -> V_20 ) [ 0 ] ;
V_21 = V_30 & V_184 ;
if ( V_21 != V_185 )
F_22 ( & V_18 -> V_34 -> V_18 , L_51
L_52 , V_21 ) ;
return;
}
static int F_92 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
struct V_192 * V_12 ;
struct V_193 * V_110 ;
struct V_66 V_66 ;
T_1 V_194 ;
int V_21 ;
if ( V_53 == - V_32 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_53 ) ;
return 0 ;
}
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_54 ,
V_53 ) ;
return 0 ;
}
if ( V_18 -> V_122 &&
! ( V_18 -> V_122 & ( 1 << V_189 ) ) ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_55 ) ;
return - V_159 ;
}
V_110 = (struct V_193 * ) V_52 ;
V_12 = (struct V_192 * ) V_49 ;
V_21 = V_110 -> V_30 & V_184 ;
if ( V_21 != V_185 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_56 , V_21 ) ;
return 0 ;
}
if ( ! V_18 -> V_122 ) {
F_21 ( & V_18 -> V_34 -> V_18 , L_57 ) ;
V_66 . V_73 = V_78 ;
V_66 . V_80 = 10 ;
memcpy ( V_66 . V_82 , V_110 -> V_195 , V_66 . V_80 ) ;
V_21 = F_54 ( V_18 -> V_123 , & V_66 , 1 ) ;
if ( V_21 )
return 0 ;
V_18 -> V_122 = 0 ;
}
V_18 -> V_176 = V_189 ;
V_194 = F_18 ( V_18 -> V_20 ) - 17 ;
V_21 = F_88 ( V_18 -> V_123 ,
V_110 -> V_186 , V_194 ) ;
if ( V_21 == 0 )
V_21 = F_93 ( V_18 -> V_123 ,
V_18 -> V_123 -> V_196 [ 0 ] . V_197 ,
! V_12 -> V_198 , V_199 ) ;
return 0 ;
}
static int F_94 ( struct V_17 * V_18 )
{
switch ( V_18 -> V_112 ) {
case V_114 :
return 0 ;
case V_116 :
return 1 ;
case V_117 :
return 2 ;
default:
return - V_159 ;
}
}
static int F_95 ( struct V_123 * V_123 , struct V_66 * V_187 ,
T_1 V_156 , T_1 * V_133 , T_5 V_134 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
struct V_192 * V_12 ;
T_1 V_136 , * V_200 ;
T_1 V_201 [ V_202 ] = { 0x00 , 0xff , 0xff , 0x00 , 0x3 } ;
int V_21 , V_203 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_18 -> V_124 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_58 ) ;
return - V_50 ;
}
if ( V_18 -> V_176 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_59 ) ;
return - V_50 ;
}
V_203 = F_94 ( V_18 ) ;
if ( V_203 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_60 , V_18 -> V_112 ) ;
return V_203 ;
}
V_136 = sizeof( struct V_192 ) + V_134 ;
if ( V_156 == V_157 )
V_136 += V_202 ;
V_12 = F_61 ( V_136 , V_56 ) ;
if ( V_12 == NULL )
return - V_139 ;
F_5 ( V_18 -> V_44 , V_204 ) ;
V_12 -> V_198 = ! V_156 ;
V_12 -> V_183 = 0 ;
V_12 -> V_203 = V_203 ;
V_200 = V_12 -> V_2 ;
if ( V_156 == V_157 && V_12 -> V_203 > 0 ) {
memcpy ( V_200 , V_201 , V_202 ) ;
V_12 -> V_183 |= 1 ;
V_200 += V_202 ;
}
if ( V_133 != NULL && V_134 > 0 ) {
V_12 -> V_183 |= 4 ;
memcpy ( V_200 , V_133 , V_134 ) ;
} else {
V_12 -> V_183 = 0 ;
}
memcpy ( F_17 ( V_18 -> V_44 ) , V_12 , V_136 ) ;
V_18 -> V_44 -> V_3 += V_136 ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_32 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 , F_92 ,
V_12 , V_56 ) ;
if ( V_21 )
goto V_205;
V_205:
F_63 ( V_12 ) ;
return V_21 ;
}
static int F_96 ( struct V_123 * V_123 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
F_56 ( V_18 ) ;
if ( V_18 -> V_147 || V_18 -> V_176 ) {
F_28 ( V_18 , V_56 ) ;
F_81 ( V_18 -> V_36 ) ;
}
V_18 -> V_176 = 0 ;
V_18 -> V_147 = 0 ;
F_91 ( & V_18 -> V_190 ) ;
return 0 ;
}
static int F_97 ( struct V_17 * V_18 , struct V_145 * V_206 ,
bool V_187 )
{
int V_207 = V_206 -> V_149 ;
struct V_6 * V_44 ;
T_1 V_113 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_61 , V_43 ,
V_207 ) ;
if ( V_207 > V_153 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_62
L_63 ,
V_153 ) ;
return - V_208 ;
}
if ( V_187 == true ) {
switch ( V_18 -> V_209 ) {
case V_210 :
if ( V_18 -> V_176 == V_211 ) {
F_98 ( V_206 , V_148 - 1 ) ;
V_44 = (struct V_6 * ) V_206 -> V_2 ;
F_5 ( V_44 ,
V_212 ) ;
break;
}
default:
F_98 ( V_206 , V_148 ) ;
V_44 = (struct V_6 * ) V_206 -> V_2 ;
F_5 ( V_44 ,
V_213 ) ;
V_113 = 1 ;
memcpy ( F_17 ( V_44 ) ,
& V_113 , sizeof( T_1 ) ) ;
V_44 -> V_3 += sizeof( T_1 ) ;
break;
}
} else {
F_98 ( V_206 , V_148 - 1 ) ;
V_44 = (struct V_6 * ) V_206 -> V_2 ;
F_5 ( V_44 , V_214 ) ;
}
V_44 -> V_3 += V_207 ;
F_8 ( V_44 ) ;
F_67 ( V_206 , V_150 ) ;
return 0 ;
}
static struct V_145 * F_99 ( struct V_17 * V_18 )
{
struct V_145 * V_206 , * V_215 , * V_216 ;
unsigned int V_217 = 0 , V_218 = 0 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_64 , V_43 ) ;
if ( F_100 ( & V_18 -> V_190 ) )
return NULL ;
if ( F_101 ( & V_18 -> V_190 ) == 1 ) {
V_206 = F_102 ( & V_18 -> V_190 ) ;
goto V_205;
}
F_103 (&dev->resp_q, tmp, t)
V_217 += V_215 -> V_149 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_65 ,
V_43 , V_217 ) ;
V_206 = F_104 ( V_217 , V_56 ) ;
if ( V_206 == NULL )
goto V_205;
F_67 ( V_206 , V_217 ) ;
F_103 (&dev->resp_q, tmp, t) {
memcpy ( V_206 -> V_2 + V_218 , V_215 -> V_2 , V_215 -> V_149 ) ;
V_218 += V_215 -> V_149 ;
}
V_205:
F_91 ( & V_18 -> V_190 ) ;
return V_206 ;
}
static int F_105 ( struct V_17 * V_18 , void * V_51 ,
T_1 * V_52 , int V_53 )
{
struct V_219 * V_49 = V_51 ;
struct V_145 * V_206 = NULL , * V_146 = V_49 -> V_146 ;
struct V_6 * V_20 = (struct V_6 * ) V_146 -> V_2 ;
int V_220 = 0 ;
T_1 V_30 ;
T_1 V_221 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_106 ( V_49 -> V_222 ) ;
if ( V_53 < 0 ) {
V_220 = V_53 ;
goto error;
}
V_30 = V_52 [ 0 ] ;
V_221 = V_30 & V_184 ;
if ( V_221 != V_185 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_66
L_67 , V_221 ) ;
V_220 = - V_38 ;
goto error;
}
F_67 ( V_146 , F_30 ( V_20 ) ) ;
F_68 ( V_146 , V_148 ) ;
F_69 ( V_146 , V_146 -> V_149 - V_150 ) ;
F_107 ( & V_18 -> V_190 , V_146 ) ;
if ( V_30 & V_223 ) {
F_23 ( V_18 -> V_39 , & V_18 -> V_224 ) ;
return - V_26 ;
}
V_206 = F_99 ( V_18 ) ;
if ( V_206 == NULL )
goto error;
V_49 -> V_225 ( V_49 -> V_226 , V_206 , 0 ) ;
F_63 ( V_49 ) ;
return 0 ;
error:
F_91 ( & V_18 -> V_190 ) ;
F_106 ( V_146 ) ;
V_49 -> V_225 ( V_49 -> V_226 , NULL , V_220 ) ;
F_63 ( V_49 ) ;
return 0 ;
}
static int F_108 ( struct V_123 * V_123 ,
struct V_66 * V_187 , struct V_145 * V_206 ,
T_7 V_225 , void * V_226 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
struct V_6 * V_44 , * V_20 ;
struct V_219 * V_49 ;
struct V_145 * V_146 ;
int V_152 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( ! V_18 -> V_176 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_68
L_69 ) ;
V_21 = - V_159 ;
goto error;
}
V_21 = F_97 ( V_18 , V_206 , true ) ;
if ( V_21 )
goto error;
V_152 = V_148 +
V_153 +
V_150 ;
V_146 = F_72 ( V_152 , V_56 ) ;
if ( ! V_146 ) {
V_21 = - V_139 ;
goto error;
}
V_20 = (struct V_6 * ) V_146 -> V_2 ;
V_44 = (struct V_6 * ) V_206 -> V_2 ;
V_49 = F_109 ( sizeof( struct V_219 ) , V_56 ) ;
if ( ! V_49 ) {
V_21 = - V_139 ;
goto V_227;
}
V_49 -> V_146 = V_146 ;
V_49 -> V_222 = V_206 ;
V_49 -> V_225 = V_225 ;
V_49 -> V_226 = V_226 ;
V_21 = F_32 ( V_18 , V_44 , V_20 , V_152 ,
F_105 , V_49 ,
V_56 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 , L_70
L_71 , V_21 ) ;
goto V_228;
}
return 0 ;
V_228:
F_63 ( V_49 ) ;
V_227:
F_66 ( V_146 ) ;
error:
F_66 ( V_206 ) ;
return V_21 ;
}
static int F_110 ( struct V_17 * V_18 , void * V_49 ,
T_1 * V_52 , int V_53 )
{
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
if ( V_53 < 0 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_72 ,
V_53 ) ;
return V_53 ;
}
if ( V_53 > 0 && V_52 [ 0 ] != 0 ) {
F_65 ( V_18 -> V_123 ) ;
V_18 -> V_147 = 0 ;
return 0 ;
}
F_23 ( V_18 -> V_39 , & V_18 -> V_151 ) ;
return 0 ;
}
static int F_111 ( struct V_123 * V_123 , struct V_145 * V_206 )
{
struct V_17 * V_18 = F_84 ( V_123 ) ;
struct V_6 * V_44 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_21 = F_97 ( V_18 , V_206 , false ) ;
if ( V_21 )
goto error;
V_44 = (struct V_6 * ) V_206 -> V_2 ;
V_21 = F_32 ( V_18 , V_44 , V_18 -> V_20 ,
V_18 -> V_172 , F_110 ,
NULL , V_56 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_73 , V_21 ) ;
goto error;
}
return 0 ;
error:
F_66 ( V_206 ) ;
return V_21 ;
}
static void F_112 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_16 ( V_16 , struct V_17 , V_224 ) ;
struct V_145 * V_229 ;
struct V_219 * V_49 = V_18 -> V_25 ;
struct V_6 * V_44 , * V_20 ;
struct V_145 * V_146 ;
int V_152 ;
int V_21 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
V_229 = F_104 ( V_148 + V_150 ,
V_56 ) ;
if ( V_229 == NULL )
goto V_230;
F_113 ( V_229 , V_148 ) ;
V_21 = F_97 ( V_18 , V_229 , true ) ;
if ( V_21 )
goto V_231;
V_152 = V_148 +
V_153 +
V_150 ;
V_146 = F_104 ( V_152 , V_56 ) ;
if ( ! V_146 ) {
V_21 = - V_139 ;
goto V_231;
}
V_20 = (struct V_6 * ) V_146 -> V_2 ;
V_44 = (struct V_6 * ) V_229 -> V_2 ;
V_49 -> V_146 = V_146 ;
V_49 -> V_222 = V_229 ;
V_21 = F_29 ( V_18 , V_44 , V_20 ,
V_152 ,
F_105 ,
V_18 -> V_25 , V_56 ) ;
if ( ! V_21 )
return;
F_22 ( & V_18 -> V_34 -> V_18 , L_70
L_71 , V_21 ) ;
F_66 ( V_146 ) ;
V_231:
F_66 ( V_229 ) ;
V_230:
F_28 ( V_18 , V_56 ) ;
F_63 ( V_49 ) ;
F_19 ( & V_18 -> V_27 ) ;
}
static int F_114 ( struct V_17 * V_18 , T_1 V_232 , T_1 * V_233 ,
T_1 V_234 )
{
int V_21 ;
T_1 * V_52 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , V_235 ) ;
V_52 = F_17 ( V_18 -> V_44 ) ;
V_52 [ 0 ] = V_232 ;
memcpy ( & V_52 [ 1 ] , V_233 , V_234 ) ;
V_18 -> V_44 -> V_3 += ( 1 + V_234 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 ) ;
return V_21 ;
}
static int F_115 ( struct V_17 * V_18 )
{
int V_21 ;
T_1 * V_52 ;
F_21 ( & V_18 -> V_34 -> V_18 , L_13 , V_43 ) ;
F_5 ( V_18 -> V_44 , 0x18 ) ;
V_52 = F_17 ( V_18 -> V_44 ) ;
V_52 [ 0 ] = 0x1 ;
V_18 -> V_44 -> V_3 += 1 ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 ) ;
return V_21 ;
}
static int F_116 ( struct V_17 * V_18 )
{
struct V_236 V_237 ;
struct V_238 V_239 ;
T_1 V_240 [ 3 ] = { 0x08 , 0x01 , 0x08 } ;
int V_21 ;
switch ( V_18 -> V_209 ) {
case V_241 :
V_237 . V_242 = V_243 ;
V_237 . V_244 = 2 ;
V_237 . V_245 =
V_246 ;
V_239 . V_247 = V_248 ;
V_239 . V_249 = V_250 ;
V_239 . V_251 = V_252 ;
break;
case V_210 :
V_237 . V_242 = 0x2 ;
V_237 . V_244 = 0x1 ;
V_237 . V_245 =
V_246 ;
V_239 . V_247 = V_248 ;
V_239 . V_249 = V_248 ;
V_239 . V_251 = V_250 ;
break;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_74 ,
V_18 -> V_209 ) ;
return - V_159 ;
}
V_21 = F_114 ( V_18 , V_253 ,
( T_1 * ) & V_237 , sizeof( V_237 ) ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_75 ) ;
return V_21 ;
}
V_21 = F_114 ( V_18 , V_254 ,
( T_1 * ) & V_239 , sizeof( V_239 ) ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_76 ) ;
return V_21 ;
}
switch ( V_18 -> V_209 ) {
case V_241 :
break;
case V_210 :
F_115 ( V_18 ) ;
V_21 = F_114 ( V_18 , V_255 ,
V_240 , 3 ) ;
if ( V_21 ) {
F_22 ( & V_18 -> V_34 -> V_18 ,
L_77 ) ;
return V_21 ;
}
F_115 ( V_18 ) ;
break;
}
return 0 ;
}
static int F_117 ( struct V_256 * V_34 ,
const struct V_257 * V_258 )
{
struct V_259 * V_260 ;
struct V_17 * V_18 ;
struct V_261 * V_262 ;
struct V_263 * V_264 ;
int V_265 = 0 ;
int V_266 = 0 ;
int V_21 = - V_139 ;
int V_5 ;
T_4 V_267 ;
V_18 = F_61 ( sizeof( * V_18 ) , V_56 ) ;
if ( ! V_18 )
return - V_139 ;
V_18 -> V_268 = F_118 ( F_119 ( V_34 ) ) ;
V_18 -> V_34 = V_34 ;
F_120 ( & V_18 -> V_27 ) ;
V_262 = V_34 -> V_269 ;
for ( V_5 = 0 ; V_5 < V_262 -> V_270 . V_271 ; ++ V_5 ) {
V_264 = & V_262 -> V_264 [ V_5 ] . V_270 ;
if ( ! V_265 && F_121 ( V_264 ) ) {
V_18 -> V_172 = F_122 ( V_264 -> V_272 ) ;
V_265 = V_264 -> V_273 ;
}
if ( ! V_266 && F_123 ( V_264 ) ) {
V_18 -> V_274 =
F_122 ( V_264 -> V_272 ) ;
V_266 = V_264 -> V_273 ;
}
}
if ( ! V_265 || ! V_266 ) {
F_22 ( & V_34 -> V_18 , L_78
L_79 ) ;
V_21 = - V_275 ;
goto error;
}
V_18 -> V_20 = F_109 ( V_18 -> V_172 , V_56 ) ;
V_18 -> V_36 = F_124 ( 0 , V_56 ) ;
V_18 -> V_44 = F_109 ( V_18 -> V_274 , V_56 ) ;
V_18 -> V_45 = F_124 ( 0 , V_56 ) ;
if ( ! V_18 -> V_20 || ! V_18 -> V_44 ||
! V_18 -> V_36 || ! V_18 -> V_45 )
goto error;
F_125 ( V_18 -> V_36 , V_18 -> V_268 ,
F_126 ( V_18 -> V_268 , V_265 ) ,
NULL , 0 , NULL , V_18 ) ;
F_125 ( V_18 -> V_45 , V_18 -> V_268 ,
F_127 ( V_18 -> V_268 , V_266 ) ,
NULL , 0 ,
F_38 , V_18 ) ;
F_128 ( & V_18 -> V_19 , F_15 ) ;
F_128 ( & V_18 -> V_224 , F_112 ) ;
F_128 ( & V_18 -> V_151 , F_71 ) ;
F_128 ( & V_18 -> V_166 , F_80 ) ;
V_18 -> V_39 = F_129 ( L_80 ,
V_276 | V_277 | V_278 ,
1 ) ;
if ( V_18 -> V_39 == NULL )
goto error;
F_130 ( & V_18 -> V_169 ) ;
V_18 -> V_169 . V_2 = ( unsigned long ) V_18 ;
V_18 -> V_169 . V_279 = F_75 ;
F_131 ( & V_18 -> V_190 ) ;
F_132 ( V_34 , V_18 ) ;
F_5 ( V_18 -> V_44 , V_280 ) ;
F_8 ( V_18 -> V_44 ) ;
V_21 = F_35 ( V_18 , V_18 -> V_44 , V_18 -> V_20 ,
V_18 -> V_172 ) ;
if ( V_21 )
goto V_281;
V_260 = (struct V_259 * )
F_17 ( V_18 -> V_20 ) ;
F_133 ( & V_18 -> V_34 -> V_18 , L_81
L_82 , V_260 -> V_282 , V_260 -> V_283 ) ;
V_18 -> V_209 = V_258 -> V_284 ;
switch ( V_18 -> V_209 ) {
case V_241 :
V_267 = V_285 ;
break;
case V_210 :
V_267 = V_286 ;
break;
default:
F_22 ( & V_18 -> V_34 -> V_18 , L_74 ,
V_18 -> V_209 ) ;
V_21 = - V_159 ;
goto V_281;
}
V_18 -> V_123 = F_134 ( & V_287 , V_267 ,
V_148 ,
V_150 ) ;
if ( ! V_18 -> V_123 )
goto V_281;
F_135 ( V_18 -> V_123 , & V_34 -> V_18 ) ;
F_136 ( V_18 -> V_123 , V_18 ) ;
V_21 = F_137 ( V_18 -> V_123 ) ;
if ( V_21 )
goto V_288;
V_21 = F_116 ( V_18 ) ;
if ( V_21 )
goto V_289;
return 0 ;
V_289:
F_138 ( V_18 -> V_123 ) ;
V_288:
F_139 ( V_18 -> V_123 ) ;
V_281:
F_140 ( V_18 -> V_39 ) ;
error:
F_63 ( V_18 -> V_20 ) ;
F_141 ( V_18 -> V_36 ) ;
F_63 ( V_18 -> V_44 ) ;
F_141 ( V_18 -> V_45 ) ;
F_63 ( V_18 ) ;
return V_21 ;
}
static void F_142 ( struct V_256 * V_34 )
{
struct V_17 * V_18 ;
V_18 = F_143 ( V_34 ) ;
F_132 ( V_34 , NULL ) ;
F_138 ( V_18 -> V_123 ) ;
F_139 ( V_18 -> V_123 ) ;
F_81 ( V_18 -> V_36 ) ;
F_81 ( V_18 -> V_45 ) ;
F_140 ( V_18 -> V_39 ) ;
F_91 ( & V_18 -> V_190 ) ;
F_77 ( & V_18 -> V_169 ) ;
F_63 ( V_18 -> V_20 ) ;
F_141 ( V_18 -> V_36 ) ;
F_63 ( V_18 -> V_44 ) ;
F_141 ( V_18 -> V_45 ) ;
F_63 ( V_18 ) ;
F_133 ( & V_34 -> V_18 , L_83 ) ;
}
