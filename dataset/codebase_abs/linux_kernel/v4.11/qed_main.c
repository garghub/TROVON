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
if ( V_3 -> V_9 )
F_11 ( V_3 -> V_9 ) ;
if ( V_3 -> V_10 )
F_11 ( V_3 -> V_10 ) ;
if ( F_12 ( & V_6 -> V_11 ) == 1 )
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
}
static int F_15 ( struct V_2 * V_3 , struct V_8 * V_6 )
{
T_3 V_12 ;
int V_13 ;
V_3 -> V_6 = V_6 ;
V_13 = F_16 ( V_6 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_5 ) ;
goto V_14;
}
if ( ! ( F_17 ( V_6 , 0 ) & V_15 ) ) {
F_9 ( V_3 , L_6 ) ;
V_13 = - V_7 ;
goto V_16;
}
if ( F_18 ( V_3 ) && ! ( F_17 ( V_6 , 2 ) & V_15 ) ) {
F_9 ( V_3 , L_7 ) ;
V_13 = - V_7 ;
goto V_16;
}
if ( F_12 ( & V_6 -> V_11 ) == 1 ) {
V_13 = F_19 ( V_6 , L_8 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_9 ) ;
goto V_16;
}
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
}
F_22 ( V_6 , V_17 , & V_12 ) ;
if ( V_12 == V_18 ) {
F_9 ( V_3 ,
L_10 ,
V_12 ) ;
V_13 = - V_19 ;
goto V_20;
}
if ( ! F_23 ( V_6 ) ) {
F_9 ( V_3 , L_11 ) ;
V_13 = - V_7 ;
goto V_20;
}
V_3 -> V_21 . V_22 = F_24 ( V_6 , V_23 ) ;
if ( F_18 ( V_3 ) && ! V_3 -> V_21 . V_22 )
F_9 ( V_3 , L_12 ) ;
V_13 = F_5 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_3 -> V_21 . V_24 = F_25 ( V_6 , 0 ) ;
V_3 -> V_21 . V_25 = F_26 ( V_6 , 0 ) ;
V_3 -> V_21 . V_26 = V_6 -> V_26 ;
V_3 -> V_10 = F_27 ( V_6 , 0 ) ;
if ( ! V_3 -> V_10 ) {
F_9 ( V_3 , L_13 ) ;
V_13 = - V_27 ;
goto V_20;
}
if ( F_18 ( V_3 ) ) {
V_3 -> V_28 = F_25 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_29 = F_28 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_9 = F_29 ( V_3 -> V_28 , V_3 -> V_29 ) ;
if ( ! V_3 -> V_9 ) {
F_9 ( V_3 , L_14 ) ;
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
V_31 -> V_38 = ( V_3 -> V_39 [ 0 ] . V_40 . V_41 ==
V_42 ) ;
V_31 -> V_43 = F_31 ( & V_3 -> V_39 [ 0 ] ) ;
F_32 ( V_31 -> V_44 , V_3 -> V_39 [ 0 ] . V_40 . V_45 ) ;
if ( F_18 ( V_3 ) ) {
V_31 -> V_46 = V_47 ;
V_31 -> V_48 = V_49 ;
V_31 -> V_50 = V_51 ;
V_31 -> V_52 = V_53 ;
V_31 -> V_54 = V_3 -> V_54 ;
V_31 -> V_55 = true ;
if ( F_33 ( V_3 ) -> V_40 . V_56 ==
V_57 )
V_31 -> V_58 = true ;
} else {
F_34 ( & V_3 -> V_39 [ 0 ] , & V_31 -> V_46 ,
& V_31 -> V_48 , & V_31 -> V_50 ,
& V_31 -> V_52 ) ;
}
if ( F_18 ( V_3 ) ) {
V_33 = F_35 ( F_33 ( V_3 ) ) ;
if ( V_33 ) {
F_36 ( F_33 ( V_3 ) , V_33 ,
& V_31 -> V_59 , NULL ) ;
F_37 ( F_33 ( V_3 ) , V_33 ,
& V_31 -> V_60 ) ;
F_38 ( F_33 ( V_3 ) , V_33 ) ;
}
} else {
F_36 ( F_33 ( V_3 ) , NULL ,
& V_31 -> V_59 , NULL ) ;
}
V_31 -> V_61 = F_33 ( V_3 ) -> V_40 . V_61 ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_40 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_41 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_62 ) ;
if ( ! V_3 )
return V_3 ;
F_43 ( V_3 ) ;
return V_3 ;
}
static int F_44 ( struct V_2 * V_3 , T_4 V_63 )
{
if ( ! V_3 )
return - V_19 ;
F_45 ( V_3 , V_64 , L_15 ) ;
return 0 ;
}
static struct V_2 * F_46 ( struct V_8 * V_6 ,
struct V_65 * V_66 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_41 ( V_6 ) ;
if ( ! V_3 )
goto V_14;
V_3 -> V_67 = V_66 -> V_67 ;
if ( V_66 -> V_68 )
V_3 -> V_69 = true ;
F_47 ( V_3 , V_66 -> V_70 , V_66 -> V_71 ) ;
V_13 = F_15 ( V_3 , V_6 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_16 ) ;
goto V_16;
}
F_49 ( V_3 , L_17 ) ;
V_13 = F_50 ( V_3 , V_72 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_18 ) ;
goto V_20;
}
F_49 ( V_3 , L_19 ) ;
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
F_44 ( V_3 , V_73 ) ;
F_39 ( V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
if ( V_3 -> V_74 . V_75 . V_76 == V_77 ) {
F_54 ( V_3 -> V_6 ) ;
F_40 ( V_3 -> V_74 . V_78 ) ;
} else if ( V_3 -> V_74 . V_75 . V_76 == V_79 ) {
F_55 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_74 . V_75 , 0 , sizeof( struct V_80 ) ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_81 * V_74 )
{
int V_82 , V_13 , V_83 ;
V_83 = V_74 -> V_84 . V_85 ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ )
V_74 -> V_78 [ V_82 ] . V_86 = V_82 ;
V_13 = F_57 ( V_3 -> V_6 , V_74 -> V_78 ,
V_74 -> V_84 . V_87 , V_83 ) ;
if ( V_13 < V_83 && V_13 >= V_74 -> V_84 . V_87 &&
( V_13 % V_3 -> V_34 ) ) {
F_54 ( V_3 -> V_6 ) ;
V_83 = ( V_13 / V_3 -> V_34 ) * V_3 -> V_34 ;
F_9 ( V_3 ,
L_20 ,
V_83 , V_74 -> V_84 . V_85 ) ;
V_13 = F_58 ( V_3 -> V_6 , V_74 -> V_78 ,
V_83 ) ;
if ( ! V_13 )
V_13 = V_83 ;
}
if ( V_13 > 0 ) {
V_74 -> V_75 . V_76 = V_77 ;
V_74 -> V_75 . V_85 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_21 ,
V_83 , V_13 ) ;
}
return V_13 ;
}
static int F_59 ( struct V_2 * V_3 , bool V_88 )
{
struct V_81 * V_74 = & V_3 -> V_74 ;
struct V_89 * V_90 ;
int V_13 = 0 , V_83 ;
switch ( V_74 -> V_84 . V_76 ) {
case V_77 :
V_83 = V_74 -> V_84 . V_85 ;
V_74 -> V_78 = F_60 ( V_83 , sizeof( * V_90 ) , V_62 ) ;
if ( ! V_74 -> V_78 ) {
V_13 = - V_27 ;
goto V_75;
}
V_13 = F_56 ( V_3 , V_74 ) ;
if ( ! V_13 )
goto V_75;
F_9 ( V_3 , L_22 ) ;
F_40 ( V_74 -> V_78 ) ;
if ( V_88 )
goto V_75;
case V_79 :
if ( V_3 -> V_34 == 1 ) {
V_13 = F_61 ( V_3 -> V_6 ) ;
if ( ! V_13 ) {
V_74 -> V_75 . V_76 = V_79 ;
goto V_75;
}
F_9 ( V_3 , L_23 ) ;
if ( V_88 )
goto V_75;
}
case V_91 :
V_74 -> V_75 . V_76 = V_91 ;
V_13 = 0 ;
goto V_75;
default:
F_9 ( V_3 , L_24 ,
V_74 -> V_84 . V_76 ) ;
V_13 = - V_92 ;
}
V_75:
if ( ! V_13 )
F_49 ( V_3 , L_25 ,
V_74 -> V_75 . V_76 == V_91 ?
L_26 : V_74 -> V_75 . V_76 == V_79 ?
L_27 : L_28 ) ;
V_3 -> V_93 = V_94 ;
return V_13 ;
}
static void F_62 ( struct V_2 * V_3 , void * V_95 ,
int V_96 , void (* F_63)( void * ) )
{
struct V_97 * V_98 = & V_3 -> V_39 [ V_96 % V_3 -> V_34 ] ;
int V_99 = V_96 / V_3 -> V_34 ;
V_98 -> V_100 [ V_99 ] . V_101 = F_63 ;
V_98 -> V_100 [ V_99 ] . V_95 = V_95 ;
}
static void F_64 ( struct V_2 * V_3 , int V_96 )
{
struct V_97 * V_98 = & V_3 -> V_39 [ V_96 % V_3 -> V_34 ] ;
int V_99 = V_96 / V_3 -> V_34 ;
memset ( & V_98 -> V_100 [ V_99 ] , 0 ,
sizeof( struct V_102 ) ) ;
}
static T_5 F_65 ( int V_26 , void * V_103 )
{
F_66 ( (struct V_104 * ) V_103 ) ;
return V_105 ;
}
static T_5 F_67 ( int V_26 , void * V_106 )
{
struct V_2 * V_3 = (struct V_2 * ) V_106 ;
struct V_97 * V_98 ;
T_5 V_13 = V_107 ;
T_6 V_108 ;
int V_82 , V_109 ;
for ( V_82 = 0 ; V_82 < V_3 -> V_34 ; V_82 ++ ) {
V_108 = F_68 ( & V_3 -> V_39 [ V_82 ] ) ;
if ( ! V_108 )
continue;
V_98 = & V_3 -> V_39 [ V_82 ] ;
if ( F_69 ( V_108 & 0x1 ) ) {
F_66 ( V_98 -> V_110 ) ;
V_108 &= ~ 0x1 ;
V_13 = V_105 ;
}
for ( V_109 = 0 ; V_109 < 64 ; V_109 ++ ) {
if ( ( 0x2ULL << V_109 ) & V_108 ) {
V_98 -> V_100 [ V_109 ] . V_101 (
V_98 -> V_100 [ V_109 ] . V_95 ) ;
V_108 &= ~ ( 0x2ULL << V_109 ) ;
V_13 = V_105 ;
}
}
if ( F_69 ( V_108 ) )
F_45 ( V_98 , V_111 ,
L_29 ,
V_108 ) ;
}
return V_13 ;
}
int F_70 ( struct V_97 * V_98 )
{
struct V_2 * V_3 = V_98 -> V_3 ;
T_7 V_76 ;
int V_13 = 0 ;
T_3 V_112 ;
V_76 = V_3 -> V_74 . V_75 . V_76 ;
if ( V_76 == V_77 ) {
V_112 = V_98 -> V_113 ;
snprintf ( V_98 -> V_114 , V_115 , L_30 ,
V_112 , V_3 -> V_6 -> V_116 -> V_117 ,
F_71 ( V_3 -> V_6 -> V_118 ) , V_98 -> V_119 ) ;
V_13 = F_72 ( V_3 -> V_74 . V_78 [ V_112 ] . V_120 ,
F_65 , 0 , V_98 -> V_114 , V_98 -> V_110 ) ;
} else {
unsigned long V_121 = 0 ;
snprintf ( V_3 -> V_114 , V_115 , L_31 ,
V_3 -> V_6 -> V_116 -> V_117 , F_71 ( V_3 -> V_6 -> V_118 ) ,
F_73 ( V_3 -> V_6 -> V_118 ) ) ;
if ( V_3 -> V_74 . V_75 . V_76 == V_91 )
V_121 |= V_122 ;
V_13 = F_72 ( V_3 -> V_6 -> V_26 , F_67 ,
V_121 , V_3 -> V_114 , V_3 ) ;
}
if ( V_13 )
F_9 ( V_3 , L_32 , V_13 ) ;
else
F_45 ( V_98 , ( V_111 | V_123 ) ,
L_33 ,
( V_76 == V_77 ) ? L_34 : L_35 ) ;
return V_13 ;
}
static void F_74 ( struct V_2 * V_3 )
{
int V_82 ;
if ( V_3 -> V_74 . V_75 . V_76 == V_77 ) {
F_75 (cdev, i) {
if ( ! V_3 -> V_39 [ V_82 ] . V_124 )
break;
F_76 ( V_3 -> V_74 . V_78 [ V_82 ] . V_120 ) ;
F_77 ( V_3 -> V_74 . V_78 [ V_82 ] . V_120 ,
V_3 -> V_39 [ V_82 ] . V_110 ) ;
}
} else {
if ( F_33 ( V_3 ) -> V_124 )
F_77 ( V_3 -> V_6 -> V_26 , V_3 ) ;
}
F_78 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_82 , V_13 ;
V_13 = F_80 ( V_3 ) ;
for ( V_82 = 0 ; V_82 < V_3 -> V_34 ; V_82 ++ ) {
struct V_97 * V_125 = & V_3 -> V_39 [ V_82 ] ;
if ( V_125 -> V_126 ) {
F_81 ( V_125 -> V_110 ) ;
V_125 -> V_126 = false ;
F_45 ( V_3 , V_127 ,
L_36 ,
V_82 , V_125 -> V_110 ) ;
}
}
F_82 ( V_3 ) ;
return V_13 ;
}
static int F_83 ( struct V_2 * V_3 )
{
int V_13 ;
V_13 = F_84 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_85 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 )
{
int V_13 , V_82 ;
if ( F_33 ( V_3 ) -> V_40 . V_41 != V_128 ) {
for ( V_82 = 0 ; V_82 < V_3 -> V_34 ; V_82 ++ ) {
struct V_97 * V_125 = & V_3 -> V_39 [ V_82 ] ;
V_125 -> V_129 = true ;
}
}
V_13 = F_87 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_49 ( V_3 , L_37 ) ;
F_88 ( V_3 ) ;
return V_13 ;
}
static int F_89 ( struct V_2 * V_3 , T_8 V_83 )
{
int V_130 = 0 ;
V_3 -> V_74 . V_131 = V_83 ? true : false ;
if ( V_3 -> V_74 . V_75 . V_76 != V_77 )
V_130 = V_3 -> V_34 * 63 ;
else if ( V_3 -> V_74 . V_132 )
V_130 = V_3 -> V_74 . V_132 ;
if ( ! V_130 )
return - V_27 ;
return F_90 ( int , V_83 , V_130 ) ;
}
static int F_91 ( struct V_2 * V_3 , struct V_133 * V_134 )
{
memset ( V_134 , 0 , sizeof( struct V_133 ) ) ;
if ( ! V_3 -> V_74 . V_131 ) {
F_49 ( V_3 ,
L_38 ) ;
return - V_92 ;
}
if ( V_3 -> V_74 . V_75 . V_76 == V_77 ) {
int V_135 = V_3 -> V_74 . V_136 ;
V_134 -> V_137 = V_3 -> V_74 . V_132 ;
V_134 -> V_138 = & V_3 -> V_74 . V_78 [ V_135 ] ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_3 ,
enum V_139 V_76 )
{
struct V_140 V_141 ;
int V_142 = 0 ;
int V_13 ;
int V_82 ;
if ( ( V_76 == V_79 ) && ( V_3 -> V_34 > 1 ) ) {
F_9 ( V_3 , L_39 ) ;
return - V_92 ;
}
memset ( & V_3 -> V_74 , 0 , sizeof( struct V_81 ) ) ;
V_3 -> V_74 . V_84 . V_76 = V_76 ;
F_75 (cdev, i) {
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
F_93 ( & V_3 -> V_39 [ V_82 ] , & V_141 ) ;
V_3 -> V_74 . V_84 . V_85 += V_141 . V_143 ;
V_3 -> V_74 . V_84 . V_85 ++ ;
}
V_3 -> V_74 . V_84 . V_87 = V_3 -> V_34 * 2 ;
V_13 = F_59 ( V_3 , false ) ;
if ( V_13 ) {
F_48 ( V_3 , L_40 ) ;
return V_13 ;
}
V_3 -> V_74 . V_136 = V_3 -> V_34 ;
V_3 -> V_74 . V_132 = V_3 -> V_74 . V_75 . V_85 -
V_3 -> V_34 ;
if ( ! F_94 ( V_144 ) )
return 0 ;
F_75 (cdev, i)
V_142 += F_95 ( & V_3 -> V_39 [ V_82 ] , V_145 ) ;
F_45 ( V_3 , V_146 ,
L_41 ,
V_3 -> V_74 . V_132 , V_142 ) ;
if ( V_3 -> V_74 . V_132 > V_142 ) {
V_3 -> V_74 . V_147 =
( V_3 -> V_74 . V_132 - V_142 )
/ V_3 -> V_34 ;
V_3 -> V_74 . V_148 =
V_3 -> V_74 . V_136 + V_142 ;
V_3 -> V_74 . V_132 = V_142 ;
} else {
V_3 -> V_74 . V_147 = 0 ;
}
F_45 ( V_3 , V_146 , L_42 ,
V_3 -> V_74 . V_147 ,
V_3 -> V_74 . V_148 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
int V_13 ;
memset ( & V_3 -> V_74 , 0 , sizeof( struct V_81 ) ) ;
V_3 -> V_74 . V_84 . V_76 = V_77 ;
F_97 ( F_33 ( V_3 ) ,
& V_3 -> V_74 . V_84 . V_85 ) ;
if ( V_3 -> V_34 > 1 ) {
T_3 V_149 = 0 ;
F_97 ( & V_3 -> V_39 [ 1 ] , & V_149 ) ;
V_3 -> V_74 . V_84 . V_85 += V_149 ;
}
V_3 -> V_74 . V_84 . V_87 = V_3 -> V_34 ;
V_13 = F_59 ( V_3 , true ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_74 . V_136 = 0 ;
V_3 -> V_74 . V_132 = V_3 -> V_74 . V_75 . V_85 ;
return 0 ;
}
T_7 F_98 ( struct V_97 * V_125 , T_7 V_150 ,
T_3 * V_151 , T_7 V_152 , T_3 * V_153 )
{
int V_13 ;
V_125 -> V_154 -> V_155 = V_151 ;
V_125 -> V_154 -> V_156 = V_150 ;
V_125 -> V_154 -> V_157 = V_153 ;
V_125 -> V_154 -> V_158 = V_152 ;
V_13 = F_99 ( V_125 -> V_154 , V_159 ) ;
if ( V_13 != V_160 ) {
F_45 ( V_125 , V_64 , L_43 ,
V_13 ) ;
return 0 ;
}
V_13 = F_100 ( V_125 -> V_154 , V_161 ) ;
F_101 ( V_125 -> V_154 ) ;
if ( V_13 != V_160 && V_13 != V_162 ) {
F_45 ( V_125 , V_64 , L_44 ,
V_125 -> V_154 -> V_163 , V_13 ) ;
return 0 ;
}
return V_125 -> V_154 -> V_164 / 4 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_82 ;
void * V_165 ;
F_75 (cdev, i) {
struct V_97 * V_125 = & V_3 -> V_39 [ V_82 ] ;
V_125 -> V_154 = F_42 ( sizeof( * V_125 -> V_154 ) , V_62 ) ;
if ( ! V_125 -> V_154 )
return - V_27 ;
V_165 = F_103 ( F_104 () ) ;
if ( ! V_165 )
return - V_27 ;
V_125 -> V_154 -> V_165 = V_165 ;
}
return 0 ;
}
static void F_105 ( struct V_2 * V_3 )
{
int V_82 ;
F_75 (cdev, i) {
struct V_97 * V_125 = & V_3 -> V_39 [ V_82 ] ;
if ( ! V_125 -> V_154 )
return;
F_106 ( V_125 -> V_154 -> V_165 ) ;
F_40 ( V_125 -> V_154 ) ;
}
}
static void F_107 ( struct V_2 * V_3 ,
struct V_166 * V_66 )
{
int V_82 ;
if ( F_94 ( V_144 ) ) {
V_66 -> V_167 . V_168 = V_169 ;
V_66 -> V_167 . V_170 = V_171 ;
V_66 -> V_167 . V_172 = V_173 ;
V_66 -> V_167 . V_174 = V_175 ;
}
if ( F_33 ( V_3 ) -> V_40 . V_41 ==
V_42 ) {
T_8 * V_176 ;
V_176 = & V_66 -> V_177 . V_176 ;
* V_176 = F_90 ( T_8 , * V_176 , 192 ) ;
}
for ( V_82 = 0 ; V_82 < V_3 -> V_34 ; V_82 ++ ) {
struct V_97 * V_125 = & V_3 -> V_39 [ V_82 ] ;
V_125 -> V_178 = * V_66 ;
}
}
static int F_108 ( struct V_2 * V_3 ,
struct V_179 * V_66 )
{
struct V_180 V_181 ;
struct V_182 V_183 ;
const T_3 * V_184 = NULL ;
struct V_97 * V_98 ;
struct V_32 * V_185 ;
int V_13 = - V_92 ;
if ( F_109 ( V_3 ) )
goto V_186;
if ( F_18 ( V_3 ) ) {
V_13 = F_110 ( & V_3 -> V_187 , V_188 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_45 ,
V_188 ) ;
goto V_186;
}
V_185 = F_35 ( F_33 ( V_3 ) ) ;
if ( V_185 ) {
F_33 ( V_3 ) -> V_189 = V_185 ;
} else {
F_9 ( V_3 , L_46 ) ;
goto V_186;
}
}
V_3 -> V_190 = V_191 ;
V_13 = F_86 ( V_3 ) ;
if ( V_13 )
goto V_186;
if ( F_18 ( V_3 ) )
V_13 = F_92 ( V_3 , V_66 -> V_76 ) ;
else
V_13 = F_96 ( V_3 ) ;
if ( V_13 )
goto V_16;
if ( F_18 ( V_3 ) ) {
V_13 = F_102 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_184 = V_3 -> V_187 -> V_184 + sizeof( T_7 ) ;
F_111 ( V_3 ) ;
}
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_192 |= 1 << V_193 |
1 << V_194 |
1 << V_195 |
1 << V_196 |
1 << V_197 ;
V_181 . V_198 = V_199 ;
V_181 . V_200 = V_199 ;
V_181 . V_201 = V_199 ;
V_13 = F_112 ( V_3 , & V_181 , true ,
V_3 -> V_74 . V_75 . V_76 ,
true , V_184 ) ;
if ( V_13 )
goto V_20;
F_49 ( V_3 ,
L_47 ) ;
if ( F_33 ( V_3 ) -> V_129 ) {
V_13 = F_113 ( V_3 ) ;
if ( V_13 )
goto V_202;
}
if ( F_18 ( V_3 ) ) {
V_98 = F_33 ( V_3 ) ;
V_183 . V_1 = ( V_66 -> V_203 << 24 ) |
( V_66 -> V_204 << 16 ) |
( V_66 -> V_205 << 8 ) |
( V_66 -> V_206 ) ;
F_114 ( V_183 . V_114 , V_66 -> V_114 ,
V_207 - 4 ) ;
V_13 = F_115 ( V_98 , V_98 -> V_208 ,
& V_183 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_48 ) ;
return V_13 ;
}
}
F_116 ( V_3 ) ;
return 0 ;
V_202:
F_80 ( V_3 ) ;
V_20:
F_117 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_74 ( V_3 ) ;
F_105 ( V_3 ) ;
F_53 ( V_3 ) ;
V_16:
F_85 ( V_3 ) ;
V_186:
if ( F_18 ( V_3 ) )
F_118 ( V_3 -> V_187 ) ;
if ( F_18 ( V_3 ) && F_33 ( V_3 ) -> V_189 )
F_38 ( F_33 ( V_3 ) ,
F_33 ( V_3 ) -> V_189 ) ;
F_119 ( V_3 , false ) ;
return V_13 ;
}
static int F_120 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
F_121 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
F_38 ( F_33 ( V_3 ) ,
F_33 ( V_3 ) -> V_189 ) ;
F_105 ( V_3 ) ;
if ( F_122 ( V_3 ) )
F_123 ( V_3 , true ) ;
F_79 ( V_3 ) ;
F_74 ( V_3 ) ;
}
F_53 ( V_3 ) ;
F_83 ( V_3 ) ;
F_119 ( V_3 , true ) ;
if ( F_18 ( V_3 ) )
F_118 ( V_3 -> V_187 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 , char V_114 [ V_115 ] ,
char V_209 [ V_210 ] )
{
int V_82 ;
memcpy ( V_3 -> V_114 , V_114 , V_115 ) ;
F_75 (cdev, i)
snprintf ( V_3 -> V_39 [ V_82 ] . V_114 , V_115 , L_49 , V_114 , V_82 ) ;
memcpy ( V_3 -> V_209 , V_209 , V_210 ) ;
V_3 -> V_211 = V_212 ;
}
static T_7 F_125 ( struct V_2 * V_3 ,
struct V_213 * V_214 ,
void * V_215 ,
T_9 V_216 , T_8 V_217 ,
enum V_218 type )
{
struct V_97 * V_125 ;
struct V_32 * V_185 ;
int V_219 ;
T_8 V_220 ;
T_3 V_221 ;
T_7 V_13 ;
if ( type == V_222 )
V_221 = V_3 -> V_34 ;
else
V_221 = 1 ;
V_219 = V_217 % V_221 ;
V_125 = & V_3 -> V_39 [ V_219 ] ;
V_220 = V_217 / V_221 ;
F_45 ( V_3 , V_111 ,
L_50 ,
V_219 , V_220 , V_217 ) ;
if ( F_18 ( V_125 -> V_3 ) ) {
V_185 = F_35 ( V_125 ) ;
if ( ! V_185 )
return - V_223 ;
V_13 = F_126 ( V_125 , V_185 , V_214 , V_215 ,
V_216 , V_220 ) ;
F_38 ( V_125 , V_185 ) ;
} else {
V_13 = F_126 ( V_125 , NULL , V_214 , V_215 ,
V_216 , V_220 ) ;
}
return V_13 ;
}
static T_7 F_127 ( struct V_2 * V_3 ,
struct V_213 * V_214 , T_8 V_217 )
{
struct V_97 * V_125 ;
int V_219 ;
T_8 V_220 ;
T_7 V_13 ;
V_219 = V_217 % V_3 -> V_34 ;
V_125 = & V_3 -> V_39 [ V_219 ] ;
V_220 = V_217 / V_3 -> V_34 ;
F_45 ( V_3 , V_111 ,
L_50 ,
V_219 , V_220 , V_217 ) ;
V_13 = F_128 ( V_125 , V_214 , V_220 ) ;
return V_13 ;
}
static bool F_129 ( struct V_2 * V_3 )
{
return true ;
}
static int F_130 ( struct V_2 * V_3 , struct V_224 * V_66 )
{
struct V_97 * V_98 ;
struct V_225 * V_226 ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
V_98 = & V_3 -> V_39 [ 0 ] ;
if ( F_131 ( V_3 ) ) {
F_132 ( V_98 , V_227 ) ;
return 0 ;
}
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_223 ;
V_226 = F_133 ( V_98 ) ;
if ( V_66 -> V_228 & V_229 )
V_226 -> V_230 . V_231 = V_66 -> V_231 ;
if ( V_66 -> V_228 & V_232 ) {
V_226 -> V_230 . V_233 = 0 ;
if ( ( V_66 -> V_234 & V_235 ) ||
( V_66 -> V_234 & V_236 ) )
V_226 -> V_230 . V_233 |=
V_237 ;
if ( V_66 -> V_234 & V_238 )
V_226 -> V_230 . V_233 |=
V_239 ;
if ( V_66 -> V_234 & V_240 )
V_226 -> V_230 . V_233 |=
V_241 ;
if ( V_66 -> V_234 & V_242 )
V_226 -> V_230 . V_233 |=
V_243 ;
if ( V_66 -> V_234 & V_244 )
V_226 -> V_230 . V_233 |=
V_245 ;
if ( V_66 -> V_234 & V_246 )
V_226 -> V_230 . V_233 |=
V_247 ;
}
if ( V_66 -> V_228 & V_248 )
V_226 -> V_230 . V_249 = V_66 -> V_249 ;
if ( V_66 -> V_228 & V_250 ) {
if ( V_66 -> V_251 & V_252 )
V_226 -> V_253 . V_231 = true ;
else
V_226 -> V_253 . V_231 = false ;
if ( V_66 -> V_251 & V_254 )
V_226 -> V_253 . V_255 = true ;
else
V_226 -> V_253 . V_255 = false ;
if ( V_66 -> V_251 & V_256 )
V_226 -> V_253 . V_257 = true ;
else
V_226 -> V_253 . V_257 = false ;
}
if ( V_66 -> V_228 & V_258 ) {
switch ( V_66 -> V_259 ) {
case V_260 :
V_226 -> V_259 = V_261 ;
break;
case V_262 :
V_226 -> V_259 = V_263 ;
break;
case V_264 :
V_226 -> V_259 = V_265 ;
break;
case V_266 :
V_226 -> V_259 = V_267 ;
break;
default:
V_226 -> V_259 = V_268 ;
break;
}
}
V_13 = F_134 ( V_98 , V_33 , V_66 -> V_269 ) ;
F_38 ( V_98 , V_33 ) ;
return V_13 ;
}
static int F_135 ( T_7 V_270 )
{
int V_271 ;
switch ( V_270 ) {
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
V_271 = V_277 ;
break;
case V_278 :
V_271 = V_279 ;
break;
case V_280 :
V_271 = V_281 ;
break;
case V_282 :
V_271 = V_283 ;
break;
case V_284 :
default:
V_271 = V_285 ;
break;
}
return V_271 ;
}
static int F_136 ( struct V_97 * V_98 ,
struct V_225 * V_66 ,
struct V_286 * V_287 ,
struct V_288 * V_289 )
{
void * V_290 ;
if ( ! F_18 ( V_98 -> V_3 ) ) {
F_137 ( V_98 , V_66 ) ;
F_138 ( V_98 , V_287 ) ;
F_139 ( V_98 , V_289 ) ;
return 0 ;
}
V_290 = F_133 ( V_98 ) ;
if ( ! V_290 )
return - V_291 ;
memcpy ( V_66 , V_290 , sizeof( * V_66 ) ) ;
V_290 = F_140 ( V_98 ) ;
if ( ! V_290 )
return - V_291 ;
memcpy ( V_287 , V_290 , sizeof( * V_287 ) ) ;
V_290 = F_141 ( V_98 ) ;
if ( ! V_290 )
return - V_291 ;
memcpy ( V_289 , V_290 , sizeof( * V_289 ) ) ;
return 0 ;
}
static void F_142 ( struct V_97 * V_98 ,
struct V_292 * V_293 )
{
struct V_225 V_66 ;
struct V_286 V_287 ;
struct V_288 V_289 ;
T_7 V_270 ;
memset ( V_293 , 0 , sizeof( * V_293 ) ) ;
if ( F_136 ( V_98 , & V_66 , & V_287 , & V_289 ) ) {
F_143 ( & V_98 -> V_3 -> V_6 -> V_5 , L_51 ) ;
return;
}
if ( V_287 . V_269 )
V_293 -> V_269 = true ;
V_293 -> V_294 = V_295 ;
if ( V_66 . V_230 . V_231 )
V_293 -> V_294 |= V_296 ;
if ( V_66 . V_253 . V_231 ||
( V_66 . V_253 . V_255 && V_66 . V_253 . V_257 ) )
V_293 -> V_294 |= V_297 ;
if ( V_66 . V_253 . V_231 || V_66 . V_253 . V_255 ||
V_66 . V_253 . V_257 )
V_293 -> V_294 |= V_298 ;
V_293 -> V_299 = V_293 -> V_294 ;
if ( V_66 . V_230 . V_233 &
V_237 )
V_293 -> V_299 |= V_235 |
V_236 ;
if ( V_66 . V_230 . V_233 &
V_239 )
V_293 -> V_299 |= V_238 ;
if ( V_66 . V_230 . V_233 &
V_241 )
V_293 -> V_299 |= V_240 ;
if ( V_66 . V_230 . V_233 &
V_243 )
V_293 -> V_299 |= V_242 ;
if ( V_66 . V_230 . V_233 &
V_245 )
V_293 -> V_299 |= V_244 ;
if ( V_66 . V_230 . V_233 &
V_247 )
V_293 -> V_299 |= V_246 ;
if ( V_289 . V_300 &
V_237 )
V_293 -> V_294 |= V_235 |
V_236 ;
if ( V_289 . V_300 &
V_239 )
V_293 -> V_294 |= V_238 ;
if ( V_289 . V_300 &
V_241 )
V_293 -> V_294 |= V_240 ;
if ( V_289 . V_300 &
V_243 )
V_293 -> V_294 |= V_242 ;
if ( V_289 . V_300 &
V_245 )
V_293 -> V_294 |= V_244 ;
if ( V_289 . V_300 &
V_247 )
V_293 -> V_294 |= V_246 ;
if ( V_287 . V_269 )
V_293 -> V_230 = V_287 . V_230 ;
V_293 -> V_301 = V_302 ;
F_144 ( V_98 -> V_3 , & V_270 ) ;
V_293 -> V_303 = F_135 ( V_270 ) ;
V_293 -> V_231 = V_66 . V_230 . V_231 ;
if ( V_66 . V_253 . V_231 )
V_293 -> V_251 |= V_252 ;
if ( V_66 . V_253 . V_255 )
V_293 -> V_251 |= V_254 ;
if ( V_66 . V_253 . V_257 )
V_293 -> V_251 |= V_256 ;
if ( V_287 . V_304 & V_305 )
V_293 -> V_306 |= V_235 ;
if ( V_287 . V_304 & V_307 )
V_293 -> V_306 |= V_236 ;
if ( V_287 . V_304 & V_308 )
V_293 -> V_306 |= V_238 ;
if ( V_287 . V_304 & V_309 )
V_293 -> V_306 |= V_240 ;
if ( V_287 . V_304 & V_310 )
V_293 -> V_306 |= V_242 ;
if ( V_287 . V_304 & V_311 )
V_293 -> V_306 |= V_244 ;
if ( V_287 . V_304 & V_312 )
V_293 -> V_306 |= V_246 ;
if ( V_287 . V_313 )
V_293 -> V_306 |= V_296 ;
if ( V_287 . V_314 )
V_293 -> V_306 |= V_298 ;
if ( V_287 . V_314 == V_315 ||
V_287 . V_314 == V_316 )
V_293 -> V_306 |= V_297 ;
}
static void F_145 ( struct V_2 * V_3 ,
struct V_292 * V_293 )
{
int V_82 ;
F_142 ( & V_3 -> V_39 [ 0 ] , V_293 ) ;
F_75 (cdev, i)
F_146 ( & V_3 -> V_39 [ V_82 ] ) ;
}
void F_147 ( struct V_97 * V_98 )
{
void * V_317 = V_98 -> V_3 -> V_318 ;
struct V_319 * V_320 = V_98 -> V_3 -> V_321 . V_322 ;
struct V_292 V_293 ;
F_142 ( V_98 , & V_293 ) ;
F_146 ( V_98 ) ;
if ( F_148 ( V_98 ) && V_317 )
V_320 -> V_323 ( V_317 , & V_293 ) ;
}
static int F_149 ( struct V_2 * V_3 )
{
struct V_97 * V_98 ;
struct V_32 * V_33 ;
int V_82 , V_13 ;
if ( F_131 ( V_3 ) )
return 0 ;
F_75 (cdev, i) {
V_98 = & V_3 -> V_39 [ V_82 ] ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 ) {
F_9 ( V_98 , L_52 ) ;
return - V_223 ;
}
V_13 = F_150 ( V_98 , V_33 ) ;
if ( V_13 )
return V_13 ;
F_38 ( V_98 , V_33 ) ;
}
return 0 ;
}
static void F_151 ( struct V_2 * V_3 , T_8 * V_324 , T_8 * V_325 )
{
* V_324 = V_3 -> V_190 ;
* V_325 = V_3 -> V_326 ;
}
static int F_152 ( struct V_2 * V_3 , T_8 V_324 , T_8 V_325 ,
T_3 V_327 , T_8 V_217 )
{
struct V_97 * V_98 ;
struct V_32 * V_33 ;
int V_219 ;
int V_108 = 0 ;
V_219 = V_327 % V_3 -> V_34 ;
V_98 = & V_3 -> V_39 [ V_219 ] ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_108 = F_153 ( V_98 , V_33 , V_324 ,
V_327 / V_3 -> V_34 , V_217 ) ;
if ( V_108 )
goto V_75;
V_108 = F_154 ( V_98 , V_33 , V_325 ,
V_327 / V_3 -> V_34 , V_217 ) ;
V_75:
F_38 ( V_98 , V_33 ) ;
return V_108 ;
}
static int F_155 ( struct V_2 * V_3 , enum V_329 V_330 )
{
struct V_97 * V_98 = F_33 ( V_3 ) ;
struct V_32 * V_33 ;
int V_108 = 0 ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_108 = F_156 ( V_98 , V_33 , V_330 ) ;
F_38 ( V_98 , V_33 ) ;
return V_108 ;
}
static int F_157 ( struct V_2 * V_3 , bool V_331 )
{
struct V_97 * V_98 = F_33 ( V_3 ) ;
struct V_32 * V_33 ;
int V_13 = 0 ;
if ( F_131 ( V_3 ) )
return 0 ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_13 = F_158 ( V_98 , V_33 , V_331 ? V_332
: V_333 ) ;
if ( V_13 )
goto V_75;
V_13 = F_159 ( V_98 , V_33 , V_334 ) ;
V_75:
F_38 ( V_98 , V_33 ) ;
return V_13 ;
}
static int F_160 ( struct V_2 * V_3 , bool V_335 )
{
struct V_97 * V_98 = F_33 ( V_3 ) ;
struct V_32 * V_33 ;
int V_108 = 0 ;
if ( F_131 ( V_3 ) )
return 0 ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_108 = F_161 ( V_98 , V_33 , V_335 ?
V_336 :
V_337 ) ;
F_38 ( V_98 , V_33 ) ;
return V_108 ;
}
static int F_162 ( struct V_2 * V_3 , T_3 * V_338 )
{
struct V_97 * V_98 = F_33 ( V_3 ) ;
struct V_32 * V_33 ;
int V_108 = 0 ;
if ( F_131 ( V_3 ) )
return 0 ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_108 = F_163 ( V_98 , V_33 , V_338 ) ;
if ( V_108 )
goto V_75;
V_108 = F_159 ( V_98 , V_33 , V_334 ) ;
V_75:
F_38 ( V_98 , V_33 ) ;
return V_108 ;
}
static int F_164 ( struct V_2 * V_3 , T_8 V_61 )
{
struct V_97 * V_98 = F_33 ( V_3 ) ;
struct V_32 * V_33 ;
int V_108 = 0 ;
if ( F_131 ( V_3 ) )
return 0 ;
V_33 = F_35 ( V_98 ) ;
if ( ! V_33 )
return - V_328 ;
V_108 = F_165 ( V_98 , V_33 , V_61 ) ;
if ( V_108 )
goto V_75;
V_108 = F_159 ( V_98 , V_33 , V_334 ) ;
V_75:
F_38 ( V_98 , V_33 ) ;
return V_108 ;
}
void F_166 ( struct V_2 * V_3 ,
enum V_339 type ,
union V_340 * V_341 )
{
struct V_342 V_343 ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
switch ( type ) {
case V_344 :
F_167 ( V_3 , & V_343 ) ;
V_341 -> V_345 . V_346 = V_343 . V_347 ;
V_341 -> V_345 . V_348 = V_343 . V_349 ;
V_341 -> V_345 . V_350 = - 1 ;
break;
case V_351 :
F_168 ( V_3 , & V_341 -> V_352 ) ;
break;
default:
F_48 ( V_3 , L_53 , type ) ;
return;
}
}
