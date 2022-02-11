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
default: return L_28 ;
}
}
int F_4 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
if ( V_33 -> V_36 ) {
if ( F_5 ( & V_33 -> V_35 , V_35 ) ) {
F_6 ( L_29 ,
& V_33 -> V_35 , V_35 ) ;
return - 1 ;
}
} else {
memcpy ( & V_33 -> V_35 , V_35 , sizeof( * V_35 ) ) ;
}
return 0 ;
}
static int F_7 ( const char * V_37 , const char * V_38 )
{
if ( ! V_37 && ! V_38 )
return 0 ;
if ( V_37 && ! V_38 )
return - 1 ;
if ( ! V_37 && V_38 )
return 1 ;
return strcmp ( V_37 , V_38 ) ;
}
int F_8 ( struct V_39 * V_40 ,
struct V_32 * V_33 )
{
struct V_39 * V_41 = V_40 ;
struct V_39 * V_42 = V_33 -> V_43 ;
int V_44 = F_9 ( struct V_39 , V_45 ) ;
int V_46 ;
int V_47 ;
if ( ! F_10 ( V_48 -> V_49 -> V_50 , F_11 ( & V_33 -> V_51 . V_52 ) ) )
return - 1 ;
V_47 = memcmp ( V_41 , V_42 , V_44 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_7 ( V_41 -> V_53 , V_42 -> V_53 ) ;
if ( V_47 )
return V_47 ;
if ( V_41 -> V_54 && ! V_42 -> V_54 )
return - 1 ;
if ( ! V_41 -> V_54 && V_42 -> V_54 )
return 1 ;
if ( V_41 -> V_54 && V_42 -> V_54 ) {
if ( V_41 -> V_54 -> type != V_42 -> V_54 -> type )
return - 1 ;
if ( V_41 -> V_54 -> V_55 . V_56 != V_42 -> V_54 -> V_55 . V_56 )
return - 1 ;
if ( V_41 -> V_54 -> V_55 . V_57 != V_42 -> V_54 -> V_55 . V_57 )
return - 1 ;
if ( V_41 -> V_54 -> V_58 != V_42 -> V_54 -> V_58 )
return - 1 ;
if ( V_41 -> V_54 -> V_54 && ! V_42 -> V_54 -> V_54 )
return - 1 ;
if ( ! V_41 -> V_54 -> V_54 && V_42 -> V_54 -> V_54 )
return 1 ;
if ( V_41 -> V_54 -> V_54 && V_42 -> V_54 -> V_54 ) {
V_47 = memcmp ( V_41 -> V_54 -> V_54 , V_42 -> V_54 -> V_54 , V_41 -> V_54 -> V_58 ) ;
if ( V_47 )
return V_47 ;
}
}
for ( V_46 = 0 ; V_46 < V_41 -> V_59 ; V_46 ++ ) {
if ( F_12 ( V_33 -> V_60 . V_61 ,
& V_41 -> V_45 [ V_46 ] ) )
return 0 ;
}
return - 1 ;
}
void * F_13 ( T_1 V_62 , T_2 V_63 )
{
if ( V_62 <= ( V_64 << V_65 ) ) {
void * V_66 = F_14 ( V_62 , V_63 | V_67 ) ;
if ( V_66 )
return V_66 ;
}
return F_15 ( V_62 , V_63 , V_68 ) ;
}
static int F_16 ( const char * V_69 , struct V_34 * V_35 )
{
int V_46 = 0 ;
char V_70 [ 3 ] ;
int V_71 = - V_72 ;
int V_73 ;
F_17 ( L_30 , V_69 ) ;
V_70 [ 2 ] = 0 ;
while ( * V_69 && V_46 < 16 ) {
if ( ispunct ( * V_69 ) ) {
V_69 ++ ;
continue;
}
if ( ! isxdigit ( V_69 [ 0 ] ) || ! isxdigit ( V_69 [ 1 ] ) )
break;
V_70 [ 0 ] = V_69 [ 0 ] ;
V_70 [ 1 ] = V_69 [ 1 ] ;
if ( sscanf ( V_70 , L_31 , & V_73 ) < 1 )
break;
V_35 -> V_35 [ V_46 ] = V_73 & 0xff ;
V_46 ++ ;
V_69 += 2 ;
}
if ( V_46 == 16 )
V_71 = 0 ;
F_17 ( L_32 , V_71 , V_35 ) ;
return V_71 ;
}
void F_18 ( struct V_39 * V_74 )
{
F_17 ( L_33 , V_74 ) ;
F_19 ( V_74 -> V_53 ) ;
if ( V_74 -> V_54 ) {
F_20 ( V_74 -> V_54 ) ;
F_19 ( V_74 -> V_54 ) ;
}
F_19 ( V_74 -> V_45 ) ;
F_19 ( V_74 ) ;
}
static int F_21 ( struct V_75 * V_76 , const char * V_53 ) {
struct V_54 * V_77 ;
int V_78 ;
int V_71 = 0 ;
struct V_75 * V_79 ;
V_77 = F_22 ( & V_80 , V_53 , NULL ) ;
if ( ! V_77 || F_23 ( V_77 ) ) {
V_78 = F_24 ( V_77 ) ;
switch ( V_78 ) {
case - V_81 :
F_25 ( L_34 ,
V_53 ) ;
break;
case - V_82 :
F_25 ( L_35 ,
V_53 ) ;
break;
case - V_83 :
F_25 ( L_36 ,
V_53 ) ;
break;
default:
F_25 ( L_37 ,
V_78 , V_53 ) ;
}
V_71 = - V_84 ;
goto V_85;
}
V_79 = V_77 -> V_86 . V_1 [ 0 ] ;
V_71 = F_26 ( V_76 , V_79 ) ;
if ( V_71 )
goto V_87;
V_87:
F_27 ( V_77 ) ;
V_85:
return V_71 ;
}
struct V_39 *
F_28 ( char * V_43 , const char * V_88 ,
const char * V_89 ,
int (* F_29)( char * V_90 , void * V_91 ) ,
void * V_91 )
{
struct V_39 * V_74 ;
const char * V_90 ;
int V_71 = - V_92 ;
T_3 V_93 [ V_94 ] ;
V_74 = F_30 ( sizeof( * V_74 ) , V_95 ) ;
if ( ! V_74 )
return F_31 ( - V_92 ) ;
V_74 -> V_45 = F_32 ( V_96 , sizeof( * V_74 -> V_45 ) ,
V_95 ) ;
if ( ! V_74 -> V_45 )
goto V_85;
F_17 ( L_38 , V_74 , V_43 ,
V_88 ) ;
V_74 -> V_63 = V_97 ;
V_74 -> V_98 = V_99 ;
V_74 -> V_100 = V_101 ;
V_74 -> V_102 = V_103 ;
V_74 -> V_104 = V_105 ;
V_71 = F_33 ( V_88 , V_89 , V_74 -> V_45 ,
V_96 , & V_74 -> V_59 ) ;
if ( V_71 < 0 )
goto V_85;
while ( ( V_90 = F_34 ( & V_43 , L_39 ) ) != NULL ) {
int V_106 , V_107 , V_47 ;
if ( ! * V_90 )
continue;
V_71 = - V_72 ;
V_106 = F_35 ( ( char * ) V_90 , V_108 , V_93 ) ;
if ( V_106 < 0 && F_29 ) {
V_71 = F_29 ( ( char * ) V_90 , V_91 ) ;
if ( V_71 < 0 ) {
F_6 ( L_40 , V_90 ) ;
goto V_85;
}
continue;
}
if ( V_106 < V_109 ) {
V_47 = F_36 ( & V_93 [ 0 ] , & V_107 ) ;
if ( V_47 < 0 ) {
F_6 ( L_41
L_42 , V_90 ) ;
continue;
}
F_17 ( L_43 , V_106 , V_107 ) ;
} else if ( V_106 > V_109 && V_106 < V_110 ) {
F_17 ( L_44 , V_106 ,
V_93 [ 0 ] . V_111 ) ;
} else {
F_17 ( L_45 , V_106 ) ;
}
switch ( V_106 ) {
case V_112 :
V_71 = F_33 ( V_93 [ 0 ] . V_111 ,
V_93 [ 0 ] . V_113 ,
& V_74 -> V_114 ,
1 , NULL ) ;
if ( V_71 < 0 )
goto V_85;
V_74 -> V_63 |= V_115 ;
break;
case V_116 :
V_71 = F_16 ( V_93 [ 0 ] . V_111 , & V_74 -> V_35 ) ;
if ( V_71 == 0 )
V_74 -> V_63 |= V_117 ;
break;
case V_118 :
V_74 -> V_53 = F_37 ( V_93 [ 0 ] . V_111 ,
V_93 [ 0 ] . V_113 - V_93 [ 0 ] . V_111 ,
V_95 ) ;
break;
case V_119 :
V_74 -> V_54 = F_30 ( sizeof( * V_74 -> V_54 ) , V_95 ) ;
if ( ! V_74 -> V_54 ) {
V_71 = - V_92 ;
goto V_85;
}
V_71 = F_38 ( V_74 -> V_54 , V_93 [ 0 ] . V_111 ) ;
if ( V_71 < 0 )
goto V_85;
break;
case V_120 :
V_74 -> V_54 = F_30 ( sizeof( * V_74 -> V_54 ) , V_95 ) ;
if ( ! V_74 -> V_54 ) {
V_71 = - V_92 ;
goto V_85;
}
V_71 = F_21 ( V_74 -> V_54 , V_93 [ 0 ] . V_111 ) ;
if ( V_71 < 0 )
goto V_85;
break;
case V_121 :
F_25 ( L_46 ) ;
break;
case V_122 :
if ( V_107 < 1 || V_107 > V_123 / 1000 ) {
F_6 ( L_47 ) ;
V_71 = - V_72 ;
goto V_85;
}
V_74 -> V_98 =
F_39 ( V_107 * 1000 ) ;
break;
case V_124 :
if ( V_107 < 1 || V_107 > V_123 / 1000 ) {
F_6 ( L_48 ) ;
V_71 = - V_72 ;
goto V_85;
}
V_74 -> V_102 = F_39 ( V_107 * 1000 ) ;
break;
case V_125 :
if ( V_107 < 0 || V_107 > V_123 / 1000 ) {
F_6 ( L_49 ) ;
V_71 = - V_72 ;
goto V_85;
}
V_74 -> V_100 = F_39 ( V_107 * 1000 ) ;
break;
case V_126 :
if ( V_107 < 0 || V_107 > V_123 / 1000 ) {
F_6 ( L_50 ) ;
V_71 = - V_72 ;
goto V_85;
}
V_74 -> V_104 = F_39 ( V_107 * 1000 ) ;
break;
case V_127 :
V_74 -> V_63 &= ~ V_128 ;
break;
case V_129 :
V_74 -> V_63 |= V_128 ;
break;
case V_130 :
V_74 -> V_63 &= ~ V_131 ;
break;
case V_132 :
V_74 -> V_63 |= V_131 ;
break;
case V_133 :
V_74 -> V_63 &= ~ V_134 ;
break;
case V_135 :
V_74 -> V_63 |= V_134 ;
break;
case V_136 :
V_74 -> V_63 &= ~ V_137 ;
break;
case V_138 :
V_74 -> V_63 |= V_137 ;
break;
case V_139 :
V_74 -> V_63 |= V_140 ;
break;
case V_141 :
V_74 -> V_63 &= ~ V_140 ;
break;
default:
F_40 ( V_106 ) ;
}
}
return V_74 ;
V_85:
F_18 ( V_74 ) ;
return F_31 ( V_71 ) ;
}
int F_41 ( struct V_142 * V_143 , struct V_32 * V_33 )
{
struct V_39 * V_74 = V_33 -> V_43 ;
T_1 V_144 = V_143 -> V_145 ;
if ( V_74 -> V_53 ) {
F_42 ( V_143 , L_51 ) ;
F_43 ( V_143 , V_74 -> V_53 , L_52 ) ;
F_44 ( V_143 , ',' ) ;
}
if ( V_74 -> V_54 )
F_42 ( V_143 , L_53 ) ;
if ( V_74 -> V_63 & V_117 )
F_45 ( V_143 , L_54 , & V_74 -> V_35 ) ;
if ( V_74 -> V_63 & V_128 )
F_42 ( V_143 , L_55 ) ;
if ( V_74 -> V_63 & V_131 )
F_42 ( V_143 , L_56 ) ;
if ( V_74 -> V_63 & V_134 )
F_42 ( V_143 , L_57 ) ;
if ( V_74 -> V_63 & V_137 )
F_42 ( V_143 , L_58 ) ;
if ( ( V_74 -> V_63 & V_140 ) == 0 )
F_42 ( V_143 , L_59 ) ;
if ( V_74 -> V_100 != V_101 )
F_45 ( V_143 , L_60 ,
F_46 ( V_74 -> V_100 ) / 1000 ) ;
if ( V_74 -> V_102 != V_103 )
F_45 ( V_143 , L_61 ,
F_46 ( V_74 -> V_102 ) / 1000 ) ;
if ( V_74 -> V_98 != V_99 )
F_45 ( V_143 , L_62 ,
F_46 ( V_74 -> V_98 ) / 1000 ) ;
if ( V_74 -> V_104 != V_105 )
F_45 ( V_143 , L_63 ,
F_46 ( V_74 -> V_104 ) / 1000 ) ;
if ( V_143 -> V_145 != V_144 )
V_143 -> V_145 -- ;
return 0 ;
}
struct V_146 * F_47 ( struct V_32 * V_33 )
{
return & V_33 -> V_51 . V_147 . V_148 ;
}
T_4 F_48 ( struct V_32 * V_33 )
{
return V_33 -> V_60 . V_149 -> V_150 ;
}
struct V_32 * F_49 ( struct V_39 * V_74 , void * V_91 )
{
struct V_32 * V_33 ;
struct V_146 * V_151 = NULL ;
int V_71 = - V_92 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_95 ) ;
if ( V_33 == NULL )
return F_31 ( - V_92 ) ;
V_33 -> V_91 = V_91 ;
V_33 -> V_43 = V_74 ;
F_50 ( & V_33 -> V_152 ) ;
F_51 ( & V_33 -> V_153 ) ;
V_33 -> V_154 = 0 ;
V_33 -> V_155 = NULL ;
V_33 -> V_156 = V_5 ;
V_33 -> V_157 = V_158 ;
if ( ! F_52 ( V_33 , V_159 ) )
V_33 -> V_157 |= V_160 ;
if ( F_52 ( V_33 , V_161 ) )
V_151 = & V_33 -> V_43 -> V_114 ;
F_53 ( & V_33 -> V_51 , V_151 ) ;
V_71 = F_54 ( & V_33 -> V_60 , V_33 ) ;
if ( V_71 < 0 )
goto V_162;
V_71 = F_55 ( & V_33 -> V_163 , V_33 ) ;
if ( V_71 < 0 )
goto V_164;
return V_33 ;
V_164:
F_56 ( & V_33 -> V_60 ) ;
V_162:
F_57 ( & V_33 -> V_51 ) ;
F_19 ( V_33 ) ;
return F_31 ( V_71 ) ;
}
void F_58 ( struct V_32 * V_33 )
{
F_17 ( L_64 , V_33 ) ;
F_59 ( & V_33 -> V_51 . V_165 , 1 ) ;
F_60 ( & V_33 -> V_163 ) ;
F_56 ( & V_33 -> V_60 ) ;
F_57 ( & V_33 -> V_51 ) ;
F_61 ( V_33 ) ;
F_18 ( V_33 -> V_43 ) ;
F_19 ( V_33 ) ;
F_17 ( L_65 , V_33 ) ;
}
static bool F_62 ( struct V_32 * V_33 )
{
return V_33 -> V_60 . V_61 && V_33 -> V_60 . V_61 -> V_166 &&
V_33 -> V_163 . V_167 && V_33 -> V_163 . V_167 -> V_166 ;
}
int F_63 ( struct V_32 * V_33 , unsigned long V_168 )
{
unsigned long V_169 = V_33 -> V_43 -> V_100 ;
long V_71 ;
V_71 = F_64 ( & V_33 -> V_60 ) ;
if ( V_71 < 0 )
return V_71 ;
while ( ! F_62 ( V_33 ) ) {
if ( V_169 && F_65 ( V_170 , V_168 + V_169 ) )
return - V_171 ;
F_17 ( L_66 ) ;
V_71 = F_66 ( V_33 -> V_153 ,
F_62 ( V_33 ) || ( V_33 -> V_154 < 0 ) ,
F_67 ( V_169 ) ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_33 -> V_154 < 0 )
return V_33 -> V_154 ;
}
F_68 ( L_67 , F_48 ( V_33 ) ,
& V_33 -> V_35 ) ;
F_69 ( V_33 ) ;
return 0 ;
}
int F_70 ( struct V_32 * V_33 )
{
int V_47 ;
unsigned long V_168 = V_170 ;
F_17 ( L_68 ) ;
F_71 ( & V_33 -> V_152 ) ;
V_47 = F_63 ( V_33 , V_168 ) ;
F_72 ( & V_33 -> V_152 ) ;
return V_47 ;
}
static int T_5 F_73 ( void )
{
int V_47 = 0 ;
V_47 = F_74 () ;
if ( V_47 < 0 )
goto V_85;
V_47 = F_75 () ;
if ( V_47 < 0 )
goto V_172;
V_47 = F_76 () ;
if ( V_47 < 0 )
goto V_173;
V_47 = F_77 () ;
if ( V_47 < 0 )
goto V_174;
F_68 ( L_69 ,
V_175 , V_176 ) ;
return 0 ;
V_174:
F_78 () ;
V_173:
F_79 () ;
V_172:
F_80 () ;
V_85:
return V_47 ;
}
static void T_6 F_81 ( void )
{
F_17 ( L_70 ) ;
F_82 ( ! F_83 () ) ;
F_84 () ;
F_78 () ;
F_79 () ;
F_80 () ;
}
