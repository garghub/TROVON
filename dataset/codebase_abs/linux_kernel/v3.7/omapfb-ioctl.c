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
if ( V_2 -> V_24 == 0 ) {
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
if ( ! V_16 -> V_28 ) {
V_23 = V_18 -> V_32 ( V_18 ) ;
if ( V_23 )
goto V_33;
}
if ( V_16 -> V_28 ) {
V_23 = F_8 ( V_14 , V_18 , V_16 -> V_34 , V_16 -> V_35 ,
V_16 -> V_36 , V_16 -> V_37 ) ;
if ( V_23 )
goto V_33;
} else {
struct V_19 V_38 ;
V_18 -> V_31 ( V_18 , & V_38 ) ;
V_38 . V_34 = V_16 -> V_34 ;
V_38 . V_35 = V_16 -> V_35 ;
V_38 . V_36 = V_16 -> V_36 ;
V_38 . V_37 = V_16 -> V_37 ;
V_23 = V_18 -> V_39 ( V_18 , & V_38 ) ;
if ( V_23 )
goto V_33;
}
if ( V_18 -> V_40 )
V_18 -> V_40 -> V_41 ( V_18 -> V_40 ) ;
if ( V_16 -> V_28 ) {
V_23 = V_18 -> V_42 ( V_18 ) ;
if ( V_23 )
goto V_33;
}
if ( V_21 -> V_3 > V_22 -> V_3 ) {
F_9 ( V_21 ) ;
F_9 ( V_22 ) ;
} else if ( V_22 -> V_3 > V_21 -> V_3 ) {
F_9 ( V_22 ) ;
F_9 ( V_21 ) ;
} else
F_9 ( V_21 ) ;
return 0 ;
V_33:
if ( V_21 != V_22 ) {
V_2 -> V_4 = V_21 ;
F_7 ( V_14 ) ;
}
V_18 -> V_39 ( V_18 , & V_20 ) ;
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
F_10 ( V_9 -> V_43 , L_2 ) ;
return V_23 ;
}
static int F_11 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
if ( V_2 -> V_24 == 0 ) {
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
} else {
struct V_17 * V_18 ;
struct V_19 V_44 ;
V_18 = V_2 -> V_27 [ 0 ] ;
V_18 -> V_31 ( V_18 , & V_44 ) ;
V_16 -> V_34 = V_44 . V_34 ;
V_16 -> V_35 = V_44 . V_35 ;
V_16 -> V_28 = V_18 -> V_45 ( V_18 ) ;
V_16 -> V_46 = 0 ;
V_16 -> V_47 = 0 ;
V_16 -> V_7 = F_1 ( V_2 ) ;
V_16 -> V_36 = V_44 . V_36 ;
V_16 -> V_37 = V_44 . V_37 ;
}
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 * V_50 ;
int V_23 = 0 , V_51 ;
T_2 V_29 ;
if ( V_49 -> type != V_52 )
return - V_25 ;
V_29 = F_13 ( V_49 -> V_29 ) ;
V_50 = V_2 -> V_4 ;
F_14 ( & V_50 -> V_53 , V_50 -> V_3 ) ;
F_15 ( & V_50 -> V_54 ) ;
if ( V_50 -> V_29 == V_29 && V_50 -> type == V_49 -> type )
goto V_26;
if ( F_16 ( & V_50 -> V_55 ) ) {
V_23 = - V_56 ;
goto V_26;
}
for ( V_51 = 0 ; V_51 < V_9 -> V_11 ; V_51 ++ ) {
struct V_1 * V_57 = F_4 ( V_9 -> V_58 [ V_51 ] ) ;
int V_59 ;
if ( V_57 -> V_4 != V_50 )
continue;
for ( V_59 = 0 ; V_59 < V_57 -> V_24 ; V_59 ++ ) {
struct V_17 * V_18 ;
V_18 = V_57 -> V_27 [ V_59 ] ;
if ( V_18 -> V_45 ( V_18 ) ) {
V_23 = - V_56 ;
goto V_26;
}
}
}
V_23 = F_17 ( V_14 , V_29 , V_49 -> type ) ;
if ( V_23 ) {
F_10 ( V_9 -> V_43 , L_3 ) ;
goto V_26;
}
V_26:
F_18 ( & V_50 -> V_54 ) ;
F_19 ( & V_50 -> V_53 ) ;
return V_23 ;
}
static int F_20 ( struct V_13 * V_14 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_6 * V_50 ;
V_50 = F_6 ( V_2 -> V_4 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_29 = V_50 -> V_29 ;
V_49 -> type = V_50 -> type ;
F_9 ( V_50 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 ,
T_3 V_60 , T_3 V_61 , T_3 V_62 , T_3 V_63 )
{
struct V_64 * V_65 = F_22 ( V_14 ) ;
T_4 V_66 , V_67 ;
if ( ! V_65 )
return 0 ;
if ( V_62 == 0 || V_63 == 0 )
return 0 ;
V_65 -> V_68 -> V_69 ( V_65 , & V_66 , & V_67 ) ;
if ( V_60 + V_62 > V_66 || V_61 + V_63 > V_67 )
return - V_25 ;
return V_65 -> V_68 -> V_70 ( V_65 , V_60 , V_61 , V_62 , V_63 ) ;
}
int F_23 ( struct V_13 * V_14 ,
T_3 V_60 , T_3 V_61 , T_3 V_62 , T_3 V_63 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_23 ;
if ( ! F_24 ( V_14 ) )
return - V_71 ;
F_25 ( V_9 ) ;
V_23 = F_21 ( V_14 , V_60 , V_61 , V_62 , V_63 ) ;
F_26 ( V_9 ) ;
F_27 ( V_14 ) ;
return V_23 ;
}
int F_28 ( struct V_13 * V_14 ,
enum V_72 V_73 )
{
struct V_64 * V_65 = F_22 ( V_14 ) ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_74 * V_75 ;
int V_23 ;
if ( ! V_65 )
return - V_25 ;
if ( V_73 != V_76 && V_73 != V_77 )
return - V_25 ;
F_25 ( V_9 ) ;
V_75 = F_29 ( V_9 , V_65 ) ;
if ( V_75 -> V_78 == V_73 ) {
F_26 ( V_9 ) ;
return 0 ;
}
V_23 = 0 ;
if ( V_65 -> V_79 & V_80 ) {
if ( V_73 == V_76 )
F_30 ( V_9 , V_65 ) ;
else
F_31 ( V_9 , V_65 ) ;
V_75 -> V_78 = V_73 ;
} else {
if ( V_73 == V_77 )
V_23 = - V_25 ;
}
F_26 ( V_9 ) ;
return V_23 ;
}
int F_32 ( struct V_13 * V_14 ,
enum V_72 * V_73 )
{
struct V_64 * V_65 = F_22 ( V_14 ) ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_74 * V_75 ;
if ( ! V_65 )
return - V_25 ;
F_25 ( V_9 ) ;
V_75 = F_29 ( V_9 , V_65 ) ;
* V_73 = V_75 -> V_78 ;
F_26 ( V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 V_38 ;
enum V_86 V_87 ;
int V_23 ;
V_82 -> V_88 ( V_82 , & V_38 ) ;
if ( V_84 -> V_89 == V_90 ) {
V_38 . V_91 = false ;
V_92 [ V_82 -> V_3 ] = * V_84 ;
V_23 = V_82 -> V_93 ( V_82 , & V_38 ) ;
if ( V_23 )
return V_23 ;
V_23 = V_82 -> V_41 ( V_82 ) ;
return V_23 ;
}
switch ( V_84 -> V_89 ) {
case V_94 :
V_87 = V_95 ;
break;
case V_96 :
V_87 = V_97 ;
break;
default:
return - V_25 ;
}
V_38 . V_98 = V_84 -> V_99 ;
V_38 . V_100 = V_84 -> V_100 ;
V_38 . V_101 = V_87 ;
V_38 . V_91 = true ;
V_92 [ V_82 -> V_3 ] = * V_84 ;
V_23 = V_82 -> V_93 ( V_82 , & V_38 ) ;
if ( V_23 )
return V_23 ;
V_23 = V_82 -> V_41 ( V_82 ) ;
return V_23 ;
}
static int F_34 ( struct V_13 * V_14 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_23 ;
int V_51 ;
struct V_81 * V_82 = NULL ;
F_25 ( V_9 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_24 ; V_51 ++ ) {
if ( V_2 -> V_27 [ V_51 ] -> V_40 ) {
V_82 = V_2 -> V_27 [ V_51 ] -> V_40 ;
break;
}
}
if ( ! V_82 ) {
V_23 = - V_25 ;
goto V_102;
}
V_23 = F_33 ( V_82 , V_84 ) ;
V_102:
F_26 ( V_9 ) ;
return V_23 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_81 * V_82 = NULL ;
int V_23 = 0 ;
int V_51 ;
F_25 ( V_9 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_24 ; V_51 ++ ) {
if ( V_2 -> V_27 [ V_51 ] -> V_40 ) {
V_82 = V_2 -> V_27 [ V_51 ] -> V_40 ;
break;
}
}
if ( ! V_82 ) {
V_23 = - V_25 ;
goto V_102;
}
* V_84 = V_92 [ V_82 -> V_3 ] ;
V_102:
F_26 ( V_9 ) ;
return V_23 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct F_36 * V_103 )
{
struct V_64 * V_65 = F_22 ( V_14 ) ;
void * V_104 ;
int V_23 ;
if ( ! V_65 || ! V_65 -> V_68 -> V_105 )
return - V_106 ;
if ( ! F_37 ( V_107 , V_103 -> V_108 , V_103 -> V_109 ) )
return - V_110 ;
if ( V_103 -> V_62 * V_103 -> V_63 * 3 > V_103 -> V_109 )
return - V_25 ;
V_104 = F_38 ( V_103 -> V_109 ) ;
if ( ! V_104 ) {
F_5 ( L_4 ) ;
return - V_111 ;
}
V_23 = V_65 -> V_68 -> V_105 ( V_65 , V_104 , V_103 -> V_109 ,
V_103 -> V_60 , V_103 -> V_61 , V_103 -> V_62 , V_103 -> V_63 ) ;
if ( V_23 > 0 ) {
if ( F_39 ( V_103 -> V_108 , V_104 , V_103 -> V_109 ) )
V_23 = - V_110 ;
}
F_40 ( V_104 ) ;
return V_23 ;
}
static int F_41 ( struct V_8 * V_9 ,
struct V_112 * V_73 )
{
int V_113 = V_73 -> V_114 ;
int V_115 = V_73 -> V_115 ;
struct V_17 * V_18 ;
enum V_116 V_117 ;
struct V_118 V_119 ;
int V_51 ;
if ( V_113 >= V_9 -> V_24 )
return - V_71 ;
V_18 = V_9 -> V_27 [ V_113 ] ;
V_117 = V_18 -> V_117 ;
V_115 = V_73 -> V_115 ;
for ( V_51 = 0 ; V_51 < sizeof( V_117 ) * 8 ; V_51 ++ ) {
if ( ! ( V_117 & ( 1 << V_51 ) ) )
continue;
if ( F_42 ( 1 << V_51 , & V_119 ) < 0 )
continue;
V_115 -- ;
if ( V_115 < 0 )
break;
}
if ( V_51 == sizeof( V_117 ) * 8 )
return - V_106 ;
V_73 -> V_120 = V_119 . V_120 ;
V_73 -> V_121 = V_119 . V_121 ;
V_73 -> V_122 = V_119 . V_122 ;
V_73 -> V_123 = V_119 . V_123 ;
V_73 -> V_124 = V_119 . V_124 ;
V_73 -> V_125 = V_119 . V_125 ;
return 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_23 = 0 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_24 ; ++ V_51 ) {
struct V_17 * V_18 = V_2 -> V_27 [ V_51 ] ;
V_23 = V_18 -> V_126 ( V_18 ) ;
if ( V_23 )
break;
}
return V_23 ;
}
int F_44 ( struct V_13 * V_14 , unsigned int V_127 , unsigned long V_128 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_64 * V_65 = F_22 ( V_14 ) ;
struct V_81 * V_82 ;
union {
struct V_129 V_130 ;
struct F_23 V_131 ;
struct V_15 V_132 ;
struct V_133 V_79 ;
struct V_48 V_134 ;
struct V_83 V_135 ;
struct V_112 V_136 ;
enum V_72 V_78 ;
int V_137 ;
struct F_36 V_105 ;
struct V_138 V_139 ;
struct V_140 V_141 ;
struct V_142 V_143 ;
T_3 V_144 ;
} V_145 ;
int V_23 = 0 ;
switch ( V_127 ) {
case V_146 :
F_5 ( L_5 ) ;
if ( ! V_65 || ! V_65 -> V_68 -> V_147 ) {
break;
}
V_23 = V_65 -> V_68 -> V_147 ( V_65 ) ;
break;
case V_148 :
F_5 ( L_6 ) ;
if ( ! V_65 || ! V_65 -> V_68 -> V_70 ) {
V_23 = - V_25 ;
break;
}
if ( F_45 ( & V_145 . V_130 ,
( void V_149 * ) V_128 ,
sizeof( V_145 . V_130 ) ) ) {
V_23 = - V_110 ;
break;
}
V_23 = F_21 ( V_14 , V_145 . V_130 . V_60 , V_145 . V_130 . V_61 ,
V_145 . V_130 . V_150 , V_145 . V_130 . V_151 ) ;
break;
case V_152 :
F_5 ( L_7 ) ;
if ( ! V_65 || ! V_65 -> V_68 -> V_70 ) {
V_23 = - V_25 ;
break;
}
if ( F_45 ( & V_145 . V_131 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_131 ) ) ) {
V_23 = - V_110 ;
break;
}
V_23 = F_21 ( V_14 , V_145 . V_131 . V_60 , V_145 . V_131 . V_61 ,
V_145 . V_131 . V_150 , V_145 . V_131 . V_151 ) ;
break;
case V_153 :
F_5 ( L_8 ) ;
if ( F_45 ( & V_145 . V_132 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_132 ) ) )
V_23 = - V_110 ;
else
V_23 = F_3 ( V_14 , & V_145 . V_132 ) ;
break;
case V_154 :
F_5 ( L_9 ) ;
V_23 = F_11 ( V_14 , & V_145 . V_132 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_132 ,
sizeof( V_145 . V_132 ) ) )
V_23 = - V_110 ;
break;
case V_155 :
F_5 ( L_10 ) ;
if ( F_45 ( & V_145 . V_134 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_134 ) ) )
V_23 = - V_110 ;
else
V_23 = F_12 ( V_14 , & V_145 . V_134 ) ;
break;
case V_156 :
F_5 ( L_11 ) ;
V_23 = F_20 ( V_14 , & V_145 . V_134 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_134 ,
sizeof( V_145 . V_134 ) ) )
V_23 = - V_110 ;
break;
case V_157 :
F_5 ( L_12 ) ;
if ( ! V_65 ) {
V_23 = - V_25 ;
break;
}
memset ( & V_145 . V_79 , 0 , sizeof( V_145 . V_79 ) ) ;
if ( V_65 -> V_79 & V_80 )
V_145 . V_79 . V_158 |= V_159 ;
if ( V_65 -> V_79 & V_160 )
V_145 . V_79 . V_158 |= V_161 ;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_79 , sizeof( V_145 . V_79 ) ) )
V_23 = - V_110 ;
break;
case V_162 :
F_5 ( L_13 ) ;
if ( F_45 ( & V_145 . V_136 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_136 ) ) ) {
V_23 = - V_110 ;
break;
}
V_23 = F_41 ( V_9 , & V_145 . V_136 ) ;
if ( V_23 < 0 )
break;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_136 ,
sizeof( V_145 . V_136 ) ) )
V_23 = - V_110 ;
break;
case V_163 :
F_5 ( L_14 ) ;
if ( F_46 ( V_145 . V_78 , ( int V_149 * ) V_128 ) )
V_23 = - V_110 ;
else
V_23 = F_28 ( V_14 , V_145 . V_78 ) ;
break;
case V_164 :
F_5 ( L_15 ) ;
V_23 = F_32 ( V_14 , & V_145 . V_78 ) ;
if ( V_23 )
break;
if ( F_47 ( V_145 . V_78 ,
(enum V_72 V_149 * ) V_128 ) )
V_23 = - V_110 ;
break;
case V_165 :
F_5 ( L_16 ) ;
if ( F_45 ( & V_145 . V_135 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_135 ) ) )
V_23 = - V_110 ;
else
V_23 = F_34 ( V_14 , & V_145 . V_135 ) ;
break;
case V_166 :
F_5 ( L_17 ) ;
V_23 = F_35 ( V_14 , & V_145 . V_135 ) ;
if ( V_23 )
break;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_135 ,
sizeof( V_145 . V_135 ) ) )
V_23 = - V_110 ;
break;
case V_167 :
if ( F_46 ( V_145 . V_144 , ( V_168 V_149 * ) V_128 ) ) {
V_23 = - V_110 ;
break;
}
if ( V_145 . V_144 != 0 ) {
V_23 = - V_71 ;
break;
}
case V_169 :
F_5 ( L_18 ) ;
if ( ! V_65 || ! V_65 -> V_170 || ! V_65 -> V_170 -> V_40 ) {
V_23 = - V_25 ;
break;
}
V_82 = V_65 -> V_170 -> V_40 ;
V_23 = V_82 -> V_171 ( V_82 ) ;
break;
case V_172 :
F_5 ( L_19 ) ;
if ( ! V_65 ) {
V_23 = - V_25 ;
break;
}
V_23 = F_43 ( V_14 ) ;
break;
case V_173 :
F_5 ( L_20 ) ;
if ( F_46 ( V_145 . V_137 , ( int V_149 * ) V_128 ) ) {
V_23 = - V_110 ;
break;
}
if ( ! V_65 || ! V_65 -> V_68 -> V_174 ) {
V_23 = - V_25 ;
break;
}
V_23 = V_65 -> V_68 -> V_174 ( V_65 , V_145 . V_137 ) ;
break;
case V_175 :
F_5 ( L_21 ) ;
if ( F_46 ( V_145 . V_137 , ( int V_149 * ) V_128 ) ) {
V_23 = - V_110 ;
break;
}
if ( ! V_65 || ! V_65 -> V_68 -> V_174 ) {
V_23 = - V_25 ;
break;
}
V_23 = V_65 -> V_68 -> V_174 ( V_65 , V_145 . V_137 ) ;
break;
case V_176 :
F_5 ( L_22 ) ;
if ( F_45 ( & V_145 . V_105 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_105 ) ) ) {
V_23 = - V_110 ;
break;
}
V_23 = F_36 ( V_14 , & V_145 . V_105 ) ;
break;
case V_177 : {
unsigned long V_178 , free , V_179 ;
F_5 ( L_23 ) ;
F_48 ( & V_178 , & free , & V_179 ) ;
V_145 . V_139 . V_180 = V_178 ;
V_145 . V_139 . free = free ;
V_145 . V_139 . V_181 = V_179 ;
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_139 ,
sizeof( V_145 . V_139 ) ) )
V_23 = - V_110 ;
break;
}
case V_182 : {
F_5 ( L_24 ) ;
if ( F_45 ( & V_145 . V_141 , ( void V_149 * ) V_128 ,
sizeof( V_145 . V_141 ) ) ) {
V_23 = - V_110 ;
break;
}
if ( ! V_65 || ! V_65 -> V_68 -> V_183 ) {
V_23 = - V_71 ;
break;
}
V_23 = V_65 -> V_68 -> V_183 ( V_65 ,
! ! V_145 . V_141 . V_28 ) ;
break;
}
case V_184 : {
T_4 V_185 , V_186 ;
F_5 ( L_25 ) ;
if ( V_65 == NULL ) {
V_23 = - V_71 ;
break;
}
V_65 -> V_68 -> V_69 ( V_65 , & V_185 , & V_186 ) ;
V_145 . V_143 . V_185 = V_185 ;
V_145 . V_143 . V_186 = V_186 ;
if ( V_65 -> V_68 -> V_187 ) {
T_3 V_62 , V_63 ;
V_65 -> V_68 -> V_187 ( V_65 , & V_62 , & V_63 ) ;
V_145 . V_143 . V_150 = V_62 ;
V_145 . V_143 . V_151 = V_63 ;
} else {
V_145 . V_143 . V_150 = 0 ;
V_145 . V_143 . V_151 = 0 ;
}
if ( F_39 ( ( void V_149 * ) V_128 , & V_145 . V_143 ,
sizeof( V_145 . V_143 ) ) )
V_23 = - V_110 ;
break;
}
default:
F_10 ( V_9 -> V_43 , L_26 , V_127 ) ;
V_23 = - V_25 ;
}
if ( V_23 < 0 )
F_5 ( L_27 , V_23 ) ;
return V_23 ;
}
