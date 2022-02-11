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
int V_12 ;
V_3 -> V_6 = V_6 ;
V_12 = F_16 ( V_6 ) ;
if ( V_12 ) {
F_9 ( V_3 , L_6 ) ;
goto V_13;
}
if ( ! ( F_17 ( V_6 , 0 ) & V_14 ) ) {
F_9 ( V_3 , L_7 ) ;
V_12 = - V_7 ;
goto V_15;
}
if ( ! ( F_17 ( V_6 , 2 ) & V_14 ) ) {
F_9 ( V_3 , L_8 ) ;
V_12 = - V_7 ;
goto V_15;
}
if ( F_12 ( & V_6 -> V_11 ) == 1 ) {
V_12 = F_18 ( V_6 , L_9 ) ;
if ( V_12 ) {
F_9 ( V_3 ,
L_10 ) ;
goto V_15;
}
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
}
if ( ! F_21 ( V_6 ) ) {
F_9 ( V_3 , L_11 ) ;
V_12 = - V_7 ;
goto V_16;
}
V_3 -> V_17 . V_18 = F_22 ( V_6 , V_19 ) ;
if ( V_3 -> V_17 . V_18 == 0 )
F_9 ( V_3 , L_12 ) ;
V_12 = F_5 ( V_3 ) ;
if ( V_12 )
goto V_16;
V_3 -> V_17 . V_20 = F_23 ( V_6 , 0 ) ;
V_3 -> V_17 . V_21 = F_24 ( V_6 , 0 ) ;
V_3 -> V_17 . V_22 = V_6 -> V_22 ;
V_3 -> V_10 = F_25 ( V_6 , 0 ) ;
if ( ! V_3 -> V_10 ) {
F_9 ( V_3 , L_13 ) ;
V_12 = - V_23 ;
goto V_16;
}
V_3 -> V_24 = F_23 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_25 = F_26 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_9 = F_27 ( V_3 -> V_24 , V_3 -> V_25 ) ;
if ( ! V_3 -> V_9 ) {
F_9 ( V_3 , L_14 ) ;
return - V_23 ;
}
return 0 ;
V_16:
F_13 ( V_6 ) ;
V_15:
F_14 ( V_6 ) ;
V_13:
return V_12 ;
}
int F_28 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
V_27 -> V_30 = V_3 -> V_30 ;
V_27 -> V_31 = V_3 -> V_17 . V_20 ;
V_27 -> V_32 = V_3 -> V_17 . V_21 ;
V_27 -> V_33 = V_3 -> V_17 . V_22 ;
V_27 -> V_34 = F_29 ( & V_3 -> V_35 [ 0 ] ) ;
F_30 ( V_27 -> V_36 , V_3 -> V_35 [ 0 ] . V_37 . V_38 ) ;
V_27 -> V_39 = V_40 ;
V_27 -> V_41 = V_42 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 = V_3 -> V_47 ;
F_31 ( V_3 , & V_27 -> V_48 ) ;
V_29 = F_32 ( F_33 ( V_3 ) ) ;
if ( V_29 ) {
F_34 ( F_33 ( V_3 ) , V_29 ,
& V_27 -> V_49 ) ;
F_35 ( F_33 ( V_3 ) , V_29 ) ;
}
return 0 ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_37 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_38 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_39 ( sizeof( * V_3 ) , V_50 ) ;
if ( ! V_3 )
return V_3 ;
F_40 ( V_3 ) ;
return V_3 ;
}
static int F_41 ( struct V_2 * V_3 ,
T_3 V_51 )
{
if ( ! V_3 )
return - V_52 ;
F_42 ( V_3 , V_53 , L_15 ) ;
return 0 ;
}
static struct V_2 * F_43 ( struct V_8 * V_6 ,
enum V_54 V_55 ,
T_4 V_56 ,
T_5 V_57 )
{
struct V_2 * V_3 ;
int V_12 ;
V_3 = F_38 ( V_6 ) ;
if ( ! V_3 )
goto V_13;
V_3 -> V_55 = V_55 ;
F_44 ( V_3 , V_56 , V_57 ) ;
V_12 = F_15 ( V_3 , V_6 ) ;
if ( V_12 ) {
F_45 ( V_3 , L_16 ) ;
goto V_15;
}
F_46 ( V_3 , L_17 ) ;
V_12 = F_47 ( V_3 , V_58 ) ;
if ( V_12 ) {
F_45 ( V_3 , L_18 ) ;
goto V_16;
}
F_46 ( V_3 , L_19 ) ;
return V_3 ;
V_16:
F_10 ( V_3 ) ;
V_15:
F_36 ( V_3 ) ;
V_13:
return NULL ;
}
static void F_48 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_49 ( V_3 ) ;
F_10 ( V_3 ) ;
F_41 ( V_3 , V_59 ) ;
F_36 ( V_3 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
if ( V_3 -> V_60 . V_61 . V_62 == V_63 ) {
F_51 ( V_3 -> V_6 ) ;
F_37 ( V_3 -> V_60 . V_64 ) ;
} else if ( V_3 -> V_60 . V_61 . V_62 == V_65 ) {
F_52 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_60 . V_61 , 0 , sizeof( struct V_66 ) ) ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_67 * V_60 )
{
int V_68 , V_12 , V_69 ;
V_69 = V_60 -> V_70 . V_71 ;
for ( V_68 = 0 ; V_68 < V_69 ; V_68 ++ )
V_60 -> V_64 [ V_68 ] . V_72 = V_68 ;
V_12 = F_54 ( V_3 -> V_6 , V_60 -> V_64 ,
V_60 -> V_70 . V_73 , V_69 ) ;
if ( V_12 < V_69 && V_12 >= V_60 -> V_70 . V_73 &&
( V_12 % V_3 -> V_30 ) ) {
F_51 ( V_3 -> V_6 ) ;
V_69 = ( V_12 / V_3 -> V_30 ) * V_3 -> V_30 ;
F_9 ( V_3 ,
L_20 ,
V_69 , V_60 -> V_70 . V_71 ) ;
V_12 = F_55 ( V_3 -> V_6 ,
V_60 -> V_64 , V_69 ) ;
if ( ! V_12 )
V_12 = V_69 ;
}
if ( V_12 > 0 ) {
V_60 -> V_61 . V_62 = V_63 ;
V_60 -> V_61 . V_71 = V_12 ;
V_12 = 0 ;
} else {
F_9 ( V_3 ,
L_21 ,
V_69 , V_12 ) ;
}
return V_12 ;
}
static int F_56 ( struct V_2 * V_3 , bool V_74 )
{
struct V_67 * V_60 = & V_3 -> V_60 ;
struct V_75 * V_76 ;
int V_12 = 0 , V_69 ;
switch ( V_60 -> V_70 . V_62 ) {
case V_63 :
V_69 = V_60 -> V_70 . V_71 ;
V_60 -> V_64 = F_57 ( V_69 , sizeof( * V_76 ) , V_50 ) ;
if ( ! V_60 -> V_64 ) {
V_12 = - V_23 ;
goto V_61;
}
V_12 = F_53 ( V_3 , V_60 ) ;
if ( ! V_12 )
goto V_61;
F_9 ( V_3 , L_22 ) ;
F_37 ( V_60 -> V_64 ) ;
if ( V_74 )
goto V_61;
case V_65 :
V_12 = F_58 ( V_3 -> V_6 ) ;
if ( ! V_12 ) {
V_60 -> V_61 . V_62 = V_65 ;
goto V_61;
}
F_9 ( V_3 , L_23 ) ;
if ( V_74 )
goto V_61;
case V_77 :
V_60 -> V_61 . V_62 = V_77 ;
V_12 = 0 ;
goto V_61;
default:
F_9 ( V_3 , L_24 ,
V_60 -> V_70 . V_62 ) ;
V_12 = - V_78 ;
}
V_61:
V_3 -> V_79 = V_80 ;
return V_12 ;
}
static void F_59 ( struct V_2 * V_3 , void * V_81 ,
int V_82 , void (* F_60)( void * ) )
{
struct V_83 * V_84 = & V_3 -> V_35 [ V_82 % V_3 -> V_30 ] ;
int V_85 = V_82 / V_3 -> V_30 ;
V_84 -> V_86 [ V_85 ] . V_87 = F_60 ;
V_84 -> V_86 [ V_85 ] . V_81 = V_81 ;
}
static void F_61 ( struct V_2 * V_3 , int V_82 )
{
struct V_83 * V_84 = & V_3 -> V_35 [ V_82 % V_3 -> V_30 ] ;
int V_85 = V_82 / V_3 -> V_30 ;
memset ( & V_84 -> V_86 [ V_85 ] , 0 ,
sizeof( struct V_88 ) ) ;
}
static T_6 F_62 ( int V_22 , void * V_89 )
{
F_63 ( (struct V_90 * ) V_89 ) ;
return V_91 ;
}
static T_6 F_64 ( int V_22 , void * V_92 )
{
struct V_2 * V_3 = (struct V_2 * ) V_92 ;
struct V_83 * V_84 ;
T_6 V_12 = V_93 ;
T_7 V_94 ;
int V_68 , V_95 ;
for ( V_68 = 0 ; V_68 < V_3 -> V_30 ; V_68 ++ ) {
V_94 = F_65 ( & V_3 -> V_35 [ V_68 ] ) ;
if ( ! V_94 )
continue;
V_84 = & V_3 -> V_35 [ V_68 ] ;
if ( F_66 ( V_94 & 0x1 ) ) {
F_63 ( V_84 -> V_96 ) ;
V_94 &= ~ 0x1 ;
V_12 = V_91 ;
}
for ( V_95 = 0 ; V_95 < 64 ; V_95 ++ ) {
if ( ( 0x2ULL << V_95 ) & V_94 ) {
V_84 -> V_86 [ V_95 ] . V_87 (
V_84 -> V_86 [ V_95 ] . V_81 ) ;
V_94 &= ~ ( 0x2ULL << V_95 ) ;
V_12 = V_91 ;
}
}
if ( F_66 ( V_94 ) )
F_42 ( V_84 , V_97 ,
L_25 ,
V_94 ) ;
}
return V_12 ;
}
int F_67 ( struct V_83 * V_84 )
{
struct V_2 * V_3 = V_84 -> V_3 ;
int V_12 = 0 ;
T_5 V_98 ;
if ( V_3 -> V_60 . V_61 . V_62 == V_63 ) {
V_98 = V_84 -> V_99 ;
snprintf ( V_84 -> V_100 , V_101 , L_26 ,
V_98 , V_3 -> V_6 -> V_102 -> V_103 ,
F_68 ( V_3 -> V_6 -> V_104 ) , V_84 -> V_105 ) ;
V_12 = F_69 ( V_3 -> V_60 . V_64 [ V_98 ] . V_106 ,
F_62 , 0 , V_84 -> V_100 , V_84 -> V_96 ) ;
if ( ! V_12 )
F_42 ( V_84 , ( V_97 | V_107 ) ,
L_27 ) ;
} else {
unsigned long V_108 = 0 ;
snprintf ( V_3 -> V_100 , V_101 , L_28 ,
V_3 -> V_6 -> V_102 -> V_103 , F_68 ( V_3 -> V_6 -> V_104 ) ,
F_70 ( V_3 -> V_6 -> V_104 ) ) ;
if ( V_3 -> V_60 . V_61 . V_62 == V_77 )
V_108 |= V_109 ;
V_12 = F_69 ( V_3 -> V_6 -> V_22 , F_64 ,
V_108 , V_3 -> V_100 , V_3 ) ;
}
return V_12 ;
}
static void F_71 ( struct V_2 * V_3 )
{
int V_68 ;
if ( V_3 -> V_60 . V_61 . V_62 == V_63 ) {
F_72 (cdev, i) {
if ( ! V_3 -> V_35 [ V_68 ] . V_110 )
break;
F_73 ( V_3 -> V_60 . V_64 [ V_68 ] . V_106 ) ;
F_74 ( V_3 -> V_60 . V_64 [ V_68 ] . V_106 ,
V_3 -> V_35 [ V_68 ] . V_96 ) ;
}
} else {
if ( F_33 ( V_3 ) -> V_110 )
F_74 ( V_3 -> V_6 -> V_22 , V_3 ) ;
}
F_75 ( V_3 ) ;
}
static int F_76 ( struct V_2 * V_3 )
{
int V_68 , V_12 ;
V_12 = F_77 ( V_3 ) ;
for ( V_68 = 0 ; V_68 < V_3 -> V_30 ; V_68 ++ ) {
struct V_83 * V_111 = & V_3 -> V_35 [ V_68 ] ;
if ( V_111 -> V_112 ) {
F_78 ( V_111 -> V_96 ) ;
V_111 -> V_112 = false ;
F_42 ( V_3 , V_113 ,
L_29 ,
V_68 , V_111 -> V_96 ) ;
}
}
return V_12 ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_12 ;
V_12 = F_80 ( V_3 ) ;
if ( V_12 )
return V_12 ;
F_81 ( V_3 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 )
{
int V_12 ;
V_12 = F_83 ( V_3 ) ;
if ( V_12 )
return V_12 ;
F_46 ( V_3 , L_30 ) ;
F_84 ( V_3 ) ;
return V_12 ;
}
static int F_85 ( struct V_2 * V_3 , T_8 V_69 )
{
int V_114 = 0 ;
V_3 -> V_60 . V_115 = V_69 ? true : false ;
if ( V_3 -> V_60 . V_61 . V_62 != V_63 )
V_114 = V_3 -> V_30 * 63 ;
else if ( V_3 -> V_60 . V_116 )
V_114 = V_3 -> V_60 . V_116 ;
if ( ! V_114 )
return - V_23 ;
return F_86 ( int , V_69 , V_114 ) ;
}
static int F_87 ( struct V_2 * V_3 , struct V_117 * V_118 )
{
memset ( V_118 , 0 , sizeof( struct V_117 ) ) ;
if ( ! V_3 -> V_60 . V_115 ) {
F_46 ( V_3 ,
L_31 ) ;
return - V_78 ;
}
if ( V_3 -> V_60 . V_61 . V_62 == V_63 ) {
int V_119 = V_3 -> V_60 . V_120 ;
V_118 -> V_121 = V_3 -> V_60 . V_116 ;
V_118 -> V_122 = & V_3 -> V_60 . V_64 [ V_119 ] ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
enum V_123 V_62 )
{
int V_12 , V_68 ;
T_5 V_71 = 0 ;
memset ( & V_3 -> V_60 , 0 , sizeof( struct V_67 ) ) ;
V_3 -> V_60 . V_70 . V_62 = V_62 ;
F_72 (cdev, i)
V_71 += F_89 ( & V_3 -> V_35 [ V_68 ] , NULL ) + 1 ;
V_3 -> V_60 . V_70 . V_71 = V_71 ;
V_3 -> V_60 . V_70 . V_73 = V_3 -> V_30 * 2 ;
V_12 = F_56 ( V_3 , false ) ;
if ( V_12 ) {
F_45 ( V_3 , L_32 ) ;
return V_12 ;
}
V_3 -> V_60 . V_120 = V_3 -> V_30 ;
V_3 -> V_60 . V_116 = V_3 -> V_60 . V_61 . V_71 -
V_3 -> V_30 ;
return 0 ;
}
T_4 F_90 ( struct V_83 * V_111 , T_4 V_124 ,
T_5 * V_125 , T_4 V_126 , T_5 * V_127 )
{
int V_12 ;
V_111 -> V_128 -> V_129 = V_125 ;
V_111 -> V_128 -> V_130 = V_124 ;
V_111 -> V_128 -> V_131 = V_127 ;
V_111 -> V_128 -> V_132 = V_126 ;
V_12 = F_91 ( V_111 -> V_128 , V_133 ) ;
if ( V_12 != V_134 ) {
F_42 ( V_111 , V_53 , L_33 ,
V_12 ) ;
return 0 ;
}
V_12 = F_92 ( V_111 -> V_128 , V_135 ) ;
F_93 ( V_111 -> V_128 ) ;
if ( V_12 != V_134 && V_12 != V_136 ) {
F_42 ( V_111 , V_53 , L_34 ,
V_111 -> V_128 -> V_137 , V_12 ) ;
return 0 ;
}
return V_111 -> V_128 -> V_138 / 4 ;
}
static int F_94 ( struct V_2 * V_3 )
{
int V_68 ;
void * V_139 ;
F_72 (cdev, i) {
struct V_83 * V_111 = & V_3 -> V_35 [ V_68 ] ;
V_111 -> V_128 = F_39 ( sizeof( * V_111 -> V_128 ) , V_50 ) ;
if ( ! V_111 -> V_128 )
return - V_23 ;
V_139 = F_95 ( F_96 () ) ;
if ( ! V_139 )
return - V_23 ;
V_111 -> V_128 -> V_139 = V_139 ;
}
return 0 ;
}
static void F_97 ( struct V_2 * V_3 )
{
int V_68 ;
F_72 (cdev, i) {
struct V_83 * V_111 = & V_3 -> V_35 [ V_68 ] ;
if ( ! V_111 -> V_128 )
return;
F_98 ( V_111 -> V_128 -> V_139 ) ;
F_37 ( V_111 -> V_128 ) ;
}
}
static void F_99 ( struct V_2 * V_3 ,
struct V_140 * V_141 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_3 -> V_30 ; V_68 ++ ) {
struct V_83 * V_111 = & V_3 -> V_35 [ V_68 ] ;
V_111 -> V_142 = * V_141 ;
}
}
static int F_100 ( struct V_2 * V_3 ,
struct V_143 * V_141 )
{
struct V_144 V_145 ;
const T_5 * V_146 = NULL ;
struct V_83 * V_84 ;
int V_12 ;
V_12 = F_101 ( & V_3 -> V_147 , V_148 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_12 ) {
F_9 ( V_3 ,
L_35 ,
V_148 ) ;
goto V_149;
}
V_12 = F_82 ( V_3 ) ;
if ( V_12 )
goto V_149;
V_12 = F_88 ( V_3 , V_141 -> V_62 ) ;
if ( V_12 )
goto V_15;
V_12 = F_94 ( V_3 ) ;
if ( V_12 ) {
F_9 ( V_3 , L_36 ) ;
goto V_16;
}
V_146 = V_3 -> V_147 -> V_146 ;
V_12 = F_102 ( V_3 , true , V_3 -> V_60 . V_61 . V_62 ,
true , V_146 ) ;
if ( V_12 )
goto V_150;
F_46 ( V_3 ,
L_37 ) ;
V_84 = F_33 ( V_3 ) ;
V_145 . V_1 = ( V_141 -> V_151 << 24 ) |
( V_141 -> V_152 << 16 ) |
( V_141 -> V_153 << 8 ) |
( V_141 -> V_154 ) ;
F_103 ( V_145 . V_100 , V_141 -> V_100 ,
V_155 - 4 ) ;
V_12 = F_104 ( V_84 , V_84 -> V_156 ,
& V_145 ) ;
if ( V_12 ) {
F_9 ( V_3 , L_38 ) ;
return V_12 ;
}
return 0 ;
V_150:
F_97 ( V_3 ) ;
F_71 ( V_3 ) ;
V_16:
F_50 ( V_3 ) ;
V_15:
F_81 ( V_3 ) ;
V_149:
F_105 ( V_3 -> V_147 ) ;
return V_12 ;
}
static int F_106 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_52 ;
F_97 ( V_3 ) ;
F_76 ( V_3 ) ;
F_71 ( V_3 ) ;
F_50 ( V_3 ) ;
F_79 ( V_3 ) ;
F_105 ( V_3 -> V_147 ) ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 , char V_100 [ V_101 ] ,
char V_157 [ V_158 ] )
{
int V_68 ;
memcpy ( V_3 -> V_100 , V_100 , V_101 ) ;
F_72 (cdev, i)
snprintf ( V_3 -> V_35 [ V_68 ] . V_100 , V_101 , L_39 , V_100 , V_68 ) ;
memcpy ( V_3 -> V_157 , V_157 , V_158 ) ;
V_3 -> V_159 = V_160 ;
}
static T_4 F_108 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
void * V_163 ,
T_9 V_164 , T_8 V_165 ,
enum V_166 type )
{
struct V_83 * V_111 ;
int V_167 ;
T_8 V_168 ;
T_5 V_169 ;
T_4 V_12 ;
if ( type == V_170 )
V_169 = V_3 -> V_30 ;
else
V_169 = 1 ;
V_167 = V_165 % V_169 ;
V_111 = & V_3 -> V_35 [ V_167 ] ;
V_168 = V_165 / V_169 ;
F_42 ( V_3 , V_97 ,
L_40 ,
V_167 , V_168 , V_165 ) ;
V_12 = F_109 ( V_111 , V_111 -> V_156 , V_162 ,
V_163 , V_164 , V_168 ) ;
return V_12 ;
}
static T_4 F_110 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
T_8 V_165 )
{
struct V_83 * V_111 ;
int V_167 ;
T_8 V_168 ;
T_4 V_12 ;
V_167 = V_165 % V_3 -> V_30 ;
V_111 = & V_3 -> V_35 [ V_167 ] ;
V_168 = V_165 / V_3 -> V_30 ;
F_42 ( V_3 , V_97 ,
L_40 ,
V_167 , V_168 , V_165 ) ;
V_12 = F_111 ( V_111 , V_162 , V_168 ) ;
return V_12 ;
}
static int F_112 ( struct V_2 * V_3 ,
struct V_171 * V_141 )
{
struct V_83 * V_84 ;
struct V_172 * V_173 ;
struct V_28 * V_29 ;
int V_12 ;
if ( ! V_3 )
return - V_52 ;
V_84 = & V_3 -> V_35 [ 0 ] ;
V_29 = F_32 ( V_84 ) ;
if ( ! V_29 )
return - V_174 ;
V_173 = F_113 ( V_84 ) ;
if ( V_141 -> V_175 & V_176 )
V_173 -> V_177 . V_178 = V_141 -> V_178 ;
if ( V_141 -> V_175 & V_179 ) {
V_173 -> V_177 . V_180 = 0 ;
if ( ( V_141 -> V_181 & V_182 ) ||
( V_141 -> V_181 & V_183 ) )
V_173 -> V_177 . V_180 |=
V_184 ;
if ( V_141 -> V_181 & V_185 )
V_173 -> V_177 . V_180 |=
V_186 ;
if ( V_141 -> V_181 & V_187 )
V_173 -> V_177 . V_180 |=
V_188 ;
if ( V_141 -> V_181 & 0 )
V_173 -> V_177 . V_180 |=
V_189 ;
if ( V_141 -> V_181 & 0 )
V_173 -> V_177 . V_180 |=
V_190 ;
}
if ( V_141 -> V_175 & V_191 )
V_173 -> V_177 . V_192 = V_141 -> V_192 ;
V_12 = F_114 ( V_84 , V_29 , V_141 -> V_193 ) ;
F_35 ( V_84 , V_29 ) ;
return V_12 ;
}
static int F_115 ( T_4 V_194 )
{
int V_195 ;
switch ( V_194 ) {
case V_196 :
case V_197 :
case V_198 :
case V_199 :
V_195 = V_200 ;
break;
case V_201 :
V_195 = V_202 ;
break;
case V_203 :
V_195 = V_204 ;
break;
case V_205 :
V_195 = V_206 ;
break;
case V_207 :
default:
V_195 = V_208 ;
break;
}
return V_195 ;
}
static void F_116 ( struct V_83 * V_84 ,
struct V_209 * V_210 )
{
struct V_172 V_141 ;
struct V_211 V_212 ;
struct V_213 V_214 ;
T_4 V_194 ;
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
memcpy ( & V_141 , F_113 ( V_84 ) , sizeof( V_141 ) ) ;
memcpy ( & V_212 , F_117 ( V_84 ) , sizeof( V_212 ) ) ;
memcpy ( & V_214 , F_118 ( V_84 ) ,
sizeof( V_214 ) ) ;
if ( V_212 . V_193 )
V_210 -> V_193 = true ;
V_210 -> V_215 = V_216 ;
if ( V_141 . V_177 . V_178 )
V_210 -> V_215 |= V_217 ;
if ( V_141 . V_218 . V_178 ||
( V_141 . V_218 . V_219 && V_141 . V_218 . V_220 ) )
V_210 -> V_215 |= V_221 ;
if ( V_141 . V_218 . V_178 || V_141 . V_218 . V_219 ||
V_141 . V_218 . V_220 )
V_210 -> V_215 |= V_222 ;
V_210 -> V_223 = V_210 -> V_215 ;
if ( V_141 . V_177 . V_180 &
V_184 )
V_210 -> V_223 |= V_182 |
V_183 ;
if ( V_141 . V_177 . V_180 &
V_186 )
V_210 -> V_223 |= V_185 ;
if ( V_141 . V_177 . V_180 &
V_188 )
V_210 -> V_223 |= V_187 ;
if ( V_141 . V_177 . V_180 &
V_189 )
V_210 -> V_223 |= 0 ;
if ( V_141 . V_177 . V_180 &
V_190 )
V_210 -> V_223 |= 0 ;
if ( V_214 . V_224 &
V_184 )
V_210 -> V_215 |= V_182 |
V_183 ;
if ( V_214 . V_224 &
V_186 )
V_210 -> V_215 |= V_185 ;
if ( V_214 . V_224 &
V_188 )
V_210 -> V_215 |= V_187 ;
if ( V_214 . V_224 &
V_189 )
V_210 -> V_215 |= 0 ;
if ( V_214 . V_224 &
V_190 )
V_210 -> V_215 |= 0 ;
if ( V_212 . V_193 )
V_210 -> V_177 = V_212 . V_177 ;
V_210 -> V_225 = V_226 ;
F_119 ( V_84 -> V_3 , & V_194 ) ;
V_210 -> V_227 = F_115 ( V_194 ) ;
V_210 -> V_178 = V_141 . V_177 . V_178 ;
if ( V_141 . V_218 . V_178 )
V_210 -> V_228 |= V_229 ;
if ( V_141 . V_218 . V_219 )
V_210 -> V_228 |= V_230 ;
if ( V_141 . V_218 . V_220 )
V_210 -> V_228 |= V_231 ;
if ( V_212 . V_232 &
V_233 )
V_210 -> V_234 |= V_182 ;
if ( V_212 . V_232 &
V_235 )
V_210 -> V_234 |= V_183 ;
if ( V_212 . V_232 &
V_236 )
V_210 -> V_234 |= V_185 ;
if ( V_212 . V_232 &
V_237 )
V_210 -> V_234 |= V_187 ;
if ( V_212 . V_232 &
V_238 )
V_210 -> V_234 |= 0 ;
if ( V_212 . V_232 &
V_239 )
V_210 -> V_234 |= 0 ;
if ( V_212 . V_240 )
V_210 -> V_234 |= V_217 ;
if ( V_212 . V_241 )
V_210 -> V_234 |= V_222 ;
if ( V_212 . V_241 == V_242 ||
V_212 . V_241 == V_243 )
V_210 -> V_234 |= V_221 ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_209 * V_210 )
{
F_116 ( & V_3 -> V_35 [ 0 ] , V_210 ) ;
}
void F_121 ( struct V_83 * V_84 )
{
void * V_244 = V_84 -> V_3 -> V_245 ;
struct V_246 * V_247 = V_84 -> V_3 -> V_248 . V_249 ;
struct V_209 V_210 ;
F_116 ( V_84 , & V_210 ) ;
if ( F_122 ( V_84 ) && V_244 )
V_247 -> V_250 ( V_244 , & V_210 ) ;
}
static int F_123 ( struct V_2 * V_3 )
{
struct V_83 * V_84 ;
struct V_28 * V_29 ;
int V_68 , V_12 ;
F_72 (cdev, i) {
V_84 = & V_3 -> V_35 [ V_68 ] ;
V_29 = F_32 ( V_84 ) ;
if ( ! V_29 ) {
F_9 ( V_84 , L_41 ) ;
return - V_174 ;
}
V_12 = F_124 ( V_84 , V_29 ) ;
if ( V_12 )
return V_12 ;
F_35 ( V_84 , V_29 ) ;
}
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , enum V_251 V_252 )
{
struct V_83 * V_84 = F_33 ( V_3 ) ;
struct V_28 * V_29 ;
int V_94 = 0 ;
V_29 = F_32 ( V_84 ) ;
if ( ! V_29 )
return - V_253 ;
V_94 = F_126 ( V_84 , V_29 , V_252 ) ;
F_35 ( V_84 , V_29 ) ;
return V_94 ;
}
T_4 F_127 ( enum V_54 V_55 )
{
switch ( V_55 ) {
case V_254 :
return V_255 ;
default:
return 0 ;
}
}
