static inline int F_1 ( enum V_1 V_2 )
{
return ( V_2 == V_3 || V_2 == V_4 ) ;
}
static inline int F_2 ( enum V_1 V_2 )
{
return ( V_2 == V_5 || V_2 == V_6 ) ;
}
static inline int F_3 ( enum V_1 V_2 )
{
return ( V_2 == V_7 || V_2 == V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 , int V_11 ,
void * V_12 , int V_13 )
{
return F_5 ( V_10 , F_6 ( V_10 , 0 ) , V_14 ,
V_15 | V_16 |
V_17 , V_11 , 0 , V_12 , V_13 ,
V_18 ) ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_5 ( V_10 , F_8 ( V_10 , 0 ) , V_22 ,
V_15 | V_23 | V_17 ,
0 , 0 , V_20 , sizeof( struct V_19 ) ,
V_18 ) ;
return V_21 ;
}
static int F_9 ( struct V_9 * V_10 , T_1 * V_24 )
{
int V_21 ;
V_21 = F_5 ( V_10 , F_8 ( V_10 , 0 ) , V_25 ,
V_15 | V_23 | V_17 ,
0 , 0 , V_24 , 1 , V_18 ) ;
return V_21 ;
}
static inline unsigned long F_10 ( struct V_19 * V_26 )
{
return F_11 ( ( V_26 -> V_27 [ 2 ] << 16 )
| ( V_26 -> V_27 [ 1 ] << 8 )
| ( V_26 -> V_27 [ 0 ] ) ) ;
}
static int F_12 ( struct V_9 * V_10 , T_1 * V_28 , T_2 V_13 ,
int V_29 )
{
T_1 * V_12 ;
struct V_19 V_30 ;
int V_21 = 0 ;
int V_31 = 1 ;
int V_32 = 0 ;
T_1 V_33 = 0 ;
T_2 V_34 = 0 ;
int V_35 = 0 ;
int V_11 = 0 ;
F_13 ( V_36 , L_1 , V_37 , V_28 , V_13 ,
V_29 ) ;
if ( ! V_13 ) {
F_14 ( & V_10 -> V_38 , L_2 ) ;
return - V_39 ;
}
V_12 = F_15 ( V_40 , V_41 ) ;
if ( ! V_12 )
return - V_42 ;
do {
if ( V_31 ) {
V_21 = F_9 ( V_10 , & V_33 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 ,
L_3 , V_21 ) ;
goto exit;
}
V_31 = 0 ;
}
switch ( V_33 ) {
case V_43 :
F_13 ( V_36 , L_4 ) ;
V_21 = F_7 ( V_10 , & V_30 ) ;
if ( V_21 >= 0 ) {
V_33 = V_30 . V_24 ;
V_34 = F_10 ( & V_30 ) ;
V_31 = 0 ;
} else
F_14 ( & V_10 -> V_38 ,
L_5 ,
V_21 ) ;
break;
case V_44 :
F_13 ( V_36 , L_6 ) ;
V_31 = 1 ;
F_13 ( V_36 , L_7 ) ;
F_16 ( V_34 ) ;
break;
case V_45 :
F_13 ( V_36 , L_8 ) ;
case V_46 :
F_13 ( V_36 , L_9 ) ;
V_35 = F_17 ( int , V_13 , V_40 ) ;
memcpy ( V_12 , V_28 , V_35 ) ;
F_13 ( V_36 , L_10
L_11 , V_13 , V_35 ,
V_11 ) ;
V_21 =
F_4 ( V_10 , V_11 , V_12 , V_35 ) ;
V_28 += V_35 ;
V_13 -= V_35 ;
V_11 ++ ;
if ( V_21 != V_35 )
F_14 ( & V_10 -> V_38 ,
L_12 ,
V_21 ) ;
V_31 = 1 ;
break;
case V_47 :
F_13 ( V_36 , L_13 ) ;
V_21 = F_7 ( V_10 , & V_30 ) ;
if ( V_21 < 0 )
break;
V_33 = V_30 . V_24 ;
V_34 = F_10 ( & V_30 ) ;
V_31 = 0 ;
if ( V_29 > 0 )
V_34 = V_29 ;
F_13 ( V_36 , L_14 ) ;
F_16 ( V_34 ) ;
break;
case V_48 :
F_13 ( V_36 , L_15 ) ;
V_32 = 1 ;
break;
case V_49 :
F_13 ( V_36 , L_16 ) ;
V_32 = 1 ;
break;
case V_50 :
F_13 ( V_36 , L_17 ) ;
break;
case V_51 :
F_13 ( V_36 , L_18 ) ;
V_21 = - V_52 ;
break;
default:
F_13 ( V_36 , L_19 , V_33 ) ;
V_21 = - V_39 ;
break;
}
} while ( ! V_32 && ( V_21 >= 0 ) );
exit:
F_18 ( V_12 ) ;
if ( V_21 >= 0 )
V_21 = 0 ;
return V_21 ;
}
static void F_19 ( unsigned long V_53 )
{
static int V_54 ;
if ( V_54 != V_55 ) {
V_54 = V_55 ;
F_20 ( V_56 , V_57 ) ;
F_21 ( & V_58 , V_59 + V_60 / 4 ) ;
} else
F_20 ( V_56 , V_61 ) ;
}
static void F_22 ( void )
{
V_55 ++ ;
if ( ! F_23 ( & V_58 ) )
F_21 ( & V_58 , V_59 + V_60 / 4 ) ;
}
static int F_24 ( struct V_9 * V_10 )
{
int V_21 ;
V_21 = F_5 ( V_10 , F_6 ( V_10 , 0 ) , 0x0a ,
V_62 | V_16 |
V_17 , 0 , 0 , NULL , 0 ,
V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
int V_21 ;
T_1 V_63 ;
T_1 * V_64 ;
V_64 = F_15 ( 1 , V_65 ) ;
if ( ! V_64 )
return - V_42 ;
V_21 = F_5 ( V_10 , F_8 ( V_10 , 0 ) , 0x33 ,
V_62 | V_23 |
V_17 , 0x01 , 0 , V_64 , 1 ,
V_18 ) ;
V_63 = * V_64 ;
F_18 ( V_64 ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 < 1 )
return - V_66 ;
else
return V_63 ;
}
static inline int F_26 ( struct V_9 * V_10 , int V_11 ,
void * V_12 , int V_13 )
{
return F_5 ( V_10 , F_6 ( V_10 , 0 ) , 0x0e ,
V_62 | V_16 | V_67 ,
0x0802 , V_11 , V_12 , V_13 ,
V_18 ) ;
}
static inline int F_27 ( struct V_9 * V_10 ,
union V_68 * V_28 , int V_69 )
{
return F_5 ( V_10 , F_8 ( V_10 , 0 ) , 0x33 ,
V_62 | V_23 |
V_17 , 0x0a02 , 0 ,
V_28 , V_69 , V_18 ) ;
}
static inline int F_28 ( struct V_9 * V_10 ,
union V_68 * V_28 , int V_69 )
{
return F_5 ( V_10 , F_8 ( V_10 , 0 ) , 0x33 ,
V_62 | V_23 |
V_17 , 0x0902 , 0 ,
V_28 , V_69 , V_18 ) ;
}
static int F_29 ( struct V_70 * V_71 )
{
int V_21 ;
union V_68 * V_72 = F_15 ( sizeof( * V_72 ) , V_41 ) ;
if ( ! V_72 )
return - V_42 ;
if ( F_1 ( V_71 -> V_1 ) ) {
V_21 = F_28 ( V_71 -> V_10 , V_72 ,
sizeof( V_72 -> V_73 ) ) ;
if ( V_21 < 0 )
goto exit;
memcpy ( V_71 -> V_74 , V_72 -> V_73 . V_74 , V_75 ) ;
V_71 -> V_76 = V_72 -> V_73 . V_76 ;
} else if ( F_2 ( V_71 -> V_1 ) ) {
V_21 = F_27 ( V_71 -> V_10 , V_72 , sizeof( V_72 -> V_77 ) ) ;
if ( V_21 < 0 )
goto exit;
memcpy ( V_71 -> V_74 , V_72 -> V_77 . V_74 , V_75 ) ;
V_71 -> V_76 = V_72 -> V_77 . V_76 ;
} else {
V_21 = F_27 ( V_71 -> V_10 , V_72 , sizeof( V_72 -> V_78 ) ) ;
if ( V_21 < 0 )
goto exit;
memcpy ( V_71 -> V_74 , V_72 -> V_78 . V_74 , V_75 ) ;
V_71 -> V_76 = V_72 -> V_78 . V_76 ;
}
exit:
F_18 ( V_72 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 , L_20 ,
V_21 ) ;
return V_21 ;
}
static struct V_81 const * F_31 ( T_3 V_82 )
{
int V_73 ;
static struct V_81 const V_83 [] = {
{ 0x10 , L_21 , 0x7ff } ,
{ 0x20 , L_22 , 0x7ff } ,
{ 0x30 , L_23 , 0x1fff } ,
{ 0x31 , L_24 , 0x600 } ,
{ 0x32 , L_25 , 0x1e00 } ,
{ 0x40 , L_26 , 0x2000 } ,
{ 0x41 , L_27 , 0x3fff } ,
{ 0x50 , L_28 , 0x3fc } ,
{ 0x00 , L_29 , 0xffffffff }
} ;
for ( V_73 = 0 ; V_73 < F_32 ( V_83 ) - 1 ; V_73 ++ )
if ( V_82 == V_83 [ V_73 ] . V_82 )
break;
return & V_83 [ V_73 ] ;
}
static inline int F_33 ( struct V_9 * V_10 , T_3 V_84 , void * V_28 ,
int V_69 )
{
int V_21 ;
V_21 = F_5 ( V_10 , F_8 ( V_10 , 0 ) , 0x33 ,
V_62 | V_23 |
V_17 , V_84 << 8 , 0 , V_28 , V_69 ,
V_18 ) ;
if ( V_21 >= 0 && V_21 != V_69 )
return - V_66 ;
return V_21 ;
}
static inline int F_34 ( struct V_9 * V_10 , T_1 V_85 )
{
T_1 * V_86 ;
int V_21 ;
V_86 = F_15 ( 40 , V_65 ) ;
if ( ! V_86 )
return - V_42 ;
V_21 = F_5 ( V_10 , F_8 ( V_10 , 0 ) , 0x22 ,
V_62 | V_23 |
V_17 , V_85 , 0 , V_86 ,
40 , V_18 ) ;
if ( V_21 >= 0 )
V_21 = V_86 [ 5 ] ;
F_18 ( V_86 ) ;
return V_21 ;
}
static const char * F_35 ( T_1 V_87 )
{
switch ( V_87 ) {
F_36 ( V_88 ) ;
F_36 ( V_89 ) ;
F_36 ( V_90 ) ;
F_36 ( V_91 ) ;
F_36 ( V_92 ) ;
F_36 ( V_93 ) ;
F_36 ( V_94 ) ;
F_36 ( V_95 ) ;
}
return L_30 ;
}
static int F_37 ( struct V_9 * V_10 , T_1 V_85 , void * V_28 ,
int V_69 )
{
int V_21 ;
struct V_96 * V_97 = F_15 ( sizeof( struct V_96 ) +
V_69 , V_41 ) ;
if ( ! V_97 )
return - V_42 ;
V_97 -> V_85 = V_85 ;
V_97 -> V_98 = 0 ;
V_97 -> V_13 = F_38 ( V_69 ) ;
memcpy ( V_97 -> V_53 , V_28 , V_69 ) ;
F_39 ( V_99 , V_97 , sizeof( struct V_96 ) + V_69 ,
L_31 ,
F_35 ( V_85 ) , V_85 ) ;
V_21 = F_5 ( V_10 , F_6 ( V_10 , 0 ) , 0x0e ,
V_62 | V_16 | V_67 ,
0 , 0 , V_97 ,
sizeof( struct V_96 ) + V_69 ,
V_18 ) ;
F_18 ( V_97 ) ;
return V_21 ;
}
static const char * F_40 ( T_1 V_87 )
{
switch ( V_87 ) {
F_41 ( V_100 ) ;
F_41 ( V_101 ) ;
F_41 ( V_102 ) ;
F_41 ( V_103 ) ;
F_41 ( V_104 ) ;
F_41 ( V_105 ) ;
F_41 ( V_106 ) ;
F_41 ( V_107 ) ;
F_41 ( V_108 ) ;
}
return L_30 ;
}
static int F_42 ( struct V_70 * V_71 , int V_85 )
{
int V_20 = 0 ;
unsigned long V_109 = V_59 + V_110 ;
do {
V_20 = F_34 ( V_71 -> V_10 , V_85 ) ;
if ( V_20 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_32 ,
V_20 ) ;
break;
}
F_13 ( V_111 ,
L_33 ,
F_43 ( V_71 -> V_79 -> V_80 ) , V_85 , V_20 ,
F_40 ( V_20 ) ) ;
if ( V_20 != V_106
&& V_20 != V_100 )
break;
F_16 ( V_60 / 10 ) ;
if ( F_44 ( V_59 , V_109 ) ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_34 , V_85 ) ;
V_20 = - V_112 ;
break;
}
} while ( 1 );
return V_20 ;
}
static int F_45 ( struct V_70 * V_71 , struct V_113 * V_28 )
{
int V_21 ;
V_21 = F_37 ( V_71 -> V_10 , V_88 , V_28 ,
F_46 ( struct V_113 ,
V_53 ) + V_28 -> V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_42 ( V_71 , V_88 ) ;
if ( V_21 != V_101 ) {
F_47 ( V_71 -> V_79 -> V_80 ,
L_35 ,
V_21 ) ;
V_21 = - V_66 ;
}
return V_21 ;
}
static int F_48 ( struct V_70 * V_71 , int V_114 )
{
int V_21 ;
int V_85 ;
if ( V_71 -> V_115 == V_114 )
return 0 ;
V_85 = V_114 ? V_93 : V_94 ;
V_21 = F_37 ( V_71 -> V_10 , V_85 , NULL , 0 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_36 , V_85 , V_21 ) ;
else
V_21 = 1 ;
V_71 -> V_115 = V_114 ;
return V_21 ;
}
static int F_49 ( struct V_70 * V_71 )
{
int V_21 = 0 ;
V_71 -> V_116 . type = V_117 ;
V_71 -> V_116 . V_13 = 1 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_119 , V_120 ) ;
V_71 -> V_116 . V_53 . V_121 = V_71 -> V_122 ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 , L_37 ,
V_21 ) ;
return V_21 ;
}
static int F_50 ( struct V_70 * V_71 , T_1 type )
{
int V_21 = 0 ;
V_71 -> V_116 . type = V_123 ;
V_71 -> V_116 . V_13 = 1 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_124 , V_125 ) ;
V_71 -> V_116 . V_53 . V_121 = type ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 , L_38 ,
V_21 ) ;
return V_21 ;
}
static int F_51 ( struct V_70 * V_71 , T_3 V_13 )
{
int V_21 = 0 ;
V_71 -> V_116 . type = V_126 ;
V_71 -> V_116 . V_13 = 2 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_127 , V_128 ) ;
V_71 -> V_116 . V_53 . V_129 = F_38 ( V_13 ) ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_39 , V_21 ) ;
return V_21 ;
}
static int F_52 ( struct V_70 * V_71 , T_3 V_13 )
{
int V_21 = 0 ;
V_71 -> V_116 . type = V_126 ;
V_71 -> V_116 . V_13 = 2 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_127 , V_130 ) ;
V_71 -> V_116 . V_53 . V_129 = F_38 ( V_13 ) ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 , L_40 , V_21 ) ;
return V_21 ;
}
static int F_53 ( struct V_70 * V_71 , int V_131 )
{
int V_21 = 0 ;
V_71 -> V_116 . type = V_123 ;
V_71 -> V_116 . V_13 = 1 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_124 , V_132 ) ;
V_71 -> V_116 . V_53 . V_121 = V_131 ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_41 , V_21 ) ;
return V_21 ;
}
static void F_54 ( struct V_70 * V_71 )
{
int V_73 ;
int V_21 ;
struct V_133 * V_134 = F_15 ( sizeof( struct V_133 ) ,
V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_135 , V_134 ,
sizeof( struct V_133 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_42 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_43 ,
F_43 ( V_71 -> V_79 -> V_80 ) ,
V_134 -> V_74 , V_134 -> V_137 [ 0 ] , V_134 -> V_137 [ 1 ] ) ;
for ( V_73 = 0 ; V_73 < F_32 ( V_134 -> V_138 ) ; V_73 ++ )
F_13 ( V_136 , L_44
L_45 , F_43 ( V_71 -> V_79 -> V_80 ) , V_73 ,
V_134 -> V_138 [ V_73 ] , V_134 -> V_139 [ V_73 ] ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_55 ( struct V_70 * V_71 )
{
int V_73 ;
int V_21 ;
int V_140 ;
struct V_141 * V_134 = F_15 ( sizeof( struct V_141 ) , V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_142 , V_134 ,
sizeof( struct V_141 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_46 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_47
L_48
L_49 , F_43 ( V_71 -> V_79 -> V_80 ) ,
V_134 -> V_143 , V_134 -> V_144 ,
V_134 -> V_145 , V_134 -> V_146 ,
F_56 ( V_134 -> V_147 ) ,
F_56 ( V_134 -> V_148 ) , V_134 -> V_149 ,
V_134 -> V_144 ) ;
V_140 = ( V_134 -> V_149 == 1 ) ?
V_150 : V_151 ;
for ( V_73 = 0 ; V_73 < V_152 ; V_73 ++ )
F_13 ( V_136 , L_50 ,
F_43 ( V_71 -> V_79 -> V_80 ) , V_73 ,
V_140 , V_134 -> V_153 [ V_73 ] ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_57 ( struct V_70 * V_71 )
{
int V_21 ;
struct V_119 * V_134 = F_15 ( sizeof( struct V_119 ) ,
V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_117 , V_134 ,
sizeof( struct V_119 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_51 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_52
L_53
L_54
L_55
L_56
L_57
L_58 ,
F_43 ( V_71 -> V_79 -> V_80 ) , F_58 ( V_134 -> V_154 ) ,
F_58 ( V_134 -> V_155 ) ,
F_58 ( V_134 -> V_156 ) ,
F_58 ( V_134 -> V_157 ) , F_58 ( V_134 -> V_158 ) ,
V_134 -> V_159 , V_134 -> V_160 , V_134 -> V_161 ,
V_134 -> V_162 , V_134 -> V_163 ,
V_164 , V_134 -> V_165 ,
V_134 -> V_166 , V_134 -> V_120 , V_134 -> V_167 ,
V_134 -> V_137 , V_134 -> V_168 ,
V_134 -> V_169 , V_134 -> V_170 ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_59 ( struct V_70 * V_71 )
{
int V_21 ;
struct V_127 * V_134 = F_15 ( sizeof( struct V_127 ) , V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_126 , V_134 , sizeof( struct V_127 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_59 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_60
L_61
L_62
L_63
L_64
L_65 ,
F_43 ( V_71 -> V_79 -> V_80 ) ,
F_56 ( V_134 -> V_171 ) ,
F_56 ( V_134 -> V_172 ) ,
F_58 ( V_134 -> V_128 ) , F_58 ( V_134 -> V_130 ) ,
F_58 ( V_134 -> V_173 ) , F_58 ( V_134 -> V_174 ) ,
V_134 -> V_175 , V_134 -> V_176 , V_134 -> V_177 ,
V_134 -> V_178 , F_58 ( V_134 -> V_179 ) ,
F_58 ( V_134 -> V_180 ) ,
F_58 ( V_134 -> V_181 ) ,
F_58 ( V_134 -> V_182 ) ,
V_164 , V_134 -> V_183 ,
V_134 -> V_184 , V_134 -> V_185 ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_60 ( struct V_70 * V_71 )
{
int V_21 ;
struct V_186 * V_134 = F_15 ( sizeof( struct V_186 ) , V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_187 , V_134 , sizeof( struct V_186 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_66 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_67
L_68
L_69
L_70
L_71 ,
F_43 ( V_71 -> V_79 -> V_80 ) , F_56 ( V_134 -> V_188 ) ,
F_58 ( V_134 -> V_189 ) , F_58 ( V_134 -> V_190 ) ,
F_58 ( V_134 -> V_191 ) ,
F_58 ( V_134 -> V_192 ) ,
F_58 ( V_134 -> V_193 ) ,
F_58 ( V_134 -> V_194 ) , V_134 -> V_195 [ 0 ] ,
V_134 -> V_195 [ 1 ] , V_134 -> V_195 [ 2 ] ,
V_134 -> V_195 [ 3 ] , V_134 -> V_196 , V_134 -> V_197 ,
V_134 -> V_198 , V_134 -> V_199 ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_61 ( struct V_70 * V_71 )
{
int V_21 ;
struct V_124 * V_134 = F_15 ( sizeof( * V_134 ) , V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_123 , V_134 , sizeof( * V_134 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_72 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_73
L_74
L_75 , F_43 ( V_71 -> V_79 -> V_80 ) ,
V_134 -> V_200 ,
V_134 -> V_132 , V_134 -> V_201 , V_134 -> V_202 ,
V_134 -> V_125 ) ;
exit:
F_18 ( V_134 ) ;
}
static void F_62 ( struct V_70 * V_71 )
{
int V_21 ;
struct V_203 * V_134 = F_15 ( sizeof( struct V_203 ) , V_41 ) ;
if ( ! V_134 )
return;
V_21 = F_33 ( V_71 -> V_10 , V_204 , V_134 ,
sizeof( struct V_203 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_76 , V_21 ) ;
goto exit;
}
F_13 ( V_136 , L_77 ,
F_43 ( V_71 -> V_79 -> V_80 ) ,
( int ) sizeof( V_134 -> V_205 ) , V_134 -> V_205 ) ;
F_13 ( V_136 , L_78 ,
F_43 ( V_71 -> V_79 -> V_80 ) ,
( int ) sizeof( V_134 -> V_206 ) , V_134 -> V_206 ) ;
exit:
F_18 ( V_134 ) ;
}
static int F_63 ( struct V_70 * V_71 )
{
struct V_207 V_208 ;
int V_21 ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
memset ( V_208 . V_209 , 0xff , V_75 ) ;
V_208 . V_210 = V_71 -> V_210 ;
V_208 . V_177 = V_211 ;
V_208 . V_212 = 0 ;
V_208 . V_180 = F_38 ( V_71 -> V_213 ) ;
V_208 . V_181 = F_38 ( V_71 -> V_214 ) ;
V_208 . V_179 = F_38 ( 0 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_90 , & V_208 , sizeof( V_208 ) ) ;
if ( V_21 >= 0 )
V_21 = F_34 ( V_71 -> V_10 , V_90 ) ;
return V_21 ;
}
static inline int F_64 ( int V_215 )
{
V_215 += V_216 ;
V_215 = V_215 % 64 ;
if ( V_215 < 50 )
return 50 - V_215 ;
if ( V_215 >= 61 )
return 64 + 50 - V_215 ;
return 0 ;
}
static void F_65 ( struct V_217 * V_217 )
{
struct V_70 * V_71 = V_217 -> V_218 ;
V_71 -> V_219 . V_53 = ( unsigned long ) V_217 ;
F_66 ( & V_71 -> V_219 ) ;
}
static int F_67 ( struct V_70 * V_71 )
{
int V_21 ;
int V_13 ;
struct V_220 * V_221 = V_71 -> V_222 ;
if ( ! V_71 -> V_223 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_79 ,
V_37 ) ;
return - V_224 ;
}
if ( ! V_221 ) {
V_221 = F_68 ( sizeof( struct V_225 ) ) ;
if ( ! V_221 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_80 ) ;
V_21 = - V_42 ;
goto exit;
}
V_71 -> V_222 = V_221 ;
} else {
F_69 ( V_221 , F_70 ( V_221 ) ) ;
F_71 ( V_221 , 0 ) ;
}
V_13 = F_72 ( V_221 ) ;
F_73 ( V_71 -> V_223 , V_71 -> V_10 , V_71 -> V_226 ,
F_74 ( V_221 , V_13 ) , V_13 , F_65 , V_71 ) ;
V_21 = F_75 ( V_71 -> V_223 , V_227 ) ;
if ( V_21 < 0 ) {
if ( V_21 == - V_228 )
F_13 ( V_229 ,
L_81 ) ;
else
F_30 ( V_71 -> V_79 -> V_80 ,
L_82 , V_21 ) ;
}
exit:
if ( V_21 < 0 && V_21 != - V_228 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_83 ) ;
return V_21 ;
}
static int F_76 ( struct V_9 * V_10 , struct V_230 * V_231 )
{
int V_21 ;
int V_64 ;
int V_11 = 0 ;
int V_35 ;
T_1 * V_12 ;
T_1 * V_28 = V_231 -> V_232 ;
int V_13 = V_231 -> V_233 ;
if ( ! V_28 || ! V_13 )
return - V_234 ;
V_64 = F_25 ( V_10 ) ;
F_13 ( V_229 , L_84 , V_64 ) ;
if ( V_64 != V_235 ) {
F_14 ( & V_10 -> V_38 , L_85 , V_64 ) ;
return - V_39 ;
}
V_12 = F_15 ( V_40 , V_41 ) ;
if ( ! V_12 )
return - V_42 ;
F_13 ( V_229 , L_86 ) ;
do {
V_35 = F_17 ( int , V_13 , V_40 ) ;
memcpy ( V_12 , V_28 , V_35 ) ;
F_13 ( V_229 ,
L_87 ,
V_13 , V_35 , V_11 ) ;
V_21 = F_26 ( V_10 , V_11 , V_12 , V_35 ) ;
if ( V_21 != V_35 ) {
F_14 ( & V_10 -> V_38 ,
L_88 ,
V_11 , V_21 ) ;
goto exit;
}
V_28 += V_35 ;
V_13 -= V_35 ;
V_11 ++ ;
} while ( V_35 > 0 );
if ( F_3 ( V_231 -> V_1 ) ) {
F_13 ( V_229 , L_89 ) ;
F_16 ( V_60 / 5 + 1 ) ;
}
exit:
F_18 ( V_12 ) ;
if ( V_21 < 0 )
F_14 ( & V_10 -> V_38 ,
L_90 , V_21 ) ;
return V_21 ;
}
static int F_77 ( struct V_9 * V_10 , struct V_230 * V_231 )
{
int V_21 ;
int V_236 = ! F_3 ( V_231 -> V_1 ) ;
V_21 = F_12 ( V_10 , V_231 -> V_237 , V_231 -> V_238 ,
V_236 ? 0 : 2 * V_60 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 ,
L_91 , V_21 ) ;
goto exit;
}
F_13 ( V_229 , L_92 ) ;
if ( V_236 ) {
V_21 = F_24 ( V_10 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 ,
L_93 , V_21 ) ;
goto exit;
}
}
F_13 ( V_229 , L_94 ) ;
F_16 ( 2 * V_60 + 1 ) ;
F_78 ( V_10 ) ;
exit:
return V_21 ;
}
static int F_79 ( struct V_70 * V_71 )
{
struct V_239 * V_240 = & V_71 -> V_241 ;
int V_21 ;
F_13 ( V_242 ,
L_95
L_96 , F_43 ( V_71 -> V_79 -> V_80 ) , V_71 -> V_243 ,
V_71 -> V_244 , V_164 , V_71 -> V_244 ,
V_71 -> V_245 == V_246 ? L_97 : L_98 ,
V_71 -> V_210 , V_71 -> V_247 ? L_99 : L_100 ,
V_71 -> V_248 , V_71 -> V_249 [ V_71 -> V_248 ] ) ;
F_13 ( V_242 ,
L_101
L_102 , F_43 ( V_71 -> V_79 -> V_80 ) ,
V_250 [ V_71 -> V_125 ] , V_71 -> V_130 ,
V_71 -> V_251 , V_71 -> V_128 ,
V_71 -> V_252 == V_253 ? L_103 : V_71 -> V_252 ==
V_254 ? L_104 : V_71 -> V_252 ==
V_255 ? L_105 : V_71 -> V_252 ==
V_256 ? L_106 : V_71 -> V_252 ==
V_257 ? L_107 : L_108 , V_71 -> V_258 ) ;
F_13 ( V_242 ,
L_109
L_110 ,
F_43 ( V_71 -> V_79 -> V_80 ) , V_71 -> V_122 , V_71 -> V_259 ,
V_71 -> V_258 == V_260 ? L_111 : L_112 ,
V_71 -> V_213 , V_71 -> V_214 ,
V_71 -> V_261 == V_262 ? L_113 : L_114 ) ;
memset ( V_240 , 0 , sizeof( struct V_239 ) ) ;
V_240 -> V_202 = 0 ;
V_240 -> V_251 = V_71 -> V_251 ;
if ( V_71 -> V_247 ) {
if ( V_71 -> V_249 [ V_71 -> V_248 ] > V_150 )
V_240 -> V_263 = 2 ;
else
V_240 -> V_263 = 1 ;
V_240 -> V_146 = 1 ;
} else {
V_240 -> V_146 = 0 ;
V_240 -> V_263 = 0 ;
}
V_240 -> V_130 = F_38 ( V_71 -> V_130 ) ;
V_240 -> V_264 = F_38 ( V_71 -> V_128 ) ;
memcpy ( V_240 -> V_265 , V_266 , 4 ) ;
V_240 -> V_267 = ( V_71 -> V_252 == V_257 ? 1 : 0 ) ;
V_240 -> V_210 = V_71 -> V_210 ;
V_240 -> V_143 = V_71 -> V_247 ;
memcpy ( V_240 -> V_268 , V_71 -> V_244 , V_164 ) ;
V_240 -> V_269 = V_71 -> V_243 ;
V_240 -> V_144 = V_71 -> V_248 ;
memcpy ( V_240 -> V_270 , V_71 -> V_271 ,
sizeof( V_71 -> V_271 ) ) ;
V_240 -> V_272 = V_71 -> V_125 ;
V_240 -> V_154 = F_38 ( V_71 -> V_154 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_95 , & V_71 -> V_241 ,
sizeof( struct V_239 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_115 ,
V_21 ) ;
return V_21 ;
}
F_42 ( V_71 , V_95 ) ;
memset ( V_71 -> V_209 , 0 , V_75 ) ;
if ( F_48 ( V_71 , 1 ) == 1 )
F_42 ( V_71 , V_93 ) ;
V_21 = F_50 ( V_71 , V_71 -> V_125 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_51 ( V_71 , V_71 -> V_128 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_52 ( V_71 , V_71 -> V_130 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_53 ( V_71 ,
V_71 -> V_252 == V_257 ? 1 : 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_49 ( V_71 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_273 & V_136 ) {
F_59 ( V_71 ) ;
F_54 ( V_71 ) ;
F_57 ( V_71 ) ;
F_55 ( V_71 ) ;
F_62 ( V_71 ) ;
F_60 ( V_71 ) ;
F_61 ( V_71 ) ;
}
return 0 ;
}
static void F_80 ( struct V_274 * V_275 )
{
struct V_70 * V_71 = F_81 ( V_275 , struct V_70 ,
V_276 ) ;
int V_21 = 0 ;
if ( V_71 -> V_277 )
return;
F_82 ( & V_71 -> V_278 ) ;
V_71 -> V_116 . type = V_123 ;
V_71 -> V_116 . V_13 = 1 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_124 , V_202 ) ;
V_71 -> V_116 . V_53 . V_121 = V_71 -> V_279 ? 1 : 0 ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_116 , V_21 ) ;
F_83 ( & V_71 -> V_278 ) ;
}
static void F_84 ( struct V_274 * V_275 )
{
struct V_70 * V_71 = F_81 ( V_275 , struct V_70 ,
V_280 ) ;
F_82 ( & V_71 -> V_278 ) ;
F_67 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
}
static void F_85 ( unsigned long V_281 )
{
struct V_217 * V_217 = (struct V_217 * ) V_281 ;
struct V_70 * V_71 = V_217 -> V_218 ;
struct V_225 * V_28 ;
struct V_282 V_283 = { 0 } ;
if ( V_71 -> V_277 ) {
F_13 ( V_229 , L_117 ) ;
F_13 ( V_229 , L_118 , V_217 -> V_20 ) ;
return;
}
if ( ! V_71 -> V_222 || ! V_71 -> V_222 -> V_53 )
return;
V_28 = (struct V_225 * ) V_71 -> V_222 -> V_53 ;
if ( V_217 -> V_20 != 0 ) {
if ( V_217 -> V_20 != - V_234 && V_217 -> V_20 != - V_284 )
F_13 ( V_285 ,
L_119 ,
V_37 , F_43 ( V_71 -> V_79 -> V_80 ) ,
V_217 -> V_20 ) ;
return;
}
F_13 ( V_286 ,
L_120 ,
F_43 ( V_71 -> V_79 -> V_80 ) , V_28 -> V_287 , V_28 -> V_288 ,
V_28 -> V_289 , V_28 -> V_290 ) ;
F_86 ( V_71 -> V_222 , V_291 ) ;
F_71 ( V_71 -> V_222 , F_58 ( V_28 -> V_292 ) ) ;
F_39 ( V_293 , V_71 -> V_222 -> V_53 ,
V_71 -> V_222 -> V_294 , L_121 , V_71 -> V_222 -> V_294 ) ;
V_283 . signal = V_28 -> V_288 ;
V_283 . V_295 |= V_296 ;
V_283 . V_295 |= V_297 ;
F_13 ( V_298 , L_122 ,
V_71 -> V_222 -> V_294 , V_71 -> V_222 -> V_299 ) ;
memcpy ( F_87 ( V_71 -> V_222 ) , & V_283 , sizeof( V_283 ) ) ;
F_88 ( V_71 -> V_79 , V_71 -> V_222 ) ;
V_71 -> V_222 = NULL ;
F_67 ( V_71 ) ;
}
static struct V_230 * F_89 ( struct V_9 * V_10 ,
enum V_1 V_1 )
{
int V_21 ;
char * V_300 ;
struct V_301 * V_302 ;
struct V_230 * V_231 = & V_303 [ V_1 ] ;
F_82 ( & V_304 ) ;
if ( V_231 -> V_305 ) {
F_13 ( V_306 , L_123 ) ;
goto exit;
}
F_13 ( V_306 , L_124 , V_231 -> V_307 ) ;
V_21 = F_90 ( & V_231 -> V_308 , V_231 -> V_307 , & V_10 -> V_38 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 , L_125 ,
V_231 -> V_307 ) ;
F_14 ( & V_10 -> V_38 ,
L_126 ) ;
goto exit;
}
F_13 ( V_306 , L_127 ) ;
V_302 = (struct V_301 * ) ( V_231 -> V_308 -> V_53 ) ;
if ( V_231 -> V_308 -> V_13 <= sizeof( * V_302 ) ) {
F_14 ( & V_10 -> V_38 ,
L_128 , V_231 -> V_308 -> V_13 ) ;
goto exit;
}
V_231 -> V_1 = F_56 ( V_302 -> V_1 ) ;
if ( V_231 -> V_1 != V_1 ) {
F_14 ( & V_10 -> V_38 ,
L_129 ,
V_1 , V_231 -> V_1 ) ;
goto exit;
}
V_231 -> V_309 . V_310 = V_302 -> V_310 ;
V_231 -> V_309 . V_311 = V_302 -> V_311 ;
V_231 -> V_309 . V_312 = V_302 -> V_312 ;
V_231 -> V_309 . V_313 = V_302 -> V_313 ;
V_300 = ( char * ) V_302 + F_56 ( V_302 -> V_314 ) ;
V_231 -> V_237 = ( T_1 * ) V_302 + F_56 ( V_302 -> V_315 ) ;
V_231 -> V_238 = F_56 ( V_302 -> V_316 ) ;
V_231 -> V_232 = ( T_1 * ) V_302 + F_56 ( V_302 -> V_317 ) ;
V_231 -> V_233 = F_56 ( V_302 -> V_318 ) ;
V_231 -> V_305 = 1 ;
F_91 ( V_319 , & V_10 -> V_38 ,
L_130 ,
V_231 -> V_307 , V_302 -> V_310 , V_302 -> V_311 , V_302 -> V_312 , V_302 -> V_313 ) ;
F_13 ( V_229 , L_131 , V_1 ,
F_56 ( V_302 -> V_315 ) , F_56 ( V_302 -> V_316 ) ,
F_56 ( V_302 -> V_317 ) , F_56 ( V_302 -> V_318 ) ) ;
F_13 ( V_229 , L_132 , V_300 ) ;
exit:
F_83 ( & V_304 ) ;
if ( V_231 -> V_305 )
return V_231 ;
else
return NULL ;
}
static int F_92 ( struct V_70 * V_71 )
{
struct V_320 V_321 ;
int V_21 ;
memset ( & V_321 , 0 , sizeof( struct V_320 ) ) ;
memcpy ( V_321 . V_244 , V_71 -> V_244 , V_71 -> V_243 ) ;
V_321 . V_243 = V_71 -> V_243 ;
memcpy ( V_321 . V_209 , V_71 -> V_209 , V_75 ) ;
V_321 . V_322 = V_323 ;
V_321 . V_210 = V_71 -> V_210 ;
V_321 . V_109 = F_38 ( 2000 ) ;
F_13 ( V_298 , L_133 , V_37 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_91 , & V_321 ,
sizeof( struct V_320 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_115 ,
V_21 ) ;
return 0 ;
}
V_21 = F_42 ( V_71 , V_91 ) ;
F_13 ( V_298 , L_134 , V_37 , V_21 ) ;
if ( V_21 != V_101 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_135 ,
V_21 ) ;
return 0 ;
}
F_49 ( V_71 ) ;
return 0 ;
}
static void F_93 ( struct V_274 * V_275 )
{
struct V_70 * V_71 = F_81 ( V_275 , struct V_70 ,
V_324 ) ;
if ( V_71 -> V_277 )
return;
F_82 ( & V_71 -> V_278 ) ;
if ( F_94 ( V_71 -> V_209 ) )
F_92 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
}
static void F_95 ( struct V_217 * V_217 )
{
struct V_70 * V_71 = V_217 -> V_218 ;
struct V_325 * V_326 = F_96 ( V_71 -> V_327 ) ;
F_13 ( V_298 , L_136 , V_37 ) ;
switch ( V_217 -> V_20 ) {
case 0 :
V_326 -> V_328 |= V_329 ;
break;
case - V_234 :
case - V_284 :
break;
default:
F_13 ( V_285 , L_137 ,
V_37 , V_217 -> V_20 ) ;
break;
}
memset ( & V_326 -> V_20 , 0 , sizeof( V_326 -> V_20 ) ) ;
F_97 ( V_71 -> V_79 , V_71 -> V_327 ) ;
V_71 -> V_327 = NULL ;
F_98 ( V_71 -> V_79 ) ;
}
static void F_99 ( struct V_330 * V_79 ,
struct V_331 * V_332 ,
struct V_220 * V_221 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
struct V_333 * V_334 = V_71 -> V_335 ;
struct V_325 * V_326 = F_96 ( V_221 ) ;
struct V_336 * V_337 = (struct V_336 * ) V_221 -> V_53 ;
int V_338 , V_339 , V_21 ;
F_13 ( V_298 , L_136 , V_37 ) ;
if ( V_71 -> V_340 -> V_20 == - V_341 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_138 , V_37 ) ;
F_100 ( V_221 ) ;
return;
}
if ( V_337 -> V_342 & F_38 ( V_343 ) ) {
if ( ! F_101 ( V_71 -> V_209 , V_337 -> V_209 ) ) {
memcpy ( V_71 -> V_209 , V_337 -> V_209 , V_75 ) ;
F_102 ( V_79 , & V_71 -> V_324 ) ;
F_100 ( V_221 ) ;
return;
}
}
F_103 ( V_79 ) ;
F_22 () ;
F_104 ( V_71 -> V_327 != NULL ) ;
V_71 -> V_327 = V_221 ;
V_338 = F_64 ( V_221 -> V_294 ) ;
V_339 = V_216 + V_221 -> V_294 + V_338 ;
memset ( V_334 , 0 , sizeof( * V_334 ) ) ;
V_334 -> V_338 = V_338 ;
V_334 -> V_292 = F_38 ( V_221 -> V_294 ) ;
V_334 -> V_344 = F_105 ( V_79 , V_326 ) -> V_345 ;
memset ( V_334 -> V_98 , 0 , sizeof( V_334 -> V_98 ) ) ;
memcpy ( V_334 -> V_346 , V_221 -> V_53 , V_221 -> V_294 ) ;
F_13 ( V_347 , L_139 ,
F_43 ( V_71 -> V_79 -> V_80 ) , F_58 ( V_334 -> V_292 ) ,
V_334 -> V_338 , V_334 -> V_344 ) ;
F_39 ( V_348 , V_334 , V_339 ,
L_140 , V_37 , V_339 ) ;
F_73 ( V_71 -> V_340 , V_71 -> V_10 , V_71 -> V_349 , V_334 ,
V_339 , F_95 , V_71 ) ;
V_21 = F_75 ( V_71 -> V_340 , V_227 ) ;
if ( V_21 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_141 , V_21 ) ;
if ( V_21 == - V_39 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_142 ,
V_71 -> V_340 ,
V_71 -> V_340 -> V_350 , V_71 -> V_340 -> V_351 ) ;
}
}
static int F_106 ( struct V_330 * V_79 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_21 ;
F_13 ( V_298 , L_136 , V_37 ) ;
F_82 ( & V_71 -> V_278 ) ;
V_21 = F_67 ( V_71 ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_143 ,
V_21 ) ;
goto error;
}
F_79 ( V_71 ) ;
F_63 ( V_71 ) ;
error:
F_83 ( & V_71 -> V_278 ) ;
return 0 ;
}
static void F_107 ( struct V_330 * V_79 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_298 , L_136 , V_37 ) ;
F_108 ( & V_71 -> V_352 ) ;
F_109 ( & V_71 -> V_324 ) ;
F_109 ( & V_71 -> V_276 ) ;
F_82 ( & V_71 -> V_278 ) ;
if ( ! V_71 -> V_277 ) {
F_48 ( V_71 , 0 ) ;
F_110 ( V_71 -> V_223 ) ;
}
F_83 ( & V_71 -> V_278 ) ;
}
static int F_111 ( struct V_330 * V_79 ,
struct V_353 * V_354 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_21 = 0 ;
F_13 ( V_298 , L_136 , V_37 ) ;
F_82 ( & V_71 -> V_278 ) ;
switch ( V_354 -> type ) {
case V_355 :
V_71 -> V_245 = V_356 ;
break;
default:
V_21 = - V_357 ;
goto exit;
}
exit:
F_83 ( & V_71 -> V_278 ) ;
return V_21 ;
}
static void F_112 ( struct V_330 * V_79 ,
struct V_353 * V_354 )
{
F_13 ( V_298 , L_136 , V_37 ) ;
}
static void F_113 ( struct V_274 * V_275 )
{
struct V_70 * V_71 = F_81 ( V_275 , struct V_70 ,
V_352 . V_275 ) ;
int V_21 ;
if ( V_71 -> V_277 )
return;
F_82 ( & V_71 -> V_278 ) ;
V_21 = F_34 ( V_71 -> V_10 , V_90 ) ;
F_13 ( V_298 , L_144 , V_37 , V_21 ) ;
if ( V_21 != V_101 ) {
F_114 ( V_71 -> V_79 , & V_71 -> V_352 ,
V_358 ) ;
F_83 ( & V_71 -> V_278 ) ;
return;
}
if ( F_94 ( V_71 -> V_209 ) )
F_92 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
F_115 ( V_71 -> V_79 , false ) ;
F_98 ( V_71 -> V_79 ) ;
}
static int F_116 ( struct V_330 * V_79 ,
struct V_353 * V_354 ,
struct V_359 * V_360 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
struct V_207 V_208 ;
T_1 * V_361 = NULL ;
int V_21 , V_294 = 0 ;
F_13 ( V_298 , L_145 , V_37 ) ;
if ( V_71 -> V_277 )
return 0 ;
F_82 ( & V_71 -> V_278 ) ;
F_103 ( V_79 ) ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
memset ( V_208 . V_209 , 0xFF , V_75 ) ;
if ( V_360 -> V_362 ) {
V_208 . V_177 = V_262 ;
V_361 = V_360 -> V_363 [ 0 ] . V_361 ;
V_294 = V_360 -> V_363 [ 0 ] . V_269 ;
} else {
V_208 . V_177 = V_211 ;
}
if ( V_294 ) {
memcpy ( V_208 . V_244 , V_361 , V_294 ) ;
V_208 . V_243 = V_294 ;
}
V_208 . V_180 = F_38 ( V_71 -> V_213 ) ;
V_208 . V_181 = F_38 ( V_71 -> V_214 ) ;
V_208 . V_179 = F_38 ( V_71 -> V_213 * 1000 ) ;
V_208 . V_212 = 0 ;
F_13 ( V_298 , L_146 , V_37 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_90 , & V_208 , sizeof( V_208 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_147 , V_21 ) ;
goto exit;
}
F_114 ( V_71 -> V_79 , & V_71 -> V_352 ,
V_358 ) ;
exit:
F_83 ( & V_71 -> V_278 ) ;
return 0 ;
}
static int F_117 ( struct V_330 * V_79 , T_2 V_364 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_298 , L_148 ,
V_37 , V_79 -> V_365 . V_366 . V_367 -> V_345 ) ;
F_39 ( V_298 , V_71 -> V_209 , V_75 , L_149 ) ;
F_82 ( & V_71 -> V_278 ) ;
V_71 -> V_210 = V_79 -> V_365 . V_366 . V_367 -> V_345 ;
if ( F_94 ( V_71 -> V_209 ) )
F_92 ( V_71 ) ;
else
F_63 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
return 0 ;
}
static void F_118 ( struct V_330 * V_79 ,
struct V_353 * V_354 ,
struct V_368 * V_365 ,
T_2 V_364 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_298 , L_145 , V_37 ) ;
if ( ! ( V_364 & V_369 ) )
return;
F_39 ( V_298 , V_365 -> V_209 , V_75 , L_149 ) ;
F_82 ( & V_71 -> V_278 ) ;
memcpy ( V_71 -> V_209 , V_365 -> V_209 , V_75 ) ;
if ( F_94 ( V_71 -> V_209 ) )
F_92 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
}
static void F_119 ( struct V_330 * V_79 ,
unsigned int V_370 ,
unsigned int * V_371 , T_4 V_372 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_328 ;
F_13 ( V_298 , L_150
L_151 ,
V_37 , V_370 , * V_371 ) ;
V_328 = V_370 & V_373 ;
* V_371 = V_373 ;
if ( V_71 -> V_277 )
return;
if ( V_328 && ! V_71 -> V_279 ) {
V_71 -> V_279 = 1 ;
} else if ( ! V_328 && V_71 -> V_279 ) {
V_71 -> V_279 = 0 ;
} else
return;
F_102 ( V_79 , & V_71 -> V_276 ) ;
}
static int F_120 ( struct V_330 * V_79 , enum V_374 V_85 ,
struct V_353 * V_354 , struct V_375 * V_376 ,
struct V_377 * V_378 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_73 ;
F_13 ( V_298 , L_152
L_153 ,
V_37 , V_85 , V_378 -> V_379 , V_378 -> V_380 , V_378 -> V_381 ) ;
if ( ( V_378 -> V_379 != V_382 ) &&
( V_378 -> V_379 != V_383 ) )
return - V_357 ;
V_378 -> V_384 = V_378 -> V_380 ;
F_82 ( & V_71 -> V_278 ) ;
switch ( V_85 ) {
case V_385 :
memcpy ( V_71 -> V_271 [ V_378 -> V_380 ] , V_378 -> V_378 , V_378 -> V_381 ) ;
V_71 -> V_249 [ V_378 -> V_380 ] = V_378 -> V_381 ;
V_71 -> V_248 = V_378 -> V_380 ;
break;
case V_386 :
default:
V_71 -> V_249 [ V_378 -> V_380 ] = 0 ;
break;
}
V_71 -> V_247 = 0 ;
for ( V_73 = 0 ; V_73 < V_152 ; V_73 ++ ) {
if ( V_71 -> V_249 [ V_73 ] != 0 )
V_71 -> V_247 = 1 ;
}
F_79 ( V_71 ) ;
F_83 ( & V_71 -> V_278 ) ;
return 0 ;
}
static struct V_70 * F_121 ( struct V_9 * V_10 )
{
struct V_330 * V_79 ;
struct V_70 * V_71 ;
V_79 = F_122 ( sizeof( struct V_70 ) , & V_387 ) ;
if ( ! V_79 ) {
F_123 (KERN_ERR DRIVER_NAME L_154
L_155 ) ;
return NULL ;
}
V_71 = V_79 -> V_71 ;
V_71 -> V_79 = V_79 ;
V_71 -> V_10 = V_10 ;
F_124 ( & V_71 -> V_278 ) ;
F_125 ( & V_71 -> V_276 , F_80 ) ;
F_125 ( & V_71 -> V_280 , F_84 ) ;
F_125 ( & V_71 -> V_324 , F_93 ) ;
F_126 ( & V_71 -> V_352 , F_113 ) ;
F_127 ( & V_71 -> V_219 , F_85 , 0 ) ;
V_71 -> V_122 = V_388 ;
V_71 -> V_259 = 0 ;
V_71 -> V_79 -> V_389 = 100000 ;
return V_71 ;
}
static int F_128 ( struct V_70 * V_71 ,
struct V_390 * V_391 )
{
struct V_392 * V_393 , * V_394 , * V_395 ;
int V_73 ;
int V_396 ;
struct V_397 * V_398 ;
F_13 ( V_399 , L_156 , V_37 ) ;
F_13 ( V_285 , L_157 , V_37 ,
V_391 -> V_400 [ 0 ] . V_401 . V_402 ) ;
V_394 = NULL ;
V_395 = NULL ;
V_398 = V_391 -> V_403 ;
for ( V_73 = 0 ; V_73 < V_398 -> V_401 . V_402 ; V_73 ++ ) {
V_393 = & V_398 -> V_393 [ V_73 ] . V_401 ;
F_13 ( V_285 , L_158 ,
V_37 , V_73 , V_393 -> V_404 ,
V_393 -> V_405 ) ;
if ( ! V_394 && F_129 ( V_393 ) )
V_394 = V_393 ;
if ( ! V_395 && F_130 ( V_393 ) )
V_395 = V_393 ;
}
if ( ! V_394 || ! V_395 ) {
F_14 ( & V_391 -> V_38 , L_159 ) ;
return - V_406 ;
}
V_71 -> V_226 = F_131 ( V_71 -> V_10 , V_394 -> V_404 ) ;
V_71 -> V_349 = F_132 ( V_71 -> V_10 , V_395 -> V_404 ) ;
V_71 -> V_223 = F_133 ( 0 , V_41 ) ;
V_71 -> V_340 = F_133 ( 0 , V_41 ) ;
if ( ! V_71 -> V_223 || ! V_71 -> V_340 ) {
F_14 ( & V_391 -> V_38 , L_160 ) ;
return - V_42 ;
}
V_396 = sizeof( struct V_333 ) + V_407 ;
V_71 -> V_335 = F_15 ( V_396 , V_41 ) ;
if ( ! V_71 -> V_335 )
return - V_42 ;
F_13 ( V_399 , L_161 , V_37 ) ;
return 0 ;
}
static int F_134 ( struct V_70 * V_71 ,
struct V_390 * V_391 )
{
struct V_80 * V_80 ;
T_5 V_294 ;
int V_21 ;
F_13 ( V_229 , L_162 ,
V_391 -> V_403 -> V_401 . V_402 ) ;
V_21 = F_128 ( V_71 , V_391 ) ;
if ( V_21 < 0 )
goto exit;
V_21 = F_29 ( V_71 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_391 -> V_38 , L_163 ) ;
goto exit;
}
V_71 -> V_408 = F_31 ( V_71 -> V_76 ) ;
V_71 -> V_210 = V_409 ;
V_71 -> V_245 = V_356 ;
V_71 -> V_130 = V_410 ;
V_71 -> V_128 = V_411 ;
V_71 -> V_251 = V_412 ;
V_71 -> V_252 = V_257 ;
V_71 -> V_125 = V_413 ;
V_71 -> V_154 = 100 ;
V_71 -> V_258 = V_260 ;
V_71 -> V_213 = V_414 ;
V_71 -> V_214 = V_415 ;
V_71 -> V_261 = V_262 ;
V_71 -> V_277 = 0 ;
V_80 = V_71 -> V_79 -> V_80 ;
V_71 -> V_79 -> V_80 -> V_416 = 1 ;
V_71 -> V_79 -> V_80 -> V_417 = 0 ;
V_71 -> V_79 -> V_80 -> V_418 = F_135 ( V_355 ) ;
V_71 -> V_79 -> V_80 -> V_419 [ V_420 ] = & V_421 ;
V_71 -> V_79 -> V_328 = V_422 |
V_423 ;
V_71 -> V_79 -> V_424 = 100 ;
F_136 ( V_71 -> V_79 , & V_391 -> V_38 ) ;
F_137 ( V_71 -> V_79 , V_71 -> V_74 ) ;
V_294 = sizeof( V_80 -> V_309 ) ;
snprintf ( V_80 -> V_309 , V_294 , L_164 ,
V_71 -> V_309 . V_310 , V_71 -> V_309 . V_311 ,
V_71 -> V_309 . V_312 , V_71 -> V_309 . V_313 ) ;
V_80 -> V_425 = V_71 -> V_1 ;
V_21 = F_138 ( V_71 -> V_79 ) ;
if ( V_21 ) {
F_123 ( V_426 L_165 ,
V_21 ) ;
goto exit;
}
V_71 -> V_427 = 1 ;
F_47 ( V_71 -> V_79 -> V_80 , L_166 ,
F_139 ( & V_391 -> V_38 ) , V_71 -> V_74 ,
V_71 -> V_309 . V_310 , V_71 -> V_309 . V_311 ,
V_71 -> V_309 . V_312 , V_71 -> V_309 . V_313 ) ;
F_47 ( V_71 -> V_79 -> V_80 , L_167 ,
V_71 -> V_76 , V_71 -> V_408 -> V_428 ) ;
exit:
return V_21 ;
}
static void F_140 ( struct V_70 * V_71 )
{
F_13 ( V_399 , L_156 , V_37 ) ;
V_71 -> V_277 = 1 ;
F_141 ( & V_71 -> V_219 ) ;
if ( V_71 -> V_427 )
F_142 ( V_71 -> V_79 ) ;
if ( V_71 -> V_340 ) {
F_110 ( V_71 -> V_340 ) ;
F_143 ( V_71 -> V_340 ) ;
}
if ( V_71 -> V_223 ) {
F_110 ( V_71 -> V_223 ) ;
F_143 ( V_71 -> V_223 ) ;
}
F_13 ( V_399 , L_168 , V_37 ) ;
F_18 ( V_71 -> V_335 ) ;
F_144 ( & V_58 ) ;
F_145 ( V_71 -> V_222 ) ;
F_146 ( V_71 -> V_10 ) ;
F_13 ( V_399 , L_169 ,
V_37 ) ;
F_147 ( V_71 -> V_79 ) ;
F_13 ( V_399 , L_161 , V_37 ) ;
}
static int F_148 ( struct V_390 * V_391 ,
const struct V_429 * V_430 )
{
int V_21 ;
struct V_70 * V_71 ;
struct V_230 * V_231 ;
struct V_9 * V_10 ;
int V_64 ;
int V_431 = 0 ;
struct V_432 V_433 ;
int V_1 = ( int ) V_430 -> V_434 ;
V_10 = F_149 ( F_150 ( V_391 ) ) ;
V_231 = F_89 ( V_10 , V_1 ) ;
if ( ! V_231 ) {
V_21 = - V_234 ;
goto error;
}
V_64 = F_25 ( V_10 ) ;
F_13 ( V_229 , L_84 , V_64 ) ;
if ( V_64 == V_435 ) {
F_14 ( & V_391 -> V_38 ,
L_170 ) ;
V_21 = - V_436 ;
goto error;
}
if ( V_64 != V_437
&& V_64 != V_235 ) {
F_91 ( V_319 , & V_391 -> V_38 ,
L_171 ) ;
V_21 = F_77 ( V_10 , V_231 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_391 -> V_38 ,
L_172 ,
V_21 ) ;
goto error;
}
F_146 ( V_10 ) ;
return V_21 ;
}
if ( ( V_231 -> V_309 . V_310 > 0 || V_231 -> V_309 . V_311 >= 100 )
|| ( V_64 == V_437 ) ) {
V_21 = F_33 ( V_10 , V_438 , & V_433 , sizeof( V_433 ) ) ;
if ( V_21 < 0 || ( V_433 . V_310 | V_433 . V_311 ) == 0 )
V_431 = 1 ;
} else
V_431 = 1 ;
if ( V_431 ) {
F_91 ( V_319 , & V_391 -> V_38 ,
L_173 ) ;
V_21 = F_76 ( V_10 , V_231 ) ;
if ( V_21 )
goto error;
V_21 = F_33 ( V_10 , V_438 , & V_433 , sizeof( V_433 ) ) ;
if ( V_21 < 0 ) {
F_14 ( & V_391 -> V_38 ,
L_174 , V_21 ) ;
goto error;
}
}
V_71 = F_121 ( V_10 ) ;
if ( ! V_71 ) {
V_21 = - V_42 ;
goto error;
}
F_151 ( V_391 , V_71 ) ;
memcpy ( & V_71 -> V_309 , & V_433 , sizeof( struct V_432 ) ) ;
V_71 -> V_1 = V_1 ;
V_21 = F_134 ( V_71 , V_391 ) ;
if ( V_21 < 0 )
F_140 ( V_71 ) ;
return V_21 ;
error:
F_146 ( V_10 ) ;
return V_21 ;
}
static void F_152 ( struct V_390 * V_391 )
{
struct V_70 * V_71 ;
V_71 = F_153 ( V_391 ) ;
F_151 ( V_391 , NULL ) ;
if ( ! V_71 )
return;
F_47 ( V_71 -> V_79 -> V_80 , L_175 ) ;
F_140 ( V_71 ) ;
F_154 ( & V_391 -> V_38 , L_176 ) ;
}
static int T_6 F_155 ( void )
{
int V_439 ;
F_123 (KERN_INFO DRIVER_DESC L_177 DRIVER_VERSION L_178 ) ;
F_124 ( & V_304 ) ;
V_439 = F_156 ( & V_440 ) ;
if ( V_439 < 0 )
F_123 (KERN_ERR DRIVER_NAME
L_179 , result) ;
F_157 ( L_180 , & V_56 ) ;
return V_439 ;
}
static void T_7 F_158 ( void )
{
int V_73 ;
F_123 (KERN_INFO DRIVER_DESC L_177 DRIVER_VERSION L_181 ) ;
F_159 ( & V_440 ) ;
for ( V_73 = 0 ; V_73 < F_32 ( V_303 ) ; V_73 ++ )
F_160 ( V_303 [ V_73 ] . V_308 ) ;
F_161 ( V_56 ) ;
}
