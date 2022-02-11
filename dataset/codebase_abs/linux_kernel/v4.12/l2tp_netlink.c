static struct V_1 * F_1 ( struct V_2 * V_3 ,
bool V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
char * V_7 ;
struct V_8 * V_9 ;
struct V_1 * V_10 = NULL ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( V_3 -> V_12 [ V_13 ] ) {
V_7 = F_3 ( V_3 -> V_12 [ V_13 ] ) ;
V_10 = F_4 ( V_11 , V_7 , V_4 ) ;
} else if ( ( V_3 -> V_12 [ V_14 ] ) &&
( V_3 -> V_12 [ V_15 ] ) ) {
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
V_6 = F_5 ( V_3 -> V_12 [ V_14 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( V_9 )
V_10 = F_7 ( V_11 , V_9 , V_6 ,
V_4 ) ;
}
return V_10 ;
}
static int F_8 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
struct V_16 * V_18 ;
void * V_19 ;
int V_20 = - V_21 ;
V_18 = F_9 ( V_22 , V_23 ) ;
if ( ! V_18 ) {
V_20 = - V_24 ;
goto V_25;
}
V_19 = F_10 ( V_18 , V_3 -> V_26 , V_3 -> V_27 ,
& V_28 , 0 , V_29 ) ;
if ( ! V_19 ) {
V_20 = - V_30 ;
goto V_31;
}
F_11 ( V_18 , V_19 ) ;
return F_12 ( F_2 ( V_3 ) , V_18 , V_3 -> V_26 ) ;
V_31:
F_13 ( V_18 ) ;
V_25:
return V_20 ;
}
static int F_14 ( struct V_32 * V_33 ,
struct V_2 * V_3 ,
struct V_8 * V_9 ,
T_2 V_34 )
{
struct V_16 * V_18 ;
int V_20 ;
V_18 = F_9 ( V_22 , V_23 ) ;
if ( ! V_18 )
return - V_24 ;
V_20 = F_15 ( V_18 , V_3 -> V_26 , V_3 -> V_27 ,
V_35 , V_9 , V_34 ) ;
if ( V_20 >= 0 ) {
V_20 = F_16 ( V_33 , V_18 , 0 , 0 , V_36 ) ;
if ( V_20 == - V_37 )
V_20 = 0 ;
return V_20 ;
}
F_13 ( V_18 ) ;
return V_20 ;
}
static int F_17 ( struct V_32 * V_33 ,
struct V_2 * V_3 ,
struct V_1 * V_10 ,
T_2 V_34 )
{
struct V_16 * V_18 ;
int V_20 ;
V_18 = F_9 ( V_22 , V_23 ) ;
if ( ! V_18 )
return - V_24 ;
V_20 = F_18 ( V_18 , V_3 -> V_26 , V_3 -> V_27 ,
V_35 , V_10 , V_34 ) ;
if ( V_20 >= 0 ) {
V_20 = F_16 ( V_33 , V_18 , 0 , 0 , V_36 ) ;
if ( V_20 == - V_37 )
V_20 = 0 ;
return V_20 ;
}
F_13 ( V_18 ) ;
return V_20 ;
}
static int F_19 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
T_1 V_5 ;
T_1 V_38 ;
int V_39 ;
int V_40 ;
int V_20 = 0 ;
struct V_41 V_42 = { 0 , } ;
struct V_8 * V_9 ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_12 [ V_15 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
if ( ! V_3 -> V_12 [ V_44 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_38 = F_5 ( V_3 -> V_12 [ V_44 ] ) ;
if ( ! V_3 -> V_12 [ V_45 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_39 = F_20 ( V_3 -> V_12 [ V_45 ] ) ;
if ( ! V_3 -> V_12 [ V_46 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_42 . V_47 = F_21 ( V_3 -> V_12 [ V_46 ] ) ;
V_40 = - 1 ;
if ( V_3 -> V_12 [ V_48 ] ) {
V_40 = F_5 ( V_3 -> V_12 [ V_48 ] ) ;
} else {
#if F_22 ( V_49 )
if ( V_3 -> V_12 [ V_50 ] &&
V_3 -> V_12 [ V_51 ] ) {
V_42 . V_52 = F_3 (
V_3 -> V_12 [ V_50 ] ) ;
V_42 . V_53 = F_3 (
V_3 -> V_12 [ V_51 ] ) ;
} else
#endif
if ( V_3 -> V_12 [ V_54 ] &&
V_3 -> V_12 [ V_55 ] ) {
V_42 . V_56 . V_57 = F_23 (
V_3 -> V_12 [ V_54 ] ) ;
V_42 . V_58 . V_57 = F_23 (
V_3 -> V_12 [ V_55 ] ) ;
} else {
V_20 = - V_43 ;
goto V_25;
}
if ( V_3 -> V_12 [ V_59 ] )
V_42 . V_60 = F_21 ( V_3 -> V_12 [ V_59 ] ) ;
if ( V_3 -> V_12 [ V_61 ] )
V_42 . V_62 = F_21 ( V_3 -> V_12 [ V_61 ] ) ;
V_42 . V_63 = F_24 (
V_3 -> V_12 [ V_64 ] ) ;
#if F_22 ( V_49 )
V_42 . V_65 = F_24 (
V_3 -> V_12 [ V_66 ] ) ;
V_42 . V_67 = F_24 (
V_3 -> V_12 [ V_68 ] ) ;
#endif
}
if ( V_3 -> V_12 [ V_69 ] )
V_42 . V_70 = F_5 ( V_3 -> V_12 [ V_69 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( V_9 != NULL ) {
V_20 = - V_71 ;
goto V_25;
}
V_20 = - V_43 ;
switch ( V_42 . V_47 ) {
case V_72 :
case V_73 :
V_20 = F_25 ( V_11 , V_40 , V_39 , V_5 ,
V_38 , & V_42 , & V_9 ) ;
break;
}
if ( V_20 >= 0 )
V_20 = F_14 ( & V_28 , V_3 ,
V_9 , V_74 ) ;
V_25:
return V_20 ;
}
static int F_26 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
int V_20 = 0 ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_12 [ V_15 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( V_9 == NULL ) {
V_20 = - V_75 ;
goto V_25;
}
F_14 ( & V_28 , V_3 ,
V_9 , V_76 ) ;
( void ) F_27 ( V_9 ) ;
V_25:
return V_20 ;
}
static int F_28 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
int V_20 = 0 ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_12 [ V_15 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( V_9 == NULL ) {
V_20 = - V_75 ;
goto V_25;
}
if ( V_3 -> V_12 [ V_69 ] )
V_9 -> V_70 = F_5 ( V_3 -> V_12 [ V_69 ] ) ;
V_20 = F_14 ( & V_28 , V_3 ,
V_9 , V_77 ) ;
V_25:
return V_20 ;
}
static int F_15 ( struct V_16 * V_17 , T_1 V_78 , T_1 V_79 , int V_80 ,
struct V_8 * V_9 , T_2 V_34 )
{
void * V_19 ;
struct V_81 * V_82 ;
struct V_83 * V_84 = NULL ;
struct V_85 * V_86 ;
#if F_22 ( V_49 )
struct V_87 * V_88 = NULL ;
#endif
V_19 = F_10 ( V_17 , V_78 , V_79 , & V_28 , V_80 , V_34 ) ;
if ( ! V_19 )
return - V_30 ;
if ( F_29 ( V_17 , V_45 , V_9 -> V_89 ) ||
F_30 ( V_17 , V_15 , V_9 -> V_5 ) ||
F_30 ( V_17 , V_44 , V_9 -> V_38 ) ||
F_30 ( V_17 , V_69 , V_9 -> V_70 ) ||
F_31 ( V_17 , V_46 , V_9 -> V_47 ) )
goto V_90;
V_82 = F_32 ( V_17 , V_91 ) ;
if ( V_82 == NULL )
goto V_90;
if ( F_33 ( V_17 , V_92 ,
F_34 ( & V_9 -> V_93 . V_94 ) ,
V_95 ) ||
F_33 ( V_17 , V_96 ,
F_34 ( & V_9 -> V_93 . V_97 ) ,
V_95 ) ||
F_33 ( V_17 , V_98 ,
F_34 ( & V_9 -> V_93 . V_99 ) ,
V_95 ) ||
F_33 ( V_17 , V_100 ,
F_34 ( & V_9 -> V_93 . V_101 ) ,
V_95 ) ||
F_33 ( V_17 , V_102 ,
F_34 ( & V_9 -> V_93 . V_103 ) ,
V_95 ) ||
F_33 ( V_17 , V_104 ,
F_34 ( & V_9 -> V_93 . V_105 ) ,
V_95 ) ||
F_33 ( V_17 , V_106 ,
F_34 ( & V_9 -> V_93 . V_107 ) ,
V_95 ) ||
F_33 ( V_17 , V_108 ,
F_34 ( & V_9 -> V_93 . V_109 ) ,
V_95 ) )
goto V_90;
F_35 ( V_17 , V_82 ) ;
V_84 = V_9 -> V_83 ;
if ( ! V_84 )
goto V_25;
#if F_22 ( V_49 )
if ( V_84 -> V_110 == V_111 )
V_88 = F_36 ( V_84 ) ;
#endif
V_86 = F_37 ( V_84 ) ;
switch ( V_9 -> V_47 ) {
case V_72 :
switch ( V_84 -> V_110 ) {
case V_112 :
if ( F_29 ( V_17 , V_64 , ! V_84 -> V_113 ) )
goto V_90;
break;
#if F_22 ( V_49 )
case V_111 :
if ( F_38 ( V_84 ) &&
F_39 ( V_17 , V_66 ) )
goto V_90;
if ( F_40 ( V_84 ) &&
F_39 ( V_17 , V_68 ) )
goto V_90;
break;
#endif
}
if ( F_31 ( V_17 , V_59 , F_41 ( V_86 -> V_114 ) ) ||
F_31 ( V_17 , V_61 , F_41 ( V_86 -> V_115 ) ) )
goto V_90;
case V_73 :
#if F_22 ( V_49 )
if ( V_88 ) {
if ( F_42 ( V_17 , V_50 ,
& V_88 -> V_116 ) ||
F_42 ( V_17 , V_51 ,
& V_84 -> V_117 ) )
goto V_90;
} else
#endif
if ( F_43 ( V_17 , V_54 ,
V_86 -> V_118 ) ||
F_43 ( V_17 , V_55 ,
V_86 -> V_119 ) )
goto V_90;
break;
}
V_25:
F_11 ( V_17 , V_19 ) ;
return 0 ;
V_90:
F_44 ( V_17 , V_19 ) ;
return - 1 ;
}
static int F_45 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
struct V_8 * V_9 ;
struct V_16 * V_18 ;
T_1 V_5 ;
int V_20 = - V_21 ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_12 [ V_15 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( V_9 == NULL ) {
V_20 = - V_75 ;
goto V_25;
}
V_18 = F_9 ( V_22 , V_23 ) ;
if ( ! V_18 ) {
V_20 = - V_24 ;
goto V_25;
}
V_20 = F_15 ( V_18 , V_3 -> V_26 , V_3 -> V_27 ,
V_35 , V_9 , V_120 ) ;
if ( V_20 < 0 )
goto V_31;
return F_12 ( V_11 , V_18 , V_3 -> V_26 ) ;
V_31:
F_13 ( V_18 ) ;
V_25:
return V_20 ;
}
static int F_46 ( struct V_16 * V_17 , struct V_121 * V_122 )
{
int V_123 = V_122 -> args [ 0 ] ;
struct V_8 * V_9 ;
struct V_11 * V_11 = F_47 ( V_17 -> V_84 ) ;
for (; ; ) {
V_9 = F_48 ( V_11 , V_123 ) ;
if ( V_9 == NULL )
goto V_25;
if ( F_15 ( V_17 , F_49 ( V_122 -> V_17 ) . V_78 ,
V_122 -> V_124 -> V_125 , V_126 ,
V_9 , V_120 ) < 0 )
goto V_25;
V_123 ++ ;
}
V_25:
V_122 -> args [ 0 ] = V_123 ;
return V_17 -> V_127 ;
}
static int F_50 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
T_1 V_5 = 0 ;
T_1 V_6 ;
T_1 V_128 ;
int V_20 = 0 ;
struct V_8 * V_9 ;
struct V_1 * V_10 ;
struct V_129 V_42 = { 0 , } ;
struct V_11 * V_11 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_12 [ V_15 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_5 = F_5 ( V_3 -> V_12 [ V_15 ] ) ;
V_9 = F_6 ( V_11 , V_5 ) ;
if ( ! V_9 ) {
V_20 = - V_75 ;
goto V_25;
}
if ( ! V_3 -> V_12 [ V_14 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_6 = F_5 ( V_3 -> V_12 [ V_14 ] ) ;
if ( ! V_3 -> V_12 [ V_130 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_128 = F_5 ( V_3 -> V_12 [ V_130 ] ) ;
if ( ! V_3 -> V_12 [ V_131 ] ) {
V_20 = - V_43 ;
goto V_25;
}
V_42 . V_132 = F_21 ( V_3 -> V_12 [ V_131 ] ) ;
if ( V_42 . V_132 >= V_133 ) {
V_20 = - V_43 ;
goto V_25;
}
if ( V_9 -> V_89 > 2 ) {
if ( V_3 -> V_12 [ V_134 ] )
V_42 . V_135 = F_21 ( V_3 -> V_12 [ V_134 ] ) ;
if ( V_3 -> V_12 [ V_136 ] )
V_42 . V_137 = F_20 ( V_3 -> V_12 [ V_136 ] ) ;
V_42 . V_138 = V_139 ;
if ( V_3 -> V_12 [ V_140 ] )
V_42 . V_138 = F_20 ( V_3 -> V_12 [ V_140 ] ) ;
V_42 . V_141 = 4 ;
if ( V_3 -> V_12 [ V_142 ] )
V_42 . V_141 = F_20 ( V_3 -> V_12 [ V_142 ] ) ;
if ( V_3 -> V_12 [ V_143 ] ) {
T_3 V_127 = F_51 ( V_3 -> V_12 [ V_143 ] ) ;
if ( V_127 > 8 ) {
V_20 = - V_43 ;
goto V_25;
}
V_42 . V_144 = V_127 ;
memcpy ( & V_42 . V_145 [ 0 ] , F_3 ( V_3 -> V_12 [ V_143 ] ) , V_127 ) ;
}
if ( V_3 -> V_12 [ V_146 ] ) {
T_3 V_127 = F_51 ( V_3 -> V_12 [ V_146 ] ) ;
if ( V_127 > 8 ) {
V_20 = - V_43 ;
goto V_25;
}
V_42 . V_147 = V_127 ;
memcpy ( & V_42 . V_148 [ 0 ] , F_3 ( V_3 -> V_12 [ V_146 ] ) , V_127 ) ;
}
if ( V_3 -> V_12 [ V_13 ] )
V_42 . V_7 = F_3 ( V_3 -> V_12 [ V_13 ] ) ;
if ( V_3 -> V_12 [ V_149 ] )
V_42 . V_150 = F_21 ( V_3 -> V_12 [ V_149 ] ) ;
}
if ( V_3 -> V_12 [ V_69 ] )
V_42 . V_70 = F_5 ( V_3 -> V_12 [ V_69 ] ) ;
if ( V_3 -> V_12 [ V_151 ] )
V_42 . V_152 = F_20 ( V_3 -> V_12 [ V_151 ] ) ;
if ( V_3 -> V_12 [ V_153 ] )
V_42 . V_154 = F_20 ( V_3 -> V_12 [ V_153 ] ) ;
if ( V_3 -> V_12 [ V_155 ] )
V_42 . V_156 = F_20 ( V_3 -> V_12 [ V_155 ] ) ;
if ( V_3 -> V_12 [ V_157 ] )
V_42 . V_158 = F_52 ( V_3 -> V_12 [ V_157 ] ) ;
if ( V_3 -> V_12 [ V_159 ] )
V_42 . V_160 = F_21 ( V_3 -> V_12 [ V_159 ] ) ;
if ( V_3 -> V_12 [ V_161 ] )
V_42 . V_162 = F_21 ( V_3 -> V_12 [ V_161 ] ) ;
#ifdef F_53
if ( V_163 [ V_42 . V_132 ] == NULL ) {
F_54 () ;
F_55 ( L_1 , V_42 . V_132 ) ;
F_56 () ;
}
#endif
if ( ( V_163 [ V_42 . V_132 ] == NULL ) ||
( V_163 [ V_42 . V_132 ] -> V_164 == NULL ) ) {
V_20 = - V_165 ;
goto V_25;
}
switch ( V_42 . V_132 ) {
case V_166 :
break;
case V_167 :
if ( ! V_3 -> V_12 [ V_149 ] ) {
V_20 = - V_43 ;
goto V_25;
}
break;
case V_168 :
break;
case V_169 :
case V_170 :
break;
case V_171 :
default:
V_20 = - V_165 ;
break;
}
V_20 = - V_165 ;
if ( V_163 [ V_42 . V_132 ] -> V_164 )
V_20 = ( * V_163 [ V_42 . V_132 ] -> V_164 ) ( V_11 , V_5 ,
V_6 , V_128 , & V_42 ) ;
if ( V_20 >= 0 ) {
V_10 = F_7 ( V_11 , V_9 , V_6 , false ) ;
if ( V_10 ) {
V_20 = F_17 ( & V_28 , V_3 , V_10 ,
V_172 ) ;
F_57 ( V_10 ) ;
}
}
V_25:
return V_20 ;
}
static int F_58 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
int V_20 = 0 ;
struct V_1 * V_10 ;
T_3 V_132 ;
V_10 = F_1 ( V_3 , true ) ;
if ( V_10 == NULL ) {
V_20 = - V_75 ;
goto V_25;
}
F_17 ( & V_28 , V_3 ,
V_10 , V_173 ) ;
V_132 = V_10 -> V_174 ;
if ( V_132 < V_133 )
if ( V_163 [ V_132 ] && V_163 [ V_132 ] -> V_175 )
V_20 = ( * V_163 [ V_132 ] -> V_175 ) ( V_10 ) ;
if ( V_10 -> V_176 )
V_10 -> V_176 ( V_10 ) ;
F_57 ( V_10 ) ;
V_25:
return V_20 ;
}
static int F_59 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
int V_20 = 0 ;
struct V_1 * V_10 ;
V_10 = F_1 ( V_3 , false ) ;
if ( V_10 == NULL ) {
V_20 = - V_75 ;
goto V_25;
}
if ( V_3 -> V_12 [ V_69 ] )
V_10 -> V_70 = F_5 ( V_3 -> V_12 [ V_69 ] ) ;
if ( V_3 -> V_12 [ V_136 ] )
V_10 -> V_137 = F_20 ( V_3 -> V_12 [ V_136 ] ) ;
if ( V_3 -> V_12 [ V_151 ] )
V_10 -> V_152 = F_20 ( V_3 -> V_12 [ V_151 ] ) ;
if ( V_3 -> V_12 [ V_153 ] ) {
V_10 -> V_154 = F_20 ( V_3 -> V_12 [ V_153 ] ) ;
F_60 ( V_10 , V_10 -> V_9 -> V_89 ) ;
}
if ( V_3 -> V_12 [ V_155 ] )
V_10 -> V_156 = F_20 ( V_3 -> V_12 [ V_155 ] ) ;
if ( V_3 -> V_12 [ V_157 ] )
V_10 -> V_158 = F_52 ( V_3 -> V_12 [ V_157 ] ) ;
if ( V_3 -> V_12 [ V_159 ] )
V_10 -> V_160 = F_21 ( V_3 -> V_12 [ V_159 ] ) ;
if ( V_3 -> V_12 [ V_161 ] )
V_10 -> V_162 = F_21 ( V_3 -> V_12 [ V_161 ] ) ;
V_20 = F_17 ( & V_28 , V_3 ,
V_10 , V_177 ) ;
F_57 ( V_10 ) ;
V_25:
return V_20 ;
}
static int F_18 ( struct V_16 * V_17 , T_1 V_78 , T_1 V_79 , int V_80 ,
struct V_1 * V_10 , T_2 V_34 )
{
void * V_19 ;
struct V_81 * V_82 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_83 * V_84 = NULL ;
V_84 = V_9 -> V_83 ;
V_19 = F_10 ( V_17 , V_78 , V_79 , & V_28 , V_80 , V_34 ) ;
if ( ! V_19 )
return - V_30 ;
if ( F_30 ( V_17 , V_15 , V_9 -> V_5 ) ||
F_30 ( V_17 , V_14 , V_10 -> V_6 ) ||
F_30 ( V_17 , V_44 , V_9 -> V_38 ) ||
F_30 ( V_17 , V_130 ,
V_10 -> V_128 ) ||
F_30 ( V_17 , V_69 , V_10 -> V_70 ) ||
F_31 ( V_17 , V_131 , V_10 -> V_174 ) ||
F_31 ( V_17 , V_159 , V_10 -> V_160 ) ||
( V_10 -> V_162 &&
F_31 ( V_17 , V_161 , V_10 -> V_162 ) ) )
goto V_90;
if ( ( V_10 -> V_7 [ 0 ] &&
F_61 ( V_17 , V_13 , V_10 -> V_7 ) ) ||
( V_10 -> V_144 &&
F_62 ( V_17 , V_143 , V_10 -> V_144 ,
& V_10 -> V_145 [ 0 ] ) ) ||
( V_10 -> V_147 &&
F_62 ( V_17 , V_146 , V_10 -> V_147 ,
& V_10 -> V_148 [ 0 ] ) ) ||
F_29 ( V_17 , V_151 , V_10 -> V_152 ) ||
F_29 ( V_17 , V_153 , V_10 -> V_154 ) ||
F_29 ( V_17 , V_155 , V_10 -> V_156 ) ||
#ifdef F_63
( ( ( V_84 ) && ( V_84 -> V_178 [ 0 ] || V_84 -> V_178 [ 1 ] ) ) &&
F_29 ( V_17 , V_179 , 1 ) ) ||
#endif
( V_10 -> V_158 &&
F_64 ( V_17 , V_157 ,
V_10 -> V_158 , V_180 ) ) )
goto V_90;
V_82 = F_32 ( V_17 , V_91 ) ;
if ( V_82 == NULL )
goto V_90;
if ( F_33 ( V_17 , V_92 ,
F_34 ( & V_10 -> V_93 . V_94 ) ,
V_95 ) ||
F_33 ( V_17 , V_96 ,
F_34 ( & V_10 -> V_93 . V_97 ) ,
V_95 ) ||
F_33 ( V_17 , V_98 ,
F_34 ( & V_10 -> V_93 . V_99 ) ,
V_95 ) ||
F_33 ( V_17 , V_100 ,
F_34 ( & V_10 -> V_93 . V_101 ) ,
V_95 ) ||
F_33 ( V_17 , V_102 ,
F_34 ( & V_10 -> V_93 . V_103 ) ,
V_95 ) ||
F_33 ( V_17 , V_104 ,
F_34 ( & V_10 -> V_93 . V_105 ) ,
V_95 ) ||
F_33 ( V_17 , V_106 ,
F_34 ( & V_10 -> V_93 . V_107 ) ,
V_95 ) ||
F_33 ( V_17 , V_108 ,
F_34 ( & V_10 -> V_93 . V_109 ) ,
V_95 ) )
goto V_90;
F_35 ( V_17 , V_82 ) ;
F_11 ( V_17 , V_19 ) ;
return 0 ;
V_90:
F_44 ( V_17 , V_19 ) ;
return - 1 ;
}
static int F_65 ( struct V_16 * V_17 , struct V_2 * V_3 )
{
struct V_1 * V_10 ;
struct V_16 * V_18 ;
int V_20 ;
V_10 = F_1 ( V_3 , false ) ;
if ( V_10 == NULL ) {
V_20 = - V_75 ;
goto V_181;
}
V_18 = F_9 ( V_22 , V_23 ) ;
if ( ! V_18 ) {
V_20 = - V_24 ;
goto V_182;
}
V_20 = F_18 ( V_18 , V_3 -> V_26 , V_3 -> V_27 ,
0 , V_10 , V_183 ) ;
if ( V_20 < 0 )
goto V_184;
V_20 = F_12 ( F_2 ( V_3 ) , V_18 , V_3 -> V_26 ) ;
F_57 ( V_10 ) ;
return V_20 ;
V_184:
F_13 ( V_18 ) ;
V_182:
F_57 ( V_10 ) ;
V_181:
return V_20 ;
}
static int F_66 ( struct V_16 * V_17 , struct V_121 * V_122 )
{
struct V_11 * V_11 = F_47 ( V_17 -> V_84 ) ;
struct V_1 * V_10 ;
struct V_8 * V_9 = NULL ;
int V_123 = V_122 -> args [ 0 ] ;
int V_185 = V_122 -> args [ 1 ] ;
for (; ; ) {
if ( V_9 == NULL ) {
V_9 = F_48 ( V_11 , V_123 ) ;
if ( V_9 == NULL )
goto V_25;
}
V_10 = F_67 ( V_9 , V_185 , false ) ;
if ( V_10 == NULL ) {
V_123 ++ ;
V_9 = NULL ;
V_185 = 0 ;
continue;
}
if ( F_18 ( V_17 , F_49 ( V_122 -> V_17 ) . V_78 ,
V_122 -> V_124 -> V_125 , V_126 ,
V_10 , V_183 ) < 0 ) {
F_57 ( V_10 ) ;
break;
}
F_57 ( V_10 ) ;
V_185 ++ ;
}
V_25:
V_122 -> args [ 0 ] = V_123 ;
V_122 -> args [ 1 ] = V_185 ;
return V_17 -> V_127 ;
}
int F_68 ( enum V_186 V_132 , const struct V_163 * V_187 )
{
int V_20 ;
V_20 = - V_43 ;
if ( V_132 >= V_133 )
goto V_181;
F_56 () ;
V_20 = - V_188 ;
if ( V_163 [ V_132 ] )
goto V_25;
V_163 [ V_132 ] = V_187 ;
V_20 = 0 ;
V_25:
F_54 () ;
V_181:
return V_20 ;
}
void F_69 ( enum V_186 V_132 )
{
if ( V_132 < V_133 ) {
F_56 () ;
V_163 [ V_132 ] = NULL ;
F_54 () ;
}
}
static int T_4 F_70 ( void )
{
F_71 ( L_2 ) ;
return F_72 ( & V_28 ) ;
}
static void F_73 ( void )
{
F_74 ( & V_28 ) ;
}
