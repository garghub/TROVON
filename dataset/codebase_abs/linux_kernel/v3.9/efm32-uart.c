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
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_5 = & V_2 -> V_5 ;
while ( F_3 ( V_2 , V_9 ) &
V_38 ) {
T_1 V_39 = F_3 ( V_2 , V_40 ) ;
int V_41 = 0 ;
V_39 &= ~ V_42 ;
V_5 -> V_27 . V_43 ++ ;
if ( ( V_39 & V_44 ) &&
! ( V_39 & V_45 ) ) {
V_39 |= V_42 ;
V_5 -> V_27 . V_46 ++ ;
if ( F_20 ( V_5 ) )
continue;
} else if ( V_39 & V_47 )
V_5 -> V_27 . V_48 ++ ;
else if ( V_39 & V_44 )
V_5 -> V_27 . V_49 ++ ;
V_39 &= V_5 -> V_50 ;
if ( V_39 & V_42 )
V_41 = V_51 ;
else if ( V_39 & V_47 )
V_41 = V_52 ;
else if ( V_39 & V_44 )
V_41 = V_53 ;
else if ( F_21 ( V_5 ,
V_39 & V_45 ) )
continue;
if ( ( V_39 & V_5 -> V_54 ) == 0 )
F_22 ( & V_5 -> V_24 -> V_5 ,
V_39 & V_45 , V_41 ) ;
}
}
static T_2 F_23 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
T_1 V_57 = F_3 ( V_2 , V_58 ) ;
int V_59 = V_60 ;
struct V_7 * V_5 = & V_2 -> V_5 ;
struct V_61 * V_62 = & V_5 -> V_24 -> V_5 ;
F_24 ( & V_5 -> V_63 ) ;
if ( V_57 & V_64 ) {
F_1 ( V_2 , V_64 , V_34 ) ;
F_19 ( V_2 ) ;
V_59 = V_65 ;
}
if ( V_57 & V_66 ) {
F_1 ( V_2 , V_66 , V_34 ) ;
V_5 -> V_27 . V_67 ++ ;
F_22 ( V_62 , 0 , V_68 ) ;
V_59 = V_65 ;
}
F_25 ( V_62 ) ;
F_26 ( & V_5 -> V_63 ) ;
return V_59 ;
}
static T_2 F_27 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
T_1 V_57 = F_3 ( V_2 , V_58 ) ;
if ( V_57 & V_20 )
F_1 ( V_2 , V_20 , V_34 ) ;
if ( V_57 & ( V_20 | V_21 ) ) {
F_10 ( V_2 ) ;
return V_65 ;
} else
return V_60 ;
}
static int F_28 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_69 ;
V_69 = F_29 ( V_2 -> V_70 ) ;
if ( V_69 ) {
F_30 ( V_2 , L_1 ) ;
goto V_71;
}
V_5 -> V_72 = F_31 ( V_2 -> V_70 ) ;
F_1 ( V_2 ,
F_32 ( V_2 -> V_73 . V_74 ) |
V_75 | V_76 ,
V_77 ) ;
V_69 = F_33 ( V_5 -> V_55 , F_23 , 0 ,
V_78 , V_2 ) ;
if ( V_69 ) {
F_30 ( V_2 , L_2 ) ;
goto V_79;
}
F_1 ( V_2 , 0 , V_17 ) ;
V_69 = F_33 ( V_2 -> V_80 , F_27 , 0 ,
V_78 , V_2 ) ;
if ( V_69 ) {
F_30 ( V_2 , L_3 ) ;
F_34 ( V_5 -> V_55 , V_2 ) ;
V_79:
F_35 ( V_2 -> V_70 ) ;
} else {
F_1 ( V_2 ,
V_64 | V_66 , V_17 ) ;
F_1 ( V_2 , V_81 , V_19 ) ;
}
V_71:
return V_69 ;
}
static void F_36 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_1 ( V_2 , 0 , V_17 ) ;
F_34 ( V_5 -> V_55 , V_2 ) ;
F_35 ( V_2 -> V_70 ) ;
}
static void F_37 ( struct V_7 * V_5 ,
struct V_82 * V_83 , struct V_82 * V_84 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned long V_85 ;
unsigned V_86 ;
T_1 V_87 ;
T_1 V_49 = 0 ;
V_83 -> V_88 &= ~ ( V_89 | V_90 ) ;
V_86 = F_38 ( V_5 , V_83 , V_84 ,
F_39 ( V_5 -> V_72 , 16 * 8192 ) ,
F_39 ( V_5 -> V_72 , 16 ) ) ;
switch ( V_83 -> V_88 & V_91 ) {
case V_92 :
V_49 |= F_40 ( 5 ) ;
break;
case V_93 :
V_49 |= F_40 ( 6 ) ;
break;
case V_94 :
V_49 |= F_40 ( 7 ) ;
break;
case V_95 :
V_49 |= F_40 ( 8 ) ;
break;
}
if ( V_83 -> V_88 & V_96 )
V_49 |= V_97 ;
else
V_49 |= V_98 ;
if ( V_83 -> V_88 & V_99 ) {
if ( V_83 -> V_88 & V_100 )
V_49 |= V_101 ;
else
V_49 |= V_102 ;
} else
V_49 |= V_103 ;
V_87 = ( F_39 ( 4 * V_5 -> V_72 , 16 * V_86 ) - 4 ) << 6 ;
F_41 ( & V_5 -> V_63 , V_85 ) ;
F_1 ( V_2 ,
V_18 | V_36 , V_19 ) ;
V_5 -> V_50 = V_45 ;
if ( V_83 -> V_104 & V_105 )
V_5 -> V_50 |=
V_44 | V_47 ;
if ( V_83 -> V_104 & ( V_106 | V_107 ) )
V_5 -> V_50 |= V_42 ;
V_5 -> V_54 = 0 ;
if ( V_83 -> V_104 & V_108 )
V_5 -> V_54 |=
V_44 | V_47 ;
if ( V_83 -> V_104 & V_109 )
V_5 -> V_54 |= V_42 ;
F_42 ( V_5 , V_83 -> V_88 , V_86 ) ;
F_1 ( V_2 , V_110 , V_111 ) ;
F_1 ( V_2 , V_49 , V_112 ) ;
F_1 ( V_2 , V_87 , V_113 ) ;
F_1 ( V_2 , V_35 | V_81 ,
V_19 ) ;
F_43 ( & V_5 -> V_63 , V_85 ) ;
}
static const char * F_44 ( struct V_7 * V_5 )
{
return V_5 -> type == V_114 ? L_4 : NULL ;
}
static void F_45 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
F_46 ( V_2 -> V_70 ) ;
F_47 ( V_2 -> V_70 ) ;
F_48 ( V_5 -> V_6 ) ;
}
static int F_49 ( struct V_7 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
int V_69 ;
V_5 -> V_6 = F_50 ( V_5 -> V_115 , 60 ) ;
if ( ! V_2 -> V_5 . V_6 ) {
V_69 = - V_116 ;
F_30 ( V_2 , L_5 ) ;
goto V_117;
}
V_2 -> V_70 = F_51 ( V_5 -> V_118 , NULL ) ;
if ( F_52 ( V_2 -> V_70 ) ) {
V_69 = F_53 ( V_2 -> V_70 ) ;
F_30 ( V_2 , L_6 ) ;
goto V_119;
}
V_69 = F_54 ( V_2 -> V_70 ) ;
if ( V_69 ) {
F_47 ( V_2 -> V_70 ) ;
V_119:
F_48 ( V_5 -> V_6 ) ;
V_117:
return V_69 ;
}
return 0 ;
}
static void F_55 ( struct V_7 * V_5 , int type )
{
if ( type & V_120 &&
! F_49 ( V_5 ) )
V_5 -> type = V_114 ;
}
static int F_56 ( struct V_7 * V_5 ,
struct V_121 * V_122 )
{
int V_69 = 0 ;
if ( V_122 -> type != V_123 && V_122 -> type != V_114 )
V_69 = - V_124 ;
return V_69 ;
}
static void F_57 ( struct V_7 * V_5 , int V_125 )
{
struct V_1 * V_2 = F_6 ( V_5 ) ;
unsigned int V_126 = 0x400 ;
T_1 V_8 ;
while ( 1 ) {
V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 & V_25 )
break;
if ( ! V_126 -- )
return;
}
F_1 ( V_2 , V_125 , V_29 ) ;
}
static void F_58 ( struct V_127 * V_128 , const char * V_129 ,
unsigned int V_130 )
{
struct V_1 * V_2 = V_131 [ V_128 -> V_132 ] ;
T_1 V_8 = F_3 ( V_2 , V_9 ) ;
unsigned int V_126 = 0x400 ;
if ( ! ( V_8 & V_133 ) )
F_1 ( V_2 , V_35 , V_19 ) ;
F_59 ( & V_2 -> V_5 , V_129 , V_130 ,
F_57 ) ;
while ( 1 ) {
T_1 V_8 = F_3 ( V_2 , V_9 ) ;
if ( V_8 & V_10 )
break;
if ( ! V_126 -- )
break;
}
if ( ! ( V_8 & V_133 ) )
F_1 ( V_2 , V_18 , V_19 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
int * V_86 , int * V_48 , int * V_134 )
{
T_1 V_135 = F_3 ( V_2 , V_111 ) ;
T_1 V_136 , V_87 , V_49 ;
if ( V_135 & V_137 )
return;
V_136 = F_3 ( V_2 , V_77 ) ;
if ( ! ( V_136 & V_76 ) )
return;
V_87 = F_3 ( V_2 , V_113 ) ;
* V_86 = F_39 ( 4 * V_2 -> V_5 . V_72 ,
16 * ( 4 + ( V_87 >> 6 ) ) ) ;
V_49 = F_3 ( V_2 , V_112 ) ;
if ( V_49 & V_101 )
* V_48 = 'o' ;
else if ( V_49 & V_102 )
* V_48 = 'e' ;
else
* V_48 = 'n' ;
* V_134 = ( V_49 & V_138 ) -
F_40 ( 4 ) + 4 ;
F_30 ( V_2 , L_7 ,
* V_86 , * V_48 , * V_134 ) ;
}
static int F_61 ( struct V_127 * V_128 , char * V_139 )
{
struct V_1 * V_2 ;
int V_86 = 115200 ;
int V_134 = 8 ;
int V_48 = 'n' ;
int V_140 = 'n' ;
int V_69 ;
if ( V_128 -> V_132 < 0 || V_128 -> V_132 >= F_62 ( V_131 ) ) {
unsigned V_141 ;
for ( V_141 = 0 ; V_141 < F_62 ( V_131 ) ; ++ V_141 ) {
if ( V_131 [ V_141 ] ) {
F_63 ( L_8 ,
V_141 , V_128 -> V_132 ) ;
V_128 -> V_132 = V_141 ;
break;
}
}
}
V_2 = V_131 [ V_128 -> V_132 ] ;
if ( ! V_2 ) {
F_63 ( L_9 , V_128 -> V_132 ) ;
return - V_142 ;
}
V_69 = F_54 ( V_2 -> V_70 ) ;
if ( V_69 ) {
F_64 ( V_2 -> V_5 . V_118 ,
L_10 , V_69 ) ;
return V_69 ;
}
V_2 -> V_5 . V_72 = F_31 ( V_2 -> V_70 ) ;
if ( V_139 )
F_65 ( V_139 , & V_86 , & V_48 , & V_134 , & V_140 ) ;
else
F_60 ( V_2 ,
& V_86 , & V_48 , & V_134 ) ;
return F_66 ( & V_2 -> V_5 , V_128 , V_86 , V_48 , V_134 , V_140 ) ;
}
static int F_67 ( struct V_143 * V_144 ,
struct V_1 * V_2 )
{
struct V_145 * V_146 = V_144 -> V_118 . V_147 ;
T_1 V_74 ;
int V_69 ;
if ( ! V_146 )
return 1 ;
V_69 = F_68 ( V_146 , L_11 , & V_74 ) ;
if ( ! V_69 ) {
if ( V_74 > 5 ) {
F_69 ( & V_144 -> V_118 , L_12 ) ;
return - V_124 ;
}
F_30 ( V_2 , L_13 , V_74 ) ;
V_2 -> V_73 . V_74 = V_74 ;
} else {
F_30 ( V_2 , L_14 ) ;
}
V_69 = F_70 ( V_146 , L_15 ) ;
if ( V_69 < 0 ) {
F_69 ( & V_144 -> V_118 , L_16 , V_69 ) ;
return V_69 ;
} else {
V_2 -> V_5 . line = V_69 ;
return 0 ;
}
}
static int F_71 ( struct V_143 * V_144 )
{
struct V_1 * V_2 ;
struct V_148 * V_149 ;
int V_69 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_150 ) ;
if ( ! V_2 ) {
F_73 ( & V_144 -> V_118 , L_17 ) ;
return - V_116 ;
}
V_149 = F_74 ( V_144 , V_151 , 0 ) ;
if ( ! V_149 ) {
V_69 = - V_142 ;
F_73 ( & V_144 -> V_118 , L_18 ) ;
goto V_152;
}
if ( F_75 ( V_149 ) < 60 ) {
V_69 = - V_124 ;
F_73 ( & V_144 -> V_118 , L_19 ) ;
goto V_153;
}
V_69 = F_76 ( V_144 , 0 ) ;
if ( V_69 <= 0 ) {
F_73 ( & V_144 -> V_118 , L_20 ) ;
goto V_154;
}
V_2 -> V_5 . V_55 = V_69 ;
V_69 = F_76 ( V_144 , 1 ) ;
if ( V_69 <= 0 )
V_69 = V_2 -> V_5 . V_55 + 1 ;
V_2 -> V_80 = V_69 ;
V_2 -> V_5 . V_118 = & V_144 -> V_118 ;
V_2 -> V_5 . V_115 = V_149 -> V_155 ;
V_2 -> V_5 . type = V_114 ;
V_2 -> V_5 . V_156 = V_157 ;
V_2 -> V_5 . V_158 = 2 ;
V_2 -> V_5 . V_159 = & V_160 ;
V_2 -> V_5 . V_85 = V_161 ;
V_69 = F_67 ( V_144 , V_2 ) ;
if ( V_69 > 0 ) {
const struct V_162 * V_73 = F_77 ( & V_144 -> V_118 ) ;
V_2 -> V_5 . line = V_144 -> V_163 ;
if ( V_73 )
V_2 -> V_73 = * V_73 ;
}
if ( V_2 -> V_5 . line >= 0 &&
V_2 -> V_5 . line < F_62 ( V_131 ) )
V_131 [ V_2 -> V_5 . line ] = V_2 ;
V_69 = F_78 ( & V_164 , & V_2 -> V_5 ) ;
if ( V_69 ) {
F_73 ( & V_144 -> V_118 , L_21 , V_69 ) ;
if ( V_144 -> V_163 >= 0 && V_144 -> V_163 < F_62 ( V_131 ) )
V_131 [ V_144 -> V_163 ] = NULL ;
V_154:
V_153:
V_152:
F_79 ( V_2 ) ;
} else {
F_80 ( V_144 , V_2 ) ;
F_73 ( & V_144 -> V_118 , L_22 ) ;
}
return V_69 ;
}
static int F_81 ( struct V_143 * V_144 )
{
struct V_1 * V_2 = F_82 ( V_144 ) ;
F_80 ( V_144 , NULL ) ;
F_83 ( & V_164 , & V_2 -> V_5 ) ;
if ( V_144 -> V_163 >= 0 && V_144 -> V_163 < F_62 ( V_131 ) )
V_131 [ V_144 -> V_163 ] = NULL ;
F_79 ( V_2 ) ;
return 0 ;
}
static int T_3 F_84 ( void )
{
int V_69 ;
V_69 = F_85 ( & V_164 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_86 ( & V_165 ) ;
if ( V_69 )
F_87 ( & V_164 ) ;
F_88 ( L_23 ) ;
return V_69 ;
}
static void T_4 F_89 ( void )
{
F_90 ( & V_165 ) ;
F_87 ( & V_164 ) ;
}
