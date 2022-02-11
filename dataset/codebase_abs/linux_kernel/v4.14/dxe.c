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
V_29 = F_14 ( V_2 -> V_57 ,
V_58 |
V_59 ,
V_59 ) ;
if ( V_29 )
goto V_56;
return 0 ;
V_56:
F_15 ( L_4 ) ;
F_16 ( V_2 ) ;
return - V_28 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_6 ) ;
F_8 ( & V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_35 ) ;
}
static int F_17 ( struct V_60 * V_61 , struct V_4 * V_62 )
{
struct V_63 * V_64 = NULL ;
struct V_63 * V_65 = NULL ;
struct V_15 * V_21 = NULL ;
T_1 V_66 ;
int V_18 ;
V_66 = V_62 -> V_19 * sizeof( struct V_63 ) ;
V_62 -> V_67 = F_18 ( V_61 , V_66 , & V_62 -> V_68 ,
V_23 ) ;
if ( ! V_62 -> V_67 )
return - V_28 ;
memset ( V_62 -> V_67 , 0 , V_66 ) ;
V_64 = (struct V_63 * ) V_62 -> V_67 ;
V_21 = V_62 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_62 -> V_19 ; V_18 ++ ) {
V_21 -> V_69 = V_64 ;
V_21 -> V_70 = V_62 -> V_68 +
V_18 * sizeof( struct V_63 ) ;
switch ( V_62 -> V_30 ) {
case V_31 :
V_64 -> V_71 = V_72 ;
V_64 -> V_73 = V_42 ;
break;
case V_32 :
V_64 -> V_71 = V_74 ;
V_64 -> V_73 = V_43 ;
break;
case V_34 :
V_64 -> V_71 = V_75 ;
V_64 -> V_76 = V_77 ;
break;
case V_36 :
V_64 -> V_71 = V_78 ;
V_64 -> V_76 = V_79 ;
break;
}
if ( 0 == V_18 ) {
V_64 -> V_80 = 0 ;
} else if ( ( 0 < V_18 ) && ( V_18 < V_62 -> V_19 - 1 ) ) {
V_65 -> V_80 =
V_21 -> V_70 ;
} else if ( V_18 == ( V_62 -> V_19 - 1 ) ) {
V_65 -> V_80 =
V_21 -> V_70 ;
V_64 -> V_80 =
V_62 -> V_8 -> V_70 ;
}
V_21 = V_21 -> V_17 ;
V_65 = V_64 ;
V_64 ++ ;
}
return 0 ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_81 * V_82 )
{
int V_18 , V_83 = V_82 -> V_83 ;
T_2 V_84 = V_82 -> V_85 ;
void * V_9 = V_82 -> V_86 ;
struct V_15 * V_87 = V_5 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_19 ; V_18 ++ ) {
if ( ! ( V_18 & 1 ) ) {
V_87 -> V_84 = V_84 ;
V_87 -> V_9 = V_9 ;
V_84 += V_83 ;
V_9 += V_83 ;
} else {
V_87 -> V_84 = 0 ;
V_87 -> V_9 = NULL ;
}
V_87 = V_87 -> V_17 ;
}
}
static int F_20 ( struct V_1 * V_2 , T_3 V_62 )
{
int V_88 = 0 ;
F_6 ( V_2 ,
V_89 ,
& V_88 ) ;
V_88 |= V_62 ;
F_5 ( V_2 ,
V_89 ,
( int ) V_88 ) ;
return 0 ;
}
static int F_21 ( struct V_60 * V_61 , struct V_15 * V_16 )
{
struct V_63 * V_90 = V_16 -> V_69 ;
struct V_91 * V_92 ;
V_92 = F_22 ( V_93 , V_94 ) ;
if ( V_92 == NULL )
return - V_28 ;
V_90 -> V_73 = F_23 ( V_61 ,
F_24 ( V_92 ) ,
V_93 ,
V_95 ) ;
if ( F_25 ( V_61 , V_90 -> V_73 ) ) {
F_26 ( V_61 , L_5 ) ;
F_27 ( V_92 ) ;
return - V_28 ;
}
V_16 -> V_92 = V_92 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_4 * V_62 )
{
int V_18 ;
struct V_15 * V_21 = NULL ;
V_21 = V_62 -> V_8 ;
for ( V_18 = 0 ; V_18 < V_62 -> V_19 ; V_18 ++ ) {
F_21 ( V_2 -> V_61 , V_21 ) ;
V_21 = V_21 -> V_17 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_4 * V_62 )
{
struct V_15 * V_87 = V_62 -> V_8 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_62 -> V_19 ; V_18 ++ ) {
F_27 ( V_87 -> V_92 ) ;
V_87 = V_87 -> V_17 ;
}
}
void F_30 ( struct V_1 * V_2 , T_4 V_96 )
{
struct V_97 * V_98 ;
struct V_91 * V_92 ;
unsigned long V_99 ;
F_31 ( & V_2 -> V_100 , V_99 ) ;
V_92 = V_2 -> V_101 ;
V_2 -> V_101 = NULL ;
F_32 ( & V_2 -> V_100 , V_99 ) ;
if ( ! V_92 ) {
F_33 ( L_6 ) ;
return;
}
V_98 = F_34 ( V_92 ) ;
if ( V_96 == 1 )
V_98 -> V_99 |= V_102 ;
F_3 ( V_12 , L_7 , V_96 ) ;
F_35 ( V_2 -> V_103 , V_92 ) ;
F_36 ( V_2 -> V_103 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_15 * V_16 ;
struct V_97 * V_98 ;
unsigned long V_99 ;
F_31 ( & V_5 -> V_22 , V_99 ) ;
V_16 = V_5 -> V_27 ;
do {
if ( V_16 -> V_69 -> V_71 & V_104 )
break;
if ( V_16 -> V_92 ) {
F_38 ( V_2 -> V_61 , V_16 -> V_69 -> V_76 ,
V_16 -> V_92 -> V_105 , V_106 ) ;
V_98 = F_34 ( V_16 -> V_92 ) ;
if ( ! ( V_98 -> V_99 & V_107 ) ) {
F_39 ( V_2 -> V_103 , V_16 -> V_92 ) ;
}
F_40 ( & V_16 -> V_25 ) ;
if ( V_2 -> V_108 ) {
V_2 -> V_108 = false ;
F_36 ( V_2 -> V_103 ) ;
}
F_41 ( & V_16 -> V_25 ) ;
V_16 -> V_92 = NULL ;
}
V_16 = V_16 -> V_17 ;
} while ( V_16 != V_5 -> V_8 &&
! ( V_16 -> V_69 -> V_71 & V_104 ) );
V_5 -> V_27 = V_16 ;
F_32 ( & V_5 -> V_22 , V_99 ) ;
}
static T_5 F_42 ( int V_109 , void * V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
int V_110 , V_111 ;
F_6 ( V_2 , V_112 , & V_110 ) ;
if ( V_110 & V_113 ) {
F_6 ( V_2 ,
V_114 ,
& V_111 ) ;
F_5 ( V_2 ,
V_115 ,
V_113 ) ;
F_5 ( V_2 , V_116 ,
V_113 ) ;
F_3 ( V_12 , L_8 ) ;
F_37 ( V_2 , & V_2 -> V_7 ) ;
}
if ( V_110 & V_117 ) {
F_6 ( V_2 ,
V_118 ,
& V_111 ) ;
F_5 ( V_2 ,
V_115 ,
V_117 ) ;
F_5 ( V_2 , V_116 ,
V_117 ) ;
F_3 ( V_12 , L_9 ) ;
F_37 ( V_2 , & V_2 -> V_6 ) ;
}
return V_119 ;
}
static T_5 F_43 ( int V_109 , void * V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
F_44 ( V_2 -> V_120 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 -> V_120 ) ;
return V_119 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_48 ( V_2 -> V_121 , F_42 ,
V_122 , L_10 , V_2 ) ;
if ( V_29 ) {
F_15 ( L_11 ) ;
goto V_56;
}
V_29 = F_48 ( V_2 -> V_120 , F_43 , V_122 ,
L_12 , V_2 ) ;
if ( V_29 ) {
F_15 ( L_13 ) ;
goto V_123;
}
F_49 ( V_2 -> V_120 ) ;
return 0 ;
V_123:
F_50 ( V_2 -> V_121 , V_2 ) ;
V_56:
return V_29 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_8 ;
struct V_63 * V_90 = V_16 -> V_69 ;
T_2 V_68 ;
struct V_91 * V_92 ;
int V_29 = 0 , V_124 ;
T_4 V_125 ;
if ( V_5 -> V_30 == V_34 ) {
V_125 = V_75 ;
V_124 = V_126 ;
} else {
V_125 = V_78 ;
V_124 = V_127 ;
}
while ( ! ( V_90 -> V_71 & V_104 ) ) {
V_92 = V_16 -> V_92 ;
V_68 = V_90 -> V_73 ;
V_29 = F_21 ( V_2 -> V_61 , V_16 ) ;
if ( 0 == V_29 ) {
F_38 ( V_2 -> V_61 , V_68 , V_93 ,
V_95 ) ;
F_52 ( V_2 , V_92 ) ;
}
V_90 -> V_71 = V_125 ;
V_16 = V_16 -> V_17 ;
V_90 = V_16 -> V_69 ;
}
F_5 ( V_2 , V_128 , V_124 ) ;
V_5 -> V_8 = V_16 ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
int V_110 ;
F_6 ( V_2 , V_112 , & V_110 ) ;
if ( V_110 & V_126 ) {
F_5 ( V_2 , V_115 ,
V_126 ) ;
F_51 ( V_2 , & ( V_2 -> V_33 ) ) ;
}
if ( V_110 & V_127 ) {
F_5 ( V_2 , V_115 ,
V_127 ) ;
F_51 ( V_2 , & ( V_2 -> V_35 ) ) ;
}
if ( ! V_110 )
F_33 ( L_14 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
T_1 V_129 ;
void * V_67 ;
V_2 -> V_130 . V_83 = V_131 +
16 - ( V_131 % 8 ) ;
V_129 = V_2 -> V_130 . V_83 * V_38 ;
V_67 = F_18 ( V_2 -> V_61 , V_129 , & V_2 -> V_130 . V_85 ,
V_23 ) ;
if ( ! V_67 )
goto V_56;
V_2 -> V_130 . V_86 = V_67 ;
memset ( V_67 , 0 , V_129 ) ;
V_2 -> V_132 . V_83 = V_131 +
16 - ( V_131 % 8 ) ;
V_129 = V_2 -> V_132 . V_83 * V_37 ;
V_67 = F_18 ( V_2 -> V_61 , V_129 , & V_2 -> V_132 . V_85 ,
V_23 ) ;
if ( ! V_67 )
goto V_56;
V_2 -> V_132 . V_86 = V_67 ;
memset ( V_67 , 0 , V_129 ) ;
return 0 ;
V_56:
F_54 ( V_2 ) ;
F_15 ( L_15 ) ;
return - V_28 ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_130 . V_86 )
F_55 ( V_2 -> V_61 , V_2 -> V_130 . V_83 *
V_38 ,
V_2 -> V_130 . V_86 ,
V_2 -> V_130 . V_85 ) ;
if ( V_2 -> V_132 . V_86 ) {
F_55 ( V_2 -> V_61 , V_2 -> V_132 . V_83 *
V_37 ,
V_2 -> V_132 . V_86 ,
V_2 -> V_132 . V_85 ) ;
}
}
int F_56 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
struct V_91 * V_92 ,
bool V_3 )
{
struct V_15 * V_16 = NULL ;
struct V_63 * V_69 = NULL ;
struct V_4 * V_5 = NULL ;
unsigned long V_99 ;
int V_29 ;
V_5 = V_3 ? & V_2 -> V_6 : & V_2 -> V_7 ;
F_31 ( & V_5 -> V_22 , V_99 ) ;
V_16 = V_5 -> V_8 ;
F_40 ( & V_16 -> V_17 -> V_25 ) ;
if ( NULL != V_16 -> V_17 -> V_92 ) {
F_57 ( V_2 -> V_103 ) ;
V_2 -> V_108 = true ;
F_41 ( & V_16 -> V_17 -> V_25 ) ;
F_32 ( & V_5 -> V_22 , V_99 ) ;
return - V_135 ;
}
F_41 ( & V_16 -> V_17 -> V_25 ) ;
V_16 -> V_92 = NULL ;
V_69 = V_16 -> V_69 ;
V_69 -> V_76 = V_16 -> V_84 ;
V_69 -> V_73 = V_5 -> V_41 ;
V_69 -> V_136 = sizeof( struct V_137 ) ;
V_69 -> V_71 = V_5 -> V_44 ;
F_3 ( V_12 , L_16 ) ;
F_58 ( V_138 , L_17 ,
( char * ) V_69 , sizeof( * V_69 ) ) ;
F_58 ( V_138 ,
L_18 , ( char * ) V_16 -> V_9 ,
sizeof( struct V_137 ) ) ;
V_16 = V_16 -> V_17 ;
V_16 -> V_92 = V_92 ;
V_69 = V_16 -> V_69 ;
if ( V_16 -> V_9 ) {
F_15 ( L_19 ) ;
V_29 = - V_139 ;
goto V_140;
}
V_69 -> V_76 = F_23 ( V_2 -> V_61 ,
V_16 -> V_92 -> V_11 ,
V_16 -> V_92 -> V_105 ,
V_106 ) ;
V_69 -> V_73 = V_5 -> V_41 ;
V_69 -> V_136 = V_16 -> V_92 -> V_105 ;
V_69 -> V_71 = V_5 -> V_47 ;
F_58 ( V_138 , L_20 ,
( char * ) V_69 , sizeof( * V_69 ) ) ;
F_58 ( V_138 , L_21 ,
( char * ) V_16 -> V_92 -> V_11 , V_16 -> V_92 -> V_105 ) ;
V_5 -> V_8 = V_16 -> V_17 ;
if ( V_3 && V_134 -> V_141 == V_142 ) {
F_14 ( V_2 -> V_143 ,
V_58 ,
V_58 ) ;
} else {
F_5 ( V_2 ,
V_5 -> V_50 , V_5 -> V_53 ) ;
}
V_29 = 0 ;
V_140:
F_32 ( & V_5 -> V_22 , V_99 ) ;
return V_29 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_88 = 0 , V_29 ;
V_88 = V_144 ;
F_5 ( V_2 , V_145 , V_88 ) ;
V_88 = ( V_127 | V_126 ) << 16 |
V_146 | V_147 ;
if ( V_2 -> V_148 )
F_2 ( V_2 , V_149 , V_88 ) ;
else
F_2 ( V_2 , V_150 , V_88 ) ;
F_17 ( V_2 -> V_61 , & V_2 -> V_6 ) ;
F_19 ( & V_2 -> V_6 , & V_2 -> V_132 ) ;
F_5 ( V_2 , V_151 ,
V_2 -> V_6 . V_8 -> V_70 ) ;
F_5 ( V_2 ,
V_152 ,
V_42 ) ;
F_6 ( V_2 , V_153 , & V_88 ) ;
F_20 ( V_2 , V_117 ) ;
F_17 ( V_2 -> V_61 , & V_2 -> V_7 ) ;
F_19 ( & V_2 -> V_7 , & V_2 -> V_130 ) ;
F_5 ( V_2 , V_154 ,
V_2 -> V_7 . V_8 -> V_70 ) ;
F_5 ( V_2 ,
V_155 ,
V_43 ) ;
F_6 ( V_2 , V_153 , & V_88 ) ;
F_20 ( V_2 , V_113 ) ;
F_17 ( V_2 -> V_61 , & V_2 -> V_33 ) ;
F_28 ( V_2 , & V_2 -> V_33 ) ;
F_5 ( V_2 , V_156 ,
V_2 -> V_33 . V_8 -> V_70 ) ;
F_5 ( V_2 ,
V_157 ,
V_77 ) ;
F_5 ( V_2 ,
V_158 ,
V_2 -> V_33 . V_8 -> V_69 -> V_80 ) ;
F_5 ( V_2 ,
V_159 ,
V_160 ) ;
F_20 ( V_2 , V_161 ) ;
F_17 ( V_2 -> V_61 , & V_2 -> V_35 ) ;
F_28 ( V_2 , & V_2 -> V_35 ) ;
F_5 ( V_2 , V_162 ,
V_2 -> V_35 . V_8 -> V_70 ) ;
F_5 ( V_2 ,
V_163 ,
V_79 ) ;
F_5 ( V_2 ,
V_164 ,
V_2 -> V_35 . V_8 -> V_69 -> V_80 ) ;
F_5 ( V_2 ,
V_165 ,
V_166 ) ;
F_20 ( V_2 , V_167 ) ;
V_29 = F_47 ( V_2 ) ;
if ( V_29 < 0 )
goto V_56;
return 0 ;
V_56:
return V_29 ;
}
void F_60 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_121 , V_2 ) ;
F_50 ( V_2 -> V_120 , V_2 ) ;
if ( V_2 -> V_101 ) {
F_35 ( V_2 -> V_103 , V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
}
F_29 ( V_2 , & V_2 -> V_33 ) ;
F_29 ( V_2 , & V_2 -> V_35 ) ;
}
