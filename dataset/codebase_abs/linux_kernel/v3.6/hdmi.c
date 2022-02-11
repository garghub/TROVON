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
const struct V_21 * V_23 )
{
int V_24 , V_25 , V_26 , V_27 ;
if ( ( V_23 -> V_28 == V_22 -> V_28 ) &&
( V_23 -> V_29 == V_22 -> V_29 ) &&
( V_23 -> V_30 == V_22 -> V_30 ) ) {
V_27 = V_23 -> V_31 + V_23 -> V_32 + V_23 -> V_33 ;
V_25 = V_22 -> V_31 + V_22 -> V_32 + V_22 -> V_33 ;
V_26 = V_23 -> V_34 + V_23 -> V_35 + V_23 -> V_36 ;
V_24 = V_23 -> V_34 + V_23 -> V_35 + V_23 -> V_36 ;
F_2 ( L_4\
L_5 ,
V_25 , V_24 ,
V_27 , V_26 ) ;
if ( ( V_25 == V_27 ) &&
( V_24 == V_26 ) ) {
return true ;
}
}
return false ;
}
static struct V_37 F_13 ( struct V_21 * V_38 )
{
int V_12 ;
struct V_37 V_13 = { - 1 } ;
F_2 ( L_6 ) ;
for ( V_12 = 0 ; V_12 < F_11 ( V_20 ) ; V_12 ++ ) {
if ( F_12 ( V_38 , & V_20 [ V_12 ] . V_39 ) ) {
V_13 = V_20 [ V_12 ] . V_13 ;
goto V_40;
}
}
for ( V_12 = 0 ; V_12 < F_11 ( V_19 ) ; V_12 ++ ) {
if ( F_12 ( V_38 , & V_19 [ V_12 ] . V_39 ) ) {
V_13 = V_19 [ V_12 ] . V_13 ;
goto V_40;
}
}
V_40: return V_13 ;
}
unsigned long F_14 ( void )
{
return V_2 . V_8 . V_15 . V_39 . V_28 * 1000 ;
}
static void F_15 ( struct V_6 * V_7 , int V_41 ,
struct V_42 * V_43 )
{
unsigned long V_44 , V_45 ;
T_2 V_46 ;
V_44 = F_16 ( V_2 . V_47 ) / 10000 ;
if ( V_7 -> V_48 . V_2 . V_49 == 0 )
V_43 -> V_49 = V_50 ;
else
V_43 -> V_49 = V_7 -> V_48 . V_2 . V_49 ;
V_45 = V_44 / V_43 -> V_49 ;
if ( V_7 -> V_48 . V_2 . V_51 == 0 )
V_43 -> V_51 = V_52 ;
else
V_43 -> V_51 = V_7 -> V_48 . V_2 . V_51 ;
V_43 -> V_53 = V_41 * V_43 -> V_51 / V_45 ;
V_46 = ( V_41 - V_43 -> V_53 / V_43 -> V_51 * V_45 ) * 262144 ;
V_43 -> V_54 = V_43 -> V_51 * V_46 / V_45 ;
V_43 -> V_55 = V_41 > 1000 * 100 ;
V_43 -> V_56 = ( ( V_43 -> V_53 * V_44 / 10 ) / ( V_43 -> V_49 * 250 ) + 5 ) / 10 ;
V_43 -> V_57 = V_58 ;
F_2 ( L_7 , V_43 -> V_53 , V_43 -> V_54 ) ;
F_2 ( L_8 , V_43 -> V_55 , V_43 -> V_56 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_1 ;
const struct V_9 * V_38 ;
struct V_21 * V_59 ;
unsigned long V_41 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
F_18 ( V_7 -> V_60 ) ;
V_59 = & V_7 -> V_61 . V_39 ;
F_2 ( L_9 ,
V_7 -> V_61 . V_39 . V_29 ,
V_7 -> V_61 . V_39 . V_30 ) ;
V_38 = F_10 () ;
if ( V_38 == NULL ) {
V_2 . V_8 . V_15 . V_13 . V_14 = 4 ;
V_2 . V_8 . V_15 . V_13 . V_17 = V_18 ;
V_2 . V_8 . V_15 = V_19 [ 0 ] ;
} else {
V_2 . V_8 . V_15 = * V_38 ;
}
V_41 = V_59 -> V_28 ;
F_15 ( V_7 , V_41 , & V_2 . V_8 . V_62 ) ;
V_2 . V_8 . V_63 -> V_64 ( & V_2 . V_8 ) ;
V_1 = V_2 . V_8 . V_63 -> V_65 ( & V_2 . V_8 ) ;
if ( V_1 ) {
F_2 ( L_10 ) ;
goto V_66;
}
V_1 = V_2 . V_8 . V_63 -> V_67 ( & V_2 . V_8 ) ;
if ( V_1 ) {
F_2 ( L_11 ) ;
goto V_66;
}
V_2 . V_8 . V_63 -> V_68 ( & V_2 . V_8 ) ;
F_19 ( V_69 ) ;
F_20 ( V_7 -> V_48 . V_70 . V_71 ) ;
F_21 ( 0 ) ;
F_22 ( V_7 -> V_60 , & V_7 -> V_61 . V_39 ) ;
V_1 = V_2 . V_8 . V_63 -> V_72 ( & V_2 . V_8 ) ;
if ( V_1 )
goto V_73;
V_1 = F_23 ( V_7 -> V_60 ) ;
if ( V_1 )
goto V_74;
return 0 ;
V_74:
V_2 . V_8 . V_63 -> V_64 ( & V_2 . V_8 ) ;
V_73:
V_2 . V_8 . V_63 -> V_75 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_63 -> V_76 ( & V_2 . V_8 ) ;
V_66:
F_5 () ;
return - V_77 ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_18 ( V_7 -> V_60 ) ;
V_2 . V_8 . V_63 -> V_64 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_63 -> V_75 ( & V_2 . V_8 ) ;
V_2 . V_8 . V_63 -> V_76 ( & V_2 . V_8 ) ;
F_5 () ;
}
int F_25 ( struct V_6 * V_7 ,
struct V_21 * V_39 )
{
struct V_37 V_13 ;
V_13 = F_13 ( V_39 ) ;
if ( V_13 . V_14 == - 1 ) {
return - V_78 ;
}
return 0 ;
}
void F_26 ( struct V_6 * V_7 )
{
struct V_37 V_13 ;
V_13 = F_13 ( & V_7 -> V_61 . V_39 ) ;
V_2 . V_8 . V_15 . V_13 . V_14 = V_13 . V_14 ;
V_2 . V_8 . V_15 . V_13 . V_17 = V_13 . V_17 ;
if ( V_7 -> V_79 == V_80 ) {
int V_1 ;
F_24 ( V_7 ) ;
V_1 = F_17 ( V_7 ) ;
if ( V_1 )
F_27 ( L_12 ) ;
} else {
F_22 ( V_7 -> V_60 , & V_7 -> V_61 . V_39 ) ;
}
}
static void F_28 ( struct V_81 * V_82 )
{
F_29 ( & V_2 . V_83 ) ;
if ( F_1 () )
return;
V_2 . V_8 . V_63 -> V_84 ( & V_2 . V_8 , V_82 ) ;
V_2 . V_8 . V_63 -> V_85 ( & V_2 . V_8 , V_82 ) ;
V_2 . V_8 . V_63 -> V_86 ( & V_2 . V_8 , V_82 ) ;
V_2 . V_8 . V_63 -> V_87 ( & V_2 . V_8 , V_82 ) ;
F_5 () ;
F_30 ( & V_2 . V_83 ) ;
}
int F_31 ( T_3 * V_88 , int V_11 )
{
int V_1 ;
F_29 ( & V_2 . V_83 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_2 . V_8 . V_63 -> V_89 ( & V_2 . V_8 , V_88 , V_11 ) ;
F_5 () ;
F_30 ( & V_2 . V_83 ) ;
return V_1 ;
}
bool F_33 ( void )
{
int V_1 ;
F_29 ( & V_2 . V_83 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_2 . V_8 . V_63 -> V_90 ( & V_2 . V_8 ) ;
F_5 () ;
F_30 ( & V_2 . V_83 ) ;
return V_1 == 1 ;
}
int F_34 ( struct V_6 * V_7 )
{
struct V_91 * V_92 = V_7 -> V_93 ;
int V_1 = 0 ;
F_2 ( L_13 ) ;
F_29 ( & V_2 . V_83 ) ;
if ( V_7 -> V_60 == NULL ) {
F_27 ( L_14 ) ;
V_1 = - V_94 ;
goto V_95;
}
V_2 . V_8 . V_96 = V_92 -> V_96 ;
V_1 = F_35 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_15 ) ;
goto V_95;
}
if ( V_7 -> V_97 ) {
V_1 = V_7 -> V_97 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_16 ) ;
goto V_98;
}
}
V_1 = F_17 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_12 ) ;
goto V_99;
}
F_30 ( & V_2 . V_83 ) ;
return 0 ;
V_99:
if ( V_7 -> V_100 )
V_7 -> V_100 ( V_7 ) ;
V_98:
F_36 ( V_7 ) ;
V_95:
F_30 ( & V_2 . V_83 ) ;
return V_1 ;
}
void F_37 ( struct V_6 * V_7 )
{
F_2 ( L_17 ) ;
F_29 ( & V_2 . V_83 ) ;
F_24 ( V_7 ) ;
if ( V_7 -> V_100 )
V_7 -> V_100 ( V_7 ) ;
F_36 ( V_7 ) ;
F_30 ( & V_2 . V_83 ) ;
}
static int F_38 ( struct V_101 * V_3 )
{
struct V_102 * V_102 ;
V_102 = F_39 ( & V_3 -> V_4 , L_18 ) ;
if ( F_40 ( V_102 ) ) {
F_27 ( L_19 ) ;
return F_41 ( V_102 ) ;
}
V_2 . V_47 = V_102 ;
return 0 ;
}
static void F_42 ( void )
{
if ( V_2 . V_47 )
F_43 ( V_2 . V_47 ) ;
}
int F_44 ( T_2 V_103 , T_2 * V_104 , T_2 * V_105 )
{
T_2 V_106 ;
bool V_107 = false ;
T_2 V_108 = V_2 . V_8 . V_15 . V_39 . V_28 ;
if ( V_104 == NULL || V_105 == NULL )
return - V_78 ;
V_106 = 100 ;
switch ( V_103 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_106 == 125 )
if ( V_108 == 27027 || V_108 == 74250 )
V_107 = true ;
if ( V_106 == 150 )
if ( V_108 == 27027 )
V_107 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_106 == 125 )
if ( V_108 == 27027 )
V_107 = true ;
break;
default:
return - V_78 ;
}
if ( V_107 ) {
switch ( V_103 ) {
case 32000 :
* V_104 = 8192 ;
break;
case 44100 :
* V_104 = 12544 ;
break;
case 48000 :
* V_104 = 8192 ;
break;
case 88200 :
* V_104 = 25088 ;
break;
case 96000 :
* V_104 = 16384 ;
break;
case 176400 :
* V_104 = 50176 ;
break;
case 192000 :
* V_104 = 32768 ;
break;
default:
return - V_78 ;
}
} else {
switch ( V_103 ) {
case 32000 :
* V_104 = 4096 ;
break;
case 44100 :
* V_104 = 6272 ;
break;
case 48000 :
* V_104 = 6144 ;
break;
case 88200 :
* V_104 = 12544 ;
break;
case 96000 :
* V_104 = 12288 ;
break;
case 176400 :
* V_104 = 25088 ;
break;
case 192000 :
* V_104 = 24576 ;
break;
default:
return - V_78 ;
}
}
* V_105 = V_108 * ( * V_104 / 128 ) * V_106 / ( V_103 / 10 ) ;
return 0 ;
}
int F_45 ( void )
{
F_2 ( L_20 ) ;
return V_2 . V_8 . V_63 -> V_109 ( & V_2 . V_8 ) ;
}
void F_46 ( void )
{
F_2 ( L_21 ) ;
V_2 . V_8 . V_63 -> V_110 ( & V_2 . V_8 ) ;
}
int F_47 ( void )
{
F_2 ( L_22 ) ;
return V_2 . V_8 . V_63 -> V_111 ( & V_2 . V_8 ) ;
}
void F_48 ( void )
{
F_2 ( L_23 ) ;
V_2 . V_8 . V_63 -> V_112 ( & V_2 . V_8 ) ;
}
bool F_49 ( void )
{
if ( V_2 . V_8 . V_15 . V_13 . V_17 == V_113 )
return true ;
else
return false ;
}
int F_50 ( struct V_114 * V_115 )
{
return V_2 . V_8 . V_63 -> V_116 ( & V_2 . V_8 , V_115 ) ;
}
static void T_1 F_51 ( struct V_101 * V_3 )
{
struct V_117 * V_118 = V_3 -> V_4 . V_119 ;
int V_1 , V_12 ;
for ( V_12 = 0 ; V_12 < V_118 -> V_120 ; ++ V_12 ) {
struct V_6 * V_7 = V_118 -> V_121 [ V_12 ] ;
if ( V_7 -> type != V_122 )
continue;
V_1 = F_7 ( V_7 ) ;
if ( V_1 ) {
F_27 ( L_24 , V_7 -> V_123 , V_1 ) ;
continue;
}
V_1 = F_52 ( V_7 , & V_3 -> V_4 , V_12 ) ;
if ( V_1 )
F_27 ( L_25 ,
V_7 -> V_123 , V_1 ) ;
}
}
static int T_1 F_53 ( struct V_101 * V_3 )
{
struct V_124 * V_125 ;
int V_1 ;
V_2 . V_3 = V_3 ;
F_54 ( & V_2 . V_83 ) ;
V_125 = F_55 ( V_2 . V_3 , V_126 , 0 ) ;
if ( ! V_125 ) {
F_27 ( L_26 ) ;
return - V_78 ;
}
V_2 . V_8 . V_127 = F_56 ( V_125 -> V_128 ,
F_57 ( V_125 ) ) ;
if ( ! V_2 . V_8 . V_127 ) {
F_27 ( L_27 ) ;
return - V_129 ;
}
V_1 = F_38 ( V_3 ) ;
if ( V_1 ) {
F_58 ( V_2 . V_8 . V_127 ) ;
return V_1 ;
}
F_59 ( & V_3 -> V_4 ) ;
V_2 . V_8 . V_130 = V_131 ;
V_2 . V_8 . V_132 = V_133 ;
V_2 . V_8 . V_134 = V_135 ;
V_2 . V_8 . V_136 = V_137 ;
F_54 ( & V_2 . V_8 . V_83 ) ;
F_60 () ;
F_61 ( L_28 , F_28 ) ;
F_51 ( V_3 ) ;
return 0 ;
}
static int T_4 F_62 ( struct V_101 * V_3 )
{
F_63 ( & V_3 -> V_4 ) ;
F_64 () ;
F_65 ( & V_3 -> V_4 ) ;
F_42 () ;
F_58 ( V_2 . V_8 . V_127 ) ;
return 0 ;
}
static int F_66 ( struct V_138 * V_4 )
{
F_67 ( V_2 . V_47 ) ;
F_68 () ;
return 0 ;
}
static int F_69 ( struct V_138 * V_4 )
{
int V_1 ;
V_1 = F_70 () ;
if ( V_1 < 0 )
return V_1 ;
F_71 ( V_2 . V_47 ) ;
return 0 ;
}
int T_1 F_72 ( void )
{
return F_73 ( & V_139 , F_53 ) ;
}
void T_4 F_74 ( void )
{
F_75 ( & V_139 ) ;
}
