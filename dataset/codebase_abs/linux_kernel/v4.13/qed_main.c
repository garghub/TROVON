static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 ) ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( L_2 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 -> V_5 ;
if ( F_6 ( V_5 , F_7 ( 64 ) ) == 0 ) {
if ( F_8 ( V_5 , F_7 ( 64 ) ) != 0 ) {
F_9 ( V_3 ,
L_3 ) ;
return - V_7 ;
}
} else if ( F_6 ( V_5 , F_7 ( 32 ) ) != 0 ) {
F_9 ( V_3 , L_4 ) ;
return - V_7 ;
}
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_8 * V_6 = V_3 -> V_6 ;
if ( V_3 -> V_9 && V_3 -> V_10 )
F_11 ( V_3 -> V_9 ) ;
if ( V_3 -> V_11 )
F_11 ( V_3 -> V_11 ) ;
if ( F_12 ( & V_6 -> V_12 ) == 1 )
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_8 * V_6 )
{
T_3 V_13 ;
int V_14 ;
V_3 -> V_6 = V_6 ;
V_14 = F_16 ( V_6 ) ;
if ( V_14 ) {
F_9 ( V_3 , L_5 ) ;
goto V_15;
}
if ( ! ( F_17 ( V_6 , 0 ) & V_16 ) ) {
F_9 ( V_3 , L_6 ) ;
V_14 = - V_7 ;
goto V_17;
}
if ( F_18 ( V_3 ) && ! ( F_17 ( V_6 , 2 ) & V_16 ) ) {
F_9 ( V_3 , L_7 ) ;
V_14 = - V_7 ;
goto V_17;
}
if ( F_12 ( & V_6 -> V_12 ) == 1 ) {
V_14 = F_19 ( V_6 , L_8 ) ;
if ( V_14 ) {
F_9 ( V_3 ,
L_9 ) ;
goto V_17;
}
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
}
F_22 ( V_6 , V_18 , & V_13 ) ;
if ( V_13 == V_19 ) {
F_9 ( V_3 ,
L_10 ,
V_13 ) ;
V_14 = - V_20 ;
goto V_21;
}
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_3 , L_11 ) ;
V_14 = - V_7 ;
goto V_21;
}
V_3 -> V_22 . V_23 = F_24 ( V_6 , V_24 ) ;
if ( F_18 ( V_3 ) && ! V_3 -> V_22 . V_23 )
F_9 ( V_3 , L_12 ) ;
V_14 = F_5 ( V_3 ) ;
if ( V_14 )
goto V_21;
V_3 -> V_22 . V_25 = F_25 ( V_6 , 0 ) ;
V_3 -> V_22 . V_26 = F_26 ( V_6 , 0 ) ;
V_3 -> V_22 . V_27 = V_6 -> V_27 ;
V_3 -> V_11 = F_27 ( V_6 , 0 ) ;
if ( ! V_3 -> V_11 ) {
F_9 ( V_3 , L_13 ) ;
V_14 = - V_28 ;
goto V_21;
}
V_3 -> V_29 = F_25 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_10 = F_28 ( V_3 -> V_6 , 2 ) ;
if ( ! V_3 -> V_10 ) {
if ( F_18 ( V_3 ) ) {
F_9 ( V_3 , L_14 ) ;
return - V_30 ;
} else {
return 0 ;
}
}
V_3 -> V_9 = F_29 ( V_3 -> V_29 , V_3 -> V_10 ) ;
if ( ! V_3 -> V_9 ) {
F_9 ( V_3 , L_15 ) ;
return - V_28 ;
}
return 0 ;
V_21:
F_13 ( V_6 ) ;
V_17:
F_14 ( V_6 ) ;
V_15:
return V_14 ;
}
int F_30 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = F_31 ( V_3 ) ;
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_37 * V_38 = & V_3 -> V_39 ;
struct V_40 * V_41 ;
memset ( V_32 , 0 , sizeof( struct V_31 ) ) ;
if ( V_38 -> V_42 . V_43 == V_44 &&
V_38 -> V_42 . V_45 )
V_32 -> V_46 = true ;
if ( V_38 -> V_47 . V_45 && V_38 -> V_48 . V_45 &&
V_38 -> V_47 . V_43 == V_44 &&
V_38 -> V_48 . V_43 == V_44 )
V_32 -> V_49 = true ;
if ( V_38 -> V_50 . V_45 && V_38 -> V_51 . V_45 &&
V_38 -> V_50 . V_43 == V_44 &&
V_38 -> V_51 . V_43 == V_44 )
V_32 -> V_52 = true ;
V_32 -> V_53 = V_3 -> V_53 ;
V_32 -> V_54 = V_3 -> V_22 . V_25 ;
V_32 -> V_55 = V_3 -> V_22 . V_26 ;
V_32 -> V_56 = V_3 -> V_22 . V_27 ;
V_32 -> V_57 = F_32 ( V_34 ) ;
V_32 -> V_58 = F_33 ( & V_3 -> V_59 [ 0 ] ) ;
V_32 -> V_60 = V_3 -> type ;
F_34 ( V_32 -> V_61 , V_36 -> V_62 ) ;
if ( F_18 ( V_3 ) ) {
V_32 -> V_63 = V_64 ;
V_32 -> V_65 = V_66 ;
V_32 -> V_67 = V_68 ;
V_32 -> V_69 = V_70 ;
V_32 -> V_71 = V_3 -> V_71 ;
V_32 -> V_72 = true ;
if ( V_36 -> V_73 == V_74 )
V_32 -> V_75 = true ;
V_32 -> V_76 = F_31 ( V_3 ) -> V_76 ;
} else {
F_35 ( & V_3 -> V_59 [ 0 ] , & V_32 -> V_63 ,
& V_32 -> V_65 , & V_32 -> V_67 ,
& V_32 -> V_69 ) ;
}
if ( F_18 ( V_3 ) ) {
V_41 = F_36 ( F_31 ( V_3 ) ) ;
if ( V_41 ) {
F_37 ( F_31 ( V_3 ) , V_41 ,
& V_32 -> V_77 , NULL ) ;
F_38 ( F_31 ( V_3 ) , V_41 ,
& V_32 -> V_78 ) ;
F_39 ( F_31 ( V_3 ) , V_41 ,
& V_32 -> V_79 ) ;
F_40 ( F_31 ( V_3 ) , V_41 ) ;
}
} else {
F_37 ( F_31 ( V_3 ) , NULL ,
& V_32 -> V_77 , NULL ) ;
}
V_32 -> V_80 = V_36 -> V_80 ;
return 0 ;
}
static void F_41 ( struct V_2 * V_3 )
{
F_42 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_43 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_44 ( sizeof( * V_3 ) , V_81 ) ;
if ( ! V_3 )
return V_3 ;
F_45 ( V_3 ) ;
return V_3 ;
}
static int F_46 ( struct V_2 * V_3 , T_4 V_82 )
{
if ( ! V_3 )
return - V_20 ;
F_47 ( V_3 , V_83 , L_16 ) ;
return 0 ;
}
static struct V_2 * F_48 ( struct V_8 * V_6 ,
struct V_84 * V_85 )
{
struct V_2 * V_3 ;
int V_14 ;
V_3 = F_43 ( V_6 ) ;
if ( ! V_3 )
goto V_15;
V_3 -> V_86 = V_87 ;
V_3 -> V_88 = V_85 -> V_88 ;
if ( V_85 -> V_89 )
V_3 -> V_90 = true ;
F_49 ( V_3 , V_85 -> V_91 , V_85 -> V_92 ) ;
V_14 = F_15 ( V_3 , V_6 ) ;
if ( V_14 ) {
F_50 ( V_3 , L_17 ) ;
goto V_17;
}
F_51 ( V_3 , L_18 ) ;
V_14 = F_52 ( V_3 , V_93 ) ;
if ( V_14 ) {
F_50 ( V_3 , L_19 ) ;
goto V_21;
}
F_51 ( V_3 , L_20 ) ;
return V_3 ;
V_21:
F_10 ( V_3 ) ;
V_17:
F_41 ( V_3 ) ;
V_15:
return NULL ;
}
static void F_53 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_54 ( V_3 ) ;
F_10 ( V_3 ) ;
F_46 ( V_3 , V_94 ) ;
F_41 ( V_3 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
if ( V_3 -> V_95 . V_96 . V_97 == V_98 ) {
F_56 ( V_3 -> V_6 ) ;
F_42 ( V_3 -> V_95 . V_99 ) ;
} else if ( V_3 -> V_95 . V_96 . V_97 == V_100 ) {
F_57 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_95 . V_96 , 0 , sizeof( struct V_101 ) ) ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_102 * V_95 )
{
int V_103 , V_14 , V_104 ;
V_104 = V_95 -> V_105 . V_106 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ )
V_95 -> V_99 [ V_103 ] . V_107 = V_103 ;
V_14 = F_59 ( V_3 -> V_6 , V_95 -> V_99 ,
V_95 -> V_105 . V_108 , V_104 ) ;
if ( V_14 < V_104 && V_14 >= V_95 -> V_105 . V_108 &&
( V_14 % V_3 -> V_53 ) ) {
F_56 ( V_3 -> V_6 ) ;
V_104 = ( V_14 / V_3 -> V_53 ) * V_3 -> V_53 ;
F_9 ( V_3 ,
L_21 ,
V_104 , V_95 -> V_105 . V_106 ) ;
V_14 = F_60 ( V_3 -> V_6 , V_95 -> V_99 ,
V_104 ) ;
if ( ! V_14 )
V_14 = V_104 ;
}
if ( V_14 > 0 ) {
V_95 -> V_96 . V_97 = V_98 ;
V_95 -> V_96 . V_106 = V_14 ;
V_14 = 0 ;
} else {
F_9 ( V_3 ,
L_22 ,
V_104 , V_14 ) ;
}
return V_14 ;
}
static int F_61 ( struct V_2 * V_3 , bool V_109 )
{
struct V_102 * V_95 = & V_3 -> V_95 ;
struct V_110 * V_111 ;
int V_14 = 0 , V_104 ;
switch ( V_95 -> V_105 . V_97 ) {
case V_98 :
V_104 = V_95 -> V_105 . V_106 ;
V_95 -> V_99 = F_62 ( V_104 , sizeof( * V_111 ) , V_81 ) ;
if ( ! V_95 -> V_99 ) {
V_14 = - V_28 ;
goto V_96;
}
V_14 = F_58 ( V_3 , V_95 ) ;
if ( ! V_14 )
goto V_96;
F_9 ( V_3 , L_23 ) ;
F_42 ( V_95 -> V_99 ) ;
if ( V_109 )
goto V_96;
case V_100 :
if ( V_3 -> V_53 == 1 ) {
V_14 = F_63 ( V_3 -> V_6 ) ;
if ( ! V_14 ) {
V_95 -> V_96 . V_97 = V_100 ;
goto V_96;
}
F_9 ( V_3 , L_24 ) ;
if ( V_109 )
goto V_96;
}
case V_112 :
V_95 -> V_96 . V_97 = V_112 ;
V_14 = 0 ;
goto V_96;
default:
F_9 ( V_3 , L_25 ,
V_95 -> V_105 . V_97 ) ;
V_14 = - V_30 ;
}
V_96:
if ( ! V_14 )
F_51 ( V_3 , L_26 ,
V_95 -> V_96 . V_97 == V_112 ?
L_27 : V_95 -> V_96 . V_97 == V_100 ?
L_28 : L_29 ) ;
V_3 -> V_113 = V_114 ;
return V_14 ;
}
static void F_64 ( struct V_2 * V_3 , void * V_115 ,
int V_116 , void (* F_65)( void * ) )
{
struct V_33 * V_117 = & V_3 -> V_59 [ V_116 % V_3 -> V_53 ] ;
int V_118 = V_116 / V_3 -> V_53 ;
V_117 -> V_119 [ V_118 ] . V_120 = F_65 ;
V_117 -> V_119 [ V_118 ] . V_115 = V_115 ;
}
static void F_66 ( struct V_2 * V_3 , int V_116 )
{
struct V_33 * V_117 = & V_3 -> V_59 [ V_116 % V_3 -> V_53 ] ;
int V_118 = V_116 / V_3 -> V_53 ;
memset ( & V_117 -> V_119 [ V_118 ] , 0 ,
sizeof( struct V_121 ) ) ;
}
static T_5 F_67 ( int V_27 , void * V_122 )
{
F_68 ( (struct V_123 * ) V_122 ) ;
return V_124 ;
}
static T_5 F_69 ( int V_27 , void * V_125 )
{
struct V_2 * V_3 = (struct V_2 * ) V_125 ;
struct V_33 * V_117 ;
T_5 V_14 = V_126 ;
T_6 V_127 ;
int V_103 , V_128 ;
for ( V_103 = 0 ; V_103 < V_3 -> V_53 ; V_103 ++ ) {
V_127 = F_70 ( & V_3 -> V_59 [ V_103 ] ) ;
if ( ! V_127 )
continue;
V_117 = & V_3 -> V_59 [ V_103 ] ;
if ( F_71 ( V_127 & 0x1 ) ) {
F_68 ( V_117 -> V_129 ) ;
V_127 &= ~ 0x1 ;
V_14 = V_124 ;
}
for ( V_128 = 0 ; V_128 < 64 ; V_128 ++ ) {
if ( ( 0x2ULL << V_128 ) & V_127 ) {
V_117 -> V_119 [ V_128 ] . V_120 (
V_117 -> V_119 [ V_128 ] . V_115 ) ;
V_127 &= ~ ( 0x2ULL << V_128 ) ;
V_14 = V_124 ;
}
}
if ( F_71 ( V_127 ) )
F_47 ( V_117 , V_130 ,
L_30 ,
V_127 ) ;
}
return V_14 ;
}
int F_72 ( struct V_33 * V_117 )
{
struct V_2 * V_3 = V_117 -> V_3 ;
T_7 V_97 ;
int V_14 = 0 ;
T_3 V_131 ;
V_97 = V_3 -> V_95 . V_96 . V_97 ;
if ( V_97 == V_98 ) {
V_131 = V_117 -> V_132 ;
snprintf ( V_117 -> V_133 , V_134 , L_31 ,
V_131 , V_3 -> V_6 -> V_135 -> V_136 ,
F_73 ( V_3 -> V_6 -> V_137 ) , V_117 -> V_76 ) ;
V_14 = F_74 ( V_3 -> V_95 . V_99 [ V_131 ] . V_138 ,
F_67 , 0 , V_117 -> V_133 , V_117 -> V_129 ) ;
} else {
unsigned long V_139 = 0 ;
snprintf ( V_3 -> V_133 , V_134 , L_32 ,
V_3 -> V_6 -> V_135 -> V_136 , F_73 ( V_3 -> V_6 -> V_137 ) ,
F_75 ( V_3 -> V_6 -> V_137 ) ) ;
if ( V_3 -> V_95 . V_96 . V_97 == V_112 )
V_139 |= V_140 ;
V_14 = F_74 ( V_3 -> V_6 -> V_27 , F_69 ,
V_139 , V_3 -> V_133 , V_3 ) ;
}
if ( V_14 )
F_9 ( V_3 , L_33 , V_14 ) ;
else
F_47 ( V_117 , ( V_130 | V_141 ) ,
L_34 ,
( V_97 == V_98 ) ? L_35 : L_36 ) ;
return V_14 ;
}
static void F_76 ( struct V_33 * V_34 )
{
if ( V_34 -> V_142 ) {
F_77 ( V_34 -> V_129 ) ;
F_78 ( V_34 -> V_129 ) ;
}
}
void F_79 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = V_34 -> V_3 ;
T_3 V_131 = V_34 -> V_132 ;
T_7 V_97 ;
V_97 = V_3 -> V_95 . V_96 . V_97 ;
if ( V_97 == V_98 )
F_80 ( V_3 -> V_95 . V_99 [ V_131 ] . V_138 ) ;
else
F_80 ( V_3 -> V_6 -> V_27 ) ;
F_76 ( V_34 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
int V_103 ;
if ( V_3 -> V_95 . V_96 . V_97 == V_98 ) {
F_82 (cdev, i) {
if ( ! V_3 -> V_59 [ V_103 ] . V_143 )
break;
F_80 ( V_3 -> V_95 . V_99 [ V_103 ] . V_138 ) ;
F_83 ( V_3 -> V_95 . V_99 [ V_103 ] . V_138 ,
V_3 -> V_59 [ V_103 ] . V_129 ) ;
}
} else {
if ( F_31 ( V_3 ) -> V_143 )
F_83 ( V_3 -> V_6 -> V_27 , V_3 ) ;
}
F_84 ( V_3 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
int V_103 , V_14 ;
V_14 = F_86 ( V_3 ) ;
for ( V_103 = 0 ; V_103 < V_3 -> V_53 ; V_103 ++ ) {
struct V_33 * V_34 = & V_3 -> V_59 [ V_103 ] ;
if ( V_34 -> V_142 ) {
F_77 ( V_34 -> V_129 ) ;
V_34 -> V_142 = false ;
F_47 ( V_3 , V_144 ,
L_37 ,
V_103 , V_34 -> V_129 ) ;
}
}
F_87 ( V_3 ) ;
return V_14 ;
}
static int F_88 ( struct V_2 * V_3 )
{
int V_14 , V_103 ;
if ( F_31 ( V_3 ) -> V_36 . V_145 != V_146 ) {
for ( V_103 = 0 ; V_103 < V_3 -> V_53 ; V_103 ++ ) {
struct V_33 * V_34 = & V_3 -> V_59 [ V_103 ] ;
V_34 -> V_147 = true ;
}
}
V_14 = F_89 ( V_3 ) ;
if ( V_14 )
return V_14 ;
F_51 ( V_3 , L_38 ) ;
F_90 ( V_3 ) ;
return V_14 ;
}
static int F_91 ( struct V_2 * V_3 , T_8 V_104 )
{
int V_148 = 0 ;
V_3 -> V_95 . V_149 = V_104 ? true : false ;
if ( V_3 -> V_95 . V_96 . V_97 != V_98 )
V_148 = V_3 -> V_53 * 63 ;
else if ( V_3 -> V_95 . V_150 )
V_148 = V_3 -> V_95 . V_150 ;
if ( ! V_148 )
return - V_28 ;
return F_92 ( int , V_104 , V_148 ) ;
}
static int F_93 ( struct V_2 * V_3 , struct V_151 * V_152 )
{
memset ( V_152 , 0 , sizeof( struct V_151 ) ) ;
if ( ! V_3 -> V_95 . V_149 ) {
F_51 ( V_3 ,
L_39 ) ;
return - V_30 ;
}
if ( V_3 -> V_95 . V_96 . V_97 == V_98 ) {
int V_153 = V_3 -> V_95 . V_154 ;
V_152 -> V_155 = V_3 -> V_95 . V_150 ;
V_152 -> V_156 = & V_3 -> V_95 . V_99 [ V_153 ] ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 ,
enum V_157 V_97 )
{
struct V_158 V_159 ;
int V_160 = 0 ;
int V_14 ;
int V_103 ;
if ( ( V_97 == V_100 ) && ( V_3 -> V_53 > 1 ) ) {
F_9 ( V_3 , L_40 ) ;
return - V_30 ;
}
memset ( & V_3 -> V_95 , 0 , sizeof( struct V_102 ) ) ;
V_3 -> V_95 . V_105 . V_97 = V_97 ;
F_82 (cdev, i) {
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
F_95 ( & V_3 -> V_59 [ V_103 ] , & V_159 ) ;
V_3 -> V_95 . V_105 . V_106 += V_159 . V_104 ;
V_3 -> V_95 . V_105 . V_106 ++ ;
}
V_3 -> V_95 . V_105 . V_108 = V_3 -> V_53 * 2 ;
V_14 = F_61 ( V_3 , false ) ;
if ( V_14 ) {
F_50 ( V_3 , L_41 ) ;
return V_14 ;
}
V_3 -> V_95 . V_154 = V_3 -> V_53 ;
V_3 -> V_95 . V_150 = V_3 -> V_95 . V_96 . V_106 -
V_3 -> V_53 ;
if ( ! F_96 ( V_161 ) ||
! F_32 ( F_31 ( V_3 ) ) )
return 0 ;
F_82 (cdev, i)
V_160 += F_97 ( & V_3 -> V_59 [ V_103 ] , V_162 ) ;
F_47 ( V_3 , V_163 ,
L_42 ,
V_3 -> V_95 . V_150 , V_160 ) ;
if ( V_3 -> V_95 . V_150 > V_160 ) {
V_3 -> V_95 . V_164 =
( V_3 -> V_95 . V_150 - V_160 )
/ V_3 -> V_53 ;
V_3 -> V_95 . V_165 =
V_3 -> V_95 . V_154 + V_160 ;
V_3 -> V_95 . V_150 = V_160 ;
} else {
V_3 -> V_95 . V_164 = 0 ;
}
F_47 ( V_3 , V_163 , L_43 ,
V_3 -> V_95 . V_164 ,
V_3 -> V_95 . V_165 ) ;
return 0 ;
}
static int F_98 ( struct V_2 * V_3 )
{
int V_14 ;
memset ( & V_3 -> V_95 , 0 , sizeof( struct V_102 ) ) ;
V_3 -> V_95 . V_105 . V_97 = V_98 ;
F_99 ( F_31 ( V_3 ) ,
& V_3 -> V_95 . V_105 . V_106 ) ;
if ( V_3 -> V_53 > 1 ) {
T_3 V_166 = 0 ;
F_99 ( & V_3 -> V_59 [ 1 ] , & V_166 ) ;
V_3 -> V_95 . V_105 . V_106 += V_166 ;
}
V_3 -> V_95 . V_105 . V_108 = V_3 -> V_53 ;
V_14 = F_61 ( V_3 , true ) ;
if ( V_14 )
return V_14 ;
V_3 -> V_95 . V_154 = 0 ;
V_3 -> V_95 . V_150 = V_3 -> V_95 . V_96 . V_106 ;
return 0 ;
}
T_7 F_100 ( struct V_33 * V_34 , T_7 V_167 ,
T_3 * V_168 , T_7 V_169 , T_3 * V_170 )
{
int V_14 ;
V_34 -> V_171 -> V_172 = V_168 ;
V_34 -> V_171 -> V_173 = V_167 ;
V_34 -> V_171 -> V_174 = V_170 ;
V_34 -> V_171 -> V_175 = V_169 ;
V_14 = F_101 ( V_34 -> V_171 , V_176 ) ;
if ( V_14 != V_177 ) {
F_47 ( V_34 , V_83 , L_44 ,
V_14 ) ;
return 0 ;
}
V_14 = F_102 ( V_34 -> V_171 , V_178 ) ;
F_103 ( V_34 -> V_171 ) ;
if ( V_14 != V_177 && V_14 != V_179 ) {
F_47 ( V_34 , V_83 , L_45 ,
V_34 -> V_171 -> V_180 , V_14 ) ;
return 0 ;
}
return V_34 -> V_171 -> V_181 / 4 ;
}
static int F_104 ( struct V_2 * V_3 )
{
int V_103 ;
void * V_182 ;
F_82 (cdev, i) {
struct V_33 * V_34 = & V_3 -> V_59 [ V_103 ] ;
V_34 -> V_171 = F_44 ( sizeof( * V_34 -> V_171 ) , V_81 ) ;
if ( ! V_34 -> V_171 )
return - V_28 ;
V_182 = F_105 ( F_106 () ) ;
if ( ! V_182 )
return - V_28 ;
V_34 -> V_171 -> V_182 = V_182 ;
}
return 0 ;
}
static void F_107 ( struct V_2 * V_3 )
{
int V_103 ;
F_82 (cdev, i) {
struct V_33 * V_34 = & V_3 -> V_59 [ V_103 ] ;
if ( ! V_34 -> V_171 )
return;
F_108 ( V_34 -> V_171 -> V_182 ) ;
F_42 ( V_34 -> V_171 ) ;
}
}
static void F_109 ( struct V_2 * V_3 ,
struct V_183 * V_85 )
{
int V_103 ;
if ( F_96 ( V_161 ) ) {
V_85 -> V_184 . V_185 = V_186 ;
V_85 -> V_184 . V_187 = V_188 ;
V_85 -> V_184 . V_189 = V_190 ;
}
if ( V_3 -> V_53 > 1 || F_110 ( V_3 ) )
V_85 -> V_191 . V_192 = 0 ;
if ( F_32 ( F_31 ( V_3 ) ) ) {
T_8 * V_193 ;
V_193 = & V_85 -> V_191 . V_193 ;
* V_193 = F_92 ( T_8 , * V_193 , 192 ) ;
}
for ( V_103 = 0 ; V_103 < V_3 -> V_53 ; V_103 ++ ) {
struct V_33 * V_34 = & V_3 -> V_59 [ V_103 ] ;
V_34 -> V_194 = * V_85 ;
}
}
static int F_111 ( struct V_2 * V_3 ,
struct V_195 * V_85 )
{
struct V_196 V_197 ;
struct V_198 V_199 ;
struct V_200 V_201 ;
struct V_37 V_202 ;
const T_3 * V_203 = NULL ;
struct V_33 * V_117 ;
#ifdef F_112
struct V_40 * V_204 ;
#endif
int V_14 = - V_30 ;
if ( F_113 ( V_3 ) )
goto V_205;
if ( F_18 ( V_3 ) ) {
V_14 = F_114 ( & V_3 -> V_206 , V_207 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_14 ) {
F_9 ( V_3 ,
L_46 ,
V_207 ) ;
goto V_205;
}
#ifdef F_112
if ( V_3 -> V_53 == 1 ) {
V_204 = F_36 ( F_31 ( V_3 ) ) ;
if ( V_204 ) {
F_31 ( V_3 ) -> V_208 = V_204 ;
} else {
F_9 ( V_3 ,
L_47 ) ;
goto V_205;
}
}
#endif
}
V_3 -> V_209 = V_210 ;
V_14 = F_88 ( V_3 ) ;
if ( V_14 )
goto V_205;
if ( F_18 ( V_3 ) )
V_14 = F_94 ( V_3 , V_85 -> V_97 ) ;
else
V_14 = F_98 ( V_3 ) ;
if ( V_14 )
goto V_17;
if ( F_18 ( V_3 ) ) {
V_14 = F_104 ( V_3 ) ;
if ( V_14 )
goto V_21;
V_203 = V_3 -> V_206 -> V_203 + sizeof( T_7 ) ;
F_115 ( V_3 ) ;
}
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_42 . V_45 = true ;
V_202 . V_47 . V_45 = true ;
V_202 . V_48 . V_45 = true ;
V_202 . V_50 . V_45 = true ;
V_202 . V_51 . V_45 = true ;
V_202 . V_42 . V_43 = V_44 ;
V_202 . V_47 . V_43 = V_44 ;
V_202 . V_48 . V_43 = V_44 ;
V_202 . V_50 . V_43 = V_44 ;
V_202 . V_51 . V_43 = V_44 ;
V_199 . V_211 = & V_202 ;
V_199 . V_212 = true ;
V_199 . V_97 = V_3 -> V_95 . V_96 . V_97 ;
V_199 . V_213 = true ;
V_199 . V_214 = V_203 ;
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
V_197 . V_215 = F_116 () ;
V_197 . V_216 = V_217 ;
V_197 . V_218 = false ;
V_197 . V_219 = V_220 ;
V_199 . V_221 = & V_197 ;
V_14 = F_117 ( V_3 , & V_199 ) ;
if ( V_14 )
goto V_21;
F_51 ( V_3 ,
L_48 ) ;
if ( F_18 ( V_3 ) ) {
V_3 -> V_222 = ( F_118 ( V_223 ) |
F_118 ( V_224 ) |
F_118 ( V_225 ) |
F_118 ( V_226 ) |
F_118 ( V_227 ) ) ;
}
if ( F_31 ( V_3 ) -> V_147 ) {
V_14 = F_119 ( V_3 ) ;
if ( V_14 )
goto V_228;
}
if ( F_18 ( V_3 ) ) {
V_117 = F_31 ( V_3 ) ;
V_201 . V_1 = ( V_85 -> V_229 << 24 ) |
( V_85 -> V_230 << 16 ) |
( V_85 -> V_231 << 8 ) |
( V_85 -> V_232 ) ;
F_120 ( V_201 . V_133 , V_85 -> V_133 ,
V_233 - 4 ) ;
V_14 = F_121 ( V_117 , V_117 -> V_234 ,
& V_201 ) ;
if ( V_14 ) {
F_9 ( V_3 , L_49 ) ;
return V_14 ;
}
}
F_122 ( V_3 ) ;
return 0 ;
V_228:
F_86 ( V_3 ) ;
V_21:
F_123 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_81 ( V_3 ) ;
F_107 ( V_3 ) ;
F_55 ( V_3 ) ;
V_17:
F_124 ( V_3 ) ;
V_205:
if ( F_18 ( V_3 ) )
F_125 ( V_3 -> V_206 ) ;
#ifdef F_112
if ( F_18 ( V_3 ) && ( V_3 -> V_53 == 1 ) &&
F_31 ( V_3 ) -> V_208 )
F_40 ( F_31 ( V_3 ) ,
F_31 ( V_3 ) -> V_208 ) ;
#endif
F_126 ( V_3 , false ) ;
return V_14 ;
}
static int F_127 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_20 ;
F_128 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
#ifdef F_112
if ( V_3 -> V_53 == 1 )
F_40 ( F_31 ( V_3 ) ,
F_31 ( V_3 ) -> V_208 ) ;
#endif
F_107 ( V_3 ) ;
if ( F_129 ( V_3 ) )
F_130 ( V_3 , true ) ;
}
F_85 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_81 ( V_3 ) ;
F_55 ( V_3 ) ;
F_124 ( V_3 ) ;
F_126 ( V_3 , true ) ;
if ( F_18 ( V_3 ) )
F_125 ( V_3 -> V_206 ) ;
return 0 ;
}
static void F_131 ( struct V_2 * V_3 , char V_133 [ V_134 ] )
{
int V_103 ;
memcpy ( V_3 -> V_133 , V_133 , V_134 ) ;
F_82 (cdev, i)
snprintf ( V_3 -> V_59 [ V_103 ] . V_133 , V_134 , L_50 , V_133 , V_103 ) ;
}
static T_7 F_132 ( struct V_2 * V_3 ,
struct V_235 * V_236 ,
void * V_237 ,
T_9 V_238 , T_8 V_239 ,
enum V_240 type )
{
struct V_33 * V_34 ;
struct V_40 * V_204 ;
int V_241 ;
T_8 V_242 ;
T_3 V_243 ;
T_7 V_14 ;
if ( type == V_244 )
V_243 = V_3 -> V_53 ;
else
V_243 = 1 ;
V_241 = V_239 % V_243 ;
V_34 = & V_3 -> V_59 [ V_241 ] ;
V_242 = V_239 / V_243 ;
F_47 ( V_3 , V_130 ,
L_51 ,
V_241 , V_242 , V_239 ) ;
if ( F_18 ( V_34 -> V_3 ) ) {
V_204 = F_36 ( V_34 ) ;
if ( ! V_204 )
return - V_245 ;
V_14 = F_133 ( V_34 , V_204 , V_236 , V_237 ,
V_238 , V_242 ) ;
F_40 ( V_34 , V_204 ) ;
} else {
V_14 = F_133 ( V_34 , NULL , V_236 , V_237 ,
V_238 , V_242 ) ;
}
return V_14 ;
}
static T_7 F_134 ( struct V_2 * V_3 ,
struct V_235 * V_236 , T_8 V_239 )
{
struct V_33 * V_34 ;
int V_241 ;
T_8 V_242 ;
T_7 V_14 ;
V_241 = V_239 % V_3 -> V_53 ;
V_34 = & V_3 -> V_59 [ V_241 ] ;
V_242 = V_239 / V_3 -> V_53 ;
F_47 ( V_3 , V_130 ,
L_51 ,
V_241 , V_242 , V_239 ) ;
V_14 = F_135 ( V_34 , V_236 , V_242 ) ;
return V_14 ;
}
static bool F_136 ( struct V_2 * V_3 )
{
return true ;
}
static int F_137 ( struct V_2 * V_3 , struct V_246 * V_85 )
{
struct V_33 * V_117 ;
struct V_247 * V_248 ;
struct V_40 * V_41 ;
int V_14 ;
if ( ! V_3 )
return - V_20 ;
V_117 = & V_3 -> V_59 [ 0 ] ;
if ( F_110 ( V_3 ) ) {
F_138 ( V_117 , V_249 ) ;
return 0 ;
}
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_245 ;
V_248 = F_139 ( V_117 ) ;
if ( V_85 -> V_250 & V_251 )
V_248 -> V_252 . V_253 = V_85 -> V_253 ;
if ( V_85 -> V_250 & V_254 ) {
V_248 -> V_252 . V_255 = 0 ;
if ( ( V_85 -> V_256 & V_257 ) ||
( V_85 -> V_256 & V_258 ) )
V_248 -> V_252 . V_255 |=
V_259 ;
if ( V_85 -> V_256 & V_260 )
V_248 -> V_252 . V_255 |=
V_261 ;
if ( V_85 -> V_256 & V_262 )
V_248 -> V_252 . V_255 |=
V_263 ;
if ( V_85 -> V_256 & V_264 )
V_248 -> V_252 . V_255 |=
V_265 ;
if ( V_85 -> V_256 & V_266 )
V_248 -> V_252 . V_255 |=
V_267 ;
if ( V_85 -> V_256 & V_268 )
V_248 -> V_252 . V_255 |=
V_269 ;
}
if ( V_85 -> V_250 & V_270 )
V_248 -> V_252 . V_271 = V_85 -> V_271 ;
if ( V_85 -> V_250 & V_272 ) {
if ( V_85 -> V_273 & V_274 )
V_248 -> V_275 . V_253 = true ;
else
V_248 -> V_275 . V_253 = false ;
if ( V_85 -> V_273 & V_276 )
V_248 -> V_275 . V_277 = true ;
else
V_248 -> V_275 . V_277 = false ;
if ( V_85 -> V_273 & V_278 )
V_248 -> V_275 . V_279 = true ;
else
V_248 -> V_275 . V_279 = false ;
}
if ( V_85 -> V_250 & V_280 ) {
switch ( V_85 -> V_281 ) {
case V_282 :
V_248 -> V_281 = V_283 ;
break;
case V_284 :
V_248 -> V_281 = V_285 ;
break;
case V_286 :
V_248 -> V_281 = V_287 ;
break;
case V_288 :
V_248 -> V_281 = V_289 ;
break;
default:
V_248 -> V_281 = V_290 ;
break;
}
}
V_14 = F_140 ( V_117 , V_41 , V_85 -> V_291 ) ;
F_40 ( V_117 , V_41 ) ;
return V_14 ;
}
static int F_141 ( T_7 V_292 )
{
int V_293 ;
switch ( V_292 ) {
case V_294 :
case V_295 :
case V_296 :
case V_297 :
case V_298 :
V_293 = V_299 ;
break;
case V_300 :
V_293 = V_301 ;
break;
case V_302 :
V_293 = V_303 ;
break;
case V_304 :
V_293 = V_305 ;
break;
case V_306 :
default:
V_293 = V_307 ;
break;
}
return V_293 ;
}
static int F_142 ( struct V_33 * V_117 ,
struct V_247 * V_85 ,
struct V_308 * V_309 ,
struct V_310 * V_311 )
{
void * V_312 ;
if ( ! F_18 ( V_117 -> V_3 ) ) {
F_143 ( V_117 , V_85 ) ;
F_144 ( V_117 , V_309 ) ;
F_145 ( V_117 , V_311 ) ;
return 0 ;
}
V_312 = F_139 ( V_117 ) ;
if ( ! V_312 )
return - V_313 ;
memcpy ( V_85 , V_312 , sizeof( * V_85 ) ) ;
V_312 = F_146 ( V_117 ) ;
if ( ! V_312 )
return - V_313 ;
memcpy ( V_309 , V_312 , sizeof( * V_309 ) ) ;
V_312 = F_147 ( V_117 ) ;
if ( ! V_312 )
return - V_313 ;
memcpy ( V_311 , V_312 , sizeof( * V_311 ) ) ;
return 0 ;
}
static void F_148 ( struct V_33 * V_117 ,
struct V_314 * V_315 )
{
struct V_247 V_85 ;
struct V_308 V_309 ;
struct V_310 V_311 ;
T_7 V_292 ;
memset ( V_315 , 0 , sizeof( * V_315 ) ) ;
if ( F_142 ( V_117 , & V_85 , & V_309 , & V_311 ) ) {
F_149 ( & V_117 -> V_3 -> V_6 -> V_5 , L_52 ) ;
return;
}
if ( V_309 . V_291 )
V_315 -> V_291 = true ;
V_315 -> V_316 = V_317 ;
if ( V_311 . V_318 )
V_315 -> V_316 |= V_319 ;
if ( V_85 . V_275 . V_253 ||
( V_85 . V_275 . V_277 && V_85 . V_275 . V_279 ) )
V_315 -> V_316 |= V_320 ;
if ( V_85 . V_275 . V_253 || V_85 . V_275 . V_277 ||
V_85 . V_275 . V_279 )
V_315 -> V_316 |= V_321 ;
V_315 -> V_322 = V_315 -> V_316 ;
if ( V_85 . V_252 . V_253 )
V_315 -> V_322 |= V_319 ;
else
V_315 -> V_322 &= ~ V_319 ;
if ( V_85 . V_252 . V_255 &
V_259 )
V_315 -> V_322 |= V_257 |
V_258 ;
if ( V_85 . V_252 . V_255 &
V_261 )
V_315 -> V_322 |= V_260 ;
if ( V_85 . V_252 . V_255 &
V_263 )
V_315 -> V_322 |= V_262 ;
if ( V_85 . V_252 . V_255 &
V_265 )
V_315 -> V_322 |= V_264 ;
if ( V_85 . V_252 . V_255 &
V_267 )
V_315 -> V_322 |= V_266 ;
if ( V_85 . V_252 . V_255 &
V_269 )
V_315 -> V_322 |= V_268 ;
if ( V_311 . V_323 &
V_259 )
V_315 -> V_316 |= V_257 |
V_258 ;
if ( V_311 . V_323 &
V_261 )
V_315 -> V_316 |= V_260 ;
if ( V_311 . V_323 &
V_263 )
V_315 -> V_316 |= V_262 ;
if ( V_311 . V_323 &
V_265 )
V_315 -> V_316 |= V_264 ;
if ( V_311 . V_323 &
V_267 )
V_315 -> V_316 |= V_266 ;
if ( V_311 . V_323 &
V_269 )
V_315 -> V_316 |= V_268 ;
if ( V_309 . V_291 )
V_315 -> V_252 = V_309 . V_252 ;
V_315 -> V_324 = V_325 ;
F_150 ( V_117 -> V_3 , & V_292 ) ;
V_315 -> V_326 = F_141 ( V_292 ) ;
V_315 -> V_253 = V_85 . V_252 . V_253 ;
if ( V_85 . V_275 . V_253 )
V_315 -> V_273 |= V_274 ;
if ( V_85 . V_275 . V_277 )
V_315 -> V_273 |= V_276 ;
if ( V_85 . V_275 . V_279 )
V_315 -> V_273 |= V_278 ;
if ( V_309 . V_327 & V_328 )
V_315 -> V_329 |= V_257 ;
if ( V_309 . V_327 & V_330 )
V_315 -> V_329 |= V_258 ;
if ( V_309 . V_327 & V_331 )
V_315 -> V_329 |= V_260 ;
if ( V_309 . V_327 & V_332 )
V_315 -> V_329 |= V_262 ;
if ( V_309 . V_327 & V_333 )
V_315 -> V_329 |= V_264 ;
if ( V_309 . V_327 & V_334 )
V_315 -> V_329 |= V_266 ;
if ( V_309 . V_327 & V_335 )
V_315 -> V_329 |= V_268 ;
if ( V_309 . V_336 )
V_315 -> V_329 |= V_319 ;
if ( V_309 . V_337 )
V_315 -> V_329 |= V_321 ;
if ( V_309 . V_337 == V_338 ||
V_309 . V_337 == V_339 )
V_315 -> V_329 |= V_320 ;
}
static void F_151 ( struct V_2 * V_3 ,
struct V_314 * V_315 )
{
int V_103 ;
F_148 ( & V_3 -> V_59 [ 0 ] , V_315 ) ;
F_82 (cdev, i)
F_152 ( & V_3 -> V_59 [ V_103 ] ) ;
}
void F_153 ( struct V_33 * V_117 )
{
void * V_340 = V_117 -> V_3 -> V_341 ;
struct V_342 * V_343 = V_117 -> V_3 -> V_344 . V_345 ;
struct V_314 V_315 ;
F_148 ( V_117 , & V_315 ) ;
F_152 ( V_117 ) ;
if ( F_154 ( V_117 ) && V_340 )
V_343 -> V_346 ( V_340 , & V_315 ) ;
}
static int F_155 ( struct V_2 * V_3 )
{
struct V_33 * V_117 ;
struct V_40 * V_41 ;
int V_103 , V_14 ;
if ( F_110 ( V_3 ) )
return 0 ;
F_82 (cdev, i) {
V_117 = & V_3 -> V_59 [ V_103 ] ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 ) {
F_9 ( V_117 , L_53 ) ;
return - V_245 ;
}
V_14 = F_156 ( V_117 , V_41 ) ;
if ( V_14 )
return V_14 ;
F_40 ( V_117 , V_41 ) ;
}
return 0 ;
}
static int F_157 ( struct V_2 * V_3 , enum V_347 type ,
T_3 * V_348 , T_8 V_349 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 = F_36 ( V_117 ) ;
int V_14 ;
if ( ! V_41 )
return - V_350 ;
V_14 = F_158 ( V_117 , V_41 , type , V_348 , V_349 ) ;
F_40 ( V_117 , V_41 ) ;
return V_14 ;
}
static void F_159 ( struct V_2 * V_3 , T_8 * V_351 , T_8 * V_352 )
{
* V_351 = V_3 -> V_209 ;
* V_352 = V_3 -> V_353 ;
}
static int F_160 ( struct V_2 * V_3 , T_8 V_351 , T_8 V_352 ,
T_8 V_354 , T_8 V_239 )
{
struct V_33 * V_117 ;
struct V_40 * V_41 ;
int V_241 ;
int V_127 = 0 ;
V_241 = V_354 % V_3 -> V_53 ;
V_117 = & V_3 -> V_59 [ V_241 ] ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_127 = F_161 ( V_117 , V_41 , V_351 ,
V_354 / V_3 -> V_53 , V_239 ) ;
if ( V_127 )
goto V_96;
V_127 = F_162 ( V_117 , V_41 , V_352 ,
V_354 / V_3 -> V_53 , V_239 ) ;
V_96:
F_40 ( V_117 , V_41 ) ;
return V_127 ;
}
static int F_163 ( struct V_2 * V_3 , enum V_355 V_356 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 ;
int V_127 = 0 ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_127 = F_164 ( V_117 , V_41 , V_356 ) ;
F_40 ( V_117 , V_41 ) ;
return V_127 ;
}
static int F_165 ( struct V_2 * V_3 , bool V_357 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 ;
int V_14 = 0 ;
if ( F_110 ( V_3 ) )
return 0 ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_14 = F_166 ( V_117 , V_41 , V_357 ? V_358
: V_359 ) ;
if ( V_14 )
goto V_96;
V_14 = F_167 ( V_117 , V_41 , V_360 ) ;
V_96:
F_40 ( V_117 , V_41 ) ;
return V_14 ;
}
static int F_168 ( struct V_2 * V_3 , bool V_361 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 ;
int V_127 = 0 ;
if ( F_110 ( V_3 ) )
return 0 ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_127 = F_169 ( V_117 , V_41 , V_361 ?
V_362 :
V_363 ) ;
F_40 ( V_117 , V_41 ) ;
return V_127 ;
}
static int F_170 ( struct V_2 * V_3 , T_3 * V_364 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 ;
int V_127 = 0 ;
if ( F_110 ( V_3 ) )
return 0 ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_127 = F_171 ( V_117 , V_41 , V_364 ) ;
if ( V_127 )
goto V_96;
V_127 = F_167 ( V_117 , V_41 , V_360 ) ;
V_96:
F_40 ( V_117 , V_41 ) ;
return V_127 ;
}
static int F_172 ( struct V_2 * V_3 , T_8 V_80 )
{
struct V_33 * V_117 = F_31 ( V_3 ) ;
struct V_40 * V_41 ;
int V_127 = 0 ;
if ( F_110 ( V_3 ) )
return 0 ;
V_41 = F_36 ( V_117 ) ;
if ( ! V_41 )
return - V_350 ;
V_127 = F_173 ( V_117 , V_41 , V_80 ) ;
if ( V_127 )
goto V_96;
V_127 = F_167 ( V_117 , V_41 , V_360 ) ;
V_96:
F_40 ( V_117 , V_41 ) ;
return V_127 ;
}
void F_174 ( struct V_2 * V_3 ,
enum V_365 type ,
union V_366 * V_367 )
{
struct V_368 V_369 ;
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
switch ( type ) {
case V_370 :
F_175 ( V_3 , & V_369 ) ;
V_367 -> V_371 . V_372 =
V_369 . V_345 . V_373 ;
V_367 -> V_371 . V_374 =
V_369 . V_345 . V_375 ;
V_367 -> V_371 . V_376 = - 1 ;
break;
case V_377 :
F_176 ( V_3 , & V_367 -> V_378 ) ;
break;
case V_379 :
F_177 ( V_3 , & V_367 -> V_380 ) ;
break;
default:
F_47 ( V_3 , V_141 ,
L_54 , type ) ;
return;
}
}
