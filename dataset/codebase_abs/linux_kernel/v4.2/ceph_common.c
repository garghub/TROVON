bool F_1 ( void * V_1 )
{
return true ;
}
const char * F_2 ( const char * V_2 , int V_3 )
{
const char * V_4 = V_2 + V_3 ;
while ( V_4 != V_2 && * ( V_4 - 1 ) != '/' )
V_4 -- ;
return V_4 ;
}
const char * F_3 ( int type )
{
switch ( type ) {
case V_5 : return L_1 ;
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
default: return L_27 ;
}
}
int F_4 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
if ( V_32 -> V_35 ) {
if ( F_5 ( & V_32 -> V_34 , V_34 ) ) {
F_6 ( L_28 ,
& V_32 -> V_34 , V_34 ) ;
return - 1 ;
}
} else {
memcpy ( & V_32 -> V_34 , V_34 , sizeof( * V_34 ) ) ;
}
return 0 ;
}
static int F_7 ( const char * V_36 , const char * V_37 )
{
if ( ! V_36 && ! V_37 )
return 0 ;
if ( V_36 && ! V_37 )
return - 1 ;
if ( ! V_36 && V_37 )
return 1 ;
return strcmp ( V_36 , V_37 ) ;
}
int F_8 ( struct V_38 * V_39 ,
struct V_31 * V_32 )
{
struct V_38 * V_40 = V_39 ;
struct V_38 * V_41 = V_32 -> V_42 ;
int V_43 = F_9 ( struct V_38 , V_44 ) ;
int V_45 ;
int V_46 ;
if ( ! F_10 ( V_47 -> V_48 -> V_49 , F_11 ( & V_32 -> V_50 . V_51 ) ) )
return - 1 ;
V_46 = memcmp ( V_40 , V_41 , V_43 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_7 ( V_40 -> V_52 , V_41 -> V_52 ) ;
if ( V_46 )
return V_46 ;
if ( V_40 -> V_53 && ! V_41 -> V_53 )
return - 1 ;
if ( ! V_40 -> V_53 && V_41 -> V_53 )
return 1 ;
if ( V_40 -> V_53 && V_41 -> V_53 ) {
if ( V_40 -> V_53 -> type != V_41 -> V_53 -> type )
return - 1 ;
if ( V_40 -> V_53 -> V_54 . V_55 != V_41 -> V_53 -> V_54 . V_55 )
return - 1 ;
if ( V_40 -> V_53 -> V_54 . V_56 != V_41 -> V_53 -> V_54 . V_56 )
return - 1 ;
if ( V_40 -> V_53 -> V_3 != V_41 -> V_53 -> V_3 )
return - 1 ;
if ( V_40 -> V_53 -> V_53 && ! V_41 -> V_53 -> V_53 )
return - 1 ;
if ( ! V_40 -> V_53 -> V_53 && V_41 -> V_53 -> V_53 )
return 1 ;
if ( V_40 -> V_53 -> V_53 && V_41 -> V_53 -> V_53 ) {
V_46 = memcmp ( V_40 -> V_53 -> V_53 , V_41 -> V_53 -> V_53 , V_40 -> V_53 -> V_3 ) ;
if ( V_46 )
return V_46 ;
}
}
for ( V_45 = 0 ; V_45 < V_40 -> V_57 ; V_45 ++ ) {
if ( F_12 ( V_32 -> V_58 . V_59 ,
& V_40 -> V_44 [ V_45 ] ) )
return 0 ;
}
return - 1 ;
}
void * F_13 ( T_1 V_60 , T_2 V_61 )
{
if ( V_60 <= ( V_62 << V_63 ) ) {
void * V_64 = F_14 ( V_60 , V_61 | V_65 ) ;
if ( V_64 )
return V_64 ;
}
return F_15 ( V_60 , V_61 | V_66 , V_67 ) ;
}
static int F_16 ( const char * V_68 , struct V_33 * V_34 )
{
int V_45 = 0 ;
char V_69 [ 3 ] ;
int V_70 = - V_71 ;
int V_72 ;
F_17 ( L_29 , V_68 ) ;
V_69 [ 2 ] = 0 ;
while ( * V_68 && V_45 < 16 ) {
if ( ispunct ( * V_68 ) ) {
V_68 ++ ;
continue;
}
if ( ! isxdigit ( V_68 [ 0 ] ) || ! isxdigit ( V_68 [ 1 ] ) )
break;
V_69 [ 0 ] = V_68 [ 0 ] ;
V_69 [ 1 ] = V_68 [ 1 ] ;
if ( sscanf ( V_69 , L_30 , & V_72 ) < 1 )
break;
V_34 -> V_34 [ V_45 ] = V_72 & 0xff ;
V_45 ++ ;
V_68 += 2 ;
}
if ( V_45 == 16 )
V_70 = 0 ;
F_17 ( L_31 , V_70 , V_34 ) ;
return V_70 ;
}
void F_18 ( struct V_38 * V_73 )
{
F_17 ( L_32 , V_73 ) ;
F_19 ( V_73 -> V_52 ) ;
if ( V_73 -> V_53 ) {
F_20 ( V_73 -> V_53 ) ;
F_19 ( V_73 -> V_53 ) ;
}
F_19 ( V_73 -> V_44 ) ;
F_19 ( V_73 ) ;
}
static int F_21 ( struct V_74 * V_75 , const char * V_52 ) {
struct V_53 * V_76 ;
int V_77 ;
int V_70 = 0 ;
struct V_74 * V_78 ;
V_76 = F_22 ( & V_79 , V_52 , NULL ) ;
if ( ! V_76 || F_23 ( V_76 ) ) {
V_77 = F_24 ( V_76 ) ;
switch ( V_77 ) {
case - V_80 :
F_25 ( L_33 ,
V_52 ) ;
break;
case - V_81 :
F_25 ( L_34 ,
V_52 ) ;
break;
case - V_82 :
F_25 ( L_35 ,
V_52 ) ;
break;
default:
F_25 ( L_36 ,
V_77 , V_52 ) ;
}
V_70 = - V_83 ;
goto V_84;
}
V_78 = V_76 -> V_85 . V_1 ;
V_70 = F_26 ( V_75 , V_78 ) ;
if ( V_70 )
goto V_86;
V_86:
F_27 ( V_76 ) ;
V_84:
return V_70 ;
}
struct V_38 *
F_28 ( char * V_42 , const char * V_87 ,
const char * V_88 ,
int (* F_29)( char * V_89 , void * V_90 ) ,
void * V_90 )
{
struct V_38 * V_73 ;
const char * V_89 ;
int V_70 = - V_91 ;
T_3 V_92 [ V_93 ] ;
V_73 = F_30 ( sizeof( * V_73 ) , V_94 ) ;
if ( ! V_73 )
return F_31 ( - V_91 ) ;
V_73 -> V_44 = F_32 ( V_95 , sizeof( * V_73 -> V_44 ) ,
V_94 ) ;
if ( ! V_73 -> V_44 )
goto V_84;
F_17 ( L_37 , V_73 , V_42 ,
V_87 ) ;
V_73 -> V_61 = V_96 ;
V_73 -> V_97 = V_98 ;
V_73 -> V_99 = V_100 ;
V_73 -> V_101 = V_102 ;
V_70 = F_33 ( V_87 , V_88 , V_73 -> V_44 ,
V_95 , & V_73 -> V_57 ) ;
if ( V_70 < 0 )
goto V_84;
while ( ( V_89 = F_34 ( & V_42 , L_38 ) ) != NULL ) {
int V_103 , V_104 , V_46 ;
if ( ! * V_89 )
continue;
V_70 = - V_71 ;
V_103 = F_35 ( ( char * ) V_89 , V_105 , V_92 ) ;
if ( V_103 < 0 && F_29 ) {
V_70 = F_29 ( ( char * ) V_89 , V_90 ) ;
if ( V_70 < 0 ) {
F_6 ( L_39 , V_89 ) ;
goto V_84;
}
continue;
}
if ( V_103 < V_106 ) {
V_46 = F_36 ( & V_92 [ 0 ] , & V_104 ) ;
if ( V_46 < 0 ) {
F_6 ( L_40
L_41 , V_89 ) ;
continue;
}
F_17 ( L_42 , V_103 , V_104 ) ;
} else if ( V_103 > V_106 && V_103 < V_107 ) {
F_17 ( L_43 , V_103 ,
V_92 [ 0 ] . V_108 ) ;
} else {
F_17 ( L_44 , V_103 ) ;
}
switch ( V_103 ) {
case V_109 :
V_70 = F_33 ( V_92 [ 0 ] . V_108 ,
V_92 [ 0 ] . V_110 ,
& V_73 -> V_111 ,
1 , NULL ) ;
if ( V_70 < 0 )
goto V_84;
V_73 -> V_61 |= V_112 ;
break;
case V_113 :
V_70 = F_16 ( V_92 [ 0 ] . V_108 , & V_73 -> V_34 ) ;
if ( V_70 == 0 )
V_73 -> V_61 |= V_114 ;
break;
case V_115 :
V_73 -> V_52 = F_37 ( V_92 [ 0 ] . V_108 ,
V_92 [ 0 ] . V_110 - V_92 [ 0 ] . V_108 ,
V_94 ) ;
break;
case V_116 :
V_73 -> V_53 = F_30 ( sizeof( * V_73 -> V_53 ) , V_94 ) ;
if ( ! V_73 -> V_53 ) {
V_70 = - V_91 ;
goto V_84;
}
V_70 = F_38 ( V_73 -> V_53 , V_92 [ 0 ] . V_108 ) ;
if ( V_70 < 0 )
goto V_84;
break;
case V_117 :
V_73 -> V_53 = F_30 ( sizeof( * V_73 -> V_53 ) , V_94 ) ;
if ( ! V_73 -> V_53 ) {
V_70 = - V_91 ;
goto V_84;
}
V_70 = F_21 ( V_73 -> V_53 , V_92 [ 0 ] . V_108 ) ;
if ( V_70 < 0 )
goto V_84;
break;
case V_118 :
F_25 ( L_45 ) ;
break;
case V_119 :
if ( V_104 < 1 || V_104 > V_120 / 1000 ) {
F_6 ( L_46 ) ;
V_70 = - V_71 ;
goto V_84;
}
V_73 -> V_97 =
F_39 ( V_104 * 1000 ) ;
break;
case V_121 :
if ( V_104 < 1 || V_104 > V_120 / 1000 ) {
F_6 ( L_47 ) ;
V_70 = - V_71 ;
goto V_84;
}
V_73 -> V_101 = F_39 ( V_104 * 1000 ) ;
break;
case V_122 :
if ( V_104 < 0 || V_104 > V_120 / 1000 ) {
F_6 ( L_48 ) ;
V_70 = - V_71 ;
goto V_84;
}
V_73 -> V_99 = F_39 ( V_104 * 1000 ) ;
break;
case V_123 :
V_73 -> V_61 &= ~ V_124 ;
break;
case V_125 :
V_73 -> V_61 |= V_124 ;
break;
case V_126 :
V_73 -> V_61 &= ~ V_127 ;
break;
case V_128 :
V_73 -> V_61 |= V_127 ;
break;
case V_129 :
V_73 -> V_61 &= ~ V_130 ;
break;
case V_131 :
V_73 -> V_61 |= V_130 ;
break;
case V_132 :
V_73 -> V_61 |= V_133 ;
break;
case V_134 :
V_73 -> V_61 &= ~ V_133 ;
break;
default:
F_40 ( V_103 ) ;
}
}
return V_73 ;
V_84:
F_18 ( V_73 ) ;
return F_31 ( V_70 ) ;
}
int F_41 ( struct V_135 * V_136 , struct V_31 * V_32 )
{
struct V_38 * V_73 = V_32 -> V_42 ;
T_1 V_137 = V_136 -> V_138 ;
if ( V_73 -> V_52 )
F_42 ( V_136 , L_49 , V_73 -> V_52 ) ;
if ( V_73 -> V_53 )
F_43 ( V_136 , L_50 ) ;
if ( V_73 -> V_61 & V_114 )
F_42 ( V_136 , L_51 , & V_73 -> V_34 ) ;
if ( V_73 -> V_61 & V_124 )
F_43 ( V_136 , L_52 ) ;
if ( V_73 -> V_61 & V_127 )
F_43 ( V_136 , L_53 ) ;
if ( V_73 -> V_61 & V_130 )
F_43 ( V_136 , L_54 ) ;
if ( ( V_73 -> V_61 & V_133 ) == 0 )
F_43 ( V_136 , L_55 ) ;
if ( V_73 -> V_99 != V_100 )
F_42 ( V_136 , L_56 ,
F_44 ( V_73 -> V_99 ) / 1000 ) ;
if ( V_73 -> V_101 != V_102 )
F_42 ( V_136 , L_57 ,
F_44 ( V_73 -> V_101 ) / 1000 ) ;
if ( V_73 -> V_97 != V_98 )
F_42 ( V_136 , L_58 ,
F_44 ( V_73 -> V_97 ) / 1000 ) ;
if ( V_136 -> V_138 != V_137 )
V_136 -> V_138 -- ;
return 0 ;
}
T_4 F_45 ( struct V_31 * V_32 )
{
return V_32 -> V_58 . V_139 -> V_140 ;
}
struct V_31 * F_46 ( struct V_38 * V_73 , void * V_90 ,
T_4 V_141 ,
T_4 V_142 )
{
struct V_31 * V_32 ;
struct V_143 * V_144 = NULL ;
int V_70 = - V_91 ;
V_32 = F_30 ( sizeof( * V_32 ) , V_94 ) ;
if ( V_32 == NULL )
return F_31 ( - V_91 ) ;
V_32 -> V_90 = V_90 ;
V_32 -> V_42 = V_73 ;
F_47 ( & V_32 -> V_145 ) ;
F_48 ( & V_32 -> V_146 ) ;
V_32 -> V_147 = 0 ;
if ( ! F_49 ( V_32 , V_148 ) )
V_142 |= V_149 ;
V_32 -> V_150 = NULL ;
V_32 -> V_141 = V_151 |
V_141 ;
V_32 -> V_142 = V_152 |
V_142 ;
if ( F_49 ( V_32 , V_153 ) )
V_144 = & V_32 -> V_42 -> V_111 ;
F_50 ( & V_32 -> V_50 , V_144 ,
V_32 -> V_141 ,
V_32 -> V_142 ,
F_49 ( V_32 , V_154 ) ,
F_49 ( V_32 , V_155 ) ) ;
V_70 = F_51 ( & V_32 -> V_58 , V_32 ) ;
if ( V_70 < 0 )
goto V_156;
V_70 = F_52 ( & V_32 -> V_157 , V_32 ) ;
if ( V_70 < 0 )
goto V_158;
return V_32 ;
V_158:
F_53 ( & V_32 -> V_58 ) ;
V_156:
F_54 ( & V_32 -> V_50 ) ;
F_19 ( V_32 ) ;
return F_31 ( V_70 ) ;
}
void F_55 ( struct V_31 * V_32 )
{
F_17 ( L_59 , V_32 ) ;
F_56 ( & V_32 -> V_50 . V_159 , 1 ) ;
F_57 ( & V_32 -> V_157 ) ;
F_53 ( & V_32 -> V_58 ) ;
F_54 ( & V_32 -> V_50 ) ;
F_58 ( V_32 ) ;
F_18 ( V_32 -> V_42 ) ;
F_19 ( V_32 ) ;
F_17 ( L_60 , V_32 ) ;
}
static int F_59 ( struct V_31 * V_32 )
{
return V_32 -> V_58 . V_59 && V_32 -> V_58 . V_59 -> V_160 &&
V_32 -> V_157 . V_161 && V_32 -> V_157 . V_161 -> V_160 ;
}
int F_60 ( struct V_31 * V_32 , unsigned long V_162 )
{
unsigned long V_163 = V_32 -> V_42 -> V_99 ;
long V_70 ;
V_70 = F_61 ( & V_32 -> V_58 ) ;
if ( V_70 < 0 )
return V_70 ;
while ( ! F_59 ( V_32 ) ) {
if ( V_163 && F_62 ( V_164 , V_162 + V_163 ) )
return - V_165 ;
F_17 ( L_61 ) ;
V_70 = F_63 ( V_32 -> V_146 ,
F_59 ( V_32 ) || ( V_32 -> V_147 < 0 ) ,
F_64 ( V_163 ) ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_32 -> V_147 < 0 )
return V_32 -> V_147 ;
}
return 0 ;
}
int F_65 ( struct V_31 * V_32 )
{
int V_46 ;
unsigned long V_162 = V_164 ;
F_17 ( L_62 ) ;
F_66 ( & V_32 -> V_145 ) ;
V_46 = F_60 ( V_32 , V_162 ) ;
F_67 ( & V_32 -> V_145 ) ;
return V_46 ;
}
static int T_5 F_68 ( void )
{
int V_46 = 0 ;
V_46 = F_69 () ;
if ( V_46 < 0 )
goto V_84;
V_46 = F_70 () ;
if ( V_46 < 0 )
goto V_166;
V_46 = F_71 () ;
if ( V_46 < 0 )
goto V_167;
V_46 = F_72 () ;
if ( V_46 < 0 )
goto V_168;
F_73 ( L_63 ,
V_169 , V_170 ) ;
return 0 ;
V_168:
F_74 () ;
V_167:
F_75 () ;
V_166:
F_76 () ;
V_84:
return V_46 ;
}
static void T_6 F_77 ( void )
{
F_17 ( L_64 ) ;
F_78 () ;
F_74 () ;
F_75 () ;
F_76 () ;
}
