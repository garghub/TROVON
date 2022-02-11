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
V_46 = memcmp ( V_40 , V_41 , V_43 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_7 ( V_40 -> V_47 , V_41 -> V_47 ) ;
if ( V_46 )
return V_46 ;
if ( V_40 -> V_48 && ! V_41 -> V_48 )
return - 1 ;
if ( ! V_40 -> V_48 && V_41 -> V_48 )
return 1 ;
if ( V_40 -> V_48 && V_41 -> V_48 ) {
if ( V_40 -> V_48 -> type != V_41 -> V_48 -> type )
return - 1 ;
if ( V_40 -> V_48 -> V_49 . V_50 != V_41 -> V_48 -> V_49 . V_50 )
return - 1 ;
if ( V_40 -> V_48 -> V_49 . V_51 != V_41 -> V_48 -> V_49 . V_51 )
return - 1 ;
if ( V_40 -> V_48 -> V_3 != V_41 -> V_48 -> V_3 )
return - 1 ;
if ( V_40 -> V_48 -> V_48 && ! V_41 -> V_48 -> V_48 )
return - 1 ;
if ( ! V_40 -> V_48 -> V_48 && V_41 -> V_48 -> V_48 )
return 1 ;
if ( V_40 -> V_48 -> V_48 && V_41 -> V_48 -> V_48 ) {
V_46 = memcmp ( V_40 -> V_48 -> V_48 , V_41 -> V_48 -> V_48 , V_40 -> V_48 -> V_3 ) ;
if ( V_46 )
return V_46 ;
}
}
for ( V_45 = 0 ; V_45 < V_40 -> V_52 ; V_45 ++ ) {
if ( F_10 ( V_32 -> V_53 . V_54 ,
& V_40 -> V_44 [ V_45 ] ) )
return 0 ;
}
return - 1 ;
}
void * F_11 ( T_1 V_55 , T_2 V_56 )
{
if ( V_55 <= ( V_57 << V_58 ) ) {
void * V_59 = F_12 ( V_55 , V_56 | V_60 ) ;
if ( V_59 )
return V_59 ;
}
return F_13 ( V_55 , V_56 | V_61 , V_62 ) ;
}
static int F_14 ( const char * V_63 , struct V_33 * V_34 )
{
int V_45 = 0 ;
char V_64 [ 3 ] ;
int V_65 = - V_66 ;
int V_67 ;
F_15 ( L_29 , V_63 ) ;
V_64 [ 2 ] = 0 ;
while ( * V_63 && V_45 < 16 ) {
if ( ispunct ( * V_63 ) ) {
V_63 ++ ;
continue;
}
if ( ! isxdigit ( V_63 [ 0 ] ) || ! isxdigit ( V_63 [ 1 ] ) )
break;
V_64 [ 0 ] = V_63 [ 0 ] ;
V_64 [ 1 ] = V_63 [ 1 ] ;
if ( sscanf ( V_64 , L_30 , & V_67 ) < 1 )
break;
V_34 -> V_34 [ V_45 ] = V_67 & 0xff ;
V_45 ++ ;
V_63 += 2 ;
}
if ( V_45 == 16 )
V_65 = 0 ;
F_15 ( L_31 , V_65 , V_34 ) ;
return V_65 ;
}
void F_16 ( struct V_38 * V_68 )
{
F_15 ( L_32 , V_68 ) ;
F_17 ( V_68 -> V_47 ) ;
if ( V_68 -> V_48 ) {
F_18 ( V_68 -> V_48 ) ;
F_17 ( V_68 -> V_48 ) ;
}
F_17 ( V_68 -> V_44 ) ;
F_17 ( V_68 ) ;
}
static int F_19 ( struct V_69 * V_70 , const char * V_47 ) {
struct V_48 * V_71 ;
int V_72 ;
int V_65 = 0 ;
struct V_69 * V_73 ;
V_71 = F_20 ( & V_74 , V_47 , NULL ) ;
if ( ! V_71 || F_21 ( V_71 ) ) {
V_72 = F_22 ( V_71 ) ;
switch ( V_72 ) {
case - V_75 :
F_23 ( L_33 ,
V_47 ) ;
break;
case - V_76 :
F_23 ( L_34 ,
V_47 ) ;
break;
case - V_77 :
F_23 ( L_35 ,
V_47 ) ;
break;
default:
F_23 ( L_36 ,
V_72 , V_47 ) ;
}
V_65 = - V_78 ;
goto V_79;
}
V_73 = V_71 -> V_80 . V_1 ;
V_65 = F_24 ( V_70 , V_73 ) ;
if ( V_65 )
goto V_81;
V_81:
F_25 ( V_71 ) ;
V_79:
return V_65 ;
}
struct V_38 *
F_26 ( char * V_42 , const char * V_82 ,
const char * V_83 ,
int (* F_27)( char * V_84 , void * V_85 ) ,
void * V_85 )
{
struct V_38 * V_68 ;
const char * V_84 ;
int V_65 = - V_86 ;
T_3 V_87 [ V_88 ] ;
if ( V_89 -> V_90 -> V_91 != & V_92 )
return F_28 ( - V_66 ) ;
V_68 = F_29 ( sizeof( * V_68 ) , V_93 ) ;
if ( ! V_68 )
return F_28 ( - V_86 ) ;
V_68 -> V_44 = F_30 ( V_94 , sizeof( * V_68 -> V_44 ) ,
V_93 ) ;
if ( ! V_68 -> V_44 )
goto V_79;
F_15 ( L_37 , V_68 , V_42 ,
V_82 ) ;
V_68 -> V_56 = V_95 ;
V_68 -> V_96 = V_97 ;
V_68 -> V_98 = V_99 ;
V_68 -> V_100 = V_101 ;
V_65 = F_31 ( V_82 , V_83 , V_68 -> V_44 ,
V_94 , & V_68 -> V_52 ) ;
if ( V_65 < 0 )
goto V_79;
while ( ( V_84 = F_32 ( & V_42 , L_38 ) ) != NULL ) {
int V_102 , V_103 , V_46 ;
if ( ! * V_84 )
continue;
V_65 = - V_66 ;
V_102 = F_33 ( ( char * ) V_84 , V_104 , V_87 ) ;
if ( V_102 < 0 && F_27 ) {
V_65 = F_27 ( ( char * ) V_84 , V_85 ) ;
if ( V_65 < 0 ) {
F_6 ( L_39 , V_84 ) ;
goto V_79;
}
continue;
}
if ( V_102 < V_105 ) {
V_46 = F_34 ( & V_87 [ 0 ] , & V_103 ) ;
if ( V_46 < 0 ) {
F_6 ( L_40
L_41 , V_84 ) ;
continue;
}
F_15 ( L_42 , V_102 , V_103 ) ;
} else if ( V_102 > V_105 && V_102 < V_106 ) {
F_15 ( L_43 , V_102 ,
V_87 [ 0 ] . V_107 ) ;
} else {
F_15 ( L_44 , V_102 ) ;
}
switch ( V_102 ) {
case V_108 :
V_65 = F_31 ( V_87 [ 0 ] . V_107 ,
V_87 [ 0 ] . V_109 ,
& V_68 -> V_110 ,
1 , NULL ) ;
if ( V_65 < 0 )
goto V_79;
V_68 -> V_56 |= V_111 ;
break;
case V_112 :
V_65 = F_14 ( V_87 [ 0 ] . V_107 , & V_68 -> V_34 ) ;
if ( V_65 == 0 )
V_68 -> V_56 |= V_113 ;
break;
case V_114 :
V_68 -> V_47 = F_35 ( V_87 [ 0 ] . V_107 ,
V_87 [ 0 ] . V_109 - V_87 [ 0 ] . V_107 ,
V_93 ) ;
break;
case V_115 :
V_68 -> V_48 = F_29 ( sizeof( * V_68 -> V_48 ) , V_93 ) ;
if ( ! V_68 -> V_48 ) {
V_65 = - V_86 ;
goto V_79;
}
V_65 = F_36 ( V_68 -> V_48 , V_87 [ 0 ] . V_107 ) ;
if ( V_65 < 0 )
goto V_79;
break;
case V_116 :
V_68 -> V_48 = F_29 ( sizeof( * V_68 -> V_48 ) , V_93 ) ;
if ( ! V_68 -> V_48 ) {
V_65 = - V_86 ;
goto V_79;
}
V_65 = F_19 ( V_68 -> V_48 , V_87 [ 0 ] . V_107 ) ;
if ( V_65 < 0 )
goto V_79;
break;
case V_117 :
F_23 ( L_45 ) ;
break;
case V_118 :
V_68 -> V_96 = V_103 ;
break;
case V_119 :
V_68 -> V_100 = V_103 ;
break;
case V_120 :
V_68 -> V_98 = V_103 ;
break;
case V_121 :
V_68 -> V_56 &= ~ V_122 ;
break;
case V_123 :
V_68 -> V_56 |= V_122 ;
break;
case V_124 :
V_68 -> V_56 &= ~ V_125 ;
break;
case V_126 :
V_68 -> V_56 |= V_125 ;
break;
case V_127 :
V_68 -> V_56 &= ~ V_128 ;
break;
case V_129 :
V_68 -> V_56 |= V_128 ;
break;
case V_130 :
V_68 -> V_56 |= V_131 ;
break;
case V_132 :
V_68 -> V_56 &= ~ V_131 ;
break;
default:
F_37 ( V_102 ) ;
}
}
return V_68 ;
V_79:
F_16 ( V_68 ) ;
return F_28 ( V_65 ) ;
}
T_4 F_38 ( struct V_31 * V_32 )
{
return V_32 -> V_53 . V_133 -> V_134 ;
}
struct V_31 * F_39 ( struct V_38 * V_68 , void * V_85 ,
T_4 V_135 ,
T_4 V_136 )
{
struct V_31 * V_32 ;
struct V_137 * V_138 = NULL ;
int V_65 = - V_86 ;
V_32 = F_29 ( sizeof( * V_32 ) , V_93 ) ;
if ( V_32 == NULL )
return F_28 ( - V_86 ) ;
V_32 -> V_85 = V_85 ;
V_32 -> V_42 = V_68 ;
F_40 ( & V_32 -> V_139 ) ;
F_41 ( & V_32 -> V_140 ) ;
V_32 -> V_141 = 0 ;
if ( ! F_42 ( V_32 , V_142 ) )
V_136 |= V_143 ;
V_32 -> V_144 = NULL ;
V_32 -> V_135 = V_145 |
V_135 ;
V_32 -> V_136 = V_146 |
V_136 ;
if ( F_42 ( V_32 , V_147 ) )
V_138 = & V_32 -> V_42 -> V_110 ;
F_43 ( & V_32 -> V_148 , V_138 ,
V_32 -> V_135 ,
V_32 -> V_136 ,
F_42 ( V_32 , V_149 ) ,
F_42 ( V_32 , V_150 ) ) ;
V_65 = F_44 ( & V_32 -> V_53 , V_32 ) ;
if ( V_65 < 0 )
goto V_151;
V_65 = F_45 ( & V_32 -> V_152 , V_32 ) ;
if ( V_65 < 0 )
goto V_153;
return V_32 ;
V_153:
F_46 ( & V_32 -> V_53 ) ;
V_151:
F_17 ( V_32 ) ;
return F_28 ( V_65 ) ;
}
void F_47 ( struct V_31 * V_32 )
{
F_15 ( L_46 , V_32 ) ;
F_48 ( & V_32 -> V_148 . V_154 , 1 ) ;
F_49 ( & V_32 -> V_152 ) ;
F_46 ( & V_32 -> V_53 ) ;
F_50 ( V_32 ) ;
F_16 ( V_32 -> V_42 ) ;
F_17 ( V_32 ) ;
F_15 ( L_47 , V_32 ) ;
}
static int F_51 ( struct V_31 * V_32 )
{
return V_32 -> V_53 . V_54 && V_32 -> V_53 . V_54 -> V_155 &&
V_32 -> V_152 . V_156 && V_32 -> V_152 . V_156 -> V_155 ;
}
int F_52 ( struct V_31 * V_32 , unsigned long V_157 )
{
int V_65 ;
unsigned long V_158 = V_32 -> V_42 -> V_98 * V_159 ;
V_65 = F_53 ( & V_32 -> V_53 ) ;
if ( V_65 < 0 )
return V_65 ;
while ( ! F_51 ( V_32 ) ) {
V_65 = - V_160 ;
if ( V_158 && F_54 ( V_161 , V_157 + V_158 ) )
return V_65 ;
F_15 ( L_48 ) ;
V_65 = F_55 ( V_32 -> V_140 ,
F_51 ( V_32 ) || ( V_32 -> V_141 < 0 ) ,
V_158 ) ;
if ( V_65 == - V_162 || V_65 == - V_163 )
return V_65 ;
if ( V_32 -> V_141 < 0 )
return V_32 -> V_141 ;
}
return 0 ;
}
int F_56 ( struct V_31 * V_32 )
{
int V_46 ;
unsigned long V_157 = V_161 ;
F_15 ( L_49 ) ;
F_57 ( & V_32 -> V_139 ) ;
V_46 = F_52 ( V_32 , V_157 ) ;
F_58 ( & V_32 -> V_139 ) ;
return V_46 ;
}
static int T_5 F_59 ( void )
{
int V_46 = 0 ;
V_46 = F_60 () ;
if ( V_46 < 0 )
goto V_79;
V_46 = F_61 () ;
if ( V_46 < 0 )
goto V_164;
V_46 = F_62 () ;
if ( V_46 < 0 )
goto V_165;
V_46 = F_63 () ;
if ( V_46 < 0 )
goto V_166;
F_64 ( L_50 ,
V_167 , V_168 ) ;
return 0 ;
V_166:
F_65 () ;
V_165:
F_66 () ;
V_164:
F_67 () ;
V_79:
return V_46 ;
}
static void T_6 F_68 ( void )
{
F_15 ( L_51 ) ;
F_69 () ;
F_65 () ;
F_66 () ;
F_67 () ;
}
