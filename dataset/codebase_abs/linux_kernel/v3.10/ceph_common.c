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
default: return L_25 ;
}
}
int F_4 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
if ( V_30 -> V_33 ) {
if ( F_5 ( & V_30 -> V_32 , V_32 ) ) {
F_6 ( L_26 ,
& V_30 -> V_32 , V_32 ) ;
return - 1 ;
}
} else {
memcpy ( & V_30 -> V_32 , V_32 , sizeof( * V_32 ) ) ;
}
return 0 ;
}
static int F_7 ( const char * V_34 , const char * V_35 )
{
if ( ! V_34 && ! V_35 )
return 0 ;
if ( V_34 && ! V_35 )
return - 1 ;
if ( ! V_34 && V_35 )
return 1 ;
return strcmp ( V_34 , V_35 ) ;
}
int F_8 ( struct V_36 * V_37 ,
struct V_29 * V_30 )
{
struct V_36 * V_38 = V_37 ;
struct V_36 * V_39 = V_30 -> V_40 ;
int V_41 = F_9 ( struct V_36 , V_42 ) ;
int V_43 ;
int V_44 ;
V_44 = memcmp ( V_38 , V_39 , V_41 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_7 ( V_38 -> V_45 , V_39 -> V_45 ) ;
if ( V_44 )
return V_44 ;
if ( V_38 -> V_46 && ! V_39 -> V_46 )
return - 1 ;
if ( ! V_38 -> V_46 && V_39 -> V_46 )
return 1 ;
if ( V_38 -> V_46 && V_39 -> V_46 ) {
if ( V_38 -> V_46 -> type != V_39 -> V_46 -> type )
return - 1 ;
if ( V_38 -> V_46 -> V_47 . V_48 != V_39 -> V_46 -> V_47 . V_48 )
return - 1 ;
if ( V_38 -> V_46 -> V_47 . V_49 != V_39 -> V_46 -> V_47 . V_49 )
return - 1 ;
if ( V_38 -> V_46 -> V_3 != V_39 -> V_46 -> V_3 )
return - 1 ;
if ( V_38 -> V_46 -> V_46 && ! V_39 -> V_46 -> V_46 )
return - 1 ;
if ( ! V_38 -> V_46 -> V_46 && V_39 -> V_46 -> V_46 )
return 1 ;
if ( V_38 -> V_46 -> V_46 && V_39 -> V_46 -> V_46 ) {
V_44 = memcmp ( V_38 -> V_46 -> V_46 , V_39 -> V_46 -> V_46 , V_38 -> V_46 -> V_3 ) ;
if ( V_44 )
return V_44 ;
}
}
for ( V_43 = 0 ; V_43 < V_38 -> V_50 ; V_43 ++ ) {
if ( F_10 ( V_30 -> V_51 . V_52 ,
& V_38 -> V_42 [ V_43 ] ) )
return 0 ;
}
return - 1 ;
}
static int F_11 ( const char * V_53 , struct V_31 * V_32 )
{
int V_43 = 0 ;
char V_54 [ 3 ] ;
int V_55 = - V_56 ;
int V_57 ;
F_12 ( L_27 , V_53 ) ;
V_54 [ 2 ] = 0 ;
while ( * V_53 && V_43 < 16 ) {
if ( ispunct ( * V_53 ) ) {
V_53 ++ ;
continue;
}
if ( ! isxdigit ( V_53 [ 0 ] ) || ! isxdigit ( V_53 [ 1 ] ) )
break;
V_54 [ 0 ] = V_53 [ 0 ] ;
V_54 [ 1 ] = V_53 [ 1 ] ;
if ( sscanf ( V_54 , L_28 , & V_57 ) < 1 )
break;
V_32 -> V_32 [ V_43 ] = V_57 & 0xff ;
V_43 ++ ;
V_53 += 2 ;
}
if ( V_43 == 16 )
V_55 = 0 ;
F_12 ( L_29 , V_55 , V_32 ) ;
return V_55 ;
}
void F_13 ( struct V_36 * V_58 )
{
F_12 ( L_30 , V_58 ) ;
F_14 ( V_58 -> V_45 ) ;
if ( V_58 -> V_46 ) {
F_15 ( V_58 -> V_46 ) ;
F_14 ( V_58 -> V_46 ) ;
}
F_14 ( V_58 -> V_42 ) ;
F_14 ( V_58 ) ;
}
static int F_16 ( struct V_59 * V_60 , const char * V_45 ) {
struct V_46 * V_61 ;
int V_62 ;
int V_55 = 0 ;
struct V_59 * V_63 ;
V_61 = F_17 ( & V_64 , V_45 , NULL ) ;
if ( ! V_61 || F_18 ( V_61 ) ) {
V_62 = F_19 ( V_61 ) ;
switch ( V_62 ) {
case - V_65 :
F_20 ( L_31 , V_45 ) ;
break;
case - V_66 :
F_20 ( L_32 , V_45 ) ;
break;
case - V_67 :
F_20 ( L_33 , V_45 ) ;
break;
default:
F_20 ( L_34
L_35 , V_62 , V_45 ) ;
}
V_55 = - V_68 ;
goto V_69;
}
V_63 = V_61 -> V_70 . V_1 ;
V_55 = F_21 ( V_60 , V_63 ) ;
if ( V_55 )
goto V_71;
V_71:
F_22 ( V_61 ) ;
V_69:
return V_55 ;
}
struct V_36 *
F_23 ( char * V_40 , const char * V_72 ,
const char * V_73 ,
int (* F_24)( char * V_74 , void * V_75 ) ,
void * V_75 )
{
struct V_36 * V_58 ;
const char * V_74 ;
int V_55 = - V_76 ;
T_1 V_77 [ V_78 ] ;
if ( V_79 -> V_80 -> V_81 != & V_82 )
return F_25 ( - V_56 ) ;
V_58 = F_26 ( sizeof( * V_58 ) , V_83 ) ;
if ( ! V_58 )
return F_25 ( - V_76 ) ;
V_58 -> V_42 = F_27 ( V_84 , sizeof( * V_58 -> V_42 ) ,
V_83 ) ;
if ( ! V_58 -> V_42 )
goto V_69;
F_12 ( L_36 , V_58 , V_40 ,
V_72 ) ;
V_58 -> V_85 = V_86 ;
V_58 -> V_87 = V_88 ;
V_58 -> V_89 = V_90 ;
V_58 -> V_91 = V_92 ;
V_55 = F_28 ( V_72 , V_73 , V_58 -> V_42 ,
V_84 , & V_58 -> V_50 ) ;
if ( V_55 < 0 )
goto V_69;
while ( ( V_74 = F_29 ( & V_40 , L_37 ) ) != NULL ) {
int V_93 , V_94 , V_44 ;
if ( ! * V_74 )
continue;
V_55 = - V_56 ;
V_93 = F_30 ( ( char * ) V_74 , V_95 , V_77 ) ;
if ( V_93 < 0 && F_24 ) {
V_55 = F_24 ( ( char * ) V_74 , V_75 ) ;
if ( V_55 < 0 ) {
F_6 ( L_38 , V_74 ) ;
goto V_69;
}
continue;
}
if ( V_93 < V_96 ) {
V_44 = F_31 ( & V_77 [ 0 ] , & V_94 ) ;
if ( V_44 < 0 ) {
F_6 ( L_39
L_40 , V_74 ) ;
continue;
}
F_12 ( L_41 , V_93 , V_94 ) ;
} else if ( V_93 > V_96 && V_93 < V_97 ) {
F_12 ( L_42 , V_93 ,
V_77 [ 0 ] . V_98 ) ;
} else {
F_12 ( L_43 , V_93 ) ;
}
switch ( V_93 ) {
case V_99 :
V_55 = F_28 ( V_77 [ 0 ] . V_98 ,
V_77 [ 0 ] . V_100 ,
& V_58 -> V_101 ,
1 , NULL ) ;
if ( V_55 < 0 )
goto V_69;
V_58 -> V_85 |= V_102 ;
break;
case V_103 :
V_55 = F_11 ( V_77 [ 0 ] . V_98 , & V_58 -> V_32 ) ;
if ( V_55 == 0 )
V_58 -> V_85 |= V_104 ;
break;
case V_105 :
V_58 -> V_45 = F_32 ( V_77 [ 0 ] . V_98 ,
V_77 [ 0 ] . V_100 - V_77 [ 0 ] . V_98 ,
V_83 ) ;
break;
case V_106 :
V_58 -> V_46 = F_26 ( sizeof( * V_58 -> V_46 ) , V_83 ) ;
if ( ! V_58 -> V_46 ) {
V_55 = - V_76 ;
goto V_69;
}
V_55 = F_33 ( V_58 -> V_46 , V_77 [ 0 ] . V_98 ) ;
if ( V_55 < 0 )
goto V_69;
break;
case V_107 :
V_58 -> V_46 = F_26 ( sizeof( * V_58 -> V_46 ) , V_83 ) ;
if ( ! V_58 -> V_46 ) {
V_55 = - V_76 ;
goto V_69;
}
V_55 = F_16 ( V_58 -> V_46 , V_77 [ 0 ] . V_98 ) ;
if ( V_55 < 0 )
goto V_69;
break;
case V_108 :
F_20 ( L_44 ) ;
break;
case V_109 :
V_58 -> V_87 = V_94 ;
break;
case V_110 :
V_58 -> V_91 = V_94 ;
break;
case V_111 :
V_58 -> V_89 = V_94 ;
break;
case V_112 :
V_58 -> V_85 &= ~ V_113 ;
break;
case V_114 :
V_58 -> V_85 |= V_113 ;
break;
case V_115 :
V_58 -> V_85 &= ~ V_116 ;
break;
case V_117 :
V_58 -> V_85 |= V_116 ;
break;
default:
F_34 ( V_93 ) ;
}
}
return V_58 ;
V_69:
F_13 ( V_58 ) ;
return F_25 ( V_55 ) ;
}
T_2 F_35 ( struct V_29 * V_30 )
{
return V_30 -> V_51 . V_118 -> V_119 ;
}
struct V_29 * F_36 ( struct V_36 * V_58 , void * V_75 ,
unsigned int V_120 ,
unsigned int V_121 )
{
struct V_29 * V_30 ;
struct V_122 * V_123 = NULL ;
int V_55 = - V_76 ;
V_30 = F_26 ( sizeof( * V_30 ) , V_83 ) ;
if ( V_30 == NULL )
return F_25 ( - V_76 ) ;
V_30 -> V_75 = V_75 ;
V_30 -> V_40 = V_58 ;
F_37 ( & V_30 -> V_124 ) ;
F_38 ( & V_30 -> V_125 ) ;
V_30 -> V_126 = 0 ;
V_30 -> V_127 = NULL ;
V_30 -> V_120 = V_128 |
V_120 ;
V_30 -> V_121 = V_129 |
V_121 ;
if ( F_39 ( V_30 , V_130 ) )
V_123 = & V_30 -> V_40 -> V_101 ;
F_40 ( & V_30 -> V_131 , V_123 ,
V_30 -> V_120 ,
V_30 -> V_121 ,
F_39 ( V_30 , V_132 ) ) ;
V_55 = F_41 ( & V_30 -> V_51 , V_30 ) ;
if ( V_55 < 0 )
goto V_133;
V_55 = F_42 ( & V_30 -> V_134 , V_30 ) ;
if ( V_55 < 0 )
goto V_135;
return V_30 ;
V_135:
F_43 ( & V_30 -> V_51 ) ;
V_133:
F_14 ( V_30 ) ;
return F_25 ( V_55 ) ;
}
void F_44 ( struct V_29 * V_30 )
{
F_12 ( L_45 , V_30 ) ;
F_45 ( & V_30 -> V_131 . V_136 , 1 ) ;
F_46 ( & V_30 -> V_134 ) ;
F_43 ( & V_30 -> V_51 ) ;
F_47 ( V_30 ) ;
F_13 ( V_30 -> V_40 ) ;
F_14 ( V_30 ) ;
F_12 ( L_46 , V_30 ) ;
}
static int F_48 ( struct V_29 * V_30 )
{
return V_30 -> V_51 . V_52 && V_30 -> V_51 . V_52 -> V_137 &&
V_30 -> V_134 . V_138 && V_30 -> V_134 . V_138 -> V_137 ;
}
int F_49 ( struct V_29 * V_30 , unsigned long V_139 )
{
int V_55 ;
unsigned long V_140 = V_30 -> V_40 -> V_89 * V_141 ;
V_55 = F_50 ( & V_30 -> V_51 ) ;
if ( V_55 < 0 )
return V_55 ;
while ( ! F_48 ( V_30 ) ) {
V_55 = - V_142 ;
if ( V_140 && F_51 ( V_143 , V_139 + V_140 ) )
return V_55 ;
F_12 ( L_47 ) ;
V_55 = F_52 ( V_30 -> V_125 ,
F_48 ( V_30 ) || ( V_30 -> V_126 < 0 ) ,
V_140 ) ;
if ( V_55 == - V_144 || V_55 == - V_145 )
return V_55 ;
if ( V_30 -> V_126 < 0 )
return V_30 -> V_126 ;
}
return 0 ;
}
int F_53 ( struct V_29 * V_30 )
{
int V_44 ;
unsigned long V_139 = V_143 ;
F_12 ( L_48 ) ;
F_54 ( & V_30 -> V_124 ) ;
V_44 = F_49 ( V_30 , V_139 ) ;
F_55 ( & V_30 -> V_124 ) ;
return V_44 ;
}
static int T_3 F_56 ( void )
{
int V_44 = 0 ;
V_44 = F_57 () ;
if ( V_44 < 0 )
goto V_69;
V_44 = F_58 () ;
if ( V_44 < 0 )
goto V_146;
V_44 = F_59 () ;
if ( V_44 < 0 )
goto V_147;
V_44 = F_60 () ;
if ( V_44 < 0 )
goto V_148;
F_61 ( L_49 ,
V_149 , V_150 ) ;
return 0 ;
V_148:
F_62 () ;
V_147:
F_63 () ;
V_146:
F_64 () ;
V_69:
return V_44 ;
}
static void T_4 F_65 ( void )
{
F_12 ( L_50 ) ;
F_66 () ;
F_62 () ;
F_63 () ;
F_64 () ;
}
