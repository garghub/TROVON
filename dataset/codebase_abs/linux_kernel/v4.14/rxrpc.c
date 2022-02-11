static int F_1 ( T_1 * V_1 )
{
F_2 () ;
return 0 ;
}
int F_3 ( void )
{
struct V_2 V_3 ;
struct V_4 * V_4 ;
int V_5 ;
F_4 ( L_1 ) ;
V_5 = - V_6 ;
V_7 = F_5 ( L_2 , V_8 , 0 ) ;
if ( ! V_7 )
goto V_9;
V_5 = F_6 ( & V_10 , V_11 , V_12 , V_13 , & V_4 ) ;
if ( V_5 < 0 )
goto V_14;
V_4 -> V_15 -> V_16 = V_17 ;
V_3 . V_18 = V_11 ;
V_3 . V_19 = V_20 ;
V_3 . V_21 = V_12 ;
V_3 . V_22 = sizeof( V_3 . V_23 . sin ) ;
V_3 . V_23 . sin . V_24 = V_25 ;
V_3 . V_23 . sin . V_26 = F_7 ( V_27 ) ;
memset ( & V_3 . V_23 . sin . V_28 , 0 ,
sizeof( V_3 . V_23 . sin . V_28 ) ) ;
V_5 = F_8 ( V_4 , (struct V_29 * ) & V_3 , sizeof( V_3 ) ) ;
if ( V_5 < 0 )
goto V_30;
F_9 ( V_4 , V_31 ,
V_32 ) ;
V_5 = F_10 ( V_4 , V_33 ) ;
if ( V_5 < 0 )
goto V_30;
V_34 = V_4 ;
F_11 ( NULL ) ;
F_12 ( L_3 ) ;
return 0 ;
V_30:
F_13 ( V_4 ) ;
V_14:
F_14 ( V_7 ) ;
V_9:
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
void F_15 ( void )
{
F_4 ( L_1 ) ;
F_10 ( V_34 , 0 ) ;
F_16 ( V_7 ) ;
if ( V_35 ) {
F_17 ( V_35 ) ;
V_35 = NULL ;
}
F_18 ( L_5 , F_19 ( & V_36 ) ) ;
F_20 ( & V_36 , F_1 ,
V_37 ) ;
F_18 ( L_6 ) ;
F_21 ( V_34 , V_38 ) ;
F_16 ( V_7 ) ;
F_13 ( V_34 ) ;
F_18 ( L_7 ) ;
F_14 ( V_7 ) ;
F_12 ( L_1 ) ;
}
static struct V_39 * F_22 ( const struct V_40 * type ,
T_2 V_41 )
{
struct V_39 * V_42 ;
int V_43 ;
V_42 = F_23 ( sizeof( * V_42 ) , V_41 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> type = type ;
F_24 ( & V_42 -> V_44 , 1 ) ;
F_25 ( & V_42 -> V_45 , V_46 ) ;
F_26 ( & V_42 -> V_47 ) ;
V_43 = F_27 ( & V_36 ) ;
F_28 ( V_42 , V_48 , 1 , V_43 ,
F_29 ( 0 ) ) ;
return V_42 ;
}
void F_17 ( struct V_39 * V_42 )
{
int V_49 = F_30 ( & V_42 -> V_44 ) ;
int V_43 = F_19 ( & V_36 ) ;
F_28 ( V_42 , V_50 , V_49 + 1 , V_43 ,
F_29 ( 0 ) ) ;
F_31 ( V_49 , >= , 0 ) ;
if ( V_49 == 0 ) {
ASSERT ( ! F_32 ( & V_42 -> V_45 ) ) ;
ASSERT ( V_42 -> type -> V_51 != NULL ) ;
if ( V_42 -> V_52 ) {
F_33 ( V_34 , V_42 -> V_52 ) ;
V_42 -> V_52 = NULL ;
}
if ( V_42 -> type -> V_53 )
V_42 -> type -> V_53 ( V_42 ) ;
F_34 ( V_42 -> V_54 ) ;
F_34 ( V_42 ) ;
V_43 = F_30 ( & V_36 ) ;
F_28 ( V_42 , V_55 , 0 , V_43 ,
F_29 ( 0 ) ) ;
if ( V_43 == 0 )
F_35 ( & V_36 ) ;
}
}
int F_36 ( struct V_39 * V_42 )
{
int V_56 = F_27 ( & V_42 -> V_44 ) ;
F_28 ( V_42 , V_57 , V_56 ,
F_19 ( & V_36 ) ,
F_29 ( 0 ) ) ;
F_25 ( & V_42 -> V_58 , V_42 -> type -> V_58 ) ;
if ( ! F_37 ( V_59 , & V_42 -> V_58 ) )
F_17 ( V_42 ) ;
return 0 ;
}
struct V_39 * F_38 ( const struct V_40 * type ,
T_3 V_60 , T_3 V_61 )
{
struct V_39 * V_42 ;
V_42 = F_22 ( type , V_17 ) ;
if ( ! V_42 )
goto V_62;
if ( V_60 ) {
V_42 -> V_60 = V_60 ;
V_42 -> V_54 = F_39 ( V_60 , V_17 ) ;
if ( ! V_42 -> V_54 )
goto V_63;
}
if ( V_61 ) {
V_42 -> V_61 = V_61 ;
V_42 -> V_64 = F_39 ( V_61 , V_17 ) ;
if ( ! V_42 -> V_64 )
goto V_63;
}
F_26 ( & V_42 -> V_47 ) ;
return V_42 ;
V_63:
F_17 ( V_42 ) ;
V_62:
return NULL ;
}
void F_40 ( struct V_39 * V_42 )
{
F_4 ( L_1 ) ;
F_34 ( V_42 -> V_54 ) ;
V_42 -> V_54 = NULL ;
F_34 ( V_42 -> V_64 ) ;
V_42 -> V_64 = NULL ;
}
static void F_41 ( struct V_39 * V_42 , struct V_65 * V_66 ,
struct V_67 * V_68 , T_4 V_69 , T_4 V_70 ,
unsigned V_71 )
{
struct V_72 * V_73 [ V_74 ] ;
unsigned int V_75 , V_49 , V_76 , V_77 , V_78 = 0 ;
V_75 = F_42 ( T_4 , V_70 - V_69 + 1 , V_74 ) ;
V_49 = F_43 ( V_42 -> V_79 , V_69 , V_75 , V_73 ) ;
F_31 ( V_49 , == , V_75 ) ;
V_66 -> V_80 |= V_81 ;
for ( V_76 = 0 ; V_76 < V_75 ; V_76 ++ ) {
V_77 = V_82 ;
if ( V_69 + V_76 >= V_70 ) {
V_77 = V_42 -> V_83 ;
V_66 -> V_80 &= ~ V_81 ;
}
V_68 [ V_76 ] . V_84 = V_73 [ V_76 ] ;
V_68 [ V_76 ] . V_85 = V_77 - V_71 ;
V_68 [ V_76 ] . V_86 = V_71 ;
V_78 += V_77 - V_71 ;
V_71 = 0 ;
}
F_44 ( & V_66 -> V_87 , V_88 | V_89 , V_68 , V_75 , V_78 ) ;
}
static void F_45 ( struct V_90 * V_90 ,
struct V_91 * V_52 ,
unsigned long V_92 )
{
struct V_39 * V_42 = (struct V_39 * ) V_92 ;
if ( V_42 -> V_93 == V_94 )
V_42 -> V_93 = V_95 ;
}
static int F_46 ( struct V_39 * V_42 , struct V_65 * V_66 )
{
struct V_67 V_68 [ V_74 ] ;
unsigned int V_78 , V_75 , V_96 , V_71 ;
T_4 V_69 = V_42 -> V_69 , V_70 = V_42 -> V_70 ;
int V_5 ;
V_71 = V_42 -> V_97 ;
V_42 -> V_97 = 0 ;
do {
F_41 ( V_42 , V_66 , V_68 , V_69 , V_70 , V_71 ) ;
V_71 = 0 ;
V_78 = V_66 -> V_87 . V_98 ;
V_75 = V_66 -> V_87 . V_99 ;
V_5 = F_47 ( V_34 , V_42 -> V_52 , V_66 ,
V_78 , F_45 ) ;
for ( V_96 = 0 ; V_96 < V_75 ; V_96 ++ )
F_48 ( V_68 [ V_96 ] . V_84 ) ;
if ( V_5 < 0 )
break;
V_69 += V_75 ;
} while ( V_69 <= V_70 );
return V_5 ;
}
int F_49 ( struct V_100 * V_101 , struct V_39 * V_42 , T_2 V_41 ,
bool V_102 )
{
struct V_2 V_3 ;
struct V_91 * V_52 ;
struct V_65 V_66 ;
struct V_103 V_104 [ 1 ] ;
T_3 V_71 ;
T_5 V_105 ;
T_6 V_106 ;
int V_5 ;
F_4 ( L_8 , V_101 -> V_107 , F_50 ( V_42 -> V_108 ) ) ;
ASSERT ( V_42 -> type != NULL ) ;
ASSERT ( V_42 -> type -> V_51 != NULL ) ;
F_18 ( L_9 ,
V_42 , V_42 -> type -> V_51 , F_51 ( V_42 -> V_109 ) ,
F_19 ( & V_36 ) ) ;
V_42 -> V_102 = V_102 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_18 = V_11 ;
V_3 . V_19 = V_42 -> V_110 ;
V_3 . V_21 = V_12 ;
V_3 . V_22 = sizeof( V_3 . V_23 . sin ) ;
V_3 . V_23 . sin . V_24 = V_25 ;
V_3 . V_23 . sin . V_26 = V_42 -> V_108 ;
memcpy ( & V_3 . V_23 . sin . V_28 , V_101 , 4 ) ;
V_105 = V_42 -> V_60 ;
if ( V_42 -> V_111 ) {
V_105 += V_42 -> V_83 - V_42 -> V_97 ;
V_105 += ( V_42 -> V_70 - V_42 -> V_69 ) * V_82 ;
}
V_52 = F_52 ( V_34 , & V_3 , V_42 -> V_109 ,
( unsigned long ) V_42 ,
V_105 , V_41 ,
( V_102 ?
V_112 :
V_113 ) ) ;
V_42 -> V_109 = NULL ;
if ( F_53 ( V_52 ) ) {
V_5 = F_54 ( V_52 ) ;
goto V_114;
}
V_42 -> V_52 = V_52 ;
V_104 [ 0 ] . V_115 = V_42 -> V_54 ;
V_104 [ 0 ] . V_116 = V_42 -> V_60 ;
V_66 . V_117 = NULL ;
V_66 . V_118 = 0 ;
F_55 ( & V_66 . V_87 , V_88 | V_119 , V_104 , 1 ,
V_42 -> V_60 ) ;
V_66 . V_120 = NULL ;
V_66 . V_121 = 0 ;
V_66 . V_80 = ( V_42 -> V_111 ? V_81 : 0 ) ;
if ( ! V_42 -> V_111 )
V_42 -> V_93 = V_95 ;
V_5 = F_47 ( V_34 , V_52 ,
& V_66 , V_42 -> V_60 ,
F_45 ) ;
if ( V_5 < 0 )
goto V_122;
if ( V_42 -> V_111 ) {
V_5 = F_46 ( V_42 , & V_66 ) ;
if ( V_5 < 0 )
goto V_122;
}
if ( V_42 -> V_102 )
return - V_123 ;
return F_56 ( V_42 ) ;
V_122:
V_42 -> V_93 = V_124 ;
if ( V_5 != - V_125 ) {
F_57 ( V_34 , V_52 , V_126 ,
V_5 , L_10 ) ;
} else {
V_106 = 0 ;
V_71 = 0 ;
F_58 ( V_34 , V_52 , NULL , 0 , & V_71 ,
false , & V_106 ) ;
V_5 = V_42 -> type -> V_127 ( V_106 ) ;
}
V_114:
F_17 ( V_42 ) ;
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
static void F_59 ( struct V_39 * V_42 )
{
T_6 V_106 ;
int V_5 ;
F_4 ( L_11 , V_42 -> type -> V_51 ) ;
while ( V_42 -> V_93 == V_95 ||
V_42 -> V_93 == V_128 ||
V_42 -> V_93 == V_129 ||
V_42 -> V_93 == V_130
) {
if ( V_42 -> V_93 == V_130 ) {
T_3 V_71 = 0 ;
V_5 = F_58 ( V_34 , V_42 -> V_52 ,
NULL , 0 , & V_71 , false ,
& V_42 -> V_106 ) ;
F_60 ( V_42 , 0 , V_71 , false , V_5 ) ;
if ( V_5 == - V_123 || V_5 == - V_131 )
return;
if ( V_5 == 1 || V_5 < 0 ) {
V_42 -> V_93 = V_124 ;
goto V_132;
}
return;
}
V_5 = V_42 -> type -> V_133 ( V_42 ) ;
switch ( V_5 ) {
case 0 :
if ( V_42 -> V_93 == V_95 )
V_42 -> V_93 = V_124 ;
goto V_132;
case - V_123 :
case - V_131 :
goto V_134;
case - V_125 :
goto V_135;
case - V_136 :
V_106 = V_137 ;
F_57 ( V_34 , V_42 -> V_52 ,
V_106 , V_5 , L_12 ) ;
goto V_138;
case - V_139 :
V_106 = V_140 ;
F_57 ( V_34 , V_42 -> V_52 ,
V_106 , V_5 , L_13 ) ;
goto V_138;
case - V_141 :
case - V_142 :
case - V_143 :
default:
V_106 = V_144 ;
if ( V_42 -> V_93 != V_95 )
V_106 = V_145 ;
F_57 ( V_34 , V_42 -> V_52 ,
V_106 , - V_142 , L_14 ) ;
goto V_138;
}
}
V_132:
if ( V_42 -> V_93 == V_124 && V_42 -> V_146 )
F_17 ( V_42 ) ;
V_134:
F_12 ( L_1 ) ;
return;
V_138:
V_42 -> error = V_5 ;
V_135:
V_42 -> V_93 = V_124 ;
goto V_132;
}
static int F_56 ( struct V_39 * V_42 )
{
int V_5 ;
F_61 ( V_147 , V_148 ) ;
F_4 ( L_1 ) ;
F_62 ( & V_42 -> V_47 , & V_147 ) ;
for (; ; ) {
F_63 ( V_149 ) ;
if ( V_42 -> V_93 < V_124 && V_42 -> V_150 ) {
V_42 -> V_150 = false ;
F_64 ( V_151 ) ;
F_59 ( V_42 ) ;
continue;
}
if ( V_42 -> V_93 == V_124 ||
F_65 ( V_148 ) )
break;
F_2 () ;
}
F_66 ( & V_42 -> V_47 , & V_147 ) ;
F_64 ( V_151 ) ;
if ( V_42 -> V_93 < V_124 ) {
F_18 ( L_15 ) ;
F_57 ( V_34 , V_42 -> V_52 ,
V_126 , - V_152 , L_16 ) ;
}
V_5 = V_42 -> error ;
F_18 ( L_17 ) ;
F_17 ( V_42 ) ;
F_12 ( L_4 , V_5 ) ;
return V_5 ;
}
static void V_113 ( struct V_90 * V_15 , struct V_91 * V_52 ,
unsigned long V_92 )
{
struct V_39 * V_42 = (struct V_39 * ) V_92 ;
V_42 -> V_150 = true ;
F_67 ( & V_42 -> V_47 ) ;
}
static void V_112 ( struct V_90 * V_15 , struct V_91 * V_52 ,
unsigned long V_92 )
{
struct V_39 * V_42 = (struct V_39 * ) V_92 ;
int V_56 ;
F_68 ( V_52 , V_42 ) ;
V_42 -> V_150 = true ;
V_56 = F_69 ( & V_42 -> V_44 , 1 , 0 ) ;
if ( V_56 != 0 ) {
F_28 ( V_42 , V_153 , V_56 ,
F_19 ( & V_36 ) ,
F_29 ( 0 ) ) ;
if ( ! F_37 ( V_7 , & V_42 -> V_45 ) )
F_17 ( V_42 ) ;
}
}
static void F_70 ( struct V_154 * V_58 )
{
struct V_39 * V_42 = F_71 ( V_58 , struct V_39 , V_45 ) ;
F_4 ( L_1 ) ;
F_17 ( V_42 ) ;
F_12 ( L_1 ) ;
}
static void V_46 ( struct V_154 * V_58 )
{
struct V_39 * V_42 = F_71 ( V_58 , struct V_39 , V_45 ) ;
F_4 ( L_1 ) ;
if ( V_42 -> V_93 < V_124 && V_42 -> V_150 ) {
V_42 -> V_150 = false ;
F_59 ( V_42 ) ;
}
if ( V_42 -> V_93 == V_124 ) {
V_42 -> V_155 = NULL ;
V_42 -> V_45 . V_156 = F_70 ;
if ( ! F_37 ( V_7 , & V_42 -> V_45 ) )
F_17 ( V_42 ) ;
}
F_17 ( V_42 ) ;
F_12 ( L_1 ) ;
}
static void F_72 ( struct V_91 * V_52 , unsigned long V_157 )
{
struct V_39 * V_42 = (struct V_39 * ) V_157 ;
V_42 -> V_52 = V_52 ;
}
static void F_11 ( struct V_154 * V_58 )
{
struct V_39 * V_42 = V_35 ;
for (; ; ) {
if ( ! V_42 ) {
V_42 = F_22 ( & V_158 , V_159 ) ;
if ( ! V_42 )
break;
V_42 -> V_102 = true ;
V_42 -> V_93 = V_128 ;
F_26 ( & V_42 -> V_47 ) ;
}
if ( F_73 ( V_34 ,
V_112 ,
F_72 ,
( unsigned long ) V_42 ,
V_159 ) < 0 )
break;
V_42 = NULL ;
}
V_35 = V_42 ;
}
static void V_32 ( struct V_91 * V_52 ,
unsigned long V_157 )
{
struct V_39 * V_42 = (struct V_39 * ) V_157 ;
V_42 -> V_52 = NULL ;
F_17 ( V_42 ) ;
}
static void V_31 ( struct V_90 * V_15 , struct V_91 * V_52 ,
unsigned long V_157 )
{
F_37 ( V_59 , & V_160 ) ;
}
static int F_74 ( struct V_39 * V_42 )
{
int V_5 ;
F_4 ( L_18 , V_42 -> V_71 ) ;
F_31 ( V_42 -> V_71 , < , 4 ) ;
V_5 = F_75 ( V_42 , & V_42 -> V_161 , 4 , true ) ;
if ( V_5 < 0 )
return V_5 ;
V_42 -> V_162 = F_76 ( V_42 -> V_161 ) ;
V_42 -> V_93 = V_129 ;
V_42 -> V_71 = 0 ;
if ( ! F_77 ( V_42 ) )
return - V_139 ;
F_78 ( V_42 ) ;
return V_42 -> type -> V_133 ( V_42 ) ;
}
static void F_79 ( struct V_90 * V_90 ,
struct V_91 * V_52 ,
unsigned long V_92 )
{
struct V_39 * V_42 = (struct V_39 * ) V_92 ;
if ( V_42 -> V_93 == V_163 )
V_42 -> V_93 = V_130 ;
}
void F_80 ( struct V_39 * V_42 )
{
struct V_65 V_66 ;
F_4 ( L_1 ) ;
F_81 ( V_34 , V_42 -> V_52 , 0 ) ;
V_66 . V_117 = NULL ;
V_66 . V_118 = 0 ;
F_55 ( & V_66 . V_87 , V_88 | V_119 , NULL , 0 , 0 ) ;
V_66 . V_120 = NULL ;
V_66 . V_121 = 0 ;
V_66 . V_80 = 0 ;
V_42 -> V_93 = V_130 ;
switch ( F_47 ( V_34 , V_42 -> V_52 , & V_66 , 0 ,
F_79 ) ) {
case 0 :
F_12 ( L_19 ) ;
return;
case - V_6 :
F_18 ( L_20 ) ;
F_57 ( V_34 , V_42 -> V_52 ,
V_126 , - V_6 , L_21 ) ;
default:
F_12 ( L_22 ) ;
return;
}
}
void F_82 ( struct V_39 * V_42 , const void * V_164 , T_3 V_165 )
{
struct V_65 V_66 ;
struct V_103 V_104 [ 1 ] ;
int V_49 ;
F_4 ( L_1 ) ;
F_81 ( V_34 , V_42 -> V_52 , V_165 ) ;
V_104 [ 0 ] . V_115 = ( void * ) V_164 ;
V_104 [ 0 ] . V_116 = V_165 ;
V_66 . V_117 = NULL ;
V_66 . V_118 = 0 ;
F_55 ( & V_66 . V_87 , V_88 | V_119 , V_104 , 1 , V_165 ) ;
V_66 . V_120 = NULL ;
V_66 . V_121 = 0 ;
V_66 . V_80 = 0 ;
V_42 -> V_93 = V_130 ;
V_49 = F_47 ( V_34 , V_42 -> V_52 , & V_66 , V_165 ,
F_79 ) ;
if ( V_49 >= 0 ) {
F_12 ( L_19 ) ;
return;
}
if ( V_49 == - V_6 ) {
F_18 ( L_20 ) ;
F_57 ( V_34 , V_42 -> V_52 ,
V_126 , - V_6 , L_21 ) ;
}
F_12 ( L_22 ) ;
}
int F_75 ( struct V_39 * V_42 , void * V_164 , T_3 V_98 ,
bool V_166 )
{
int V_5 ;
F_4 ( L_23 ,
V_42 -> type -> V_51 , V_42 -> V_71 , V_98 , V_166 ) ;
F_31 ( V_42 -> V_71 , <= , V_98 ) ;
V_5 = F_58 ( V_34 , V_42 -> V_52 ,
V_164 , V_98 , & V_42 -> V_71 ,
V_166 , & V_42 -> V_106 ) ;
F_60 ( V_42 , V_98 , V_42 -> V_71 , V_166 , V_5 ) ;
if ( V_5 == 0 || V_5 == - V_131 )
return V_5 ;
if ( V_5 == 1 ) {
switch ( V_42 -> V_93 ) {
case V_95 :
V_42 -> V_93 = V_124 ;
break;
case V_129 :
V_42 -> V_93 = V_163 ;
break;
default:
break;
}
return 0 ;
}
if ( V_5 == - V_125 )
V_42 -> error = V_42 -> type -> V_127 ( V_42 -> V_106 ) ;
else
V_42 -> error = V_5 ;
V_42 -> V_93 = V_124 ;
return V_5 ;
}
