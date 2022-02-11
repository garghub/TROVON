static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_3 ( struct V_4 * V_5 )
{
unsigned long V_6 ;
struct V_7 * V_8 = F_4 ( V_5 , struct V_7 ,
V_9 ) ;
F_5 ( & V_8 -> V_10 , V_6 ) ;
V_8 -> V_11 = V_8 -> V_12 ;
if ( V_8 -> V_13 == V_14 &&
V_8 -> V_11 == V_8 -> V_15 ) {
F_6 ( V_16 , L_1 ) ;
F_7 ( & V_8 -> V_17 ) ;
}
F_8 ( & V_8 -> V_10 , V_6 ) ;
F_9 ( & V_8 -> V_18 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
T_1 V_19 , V_20 , V_21 , V_22 ;
unsigned V_23 ;
unsigned long V_6 ;
T_1 V_24 ;
T_2 V_25 ;
struct V_26 * V_27 = V_8 -> V_27 ;
F_5 ( & V_8 -> V_10 , V_6 ) ;
V_25 = F_11 ( F_12 ( F_13 () ,
V_8 -> V_28 ) ) ;
if ( V_25 > 20 * V_29 ) {
T_1 V_30 ;
V_30 = F_14 ( V_25 , V_29 ) / V_31 ;
F_15 ( V_32 L_2
L_3 , V_25 , V_30 ) ;
}
if ( V_8 -> V_11 == V_8 -> V_12 ) {
F_8 ( & V_8 -> V_10 , V_6 ) ;
return - 1 ;
}
if ( V_8 -> V_13 == V_33 ) {
F_6 ( V_16 , L_4 ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
return - 1 ;
}
V_19 = V_8 -> V_34 . V_35 ;
V_20 = V_8 -> V_34 . V_36 ;
V_21 = V_8 -> V_34 . V_37 - V_19 ;
V_22 = V_8 -> V_34 . V_38 - V_20 ;
V_24 = V_8 -> V_24 ;
V_8 -> V_34 . V_35 = V_8 -> V_39 + 1 ;
V_8 -> V_34 . V_36 = V_8 -> V_40 + 1 ;
V_8 -> V_34 . V_37 = 0 ;
V_8 -> V_34 . V_38 = 0 ;
if ( F_16 ( V_21 > V_8 -> V_39 || V_22 > V_8 -> V_40 ||
V_21 == 0 || V_22 == 0 ) ) {
F_15 ( V_41 L_5
L_6 , V_19 , V_20 , V_21 , V_22 ) ;
V_8 -> V_11 = V_8 -> V_12 ;
goto error;
}
F_8 ( & V_8 -> V_10 , V_6 ) ;
V_23 = ( ( V_8 -> V_39 * ( V_24 + V_20 ) + V_19 ) * 2 ) ;
V_42 -> V_43 ( V_42 , V_23 + V_8 -> V_44 -> V_45 . V_46 ,
V_8 -> V_39 * 2 , V_21 , V_22 , V_19 , V_20 , & V_8 -> V_9 ,
V_27 -> V_47 ) ;
return 0 ;
error:
F_8 ( & V_8 -> V_10 , V_6 ) ;
if ( V_27 -> V_48 )
V_27 -> V_48 ( V_27 ) ;
F_9 ( & V_8 -> V_18 ) ;
return 0 ;
}
static void F_17 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_4 ( V_5 , struct V_7 ,
V_49 ) ;
F_10 ( V_8 ) ;
}
static enum V_50 F_18 ( struct V_51 * V_52 )
{
struct V_7 * V_8 = F_4 ( V_52 , struct V_7 ,
V_53 ) ;
F_10 ( V_8 ) ;
return V_54 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 ,
T_1 V_24 , int V_55 )
{
struct V_7 * V_8 = V_2 -> V_56 ;
struct V_26 * V_27 = V_8 -> V_27 ;
unsigned long V_6 ;
int V_13 ;
int V_57 = 1 ;
F_6 ( V_58 , L_7 ,
V_35 , V_36 , V_37 , V_38 , V_24 , V_55 ) ;
V_59:
F_5 ( & V_8 -> V_10 , V_6 ) ;
if ( V_8 -> V_13 == V_33 ) {
F_6 ( V_16 , L_8 ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
if ( V_55 )
F_20 ( V_8 -> V_18 ,
V_8 -> V_13 != V_33 , V_60 / 10 ) ;
return;
}
V_13 = V_8 -> V_13 ;
if ( ( V_55 && V_8 -> V_12 != V_8 -> V_11 ) ||
V_13 == V_14 ) {
int V_61 ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
V_61 = F_20 ( V_8 -> V_18 ,
V_8 -> V_11 == V_8 -> V_12 &&
V_8 -> V_13 != V_14 , 5 * V_60 ) ;
if ( V_61 <= 0 && ( V_8 -> V_12 != V_8 -> V_11 ||
V_8 -> V_13 == V_14 ) ) {
if ( V_57 && V_27 -> V_62 &&
( V_13 == V_63 ) ) {
V_27 -> V_62 ( V_27 ,
& V_8 -> V_49 ) ;
V_57 = 0 ;
F_15 ( V_32 L_9
L_10 ) ;
} else {
F_15 ( V_32 L_9
L_11 ,
V_8 -> V_12 ,
V_8 -> V_11 ) ;
return;
}
}
goto V_59;
}
V_8 -> V_12 ++ ;
if ( V_55 ) {
V_8 -> V_24 = V_24 ;
if ( V_35 == 0 && V_36 == 0 && V_37 == V_2 -> V_64 . V_39 &&
V_38 == V_2 -> V_64 . V_40 ) {
if ( V_13 == V_65 ) {
V_8 -> V_15 = V_8 -> V_12 ;
F_6 ( V_16 , L_12 ) ;
V_8 -> V_13 = V_14 ;
}
}
}
if ( V_35 < V_8 -> V_34 . V_35 )
V_8 -> V_34 . V_35 = V_35 ;
if ( V_36 < V_8 -> V_34 . V_36 )
V_8 -> V_34 . V_36 = V_36 ;
if ( V_37 > V_8 -> V_34 . V_37 )
V_8 -> V_34 . V_37 = V_37 ;
if ( V_38 > V_8 -> V_34 . V_38 )
V_8 -> V_34 . V_38 = V_38 ;
F_6 ( V_58 , L_13 ,
V_8 -> V_34 . V_35 , V_8 -> V_34 . V_36 ,
V_8 -> V_34 . V_37 , V_8 -> V_34 . V_38 ,
V_8 -> V_24 ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
V_8 -> V_28 = F_13 () ;
if ( V_27 -> V_62 && ( V_13 == V_63 ) ) {
V_27 -> V_62 ( V_27 , & V_8 -> V_49 ) ;
} else {
if ( ! F_21 ( & V_8 -> V_53 ) ) {
F_22 ( & V_8 -> V_53 ,
F_23 ( 0 , V_66 / 60 ) ,
V_67 ) ;
}
}
}
static void F_24 ( struct V_1 * V_2 , T_1 V_35 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 )
{
F_19 ( V_2 , V_35 , V_36 , V_37 , V_38 , 0 , 0 ) ;
}
static void F_25 ( struct V_68 * V_69 )
{
struct V_7 * V_8 =
F_4 ( V_69 , struct V_7 , V_17 ) ;
struct V_26 * V_27 = V_8 -> V_27 ;
unsigned long V_6 ;
F_26 ( & V_8 -> V_70 ) ;
F_6 ( V_16 , L_14 ) ;
if ( V_8 -> V_13 == V_14 ) {
if ( V_27 -> V_71 ( V_27 ) ) {
F_15 ( V_41 L_15
L_16 ) ;
goto error;
}
F_5 ( & V_8 -> V_10 , V_6 ) ;
V_8 -> V_13 = V_63 ;
F_9 ( & V_8 -> V_18 ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
}
error:
F_27 ( & V_8 -> V_70 ) ;
}
static int F_28 ( struct V_72 * V_64 , struct V_1 * V_2 )
{
if ( ( V_64 -> V_39 != V_2 -> V_64 . V_39 ) ||
( V_64 -> V_40 != V_2 -> V_64 . V_40 ) ||
( V_64 -> V_73 != V_2 -> V_64 . V_73 ) ||
( V_64 -> V_74 != V_2 -> V_64 . V_74 ) ||
( V_64 -> V_75 != V_2 -> V_64 . V_75 ) ||
( V_64 -> V_76 != V_2 -> V_64 . V_76 ) ||
( V_64 -> V_77 != V_2 -> V_64 . V_77 ) )
return - V_78 ;
return 0 ;
}
int F_29 ( struct V_72 * V_64 , struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_56 ;
struct V_26 * V_27 = V_8 -> V_27 ;
if ( ( V_27 -> V_79 & V_80 ) &&
( V_64 -> V_81 [ 0 ] == 0x54445055 ) ) {
F_19 ( V_2 , V_64 -> V_81 [ 1 ] & 0xffff ,
V_64 -> V_81 [ 1 ] >> 16 ,
V_64 -> V_81 [ 2 ] & 0xffff ,
V_64 -> V_81 [ 2 ] >> 16 , V_64 -> V_24 , 1 ) ;
} else {
F_19 ( V_2 , 0 , 0 , V_2 -> V_64 . V_39 , V_2 -> V_64 . V_40 ,
V_64 -> V_24 , 1 ) ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_82 , const struct V_83 * V_84 )
{
F_31 ( V_82 , V_84 ) ;
F_24 ( V_82 , V_84 -> V_85 , V_84 -> V_86 , V_84 -> V_85 + V_84 -> V_87 ,
V_84 -> V_86 + V_84 -> V_88 ) ;
}
static void F_32 ( struct V_1 * V_82 , const struct V_89 * V_90 )
{
F_33 ( V_82 , V_90 ) ;
F_24 ( V_82 , V_90 -> V_85 , V_90 -> V_86 , V_90 -> V_85 + V_90 -> V_87 ,
V_90 -> V_86 + V_90 -> V_88 ) ;
}
static void F_34 ( struct V_1 * V_82 , const struct V_91 * V_92 )
{
F_35 ( V_82 , V_92 ) ;
F_24 ( V_82 , V_92 -> V_85 , V_92 -> V_86 , V_92 -> V_85 + V_92 -> V_87 ,
V_92 -> V_86 + V_92 -> V_88 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
void T_3 * V_82 )
{
struct V_93 V_94 ;
struct V_95 V_96 ;
int V_97 ;
int V_61 ;
if ( F_37 ( & V_96 , V_82 , sizeof( V_96 ) ) )
return - V_98 ;
for ( V_97 = 0 ; V_97 < V_96 . V_99 ; V_97 ++ ) {
struct V_95 * V_100 =
(struct V_95 * ) V_82 ;
if ( F_37 ( & V_94 , & V_100 -> V_94 [ V_97 ] , sizeof( V_94 ) ) )
return - V_98 ;
V_61 = V_42 -> V_101 ( V_42 , V_2 , & V_94 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_82 , unsigned int V_102 , unsigned long V_103 )
{
void T_3 * V_104 = ( void T_3 * ) V_103 ;
int V_61 ;
switch ( V_102 ) {
case V_105 :
V_42 -> V_106 ( V_42 , V_103 ) ;
break;
case V_107 :
V_61 = F_36 ( V_82 , V_104 ) ;
if ( V_61 )
return V_61 ;
break;
default:
F_15 ( V_41 L_17 , V_102 ) ;
return - V_78 ;
}
return 0 ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_8 -> V_44 ;
int V_108 ;
strncpy ( V_1 -> V_45 . V_109 , L_18 , 16 ) ;
V_1 -> V_45 . V_110 = 1 ;
V_1 -> V_111 = & V_112 ;
V_1 -> V_113 = V_114 ;
V_1 -> V_45 . type = V_115 ;
V_1 -> V_45 . V_116 = V_117 ;
V_1 -> V_45 . V_118 = V_8 -> V_39 * 2 ;
V_1 -> V_64 . V_39 = V_8 -> V_39 ;
V_1 -> V_64 . V_40 = V_8 -> V_40 ;
V_1 -> V_64 . V_87 = V_8 -> V_27 -> V_119 -> V_87 ;
V_1 -> V_64 . V_88 = V_8 -> V_27 -> V_119 -> V_88 ;
V_1 -> V_64 . V_73 = V_8 -> V_39 ;
V_1 -> V_64 . V_74 = V_8 -> V_40 * 2 ;
V_1 -> V_64 . V_76 = V_120 ;
V_1 -> V_64 . V_121 = 0 ;
V_1 -> V_64 . V_24 = 0 ;
if ( V_8 -> V_27 -> V_79 & V_80 ) {
V_1 -> V_45 . V_81 [ 0 ] = 0x5444 ;
V_1 -> V_45 . V_81 [ 1 ] = 0x5055 ;
V_1 -> V_64 . V_81 [ 0 ] = 0x54445055 ;
V_1 -> V_64 . V_81 [ 1 ] = 0 ;
V_1 -> V_64 . V_81 [ 2 ] = ( V_122 ) V_8 -> V_39 |
( ( T_1 ) V_8 -> V_40 << 16 ) ;
}
V_1 -> V_64 . V_123 . V_124 = 11 ;
V_1 -> V_64 . V_123 . V_125 = 5 ;
V_1 -> V_64 . V_123 . V_126 = 0 ;
V_1 -> V_64 . V_127 . V_124 = 5 ;
V_1 -> V_64 . V_127 . V_125 = 6 ;
V_1 -> V_64 . V_127 . V_126 = 0 ;
V_1 -> V_64 . V_128 . V_124 = 0 ;
V_1 -> V_64 . V_128 . V_125 = 5 ;
V_1 -> V_64 . V_128 . V_126 = 0 ;
V_108 = F_40 ( & V_1 -> V_129 , 16 , 0 ) ;
V_1 -> V_130 = V_131 ;
V_131 [ 0 ] = 0 ;
for ( V_108 = 1 ; V_108 < 16 ; V_108 ++ )
V_131 [ V_108 ] = 0xffffffff ;
}
static int F_41 ( struct V_7 * V_8 , struct V_132 * V_133 )
{
struct V_1 * V_44 = V_8 -> V_44 ;
struct V_134 * V_134 ;
unsigned long V_135 = V_8 -> V_39 * V_8 -> V_40 *
( V_120 >> 3 ) * 2 ;
unsigned char * V_136 ;
V_134 = F_42 ( V_133 , V_137 , 0 ) ;
if ( ! V_134 )
return - V_78 ;
if ( V_134 -> V_138 - V_134 -> V_139 < V_135 ) {
F_15 ( V_140 L_19
L_20 ) ;
return - V_141 ;
}
V_44 -> V_45 . V_46 = V_134 -> V_139 ;
V_44 -> V_45 . V_142 = F_43 ( V_134 ) ;
V_136 = F_44 ( V_134 -> V_139 , F_43 ( V_134 ) ) ;
if ( V_136 == NULL ) {
F_15 ( V_140 L_21 ) ;
return - V_141 ;
}
V_44 -> V_143 = V_136 ;
return 0 ;
}
static int F_45 ( struct V_132 * V_133 )
{
struct V_1 * V_44 ;
struct V_7 * V_8 ;
struct V_26 * V_27 = V_133 -> V_144 . V_145 ;
int V_61 ;
if ( ! V_27 ) {
F_46 ( L_22 ) ;
return - V_78 ;
}
if ( ! V_27 -> V_119 ) {
F_46 ( L_23 ) ;
return - V_78 ;
}
V_44 = F_47 ( sizeof( struct V_7 ) , & V_133 -> V_144 ) ;
if ( ! V_44 )
return - V_141 ;
V_8 = V_44 -> V_56 ;
V_8 -> V_44 = V_44 ;
V_8 -> V_27 = V_27 ;
V_8 -> V_39 = V_27 -> V_119 -> V_39 ;
V_8 -> V_40 = V_27 -> V_119 -> V_40 ;
V_61 = F_41 ( V_8 , V_133 ) ;
if ( V_61 )
goto V_146;
F_39 ( V_8 ) ;
F_48 ( & V_8 -> V_10 ) ;
F_49 ( & V_8 -> V_70 ) ;
F_50 ( & V_8 -> V_18 ) ;
F_51 ( & V_8 -> V_17 , F_25 ) ;
V_8 -> V_147 = F_52 ( & V_133 -> V_144 ,
V_8 -> V_44 -> V_64 . V_76 * V_8 -> V_39 ,
V_148 ) ;
if ( ! V_8 -> V_147 ) {
V_61 = - V_141 ;
goto V_149;
}
F_15 ( V_41 L_24 ,
V_8 -> V_39 , V_8 -> V_40 ) ;
V_8 -> V_9 . V_150 = F_3 ;
V_8 -> V_49 . V_150 = F_17 ;
F_53 ( & V_8 -> V_53 , V_151 ,
V_67 ) ;
V_8 -> V_53 . V_152 = F_18 ;
V_61 = F_54 ( V_44 ) ;
if ( V_61 )
goto V_149;
V_8 -> V_13 = V_65 ;
F_55 ( V_133 , V_8 ) ;
return 0 ;
V_149:
F_56 ( V_44 -> V_143 ) ;
V_146:
F_57 ( V_8 -> V_44 ) ;
return V_61 ;
}
static int F_58 ( struct V_132 * V_133 )
{
struct V_7 * V_8 ;
V_8 = F_59 ( V_133 ) ;
F_60 ( V_8 -> V_44 ) ;
F_56 ( V_8 -> V_44 -> V_143 ) ;
F_57 ( V_8 -> V_44 ) ;
return 0 ;
}
static int F_61 ( struct V_153 * V_144 ,
struct V_154 * V_155 )
{
if ( V_42 )
return 0 ;
V_42 = F_4 ( V_144 , struct V_156 , V_144 ) ;
return F_62 ( & V_157 ) ;
}
static void F_63 ( struct V_153 * V_144 ,
struct V_154 * V_155 )
{
if ( V_144 != & V_42 -> V_144 )
return;
F_64 ( & V_157 ) ;
V_42 = NULL ;
}
static int T_4 F_65 ( void )
{
return F_66 ( & V_158 ) ;
}
