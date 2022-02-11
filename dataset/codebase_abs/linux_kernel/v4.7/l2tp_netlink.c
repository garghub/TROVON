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
if ( V_3 -> V_11 [ V_62 ] )
V_41 . V_63 = F_24 ( V_3 -> V_11 [ V_62 ] ) ;
#if F_22 ( V_48 )
if ( V_3 -> V_11 [ V_64 ] )
V_41 . V_65 = F_24 ( V_3 -> V_11 [ V_64 ] ) ;
if ( V_3 -> V_11 [ V_66 ] )
V_41 . V_67 = F_24 ( V_3 -> V_11 [ V_66 ] ) ;
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
if ( F_31 ( V_16 , V_58 , F_38 ( V_85 -> V_111 ) ) ||
F_31 ( V_16 , V_60 , F_38 ( V_85 -> V_112 ) ) ||
F_29 ( V_16 , V_62 , ! V_83 -> V_113 ) )
goto V_89;
case V_72 :
#if F_22 ( V_48 )
if ( V_87 ) {
if ( F_39 ( V_16 , V_49 ,
& V_87 -> V_114 ) ||
F_39 ( V_16 , V_50 ,
& V_83 -> V_115 ) )
goto V_89;
} else
#endif
if ( F_40 ( V_16 , V_53 ,
V_85 -> V_116 ) ||
F_40 ( V_16 , V_54 ,
V_85 -> V_117 ) )
goto V_89;
break;
}
V_24:
F_11 ( V_16 , V_18 ) ;
return 0 ;
V_89:
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
V_34 , V_8 , V_118 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( V_10 , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_43 ( struct V_15 * V_16 , struct V_119 * V_120 )
{
int V_121 = V_120 -> args [ 0 ] ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_44 ( V_16 -> V_83 ) ;
for (; ; ) {
V_8 = F_45 ( V_10 , V_121 ) ;
if ( V_8 == NULL )
goto V_24;
if ( F_15 ( V_16 , F_46 ( V_120 -> V_16 ) . V_77 ,
V_120 -> V_122 -> V_123 , V_124 ,
V_8 , V_118 ) < 0 )
goto V_24;
V_121 ++ ;
}
V_24:
V_120 -> args [ 0 ] = V_121 ;
return V_16 -> V_125 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_126 ;
int V_19 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_127 V_41 = { 0 , } ;
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
if ( ! V_3 -> V_11 [ V_128 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_126 = F_5 ( V_3 -> V_11 [ V_128 ] ) ;
if ( ! V_3 -> V_11 [ V_129 ] ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_130 = F_21 ( V_3 -> V_11 [ V_129 ] ) ;
if ( V_41 . V_130 >= V_131 ) {
V_19 = - V_42 ;
goto V_24;
}
if ( V_8 -> V_88 > 2 ) {
if ( V_3 -> V_11 [ V_132 ] )
V_41 . V_133 = F_21 ( V_3 -> V_11 [ V_132 ] ) ;
if ( V_3 -> V_11 [ V_134 ] )
V_41 . V_135 = F_20 ( V_3 -> V_11 [ V_134 ] ) ;
V_41 . V_136 = V_137 ;
if ( V_3 -> V_11 [ V_138 ] )
V_41 . V_136 = F_20 ( V_3 -> V_11 [ V_138 ] ) ;
V_41 . V_139 = 4 ;
if ( V_3 -> V_11 [ V_140 ] )
V_41 . V_139 = F_20 ( V_3 -> V_11 [ V_140 ] ) ;
if ( V_3 -> V_11 [ V_141 ] ) {
T_3 V_125 = F_48 ( V_3 -> V_11 [ V_141 ] ) ;
if ( V_125 > 8 ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_142 = V_125 ;
memcpy ( & V_41 . V_143 [ 0 ] , F_3 ( V_3 -> V_11 [ V_141 ] ) , V_125 ) ;
}
if ( V_3 -> V_11 [ V_144 ] ) {
T_3 V_125 = F_48 ( V_3 -> V_11 [ V_144 ] ) ;
if ( V_125 > 8 ) {
V_19 = - V_42 ;
goto V_24;
}
V_41 . V_145 = V_125 ;
memcpy ( & V_41 . V_146 [ 0 ] , F_3 ( V_3 -> V_11 [ V_144 ] ) , V_125 ) ;
}
if ( V_3 -> V_11 [ V_12 ] )
V_41 . V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
if ( V_3 -> V_11 [ V_147 ] )
V_41 . V_148 = F_21 ( V_3 -> V_11 [ V_147 ] ) ;
}
if ( V_3 -> V_11 [ V_68 ] )
V_41 . V_69 = F_5 ( V_3 -> V_11 [ V_68 ] ) ;
if ( V_3 -> V_11 [ V_149 ] )
V_41 . V_150 = F_20 ( V_3 -> V_11 [ V_149 ] ) ;
if ( V_3 -> V_11 [ V_151 ] )
V_41 . V_152 = F_20 ( V_3 -> V_11 [ V_151 ] ) ;
if ( V_3 -> V_11 [ V_153 ] )
V_41 . V_154 = F_20 ( V_3 -> V_11 [ V_153 ] ) ;
if ( V_3 -> V_11 [ V_155 ] )
V_41 . V_156 = F_49 ( V_3 -> V_11 [ V_155 ] ) ;
if ( V_3 -> V_11 [ V_157 ] )
V_41 . V_158 = F_21 ( V_3 -> V_11 [ V_157 ] ) ;
if ( V_3 -> V_11 [ V_159 ] )
V_41 . V_160 = F_21 ( V_3 -> V_11 [ V_159 ] ) ;
#ifdef F_50
if ( V_161 [ V_41 . V_130 ] == NULL ) {
F_51 () ;
F_52 ( L_1 , V_41 . V_130 ) ;
F_53 () ;
}
#endif
if ( ( V_161 [ V_41 . V_130 ] == NULL ) ||
( V_161 [ V_41 . V_130 ] -> V_162 == NULL ) ) {
V_19 = - V_163 ;
goto V_24;
}
switch ( V_41 . V_130 ) {
case V_164 :
break;
case V_165 :
if ( ! V_3 -> V_11 [ V_147 ] ) {
V_19 = - V_42 ;
goto V_24;
}
break;
case V_166 :
break;
case V_167 :
case V_168 :
break;
case V_169 :
default:
V_19 = - V_163 ;
break;
}
V_19 = - V_163 ;
if ( V_161 [ V_41 . V_130 ] -> V_162 )
V_19 = ( * V_161 [ V_41 . V_130 ] -> V_162 ) ( V_10 , V_4 ,
V_5 , V_126 , & V_41 ) ;
if ( V_19 >= 0 ) {
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 )
V_19 = F_17 ( & V_27 , V_3 , V_9 ,
V_170 ) ;
}
V_24:
return V_19 ;
}
static int F_54 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
T_3 V_130 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_74 ;
goto V_24;
}
F_17 ( & V_27 , V_3 ,
V_9 , V_171 ) ;
V_130 = V_9 -> V_172 ;
if ( V_130 < V_131 )
if ( V_161 [ V_130 ] && V_161 [ V_130 ] -> V_173 )
V_19 = ( * V_161 [ V_130 ] -> V_173 ) ( V_9 ) ;
V_24:
return V_19 ;
}
static int F_55 ( struct V_15 * V_16 , struct V_2 * V_3 )
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
if ( V_3 -> V_11 [ V_134 ] )
V_9 -> V_135 = F_20 ( V_3 -> V_11 [ V_134 ] ) ;
if ( V_3 -> V_11 [ V_149 ] )
V_9 -> V_150 = F_20 ( V_3 -> V_11 [ V_149 ] ) ;
if ( V_3 -> V_11 [ V_151 ] ) {
V_9 -> V_152 = F_20 ( V_3 -> V_11 [ V_151 ] ) ;
F_56 ( V_9 , V_9 -> V_8 -> V_88 ) ;
}
if ( V_3 -> V_11 [ V_153 ] )
V_9 -> V_154 = F_20 ( V_3 -> V_11 [ V_153 ] ) ;
if ( V_3 -> V_11 [ V_155 ] )
V_9 -> V_156 = F_49 ( V_3 -> V_11 [ V_155 ] ) ;
if ( V_3 -> V_11 [ V_157 ] )
V_9 -> V_158 = F_21 ( V_3 -> V_11 [ V_157 ] ) ;
if ( V_3 -> V_11 [ V_159 ] )
V_9 -> V_160 = F_21 ( V_3 -> V_11 [ V_159 ] ) ;
V_19 = F_17 ( & V_27 , V_3 ,
V_9 , V_174 ) ;
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
F_30 ( V_16 , V_128 ,
V_9 -> V_126 ) ||
F_30 ( V_16 , V_68 , V_9 -> V_69 ) ||
F_31 ( V_16 , V_129 , V_9 -> V_172 ) ||
F_31 ( V_16 , V_157 , V_9 -> V_158 ) ||
( V_9 -> V_160 &&
F_31 ( V_16 , V_159 , V_9 -> V_160 ) ) )
goto V_89;
if ( ( V_9 -> V_6 [ 0 ] &&
F_57 ( V_16 , V_12 , V_9 -> V_6 ) ) ||
( V_9 -> V_142 &&
F_58 ( V_16 , V_141 , V_9 -> V_142 ,
& V_9 -> V_143 [ 0 ] ) ) ||
( V_9 -> V_145 &&
F_58 ( V_16 , V_144 , V_9 -> V_145 ,
& V_9 -> V_146 [ 0 ] ) ) ||
F_29 ( V_16 , V_149 , V_9 -> V_150 ) ||
F_29 ( V_16 , V_151 , V_9 -> V_152 ) ||
F_29 ( V_16 , V_153 , V_9 -> V_154 ) ||
#ifdef F_59
( ( ( V_83 ) && ( V_83 -> V_175 [ 0 ] || V_83 -> V_175 [ 1 ] ) ) &&
F_29 ( V_16 , V_176 , 1 ) ) ||
#endif
( V_9 -> V_156 &&
F_60 ( V_16 , V_155 ,
V_9 -> V_156 , V_177 ) ) )
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
V_19 = - V_74 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_18 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
0 , V_9 , V_178 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_62 ( struct V_15 * V_16 , struct V_119 * V_120 )
{
struct V_10 * V_10 = F_44 ( V_16 -> V_83 ) ;
struct V_1 * V_9 ;
struct V_7 * V_8 = NULL ;
int V_121 = V_120 -> args [ 0 ] ;
int V_179 = V_120 -> args [ 1 ] ;
for (; ; ) {
if ( V_8 == NULL ) {
V_8 = F_45 ( V_10 , V_121 ) ;
if ( V_8 == NULL )
goto V_24;
}
V_9 = F_63 ( V_8 , V_179 ) ;
if ( V_9 == NULL ) {
V_121 ++ ;
V_8 = NULL ;
V_179 = 0 ;
continue;
}
if ( F_18 ( V_16 , F_46 ( V_120 -> V_16 ) . V_77 ,
V_120 -> V_122 -> V_123 , V_124 ,
V_9 , V_178 ) < 0 )
break;
V_179 ++ ;
}
V_24:
V_120 -> args [ 0 ] = V_121 ;
V_120 -> args [ 1 ] = V_179 ;
return V_16 -> V_125 ;
}
int F_64 ( enum V_180 V_130 , const struct V_161 * V_181 )
{
int V_19 ;
V_19 = - V_42 ;
if ( V_130 >= V_131 )
goto V_182;
F_53 () ;
V_19 = - V_183 ;
if ( V_161 [ V_130 ] )
goto V_24;
V_161 [ V_130 ] = V_181 ;
V_19 = 0 ;
V_24:
F_51 () ;
V_182:
return V_19 ;
}
void F_65 ( enum V_180 V_130 )
{
if ( V_130 < V_131 ) {
F_53 () ;
V_161 [ V_130 ] = NULL ;
F_51 () ;
}
}
static int F_66 ( void )
{
F_67 ( L_2 ) ;
return F_68 ( & V_27 ,
V_184 ,
V_185 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_27 ) ;
}
