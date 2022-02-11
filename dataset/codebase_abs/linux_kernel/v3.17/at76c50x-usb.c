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
int V_21 = 0 ;
int V_30 = 1 ;
int V_31 = 0 ;
T_2 V_32 = 0 ;
int V_33 = 0 ;
int V_11 = 0 ;
struct V_19 * V_34 = NULL ;
T_1 * V_35 = NULL ;
T_1 * V_12 = NULL ;
F_13 ( V_36 , L_1 , V_37 , V_28 , V_13 ,
V_29 ) ;
if ( ! V_13 ) {
F_14 ( & V_10 -> V_38 , L_2 ) ;
return - V_39 ;
}
V_34 = F_15 ( sizeof( struct V_19 ) , V_40 ) ;
if ( ! V_34 ) {
V_21 = - V_41 ;
goto exit;
}
V_12 = F_15 ( V_42 , V_40 ) ;
if ( ! V_12 ) {
V_21 = - V_41 ;
goto exit;
}
V_35 = F_15 ( sizeof( T_1 ) , V_40 ) ;
if ( ! V_35 ) {
V_21 = - V_41 ;
goto exit;
}
* V_35 = 0 ;
do {
if ( V_30 ) {
V_21 = F_9 ( V_10 , V_35 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 ,
L_3 , V_21 ) ;
goto exit;
}
V_30 = 0 ;
}
switch ( * V_35 ) {
case V_43 :
F_13 ( V_36 , L_4 ) ;
V_21 = F_7 ( V_10 , V_34 ) ;
if ( V_21 >= 0 ) {
* V_35 = V_34 -> V_24 ;
V_32 = F_10 ( V_34 ) ;
V_30 = 0 ;
} else
F_14 ( & V_10 -> V_38 ,
L_5 ,
V_21 ) ;
break;
case V_44 :
F_13 ( V_36 , L_6 ) ;
V_30 = 1 ;
F_13 ( V_36 , L_7 ) ;
F_16 ( V_32 ) ;
break;
case V_45 :
F_13 ( V_36 , L_8 ) ;
case V_46 :
F_13 ( V_36 , L_9 ) ;
V_33 = F_17 ( int , V_13 , V_42 ) ;
memcpy ( V_12 , V_28 , V_33 ) ;
F_13 ( V_36 , L_10
L_11 , V_13 , V_33 ,
V_11 ) ;
V_21 =
F_4 ( V_10 , V_11 , V_12 , V_33 ) ;
V_28 += V_33 ;
V_13 -= V_33 ;
V_11 ++ ;
if ( V_21 != V_33 )
F_14 ( & V_10 -> V_38 ,
L_12 ,
V_21 ) ;
V_30 = 1 ;
break;
case V_47 :
F_13 ( V_36 , L_13 ) ;
V_21 = F_7 ( V_10 , V_34 ) ;
if ( V_21 < 0 )
break;
* V_35 = V_34 -> V_24 ;
V_32 = F_10 ( V_34 ) ;
V_30 = 0 ;
if ( V_29 > 0 )
V_32 = V_29 ;
F_13 ( V_36 , L_14 ) ;
F_16 ( V_32 ) ;
break;
case V_48 :
F_13 ( V_36 , L_15 ) ;
V_31 = 1 ;
break;
case V_49 :
F_13 ( V_36 , L_16 ) ;
V_31 = 1 ;
break;
case V_50 :
F_13 ( V_36 , L_17 ) ;
break;
case V_51 :
F_13 ( V_36 , L_18 ) ;
V_21 = - V_52 ;
break;
default:
F_13 ( V_36 , L_19 , * V_35 ) ;
V_21 = - V_39 ;
break;
}
} while ( ! V_31 && ( V_21 >= 0 ) );
exit:
F_18 ( V_35 ) ;
F_18 ( V_12 ) ;
F_18 ( V_34 ) ;
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
return - V_41 ;
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
union V_68 * V_72 = F_15 ( sizeof( * V_72 ) , V_40 ) ;
if ( ! V_72 )
return - V_41 ;
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
return - V_41 ;
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
V_69 , V_40 ) ;
if ( ! V_97 )
return - V_41 ;
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
V_40 ) ;
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
struct V_141 * V_134 = F_15 ( sizeof( struct V_141 ) , V_40 ) ;
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
V_40 ) ;
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
struct V_127 * V_134 = F_15 ( sizeof( struct V_127 ) , V_40 ) ;
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
struct V_186 * V_134 = F_15 ( sizeof( struct V_186 ) , V_40 ) ;
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
struct V_124 * V_134 = F_15 ( sizeof( * V_134 ) , V_40 ) ;
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
struct V_203 * V_134 = F_15 ( sizeof( struct V_203 ) , V_40 ) ;
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
V_21 = - V_41 ;
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
int V_33 ;
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
V_12 = F_15 ( V_42 , V_40 ) ;
if ( ! V_12 )
return - V_41 ;
F_13 ( V_229 , L_86 ) ;
do {
V_33 = F_17 ( int , V_13 , V_42 ) ;
memcpy ( V_12 , V_28 , V_33 ) ;
F_13 ( V_229 ,
L_87 ,
V_13 , V_33 , V_11 ) ;
V_21 = F_26 ( V_10 , V_11 , V_12 , V_33 ) ;
if ( V_21 != V_33 ) {
F_14 ( & V_10 -> V_38 ,
L_88 ,
V_11 , V_21 ) ;
V_21 = - V_66 ;
goto exit;
}
V_28 += V_33 ;
V_13 -= V_33 ;
V_11 ++ ;
} while ( V_33 > 0 );
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
V_71 -> V_273 = false ;
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
if ( V_274 & V_136 ) {
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
static void F_80 ( struct V_275 * V_276 )
{
struct V_70 * V_71 = F_81 ( V_276 , struct V_70 ,
V_277 ) ;
int V_21 = 0 ;
if ( V_71 -> V_278 )
return;
F_82 ( & V_71 -> V_279 ) ;
V_71 -> V_116 . type = V_123 ;
V_71 -> V_116 . V_13 = 1 ;
V_71 -> V_116 . V_118 = F_46 ( struct V_124 , V_202 ) ;
V_71 -> V_116 . V_53 . V_121 = V_71 -> V_280 ? 1 : 0 ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_116 , V_21 ) ;
F_83 ( & V_71 -> V_279 ) ;
}
static void F_84 ( struct V_275 * V_276 )
{
struct V_70 * V_71 = F_81 ( V_276 , struct V_70 ,
V_281 ) ;
F_82 ( & V_71 -> V_279 ) ;
F_67 ( V_71 ) ;
F_83 ( & V_71 -> V_279 ) ;
}
static inline int F_85 ( struct V_70 * V_71 )
{
T_4 V_282 ;
const T_1 * V_283 ;
int V_210 = V_71 -> V_210 ;
int V_284 = V_71 -> V_222 -> V_284 ;
struct V_285 * V_286 = ( void * ) V_71 -> V_222 -> V_53 ;
if ( ! V_71 -> V_273 )
goto exit;
if ( V_284 < 24 )
goto exit;
if ( F_86 ( V_286 -> V_287 ) ) {
V_282 = F_46 ( struct V_288 , V_289 . V_290 . V_291 ) ;
V_283 = ( (struct V_288 * ) V_286 ) -> V_289 . V_290 . V_291 ;
} else if ( F_87 ( V_286 -> V_287 ) ) {
V_282 = F_46 ( struct V_288 , V_289 . V_292 . V_291 ) ;
V_283 = ( (struct V_288 * ) V_286 ) -> V_289 . V_292 . V_291 ;
} else {
goto exit;
}
V_284 -= V_282 ;
V_283 = F_88 ( V_293 , V_283 , V_284 ) ;
if ( V_283 && V_283 [ 1 ] > 0 )
V_210 = V_283 [ 2 ] ;
exit:
return F_89 ( V_210 , V_294 ) ;
}
static void F_90 ( unsigned long V_295 )
{
struct V_217 * V_217 = (struct V_217 * ) V_295 ;
struct V_70 * V_71 = V_217 -> V_218 ;
struct V_225 * V_28 ;
struct V_296 V_297 = { 0 } ;
if ( V_71 -> V_278 ) {
F_13 ( V_229 , L_117 ) ;
F_13 ( V_229 , L_118 , V_217 -> V_20 ) ;
return;
}
if ( ! V_71 -> V_222 || ! V_71 -> V_222 -> V_53 )
return;
V_28 = (struct V_225 * ) V_71 -> V_222 -> V_53 ;
if ( V_217 -> V_20 != 0 ) {
if ( V_217 -> V_20 != - V_234 && V_217 -> V_20 != - V_298 )
F_13 ( V_299 ,
L_119 ,
V_37 , F_43 ( V_71 -> V_79 -> V_80 ) ,
V_217 -> V_20 ) ;
return;
}
F_13 ( V_300 ,
L_120 ,
F_43 ( V_71 -> V_79 -> V_80 ) , V_28 -> V_301 , V_28 -> V_302 ,
V_28 -> V_303 , V_28 -> V_304 ) ;
F_91 ( V_71 -> V_222 , V_305 ) ;
F_71 ( V_71 -> V_222 , F_58 ( V_28 -> V_306 ) ) ;
F_39 ( V_307 , V_71 -> V_222 -> V_53 ,
V_71 -> V_222 -> V_284 , L_121 , V_71 -> V_222 -> V_284 ) ;
V_297 . signal = V_28 -> V_302 ;
V_297 . V_308 |= V_309 ;
V_297 . V_308 |= V_310 ;
V_297 . V_311 = V_294 ;
V_297 . V_312 = F_85 ( V_71 ) ;
F_13 ( V_313 , L_122 ,
V_71 -> V_222 -> V_284 , V_71 -> V_222 -> V_314 ) ;
memcpy ( F_92 ( V_71 -> V_222 ) , & V_297 , sizeof( V_297 ) ) ;
F_93 ( V_71 -> V_79 , V_71 -> V_222 ) ;
V_71 -> V_222 = NULL ;
F_67 ( V_71 ) ;
}
static struct V_230 * F_94 ( struct V_9 * V_10 ,
enum V_1 V_1 )
{
int V_21 ;
char * V_315 ;
struct V_316 * V_317 ;
struct V_230 * V_231 = & V_318 [ V_1 ] ;
F_82 ( & V_319 ) ;
if ( V_231 -> V_320 ) {
F_13 ( V_321 , L_123 ) ;
goto exit;
}
F_13 ( V_321 , L_124 , V_231 -> V_322 ) ;
V_21 = F_95 ( & V_231 -> V_323 , V_231 -> V_322 , & V_10 -> V_38 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_10 -> V_38 , L_125 ,
V_231 -> V_322 ) ;
F_14 ( & V_10 -> V_38 ,
L_126 ) ;
goto exit;
}
F_13 ( V_321 , L_127 ) ;
V_317 = (struct V_316 * ) ( V_231 -> V_323 -> V_53 ) ;
if ( V_231 -> V_323 -> V_13 <= sizeof( * V_317 ) ) {
F_14 ( & V_10 -> V_38 ,
L_128 , V_231 -> V_323 -> V_13 ) ;
goto exit;
}
V_231 -> V_1 = F_56 ( V_317 -> V_1 ) ;
if ( V_231 -> V_1 != V_1 ) {
F_14 ( & V_10 -> V_38 ,
L_129 ,
V_1 , V_231 -> V_1 ) ;
goto exit;
}
V_231 -> V_324 . V_325 = V_317 -> V_325 ;
V_231 -> V_324 . V_326 = V_317 -> V_326 ;
V_231 -> V_324 . V_327 = V_317 -> V_327 ;
V_231 -> V_324 . V_328 = V_317 -> V_328 ;
V_315 = ( char * ) V_317 + F_56 ( V_317 -> V_329 ) ;
V_231 -> V_237 = ( T_1 * ) V_317 + F_56 ( V_317 -> V_330 ) ;
V_231 -> V_238 = F_56 ( V_317 -> V_331 ) ;
V_231 -> V_232 = ( T_1 * ) V_317 + F_56 ( V_317 -> V_332 ) ;
V_231 -> V_233 = F_56 ( V_317 -> V_333 ) ;
V_231 -> V_320 = 1 ;
F_96 ( V_334 , & V_10 -> V_38 ,
L_130 ,
V_231 -> V_322 , V_317 -> V_325 , V_317 -> V_326 , V_317 -> V_327 , V_317 -> V_328 ) ;
F_13 ( V_229 , L_131 , V_1 ,
F_56 ( V_317 -> V_330 ) , F_56 ( V_317 -> V_331 ) ,
F_56 ( V_317 -> V_332 ) , F_56 ( V_317 -> V_333 ) ) ;
F_13 ( V_229 , L_132 , V_315 ) ;
exit:
F_83 ( & V_319 ) ;
if ( V_231 -> V_320 )
return V_231 ;
else
return NULL ;
}
static int F_97 ( struct V_70 * V_71 )
{
struct V_335 V_336 ;
int V_21 ;
memset ( & V_336 , 0 , sizeof( struct V_335 ) ) ;
memcpy ( V_336 . V_244 , V_71 -> V_244 , V_71 -> V_243 ) ;
V_336 . V_243 = V_71 -> V_243 ;
memcpy ( V_336 . V_209 , V_71 -> V_209 , V_75 ) ;
V_336 . V_337 = V_338 ;
V_336 . V_210 = V_71 -> V_210 ;
V_336 . V_109 = F_38 ( 2000 ) ;
F_13 ( V_313 , L_133 , V_37 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_91 , & V_336 ,
sizeof( struct V_335 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_115 ,
V_21 ) ;
return 0 ;
}
V_21 = F_42 ( V_71 , V_91 ) ;
F_13 ( V_313 , L_134 , V_37 , V_21 ) ;
if ( V_21 != V_101 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_135 ,
V_21 ) ;
return 0 ;
}
F_49 ( V_71 ) ;
return 0 ;
}
static void F_98 ( struct V_275 * V_276 )
{
struct V_70 * V_71 = F_81 ( V_276 , struct V_70 ,
V_339 ) ;
if ( V_71 -> V_278 )
return;
F_82 ( & V_71 -> V_279 ) ;
if ( F_99 ( V_71 -> V_209 ) )
F_97 ( V_71 ) ;
F_83 ( & V_71 -> V_279 ) ;
}
static void F_100 ( struct V_217 * V_217 )
{
struct V_70 * V_71 = V_217 -> V_218 ;
struct V_340 * V_341 = F_101 ( V_71 -> V_342 ) ;
F_13 ( V_313 , L_136 , V_37 ) ;
switch ( V_217 -> V_20 ) {
case 0 :
V_341 -> V_343 |= V_344 ;
break;
case - V_234 :
case - V_298 :
break;
default:
F_13 ( V_299 , L_137 ,
V_37 , V_217 -> V_20 ) ;
break;
}
memset ( & V_341 -> V_20 , 0 , sizeof( V_341 -> V_20 ) ) ;
F_102 ( V_71 -> V_79 , V_71 -> V_342 ) ;
V_71 -> V_342 = NULL ;
F_103 ( V_71 -> V_79 ) ;
}
static void F_104 ( struct V_345 * V_79 ,
struct V_346 * V_347 ,
struct V_220 * V_221 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
struct V_348 * V_349 = V_71 -> V_350 ;
struct V_340 * V_341 = F_101 ( V_221 ) ;
struct V_288 * V_351 = (struct V_288 * ) V_221 -> V_53 ;
int V_352 , V_353 , V_21 ;
F_13 ( V_313 , L_136 , V_37 ) ;
if ( V_71 -> V_354 -> V_20 == - V_355 ) {
F_30 ( V_71 -> V_79 -> V_80 ,
L_138 , V_37 ) ;
F_105 ( V_221 ) ;
return;
}
if ( V_351 -> V_287 & F_38 ( V_356 ) ) {
if ( ! F_106 ( V_71 -> V_209 , V_351 -> V_209 ) ) {
memcpy ( V_71 -> V_209 , V_351 -> V_209 , V_75 ) ;
F_107 ( V_79 , & V_71 -> V_339 ) ;
F_105 ( V_221 ) ;
return;
}
}
F_108 ( V_79 ) ;
F_22 () ;
F_109 ( V_71 -> V_342 != NULL ) ;
V_71 -> V_342 = V_221 ;
V_352 = F_64 ( V_221 -> V_284 ) ;
V_353 = V_216 + V_221 -> V_284 + V_352 ;
memset ( V_349 , 0 , sizeof( * V_349 ) ) ;
V_349 -> V_352 = V_352 ;
V_349 -> V_306 = F_38 ( V_221 -> V_284 ) ;
V_349 -> V_357 = F_110 ( V_79 , V_341 ) -> V_358 ;
memset ( V_349 -> V_98 , 0 , sizeof( V_349 -> V_98 ) ) ;
memcpy ( V_349 -> V_359 , V_221 -> V_53 , V_221 -> V_284 ) ;
F_13 ( V_360 , L_139 ,
F_43 ( V_71 -> V_79 -> V_80 ) , F_58 ( V_349 -> V_306 ) ,
V_349 -> V_352 , V_349 -> V_357 ) ;
F_39 ( V_361 , V_349 , V_353 ,
L_140 , V_37 , V_353 ) ;
F_73 ( V_71 -> V_354 , V_71 -> V_10 , V_71 -> V_362 , V_349 ,
V_353 , F_100 , V_71 ) ;
V_21 = F_75 ( V_71 -> V_354 , V_227 ) ;
if ( V_21 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_141 , V_21 ) ;
if ( V_21 == - V_39 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_142 ,
V_71 -> V_354 ,
V_71 -> V_354 -> V_363 , V_71 -> V_354 -> V_364 ) ;
}
}
static int F_111 ( struct V_345 * V_79 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_21 ;
F_13 ( V_313 , L_136 , V_37 ) ;
F_82 ( & V_71 -> V_279 ) ;
V_21 = F_67 ( V_71 ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_143 ,
V_21 ) ;
goto error;
}
F_79 ( V_71 ) ;
F_63 ( V_71 ) ;
error:
F_83 ( & V_71 -> V_279 ) ;
return 0 ;
}
static void F_112 ( struct V_345 * V_79 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_313 , L_136 , V_37 ) ;
F_113 ( & V_71 -> V_365 ) ;
F_114 ( & V_71 -> V_339 ) ;
F_114 ( & V_71 -> V_277 ) ;
F_82 ( & V_71 -> V_279 ) ;
if ( ! V_71 -> V_278 ) {
F_48 ( V_71 , 0 ) ;
F_115 ( V_71 -> V_223 ) ;
}
F_83 ( & V_71 -> V_279 ) ;
}
static int F_116 ( struct V_345 * V_79 ,
struct V_366 * V_367 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_21 = 0 ;
F_13 ( V_313 , L_136 , V_37 ) ;
F_82 ( & V_71 -> V_279 ) ;
switch ( V_367 -> type ) {
case V_368 :
V_71 -> V_245 = V_369 ;
break;
default:
V_21 = - V_370 ;
goto exit;
}
exit:
F_83 ( & V_71 -> V_279 ) ;
return V_21 ;
}
static void F_117 ( struct V_345 * V_79 ,
struct V_366 * V_367 )
{
F_13 ( V_313 , L_136 , V_37 ) ;
}
static void F_118 ( struct V_275 * V_276 )
{
struct V_70 * V_71 = F_81 ( V_276 , struct V_70 ,
V_365 . V_276 ) ;
int V_21 ;
if ( V_71 -> V_278 )
return;
F_82 ( & V_71 -> V_279 ) ;
V_21 = F_34 ( V_71 -> V_10 , V_90 ) ;
F_13 ( V_313 , L_144 , V_37 , V_21 ) ;
if ( V_21 != V_101 ) {
F_119 ( V_71 -> V_79 , & V_71 -> V_365 ,
V_371 ) ;
F_83 ( & V_71 -> V_279 ) ;
return;
}
if ( F_99 ( V_71 -> V_209 ) )
F_97 ( V_71 ) ;
V_71 -> V_273 = false ;
F_83 ( & V_71 -> V_279 ) ;
F_120 ( V_71 -> V_79 , false ) ;
F_103 ( V_71 -> V_79 ) ;
}
static int F_121 ( struct V_345 * V_79 ,
struct V_366 * V_367 ,
struct V_372 * V_373 )
{
struct V_374 * V_375 = & V_373 -> V_375 ;
struct V_70 * V_71 = V_79 -> V_71 ;
struct V_207 V_208 ;
T_1 * V_376 = NULL ;
int V_21 , V_284 = 0 ;
F_13 ( V_313 , L_145 , V_37 ) ;
if ( V_71 -> V_278 )
return 0 ;
F_82 ( & V_71 -> V_279 ) ;
F_108 ( V_79 ) ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
memset ( V_208 . V_209 , 0xFF , V_75 ) ;
if ( V_375 -> V_377 ) {
V_208 . V_177 = V_262 ;
V_376 = V_375 -> V_378 [ 0 ] . V_376 ;
V_284 = V_375 -> V_378 [ 0 ] . V_269 ;
} else {
V_208 . V_177 = V_211 ;
}
if ( V_284 ) {
memcpy ( V_208 . V_244 , V_376 , V_284 ) ;
V_208 . V_243 = V_284 ;
}
V_208 . V_180 = F_38 ( V_71 -> V_213 ) ;
V_208 . V_181 = F_38 ( V_71 -> V_214 ) ;
V_208 . V_179 = F_38 ( V_71 -> V_213 * 1000 ) ;
V_208 . V_212 = 0 ;
F_13 ( V_313 , L_146 , V_37 ) ;
V_21 = F_37 ( V_71 -> V_10 , V_90 , & V_208 , sizeof( V_208 ) ) ;
if ( V_21 < 0 ) {
F_30 ( V_71 -> V_79 -> V_80 , L_147 , V_21 ) ;
goto exit;
}
V_71 -> V_273 = true ;
F_119 ( V_71 -> V_79 , & V_71 -> V_365 ,
V_371 ) ;
exit:
F_83 ( & V_71 -> V_279 ) ;
return 0 ;
}
static int F_122 ( struct V_345 * V_79 , T_2 V_379 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_313 , L_148 ,
V_37 , V_79 -> V_380 . V_381 . V_382 -> V_358 ) ;
F_39 ( V_313 , V_71 -> V_209 , V_75 , L_149 ) ;
F_82 ( & V_71 -> V_279 ) ;
V_71 -> V_210 = V_79 -> V_380 . V_381 . V_382 -> V_358 ;
if ( F_99 ( V_71 -> V_209 ) )
F_97 ( V_71 ) ;
else
F_63 ( V_71 ) ;
F_83 ( & V_71 -> V_279 ) ;
return 0 ;
}
static void F_123 ( struct V_345 * V_79 ,
struct V_366 * V_367 ,
struct V_383 * V_380 ,
T_2 V_379 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
F_13 ( V_313 , L_145 , V_37 ) ;
if ( ! ( V_379 & V_384 ) )
return;
F_39 ( V_313 , V_380 -> V_209 , V_75 , L_149 ) ;
F_82 ( & V_71 -> V_279 ) ;
memcpy ( V_71 -> V_209 , V_380 -> V_209 , V_75 ) ;
if ( F_99 ( V_71 -> V_209 ) )
F_97 ( V_71 ) ;
F_83 ( & V_71 -> V_279 ) ;
}
static void F_124 ( struct V_345 * V_79 ,
unsigned int V_385 ,
unsigned int * V_386 , T_5 V_387 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_343 ;
F_13 ( V_313 , L_150
L_151 ,
V_37 , V_385 , * V_386 ) ;
V_343 = V_385 & V_388 ;
* V_386 = V_388 ;
if ( V_71 -> V_278 )
return;
if ( V_343 && ! V_71 -> V_280 ) {
V_71 -> V_280 = 1 ;
} else if ( ! V_343 && V_71 -> V_280 ) {
V_71 -> V_280 = 0 ;
} else
return;
F_107 ( V_79 , & V_71 -> V_277 ) ;
}
static int F_125 ( struct V_70 * V_71 )
{
int V_21 = 0 ;
struct V_141 * V_389 = & V_71 -> V_116 . V_53 . V_390 ;
V_71 -> V_116 . type = V_142 ;
V_71 -> V_116 . V_13 = sizeof( struct V_141 ) ;
V_71 -> V_116 . V_118 = 0 ;
memset ( V_389 , 0 , sizeof( * V_389 ) ) ;
if ( V_71 -> V_247 ) {
if ( V_71 -> V_249 [ V_71 -> V_248 ] > V_150 )
V_389 -> V_149 = 2 ;
else
V_389 -> V_149 = 1 ;
V_389 -> V_146 = 1 ;
} else {
V_389 -> V_146 = 0 ;
V_389 -> V_149 = 0 ;
}
V_389 -> V_143 = V_71 -> V_247 ;
V_389 -> V_144 = V_71 -> V_248 ;
memcpy ( V_389 -> V_153 , V_71 -> V_271 ,
sizeof( V_71 -> V_271 ) ) ;
V_21 = F_45 ( V_71 , & V_71 -> V_116 ) ;
if ( V_21 < 0 )
F_30 ( V_71 -> V_79 -> V_80 ,
L_152 , V_21 ) ;
return V_21 ;
}
static int F_126 ( struct V_345 * V_79 , enum V_391 V_85 ,
struct V_366 * V_367 , struct V_392 * V_393 ,
struct V_394 * V_395 )
{
struct V_70 * V_71 = V_79 -> V_71 ;
int V_73 ;
F_13 ( V_313 , L_153
L_154 ,
V_37 , V_85 , V_395 -> V_396 , V_395 -> V_397 , V_395 -> V_398 ) ;
if ( ( V_395 -> V_396 != V_399 ) &&
( V_395 -> V_396 != V_400 ) )
return - V_370 ;
V_395 -> V_401 = V_395 -> V_397 ;
F_82 ( & V_71 -> V_279 ) ;
switch ( V_85 ) {
case V_402 :
memcpy ( V_71 -> V_271 [ V_395 -> V_397 ] , V_395 -> V_395 , V_395 -> V_398 ) ;
V_71 -> V_249 [ V_395 -> V_397 ] = V_395 -> V_398 ;
V_71 -> V_248 = V_395 -> V_397 ;
break;
case V_403 :
default:
V_71 -> V_249 [ V_395 -> V_397 ] = 0 ;
break;
}
V_71 -> V_247 = 0 ;
for ( V_73 = 0 ; V_73 < V_152 ; V_73 ++ ) {
if ( V_71 -> V_249 [ V_73 ] != 0 )
V_71 -> V_247 = 1 ;
}
F_125 ( V_71 ) ;
F_83 ( & V_71 -> V_279 ) ;
return 0 ;
}
static struct V_70 * F_127 ( struct V_9 * V_10 )
{
struct V_345 * V_79 ;
struct V_70 * V_71 ;
V_79 = F_128 ( sizeof( struct V_70 ) , & V_404 ) ;
if ( ! V_79 ) {
F_129 (KERN_ERR DRIVER_NAME L_155
L_156 ) ;
return NULL ;
}
V_71 = V_79 -> V_71 ;
V_71 -> V_79 = V_79 ;
V_71 -> V_10 = V_10 ;
F_130 ( & V_71 -> V_279 ) ;
F_131 ( & V_71 -> V_277 , F_80 ) ;
F_131 ( & V_71 -> V_281 , F_84 ) ;
F_131 ( & V_71 -> V_339 , F_98 ) ;
F_132 ( & V_71 -> V_365 , F_118 ) ;
F_133 ( & V_71 -> V_219 , F_90 , 0 ) ;
V_71 -> V_122 = V_405 ;
V_71 -> V_259 = 0 ;
return V_71 ;
}
static int F_134 ( struct V_70 * V_71 ,
struct V_406 * V_407 )
{
struct V_408 * V_409 , * V_410 , * V_411 ;
int V_73 ;
int V_412 ;
struct V_413 * V_414 ;
F_13 ( V_415 , L_157 , V_37 ) ;
F_13 ( V_299 , L_158 , V_37 ,
V_407 -> V_416 [ 0 ] . V_417 . V_418 ) ;
V_410 = NULL ;
V_411 = NULL ;
V_414 = V_407 -> V_419 ;
for ( V_73 = 0 ; V_73 < V_414 -> V_417 . V_418 ; V_73 ++ ) {
V_409 = & V_414 -> V_409 [ V_73 ] . V_417 ;
F_13 ( V_299 , L_159 ,
V_37 , V_73 , V_409 -> V_420 ,
V_409 -> V_421 ) ;
if ( ! V_410 && F_135 ( V_409 ) )
V_410 = V_409 ;
if ( ! V_411 && F_136 ( V_409 ) )
V_411 = V_409 ;
}
if ( ! V_410 || ! V_411 ) {
F_14 ( & V_407 -> V_38 , L_160 ) ;
return - V_422 ;
}
V_71 -> V_226 = F_137 ( V_71 -> V_10 , V_410 -> V_420 ) ;
V_71 -> V_362 = F_138 ( V_71 -> V_10 , V_411 -> V_420 ) ;
V_71 -> V_223 = F_139 ( 0 , V_40 ) ;
V_71 -> V_354 = F_139 ( 0 , V_40 ) ;
if ( ! V_71 -> V_223 || ! V_71 -> V_354 ) {
F_14 ( & V_407 -> V_38 , L_161 ) ;
return - V_41 ;
}
V_412 = sizeof( struct V_348 ) + V_423 ;
V_71 -> V_350 = F_15 ( V_412 , V_40 ) ;
if ( ! V_71 -> V_350 )
return - V_41 ;
F_13 ( V_415 , L_162 , V_37 ) ;
return 0 ;
}
static int F_140 ( struct V_70 * V_71 ,
struct V_406 * V_407 )
{
struct V_80 * V_80 ;
T_4 V_284 ;
int V_21 ;
F_13 ( V_229 , L_163 ,
V_407 -> V_419 -> V_417 . V_418 ) ;
V_21 = F_134 ( V_71 , V_407 ) ;
if ( V_21 < 0 )
goto exit;
V_21 = F_29 ( V_71 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_407 -> V_38 , L_164 ) ;
goto exit;
}
V_71 -> V_424 = F_31 ( V_71 -> V_76 ) ;
V_71 -> V_210 = V_425 ;
V_71 -> V_245 = V_369 ;
V_71 -> V_130 = V_426 ;
V_71 -> V_128 = V_427 ;
V_71 -> V_251 = V_428 ;
V_71 -> V_252 = V_257 ;
V_71 -> V_125 = V_429 ;
V_71 -> V_154 = 100 ;
V_71 -> V_258 = V_260 ;
V_71 -> V_213 = V_430 ;
V_71 -> V_214 = V_431 ;
V_71 -> V_261 = V_262 ;
V_71 -> V_278 = 0 ;
V_80 = V_71 -> V_79 -> V_80 ;
V_71 -> V_79 -> V_80 -> V_432 = 1 ;
V_71 -> V_79 -> V_80 -> V_433 = 0 ;
V_71 -> V_79 -> V_80 -> V_434 = F_141 ( V_368 ) ;
V_71 -> V_79 -> V_80 -> V_435 [ V_294 ] = & V_436 ;
V_71 -> V_79 -> V_343 = V_437 |
V_438 ;
V_71 -> V_79 -> V_439 = 100 ;
F_142 ( V_71 -> V_79 , & V_407 -> V_38 ) ;
F_143 ( V_71 -> V_79 , V_71 -> V_74 ) ;
V_284 = sizeof( V_80 -> V_324 ) ;
snprintf ( V_80 -> V_324 , V_284 , L_165 ,
V_71 -> V_324 . V_325 , V_71 -> V_324 . V_326 ,
V_71 -> V_324 . V_327 , V_71 -> V_324 . V_328 ) ;
V_80 -> V_440 = V_71 -> V_1 ;
V_21 = F_144 ( V_71 -> V_79 ) ;
if ( V_21 ) {
F_129 ( V_441 L_166 ,
V_21 ) ;
goto exit;
}
V_71 -> V_442 = 1 ;
F_47 ( V_71 -> V_79 -> V_80 , L_167 ,
F_145 ( & V_407 -> V_38 ) , V_71 -> V_74 ,
V_71 -> V_324 . V_325 , V_71 -> V_324 . V_326 ,
V_71 -> V_324 . V_327 , V_71 -> V_324 . V_328 ) ;
F_47 ( V_71 -> V_79 -> V_80 , L_168 ,
V_71 -> V_76 , V_71 -> V_424 -> V_443 ) ;
exit:
return V_21 ;
}
static void F_146 ( struct V_70 * V_71 )
{
F_13 ( V_415 , L_157 , V_37 ) ;
V_71 -> V_278 = 1 ;
F_147 ( & V_71 -> V_219 ) ;
if ( V_71 -> V_442 )
F_148 ( V_71 -> V_79 ) ;
if ( V_71 -> V_354 ) {
F_115 ( V_71 -> V_354 ) ;
F_149 ( V_71 -> V_354 ) ;
}
if ( V_71 -> V_223 ) {
F_115 ( V_71 -> V_223 ) ;
F_149 ( V_71 -> V_223 ) ;
}
F_13 ( V_415 , L_169 , V_37 ) ;
F_18 ( V_71 -> V_350 ) ;
F_150 ( & V_58 ) ;
F_151 ( V_71 -> V_222 ) ;
F_13 ( V_415 , L_170 ,
V_37 ) ;
F_152 ( V_71 -> V_79 ) ;
F_13 ( V_415 , L_162 , V_37 ) ;
}
static int F_153 ( struct V_406 * V_407 ,
const struct V_444 * V_445 )
{
int V_21 ;
struct V_70 * V_71 ;
struct V_230 * V_231 ;
struct V_9 * V_10 ;
int V_64 ;
int V_446 = 0 ;
struct V_447 * V_448 = NULL ;
int V_1 = ( int ) V_445 -> V_449 ;
V_10 = F_154 ( F_155 ( V_407 ) ) ;
V_448 = F_15 ( sizeof( * V_448 ) , V_40 ) ;
if ( ! V_448 ) {
V_21 = - V_41 ;
goto exit;
}
V_231 = F_94 ( V_10 , V_1 ) ;
if ( ! V_231 ) {
V_21 = - V_234 ;
goto exit;
}
V_64 = F_25 ( V_10 ) ;
F_13 ( V_229 , L_84 , V_64 ) ;
if ( V_64 == V_450 ) {
F_14 ( & V_407 -> V_38 ,
L_171 ) ;
V_21 = - V_451 ;
goto exit;
}
if ( V_64 != V_452
&& V_64 != V_235 ) {
F_96 ( V_334 , & V_407 -> V_38 ,
L_172 ) ;
V_21 = F_77 ( V_10 , V_231 ) ;
if ( V_21 < 0 ) {
F_14 ( & V_407 -> V_38 ,
L_173 ,
V_21 ) ;
goto exit;
}
F_156 ( V_10 ) ;
goto exit;
}
if ( ( V_231 -> V_324 . V_325 > 0 || V_231 -> V_324 . V_326 >= 100 )
|| ( V_64 == V_452 ) ) {
V_21 = F_33 ( V_10 , V_453 , V_448 , sizeof( * V_448 ) ) ;
if ( V_21 < 0 || ( V_448 -> V_325 | V_448 -> V_326 ) == 0 )
V_446 = 1 ;
} else
V_446 = 1 ;
if ( V_446 ) {
F_96 ( V_334 , & V_407 -> V_38 ,
L_174 ) ;
V_21 = F_76 ( V_10 , V_231 ) ;
if ( V_21 < 0 )
goto exit;
V_21 = F_33 ( V_10 , V_453 , V_448 , sizeof( * V_448 ) ) ;
if ( V_21 < 0 ) {
F_14 ( & V_407 -> V_38 ,
L_175 , V_21 ) ;
goto exit;
}
}
V_71 = F_127 ( V_10 ) ;
if ( ! V_71 ) {
V_21 = - V_41 ;
goto exit;
}
F_157 ( V_407 , V_71 ) ;
memcpy ( & V_71 -> V_324 , V_448 , sizeof( struct V_447 ) ) ;
V_71 -> V_1 = V_1 ;
V_21 = F_140 ( V_71 , V_407 ) ;
if ( V_21 < 0 )
F_146 ( V_71 ) ;
exit:
F_18 ( V_448 ) ;
if ( V_21 < 0 )
F_156 ( V_10 ) ;
return V_21 ;
}
static void F_158 ( struct V_406 * V_407 )
{
struct V_70 * V_71 ;
V_71 = F_159 ( V_407 ) ;
F_157 ( V_407 , NULL ) ;
if ( ! V_71 )
return;
F_47 ( V_71 -> V_79 -> V_80 , L_176 ) ;
F_146 ( V_71 ) ;
F_156 ( V_71 -> V_10 ) ;
F_160 ( & V_407 -> V_38 , L_177 ) ;
}
static int T_6 F_161 ( void )
{
int V_454 ;
F_129 (KERN_INFO DRIVER_DESC L_178 DRIVER_VERSION L_179 ) ;
F_130 ( & V_319 ) ;
V_454 = F_162 ( & V_455 ) ;
if ( V_454 < 0 )
F_129 (KERN_ERR DRIVER_NAME
L_180 , result) ;
F_163 ( L_181 , & V_56 ) ;
return V_454 ;
}
static void T_7 F_164 ( void )
{
int V_73 ;
F_129 (KERN_INFO DRIVER_DESC L_178 DRIVER_VERSION L_182 ) ;
F_165 ( & V_455 ) ;
for ( V_73 = 0 ; V_73 < F_32 ( V_318 ) ; V_73 ++ )
F_166 ( V_318 [ V_73 ] . V_323 ) ;
F_167 ( V_56 ) ;
}
