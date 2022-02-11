static int T_1 F_1 ( void )
{
F_2 ( L_1 ) ;
F_3 ( L_2 , V_1 ) ;
return 0 ;
}
static void T_2 F_4 ( void )
{
F_2 ( L_3 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
if ( F_6 ( V_5 , F_7 ( 64 ) ) == 0 ) {
if ( F_8 ( V_5 , F_7 ( 64 ) ) != 0 ) {
F_9 ( V_3 ,
L_4 ) ;
return - V_7 ;
}
} else if ( F_6 ( V_5 , F_7 ( 32 ) ) != 0 ) {
F_9 ( V_3 , L_5 ) ;
return - V_7 ;
}
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_8 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_9 )
F_11 ( V_3 -> V_9 ) ;
if ( V_3 -> V_10 )
F_11 ( V_3 -> V_10 ) ;
if ( F_12 ( & V_6 -> V_11 ) == 1 )
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_8 * V_6 )
{
T_3 V_12 ;
int V_13 ;
V_3 -> V_6 = V_6 ;
V_13 = F_16 ( V_6 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_6 ) ;
goto V_14;
}
if ( ! ( F_17 ( V_6 , 0 ) & V_15 ) ) {
F_9 ( V_3 , L_7 ) ;
V_13 = - V_7 ;
goto V_16;
}
if ( F_18 ( V_3 ) && ! ( F_17 ( V_6 , 2 ) & V_15 ) ) {
F_9 ( V_3 , L_8 ) ;
V_13 = - V_7 ;
goto V_16;
}
if ( F_12 ( & V_6 -> V_11 ) == 1 ) {
V_13 = F_19 ( V_6 , L_9 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_10 ) ;
goto V_16;
}
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
}
F_22 ( V_6 , V_17 , & V_12 ) ;
if ( V_12 == V_18 ) {
F_9 ( V_3 ,
L_11 ,
V_12 ) ;
V_13 = - V_19 ;
goto V_20;
}
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_3 , L_12 ) ;
V_13 = - V_7 ;
goto V_20;
}
V_3 -> V_21 . V_22 = F_24 ( V_6 , V_23 ) ;
if ( F_18 ( V_3 ) && ! V_3 -> V_21 . V_22 )
F_9 ( V_3 , L_13 ) ;
V_13 = F_5 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_3 -> V_21 . V_24 = F_25 ( V_6 , 0 ) ;
V_3 -> V_21 . V_25 = F_26 ( V_6 , 0 ) ;
V_3 -> V_21 . V_26 = V_6 -> V_26 ;
V_3 -> V_10 = F_27 ( V_6 , 0 ) ;
if ( ! V_3 -> V_10 ) {
F_9 ( V_3 , L_14 ) ;
V_13 = - V_27 ;
goto V_20;
}
if ( F_18 ( V_3 ) ) {
V_3 -> V_28 = F_25 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_29 = F_28 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_9 = F_29 ( V_3 -> V_28 , V_3 -> V_29 ) ;
if ( ! V_3 -> V_9 ) {
F_9 ( V_3 , L_15 ) ;
return - V_27 ;
}
}
return 0 ;
V_20:
F_13 ( V_6 ) ;
V_16:
F_14 ( V_6 ) ;
V_14:
return V_13 ;
}
int F_30 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_34 = V_3 -> V_34 ;
V_31 -> V_35 = V_3 -> V_21 . V_24 ;
V_31 -> V_36 = V_3 -> V_21 . V_25 ;
V_31 -> V_37 = V_3 -> V_21 . V_26 ;
V_31 -> V_38 =
( V_3 -> V_39 [ 0 ] . V_40 . V_41 == V_42 ) ;
V_31 -> V_43 = F_31 ( & V_3 -> V_39 [ 0 ] ) ;
F_32 ( V_31 -> V_44 , V_3 -> V_39 [ 0 ] . V_40 . V_45 ) ;
if ( F_18 ( V_3 ) ) {
V_31 -> V_46 = V_47 ;
V_31 -> V_48 = V_49 ;
V_31 -> V_50 = V_51 ;
V_31 -> V_52 = V_53 ;
V_31 -> V_54 = V_3 -> V_54 ;
V_31 -> V_55 = true ;
} else {
F_33 ( & V_3 -> V_39 [ 0 ] , & V_31 -> V_46 ,
& V_31 -> V_48 , & V_31 -> V_50 ,
& V_31 -> V_52 ) ;
}
if ( F_18 ( V_3 ) ) {
V_33 = F_34 ( F_35 ( V_3 ) ) ;
if ( V_33 ) {
F_36 ( F_35 ( V_3 ) , V_33 ,
& V_31 -> V_56 , NULL ) ;
F_37 ( F_35 ( V_3 ) , V_33 ,
& V_31 -> V_57 ) ;
F_38 ( F_35 ( V_3 ) , V_33 ) ;
}
} else {
F_36 ( F_35 ( V_3 ) , NULL ,
& V_31 -> V_56 , NULL ) ;
}
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_40 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_41 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_58 ) ;
if ( ! V_3 )
return V_3 ;
F_43 ( V_3 ) ;
return V_3 ;
}
static int F_44 ( struct V_2 * V_3 ,
T_4 V_59 )
{
if ( ! V_3 )
return - V_19 ;
F_45 ( V_3 , V_60 , L_16 ) ;
return 0 ;
}
static struct V_2 * F_46 ( struct V_8 * V_6 ,
struct V_61 * V_62 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_41 ( V_6 ) ;
if ( ! V_3 )
goto V_14;
V_3 -> V_63 = V_62 -> V_63 ;
if ( V_62 -> V_64 )
V_3 -> V_65 = true ;
F_47 ( V_3 , V_62 -> V_66 , V_62 -> V_67 ) ;
V_13 = F_15 ( V_3 , V_6 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_17 ) ;
goto V_16;
}
F_49 ( V_3 , L_18 ) ;
V_13 = F_50 ( V_3 , V_68 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_19 ) ;
goto V_20;
}
F_49 ( V_3 , L_20 ) ;
return V_3 ;
V_20:
F_10 ( V_3 ) ;
V_16:
F_39 ( V_3 ) ;
V_14:
return NULL ;
}
static void F_51 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_52 ( V_3 ) ;
F_10 ( V_3 ) ;
F_44 ( V_3 , V_69 ) ;
F_39 ( V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
if ( V_3 -> V_70 . V_71 . V_72 == V_73 ) {
F_54 ( V_3 -> V_6 ) ;
F_40 ( V_3 -> V_70 . V_74 ) ;
} else if ( V_3 -> V_70 . V_71 . V_72 == V_75 ) {
F_55 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_70 . V_71 , 0 , sizeof( struct V_76 ) ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_77 * V_70 )
{
int V_78 , V_13 , V_79 ;
V_79 = V_70 -> V_80 . V_81 ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
V_70 -> V_74 [ V_78 ] . V_82 = V_78 ;
V_13 = F_57 ( V_3 -> V_6 , V_70 -> V_74 ,
V_70 -> V_80 . V_83 , V_79 ) ;
if ( V_13 < V_79 && V_13 >= V_70 -> V_80 . V_83 &&
( V_13 % V_3 -> V_34 ) ) {
F_54 ( V_3 -> V_6 ) ;
V_79 = ( V_13 / V_3 -> V_34 ) * V_3 -> V_34 ;
F_9 ( V_3 ,
L_21 ,
V_79 , V_70 -> V_80 . V_81 ) ;
V_13 = F_58 ( V_3 -> V_6 ,
V_70 -> V_74 , V_79 ) ;
if ( ! V_13 )
V_13 = V_79 ;
}
if ( V_13 > 0 ) {
V_70 -> V_71 . V_72 = V_73 ;
V_70 -> V_71 . V_81 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_22 ,
V_79 , V_13 ) ;
}
return V_13 ;
}
static int F_59 ( struct V_2 * V_3 , bool V_84 )
{
struct V_77 * V_70 = & V_3 -> V_70 ;
struct V_85 * V_86 ;
int V_13 = 0 , V_79 ;
switch ( V_70 -> V_80 . V_72 ) {
case V_73 :
V_79 = V_70 -> V_80 . V_81 ;
V_70 -> V_74 = F_60 ( V_79 , sizeof( * V_86 ) , V_58 ) ;
if ( ! V_70 -> V_74 ) {
V_13 = - V_27 ;
goto V_71;
}
V_13 = F_56 ( V_3 , V_70 ) ;
if ( ! V_13 )
goto V_71;
F_9 ( V_3 , L_23 ) ;
F_40 ( V_70 -> V_74 ) ;
if ( V_84 )
goto V_71;
case V_75 :
if ( V_3 -> V_34 == 1 ) {
V_13 = F_61 ( V_3 -> V_6 ) ;
if ( ! V_13 ) {
V_70 -> V_71 . V_72 = V_75 ;
goto V_71;
}
F_9 ( V_3 , L_24 ) ;
if ( V_84 )
goto V_71;
}
case V_87 :
V_70 -> V_71 . V_72 = V_87 ;
V_13 = 0 ;
goto V_71;
default:
F_9 ( V_3 , L_25 ,
V_70 -> V_80 . V_72 ) ;
V_13 = - V_88 ;
}
V_71:
V_3 -> V_89 = V_90 ;
return V_13 ;
}
static void F_62 ( struct V_2 * V_3 , void * V_91 ,
int V_92 , void (* F_63)( void * ) )
{
struct V_93 * V_94 = & V_3 -> V_39 [ V_92 % V_3 -> V_34 ] ;
int V_95 = V_92 / V_3 -> V_34 ;
V_94 -> V_96 [ V_95 ] . V_97 = F_63 ;
V_94 -> V_96 [ V_95 ] . V_91 = V_91 ;
}
static void F_64 ( struct V_2 * V_3 , int V_92 )
{
struct V_93 * V_94 = & V_3 -> V_39 [ V_92 % V_3 -> V_34 ] ;
int V_95 = V_92 / V_3 -> V_34 ;
memset ( & V_94 -> V_96 [ V_95 ] , 0 ,
sizeof( struct V_98 ) ) ;
}
static T_5 F_65 ( int V_26 , void * V_99 )
{
F_66 ( (struct V_100 * ) V_99 ) ;
return V_101 ;
}
static T_5 F_67 ( int V_26 , void * V_102 )
{
struct V_2 * V_3 = (struct V_2 * ) V_102 ;
struct V_93 * V_94 ;
T_5 V_13 = V_103 ;
T_6 V_104 ;
int V_78 , V_105 ;
for ( V_78 = 0 ; V_78 < V_3 -> V_34 ; V_78 ++ ) {
V_104 = F_68 ( & V_3 -> V_39 [ V_78 ] ) ;
if ( ! V_104 )
continue;
V_94 = & V_3 -> V_39 [ V_78 ] ;
if ( F_69 ( V_104 & 0x1 ) ) {
F_66 ( V_94 -> V_106 ) ;
V_104 &= ~ 0x1 ;
V_13 = V_101 ;
}
for ( V_105 = 0 ; V_105 < 64 ; V_105 ++ ) {
if ( ( 0x2ULL << V_105 ) & V_104 ) {
V_94 -> V_96 [ V_105 ] . V_97 (
V_94 -> V_96 [ V_105 ] . V_91 ) ;
V_104 &= ~ ( 0x2ULL << V_105 ) ;
V_13 = V_101 ;
}
}
if ( F_69 ( V_104 ) )
F_45 ( V_94 , V_107 ,
L_26 ,
V_104 ) ;
}
return V_13 ;
}
int F_70 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = V_94 -> V_3 ;
int V_13 = 0 ;
T_3 V_108 ;
if ( V_3 -> V_70 . V_71 . V_72 == V_73 ) {
V_108 = V_94 -> V_109 ;
snprintf ( V_94 -> V_110 , V_111 , L_27 ,
V_108 , V_3 -> V_6 -> V_112 -> V_113 ,
F_71 ( V_3 -> V_6 -> V_114 ) , V_94 -> V_115 ) ;
V_13 = F_72 ( V_3 -> V_70 . V_74 [ V_108 ] . V_116 ,
F_65 , 0 , V_94 -> V_110 , V_94 -> V_106 ) ;
if ( ! V_13 )
F_45 ( V_94 , ( V_107 | V_117 ) ,
L_28 ) ;
} else {
unsigned long V_118 = 0 ;
snprintf ( V_3 -> V_110 , V_111 , L_29 ,
V_3 -> V_6 -> V_112 -> V_113 , F_71 ( V_3 -> V_6 -> V_114 ) ,
F_73 ( V_3 -> V_6 -> V_114 ) ) ;
if ( V_3 -> V_70 . V_71 . V_72 == V_87 )
V_118 |= V_119 ;
V_13 = F_72 ( V_3 -> V_6 -> V_26 , F_67 ,
V_118 , V_3 -> V_110 , V_3 ) ;
}
return V_13 ;
}
static void F_74 ( struct V_2 * V_3 )
{
int V_78 ;
if ( V_3 -> V_70 . V_71 . V_72 == V_73 ) {
F_75 (cdev, i) {
if ( ! V_3 -> V_39 [ V_78 ] . V_120 )
break;
F_76 ( V_3 -> V_70 . V_74 [ V_78 ] . V_116 ) ;
F_77 ( V_3 -> V_70 . V_74 [ V_78 ] . V_116 ,
V_3 -> V_39 [ V_78 ] . V_106 ) ;
}
} else {
if ( F_35 ( V_3 ) -> V_120 )
F_77 ( V_3 -> V_6 -> V_26 , V_3 ) ;
}
F_78 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_78 , V_13 ;
V_13 = F_80 ( V_3 ) ;
for ( V_78 = 0 ; V_78 < V_3 -> V_34 ; V_78 ++ ) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
if ( V_121 -> V_122 ) {
F_81 ( V_121 -> V_106 ) ;
V_121 -> V_122 = false ;
F_45 ( V_3 , V_123 ,
L_30 ,
V_78 , V_121 -> V_106 ) ;
}
}
return V_13 ;
}
static int F_82 ( struct V_2 * V_3 )
{
int V_13 ;
V_13 = F_83 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_84 ( V_3 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_13 ;
V_13 = F_86 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_49 ( V_3 , L_31 ) ;
F_87 ( V_3 ) ;
return V_13 ;
}
static int F_88 ( struct V_2 * V_3 , T_7 V_79 )
{
int V_124 = 0 ;
V_3 -> V_70 . V_125 = V_79 ? true : false ;
if ( V_3 -> V_70 . V_71 . V_72 != V_73 )
V_124 = V_3 -> V_34 * 63 ;
else if ( V_3 -> V_70 . V_126 )
V_124 = V_3 -> V_70 . V_126 ;
if ( ! V_124 )
return - V_27 ;
return F_89 ( int , V_79 , V_124 ) ;
}
static int F_90 ( struct V_2 * V_3 , struct V_127 * V_128 )
{
memset ( V_128 , 0 , sizeof( struct V_127 ) ) ;
if ( ! V_3 -> V_70 . V_125 ) {
F_49 ( V_3 ,
L_32 ) ;
return - V_88 ;
}
if ( V_3 -> V_70 . V_71 . V_72 == V_73 ) {
int V_129 = V_3 -> V_70 . V_130 ;
V_128 -> V_131 = V_3 -> V_70 . V_126 ;
V_128 -> V_132 = & V_3 -> V_70 . V_74 [ V_129 ] ;
}
return 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
enum V_133 V_72 )
{
struct V_134 V_135 ;
int V_13 ;
int V_78 ;
if ( ( V_72 == V_75 ) && ( V_3 -> V_34 > 1 ) ) {
F_9 ( V_3 , L_33 ) ;
return - V_88 ;
}
memset ( & V_3 -> V_70 , 0 , sizeof( struct V_77 ) ) ;
V_3 -> V_70 . V_80 . V_72 = V_72 ;
F_75 (cdev, i) {
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
F_92 ( & V_3 -> V_39 [ V_78 ] , & V_135 ) ;
V_3 -> V_70 . V_80 . V_81 += V_135 . V_136 ;
V_3 -> V_70 . V_80 . V_81 ++ ;
}
V_3 -> V_70 . V_80 . V_83 = V_3 -> V_34 * 2 ;
V_13 = F_59 ( V_3 , false ) ;
if ( V_13 ) {
F_48 ( V_3 , L_34 ) ;
return V_13 ;
}
V_3 -> V_70 . V_130 = V_3 -> V_34 ;
V_3 -> V_70 . V_126 = V_3 -> V_70 . V_71 . V_81 -
V_3 -> V_34 ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
int V_13 ;
memset ( & V_3 -> V_70 , 0 , sizeof( struct V_77 ) ) ;
V_3 -> V_70 . V_80 . V_72 = V_73 ;
F_94 ( F_35 ( V_3 ) ,
& V_3 -> V_70 . V_80 . V_81 ) ;
if ( V_3 -> V_34 > 1 ) {
T_3 V_137 = 0 ;
F_94 ( & V_3 -> V_39 [ 1 ] , & V_137 ) ;
V_3 -> V_70 . V_80 . V_81 += V_137 ;
}
V_3 -> V_70 . V_80 . V_83 = V_3 -> V_34 ;
V_13 = F_59 ( V_3 , true ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_70 . V_130 = 0 ;
V_3 -> V_70 . V_126 = V_3 -> V_70 . V_71 . V_81 ;
return 0 ;
}
T_8 F_95 ( struct V_93 * V_121 , T_8 V_138 ,
T_3 * V_139 , T_8 V_140 , T_3 * V_141 )
{
int V_13 ;
V_121 -> V_142 -> V_143 = V_139 ;
V_121 -> V_142 -> V_144 = V_138 ;
V_121 -> V_142 -> V_145 = V_141 ;
V_121 -> V_142 -> V_146 = V_140 ;
V_13 = F_96 ( V_121 -> V_142 , V_147 ) ;
if ( V_13 != V_148 ) {
F_45 ( V_121 , V_60 , L_35 ,
V_13 ) ;
return 0 ;
}
V_13 = F_97 ( V_121 -> V_142 , V_149 ) ;
F_98 ( V_121 -> V_142 ) ;
if ( V_13 != V_148 && V_13 != V_150 ) {
F_45 ( V_121 , V_60 , L_36 ,
V_121 -> V_142 -> V_151 , V_13 ) ;
return 0 ;
}
return V_121 -> V_142 -> V_152 / 4 ;
}
static int F_99 ( struct V_2 * V_3 )
{
int V_78 ;
void * V_153 ;
F_75 (cdev, i) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
V_121 -> V_142 = F_42 ( sizeof( * V_121 -> V_142 ) , V_58 ) ;
if ( ! V_121 -> V_142 )
return - V_27 ;
V_153 = F_100 ( F_101 () ) ;
if ( ! V_153 )
return - V_27 ;
V_121 -> V_142 -> V_153 = V_153 ;
}
return 0 ;
}
static void F_102 ( struct V_2 * V_3 )
{
int V_78 ;
F_75 (cdev, i) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
if ( ! V_121 -> V_142 )
return;
F_103 ( V_121 -> V_142 -> V_153 ) ;
F_40 ( V_121 -> V_142 ) ;
}
}
static void F_104 ( struct V_2 * V_3 ,
struct V_154 * V_62 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_3 -> V_34 ; V_78 ++ ) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
V_121 -> V_155 = * V_62 ;
}
}
static int F_105 ( struct V_2 * V_3 ,
struct V_156 * V_62 )
{
struct V_157 V_158 ;
struct V_159 V_160 ;
const T_3 * V_161 = NULL ;
struct V_93 * V_94 ;
int V_13 = - V_88 ;
if ( F_106 ( V_3 ) )
goto V_162;
if ( F_18 ( V_3 ) ) {
V_13 = F_107 ( & V_3 -> V_163 , V_164 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_37 ,
V_164 ) ;
goto V_162;
}
}
V_13 = F_85 ( V_3 ) ;
if ( V_13 )
goto V_162;
if ( F_18 ( V_3 ) )
V_13 = F_91 ( V_3 , V_62 -> V_72 ) ;
else
V_13 = F_93 ( V_3 ) ;
if ( V_13 )
goto V_16;
if ( F_18 ( V_3 ) ) {
V_13 = F_99 ( V_3 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_38 ) ;
goto V_20;
}
V_161 = V_3 -> V_163 -> V_161 + sizeof( T_8 ) ;
}
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_158 . V_165 |= 1 << V_166 |
1 << V_167 |
1 << V_168 |
1 << V_169 |
1 << V_170 ;
V_158 . V_171 = V_172 ;
V_158 . V_173 = V_172 ;
V_158 . V_174 = V_172 ;
V_13 = F_108 ( V_3 , & V_158 , true ,
V_3 -> V_70 . V_71 . V_72 ,
true , V_161 ) ;
if ( V_13 )
goto V_20;
F_49 ( V_3 ,
L_39 ) ;
if ( F_18 ( V_3 ) ) {
V_94 = F_35 ( V_3 ) ;
V_160 . V_1 = ( V_62 -> V_175 << 24 ) |
( V_62 -> V_176 << 16 ) |
( V_62 -> V_177 << 8 ) |
( V_62 -> V_178 ) ;
F_109 ( V_160 . V_110 , V_62 -> V_110 ,
V_179 - 4 ) ;
V_13 = F_110 ( V_94 , V_94 -> V_180 ,
& V_160 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_40 ) ;
return V_13 ;
}
}
F_111 ( V_3 ) ;
return 0 ;
V_20:
F_112 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_74 ( V_3 ) ;
F_102 ( V_3 ) ;
F_53 ( V_3 ) ;
V_16:
F_84 ( V_3 ) ;
V_162:
if ( F_18 ( V_3 ) )
F_113 ( V_3 -> V_163 ) ;
F_114 ( V_3 , false ) ;
return V_13 ;
}
static int F_115 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
if ( F_18 ( V_3 ) ) {
F_102 ( V_3 ) ;
if ( F_116 ( V_3 ) )
F_117 ( V_3 , true ) ;
F_79 ( V_3 ) ;
F_74 ( V_3 ) ;
}
F_53 ( V_3 ) ;
F_82 ( V_3 ) ;
F_114 ( V_3 , true ) ;
if ( F_18 ( V_3 ) )
F_113 ( V_3 -> V_163 ) ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 , char V_110 [ V_111 ] ,
char V_181 [ V_182 ] )
{
int V_78 ;
memcpy ( V_3 -> V_110 , V_110 , V_111 ) ;
F_75 (cdev, i)
snprintf ( V_3 -> V_39 [ V_78 ] . V_110 , V_111 , L_41 , V_110 , V_78 ) ;
memcpy ( V_3 -> V_181 , V_181 , V_182 ) ;
V_3 -> V_183 = V_184 ;
}
static T_8 F_119 ( struct V_2 * V_3 ,
struct V_185 * V_186 ,
void * V_187 ,
T_9 V_188 , T_7 V_189 ,
enum V_190 type )
{
struct V_93 * V_121 ;
int V_191 ;
T_7 V_192 ;
T_3 V_193 ;
T_8 V_13 ;
if ( type == V_194 )
V_193 = V_3 -> V_34 ;
else
V_193 = 1 ;
V_191 = V_189 % V_193 ;
V_121 = & V_3 -> V_39 [ V_191 ] ;
V_192 = V_189 / V_193 ;
F_45 ( V_3 , V_107 ,
L_42 ,
V_191 , V_192 , V_189 ) ;
V_13 = F_120 ( V_121 , V_121 -> V_180 , V_186 ,
V_187 , V_188 , V_192 ) ;
return V_13 ;
}
static T_8 F_121 ( struct V_2 * V_3 ,
struct V_185 * V_186 ,
T_7 V_189 )
{
struct V_93 * V_121 ;
int V_191 ;
T_7 V_192 ;
T_8 V_13 ;
V_191 = V_189 % V_3 -> V_34 ;
V_121 = & V_3 -> V_39 [ V_191 ] ;
V_192 = V_189 / V_3 -> V_34 ;
F_45 ( V_3 , V_107 ,
L_42 ,
V_191 , V_192 , V_189 ) ;
V_13 = F_122 ( V_121 , V_186 , V_192 ) ;
return V_13 ;
}
static bool F_123 ( struct V_2 * V_3 )
{
return true ;
}
static int F_124 ( struct V_2 * V_3 , struct V_195 * V_62 )
{
struct V_93 * V_94 ;
struct V_196 * V_197 ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
if ( F_125 ( V_3 ) )
return 0 ;
V_94 = & V_3 -> V_39 [ 0 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_198 ;
V_197 = F_126 ( V_94 ) ;
if ( V_62 -> V_199 & V_200 )
V_197 -> V_201 . V_202 = V_62 -> V_202 ;
if ( V_62 -> V_199 & V_203 ) {
V_197 -> V_201 . V_204 = 0 ;
if ( ( V_62 -> V_205 & V_206 ) ||
( V_62 -> V_205 & V_207 ) )
V_197 -> V_201 . V_204 |=
V_208 ;
if ( V_62 -> V_205 & V_209 )
V_197 -> V_201 . V_204 |=
V_210 ;
if ( V_62 -> V_205 & V_211 )
V_197 -> V_201 . V_204 |=
V_212 ;
if ( V_62 -> V_205 & 0 )
V_197 -> V_201 . V_204 |=
V_213 ;
if ( V_62 -> V_205 & 0 )
V_197 -> V_201 . V_204 |=
V_214 ;
}
if ( V_62 -> V_199 & V_215 )
V_197 -> V_201 . V_216 = V_62 -> V_216 ;
if ( V_62 -> V_199 & V_217 ) {
if ( V_62 -> V_218 & V_219 )
V_197 -> V_220 . V_202 = true ;
else
V_197 -> V_220 . V_202 = false ;
if ( V_62 -> V_218 & V_221 )
V_197 -> V_220 . V_222 = true ;
else
V_197 -> V_220 . V_222 = false ;
if ( V_62 -> V_218 & V_223 )
V_197 -> V_220 . V_224 = true ;
else
V_197 -> V_220 . V_224 = false ;
}
if ( V_62 -> V_199 & V_225 ) {
switch ( V_62 -> V_226 ) {
case V_227 :
V_197 -> V_226 = V_228 ;
break;
case V_229 :
V_197 -> V_226 = V_230 ;
break;
case V_231 :
V_197 -> V_226 = V_232 ;
break;
case V_233 :
V_197 -> V_226 = V_234 ;
break;
default:
V_197 -> V_226 = V_235 ;
break;
}
}
V_13 = F_127 ( V_94 , V_33 , V_62 -> V_236 ) ;
F_38 ( V_94 , V_33 ) ;
return V_13 ;
}
static int F_128 ( T_8 V_237 )
{
int V_238 ;
switch ( V_237 ) {
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_238 = V_244 ;
break;
case V_245 :
V_238 = V_246 ;
break;
case V_247 :
V_238 = V_248 ;
break;
case V_249 :
V_238 = V_250 ;
break;
case V_251 :
default:
V_238 = V_252 ;
break;
}
return V_238 ;
}
static int F_129 ( struct V_93 * V_94 ,
struct V_196 * V_62 ,
struct V_253 * V_254 ,
struct V_255 * V_256 )
{
void * V_257 ;
if ( ! F_18 ( V_94 -> V_3 ) ) {
F_130 ( V_94 , V_62 ) ;
F_131 ( V_94 , V_254 ) ;
F_132 ( V_94 , V_256 ) ;
return 0 ;
}
V_257 = F_126 ( V_94 ) ;
if ( ! V_257 )
return - V_258 ;
memcpy ( V_62 , V_257 , sizeof( * V_62 ) ) ;
V_257 = F_133 ( V_94 ) ;
if ( ! V_257 )
return - V_258 ;
memcpy ( V_254 , V_257 , sizeof( * V_254 ) ) ;
V_257 = F_134 ( V_94 ) ;
if ( ! V_257 )
return - V_258 ;
memcpy ( V_256 , V_257 , sizeof( * V_256 ) ) ;
return 0 ;
}
static void F_135 ( struct V_93 * V_94 ,
struct V_259 * V_260 )
{
struct V_196 V_62 ;
struct V_253 V_254 ;
struct V_255 V_256 ;
T_8 V_237 ;
memset ( V_260 , 0 , sizeof( * V_260 ) ) ;
if ( F_129 ( V_94 , & V_62 , & V_254 , & V_256 ) ) {
F_136 ( & V_94 -> V_3 -> V_6 -> V_5 , L_43 ) ;
return;
}
if ( V_254 . V_236 )
V_260 -> V_236 = true ;
V_260 -> V_261 = V_262 ;
if ( V_62 . V_201 . V_202 )
V_260 -> V_261 |= V_263 ;
if ( V_62 . V_220 . V_202 ||
( V_62 . V_220 . V_222 && V_62 . V_220 . V_224 ) )
V_260 -> V_261 |= V_264 ;
if ( V_62 . V_220 . V_202 || V_62 . V_220 . V_222 ||
V_62 . V_220 . V_224 )
V_260 -> V_261 |= V_265 ;
V_260 -> V_266 = V_260 -> V_261 ;
if ( V_62 . V_201 . V_204 &
V_208 )
V_260 -> V_266 |= V_206 |
V_207 ;
if ( V_62 . V_201 . V_204 &
V_210 )
V_260 -> V_266 |= V_209 ;
if ( V_62 . V_201 . V_204 &
V_212 )
V_260 -> V_266 |= V_211 ;
if ( V_62 . V_201 . V_204 &
V_213 )
V_260 -> V_266 |= 0 ;
if ( V_62 . V_201 . V_204 &
V_214 )
V_260 -> V_266 |= 0 ;
if ( V_256 . V_267 &
V_208 )
V_260 -> V_261 |= V_206 |
V_207 ;
if ( V_256 . V_267 &
V_210 )
V_260 -> V_261 |= V_209 ;
if ( V_256 . V_267 &
V_212 )
V_260 -> V_261 |= V_211 ;
if ( V_256 . V_267 &
V_213 )
V_260 -> V_261 |= 0 ;
if ( V_256 . V_267 &
V_214 )
V_260 -> V_261 |= 0 ;
if ( V_254 . V_236 )
V_260 -> V_201 = V_254 . V_201 ;
V_260 -> V_268 = V_269 ;
F_137 ( V_94 -> V_3 , & V_237 ) ;
V_260 -> V_270 = F_128 ( V_237 ) ;
V_260 -> V_202 = V_62 . V_201 . V_202 ;
if ( V_62 . V_220 . V_202 )
V_260 -> V_218 |= V_219 ;
if ( V_62 . V_220 . V_222 )
V_260 -> V_218 |= V_221 ;
if ( V_62 . V_220 . V_224 )
V_260 -> V_218 |= V_223 ;
if ( V_254 . V_271 &
V_272 )
V_260 -> V_273 |= V_206 ;
if ( V_254 . V_271 &
V_274 )
V_260 -> V_273 |= V_207 ;
if ( V_254 . V_271 &
V_275 )
V_260 -> V_273 |= V_209 ;
if ( V_254 . V_271 &
V_276 )
V_260 -> V_273 |= V_211 ;
if ( V_254 . V_271 &
V_277 )
V_260 -> V_273 |= 0 ;
if ( V_254 . V_271 &
V_278 )
V_260 -> V_273 |= 0 ;
if ( V_254 . V_279 )
V_260 -> V_273 |= V_263 ;
if ( V_254 . V_280 )
V_260 -> V_273 |= V_265 ;
if ( V_254 . V_280 == V_281 ||
V_254 . V_280 == V_282 )
V_260 -> V_273 |= V_264 ;
}
static void F_138 ( struct V_2 * V_3 ,
struct V_259 * V_260 )
{
int V_78 ;
F_135 ( & V_3 -> V_39 [ 0 ] , V_260 ) ;
F_75 (cdev, i)
F_139 ( & V_3 -> V_39 [ V_78 ] ) ;
}
void F_140 ( struct V_93 * V_94 )
{
void * V_283 = V_94 -> V_3 -> V_284 ;
struct V_285 * V_286 = V_94 -> V_3 -> V_287 . V_288 ;
struct V_259 V_260 ;
F_135 ( V_94 , & V_260 ) ;
F_139 ( V_94 ) ;
if ( F_141 ( V_94 ) && V_283 )
V_286 -> V_289 ( V_283 , & V_260 ) ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_93 * V_94 ;
struct V_32 * V_33 ;
int V_78 , V_13 ;
if ( F_125 ( V_3 ) )
return 0 ;
F_75 (cdev, i) {
V_94 = & V_3 -> V_39 [ V_78 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 ) {
F_9 ( V_94 , L_44 ) ;
return - V_198 ;
}
V_13 = F_143 ( V_94 , V_33 ) ;
if ( V_13 )
return V_13 ;
F_38 ( V_94 , V_33 ) ;
}
return 0 ;
}
static void F_144 ( struct V_2 * V_3 , T_7 * V_290 , T_7 * V_291 )
{
* V_290 = V_3 -> V_292 ;
* V_291 = V_3 -> V_293 ;
}
static int F_145 ( struct V_2 * V_3 , T_7 V_290 , T_7 V_291 ,
T_3 V_294 , T_7 V_189 )
{
struct V_93 * V_94 ;
struct V_32 * V_33 ;
int V_191 ;
int V_104 = 0 ;
V_191 = V_294 % V_3 -> V_34 ;
V_94 = & V_3 -> V_39 [ V_191 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_295 ;
V_104 = F_146 ( V_94 , V_33 , V_290 ,
V_294 / V_3 -> V_34 , V_189 ) ;
if ( V_104 )
goto V_71;
V_104 = F_147 ( V_94 , V_33 , V_291 ,
V_294 / V_3 -> V_34 , V_189 ) ;
V_71:
F_38 ( V_94 , V_33 ) ;
return V_104 ;
}
static int F_148 ( struct V_2 * V_3 , enum V_296 V_297 )
{
struct V_93 * V_94 = F_35 ( V_3 ) ;
struct V_32 * V_33 ;
int V_104 = 0 ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_295 ;
V_104 = F_149 ( V_94 , V_33 , V_297 ) ;
F_38 ( V_94 , V_33 ) ;
return V_104 ;
}
