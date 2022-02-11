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
static int F_44 ( struct V_2 * V_3 , T_4 V_59 )
{
if ( ! V_3 )
return - V_19 ;
F_45 ( V_3 , V_60 , L_15 ) ;
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
F_48 ( V_3 , L_16 ) ;
goto V_16;
}
F_49 ( V_3 , L_17 ) ;
V_13 = F_50 ( V_3 , V_68 ) ;
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
L_20 ,
V_79 , V_70 -> V_80 . V_81 ) ;
V_13 = F_58 ( V_3 -> V_6 , V_70 -> V_74 ,
V_79 ) ;
if ( ! V_13 )
V_13 = V_79 ;
}
if ( V_13 > 0 ) {
V_70 -> V_71 . V_72 = V_73 ;
V_70 -> V_71 . V_81 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_21 ,
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
F_9 ( V_3 , L_22 ) ;
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
F_9 ( V_3 , L_23 ) ;
if ( V_84 )
goto V_71;
}
case V_87 :
V_70 -> V_71 . V_72 = V_87 ;
V_13 = 0 ;
goto V_71;
default:
F_9 ( V_3 , L_24 ,
V_70 -> V_80 . V_72 ) ;
V_13 = - V_88 ;
}
V_71:
if ( ! V_13 )
F_49 ( V_3 , L_25 ,
V_70 -> V_71 . V_72 == V_87 ?
L_26 : V_70 -> V_71 . V_72 == V_75 ?
L_27 : L_28 ) ;
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
L_29 ,
V_104 ) ;
}
return V_13 ;
}
int F_70 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = V_94 -> V_3 ;
T_7 V_72 ;
int V_13 = 0 ;
T_3 V_108 ;
V_72 = V_3 -> V_70 . V_71 . V_72 ;
if ( V_72 == V_73 ) {
V_108 = V_94 -> V_109 ;
snprintf ( V_94 -> V_110 , V_111 , L_30 ,
V_108 , V_3 -> V_6 -> V_112 -> V_113 ,
F_71 ( V_3 -> V_6 -> V_114 ) , V_94 -> V_115 ) ;
V_13 = F_72 ( V_3 -> V_70 . V_74 [ V_108 ] . V_116 ,
F_65 , 0 , V_94 -> V_110 , V_94 -> V_106 ) ;
} else {
unsigned long V_117 = 0 ;
snprintf ( V_3 -> V_110 , V_111 , L_31 ,
V_3 -> V_6 -> V_112 -> V_113 , F_71 ( V_3 -> V_6 -> V_114 ) ,
F_73 ( V_3 -> V_6 -> V_114 ) ) ;
if ( V_3 -> V_70 . V_71 . V_72 == V_87 )
V_117 |= V_118 ;
V_13 = F_72 ( V_3 -> V_6 -> V_26 , F_67 ,
V_117 , V_3 -> V_110 , V_3 ) ;
}
if ( V_13 )
F_9 ( V_3 , L_32 , V_13 ) ;
else
F_45 ( V_94 , ( V_107 | V_119 ) ,
L_33 ,
( V_72 == V_73 ) ? L_34 : L_35 ) ;
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
L_36 ,
V_78 , V_121 -> V_106 ) ;
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
int V_13 , V_78 ;
if ( F_35 ( V_3 ) -> V_40 . V_41 != V_124 ) {
for ( V_78 = 0 ; V_78 < V_3 -> V_34 ; V_78 ++ ) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
V_121 -> V_125 = true ;
}
}
V_13 = F_87 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_49 ( V_3 , L_37 ) ;
F_88 ( V_3 ) ;
return V_13 ;
}
static int F_89 ( struct V_2 * V_3 , T_8 V_79 )
{
int V_126 = 0 ;
V_3 -> V_70 . V_127 = V_79 ? true : false ;
if ( V_3 -> V_70 . V_71 . V_72 != V_73 )
V_126 = V_3 -> V_34 * 63 ;
else if ( V_3 -> V_70 . V_128 )
V_126 = V_3 -> V_70 . V_128 ;
if ( ! V_126 )
return - V_27 ;
return F_90 ( int , V_79 , V_126 ) ;
}
static int F_91 ( struct V_2 * V_3 , struct V_129 * V_130 )
{
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
if ( ! V_3 -> V_70 . V_127 ) {
F_49 ( V_3 ,
L_38 ) ;
return - V_88 ;
}
if ( V_3 -> V_70 . V_71 . V_72 == V_73 ) {
int V_131 = V_3 -> V_70 . V_132 ;
V_130 -> V_133 = V_3 -> V_70 . V_128 ;
V_130 -> V_134 = & V_3 -> V_70 . V_74 [ V_131 ] ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_3 ,
enum V_135 V_72 )
{
struct V_136 V_137 ;
int V_138 = 0 ;
int V_13 ;
int V_78 ;
if ( ( V_72 == V_75 ) && ( V_3 -> V_34 > 1 ) ) {
F_9 ( V_3 , L_39 ) ;
return - V_88 ;
}
memset ( & V_3 -> V_70 , 0 , sizeof( struct V_77 ) ) ;
V_3 -> V_70 . V_80 . V_72 = V_72 ;
F_75 (cdev, i) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
F_93 ( & V_3 -> V_39 [ V_78 ] , & V_137 ) ;
V_3 -> V_70 . V_80 . V_81 += V_137 . V_139 ;
V_3 -> V_70 . V_80 . V_81 ++ ;
}
V_3 -> V_70 . V_80 . V_83 = V_3 -> V_34 * 2 ;
V_13 = F_59 ( V_3 , false ) ;
if ( V_13 ) {
F_48 ( V_3 , L_40 ) ;
return V_13 ;
}
V_3 -> V_70 . V_132 = V_3 -> V_34 ;
V_3 -> V_70 . V_128 = V_3 -> V_70 . V_71 . V_81 -
V_3 -> V_34 ;
if ( ! F_94 ( V_140 ) )
return 0 ;
F_75 (cdev, i)
V_138 += F_95 ( & V_3 -> V_39 [ V_78 ] , V_141 ) ;
F_45 ( V_3 , V_142 ,
L_41 ,
V_3 -> V_70 . V_128 , V_138 ) ;
if ( V_3 -> V_70 . V_128 > V_138 ) {
V_3 -> V_70 . V_143 =
( V_3 -> V_70 . V_128 - V_138 )
/ V_3 -> V_34 ;
V_3 -> V_70 . V_144 =
V_3 -> V_70 . V_132 + V_138 ;
V_3 -> V_70 . V_128 = V_138 ;
} else {
V_3 -> V_70 . V_143 = 0 ;
}
F_45 ( V_3 , V_142 , L_42 ,
V_3 -> V_70 . V_143 ,
V_3 -> V_70 . V_144 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
int V_13 ;
memset ( & V_3 -> V_70 , 0 , sizeof( struct V_77 ) ) ;
V_3 -> V_70 . V_80 . V_72 = V_73 ;
F_97 ( F_35 ( V_3 ) ,
& V_3 -> V_70 . V_80 . V_81 ) ;
if ( V_3 -> V_34 > 1 ) {
T_3 V_145 = 0 ;
F_97 ( & V_3 -> V_39 [ 1 ] , & V_145 ) ;
V_3 -> V_70 . V_80 . V_81 += V_145 ;
}
V_3 -> V_70 . V_80 . V_83 = V_3 -> V_34 ;
V_13 = F_59 ( V_3 , true ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_70 . V_132 = 0 ;
V_3 -> V_70 . V_128 = V_3 -> V_70 . V_71 . V_81 ;
return 0 ;
}
T_7 F_98 ( struct V_93 * V_121 , T_7 V_146 ,
T_3 * V_147 , T_7 V_148 , T_3 * V_149 )
{
int V_13 ;
V_121 -> V_150 -> V_151 = V_147 ;
V_121 -> V_150 -> V_152 = V_146 ;
V_121 -> V_150 -> V_153 = V_149 ;
V_121 -> V_150 -> V_154 = V_148 ;
V_13 = F_99 ( V_121 -> V_150 , V_155 ) ;
if ( V_13 != V_156 ) {
F_45 ( V_121 , V_60 , L_43 ,
V_13 ) ;
return 0 ;
}
V_13 = F_100 ( V_121 -> V_150 , V_157 ) ;
F_101 ( V_121 -> V_150 ) ;
if ( V_13 != V_156 && V_13 != V_158 ) {
F_45 ( V_121 , V_60 , L_44 ,
V_121 -> V_150 -> V_159 , V_13 ) ;
return 0 ;
}
return V_121 -> V_150 -> V_160 / 4 ;
}
static int F_102 ( struct V_2 * V_3 )
{
int V_78 ;
void * V_161 ;
F_75 (cdev, i) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
V_121 -> V_150 = F_42 ( sizeof( * V_121 -> V_150 ) , V_58 ) ;
if ( ! V_121 -> V_150 )
return - V_27 ;
V_161 = F_103 ( F_104 () ) ;
if ( ! V_161 )
return - V_27 ;
V_121 -> V_150 -> V_161 = V_161 ;
}
return 0 ;
}
static void F_105 ( struct V_2 * V_3 )
{
int V_78 ;
F_75 (cdev, i) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
if ( ! V_121 -> V_150 )
return;
F_106 ( V_121 -> V_150 -> V_161 ) ;
F_40 ( V_121 -> V_150 ) ;
}
}
static void F_107 ( struct V_2 * V_3 ,
struct V_162 * V_62 )
{
int V_78 ;
if ( F_94 ( V_140 ) ) {
V_62 -> V_163 . V_164 = V_165 ;
V_62 -> V_163 . V_166 = V_167 ;
V_62 -> V_163 . V_168 = V_169 ;
V_62 -> V_163 . V_170 = V_171 ;
}
for ( V_78 = 0 ; V_78 < V_3 -> V_34 ; V_78 ++ ) {
struct V_93 * V_121 = & V_3 -> V_39 [ V_78 ] ;
V_121 -> V_172 = * V_62 ;
}
}
static int F_108 ( struct V_2 * V_3 ,
struct V_173 * V_62 )
{
struct V_174 V_175 ;
struct V_176 V_177 ;
const T_3 * V_178 = NULL ;
struct V_93 * V_94 ;
int V_13 = - V_88 ;
if ( F_109 ( V_3 ) )
goto V_179;
if ( F_18 ( V_3 ) ) {
V_13 = F_110 ( & V_3 -> V_180 , V_181 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_45 ,
V_181 ) ;
goto V_179;
}
}
V_3 -> V_182 = V_183 ;
V_13 = F_86 ( V_3 ) ;
if ( V_13 )
goto V_179;
if ( F_18 ( V_3 ) )
V_13 = F_92 ( V_3 , V_62 -> V_72 ) ;
else
V_13 = F_96 ( V_3 ) ;
if ( V_13 )
goto V_16;
if ( F_18 ( V_3 ) ) {
V_13 = F_102 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_178 = V_3 -> V_180 -> V_178 + sizeof( T_7 ) ;
F_111 ( V_3 ) ;
}
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_184 |= 1 << V_185 |
1 << V_186 |
1 << V_187 |
1 << V_188 |
1 << V_189 ;
V_175 . V_190 = V_191 ;
V_175 . V_192 = V_191 ;
V_175 . V_193 = V_191 ;
V_13 = F_112 ( V_3 , & V_175 , true ,
V_3 -> V_70 . V_71 . V_72 ,
true , V_178 ) ;
if ( V_13 )
goto V_20;
F_49 ( V_3 ,
L_46 ) ;
if ( F_35 ( V_3 ) -> V_125 ) {
V_13 = F_113 ( V_3 ) ;
if ( V_13 )
goto V_194;
}
if ( F_18 ( V_3 ) ) {
V_94 = F_35 ( V_3 ) ;
V_177 . V_1 = ( V_62 -> V_195 << 24 ) |
( V_62 -> V_196 << 16 ) |
( V_62 -> V_197 << 8 ) |
( V_62 -> V_198 ) ;
F_114 ( V_177 . V_110 , V_62 -> V_110 ,
V_199 - 4 ) ;
V_13 = F_115 ( V_94 , V_94 -> V_200 ,
& V_177 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_47 ) ;
return V_13 ;
}
}
F_116 ( V_3 ) ;
return 0 ;
V_194:
F_80 ( V_3 ) ;
V_20:
F_117 ( V_3 ) ;
if ( F_18 ( V_3 ) )
F_74 ( V_3 ) ;
F_105 ( V_3 ) ;
F_53 ( V_3 ) ;
V_16:
F_85 ( V_3 ) ;
V_179:
if ( F_18 ( V_3 ) )
F_118 ( V_3 -> V_180 ) ;
F_119 ( V_3 , false ) ;
return V_13 ;
}
static int F_120 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
F_121 ( V_3 ) ;
if ( F_18 ( V_3 ) ) {
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
F_118 ( V_3 -> V_180 ) ;
return 0 ;
}
static void F_124 ( struct V_2 * V_3 , char V_110 [ V_111 ] ,
char V_201 [ V_202 ] )
{
int V_78 ;
memcpy ( V_3 -> V_110 , V_110 , V_111 ) ;
F_75 (cdev, i)
snprintf ( V_3 -> V_39 [ V_78 ] . V_110 , V_111 , L_48 , V_110 , V_78 ) ;
memcpy ( V_3 -> V_201 , V_201 , V_202 ) ;
V_3 -> V_203 = V_204 ;
}
static T_7 F_125 ( struct V_2 * V_3 ,
struct V_205 * V_206 ,
void * V_207 ,
T_9 V_208 , T_8 V_209 ,
enum V_210 type )
{
struct V_93 * V_121 ;
int V_211 ;
T_8 V_212 ;
T_3 V_213 ;
T_7 V_13 ;
if ( type == V_214 )
V_213 = V_3 -> V_34 ;
else
V_213 = 1 ;
V_211 = V_209 % V_213 ;
V_121 = & V_3 -> V_39 [ V_211 ] ;
V_212 = V_209 / V_213 ;
F_45 ( V_3 , V_107 ,
L_49 ,
V_211 , V_212 , V_209 ) ;
V_13 = F_126 ( V_121 , V_121 -> V_200 , V_206 ,
V_207 , V_208 , V_212 ) ;
return V_13 ;
}
static T_7 F_127 ( struct V_2 * V_3 ,
struct V_205 * V_206 , T_8 V_209 )
{
struct V_93 * V_121 ;
int V_211 ;
T_8 V_212 ;
T_7 V_13 ;
V_211 = V_209 % V_3 -> V_34 ;
V_121 = & V_3 -> V_39 [ V_211 ] ;
V_212 = V_209 / V_3 -> V_34 ;
F_45 ( V_3 , V_107 ,
L_49 ,
V_211 , V_212 , V_209 ) ;
V_13 = F_128 ( V_121 , V_206 , V_212 ) ;
return V_13 ;
}
static bool F_129 ( struct V_2 * V_3 )
{
return true ;
}
static int F_130 ( struct V_2 * V_3 , struct V_215 * V_62 )
{
struct V_93 * V_94 ;
struct V_216 * V_217 ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
if ( F_131 ( V_3 ) )
return 0 ;
V_94 = & V_3 -> V_39 [ 0 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_218 ;
V_217 = F_132 ( V_94 ) ;
if ( V_62 -> V_219 & V_220 )
V_217 -> V_221 . V_222 = V_62 -> V_222 ;
if ( V_62 -> V_219 & V_223 ) {
V_217 -> V_221 . V_224 = 0 ;
if ( ( V_62 -> V_225 & V_226 ) ||
( V_62 -> V_225 & V_227 ) )
V_217 -> V_221 . V_224 |=
V_228 ;
if ( V_62 -> V_225 & V_229 )
V_217 -> V_221 . V_224 |=
V_230 ;
if ( V_62 -> V_225 & V_231 )
V_217 -> V_221 . V_224 |=
V_232 ;
if ( V_62 -> V_225 & V_233 )
V_217 -> V_221 . V_224 |=
V_234 ;
if ( V_62 -> V_225 & V_235 )
V_217 -> V_221 . V_224 |=
V_236 ;
if ( V_62 -> V_225 & V_237 )
V_217 -> V_221 . V_224 |=
V_238 ;
}
if ( V_62 -> V_219 & V_239 )
V_217 -> V_221 . V_240 = V_62 -> V_240 ;
if ( V_62 -> V_219 & V_241 ) {
if ( V_62 -> V_242 & V_243 )
V_217 -> V_244 . V_222 = true ;
else
V_217 -> V_244 . V_222 = false ;
if ( V_62 -> V_242 & V_245 )
V_217 -> V_244 . V_246 = true ;
else
V_217 -> V_244 . V_246 = false ;
if ( V_62 -> V_242 & V_247 )
V_217 -> V_244 . V_248 = true ;
else
V_217 -> V_244 . V_248 = false ;
}
if ( V_62 -> V_219 & V_249 ) {
switch ( V_62 -> V_250 ) {
case V_251 :
V_217 -> V_250 = V_252 ;
break;
case V_253 :
V_217 -> V_250 = V_254 ;
break;
case V_255 :
V_217 -> V_250 = V_256 ;
break;
case V_257 :
V_217 -> V_250 = V_258 ;
break;
default:
V_217 -> V_250 = V_259 ;
break;
}
}
V_13 = F_133 ( V_94 , V_33 , V_62 -> V_260 ) ;
F_38 ( V_94 , V_33 ) ;
return V_13 ;
}
static int F_134 ( T_7 V_261 )
{
int V_262 ;
switch ( V_261 ) {
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_262 = V_268 ;
break;
case V_269 :
V_262 = V_270 ;
break;
case V_271 :
V_262 = V_272 ;
break;
case V_273 :
V_262 = V_274 ;
break;
case V_275 :
default:
V_262 = V_276 ;
break;
}
return V_262 ;
}
static int F_135 ( struct V_93 * V_94 ,
struct V_216 * V_62 ,
struct V_277 * V_278 ,
struct V_279 * V_280 )
{
void * V_281 ;
if ( ! F_18 ( V_94 -> V_3 ) ) {
F_136 ( V_94 , V_62 ) ;
F_137 ( V_94 , V_278 ) ;
F_138 ( V_94 , V_280 ) ;
return 0 ;
}
V_281 = F_132 ( V_94 ) ;
if ( ! V_281 )
return - V_282 ;
memcpy ( V_62 , V_281 , sizeof( * V_62 ) ) ;
V_281 = F_139 ( V_94 ) ;
if ( ! V_281 )
return - V_282 ;
memcpy ( V_278 , V_281 , sizeof( * V_278 ) ) ;
V_281 = F_140 ( V_94 ) ;
if ( ! V_281 )
return - V_282 ;
memcpy ( V_280 , V_281 , sizeof( * V_280 ) ) ;
return 0 ;
}
static void F_141 ( struct V_93 * V_94 ,
struct V_283 * V_284 )
{
struct V_216 V_62 ;
struct V_277 V_278 ;
struct V_279 V_280 ;
T_7 V_261 ;
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
if ( F_135 ( V_94 , & V_62 , & V_278 , & V_280 ) ) {
F_142 ( & V_94 -> V_3 -> V_6 -> V_5 , L_50 ) ;
return;
}
if ( V_278 . V_260 )
V_284 -> V_260 = true ;
V_284 -> V_285 = V_286 ;
if ( V_62 . V_221 . V_222 )
V_284 -> V_285 |= V_287 ;
if ( V_62 . V_244 . V_222 ||
( V_62 . V_244 . V_246 && V_62 . V_244 . V_248 ) )
V_284 -> V_285 |= V_288 ;
if ( V_62 . V_244 . V_222 || V_62 . V_244 . V_246 ||
V_62 . V_244 . V_248 )
V_284 -> V_285 |= V_289 ;
V_284 -> V_290 = V_284 -> V_285 ;
if ( V_62 . V_221 . V_224 &
V_228 )
V_284 -> V_290 |= V_226 |
V_227 ;
if ( V_62 . V_221 . V_224 &
V_230 )
V_284 -> V_290 |= V_229 ;
if ( V_62 . V_221 . V_224 &
V_232 )
V_284 -> V_290 |= V_231 ;
if ( V_62 . V_221 . V_224 &
V_234 )
V_284 -> V_290 |= V_233 ;
if ( V_62 . V_221 . V_224 &
V_236 )
V_284 -> V_290 |= V_235 ;
if ( V_62 . V_221 . V_224 &
V_238 )
V_284 -> V_290 |= V_237 ;
if ( V_280 . V_291 &
V_228 )
V_284 -> V_285 |= V_226 |
V_227 ;
if ( V_280 . V_291 &
V_230 )
V_284 -> V_285 |= V_229 ;
if ( V_280 . V_291 &
V_232 )
V_284 -> V_285 |= V_231 ;
if ( V_280 . V_291 &
V_234 )
V_284 -> V_285 |= V_233 ;
if ( V_280 . V_291 &
V_236 )
V_284 -> V_285 |= V_235 ;
if ( V_280 . V_291 &
V_238 )
V_284 -> V_285 |= V_237 ;
if ( V_278 . V_260 )
V_284 -> V_221 = V_278 . V_221 ;
V_284 -> V_292 = V_293 ;
F_143 ( V_94 -> V_3 , & V_261 ) ;
V_284 -> V_294 = F_134 ( V_261 ) ;
V_284 -> V_222 = V_62 . V_221 . V_222 ;
if ( V_62 . V_244 . V_222 )
V_284 -> V_242 |= V_243 ;
if ( V_62 . V_244 . V_246 )
V_284 -> V_242 |= V_245 ;
if ( V_62 . V_244 . V_248 )
V_284 -> V_242 |= V_247 ;
if ( V_278 . V_295 & V_296 )
V_284 -> V_297 |= V_226 ;
if ( V_278 . V_295 & V_298 )
V_284 -> V_297 |= V_227 ;
if ( V_278 . V_295 & V_299 )
V_284 -> V_297 |= V_229 ;
if ( V_278 . V_295 & V_300 )
V_284 -> V_297 |= V_231 ;
if ( V_278 . V_295 & V_301 )
V_284 -> V_297 |= V_233 ;
if ( V_278 . V_295 & V_302 )
V_284 -> V_297 |= V_235 ;
if ( V_278 . V_295 & V_303 )
V_284 -> V_297 |= V_237 ;
if ( V_278 . V_304 )
V_284 -> V_297 |= V_287 ;
if ( V_278 . V_305 )
V_284 -> V_297 |= V_289 ;
if ( V_278 . V_305 == V_306 ||
V_278 . V_305 == V_307 )
V_284 -> V_297 |= V_288 ;
}
static void F_144 ( struct V_2 * V_3 ,
struct V_283 * V_284 )
{
int V_78 ;
F_141 ( & V_3 -> V_39 [ 0 ] , V_284 ) ;
F_75 (cdev, i)
F_145 ( & V_3 -> V_39 [ V_78 ] ) ;
}
void F_146 ( struct V_93 * V_94 )
{
void * V_308 = V_94 -> V_3 -> V_309 ;
struct V_310 * V_311 = V_94 -> V_3 -> V_312 . V_313 ;
struct V_283 V_284 ;
F_141 ( V_94 , & V_284 ) ;
F_145 ( V_94 ) ;
if ( F_147 ( V_94 ) && V_308 )
V_311 -> V_314 ( V_308 , & V_284 ) ;
}
static int F_148 ( struct V_2 * V_3 )
{
struct V_93 * V_94 ;
struct V_32 * V_33 ;
int V_78 , V_13 ;
if ( F_131 ( V_3 ) )
return 0 ;
F_75 (cdev, i) {
V_94 = & V_3 -> V_39 [ V_78 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 ) {
F_9 ( V_94 , L_51 ) ;
return - V_218 ;
}
V_13 = F_149 ( V_94 , V_33 ) ;
if ( V_13 )
return V_13 ;
F_38 ( V_94 , V_33 ) ;
}
return 0 ;
}
static void F_150 ( struct V_2 * V_3 , T_8 * V_315 , T_8 * V_316 )
{
* V_315 = V_3 -> V_182 ;
* V_316 = V_3 -> V_317 ;
}
static int F_151 ( struct V_2 * V_3 , T_8 V_315 , T_8 V_316 ,
T_3 V_318 , T_8 V_209 )
{
struct V_93 * V_94 ;
struct V_32 * V_33 ;
int V_211 ;
int V_104 = 0 ;
V_211 = V_318 % V_3 -> V_34 ;
V_94 = & V_3 -> V_39 [ V_211 ] ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_319 ;
V_104 = F_152 ( V_94 , V_33 , V_315 ,
V_318 / V_3 -> V_34 , V_209 ) ;
if ( V_104 )
goto V_71;
V_104 = F_153 ( V_94 , V_33 , V_316 ,
V_318 / V_3 -> V_34 , V_209 ) ;
V_71:
F_38 ( V_94 , V_33 ) ;
return V_104 ;
}
static int F_154 ( struct V_2 * V_3 , enum V_320 V_321 )
{
struct V_93 * V_94 = F_35 ( V_3 ) ;
struct V_32 * V_33 ;
int V_104 = 0 ;
V_33 = F_34 ( V_94 ) ;
if ( ! V_33 )
return - V_319 ;
V_104 = F_155 ( V_94 , V_33 , V_321 ) ;
F_38 ( V_94 , V_33 ) ;
return V_104 ;
}
void F_156 ( struct V_2 * V_3 ,
enum V_322 type ,
union V_323 * V_324 )
{
struct V_325 V_326 ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
switch ( type ) {
case V_327 :
F_157 ( V_3 , & V_326 ) ;
V_324 -> V_328 . V_329 = V_326 . V_330 ;
V_324 -> V_328 . V_331 = V_326 . V_332 ;
V_324 -> V_328 . V_333 = - 1 ;
break;
default:
F_48 ( V_3 , L_52 , type ) ;
return;
}
}
