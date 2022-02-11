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
void * F_11 ( T_1 V_53 , T_2 V_54 )
{
if ( V_53 <= ( V_55 << V_56 ) ) {
void * V_57 = F_12 ( V_53 , V_54 | V_58 ) ;
if ( V_57 )
return V_57 ;
}
return F_13 ( V_53 , V_54 | V_59 , V_60 ) ;
}
void F_14 ( const void * V_57 )
{
if ( F_15 ( V_57 ) )
F_16 ( V_57 ) ;
else
F_17 ( V_57 ) ;
}
static int F_18 ( const char * V_61 , struct V_31 * V_32 )
{
int V_43 = 0 ;
char V_62 [ 3 ] ;
int V_63 = - V_64 ;
int V_65 ;
F_19 ( L_27 , V_61 ) ;
V_62 [ 2 ] = 0 ;
while ( * V_61 && V_43 < 16 ) {
if ( ispunct ( * V_61 ) ) {
V_61 ++ ;
continue;
}
if ( ! isxdigit ( V_61 [ 0 ] ) || ! isxdigit ( V_61 [ 1 ] ) )
break;
V_62 [ 0 ] = V_61 [ 0 ] ;
V_62 [ 1 ] = V_61 [ 1 ] ;
if ( sscanf ( V_62 , L_28 , & V_65 ) < 1 )
break;
V_32 -> V_32 [ V_43 ] = V_65 & 0xff ;
V_43 ++ ;
V_61 += 2 ;
}
if ( V_43 == 16 )
V_63 = 0 ;
F_19 ( L_29 , V_63 , V_32 ) ;
return V_63 ;
}
void F_20 ( struct V_36 * V_66 )
{
F_19 ( L_30 , V_66 ) ;
F_17 ( V_66 -> V_45 ) ;
if ( V_66 -> V_46 ) {
F_21 ( V_66 -> V_46 ) ;
F_17 ( V_66 -> V_46 ) ;
}
F_17 ( V_66 -> V_42 ) ;
F_17 ( V_66 ) ;
}
static int F_22 ( struct V_67 * V_68 , const char * V_45 ) {
struct V_46 * V_69 ;
int V_70 ;
int V_63 = 0 ;
struct V_67 * V_71 ;
V_69 = F_23 ( & V_72 , V_45 , NULL ) ;
if ( ! V_69 || F_24 ( V_69 ) ) {
V_70 = F_25 ( V_69 ) ;
switch ( V_70 ) {
case - V_73 :
F_26 ( L_31 , V_45 ) ;
break;
case - V_74 :
F_26 ( L_32 , V_45 ) ;
break;
case - V_75 :
F_26 ( L_33 , V_45 ) ;
break;
default:
F_26 ( L_34
L_35 , V_70 , V_45 ) ;
}
V_63 = - V_76 ;
goto V_77;
}
V_71 = V_69 -> V_78 . V_1 ;
V_63 = F_27 ( V_68 , V_71 ) ;
if ( V_63 )
goto V_79;
V_79:
F_28 ( V_69 ) ;
V_77:
return V_63 ;
}
struct V_36 *
F_29 ( char * V_40 , const char * V_80 ,
const char * V_81 ,
int (* F_30)( char * V_82 , void * V_83 ) ,
void * V_83 )
{
struct V_36 * V_66 ;
const char * V_82 ;
int V_63 = - V_84 ;
T_3 V_85 [ V_86 ] ;
if ( V_87 -> V_88 -> V_89 != & V_90 )
return F_31 ( - V_64 ) ;
V_66 = F_32 ( sizeof( * V_66 ) , V_91 ) ;
if ( ! V_66 )
return F_31 ( - V_84 ) ;
V_66 -> V_42 = F_33 ( V_92 , sizeof( * V_66 -> V_42 ) ,
V_91 ) ;
if ( ! V_66 -> V_42 )
goto V_77;
F_19 ( L_36 , V_66 , V_40 ,
V_80 ) ;
V_66 -> V_54 = V_93 ;
V_66 -> V_94 = V_95 ;
V_66 -> V_96 = V_97 ;
V_66 -> V_98 = V_99 ;
V_63 = F_34 ( V_80 , V_81 , V_66 -> V_42 ,
V_92 , & V_66 -> V_50 ) ;
if ( V_63 < 0 )
goto V_77;
while ( ( V_82 = F_35 ( & V_40 , L_37 ) ) != NULL ) {
int V_100 , V_101 , V_44 ;
if ( ! * V_82 )
continue;
V_63 = - V_64 ;
V_100 = F_36 ( ( char * ) V_82 , V_102 , V_85 ) ;
if ( V_100 < 0 && F_30 ) {
V_63 = F_30 ( ( char * ) V_82 , V_83 ) ;
if ( V_63 < 0 ) {
F_6 ( L_38 , V_82 ) ;
goto V_77;
}
continue;
}
if ( V_100 < V_103 ) {
V_44 = F_37 ( & V_85 [ 0 ] , & V_101 ) ;
if ( V_44 < 0 ) {
F_6 ( L_39
L_40 , V_82 ) ;
continue;
}
F_19 ( L_41 , V_100 , V_101 ) ;
} else if ( V_100 > V_103 && V_100 < V_104 ) {
F_19 ( L_42 , V_100 ,
V_85 [ 0 ] . V_105 ) ;
} else {
F_19 ( L_43 , V_100 ) ;
}
switch ( V_100 ) {
case V_106 :
V_63 = F_34 ( V_85 [ 0 ] . V_105 ,
V_85 [ 0 ] . V_107 ,
& V_66 -> V_108 ,
1 , NULL ) ;
if ( V_63 < 0 )
goto V_77;
V_66 -> V_54 |= V_109 ;
break;
case V_110 :
V_63 = F_18 ( V_85 [ 0 ] . V_105 , & V_66 -> V_32 ) ;
if ( V_63 == 0 )
V_66 -> V_54 |= V_111 ;
break;
case V_112 :
V_66 -> V_45 = F_38 ( V_85 [ 0 ] . V_105 ,
V_85 [ 0 ] . V_107 - V_85 [ 0 ] . V_105 ,
V_91 ) ;
break;
case V_113 :
V_66 -> V_46 = F_32 ( sizeof( * V_66 -> V_46 ) , V_91 ) ;
if ( ! V_66 -> V_46 ) {
V_63 = - V_84 ;
goto V_77;
}
V_63 = F_39 ( V_66 -> V_46 , V_85 [ 0 ] . V_105 ) ;
if ( V_63 < 0 )
goto V_77;
break;
case V_114 :
V_66 -> V_46 = F_32 ( sizeof( * V_66 -> V_46 ) , V_91 ) ;
if ( ! V_66 -> V_46 ) {
V_63 = - V_84 ;
goto V_77;
}
V_63 = F_22 ( V_66 -> V_46 , V_85 [ 0 ] . V_105 ) ;
if ( V_63 < 0 )
goto V_77;
break;
case V_115 :
F_26 ( L_44 ) ;
break;
case V_116 :
V_66 -> V_94 = V_101 ;
break;
case V_117 :
V_66 -> V_98 = V_101 ;
break;
case V_118 :
V_66 -> V_96 = V_101 ;
break;
case V_119 :
V_66 -> V_54 &= ~ V_120 ;
break;
case V_121 :
V_66 -> V_54 |= V_120 ;
break;
case V_122 :
V_66 -> V_54 &= ~ V_123 ;
break;
case V_124 :
V_66 -> V_54 |= V_123 ;
break;
default:
F_40 ( V_100 ) ;
}
}
return V_66 ;
V_77:
F_20 ( V_66 ) ;
return F_31 ( V_63 ) ;
}
T_4 F_41 ( struct V_29 * V_30 )
{
return V_30 -> V_51 . V_125 -> V_126 ;
}
struct V_29 * F_42 ( struct V_36 * V_66 , void * V_83 ,
T_4 V_127 ,
T_4 V_128 )
{
struct V_29 * V_30 ;
struct V_129 * V_130 = NULL ;
int V_63 = - V_84 ;
V_30 = F_32 ( sizeof( * V_30 ) , V_91 ) ;
if ( V_30 == NULL )
return F_31 ( - V_84 ) ;
V_30 -> V_83 = V_83 ;
V_30 -> V_40 = V_66 ;
F_43 ( & V_30 -> V_131 ) ;
F_44 ( & V_30 -> V_132 ) ;
V_30 -> V_133 = 0 ;
V_30 -> V_134 = NULL ;
V_30 -> V_127 = V_135 |
V_127 ;
V_30 -> V_128 = V_136 |
V_128 ;
if ( F_45 ( V_30 , V_137 ) )
V_130 = & V_30 -> V_40 -> V_108 ;
F_46 ( & V_30 -> V_138 , V_130 ,
V_30 -> V_127 ,
V_30 -> V_128 ,
F_45 ( V_30 , V_139 ) ) ;
V_63 = F_47 ( & V_30 -> V_51 , V_30 ) ;
if ( V_63 < 0 )
goto V_140;
V_63 = F_48 ( & V_30 -> V_141 , V_30 ) ;
if ( V_63 < 0 )
goto V_142;
return V_30 ;
V_142:
F_49 ( & V_30 -> V_51 ) ;
V_140:
F_17 ( V_30 ) ;
return F_31 ( V_63 ) ;
}
void F_50 ( struct V_29 * V_30 )
{
F_19 ( L_45 , V_30 ) ;
F_51 ( & V_30 -> V_138 . V_143 , 1 ) ;
F_52 ( & V_30 -> V_141 ) ;
F_49 ( & V_30 -> V_51 ) ;
F_53 ( V_30 ) ;
F_20 ( V_30 -> V_40 ) ;
F_17 ( V_30 ) ;
F_19 ( L_46 , V_30 ) ;
}
static int F_54 ( struct V_29 * V_30 )
{
return V_30 -> V_51 . V_52 && V_30 -> V_51 . V_52 -> V_144 &&
V_30 -> V_141 . V_145 && V_30 -> V_141 . V_145 -> V_144 ;
}
int F_55 ( struct V_29 * V_30 , unsigned long V_146 )
{
int V_63 ;
unsigned long V_147 = V_30 -> V_40 -> V_96 * V_148 ;
V_63 = F_56 ( & V_30 -> V_51 ) ;
if ( V_63 < 0 )
return V_63 ;
while ( ! F_54 ( V_30 ) ) {
V_63 = - V_149 ;
if ( V_147 && F_57 ( V_150 , V_146 + V_147 ) )
return V_63 ;
F_19 ( L_47 ) ;
V_63 = F_58 ( V_30 -> V_132 ,
F_54 ( V_30 ) || ( V_30 -> V_133 < 0 ) ,
V_147 ) ;
if ( V_63 == - V_151 || V_63 == - V_152 )
return V_63 ;
if ( V_30 -> V_133 < 0 )
return V_30 -> V_133 ;
}
return 0 ;
}
int F_59 ( struct V_29 * V_30 )
{
int V_44 ;
unsigned long V_146 = V_150 ;
F_19 ( L_48 ) ;
F_60 ( & V_30 -> V_131 ) ;
V_44 = F_55 ( V_30 , V_146 ) ;
F_61 ( & V_30 -> V_131 ) ;
return V_44 ;
}
static int T_5 F_62 ( void )
{
int V_44 = 0 ;
V_44 = F_63 () ;
if ( V_44 < 0 )
goto V_77;
V_44 = F_64 () ;
if ( V_44 < 0 )
goto V_153;
V_44 = F_65 () ;
if ( V_44 < 0 )
goto V_154;
V_44 = F_66 () ;
if ( V_44 < 0 )
goto V_155;
F_67 ( L_49 ,
V_156 , V_157 ) ;
return 0 ;
V_155:
F_68 () ;
V_154:
F_69 () ;
V_153:
F_70 () ;
V_77:
return V_44 ;
}
static void T_6 F_71 ( void )
{
F_19 ( L_50 ) ;
F_72 () ;
F_68 () ;
F_69 () ;
F_70 () ;
}
