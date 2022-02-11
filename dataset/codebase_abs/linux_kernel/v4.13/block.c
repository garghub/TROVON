static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
V_4 = V_3 -> V_6 ;
if ( V_4 && V_4 -> V_7 == 0 )
V_4 = NULL ;
if ( V_4 )
V_4 -> V_7 ++ ;
F_3 ( & V_5 ) ;
return V_4 ;
}
static inline int F_4 ( struct V_2 * V_3 )
{
int V_8 = V_3 -> V_9 / V_10 ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
V_4 -> V_7 -- ;
if ( V_4 -> V_7 == 0 ) {
int V_8 = F_4 ( V_4 -> V_3 ) ;
F_6 ( V_4 -> V_11 . V_11 ) ;
F_7 ( & V_12 , V_8 ) ;
F_8 ( V_4 -> V_3 ) ;
F_9 ( V_4 ) ;
}
F_3 ( & V_5 ) ;
}
static T_1 F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
int V_18 ;
struct V_1 * V_4 = F_1 ( F_11 ( V_14 ) ) ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
int V_21 = 0 ;
if ( V_20 -> V_22 . V_23 & V_24 )
V_21 = 2 ;
else if ( V_20 -> V_22 . V_23 & V_25 )
V_21 = 1 ;
V_18 = snprintf ( V_17 , V_26 , L_1 , V_21 ) ;
F_5 ( V_4 ) ;
return V_18 ;
}
static T_1 F_12 ( struct V_13 * V_14 ,
struct V_15 * V_16 , const char * V_17 , T_2 V_27 )
{
int V_18 ;
struct V_1 * V_4 , * V_28 ;
struct V_19 * V_20 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
if ( F_13 ( V_17 , 0 , & V_33 ) )
return - V_34 ;
if ( V_33 != 1 )
return V_27 ;
V_4 = F_1 ( F_11 ( V_14 ) ) ;
V_30 = & V_4 -> V_11 ;
V_20 = V_4 -> V_11 . V_20 ;
V_32 = F_14 ( V_30 -> V_11 , V_35 , V_36 ) ;
F_15 ( V_32 ) -> V_37 = V_38 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_18 = F_15 ( V_32 ) -> V_39 ;
if ( ! V_18 ) {
F_17 ( L_2 ,
V_4 -> V_3 -> V_40 ) ;
F_18 ( V_4 -> V_3 , 1 ) ;
F_19 (part_md, &md->part, part)
if ( V_28 -> V_41 == V_42 ) {
F_17 ( L_2 , V_28 -> V_3 -> V_40 ) ;
F_18 ( V_28 -> V_3 , 1 ) ;
}
}
F_5 ( V_4 ) ;
return V_27 ;
}
static T_1 F_20 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_18 ;
struct V_1 * V_4 = F_1 ( F_11 ( V_14 ) ) ;
V_18 = snprintf ( V_17 , V_26 , L_1 ,
F_21 ( F_11 ( V_14 ) ) ^
V_4 -> V_43 ) ;
F_5 ( V_4 ) ;
return V_18 ;
}
static T_1 F_22 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_2 V_27 )
{
int V_18 ;
char * V_44 ;
struct V_1 * V_4 = F_1 ( F_11 ( V_14 ) ) ;
unsigned long V_33 = F_23 ( V_17 , & V_44 , 0 ) ;
if ( V_44 == V_17 ) {
V_18 = - V_34 ;
goto V_45;
}
F_18 ( F_11 ( V_14 ) , V_33 || V_4 -> V_43 ) ;
V_18 = V_27 ;
V_45:
F_5 ( V_4 ) ;
return V_18 ;
}
static int F_24 ( struct V_46 * V_47 , T_3 V_48 )
{
struct V_1 * V_4 = F_1 ( V_47 -> V_49 ) ;
int V_18 = - V_50 ;
F_2 ( & V_51 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_25 ( V_47 ) ;
V_18 = 0 ;
if ( ( V_48 & V_52 ) && V_4 -> V_43 ) {
F_5 ( V_4 ) ;
V_18 = - V_53 ;
}
}
F_3 ( & V_51 ) ;
return V_18 ;
}
static void F_26 ( struct V_2 * V_3 , T_3 V_48 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_51 ) ;
F_5 ( V_4 ) ;
F_3 ( & V_51 ) ;
}
static int
F_27 ( struct V_46 * V_47 , struct V_54 * V_55 )
{
V_55 -> V_56 = F_28 ( V_47 -> V_49 ) / ( 4 * 16 ) ;
V_55 -> V_57 = 4 ;
V_55 -> V_58 = 16 ;
return 0 ;
}
static struct V_59 * F_29 (
struct V_60 T_4 * V_61 )
{
struct V_59 * V_62 ;
int V_63 ;
V_62 = F_30 ( sizeof( * V_62 ) , V_64 ) ;
if ( ! V_62 ) {
V_63 = - V_65 ;
goto V_45;
}
if ( F_31 ( & V_62 -> V_66 , V_61 , sizeof( V_62 -> V_66 ) ) ) {
V_63 = - V_67 ;
goto V_68;
}
V_62 -> V_69 = ( V_70 ) V_62 -> V_66 . V_71 * V_62 -> V_66 . V_72 ;
if ( V_62 -> V_69 > V_73 ) {
V_63 = - V_74 ;
goto V_68;
}
if ( ! V_62 -> V_69 ) {
V_62 -> V_17 = NULL ;
return V_62 ;
}
V_62 -> V_17 = F_30 ( V_62 -> V_69 , V_64 ) ;
if ( ! V_62 -> V_17 ) {
V_63 = - V_65 ;
goto V_68;
}
if ( F_31 ( V_62 -> V_17 , ( void T_4 * ) ( unsigned long )
V_62 -> V_66 . V_75 , V_62 -> V_69 ) ) {
V_63 = - V_67 ;
goto V_76;
}
return V_62 ;
V_76:
F_9 ( V_62 -> V_17 ) ;
V_68:
F_9 ( V_62 ) ;
V_45:
return F_32 ( V_63 ) ;
}
static int F_33 ( struct V_60 T_4 * V_77 ,
struct V_59 * V_62 )
{
struct V_60 * V_66 = & V_62 -> V_66 ;
if ( F_34 ( & ( V_77 -> V_78 ) , V_66 -> V_78 ,
sizeof( V_66 -> V_78 ) ) )
return - V_67 ;
if ( ! V_62 -> V_66 . V_79 ) {
if ( F_34 ( ( void T_4 * ) ( unsigned long ) V_66 -> V_75 ,
V_62 -> V_17 , V_62 -> V_69 ) )
return - V_67 ;
}
return 0 ;
}
static int F_35 ( struct V_19 * V_20 , T_5 * V_80 ,
T_5 V_81 )
{
int V_63 ;
T_5 V_82 = 0 ;
if ( ! V_80 || ! V_81 )
return - V_34 ;
do {
V_63 = F_36 ( V_20 , V_80 , 5 ) ;
if ( V_63 )
break;
if ( ! F_37 ( * V_80 ) &&
( F_38 ( * V_80 ) != V_83 ) )
break;
F_39 ( 1000 , 5000 ) ;
} while ( ++ V_82 < V_81 );
if ( V_82 == V_81 )
V_63 = - V_84 ;
return V_63 ;
}
static int F_40 ( struct V_19 * V_20 )
{
int V_63 ;
if ( ! F_41 ( V_20 ) ) {
F_42 ( L_3 ,
F_43 ( V_20 -> V_85 ) , V_86 ) ;
V_63 = - V_87 ;
goto V_45;
}
F_44 ( L_4 ,
F_43 ( V_20 -> V_85 ) , V_86 ) ;
V_63 = F_45 ( V_20 , V_88 ,
V_89 , 1 ,
V_90 ) ;
if ( V_63 )
F_46 ( L_5 ,
F_43 ( V_20 -> V_85 ) , V_86 , V_63 ) ;
F_44 ( L_6 , F_43 ( V_20 -> V_85 ) ,
V_86 ) ;
V_45:
return V_63 ;
}
static int F_47 ( struct V_19 * V_20 , struct V_1 * V_4 ,
struct V_59 * V_62 )
{
struct V_91 V_92 = {} ;
struct V_93 V_94 = {} ;
struct V_95 V_96 = {} ;
struct V_97 V_98 ;
int V_63 ;
bool V_99 = false ;
T_5 V_80 = 0 ;
if ( ! V_20 || ! V_4 || ! V_62 )
return - V_34 ;
if ( V_4 -> V_41 & V_100 )
V_99 = true ;
V_92 . V_101 = V_62 -> V_66 . V_101 ;
V_92 . V_102 = V_62 -> V_66 . V_102 ;
V_92 . V_103 = V_62 -> V_66 . V_103 ;
if ( V_62 -> V_69 ) {
V_94 . V_98 = & V_98 ;
V_94 . V_104 = 1 ;
V_94 . V_71 = V_62 -> V_66 . V_71 ;
V_94 . V_72 = V_62 -> V_66 . V_72 ;
F_48 ( V_94 . V_98 , V_62 -> V_17 , V_62 -> V_69 ) ;
if ( V_62 -> V_66 . V_79 )
V_94 . V_103 = V_105 ;
else
V_94 . V_103 = V_106 ;
F_49 ( & V_94 , V_20 ) ;
if ( V_62 -> V_66 . V_107 )
V_94 . V_108 = V_62 -> V_66 . V_107 ;
if ( ( V_92 . V_103 & V_109 ) == V_109 ) {
V_94 . V_108 = V_62 -> V_66 . V_110 * 1000000 ;
}
V_96 . V_94 = & V_94 ;
}
V_96 . V_92 = & V_92 ;
V_63 = F_50 ( V_20 , V_4 ) ;
if ( V_63 )
return V_63 ;
if ( V_62 -> V_66 . V_111 ) {
V_63 = F_51 ( V_20 -> V_85 , V_20 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_99 ) {
V_63 = F_52 ( V_20 , V_94 . V_72 ,
V_62 -> V_66 . V_79 & ( 1 << 31 ) ) ;
if ( V_63 )
return V_63 ;
}
if ( ( F_53 ( V_92 . V_102 ) == V_89 ) &&
( V_92 . V_101 == V_112 ) ) {
V_63 = F_40 ( V_20 ) ;
if ( V_63 )
F_46 ( L_7 ,
V_86 , V_63 ) ;
return V_63 ;
}
F_54 ( V_20 -> V_85 , & V_96 ) ;
if ( V_92 . error ) {
F_55 ( F_56 ( V_20 -> V_85 ) , L_8 ,
V_86 , V_92 . error ) ;
return V_92 . error ;
}
if ( V_94 . error ) {
F_55 ( F_56 ( V_20 -> V_85 ) , L_9 ,
V_86 , V_94 . error ) ;
return V_94 . error ;
}
if ( V_62 -> V_66 . V_113 )
F_39 ( V_62 -> V_66 . V_113 , V_62 -> V_66 . V_114 ) ;
memcpy ( & ( V_62 -> V_66 . V_78 ) , V_92 . V_115 , sizeof( V_92 . V_115 ) ) ;
if ( V_99 ) {
V_63 = F_35 ( V_20 , & V_80 , 5 ) ;
if ( V_63 )
F_55 ( F_56 ( V_20 -> V_85 ) ,
L_10 ,
V_86 , V_80 , V_63 ) ;
}
return V_63 ;
}
static int F_57 ( struct V_46 * V_47 ,
struct V_60 T_4 * V_77 )
{
struct V_59 * V_62 ;
struct V_59 * V_116 [ 1 ] ;
struct V_1 * V_4 ;
struct V_29 * V_30 ;
struct V_19 * V_20 ;
int V_63 = 0 , V_117 = 0 ;
struct V_31 * V_32 ;
if ( ( ! F_58 ( V_118 ) ) || ( V_47 != V_47 -> V_119 ) )
return - V_84 ;
V_62 = F_29 ( V_77 ) ;
if ( F_59 ( V_62 ) )
return F_60 ( V_62 ) ;
V_4 = F_1 ( V_47 -> V_49 ) ;
if ( ! V_4 ) {
V_63 = - V_34 ;
goto V_120;
}
V_20 = V_4 -> V_11 . V_20 ;
if ( F_59 ( V_20 ) ) {
V_63 = F_60 ( V_20 ) ;
goto V_121;
}
V_30 = & V_4 -> V_11 ;
V_32 = F_14 ( V_30 -> V_11 ,
V_62 -> V_66 . V_79 ? V_35 : V_122 ,
V_36 ) ;
V_116 [ 0 ] = V_62 ;
F_15 ( V_32 ) -> V_37 = V_123 ;
F_15 ( V_32 ) -> V_62 = V_116 ;
F_15 ( V_32 ) -> V_124 = 1 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_117 = F_15 ( V_32 ) -> V_39 ;
V_63 = F_33 ( V_77 , V_62 ) ;
F_61 ( V_32 ) ;
V_121:
F_5 ( V_4 ) ;
V_120:
F_9 ( V_62 -> V_17 ) ;
F_9 ( V_62 ) ;
return V_117 ? V_117 : V_63 ;
}
static int F_62 ( struct V_46 * V_47 ,
struct V_125 T_4 * V_61 )
{
struct V_59 * * V_62 = NULL ;
struct V_60 T_4 * V_126 = V_61 -> V_126 ;
struct V_19 * V_20 ;
struct V_1 * V_4 ;
struct V_29 * V_30 ;
int V_127 , V_63 = 0 , V_117 = 0 ;
T_6 V_128 ;
struct V_31 * V_32 ;
if ( ( ! F_58 ( V_118 ) ) || ( V_47 != V_47 -> V_119 ) )
return - V_84 ;
if ( F_31 ( & V_128 , & V_61 -> V_128 ,
sizeof( V_128 ) ) )
return - V_67 ;
if ( ! V_128 )
return 0 ;
if ( V_128 > V_129 )
return - V_34 ;
V_62 = F_63 ( V_128 , sizeof( * V_62 ) , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
V_62 [ V_127 ] = F_29 ( & V_126 [ V_127 ] ) ;
if ( F_59 ( V_62 [ V_127 ] ) ) {
V_63 = F_60 ( V_62 [ V_127 ] ) ;
V_128 = V_127 ;
goto V_120;
}
}
V_4 = F_1 ( V_47 -> V_49 ) ;
if ( ! V_4 ) {
V_63 = - V_34 ;
goto V_120;
}
V_20 = V_4 -> V_11 . V_20 ;
if ( F_59 ( V_20 ) ) {
V_63 = F_60 ( V_20 ) ;
goto V_121;
}
V_30 = & V_4 -> V_11 ;
V_32 = F_14 ( V_30 -> V_11 ,
V_62 [ 0 ] -> V_66 . V_79 ? V_35 : V_122 ,
V_36 ) ;
F_15 ( V_32 ) -> V_37 = V_123 ;
F_15 ( V_32 ) -> V_62 = V_62 ;
F_15 ( V_32 ) -> V_124 = V_128 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_117 = F_15 ( V_32 ) -> V_39 ;
for ( V_127 = 0 ; V_127 < V_128 && ! V_63 ; V_127 ++ )
V_63 = F_33 ( & V_126 [ V_127 ] , V_62 [ V_127 ] ) ;
F_61 ( V_32 ) ;
V_121:
F_5 ( V_4 ) ;
V_120:
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
F_9 ( V_62 [ V_127 ] -> V_17 ) ;
F_9 ( V_62 [ V_127 ] ) ;
}
F_9 ( V_62 ) ;
return V_117 ? V_117 : V_63 ;
}
static int F_64 ( struct V_46 * V_47 , T_3 V_48 ,
unsigned int V_92 , unsigned long V_102 )
{
switch ( V_92 ) {
case V_130 :
return F_57 ( V_47 ,
(struct V_60 T_4 * ) V_102 ) ;
case V_131 :
return F_62 ( V_47 ,
(struct V_125 T_4 * ) V_102 ) ;
default:
return - V_34 ;
}
}
static int F_65 ( struct V_46 * V_47 , T_3 V_48 ,
unsigned int V_92 , unsigned long V_102 )
{
return F_64 ( V_47 , V_48 , V_92 , ( unsigned long ) F_66 ( V_102 ) ) ;
}
static int F_67 ( struct V_19 * V_20 ,
unsigned int V_132 )
{
int V_18 = 0 ;
if ( V_132 == V_133 ) {
if ( V_20 -> V_22 . V_134 ) {
V_18 = F_68 ( V_20 ) ;
if ( V_18 )
return V_18 ;
}
F_69 ( V_20 -> V_85 ) ;
}
return V_18 ;
}
static int F_70 ( struct V_19 * V_20 ,
unsigned int V_132 )
{
int V_18 = 0 ;
if ( V_132 == V_133 ) {
F_71 ( V_20 -> V_85 ) ;
if ( V_20 -> V_135 && ! V_20 -> V_22 . V_134 )
V_18 = F_72 ( V_20 ) ;
}
return V_18 ;
}
static inline int F_50 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
int V_18 = 0 ;
struct V_1 * V_136 = F_73 ( & V_20 -> V_14 ) ;
if ( V_136 -> V_137 == V_4 -> V_132 )
return 0 ;
if ( F_74 ( V_20 ) ) {
T_7 V_138 = V_20 -> V_22 . V_138 ;
V_18 = F_67 ( V_20 , V_4 -> V_132 ) ;
if ( V_18 )
return V_18 ;
V_138 &= ~ V_139 ;
V_138 |= V_4 -> V_132 ;
V_18 = F_45 ( V_20 , V_88 ,
V_140 , V_138 ,
V_20 -> V_22 . V_141 ) ;
if ( V_18 ) {
F_70 ( V_20 , V_4 -> V_132 ) ;
return V_18 ;
}
V_20 -> V_22 . V_138 = V_138 ;
V_18 = F_70 ( V_20 , V_136 -> V_137 ) ;
}
V_136 -> V_137 = V_4 -> V_132 ;
return V_18 ;
}
static int F_75 ( struct V_19 * V_20 , T_5 * V_142 )
{
int V_63 ;
T_5 V_143 ;
T_8 * V_72 ;
struct V_95 V_96 = {} ;
struct V_91 V_92 = {} ;
struct V_93 V_94 = {} ;
struct V_97 V_98 ;
V_92 . V_101 = V_144 ;
V_92 . V_102 = V_20 -> V_145 << 16 ;
V_92 . V_103 = V_146 | V_147 | V_148 ;
V_63 = F_76 ( V_20 -> V_85 , & V_92 , 0 ) ;
if ( V_63 )
return V_63 ;
if ( ! F_77 ( V_20 -> V_85 ) && ! ( V_92 . V_115 [ 0 ] & V_149 ) )
return - V_150 ;
memset ( & V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 . V_101 = V_151 ;
V_92 . V_102 = 0 ;
V_92 . V_103 = V_146 | V_147 | V_152 ;
V_94 . V_71 = 4 ;
V_94 . V_72 = 1 ;
V_94 . V_103 = V_106 ;
V_94 . V_98 = & V_98 ;
V_94 . V_104 = 1 ;
F_49 ( & V_94 , V_20 ) ;
V_96 . V_92 = & V_92 ;
V_96 . V_94 = & V_94 ;
V_72 = F_30 ( 4 , V_64 ) ;
if ( ! V_72 )
return - V_65 ;
F_48 ( & V_98 , V_72 , 4 ) ;
F_54 ( V_20 -> V_85 , & V_96 ) ;
V_143 = F_78 ( * V_72 ) ;
F_9 ( V_72 ) ;
if ( V_92 . error || V_94 . error )
return - V_150 ;
* V_142 = V_143 ;
return 0 ;
}
static int F_79 ( struct V_19 * V_20 , unsigned int V_153 ,
bool V_154 , struct V_31 * V_32 , bool * V_155 )
{
unsigned long V_156 = V_157 + F_80 ( V_153 ) ;
int V_63 = 0 ;
T_5 V_80 ;
do {
V_63 = F_36 ( V_20 , & V_80 , 5 ) ;
if ( V_63 ) {
F_46 ( L_11 ,
V_32 -> V_158 -> V_40 , V_63 ) ;
return V_63 ;
}
if ( V_80 & V_159 ) {
F_46 ( L_12 ,
V_32 -> V_158 -> V_40 , V_86 , V_80 ) ;
* V_155 = true ;
}
if ( ( V_20 -> V_85 -> V_160 & V_161 ) &&
V_154 )
break;
if ( F_81 ( V_157 , V_156 ) ) {
F_46 ( L_13 ,
F_43 ( V_20 -> V_85 ) ,
V_32 -> V_158 -> V_40 , V_86 ) ;
return - V_162 ;
}
} while ( ! ( V_80 & V_163 ) ||
( F_38 ( V_80 ) == V_83 ) );
return V_63 ;
}
static int F_82 ( struct V_19 * V_20 , unsigned int V_153 ,
struct V_31 * V_32 , bool * V_155 , T_5 * V_164 )
{
struct V_165 * V_85 = V_20 -> V_85 ;
struct V_91 V_92 = {} ;
int V_63 ;
bool V_166 = F_83 ( V_32 ) == V_167 ;
if ( V_85 -> V_168 && ( V_153 > V_85 -> V_168 ) )
V_166 = false ;
V_92 . V_101 = V_169 ;
if ( V_166 ) {
V_92 . V_103 = V_170 | V_109 | V_148 ;
V_92 . V_171 = V_153 ;
} else {
V_92 . V_103 = V_146 | V_147 | V_148 ;
}
V_63 = F_76 ( V_85 , & V_92 , 5 ) ;
if ( V_63 )
return V_63 ;
* V_164 = V_92 . V_115 [ 0 ] ;
if ( F_83 ( V_32 ) == V_172 )
return 0 ;
if ( ! F_77 ( V_85 ) &&
( * V_164 & V_159 ) ) {
F_46 ( L_14 ,
V_32 -> V_158 -> V_40 , V_86 , * V_164 ) ;
* V_155 = true ;
}
return F_79 ( V_20 , V_153 , V_166 , V_32 , V_155 ) ;
}
static int F_84 ( struct V_31 * V_32 , const char * V_173 , int error ,
bool V_174 , T_5 V_80 )
{
switch ( error ) {
case - V_175 :
F_46 ( L_15 ,
V_32 -> V_158 -> V_40 , L_16 ,
V_173 , V_80 ) ;
return V_176 ;
case - V_162 :
F_46 ( L_15 ,
V_32 -> V_158 -> V_40 , L_17 , V_173 , V_80 ) ;
if ( ! V_174 ) {
F_46 ( L_18 ,
V_32 -> V_158 -> V_40 ) ;
return V_176 ;
}
if ( V_80 & ( V_177 | V_178 ) ) {
F_46 ( L_19 ,
V_32 -> V_158 -> V_40 ) ;
return V_176 ;
}
return V_179 ;
default:
F_46 ( L_20 ,
V_32 -> V_158 -> V_40 , error , V_80 ) ;
return V_179 ;
}
}
static int F_85 ( struct V_19 * V_20 , struct V_31 * V_32 ,
struct V_180 * V_181 , bool * V_182 , bool * V_155 )
{
bool V_183 = true ;
T_5 V_80 , V_164 = 0 ;
int V_63 , V_184 ;
if ( F_86 ( V_20 ) )
return V_185 ;
for ( V_184 = 2 ; V_184 >= 0 ; V_184 -- ) {
V_63 = F_36 ( V_20 , & V_80 , 0 ) ;
if ( ! V_63 )
break;
F_87 ( V_20 -> V_85 ) ;
V_183 = false ;
F_46 ( L_21 ,
V_32 -> V_158 -> V_40 , V_63 , V_184 ? L_22 : L_23 ) ;
}
if ( V_63 ) {
if ( F_88 ( V_20 -> V_85 ) )
return V_185 ;
return V_179 ;
}
if ( ( V_80 & V_186 ) ||
( V_181 -> V_187 . V_115 [ 0 ] & V_186 ) ||
( V_181 -> V_92 . V_115 [ 0 ] & V_186 ) )
* V_182 = true ;
if ( ! F_77 ( V_20 -> V_85 ) && F_83 ( V_32 ) != V_172 )
if ( ( V_80 & V_159 ) ||
( V_181 -> V_187 . V_115 [ 0 ] & V_159 ) ) {
F_46 ( L_24 ,
V_32 -> V_158 -> V_40 , V_86 ,
V_181 -> V_187 . V_115 [ 0 ] , V_80 ) ;
* V_155 = true ;
}
if ( F_38 ( V_80 ) == V_188 ||
F_38 ( V_80 ) == V_189 ) {
V_63 = F_82 ( V_20 ,
F_89 ( V_181 -> V_94 . V_108 , 1000000 ) ,
V_32 , V_155 , & V_164 ) ;
if ( V_63 ) {
F_46 ( L_25 ,
V_32 -> V_158 -> V_40 , V_63 ) ;
return V_179 ;
}
if ( V_164 & V_186 )
* V_182 = true ;
}
if ( V_181 -> V_190 . error )
return F_84 ( V_32 , L_26 , V_181 -> V_190 . error ,
V_183 , V_80 ) ;
if ( V_181 -> V_92 . error )
return F_84 ( V_32 , L_27 , V_181 -> V_92 . error ,
V_183 , V_80 ) ;
if ( ! V_181 -> V_187 . error )
return V_191 ;
F_17 ( L_28 ,
V_32 -> V_158 -> V_40 , V_181 -> V_187 . error ,
V_181 -> V_92 . V_115 [ 0 ] , V_80 ) ;
if ( V_164 ) {
V_181 -> V_187 . V_115 [ 0 ] = V_164 ;
V_181 -> V_187 . error = 0 ;
}
return V_191 ;
}
static int F_90 ( struct V_1 * V_4 , struct V_165 * V_85 ,
int type )
{
int V_63 ;
if ( V_4 -> V_192 & type )
return - V_193 ;
V_4 -> V_192 |= type ;
V_63 = F_91 ( V_85 ) ;
if ( V_63 != - V_87 ) {
struct V_1 * V_136 =
F_73 ( & V_85 -> V_20 -> V_14 ) ;
int V_194 ;
V_136 -> V_137 = V_136 -> V_132 ;
V_194 = F_50 ( V_85 -> V_20 , V_4 ) ;
if ( V_194 ) {
return - V_195 ;
}
}
return V_63 ;
}
static inline void F_92 ( struct V_1 * V_4 , int type )
{
V_4 -> V_192 &= ~ type ;
}
int F_93 ( struct V_29 * V_30 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
if ( V_4 && V_4 -> V_132 == V_133 )
return true ;
return false ;
}
static void F_94 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_197 * V_198 ;
struct V_19 * V_20 = V_30 -> V_20 ;
struct V_1 * V_4 = V_30 -> V_196 ;
int V_18 ;
int V_127 ;
V_198 = F_15 ( V_32 ) ;
switch ( V_198 -> V_37 ) {
case V_123 :
for ( V_127 = 0 , V_18 = 0 ; V_127 < V_198 -> V_124 ; V_127 ++ ) {
V_18 = F_47 ( V_20 , V_4 , V_198 -> V_62 [ V_127 ] ) ;
if ( V_18 )
break;
}
if ( V_4 -> V_41 & V_100 )
F_50 ( V_20 , F_73 ( & V_20 -> V_14 ) ) ;
break;
case V_38 :
V_18 = F_45 ( V_20 , V_88 , V_199 ,
V_20 -> V_22 . V_23 |
V_25 ,
V_20 -> V_22 . V_141 ) ;
if ( V_18 )
F_46 ( L_29 ,
V_4 -> V_3 -> V_40 , V_18 ) ;
else
V_20 -> V_22 . V_23 |=
V_25 ;
break;
default:
F_46 ( L_30 ,
V_4 -> V_3 -> V_40 ) ;
V_18 = - V_34 ;
break;
}
V_198 -> V_39 = V_18 ;
F_95 ( V_32 , V_18 ? V_200 : V_201 ) ;
}
static void F_96 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_202 , V_203 , V_102 ;
int V_63 = 0 , type = V_204 ;
T_9 V_80 = V_201 ;
if ( ! F_97 ( V_20 ) ) {
V_80 = V_205 ;
goto V_206;
}
V_202 = F_98 ( V_32 ) ;
V_203 = F_99 ( V_32 ) ;
if ( F_100 ( V_20 ) )
V_102 = V_207 ;
else if ( F_101 ( V_20 ) )
V_102 = V_208 ;
else
V_102 = V_209 ;
do {
V_63 = 0 ;
if ( V_20 -> V_210 & V_211 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_212 ,
V_102 == V_208 ?
V_213 :
V_214 ,
0 ) ;
}
if ( ! V_63 )
V_63 = F_102 ( V_20 , V_202 , V_203 , V_102 ) ;
} while ( V_63 == - V_150 && ! F_90 ( V_4 , V_20 -> V_85 , type ) );
if ( V_63 )
V_80 = V_200 ;
else
F_92 ( V_4 , type ) ;
V_206:
F_103 ( V_32 , V_80 , F_104 ( V_32 ) ) ;
}
static void F_105 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_202 , V_203 , V_102 ;
int V_63 = 0 , type = V_215 ;
T_9 V_80 = V_201 ;
if ( ! ( F_106 ( V_20 ) ) ) {
V_80 = V_205 ;
goto V_45;
}
V_202 = F_98 ( V_32 ) ;
V_203 = F_99 ( V_32 ) ;
if ( F_101 ( V_20 ) && ! F_107 ( V_20 , V_202 , V_203 ) )
V_102 = V_216 ;
else
V_102 = V_217 ;
V_184:
if ( V_20 -> V_210 & V_211 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_212 ,
V_102 == V_216 ?
V_218 :
V_219 ,
0 ) ;
if ( V_63 )
goto V_220;
}
V_63 = F_102 ( V_20 , V_202 , V_203 , V_102 ) ;
if ( V_63 == - V_150 )
goto V_220;
if ( V_63 ) {
V_80 = V_200 ;
goto V_45;
}
if ( V_102 == V_216 ) {
if ( V_20 -> V_210 & V_211 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_212 ,
V_221 ,
0 ) ;
if ( V_63 )
goto V_220;
}
V_63 = F_102 ( V_20 , V_202 , V_203 , V_222 ) ;
if ( V_63 == - V_150 )
goto V_220;
if ( V_63 ) {
V_80 = V_200 ;
goto V_45;
}
}
V_220:
if ( V_63 && ! F_90 ( V_4 , V_20 -> V_85 , type ) )
goto V_184;
if ( ! V_63 )
F_92 ( V_4 , type ) ;
V_45:
F_103 ( V_32 , V_80 , F_104 ( V_32 ) ) ;
}
static void F_108 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
int V_18 = 0 ;
V_18 = F_109 ( V_20 ) ;
F_95 ( V_32 , V_18 ? V_200 : V_201 ) ;
}
static inline void F_110 ( struct V_180 * V_181 ,
struct V_19 * V_20 ,
struct V_31 * V_32 )
{
if ( ! ( V_20 -> V_22 . V_223 & V_224 ) ) {
if ( ! F_111 ( F_98 ( V_32 ) , V_20 -> V_22 . V_225 ) )
V_181 -> V_94 . V_72 = 1 ;
if ( V_181 -> V_94 . V_72 > V_20 -> V_22 . V_225 )
V_181 -> V_94 . V_72 = V_20 -> V_22 . V_225 ;
else if ( V_181 -> V_94 . V_72 < V_20 -> V_22 . V_225 )
V_181 -> V_94 . V_72 = 1 ;
}
}
static void F_112 ( struct V_180 * V_181 )
{
T_5 V_226 ;
if ( ! V_181 -> V_187 . error ) {
bool V_227 ;
V_226 = V_181 -> V_187 . V_115 [ 0 ] & V_228 ;
V_227 = V_226 & V_229 && ! V_181 -> V_96 . V_190 ;
if ( V_226 && ! V_227 )
V_181 -> V_187 . error = - V_150 ;
}
}
static enum V_230 F_113 ( struct V_19 * V_20 ,
struct V_231 * V_232 )
{
struct V_197 * V_233 = F_114 ( V_232 , struct V_197 ,
V_232 ) ;
struct V_180 * V_181 = & V_233 -> V_181 ;
struct V_31 * V_32 = F_115 ( V_233 ) ;
int V_234 = V_20 -> V_85 -> V_234 ;
bool V_182 = false ;
bool V_155 = false ;
F_112 ( V_181 ) ;
if ( V_181 -> V_190 . error || V_181 -> V_92 . error ||
V_181 -> V_187 . error || V_181 -> V_94 . error ) {
switch ( F_85 ( V_20 , V_32 , V_181 , & V_182 , & V_155 ) ) {
case V_176 :
return V_235 ;
case V_179 :
return V_236 ;
case V_185 :
return V_237 ;
case V_191 :
break;
}
}
if ( V_181 -> V_92 . V_115 [ 0 ] & V_228 ) {
F_46 ( L_31 ,
V_32 -> V_158 -> V_40 , V_181 -> V_92 . V_115 [ 0 ] ) ;
return V_236 ;
}
if ( ! F_77 ( V_20 -> V_85 ) && F_83 ( V_32 ) != V_172 ) {
int V_63 ;
if ( V_181 -> V_187 . V_115 [ 0 ] & V_159 ) {
F_46 ( L_32 ,
V_32 -> V_158 -> V_40 , V_86 ,
V_181 -> V_187 . V_115 [ 0 ] ) ;
V_155 = true ;
}
V_63 = F_79 ( V_20 , V_238 , false , V_32 ,
& V_155 ) ;
if ( V_63 )
return V_239 ;
}
if ( V_155 ) {
F_42 ( L_33 ,
V_32 -> V_158 -> V_40 ) ;
return V_235 ;
}
if ( V_181 -> V_94 . error || V_181 -> V_187 . error ) {
if ( V_234 && ! V_181 -> V_240 ) {
F_44 ( L_34 ,
V_32 -> V_158 -> V_40 ) ;
V_181 -> V_240 = 1 ;
return V_235 ;
}
F_46 ( L_35 ,
V_32 -> V_158 -> V_40 , V_181 -> V_94 . error ? : V_181 -> V_187 . error ,
( unsigned ) F_98 ( V_32 ) ,
( unsigned ) F_99 ( V_32 ) ,
V_181 -> V_92 . V_115 [ 0 ] , V_181 -> V_187 . V_115 [ 0 ] ) ;
if ( F_83 ( V_32 ) == V_172 ) {
if ( V_182 )
return V_241 ;
return V_242 ;
} else {
return V_239 ;
}
}
if ( ! V_181 -> V_94 . V_243 )
return V_235 ;
if ( F_104 ( V_32 ) != V_181 -> V_94 . V_243 )
return V_244 ;
return V_245 ;
}
static void F_116 ( struct V_29 * V_30 , struct V_197 * V_246 ,
int V_247 , bool * V_248 ,
bool * V_249 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
struct V_180 * V_181 = & V_246 -> V_181 ;
struct V_31 * V_32 = F_115 ( V_246 ) ;
* V_248 = ( V_32 -> V_250 & V_251 ) &&
F_83 ( V_32 ) == V_167 &&
( V_4 -> V_103 & V_252 ) ;
memset ( V_181 , 0 , sizeof( struct V_180 ) ) ;
V_181 -> V_96 . V_94 = & V_181 -> V_94 ;
V_181 -> V_187 . V_101 = V_169 ;
V_181 -> V_187 . V_102 = 0 ;
if ( F_83 ( V_32 ) == V_172 ) {
V_181 -> V_94 . V_103 = V_106 ;
V_181 -> V_187 . V_103 = V_146 | V_147 | V_148 ;
} else {
V_181 -> V_94 . V_103 = V_105 ;
V_181 -> V_187 . V_103 = V_170 | V_109 | V_148 ;
}
V_181 -> V_94 . V_71 = 512 ;
V_181 -> V_94 . V_72 = F_99 ( V_32 ) ;
if ( V_181 -> V_94 . V_72 > V_20 -> V_85 -> V_253 )
V_181 -> V_94 . V_72 = V_20 -> V_85 -> V_253 ;
if ( V_181 -> V_94 . V_72 > 1 ) {
if ( V_247 )
V_181 -> V_94 . V_72 = 1 ;
if ( V_20 -> V_85 -> V_254 -> V_255 )
V_181 -> V_94 . V_72 = V_20 -> V_85 -> V_254 -> V_255 ( V_20 ,
( F_83 ( V_32 ) == V_172 ) ?
V_106 : V_105 ,
V_181 -> V_94 . V_72 ) ;
}
if ( * V_248 )
F_110 ( V_181 , V_20 , V_32 ) ;
* V_249 = V_20 -> V_22 . V_256 &&
( V_32 -> V_250 & V_257 ) &&
( F_83 ( V_32 ) == V_167 ) &&
( ( V_181 -> V_94 . V_72 * V_181 -> V_94 . V_71 ) >=
V_20 -> V_22 . V_256 ) ;
F_49 ( & V_181 -> V_94 , V_20 ) ;
V_181 -> V_94 . V_98 = V_246 -> V_98 ;
V_181 -> V_94 . V_104 = F_117 ( V_30 , V_246 ) ;
if ( V_181 -> V_94 . V_72 != F_99 ( V_32 ) ) {
int V_127 , V_258 = V_181 -> V_94 . V_72 << 9 ;
struct V_97 * V_98 ;
F_118 (brq->data.sg, sg, brq->data.sg_len, i) {
V_258 -= V_98 -> V_259 ;
if ( V_258 <= 0 ) {
V_98 -> V_259 += V_258 ;
V_127 ++ ;
break;
}
}
V_181 -> V_94 . V_104 = V_127 ;
}
V_246 -> V_232 . V_96 = & V_181 -> V_96 ;
F_119 ( V_246 ) ;
}
static void F_120 ( struct V_197 * V_246 ,
struct V_19 * V_20 ,
int V_247 ,
struct V_29 * V_30 )
{
T_5 V_260 , V_261 ;
struct V_180 * V_181 = & V_246 -> V_181 ;
struct V_31 * V_32 = F_115 ( V_246 ) ;
struct V_1 * V_4 = V_30 -> V_196 ;
bool V_248 , V_249 ;
F_116 ( V_30 , V_246 , V_247 , & V_248 , & V_249 ) ;
V_181 -> V_96 . V_92 = & V_181 -> V_92 ;
V_181 -> V_92 . V_102 = F_98 ( V_32 ) ;
if ( ! F_121 ( V_20 ) )
V_181 -> V_92 . V_102 <<= 9 ;
V_181 -> V_92 . V_103 = V_146 | V_147 | V_152 ;
if ( V_181 -> V_94 . V_72 > 1 || V_248 ) {
if ( ! F_77 ( V_20 -> V_85 ) ||
F_83 ( V_32 ) == V_172 )
V_181 -> V_96 . V_187 = & V_181 -> V_187 ;
V_260 = V_262 ;
V_261 = V_263 ;
} else {
V_181 -> V_96 . V_187 = NULL ;
V_260 = V_264 ;
V_261 = V_265 ;
}
V_181 -> V_92 . V_101 = F_83 ( V_32 ) == V_172 ? V_260 : V_261 ;
if ( ( V_4 -> V_103 & V_266 ) && F_122 ( V_181 -> V_92 . V_101 ) &&
( V_248 || ! ( V_20 -> V_210 & V_267 ) ||
V_249 ) ) {
V_181 -> V_190 . V_101 = V_268 ;
V_181 -> V_190 . V_102 = V_181 -> V_94 . V_72 |
( V_248 ? ( 1 << 31 ) : 0 ) |
( V_249 ? ( 1 << 29 ) : 0 ) ;
V_181 -> V_190 . V_103 = V_147 | V_148 ;
V_181 -> V_96 . V_190 = & V_181 -> V_190 ;
}
V_246 -> V_232 . V_269 = F_113 ;
}
static bool F_123 ( struct V_1 * V_4 , struct V_19 * V_20 ,
struct V_180 * V_181 , struct V_31 * V_32 ,
bool V_270 )
{
bool V_271 ;
if ( F_124 ( V_20 ) ) {
T_5 V_72 ;
int V_63 ;
V_63 = F_75 ( V_20 , & V_72 ) ;
if ( V_63 )
V_271 = V_270 ;
else
V_271 = F_103 ( V_32 , V_201 , V_72 << 9 ) ;
} else {
V_271 = F_103 ( V_32 , V_201 , V_181 -> V_94 . V_243 ) ;
}
return V_271 ;
}
static void F_125 ( struct V_29 * V_30 , struct V_19 * V_20 ,
struct V_31 * V_32 ,
struct V_197 * V_246 )
{
if ( F_86 ( V_20 ) )
V_32 -> V_272 |= V_273 ;
while ( F_103 ( V_32 , V_200 , F_126 ( V_32 ) ) ) ;
V_30 -> V_274 -- ;
}
static void F_127 ( struct V_29 * V_30 , struct V_31 * V_32 ,
struct V_197 * V_246 )
{
if ( ! V_32 )
return;
if ( F_86 ( V_30 -> V_20 ) ) {
V_32 -> V_272 |= V_273 ;
F_95 ( V_32 , V_200 ) ;
V_30 -> V_274 -- ;
return;
}
F_120 ( V_246 , V_30 -> V_20 , 0 , V_30 ) ;
F_128 ( V_30 -> V_20 -> V_85 , & V_246 -> V_232 , NULL ) ;
}
static void F_129 ( struct V_29 * V_30 , struct V_31 * V_275 )
{
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
struct V_180 * V_181 ;
int V_247 = 0 , V_184 = 0 , type , V_240 = 0 ;
enum V_230 V_80 ;
struct V_197 * V_276 = NULL ;
struct V_197 * V_198 ;
struct V_31 * V_277 ;
struct V_231 * V_278 ;
struct V_231 * V_279 ;
bool V_271 = true ;
if ( V_275 ) {
V_276 = F_15 ( V_275 ) ;
V_30 -> V_274 ++ ;
}
if ( ! V_30 -> V_274 )
return;
do {
if ( V_275 ) {
if ( F_130 ( V_20 ) &&
! F_111 ( F_99 ( V_275 ) , 8 ) ) {
F_46 ( L_36 ,
V_275 -> V_158 -> V_40 ) ;
F_125 ( V_30 , V_20 , V_275 , V_276 ) ;
return;
}
F_120 ( V_276 , V_20 , 0 , V_30 ) ;
V_278 = & V_276 -> V_232 ;
} else
V_278 = NULL ;
V_279 = F_128 ( V_20 -> V_85 , V_278 , & V_80 ) ;
if ( ! V_279 ) {
return;
}
V_198 = F_114 ( V_279 , struct V_197 , V_232 ) ;
V_181 = & V_198 -> V_181 ;
V_277 = F_115 ( V_198 ) ;
type = F_83 ( V_277 ) == V_172 ? V_280 : V_281 ;
F_131 ( V_198 ) ;
switch ( V_80 ) {
case V_245 :
case V_244 :
F_92 ( V_4 , type ) ;
V_271 = F_103 ( V_277 , V_201 ,
V_181 -> V_94 . V_243 ) ;
if ( V_80 == V_245 && V_271 ) {
F_46 ( L_37 ,
V_86 , F_104 ( V_277 ) ,
V_181 -> V_94 . V_243 ) ;
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
return;
}
break;
case V_239 :
V_271 = F_123 ( V_4 , V_20 , V_181 , V_277 , V_271 ) ;
if ( F_90 ( V_4 , V_20 -> V_85 , type ) ) {
if ( V_271 )
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
else
V_30 -> V_274 -- ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
}
if ( ! V_271 ) {
V_30 -> V_274 -- ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
}
break;
case V_235 :
V_240 = V_181 -> V_240 ;
if ( V_184 ++ < 5 )
break;
case V_236 :
if ( ! F_90 ( V_4 , V_20 -> V_85 , type ) )
break;
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
case V_242 : {
int V_63 ;
V_63 = F_90 ( V_4 , V_20 -> V_85 , type ) ;
if ( ! V_63 )
break;
if ( V_63 == - V_195 ) {
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
}
}
case V_241 :
if ( V_181 -> V_94 . V_72 > 1 ) {
F_42 ( L_38 ,
V_277 -> V_158 -> V_40 ) ;
V_247 = 1 ;
break;
}
V_271 = F_103 ( V_277 , V_200 ,
V_181 -> V_94 . V_71 ) ;
if ( ! V_271 ) {
V_30 -> V_274 -- ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
}
break;
case V_237 :
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
default:
F_46 ( L_39 ,
V_277 -> V_158 -> V_40 , V_80 ) ;
F_125 ( V_30 , V_20 , V_277 , V_198 ) ;
F_127 ( V_30 , V_275 , V_276 ) ;
return;
}
if ( V_271 ) {
F_120 ( V_198 , V_20 ,
V_247 , V_30 ) ;
F_128 ( V_20 -> V_85 ,
& V_198 -> V_232 , NULL ) ;
V_198 -> V_181 . V_240 = V_240 ;
}
} while ( V_271 );
V_30 -> V_274 -- ;
}
void F_132 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
int V_18 ;
struct V_1 * V_4 = V_30 -> V_196 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
if ( V_32 && ! V_30 -> V_274 )
F_133 ( V_20 ) ;
V_18 = F_50 ( V_20 , V_4 ) ;
if ( V_18 ) {
if ( V_32 ) {
F_95 ( V_32 , V_200 ) ;
}
goto V_45;
}
if ( V_32 ) {
switch ( F_134 ( V_32 ) ) {
case V_122 :
case V_35 :
if ( V_30 -> V_274 )
F_129 ( V_30 , NULL ) ;
F_94 ( V_30 , V_32 ) ;
break;
case V_282 :
if ( V_30 -> V_274 )
F_129 ( V_30 , NULL ) ;
F_96 ( V_30 , V_32 ) ;
break;
case V_283 :
if ( V_30 -> V_274 )
F_129 ( V_30 , NULL ) ;
F_105 ( V_30 , V_32 ) ;
break;
case V_284 :
if ( V_30 -> V_274 )
F_129 ( V_30 , NULL ) ;
F_108 ( V_30 , V_32 ) ;
break;
default:
F_129 ( V_30 , V_32 ) ;
V_20 -> V_85 -> V_285 . V_286 = false ;
break;
}
} else {
F_129 ( V_30 , NULL ) ;
V_20 -> V_85 -> V_285 . V_286 = false ;
}
V_45:
if ( ! V_30 -> V_274 )
F_135 ( V_20 ) ;
}
static inline int F_136 ( struct V_19 * V_20 )
{
return F_137 ( V_20 ) ||
! ( V_20 -> V_287 . V_288 & V_289 ) ;
}
static struct V_1 * F_138 ( struct V_19 * V_20 ,
struct V_13 * V_290 ,
T_10 V_291 ,
bool V_292 ,
const char * V_293 ,
int V_41 )
{
struct V_1 * V_4 ;
int V_8 , V_18 ;
V_8 = F_139 ( & V_12 , 0 , V_294 , V_64 ) ;
if ( V_8 < 0 )
return F_32 ( V_8 ) ;
V_4 = F_140 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_4 ) {
V_18 = - V_65 ;
goto V_45;
}
V_4 -> V_41 = V_41 ;
V_4 -> V_43 = F_136 ( V_20 ) ;
V_4 -> V_3 = F_141 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_18 = - V_65 ;
goto V_295;
}
F_142 ( & V_4 -> V_296 ) ;
F_143 ( & V_4 -> V_297 ) ;
V_4 -> V_7 = 1 ;
V_18 = F_144 ( & V_4 -> V_11 , V_20 , & V_4 -> V_296 , V_293 ) ;
if ( V_18 )
goto V_298;
V_4 -> V_11 . V_196 = V_4 ;
V_4 -> V_3 -> V_299 = V_300 ;
V_4 -> V_3 -> V_9 = V_8 * V_10 ;
V_4 -> V_3 -> V_301 = & V_302 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_11 = V_4 -> V_11 . V_11 ;
V_4 -> V_290 = V_290 ;
F_18 ( V_4 -> V_3 , V_4 -> V_43 || V_292 ) ;
V_4 -> V_3 -> V_103 = V_303 ;
if ( V_41 & ( V_100 | V_42 ) )
V_4 -> V_3 -> V_103 |= V_304 ;
snprintf ( V_4 -> V_3 -> V_40 , sizeof( V_4 -> V_3 -> V_40 ) ,
L_40 , V_20 -> V_85 -> V_305 , V_293 ? V_293 : L_41 ) ;
if ( F_74 ( V_20 ) )
F_145 ( V_4 -> V_11 . V_11 ,
V_20 -> V_22 . V_306 ) ;
else
F_145 ( V_4 -> V_11 . V_11 , 512 ) ;
F_146 ( V_4 -> V_3 , V_291 ) ;
if ( F_147 ( V_20 -> V_85 ) ) {
if ( ( F_74 ( V_20 ) &&
V_20 -> V_287 . V_307 >= V_308 ) ||
( F_124 ( V_20 ) &&
V_20 -> V_309 . V_126 & V_310 ) )
V_4 -> V_103 |= V_266 ;
}
if ( F_74 ( V_20 ) &&
V_4 -> V_103 & V_266 &&
( ( V_20 -> V_22 . V_223 & V_224 ) ||
V_20 -> V_22 . V_225 ) ) {
V_4 -> V_103 |= V_252 ;
F_148 ( V_4 -> V_11 . V_11 , true , true ) ;
}
return V_4 ;
V_298:
F_8 ( V_4 -> V_3 ) ;
V_295:
F_9 ( V_4 ) ;
V_45:
F_7 ( & V_12 , V_8 ) ;
return F_32 ( V_18 ) ;
}
static struct V_1 * F_149 ( struct V_19 * V_20 )
{
T_10 V_291 ;
if ( ! F_124 ( V_20 ) && F_121 ( V_20 ) ) {
V_291 = V_20 -> V_22 . V_58 ;
} else {
V_291 = ( F_150 ( T_10 ) ) V_20 -> V_287 . V_311
<< ( V_20 -> V_287 . V_312 - 9 ) ;
}
return F_138 ( V_20 , & V_20 -> V_14 , V_291 , false , NULL ,
V_313 ) ;
}
static int F_151 ( struct V_19 * V_20 ,
struct V_1 * V_4 ,
unsigned int V_132 ,
T_10 V_291 ,
bool V_292 ,
const char * V_293 ,
int V_41 )
{
char V_314 [ 10 ] ;
struct V_1 * V_28 ;
V_28 = F_138 ( V_20 , F_152 ( V_4 -> V_3 ) , V_291 , V_292 ,
V_293 , V_41 ) ;
if ( F_59 ( V_28 ) )
return F_60 ( V_28 ) ;
V_28 -> V_132 = V_132 ;
F_153 ( & V_28 -> V_297 , & V_4 -> V_297 ) ;
F_154 ( ( V_70 ) F_28 ( V_28 -> V_3 ) , 512 , V_315 ,
V_314 , sizeof( V_314 ) ) ;
F_17 ( L_42 ,
V_28 -> V_3 -> V_40 , F_155 ( V_20 ) ,
F_156 ( V_20 ) , V_28 -> V_132 , V_314 ) ;
return 0 ;
}
static int F_157 ( struct V_19 * V_20 , struct V_1 * V_4 )
{
int V_316 , V_18 = 0 ;
if ( ! F_74 ( V_20 ) )
return 0 ;
for ( V_316 = 0 ; V_316 < V_20 -> V_317 ; V_316 ++ ) {
if ( V_20 -> V_297 [ V_316 ] . V_291 ) {
V_18 = F_151 ( V_20 , V_4 ,
V_20 -> V_297 [ V_316 ] . V_318 ,
V_20 -> V_297 [ V_316 ] . V_291 >> 9 ,
V_20 -> V_297 [ V_316 ] . V_319 ,
V_20 -> V_297 [ V_316 ] . V_173 ,
V_20 -> V_297 [ V_316 ] . V_41 ) ;
if ( V_18 )
return V_18 ;
}
}
return V_18 ;
}
static void F_158 ( struct V_1 * V_4 )
{
struct V_19 * V_20 ;
if ( V_4 ) {
V_20 = V_4 -> V_11 . V_20 ;
F_159 ( V_4 -> V_11 . V_11 -> V_320 ) ;
F_160 ( V_321 , V_4 -> V_11 . V_11 ) ;
F_161 ( V_4 -> V_11 . V_11 -> V_320 ) ;
F_162 ( V_4 -> V_11 . V_11 ) ;
F_163 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_3 -> V_103 & V_322 ) {
F_164 ( F_152 ( V_4 -> V_3 ) , & V_4 -> V_319 ) ;
if ( ( V_4 -> V_41 & V_42 ) &&
V_20 -> V_22 . V_323 )
F_164 ( F_152 ( V_4 -> V_3 ) ,
& V_4 -> V_324 ) ;
F_165 ( V_4 -> V_3 ) ;
}
F_5 ( V_4 ) ;
}
}
static void F_166 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
struct V_325 * V_326 , * V_327 ;
struct V_1 * V_28 ;
F_167 (pos, q, &md->part) {
V_28 = F_168 ( V_326 , struct V_1 , V_297 ) ;
F_169 ( V_326 ) ;
F_158 ( V_28 ) ;
}
}
static int F_170 ( struct V_1 * V_4 )
{
int V_18 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
F_171 ( V_4 -> V_290 , V_4 -> V_3 ) ;
V_4 -> V_319 . V_328 = F_20 ;
V_4 -> V_319 . V_329 = F_22 ;
F_172 ( & V_4 -> V_319 . V_16 ) ;
V_4 -> V_319 . V_16 . V_173 = L_43 ;
V_4 -> V_319 . V_16 . V_48 = V_330 | V_331 ;
V_18 = F_173 ( F_152 ( V_4 -> V_3 ) , & V_4 -> V_319 ) ;
if ( V_18 )
goto V_332;
if ( ( V_4 -> V_41 & V_42 ) &&
V_20 -> V_22 . V_323 ) {
T_11 V_48 ;
if ( V_20 -> V_22 . V_23 & V_333 )
V_48 = V_330 ;
else
V_48 = V_330 | V_331 ;
V_4 -> V_324 . V_328 = F_10 ;
V_4 -> V_324 . V_329 = F_12 ;
F_172 ( & V_4 -> V_324 . V_16 ) ;
V_4 -> V_324 . V_16 . V_48 = V_48 ;
V_4 -> V_324 . V_16 . V_173 =
L_44 ;
V_18 = F_173 ( F_152 ( V_4 -> V_3 ) ,
& V_4 -> V_324 ) ;
if ( V_18 )
goto V_334;
}
return V_18 ;
V_334:
F_164 ( F_152 ( V_4 -> V_3 ) , & V_4 -> V_319 ) ;
V_332:
F_165 ( V_4 -> V_3 ) ;
return V_18 ;
}
static int F_174 ( struct V_19 * V_20 )
{
struct V_1 * V_4 , * V_28 ;
char V_314 [ 10 ] ;
if ( ! ( V_20 -> V_287 . V_288 & V_335 ) )
return - V_195 ;
F_175 ( V_20 , V_336 ) ;
V_4 = F_149 ( V_20 ) ;
if ( F_59 ( V_4 ) )
return F_60 ( V_4 ) ;
F_154 ( ( V_70 ) F_28 ( V_4 -> V_3 ) , 512 , V_315 ,
V_314 , sizeof( V_314 ) ) ;
F_17 ( L_45 ,
V_4 -> V_3 -> V_40 , F_155 ( V_20 ) , F_156 ( V_20 ) ,
V_314 , V_4 -> V_43 ? L_46 : L_41 ) ;
if ( F_157 ( V_20 , V_4 ) )
goto V_45;
F_176 ( & V_20 -> V_14 , V_4 ) ;
if ( F_170 ( V_4 ) )
goto V_45;
F_19 (part_md, &md->part, part) {
if ( F_170 ( V_28 ) )
goto V_45;
}
F_177 ( & V_20 -> V_14 , 3000 ) ;
F_178 ( & V_20 -> V_14 ) ;
if ( V_20 -> type != V_337 ) {
F_179 ( & V_20 -> V_14 ) ;
F_180 ( & V_20 -> V_14 ) ;
}
return 0 ;
V_45:
F_166 ( V_20 , V_4 ) ;
F_158 ( V_4 ) ;
return 0 ;
}
static void F_181 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_73 ( & V_20 -> V_14 ) ;
F_166 ( V_20 , V_4 ) ;
F_182 ( & V_20 -> V_14 ) ;
F_183 ( V_20 -> V_85 ) ;
F_50 ( V_20 , V_4 ) ;
F_184 ( V_20 -> V_85 ) ;
if ( V_20 -> type != V_337 )
F_185 ( & V_20 -> V_14 ) ;
F_186 ( & V_20 -> V_14 ) ;
F_158 ( V_4 ) ;
F_176 ( & V_20 -> V_14 , NULL ) ;
}
static int F_187 ( struct V_19 * V_20 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_73 ( & V_20 -> V_14 ) ;
if ( V_4 ) {
F_188 ( & V_4 -> V_11 ) ;
F_19 (part_md, &md->part, part) {
F_188 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static void F_189 ( struct V_19 * V_20 )
{
F_187 ( V_20 ) ;
}
static int F_190 ( struct V_13 * V_14 )
{
struct V_19 * V_20 = F_191 ( V_14 ) ;
return F_187 ( V_20 ) ;
}
static int F_192 ( struct V_13 * V_14 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_73 ( V_14 ) ;
if ( V_4 ) {
V_4 -> V_137 = V_4 -> V_132 ;
F_193 ( & V_4 -> V_11 ) ;
F_19 (part_md, &md->part, part) {
F_193 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static int T_12 F_194 ( void )
{
int V_338 ;
if ( V_10 != V_339 )
F_17 ( L_47 , V_10 ) ;
V_294 = F_195 ( V_340 , ( 1 << V_341 ) / V_10 ) ;
V_338 = F_196 ( V_300 , L_48 ) ;
if ( V_338 )
goto V_45;
V_338 = F_197 ( & V_342 ) ;
if ( V_338 )
goto V_343;
return 0 ;
V_343:
F_198 ( V_300 , L_48 ) ;
V_45:
return V_338 ;
}
static void T_13 F_199 ( void )
{
F_200 ( & V_342 ) ;
F_198 ( V_300 , L_48 ) ;
}
