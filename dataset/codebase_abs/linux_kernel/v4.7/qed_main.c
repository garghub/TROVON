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
V_31 -> V_38 = F_31 ( & V_3 -> V_39 [ 0 ] ) ;
F_32 ( V_31 -> V_40 , V_3 -> V_39 [ 0 ] . V_41 . V_42 ) ;
if ( F_18 ( V_3 ) ) {
V_31 -> V_43 = V_44 ;
V_31 -> V_45 = V_46 ;
V_31 -> V_47 = V_48 ;
V_31 -> V_49 = V_50 ;
V_31 -> V_51 = V_3 -> V_51 ;
V_31 -> V_52 = true ;
} else {
F_33 ( & V_3 -> V_39 [ 0 ] , & V_31 -> V_43 ,
& V_31 -> V_45 , & V_31 -> V_47 ,
& V_31 -> V_49 ) ;
}
if ( F_18 ( V_3 ) ) {
V_33 = F_34 ( F_35 ( V_3 ) ) ;
if ( V_33 ) {
F_36 ( F_35 ( V_3 ) , V_33 ,
& V_31 -> V_53 , NULL ) ;
F_37 ( F_35 ( V_3 ) , V_33 ,
& V_31 -> V_54 ) ;
F_38 ( F_35 ( V_3 ) , V_33 ) ;
}
} else {
F_36 ( F_35 ( V_3 ) , NULL ,
& V_31 -> V_53 , NULL ) ;
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
V_3 = F_42 ( sizeof( * V_3 ) , V_55 ) ;
if ( ! V_3 )
return V_3 ;
F_43 ( V_3 ) ;
return V_3 ;
}
static int F_44 ( struct V_2 * V_3 ,
T_4 V_56 )
{
if ( ! V_3 )
return - V_19 ;
F_45 ( V_3 , V_57 , L_16 ) ;
return 0 ;
}
static struct V_2 * F_46 ( struct V_8 * V_6 ,
struct V_58 * V_59 )
{
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_41 ( V_6 ) ;
if ( ! V_3 )
goto V_14;
V_3 -> V_60 = V_59 -> V_60 ;
if ( V_59 -> V_61 )
V_3 -> V_62 = true ;
F_47 ( V_3 , V_59 -> V_63 , V_59 -> V_64 ) ;
V_13 = F_15 ( V_3 , V_6 ) ;
if ( V_13 ) {
F_48 ( V_3 , L_17 ) ;
goto V_16;
}
F_49 ( V_3 , L_18 ) ;
V_13 = F_50 ( V_3 , V_65 ) ;
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
F_44 ( V_3 , V_66 ) ;
F_39 ( V_3 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
if ( V_3 -> V_67 . V_68 . V_69 == V_70 ) {
F_54 ( V_3 -> V_6 ) ;
F_40 ( V_3 -> V_67 . V_71 ) ;
} else if ( V_3 -> V_67 . V_68 . V_69 == V_72 ) {
F_55 ( V_3 -> V_6 ) ;
}
memset ( & V_3 -> V_67 . V_68 , 0 , sizeof( struct V_73 ) ) ;
}
static int F_56 ( struct V_2 * V_3 ,
struct V_74 * V_67 )
{
int V_75 , V_13 , V_76 ;
V_76 = V_67 -> V_77 . V_78 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
V_67 -> V_71 [ V_75 ] . V_79 = V_75 ;
V_13 = F_57 ( V_3 -> V_6 , V_67 -> V_71 ,
V_67 -> V_77 . V_80 , V_76 ) ;
if ( V_13 < V_76 && V_13 >= V_67 -> V_77 . V_80 &&
( V_13 % V_3 -> V_34 ) ) {
F_54 ( V_3 -> V_6 ) ;
V_76 = ( V_13 / V_3 -> V_34 ) * V_3 -> V_34 ;
F_9 ( V_3 ,
L_21 ,
V_76 , V_67 -> V_77 . V_78 ) ;
V_13 = F_58 ( V_3 -> V_6 ,
V_67 -> V_71 , V_76 ) ;
if ( ! V_13 )
V_13 = V_76 ;
}
if ( V_13 > 0 ) {
V_67 -> V_68 . V_69 = V_70 ;
V_67 -> V_68 . V_78 = V_13 ;
V_13 = 0 ;
} else {
F_9 ( V_3 ,
L_22 ,
V_76 , V_13 ) ;
}
return V_13 ;
}
static int F_59 ( struct V_2 * V_3 , bool V_81 )
{
struct V_74 * V_67 = & V_3 -> V_67 ;
struct V_82 * V_83 ;
int V_13 = 0 , V_76 ;
switch ( V_67 -> V_77 . V_69 ) {
case V_70 :
V_76 = V_67 -> V_77 . V_78 ;
V_67 -> V_71 = F_60 ( V_76 , sizeof( * V_83 ) , V_55 ) ;
if ( ! V_67 -> V_71 ) {
V_13 = - V_27 ;
goto V_68;
}
V_13 = F_56 ( V_3 , V_67 ) ;
if ( ! V_13 )
goto V_68;
F_9 ( V_3 , L_23 ) ;
F_40 ( V_67 -> V_71 ) ;
if ( V_81 )
goto V_68;
case V_72 :
if ( V_3 -> V_34 == 1 ) {
V_13 = F_61 ( V_3 -> V_6 ) ;
if ( ! V_13 ) {
V_67 -> V_68 . V_69 = V_72 ;
goto V_68;
}
F_9 ( V_3 , L_24 ) ;
if ( V_81 )
goto V_68;
}
case V_84 :
V_67 -> V_68 . V_69 = V_84 ;
V_13 = 0 ;
goto V_68;
default:
F_9 ( V_3 , L_25 ,
V_67 -> V_77 . V_69 ) ;
V_13 = - V_85 ;
}
V_68:
V_3 -> V_86 = V_87 ;
return V_13 ;
}
static void F_62 ( struct V_2 * V_3 , void * V_88 ,
int V_89 , void (* F_63)( void * ) )
{
struct V_90 * V_91 = & V_3 -> V_39 [ V_89 % V_3 -> V_34 ] ;
int V_92 = V_89 / V_3 -> V_34 ;
V_91 -> V_93 [ V_92 ] . V_94 = F_63 ;
V_91 -> V_93 [ V_92 ] . V_88 = V_88 ;
}
static void F_64 ( struct V_2 * V_3 , int V_89 )
{
struct V_90 * V_91 = & V_3 -> V_39 [ V_89 % V_3 -> V_34 ] ;
int V_92 = V_89 / V_3 -> V_34 ;
memset ( & V_91 -> V_93 [ V_92 ] , 0 ,
sizeof( struct V_95 ) ) ;
}
static T_5 F_65 ( int V_26 , void * V_96 )
{
F_66 ( (struct V_97 * ) V_96 ) ;
return V_98 ;
}
static T_5 F_67 ( int V_26 , void * V_99 )
{
struct V_2 * V_3 = (struct V_2 * ) V_99 ;
struct V_90 * V_91 ;
T_5 V_13 = V_100 ;
T_6 V_101 ;
int V_75 , V_102 ;
for ( V_75 = 0 ; V_75 < V_3 -> V_34 ; V_75 ++ ) {
V_101 = F_68 ( & V_3 -> V_39 [ V_75 ] ) ;
if ( ! V_101 )
continue;
V_91 = & V_3 -> V_39 [ V_75 ] ;
if ( F_69 ( V_101 & 0x1 ) ) {
F_66 ( V_91 -> V_103 ) ;
V_101 &= ~ 0x1 ;
V_13 = V_98 ;
}
for ( V_102 = 0 ; V_102 < 64 ; V_102 ++ ) {
if ( ( 0x2ULL << V_102 ) & V_101 ) {
V_91 -> V_93 [ V_102 ] . V_94 (
V_91 -> V_93 [ V_102 ] . V_88 ) ;
V_101 &= ~ ( 0x2ULL << V_102 ) ;
V_13 = V_98 ;
}
}
if ( F_69 ( V_101 ) )
F_45 ( V_91 , V_104 ,
L_26 ,
V_101 ) ;
}
return V_13 ;
}
int F_70 ( struct V_90 * V_91 )
{
struct V_2 * V_3 = V_91 -> V_3 ;
int V_13 = 0 ;
T_3 V_105 ;
if ( V_3 -> V_67 . V_68 . V_69 == V_70 ) {
V_105 = V_91 -> V_106 ;
snprintf ( V_91 -> V_107 , V_108 , L_27 ,
V_105 , V_3 -> V_6 -> V_109 -> V_110 ,
F_71 ( V_3 -> V_6 -> V_111 ) , V_91 -> V_112 ) ;
V_13 = F_72 ( V_3 -> V_67 . V_71 [ V_105 ] . V_113 ,
F_65 , 0 , V_91 -> V_107 , V_91 -> V_103 ) ;
if ( ! V_13 )
F_45 ( V_91 , ( V_104 | V_114 ) ,
L_28 ) ;
} else {
unsigned long V_115 = 0 ;
snprintf ( V_3 -> V_107 , V_108 , L_29 ,
V_3 -> V_6 -> V_109 -> V_110 , F_71 ( V_3 -> V_6 -> V_111 ) ,
F_73 ( V_3 -> V_6 -> V_111 ) ) ;
if ( V_3 -> V_67 . V_68 . V_69 == V_84 )
V_115 |= V_116 ;
V_13 = F_72 ( V_3 -> V_6 -> V_26 , F_67 ,
V_115 , V_3 -> V_107 , V_3 ) ;
}
return V_13 ;
}
static void F_74 ( struct V_2 * V_3 )
{
int V_75 ;
if ( V_3 -> V_67 . V_68 . V_69 == V_70 ) {
F_75 (cdev, i) {
if ( ! V_3 -> V_39 [ V_75 ] . V_117 )
break;
F_76 ( V_3 -> V_67 . V_71 [ V_75 ] . V_113 ) ;
F_77 ( V_3 -> V_67 . V_71 [ V_75 ] . V_113 ,
V_3 -> V_39 [ V_75 ] . V_103 ) ;
}
} else {
if ( F_35 ( V_3 ) -> V_117 )
F_77 ( V_3 -> V_6 -> V_26 , V_3 ) ;
}
F_78 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 )
{
int V_75 , V_13 ;
V_13 = F_80 ( V_3 ) ;
for ( V_75 = 0 ; V_75 < V_3 -> V_34 ; V_75 ++ ) {
struct V_90 * V_118 = & V_3 -> V_39 [ V_75 ] ;
if ( V_118 -> V_119 ) {
F_81 ( V_118 -> V_103 ) ;
V_118 -> V_119 = false ;
F_45 ( V_3 , V_120 ,
L_30 ,
V_75 , V_118 -> V_103 ) ;
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
static int F_88 ( struct V_2 * V_3 , T_7 V_76 )
{
int V_121 = 0 ;
V_3 -> V_67 . V_122 = V_76 ? true : false ;
if ( V_3 -> V_67 . V_68 . V_69 != V_70 )
V_121 = V_3 -> V_34 * 63 ;
else if ( V_3 -> V_67 . V_123 )
V_121 = V_3 -> V_67 . V_123 ;
if ( ! V_121 )
return - V_27 ;
return F_89 ( int , V_76 , V_121 ) ;
}
static int F_90 ( struct V_2 * V_3 , struct V_124 * V_125 )
{
memset ( V_125 , 0 , sizeof( struct V_124 ) ) ;
if ( ! V_3 -> V_67 . V_122 ) {
F_49 ( V_3 ,
L_32 ) ;
return - V_85 ;
}
if ( V_3 -> V_67 . V_68 . V_69 == V_70 ) {
int V_126 = V_3 -> V_67 . V_127 ;
V_125 -> V_128 = V_3 -> V_67 . V_123 ;
V_125 -> V_129 = & V_3 -> V_67 . V_71 [ V_126 ] ;
}
return 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
enum V_130 V_69 )
{
struct V_131 V_132 ;
int V_13 ;
int V_75 ;
memset ( & V_3 -> V_67 , 0 , sizeof( struct V_74 ) ) ;
V_3 -> V_67 . V_77 . V_69 = V_69 ;
F_75 (cdev, i) {
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
F_92 ( & V_3 -> V_39 [ V_75 ] , & V_132 ) ;
V_3 -> V_67 . V_77 . V_78 += V_132 . V_133 ;
V_3 -> V_67 . V_77 . V_78 ++ ;
}
V_3 -> V_67 . V_77 . V_80 = V_3 -> V_34 * 2 ;
V_13 = F_59 ( V_3 , false ) ;
if ( V_13 ) {
F_48 ( V_3 , L_33 ) ;
return V_13 ;
}
V_3 -> V_67 . V_127 = V_3 -> V_34 ;
V_3 -> V_67 . V_123 = V_3 -> V_67 . V_68 . V_78 -
V_3 -> V_34 ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
int V_13 ;
memset ( & V_3 -> V_67 , 0 , sizeof( struct V_74 ) ) ;
V_3 -> V_67 . V_77 . V_69 = V_70 ;
F_94 ( F_35 ( V_3 ) ,
& V_3 -> V_67 . V_77 . V_78 ) ;
if ( V_3 -> V_34 > 1 ) {
T_3 V_134 = 0 ;
F_94 ( & V_3 -> V_39 [ 1 ] , & V_134 ) ;
V_3 -> V_67 . V_77 . V_78 += V_134 ;
}
V_3 -> V_67 . V_77 . V_80 = V_3 -> V_34 ;
V_13 = F_59 ( V_3 , true ) ;
if ( V_13 )
return V_13 ;
V_3 -> V_67 . V_127 = 0 ;
V_3 -> V_67 . V_123 = V_3 -> V_67 . V_68 . V_78 ;
return 0 ;
}
T_8 F_95 ( struct V_90 * V_118 , T_8 V_135 ,
T_3 * V_136 , T_8 V_137 , T_3 * V_138 )
{
int V_13 ;
V_118 -> V_139 -> V_140 = V_136 ;
V_118 -> V_139 -> V_141 = V_135 ;
V_118 -> V_139 -> V_142 = V_138 ;
V_118 -> V_139 -> V_143 = V_137 ;
V_13 = F_96 ( V_118 -> V_139 , V_144 ) ;
if ( V_13 != V_145 ) {
F_45 ( V_118 , V_57 , L_34 ,
V_13 ) ;
return 0 ;
}
V_13 = F_97 ( V_118 -> V_139 , V_146 ) ;
F_98 ( V_118 -> V_139 ) ;
if ( V_13 != V_145 && V_13 != V_147 ) {
F_45 ( V_118 , V_57 , L_35 ,
V_118 -> V_139 -> V_148 , V_13 ) ;
return 0 ;
}
return V_118 -> V_139 -> V_149 / 4 ;
}
static int F_99 ( struct V_2 * V_3 )
{
int V_75 ;
void * V_150 ;
F_75 (cdev, i) {
struct V_90 * V_118 = & V_3 -> V_39 [ V_75 ] ;
V_118 -> V_139 = F_42 ( sizeof( * V_118 -> V_139 ) , V_55 ) ;
if ( ! V_118 -> V_139 )
return - V_27 ;
V_150 = F_100 ( F_101 () ) ;
if ( ! V_150 )
return - V_27 ;
V_118 -> V_139 -> V_150 = V_150 ;
}
return 0 ;
}
static void F_102 ( struct V_2 * V_3 )
{
int V_75 ;
F_75 (cdev, i) {
struct V_90 * V_118 = & V_3 -> V_39 [ V_75 ] ;
if ( ! V_118 -> V_139 )
return;
F_103 ( V_118 -> V_139 -> V_150 ) ;
F_40 ( V_118 -> V_139 ) ;
}
}
static void F_104 ( struct V_2 * V_3 ,
struct V_151 * V_59 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_3 -> V_34 ; V_75 ++ ) {
struct V_90 * V_118 = & V_3 -> V_39 [ V_75 ] ;
V_118 -> V_152 = * V_59 ;
}
}
static int F_105 ( struct V_2 * V_3 ,
struct V_153 * V_59 )
{
struct V_154 V_155 ;
struct V_156 V_157 ;
const T_3 * V_158 = NULL ;
struct V_90 * V_91 ;
int V_13 = - V_85 ;
if ( F_106 ( V_3 ) )
goto V_159;
if ( F_18 ( V_3 ) ) {
V_13 = F_107 ( & V_3 -> V_160 , V_161 ,
& V_3 -> V_6 -> V_5 ) ;
if ( V_13 ) {
F_9 ( V_3 ,
L_36 ,
V_161 ) ;
goto V_159;
}
}
V_13 = F_85 ( V_3 ) ;
if ( V_13 )
goto V_159;
if ( F_18 ( V_3 ) )
V_13 = F_91 ( V_3 , V_59 -> V_69 ) ;
else
V_13 = F_93 ( V_3 ) ;
if ( V_13 )
goto V_16;
if ( F_18 ( V_3 ) ) {
V_13 = F_99 ( V_3 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_37 ) ;
goto V_20;
}
V_158 = V_3 -> V_160 -> V_158 ;
}
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_162 |= 1 << V_163 |
1 << V_164 |
1 << V_165 |
1 << V_166 |
1 << V_167 ;
V_155 . V_168 = V_169 ;
V_155 . V_170 = V_169 ;
V_155 . V_171 = V_169 ;
V_13 = F_108 ( V_3 , & V_155 , true ,
V_3 -> V_67 . V_68 . V_69 ,
true , V_158 ) ;
if ( V_13 )
goto V_20;
F_49 ( V_3 ,
L_38 ) ;
if ( F_18 ( V_3 ) ) {
V_91 = F_35 ( V_3 ) ;
V_157 . V_1 = ( V_59 -> V_172 << 24 ) |
( V_59 -> V_173 << 16 ) |
( V_59 -> V_174 << 8 ) |
( V_59 -> V_175 ) ;
F_109 ( V_157 . V_107 , V_59 -> V_107 ,
V_176 - 4 ) ;
V_13 = F_110 ( V_91 , V_91 -> V_177 ,
& V_157 ) ;
if ( V_13 ) {
F_9 ( V_3 , L_39 ) ;
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
V_159:
if ( F_18 ( V_3 ) )
F_113 ( V_3 -> V_160 ) ;
F_114 ( V_3 , false ) ;
return V_13 ;
}
static int F_115 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return - V_19 ;
if ( F_18 ( V_3 ) ) {
F_102 ( V_3 ) ;
F_116 ( V_3 , true ) ;
F_79 ( V_3 ) ;
F_74 ( V_3 ) ;
}
F_53 ( V_3 ) ;
F_82 ( V_3 ) ;
F_114 ( V_3 , true ) ;
if ( F_18 ( V_3 ) )
F_113 ( V_3 -> V_160 ) ;
return 0 ;
}
static void F_117 ( struct V_2 * V_3 , char V_107 [ V_108 ] ,
char V_178 [ V_179 ] )
{
int V_75 ;
memcpy ( V_3 -> V_107 , V_107 , V_108 ) ;
F_75 (cdev, i)
snprintf ( V_3 -> V_39 [ V_75 ] . V_107 , V_108 , L_40 , V_107 , V_75 ) ;
memcpy ( V_3 -> V_178 , V_178 , V_179 ) ;
V_3 -> V_180 = V_181 ;
}
static T_8 F_118 ( struct V_2 * V_3 ,
struct V_182 * V_183 ,
void * V_184 ,
T_9 V_185 , T_7 V_186 ,
enum V_187 type )
{
struct V_90 * V_118 ;
int V_188 ;
T_7 V_189 ;
T_3 V_190 ;
T_8 V_13 ;
if ( type == V_191 )
V_190 = V_3 -> V_34 ;
else
V_190 = 1 ;
V_188 = V_186 % V_190 ;
V_118 = & V_3 -> V_39 [ V_188 ] ;
V_189 = V_186 / V_190 ;
F_45 ( V_3 , V_104 ,
L_41 ,
V_188 , V_189 , V_186 ) ;
V_13 = F_119 ( V_118 , V_118 -> V_177 , V_183 ,
V_184 , V_185 , V_189 ) ;
return V_13 ;
}
static T_8 F_120 ( struct V_2 * V_3 ,
struct V_182 * V_183 ,
T_7 V_186 )
{
struct V_90 * V_118 ;
int V_188 ;
T_7 V_189 ;
T_8 V_13 ;
V_188 = V_186 % V_3 -> V_34 ;
V_118 = & V_3 -> V_39 [ V_188 ] ;
V_189 = V_186 / V_3 -> V_34 ;
F_45 ( V_3 , V_104 ,
L_41 ,
V_188 , V_189 , V_186 ) ;
V_13 = F_121 ( V_118 , V_183 , V_189 ) ;
return V_13 ;
}
static bool F_122 ( struct V_2 * V_3 )
{
return true ;
}
static int F_123 ( struct V_2 * V_3 ,
struct V_192 * V_59 )
{
struct V_90 * V_91 ;
struct V_193 * V_194 ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! V_3 )
return - V_19 ;
if ( F_124 ( V_3 ) )
return 0 ;
V_91 = & V_3 -> V_39 [ 0 ] ;
V_33 = F_34 ( V_91 ) ;
if ( ! V_33 )
return - V_195 ;
V_194 = F_125 ( V_91 ) ;
if ( V_59 -> V_196 & V_197 )
V_194 -> V_198 . V_199 = V_59 -> V_199 ;
if ( V_59 -> V_196 & V_200 ) {
V_194 -> V_198 . V_201 = 0 ;
if ( ( V_59 -> V_202 & V_203 ) ||
( V_59 -> V_202 & V_204 ) )
V_194 -> V_198 . V_201 |=
V_205 ;
if ( V_59 -> V_202 & V_206 )
V_194 -> V_198 . V_201 |=
V_207 ;
if ( V_59 -> V_202 & V_208 )
V_194 -> V_198 . V_201 |=
V_209 ;
if ( V_59 -> V_202 & 0 )
V_194 -> V_198 . V_201 |=
V_210 ;
if ( V_59 -> V_202 & 0 )
V_194 -> V_198 . V_201 |=
V_211 ;
}
if ( V_59 -> V_196 & V_212 )
V_194 -> V_198 . V_213 = V_59 -> V_213 ;
if ( V_59 -> V_196 & V_214 ) {
if ( V_59 -> V_215 & V_216 )
V_194 -> V_217 . V_199 = true ;
else
V_194 -> V_217 . V_199 = false ;
if ( V_59 -> V_215 & V_218 )
V_194 -> V_217 . V_219 = true ;
else
V_194 -> V_217 . V_219 = false ;
if ( V_59 -> V_215 & V_220 )
V_194 -> V_217 . V_221 = true ;
else
V_194 -> V_217 . V_221 = false ;
}
if ( V_59 -> V_196 & V_222 ) {
switch ( V_59 -> V_223 ) {
case V_224 :
V_194 -> V_223 = V_225 ;
break;
case V_226 :
V_194 -> V_223 = V_227 ;
break;
case V_228 :
V_194 -> V_223 = V_229 ;
break;
case V_230 :
V_194 -> V_223 = V_231 ;
break;
default:
V_194 -> V_223 = V_232 ;
break;
}
}
V_13 = F_126 ( V_91 , V_33 , V_59 -> V_233 ) ;
F_38 ( V_91 , V_33 ) ;
return V_13 ;
}
static int F_127 ( T_8 V_234 )
{
int V_235 ;
switch ( V_234 ) {
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
V_235 = V_241 ;
break;
case V_242 :
V_235 = V_243 ;
break;
case V_244 :
V_235 = V_245 ;
break;
case V_246 :
V_235 = V_247 ;
break;
case V_248 :
default:
V_235 = V_249 ;
break;
}
return V_235 ;
}
static int F_128 ( struct V_90 * V_91 ,
struct V_193 * V_59 ,
struct V_250 * V_251 ,
struct V_252 * V_253 )
{
void * V_254 ;
if ( ! F_18 ( V_91 -> V_3 ) ) {
F_129 ( V_91 , V_59 ) ;
F_130 ( V_91 , V_251 ) ;
F_131 ( V_91 , V_253 ) ;
return 0 ;
}
V_254 = F_125 ( V_91 ) ;
if ( ! V_254 )
return - V_255 ;
memcpy ( V_59 , V_254 , sizeof( * V_59 ) ) ;
V_254 = F_132 ( V_91 ) ;
if ( ! V_254 )
return - V_255 ;
memcpy ( V_251 , V_254 , sizeof( * V_251 ) ) ;
V_254 = F_133 ( V_91 ) ;
if ( ! V_254 )
return - V_255 ;
memcpy ( V_253 , V_254 , sizeof( * V_253 ) ) ;
return 0 ;
}
static void F_134 ( struct V_90 * V_91 ,
struct V_256 * V_257 )
{
struct V_193 V_59 ;
struct V_250 V_251 ;
struct V_252 V_253 ;
T_8 V_234 ;
memset ( V_257 , 0 , sizeof( * V_257 ) ) ;
if ( F_128 ( V_91 , & V_59 , & V_251 , & V_253 ) ) {
F_135 ( & V_91 -> V_3 -> V_6 -> V_5 , L_42 ) ;
return;
}
if ( V_251 . V_233 )
V_257 -> V_233 = true ;
V_257 -> V_258 = V_259 ;
if ( V_59 . V_198 . V_199 )
V_257 -> V_258 |= V_260 ;
if ( V_59 . V_217 . V_199 ||
( V_59 . V_217 . V_219 && V_59 . V_217 . V_221 ) )
V_257 -> V_258 |= V_261 ;
if ( V_59 . V_217 . V_199 || V_59 . V_217 . V_219 ||
V_59 . V_217 . V_221 )
V_257 -> V_258 |= V_262 ;
V_257 -> V_263 = V_257 -> V_258 ;
if ( V_59 . V_198 . V_201 &
V_205 )
V_257 -> V_263 |= V_203 |
V_204 ;
if ( V_59 . V_198 . V_201 &
V_207 )
V_257 -> V_263 |= V_206 ;
if ( V_59 . V_198 . V_201 &
V_209 )
V_257 -> V_263 |= V_208 ;
if ( V_59 . V_198 . V_201 &
V_210 )
V_257 -> V_263 |= 0 ;
if ( V_59 . V_198 . V_201 &
V_211 )
V_257 -> V_263 |= 0 ;
if ( V_253 . V_264 &
V_205 )
V_257 -> V_258 |= V_203 |
V_204 ;
if ( V_253 . V_264 &
V_207 )
V_257 -> V_258 |= V_206 ;
if ( V_253 . V_264 &
V_209 )
V_257 -> V_258 |= V_208 ;
if ( V_253 . V_264 &
V_210 )
V_257 -> V_258 |= 0 ;
if ( V_253 . V_264 &
V_211 )
V_257 -> V_258 |= 0 ;
if ( V_251 . V_233 )
V_257 -> V_198 = V_251 . V_198 ;
V_257 -> V_265 = V_266 ;
F_136 ( V_91 -> V_3 , & V_234 ) ;
V_257 -> V_267 = F_127 ( V_234 ) ;
V_257 -> V_199 = V_59 . V_198 . V_199 ;
if ( V_59 . V_217 . V_199 )
V_257 -> V_215 |= V_216 ;
if ( V_59 . V_217 . V_219 )
V_257 -> V_215 |= V_218 ;
if ( V_59 . V_217 . V_221 )
V_257 -> V_215 |= V_220 ;
if ( V_251 . V_268 &
V_269 )
V_257 -> V_270 |= V_203 ;
if ( V_251 . V_268 &
V_271 )
V_257 -> V_270 |= V_204 ;
if ( V_251 . V_268 &
V_272 )
V_257 -> V_270 |= V_206 ;
if ( V_251 . V_268 &
V_273 )
V_257 -> V_270 |= V_208 ;
if ( V_251 . V_268 &
V_274 )
V_257 -> V_270 |= 0 ;
if ( V_251 . V_268 &
V_275 )
V_257 -> V_270 |= 0 ;
if ( V_251 . V_276 )
V_257 -> V_270 |= V_260 ;
if ( V_251 . V_277 )
V_257 -> V_270 |= V_262 ;
if ( V_251 . V_277 == V_278 ||
V_251 . V_277 == V_279 )
V_257 -> V_270 |= V_261 ;
}
static void F_137 ( struct V_2 * V_3 ,
struct V_256 * V_257 )
{
int V_75 ;
F_134 ( & V_3 -> V_39 [ 0 ] , V_257 ) ;
F_75 (cdev, i)
F_138 ( & V_3 -> V_39 [ V_75 ] ) ;
}
void F_139 ( struct V_90 * V_91 )
{
void * V_280 = V_91 -> V_3 -> V_281 ;
struct V_282 * V_283 = V_91 -> V_3 -> V_284 . V_285 ;
struct V_256 V_257 ;
F_134 ( V_91 , & V_257 ) ;
F_138 ( V_91 ) ;
if ( F_140 ( V_91 ) && V_280 )
V_283 -> V_286 ( V_280 , & V_257 ) ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_90 * V_91 ;
struct V_32 * V_33 ;
int V_75 , V_13 ;
if ( F_124 ( V_3 ) )
return 0 ;
F_75 (cdev, i) {
V_91 = & V_3 -> V_39 [ V_75 ] ;
V_33 = F_34 ( V_91 ) ;
if ( ! V_33 ) {
F_9 ( V_91 , L_43 ) ;
return - V_195 ;
}
V_13 = F_142 ( V_91 , V_33 ) ;
if ( V_13 )
return V_13 ;
F_38 ( V_91 , V_33 ) ;
}
return 0 ;
}
static int F_143 ( struct V_2 * V_3 , enum V_287 V_288 )
{
struct V_90 * V_91 = F_35 ( V_3 ) ;
struct V_32 * V_33 ;
int V_101 = 0 ;
V_33 = F_34 ( V_91 ) ;
if ( ! V_33 )
return - V_289 ;
V_101 = F_144 ( V_91 , V_33 , V_288 ) ;
F_38 ( V_91 , V_33 ) ;
return V_101 ;
}
