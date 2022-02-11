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
unsigned long V_15 ;
if ( F_3 ( V_1 -> V_16 ) ) {
F_7 ( V_1 -> V_5 , V_15 ) ;
if ( F_8 ( V_1 -> V_5 ) )
F_9 ( V_1 -> V_5 , V_17 ) ;
F_10 ( V_1 -> V_5 , V_15 ) ;
}
}
static void F_11 ( struct V_1 * V_1 , unsigned int V_18 )
{
struct V_3 * V_4 ;
T_2 V_19 ;
unsigned int V_12 ;
if ( ! F_3 ( V_1 -> V_13 ) )
return;
V_4 = V_1 -> V_5 -> V_4 ;
V_19 = V_18 - V_1 -> V_20 ;
if ( V_19 < V_4 -> V_8 ) {
if ( V_1 -> V_7 + V_19 <= V_4 -> V_8 ) {
memset ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
0 , V_19 * 4 ) ;
} else {
V_12 = V_4 -> V_8 - V_1 -> V_7 ;
memset ( V_4 -> V_14 + V_1 -> V_7 * 4 ,
0 , V_12 * 4 ) ;
memset ( V_4 -> V_14 , 0 , ( V_19 - V_12 ) * 4 ) ;
}
F_1 ( V_1 , V_19 ) ;
} else {
F_6 ( V_1 ) ;
}
}
static void F_12 ( struct V_21 * V_22 , T_2 V_23 ,
T_3 V_24 , void * V_25 , void * V_26 )
{
struct V_1 * V_1 = V_26 ;
const struct V_27 * V_28 ;
unsigned int V_29 , V_30 , V_2 , V_18 ;
int V_31 ;
if ( V_1 -> V_32 < 0 )
return;
V_29 = V_1 -> V_32 ;
V_28 = V_1 -> V_33 . V_34 [ V_29 ] . V_33 ;
V_30 = F_13 ( V_25 ) >> 16 ;
if ( F_14 ( V_30 >= 16 &&
V_28 -> V_35 == F_15 ( 0x73676874 ) ) ) {
V_2 = F_16 ( V_28 -> V_36 ) ;
if ( F_14 ( V_2 <= ( V_30 - 16 ) / 4 ) ) {
V_18 = F_16 ( V_28 -> V_37 ) ;
if ( F_17 ( V_18 != V_1 -> V_20 ) ) {
if ( ! V_1 -> V_38 )
F_11 ( V_1 , V_18 ) ;
V_1 -> V_38 = false ;
V_1 -> V_20 = V_18 ;
}
F_5 ( V_1 , V_28 -> V_11 , V_2 ) ;
V_1 -> V_20 += V_2 ;
}
}
V_31 = F_18 ( V_1 -> V_22 , & V_39 ,
& V_1 -> V_33 . V_40 ,
V_1 -> V_33 . V_34 [ V_29 ] . V_41 ) ;
if ( V_31 < 0 ) {
F_19 ( & V_1 -> V_42 -> V_43 , L_1 , V_31 ) ;
F_6 ( V_1 ) ;
V_1 -> V_32 = - 1 ;
return;
}
F_20 ( V_1 -> V_22 ) ;
if ( ++ V_29 >= V_44 )
V_29 = 0 ;
V_1 -> V_32 = V_29 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_45 , V_31 ;
T_4 V_46 ;
V_47:
V_45 = F_22 ( & V_1 -> V_48 ,
sizeof( struct V_27 ) ,
V_1 -> V_43 -> V_49 ) ;
if ( V_45 < 0 ) {
V_31 = V_45 ;
goto error;
}
V_46 = F_15 ( V_45 | ( V_1 -> V_43 -> V_49 << V_50 ) ) ;
V_31 = F_23 ( V_1 -> V_42 , V_51 ,
V_1 -> V_52 + V_53 ,
& V_46 , 4 , V_54 |
V_1 -> V_48 . V_55 ) ;
if ( V_31 == - V_56 ) {
F_24 ( & V_1 -> V_48 ) ;
goto V_47;
} else if ( V_31 < 0 ) {
goto V_57;
}
return 0 ;
V_57:
F_24 ( & V_1 -> V_48 ) ;
error:
return V_31 ;
}
static int F_25 ( struct V_58 * V_59 )
{
static const struct V_60 V_61 = {
. V_62 = V_63 |
V_64 |
V_65 |
V_66 |
V_67 ,
. V_68 = V_69 ,
. V_70 = V_71 ,
. V_72 = 48000 ,
. V_73 = 48000 ,
. V_74 = 2 ,
. V_75 = 2 ,
. V_76 = 4 * 1024 * 1024 ,
. V_77 = V_78 * 4 ,
. V_79 = 1024 * 1024 ,
. V_80 = 2 ,
. V_81 = V_82 ,
} ;
struct V_1 * V_1 = V_59 -> V_83 ;
V_59 -> V_4 -> V_84 = V_61 ;
return F_26 ( & V_1 -> V_33 , V_1 -> V_42 ,
V_44 ,
sizeof( struct V_27 ) ,
V_85 ) ;
}
static int F_27 ( struct V_58 * V_59 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
F_28 ( & V_1 -> V_33 , V_1 -> V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 ,
struct V_86 * V_87 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
int V_31 ;
V_31 = F_30 ( V_59 ,
F_31 ( V_87 ) ) ;
if ( V_31 < 0 )
return V_31 ;
F_3 ( V_1 -> V_16 ) = true ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , int V_41 , T_4 * V_46 )
{
return F_23 ( V_1 -> V_42 , V_88 ,
V_1 -> V_52 + V_41 , V_46 , 4 , 0 ) ;
}
static int F_33 ( struct V_1 * V_1 , int V_41 , T_4 V_46 )
{
return F_23 ( V_1 -> V_42 , V_51 ,
V_1 -> V_52 + V_41 , & V_46 , 4 , 0 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
T_4 V_46 ;
if ( ! V_1 -> V_22 )
return;
F_35 ( V_1 -> V_22 ) ;
F_36 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
F_24 ( & V_1 -> V_48 ) ;
V_46 = 0 ;
F_23 ( V_1 -> V_42 , V_51 ,
V_1 -> V_52 + V_89 ,
& V_46 , 4 , V_90 ) ;
}
static int F_37 ( struct V_58 * V_59 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
F_3 ( V_1 -> V_16 ) = false ;
F_38 ( & V_1 -> V_91 ) ;
F_34 ( V_1 ) ;
F_39 ( & V_1 -> V_91 ) ;
return F_40 ( V_59 ) ;
}
static int F_41 ( struct V_1 * V_1 )
{
unsigned int V_92 ;
int V_31 ;
if ( V_1 -> V_22 ) {
if ( V_1 -> V_32 < 0 )
F_34 ( V_1 ) ;
else
return 0 ;
}
V_31 = F_33 ( V_1 , V_93 , F_15 ( V_94 ) ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_21 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_33 ( V_1 , V_89 , F_15 ( V_95 ) ) ;
if ( V_31 < 0 )
goto V_57;
V_1 -> V_22 = F_42 ( V_1 -> V_43 -> V_96 ,
V_97 ,
V_1 -> V_48 . V_98 ,
V_1 -> V_43 -> V_49 ,
4 , F_12 , V_1 ) ;
if ( F_43 ( V_1 -> V_22 ) ) {
V_31 = F_44 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
goto V_57;
}
for ( V_92 = 0 ; V_92 < V_44 ; ++ V_92 ) {
V_31 = F_18 ( V_1 -> V_22 , & V_39 ,
& V_1 -> V_33 . V_40 ,
V_1 -> V_33 . V_34 [ V_92 ] . V_41 ) ;
if ( V_31 < 0 )
goto V_99;
}
V_1 -> V_38 = true ;
V_1 -> V_32 = 0 ;
V_31 = F_45 ( V_1 -> V_22 , - 1 , 0 ,
V_100 ) ;
if ( V_31 < 0 )
goto V_99;
return 0 ;
V_99:
F_36 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
V_57:
F_24 ( & V_1 -> V_48 ) ;
F_33 ( V_1 , V_89 , 0 ) ;
error:
return V_31 ;
}
static int F_46 ( struct V_58 * V_59 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
int V_31 ;
V_1 -> V_7 = 0 ;
V_1 -> V_9 = 0 ;
F_38 ( & V_1 -> V_91 ) ;
V_31 = F_41 ( V_1 ) ;
F_39 ( & V_1 -> V_91 ) ;
return V_31 ;
}
static int F_47 ( struct V_58 * V_59 , int V_101 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
switch ( V_101 ) {
case V_102 :
F_3 ( V_1 -> V_13 ) = true ;
break;
case V_103 :
F_3 ( V_1 -> V_13 ) = false ;
break;
default:
return - V_104 ;
}
return 0 ;
}
static T_5 F_48 ( struct V_58 * V_59 )
{
struct V_1 * V_1 = V_59 -> V_83 ;
return F_3 ( V_1 -> V_7 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
static struct V_105 V_106 = {
. V_107 = F_25 ,
. V_108 = F_27 ,
. V_109 = V_110 ,
. V_87 = F_29 ,
. V_111 = F_37 ,
. V_112 = F_46 ,
. V_113 = F_47 ,
. V_114 = F_48 ,
. V_115 = V_116 ,
. V_117 = V_118 ,
} ;
struct V_119 * V_5 ;
int V_31 ;
V_31 = F_50 ( V_1 -> V_96 , L_2 , 0 , 0 , 1 , & V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
V_5 -> V_83 = V_1 ;
strcpy ( V_5 -> V_120 , L_2 ) ;
V_1 -> V_5 = V_5 -> V_121 [ V_122 ] . V_59 ;
V_1 -> V_5 -> V_106 = & V_106 ;
return 0 ;
}
static int F_51 ( struct V_123 * V_124 ,
struct V_125 * V_62 )
{
struct V_1 * V_1 = V_124 -> V_83 ;
V_62 -> type = V_126 ;
V_62 -> V_2 = 1 ;
V_62 -> V_46 . integer . V_127 = V_1 -> V_128 ;
V_62 -> V_46 . integer . V_129 = V_1 -> V_130 ;
return 0 ;
}
static int F_52 ( struct V_123 * V_124 ,
struct V_131 * V_46 )
{
struct V_1 * V_1 = V_124 -> V_83 ;
T_4 V_132 ;
int V_31 ;
V_31 = F_32 ( V_1 , V_133 , & V_132 ) ;
if ( V_31 < 0 )
return V_31 ;
V_46 -> V_46 . integer . V_46 [ 0 ] = ( V_134 ) F_16 ( V_132 ) ;
return 0 ;
}
static int F_53 ( struct V_123 * V_124 ,
struct V_131 * V_46 )
{
struct V_1 * V_1 = V_124 -> V_83 ;
if ( V_46 -> V_46 . integer . V_46 [ 0 ] < V_1 -> V_128 ||
V_46 -> V_46 . integer . V_46 [ 0 ] > V_1 -> V_130 )
return - V_104 ;
return F_33 ( V_1 , V_133 ,
F_15 ( V_46 -> V_46 . integer . V_46 [ 0 ] ) ) ;
}
static int F_54 ( struct V_123 * V_124 ,
struct V_131 * V_46 )
{
struct V_1 * V_1 = V_124 -> V_83 ;
T_4 V_135 ;
int V_31 ;
V_31 = F_32 ( V_1 , V_136 , & V_135 ) ;
if ( V_31 < 0 )
return V_31 ;
V_46 -> V_46 . integer . V_46 [ 0 ] = ! V_135 ;
return 0 ;
}
static int F_55 ( struct V_123 * V_124 ,
struct V_131 * V_46 )
{
struct V_1 * V_1 = V_124 -> V_83 ;
return F_33 ( V_1 , V_136 ,
( V_137 T_4 ) ! V_46 -> V_46 . integer . V_46 [ 0 ] ) ;
}
static int F_56 ( struct V_1 * V_1 )
{
static const struct V_138 V_139 = {
. V_140 = V_141 ,
. V_120 = L_3 ,
. V_142 = V_143 |
V_144 ,
. V_62 = F_51 ,
. V_145 = F_52 ,
. V_146 = F_53 ,
} ;
static const struct V_138 V_147 = {
. V_140 = V_141 ,
. V_120 = L_4 ,
. V_62 = V_148 ,
. V_145 = F_54 ,
. V_146 = F_55 ,
} ;
T_4 V_46 ;
struct V_123 * V_124 ;
int V_31 ;
V_31 = F_32 ( V_1 , V_149 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_128 = F_16 ( V_46 ) ;
V_31 = F_32 ( V_1 , V_150 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_130 = F_16 ( V_46 ) ;
V_1 -> V_151 [ 0 ] = V_152 ;
V_1 -> V_151 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_31 = F_32 ( V_1 , V_153 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_151 [ 2 ] = ( V_134 ) F_16 ( V_46 ) * 100 ;
V_31 = F_32 ( V_1 , V_154 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_151 [ 3 ] = ( V_134 ) F_16 ( V_46 ) * 100 ;
V_124 = F_57 ( & V_139 , V_1 ) ;
if ( V_124 )
V_124 -> V_155 . V_156 = V_1 -> V_151 ;
V_31 = F_58 ( V_1 -> V_96 , V_124 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_58 ( V_1 -> V_96 , F_57 ( & V_147 , V_1 ) ) ;
if ( V_31 < 0 )
return V_31 ;
return 0 ;
}
static void F_59 ( struct V_157 * V_96 )
{
struct V_1 * V_1 = V_96 -> V_83 ;
F_60 ( & V_1 -> V_48 ) ;
F_61 ( V_1 -> V_42 ) ;
F_62 ( & V_1 -> V_91 ) ;
}
static T_6 F_63 ( struct V_158 * V_42 )
{
struct V_159 V_92 ;
int V_160 , V_46 ;
F_64 ( & V_92 , V_42 -> V_161 ) ;
while ( F_65 ( & V_92 , & V_160 , & V_46 ) )
if ( V_160 == V_162 )
return V_163 + V_46 * 4 ;
return 0 ;
}
static int F_66 ( struct V_158 * V_42 ,
const struct V_164 * V_165 )
{
struct V_166 * V_167 = F_67 ( V_42 ) ;
struct V_157 * V_96 ;
struct V_1 * V_1 ;
int V_31 ;
V_31 = F_68 ( - 1 , NULL , V_168 , sizeof( * V_1 ) , & V_96 ) ;
if ( V_31 < 0 )
return V_31 ;
F_69 ( V_96 , & V_42 -> V_43 ) ;
V_1 = V_96 -> V_83 ;
V_1 -> V_96 = V_96 ;
F_70 ( & V_1 -> V_91 ) ;
V_1 -> V_42 = F_71 ( V_42 ) ;
V_1 -> V_43 = V_167 ;
V_1 -> V_52 = F_63 ( V_42 ) ;
if ( ! V_1 -> V_52 ) {
F_19 ( & V_42 -> V_43 , L_5 ) ;
V_31 = - V_169 ;
goto V_170;
}
F_72 ( & V_1 -> V_48 , V_42 ) ;
V_96 -> V_171 = F_59 ;
strcpy ( V_96 -> V_172 , L_2 ) ;
strcpy ( V_96 -> V_173 , L_6 ) ;
snprintf ( V_96 -> V_174 , sizeof( V_96 -> V_174 ) ,
L_7 ,
V_167 -> V_175 [ 3 ] , V_167 -> V_175 [ 4 ] ,
F_73 ( & V_42 -> V_43 ) , 100 << V_167 -> V_49 ) ;
strcpy ( V_96 -> V_176 , L_2 ) ;
V_31 = F_49 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_56 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_74 ( V_96 ) ;
if ( V_31 < 0 )
goto error;
F_75 ( & V_42 -> V_43 , V_1 ) ;
return 0 ;
V_170:
F_61 ( V_1 -> V_42 ) ;
F_62 ( & V_1 -> V_91 ) ;
error:
F_76 ( V_96 ) ;
return V_31 ;
}
static void F_77 ( struct V_158 * V_42 )
{
struct V_1 * V_1 = F_78 ( & V_42 -> V_43 ) ;
if ( F_79 ( & V_1 -> V_48 ) < 0 ) {
F_6 ( V_1 ) ;
F_38 ( & V_1 -> V_91 ) ;
F_34 ( V_1 ) ;
F_39 ( & V_1 -> V_91 ) ;
}
}
static void F_80 ( struct V_158 * V_42 )
{
struct V_1 * V_1 = F_78 ( & V_42 -> V_43 ) ;
F_6 ( V_1 ) ;
F_81 ( V_1 -> V_96 ) ;
F_38 ( & V_1 -> V_91 ) ;
F_34 ( V_1 ) ;
F_39 ( & V_1 -> V_91 ) ;
F_82 ( V_1 -> V_96 ) ;
}
static int T_7 F_83 ( void )
{
return F_84 ( & V_177 . V_172 ) ;
}
static void T_8 F_85 ( void )
{
F_86 ( & V_177 . V_172 ) ;
}
