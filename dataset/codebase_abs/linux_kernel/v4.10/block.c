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
F_7 ( & V_12 ) ;
F_8 ( & V_13 , V_8 ) ;
F_9 ( & V_12 ) ;
F_10 ( V_4 -> V_3 ) ;
F_11 ( V_4 ) ;
}
F_3 ( & V_5 ) ;
}
static T_1 F_12 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_13 ( V_15 ) ) ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
int V_22 = 0 ;
if ( V_21 -> V_23 . V_24 & V_25 )
V_22 = 2 ;
else if ( V_21 -> V_23 . V_24 & V_26 )
V_22 = 1 ;
V_19 = snprintf ( V_18 , V_27 , L_1 , V_22 ) ;
F_5 ( V_4 ) ;
return V_19 ;
}
static T_1 F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_28 )
{
int V_19 ;
struct V_1 * V_4 , * V_29 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
if ( F_15 ( V_18 , 0 , & V_30 ) )
return - V_31 ;
if ( V_30 != 1 )
return V_28 ;
V_4 = F_1 ( F_13 ( V_15 ) ) ;
V_21 = V_4 -> V_11 . V_21 ;
F_16 ( V_21 ) ;
V_19 = F_17 ( V_21 , V_32 , V_33 ,
V_21 -> V_23 . V_24 |
V_26 ,
V_21 -> V_23 . V_34 ) ;
if ( V_19 )
F_18 ( L_2 , V_4 -> V_3 -> V_35 , V_19 ) ;
else
V_21 -> V_23 . V_24 |= V_26 ;
F_19 ( V_21 ) ;
if ( ! V_19 ) {
F_20 ( L_3 ,
V_4 -> V_3 -> V_35 ) ;
F_21 ( V_4 -> V_3 , 1 ) ;
F_22 (part_md, &md->part, part)
if ( V_29 -> V_36 == V_37 ) {
F_20 ( L_3 , V_29 -> V_3 -> V_35 ) ;
F_21 ( V_29 -> V_3 , 1 ) ;
}
}
F_5 ( V_4 ) ;
return V_28 ;
}
static T_1 F_23 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_13 ( V_15 ) ) ;
V_19 = snprintf ( V_18 , V_27 , L_1 ,
F_24 ( F_13 ( V_15 ) ) ^
V_4 -> V_38 ) ;
F_5 ( V_4 ) ;
return V_19 ;
}
static T_1 F_25 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , T_2 V_28 )
{
int V_19 ;
char * V_39 ;
struct V_1 * V_4 = F_1 ( F_13 ( V_15 ) ) ;
unsigned long V_30 = F_26 ( V_18 , & V_39 , 0 ) ;
if ( V_39 == V_18 ) {
V_19 = - V_31 ;
goto V_40;
}
F_21 ( F_13 ( V_15 ) , V_30 || V_4 -> V_38 ) ;
V_19 = V_28 ;
V_40:
F_5 ( V_4 ) ;
return V_19 ;
}
static int F_27 ( struct V_41 * V_42 , T_3 V_43 )
{
struct V_1 * V_4 = F_1 ( V_42 -> V_44 ) ;
int V_19 = - V_45 ;
F_2 ( & V_46 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_28 ( V_42 ) ;
V_19 = 0 ;
if ( ( V_43 & V_47 ) && V_4 -> V_38 ) {
F_5 ( V_4 ) ;
V_19 = - V_48 ;
}
}
F_3 ( & V_46 ) ;
return V_19 ;
}
static void F_29 ( struct V_2 * V_3 , T_3 V_43 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_46 ) ;
F_5 ( V_4 ) ;
F_3 ( & V_46 ) ;
}
static int
F_30 ( struct V_41 * V_42 , struct V_49 * V_50 )
{
V_50 -> V_51 = F_31 ( V_42 -> V_44 ) / ( 4 * 16 ) ;
V_50 -> V_52 = 4 ;
V_50 -> V_53 = 16 ;
return 0 ;
}
static struct V_54 * F_32 (
struct V_55 T_4 * V_56 )
{
struct V_54 * V_57 ;
int V_58 ;
V_57 = F_33 ( sizeof( * V_57 ) , V_59 ) ;
if ( ! V_57 ) {
V_58 = - V_60 ;
goto V_40;
}
if ( F_34 ( & V_57 -> V_61 , V_56 , sizeof( V_57 -> V_61 ) ) ) {
V_58 = - V_62 ;
goto V_63;
}
V_57 -> V_64 = ( V_65 ) V_57 -> V_61 . V_66 * V_57 -> V_61 . V_67 ;
if ( V_57 -> V_64 > V_68 ) {
V_58 = - V_69 ;
goto V_63;
}
if ( ! V_57 -> V_64 ) {
V_57 -> V_18 = NULL ;
return V_57 ;
}
V_57 -> V_18 = F_33 ( V_57 -> V_64 , V_59 ) ;
if ( ! V_57 -> V_18 ) {
V_58 = - V_60 ;
goto V_63;
}
if ( F_34 ( V_57 -> V_18 , ( void T_4 * ) ( unsigned long )
V_57 -> V_61 . V_70 , V_57 -> V_64 ) ) {
V_58 = - V_62 ;
goto V_71;
}
return V_57 ;
V_71:
F_11 ( V_57 -> V_18 ) ;
V_63:
F_11 ( V_57 ) ;
V_40:
return F_35 ( V_58 ) ;
}
static int F_36 ( struct V_55 T_4 * V_72 ,
struct V_54 * V_57 )
{
struct V_55 * V_61 = & V_57 -> V_61 ;
if ( F_37 ( & ( V_72 -> V_73 ) , V_61 -> V_73 ,
sizeof( V_61 -> V_73 ) ) )
return - V_62 ;
if ( ! V_57 -> V_61 . V_74 ) {
if ( F_37 ( ( void T_4 * ) ( unsigned long ) V_61 -> V_70 ,
V_57 -> V_18 , V_57 -> V_64 ) )
return - V_62 ;
}
return 0 ;
}
static int F_38 ( struct V_20 * V_21 , T_5 * V_75 ,
T_5 V_76 )
{
int V_58 ;
T_5 V_77 = 0 ;
if ( ! V_75 || ! V_76 )
return - V_31 ;
do {
V_58 = F_39 ( V_21 , V_75 , 5 ) ;
if ( V_58 )
break;
if ( ! F_40 ( * V_75 ) &&
( F_41 ( * V_75 ) != V_78 ) )
break;
F_42 ( 1000 , 5000 ) ;
} while ( ++ V_77 < V_76 );
if ( V_77 == V_76 )
V_58 = - V_79 ;
return V_58 ;
}
static int F_43 ( struct V_20 * V_21 )
{
int V_58 ;
if ( ! F_44 ( V_21 ) ) {
F_45 ( L_4 ,
F_46 ( V_21 -> V_80 ) , V_81 ) ;
V_58 = - V_82 ;
goto V_40;
}
F_47 ( L_5 ,
F_46 ( V_21 -> V_80 ) , V_81 ) ;
V_58 = F_17 ( V_21 , V_32 ,
V_83 , 1 ,
V_84 ) ;
if ( V_58 )
F_18 ( L_6 ,
F_46 ( V_21 -> V_80 ) , V_81 , V_58 ) ;
F_47 ( L_7 , F_46 ( V_21 -> V_80 ) ,
V_81 ) ;
V_40:
return V_58 ;
}
static int F_48 ( struct V_20 * V_21 , struct V_1 * V_4 ,
struct V_54 * V_57 )
{
struct V_85 V_86 = { 0 } ;
struct V_87 V_88 = { 0 } ;
struct V_89 V_90 = { NULL } ;
struct V_91 V_92 ;
int V_58 ;
int V_93 = false ;
T_5 V_75 = 0 ;
if ( ! V_21 || ! V_4 || ! V_57 )
return - V_31 ;
if ( V_4 -> V_36 & V_94 )
V_93 = true ;
V_86 . V_95 = V_57 -> V_61 . V_95 ;
V_86 . V_96 = V_57 -> V_61 . V_96 ;
V_86 . V_97 = V_57 -> V_61 . V_97 ;
if ( V_57 -> V_64 ) {
V_88 . V_92 = & V_92 ;
V_88 . V_98 = 1 ;
V_88 . V_66 = V_57 -> V_61 . V_66 ;
V_88 . V_67 = V_57 -> V_61 . V_67 ;
F_49 ( V_88 . V_92 , V_57 -> V_18 , V_57 -> V_64 ) ;
if ( V_57 -> V_61 . V_74 )
V_88 . V_97 = V_99 ;
else
V_88 . V_97 = V_100 ;
F_50 ( & V_88 , V_21 ) ;
if ( V_57 -> V_61 . V_101 )
V_88 . V_102 = V_57 -> V_61 . V_101 ;
if ( ( V_86 . V_97 & V_103 ) == V_103 ) {
V_88 . V_102 = V_57 -> V_61 . V_104 * 1000000 ;
}
V_90 . V_88 = & V_88 ;
}
V_90 . V_86 = & V_86 ;
V_58 = F_51 ( V_21 , V_4 ) ;
if ( V_58 )
return V_58 ;
if ( V_57 -> V_61 . V_105 ) {
V_58 = F_52 ( V_21 -> V_80 , V_21 ) ;
if ( V_58 )
return V_58 ;
}
if ( V_93 ) {
V_58 = F_53 ( V_21 , V_88 . V_67 ,
V_57 -> V_61 . V_74 & ( 1 << 31 ) ) ;
if ( V_58 )
return V_58 ;
}
if ( ( F_54 ( V_86 . V_96 ) == V_83 ) &&
( V_86 . V_95 == V_106 ) ) {
V_58 = F_43 ( V_21 ) ;
if ( V_58 )
F_18 ( L_8 ,
V_81 , V_58 ) ;
return V_58 ;
}
F_55 ( V_21 -> V_80 , & V_90 ) ;
if ( V_86 . error ) {
F_56 ( F_57 ( V_21 -> V_80 ) , L_9 ,
V_81 , V_86 . error ) ;
return V_86 . error ;
}
if ( V_88 . error ) {
F_56 ( F_57 ( V_21 -> V_80 ) , L_10 ,
V_81 , V_88 . error ) ;
return V_88 . error ;
}
if ( V_57 -> V_61 . V_107 )
F_42 ( V_57 -> V_61 . V_107 , V_57 -> V_61 . V_108 ) ;
memcpy ( & ( V_57 -> V_61 . V_73 ) , V_86 . V_109 , sizeof( V_86 . V_109 ) ) ;
if ( V_93 ) {
V_58 = F_38 ( V_21 , & V_75 , 5 ) ;
if ( V_58 )
F_56 ( F_57 ( V_21 -> V_80 ) ,
L_11 ,
V_81 , V_75 , V_58 ) ;
}
return V_58 ;
}
static int F_58 ( struct V_41 * V_42 ,
struct V_55 T_4 * V_72 )
{
struct V_54 * V_57 ;
struct V_1 * V_4 ;
struct V_20 * V_21 ;
int V_58 = 0 , V_110 = 0 ;
if ( ( ! F_59 ( V_111 ) ) || ( V_42 != V_42 -> V_112 ) )
return - V_79 ;
V_57 = F_32 ( V_72 ) ;
if ( F_60 ( V_57 ) )
return F_61 ( V_57 ) ;
V_4 = F_1 ( V_42 -> V_44 ) ;
if ( ! V_4 ) {
V_58 = - V_31 ;
goto V_113;
}
V_21 = V_4 -> V_11 . V_21 ;
if ( F_60 ( V_21 ) ) {
V_58 = F_61 ( V_21 ) ;
goto V_114;
}
F_16 ( V_21 ) ;
V_110 = F_48 ( V_21 , V_4 , V_57 ) ;
if ( V_4 -> V_36 & V_94 )
F_51 ( V_21 , F_62 ( & V_21 -> V_15 ) ) ;
F_19 ( V_21 ) ;
V_58 = F_36 ( V_72 , V_57 ) ;
V_114:
F_5 ( V_4 ) ;
V_113:
F_11 ( V_57 -> V_18 ) ;
F_11 ( V_57 ) ;
return V_110 ? V_110 : V_58 ;
}
static int F_63 ( struct V_41 * V_42 ,
struct V_115 T_4 * V_56 )
{
struct V_54 * * V_57 = NULL ;
struct V_55 T_4 * V_116 = V_56 -> V_116 ;
struct V_20 * V_21 ;
struct V_1 * V_4 ;
int V_117 , V_58 = 0 , V_110 = 0 ;
T_6 V_118 ;
if ( ( ! F_59 ( V_111 ) ) || ( V_42 != V_42 -> V_112 ) )
return - V_79 ;
if ( F_34 ( & V_118 , & V_56 -> V_118 ,
sizeof( V_118 ) ) )
return - V_62 ;
if ( V_118 > V_119 )
return - V_31 ;
V_57 = F_64 ( V_118 , sizeof( * V_57 ) , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
V_57 [ V_117 ] = F_32 ( & V_116 [ V_117 ] ) ;
if ( F_60 ( V_57 [ V_117 ] ) ) {
V_58 = F_61 ( V_57 [ V_117 ] ) ;
V_118 = V_117 ;
goto V_113;
}
}
V_4 = F_1 ( V_42 -> V_44 ) ;
if ( ! V_4 ) {
V_58 = - V_31 ;
goto V_113;
}
V_21 = V_4 -> V_11 . V_21 ;
if ( F_60 ( V_21 ) ) {
V_58 = F_61 ( V_21 ) ;
goto V_114;
}
F_16 ( V_21 ) ;
for ( V_117 = 0 ; V_117 < V_118 && ! V_110 ; V_117 ++ )
V_110 = F_48 ( V_21 , V_4 , V_57 [ V_117 ] ) ;
if ( V_4 -> V_36 & V_94 )
F_51 ( V_21 , F_62 ( & V_21 -> V_15 ) ) ;
F_19 ( V_21 ) ;
for ( V_117 = 0 ; V_117 < V_118 && ! V_58 ; V_117 ++ )
V_58 = F_36 ( & V_116 [ V_117 ] , V_57 [ V_117 ] ) ;
V_114:
F_5 ( V_4 ) ;
V_113:
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
F_11 ( V_57 [ V_117 ] -> V_18 ) ;
F_11 ( V_57 [ V_117 ] ) ;
}
F_11 ( V_57 ) ;
return V_110 ? V_110 : V_58 ;
}
static int F_65 ( struct V_41 * V_42 , T_3 V_43 ,
unsigned int V_86 , unsigned long V_96 )
{
switch ( V_86 ) {
case V_120 :
return F_58 ( V_42 ,
(struct V_55 T_4 * ) V_96 ) ;
case V_121 :
return F_63 ( V_42 ,
(struct V_115 T_4 * ) V_96 ) ;
default:
return - V_31 ;
}
}
static int F_66 ( struct V_41 * V_42 , T_3 V_43 ,
unsigned int V_86 , unsigned long V_96 )
{
return F_65 ( V_42 , V_43 , V_86 , ( unsigned long ) F_67 ( V_96 ) ) ;
}
static inline int F_51 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_122 = F_62 ( & V_21 -> V_15 ) ;
if ( V_122 -> V_123 == V_4 -> V_124 )
return 0 ;
if ( F_68 ( V_21 ) ) {
T_7 V_125 = V_21 -> V_23 . V_125 ;
if ( V_4 -> V_124 == V_126 )
F_69 ( V_21 -> V_80 ) ;
V_125 &= ~ V_127 ;
V_125 |= V_4 -> V_124 ;
V_19 = F_17 ( V_21 , V_32 ,
V_128 , V_125 ,
V_21 -> V_23 . V_34 ) ;
if ( V_19 ) {
if ( V_4 -> V_124 == V_126 )
F_70 ( V_21 -> V_80 ) ;
return V_19 ;
}
V_21 -> V_23 . V_125 = V_125 ;
if ( V_122 -> V_123 == V_126 )
F_70 ( V_21 -> V_80 ) ;
}
V_122 -> V_123 = V_4 -> V_124 ;
return 0 ;
}
static T_5 F_71 ( struct V_20 * V_21 )
{
int V_58 ;
T_5 V_129 ;
T_8 * V_67 ;
struct V_89 V_90 = { NULL } ;
struct V_85 V_86 = { 0 } ;
struct V_87 V_88 = { 0 } ;
struct V_91 V_92 ;
V_86 . V_95 = V_130 ;
V_86 . V_96 = V_21 -> V_131 << 16 ;
V_86 . V_97 = V_132 | V_133 | V_134 ;
V_58 = F_72 ( V_21 -> V_80 , & V_86 , 0 ) ;
if ( V_58 )
return ( T_5 ) - 1 ;
if ( ! F_73 ( V_21 -> V_80 ) && ! ( V_86 . V_109 [ 0 ] & V_135 ) )
return ( T_5 ) - 1 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . V_95 = V_136 ;
V_86 . V_96 = 0 ;
V_86 . V_97 = V_132 | V_133 | V_137 ;
V_88 . V_66 = 4 ;
V_88 . V_67 = 1 ;
V_88 . V_97 = V_100 ;
V_88 . V_92 = & V_92 ;
V_88 . V_98 = 1 ;
F_50 ( & V_88 , V_21 ) ;
V_90 . V_86 = & V_86 ;
V_90 . V_88 = & V_88 ;
V_67 = F_33 ( 4 , V_59 ) ;
if ( ! V_67 )
return ( T_5 ) - 1 ;
F_49 ( & V_92 , V_67 , 4 ) ;
F_55 ( V_21 -> V_80 , & V_90 ) ;
V_129 = F_74 ( * V_67 ) ;
F_11 ( V_67 ) ;
if ( V_86 . error || V_88 . error )
V_129 = ( T_5 ) - 1 ;
return V_129 ;
}
static int F_39 ( struct V_20 * V_21 , T_5 * V_75 , int V_138 )
{
struct V_85 V_86 = { 0 } ;
int V_58 ;
V_86 . V_95 = V_139 ;
if ( ! F_73 ( V_21 -> V_80 ) )
V_86 . V_96 = V_21 -> V_131 << 16 ;
V_86 . V_97 = V_140 | V_133 | V_134 ;
V_58 = F_72 ( V_21 -> V_80 , & V_86 , V_138 ) ;
if ( V_58 == 0 )
* V_75 = V_86 . V_109 [ 0 ] ;
return V_58 ;
}
static int F_75 ( struct V_20 * V_21 , unsigned int V_141 ,
bool V_142 , struct V_143 * V_144 , bool * V_145 )
{
unsigned long V_146 = V_147 + F_76 ( V_141 ) ;
int V_58 = 0 ;
T_5 V_75 ;
do {
V_58 = F_39 ( V_21 , & V_75 , 5 ) ;
if ( V_58 ) {
F_18 ( L_12 ,
V_144 -> V_148 -> V_35 , V_58 ) ;
return V_58 ;
}
if ( V_75 & V_149 ) {
F_18 ( L_13 ,
V_144 -> V_148 -> V_35 , V_81 , V_75 ) ;
* V_145 = true ;
}
if ( ( V_21 -> V_80 -> V_150 & V_151 ) &&
V_142 )
break;
if ( F_77 ( V_147 , V_146 ) ) {
F_18 ( L_14 ,
F_46 ( V_21 -> V_80 ) ,
V_144 -> V_148 -> V_35 , V_81 ) ;
return - V_152 ;
}
} while ( ! ( V_75 & V_153 ) ||
( F_41 ( V_75 ) == V_78 ) );
return V_58 ;
}
static int F_78 ( struct V_20 * V_21 , unsigned int V_141 ,
struct V_143 * V_144 , bool * V_145 , T_5 * V_154 )
{
struct V_155 * V_80 = V_21 -> V_80 ;
struct V_85 V_86 = { 0 } ;
int V_58 ;
bool V_156 = F_79 ( V_144 ) == V_157 ;
if ( V_80 -> V_158 && ( V_141 > V_80 -> V_158 ) )
V_156 = false ;
V_86 . V_95 = V_159 ;
if ( V_156 ) {
V_86 . V_97 = V_160 | V_103 | V_134 ;
V_86 . V_161 = V_141 ;
} else {
V_86 . V_97 = V_132 | V_133 | V_134 ;
}
V_58 = F_72 ( V_80 , & V_86 , 5 ) ;
if ( V_58 )
return V_58 ;
* V_154 = V_86 . V_109 [ 0 ] ;
if ( F_79 ( V_144 ) == V_162 )
return 0 ;
if ( ! F_73 ( V_80 ) &&
( * V_154 & V_149 ) ) {
F_18 ( L_15 ,
V_144 -> V_148 -> V_35 , V_81 , * V_154 ) ;
* V_145 = true ;
}
return F_75 ( V_21 , V_141 , V_156 , V_144 , V_145 ) ;
}
static int F_80 ( struct V_143 * V_144 , const char * V_163 , int error ,
bool V_164 , T_5 V_75 )
{
switch ( error ) {
case - V_165 :
F_18 ( L_16 ,
V_144 -> V_148 -> V_35 , L_17 ,
V_163 , V_75 ) ;
return V_166 ;
case - V_152 :
F_18 ( L_16 ,
V_144 -> V_148 -> V_35 , L_18 , V_163 , V_75 ) ;
if ( ! V_164 ) {
F_18 ( L_19 ,
V_144 -> V_148 -> V_35 ) ;
return V_166 ;
}
if ( V_75 & ( V_167 | V_168 ) ) {
F_18 ( L_20 ,
V_144 -> V_148 -> V_35 ) ;
return V_166 ;
}
return V_169 ;
default:
F_18 ( L_21 ,
V_144 -> V_148 -> V_35 , error , V_75 ) ;
return V_169 ;
}
}
static int F_81 ( struct V_20 * V_21 , struct V_143 * V_144 ,
struct V_170 * V_171 , bool * V_172 , bool * V_145 )
{
bool V_173 = true ;
T_5 V_75 , V_154 = 0 ;
int V_58 , V_174 ;
if ( F_82 ( V_21 ) )
return V_175 ;
for ( V_174 = 2 ; V_174 >= 0 ; V_174 -- ) {
V_58 = F_39 ( V_21 , & V_75 , 0 ) ;
if ( ! V_58 )
break;
F_83 ( V_21 -> V_80 ) ;
V_173 = false ;
F_18 ( L_22 ,
V_144 -> V_148 -> V_35 , V_58 , V_174 ? L_23 : L_24 ) ;
}
if ( V_58 ) {
if ( F_84 ( V_21 -> V_80 ) )
return V_175 ;
return V_169 ;
}
if ( ( V_75 & V_176 ) ||
( V_171 -> V_177 . V_109 [ 0 ] & V_176 ) ||
( V_171 -> V_86 . V_109 [ 0 ] & V_176 ) )
* V_172 = true ;
if ( ! F_73 ( V_21 -> V_80 ) && F_79 ( V_144 ) != V_162 )
if ( ( V_75 & V_149 ) ||
( V_171 -> V_177 . V_109 [ 0 ] & V_149 ) ) {
F_18 ( L_25 ,
V_144 -> V_148 -> V_35 , V_81 ,
V_171 -> V_177 . V_109 [ 0 ] , V_75 ) ;
* V_145 = true ;
}
if ( F_41 ( V_75 ) == V_178 ||
F_41 ( V_75 ) == V_179 ) {
V_58 = F_78 ( V_21 ,
F_85 ( V_171 -> V_88 . V_102 , 1000000 ) ,
V_144 , V_145 , & V_154 ) ;
if ( V_58 ) {
F_18 ( L_26 ,
V_144 -> V_148 -> V_35 , V_58 ) ;
return V_169 ;
}
if ( V_154 & V_176 )
* V_172 = true ;
}
if ( V_171 -> V_180 . error )
return F_80 ( V_144 , L_27 , V_171 -> V_180 . error ,
V_173 , V_75 ) ;
if ( V_171 -> V_86 . error )
return F_80 ( V_144 , L_28 , V_171 -> V_86 . error ,
V_173 , V_75 ) ;
if ( ! V_171 -> V_177 . error )
return V_181 ;
F_20 ( L_29 ,
V_144 -> V_148 -> V_35 , V_171 -> V_177 . error ,
V_171 -> V_86 . V_109 [ 0 ] , V_75 ) ;
if ( V_154 ) {
V_171 -> V_177 . V_109 [ 0 ] = V_154 ;
V_171 -> V_177 . error = 0 ;
}
return V_181 ;
}
static int F_86 ( struct V_1 * V_4 , struct V_155 * V_80 ,
int type )
{
int V_58 ;
if ( V_4 -> V_182 & type )
return - V_183 ;
V_4 -> V_182 |= type ;
V_58 = F_87 ( V_80 ) ;
if ( V_58 != - V_82 ) {
struct V_1 * V_122 =
F_62 ( & V_80 -> V_21 -> V_15 ) ;
int V_184 ;
V_122 -> V_123 = V_122 -> V_124 ;
V_184 = F_51 ( V_80 -> V_21 , V_4 ) ;
if ( V_184 ) {
return - V_185 ;
}
}
return V_58 ;
}
static inline void F_88 ( struct V_1 * V_4 , int type )
{
V_4 -> V_182 &= ~ type ;
}
int F_89 ( struct V_186 * V_187 )
{
struct V_1 * V_4 = V_187 -> V_188 ;
if ( V_4 && V_4 -> V_124 == V_126 )
return true ;
return false ;
}
static int F_90 ( struct V_186 * V_187 , struct V_143 * V_144 )
{
struct V_1 * V_4 = V_187 -> V_188 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
unsigned int V_189 , V_190 , V_96 ;
int V_58 = 0 , type = V_191 ;
if ( ! F_91 ( V_21 ) ) {
V_58 = - V_82 ;
goto V_40;
}
V_189 = F_92 ( V_144 ) ;
V_190 = F_93 ( V_144 ) ;
if ( F_94 ( V_21 ) )
V_96 = V_192 ;
else if ( F_95 ( V_21 ) )
V_96 = V_193 ;
else
V_96 = V_194 ;
V_174:
if ( V_21 -> V_195 & V_196 ) {
V_58 = F_17 ( V_21 , V_32 ,
V_197 ,
V_96 == V_193 ?
V_198 :
V_199 ,
0 ) ;
if ( V_58 )
goto V_40;
}
V_58 = F_96 ( V_21 , V_189 , V_190 , V_96 ) ;
V_40:
if ( V_58 == - V_200 && ! F_86 ( V_4 , V_21 -> V_80 , type ) )
goto V_174;
if ( ! V_58 )
F_88 ( V_4 , type ) ;
F_97 ( V_144 , V_58 , F_98 ( V_144 ) ) ;
return V_58 ? 0 : 1 ;
}
static int F_99 ( struct V_186 * V_187 ,
struct V_143 * V_144 )
{
struct V_1 * V_4 = V_187 -> V_188 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
unsigned int V_189 , V_190 , V_96 ;
int V_58 = 0 , type = V_201 ;
if ( ! ( F_100 ( V_21 ) ) ) {
V_58 = - V_82 ;
goto V_40;
}
V_189 = F_92 ( V_144 ) ;
V_190 = F_93 ( V_144 ) ;
if ( F_95 ( V_21 ) && ! F_101 ( V_21 , V_189 , V_190 ) )
V_96 = V_202 ;
else
V_96 = V_203 ;
V_174:
if ( V_21 -> V_195 & V_196 ) {
V_58 = F_17 ( V_21 , V_32 ,
V_197 ,
V_96 == V_202 ?
V_204 :
V_205 ,
0 ) ;
if ( V_58 )
goto V_206;
}
V_58 = F_96 ( V_21 , V_189 , V_190 , V_96 ) ;
if ( V_58 == - V_200 )
goto V_206;
if ( V_58 )
goto V_40;
if ( V_96 == V_202 ) {
if ( V_21 -> V_195 & V_196 ) {
V_58 = F_17 ( V_21 , V_32 ,
V_197 ,
V_207 ,
0 ) ;
if ( V_58 )
goto V_206;
}
V_58 = F_96 ( V_21 , V_189 , V_190 , V_208 ) ;
if ( V_58 == - V_200 )
goto V_206;
if ( V_58 )
goto V_40;
}
V_206:
if ( V_58 && ! F_86 ( V_4 , V_21 -> V_80 , type ) )
goto V_174;
if ( ! V_58 )
F_88 ( V_4 , type ) ;
V_40:
F_97 ( V_144 , V_58 , F_98 ( V_144 ) ) ;
return V_58 ? 0 : 1 ;
}
static int F_102 ( struct V_186 * V_187 , struct V_143 * V_144 )
{
struct V_1 * V_4 = V_187 -> V_188 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
int V_19 = 0 ;
V_19 = F_103 ( V_21 ) ;
if ( V_19 )
V_19 = - V_200 ;
F_104 ( V_144 , V_19 ) ;
return V_19 ? 0 : 1 ;
}
static inline void F_105 ( struct V_170 * V_171 ,
struct V_20 * V_21 ,
struct V_143 * V_144 )
{
if ( ! ( V_21 -> V_23 . V_209 & V_210 ) ) {
if ( ! F_106 ( V_171 -> V_86 . V_96 , V_21 -> V_23 . V_211 ) )
V_171 -> V_88 . V_67 = 1 ;
if ( V_171 -> V_88 . V_67 > V_21 -> V_23 . V_211 )
V_171 -> V_88 . V_67 = V_21 -> V_23 . V_211 ;
else if ( V_171 -> V_88 . V_67 < V_21 -> V_23 . V_211 )
V_171 -> V_88 . V_67 = 1 ;
}
}
static enum V_212 F_107 ( struct V_20 * V_21 ,
struct V_213 * V_214 )
{
struct V_215 * V_216 = F_108 ( V_214 , struct V_215 ,
V_217 ) ;
struct V_170 * V_171 = & V_216 -> V_171 ;
struct V_143 * V_144 = V_216 -> V_144 ;
int V_218 = V_21 -> V_80 -> V_218 ;
bool V_172 = false ;
bool V_145 = false ;
if ( V_171 -> V_180 . error || V_171 -> V_86 . error || V_171 -> V_177 . error ||
V_171 -> V_88 . error ) {
switch ( F_81 ( V_21 , V_144 , V_171 , & V_172 , & V_145 ) ) {
case V_166 :
return V_219 ;
case V_169 :
return V_220 ;
case V_175 :
return V_221 ;
case V_181 :
break;
}
}
if ( V_171 -> V_86 . V_109 [ 0 ] & V_222 ) {
F_18 ( L_30 ,
V_144 -> V_148 -> V_35 , V_171 -> V_86 . V_109 [ 0 ] ) ;
return V_220 ;
}
if ( ! F_73 ( V_21 -> V_80 ) && F_79 ( V_144 ) != V_162 ) {
int V_58 ;
if ( V_171 -> V_177 . V_109 [ 0 ] & V_149 ) {
F_18 ( L_31 ,
V_144 -> V_148 -> V_35 , V_81 ,
V_171 -> V_177 . V_109 [ 0 ] ) ;
V_145 = true ;
}
V_58 = F_75 ( V_21 , V_223 , false , V_144 ,
& V_145 ) ;
if ( V_58 )
return V_224 ;
}
if ( V_145 ) {
F_45 ( L_32 ,
V_144 -> V_148 -> V_35 ) ;
return V_219 ;
}
if ( V_171 -> V_88 . error ) {
if ( V_218 && ! V_171 -> V_225 ) {
F_47 ( L_33 ,
V_144 -> V_148 -> V_35 ) ;
V_171 -> V_225 = 1 ;
return V_219 ;
}
F_18 ( L_34 ,
V_144 -> V_148 -> V_35 , V_171 -> V_88 . error ,
( unsigned ) F_92 ( V_144 ) ,
( unsigned ) F_93 ( V_144 ) ,
V_171 -> V_86 . V_109 [ 0 ] , V_171 -> V_177 . V_109 [ 0 ] ) ;
if ( F_79 ( V_144 ) == V_162 ) {
if ( V_172 )
return V_226 ;
return V_227 ;
} else {
return V_224 ;
}
}
if ( ! V_171 -> V_88 . V_228 )
return V_219 ;
if ( F_98 ( V_144 ) != V_171 -> V_88 . V_228 )
return V_229 ;
return V_230 ;
}
static void F_109 ( struct V_215 * V_231 ,
struct V_20 * V_21 ,
int V_232 ,
struct V_186 * V_187 )
{
T_5 V_233 , V_234 ;
struct V_170 * V_171 = & V_231 -> V_171 ;
struct V_143 * V_144 = V_231 -> V_144 ;
struct V_1 * V_4 = V_187 -> V_188 ;
bool V_235 ;
bool V_236 = ( V_144 -> V_237 & V_238 ) &&
( F_79 ( V_144 ) == V_157 ) &&
( V_4 -> V_97 & V_239 ) ;
memset ( V_171 , 0 , sizeof( struct V_170 ) ) ;
V_171 -> V_90 . V_86 = & V_171 -> V_86 ;
V_171 -> V_90 . V_88 = & V_171 -> V_88 ;
V_171 -> V_86 . V_96 = F_92 ( V_144 ) ;
if ( ! F_110 ( V_21 ) )
V_171 -> V_86 . V_96 <<= 9 ;
V_171 -> V_86 . V_97 = V_132 | V_133 | V_137 ;
V_171 -> V_88 . V_66 = 512 ;
V_171 -> V_177 . V_95 = V_159 ;
V_171 -> V_177 . V_96 = 0 ;
V_171 -> V_88 . V_67 = F_93 ( V_144 ) ;
if ( V_171 -> V_88 . V_67 > V_21 -> V_80 -> V_240 )
V_171 -> V_88 . V_67 = V_21 -> V_80 -> V_240 ;
if ( V_171 -> V_88 . V_67 > 1 ) {
if ( V_232 )
V_171 -> V_88 . V_67 = 1 ;
if ( V_21 -> V_80 -> V_241 -> V_242 )
V_171 -> V_88 . V_67 = V_21 -> V_80 -> V_241 -> V_242 ( V_21 ,
( F_79 ( V_144 ) == V_162 ) ?
V_100 : V_99 ,
V_171 -> V_88 . V_67 ) ;
}
if ( V_171 -> V_88 . V_67 > 1 || V_236 ) {
if ( ! F_73 ( V_21 -> V_80 ) ||
F_79 ( V_144 ) == V_162 )
V_171 -> V_90 . V_177 = & V_171 -> V_177 ;
V_233 = V_243 ;
V_234 = V_244 ;
} else {
V_171 -> V_90 . V_177 = NULL ;
V_233 = V_245 ;
V_234 = V_246 ;
}
if ( F_79 ( V_144 ) == V_162 ) {
V_171 -> V_86 . V_95 = V_233 ;
V_171 -> V_88 . V_97 = V_100 ;
if ( V_171 -> V_90 . V_177 )
V_171 -> V_177 . V_97 = V_132 | V_133 |
V_134 ;
} else {
V_171 -> V_86 . V_95 = V_234 ;
V_171 -> V_88 . V_97 = V_99 ;
if ( V_171 -> V_90 . V_177 )
V_171 -> V_177 . V_97 = V_160 | V_103 |
V_134 ;
}
if ( V_236 )
F_105 ( V_171 , V_21 , V_144 ) ;
V_235 = ( V_21 -> V_23 . V_247 ) &&
( V_144 -> V_237 & V_248 ) &&
( F_79 ( V_144 ) == V_157 ) &&
( ( V_171 -> V_88 . V_67 * V_171 -> V_88 . V_66 ) >=
V_21 -> V_23 . V_247 ) ;
if ( ( V_4 -> V_97 & V_249 ) && F_111 ( V_171 -> V_86 . V_95 ) &&
( V_236 || ! ( V_21 -> V_195 & V_250 ) ||
V_235 ) ) {
V_171 -> V_180 . V_95 = V_251 ;
V_171 -> V_180 . V_96 = V_171 -> V_88 . V_67 |
( V_236 ? ( 1 << 31 ) : 0 ) |
( V_235 ? ( 1 << 29 ) : 0 ) ;
V_171 -> V_180 . V_97 = V_133 | V_134 ;
V_171 -> V_90 . V_180 = & V_171 -> V_180 ;
}
F_50 ( & V_171 -> V_88 , V_21 ) ;
V_171 -> V_88 . V_92 = V_231 -> V_92 ;
V_171 -> V_88 . V_98 = F_112 ( V_187 , V_231 ) ;
if ( V_171 -> V_88 . V_67 != F_93 ( V_144 ) ) {
int V_117 , V_252 = V_171 -> V_88 . V_67 << 9 ;
struct V_91 * V_92 ;
F_113 (brq->data.sg, sg, brq->data.sg_len, i) {
V_252 -= V_92 -> V_253 ;
if ( V_252 <= 0 ) {
V_92 -> V_253 += V_252 ;
V_117 ++ ;
break;
}
}
V_171 -> V_88 . V_98 = V_117 ;
}
V_231 -> V_217 . V_90 = & V_171 -> V_90 ;
V_231 -> V_217 . V_254 = F_107 ;
F_114 ( V_231 ) ;
}
static int F_115 ( struct V_1 * V_4 , struct V_20 * V_21 ,
struct V_170 * V_171 , struct V_143 * V_144 ,
int V_19 )
{
struct V_215 * V_255 ;
V_255 = F_108 ( V_171 , struct V_215 , V_171 ) ;
if ( F_116 ( V_21 ) ) {
T_5 V_67 ;
V_67 = F_71 ( V_21 ) ;
if ( V_67 != ( T_5 ) - 1 ) {
V_19 = F_97 ( V_144 , 0 , V_67 << 9 ) ;
}
} else {
V_19 = F_97 ( V_144 , 0 , V_171 -> V_88 . V_228 ) ;
}
return V_19 ;
}
static int F_117 ( struct V_186 * V_187 , struct V_143 * V_256 )
{
struct V_1 * V_4 = V_187 -> V_188 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
struct V_170 * V_171 ;
int V_19 = 1 , V_232 = 0 , V_174 = 0 , type , V_225 = 0 ;
enum V_212 V_75 ;
struct V_215 * V_255 ;
struct V_143 * V_144 ;
struct V_213 * V_214 ;
if ( ! V_256 && ! V_187 -> V_257 -> V_144 )
return 0 ;
do {
if ( V_256 ) {
if ( F_118 ( V_21 ) &&
! F_106 ( F_93 ( V_256 ) , 8 ) ) {
F_18 ( L_35 ,
V_256 -> V_148 -> V_35 ) ;
V_255 = V_187 -> V_258 ;
V_144 = V_256 ;
V_256 = NULL ;
goto V_259;
}
F_109 ( V_187 -> V_258 , V_21 , 0 , V_187 ) ;
V_214 = & V_187 -> V_258 -> V_217 ;
} else
V_214 = NULL ;
V_214 = F_119 ( V_21 -> V_80 , V_214 , & V_75 ) ;
if ( ! V_214 ) {
if ( V_75 == V_260 )
V_187 -> V_97 |= V_261 ;
return 0 ;
}
V_255 = F_108 ( V_214 , struct V_215 , V_217 ) ;
V_171 = & V_255 -> V_171 ;
V_144 = V_255 -> V_144 ;
type = F_79 ( V_144 ) == V_162 ? V_262 : V_263 ;
F_120 ( V_255 ) ;
switch ( V_75 ) {
case V_230 :
case V_229 :
F_88 ( V_4 , type ) ;
V_19 = F_97 ( V_144 , 0 ,
V_171 -> V_88 . V_228 ) ;
if ( V_75 == V_230 && V_19 ) {
F_18 ( L_36 ,
V_81 , F_98 ( V_144 ) ,
V_171 -> V_88 . V_228 ) ;
V_256 = NULL ;
goto V_259;
}
break;
case V_224 :
V_19 = F_115 ( V_4 , V_21 , V_171 , V_144 , V_19 ) ;
if ( F_86 ( V_4 , V_21 -> V_80 , type ) )
goto V_259;
if ( ! V_19 )
goto V_264;
break;
case V_219 :
V_225 = V_171 -> V_225 ;
if ( V_174 ++ < 5 )
break;
case V_220 :
if ( ! F_86 ( V_4 , V_21 -> V_80 , type ) )
break;
goto V_259;
case V_227 : {
int V_58 ;
V_58 = F_86 ( V_4 , V_21 -> V_80 , type ) ;
if ( ! V_58 )
break;
if ( V_58 == - V_185 )
goto V_259;
}
case V_226 :
if ( V_171 -> V_88 . V_67 > 1 ) {
F_45 ( L_37 ,
V_144 -> V_148 -> V_35 ) ;
V_232 = 1 ;
break;
}
V_19 = F_97 ( V_144 , - V_200 ,
V_171 -> V_88 . V_66 ) ;
if ( ! V_19 )
goto V_264;
break;
case V_221 :
goto V_259;
default:
F_18 ( L_38 ,
V_144 -> V_148 -> V_35 , V_75 ) ;
goto V_259;
}
if ( V_19 ) {
F_109 ( V_255 , V_21 ,
V_232 , V_187 ) ;
F_119 ( V_21 -> V_80 ,
& V_255 -> V_217 , NULL ) ;
V_255 -> V_171 . V_225 = V_225 ;
}
} while ( V_19 );
return 1 ;
V_259:
if ( F_82 ( V_21 ) )
V_144 -> V_265 |= V_266 ;
while ( V_19 )
V_19 = F_97 ( V_144 , - V_200 ,
F_121 ( V_144 ) ) ;
V_264:
if ( V_256 ) {
if ( F_82 ( V_21 ) ) {
V_256 -> V_265 |= V_266 ;
F_104 ( V_256 , - V_200 ) ;
} else {
F_109 ( V_187 -> V_258 , V_21 , 0 , V_187 ) ;
F_119 ( V_21 -> V_80 ,
& V_187 -> V_258 -> V_217 , NULL ) ;
}
}
return 0 ;
}
int F_122 ( struct V_186 * V_187 , struct V_143 * V_144 )
{
int V_19 ;
struct V_1 * V_4 = V_187 -> V_188 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
bool V_267 = F_123 ( V_144 ) ;
if ( V_144 && ! V_187 -> V_257 -> V_144 )
F_16 ( V_21 ) ;
V_19 = F_51 ( V_21 , V_4 ) ;
if ( V_19 ) {
if ( V_144 ) {
F_104 ( V_144 , - V_200 ) ;
}
V_19 = 0 ;
goto V_40;
}
V_187 -> V_97 &= ~ V_261 ;
if ( V_144 && F_124 ( V_144 ) == V_268 ) {
if ( V_21 -> V_80 -> V_214 )
F_117 ( V_187 , NULL ) ;
V_19 = F_90 ( V_187 , V_144 ) ;
} else if ( V_144 && F_124 ( V_144 ) == V_269 ) {
if ( V_21 -> V_80 -> V_214 )
F_117 ( V_187 , NULL ) ;
V_19 = F_99 ( V_187 , V_144 ) ;
} else if ( V_144 && F_124 ( V_144 ) == V_270 ) {
if ( V_21 -> V_80 -> V_214 )
F_117 ( V_187 , NULL ) ;
V_19 = F_102 ( V_187 , V_144 ) ;
} else {
V_19 = F_117 ( V_187 , V_144 ) ;
}
V_40:
if ( ( ! V_144 && ! ( V_187 -> V_97 & V_261 ) ) || V_267 )
F_19 ( V_21 ) ;
return V_19 ;
}
static inline int F_125 ( struct V_20 * V_21 )
{
return F_126 ( V_21 ) ||
! ( V_21 -> V_271 . V_272 & V_273 ) ;
}
static struct V_1 * F_127 ( struct V_20 * V_21 ,
struct V_14 * V_274 ,
T_9 V_275 ,
bool V_276 ,
const char * V_277 ,
int V_36 )
{
struct V_1 * V_4 ;
int V_8 , V_19 ;
V_278:
if ( ! F_128 ( & V_13 , V_59 ) )
return F_35 ( - V_60 ) ;
F_7 ( & V_12 ) ;
V_19 = F_129 ( & V_13 , & V_8 ) ;
F_9 ( & V_12 ) ;
if ( V_19 == - V_279 )
goto V_278;
else if ( V_19 )
return F_35 ( V_19 ) ;
if ( V_8 >= V_280 ) {
V_19 = - V_281 ;
goto V_40;
}
V_4 = F_130 ( sizeof( struct V_1 ) , V_59 ) ;
if ( ! V_4 ) {
V_19 = - V_60 ;
goto V_40;
}
V_4 -> V_36 = V_36 ;
V_4 -> V_38 = F_125 ( V_21 ) ;
V_4 -> V_3 = F_131 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_60 ;
goto V_282;
}
F_132 ( & V_4 -> V_283 ) ;
F_133 ( & V_4 -> V_284 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_134 ( & V_4 -> V_11 , V_21 , & V_4 -> V_283 , V_277 ) ;
if ( V_19 )
goto V_285;
V_4 -> V_11 . V_188 = V_4 ;
V_4 -> V_3 -> V_286 = V_287 ;
V_4 -> V_3 -> V_9 = V_8 * V_10 ;
V_4 -> V_3 -> V_288 = & V_289 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_11 = V_4 -> V_11 . V_11 ;
V_4 -> V_274 = V_274 ;
F_21 ( V_4 -> V_3 , V_4 -> V_38 || V_276 ) ;
V_4 -> V_3 -> V_97 = V_290 ;
if ( V_36 & ( V_94 | V_37 ) )
V_4 -> V_3 -> V_97 |= V_291 ;
snprintf ( V_4 -> V_3 -> V_35 , sizeof( V_4 -> V_3 -> V_35 ) ,
L_39 , V_21 -> V_80 -> V_292 , V_277 ? V_277 : L_40 ) ;
if ( F_68 ( V_21 ) )
F_135 ( V_4 -> V_11 . V_11 ,
V_21 -> V_23 . V_293 ) ;
else
F_135 ( V_4 -> V_11 . V_11 , 512 ) ;
F_136 ( V_4 -> V_3 , V_275 ) ;
if ( F_137 ( V_21 -> V_80 ) ) {
if ( ( F_68 ( V_21 ) &&
V_21 -> V_271 . V_294 >= V_295 ) ||
( F_116 ( V_21 ) &&
V_21 -> V_296 . V_116 & V_297 ) )
V_4 -> V_97 |= V_249 ;
}
if ( F_68 ( V_21 ) &&
V_4 -> V_97 & V_249 &&
( ( V_21 -> V_23 . V_209 & V_210 ) ||
V_21 -> V_23 . V_211 ) ) {
V_4 -> V_97 |= V_239 ;
F_138 ( V_4 -> V_11 . V_11 , true , true ) ;
}
return V_4 ;
V_285:
F_10 ( V_4 -> V_3 ) ;
V_282:
F_11 ( V_4 ) ;
V_40:
F_7 ( & V_12 ) ;
F_8 ( & V_13 , V_8 ) ;
F_9 ( & V_12 ) ;
return F_35 ( V_19 ) ;
}
static struct V_1 * F_139 ( struct V_20 * V_21 )
{
T_9 V_275 ;
if ( ! F_116 ( V_21 ) && F_110 ( V_21 ) ) {
V_275 = V_21 -> V_23 . V_53 ;
} else {
V_275 = ( F_140 ( T_9 ) ) V_21 -> V_271 . V_298
<< ( V_21 -> V_271 . V_299 - 9 ) ;
}
return F_127 ( V_21 , & V_21 -> V_15 , V_275 , false , NULL ,
V_300 ) ;
}
static int F_141 ( struct V_20 * V_21 ,
struct V_1 * V_4 ,
unsigned int V_124 ,
T_9 V_275 ,
bool V_276 ,
const char * V_277 ,
int V_36 )
{
char V_301 [ 10 ] ;
struct V_1 * V_29 ;
V_29 = F_127 ( V_21 , F_142 ( V_4 -> V_3 ) , V_275 , V_276 ,
V_277 , V_36 ) ;
if ( F_60 ( V_29 ) )
return F_61 ( V_29 ) ;
V_29 -> V_124 = V_124 ;
F_143 ( & V_29 -> V_284 , & V_4 -> V_284 ) ;
F_144 ( ( V_65 ) F_31 ( V_29 -> V_3 ) , 512 , V_302 ,
V_301 , sizeof( V_301 ) ) ;
F_20 ( L_41 ,
V_29 -> V_3 -> V_35 , F_145 ( V_21 ) ,
F_146 ( V_21 ) , V_29 -> V_124 , V_301 ) ;
return 0 ;
}
static int F_147 ( struct V_20 * V_21 , struct V_1 * V_4 )
{
int V_303 , V_19 = 0 ;
if ( ! F_68 ( V_21 ) )
return 0 ;
for ( V_303 = 0 ; V_303 < V_21 -> V_304 ; V_303 ++ ) {
if ( V_21 -> V_284 [ V_303 ] . V_275 ) {
V_19 = F_141 ( V_21 , V_4 ,
V_21 -> V_284 [ V_303 ] . V_305 ,
V_21 -> V_284 [ V_303 ] . V_275 >> 9 ,
V_21 -> V_284 [ V_303 ] . V_306 ,
V_21 -> V_284 [ V_303 ] . V_163 ,
V_21 -> V_284 [ V_303 ] . V_36 ) ;
if ( V_19 )
return V_19 ;
}
}
return V_19 ;
}
static void F_148 ( struct V_1 * V_4 )
{
struct V_20 * V_21 ;
if ( V_4 ) {
V_21 = V_4 -> V_11 . V_21 ;
F_149 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_3 -> V_97 & V_307 ) {
F_150 ( F_142 ( V_4 -> V_3 ) , & V_4 -> V_306 ) ;
if ( ( V_4 -> V_36 & V_37 ) &&
V_21 -> V_23 . V_308 )
F_150 ( F_142 ( V_4 -> V_3 ) ,
& V_4 -> V_309 ) ;
F_151 ( V_4 -> V_3 ) ;
}
F_5 ( V_4 ) ;
}
}
static void F_152 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
struct V_310 * V_311 , * V_312 ;
struct V_1 * V_29 ;
F_153 (pos, q, &md->part) {
V_29 = F_154 ( V_311 , struct V_1 , V_284 ) ;
F_155 ( V_311 ) ;
F_148 ( V_29 ) ;
}
}
static int F_156 ( struct V_1 * V_4 )
{
int V_19 ;
struct V_20 * V_21 = V_4 -> V_11 . V_21 ;
F_157 ( V_4 -> V_274 , V_4 -> V_3 ) ;
V_4 -> V_306 . V_313 = F_23 ;
V_4 -> V_306 . V_314 = F_25 ;
F_158 ( & V_4 -> V_306 . V_17 ) ;
V_4 -> V_306 . V_17 . V_163 = L_42 ;
V_4 -> V_306 . V_17 . V_43 = V_315 | V_316 ;
V_19 = F_159 ( F_142 ( V_4 -> V_3 ) , & V_4 -> V_306 ) ;
if ( V_19 )
goto V_317;
if ( ( V_4 -> V_36 & V_37 ) &&
V_21 -> V_23 . V_308 ) {
T_10 V_43 ;
if ( V_21 -> V_23 . V_24 & V_318 )
V_43 = V_315 ;
else
V_43 = V_315 | V_316 ;
V_4 -> V_309 . V_313 = F_12 ;
V_4 -> V_309 . V_314 = F_14 ;
F_158 ( & V_4 -> V_309 . V_17 ) ;
V_4 -> V_309 . V_17 . V_43 = V_43 ;
V_4 -> V_309 . V_17 . V_163 =
L_43 ;
V_19 = F_159 ( F_142 ( V_4 -> V_3 ) ,
& V_4 -> V_309 ) ;
if ( V_19 )
goto V_319;
}
return V_19 ;
V_319:
F_150 ( F_142 ( V_4 -> V_3 ) , & V_4 -> V_306 ) ;
V_317:
F_151 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_160 ( struct V_20 * V_21 )
{
struct V_1 * V_4 , * V_29 ;
char V_301 [ 10 ] ;
if ( ! ( V_21 -> V_271 . V_272 & V_320 ) )
return - V_185 ;
F_161 ( V_21 , V_321 ) ;
V_4 = F_139 ( V_21 ) ;
if ( F_60 ( V_4 ) )
return F_61 ( V_4 ) ;
F_144 ( ( V_65 ) F_31 ( V_4 -> V_3 ) , 512 , V_302 ,
V_301 , sizeof( V_301 ) ) ;
F_20 ( L_44 ,
V_4 -> V_3 -> V_35 , F_145 ( V_21 ) , F_146 ( V_21 ) ,
V_301 , V_4 -> V_38 ? L_45 : L_40 ) ;
if ( F_147 ( V_21 , V_4 ) )
goto V_40;
F_162 ( & V_21 -> V_15 , V_4 ) ;
if ( F_156 ( V_4 ) )
goto V_40;
F_22 (part_md, &md->part, part) {
if ( F_156 ( V_29 ) )
goto V_40;
}
F_163 ( & V_21 -> V_15 , 3000 ) ;
F_164 ( & V_21 -> V_15 ) ;
if ( V_21 -> type != V_322 ) {
F_165 ( & V_21 -> V_15 ) ;
F_166 ( & V_21 -> V_15 ) ;
}
return 0 ;
V_40:
F_152 ( V_21 , V_4 ) ;
F_148 ( V_4 ) ;
return 0 ;
}
static void F_167 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_62 ( & V_21 -> V_15 ) ;
F_152 ( V_21 , V_4 ) ;
F_168 ( & V_21 -> V_15 ) ;
F_169 ( V_21 -> V_80 ) ;
F_51 ( V_21 , V_4 ) ;
F_170 ( V_21 -> V_80 ) ;
if ( V_21 -> type != V_322 )
F_171 ( & V_21 -> V_15 ) ;
F_172 ( & V_21 -> V_15 ) ;
F_148 ( V_4 ) ;
F_162 ( & V_21 -> V_15 , NULL ) ;
}
static int F_173 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_62 ( & V_21 -> V_15 ) ;
if ( V_4 ) {
F_174 ( & V_4 -> V_11 ) ;
F_22 (part_md, &md->part, part) {
F_174 ( & V_29 -> V_11 ) ;
}
}
return 0 ;
}
static void F_175 ( struct V_20 * V_21 )
{
F_173 ( V_21 ) ;
}
static int F_176 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = F_177 ( V_15 ) ;
return F_173 ( V_21 ) ;
}
static int F_178 ( struct V_14 * V_15 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_62 ( V_15 ) ;
if ( V_4 ) {
V_4 -> V_123 = V_4 -> V_124 ;
F_179 ( & V_4 -> V_11 ) ;
F_22 (part_md, &md->part, part) {
F_179 ( & V_29 -> V_11 ) ;
}
}
return 0 ;
}
static int T_11 F_180 ( void )
{
int V_323 ;
if ( V_10 != V_324 )
F_20 ( L_46 , V_10 ) ;
V_280 = F_181 ( V_325 , ( 1 << V_326 ) / V_10 ) ;
V_323 = F_182 ( V_287 , L_47 ) ;
if ( V_323 )
goto V_40;
V_323 = F_183 ( & V_327 ) ;
if ( V_323 )
goto V_328;
return 0 ;
V_328:
F_184 ( V_287 , L_47 ) ;
V_40:
return V_323 ;
}
static void T_12 F_185 ( void )
{
F_186 ( & V_327 ) ;
F_184 ( V_287 , L_47 ) ;
}
