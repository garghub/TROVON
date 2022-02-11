static struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_5 ;
char * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 = NULL ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( V_3 -> V_11 [ V_12 ] ) {
V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
V_9 = F_4 ( V_10 , V_6 ) ;
} else if ( ( V_3 -> V_11 [ V_13 ] ) &&
( V_3 -> V_11 [ V_14 ] ) ) {
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 )
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
}
return V_9 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_15 * V_17 ;
void * V_18 ;
int V_19 = - V_20 ;
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_18 = F_10 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
& V_27 , 0 , V_28 ) ;
if ( ! V_18 ) {
V_19 = - V_29 ;
goto V_30;
}
F_11 ( V_17 , V_18 ) ;
return F_12 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_14 ( struct V_31 * V_32 ,
struct V_2 * V_3 ,
struct V_7 * V_8 ,
T_2 V_33 )
{
struct V_15 * V_17 ;
int V_19 ;
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 )
return - V_23 ;
V_19 = F_15 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_34 , V_8 , V_33 ) ;
if ( V_19 >= 0 ) {
V_19 = F_16 ( V_32 , V_17 , 0 , 0 , V_35 ) ;
if ( V_19 == - V_36 )
V_19 = 0 ;
return V_19 ;
}
F_13 ( V_17 ) ;
return V_19 ;
}
static int F_17 ( struct V_31 * V_32 ,
struct V_2 * V_3 ,
struct V_1 * V_9 ,
T_2 V_33 )
{
struct V_15 * V_17 ;
int V_19 ;
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 )
return - V_23 ;
V_19 = F_18 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_34 , V_9 , V_33 ) ;
if ( V_19 >= 0 ) {
V_19 = F_16 ( V_32 , V_17 , 0 , 0 , V_35 ) ;
if ( V_19 == - V_36 )
V_19 = 0 ;
return V_19 ;
}
F_13 ( V_17 ) ;
return V_19 ;
}
static int F_19 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_37 ;
int V_38 ;
int V_39 ;
int V_19 = 0 ;
struct V_40 V_41 = { 0 , } ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
if ( ! V_3 -> V_11 [ V_43 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_37 = F_5 ( V_3 -> V_11 [ V_43 ] ) ;
if ( ! V_3 -> V_11 [ V_44 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_38 = F_20 ( V_3 -> V_11 [ V_44 ] ) ;
if ( ! V_3 -> V_11 [ V_45 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_46 = F_21 ( V_3 -> V_11 [ V_45 ] ) ;
V_39 = - 1 ;
if ( V_3 -> V_11 [ V_47 ] ) {
V_39 = F_5 ( V_3 -> V_11 [ V_47 ] ) ;
} else {
#if F_22 ( V_48 )
if ( V_3 -> V_11 [ V_49 ] &&
V_3 -> V_11 [ V_50 ] ) {
V_41 . V_51 = F_3 (
V_3 -> V_11 [ V_49 ] ) ;
V_41 . V_52 = F_3 (
V_3 -> V_11 [ V_50 ] ) ;
} else
#endif
if ( V_3 -> V_11 [ V_53 ] &&
V_3 -> V_11 [ V_54 ] ) {
V_41 . V_55 . V_56 = F_23 (
V_3 -> V_11 [ V_53 ] ) ;
V_41 . V_57 . V_56 = F_23 (
V_3 -> V_11 [ V_54 ] ) ;
} else {
V_19 = - V_42 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_58 ] )
V_41 . V_59 = F_21 ( V_3 -> V_11 [ V_58 ] ) ;
if ( V_3 -> V_11 [ V_60 ] )
V_41 . V_61 = F_21 ( V_3 -> V_11 [ V_60 ] ) ;
V_41 . V_62 = F_24 (
V_3 -> V_11 [ V_63 ] ) ;
#if F_22 ( V_48 )
V_41 . V_64 = F_24 (
V_3 -> V_11 [ V_65 ] ) ;
V_41 . V_66 = F_24 (
V_3 -> V_11 [ V_67 ] ) ;
#endif
}
if ( V_3 -> V_11 [ V_68 ] )
V_41 . V_69 = F_5 ( V_3 -> V_11 [ V_68 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 != NULL ) {
V_19 = - V_70 ;
goto V_24;
}
V_19 = - V_42 ;
switch ( V_41 . V_46 ) {
case V_71 :
case V_72 :
V_19 = F_25 ( V_10 , V_39 , V_38 , V_4 ,
V_37 , & V_41 , & V_8 ) ;
break;
}
if ( V_19 >= 0 )
V_19 = F_14 ( & V_27 , V_3 ,
V_8 , V_73 ) ;
V_24:
return V_19 ;
}
static int F_26 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
F_14 ( & V_27 , V_3 ,
V_8 , V_75 ) ;
( void ) F_27 ( V_8 ) ;
V_24:
return V_19 ;
}
static int F_28 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_68 ] )
V_8 -> V_69 = F_5 ( V_3 -> V_11 [ V_68 ] ) ;
V_19 = F_14 ( & V_27 , V_3 ,
V_8 , V_76 ) ;
V_24:
return V_19 ;
}
static int F_15 ( struct V_15 * V_16 , T_1 V_77 , T_1 V_78 , int V_79 ,
struct V_7 * V_8 , T_2 V_33 )
{
void * V_18 ;
struct V_80 * V_81 ;
struct V_82 * V_83 = NULL ;
struct V_84 * V_85 ;
#if F_22 ( V_48 )
struct V_86 * V_87 = NULL ;
#endif
V_18 = F_10 ( V_16 , V_77 , V_78 , & V_27 , V_79 , V_33 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_29 ( V_16 , V_44 , V_8 -> V_88 ) ||
F_30 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_30 ( V_16 , V_43 , V_8 -> V_37 ) ||
F_30 ( V_16 , V_68 , V_8 -> V_69 ) ||
F_31 ( V_16 , V_45 , V_8 -> V_46 ) )
goto V_89;
V_81 = F_32 ( V_16 , V_90 ) ;
if ( V_81 == NULL )
goto V_89;
if ( F_33 ( V_16 , V_91 ,
F_34 ( & V_8 -> V_92 . V_93 ) ,
V_94 ) ||
F_33 ( V_16 , V_95 ,
F_34 ( & V_8 -> V_92 . V_96 ) ,
V_94 ) ||
F_33 ( V_16 , V_97 ,
F_34 ( & V_8 -> V_92 . V_98 ) ,
V_94 ) ||
F_33 ( V_16 , V_99 ,
F_34 ( & V_8 -> V_92 . V_100 ) ,
V_94 ) ||
F_33 ( V_16 , V_101 ,
F_34 ( & V_8 -> V_92 . V_102 ) ,
V_94 ) ||
F_33 ( V_16 , V_103 ,
F_34 ( & V_8 -> V_92 . V_104 ) ,
V_94 ) ||
F_33 ( V_16 , V_105 ,
F_34 ( & V_8 -> V_92 . V_106 ) ,
V_94 ) ||
F_33 ( V_16 , V_107 ,
F_34 ( & V_8 -> V_92 . V_108 ) ,
V_94 ) )
goto V_89;
F_35 ( V_16 , V_81 ) ;
V_83 = V_8 -> V_82 ;
if ( ! V_83 )
goto V_24;
#if F_22 ( V_48 )
if ( V_83 -> V_109 == V_110 )
V_87 = F_36 ( V_83 ) ;
#endif
V_85 = F_37 ( V_83 ) ;
switch ( V_8 -> V_46 ) {
case V_71 :
switch ( V_83 -> V_109 ) {
case V_111 :
if ( F_29 ( V_16 , V_63 , ! V_83 -> V_112 ) )
goto V_89;
break;
#if F_22 ( V_48 )
case V_110 :
if ( F_38 ( V_83 ) &&
F_39 ( V_16 , V_65 ) )
goto V_89;
if ( F_40 ( V_83 ) &&
F_39 ( V_16 , V_67 ) )
goto V_89;
break;
#endif
}
if ( F_31 ( V_16 , V_58 , F_41 ( V_85 -> V_113 ) ) ||
F_31 ( V_16 , V_60 , F_41 ( V_85 -> V_114 ) ) )
goto V_89;
case V_72 :
#if F_22 ( V_48 )
if ( V_87 ) {
if ( F_42 ( V_16 , V_49 ,
& V_87 -> V_115 ) ||
F_42 ( V_16 , V_50 ,
& V_83 -> V_116 ) )
goto V_89;
} else
#endif
if ( F_43 ( V_16 , V_53 ,
V_85 -> V_117 ) ||
F_43 ( V_16 , V_54 ,
V_85 -> V_118 ) )
goto V_89;
break;
}
V_24:
F_11 ( V_16 , V_18 ) ;
return 0 ;
V_89:
F_44 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_45 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
struct V_15 * V_17 ;
T_1 V_4 ;
int V_19 = - V_20 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_15 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_34 , V_8 , V_119 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( V_10 , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_46 ( struct V_15 * V_16 , struct V_120 * V_121 )
{
int V_122 = V_121 -> args [ 0 ] ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_47 ( V_16 -> V_83 ) ;
for (; ; ) {
V_8 = F_48 ( V_10 , V_122 ) ;
if ( V_8 == NULL )
goto V_24;
if ( F_15 ( V_16 , F_49 ( V_121 -> V_16 ) . V_77 ,
V_121 -> V_123 -> V_124 , V_125 ,
V_8 , V_119 ) < 0 )
goto V_24;
V_122 ++ ;
}
V_24:
V_121 -> args [ 0 ] = V_122 ;
return V_16 -> V_126 ;
}
static int F_50 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_127 ;
int V_19 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_128 V_41 = { 0 , } ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( ! V_8 ) {
V_19 = - V_74 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_13 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 ) {
V_19 = - V_70 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_129 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_127 = F_5 ( V_3 -> V_11 [ V_129 ] ) ;
if ( ! V_3 -> V_11 [ V_130 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_131 = F_21 ( V_3 -> V_11 [ V_130 ] ) ;
if ( V_41 . V_131 >= V_132 ) {
V_19 = - V_42 ;
goto V_24;
}
if ( V_8 -> V_88 > 2 ) {
if ( V_3 -> V_11 [ V_133 ] )
V_41 . V_134 = F_21 ( V_3 -> V_11 [ V_133 ] ) ;
if ( V_3 -> V_11 [ V_135 ] )
V_41 . V_136 = F_20 ( V_3 -> V_11 [ V_135 ] ) ;
V_41 . V_137 = V_138 ;
if ( V_3 -> V_11 [ V_139 ] )
V_41 . V_137 = F_20 ( V_3 -> V_11 [ V_139 ] ) ;
V_41 . V_140 = 4 ;
if ( V_3 -> V_11 [ V_141 ] )
V_41 . V_140 = F_20 ( V_3 -> V_11 [ V_141 ] ) ;
if ( V_3 -> V_11 [ V_142 ] ) {
T_3 V_126 = F_51 ( V_3 -> V_11 [ V_142 ] ) ;
if ( V_126 > 8 ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_143 = V_126 ;
memcpy ( & V_41 . V_144 [ 0 ] , F_3 ( V_3 -> V_11 [ V_142 ] ) , V_126 ) ;
}
if ( V_3 -> V_11 [ V_145 ] ) {
T_3 V_126 = F_51 ( V_3 -> V_11 [ V_145 ] ) ;
if ( V_126 > 8 ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_146 = V_126 ;
memcpy ( & V_41 . V_147 [ 0 ] , F_3 ( V_3 -> V_11 [ V_145 ] ) , V_126 ) ;
}
if ( V_3 -> V_11 [ V_12 ] )
V_41 . V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
if ( V_3 -> V_11 [ V_148 ] )
V_41 . V_149 = F_21 ( V_3 -> V_11 [ V_148 ] ) ;
}
if ( V_3 -> V_11 [ V_68 ] )
V_41 . V_69 = F_5 ( V_3 -> V_11 [ V_68 ] ) ;
if ( V_3 -> V_11 [ V_150 ] )
V_41 . V_151 = F_20 ( V_3 -> V_11 [ V_150 ] ) ;
if ( V_3 -> V_11 [ V_152 ] )
V_41 . V_153 = F_20 ( V_3 -> V_11 [ V_152 ] ) ;
if ( V_3 -> V_11 [ V_154 ] )
V_41 . V_155 = F_20 ( V_3 -> V_11 [ V_154 ] ) ;
if ( V_3 -> V_11 [ V_156 ] )
V_41 . V_157 = F_52 ( V_3 -> V_11 [ V_156 ] ) ;
if ( V_3 -> V_11 [ V_158 ] )
V_41 . V_159 = F_21 ( V_3 -> V_11 [ V_158 ] ) ;
if ( V_3 -> V_11 [ V_160 ] )
V_41 . V_161 = F_21 ( V_3 -> V_11 [ V_160 ] ) ;
#ifdef F_53
if ( V_162 [ V_41 . V_131 ] == NULL ) {
F_54 () ;
F_55 ( L_1 , V_41 . V_131 ) ;
F_56 () ;
}
#endif
if ( ( V_162 [ V_41 . V_131 ] == NULL ) ||
( V_162 [ V_41 . V_131 ] -> V_163 == NULL ) ) {
V_19 = - V_164 ;
goto V_24;
}
switch ( V_41 . V_131 ) {
case V_165 :
break;
case V_166 :
if ( ! V_3 -> V_11 [ V_148 ] ) {
V_19 = - V_42 ;
goto V_24;
}
break;
case V_167 :
break;
case V_168 :
case V_169 :
break;
case V_170 :
default:
V_19 = - V_164 ;
break;
}
V_19 = - V_164 ;
if ( V_162 [ V_41 . V_131 ] -> V_163 )
V_19 = ( * V_162 [ V_41 . V_131 ] -> V_163 ) ( V_10 , V_4 ,
V_5 , V_127 , & V_41 ) ;
if ( V_19 >= 0 ) {
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 )
V_19 = F_17 ( & V_27 , V_3 , V_9 ,
V_171 ) ;
}
V_24:
return V_19 ;
}
static int F_57 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
T_3 V_131 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
F_17 ( & V_27 , V_3 ,
V_9 , V_172 ) ;
V_131 = V_9 -> V_173 ;
if ( V_131 < V_132 )
if ( V_162 [ V_131 ] && V_162 [ V_131 ] -> V_174 )
V_19 = ( * V_162 [ V_131 ] -> V_174 ) ( V_9 ) ;
V_24:
return V_19 ;
}
static int F_58 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_68 ] )
V_9 -> V_69 = F_5 ( V_3 -> V_11 [ V_68 ] ) ;
if ( V_3 -> V_11 [ V_135 ] )
V_9 -> V_136 = F_20 ( V_3 -> V_11 [ V_135 ] ) ;
if ( V_3 -> V_11 [ V_150 ] )
V_9 -> V_151 = F_20 ( V_3 -> V_11 [ V_150 ] ) ;
if ( V_3 -> V_11 [ V_152 ] ) {
V_9 -> V_153 = F_20 ( V_3 -> V_11 [ V_152 ] ) ;
F_59 ( V_9 , V_9 -> V_8 -> V_88 ) ;
}
if ( V_3 -> V_11 [ V_154 ] )
V_9 -> V_155 = F_20 ( V_3 -> V_11 [ V_154 ] ) ;
if ( V_3 -> V_11 [ V_156 ] )
V_9 -> V_157 = F_52 ( V_3 -> V_11 [ V_156 ] ) ;
if ( V_3 -> V_11 [ V_158 ] )
V_9 -> V_159 = F_21 ( V_3 -> V_11 [ V_158 ] ) ;
if ( V_3 -> V_11 [ V_160 ] )
V_9 -> V_161 = F_21 ( V_3 -> V_11 [ V_160 ] ) ;
V_19 = F_17 ( & V_27 , V_3 ,
V_9 , V_175 ) ;
V_24:
return V_19 ;
}
static int F_18 ( struct V_15 * V_16 , T_1 V_77 , T_1 V_78 , int V_79 ,
struct V_1 * V_9 , T_2 V_33 )
{
void * V_18 ;
struct V_80 * V_81 ;
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_82 * V_83 = NULL ;
V_83 = V_8 -> V_82 ;
V_18 = F_10 ( V_16 , V_77 , V_78 , & V_27 , V_79 , V_33 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_30 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_30 ( V_16 , V_13 , V_9 -> V_5 ) ||
F_30 ( V_16 , V_43 , V_8 -> V_37 ) ||
F_30 ( V_16 , V_129 ,
V_9 -> V_127 ) ||
F_30 ( V_16 , V_68 , V_9 -> V_69 ) ||
F_31 ( V_16 , V_130 , V_9 -> V_173 ) ||
F_31 ( V_16 , V_158 , V_9 -> V_159 ) ||
( V_9 -> V_161 &&
F_31 ( V_16 , V_160 , V_9 -> V_161 ) ) )
goto V_89;
if ( ( V_9 -> V_6 [ 0 ] &&
F_60 ( V_16 , V_12 , V_9 -> V_6 ) ) ||
( V_9 -> V_143 &&
F_61 ( V_16 , V_142 , V_9 -> V_143 ,
& V_9 -> V_144 [ 0 ] ) ) ||
( V_9 -> V_146 &&
F_61 ( V_16 , V_145 , V_9 -> V_146 ,
& V_9 -> V_147 [ 0 ] ) ) ||
F_29 ( V_16 , V_150 , V_9 -> V_151 ) ||
F_29 ( V_16 , V_152 , V_9 -> V_153 ) ||
F_29 ( V_16 , V_154 , V_9 -> V_155 ) ||
#ifdef F_62
( ( ( V_83 ) && ( V_83 -> V_176 [ 0 ] || V_83 -> V_176 [ 1 ] ) ) &&
F_29 ( V_16 , V_177 , 1 ) ) ||
#endif
( V_9 -> V_157 &&
F_63 ( V_16 , V_156 ,
V_9 -> V_157 , V_178 ) ) )
goto V_89;
V_81 = F_32 ( V_16 , V_90 ) ;
if ( V_81 == NULL )
goto V_89;
if ( F_33 ( V_16 , V_91 ,
F_34 ( & V_9 -> V_92 . V_93 ) ,
V_94 ) ||
F_33 ( V_16 , V_95 ,
F_34 ( & V_9 -> V_92 . V_96 ) ,
V_94 ) ||
F_33 ( V_16 , V_97 ,
F_34 ( & V_9 -> V_92 . V_98 ) ,
V_94 ) ||
F_33 ( V_16 , V_99 ,
F_34 ( & V_9 -> V_92 . V_100 ) ,
V_94 ) ||
F_33 ( V_16 , V_101 ,
F_34 ( & V_9 -> V_92 . V_102 ) ,
V_94 ) ||
F_33 ( V_16 , V_103 ,
F_34 ( & V_9 -> V_92 . V_104 ) ,
V_94 ) ||
F_33 ( V_16 , V_105 ,
F_34 ( & V_9 -> V_92 . V_106 ) ,
V_94 ) ||
F_33 ( V_16 , V_107 ,
F_34 ( & V_9 -> V_92 . V_108 ) ,
V_94 ) )
goto V_89;
F_35 ( V_16 , V_81 ) ;
F_11 ( V_16 , V_18 ) ;
return 0 ;
V_89:
F_44 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_64 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_15 * V_17 ;
int V_19 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_18 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
0 , V_9 , V_179 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_65 ( struct V_15 * V_16 , struct V_120 * V_121 )
{
struct V_10 * V_10 = F_47 ( V_16 -> V_83 ) ;
struct V_1 * V_9 ;
struct V_7 * V_8 = NULL ;
int V_122 = V_121 -> args [ 0 ] ;
int V_180 = V_121 -> args [ 1 ] ;
for (; ; ) {
if ( V_8 == NULL ) {
V_8 = F_48 ( V_10 , V_122 ) ;
if ( V_8 == NULL )
goto V_24;
}
V_9 = F_66 ( V_8 , V_180 ) ;
if ( V_9 == NULL ) {
V_122 ++ ;
V_8 = NULL ;
V_180 = 0 ;
continue;
}
if ( F_18 ( V_16 , F_49 ( V_121 -> V_16 ) . V_77 ,
V_121 -> V_123 -> V_124 , V_125 ,
V_9 , V_179 ) < 0 )
break;
V_180 ++ ;
}
V_24:
V_121 -> args [ 0 ] = V_122 ;
V_121 -> args [ 1 ] = V_180 ;
return V_16 -> V_126 ;
}
int F_67 ( enum V_181 V_131 , const struct V_162 * V_182 )
{
int V_19 ;
V_19 = - V_42 ;
if ( V_131 >= V_132 )
goto V_183;
F_56 () ;
V_19 = - V_184 ;
if ( V_162 [ V_131 ] )
goto V_24;
V_162 [ V_131 ] = V_182 ;
V_19 = 0 ;
V_24:
F_54 () ;
V_183:
return V_19 ;
}
void F_68 ( enum V_181 V_131 )
{
if ( V_131 < V_132 ) {
F_56 () ;
V_162 [ V_131 ] = NULL ;
F_54 () ;
}
}
static int T_4 F_69 ( void )
{
F_70 ( L_2 ) ;
return F_71 ( & V_27 ) ;
}
static void F_72 ( void )
{
F_73 ( & V_27 ) ;
}
