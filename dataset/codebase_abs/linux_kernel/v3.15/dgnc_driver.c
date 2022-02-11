int F_1 ( void )
{
int V_1 = 0 ;
F_2 ( ( L_1 , V_2 , V_3 ) ) ;
V_1 = F_3 () ;
if ( V_1 < 0 ) {
return V_1 ;
}
V_1 = F_4 () ;
if ( V_1 < 0 ) {
if ( V_4 )
F_5 ( & V_5 ) ;
else
F_6 ( L_2 ) ;
F_7 () ;
}
else {
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
#if F_36 ( V_37 )
F_37 () ;
#endif
if ( V_4 )
F_5 ( & V_5 ) ;
}
static void F_34 ( struct V_38 * V_39 )
{
int V_33 = 0 ;
if( ! V_39 || V_39 -> V_40 != V_41 )
return;
switch ( V_39 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
F_38 ( 0 , V_39 -> V_47 + 0x4c ) ;
break;
default:
break;
}
if ( V_39 -> V_48 )
F_39 ( V_39 -> V_48 , V_39 ) ;
F_40 ( & V_39 -> V_49 ) ;
if ( V_39 -> V_50 ) {
F_41 ( V_39 -> V_50 ) ;
V_39 -> V_50 = NULL ;
}
if ( V_39 -> V_51 ) {
unsigned long V_6 ;
F_16 ( V_52 , V_6 ) ;
V_39 -> V_53 = NULL ;
F_42 ( L_10 , V_39 -> V_51 ) ;
F_43 ( V_39 -> V_51 ) ;
V_39 -> V_51 = NULL ;
F_19 ( V_52 , V_6 ) ;
}
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ ) {
if ( V_39 -> V_55 [ V_33 ] ) {
if ( V_39 -> V_55 [ V_33 ] -> V_56 )
F_43 ( V_39 -> V_55 [ V_33 ] -> V_56 ) ;
if ( V_39 -> V_55 [ V_33 ] -> V_57 )
F_43 ( V_39 -> V_55 [ V_33 ] -> V_57 ) ;
if ( V_39 -> V_55 [ V_33 ] -> V_58 )
F_43 ( V_39 -> V_55 [ V_33 ] -> V_58 ) ;
F_43 ( V_39 -> V_55 [ V_33 ] ) ;
V_39 -> V_55 [ V_33 ] = NULL ;
}
}
if ( V_39 -> V_59 )
F_43 ( V_39 -> V_59 ) ;
V_36 [ V_39 -> V_60 ] = NULL ;
F_43 ( V_39 ) ;
}
static int F_25 ( struct V_25 * V_26 , int V_61 )
{
struct V_38 * V_39 ;
unsigned int V_62 ;
int V_33 = 0 ;
int V_1 = 0 ;
unsigned long V_6 ;
V_39 = V_36 [ V_4 ] =
F_44 ( sizeof( * V_39 ) , V_63 ) ;
if ( ! V_39 )
return - V_64 ;
V_39 -> V_53 = V_39 -> V_51 =
F_44 ( sizeof( V_65 ) * 8192 , V_63 ) ;
if ( ! V_39 -> V_53 ) {
F_43 ( V_39 ) ;
return - V_64 ;
}
V_39 -> V_40 = V_41 ;
V_39 -> V_60 = V_4 ;
V_39 -> V_66 = V_67 [ V_61 ] . V_66 ;
V_39 -> V_42 = V_67 [ V_61 ] . V_42 ;
V_39 -> V_26 = V_26 ;
V_39 -> V_68 = V_26 -> V_69 -> V_70 ;
V_39 -> V_71 = F_45 ( V_26 -> V_72 ) ;
V_39 -> V_73 = V_74 [ V_61 ] . V_73 ;
V_39 -> V_75 = V_74 [ V_61 ] . V_75 ;
if ( V_74 [ V_33 ] . V_76 )
V_39 -> V_77 |= V_78 ;
V_39 -> V_79 = V_80 ;
F_46 ( & V_39 -> V_81 ) ;
F_47 ( V_39 -> V_82 ) ;
F_47 ( V_39 -> V_83 ) ;
V_39 -> V_84 = V_85 ;
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ ) {
V_39 -> V_55 [ V_33 ] = NULL ;
}
F_48 ( V_26 , V_86 , & V_39 -> V_87 ) ;
F_48 ( V_26 , V_88 , & V_39 -> V_89 ) ;
F_49 ( V_26 , V_90 , & V_39 -> V_91 ) ;
V_62 = V_26 -> V_48 ;
V_39 -> V_48 = V_62 ;
switch( V_39 -> V_42 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
V_39 -> V_92 = V_93 | V_94 ;
F_9 ( ( L_11 ) ) ;
V_39 -> V_95 = F_50 ( V_26 , 4 ) ;
if ( ! V_39 -> V_95 ) {
F_2 ( ( L_12 ) ) ;
return - V_96 ;
}
V_39 -> V_97 = F_51 ( V_26 , 4 ) ;
if ( V_39 -> V_95 & 1 )
V_39 -> V_95 &= ~ 3 ;
else
V_39 -> V_95 &= ~ 15 ;
V_39 -> V_47 = F_50 ( V_26 , 1 ) ;
V_39 -> V_98 = F_51 ( V_26 , 1 ) ;
V_39 -> V_47 = ( ( unsigned int ) ( V_39 -> V_47 ) ) & 0xFFFE ;
V_39 -> V_99 = & V_100 ;
V_39 -> V_101 = 0x8 ;
V_39 -> V_102 = 921600 ;
F_52 ( V_39 ) ;
V_39 -> V_99 -> V_103 ( V_39 ) ;
F_38 ( 0x43 , V_39 -> V_47 + 0x4c ) ;
break;
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
case V_116 :
if ( V_39 -> V_77 & V_78 )
V_39 -> V_92 = V_117 | V_94 ;
else
V_39 -> V_92 = V_118 | V_94 ;
F_9 ( ( L_13 ) ) ;
V_39 -> V_95 = F_50 ( V_26 , 0 ) ;
V_39 -> V_97 = F_51 ( V_26 , 0 ) ;
if ( V_39 -> V_95 & 1 )
V_39 -> V_95 &= ~ 3 ;
else
V_39 -> V_95 &= ~ 15 ;
V_39 -> V_99 = & V_119 ;
V_39 -> V_101 = 0x200 ;
V_39 -> V_102 = 921600 ;
F_52 ( V_39 ) ;
if ( V_39 -> V_50 ) {
V_39 -> V_120 = F_53 ( V_39 -> V_50 + 0x8D ) ;
V_39 -> V_99 -> V_103 ( V_39 ) ;
}
break;
default:
F_2 ( ( L_14 ) ) ;
return - V_10 ;
}
V_1 = F_54 ( V_39 ) ;
if ( V_1 < 0 ) {
F_33 ( V_39 ) ;
F_2 ( ( L_15 , V_1 ) ) ;
V_39 -> V_84 = V_121 ;
V_39 -> V_79 = V_80 ;
goto V_122;
}
V_1 = F_55 ( V_39 ) ;
if ( V_1 < 0 ) {
F_2 ( ( L_16 , V_1 ) ) ;
V_39 -> V_84 = V_121 ;
V_39 -> V_79 = V_80 ;
goto V_122;
}
V_1 = F_56 ( V_39 ) ;
if ( V_1 < 0 ) {
F_33 ( V_39 ) ;
F_2 ( ( L_17 , V_1 ) ) ;
V_39 -> V_84 = V_121 ;
V_39 -> V_79 = V_80 ;
goto V_122;
}
V_39 -> V_84 = V_123 ;
V_39 -> V_79 = V_124 ;
F_57 ( V_39 ) ;
F_58 ( & V_39 -> V_49 , V_39 -> V_99 -> V_125 , ( unsigned long ) V_39 ) ;
F_9 ( ( L_18 , V_33 ) ) ;
F_16 ( V_52 , V_6 ) ;
V_39 -> V_53 = NULL ;
F_42 ( L_10 , V_39 -> V_51 ) ;
F_43 ( V_39 -> V_51 ) ;
V_39 -> V_51 = NULL ;
F_19 ( V_52 , V_6 ) ;
V_39 -> V_59 = F_44 ( V_126 , V_63 ) ;
F_59 ( & V_39 -> V_81 ) ;
return 0 ;
V_122:
return - V_10 ;
}
static int F_55 ( struct V_38 * V_39 ) {
int V_1 = 0 ;
F_9 ( ( L_19 ) ) ;
if ( ! V_39 || V_39 -> V_40 != V_41 )
return - V_96 ;
F_9 ( ( L_20 ) ) ;
if ( V_39 -> V_48 ) {
V_1 = F_60 ( V_39 -> V_48 , V_39 -> V_99 -> V_127 , V_128 , L_21 , V_39 ) ;
if ( V_1 ) {
F_42 ( L_22 , V_39 -> V_48 ) ;
V_39 -> V_84 = V_121 ;
V_39 -> V_79 = V_80 ;
V_1 = - V_96 ;
} else {
F_9 ( ( L_23 , V_39 -> V_48 ) ) ;
}
}
return V_1 ;
}
static void F_52 ( struct V_38 * V_39 )
{
if ( ! V_39 || V_39 -> V_40 != V_41 )
return;
V_39 -> V_50 = F_61 ( V_39 -> V_95 , 0x1000 ) ;
F_9 ( ( L_24 , V_39 -> V_50 ) ) ;
}
static void V_17 ( T_1 V_129 )
{
struct V_38 * V_39 ;
unsigned long V_34 ;
int V_33 ;
unsigned long V_130 ;
V_131 ++ ;
if ( V_23 != V_24 ) {
goto V_132;
}
for ( V_33 = 0 ; V_33 < V_4 ; V_33 ++ ) {
V_39 = V_36 [ V_33 ] ;
F_16 ( V_39 -> V_82 , V_34 ) ;
if ( V_39 -> V_84 == V_121 ) {
F_19 ( V_39 -> V_82 , V_34 ) ;
continue;
}
F_62 ( & V_39 -> V_49 ) ;
F_19 ( V_39 -> V_82 , V_34 ) ;
}
V_132:
F_16 ( V_14 , V_34 ) ;
V_19 += F_18 ( V_21 ) ;
V_130 = V_19 - V_20 ;
if ( ( T_1 ) V_130 >= 2 * V_21 ) {
V_19 = V_20 + F_18 ( V_21 ) ;
}
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
V_133 = V_134 ;
V_135 = V_136 ;
V_137 = V_138 ;
for ( V_33 = 0 ; V_33 < V_139 ; V_33 ++ ) {
V_36 [ V_33 ] = NULL ;
}
F_17 ( & V_15 ) ;
}
int F_63 ( T_1 V_140 )
{
V_141 -> V_84 = V_142 ;
F_64 ( ( V_140 * V_143 ) / 1000 ) ;
return F_65 ( V_141 ) ;
}
char * F_66 ( int V_144 )
{
switch( V_144 ) {
case V_145 : return L_25 ;
case V_146 : return L_26 ;
case V_147 : return L_27 ;
case V_148 : return L_28 ;
case V_149 : return L_29 ;
case V_150 : return L_30 ;
case V_151 : return L_31 ;
case V_152 : return L_32 ;
case V_153 : return L_33 ;
case V_154 : return L_34 ;
case V_155 : return L_35 ;
case V_156 : return L_36 ;
case V_157 : return L_37 ;
case V_158 : return L_38 ;
case V_159 : return L_39 ;
case V_160 : return L_40 ;
case V_161 : return L_41 ;
case V_162 : return L_42 ;
case V_163 : return L_43 ;
case V_164 : return L_44 ;
case V_165 : return L_45 ;
case V_166 : return L_46 ;
case V_167 : return L_47 ;
case V_168 : return L_48 ;
case V_169 : return L_49 ;
case V_170 : return L_50 ;
case V_171 : return L_51 ;
case V_172 : return L_52 ;
case V_173 : return L_53 ;
case V_174 : return L_54 ;
case V_175 : return L_55 ;
case V_176 : return L_56 ;
case V_177 : return L_57 ;
case V_178 : return L_58 ;
case V_179 : return L_59 ;
case V_180 : return L_60 ;
default: return L_61 ;
}
}
