bool F_1 ( void * V_1 )
{
return true ;
}
static int F_2 ( char * V_2 ,
const struct V_3 * V_4 )
{
return sprintf ( V_2 , L_1 , V_5 ) ;
}
const char * F_3 ( int type )
{
switch ( type ) {
case V_6 : return L_2 ;
case V_7 : return L_3 ;
case V_8 : return L_4 ;
case V_9 : return L_5 ;
case V_10 : return L_6 ;
case V_11 : return L_7 ;
case V_12 : return L_8 ;
case V_13 : return L_9 ;
case V_14 : return L_10 ;
case V_15 : return L_11 ;
case V_16 : return L_12 ;
case V_17 : return L_13 ;
case V_18 : return L_14 ;
case V_19 : return L_15 ;
case V_20 : return L_16 ;
case V_21 : return L_17 ;
case V_22 : return L_18 ;
case V_23 : return L_19 ;
case V_24 : return L_20 ;
case V_25 : return L_21 ;
case V_26 : return L_22 ;
case V_27 : return L_23 ;
case V_28 : return L_24 ;
case V_29 : return L_25 ;
case V_30 : return L_26 ;
case V_31 : return L_27 ;
case V_32 : return L_28 ;
default: return L_29 ;
}
}
int F_4 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
if ( V_34 -> V_37 ) {
if ( F_5 ( & V_34 -> V_36 , V_36 ) ) {
F_6 ( L_30 ,
& V_34 -> V_36 , V_36 ) ;
return - 1 ;
}
} else {
memcpy ( & V_34 -> V_36 , V_36 , sizeof( * V_36 ) ) ;
}
return 0 ;
}
static int F_7 ( const char * V_38 , const char * V_39 )
{
if ( ! V_38 && ! V_39 )
return 0 ;
if ( V_38 && ! V_39 )
return - 1 ;
if ( ! V_38 && V_39 )
return 1 ;
return strcmp ( V_38 , V_39 ) ;
}
int F_8 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_40 * V_42 = V_41 ;
struct V_40 * V_43 = V_34 -> V_44 ;
int V_45 = F_9 ( struct V_40 , V_46 ) ;
int V_47 ;
int V_48 ;
if ( ! F_10 ( V_49 -> V_50 -> V_51 , F_11 ( & V_34 -> V_52 . V_53 ) ) )
return - 1 ;
V_48 = memcmp ( V_42 , V_43 , V_45 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_7 ( V_42 -> V_54 , V_43 -> V_54 ) ;
if ( V_48 )
return V_48 ;
if ( V_42 -> V_55 && ! V_43 -> V_55 )
return - 1 ;
if ( ! V_42 -> V_55 && V_43 -> V_55 )
return 1 ;
if ( V_42 -> V_55 && V_43 -> V_55 ) {
if ( V_42 -> V_55 -> type != V_43 -> V_55 -> type )
return - 1 ;
if ( V_42 -> V_55 -> V_56 . V_57 != V_43 -> V_55 -> V_56 . V_57 )
return - 1 ;
if ( V_42 -> V_55 -> V_56 . V_58 != V_43 -> V_55 -> V_56 . V_58 )
return - 1 ;
if ( V_42 -> V_55 -> V_59 != V_43 -> V_55 -> V_59 )
return - 1 ;
if ( V_42 -> V_55 -> V_55 && ! V_43 -> V_55 -> V_55 )
return - 1 ;
if ( ! V_42 -> V_55 -> V_55 && V_43 -> V_55 -> V_55 )
return 1 ;
if ( V_42 -> V_55 -> V_55 && V_43 -> V_55 -> V_55 ) {
V_48 = memcmp ( V_42 -> V_55 -> V_55 , V_43 -> V_55 -> V_55 , V_42 -> V_55 -> V_59 ) ;
if ( V_48 )
return V_48 ;
}
}
for ( V_47 = 0 ; V_47 < V_42 -> V_60 ; V_47 ++ ) {
if ( F_12 ( V_34 -> V_61 . V_62 ,
& V_42 -> V_46 [ V_47 ] ) )
return 0 ;
}
return - 1 ;
}
void * F_13 ( T_1 V_63 , T_2 V_64 )
{
if ( V_63 <= ( V_65 << V_66 ) ) {
void * V_67 = F_14 ( V_63 , V_64 | V_68 ) ;
if ( V_67 )
return V_67 ;
}
return F_15 ( V_63 , V_64 , V_69 ) ;
}
static int F_16 ( const char * V_70 , struct V_35 * V_36 )
{
int V_47 = 0 ;
char V_71 [ 3 ] ;
int V_72 = - V_73 ;
int V_74 ;
F_17 ( L_31 , V_70 ) ;
V_71 [ 2 ] = 0 ;
while ( * V_70 && V_47 < 16 ) {
if ( ispunct ( * V_70 ) ) {
V_70 ++ ;
continue;
}
if ( ! isxdigit ( V_70 [ 0 ] ) || ! isxdigit ( V_70 [ 1 ] ) )
break;
V_71 [ 0 ] = V_70 [ 0 ] ;
V_71 [ 1 ] = V_70 [ 1 ] ;
if ( sscanf ( V_71 , L_32 , & V_74 ) < 1 )
break;
V_36 -> V_36 [ V_47 ] = V_74 & 0xff ;
V_47 ++ ;
V_70 += 2 ;
}
if ( V_47 == 16 )
V_72 = 0 ;
F_17 ( L_33 , V_72 , V_36 ) ;
return V_72 ;
}
void F_18 ( struct V_40 * V_75 )
{
F_17 ( L_34 , V_75 ) ;
F_19 ( V_75 -> V_54 ) ;
if ( V_75 -> V_55 ) {
F_20 ( V_75 -> V_55 ) ;
F_19 ( V_75 -> V_55 ) ;
}
F_19 ( V_75 -> V_46 ) ;
F_19 ( V_75 ) ;
}
static int F_21 ( struct V_76 * V_77 , const char * V_54 ) {
struct V_55 * V_78 ;
int V_79 ;
int V_72 = 0 ;
struct V_76 * V_80 ;
V_78 = F_22 ( & V_81 , V_54 , NULL ) ;
if ( ! V_78 || F_23 ( V_78 ) ) {
V_79 = F_24 ( V_78 ) ;
switch ( V_79 ) {
case - V_82 :
F_25 ( L_35 ,
V_54 ) ;
break;
case - V_83 :
F_25 ( L_36 ,
V_54 ) ;
break;
case - V_84 :
F_25 ( L_37 ,
V_54 ) ;
break;
default:
F_25 ( L_38 ,
V_79 , V_54 ) ;
}
V_72 = - V_85 ;
goto V_86;
}
V_80 = V_78 -> V_87 . V_1 [ 0 ] ;
V_72 = F_26 ( V_77 , V_80 ) ;
if ( V_72 )
goto V_88;
V_88:
F_27 ( V_78 ) ;
V_86:
return V_72 ;
}
struct V_40 *
F_28 ( char * V_44 , const char * V_89 ,
const char * V_90 ,
int (* F_29)( char * V_91 , void * V_92 ) ,
void * V_92 )
{
struct V_40 * V_75 ;
const char * V_91 ;
int V_72 = - V_93 ;
T_3 V_94 [ V_95 ] ;
V_75 = F_30 ( sizeof( * V_75 ) , V_96 ) ;
if ( ! V_75 )
return F_31 ( - V_93 ) ;
V_75 -> V_46 = F_32 ( V_97 , sizeof( * V_75 -> V_46 ) ,
V_96 ) ;
if ( ! V_75 -> V_46 )
goto V_86;
F_17 ( L_39 , V_75 , V_44 ,
V_89 ) ;
V_75 -> V_64 = V_98 ;
V_75 -> V_99 = V_100 ;
V_75 -> V_101 = V_102 ;
V_75 -> V_103 = V_104 ;
V_75 -> V_105 = V_106 ;
V_72 = F_33 ( V_89 , V_90 , V_75 -> V_46 ,
V_97 , & V_75 -> V_60 ) ;
if ( V_72 < 0 )
goto V_86;
while ( ( V_91 = F_34 ( & V_44 , L_40 ) ) != NULL ) {
int V_107 , V_108 , V_48 ;
if ( ! * V_91 )
continue;
V_72 = - V_73 ;
V_107 = F_35 ( ( char * ) V_91 , V_109 , V_94 ) ;
if ( V_107 < 0 && F_29 ) {
V_72 = F_29 ( ( char * ) V_91 , V_92 ) ;
if ( V_72 < 0 ) {
F_6 ( L_41 , V_91 ) ;
goto V_86;
}
continue;
}
if ( V_107 < V_110 ) {
V_48 = F_36 ( & V_94 [ 0 ] , & V_108 ) ;
if ( V_48 < 0 ) {
F_6 ( L_42
L_43 , V_91 ) ;
continue;
}
F_17 ( L_44 , V_107 , V_108 ) ;
} else if ( V_107 > V_110 && V_107 < V_111 ) {
F_17 ( L_45 , V_107 ,
V_94 [ 0 ] . V_112 ) ;
} else {
F_17 ( L_46 , V_107 ) ;
}
switch ( V_107 ) {
case V_113 :
V_72 = F_33 ( V_94 [ 0 ] . V_112 ,
V_94 [ 0 ] . V_114 ,
& V_75 -> V_115 ,
1 , NULL ) ;
if ( V_72 < 0 )
goto V_86;
V_75 -> V_64 |= V_116 ;
break;
case V_117 :
V_72 = F_16 ( V_94 [ 0 ] . V_112 , & V_75 -> V_36 ) ;
if ( V_72 == 0 )
V_75 -> V_64 |= V_118 ;
break;
case V_119 :
V_75 -> V_54 = F_37 ( V_94 [ 0 ] . V_112 ,
V_94 [ 0 ] . V_114 - V_94 [ 0 ] . V_112 ,
V_96 ) ;
break;
case V_120 :
V_75 -> V_55 = F_30 ( sizeof( * V_75 -> V_55 ) , V_96 ) ;
if ( ! V_75 -> V_55 ) {
V_72 = - V_93 ;
goto V_86;
}
V_72 = F_38 ( V_75 -> V_55 , V_94 [ 0 ] . V_112 ) ;
if ( V_72 < 0 )
goto V_86;
break;
case V_121 :
V_75 -> V_55 = F_30 ( sizeof( * V_75 -> V_55 ) , V_96 ) ;
if ( ! V_75 -> V_55 ) {
V_72 = - V_93 ;
goto V_86;
}
V_72 = F_21 ( V_75 -> V_55 , V_94 [ 0 ] . V_112 ) ;
if ( V_72 < 0 )
goto V_86;
break;
case V_122 :
F_25 ( L_47 ) ;
break;
case V_123 :
if ( V_108 < 1 || V_108 > V_124 / 1000 ) {
F_6 ( L_48 ) ;
V_72 = - V_73 ;
goto V_86;
}
V_75 -> V_99 =
F_39 ( V_108 * 1000 ) ;
break;
case V_125 :
if ( V_108 < 1 || V_108 > V_124 / 1000 ) {
F_6 ( L_49 ) ;
V_72 = - V_73 ;
goto V_86;
}
V_75 -> V_103 = F_39 ( V_108 * 1000 ) ;
break;
case V_126 :
if ( V_108 < 0 || V_108 > V_124 / 1000 ) {
F_6 ( L_50 ) ;
V_72 = - V_73 ;
goto V_86;
}
V_75 -> V_101 = F_39 ( V_108 * 1000 ) ;
break;
case V_127 :
if ( V_108 < 0 || V_108 > V_124 / 1000 ) {
F_6 ( L_51 ) ;
V_72 = - V_73 ;
goto V_86;
}
V_75 -> V_105 = F_39 ( V_108 * 1000 ) ;
break;
case V_128 :
V_75 -> V_64 &= ~ V_129 ;
break;
case V_130 :
V_75 -> V_64 |= V_129 ;
break;
case V_131 :
V_75 -> V_64 &= ~ V_132 ;
break;
case V_133 :
V_75 -> V_64 |= V_132 ;
break;
case V_134 :
V_75 -> V_64 &= ~ V_135 ;
break;
case V_136 :
V_75 -> V_64 |= V_135 ;
break;
case V_137 :
V_75 -> V_64 &= ~ V_138 ;
break;
case V_139 :
V_75 -> V_64 |= V_138 ;
break;
case V_140 :
V_75 -> V_64 |= V_141 ;
break;
case V_142 :
V_75 -> V_64 &= ~ V_141 ;
break;
default:
F_40 ( V_107 ) ;
}
}
return V_75 ;
V_86:
F_18 ( V_75 ) ;
return F_31 ( V_72 ) ;
}
int F_41 ( struct V_143 * V_144 , struct V_33 * V_34 )
{
struct V_40 * V_75 = V_34 -> V_44 ;
T_1 V_145 = V_144 -> V_146 ;
if ( V_75 -> V_54 ) {
F_42 ( V_144 , L_52 ) ;
F_43 ( V_144 , V_75 -> V_54 , L_53 ) ;
F_44 ( V_144 , ',' ) ;
}
if ( V_75 -> V_55 )
F_42 ( V_144 , L_54 ) ;
if ( V_75 -> V_64 & V_118 )
F_45 ( V_144 , L_55 , & V_75 -> V_36 ) ;
if ( V_75 -> V_64 & V_129 )
F_42 ( V_144 , L_56 ) ;
if ( V_75 -> V_64 & V_132 )
F_42 ( V_144 , L_57 ) ;
if ( V_75 -> V_64 & V_135 )
F_42 ( V_144 , L_58 ) ;
if ( V_75 -> V_64 & V_138 )
F_42 ( V_144 , L_59 ) ;
if ( ( V_75 -> V_64 & V_141 ) == 0 )
F_42 ( V_144 , L_60 ) ;
if ( V_75 -> V_101 != V_102 )
F_45 ( V_144 , L_61 ,
F_46 ( V_75 -> V_101 ) / 1000 ) ;
if ( V_75 -> V_103 != V_104 )
F_45 ( V_144 , L_62 ,
F_46 ( V_75 -> V_103 ) / 1000 ) ;
if ( V_75 -> V_99 != V_100 )
F_45 ( V_144 , L_63 ,
F_46 ( V_75 -> V_99 ) / 1000 ) ;
if ( V_75 -> V_105 != V_106 )
F_45 ( V_144 , L_64 ,
F_46 ( V_75 -> V_105 ) / 1000 ) ;
if ( V_144 -> V_146 != V_145 )
V_144 -> V_146 -- ;
return 0 ;
}
struct V_147 * F_47 ( struct V_33 * V_34 )
{
return & V_34 -> V_52 . V_148 . V_149 ;
}
T_4 F_48 ( struct V_33 * V_34 )
{
return V_34 -> V_61 . V_150 -> V_151 ;
}
struct V_33 * F_49 ( struct V_40 * V_75 , void * V_92 )
{
struct V_33 * V_34 ;
struct V_147 * V_152 = NULL ;
int V_72 ;
V_72 = F_50 () ;
if ( V_72 < 0 )
return F_31 ( V_72 ) ;
V_34 = F_30 ( sizeof( * V_34 ) , V_96 ) ;
if ( V_34 == NULL )
return F_31 ( - V_93 ) ;
V_34 -> V_92 = V_92 ;
V_34 -> V_44 = V_75 ;
F_51 ( & V_34 -> V_153 ) ;
F_52 ( & V_34 -> V_154 ) ;
V_34 -> V_155 = 0 ;
V_34 -> V_156 = NULL ;
V_34 -> V_157 = V_5 ;
V_34 -> V_158 = V_159 ;
if ( ! F_53 ( V_34 , V_160 ) )
V_34 -> V_158 |= V_161 ;
if ( F_53 ( V_34 , V_162 ) )
V_152 = & V_34 -> V_44 -> V_115 ;
F_54 ( & V_34 -> V_52 , V_152 ) ;
V_72 = F_55 ( & V_34 -> V_61 , V_34 ) ;
if ( V_72 < 0 )
goto V_163;
V_72 = F_56 ( & V_34 -> V_164 , V_34 ) ;
if ( V_72 < 0 )
goto V_165;
return V_34 ;
V_165:
F_57 ( & V_34 -> V_61 ) ;
V_163:
F_58 ( & V_34 -> V_52 ) ;
F_19 ( V_34 ) ;
return F_31 ( V_72 ) ;
}
void F_59 ( struct V_33 * V_34 )
{
F_17 ( L_65 , V_34 ) ;
F_60 ( & V_34 -> V_52 . V_166 , 1 ) ;
F_61 ( & V_34 -> V_164 ) ;
F_57 ( & V_34 -> V_61 ) ;
F_58 ( & V_34 -> V_52 ) ;
F_62 ( V_34 ) ;
F_18 ( V_34 -> V_44 ) ;
F_19 ( V_34 ) ;
F_17 ( L_66 , V_34 ) ;
}
static bool F_63 ( struct V_33 * V_34 )
{
return V_34 -> V_61 . V_62 && V_34 -> V_61 . V_62 -> V_167 &&
V_34 -> V_164 . V_168 && V_34 -> V_164 . V_168 -> V_167 ;
}
int F_64 ( struct V_33 * V_34 , unsigned long V_169 )
{
unsigned long V_170 = V_34 -> V_44 -> V_101 ;
long V_72 ;
V_72 = F_65 ( & V_34 -> V_61 ) ;
if ( V_72 < 0 )
return V_72 ;
while ( ! F_63 ( V_34 ) ) {
if ( V_170 && F_66 ( V_171 , V_169 + V_170 ) )
return - V_172 ;
F_17 ( L_67 ) ;
V_72 = F_67 ( V_34 -> V_154 ,
F_63 ( V_34 ) || ( V_34 -> V_155 < 0 ) ,
F_68 ( V_170 ) ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_34 -> V_155 < 0 )
return V_34 -> V_155 ;
}
F_69 ( L_68 , F_48 ( V_34 ) ,
& V_34 -> V_36 ) ;
F_70 ( V_34 ) ;
return 0 ;
}
int F_71 ( struct V_33 * V_34 )
{
int V_48 ;
unsigned long V_169 = V_171 ;
F_17 ( L_69 ) ;
F_72 ( & V_34 -> V_153 ) ;
V_48 = F_64 ( V_34 , V_169 ) ;
F_73 ( & V_34 -> V_153 ) ;
return V_48 ;
}
static int T_5 F_74 ( void )
{
int V_48 = 0 ;
V_48 = F_75 () ;
if ( V_48 < 0 )
goto V_86;
V_48 = F_76 () ;
if ( V_48 < 0 )
goto V_173;
V_48 = F_77 () ;
if ( V_48 < 0 )
goto V_174;
V_48 = F_78 () ;
if ( V_48 < 0 )
goto V_175;
F_69 ( L_70 ,
V_176 , V_177 ) ;
return 0 ;
V_175:
F_79 () ;
V_174:
F_80 () ;
V_173:
F_81 () ;
V_86:
return V_48 ;
}
static void T_6 F_82 ( void )
{
F_17 ( L_71 ) ;
F_83 ( ! F_84 () ) ;
F_85 () ;
F_79 () ;
F_80 () ;
F_81 () ;
}
