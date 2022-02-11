static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_3 * V_4 )
{
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_6 ;
int V_7 ;
if ( V_8 ) {
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
V_4 -> V_9 . V_10 [ V_7 ] . V_11 =
F_7 ( V_12 [ V_7 ] ) ;
V_4 -> V_9 . V_13 = V_7 ;
} else {
struct V_14 * V_15 ;
V_15 = V_4 -> V_2 -> V_16 ;
V_4 -> V_9 = V_15 -> V_9 ;
}
if ( ! V_4 -> V_9 . V_13 ) {
struct V_17 * V_18 = V_4 -> V_18 ;
int V_19 ;
int V_20 = V_18 -> V_20 ;
if ( V_20 == 12 )
V_20 = 16 ;
V_19 = V_21 * V_22 * V_20 / 8 ;
V_4 -> V_9 . V_13 = 1 ;
V_4 -> V_9 . V_10 [ 0 ] . V_11 = F_7 ( V_19 ) ;
}
V_6 = V_4 -> V_23 -> V_24 ( V_4 , 0 , & V_4 -> V_9 ) ;
if ( V_6 < 0 ) {
F_8 ( V_4 -> V_2 , L_1 ,
V_6 ) ;
return V_6 ;
}
#ifdef F_9
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
F_10 ( V_4 -> V_2 , L_2 ,
V_7 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_25 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_26 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_11 ) ;
}
#endif
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
V_4 -> V_23 -> V_27 () ;
}
static int F_12 ( struct V_28 * V_29 )
{
int V_6 ;
unsigned long V_30 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_34 * V_35 = & V_29 -> V_35 ;
V_30 = V_35 -> V_36 * V_29 -> V_37 . V_38 +
V_35 -> V_39 * V_35 -> V_40 / 8 ;
if ( V_4 -> V_23 -> V_41 )
V_4 -> V_23 -> V_41 () ;
V_6 = V_4 -> V_23 -> V_42 ( V_32 -> V_43 , V_32 -> V_44 . V_45 ,
V_30 , V_35 -> V_46 ,
V_32 -> V_44 . V_47 , V_32 -> V_44 . V_48 ,
V_35 -> V_49 , V_35 -> V_50 , V_32 -> V_51 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_4 -> V_23 -> V_52 != NULL ) {
V_6 = V_4 -> V_23 -> V_52 ( V_35 -> V_53 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_4 -> V_23 -> V_54 != NULL )
V_6 = V_4 -> V_23 -> V_54 ( V_32 -> V_43 ,
V_35 -> V_49 , V_35 -> V_50 ,
V_32 -> V_44 . V_55 ,
V_32 -> V_44 . V_56 ) ;
return V_6 ;
}
static int F_13 ( struct V_28 * V_44 , int V_57 )
{
return 0 ;
}
static int F_14 ( struct V_28 * V_44 , int V_57 )
{
F_15 ( V_44 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_44 , T_1 V_58 , T_1 V_59 , T_1 V_60 ,
T_1 V_61 , T_1 V_62 , int V_63 )
{
struct V_31 * V_32 = V_44 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_34 * V_35 = & V_44 -> V_35 ;
int V_6 = 0 ;
switch ( V_32 -> V_51 ) {
case V_64 :
case V_65 :
case V_66 :
V_6 = - V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( V_4 -> V_23 -> V_72 )
V_6 = V_4 -> V_23 -> V_72 ( V_58 , V_59 , V_60 , V_61 ,
V_62 , V_63 ) ;
case V_73 :
case V_74 :
if ( V_6 != 0 )
break;
if ( V_58 < 0 ) {
V_6 = - V_67 ;
break;
}
if ( V_58 < 16 ) {
T_2 V_75 ;
V_75 = ( ( V_59 >> ( 16 - V_35 -> V_59 . V_76 ) ) <<
V_35 -> V_59 . V_30 ) |
( ( V_60 >> ( 16 - V_35 -> V_60 . V_76 ) ) <<
V_35 -> V_60 . V_30 ) |
( V_61 >> ( 16 - V_35 -> V_61 . V_76 ) ) ;
( ( V_77 * ) ( V_44 -> V_78 ) ) [ V_58 ] = V_75 ;
}
break;
default:
F_17 () ;
}
return V_6 ;
}
static int F_18 ( T_1 V_58 , T_1 V_59 , T_1 V_60 , T_1 V_61 ,
T_1 V_62 , struct V_28 * V_44 )
{
return F_16 ( V_44 , V_58 , V_59 , V_60 , V_61 , V_62 , 1 ) ;
}
static int F_19 ( struct V_79 * V_80 , struct V_28 * V_44 )
{
int V_81 , V_82 , V_6 ;
T_2 * V_59 , * V_60 , * V_61 , * V_62 ;
T_2 V_83 = 0xffff ;
V_59 = V_80 -> V_59 ;
V_60 = V_80 -> V_60 ;
V_61 = V_80 -> V_61 ;
V_62 = V_80 -> V_62 ;
V_82 = V_80 -> V_84 ;
for ( V_81 = 0 ; V_81 < V_80 -> V_85 ; V_81 ++ ) {
if ( V_62 )
V_83 = * V_62 ++ ;
V_6 = F_16 ( V_44 , V_82 ++ , * V_59 ++ , * V_60 ++ , * V_61 ++ , V_83 ,
V_81 == V_80 -> V_85 - 1 ) ;
if ( V_6 != 0 )
return V_6 ;
}
return 0 ;
}
static int F_20 ( int V_86 , struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_87 = 0 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
switch ( V_86 ) {
case V_88 :
if ( V_4 -> V_89 == V_90 ) {
if ( V_4 -> V_23 -> V_91 )
V_4 -> V_23 -> V_91 () ;
V_4 -> V_18 -> V_92 ( V_4 -> V_18 ) ;
V_4 -> V_89 = V_93 ;
if ( V_4 -> V_23 -> V_94 () ==
V_95 )
V_87 = 1 ;
}
break;
case V_96 :
if ( V_4 -> V_89 == V_93 ) {
V_4 -> V_18 -> V_97 ( V_4 -> V_18 ) ;
if ( V_4 -> V_23 -> V_98 )
V_4 -> V_23 -> V_98 () ;
V_4 -> V_89 = V_90 ;
}
break;
default:
V_6 = - V_67 ;
}
F_4 ( V_4 ) ;
if ( V_6 == 0 && V_87 )
V_6 = F_21 ( V_29 ) ;
return V_6 ;
}
static void F_15 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
F_2 ( V_4 ) ;
if ( V_4 -> V_23 -> V_41 )
V_4 -> V_23 -> V_41 () ;
F_4 ( V_4 ) ;
}
static void F_22 ( struct V_28 * V_29 , int V_99 )
{
struct V_100 * V_37 = & V_29 -> V_37 ;
struct V_34 * V_35 = & V_29 -> V_35 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_101 * V_102 ;
int V_20 ;
V_102 = & V_32 -> V_4 -> V_9 . V_10 [ V_32 -> V_43 ] ;
V_29 -> V_103 = V_102 -> V_26 ;
if ( ! V_99 ) {
F_3 ( & V_29 -> V_104 ) ;
V_37 -> V_105 = V_102 -> V_25 ;
V_37 -> V_106 = V_102 -> V_11 ;
F_5 ( & V_29 -> V_104 ) ;
} else {
V_37 -> V_105 = V_102 -> V_25 ;
V_37 -> V_106 = V_102 -> V_11 ;
}
V_37 -> type = V_107 ;
V_20 = V_35 -> V_40 ;
if ( V_35 -> V_108 )
V_37 -> V_109 = V_110 ;
else switch ( V_35 -> V_40 ) {
case 16 :
case 12 :
V_37 -> V_109 = V_111 ;
V_20 = 16 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_37 -> V_109 = V_110 ;
break;
}
V_37 -> V_112 = V_113 ;
V_37 -> V_38 = V_35 -> V_46 * V_20 / 8 ;
}
static int F_23 ( struct V_31 * V_32 ,
struct V_34 * V_35 )
{
switch ( V_35 -> V_108 ) {
case 0 :
break;
case V_64 :
V_35 -> V_40 = 16 ;
V_32 -> V_51 = V_35 -> V_108 ;
return 0 ;
case V_65 :
V_35 -> V_40 = 12 ;
V_32 -> V_51 = V_35 -> V_108 ;
return 0 ;
case V_66 :
V_35 -> V_40 = 16 ;
V_32 -> V_51 = V_35 -> V_108 ;
return 0 ;
default:
return - V_67 ;
}
switch ( V_35 -> V_40 ) {
case 1 :
V_32 -> V_51 = V_71 ;
return 0 ;
case 2 :
V_32 -> V_51 = V_70 ;
return 0 ;
case 4 :
V_32 -> V_51 = V_69 ;
return 0 ;
case 8 :
V_32 -> V_51 = V_68 ;
return 0 ;
case 12 :
V_35 -> V_40 = 16 ;
case 16 :
if ( V_32 -> V_4 -> V_18 -> V_20 == 12 )
V_32 -> V_51 = V_74 ;
else
V_32 -> V_51 = V_73 ;
return 0 ;
default:
return - V_67 ;
}
}
static int F_24 ( struct V_28 * V_29 ,
struct V_34 * V_35 )
{
int V_20 ;
unsigned long V_114 ;
unsigned long V_115 ;
int V_116 , V_117 ;
int V_118 , V_119 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_17 * V_18 = V_4 -> V_18 ;
if ( F_23 ( V_32 , V_35 ) < 0 )
return - V_67 ;
V_20 = V_35 -> V_40 ;
if ( V_32 -> V_51 == V_74 )
V_20 = 16 ;
switch ( V_35 -> V_53 ) {
case 0 :
case 180 :
V_116 = V_120 ;
V_117 = V_18 -> V_121 ;
V_118 = V_122 ;
V_119 = V_18 -> V_123 ;
if ( F_25 () ) {
V_35 -> V_49 = V_18 -> V_121 ;
V_35 -> V_50 = V_18 -> V_123 ;
}
break;
case 90 :
case 270 :
V_116 = V_122 ;
V_117 = V_18 -> V_123 ;
V_118 = V_120 ;
V_119 = V_18 -> V_121 ;
if ( F_25 () ) {
V_35 -> V_49 = V_18 -> V_123 ;
V_35 -> V_50 = V_18 -> V_121 ;
}
break;
default:
return - V_67 ;
}
if ( V_35 -> V_49 < V_116 )
V_35 -> V_49 = V_116 ;
if ( V_35 -> V_50 < V_118 )
V_35 -> V_50 = V_118 ;
if ( V_35 -> V_49 > V_117 )
V_35 -> V_49 = V_117 ;
if ( V_35 -> V_50 > V_119 )
V_35 -> V_50 = V_119 ;
if ( V_35 -> V_46 < V_35 -> V_49 )
V_35 -> V_46 = V_35 -> V_49 ;
if ( V_35 -> V_124 < V_35 -> V_50 )
V_35 -> V_124 = V_35 -> V_50 ;
V_114 = V_4 -> V_9 . V_10 [ V_32 -> V_43 ] . V_11 ;
V_115 = V_35 -> V_46 * V_20 / 8 ;
if ( V_115 * V_35 -> V_124 > V_114 ) {
V_115 = V_114 / V_35 -> V_124 ;
V_35 -> V_46 = V_115 * 8 / V_20 ;
if ( V_35 -> V_46 < V_35 -> V_49 ) {
V_35 -> V_46 = V_35 -> V_49 ;
V_115 = V_35 -> V_49 * V_20 / 8 ;
V_35 -> V_124 = V_114 / V_115 ;
}
if ( V_35 -> V_46 < V_35 -> V_49 )
V_35 -> V_49 = V_35 -> V_46 ;
if ( V_35 -> V_124 < V_35 -> V_50 )
V_35 -> V_50 = V_35 -> V_124 ;
if ( V_35 -> V_49 < V_116 || V_35 -> V_50 < V_118 )
return - V_67 ;
}
if ( V_35 -> V_49 + V_35 -> V_39 > V_35 -> V_46 )
V_35 -> V_39 = V_35 -> V_46 - V_35 -> V_49 ;
if ( V_35 -> V_50 + V_35 -> V_36 > V_35 -> V_124 )
V_35 -> V_36 = V_35 -> V_124 - V_35 -> V_50 ;
if ( V_32 -> V_51 == V_74 ) {
V_35 -> V_59 . V_30 = 8 ; V_35 -> V_59 . V_76 = 4 ;
V_35 -> V_59 . V_125 = 0 ;
V_35 -> V_60 . V_30 = 4 ; V_35 -> V_60 . V_76 = 4 ;
V_35 -> V_60 . V_125 = 0 ;
V_35 -> V_61 . V_30 = 0 ; V_35 -> V_61 . V_76 = 4 ;
V_35 -> V_61 . V_125 = 0 ;
} else {
V_35 -> V_59 . V_30 = 11 ; V_35 -> V_59 . V_76 = 5 ;
V_35 -> V_59 . V_125 = 0 ;
V_35 -> V_60 . V_30 = 5 ; V_35 -> V_60 . V_76 = 6 ;
V_35 -> V_60 . V_125 = 0 ;
V_35 -> V_61 . V_30 = 0 ; V_35 -> V_61 . V_76 = 5 ;
V_35 -> V_61 . V_125 = 0 ;
}
V_35 -> V_126 = - 1 ;
V_35 -> V_127 = - 1 ;
V_35 -> V_128 = 0 ;
V_35 -> V_129 = 10000000 / ( V_18 -> V_130 / 100 ) ;
V_35 -> V_131 = V_18 -> V_132 ;
V_35 -> V_133 = V_18 -> V_134 ;
V_35 -> V_135 = V_18 -> V_136 ;
V_35 -> V_137 = V_18 -> V_138 ;
V_35 -> V_139 = V_18 -> V_140 ;
V_35 -> V_141 = V_18 -> V_142 ;
V_35 -> V_143 = V_144 ;
V_35 -> V_41 = 0 ;
return 0 ;
}
static void F_26 ( struct V_28 * V_29 , int V_53 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
F_2 ( V_4 ) ;
if ( V_53 != V_29 -> V_35 . V_53 ) {
struct V_34 * V_145 = & V_4 -> V_145 ;
memcpy ( V_145 , & V_29 -> V_35 , sizeof( * V_145 ) ) ;
V_145 -> V_53 = V_53 ;
if ( F_24 ( V_29 , V_145 ) == 0 &&
memcmp ( V_145 , & V_29 -> V_35 , sizeof( * V_145 ) ) ) {
memcpy ( & V_29 -> V_35 , V_145 , sizeof( * V_145 ) ) ;
F_12 ( V_29 ) ;
}
}
F_4 ( V_4 ) ;
}
static int F_27 ( struct V_34 * V_35 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
if ( V_35 -> V_39 != V_29 -> V_35 . V_39 ||
V_35 -> V_36 != V_29 -> V_35 . V_36 ) {
struct V_34 * V_145 = & V_4 -> V_145 ;
memcpy ( V_145 , & V_29 -> V_35 , sizeof( * V_145 ) ) ;
V_145 -> V_39 = V_35 -> V_39 ;
V_145 -> V_36 = V_35 -> V_36 ;
if ( F_24 ( V_29 , V_145 ) )
V_6 = - V_67 ;
else {
memcpy ( & V_29 -> V_35 , V_145 , sizeof( * V_145 ) ) ;
F_12 ( V_29 ) ;
}
}
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_28 ( struct V_28 * V_29 , int V_146 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
V_146 = V_146 ? 1 : 0 ;
if ( F_25 () )
V_6 = - V_67 ;
else if ( V_146 != V_32 -> V_44 . V_146 ) {
V_32 -> V_44 . V_146 = V_146 ;
V_6 = F_12 ( V_29 ) ;
}
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_29 ( struct V_34 * V_35 , struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_6 ;
F_2 ( V_4 ) ;
if ( V_4 -> V_23 -> V_41 != NULL )
V_4 -> V_23 -> V_41 () ;
V_6 = F_24 ( V_29 , V_35 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_30 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
F_22 ( V_29 , 0 ) ;
V_6 = F_12 ( V_29 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
int F_31 ( struct V_28 * V_29 ,
struct V_147 * V_148 ,
void (* F_32)( void * ) ,
void * V_149 )
{
int V_49 , V_50 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_34 * V_35 = & V_29 -> V_35 ;
switch ( V_35 -> V_53 ) {
case 0 :
case 180 :
V_49 = V_4 -> V_18 -> V_121 ;
V_50 = V_4 -> V_18 -> V_123 ;
break;
case 90 :
case 270 :
V_49 = V_4 -> V_18 -> V_123 ;
V_50 = V_4 -> V_18 -> V_121 ;
break;
default:
return - V_67 ;
}
if ( V_148 -> V_150 >= V_49 || V_148 -> V_151 >= V_50 ||
V_148 -> V_152 > V_49 || V_148 -> V_153 > V_50 )
return - V_67 ;
if ( ! V_4 -> V_23 -> V_154 ||
V_4 -> V_23 -> V_94 () != V_95 )
return - V_155 ;
if ( V_148 -> V_150 + V_148 -> V_127 > V_49 )
V_148 -> V_127 = V_49 - V_148 -> V_150 ;
if ( V_148 -> V_151 + V_148 -> V_126 > V_50 )
V_148 -> V_126 = V_50 - V_148 -> V_151 ;
if ( V_148 -> V_152 + V_148 -> V_55 > V_49 )
V_148 -> V_55 = V_49 - V_148 -> V_152 ;
if ( V_148 -> V_153 + V_148 -> V_56 > V_50 )
V_148 -> V_56 = V_50 - V_148 -> V_153 ;
if ( ! V_148 -> V_127 || ! V_148 -> V_126 || ! V_148 -> V_55 || ! V_148 -> V_56 )
return 0 ;
return V_4 -> V_23 -> V_154 ( V_29 , V_148 , F_32 , V_149 ) ;
}
static int F_33 ( struct V_28 * V_29 ,
struct V_147 * V_148 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
int V_156 ;
F_2 ( V_32 -> V_4 ) ;
V_156 = F_31 ( V_29 , V_148 , NULL , NULL ) ;
F_4 ( V_32 -> V_4 ) ;
return V_156 ;
}
static int F_21 ( struct V_28 * V_29 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_147 V_148 ;
int V_6 ;
if ( ! V_4 -> V_23 -> V_154 ||
V_4 -> V_23 -> V_94 () != V_95 )
return - V_155 ;
V_148 . V_150 = 0 ;
V_148 . V_151 = 0 ;
V_148 . V_127 = V_29 -> V_35 . V_49 ;
V_148 . V_126 = V_29 -> V_35 . V_50 ;
V_148 . V_152 = 0 ;
V_148 . V_153 = 0 ;
V_148 . V_55 = V_29 -> V_35 . V_49 ;
V_148 . V_56 = V_29 -> V_35 . V_50 ;
V_148 . V_157 = 0 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_154 ( V_29 , & V_148 , NULL , NULL ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_34 ( struct V_28 * V_29 , struct V_158 * V_159 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_17 * V_18 = V_4 -> V_18 ;
struct V_158 V_160 ;
int V_6 = 0 ;
if ( V_159 -> V_47 + V_159 -> V_55 > V_18 -> V_121 ||
V_159 -> V_48 + V_159 -> V_56 > V_18 -> V_123 )
return - V_67 ;
F_2 ( V_4 ) ;
if ( V_159 -> V_161 && ! V_4 -> V_9 . V_10 [ V_32 -> V_43 ] . V_11 ) {
V_6 = - V_67 ;
goto V_162;
}
V_160 = V_32 -> V_44 ;
V_32 -> V_44 = * V_159 ;
if ( V_159 -> V_161 ) {
V_6 = F_12 ( V_29 ) ;
if ( V_6 < 0 ) {
V_32 -> V_44 = V_160 ;
goto V_162;
}
}
V_6 = V_4 -> V_23 -> V_163 ( V_32 -> V_43 , V_159 -> V_161 ) ;
if ( V_6 < 0 ) {
V_32 -> V_44 = V_160 ;
goto V_162;
}
V_162:
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_35 ( struct V_28 * V_29 , struct V_158 * V_159 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
* V_159 = V_32 -> V_44 ;
return 0 ;
}
static int F_36 ( struct V_28 * V_29 , struct V_164 * V_165 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_101 * V_102 = & V_4 -> V_9 . V_10 [ V_32 -> V_43 ] ;
T_3 V_11 ;
int V_6 = 0 ;
if ( V_4 -> V_23 -> V_166 == NULL )
return - V_155 ;
if ( V_165 -> type > V_167 )
return - V_67 ;
V_11 = F_7 ( V_165 -> V_11 ) ;
F_2 ( V_4 ) ;
if ( V_32 -> V_44 . V_161 ) {
V_6 = - V_168 ;
goto V_162;
}
if ( V_102 -> V_11 != V_11 || V_102 -> type != V_165 -> type ) {
struct V_34 * V_145 = & V_4 -> V_145 ;
unsigned long V_169 = V_102 -> V_11 ;
T_4 V_170 = V_102 -> type ;
unsigned long V_25 ;
V_102 -> V_11 = V_11 ;
V_102 -> type = V_165 -> type ;
if ( V_169 != V_11 && V_11 ) {
if ( V_11 ) {
memcpy ( V_145 , & V_29 -> V_35 , sizeof( * V_145 ) ) ;
V_6 = F_24 ( V_29 , V_145 ) ;
if ( V_6 < 0 )
goto V_162;
}
}
if ( V_4 -> V_23 -> V_41 )
V_4 -> V_23 -> V_41 () ;
V_6 = V_4 -> V_23 -> V_166 ( V_32 -> V_43 , V_11 , V_165 -> type , & V_25 ) ;
if ( V_6 < 0 ) {
V_102 -> V_11 = V_169 ;
V_102 -> type = V_170 ;
goto V_162;
}
V_102 -> V_25 = V_25 ;
if ( V_169 != V_11 ) {
if ( V_11 ) {
memcpy ( & V_29 -> V_35 , V_145 , sizeof( V_29 -> V_35 ) ) ;
F_22 ( V_29 , 0 ) ;
} else {
F_3 ( & V_29 -> V_104 ) ;
V_29 -> V_37 . V_105 = 0 ;
V_29 -> V_37 . V_106 = 0 ;
F_5 ( & V_29 -> V_104 ) ;
}
}
}
V_162:
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_37 ( struct V_28 * V_29 , struct V_164 * V_165 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_101 * V_102 ;
V_102 = & V_4 -> V_9 . V_10 [ V_32 -> V_43 ] ;
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
V_165 -> V_11 = V_102 -> V_11 ;
V_165 -> type = V_102 -> type ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_171 * V_172 )
{
int V_6 ;
if ( ! V_4 -> V_23 -> V_173 )
return - V_155 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_173 ( V_172 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_171 * V_172 )
{
int V_6 ;
if ( ! V_4 -> V_23 -> V_174 )
return - V_155 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_174 ( V_172 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static void F_40 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_175 ; V_7 ++ )
F_41 ( & V_176 [ V_7 ] ) ;
}
int F_42 ( struct V_177 * V_178 ,
T_5 F_32 ,
void * V_149 )
{
int V_6 ;
if ( ( unsigned ) V_178 -> V_179 > V_175 )
return - V_67 ;
if ( ! V_180 ) {
F_40 () ;
V_180 = 1 ;
}
V_178 -> V_181 . V_182 = ( int (*) (struct V_183 * ,
unsigned long , void * ) ) F_32 ;
V_178 -> V_184 = V_149 ;
V_6 = F_43 (
& V_176 [ V_178 -> V_179 ] ,
& V_178 -> V_181 ) ;
if ( V_6 )
return V_6 ;
if ( V_185 != NULL &&
V_185 -> V_23 && V_185 -> V_23 -> V_186 ) {
V_185 -> V_23 -> V_186 ( V_178 ) ;
}
return 0 ;
}
int F_44 ( struct V_177 * V_178 )
{
return F_45 (
& V_176 [ V_178 -> V_179 ] , & V_178 -> V_181 ) ;
}
void F_46 ( struct V_3 * V_4 , unsigned long V_187 )
{
int V_7 ;
if ( ! V_180 )
return;
for ( V_7 = 0 ; V_7 < V_175 ; V_7 ++ )
F_47 ( & V_176 [ V_7 ] , V_187 ,
V_4 -> V_28 [ V_7 ] ) ;
}
static int F_48 ( struct V_3 * V_4 ,
enum V_188 V_189 )
{
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_190 ( V_189 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static enum V_188 F_49 ( struct V_3 * V_4 )
{
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_94 () ;
F_4 ( V_4 ) ;
return V_6 ;
}
static void F_50 ( struct V_3 * V_4 , int V_32 ,
struct V_191 * V_192 )
{
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_4 -> V_23 -> V_193 ( V_32 , V_192 ) ;
V_192 -> V_23 |= V_4 -> V_18 -> V_193 ( V_4 -> V_18 ) ;
}
void F_51 ( struct V_3 * V_4 , T_2 V_194 )
{
F_2 ( V_4 ) ;
* ( T_2 * ) V_4 -> V_9 . V_10 [ 0 ] . V_26 = V_194 ;
if ( V_4 -> V_23 -> V_94 () == V_95 ) {
struct V_147 V_148 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_148 . V_127 = 2 ;
V_148 . V_126 = 2 ;
V_148 . V_55 = 2 ;
V_148 . V_56 = 2 ;
V_4 -> V_23 -> V_154 ( V_4 -> V_28 [ 0 ] , & V_148 , NULL , NULL ) ;
}
F_4 ( V_4 ) ;
}
static int F_52 ( struct V_28 * V_29 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_197 * V_198 = V_29 -> V_199 ;
union {
struct V_147 V_154 ;
struct V_158 V_200 ;
struct V_164 V_201 ;
struct V_171 V_202 ;
enum V_188 V_203 ;
struct V_191 V_192 ;
unsigned int V_146 ;
int V_204 ;
int V_163 ;
} V_205 ;
int V_6 = 0 ;
F_53 ( ! V_198 ) ;
switch ( V_195 ) {
case V_206 :
if ( F_54 ( V_205 . V_146 , ( int V_207 * ) V_196 ) )
V_6 = - V_208 ;
else
F_28 ( V_29 , V_205 . V_146 ) ;
break;
case V_209 :
F_15 ( V_29 ) ;
break;
case V_210 :
break;
case V_211 :
if ( F_54 ( V_205 . V_203 , ( int V_207 * ) V_196 ) )
V_6 = - V_208 ;
else
V_6 = F_48 ( V_4 , V_205 . V_203 ) ;
break;
case V_212 :
V_205 . V_203 = F_49 ( V_4 ) ;
if ( F_55 ( V_205 . V_203 ,
(enum V_188 V_207 * ) V_196 ) )
V_6 = - V_208 ;
break;
case V_213 :
if ( F_56 ( & V_205 . V_154 , ( void V_207 * ) V_196 ,
sizeof( struct V_214 ) ) )
V_6 = - V_208 ;
else {
struct V_147 * V_215 = & V_205 . V_154 ;
V_215 -> V_152 = V_215 -> V_150 ;
V_215 -> V_153 = V_215 -> V_151 ;
V_215 -> V_55 = V_215 -> V_127 ;
V_215 -> V_56 = V_215 -> V_126 ;
memset ( V_215 -> V_216 , 0 , sizeof( V_215 -> V_216 ) ) ;
V_6 = F_33 ( V_29 , V_215 ) ;
}
break;
case V_217 :
if ( F_56 ( & V_205 . V_154 , ( void V_207 * ) V_196 ,
sizeof( V_205 . V_154 ) ) )
V_6 = - V_208 ;
else
V_6 = F_33 ( V_29 , & V_205 . V_154 ) ;
break;
case V_218 :
if ( F_56 ( & V_205 . V_200 , ( void V_207 * ) V_196 ,
sizeof( V_205 . V_200 ) ) )
V_6 = - V_208 ;
else
V_6 = F_34 ( V_29 , & V_205 . V_200 ) ;
break;
case V_219 :
if ( ( V_6 = F_35 ( V_29 , & V_205 . V_200 ) ) < 0 )
break;
if ( F_57 ( ( void V_207 * ) V_196 , & V_205 . V_200 ,
sizeof( V_205 . V_200 ) ) )
V_6 = - V_208 ;
break;
case V_220 :
if ( F_56 ( & V_205 . V_201 , ( void V_207 * ) V_196 ,
sizeof( V_205 . V_201 ) ) )
V_6 = - V_208 ;
else
V_6 = F_36 ( V_29 , & V_205 . V_201 ) ;
break;
case V_221 :
if ( ( V_6 = F_37 ( V_29 , & V_205 . V_201 ) ) < 0 )
break;
if ( F_57 ( ( void V_207 * ) V_196 , & V_205 . V_201 ,
sizeof( V_205 . V_201 ) ) )
V_6 = - V_208 ;
break;
case V_222 :
if ( F_56 ( & V_205 . V_202 , ( void V_207 * ) V_196 ,
sizeof( V_205 . V_202 ) ) )
V_6 = - V_208 ;
else
V_6 = F_38 ( V_4 , & V_205 . V_202 ) ;
break;
case V_223 :
if ( ( V_6 = F_39 ( V_4 , & V_205 . V_202 ) ) < 0 )
break;
if ( F_57 ( ( void V_207 * ) V_196 , & V_205 . V_202 ,
sizeof( V_205 . V_202 ) ) )
V_6 = - V_208 ;
break;
case V_224 :
F_50 ( V_4 , V_32 -> V_43 , & V_205 . V_192 ) ;
if ( F_57 ( ( void V_207 * ) V_196 , & V_205 . V_192 , sizeof( V_205 . V_192 ) ) )
V_6 = - V_208 ;
break;
case V_225 :
{
int V_226 ;
if ( F_54 ( V_226 , ( int V_207 * ) V_196 ) ) {
V_6 = - V_208 ;
break;
}
if ( ! V_4 -> V_18 -> V_227 ) {
V_6 = - V_67 ;
break;
}
V_6 = V_4 -> V_18 -> V_227 ( V_4 -> V_18 , V_226 ) ;
break;
}
case V_228 :
{
int V_226 ;
if ( F_54 ( V_226 , ( int V_207 * ) V_196 ) ) {
V_6 = - V_208 ;
break;
}
if ( ! V_4 -> V_23 -> V_227 ) {
V_6 = - V_67 ;
break;
}
V_6 = V_4 -> V_23 -> V_227 ( V_226 ) ;
break;
}
default:
V_6 = - V_67 ;
}
return V_6 ;
}
static int F_58 ( struct V_28 * V_44 , struct V_229 * V_230 )
{
struct V_31 * V_32 = V_44 -> V_33 ;
struct V_3 * V_4 = V_32 -> V_4 ;
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_23 -> V_231 ( V_44 , V_230 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static T_6 F_59 ( struct V_1 * V_2 ,
struct V_232 * V_233 , char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
int V_32 ;
T_3 V_11 ;
struct V_191 V_192 ;
V_32 = 0 ;
V_11 = 0 ;
while ( V_11 < V_235 && V_32 < V_175 ) {
F_50 ( V_4 , V_32 , & V_192 ) ;
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_3 ,
V_32 , V_192 . V_23 , V_192 . V_236 , V_192 . V_237 ) ;
V_32 ++ ;
}
return V_11 ;
}
static T_6 F_61 ( struct V_1 * V_2 ,
struct V_232 * V_233 , char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
int V_7 ;
struct V_191 V_192 ;
int V_32 ;
T_3 V_11 ;
V_32 = 0 ;
V_11 = 0 ;
while ( V_11 < V_235 && V_32 < V_175 ) {
F_50 ( V_4 , V_32 , & V_192 ) ;
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_4 , V_32 ) ;
for ( V_7 = 0 ; V_7 < F_62 ( V_238 ) &&
V_11 < V_235 ; V_7 ++ ) {
if ( V_238 [ V_7 ] . V_239 & V_192 . V_23 )
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_5 , V_238 [ V_7 ] . V_240 ) ;
}
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_6 ) ;
for ( V_7 = 0 ; V_7 < F_62 ( V_241 ) &&
V_11 < V_235 ; V_7 ++ ) {
if ( V_241 [ V_7 ] . V_239 & V_192 . V_236 )
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_7 , V_241 [ V_7 ] . V_240 ) ;
}
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_8 ) ;
for ( V_7 = 0 ; V_7 < F_62 ( V_241 ) &&
V_11 < V_235 ; V_7 ++ ) {
if ( V_241 [ V_7 ] . V_239 & V_192 . V_237 )
V_11 += snprintf ( & V_234 [ V_11 ] , V_235 - V_11 ,
L_7 , V_241 [ V_7 ] . V_240 ) ;
}
V_32 ++ ;
}
return V_11 ;
}
static T_6 F_63 ( struct V_1 * V_2 ,
struct V_232 * V_233 , char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
return snprintf ( V_234 , V_235 , L_9 , V_4 -> V_18 -> V_240 ) ;
}
static T_6 F_64 ( struct V_1 * V_2 ,
struct V_232 * V_233 ,
char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_18 -> V_242 ) {
V_6 = snprintf ( V_234 , V_235 , L_10 ,
V_4 -> V_18 -> V_242 ( V_4 -> V_18 ) ) ;
} else
V_6 = - V_155 ;
return V_6 ;
}
static T_6 F_65 ( struct V_1 * V_2 ,
struct V_232 * V_233 ,
const char * V_234 , T_3 V_11 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_18 -> V_243 ) {
unsigned int V_244 ;
if ( sscanf ( V_234 , L_11 , & V_244 ) == 1 ) {
V_6 = V_4 -> V_18 -> V_243 ( V_4 -> V_18 ,
V_244 ) ;
} else
V_6 = - V_67 ;
} else
V_6 = - V_155 ;
return V_6 ? V_6 : V_11 ;
}
static T_6 F_66 ( struct V_1 * V_2 ,
struct V_232 * V_233 , char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_18 -> V_242 ) {
V_6 = snprintf ( V_234 , V_235 , L_10 ,
V_4 -> V_18 -> V_245 ( V_4 -> V_18 ) ) ;
} else
V_6 = - V_155 ;
return V_6 ;
}
static T_6 F_67 ( struct V_1 * V_2 ,
struct V_232 * V_233 , char * V_234 )
{
struct V_3 * V_4 = F_60 ( V_2 ) ;
return snprintf ( V_234 , V_235 , L_9 , V_4 -> V_23 -> V_240 ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
int V_6 ;
if ( ( V_6 = F_69 ( V_4 -> V_2 , & V_246 ) ) )
goto V_247;
if ( ( V_6 = F_69 ( V_4 -> V_2 , & V_248 ) ) )
goto V_249;
if ( ( V_6 = F_70 ( & V_4 -> V_2 -> V_250 , & V_251 ) ) )
goto V_252;
if ( ( V_6 = F_70 ( & V_4 -> V_2 -> V_250 , & V_253 ) ) )
goto V_254;
return 0 ;
V_254:
F_71 ( & V_4 -> V_2 -> V_250 , & V_251 ) ;
V_252:
F_72 ( V_4 -> V_2 , & V_248 ) ;
V_249:
F_72 ( V_4 -> V_2 , & V_246 ) ;
V_247:
F_8 ( V_4 -> V_2 , L_12 ) ;
return V_6 ;
}
static void F_73 ( struct V_3 * V_4 )
{
F_71 ( & V_4 -> V_2 -> V_250 , & V_253 ) ;
F_71 ( & V_4 -> V_2 -> V_250 , & V_251 ) ;
F_72 ( V_4 -> V_2 , & V_246 ) ;
F_72 ( V_4 -> V_2 , & V_248 ) ;
}
static int F_74 ( struct V_3 * V_4 , struct V_28 * V_44 )
{
struct V_34 * V_35 = & V_44 -> V_35 ;
struct V_100 * V_37 = & V_44 -> V_37 ;
int V_6 = 0 ;
V_44 -> V_199 = & V_255 ;
V_44 -> V_256 = V_257 ;
strncpy ( V_37 -> V_258 , V_259 , sizeof( V_37 -> V_258 ) ) ;
V_44 -> V_78 = V_4 -> V_78 ;
V_35 -> V_260 = V_261 ? V_262 : 0 ;
V_35 -> V_49 = V_21 ;
V_35 -> V_50 = V_22 ;
V_35 -> V_46 = V_21 ;
V_35 -> V_124 = V_22 ;
V_35 -> V_53 = V_263 ;
V_35 -> V_40 = V_4 -> V_18 -> V_20 ;
F_24 ( V_44 , V_35 ) ;
F_22 ( V_44 , 1 ) ;
V_6 = F_75 ( & V_44 -> V_80 , 16 , 0 ) ;
if ( V_6 != 0 )
F_8 ( V_4 -> V_2 , L_13 ) ;
return V_6 ;
}
static void F_76 ( struct V_3 * V_4 , struct V_28 * V_29 )
{
F_77 ( & V_29 -> V_80 ) ;
}
static void F_78 ( struct V_3 * V_4 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
if ( V_4 -> V_28 [ V_7 ] == NULL )
break;
F_76 ( V_4 , V_4 -> V_28 [ V_7 ] ) ;
F_79 ( V_4 -> V_28 [ V_7 ] ) ;
}
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_28 * V_29 ;
int V_7 ;
int V_6 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
struct V_31 * V_32 ;
V_29 = F_81 ( sizeof( struct V_31 ) ,
V_4 -> V_2 ) ;
if ( V_29 == NULL ) {
F_8 ( V_4 -> V_2 ,
L_14 ) ;
F_78 ( V_4 ) ;
return - V_264 ;
}
V_32 = V_29 -> V_33 ;
V_32 -> V_43 = V_7 ;
V_32 -> V_4 = V_4 ;
V_32 -> V_44 . V_146 = V_265 ;
V_4 -> V_28 [ V_7 ] = V_29 ;
if ( ( V_6 = F_74 ( V_4 , V_29 ) ) < 0 ) {
F_79 ( V_29 ) ;
F_78 ( V_4 ) ;
return V_6 ;
}
V_32 -> V_44 . V_55 = V_29 -> V_35 . V_49 ;
V_32 -> V_44 . V_56 = V_29 -> V_35 . V_50 ;
}
return 0 ;
}
static void F_82 ( struct V_3 * V_4 , int V_89 )
{
int V_7 ;
switch ( V_89 ) {
case V_93 :
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ )
F_83 ( V_4 -> V_28 [ V_7 ] ) ;
case 7 :
F_73 ( V_4 ) ;
case 6 :
V_4 -> V_18 -> V_97 ( V_4 -> V_18 ) ;
case 5 :
F_48 ( V_4 , V_266 ) ;
case 4 :
F_78 ( V_4 ) ;
case 3 :
F_11 ( V_4 ) ;
case 2 :
V_4 -> V_18 -> V_27 ( V_4 -> V_18 ) ;
case 1 :
F_84 ( V_4 -> V_2 , NULL ) ;
F_85 ( V_4 ) ;
case 0 :
break;
default:
F_17 () ;
}
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_14 * V_15 ;
char V_240 [ 17 ] ;
int V_7 ;
V_15 = V_4 -> V_2 -> V_16 ;
V_4 -> V_23 = NULL ;
strncpy ( V_240 , V_15 -> V_267 . V_268 , sizeof( V_240 ) - 1 ) ;
V_240 [ sizeof( V_240 ) - 1 ] = '\0' ;
if ( strcmp ( V_240 , L_15 ) == 0 ) {
V_4 -> V_23 = V_4 -> V_269 ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < F_62 ( V_270 ) ; V_7 ++ ) {
F_10 ( V_4 -> V_2 , L_16 , V_270 [ V_7 ] -> V_240 ) ;
if ( strcmp ( V_270 [ V_7 ] -> V_240 , V_240 ) == 0 ) {
V_4 -> V_23 = V_270 [ V_7 ] ;
break;
}
}
if ( V_4 -> V_23 == NULL ) {
F_10 ( V_4 -> V_2 , L_17 , V_240 ) ;
return - 1 ;
}
return 0 ;
}
static void F_87 ( struct V_3 * V_4 )
{
#define F_88 ( V_150 ) (fbdev->ctrl->x != NULL)
#define F_89 ( V_150 ) (fbdev->panel->x != NULL)
F_53 ( V_4 -> V_23 == NULL || V_4 -> V_18 == NULL ) ;
F_53 ( ! ( F_88 ( V_24 ) && F_88 ( V_27 ) && F_88 ( V_193 ) &&
F_88 ( V_190 ) && F_88 ( V_42 ) && F_88 ( V_163 ) &&
F_89 ( V_24 ) && F_89 ( V_27 ) && F_89 ( V_92 ) && F_89 ( V_97 ) &&
F_89 ( V_193 ) ) ) ;
#undef F_89
#undef F_88
}
static int F_90 ( struct V_271 * V_272 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = NULL ;
int V_273 ;
unsigned long V_274 , V_275 , V_276 ;
unsigned long V_277 ;
int V_7 ;
int V_6 = 0 ;
V_273 = 0 ;
if ( V_272 -> V_278 != 0 ) {
F_8 ( & V_272 -> V_2 , L_18 ) ;
V_6 = - V_155 ;
goto V_27;
}
if ( V_272 -> V_2 . V_16 == NULL ) {
F_8 ( & V_272 -> V_2 , L_19 ) ;
V_6 = - V_279 ;
goto V_27;
}
V_4 = F_91 ( sizeof( struct V_3 ) , V_280 ) ;
if ( V_4 == NULL ) {
F_8 ( & V_272 -> V_2 ,
L_20 ) ;
V_6 = - V_264 ;
goto V_27;
}
V_273 ++ ;
V_4 -> V_2 = & V_272 -> V_2 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_281 = & V_282 ;
F_92 ( V_272 , V_4 ) ;
F_93 ( & V_4 -> V_5 ) ;
#ifdef F_94
V_4 -> V_269 = & V_283 ;
#ifdef F_95
V_4 -> V_284 = & V_285 ;
#endif
#else
V_4 -> V_269 = & V_286 ;
#ifdef F_95
V_4 -> V_284 = & V_287 ;
#endif
#endif
if ( F_86 ( V_4 ) < 0 ) {
F_8 ( V_4 -> V_2 ,
L_21 ) ;
V_6 = - V_155 ;
goto V_27;
}
V_6 = V_4 -> V_18 -> V_24 ( V_4 -> V_18 , V_4 ) ;
if ( V_6 )
goto V_27;
F_96 ( L_22 , V_4 -> V_18 -> V_240 ) ;
V_21 = V_21 ? V_21 : V_4 -> V_18 -> V_121 ;
V_22 = V_22 ? V_22 : V_4 -> V_18 -> V_123 ;
V_273 ++ ;
V_6 = F_6 ( V_4 ) ;
if ( V_6 )
goto V_27;
if ( V_4 -> V_23 -> V_231 != NULL )
V_255 . V_288 = F_58 ;
V_273 ++ ;
F_87 ( V_4 ) ;
V_6 = F_80 ( V_4 ) ;
if ( V_6 )
goto V_27;
V_273 ++ ;
#ifdef F_97
if ( F_98 () )
F_99 ( 0 , V_289 , 15 ) ;
#endif
V_6 = F_12 ( V_4 -> V_28 [ 0 ] ) ;
if ( V_6 ) {
F_8 ( V_4 -> V_2 , L_23 ) ;
goto V_27;
}
V_6 = V_4 -> V_23 -> V_163 ( V_290 , 1 ) ;
if ( V_6 )
goto V_27;
F_48 ( V_4 , V_291 ?
V_95 : V_292 ) ;
V_273 ++ ;
V_6 = V_4 -> V_18 -> V_92 ( V_4 -> V_18 ) ;
if ( V_6 )
goto V_27;
V_273 ++ ;
V_6 = F_68 ( V_4 ) ;
if ( V_6 )
goto V_27;
V_273 ++ ;
V_277 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
V_6 = F_100 ( V_4 -> V_28 [ V_7 ] ) ;
if ( V_6 != 0 ) {
F_8 ( V_4 -> V_2 ,
L_24 , V_7 ) ;
goto V_27;
}
V_277 += V_4 -> V_9 . V_10 [ V_7 ] . V_11 ;
}
V_4 -> V_89 = V_93 ;
V_18 = V_4 -> V_18 ;
V_274 = V_18 -> V_130 * 1000 ;
V_275 = V_274 * 10 / ( V_18 -> V_132 + V_18 -> V_121 + V_18 -> V_134 + V_18 -> V_140 ) ;
V_276 = V_275 / ( V_18 -> V_136 + V_18 -> V_123 + V_18 -> V_138 + V_18 -> V_142 ) ;
V_185 = V_4 ;
F_96 ( L_25 ,
V_277 , V_4 -> V_9 . V_13 ) ;
F_96 ( L_26
L_27 ,
V_274 / 1000 , V_275 / 10000 , V_275 % 10 , V_276 / 10 , V_276 % 10 ) ;
return 0 ;
V_27:
F_82 ( V_4 , V_273 ) ;
return V_6 ;
}
static int F_101 ( struct V_271 * V_272 )
{
int V_6 ;
F_53 ( V_293 != NULL ) ;
V_6 = F_102 ( & V_282 ) ;
if ( V_6 ) {
F_8 ( & V_272 -> V_2 , L_28 ) ;
return V_6 ;
}
V_293 = V_272 ;
if ( V_294 != NULL )
F_90 ( V_293 , V_294 ) ;
return 0 ;
}
void F_103 ( struct V_17 * V_18 )
{
F_53 ( V_294 != NULL ) ;
V_294 = V_18 ;
if ( V_293 != NULL )
F_90 ( V_293 , V_294 ) ;
}
static int F_104 ( struct V_271 * V_272 )
{
struct V_3 * V_4 = F_105 ( V_272 ) ;
enum V_295 V_296 = V_4 -> V_89 ;
V_4 -> V_89 = V_297 ;
F_82 ( V_4 , V_296 ) ;
F_106 ( & V_282 ) ;
V_4 -> V_281 = NULL ;
return 0 ;
}
static int F_107 ( struct V_271 * V_272 , T_7 V_298 )
{
struct V_3 * V_4 = F_105 ( V_272 ) ;
if ( V_4 != NULL )
F_20 ( V_96 , V_4 -> V_28 [ 0 ] ) ;
return 0 ;
}
static int F_108 ( struct V_271 * V_272 )
{
struct V_3 * V_4 = F_105 ( V_272 ) ;
if ( V_4 != NULL )
F_20 ( V_88 , V_4 -> V_28 [ 0 ] ) ;
return 0 ;
}
static int T_8 F_109 ( char * V_299 )
{
char * V_300 = NULL ;
int V_6 = 0 ;
F_110 ( L_29 , V_299 ) ;
if ( ! V_299 || ! * V_299 )
return 0 ;
while ( ! V_6 && ( V_300 = F_111 ( & V_299 , L_30 ) ) != NULL ) {
if ( ! strncmp ( V_300 , L_31 , 5 ) )
V_261 = 1 ;
else if ( ! strncmp ( V_300 , L_32 , 5 ) ) {
char * V_301 ;
unsigned long V_277 ;
V_277 = ( F_112 ( V_300 + 5 , & V_301 , 0 ) ) ;
switch ( V_301 [ 0 ] ) {
case '\0' :
break;
case 'm' :
case 'M' :
V_277 *= 1024 ;
case 'k' :
case 'K' :
V_277 *= 1024 ;
break;
default:
F_110 ( L_33 ,
V_301 [ 0 ] ) ;
V_6 = - 1 ;
}
V_12 [ V_8 ++ ] = V_277 ;
}
else if ( ! strncmp ( V_300 , L_34 , 6 ) )
V_21 = F_112 ( V_300 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_300 , L_35 , 6 ) )
V_22 = F_112 ( V_300 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_300 , L_36 , 7 ) )
V_263 = ( F_112 ( V_300 + 7 , NULL , 0 ) ) ;
else if ( ! strncmp ( V_300 , L_37 , 7 ) )
V_265 = ( F_112 ( V_300 + 7 , NULL , 0 ) ) ;
else if ( ! strncmp ( V_300 , L_38 , 13 ) )
V_291 = 1 ;
else {
F_110 ( L_39 ) ;
V_6 = - 1 ;
}
}
return V_6 ;
}
static int T_8 F_113 ( void )
{
#ifndef F_114
char * V_302 ;
if ( F_115 ( L_40 , & V_302 ) )
return - V_155 ;
F_109 ( V_302 ) ;
#endif
if ( F_116 ( & V_303 ) ) {
F_110 ( L_41 ) ;
return - V_155 ;
}
return 0 ;
}
static void T_9 F_117 ( void )
{
F_118 ( & V_303 ) ;
}
