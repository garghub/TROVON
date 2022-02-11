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
struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
if ( F_13 ( V_17 , 0 , & V_33 ) )
return - V_34 ;
if ( V_33 != 1 )
return V_27 ;
V_4 = F_1 ( F_11 ( V_14 ) ) ;
V_30 = & V_4 -> V_11 ;
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
V_63 = F_50 ( V_20 , V_4 -> V_111 ) ;
if ( V_63 )
return V_63 ;
if ( V_62 -> V_66 . V_112 ) {
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
( V_92 . V_101 == V_113 ) ) {
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
if ( V_62 -> V_66 . V_114 )
F_39 ( V_62 -> V_66 . V_114 , V_62 -> V_66 . V_115 ) ;
memcpy ( & ( V_62 -> V_66 . V_78 ) , V_92 . V_116 , sizeof( V_92 . V_116 ) ) ;
if ( V_99 ) {
V_63 = F_35 ( V_20 , & V_80 , 5 ) ;
if ( V_63 )
F_55 ( F_56 ( V_20 -> V_85 ) ,
L_10 ,
V_86 , V_80 , V_63 ) ;
}
return V_63 ;
}
static int F_57 ( struct V_1 * V_4 ,
struct V_60 T_4 * V_77 )
{
struct V_59 * V_62 ;
struct V_59 * V_117 [ 1 ] ;
struct V_29 * V_30 ;
struct V_19 * V_20 ;
int V_63 = 0 , V_118 = 0 ;
struct V_31 * V_32 ;
V_62 = F_29 ( V_77 ) ;
if ( F_58 ( V_62 ) )
return F_59 ( V_62 ) ;
V_20 = V_4 -> V_11 . V_20 ;
if ( F_58 ( V_20 ) ) {
V_63 = F_59 ( V_20 ) ;
goto V_119;
}
V_30 = & V_4 -> V_11 ;
V_32 = F_14 ( V_30 -> V_11 ,
V_62 -> V_66 . V_79 ? V_35 : V_120 ,
V_36 ) ;
V_117 [ 0 ] = V_62 ;
F_15 ( V_32 ) -> V_37 = V_121 ;
F_15 ( V_32 ) -> V_122 = V_117 ;
F_15 ( V_32 ) -> V_123 = 1 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_118 = F_15 ( V_32 ) -> V_39 ;
V_63 = F_33 ( V_77 , V_62 ) ;
F_60 ( V_32 ) ;
V_119:
F_9 ( V_62 -> V_17 ) ;
F_9 ( V_62 ) ;
return V_118 ? V_118 : V_63 ;
}
static int F_61 ( struct V_1 * V_4 ,
struct V_124 T_4 * V_61 )
{
struct V_59 * * V_62 = NULL ;
struct V_60 T_4 * V_125 = V_61 -> V_125 ;
struct V_19 * V_20 ;
struct V_29 * V_30 ;
int V_126 , V_63 = 0 , V_118 = 0 ;
T_6 V_127 ;
struct V_31 * V_32 ;
if ( F_31 ( & V_127 , & V_61 -> V_127 ,
sizeof( V_127 ) ) )
return - V_67 ;
if ( ! V_127 )
return 0 ;
if ( V_127 > V_128 )
return - V_34 ;
V_62 = F_62 ( V_127 , sizeof( * V_62 ) , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_62 [ V_126 ] = F_29 ( & V_125 [ V_126 ] ) ;
if ( F_58 ( V_62 [ V_126 ] ) ) {
V_63 = F_59 ( V_62 [ V_126 ] ) ;
V_127 = V_126 ;
goto V_129;
}
}
V_20 = V_4 -> V_11 . V_20 ;
if ( F_58 ( V_20 ) ) {
V_63 = F_59 ( V_20 ) ;
goto V_129;
}
V_30 = & V_4 -> V_11 ;
V_32 = F_14 ( V_30 -> V_11 ,
V_62 [ 0 ] -> V_66 . V_79 ? V_35 : V_120 ,
V_36 ) ;
F_15 ( V_32 ) -> V_37 = V_121 ;
F_15 ( V_32 ) -> V_122 = V_62 ;
F_15 ( V_32 ) -> V_123 = V_127 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_118 = F_15 ( V_32 ) -> V_39 ;
for ( V_126 = 0 ; V_126 < V_127 && ! V_63 ; V_126 ++ )
V_63 = F_33 ( & V_125 [ V_126 ] , V_62 [ V_126 ] ) ;
F_60 ( V_32 ) ;
V_129:
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
F_9 ( V_62 [ V_126 ] -> V_17 ) ;
F_9 ( V_62 [ V_126 ] ) ;
}
F_9 ( V_62 ) ;
return V_118 ? V_118 : V_63 ;
}
static int F_63 ( struct V_46 * V_47 )
{
if ( ( ! F_64 ( V_130 ) ) || ( V_47 != V_47 -> V_131 ) )
return - V_84 ;
return 0 ;
}
static int F_65 ( struct V_46 * V_47 , T_3 V_48 ,
unsigned int V_92 , unsigned long V_102 )
{
struct V_1 * V_4 ;
int V_18 ;
switch ( V_92 ) {
case V_132 :
V_18 = F_63 ( V_47 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_1 ( V_47 -> V_49 ) ;
if ( ! V_4 )
return - V_34 ;
V_18 = F_57 ( V_4 ,
(struct V_60 T_4 * ) V_102 ) ;
F_5 ( V_4 ) ;
return V_18 ;
case V_133 :
V_18 = F_63 ( V_47 ) ;
if ( V_18 )
return V_18 ;
V_4 = F_1 ( V_47 -> V_49 ) ;
if ( ! V_4 )
return - V_34 ;
V_18 = F_61 ( V_4 ,
(struct V_124 T_4 * ) V_102 ) ;
F_5 ( V_4 ) ;
return V_18 ;
default:
return - V_34 ;
}
}
static int F_66 ( struct V_46 * V_47 , T_3 V_48 ,
unsigned int V_92 , unsigned long V_102 )
{
return F_65 ( V_47 , V_48 , V_92 , ( unsigned long ) F_67 ( V_102 ) ) ;
}
static int F_68 ( struct V_19 * V_20 ,
unsigned int V_111 )
{
int V_18 = 0 ;
if ( V_111 == V_134 ) {
if ( V_20 -> V_22 . V_135 ) {
V_18 = F_69 ( V_20 ) ;
if ( V_18 )
return V_18 ;
}
F_70 ( V_20 -> V_85 ) ;
}
return V_18 ;
}
static int F_71 ( struct V_19 * V_20 ,
unsigned int V_111 )
{
int V_18 = 0 ;
if ( V_111 == V_134 ) {
F_72 ( V_20 -> V_85 ) ;
if ( V_20 -> V_136 && ! V_20 -> V_22 . V_135 )
V_18 = F_73 ( V_20 ) ;
}
return V_18 ;
}
static inline int F_50 ( struct V_19 * V_20 ,
unsigned int V_111 )
{
int V_18 = 0 ;
struct V_1 * V_137 = F_74 ( & V_20 -> V_14 ) ;
if ( V_137 -> V_138 == V_111 )
return 0 ;
if ( F_75 ( V_20 ) ) {
T_7 V_139 = V_20 -> V_22 . V_139 ;
V_18 = F_68 ( V_20 , V_111 ) ;
if ( V_18 )
return V_18 ;
V_139 &= ~ V_140 ;
V_139 |= V_111 ;
V_18 = F_45 ( V_20 , V_88 ,
V_141 , V_139 ,
V_20 -> V_22 . V_142 ) ;
if ( V_18 ) {
F_71 ( V_20 , V_111 ) ;
return V_18 ;
}
V_20 -> V_22 . V_139 = V_139 ;
V_18 = F_71 ( V_20 , V_137 -> V_138 ) ;
}
V_137 -> V_138 = V_111 ;
return V_18 ;
}
static int F_76 ( struct V_19 * V_20 , T_5 * V_143 )
{
int V_63 ;
T_5 V_144 ;
T_8 * V_72 ;
struct V_95 V_96 = {} ;
struct V_91 V_92 = {} ;
struct V_93 V_94 = {} ;
struct V_97 V_98 ;
V_92 . V_101 = V_145 ;
V_92 . V_102 = V_20 -> V_146 << 16 ;
V_92 . V_103 = V_147 | V_148 | V_149 ;
V_63 = F_77 ( V_20 -> V_85 , & V_92 , 0 ) ;
if ( V_63 )
return V_63 ;
if ( ! F_78 ( V_20 -> V_85 ) && ! ( V_92 . V_116 [ 0 ] & V_150 ) )
return - V_151 ;
memset ( & V_92 , 0 , sizeof( struct V_91 ) ) ;
V_92 . V_101 = V_152 ;
V_92 . V_102 = 0 ;
V_92 . V_103 = V_147 | V_148 | V_153 ;
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
V_144 = F_79 ( * V_72 ) ;
F_9 ( V_72 ) ;
if ( V_92 . error || V_94 . error )
return - V_151 ;
* V_143 = V_144 ;
return 0 ;
}
static int F_80 ( struct V_19 * V_20 , unsigned int V_154 ,
bool V_155 , struct V_31 * V_32 , bool * V_156 )
{
unsigned long V_157 = V_158 + F_81 ( V_154 ) ;
int V_63 = 0 ;
T_5 V_80 ;
do {
V_63 = F_36 ( V_20 , & V_80 , 5 ) ;
if ( V_63 ) {
F_46 ( L_11 ,
V_32 -> V_159 -> V_40 , V_63 ) ;
return V_63 ;
}
if ( V_80 & V_160 ) {
F_46 ( L_12 ,
V_32 -> V_159 -> V_40 , V_86 , V_80 ) ;
* V_156 = true ;
}
if ( ( V_20 -> V_85 -> V_161 & V_162 ) &&
V_155 )
break;
if ( F_82 ( V_158 , V_157 ) ) {
F_46 ( L_13 ,
F_43 ( V_20 -> V_85 ) ,
V_32 -> V_159 -> V_40 , V_86 ) ;
return - V_163 ;
}
} while ( ! ( V_80 & V_164 ) ||
( F_38 ( V_80 ) == V_83 ) );
return V_63 ;
}
static int F_83 ( struct V_19 * V_20 , unsigned int V_154 ,
struct V_31 * V_32 , bool * V_156 , T_5 * V_165 )
{
struct V_166 * V_85 = V_20 -> V_85 ;
struct V_91 V_92 = {} ;
int V_63 ;
bool V_167 = F_84 ( V_32 ) == V_168 ;
if ( V_85 -> V_169 && ( V_154 > V_85 -> V_169 ) )
V_167 = false ;
V_92 . V_101 = V_170 ;
if ( V_167 ) {
V_92 . V_103 = V_171 | V_109 | V_149 ;
V_92 . V_172 = V_154 ;
} else {
V_92 . V_103 = V_147 | V_148 | V_149 ;
}
V_63 = F_77 ( V_85 , & V_92 , 5 ) ;
if ( V_63 )
return V_63 ;
* V_165 = V_92 . V_116 [ 0 ] ;
if ( F_84 ( V_32 ) == V_173 )
return 0 ;
if ( ! F_78 ( V_85 ) &&
( * V_165 & V_160 ) ) {
F_46 ( L_14 ,
V_32 -> V_159 -> V_40 , V_86 , * V_165 ) ;
* V_156 = true ;
}
return F_80 ( V_20 , V_154 , V_167 , V_32 , V_156 ) ;
}
static int F_85 ( struct V_31 * V_32 , const char * V_174 , int error ,
bool V_175 , T_5 V_80 )
{
switch ( error ) {
case - V_176 :
F_46 ( L_15 ,
V_32 -> V_159 -> V_40 , L_16 ,
V_174 , V_80 ) ;
return V_177 ;
case - V_163 :
F_46 ( L_15 ,
V_32 -> V_159 -> V_40 , L_17 , V_174 , V_80 ) ;
if ( ! V_175 ) {
F_46 ( L_18 ,
V_32 -> V_159 -> V_40 ) ;
return V_177 ;
}
if ( V_80 & ( V_178 | V_179 ) ) {
F_46 ( L_19 ,
V_32 -> V_159 -> V_40 ) ;
return V_177 ;
}
return V_180 ;
default:
F_46 ( L_20 ,
V_32 -> V_159 -> V_40 , error , V_80 ) ;
return V_180 ;
}
}
static int F_86 ( struct V_19 * V_20 , struct V_31 * V_32 ,
struct V_181 * V_182 , bool * V_183 , bool * V_156 )
{
bool V_184 = true ;
T_5 V_80 , V_165 = 0 ;
int V_63 , V_185 ;
if ( F_87 ( V_20 ) )
return V_186 ;
for ( V_185 = 2 ; V_185 >= 0 ; V_185 -- ) {
V_63 = F_36 ( V_20 , & V_80 , 0 ) ;
if ( ! V_63 )
break;
F_88 ( V_20 -> V_85 ) ;
V_184 = false ;
F_46 ( L_21 ,
V_32 -> V_159 -> V_40 , V_63 , V_185 ? L_22 : L_23 ) ;
}
if ( V_63 ) {
if ( F_89 ( V_20 -> V_85 ) )
return V_186 ;
return V_180 ;
}
if ( ( V_80 & V_187 ) ||
( V_182 -> V_188 . V_116 [ 0 ] & V_187 ) ||
( V_182 -> V_92 . V_116 [ 0 ] & V_187 ) )
* V_183 = true ;
if ( ! F_78 ( V_20 -> V_85 ) && F_84 ( V_32 ) != V_173 )
if ( ( V_80 & V_160 ) ||
( V_182 -> V_188 . V_116 [ 0 ] & V_160 ) ) {
F_46 ( L_24 ,
V_32 -> V_159 -> V_40 , V_86 ,
V_182 -> V_188 . V_116 [ 0 ] , V_80 ) ;
* V_156 = true ;
}
if ( F_38 ( V_80 ) == V_189 ||
F_38 ( V_80 ) == V_190 ) {
V_63 = F_83 ( V_20 ,
F_90 ( V_182 -> V_94 . V_108 , 1000000 ) ,
V_32 , V_156 , & V_165 ) ;
if ( V_63 ) {
F_46 ( L_25 ,
V_32 -> V_159 -> V_40 , V_63 ) ;
return V_180 ;
}
if ( V_165 & V_187 )
* V_183 = true ;
}
if ( V_182 -> V_191 . error )
return F_85 ( V_32 , L_26 , V_182 -> V_191 . error ,
V_184 , V_80 ) ;
if ( V_182 -> V_92 . error )
return F_85 ( V_32 , L_27 , V_182 -> V_92 . error ,
V_184 , V_80 ) ;
if ( ! V_182 -> V_188 . error )
return V_192 ;
F_17 ( L_28 ,
V_32 -> V_159 -> V_40 , V_182 -> V_188 . error ,
V_182 -> V_92 . V_116 [ 0 ] , V_80 ) ;
if ( V_165 ) {
V_182 -> V_188 . V_116 [ 0 ] = V_165 ;
V_182 -> V_188 . error = 0 ;
}
return V_192 ;
}
static int F_91 ( struct V_1 * V_4 , struct V_166 * V_85 ,
int type )
{
int V_63 ;
if ( V_4 -> V_193 & type )
return - V_194 ;
V_4 -> V_193 |= type ;
V_63 = F_92 ( V_85 ) ;
if ( V_63 != - V_87 ) {
struct V_1 * V_137 =
F_74 ( & V_85 -> V_20 -> V_14 ) ;
int V_195 ;
V_137 -> V_138 = V_137 -> V_111 ;
V_195 = F_50 ( V_85 -> V_20 , V_4 -> V_111 ) ;
if ( V_195 ) {
return - V_196 ;
}
}
return V_63 ;
}
static inline void F_93 ( struct V_1 * V_4 , int type )
{
V_4 -> V_193 &= ~ type ;
}
int F_94 ( struct V_29 * V_30 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
if ( V_4 && V_4 -> V_111 == V_134 )
return true ;
return false ;
}
static void F_95 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_198 * V_199 ;
struct V_19 * V_20 = V_30 -> V_20 ;
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_1 * V_137 = F_74 ( & V_20 -> V_14 ) ;
struct V_59 * * V_62 ;
T_7 * * V_22 ;
T_5 V_80 ;
int V_18 ;
int V_126 ;
V_199 = F_15 ( V_32 ) ;
switch ( V_199 -> V_37 ) {
case V_121 :
V_62 = V_199 -> V_122 ;
for ( V_126 = 0 , V_18 = 0 ; V_126 < V_199 -> V_123 ; V_126 ++ ) {
V_18 = F_47 ( V_20 , V_4 , V_62 [ V_126 ] ) ;
if ( V_18 )
break;
}
if ( V_4 -> V_41 & V_100 )
F_50 ( V_20 , V_137 -> V_111 ) ;
break;
case V_38 :
V_18 = F_45 ( V_20 , V_88 , V_200 ,
V_20 -> V_22 . V_23 |
V_25 ,
V_20 -> V_22 . V_142 ) ;
if ( V_18 )
F_46 ( L_29 ,
V_4 -> V_3 -> V_40 , V_18 ) ;
else
V_20 -> V_22 . V_23 |=
V_25 ;
break;
case V_201 :
V_18 = F_96 ( V_20 , & V_80 ) ;
if ( ! V_18 )
V_18 = V_80 ;
break;
case V_202 :
V_22 = V_199 -> V_122 ;
V_18 = F_97 ( V_20 , V_22 ) ;
break;
default:
F_46 ( L_30 ,
V_4 -> V_3 -> V_40 ) ;
V_18 = - V_34 ;
break;
}
V_199 -> V_39 = V_18 ;
F_98 ( V_32 , V_18 ? V_203 : V_204 ) ;
}
static void F_99 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_205 , V_206 , V_102 ;
int V_63 = 0 , type = V_207 ;
T_9 V_80 = V_204 ;
if ( ! F_100 ( V_20 ) ) {
V_80 = V_208 ;
goto V_209;
}
V_205 = F_101 ( V_32 ) ;
V_206 = F_102 ( V_32 ) ;
if ( F_103 ( V_20 ) )
V_102 = V_210 ;
else if ( F_104 ( V_20 ) )
V_102 = V_211 ;
else
V_102 = V_212 ;
do {
V_63 = 0 ;
if ( V_20 -> V_213 & V_214 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_215 ,
V_102 == V_211 ?
V_216 :
V_217 ,
0 ) ;
}
if ( ! V_63 )
V_63 = F_105 ( V_20 , V_205 , V_206 , V_102 ) ;
} while ( V_63 == - V_151 && ! F_91 ( V_4 , V_20 -> V_85 , type ) );
if ( V_63 )
V_80 = V_203 ;
else
F_93 ( V_4 , type ) ;
V_209:
F_106 ( V_32 , V_80 , F_107 ( V_32 ) ) ;
}
static void F_108 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_205 , V_206 , V_102 ;
int V_63 = 0 , type = V_218 ;
T_9 V_80 = V_204 ;
if ( ! ( F_109 ( V_20 ) ) ) {
V_80 = V_208 ;
goto V_45;
}
V_205 = F_101 ( V_32 ) ;
V_206 = F_102 ( V_32 ) ;
if ( F_104 ( V_20 ) && ! F_110 ( V_20 , V_205 , V_206 ) )
V_102 = V_219 ;
else
V_102 = V_220 ;
V_185:
if ( V_20 -> V_213 & V_214 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_215 ,
V_102 == V_219 ?
V_221 :
V_222 ,
0 ) ;
if ( V_63 )
goto V_223;
}
V_63 = F_105 ( V_20 , V_205 , V_206 , V_102 ) ;
if ( V_63 == - V_151 )
goto V_223;
if ( V_63 ) {
V_80 = V_203 ;
goto V_45;
}
if ( V_102 == V_219 ) {
if ( V_20 -> V_213 & V_214 ) {
V_63 = F_45 ( V_20 , V_88 ,
V_215 ,
V_224 ,
0 ) ;
if ( V_63 )
goto V_223;
}
V_63 = F_105 ( V_20 , V_205 , V_206 , V_225 ) ;
if ( V_63 == - V_151 )
goto V_223;
if ( V_63 ) {
V_80 = V_203 ;
goto V_45;
}
}
V_223:
if ( V_63 && ! F_91 ( V_4 , V_20 -> V_85 , type ) )
goto V_185;
if ( ! V_63 )
F_93 ( V_4 , type ) ;
V_45:
F_106 ( V_32 , V_80 , F_107 ( V_32 ) ) ;
}
static void F_111 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
int V_18 = 0 ;
V_18 = F_112 ( V_20 ) ;
F_98 ( V_32 , V_18 ? V_203 : V_204 ) ;
}
static inline void F_113 ( struct V_181 * V_182 ,
struct V_19 * V_20 ,
struct V_31 * V_32 )
{
if ( ! ( V_20 -> V_22 . V_226 & V_227 ) ) {
if ( ! F_114 ( F_101 ( V_32 ) , V_20 -> V_22 . V_228 ) )
V_182 -> V_94 . V_72 = 1 ;
if ( V_182 -> V_94 . V_72 > V_20 -> V_22 . V_228 )
V_182 -> V_94 . V_72 = V_20 -> V_22 . V_228 ;
else if ( V_182 -> V_94 . V_72 < V_20 -> V_22 . V_228 )
V_182 -> V_94 . V_72 = 1 ;
}
}
static void F_115 ( struct V_181 * V_182 )
{
T_5 V_229 ;
if ( ! V_182 -> V_188 . error ) {
bool V_230 ;
V_229 = V_182 -> V_188 . V_116 [ 0 ] & V_231 ;
V_230 = V_229 & V_232 && ! V_182 -> V_96 . V_191 ;
if ( V_229 && ! V_230 )
V_182 -> V_188 . error = - V_151 ;
}
}
static enum V_233 F_116 ( struct V_19 * V_20 ,
struct V_234 * V_235 )
{
struct V_198 * V_236 = F_117 ( V_235 , struct V_198 ,
V_235 ) ;
struct V_181 * V_182 = & V_236 -> V_182 ;
struct V_31 * V_32 = F_118 ( V_236 ) ;
int V_237 = V_20 -> V_85 -> V_237 ;
bool V_183 = false ;
bool V_156 = false ;
F_115 ( V_182 ) ;
if ( V_182 -> V_191 . error || V_182 -> V_92 . error ||
V_182 -> V_188 . error || V_182 -> V_94 . error ) {
switch ( F_86 ( V_20 , V_32 , V_182 , & V_183 , & V_156 ) ) {
case V_177 :
return V_238 ;
case V_180 :
return V_239 ;
case V_186 :
return V_240 ;
case V_192 :
break;
}
}
if ( V_182 -> V_92 . V_116 [ 0 ] & V_231 ) {
F_46 ( L_31 ,
V_32 -> V_159 -> V_40 , V_182 -> V_92 . V_116 [ 0 ] ) ;
return V_239 ;
}
if ( ! F_78 ( V_20 -> V_85 ) && F_84 ( V_32 ) != V_173 ) {
int V_63 ;
if ( V_182 -> V_188 . V_116 [ 0 ] & V_160 ) {
F_46 ( L_32 ,
V_32 -> V_159 -> V_40 , V_86 ,
V_182 -> V_188 . V_116 [ 0 ] ) ;
V_156 = true ;
}
V_63 = F_80 ( V_20 , V_241 , false , V_32 ,
& V_156 ) ;
if ( V_63 )
return V_242 ;
}
if ( V_156 ) {
F_42 ( L_33 ,
V_32 -> V_159 -> V_40 ) ;
return V_238 ;
}
if ( V_182 -> V_94 . error || V_182 -> V_188 . error ) {
if ( V_237 && ! V_182 -> V_243 ) {
F_44 ( L_34 ,
V_32 -> V_159 -> V_40 ) ;
V_182 -> V_243 = 1 ;
return V_238 ;
}
F_46 ( L_35 ,
V_32 -> V_159 -> V_40 , V_182 -> V_94 . error ? : V_182 -> V_188 . error ,
( unsigned ) F_101 ( V_32 ) ,
( unsigned ) F_102 ( V_32 ) ,
V_182 -> V_92 . V_116 [ 0 ] , V_182 -> V_188 . V_116 [ 0 ] ) ;
if ( F_84 ( V_32 ) == V_173 ) {
if ( V_183 )
return V_244 ;
return V_245 ;
} else {
return V_242 ;
}
}
if ( ! V_182 -> V_94 . V_246 )
return V_238 ;
if ( F_107 ( V_32 ) != V_182 -> V_94 . V_246 )
return V_247 ;
return V_248 ;
}
static void F_119 ( struct V_29 * V_30 , struct V_198 * V_249 ,
int V_250 , bool * V_251 ,
bool * V_252 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
struct V_181 * V_182 = & V_249 -> V_182 ;
struct V_31 * V_32 = F_118 ( V_249 ) ;
* V_251 = ( V_32 -> V_253 & V_254 ) &&
F_84 ( V_32 ) == V_168 &&
( V_4 -> V_103 & V_255 ) ;
memset ( V_182 , 0 , sizeof( struct V_181 ) ) ;
V_182 -> V_96 . V_94 = & V_182 -> V_94 ;
V_182 -> V_188 . V_101 = V_170 ;
V_182 -> V_188 . V_102 = 0 ;
if ( F_84 ( V_32 ) == V_173 ) {
V_182 -> V_94 . V_103 = V_106 ;
V_182 -> V_188 . V_103 = V_147 | V_148 | V_149 ;
} else {
V_182 -> V_94 . V_103 = V_105 ;
V_182 -> V_188 . V_103 = V_171 | V_109 | V_149 ;
}
V_182 -> V_94 . V_71 = 512 ;
V_182 -> V_94 . V_72 = F_102 ( V_32 ) ;
if ( V_182 -> V_94 . V_72 > V_20 -> V_85 -> V_256 )
V_182 -> V_94 . V_72 = V_20 -> V_85 -> V_256 ;
if ( V_182 -> V_94 . V_72 > 1 ) {
if ( V_250 )
V_182 -> V_94 . V_72 = 1 ;
if ( V_20 -> V_85 -> V_257 -> V_258 )
V_182 -> V_94 . V_72 = V_20 -> V_85 -> V_257 -> V_258 ( V_20 ,
( F_84 ( V_32 ) == V_173 ) ?
V_106 : V_105 ,
V_182 -> V_94 . V_72 ) ;
}
if ( * V_251 )
F_113 ( V_182 , V_20 , V_32 ) ;
* V_252 = V_20 -> V_22 . V_259 &&
( V_32 -> V_253 & V_260 ) &&
( F_84 ( V_32 ) == V_168 ) &&
( ( V_182 -> V_94 . V_72 * V_182 -> V_94 . V_71 ) >=
V_20 -> V_22 . V_259 ) ;
F_49 ( & V_182 -> V_94 , V_20 ) ;
V_182 -> V_94 . V_98 = V_249 -> V_98 ;
V_182 -> V_94 . V_104 = F_120 ( V_30 , V_249 ) ;
if ( V_182 -> V_94 . V_72 != F_102 ( V_32 ) ) {
int V_126 , V_261 = V_182 -> V_94 . V_72 << 9 ;
struct V_97 * V_98 ;
F_121 (brq->data.sg, sg, brq->data.sg_len, i) {
V_261 -= V_98 -> V_262 ;
if ( V_261 <= 0 ) {
V_98 -> V_262 += V_261 ;
V_126 ++ ;
break;
}
}
V_182 -> V_94 . V_104 = V_126 ;
}
V_249 -> V_235 . V_96 = & V_182 -> V_96 ;
}
static void F_122 ( struct V_198 * V_249 ,
struct V_19 * V_20 ,
int V_250 ,
struct V_29 * V_30 )
{
T_5 V_263 , V_264 ;
struct V_181 * V_182 = & V_249 -> V_182 ;
struct V_31 * V_32 = F_118 ( V_249 ) ;
struct V_1 * V_4 = V_30 -> V_197 ;
bool V_251 , V_252 ;
F_119 ( V_30 , V_249 , V_250 , & V_251 , & V_252 ) ;
V_182 -> V_96 . V_92 = & V_182 -> V_92 ;
V_182 -> V_92 . V_102 = F_101 ( V_32 ) ;
if ( ! F_123 ( V_20 ) )
V_182 -> V_92 . V_102 <<= 9 ;
V_182 -> V_92 . V_103 = V_147 | V_148 | V_153 ;
if ( V_182 -> V_94 . V_72 > 1 || V_251 ) {
if ( ! F_78 ( V_20 -> V_85 ) ||
F_84 ( V_32 ) == V_173 )
V_182 -> V_96 . V_188 = & V_182 -> V_188 ;
V_263 = V_265 ;
V_264 = V_266 ;
} else {
V_182 -> V_96 . V_188 = NULL ;
V_263 = V_267 ;
V_264 = V_268 ;
}
V_182 -> V_92 . V_101 = F_84 ( V_32 ) == V_173 ? V_263 : V_264 ;
if ( ( V_4 -> V_103 & V_269 ) && F_124 ( V_182 -> V_92 . V_101 ) &&
( V_251 || ! ( V_20 -> V_213 & V_270 ) ||
V_252 ) ) {
V_182 -> V_191 . V_101 = V_271 ;
V_182 -> V_191 . V_102 = V_182 -> V_94 . V_72 |
( V_251 ? ( 1 << 31 ) : 0 ) |
( V_252 ? ( 1 << 29 ) : 0 ) ;
V_182 -> V_191 . V_103 = V_148 | V_149 ;
V_182 -> V_96 . V_191 = & V_182 -> V_191 ;
}
V_249 -> V_235 . V_272 = F_116 ;
}
static bool F_125 ( struct V_1 * V_4 , struct V_19 * V_20 ,
struct V_181 * V_182 , struct V_31 * V_32 ,
bool V_273 )
{
bool V_274 ;
if ( F_126 ( V_20 ) ) {
T_5 V_72 ;
int V_63 ;
V_63 = F_76 ( V_20 , & V_72 ) ;
if ( V_63 )
V_274 = V_273 ;
else
V_274 = F_106 ( V_32 , V_204 , V_72 << 9 ) ;
} else {
V_274 = F_106 ( V_32 , V_204 , V_182 -> V_94 . V_246 ) ;
}
return V_274 ;
}
static void F_127 ( struct V_29 * V_30 , struct V_19 * V_20 ,
struct V_31 * V_32 ,
struct V_198 * V_249 )
{
if ( F_87 ( V_20 ) )
V_32 -> V_275 |= V_276 ;
while ( F_106 ( V_32 , V_203 , F_128 ( V_32 ) ) ) ;
V_30 -> V_277 -- ;
}
static void F_129 ( struct V_29 * V_30 , struct V_31 * V_32 ,
struct V_198 * V_249 )
{
if ( ! V_32 )
return;
if ( F_87 ( V_30 -> V_20 ) ) {
V_32 -> V_275 |= V_276 ;
F_98 ( V_32 , V_203 ) ;
V_30 -> V_277 -- ;
return;
}
F_122 ( V_249 , V_30 -> V_20 , 0 , V_30 ) ;
F_130 ( V_30 -> V_20 -> V_85 , & V_249 -> V_235 , NULL ) ;
}
static void F_131 ( struct V_29 * V_30 , struct V_31 * V_278 )
{
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
struct V_181 * V_182 ;
int V_250 = 0 , V_185 = 0 , type , V_243 = 0 ;
enum V_233 V_80 ;
struct V_198 * V_279 = NULL ;
struct V_198 * V_199 ;
struct V_31 * V_280 ;
struct V_234 * V_281 ;
struct V_234 * V_282 ;
bool V_274 = true ;
if ( V_278 ) {
V_279 = F_15 ( V_278 ) ;
V_30 -> V_277 ++ ;
}
if ( ! V_30 -> V_277 )
return;
do {
if ( V_278 ) {
if ( F_132 ( V_20 ) &&
! F_114 ( F_102 ( V_278 ) , 8 ) ) {
F_46 ( L_36 ,
V_278 -> V_159 -> V_40 ) ;
F_127 ( V_30 , V_20 , V_278 , V_279 ) ;
return;
}
F_122 ( V_279 , V_20 , 0 , V_30 ) ;
V_281 = & V_279 -> V_235 ;
} else
V_281 = NULL ;
V_282 = F_130 ( V_20 -> V_85 , V_281 , & V_80 ) ;
if ( ! V_282 ) {
return;
}
V_199 = F_117 ( V_282 , struct V_198 , V_235 ) ;
V_182 = & V_199 -> V_182 ;
V_280 = F_118 ( V_199 ) ;
type = F_84 ( V_280 ) == V_173 ? V_283 : V_284 ;
switch ( V_80 ) {
case V_248 :
case V_247 :
F_93 ( V_4 , type ) ;
V_274 = F_106 ( V_280 , V_204 ,
V_182 -> V_94 . V_246 ) ;
if ( V_80 == V_248 && V_274 ) {
F_46 ( L_37 ,
V_86 , F_107 ( V_280 ) ,
V_182 -> V_94 . V_246 ) ;
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
return;
}
break;
case V_242 :
V_274 = F_125 ( V_4 , V_20 , V_182 , V_280 , V_274 ) ;
if ( F_91 ( V_4 , V_20 -> V_85 , type ) ) {
if ( V_274 )
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
else
V_30 -> V_277 -- ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
}
if ( ! V_274 ) {
V_30 -> V_277 -- ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
}
break;
case V_238 :
V_243 = V_182 -> V_243 ;
if ( V_185 ++ < 5 )
break;
case V_239 :
if ( ! F_91 ( V_4 , V_20 -> V_85 , type ) )
break;
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
case V_245 : {
int V_63 ;
V_63 = F_91 ( V_4 , V_20 -> V_85 , type ) ;
if ( ! V_63 )
break;
if ( V_63 == - V_196 ) {
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
}
}
case V_244 :
if ( V_182 -> V_94 . V_72 > 1 ) {
F_42 ( L_38 ,
V_280 -> V_159 -> V_40 ) ;
V_250 = 1 ;
break;
}
V_274 = F_106 ( V_280 , V_203 ,
V_182 -> V_94 . V_71 ) ;
if ( ! V_274 ) {
V_30 -> V_277 -- ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
}
break;
case V_240 :
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
default:
F_46 ( L_39 ,
V_280 -> V_159 -> V_40 , V_80 ) ;
F_127 ( V_30 , V_20 , V_280 , V_199 ) ;
F_129 ( V_30 , V_278 , V_279 ) ;
return;
}
if ( V_274 ) {
F_122 ( V_199 , V_20 ,
V_250 , V_30 ) ;
F_130 ( V_20 -> V_85 ,
& V_199 -> V_235 , NULL ) ;
V_199 -> V_182 . V_243 = V_243 ;
}
} while ( V_274 );
V_30 -> V_277 -- ;
}
void F_133 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
int V_18 ;
struct V_1 * V_4 = V_30 -> V_197 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
if ( V_32 && ! V_30 -> V_277 )
F_134 ( V_20 ) ;
V_18 = F_50 ( V_20 , V_4 -> V_111 ) ;
if ( V_18 ) {
if ( V_32 ) {
F_98 ( V_32 , V_203 ) ;
}
goto V_45;
}
if ( V_32 ) {
switch ( F_135 ( V_32 ) ) {
case V_120 :
case V_35 :
if ( V_30 -> V_277 )
F_131 ( V_30 , NULL ) ;
F_95 ( V_30 , V_32 ) ;
break;
case V_285 :
if ( V_30 -> V_277 )
F_131 ( V_30 , NULL ) ;
F_99 ( V_30 , V_32 ) ;
break;
case V_286 :
if ( V_30 -> V_277 )
F_131 ( V_30 , NULL ) ;
F_108 ( V_30 , V_32 ) ;
break;
case V_287 :
if ( V_30 -> V_277 )
F_131 ( V_30 , NULL ) ;
F_111 ( V_30 , V_32 ) ;
break;
default:
F_131 ( V_30 , V_32 ) ;
V_20 -> V_85 -> V_288 . V_289 = false ;
break;
}
} else {
F_131 ( V_30 , NULL ) ;
V_20 -> V_85 -> V_288 . V_289 = false ;
}
V_45:
if ( ! V_30 -> V_277 )
F_136 ( V_20 ) ;
}
static inline int F_137 ( struct V_19 * V_20 )
{
return F_138 ( V_20 ) ||
! ( V_20 -> V_290 . V_291 & V_292 ) ;
}
static struct V_1 * F_139 ( struct V_19 * V_20 ,
struct V_13 * V_293 ,
T_10 V_294 ,
bool V_295 ,
const char * V_296 ,
int V_41 )
{
struct V_1 * V_4 ;
int V_8 , V_18 ;
V_8 = F_140 ( & V_12 , 0 , V_297 , V_64 ) ;
if ( V_8 < 0 ) {
if ( V_8 == - V_298 )
F_55 ( F_56 ( V_20 -> V_85 ) ,
L_40 ) ;
return F_32 ( V_8 ) ;
}
V_4 = F_141 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_4 ) {
V_18 = - V_65 ;
goto V_45;
}
V_4 -> V_41 = V_41 ;
V_4 -> V_43 = F_137 ( V_20 ) ;
V_4 -> V_3 = F_142 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_18 = - V_65 ;
goto V_299;
}
F_143 ( & V_4 -> V_300 ) ;
F_144 ( & V_4 -> V_301 ) ;
V_4 -> V_7 = 1 ;
V_18 = F_145 ( & V_4 -> V_11 , V_20 , & V_4 -> V_300 , V_296 ) ;
if ( V_18 )
goto V_302;
V_4 -> V_11 . V_197 = V_4 ;
V_4 -> V_3 -> V_303 = V_304 ;
V_4 -> V_3 -> V_9 = V_8 * V_10 ;
V_4 -> V_3 -> V_305 = & V_306 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_11 = V_4 -> V_11 . V_11 ;
V_4 -> V_293 = V_293 ;
F_18 ( V_4 -> V_3 , V_4 -> V_43 || V_295 ) ;
V_4 -> V_3 -> V_103 = V_307 ;
if ( V_41 & ( V_100 | V_42 ) )
V_4 -> V_3 -> V_103 |= V_308 ;
snprintf ( V_4 -> V_3 -> V_40 , sizeof( V_4 -> V_3 -> V_40 ) ,
L_41 , V_20 -> V_85 -> V_309 , V_296 ? V_296 : L_42 ) ;
if ( F_75 ( V_20 ) )
F_146 ( V_4 -> V_11 . V_11 ,
V_20 -> V_22 . V_310 ) ;
else
F_146 ( V_4 -> V_11 . V_11 , 512 ) ;
F_147 ( V_4 -> V_3 , V_294 ) ;
if ( F_148 ( V_20 -> V_85 ) ) {
if ( ( F_75 ( V_20 ) &&
V_20 -> V_290 . V_311 >= V_312 ) ||
( F_126 ( V_20 ) &&
V_20 -> V_313 . V_125 & V_314 ) )
V_4 -> V_103 |= V_269 ;
}
if ( F_75 ( V_20 ) &&
V_4 -> V_103 & V_269 &&
( ( V_20 -> V_22 . V_226 & V_227 ) ||
V_20 -> V_22 . V_228 ) ) {
V_4 -> V_103 |= V_255 ;
F_149 ( V_4 -> V_11 . V_11 , true , true ) ;
}
return V_4 ;
V_302:
F_8 ( V_4 -> V_3 ) ;
V_299:
F_9 ( V_4 ) ;
V_45:
F_7 ( & V_12 , V_8 ) ;
return F_32 ( V_18 ) ;
}
static struct V_1 * F_150 ( struct V_19 * V_20 )
{
T_10 V_294 ;
if ( ! F_126 ( V_20 ) && F_123 ( V_20 ) ) {
V_294 = V_20 -> V_22 . V_58 ;
} else {
V_294 = ( F_151 ( T_10 ) ) V_20 -> V_290 . V_315
<< ( V_20 -> V_290 . V_316 - 9 ) ;
}
return F_139 ( V_20 , & V_20 -> V_14 , V_294 , false , NULL ,
V_317 ) ;
}
static int F_152 ( struct V_19 * V_20 ,
struct V_1 * V_4 ,
unsigned int V_111 ,
T_10 V_294 ,
bool V_295 ,
const char * V_296 ,
int V_41 )
{
char V_318 [ 10 ] ;
struct V_1 * V_28 ;
V_28 = F_139 ( V_20 , F_153 ( V_4 -> V_3 ) , V_294 , V_295 ,
V_296 , V_41 ) ;
if ( F_58 ( V_28 ) )
return F_59 ( V_28 ) ;
V_28 -> V_111 = V_111 ;
F_154 ( & V_28 -> V_301 , & V_4 -> V_301 ) ;
F_155 ( ( V_70 ) F_28 ( V_28 -> V_3 ) , 512 , V_319 ,
V_318 , sizeof( V_318 ) ) ;
F_17 ( L_43 ,
V_28 -> V_3 -> V_40 , F_156 ( V_20 ) ,
F_157 ( V_20 ) , V_28 -> V_111 , V_318 ) ;
return 0 ;
}
static int F_158 ( struct V_19 * V_20 , struct V_1 * V_4 )
{
int V_320 , V_18 = 0 ;
if ( ! F_75 ( V_20 ) )
return 0 ;
for ( V_320 = 0 ; V_320 < V_20 -> V_321 ; V_320 ++ ) {
if ( V_20 -> V_301 [ V_320 ] . V_294 ) {
V_18 = F_152 ( V_20 , V_4 ,
V_20 -> V_301 [ V_320 ] . V_322 ,
V_20 -> V_301 [ V_320 ] . V_294 >> 9 ,
V_20 -> V_301 [ V_320 ] . V_323 ,
V_20 -> V_301 [ V_320 ] . V_174 ,
V_20 -> V_301 [ V_320 ] . V_41 ) ;
if ( V_18 )
return V_18 ;
}
}
return V_18 ;
}
static void F_159 ( struct V_1 * V_4 )
{
struct V_19 * V_20 ;
if ( V_4 ) {
V_20 = V_4 -> V_11 . V_20 ;
F_160 ( V_4 -> V_11 . V_11 -> V_324 ) ;
F_161 ( V_325 , V_4 -> V_11 . V_11 ) ;
F_162 ( V_4 -> V_11 . V_11 -> V_324 ) ;
F_163 ( V_4 -> V_11 . V_11 ) ;
F_164 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_3 -> V_103 & V_326 ) {
F_165 ( F_153 ( V_4 -> V_3 ) , & V_4 -> V_323 ) ;
if ( ( V_4 -> V_41 & V_42 ) &&
V_20 -> V_22 . V_327 )
F_165 ( F_153 ( V_4 -> V_3 ) ,
& V_4 -> V_328 ) ;
F_166 ( V_4 -> V_3 ) ;
}
F_5 ( V_4 ) ;
}
}
static void F_167 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
struct V_329 * V_330 , * V_331 ;
struct V_1 * V_28 ;
F_168 (pos, q, &md->part) {
V_28 = F_169 ( V_330 , struct V_1 , V_301 ) ;
F_170 ( V_330 ) ;
F_159 ( V_28 ) ;
}
}
static int F_171 ( struct V_1 * V_4 )
{
int V_18 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
F_172 ( V_4 -> V_293 , V_4 -> V_3 ) ;
V_4 -> V_323 . V_332 = F_20 ;
V_4 -> V_323 . V_333 = F_22 ;
F_173 ( & V_4 -> V_323 . V_16 ) ;
V_4 -> V_323 . V_16 . V_174 = L_44 ;
V_4 -> V_323 . V_16 . V_48 = V_334 | V_335 ;
V_18 = F_174 ( F_153 ( V_4 -> V_3 ) , & V_4 -> V_323 ) ;
if ( V_18 )
goto V_336;
if ( ( V_4 -> V_41 & V_42 ) &&
V_20 -> V_22 . V_327 ) {
T_11 V_48 ;
if ( V_20 -> V_22 . V_23 & V_337 )
V_48 = V_334 ;
else
V_48 = V_334 | V_335 ;
V_4 -> V_328 . V_332 = F_10 ;
V_4 -> V_328 . V_333 = F_12 ;
F_173 ( & V_4 -> V_328 . V_16 ) ;
V_4 -> V_328 . V_16 . V_48 = V_48 ;
V_4 -> V_328 . V_16 . V_174 =
L_45 ;
V_18 = F_174 ( F_153 ( V_4 -> V_3 ) ,
& V_4 -> V_328 ) ;
if ( V_18 )
goto V_338;
}
return V_18 ;
V_338:
F_165 ( F_153 ( V_4 -> V_3 ) , & V_4 -> V_323 ) ;
V_336:
F_166 ( V_4 -> V_3 ) ;
return V_18 ;
}
static int F_175 ( void * V_94 , V_70 * V_229 )
{
struct V_19 * V_20 = V_94 ;
struct V_1 * V_4 = F_74 ( & V_20 -> V_14 ) ;
struct V_29 * V_30 = & V_4 -> V_11 ;
struct V_31 * V_32 ;
int V_18 ;
V_32 = F_14 ( V_30 -> V_11 , V_120 , V_36 ) ;
F_15 ( V_32 ) -> V_37 = V_201 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_18 = F_15 ( V_32 ) -> V_39 ;
if ( V_18 >= 0 ) {
* V_229 = V_18 ;
V_18 = 0 ;
}
return V_18 ;
}
static int F_176 ( struct V_339 * V_339 , struct V_340 * V_341 )
{
struct V_19 * V_20 = V_339 -> V_342 ;
struct V_1 * V_4 = F_74 ( & V_20 -> V_14 ) ;
struct V_29 * V_30 = & V_4 -> V_11 ;
struct V_31 * V_32 ;
char * V_17 ;
T_1 V_343 = 0 ;
T_7 * V_22 ;
int V_63 , V_126 ;
V_17 = F_30 ( V_344 + 1 , V_64 ) ;
if ( ! V_17 )
return - V_65 ;
V_32 = F_14 ( V_30 -> V_11 , V_120 , V_36 ) ;
F_15 ( V_32 ) -> V_37 = V_202 ;
F_15 ( V_32 ) -> V_122 = & V_22 ;
F_16 ( V_30 -> V_11 , NULL , V_32 , 0 ) ;
V_63 = F_15 ( V_32 ) -> V_39 ;
if ( V_63 ) {
F_46 ( L_46 , V_63 ) ;
goto V_345;
}
for ( V_126 = 0 ; V_126 < 512 ; V_126 ++ )
V_343 += sprintf ( V_17 + V_343 , L_47 , V_22 [ V_126 ] ) ;
V_343 += sprintf ( V_17 + V_343 , L_48 ) ;
if ( V_343 != V_344 ) {
V_63 = - V_34 ;
goto V_345;
}
V_341 -> V_6 = V_17 ;
F_9 ( V_22 ) ;
return 0 ;
V_345:
F_9 ( V_17 ) ;
return V_63 ;
}
static T_1 F_177 ( struct V_340 * V_341 , char T_4 * V_346 ,
T_2 V_347 , T_12 * V_348 )
{
char * V_17 = V_341 -> V_6 ;
return F_178 ( V_346 , V_347 , V_348 ,
V_17 , V_344 ) ;
}
static int F_179 ( struct V_339 * V_339 , struct V_340 * V_340 )
{
F_9 ( V_340 -> V_6 ) ;
return 0 ;
}
static int F_180 ( struct V_19 * V_20 )
{
struct V_349 * V_350 ;
if ( ! V_20 -> V_351 )
return 0 ;
V_350 = V_20 -> V_351 ;
if ( F_75 ( V_20 ) || F_126 ( V_20 ) ) {
if ( ! F_181 ( L_49 , V_352 , V_350 , V_20 ,
& V_353 ) )
return - V_151 ;
}
if ( F_75 ( V_20 ) ) {
if ( ! F_181 ( L_50 , V_352 , V_350 , V_20 ,
& V_354 ) )
return - V_151 ;
}
return 0 ;
}
static int F_180 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_182 ( struct V_19 * V_20 )
{
struct V_1 * V_4 , * V_28 ;
char V_318 [ 10 ] ;
if ( ! ( V_20 -> V_290 . V_291 & V_355 ) )
return - V_196 ;
F_183 ( V_20 , V_356 ) ;
V_4 = F_150 ( V_20 ) ;
if ( F_58 ( V_4 ) )
return F_59 ( V_4 ) ;
F_155 ( ( V_70 ) F_28 ( V_4 -> V_3 ) , 512 , V_319 ,
V_318 , sizeof( V_318 ) ) ;
F_17 ( L_51 ,
V_4 -> V_3 -> V_40 , F_156 ( V_20 ) , F_157 ( V_20 ) ,
V_318 , V_4 -> V_43 ? L_52 : L_42 ) ;
if ( F_158 ( V_20 , V_4 ) )
goto V_45;
F_184 ( & V_20 -> V_14 , V_4 ) ;
if ( F_171 ( V_4 ) )
goto V_45;
F_19 (part_md, &md->part, part) {
if ( F_171 ( V_28 ) )
goto V_45;
}
F_180 ( V_20 ) ;
F_185 ( & V_20 -> V_14 , 3000 ) ;
F_186 ( & V_20 -> V_14 ) ;
if ( V_20 -> type != V_357 ) {
F_187 ( & V_20 -> V_14 ) ;
F_188 ( & V_20 -> V_14 ) ;
}
return 0 ;
V_45:
F_167 ( V_20 , V_4 ) ;
F_159 ( V_4 ) ;
return 0 ;
}
static void F_189 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_74 ( & V_20 -> V_14 ) ;
F_167 ( V_20 , V_4 ) ;
F_190 ( & V_20 -> V_14 ) ;
F_191 ( V_20 -> V_85 ) ;
F_50 ( V_20 , V_4 -> V_111 ) ;
F_192 ( V_20 -> V_85 ) ;
if ( V_20 -> type != V_357 )
F_193 ( & V_20 -> V_14 ) ;
F_194 ( & V_20 -> V_14 ) ;
F_159 ( V_4 ) ;
F_184 ( & V_20 -> V_14 , NULL ) ;
}
static int F_195 ( struct V_19 * V_20 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_74 ( & V_20 -> V_14 ) ;
if ( V_4 ) {
F_196 ( & V_4 -> V_11 ) ;
F_19 (part_md, &md->part, part) {
F_196 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static void F_197 ( struct V_19 * V_20 )
{
F_195 ( V_20 ) ;
}
static int F_198 ( struct V_13 * V_14 )
{
struct V_19 * V_20 = F_199 ( V_14 ) ;
return F_195 ( V_20 ) ;
}
static int F_200 ( struct V_13 * V_14 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_74 ( V_14 ) ;
if ( V_4 ) {
V_4 -> V_138 = V_4 -> V_111 ;
F_201 ( & V_4 -> V_11 ) ;
F_19 (part_md, &md->part, part) {
F_201 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static int T_13 F_202 ( void )
{
int V_358 ;
if ( V_10 != V_359 )
F_17 ( L_53 , V_10 ) ;
V_297 = F_203 ( V_360 , ( 1 << V_361 ) / V_10 ) ;
V_358 = F_204 ( V_304 , L_54 ) ;
if ( V_358 )
goto V_45;
V_358 = F_205 ( & V_362 ) ;
if ( V_358 )
goto V_363;
return 0 ;
V_363:
F_206 ( V_304 , L_54 ) ;
V_45:
return V_358 ;
}
static void T_14 F_207 ( void )
{
F_208 ( & V_362 ) ;
F_206 ( V_304 , L_54 ) ;
}
