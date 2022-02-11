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
struct V_32 * V_33 = & V_3 -> V_34 ;
struct V_35 * V_36 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
if ( V_33 -> V_37 . V_38 == V_39 &&
V_33 -> V_37 . V_40 )
V_31 -> V_41 = true ;
if ( V_33 -> V_42 . V_40 && V_33 -> V_43 . V_40 &&
V_33 -> V_42 . V_38 == V_39 &&
V_33 -> V_43 . V_38 == V_39 )
V_31 -> V_44 = true ;
if ( V_33 -> V_45 . V_40 && V_33 -> V_46 . V_40 &&
V_33 -> V_45 . V_38 == V_39 &&
V_33 -> V_46 . V_38 == V_39 )
V_31 -> V_47 = true ;
V_31 -> V_48 = V_3 -> V_48 ;
V_31 -> V_49 = V_3 -> V_21 . V_24 ;
V_31 -> V_50 = V_3 -> V_21 . V_25 ;
V_31 -> V_51 = V_3 -> V_21 . V_26 ;
V_31 -> V_52 = ( V_3 -> V_53 [ 0 ] . V_54 . V_55 ==
V_56 ) ;
V_31 -> V_57 = F_31 ( & V_3 -> V_53 [ 0 ] ) ;
V_31 -> V_58 = V_3 -> type ;
F_32 ( V_31 -> V_59 , V_3 -> V_53 [ 0 ] . V_54 . V_60 ) ;
if ( F_18 ( V_3 ) ) {
V_31 -> V_61 = V_62 ;
V_31 -> V_63 = V_64 ;
V_31 -> V_65 = V_66 ;
V_31 -> V_67 = V_68 ;
V_31 -> V_69 = V_3 -> V_69 ;
V_31 -> V_70 = true ;
if ( F_33 ( V_3 ) -> V_54 . V_71 ==
V_72 )
V_31 -> V_73 = true ;
} else {
F_34 ( & V_3 -> V_53 [ 0 ] , & V_31 -> V_61 ,
& V_31 -> V_63 , & V_31 -> V_65 ,
& V_31 -> V_67 ) ;
}
if ( F_18 ( V_3 ) ) {
V_36 = F_35 ( F_33 ( V_3 ) ) ;
if ( V_36 ) {
F_36 ( F_33 ( V_3 ) , V_36 ,
& V_31 -> V_74 , NULL ) ;
F_37 ( F_33 ( V_3 ) , V_36 ,
& V_31 -> V_75 ) ;
F_38 ( F_33 ( V_3 ) , V_36 ) ;
}
} else {
F_36 ( F_33 ( V_3 ) , NULL ,
& V_31 -> V_74 , NULL ) ;
}
V_31 -> V_76 = F_33 ( V_3 ) -> V_54 . V_76 ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
F_40 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_41 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_42 ( sizeof( * V_3 ) , V_77 ) ;
if ( ! V_3 )
return V_3 ;
F_43 ( V_3 ) ;
return V_3 ;
}
static int F_44 ( struct V_2 * V_3 , T_4 V_78 )
{
if ( ! V_3 )
return - V_19 ;
F_45 ( V_3 , V_79 , L_15 ) ;
return 0 ;
}
static struct V_2 * F_46 ( struct V_8 * V_6 ,
struct V_80 * V_81 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_41 ( V_6 ) ;
if ( ! V_3 )
goto V_14;
V_3 -> V_82 = V_81 -> V_82 ;
if ( V_81 -> V_83 )
V_3 -> V_84 = true ;
F_47 ( V_3 , V_81 -> V_85 , V_81 -> V_86 ) ;
V_13 = F_15 ( V_3 , V_6 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_16 ) ;
goto V_16;
}
F_49 ( V_3 , L_17 ) ;
V_13 = F_50 ( V_3 , V_87 ) ;
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
F_44 ( V_3 , V_88 ) ;
F_39 ( V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
if ( V_3 -> V_89 . V_90 . V_91 == V_92 ) {
F_54 ( V_3 -> V_6 ) ;
F_40 ( V_3 -> V_89 . V_93 ) ;
} else if ( V_3 -> V_89 . V_90 . V_91 == V_94 ) {
F_55 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_89 . V_90 , 0 , sizeof( struct V_95 ) ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_96 * V_89 )
{
int V_97 , V_13 , V_98 ;
V_98 = V_89 -> V_99 . V_100 ;
for ( V_97 = 0 ; V_97 < V_98 ; V_97 ++ )
V_89 -> V_93 [ V_97 ] . V_101 = V_97 ;
V_13 = F_57 ( V_3 -> V_6 , V_89 -> V_93 ,
V_89 -> V_99 . V_102 , V_98 ) ;
if ( V_13 < V_98 && V_13 >= V_89 -> V_99 . V_102 &&
( V_13 % V_3 -> V_48 ) ) {
F_54 ( V_3 -> V_6 ) ;
V_98 = ( V_13 / V_3 -> V_48 ) * V_3 -> V_48 ;
F_9 ( V_3 ,
L_20 ,
V_98 , V_89 -> V_99 . V_100 ) ;
V_13 = F_58 ( V_3 -> V_6 , V_89 -> V_93 ,
V_98 ) ;
if ( ! V_13 )
V_13 = V_98 ;
}
if ( V_13 > 0 ) {
V_89 -> V_90 . V_91 = V_92 ;
V_89 -> V_90 . V_100 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_21 ,
V_98 , V_13 ) ;
}
return V_13 ;
}
static int F_59 ( struct V_2 * V_3 , bool V_103 )
{
struct V_96 * V_89 = & V_3 -> V_89 ;
struct V_104 * V_105 ;
int V_13 = 0 , V_98 ;
switch ( V_89 -> V_99 . V_91 ) {
case V_92 :
V_98 = V_89 -> V_99 . V_100 ;
V_89 -> V_93 = F_60 ( V_98 , sizeof( * V_105 ) , V_77 ) ;
if ( ! V_89 -> V_93 ) {
V_13 = - V_27 ;
goto V_90;
}
V_13 = F_56 ( V_3 , V_89 ) ;
if ( ! V_13 )
goto V_90;
F_9 ( V_3 , L_22 ) ;
F_40 ( V_89 -> V_93 ) ;
if ( V_103 )
goto V_90;
case V_94 :
if ( V_3 -> V_48 == 1 ) {
V_13 = F_61 ( V_3 -> V_6 ) ;
if ( ! V_13 ) {
V_89 -> V_90 . V_91 = V_94 ;
goto V_90;
}
F_9 ( V_3 , L_23 ) ;
if ( V_103 )
goto V_90;
}
case V_106 :
V_89 -> V_90 . V_91 = V_106 ;
V_13 = 0 ;
goto V_90;
default:
F_9 ( V_3 , L_24 ,
V_89 -> V_99 . V_91 ) ;
V_13 = - V_107 ;
}
V_90:
if ( ! V_13 )
F_49 ( V_3 , L_25 ,
V_89 -> V_90 . V_91 == V_106 ?
L_26 : V_89 -> V_90 . V_91 == V_94 ?
L_27 : L_28 ) ;
V_3 -> V_108 = V_109 ;
return V_13 ;
}
static void F_62 ( struct V_2 * V_3 , void * V_110 ,
int V_111 , void (* F_63)( void * ) )
{
struct V_112 * V_113 = & V_3 -> V_53 [ V_111 % V_3 -> V_48 ] ;
int V_114 = V_111 / V_3 -> V_48 ;
V_113 -> V_115 [ V_114 ] . V_116 = F_63 ;
V_113 -> V_115 [ V_114 ] . V_110 = V_110 ;
}
static void F_64 ( struct V_2 * V_3 , int V_111 )
{
struct V_112 * V_113 = & V_3 -> V_53 [ V_111 % V_3 -> V_48 ] ;
int V_114 = V_111 / V_3 -> V_48 ;
memset ( & V_113 -> V_115 [ V_114 ] , 0 ,
sizeof( struct V_117 ) ) ;
}
static T_5 F_65 ( int V_26 , void * V_118 )
{
F_66 ( (struct V_119 * ) V_118 ) ;
return V_120 ;
}
static T_5 F_67 ( int V_26 , void * V_121 )
{
struct V_2 * V_3 = (struct V_2 * ) V_121 ;
struct V_112 * V_113 ;
T_5 V_13 = V_122 ;
T_6 V_123 ;
int V_97 , V_124 ;
for ( V_97 = 0 ; V_97 < V_3 -> V_48 ; V_97 ++ ) {
V_123 = F_68 ( & V_3 -> V_53 [ V_97 ] ) ;
if ( ! V_123 )
continue;
V_113 = & V_3 -> V_53 [ V_97 ] ;
if ( F_69 ( V_123 & 0x1 ) ) {
F_66 ( V_113 -> V_125 ) ;
V_123 &= ~ 0x1 ;
V_13 = V_120 ;
}
for ( V_124 = 0 ; V_124 < 64 ; V_124 ++ ) {
if ( ( 0x2ULL << V_124 ) & V_123 ) {
V_113 -> V_115 [ V_124 ] . V_116 (
V_113 -> V_115 [ V_124 ] . V_110 ) ;
V_123 &= ~ ( 0x2ULL << V_124 ) ;
V_13 = V_120 ;
}
}
if ( F_69 ( V_123 ) )
F_45 ( V_113 , V_126 ,
L_29 ,
V_123 ) ;
}
return V_13 ;
}
int F_70 ( struct V_112 * V_113 )
{
struct V_2 * V_3 = V_113 -> V_3 ;
T_7 V_91 ;
int V_13 = 0 ;
T_3 V_127 ;
V_91 = V_3 -> V_89 . V_90 . V_91 ;
if ( V_91 == V_92 ) {
V_127 = V_113 -> V_128 ;
snprintf ( V_113 -> V_129 , V_130 , L_30 ,
V_127 , V_3 -> V_6 -> V_131 -> V_132 ,
F_71 ( V_3 -> V_6 -> V_133 ) , V_113 -> V_134 ) ;
V_13 = F_72 ( V_3 -> V_89 . V_93 [ V_127 ] . V_135 ,
F_65 , 0 , V_113 -> V_129 , V_113 -> V_125 ) ;
} else {
unsigned long V_136 = 0 ;
snprintf ( V_3 -> V_129 , V_130 , L_31 ,
V_3 -> V_6 -> V_131 -> V_132 , F_71 ( V_3 -> V_6 -> V_133 ) ,
F_73 ( V_3 -> V_6 -> V_133 ) ) ;
if ( V_3 -> V_89 . V_90 . V_91 == V_106 )
V_136 |= V_137 ;
V_13 = F_72 ( V_3 -> V_6 -> V_26 , F_67 ,
V_136 , V_3 -> V_129 , V_3 ) ;
}
if ( V_13 )
F_9 ( V_3 , L_32 , V_13 ) ;
else
F_45 ( V_113 , ( V_126 | V_138 ) ,
L_33 ,
( V_91 == V_92 ) ? L_34 : L_35 ) ;
return V_13 ;
}
void F_74 ( struct V_112 * V_139 )
{
struct V_2 * V_3 = V_139 -> V_3 ;
T_3 V_127 = V_139 -> V_128 ;
T_7 V_91 ;
V_91 = V_3 -> V_89 . V_90 . V_91 ;
if ( V_91 == V_92 )
F_75 ( V_3 -> V_89 . V_93 [ V_127 ] . V_135 ) ;
else
F_75 ( V_3 -> V_6 -> V_26 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
int V_97 ;
if ( V_3 -> V_89 . V_90 . V_91 == V_92 ) {
F_77 (cdev, i) {
if ( ! V_3 -> V_53 [ V_97 ] . V_140 )
break;
F_75 ( V_3 -> V_89 . V_93 [ V_97 ] . V_135 ) ;
F_78 ( V_3 -> V_89 . V_93 [ V_97 ] . V_135 ,
V_3 -> V_53 [ V_97 ] . V_125 ) ;
}
} else {
if ( F_33 ( V_3 ) -> V_140 )
F_78 ( V_3 -> V_6 -> V_26 , V_3 ) ;
}
F_79 ( V_3 ) ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_97 , V_13 ;
V_13 = F_81 ( V_3 ) ;
for ( V_97 = 0 ; V_97 < V_3 -> V_48 ; V_97 ++ ) {
struct V_112 * V_139 = & V_3 -> V_53 [ V_97 ] ;
if ( V_139 -> V_141 ) {
F_82 ( V_139 -> V_125 ) ;
V_139 -> V_141 = false ;
F_45 ( V_3 , V_142 ,
L_36 ,
V_97 , V_139 -> V_125 ) ;
}
}
F_83 ( V_3 ) ;
return V_13 ;
}
static int F_84 ( struct V_2 * V_3 )
{
int V_13 , V_97 ;
if ( F_33 ( V_3 ) -> V_54 . V_55 != V_143 ) {
for ( V_97 = 0 ; V_97 < V_3 -> V_48 ; V_97 ++ ) {
struct V_112 * V_139 = & V_3 -> V_53 [ V_97 ] ;
V_139 -> V_144 = true ;
}
}
V_13 = F_85 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_49 ( V_3 , L_37 ) ;
F_86 ( V_3 ) ;
return V_13 ;
}
static int F_87 ( struct V_2 * V_3 , T_8 V_98 )
{
int V_145 = 0 ;
V_3 -> V_89 . V_146 = V_98 ? true : false ;
if ( V_3 -> V_89 . V_90 . V_91 != V_92 )
V_145 = V_3 -> V_48 * 63 ;
else if ( V_3 -> V_89 . V_147 )
V_145 = V_3 -> V_89 . V_147 ;
if ( ! V_145 )
return - V_27 ;
return F_88 ( int , V_98 , V_145 ) ;
}
static int F_89 ( struct V_2 * V_3 , struct V_148 * V_149 )
{
memset ( V_149 , 0 , sizeof( struct V_148 ) ) ;
if ( ! V_3 -> V_89 . V_146 ) {
F_49 ( V_3 ,
L_38 ) ;
return - V_107 ;
}
if ( V_3 -> V_89 . V_90 . V_91 == V_92 ) {
int V_150 = V_3 -> V_89 . V_151 ;
V_149 -> V_152 = V_3 -> V_89 . V_147 ;
V_149 -> V_153 = & V_3 -> V_89 . V_93 [ V_150 ] ;
}
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
enum V_154 V_91 )
{
struct V_155 V_156 ;
int V_157 = 0 ;
int V_13 ;
int V_97 ;
if ( ( V_91 == V_94 ) && ( V_3 -> V_48 > 1 ) ) {
F_9 ( V_3 , L_39 ) ;
return - V_107 ;
}
memset ( & V_3 -> V_89 , 0 , sizeof( struct V_96 ) ) ;
V_3 -> V_89 . V_99 . V_91 = V_91 ;
F_77 (cdev, i) {
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
F_91 ( & V_3 -> V_53 [ V_97 ] , & V_156 ) ;
V_3 -> V_89 . V_99 . V_100 += V_156 . V_158 ;
V_3 -> V_89 . V_99 . V_100 ++ ;
}
V_3 -> V_89 . V_99 . V_102 = V_3 -> V_48 * 2 ;
V_13 = F_59 ( V_3 , false ) ;
if ( V_13 ) {
F_48 ( V_3 , L_40 ) ;
return V_13 ;
}
V_3 -> V_89 . V_151 = V_3 -> V_48 ;
V_3 -> V_89 . V_147 = V_3 -> V_89 . V_90 . V_100 -
V_3 -> V_48 ;
if ( ! F_92 ( V_159 ) ||
F_33 ( V_3 ) -> V_54 . V_55 != V_56 )
return 0 ;
F_77 (cdev, i)
V_157 += F_93 ( & V_3 -> V_53 [ V_97 ] , V_160 ) ;
F_45 ( V_3 , V_161 ,
L_41 ,
V_3 -> V_89 . V_147 , V_157 ) ;
if ( V_3 -> V_89 . V_147 > V_157 ) {
V_3 -> V_89 . V_162 =
( V_3 -> V_89 . V_147 - V_157 )
/ V_3 -> V_48 ;
V_3 -> V_89 . V_163 =
V_3 -> V_89 . V_151 + V_157 ;
V_3 -> V_89 . V_147 = V_157 ;
} else {
V_3 -> V_89 . V_162 = 0 ;
}
F_45 ( V_3 , V_161 , L_42 ,
V_3 -> V_89 . V_162 ,
V_3 -> V_89 . V_163 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 )
{
int V_13 ;
memset ( & V_3 -> V_89 , 0 , sizeof( struct V_96 ) ) ;
V_3 -> V_89 . V_99 . V_91 = V_92 ;
F_95 ( F_33 ( V_3 ) ,
& V_3 -> V_89 . V_99 . V_100 ) ;
if ( V_3 -> V_48 > 1 ) {
T_3 V_164 = 0 ;
F_95 ( & V_3 -> V_53 [ 1 ] , & V_164 ) ;
V_3 -> V_89 . V_99 . V_100 += V_164 ;
}
V_3 -> V_89 . V_99 . V_102 = V_3 -> V_48 ;
V_13 = F_59 ( V_3 , true ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_89 . V_151 = 0 ;
V_3 -> V_89 . V_147 = V_3 -> V_89 . V_90 . V_100 ;
return 0 ;
}
T_7 F_96 ( struct V_112 * V_139 , T_7 V_165 ,
T_3 * V_166 , T_7 V_167 , T_3 * V_168 )
{
int V_13 ;
V_139 -> V_169 -> V_170 = V_166 ;
V_139 -> V_169 -> V_171 = V_165 ;
V_139 -> V_169 -> V_172 = V_168 ;
V_139 -> V_169 -> V_173 = V_167 ;
V_13 = F_97 ( V_139 -> V_169 , V_174 ) ;
if ( V_13 != V_175 ) {
F_45 ( V_139 , V_79 , L_43 ,
V_13 ) ;
return 0 ;
}
V_13 = F_98 ( V_139 -> V_169 , V_176 ) ;
F_99 ( V_139 -> V_169 ) ;
if ( V_13 != V_175 && V_13 != V_177 ) {
F_45 ( V_139 , V_79 , L_44 ,
V_139 -> V_169 -> V_178 , V_13 ) ;
return 0 ;
}
return V_139 -> V_169 -> V_179 / 4 ;
}
static int F_100 ( struct V_2 * V_3 )
{
int V_97 ;
void * V_180 ;
F_77 (cdev, i) {
struct V_112 * V_139 = & V_3 -> V_53 [ V_97 ] ;
V_139 -> V_169 = F_42 ( sizeof( * V_139 -> V_169 ) , V_77 ) ;
if ( ! V_139 -> V_169 )
return - V_27 ;
V_180 = F_101 ( F_102 () ) ;
if ( ! V_180 )
return - V_27 ;
V_139 -> V_169 -> V_180 = V_180 ;
}
return 0 ;
}
static void F_103 ( struct V_2 * V_3 )
{
int V_97 ;
F_77 (cdev, i) {
struct V_112 * V_139 = & V_3 -> V_53 [ V_97 ] ;
if ( ! V_139 -> V_169 )
return;
F_104 ( V_139 -> V_169 -> V_180 ) ;
F_40 ( V_139 -> V_169 ) ;
}
}
static void F_105 ( struct V_2 * V_3 ,
struct V_181 * V_81 )
{
int V_97 ;
if ( F_92 ( V_159 ) ) {
V_81 -> V_182 . V_183 = V_184 ;
V_81 -> V_182 . V_185 = V_186 ;
V_81 -> V_182 . V_187 = V_188 ;
}
if ( V_3 -> V_48 > 1 || F_106 ( V_3 ) )
V_81 -> V_189 . V_190 = 0 ;
if ( F_33 ( V_3 ) -> V_54 . V_55 ==
V_56 ) {
T_8 * V_191 ;
V_191 = & V_81 -> V_189 . V_191 ;
* V_191 = F_88 ( T_8 , * V_191 , 192 ) ;
}
for ( V_97 = 0 ; V_97 < V_3 -> V_48 ; V_97 ++ ) {
struct V_112 * V_139 = & V_3 -> V_53 [ V_97 ] ;
V_139 -> V_192 = * V_81 ;
}
}
static int F_107 ( struct V_2 * V_3 ,
struct V_193 * V_81 )
{
struct V_194 V_195 ;
struct V_196 V_197 ;
struct V_198 V_199 ;
struct V_32 V_200 ;
const T_3 * V_201 = NULL ;
struct V_112 * V_113 ;
#ifdef F_108
struct V_35 * V_202 ;
#endif
int V_13 = - V_107 ;
if ( F_109 ( V_3 ) )
goto V_203;
if ( F_18 ( V_3 ) ) {
V_13 = F_110 ( & V_3 -> V_204 , V_205 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_45 ,
V_205 ) ;
goto V_203;
}
#ifdef F_108
if ( V_3 -> V_48 == 1 ) {
V_202 = F_35 ( F_33 ( V_3 ) ) ;
if ( V_202 ) {
F_33 ( V_3 ) -> V_206 = V_202 ;
} else {
F_9 ( V_3 ,
L_46 ) ;
goto V_203;
}
}
#endif
}
V_3 -> V_207 = V_208 ;
V_13 = F_84 ( V_3 ) ;
if ( V_13 )
goto V_203;
if ( F_18 ( V_3 ) )
V_13 = F_90 ( V_3 , V_81 -> V_91 ) ;
else
V_13 = F_94 ( V_3 ) ;
if ( V_13 )
goto V_16;
if ( F_18 ( V_3 ) ) {
V_13 = F_100 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_201 = V_3 -> V_204 -> V_201 + sizeof( T_7 ) ;
F_111 ( V_3 ) ;
}
memset ( & V_197 , 0 , sizeof( V_197 ) ) ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_37 . V_40 = true ;
V_200 . V_42 . V_40 = true ;
V_200 . V_43 . V_40 = true ;
V_200 . V_45 . V_40 = true ;
V_200 . V_46 . V_40 = true ;
V_200 . V_37 . V_38 = V_39 ;
V_200 . V_42 . V_38 = V_39 ;
V_200 . V_43 . V_38 = V_39 ;
V_200 . V_45 . V_38 = V_39 ;
V_200 . V_46 . V_38 = V_39 ;
V_197 . V_209 = & V_200 ;
V_197 . V_210 = true ;
V_197 . V_91 = V_3 -> V_89 . V_90 . V_91 ;
V_197 . V_211 = true ;
V_197 . V_212 = V_201 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_213 = F_112 () ;
V_195 . V_214 = V_215 ;
V_195 . V_216 = false ;
V_195 . V_217 = V_218 ;
V_197 . V_219 = & V_195 ;
V_13 = F_113 ( V_3 , & V_197 ) ;
if ( V_13 )
goto V_20;
F_49 ( V_3 ,
L_47 ) ;
if ( F_18 ( V_3 ) ) {
V_3 -> V_220 = ( F_114 ( V_221 ) |
F_114 ( V_222 ) |
F_114 ( V_223 ) |
F_114 ( V_224 ) |
F_114 ( V_225 ) ) ;
}
if ( F_33 ( V_3 ) -> V_144 ) {
V_13 = F_115 ( V_3 ) ;
if ( V_13 )
goto V_226;
}
if ( F_18 ( V_3 ) ) {
V_113 = F_33 ( V_3 ) ;
V_199 . V_1 = ( V_81 -> V_227 << 24 ) |
( V_81 -> V_228 << 16 ) |
( V_81 -> V_229 << 8 ) |
( V_81 -> V_230 ) ;
F_116 ( V_199 . V_129 , V_81 -> V_129 ,
V_231 - 4 ) ;
V_13 = F_117 ( V_113 , V_113 -> V_232 ,
& V_199 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_48 ) ;
return V_13 ;
}
}
F_118 ( V_3 ) ;
return 0 ;
V_226:
F_81 ( V_3 ) ;
V_20:
F_119 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_76 ( V_3 ) ;
F_103 ( V_3 ) ;
F_53 ( V_3 ) ;
V_16:
F_120 ( V_3 ) ;
V_203:
if ( F_18 ( V_3 ) )
F_121 ( V_3 -> V_204 ) ;
#ifdef F_108
if ( F_18 ( V_3 ) && ( V_3 -> V_48 == 1 ) &&
F_33 ( V_3 ) -> V_206 )
F_38 ( F_33 ( V_3 ) ,
F_33 ( V_3 ) -> V_206 ) ;
#endif
F_122 ( V_3 , false ) ;
return V_13 ;
}
static int F_123 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
F_124 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
#ifdef F_108
if ( V_3 -> V_48 == 1 )
F_38 ( F_33 ( V_3 ) ,
F_33 ( V_3 ) -> V_206 ) ;
#endif
F_103 ( V_3 ) ;
if ( F_125 ( V_3 ) )
F_126 ( V_3 , true ) ;
}
F_80 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_76 ( V_3 ) ;
F_53 ( V_3 ) ;
F_120 ( V_3 ) ;
F_122 ( V_3 , true ) ;
if ( F_18 ( V_3 ) )
F_121 ( V_3 -> V_204 ) ;
return 0 ;
}
static void F_127 ( struct V_2 * V_3 , char V_129 [ V_130 ] ,
char V_233 [ V_234 ] )
{
int V_97 ;
memcpy ( V_3 -> V_129 , V_129 , V_130 ) ;
F_77 (cdev, i)
snprintf ( V_3 -> V_53 [ V_97 ] . V_129 , V_130 , L_49 , V_129 , V_97 ) ;
memcpy ( V_3 -> V_233 , V_233 , V_234 ) ;
V_3 -> V_235 = V_236 ;
}
static T_7 F_128 ( struct V_2 * V_3 ,
struct V_237 * V_238 ,
void * V_239 ,
T_9 V_240 , T_8 V_241 ,
enum V_242 type )
{
struct V_112 * V_139 ;
struct V_35 * V_202 ;
int V_243 ;
T_8 V_244 ;
T_3 V_245 ;
T_7 V_13 ;
if ( type == V_246 )
V_245 = V_3 -> V_48 ;
else
V_245 = 1 ;
V_243 = V_241 % V_245 ;
V_139 = & V_3 -> V_53 [ V_243 ] ;
V_244 = V_241 / V_245 ;
F_45 ( V_3 , V_126 ,
L_50 ,
V_243 , V_244 , V_241 ) ;
if ( F_18 ( V_139 -> V_3 ) ) {
V_202 = F_35 ( V_139 ) ;
if ( ! V_202 )
return - V_247 ;
V_13 = F_129 ( V_139 , V_202 , V_238 , V_239 ,
V_240 , V_244 ) ;
F_38 ( V_139 , V_202 ) ;
} else {
V_13 = F_129 ( V_139 , NULL , V_238 , V_239 ,
V_240 , V_244 ) ;
}
return V_13 ;
}
static T_7 F_130 ( struct V_2 * V_3 ,
struct V_237 * V_238 , T_8 V_241 )
{
struct V_112 * V_139 ;
int V_243 ;
T_8 V_244 ;
T_7 V_13 ;
V_243 = V_241 % V_3 -> V_48 ;
V_139 = & V_3 -> V_53 [ V_243 ] ;
V_244 = V_241 / V_3 -> V_48 ;
F_45 ( V_3 , V_126 ,
L_50 ,
V_243 , V_244 , V_241 ) ;
V_13 = F_131 ( V_139 , V_238 , V_244 ) ;
return V_13 ;
}
static bool F_132 ( struct V_2 * V_3 )
{
return true ;
}
static int F_133 ( struct V_2 * V_3 , struct V_248 * V_81 )
{
struct V_112 * V_113 ;
struct V_249 * V_250 ;
struct V_35 * V_36 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
V_113 = & V_3 -> V_53 [ 0 ] ;
if ( F_106 ( V_3 ) ) {
F_134 ( V_113 , V_251 ) ;
return 0 ;
}
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_247 ;
V_250 = F_135 ( V_113 ) ;
if ( V_81 -> V_252 & V_253 )
V_250 -> V_254 . V_255 = V_81 -> V_255 ;
if ( V_81 -> V_252 & V_256 ) {
V_250 -> V_254 . V_257 = 0 ;
if ( ( V_81 -> V_258 & V_259 ) ||
( V_81 -> V_258 & V_260 ) )
V_250 -> V_254 . V_257 |=
V_261 ;
if ( V_81 -> V_258 & V_262 )
V_250 -> V_254 . V_257 |=
V_263 ;
if ( V_81 -> V_258 & V_264 )
V_250 -> V_254 . V_257 |=
V_265 ;
if ( V_81 -> V_258 & V_266 )
V_250 -> V_254 . V_257 |=
V_267 ;
if ( V_81 -> V_258 & V_268 )
V_250 -> V_254 . V_257 |=
V_269 ;
if ( V_81 -> V_258 & V_270 )
V_250 -> V_254 . V_257 |=
V_271 ;
}
if ( V_81 -> V_252 & V_272 )
V_250 -> V_254 . V_273 = V_81 -> V_273 ;
if ( V_81 -> V_252 & V_274 ) {
if ( V_81 -> V_275 & V_276 )
V_250 -> V_277 . V_255 = true ;
else
V_250 -> V_277 . V_255 = false ;
if ( V_81 -> V_275 & V_278 )
V_250 -> V_277 . V_279 = true ;
else
V_250 -> V_277 . V_279 = false ;
if ( V_81 -> V_275 & V_280 )
V_250 -> V_277 . V_281 = true ;
else
V_250 -> V_277 . V_281 = false ;
}
if ( V_81 -> V_252 & V_282 ) {
switch ( V_81 -> V_283 ) {
case V_284 :
V_250 -> V_283 = V_285 ;
break;
case V_286 :
V_250 -> V_283 = V_287 ;
break;
case V_288 :
V_250 -> V_283 = V_289 ;
break;
case V_290 :
V_250 -> V_283 = V_291 ;
break;
default:
V_250 -> V_283 = V_292 ;
break;
}
}
V_13 = F_136 ( V_113 , V_36 , V_81 -> V_293 ) ;
F_38 ( V_113 , V_36 ) ;
return V_13 ;
}
static int F_137 ( T_7 V_294 )
{
int V_295 ;
switch ( V_294 ) {
case V_296 :
case V_297 :
case V_298 :
case V_299 :
case V_300 :
V_295 = V_301 ;
break;
case V_302 :
V_295 = V_303 ;
break;
case V_304 :
V_295 = V_305 ;
break;
case V_306 :
V_295 = V_307 ;
break;
case V_308 :
default:
V_295 = V_309 ;
break;
}
return V_295 ;
}
static int F_138 ( struct V_112 * V_113 ,
struct V_249 * V_81 ,
struct V_310 * V_311 ,
struct V_312 * V_313 )
{
void * V_314 ;
if ( ! F_18 ( V_113 -> V_3 ) ) {
F_139 ( V_113 , V_81 ) ;
F_140 ( V_113 , V_311 ) ;
F_141 ( V_113 , V_313 ) ;
return 0 ;
}
V_314 = F_135 ( V_113 ) ;
if ( ! V_314 )
return - V_315 ;
memcpy ( V_81 , V_314 , sizeof( * V_81 ) ) ;
V_314 = F_142 ( V_113 ) ;
if ( ! V_314 )
return - V_315 ;
memcpy ( V_311 , V_314 , sizeof( * V_311 ) ) ;
V_314 = F_143 ( V_113 ) ;
if ( ! V_314 )
return - V_315 ;
memcpy ( V_313 , V_314 , sizeof( * V_313 ) ) ;
return 0 ;
}
static void F_144 ( struct V_112 * V_113 ,
struct V_316 * V_317 )
{
struct V_249 V_81 ;
struct V_310 V_311 ;
struct V_312 V_313 ;
T_7 V_294 ;
memset ( V_317 , 0 , sizeof( * V_317 ) ) ;
if ( F_138 ( V_113 , & V_81 , & V_311 , & V_313 ) ) {
F_145 ( & V_113 -> V_3 -> V_6 -> V_5 , L_51 ) ;
return;
}
if ( V_311 . V_293 )
V_317 -> V_293 = true ;
V_317 -> V_318 = V_319 ;
if ( V_313 . V_320 )
V_317 -> V_318 |= V_321 ;
if ( V_81 . V_277 . V_255 ||
( V_81 . V_277 . V_279 && V_81 . V_277 . V_281 ) )
V_317 -> V_318 |= V_322 ;
if ( V_81 . V_277 . V_255 || V_81 . V_277 . V_279 ||
V_81 . V_277 . V_281 )
V_317 -> V_318 |= V_323 ;
V_317 -> V_324 = V_317 -> V_318 ;
if ( V_81 . V_254 . V_255 )
V_317 -> V_324 |= V_321 ;
else
V_317 -> V_324 &= ~ V_321 ;
if ( V_81 . V_254 . V_257 &
V_261 )
V_317 -> V_324 |= V_259 |
V_260 ;
if ( V_81 . V_254 . V_257 &
V_263 )
V_317 -> V_324 |= V_262 ;
if ( V_81 . V_254 . V_257 &
V_265 )
V_317 -> V_324 |= V_264 ;
if ( V_81 . V_254 . V_257 &
V_267 )
V_317 -> V_324 |= V_266 ;
if ( V_81 . V_254 . V_257 &
V_269 )
V_317 -> V_324 |= V_268 ;
if ( V_81 . V_254 . V_257 &
V_271 )
V_317 -> V_324 |= V_270 ;
if ( V_313 . V_325 &
V_261 )
V_317 -> V_318 |= V_259 |
V_260 ;
if ( V_313 . V_325 &
V_263 )
V_317 -> V_318 |= V_262 ;
if ( V_313 . V_325 &
V_265 )
V_317 -> V_318 |= V_264 ;
if ( V_313 . V_325 &
V_267 )
V_317 -> V_318 |= V_266 ;
if ( V_313 . V_325 &
V_269 )
V_317 -> V_318 |= V_268 ;
if ( V_313 . V_325 &
V_271 )
V_317 -> V_318 |= V_270 ;
if ( V_311 . V_293 )
V_317 -> V_254 = V_311 . V_254 ;
V_317 -> V_326 = V_327 ;
F_146 ( V_113 -> V_3 , & V_294 ) ;
V_317 -> V_328 = F_137 ( V_294 ) ;
V_317 -> V_255 = V_81 . V_254 . V_255 ;
if ( V_81 . V_277 . V_255 )
V_317 -> V_275 |= V_276 ;
if ( V_81 . V_277 . V_279 )
V_317 -> V_275 |= V_278 ;
if ( V_81 . V_277 . V_281 )
V_317 -> V_275 |= V_280 ;
if ( V_311 . V_329 & V_330 )
V_317 -> V_331 |= V_259 ;
if ( V_311 . V_329 & V_332 )
V_317 -> V_331 |= V_260 ;
if ( V_311 . V_329 & V_333 )
V_317 -> V_331 |= V_262 ;
if ( V_311 . V_329 & V_334 )
V_317 -> V_331 |= V_264 ;
if ( V_311 . V_329 & V_335 )
V_317 -> V_331 |= V_266 ;
if ( V_311 . V_329 & V_336 )
V_317 -> V_331 |= V_268 ;
if ( V_311 . V_329 & V_337 )
V_317 -> V_331 |= V_270 ;
if ( V_311 . V_338 )
V_317 -> V_331 |= V_321 ;
if ( V_311 . V_339 )
V_317 -> V_331 |= V_323 ;
if ( V_311 . V_339 == V_340 ||
V_311 . V_339 == V_341 )
V_317 -> V_331 |= V_322 ;
}
static void F_147 ( struct V_2 * V_3 ,
struct V_316 * V_317 )
{
int V_97 ;
F_144 ( & V_3 -> V_53 [ 0 ] , V_317 ) ;
F_77 (cdev, i)
F_148 ( & V_3 -> V_53 [ V_97 ] ) ;
}
void F_149 ( struct V_112 * V_113 )
{
void * V_342 = V_113 -> V_3 -> V_343 ;
struct V_344 * V_345 = V_113 -> V_3 -> V_346 . V_347 ;
struct V_316 V_317 ;
F_144 ( V_113 , & V_317 ) ;
F_148 ( V_113 ) ;
if ( F_150 ( V_113 ) && V_342 )
V_345 -> V_348 ( V_342 , & V_317 ) ;
}
static int F_151 ( struct V_2 * V_3 )
{
struct V_112 * V_113 ;
struct V_35 * V_36 ;
int V_97 , V_13 ;
if ( F_106 ( V_3 ) )
return 0 ;
F_77 (cdev, i) {
V_113 = & V_3 -> V_53 [ V_97 ] ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 ) {
F_9 ( V_113 , L_52 ) ;
return - V_247 ;
}
V_13 = F_152 ( V_113 , V_36 ) ;
if ( V_13 )
return V_13 ;
F_38 ( V_113 , V_36 ) ;
}
return 0 ;
}
static void F_153 ( struct V_2 * V_3 , T_8 * V_349 , T_8 * V_350 )
{
* V_349 = V_3 -> V_207 ;
* V_350 = V_3 -> V_351 ;
}
static int F_154 ( struct V_2 * V_3 , T_8 V_349 , T_8 V_350 ,
T_8 V_352 , T_8 V_241 )
{
struct V_112 * V_113 ;
struct V_35 * V_36 ;
int V_243 ;
int V_123 = 0 ;
V_243 = V_352 % V_3 -> V_48 ;
V_113 = & V_3 -> V_53 [ V_243 ] ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_123 = F_155 ( V_113 , V_36 , V_349 ,
V_352 / V_3 -> V_48 , V_241 ) ;
if ( V_123 )
goto V_90;
V_123 = F_156 ( V_113 , V_36 , V_350 ,
V_352 / V_3 -> V_48 , V_241 ) ;
V_90:
F_38 ( V_113 , V_36 ) ;
return V_123 ;
}
static int F_157 ( struct V_2 * V_3 , enum V_354 V_355 )
{
struct V_112 * V_113 = F_33 ( V_3 ) ;
struct V_35 * V_36 ;
int V_123 = 0 ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_123 = F_158 ( V_113 , V_36 , V_355 ) ;
F_38 ( V_113 , V_36 ) ;
return V_123 ;
}
static int F_159 ( struct V_2 * V_3 , bool V_356 )
{
struct V_112 * V_113 = F_33 ( V_3 ) ;
struct V_35 * V_36 ;
int V_13 = 0 ;
if ( F_106 ( V_3 ) )
return 0 ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_13 = F_160 ( V_113 , V_36 , V_356 ? V_357
: V_358 ) ;
if ( V_13 )
goto V_90;
V_13 = F_161 ( V_113 , V_36 , V_359 ) ;
V_90:
F_38 ( V_113 , V_36 ) ;
return V_13 ;
}
static int F_162 ( struct V_2 * V_3 , bool V_360 )
{
struct V_112 * V_113 = F_33 ( V_3 ) ;
struct V_35 * V_36 ;
int V_123 = 0 ;
if ( F_106 ( V_3 ) )
return 0 ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_123 = F_163 ( V_113 , V_36 , V_360 ?
V_361 :
V_362 ) ;
F_38 ( V_113 , V_36 ) ;
return V_123 ;
}
static int F_164 ( struct V_2 * V_3 , T_3 * V_363 )
{
struct V_112 * V_113 = F_33 ( V_3 ) ;
struct V_35 * V_36 ;
int V_123 = 0 ;
if ( F_106 ( V_3 ) )
return 0 ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_123 = F_165 ( V_113 , V_36 , V_363 ) ;
if ( V_123 )
goto V_90;
V_123 = F_161 ( V_113 , V_36 , V_359 ) ;
V_90:
F_38 ( V_113 , V_36 ) ;
return V_123 ;
}
static int F_166 ( struct V_2 * V_3 , T_8 V_76 )
{
struct V_112 * V_113 = F_33 ( V_3 ) ;
struct V_35 * V_36 ;
int V_123 = 0 ;
if ( F_106 ( V_3 ) )
return 0 ;
V_36 = F_35 ( V_113 ) ;
if ( ! V_36 )
return - V_353 ;
V_123 = F_167 ( V_113 , V_36 , V_76 ) ;
if ( V_123 )
goto V_90;
V_123 = F_161 ( V_113 , V_36 , V_359 ) ;
V_90:
F_38 ( V_113 , V_36 ) ;
return V_123 ;
}
void F_168 ( struct V_2 * V_3 ,
enum V_364 type ,
union V_365 * V_366 )
{
struct V_367 V_368 ;
memset ( V_366 , 0 , sizeof( * V_366 ) ) ;
switch ( type ) {
case V_369 :
F_169 ( V_3 , & V_368 ) ;
V_366 -> V_370 . V_371 =
V_368 . V_347 . V_372 ;
V_366 -> V_370 . V_373 =
V_368 . V_347 . V_374 ;
V_366 -> V_370 . V_375 = - 1 ;
break;
case V_376 :
F_170 ( V_3 , & V_366 -> V_377 ) ;
break;
case V_378 :
F_171 ( V_3 , & V_366 -> V_379 ) ;
break;
default:
F_45 ( V_3 , V_138 ,
L_53 , type ) ;
return;
}
}
