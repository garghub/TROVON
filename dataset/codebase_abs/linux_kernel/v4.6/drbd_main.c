struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_1 ;
if ( ! V_3 )
return F_2 ( V_2 , 1 ) ;
V_1 = F_3 ( V_2 , 1 , V_3 ) ;
if ( ! V_1 )
return NULL ;
return V_1 ;
}
int F_4 ( struct V_4 * V_5 , enum V_6 V_7 )
{
int V_8 ;
F_5 ( & V_5 -> V_9 ) ;
V_8 = ( V_5 -> V_10 . V_11 >= V_7 ) ;
if ( ! V_8 ) {
if ( F_6 ( & V_5 -> V_9 ) )
F_7 ( & V_5 -> V_12 ) ;
}
return V_8 ;
}
void F_8 ( struct V_13 * V_14 , unsigned int V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 = NULL ;
int V_20 = 0 ;
int V_21 = 0 ;
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_10 (r, &connection->transfer_log, tl_requests) {
const unsigned V_24 = V_18 -> V_25 ;
if ( ! V_19 ) {
if ( ! ( V_24 & V_26 ) )
continue;
if ( ! ( V_24 & V_27 ) )
continue;
if ( V_24 & V_28 )
continue;
V_19 = V_18 ;
V_20 = V_19 -> V_29 ;
V_21 ++ ;
} else {
if ( V_18 -> V_29 != V_20 )
break;
if ( ! ( V_24 & V_26 ) )
continue;
V_21 ++ ;
}
}
if ( V_19 == NULL ) {
F_11 ( V_14 , L_1 ,
V_15 ) ;
goto V_30;
}
if ( V_20 != V_15 ) {
F_11 ( V_14 , L_2 ,
V_15 , V_20 ) ;
goto V_30;
}
if ( V_21 != V_16 ) {
F_11 ( V_14 , L_3 ,
V_15 , V_16 , V_21 ) ;
goto V_30;
}
F_10 (req, &connection->transfer_log, tl_requests)
if ( V_19 -> V_29 == V_20 )
break;
F_12 (req, r, &connection->transfer_log, tl_requests) {
if ( V_19 -> V_29 != V_20 )
break;
F_13 ( V_19 , V_31 ) ;
}
F_14 ( & V_14 -> V_22 -> V_23 ) ;
return;
V_30:
F_14 ( & V_14 -> V_22 -> V_23 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_33 ) , V_34 ) ;
}
void F_17 ( struct V_13 * V_14 , enum V_35 V_36 )
{
struct V_17 * V_19 , * V_18 ;
F_18 (req, r, &connection->transfer_log, tl_requests)
F_13 ( V_19 , V_36 ) ;
}
void F_19 ( struct V_13 * V_14 , enum V_35 V_36 )
{
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_17 ( V_14 , V_36 ) ;
F_14 ( & V_14 -> V_22 -> V_23 ) ;
}
void F_20 ( struct V_13 * V_14 )
{
F_19 ( V_14 , V_37 ) ;
}
void F_21 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_22 ( V_5 ) -> V_14 ;
struct V_17 * V_19 , * V_18 ;
F_9 ( & V_14 -> V_22 -> V_23 ) ;
F_18 (req, r, &connection->transfer_log, tl_requests) {
if ( ! ( V_19 -> V_25 & V_38 ) )
continue;
if ( V_19 -> V_5 != V_5 )
continue;
F_13 ( V_19 , V_39 ) ;
}
F_14 ( & V_14 -> V_22 -> V_23 ) ;
}
static int F_23 ( void * V_40 )
{
struct V_41 * V_42 = (struct V_41 * ) V_40 ;
struct V_43 * V_22 = V_42 -> V_22 ;
unsigned long V_44 ;
int V_45 ;
snprintf ( V_46 -> V_47 , sizeof( V_46 -> V_47 ) , L_4 ,
V_42 -> V_48 [ 0 ] ,
V_22 -> V_48 ) ;
V_49:
V_45 = V_42 -> V_50 ( V_42 ) ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
if ( V_42 -> V_52 == V_53 ) {
F_25 ( V_22 , L_5 , V_42 -> V_48 ) ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
goto V_49;
}
V_42 -> V_55 = NULL ;
V_42 -> V_52 = V_56 ;
F_27 () ;
F_28 ( & V_42 -> V_57 ) ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_25 ( V_22 , L_6 , V_46 -> V_47 ) ;
if ( V_42 -> V_14 )
F_29 ( & V_42 -> V_14 -> V_58 , V_59 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_30 ( V_61 ) ;
return V_45 ;
}
static void F_31 ( struct V_43 * V_22 , struct V_41 * V_42 ,
int (* F_32) ( struct V_41 * ) , const char * V_48 )
{
F_33 ( & V_42 -> V_51 ) ;
V_42 -> V_55 = NULL ;
V_42 -> V_52 = V_56 ;
V_42 -> V_50 = F_32 ;
V_42 -> V_22 = V_22 ;
V_42 -> V_14 = NULL ;
V_42 -> V_48 = V_48 ;
}
int F_34 ( struct V_41 * V_42 )
{
struct V_43 * V_22 = V_42 -> V_22 ;
struct V_62 * V_63 ;
unsigned long V_44 ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
switch ( V_42 -> V_52 ) {
case V_56 :
F_25 ( V_22 , L_7 ,
V_42 -> V_48 , V_46 -> V_47 , V_46 -> V_64 ) ;
if ( ! F_35 ( V_61 ) ) {
F_11 ( V_22 , L_8 ) ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
return false ;
}
F_36 ( & V_22 -> V_58 ) ;
if ( V_42 -> V_14 )
F_36 ( & V_42 -> V_14 -> V_58 ) ;
F_37 ( & V_42 -> V_57 ) ;
V_42 -> V_65 = 1 ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_38 ( V_46 ) ;
V_63 = F_39 ( F_23 , ( void * ) V_42 ,
L_4 , V_42 -> V_48 [ 0 ] , V_42 -> V_22 -> V_48 ) ;
if ( F_40 ( V_63 ) ) {
F_11 ( V_22 , L_9 ) ;
if ( V_42 -> V_14 )
F_29 ( & V_42 -> V_14 -> V_58 , V_59 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_30 ( V_61 ) ;
return false ;
}
F_24 ( & V_42 -> V_51 , V_44 ) ;
V_42 -> V_55 = V_63 ;
V_42 -> V_52 = V_54 ;
F_26 ( & V_42 -> V_51 , V_44 ) ;
F_41 ( V_63 ) ;
break;
case V_66 :
V_42 -> V_52 = V_53 ;
F_25 ( V_22 , L_10 ,
V_42 -> V_48 , V_46 -> V_47 , V_46 -> V_64 ) ;
case V_54 :
case V_53 :
default:
F_26 ( & V_42 -> V_51 , V_44 ) ;
break;
}
return true ;
}
void F_42 ( struct V_41 * V_42 , int V_49 , int V_67 )
{
unsigned long V_44 ;
enum V_68 V_69 = V_49 ? V_53 : V_66 ;
F_24 ( & V_42 -> V_51 , V_44 ) ;
if ( V_42 -> V_52 == V_56 ) {
F_26 ( & V_42 -> V_51 , V_44 ) ;
if ( V_49 )
F_34 ( V_42 ) ;
return;
}
if ( V_42 -> V_52 != V_69 ) {
if ( V_42 -> V_55 == NULL ) {
F_26 ( & V_42 -> V_51 , V_44 ) ;
return;
}
V_42 -> V_52 = V_69 ;
F_27 () ;
F_37 ( & V_42 -> V_57 ) ;
if ( V_42 -> V_55 != V_46 )
F_43 ( V_70 , V_42 -> V_55 ) ;
}
F_26 ( & V_42 -> V_51 , V_44 ) ;
if ( V_67 )
F_44 ( & V_42 -> V_57 ) ;
}
int F_45 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 = 0 , V_74 = - 1 ;
F_46 () ;
V_72 = F_47 ( & V_14 -> V_75 , & V_73 ) ;
if ( V_72 )
V_74 = F_48 ( V_72 -> V_5 ) ;
F_49 () ;
return V_74 ;
}
static void F_50 ( T_2 * V_76 )
{
unsigned int * V_77 , V_78 = ~ 0 ;
V_77 = F_51 ( V_79 * sizeof( * V_77 ) , V_80 ) ;
if ( V_77 ) {
struct V_43 * V_22 ;
unsigned int V_81 , V_82 = ~ 0 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_53 (cpu, resource->cpu_mask)
V_77 [ V_81 ] ++ ;
}
F_49 () ;
F_54 (cpu) {
if ( V_77 [ V_81 ] < V_82 ) {
V_82 = V_77 [ V_81 ] ;
V_78 = V_81 ;
}
}
F_55 ( V_77 ) ;
}
if ( V_78 == ~ 0 ) {
F_56 ( * V_76 ) ;
return;
}
F_57 ( V_78 , * V_76 ) ;
}
void F_58 ( struct V_41 * V_42 )
{
struct V_43 * V_22 = V_42 -> V_22 ;
struct V_62 * V_83 = V_46 ;
if ( ! V_42 -> V_65 )
return;
V_42 -> V_65 = 0 ;
F_59 ( V_83 , V_22 -> V_76 ) ;
}
unsigned int F_60 ( struct V_13 * V_14 )
{
if ( V_14 -> V_84 >= 100 ) {
F_61 ( ! F_62 ( sizeof( struct V_85 ) , 8 ) ) ;
return sizeof( struct V_85 ) ;
} else {
F_61 ( sizeof( struct V_86 ) !=
sizeof( struct V_87 ) ) ;
F_61 ( ! F_62 ( sizeof( struct V_86 ) , 8 ) ) ;
return sizeof( struct V_86 ) ;
}
}
static unsigned int F_63 ( struct V_86 * V_88 , enum V_89 V_90 , int V_91 )
{
V_88 -> V_92 = F_64 ( V_93 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_65 ( V_91 ) ;
return sizeof( struct V_86 ) ;
}
static unsigned int F_66 ( struct V_87 * V_88 , enum V_89 V_90 , int V_91 )
{
V_88 -> V_92 = F_65 ( V_96 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_64 ( V_91 ) ;
return sizeof( struct V_87 ) ;
}
static unsigned int F_67 ( struct V_85 * V_88 , enum V_89 V_90 ,
int V_91 , int V_73 )
{
V_88 -> V_92 = F_64 ( V_97 ) ;
V_88 -> V_98 = F_65 ( V_73 ) ;
V_88 -> V_94 = F_65 ( V_90 ) ;
V_88 -> V_95 = F_64 ( V_91 ) ;
V_88 -> V_99 = 0 ;
return sizeof( struct V_85 ) ;
}
static unsigned int F_68 ( struct V_13 * V_14 , int V_73 ,
void * V_100 , enum V_89 V_90 , int V_91 )
{
if ( V_14 -> V_84 >= 100 )
return F_67 ( V_100 , V_90 , V_91 , V_73 ) ;
else if ( V_14 -> V_84 >= 95 &&
V_91 > V_101 )
return F_66 ( V_100 , V_90 , V_91 ) ;
else
return F_63 ( V_100 , V_90 , V_91 ) ;
}
static void * F_69 ( struct V_13 * V_14 ,
struct V_102 * V_103 )
{
if ( ! V_103 -> V_104 )
return NULL ;
return V_103 -> V_105 + F_60 ( V_14 ) ;
}
void * F_70 ( struct V_13 * V_14 , struct V_102 * V_103 )
{
void * V_83 ;
F_71 ( & V_103 -> V_106 ) ;
V_83 = F_69 ( V_14 , V_103 ) ;
if ( ! V_83 )
F_72 ( & V_103 -> V_106 ) ;
return V_83 ;
}
void * F_73 ( struct V_71 * V_72 , struct V_102 * V_103 )
{
return F_70 ( V_72 -> V_14 , V_103 ) ;
}
static int F_74 ( struct V_13 * V_14 , int V_73 ,
struct V_102 * V_103 , enum V_89 V_90 ,
unsigned int V_107 , void * V_108 ,
unsigned int V_91 )
{
int V_109 ;
int V_110 ;
V_109 = V_108 ? V_111 : 0 ;
V_107 += F_68 ( V_14 , V_73 , V_103 -> V_105 , V_90 ,
V_107 + V_91 ) ;
V_110 = F_75 ( V_14 , V_103 -> V_104 , V_103 -> V_105 , V_107 ,
V_109 ) ;
if ( V_108 && ! V_110 )
V_110 = F_75 ( V_14 , V_103 -> V_104 , V_108 , V_91 , 0 ) ;
if ( ! V_110 && ( V_90 == V_112 || V_90 == V_113 ) )
F_76 ( V_103 -> V_104 ) ;
return V_110 ;
}
static int F_77 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
return F_74 ( V_14 , 0 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
}
int F_78 ( struct V_13 * V_14 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_77 ( V_14 , V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_79 ( struct V_71 * V_72 , struct V_102 * V_103 ,
enum V_89 V_90 , unsigned int V_107 ,
void * V_108 , unsigned int V_91 )
{
int V_110 ;
V_110 = F_74 ( V_72 -> V_14 , V_72 -> V_5 -> V_73 ,
V_103 , V_90 , V_107 , V_108 , V_91 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_80 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_114 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_115 ;
return F_78 ( V_14 , V_103 , V_112 , 0 , NULL , 0 ) ;
}
int F_81 ( struct V_13 * V_14 )
{
struct V_102 * V_103 ;
V_103 = & V_14 -> V_114 ;
if ( ! F_70 ( V_14 , V_103 ) )
return - V_115 ;
return F_78 ( V_14 , V_103 , V_113 , 0 , NULL , 0 ) ;
}
int F_82 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_116 * V_83 ;
int V_91 ;
const int V_117 = V_72 -> V_14 -> V_84 ;
enum V_89 V_90 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
F_46 () ;
V_119 = F_83 ( V_72 -> V_14 -> V_118 ) ;
V_91 = V_117 <= 87 ? sizeof( struct V_122 )
: V_117 == 88 ? sizeof( struct V_122 )
+ strlen ( V_119 -> V_123 ) + 1
: V_117 <= 94 ? sizeof( struct V_124 )
: sizeof( struct V_116 ) ;
V_90 = V_117 >= 89 ? V_125 : V_126 ;
memset ( V_83 -> V_123 , 0 , 2 * V_127 ) ;
if ( F_84 ( V_72 -> V_5 ) ) {
V_121 = F_83 ( V_72 -> V_5 -> V_128 -> V_120 ) ;
V_83 -> V_129 = F_64 ( V_121 -> V_129 ) ;
V_83 -> V_130 = F_64 ( V_121 -> V_130 ) ;
V_83 -> V_131 = F_64 ( V_121 -> V_131 ) ;
V_83 -> V_132 = F_64 ( V_121 -> V_132 ) ;
V_83 -> V_133 = F_64 ( V_121 -> V_133 ) ;
F_85 ( V_72 -> V_5 ) ;
} else {
V_83 -> V_129 = F_64 ( V_134 ) ;
V_83 -> V_130 = F_64 ( V_135 ) ;
V_83 -> V_131 = F_64 ( V_136 ) ;
V_83 -> V_132 = F_64 ( V_137 ) ;
V_83 -> V_133 = F_64 ( V_138 ) ;
}
if ( V_117 >= 88 )
strcpy ( V_83 -> V_123 , V_119 -> V_123 ) ;
if ( V_117 >= 89 )
strcpy ( V_83 -> V_139 , V_119 -> V_139 ) ;
F_49 () ;
return F_79 ( V_72 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_86 ( struct V_13 * V_14 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_140 * V_83 ;
struct V_118 * V_119 ;
int V_91 , V_141 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_69 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
F_46 () ;
V_119 = F_83 ( V_14 -> V_118 ) ;
if ( V_119 -> V_142 && V_14 -> V_84 < 92 ) {
F_49 () ;
F_72 ( & V_103 -> V_106 ) ;
F_11 ( V_14 , L_11 ) ;
return - V_143 ;
}
V_91 = sizeof( * V_83 ) ;
if ( V_14 -> V_84 >= 87 )
V_91 += strlen ( V_119 -> V_144 ) + 1 ;
V_83 -> V_145 = F_64 ( V_119 -> V_146 ) ;
V_83 -> V_147 = F_64 ( V_119 -> V_147 ) ;
V_83 -> V_148 = F_64 ( V_119 -> V_148 ) ;
V_83 -> V_149 = F_64 ( V_119 -> V_149 ) ;
V_83 -> V_150 = F_64 ( V_119 -> V_150 ) ;
V_141 = 0 ;
if ( V_119 -> V_151 )
V_141 |= V_152 ;
if ( V_119 -> V_142 )
V_141 |= V_153 ;
V_83 -> V_154 = F_64 ( V_141 ) ;
if ( V_14 -> V_84 >= 87 )
strcpy ( V_83 -> V_144 , V_119 -> V_144 ) ;
F_49 () ;
return F_77 ( V_14 , V_103 , V_90 , V_91 , NULL , 0 ) ;
}
int F_87 ( struct V_13 * V_14 )
{
int V_110 ;
F_71 ( & V_14 -> V_108 . V_106 ) ;
V_110 = F_86 ( V_14 , V_155 ) ;
F_72 ( & V_14 -> V_108 . V_106 ) ;
return V_110 ;
}
static int F_88 ( struct V_71 * V_72 , T_3 V_156 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_157 * V_83 ;
int V_158 ;
if ( ! F_89 ( V_5 , V_159 ) )
return 0 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 ) {
F_85 ( V_5 ) ;
return - V_115 ;
}
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_83 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_5 -> V_165 = F_91 ( V_5 ) ;
V_83 -> V_164 [ V_163 ] = F_90 ( V_5 -> V_165 ) ;
F_46 () ;
V_156 |= F_83 ( V_72 -> V_14 -> V_118 ) -> V_151 ? 1 : 0 ;
F_49 () ;
V_156 |= F_92 ( V_166 , & V_5 -> V_44 ) ? 2 : 0 ;
V_156 |= V_5 -> V_167 . V_11 == V_168 ? 4 : 0 ;
V_83 -> V_164 [ V_169 ] = F_90 ( V_156 ) ;
F_85 ( V_5 ) ;
return F_79 ( V_72 , V_103 , V_170 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_93 ( struct V_71 * V_72 )
{
return F_88 ( V_72 , 0 ) ;
}
int F_94 ( struct V_71 * V_72 )
{
return F_88 ( V_72 , 8 ) ;
}
void F_95 ( struct V_4 * V_5 , const char * V_171 )
{
if ( F_89 ( V_5 , V_159 ) ) {
T_3 * V_164 = V_5 -> V_128 -> V_160 . V_164 ;
F_25 ( V_5 , L_12 ,
V_171 ,
( unsigned long long ) V_164 [ V_162 ] ,
( unsigned long long ) V_164 [ V_172 ] ,
( unsigned long long ) V_164 [ V_173 ] ,
( unsigned long long ) V_164 [ V_174 ] ) ;
F_85 ( V_5 ) ;
} else {
F_25 ( V_5 , L_13 ,
V_171 ,
( unsigned long long ) V_5 -> V_175 ) ;
}
}
void F_96 ( struct V_71 * V_72 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_176 * V_83 ;
T_3 V_164 ;
F_97 ( V_5 , V_5 -> V_10 . V_11 == V_177 ) ;
V_164 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_164 && V_164 != V_178 )
V_164 = V_164 + V_179 ;
else
F_98 ( & V_164 , sizeof( T_3 ) ) ;
F_99 ( V_5 , V_172 , V_164 ) ;
F_95 ( V_5 , L_14 ) ;
F_100 ( V_5 ) ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_164 = F_90 ( V_164 ) ;
F_79 ( V_72 , V_103 , V_180 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
int F_101 ( struct V_71 * V_72 , int V_181 , enum V_182 V_44 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_183 * V_83 ;
T_4 V_184 , V_185 ;
int V_186 ;
unsigned int V_187 ;
if ( F_89 ( V_5 , V_159 ) ) {
F_97 ( V_5 , V_5 -> V_128 -> V_188 ) ;
V_184 = F_102 ( V_5 -> V_128 ) ;
F_46 () ;
V_185 = F_83 ( V_5 -> V_128 -> V_120 ) -> V_189 ;
F_49 () ;
V_186 = F_103 ( V_5 ) ;
V_187 = F_104 ( V_5 -> V_128 -> V_188 -> V_190 -> V_191 ) << 9 ;
V_187 = V_82 ( V_187 , V_192 ) ;
F_85 ( V_5 ) ;
} else {
V_184 = 0 ;
V_185 = 0 ;
V_186 = V_193 ;
V_187 = V_192 ;
}
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
if ( V_72 -> V_14 -> V_84 <= 94 )
V_187 = V_82 ( V_187 , V_101 ) ;
else if ( V_72 -> V_14 -> V_84 < 100 )
V_187 = V_82 ( V_187 , V_194 ) ;
V_83 -> V_184 = F_90 ( V_184 ) ;
V_83 -> V_185 = F_90 ( V_185 ) ;
V_83 -> V_195 = F_90 ( V_181 ? 0 : F_105 ( V_5 -> V_196 ) ) ;
V_83 -> V_187 = F_64 ( V_187 ) ;
V_83 -> V_197 = F_65 ( V_186 ) ;
V_83 -> V_182 = F_65 ( V_44 ) ;
return F_79 ( V_72 , V_103 , V_198 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_106 ( struct V_71 * V_72 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_72 -> V_5 -> V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_107 ( struct V_71 * V_72 , union V_201 V_10 )
{
struct V_102 * V_103 ;
struct V_199 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_10 = F_64 ( V_10 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_200 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_108 ( struct V_71 * V_72 , union V_201 V_202 , union V_201 V_203 )
{
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_79 ( V_72 , V_103 , V_205 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_109 ( struct V_13 * V_14 , union V_201 V_202 , union V_201 V_203 )
{
enum V_89 V_90 ;
struct V_102 * V_103 ;
struct V_204 * V_83 ;
V_90 = V_14 -> V_84 < 100 ? V_205 : V_206 ;
V_103 = & V_14 -> V_108 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_202 = F_64 ( V_202 . V_158 ) ;
V_83 -> V_203 = F_64 ( V_203 . V_158 ) ;
return F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_110 ( struct V_71 * V_72 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_79 ( V_72 , V_103 , V_210 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
void F_111 ( struct V_13 * V_14 , enum V_207 V_208 )
{
struct V_102 * V_103 ;
struct V_209 * V_83 ;
enum V_89 V_90 = V_14 -> V_84 < 100 ? V_210 : V_211 ;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( V_83 ) {
V_83 -> V_208 = F_64 ( V_208 ) ;
F_78 ( V_14 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
}
static void F_112 ( struct V_212 * V_83 , enum V_213 V_214 )
{
F_113 ( V_214 & ~ 0xf ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0xf ) | V_214 ;
}
static void F_114 ( struct V_212 * V_83 , int V_216 )
{
V_83 -> V_215 = ( V_83 -> V_215 & ~ 0x80 ) | ( V_216 ? 0x80 : 0 ) ;
}
static void F_115 ( struct V_212 * V_83 , int V_217 )
{
F_113 ( V_217 & ~ 0x7 ) ;
V_83 -> V_215 = ( V_83 -> V_215 & ( ~ 0x7 << 4 ) ) | ( V_217 << 4 ) ;
}
static int F_116 ( struct V_4 * V_5 ,
struct V_212 * V_83 ,
unsigned int V_91 ,
struct V_218 * V_219 )
{
struct V_220 V_221 ;
unsigned long V_222 ;
unsigned long V_223 ;
unsigned long V_224 ;
unsigned V_225 ;
unsigned V_226 ;
int V_227 , V_228 ;
F_46 () ;
V_228 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) -> V_228 ;
F_49 () ;
if ( ! V_228 || F_22 ( V_5 ) -> V_14 -> V_84 < 90 )
return 0 ;
if ( V_219 -> V_229 >= V_219 -> V_230 )
return 0 ;
F_117 ( & V_221 , V_83 -> V_214 , V_91 , 0 ) ;
memset ( V_83 -> V_214 , 0 , V_91 ) ;
V_222 = 0 ;
V_226 = 2 ;
do {
V_223 = ( V_226 == 0 ) ? F_118 ( V_5 , V_219 -> V_229 )
: F_119 ( V_5 , V_219 -> V_229 ) ;
if ( V_223 == - 1UL )
V_223 = V_219 -> V_230 ;
V_224 = V_223 - V_219 -> V_229 ;
if ( V_226 == 2 ) {
if ( V_224 == 0 ) {
F_114 ( V_83 , 1 ) ;
V_226 = ! V_226 ;
continue;
}
F_114 ( V_83 , 0 ) ;
}
if ( V_224 == 0 ) {
F_11 ( V_5 , L_15
L_16 , V_226 , V_219 -> V_229 ) ;
return - 1 ;
}
V_227 = F_120 ( & V_221 , V_224 ) ;
if ( V_227 == - V_231 )
break;
if ( V_227 <= 0 ) {
F_11 ( V_5 , L_17 , V_227 ) ;
return 0 ;
}
V_226 = ! V_226 ;
V_222 += V_224 ;
V_219 -> V_229 = V_223 ;
} while ( V_219 -> V_229 < V_219 -> V_230 );
V_225 = V_221 . V_232 . V_233 - V_83 -> V_214 + ! ! V_221 . V_232 . V_234 ;
if ( V_222 < ( V_225 << 3 ) ) {
V_219 -> V_229 -= V_222 ;
F_121 ( V_219 ) ;
V_219 -> V_229 = V_219 -> V_235 * V_236 ;
return 0 ;
}
F_121 ( V_219 ) ;
F_115 ( V_83 , ( 8 - V_221 . V_232 . V_234 ) & 0x7 ) ;
return V_225 ;
}
static int
F_122 ( struct V_4 * V_5 , struct V_218 * V_219 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
unsigned int V_107 = F_60 ( F_22 ( V_5 ) -> V_14 ) ;
struct V_212 * V_83 = V_103 -> V_105 + V_107 ;
int V_225 , V_110 ;
V_225 = F_116 ( V_5 , V_83 ,
V_237 - V_107 - sizeof( * V_83 ) , V_219 ) ;
if ( V_225 < 0 )
return - V_115 ;
if ( V_225 ) {
F_112 ( V_83 , V_238 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 ,
V_239 , sizeof( * V_83 ) + V_225 ,
NULL , 0 ) ;
V_219 -> V_240 [ 0 ] ++ ;
V_219 -> V_241 [ 0 ] += V_107 + sizeof( * V_83 ) + V_225 ;
if ( V_219 -> V_229 >= V_219 -> V_230 )
V_225 = 0 ;
} else {
unsigned int V_242 ;
unsigned long V_243 ;
unsigned long * V_83 = V_103 -> V_105 + V_107 ;
V_242 = V_237 - V_107 ;
V_243 = F_123 ( V_244 , V_242 / sizeof( * V_83 ) ,
V_219 -> V_245 - V_219 -> V_235 ) ;
V_225 = V_243 * sizeof( * V_83 ) ;
if ( V_225 )
F_124 ( V_5 , V_219 -> V_235 , V_243 , V_83 ) ;
V_110 = F_74 ( F_22 ( V_5 ) -> V_14 , V_5 -> V_73 , V_103 , V_246 , V_225 , NULL , 0 ) ;
V_219 -> V_235 += V_243 ;
V_219 -> V_229 = V_219 -> V_235 * V_236 ;
V_219 -> V_240 [ 1 ] ++ ;
V_219 -> V_241 [ 1 ] += V_107 + V_225 ;
if ( V_219 -> V_229 > V_219 -> V_230 )
V_219 -> V_229 = V_219 -> V_230 ;
}
if ( ! V_110 ) {
if ( V_225 == 0 ) {
F_125 ( V_5 , L_18 , V_219 ) ;
return 0 ;
} else
return 1 ;
}
return - V_115 ;
}
static int F_126 ( struct V_4 * V_5 )
{
struct V_218 V_219 ;
int V_110 ;
if ( ! F_127 ( V_5 -> V_247 ) )
return false ;
if ( F_84 ( V_5 ) ) {
if ( F_128 ( V_5 -> V_128 , V_248 ) ) {
F_25 ( V_5 , L_19 ) ;
F_129 ( V_5 ) ;
if ( F_130 ( V_5 ) ) {
F_11 ( V_5 , L_20 ) ;
} else {
F_131 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
}
}
F_85 ( V_5 ) ;
}
V_219 = (struct V_218 ) {
. V_230 = F_132 ( V_5 ) ,
. V_245 = F_133 ( V_5 ) ,
} ;
do {
V_110 = F_122 ( V_5 , & V_219 ) ;
} while ( V_110 > 0 );
return V_110 == 0 ;
}
int F_134 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = & F_22 ( V_5 ) -> V_14 -> V_108 ;
int V_110 = - 1 ;
F_71 ( & V_103 -> V_106 ) ;
if ( V_103 -> V_104 )
V_110 = ! F_126 ( V_5 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
void F_135 ( struct V_13 * V_14 , T_5 V_15 , T_5 V_16 )
{
struct V_102 * V_103 ;
struct V_249 * V_83 ;
if ( V_14 -> V_250 < V_251 )
return;
V_103 = & V_14 -> V_114 ;
V_83 = F_70 ( V_14 , V_103 ) ;
if ( ! V_83 )
return;
V_83 -> V_252 = V_15 ;
V_83 -> V_16 = F_64 ( V_16 ) ;
F_78 ( V_14 , V_103 , V_253 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_136 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_3 V_254 , T_5 V_255 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_257 * V_83 ;
if ( V_72 -> V_5 -> V_10 . V_32 < V_258 )
return - V_115 ;
V_103 = & V_72 -> V_14 -> V_114 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = V_254 ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = V_255 ;
V_83 -> V_259 = F_64 ( F_137 ( & V_72 -> V_5 -> V_260 ) ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
void F_138 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_261 * V_262 , int V_242 )
{
if ( V_72 -> V_14 -> V_263 )
V_242 -= F_139 ( V_72 -> V_14 -> V_263 ) ;
F_136 ( V_72 , V_90 , V_262 -> V_254 , F_64 ( V_242 ) ,
V_262 -> V_256 ) ;
}
void F_140 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_264 * V_265 )
{
F_136 ( V_72 , V_90 , V_265 -> V_254 , V_265 -> V_255 , V_265 -> V_256 ) ;
}
int F_141 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_266 * V_267 )
{
return F_136 ( V_72 , V_90 ,
F_90 ( V_267 -> V_158 . V_254 ) ,
F_64 ( V_267 -> V_158 . V_91 ) ,
V_267 -> V_256 ) ;
}
int F_142 ( struct V_71 * V_72 , enum V_89 V_90 ,
T_4 V_254 , int V_255 , T_3 V_256 )
{
return F_136 ( V_72 , V_90 ,
F_90 ( V_254 ) ,
F_64 ( V_255 ) ,
F_90 ( V_256 ) ) ;
}
int F_143 ( struct V_71 * V_72 , int V_90 ,
T_4 V_254 , int V_91 , T_3 V_256 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_256 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_144 ( struct V_71 * V_72 , T_4 V_254 , int V_91 ,
void * V_268 , int V_269 , enum V_89 V_90 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_90 , sizeof( * V_83 ) , V_268 , V_269 ) ;
}
int F_145 ( struct V_71 * V_72 , T_4 V_254 , int V_91 )
{
struct V_102 * V_103 ;
struct V_264 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_254 ) ;
V_83 -> V_256 = V_270 ;
V_83 -> V_255 = F_64 ( V_91 ) ;
return F_79 ( V_72 , V_103 , V_271 , sizeof( * V_83 ) , NULL , 0 ) ;
}
static int F_146 ( struct V_13 * V_14 , struct V_104 * V_103 )
{
int V_272 ;
V_272 = V_14 -> V_114 . V_104 == V_103
|| ! V_14 -> V_273 . V_55
|| F_147 ( & V_14 -> V_273 ) != V_54
|| V_14 -> V_250 < V_251 ;
if ( V_272 )
return true ;
V_272 = ! -- V_14 -> V_274 ;
if ( ! V_272 ) {
F_11 ( V_14 , L_21 ,
V_46 -> V_47 , V_46 -> V_64 , V_14 -> V_274 ) ;
F_148 ( V_14 ) ;
}
return V_272 ; ;
}
static void F_149 ( struct V_13 * V_14 )
{
struct V_103 * V_275 = V_14 -> V_108 . V_104 -> V_275 ;
if ( V_275 -> V_276 > V_275 -> V_277 * 4 / 5 )
F_150 ( V_278 , & V_14 -> V_44 ) ;
}
static int F_151 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 ;
void * V_281 ;
int V_110 ;
V_104 = V_72 -> V_14 -> V_108 . V_104 ;
V_281 = F_152 ( V_279 ) + V_280 ;
V_110 = F_75 ( V_72 -> V_14 , V_104 , V_281 , V_91 , V_109 ) ;
F_153 ( V_279 ) ;
if ( ! V_110 )
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
return V_110 ;
}
static int F_154 ( struct V_71 * V_72 , struct V_279 * V_279 ,
int V_280 , V_244 V_91 , unsigned V_109 )
{
struct V_104 * V_104 = V_72 -> V_14 -> V_108 . V_104 ;
T_6 V_283 = F_155 () ;
int V_225 = V_91 ;
int V_110 = - V_115 ;
if ( V_284 || ( F_156 ( V_279 ) < 1 ) || F_157 ( V_279 ) )
return F_151 ( V_72 , V_279 , V_280 , V_91 , V_109 ) ;
V_109 |= V_285 ;
F_149 ( V_72 -> V_14 ) ;
F_158 ( V_286 ) ;
do {
int V_287 ;
V_287 = V_104 -> V_288 -> V_289 ( V_104 , V_279 , V_280 , V_225 , V_109 ) ;
if ( V_287 <= 0 ) {
if ( V_287 == - V_290 ) {
if ( F_146 ( V_72 -> V_14 , V_104 ) )
break;
continue;
}
F_159 ( V_72 -> V_5 , L_22 ,
V_291 , ( int ) V_91 , V_225 , V_287 ) ;
if ( V_287 < 0 )
V_110 = V_287 ;
break;
}
V_225 -= V_287 ;
V_280 += V_287 ;
} while ( V_225 > 0 );
F_158 ( V_283 ) ;
F_160 ( V_278 , & V_72 -> V_14 -> V_44 ) ;
if ( V_225 == 0 ) {
V_110 = 0 ;
V_72 -> V_5 -> V_282 += V_91 >> 9 ;
}
return V_110 ;
}
static int F_161 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_162 (bvec, bio, iter) {
int V_110 ;
V_110 = F_151 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_163 ( V_293 , V_295 )
? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_164 ( struct V_71 * V_72 , struct V_1 * V_1 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
F_162 (bvec, bio, iter) {
int V_110 ;
V_110 = F_154 ( V_72 , V_293 . V_296 ,
V_293 . V_297 , V_293 . V_298 ,
F_163 ( V_293 , V_295 ) ? 0 : V_111 ) ;
if ( V_110 )
return V_110 ;
}
return 0 ;
}
static int F_165 ( struct V_71 * V_72 ,
struct V_266 * V_267 )
{
struct V_279 * V_279 = V_267 -> V_299 ;
unsigned V_225 = V_267 -> V_158 . V_91 ;
int V_110 ;
F_166 (page) {
unsigned V_300 = F_123 ( unsigned , V_225 , V_301 ) ;
V_110 = F_154 ( V_72 , V_279 , 0 , V_300 ,
F_167 ( V_279 ) ? V_111 : 0 ) ;
if ( V_110 )
return V_110 ;
V_225 -= V_300 ;
}
return 0 ;
}
static T_5 F_168 ( struct V_13 * V_14 , unsigned long V_302 )
{
if ( V_14 -> V_84 >= 95 )
return ( V_302 & V_303 ? V_304 : 0 ) |
( V_302 & V_305 ? V_306 : 0 ) |
( V_302 & V_307 ? V_308 : 0 ) |
( V_302 & V_309 ? V_310 : 0 ) ;
else
return V_302 & V_303 ? V_304 : 0 ;
}
int F_169 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_261 * V_83 ;
unsigned int V_311 = 0 ;
int V_269 ;
int V_110 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_269 = V_72 -> V_14 -> V_312 ?
F_139 ( V_72 -> V_14 -> V_312 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_256 = ( unsigned long ) V_19 ;
V_83 -> V_259 = F_64 ( F_137 ( & V_5 -> V_260 ) ) ;
V_311 = F_168 ( V_72 -> V_14 , V_19 -> V_313 -> V_302 ) ;
if ( V_5 -> V_10 . V_32 >= V_314 &&
V_5 -> V_10 . V_32 <= V_315 )
V_311 |= V_316 ;
if ( V_72 -> V_14 -> V_84 >= 100 ) {
if ( V_19 -> V_25 & V_317 )
V_311 |= V_318 ;
if ( V_19 -> V_25 & V_319
|| ( V_311 & V_316 ) )
V_311 |= V_320 ;
}
V_83 -> V_311 = F_64 ( V_311 ) ;
if ( V_311 & V_310 ) {
struct V_321 * V_322 = (struct V_321 * ) V_83 ;
V_322 -> V_91 = F_64 ( V_19 -> V_158 . V_91 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_323 , sizeof( * V_322 ) , NULL , 0 ) ;
goto V_324;
}
if ( V_269 )
F_170 ( V_72 -> V_14 -> V_312 , V_19 -> V_313 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_325 , sizeof( * V_83 ) + V_269 , NULL , V_19 -> V_158 . V_91 ) ;
if ( ! V_110 ) {
if ( ! ( V_19 -> V_25 & ( V_317 | V_319 ) ) || V_269 )
V_110 = F_161 ( V_72 , V_19 -> V_313 ) ;
else
V_110 = F_164 ( V_72 , V_19 -> V_313 ) ;
if ( V_269 > 0 && V_269 <= 64 ) {
unsigned char V_268 [ 64 ] ;
F_170 ( V_72 -> V_14 -> V_312 , V_19 -> V_313 , V_268 ) ;
if ( memcmp ( V_83 + 1 , V_268 , V_269 ) ) {
F_159 ( V_5 ,
L_23 ,
( unsigned long long ) V_19 -> V_158 . V_254 , V_19 -> V_158 . V_91 ) ;
}
}
}
V_324:
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_171 ( struct V_71 * V_72 , enum V_89 V_90 ,
struct V_266 * V_267 )
{
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_102 * V_103 ;
struct V_261 * V_83 ;
int V_110 ;
int V_269 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
V_269 = V_72 -> V_14 -> V_312 ?
F_139 ( V_72 -> V_14 -> V_312 ) : 0 ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_267 -> V_158 . V_254 ) ;
V_83 -> V_256 = V_267 -> V_256 ;
V_83 -> V_259 = 0 ;
V_83 -> V_311 = 0 ;
if ( V_269 )
F_172 ( V_72 -> V_14 -> V_312 , V_267 , V_83 + 1 ) ;
V_110 = F_74 ( V_72 -> V_14 , V_5 -> V_73 , V_103 , V_90 , sizeof( * V_83 ) + V_269 , NULL , V_267 -> V_158 . V_91 ) ;
if ( ! V_110 )
V_110 = F_165 ( V_72 , V_267 ) ;
F_72 ( & V_103 -> V_106 ) ;
return V_110 ;
}
int F_173 ( struct V_71 * V_72 , struct V_17 * V_19 )
{
struct V_102 * V_103 ;
struct V_326 * V_83 ;
V_103 = & V_72 -> V_14 -> V_108 ;
V_83 = F_73 ( V_72 , V_103 ) ;
if ( ! V_83 )
return - V_115 ;
V_83 -> V_254 = F_90 ( V_19 -> V_158 . V_254 ) ;
V_83 -> V_255 = F_64 ( V_19 -> V_158 . V_91 ) ;
return F_79 ( V_72 , V_103 , V_327 , sizeof( * V_83 ) , NULL , 0 ) ;
}
int F_174 ( struct V_13 * V_14 , struct V_104 * V_103 ,
void * V_328 , V_244 V_91 , unsigned V_109 )
{
struct V_329 V_330 ;
struct V_331 V_332 ;
int V_333 , V_287 = 0 ;
if ( ! V_103 )
return - V_334 ;
V_330 . V_335 = V_328 ;
V_330 . V_336 = V_91 ;
V_332 . V_337 = NULL ;
V_332 . V_338 = 0 ;
V_332 . V_339 = NULL ;
V_332 . V_340 = 0 ;
V_332 . V_109 = V_109 | V_285 ;
if ( V_103 == V_14 -> V_108 . V_104 ) {
F_46 () ;
V_14 -> V_274 = F_83 ( V_14 -> V_118 ) -> V_274 ;
F_49 () ;
F_149 ( V_14 ) ;
}
do {
V_333 = F_175 ( V_103 , & V_332 , & V_330 , 1 , V_91 ) ;
if ( V_333 == - V_290 ) {
if ( F_146 ( V_14 , V_103 ) )
break;
else
continue;
}
if ( V_333 == - V_341 ) {
F_38 ( V_46 ) ;
V_333 = 0 ;
}
if ( V_333 < 0 )
break;
V_287 += V_333 ;
V_330 . V_335 += V_333 ;
V_330 . V_336 -= V_333 ;
} while ( V_287 < V_91 );
if ( V_103 == V_14 -> V_108 . V_104 )
F_160 ( V_278 , & V_14 -> V_44 ) ;
if ( V_333 <= 0 ) {
if ( V_333 != - V_290 ) {
F_11 ( V_14 , L_24 ,
V_103 == V_14 -> V_114 . V_104 ? L_25 : L_26 ,
V_333 ) ;
F_15 ( V_14 , F_16 ( V_32 , V_342 ) , V_34 ) ;
} else
F_15 ( V_14 , F_16 ( V_32 , V_343 ) , V_34 ) ;
}
return V_287 ;
}
int F_75 ( struct V_13 * V_14 , struct V_104 * V_103 , void * V_100 ,
V_244 V_91 , unsigned V_109 )
{
int V_110 ;
V_110 = F_174 ( V_14 , V_103 , V_100 , V_91 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
if ( V_110 != V_91 )
return - V_115 ;
return 0 ;
}
static int F_176 ( struct V_344 * V_345 , T_7 V_346 )
{
struct V_4 * V_5 = V_345 -> V_190 -> V_347 ;
unsigned long V_44 ;
int V_333 = 0 ;
F_71 ( & V_348 ) ;
F_24 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
if ( V_5 -> V_10 . V_349 != V_350 ) {
if ( V_346 & V_351 )
V_333 = - V_352 ;
else if ( ! V_353 )
V_333 = - V_354 ;
}
if ( ! V_333 )
V_5 -> V_355 ++ ;
F_26 ( & V_5 -> V_22 -> V_23 , V_44 ) ;
F_72 ( & V_348 ) ;
return V_333 ;
}
static void F_177 ( struct V_356 * V_357 , T_7 V_346 )
{
struct V_4 * V_5 = V_357 -> V_347 ;
F_71 ( & V_348 ) ;
V_5 -> V_355 -- ;
F_72 ( & V_348 ) ;
}
static void F_178 ( struct V_4 * V_5 )
{
V_5 -> V_10 = (union V_358 ) {
{ . V_349 = V_359 ,
. V_360 = V_361 ,
. V_32 = V_362 ,
. V_11 = V_363 ,
. V_364 = V_365 ,
} } ;
}
void F_179 ( struct V_4 * V_5 )
{
F_178 ( V_5 ) ;
F_180 ( & V_5 -> V_366 , 0 ) ;
F_180 ( & V_5 -> V_367 , 0 ) ;
F_180 ( & V_5 -> V_368 , 0 ) ;
F_180 ( & V_5 -> V_369 , 0 ) ;
F_180 ( & V_5 -> V_370 , 0 ) ;
F_180 ( & V_5 -> V_9 , 0 ) ;
F_180 ( & V_5 -> V_371 , 0 ) ;
F_180 ( & V_5 -> V_372 , 0 ) ;
F_180 ( & V_5 -> V_373 , 0 ) ;
F_180 ( & V_5 -> V_374 , 0 ) ;
F_180 ( & V_5 -> V_375 . V_376 , 0 ) ;
F_181 ( & V_5 -> V_377 ) ;
V_5 -> V_378 = & V_5 -> V_377 ;
F_33 ( & V_5 -> V_379 ) ;
F_33 ( & V_5 -> V_380 ) ;
F_182 ( & V_5 -> V_381 ) ;
F_182 ( & V_5 -> V_382 ) ;
F_182 ( & V_5 -> V_383 ) ;
F_182 ( & V_5 -> V_384 ) ;
F_182 ( & V_5 -> V_385 ) ;
F_182 ( & V_5 -> V_386 ) ;
F_182 ( & V_5 -> V_387 . V_388 ) ;
F_182 ( & V_5 -> V_389 . V_388 ) ;
F_182 ( & V_5 -> V_390 . V_391 . V_388 ) ;
F_182 ( & V_5 -> V_392 [ 0 ] ) ;
F_182 ( & V_5 -> V_392 [ 1 ] ) ;
F_182 ( & V_5 -> V_393 [ 0 ] ) ;
F_182 ( & V_5 -> V_393 [ 1 ] ) ;
V_5 -> V_387 . V_394 = V_395 ;
V_5 -> V_389 . V_394 = V_396 ;
V_5 -> V_390 . V_391 . V_394 = V_397 ;
F_183 ( & V_5 -> V_398 ) ;
F_183 ( & V_5 -> V_399 ) ;
F_183 ( & V_5 -> V_400 ) ;
F_183 ( & V_5 -> V_401 ) ;
V_5 -> V_398 . V_50 = V_402 ;
V_5 -> V_398 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_399 . V_50 = V_403 ;
V_5 -> V_399 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_400 . V_50 = V_404 ;
V_5 -> V_400 . V_108 = ( unsigned long ) V_5 ;
V_5 -> V_401 . V_50 = V_405 ;
V_5 -> V_401 . V_108 = ( unsigned long ) V_5 ;
F_184 ( & V_5 -> V_12 ) ;
F_184 ( & V_5 -> V_406 ) ;
F_184 ( & V_5 -> V_407 ) ;
F_184 ( & V_5 -> V_408 ) ;
F_184 ( & V_5 -> V_409 ) ;
V_5 -> V_410 = V_411 ;
V_5 -> V_412 = V_413 ;
V_5 -> V_414 = V_413 ;
}
void F_185 ( struct V_4 * V_5 )
{
int V_158 ;
if ( F_22 ( V_5 ) -> V_14 -> V_415 . V_52 != V_56 )
F_11 ( V_5 , L_27 ,
F_22 ( V_5 ) -> V_14 -> V_415 . V_52 ) ;
V_5 -> V_416 =
V_5 -> V_417 =
V_5 -> V_418 =
V_5 -> V_419 =
V_5 -> V_282 =
V_5 -> V_420 =
V_5 -> V_421 =
V_5 -> V_422 =
V_5 -> V_423 =
V_5 -> V_424 = 0 ;
V_5 -> V_425 = 0 ;
V_5 -> V_426 = 0 ;
for ( V_158 = 0 ; V_158 < V_427 ; V_158 ++ ) {
V_5 -> V_428 [ V_158 ] = 0 ;
V_5 -> V_429 [ V_158 ] = 0 ;
}
F_97 ( V_5 , F_22 ( V_5 ) -> V_14 -> V_118 == NULL ) ;
F_186 ( V_5 , 0 ) ;
if ( V_5 -> V_247 ) {
F_187 ( V_5 , 0 , 1 ) ;
F_188 ( V_5 ) ;
}
F_189 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_160 ( V_430 , & V_5 -> V_44 ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_381 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_382 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_383 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_384 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_385 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_386 ) ) ;
F_97 ( V_5 , F_190 ( & F_22 ( V_5 ) -> V_14 -> V_431 . V_432 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_387 . V_388 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_389 . V_388 ) ) ;
F_178 ( V_5 ) ;
}
static void F_191 ( void )
{
struct V_279 * V_279 ;
while ( V_433 ) {
V_279 = V_433 ;
V_433 = (struct V_279 * ) F_192 ( V_279 ) ;
F_193 ( V_279 ) ;
V_434 -- ;
}
if ( V_3 )
F_194 ( V_3 ) ;
if ( V_435 )
F_195 ( V_435 ) ;
if ( V_436 )
F_195 ( V_436 ) ;
if ( V_437 )
F_195 ( V_437 ) ;
if ( V_438 )
F_196 ( V_438 ) ;
if ( V_439 )
F_196 ( V_439 ) ;
if ( V_440 )
F_196 ( V_440 ) ;
if ( V_441 )
F_196 ( V_441 ) ;
V_3 = NULL ;
V_435 = NULL ;
V_436 = NULL ;
V_437 = NULL ;
V_438 = NULL ;
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
return;
}
static int F_197 ( void )
{
struct V_279 * V_279 ;
const int V_442 = ( V_192 / V_301 ) * V_443 ;
int V_158 ;
V_437 = NULL ;
V_438 = NULL ;
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
V_433 = NULL ;
V_435 = NULL ;
V_3 = NULL ;
V_439 = F_198 (
L_28 , sizeof( struct V_17 ) , 0 , 0 , NULL ) ;
if ( V_439 == NULL )
goto V_444;
V_438 = F_198 (
L_29 , sizeof( struct V_266 ) , 0 , 0 , NULL ) ;
if ( V_438 == NULL )
goto V_444;
V_440 = F_198 (
L_30 , sizeof( struct V_445 ) , 0 , 0 , NULL ) ;
if ( V_440 == NULL )
goto V_444;
V_441 = F_198 (
L_31 , sizeof( struct V_446 ) , 0 , 0 , NULL ) ;
if ( V_441 == NULL )
goto V_444;
V_3 = F_199 ( V_447 , 0 ) ;
if ( V_3 == NULL )
goto V_444;
V_435 = F_200 ( V_447 , 0 ) ;
if ( V_435 == NULL )
goto V_444;
V_437 = F_201 ( V_442 ,
V_439 ) ;
if ( V_437 == NULL )
goto V_444;
V_436 = F_201 ( V_442 , V_438 ) ;
if ( V_436 == NULL )
goto V_444;
F_33 ( & V_448 ) ;
for ( V_158 = 0 ; V_158 < V_442 ; V_158 ++ ) {
V_279 = F_202 ( V_449 ) ;
if ( ! V_279 )
goto V_444;
F_203 ( V_279 , ( unsigned long ) V_433 ) ;
V_433 = V_279 ;
}
V_434 = V_442 ;
return 0 ;
V_444:
F_191 () ;
return - V_450 ;
}
static void F_204 ( struct V_4 * V_5 )
{
int V_451 ;
V_451 = F_205 ( V_5 , & V_5 -> V_381 ) ;
if ( V_451 )
F_11 ( V_5 , L_32 , V_451 ) ;
V_451 = F_205 ( V_5 , & V_5 -> V_382 ) ;
if ( V_451 )
F_11 ( V_5 , L_33 , V_451 ) ;
V_451 = F_205 ( V_5 , & V_5 -> V_384 ) ;
if ( V_451 )
F_11 ( V_5 , L_34 , V_451 ) ;
V_451 = F_205 ( V_5 , & V_5 -> V_383 ) ;
if ( V_451 )
F_11 ( V_5 , L_35 , V_451 ) ;
V_451 = F_205 ( V_5 , & V_5 -> V_385 ) ;
if ( V_451 )
F_11 ( V_5 , L_36 , V_451 ) ;
}
void F_206 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_207 ( V_58 , struct V_4 , V_58 ) ;
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_71 * V_72 , * V_452 ;
F_208 ( & V_5 -> V_401 ) ;
F_97 ( V_5 , V_5 -> V_355 == 0 ) ;
if ( V_5 -> V_196 )
F_209 ( V_5 -> V_196 ) ;
F_189 ( V_5 , V_5 -> V_128 ) ;
V_5 -> V_128 = NULL ;
F_204 ( V_5 ) ;
F_210 ( V_5 -> V_453 ) ;
F_210 ( V_5 -> V_454 ) ;
F_55 ( V_5 -> V_455 ) ;
if ( V_5 -> V_247 )
F_188 ( V_5 ) ;
F_193 ( V_5 -> V_375 . V_279 ) ;
F_211 ( V_5 -> V_456 ) ;
F_212 ( V_5 -> V_457 ) ;
F_55 ( V_5 -> V_458 ) ;
F_213 (peer_device, tmp_peer_device, device) {
F_29 ( & V_72 -> V_14 -> V_58 , V_59 ) ;
F_55 ( V_72 ) ;
}
memset ( V_5 , 0xfd , sizeof( * V_5 ) ) ;
F_55 ( V_5 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_214 ( struct V_459 * V_460 )
{
struct V_461 * V_462 = F_207 ( V_460 , struct V_461 , V_463 ) ;
F_215 ( V_464 ) ;
struct V_17 * V_19 , * V_223 ;
F_9 ( & V_462 -> V_465 ) ;
F_216 ( & V_462 -> V_464 , & V_464 ) ;
F_14 ( & V_462 -> V_465 ) ;
F_18 (req, tmp, &writes, tl_requests) {
struct V_4 * V_5 = V_19 -> V_5 ;
struct V_1 * V_1 = V_19 -> V_313 ;
unsigned long V_466 = V_19 -> V_466 ;
bool V_467 ;
V_467 =
F_127 ( F_217 ( & V_19 -> V_468 ) == 0 ) &&
F_127 ( V_19 -> V_25 & V_469 ) &&
F_127 ( ( V_19 -> V_25 & V_38 ) == 0 ||
( V_19 -> V_25 & V_470 ) != 0 ) ;
if ( ! V_467 )
F_11 ( V_5 , L_37 ,
V_19 , F_217 ( & V_19 -> V_468 ) ,
V_19 -> V_25 ) ;
F_29 ( & V_19 -> V_58 , V_471 ) ;
F_218 ( V_5 ) ;
F_219 ( V_5 , V_1 , V_466 ) ;
}
}
void F_220 ( struct V_17 * V_19 )
{
unsigned long V_44 ;
F_24 ( & V_462 . V_465 , V_44 ) ;
F_221 ( & V_19 -> V_472 , & V_462 . V_464 ) ;
F_26 ( & V_462 . V_465 , V_44 ) ;
F_222 ( V_19 -> V_5 ) ;
F_223 ( V_462 . V_473 , & V_462 . V_463 ) ;
}
void V_60 ( struct V_58 * V_58 )
{
struct V_43 * V_22 =
F_207 ( V_58 , struct V_43 , V_58 ) ;
F_224 ( & V_22 -> V_474 ) ;
F_225 ( V_22 -> V_76 ) ;
F_55 ( V_22 -> V_48 ) ;
memset ( V_22 , 0xf2 , sizeof( * V_22 ) ) ;
F_55 ( V_22 ) ;
}
void F_226 ( struct V_43 * V_22 )
{
struct V_13 * V_14 , * V_223 ;
F_227 (connection, tmp, resource) {
F_228 ( & V_14 -> V_475 ) ;
F_229 ( V_14 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
F_230 ( V_22 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static void F_231 ( void )
{
unsigned int V_158 ;
struct V_4 * V_5 ;
struct V_43 * V_22 , * V_223 ;
if ( V_476 )
F_232 ( L_38 , NULL ) ;
if ( V_462 . V_473 )
F_233 ( V_462 . V_473 ) ;
F_234 () ;
F_235 () ;
F_236 (&drbd_devices, device, i)
F_237 ( V_5 ) ;
F_238 (resource, tmp, &drbd_resources) {
F_228 ( & V_22 -> V_477 ) ;
F_226 ( V_22 ) ;
}
F_191 () ;
F_239 ( V_478 , L_38 ) ;
F_224 ( & V_479 ) ;
F_240 ( L_39 ) ;
}
static int F_241 ( void * V_480 , int V_481 )
{
struct V_4 * V_5 = V_480 ;
struct V_482 * V_432 ;
char V_483 = '-' ;
int V_18 = 0 ;
if ( ! F_242 ( V_5 ) ) {
V_18 = V_481 ;
V_483 = 'd' ;
goto V_324;
}
if ( F_92 ( V_484 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_485 ) ;
if ( ! F_89 ( V_5 , V_177 ) )
V_18 |= ( 1 << V_486 ) ;
else
F_85 ( V_5 ) ;
V_18 &= V_481 ;
V_483 = 'c' ;
goto V_324;
}
if ( F_84 ( V_5 ) ) {
V_432 = F_243 ( V_5 -> V_128 -> V_188 ) ;
V_18 = F_244 ( & V_432 -> V_487 , V_481 ) ;
F_85 ( V_5 ) ;
if ( V_18 )
V_483 = 'b' ;
}
if ( V_481 & ( 1 << V_485 ) &&
F_92 ( V_278 , & F_22 ( V_5 ) -> V_14 -> V_44 ) ) {
V_18 |= ( 1 << V_485 ) ;
V_483 = V_483 == 'b' ? 'a' : 'n' ;
}
V_324:
V_5 -> V_488 = V_483 ;
return V_18 ;
}
static void F_245 ( struct V_489 * V_473 )
{
F_33 ( & V_473 -> V_490 ) ;
F_182 ( & V_473 -> V_432 ) ;
F_184 ( & V_473 -> V_491 ) ;
}
static int F_246 ( struct V_492 * V_391 , int V_493 )
{
struct V_494 * V_494 =
F_207 ( V_391 , struct V_494 , V_391 ) ;
F_247 ( & V_494 -> V_495 ) ;
return 0 ;
}
void F_248 ( struct V_489 * V_496 )
{
struct V_494 V_494 ;
V_494 . V_391 . V_394 = F_246 ;
F_37 ( & V_494 . V_495 ) ;
F_249 ( V_496 , & V_494 . V_391 ) ;
F_44 ( & V_494 . V_495 ) ;
}
struct V_43 * F_250 ( const char * V_48 )
{
struct V_43 * V_22 ;
if ( ! V_48 || ! V_48 [ 0 ] )
return NULL ;
F_46 () ;
F_52 (resource, &drbd_resources) {
if ( ! strcmp ( V_22 -> V_48 , V_48 ) ) {
F_36 ( & V_22 -> V_58 ) ;
goto V_497;
}
}
V_22 = NULL ;
V_497:
F_49 () ;
return V_22 ;
}
struct V_13 * F_251 ( void * V_498 , int V_499 ,
void * V_500 , int V_501 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
F_46 () ;
F_52 (resource, &drbd_resources) {
F_252 (connection, resource) {
if ( V_14 -> V_499 == V_499 &&
V_14 -> V_501 == V_501 &&
! memcmp ( & V_14 -> V_498 , V_498 , V_499 ) &&
! memcmp ( & V_14 -> V_500 , V_500 , V_501 ) ) {
F_36 ( & V_14 -> V_58 ) ;
goto V_497;
}
}
}
V_14 = NULL ;
V_497:
F_49 () ;
return V_14 ;
}
static int F_253 ( struct V_102 * V_104 )
{
V_104 -> V_502 = ( void * ) F_254 ( V_80 ) ;
if ( ! V_104 -> V_502 )
return - V_450 ;
V_104 -> V_105 = ( void * ) F_254 ( V_80 ) ;
if ( ! V_104 -> V_105 )
return - V_450 ;
return 0 ;
}
static void F_255 ( struct V_102 * V_104 )
{
F_256 ( ( unsigned long ) V_104 -> V_105 ) ;
F_256 ( ( unsigned long ) V_104 -> V_502 ) ;
}
void F_257 ( struct V_13 * V_14 )
{
F_258 ( V_14 ) ;
F_259 ( V_14 -> V_503 ) ;
F_259 ( V_14 -> V_504 ) ;
F_260 ( V_14 -> V_505 ) ;
F_259 ( V_14 -> V_312 ) ;
F_259 ( V_14 -> V_263 ) ;
F_55 ( V_14 -> V_506 ) ;
F_55 ( V_14 -> V_507 ) ;
V_14 -> V_503 = NULL ;
V_14 -> V_504 = NULL ;
V_14 -> V_505 = NULL ;
V_14 -> V_312 = NULL ;
V_14 -> V_263 = NULL ;
V_14 -> V_506 = NULL ;
V_14 -> V_507 = NULL ;
}
int F_261 ( struct V_43 * V_22 , struct V_508 * V_508 )
{
struct V_13 * V_14 ;
T_2 V_509 ;
int V_110 ;
if ( ! F_262 ( & V_509 , V_80 ) )
return - V_450 ;
if ( V_79 > 1 && V_508 -> V_76 [ 0 ] != 0 ) {
V_110 = F_263 ( V_508 -> V_76 , V_510 ,
F_264 ( V_509 ) , V_79 ) ;
if ( V_110 == - V_511 ) {
T_2 V_512 ;
if ( F_262 ( & V_512 , V_80 ) ) {
F_56 ( V_512 ) ;
F_265 ( V_509 , V_509 , V_512 ) ;
F_159 ( V_22 , L_40 ,
V_508 -> V_76 ,
strlen ( V_508 -> V_76 ) > 12 ? L_41 : L_42 ,
V_79 ) ;
F_225 ( V_512 ) ;
V_110 = 0 ;
}
}
if ( V_110 ) {
F_159 ( V_22 , L_43 , V_110 ) ;
goto V_513;
}
}
V_22 -> V_508 = * V_508 ;
if ( F_266 ( V_509 ) )
F_50 ( & V_509 ) ;
if ( ! F_267 ( V_22 -> V_76 , V_509 ) ) {
F_268 ( V_22 -> V_76 , V_509 ) ;
F_252 (connection, resource) {
V_14 -> V_415 . V_65 = 1 ;
V_14 -> V_273 . V_65 = 1 ;
V_14 -> V_463 . V_65 = 1 ;
}
}
V_110 = 0 ;
V_513:
F_225 ( V_509 ) ;
return V_110 ;
}
struct V_43 * F_269 ( const char * V_48 )
{
struct V_43 * V_22 ;
V_22 = F_51 ( sizeof( struct V_43 ) , V_80 ) ;
if ( ! V_22 )
goto V_513;
V_22 -> V_48 = F_270 ( V_48 , V_80 ) ;
if ( ! V_22 -> V_48 )
goto V_514;
if ( ! F_262 ( & V_22 -> V_76 , V_80 ) )
goto V_515;
F_271 ( & V_22 -> V_58 ) ;
F_272 ( & V_22 -> V_474 ) ;
F_182 ( & V_22 -> V_475 ) ;
V_22 -> V_516 = V_517 ;
F_273 ( & V_22 -> V_477 , & V_518 ) ;
F_181 ( & V_22 -> V_519 ) ;
F_181 ( & V_22 -> V_520 ) ;
F_33 ( & V_22 -> V_23 ) ;
F_274 ( V_22 ) ;
return V_22 ;
V_515:
F_55 ( V_22 -> V_48 ) ;
V_514:
F_55 ( V_22 ) ;
V_513:
return NULL ;
}
struct V_13 * F_275 ( const char * V_48 , struct V_508 * V_508 )
{
struct V_43 * V_22 ;
struct V_13 * V_14 ;
V_14 = F_51 ( sizeof( struct V_13 ) , V_80 ) ;
if ( ! V_14 )
return NULL ;
if ( F_253 ( & V_14 -> V_108 ) )
goto V_513;
if ( F_253 ( & V_14 -> V_114 ) )
goto V_513;
V_14 -> V_521 = F_51 ( sizeof( struct V_522 ) , V_80 ) ;
if ( ! V_14 -> V_521 )
goto V_513;
F_182 ( & V_14 -> V_523 ) ;
F_182 ( & V_14 -> V_521 -> V_388 ) ;
V_14 -> V_524 = 1 ;
F_33 ( & V_14 -> V_525 ) ;
V_14 -> V_526 . V_527 = false ;
V_14 -> V_526 . V_528 = 0 ;
V_14 -> V_526 . V_529 = 0 ;
V_22 = F_269 ( V_48 ) ;
if ( ! V_22 )
goto V_513;
V_14 -> V_250 = V_362 ;
F_181 ( & V_14 -> V_530 ) ;
F_184 ( & V_14 -> V_531 ) ;
F_272 ( & V_14 -> V_75 ) ;
F_245 ( & V_14 -> V_431 ) ;
F_181 ( & V_14 -> V_108 . V_106 ) ;
F_181 ( & V_14 -> V_114 . V_106 ) ;
F_31 ( V_22 , & V_14 -> V_415 , V_532 , L_44 ) ;
V_14 -> V_415 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_463 , V_533 , L_45 ) ;
V_14 -> V_463 . V_14 = V_14 ;
F_31 ( V_22 , & V_14 -> V_273 , V_534 , L_46 ) ;
V_14 -> V_273 . V_14 = V_14 ;
F_271 ( & V_14 -> V_58 ) ;
V_14 -> V_22 = V_22 ;
if ( F_261 ( V_22 , V_508 ) )
goto V_535;
F_36 ( & V_22 -> V_58 ) ;
F_273 ( & V_14 -> V_475 , & V_22 -> V_475 ) ;
F_276 ( V_14 ) ;
return V_14 ;
V_535:
F_228 ( & V_22 -> V_477 ) ;
F_226 ( V_22 ) ;
V_513:
F_55 ( V_14 -> V_521 ) ;
F_255 ( & V_14 -> V_114 ) ;
F_255 ( & V_14 -> V_108 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
void V_59 ( struct V_58 * V_58 )
{
struct V_13 * V_14 = F_207 ( V_58 , struct V_13 , V_58 ) ;
struct V_43 * V_22 = V_14 -> V_22 ;
if ( F_217 ( & V_14 -> V_521 -> V_536 ) != 0 )
F_11 ( V_14 , L_47 , F_217 ( & V_14 -> V_521 -> V_536 ) ) ;
F_55 ( V_14 -> V_521 ) ;
F_224 ( & V_14 -> V_75 ) ;
F_255 ( & V_14 -> V_114 ) ;
F_255 ( & V_14 -> V_108 ) ;
F_55 ( V_14 -> V_506 ) ;
F_55 ( V_14 -> V_507 ) ;
memset ( V_14 , 0xfc , sizeof( * V_14 ) ) ;
F_55 ( V_14 ) ;
F_29 ( & V_22 -> V_58 , V_60 ) ;
}
static int F_277 ( struct V_4 * V_5 )
{
V_5 -> V_537 . V_473 =
F_278 ( L_48 , V_538 , V_5 -> V_74 ) ;
if ( ! V_5 -> V_537 . V_473 )
return - V_450 ;
F_279 ( & V_5 -> V_537 . V_463 , V_539 ) ;
F_182 ( & V_5 -> V_537 . V_464 ) ;
return 0 ;
}
enum V_540 F_280 ( struct V_541 * V_542 , unsigned int V_74 )
{
struct V_43 * V_22 = V_542 -> V_22 ;
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_71 * V_72 , * V_452 ;
struct V_356 * V_11 ;
struct V_482 * V_432 ;
int V_543 ;
int V_73 = V_542 -> V_98 ;
enum V_540 V_110 = V_544 ;
V_5 = F_281 ( V_74 ) ;
if ( V_5 )
return V_545 ;
V_5 = F_51 ( sizeof( struct V_4 ) , V_80 ) ;
if ( ! V_5 )
return V_544 ;
F_271 ( & V_5 -> V_58 ) ;
F_36 ( & V_22 -> V_58 ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_74 = V_74 ;
V_5 -> V_73 = V_73 ;
F_179 ( V_5 ) ;
V_432 = F_282 ( V_80 ) ;
if ( ! V_432 )
goto V_546;
V_5 -> V_457 = V_432 ;
V_432 -> V_547 = V_5 ;
V_11 = F_283 ( 1 ) ;
if ( ! V_11 )
goto V_548;
V_5 -> V_456 = V_11 ;
F_284 ( V_11 , true ) ;
V_11 -> V_191 = V_432 ;
V_11 -> V_549 = V_478 ;
V_11 -> V_550 = V_74 ;
V_11 -> V_551 = & V_552 ;
sprintf ( V_11 -> V_553 , L_49 , V_74 ) ;
V_11 -> V_347 = V_5 ;
V_5 -> V_196 = F_285 ( F_286 ( V_478 , V_74 ) ) ;
V_5 -> V_196 -> V_554 = V_5 -> V_196 ;
V_432 -> V_487 . V_555 = F_241 ;
V_432 -> V_487 . V_480 = V_5 ;
F_287 ( V_432 , V_556 ) ;
F_288 ( V_432 , V_307 | V_305 ) ;
F_289 ( V_432 , V_413 >> 8 ) ;
F_290 ( V_432 , V_557 ) ;
V_432 -> V_558 = & V_22 -> V_23 ;
V_5 -> V_375 . V_279 = F_202 ( V_80 ) ;
if ( ! V_5 -> V_375 . V_279 )
goto V_559;
if ( F_291 ( V_5 ) )
goto V_560;
V_5 -> V_561 = V_562 ;
V_5 -> V_563 = V_562 ;
V_543 = F_292 ( & V_479 , V_5 , V_74 , V_74 + 1 , V_80 ) ;
if ( V_543 < 0 ) {
if ( V_543 == - V_564 )
V_110 = V_545 ;
goto V_565;
}
F_36 ( & V_5 -> V_58 ) ;
V_543 = F_292 ( & V_22 -> V_474 , V_5 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_543 < 0 ) {
if ( V_543 == - V_564 )
V_110 = V_545 ;
goto V_566;
}
F_36 ( & V_5 -> V_58 ) ;
F_182 ( & V_5 -> V_75 ) ;
F_182 ( & V_5 -> V_567 ) ;
F_293 (connection, resource) {
V_72 = F_51 ( sizeof( struct V_71 ) , V_80 ) ;
if ( ! V_72 )
goto V_568;
V_72 -> V_14 = V_14 ;
V_72 -> V_5 = V_5 ;
F_294 ( & V_72 -> V_75 , & V_5 -> V_75 ) ;
F_36 ( & V_5 -> V_58 ) ;
V_543 = F_292 ( & V_14 -> V_75 , V_72 , V_73 , V_73 + 1 , V_80 ) ;
if ( V_543 < 0 ) {
if ( V_543 == - V_564 )
V_110 = V_569 ;
goto V_568;
}
F_36 ( & V_14 -> V_58 ) ;
F_279 ( & V_72 -> V_570 , V_571 ) ;
}
if ( F_277 ( V_5 ) ) {
V_110 = V_544 ;
goto V_572;
}
F_295 ( V_11 ) ;
V_5 -> V_10 . V_32 = F_296 ( V_22 ) -> V_250 ;
if ( V_5 -> V_10 . V_32 == V_251 ) {
F_297 (peer_device, device)
F_298 ( V_72 ) ;
}
F_297 (peer_device, device)
F_299 ( V_72 ) ;
F_300 ( V_5 ) ;
return V_573 ;
V_572:
F_301 ( & V_14 -> V_75 , V_73 ) ;
V_568:
F_293 (connection, resource) {
V_72 = F_302 ( & V_14 -> V_75 , V_73 ) ;
if ( V_72 ) {
F_301 ( & V_14 -> V_75 , V_73 ) ;
F_29 ( & V_14 -> V_58 , V_59 ) ;
}
}
F_213 (peer_device, tmp_peer_device, device) {
F_228 ( & V_72 -> V_75 ) ;
F_55 ( V_72 ) ;
}
F_301 ( & V_22 -> V_474 , V_73 ) ;
V_566:
F_301 ( & V_479 , V_74 ) ;
F_303 () ;
V_565:
F_188 ( V_5 ) ;
V_560:
F_193 ( V_5 -> V_375 . V_279 ) ;
V_559:
F_211 ( V_11 ) ;
V_548:
F_212 ( V_432 ) ;
V_546:
F_29 ( & V_22 -> V_58 , V_60 ) ;
F_55 ( V_5 ) ;
return V_110 ;
}
void F_237 ( struct V_4 * V_5 )
{
struct V_43 * V_22 = V_5 -> V_22 ;
struct V_13 * V_14 ;
struct V_71 * V_72 ;
int V_574 = 3 ;
F_297 (peer_device, device)
F_304 ( V_72 ) ;
F_305 ( V_5 ) ;
F_293 (connection, resource) {
F_301 ( & V_14 -> V_75 , V_5 -> V_73 ) ;
V_574 ++ ;
}
F_301 ( & V_22 -> V_474 , V_5 -> V_73 ) ;
F_301 ( & V_479 , F_48 ( V_5 ) ) ;
F_306 ( V_5 -> V_456 ) ;
F_303 () ;
F_307 ( & V_5 -> V_58 , V_574 , F_206 ) ;
}
static int T_8 F_308 ( void )
{
int V_110 ;
if ( V_443 < V_575 || V_443 > V_576 ) {
F_309 ( L_50 , V_443 ) ;
#ifdef F_310
return - V_577 ;
#else
V_443 = V_578 ;
#endif
}
V_110 = F_311 ( V_478 , L_38 ) ;
if ( V_110 ) {
F_309 ( L_51 ,
V_478 ) ;
return V_110 ;
}
F_184 ( & V_579 ) ;
V_476 = NULL ;
F_272 ( & V_479 ) ;
F_181 ( & V_580 ) ;
F_182 ( & V_518 ) ;
V_110 = F_312 () ;
if ( V_110 ) {
F_309 ( L_52 ) ;
goto V_513;
}
V_110 = F_197 () ;
if ( V_110 )
goto V_513;
V_110 = - V_450 ;
V_476 = F_313 ( L_38 , V_581 | V_582 , NULL , & V_583 , NULL ) ;
if ( ! V_476 ) {
F_309 ( L_53 ) ;
goto V_513;
}
V_462 . V_473 = F_314 ( L_54 ) ;
if ( ! V_462 . V_473 ) {
F_309 ( L_55 ) ;
goto V_513;
}
F_279 ( & V_462 . V_463 , F_214 ) ;
F_33 ( & V_462 . V_465 ) ;
F_182 ( & V_462 . V_464 ) ;
if ( F_315 () )
F_316 ( L_56 ) ;
F_240 ( L_57
L_58 V_584 L_59 ,
V_585 , V_586 , V_587 ) ;
F_240 ( L_60 , F_317 () ) ;
F_240 ( L_61 , V_478 ) ;
return 0 ;
V_513:
F_231 () ;
if ( V_110 == - V_450 )
F_309 ( L_62 ) ;
else
F_309 ( L_63 ) ;
return V_110 ;
}
static void F_318 ( struct V_102 * V_588 )
{
struct V_104 * V_24 ;
F_71 ( & V_588 -> V_106 ) ;
V_24 = V_588 -> V_104 ;
V_588 -> V_104 = NULL ;
F_72 ( & V_588 -> V_106 ) ;
if ( V_24 ) {
F_303 () ;
F_319 ( V_24 , V_589 ) ;
F_320 ( V_24 ) ;
}
}
void F_258 ( struct V_13 * V_14 )
{
if ( V_14 -> V_108 . V_104 )
F_318 ( & V_14 -> V_108 ) ;
if ( V_14 -> V_114 . V_104 )
F_318 ( & V_14 -> V_114 ) ;
}
void F_321 ( struct V_13 * V_14 )
{
struct V_71 * V_72 ;
int V_73 ;
F_46 () ;
F_236 (&connection->peer_devices, peer_device, vnr) {
struct V_4 * V_5 = V_72 -> V_5 ;
F_36 ( & V_5 -> V_58 ) ;
F_49 () ;
F_100 ( V_5 ) ;
F_29 ( & V_5 -> V_58 , F_206 ) ;
F_46 () ;
}
F_49 () ;
}
void F_322 ( struct V_4 * V_5 , void * V_233 )
{
struct V_590 * V_100 = V_233 ;
T_4 V_254 ;
int V_158 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_591 = F_90 ( F_105 ( V_5 -> V_196 ) ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_100 -> V_164 [ V_158 ] = F_90 ( V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ) ;
V_100 -> V_44 = F_64 ( V_5 -> V_128 -> V_160 . V_44 ) ;
V_100 -> V_92 = F_64 ( V_592 ) ;
V_100 -> V_593 = F_64 ( V_5 -> V_128 -> V_160 . V_593 ) ;
V_100 -> V_594 = F_64 ( V_5 -> V_128 -> V_160 . V_594 ) ;
V_100 -> V_595 = F_64 ( V_5 -> V_453 -> V_596 ) ;
V_100 -> V_597 = F_64 ( V_598 ) ;
V_100 -> V_599 = F_90 ( V_5 -> V_128 -> V_160 . V_599 ) ;
V_100 -> V_600 = F_64 ( V_5 -> V_128 -> V_160 . V_600 ) ;
V_100 -> V_601 = F_64 ( V_5 -> V_412 ) ;
V_100 -> V_602 = F_64 ( V_5 -> V_128 -> V_160 . V_602 ) ;
V_100 -> V_603 = F_64 ( V_5 -> V_128 -> V_160 . V_603 ) ;
F_97 ( V_5 , F_323 ( V_5 -> V_128 ) == V_5 -> V_128 -> V_160 . V_604 ) ;
V_254 = V_5 -> V_128 -> V_160 . V_604 ;
if ( F_324 ( V_5 , V_5 -> V_128 , V_254 , V_605 ) ) {
F_11 ( V_5 , L_64 ) ;
F_325 ( V_5 , 1 , V_606 ) ;
}
}
void F_100 ( struct V_4 * V_5 )
{
struct V_590 * V_100 ;
F_61 ( V_163 != 4 ) ;
F_61 ( sizeof( struct V_590 ) != 4096 ) ;
F_326 ( & V_5 -> V_399 ) ;
if ( ! F_327 ( V_607 , & V_5 -> V_44 ) )
return;
if ( ! F_89 ( V_5 , V_608 ) )
return;
V_100 = F_328 ( V_5 , V_291 ) ;
if ( ! V_100 )
goto V_324;
F_322 ( V_5 , V_100 ) ;
V_5 -> V_128 -> V_160 . V_591 = F_105 ( V_5 -> V_196 ) ;
F_329 ( V_5 ) ;
V_324:
F_85 ( V_5 ) ;
}
static int F_330 ( struct V_4 * V_5 ,
struct V_590 * V_609 ,
struct V_610 * V_611 )
{
T_5 V_602 = F_331 ( V_609 -> V_602 ) ;
T_5 V_603 = F_331 ( V_609 -> V_603 ) ;
T_3 V_612 ;
if ( V_602 == 0 && V_603 == 0 ) {
V_602 = 1 ;
V_603 = V_613 / 8 ;
}
if ( V_602 == 0 || V_603 == 0 )
goto V_110;
V_612 = ( T_3 ) V_602 * V_603 ;
if ( V_612 > ( 16 * 1024 * 1024 / 4 ) )
goto V_110;
if ( V_612 < V_613 / 8 )
goto V_110;
V_611 -> V_603 = V_603 ;
V_611 -> V_602 = V_602 ;
V_611 -> V_612 = V_612 ;
return 0 ;
V_110:
F_11 ( V_5 , L_65 ,
V_602 , V_603 ) ;
return - V_577 ;
}
static int F_332 ( struct V_4 * V_5 , struct V_614 * V_345 )
{
T_4 V_615 = F_105 ( V_345 -> V_616 ) ;
struct V_610 * V_611 = & V_345 -> V_160 ;
T_9 V_617 ;
T_9 V_618 ;
if ( V_611 -> V_594 < 0 ) {
if ( V_611 -> V_600 > V_611 -> V_594 )
goto V_110;
V_617 = - V_611 -> V_594 ;
V_618 = V_611 -> V_594 - V_611 -> V_600 ;
} else {
if ( V_611 -> V_594 != V_619 )
goto V_110;
if ( V_611 -> V_600 < V_611 -> V_594 + V_611 -> V_612 * V_619 )
goto V_110;
V_617 = V_611 -> V_600 - V_619 ;
V_618 = V_611 -> V_593 - V_611 -> V_600 ;
}
if ( V_611 -> V_620 >= 0 ) {
if ( V_611 -> V_593 != V_621
|| V_611 -> V_594 != V_619
|| V_611 -> V_600 != V_619 + V_613
|| V_611 -> V_602 != 1
|| V_611 -> V_603 != V_613 / 8 )
goto V_110;
}
if ( V_615 < V_611 -> V_593 )
goto V_110;
if ( V_615 - V_611 -> V_593 < F_333 ( V_345 ) )
goto V_110;
if ( ( V_617 & 7 ) || ( V_617 < V_613 ) )
goto V_110;
if ( V_617 != V_611 -> V_612 * V_619 )
goto V_110;
if ( V_611 -> V_600 & 7 )
goto V_110;
if ( V_618 < ( V_611 -> V_591 + 7 ) / V_619 / 8 / 512 )
goto V_110;
return 0 ;
V_110:
F_11 ( V_5 , L_66
L_67
L_68 ,
V_611 -> V_620 ,
V_611 -> V_602 , V_611 -> V_603 ,
V_611 -> V_594 , V_611 -> V_600 , V_611 -> V_593 ,
( unsigned long long ) V_611 -> V_591 ,
( unsigned long long ) V_615 ) ;
return - V_577 ;
}
int F_334 ( struct V_4 * V_5 , struct V_614 * V_345 )
{
struct V_590 * V_100 ;
T_5 V_92 , V_44 ;
int V_158 , V_333 = V_573 ;
if ( V_5 -> V_10 . V_11 != V_363 )
return V_622 ;
V_100 = F_328 ( V_5 , V_291 ) ;
if ( ! V_100 )
return V_544 ;
V_345 -> V_160 . V_620 = V_345 -> V_120 -> V_620 ;
V_345 -> V_160 . V_604 = F_323 ( V_345 ) ;
V_345 -> V_160 . V_593 = 8 ;
if ( F_324 ( V_5 , V_345 , V_345 -> V_160 . V_604 , V_623 ) ) {
F_11 ( V_5 , L_69 ) ;
V_333 = V_624 ;
goto V_110;
}
V_92 = F_331 ( V_100 -> V_92 ) ;
V_44 = F_331 ( V_100 -> V_44 ) ;
if ( V_92 == V_592 ||
( V_92 == V_625 && ! ( V_44 & V_626 ) ) ) {
F_11 ( V_5 , L_70 ) ;
V_333 = V_627 ;
goto V_110;
}
V_333 = V_628 ;
if ( V_92 != V_625 ) {
if ( V_92 == V_629 )
F_11 ( V_5 , L_71 ) ;
else
F_11 ( V_5 , L_72 ) ;
goto V_110;
}
if ( F_331 ( V_100 -> V_597 ) != V_598 ) {
F_11 ( V_5 , L_73 ,
F_331 ( V_100 -> V_597 ) , V_598 ) ;
goto V_110;
}
V_345 -> V_160 . V_591 = F_335 ( V_100 -> V_591 ) ;
for ( V_158 = V_162 ; V_158 < V_163 ; V_158 ++ )
V_345 -> V_160 . V_164 [ V_158 ] = F_335 ( V_100 -> V_164 [ V_158 ] ) ;
V_345 -> V_160 . V_44 = F_331 ( V_100 -> V_44 ) ;
V_345 -> V_160 . V_599 = F_335 ( V_100 -> V_599 ) ;
V_345 -> V_160 . V_593 = F_331 ( V_100 -> V_593 ) ;
V_345 -> V_160 . V_594 = F_331 ( V_100 -> V_594 ) ;
V_345 -> V_160 . V_600 = F_331 ( V_100 -> V_600 ) ;
if ( F_330 ( V_5 , V_100 , & V_345 -> V_160 ) )
goto V_110;
if ( F_332 ( V_5 , V_345 ) )
goto V_110;
if ( F_331 ( V_100 -> V_600 ) != V_345 -> V_160 . V_600 ) {
F_11 ( V_5 , L_74 ,
F_331 ( V_100 -> V_600 ) , V_345 -> V_160 . V_600 ) ;
goto V_110;
}
if ( F_331 ( V_100 -> V_593 ) != V_345 -> V_160 . V_593 ) {
F_11 ( V_5 , L_75 ,
F_331 ( V_100 -> V_593 ) , V_345 -> V_160 . V_593 ) ;
goto V_110;
}
V_333 = V_573 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( V_5 -> V_10 . V_32 < V_258 ) {
unsigned int V_360 ;
V_360 = F_331 ( V_100 -> V_601 ) ;
V_360 = F_336 ( V_360 , V_413 ) ;
V_5 -> V_412 = V_360 ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_110:
F_329 ( V_5 ) ;
return V_333 ;
}
void F_337 ( struct V_4 * V_5 , unsigned int line , const char * F_32 )
{
if ( ! F_338 ( V_607 , & V_5 -> V_44 ) ) {
F_339 ( & V_5 -> V_399 , V_630 + V_631 ) ;
V_5 -> V_632 . line = line ;
V_5 -> V_632 . F_32 = F_32 ;
}
}
void F_340 ( struct V_4 * V_5 )
{
if ( ! F_338 ( V_607 , & V_5 -> V_44 ) )
F_339 ( & V_5 -> V_399 , V_630 + 5 * V_631 ) ;
}
void F_341 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_158 ;
for ( V_158 = V_173 ; V_158 < V_174 ; V_158 ++ )
V_5 -> V_128 -> V_160 . V_164 [ V_158 + 1 ] = V_5 -> V_128 -> V_160 . V_164 [ V_158 ] ;
}
void F_342 ( struct V_4 * V_5 , int V_633 , T_3 V_203 ) __must_hold( T_10 )
{
if ( V_633 == V_162 ) {
if ( V_5 -> V_10 . V_349 == V_350 )
V_203 |= 1 ;
else
V_203 &= ~ ( ( T_3 ) 1 ) ;
F_343 ( V_5 , V_203 ) ;
}
V_5 -> V_128 -> V_160 . V_164 [ V_633 ] = V_203 ;
F_340 ( V_5 ) ;
}
void F_344 ( struct V_4 * V_5 , int V_633 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_342 ( V_5 , V_633 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_99 ( struct V_4 * V_5 , int V_633 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_633 ] ) {
F_341 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_633 ] ;
}
F_342 ( V_5 , V_633 , V_203 ) ;
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
}
void F_345 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
T_3 V_203 ;
unsigned long long V_634 ;
F_98 ( & V_203 , sizeof( T_3 ) ) ;
F_9 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
V_634 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_634 )
F_159 ( V_5 , L_76 , V_634 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_5 -> V_128 -> V_160 . V_164 [ V_162 ] ;
F_342 ( V_5 , V_162 , V_203 ) ;
F_14 ( & V_5 -> V_128 -> V_160 . V_161 ) ;
F_95 ( V_5 , L_77 ) ;
F_100 ( V_5 ) ;
}
void F_346 ( struct V_4 * V_5 , T_3 V_203 ) __must_hold( T_10 )
{
unsigned long V_44 ;
if ( V_5 -> V_128 -> V_160 . V_164 [ V_172 ] == 0 && V_203 == 0 )
return;
F_24 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
if ( V_203 == 0 ) {
F_341 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_173 ] = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = 0 ;
} else {
unsigned long long V_634 = V_5 -> V_128 -> V_160 . V_164 [ V_172 ] ;
if ( V_634 )
F_159 ( V_5 , L_76 , V_634 ) ;
V_5 -> V_128 -> V_160 . V_164 [ V_172 ] = V_203 & ~ ( ( T_3 ) 1 ) ;
}
F_26 ( & V_5 -> V_128 -> V_160 . V_161 , V_44 ) ;
F_340 ( V_5 ) ;
}
int F_347 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
int V_333 = - V_115 ;
F_348 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
F_129 ( V_5 ) ;
V_333 = F_130 ( V_5 ) ;
if ( ! V_333 ) {
F_131 ( V_5 , V_248 ) ;
F_100 ( V_5 ) ;
}
return V_333 ;
}
int F_349 ( struct V_4 * V_5 ) __must_hold( T_10 )
{
F_350 ( V_5 ) ;
F_351 ( V_5 ) ;
return F_130 ( V_5 ) ;
}
static int V_397 ( struct V_492 * V_391 , int V_635 )
{
struct V_4 * V_5 =
F_207 ( V_391 , struct V_4 , V_390 . V_391 ) ;
struct V_390 * V_636 = & V_5 -> V_390 ;
int V_333 = - V_115 ;
F_97 ( V_5 , F_217 ( & V_5 -> V_366 ) == 0 ) ;
if ( F_84 ( V_5 ) ) {
F_352 ( V_5 , V_636 -> V_637 , V_636 -> V_44 ) ;
V_333 = V_636 -> V_638 ( V_5 ) ;
F_353 ( V_5 ) ;
F_85 ( V_5 ) ;
}
F_354 ( V_639 , & V_5 -> V_44 ) ;
F_7 ( & V_5 -> V_12 ) ;
if ( V_636 -> V_495 )
V_636 -> V_495 ( V_5 , V_333 ) ;
F_160 ( V_640 , & V_5 -> V_44 ) ;
V_636 -> V_637 = NULL ;
V_636 -> V_44 = 0 ;
return 0 ;
}
void F_355 ( struct V_4 * V_5 ,
int (* V_638)( struct V_4 * ) ,
void (* V_495)( struct V_4 * , int ) ,
char * V_637 , enum V_641 V_44 )
{
F_97 ( V_5 , V_46 == F_22 ( V_5 ) -> V_14 -> V_463 . V_55 ) ;
F_97 ( V_5 , ! F_92 ( V_640 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , ! F_92 ( V_639 , & V_5 -> V_44 ) ) ;
F_97 ( V_5 , F_190 ( & V_5 -> V_390 . V_391 . V_388 ) ) ;
if ( V_5 -> V_390 . V_637 )
F_11 ( V_5 , L_78 ,
V_637 , V_5 -> V_390 . V_637 ) ;
V_5 -> V_390 . V_638 = V_638 ;
V_5 -> V_390 . V_495 = V_495 ;
V_5 -> V_390 . V_637 = V_637 ;
V_5 -> V_390 . V_44 = V_44 ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
F_150 ( V_639 , & V_5 -> V_44 ) ;
if ( V_44 == V_642 || F_217 ( & V_5 -> V_366 ) == 0 ) {
if ( ! F_338 ( V_640 , & V_5 -> V_44 ) )
F_249 ( & F_22 ( V_5 ) -> V_14 -> V_431 ,
& V_5 -> V_390 . V_391 ) ;
}
F_14 ( & V_5 -> V_22 -> V_23 ) ;
}
int F_356 ( struct V_4 * V_5 , int (* V_638)( struct V_4 * ) ,
char * V_637 , enum V_641 V_44 )
{
int V_333 ;
F_97 ( V_5 , V_46 != F_22 ( V_5 ) -> V_14 -> V_463 . V_55 ) ;
if ( ( V_44 & V_643 ) == 0 )
F_357 ( V_5 ) ;
F_352 ( V_5 , V_637 , V_44 ) ;
V_333 = V_638 ( V_5 ) ;
F_353 ( V_5 ) ;
if ( ( V_44 & V_643 ) == 0 )
F_358 ( V_5 ) ;
return V_333 ;
}
void F_348 ( struct V_4 * V_5 , int V_644 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_644 ) != V_644 ) {
F_340 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 |= V_644 ;
}
}
void F_131 ( struct V_4 * V_5 , int V_644 ) __must_hold( T_10 )
{
if ( ( V_5 -> V_128 -> V_160 . V_44 & V_644 ) != 0 ) {
F_340 ( V_5 ) ;
V_5 -> V_128 -> V_160 . V_44 &= ~ V_644 ;
}
}
int F_128 ( struct V_614 * V_345 , int V_644 )
{
return ( V_345 -> V_160 . V_44 & V_644 ) != 0 ;
}
static void V_403 ( unsigned long V_108 )
{
struct V_4 * V_5 = (struct V_4 * ) V_108 ;
F_359 ( V_5 , V_645 ) ;
}
const char * F_360 ( enum V_89 V_90 )
{
static const char * V_646 [] = {
[ V_325 ] = L_79 ,
[ V_647 ] = L_80 ,
[ V_648 ] = L_81 ,
[ V_649 ] = L_82 ,
[ V_246 ] = L_83 ,
[ V_650 ] = L_84 ,
[ V_651 ] = L_85 ,
[ V_652 ] = L_86 ,
[ V_653 ] = L_87 ,
[ V_654 ] = L_88 ,
[ V_126 ] = L_89 ,
[ V_125 ] = L_90 ,
[ V_155 ] = L_91 ,
[ V_170 ] = L_92 ,
[ V_198 ] = L_93 ,
[ V_200 ] = L_94 ,
[ V_180 ] = L_95 ,
[ V_655 ] = L_96 ,
[ V_656 ] = L_97 ,
[ V_112 ] = L_98 ,
[ V_113 ] = L_99 ,
[ V_657 ] = L_100 ,
[ V_658 ] = L_101 ,
[ V_659 ] = L_102 ,
[ V_660 ] = L_103 ,
[ V_661 ] = L_104 ,
[ V_662 ] = L_105 ,
[ V_663 ] = L_106 ,
[ V_253 ] = L_107 ,
[ V_205 ] = L_108 ,
[ V_210 ] = L_109 ,
[ V_271 ] = L_110 ,
[ V_664 ] = L_111 ,
[ V_665 ] = L_112 ,
[ V_666 ] = L_113 ,
[ V_667 ] = L_114 ,
[ V_239 ] = L_115 ,
[ V_668 ] = L_116 ,
[ V_327 ] = L_117 ,
[ V_669 ] = L_118 ,
[ V_670 ] = L_119 ,
[ V_206 ] = L_120 ,
[ V_211 ] = L_121 ,
[ V_669 ] = L_122 ,
[ V_671 ] = L_123 ,
} ;
if ( V_90 == V_672 )
return L_124 ;
if ( V_90 == V_673 )
return L_125 ;
if ( V_90 == V_674 )
return L_126 ;
if ( V_90 >= F_361 ( V_646 ) )
return L_127 ;
return V_646 [ V_90 ] ;
}
int F_362 ( struct V_4 * V_5 , struct V_675 * V_158 )
{
struct V_118 * V_119 ;
F_363 ( V_67 ) ;
long V_676 ;
F_46 () ;
V_119 = F_83 ( F_22 ( V_5 ) -> V_14 -> V_118 ) ;
if ( ! V_119 ) {
F_49 () ;
return - V_677 ;
}
V_676 = V_119 -> V_274 ? V_119 -> V_676 * V_631 / 10 * V_119 -> V_274 : V_678 ;
F_49 () ;
V_158 -> V_679 = true ;
F_364 ( & V_5 -> V_12 , & V_67 , V_680 ) ;
F_14 ( & V_5 -> V_22 -> V_23 ) ;
V_676 = F_365 ( V_676 ) ;
F_366 ( & V_5 -> V_12 , & V_67 ) ;
F_9 ( & V_5 -> V_22 -> V_23 ) ;
if ( ! V_676 || V_5 -> V_10 . V_32 < V_258 )
return - V_677 ;
if ( F_367 ( V_46 ) )
return - V_681 ;
return 0 ;
}
void F_368 ( void )
{
struct V_43 * V_22 ;
int T_11 V_158 = 0 ;
F_71 ( & V_580 ) ;
F_369 () ;
F_370 (resource, &drbd_resources)
F_371 ( & V_22 -> V_23 , V_158 ++ ) ;
}
void F_372 ( void )
{
struct V_43 * V_22 ;
F_370 (resource, &drbd_resources)
F_373 ( & V_22 -> V_23 ) ;
F_374 () ;
F_72 ( & V_580 ) ;
}
static unsigned long
F_375 ( struct V_682 * V_683 )
{
long V_684 ;
if ( ! V_683 -> V_685 -- ) {
F_98 ( & V_684 , sizeof( V_684 ) ) ;
V_683 -> V_10 += V_684 ;
V_683 -> V_685 = V_686 ;
}
V_683 -> V_10 = V_683 -> V_10 * V_687 + V_688 ;
return F_376 ( V_683 -> V_10 ) ;
}
static char *
F_377 ( unsigned int type ) {
static char * V_689 [] = {
[ V_690 ] = L_128 ,
[ V_691 ] = L_129 ,
[ V_692 ] = L_130 ,
[ V_693 ] = L_131 ,
[ V_694 ] = L_132 ,
[ V_695 ] = L_133 ,
[ V_696 ] = L_134 ,
[ V_697 ] = L_135 ,
[ V_698 ] = L_136 ,
[ V_699 ] = L_137 ,
} ;
return ( type < V_700 ) ? V_689 [ type ] : L_138 ;
}
unsigned int
F_378 ( struct V_4 * V_5 , unsigned int type )
{
static struct V_682 V_701 = { 0 , 0 } ;
unsigned int V_702 = (
( V_703 == 0 ||
( ( 1 << F_48 ( V_5 ) ) & V_703 ) != 0 ) &&
( ( ( F_375 ( & V_701 ) % 100 ) + 1 ) <= V_704 ) ) ;
if ( V_702 ) {
V_705 ++ ;
if ( F_379 ( & V_706 ) )
F_159 ( V_5 , L_139 ,
F_377 ( type ) ) ;
}
return V_702 ;
}
const char * F_317 ( void )
{
static char V_707 [ 38 ] = L_140 ;
if ( V_707 [ 0 ] == 0 ) {
#ifdef F_310
sprintf ( V_707 , L_141 , V_61 -> V_708 ) ;
#else
V_707 [ 0 ] = 'b' ;
#endif
}
return V_707 ;
}
