const char * F_1 ( const char * V_1 , int V_2 )
{
const char * V_3 = V_1 + V_2 ;
while ( V_3 != V_1 && * ( V_3 - 1 ) != '/' )
V_3 -- ;
return V_3 ;
}
const char * F_2 ( int type )
{
switch ( type ) {
case V_4 : return L_1 ;
case V_5 : return L_2 ;
case V_6 : return L_3 ;
case V_7 : return L_4 ;
case V_8 : return L_5 ;
case V_9 : return L_6 ;
case V_10 : return L_7 ;
case V_11 : return L_8 ;
case V_12 : return L_9 ;
case V_13 : return L_10 ;
case V_14 : return L_11 ;
case V_15 : return L_12 ;
case V_16 : return L_13 ;
case V_17 : return L_14 ;
case V_18 : return L_15 ;
case V_19 : return L_16 ;
case V_20 : return L_17 ;
case V_21 : return L_18 ;
case V_22 : return L_19 ;
case V_23 : return L_20 ;
case V_24 : return L_21 ;
case V_25 : return L_22 ;
case V_26 : return L_23 ;
case V_27 : return L_24 ;
default: return L_25 ;
}
}
int F_3 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
if ( V_29 -> V_32 ) {
if ( F_4 ( & V_29 -> V_31 , V_31 ) ) {
F_5 ( L_26 ,
& V_29 -> V_31 , V_31 ) ;
return - 1 ;
}
} else {
memcpy ( & V_29 -> V_31 , V_31 , sizeof( * V_31 ) ) ;
}
return 0 ;
}
static int F_6 ( const char * V_33 , const char * V_34 )
{
if ( ! V_33 && ! V_34 )
return 0 ;
if ( V_33 && ! V_34 )
return - 1 ;
if ( ! V_33 && V_34 )
return 1 ;
return strcmp ( V_33 , V_34 ) ;
}
int F_7 ( struct V_35 * V_36 ,
struct V_28 * V_29 )
{
struct V_35 * V_37 = V_36 ;
struct V_35 * V_38 = V_29 -> V_39 ;
int V_40 = F_8 ( struct V_35 , V_41 ) ;
int V_42 ;
int V_43 ;
V_43 = memcmp ( V_37 , V_38 , V_40 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_6 ( V_37 -> V_44 , V_38 -> V_44 ) ;
if ( V_43 )
return V_43 ;
if ( V_37 -> V_45 && ! V_38 -> V_45 )
return - 1 ;
if ( ! V_37 -> V_45 && V_38 -> V_45 )
return 1 ;
if ( V_37 -> V_45 && V_38 -> V_45 ) {
if ( V_37 -> V_45 -> type != V_38 -> V_45 -> type )
return - 1 ;
if ( V_37 -> V_45 -> V_46 . V_47 != V_38 -> V_45 -> V_46 . V_47 )
return - 1 ;
if ( V_37 -> V_45 -> V_46 . V_48 != V_38 -> V_45 -> V_46 . V_48 )
return - 1 ;
if ( V_37 -> V_45 -> V_2 != V_38 -> V_45 -> V_2 )
return - 1 ;
if ( V_37 -> V_45 -> V_45 && ! V_38 -> V_45 -> V_45 )
return - 1 ;
if ( ! V_37 -> V_45 -> V_45 && V_38 -> V_45 -> V_45 )
return 1 ;
if ( V_37 -> V_45 -> V_45 && V_38 -> V_45 -> V_45 ) {
V_43 = memcmp ( V_37 -> V_45 -> V_45 , V_38 -> V_45 -> V_45 , V_37 -> V_45 -> V_2 ) ;
if ( V_43 )
return V_43 ;
}
}
for ( V_42 = 0 ; V_42 < V_37 -> V_49 ; V_42 ++ ) {
if ( F_9 ( V_29 -> V_50 . V_51 ,
& V_37 -> V_41 [ V_42 ] ) )
return 0 ;
}
return - 1 ;
}
static int F_10 ( const char * V_52 , struct V_30 * V_31 )
{
int V_42 = 0 ;
char V_53 [ 3 ] ;
int V_54 = - V_55 ;
int V_56 ;
F_11 ( L_27 , V_52 ) ;
V_53 [ 2 ] = 0 ;
while ( * V_52 && V_42 < 16 ) {
if ( ispunct ( * V_52 ) ) {
V_52 ++ ;
continue;
}
if ( ! isxdigit ( V_52 [ 0 ] ) || ! isxdigit ( V_52 [ 1 ] ) )
break;
V_53 [ 0 ] = V_52 [ 0 ] ;
V_53 [ 1 ] = V_52 [ 1 ] ;
if ( sscanf ( V_53 , L_28 , & V_56 ) < 1 )
break;
V_31 -> V_31 [ V_42 ] = V_56 & 0xff ;
V_42 ++ ;
V_52 += 2 ;
}
if ( V_42 == 16 )
V_54 = 0 ;
F_11 ( L_29 , V_54 , V_31 ) ;
return V_54 ;
}
void F_12 ( struct V_35 * V_57 )
{
F_11 ( L_30 , V_57 ) ;
F_13 ( V_57 -> V_44 ) ;
if ( V_57 -> V_45 ) {
F_14 ( V_57 -> V_45 ) ;
F_13 ( V_57 -> V_45 ) ;
}
F_13 ( V_57 -> V_41 ) ;
F_13 ( V_57 ) ;
}
static int F_15 ( struct V_58 * V_59 , const char * V_44 ) {
struct V_45 * V_60 ;
int V_61 ;
int V_54 = 0 ;
struct V_58 * V_62 ;
V_60 = F_16 ( & V_63 , V_44 , NULL ) ;
if ( ! V_60 || F_17 ( V_60 ) ) {
V_61 = F_18 ( V_60 ) ;
switch ( V_61 ) {
case - V_64 :
F_19 ( L_31 , V_44 ) ;
break;
case - V_65 :
F_19 ( L_32 , V_44 ) ;
break;
case - V_66 :
F_19 ( L_33 , V_44 ) ;
break;
default:
F_19 ( L_34
L_35 , V_61 , V_44 ) ;
}
V_54 = - V_67 ;
goto V_68;
}
V_62 = V_60 -> V_69 . V_70 ;
V_54 = F_20 ( V_59 , V_62 ) ;
if ( V_54 )
goto V_71;
V_71:
F_21 ( V_60 ) ;
V_68:
return V_54 ;
}
struct V_35 *
F_22 ( char * V_39 , const char * V_72 ,
const char * V_73 ,
int (* F_23)( char * V_74 , void * V_75 ) ,
void * V_75 )
{
struct V_35 * V_57 ;
const char * V_74 ;
int V_54 = - V_76 ;
T_1 V_77 [ V_78 ] ;
V_57 = F_24 ( sizeof( * V_57 ) , V_79 ) ;
if ( ! V_57 )
return F_25 ( - V_76 ) ;
V_57 -> V_41 = F_26 ( V_80 , sizeof( * V_57 -> V_41 ) ,
V_79 ) ;
if ( ! V_57 -> V_41 )
goto V_68;
F_11 ( L_36 , V_57 , V_39 ,
V_72 ) ;
V_57 -> V_81 = V_82 ;
V_57 -> V_83 = V_84 ;
V_57 -> V_85 = V_86 ;
V_57 -> V_87 = V_88 ;
V_54 = F_27 ( V_72 , V_73 , V_57 -> V_41 ,
V_80 , & V_57 -> V_49 ) ;
if ( V_54 < 0 )
goto V_68;
while ( ( V_74 = F_28 ( & V_39 , L_37 ) ) != NULL ) {
int V_89 , V_90 , V_43 ;
if ( ! * V_74 )
continue;
V_54 = - V_55 ;
V_89 = F_29 ( ( char * ) V_74 , V_91 , V_77 ) ;
if ( V_89 < 0 && F_23 ) {
V_54 = F_23 ( ( char * ) V_74 , V_75 ) ;
if ( V_54 < 0 ) {
F_5 ( L_38 , V_74 ) ;
goto V_68;
}
continue;
}
if ( V_89 < V_92 ) {
V_43 = F_30 ( & V_77 [ 0 ] , & V_90 ) ;
if ( V_43 < 0 ) {
F_5 ( L_39
L_40 , V_74 ) ;
continue;
}
F_11 ( L_41 , V_89 , V_90 ) ;
} else if ( V_89 > V_92 && V_89 < V_93 ) {
F_11 ( L_42 , V_89 ,
V_77 [ 0 ] . V_94 ) ;
} else {
F_11 ( L_43 , V_89 ) ;
}
switch ( V_89 ) {
case V_95 :
V_54 = F_27 ( V_77 [ 0 ] . V_94 ,
V_77 [ 0 ] . V_96 ,
& V_57 -> V_97 ,
1 , NULL ) ;
if ( V_54 < 0 )
goto V_68;
V_57 -> V_81 |= V_98 ;
break;
case V_99 :
V_54 = F_10 ( V_77 [ 0 ] . V_94 , & V_57 -> V_31 ) ;
if ( V_54 == 0 )
V_57 -> V_81 |= V_100 ;
break;
case V_101 :
V_57 -> V_44 = F_31 ( V_77 [ 0 ] . V_94 ,
V_77 [ 0 ] . V_96 - V_77 [ 0 ] . V_94 ,
V_79 ) ;
break;
case V_102 :
V_57 -> V_45 = F_24 ( sizeof( * V_57 -> V_45 ) , V_79 ) ;
if ( ! V_57 -> V_45 ) {
V_54 = - V_76 ;
goto V_68;
}
V_54 = F_32 ( V_57 -> V_45 , V_77 [ 0 ] . V_94 ) ;
if ( V_54 < 0 )
goto V_68;
break;
case V_103 :
V_57 -> V_45 = F_24 ( sizeof( * V_57 -> V_45 ) , V_79 ) ;
if ( ! V_57 -> V_45 ) {
V_54 = - V_76 ;
goto V_68;
}
V_54 = F_15 ( V_57 -> V_45 , V_77 [ 0 ] . V_94 ) ;
if ( V_54 < 0 )
goto V_68;
break;
case V_104 :
F_19 ( L_44 ) ;
break;
case V_105 :
V_57 -> V_83 = V_90 ;
break;
case V_106 :
V_57 -> V_87 = V_90 ;
break;
case V_107 :
V_57 -> V_85 = V_90 ;
break;
case V_108 :
V_57 -> V_81 &= ~ V_109 ;
break;
case V_110 :
V_57 -> V_81 |= V_109 ;
break;
case V_111 :
V_57 -> V_81 &= ~ V_112 ;
break;
case V_113 :
V_57 -> V_81 |= V_112 ;
break;
default:
F_33 ( V_89 ) ;
}
}
return V_57 ;
V_68:
F_12 ( V_57 ) ;
return F_25 ( V_54 ) ;
}
T_2 F_34 ( struct V_28 * V_29 )
{
return V_29 -> V_50 . V_114 -> V_115 ;
}
struct V_28 * F_35 ( struct V_35 * V_57 , void * V_75 ,
unsigned int V_116 ,
unsigned int V_117 )
{
struct V_28 * V_29 ;
struct V_118 * V_119 = NULL ;
int V_54 = - V_76 ;
V_29 = F_24 ( sizeof( * V_29 ) , V_79 ) ;
if ( V_29 == NULL )
return F_25 ( - V_76 ) ;
V_29 -> V_75 = V_75 ;
V_29 -> V_39 = V_57 ;
F_36 ( & V_29 -> V_120 ) ;
F_37 ( & V_29 -> V_121 ) ;
V_29 -> V_122 = 0 ;
V_29 -> V_123 = NULL ;
V_29 -> V_116 = V_124 |
V_116 ;
V_29 -> V_117 = V_125 |
V_117 ;
if ( F_38 ( V_29 , V_126 ) )
V_119 = & V_29 -> V_39 -> V_97 ;
F_39 ( & V_29 -> V_127 , V_119 ,
V_29 -> V_116 ,
V_29 -> V_117 ,
F_38 ( V_29 , V_128 ) ) ;
V_54 = F_40 ( & V_29 -> V_50 , V_29 ) ;
if ( V_54 < 0 )
goto V_129;
V_54 = F_41 ( & V_29 -> V_130 , V_29 ) ;
if ( V_54 < 0 )
goto V_131;
return V_29 ;
V_131:
F_42 ( & V_29 -> V_50 ) ;
V_129:
F_13 ( V_29 ) ;
return F_25 ( V_54 ) ;
}
void F_43 ( struct V_28 * V_29 )
{
F_11 ( L_45 , V_29 ) ;
F_44 ( & V_29 -> V_127 . V_132 , 1 ) ;
F_45 ( & V_29 -> V_130 ) ;
F_42 ( & V_29 -> V_50 ) ;
F_46 ( V_29 ) ;
F_12 ( V_29 -> V_39 ) ;
F_13 ( V_29 ) ;
F_11 ( L_46 , V_29 ) ;
}
static int F_47 ( struct V_28 * V_29 )
{
return V_29 -> V_50 . V_51 && V_29 -> V_50 . V_51 -> V_133 &&
V_29 -> V_130 . V_134 && V_29 -> V_130 . V_134 -> V_133 ;
}
int F_48 ( struct V_28 * V_29 , unsigned long V_135 )
{
int V_54 ;
unsigned long V_136 = V_29 -> V_39 -> V_85 * V_137 ;
V_54 = F_49 ( & V_29 -> V_50 ) ;
if ( V_54 < 0 )
return V_54 ;
while ( ! F_47 ( V_29 ) ) {
V_54 = - V_138 ;
if ( V_136 && F_50 ( V_139 , V_135 + V_136 ) )
return V_54 ;
F_11 ( L_47 ) ;
V_54 = F_51 ( V_29 -> V_121 ,
F_47 ( V_29 ) || ( V_29 -> V_122 < 0 ) ,
V_136 ) ;
if ( V_54 == - V_140 || V_54 == - V_141 )
return V_54 ;
if ( V_29 -> V_122 < 0 )
return V_29 -> V_122 ;
}
return 0 ;
}
int F_52 ( struct V_28 * V_29 )
{
int V_43 ;
unsigned long V_135 = V_139 ;
F_11 ( L_48 ) ;
F_53 ( & V_29 -> V_120 ) ;
V_43 = F_48 ( V_29 , V_135 ) ;
F_54 ( & V_29 -> V_120 ) ;
return V_43 ;
}
static int T_3 F_55 ( void )
{
int V_43 = 0 ;
V_43 = F_56 () ;
if ( V_43 < 0 )
goto V_68;
V_43 = F_57 () ;
if ( V_43 < 0 )
goto V_142;
V_43 = F_58 () ;
if ( V_43 < 0 )
goto V_143;
F_59 ( L_49 ,
V_144 , V_145 ,
V_146 , V_147 ,
V_148 , V_149 ) ;
return 0 ;
V_143:
F_60 () ;
V_142:
F_61 () ;
V_68:
return V_43 ;
}
static void T_4 F_62 ( void )
{
F_11 ( L_50 ) ;
F_63 () ;
F_60 () ;
F_61 () ;
}
