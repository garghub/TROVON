static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
F_4 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = false ;
V_4 -> V_9 = false ;
V_4 -> V_10 = V_3 ;
V_4 -> V_5 = V_5 ;
F_5 ( V_3 , V_4 ) ;
return V_4 ;
}
static struct V_1 * F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_9 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_11;
if ( V_4 -> V_9 &&
F_8 ( & V_4 -> V_12 ) == 0 )
V_4 = NULL ;
V_11:
return V_4 ;
}
static int F_9 ( struct V_1 * V_4 )
{
struct V_13 * V_14 ;
int V_15 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_16 ) {
V_14 = & V_4 -> V_14 ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_17 . V_18 =
V_19 ;
V_14 -> V_20 . V_21 .
V_22 . V_23 = V_24 ;
V_15 = F_10 ( V_4 -> V_10 -> V_25 ,
V_14 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_14 ,
V_26 , 0 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_1
L_2 ) ;
return V_15 ;
}
}
if ( V_4 -> V_27 ) {
V_15 = F_12 ( V_4 -> V_10 -> V_25 ,
V_4 -> V_27 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_3 ) ;
return V_15 ;
}
V_4 -> V_27 = 0 ;
}
if ( V_4 -> V_28 ) {
F_13 ( V_4 -> V_28 ) ;
V_4 -> V_28 = NULL ;
}
if ( V_4 -> V_29 ) {
V_4 -> V_16 = 0 ;
F_14 ( V_4 -> V_29 ) ;
V_4 -> V_29 = NULL ;
}
if ( V_4 -> V_30 ) {
V_14 = & V_4 -> V_14 ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_17 . V_18 =
V_31 ;
V_14 -> V_20 . V_21 . V_22 . V_23 = 0 ;
V_15 = F_10 ( V_4 -> V_10 -> V_25 ,
V_14 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_14 ,
V_26 , 0 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_1
L_4 ) ;
return V_15 ;
}
}
if ( V_4 -> V_32 ) {
V_15 = F_12 ( V_4 -> V_10 -> V_25 ,
V_4 -> V_32 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_5 ) ;
return V_15 ;
}
V_4 -> V_32 = 0 ;
}
if ( V_4 -> V_33 ) {
F_15 ( ( unsigned long ) V_4 -> V_33 ,
F_16 ( V_4 -> V_34 ) ) ;
V_4 -> V_33 = NULL ;
}
F_14 ( V_4 -> V_35 ) ;
return V_15 ;
}
static int F_17 ( struct V_2 * V_3 )
{
int V_15 = 0 ;
int V_36 ;
struct V_1 * V_4 ;
struct V_13 * V_37 ;
struct V_4 * V_5 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_38 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_28 = F_18 ( V_4 -> V_39 ) ;
if ( ! V_4 -> V_28 ) {
F_11 ( V_5 , L_6
L_7 , V_4 -> V_39 ) ;
V_15 = - V_40 ;
goto V_41;
}
V_15 = F_19 ( V_3 -> V_25 , V_4 -> V_28 ,
V_4 -> V_39 ,
& V_4 -> V_27 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_8 ) ;
goto V_41;
}
V_37 = & V_4 -> V_42 ;
memset ( V_37 , 0 , sizeof( struct V_13 ) ) ;
V_37 -> V_17 . V_18 = V_43 ;
V_37 -> V_20 . V_21 . V_44 .
V_45 = V_4 -> V_27 ;
V_37 -> V_20 . V_21 .
V_44 . V_23 = V_24 ;
V_15 = F_10 ( V_3 -> V_25 , V_37 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_37 ,
V_26 ,
V_46 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_9 ) ;
goto V_41;
}
V_36 = F_20 ( & V_4 -> V_47 , 5 * V_48 ) ;
F_21 ( V_36 == 0 ) ;
if ( V_37 -> V_20 . V_21 .
V_49 . V_50 != V_51 ) {
F_11 ( V_5 , L_10
L_11 ,
V_37 -> V_20 . V_21 .
V_49 . V_50 ) ;
V_15 = - V_52 ;
goto V_41;
}
V_4 -> V_16 = V_37 -> V_20 .
V_21 . V_49 . V_53 ;
V_4 -> V_29 = F_22 (
V_37 -> V_20 . V_21 . V_49 . V_54 ,
V_4 -> V_16 *
sizeof( struct V_55 ) ,
V_6 ) ;
if ( V_4 -> V_29 == NULL ) {
V_15 = - V_52 ;
goto V_41;
}
if ( V_4 -> V_16 != 1 ||
V_4 -> V_29 -> V_56 != 0 ) {
V_15 = - V_52 ;
goto V_41;
}
V_4 -> V_33 =
( void * ) F_23 ( V_6 | V_57 ,
F_16 ( V_4 -> V_34 ) ) ;
if ( ! V_4 -> V_33 ) {
F_11 ( V_5 , L_12
L_7 , V_4 -> V_34 ) ;
V_15 = - V_40 ;
goto V_41;
}
V_15 = F_19 ( V_3 -> V_25 , V_4 -> V_33 ,
V_4 -> V_34 ,
& V_4 -> V_32 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_13 ) ;
goto V_41;
}
V_37 = & V_4 -> V_42 ;
memset ( V_37 , 0 , sizeof( struct V_13 ) ) ;
V_37 -> V_17 . V_18 = V_58 ;
V_37 -> V_20 . V_21 . V_44 . V_45 =
V_4 -> V_32 ;
V_37 -> V_20 . V_21 . V_44 . V_23 = 0 ;
V_15 = F_10 ( V_3 -> V_25 , V_37 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_37 ,
V_26 ,
V_46 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_14 ) ;
goto V_41;
}
V_36 = F_20 ( & V_4 -> V_47 , 5 * V_48 ) ;
F_21 ( V_36 == 0 ) ;
if ( V_37 -> V_20 . V_21 .
V_59 . V_50 != V_51 ) {
F_11 ( V_5 , L_15
L_11 ,
V_37 -> V_20 . V_21 .
V_49 . V_50 ) ;
V_15 = - V_52 ;
goto V_41;
}
V_4 -> V_30 = V_37 -> V_20 .
V_21 . V_59 . V_60 ;
V_4 -> V_61 =
V_4 -> V_34 / V_4 -> V_30 ;
F_24 ( & V_3 -> V_3 , L_16 ,
V_4 -> V_30 , V_4 -> V_61 ) ;
V_4 -> V_62 = F_25 ( V_4 -> V_61 ,
V_63 ) ;
V_4 -> V_35 =
F_3 ( V_4 -> V_62 * sizeof( V_64 ) , V_6 ) ;
if ( V_4 -> V_35 == NULL ) {
V_15 = - V_40 ;
goto V_41;
}
goto exit;
V_41:
F_9 ( V_4 ) ;
exit:
return V_15 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_13 * V_37 ,
T_1 V_65 )
{
int V_15 , V_36 ;
memset ( V_37 , 0 , sizeof( struct V_13 ) ) ;
V_37 -> V_17 . V_18 = V_66 ;
V_37 -> V_20 . V_67 . V_68 . V_69 = V_65 ;
V_37 -> V_20 . V_67 . V_68 . V_70 = V_65 ;
V_15 = F_10 ( V_3 -> V_25 , V_37 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_37 ,
V_26 ,
V_46 ) ;
if ( V_15 != 0 )
return V_15 ;
V_36 = F_20 ( & V_4 -> V_47 , 5 * V_48 ) ;
if ( V_36 == 0 )
return - V_71 ;
if ( V_37 -> V_20 . V_67 . V_72 . V_50 !=
V_51 )
return - V_52 ;
if ( V_65 == V_73 )
return 0 ;
memset ( V_37 , 0 , sizeof( struct V_13 ) ) ;
V_37 -> V_17 . V_18 = V_74 ;
V_37 -> V_20 . V_75 . V_76 . V_77 = V_4 -> V_5 -> V_77 ;
V_37 -> V_20 . V_75 . V_76 . V_78 . V_79 = 1 ;
V_15 = F_10 ( V_3 -> V_25 , V_37 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_37 ,
V_26 , 0 ) ;
return V_15 ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_15 ;
struct V_1 * V_4 ;
struct V_13 * V_37 ;
int V_80 ;
struct V_4 * V_5 ;
T_1 V_81 [] = { V_73 , V_82 ,
V_83 , V_84 } ;
int V_85 , V_86 = 4 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_38 ;
V_5 = V_4 -> V_5 ;
V_37 = & V_4 -> V_42 ;
for ( V_85 = V_86 - 1 ; V_85 >= 0 ; V_85 -- )
if ( F_26 ( V_3 , V_4 , V_37 ,
V_81 [ V_85 ] ) == 0 ) {
V_4 -> V_87 = V_81 [ V_85 ] ;
break;
}
if ( V_85 < 0 ) {
V_15 = - V_88 ;
goto V_41;
}
F_28 ( L_17 , V_4 -> V_87 ) ;
memset ( V_37 , 0 , sizeof( struct V_13 ) ) ;
if ( V_4 -> V_87 <= V_83 )
V_80 = 0x00060001 ;
else
V_80 = 0x0006001e ;
V_37 -> V_17 . V_18 = V_89 ;
V_37 -> V_20 . V_21 .
V_90 . V_91 =
( V_80 & 0xFFFF0000 ) >> 16 ;
V_37 -> V_20 . V_21 .
V_90 . V_92 =
V_80 & 0xFFFF ;
V_15 = F_10 ( V_3 -> V_25 , V_37 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_37 ,
V_26 , 0 ) ;
if ( V_15 != 0 )
goto V_41;
if ( V_4 -> V_87 <= V_82 )
V_4 -> V_39 = V_93 ;
else
V_4 -> V_39 = V_94 ;
V_4 -> V_34 = V_95 ;
V_15 = F_17 ( V_3 ) ;
V_41:
return V_15 ;
}
static void F_29 ( struct V_1 * V_4 )
{
F_9 ( V_4 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_96 ;
V_4 = F_2 ( V_3 ) ;
F_29 ( V_4 ) ;
F_31 ( & V_3 -> V_25 -> V_97 , V_96 ) ;
F_5 ( V_3 , NULL ) ;
F_32 ( & V_3 -> V_25 -> V_97 , V_96 ) ;
F_33 ( & V_3 -> V_3 , L_18 ) ;
F_34 ( V_3 -> V_25 ) ;
if ( V_4 -> V_98 )
F_13 ( V_4 -> V_98 ) ;
F_14 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_35 (
struct V_99 * V_100 )
{
T_1 V_101 , V_102 ;
F_36 ( V_100 , & V_101 , & V_102 ) ;
return V_102 * 100 / V_100 -> V_103 ;
}
static inline void F_37 ( struct V_1 * V_4 ,
T_1 V_104 )
{
F_38 ( V_104 , V_4 -> V_35 ) ;
}
static void F_39 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_105 * V_106 )
{
struct V_13 * V_107 ;
struct V_108 * V_109 ;
struct V_4 * V_5 ;
T_1 V_110 ;
V_5 = V_4 -> V_5 ;
V_107 = (struct V_13 * ) ( ( unsigned long ) V_106 +
( V_106 -> V_111 << 3 ) ) ;
if ( ( V_107 -> V_17 . V_18 == V_112 ) ||
( V_107 -> V_17 . V_18 ==
V_113 ) ||
( V_107 -> V_17 . V_18 ==
V_114 ) ||
( V_107 -> V_17 . V_18 ==
V_115 ) ) {
memcpy ( & V_4 -> V_42 , V_107 ,
sizeof( struct V_13 ) ) ;
F_40 ( & V_4 -> V_47 ) ;
} else if ( V_107 -> V_17 . V_18 ==
V_116 ) {
int V_12 ;
T_2 V_117 = 0 ;
struct V_118 * V_25 = V_3 -> V_25 ;
int V_119 ;
V_109 = (struct V_108 * ) ( unsigned long )
V_106 -> V_120 ;
if ( V_109 ) {
V_110 = V_109 -> V_121 ;
if ( V_110 != V_122 )
F_37 ( V_4 , V_110 ) ;
V_117 = V_109 -> V_117 ;
V_25 = V_109 -> V_25 ;
V_109 -> V_123 ( V_109 ->
V_124 ) ;
}
V_12 =
F_41 ( & V_4 -> V_12 ) ;
V_119 = F_41 ( & V_4 ->
V_119 [ V_117 ] ) ;
if ( V_4 -> V_9 && V_12 == 0 )
F_42 ( & V_4 -> V_7 ) ;
if ( F_43 ( F_44 ( V_5 , V_117 ) ) &&
! V_4 -> V_8 &&
( F_35 ( & V_25 -> V_125 ) >
V_126 || V_119 < 1 ) )
F_45 ( F_44 (
V_5 , V_117 ) ) ;
} else {
F_11 ( V_5 , L_19
L_20 , V_107 -> V_17 . V_18 ) ;
}
}
static T_1 F_46 ( struct V_1 * V_4 )
{
unsigned long V_104 ;
T_1 V_127 = V_4 -> V_62 ;
unsigned long * V_128 = ( unsigned long * ) V_4 -> V_35 ;
T_1 V_129 = V_4 -> V_61 ;
int V_130 = V_122 ;
int V_85 ;
int V_131 ;
for ( V_85 = 0 ; V_85 < V_127 ; V_85 ++ ) {
if ( ! ~ ( V_128 [ V_85 ] ) )
continue;
V_104 = F_47 ( V_128 [ V_85 ] ) ;
V_131 = F_48 ( V_104 , & V_128 [ V_85 ] ) ;
if ( V_131 )
continue;
if ( ( V_104 + ( V_85 * V_63 ) ) >= V_129 )
break;
V_130 = ( V_104 + ( V_85 * V_63 ) ) ;
break;
}
return V_130 ;
}
T_1 F_49 ( struct V_1 * V_4 ,
unsigned int V_132 ,
struct V_108 * V_106 )
{
char * V_133 = V_4 -> V_33 ;
char * V_134 = ( V_133 + ( V_132 * V_4 -> V_30 ) ) ;
int V_85 ;
T_1 V_135 = 0 ;
for ( V_85 = 0 ; V_85 < V_106 -> V_136 ; V_85 ++ ) {
char * V_137 = F_50 ( V_106 -> V_138 [ V_85 ] . V_139 << V_140 ) ;
T_1 V_56 = V_106 -> V_138 [ V_85 ] . V_56 ;
T_1 V_141 = V_106 -> V_138 [ V_85 ] . V_141 ;
memcpy ( V_134 , ( V_137 + V_56 ) , V_141 ) ;
V_135 += V_141 ;
V_134 += V_141 ;
}
return V_135 ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_108 * V_106 )
{
struct V_1 * V_4 ;
int V_15 = 0 ;
struct V_13 V_142 ;
struct V_4 * V_5 ;
struct V_118 * V_143 = NULL ;
T_3 V_144 ;
unsigned int V_132 = V_122 ;
T_1 V_135 = 0 ;
struct V_145 * V_146 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return - V_38 ;
V_5 = V_4 -> V_5 ;
V_142 . V_17 . V_18 = V_147 ;
if ( V_106 -> V_148 ) {
V_142 . V_20 . V_21 . V_149 . V_150 = 0 ;
} else {
V_142 . V_20 . V_21 . V_149 . V_150 = 1 ;
}
if ( V_106 -> V_151 < V_4 -> V_30 ) {
V_132 = F_46 ( V_4 ) ;
if ( V_132 != V_122 ) {
V_135 = F_49 ( V_4 ,
V_132 ,
V_106 ) ;
V_146 = (struct V_145 * )
( unsigned long ) V_106 -> V_152 ;
if ( V_146 )
F_52 ( V_146 ) ;
V_106 -> V_136 = 0 ;
}
}
V_106 -> V_121 = V_132 ;
V_142 . V_20 . V_21 . V_149 . V_153 =
V_132 ;
V_142 . V_20 . V_21 . V_149 . V_154 = V_135 ;
if ( V_106 -> V_123 )
V_144 = ( V_64 ) V_106 ;
else
V_144 = 0 ;
V_143 = V_4 -> V_155 [ V_106 -> V_117 ] ;
if ( V_143 == NULL )
V_143 = V_3 -> V_25 ;
V_106 -> V_25 = V_143 ;
if ( V_106 -> V_136 ) {
V_15 = F_53 ( V_143 ,
V_106 -> V_138 ,
V_106 -> V_136 ,
& V_142 ,
sizeof( struct V_13 ) ,
V_144 ) ;
} else {
V_15 = F_10 ( V_143 , & V_142 ,
sizeof( struct V_13 ) ,
V_144 ,
V_26 ,
V_46 ) ;
}
if ( V_15 == 0 ) {
F_54 ( & V_4 -> V_12 ) ;
F_54 ( & V_4 -> V_119 [ V_106 -> V_117 ] ) ;
if ( F_35 ( & V_143 -> V_125 ) <
V_156 ) {
F_55 ( F_44 (
V_5 , V_106 -> V_117 ) ) ;
if ( F_8 ( & V_4 ->
V_119 [ V_106 -> V_117 ] ) < 1 )
F_45 ( F_44 (
V_5 , V_106 -> V_117 ) ) ;
}
} else if ( V_15 == - V_157 ) {
F_55 ( F_44 (
V_5 , V_106 -> V_117 ) ) ;
if ( F_8 ( & V_4 -> V_119 [ V_106 -> V_117 ] ) < 1 ) {
F_45 ( F_44 (
V_5 , V_106 -> V_117 ) ) ;
V_15 = - V_158 ;
}
} else {
F_11 ( V_5 , L_21 ,
V_106 , V_15 ) ;
}
return V_15 ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_118 * V_25 ,
struct V_1 * V_4 ,
T_3 V_159 , T_1 V_50 )
{
struct V_13 V_160 ;
int V_161 = 0 ;
int V_15 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_160 . V_17 . V_18 =
V_116 ;
V_160 . V_20 . V_21 . V_162 . V_50 = V_50 ;
V_163:
V_15 = F_10 ( V_25 , & V_160 ,
sizeof( struct V_13 ) , V_159 ,
V_164 , 0 ) ;
if ( V_15 == 0 ) {
} else if ( V_15 == - V_157 ) {
V_161 ++ ;
F_11 ( V_5 , L_22
L_23 , V_159 , V_161 ) ;
if ( V_161 < 4 ) {
F_57 ( 100 ) ;
goto V_163;
} else {
F_11 ( V_5 , L_24
L_25 ,
V_159 ) ;
}
} else {
F_11 ( V_5 , L_24
L_26 , V_159 ) ;
}
}
static void F_58 ( struct V_1 * V_4 ,
struct V_118 * V_25 ,
struct V_2 * V_3 ,
struct V_105 * V_106 )
{
struct V_165 * V_166 ;
struct V_13 * V_107 ;
struct V_108 V_167 ;
struct V_108 * V_168 = & V_167 ;
T_1 V_50 = V_51 ;
int V_85 ;
int V_169 = 0 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
if ( V_106 -> type != V_170 ) {
F_11 ( V_5 , L_27 ,
V_106 -> type ) ;
return;
}
V_107 = (struct V_13 * ) ( ( unsigned long ) V_106 +
( V_106 -> V_111 << 3 ) ) ;
if ( V_107 -> V_17 . V_18 !=
V_147 ) {
F_11 ( V_5 , L_28
L_29 , V_107 -> V_17 . V_18 ) ;
return;
}
V_166 = (struct V_165 * ) V_106 ;
if ( V_166 -> V_171 != V_24 ) {
F_11 ( V_5 , L_30
L_31 , V_24 ,
V_166 -> V_171 ) ;
return;
}
V_169 = V_166 -> V_172 ;
V_168 -> V_3 = V_3 ;
V_168 -> V_25 = V_25 ;
for ( V_85 = 0 ; V_85 < V_169 ; V_85 ++ ) {
V_168 -> V_50 = V_51 ;
V_168 -> V_173 = ( void * ) ( ( unsigned long ) V_4 ->
V_28 + V_166 -> V_174 [ V_85 ] . V_175 ) ;
V_168 -> V_151 =
V_166 -> V_174 [ V_85 ] . V_176 ;
F_59 ( V_3 , V_168 ) ;
if ( V_168 -> V_50 != V_51 )
V_50 = V_177 ;
}
F_56 ( V_3 , V_25 , V_4 ,
V_166 -> V_178 . V_120 , V_50 ) ;
}
static void F_60 ( struct V_2 * V_179 ,
struct V_105 * V_180 )
{
struct V_1 * V_181 ;
struct V_4 * V_5 ;
struct V_13 * V_182 ;
int V_85 ;
T_1 V_169 , * V_183 ;
V_181 = F_6 ( V_179 ) ;
if ( ! V_181 )
return;
V_5 = V_181 -> V_5 ;
V_182 = (struct V_13 * ) ( ( unsigned long ) V_180 +
( V_180 -> V_111 << 3 ) ) ;
if ( V_182 -> V_17 . V_18 != V_184 )
return;
V_169 = V_182 -> V_20 . V_185 . V_186 . V_169 ;
if ( V_169 != V_187 ) {
F_11 ( V_5 , L_32 , V_169 ) ;
return;
}
V_183 = ( T_1 * ) ( ( unsigned long ) & V_182 -> V_20 . V_185 . V_186 +
V_182 -> V_20 . V_185 . V_186 . V_56 ) ;
for ( V_85 = 0 ; V_85 < V_169 ; V_85 ++ )
V_181 -> V_186 [ V_85 ] = V_183 [ V_85 ] ;
}
void F_61 ( void * V_188 )
{
int V_15 ;
struct V_118 * V_25 = (struct V_118 * ) V_188 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_189 ;
T_3 V_190 ;
struct V_105 * V_191 ;
unsigned char * V_192 ;
int V_193 = V_194 ;
struct V_4 * V_5 ;
if ( V_25 -> V_195 != NULL )
V_3 = V_25 -> V_195 -> V_196 ;
else
V_3 = V_25 -> V_196 ;
V_4 = F_7 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_192 = F_62 ( V_25 ) ;
do {
V_15 = F_63 ( V_25 , V_192 , V_193 ,
& V_189 , & V_190 ) ;
if ( V_15 == 0 ) {
if ( V_189 > 0 ) {
V_191 = (struct V_105 * ) V_192 ;
switch ( V_191 -> type ) {
case V_164 :
F_39 ( V_4 ,
V_3 , V_191 ) ;
break;
case V_170 :
F_58 ( V_4 , V_25 ,
V_3 , V_191 ) ;
break;
case V_26 :
F_60 ( V_3 , V_191 ) ;
break;
default:
F_11 ( V_5 ,
L_33
L_34 ,
V_191 -> type , V_190 ,
V_189 ) ;
break;
}
} else {
break;
}
} else if ( V_15 == - V_197 ) {
if ( V_193 > V_194 )
F_14 ( V_192 ) ;
V_192 = F_64 ( V_189 , V_198 ) ;
if ( V_192 == NULL ) {
F_11 ( V_5 ,
L_35
L_36 , V_189 ) ;
break;
}
V_193 = V_189 ;
}
} while ( 1 );
if ( V_193 > V_194 )
F_14 ( V_192 ) ;
return;
}
int F_65 ( struct V_2 * V_3 , void * V_199 )
{
int V_15 = 0 ;
int V_200 =
( (struct V_201 * ) V_199 ) -> V_200 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_15 = - V_40 ;
goto V_41;
}
V_4 -> V_200 = V_200 ;
V_5 = V_4 -> V_5 ;
F_66 ( & V_4 -> V_47 ) ;
F_67 ( V_3 -> V_25 , V_4 -> V_202 ) ;
V_15 = F_68 ( V_3 -> V_25 , V_200 * V_203 ,
V_200 * V_203 , NULL , 0 ,
F_61 , V_3 -> V_25 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 , L_37 , V_15 ) ;
goto V_41;
}
F_69 ( L_38 ) ;
V_4 -> V_155 [ 0 ] = V_3 -> V_25 ;
V_15 = F_27 ( V_3 ) ;
if ( V_15 != 0 ) {
F_11 ( V_5 ,
L_39 , V_15 ) ;
goto V_204;
}
return V_15 ;
V_204:
F_34 ( V_3 -> V_25 ) ;
V_41:
if ( V_4 )
F_14 ( V_4 ) ;
return V_15 ;
}
