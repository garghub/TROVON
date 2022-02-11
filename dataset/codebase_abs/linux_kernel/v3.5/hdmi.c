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
F_2 ( L_3 ) ;
F_8 ( & V_2 . V_8 ) ;
return 0 ;
}
static const struct V_9 * F_9 (
const struct V_9 * V_10 ,
int V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
if ( V_10 [ V_12 ] . V_13 . V_14 == V_2 . V_8 . V_15 . V_13 . V_14 )
return & V_10 [ V_12 ] ;
}
return NULL ;
}
static const struct V_9 * F_10 ( void )
{
const struct V_9 * V_16 ;
int V_11 ;
if ( V_2 . V_8 . V_15 . V_13 . V_17 == V_18 ) {
V_16 = V_19 ;
V_11 = F_11 ( V_19 ) ;
} else {
V_16 = V_20 ;
V_11 = F_11 ( V_20 ) ;
}
return F_9 ( V_16 , V_11 ) ;
}
static bool F_12 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
int V_25 , V_26 , V_27 , V_28 ;
if ( ( V_24 -> V_29 == V_22 -> V_29 ) &&
( V_24 -> V_30 == V_22 -> V_30 ) &&
( V_24 -> V_31 == V_22 -> V_31 ) ) {
V_28 = V_24 -> V_32 + V_24 -> V_33 + V_24 -> V_34 ;
V_26 = V_22 -> V_32 + V_22 -> V_33 + V_22 -> V_34 ;
V_27 = V_24 -> V_35 + V_24 -> V_36 + V_24 -> V_37 ;
V_25 = V_24 -> V_35 + V_24 -> V_36 + V_24 -> V_37 ;
F_2 ( L_4\
L_5 ,
V_26 , V_25 ,
V_28 , V_27 ) ;
if ( ( V_26 == V_28 ) &&
( V_25 == V_27 ) ) {
return true ;
}
}
return false ;
}
static struct V_38 F_13 ( struct V_21 * V_39 )
{
int V_12 ;
struct V_38 V_13 = { - 1 } ;
F_2 ( L_6 ) ;
for ( V_12 = 0 ; V_12 < F_11 ( V_20 ) ; V_12 ++ ) {
if ( F_12 ( V_39 , & V_20 [ V_12 ] . V_40 ) ) {
V_13 = V_20 [ V_12 ] . V_13 ;
goto V_41;
}
}
for ( V_12 = 0 ; V_12 < F_11 ( V_19 ) ; V_12 ++ ) {
if ( F_12 ( V_39 , & V_19 [ V_12 ] . V_40 ) ) {
V_13 = V_19 [ V_12 ] . V_13 ;
goto V_41;
}
}
V_41: return V_13 ;
}
unsigned long F_14 ( void )
{
return V_2 . V_8 . V_15 . V_40 . V_29 * 1000 ;
}
static void F_15 ( struct V_6 * V_7 , int V_42 ,
struct V_43 * V_44 )
{
unsigned long V_45 , V_46 ;
T_2 V_47 ;
V_45 = F_16 ( V_2 . V_48 ) / 10000 ;
if ( V_7 -> V_49 . V_2 . V_50 == 0 )
V_44 -> V_50 = V_51 ;
else
V_44 -> V_50 = V_7 -> V_49 . V_2 . V_50 ;
V_46 = V_45 / V_44 -> V_50 ;
if ( V_7 -> V_49 . V_2 . V_52 == 0 )
V_44 -> V_52 = V_53 ;
else
V_44 -> V_52 = V_7 -> V_49 . V_2 . V_52 ;
V_44 -> V_54 = V_42 * V_44 -> V_52 / V_46 ;
V_47 = ( V_42 - V_44 -> V_54 / V_44 -> V_52 * V_46 ) * 262144 ;
V_44 -> V_55 = V_44 -> V_52 * V_47 / V_46 ;
V_44 -> V_56 = V_42 > 1000 * 100 ;
V_44 -> V_57 = ( ( V_44 -> V_54 * V_45 / 10 ) / ( V_44 -> V_50 * 250 ) + 5 ) / 10 ;
V_44 -> V_58 = V_59 ;
F_2 ( L_7 , V_44 -> V_54 , V_44 -> V_55 ) ;
F_2 ( L_8 , V_44 -> V_56 , V_44 -> V_57 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_1 ;
const struct V_9 * V_39 ;
struct V_21 * V_60 ;
unsigned long V_42 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
F_18 ( V_7 -> V_61 ) ;
V_60 = & V_7 -> V_62 . V_40 ;
F_2 ( L_9 ,
V_7 -> V_62 . V_40 . V_30 ,
V_7 -> V_62 . V_40 . V_31 ) ;
V_39 = F_10 () ;
if ( V_39 == NULL ) {
V_2 . V_8 . V_15 . V_13 . V_14 = 4 ;
V_2 . V_8 . V_15 . V_13 . V_17 = V_18 ;
V_2 . V_8 . V_15 = V_19 [ 0 ] ;
} else {
V_2 . V_8 . V_15 = * V_39 ;
}
V_42 = V_60 -> V_29 ;
F_15 ( V_7 , V_42 , & V_2 . V_8 . V_63 ) ;
V_2 . V_8 . V_64 -> V_65 ( & V_2 . V_8 ) ;
V_1 = V_2 . V_8 . V_64 -> V_66 ( & V_2 . V_8 ) ;
if ( V_1 ) {
F_2 ( L_10 ) ;
goto V_67;
}
V_1 = V_2 . V_8 . V_64 -> V_68 ( & V_2 . V_8 ) ;
if ( V_1 ) {
F_2 ( L_11 ) ;
goto V_67;
}
V_2 . V_8 . V_64 -> V_69 ( & V_2 . V_8 ) ;
F_19 ( V_70 ) ;
F_20 ( V_7 -> V_49 . V_71 . V_72 ) ;
F_21 ( 0 ) ;
F_22 ( V_7 -> V_61 , & V_7 -> V_62 . V_40 ) ;
V_1 = V_2 . V_8 . V_64 -> V_73 ( & V_2 . V_8 ) ;
if ( V_1 )
goto V_74;
V_1 = F_23 ( V_7 -> V_61 ) ;
if ( V_1 )
goto V_75;
return 0 ;
V_75:
V_2 . V_8 . V_64 -> V_65 ( & V_2 . V_8 ) ;
V_74:
V_2 . V_8 . V_64 -> V_76 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_64 -> V_77 ( & V_2 . V_8 ) ;
V_67:
F_5 () ;
return - V_78 ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_18 ( V_7 -> V_61 ) ;
V_2 . V_8 . V_64 -> V_65 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_64 -> V_76 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_64 -> V_77 ( & V_2 . V_8 ) ;
F_5 () ;
}
int F_25 ( struct V_6 * V_7 ,
struct V_21 * V_40 )
{
struct V_38 V_13 ;
V_13 = F_13 ( V_40 ) ;
if ( V_13 . V_14 == - 1 ) {
return - V_79 ;
}
return 0 ;
}
void F_26 ( struct V_6 * V_7 )
{
struct V_38 V_13 ;
V_13 = F_13 ( & V_7 -> V_62 . V_40 ) ;
V_2 . V_8 . V_15 . V_13 . V_14 = V_13 . V_14 ;
V_2 . V_8 . V_15 . V_13 . V_17 = V_13 . V_17 ;
if ( V_7 -> V_80 == V_81 ) {
int V_1 ;
F_24 ( V_7 ) ;
V_1 = F_17 ( V_7 ) ;
if ( V_1 )
F_27 ( L_12 ) ;
} else {
F_22 ( V_7 -> V_61 , & V_7 -> V_62 . V_40 ) ;
}
}
static void F_28 ( struct V_82 * V_83 )
{
F_29 ( & V_2 . V_84 ) ;
if ( F_1 () )
return;
V_2 . V_8 . V_64 -> V_85 ( & V_2 . V_8 , V_83 ) ;
V_2 . V_8 . V_64 -> V_86 ( & V_2 . V_8 , V_83 ) ;
V_2 . V_8 . V_64 -> V_87 ( & V_2 . V_8 , V_83 ) ;
V_2 . V_8 . V_64 -> V_88 ( & V_2 . V_8 , V_83 ) ;
F_5 () ;
F_30 ( & V_2 . V_84 ) ;
}
int F_31 ( T_3 * V_89 , int V_11 )
{
int V_1 ;
F_29 ( & V_2 . V_84 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_2 . V_8 . V_64 -> V_90 ( & V_2 . V_8 , V_89 , V_11 ) ;
F_5 () ;
F_30 ( & V_2 . V_84 ) ;
return V_1 ;
}
bool F_33 ( void )
{
int V_1 ;
F_29 ( & V_2 . V_84 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_2 . V_8 . V_64 -> V_91 ( & V_2 . V_8 ) ;
F_5 () ;
F_30 ( & V_2 . V_84 ) ;
return V_1 == 1 ;
}
int F_34 ( struct V_6 * V_7 )
{
struct V_92 * V_93 = V_7 -> V_94 ;
int V_1 = 0 ;
F_2 ( L_13 ) ;
F_29 ( & V_2 . V_84 ) ;
if ( V_7 -> V_61 == NULL ) {
F_27 ( L_14 ) ;
V_1 = - V_95 ;
goto V_96;
}
V_2 . V_8 . V_97 = V_93 -> V_97 ;
V_1 = F_35 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_15 ) ;
goto V_96;
}
if ( V_7 -> V_98 ) {
V_1 = V_7 -> V_98 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_16 ) ;
goto V_99;
}
}
V_1 = F_17 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_12 ) ;
goto V_100;
}
F_30 ( & V_2 . V_84 ) ;
return 0 ;
V_100:
if ( V_7 -> V_101 )
V_7 -> V_101 ( V_7 ) ;
V_99:
F_36 ( V_7 ) ;
V_96:
F_30 ( & V_2 . V_84 ) ;
return V_1 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_2 ( L_17 ) ;
F_29 ( & V_2 . V_84 ) ;
F_24 ( V_7 ) ;
if ( V_7 -> V_101 )
V_7 -> V_101 ( V_7 ) ;
F_36 ( V_7 ) ;
F_30 ( & V_2 . V_84 ) ;
}
static int F_38 ( struct V_102 * V_3 )
{
struct V_103 * V_103 ;
V_103 = F_39 ( & V_3 -> V_4 , L_18 ) ;
if ( F_40 ( V_103 ) ) {
F_27 ( L_19 ) ;
return F_41 ( V_103 ) ;
}
V_2 . V_48 = V_103 ;
return 0 ;
}
static void F_42 ( void )
{
if ( V_2 . V_48 )
F_43 ( V_2 . V_48 ) ;
}
int F_44 ( T_2 V_104 , T_2 * V_105 , T_2 * V_106 )
{
T_2 V_107 ;
bool V_108 = false ;
T_2 V_109 = V_2 . V_8 . V_15 . V_40 . V_29 ;
if ( V_105 == NULL || V_106 == NULL )
return - V_79 ;
V_107 = 100 ;
switch ( V_104 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_107 == 125 )
if ( V_109 == 27027 || V_109 == 74250 )
V_108 = true ;
if ( V_107 == 150 )
if ( V_109 == 27027 )
V_108 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_107 == 125 )
if ( V_109 == 27027 )
V_108 = true ;
break;
default:
return - V_79 ;
}
if ( V_108 ) {
switch ( V_104 ) {
case 32000 :
* V_105 = 8192 ;
break;
case 44100 :
* V_105 = 12544 ;
break;
case 48000 :
* V_105 = 8192 ;
break;
case 88200 :
* V_105 = 25088 ;
break;
case 96000 :
* V_105 = 16384 ;
break;
case 176400 :
* V_105 = 50176 ;
break;
case 192000 :
* V_105 = 32768 ;
break;
default:
return - V_79 ;
}
} else {
switch ( V_104 ) {
case 32000 :
* V_105 = 4096 ;
break;
case 44100 :
* V_105 = 6272 ;
break;
case 48000 :
* V_105 = 6144 ;
break;
case 88200 :
* V_105 = 12544 ;
break;
case 96000 :
* V_105 = 12288 ;
break;
case 176400 :
* V_105 = 25088 ;
break;
case 192000 :
* V_105 = 24576 ;
break;
default:
return - V_79 ;
}
}
* V_106 = V_109 * ( * V_105 / 128 ) * V_107 / ( V_104 / 10 ) ;
return 0 ;
}
int F_45 ( void )
{
F_2 ( L_20 ) ;
return V_2 . V_8 . V_64 -> V_110 ( & V_2 . V_8 ) ;
}
void F_46 ( void )
{
F_2 ( L_21 ) ;
V_2 . V_8 . V_64 -> V_111 ( & V_2 . V_8 ) ;
}
int F_47 ( void )
{
F_2 ( L_22 ) ;
return V_2 . V_8 . V_64 -> V_112 ( & V_2 . V_8 ) ;
}
void F_48 ( void )
{
F_2 ( L_23 ) ;
V_2 . V_8 . V_64 -> V_113 ( & V_2 . V_8 ) ;
}
bool F_49 ( void )
{
if ( V_2 . V_8 . V_15 . V_13 . V_17 == V_114 )
return true ;
else
return false ;
}
int F_50 ( struct V_115 * V_116 )
{
return V_2 . V_8 . V_64 -> V_117 ( & V_2 . V_8 , V_116 ) ;
}
static void T_1 F_51 ( struct V_102 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_4 . V_120 ;
int V_1 , V_12 ;
for ( V_12 = 0 ; V_12 < V_119 -> V_121 ; ++ V_12 ) {
struct V_6 * V_7 = V_119 -> V_122 [ V_12 ] ;
if ( V_7 -> type != V_123 )
continue;
V_1 = F_7 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_24 , V_7 -> V_124 , V_1 ) ;
continue;
}
V_1 = F_52 ( V_7 , & V_3 -> V_4 , V_12 ) ;
if ( V_1 )
F_27 ( L_25 ,
V_7 -> V_124 , V_1 ) ;
}
}
static int T_1 F_53 ( struct V_102 * V_3 )
{
struct V_125 * V_126 ;
int V_1 ;
V_2 . V_3 = V_3 ;
F_54 ( & V_2 . V_84 ) ;
V_126 = F_55 ( V_2 . V_3 , V_127 , 0 ) ;
if ( ! V_126 ) {
F_27 ( L_26 ) ;
return - V_79 ;
}
V_2 . V_8 . V_128 = F_56 ( V_126 -> V_129 ,
F_57 ( V_126 ) ) ;
if ( ! V_2 . V_8 . V_128 ) {
F_27 ( L_27 ) ;
return - V_130 ;
}
V_1 = F_38 ( V_3 ) ;
if ( V_1 ) {
F_58 ( V_2 . V_8 . V_128 ) ;
return V_1 ;
}
F_59 ( & V_3 -> V_4 ) ;
V_2 . V_8 . V_131 = V_132 ;
V_2 . V_8 . V_133 = V_134 ;
V_2 . V_8 . V_135 = V_136 ;
V_2 . V_8 . V_137 = V_138 ;
F_60 () ;
F_61 ( L_28 , F_28 ) ;
F_51 ( V_3 ) ;
return 0 ;
}
static int T_4 F_62 ( struct V_102 * V_3 )
{
F_63 ( & V_3 -> V_4 ) ;
F_64 () ;
F_65 ( & V_3 -> V_4 ) ;
F_42 () ;
F_58 ( V_2 . V_8 . V_128 ) ;
return 0 ;
}
static int F_66 ( struct V_139 * V_4 )
{
F_67 ( V_2 . V_48 ) ;
F_68 () ;
return 0 ;
}
static int F_69 ( struct V_139 * V_4 )
{
int V_1 ;
V_1 = F_70 () ;
if ( V_1 < 0 )
return V_1 ;
F_71 ( V_2 . V_48 ) ;
return 0 ;
}
int T_1 F_72 ( void )
{
return F_73 ( & V_140 , F_53 ) ;
}
void T_4 F_74 ( void )
{
F_75 ( & V_140 ) ;
}
