static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 ) ;
F_3 ( V_2 , V_4 ) ;
F_4 ( V_2 -> V_5 ) ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
F_6 ( & V_10 ) ;
V_9 = V_8 -> V_11 ;
if ( V_9 && V_9 -> V_12 == 0 )
V_9 = NULL ;
if ( V_9 )
V_9 -> V_12 ++ ;
F_7 ( & V_10 ) ;
return V_9 ;
}
static inline int F_8 ( struct V_7 * V_8 )
{
int V_13 = V_8 -> V_14 / V_15 ;
return V_13 ;
}
static void F_9 ( struct V_6 * V_9 )
{
F_6 ( & V_10 ) ;
V_9 -> V_12 -- ;
if ( V_9 -> V_12 == 0 ) {
int V_13 = F_8 ( V_9 -> V_8 ) ;
F_10 ( V_9 -> V_16 . V_16 ) ;
F_11 ( & V_17 , V_13 ) ;
F_12 ( V_9 -> V_8 ) ;
F_13 ( V_9 ) ;
}
F_7 ( & V_10 ) ;
}
static T_1 F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
int V_23 ;
struct V_6 * V_9 = F_5 ( F_15 ( V_19 ) ) ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
int V_26 = 0 ;
if ( V_25 -> V_27 . V_28 & V_29 )
V_26 = 2 ;
else if ( V_25 -> V_27 . V_28 & V_30 )
V_26 = 1 ;
V_23 = snprintf ( V_22 , V_31 , L_1 , V_26 ) ;
F_9 ( V_9 ) ;
return V_23 ;
}
static T_1 F_16 ( struct V_18 * V_19 ,
struct V_20 * V_21 , const char * V_22 , T_2 V_32 )
{
int V_23 ;
struct V_6 * V_9 , * V_33 ;
struct V_24 * V_25 ;
unsigned long V_34 ;
if ( F_17 ( V_22 , 0 , & V_34 ) )
return - V_35 ;
if ( V_34 != 1 )
return V_32 ;
V_9 = F_5 ( F_15 ( V_19 ) ) ;
V_25 = V_9 -> V_16 . V_25 ;
F_18 ( V_25 ) ;
V_23 = F_19 ( V_25 , V_36 , V_37 ,
V_25 -> V_27 . V_28 |
V_30 ,
V_25 -> V_27 . V_38 ) ;
if ( V_23 )
F_20 ( L_2 , V_9 -> V_8 -> V_39 , V_23 ) ;
else
V_25 -> V_27 . V_28 |= V_30 ;
F_21 ( V_25 ) ;
if ( ! V_23 ) {
F_22 ( L_3 ,
V_9 -> V_8 -> V_39 ) ;
F_23 ( V_9 -> V_8 , 1 ) ;
F_24 (part_md, &md->part, part)
if ( V_33 -> V_40 == V_41 ) {
F_22 ( L_3 , V_33 -> V_8 -> V_39 ) ;
F_23 ( V_33 -> V_8 , 1 ) ;
}
}
F_9 ( V_9 ) ;
return V_32 ;
}
static T_1 F_25 ( struct V_18 * V_19 , struct V_20 * V_21 ,
char * V_22 )
{
int V_23 ;
struct V_6 * V_9 = F_5 ( F_15 ( V_19 ) ) ;
V_23 = snprintf ( V_22 , V_31 , L_1 ,
F_26 ( F_15 ( V_19 ) ) ^
V_9 -> V_42 ) ;
F_9 ( V_9 ) ;
return V_23 ;
}
static T_1 F_27 ( struct V_18 * V_19 , struct V_20 * V_21 ,
const char * V_22 , T_2 V_32 )
{
int V_23 ;
char * V_43 ;
struct V_6 * V_9 = F_5 ( F_15 ( V_19 ) ) ;
unsigned long V_34 = F_28 ( V_22 , & V_43 , 0 ) ;
if ( V_43 == V_22 ) {
V_23 = - V_35 ;
goto V_44;
}
F_23 ( F_15 ( V_19 ) , V_34 || V_9 -> V_42 ) ;
V_23 = V_32 ;
V_44:
F_9 ( V_9 ) ;
return V_23 ;
}
static int F_29 ( struct V_45 * V_46 , T_3 V_47 )
{
struct V_6 * V_9 = F_5 ( V_46 -> V_48 ) ;
int V_23 = - V_49 ;
F_6 ( & V_50 ) ;
if ( V_9 ) {
if ( V_9 -> V_12 == 2 )
F_30 ( V_46 ) ;
V_23 = 0 ;
if ( ( V_47 & V_51 ) && V_9 -> V_42 ) {
F_9 ( V_9 ) ;
V_23 = - V_52 ;
}
}
F_7 ( & V_50 ) ;
return V_23 ;
}
static void F_31 ( struct V_7 * V_8 , T_3 V_47 )
{
struct V_6 * V_9 = V_8 -> V_11 ;
F_6 ( & V_50 ) ;
F_9 ( V_9 ) ;
F_7 ( & V_50 ) ;
}
static int
F_32 ( struct V_45 * V_46 , struct V_53 * V_54 )
{
V_54 -> V_55 = F_33 ( V_46 -> V_48 ) / ( 4 * 16 ) ;
V_54 -> V_56 = 4 ;
V_54 -> V_57 = 16 ;
return 0 ;
}
static struct V_58 * F_34 (
struct V_59 T_4 * V_60 )
{
struct V_58 * V_61 ;
int V_62 ;
V_61 = F_35 ( sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 ) {
V_62 = - V_64 ;
goto V_44;
}
if ( F_36 ( & V_61 -> V_65 , V_60 , sizeof( V_61 -> V_65 ) ) ) {
V_62 = - V_66 ;
goto V_67;
}
V_61 -> V_68 = ( V_69 ) V_61 -> V_65 . V_70 * V_61 -> V_65 . V_71 ;
if ( V_61 -> V_68 > V_72 ) {
V_62 = - V_73 ;
goto V_67;
}
if ( ! V_61 -> V_68 ) {
V_61 -> V_22 = NULL ;
return V_61 ;
}
V_61 -> V_22 = F_35 ( V_61 -> V_68 , V_63 ) ;
if ( ! V_61 -> V_22 ) {
V_62 = - V_64 ;
goto V_67;
}
if ( F_36 ( V_61 -> V_22 , ( void T_4 * ) ( unsigned long )
V_61 -> V_65 . V_74 , V_61 -> V_68 ) ) {
V_62 = - V_66 ;
goto V_75;
}
return V_61 ;
V_75:
F_13 ( V_61 -> V_22 ) ;
V_67:
F_13 ( V_61 ) ;
V_44:
return F_37 ( V_62 ) ;
}
static int F_38 ( struct V_59 T_4 * V_76 ,
struct V_58 * V_61 )
{
struct V_59 * V_65 = & V_61 -> V_65 ;
if ( F_39 ( & ( V_76 -> V_77 ) , V_65 -> V_77 ,
sizeof( V_65 -> V_77 ) ) )
return - V_66 ;
if ( ! V_61 -> V_65 . V_78 ) {
if ( F_39 ( ( void T_4 * ) ( unsigned long ) V_65 -> V_74 ,
V_61 -> V_22 , V_61 -> V_68 ) )
return - V_66 ;
}
return 0 ;
}
static int F_40 ( struct V_24 * V_25 , T_5 * V_79 ,
T_5 V_80 )
{
int V_62 ;
T_5 V_81 = 0 ;
if ( ! V_79 || ! V_80 )
return - V_35 ;
do {
V_62 = F_41 ( V_25 , V_79 , 5 ) ;
if ( V_62 )
break;
if ( ! F_42 ( * V_79 ) &&
( F_43 ( * V_79 ) != V_82 ) )
break;
F_44 ( 1000 , 5000 ) ;
} while ( ++ V_81 < V_80 );
if ( V_81 == V_80 )
V_62 = - V_83 ;
return V_62 ;
}
static int F_45 ( struct V_24 * V_25 )
{
int V_62 ;
if ( ! F_46 ( V_25 ) ) {
F_47 ( L_4 ,
F_48 ( V_25 -> V_84 ) , V_85 ) ;
V_62 = - V_86 ;
goto V_44;
}
F_49 ( L_5 ,
F_48 ( V_25 -> V_84 ) , V_85 ) ;
V_62 = F_19 ( V_25 , V_36 ,
V_87 , 1 ,
V_88 ) ;
if ( V_62 )
F_20 ( L_6 ,
F_48 ( V_25 -> V_84 ) , V_85 , V_62 ) ;
F_49 ( L_7 , F_48 ( V_25 -> V_84 ) ,
V_85 ) ;
V_44:
return V_62 ;
}
static int F_50 ( struct V_24 * V_25 , struct V_6 * V_9 ,
struct V_58 * V_61 )
{
struct V_89 V_90 = {} ;
struct V_91 V_92 = {} ;
struct V_93 V_94 = {} ;
struct V_95 V_96 ;
int V_62 ;
int V_97 = false ;
T_5 V_79 = 0 ;
if ( ! V_25 || ! V_9 || ! V_61 )
return - V_35 ;
if ( V_9 -> V_40 & V_98 )
V_97 = true ;
V_90 . V_99 = V_61 -> V_65 . V_99 ;
V_90 . V_100 = V_61 -> V_65 . V_100 ;
V_90 . V_101 = V_61 -> V_65 . V_101 ;
if ( V_61 -> V_68 ) {
V_92 . V_96 = & V_96 ;
V_92 . V_102 = 1 ;
V_92 . V_70 = V_61 -> V_65 . V_70 ;
V_92 . V_71 = V_61 -> V_65 . V_71 ;
F_51 ( V_92 . V_96 , V_61 -> V_22 , V_61 -> V_68 ) ;
if ( V_61 -> V_65 . V_78 )
V_92 . V_101 = V_103 ;
else
V_92 . V_101 = V_104 ;
F_52 ( & V_92 , V_25 ) ;
if ( V_61 -> V_65 . V_105 )
V_92 . V_106 = V_61 -> V_65 . V_105 ;
if ( ( V_90 . V_101 & V_107 ) == V_107 ) {
V_92 . V_106 = V_61 -> V_65 . V_108 * 1000000 ;
}
V_94 . V_92 = & V_92 ;
}
V_94 . V_90 = & V_90 ;
V_62 = F_53 ( V_25 , V_9 ) ;
if ( V_62 )
return V_62 ;
if ( V_61 -> V_65 . V_109 ) {
V_62 = F_54 ( V_25 -> V_84 , V_25 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_97 ) {
V_62 = F_55 ( V_25 , V_92 . V_71 ,
V_61 -> V_65 . V_78 & ( 1 << 31 ) ) ;
if ( V_62 )
return V_62 ;
}
if ( ( F_56 ( V_90 . V_100 ) == V_87 ) &&
( V_90 . V_99 == V_110 ) ) {
V_62 = F_45 ( V_25 ) ;
if ( V_62 )
F_20 ( L_8 ,
V_85 , V_62 ) ;
return V_62 ;
}
F_57 ( V_25 -> V_84 , & V_94 ) ;
if ( V_90 . error ) {
F_58 ( F_59 ( V_25 -> V_84 ) , L_9 ,
V_85 , V_90 . error ) ;
return V_90 . error ;
}
if ( V_92 . error ) {
F_58 ( F_59 ( V_25 -> V_84 ) , L_10 ,
V_85 , V_92 . error ) ;
return V_92 . error ;
}
if ( V_61 -> V_65 . V_111 )
F_44 ( V_61 -> V_65 . V_111 , V_61 -> V_65 . V_112 ) ;
memcpy ( & ( V_61 -> V_65 . V_77 ) , V_90 . V_113 , sizeof( V_90 . V_113 ) ) ;
if ( V_97 ) {
V_62 = F_40 ( V_25 , & V_79 , 5 ) ;
if ( V_62 )
F_58 ( F_59 ( V_25 -> V_84 ) ,
L_11 ,
V_85 , V_79 , V_62 ) ;
}
return V_62 ;
}
static int F_60 ( struct V_45 * V_46 ,
struct V_59 T_4 * V_76 )
{
struct V_58 * V_61 ;
struct V_6 * V_9 ;
struct V_24 * V_25 ;
int V_62 = 0 , V_114 = 0 ;
if ( ( ! F_61 ( V_115 ) ) || ( V_46 != V_46 -> V_116 ) )
return - V_83 ;
V_61 = F_34 ( V_76 ) ;
if ( F_62 ( V_61 ) )
return F_63 ( V_61 ) ;
V_9 = F_5 ( V_46 -> V_48 ) ;
if ( ! V_9 ) {
V_62 = - V_35 ;
goto V_117;
}
V_25 = V_9 -> V_16 . V_25 ;
if ( F_62 ( V_25 ) ) {
V_62 = F_63 ( V_25 ) ;
goto V_118;
}
F_18 ( V_25 ) ;
V_114 = F_50 ( V_25 , V_9 , V_61 ) ;
if ( V_9 -> V_40 & V_98 )
F_53 ( V_25 , F_64 ( & V_25 -> V_19 ) ) ;
F_21 ( V_25 ) ;
V_62 = F_38 ( V_76 , V_61 ) ;
V_118:
F_9 ( V_9 ) ;
V_117:
F_13 ( V_61 -> V_22 ) ;
F_13 ( V_61 ) ;
return V_114 ? V_114 : V_62 ;
}
static int F_65 ( struct V_45 * V_46 ,
struct V_119 T_4 * V_60 )
{
struct V_58 * * V_61 = NULL ;
struct V_59 T_4 * V_120 = V_60 -> V_120 ;
struct V_24 * V_25 ;
struct V_6 * V_9 ;
int V_121 , V_62 = 0 , V_114 = 0 ;
T_6 V_122 ;
if ( ( ! F_61 ( V_115 ) ) || ( V_46 != V_46 -> V_116 ) )
return - V_83 ;
if ( F_36 ( & V_122 , & V_60 -> V_122 ,
sizeof( V_122 ) ) )
return - V_66 ;
if ( V_122 > V_123 )
return - V_35 ;
V_61 = F_66 ( V_122 , sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 )
return - V_64 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
V_61 [ V_121 ] = F_34 ( & V_120 [ V_121 ] ) ;
if ( F_62 ( V_61 [ V_121 ] ) ) {
V_62 = F_63 ( V_61 [ V_121 ] ) ;
V_122 = V_121 ;
goto V_117;
}
}
V_9 = F_5 ( V_46 -> V_48 ) ;
if ( ! V_9 ) {
V_62 = - V_35 ;
goto V_117;
}
V_25 = V_9 -> V_16 . V_25 ;
if ( F_62 ( V_25 ) ) {
V_62 = F_63 ( V_25 ) ;
goto V_118;
}
F_18 ( V_25 ) ;
for ( V_121 = 0 ; V_121 < V_122 && ! V_114 ; V_121 ++ )
V_114 = F_50 ( V_25 , V_9 , V_61 [ V_121 ] ) ;
if ( V_9 -> V_40 & V_98 )
F_53 ( V_25 , F_64 ( & V_25 -> V_19 ) ) ;
F_21 ( V_25 ) ;
for ( V_121 = 0 ; V_121 < V_122 && ! V_62 ; V_121 ++ )
V_62 = F_38 ( & V_120 [ V_121 ] , V_61 [ V_121 ] ) ;
V_118:
F_9 ( V_9 ) ;
V_117:
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
F_13 ( V_61 [ V_121 ] -> V_22 ) ;
F_13 ( V_61 [ V_121 ] ) ;
}
F_13 ( V_61 ) ;
return V_114 ? V_114 : V_62 ;
}
static int F_67 ( struct V_45 * V_46 , T_3 V_47 ,
unsigned int V_90 , unsigned long V_100 )
{
switch ( V_90 ) {
case V_124 :
return F_60 ( V_46 ,
(struct V_59 T_4 * ) V_100 ) ;
case V_125 :
return F_65 ( V_46 ,
(struct V_119 T_4 * ) V_100 ) ;
default:
return - V_35 ;
}
}
static int F_68 ( struct V_45 * V_46 , T_3 V_47 ,
unsigned int V_90 , unsigned long V_100 )
{
return F_67 ( V_46 , V_47 , V_90 , ( unsigned long ) F_69 ( V_100 ) ) ;
}
static int F_70 ( struct V_24 * V_25 ,
unsigned int V_126 )
{
int V_23 = 0 ;
if ( V_126 == V_127 ) {
if ( V_25 -> V_27 . V_128 ) {
V_23 = F_71 ( V_25 ) ;
if ( V_23 )
return V_23 ;
}
F_72 ( V_25 -> V_84 ) ;
}
return V_23 ;
}
static int F_73 ( struct V_24 * V_25 ,
unsigned int V_126 )
{
int V_23 = 0 ;
if ( V_126 == V_127 ) {
F_74 ( V_25 -> V_84 ) ;
if ( V_25 -> V_129 && ! V_25 -> V_27 . V_128 )
V_23 = F_75 ( V_25 ) ;
}
return V_23 ;
}
static inline int F_53 ( struct V_24 * V_25 ,
struct V_6 * V_9 )
{
int V_23 = 0 ;
struct V_6 * V_130 = F_64 ( & V_25 -> V_19 ) ;
if ( V_130 -> V_131 == V_9 -> V_126 )
return 0 ;
if ( F_76 ( V_25 ) ) {
T_7 V_132 = V_25 -> V_27 . V_132 ;
V_23 = F_70 ( V_25 , V_9 -> V_126 ) ;
if ( V_23 )
return V_23 ;
V_132 &= ~ V_133 ;
V_132 |= V_9 -> V_126 ;
V_23 = F_19 ( V_25 , V_36 ,
V_134 , V_132 ,
V_25 -> V_27 . V_38 ) ;
if ( V_23 ) {
F_73 ( V_25 , V_9 -> V_126 ) ;
return V_23 ;
}
V_25 -> V_27 . V_132 = V_132 ;
V_23 = F_73 ( V_25 , V_130 -> V_131 ) ;
}
V_130 -> V_131 = V_9 -> V_126 ;
return V_23 ;
}
static int F_77 ( struct V_24 * V_25 , T_5 * V_135 )
{
int V_62 ;
T_5 V_136 ;
T_8 * V_71 ;
struct V_93 V_94 = {} ;
struct V_89 V_90 = {} ;
struct V_91 V_92 = {} ;
struct V_95 V_96 ;
V_90 . V_99 = V_137 ;
V_90 . V_100 = V_25 -> V_138 << 16 ;
V_90 . V_101 = V_139 | V_140 | V_141 ;
V_62 = F_78 ( V_25 -> V_84 , & V_90 , 0 ) ;
if ( V_62 )
return V_62 ;
if ( ! F_79 ( V_25 -> V_84 ) && ! ( V_90 . V_113 [ 0 ] & V_142 ) )
return - V_143 ;
memset ( & V_90 , 0 , sizeof( struct V_89 ) ) ;
V_90 . V_99 = V_144 ;
V_90 . V_100 = 0 ;
V_90 . V_101 = V_139 | V_140 | V_145 ;
V_92 . V_70 = 4 ;
V_92 . V_71 = 1 ;
V_92 . V_101 = V_104 ;
V_92 . V_96 = & V_96 ;
V_92 . V_102 = 1 ;
F_52 ( & V_92 , V_25 ) ;
V_94 . V_90 = & V_90 ;
V_94 . V_92 = & V_92 ;
V_71 = F_35 ( 4 , V_63 ) ;
if ( ! V_71 )
return - V_64 ;
F_51 ( & V_96 , V_71 , 4 ) ;
F_57 ( V_25 -> V_84 , & V_94 ) ;
V_136 = F_80 ( * V_71 ) ;
F_13 ( V_71 ) ;
if ( V_90 . error || V_92 . error )
return - V_143 ;
* V_135 = V_136 ;
return 0 ;
}
static int F_41 ( struct V_24 * V_25 , T_5 * V_79 , int V_146 )
{
struct V_89 V_90 = {} ;
int V_62 ;
V_90 . V_99 = V_147 ;
if ( ! F_79 ( V_25 -> V_84 ) )
V_90 . V_100 = V_25 -> V_138 << 16 ;
V_90 . V_101 = V_148 | V_140 | V_141 ;
V_62 = F_78 ( V_25 -> V_84 , & V_90 , V_146 ) ;
if ( V_62 == 0 )
* V_79 = V_90 . V_113 [ 0 ] ;
return V_62 ;
}
static int F_81 ( struct V_24 * V_25 , unsigned int V_149 ,
bool V_150 , struct V_3 * V_4 , bool * V_151 )
{
unsigned long V_152 = V_153 + F_82 ( V_149 ) ;
int V_62 = 0 ;
T_5 V_79 ;
do {
V_62 = F_41 ( V_25 , & V_79 , 5 ) ;
if ( V_62 ) {
F_20 ( L_12 ,
V_4 -> V_154 -> V_39 , V_62 ) ;
return V_62 ;
}
if ( V_79 & V_155 ) {
F_20 ( L_13 ,
V_4 -> V_154 -> V_39 , V_85 , V_79 ) ;
* V_151 = true ;
}
if ( ( V_25 -> V_84 -> V_156 & V_157 ) &&
V_150 )
break;
if ( F_83 ( V_153 , V_152 ) ) {
F_20 ( L_14 ,
F_48 ( V_25 -> V_84 ) ,
V_4 -> V_154 -> V_39 , V_85 ) ;
return - V_158 ;
}
} while ( ! ( V_79 & V_159 ) ||
( F_43 ( V_79 ) == V_82 ) );
return V_62 ;
}
static int F_84 ( struct V_24 * V_25 , unsigned int V_149 ,
struct V_3 * V_4 , bool * V_151 , T_5 * V_160 )
{
struct V_161 * V_84 = V_25 -> V_84 ;
struct V_89 V_90 = {} ;
int V_62 ;
bool V_162 = F_85 ( V_4 ) == V_163 ;
if ( V_84 -> V_164 && ( V_149 > V_84 -> V_164 ) )
V_162 = false ;
V_90 . V_99 = V_165 ;
if ( V_162 ) {
V_90 . V_101 = V_166 | V_107 | V_141 ;
V_90 . V_167 = V_149 ;
} else {
V_90 . V_101 = V_139 | V_140 | V_141 ;
}
V_62 = F_78 ( V_84 , & V_90 , 5 ) ;
if ( V_62 )
return V_62 ;
* V_160 = V_90 . V_113 [ 0 ] ;
if ( F_85 ( V_4 ) == V_168 )
return 0 ;
if ( ! F_79 ( V_84 ) &&
( * V_160 & V_155 ) ) {
F_20 ( L_15 ,
V_4 -> V_154 -> V_39 , V_85 , * V_160 ) ;
* V_151 = true ;
}
return F_81 ( V_25 , V_149 , V_162 , V_4 , V_151 ) ;
}
static int F_86 ( struct V_3 * V_4 , const char * V_169 , int error ,
bool V_170 , T_5 V_79 )
{
switch ( error ) {
case - V_171 :
F_20 ( L_16 ,
V_4 -> V_154 -> V_39 , L_17 ,
V_169 , V_79 ) ;
return V_172 ;
case - V_158 :
F_20 ( L_16 ,
V_4 -> V_154 -> V_39 , L_18 , V_169 , V_79 ) ;
if ( ! V_170 ) {
F_20 ( L_19 ,
V_4 -> V_154 -> V_39 ) ;
return V_172 ;
}
if ( V_79 & ( V_173 | V_174 ) ) {
F_20 ( L_20 ,
V_4 -> V_154 -> V_39 ) ;
return V_172 ;
}
return V_175 ;
default:
F_20 ( L_21 ,
V_4 -> V_154 -> V_39 , error , V_79 ) ;
return V_175 ;
}
}
static int F_87 ( struct V_24 * V_25 , struct V_3 * V_4 ,
struct V_176 * V_177 , bool * V_178 , bool * V_151 )
{
bool V_179 = true ;
T_5 V_79 , V_160 = 0 ;
int V_62 , V_180 ;
if ( F_88 ( V_25 ) )
return V_181 ;
for ( V_180 = 2 ; V_180 >= 0 ; V_180 -- ) {
V_62 = F_41 ( V_25 , & V_79 , 0 ) ;
if ( ! V_62 )
break;
F_89 ( V_25 -> V_84 ) ;
V_179 = false ;
F_20 ( L_22 ,
V_4 -> V_154 -> V_39 , V_62 , V_180 ? L_23 : L_24 ) ;
}
if ( V_62 ) {
if ( F_90 ( V_25 -> V_84 ) )
return V_181 ;
return V_175 ;
}
if ( ( V_79 & V_182 ) ||
( V_177 -> V_183 . V_113 [ 0 ] & V_182 ) ||
( V_177 -> V_90 . V_113 [ 0 ] & V_182 ) )
* V_178 = true ;
if ( ! F_79 ( V_25 -> V_84 ) && F_85 ( V_4 ) != V_168 )
if ( ( V_79 & V_155 ) ||
( V_177 -> V_183 . V_113 [ 0 ] & V_155 ) ) {
F_20 ( L_25 ,
V_4 -> V_154 -> V_39 , V_85 ,
V_177 -> V_183 . V_113 [ 0 ] , V_79 ) ;
* V_151 = true ;
}
if ( F_43 ( V_79 ) == V_184 ||
F_43 ( V_79 ) == V_185 ) {
V_62 = F_84 ( V_25 ,
F_91 ( V_177 -> V_92 . V_106 , 1000000 ) ,
V_4 , V_151 , & V_160 ) ;
if ( V_62 ) {
F_20 ( L_26 ,
V_4 -> V_154 -> V_39 , V_62 ) ;
return V_175 ;
}
if ( V_160 & V_182 )
* V_178 = true ;
}
if ( V_177 -> V_186 . error )
return F_86 ( V_4 , L_27 , V_177 -> V_186 . error ,
V_179 , V_79 ) ;
if ( V_177 -> V_90 . error )
return F_86 ( V_4 , L_28 , V_177 -> V_90 . error ,
V_179 , V_79 ) ;
if ( ! V_177 -> V_183 . error )
return V_187 ;
F_22 ( L_29 ,
V_4 -> V_154 -> V_39 , V_177 -> V_183 . error ,
V_177 -> V_90 . V_113 [ 0 ] , V_79 ) ;
if ( V_160 ) {
V_177 -> V_183 . V_113 [ 0 ] = V_160 ;
V_177 -> V_183 . error = 0 ;
}
return V_187 ;
}
static int F_92 ( struct V_6 * V_9 , struct V_161 * V_84 ,
int type )
{
int V_62 ;
if ( V_9 -> V_188 & type )
return - V_189 ;
V_9 -> V_188 |= type ;
V_62 = F_93 ( V_84 ) ;
if ( V_62 != - V_86 ) {
struct V_6 * V_130 =
F_64 ( & V_84 -> V_25 -> V_19 ) ;
int V_190 ;
V_130 -> V_131 = V_130 -> V_126 ;
V_190 = F_53 ( V_84 -> V_25 , V_9 ) ;
if ( V_190 ) {
return - V_191 ;
}
}
return V_62 ;
}
static inline void F_94 ( struct V_6 * V_9 , int type )
{
V_9 -> V_188 &= ~ type ;
}
int F_95 ( struct V_192 * V_193 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
if ( V_9 && V_9 -> V_126 == V_127 )
return true ;
return false ;
}
static void F_96 ( struct V_192 * V_193 , struct V_3 * V_4 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
unsigned int V_195 , V_196 , V_100 ;
int V_62 = 0 , type = V_197 ;
if ( ! F_97 ( V_25 ) ) {
V_62 = - V_86 ;
goto V_198;
}
V_195 = F_98 ( V_4 ) ;
V_196 = F_99 ( V_4 ) ;
if ( F_100 ( V_25 ) )
V_100 = V_199 ;
else if ( F_101 ( V_25 ) )
V_100 = V_200 ;
else
V_100 = V_201 ;
do {
V_62 = 0 ;
if ( V_25 -> V_202 & V_203 ) {
V_62 = F_19 ( V_25 , V_36 ,
V_204 ,
V_100 == V_200 ?
V_205 :
V_206 ,
0 ) ;
}
if ( ! V_62 )
V_62 = F_102 ( V_25 , V_195 , V_196 , V_100 ) ;
} while ( V_62 == - V_143 && ! F_92 ( V_9 , V_25 -> V_84 , type ) );
if ( ! V_62 )
F_94 ( V_9 , type ) ;
V_198:
F_103 ( V_4 , V_62 , F_104 ( V_4 ) ) ;
}
static void F_105 ( struct V_192 * V_193 ,
struct V_3 * V_4 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
unsigned int V_195 , V_196 , V_100 ;
int V_62 = 0 , type = V_207 ;
if ( ! ( F_106 ( V_25 ) ) ) {
V_62 = - V_86 ;
goto V_44;
}
V_195 = F_98 ( V_4 ) ;
V_196 = F_99 ( V_4 ) ;
if ( F_101 ( V_25 ) && ! F_107 ( V_25 , V_195 , V_196 ) )
V_100 = V_208 ;
else
V_100 = V_209 ;
V_180:
if ( V_25 -> V_202 & V_203 ) {
V_62 = F_19 ( V_25 , V_36 ,
V_204 ,
V_100 == V_208 ?
V_210 :
V_211 ,
0 ) ;
if ( V_62 )
goto V_212;
}
V_62 = F_102 ( V_25 , V_195 , V_196 , V_100 ) ;
if ( V_62 == - V_143 )
goto V_212;
if ( V_62 )
goto V_44;
if ( V_100 == V_208 ) {
if ( V_25 -> V_202 & V_203 ) {
V_62 = F_19 ( V_25 , V_36 ,
V_204 ,
V_213 ,
0 ) ;
if ( V_62 )
goto V_212;
}
V_62 = F_102 ( V_25 , V_195 , V_196 , V_214 ) ;
if ( V_62 == - V_143 )
goto V_212;
if ( V_62 )
goto V_44;
}
V_212:
if ( V_62 && ! F_92 ( V_9 , V_25 -> V_84 , type ) )
goto V_180;
if ( ! V_62 )
F_94 ( V_9 , type ) ;
V_44:
F_103 ( V_4 , V_62 , F_104 ( V_4 ) ) ;
}
static void F_108 ( struct V_192 * V_193 , struct V_3 * V_4 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
int V_23 = 0 ;
V_23 = F_109 ( V_25 ) ;
if ( V_23 )
V_23 = - V_143 ;
F_110 ( V_4 , V_23 ) ;
}
static inline void F_111 ( struct V_176 * V_177 ,
struct V_24 * V_25 ,
struct V_3 * V_4 )
{
if ( ! ( V_25 -> V_27 . V_215 & V_216 ) ) {
if ( ! F_112 ( F_98 ( V_4 ) , V_25 -> V_27 . V_217 ) )
V_177 -> V_92 . V_71 = 1 ;
if ( V_177 -> V_92 . V_71 > V_25 -> V_27 . V_217 )
V_177 -> V_92 . V_71 = V_25 -> V_27 . V_217 ;
else if ( V_177 -> V_92 . V_71 < V_25 -> V_27 . V_217 )
V_177 -> V_92 . V_71 = 1 ;
}
}
static enum V_218 F_113 ( struct V_24 * V_25 ,
struct V_219 * V_220 )
{
struct V_221 * V_222 = F_114 ( V_220 , struct V_221 ,
V_220 ) ;
struct V_176 * V_177 = & V_222 -> V_177 ;
struct V_3 * V_4 = V_222 -> V_4 ;
int V_223 = V_25 -> V_84 -> V_223 ;
bool V_178 = false ;
bool V_151 = false ;
if ( V_177 -> V_186 . error || V_177 -> V_90 . error || V_177 -> V_183 . error ||
V_177 -> V_92 . error ) {
switch ( F_87 ( V_25 , V_4 , V_177 , & V_178 , & V_151 ) ) {
case V_172 :
return V_224 ;
case V_175 :
return V_225 ;
case V_181 :
return V_226 ;
case V_187 :
break;
}
}
if ( V_177 -> V_90 . V_113 [ 0 ] & V_227 ) {
F_20 ( L_30 ,
V_4 -> V_154 -> V_39 , V_177 -> V_90 . V_113 [ 0 ] ) ;
return V_225 ;
}
if ( ! F_79 ( V_25 -> V_84 ) && F_85 ( V_4 ) != V_168 ) {
int V_62 ;
if ( V_177 -> V_183 . V_113 [ 0 ] & V_155 ) {
F_20 ( L_31 ,
V_4 -> V_154 -> V_39 , V_85 ,
V_177 -> V_183 . V_113 [ 0 ] ) ;
V_151 = true ;
}
V_62 = F_81 ( V_25 , V_228 , false , V_4 ,
& V_151 ) ;
if ( V_62 )
return V_229 ;
}
if ( V_151 ) {
F_47 ( L_32 ,
V_4 -> V_154 -> V_39 ) ;
return V_224 ;
}
if ( V_177 -> V_92 . error ) {
if ( V_223 && ! V_177 -> V_230 ) {
F_49 ( L_33 ,
V_4 -> V_154 -> V_39 ) ;
V_177 -> V_230 = 1 ;
return V_224 ;
}
F_20 ( L_34 ,
V_4 -> V_154 -> V_39 , V_177 -> V_92 . error ,
( unsigned ) F_98 ( V_4 ) ,
( unsigned ) F_99 ( V_4 ) ,
V_177 -> V_90 . V_113 [ 0 ] , V_177 -> V_183 . V_113 [ 0 ] ) ;
if ( F_85 ( V_4 ) == V_168 ) {
if ( V_178 )
return V_231 ;
return V_232 ;
} else {
return V_229 ;
}
}
if ( ! V_177 -> V_92 . V_233 )
return V_224 ;
if ( F_104 ( V_4 ) != V_177 -> V_92 . V_233 )
return V_234 ;
return V_235 ;
}
static void F_115 ( struct V_192 * V_193 , struct V_221 * V_236 ,
int V_237 , bool * V_238 ,
bool * V_239 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
struct V_176 * V_177 = & V_236 -> V_177 ;
struct V_3 * V_4 = V_236 -> V_4 ;
* V_238 = ( V_4 -> V_240 & V_241 ) &&
F_85 ( V_4 ) == V_163 &&
( V_9 -> V_101 & V_242 ) ;
memset ( V_177 , 0 , sizeof( struct V_176 ) ) ;
V_177 -> V_94 . V_92 = & V_177 -> V_92 ;
V_177 -> V_183 . V_99 = V_165 ;
V_177 -> V_183 . V_100 = 0 ;
if ( F_85 ( V_4 ) == V_168 ) {
V_177 -> V_92 . V_101 = V_104 ;
V_177 -> V_183 . V_101 = V_139 | V_140 | V_141 ;
} else {
V_177 -> V_92 . V_101 = V_103 ;
V_177 -> V_183 . V_101 = V_166 | V_107 | V_141 ;
}
V_177 -> V_92 . V_70 = 512 ;
V_177 -> V_92 . V_71 = F_99 ( V_4 ) ;
if ( V_177 -> V_92 . V_71 > V_25 -> V_84 -> V_243 )
V_177 -> V_92 . V_71 = V_25 -> V_84 -> V_243 ;
if ( V_177 -> V_92 . V_71 > 1 ) {
if ( V_237 )
V_177 -> V_92 . V_71 = 1 ;
if ( V_25 -> V_84 -> V_244 -> V_245 )
V_177 -> V_92 . V_71 = V_25 -> V_84 -> V_244 -> V_245 ( V_25 ,
( F_85 ( V_4 ) == V_168 ) ?
V_104 : V_103 ,
V_177 -> V_92 . V_71 ) ;
}
if ( * V_238 )
F_111 ( V_177 , V_25 , V_4 ) ;
* V_239 = V_25 -> V_27 . V_246 &&
( V_4 -> V_240 & V_247 ) &&
( F_85 ( V_4 ) == V_163 ) &&
( ( V_177 -> V_92 . V_71 * V_177 -> V_92 . V_70 ) >=
V_25 -> V_27 . V_246 ) ;
F_52 ( & V_177 -> V_92 , V_25 ) ;
V_177 -> V_92 . V_96 = V_236 -> V_96 ;
V_177 -> V_92 . V_102 = F_116 ( V_193 , V_236 ) ;
if ( V_177 -> V_92 . V_71 != F_99 ( V_4 ) ) {
int V_121 , V_248 = V_177 -> V_92 . V_71 << 9 ;
struct V_95 * V_96 ;
F_117 (brq->data.sg, sg, brq->data.sg_len, i) {
V_248 -= V_96 -> V_249 ;
if ( V_248 <= 0 ) {
V_96 -> V_249 += V_248 ;
V_121 ++ ;
break;
}
}
V_177 -> V_92 . V_102 = V_121 ;
}
V_236 -> V_220 . V_94 = & V_177 -> V_94 ;
F_118 ( V_236 ) ;
}
static void F_119 ( struct V_221 * V_236 ,
struct V_24 * V_25 ,
int V_237 ,
struct V_192 * V_193 )
{
T_5 V_250 , V_251 ;
struct V_176 * V_177 = & V_236 -> V_177 ;
struct V_3 * V_4 = V_236 -> V_4 ;
struct V_6 * V_9 = V_193 -> V_194 ;
bool V_238 , V_239 ;
F_115 ( V_193 , V_236 , V_237 , & V_238 , & V_239 ) ;
V_177 -> V_94 . V_90 = & V_177 -> V_90 ;
V_177 -> V_90 . V_100 = F_98 ( V_4 ) ;
if ( ! F_120 ( V_25 ) )
V_177 -> V_90 . V_100 <<= 9 ;
V_177 -> V_90 . V_101 = V_139 | V_140 | V_145 ;
if ( V_177 -> V_92 . V_71 > 1 || V_238 ) {
if ( ! F_79 ( V_25 -> V_84 ) ||
F_85 ( V_4 ) == V_168 )
V_177 -> V_94 . V_183 = & V_177 -> V_183 ;
V_250 = V_252 ;
V_251 = V_253 ;
} else {
V_177 -> V_94 . V_183 = NULL ;
V_250 = V_254 ;
V_251 = V_255 ;
}
V_177 -> V_90 . V_99 = F_85 ( V_4 ) == V_168 ? V_250 : V_251 ;
if ( ( V_9 -> V_101 & V_256 ) && F_121 ( V_177 -> V_90 . V_99 ) &&
( V_238 || ! ( V_25 -> V_202 & V_257 ) ||
V_239 ) ) {
V_177 -> V_186 . V_99 = V_258 ;
V_177 -> V_186 . V_100 = V_177 -> V_92 . V_71 |
( V_238 ? ( 1 << 31 ) : 0 ) |
( V_239 ? ( 1 << 29 ) : 0 ) ;
V_177 -> V_186 . V_101 = V_140 | V_141 ;
V_177 -> V_94 . V_186 = & V_177 -> V_186 ;
}
V_236 -> V_220 . V_259 = F_113 ;
}
static bool F_122 ( struct V_6 * V_9 , struct V_24 * V_25 ,
struct V_176 * V_177 , struct V_3 * V_4 ,
bool V_260 )
{
bool V_261 ;
if ( F_123 ( V_25 ) ) {
T_5 V_71 ;
int V_62 ;
V_62 = F_77 ( V_25 , & V_71 ) ;
if ( V_62 )
V_261 = V_260 ;
else
V_261 = F_103 ( V_4 , 0 , V_71 << 9 ) ;
} else {
V_261 = F_103 ( V_4 , 0 , V_177 -> V_92 . V_233 ) ;
}
return V_261 ;
}
static void F_124 ( struct V_192 * V_193 , struct V_24 * V_25 ,
struct V_3 * V_4 ,
struct V_221 * V_236 )
{
if ( F_88 ( V_25 ) )
V_4 -> V_262 |= V_263 ;
while ( F_103 ( V_4 , - V_143 , F_125 ( V_4 ) ) ) ;
F_126 ( V_193 , V_236 ) ;
}
static void F_127 ( struct V_192 * V_193 , struct V_3 * V_4 ,
struct V_221 * V_236 )
{
if ( ! V_4 )
return;
if ( F_88 ( V_193 -> V_25 ) ) {
V_4 -> V_262 |= V_263 ;
F_110 ( V_4 , - V_143 ) ;
F_126 ( V_193 , V_236 ) ;
return;
}
F_119 ( V_236 , V_193 -> V_25 , 0 , V_193 ) ;
F_128 ( V_193 -> V_25 -> V_84 , & V_236 -> V_220 , NULL ) ;
}
static void F_129 ( struct V_192 * V_193 , struct V_3 * V_264 )
{
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
struct V_176 * V_177 ;
int V_237 = 0 , V_180 = 0 , type , V_230 = 0 ;
enum V_218 V_79 ;
struct V_221 * V_265 = NULL ;
struct V_221 * V_266 ;
struct V_3 * V_267 ;
struct V_219 * V_268 ;
struct V_219 * V_269 ;
bool V_261 = true ;
if ( V_264 ) {
V_265 = F_130 ( V_193 , V_264 ) ;
if ( ! V_265 ) {
F_131 ( 1 ) ;
F_1 ( V_193 -> V_16 , V_264 ) ;
V_264 = NULL ;
}
}
if ( ! V_193 -> V_270 )
return;
do {
if ( V_264 ) {
if ( F_132 ( V_25 ) &&
! F_112 ( F_99 ( V_264 ) , 8 ) ) {
F_20 ( L_35 ,
V_264 -> V_154 -> V_39 ) ;
F_124 ( V_193 , V_25 , V_264 , V_265 ) ;
return;
}
F_119 ( V_265 , V_25 , 0 , V_193 ) ;
V_268 = & V_265 -> V_220 ;
} else
V_268 = NULL ;
V_269 = F_128 ( V_25 -> V_84 , V_268 , & V_79 ) ;
if ( ! V_269 ) {
return;
}
V_266 = F_114 ( V_269 , struct V_221 , V_220 ) ;
V_177 = & V_266 -> V_177 ;
V_267 = V_266 -> V_4 ;
type = F_85 ( V_267 ) == V_168 ? V_271 : V_272 ;
F_133 ( V_266 ) ;
switch ( V_79 ) {
case V_235 :
case V_234 :
F_94 ( V_9 , type ) ;
V_261 = F_103 ( V_267 , 0 ,
V_177 -> V_92 . V_233 ) ;
if ( V_79 == V_235 && V_261 ) {
F_20 ( L_36 ,
V_85 , F_104 ( V_267 ) ,
V_177 -> V_92 . V_233 ) ;
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
return;
}
break;
case V_229 :
V_261 = F_122 ( V_9 , V_25 , V_177 , V_267 , V_261 ) ;
if ( F_92 ( V_9 , V_25 -> V_84 , type ) ) {
if ( V_261 )
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
else
F_126 ( V_193 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
}
if ( ! V_261 ) {
F_126 ( V_193 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
}
break;
case V_224 :
V_230 = V_177 -> V_230 ;
if ( V_180 ++ < 5 )
break;
case V_225 :
if ( ! F_92 ( V_9 , V_25 -> V_84 , type ) )
break;
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
case V_232 : {
int V_62 ;
V_62 = F_92 ( V_9 , V_25 -> V_84 , type ) ;
if ( ! V_62 )
break;
if ( V_62 == - V_191 ) {
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
}
}
case V_231 :
if ( V_177 -> V_92 . V_71 > 1 ) {
F_47 ( L_37 ,
V_267 -> V_154 -> V_39 ) ;
V_237 = 1 ;
break;
}
V_261 = F_103 ( V_267 , - V_143 ,
V_177 -> V_92 . V_70 ) ;
if ( ! V_261 ) {
F_126 ( V_193 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
}
break;
case V_226 :
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
default:
F_20 ( L_38 ,
V_267 -> V_154 -> V_39 , V_79 ) ;
F_124 ( V_193 , V_25 , V_267 , V_266 ) ;
F_127 ( V_193 , V_264 , V_265 ) ;
return;
}
if ( V_261 ) {
F_119 ( V_266 , V_25 ,
V_237 , V_193 ) ;
F_128 ( V_25 -> V_84 ,
& V_266 -> V_220 , NULL ) ;
V_266 -> V_177 . V_230 = V_230 ;
}
} while ( V_261 );
F_126 ( V_193 , V_266 ) ;
}
void F_134 ( struct V_192 * V_193 , struct V_3 * V_4 )
{
int V_23 ;
struct V_6 * V_9 = V_193 -> V_194 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
if ( V_4 && ! V_193 -> V_270 )
F_18 ( V_25 ) ;
V_23 = F_53 ( V_25 , V_9 ) ;
if ( V_23 ) {
if ( V_4 ) {
F_110 ( V_4 , - V_143 ) ;
}
goto V_44;
}
if ( V_4 && F_135 ( V_4 ) == V_273 ) {
if ( V_193 -> V_270 )
F_129 ( V_193 , NULL ) ;
F_96 ( V_193 , V_4 ) ;
} else if ( V_4 && F_135 ( V_4 ) == V_274 ) {
if ( V_193 -> V_270 )
F_129 ( V_193 , NULL ) ;
F_105 ( V_193 , V_4 ) ;
} else if ( V_4 && F_135 ( V_4 ) == V_275 ) {
if ( V_193 -> V_270 )
F_129 ( V_193 , NULL ) ;
F_108 ( V_193 , V_4 ) ;
} else {
F_129 ( V_193 , V_4 ) ;
V_25 -> V_84 -> V_276 . V_277 = false ;
}
V_44:
if ( ! V_193 -> V_270 )
F_21 ( V_25 ) ;
}
static inline int F_136 ( struct V_24 * V_25 )
{
return F_137 ( V_25 ) ||
! ( V_25 -> V_278 . V_279 & V_280 ) ;
}
static struct V_6 * F_138 ( struct V_24 * V_25 ,
struct V_18 * V_281 ,
T_9 V_282 ,
bool V_283 ,
const char * V_284 ,
int V_40 )
{
struct V_6 * V_9 ;
int V_13 , V_23 ;
V_13 = F_139 ( & V_17 , 0 , V_285 , V_63 ) ;
if ( V_13 < 0 )
return F_37 ( V_13 ) ;
V_9 = F_140 ( sizeof( struct V_6 ) , V_63 ) ;
if ( ! V_9 ) {
V_23 = - V_64 ;
goto V_44;
}
V_9 -> V_40 = V_40 ;
V_9 -> V_42 = F_136 ( V_25 ) ;
V_9 -> V_8 = F_141 ( V_15 ) ;
if ( V_9 -> V_8 == NULL ) {
V_23 = - V_64 ;
goto V_286;
}
F_142 ( & V_9 -> V_287 ) ;
F_143 ( & V_9 -> V_288 ) ;
V_9 -> V_12 = 1 ;
V_23 = F_144 ( & V_9 -> V_16 , V_25 , & V_9 -> V_287 , V_284 ) ;
if ( V_23 )
goto V_289;
V_9 -> V_16 . V_194 = V_9 ;
V_9 -> V_8 -> V_290 = V_291 ;
V_9 -> V_8 -> V_14 = V_13 * V_15 ;
V_9 -> V_8 -> V_292 = & V_293 ;
V_9 -> V_8 -> V_11 = V_9 ;
V_9 -> V_8 -> V_16 = V_9 -> V_16 . V_16 ;
V_9 -> V_281 = V_281 ;
F_23 ( V_9 -> V_8 , V_9 -> V_42 || V_283 ) ;
V_9 -> V_8 -> V_101 = V_294 ;
if ( V_40 & ( V_98 | V_41 ) )
V_9 -> V_8 -> V_101 |= V_295 ;
snprintf ( V_9 -> V_8 -> V_39 , sizeof( V_9 -> V_8 -> V_39 ) ,
L_39 , V_25 -> V_84 -> V_296 , V_284 ? V_284 : L_40 ) ;
if ( F_76 ( V_25 ) )
F_145 ( V_9 -> V_16 . V_16 ,
V_25 -> V_27 . V_297 ) ;
else
F_145 ( V_9 -> V_16 . V_16 , 512 ) ;
F_146 ( V_9 -> V_8 , V_282 ) ;
if ( F_147 ( V_25 -> V_84 ) ) {
if ( ( F_76 ( V_25 ) &&
V_25 -> V_278 . V_298 >= V_299 ) ||
( F_123 ( V_25 ) &&
V_25 -> V_300 . V_120 & V_301 ) )
V_9 -> V_101 |= V_256 ;
}
if ( F_76 ( V_25 ) &&
V_9 -> V_101 & V_256 &&
( ( V_25 -> V_27 . V_215 & V_216 ) ||
V_25 -> V_27 . V_217 ) ) {
V_9 -> V_101 |= V_242 ;
F_148 ( V_9 -> V_16 . V_16 , true , true ) ;
}
return V_9 ;
V_289:
F_12 ( V_9 -> V_8 ) ;
V_286:
F_13 ( V_9 ) ;
V_44:
F_11 ( & V_17 , V_13 ) ;
return F_37 ( V_23 ) ;
}
static struct V_6 * F_149 ( struct V_24 * V_25 )
{
T_9 V_282 ;
if ( ! F_123 ( V_25 ) && F_120 ( V_25 ) ) {
V_282 = V_25 -> V_27 . V_57 ;
} else {
V_282 = ( F_150 ( T_9 ) ) V_25 -> V_278 . V_302
<< ( V_25 -> V_278 . V_303 - 9 ) ;
}
return F_138 ( V_25 , & V_25 -> V_19 , V_282 , false , NULL ,
V_304 ) ;
}
static int F_151 ( struct V_24 * V_25 ,
struct V_6 * V_9 ,
unsigned int V_126 ,
T_9 V_282 ,
bool V_283 ,
const char * V_284 ,
int V_40 )
{
char V_305 [ 10 ] ;
struct V_6 * V_33 ;
V_33 = F_138 ( V_25 , F_152 ( V_9 -> V_8 ) , V_282 , V_283 ,
V_284 , V_40 ) ;
if ( F_62 ( V_33 ) )
return F_63 ( V_33 ) ;
V_33 -> V_126 = V_126 ;
F_153 ( & V_33 -> V_288 , & V_9 -> V_288 ) ;
F_154 ( ( V_69 ) F_33 ( V_33 -> V_8 ) , 512 , V_306 ,
V_305 , sizeof( V_305 ) ) ;
F_22 ( L_41 ,
V_33 -> V_8 -> V_39 , F_155 ( V_25 ) ,
F_156 ( V_25 ) , V_33 -> V_126 , V_305 ) ;
return 0 ;
}
static int F_157 ( struct V_24 * V_25 , struct V_6 * V_9 )
{
int V_307 , V_23 = 0 ;
if ( ! F_76 ( V_25 ) )
return 0 ;
for ( V_307 = 0 ; V_307 < V_25 -> V_308 ; V_307 ++ ) {
if ( V_25 -> V_288 [ V_307 ] . V_282 ) {
V_23 = F_151 ( V_25 , V_9 ,
V_25 -> V_288 [ V_307 ] . V_309 ,
V_25 -> V_288 [ V_307 ] . V_282 >> 9 ,
V_25 -> V_288 [ V_307 ] . V_310 ,
V_25 -> V_288 [ V_307 ] . V_169 ,
V_25 -> V_288 [ V_307 ] . V_40 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
static void F_158 ( struct V_6 * V_9 )
{
struct V_24 * V_25 ;
if ( V_9 ) {
V_25 = V_9 -> V_16 . V_25 ;
F_159 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_8 -> V_101 & V_311 ) {
F_160 ( F_152 ( V_9 -> V_8 ) , & V_9 -> V_310 ) ;
if ( ( V_9 -> V_40 & V_41 ) &&
V_25 -> V_27 . V_312 )
F_160 ( F_152 ( V_9 -> V_8 ) ,
& V_9 -> V_313 ) ;
F_161 ( V_9 -> V_8 ) ;
}
F_9 ( V_9 ) ;
}
}
static void F_162 ( struct V_24 * V_25 ,
struct V_6 * V_9 )
{
struct V_314 * V_315 , * V_2 ;
struct V_6 * V_33 ;
F_163 (pos, q, &md->part) {
V_33 = F_164 ( V_315 , struct V_6 , V_288 ) ;
F_165 ( V_315 ) ;
F_158 ( V_33 ) ;
}
}
static int F_166 ( struct V_6 * V_9 )
{
int V_23 ;
struct V_24 * V_25 = V_9 -> V_16 . V_25 ;
F_167 ( V_9 -> V_281 , V_9 -> V_8 ) ;
V_9 -> V_310 . V_316 = F_25 ;
V_9 -> V_310 . V_317 = F_27 ;
F_168 ( & V_9 -> V_310 . V_21 ) ;
V_9 -> V_310 . V_21 . V_169 = L_42 ;
V_9 -> V_310 . V_21 . V_47 = V_318 | V_319 ;
V_23 = F_169 ( F_152 ( V_9 -> V_8 ) , & V_9 -> V_310 ) ;
if ( V_23 )
goto V_320;
if ( ( V_9 -> V_40 & V_41 ) &&
V_25 -> V_27 . V_312 ) {
T_10 V_47 ;
if ( V_25 -> V_27 . V_28 & V_321 )
V_47 = V_318 ;
else
V_47 = V_318 | V_319 ;
V_9 -> V_313 . V_316 = F_14 ;
V_9 -> V_313 . V_317 = F_16 ;
F_168 ( & V_9 -> V_313 . V_21 ) ;
V_9 -> V_313 . V_21 . V_47 = V_47 ;
V_9 -> V_313 . V_21 . V_169 =
L_43 ;
V_23 = F_169 ( F_152 ( V_9 -> V_8 ) ,
& V_9 -> V_313 ) ;
if ( V_23 )
goto V_322;
}
return V_23 ;
V_322:
F_160 ( F_152 ( V_9 -> V_8 ) , & V_9 -> V_310 ) ;
V_320:
F_161 ( V_9 -> V_8 ) ;
return V_23 ;
}
static int F_170 ( struct V_24 * V_25 )
{
struct V_6 * V_9 , * V_33 ;
char V_305 [ 10 ] ;
int V_23 ;
if ( ! ( V_25 -> V_278 . V_279 & V_323 ) )
return - V_191 ;
F_171 ( V_25 , V_324 ) ;
V_23 = F_172 ( V_25 ) ;
if ( V_23 )
return V_23 ;
V_9 = F_149 ( V_25 ) ;
if ( F_62 ( V_9 ) ) {
F_173 ( V_25 ) ;
return F_63 ( V_9 ) ;
}
F_154 ( ( V_69 ) F_33 ( V_9 -> V_8 ) , 512 , V_306 ,
V_305 , sizeof( V_305 ) ) ;
F_22 ( L_44 ,
V_9 -> V_8 -> V_39 , F_155 ( V_25 ) , F_156 ( V_25 ) ,
V_305 , V_9 -> V_42 ? L_45 : L_40 ) ;
if ( F_157 ( V_25 , V_9 ) )
goto V_44;
F_174 ( & V_25 -> V_19 , V_9 ) ;
if ( F_166 ( V_9 ) )
goto V_44;
F_24 (part_md, &md->part, part) {
if ( F_166 ( V_33 ) )
goto V_44;
}
F_175 ( & V_25 -> V_19 , 3000 ) ;
F_176 ( & V_25 -> V_19 ) ;
if ( V_25 -> type != V_325 ) {
F_177 ( & V_25 -> V_19 ) ;
F_178 ( & V_25 -> V_19 ) ;
}
return 0 ;
V_44:
F_162 ( V_25 , V_9 ) ;
F_158 ( V_9 ) ;
F_173 ( V_25 ) ;
return 0 ;
}
static void F_179 ( struct V_24 * V_25 )
{
struct V_6 * V_9 = F_64 ( & V_25 -> V_19 ) ;
F_162 ( V_25 , V_9 ) ;
F_180 ( & V_25 -> V_19 ) ;
F_181 ( V_25 -> V_84 ) ;
F_53 ( V_25 , V_9 ) ;
F_182 ( V_25 -> V_84 ) ;
if ( V_25 -> type != V_325 )
F_183 ( & V_25 -> V_19 ) ;
F_184 ( & V_25 -> V_19 ) ;
F_158 ( V_9 ) ;
F_174 ( & V_25 -> V_19 , NULL ) ;
F_173 ( V_25 ) ;
}
static int F_185 ( struct V_24 * V_25 )
{
struct V_6 * V_33 ;
struct V_6 * V_9 = F_64 ( & V_25 -> V_19 ) ;
if ( V_9 ) {
F_186 ( & V_9 -> V_16 ) ;
F_24 (part_md, &md->part, part) {
F_186 ( & V_33 -> V_16 ) ;
}
}
return 0 ;
}
static void F_187 ( struct V_24 * V_25 )
{
F_185 ( V_25 ) ;
}
static int F_188 ( struct V_18 * V_19 )
{
struct V_24 * V_25 = F_189 ( V_19 ) ;
return F_185 ( V_25 ) ;
}
static int F_190 ( struct V_18 * V_19 )
{
struct V_6 * V_33 ;
struct V_6 * V_9 = F_64 ( V_19 ) ;
if ( V_9 ) {
V_9 -> V_131 = V_9 -> V_126 ;
F_191 ( & V_9 -> V_16 ) ;
F_24 (part_md, &md->part, part) {
F_191 ( & V_33 -> V_16 ) ;
}
}
return 0 ;
}
static int T_11 F_192 ( void )
{
int V_326 ;
if ( V_15 != V_327 )
F_22 ( L_46 , V_15 ) ;
V_285 = F_193 ( V_328 , ( 1 << V_329 ) / V_15 ) ;
V_326 = F_194 ( V_291 , L_47 ) ;
if ( V_326 )
goto V_44;
V_326 = F_195 ( & V_330 ) ;
if ( V_326 )
goto V_331;
return 0 ;
V_331:
F_196 ( V_291 , L_47 ) ;
V_44:
return V_326 ;
}
static void T_12 F_197 ( void )
{
F_198 ( & V_330 ) ;
F_196 ( V_291 , L_47 ) ;
}
