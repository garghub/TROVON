int F_1 ( void )
{
int V_1 = 0 ;
F_2 ( ( L_1 , V_2 , V_3 ) ) ;
V_1 = F_3 () ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_4 () ;
if ( V_1 < 0 ) {
if ( V_4 )
F_5 ( & V_5 ) ;
else
F_6 ( L_2 ) ;
F_7 () ;
} else {
F_8 ( & V_5 ) ;
}
F_9 ( ( L_3 , V_1 ) ) ;
return V_1 ;
}
static int F_3 ( void )
{
int V_1 = 0 ;
unsigned long V_6 ;
if ( V_7 == FALSE ) {
V_7 = TRUE ;
F_10 () ;
V_4 = 0 ;
F_2 ( ( L_4 ) ) ;
if ( ! V_8 ) {
V_1 = F_11 ( 0 , L_5 , & V_9 ) ;
if ( V_1 <= 0 ) {
F_2 ( ( L_6 , V_1 ) ) ;
V_1 = - V_10 ;
return V_1 ;
}
V_11 = V_1 ;
V_12 = F_12 ( V_13 , L_7 ) ;
F_13 ( V_12 , NULL ,
F_14 ( V_11 , 0 ) ,
NULL , L_7 ) ;
V_8 = TRUE ;
}
V_1 = F_15 () ;
if ( V_1 < 0 ) {
F_2 ( ( L_8 , V_1 ) ) ;
return V_1 ;
}
F_16 ( V_14 , V_6 ) ;
F_17 ( & V_15 ) ;
V_15 . V_16 = V_17 ;
V_15 . V_18 = 0 ;
V_19 = V_20 + F_18 ( V_21 ) ;
V_15 . V_22 = V_19 ;
F_19 ( V_14 , V_6 ) ;
F_20 ( & V_15 ) ;
V_23 = V_24 ;
}
return V_1 ;
}
static int F_4 ( void )
{
return F_21 ( & V_5 ) ;
}
static int F_22 ( struct V_25 * V_26 , const struct V_27 * V_28 )
{
int V_1 ;
V_1 = F_23 ( V_26 ) ;
if ( V_1 < 0 ) {
V_1 = - V_29 ;
} else {
V_1 = F_24 ( V_26 , V_28 -> V_30 ) ;
if ( V_1 == 0 ) {
V_4 ++ ;
F_9 ( ( L_9 , V_4 ) ) ;
}
}
return V_1 ;
}
static int F_24 ( struct V_25 * V_26 , int V_31 )
{
return F_25 ( V_26 , V_31 ) ;
}
static void F_26 ( struct V_25 * V_32 )
{
}
void F_7 ( void )
{
int V_33 ;
T_1 V_34 ;
F_16 ( V_14 , V_34 ) ;
V_35 = 1 ;
F_19 ( V_14 , V_34 ) ;
F_27 ( & V_15 ) ;
F_28 ( & V_5 ) ;
if ( V_8 ) {
F_29 ( V_12 , F_14 ( V_11 , 0 ) ) ;
F_30 ( V_12 ) ;
F_31 ( V_11 , L_5 ) ;
}
for ( V_33 = 0 ; V_33 < V_4 ; ++ V_33 ) {
F_32 ( V_36 [ V_33 ] ) ;
F_33 ( V_36 [ V_33 ] ) ;
F_34 ( V_36 [ V_33 ] ) ;
}
F_35 () ;
if ( V_4 )
F_5 ( & V_5 ) ;
}
static void F_34 ( struct V_37 * V_38 )
{
int V_33 = 0 ;
if ( ! V_38 || V_38 -> V_39 != V_40 )
return;
switch ( V_38 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
F_36 ( 0 , V_38 -> V_46 + 0x4c ) ;
break;
default:
break;
}
if ( V_38 -> V_47 )
F_37 ( V_38 -> V_47 , V_38 ) ;
F_38 ( & V_38 -> V_48 ) ;
if ( V_38 -> V_49 ) {
F_39 ( V_38 -> V_49 ) ;
V_38 -> V_49 = NULL ;
}
if ( V_38 -> V_50 ) {
unsigned long V_6 ;
F_16 ( V_51 , V_6 ) ;
V_38 -> V_52 = NULL ;
F_40 ( L_10 , V_38 -> V_50 ) ;
F_41 ( V_38 -> V_50 ) ;
V_38 -> V_50 = NULL ;
F_19 ( V_51 , V_6 ) ;
}
for ( V_33 = 0 ; V_33 < V_53 ; V_33 ++ ) {
if ( V_38 -> V_54 [ V_33 ] ) {
F_41 ( V_38 -> V_54 [ V_33 ] -> V_55 ) ;
F_41 ( V_38 -> V_54 [ V_33 ] -> V_56 ) ;
F_41 ( V_38 -> V_54 [ V_33 ] -> V_57 ) ;
F_41 ( V_38 -> V_54 [ V_33 ] ) ;
V_38 -> V_54 [ V_33 ] = NULL ;
}
}
F_41 ( V_38 -> V_58 ) ;
V_36 [ V_38 -> V_59 ] = NULL ;
F_41 ( V_38 ) ;
}
static int F_25 ( struct V_25 * V_26 , int V_60 )
{
struct V_37 * V_38 ;
unsigned int V_61 ;
int V_33 = 0 ;
int V_1 = 0 ;
unsigned long V_6 ;
V_38 = V_36 [ V_4 ] =
F_42 ( sizeof( * V_38 ) , V_62 ) ;
if ( ! V_38 )
return - V_63 ;
V_38 -> V_52 = V_38 -> V_50 =
F_42 ( sizeof( V_64 ) * 8192 , V_62 ) ;
if ( ! V_38 -> V_52 ) {
F_41 ( V_38 ) ;
return - V_63 ;
}
V_38 -> V_39 = V_40 ;
V_38 -> V_59 = V_4 ;
V_38 -> V_65 = V_66 [ V_60 ] . V_65 ;
V_38 -> V_41 = V_66 [ V_60 ] . V_41 ;
V_38 -> V_26 = V_26 ;
V_38 -> V_67 = V_26 -> V_68 -> V_69 ;
V_38 -> V_70 = F_43 ( V_26 -> V_71 ) ;
V_38 -> V_72 = V_73 [ V_60 ] . V_72 ;
V_38 -> V_74 = V_73 [ V_60 ] . V_74 ;
if ( V_73 [ V_33 ] . V_75 )
V_38 -> V_76 |= V_77 ;
V_38 -> V_78 = V_79 ;
F_44 ( & V_38 -> V_80 ) ;
F_45 ( V_38 -> V_81 ) ;
F_45 ( V_38 -> V_82 ) ;
V_38 -> V_83 = V_84 ;
for ( V_33 = 0 ; V_33 < V_53 ; V_33 ++ )
V_38 -> V_54 [ V_33 ] = NULL ;
F_46 ( V_26 , V_85 , & V_38 -> V_86 ) ;
F_46 ( V_26 , V_87 , & V_38 -> V_88 ) ;
F_47 ( V_26 , V_89 , & V_38 -> V_90 ) ;
V_61 = V_26 -> V_47 ;
V_38 -> V_47 = V_61 ;
switch ( V_38 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
case V_45 :
V_38 -> V_91 = V_92 | V_93 ;
F_9 ( ( L_11 ) ) ;
V_38 -> V_94 = F_48 ( V_26 , 4 ) ;
if ( ! V_38 -> V_94 ) {
F_2 ( ( L_12 ) ) ;
return - V_95 ;
}
V_38 -> V_96 = F_49 ( V_26 , 4 ) ;
if ( V_38 -> V_94 & 1 )
V_38 -> V_94 &= ~ 3 ;
else
V_38 -> V_94 &= ~ 15 ;
V_38 -> V_46 = F_48 ( V_26 , 1 ) ;
V_38 -> V_97 = F_49 ( V_26 , 1 ) ;
V_38 -> V_46 = ( ( unsigned int ) ( V_38 -> V_46 ) ) & 0xFFFE ;
V_38 -> V_98 = & V_99 ;
V_38 -> V_100 = 0x8 ;
V_38 -> V_101 = 921600 ;
F_50 ( V_38 ) ;
V_38 -> V_98 -> V_102 ( V_38 ) ;
F_36 ( 0x43 , V_38 -> V_46 + 0x4c ) ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
if ( V_38 -> V_76 & V_77 )
V_38 -> V_91 = V_116 | V_93 ;
else
V_38 -> V_91 = V_117 | V_93 ;
F_9 ( ( L_13 ) ) ;
V_38 -> V_94 = F_48 ( V_26 , 0 ) ;
V_38 -> V_96 = F_49 ( V_26 , 0 ) ;
if ( V_38 -> V_94 & 1 )
V_38 -> V_94 &= ~ 3 ;
else
V_38 -> V_94 &= ~ 15 ;
V_38 -> V_98 = & V_118 ;
V_38 -> V_100 = 0x200 ;
V_38 -> V_101 = 921600 ;
F_50 ( V_38 ) ;
if ( V_38 -> V_49 ) {
V_38 -> V_119 = F_51 ( V_38 -> V_49 + 0x8D ) ;
V_38 -> V_98 -> V_102 ( V_38 ) ;
}
break;
default:
F_2 ( ( L_14 ) ) ;
return - V_10 ;
}
V_1 = F_52 ( V_38 ) ;
if ( V_1 < 0 ) {
F_33 ( V_38 ) ;
F_2 ( ( L_15 , V_1 ) ) ;
V_38 -> V_83 = V_120 ;
V_38 -> V_78 = V_79 ;
goto V_121;
}
V_1 = F_53 ( V_38 ) ;
if ( V_1 < 0 ) {
F_2 ( ( L_16 , V_1 ) ) ;
V_38 -> V_83 = V_120 ;
V_38 -> V_78 = V_79 ;
goto V_121;
}
V_1 = F_54 ( V_38 ) ;
if ( V_1 < 0 ) {
F_33 ( V_38 ) ;
F_2 ( ( L_17 , V_1 ) ) ;
V_38 -> V_83 = V_120 ;
V_38 -> V_78 = V_79 ;
goto V_121;
}
V_38 -> V_83 = V_122 ;
V_38 -> V_78 = V_123 ;
F_55 ( V_38 ) ;
F_56 ( & V_38 -> V_48 , V_38 -> V_98 -> V_124 , ( unsigned long ) V_38 ) ;
F_9 ( ( L_18 , V_33 ) ) ;
F_16 ( V_51 , V_6 ) ;
V_38 -> V_52 = NULL ;
F_40 ( L_10 , V_38 -> V_50 ) ;
F_41 ( V_38 -> V_50 ) ;
V_38 -> V_50 = NULL ;
F_19 ( V_51 , V_6 ) ;
V_38 -> V_58 = F_42 ( V_125 , V_62 ) ;
F_57 ( & V_38 -> V_80 ) ;
return 0 ;
V_121:
return - V_10 ;
}
static int F_53 ( struct V_37 * V_38 )
{
int V_1 = 0 ;
F_9 ( ( L_19 ) ) ;
if ( ! V_38 || V_38 -> V_39 != V_40 )
return - V_95 ;
F_9 ( ( L_20 ) ) ;
if ( V_38 -> V_47 ) {
V_1 = F_58 ( V_38 -> V_47 , V_38 -> V_98 -> V_126 ,
V_127 , L_21 , V_38 ) ;
if ( V_1 ) {
F_59 ( & V_38 -> V_26 -> V_32 ,
L_22 , V_38 -> V_47 ) ;
V_38 -> V_83 = V_120 ;
V_38 -> V_78 = V_79 ;
V_1 = - V_95 ;
} else {
F_9 ( ( L_23 ,
V_38 -> V_47 ) ) ;
}
}
return V_1 ;
}
static void F_50 ( struct V_37 * V_38 )
{
if ( ! V_38 || V_38 -> V_39 != V_40 )
return;
V_38 -> V_49 = F_60 ( V_38 -> V_94 , 0x1000 ) ;
F_9 ( ( L_24 , V_38 -> V_49 ) ) ;
}
static void V_17 ( T_1 V_128 )
{
struct V_37 * V_38 ;
unsigned long V_34 ;
int V_33 ;
unsigned long V_129 ;
V_130 ++ ;
if ( V_23 != V_24 )
goto V_131;
for ( V_33 = 0 ; V_33 < V_4 ; V_33 ++ ) {
V_38 = V_36 [ V_33 ] ;
F_16 ( V_38 -> V_81 , V_34 ) ;
if ( V_38 -> V_83 == V_120 ) {
F_19 ( V_38 -> V_81 , V_34 ) ;
continue;
}
F_61 ( & V_38 -> V_48 ) ;
F_19 ( V_38 -> V_81 , V_34 ) ;
}
V_131:
F_16 ( V_14 , V_34 ) ;
V_19 += F_18 ( V_21 ) ;
V_129 = V_19 - V_20 ;
if ( ( T_1 ) V_129 >= 2 * V_21 )
V_19 = V_20 + F_18 ( V_21 ) ;
F_17 ( & V_15 ) ;
V_15 . V_16 = V_17 ;
V_15 . V_18 = 0 ;
V_15 . V_22 = V_19 ;
F_19 ( V_14 , V_34 ) ;
if ( ! V_35 )
F_20 ( & V_15 ) ;
}
static void F_10 ( void )
{
int V_33 = 0 ;
V_132 = V_133 ;
V_134 = V_135 ;
V_136 = V_137 ;
for ( V_33 = 0 ; V_33 < V_138 ; V_33 ++ )
V_36 [ V_33 ] = NULL ;
F_17 ( & V_15 ) ;
}
int F_62 ( T_1 V_139 )
{
V_140 -> V_83 = V_141 ;
F_63 ( ( V_139 * V_142 ) / 1000 ) ;
return F_64 ( V_140 ) ;
}
char * F_65 ( int V_143 )
{
switch ( V_143 ) {
case V_144 : return L_25 ;
case V_145 : return L_26 ;
case V_146 : return L_27 ;
case V_147 : return L_28 ;
case V_148 : return L_29 ;
case V_149 : return L_30 ;
case V_150 : return L_31 ;
case V_151 : return L_32 ;
case V_152 : return L_33 ;
case V_153 : return L_34 ;
case V_154 : return L_35 ;
case V_155 : return L_36 ;
case V_156 : return L_37 ;
case V_157 : return L_38 ;
case V_158 : return L_39 ;
case V_159 : return L_40 ;
case V_160 : return L_41 ;
case V_161 : return L_42 ;
case V_162 : return L_43 ;
case V_163 : return L_44 ;
case V_164 : return L_45 ;
case V_165 : return L_46 ;
case V_166 : return L_47 ;
case V_167 : return L_48 ;
case V_168 : return L_49 ;
case V_169 : return L_50 ;
case V_170 : return L_51 ;
case V_171 : return L_52 ;
case V_172 : return L_53 ;
case V_173 : return L_54 ;
case V_174 : return L_55 ;
case V_175 : return L_56 ;
case V_176 : return L_57 ;
case V_177 : return L_58 ;
case V_178 : return L_59 ;
case V_179 : return L_60 ;
default: return L_61 ;
}
}
