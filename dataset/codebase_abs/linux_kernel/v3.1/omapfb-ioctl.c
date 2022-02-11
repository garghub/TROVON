static T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_2 -> V_4 -> V_3 )
return 0 ;
return V_5 | V_2 -> V_4 -> V_3 ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 ,
T_1 V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( V_7 & V_5 )
V_7 &= V_10 ;
else
V_7 = V_2 -> V_3 ;
if ( V_7 >= V_9 -> V_11 )
return NULL ;
return & V_9 -> V_12 [ V_7 ] ;
}
static int F_3 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_17 * V_18 ;
struct V_19 V_20 ;
struct V_6 * V_21 , * V_22 ;
int V_23 = 0 ;
F_5 ( L_1 ) ;
if ( V_2 -> V_24 != 1 ) {
V_23 = - V_25 ;
goto V_26;
}
V_18 = V_2 -> V_27 [ 0 ] ;
V_21 = V_2 -> V_4 ;
V_22 = F_2 ( V_2 , V_16 -> V_7 ) ;
if ( ! V_22 ) {
V_23 = - V_25 ;
goto V_26;
}
if ( V_21 -> V_3 < V_22 -> V_3 ) {
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
} else if ( V_22 -> V_3 < V_21 -> V_3 ) {
F_6 ( V_22 ) ;
F_6 ( V_21 ) ;
} else
F_6 ( V_21 ) ;
if ( V_16 -> V_28 && ! V_22 -> V_29 ) {
V_23 = - V_25 ;
goto V_30;
}
V_18 -> V_31 ( V_18 , & V_20 ) ;
if ( V_21 != V_22 ) {
V_2 -> V_4 = V_22 ;
F_7 ( V_14 ) ;
}
if ( V_16 -> V_28 ) {
struct V_19 V_32 ;
V_23 = F_8 ( V_14 , V_18 , V_16 -> V_33 , V_16 -> V_34 ,
V_16 -> V_35 , V_16 -> V_36 ) ;
if ( V_23 )
goto V_37;
V_18 -> V_31 ( V_18 , & V_32 ) ;
if ( ! V_32 . V_28 ) {
V_32 . V_28 = V_16 -> V_28 ;
V_23 = V_18 -> V_38 ( V_18 , & V_32 ) ;
if ( V_23 )
goto V_37;
}
} else {
struct V_19 V_32 ;
V_18 -> V_31 ( V_18 , & V_32 ) ;
V_32 . V_28 = V_16 -> V_28 ;
V_32 . V_33 = V_16 -> V_33 ;
V_32 . V_34 = V_16 -> V_34 ;
V_32 . V_35 = V_16 -> V_35 ;
V_32 . V_36 = V_16 -> V_36 ;
V_23 = V_18 -> V_38 ( V_18 , & V_32 ) ;
if ( V_23 )
goto V_37;
}
if ( V_18 -> V_39 )
V_18 -> V_39 -> V_40 ( V_18 -> V_39 ) ;
if ( V_21 -> V_3 > V_22 -> V_3 ) {
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
} else if ( V_22 -> V_3 > V_21 -> V_3 ) {
F_9 ( V_22 ) ;
F_9 ( V_21 ) ;
} else
F_9 ( V_21 ) ;
return 0 ;
V_37:
if ( V_21 != V_22 ) {
V_2 -> V_4 = V_21 ;
F_7 ( V_14 ) ;
}
V_18 -> V_38 ( V_18 , & V_20 ) ;
V_30:
if ( V_21 -> V_3 > V_22 -> V_3 ) {
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
} else if ( V_22 -> V_3 > V_21 -> V_3 ) {
F_9 ( V_22 ) ;
F_9 ( V_21 ) ;
} else
F_9 ( V_21 ) ;
V_26:
F_10 ( V_9 -> V_41 , L_2 ) ;
return V_23 ;
}
static int F_11 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
if ( V_2 -> V_24 != 1 ) {
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
} else {
struct V_17 * V_18 ;
struct V_19 * V_42 ;
V_18 = V_2 -> V_27 [ 0 ] ;
V_42 = & V_18 -> V_32 ;
V_16 -> V_33 = V_42 -> V_33 ;
V_16 -> V_34 = V_42 -> V_34 ;
V_16 -> V_28 = V_42 -> V_28 ;
V_16 -> V_43 = 0 ;
V_16 -> V_44 = 0 ;
V_16 -> V_7 = F_1 ( V_2 ) ;
V_16 -> V_35 = V_42 -> V_35 ;
V_16 -> V_36 = V_42 -> V_36 ;
}
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 * V_47 ;
int V_23 = 0 , V_48 ;
T_2 V_29 ;
if ( V_46 -> type > V_49 )
return - V_25 ;
V_29 = F_13 ( V_46 -> V_29 ) ;
V_47 = V_2 -> V_4 ;
F_14 ( & V_47 -> V_50 , V_47 -> V_3 ) ;
F_15 ( & V_47 -> V_51 ) ;
if ( F_16 ( & V_47 -> V_52 ) ) {
V_23 = - V_53 ;
goto V_26;
}
for ( V_48 = 0 ; V_48 < V_9 -> V_11 ; V_48 ++ ) {
struct V_1 * V_54 = F_4 ( V_9 -> V_55 [ V_48 ] ) ;
int V_56 ;
if ( V_54 -> V_4 != V_47 )
continue;
for ( V_56 = 0 ; V_56 < V_54 -> V_24 ; V_56 ++ ) {
if ( V_54 -> V_27 [ V_56 ] -> V_32 . V_28 ) {
V_23 = - V_53 ;
goto V_26;
}
}
}
if ( V_47 -> V_29 != V_29 || V_47 -> type != V_46 -> type ) {
V_23 = F_17 ( V_14 , V_29 , V_46 -> type ) ;
if ( V_23 ) {
F_10 ( V_9 -> V_41 , L_3 ) ;
goto V_26;
}
}
V_26:
F_18 ( & V_47 -> V_51 ) ;
F_19 ( & V_47 -> V_50 ) ;
return V_23 ;
}
static int F_20 ( struct V_13 * V_14 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_6 * V_47 ;
V_47 = F_6 ( V_2 -> V_4 ) ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_29 = V_47 -> V_29 ;
V_46 -> type = V_47 -> type ;
F_9 ( V_47 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 ,
T_3 V_57 , T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
struct V_61 * V_62 = F_22 ( V_14 ) ;
T_4 V_63 , V_64 ;
if ( ! V_62 )
return 0 ;
if ( V_59 == 0 || V_60 == 0 )
return 0 ;
V_62 -> V_65 -> V_66 ( V_62 , & V_63 , & V_64 ) ;
if ( V_57 + V_59 > V_63 || V_58 + V_60 > V_64 )
return - V_25 ;
return V_62 -> V_65 -> V_67 ( V_62 , V_57 , V_58 , V_59 , V_60 ) ;
}
int F_23 ( struct V_13 * V_14 ,
T_3 V_57 , T_3 V_58 , T_3 V_59 , T_3 V_60 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_23 ;
if ( ! F_24 ( V_14 ) )
return - V_68 ;
F_25 ( V_9 ) ;
V_23 = F_21 ( V_14 , V_57 , V_58 , V_59 , V_60 ) ;
F_26 ( V_9 ) ;
F_27 ( V_14 ) ;
return V_23 ;
}
int F_28 ( struct V_13 * V_14 ,
enum V_69 V_70 )
{
struct V_61 * V_62 = F_22 ( V_14 ) ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_71 * V_72 ;
int V_23 ;
if ( ! V_62 )
return - V_25 ;
if ( V_70 != V_73 && V_70 != V_74 )
return - V_25 ;
F_25 ( V_9 ) ;
V_72 = F_29 ( V_9 , V_62 ) ;
if ( V_72 -> V_75 == V_70 ) {
F_26 ( V_9 ) ;
return 0 ;
}
V_23 = 0 ;
if ( V_62 -> V_76 & V_77 ) {
if ( V_70 == V_73 )
F_30 ( V_9 , V_62 ) ;
else
F_31 ( V_9 , V_62 ) ;
V_72 -> V_75 = V_70 ;
} else {
if ( V_70 == V_74 )
V_23 = - V_25 ;
}
F_26 ( V_9 ) ;
return V_23 ;
}
int F_32 ( struct V_13 * V_14 ,
enum V_69 * V_70 )
{
struct V_61 * V_62 = F_22 ( V_14 ) ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_71 * V_72 ;
if ( ! V_62 )
return - V_25 ;
F_25 ( V_9 ) ;
V_72 = F_29 ( V_9 , V_62 ) ;
* V_70 = V_72 -> V_75 ;
F_26 ( V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_82 V_32 ;
enum V_83 V_84 ;
int V_23 ;
V_79 -> V_85 ( V_79 , & V_32 ) ;
if ( V_81 -> V_86 == V_87 ) {
V_32 . V_88 = false ;
V_89 [ V_79 -> V_3 ] = * V_81 ;
V_23 = V_79 -> V_90 ( V_79 , & V_32 ) ;
if ( V_23 )
return V_23 ;
V_23 = V_79 -> V_40 ( V_79 ) ;
return V_23 ;
}
switch ( V_81 -> V_86 ) {
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
default:
return - V_25 ;
}
V_32 . V_95 = V_81 -> V_96 ;
V_32 . V_97 = V_81 -> V_97 ;
V_32 . V_98 = V_84 ;
V_32 . V_88 = true ;
V_89 [ V_79 -> V_3 ] = * V_81 ;
V_23 = V_79 -> V_90 ( V_79 , & V_32 ) ;
if ( V_23 )
return V_23 ;
V_23 = V_79 -> V_40 ( V_79 ) ;
return V_23 ;
}
static int F_34 ( struct V_13 * V_14 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_23 ;
int V_48 ;
struct V_78 * V_79 = NULL ;
F_25 ( V_9 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_24 ; V_48 ++ ) {
if ( V_2 -> V_27 [ V_48 ] -> V_39 ) {
V_79 = V_2 -> V_27 [ V_48 ] -> V_39 ;
break;
}
}
if ( ! V_79 ) {
V_23 = - V_25 ;
goto V_99;
}
V_23 = F_33 ( V_79 , V_81 ) ;
V_99:
F_26 ( V_9 ) ;
return V_23 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_78 * V_79 = NULL ;
int V_23 = 0 ;
int V_48 ;
F_25 ( V_9 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_24 ; V_48 ++ ) {
if ( V_2 -> V_27 [ V_48 ] -> V_39 ) {
V_79 = V_2 -> V_27 [ V_48 ] -> V_39 ;
break;
}
}
if ( ! V_79 ) {
V_23 = - V_25 ;
goto V_99;
}
* V_81 = V_89 [ V_79 -> V_3 ] ;
V_99:
F_26 ( V_9 ) ;
return V_23 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct F_36 * V_100 )
{
struct V_61 * V_62 = F_22 ( V_14 ) ;
void * V_101 ;
int V_23 ;
if ( ! V_62 || ! V_62 -> V_65 -> V_102 )
return - V_103 ;
if ( ! F_37 ( V_104 , V_100 -> V_105 , V_100 -> V_106 ) )
return - V_107 ;
if ( V_100 -> V_59 * V_100 -> V_60 * 3 > V_100 -> V_106 )
return - V_25 ;
V_101 = F_38 ( V_100 -> V_106 ) ;
if ( ! V_101 ) {
F_5 ( L_4 ) ;
return - V_108 ;
}
V_23 = V_62 -> V_65 -> V_102 ( V_62 , V_101 , V_100 -> V_106 ,
V_100 -> V_57 , V_100 -> V_58 , V_100 -> V_59 , V_100 -> V_60 ) ;
if ( V_23 > 0 ) {
if ( F_39 ( V_100 -> V_105 , V_101 , V_100 -> V_106 ) )
V_23 = - V_107 ;
}
F_40 ( V_101 ) ;
return V_23 ;
}
static int F_41 ( struct V_8 * V_9 ,
struct V_109 * V_70 )
{
int V_110 = V_70 -> V_111 ;
int V_112 = V_70 -> V_112 ;
struct V_17 * V_18 ;
enum V_113 V_114 ;
struct V_115 V_116 ;
int V_48 ;
if ( V_110 >= V_9 -> V_24 )
return - V_68 ;
V_18 = V_9 -> V_27 [ V_110 ] ;
V_114 = V_18 -> V_114 ;
V_112 = V_70 -> V_112 ;
for ( V_48 = 0 ; V_48 < sizeof( V_114 ) * 8 ; V_48 ++ ) {
if ( ! ( V_114 & ( 1 << V_48 ) ) )
continue;
if ( F_42 ( 1 << V_48 , & V_116 ) < 0 )
continue;
V_112 -- ;
if ( V_112 < 0 )
break;
}
if ( V_48 == sizeof( V_114 ) * 8 )
return - V_103 ;
V_70 -> V_117 = V_116 . V_117 ;
V_70 -> V_118 = V_116 . V_118 ;
V_70 -> V_119 = V_116 . V_119 ;
V_70 -> V_120 = V_116 . V_120 ;
V_70 -> V_121 = V_116 . V_121 ;
V_70 -> V_122 = V_116 . V_122 ;
return 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_23 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_24 ; ++ V_48 ) {
struct V_17 * V_18 = V_2 -> V_27 [ V_48 ] ;
V_23 = V_18 -> V_123 ( V_18 ) ;
if ( V_23 )
break;
}
return V_23 ;
}
int F_44 ( struct V_13 * V_14 , unsigned int V_124 , unsigned long V_125 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_61 * V_62 = F_22 ( V_14 ) ;
union {
struct V_126 V_127 ;
struct F_23 V_128 ;
struct V_15 V_129 ;
struct V_130 V_76 ;
struct V_45 V_131 ;
struct V_80 V_132 ;
struct V_109 V_133 ;
enum V_69 V_75 ;
int V_134 ;
struct F_36 V_102 ;
struct V_135 V_136 ;
struct V_137 V_138 ;
struct V_139 V_140 ;
T_3 V_141 ;
} V_142 ;
int V_23 = 0 ;
switch ( V_124 ) {
case V_143 :
F_5 ( L_5 ) ;
if ( ! V_62 || ! V_62 -> V_65 -> V_144 ) {
break;
}
V_23 = V_62 -> V_65 -> V_144 ( V_62 ) ;
break;
case V_145 :
F_5 ( L_6 ) ;
if ( ! V_62 || ! V_62 -> V_65 -> V_67 ) {
V_23 = - V_25 ;
break;
}
if ( F_45 ( & V_142 . V_127 ,
( void V_146 * ) V_125 ,
sizeof( V_142 . V_127 ) ) ) {
V_23 = - V_107 ;
break;
}
V_23 = F_21 ( V_14 , V_142 . V_127 . V_57 , V_142 . V_127 . V_58 ,
V_142 . V_127 . V_147 , V_142 . V_127 . V_148 ) ;
break;
case V_149 :
F_5 ( L_7 ) ;
if ( ! V_62 || ! V_62 -> V_65 -> V_67 ) {
V_23 = - V_25 ;
break;
}
if ( F_45 ( & V_142 . V_128 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_128 ) ) ) {
V_23 = - V_107 ;
break;
}
V_23 = F_21 ( V_14 , V_142 . V_128 . V_57 , V_142 . V_128 . V_58 ,
V_142 . V_128 . V_147 , V_142 . V_128 . V_148 ) ;
break;
case V_150 :
F_5 ( L_8 ) ;
if ( F_45 ( & V_142 . V_129 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_129 ) ) )
V_23 = - V_107 ;
else
V_23 = F_3 ( V_14 , & V_142 . V_129 ) ;
break;
case V_151 :
F_5 ( L_9 ) ;
V_23 = F_11 ( V_14 , & V_142 . V_129 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_129 ,
sizeof( V_142 . V_129 ) ) )
V_23 = - V_107 ;
break;
case V_152 :
F_5 ( L_10 ) ;
if ( F_45 ( & V_142 . V_131 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_131 ) ) )
V_23 = - V_107 ;
else
V_23 = F_12 ( V_14 , & V_142 . V_131 ) ;
break;
case V_153 :
F_5 ( L_11 ) ;
V_23 = F_20 ( V_14 , & V_142 . V_131 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_131 ,
sizeof( V_142 . V_131 ) ) )
V_23 = - V_107 ;
break;
case V_154 :
F_5 ( L_12 ) ;
if ( ! V_62 ) {
V_23 = - V_25 ;
break;
}
memset ( & V_142 . V_76 , 0 , sizeof( V_142 . V_76 ) ) ;
if ( V_62 -> V_76 & V_77 )
V_142 . V_76 . V_155 |= V_156 ;
if ( V_62 -> V_76 & V_157 )
V_142 . V_76 . V_155 |= V_158 ;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_76 , sizeof( V_142 . V_76 ) ) )
V_23 = - V_107 ;
break;
case V_159 :
F_5 ( L_13 ) ;
if ( F_45 ( & V_142 . V_133 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_133 ) ) ) {
V_23 = - V_107 ;
break;
}
V_23 = F_41 ( V_9 , & V_142 . V_133 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_133 ,
sizeof( V_142 . V_133 ) ) )
V_23 = - V_107 ;
break;
case V_160 :
F_5 ( L_14 ) ;
if ( F_46 ( V_142 . V_75 , ( int V_146 * ) V_125 ) )
V_23 = - V_107 ;
else
V_23 = F_28 ( V_14 , V_142 . V_75 ) ;
break;
case V_161 :
F_5 ( L_15 ) ;
V_23 = F_32 ( V_14 , & V_142 . V_75 ) ;
if ( V_23 )
break;
if ( F_47 ( V_142 . V_75 ,
(enum V_69 V_146 * ) V_125 ) )
V_23 = - V_107 ;
break;
case V_162 :
F_5 ( L_16 ) ;
if ( F_45 ( & V_142 . V_132 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_132 ) ) )
V_23 = - V_107 ;
else
V_23 = F_34 ( V_14 , & V_142 . V_132 ) ;
break;
case V_163 :
F_5 ( L_17 ) ;
V_23 = F_35 ( V_14 , & V_142 . V_132 ) ;
if ( V_23 )
break;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_132 ,
sizeof( V_142 . V_132 ) ) )
V_23 = - V_107 ;
break;
case V_164 :
if ( F_46 ( V_142 . V_141 , ( V_165 V_146 * ) V_125 ) ) {
V_23 = - V_107 ;
break;
}
if ( V_142 . V_141 != 0 ) {
V_23 = - V_68 ;
break;
}
case V_166 :
F_5 ( L_18 ) ;
if ( ! V_62 ) {
V_23 = - V_25 ;
break;
}
V_23 = V_62 -> V_39 -> V_167 ( V_62 -> V_39 ) ;
break;
case V_168 :
F_5 ( L_19 ) ;
if ( ! V_62 ) {
V_23 = - V_25 ;
break;
}
V_23 = F_43 ( V_14 ) ;
break;
case V_169 :
F_5 ( L_20 ) ;
if ( F_46 ( V_142 . V_134 , ( int V_146 * ) V_125 ) ) {
V_23 = - V_107 ;
break;
}
if ( ! V_62 || ! V_62 -> V_65 -> V_170 ) {
V_23 = - V_25 ;
break;
}
V_23 = V_62 -> V_65 -> V_170 ( V_62 , V_142 . V_134 ) ;
break;
case V_171 :
F_5 ( L_21 ) ;
if ( F_46 ( V_142 . V_134 , ( int V_146 * ) V_125 ) ) {
V_23 = - V_107 ;
break;
}
if ( ! V_62 || ! V_62 -> V_65 -> V_170 ) {
V_23 = - V_25 ;
break;
}
V_23 = V_62 -> V_65 -> V_170 ( V_62 , V_142 . V_134 ) ;
break;
case V_172 :
F_5 ( L_22 ) ;
if ( F_45 ( & V_142 . V_102 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_102 ) ) ) {
V_23 = - V_107 ;
break;
}
V_23 = F_36 ( V_14 , & V_142 . V_102 ) ;
break;
case V_173 : {
unsigned long V_174 , free , V_175 ;
F_5 ( L_23 ) ;
F_48 ( & V_174 , & free , & V_175 ) ;
V_142 . V_136 . V_176 = V_174 ;
V_142 . V_136 . free = free ;
V_142 . V_136 . V_177 = V_175 ;
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_136 ,
sizeof( V_142 . V_136 ) ) )
V_23 = - V_107 ;
break;
}
case V_178 : {
F_5 ( L_24 ) ;
if ( F_45 ( & V_142 . V_138 , ( void V_146 * ) V_125 ,
sizeof( V_142 . V_138 ) ) ) {
V_23 = - V_107 ;
break;
}
if ( ! V_62 || ! V_62 -> V_65 -> V_179 ) {
V_23 = - V_68 ;
break;
}
V_23 = V_62 -> V_65 -> V_179 ( V_62 ,
! ! V_142 . V_138 . V_28 ) ;
break;
}
case V_180 : {
T_4 V_181 , V_182 ;
F_5 ( L_25 ) ;
if ( V_62 == NULL ) {
V_23 = - V_68 ;
break;
}
V_62 -> V_65 -> V_66 ( V_62 , & V_181 , & V_182 ) ;
V_142 . V_140 . V_181 = V_181 ;
V_142 . V_140 . V_182 = V_182 ;
if ( V_62 -> V_65 -> V_183 ) {
T_3 V_59 , V_60 ;
V_62 -> V_65 -> V_183 ( V_62 , & V_59 , & V_60 ) ;
V_142 . V_140 . V_147 = V_59 ;
V_142 . V_140 . V_148 = V_60 ;
} else {
V_142 . V_140 . V_147 = 0 ;
V_142 . V_140 . V_148 = 0 ;
}
if ( F_39 ( ( void V_146 * ) V_125 , & V_142 . V_140 ,
sizeof( V_142 . V_140 ) ) )
V_23 = - V_107 ;
break;
}
default:
F_10 ( V_9 -> V_41 , L_26 , V_124 ) ;
V_23 = - V_25 ;
}
if ( V_23 < 0 )
F_5 ( L_27 , V_23 ) ;
return V_23 ;
}
