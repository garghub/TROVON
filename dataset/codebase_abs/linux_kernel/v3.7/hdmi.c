static int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
V_1 = F_3 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 ) ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
static void F_5 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
V_1 = F_6 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 && V_1 != - V_5 ) ;
}
static int T_1 F_7 ( struct V_6 * V_7 )
{
int V_1 ;
struct V_8 V_9 [] = {
{ V_2 . V_10 , V_11 , L_3 } ,
{ V_2 . V_12 , V_11 , L_4 } ,
{ V_2 . V_13 , V_14 , L_5 } ,
} ;
F_2 ( L_6 ) ;
F_8 ( & V_2 . V_15 ) ;
if ( V_2 . V_16 == NULL ) {
struct V_17 * V_18 ;
V_18 = F_9 ( & V_2 . V_3 -> V_4 , L_7 ) ;
if ( F_10 ( V_18 ) ) {
F_11 ( L_8 ) ;
return F_12 ( V_18 ) ;
}
V_2 . V_16 = V_18 ;
}
V_1 = F_13 ( V_9 , F_14 ( V_9 ) ) ;
if ( V_1 )
return V_1 ;
return 0 ;
}
static void T_2 F_15 ( struct V_6 * V_7 )
{
F_2 ( L_9 ) ;
F_16 ( V_2 . V_10 ) ;
F_16 ( V_2 . V_12 ) ;
F_16 ( V_2 . V_13 ) ;
}
static const struct V_19 * F_17 (
const struct V_19 * V_20 ,
int V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
if ( V_20 [ V_22 ] . V_23 . V_24 == V_2 . V_15 . V_25 . V_23 . V_24 )
return & V_20 [ V_22 ] ;
}
return NULL ;
}
static const struct V_19 * F_18 ( void )
{
const struct V_19 * V_26 ;
int V_21 ;
if ( V_2 . V_15 . V_25 . V_23 . V_27 == V_28 ) {
V_26 = V_29 ;
V_21 = F_14 ( V_29 ) ;
} else {
V_26 = V_30 ;
V_21 = F_14 ( V_30 ) ;
}
return F_17 ( V_26 , V_21 ) ;
}
static bool F_19 ( struct V_31 * V_32 ,
const struct V_31 * V_33 )
{
int V_34 , V_35 , V_36 , V_37 ;
if ( ( V_33 -> V_38 == V_32 -> V_38 ) &&
( V_33 -> V_39 == V_32 -> V_39 ) &&
( V_33 -> V_40 == V_32 -> V_40 ) ) {
V_37 = V_33 -> V_41 + V_33 -> V_42 + V_33 -> V_43 ;
V_35 = V_32 -> V_41 + V_32 -> V_42 + V_32 -> V_43 ;
V_36 = V_33 -> V_44 + V_33 -> V_45 + V_33 -> V_46 ;
V_34 = V_33 -> V_44 + V_33 -> V_45 + V_33 -> V_46 ;
F_2 ( L_10\
L_11 ,
V_35 , V_34 ,
V_37 , V_36 ) ;
if ( ( V_35 == V_37 ) &&
( V_34 == V_36 ) ) {
return true ;
}
}
return false ;
}
static struct V_47 F_20 ( struct V_31 * V_48 )
{
int V_22 ;
struct V_47 V_23 = { - 1 } ;
F_2 ( L_12 ) ;
for ( V_22 = 0 ; V_22 < F_14 ( V_30 ) ; V_22 ++ ) {
if ( F_19 ( V_48 , & V_30 [ V_22 ] . V_49 ) ) {
V_23 = V_30 [ V_22 ] . V_23 ;
goto V_50;
}
}
for ( V_22 = 0 ; V_22 < F_14 ( V_29 ) ; V_22 ++ ) {
if ( F_19 ( V_48 , & V_29 [ V_22 ] . V_49 ) ) {
V_23 = V_29 [ V_22 ] . V_23 ;
goto V_50;
}
}
V_50: return V_23 ;
}
unsigned long F_21 ( void )
{
return V_2 . V_15 . V_25 . V_49 . V_38 * 1000 ;
}
static void F_22 ( struct V_6 * V_7 , int V_51 ,
struct V_52 * V_53 )
{
unsigned long V_54 , V_55 ;
T_3 V_56 ;
V_54 = F_23 ( V_2 . V_57 ) / 10000 ;
if ( V_7 -> V_58 . V_2 . V_59 == 0 )
V_53 -> V_59 = V_60 ;
else
V_53 -> V_59 = V_7 -> V_58 . V_2 . V_59 ;
V_55 = V_54 / V_53 -> V_59 ;
if ( V_7 -> V_58 . V_2 . V_61 == 0 )
V_53 -> V_61 = V_62 ;
else
V_53 -> V_61 = V_7 -> V_58 . V_2 . V_61 ;
V_53 -> V_63 = V_51 * V_53 -> V_61 / V_55 ;
V_56 = ( V_51 - V_53 -> V_63 / V_53 -> V_61 * V_55 ) * 262144 ;
V_53 -> V_64 = V_53 -> V_61 * V_56 / V_55 ;
V_53 -> V_65 = V_51 > 1000 * 100 ;
V_53 -> V_66 = ( ( V_53 -> V_63 * V_54 / 10 ) / ( V_53 -> V_59 * 250 ) + 5 ) / 10 ;
V_53 -> V_67 = V_68 ;
F_2 ( L_13 , V_53 -> V_63 , V_53 -> V_64 ) ;
F_2 ( L_14 , V_53 -> V_65 , V_53 -> V_66 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
int V_1 ;
struct V_31 * V_69 ;
struct V_70 * V_71 = V_7 -> V_72 -> V_73 ;
unsigned long V_51 ;
F_25 ( V_2 . V_10 , 1 ) ;
F_25 ( V_2 . V_12 , 1 ) ;
F_26 ( 300 ) ;
V_1 = F_27 ( V_2 . V_16 ) ;
if ( V_1 )
goto V_74;
V_1 = F_1 () ;
if ( V_1 )
goto V_75;
F_28 ( V_71 ) ;
V_69 = & V_2 . V_15 . V_25 . V_49 ;
F_2 ( L_15 , V_69 -> V_39 , V_69 -> V_40 ) ;
V_51 = V_69 -> V_38 ;
F_22 ( V_7 , V_51 , & V_2 . V_15 . V_76 ) ;
V_2 . V_15 . V_77 -> V_78 ( & V_2 . V_15 ) ;
V_1 = V_2 . V_15 . V_77 -> V_79 ( & V_2 . V_15 ) ;
if ( V_1 ) {
F_2 ( L_16 ) ;
goto V_80;
}
V_1 = V_2 . V_15 . V_77 -> V_81 ( & V_2 . V_15 ) ;
if ( V_1 ) {
F_2 ( L_17 ) ;
goto V_82;
}
V_2 . V_15 . V_77 -> V_83 ( & V_2 . V_15 ) ;
F_29 ( V_84 ) ;
F_30 ( V_7 -> V_58 . V_85 . V_86 ) ;
F_31 ( 0 ) ;
F_32 ( V_71 , V_69 ) ;
V_1 = V_2 . V_15 . V_77 -> V_87 ( & V_2 . V_15 ) ;
if ( V_1 )
goto V_88;
V_1 = F_33 ( V_71 ) ;
if ( V_1 )
goto V_89;
return 0 ;
V_89:
V_2 . V_15 . V_77 -> V_78 ( & V_2 . V_15 ) ;
V_88:
V_2 . V_15 . V_77 -> V_90 ( & V_2 . V_15 ) ;
V_82:
V_2 . V_15 . V_77 -> V_91 ( & V_2 . V_15 ) ;
V_80:
F_5 () ;
V_75:
F_34 ( V_2 . V_16 ) ;
V_74:
F_25 ( V_2 . V_10 , 0 ) ;
F_25 ( V_2 . V_12 , 0 ) ;
return - V_92 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_70 * V_71 = V_7 -> V_72 -> V_73 ;
F_28 ( V_71 ) ;
V_2 . V_15 . V_77 -> V_78 ( & V_2 . V_15 ) ;
V_2 . V_15 . V_77 -> V_90 ( & V_2 . V_15 ) ;
V_2 . V_15 . V_77 -> V_91 ( & V_2 . V_15 ) ;
F_5 () ;
F_34 ( V_2 . V_16 ) ;
F_25 ( V_2 . V_10 , 0 ) ;
F_25 ( V_2 . V_12 , 0 ) ;
}
int F_36 ( struct V_6 * V_7 ,
struct V_31 * V_49 )
{
struct V_47 V_23 ;
V_23 = F_20 ( V_49 ) ;
if ( V_23 . V_24 == - 1 ) {
return - V_93 ;
}
return 0 ;
}
void F_37 ( struct V_6 * V_7 ,
struct V_31 * V_49 )
{
struct V_47 V_23 ;
const struct V_19 * V_94 ;
F_38 ( & V_2 . V_95 ) ;
V_23 = F_20 ( V_49 ) ;
V_2 . V_15 . V_25 . V_23 = V_23 ;
V_94 = F_18 () ;
if ( V_94 != NULL )
V_2 . V_15 . V_25 = * V_94 ;
F_39 ( & V_2 . V_95 ) ;
}
static void F_40 ( struct V_96 * V_97 )
{
F_38 ( & V_2 . V_95 ) ;
if ( F_1 () ) {
F_39 ( & V_2 . V_95 ) ;
return;
}
V_2 . V_15 . V_77 -> V_98 ( & V_2 . V_15 , V_97 ) ;
V_2 . V_15 . V_77 -> V_99 ( & V_2 . V_15 , V_97 ) ;
V_2 . V_15 . V_77 -> V_100 ( & V_2 . V_15 , V_97 ) ;
V_2 . V_15 . V_77 -> V_101 ( & V_2 . V_15 , V_97 ) ;
F_5 () ;
F_39 ( & V_2 . V_95 ) ;
}
int F_41 ( T_4 * V_102 , int V_21 )
{
int V_1 ;
F_38 ( & V_2 . V_95 ) ;
V_1 = F_1 () ;
F_42 ( V_1 ) ;
V_1 = V_2 . V_15 . V_77 -> V_103 ( & V_2 . V_15 , V_102 , V_21 ) ;
F_5 () ;
F_39 ( & V_2 . V_95 ) ;
return V_1 ;
}
bool F_43 ( void )
{
int V_1 ;
F_38 ( & V_2 . V_95 ) ;
V_1 = F_1 () ;
F_42 ( V_1 ) ;
V_1 = V_2 . V_15 . V_77 -> V_104 ( & V_2 . V_15 ) ;
F_5 () ;
F_39 ( & V_2 . V_95 ) ;
return V_1 == 1 ;
}
int F_44 ( struct V_6 * V_7 )
{
struct V_105 * V_106 = V_7 -> V_72 ;
int V_1 = 0 ;
F_2 ( L_18 ) ;
F_38 ( & V_2 . V_95 ) ;
if ( V_106 == NULL || V_106 -> V_73 == NULL ) {
F_11 ( L_19 ) ;
V_1 = - V_107 ;
goto V_108;
}
V_2 . V_15 . V_13 = V_2 . V_13 ;
V_1 = F_45 ( V_7 ) ;
if ( V_1 ) {
F_11 ( L_20 ) ;
goto V_108;
}
V_1 = F_24 ( V_7 ) ;
if ( V_1 ) {
F_11 ( L_21 ) ;
goto V_109;
}
F_39 ( & V_2 . V_95 ) ;
return 0 ;
V_109:
F_46 ( V_7 ) ;
V_108:
F_39 ( & V_2 . V_95 ) ;
return V_1 ;
}
void F_47 ( struct V_6 * V_7 )
{
F_2 ( L_22 ) ;
F_38 ( & V_2 . V_95 ) ;
F_35 ( V_7 ) ;
F_46 ( V_7 ) ;
F_39 ( & V_2 . V_95 ) ;
}
static int F_48 ( struct V_110 * V_3 )
{
struct V_111 * V_111 ;
V_111 = F_49 ( & V_3 -> V_4 , L_23 ) ;
if ( F_10 ( V_111 ) ) {
F_11 ( L_24 ) ;
return F_12 ( V_111 ) ;
}
V_2 . V_57 = V_111 ;
return 0 ;
}
static void F_50 ( void )
{
if ( V_2 . V_57 )
F_51 ( V_2 . V_57 ) ;
}
int F_52 ( T_3 V_112 , T_3 * V_113 , T_3 * V_114 )
{
T_3 V_115 ;
bool V_116 = false ;
T_3 V_117 = V_2 . V_15 . V_25 . V_49 . V_38 ;
if ( V_113 == NULL || V_114 == NULL )
return - V_93 ;
V_115 = 100 ;
switch ( V_112 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_115 == 125 )
if ( V_117 == 27027 || V_117 == 74250 )
V_116 = true ;
if ( V_115 == 150 )
if ( V_117 == 27027 )
V_116 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_115 == 125 )
if ( V_117 == 27027 )
V_116 = true ;
break;
default:
return - V_93 ;
}
if ( V_116 ) {
switch ( V_112 ) {
case 32000 :
* V_113 = 8192 ;
break;
case 44100 :
* V_113 = 12544 ;
break;
case 48000 :
* V_113 = 8192 ;
break;
case 88200 :
* V_113 = 25088 ;
break;
case 96000 :
* V_113 = 16384 ;
break;
case 176400 :
* V_113 = 50176 ;
break;
case 192000 :
* V_113 = 32768 ;
break;
default:
return - V_93 ;
}
} else {
switch ( V_112 ) {
case 32000 :
* V_113 = 4096 ;
break;
case 44100 :
* V_113 = 6272 ;
break;
case 48000 :
* V_113 = 6144 ;
break;
case 88200 :
* V_113 = 12544 ;
break;
case 96000 :
* V_113 = 12288 ;
break;
case 176400 :
* V_113 = 25088 ;
break;
case 192000 :
* V_113 = 24576 ;
break;
default:
return - V_93 ;
}
}
* V_114 = V_117 * ( * V_113 / 128 ) * V_115 / ( V_112 / 10 ) ;
return 0 ;
}
int F_53 ( void )
{
F_2 ( L_25 ) ;
return V_2 . V_15 . V_77 -> V_118 ( & V_2 . V_15 ) ;
}
void F_54 ( void )
{
F_2 ( L_26 ) ;
V_2 . V_15 . V_77 -> V_119 ( & V_2 . V_15 ) ;
}
int F_55 ( void )
{
F_2 ( L_27 ) ;
return V_2 . V_15 . V_77 -> V_120 ( & V_2 . V_15 ) ;
}
void F_56 ( void )
{
F_2 ( L_28 ) ;
V_2 . V_15 . V_77 -> V_121 ( & V_2 . V_15 ) ;
}
bool F_57 ( void )
{
if ( V_2 . V_15 . V_25 . V_23 . V_27 == V_122 )
return true ;
else
return false ;
}
int F_58 ( struct V_123 * V_124 )
{
return V_2 . V_15 . V_77 -> V_125 ( & V_2 . V_15 , V_124 ) ;
}
static struct V_6 * T_1 F_59 ( struct V_110 * V_3 )
{
struct V_126 * V_127 = V_3 -> V_4 . V_128 ;
const char * V_129 = F_60 () ;
struct V_6 * V_130 ;
int V_22 ;
V_130 = NULL ;
for ( V_22 = 0 ; V_22 < V_127 -> V_131 ; ++ V_22 ) {
struct V_6 * V_7 = V_127 -> V_132 [ V_22 ] ;
if ( V_7 -> type != V_133 )
continue;
if ( V_130 == NULL )
V_130 = V_7 ;
if ( V_129 != NULL &&
strcmp ( V_7 -> V_134 , V_129 ) == 0 ) {
V_130 = V_7 ;
break;
}
}
return V_130 ;
}
static void T_1 F_61 ( struct V_110 * V_3 )
{
struct V_6 * V_135 ;
struct V_6 * V_7 ;
struct V_136 * V_137 ;
int V_1 ;
V_135 = F_59 ( V_3 ) ;
if ( ! V_135 )
return;
V_7 = F_62 ( & V_3 -> V_4 ) ;
if ( ! V_7 )
return;
F_63 ( V_7 , V_135 ) ;
V_137 = V_7 -> V_138 ;
V_2 . V_10 = V_137 -> V_10 ;
V_2 . V_12 = V_137 -> V_12 ;
V_2 . V_13 = V_137 -> V_13 ;
V_7 -> V_139 = V_140 ;
V_1 = F_7 ( V_7 ) ;
if ( V_1 ) {
F_11 ( L_29 , V_7 -> V_134 , V_1 ) ;
F_64 ( V_7 ) ;
return;
}
V_1 = F_65 ( V_7 ) ;
if ( V_1 ) {
F_11 ( L_30 , V_7 -> V_134 , V_1 ) ;
F_64 ( V_7 ) ;
return;
}
}
static void T_1 F_66 ( struct V_110 * V_3 )
{
struct V_105 * V_106 = & V_2 . V_72 ;
V_106 -> V_3 = V_3 ;
V_106 -> V_141 = V_142 ;
V_106 -> type = V_133 ;
F_67 ( V_106 ) ;
}
static void T_2 F_68 ( struct V_110 * V_3 )
{
struct V_105 * V_106 = & V_2 . V_72 ;
F_69 ( V_106 ) ;
}
static int T_1 F_70 ( struct V_110 * V_3 )
{
struct V_143 * V_144 ;
int V_1 ;
V_2 . V_3 = V_3 ;
F_71 ( & V_2 . V_95 ) ;
V_144 = F_72 ( V_2 . V_3 , V_145 , 0 ) ;
if ( ! V_144 ) {
F_11 ( L_31 ) ;
return - V_93 ;
}
V_2 . V_15 . V_146 = F_73 ( V_144 -> V_147 ,
F_74 ( V_144 ) ) ;
if ( ! V_2 . V_15 . V_146 ) {
F_11 ( L_32 ) ;
return - V_148 ;
}
V_1 = F_48 ( V_3 ) ;
if ( V_1 ) {
F_75 ( V_2 . V_15 . V_146 ) ;
return V_1 ;
}
F_76 ( & V_3 -> V_4 ) ;
V_2 . V_15 . V_149 = V_150 ;
V_2 . V_15 . V_151 = V_152 ;
V_2 . V_15 . V_153 = V_154 ;
V_2 . V_15 . V_155 = V_156 ;
F_71 ( & V_2 . V_15 . V_95 ) ;
F_77 () ;
F_78 ( L_33 , F_40 ) ;
F_66 ( V_3 ) ;
F_61 ( V_3 ) ;
return 0 ;
}
static int T_2 F_79 ( struct V_157 * V_4 , void * V_138 )
{
struct V_6 * V_7 = F_80 ( V_4 ) ;
F_15 ( V_7 ) ;
return 0 ;
}
static int T_2 F_81 ( struct V_110 * V_3 )
{
F_82 ( & V_3 -> V_4 , NULL , F_79 ) ;
F_83 ( & V_3 -> V_4 ) ;
F_84 () ;
F_68 ( V_3 ) ;
F_85 ( & V_3 -> V_4 ) ;
F_50 () ;
F_75 ( V_2 . V_15 . V_146 ) ;
return 0 ;
}
static int F_86 ( struct V_157 * V_4 )
{
F_87 ( V_2 . V_57 ) ;
F_88 () ;
return 0 ;
}
static int F_89 ( struct V_157 * V_4 )
{
int V_1 ;
V_1 = F_90 () ;
if ( V_1 < 0 )
return V_1 ;
F_91 ( V_2 . V_57 ) ;
return 0 ;
}
int T_1 F_92 ( void )
{
return F_93 ( & V_158 , F_70 ) ;
}
void T_2 F_94 ( void )
{
F_95 ( & V_158 ) ;
}
