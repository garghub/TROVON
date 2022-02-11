static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
int V_6 ;
do {
V_6 = F_2 ( V_2 , V_4 , V_5 ) ;
if ( V_6 != - V_7 )
break;
F_3 ( V_8 ) ;
V_6 = - V_9 ;
} while ( ! F_4 ( V_10 ) );
return V_6 ;
}
static int
F_5 ( struct V_11 * V_12 , struct V_13 * V_13 )
{
if ( V_12 -> V_14 != - V_7 )
return 0 ;
if ( V_12 -> V_14 == - V_7 )
F_6 ( V_13 , V_15 ) ;
V_12 -> V_14 = 0 ;
F_7 ( V_12 ) ;
F_8 ( V_12 , V_8 ) ;
return 1 ;
}
static int
F_9 ( struct V_1 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_23 ] ,
. V_24 = V_18 ,
. V_25 = V_20 ,
} ;
int V_26 ;
F_10 ( L_1 , V_27 ) ;
F_11 ( V_20 -> V_28 ) ;
V_26 = F_2 ( V_16 , & V_4 , 0 ) ;
F_10 ( L_2 , V_27 , V_26 ) ;
if ( V_26 == 0 && ! ( V_20 -> V_28 -> V_29 & V_30 ) ) {
V_4 . V_21 = & V_22 [ V_31 ] ;
V_4 . V_25 = V_20 -> V_28 ;
V_26 = F_2 ( V_16 , & V_4 , 0 ) ;
F_10 ( L_3 , V_27 , V_26 ) ;
}
return V_26 ;
}
static int
F_12 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_26 ;
V_26 = F_9 ( V_33 -> V_16 , V_18 , V_20 ) ;
if ( V_26 && V_33 -> V_34 -> V_35 != V_33 -> V_16 )
V_26 = F_9 ( V_33 -> V_34 -> V_35 , V_18 , V_20 ) ;
return V_26 ;
}
static int
F_13 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_36 * V_28 , struct V_37 * V_38 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_31 ] ,
. V_24 = V_18 ,
. V_25 = V_28 ,
} ;
int V_26 ;
F_10 ( L_4 ) ;
F_11 ( V_28 ) ;
V_26 = F_2 ( V_33 -> V_16 , & V_4 , 0 ) ;
F_10 ( L_5 , V_26 ) ;
return V_26 ;
}
static int
F_14 ( struct V_39 * V_39 , struct V_36 * V_28 ,
struct V_40 * V_41 )
{
struct V_13 * V_13 = F_15 ( V_39 ) ;
struct V_42 V_43 = {
. V_44 = F_16 ( V_13 ) ,
. V_41 = V_41 ,
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_45 ] ,
. V_24 = & V_43 ,
. V_25 = V_28 ,
} ;
int V_26 ;
F_10 ( L_6 ) ;
if ( V_41 -> V_46 & V_47 )
V_4 . V_48 = F_17 ( V_41 -> V_49 ) ;
F_11 ( V_28 ) ;
V_26 = F_2 ( F_18 ( V_13 ) , & V_4 , 0 ) ;
if ( V_26 == 0 )
F_19 ( V_13 , V_41 , V_28 ) ;
F_10 ( L_7 , V_26 ) ;
return V_26 ;
}
static int
F_20 ( struct V_13 * V_50 , const struct V_51 * V_52 ,
struct V_17 * V_18 , struct V_36 * V_28 ,
struct V_37 * V_38 )
{
struct V_53 V_43 = {
. V_44 = F_16 ( V_50 ) ,
. V_52 = V_52 -> V_52 ,
. V_54 = V_52 -> V_54
} ;
struct V_55 V_6 = {
. V_44 = V_18 ,
. V_28 = V_28
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_56 ] ,
. V_24 = & V_43 ,
. V_25 = & V_6 ,
} ;
int V_26 ;
F_10 ( L_8 , V_52 -> V_52 ) ;
V_6 . V_57 = F_21 () ;
if ( V_6 . V_57 == NULL )
return - V_58 ;
F_11 ( V_28 ) ;
V_26 = F_2 ( F_18 ( V_50 ) , & V_4 , 0 ) ;
F_22 ( V_50 , V_6 . V_57 ) ;
if ( V_26 >= 0 && ! ( V_28 -> V_29 & V_30 ) ) {
V_4 . V_21 = & V_22 [ V_31 ] ;
V_4 . V_24 = V_18 ;
V_4 . V_25 = V_28 ;
V_26 = F_2 ( F_18 ( V_50 ) , & V_4 , 0 ) ;
}
F_23 ( V_6 . V_57 ) ;
F_10 ( L_9 , V_26 ) ;
return V_26 ;
}
static int F_24 ( struct V_13 * V_13 , struct V_59 * V_60 )
{
struct V_61 V_43 = {
. V_44 = F_16 ( V_13 ) ,
} ;
struct V_62 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_63 ] ,
. V_24 = & V_43 ,
. V_25 = & V_6 ,
. V_48 = V_60 -> V_64 ,
} ;
int V_65 = V_60 -> V_66 ;
int V_26 = - V_58 ;
F_10 ( L_10 ) ;
if ( V_65 & V_67 )
V_43 . V_68 |= V_69 ;
if ( F_25 ( V_13 -> V_70 ) ) {
if ( V_65 & V_71 )
V_43 . V_68 |= V_72 | V_73 | V_74 ;
if ( V_65 & V_75 )
V_43 . V_68 |= V_76 ;
} else {
if ( V_65 & V_71 )
V_43 . V_68 |= V_72 | V_73 ;
if ( V_65 & V_75 )
V_43 . V_68 |= V_77 ;
}
V_6 . V_28 = F_21 () ;
if ( V_6 . V_28 == NULL )
goto V_78;
V_26 = F_2 ( F_18 ( V_13 ) , & V_4 , 0 ) ;
F_22 ( V_13 , V_6 . V_28 ) ;
if ( V_26 == 0 )
F_26 ( V_60 , V_6 . V_68 ) ;
F_23 ( V_6 . V_28 ) ;
V_78:
F_10 ( L_11 , V_26 ) ;
return V_26 ;
}
static int F_27 ( struct V_13 * V_13 , struct V_79 * V_79 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_36 * V_28 ;
struct V_82 args = {
. V_44 = F_16 ( V_13 ) ,
. V_80 = V_80 ,
. V_81 = V_81 ,
. V_83 = & V_79
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_84 ] ,
. V_24 = & args ,
} ;
int V_26 = - V_58 ;
F_10 ( L_12 ) ;
V_28 = F_21 () ;
if ( V_28 == NULL )
goto V_78;
V_4 . V_25 = V_28 ;
V_26 = F_2 ( F_18 ( V_13 ) , & V_4 , 0 ) ;
F_22 ( V_13 , V_28 ) ;
F_23 ( V_28 ) ;
V_78:
F_10 ( L_13 , V_26 ) ;
return V_26 ;
}
static struct V_85 * F_28 ( void )
{
struct V_85 * V_86 ;
V_86 = F_29 ( sizeof( * V_86 ) , V_87 ) ;
if ( V_86 != NULL ) {
V_86 -> V_4 . V_24 = & V_86 -> V_43 ;
V_86 -> V_4 . V_25 = & V_86 -> V_6 ;
V_86 -> V_6 . V_44 = & V_86 -> V_44 ;
V_86 -> V_6 . V_28 = & V_86 -> V_28 ;
V_86 -> V_6 . V_57 = & V_86 -> V_57 ;
F_11 ( V_86 -> V_6 . V_28 ) ;
F_11 ( V_86 -> V_6 . V_57 ) ;
}
return V_86 ;
}
static int F_30 ( struct V_13 * V_50 , struct V_39 * V_39 , struct V_85 * V_86 )
{
int V_26 ;
V_26 = F_2 ( F_18 ( V_50 ) , & V_86 -> V_4 , 0 ) ;
F_31 ( V_50 , V_86 -> V_6 . V_57 ) ;
if ( V_26 == 0 )
V_26 = F_32 ( V_39 , V_86 -> V_6 . V_44 , V_86 -> V_6 . V_28 , NULL ) ;
return V_26 ;
}
static void F_33 ( struct V_85 * V_86 )
{
F_34 ( V_86 ) ;
}
static int
F_35 ( struct V_13 * V_50 , struct V_39 * V_39 , struct V_40 * V_41 ,
int V_5 )
{
struct V_88 * V_89 , * V_90 ;
struct V_85 * V_86 ;
int V_26 = - V_58 ;
F_10 ( L_14 , V_39 ) ;
V_86 = F_28 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_21 = & V_22 [ V_91 ] ;
V_86 -> V_43 . V_92 . V_44 = F_16 ( V_50 ) ;
V_86 -> V_43 . V_92 . V_52 = V_39 -> V_93 . V_52 ;
V_86 -> V_43 . V_92 . V_54 = V_39 -> V_93 . V_54 ;
V_86 -> V_43 . V_92 . V_41 = V_41 ;
V_86 -> V_43 . V_92 . V_94 = V_95 ;
if ( V_5 & V_96 ) {
V_86 -> V_43 . V_92 . V_94 = V_97 ;
V_86 -> V_43 . V_92 . V_98 [ 0 ] = F_36 ( V_99 ) ;
V_86 -> V_43 . V_92 . V_98 [ 1 ] = F_36 ( V_10 -> V_100 ) ;
}
V_26 = F_37 ( V_50 , & V_41 -> V_101 , & V_89 , & V_90 ) ;
if ( V_26 )
goto V_78;
for (; ; ) {
V_26 = F_30 ( V_50 , V_39 , V_86 ) ;
if ( V_26 != - V_102 )
break;
switch ( V_86 -> V_43 . V_92 . V_94 ) {
case V_97 :
V_86 -> V_43 . V_92 . V_94 = V_103 ;
break;
case V_103 :
V_86 -> V_43 . V_92 . V_94 = V_95 ;
break;
case V_95 :
goto V_78;
}
F_11 ( V_86 -> V_6 . V_57 ) ;
F_11 ( V_86 -> V_6 . V_28 ) ;
}
if ( V_26 != 0 )
goto V_104;
if ( V_86 -> V_43 . V_92 . V_94 == V_97 ) {
F_10 ( L_15 ) ;
if ( ! ( V_41 -> V_46 & V_105 ) )
V_41 -> V_46 |= V_106 ;
if ( ! ( V_41 -> V_46 & V_107 ) )
V_41 -> V_46 |= V_108 ;
V_26 = F_14 ( V_39 , V_86 -> V_6 . V_28 , V_41 ) ;
F_31 ( F_15 ( V_39 ) , V_86 -> V_6 . V_28 ) ;
F_10 ( L_16 , V_26 ) ;
if ( V_26 != 0 )
goto V_104;
}
V_26 = F_38 ( F_15 ( V_39 ) , V_90 , V_89 ) ;
V_104:
F_39 ( V_90 ) ;
F_39 ( V_89 ) ;
V_78:
F_33 ( V_86 ) ;
F_10 ( L_17 , V_26 ) ;
return V_26 ;
}
static int
F_40 ( struct V_13 * V_50 , const struct V_51 * V_52 )
{
struct V_109 V_43 = {
. V_44 = F_16 ( V_50 ) ,
. V_52 = * V_52 ,
} ;
struct V_110 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_111 ] ,
. V_24 = & V_43 ,
. V_25 = & V_6 ,
} ;
int V_26 = - V_58 ;
F_10 ( L_18 , V_52 -> V_52 ) ;
V_6 . V_57 = F_21 () ;
if ( V_6 . V_57 == NULL )
goto V_78;
V_26 = F_2 ( F_18 ( V_50 ) , & V_4 , 0 ) ;
F_31 ( V_50 , V_6 . V_57 ) ;
F_23 ( V_6 . V_57 ) ;
V_78:
F_10 ( L_19 , V_26 ) ;
return V_26 ;
}
static void
F_41 ( struct V_3 * V_4 , struct V_13 * V_50 )
{
V_4 -> V_21 = & V_22 [ V_111 ] ;
}
static void F_42 ( struct V_11 * V_12 , struct V_112 * V_86 )
{
F_43 ( V_12 ) ;
}
static int
F_44 ( struct V_11 * V_12 , struct V_13 * V_50 )
{
struct V_110 * V_6 ;
if ( F_5 ( V_12 , V_50 ) )
return 0 ;
V_6 = V_12 -> V_113 . V_25 ;
F_31 ( V_50 , V_6 -> V_57 ) ;
return 1 ;
}
static void
F_45 ( struct V_3 * V_4 , struct V_13 * V_50 )
{
V_4 -> V_21 = & V_22 [ V_114 ] ;
}
static void F_46 ( struct V_11 * V_12 , struct V_115 * V_86 )
{
F_43 ( V_12 ) ;
}
static int
F_47 ( struct V_11 * V_12 , struct V_13 * V_116 ,
struct V_13 * V_117 )
{
struct V_118 * V_6 ;
if ( F_5 ( V_12 , V_116 ) )
return 0 ;
V_6 = V_12 -> V_113 . V_25 ;
F_31 ( V_116 , V_6 -> V_119 ) ;
F_31 ( V_117 , V_6 -> V_120 ) ;
return 1 ;
}
static int
F_48 ( struct V_13 * V_13 , struct V_13 * V_50 , const struct V_51 * V_52 )
{
struct V_121 V_43 = {
. V_122 = F_16 ( V_13 ) ,
. V_123 = F_16 ( V_50 ) ,
. V_124 = V_52 -> V_52 ,
. V_125 = V_52 -> V_54
} ;
struct V_126 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_127 ] ,
. V_24 = & V_43 ,
. V_25 = & V_6 ,
} ;
int V_26 = - V_58 ;
F_10 ( L_20 , V_52 -> V_52 ) ;
V_6 . V_28 = F_21 () ;
V_6 . V_57 = F_21 () ;
if ( V_6 . V_28 == NULL || V_6 . V_57 == NULL )
goto V_78;
V_26 = F_2 ( F_18 ( V_13 ) , & V_4 , 0 ) ;
F_31 ( V_50 , V_6 . V_57 ) ;
F_31 ( V_13 , V_6 . V_28 ) ;
V_78:
F_23 ( V_6 . V_57 ) ;
F_23 ( V_6 . V_28 ) ;
F_10 ( L_21 , V_26 ) ;
return V_26 ;
}
static int
F_49 ( struct V_13 * V_50 , struct V_39 * V_39 , struct V_79 * V_79 ,
unsigned int V_54 , struct V_40 * V_41 )
{
struct V_85 * V_86 ;
int V_26 = - V_58 ;
if ( V_54 > V_128 )
return - V_129 ;
F_10 ( L_22 , V_39 ) ;
V_86 = F_28 () ;
if ( V_86 == NULL )
goto V_78;
V_86 -> V_4 . V_21 = & V_22 [ V_130 ] ;
V_86 -> V_43 . V_131 . V_122 = F_16 ( V_50 ) ;
V_86 -> V_43 . V_131 . V_132 = V_39 -> V_93 . V_52 ;
V_86 -> V_43 . V_131 . V_133 = V_39 -> V_93 . V_54 ;
V_86 -> V_43 . V_131 . V_83 = & V_79 ;
V_86 -> V_43 . V_131 . V_134 = V_54 ;
V_86 -> V_43 . V_131 . V_41 = V_41 ;
V_26 = F_30 ( V_50 , V_39 , V_86 ) ;
F_33 ( V_86 ) ;
V_78:
F_10 ( L_23 , V_26 ) ;
return V_26 ;
}
static int
F_50 ( struct V_13 * V_50 , struct V_39 * V_39 , struct V_40 * V_41 )
{
struct V_88 * V_89 , * V_90 ;
struct V_85 * V_86 ;
int V_26 = - V_58 ;
F_10 ( L_24 , V_39 ) ;
V_86 = F_28 () ;
if ( V_86 == NULL )
goto V_78;
V_26 = F_37 ( V_50 , & V_41 -> V_101 , & V_89 , & V_90 ) ;
if ( V_26 )
goto V_78;
V_86 -> V_4 . V_21 = & V_22 [ V_135 ] ;
V_86 -> V_43 . V_136 . V_44 = F_16 ( V_50 ) ;
V_86 -> V_43 . V_136 . V_52 = V_39 -> V_93 . V_52 ;
V_86 -> V_43 . V_136 . V_54 = V_39 -> V_93 . V_54 ;
V_86 -> V_43 . V_136 . V_41 = V_41 ;
V_26 = F_30 ( V_50 , V_39 , V_86 ) ;
if ( V_26 != 0 )
goto V_104;
V_26 = F_38 ( F_15 ( V_39 ) , V_90 , V_89 ) ;
V_104:
F_39 ( V_90 ) ;
F_39 ( V_89 ) ;
V_78:
F_33 ( V_86 ) ;
F_10 ( L_25 , V_26 ) ;
return V_26 ;
}
static int
F_51 ( struct V_13 * V_50 , const struct V_51 * V_52 )
{
struct V_36 * V_57 ;
struct V_53 V_43 = {
. V_44 = F_16 ( V_50 ) ,
. V_52 = V_52 -> V_52 ,
. V_54 = V_52 -> V_54
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_137 ] ,
. V_24 = & V_43 ,
} ;
int V_26 = - V_58 ;
F_10 ( L_26 , V_52 -> V_52 ) ;
V_57 = F_21 () ;
if ( V_57 == NULL )
goto V_78;
V_4 . V_25 = V_57 ;
V_26 = F_2 ( F_18 ( V_50 ) , & V_4 , 0 ) ;
F_31 ( V_50 , V_57 ) ;
F_23 ( V_57 ) ;
V_78:
F_10 ( L_27 , V_26 ) ;
return V_26 ;
}
static int
F_52 ( struct V_39 * V_39 , struct V_48 * V_64 ,
T_1 V_138 , struct V_79 * * V_83 , unsigned int V_139 , bool V_140 )
{
struct V_13 * V_50 = F_15 ( V_39 ) ;
T_2 * V_141 = F_53 ( V_50 ) -> V_142 ;
struct V_143 V_43 = {
. V_44 = F_16 ( V_50 ) ,
. V_138 = V_138 ,
. V_141 = { V_141 [ 0 ] , V_141 [ 1 ] } ,
. V_140 = V_140 ,
. V_139 = V_139 ,
. V_83 = V_83
} ;
struct V_144 V_6 = {
. V_141 = V_141 ,
. V_140 = V_140
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_145 ] ,
. V_24 = & V_43 ,
. V_25 = & V_6 ,
. V_48 = V_64
} ;
int V_26 = - V_58 ;
if ( V_140 )
V_4 . V_21 = & V_22 [ V_146 ] ;
F_10 ( L_28 ,
V_140 ? L_29 : L_30 , ( unsigned int ) V_138 ) ;
V_6 . V_57 = F_21 () ;
if ( V_6 . V_57 == NULL )
goto V_78;
V_26 = F_2 ( F_18 ( V_50 ) , & V_4 , 0 ) ;
F_54 ( V_50 ) ;
F_22 ( V_50 , V_6 . V_57 ) ;
F_23 ( V_6 . V_57 ) ;
V_78:
F_10 ( L_31 ,
V_140 ? L_29 : L_30 , V_26 ) ;
return V_26 ;
}
static int
F_55 ( struct V_13 * V_50 , struct V_39 * V_39 , struct V_40 * V_41 ,
T_3 V_147 )
{
struct V_88 * V_89 , * V_90 ;
struct V_85 * V_86 ;
int V_26 = - V_58 ;
F_10 ( L_32 , V_39 ,
F_56 ( V_147 ) , F_57 ( V_147 ) ) ;
V_86 = F_28 () ;
if ( V_86 == NULL )
goto V_78;
V_26 = F_37 ( V_50 , & V_41 -> V_101 , & V_89 , & V_90 ) ;
if ( V_26 )
goto V_78;
V_86 -> V_4 . V_21 = & V_22 [ V_148 ] ;
V_86 -> V_43 . V_149 . V_44 = F_16 ( V_50 ) ;
V_86 -> V_43 . V_149 . V_52 = V_39 -> V_93 . V_52 ;
V_86 -> V_43 . V_149 . V_54 = V_39 -> V_93 . V_54 ;
V_86 -> V_43 . V_149 . V_41 = V_41 ;
V_86 -> V_43 . V_149 . V_147 = V_147 ;
switch ( V_41 -> V_101 & V_150 ) {
case V_151 :
V_86 -> V_43 . V_149 . type = V_152 ;
break;
case V_153 :
V_86 -> V_43 . V_149 . type = V_154 ;
break;
case V_155 :
V_86 -> V_43 . V_149 . type = V_156 ;
break;
case V_157 :
V_86 -> V_43 . V_149 . type = V_158 ;
break;
default:
V_26 = - V_159 ;
goto V_78;
}
V_26 = F_30 ( V_50 , V_39 , V_86 ) ;
if ( V_26 != 0 )
goto V_104;
V_26 = F_38 ( F_15 ( V_39 ) , V_90 , V_89 ) ;
V_104:
F_39 ( V_90 ) ;
F_39 ( V_89 ) ;
V_78:
F_33 ( V_86 ) ;
F_10 ( L_33 , V_26 ) ;
return V_26 ;
}
static int
F_58 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_160 * V_161 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_162 ] ,
. V_24 = V_18 ,
. V_25 = V_161 ,
} ;
int V_26 ;
F_10 ( L_34 ) ;
F_11 ( V_161 -> V_28 ) ;
V_26 = F_2 ( V_33 -> V_16 , & V_4 , 0 ) ;
F_10 ( L_35 , V_26 ) ;
return V_26 ;
}
static int
F_59 ( struct V_1 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_23 ] ,
. V_24 = V_18 ,
. V_25 = V_20 ,
} ;
int V_26 ;
F_10 ( L_36 ) ;
F_11 ( V_20 -> V_28 ) ;
V_26 = F_2 ( V_16 , & V_4 , 0 ) ;
F_10 ( L_37 , V_26 ) ;
return V_26 ;
}
static int
F_60 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_26 ;
V_26 = F_59 ( V_33 -> V_16 , V_18 , V_20 ) ;
if ( V_26 && V_33 -> V_34 -> V_35 != V_33 -> V_16 )
V_26 = F_59 ( V_33 -> V_34 -> V_35 , V_18 , V_20 ) ;
return V_26 ;
}
static int
F_61 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_163 * V_20 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_164 ] ,
. V_24 = V_18 ,
. V_25 = V_20 ,
} ;
int V_26 ;
F_10 ( L_38 ) ;
F_11 ( V_20 -> V_28 ) ;
V_26 = F_2 ( V_33 -> V_16 , & V_4 , 0 ) ;
F_10 ( L_39 , V_26 ) ;
return V_26 ;
}
static int F_62 ( struct V_11 * V_12 , struct V_165 * V_166 )
{
struct V_13 * V_13 = V_166 -> V_13 ;
if ( V_166 -> V_167 != NULL )
return V_166 -> V_167 ( V_12 , V_166 ) ;
if ( F_5 ( V_12 , V_13 ) )
return - V_168 ;
F_54 ( V_13 ) ;
F_22 ( V_13 , & V_166 -> V_28 ) ;
return 0 ;
}
static void F_63 ( struct V_165 * V_166 ,
struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_169 ] ;
}
static int F_64 ( struct V_11 * V_12 ,
struct V_165 * V_166 )
{
F_43 ( V_12 ) ;
return 0 ;
}
static int F_65 ( struct V_11 * V_12 , struct V_165 * V_166 )
{
struct V_13 * V_13 = V_166 -> V_13 ;
if ( V_166 -> V_167 != NULL )
return V_166 -> V_167 ( V_12 , V_166 ) ;
if ( F_5 ( V_12 , V_13 ) )
return - V_168 ;
if ( V_12 -> V_14 >= 0 )
F_66 ( V_166 ) ;
return 0 ;
}
static void F_67 ( struct V_165 * V_166 ,
struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_170 ] ;
}
static void F_68 ( struct V_11 * V_12 , struct V_171 * V_86 )
{
F_43 ( V_12 ) ;
}
static int F_69 ( struct V_11 * V_12 , struct V_171 * V_86 )
{
if ( V_86 -> V_172 != NULL )
return V_86 -> V_172 ( V_12 , V_86 ) ;
if ( F_5 ( V_12 , V_86 -> V_13 ) )
return - V_168 ;
F_22 ( V_86 -> V_13 , V_86 -> V_6 . V_28 ) ;
return 0 ;
}
static void F_70 ( struct V_171 * V_86 , struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_173 ] ;
}
static void F_71 ( void * V_86 )
{
struct V_174 * V_175 = V_86 ;
if ( V_175 && F_72 ( V_176 , & V_175 -> V_177 -> V_5 ) ) {
F_73 ( V_175 -> V_177 ) ;
F_74 ( V_175 -> V_177 ) ;
}
}
static bool F_75 ( struct V_11 * V_12 , void * V_86 )
{
struct V_174 * V_175 = V_86 ;
if ( V_175 && F_72 ( V_176 , & V_175 -> V_177 -> V_5 ) )
return F_76 ( V_12 , V_175 ) ;
return false ;
}
static void F_77 ( void * V_86 )
{
struct V_174 * V_175 = V_86 ;
struct V_178 * V_179 ;
if ( V_175 && F_72 ( V_176 , & V_175 -> V_177 -> V_5 ) ) {
V_179 = V_175 -> V_177 ;
F_78 ( V_175 ) ;
F_79 ( V_179 ) ;
}
}
static int
F_80 ( struct V_180 * V_181 , int V_182 , struct V_183 * V_184 )
{
struct V_13 * V_13 = F_81 ( V_181 ) ;
struct V_174 * V_175 = NULL ;
struct V_178 * V_179 = F_82 ( V_181 ) ;
int V_26 ;
if ( V_184 -> V_185 & V_186 ) {
V_175 = F_74 ( V_179 ) ;
if ( F_83 ( V_175 ) )
V_175 = NULL ;
else
F_84 ( V_176 , & V_179 -> V_5 ) ;
}
V_26 = F_85 ( F_86 ( V_13 ) -> V_187 , V_182 , V_184 , V_175 ) ;
if ( V_175 )
F_78 ( V_175 ) ;
return V_26 ;
}
static int F_87 ( struct V_13 * V_13 , T_4 V_5 )
{
return 0 ;
}
static int F_88 ( struct V_13 * V_13 )
{
F_89 ( V_13 ) ;
return 0 ;
}
