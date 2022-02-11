static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned V_4 )
{
F_2 ( V_3 , V_2 -> V_5 . V_6 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return F_4 ( V_2 -> V_5 . V_6 + V_4 ) ;
}
static unsigned int F_5 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_1 V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 & V_10 )
return V_11 ;
else
return 0 ;
}
static void F_7 ( struct V_7 * V_5 , unsigned int V_12 )
{
}
static unsigned int F_8 ( struct V_7 * V_5 )
{
return V_13 | V_14 | V_15 ;
}
static void F_9 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_1 V_16 = F_3 ( V_2 , V_17 ) ;
F_1 ( V_2 , V_18 , V_19 ) ;
V_16 &= ~ ( V_20 | V_21 ) ;
F_1 ( V_2 , V_16 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_5 = & V_2 -> V_5 ;
struct V_22 * V_23 = & V_5 -> V_24 -> V_23 ;
while ( F_3 ( V_2 , V_9 ) &
V_25 ) {
if ( V_5 -> V_26 ) {
V_5 -> V_27 . V_28 ++ ;
F_1 ( V_2 , V_5 -> V_26 ,
V_29 ) ;
V_5 -> V_26 = 0 ;
continue;
}
if ( ! F_11 ( V_23 ) && ! F_12 ( V_5 ) ) {
V_5 -> V_27 . V_28 ++ ;
F_1 ( V_2 , V_23 -> V_30 [ V_23 -> V_31 ] ,
V_29 ) ;
V_23 -> V_31 = ( V_23 -> V_31 + 1 ) & ( V_32 - 1 ) ;
} else
break;
}
if ( F_13 ( V_23 ) < V_33 )
F_14 ( V_5 ) ;
if ( ! V_5 -> V_26 && F_11 ( V_23 ) &&
F_3 ( V_2 , V_9 ) &
V_10 )
F_9 ( V_5 ) ;
}
static void F_15 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_1 V_16 ;
F_1 ( V_2 ,
V_21 | V_20 , V_34 ) ;
V_16 = F_3 ( V_2 , V_17 ) ;
F_1 ( V_2 ,
V_16 | V_21 | V_20 , V_17 ) ;
F_1 ( V_2 , V_35 , V_19 ) ;
F_10 ( V_2 ) ;
}
static void F_16 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_1 ( V_2 , V_36 , V_19 ) ;
}
static void F_17 ( struct V_7 * V_5 )
{
}
static void F_18 ( struct V_7 * V_5 , int V_37 )
{
}
static void F_19 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_7 * V_5 = & V_2 -> V_5 ;
while ( F_3 ( V_2 , V_9 ) &
V_40 ) {
T_1 V_41 = F_3 ( V_2 , V_42 ) ;
int V_43 = 0 ;
V_41 &= ~ V_44 ;
V_5 -> V_27 . V_45 ++ ;
if ( ( V_41 & V_46 ) &&
! ( V_41 & V_47 ) ) {
V_41 |= V_44 ;
V_5 -> V_27 . V_48 ++ ;
if ( F_20 ( V_5 ) )
continue;
} else if ( V_41 & V_49 )
V_5 -> V_27 . V_50 ++ ;
else if ( V_41 & V_46 )
V_5 -> V_27 . V_51 ++ ;
V_41 &= V_5 -> V_52 ;
if ( V_41 & V_44 )
V_43 = V_53 ;
else if ( V_41 & V_49 )
V_43 = V_54 ;
else if ( V_41 & V_46 )
V_43 = V_55 ;
else if ( F_21 ( V_5 ,
V_41 & V_47 ) )
continue;
if ( V_39 && ( V_41 & V_5 -> V_56 ) == 0 )
F_22 ( V_39 ,
V_41 & V_47 , V_43 ) ;
}
}
static T_2 F_23 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_1 V_59 = F_3 ( V_2 , V_60 ) ;
int V_61 = V_62 ;
struct V_7 * V_5 = & V_2 -> V_5 ;
struct V_38 * V_39 ;
F_24 ( & V_5 -> V_63 ) ;
V_39 = F_25 ( V_5 -> V_24 -> V_5 . V_39 ) ;
if ( V_59 & V_64 ) {
F_1 ( V_2 , V_64 , V_34 ) ;
F_19 ( V_2 , V_39 ) ;
V_61 = V_65 ;
}
if ( V_59 & V_66 ) {
F_1 ( V_2 , V_66 , V_34 ) ;
V_5 -> V_27 . V_67 ++ ;
if ( V_39 )
F_22 ( V_39 , 0 , V_68 ) ;
V_61 = V_65 ;
}
if ( V_39 ) {
F_26 ( V_39 ) ;
F_27 ( V_39 ) ;
}
F_28 ( & V_5 -> V_63 ) ;
return V_61 ;
}
static T_2 F_29 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_1 V_59 = F_3 ( V_2 , V_60 ) ;
if ( V_59 & V_20 )
F_1 ( V_2 , V_20 , V_34 ) ;
if ( V_59 & ( V_20 | V_21 ) ) {
F_10 ( V_2 ) ;
return V_65 ;
} else
return V_62 ;
}
static int F_30 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
T_1 V_69 = 0 ;
struct V_70 * V_71 = F_31 ( V_5 -> V_72 ) ;
int V_73 ;
if ( V_71 )
V_69 = F_32 ( V_71 -> V_69 ) ;
V_73 = F_33 ( V_2 -> V_74 ) ;
if ( V_73 ) {
F_34 ( V_2 , L_1 ) ;
goto V_75;
}
V_5 -> V_76 = F_35 ( V_2 -> V_74 ) ;
F_1 ( V_2 , V_69 | V_77 | V_78 ,
V_79 ) ;
V_73 = F_36 ( V_5 -> V_57 , F_23 , 0 ,
V_80 , V_2 ) ;
if ( V_73 ) {
F_34 ( V_2 , L_2 ) ;
goto V_81;
}
F_1 ( V_2 , 0 , V_17 ) ;
V_73 = F_36 ( V_2 -> V_82 , F_29 , 0 ,
V_80 , V_2 ) ;
if ( V_73 ) {
F_34 ( V_2 , L_3 ) ;
F_37 ( V_5 -> V_57 , V_2 ) ;
V_81:
F_38 ( V_2 -> V_74 ) ;
} else {
F_1 ( V_2 ,
V_64 | V_66 , V_17 ) ;
F_1 ( V_2 , V_83 , V_19 ) ;
}
V_75:
return V_73 ;
}
static void F_39 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_1 ( V_2 , 0 , V_17 ) ;
F_37 ( V_5 -> V_57 , V_2 ) ;
F_38 ( V_2 -> V_74 ) ;
}
static void F_40 ( struct V_7 * V_5 ,
struct V_84 * V_85 , struct V_84 * V_86 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned long V_87 ;
unsigned V_88 ;
T_1 V_89 ;
T_1 V_51 = 0 ;
V_85 -> V_90 &= ~ ( V_91 | V_92 ) ;
V_88 = F_41 ( V_5 , V_85 , V_86 ,
F_42 ( V_5 -> V_76 , 16 * 8192 ) ,
F_42 ( V_5 -> V_76 , 16 ) ) ;
switch ( V_85 -> V_90 & V_93 ) {
case V_94 :
V_51 |= F_43 ( 5 ) ;
break;
case V_95 :
V_51 |= F_43 ( 6 ) ;
break;
case V_96 :
V_51 |= F_43 ( 7 ) ;
break;
case V_97 :
V_51 |= F_43 ( 8 ) ;
break;
}
if ( V_85 -> V_90 & V_98 )
V_51 |= V_99 ;
else
V_51 |= V_100 ;
if ( V_85 -> V_90 & V_101 ) {
if ( V_85 -> V_90 & V_102 )
V_51 |= V_103 ;
else
V_51 |= V_104 ;
} else
V_51 |= V_105 ;
V_89 = ( F_42 ( 4 * V_5 -> V_76 , 16 * V_88 ) - 4 ) << 6 ;
F_44 ( & V_5 -> V_63 , V_87 ) ;
F_1 ( V_2 ,
V_18 | V_36 , V_19 ) ;
V_5 -> V_52 = V_47 ;
if ( V_85 -> V_106 & V_107 )
V_5 -> V_52 |=
V_46 | V_49 ;
if ( V_85 -> V_106 & ( V_108 | V_109 ) )
V_5 -> V_52 |= V_44 ;
V_5 -> V_56 = 0 ;
if ( V_85 -> V_106 & V_110 )
V_5 -> V_56 |=
V_46 | V_49 ;
if ( V_85 -> V_106 & V_111 )
V_5 -> V_56 |= V_44 ;
F_45 ( V_5 , V_85 -> V_90 , V_88 ) ;
F_1 ( V_2 , V_112 , V_113 ) ;
F_1 ( V_2 , V_51 , V_114 ) ;
F_1 ( V_2 , V_89 , V_115 ) ;
F_1 ( V_2 , V_35 | V_83 ,
V_19 ) ;
F_46 ( & V_5 -> V_63 , V_87 ) ;
}
static const char * F_47 ( struct V_7 * V_5 )
{
return V_5 -> type == V_116 ? L_4 : NULL ;
}
static void F_48 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_49 ( V_2 -> V_74 ) ;
F_50 ( V_2 -> V_74 ) ;
F_51 ( V_5 -> V_6 ) ;
}
static int F_52 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_73 ;
V_5 -> V_6 = F_53 ( V_5 -> V_117 , 60 ) ;
if ( ! V_2 -> V_5 . V_6 ) {
V_73 = - V_118 ;
F_34 ( V_2 , L_5 ) ;
goto V_119;
}
V_2 -> V_74 = F_54 ( V_5 -> V_72 , NULL ) ;
if ( F_55 ( V_2 -> V_74 ) ) {
V_73 = F_56 ( V_2 -> V_74 ) ;
F_34 ( V_2 , L_6 ) ;
goto V_120;
}
V_73 = F_57 ( V_2 -> V_74 ) ;
if ( V_73 ) {
F_50 ( V_2 -> V_74 ) ;
V_120:
F_51 ( V_5 -> V_6 ) ;
V_119:
return V_73 ;
}
return 0 ;
}
static void F_58 ( struct V_7 * V_5 , int type )
{
if ( type & V_121 &&
! F_52 ( V_5 ) )
V_5 -> type = V_116 ;
}
static int F_59 ( struct V_7 * V_5 ,
struct V_122 * V_123 )
{
int V_73 = 0 ;
if ( V_123 -> type != V_124 && V_123 -> type != V_116 )
V_73 = - V_125 ;
return V_73 ;
}
static void F_60 ( struct V_7 * V_5 , int V_126 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned int V_127 = 0x400 ;
T_1 V_8 ;
while ( 1 ) {
V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 & V_25 )
break;
if ( ! V_127 -- )
return;
}
F_1 ( V_2 , V_126 , V_29 ) ;
}
static void F_61 ( struct V_128 * V_129 , const char * V_130 ,
unsigned int V_131 )
{
struct V_1 * V_2 = V_132 [ V_129 -> V_133 ] ;
T_1 V_8 = F_3 ( V_2 , V_9 ) ;
unsigned int V_127 = 0x400 ;
if ( ! ( V_8 & V_134 ) )
F_1 ( V_2 , V_35 , V_19 ) ;
F_62 ( & V_2 -> V_5 , V_130 , V_131 ,
F_60 ) ;
while ( 1 ) {
T_1 V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 & V_10 )
break;
if ( ! V_127 -- )
break;
}
if ( ! ( V_8 & V_134 ) )
F_1 ( V_2 , V_18 , V_19 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
int * V_88 , int * V_50 , int * V_135 )
{
T_1 V_136 = F_3 ( V_2 , V_113 ) ;
T_1 V_137 , V_89 , V_51 ;
if ( V_136 & V_138 )
return;
V_137 = F_3 ( V_2 , V_79 ) ;
if ( ! ( V_137 & V_78 ) )
return;
V_89 = F_3 ( V_2 , V_115 ) ;
* V_88 = F_42 ( 4 * V_2 -> V_5 . V_76 ,
16 * ( 4 + ( V_89 >> 6 ) ) ) ;
V_51 = F_3 ( V_2 , V_114 ) ;
if ( V_51 & V_103 )
* V_50 = 'o' ;
else if ( V_51 & V_104 )
* V_50 = 'e' ;
else
* V_50 = 'n' ;
* V_135 = ( V_51 & V_139 ) -
F_43 ( 4 ) + 4 ;
F_34 ( V_2 , L_7 ,
* V_88 , * V_50 , * V_135 ) ;
}
static int F_64 ( struct V_128 * V_129 , char * V_140 )
{
struct V_1 * V_2 ;
int V_88 = 115200 ;
int V_135 = 8 ;
int V_50 = 'n' ;
int V_141 = 'n' ;
int V_73 ;
if ( V_129 -> V_133 < 0 || V_129 -> V_133 >= F_65 ( V_132 ) ) {
unsigned V_142 ;
for ( V_142 = 0 ; V_142 < F_65 ( V_132 ) ; ++ V_142 ) {
if ( V_132 [ V_142 ] ) {
F_66 ( L_8 ,
V_142 , V_129 -> V_133 ) ;
V_129 -> V_133 = V_142 ;
break;
}
}
}
V_2 = V_132 [ V_129 -> V_133 ] ;
if ( ! V_2 ) {
F_66 ( L_9 , V_129 -> V_133 ) ;
return - V_143 ;
}
V_73 = F_57 ( V_2 -> V_74 ) ;
if ( V_73 ) {
F_67 ( V_2 -> V_5 . V_72 ,
L_10 , V_73 ) ;
return V_73 ;
}
V_2 -> V_5 . V_76 = F_35 ( V_2 -> V_74 ) ;
if ( V_140 )
F_68 ( V_140 , & V_88 , & V_50 , & V_135 , & V_141 ) ;
else
F_63 ( V_2 ,
& V_88 , & V_50 , & V_135 ) ;
return F_69 ( & V_2 -> V_5 , V_129 , V_88 , V_50 , V_135 , V_141 ) ;
}
static int F_70 ( struct V_144 * V_145 ,
struct V_1 * V_2 )
{
struct V_146 * V_147 = V_145 -> V_72 . V_148 ;
int V_73 ;
if ( ! V_147 )
return 1 ;
V_73 = F_71 ( V_147 , L_11 ) ;
if ( V_73 < 0 ) {
F_72 ( & V_145 -> V_72 , L_12 , V_73 ) ;
return V_73 ;
} else {
V_2 -> V_5 . line = V_73 ;
return 0 ;
}
}
static int T_3 F_73 ( struct V_144 * V_145 )
{
struct V_1 * V_2 ;
struct V_149 * V_150 ;
int V_73 ;
V_2 = F_74 ( sizeof( * V_2 ) , V_151 ) ;
if ( ! V_2 ) {
F_75 ( & V_145 -> V_72 , L_13 ) ;
return - V_118 ;
}
V_150 = F_76 ( V_145 , V_152 , 0 ) ;
if ( ! V_150 ) {
V_73 = - V_143 ;
F_75 ( & V_145 -> V_72 , L_14 ) ;
goto V_153;
}
if ( F_77 ( V_150 ) < 60 ) {
V_73 = - V_125 ;
F_75 ( & V_145 -> V_72 , L_15 ) ;
goto V_154;
}
V_73 = F_78 ( V_145 , 0 ) ;
if ( V_73 <= 0 ) {
F_75 ( & V_145 -> V_72 , L_16 ) ;
goto V_155;
}
V_2 -> V_5 . V_57 = V_73 ;
V_73 = F_78 ( V_145 , 1 ) ;
if ( V_73 <= 0 )
V_73 = V_2 -> V_5 . V_57 + 1 ;
V_2 -> V_82 = V_73 ;
V_2 -> V_5 . V_72 = & V_145 -> V_72 ;
V_2 -> V_5 . V_117 = V_150 -> V_156 ;
V_2 -> V_5 . type = V_116 ;
V_2 -> V_5 . V_157 = V_158 ;
V_2 -> V_5 . V_159 = 2 ;
V_2 -> V_5 . V_160 = & V_161 ;
V_2 -> V_5 . V_87 = V_162 ;
V_73 = F_70 ( V_145 , V_2 ) ;
if ( V_73 > 0 )
V_2 -> V_5 . line = V_145 -> V_163 ;
if ( V_2 -> V_5 . line >= 0 &&
V_2 -> V_5 . line < F_65 ( V_132 ) )
V_132 [ V_2 -> V_5 . line ] = V_2 ;
V_73 = F_79 ( & V_164 , & V_2 -> V_5 ) ;
if ( V_73 ) {
F_75 ( & V_145 -> V_72 , L_17 , V_73 ) ;
if ( V_145 -> V_163 >= 0 && V_145 -> V_163 < F_65 ( V_132 ) )
V_132 [ V_145 -> V_163 ] = NULL ;
V_155:
V_154:
V_153:
F_80 ( V_2 ) ;
} else {
F_81 ( V_145 , V_2 ) ;
F_75 ( & V_145 -> V_72 , L_18 ) ;
}
return V_73 ;
}
static int T_4 F_82 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_83 ( V_145 ) ;
F_81 ( V_145 , NULL ) ;
F_84 ( & V_164 , & V_2 -> V_5 ) ;
if ( V_145 -> V_163 >= 0 && V_145 -> V_163 < F_65 ( V_132 ) )
V_132 [ V_145 -> V_163 ] = NULL ;
F_80 ( V_2 ) ;
return 0 ;
}
static int T_5 F_85 ( void )
{
int V_73 ;
V_73 = F_86 ( & V_164 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_87 ( & V_165 ) ;
if ( V_73 )
F_88 ( & V_164 ) ;
F_89 ( L_19 ) ;
return V_73 ;
}
static void T_6 F_90 ( void )
{
F_91 ( & V_165 ) ;
F_88 ( & V_164 ) ;
}
