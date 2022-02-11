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
if ( V_19 >= 0 )
return F_16 ( V_32 , V_17 , 0 , 0 , V_35 ) ;
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
if ( V_19 >= 0 )
return F_16 ( V_32 , V_17 , 0 , 0 , V_35 ) ;
F_13 ( V_17 ) ;
return V_19 ;
}
static int F_19 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_36 ;
int V_37 ;
int V_38 ;
int V_19 = 0 ;
struct V_39 V_40 = { 0 , } ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
if ( ! V_3 -> V_11 [ V_42 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_36 = F_5 ( V_3 -> V_11 [ V_42 ] ) ;
if ( ! V_3 -> V_11 [ V_43 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_37 = F_20 ( V_3 -> V_11 [ V_43 ] ) ;
if ( ! V_3 -> V_11 [ V_44 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_40 . V_45 = F_21 ( V_3 -> V_11 [ V_44 ] ) ;
V_38 = - 1 ;
if ( V_3 -> V_11 [ V_46 ] ) {
V_38 = F_5 ( V_3 -> V_11 [ V_46 ] ) ;
} else {
#if F_22 ( V_47 )
if ( V_3 -> V_11 [ V_48 ] &&
V_3 -> V_11 [ V_49 ] ) {
V_40 . V_50 = F_3 (
V_3 -> V_11 [ V_48 ] ) ;
V_40 . V_51 = F_3 (
V_3 -> V_11 [ V_49 ] ) ;
} else
#endif
if ( V_3 -> V_11 [ V_52 ] &&
V_3 -> V_11 [ V_53 ] ) {
V_40 . V_54 . V_55 = F_23 (
V_3 -> V_11 [ V_52 ] ) ;
V_40 . V_56 . V_55 = F_23 (
V_3 -> V_11 [ V_53 ] ) ;
} else {
V_19 = - V_41 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_57 ] )
V_40 . V_58 = F_21 ( V_3 -> V_11 [ V_57 ] ) ;
if ( V_3 -> V_11 [ V_59 ] )
V_40 . V_60 = F_21 ( V_3 -> V_11 [ V_59 ] ) ;
if ( V_3 -> V_11 [ V_61 ] )
V_40 . V_62 = F_24 ( V_3 -> V_11 [ V_61 ] ) ;
#if F_22 ( V_47 )
if ( V_3 -> V_11 [ V_63 ] )
V_40 . V_64 = F_24 ( V_3 -> V_11 [ V_63 ] ) ;
if ( V_3 -> V_11 [ V_65 ] )
V_40 . V_66 = F_24 ( V_3 -> V_11 [ V_65 ] ) ;
#endif
}
if ( V_3 -> V_11 [ V_67 ] )
V_40 . V_68 = F_5 ( V_3 -> V_11 [ V_67 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 != NULL ) {
V_19 = - V_69 ;
goto V_24;
}
V_19 = - V_41 ;
switch ( V_40 . V_45 ) {
case V_70 :
case V_71 :
V_19 = F_25 ( V_10 , V_38 , V_37 , V_4 ,
V_36 , & V_40 , & V_8 ) ;
break;
}
if ( V_19 >= 0 )
V_19 = F_14 ( & V_27 , V_3 ,
V_8 , V_72 ) ;
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
V_19 = - V_41 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
F_14 ( & V_27 , V_3 ,
V_8 , V_74 ) ;
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
V_19 = - V_41 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_67 ] )
V_8 -> V_68 = F_5 ( V_3 -> V_11 [ V_67 ] ) ;
V_19 = F_14 ( & V_27 , V_3 ,
V_8 , V_75 ) ;
V_24:
return V_19 ;
}
static int F_15 ( struct V_15 * V_16 , T_1 V_76 , T_1 V_77 , int V_78 ,
struct V_7 * V_8 , T_2 V_33 )
{
void * V_18 ;
struct V_79 * V_80 ;
struct V_81 * V_82 = NULL ;
struct V_83 * V_84 ;
#if F_22 ( V_47 )
struct V_85 * V_86 = NULL ;
#endif
V_18 = F_10 ( V_16 , V_76 , V_77 , & V_27 , V_78 , V_33 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_29 ( V_16 , V_43 , V_8 -> V_87 ) ||
F_30 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_30 ( V_16 , V_42 , V_8 -> V_36 ) ||
F_30 ( V_16 , V_67 , V_8 -> V_68 ) ||
F_31 ( V_16 , V_44 , V_8 -> V_45 ) )
goto V_88;
V_80 = F_32 ( V_16 , V_89 ) ;
if ( V_80 == NULL )
goto V_88;
if ( F_33 ( V_16 , V_90 ,
F_34 ( & V_8 -> V_91 . V_92 ) ) ||
F_33 ( V_16 , V_93 ,
F_34 ( & V_8 -> V_91 . V_94 ) ) ||
F_33 ( V_16 , V_95 ,
F_34 ( & V_8 -> V_91 . V_96 ) ) ||
F_33 ( V_16 , V_97 ,
F_34 ( & V_8 -> V_91 . V_98 ) ) ||
F_33 ( V_16 , V_99 ,
F_34 ( & V_8 -> V_91 . V_100 ) ) ||
F_33 ( V_16 , V_101 ,
F_34 ( & V_8 -> V_91 . V_102 ) ) ||
F_33 ( V_16 , V_103 ,
F_34 ( & V_8 -> V_91 . V_104 ) ) ||
F_33 ( V_16 , V_105 ,
F_34 ( & V_8 -> V_91 . V_106 ) ) )
goto V_88;
F_35 ( V_16 , V_80 ) ;
V_82 = V_8 -> V_81 ;
if ( ! V_82 )
goto V_24;
#if F_22 ( V_47 )
if ( V_82 -> V_107 == V_108 )
V_86 = F_36 ( V_82 ) ;
#endif
V_84 = F_37 ( V_82 ) ;
switch ( V_8 -> V_45 ) {
case V_70 :
if ( F_31 ( V_16 , V_57 , F_38 ( V_84 -> V_109 ) ) ||
F_31 ( V_16 , V_59 , F_38 ( V_84 -> V_110 ) ) ||
F_29 ( V_16 , V_61 , ! V_82 -> V_111 ) )
goto V_88;
case V_71 :
#if F_22 ( V_47 )
if ( V_86 ) {
if ( F_39 ( V_16 , V_48 ,
& V_86 -> V_112 ) ||
F_39 ( V_16 , V_49 ,
& V_82 -> V_113 ) )
goto V_88;
} else
#endif
if ( F_40 ( V_16 , V_52 ,
V_84 -> V_114 ) ||
F_40 ( V_16 , V_53 ,
V_84 -> V_115 ) )
goto V_88;
break;
}
V_24:
F_11 ( V_16 , V_18 ) ;
return 0 ;
V_88:
F_41 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_42 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
struct V_15 * V_17 ;
T_1 V_4 ;
int V_19 = - V_20 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_15 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_34 , V_8 , V_116 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( V_10 , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_43 ( struct V_15 * V_16 , struct V_117 * V_118 )
{
int V_119 = V_118 -> args [ 0 ] ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_44 ( V_16 -> V_82 ) ;
for (; ; ) {
V_8 = F_45 ( V_10 , V_119 ) ;
if ( V_8 == NULL )
goto V_24;
if ( F_15 ( V_16 , F_46 ( V_118 -> V_16 ) . V_76 ,
V_118 -> V_120 -> V_121 , V_122 ,
V_8 , V_116 ) < 0 )
goto V_24;
V_119 ++ ;
}
V_24:
V_118 -> args [ 0 ] = V_119 ;
return V_16 -> V_123 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_124 ;
int V_19 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_125 V_40 = { 0 , } ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( ! V_8 ) {
V_19 = - V_73 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_13 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 ) {
V_19 = - V_69 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_126 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_124 = F_5 ( V_3 -> V_11 [ V_126 ] ) ;
if ( ! V_3 -> V_11 [ V_127 ] ) {
V_19 = - V_41 ;
goto V_24;
}
V_40 . V_128 = F_21 ( V_3 -> V_11 [ V_127 ] ) ;
if ( V_40 . V_128 >= V_129 ) {
V_19 = - V_41 ;
goto V_24;
}
if ( V_8 -> V_87 > 2 ) {
if ( V_3 -> V_11 [ V_130 ] )
V_40 . V_131 = F_21 ( V_3 -> V_11 [ V_130 ] ) ;
if ( V_3 -> V_11 [ V_132 ] )
V_40 . V_133 = F_20 ( V_3 -> V_11 [ V_132 ] ) ;
V_40 . V_134 = V_135 ;
if ( V_3 -> V_11 [ V_136 ] )
V_40 . V_134 = F_20 ( V_3 -> V_11 [ V_136 ] ) ;
V_40 . V_137 = 4 ;
if ( V_3 -> V_11 [ V_138 ] )
V_40 . V_137 = F_20 ( V_3 -> V_11 [ V_138 ] ) ;
if ( V_3 -> V_11 [ V_139 ] ) {
T_3 V_123 = F_48 ( V_3 -> V_11 [ V_139 ] ) ;
if ( V_123 > 8 ) {
V_19 = - V_41 ;
goto V_24;
}
V_40 . V_140 = V_123 ;
memcpy ( & V_40 . V_141 [ 0 ] , F_3 ( V_3 -> V_11 [ V_139 ] ) , V_123 ) ;
}
if ( V_3 -> V_11 [ V_142 ] ) {
T_3 V_123 = F_48 ( V_3 -> V_11 [ V_142 ] ) ;
if ( V_123 > 8 ) {
V_19 = - V_41 ;
goto V_24;
}
V_40 . V_143 = V_123 ;
memcpy ( & V_40 . V_144 [ 0 ] , F_3 ( V_3 -> V_11 [ V_142 ] ) , V_123 ) ;
}
if ( V_3 -> V_11 [ V_12 ] )
V_40 . V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
if ( V_3 -> V_11 [ V_145 ] )
V_40 . V_146 = F_21 ( V_3 -> V_11 [ V_145 ] ) ;
}
if ( V_3 -> V_11 [ V_67 ] )
V_40 . V_68 = F_5 ( V_3 -> V_11 [ V_67 ] ) ;
if ( V_3 -> V_11 [ V_147 ] )
V_40 . V_148 = F_20 ( V_3 -> V_11 [ V_147 ] ) ;
if ( V_3 -> V_11 [ V_149 ] )
V_40 . V_150 = F_20 ( V_3 -> V_11 [ V_149 ] ) ;
if ( V_3 -> V_11 [ V_151 ] )
V_40 . V_152 = F_20 ( V_3 -> V_11 [ V_151 ] ) ;
if ( V_3 -> V_11 [ V_153 ] )
V_40 . V_154 = F_49 ( V_3 -> V_11 [ V_153 ] ) ;
if ( V_3 -> V_11 [ V_155 ] )
V_40 . V_156 = F_21 ( V_3 -> V_11 [ V_155 ] ) ;
if ( V_3 -> V_11 [ V_157 ] )
V_40 . V_158 = F_21 ( V_3 -> V_11 [ V_157 ] ) ;
#ifdef F_50
if ( V_159 [ V_40 . V_128 ] == NULL ) {
F_51 () ;
F_52 ( L_1 , V_40 . V_128 ) ;
F_53 () ;
}
#endif
if ( ( V_159 [ V_40 . V_128 ] == NULL ) ||
( V_159 [ V_40 . V_128 ] -> V_160 == NULL ) ) {
V_19 = - V_161 ;
goto V_24;
}
switch ( V_40 . V_128 ) {
case V_162 :
break;
case V_163 :
if ( ! V_3 -> V_11 [ V_145 ] ) {
V_19 = - V_41 ;
goto V_24;
}
break;
case V_164 :
break;
case V_165 :
case V_166 :
break;
case V_167 :
default:
V_19 = - V_161 ;
break;
}
V_19 = - V_161 ;
if ( V_159 [ V_40 . V_128 ] -> V_160 )
V_19 = ( * V_159 [ V_40 . V_128 ] -> V_160 ) ( V_10 , V_4 ,
V_5 , V_124 , & V_40 ) ;
if ( V_19 >= 0 ) {
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 )
V_19 = F_17 ( & V_27 , V_3 , V_9 ,
V_168 ) ;
}
V_24:
return V_19 ;
}
static int F_54 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
T_3 V_128 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
F_17 ( & V_27 , V_3 ,
V_9 , V_169 ) ;
V_128 = V_9 -> V_170 ;
if ( V_128 < V_129 )
if ( V_159 [ V_128 ] && V_159 [ V_128 ] -> V_171 )
V_19 = ( * V_159 [ V_128 ] -> V_171 ) ( V_9 ) ;
V_24:
return V_19 ;
}
static int F_55 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_67 ] )
V_9 -> V_68 = F_5 ( V_3 -> V_11 [ V_67 ] ) ;
if ( V_3 -> V_11 [ V_132 ] )
V_9 -> V_133 = F_20 ( V_3 -> V_11 [ V_132 ] ) ;
if ( V_3 -> V_11 [ V_147 ] )
V_9 -> V_148 = F_20 ( V_3 -> V_11 [ V_147 ] ) ;
if ( V_3 -> V_11 [ V_149 ] ) {
V_9 -> V_150 = F_20 ( V_3 -> V_11 [ V_149 ] ) ;
F_56 ( V_9 , V_9 -> V_8 -> V_87 ) ;
}
if ( V_3 -> V_11 [ V_151 ] )
V_9 -> V_152 = F_20 ( V_3 -> V_11 [ V_151 ] ) ;
if ( V_3 -> V_11 [ V_153 ] )
V_9 -> V_154 = F_49 ( V_3 -> V_11 [ V_153 ] ) ;
if ( V_3 -> V_11 [ V_155 ] )
V_9 -> V_156 = F_21 ( V_3 -> V_11 [ V_155 ] ) ;
if ( V_3 -> V_11 [ V_157 ] )
V_9 -> V_158 = F_21 ( V_3 -> V_11 [ V_157 ] ) ;
V_19 = F_17 ( & V_27 , V_3 ,
V_9 , V_172 ) ;
V_24:
return V_19 ;
}
static int F_18 ( struct V_15 * V_16 , T_1 V_76 , T_1 V_77 , int V_78 ,
struct V_1 * V_9 , T_2 V_33 )
{
void * V_18 ;
struct V_79 * V_80 ;
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_81 * V_82 = NULL ;
V_82 = V_8 -> V_81 ;
V_18 = F_10 ( V_16 , V_76 , V_77 , & V_27 , V_78 , V_33 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_30 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_30 ( V_16 , V_13 , V_9 -> V_5 ) ||
F_30 ( V_16 , V_42 , V_8 -> V_36 ) ||
F_30 ( V_16 , V_126 ,
V_9 -> V_124 ) ||
F_30 ( V_16 , V_67 , V_9 -> V_68 ) ||
F_31 ( V_16 , V_127 , V_9 -> V_170 ) ||
F_31 ( V_16 , V_155 , V_9 -> V_156 ) ||
( V_9 -> V_158 &&
F_31 ( V_16 , V_157 , V_9 -> V_158 ) ) )
goto V_88;
if ( ( V_9 -> V_6 [ 0 ] &&
F_57 ( V_16 , V_12 , V_9 -> V_6 ) ) ||
( V_9 -> V_140 &&
F_58 ( V_16 , V_139 , V_9 -> V_140 ,
& V_9 -> V_141 [ 0 ] ) ) ||
( V_9 -> V_143 &&
F_58 ( V_16 , V_142 , V_9 -> V_143 ,
& V_9 -> V_144 [ 0 ] ) ) ||
F_29 ( V_16 , V_147 , V_9 -> V_148 ) ||
F_29 ( V_16 , V_149 , V_9 -> V_150 ) ||
F_29 ( V_16 , V_151 , V_9 -> V_152 ) ||
#ifdef F_59
( ( ( V_82 ) && ( V_82 -> V_173 [ 0 ] || V_82 -> V_173 [ 1 ] ) ) &&
F_29 ( V_16 , V_174 , 1 ) ) ||
#endif
( V_9 -> V_154 &&
F_60 ( V_16 , V_153 , V_9 -> V_154 ) ) )
goto V_88;
V_80 = F_32 ( V_16 , V_89 ) ;
if ( V_80 == NULL )
goto V_88;
if ( F_33 ( V_16 , V_90 ,
F_34 ( & V_9 -> V_91 . V_92 ) ) ||
F_33 ( V_16 , V_93 ,
F_34 ( & V_9 -> V_91 . V_94 ) ) ||
F_33 ( V_16 , V_95 ,
F_34 ( & V_9 -> V_91 . V_96 ) ) ||
F_33 ( V_16 , V_97 ,
F_34 ( & V_9 -> V_91 . V_98 ) ) ||
F_33 ( V_16 , V_99 ,
F_34 ( & V_9 -> V_91 . V_100 ) ) ||
F_33 ( V_16 , V_101 ,
F_34 ( & V_9 -> V_91 . V_102 ) ) ||
F_33 ( V_16 , V_103 ,
F_34 ( & V_9 -> V_91 . V_104 ) ) ||
F_33 ( V_16 , V_105 ,
F_34 ( & V_9 -> V_91 . V_106 ) ) )
goto V_88;
F_35 ( V_16 , V_80 ) ;
F_11 ( V_16 , V_18 ) ;
return 0 ;
V_88:
F_41 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_61 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_15 * V_17 ;
int V_19 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_73 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_18 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
0 , V_9 , V_175 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_62 ( struct V_15 * V_16 , struct V_117 * V_118 )
{
struct V_10 * V_10 = F_44 ( V_16 -> V_82 ) ;
struct V_1 * V_9 ;
struct V_7 * V_8 = NULL ;
int V_119 = V_118 -> args [ 0 ] ;
int V_176 = V_118 -> args [ 1 ] ;
for (; ; ) {
if ( V_8 == NULL ) {
V_8 = F_45 ( V_10 , V_119 ) ;
if ( V_8 == NULL )
goto V_24;
}
V_9 = F_63 ( V_8 , V_176 ) ;
if ( V_9 == NULL ) {
V_119 ++ ;
V_8 = NULL ;
V_176 = 0 ;
continue;
}
if ( F_18 ( V_16 , F_46 ( V_118 -> V_16 ) . V_76 ,
V_118 -> V_120 -> V_121 , V_122 ,
V_9 , V_175 ) < 0 )
break;
V_176 ++ ;
}
V_24:
V_118 -> args [ 0 ] = V_119 ;
V_118 -> args [ 1 ] = V_176 ;
return V_16 -> V_123 ;
}
int F_64 ( enum V_177 V_128 , const struct V_159 * V_178 )
{
int V_19 ;
V_19 = - V_41 ;
if ( V_128 >= V_129 )
goto V_179;
F_53 () ;
V_19 = - V_180 ;
if ( V_159 [ V_128 ] )
goto V_24;
V_159 [ V_128 ] = V_178 ;
V_19 = 0 ;
V_24:
F_51 () ;
V_179:
return V_19 ;
}
void F_65 ( enum V_177 V_128 )
{
if ( V_128 < V_129 ) {
F_53 () ;
V_159 [ V_128 ] = NULL ;
F_51 () ;
}
}
static int F_66 ( void )
{
F_67 ( L_2 ) ;
return F_68 ( & V_27 ,
V_181 ,
V_182 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_27 ) ;
}
