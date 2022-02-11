static void F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
unsigned int V_6 ;
F_2 () ;
V_6 = V_1 -> V_7 ;
V_6 += V_2 ;
if ( V_6 >= V_4 -> V_8 )
V_6 -= V_4 -> V_8 ;
F_3 ( V_1 -> V_7 ) = V_6 ;
V_1 -> V_9 += V_2 ;
if ( V_1 -> V_9 >= V_4 -> V_10 ) {
V_1 -> V_9 -= V_4 -> V_10 ;
F_4 ( V_1 -> V_5 ) ;
}
}
static void F_5 ( struct V_1 * V_1 ,
const T_1 * V_11 , unsigned int V_2 )
{
struct V_3 * V_4 ;
unsigned int V_12 ;
if ( ! F_3 ( V_1 -> V_13 ) )
return;
V_4 = V_1 -> V_5 -> V_4 ;
if ( V_1 -> V_7 + V_2 <= V_4 -> V_8 ) {
memcpy ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
V_11 , V_2 * 4 ) ;
} else {
V_12 = V_4 -> V_8 - V_1 -> V_7 ;
memcpy ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
V_11 , V_12 * 4 ) ;
V_11 += V_12 * 2 ;
memcpy ( V_4 -> V_14 , V_11 , ( V_2 - V_12 ) * 4 ) ;
}
F_1 ( V_1 , V_2 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
if ( F_3 ( V_1 -> V_15 ) )
F_7 ( V_1 -> V_5 ) ;
}
static void F_8 ( struct V_1 * V_1 , unsigned int V_16 )
{
struct V_3 * V_4 ;
T_2 V_17 ;
unsigned int V_12 ;
if ( ! F_3 ( V_1 -> V_13 ) )
return;
V_4 = V_1 -> V_5 -> V_4 ;
V_17 = V_16 - V_1 -> V_18 ;
if ( V_17 < V_4 -> V_8 ) {
if ( V_1 -> V_7 + V_17 <= V_4 -> V_8 ) {
memset ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
0 , V_17 * 4 ) ;
} else {
V_12 = V_4 -> V_8 - V_1 -> V_7 ;
memset ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
0 , V_12 * 4 ) ;
memset ( V_4 -> V_14 , 0 , ( V_17 - V_12 ) * 4 ) ;
}
F_1 ( V_1 , V_17 ) ;
} else {
F_6 ( V_1 ) ;
}
}
static void F_9 ( struct V_19 * V_20 , T_2 V_21 ,
T_3 V_22 , void * V_23 , void * V_24 )
{
struct V_1 * V_1 = V_24 ;
const struct V_25 * V_26 ;
unsigned int V_27 , V_28 , V_2 , V_16 ;
int V_29 ;
if ( V_1 -> V_30 < 0 )
return;
V_27 = V_1 -> V_30 ;
V_26 = V_1 -> V_31 . V_32 [ V_27 ] . V_31 ;
V_28 = F_10 ( V_23 ) >> 16 ;
if ( F_11 ( V_28 >= 16 &&
V_26 -> V_33 == F_12 ( 0x73676874 ) ) ) {
V_2 = F_13 ( V_26 -> V_34 ) ;
if ( F_11 ( V_2 <= ( V_28 - 16 ) / 4 ) ) {
V_16 = F_13 ( V_26 -> V_35 ) ;
if ( F_14 ( V_16 != V_1 -> V_18 ) ) {
if ( ! V_1 -> V_36 )
F_8 ( V_1 , V_16 ) ;
V_1 -> V_36 = false ;
V_1 -> V_18 = V_16 ;
}
F_5 ( V_1 , V_26 -> V_11 , V_2 ) ;
V_1 -> V_18 += V_2 ;
}
}
V_29 = F_15 ( V_1 -> V_20 , & V_37 ,
& V_1 -> V_31 . V_38 ,
V_1 -> V_31 . V_32 [ V_27 ] . V_39 ) ;
if ( V_29 < 0 ) {
F_16 ( & V_1 -> V_40 -> V_41 , L_1 , V_29 ) ;
F_6 ( V_1 ) ;
V_1 -> V_30 = - 1 ;
return;
}
F_17 ( V_1 -> V_20 ) ;
if ( ++ V_27 >= V_42 )
V_27 = 0 ;
V_1 -> V_30 = V_27 ;
}
static int F_18 ( struct V_1 * V_1 )
{
int V_43 , V_29 ;
T_4 V_44 ;
V_45:
V_43 = F_19 ( & V_1 -> V_46 ,
sizeof( struct V_25 ) ,
V_1 -> V_41 -> V_47 ) ;
if ( V_43 < 0 ) {
V_29 = V_43 ;
goto error;
}
V_44 = F_12 ( V_43 | ( V_1 -> V_41 -> V_47 << V_48 ) ) ;
V_29 = F_20 ( V_1 -> V_40 , V_49 ,
V_1 -> V_50 + V_51 ,
& V_44 , 4 , V_52 |
V_1 -> V_46 . V_53 ) ;
if ( V_29 == - V_54 ) {
F_21 ( & V_1 -> V_46 ) ;
goto V_45;
} else if ( V_29 < 0 ) {
goto V_55;
}
return 0 ;
V_55:
F_21 ( & V_1 -> V_46 ) ;
error:
return V_29 ;
}
static int F_22 ( struct V_56 * V_57 )
{
static const struct V_58 V_59 = {
. V_60 = V_61 |
V_62 |
V_63 |
V_64 |
V_65 ,
. V_66 = V_67 ,
. V_68 = V_69 ,
. V_70 = 48000 ,
. V_71 = 48000 ,
. V_72 = 2 ,
. V_73 = 2 ,
. V_74 = 4 * 1024 * 1024 ,
. V_75 = V_76 * 4 ,
. V_77 = 1024 * 1024 ,
. V_78 = 2 ,
. V_79 = V_80 ,
} ;
struct V_1 * V_1 = V_57 -> V_81 ;
V_57 -> V_4 -> V_82 = V_59 ;
return F_23 ( & V_1 -> V_31 , V_1 -> V_40 ,
V_42 ,
sizeof( struct V_25 ) ,
V_83 ) ;
}
static int F_24 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
F_25 ( & V_1 -> V_31 , V_1 -> V_40 ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_57 ,
struct V_84 * V_85 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
int V_29 ;
V_29 = F_27 ( V_57 ,
F_28 ( V_85 ) ) ;
if ( V_29 < 0 )
return V_29 ;
F_3 ( V_1 -> V_15 ) = true ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , int V_39 , T_4 * V_44 )
{
return F_20 ( V_1 -> V_40 , V_86 ,
V_1 -> V_50 + V_39 , V_44 , 4 , 0 ) ;
}
static int F_30 ( struct V_1 * V_1 , int V_39 , T_4 V_44 )
{
return F_20 ( V_1 -> V_40 , V_49 ,
V_1 -> V_50 + V_39 , & V_44 , 4 , 0 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
T_4 V_44 ;
if ( ! V_1 -> V_20 )
return;
F_32 ( V_1 -> V_20 ) ;
F_33 ( V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
F_21 ( & V_1 -> V_46 ) ;
V_44 = 0 ;
F_20 ( V_1 -> V_40 , V_49 ,
V_1 -> V_50 + V_87 ,
& V_44 , 4 , V_88 ) ;
}
static int F_34 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
F_3 ( V_1 -> V_15 ) = false ;
F_35 ( & V_1 -> V_89 ) ;
F_31 ( V_1 ) ;
F_36 ( & V_1 -> V_89 ) ;
return F_37 ( V_57 ) ;
}
static int F_38 ( struct V_1 * V_1 )
{
unsigned int V_90 ;
int V_29 ;
if ( V_1 -> V_20 ) {
if ( V_1 -> V_30 < 0 )
F_31 ( V_1 ) ;
else
return 0 ;
}
V_29 = F_30 ( V_1 , V_91 , F_12 ( V_92 ) ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_18 ( V_1 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_30 ( V_1 , V_87 , F_12 ( V_93 ) ) ;
if ( V_29 < 0 )
goto V_55;
V_1 -> V_20 = F_39 ( V_1 -> V_41 -> V_94 ,
V_95 ,
V_1 -> V_46 . V_96 ,
V_1 -> V_41 -> V_47 ,
4 , F_9 , V_1 ) ;
if ( F_40 ( V_1 -> V_20 ) ) {
V_29 = F_41 ( V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
goto V_55;
}
for ( V_90 = 0 ; V_90 < V_42 ; ++ V_90 ) {
V_29 = F_15 ( V_1 -> V_20 , & V_37 ,
& V_1 -> V_31 . V_38 ,
V_1 -> V_31 . V_32 [ V_90 ] . V_39 ) ;
if ( V_29 < 0 )
goto V_97;
}
V_1 -> V_36 = true ;
V_1 -> V_30 = 0 ;
V_29 = F_42 ( V_1 -> V_20 , - 1 , 0 ,
V_98 ) ;
if ( V_29 < 0 )
goto V_97;
return 0 ;
V_97:
F_33 ( V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
V_55:
F_21 ( & V_1 -> V_46 ) ;
F_30 ( V_1 , V_87 , 0 ) ;
error:
return V_29 ;
}
static int F_43 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
int V_29 ;
V_1 -> V_7 = 0 ;
V_1 -> V_9 = 0 ;
F_35 ( & V_1 -> V_89 ) ;
V_29 = F_38 ( V_1 ) ;
F_36 ( & V_1 -> V_89 ) ;
return V_29 ;
}
static int F_44 ( struct V_56 * V_57 , int V_99 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
switch ( V_99 ) {
case V_100 :
F_3 ( V_1 -> V_13 ) = true ;
break;
case V_101 :
F_3 ( V_1 -> V_13 ) = false ;
break;
default:
return - V_102 ;
}
return 0 ;
}
static T_5 F_45 ( struct V_56 * V_57 )
{
struct V_1 * V_1 = V_57 -> V_81 ;
return F_3 ( V_1 -> V_7 ) ;
}
static int F_46 ( struct V_1 * V_1 )
{
static struct V_103 V_104 = {
. V_105 = F_22 ,
. V_106 = F_24 ,
. V_107 = V_108 ,
. V_85 = F_26 ,
. V_109 = F_34 ,
. V_110 = F_43 ,
. V_111 = F_44 ,
. V_112 = F_45 ,
. V_113 = V_114 ,
. V_115 = V_116 ,
} ;
struct V_117 * V_5 ;
int V_29 ;
V_29 = F_47 ( V_1 -> V_94 , L_2 , 0 , 0 , 1 , & V_5 ) ;
if ( V_29 < 0 )
return V_29 ;
V_5 -> V_81 = V_1 ;
strcpy ( V_5 -> V_118 , L_2 ) ;
V_1 -> V_5 = V_5 -> V_119 [ V_120 ] . V_57 ;
V_1 -> V_5 -> V_104 = & V_104 ;
return 0 ;
}
static int F_48 ( struct V_121 * V_122 ,
struct V_123 * V_60 )
{
struct V_1 * V_1 = V_122 -> V_81 ;
V_60 -> type = V_124 ;
V_60 -> V_2 = 1 ;
V_60 -> V_44 . integer . V_125 = V_1 -> V_126 ;
V_60 -> V_44 . integer . V_127 = V_1 -> V_128 ;
return 0 ;
}
static int F_49 ( struct V_121 * V_122 ,
struct V_129 * V_44 )
{
struct V_1 * V_1 = V_122 -> V_81 ;
T_4 V_130 ;
int V_29 ;
V_29 = F_29 ( V_1 , V_131 , & V_130 ) ;
if ( V_29 < 0 )
return V_29 ;
V_44 -> V_44 . integer . V_44 [ 0 ] = ( V_132 ) F_13 ( V_130 ) ;
return 0 ;
}
static int F_50 ( struct V_121 * V_122 ,
struct V_129 * V_44 )
{
struct V_1 * V_1 = V_122 -> V_81 ;
if ( V_44 -> V_44 . integer . V_44 [ 0 ] < V_1 -> V_126 ||
V_44 -> V_44 . integer . V_44 [ 0 ] > V_1 -> V_128 )
return - V_102 ;
return F_30 ( V_1 , V_131 ,
F_12 ( V_44 -> V_44 . integer . V_44 [ 0 ] ) ) ;
}
static int F_51 ( struct V_121 * V_122 ,
struct V_129 * V_44 )
{
struct V_1 * V_1 = V_122 -> V_81 ;
T_4 V_133 ;
int V_29 ;
V_29 = F_29 ( V_1 , V_134 , & V_133 ) ;
if ( V_29 < 0 )
return V_29 ;
V_44 -> V_44 . integer . V_44 [ 0 ] = ! V_133 ;
return 0 ;
}
static int F_52 ( struct V_121 * V_122 ,
struct V_129 * V_44 )
{
struct V_1 * V_1 = V_122 -> V_81 ;
return F_30 ( V_1 , V_134 ,
( V_135 T_4 ) ! V_44 -> V_44 . integer . V_44 [ 0 ] ) ;
}
static int F_53 ( struct V_1 * V_1 )
{
static const struct V_136 V_137 = {
. V_138 = V_139 ,
. V_118 = L_3 ,
. V_140 = V_141 |
V_142 ,
. V_60 = F_48 ,
. V_143 = F_49 ,
. V_144 = F_50 ,
} ;
static const struct V_136 V_145 = {
. V_138 = V_139 ,
. V_118 = L_4 ,
. V_60 = V_146 ,
. V_143 = F_51 ,
. V_144 = F_52 ,
} ;
T_4 V_44 ;
struct V_121 * V_122 ;
int V_29 ;
V_29 = F_29 ( V_1 , V_147 , & V_44 ) ;
if ( V_29 < 0 )
return V_29 ;
V_1 -> V_126 = F_13 ( V_44 ) ;
V_29 = F_29 ( V_1 , V_148 , & V_44 ) ;
if ( V_29 < 0 )
return V_29 ;
V_1 -> V_128 = F_13 ( V_44 ) ;
V_1 -> V_149 [ 0 ] = V_150 ;
V_1 -> V_149 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_29 = F_29 ( V_1 , V_151 , & V_44 ) ;
if ( V_29 < 0 )
return V_29 ;
V_1 -> V_149 [ 2 ] = ( V_132 ) F_13 ( V_44 ) * 100 ;
V_29 = F_29 ( V_1 , V_152 , & V_44 ) ;
if ( V_29 < 0 )
return V_29 ;
V_1 -> V_149 [ 3 ] = ( V_132 ) F_13 ( V_44 ) * 100 ;
V_122 = F_54 ( & V_137 , V_1 ) ;
if ( V_122 )
V_122 -> V_153 . V_154 = V_1 -> V_149 ;
V_29 = F_55 ( V_1 -> V_94 , V_122 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_55 ( V_1 -> V_94 , F_54 ( & V_145 , V_1 ) ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static void F_56 ( struct V_155 * V_94 )
{
struct V_1 * V_1 = V_94 -> V_81 ;
F_57 ( & V_1 -> V_46 ) ;
F_58 ( V_1 -> V_40 ) ;
F_59 ( & V_1 -> V_89 ) ;
}
static T_6 F_60 ( struct V_156 * V_40 )
{
struct V_157 V_90 ;
int V_158 , V_44 ;
F_61 ( & V_90 , V_40 -> V_159 ) ;
while ( F_62 ( & V_90 , & V_158 , & V_44 ) )
if ( V_158 == V_160 )
return V_161 + V_44 * 4 ;
return 0 ;
}
static int F_63 ( struct V_156 * V_40 ,
const struct V_162 * V_163 )
{
struct V_164 * V_165 = F_64 ( V_40 ) ;
struct V_155 * V_94 ;
struct V_1 * V_1 ;
int V_29 ;
V_29 = F_65 ( & V_40 -> V_41 , - 1 , NULL , V_166 ,
sizeof( * V_1 ) , & V_94 ) ;
if ( V_29 < 0 )
return V_29 ;
V_1 = V_94 -> V_81 ;
V_1 -> V_94 = V_94 ;
F_66 ( & V_1 -> V_89 ) ;
V_1 -> V_40 = F_67 ( V_40 ) ;
V_1 -> V_41 = V_165 ;
V_1 -> V_50 = F_60 ( V_40 ) ;
if ( ! V_1 -> V_50 ) {
F_16 ( & V_40 -> V_41 , L_5 ) ;
V_29 = - V_167 ;
goto V_168;
}
F_68 ( & V_1 -> V_46 , V_40 ) ;
V_94 -> V_169 = F_56 ;
strcpy ( V_94 -> V_170 , L_2 ) ;
strcpy ( V_94 -> V_171 , L_6 ) ;
snprintf ( V_94 -> V_172 , sizeof( V_94 -> V_172 ) ,
L_7 ,
V_165 -> V_173 [ 3 ] , V_165 -> V_173 [ 4 ] ,
F_69 ( & V_40 -> V_41 ) , 100 << V_165 -> V_47 ) ;
strcpy ( V_94 -> V_174 , L_2 ) ;
V_29 = F_46 ( V_1 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_53 ( V_1 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_70 ( V_94 ) ;
if ( V_29 < 0 )
goto error;
F_71 ( & V_40 -> V_41 , V_1 ) ;
return 0 ;
V_168:
F_58 ( V_1 -> V_40 ) ;
F_59 ( & V_1 -> V_89 ) ;
error:
F_72 ( V_94 ) ;
return V_29 ;
}
static void F_73 ( struct V_156 * V_40 )
{
struct V_1 * V_1 = F_74 ( & V_40 -> V_41 ) ;
if ( F_75 ( & V_1 -> V_46 ) < 0 ) {
F_6 ( V_1 ) ;
F_35 ( & V_1 -> V_89 ) ;
F_31 ( V_1 ) ;
F_36 ( & V_1 -> V_89 ) ;
}
}
static void F_76 ( struct V_156 * V_40 )
{
struct V_1 * V_1 = F_74 ( & V_40 -> V_41 ) ;
F_6 ( V_1 ) ;
F_77 ( V_1 -> V_94 ) ;
F_35 ( & V_1 -> V_89 ) ;
F_31 ( V_1 ) ;
F_36 ( & V_1 -> V_89 ) ;
F_78 ( V_1 -> V_94 ) ;
}
static int T_7 F_79 ( void )
{
return F_80 ( & V_175 . V_170 ) ;
}
static void T_8 F_81 ( void )
{
F_82 ( & V_175 . V_170 ) ;
}
