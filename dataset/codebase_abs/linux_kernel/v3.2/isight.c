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
int V_45 , V_31 , V_46 , V_47 = 0 ;
T_4 V_48 ;
V_49:
V_45 = F_22 ( & V_1 -> V_50 ,
sizeof( struct V_27 ) ,
V_1 -> V_43 -> V_51 ) ;
if ( V_45 < 0 ) {
V_31 = V_45 ;
goto error;
}
V_48 = F_15 ( V_45 | ( V_1 -> V_43 -> V_51 << V_52 ) ) ;
for (; ; ) {
V_46 = F_23 (
V_1 -> V_43 -> V_53 ,
V_54 ,
V_1 -> V_43 -> V_55 ,
V_1 -> V_50 . V_56 ,
V_1 -> V_43 -> V_51 ,
V_1 -> V_57 + V_58 ,
& V_48 , 4 ) ;
if ( V_46 == V_59 ) {
return 0 ;
} else if ( V_46 == V_60 ) {
F_24 ( & V_1 -> V_50 ) ;
goto V_49;
} else if ( F_25 ( V_46 ) || ++ V_47 >= 3 ) {
V_31 = - V_61 ;
goto V_62;
}
F_26 ( 5 ) ;
}
V_62:
F_24 ( & V_1 -> V_50 ) ;
error:
return V_31 ;
}
static int F_27 ( struct V_63 * V_64 )
{
static const struct V_65 V_66 = {
. V_67 = V_68 |
V_69 |
V_70 |
V_71 |
V_72 ,
. V_73 = V_74 ,
. V_75 = V_76 ,
. V_77 = 48000 ,
. V_78 = 48000 ,
. V_79 = 2 ,
. V_80 = 2 ,
. V_81 = 4 * 1024 * 1024 ,
. V_82 = V_83 * 4 ,
. V_84 = 1024 * 1024 ,
. V_85 = 2 ,
. V_86 = V_87 ,
} ;
struct V_1 * V_1 = V_64 -> V_88 ;
V_64 -> V_4 -> V_89 = V_66 ;
return F_28 ( & V_1 -> V_33 , V_1 -> V_42 ,
V_44 ,
sizeof( struct V_27 ) ,
V_90 ) ;
}
static int F_29 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
F_30 ( & V_1 -> V_33 , V_1 -> V_42 ) ;
return 0 ;
}
static int F_31 ( struct V_63 * V_64 ,
struct V_91 * V_92 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
int V_31 ;
V_31 = F_32 ( V_64 ,
F_33 ( V_92 ) ) ;
if ( V_31 < 0 )
return V_31 ;
F_3 ( V_1 -> V_16 ) = true ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , int V_41 , T_4 * V_48 )
{
return F_35 ( V_1 -> V_42 , V_93 ,
V_1 -> V_57 + V_41 , V_48 , 4 ) ;
}
static int F_36 ( struct V_1 * V_1 , int V_41 , T_4 V_48 )
{
return F_35 ( V_1 -> V_42 , V_54 ,
V_1 -> V_57 + V_41 , & V_48 , 4 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_22 )
return;
F_38 ( V_1 -> V_22 ) ;
F_39 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
F_24 ( & V_1 -> V_50 ) ;
F_36 ( V_1 , V_94 , 0 ) ;
}
static int F_40 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
F_3 ( V_1 -> V_16 ) = false ;
F_41 ( & V_1 -> V_95 ) ;
F_37 ( V_1 ) ;
F_42 ( & V_1 -> V_95 ) ;
return F_43 ( V_64 ) ;
}
static int F_44 ( struct V_1 * V_1 )
{
unsigned int V_96 ;
int V_31 ;
if ( V_1 -> V_22 ) {
if ( V_1 -> V_32 < 0 )
F_37 ( V_1 ) ;
else
return 0 ;
}
V_31 = F_36 ( V_1 , V_97 , F_15 ( V_98 ) ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_21 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_36 ( V_1 , V_94 , F_15 ( V_99 ) ) ;
if ( V_31 < 0 )
goto V_62;
V_1 -> V_22 = F_45 ( V_1 -> V_43 -> V_53 ,
V_100 ,
V_1 -> V_50 . V_101 ,
V_1 -> V_43 -> V_51 ,
4 , F_12 , V_1 ) ;
if ( F_46 ( V_1 -> V_22 ) ) {
V_31 = F_47 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
goto V_62;
}
for ( V_96 = 0 ; V_96 < V_44 ; ++ V_96 ) {
V_31 = F_18 ( V_1 -> V_22 , & V_39 ,
& V_1 -> V_33 . V_40 ,
V_1 -> V_33 . V_34 [ V_96 ] . V_41 ) ;
if ( V_31 < 0 )
goto V_102;
}
V_1 -> V_38 = true ;
V_1 -> V_32 = 0 ;
V_31 = F_48 ( V_1 -> V_22 , - 1 , 0 ,
V_103 ) ;
if ( V_31 < 0 )
goto V_102;
return 0 ;
V_102:
F_39 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
V_62:
F_24 ( & V_1 -> V_50 ) ;
F_36 ( V_1 , V_94 , 0 ) ;
error:
return V_31 ;
}
static int F_49 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
int V_31 ;
V_1 -> V_7 = 0 ;
V_1 -> V_9 = 0 ;
F_41 ( & V_1 -> V_95 ) ;
V_31 = F_44 ( V_1 ) ;
F_42 ( & V_1 -> V_95 ) ;
return V_31 ;
}
static int F_50 ( struct V_63 * V_64 , int V_104 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
switch ( V_104 ) {
case V_105 :
F_3 ( V_1 -> V_13 ) = true ;
break;
case V_106 :
F_3 ( V_1 -> V_13 ) = false ;
break;
default:
return - V_107 ;
}
return 0 ;
}
static T_5 F_51 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = V_64 -> V_88 ;
return F_3 ( V_1 -> V_7 ) ;
}
static int F_52 ( struct V_1 * V_1 )
{
static struct V_108 V_109 = {
. V_110 = F_27 ,
. V_111 = F_29 ,
. V_112 = V_113 ,
. V_92 = F_31 ,
. V_114 = F_40 ,
. V_115 = F_49 ,
. V_116 = F_50 ,
. V_117 = F_51 ,
. V_118 = V_119 ,
. V_120 = V_121 ,
} ;
struct V_122 * V_5 ;
int V_31 ;
V_31 = F_53 ( V_1 -> V_53 , L_2 , 0 , 0 , 1 , & V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
V_5 -> V_88 = V_1 ;
strcpy ( V_5 -> V_123 , L_2 ) ;
V_1 -> V_5 = V_5 -> V_124 [ V_125 ] . V_64 ;
V_1 -> V_5 -> V_109 = & V_109 ;
return 0 ;
}
static int F_54 ( struct V_126 * V_127 ,
struct V_128 * V_67 )
{
struct V_1 * V_1 = V_127 -> V_88 ;
V_67 -> type = V_129 ;
V_67 -> V_2 = 1 ;
V_67 -> V_48 . integer . V_130 = V_1 -> V_131 ;
V_67 -> V_48 . integer . V_132 = V_1 -> V_133 ;
return 0 ;
}
static int F_55 ( struct V_126 * V_127 ,
struct V_134 * V_48 )
{
struct V_1 * V_1 = V_127 -> V_88 ;
T_4 V_135 ;
int V_31 ;
V_31 = F_34 ( V_1 , V_136 , & V_135 ) ;
if ( V_31 < 0 )
return V_31 ;
V_48 -> V_48 . integer . V_48 [ 0 ] = ( V_137 ) F_16 ( V_135 ) ;
return 0 ;
}
static int F_56 ( struct V_126 * V_127 ,
struct V_134 * V_48 )
{
struct V_1 * V_1 = V_127 -> V_88 ;
if ( V_48 -> V_48 . integer . V_48 [ 0 ] < V_1 -> V_131 ||
V_48 -> V_48 . integer . V_48 [ 0 ] > V_1 -> V_133 )
return - V_107 ;
return F_36 ( V_1 , V_136 ,
F_15 ( V_48 -> V_48 . integer . V_48 [ 0 ] ) ) ;
}
static int F_57 ( struct V_126 * V_127 ,
struct V_134 * V_48 )
{
struct V_1 * V_1 = V_127 -> V_88 ;
T_4 V_138 ;
int V_31 ;
V_31 = F_34 ( V_1 , V_139 , & V_138 ) ;
if ( V_31 < 0 )
return V_31 ;
V_48 -> V_48 . integer . V_48 [ 0 ] = ! V_138 ;
return 0 ;
}
static int F_58 ( struct V_126 * V_127 ,
struct V_134 * V_48 )
{
struct V_1 * V_1 = V_127 -> V_88 ;
return F_36 ( V_1 , V_139 ,
( V_140 T_4 ) ! V_48 -> V_48 . integer . V_48 [ 0 ] ) ;
}
static int F_59 ( struct V_1 * V_1 )
{
static const struct V_141 V_142 = {
. V_143 = V_144 ,
. V_123 = L_3 ,
. V_145 = V_146 |
V_147 ,
. V_67 = F_54 ,
. V_148 = F_55 ,
. V_149 = F_56 ,
} ;
static const struct V_141 V_150 = {
. V_143 = V_144 ,
. V_123 = L_4 ,
. V_67 = V_151 ,
. V_148 = F_57 ,
. V_149 = F_58 ,
} ;
T_4 V_48 ;
struct V_126 * V_127 ;
int V_31 ;
V_31 = F_34 ( V_1 , V_152 , & V_48 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_131 = F_16 ( V_48 ) ;
V_31 = F_34 ( V_1 , V_153 , & V_48 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_133 = F_16 ( V_48 ) ;
V_1 -> V_154 [ 0 ] = V_155 ;
V_1 -> V_154 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_31 = F_34 ( V_1 , V_156 , & V_48 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_154 [ 2 ] = ( V_137 ) F_16 ( V_48 ) * 100 ;
V_31 = F_34 ( V_1 , V_157 , & V_48 ) ;
if ( V_31 < 0 )
return V_31 ;
V_1 -> V_154 [ 3 ] = ( V_137 ) F_16 ( V_48 ) * 100 ;
V_127 = F_60 ( & V_142 , V_1 ) ;
if ( V_127 )
V_127 -> V_158 . V_159 = V_1 -> V_154 ;
V_31 = F_61 ( V_1 -> V_53 , V_127 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_61 ( V_1 -> V_53 , F_60 ( & V_150 , V_1 ) ) ;
if ( V_31 < 0 )
return V_31 ;
return 0 ;
}
static void F_62 ( struct V_160 * V_53 )
{
struct V_1 * V_1 = V_53 -> V_88 ;
F_63 ( & V_1 -> V_50 ) ;
F_64 ( V_1 -> V_42 ) ;
F_65 ( V_1 -> V_43 ) ;
F_66 ( & V_1 -> V_95 ) ;
}
static T_6 F_67 ( struct V_161 * V_42 )
{
struct V_162 V_96 ;
int V_163 , V_48 ;
F_68 ( & V_96 , V_42 -> V_164 ) ;
while ( F_69 ( & V_96 , & V_163 , & V_48 ) )
if ( V_163 == V_165 )
return V_166 + V_48 * 4 ;
return 0 ;
}
static int F_70 ( struct V_43 * V_167 )
{
struct V_161 * V_42 = V_161 ( V_167 ) ;
struct V_168 * V_169 = F_71 ( V_42 ) ;
struct V_160 * V_53 ;
struct V_1 * V_1 ;
int V_31 ;
V_31 = F_72 ( - 1 , NULL , V_170 , sizeof( * V_1 ) , & V_53 ) ;
if ( V_31 < 0 )
return V_31 ;
F_73 ( V_53 , V_167 ) ;
V_1 = V_53 -> V_88 ;
V_1 -> V_53 = V_53 ;
F_74 ( & V_1 -> V_95 ) ;
V_1 -> V_42 = F_75 ( V_42 ) ;
V_1 -> V_43 = F_76 ( V_169 ) ;
V_1 -> V_57 = F_67 ( V_42 ) ;
if ( ! V_1 -> V_57 ) {
F_19 ( & V_42 -> V_43 , L_5 ) ;
V_31 = - V_171 ;
goto V_172;
}
F_77 ( & V_1 -> V_50 , V_42 ) ;
V_53 -> V_173 = F_62 ;
strcpy ( V_53 -> V_174 , L_2 ) ;
strcpy ( V_53 -> V_175 , L_6 ) ;
snprintf ( V_53 -> V_176 , sizeof( V_53 -> V_176 ) ,
L_7 ,
V_169 -> V_177 [ 3 ] , V_169 -> V_177 [ 4 ] ,
F_78 ( & V_42 -> V_43 ) , 100 << V_169 -> V_51 ) ;
strcpy ( V_53 -> V_178 , L_2 ) ;
V_31 = F_52 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_59 ( V_1 ) ;
if ( V_31 < 0 )
goto error;
V_31 = F_79 ( V_53 ) ;
if ( V_31 < 0 )
goto error;
F_80 ( V_167 , V_1 ) ;
return 0 ;
V_172:
F_64 ( V_1 -> V_42 ) ;
F_65 ( V_1 -> V_43 ) ;
F_66 ( & V_1 -> V_95 ) ;
error:
F_81 ( V_53 ) ;
return V_31 ;
}
static int F_82 ( struct V_43 * V_179 )
{
struct V_1 * V_1 = F_83 ( V_179 ) ;
F_6 ( V_1 ) ;
F_84 ( V_1 -> V_53 ) ;
F_41 ( & V_1 -> V_95 ) ;
F_37 ( V_1 ) ;
F_42 ( & V_1 -> V_95 ) ;
F_85 ( V_1 -> V_53 ) ;
return 0 ;
}
static void F_86 ( struct V_161 * V_42 )
{
struct V_1 * V_1 = F_83 ( & V_42 -> V_43 ) ;
if ( F_87 ( & V_1 -> V_50 ) < 0 ) {
F_6 ( V_1 ) ;
F_41 ( & V_1 -> V_95 ) ;
F_37 ( V_1 ) ;
F_42 ( & V_1 -> V_95 ) ;
}
}
static int T_7 F_88 ( void )
{
return F_89 ( & V_180 . V_174 ) ;
}
static void T_8 F_90 ( void )
{
F_91 ( & V_180 . V_174 ) ;
}
