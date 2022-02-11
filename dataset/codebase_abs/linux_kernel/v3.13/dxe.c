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
static void F_5 ( struct V_1 * V_2 , int V_10 , int * V_11 )
{
* V_11 = F_6 ( V_2 -> V_13 + V_10 ) ;
F_3 ( V_12 ,
L_2 ,
V_10 , * V_11 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_8 , * V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 && V_15 ; V_17 ++ ) {
V_16 = V_15 -> V_16 ;
F_8 ( V_15 ) ;
V_15 = V_16 ;
}
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_14 * V_19 = NULL ;
struct V_14 * V_20 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 ; V_17 ++ ) {
V_20 = F_10 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
goto V_22;
V_20 -> V_23 = V_17 ;
if ( V_17 == 0 ) {
V_5 -> V_8 = V_20 ;
V_5 -> V_24 = V_20 ;
} else if ( V_5 -> V_18 - 1 == V_17 ) {
V_19 -> V_16 = V_20 ;
V_20 -> V_16 = V_5 -> V_8 ;
} else {
V_19 -> V_16 = V_20 ;
}
V_19 = V_20 ;
}
return 0 ;
V_22:
F_7 ( V_5 ) ;
return - V_25 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_26 ;
V_2 -> V_6 . V_27 = V_28 ;
V_2 -> V_7 . V_27 = V_29 ;
V_2 -> V_30 . V_27 = V_31 ;
V_2 -> V_32 . V_27 = V_33 ;
V_2 -> V_6 . V_18 = V_34 ;
V_2 -> V_7 . V_18 = V_35 ;
V_2 -> V_30 . V_18 = V_36 ;
V_2 -> V_32 . V_18 = V_37 ;
V_2 -> V_6 . V_38 = V_39 ;
V_2 -> V_7 . V_38 = V_40 ;
V_2 -> V_6 . V_41 = V_42 ;
V_2 -> V_7 . V_41 = V_43 ;
V_2 -> V_6 . V_44 = V_45 ;
V_2 -> V_7 . V_44 = V_46 ;
V_2 -> V_6 . V_47 = V_48 ;
V_2 -> V_7 . V_47 = V_49 ;
V_2 -> V_6 . V_50 = V_51 ;
V_2 -> V_7 . V_50 = V_52 ;
V_26 = F_9 ( & V_2 -> V_6 ) ;
if ( V_26 )
goto V_53;
V_26 = F_9 ( & V_2 -> V_7 ) ;
if ( V_26 )
goto V_53;
V_26 = F_9 ( & V_2 -> V_30 ) ;
if ( V_26 )
goto V_53;
V_26 = F_9 ( & V_2 -> V_32 ) ;
if ( V_26 )
goto V_53;
V_26 = V_2 -> V_54 -> V_55 (
V_56 ,
V_57 ) ;
return 0 ;
V_53:
F_12 ( L_3 ) ;
F_13 ( V_2 ) ;
return - V_25 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_6 ) ;
F_7 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_30 ) ;
F_7 ( & V_2 -> V_32 ) ;
}
static int F_14 ( struct V_4 * V_58 )
{
struct V_59 * V_60 = NULL ;
struct V_59 * V_61 = NULL ;
struct V_14 * V_20 = NULL ;
T_1 V_62 ;
int V_17 ;
V_62 = V_58 -> V_18 * sizeof( struct V_59 ) ;
V_58 -> V_63 = F_15 ( NULL , V_62 , & V_58 -> V_64 ,
V_21 ) ;
if ( ! V_58 -> V_63 )
return - V_25 ;
memset ( V_58 -> V_63 , 0 , V_62 ) ;
V_60 = (struct V_59 * ) V_58 -> V_63 ;
V_20 = V_58 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_58 -> V_18 ; V_17 ++ ) {
V_20 -> V_65 = V_60 ;
V_20 -> V_66 = V_58 -> V_64 +
V_17 * sizeof( struct V_59 ) ;
switch ( V_58 -> V_27 ) {
case V_28 :
V_60 -> V_67 = V_68 ;
V_60 -> V_69 = V_39 ;
break;
case V_29 :
V_60 -> V_67 = V_70 ;
V_60 -> V_69 = V_40 ;
break;
case V_31 :
V_60 -> V_67 = V_71 ;
V_60 -> V_72 = V_73 ;
break;
case V_33 :
V_60 -> V_67 = V_74 ;
V_60 -> V_72 = V_75 ;
break;
}
if ( 0 == V_17 ) {
V_60 -> V_76 = 0 ;
} else if ( ( 0 < V_17 ) && ( V_17 < V_58 -> V_18 - 1 ) ) {
V_61 -> V_76 =
V_20 -> V_66 ;
} else if ( V_17 == ( V_58 -> V_18 - 1 ) ) {
V_61 -> V_76 =
V_20 -> V_66 ;
V_60 -> V_76 =
V_58 -> V_8 -> V_66 ;
}
V_20 = V_20 -> V_16 ;
V_61 = V_60 ;
V_60 ++ ;
}
return 0 ;
}
static void F_16 ( struct V_4 * V_5 ,
struct V_77 * V_78 )
{
int V_17 , V_79 = V_78 -> V_79 ;
T_2 V_80 = V_78 -> V_81 ;
void * V_9 = V_78 -> V_82 ;
struct V_14 * V_83 = V_5 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 ; V_17 ++ ) {
if ( ! ( V_17 & 1 ) ) {
V_83 -> V_80 = V_80 ;
V_83 -> V_9 = V_9 ;
V_80 += V_79 ;
V_9 += V_79 ;
} else {
V_83 -> V_80 = 0 ;
V_83 -> V_9 = NULL ;
}
V_83 = V_83 -> V_16 ;
}
}
static int F_17 ( struct V_1 * V_2 , T_3 V_58 )
{
int V_84 = 0 ;
F_5 ( V_2 ,
V_85 ,
& V_84 ) ;
V_84 |= V_58 ;
F_2 ( V_2 ,
V_85 ,
( int ) V_84 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_59 * V_86 = V_15 -> V_65 ;
struct V_87 * V_88 ;
V_88 = F_19 ( V_89 , V_90 ) ;
if ( V_88 == NULL )
return - V_25 ;
V_86 -> V_69 = F_20 ( NULL ,
F_21 ( V_88 ) ,
V_89 ,
V_91 ) ;
V_15 -> V_88 = V_88 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_4 * V_58 )
{
int V_17 ;
struct V_14 * V_20 = NULL ;
V_20 = V_58 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_58 -> V_18 ; V_17 ++ ) {
F_18 ( V_20 ) ;
V_20 = V_20 -> V_16 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_4 * V_58 )
{
struct V_14 * V_83 = V_58 -> V_8 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_58 -> V_18 ; V_17 ++ ) {
F_24 ( V_83 -> V_88 ) ;
V_83 = V_83 -> V_16 ;
}
}
void F_25 ( struct V_1 * V_2 , T_4 V_92 )
{
struct V_93 * V_94 ;
struct V_87 * V_88 ;
unsigned long V_95 ;
F_26 ( & V_2 -> V_96 , V_95 ) ;
V_88 = V_2 -> V_97 ;
V_2 -> V_97 = NULL ;
F_27 ( & V_2 -> V_96 , V_95 ) ;
if ( ! V_88 ) {
F_28 ( L_4 ) ;
return;
}
V_94 = F_29 ( V_88 ) ;
if ( V_92 == 1 )
V_94 -> V_95 |= V_98 ;
F_3 ( V_12 , L_5 , V_92 ) ;
F_30 ( V_2 -> V_99 , V_88 ) ;
F_31 ( V_2 -> V_99 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_24 ;
struct V_93 * V_94 ;
unsigned long V_95 ;
do {
if ( V_15 -> V_88 ) {
F_33 ( NULL , V_15 -> V_65 -> V_72 ,
V_15 -> V_88 -> V_100 , V_101 ) ;
V_94 = F_29 ( V_15 -> V_88 ) ;
if ( ! ( V_94 -> V_95 & V_102 ) ) {
F_34 ( V_2 -> V_99 , V_15 -> V_88 ) ;
}
F_26 ( & V_15 -> V_103 , V_95 ) ;
if ( V_2 -> V_104 ) {
V_2 -> V_104 = false ;
F_31 ( V_2 -> V_99 ) ;
}
F_27 ( & V_15 -> V_103 , V_95 ) ;
V_15 -> V_88 = NULL ;
}
V_15 = V_15 -> V_16 ;
} while ( V_15 != V_5 -> V_8 &&
! ( V_15 -> V_65 -> V_67 & V_105 ) );
V_5 -> V_24 = V_15 ;
}
static T_5 F_35 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
int V_108 , V_109 ;
F_5 ( V_2 , V_110 , & V_108 ) ;
if ( V_108 & V_111 ) {
F_5 ( V_2 ,
V_112 ,
& V_109 ) ;
F_2 ( V_2 ,
V_113 ,
V_111 ) ;
F_2 ( V_2 , V_114 ,
V_111 ) ;
F_3 ( V_12 , L_6 ) ;
F_32 ( V_2 , & V_2 -> V_7 ) ;
}
if ( V_108 & V_115 ) {
F_5 ( V_2 ,
V_116 ,
& V_109 ) ;
F_2 ( V_2 ,
V_113 ,
V_115 ) ;
F_2 ( V_2 , V_114 ,
V_115 ) ;
F_3 ( V_12 , L_7 ) ;
F_32 ( V_2 , & V_2 -> V_6 ) ;
}
return V_117 ;
}
static T_5 F_36 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
F_37 ( V_2 -> V_118 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 -> V_118 ) ;
return V_117 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_41 ( V_2 -> V_119 , F_35 ,
V_120 , L_8 , V_2 ) ;
if ( V_26 ) {
F_12 ( L_9 ) ;
goto V_53;
}
V_26 = F_41 ( V_2 -> V_118 , F_36 , V_120 ,
L_10 , V_2 ) ;
if ( V_26 ) {
F_12 ( L_11 ) ;
goto V_121;
}
F_42 ( V_2 -> V_118 ) ;
return 0 ;
V_121:
F_43 ( V_2 -> V_119 , V_2 ) ;
V_53:
return V_26 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_8 ;
struct V_59 * V_86 = V_15 -> V_65 ;
T_2 V_64 ;
struct V_87 * V_88 ;
while ( ! ( V_86 -> V_67 & V_105 ) ) {
V_88 = V_15 -> V_88 ;
V_64 = V_86 -> V_69 ;
F_18 ( V_15 ) ;
switch ( V_5 -> V_27 ) {
case V_31 :
V_86 -> V_67 = V_71 ;
F_2 ( V_2 , V_122 ,
V_123 ) ;
break;
case V_33 :
V_86 -> V_67 = V_74 ;
F_2 ( V_2 , V_122 ,
V_124 ) ;
break;
default:
F_28 ( L_12 ) ;
}
F_33 ( NULL , V_64 , V_89 ,
V_91 ) ;
F_45 ( V_2 , V_88 ) ;
V_15 = V_15 -> V_16 ;
V_86 = V_15 -> V_65 ;
}
V_5 -> V_8 = V_15 ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
int V_108 ;
F_5 ( V_2 , V_110 , & V_108 ) ;
if ( V_108 & V_123 ) {
F_2 ( V_2 , V_113 ,
V_123 ) ;
F_44 ( V_2 , & ( V_2 -> V_30 ) ) ;
}
if ( V_108 & V_124 ) {
F_2 ( V_2 , V_113 ,
V_124 ) ;
F_44 ( V_2 , & ( V_2 -> V_32 ) ) ;
}
if ( ! V_108 )
F_28 ( L_13 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
T_1 V_125 ;
void * V_63 ;
V_2 -> V_126 . V_79 = V_127 +
16 - ( V_127 % 8 ) ;
V_125 = V_2 -> V_126 . V_79 * V_35 ;
V_63 = F_15 ( NULL , V_125 , & V_2 -> V_126 . V_81 ,
V_21 ) ;
if ( ! V_63 )
goto V_53;
V_2 -> V_126 . V_82 = V_63 ;
memset ( V_63 , 0 , V_125 ) ;
V_2 -> V_128 . V_79 = V_127 +
16 - ( V_127 % 8 ) ;
V_125 = V_2 -> V_128 . V_79 * V_34 ;
V_63 = F_15 ( NULL , V_125 , & V_2 -> V_128 . V_81 ,
V_21 ) ;
if ( ! V_63 )
goto V_53;
V_2 -> V_128 . V_82 = V_63 ;
memset ( V_63 , 0 , V_125 ) ;
return 0 ;
V_53:
F_47 ( V_2 ) ;
F_12 ( L_14 ) ;
return - V_25 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 . V_82 )
F_48 ( NULL , V_2 -> V_126 . V_79 *
V_35 ,
V_2 -> V_126 . V_82 ,
V_2 -> V_126 . V_81 ) ;
if ( V_2 -> V_128 . V_82 ) {
F_48 ( NULL , V_2 -> V_128 . V_79 *
V_34 ,
V_2 -> V_128 . V_82 ,
V_2 -> V_128 . V_81 ) ;
}
}
int F_49 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_87 * V_88 ,
bool V_3 )
{
struct V_14 * V_15 = NULL ;
struct V_59 * V_65 = NULL ;
struct V_4 * V_5 = NULL ;
unsigned long V_95 ;
V_5 = V_3 ? & V_2 -> V_6 : & V_2 -> V_7 ;
V_15 = V_5 -> V_8 ;
F_26 ( & V_15 -> V_16 -> V_103 , V_95 ) ;
if ( NULL != V_15 -> V_16 -> V_88 ) {
F_50 ( V_2 -> V_99 ) ;
V_2 -> V_104 = true ;
F_27 ( & V_15 -> V_16 -> V_103 , V_95 ) ;
return - V_131 ;
}
F_27 ( & V_15 -> V_16 -> V_103 , V_95 ) ;
V_15 -> V_88 = NULL ;
V_65 = V_15 -> V_65 ;
V_65 -> V_72 = V_15 -> V_80 ;
V_65 -> V_69 = V_5 -> V_38 ;
V_65 -> V_132 = sizeof( struct V_133 ) ;
V_65 -> V_67 = V_5 -> V_41 ;
F_3 ( V_12 , L_15 ) ;
F_51 ( V_134 , L_16 ,
( char * ) V_65 , sizeof( * V_65 ) ) ;
F_51 ( V_134 ,
L_17 , ( char * ) V_15 -> V_9 ,
sizeof( struct V_133 ) ) ;
V_15 = V_15 -> V_16 ;
V_15 -> V_88 = V_88 ;
V_65 = V_15 -> V_65 ;
if ( V_15 -> V_9 ) {
F_12 ( L_18 ) ;
return - V_135 ;
}
V_65 -> V_72 = F_20 ( NULL ,
V_15 -> V_88 -> V_11 ,
V_15 -> V_88 -> V_100 ,
V_101 ) ;
V_65 -> V_69 = V_5 -> V_38 ;
V_65 -> V_132 = V_15 -> V_88 -> V_100 ;
V_65 -> V_67 = V_5 -> V_44 ;
F_51 ( V_134 , L_19 ,
( char * ) V_65 , sizeof( * V_65 ) ) ;
F_51 ( V_134 , L_20 ,
( char * ) V_15 -> V_88 -> V_11 , V_15 -> V_88 -> V_100 ) ;
V_5 -> V_8 = V_15 -> V_16 ;
if ( V_3 && V_130 -> V_136 == V_137 ) {
V_2 -> V_54 -> V_55 (
0 ,
V_56 ) ;
} else {
F_2 ( V_2 ,
V_5 -> V_47 , V_5 -> V_50 ) ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_84 = 0 , V_26 ;
V_84 = V_138 ;
F_2 ( V_2 , V_139 , V_84 ) ;
V_84 = V_140 ;
F_2 ( V_2 , V_141 , V_84 ) ;
F_14 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_6 , & V_2 -> V_128 ) ;
F_2 ( V_2 , V_142 ,
V_2 -> V_6 . V_8 -> V_66 ) ;
F_2 ( V_2 ,
V_143 ,
V_39 ) ;
F_5 ( V_2 , V_144 , & V_84 ) ;
F_17 ( V_2 , V_115 ) ;
F_14 ( & V_2 -> V_7 ) ;
F_16 ( & V_2 -> V_7 , & V_2 -> V_126 ) ;
F_2 ( V_2 , V_145 ,
V_2 -> V_7 . V_8 -> V_66 ) ;
F_2 ( V_2 ,
V_146 ,
V_40 ) ;
F_5 ( V_2 , V_144 , & V_84 ) ;
F_17 ( V_2 , V_111 ) ;
F_14 ( & V_2 -> V_30 ) ;
F_22 ( V_2 , & V_2 -> V_30 ) ;
F_2 ( V_2 , V_147 ,
V_2 -> V_30 . V_8 -> V_66 ) ;
F_2 ( V_2 ,
V_148 ,
V_73 ) ;
F_2 ( V_2 ,
V_149 ,
V_2 -> V_30 . V_8 -> V_65 -> V_76 ) ;
F_2 ( V_2 ,
V_150 ,
V_151 ) ;
F_17 ( V_2 , V_152 ) ;
F_14 ( & V_2 -> V_32 ) ;
F_22 ( V_2 , & V_2 -> V_32 ) ;
F_2 ( V_2 , V_153 ,
V_2 -> V_32 . V_8 -> V_66 ) ;
F_2 ( V_2 ,
V_154 ,
V_75 ) ;
F_2 ( V_2 ,
V_155 ,
V_2 -> V_32 . V_8 -> V_65 -> V_76 ) ;
F_2 ( V_2 ,
V_156 ,
V_157 ) ;
F_17 ( V_2 , V_158 ) ;
V_26 = F_40 ( V_2 ) ;
if ( V_26 < 0 )
goto V_53;
return 0 ;
V_53:
return V_26 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_119 , V_2 ) ;
F_43 ( V_2 -> V_118 , V_2 ) ;
if ( V_2 -> V_97 ) {
F_30 ( V_2 -> V_99 , V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
F_23 ( V_2 , & V_2 -> V_30 ) ;
F_23 ( V_2 , & V_2 -> V_32 ) ;
}
