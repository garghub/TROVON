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
if ( ! ( F_17 ( V_6 , 2 ) & V_15 ) ) {
F_9 ( V_3 , L_8 ) ;
V_13 = - V_7 ;
goto V_16;
}
if ( F_12 ( & V_6 -> V_11 ) == 1 ) {
V_13 = F_18 ( V_6 , L_9 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_10 ) ;
goto V_16;
}
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
}
F_21 ( V_6 , V_17 , & V_12 ) ;
if ( V_12 == V_18 ) {
F_9 ( V_3 ,
L_11 ,
V_12 ) ;
V_13 = - V_19 ;
goto V_20;
}
if ( ! F_22 ( V_6 ) ) {
F_9 ( V_3 , L_12 ) ;
V_13 = - V_7 ;
goto V_20;
}
V_3 -> V_21 . V_22 = F_23 ( V_6 , V_23 ) ;
if ( V_3 -> V_21 . V_22 == 0 )
F_9 ( V_3 , L_13 ) ;
V_13 = F_5 ( V_3 ) ;
if ( V_13 )
goto V_20;
V_3 -> V_21 . V_24 = F_24 ( V_6 , 0 ) ;
V_3 -> V_21 . V_25 = F_25 ( V_6 , 0 ) ;
V_3 -> V_21 . V_26 = V_6 -> V_26 ;
V_3 -> V_10 = F_26 ( V_6 , 0 ) ;
if ( ! V_3 -> V_10 ) {
F_9 ( V_3 , L_14 ) ;
V_13 = - V_27 ;
goto V_20;
}
V_3 -> V_28 = F_24 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_29 = F_27 ( V_3 -> V_6 , 2 ) ;
V_3 -> V_9 = F_28 ( V_3 -> V_28 , V_3 -> V_29 ) ;
if ( ! V_3 -> V_9 ) {
F_9 ( V_3 , L_15 ) ;
return - V_27 ;
}
return 0 ;
V_20:
F_13 ( V_6 ) ;
V_16:
F_14 ( V_6 ) ;
V_14:
return V_13 ;
}
int F_29 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_34 = V_3 -> V_34 ;
V_31 -> V_35 = V_3 -> V_21 . V_24 ;
V_31 -> V_36 = V_3 -> V_21 . V_25 ;
V_31 -> V_37 = V_3 -> V_21 . V_26 ;
V_31 -> V_38 = F_30 ( & V_3 -> V_39 [ 0 ] ) ;
F_31 ( V_31 -> V_40 , V_3 -> V_39 [ 0 ] . V_41 . V_42 ) ;
V_31 -> V_43 = V_44 ;
V_31 -> V_45 = V_46 ;
V_31 -> V_47 = V_48 ;
V_31 -> V_49 = V_50 ;
V_31 -> V_51 = V_3 -> V_51 ;
F_32 ( V_3 , & V_31 -> V_52 ) ;
V_33 = F_33 ( F_34 ( V_3 ) ) ;
if ( V_33 ) {
F_35 ( F_34 ( V_3 ) , V_33 ,
& V_31 -> V_53 ) ;
F_36 ( F_34 ( V_3 ) , V_33 ) ;
}
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
F_38 ( ( void * ) V_3 ) ;
}
static struct V_2 * F_39 ( struct V_8 * V_6 )
{
struct V_2 * V_3 ;
V_3 = F_40 ( sizeof( * V_3 ) , V_54 ) ;
if ( ! V_3 )
return V_3 ;
F_41 ( V_3 ) ;
return V_3 ;
}
static int F_42 ( struct V_2 * V_3 ,
T_4 V_55 )
{
if ( ! V_3 )
return - V_19 ;
F_43 ( V_3 , V_56 , L_16 ) ;
return 0 ;
}
static struct V_2 * F_44 ( struct V_8 * V_6 ,
enum V_57 V_58 ,
T_5 V_59 ,
T_3 V_60 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_39 ( V_6 ) ;
if ( ! V_3 )
goto V_14;
V_3 -> V_58 = V_58 ;
F_45 ( V_3 , V_59 , V_60 ) ;
V_13 = F_15 ( V_3 , V_6 ) ;
if ( V_13 ) {
F_46 ( V_3 , L_17 ) ;
goto V_16;
}
F_47 ( V_3 , L_18 ) ;
V_13 = F_48 ( V_3 , V_61 ) ;
if ( V_13 ) {
F_46 ( V_3 , L_19 ) ;
goto V_20;
}
F_47 ( V_3 , L_20 ) ;
return V_3 ;
V_20:
F_10 ( V_3 ) ;
V_16:
F_37 ( V_3 ) ;
V_14:
return NULL ;
}
static void F_49 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_50 ( V_3 ) ;
F_10 ( V_3 ) ;
F_42 ( V_3 , V_62 ) ;
F_37 ( V_3 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
if ( V_3 -> V_63 . V_64 . V_65 == V_66 ) {
F_52 ( V_3 -> V_6 ) ;
F_38 ( V_3 -> V_63 . V_67 ) ;
} else if ( V_3 -> V_63 . V_64 . V_65 == V_68 ) {
F_53 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_63 . V_64 , 0 , sizeof( struct V_69 ) ) ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_70 * V_63 )
{
int V_71 , V_13 , V_72 ;
V_72 = V_63 -> V_73 . V_74 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
V_63 -> V_67 [ V_71 ] . V_75 = V_71 ;
V_13 = F_55 ( V_3 -> V_6 , V_63 -> V_67 ,
V_63 -> V_73 . V_76 , V_72 ) ;
if ( V_13 < V_72 && V_13 >= V_63 -> V_73 . V_76 &&
( V_13 % V_3 -> V_34 ) ) {
F_52 ( V_3 -> V_6 ) ;
V_72 = ( V_13 / V_3 -> V_34 ) * V_3 -> V_34 ;
F_9 ( V_3 ,
L_21 ,
V_72 , V_63 -> V_73 . V_74 ) ;
V_13 = F_56 ( V_3 -> V_6 ,
V_63 -> V_67 , V_72 ) ;
if ( ! V_13 )
V_13 = V_72 ;
}
if ( V_13 > 0 ) {
V_63 -> V_64 . V_65 = V_66 ;
V_63 -> V_64 . V_74 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_22 ,
V_72 , V_13 ) ;
}
return V_13 ;
}
static int F_57 ( struct V_2 * V_3 , bool V_77 )
{
struct V_70 * V_63 = & V_3 -> V_63 ;
struct V_78 * V_79 ;
int V_13 = 0 , V_72 ;
switch ( V_63 -> V_73 . V_65 ) {
case V_66 :
V_72 = V_63 -> V_73 . V_74 ;
V_63 -> V_67 = F_58 ( V_72 , sizeof( * V_79 ) , V_54 ) ;
if ( ! V_63 -> V_67 ) {
V_13 = - V_27 ;
goto V_64;
}
V_13 = F_54 ( V_3 , V_63 ) ;
if ( ! V_13 )
goto V_64;
F_9 ( V_3 , L_23 ) ;
F_38 ( V_63 -> V_67 ) ;
if ( V_77 )
goto V_64;
case V_68 :
V_13 = F_59 ( V_3 -> V_6 ) ;
if ( ! V_13 ) {
V_63 -> V_64 . V_65 = V_68 ;
goto V_64;
}
F_9 ( V_3 , L_24 ) ;
if ( V_77 )
goto V_64;
case V_80 :
V_63 -> V_64 . V_65 = V_80 ;
V_13 = 0 ;
goto V_64;
default:
F_9 ( V_3 , L_25 ,
V_63 -> V_73 . V_65 ) ;
V_13 = - V_81 ;
}
V_64:
V_3 -> V_82 = V_83 ;
return V_13 ;
}
static void F_60 ( struct V_2 * V_3 , void * V_84 ,
int V_85 , void (* F_61)( void * ) )
{
struct V_86 * V_87 = & V_3 -> V_39 [ V_85 % V_3 -> V_34 ] ;
int V_88 = V_85 / V_3 -> V_34 ;
V_87 -> V_89 [ V_88 ] . V_90 = F_61 ;
V_87 -> V_89 [ V_88 ] . V_84 = V_84 ;
}
static void F_62 ( struct V_2 * V_3 , int V_85 )
{
struct V_86 * V_87 = & V_3 -> V_39 [ V_85 % V_3 -> V_34 ] ;
int V_88 = V_85 / V_3 -> V_34 ;
memset ( & V_87 -> V_89 [ V_88 ] , 0 ,
sizeof( struct V_91 ) ) ;
}
static T_6 F_63 ( int V_26 , void * V_92 )
{
F_64 ( (struct V_93 * ) V_92 ) ;
return V_94 ;
}
static T_6 F_65 ( int V_26 , void * V_95 )
{
struct V_2 * V_3 = (struct V_2 * ) V_95 ;
struct V_86 * V_87 ;
T_6 V_13 = V_96 ;
T_7 V_97 ;
int V_71 , V_98 ;
for ( V_71 = 0 ; V_71 < V_3 -> V_34 ; V_71 ++ ) {
V_97 = F_66 ( & V_3 -> V_39 [ V_71 ] ) ;
if ( ! V_97 )
continue;
V_87 = & V_3 -> V_39 [ V_71 ] ;
if ( F_67 ( V_97 & 0x1 ) ) {
F_64 ( V_87 -> V_99 ) ;
V_97 &= ~ 0x1 ;
V_13 = V_94 ;
}
for ( V_98 = 0 ; V_98 < 64 ; V_98 ++ ) {
if ( ( 0x2ULL << V_98 ) & V_97 ) {
V_87 -> V_89 [ V_98 ] . V_90 (
V_87 -> V_89 [ V_98 ] . V_84 ) ;
V_97 &= ~ ( 0x2ULL << V_98 ) ;
V_13 = V_94 ;
}
}
if ( F_67 ( V_97 ) )
F_43 ( V_87 , V_100 ,
L_26 ,
V_97 ) ;
}
return V_13 ;
}
int F_68 ( struct V_86 * V_87 )
{
struct V_2 * V_3 = V_87 -> V_3 ;
int V_13 = 0 ;
T_3 V_101 ;
if ( V_3 -> V_63 . V_64 . V_65 == V_66 ) {
V_101 = V_87 -> V_102 ;
snprintf ( V_87 -> V_103 , V_104 , L_27 ,
V_101 , V_3 -> V_6 -> V_105 -> V_106 ,
F_69 ( V_3 -> V_6 -> V_107 ) , V_87 -> V_108 ) ;
V_13 = F_70 ( V_3 -> V_63 . V_67 [ V_101 ] . V_109 ,
F_63 , 0 , V_87 -> V_103 , V_87 -> V_99 ) ;
if ( ! V_13 )
F_43 ( V_87 , ( V_100 | V_110 ) ,
L_28 ) ;
} else {
unsigned long V_111 = 0 ;
snprintf ( V_3 -> V_103 , V_104 , L_29 ,
V_3 -> V_6 -> V_105 -> V_106 , F_69 ( V_3 -> V_6 -> V_107 ) ,
F_71 ( V_3 -> V_6 -> V_107 ) ) ;
if ( V_3 -> V_63 . V_64 . V_65 == V_80 )
V_111 |= V_112 ;
V_13 = F_70 ( V_3 -> V_6 -> V_26 , F_65 ,
V_111 , V_3 -> V_103 , V_3 ) ;
}
return V_13 ;
}
static void F_72 ( struct V_2 * V_3 )
{
int V_71 ;
if ( V_3 -> V_63 . V_64 . V_65 == V_66 ) {
F_73 (cdev, i) {
if ( ! V_3 -> V_39 [ V_71 ] . V_113 )
break;
F_74 ( V_3 -> V_63 . V_67 [ V_71 ] . V_109 ) ;
F_75 ( V_3 -> V_63 . V_67 [ V_71 ] . V_109 ,
V_3 -> V_39 [ V_71 ] . V_99 ) ;
}
} else {
if ( F_34 ( V_3 ) -> V_113 )
F_75 ( V_3 -> V_6 -> V_26 , V_3 ) ;
}
F_76 ( V_3 ) ;
}
static int F_77 ( struct V_2 * V_3 )
{
int V_71 , V_13 ;
V_13 = F_78 ( V_3 ) ;
for ( V_71 = 0 ; V_71 < V_3 -> V_34 ; V_71 ++ ) {
struct V_86 * V_114 = & V_3 -> V_39 [ V_71 ] ;
if ( V_114 -> V_115 ) {
F_79 ( V_114 -> V_99 ) ;
V_114 -> V_115 = false ;
F_43 ( V_3 , V_116 ,
L_30 ,
V_71 , V_114 -> V_99 ) ;
}
}
return V_13 ;
}
static int F_80 ( struct V_2 * V_3 )
{
int V_13 ;
V_13 = F_81 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_82 ( V_3 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 )
{
int V_13 ;
V_13 = F_84 ( V_3 ) ;
if ( V_13 )
return V_13 ;
F_47 ( V_3 , L_31 ) ;
F_85 ( V_3 ) ;
return V_13 ;
}
static int F_86 ( struct V_2 * V_3 , T_8 V_72 )
{
int V_117 = 0 ;
V_3 -> V_63 . V_118 = V_72 ? true : false ;
if ( V_3 -> V_63 . V_64 . V_65 != V_66 )
V_117 = V_3 -> V_34 * 63 ;
else if ( V_3 -> V_63 . V_119 )
V_117 = V_3 -> V_63 . V_119 ;
if ( ! V_117 )
return - V_27 ;
return F_87 ( int , V_72 , V_117 ) ;
}
static int F_88 ( struct V_2 * V_3 , struct V_120 * V_121 )
{
memset ( V_121 , 0 , sizeof( struct V_120 ) ) ;
if ( ! V_3 -> V_63 . V_118 ) {
F_47 ( V_3 ,
L_32 ) ;
return - V_81 ;
}
if ( V_3 -> V_63 . V_64 . V_65 == V_66 ) {
int V_122 = V_3 -> V_63 . V_123 ;
V_121 -> V_124 = V_3 -> V_63 . V_119 ;
V_121 -> V_125 = & V_3 -> V_63 . V_67 [ V_122 ] ;
}
return 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
enum V_126 V_65 )
{
struct V_127 V_128 ;
int V_13 ;
int V_71 ;
memset ( & V_3 -> V_63 , 0 , sizeof( struct V_70 ) ) ;
V_3 -> V_63 . V_73 . V_65 = V_65 ;
F_73 (cdev, i) {
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_90 ( & V_3 -> V_39 [ V_71 ] , & V_128 ) ;
V_3 -> V_63 . V_73 . V_74 += V_128 . V_129 ;
V_3 -> V_63 . V_73 . V_74 ++ ;
}
V_3 -> V_63 . V_73 . V_76 = V_3 -> V_34 * 2 ;
V_13 = F_57 ( V_3 , false ) ;
if ( V_13 ) {
F_46 ( V_3 , L_33 ) ;
return V_13 ;
}
V_3 -> V_63 . V_123 = V_3 -> V_34 ;
V_3 -> V_63 . V_119 = V_3 -> V_63 . V_64 . V_74 -
V_3 -> V_34 ;
return 0 ;
}
T_5 F_91 ( struct V_86 * V_114 , T_5 V_130 ,
T_3 * V_131 , T_5 V_132 , T_3 * V_133 )
{
int V_13 ;
V_114 -> V_134 -> V_135 = V_131 ;
V_114 -> V_134 -> V_136 = V_130 ;
V_114 -> V_134 -> V_137 = V_133 ;
V_114 -> V_134 -> V_138 = V_132 ;
V_13 = F_92 ( V_114 -> V_134 , V_139 ) ;
if ( V_13 != V_140 ) {
F_43 ( V_114 , V_56 , L_34 ,
V_13 ) ;
return 0 ;
}
V_13 = F_93 ( V_114 -> V_134 , V_141 ) ;
F_94 ( V_114 -> V_134 ) ;
if ( V_13 != V_140 && V_13 != V_142 ) {
F_43 ( V_114 , V_56 , L_35 ,
V_114 -> V_134 -> V_143 , V_13 ) ;
return 0 ;
}
return V_114 -> V_134 -> V_144 / 4 ;
}
static int F_95 ( struct V_2 * V_3 )
{
int V_71 ;
void * V_145 ;
F_73 (cdev, i) {
struct V_86 * V_114 = & V_3 -> V_39 [ V_71 ] ;
V_114 -> V_134 = F_40 ( sizeof( * V_114 -> V_134 ) , V_54 ) ;
if ( ! V_114 -> V_134 )
return - V_27 ;
V_145 = F_96 ( F_97 () ) ;
if ( ! V_145 )
return - V_27 ;
V_114 -> V_134 -> V_145 = V_145 ;
}
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
int V_71 ;
F_73 (cdev, i) {
struct V_86 * V_114 = & V_3 -> V_39 [ V_71 ] ;
if ( ! V_114 -> V_134 )
return;
F_99 ( V_114 -> V_134 -> V_145 ) ;
F_38 ( V_114 -> V_134 ) ;
}
}
static void F_100 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_3 -> V_34 ; V_71 ++ ) {
struct V_86 * V_114 = & V_3 -> V_39 [ V_71 ] ;
V_114 -> V_148 = * V_147 ;
}
}
static int F_101 ( struct V_2 * V_3 ,
struct V_149 * V_147 )
{
struct V_150 V_151 ;
const T_3 * V_152 = NULL ;
struct V_86 * V_87 ;
int V_13 ;
V_13 = F_102 ( & V_3 -> V_153 , V_154 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_36 ,
V_154 ) ;
goto V_155;
}
V_13 = F_83 ( V_3 ) ;
if ( V_13 )
goto V_155;
V_13 = F_89 ( V_3 , V_147 -> V_65 ) ;
if ( V_13 )
goto V_16;
V_13 = F_95 ( V_3 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_37 ) ;
goto V_20;
}
V_152 = V_3 -> V_153 -> V_152 ;
V_13 = F_103 ( V_3 , true , V_3 -> V_63 . V_64 . V_65 ,
true , V_152 ) ;
if ( V_13 )
goto V_20;
F_47 ( V_3 ,
L_38 ) ;
V_87 = F_34 ( V_3 ) ;
V_151 . V_1 = ( V_147 -> V_156 << 24 ) |
( V_147 -> V_157 << 16 ) |
( V_147 -> V_158 << 8 ) |
( V_147 -> V_159 ) ;
F_104 ( V_151 . V_103 , V_147 -> V_103 ,
V_160 - 4 ) ;
V_13 = F_105 ( V_87 , V_87 -> V_161 ,
& V_151 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_39 ) ;
return V_13 ;
}
F_106 ( V_3 ) ;
return 0 ;
V_20:
F_107 ( V_3 ) ;
F_72 ( V_3 ) ;
F_98 ( V_3 ) ;
F_51 ( V_3 ) ;
V_16:
F_82 ( V_3 ) ;
V_155:
F_108 ( V_3 -> V_153 ) ;
return V_13 ;
}
static int F_109 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
F_98 ( V_3 ) ;
F_77 ( V_3 ) ;
F_72 ( V_3 ) ;
F_51 ( V_3 ) ;
F_80 ( V_3 ) ;
F_108 ( V_3 -> V_153 ) ;
return 0 ;
}
static void F_110 ( struct V_2 * V_3 , char V_103 [ V_104 ] ,
char V_162 [ V_163 ] )
{
int V_71 ;
memcpy ( V_3 -> V_103 , V_103 , V_104 ) ;
F_73 (cdev, i)
snprintf ( V_3 -> V_39 [ V_71 ] . V_103 , V_104 , L_40 , V_103 , V_71 ) ;
memcpy ( V_3 -> V_162 , V_162 , V_163 ) ;
V_3 -> V_164 = V_165 ;
}
static T_5 F_111 ( struct V_2 * V_3 ,
struct V_166 * V_167 ,
void * V_168 ,
T_9 V_169 , T_8 V_170 ,
enum V_171 type )
{
struct V_86 * V_114 ;
int V_172 ;
T_8 V_173 ;
T_3 V_174 ;
T_5 V_13 ;
if ( type == V_175 )
V_174 = V_3 -> V_34 ;
else
V_174 = 1 ;
V_172 = V_170 % V_174 ;
V_114 = & V_3 -> V_39 [ V_172 ] ;
V_173 = V_170 / V_174 ;
F_43 ( V_3 , V_100 ,
L_41 ,
V_172 , V_173 , V_170 ) ;
V_13 = F_112 ( V_114 , V_114 -> V_161 , V_167 ,
V_168 , V_169 , V_173 ) ;
return V_13 ;
}
static T_5 F_113 ( struct V_2 * V_3 ,
struct V_166 * V_167 ,
T_8 V_170 )
{
struct V_86 * V_114 ;
int V_172 ;
T_8 V_173 ;
T_5 V_13 ;
V_172 = V_170 % V_3 -> V_34 ;
V_114 = & V_3 -> V_39 [ V_172 ] ;
V_173 = V_170 / V_3 -> V_34 ;
F_43 ( V_3 , V_100 ,
L_41 ,
V_172 , V_173 , V_170 ) ;
V_13 = F_114 ( V_114 , V_167 , V_173 ) ;
return V_13 ;
}
static int F_115 ( struct V_2 * V_3 ,
struct V_176 * V_147 )
{
struct V_86 * V_87 ;
struct V_177 * V_178 ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
V_87 = & V_3 -> V_39 [ 0 ] ;
V_33 = F_33 ( V_87 ) ;
if ( ! V_33 )
return - V_179 ;
V_178 = F_116 ( V_87 ) ;
if ( V_147 -> V_180 & V_181 )
V_178 -> V_182 . V_183 = V_147 -> V_183 ;
if ( V_147 -> V_180 & V_184 ) {
V_178 -> V_182 . V_185 = 0 ;
if ( ( V_147 -> V_186 & V_187 ) ||
( V_147 -> V_186 & V_188 ) )
V_178 -> V_182 . V_185 |=
V_189 ;
if ( V_147 -> V_186 & V_190 )
V_178 -> V_182 . V_185 |=
V_191 ;
if ( V_147 -> V_186 & V_192 )
V_178 -> V_182 . V_185 |=
V_193 ;
if ( V_147 -> V_186 & 0 )
V_178 -> V_182 . V_185 |=
V_194 ;
if ( V_147 -> V_186 & 0 )
V_178 -> V_182 . V_185 |=
V_195 ;
}
if ( V_147 -> V_180 & V_196 )
V_178 -> V_182 . V_197 = V_147 -> V_197 ;
V_13 = F_117 ( V_87 , V_33 , V_147 -> V_198 ) ;
F_36 ( V_87 , V_33 ) ;
return V_13 ;
}
static int F_118 ( T_5 V_199 )
{
int V_200 ;
switch ( V_199 ) {
case V_201 :
case V_202 :
case V_203 :
case V_204 :
V_200 = V_205 ;
break;
case V_206 :
V_200 = V_207 ;
break;
case V_208 :
V_200 = V_209 ;
break;
case V_210 :
V_200 = V_211 ;
break;
case V_212 :
default:
V_200 = V_213 ;
break;
}
return V_200 ;
}
static void F_119 ( struct V_86 * V_87 ,
struct V_214 * V_215 )
{
struct V_177 V_147 ;
struct V_216 V_217 ;
struct V_218 V_219 ;
T_5 V_199 ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
memcpy ( & V_147 , F_116 ( V_87 ) , sizeof( V_147 ) ) ;
memcpy ( & V_217 , F_120 ( V_87 ) , sizeof( V_217 ) ) ;
memcpy ( & V_219 , F_121 ( V_87 ) ,
sizeof( V_219 ) ) ;
if ( V_217 . V_198 )
V_215 -> V_198 = true ;
V_215 -> V_220 = V_221 ;
if ( V_147 . V_182 . V_183 )
V_215 -> V_220 |= V_222 ;
if ( V_147 . V_223 . V_183 ||
( V_147 . V_223 . V_224 && V_147 . V_223 . V_225 ) )
V_215 -> V_220 |= V_226 ;
if ( V_147 . V_223 . V_183 || V_147 . V_223 . V_224 ||
V_147 . V_223 . V_225 )
V_215 -> V_220 |= V_227 ;
V_215 -> V_228 = V_215 -> V_220 ;
if ( V_147 . V_182 . V_185 &
V_189 )
V_215 -> V_228 |= V_187 |
V_188 ;
if ( V_147 . V_182 . V_185 &
V_191 )
V_215 -> V_228 |= V_190 ;
if ( V_147 . V_182 . V_185 &
V_193 )
V_215 -> V_228 |= V_192 ;
if ( V_147 . V_182 . V_185 &
V_194 )
V_215 -> V_228 |= 0 ;
if ( V_147 . V_182 . V_185 &
V_195 )
V_215 -> V_228 |= 0 ;
if ( V_219 . V_229 &
V_189 )
V_215 -> V_220 |= V_187 |
V_188 ;
if ( V_219 . V_229 &
V_191 )
V_215 -> V_220 |= V_190 ;
if ( V_219 . V_229 &
V_193 )
V_215 -> V_220 |= V_192 ;
if ( V_219 . V_229 &
V_194 )
V_215 -> V_220 |= 0 ;
if ( V_219 . V_229 &
V_195 )
V_215 -> V_220 |= 0 ;
if ( V_217 . V_198 )
V_215 -> V_182 = V_217 . V_182 ;
V_215 -> V_230 = V_231 ;
F_122 ( V_87 -> V_3 , & V_199 ) ;
V_215 -> V_232 = F_118 ( V_199 ) ;
V_215 -> V_183 = V_147 . V_182 . V_183 ;
if ( V_147 . V_223 . V_183 )
V_215 -> V_233 |= V_234 ;
if ( V_147 . V_223 . V_224 )
V_215 -> V_233 |= V_235 ;
if ( V_147 . V_223 . V_225 )
V_215 -> V_233 |= V_236 ;
if ( V_217 . V_237 &
V_238 )
V_215 -> V_239 |= V_187 ;
if ( V_217 . V_237 &
V_240 )
V_215 -> V_239 |= V_188 ;
if ( V_217 . V_237 &
V_241 )
V_215 -> V_239 |= V_190 ;
if ( V_217 . V_237 &
V_242 )
V_215 -> V_239 |= V_192 ;
if ( V_217 . V_237 &
V_243 )
V_215 -> V_239 |= 0 ;
if ( V_217 . V_237 &
V_244 )
V_215 -> V_239 |= 0 ;
if ( V_217 . V_245 )
V_215 -> V_239 |= V_222 ;
if ( V_217 . V_246 )
V_215 -> V_239 |= V_227 ;
if ( V_217 . V_246 == V_247 ||
V_217 . V_246 == V_248 )
V_215 -> V_239 |= V_226 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_214 * V_215 )
{
F_119 ( & V_3 -> V_39 [ 0 ] , V_215 ) ;
}
void F_124 ( struct V_86 * V_87 )
{
void * V_249 = V_87 -> V_3 -> V_250 ;
struct V_251 * V_252 = V_87 -> V_3 -> V_253 . V_254 ;
struct V_214 V_215 ;
F_119 ( V_87 , & V_215 ) ;
if ( F_125 ( V_87 ) && V_249 )
V_252 -> V_255 ( V_249 , & V_215 ) ;
}
static int F_126 ( struct V_2 * V_3 )
{
struct V_86 * V_87 ;
struct V_32 * V_33 ;
int V_71 , V_13 ;
F_73 (cdev, i) {
V_87 = & V_3 -> V_39 [ V_71 ] ;
V_33 = F_33 ( V_87 ) ;
if ( ! V_33 ) {
F_9 ( V_87 , L_42 ) ;
return - V_179 ;
}
V_13 = F_127 ( V_87 , V_33 ) ;
if ( V_13 )
return V_13 ;
F_36 ( V_87 , V_33 ) ;
}
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , enum V_256 V_257 )
{
struct V_86 * V_87 = F_34 ( V_3 ) ;
struct V_32 * V_33 ;
int V_97 = 0 ;
V_33 = F_33 ( V_87 ) ;
if ( ! V_33 )
return - V_258 ;
V_97 = F_129 ( V_87 , V_33 , V_257 ) ;
F_36 ( V_87 , V_33 ) ;
return V_97 ;
}
T_5 F_130 ( enum V_57 V_58 )
{
switch ( V_58 ) {
case V_259 :
return V_260 ;
default:
return 0 ;
}
}
