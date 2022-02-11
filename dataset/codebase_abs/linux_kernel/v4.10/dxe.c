void * F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_3 ?
& V_2 -> V_6 :
& V_2 -> V_7 ;
return V_5 -> V_8 -> V_9 ;
}
static void F_2 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
F_3 ( V_12 ,
L_1 ,
V_10 , V_11 ) ;
F_4 ( V_11 , V_2 -> V_13 + V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
F_3 ( V_12 ,
L_2 ,
V_10 , V_11 ) ;
F_4 ( V_11 , V_2 -> V_14 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_10 , int * V_11 )
{
* V_11 = F_7 ( V_2 -> V_14 + V_10 ) ;
F_3 ( V_12 ,
L_3 ,
V_10 , * V_11 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_8 , * V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_19 && V_16 ; V_18 ++ ) {
V_17 = V_16 -> V_17 ;
F_9 ( V_16 ) ;
V_16 = V_17 ;
}
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_15 * V_20 = NULL ;
struct V_15 * V_21 = NULL ;
int V_18 ;
F_11 ( & V_5 -> V_22 ) ;
for ( V_18 = 0 ; V_18 < V_5 -> V_19 ; V_18 ++ ) {
V_21 = F_12 ( sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
goto V_24;
F_11 ( & V_21 -> V_25 ) ;
V_21 -> V_26 = V_18 ;
if ( V_18 == 0 ) {
V_5 -> V_8 = V_21 ;
V_5 -> V_27 = V_21 ;
} else if ( V_5 -> V_19 - 1 == V_18 ) {
V_20 -> V_17 = V_21 ;
V_21 -> V_17 = V_5 -> V_8 ;
} else {
V_20 -> V_17 = V_21 ;
}
V_20 = V_21 ;
}
return 0 ;
V_24:
F_8 ( V_5 ) ;
return - V_28 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_29 ;
V_2 -> V_6 . V_30 = V_31 ;
V_2 -> V_7 . V_30 = V_32 ;
V_2 -> V_33 . V_30 = V_34 ;
V_2 -> V_35 . V_30 = V_36 ;
V_2 -> V_6 . V_19 = V_37 ;
V_2 -> V_7 . V_19 = V_38 ;
V_2 -> V_33 . V_19 = V_39 ;
V_2 -> V_35 . V_19 = V_40 ;
V_2 -> V_6 . V_41 = V_42 ;
V_2 -> V_7 . V_41 = V_43 ;
V_2 -> V_6 . V_44 = V_45 ;
V_2 -> V_7 . V_44 = V_46 ;
V_2 -> V_6 . V_47 = V_48 ;
V_2 -> V_7 . V_47 = V_49 ;
V_2 -> V_6 . V_50 = V_51 ;
V_2 -> V_7 . V_50 = V_52 ;
V_2 -> V_6 . V_53 = V_54 ;
V_2 -> V_7 . V_53 = V_55 ;
V_29 = F_10 ( & V_2 -> V_6 ) ;
if ( V_29 )
goto V_56;
V_29 = F_10 ( & V_2 -> V_7 ) ;
if ( V_29 )
goto V_56;
V_29 = F_10 ( & V_2 -> V_33 ) ;
if ( V_29 )
goto V_56;
V_29 = F_10 ( & V_2 -> V_35 ) ;
if ( V_29 )
goto V_56;
V_29 = V_2 -> V_57 -> V_58 (
V_59 ,
V_60 ) ;
return 0 ;
V_56:
F_14 ( L_4 ) ;
F_15 ( V_2 ) ;
return - V_28 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_6 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_35 ) ;
}
static int F_16 ( struct V_61 * V_62 , struct V_4 * V_63 )
{
struct V_64 * V_65 = NULL ;
struct V_64 * V_66 = NULL ;
struct V_15 * V_21 = NULL ;
T_1 V_67 ;
int V_18 ;
V_67 = V_63 -> V_19 * sizeof( struct V_64 ) ;
V_63 -> V_68 = F_17 ( V_62 , V_67 , & V_63 -> V_69 ,
V_23 ) ;
if ( ! V_63 -> V_68 )
return - V_28 ;
memset ( V_63 -> V_68 , 0 , V_67 ) ;
V_65 = (struct V_64 * ) V_63 -> V_68 ;
V_21 = V_63 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_63 -> V_19 ; V_18 ++ ) {
V_21 -> V_70 = V_65 ;
V_21 -> V_71 = V_63 -> V_69 +
V_18 * sizeof( struct V_64 ) ;
switch ( V_63 -> V_30 ) {
case V_31 :
V_65 -> V_72 = V_73 ;
V_65 -> V_74 = V_42 ;
break;
case V_32 :
V_65 -> V_72 = V_75 ;
V_65 -> V_74 = V_43 ;
break;
case V_34 :
V_65 -> V_72 = V_76 ;
V_65 -> V_77 = V_78 ;
break;
case V_36 :
V_65 -> V_72 = V_79 ;
V_65 -> V_77 = V_80 ;
break;
}
if ( 0 == V_18 ) {
V_65 -> V_81 = 0 ;
} else if ( ( 0 < V_18 ) && ( V_18 < V_63 -> V_19 - 1 ) ) {
V_66 -> V_81 =
V_21 -> V_71 ;
} else if ( V_18 == ( V_63 -> V_19 - 1 ) ) {
V_66 -> V_81 =
V_21 -> V_71 ;
V_65 -> V_81 =
V_63 -> V_8 -> V_71 ;
}
V_21 = V_21 -> V_17 ;
V_66 = V_65 ;
V_65 ++ ;
}
return 0 ;
}
static void F_18 ( struct V_4 * V_5 ,
struct V_82 * V_83 )
{
int V_18 , V_84 = V_83 -> V_84 ;
T_2 V_85 = V_83 -> V_86 ;
void * V_9 = V_83 -> V_87 ;
struct V_15 * V_88 = V_5 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_19 ; V_18 ++ ) {
if ( ! ( V_18 & 1 ) ) {
V_88 -> V_85 = V_85 ;
V_88 -> V_9 = V_9 ;
V_85 += V_84 ;
V_9 += V_84 ;
} else {
V_88 -> V_85 = 0 ;
V_88 -> V_9 = NULL ;
}
V_88 = V_88 -> V_17 ;
}
}
static int F_19 ( struct V_1 * V_2 , T_3 V_63 )
{
int V_89 = 0 ;
F_6 ( V_2 ,
V_90 ,
& V_89 ) ;
V_89 |= V_63 ;
F_5 ( V_2 ,
V_90 ,
( int ) V_89 ) ;
return 0 ;
}
static int F_20 ( struct V_61 * V_62 , struct V_15 * V_16 )
{
struct V_64 * V_91 = V_16 -> V_70 ;
struct V_92 * V_93 ;
V_93 = F_21 ( V_94 , V_95 ) ;
if ( V_93 == NULL )
return - V_28 ;
V_91 -> V_74 = F_22 ( V_62 ,
F_23 ( V_93 ) ,
V_94 ,
V_96 ) ;
V_16 -> V_93 = V_93 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_4 * V_63 )
{
int V_18 ;
struct V_15 * V_21 = NULL ;
V_21 = V_63 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_63 -> V_19 ; V_18 ++ ) {
F_20 ( V_2 -> V_62 , V_21 ) ;
V_21 = V_21 -> V_17 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_4 * V_63 )
{
struct V_15 * V_88 = V_63 -> V_8 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_63 -> V_19 ; V_18 ++ ) {
F_26 ( V_88 -> V_93 ) ;
V_88 = V_88 -> V_17 ;
}
}
void F_27 ( struct V_1 * V_2 , T_4 V_97 )
{
struct V_98 * V_99 ;
struct V_92 * V_93 ;
unsigned long V_100 ;
F_28 ( & V_2 -> V_101 , V_100 ) ;
V_93 = V_2 -> V_102 ;
V_2 -> V_102 = NULL ;
F_29 ( & V_2 -> V_101 , V_100 ) ;
if ( ! V_93 ) {
F_30 ( L_5 ) ;
return;
}
V_99 = F_31 ( V_93 ) ;
if ( V_97 == 1 )
V_99 -> V_100 |= V_103 ;
F_3 ( V_12 , L_6 , V_97 ) ;
F_32 ( V_2 -> V_104 , V_93 ) ;
F_33 ( V_2 -> V_104 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_15 * V_16 ;
struct V_98 * V_99 ;
unsigned long V_100 ;
F_28 ( & V_5 -> V_22 , V_100 ) ;
V_16 = V_5 -> V_27 ;
do {
if ( V_16 -> V_70 -> V_72 & V_105 )
break;
if ( V_16 -> V_93 ) {
F_35 ( V_2 -> V_62 , V_16 -> V_70 -> V_77 ,
V_16 -> V_93 -> V_106 , V_107 ) ;
V_99 = F_31 ( V_16 -> V_93 ) ;
if ( ! ( V_99 -> V_100 & V_108 ) ) {
F_36 ( V_2 -> V_104 , V_16 -> V_93 ) ;
}
F_37 ( & V_16 -> V_25 ) ;
if ( V_2 -> V_109 ) {
V_2 -> V_109 = false ;
F_33 ( V_2 -> V_104 ) ;
}
F_38 ( & V_16 -> V_25 ) ;
V_16 -> V_93 = NULL ;
}
V_16 = V_16 -> V_17 ;
} while ( V_16 != V_5 -> V_8 &&
! ( V_16 -> V_70 -> V_72 & V_105 ) );
V_5 -> V_27 = V_16 ;
F_29 ( & V_5 -> V_22 , V_100 ) ;
}
static T_5 F_39 ( int V_110 , void * V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
int V_111 , V_112 ;
F_6 ( V_2 , V_113 , & V_111 ) ;
if ( V_111 & V_114 ) {
F_6 ( V_2 ,
V_115 ,
& V_112 ) ;
F_5 ( V_2 ,
V_116 ,
V_114 ) ;
F_5 ( V_2 , V_117 ,
V_114 ) ;
F_3 ( V_12 , L_7 ) ;
F_34 ( V_2 , & V_2 -> V_7 ) ;
}
if ( V_111 & V_118 ) {
F_6 ( V_2 ,
V_119 ,
& V_112 ) ;
F_5 ( V_2 ,
V_116 ,
V_118 ) ;
F_5 ( V_2 , V_117 ,
V_118 ) ;
F_3 ( V_12 , L_8 ) ;
F_34 ( V_2 , & V_2 -> V_6 ) ;
}
return V_120 ;
}
static T_5 F_40 ( int V_110 , void * V_62 )
{
struct V_1 * V_2 = (struct V_1 * ) V_62 ;
F_41 ( V_2 -> V_121 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 -> V_121 ) ;
return V_120 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_45 ( V_2 -> V_122 , F_39 ,
V_123 , L_9 , V_2 ) ;
if ( V_29 ) {
F_14 ( L_10 ) ;
goto V_56;
}
V_29 = F_45 ( V_2 -> V_121 , F_40 , V_123 ,
L_11 , V_2 ) ;
if ( V_29 ) {
F_14 ( L_12 ) ;
goto V_124;
}
F_46 ( V_2 -> V_121 ) ;
return 0 ;
V_124:
F_47 ( V_2 -> V_122 , V_2 ) ;
V_56:
return V_29 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_8 ;
struct V_64 * V_91 = V_16 -> V_70 ;
T_2 V_69 ;
struct V_92 * V_93 ;
int V_29 = 0 , V_125 ;
T_4 V_126 ;
if ( V_5 -> V_30 == V_34 ) {
V_126 = V_76 ;
V_125 = V_127 ;
} else {
V_126 = V_79 ;
V_125 = V_128 ;
}
while ( ! ( V_91 -> V_72 & V_105 ) ) {
V_93 = V_16 -> V_93 ;
V_69 = V_91 -> V_74 ;
V_29 = F_20 ( V_2 -> V_62 , V_16 ) ;
if ( 0 == V_29 ) {
F_35 ( V_2 -> V_62 , V_69 , V_94 ,
V_96 ) ;
F_49 ( V_2 , V_93 ) ;
}
V_91 -> V_72 = V_126 ;
V_16 = V_16 -> V_17 ;
V_91 = V_16 -> V_70 ;
}
F_5 ( V_2 , V_129 , V_125 ) ;
V_5 -> V_8 = V_16 ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_111 ;
F_6 ( V_2 , V_113 , & V_111 ) ;
if ( V_111 & V_127 ) {
F_5 ( V_2 , V_116 ,
V_127 ) ;
F_48 ( V_2 , & ( V_2 -> V_33 ) ) ;
}
if ( V_111 & V_128 ) {
F_5 ( V_2 , V_116 ,
V_128 ) ;
F_48 ( V_2 , & ( V_2 -> V_35 ) ) ;
}
if ( ! V_111 )
F_30 ( L_13 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
T_1 V_130 ;
void * V_68 ;
V_2 -> V_131 . V_84 = V_132 +
16 - ( V_132 % 8 ) ;
V_130 = V_2 -> V_131 . V_84 * V_38 ;
V_68 = F_17 ( V_2 -> V_62 , V_130 , & V_2 -> V_131 . V_86 ,
V_23 ) ;
if ( ! V_68 )
goto V_56;
V_2 -> V_131 . V_87 = V_68 ;
memset ( V_68 , 0 , V_130 ) ;
V_2 -> V_133 . V_84 = V_132 +
16 - ( V_132 % 8 ) ;
V_130 = V_2 -> V_133 . V_84 * V_37 ;
V_68 = F_17 ( V_2 -> V_62 , V_130 , & V_2 -> V_133 . V_86 ,
V_23 ) ;
if ( ! V_68 )
goto V_56;
V_2 -> V_133 . V_87 = V_68 ;
memset ( V_68 , 0 , V_130 ) ;
return 0 ;
V_56:
F_51 ( V_2 ) ;
F_14 ( L_14 ) ;
return - V_28 ;
}
void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 . V_87 )
F_52 ( V_2 -> V_62 , V_2 -> V_131 . V_84 *
V_38 ,
V_2 -> V_131 . V_87 ,
V_2 -> V_131 . V_86 ) ;
if ( V_2 -> V_133 . V_87 ) {
F_52 ( V_2 -> V_62 , V_2 -> V_133 . V_84 *
V_37 ,
V_2 -> V_133 . V_87 ,
V_2 -> V_133 . V_86 ) ;
}
}
int F_53 ( struct V_1 * V_2 ,
struct V_134 * V_135 ,
struct V_92 * V_93 ,
bool V_3 )
{
struct V_15 * V_16 = NULL ;
struct V_64 * V_70 = NULL ;
struct V_4 * V_5 = NULL ;
unsigned long V_100 ;
int V_29 ;
V_5 = V_3 ? & V_2 -> V_6 : & V_2 -> V_7 ;
F_28 ( & V_5 -> V_22 , V_100 ) ;
V_16 = V_5 -> V_8 ;
F_37 ( & V_16 -> V_17 -> V_25 ) ;
if ( NULL != V_16 -> V_17 -> V_93 ) {
F_54 ( V_2 -> V_104 ) ;
V_2 -> V_109 = true ;
F_38 ( & V_16 -> V_17 -> V_25 ) ;
F_29 ( & V_5 -> V_22 , V_100 ) ;
return - V_136 ;
}
F_38 ( & V_16 -> V_17 -> V_25 ) ;
V_16 -> V_93 = NULL ;
V_70 = V_16 -> V_70 ;
V_70 -> V_77 = V_16 -> V_85 ;
V_70 -> V_74 = V_5 -> V_41 ;
V_70 -> V_137 = sizeof( struct V_138 ) ;
V_70 -> V_72 = V_5 -> V_44 ;
F_3 ( V_12 , L_15 ) ;
F_55 ( V_139 , L_16 ,
( char * ) V_70 , sizeof( * V_70 ) ) ;
F_55 ( V_139 ,
L_17 , ( char * ) V_16 -> V_9 ,
sizeof( struct V_138 ) ) ;
V_16 = V_16 -> V_17 ;
V_16 -> V_93 = V_93 ;
V_70 = V_16 -> V_70 ;
if ( V_16 -> V_9 ) {
F_14 ( L_18 ) ;
V_29 = - V_140 ;
goto V_141;
}
V_70 -> V_77 = F_22 ( V_2 -> V_62 ,
V_16 -> V_93 -> V_11 ,
V_16 -> V_93 -> V_106 ,
V_107 ) ;
V_70 -> V_74 = V_5 -> V_41 ;
V_70 -> V_137 = V_16 -> V_93 -> V_106 ;
V_70 -> V_72 = V_5 -> V_47 ;
F_55 ( V_139 , L_19 ,
( char * ) V_70 , sizeof( * V_70 ) ) ;
F_55 ( V_139 , L_20 ,
( char * ) V_16 -> V_93 -> V_11 , V_16 -> V_93 -> V_106 ) ;
V_5 -> V_8 = V_16 -> V_17 ;
if ( V_3 && V_135 -> V_142 == V_143 ) {
V_2 -> V_57 -> V_58 (
0 ,
V_59 ) ;
} else {
F_5 ( V_2 ,
V_5 -> V_50 , V_5 -> V_53 ) ;
}
V_29 = 0 ;
V_141:
F_29 ( & V_5 -> V_22 , V_100 ) ;
return V_29 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_89 = 0 , V_29 ;
V_89 = V_144 ;
F_5 ( V_2 , V_145 , V_89 ) ;
V_89 = ( V_128 | V_127 ) << 16 |
V_146 | V_147 ;
if ( V_2 -> V_148 )
F_2 ( V_2 , V_149 , V_89 ) ;
else
F_2 ( V_2 , V_150 , V_89 ) ;
F_16 ( V_2 -> V_62 , & V_2 -> V_6 ) ;
F_18 ( & V_2 -> V_6 , & V_2 -> V_133 ) ;
F_5 ( V_2 , V_151 ,
V_2 -> V_6 . V_8 -> V_71 ) ;
F_5 ( V_2 ,
V_152 ,
V_42 ) ;
F_6 ( V_2 , V_153 , & V_89 ) ;
F_19 ( V_2 , V_118 ) ;
F_16 ( V_2 -> V_62 , & V_2 -> V_7 ) ;
F_18 ( & V_2 -> V_7 , & V_2 -> V_131 ) ;
F_5 ( V_2 , V_154 ,
V_2 -> V_7 . V_8 -> V_71 ) ;
F_5 ( V_2 ,
V_155 ,
V_43 ) ;
F_6 ( V_2 , V_153 , & V_89 ) ;
F_19 ( V_2 , V_114 ) ;
F_16 ( V_2 -> V_62 , & V_2 -> V_33 ) ;
F_24 ( V_2 , & V_2 -> V_33 ) ;
F_5 ( V_2 , V_156 ,
V_2 -> V_33 . V_8 -> V_71 ) ;
F_5 ( V_2 ,
V_157 ,
V_78 ) ;
F_5 ( V_2 ,
V_158 ,
V_2 -> V_33 . V_8 -> V_70 -> V_81 ) ;
F_5 ( V_2 ,
V_159 ,
V_160 ) ;
F_19 ( V_2 , V_161 ) ;
F_16 ( V_2 -> V_62 , & V_2 -> V_35 ) ;
F_24 ( V_2 , & V_2 -> V_35 ) ;
F_5 ( V_2 , V_162 ,
V_2 -> V_35 . V_8 -> V_71 ) ;
F_5 ( V_2 ,
V_163 ,
V_80 ) ;
F_5 ( V_2 ,
V_164 ,
V_2 -> V_35 . V_8 -> V_70 -> V_81 ) ;
F_5 ( V_2 ,
V_165 ,
V_166 ) ;
F_19 ( V_2 , V_167 ) ;
V_29 = F_44 ( V_2 ) ;
if ( V_29 < 0 )
goto V_56;
return 0 ;
V_56:
return V_29 ;
}
void F_57 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_122 , V_2 ) ;
F_47 ( V_2 -> V_121 , V_2 ) ;
if ( V_2 -> V_102 ) {
F_32 ( V_2 -> V_104 , V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
}
F_25 ( V_2 , & V_2 -> V_33 ) ;
F_25 ( V_2 , & V_2 -> V_35 ) ;
}
