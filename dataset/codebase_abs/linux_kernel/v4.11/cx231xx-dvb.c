static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( V_2 -> V_2 ,
L_10 , V_4 , V_5 ) ;
} else {
F_2 ( V_2 -> V_2 ,
L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static inline int F_3 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_15 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_16 & V_17 )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
for ( V_15 = 0 ; V_15 < V_14 -> V_18 ; V_15 ++ ) {
int V_4 = V_14 -> V_19 [ V_15 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_14 -> V_19 [ V_15 ] . V_4 != - V_11 )
continue;
}
F_4 ( & V_2 -> V_20 -> V_21 ,
V_14 -> V_22 +
V_14 -> V_19 [ V_15 ] . V_23 ,
V_14 -> V_19 [ V_15 ] . V_24 ) ;
}
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_16 & V_17 )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
F_4 ( & V_2 -> V_20 -> V_21 ,
V_14 -> V_22 , V_14 -> V_24 ) ;
return 0 ;
}
static int F_6 ( struct V_25 * V_20 )
{
int V_26 ;
struct V_1 * V_2 = V_20 -> V_27 . V_28 ;
if ( V_2 -> V_29 ) {
F_2 ( V_2 -> V_2 , L_12 ) ;
F_7 ( V_2 , V_30 , 4 ) ;
V_26 = F_8 ( V_2 , V_31 ) ;
if ( V_26 < 0 )
return V_26 ;
V_2 -> V_32 = 1 ;
return F_9 ( V_2 , V_33 ,
V_34 ,
V_2 -> V_35 . V_36 ,
F_3 ) ;
} else {
F_2 ( V_2 -> V_2 , L_13 ) ;
F_7 ( V_2 , V_30 , 0 ) ;
V_26 = F_8 ( V_2 , V_31 ) ;
if ( V_26 < 0 )
return V_26 ;
V_2 -> V_32 = 1 ;
return F_10 ( V_2 , V_33 ,
V_34 ,
V_2 -> V_35 . V_36 ,
F_5 ) ;
}
}
static int F_11 ( struct V_25 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_27 . V_28 ;
if ( V_2 -> V_29 )
F_12 ( V_2 ) ;
else
F_13 ( V_2 ) ;
F_8 ( V_2 , V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_21 = V_39 -> V_21 ;
struct V_25 * V_20 = V_21 -> V_28 ;
int V_26 , V_41 ;
if ( ! V_21 -> V_42 . V_43 )
return - V_44 ;
F_15 ( & V_20 -> V_45 ) ;
V_20 -> V_46 ++ ;
V_26 = V_20 -> V_46 ;
if ( V_20 -> V_46 == 1 ) {
V_41 = F_6 ( V_20 ) ;
if ( V_41 < 0 )
V_26 = V_41 ;
}
F_16 ( & V_20 -> V_45 ) ;
return V_26 ;
}
static int F_17 ( struct V_38 * V_39 )
{
struct V_40 * V_21 = V_39 -> V_21 ;
struct V_25 * V_20 = V_21 -> V_28 ;
int V_47 = 0 ;
F_15 ( & V_20 -> V_45 ) ;
V_20 -> V_46 -- ;
if ( 0 == V_20 -> V_46 )
V_47 = F_11 ( V_20 ) ;
F_16 ( & V_20 -> V_45 ) ;
return V_47 ;
}
static int F_18 ( struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_49 -> V_20 -> V_28 ;
if ( V_50 )
return F_8 ( V_2 , V_31 ) ;
else
return F_8 ( V_2 , V_37 ) ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_51 )
{
if ( ( V_2 -> V_20 != NULL ) && ( V_2 -> V_20 -> V_43 != NULL ) ) {
struct V_52 * V_53 = & V_2 -> V_20 -> V_43 -> V_54 . V_55 ;
if ( V_53 -> V_56 != NULL ) {
struct V_57 V_58 ;
V_58 . V_59 = V_51 ;
V_58 . V_60 = V_2 -> V_61 ;
V_58 . V_62 = 0 ;
V_53 -> V_56 ( V_2 -> V_20 -> V_43 , & V_58 ) ;
}
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( ( V_2 -> V_20 != NULL ) && ( V_2 -> V_20 -> V_43 != NULL ) ) {
struct V_52 * V_53 = & V_2 -> V_20 -> V_43 -> V_54 . V_55 ;
if ( V_53 -> V_63 != NULL && ! V_2 -> V_64 ) {
F_2 ( V_2 -> V_2 ,
L_14 ) ;
V_4 = V_53 -> V_63 ( V_2 -> V_20 -> V_43 ) ;
if ( V_4 == 0 ) {
V_2 -> V_64 = 1 ;
F_2 ( V_2 -> V_2 ,
L_15 ) ;
} else {
V_2 -> V_64 = 0 ;
F_2 ( V_2 -> V_2 ,
L_16 ) ;
}
}
}
return V_4 ;
}
static int F_21 ( struct V_25 * V_20 ,
struct V_65 * V_65 ,
struct V_1 * V_2 , struct V_66 * V_66 )
{
int V_67 ;
F_22 ( & V_20 -> V_45 ) ;
V_67 = F_23 ( & V_20 -> V_27 , V_2 -> V_68 , V_65 , V_66 ,
V_69 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_17 ,
V_2 -> V_68 , V_67 ) ;
goto V_70;
}
F_25 ( & V_20 -> V_27 , V_2 -> V_71 ) ;
V_20 -> V_43 -> V_54 . V_72 = F_18 ;
V_20 -> V_27 . V_28 = V_2 ;
V_67 = F_26 ( & V_20 -> V_27 , V_20 -> V_43 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_18 ,
V_2 -> V_68 , V_67 ) ;
goto V_73;
}
V_20 -> V_21 . V_42 . V_74 =
V_75 | V_76 |
V_77 ;
V_20 -> V_21 . V_28 = V_20 ;
V_20 -> V_21 . V_78 = 256 ;
V_20 -> V_21 . V_79 = 256 ;
V_20 -> V_21 . F_14 = F_14 ;
V_20 -> V_21 . F_17 = F_17 ;
V_67 = F_27 ( & V_20 -> V_21 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_19 ,
V_2 -> V_68 , V_67 ) ;
goto V_80;
}
V_20 -> V_81 . V_78 = 256 ;
V_20 -> V_81 . V_21 = & V_20 -> V_21 . V_42 ;
V_20 -> V_81 . V_74 = 0 ;
V_67 = F_28 ( & V_20 -> V_81 , & V_20 -> V_27 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_20 ,
V_2 -> V_68 , V_67 ) ;
goto V_82;
}
V_20 -> V_83 . V_84 = V_85 ;
V_67 = V_20 -> V_21 . V_42 . V_86 ( & V_20 -> V_21 . V_42 , & V_20 -> V_83 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_21 ,
V_2 -> V_68 , V_67 ) ;
goto V_87;
}
V_20 -> V_88 . V_84 = V_89 ;
V_67 = V_20 -> V_21 . V_42 . V_86 ( & V_20 -> V_21 . V_42 , & V_20 -> V_88 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_22 ,
V_2 -> V_68 , V_67 ) ;
goto V_90;
}
V_67 = V_20 -> V_21 . V_42 . V_91 ( & V_20 -> V_21 . V_42 , & V_20 -> V_83 ) ;
if ( V_67 < 0 ) {
F_24 ( V_2 -> V_2 ,
L_23 ,
V_2 -> V_68 , V_67 ) ;
goto V_92;
}
F_29 ( & V_20 -> V_27 , & V_20 -> V_93 , & V_20 -> V_21 . V_42 ) ;
V_67 = F_30 ( & V_20 -> V_27 ,
V_2 -> V_94 == V_95 ) ;
if ( V_67 < 0 )
goto V_96;
return 0 ;
V_96:
F_31 ( & V_20 -> V_93 ) ;
V_92:
V_20 -> V_21 . V_42 . V_97 ( & V_20 -> V_21 . V_42 , & V_20 -> V_88 ) ;
V_90:
V_20 -> V_21 . V_42 . V_97 ( & V_20 -> V_21 . V_42 , & V_20 -> V_83 ) ;
V_87:
F_32 ( & V_20 -> V_81 ) ;
V_82:
F_33 ( & V_20 -> V_21 ) ;
V_80:
F_34 ( V_20 -> V_43 ) ;
V_73:
F_35 ( V_20 -> V_43 ) ;
F_36 ( & V_20 -> V_27 ) ;
V_70:
return V_67 ;
}
static void F_37 ( struct V_25 * V_20 )
{
struct V_98 * V_99 ;
F_31 ( & V_20 -> V_93 ) ;
V_20 -> V_21 . V_42 . V_97 ( & V_20 -> V_21 . V_42 , & V_20 -> V_88 ) ;
V_20 -> V_21 . V_42 . V_97 ( & V_20 -> V_21 . V_42 , & V_20 -> V_83 ) ;
F_32 ( & V_20 -> V_81 ) ;
F_33 ( & V_20 -> V_21 ) ;
V_99 = V_20 -> V_100 ;
if ( V_99 ) {
F_38 ( V_99 -> V_2 . V_101 -> V_102 ) ;
F_39 ( V_99 ) ;
}
V_99 = V_20 -> V_103 ;
if ( V_99 ) {
F_38 ( V_99 -> V_2 . V_101 -> V_102 ) ;
F_39 ( V_99 ) ;
}
F_34 ( V_20 -> V_43 ) ;
F_35 ( V_20 -> V_43 ) ;
F_36 ( & V_20 -> V_27 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
struct V_25 * V_20 ;
struct V_104 * V_105 ;
struct V_104 * V_106 ;
if ( ! V_2 -> V_107 . V_108 ) {
return 0 ;
}
V_20 = F_41 ( sizeof( struct V_25 ) , V_109 ) ;
if ( V_20 == NULL ) {
F_42 ( V_2 -> V_2 ,
L_24 ) ;
return - V_110 ;
}
V_2 -> V_20 = V_20 ;
V_2 -> F_19 = F_19 ;
V_2 -> F_20 = F_20 ;
V_105 = F_43 ( V_2 , V_2 -> V_107 . V_111 ) ;
V_106 = F_43 ( V_2 , V_2 -> V_107 . V_112 ) ;
F_15 ( & V_2 -> V_45 ) ;
F_8 ( V_2 , V_31 ) ;
F_44 ( V_2 ) ;
switch ( V_2 -> V_113 ) {
case V_114 :
case V_115 :
V_2 -> V_20 -> V_43 = F_45 ( V_116 ,
& V_117 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_25 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
if ( ! F_45 ( V_121 , V_2 -> V_20 -> V_43 ,
V_105 ,
& V_122 ) ) {
V_67 = - V_44 ;
goto V_118;
}
break;
case V_123 :
case V_124 :
V_2 -> V_20 -> V_43 = F_45 ( V_125 ,
& V_126 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_26 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
if ( ! F_45 ( V_121 , V_2 -> V_20 -> V_43 ,
V_105 ,
& V_127 ) ) {
V_67 = - V_44 ;
goto V_118;
}
break;
case V_128 :
V_2 -> V_20 -> V_43 = F_45 ( V_116 ,
& V_117 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_25 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
if ( ! F_45 ( V_129 , V_2 -> V_20 -> V_43 ,
0x60 , V_105 ,
& V_130 ) ) {
V_67 = - V_44 ;
goto V_118;
}
break;
case V_131 :
case V_132 :
V_2 -> V_20 -> V_43 = F_45 ( V_125 ,
& V_133 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_26 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
if ( ! F_45 ( V_129 , V_2 -> V_20 -> V_43 ,
0x60 , V_105 ,
& V_130 ) ) {
V_67 = - V_44 ;
goto V_118;
}
break;
case V_134 :
F_42 ( V_2 -> V_2 ,
L_27 ,
V_135 , F_47 ( V_105 ) ) ;
V_2 -> V_20 -> V_43 = F_45 ( V_136 ,
& V_137 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_28 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
F_45 ( V_129 , V_2 -> V_20 -> V_43 ,
0x60 , V_105 ,
& V_138 ) ;
break;
case V_139 :
{
struct V_98 * V_99 ;
struct V_140 V_141 ;
struct V_142 V_143 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_49 = & V_2 -> V_20 -> V_43 ;
V_143 . V_144 = V_145 ,
V_143 . V_146 = 16000000 ,
memset ( & V_141 , 0 , sizeof( struct V_140 ) ) ;
F_48 ( V_141 . type , L_29 , V_147 ) ;
V_141 . V_148 = 0x64 ;
V_141 . V_149 = & V_143 ;
F_49 ( V_141 . type ) ;
V_99 = F_50 ( V_106 , & V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL || V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_30 ) ;
V_67 = - V_44 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_20 -> V_103 = V_99 ;
V_2 -> V_20 -> V_43 -> V_54 . V_151 = NULL ;
V_20 -> V_43 -> V_119 = V_120 ;
F_45 ( V_129 , V_2 -> V_20 -> V_43 ,
0x60 ,
V_105 ,
& V_138 ) ;
V_2 -> F_20 = NULL ;
break;
}
case V_152 :
{
struct V_98 * V_99 ;
struct V_140 V_141 ;
struct V_142 V_143 ;
struct V_153 V_153 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_49 = & V_2 -> V_20 -> V_43 ;
V_143 . V_144 = V_154 ,
V_143 . V_146 = 24000000 ,
memset ( & V_141 , 0 , sizeof( struct V_140 ) ) ;
F_48 ( V_141 . type , L_29 , V_147 ) ;
V_141 . V_148 = 0x64 ;
V_141 . V_149 = & V_143 ;
F_49 ( V_141 . type ) ;
V_99 = F_50 ( V_106 , & V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL || V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_30 ) ;
V_67 = - V_44 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_20 -> V_103 = V_99 ;
memset ( & V_141 , 0 , sizeof( struct V_140 ) ) ;
V_2 -> V_20 -> V_43 -> V_54 . V_151 = NULL ;
V_20 -> V_43 -> V_119 = V_120 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_49 = V_2 -> V_20 -> V_43 ;
#ifdef F_52
V_153 . V_155 = V_2 -> V_71 ;
#endif
V_153 . V_156 = 1 ;
V_153 . V_157 = true ;
F_48 ( V_141 . type , L_31 , V_147 ) ;
V_141 . V_148 = 0x60 ;
V_141 . V_149 = & V_153 ;
F_49 ( L_31 ) ;
V_99 = F_50 (
V_105 ,
& V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL ) {
F_35 ( V_2 -> V_20 -> V_43 ) ;
V_67 = - V_150 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
F_35 ( V_2 -> V_20 -> V_43 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_2 -> F_20 = NULL ;
V_2 -> V_20 -> V_100 = V_99 ;
break;
}
case V_158 :
{
struct V_98 * V_99 ;
struct V_140 V_141 ;
struct V_153 V_153 ;
memset ( & V_141 , 0 , sizeof( struct V_140 ) ) ;
V_2 -> V_20 -> V_43 = F_45 ( V_159 ,
& V_160 ,
V_106
) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_32 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_2 -> V_20 -> V_43 -> V_54 . V_151 = NULL ;
V_20 -> V_43 -> V_119 = V_120 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_49 = V_2 -> V_20 -> V_43 ;
#ifdef F_52
V_153 . V_155 = V_2 -> V_71 ;
#endif
V_153 . V_156 = 1 ;
V_153 . V_157 = true ;
F_48 ( V_141 . type , L_31 , V_147 ) ;
V_141 . V_148 = 0x60 ;
V_141 . V_149 = & V_153 ;
F_49 ( L_31 ) ;
V_99 = F_50 (
V_105 ,
& V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL ) {
F_35 ( V_2 -> V_20 -> V_43 ) ;
V_67 = - V_150 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
F_35 ( V_2 -> V_20 -> V_43 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_2 -> F_20 = NULL ;
V_2 -> V_20 -> V_100 = V_99 ;
break;
}
case V_161 :
case V_162 :
F_42 ( V_2 -> V_2 ,
L_33 ,
V_135 , F_47 ( V_105 ) ) ;
V_2 -> V_20 -> V_43 = F_45 ( V_163 ,
& V_164 ,
V_106 ) ;
if ( V_2 -> V_20 -> V_43 == NULL ) {
F_46 ( V_2 -> V_2 ,
L_34 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_20 -> V_43 -> V_119 = V_120 ;
F_45 ( V_129 , V_2 -> V_20 -> V_43 ,
0x60 , V_105 ,
& V_165 ) ;
break;
case V_166 :
{
struct V_153 V_153 = {} ;
struct V_167 V_167 = {} ;
struct V_140 V_141 = {} ;
struct V_98 * V_99 ;
struct V_104 * V_27 ;
V_167 . V_168 = V_169 ;
V_167 . V_49 = & V_2 -> V_20 -> V_43 ;
V_167 . V_104 = & V_27 ;
V_167 . V_170 = true ;
F_48 ( V_141 . type , L_35 , sizeof( V_141 . type ) ) ;
V_141 . V_148 = V_2 -> V_107 . V_171 ;
V_141 . V_149 = & V_167 ;
F_49 ( V_141 . type ) ;
V_99 = F_50 ( V_106 , & V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL ) {
V_67 = - V_150 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_20 -> V_103 = V_99 ;
V_153 . V_49 = V_2 -> V_20 -> V_43 ;
#ifdef F_52
V_153 . V_155 = V_2 -> V_71 ;
#endif
V_153 . V_156 = 1 ;
V_153 . V_157 = false ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_48 ( V_141 . type , L_31 , sizeof( V_141 . type ) ) ;
V_141 . V_148 = V_2 -> V_107 . V_172 ;
V_141 . V_149 = & V_153 ;
F_49 ( V_141 . type ) ;
V_99 = F_50 ( V_105 , & V_141 ) ;
if ( V_99 == NULL || V_99 -> V_2 . V_101 == NULL ) {
F_38 ( V_20 -> V_103 -> V_2 . V_101 -> V_102 ) ;
F_39 ( V_20 -> V_103 ) ;
V_67 = - V_150 ;
goto V_118;
}
if ( ! F_51 ( V_99 -> V_2 . V_101 -> V_102 ) ) {
F_39 ( V_99 ) ;
F_38 ( V_20 -> V_103 -> V_2 . V_101 -> V_102 ) ;
F_39 ( V_20 -> V_103 ) ;
V_67 = - V_150 ;
goto V_118;
}
V_2 -> F_20 = NULL ;
V_2 -> V_20 -> V_100 = V_99 ;
break;
}
default:
F_46 ( V_2 -> V_2 ,
L_36 ,
V_2 -> V_68 ) ;
break;
}
if ( NULL == V_20 -> V_43 ) {
F_46 ( V_2 -> V_2 ,
L_37 , V_2 -> V_68 ) ;
V_67 = - V_44 ;
goto V_118;
}
V_67 = F_21 ( V_20 , V_173 , V_2 , V_2 -> V_2 ) ;
if ( V_67 < 0 )
goto V_118;
F_42 ( V_2 -> V_2 , L_38 ) ;
V_41:
F_8 ( V_2 , V_37 ) ;
F_16 ( & V_2 -> V_45 ) ;
return V_67 ;
V_118:
F_53 ( V_20 ) ;
V_2 -> V_20 = NULL ;
goto V_41;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_107 . V_108 ) {
return 0 ;
}
if ( V_2 -> V_20 ) {
F_37 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
}
return 0 ;
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_174 ) ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_174 ) ;
}
