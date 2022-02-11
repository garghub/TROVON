static int F_1 ( void )
{
int V_1 = - V_2 ;
struct V_3 T_1 * V_4 = V_5 ;
T_2 V_6 = F_2 ( F_3 () , V_7 ) ;
while ( ! F_4 ( F_3 () , V_6 ) ) {
if ( F_5 ( & V_4 -> V_8 ) & V_9 ) {
V_1 = 0 ;
break;
}
F_6 ( 3 ) ;
}
return V_1 ;
}
static int F_7 ( T_3 V_10 )
{
int V_1 = - V_2 ;
struct V_3 * V_4 =
(struct V_3 * ) V_5 ;
static T_2 V_11 , V_12 ;
static int V_13 ;
unsigned int V_14 ;
if ( V_10 == V_15 ) {
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
}
if ( V_16 ) {
V_14 = F_8 ( F_3 () , V_11 ) ;
if ( V_16 > V_14 )
F_6 ( V_16 - V_14 ) ;
}
if ( V_17 ) {
if ( V_13 == 0 ) {
V_14 = F_9 ( F_3 () , V_12 ) ;
if ( V_14 < 60 * V_18 ) {
F_10 ( L_1 ) ;
return - V_2 ;
}
V_12 = F_3 () ;
V_13 = V_17 ;
}
V_13 -- ;
}
F_11 ( V_10 , & V_4 -> V_19 ) ;
F_11 ( 0 , & V_4 -> V_8 ) ;
V_1 = F_12 ( V_20 , & V_10 ) ;
if ( V_1 < 0 ) {
F_13 ( L_2 ,
V_10 , V_1 ) ;
return V_1 ;
}
if ( V_10 == V_15 || V_16 ) {
V_1 = F_1 () ;
if ( V_16 )
V_11 = F_3 () ;
}
F_14 ( V_20 , V_1 ) ;
return V_1 ;
}
static void F_15 ( struct V_21 * V_22 , void * V_23 , int V_1 )
{
if ( V_1 < 0 )
F_10 ( L_3 ,
* ( T_3 * ) V_23 , V_1 ) ;
else
F_10 ( L_4 ,
* ( T_3 * ) V_23 , V_1 ) ;
}
static int F_16 ( struct V_24 * V_25 , T_4 V_26 )
{
int V_27 = - V_28 ;
T_5 V_8 = V_29 ;
struct V_30 V_31 = { V_32 , NULL } ;
struct V_30 V_33 = { sizeof( L_5 ) , L_5 } ;
struct V_30 V_34 = { 0 , NULL } ;
union V_35 * V_36 = NULL ;
struct V_37 * V_38 ;
V_8 = F_17 ( V_26 , L_6 , NULL , & V_31 ,
V_39 ) ;
if ( F_18 ( V_8 ) )
return - V_40 ;
V_36 = V_31 . V_41 ;
if ( ! V_36 || V_36 -> V_42 . V_43 != 1 ) {
F_10 ( L_7 ) ;
goto V_44;
}
V_38 = & ( V_25 -> V_45 ) ;
V_34 . V_46 = sizeof( struct V_37 ) ;
V_34 . V_41 = V_38 ;
V_8 = F_19 ( & ( V_36 -> V_42 . V_47 [ 0 ] ) ,
& V_33 , & V_34 ) ;
if ( F_18 ( V_8 ) ) {
F_10 ( L_8 , V_25 -> V_48 ) ;
goto V_44;
}
if ( V_38 -> V_49 != V_50 ) {
F_10 ( L_9 , V_25 -> V_48 ) ;
goto V_44;
}
if ( V_38 -> V_51 != V_52 ) {
F_10 ( L_10 , V_25 -> V_48 ) ;
goto V_44;
}
if ( V_38 -> V_53 != V_54 &&
V_38 -> V_53 != V_55 &&
V_38 -> V_53 != V_56 ) {
F_10 ( L_11 , V_25 -> V_48 ) ;
goto V_44;
}
V_27 = 0 ;
V_44:
F_20 ( V_31 . V_41 ) ;
return V_27 ;
}
int F_21 ( struct V_57 * * V_58 )
{
int V_59 ;
int V_60 = 0 ;
unsigned int V_61 , V_62 ;
T_6 V_63 ;
struct V_57 * V_64 , * V_65 ;
struct V_37 * V_38 ;
struct V_37 * V_66 ;
struct V_24 * V_25 , * V_67 ;
if ( ! F_22 ( & V_63 , V_68 ) )
return - V_69 ;
F_23 (i) {
V_64 = V_58 [ V_61 ] ;
if ( ! V_64 )
continue;
if ( F_24 ( V_61 , V_63 ) )
continue;
V_25 = F_25 ( V_70 , V_61 ) ;
if ( ! V_25 ) {
V_60 = - V_28 ;
goto V_71;
}
V_38 = & ( V_25 -> V_45 ) ;
F_26 ( V_61 , V_64 -> V_72 ) ;
F_26 ( V_61 , V_63 ) ;
if ( V_38 -> V_73 <= 1 )
continue;
V_59 = V_38 -> V_73 ;
if ( V_38 -> V_53 == V_54 )
V_64 -> V_74 = V_75 ;
else if ( V_38 -> V_53 == V_56 )
V_64 -> V_74 = V_76 ;
else if ( V_38 -> V_53 == V_55 )
V_64 -> V_74 = V_77 ;
F_23 (j) {
if ( V_61 == V_62 )
continue;
V_67 = F_25 ( V_70 , V_62 ) ;
if ( ! V_67 ) {
V_60 = - V_28 ;
goto V_71;
}
V_66 = & ( V_67 -> V_45 ) ;
if ( V_66 -> V_78 != V_38 -> V_78 )
continue;
if ( V_66 -> V_73 != V_59 ) {
V_60 = - V_28 ;
goto V_71;
}
if ( V_38 -> V_53 != V_66 -> V_53 ) {
V_60 = - V_28 ;
goto V_71;
}
F_26 ( V_62 , V_63 ) ;
F_26 ( V_62 , V_64 -> V_72 ) ;
}
F_23 (j) {
if ( V_61 == V_62 )
continue;
V_65 = V_58 [ V_62 ] ;
if ( ! V_65 )
continue;
V_67 = F_25 ( V_70 , V_62 ) ;
if ( ! V_67 ) {
V_60 = - V_28 ;
goto V_71;
}
V_66 = & ( V_67 -> V_45 ) ;
if ( V_66 -> V_78 != V_38 -> V_78 )
continue;
V_65 -> V_74 = V_64 -> V_74 ;
F_27 ( V_65 -> V_72 ,
V_64 -> V_72 ) ;
}
}
V_71:
F_23 (i) {
V_64 = V_58 [ V_61 ] ;
if ( ! V_64 )
continue;
if ( V_60 ) {
F_28 ( V_64 -> V_72 ) ;
F_26 ( V_61 , V_64 -> V_72 ) ;
V_64 -> V_74 = V_75 ;
}
}
F_29 ( V_63 ) ;
return V_60 ;
}
static int F_30 ( int V_79 )
{
struct V_80 * V_81 ;
unsigned int V_82 ;
T_7 V_83 ;
if ( V_79 >= 0 ) {
V_20 = F_31 ( & V_84 ,
V_79 ) ;
if ( F_32 ( V_20 ) ) {
F_13 ( L_12 ) ;
return - V_40 ;
}
V_81 = V_20 -> V_85 ;
if ( ! V_81 ) {
F_13 ( L_13 ) ;
return - V_40 ;
}
V_86 = V_81 -> V_87 ;
V_82 = V_81 -> V_46 ;
V_83 = V_88 * V_81 -> V_89 ;
V_7 = F_33 ( V_83 * V_90 ) ;
V_16 = V_81 -> V_91 ;
V_17 = V_81 -> V_92 ;
V_5 = F_34 ( V_86 , V_82 ) ;
if ( ! V_5 ) {
F_13 ( L_14 ) ;
return - V_69 ;
}
V_93 = true ;
}
return 0 ;
}
int F_35 ( struct V_94 * V_64 )
{
struct V_30 V_95 = { V_32 , NULL } ;
union V_35 * V_96 , * V_97 ;
struct V_24 * V_25 ;
struct V_98 * V_99 ;
T_4 V_26 = V_64 -> V_26 ;
unsigned int V_100 , V_61 , V_101 ;
T_5 V_8 ;
int V_1 = - V_28 ;
V_8 = F_17 ( V_26 , L_15 , NULL , & V_95 ,
V_39 ) ;
if ( F_18 ( V_8 ) ) {
V_1 = - V_40 ;
goto V_102;
}
V_96 = (union V_35 * ) V_95 . V_41 ;
V_25 = F_36 ( sizeof( struct V_24 ) , V_68 ) ;
if ( ! V_25 ) {
V_1 = - V_69 ;
goto V_102;
}
V_97 = & V_96 -> V_42 . V_47 [ 0 ] ;
if ( V_97 -> type == V_103 ) {
V_100 = V_97 -> integer . V_104 ;
} else {
F_10 ( L_16 ,
V_97 -> type ) ;
goto V_105;
}
if ( V_100 != V_106 ) {
F_10 ( L_17 ,
V_100 , V_106 ) ;
goto V_105;
}
V_97 = & V_96 -> V_42 . V_47 [ 1 ] ;
if ( V_97 -> type == V_103 ) {
V_101 = V_97 -> integer . V_104 ;
} else {
F_10 ( L_18 ,
V_97 -> type ) ;
goto V_105;
}
if ( V_101 != V_107 ) {
F_10 ( L_19 ,
V_101 , V_107 ) ;
goto V_105;
}
for ( V_61 = 2 ; V_61 < V_100 ; V_61 ++ ) {
V_97 = & V_96 -> V_42 . V_47 [ V_61 ] ;
if ( V_97 -> type == V_103 ) {
V_25 -> V_108 [ V_61 - 2 ] . type = V_103 ;
V_25 -> V_108 [ V_61 - 2 ] . V_109 . V_110 = V_97 -> integer . V_104 ;
} else if ( V_97 -> type == V_111 ) {
V_99 = (struct V_98 * )
V_97 -> V_31 . V_41 ;
if ( V_99 -> V_112 == V_113 ) {
if ( V_79 < 0 )
V_79 = V_99 -> V_114 ;
else if ( V_79 != V_99 -> V_114 ) {
F_10 ( L_20 ) ;
goto V_105;
}
} else if ( V_99 -> V_112 != V_115 ) {
F_10 ( L_21 , V_99 -> V_112 ) ;
goto V_105;
}
V_25 -> V_108 [ V_61 - 2 ] . type = V_111 ;
memcpy ( & V_25 -> V_108 [ V_61 - 2 ] . V_109 . V_116 , V_99 , sizeof( * V_99 ) ) ;
} else {
F_10 ( L_22 , V_61 , V_64 -> V_117 ) ;
goto V_105;
}
}
V_25 -> V_48 = V_64 -> V_117 ;
V_1 = F_16 ( V_25 , V_26 ) ;
if ( V_1 )
goto V_105;
if ( ! V_93 ) {
V_1 = F_30 ( V_79 ) ;
if ( V_1 )
goto V_105;
}
F_25 ( V_70 , V_64 -> V_117 ) = V_25 ;
F_10 ( L_23 , V_64 -> V_117 ) ;
F_20 ( V_95 . V_41 ) ;
return 0 ;
V_105:
F_20 ( V_25 ) ;
V_102:
F_20 ( V_95 . V_41 ) ;
return V_1 ;
}
void F_37 ( struct V_94 * V_64 )
{
struct V_24 * V_25 ;
V_25 = F_25 ( V_70 , V_64 -> V_117 ) ;
F_20 ( V_25 ) ;
}
static int F_38 ( struct V_98 * V_116 , T_7 * V_118 )
{
int V_119 = 0 ;
* V_118 = 0 ;
if ( V_116 -> V_112 == V_113 ) {
void T_1 * V_120 = F_39 ( V_116 -> V_121 ) ;
switch ( V_116 -> V_122 ) {
case 8 :
* V_118 = F_40 ( V_120 ) ;
break;
case 16 :
* V_118 = F_5 ( V_120 ) ;
break;
case 32 :
* V_118 = F_41 ( V_120 ) ;
break;
case 64 :
* V_118 = F_42 ( V_120 ) ;
break;
default:
F_10 ( L_24 ,
V_116 -> V_122 ) ;
V_119 = - V_28 ;
}
} else
V_119 = F_43 ( ( V_123 ) V_116 -> V_121 ,
V_118 , V_116 -> V_122 ) ;
return V_119 ;
}
static int F_44 ( struct V_98 * V_116 , T_7 V_118 )
{
int V_119 = 0 ;
if ( V_116 -> V_112 == V_113 ) {
void T_1 * V_120 = F_39 ( V_116 -> V_121 ) ;
switch ( V_116 -> V_122 ) {
case 8 :
F_45 ( V_118 , V_120 ) ;
break;
case 16 :
F_11 ( V_118 , V_120 ) ;
break;
case 32 :
F_46 ( V_118 , V_120 ) ;
break;
case 64 :
F_47 ( V_118 , V_120 ) ;
break;
default:
F_10 ( L_25 ,
V_116 -> V_122 ) ;
V_119 = - V_28 ;
break;
}
} else
V_119 = F_48 ( ( V_123 ) V_116 -> V_121 ,
V_118 , V_116 -> V_122 ) ;
return V_119 ;
}
int F_49 ( int V_124 , struct V_125 * V_126 )
{
struct V_24 * V_24 = F_25 ( V_70 , V_124 ) ;
struct V_127 * V_128 , * V_129 , * V_130 ,
* V_131 ;
T_7 V_132 , V_133 , V_134 , V_135 ;
int V_1 = 0 ;
if ( ! V_24 ) {
F_10 ( L_26 , V_124 ) ;
return - V_40 ;
}
V_128 = & V_24 -> V_108 [ V_136 ] ;
V_129 = & V_24 -> V_108 [ V_137 ] ;
V_130 = & V_24 -> V_108 [ V_138 ] ;
V_131 = & V_24 -> V_108 [ V_139 ] ;
F_50 ( & V_140 ) ;
if ( ( V_128 -> V_109 . V_116 . V_112 == V_113 ) ||
( V_129 -> V_109 . V_116 . V_112 == V_113 ) ||
( V_130 -> V_109 . V_116 . V_112 == V_113 ) ||
( V_131 -> V_109 . V_116 . V_112 == V_113 ) ) {
if ( F_7 ( V_15 ) < 0 ) {
V_1 = - V_2 ;
goto V_141;
}
}
F_38 ( & V_128 -> V_109 . V_116 , & V_132 ) ;
V_126 -> V_142 = V_132 ;
F_38 ( & V_129 -> V_109 . V_116 , & V_133 ) ;
V_126 -> V_143 = V_133 ;
F_38 ( & V_130 -> V_109 . V_116 , & V_134 ) ;
V_126 -> V_144 = V_134 ;
F_38 ( & V_131 -> V_109 . V_116 , & V_135 ) ;
V_126 -> V_145 = V_135 ;
if ( ! V_134 )
V_126 -> V_144 = V_126 -> V_145 ;
if ( ! V_132 || ! V_133 || ! V_135 )
V_1 = - V_28 ;
V_141:
F_51 ( & V_140 ) ;
return V_1 ;
}
int F_52 ( int V_124 , struct V_146 * V_147 )
{
struct V_24 * V_24 = F_25 ( V_70 , V_124 ) ;
struct V_127 * V_148 , * V_149 ;
T_7 V_150 , V_151 ;
int V_1 = 0 ;
if ( ! V_24 ) {
F_10 ( L_26 , V_124 ) ;
return - V_40 ;
}
V_148 = & V_24 -> V_108 [ V_152 ] ;
V_149 = & V_24 -> V_108 [ V_153 ] ;
F_50 ( & V_140 ) ;
if ( ( V_148 -> V_109 . V_116 . V_112 == V_113 ) ||
( V_149 -> V_109 . V_116 . V_112 == V_113 ) ) {
if ( F_7 ( V_15 ) < 0 ) {
V_1 = - V_2 ;
goto V_141;
}
}
F_38 ( & V_148 -> V_109 . V_116 , & V_150 ) ;
F_38 ( & V_149 -> V_109 . V_116 , & V_151 ) ;
if ( ! V_150 || ! V_151 ) {
V_1 = - V_28 ;
goto V_141;
}
V_147 -> V_150 = V_150 ;
V_147 -> V_151 = V_151 ;
V_147 -> V_150 -= V_147 -> V_154 ;
V_147 -> V_151 -= V_147 -> V_155 ;
V_147 -> V_154 = V_150 ;
V_147 -> V_155 = V_151 ;
V_141:
F_51 ( & V_140 ) ;
return V_1 ;
}
int F_53 ( int V_156 , struct V_157 * V_158 )
{
struct V_24 * V_24 = F_25 ( V_70 , V_156 ) ;
struct V_127 * V_159 ;
int V_1 = 0 ;
if ( ! V_24 ) {
F_10 ( L_26 , V_156 ) ;
return - V_40 ;
}
V_159 = & V_24 -> V_108 [ V_160 ] ;
F_50 ( & V_140 ) ;
if ( V_159 -> V_109 . V_116 . V_112 == V_113 ) {
V_1 = F_1 () ;
if ( V_1 )
goto V_161;
}
F_44 ( & V_159 -> V_109 . V_116 , V_158 -> V_162 ) ;
if ( V_159 -> V_109 . V_116 . V_112 == V_113 ) {
if ( F_7 ( V_163 ) < 0 )
V_1 = - V_2 ;
}
V_161:
F_51 ( & V_140 ) ;
return V_1 ;
}
