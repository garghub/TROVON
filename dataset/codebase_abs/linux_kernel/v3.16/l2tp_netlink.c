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
static int F_14 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 ;
T_1 V_31 ;
int V_32 ;
int V_33 ;
int V_19 = 0 ;
struct V_34 V_35 = { 0 , } ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
if ( ! V_3 -> V_11 [ V_37 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_31 = F_5 ( V_3 -> V_11 [ V_37 ] ) ;
if ( ! V_3 -> V_11 [ V_38 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_32 = F_15 ( V_3 -> V_11 [ V_38 ] ) ;
if ( ! V_3 -> V_11 [ V_39 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_35 . V_40 = F_16 ( V_3 -> V_11 [ V_39 ] ) ;
V_33 = - 1 ;
if ( V_3 -> V_11 [ V_41 ] ) {
V_33 = F_5 ( V_3 -> V_11 [ V_41 ] ) ;
} else {
#if F_17 ( V_42 )
if ( V_3 -> V_11 [ V_43 ] &&
V_3 -> V_11 [ V_44 ] ) {
V_35 . V_45 = F_3 (
V_3 -> V_11 [ V_43 ] ) ;
V_35 . V_46 = F_3 (
V_3 -> V_11 [ V_44 ] ) ;
} else
#endif
if ( V_3 -> V_11 [ V_47 ] &&
V_3 -> V_11 [ V_48 ] ) {
V_35 . V_49 . V_50 = F_18 (
V_3 -> V_11 [ V_47 ] ) ;
V_35 . V_51 . V_50 = F_18 (
V_3 -> V_11 [ V_48 ] ) ;
} else {
V_19 = - V_36 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_52 ] )
V_35 . V_53 = F_16 ( V_3 -> V_11 [ V_52 ] ) ;
if ( V_3 -> V_11 [ V_54 ] )
V_35 . V_55 = F_16 ( V_3 -> V_11 [ V_54 ] ) ;
if ( V_3 -> V_11 [ V_56 ] )
V_35 . V_57 = F_19 ( V_3 -> V_11 [ V_56 ] ) ;
#if F_17 ( V_42 )
if ( V_3 -> V_11 [ V_58 ] )
V_35 . V_59 = F_19 ( V_3 -> V_11 [ V_58 ] ) ;
if ( V_3 -> V_11 [ V_60 ] )
V_35 . V_61 = F_19 ( V_3 -> V_11 [ V_60 ] ) ;
#endif
}
if ( V_3 -> V_11 [ V_62 ] )
V_35 . V_63 = F_5 ( V_3 -> V_11 [ V_62 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 != NULL ) {
V_19 = - V_64 ;
goto V_24;
}
V_19 = - V_36 ;
switch ( V_35 . V_40 ) {
case V_65 :
case V_66 :
V_19 = F_20 ( V_10 , V_33 , V_32 , V_4 ,
V_31 , & V_35 , & V_8 ) ;
break;
}
V_24:
return V_19 ;
}
static int F_21 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
( void ) F_22 ( V_8 ) ;
V_24:
return V_19 ;
}
static int F_23 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
T_1 V_4 ;
int V_19 = 0 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_62 ] )
V_8 -> V_63 = F_5 ( V_3 -> V_11 [ V_62 ] ) ;
V_24:
return V_19 ;
}
static int F_24 ( struct V_15 * V_16 , T_1 V_68 , T_1 V_69 , int V_70 ,
struct V_7 * V_8 )
{
void * V_18 ;
struct V_71 * V_72 ;
struct V_73 * V_74 = NULL ;
struct V_75 * V_76 ;
#if F_17 ( V_42 )
struct V_77 * V_78 = NULL ;
#endif
V_18 = F_10 ( V_16 , V_68 , V_69 , & V_27 , V_70 ,
V_79 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_25 ( V_16 , V_38 , V_8 -> V_80 ) ||
F_26 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_26 ( V_16 , V_37 , V_8 -> V_31 ) ||
F_26 ( V_16 , V_62 , V_8 -> V_63 ) ||
F_27 ( V_16 , V_39 , V_8 -> V_40 ) )
goto V_81;
V_72 = F_28 ( V_16 , V_82 ) ;
if ( V_72 == NULL )
goto V_81;
if ( F_29 ( V_16 , V_83 ,
F_30 ( & V_8 -> V_84 . V_85 ) ) ||
F_29 ( V_16 , V_86 ,
F_30 ( & V_8 -> V_84 . V_87 ) ) ||
F_29 ( V_16 , V_88 ,
F_30 ( & V_8 -> V_84 . V_89 ) ) ||
F_29 ( V_16 , V_90 ,
F_30 ( & V_8 -> V_84 . V_91 ) ) ||
F_29 ( V_16 , V_92 ,
F_30 ( & V_8 -> V_84 . V_93 ) ) ||
F_29 ( V_16 , V_94 ,
F_30 ( & V_8 -> V_84 . V_95 ) ) ||
F_29 ( V_16 , V_96 ,
F_30 ( & V_8 -> V_84 . V_97 ) ) ||
F_29 ( V_16 , V_98 ,
F_30 ( & V_8 -> V_84 . V_99 ) ) )
goto V_81;
F_31 ( V_16 , V_72 ) ;
V_74 = V_8 -> V_73 ;
if ( ! V_74 )
goto V_24;
#if F_17 ( V_42 )
if ( V_74 -> V_100 == V_101 )
V_78 = F_32 ( V_74 ) ;
#endif
V_76 = F_33 ( V_74 ) ;
switch ( V_8 -> V_40 ) {
case V_65 :
if ( F_27 ( V_16 , V_52 , F_34 ( V_76 -> V_102 ) ) ||
F_27 ( V_16 , V_54 , F_34 ( V_76 -> V_103 ) ) ||
F_25 ( V_16 , V_56 , ! V_74 -> V_104 ) )
goto V_81;
case V_66 :
#if F_17 ( V_42 )
if ( V_78 ) {
if ( F_35 ( V_16 , V_43 , sizeof( V_78 -> V_105 ) ,
& V_78 -> V_105 ) ||
F_35 ( V_16 , V_44 , sizeof( V_74 -> V_106 ) ,
& V_74 -> V_106 ) )
goto V_81;
} else
#endif
if ( F_36 ( V_16 , V_47 , V_76 -> V_107 ) ||
F_36 ( V_16 , V_48 , V_76 -> V_108 ) )
goto V_81;
break;
}
V_24:
return F_11 ( V_16 , V_18 ) ;
V_81:
F_37 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_38 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_7 * V_8 ;
struct V_15 * V_17 ;
T_1 V_4 ;
int V_19 = - V_20 ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( V_8 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_24 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
V_109 , V_8 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( V_10 , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_39 ( struct V_15 * V_16 , struct V_110 * V_111 )
{
int V_112 = V_111 -> args [ 0 ] ;
struct V_7 * V_8 ;
struct V_10 * V_10 = F_40 ( V_16 -> V_74 ) ;
for (; ; ) {
V_8 = F_41 ( V_10 , V_112 ) ;
if ( V_8 == NULL )
goto V_24;
if ( F_24 ( V_16 , F_42 ( V_111 -> V_16 ) . V_68 ,
V_111 -> V_113 -> V_114 , V_115 ,
V_8 ) <= 0 )
goto V_24;
V_112 ++ ;
}
V_24:
V_111 -> args [ 0 ] = V_112 ;
return V_16 -> V_116 ;
}
static int F_43 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
T_1 V_4 = 0 ;
T_1 V_5 ;
T_1 V_117 ;
int V_19 = 0 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_118 V_35 = { 0 , } ;
struct V_10 * V_10 = F_2 ( V_3 ) ;
if ( ! V_3 -> V_11 [ V_14 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_4 = F_5 ( V_3 -> V_11 [ V_14 ] ) ;
V_8 = F_6 ( V_10 , V_4 ) ;
if ( ! V_8 ) {
V_19 = - V_67 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_13 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_5 = F_5 ( V_3 -> V_11 [ V_13 ] ) ;
V_9 = F_7 ( V_10 , V_8 , V_5 ) ;
if ( V_9 ) {
V_19 = - V_64 ;
goto V_24;
}
if ( ! V_3 -> V_11 [ V_119 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_117 = F_5 ( V_3 -> V_11 [ V_119 ] ) ;
if ( ! V_3 -> V_11 [ V_120 ] ) {
V_19 = - V_36 ;
goto V_24;
}
V_35 . V_121 = F_16 ( V_3 -> V_11 [ V_120 ] ) ;
if ( V_35 . V_121 >= V_122 ) {
V_19 = - V_36 ;
goto V_24;
}
if ( V_8 -> V_80 > 2 ) {
if ( V_3 -> V_11 [ V_123 ] )
V_35 . V_124 = F_16 ( V_3 -> V_11 [ V_123 ] ) ;
if ( V_3 -> V_11 [ V_125 ] )
V_35 . V_126 = F_15 ( V_3 -> V_11 [ V_125 ] ) ;
V_35 . V_127 = V_128 ;
if ( V_3 -> V_11 [ V_129 ] )
V_35 . V_127 = F_15 ( V_3 -> V_11 [ V_129 ] ) ;
V_35 . V_130 = 4 ;
if ( V_3 -> V_11 [ V_131 ] )
V_35 . V_130 = F_15 ( V_3 -> V_11 [ V_131 ] ) ;
if ( V_3 -> V_11 [ V_132 ] ) {
T_2 V_116 = F_44 ( V_3 -> V_11 [ V_132 ] ) ;
if ( V_116 > 8 ) {
V_19 = - V_36 ;
goto V_24;
}
V_35 . V_133 = V_116 ;
memcpy ( & V_35 . V_134 [ 0 ] , F_3 ( V_3 -> V_11 [ V_132 ] ) , V_116 ) ;
}
if ( V_3 -> V_11 [ V_135 ] ) {
T_2 V_116 = F_44 ( V_3 -> V_11 [ V_135 ] ) ;
if ( V_116 > 8 ) {
V_19 = - V_36 ;
goto V_24;
}
V_35 . V_136 = V_116 ;
memcpy ( & V_35 . V_137 [ 0 ] , F_3 ( V_3 -> V_11 [ V_135 ] ) , V_116 ) ;
}
if ( V_3 -> V_11 [ V_12 ] )
V_35 . V_6 = F_3 ( V_3 -> V_11 [ V_12 ] ) ;
if ( V_3 -> V_11 [ V_138 ] )
V_35 . V_139 = F_16 ( V_3 -> V_11 [ V_138 ] ) ;
}
if ( V_3 -> V_11 [ V_62 ] )
V_35 . V_63 = F_5 ( V_3 -> V_11 [ V_62 ] ) ;
if ( V_3 -> V_11 [ V_140 ] )
V_35 . V_141 = F_15 ( V_3 -> V_11 [ V_140 ] ) ;
if ( V_3 -> V_11 [ V_142 ] )
V_35 . V_143 = F_15 ( V_3 -> V_11 [ V_142 ] ) ;
if ( V_3 -> V_11 [ V_144 ] )
V_35 . V_145 = F_15 ( V_3 -> V_11 [ V_144 ] ) ;
if ( V_3 -> V_11 [ V_146 ] )
V_35 . V_147 = F_45 ( V_3 -> V_11 [ V_146 ] ) ;
if ( V_3 -> V_11 [ V_148 ] )
V_35 . V_149 = F_16 ( V_3 -> V_11 [ V_148 ] ) ;
if ( V_3 -> V_11 [ V_150 ] )
V_35 . V_151 = F_16 ( V_3 -> V_11 [ V_150 ] ) ;
if ( ( V_152 [ V_35 . V_121 ] == NULL ) ||
( V_152 [ V_35 . V_121 ] -> V_153 == NULL ) ) {
V_19 = - V_154 ;
goto V_24;
}
switch ( V_35 . V_121 ) {
case V_155 :
break;
case V_156 :
if ( ! V_3 -> V_11 [ V_138 ] ) {
V_19 = - V_36 ;
goto V_24;
}
break;
case V_157 :
break;
case V_158 :
case V_159 :
break;
case V_160 :
default:
V_19 = - V_154 ;
break;
}
V_19 = - V_154 ;
if ( V_152 [ V_35 . V_121 ] -> V_153 )
V_19 = ( * V_152 [ V_35 . V_121 ] -> V_153 ) ( V_10 , V_4 ,
V_5 , V_117 , & V_35 ) ;
V_24:
return V_19 ;
}
static int F_46 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
T_2 V_121 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
V_121 = V_9 -> V_161 ;
if ( V_121 < V_122 )
if ( V_152 [ V_121 ] && V_152 [ V_121 ] -> V_162 )
V_19 = ( * V_152 [ V_121 ] -> V_162 ) ( V_9 ) ;
V_24:
return V_19 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
int V_19 = 0 ;
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
if ( V_3 -> V_11 [ V_62 ] )
V_9 -> V_63 = F_5 ( V_3 -> V_11 [ V_62 ] ) ;
if ( V_3 -> V_11 [ V_125 ] )
V_9 -> V_126 = F_15 ( V_3 -> V_11 [ V_125 ] ) ;
if ( V_3 -> V_11 [ V_140 ] )
V_9 -> V_141 = F_15 ( V_3 -> V_11 [ V_140 ] ) ;
if ( V_3 -> V_11 [ V_142 ] ) {
V_9 -> V_143 = F_15 ( V_3 -> V_11 [ V_142 ] ) ;
F_48 ( V_9 , V_9 -> V_8 -> V_80 ) ;
}
if ( V_3 -> V_11 [ V_144 ] )
V_9 -> V_145 = F_15 ( V_3 -> V_11 [ V_144 ] ) ;
if ( V_3 -> V_11 [ V_146 ] )
V_9 -> V_147 = F_45 ( V_3 -> V_11 [ V_146 ] ) ;
if ( V_3 -> V_11 [ V_148 ] )
V_9 -> V_149 = F_16 ( V_3 -> V_11 [ V_148 ] ) ;
if ( V_3 -> V_11 [ V_150 ] )
V_9 -> V_151 = F_16 ( V_3 -> V_11 [ V_150 ] ) ;
V_24:
return V_19 ;
}
static int F_49 ( struct V_15 * V_16 , T_1 V_68 , T_1 V_69 , int V_70 ,
struct V_1 * V_9 )
{
void * V_18 ;
struct V_71 * V_72 ;
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_73 * V_74 = NULL ;
V_74 = V_8 -> V_73 ;
V_18 = F_10 ( V_16 , V_68 , V_69 , & V_27 , V_70 , V_163 ) ;
if ( ! V_18 )
return - V_29 ;
if ( F_26 ( V_16 , V_14 , V_8 -> V_4 ) ||
F_26 ( V_16 , V_13 , V_9 -> V_5 ) ||
F_26 ( V_16 , V_37 , V_8 -> V_31 ) ||
F_26 ( V_16 , V_119 ,
V_9 -> V_117 ) ||
F_26 ( V_16 , V_62 , V_9 -> V_63 ) ||
F_27 ( V_16 , V_120 , V_9 -> V_161 ) ||
F_27 ( V_16 , V_148 , V_9 -> V_149 ) ||
( V_9 -> V_151 &&
F_27 ( V_16 , V_150 , V_9 -> V_151 ) ) )
goto V_81;
if ( ( V_9 -> V_6 [ 0 ] &&
F_50 ( V_16 , V_12 , V_9 -> V_6 ) ) ||
( V_9 -> V_133 &&
F_35 ( V_16 , V_132 , V_9 -> V_133 ,
& V_9 -> V_134 [ 0 ] ) ) ||
( V_9 -> V_136 &&
F_35 ( V_16 , V_135 , V_9 -> V_136 ,
& V_9 -> V_137 [ 0 ] ) ) ||
F_25 ( V_16 , V_140 , V_9 -> V_141 ) ||
F_25 ( V_16 , V_142 , V_9 -> V_143 ) ||
F_25 ( V_16 , V_144 , V_9 -> V_145 ) ||
#ifdef F_51
( ( ( V_74 ) && ( V_74 -> V_164 [ 0 ] || V_74 -> V_164 [ 1 ] ) ) &&
F_25 ( V_16 , V_165 , 1 ) ) ||
#endif
( V_9 -> V_147 &&
F_52 ( V_16 , V_146 , V_9 -> V_147 ) ) )
goto V_81;
V_72 = F_28 ( V_16 , V_82 ) ;
if ( V_72 == NULL )
goto V_81;
if ( F_29 ( V_16 , V_83 ,
F_30 ( & V_9 -> V_84 . V_85 ) ) ||
F_29 ( V_16 , V_86 ,
F_30 ( & V_9 -> V_84 . V_87 ) ) ||
F_29 ( V_16 , V_88 ,
F_30 ( & V_9 -> V_84 . V_89 ) ) ||
F_29 ( V_16 , V_90 ,
F_30 ( & V_9 -> V_84 . V_91 ) ) ||
F_29 ( V_16 , V_92 ,
F_30 ( & V_9 -> V_84 . V_93 ) ) ||
F_29 ( V_16 , V_94 ,
F_30 ( & V_9 -> V_84 . V_95 ) ) ||
F_29 ( V_16 , V_96 ,
F_30 ( & V_9 -> V_84 . V_97 ) ) ||
F_29 ( V_16 , V_98 ,
F_30 ( & V_9 -> V_84 . V_99 ) ) )
goto V_81;
F_31 ( V_16 , V_72 ) ;
return F_11 ( V_16 , V_18 ) ;
V_81:
F_37 ( V_16 , V_18 ) ;
return - 1 ;
}
static int F_53 ( struct V_15 * V_16 , struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_15 * V_17 ;
int V_19 ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 == NULL ) {
V_19 = - V_67 ;
goto V_24;
}
V_17 = F_9 ( V_21 , V_22 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_24;
}
V_19 = F_49 ( V_17 , V_3 -> V_25 , V_3 -> V_26 ,
0 , V_9 ) ;
if ( V_19 < 0 )
goto V_30;
return F_12 ( F_2 ( V_3 ) , V_17 , V_3 -> V_25 ) ;
V_30:
F_13 ( V_17 ) ;
V_24:
return V_19 ;
}
static int F_54 ( struct V_15 * V_16 , struct V_110 * V_111 )
{
struct V_10 * V_10 = F_40 ( V_16 -> V_74 ) ;
struct V_1 * V_9 ;
struct V_7 * V_8 = NULL ;
int V_112 = V_111 -> args [ 0 ] ;
int V_166 = V_111 -> args [ 1 ] ;
for (; ; ) {
if ( V_8 == NULL ) {
V_8 = F_41 ( V_10 , V_112 ) ;
if ( V_8 == NULL )
goto V_24;
}
V_9 = F_55 ( V_8 , V_166 ) ;
if ( V_9 == NULL ) {
V_112 ++ ;
V_8 = NULL ;
V_166 = 0 ;
continue;
}
if ( F_49 ( V_16 , F_42 ( V_111 -> V_16 ) . V_68 ,
V_111 -> V_113 -> V_114 , V_115 ,
V_9 ) <= 0 )
break;
V_166 ++ ;
}
V_24:
V_111 -> args [ 0 ] = V_112 ;
V_111 -> args [ 1 ] = V_166 ;
return V_16 -> V_116 ;
}
int F_56 ( enum V_167 V_121 , const struct V_152 * V_168 )
{
int V_19 ;
V_19 = - V_36 ;
if ( V_121 >= V_122 )
goto V_169;
F_57 () ;
V_19 = - V_170 ;
if ( V_152 [ V_121 ] )
goto V_24;
V_152 [ V_121 ] = V_168 ;
V_19 = 0 ;
V_24:
F_58 () ;
V_169:
return V_19 ;
}
void F_59 ( enum V_167 V_121 )
{
if ( V_121 < V_122 ) {
F_57 () ;
V_152 [ V_121 ] = NULL ;
F_58 () ;
}
}
static int F_60 ( void )
{
F_61 ( L_1 ) ;
return F_62 ( & V_27 , V_171 ) ;
}
static void F_63 ( void )
{
F_64 ( & V_27 ) ;
}
