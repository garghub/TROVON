static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = F_3 ( V_8 , V_6 ) ;
if ( ! V_4 -> V_7 ) {
F_4 ( V_4 ) ;
return NULL ;
}
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = false ;
V_4 -> V_11 = false ;
V_4 -> V_12 = V_3 ;
V_4 -> V_5 = V_5 ;
F_6 ( V_3 , V_4 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_13 )
{
F_4 ( V_13 -> V_7 ) ;
F_4 ( V_13 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_11 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_14;
if ( V_4 -> V_11 &&
F_10 ( & V_4 -> V_15 ) == 0 )
V_4 = NULL ;
V_14:
return V_4 ;
}
static int F_11 ( struct V_1 * V_4 )
{
struct V_16 * V_17 ;
int V_18 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_19 ) {
V_17 = & V_4 -> V_17 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_20 . V_21 =
V_22 ;
V_17 -> V_23 . V_24 .
V_25 . V_26 = V_27 ;
V_18 = F_12 ( V_4 -> V_12 -> V_28 ,
V_17 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_17 ,
V_29 , 0 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 , L_1
L_2 ) ;
return V_18 ;
}
}
if ( V_4 -> V_30 ) {
V_18 = F_14 ( V_4 -> V_12 -> V_28 ,
V_4 -> V_30 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_3 ) ;
return V_18 ;
}
V_4 -> V_30 = 0 ;
}
if ( V_4 -> V_31 ) {
F_15 ( V_4 -> V_31 ) ;
V_4 -> V_31 = NULL ;
}
if ( V_4 -> V_32 ) {
V_4 -> V_19 = 0 ;
F_4 ( V_4 -> V_32 ) ;
V_4 -> V_32 = NULL ;
}
if ( V_4 -> V_33 ) {
V_17 = & V_4 -> V_17 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_20 . V_21 =
V_34 ;
V_17 -> V_23 . V_24 . V_25 . V_26 = 0 ;
V_18 = F_12 ( V_4 -> V_12 -> V_28 ,
V_17 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_17 ,
V_29 , 0 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 , L_1
L_4 ) ;
return V_18 ;
}
}
if ( V_4 -> V_35 ) {
V_18 = F_14 ( V_4 -> V_12 -> V_28 ,
V_4 -> V_35 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_5 ) ;
return V_18 ;
}
V_4 -> V_35 = 0 ;
}
if ( V_4 -> V_36 ) {
F_15 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
}
F_4 ( V_4 -> V_37 ) ;
return V_18 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_18 = 0 ;
int V_38 ;
struct V_1 * V_4 ;
struct V_16 * V_39 ;
struct V_4 * V_5 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_40 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_31 = F_17 ( V_4 -> V_41 ) ;
if ( ! V_4 -> V_31 ) {
F_13 ( V_5 , L_6
L_7 , V_4 -> V_41 ) ;
V_18 = - V_42 ;
goto V_43;
}
V_18 = F_18 ( V_3 -> V_28 , V_4 -> V_31 ,
V_4 -> V_41 ,
& V_4 -> V_30 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_8 ) ;
goto V_43;
}
V_39 = & V_4 -> V_44 ;
memset ( V_39 , 0 , sizeof( struct V_16 ) ) ;
V_39 -> V_20 . V_21 = V_45 ;
V_39 -> V_23 . V_24 . V_46 .
V_47 = V_4 -> V_30 ;
V_39 -> V_23 . V_24 .
V_46 . V_26 = V_27 ;
V_18 = F_12 ( V_3 -> V_28 , V_39 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_39 ,
V_29 ,
V_48 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_9 ) ;
goto V_43;
}
V_38 = F_19 ( & V_4 -> V_49 , 5 * V_50 ) ;
F_20 ( V_38 == 0 ) ;
if ( V_39 -> V_23 . V_24 .
V_51 . V_52 != V_53 ) {
F_13 ( V_5 , L_10
L_11 ,
V_39 -> V_23 . V_24 .
V_51 . V_52 ) ;
V_18 = - V_54 ;
goto V_43;
}
V_4 -> V_19 = V_39 -> V_23 .
V_24 . V_51 . V_55 ;
V_4 -> V_32 = F_21 (
V_39 -> V_23 . V_24 . V_51 . V_56 ,
V_4 -> V_19 *
sizeof( struct V_57 ) ,
V_6 ) ;
if ( V_4 -> V_32 == NULL ) {
V_18 = - V_54 ;
goto V_43;
}
if ( V_4 -> V_19 != 1 ||
V_4 -> V_32 -> V_58 != 0 ) {
V_18 = - V_54 ;
goto V_43;
}
V_4 -> V_36 = F_17 ( V_4 -> V_59 ) ;
if ( ! V_4 -> V_36 ) {
F_13 ( V_5 , L_12
L_7 , V_4 -> V_59 ) ;
V_18 = - V_42 ;
goto V_43;
}
V_18 = F_18 ( V_3 -> V_28 , V_4 -> V_36 ,
V_4 -> V_59 ,
& V_4 -> V_35 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_13 ) ;
goto V_43;
}
V_39 = & V_4 -> V_44 ;
memset ( V_39 , 0 , sizeof( struct V_16 ) ) ;
V_39 -> V_20 . V_21 = V_60 ;
V_39 -> V_23 . V_24 . V_46 . V_47 =
V_4 -> V_35 ;
V_39 -> V_23 . V_24 . V_46 . V_26 = 0 ;
V_18 = F_12 ( V_3 -> V_28 , V_39 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_39 ,
V_29 ,
V_48 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_14 ) ;
goto V_43;
}
V_38 = F_19 ( & V_4 -> V_49 , 5 * V_50 ) ;
F_20 ( V_38 == 0 ) ;
if ( V_39 -> V_23 . V_24 .
V_61 . V_52 != V_53 ) {
F_13 ( V_5 , L_15
L_11 ,
V_39 -> V_23 . V_24 .
V_51 . V_52 ) ;
V_18 = - V_54 ;
goto V_43;
}
V_4 -> V_33 = V_39 -> V_23 .
V_24 . V_61 . V_62 ;
V_4 -> V_63 =
V_4 -> V_59 / V_4 -> V_33 ;
F_22 ( & V_3 -> V_3 , L_16 ,
V_4 -> V_33 , V_4 -> V_63 ) ;
V_4 -> V_64 = F_23 ( V_4 -> V_63 ,
V_65 ) ;
V_4 -> V_37 =
F_3 ( V_4 -> V_64 * sizeof( V_66 ) , V_6 ) ;
if ( V_4 -> V_37 == NULL ) {
V_18 = - V_42 ;
goto V_43;
}
goto exit;
V_43:
F_11 ( V_4 ) ;
exit:
return V_18 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_16 * V_39 ,
T_1 V_67 )
{
int V_18 , V_38 ;
memset ( V_39 , 0 , sizeof( struct V_16 ) ) ;
V_39 -> V_20 . V_21 = V_68 ;
V_39 -> V_23 . V_69 . V_70 . V_71 = V_67 ;
V_39 -> V_23 . V_69 . V_70 . V_72 = V_67 ;
V_18 = F_12 ( V_3 -> V_28 , V_39 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_39 ,
V_29 ,
V_48 ) ;
if ( V_18 != 0 )
return V_18 ;
V_38 = F_19 ( & V_4 -> V_49 , 5 * V_50 ) ;
if ( V_38 == 0 )
return - V_73 ;
if ( V_39 -> V_23 . V_69 . V_74 . V_52 !=
V_53 )
return - V_54 ;
if ( V_67 == V_75 )
return 0 ;
memset ( V_39 , 0 , sizeof( struct V_16 ) ) ;
V_39 -> V_20 . V_21 = V_76 ;
V_39 -> V_23 . V_77 . V_78 . V_79 = V_4 -> V_5 -> V_79 ;
V_39 -> V_23 . V_77 . V_78 . V_80 . V_81 = 1 ;
V_18 = F_12 ( V_3 -> V_28 , V_39 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_39 ,
V_29 , 0 ) ;
return V_18 ;
}
static int F_25 ( struct V_2 * V_3 )
{
int V_18 ;
struct V_1 * V_4 ;
struct V_16 * V_39 ;
int V_82 ;
struct V_4 * V_5 ;
T_1 V_83 [] = { V_75 , V_84 ,
V_85 , V_86 } ;
int V_87 , V_88 = 4 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_40 ;
V_5 = V_4 -> V_5 ;
V_39 = & V_4 -> V_44 ;
for ( V_87 = V_88 - 1 ; V_87 >= 0 ; V_87 -- )
if ( F_24 ( V_3 , V_4 , V_39 ,
V_83 [ V_87 ] ) == 0 ) {
V_4 -> V_89 = V_83 [ V_87 ] ;
break;
}
if ( V_87 < 0 ) {
V_18 = - V_90 ;
goto V_43;
}
F_26 ( L_17 , V_4 -> V_89 ) ;
memset ( V_39 , 0 , sizeof( struct V_16 ) ) ;
if ( V_4 -> V_89 <= V_85 )
V_82 = 0x00060001 ;
else
V_82 = 0x0006001e ;
V_39 -> V_20 . V_21 = V_91 ;
V_39 -> V_23 . V_24 .
V_92 . V_93 =
( V_82 & 0xFFFF0000 ) >> 16 ;
V_39 -> V_23 . V_24 .
V_92 . V_94 =
V_82 & 0xFFFF ;
V_18 = F_12 ( V_3 -> V_28 , V_39 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_39 ,
V_29 , 0 ) ;
if ( V_18 != 0 )
goto V_43;
if ( V_4 -> V_89 <= V_84 )
V_4 -> V_41 = V_95 ;
else
V_4 -> V_41 = V_96 ;
V_4 -> V_59 = V_97 ;
V_18 = F_16 ( V_3 ) ;
V_43:
return V_18 ;
}
static void F_27 ( struct V_1 * V_4 )
{
F_11 ( V_4 ) ;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_98 ;
V_4 = F_2 ( V_3 ) ;
F_27 ( V_4 ) ;
F_29 ( & V_3 -> V_28 -> V_99 , V_98 ) ;
F_6 ( V_3 , NULL ) ;
F_30 ( & V_3 -> V_28 -> V_99 , V_98 ) ;
F_31 ( & V_3 -> V_3 , L_18 ) ;
F_32 ( V_3 -> V_28 ) ;
if ( V_4 -> V_100 )
F_15 ( V_4 -> V_100 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_33 (
struct V_101 * V_102 )
{
T_1 V_103 , V_104 ;
F_34 ( V_102 , & V_103 , & V_104 ) ;
return V_104 * 100 / V_102 -> V_105 ;
}
static inline void F_35 ( struct V_1 * V_4 ,
T_1 V_106 )
{
F_36 ( V_106 , V_4 -> V_37 ) ;
}
static void F_37 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_107 * V_108 )
{
struct V_16 * V_109 ;
struct V_110 * V_111 ;
struct V_4 * V_5 ;
T_1 V_112 ;
V_5 = V_4 -> V_5 ;
V_109 = (struct V_16 * ) ( ( unsigned long ) V_108 +
( V_108 -> V_113 << 3 ) ) ;
if ( ( V_109 -> V_20 . V_21 == V_114 ) ||
( V_109 -> V_20 . V_21 ==
V_115 ) ||
( V_109 -> V_20 . V_21 ==
V_116 ) ||
( V_109 -> V_20 . V_21 ==
V_117 ) ) {
memcpy ( & V_4 -> V_44 , V_109 ,
sizeof( struct V_16 ) ) ;
F_38 ( & V_4 -> V_49 ) ;
} else if ( V_109 -> V_20 . V_21 ==
V_118 ) {
int V_15 ;
T_2 V_119 = 0 ;
struct V_120 * V_28 = V_3 -> V_28 ;
int V_121 ;
V_111 = (struct V_110 * ) ( unsigned long )
V_108 -> V_122 ;
if ( V_111 ) {
V_112 = V_111 -> V_123 ;
if ( V_112 != V_124 )
F_35 ( V_4 , V_112 ) ;
V_119 = V_111 -> V_119 ;
V_28 = V_111 -> V_28 ;
V_111 -> V_125 ( V_111 ->
V_126 ) ;
}
V_15 =
F_39 ( & V_4 -> V_15 ) ;
V_121 = F_39 ( & V_4 ->
V_121 [ V_119 ] ) ;
if ( V_4 -> V_11 && V_15 == 0 )
F_40 ( & V_4 -> V_9 ) ;
if ( F_41 ( F_42 ( V_5 , V_119 ) ) &&
! V_4 -> V_10 &&
( F_33 ( & V_28 -> V_127 ) >
V_128 || V_121 < 1 ) )
F_43 ( F_42 (
V_5 , V_119 ) ) ;
} else {
F_13 ( V_5 , L_19
L_20 , V_109 -> V_20 . V_21 ) ;
}
}
static T_1 F_44 ( struct V_1 * V_4 )
{
unsigned long V_106 ;
T_1 V_129 = V_4 -> V_64 ;
unsigned long * V_130 = ( unsigned long * ) V_4 -> V_37 ;
T_1 V_131 = V_4 -> V_63 ;
int V_132 = V_124 ;
int V_87 ;
int V_133 ;
for ( V_87 = 0 ; V_87 < V_129 ; V_87 ++ ) {
if ( ! ~ ( V_130 [ V_87 ] ) )
continue;
V_106 = F_45 ( V_130 [ V_87 ] ) ;
V_133 = F_46 ( V_106 , & V_130 [ V_87 ] ) ;
if ( V_133 )
continue;
if ( ( V_106 + ( V_87 * V_65 ) ) >= V_131 )
break;
V_132 = ( V_106 + ( V_87 * V_65 ) ) ;
break;
}
return V_132 ;
}
T_1 F_47 ( struct V_1 * V_4 ,
unsigned int V_134 ,
struct V_110 * V_108 )
{
char * V_135 = V_4 -> V_36 ;
char * V_136 = ( V_135 + ( V_134 * V_4 -> V_33 ) ) ;
int V_87 ;
T_1 V_137 = 0 ;
for ( V_87 = 0 ; V_87 < V_108 -> V_138 ; V_87 ++ ) {
char * V_139 = F_48 ( V_108 -> V_140 [ V_87 ] . V_141 << V_142 ) ;
T_1 V_58 = V_108 -> V_140 [ V_87 ] . V_58 ;
T_1 V_143 = V_108 -> V_140 [ V_87 ] . V_143 ;
memcpy ( V_136 , ( V_139 + V_58 ) , V_143 ) ;
V_137 += V_143 ;
V_136 += V_143 ;
}
return V_137 ;
}
int F_49 ( struct V_2 * V_3 ,
struct V_110 * V_108 )
{
struct V_1 * V_4 ;
int V_18 = 0 ;
struct V_16 V_144 ;
struct V_4 * V_5 ;
struct V_120 * V_145 = NULL ;
T_3 V_146 ;
unsigned int V_134 = V_124 ;
T_1 V_137 = 0 ;
struct V_147 * V_148 ;
T_2 V_119 = V_108 -> V_119 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_40 ;
V_5 = V_4 -> V_5 ;
V_144 . V_20 . V_21 = V_149 ;
if ( V_108 -> V_150 ) {
V_144 . V_23 . V_24 . V_151 . V_152 = 0 ;
} else {
V_144 . V_23 . V_24 . V_151 . V_152 = 1 ;
}
if ( V_108 -> V_153 < V_4 -> V_33 ) {
V_134 = F_44 ( V_4 ) ;
if ( V_134 != V_124 ) {
V_137 = F_47 ( V_4 ,
V_134 ,
V_108 ) ;
V_148 = (struct V_147 * )
( unsigned long ) V_108 -> V_154 ;
if ( V_148 )
F_50 ( V_148 ) ;
V_108 -> V_138 = 0 ;
}
}
V_108 -> V_123 = V_134 ;
V_144 . V_23 . V_24 . V_151 . V_155 =
V_134 ;
V_144 . V_23 . V_24 . V_151 . V_156 = V_137 ;
if ( V_108 -> V_125 )
V_146 = ( V_66 ) V_108 ;
else
V_146 = 0 ;
V_145 = V_4 -> V_157 [ V_108 -> V_119 ] ;
if ( V_145 == NULL )
V_145 = V_3 -> V_28 ;
V_108 -> V_28 = V_145 ;
if ( V_108 -> V_138 ) {
V_18 = F_51 ( V_145 ,
V_108 -> V_140 ,
V_108 -> V_138 ,
& V_144 ,
sizeof( struct V_16 ) ,
V_146 ) ;
} else {
V_18 = F_12 ( V_145 , & V_144 ,
sizeof( struct V_16 ) ,
V_146 ,
V_29 ,
V_48 ) ;
}
if ( V_18 == 0 ) {
F_52 ( & V_4 -> V_15 ) ;
F_52 ( & V_4 -> V_121 [ V_119 ] ) ;
if ( F_33 ( & V_145 -> V_127 ) <
V_158 ) {
F_53 ( F_42 (
V_5 , V_119 ) ) ;
if ( F_10 ( & V_4 ->
V_121 [ V_119 ] ) < 1 )
F_43 ( F_42 (
V_5 , V_119 ) ) ;
}
} else if ( V_18 == - V_159 ) {
F_53 ( F_42 (
V_5 , V_119 ) ) ;
if ( F_10 ( & V_4 -> V_121 [ V_119 ] ) < 1 ) {
F_43 ( F_42 (
V_5 , V_119 ) ) ;
V_18 = - V_160 ;
}
} else {
F_13 ( V_5 , L_21 ,
V_108 , V_18 ) ;
}
return V_18 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_120 * V_28 ,
struct V_1 * V_4 ,
T_3 V_161 , T_1 V_52 )
{
struct V_16 V_162 ;
int V_163 = 0 ;
int V_18 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_162 . V_20 . V_21 =
V_118 ;
V_162 . V_23 . V_24 . V_164 . V_52 = V_52 ;
V_165:
V_18 = F_12 ( V_28 , & V_162 ,
sizeof( struct V_16 ) , V_161 ,
V_166 , 0 ) ;
if ( V_18 == 0 ) {
} else if ( V_18 == - V_159 ) {
V_163 ++ ;
F_13 ( V_5 , L_22
L_23 , V_161 , V_163 ) ;
if ( V_163 < 4 ) {
F_55 ( 100 ) ;
goto V_165;
} else {
F_13 ( V_5 , L_24
L_25 ,
V_161 ) ;
}
} else {
F_13 ( V_5 , L_24
L_26 , V_161 ) ;
}
}
static void F_56 ( struct V_1 * V_4 ,
struct V_120 * V_28 ,
struct V_2 * V_3 ,
struct V_107 * V_108 )
{
struct V_167 * V_168 ;
struct V_16 * V_109 ;
struct V_110 V_169 ;
struct V_110 * V_170 = & V_169 ;
T_1 V_52 = V_53 ;
int V_87 ;
int V_171 = 0 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
if ( V_108 -> type != V_172 ) {
F_13 ( V_5 , L_27 ,
V_108 -> type ) ;
return;
}
V_109 = (struct V_16 * ) ( ( unsigned long ) V_108 +
( V_108 -> V_113 << 3 ) ) ;
if ( V_109 -> V_20 . V_21 !=
V_149 ) {
F_13 ( V_5 , L_28
L_29 , V_109 -> V_20 . V_21 ) ;
return;
}
V_168 = (struct V_167 * ) V_108 ;
if ( V_168 -> V_173 != V_27 ) {
F_13 ( V_5 , L_30
L_31 , V_27 ,
V_168 -> V_173 ) ;
return;
}
V_171 = V_168 -> V_174 ;
V_170 -> V_3 = V_3 ;
V_170 -> V_28 = V_28 ;
for ( V_87 = 0 ; V_87 < V_171 ; V_87 ++ ) {
V_170 -> V_52 = V_53 ;
V_170 -> V_175 = ( void * ) ( ( unsigned long ) V_4 ->
V_31 + V_168 -> V_176 [ V_87 ] . V_177 ) ;
V_170 -> V_153 =
V_168 -> V_176 [ V_87 ] . V_178 ;
F_57 ( V_3 , V_170 ) ;
if ( V_170 -> V_52 != V_53 )
V_52 = V_179 ;
}
F_54 ( V_3 , V_28 , V_4 ,
V_168 -> V_180 . V_122 , V_52 ) ;
}
static void F_58 ( struct V_2 * V_181 ,
struct V_107 * V_182 )
{
struct V_1 * V_183 ;
struct V_4 * V_5 ;
struct V_16 * V_184 ;
int V_87 ;
T_1 V_171 , * V_185 ;
V_183 = F_8 ( V_181 ) ;
if ( ! V_183 )
return;
V_5 = V_183 -> V_5 ;
V_184 = (struct V_16 * ) ( ( unsigned long ) V_182 +
( V_182 -> V_113 << 3 ) ) ;
if ( V_184 -> V_20 . V_21 != V_186 )
return;
V_171 = V_184 -> V_23 . V_187 . V_188 . V_171 ;
if ( V_171 != V_189 ) {
F_13 ( V_5 , L_32 , V_171 ) ;
return;
}
V_185 = ( T_1 * ) ( ( unsigned long ) & V_184 -> V_23 . V_187 . V_188 +
V_184 -> V_23 . V_187 . V_188 . V_58 ) ;
for ( V_87 = 0 ; V_87 < V_171 ; V_87 ++ )
V_183 -> V_188 [ V_87 ] = V_185 [ V_87 ] ;
}
void F_59 ( void * V_190 )
{
int V_18 ;
struct V_120 * V_28 = (struct V_120 * ) V_190 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_191 ;
T_3 V_192 ;
struct V_107 * V_193 ;
unsigned char * V_194 ;
int V_195 = V_8 ;
struct V_4 * V_5 ;
if ( V_28 -> V_196 != NULL )
V_3 = V_28 -> V_196 -> V_197 ;
else
V_3 = V_28 -> V_197 ;
V_4 = F_9 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_194 = F_60 ( V_28 ) ;
do {
V_18 = F_61 ( V_28 , V_194 , V_195 ,
& V_191 , & V_192 ) ;
if ( V_18 == 0 ) {
if ( V_191 > 0 ) {
V_193 = (struct V_107 * ) V_194 ;
switch ( V_193 -> type ) {
case V_166 :
F_37 ( V_4 ,
V_3 , V_193 ) ;
break;
case V_172 :
F_56 ( V_4 , V_28 ,
V_3 , V_193 ) ;
break;
case V_29 :
F_58 ( V_3 , V_193 ) ;
break;
default:
F_13 ( V_5 ,
L_33
L_34 ,
V_193 -> type , V_192 ,
V_191 ) ;
break;
}
} else {
break;
}
} else if ( V_18 == - V_198 ) {
if ( V_195 > V_8 )
F_4 ( V_194 ) ;
V_194 = F_62 ( V_191 , V_199 ) ;
if ( V_194 == NULL ) {
F_13 ( V_5 ,
L_35
L_36 , V_191 ) ;
break;
}
V_195 = V_191 ;
}
} while ( 1 );
if ( V_195 > V_8 )
F_4 ( V_194 ) ;
return;
}
int F_63 ( struct V_2 * V_3 , void * V_200 )
{
int V_18 = 0 ;
int V_201 =
( (struct V_202 * ) V_200 ) -> V_201 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_42 ;
V_4 -> V_201 = V_201 ;
V_5 = V_4 -> V_5 ;
F_64 ( & V_4 -> V_49 ) ;
F_65 ( V_3 -> V_28 , V_4 -> V_7 ) ;
V_18 = F_66 ( V_3 -> V_28 , V_201 * V_203 ,
V_201 * V_203 , NULL , 0 ,
F_59 , V_3 -> V_28 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 , L_37 , V_18 ) ;
goto V_43;
}
F_67 ( L_38 ) ;
V_4 -> V_157 [ 0 ] = V_3 -> V_28 ;
V_18 = F_25 ( V_3 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_39 , V_18 ) ;
goto V_204;
}
return V_18 ;
V_204:
F_32 ( V_3 -> V_28 ) ;
V_43:
F_7 ( V_4 ) ;
return V_18 ;
}
