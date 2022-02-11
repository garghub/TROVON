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
F_6 ( L_27 , F_7 ( V_29 ) , V_31 ) ;
memcpy ( & V_29 -> V_31 , V_31 , sizeof( * V_31 ) ) ;
F_8 ( V_29 ) ;
V_29 -> V_32 = true ;
}
return 0 ;
}
static int F_9 ( const char * V_33 , const char * V_34 )
{
if ( ! V_33 && ! V_34 )
return 0 ;
if ( V_33 && ! V_34 )
return - 1 ;
if ( ! V_33 && V_34 )
return 1 ;
return strcmp ( V_33 , V_34 ) ;
}
int F_10 ( struct V_35 * V_36 ,
struct V_28 * V_29 )
{
struct V_35 * V_37 = V_36 ;
struct V_35 * V_38 = V_29 -> V_39 ;
int V_40 = F_11 ( struct V_35 , V_41 ) ;
int V_42 ;
int V_43 ;
V_43 = memcmp ( V_37 , V_38 , V_40 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_9 ( V_37 -> V_44 , V_38 -> V_44 ) ;
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
if ( F_12 ( V_29 -> V_50 . V_51 ,
& V_37 -> V_41 [ V_42 ] ) )
return 0 ;
}
return - 1 ;
}
static int F_13 ( const char * V_52 , struct V_30 * V_31 )
{
int V_42 = 0 ;
char V_53 [ 3 ] ;
int V_54 = - V_55 ;
int V_56 ;
F_14 ( L_28 , V_52 ) ;
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
if ( sscanf ( V_53 , L_29 , & V_56 ) < 1 )
break;
V_31 -> V_31 [ V_42 ] = V_56 & 0xff ;
V_42 ++ ;
V_52 += 2 ;
}
if ( V_42 == 16 )
V_54 = 0 ;
F_14 ( L_30 , V_54 , V_31 ) ;
return V_54 ;
}
void F_15 ( struct V_35 * V_57 )
{
F_14 ( L_31 , V_57 ) ;
F_16 ( V_57 -> V_44 ) ;
if ( V_57 -> V_45 ) {
F_17 ( V_57 -> V_45 ) ;
F_16 ( V_57 -> V_45 ) ;
}
F_16 ( V_57 -> V_41 ) ;
F_16 ( V_57 ) ;
}
static int F_18 ( struct V_58 * V_59 , const char * V_44 ) {
struct V_45 * V_60 ;
int V_61 ;
int V_54 = 0 ;
struct V_58 * V_62 ;
V_60 = F_19 ( & V_63 , V_44 , NULL ) ;
if ( ! V_60 || F_20 ( V_60 ) ) {
V_61 = F_21 ( V_60 ) ;
switch ( V_61 ) {
case - V_64 :
F_22 ( L_32 , V_44 ) ;
break;
case - V_65 :
F_22 ( L_33 , V_44 ) ;
break;
case - V_66 :
F_22 ( L_34 , V_44 ) ;
break;
default:
F_22 ( L_35
L_36 , V_61 , V_44 ) ;
}
V_54 = - V_67 ;
goto V_68;
}
V_62 = V_60 -> V_69 . V_70 ;
V_54 = F_23 ( V_59 , V_62 ) ;
if ( V_54 )
goto V_71;
V_71:
F_24 ( V_60 ) ;
V_68:
return V_54 ;
}
int F_25 ( struct V_35 * * V_72 , char * V_39 ,
const char * V_73 , const char * V_74 ,
int (* F_26)( char * V_75 , void * V_76 ) ,
void * V_76 )
{
struct V_35 * V_57 ;
const char * V_75 ;
int V_54 = - V_77 ;
T_1 V_78 [ V_79 ] ;
V_57 = F_27 ( sizeof( * V_57 ) , V_80 ) ;
if ( ! V_57 )
return V_54 ;
V_57 -> V_41 = F_28 ( V_81 , sizeof( * V_57 -> V_41 ) ,
V_80 ) ;
if ( ! V_57 -> V_41 )
goto V_68;
F_14 ( L_37 , V_57 , V_39 ,
V_73 ) ;
V_57 -> V_82 = V_83 ;
V_57 -> V_84 = V_85 ;
V_57 -> V_86 = V_87 ;
V_57 -> V_88 = V_89 ;
V_57 -> V_90 = V_91 ;
V_54 = F_29 ( V_73 , V_74 , V_57 -> V_41 ,
V_81 , & V_57 -> V_49 ) ;
if ( V_54 < 0 )
goto V_68;
while ( ( V_75 = F_30 ( & V_39 , L_38 ) ) != NULL ) {
int V_92 , V_93 , V_43 ;
if ( ! * V_75 )
continue;
V_54 = - V_55 ;
V_92 = F_31 ( ( char * ) V_75 , V_94 , V_78 ) ;
if ( V_92 < 0 && F_26 ) {
V_54 = F_26 ( ( char * ) V_75 , V_76 ) ;
if ( V_54 < 0 ) {
F_5 ( L_39 , V_75 ) ;
goto V_68;
}
continue;
}
if ( V_92 < V_95 ) {
V_43 = F_32 ( & V_78 [ 0 ] , & V_93 ) ;
if ( V_43 < 0 ) {
F_5 ( L_40
L_41 , V_75 ) ;
continue;
}
F_14 ( L_42 , V_92 , V_93 ) ;
} else if ( V_92 > V_95 && V_92 < V_96 ) {
F_14 ( L_43 , V_92 ,
V_78 [ 0 ] . V_97 ) ;
} else {
F_14 ( L_44 , V_92 ) ;
}
switch ( V_92 ) {
case V_98 :
V_54 = F_29 ( V_78 [ 0 ] . V_97 ,
V_78 [ 0 ] . V_99 ,
& V_57 -> V_100 ,
1 , NULL ) ;
if ( V_54 < 0 )
goto V_68;
V_57 -> V_82 |= V_101 ;
break;
case V_102 :
V_54 = F_13 ( V_78 [ 0 ] . V_97 , & V_57 -> V_31 ) ;
if ( V_54 == 0 )
V_57 -> V_82 |= V_103 ;
break;
case V_104 :
V_57 -> V_44 = F_33 ( V_78 [ 0 ] . V_97 ,
V_78 [ 0 ] . V_99 - V_78 [ 0 ] . V_97 ,
V_80 ) ;
break;
case V_105 :
V_57 -> V_45 = F_27 ( sizeof( * V_57 -> V_45 ) , V_80 ) ;
if ( ! V_57 -> V_45 ) {
V_54 = - V_77 ;
goto V_68;
}
V_54 = F_34 ( V_57 -> V_45 , V_78 [ 0 ] . V_97 ) ;
if ( V_54 < 0 )
goto V_68;
break;
case V_106 :
V_57 -> V_45 = F_27 ( sizeof( * V_57 -> V_45 ) , V_80 ) ;
if ( ! V_57 -> V_45 ) {
V_54 = - V_77 ;
goto V_68;
}
V_54 = F_18 ( V_57 -> V_45 , V_78 [ 0 ] . V_97 ) ;
if ( V_54 < 0 )
goto V_68;
break;
case V_107 :
V_57 -> V_84 = V_93 ;
break;
case V_108 :
V_57 -> V_86 = V_93 ;
break;
case V_109 :
V_57 -> V_90 = V_93 ;
break;
case V_110 :
V_57 -> V_88 = V_93 ;
break;
case V_111 :
V_57 -> V_82 |= V_112 ;
break;
case V_113 :
V_57 -> V_82 |= V_114 ;
break;
default:
F_35 ( V_92 ) ;
}
}
* V_72 = V_57 ;
return 0 ;
V_68:
F_15 ( V_57 ) ;
return V_54 ;
}
T_2 F_7 ( struct V_28 * V_29 )
{
return V_29 -> V_50 . V_115 -> V_116 ;
}
struct V_28 * F_36 ( struct V_35 * V_57 , void * V_76 ,
unsigned V_117 ,
unsigned V_118 )
{
struct V_28 * V_29 ;
struct V_119 * V_120 = NULL ;
int V_54 = - V_77 ;
V_29 = F_27 ( sizeof( * V_29 ) , V_80 ) ;
if ( V_29 == NULL )
return F_37 ( - V_77 ) ;
V_29 -> V_76 = V_76 ;
V_29 -> V_39 = V_57 ;
F_38 ( & V_29 -> V_121 ) ;
F_39 ( & V_29 -> V_122 ) ;
V_29 -> V_123 = 0 ;
V_29 -> V_124 = NULL ;
V_29 -> V_117 = V_125 |
V_117 ;
V_29 -> V_118 = V_126 |
V_118 ;
if ( F_40 ( V_29 , V_127 ) )
V_120 = & V_29 -> V_39 -> V_100 ;
V_29 -> V_128 = F_41 ( V_120 ,
V_29 -> V_117 ,
V_29 -> V_118 ) ;
if ( F_20 ( V_29 -> V_128 ) ) {
V_54 = F_21 ( V_29 -> V_128 ) ;
goto V_129;
}
V_29 -> V_128 -> V_130 = F_40 ( V_29 , V_131 ) ;
V_54 = F_42 ( & V_29 -> V_50 , V_29 ) ;
if ( V_54 < 0 )
goto V_132;
V_54 = F_43 ( & V_29 -> V_133 , V_29 ) ;
if ( V_54 < 0 )
goto V_134;
return V_29 ;
V_134:
F_44 ( & V_29 -> V_50 ) ;
V_132:
F_45 ( V_29 -> V_128 ) ;
V_129:
F_16 ( V_29 ) ;
return F_37 ( V_54 ) ;
}
void F_46 ( struct V_28 * V_29 )
{
F_14 ( L_45 , V_29 ) ;
F_47 ( & V_29 -> V_133 ) ;
F_48 () ;
F_44 ( & V_29 -> V_50 ) ;
F_49 ( V_29 ) ;
F_45 ( V_29 -> V_128 ) ;
F_15 ( V_29 -> V_39 ) ;
F_16 ( V_29 ) ;
F_14 ( L_46 , V_29 ) ;
}
static int F_50 ( struct V_28 * V_29 )
{
return V_29 -> V_50 . V_51 && V_29 -> V_50 . V_51 -> V_135 &&
V_29 -> V_133 . V_136 && V_29 -> V_133 . V_136 -> V_135 ;
}
int F_51 ( struct V_28 * V_29 , unsigned long V_137 )
{
int V_54 ;
unsigned long V_138 = V_29 -> V_39 -> V_88 * V_139 ;
V_54 = F_52 ( & V_29 -> V_50 ) ;
if ( V_54 < 0 )
return V_54 ;
while ( ! F_50 ( V_29 ) ) {
V_54 = - V_140 ;
if ( V_138 && F_53 ( V_141 , V_137 + V_138 ) )
return V_54 ;
F_14 ( L_47 ) ;
V_54 = F_54 ( V_29 -> V_122 ,
F_50 ( V_29 ) || ( V_29 -> V_123 < 0 ) ,
V_138 ) ;
if ( V_54 == - V_142 || V_54 == - V_143 )
return V_54 ;
if ( V_29 -> V_123 < 0 )
return V_29 -> V_123 ;
}
return 0 ;
}
int F_55 ( struct V_28 * V_29 )
{
int V_43 ;
unsigned long V_137 = V_141 ;
F_14 ( L_48 ) ;
F_56 ( & V_29 -> V_121 ) ;
V_43 = F_51 ( V_29 , V_137 ) ;
F_57 ( & V_29 -> V_121 ) ;
return V_43 ;
}
static int T_3 F_58 ( void )
{
int V_43 = 0 ;
V_43 = F_59 () ;
if ( V_43 < 0 )
goto V_68;
V_43 = F_60 () ;
if ( V_43 < 0 )
goto V_144;
V_43 = F_61 () ;
if ( V_43 < 0 )
goto V_145;
F_6 ( L_49 ,
V_146 , V_147 ,
V_148 , V_149 ,
V_150 , V_151 ) ;
return 0 ;
V_145:
F_62 () ;
V_144:
F_63 () ;
V_68:
return V_43 ;
}
static void T_4 F_64 ( void )
{
F_14 ( L_50 ) ;
F_65 () ;
F_62 () ;
F_63 () ;
}
