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
unsigned long V_29 ;
if ( F_13 ( V_17 , 0 , & V_29 ) )
return - V_30 ;
if ( V_29 != 1 )
return V_27 ;
V_4 = F_1 ( F_11 ( V_14 ) ) ;
V_20 = V_4 -> V_11 . V_20 ;
F_14 ( V_20 ) ;
V_18 = F_15 ( V_20 , V_31 , V_32 ,
V_20 -> V_22 . V_23 |
V_25 ,
V_20 -> V_22 . V_33 ) ;
if ( V_18 )
F_16 ( L_2 , V_4 -> V_3 -> V_34 , V_18 ) ;
else
V_20 -> V_22 . V_23 |= V_25 ;
F_17 ( V_20 ) ;
if ( ! V_18 ) {
F_18 ( L_3 ,
V_4 -> V_3 -> V_34 ) ;
F_19 ( V_4 -> V_3 , 1 ) ;
F_20 (part_md, &md->part, part)
if ( V_28 -> V_35 == V_36 ) {
F_18 ( L_3 , V_28 -> V_3 -> V_34 ) ;
F_19 ( V_28 -> V_3 , 1 ) ;
}
}
F_5 ( V_4 ) ;
return V_27 ;
}
static T_1 F_21 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_18 ;
struct V_1 * V_4 = F_1 ( F_11 ( V_14 ) ) ;
V_18 = snprintf ( V_17 , V_26 , L_1 ,
F_22 ( F_11 ( V_14 ) ) ^
V_4 -> V_37 ) ;
F_5 ( V_4 ) ;
return V_18 ;
}
static T_1 F_23 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_2 V_27 )
{
int V_18 ;
char * V_38 ;
struct V_1 * V_4 = F_1 ( F_11 ( V_14 ) ) ;
unsigned long V_29 = F_24 ( V_17 , & V_38 , 0 ) ;
if ( V_38 == V_17 ) {
V_18 = - V_30 ;
goto V_39;
}
F_19 ( F_11 ( V_14 ) , V_29 || V_4 -> V_37 ) ;
V_18 = V_27 ;
V_39:
F_5 ( V_4 ) ;
return V_18 ;
}
static int F_25 ( struct V_40 * V_41 , T_3 V_42 )
{
struct V_1 * V_4 = F_1 ( V_41 -> V_43 ) ;
int V_18 = - V_44 ;
F_2 ( & V_45 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_26 ( V_41 ) ;
V_18 = 0 ;
if ( ( V_42 & V_46 ) && V_4 -> V_37 ) {
F_5 ( V_4 ) ;
V_18 = - V_47 ;
}
}
F_3 ( & V_45 ) ;
return V_18 ;
}
static void F_27 ( struct V_2 * V_3 , T_3 V_42 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_45 ) ;
F_5 ( V_4 ) ;
F_3 ( & V_45 ) ;
}
static int
F_28 ( struct V_40 * V_41 , struct V_48 * V_49 )
{
V_49 -> V_50 = F_29 ( V_41 -> V_43 ) / ( 4 * 16 ) ;
V_49 -> V_51 = 4 ;
V_49 -> V_52 = 16 ;
return 0 ;
}
static struct V_53 * F_30 (
struct V_54 T_4 * V_55 )
{
struct V_53 * V_56 ;
int V_57 ;
V_56 = F_31 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 ) {
V_57 = - V_59 ;
goto V_39;
}
if ( F_32 ( & V_56 -> V_60 , V_55 , sizeof( V_56 -> V_60 ) ) ) {
V_57 = - V_61 ;
goto V_62;
}
V_56 -> V_63 = ( V_64 ) V_56 -> V_60 . V_65 * V_56 -> V_60 . V_66 ;
if ( V_56 -> V_63 > V_67 ) {
V_57 = - V_68 ;
goto V_62;
}
if ( ! V_56 -> V_63 ) {
V_56 -> V_17 = NULL ;
return V_56 ;
}
V_56 -> V_17 = F_31 ( V_56 -> V_63 , V_58 ) ;
if ( ! V_56 -> V_17 ) {
V_57 = - V_59 ;
goto V_62;
}
if ( F_32 ( V_56 -> V_17 , ( void T_4 * ) ( unsigned long )
V_56 -> V_60 . V_69 , V_56 -> V_63 ) ) {
V_57 = - V_61 ;
goto V_70;
}
return V_56 ;
V_70:
F_9 ( V_56 -> V_17 ) ;
V_62:
F_9 ( V_56 ) ;
V_39:
return F_33 ( V_57 ) ;
}
static int F_34 ( struct V_54 T_4 * V_71 ,
struct V_53 * V_56 )
{
struct V_54 * V_60 = & V_56 -> V_60 ;
if ( F_35 ( & ( V_71 -> V_72 ) , V_60 -> V_72 ,
sizeof( V_60 -> V_72 ) ) )
return - V_61 ;
if ( ! V_56 -> V_60 . V_73 ) {
if ( F_35 ( ( void T_4 * ) ( unsigned long ) V_60 -> V_69 ,
V_56 -> V_17 , V_56 -> V_63 ) )
return - V_61 ;
}
return 0 ;
}
static int F_36 ( struct V_19 * V_20 , T_5 * V_74 ,
T_5 V_75 )
{
int V_57 ;
T_5 V_76 = 0 ;
if ( ! V_74 || ! V_75 )
return - V_30 ;
do {
V_57 = F_37 ( V_20 , V_74 , 5 ) ;
if ( V_57 )
break;
if ( ! F_38 ( * V_74 ) &&
( F_39 ( * V_74 ) != V_77 ) )
break;
F_40 ( 1000 , 5000 ) ;
} while ( ++ V_76 < V_75 );
if ( V_76 == V_75 )
V_57 = - V_78 ;
return V_57 ;
}
static int F_41 ( struct V_19 * V_20 )
{
int V_57 ;
if ( ! F_42 ( V_20 ) ) {
F_43 ( L_4 ,
F_44 ( V_20 -> V_79 ) , V_80 ) ;
V_57 = - V_81 ;
goto V_39;
}
F_45 ( L_5 ,
F_44 ( V_20 -> V_79 ) , V_80 ) ;
V_57 = F_15 ( V_20 , V_31 ,
V_82 , 1 ,
V_83 ) ;
if ( V_57 )
F_16 ( L_6 ,
F_44 ( V_20 -> V_79 ) , V_80 , V_57 ) ;
F_45 ( L_7 , F_44 ( V_20 -> V_79 ) ,
V_80 ) ;
V_39:
return V_57 ;
}
static int F_46 ( struct V_19 * V_20 , struct V_1 * V_4 ,
struct V_53 * V_56 )
{
struct V_84 V_85 = {} ;
struct V_86 V_87 = {} ;
struct V_88 V_89 = {} ;
struct V_90 V_91 ;
int V_57 ;
int V_92 = false ;
T_5 V_74 = 0 ;
if ( ! V_20 || ! V_4 || ! V_56 )
return - V_30 ;
if ( V_4 -> V_35 & V_93 )
V_92 = true ;
V_85 . V_94 = V_56 -> V_60 . V_94 ;
V_85 . V_95 = V_56 -> V_60 . V_95 ;
V_85 . V_96 = V_56 -> V_60 . V_96 ;
if ( V_56 -> V_63 ) {
V_87 . V_91 = & V_91 ;
V_87 . V_97 = 1 ;
V_87 . V_65 = V_56 -> V_60 . V_65 ;
V_87 . V_66 = V_56 -> V_60 . V_66 ;
F_47 ( V_87 . V_91 , V_56 -> V_17 , V_56 -> V_63 ) ;
if ( V_56 -> V_60 . V_73 )
V_87 . V_96 = V_98 ;
else
V_87 . V_96 = V_99 ;
F_48 ( & V_87 , V_20 ) ;
if ( V_56 -> V_60 . V_100 )
V_87 . V_101 = V_56 -> V_60 . V_100 ;
if ( ( V_85 . V_96 & V_102 ) == V_102 ) {
V_87 . V_101 = V_56 -> V_60 . V_103 * 1000000 ;
}
V_89 . V_87 = & V_87 ;
}
V_89 . V_85 = & V_85 ;
V_57 = F_49 ( V_20 , V_4 ) ;
if ( V_57 )
return V_57 ;
if ( V_56 -> V_60 . V_104 ) {
V_57 = F_50 ( V_20 -> V_79 , V_20 ) ;
if ( V_57 )
return V_57 ;
}
if ( V_92 ) {
V_57 = F_51 ( V_20 , V_87 . V_66 ,
V_56 -> V_60 . V_73 & ( 1 << 31 ) ) ;
if ( V_57 )
return V_57 ;
}
if ( ( F_52 ( V_85 . V_95 ) == V_82 ) &&
( V_85 . V_94 == V_105 ) ) {
V_57 = F_41 ( V_20 ) ;
if ( V_57 )
F_16 ( L_8 ,
V_80 , V_57 ) ;
return V_57 ;
}
F_53 ( V_20 -> V_79 , & V_89 ) ;
if ( V_85 . error ) {
F_54 ( F_55 ( V_20 -> V_79 ) , L_9 ,
V_80 , V_85 . error ) ;
return V_85 . error ;
}
if ( V_87 . error ) {
F_54 ( F_55 ( V_20 -> V_79 ) , L_10 ,
V_80 , V_87 . error ) ;
return V_87 . error ;
}
if ( V_56 -> V_60 . V_106 )
F_40 ( V_56 -> V_60 . V_106 , V_56 -> V_60 . V_107 ) ;
memcpy ( & ( V_56 -> V_60 . V_72 ) , V_85 . V_108 , sizeof( V_85 . V_108 ) ) ;
if ( V_92 ) {
V_57 = F_36 ( V_20 , & V_74 , 5 ) ;
if ( V_57 )
F_54 ( F_55 ( V_20 -> V_79 ) ,
L_11 ,
V_80 , V_74 , V_57 ) ;
}
return V_57 ;
}
static int F_56 ( struct V_40 * V_41 ,
struct V_54 T_4 * V_71 )
{
struct V_53 * V_56 ;
struct V_1 * V_4 ;
struct V_19 * V_20 ;
int V_57 = 0 , V_109 = 0 ;
if ( ( ! F_57 ( V_110 ) ) || ( V_41 != V_41 -> V_111 ) )
return - V_78 ;
V_56 = F_30 ( V_71 ) ;
if ( F_58 ( V_56 ) )
return F_59 ( V_56 ) ;
V_4 = F_1 ( V_41 -> V_43 ) ;
if ( ! V_4 ) {
V_57 = - V_30 ;
goto V_112;
}
V_20 = V_4 -> V_11 . V_20 ;
if ( F_58 ( V_20 ) ) {
V_57 = F_59 ( V_20 ) ;
goto V_113;
}
F_14 ( V_20 ) ;
V_109 = F_46 ( V_20 , V_4 , V_56 ) ;
if ( V_4 -> V_35 & V_93 )
F_49 ( V_20 , F_60 ( & V_20 -> V_14 ) ) ;
F_17 ( V_20 ) ;
V_57 = F_34 ( V_71 , V_56 ) ;
V_113:
F_5 ( V_4 ) ;
V_112:
F_9 ( V_56 -> V_17 ) ;
F_9 ( V_56 ) ;
return V_109 ? V_109 : V_57 ;
}
static int F_61 ( struct V_40 * V_41 ,
struct V_114 T_4 * V_55 )
{
struct V_53 * * V_56 = NULL ;
struct V_54 T_4 * V_115 = V_55 -> V_115 ;
struct V_19 * V_20 ;
struct V_1 * V_4 ;
int V_116 , V_57 = 0 , V_109 = 0 ;
T_6 V_117 ;
if ( ( ! F_57 ( V_110 ) ) || ( V_41 != V_41 -> V_111 ) )
return - V_78 ;
if ( F_32 ( & V_117 , & V_55 -> V_117 ,
sizeof( V_117 ) ) )
return - V_61 ;
if ( V_117 > V_118 )
return - V_30 ;
V_56 = F_62 ( V_117 , sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
V_56 [ V_116 ] = F_30 ( & V_115 [ V_116 ] ) ;
if ( F_58 ( V_56 [ V_116 ] ) ) {
V_57 = F_59 ( V_56 [ V_116 ] ) ;
V_117 = V_116 ;
goto V_112;
}
}
V_4 = F_1 ( V_41 -> V_43 ) ;
if ( ! V_4 ) {
V_57 = - V_30 ;
goto V_112;
}
V_20 = V_4 -> V_11 . V_20 ;
if ( F_58 ( V_20 ) ) {
V_57 = F_59 ( V_20 ) ;
goto V_113;
}
F_14 ( V_20 ) ;
for ( V_116 = 0 ; V_116 < V_117 && ! V_109 ; V_116 ++ )
V_109 = F_46 ( V_20 , V_4 , V_56 [ V_116 ] ) ;
if ( V_4 -> V_35 & V_93 )
F_49 ( V_20 , F_60 ( & V_20 -> V_14 ) ) ;
F_17 ( V_20 ) ;
for ( V_116 = 0 ; V_116 < V_117 && ! V_57 ; V_116 ++ )
V_57 = F_34 ( & V_115 [ V_116 ] , V_56 [ V_116 ] ) ;
V_113:
F_5 ( V_4 ) ;
V_112:
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ ) {
F_9 ( V_56 [ V_116 ] -> V_17 ) ;
F_9 ( V_56 [ V_116 ] ) ;
}
F_9 ( V_56 ) ;
return V_109 ? V_109 : V_57 ;
}
static int F_63 ( struct V_40 * V_41 , T_3 V_42 ,
unsigned int V_85 , unsigned long V_95 )
{
switch ( V_85 ) {
case V_119 :
return F_56 ( V_41 ,
(struct V_54 T_4 * ) V_95 ) ;
case V_120 :
return F_61 ( V_41 ,
(struct V_114 T_4 * ) V_95 ) ;
default:
return - V_30 ;
}
}
static int F_64 ( struct V_40 * V_41 , T_3 V_42 ,
unsigned int V_85 , unsigned long V_95 )
{
return F_63 ( V_41 , V_42 , V_85 , ( unsigned long ) F_65 ( V_95 ) ) ;
}
static inline int F_49 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
int V_18 ;
struct V_1 * V_121 = F_60 ( & V_20 -> V_14 ) ;
if ( V_121 -> V_122 == V_4 -> V_123 )
return 0 ;
if ( F_66 ( V_20 ) ) {
T_7 V_124 = V_20 -> V_22 . V_124 ;
if ( V_4 -> V_123 == V_125 )
F_67 ( V_20 -> V_79 ) ;
V_124 &= ~ V_126 ;
V_124 |= V_4 -> V_123 ;
V_18 = F_15 ( V_20 , V_31 ,
V_127 , V_124 ,
V_20 -> V_22 . V_33 ) ;
if ( V_18 ) {
if ( V_4 -> V_123 == V_125 )
F_68 ( V_20 -> V_79 ) ;
return V_18 ;
}
V_20 -> V_22 . V_124 = V_124 ;
if ( V_121 -> V_122 == V_125 )
F_68 ( V_20 -> V_79 ) ;
}
V_121 -> V_122 = V_4 -> V_123 ;
return 0 ;
}
static int F_69 ( struct V_19 * V_20 , T_5 * V_128 )
{
int V_57 ;
T_5 V_129 ;
T_8 * V_66 ;
struct V_88 V_89 = {} ;
struct V_84 V_85 = {} ;
struct V_86 V_87 = {} ;
struct V_90 V_91 ;
V_85 . V_94 = V_130 ;
V_85 . V_95 = V_20 -> V_131 << 16 ;
V_85 . V_96 = V_132 | V_133 | V_134 ;
V_57 = F_70 ( V_20 -> V_79 , & V_85 , 0 ) ;
if ( V_57 )
return V_57 ;
if ( ! F_71 ( V_20 -> V_79 ) && ! ( V_85 . V_108 [ 0 ] & V_135 ) )
return - V_136 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . V_94 = V_137 ;
V_85 . V_95 = 0 ;
V_85 . V_96 = V_132 | V_133 | V_138 ;
V_87 . V_65 = 4 ;
V_87 . V_66 = 1 ;
V_87 . V_96 = V_99 ;
V_87 . V_91 = & V_91 ;
V_87 . V_97 = 1 ;
F_48 ( & V_87 , V_20 ) ;
V_89 . V_85 = & V_85 ;
V_89 . V_87 = & V_87 ;
V_66 = F_31 ( 4 , V_58 ) ;
if ( ! V_66 )
return - V_59 ;
F_47 ( & V_91 , V_66 , 4 ) ;
F_53 ( V_20 -> V_79 , & V_89 ) ;
V_129 = F_72 ( * V_66 ) ;
F_9 ( V_66 ) ;
if ( V_85 . error || V_87 . error )
return - V_136 ;
* V_128 = V_129 ;
return 0 ;
}
static int F_37 ( struct V_19 * V_20 , T_5 * V_74 , int V_139 )
{
struct V_84 V_85 = {} ;
int V_57 ;
V_85 . V_94 = V_140 ;
if ( ! F_71 ( V_20 -> V_79 ) )
V_85 . V_95 = V_20 -> V_131 << 16 ;
V_85 . V_96 = V_141 | V_133 | V_134 ;
V_57 = F_70 ( V_20 -> V_79 , & V_85 , V_139 ) ;
if ( V_57 == 0 )
* V_74 = V_85 . V_108 [ 0 ] ;
return V_57 ;
}
static int F_73 ( struct V_19 * V_20 , unsigned int V_142 ,
bool V_143 , struct V_144 * V_145 , bool * V_146 )
{
unsigned long V_147 = V_148 + F_74 ( V_142 ) ;
int V_57 = 0 ;
T_5 V_74 ;
do {
V_57 = F_37 ( V_20 , & V_74 , 5 ) ;
if ( V_57 ) {
F_16 ( L_12 ,
V_145 -> V_149 -> V_34 , V_57 ) ;
return V_57 ;
}
if ( V_74 & V_150 ) {
F_16 ( L_13 ,
V_145 -> V_149 -> V_34 , V_80 , V_74 ) ;
* V_146 = true ;
}
if ( ( V_20 -> V_79 -> V_151 & V_152 ) &&
V_143 )
break;
if ( F_75 ( V_148 , V_147 ) ) {
F_16 ( L_14 ,
F_44 ( V_20 -> V_79 ) ,
V_145 -> V_149 -> V_34 , V_80 ) ;
return - V_153 ;
}
} while ( ! ( V_74 & V_154 ) ||
( F_39 ( V_74 ) == V_77 ) );
return V_57 ;
}
static int F_76 ( struct V_19 * V_20 , unsigned int V_142 ,
struct V_144 * V_145 , bool * V_146 , T_5 * V_155 )
{
struct V_156 * V_79 = V_20 -> V_79 ;
struct V_84 V_85 = {} ;
int V_57 ;
bool V_157 = F_77 ( V_145 ) == V_158 ;
if ( V_79 -> V_159 && ( V_142 > V_79 -> V_159 ) )
V_157 = false ;
V_85 . V_94 = V_160 ;
if ( V_157 ) {
V_85 . V_96 = V_161 | V_102 | V_134 ;
V_85 . V_162 = V_142 ;
} else {
V_85 . V_96 = V_132 | V_133 | V_134 ;
}
V_57 = F_70 ( V_79 , & V_85 , 5 ) ;
if ( V_57 )
return V_57 ;
* V_155 = V_85 . V_108 [ 0 ] ;
if ( F_77 ( V_145 ) == V_163 )
return 0 ;
if ( ! F_71 ( V_79 ) &&
( * V_155 & V_150 ) ) {
F_16 ( L_15 ,
V_145 -> V_149 -> V_34 , V_80 , * V_155 ) ;
* V_146 = true ;
}
return F_73 ( V_20 , V_142 , V_157 , V_145 , V_146 ) ;
}
static int F_78 ( struct V_144 * V_145 , const char * V_164 , int error ,
bool V_165 , T_5 V_74 )
{
switch ( error ) {
case - V_166 :
F_16 ( L_16 ,
V_145 -> V_149 -> V_34 , L_17 ,
V_164 , V_74 ) ;
return V_167 ;
case - V_153 :
F_16 ( L_16 ,
V_145 -> V_149 -> V_34 , L_18 , V_164 , V_74 ) ;
if ( ! V_165 ) {
F_16 ( L_19 ,
V_145 -> V_149 -> V_34 ) ;
return V_167 ;
}
if ( V_74 & ( V_168 | V_169 ) ) {
F_16 ( L_20 ,
V_145 -> V_149 -> V_34 ) ;
return V_167 ;
}
return V_170 ;
default:
F_16 ( L_21 ,
V_145 -> V_149 -> V_34 , error , V_74 ) ;
return V_170 ;
}
}
static int F_79 ( struct V_19 * V_20 , struct V_144 * V_145 ,
struct V_171 * V_172 , bool * V_173 , bool * V_146 )
{
bool V_174 = true ;
T_5 V_74 , V_155 = 0 ;
int V_57 , V_175 ;
if ( F_80 ( V_20 ) )
return V_176 ;
for ( V_175 = 2 ; V_175 >= 0 ; V_175 -- ) {
V_57 = F_37 ( V_20 , & V_74 , 0 ) ;
if ( ! V_57 )
break;
F_81 ( V_20 -> V_79 ) ;
V_174 = false ;
F_16 ( L_22 ,
V_145 -> V_149 -> V_34 , V_57 , V_175 ? L_23 : L_24 ) ;
}
if ( V_57 ) {
if ( F_82 ( V_20 -> V_79 ) )
return V_176 ;
return V_170 ;
}
if ( ( V_74 & V_177 ) ||
( V_172 -> V_178 . V_108 [ 0 ] & V_177 ) ||
( V_172 -> V_85 . V_108 [ 0 ] & V_177 ) )
* V_173 = true ;
if ( ! F_71 ( V_20 -> V_79 ) && F_77 ( V_145 ) != V_163 )
if ( ( V_74 & V_150 ) ||
( V_172 -> V_178 . V_108 [ 0 ] & V_150 ) ) {
F_16 ( L_25 ,
V_145 -> V_149 -> V_34 , V_80 ,
V_172 -> V_178 . V_108 [ 0 ] , V_74 ) ;
* V_146 = true ;
}
if ( F_39 ( V_74 ) == V_179 ||
F_39 ( V_74 ) == V_180 ) {
V_57 = F_76 ( V_20 ,
F_83 ( V_172 -> V_87 . V_101 , 1000000 ) ,
V_145 , V_146 , & V_155 ) ;
if ( V_57 ) {
F_16 ( L_26 ,
V_145 -> V_149 -> V_34 , V_57 ) ;
return V_170 ;
}
if ( V_155 & V_177 )
* V_173 = true ;
}
if ( V_172 -> V_181 . error )
return F_78 ( V_145 , L_27 , V_172 -> V_181 . error ,
V_174 , V_74 ) ;
if ( V_172 -> V_85 . error )
return F_78 ( V_145 , L_28 , V_172 -> V_85 . error ,
V_174 , V_74 ) ;
if ( ! V_172 -> V_178 . error )
return V_182 ;
F_18 ( L_29 ,
V_145 -> V_149 -> V_34 , V_172 -> V_178 . error ,
V_172 -> V_85 . V_108 [ 0 ] , V_74 ) ;
if ( V_155 ) {
V_172 -> V_178 . V_108 [ 0 ] = V_155 ;
V_172 -> V_178 . error = 0 ;
}
return V_182 ;
}
static int F_84 ( struct V_1 * V_4 , struct V_156 * V_79 ,
int type )
{
int V_57 ;
if ( V_4 -> V_183 & type )
return - V_184 ;
V_4 -> V_183 |= type ;
V_57 = F_85 ( V_79 ) ;
if ( V_57 != - V_81 ) {
struct V_1 * V_121 =
F_60 ( & V_79 -> V_20 -> V_14 ) ;
int V_185 ;
V_121 -> V_122 = V_121 -> V_123 ;
V_185 = F_49 ( V_79 -> V_20 , V_4 ) ;
if ( V_185 ) {
return - V_186 ;
}
}
return V_57 ;
}
static inline void F_86 ( struct V_1 * V_4 , int type )
{
V_4 -> V_183 &= ~ type ;
}
int F_87 ( struct V_187 * V_188 )
{
struct V_1 * V_4 = V_188 -> V_189 ;
if ( V_4 && V_4 -> V_123 == V_125 )
return true ;
return false ;
}
static void F_88 ( struct V_187 * V_188 , struct V_144 * V_145 )
{
struct V_1 * V_4 = V_188 -> V_189 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_190 , V_191 , V_95 ;
int V_57 = 0 , type = V_192 ;
if ( ! F_89 ( V_20 ) ) {
V_57 = - V_81 ;
goto V_193;
}
V_190 = F_90 ( V_145 ) ;
V_191 = F_91 ( V_145 ) ;
if ( F_92 ( V_20 ) )
V_95 = V_194 ;
else if ( F_93 ( V_20 ) )
V_95 = V_195 ;
else
V_95 = V_196 ;
do {
V_57 = 0 ;
if ( V_20 -> V_197 & V_198 ) {
V_57 = F_15 ( V_20 , V_31 ,
V_199 ,
V_95 == V_195 ?
V_200 :
V_201 ,
0 ) ;
}
if ( ! V_57 )
V_57 = F_94 ( V_20 , V_190 , V_191 , V_95 ) ;
} while ( V_57 == - V_136 && ! F_84 ( V_4 , V_20 -> V_79 , type ) );
if ( ! V_57 )
F_86 ( V_4 , type ) ;
V_193:
F_95 ( V_145 , V_57 , F_96 ( V_145 ) ) ;
}
static void F_97 ( struct V_187 * V_188 ,
struct V_144 * V_145 )
{
struct V_1 * V_4 = V_188 -> V_189 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
unsigned int V_190 , V_191 , V_95 ;
int V_57 = 0 , type = V_202 ;
if ( ! ( F_98 ( V_20 ) ) ) {
V_57 = - V_81 ;
goto V_39;
}
V_190 = F_90 ( V_145 ) ;
V_191 = F_91 ( V_145 ) ;
if ( F_93 ( V_20 ) && ! F_99 ( V_20 , V_190 , V_191 ) )
V_95 = V_203 ;
else
V_95 = V_204 ;
V_175:
if ( V_20 -> V_197 & V_198 ) {
V_57 = F_15 ( V_20 , V_31 ,
V_199 ,
V_95 == V_203 ?
V_205 :
V_206 ,
0 ) ;
if ( V_57 )
goto V_207;
}
V_57 = F_94 ( V_20 , V_190 , V_191 , V_95 ) ;
if ( V_57 == - V_136 )
goto V_207;
if ( V_57 )
goto V_39;
if ( V_95 == V_203 ) {
if ( V_20 -> V_197 & V_198 ) {
V_57 = F_15 ( V_20 , V_31 ,
V_199 ,
V_208 ,
0 ) ;
if ( V_57 )
goto V_207;
}
V_57 = F_94 ( V_20 , V_190 , V_191 , V_209 ) ;
if ( V_57 == - V_136 )
goto V_207;
if ( V_57 )
goto V_39;
}
V_207:
if ( V_57 && ! F_84 ( V_4 , V_20 -> V_79 , type ) )
goto V_175;
if ( ! V_57 )
F_86 ( V_4 , type ) ;
V_39:
F_95 ( V_145 , V_57 , F_96 ( V_145 ) ) ;
}
static void F_100 ( struct V_187 * V_188 , struct V_144 * V_145 )
{
struct V_1 * V_4 = V_188 -> V_189 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
int V_18 = 0 ;
V_18 = F_101 ( V_20 ) ;
if ( V_18 )
V_18 = - V_136 ;
F_102 ( V_145 , V_18 ) ;
}
static inline void F_103 ( struct V_171 * V_172 ,
struct V_19 * V_20 ,
struct V_144 * V_145 )
{
if ( ! ( V_20 -> V_22 . V_210 & V_211 ) ) {
if ( ! F_104 ( V_172 -> V_85 . V_95 , V_20 -> V_22 . V_212 ) )
V_172 -> V_87 . V_66 = 1 ;
if ( V_172 -> V_87 . V_66 > V_20 -> V_22 . V_212 )
V_172 -> V_87 . V_66 = V_20 -> V_22 . V_212 ;
else if ( V_172 -> V_87 . V_66 < V_20 -> V_22 . V_212 )
V_172 -> V_87 . V_66 = 1 ;
}
}
static enum V_213 F_105 ( struct V_19 * V_20 ,
struct V_214 * V_215 )
{
struct V_216 * V_217 = F_106 ( V_215 , struct V_216 ,
V_215 ) ;
struct V_171 * V_172 = & V_217 -> V_172 ;
struct V_144 * V_145 = V_217 -> V_145 ;
int V_218 = V_20 -> V_79 -> V_218 ;
bool V_173 = false ;
bool V_146 = false ;
if ( V_172 -> V_181 . error || V_172 -> V_85 . error || V_172 -> V_178 . error ||
V_172 -> V_87 . error ) {
switch ( F_79 ( V_20 , V_145 , V_172 , & V_173 , & V_146 ) ) {
case V_167 :
return V_219 ;
case V_170 :
return V_220 ;
case V_176 :
return V_221 ;
case V_182 :
break;
}
}
if ( V_172 -> V_85 . V_108 [ 0 ] & V_222 ) {
F_16 ( L_30 ,
V_145 -> V_149 -> V_34 , V_172 -> V_85 . V_108 [ 0 ] ) ;
return V_220 ;
}
if ( ! F_71 ( V_20 -> V_79 ) && F_77 ( V_145 ) != V_163 ) {
int V_57 ;
if ( V_172 -> V_178 . V_108 [ 0 ] & V_150 ) {
F_16 ( L_31 ,
V_145 -> V_149 -> V_34 , V_80 ,
V_172 -> V_178 . V_108 [ 0 ] ) ;
V_146 = true ;
}
V_57 = F_73 ( V_20 , V_223 , false , V_145 ,
& V_146 ) ;
if ( V_57 )
return V_224 ;
}
if ( V_146 ) {
F_43 ( L_32 ,
V_145 -> V_149 -> V_34 ) ;
return V_219 ;
}
if ( V_172 -> V_87 . error ) {
if ( V_218 && ! V_172 -> V_225 ) {
F_45 ( L_33 ,
V_145 -> V_149 -> V_34 ) ;
V_172 -> V_225 = 1 ;
return V_219 ;
}
F_16 ( L_34 ,
V_145 -> V_149 -> V_34 , V_172 -> V_87 . error ,
( unsigned ) F_90 ( V_145 ) ,
( unsigned ) F_91 ( V_145 ) ,
V_172 -> V_85 . V_108 [ 0 ] , V_172 -> V_178 . V_108 [ 0 ] ) ;
if ( F_77 ( V_145 ) == V_163 ) {
if ( V_173 )
return V_226 ;
return V_227 ;
} else {
return V_224 ;
}
}
if ( ! V_172 -> V_87 . V_228 )
return V_219 ;
if ( F_96 ( V_145 ) != V_172 -> V_87 . V_228 )
return V_229 ;
return V_230 ;
}
static void F_107 ( struct V_216 * V_231 ,
struct V_19 * V_20 ,
int V_232 ,
struct V_187 * V_188 )
{
T_5 V_233 , V_234 ;
struct V_171 * V_172 = & V_231 -> V_172 ;
struct V_144 * V_145 = V_231 -> V_145 ;
struct V_1 * V_4 = V_188 -> V_189 ;
bool V_235 ;
bool V_236 = ( V_145 -> V_237 & V_238 ) &&
( F_77 ( V_145 ) == V_158 ) &&
( V_4 -> V_96 & V_239 ) ;
memset ( V_172 , 0 , sizeof( struct V_171 ) ) ;
V_172 -> V_89 . V_85 = & V_172 -> V_85 ;
V_172 -> V_89 . V_87 = & V_172 -> V_87 ;
V_172 -> V_85 . V_95 = F_90 ( V_145 ) ;
if ( ! F_108 ( V_20 ) )
V_172 -> V_85 . V_95 <<= 9 ;
V_172 -> V_85 . V_96 = V_132 | V_133 | V_138 ;
V_172 -> V_87 . V_65 = 512 ;
V_172 -> V_178 . V_94 = V_160 ;
V_172 -> V_178 . V_95 = 0 ;
V_172 -> V_87 . V_66 = F_91 ( V_145 ) ;
if ( V_172 -> V_87 . V_66 > V_20 -> V_79 -> V_240 )
V_172 -> V_87 . V_66 = V_20 -> V_79 -> V_240 ;
if ( V_172 -> V_87 . V_66 > 1 ) {
if ( V_232 )
V_172 -> V_87 . V_66 = 1 ;
if ( V_20 -> V_79 -> V_241 -> V_242 )
V_172 -> V_87 . V_66 = V_20 -> V_79 -> V_241 -> V_242 ( V_20 ,
( F_77 ( V_145 ) == V_163 ) ?
V_99 : V_98 ,
V_172 -> V_87 . V_66 ) ;
}
if ( V_172 -> V_87 . V_66 > 1 || V_236 ) {
if ( ! F_71 ( V_20 -> V_79 ) ||
F_77 ( V_145 ) == V_163 )
V_172 -> V_89 . V_178 = & V_172 -> V_178 ;
V_233 = V_243 ;
V_234 = V_244 ;
} else {
V_172 -> V_89 . V_178 = NULL ;
V_233 = V_245 ;
V_234 = V_246 ;
}
if ( F_77 ( V_145 ) == V_163 ) {
V_172 -> V_85 . V_94 = V_233 ;
V_172 -> V_87 . V_96 = V_99 ;
if ( V_172 -> V_89 . V_178 )
V_172 -> V_178 . V_96 = V_132 | V_133 |
V_134 ;
} else {
V_172 -> V_85 . V_94 = V_234 ;
V_172 -> V_87 . V_96 = V_98 ;
if ( V_172 -> V_89 . V_178 )
V_172 -> V_178 . V_96 = V_161 | V_102 |
V_134 ;
}
if ( V_236 )
F_103 ( V_172 , V_20 , V_145 ) ;
V_235 = ( V_20 -> V_22 . V_247 ) &&
( V_145 -> V_237 & V_248 ) &&
( F_77 ( V_145 ) == V_158 ) &&
( ( V_172 -> V_87 . V_66 * V_172 -> V_87 . V_65 ) >=
V_20 -> V_22 . V_247 ) ;
if ( ( V_4 -> V_96 & V_249 ) && F_109 ( V_172 -> V_85 . V_94 ) &&
( V_236 || ! ( V_20 -> V_197 & V_250 ) ||
V_235 ) ) {
V_172 -> V_181 . V_94 = V_251 ;
V_172 -> V_181 . V_95 = V_172 -> V_87 . V_66 |
( V_236 ? ( 1 << 31 ) : 0 ) |
( V_235 ? ( 1 << 29 ) : 0 ) ;
V_172 -> V_181 . V_96 = V_133 | V_134 ;
V_172 -> V_89 . V_181 = & V_172 -> V_181 ;
}
F_48 ( & V_172 -> V_87 , V_20 ) ;
V_172 -> V_87 . V_91 = V_231 -> V_91 ;
V_172 -> V_87 . V_97 = F_110 ( V_188 , V_231 ) ;
if ( V_172 -> V_87 . V_66 != F_91 ( V_145 ) ) {
int V_116 , V_252 = V_172 -> V_87 . V_66 << 9 ;
struct V_90 * V_91 ;
F_111 (brq->data.sg, sg, brq->data.sg_len, i) {
V_252 -= V_91 -> V_253 ;
if ( V_252 <= 0 ) {
V_91 -> V_253 += V_252 ;
V_116 ++ ;
break;
}
}
V_172 -> V_87 . V_97 = V_116 ;
}
V_231 -> V_215 . V_89 = & V_172 -> V_89 ;
V_231 -> V_215 . V_254 = F_105 ;
F_112 ( V_231 ) ;
}
static bool F_113 ( struct V_1 * V_4 , struct V_19 * V_20 ,
struct V_171 * V_172 , struct V_144 * V_145 ,
bool V_255 )
{
bool V_256 ;
if ( F_114 ( V_20 ) ) {
T_5 V_66 ;
int V_57 ;
V_57 = F_69 ( V_20 , & V_66 ) ;
if ( V_57 )
V_256 = V_255 ;
else
V_256 = F_95 ( V_145 , 0 , V_66 << 9 ) ;
} else {
V_256 = F_95 ( V_145 , 0 , V_172 -> V_87 . V_228 ) ;
}
return V_256 ;
}
static void F_115 ( struct V_19 * V_20 , struct V_144 * V_145 )
{
if ( F_80 ( V_20 ) )
V_145 -> V_257 |= V_258 ;
while ( F_95 ( V_145 , - V_136 , F_116 ( V_145 ) ) ) ;
}
static void F_117 ( struct V_187 * V_188 , struct V_144 * V_145 )
{
if ( ! V_145 )
return;
if ( F_80 ( V_188 -> V_20 ) ) {
V_145 -> V_257 |= V_258 ;
F_102 ( V_145 , - V_136 ) ;
return;
}
F_107 ( V_188 -> V_259 , V_188 -> V_20 , 0 , V_188 ) ;
F_118 ( V_188 -> V_20 -> V_79 , & V_188 -> V_259 -> V_215 , NULL ) ;
}
static void F_119 ( struct V_187 * V_188 , struct V_144 * V_260 )
{
struct V_1 * V_4 = V_188 -> V_189 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
struct V_171 * V_172 ;
int V_232 = 0 , V_175 = 0 , type , V_225 = 0 ;
enum V_213 V_74 ;
struct V_216 * V_261 ;
struct V_144 * V_262 ;
struct V_214 * V_263 ;
struct V_214 * V_264 ;
bool V_256 = true ;
if ( ! V_260 && ! V_188 -> V_265 -> V_145 )
return;
do {
if ( V_260 ) {
if ( F_120 ( V_20 ) &&
! F_104 ( F_91 ( V_260 ) , 8 ) ) {
F_16 ( L_35 ,
V_260 -> V_149 -> V_34 ) ;
F_115 ( V_20 , V_260 ) ;
return;
}
F_107 ( V_188 -> V_259 , V_20 , 0 , V_188 ) ;
V_263 = & V_188 -> V_259 -> V_215 ;
} else
V_263 = NULL ;
V_264 = F_118 ( V_20 -> V_79 , V_263 , & V_74 ) ;
if ( ! V_264 ) {
if ( V_74 == V_266 )
V_188 -> V_267 = true ;
return;
}
V_261 = F_106 ( V_264 , struct V_216 , V_215 ) ;
V_172 = & V_261 -> V_172 ;
V_262 = V_261 -> V_145 ;
type = F_77 ( V_262 ) == V_163 ? V_268 : V_269 ;
F_121 ( V_261 ) ;
switch ( V_74 ) {
case V_230 :
case V_229 :
F_86 ( V_4 , type ) ;
V_256 = F_95 ( V_262 , 0 ,
V_172 -> V_87 . V_228 ) ;
if ( V_74 == V_230 && V_256 ) {
F_16 ( L_36 ,
V_80 , F_96 ( V_262 ) ,
V_172 -> V_87 . V_228 ) ;
F_115 ( V_20 , V_262 ) ;
return;
}
break;
case V_224 :
V_256 = F_113 ( V_4 , V_20 , V_172 , V_262 , V_256 ) ;
if ( F_84 ( V_4 , V_20 -> V_79 , type ) ) {
if ( V_256 )
F_115 ( V_20 , V_262 ) ;
F_117 ( V_188 , V_260 ) ;
return;
}
if ( ! V_256 ) {
F_117 ( V_188 , V_260 ) ;
return;
}
break;
case V_219 :
V_225 = V_172 -> V_225 ;
if ( V_175 ++ < 5 )
break;
case V_220 :
if ( ! F_84 ( V_4 , V_20 -> V_79 , type ) )
break;
F_115 ( V_20 , V_262 ) ;
F_117 ( V_188 , V_260 ) ;
return;
case V_227 : {
int V_57 ;
V_57 = F_84 ( V_4 , V_20 -> V_79 , type ) ;
if ( ! V_57 )
break;
if ( V_57 == - V_186 ) {
F_115 ( V_20 , V_262 ) ;
F_117 ( V_188 , V_260 ) ;
return;
}
}
case V_226 :
if ( V_172 -> V_87 . V_66 > 1 ) {
F_43 ( L_37 ,
V_262 -> V_149 -> V_34 ) ;
V_232 = 1 ;
break;
}
V_256 = F_95 ( V_262 , - V_136 ,
V_172 -> V_87 . V_65 ) ;
if ( ! V_256 ) {
F_117 ( V_188 , V_260 ) ;
return;
}
break;
case V_221 :
F_115 ( V_20 , V_262 ) ;
F_117 ( V_188 , V_260 ) ;
return;
default:
F_16 ( L_38 ,
V_262 -> V_149 -> V_34 , V_74 ) ;
F_115 ( V_20 , V_262 ) ;
F_117 ( V_188 , V_260 ) ;
return;
}
if ( V_256 ) {
F_107 ( V_261 , V_20 ,
V_232 , V_188 ) ;
F_118 ( V_20 -> V_79 ,
& V_261 -> V_215 , NULL ) ;
V_261 -> V_172 . V_225 = V_225 ;
}
} while ( V_256 );
}
void F_122 ( struct V_187 * V_188 , struct V_144 * V_145 )
{
int V_18 ;
struct V_1 * V_4 = V_188 -> V_189 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
bool V_270 = F_123 ( V_145 ) ;
if ( V_145 && ! V_188 -> V_265 -> V_145 )
F_14 ( V_20 ) ;
V_18 = F_49 ( V_20 , V_4 ) ;
if ( V_18 ) {
if ( V_145 ) {
F_102 ( V_145 , - V_136 ) ;
}
goto V_39;
}
V_188 -> V_267 = false ;
if ( V_145 && F_124 ( V_145 ) == V_271 ) {
if ( V_20 -> V_79 -> V_215 )
F_119 ( V_188 , NULL ) ;
F_88 ( V_188 , V_145 ) ;
} else if ( V_145 && F_124 ( V_145 ) == V_272 ) {
if ( V_20 -> V_79 -> V_215 )
F_119 ( V_188 , NULL ) ;
F_97 ( V_188 , V_145 ) ;
} else if ( V_145 && F_124 ( V_145 ) == V_273 ) {
if ( V_20 -> V_79 -> V_215 )
F_119 ( V_188 , NULL ) ;
F_100 ( V_188 , V_145 ) ;
} else {
F_119 ( V_188 , V_145 ) ;
V_20 -> V_79 -> V_274 . V_275 = false ;
}
V_39:
if ( ( ! V_145 && ! V_188 -> V_267 ) || V_270 )
F_17 ( V_20 ) ;
}
static inline int F_125 ( struct V_19 * V_20 )
{
return F_126 ( V_20 ) ||
! ( V_20 -> V_276 . V_277 & V_278 ) ;
}
static struct V_1 * F_127 ( struct V_19 * V_20 ,
struct V_13 * V_279 ,
T_9 V_280 ,
bool V_281 ,
const char * V_282 ,
int V_35 )
{
struct V_1 * V_4 ;
int V_8 , V_18 ;
V_8 = F_128 ( & V_12 , 0 , V_283 , V_58 ) ;
if ( V_8 < 0 )
return F_33 ( V_8 ) ;
V_4 = F_129 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_4 ) {
V_18 = - V_59 ;
goto V_39;
}
V_4 -> V_35 = V_35 ;
V_4 -> V_37 = F_125 ( V_20 ) ;
V_4 -> V_3 = F_130 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_18 = - V_59 ;
goto V_284;
}
F_131 ( & V_4 -> V_285 ) ;
F_132 ( & V_4 -> V_286 ) ;
V_4 -> V_7 = 1 ;
V_18 = F_133 ( & V_4 -> V_11 , V_20 , & V_4 -> V_285 , V_282 ) ;
if ( V_18 )
goto V_287;
V_4 -> V_11 . V_189 = V_4 ;
V_4 -> V_3 -> V_288 = V_289 ;
V_4 -> V_3 -> V_9 = V_8 * V_10 ;
V_4 -> V_3 -> V_290 = & V_291 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_11 = V_4 -> V_11 . V_11 ;
V_4 -> V_279 = V_279 ;
F_19 ( V_4 -> V_3 , V_4 -> V_37 || V_281 ) ;
V_4 -> V_3 -> V_96 = V_292 ;
if ( V_35 & ( V_93 | V_36 ) )
V_4 -> V_3 -> V_96 |= V_293 ;
snprintf ( V_4 -> V_3 -> V_34 , sizeof( V_4 -> V_3 -> V_34 ) ,
L_39 , V_20 -> V_79 -> V_294 , V_282 ? V_282 : L_40 ) ;
if ( F_66 ( V_20 ) )
F_134 ( V_4 -> V_11 . V_11 ,
V_20 -> V_22 . V_295 ) ;
else
F_134 ( V_4 -> V_11 . V_11 , 512 ) ;
F_135 ( V_4 -> V_3 , V_280 ) ;
if ( F_136 ( V_20 -> V_79 ) ) {
if ( ( F_66 ( V_20 ) &&
V_20 -> V_276 . V_296 >= V_297 ) ||
( F_114 ( V_20 ) &&
V_20 -> V_298 . V_115 & V_299 ) )
V_4 -> V_96 |= V_249 ;
}
if ( F_66 ( V_20 ) &&
V_4 -> V_96 & V_249 &&
( ( V_20 -> V_22 . V_210 & V_211 ) ||
V_20 -> V_22 . V_212 ) ) {
V_4 -> V_96 |= V_239 ;
F_137 ( V_4 -> V_11 . V_11 , true , true ) ;
}
return V_4 ;
V_287:
F_8 ( V_4 -> V_3 ) ;
V_284:
F_9 ( V_4 ) ;
V_39:
F_7 ( & V_12 , V_8 ) ;
return F_33 ( V_18 ) ;
}
static struct V_1 * F_138 ( struct V_19 * V_20 )
{
T_9 V_280 ;
if ( ! F_114 ( V_20 ) && F_108 ( V_20 ) ) {
V_280 = V_20 -> V_22 . V_52 ;
} else {
V_280 = ( F_139 ( T_9 ) ) V_20 -> V_276 . V_300
<< ( V_20 -> V_276 . V_301 - 9 ) ;
}
return F_127 ( V_20 , & V_20 -> V_14 , V_280 , false , NULL ,
V_302 ) ;
}
static int F_140 ( struct V_19 * V_20 ,
struct V_1 * V_4 ,
unsigned int V_123 ,
T_9 V_280 ,
bool V_281 ,
const char * V_282 ,
int V_35 )
{
char V_303 [ 10 ] ;
struct V_1 * V_28 ;
V_28 = F_127 ( V_20 , F_141 ( V_4 -> V_3 ) , V_280 , V_281 ,
V_282 , V_35 ) ;
if ( F_58 ( V_28 ) )
return F_59 ( V_28 ) ;
V_28 -> V_123 = V_123 ;
F_142 ( & V_28 -> V_286 , & V_4 -> V_286 ) ;
F_143 ( ( V_64 ) F_29 ( V_28 -> V_3 ) , 512 , V_304 ,
V_303 , sizeof( V_303 ) ) ;
F_18 ( L_41 ,
V_28 -> V_3 -> V_34 , F_144 ( V_20 ) ,
F_145 ( V_20 ) , V_28 -> V_123 , V_303 ) ;
return 0 ;
}
static int F_146 ( struct V_19 * V_20 , struct V_1 * V_4 )
{
int V_305 , V_18 = 0 ;
if ( ! F_66 ( V_20 ) )
return 0 ;
for ( V_305 = 0 ; V_305 < V_20 -> V_306 ; V_305 ++ ) {
if ( V_20 -> V_286 [ V_305 ] . V_280 ) {
V_18 = F_140 ( V_20 , V_4 ,
V_20 -> V_286 [ V_305 ] . V_307 ,
V_20 -> V_286 [ V_305 ] . V_280 >> 9 ,
V_20 -> V_286 [ V_305 ] . V_308 ,
V_20 -> V_286 [ V_305 ] . V_164 ,
V_20 -> V_286 [ V_305 ] . V_35 ) ;
if ( V_18 )
return V_18 ;
}
}
return V_18 ;
}
static void F_147 ( struct V_1 * V_4 )
{
struct V_19 * V_20 ;
if ( V_4 ) {
V_20 = V_4 -> V_11 . V_20 ;
F_148 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_3 -> V_96 & V_309 ) {
F_149 ( F_141 ( V_4 -> V_3 ) , & V_4 -> V_308 ) ;
if ( ( V_4 -> V_35 & V_36 ) &&
V_20 -> V_22 . V_310 )
F_149 ( F_141 ( V_4 -> V_3 ) ,
& V_4 -> V_311 ) ;
F_150 ( V_4 -> V_3 ) ;
}
F_5 ( V_4 ) ;
}
}
static void F_151 ( struct V_19 * V_20 ,
struct V_1 * V_4 )
{
struct V_312 * V_313 , * V_314 ;
struct V_1 * V_28 ;
F_152 (pos, q, &md->part) {
V_28 = F_153 ( V_313 , struct V_1 , V_286 ) ;
F_154 ( V_313 ) ;
F_147 ( V_28 ) ;
}
}
static int F_155 ( struct V_1 * V_4 )
{
int V_18 ;
struct V_19 * V_20 = V_4 -> V_11 . V_20 ;
F_156 ( V_4 -> V_279 , V_4 -> V_3 ) ;
V_4 -> V_308 . V_315 = F_21 ;
V_4 -> V_308 . V_316 = F_23 ;
F_157 ( & V_4 -> V_308 . V_16 ) ;
V_4 -> V_308 . V_16 . V_164 = L_42 ;
V_4 -> V_308 . V_16 . V_42 = V_317 | V_318 ;
V_18 = F_158 ( F_141 ( V_4 -> V_3 ) , & V_4 -> V_308 ) ;
if ( V_18 )
goto V_319;
if ( ( V_4 -> V_35 & V_36 ) &&
V_20 -> V_22 . V_310 ) {
T_10 V_42 ;
if ( V_20 -> V_22 . V_23 & V_320 )
V_42 = V_317 ;
else
V_42 = V_317 | V_318 ;
V_4 -> V_311 . V_315 = F_10 ;
V_4 -> V_311 . V_316 = F_12 ;
F_157 ( & V_4 -> V_311 . V_16 ) ;
V_4 -> V_311 . V_16 . V_42 = V_42 ;
V_4 -> V_311 . V_16 . V_164 =
L_43 ;
V_18 = F_158 ( F_141 ( V_4 -> V_3 ) ,
& V_4 -> V_311 ) ;
if ( V_18 )
goto V_321;
}
return V_18 ;
V_321:
F_149 ( F_141 ( V_4 -> V_3 ) , & V_4 -> V_308 ) ;
V_319:
F_150 ( V_4 -> V_3 ) ;
return V_18 ;
}
static int F_159 ( struct V_19 * V_20 )
{
struct V_1 * V_4 , * V_28 ;
char V_303 [ 10 ] ;
if ( ! ( V_20 -> V_276 . V_277 & V_322 ) )
return - V_186 ;
F_160 ( V_20 , V_323 ) ;
V_4 = F_138 ( V_20 ) ;
if ( F_58 ( V_4 ) )
return F_59 ( V_4 ) ;
F_143 ( ( V_64 ) F_29 ( V_4 -> V_3 ) , 512 , V_304 ,
V_303 , sizeof( V_303 ) ) ;
F_18 ( L_44 ,
V_4 -> V_3 -> V_34 , F_144 ( V_20 ) , F_145 ( V_20 ) ,
V_303 , V_4 -> V_37 ? L_45 : L_40 ) ;
if ( F_146 ( V_20 , V_4 ) )
goto V_39;
F_161 ( & V_20 -> V_14 , V_4 ) ;
if ( F_155 ( V_4 ) )
goto V_39;
F_20 (part_md, &md->part, part) {
if ( F_155 ( V_28 ) )
goto V_39;
}
F_162 ( & V_20 -> V_14 , 3000 ) ;
F_163 ( & V_20 -> V_14 ) ;
if ( V_20 -> type != V_324 ) {
F_164 ( & V_20 -> V_14 ) ;
F_165 ( & V_20 -> V_14 ) ;
}
return 0 ;
V_39:
F_151 ( V_20 , V_4 ) ;
F_147 ( V_4 ) ;
return 0 ;
}
static void F_166 ( struct V_19 * V_20 )
{
struct V_1 * V_4 = F_60 ( & V_20 -> V_14 ) ;
F_151 ( V_20 , V_4 ) ;
F_167 ( & V_20 -> V_14 ) ;
F_168 ( V_20 -> V_79 ) ;
F_49 ( V_20 , V_4 ) ;
F_169 ( V_20 -> V_79 ) ;
if ( V_20 -> type != V_324 )
F_170 ( & V_20 -> V_14 ) ;
F_171 ( & V_20 -> V_14 ) ;
F_147 ( V_4 ) ;
F_161 ( & V_20 -> V_14 , NULL ) ;
}
static int F_172 ( struct V_19 * V_20 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_60 ( & V_20 -> V_14 ) ;
if ( V_4 ) {
F_173 ( & V_4 -> V_11 ) ;
F_20 (part_md, &md->part, part) {
F_173 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static void F_174 ( struct V_19 * V_20 )
{
F_172 ( V_20 ) ;
}
static int F_175 ( struct V_13 * V_14 )
{
struct V_19 * V_20 = F_176 ( V_14 ) ;
return F_172 ( V_20 ) ;
}
static int F_177 ( struct V_13 * V_14 )
{
struct V_1 * V_28 ;
struct V_1 * V_4 = F_60 ( V_14 ) ;
if ( V_4 ) {
V_4 -> V_122 = V_4 -> V_123 ;
F_178 ( & V_4 -> V_11 ) ;
F_20 (part_md, &md->part, part) {
F_178 ( & V_28 -> V_11 ) ;
}
}
return 0 ;
}
static int T_11 F_179 ( void )
{
int V_325 ;
if ( V_10 != V_326 )
F_18 ( L_46 , V_10 ) ;
V_283 = F_180 ( V_327 , ( 1 << V_328 ) / V_10 ) ;
V_325 = F_181 ( V_289 , L_47 ) ;
if ( V_325 )
goto V_39;
V_325 = F_182 ( & V_329 ) ;
if ( V_325 )
goto V_330;
return 0 ;
V_330:
F_183 ( V_289 , L_47 ) ;
V_39:
return V_325 ;
}
static void T_12 F_184 ( void )
{
F_185 ( & V_329 ) ;
F_183 ( V_289 , L_47 ) ;
}
