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
static void F_5 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_8 , * V_16 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 && V_15 ; V_17 ++ ) {
V_16 = V_15 -> V_16 ;
F_6 ( V_15 ) ;
V_15 = V_16 ;
}
}
static int F_7 ( struct V_4 * V_5 )
{
struct V_14 * V_19 = NULL ;
struct V_14 * V_20 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 ; V_17 ++ ) {
V_20 = F_8 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
goto V_22;
F_9 ( & V_20 -> V_23 ) ;
V_20 -> V_24 = V_17 ;
if ( V_17 == 0 ) {
V_5 -> V_8 = V_20 ;
V_5 -> V_25 = V_20 ;
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
F_5 ( V_5 ) ;
return - V_26 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_27 ;
V_2 -> V_6 . V_28 = V_29 ;
V_2 -> V_7 . V_28 = V_30 ;
V_2 -> V_31 . V_28 = V_32 ;
V_2 -> V_33 . V_28 = V_34 ;
V_2 -> V_6 . V_18 = V_35 ;
V_2 -> V_7 . V_18 = V_36 ;
V_2 -> V_31 . V_18 = V_37 ;
V_2 -> V_33 . V_18 = V_38 ;
V_2 -> V_6 . V_39 = V_40 ;
V_2 -> V_7 . V_39 = V_41 ;
V_2 -> V_6 . V_42 = V_43 ;
V_2 -> V_7 . V_42 = V_44 ;
V_2 -> V_6 . V_45 = V_46 ;
V_2 -> V_7 . V_45 = V_47 ;
V_2 -> V_6 . V_48 = V_49 ;
V_2 -> V_7 . V_48 = V_50 ;
V_2 -> V_6 . V_51 = V_52 ;
V_2 -> V_7 . V_51 = V_53 ;
V_27 = F_7 ( & V_2 -> V_6 ) ;
if ( V_27 )
goto V_54;
V_27 = F_7 ( & V_2 -> V_7 ) ;
if ( V_27 )
goto V_54;
V_27 = F_7 ( & V_2 -> V_31 ) ;
if ( V_27 )
goto V_54;
V_27 = F_7 ( & V_2 -> V_33 ) ;
if ( V_27 )
goto V_54;
V_27 = V_2 -> V_55 -> V_56 (
V_57 ,
V_58 ) ;
return 0 ;
V_54:
F_11 ( L_2 ) ;
F_12 ( V_2 ) ;
return - V_26 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_31 ) ;
F_5 ( & V_2 -> V_33 ) ;
}
static int F_13 ( struct V_4 * V_59 )
{
struct V_60 * V_61 = NULL ;
struct V_60 * V_62 = NULL ;
struct V_14 * V_20 = NULL ;
T_1 V_63 ;
int V_17 ;
V_63 = V_59 -> V_18 * sizeof( struct V_60 ) ;
V_59 -> V_64 = F_14 ( NULL , V_63 , & V_59 -> V_65 ,
V_21 ) ;
if ( ! V_59 -> V_64 )
return - V_26 ;
memset ( V_59 -> V_64 , 0 , V_63 ) ;
V_61 = (struct V_60 * ) V_59 -> V_64 ;
V_20 = V_59 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_59 -> V_18 ; V_17 ++ ) {
V_20 -> V_66 = V_61 ;
V_20 -> V_67 = V_59 -> V_65 +
V_17 * sizeof( struct V_60 ) ;
switch ( V_59 -> V_28 ) {
case V_29 :
V_61 -> V_68 = V_69 ;
V_61 -> V_70 = V_40 ;
break;
case V_30 :
V_61 -> V_68 = V_71 ;
V_61 -> V_70 = V_41 ;
break;
case V_32 :
V_61 -> V_68 = V_72 ;
V_61 -> V_73 = V_74 ;
break;
case V_34 :
V_61 -> V_68 = V_75 ;
V_61 -> V_73 = V_76 ;
break;
}
if ( 0 == V_17 ) {
V_61 -> V_77 = 0 ;
} else if ( ( 0 < V_17 ) && ( V_17 < V_59 -> V_18 - 1 ) ) {
V_62 -> V_77 =
V_20 -> V_67 ;
} else if ( V_17 == ( V_59 -> V_18 - 1 ) ) {
V_62 -> V_77 =
V_20 -> V_67 ;
V_61 -> V_77 =
V_59 -> V_8 -> V_67 ;
}
V_20 = V_20 -> V_16 ;
V_62 = V_61 ;
V_61 ++ ;
}
return 0 ;
}
static void F_15 ( struct V_4 * V_5 ,
struct V_78 * V_79 )
{
int V_17 , V_80 = V_79 -> V_80 ;
T_2 V_81 = V_79 -> V_82 ;
void * V_9 = V_79 -> V_83 ;
struct V_14 * V_84 = V_5 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_18 ; V_17 ++ ) {
if ( ! ( V_17 & 1 ) ) {
V_84 -> V_81 = V_81 ;
V_84 -> V_9 = V_9 ;
V_81 += V_80 ;
V_9 += V_80 ;
} else {
V_84 -> V_81 = 0 ;
V_84 -> V_9 = NULL ;
}
V_84 = V_84 -> V_16 ;
}
}
static int F_16 ( struct V_1 * V_2 , T_3 V_59 )
{
int V_85 = 0 ;
F_17 ( V_2 ,
V_86 ,
& V_85 ) ;
V_85 |= V_59 ;
F_2 ( V_2 ,
V_86 ,
( int ) V_85 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
struct V_60 * V_87 = V_15 -> V_66 ;
struct V_88 * V_89 ;
V_89 = F_19 ( V_90 , V_91 ) ;
if ( V_89 == NULL )
return - V_26 ;
V_87 -> V_70 = F_20 ( NULL ,
F_21 ( V_89 ) ,
V_90 ,
V_92 ) ;
V_15 -> V_89 = V_89 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_4 * V_59 )
{
int V_17 ;
struct V_14 * V_20 = NULL ;
V_20 = V_59 -> V_8 ;
for ( V_17 = 0 ; V_17 < V_59 -> V_18 ; V_17 ++ ) {
F_18 ( V_20 ) ;
V_20 = V_20 -> V_16 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_4 * V_59 )
{
struct V_14 * V_84 = V_59 -> V_8 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_59 -> V_18 ; V_17 ++ ) {
F_24 ( V_84 -> V_89 ) ;
V_84 = V_84 -> V_16 ;
}
}
void F_25 ( struct V_1 * V_2 , T_4 V_93 )
{
struct V_94 * V_95 ;
struct V_88 * V_89 ;
unsigned long V_96 ;
F_26 ( & V_2 -> V_97 , V_96 ) ;
V_89 = V_2 -> V_98 ;
V_2 -> V_98 = NULL ;
F_27 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_89 ) {
F_28 ( L_3 ) ;
return;
}
V_95 = F_29 ( V_89 ) ;
if ( V_93 == 1 )
V_95 -> V_96 |= V_99 ;
F_3 ( V_12 , L_4 , V_93 ) ;
F_30 ( V_2 -> V_100 , V_89 ) ;
F_31 ( V_2 -> V_100 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_25 ;
struct V_94 * V_95 ;
unsigned long V_96 ;
do {
if ( V_15 -> V_66 -> V_68 & V_101 )
break;
if ( V_15 -> V_89 ) {
F_33 ( NULL , V_15 -> V_66 -> V_73 ,
V_15 -> V_89 -> V_102 , V_103 ) ;
V_95 = F_29 ( V_15 -> V_89 ) ;
if ( ! ( V_95 -> V_96 & V_104 ) ) {
F_34 ( V_2 -> V_100 , V_15 -> V_89 ) ;
}
F_26 ( & V_15 -> V_23 , V_96 ) ;
if ( V_2 -> V_105 ) {
V_2 -> V_105 = false ;
F_31 ( V_2 -> V_100 ) ;
}
F_27 ( & V_15 -> V_23 , V_96 ) ;
V_15 -> V_89 = NULL ;
}
V_15 = V_15 -> V_16 ;
} while ( V_15 != V_5 -> V_8 &&
! ( V_15 -> V_66 -> V_68 & V_101 ) );
V_5 -> V_25 = V_15 ;
}
static T_5 F_35 ( int V_106 , void * V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
int V_108 , V_109 ;
F_17 ( V_2 , V_110 , & V_108 ) ;
if ( V_108 & V_111 ) {
F_17 ( V_2 ,
V_112 ,
& V_109 ) ;
F_2 ( V_2 ,
V_113 ,
V_111 ) ;
F_2 ( V_2 , V_114 ,
V_111 ) ;
F_3 ( V_12 , L_5 ) ;
F_32 ( V_2 , & V_2 -> V_7 ) ;
}
if ( V_108 & V_115 ) {
F_17 ( V_2 ,
V_116 ,
& V_109 ) ;
F_2 ( V_2 ,
V_113 ,
V_115 ) ;
F_2 ( V_2 , V_114 ,
V_115 ) ;
F_3 ( V_12 , L_6 ) ;
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
int V_27 ;
V_27 = F_41 ( V_2 -> V_119 , F_35 ,
V_120 , L_7 , V_2 ) ;
if ( V_27 ) {
F_11 ( L_8 ) ;
goto V_54;
}
V_27 = F_41 ( V_2 -> V_118 , F_36 , V_120 ,
L_9 , V_2 ) ;
if ( V_27 ) {
F_11 ( L_10 ) ;
goto V_121;
}
F_42 ( V_2 -> V_118 ) ;
return 0 ;
V_121:
F_43 ( V_2 -> V_119 , V_2 ) ;
V_54:
return V_27 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_8 ;
struct V_60 * V_87 = V_15 -> V_66 ;
T_2 V_65 ;
struct V_88 * V_89 ;
while ( ! ( V_87 -> V_68 & V_101 ) ) {
V_89 = V_15 -> V_89 ;
V_65 = V_87 -> V_70 ;
F_18 ( V_15 ) ;
switch ( V_5 -> V_28 ) {
case V_32 :
V_87 -> V_68 = V_72 ;
F_2 ( V_2 , V_122 ,
V_123 ) ;
break;
case V_34 :
V_87 -> V_68 = V_75 ;
F_2 ( V_2 , V_122 ,
V_124 ) ;
break;
default:
F_28 ( L_11 ) ;
}
F_33 ( NULL , V_65 , V_90 ,
V_92 ) ;
F_45 ( V_2 , V_89 ) ;
V_15 = V_15 -> V_16 ;
V_87 = V_15 -> V_66 ;
}
V_5 -> V_8 = V_15 ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
int V_108 ;
F_17 ( V_2 , V_110 , & V_108 ) ;
if ( V_108 & V_123 ) {
F_2 ( V_2 , V_113 ,
V_123 ) ;
F_44 ( V_2 , & ( V_2 -> V_31 ) ) ;
}
if ( V_108 & V_124 ) {
F_2 ( V_2 , V_113 ,
V_124 ) ;
F_44 ( V_2 , & ( V_2 -> V_33 ) ) ;
}
if ( ! V_108 )
F_28 ( L_12 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
T_1 V_125 ;
void * V_64 ;
V_2 -> V_126 . V_80 = V_127 +
16 - ( V_127 % 8 ) ;
V_125 = V_2 -> V_126 . V_80 * V_36 ;
V_64 = F_14 ( NULL , V_125 , & V_2 -> V_126 . V_82 ,
V_21 ) ;
if ( ! V_64 )
goto V_54;
V_2 -> V_126 . V_83 = V_64 ;
memset ( V_64 , 0 , V_125 ) ;
V_2 -> V_128 . V_80 = V_127 +
16 - ( V_127 % 8 ) ;
V_125 = V_2 -> V_128 . V_80 * V_35 ;
V_64 = F_14 ( NULL , V_125 , & V_2 -> V_128 . V_82 ,
V_21 ) ;
if ( ! V_64 )
goto V_54;
V_2 -> V_128 . V_83 = V_64 ;
memset ( V_64 , 0 , V_125 ) ;
return 0 ;
V_54:
F_47 ( V_2 ) ;
F_11 ( L_13 ) ;
return - V_26 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 . V_83 )
F_48 ( NULL , V_2 -> V_126 . V_80 *
V_36 ,
V_2 -> V_126 . V_83 ,
V_2 -> V_126 . V_82 ) ;
if ( V_2 -> V_128 . V_83 ) {
F_48 ( NULL , V_2 -> V_128 . V_80 *
V_35 ,
V_2 -> V_128 . V_83 ,
V_2 -> V_128 . V_82 ) ;
}
}
int F_49 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_88 * V_89 ,
bool V_3 )
{
struct V_14 * V_15 = NULL ;
struct V_60 * V_66 = NULL ;
struct V_4 * V_5 = NULL ;
unsigned long V_96 ;
V_5 = V_3 ? & V_2 -> V_6 : & V_2 -> V_7 ;
V_15 = V_5 -> V_8 ;
F_26 ( & V_15 -> V_16 -> V_23 , V_96 ) ;
if ( NULL != V_15 -> V_16 -> V_89 ) {
F_50 ( V_2 -> V_100 ) ;
V_2 -> V_105 = true ;
F_27 ( & V_15 -> V_16 -> V_23 , V_96 ) ;
return - V_131 ;
}
F_27 ( & V_15 -> V_16 -> V_23 , V_96 ) ;
V_15 -> V_89 = NULL ;
V_66 = V_15 -> V_66 ;
V_66 -> V_73 = V_15 -> V_81 ;
V_66 -> V_70 = V_5 -> V_39 ;
V_66 -> V_132 = sizeof( struct V_133 ) ;
V_66 -> V_68 = V_5 -> V_42 ;
F_3 ( V_12 , L_14 ) ;
F_51 ( V_134 , L_15 ,
( char * ) V_66 , sizeof( * V_66 ) ) ;
F_51 ( V_134 ,
L_16 , ( char * ) V_15 -> V_9 ,
sizeof( struct V_133 ) ) ;
V_15 = V_15 -> V_16 ;
V_15 -> V_89 = V_89 ;
V_66 = V_15 -> V_66 ;
if ( V_15 -> V_9 ) {
F_11 ( L_17 ) ;
return - V_135 ;
}
V_66 -> V_73 = F_20 ( NULL ,
V_15 -> V_89 -> V_11 ,
V_15 -> V_89 -> V_102 ,
V_103 ) ;
V_66 -> V_70 = V_5 -> V_39 ;
V_66 -> V_132 = V_15 -> V_89 -> V_102 ;
V_66 -> V_68 = V_5 -> V_45 ;
F_51 ( V_134 , L_18 ,
( char * ) V_66 , sizeof( * V_66 ) ) ;
F_51 ( V_134 , L_19 ,
( char * ) V_15 -> V_89 -> V_11 , V_15 -> V_89 -> V_102 ) ;
V_5 -> V_8 = V_15 -> V_16 ;
if ( V_3 && V_130 -> V_136 == V_137 ) {
V_2 -> V_55 -> V_56 (
0 ,
V_57 ) ;
} else {
F_2 ( V_2 ,
V_5 -> V_48 , V_5 -> V_51 ) ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_85 = 0 , V_27 ;
V_85 = V_138 ;
F_2 ( V_2 , V_139 , V_85 ) ;
V_85 = V_140 ;
F_53 ( V_2 , V_141 , V_85 ) ;
F_13 ( & V_2 -> V_6 ) ;
F_15 ( & V_2 -> V_6 , & V_2 -> V_128 ) ;
F_2 ( V_2 , V_142 ,
V_2 -> V_6 . V_8 -> V_67 ) ;
F_2 ( V_2 ,
V_143 ,
V_40 ) ;
F_17 ( V_2 , V_144 , & V_85 ) ;
F_16 ( V_2 , V_115 ) ;
F_13 ( & V_2 -> V_7 ) ;
F_15 ( & V_2 -> V_7 , & V_2 -> V_126 ) ;
F_2 ( V_2 , V_145 ,
V_2 -> V_7 . V_8 -> V_67 ) ;
F_2 ( V_2 ,
V_146 ,
V_41 ) ;
F_17 ( V_2 , V_144 , & V_85 ) ;
F_16 ( V_2 , V_111 ) ;
F_13 ( & V_2 -> V_31 ) ;
F_22 ( V_2 , & V_2 -> V_31 ) ;
F_2 ( V_2 , V_147 ,
V_2 -> V_31 . V_8 -> V_67 ) ;
F_2 ( V_2 ,
V_148 ,
V_74 ) ;
F_2 ( V_2 ,
V_149 ,
V_2 -> V_31 . V_8 -> V_66 -> V_77 ) ;
F_2 ( V_2 ,
V_150 ,
V_151 ) ;
F_16 ( V_2 , V_152 ) ;
F_13 ( & V_2 -> V_33 ) ;
F_22 ( V_2 , & V_2 -> V_33 ) ;
F_2 ( V_2 , V_153 ,
V_2 -> V_33 . V_8 -> V_67 ) ;
F_2 ( V_2 ,
V_154 ,
V_76 ) ;
F_2 ( V_2 ,
V_155 ,
V_2 -> V_33 . V_8 -> V_66 -> V_77 ) ;
F_2 ( V_2 ,
V_156 ,
V_157 ) ;
F_16 ( V_2 , V_158 ) ;
V_27 = F_40 ( V_2 ) ;
if ( V_27 < 0 )
goto V_54;
return 0 ;
V_54:
return V_27 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_119 , V_2 ) ;
F_43 ( V_2 -> V_118 , V_2 ) ;
if ( V_2 -> V_98 ) {
F_30 ( V_2 -> V_100 , V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
}
F_23 ( V_2 , & V_2 -> V_31 ) ;
F_23 ( V_2 , & V_2 -> V_33 ) ;
}
