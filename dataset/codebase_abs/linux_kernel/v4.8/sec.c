int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
if ( V_3 >= V_8 )
return - V_9 ;
F_3 ( & V_10 ) ;
if ( F_4 ( V_11 [ V_3 ] ) ) {
F_5 ( & V_10 ) ;
return - V_12 ;
}
V_11 [ V_3 ] = V_2 ;
F_5 ( & V_10 ) ;
F_6 ( V_13 , L_1 , V_2 -> V_5 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 ;
F_2 ( V_3 < V_8 ) ;
F_3 ( & V_10 ) ;
if ( F_4 ( ! V_11 [ V_3 ] ) ) {
F_5 ( & V_10 ) ;
F_8 ( L_2 , V_2 -> V_5 ) ;
return - V_9 ;
}
F_2 ( V_11 [ V_3 ] == V_2 ) ;
V_11 [ V_3 ] = NULL ;
F_5 ( & V_10 ) ;
F_6 ( V_13 , L_3 , V_2 -> V_5 ) ;
return 0 ;
}
static
struct V_1 * F_9 ( T_2 V_14 )
{
static F_10 ( V_15 ) ;
static T_3 V_16 = F_11 ( 0 ) ;
struct V_1 * V_2 ;
T_1 V_3 = F_12 ( V_14 ) ;
T_1 V_17 = 0 ;
if ( V_3 >= V_8 )
return NULL ;
while ( 1 ) {
F_13 ( & V_10 ) ;
V_2 = V_11 [ V_3 ] ;
if ( V_2 && ! F_14 ( V_2 -> V_18 ) )
V_2 = NULL ;
if ( ! V_2 )
V_17 = F_15 ( & V_16 ) ;
F_16 ( & V_10 ) ;
if ( V_2 || V_17 != 0 ||
V_3 != V_19 )
break;
F_17 ( & V_15 ) ;
if ( F_15 ( & V_16 ) == 0 ) {
if ( F_18 ( L_4 ) == 0 )
F_6 ( V_13 ,
L_5 ) ;
else
F_8 ( L_6 ) ;
F_19 ( & V_16 , 1 ) ;
}
F_20 ( & V_15 ) ;
}
return V_2 ;
}
T_2 F_21 ( const char * V_20 )
{
if ( ! strcmp ( V_20 , L_7 ) )
return V_21 ;
if ( ! strcmp ( V_20 , L_8 ) )
return V_22 ;
if ( ! strcmp ( V_20 , L_9 ) )
return V_23 ;
if ( ! strcmp ( V_20 , L_10 ) )
return V_24 ;
if ( ! strcmp ( V_20 , L_11 ) )
return V_25 ;
if ( ! strcmp ( V_20 , L_12 ) )
return V_26 ;
return V_27 ;
}
const char * F_22 ( T_2 V_28 )
{
T_2 V_29 = F_23 ( V_28 ) ;
if ( V_29 == F_23 ( V_21 ) )
return L_7 ;
else if ( V_29 == F_23 ( V_22 ) )
return L_8 ;
else if ( V_29 == F_23 ( V_23 ) )
return L_9 ;
else if ( V_29 == F_23 ( V_24 ) )
return L_10 ;
else if ( V_29 == F_23 ( V_25 ) )
return L_11 ;
else if ( V_29 == F_23 ( V_26 ) )
return L_12 ;
F_8 ( L_13 , V_28 ) ;
return L_14 ;
}
char * F_24 ( struct V_30 * V_31 ,
char * V_32 , int V_33 )
{
if ( F_12 ( V_31 -> V_34 ) == V_35 )
snprintf ( V_32 , V_33 , L_15 ,
F_25 ( V_31 -> V_36 . V_37 . V_38 ) ) ;
else
snprintf ( V_32 , V_33 , L_16 ,
F_22 ( V_31 -> V_34 ) ) ;
V_32 [ V_33 - 1 ] = '\0' ;
return V_32 ;
}
char * F_26 ( struct V_30 * V_31 , char * V_32 , int V_33 )
{
F_27 ( V_32 , F_22 ( V_31 -> V_34 ) , V_33 ) ;
if ( F_12 ( V_31 -> V_34 ) == V_35 ) {
char V_39 [ 16 ] ;
V_39 [ 0 ] = '-' ;
F_24 ( V_31 , & V_39 [ 1 ] , sizeof( V_39 ) - 1 ) ;
F_28 ( V_32 , V_39 , V_33 ) ;
}
return V_32 ;
}
static char * F_29 ( T_2 V_40 , char * V_32 , int V_33 )
{
V_32 [ 0 ] = '\0' ;
if ( V_40 & V_41 )
F_28 ( V_32 , L_17 , V_33 ) ;
if ( V_40 & V_42 )
F_28 ( V_32 , L_18 , V_33 ) ;
if ( V_40 & V_43 )
F_28 ( V_32 , L_19 , V_33 ) ;
if ( V_40 & V_44 )
F_28 ( V_32 , L_20 , V_33 ) ;
if ( V_32 [ 0 ] == '\0' )
F_28 ( V_32 , L_21 , V_33 ) ;
return V_32 ;
}
static
struct V_45 * F_30 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
int V_50 = 1 , V_51 = 1 ;
F_2 ( V_47 ) ;
F_2 ( V_47 -> V_52 -> V_6 -> V_53 ) ;
if ( V_47 -> V_54 . V_55 & ( V_41 |
V_42 ) ) {
V_49 . V_56 = 0 ;
V_49 . V_57 = 0 ;
if ( V_47 -> V_54 . V_55 & V_41 ) {
V_50 = 0 ;
V_51 = 0 ;
}
} else {
V_49 . V_56 = F_31 ( & V_58 , F_32 () ) ;
V_49 . V_57 = F_33 ( & V_58 , F_34 () ) ;
}
return V_47 -> V_52 -> V_6 -> V_53 ( V_47 , & V_49 ,
V_50 , V_51 ) ;
}
struct V_45 * F_35 ( struct V_45 * V_59 )
{
F_36 ( & V_59 -> V_60 ) ;
return V_59 ;
}
void F_37 ( struct V_45 * V_59 , int V_61 )
{
struct V_46 * V_47 = V_59 -> V_62 ;
F_2 ( V_47 ) ;
F_38 ( & V_59 -> V_60 ) ;
if ( ! F_39 ( & V_59 -> V_60 ) )
return;
V_47 -> V_52 -> V_6 -> V_63 ( V_47 , V_59 , V_61 ) ;
}
static int F_40 ( struct V_64 * V_65 )
{
int V_66 = 0 ;
F_41 ( & V_65 -> V_67 ) ;
if ( V_65 -> V_68 &&
V_65 -> V_68 < F_42 () ) {
V_66 = 1 ;
V_65 -> V_68 = 0 ;
}
F_43 ( & V_65 -> V_67 ) ;
if ( ! V_66 )
return 0 ;
F_6 ( V_13 , L_22 ) ;
return F_44 ( V_65 , NULL , NULL ) ;
}
static int F_45 ( struct V_64 * V_65 ,
struct V_46 * * V_47 )
{
int V_69 ;
if ( F_4 ( V_65 -> V_68 ) ) {
V_69 = F_40 ( V_65 ) ;
if ( V_69 )
return V_69 ;
}
* V_47 = F_46 ( V_65 ) ;
if ( ! * V_47 ) {
F_8 ( L_23 ,
V_65 , F_47 ( V_65 -> V_70 ) ) ;
return - V_71 ;
}
if ( F_4 ( ( * V_47 ) -> V_72 ) ) {
F_8 ( L_24 , V_47 ) ;
F_48 ( * V_47 ) ;
return - V_71 ;
}
return 0 ;
}
int F_49 ( struct V_73 * V_74 )
{
struct V_64 * V_65 = V_74 -> V_75 ;
struct V_46 * V_47 ;
int V_69 ;
F_2 ( ! V_74 -> V_76 ) ;
F_2 ( V_65 ) ;
V_69 = F_45 ( V_65 , & V_47 ) ;
if ( V_69 )
return V_69 ;
V_74 -> V_76 = F_30 ( V_47 ) ;
F_48 ( V_47 ) ;
if ( ! V_74 -> V_76 ) {
F_8 ( L_25 , V_74 ) ;
return - V_77 ;
}
return 0 ;
}
void F_50 ( struct V_73 * V_74 , int V_61 )
{
F_2 ( V_74 ) ;
F_2 ( V_74 -> V_76 ) ;
if ( ! F_51 ( & V_74 -> V_78 ) ) {
F_41 ( & V_74 -> V_76 -> V_79 ) ;
F_52 ( & V_74 -> V_78 ) ;
F_43 ( & V_74 -> V_76 -> V_79 ) ;
}
F_37 ( V_74 -> V_76 , V_61 ) ;
V_74 -> V_76 = NULL ;
}
static
int F_53 ( struct V_73 * V_74 ,
struct V_45 * V_80 ,
struct V_45 * V_81 )
{
struct V_30 V_82 ;
char * V_83 = NULL ;
int V_84 ;
int V_69 = 0 ;
F_2 ( V_74 -> V_85 ) ;
F_2 ( V_74 -> V_86 ) ;
F_2 ( V_74 -> V_87 ) ;
F_6 ( V_13 , L_26 ,
V_74 ,
V_80 , V_80 -> V_88 . V_56 , F_54 ( V_80 -> V_62 ) ,
V_81 , V_81 -> V_88 . V_56 , F_54 ( V_81 -> V_62 ) ,
V_80 -> V_62 , V_80 -> V_62 -> V_52 -> V_5 ,
V_81 -> V_62 , V_81 -> V_62 -> V_52 -> V_5 ) ;
V_82 = V_74 -> V_89 ;
V_84 = V_74 -> V_86 ;
if ( V_84 != 0 ) {
V_83 = F_55 ( V_84 , V_90 ) ;
if ( ! V_83 )
return - V_77 ;
memcpy ( V_83 , V_74 -> V_85 , V_84 ) ;
}
V_74 -> V_76 = V_80 ;
F_56 ( V_74 ) ;
F_57 ( V_74 ) ;
V_74 -> V_76 = V_81 ;
F_58 ( V_74 , 0 ) ;
if ( V_84 != 0 ) {
V_69 = F_59 ( V_74 , V_84 ) ;
if ( ! V_69 ) {
F_2 ( V_74 -> V_85 ) ;
memcpy ( V_74 -> V_85 , V_83 , V_84 ) ;
} else {
F_60 ( L_27 , V_69 ) ;
V_74 -> V_89 = V_82 ;
}
F_61 ( V_83 ) ;
}
return V_69 ;
}
static int F_62 ( struct V_73 * V_74 )
{
struct V_45 * V_80 = V_74 -> V_76 ;
struct V_45 * V_81 ;
int V_69 ;
F_2 ( V_80 ) ;
F_35 ( V_80 ) ;
F_50 ( V_74 , 0 ) ;
V_69 = F_49 ( V_74 ) ;
if ( F_4 ( V_69 ) ) {
F_2 ( ! V_74 -> V_76 ) ;
V_74 -> V_76 = V_80 ;
return V_69 ;
}
V_81 = V_74 -> V_76 ;
F_2 ( V_81 ) ;
if ( F_4 ( V_81 == V_80 &&
F_63 ( V_91 , & V_80 -> V_92 ) ) ) {
F_6 ( V_13 ,
L_28 ,
V_81 , V_81 -> V_92 ) ;
F_64 ( V_93 ) ;
F_65 ( V_94 ) ;
} else {
V_69 = F_53 ( V_74 , V_80 , V_81 ) ;
if ( V_69 ) {
F_50 ( V_74 , 0 ) ;
V_74 -> V_76 = V_80 ;
return V_69 ;
}
F_2 ( V_74 -> V_76 == V_81 ) ;
}
F_37 ( V_80 , 1 ) ;
return 0 ;
}
static
int F_66 ( struct V_45 * V_59 )
{
if ( F_67 ( V_59 ) )
return 1 ;
return 0 ;
}
static
int F_68 ( void * V_95 )
{
struct V_73 * V_74 = V_95 ;
int V_69 ;
F_69 ( V_74 -> V_85 , V_74 -> V_75 -> V_96 ) ;
V_69 = F_70 ( V_74 , 1 ) ;
if ( V_69 == 0 )
V_74 -> V_76 -> V_97 -> V_98 ( V_74 -> V_76 , 0 ) ;
return V_69 ;
}
static
void F_71 ( void * V_95 )
{
struct V_73 * V_74 = V_95 ;
F_41 ( & V_74 -> V_99 ) ;
V_74 -> V_100 = 1 ;
F_43 ( & V_74 -> V_99 ) ;
}
static
void F_72 ( struct V_73 * V_74 , struct V_45 * V_59 )
{
F_41 ( & V_59 -> V_79 ) ;
if ( ! F_51 ( & V_74 -> V_78 ) )
F_52 ( & V_74 -> V_78 ) ;
F_43 ( & V_59 -> V_79 ) ;
}
int F_73 ( struct V_73 * V_74 , long V_101 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_46 * V_47 ;
struct V_102 V_103 ;
int V_69 ;
F_2 ( V_59 ) ;
if ( V_74 -> V_104 || V_74 -> V_105 )
return 0 ;
V_106:
V_69 = F_45 ( V_74 -> V_75 , & V_47 ) ;
if ( V_69 )
return V_69 ;
if ( V_47 -> V_54 . V_34 != V_74 -> V_89 . V_34 ) {
F_6 ( V_13 , L_29 ,
V_74 , V_74 -> V_89 . V_34 , V_47 -> V_54 . V_34 ) ;
F_72 ( V_74 , V_59 ) ;
F_62 ( V_74 ) ;
V_59 = V_74 -> V_76 ;
}
F_48 ( V_47 ) ;
if ( F_74 ( V_59 ) )
return 0 ;
if ( F_4 ( F_63 ( V_107 , & V_59 -> V_92 ) ) ) {
F_2 ( V_59 -> V_97 -> V_108 ) ;
V_59 -> V_97 -> V_108 ( V_59 ) ;
}
F_2 ( F_63 ( V_107 , & V_59 -> V_92 ) == 0 ) ;
F_2 ( V_59 -> V_97 -> V_109 ) ;
if ( V_59 -> V_97 -> V_109 ( V_59 ) == 0 ) {
F_72 ( V_74 , V_59 ) ;
return 0 ;
}
if ( F_4 ( F_63 ( V_110 , & V_59 -> V_92 ) ) ) {
F_41 ( & V_74 -> V_99 ) ;
V_74 -> V_111 = 1 ;
F_43 ( & V_74 -> V_99 ) ;
F_72 ( V_74 , V_59 ) ;
return - V_112 ;
}
if ( F_63 ( V_113 , & V_59 -> V_92 ) &&
F_4 ( V_74 -> V_85 ) &&
F_75 ( V_74 -> V_85 ) & V_114 ) {
F_72 ( V_74 , V_59 ) ;
return 0 ;
}
if ( F_4 ( F_63 ( V_91 , & V_59 -> V_92 ) ) ) {
F_72 ( V_74 , V_59 ) ;
if ( V_74 -> V_75 -> V_115 ) {
F_41 ( & V_74 -> V_99 ) ;
V_74 -> V_111 = 1 ;
F_43 ( & V_74 -> V_99 ) ;
return - V_116 ;
}
V_69 = F_62 ( V_74 ) ;
if ( V_69 ) {
F_2 ( V_59 == V_74 -> V_76 ) ;
F_8 ( L_30 ,
V_74 , V_59 , V_69 ) ;
F_41 ( & V_74 -> V_99 ) ;
V_74 -> V_111 = 1 ;
F_43 ( & V_74 -> V_99 ) ;
return V_69 ;
}
V_59 = V_74 -> V_76 ;
goto V_106;
}
F_41 ( & V_59 -> V_79 ) ;
if ( F_51 ( & V_74 -> V_78 ) )
F_76 ( & V_74 -> V_78 , & V_59 -> V_117 ) ;
F_43 ( & V_59 -> V_79 ) ;
if ( V_101 < 0 )
return - V_118 ;
F_2 ( V_74 -> V_119 == 0 ) ;
F_41 ( & V_74 -> V_99 ) ;
V_74 -> V_111 = 0 ;
V_74 -> V_120 = 0 ;
V_74 -> V_121 = 0 ;
V_74 -> V_122 = 0 ;
F_43 ( & V_74 -> V_99 ) ;
V_103 = F_77 ( V_101 * V_94 , F_68 ,
F_71 , V_74 ) ;
V_69 = F_78 ( V_74 -> V_123 , F_66 ( V_59 ) , & V_103 ) ;
if ( ! F_67 ( V_59 ) ) {
F_72 ( V_74 , V_59 ) ;
F_2 ( V_69 != 0 ) ;
return V_69 ;
}
goto V_106;
}
void F_58 ( struct V_73 * V_74 , int V_124 )
{
struct V_46 * V_47 ;
F_2 ( V_74 -> V_75 ) ;
F_2 ( V_74 -> V_76 ) ;
F_2 ( V_74 -> V_76 -> V_62 ) ;
F_2 ( V_74 -> V_125 == 0 || V_74 -> V_126 == 0 ) ;
switch ( V_124 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_74 -> V_125 = 1 ;
break;
case V_131 :
case V_132 :
V_74 -> V_126 = 1 ;
break;
case V_133 :
V_74 -> V_104 = 1 ;
break;
case V_134 :
V_74 -> V_105 = 1 ;
break;
case 0 :
F_2 ( V_74 -> V_104 == 0 ) ;
F_2 ( V_74 -> V_105 == 0 ) ;
V_74 -> V_135 = 0 ;
V_74 -> V_136 = 0 ;
break;
}
V_47 = V_74 -> V_76 -> V_62 ;
F_41 ( & V_47 -> V_137 ) ;
V_74 -> V_89 = V_47 -> V_54 ;
F_43 ( & V_47 -> V_137 ) ;
if ( F_4 ( V_74 -> V_104 ) )
F_79 ( & V_74 -> V_89 . V_34 , V_138 ) ;
else if ( F_4 ( V_74 -> V_105 ) )
F_79 ( & V_74 -> V_89 . V_34 , V_139 ) ;
if ( ( V_47 -> V_54 . V_55 & V_43 ) &&
( V_74 -> V_89 . V_34 != V_21 ) )
V_74 -> V_135 = 1 ;
if ( ( V_74 -> V_125 || V_74 -> V_126 ) &&
F_80 ( & V_74 -> V_89 ) )
V_74 -> V_136 = 1 ;
}
void F_81 ( struct V_73 * V_74 )
{
if ( F_82 ( V_74 -> V_89 . V_34 ) != V_140 )
return;
F_2 ( V_74 -> V_141 ) ;
if ( V_74 -> V_142 || ! V_74 -> V_143 )
return;
F_83 ( V_74 -> V_143 ) ;
V_74 -> V_143 = NULL ;
V_74 -> V_144 = 0 ;
}
int F_84 ( struct V_64 * V_65 )
{
struct V_46 * V_47 ;
struct V_45 * V_59 ;
struct V_73 * V_74 = NULL ;
int V_69 ;
F_85 () ;
V_47 = F_46 ( V_65 ) ;
V_59 = F_30 ( V_47 ) ;
F_48 ( V_47 ) ;
if ( ! V_59 )
return - V_77 ;
if ( F_74 ( V_59 ) ||
V_59 -> V_97 -> V_109 ( V_59 ) == 0 ) {
F_37 ( V_59 , 1 ) ;
return 0 ;
}
if ( F_86 ( V_59 ) ) {
F_37 ( V_59 , 1 ) ;
return - V_71 ;
}
V_74 = F_87 ( V_90 ) ;
if ( ! V_74 )
return - V_77 ;
F_88 ( V_74 ) ;
F_19 ( & V_74 -> V_145 , 10000 ) ;
V_74 -> V_75 = V_65 ;
V_74 -> V_89 = V_47 -> V_54 ;
V_74 -> V_76 = V_59 ;
V_69 = F_73 ( V_74 , 0 ) ;
F_2 ( F_51 ( & V_74 -> V_78 ) ) ;
F_37 ( V_74 -> V_76 , 1 ) ;
F_89 ( V_74 ) ;
return V_69 ;
}
int F_90 ( struct V_73 * V_74 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
int V_69 = 0 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_74 -> V_143 || V_74 -> V_141 ) ;
if ( V_74 -> V_146 ) {
V_69 = F_91 ( V_74 , V_74 -> V_146 ) ;
if ( V_69 )
return V_69 ;
}
switch ( F_82 ( V_74 -> V_89 . V_34 ) ) {
case V_138 :
case V_147 :
case V_139 :
F_2 ( V_59 -> V_97 -> V_148 ) ;
V_69 = V_59 -> V_97 -> V_148 ( V_59 , V_74 ) ;
break;
case V_140 :
F_2 ( V_59 -> V_97 -> V_149 ) ;
V_69 = V_59 -> V_97 -> V_149 ( V_59 , V_74 ) ;
break;
default:
F_92 () ;
}
if ( V_69 == 0 ) {
F_2 ( V_74 -> V_150 ) ;
F_2 ( V_74 -> V_150 % 8 == 0 ) ;
F_2 ( V_74 -> V_150 <= V_74 -> V_144 ) ;
}
return V_69 ;
}
static int F_93 ( struct V_73 * V_74 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
int V_69 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_74 -> V_151 ) ;
F_2 ( V_74 -> V_152 ) ;
F_2 ( ! V_74 -> V_153 ) ;
V_74 -> V_154 = 0 ;
V_69 = F_94 ( V_74 -> V_152 , V_74 -> V_155 ) ;
switch ( V_69 ) {
case 1 :
F_95 ( V_74 , V_156 ) ;
case 0 :
break;
default:
F_8 ( L_31 , V_74 -> V_157 ) ;
return - V_158 ;
}
if ( V_74 -> V_155 < sizeof( struct V_159 ) ) {
F_8 ( L_32 ,
V_74 -> V_155 ) ;
return - V_158 ;
}
if ( F_12 ( V_74 -> V_152 -> V_160 ) !=
F_12 ( V_74 -> V_89 . V_34 ) ) {
F_8 ( L_33 ,
F_12 ( V_74 -> V_152 -> V_160 ) ,
F_12 ( V_74 -> V_89 . V_34 ) ) ;
return - V_158 ;
}
switch ( F_82 ( V_74 -> V_89 . V_34 ) ) {
case V_138 :
case V_147 :
case V_139 :
F_2 ( V_59 -> V_97 -> V_161 ) ;
V_69 = V_59 -> V_97 -> V_161 ( V_59 , V_74 ) ;
break;
case V_140 :
F_2 ( V_59 -> V_97 -> V_162 ) ;
V_69 = V_59 -> V_97 -> V_162 ( V_59 , V_74 ) ;
break;
default:
F_92 () ;
}
F_2 ( V_69 || V_74 -> V_153 || V_74 -> V_121 ) ;
if ( F_12 ( V_74 -> V_89 . V_34 ) != V_163 &&
! V_74 -> V_104 )
V_74 -> V_154 = 0 ;
return V_69 ;
}
int F_96 ( struct V_73 * V_74 )
{
F_2 ( V_74 -> V_151 ) ;
F_2 ( ! V_74 -> V_152 ) ;
F_2 ( ! V_74 -> V_153 ) ;
F_2 ( V_74 -> V_164 + V_74 -> V_165 <= V_74 -> V_166 ) ;
if ( V_74 -> V_164 == 0 &&
( F_97 ( V_74 -> V_85 ) & V_167 ) ) {
F_8 ( L_34 ) ;
return - V_158 ;
}
if ( V_74 -> V_164 % 8 != 0 ) {
F_8 ( L_35 , V_74 -> V_164 ) ;
return - V_158 ;
}
V_74 -> V_152 = (struct V_159 * )
( V_74 -> V_151 + V_74 -> V_164 ) ;
V_74 -> V_155 = V_74 -> V_165 ;
return F_93 ( V_74 ) ;
}
int F_98 ( struct V_73 * V_74 ,
struct V_73 * * V_168 )
{
struct V_73 * V_169 ;
char * V_170 ;
int V_171 , V_172 ;
int V_69 ;
V_169 = F_87 ( V_90 ) ;
if ( ! V_169 )
return - V_77 ;
F_88 ( V_169 ) ;
V_172 = V_74 -> V_165 ;
V_171 = F_99 ( V_172 ) ;
V_170 = F_55 ( V_171 , V_90 ) ;
if ( ! V_170 ) {
V_69 = - V_77 ;
goto V_173;
}
F_41 ( & V_74 -> V_99 ) ;
if ( V_74 -> V_174 ) {
F_43 ( & V_74 -> V_99 ) ;
V_69 = - V_12 ;
goto V_175;
}
F_2 ( V_74 -> V_151 ) ;
F_2 ( ! V_74 -> V_152 ) ;
F_2 ( ! V_74 -> V_153 ) ;
if ( V_74 -> V_164 != 0 ) {
F_8 ( L_36 , V_74 -> V_164 ) ;
F_43 ( & V_74 -> V_99 ) ;
V_69 = - V_158 ;
goto V_175;
}
if ( V_74 -> V_165 != V_172 ) {
F_8 ( L_37 ,
V_172 , V_74 -> V_165 ) ;
F_43 ( & V_74 -> V_99 ) ;
V_69 = - V_9 ;
goto V_175;
}
if ( V_74 -> V_165 < sizeof( struct V_159 ) ) {
F_8 ( L_38 ,
V_74 -> V_165 ) ;
F_43 ( & V_74 -> V_99 ) ;
V_69 = - V_12 ;
goto V_175;
}
memcpy ( V_170 , V_74 -> V_151 , V_172 ) ;
F_43 ( & V_74 -> V_99 ) ;
V_169 -> V_76 = F_35 ( V_74 -> V_76 ) ;
V_169 -> V_89 = V_74 -> V_89 ;
V_169 -> V_151 = V_170 ;
V_169 -> V_166 = V_171 ;
V_169 -> V_152 = (struct V_159 * ) V_170 ;
V_169 -> V_155 = V_172 ;
V_169 -> V_176 = 1 ;
V_169 -> V_85 = V_74 -> V_85 ;
V_69 = F_93 ( V_169 ) ;
if ( V_69 ) {
F_100 ( V_177 , V_169 ,
L_39 , V_69 ) ;
goto V_178;
}
F_2 ( V_169 -> V_153 ) ;
* V_168 = V_169 ;
return 0 ;
V_178:
F_37 ( V_169 -> V_76 , 1 ) ;
V_175:
F_61 ( V_170 ) ;
V_173:
F_89 ( V_169 ) ;
return V_69 ;
}
void F_101 ( struct V_73 * V_169 )
{
F_2 ( V_169 -> V_151 ) ;
F_2 ( V_169 -> V_152 ) ;
F_2 ( V_169 -> V_153 ) ;
F_37 ( V_169 -> V_76 , 1 ) ;
F_61 ( V_169 -> V_151 ) ;
F_89 ( V_169 ) ;
}
int F_102 ( void )
{
return F_103 ( & V_179 ) ;
}
static int F_104 ( struct V_46 * V_47 , T_4 V_180 ,
int V_181 , int V_182 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_6 -> V_183 ) ;
return V_2 -> V_6 -> V_183 ( V_47 , V_180 , V_181 , V_182 ) ;
}
static void F_105 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_52 ;
F_106 ( & V_47 -> V_184 ) ;
F_106 ( & V_47 -> V_185 ) ;
F_2 ( V_2 -> V_6 -> V_186 ) ;
F_6 ( V_13 , L_40 , V_47 -> V_52 -> V_5 , V_47 ) ;
V_2 -> V_6 -> V_186 ( V_47 ) ;
F_107 ( V_2 ) ;
}
static void F_108 ( struct V_46 * V_47 )
{
F_38 ( & V_47 -> V_184 ) ;
if ( V_47 -> V_52 -> V_6 -> V_187 ) {
V_47 -> V_52 -> V_6 -> V_187 ( V_47 ) ;
F_104 ( V_47 , - 1 , 1 , 1 ) ;
}
}
static struct V_46 * F_109 ( struct V_46 * V_47 )
{
if ( V_47 )
F_36 ( & V_47 -> V_184 ) ;
return V_47 ;
}
void F_48 ( struct V_46 * V_47 )
{
if ( V_47 ) {
F_38 ( & V_47 -> V_184 ) ;
if ( F_39 ( & V_47 -> V_184 ) ) {
F_110 ( V_47 ) ;
F_105 ( V_47 ) ;
}
}
}
static
struct V_46 * F_111 ( struct V_64 * V_65 ,
struct V_188 * V_189 ,
struct V_30 * V_31 ,
enum V_190 V_191 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
char V_192 [ 32 ] ;
if ( V_189 ) {
F_2 ( V_65 -> V_193 == 1 ) ;
F_6 ( V_13 , L_41 ,
V_65 -> V_194 -> V_195 -> V_196 ,
V_65 -> V_194 -> V_197 ,
F_26 ( V_31 , V_192 , sizeof( V_192 ) ) ) ;
V_2 = F_112 ( V_189 -> V_198 ) ;
V_31 -> V_55 |= V_41 | V_42 ;
} else {
F_2 ( V_65 -> V_193 == 0 ) ;
F_6 ( V_13 , L_42 ,
V_65 -> V_194 -> V_195 -> V_196 ,
V_65 -> V_194 -> V_197 ,
F_26 ( V_31 , V_192 , sizeof( V_192 ) ) ) ;
V_2 = F_9 ( V_31 -> V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_43 , V_31 -> V_34 ) ;
return NULL ;
}
}
V_47 = V_2 -> V_6 -> V_199 ( V_65 , V_189 , V_31 ) ;
if ( V_47 ) {
F_36 ( & V_47 -> V_184 ) ;
V_47 -> V_200 = V_191 ;
if ( V_47 -> V_201 && V_2 -> V_6 -> V_202 )
F_113 ( V_47 ) ;
} else {
F_107 ( V_2 ) ;
}
return V_47 ;
}
struct V_46 * F_46 ( struct V_64 * V_65 )
{
struct V_46 * V_47 ;
F_41 ( & V_65 -> V_67 ) ;
V_47 = F_109 ( V_65 -> V_203 ) ;
F_43 ( & V_65 -> V_67 ) ;
return V_47 ;
}
static void F_114 ( struct V_64 * V_65 ,
struct V_46 * V_47 )
{
struct V_46 * V_204 ;
F_38 ( & V_47 -> V_184 ) ;
F_41 ( & V_65 -> V_67 ) ;
V_204 = V_65 -> V_203 ;
V_65 -> V_203 = V_47 ;
F_43 ( & V_65 -> V_67 ) ;
if ( V_204 ) {
F_108 ( V_204 ) ;
F_48 ( V_204 ) ;
}
}
static inline
int F_115 ( struct V_30 * V_205 , struct V_30 * V_206 )
{
return ( memcmp ( V_205 , V_206 , sizeof( * V_205 ) ) == 0 ) ;
}
static inline
void F_116 ( struct V_30 * V_207 , struct V_30 * V_208 )
{
* V_207 = * V_208 ;
}
static void F_117 ( struct V_64 * V_65 ,
struct V_46 * V_47 ,
struct V_30 * V_31 )
{
char V_209 [ 32 ] , V_210 [ 32 ] ;
if ( V_47 -> V_54 . V_55 != V_31 -> V_55 )
F_6 ( V_13 , L_44 ,
F_29 ( V_47 -> V_54 . V_55 ,
V_209 , sizeof( V_209 ) ) ,
F_29 ( V_31 -> V_55 ,
V_210 , sizeof( V_210 ) ) ) ;
F_41 ( & V_47 -> V_137 ) ;
F_116 ( & V_47 -> V_54 , V_31 ) ;
F_43 ( & V_47 -> V_137 ) ;
}
int F_44 ( struct V_64 * V_65 ,
struct V_188 * V_189 ,
struct V_30 * V_28 )
{
struct V_211 * V_212 ;
struct V_30 V_31 ;
struct V_46 * V_47 , * V_213 ;
enum V_190 V_191 ;
char V_192 [ 24 ] ;
int V_69 = 0 ;
F_85 () ;
if ( ! V_65 )
return 0 ;
V_212 = V_65 -> V_214 ;
if ( ! V_189 ) {
struct V_215 * V_216 = & V_65 -> V_194 -> V_217 . V_218 ;
if ( V_216 -> V_219 == V_220 )
V_31 = V_216 -> V_221 ;
else
F_118 ( V_216 -> V_219 ,
V_216 -> V_222 ,
& V_216 -> V_223 ,
V_212 -> V_224 , & V_31 ) ;
V_191 = V_65 -> V_194 -> V_217 . V_218 . V_219 ;
} else {
V_31 = * V_28 ;
if ( V_31 . V_34 != V_21 )
V_31 . V_55 = V_41 |
V_42 ;
V_191 = F_119 ( V_65 -> V_194 ) ;
}
V_47 = F_46 ( V_65 ) ;
if ( V_47 ) {
char V_210 [ 24 ] ;
if ( F_115 ( & V_31 , & V_47 -> V_54 ) )
goto V_225;
F_6 ( V_13 , L_45 ,
V_65 -> V_194 -> V_197 ,
F_120 ( & V_212 -> V_226 ) ,
F_26 ( & V_47 -> V_54 , V_192 , sizeof( V_192 ) ) ,
F_26 ( & V_31 , V_210 , sizeof( V_210 ) ) ) ;
if ( F_12 ( V_31 . V_34 ) ==
F_12 ( V_47 -> V_54 . V_34 ) &&
F_121 ( V_31 . V_34 ) ==
F_121 ( V_47 -> V_54 . V_34 ) ) {
F_117 ( V_65 , V_47 , & V_31 ) ;
goto V_225;
}
} else if ( F_23 ( V_31 . V_34 ) !=
F_23 ( V_21 ) ) {
F_6 ( V_13 , L_46 ,
V_65 -> V_194 -> V_197 ,
F_120 ( & V_212 -> V_226 ) ,
F_122 ( V_212 -> V_224 ) ,
F_26 ( & V_31 , V_192 , sizeof( V_192 ) ) ) ;
}
F_17 ( & V_65 -> V_227 ) ;
V_213 = F_111 ( V_65 , V_189 , & V_31 , V_191 ) ;
if ( V_213 ) {
F_114 ( V_65 , V_213 ) ;
} else {
F_8 ( L_47 ,
V_65 -> V_194 -> V_197 ,
F_120 ( & V_212 -> V_226 ) ) ;
V_69 = - V_112 ;
}
F_20 ( & V_65 -> V_227 ) ;
V_225:
F_48 ( V_47 ) ;
return V_69 ;
}
void F_123 ( struct V_64 * V_65 )
{
if ( V_65 -> V_203 ) {
F_108 ( V_65 -> V_203 ) ;
F_48 ( V_65 -> V_203 ) ;
V_65 -> V_203 = NULL ;
}
}
static void F_124 ( struct V_64 * V_65 ,
T_4 V_180 , int V_181 , int V_182 )
{
struct V_46 * V_47 ;
if ( ! V_65 )
return;
V_47 = F_46 ( V_65 ) ;
if ( ! V_47 )
return;
F_104 ( V_47 , V_180 , V_181 , V_182 ) ;
F_48 ( V_47 ) ;
}
void F_125 ( struct V_64 * V_65 )
{
F_124 ( V_65 , F_31 ( & V_58 , F_32 () ) ,
1 , 1 ) ;
}
void F_126 ( struct V_64 * V_65 )
{
F_124 ( V_65 , - 1 , 1 , 1 ) ;
}
int F_59 ( struct V_73 * V_74 , int V_228 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_1 * V_2 ;
int V_69 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_2 ( ! V_74 -> V_85 ) ;
F_38 ( & V_59 -> V_60 ) ;
V_2 = V_59 -> V_62 -> V_52 ;
V_69 = V_2 -> V_6 -> V_229 ( V_59 -> V_62 , V_74 , V_228 ) ;
if ( ! V_69 ) {
F_2 ( V_74 -> V_85 ) ;
F_2 ( V_74 -> V_143 || V_74 -> V_141 ) ;
if ( V_74 -> V_142 )
memset ( V_74 -> V_85 , 0 , V_228 ) ;
}
return V_69 ;
}
void F_56 ( struct V_73 * V_74 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_38 ( & V_59 -> V_60 ) ;
if ( ! V_74 -> V_143 && ! V_74 -> V_141 )
return;
V_2 = V_59 -> V_62 -> V_52 ;
V_2 -> V_6 -> V_230 ( V_59 -> V_62 , V_74 ) ;
V_74 -> V_85 = NULL ;
}
void F_127 ( struct V_159 * V_231 ,
int V_232 , int V_233 )
{
void * V_208 , * V_207 ;
int V_234 , V_235 , V_236 ;
F_2 ( V_232 < V_231 -> V_237 ) ;
F_2 ( V_231 -> V_238 [ V_232 ] <= V_233 ) ;
if ( V_231 -> V_238 [ V_232 ] == V_233 )
return;
if ( V_232 == V_231 -> V_237 - 1 ) {
V_231 -> V_238 [ V_232 ] = V_233 ;
return;
}
V_234 = V_231 -> V_238 [ V_232 ] ;
V_208 = F_128 ( V_231 , V_232 + 1 , 0 ) ;
V_231 -> V_238 [ V_232 ] = V_233 ;
V_207 = F_128 ( V_231 , V_232 + 1 , 0 ) ;
V_231 -> V_238 [ V_232 ] = V_234 ;
F_2 ( V_231 -> V_239 == V_240 ) ;
V_235 = F_129 ( V_231 -> V_237 , V_231 -> V_238 ) ;
V_236 = V_235 - ( ( unsigned long ) V_208 - ( unsigned long ) V_231 ) ;
F_2 ( V_236 >= 0 ) ;
if ( V_236 )
memmove ( V_207 , V_208 , V_236 ) ;
V_231 -> V_238 [ V_232 ] = V_233 ;
}
int F_130 ( struct V_73 * V_74 ,
int V_232 , int V_233 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_241 * V_242 ;
struct V_159 * V_231 = V_74 -> V_85 ;
F_2 ( V_59 ) ;
F_2 ( V_231 ) ;
F_2 ( V_231 -> V_237 > V_232 ) ;
F_2 ( V_231 -> V_238 [ V_232 ] <= V_233 ) ;
if ( V_231 -> V_238 [ V_232 ] == V_233 )
return 0 ;
V_242 = V_59 -> V_62 -> V_52 -> V_6 ;
F_2 ( V_242 -> V_243 ) ;
return V_242 -> V_243 ( V_59 -> V_62 , V_74 , V_232 , V_233 ) ;
}
int F_131 ( struct V_73 * V_74 , int V_228 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
if ( V_74 -> V_151 )
return 0 ;
V_2 = V_59 -> V_62 -> V_52 ;
return V_2 -> V_6 -> V_244 ( V_59 -> V_62 , V_74 , V_228 ) ;
}
void F_57 ( struct V_73 * V_74 )
{
struct V_45 * V_59 = V_74 -> V_76 ;
struct V_1 * V_2 ;
F_2 ( V_59 ) ;
F_2 ( V_59 -> V_62 ) ;
F_2 ( V_59 -> V_62 -> V_52 ) ;
F_38 ( & V_59 -> V_60 ) ;
if ( ! V_74 -> V_151 )
return;
F_2 ( V_74 -> V_166 ) ;
V_2 = V_59 -> V_62 -> V_52 ;
V_2 -> V_6 -> V_245 ( V_59 -> V_62 , V_74 ) ;
V_74 -> V_153 = NULL ;
}
static int F_132 ( struct V_64 * V_65 ,
struct V_188 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_198 ;
if ( ! V_2 -> V_7 -> V_246 )
return 0 ;
return V_2 -> V_7 -> V_246 ( V_65 , V_59 ) ;
}
static int F_133 ( struct V_30 * exp ,
struct V_73 * V_74 )
{
struct V_30 * V_28 = & V_74 -> V_89 ;
if ( exp -> V_34 == V_247 || exp -> V_34 == V_28 -> V_34 )
return 1 ;
if ( ( V_74 -> V_104 || V_74 -> V_105 ) &&
F_12 ( exp -> V_34 ) ==
F_12 ( V_28 -> V_34 ) &&
F_121 ( exp -> V_34 ) == F_121 ( V_28 -> V_34 ) )
return 1 ;
return 0 ;
}
int F_134 ( struct V_248 * exp ,
struct V_73 * V_74 )
{
struct V_30 V_14 ;
if ( ! exp )
return 0 ;
if ( ! exp -> V_249 )
return 0 ;
if ( V_74 -> V_105 )
return 0 ;
F_41 ( & exp -> V_250 ) ;
if ( F_4 ( exp -> V_251 ) &&
F_133 ( & exp -> V_252 [ 1 ] , V_74 ) ) {
F_6 ( V_13 , L_48 , exp ,
exp -> V_253 . V_34 , exp -> V_252 [ 1 ] . V_34 ) ;
V_14 = exp -> V_252 [ 1 ] ;
exp -> V_252 [ 1 ] = exp -> V_252 [ 0 ] ;
exp -> V_254 [ 1 ] = exp -> V_254 [ 0 ] ;
exp -> V_252 [ 0 ] = exp -> V_253 ;
exp -> V_254 [ 0 ] = F_42 () +
V_255 ;
exp -> V_253 = V_14 ;
exp -> V_251 = 0 ;
F_2 ( exp -> V_256 == 1 ) ;
if ( V_74 -> V_257 &&
! ( V_74 -> V_104 &&
( V_74 -> V_258 || V_74 -> V_259 ||
V_74 -> V_260 ) ) ) {
F_43 ( & exp -> V_250 ) ;
F_6 ( V_13 , L_49 ,
V_74 -> V_257 , V_74 -> V_104 ,
V_74 -> V_258 , V_74 -> V_259 ,
V_74 -> V_260 ) ;
return 0 ;
}
exp -> V_256 = 0 ;
F_43 ( & exp -> V_250 ) ;
return F_44 ( exp -> V_249 ,
V_74 -> V_261 , & V_14 ) ;
}
if ( F_135 ( F_133 ( & exp -> V_253 , V_74 ) ) ) {
if ( ! V_74 -> V_257 || ! V_74 -> V_104 ||
( ! V_74 -> V_258 && ! V_74 -> V_259 &&
! V_74 -> V_260 ) ) {
F_43 ( & exp -> V_250 ) ;
return 0 ;
}
if ( exp -> V_251 ) {
F_2 ( exp -> V_256 ) ;
F_43 ( & exp -> V_250 ) ;
return 0 ;
}
if ( exp -> V_256 ) {
exp -> V_256 = 0 ;
F_6 ( V_13 , L_50 ,
exp , exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 ,
exp -> V_252 [ 1 ] . V_34 ) ;
V_14 = exp -> V_253 ;
F_43 ( & exp -> V_250 ) ;
return F_44 ( exp -> V_249 ,
V_74 -> V_261 ,
& V_14 ) ;
} else {
F_6 ( V_13 , L_51 ,
exp , exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 ,
exp -> V_252 [ 1 ] . V_34 ) ;
F_43 ( & exp -> V_250 ) ;
return F_132 ( exp -> V_249 ,
V_74 -> V_261 ) ;
}
}
if ( exp -> V_254 [ 0 ] ) {
if ( exp -> V_254 [ 0 ] >= F_42 () ) {
if ( F_133 ( & exp -> V_252 [ 0 ] , V_74 ) ) {
F_6 ( V_13 , L_52 , exp ,
exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 ,
exp -> V_252 [ 1 ] . V_34 ,
( V_262 ) ( exp -> V_254 [ 0 ] -
F_42 () ) ) ;
F_43 ( & exp -> V_250 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_53 ) ;
exp -> V_254 [ 0 ] = 0 ;
}
F_6 ( V_13 , L_54 , exp ,
exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 , exp -> V_252 [ 1 ] . V_34 ,
V_74 -> V_89 . V_34 ) ;
}
if ( exp -> V_251 == 0 && exp -> V_254 [ 1 ] ) {
if ( exp -> V_254 [ 1 ] >= F_42 () ) {
if ( F_133 ( & exp -> V_252 [ 1 ] , V_74 ) ) {
F_6 ( V_13 , L_55 ,
exp ,
exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 ,
exp -> V_252 [ 1 ] . V_34 ,
( V_262 ) ( exp -> V_254 [ 1 ] -
F_42 () ) ) ;
F_43 ( & exp -> V_250 ) ;
return 0 ;
}
} else {
F_6 ( V_13 , L_56 ) ;
exp -> V_254 [ 1 ] = 0 ;
}
F_6 ( V_13 , L_57 ,
exp , exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 , exp -> V_252 [ 1 ] . V_34 ,
V_74 -> V_89 . V_34 ) ;
} else {
F_6 ( V_13 , L_58 ,
exp , exp -> V_253 . V_34 , exp -> V_252 [ 0 ] . V_34 ,
exp -> V_252 [ 1 ] . V_34 ) ;
}
F_43 ( & exp -> V_250 ) ;
F_60 ( L_59 ,
exp , exp -> V_263 -> V_197 ,
V_74 , V_74 -> V_257 , V_74 -> V_104 , V_74 -> V_105 ,
V_74 -> V_258 , V_74 -> V_259 , V_74 -> V_260 ,
V_74 -> V_89 . V_34 ,
exp -> V_253 . V_34 ,
exp -> V_252 [ 0 ] . V_34 ,
exp -> V_254 [ 0 ] ?
( V_262 ) ( exp -> V_254 [ 0 ] - F_42 () ) : 0 ,
exp -> V_252 [ 1 ] . V_34 ,
exp -> V_254 [ 1 ] ?
( V_262 ) ( exp -> V_254 [ 1 ] - F_42 () ) : 0 ) ;
return - V_71 ;
}
static int F_136 ( struct V_73 * V_74 , int V_264 )
{
if ( ! V_74 -> V_257 || V_264 == V_265 )
return V_264 ;
switch ( V_74 -> V_266 ) {
case V_267 :
if ( V_74 -> V_259 || V_74 -> V_260 ) {
F_100 ( V_268 , V_74 , L_60 ) ;
V_264 = V_265 ;
}
break;
case V_269 :
if ( ! V_74 -> V_259 ) {
F_100 ( V_268 , V_74 , L_61 ) ;
V_264 = V_265 ;
}
break;
case V_270 :
if ( ! V_74 -> V_260 ) {
F_100 ( V_268 , V_74 , L_62 ) ;
V_264 = V_265 ;
}
break;
case V_271 :
case V_220 :
if ( ! V_74 -> V_258 && ! V_74 -> V_259 &&
! V_74 -> V_260 ) {
F_100 ( V_268 , V_74 , L_63 ) ;
V_264 = V_265 ;
}
break;
case V_272 :
default:
F_100 ( V_268 , V_74 , L_64 , V_74 -> V_266 ) ;
V_264 = V_265 ;
}
return V_264 ;
}
int F_137 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_159 * V_231 = V_74 -> V_143 ;
int V_69 ;
F_2 ( V_231 ) ;
F_2 ( ! V_74 -> V_85 ) ;
F_2 ( ! V_74 -> V_153 ) ;
F_2 ( ! V_74 -> V_261 ) ;
V_74 -> V_273 = 0 ;
V_69 = F_94 ( V_231 , V_74 -> V_150 ) ;
switch ( V_69 ) {
case 1 :
F_138 ( V_74 , V_156 ) ;
case 0 :
break;
default:
F_8 ( L_65 ,
F_139 ( V_74 -> V_274 ) , V_74 -> V_157 ) ;
return V_265 ;
}
V_74 -> V_89 . V_34 = F_140 ( V_231 -> V_160 ) ;
V_74 -> V_266 = V_272 ;
V_74 -> V_275 = - 1 ;
V_74 -> V_276 = - 1 ;
V_2 = F_9 ( V_74 -> V_89 . V_34 ) ;
if ( ! V_2 ) {
F_8 ( L_66 , V_74 -> V_89 . V_34 ) ;
return V_265 ;
}
F_2 ( V_2 -> V_7 -> V_277 ) ;
V_69 = V_2 -> V_7 -> V_277 ( V_74 ) ;
F_107 ( V_2 ) ;
F_2 ( V_74 -> V_85 || V_69 != V_278 ) ;
F_2 ( V_74 -> V_261 || V_69 == V_265 ) ;
if ( F_12 ( V_74 -> V_89 . V_34 ) != V_163 )
V_74 -> V_273 = 0 ;
V_69 = F_136 ( V_74 , V_69 ) ;
return V_69 ;
}
int F_141 ( struct V_73 * V_74 , int V_279 )
{
struct V_1 * V_2 ;
struct V_280 * V_281 ;
int V_69 ;
F_2 ( V_74 -> V_261 ) ;
F_2 ( V_74 -> V_261 -> V_198 ) ;
V_2 = V_74 -> V_261 -> V_198 ;
F_2 ( V_2 -> V_7 -> V_282 ) ;
V_69 = V_2 -> V_7 -> V_282 ( V_74 , V_279 ) ;
if ( F_4 ( V_69 == - V_77 ) ) {
struct V_283 * V_284 = V_74 -> V_285 -> V_286 ;
if ( V_284 -> V_287 -> V_288 <
V_279 + sizeof( struct V_280 ) ) {
F_8 ( L_67 ,
V_279 + sizeof( struct V_280 ) ,
V_284 -> V_287 -> V_288 ) ;
return - V_77 ;
}
V_281 = F_142 ( V_284 ) ;
if ( ! V_281 )
return - V_77 ;
V_74 -> V_289 = V_281 ;
V_69 = V_2 -> V_7 -> V_282 ( V_74 , V_279 ) ;
if ( V_69 ) {
F_143 ( V_281 ) ;
V_74 -> V_289 = NULL ;
}
}
F_2 ( V_69 != 0 ||
( V_74 -> V_289 && V_74 -> V_289 -> V_290 ) ) ;
return V_69 ;
}
int F_144 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
int V_69 ;
F_2 ( V_74 -> V_261 ) ;
F_2 ( V_74 -> V_261 -> V_198 ) ;
V_2 = V_74 -> V_261 -> V_198 ;
F_2 ( V_2 -> V_7 -> V_291 ) ;
V_69 = V_2 -> V_7 -> V_291 ( V_74 ) ;
F_2 ( V_69 || V_74 -> V_289 -> V_292 ) ;
return V_69 ;
}
void F_145 ( struct V_280 * V_281 )
{
struct V_1 * V_2 ;
unsigned int V_293 ;
F_2 ( V_281 -> V_294 ) ;
F_2 ( V_281 -> V_294 -> V_198 ) ;
V_2 = V_281 -> V_294 -> V_198 ;
F_2 ( V_2 -> V_7 -> V_295 ) ;
V_293 = V_281 -> V_296 ;
V_2 -> V_7 -> V_295 ( V_281 ) ;
if ( V_293 )
F_143 ( V_281 ) ;
}
void F_146 ( struct V_73 * V_74 )
{
struct V_188 * V_59 = V_74 -> V_261 ;
if ( V_59 )
F_36 ( & V_59 -> V_297 ) ;
}
void F_147 ( struct V_73 * V_74 )
{
struct V_188 * V_59 = V_74 -> V_261 ;
if ( ! V_59 )
return;
F_38 ( & V_59 -> V_297 ) ;
if ( F_39 ( & V_59 -> V_297 ) ) {
if ( V_59 -> V_198 -> V_7 -> V_298 )
V_59 -> V_198 -> V_7 -> V_298 ( V_59 ) ;
}
V_74 -> V_261 = NULL ;
}
int F_91 ( struct V_73 * V_74 ,
struct V_299 * V_300 )
{
struct V_45 * V_59 ;
F_2 ( V_74 -> V_125 || V_74 -> V_126 ) ;
if ( ! V_74 -> V_136 )
return 0 ;
V_59 = V_74 -> V_76 ;
if ( V_59 -> V_97 -> V_301 )
return V_59 -> V_97 -> V_301 ( V_59 , V_74 , V_300 ) ;
return 0 ;
}
int F_148 ( struct V_73 * V_74 ,
struct V_299 * V_300 ,
int V_302 )
{
struct V_45 * V_59 ;
int V_69 ;
F_2 ( V_74 -> V_125 && ! V_74 -> V_126 ) ;
if ( ! V_74 -> V_136 )
return V_300 -> V_303 ;
V_59 = V_74 -> V_76 ;
if ( V_59 -> V_97 -> V_304 ) {
V_69 = V_59 -> V_97 -> V_304 ( V_59 , V_74 , V_300 ) ;
if ( V_69 < 0 )
return V_69 ;
}
return V_300 -> V_303 ;
}
int F_149 ( struct V_73 * V_74 ,
struct V_299 * V_300 )
{
struct V_45 * V_59 ;
int V_69 ;
F_2 ( ! V_74 -> V_125 && V_74 -> V_126 ) ;
if ( ! V_74 -> V_136 )
return 0 ;
V_59 = V_74 -> V_76 ;
if ( V_59 -> V_97 -> V_304 ) {
V_69 = V_59 -> V_97 -> V_304 ( V_59 , V_74 , V_300 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( V_300 -> V_305 != V_300 -> V_303 ) {
F_8 ( L_68 ,
V_300 -> V_305 , V_300 -> V_303 ) ;
return - V_158 ;
}
return 0 ;
}
int F_150 ( void )
{
int V_306 ;
V_306 = V_307 ;
if ( V_306 > V_308 )
V_306 = V_308 ;
return F_151 ( V_306 ) ;
}
int F_152 ( struct V_159 * V_231 , int V_309 )
{
struct V_310 * V_311 ;
V_311 = F_128 ( V_231 , V_309 , 0 ) ;
if ( ! V_311 )
return - V_9 ;
V_311 -> V_312 = F_31 ( & V_58 , F_32 () ) ;
V_311 -> V_313 = F_33 ( & V_58 , F_34 () ) ;
V_311 -> V_314 = F_31 ( & V_58 , F_153 () ) ;
V_311 -> V_315 = F_33 ( & V_58 , F_154 () ) ;
V_311 -> V_316 = F_155 () ;
V_311 -> V_317 = ( V_231 -> V_238 [ V_309 ] - sizeof( * V_311 ) ) / 4 ;
F_156 ( V_318 ) ;
if ( V_311 -> V_317 > V_307 )
V_311 -> V_317 = V_307 ;
memcpy ( V_311 -> V_319 , F_157 () -> V_320 -> V_321 [ 0 ] ,
V_311 -> V_317 * sizeof( T_2 ) ) ;
F_158 ( V_318 ) ;
return 0 ;
}
int F_159 ( struct V_159 * V_231 , int V_309 , int V_322 )
{
struct V_310 * V_311 ;
int V_323 ;
V_311 = F_128 ( V_231 , V_309 , sizeof( * V_311 ) ) ;
if ( ! V_311 )
return - V_9 ;
if ( V_322 ) {
F_160 ( & V_311 -> V_312 ) ;
F_160 ( & V_311 -> V_313 ) ;
F_160 ( & V_311 -> V_314 ) ;
F_160 ( & V_311 -> V_315 ) ;
F_160 ( & V_311 -> V_316 ) ;
F_160 ( & V_311 -> V_317 ) ;
}
if ( V_311 -> V_317 > V_308 ) {
F_8 ( L_69 , V_311 -> V_317 ) ;
return - V_9 ;
}
if ( sizeof( * V_311 ) + V_311 -> V_317 * sizeof( T_2 ) >
V_231 -> V_238 [ V_309 ] ) {
F_8 ( L_70 ,
V_311 -> V_317 , V_231 -> V_238 [ V_309 ] ) ;
return - V_9 ;
}
if ( V_322 ) {
for ( V_323 = 0 ; V_323 < V_311 -> V_317 ; V_323 ++ )
F_160 ( & V_311 -> V_319 [ V_323 ] ) ;
}
return 0 ;
}
const char * F_54 ( struct V_46 * V_47 )
{
if ( ! V_47 || ! V_47 -> V_324 || ! V_47 -> V_324 -> V_194 )
return L_71 ;
if ( F_161 ( V_47 ) )
return L_72 ;
return F_120 ( & V_47 -> V_324 -> V_194 -> V_217 . V_218 . V_223 ) ;
}
bool F_80 ( struct V_30 * V_28 )
{
switch ( F_162 ( V_28 -> V_34 ) ) {
case V_325 :
case V_326 :
return true ;
default:
return false ;
}
}
int F_163 ( void )
{
int V_69 ;
F_164 ( & V_10 ) ;
V_69 = F_165 () ;
if ( V_69 )
goto V_225;
V_69 = F_166 () ;
if ( V_69 )
goto V_327;
V_69 = F_167 () ;
if ( V_69 )
goto V_328;
V_69 = F_168 () ;
if ( V_69 )
goto V_329;
V_69 = F_169 () ;
if ( V_69 )
goto V_330;
V_69 = F_170 () ;
if ( V_69 )
goto V_331;
return 0 ;
V_331:
F_171 () ;
V_330:
F_172 () ;
V_329:
F_173 () ;
V_328:
F_174 () ;
V_327:
F_175 () ;
V_225:
return V_69 ;
}
void F_176 ( void )
{
F_177 () ;
F_171 () ;
F_172 () ;
F_173 () ;
F_174 () ;
F_175 () ;
}
