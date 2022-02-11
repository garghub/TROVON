static struct V_1 * F_1 ( struct V_2 * V_2 , unsigned V_3 )
{
struct V_1 * V_4 = NULL ;
if ( V_3 < V_2 -> V_5 . V_6 ) {
struct V_1 T_1 * * V_7 =
F_2 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_2 ( V_7 [ V_3 ] ) ;
}
return V_4 ;
}
static inline struct V_8 * F_3 ( const struct V_9 * V_10 )
{
return F_4 ( V_10 -> V_11 ) ;
}
static bool F_5 ( const struct V_9 * V_10 )
{
return V_10 && ( V_10 -> V_12 & V_13 ) && F_6 ( V_10 ) ;
}
static unsigned int F_7 ( const struct V_1 * V_4 )
{
return V_4 -> V_14 * sizeof( struct V_15 ) ;
}
static unsigned int F_8 ( const struct V_9 * V_10 )
{
return V_10 -> V_16 ;
}
static bool F_9 ( const struct V_17 * V_18 , unsigned int V_16 )
{
if ( V_18 -> V_19 <= V_16 )
return false ;
if ( F_10 ( V_18 ) && F_11 ( V_18 ) <= V_16 )
return false ;
return true ;
}
static bool F_12 ( struct V_1 * V_4 , struct V_17 * V_18 ,
struct V_20 V_21 )
{
struct V_22 * V_23 ;
bool V_24 = true ;
if ( ! F_13 ( V_18 , 12 ) )
return false ;
V_23 = F_14 ( V_18 ) ;
if ( V_23 -> V_25 == 4 ) {
V_18 -> V_26 = F_15 ( V_27 ) ;
F_16 ( & V_23 -> V_28 ,
F_15 ( V_23 -> V_29 << 8 ) ,
F_15 ( V_21 . V_29 << 8 ) ) ;
V_23 -> V_29 = V_21 . V_29 ;
}
else if ( V_23 -> V_25 == 6 ) {
struct V_30 * V_31 = F_17 ( V_18 ) ;
V_18 -> V_26 = F_15 ( V_32 ) ;
V_31 -> V_33 = V_21 . V_29 ;
}
else
V_24 = false ;
return V_24 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_9 * V_10 ,
struct V_34 * V_35 , struct V_9 * V_36 )
{
struct V_2 * V_2 = F_19 ( V_10 ) ;
struct V_15 * V_37 ;
struct V_1 * V_4 ;
struct V_20 V_21 ;
struct V_9 * V_38 ;
struct V_8 * V_39 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned int V_16 ;
int V_42 ;
V_39 = F_3 ( V_10 ) ;
if ( ! V_39 || ! V_39 -> V_43 )
goto V_44;
if ( V_18 -> V_45 != V_46 )
goto V_44;
if ( ( V_18 = F_20 ( V_18 , V_47 ) ) == NULL )
goto V_44;
if ( ! F_13 ( V_18 , sizeof( * V_37 ) ) )
goto V_44;
V_37 = F_21 ( V_18 ) ;
V_21 = F_22 ( V_37 ) ;
F_23 ( V_18 , sizeof( * V_37 ) ) ;
F_24 ( V_18 ) ;
F_25 ( V_18 ) ;
V_4 = F_1 ( V_2 , V_21 . V_48 ) ;
if ( ! V_4 )
goto V_44;
V_38 = F_2 ( V_4 -> V_49 ) ;
if ( ! F_5 ( V_38 ) )
goto V_44;
if ( F_26 ( V_18 ) )
goto V_44;
F_27 ( V_18 ) ;
if ( V_21 . V_29 <= 1 )
goto V_44;
V_21 . V_29 -= 1 ;
V_41 = F_7 ( V_4 ) ;
V_16 = F_8 ( V_38 ) ;
if ( F_9 ( V_18 , V_16 - V_41 ) )
goto V_44;
V_40 = F_28 ( V_38 ) ;
if ( ! V_38 -> V_50 )
V_40 = 0 ;
if ( F_29 ( V_18 , V_40 + V_41 ) )
goto V_44;
V_18 -> V_10 = V_38 ;
V_18 -> V_26 = F_15 ( V_51 ) ;
if ( F_30 ( ! V_41 && V_21 . V_52 ) ) {
if ( ! F_12 ( V_4 , V_18 , V_21 ) )
goto V_44;
} else {
bool V_52 ;
int V_53 ;
F_31 ( V_18 , V_41 ) ;
F_24 ( V_18 ) ;
V_37 = F_21 ( V_18 ) ;
V_52 = V_21 . V_52 ;
for ( V_53 = V_4 -> V_14 - 1 ; V_53 >= 0 ; V_53 -- ) {
V_37 [ V_53 ] = F_32 ( V_4 -> V_54 [ V_53 ] , V_21 . V_29 , 0 , V_52 ) ;
V_52 = false ;
}
}
V_42 = F_33 ( V_4 -> V_55 , V_38 , V_4 -> V_56 , V_18 ) ;
if ( V_42 )
F_34 ( L_1 ,
V_57 , V_42 ) ;
return 0 ;
V_44:
F_35 ( V_18 ) ;
return V_58 ;
}
static struct V_1 * F_36 ( T_2 V_59 )
{
struct V_1 * V_4 ;
V_4 = F_37 ( sizeof( * V_4 ) + V_59 , V_60 ) ;
if ( V_4 )
V_4 -> V_61 = V_59 ;
return V_4 ;
}
static void F_38 ( struct V_1 * V_4 )
{
if ( V_4 )
F_39 ( V_4 , V_62 ) ;
}
static void F_40 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_63 , struct V_1 * V_64 ,
const struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 ? V_66 -> V_68 : NULL ;
unsigned V_69 = V_66 ? V_66 -> V_69 : 0 ;
int V_70 = V_64 ? V_71 : V_72 ;
struct V_1 * V_4 = V_64 ? V_64 : V_63 ;
unsigned V_73 = ( V_63 && V_64 ) ? V_74 : 0 ;
if ( V_4 && ( V_3 >= 16 ) )
F_41 ( V_70 , V_3 , V_4 , V_68 , V_2 , V_69 , V_73 ) ;
}
static void F_42 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_9 * V_10 , struct V_1 * V_64 ,
const struct V_65 * V_66 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 , * V_63 = NULL ;
F_43 () ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_10 || ( V_4 && ( F_44 ( V_4 -> V_49 ) == V_10 ) ) ) {
F_45 ( V_7 [ V_3 ] , V_64 ) ;
V_63 = V_4 ;
}
F_40 ( V_2 , V_3 , V_63 , V_64 , V_66 ) ;
F_38 ( V_63 ) ;
}
static unsigned F_46 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
unsigned V_3 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 16 ; V_3 < V_6 ; V_3 ++ ) {
if ( ! F_44 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_75 ;
}
static int F_47 ( struct V_76 * V_77 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_77 -> V_78 . V_79 ;
struct V_9 * V_10 = NULL ;
struct V_1 * V_4 , * V_63 ;
unsigned V_3 ;
int V_53 ;
int V_42 = - V_80 ;
V_3 = V_77 -> V_81 ;
if ( ( V_3 == V_75 ) &&
( V_77 -> V_82 & V_83 ) ) {
V_3 = F_46 ( V_2 ) ;
}
if ( V_3 < 16 )
goto V_84;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_84;
if ( V_77 -> V_85 > V_86 )
goto V_84;
V_42 = - V_87 ;
V_10 = F_48 ( V_2 , V_77 -> V_88 ) ;
if ( ! V_10 )
goto V_84;
V_42 = - V_80 ;
if ( ! F_3 ( V_10 ) )
goto V_84;
V_42 = - V_80 ;
if ( ( V_77 -> V_89 == V_90 ) &&
( V_10 -> V_91 != V_77 -> V_92 ) )
goto V_84;
V_42 = - V_93 ;
if ( V_77 -> V_82 & V_94 )
goto V_84;
V_42 = - V_95 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_63 = F_44 ( V_7 [ V_3 ] ) ;
if ( ( V_77 -> V_82 & V_96 ) && V_63 )
goto V_84;
V_42 = - V_95 ;
if ( ! ( V_77 -> V_82 & V_74 ) && V_63 )
goto V_84;
V_42 = - V_97 ;
if ( ! ( V_77 -> V_82 & V_83 ) && ! V_63 )
goto V_84;
V_42 = - V_98 ;
V_4 = F_36 ( V_77 -> V_92 ) ;
if ( ! V_4 )
goto V_84;
V_4 -> V_14 = V_77 -> V_85 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_14 ; V_53 ++ )
V_4 -> V_54 [ V_53 ] = V_77 -> V_99 [ V_53 ] ;
V_4 -> V_100 = V_77 -> V_101 ;
F_49 ( V_4 -> V_49 , V_10 ) ;
V_4 -> V_55 = V_77 -> V_89 ;
memcpy ( V_4 -> V_56 , V_77 -> V_102 , V_77 -> V_92 ) ;
F_42 ( V_2 , V_3 , NULL , V_4 , & V_77 -> V_78 ) ;
F_50 ( V_10 ) ;
return 0 ;
V_84:
if ( V_10 )
F_50 ( V_10 ) ;
return V_42 ;
}
static int F_51 ( struct V_76 * V_77 )
{
struct V_2 * V_2 = V_77 -> V_78 . V_79 ;
unsigned V_3 ;
int V_42 = - V_80 ;
V_3 = V_77 -> V_81 ;
if ( V_3 < 16 )
goto V_84;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_84;
F_42 ( V_2 , V_3 , NULL , NULL , & V_77 -> V_78 ) ;
V_42 = 0 ;
V_84:
return V_42 ;
}
static int F_52 ( struct V_9 * V_10 ,
struct V_8 * V_39 )
{
char V_103 [ sizeof( L_2 ) + V_104 ] ;
struct V_105 * V_106 ;
int V_53 ;
V_106 = F_53 ( & V_107 , sizeof( V_107 ) , V_60 ) ;
if ( ! V_106 )
goto V_108;
for ( V_53 = 0 ; V_53 < F_54 ( V_107 ) ; V_53 ++ )
V_106 [ V_53 ] . V_109 = ( char * ) V_39 + ( V_110 ) V_106 [ V_53 ] . V_109 ;
snprintf ( V_103 , sizeof( V_103 ) , L_3 , V_10 -> V_111 ) ;
V_39 -> V_112 = F_55 ( F_19 ( V_10 ) , V_103 , V_106 ) ;
if ( ! V_39 -> V_112 )
goto free;
return 0 ;
free:
F_56 ( V_106 ) ;
V_108:
return - V_113 ;
}
static void F_57 ( struct V_8 * V_39 )
{
struct V_105 * V_106 ;
V_106 = V_39 -> V_112 -> V_114 ;
F_58 ( V_39 -> V_112 ) ;
F_56 ( V_106 ) ;
}
static struct V_8 * F_59 ( struct V_9 * V_10 )
{
struct V_8 * V_39 ;
int V_42 = - V_98 ;
F_43 () ;
V_39 = F_37 ( sizeof( * V_39 ) , V_60 ) ;
if ( ! V_39 )
return F_60 ( V_42 ) ;
V_42 = F_52 ( V_10 , V_39 ) ;
if ( V_42 )
goto free;
F_45 ( V_10 -> V_11 , V_39 ) ;
return V_39 ;
free:
F_56 ( V_39 ) ;
return F_60 ( V_42 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_19 ( V_10 ) ;
struct V_8 * V_39 ;
unsigned V_3 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_44 ( V_4 -> V_49 ) != V_10 )
continue;
V_4 -> V_49 = NULL ;
}
V_39 = F_3 ( V_10 ) ;
if ( ! V_39 )
return;
F_57 ( V_39 ) ;
F_49 ( V_10 -> V_11 , NULL ) ;
F_39 ( V_39 , V_115 ) ;
}
static int F_62 ( struct V_116 * V_117 , unsigned long V_70 ,
void * V_118 )
{
struct V_9 * V_10 = F_63 ( V_118 ) ;
struct V_8 * V_39 ;
switch( V_70 ) {
case V_119 :
if ( ( V_10 -> type == V_120 ) ||
( V_10 -> type == V_121 ) ) {
V_39 = F_59 ( V_10 ) ;
if ( F_64 ( V_39 ) )
return F_65 ( F_66 ( V_39 ) ) ;
}
break;
case V_122 :
F_61 ( V_10 ) ;
break;
case V_123 :
V_39 = F_3 ( V_10 ) ;
if ( V_39 ) {
int V_42 ;
F_57 ( V_39 ) ;
V_42 = F_52 ( V_10 , V_39 ) ;
if ( V_42 )
return F_65 ( V_42 ) ;
}
break;
}
return V_124 ;
}
static int F_67 ( struct V_17 * V_18 ,
T_3 V_106 , const void * V_125 , int V_59 )
{
static const int V_126 [ V_127 + 1 ] = {
V_128 , V_129 , V_130 , V_131 ,
} ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
int V_136 = V_137 ;
V_133 = F_68 ( V_18 , V_138 , V_59 + 2 ) ;
if ( ! V_133 )
return - V_139 ;
if ( V_106 <= V_127 )
V_136 = V_126 [ V_106 ] ;
V_135 = F_69 ( V_133 ) ;
V_135 -> V_140 = V_136 ;
memcpy ( V_135 -> V_141 , V_125 , V_59 ) ;
return 0 ;
}
int F_70 ( struct V_17 * V_18 , int V_142 ,
T_3 V_143 , const T_4 V_48 [] )
{
struct V_132 * V_133 ;
struct V_15 * V_144 ;
bool V_52 ;
int V_53 ;
V_133 = F_68 ( V_18 , V_142 , V_143 * 4 ) ;
if ( ! V_133 )
return - V_139 ;
V_144 = F_69 ( V_133 ) ;
V_52 = true ;
for ( V_53 = V_143 - 1 ; V_53 >= 0 ; V_53 -- ) {
V_144 [ V_53 ] = F_32 ( V_48 [ V_53 ] , 0 , 0 , V_52 ) ;
V_52 = false ;
}
return 0 ;
}
int F_71 ( const struct V_132 * V_133 ,
T_4 V_145 , T_4 * V_143 , T_4 V_48 [] )
{
unsigned V_19 = F_72 ( V_133 ) ;
unsigned V_146 ;
struct V_15 * V_144 ;
bool V_52 ;
int V_53 ;
if ( V_19 & 3 )
return - V_80 ;
V_146 = V_19 / 4 ;
if ( V_146 > V_145 )
return - V_80 ;
V_144 = F_69 ( V_133 ) ;
V_52 = true ;
for ( V_53 = V_146 - 1 ; V_53 >= 0 ; V_53 -- , V_52 = false ) {
struct V_20 V_21 ;
V_21 = F_22 ( V_144 + V_53 ) ;
if ( ( V_21 . V_52 != V_52 ) || V_21 . V_29 || V_21 . V_147 )
return - V_80 ;
switch ( V_21 . V_48 ) {
case V_148 :
return - V_80 ;
}
V_48 [ V_53 ] = V_21 . V_48 ;
}
* V_143 = V_146 ;
return 0 ;
}
static int F_73 ( struct V_17 * V_18 , struct V_67 * V_68 ,
struct V_76 * V_77 )
{
struct V_149 * V_150 ;
struct V_132 * V_151 [ V_152 + 1 ] ;
int V_3 ;
int V_42 ;
V_42 = F_74 ( V_68 , sizeof( * V_150 ) , V_151 , V_152 , V_153 ) ;
if ( V_42 < 0 )
goto V_84;
V_42 = - V_80 ;
V_150 = F_75 ( V_68 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
if ( V_150 -> V_154 != V_155 )
goto V_84;
if ( V_150 -> V_156 != 20 )
goto V_84;
if ( V_150 -> V_157 != 0 )
goto V_84;
if ( V_150 -> V_158 != 0 )
goto V_84;
if ( V_150 -> V_159 != V_160 )
goto V_84;
if ( V_150 -> V_161 != V_162 )
goto V_84;
if ( V_150 -> V_163 != V_164 )
goto V_84;
if ( V_150 -> V_165 != 0 )
goto V_84;
V_77 -> V_81 = V_75 ;
V_77 -> V_101 = V_150 -> V_166 ;
V_77 -> V_82 = V_68 -> V_167 ;
V_77 -> V_78 . V_69 = F_76 ( V_18 ) . V_69 ;
V_77 -> V_78 . V_68 = V_68 ;
V_77 -> V_78 . V_79 = F_77 ( V_18 -> V_168 ) ;
for ( V_3 = 0 ; V_3 <= V_152 ; V_3 ++ ) {
struct V_132 * V_133 = V_151 [ V_3 ] ;
if ( ! V_133 )
continue;
switch( V_3 ) {
case V_169 :
V_77 -> V_88 = F_78 ( V_133 ) ;
break;
case V_170 :
if ( F_71 ( V_133 , V_86 ,
& V_77 -> V_85 ,
V_77 -> V_99 ) )
goto V_84;
break;
case V_171 :
{
T_4 V_172 ;
if ( F_71 ( V_133 , 1 , & V_172 ,
& V_77 -> V_81 ) )
goto V_84;
if ( V_77 -> V_81 < 16 )
goto V_84;
break;
}
case V_138 :
{
struct V_134 * V_135 = F_69 ( V_133 ) ;
if ( F_72 ( V_133 ) < F_79 ( struct V_134 , V_141 ) )
goto V_84;
V_77 -> V_92 = F_72 ( V_133 ) -
F_79 ( struct V_134 , V_141 ) ;
if ( V_77 -> V_92 > V_173 )
goto V_84;
switch( V_135 -> V_140 ) {
case V_131 :
V_77 -> V_89 = V_90 ;
break;
case V_128 :
V_77 -> V_89 = V_174 ;
if ( V_77 -> V_92 != 4 )
goto V_84;
break;
case V_129 :
V_77 -> V_89 = V_175 ;
if ( V_77 -> V_92 != 16 )
goto V_84;
break;
default:
goto V_84;
}
memcpy ( V_77 -> V_102 , V_135 -> V_141 , V_77 -> V_92 ) ;
break;
}
default:
goto V_84;
}
}
V_42 = 0 ;
V_84:
return V_42 ;
}
static int F_80 ( struct V_17 * V_18 , struct V_67 * V_68 )
{
struct V_76 V_77 ;
int V_42 ;
V_42 = F_73 ( V_18 , V_68 , & V_77 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_51 ( & V_77 ) ;
}
static int F_81 ( struct V_17 * V_18 , struct V_67 * V_68 )
{
struct V_76 V_77 ;
int V_42 ;
V_42 = F_73 ( V_18 , V_68 , & V_77 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_47 ( & V_77 ) ;
}
static int F_82 ( struct V_17 * V_18 , T_4 V_69 , T_4 V_176 , int V_70 ,
T_4 V_48 , struct V_1 * V_4 , int V_12 )
{
struct V_9 * V_10 ;
struct V_67 * V_68 ;
struct V_149 * V_150 ;
V_68 = F_83 ( V_18 , V_69 , V_176 , V_70 , sizeof( * V_150 ) , V_12 ) ;
if ( V_68 == NULL )
return - V_139 ;
V_150 = F_75 ( V_68 ) ;
V_150 -> V_154 = V_155 ;
V_150 -> V_156 = 20 ;
V_150 -> V_157 = 0 ;
V_150 -> V_158 = 0 ;
V_150 -> V_159 = V_160 ;
V_150 -> V_166 = V_4 -> V_100 ;
V_150 -> V_161 = V_162 ;
V_150 -> V_163 = V_164 ;
V_150 -> V_165 = 0 ;
if ( V_4 -> V_14 &&
F_70 ( V_18 , V_170 , V_4 -> V_14 , V_4 -> V_54 ) )
goto V_177;
if ( F_67 ( V_18 , V_4 -> V_55 , V_4 -> V_56 , V_4 -> V_61 ) )
goto V_177;
V_10 = F_44 ( V_4 -> V_49 ) ;
if ( V_10 && F_84 ( V_18 , V_169 , V_10 -> V_178 ) )
goto V_177;
if ( F_70 ( V_18 , V_171 , 1 , & V_48 ) )
goto V_177;
F_85 ( V_18 , V_68 ) ;
return 0 ;
V_177:
F_86 ( V_18 , V_68 ) ;
return - V_139 ;
}
static int F_87 ( struct V_17 * V_18 , struct V_179 * V_180 )
{
struct V_2 * V_2 = F_77 ( V_18 -> V_168 ) ;
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
unsigned int V_3 ;
F_43 () ;
V_3 = V_180 -> args [ 0 ] ;
if ( V_3 < 16 )
V_3 = 16 ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_44 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_82 ( V_18 , F_76 ( V_180 -> V_18 ) . V_69 ,
V_180 -> V_68 -> V_181 , V_71 ,
V_3 , V_4 , V_182 ) < 0 )
break;
}
V_180 -> args [ 0 ] = V_3 ;
return V_18 -> V_19 ;
}
static inline T_2 F_88 ( struct V_1 * V_4 )
{
T_2 V_183 =
F_89 ( sizeof( struct V_149 ) )
+ F_90 ( 2 + V_4 -> V_61 )
+ F_90 ( 4 ) ;
if ( V_4 -> V_14 )
V_183 += F_90 ( V_4 -> V_14 * 4 ) ;
if ( V_4 -> V_49 )
V_183 += F_90 ( 4 ) ;
return V_183 ;
}
static void F_41 ( int V_70 , T_4 V_48 , struct V_1 * V_4 ,
struct V_67 * V_68 , struct V_2 * V_2 , T_4 V_69 ,
unsigned int V_73 )
{
struct V_17 * V_18 ;
T_4 V_176 = V_68 ? V_68 -> V_181 : 0 ;
int V_42 = - V_113 ;
V_18 = F_91 ( F_88 ( V_4 ) , V_60 ) ;
if ( V_18 == NULL )
goto V_84;
V_42 = F_82 ( V_18 , V_69 , V_176 , V_70 , V_48 , V_4 , V_73 ) ;
if ( V_42 < 0 ) {
F_92 ( V_42 == - V_139 ) ;
F_35 ( V_18 ) ;
goto V_84;
}
F_93 ( V_18 , V_2 , V_69 , V_184 , V_68 , V_60 ) ;
return;
V_84:
if ( V_42 < 0 )
F_94 ( V_2 , V_184 , V_42 ) ;
}
static int F_95 ( struct V_2 * V_2 , T_2 V_185 )
{
T_2 V_186 = sizeof( struct V_1 * ) * V_185 ;
T_2 V_187 ;
T_2 V_188 ;
struct V_1 T_1 * * V_143 = NULL , * * V_63 ;
struct V_1 * V_189 = NULL , * V_190 = NULL ;
unsigned V_3 ;
if ( V_186 ) {
V_143 = F_37 ( V_186 , V_60 | V_191 | V_192 ) ;
if ( ! V_143 )
V_143 = F_96 ( V_186 ) ;
if ( ! V_143 )
goto V_193;
}
if ( V_185 > V_194 ) {
struct V_9 * V_195 = V_2 -> V_196 ;
V_189 = F_36 ( V_195 -> V_91 ) ;
if ( ! V_189 )
goto V_197;
F_49 ( V_189 -> V_49 , V_195 ) ;
V_189 -> V_100 = V_198 ;
V_189 -> V_55 = V_90 ;
memcpy ( V_189 -> V_56 , V_195 -> V_199 , V_195 -> V_91 ) ;
}
if ( V_185 > V_200 ) {
struct V_9 * V_195 = V_2 -> V_196 ;
V_190 = F_36 ( V_195 -> V_91 ) ;
if ( ! V_190 )
goto V_201;
F_49 ( V_190 -> V_49 , V_195 ) ;
V_190 -> V_100 = V_198 ;
V_190 -> V_55 = V_90 ;
memcpy ( V_190 -> V_56 , V_195 -> V_199 , V_195 -> V_91 ) ;
}
F_97 () ;
V_63 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_187 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_185 ; V_3 < V_187 ; V_3 ++ )
F_42 ( V_2 , V_3 , NULL , NULL , NULL ) ;
V_188 = V_186 ;
if ( V_187 < V_185 )
V_188 = V_187 * sizeof( struct V_1 * ) ;
memcpy ( V_143 , V_63 , V_188 ) ;
if ( ( V_187 <= V_200 ) &&
( V_185 > V_200 ) ) {
F_49 ( V_143 [ V_200 ] , V_190 ) ;
V_190 = NULL ;
}
if ( ( V_187 <= V_194 ) &&
( V_185 > V_194 ) ) {
F_49 ( V_143 [ V_194 ] , V_189 ) ;
V_189 = NULL ;
}
V_2 -> V_5 . V_6 = V_185 ;
F_45 ( V_2 -> V_5 . V_7 , V_143 ) ;
F_98 () ;
F_38 ( V_190 ) ;
F_38 ( V_189 ) ;
if ( V_63 ) {
F_99 () ;
F_100 ( V_63 ) ;
}
return 0 ;
V_201:
F_38 ( V_189 ) ;
V_197:
F_100 ( V_143 ) ;
V_193:
return - V_98 ;
}
static int F_101 ( struct V_105 * V_106 , int V_202 ,
void T_5 * V_203 , T_2 * V_204 , T_6 * V_205 )
{
struct V_2 * V_2 = V_106 -> V_109 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_206 ;
struct V_105 V_207 = {
. V_208 = V_106 -> V_208 ,
. V_109 = & V_6 ,
. V_209 = sizeof( int ) ,
. V_210 = V_106 -> V_210 ,
. V_211 = & V_212 ,
. V_213 = & V_214 ,
} ;
V_206 = F_102 ( & V_207 , V_202 , V_203 , V_204 , V_205 ) ;
if ( V_202 && V_206 == 0 )
V_206 = F_95 ( V_2 , V_6 ) ;
return V_206 ;
}
static int F_103 ( struct V_2 * V_2 )
{
struct V_105 * V_106 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_106 = F_53 ( V_215 , sizeof( V_215 ) , V_60 ) ;
if ( V_106 == NULL )
return - V_98 ;
V_106 [ 0 ] . V_109 = V_2 ;
V_2 -> V_5 . V_216 = F_55 ( V_2 , L_4 , V_106 ) ;
if ( V_2 -> V_5 . V_216 == NULL )
return - V_98 ;
return 0 ;
}
static void F_104 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_2 V_6 ;
struct V_105 * V_106 ;
unsigned int V_3 ;
V_106 = V_2 -> V_5 . V_216 -> V_114 ;
F_58 ( V_2 -> V_5 . V_216 ) ;
F_56 ( V_106 ) ;
F_97 () ;
V_7 = F_44 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_44 ( V_7 [ V_3 ] ) ;
F_49 ( V_7 [ V_3 ] , NULL ) ;
F_38 ( V_4 ) ;
}
F_98 () ;
F_100 ( V_7 ) ;
}
static int T_7 F_105 ( void )
{
int V_42 ;
F_106 ( sizeof( struct V_15 ) != 4 ) ;
V_42 = F_107 ( & V_217 ) ;
if ( V_42 )
goto V_108;
V_42 = F_108 ( & V_218 ) ;
if ( V_42 )
goto V_219;
F_109 ( & V_220 ) ;
F_110 ( V_221 , V_71 , F_81 , NULL , NULL ) ;
F_110 ( V_221 , V_72 , F_80 , NULL , NULL ) ;
F_110 ( V_221 , V_222 , NULL , F_87 , NULL ) ;
V_42 = 0 ;
V_108:
return V_42 ;
V_219:
F_111 ( & V_217 ) ;
goto V_108;
}
static void T_8 F_112 ( void )
{
F_113 ( V_221 ) ;
F_114 ( & V_220 ) ;
F_115 ( & V_218 ) ;
F_111 ( & V_217 ) ;
}
