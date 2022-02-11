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
V_17 -> V_23 . V_24 . V_35 . V_26 =
V_36 ;
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
if ( V_4 -> V_37 ) {
V_18 = F_14 ( V_4 -> V_12 -> V_28 ,
V_4 -> V_37 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_5 ) ;
return V_18 ;
}
V_4 -> V_37 = 0 ;
}
if ( V_4 -> V_38 ) {
F_15 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
}
F_4 ( V_4 -> V_39 ) ;
return V_18 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_18 = 0 ;
unsigned long V_40 ;
struct V_1 * V_4 ;
struct V_16 * V_41 ;
struct V_4 * V_5 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_42 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_31 = F_17 ( V_4 -> V_43 ) ;
if ( ! V_4 -> V_31 ) {
F_13 ( V_5 , L_6
L_7 , V_4 -> V_43 ) ;
V_18 = - V_44 ;
goto V_45;
}
V_18 = F_18 ( V_3 -> V_28 , V_4 -> V_31 ,
V_4 -> V_43 ,
& V_4 -> V_30 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_8 ) ;
goto V_45;
}
V_41 = & V_4 -> V_46 ;
memset ( V_41 , 0 , sizeof( struct V_16 ) ) ;
V_41 -> V_20 . V_21 = V_47 ;
V_41 -> V_23 . V_24 . V_48 .
V_49 = V_4 -> V_30 ;
V_41 -> V_23 . V_24 .
V_48 . V_26 = V_27 ;
V_18 = F_12 ( V_3 -> V_28 , V_41 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_41 ,
V_29 ,
V_50 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_9 ) ;
goto V_45;
}
V_40 = F_19 ( & V_4 -> V_51 , 5 * V_52 ) ;
F_20 ( V_40 == 0 ) ;
if ( V_41 -> V_23 . V_24 .
V_53 . V_54 != V_55 ) {
F_13 ( V_5 , L_10
L_11 ,
V_41 -> V_23 . V_24 .
V_53 . V_54 ) ;
V_18 = - V_56 ;
goto V_45;
}
V_4 -> V_19 = V_41 -> V_23 .
V_24 . V_53 . V_57 ;
V_4 -> V_32 = F_21 (
V_41 -> V_23 . V_24 . V_53 . V_58 ,
V_4 -> V_19 *
sizeof( struct V_59 ) ,
V_6 ) ;
if ( V_4 -> V_32 == NULL ) {
V_18 = - V_56 ;
goto V_45;
}
if ( V_4 -> V_19 != 1 ||
V_4 -> V_32 -> V_60 != 0 ) {
V_18 = - V_56 ;
goto V_45;
}
V_4 -> V_38 = F_17 ( V_4 -> V_61 ) ;
if ( ! V_4 -> V_38 ) {
F_13 ( V_5 , L_12
L_7 , V_4 -> V_61 ) ;
V_18 = - V_44 ;
goto V_45;
}
V_18 = F_18 ( V_3 -> V_28 , V_4 -> V_38 ,
V_4 -> V_61 ,
& V_4 -> V_37 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_13 ) ;
goto V_45;
}
V_41 = & V_4 -> V_46 ;
memset ( V_41 , 0 , sizeof( struct V_16 ) ) ;
V_41 -> V_20 . V_21 = V_62 ;
V_41 -> V_23 . V_24 . V_63 . V_49 =
V_4 -> V_37 ;
V_41 -> V_23 . V_24 . V_63 . V_26 = V_36 ;
V_18 = F_12 ( V_3 -> V_28 , V_41 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_41 ,
V_29 ,
V_50 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_14 ) ;
goto V_45;
}
V_40 = F_19 ( & V_4 -> V_51 , 5 * V_52 ) ;
F_20 ( V_40 == 0 ) ;
if ( V_41 -> V_23 . V_24 .
V_64 . V_54 != V_55 ) {
F_13 ( V_5 , L_15
L_11 ,
V_41 -> V_23 . V_24 .
V_64 . V_54 ) ;
V_18 = - V_56 ;
goto V_45;
}
V_4 -> V_33 = V_41 -> V_23 .
V_24 . V_64 . V_65 ;
V_4 -> V_66 =
V_4 -> V_61 / V_4 -> V_33 ;
F_22 ( & V_3 -> V_3 , L_16 ,
V_4 -> V_33 , V_4 -> V_66 ) ;
V_4 -> V_67 = F_23 ( V_4 -> V_66 ,
V_68 ) ;
V_4 -> V_39 =
F_3 ( V_4 -> V_67 * sizeof( V_69 ) , V_6 ) ;
if ( V_4 -> V_39 == NULL ) {
V_18 = - V_44 ;
goto V_45;
}
goto exit;
V_45:
F_11 ( V_4 ) ;
exit:
return V_18 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_16 * V_41 ,
T_1 V_70 )
{
int V_18 ;
unsigned long V_40 ;
memset ( V_41 , 0 , sizeof( struct V_16 ) ) ;
V_41 -> V_20 . V_21 = V_71 ;
V_41 -> V_23 . V_72 . V_73 . V_74 = V_70 ;
V_41 -> V_23 . V_72 . V_73 . V_75 = V_70 ;
V_18 = F_12 ( V_3 -> V_28 , V_41 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_41 ,
V_29 ,
V_50 ) ;
if ( V_18 != 0 )
return V_18 ;
V_40 = F_19 ( & V_4 -> V_51 , 5 * V_52 ) ;
if ( V_40 == 0 )
return - V_76 ;
if ( V_41 -> V_23 . V_72 . V_77 . V_54 !=
V_55 )
return - V_56 ;
if ( V_70 == V_78 )
return 0 ;
memset ( V_41 , 0 , sizeof( struct V_16 ) ) ;
V_41 -> V_20 . V_21 = V_79 ;
V_41 -> V_23 . V_80 . V_81 . V_82 = V_4 -> V_5 -> V_82 +
V_83 ;
V_41 -> V_23 . V_80 . V_81 . V_84 . V_85 = 1 ;
V_18 = F_12 ( V_3 -> V_28 , V_41 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_41 ,
V_29 , 0 ) ;
return V_18 ;
}
static int F_25 ( struct V_2 * V_3 )
{
int V_18 ;
struct V_1 * V_4 ;
struct V_16 * V_41 ;
int V_86 ;
struct V_4 * V_5 ;
T_1 V_87 [] = { V_78 , V_88 ,
V_89 , V_90 } ;
int V_91 , V_92 = 4 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_42 ;
V_5 = V_4 -> V_5 ;
V_41 = & V_4 -> V_46 ;
for ( V_91 = V_92 - 1 ; V_91 >= 0 ; V_91 -- )
if ( F_24 ( V_3 , V_4 , V_41 ,
V_87 [ V_91 ] ) == 0 ) {
V_4 -> V_93 = V_87 [ V_91 ] ;
break;
}
if ( V_91 < 0 ) {
V_18 = - V_94 ;
goto V_45;
}
F_26 ( L_17 , V_4 -> V_93 ) ;
memset ( V_41 , 0 , sizeof( struct V_16 ) ) ;
if ( V_4 -> V_93 <= V_89 )
V_86 = 0x00060001 ;
else
V_86 = 0x0006001e ;
V_41 -> V_20 . V_21 = V_95 ;
V_41 -> V_23 . V_24 .
V_96 . V_97 =
( V_86 & 0xFFFF0000 ) >> 16 ;
V_41 -> V_23 . V_24 .
V_96 . V_98 =
V_86 & 0xFFFF ;
V_18 = F_12 ( V_3 -> V_28 , V_41 ,
sizeof( struct V_16 ) ,
( unsigned long ) V_41 ,
V_29 , 0 ) ;
if ( V_18 != 0 )
goto V_45;
if ( V_4 -> V_93 <= V_88 )
V_4 -> V_43 = V_99 ;
else
V_4 -> V_43 = V_100 ;
V_4 -> V_61 = V_101 ;
V_18 = F_16 ( V_3 ) ;
V_45:
return V_18 ;
}
static void F_27 ( struct V_1 * V_4 )
{
F_11 ( V_4 ) ;
}
int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_102 ;
V_4 = F_2 ( V_3 ) ;
F_27 ( V_4 ) ;
F_29 ( & V_3 -> V_28 -> V_103 , V_102 ) ;
F_6 ( V_3 , NULL ) ;
F_30 ( & V_3 -> V_28 -> V_103 , V_102 ) ;
F_31 ( & V_3 -> V_3 , L_18 ) ;
F_32 ( V_3 -> V_28 ) ;
F_15 ( V_4 -> V_104 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_33 (
struct V_105 * V_106 )
{
T_1 V_107 , V_108 ;
F_34 ( V_106 , & V_107 , & V_108 ) ;
return V_108 * 100 / V_106 -> V_109 ;
}
static inline void F_35 ( struct V_1 * V_4 ,
T_1 V_110 )
{
F_36 ( V_110 , V_4 -> V_39 ) ;
}
static void F_37 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_111 * V_112 )
{
struct V_16 * V_113 ;
struct V_114 * V_115 ;
struct V_4 * V_5 ;
T_1 V_116 ;
V_5 = V_4 -> V_5 ;
V_113 = (struct V_16 * ) ( ( unsigned long ) V_112 +
( V_112 -> V_117 << 3 ) ) ;
if ( ( V_113 -> V_20 . V_21 == V_118 ) ||
( V_113 -> V_20 . V_21 ==
V_119 ) ||
( V_113 -> V_20 . V_21 ==
V_120 ) ||
( V_113 -> V_20 . V_21 ==
V_121 ) ) {
memcpy ( & V_4 -> V_46 , V_113 ,
sizeof( struct V_16 ) ) ;
F_38 ( & V_4 -> V_51 ) ;
} else if ( V_113 -> V_20 . V_21 ==
V_122 ) {
int V_15 ;
T_2 V_123 = 0 ;
struct V_124 * V_28 = V_3 -> V_28 ;
int V_125 ;
V_115 = (struct V_114 * ) ( unsigned long )
V_112 -> V_126 ;
if ( V_115 ) {
V_116 = V_115 -> V_127 ;
if ( V_116 != V_128 )
F_35 ( V_4 , V_116 ) ;
V_123 = V_115 -> V_123 ;
V_28 = V_115 -> V_28 ;
V_115 -> V_129 ( V_115 ->
V_130 ) ;
}
V_15 =
F_39 ( & V_4 -> V_15 ) ;
V_125 = F_39 ( & V_4 ->
V_125 [ V_123 ] ) ;
if ( V_4 -> V_11 && V_15 == 0 )
F_40 ( & V_4 -> V_9 ) ;
if ( F_41 ( F_42 ( V_5 , V_123 ) ) &&
! V_4 -> V_10 &&
( F_33 ( & V_28 -> V_131 ) >
V_132 || V_125 < 1 ) )
F_43 ( F_42 (
V_5 , V_123 ) ) ;
} else {
F_13 ( V_5 , L_19
L_20 , V_113 -> V_20 . V_21 ) ;
}
}
static T_1 F_44 ( struct V_1 * V_4 )
{
unsigned long V_110 ;
T_1 V_133 = V_4 -> V_67 ;
unsigned long * V_134 = ( unsigned long * ) V_4 -> V_39 ;
T_1 V_135 = V_4 -> V_66 ;
int V_136 = V_128 ;
int V_91 ;
int V_137 ;
for ( V_91 = 0 ; V_91 < V_133 ; V_91 ++ ) {
if ( ! ~ ( V_134 [ V_91 ] ) )
continue;
V_110 = F_45 ( V_134 [ V_91 ] ) ;
V_137 = F_46 ( V_110 , & V_134 [ V_91 ] ) ;
if ( V_137 )
continue;
if ( ( V_110 + ( V_91 * V_68 ) ) >= V_135 )
break;
V_136 = ( V_110 + ( V_91 * V_68 ) ) ;
break;
}
return V_136 ;
}
static T_1 F_47 ( struct V_1 * V_4 ,
unsigned int V_138 ,
struct V_114 * V_112 )
{
char * V_139 = V_4 -> V_38 ;
char * V_140 = ( V_139 + ( V_138 * V_4 -> V_33 ) ) ;
int V_91 ;
T_1 V_141 = 0 ;
for ( V_91 = 0 ; V_91 < V_112 -> V_142 ; V_91 ++ ) {
char * V_143 = F_48 ( V_112 -> V_144 [ V_91 ] . V_145 << V_146 ) ;
T_1 V_60 = V_112 -> V_144 [ V_91 ] . V_60 ;
T_1 V_147 = V_112 -> V_144 [ V_91 ] . V_147 ;
memcpy ( V_140 , ( V_143 + V_60 ) , V_147 ) ;
V_141 += V_147 ;
V_140 += V_147 ;
}
return V_141 ;
}
int F_49 ( struct V_2 * V_3 ,
struct V_114 * V_112 )
{
struct V_1 * V_4 ;
int V_18 = 0 ;
struct V_16 V_148 ;
struct V_4 * V_5 ;
struct V_124 * V_149 = NULL ;
T_3 V_150 ;
unsigned int V_138 = V_128 ;
T_1 V_141 = 0 ;
struct V_151 * V_152 = NULL ;
T_2 V_123 = V_112 -> V_123 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_42 ;
V_5 = V_4 -> V_5 ;
V_148 . V_20 . V_21 = V_153 ;
if ( V_112 -> V_154 ) {
V_148 . V_23 . V_24 . V_155 . V_156 = 0 ;
} else {
V_148 . V_23 . V_24 . V_155 . V_156 = 1 ;
}
if ( V_112 -> V_157 < V_4 -> V_33 ) {
V_138 = F_44 ( V_4 ) ;
if ( V_138 != V_128 ) {
V_141 = F_47 ( V_4 ,
V_138 ,
V_112 ) ;
V_152 = (struct V_151 * )
( unsigned long ) V_112 -> V_158 ;
V_112 -> V_142 = 0 ;
}
}
V_112 -> V_127 = V_138 ;
V_148 . V_23 . V_24 . V_155 . V_159 =
V_138 ;
V_148 . V_23 . V_24 . V_155 . V_160 = V_141 ;
if ( V_112 -> V_129 )
V_150 = ( V_69 ) V_112 ;
else
V_150 = 0 ;
V_149 = V_4 -> V_161 [ V_112 -> V_123 ] ;
if ( V_149 == NULL )
V_149 = V_3 -> V_28 ;
V_112 -> V_28 = V_149 ;
if ( V_149 -> V_162 )
return - V_42 ;
if ( V_112 -> V_142 ) {
V_18 = F_50 ( V_149 ,
V_112 -> V_144 ,
V_112 -> V_142 ,
& V_148 ,
sizeof( struct V_16 ) ,
V_150 ) ;
} else {
V_18 = F_12 ( V_149 , & V_148 ,
sizeof( struct V_16 ) ,
V_150 ,
V_29 ,
V_50 ) ;
}
if ( V_18 == 0 ) {
F_51 ( & V_4 -> V_15 ) ;
F_51 ( & V_4 -> V_125 [ V_123 ] ) ;
if ( F_33 ( & V_149 -> V_131 ) <
V_163 ) {
F_52 ( F_42 (
V_5 , V_123 ) ) ;
if ( F_10 ( & V_4 ->
V_125 [ V_123 ] ) < 1 )
F_43 ( F_42 (
V_5 , V_123 ) ) ;
}
} else if ( V_18 == - V_164 ) {
F_52 ( F_42 (
V_5 , V_123 ) ) ;
if ( F_10 ( & V_4 -> V_125 [ V_123 ] ) < 1 ) {
F_43 ( F_42 (
V_5 , V_123 ) ) ;
V_18 = - V_165 ;
}
} else {
F_13 ( V_5 , L_21 ,
V_112 , V_18 ) ;
}
if ( V_18 != 0 ) {
if ( V_138 != V_128 )
F_35 ( V_4 , V_138 ) ;
} else if ( V_152 ) {
F_53 ( V_152 ) ;
}
return V_18 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_124 * V_28 ,
struct V_1 * V_4 ,
T_3 V_166 , T_1 V_54 )
{
struct V_16 V_167 ;
int V_168 = 0 ;
int V_18 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_167 . V_20 . V_21 =
V_122 ;
V_167 . V_23 . V_24 . V_169 . V_54 = V_54 ;
V_170:
V_18 = F_12 ( V_28 , & V_167 ,
sizeof( struct V_16 ) , V_166 ,
V_171 , 0 ) ;
if ( V_18 == 0 ) {
} else if ( V_18 == - V_164 ) {
V_168 ++ ;
F_13 ( V_5 , L_22
L_23 , V_166 , V_168 ) ;
if ( V_168 < 4 ) {
F_55 ( 100 ) ;
goto V_170;
} else {
F_13 ( V_5 , L_24
L_25 ,
V_166 ) ;
}
} else {
F_13 ( V_5 , L_24
L_26 , V_166 ) ;
}
}
static void F_56 ( struct V_1 * V_4 ,
struct V_124 * V_28 ,
struct V_2 * V_3 ,
struct V_111 * V_112 )
{
struct V_172 * V_173 ;
struct V_16 * V_113 ;
struct V_114 V_174 ;
struct V_114 * V_175 = & V_174 ;
T_1 V_54 = V_55 ;
int V_91 ;
int V_176 = 0 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
if ( V_112 -> type != V_177 ) {
F_13 ( V_5 , L_27 ,
V_112 -> type ) ;
return;
}
V_113 = (struct V_16 * ) ( ( unsigned long ) V_112 +
( V_112 -> V_117 << 3 ) ) ;
if ( V_113 -> V_20 . V_21 !=
V_153 ) {
F_13 ( V_5 , L_28
L_29 , V_113 -> V_20 . V_21 ) ;
return;
}
V_173 = (struct V_172 * ) V_112 ;
if ( V_173 -> V_178 != V_27 ) {
F_13 ( V_5 , L_30
L_31 , V_27 ,
V_173 -> V_178 ) ;
return;
}
V_176 = V_173 -> V_179 ;
V_175 -> V_3 = V_3 ;
V_175 -> V_28 = V_28 ;
for ( V_91 = 0 ; V_91 < V_176 ; V_91 ++ ) {
V_175 -> V_54 = V_55 ;
V_175 -> V_180 = ( void * ) ( ( unsigned long ) V_4 ->
V_31 + V_173 -> V_181 [ V_91 ] . V_182 ) ;
V_175 -> V_157 =
V_173 -> V_181 [ V_91 ] . V_183 ;
F_57 ( V_3 , V_175 ) ;
if ( V_175 -> V_54 != V_55 )
V_54 = V_184 ;
}
F_54 ( V_3 , V_28 , V_4 ,
V_173 -> V_185 . V_126 , V_54 ) ;
}
static void F_58 ( struct V_2 * V_186 ,
struct V_111 * V_187 )
{
struct V_1 * V_188 ;
struct V_4 * V_5 ;
struct V_16 * V_189 ;
int V_91 ;
T_1 V_176 , * V_190 ;
V_188 = F_8 ( V_186 ) ;
if ( ! V_188 )
return;
V_5 = V_188 -> V_5 ;
V_189 = (struct V_16 * ) ( ( unsigned long ) V_187 +
( V_187 -> V_117 << 3 ) ) ;
if ( V_189 -> V_20 . V_21 != V_191 )
return;
V_176 = V_189 -> V_23 . V_192 . V_193 . V_176 ;
if ( V_176 != V_194 ) {
F_13 ( V_5 , L_32 , V_176 ) ;
return;
}
V_190 = ( T_1 * ) ( ( unsigned long ) & V_189 -> V_23 . V_192 . V_193 +
V_189 -> V_23 . V_192 . V_193 . V_60 ) ;
for ( V_91 = 0 ; V_91 < V_176 ; V_91 ++ )
V_188 -> V_193 [ V_91 ] = V_190 [ V_91 ] ;
}
void F_59 ( void * V_195 )
{
int V_18 ;
struct V_124 * V_28 = (struct V_124 * ) V_195 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_196 ;
T_3 V_197 ;
struct V_111 * V_198 ;
unsigned char * V_199 ;
int V_200 = V_8 ;
struct V_4 * V_5 ;
if ( V_28 -> V_201 != NULL )
V_3 = V_28 -> V_201 -> V_202 ;
else
V_3 = V_28 -> V_202 ;
V_4 = F_9 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_199 = F_60 ( V_28 ) ;
do {
V_18 = F_61 ( V_28 , V_199 , V_200 ,
& V_196 , & V_197 ) ;
if ( V_18 == 0 ) {
if ( V_196 > 0 ) {
V_198 = (struct V_111 * ) V_199 ;
switch ( V_198 -> type ) {
case V_171 :
F_37 ( V_4 ,
V_3 , V_198 ) ;
break;
case V_177 :
F_56 ( V_4 , V_28 ,
V_3 , V_198 ) ;
break;
case V_29 :
F_58 ( V_3 , V_198 ) ;
break;
default:
F_13 ( V_5 ,
L_33
L_34 ,
V_198 -> type , V_197 ,
V_196 ) ;
break;
}
} else {
break;
}
} else if ( V_18 == - V_203 ) {
if ( V_200 > V_8 )
F_4 ( V_199 ) ;
V_199 = F_62 ( V_196 , V_204 ) ;
if ( V_199 == NULL ) {
F_13 ( V_5 ,
L_35
L_36 , V_196 ) ;
break;
}
V_200 = V_196 ;
}
} while ( 1 );
if ( V_200 > V_8 )
F_4 ( V_199 ) ;
return;
}
int F_63 ( struct V_2 * V_3 , void * V_205 )
{
int V_18 = 0 ;
int V_206 =
( (struct V_207 * ) V_205 ) -> V_206 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_44 ;
V_4 -> V_206 = V_206 ;
V_5 = V_4 -> V_5 ;
F_64 ( & V_4 -> V_51 ) ;
F_65 ( V_3 -> V_28 , V_4 -> V_7 ) ;
V_18 = F_66 ( V_3 -> V_28 , V_206 * V_208 ,
V_206 * V_208 , NULL , 0 ,
F_59 , V_3 -> V_28 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 , L_37 , V_18 ) ;
goto V_45;
}
F_67 ( L_38 ) ;
V_4 -> V_161 [ 0 ] = V_3 -> V_28 ;
V_18 = F_25 ( V_3 ) ;
if ( V_18 != 0 ) {
F_13 ( V_5 ,
L_39 , V_18 ) ;
goto V_209;
}
return V_18 ;
V_209:
F_32 ( V_3 -> V_28 ) ;
V_45:
F_7 ( V_4 ) ;
return V_18 ;
}
