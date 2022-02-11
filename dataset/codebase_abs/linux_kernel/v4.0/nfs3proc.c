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
struct V_13 * V_13 = V_39 -> V_42 ;
struct V_43 V_44 = {
. V_45 = F_15 ( V_13 ) ,
. V_41 = V_41 ,
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_46 ] ,
. V_24 = & V_44 ,
. V_25 = V_28 ,
} ;
int V_26 ;
F_10 ( L_6 ) ;
if ( V_41 -> V_47 & V_48 )
V_4 . V_49 = F_16 ( V_41 -> V_50 ) ;
F_11 ( V_28 ) ;
V_26 = F_2 ( F_17 ( V_13 ) , & V_4 , 0 ) ;
if ( V_26 == 0 )
F_18 ( V_13 , V_41 , V_28 ) ;
F_10 ( L_7 , V_26 ) ;
return V_26 ;
}
static int
F_19 ( struct V_13 * V_51 , struct V_52 * V_53 ,
struct V_17 * V_18 , struct V_36 * V_28 ,
struct V_37 * V_38 )
{
struct V_54 V_44 = {
. V_45 = F_15 ( V_51 ) ,
. V_53 = V_53 -> V_53 ,
. V_55 = V_53 -> V_55
} ;
struct V_56 V_6 = {
. V_45 = V_18 ,
. V_28 = V_28
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_57 ] ,
. V_24 = & V_44 ,
. V_25 = & V_6 ,
} ;
int V_26 ;
F_10 ( L_8 , V_53 -> V_53 ) ;
V_6 . V_58 = F_20 () ;
if ( V_6 . V_58 == NULL )
return - V_59 ;
F_11 ( V_28 ) ;
V_26 = F_2 ( F_17 ( V_51 ) , & V_4 , 0 ) ;
F_21 ( V_51 , V_6 . V_58 ) ;
if ( V_26 >= 0 && ! ( V_28 -> V_29 & V_30 ) ) {
V_4 . V_21 = & V_22 [ V_31 ] ;
V_4 . V_24 = V_18 ;
V_4 . V_25 = V_28 ;
V_26 = F_2 ( F_17 ( V_51 ) , & V_4 , 0 ) ;
}
F_22 ( V_6 . V_58 ) ;
F_10 ( L_9 , V_26 ) ;
return V_26 ;
}
static int F_23 ( struct V_13 * V_13 , struct V_60 * V_61 )
{
struct V_62 V_44 = {
. V_45 = F_15 ( V_13 ) ,
} ;
struct V_63 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_64 ] ,
. V_24 = & V_44 ,
. V_25 = & V_6 ,
. V_49 = V_61 -> V_65 ,
} ;
int V_66 = V_61 -> V_67 ;
int V_26 = - V_59 ;
F_10 ( L_10 ) ;
if ( V_66 & V_68 )
V_44 . V_69 |= V_70 ;
if ( F_24 ( V_13 -> V_71 ) ) {
if ( V_66 & V_72 )
V_44 . V_69 |= V_73 | V_74 | V_75 ;
if ( V_66 & V_76 )
V_44 . V_69 |= V_77 ;
} else {
if ( V_66 & V_72 )
V_44 . V_69 |= V_73 | V_74 ;
if ( V_66 & V_76 )
V_44 . V_69 |= V_78 ;
}
V_6 . V_28 = F_20 () ;
if ( V_6 . V_28 == NULL )
goto V_79;
V_26 = F_2 ( F_17 ( V_13 ) , & V_4 , 0 ) ;
F_21 ( V_13 , V_6 . V_28 ) ;
if ( V_26 == 0 ) {
V_61 -> V_67 = 0 ;
if ( V_6 . V_69 & V_70 )
V_61 -> V_67 |= V_68 ;
if ( V_6 . V_69 & ( V_73 | V_74 | V_75 ) )
V_61 -> V_67 |= V_72 ;
if ( V_6 . V_69 & ( V_77 | V_78 ) )
V_61 -> V_67 |= V_76 ;
}
F_22 ( V_6 . V_28 ) ;
V_79:
F_10 ( L_11 , V_26 ) ;
return V_26 ;
}
static int F_25 ( struct V_13 * V_13 , struct V_80 * V_80 ,
unsigned int V_81 , unsigned int V_82 )
{
struct V_36 * V_28 ;
struct V_83 args = {
. V_45 = F_15 ( V_13 ) ,
. V_81 = V_81 ,
. V_82 = V_82 ,
. V_84 = & V_80
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_85 ] ,
. V_24 = & args ,
} ;
int V_26 = - V_59 ;
F_10 ( L_12 ) ;
V_28 = F_20 () ;
if ( V_28 == NULL )
goto V_79;
V_4 . V_25 = V_28 ;
V_26 = F_2 ( F_17 ( V_13 ) , & V_4 , 0 ) ;
F_21 ( V_13 , V_28 ) ;
F_22 ( V_28 ) ;
V_79:
F_10 ( L_13 , V_26 ) ;
return V_26 ;
}
static struct V_86 * F_26 ( void )
{
struct V_86 * V_87 ;
V_87 = F_27 ( sizeof( * V_87 ) , V_88 ) ;
if ( V_87 != NULL ) {
V_87 -> V_4 . V_24 = & V_87 -> V_44 ;
V_87 -> V_4 . V_25 = & V_87 -> V_6 ;
V_87 -> V_6 . V_45 = & V_87 -> V_45 ;
V_87 -> V_6 . V_28 = & V_87 -> V_28 ;
V_87 -> V_6 . V_58 = & V_87 -> V_58 ;
F_11 ( V_87 -> V_6 . V_28 ) ;
F_11 ( V_87 -> V_6 . V_58 ) ;
}
return V_87 ;
}
static int F_28 ( struct V_13 * V_51 , struct V_39 * V_39 , struct V_86 * V_87 )
{
int V_26 ;
V_26 = F_2 ( F_17 ( V_51 ) , & V_87 -> V_4 , 0 ) ;
F_29 ( V_51 , V_87 -> V_6 . V_58 ) ;
if ( V_26 == 0 )
V_26 = F_30 ( V_39 , V_87 -> V_6 . V_45 , V_87 -> V_6 . V_28 , NULL ) ;
return V_26 ;
}
static void F_31 ( struct V_86 * V_87 )
{
F_32 ( V_87 ) ;
}
static int
F_33 ( struct V_13 * V_51 , struct V_39 * V_39 , struct V_40 * V_41 ,
int V_5 )
{
struct V_89 * V_90 , * V_91 ;
struct V_86 * V_87 ;
int V_26 = - V_59 ;
F_10 ( L_14 , V_39 ) ;
V_87 = F_26 () ;
if ( V_87 == NULL )
goto V_79;
V_87 -> V_4 . V_21 = & V_22 [ V_92 ] ;
V_87 -> V_44 . V_93 . V_45 = F_15 ( V_51 ) ;
V_87 -> V_44 . V_93 . V_53 = V_39 -> V_94 . V_53 ;
V_87 -> V_44 . V_93 . V_55 = V_39 -> V_94 . V_55 ;
V_87 -> V_44 . V_93 . V_41 = V_41 ;
V_87 -> V_44 . V_93 . V_95 = V_96 ;
if ( V_5 & V_97 ) {
V_87 -> V_44 . V_93 . V_95 = V_98 ;
V_87 -> V_44 . V_93 . V_99 [ 0 ] = F_34 ( V_100 ) ;
V_87 -> V_44 . V_93 . V_99 [ 1 ] = F_34 ( V_10 -> V_101 ) ;
}
V_26 = F_35 ( V_51 , & V_41 -> V_102 , & V_90 , & V_91 ) ;
if ( V_26 )
goto V_79;
for (; ; ) {
V_26 = F_28 ( V_51 , V_39 , V_87 ) ;
if ( V_26 != - V_103 )
break;
switch ( V_87 -> V_44 . V_93 . V_95 ) {
case V_98 :
V_87 -> V_44 . V_93 . V_95 = V_104 ;
break;
case V_104 :
V_87 -> V_44 . V_93 . V_95 = V_96 ;
break;
case V_96 :
goto V_79;
}
F_11 ( V_87 -> V_6 . V_58 ) ;
F_11 ( V_87 -> V_6 . V_28 ) ;
}
if ( V_26 != 0 )
goto V_105;
if ( V_87 -> V_44 . V_93 . V_95 == V_98 ) {
F_10 ( L_15 ) ;
if ( ! ( V_41 -> V_47 & V_106 ) )
V_41 -> V_47 |= V_107 ;
if ( ! ( V_41 -> V_47 & V_108 ) )
V_41 -> V_47 |= V_109 ;
V_26 = F_14 ( V_39 , V_87 -> V_6 . V_28 , V_41 ) ;
F_29 ( V_39 -> V_42 , V_87 -> V_6 . V_28 ) ;
F_10 ( L_16 , V_26 ) ;
if ( V_26 != 0 )
goto V_105;
}
V_26 = F_36 ( V_39 -> V_42 , V_91 , V_90 ) ;
V_105:
F_37 ( V_91 ) ;
F_37 ( V_90 ) ;
V_79:
F_31 ( V_87 ) ;
F_10 ( L_17 , V_26 ) ;
return V_26 ;
}
static int
F_38 ( struct V_13 * V_51 , struct V_52 * V_53 )
{
struct V_110 V_44 = {
. V_45 = F_15 ( V_51 ) ,
. V_53 = * V_53 ,
} ;
struct V_111 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_112 ] ,
. V_24 = & V_44 ,
. V_25 = & V_6 ,
} ;
int V_26 = - V_59 ;
F_10 ( L_18 , V_53 -> V_53 ) ;
V_6 . V_58 = F_20 () ;
if ( V_6 . V_58 == NULL )
goto V_79;
V_26 = F_2 ( F_17 ( V_51 ) , & V_4 , 0 ) ;
F_29 ( V_51 , V_6 . V_58 ) ;
F_22 ( V_6 . V_58 ) ;
V_79:
F_10 ( L_19 , V_26 ) ;
return V_26 ;
}
static void
F_39 ( struct V_3 * V_4 , struct V_13 * V_51 )
{
V_4 -> V_21 = & V_22 [ V_112 ] ;
}
static void F_40 ( struct V_11 * V_12 , struct V_113 * V_87 )
{
F_41 ( V_12 ) ;
}
static int
F_42 ( struct V_11 * V_12 , struct V_13 * V_51 )
{
struct V_111 * V_6 ;
if ( F_5 ( V_12 , V_51 ) )
return 0 ;
V_6 = V_12 -> V_114 . V_25 ;
F_29 ( V_51 , V_6 -> V_58 ) ;
return 1 ;
}
static void
F_43 ( struct V_3 * V_4 , struct V_13 * V_51 )
{
V_4 -> V_21 = & V_22 [ V_115 ] ;
}
static void F_44 ( struct V_11 * V_12 , struct V_116 * V_87 )
{
F_41 ( V_12 ) ;
}
static int
F_45 ( struct V_11 * V_12 , struct V_13 * V_117 ,
struct V_13 * V_118 )
{
struct V_119 * V_6 ;
if ( F_5 ( V_12 , V_117 ) )
return 0 ;
V_6 = V_12 -> V_114 . V_25 ;
F_29 ( V_117 , V_6 -> V_120 ) ;
F_29 ( V_118 , V_6 -> V_121 ) ;
return 1 ;
}
static int
F_46 ( struct V_13 * V_13 , struct V_13 * V_51 , struct V_52 * V_53 )
{
struct V_122 V_44 = {
. V_123 = F_15 ( V_13 ) ,
. V_124 = F_15 ( V_51 ) ,
. V_125 = V_53 -> V_53 ,
. V_126 = V_53 -> V_55
} ;
struct V_127 V_6 ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_128 ] ,
. V_24 = & V_44 ,
. V_25 = & V_6 ,
} ;
int V_26 = - V_59 ;
F_10 ( L_20 , V_53 -> V_53 ) ;
V_6 . V_28 = F_20 () ;
V_6 . V_58 = F_20 () ;
if ( V_6 . V_28 == NULL || V_6 . V_58 == NULL )
goto V_79;
V_26 = F_2 ( F_17 ( V_13 ) , & V_4 , 0 ) ;
F_29 ( V_51 , V_6 . V_58 ) ;
F_29 ( V_13 , V_6 . V_28 ) ;
V_79:
F_22 ( V_6 . V_58 ) ;
F_22 ( V_6 . V_28 ) ;
F_10 ( L_21 , V_26 ) ;
return V_26 ;
}
static int
F_47 ( struct V_13 * V_51 , struct V_39 * V_39 , struct V_80 * V_80 ,
unsigned int V_55 , struct V_40 * V_41 )
{
struct V_86 * V_87 ;
int V_26 = - V_59 ;
if ( V_55 > V_129 )
return - V_130 ;
F_10 ( L_22 , V_39 ) ;
V_87 = F_26 () ;
if ( V_87 == NULL )
goto V_79;
V_87 -> V_4 . V_21 = & V_22 [ V_131 ] ;
V_87 -> V_44 . V_132 . V_123 = F_15 ( V_51 ) ;
V_87 -> V_44 . V_132 . V_133 = V_39 -> V_94 . V_53 ;
V_87 -> V_44 . V_132 . V_134 = V_39 -> V_94 . V_55 ;
V_87 -> V_44 . V_132 . V_84 = & V_80 ;
V_87 -> V_44 . V_132 . V_135 = V_55 ;
V_87 -> V_44 . V_132 . V_41 = V_41 ;
V_26 = F_28 ( V_51 , V_39 , V_87 ) ;
F_31 ( V_87 ) ;
V_79:
F_10 ( L_23 , V_26 ) ;
return V_26 ;
}
static int
F_48 ( struct V_13 * V_51 , struct V_39 * V_39 , struct V_40 * V_41 )
{
struct V_89 * V_90 , * V_91 ;
struct V_86 * V_87 ;
int V_26 = - V_59 ;
F_10 ( L_24 , V_39 ) ;
V_87 = F_26 () ;
if ( V_87 == NULL )
goto V_79;
V_26 = F_35 ( V_51 , & V_41 -> V_102 , & V_90 , & V_91 ) ;
if ( V_26 )
goto V_79;
V_87 -> V_4 . V_21 = & V_22 [ V_136 ] ;
V_87 -> V_44 . V_137 . V_45 = F_15 ( V_51 ) ;
V_87 -> V_44 . V_137 . V_53 = V_39 -> V_94 . V_53 ;
V_87 -> V_44 . V_137 . V_55 = V_39 -> V_94 . V_55 ;
V_87 -> V_44 . V_137 . V_41 = V_41 ;
V_26 = F_28 ( V_51 , V_39 , V_87 ) ;
if ( V_26 != 0 )
goto V_105;
V_26 = F_36 ( V_39 -> V_42 , V_91 , V_90 ) ;
V_105:
F_37 ( V_91 ) ;
F_37 ( V_90 ) ;
V_79:
F_31 ( V_87 ) ;
F_10 ( L_25 , V_26 ) ;
return V_26 ;
}
static int
F_49 ( struct V_13 * V_51 , struct V_52 * V_53 )
{
struct V_36 * V_58 ;
struct V_54 V_44 = {
. V_45 = F_15 ( V_51 ) ,
. V_53 = V_53 -> V_53 ,
. V_55 = V_53 -> V_55
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_138 ] ,
. V_24 = & V_44 ,
} ;
int V_26 = - V_59 ;
F_10 ( L_26 , V_53 -> V_53 ) ;
V_58 = F_20 () ;
if ( V_58 == NULL )
goto V_79;
V_4 . V_25 = V_58 ;
V_26 = F_2 ( F_17 ( V_51 ) , & V_4 , 0 ) ;
F_29 ( V_51 , V_58 ) ;
F_22 ( V_58 ) ;
V_79:
F_10 ( L_27 , V_26 ) ;
return V_26 ;
}
static int
F_50 ( struct V_39 * V_39 , struct V_49 * V_65 ,
T_1 V_139 , struct V_80 * * V_84 , unsigned int V_140 , int V_141 )
{
struct V_13 * V_51 = V_39 -> V_42 ;
T_2 * V_142 = F_51 ( V_51 ) -> V_143 ;
struct V_144 V_44 = {
. V_45 = F_15 ( V_51 ) ,
. V_139 = V_139 ,
. V_142 = { V_142 [ 0 ] , V_142 [ 1 ] } ,
. V_141 = V_141 ,
. V_140 = V_140 ,
. V_84 = V_84
} ;
struct V_145 V_6 = {
. V_142 = V_142 ,
. V_141 = V_141
} ;
struct V_3 V_4 = {
. V_21 = & V_22 [ V_146 ] ,
. V_24 = & V_44 ,
. V_25 = & V_6 ,
. V_49 = V_65
} ;
int V_26 = - V_59 ;
if ( V_141 )
V_4 . V_21 = & V_22 [ V_147 ] ;
F_10 ( L_28 ,
V_141 ? L_29 : L_30 , ( unsigned int ) V_139 ) ;
V_6 . V_58 = F_20 () ;
if ( V_6 . V_58 == NULL )
goto V_79;
V_26 = F_2 ( F_17 ( V_51 ) , & V_4 , 0 ) ;
F_52 ( V_51 ) ;
F_21 ( V_51 , V_6 . V_58 ) ;
F_22 ( V_6 . V_58 ) ;
V_79:
F_10 ( L_31 ,
V_141 ? L_29 : L_30 , V_26 ) ;
return V_26 ;
}
static int
F_53 ( struct V_13 * V_51 , struct V_39 * V_39 , struct V_40 * V_41 ,
T_3 V_148 )
{
struct V_89 * V_90 , * V_91 ;
struct V_86 * V_87 ;
int V_26 = - V_59 ;
F_10 ( L_32 , V_39 ,
F_54 ( V_148 ) , F_55 ( V_148 ) ) ;
V_87 = F_26 () ;
if ( V_87 == NULL )
goto V_79;
V_26 = F_35 ( V_51 , & V_41 -> V_102 , & V_90 , & V_91 ) ;
if ( V_26 )
goto V_79;
V_87 -> V_4 . V_21 = & V_22 [ V_149 ] ;
V_87 -> V_44 . V_150 . V_45 = F_15 ( V_51 ) ;
V_87 -> V_44 . V_150 . V_53 = V_39 -> V_94 . V_53 ;
V_87 -> V_44 . V_150 . V_55 = V_39 -> V_94 . V_55 ;
V_87 -> V_44 . V_150 . V_41 = V_41 ;
V_87 -> V_44 . V_150 . V_148 = V_148 ;
switch ( V_41 -> V_102 & V_151 ) {
case V_152 :
V_87 -> V_44 . V_150 . type = V_153 ;
break;
case V_154 :
V_87 -> V_44 . V_150 . type = V_155 ;
break;
case V_156 :
V_87 -> V_44 . V_150 . type = V_157 ;
break;
case V_158 :
V_87 -> V_44 . V_150 . type = V_159 ;
break;
default:
V_26 = - V_160 ;
goto V_79;
}
V_26 = F_28 ( V_51 , V_39 , V_87 ) ;
if ( V_26 != 0 )
goto V_105;
V_26 = F_36 ( V_39 -> V_42 , V_91 , V_90 ) ;
V_105:
F_37 ( V_91 ) ;
F_37 ( V_90 ) ;
V_79:
F_31 ( V_87 ) ;
F_10 ( L_33 , V_26 ) ;
return V_26 ;
}
static int
F_56 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_161 * V_162 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_163 ] ,
. V_24 = V_18 ,
. V_25 = V_162 ,
} ;
int V_26 ;
F_10 ( L_34 ) ;
F_11 ( V_162 -> V_28 ) ;
V_26 = F_2 ( V_33 -> V_16 , & V_4 , 0 ) ;
F_10 ( L_35 , V_26 ) ;
return V_26 ;
}
static int
F_57 ( struct V_1 * V_16 , struct V_17 * V_18 ,
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
F_58 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_26 ;
V_26 = F_57 ( V_33 -> V_16 , V_18 , V_20 ) ;
if ( V_26 && V_33 -> V_34 -> V_35 != V_33 -> V_16 )
V_26 = F_57 ( V_33 -> V_34 -> V_35 , V_18 , V_20 ) ;
return V_26 ;
}
static int
F_59 ( struct V_32 * V_33 , struct V_17 * V_18 ,
struct V_164 * V_20 )
{
struct V_3 V_4 = {
. V_21 = & V_22 [ V_165 ] ,
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
static int F_60 ( struct V_11 * V_12 , struct V_166 * V_167 )
{
struct V_13 * V_13 = V_167 -> V_13 ;
if ( V_167 -> V_168 != NULL )
return V_167 -> V_168 ( V_12 , V_167 ) ;
if ( F_5 ( V_12 , V_13 ) )
return - V_169 ;
F_52 ( V_13 ) ;
F_21 ( V_13 , & V_167 -> V_28 ) ;
return 0 ;
}
static void F_61 ( struct V_166 * V_167 ,
struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_170 ] ;
}
static int F_62 ( struct V_11 * V_12 ,
struct V_166 * V_167 )
{
F_41 ( V_12 ) ;
return 0 ;
}
static int F_63 ( struct V_11 * V_12 , struct V_166 * V_167 )
{
struct V_13 * V_13 = V_167 -> V_13 ;
if ( V_167 -> V_168 != NULL )
return V_167 -> V_168 ( V_12 , V_167 ) ;
if ( F_5 ( V_12 , V_13 ) )
return - V_169 ;
if ( V_12 -> V_14 >= 0 )
F_64 ( V_167 ) ;
return 0 ;
}
static void F_65 ( struct V_166 * V_167 ,
struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_171 ] ;
}
static void F_66 ( struct V_11 * V_12 , struct V_172 * V_87 )
{
F_41 ( V_12 ) ;
}
static int F_67 ( struct V_11 * V_12 , struct V_172 * V_87 )
{
if ( V_87 -> V_173 != NULL )
return V_87 -> V_173 ( V_12 , V_87 ) ;
if ( F_5 ( V_12 , V_87 -> V_13 ) )
return - V_169 ;
F_21 ( V_87 -> V_13 , V_87 -> V_6 . V_28 ) ;
return 0 ;
}
static void F_68 ( struct V_172 * V_87 , struct V_3 * V_4 )
{
V_4 -> V_21 = & V_22 [ V_174 ] ;
}
static int
F_69 ( struct V_175 * V_176 , int V_177 , struct V_178 * V_179 )
{
struct V_13 * V_13 = F_70 ( V_176 ) ;
return F_71 ( F_72 ( V_13 ) -> V_180 , V_177 , V_179 ) ;
}
static int F_73 ( struct V_13 * V_13 , T_4 V_5 )
{
return 0 ;
}
static int F_74 ( struct V_13 * V_13 )
{
F_75 ( V_13 ) ;
return 0 ;
}
