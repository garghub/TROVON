int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_4 != NULL )
return - V_5 ;
V_2 -> V_4 = F_2 ( V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void * F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
V_2 -> V_7 = F_6 ( V_6 , V_8 ) ;
return V_2 -> V_7 ;
}
int F_7 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
if ( V_9 < 1 )
return - V_13 ;
V_11 = F_8 ( V_9 , sizeof( * V_11 ) , V_8 ) ;
if ( ! V_11 )
return - V_14 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = V_9 ;
for ( V_12 = 0 ; V_12 < V_9 ; ++ V_12 ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
V_11 -> V_3 = V_2 ;
V_11 -> V_17 = V_12 ;
V_11 -> V_18 = V_19 ;
F_9 ( & V_11 -> V_20 ) ;
V_11 -> V_21 = - 1 ;
}
return 0 ;
}
int F_10 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_22 )
return - V_13 ;
V_11 -> V_23 = F_8 ( V_11 -> V_22 , sizeof( * V_11 -> V_23 ) , V_8 ) ;
if ( ! V_11 -> V_23 )
return - V_14 ;
if ( ! V_11 -> V_24 )
V_11 -> V_24 = V_25 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_10 * V_11 ;
if ( V_2 -> V_15 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> V_26 & V_27 )
F_12 ( V_11 -> V_7 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_28 ) {
F_14 ( V_2 , V_11 , 0 ) ;
F_12 ( V_11 -> V_28 ) ;
}
F_12 ( V_11 -> V_23 ) ;
}
F_12 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = 0 ;
}
F_12 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = false ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = NULL ;
V_2 -> V_39 = NULL ;
V_2 -> V_40 = NULL ;
F_3 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_41 ) ;
V_2 -> V_42 = false ;
V_2 -> V_43 ++ ;
if ( V_2 -> V_29 )
V_2 -> V_29 -> V_44 ( V_2 ) ;
F_11 ( V_2 ) ;
F_18 ( & V_2 -> V_41 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
return - V_13 ;
}
int V_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
unsigned int V_48 = F_21 ( V_46 -> V_49 ) ;
int V_12 ;
if ( ! V_11 -> V_23 )
return - V_13 ;
for ( V_12 = 0 ; V_12 < V_46 -> V_50 ; V_12 ++ )
V_47 [ V_12 ] = V_11 -> V_23 [ V_48 ] ;
return V_46 -> V_50 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_45 * V_46 ,
int (* F_23)( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_45 * V_46 ,
unsigned long V_51 ) ,
unsigned long V_51 )
{
unsigned long V_52 = V_53 + F_24 ( V_54 ) ;
int V_55 ;
while ( F_25 ( V_53 , V_52 ) ) {
V_55 = F_23 ( V_2 , V_11 , V_46 , V_51 ) ;
if ( V_55 != - V_56 )
return V_55 ;
F_26 () ;
}
return - V_57 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_45 * V_46 ,
unsigned int * V_47 ,
unsigned int V_58 )
{
unsigned int V_59 = 1 << F_21 ( V_46 -> V_49 ) ;
if ( ! V_58 )
V_58 = V_59 ;
switch ( V_47 [ 0 ] ) {
case V_60 :
V_11 -> V_61 &= ~ V_58 ;
break;
case V_62 :
V_11 -> V_61 |= V_58 ;
break;
case V_63 :
V_47 [ 1 ] = ( V_11 -> V_61 & V_58 ) ? V_64 : V_65 ;
return V_46 -> V_50 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_28 ( struct V_10 * V_11 ,
unsigned int * V_47 )
{
unsigned int V_66 = ( V_11 -> V_22 < 32 ) ? ( ( 1 << V_11 -> V_22 ) - 1 )
: 0xffffffff ;
unsigned int V_58 = V_47 [ 0 ] & V_66 ;
unsigned int V_67 = V_47 [ 1 ] ;
if ( V_58 ) {
V_11 -> V_68 &= ~ V_58 ;
V_11 -> V_68 |= ( V_67 & V_58 ) ;
}
return V_58 ;
}
unsigned int F_29 ( struct V_10 * V_11 )
{
struct V_69 * V_70 = & V_11 -> V_28 -> V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
switch ( V_11 -> type ) {
case V_73 :
case V_74 :
case V_75 :
V_72 = 8 * F_30 ( V_11 ) ;
V_71 = F_31 ( V_70 -> V_76 , V_72 ) ;
break;
default:
V_71 = V_70 -> V_76 ;
break;
}
return F_32 ( V_11 , V_71 ) ;
}
unsigned int F_33 ( struct V_10 * V_11 ,
unsigned int V_77 )
{
struct V_78 * V_28 = V_11 -> V_28 ;
struct V_69 * V_70 = & V_28 -> V_70 ;
if ( V_77 == 0 ) {
unsigned int V_79 = F_34 ( V_11 ) ;
V_77 = V_79 / F_29 ( V_11 ) ;
}
if ( V_70 -> V_80 == V_81 ) {
unsigned int V_82 = 0 ;
if ( V_28 -> V_83 < V_70 -> V_84 )
V_82 = V_70 -> V_84 - V_28 -> V_83 ;
if ( V_77 > V_82 )
V_77 = V_82 ;
}
return V_77 ;
}
unsigned int F_35 ( struct V_10 * V_11 ,
unsigned int V_85 )
{
struct V_78 * V_28 = V_11 -> V_28 ;
struct V_69 * V_70 = & V_28 -> V_70 ;
if ( V_70 -> V_80 == V_81 ) {
unsigned int V_77 = ( V_85 / V_70 -> V_76 ) + 1 ;
unsigned int V_82 = F_33 ( V_11 , V_77 ) ;
unsigned int V_86 =
F_36 ( V_11 , V_28 -> V_87 ) ;
unsigned long long V_88 = 0 ;
if ( V_82 ) {
V_88 = ( ( unsigned long long ) V_82 *
V_70 -> V_76 ) - V_86 ;
}
if ( V_88 < V_85 )
V_85 = V_88 ;
}
return V_85 ;
}
void F_37 ( struct V_10 * V_11 ,
unsigned int V_89 )
{
struct V_78 * V_28 = V_11 -> V_28 ;
struct V_69 * V_70 = & V_28 -> V_70 ;
unsigned int V_90 = F_29 ( V_11 ) ;
if ( ! ( V_11 -> V_91 & V_92 ) ) {
V_28 -> V_93 += F_36 ( V_11 , V_89 ) ;
V_28 -> V_93 %= V_70 -> V_94 ;
}
V_28 -> V_87 += V_89 ;
if ( V_28 -> V_87 >= V_90 ) {
unsigned int V_77 = V_28 -> V_87 / V_90 ;
if ( V_28 -> V_83 < ( V_95 - V_77 ) )
V_28 -> V_83 += V_77 ;
else
V_28 -> V_83 = V_95 ;
V_28 -> V_87 %= V_90 ;
V_28 -> V_96 |= V_97 ;
}
}
unsigned int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_96 = V_11 -> V_28 -> V_96 ;
if ( V_96 == 0 )
return V_96 ;
if ( V_96 & V_98 )
V_11 -> V_99 ( V_2 , V_11 ) ;
F_39 ( V_2 , V_11 ) ;
return V_96 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
struct V_45 V_100 ;
int V_55 ;
static const unsigned V_101 = 32 ;
unsigned V_48 = F_21 ( V_46 -> V_49 ) ;
const unsigned V_102 =
( V_48 < V_101 ) ? 0 : V_48 ;
unsigned int V_103 [ 2 ] ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_46 = V_104 ;
V_100 . V_49 = V_102 ;
V_100 . V_50 = 2 ;
V_100 . V_105 = V_46 -> V_105 ;
if ( V_46 -> V_46 == V_106 ) {
if ( ! ( V_11 -> V_91 & V_107 ) )
return - V_13 ;
V_103 [ 0 ] = 1 << ( V_48 - V_102 ) ;
V_103 [ 1 ] = V_47 [ 0 ] ? ( 1 << ( V_48 - V_102 ) )
: 0 ;
}
V_55 = V_11 -> V_108 ( V_2 , V_11 , & V_100 , V_103 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_46 -> V_46 == V_109 )
V_47 [ 0 ] = ( V_103 [ 1 ] >> ( V_48 - V_102 ) ) & 1 ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_78 * V_28 ;
unsigned int V_110 ;
int V_55 ;
if ( ( V_11 -> V_91 & ( V_111 | V_112 ) ) == 0 ) {
F_42 ( V_2 -> V_113 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_114 ) {
F_42 ( V_2 -> V_113 ,
L_2 ) ;
return - V_13 ;
}
V_28 = F_6 ( sizeof( * V_28 ) , V_8 ) ;
if ( ! V_28 )
return - V_14 ;
F_43 ( & V_28 -> V_115 ) ;
V_11 -> V_28 = V_28 ;
V_28 -> V_116 = V_117 * 1024 ;
V_110 = V_118 * 1024 ;
if ( V_110 > V_28 -> V_116 )
V_110 = V_28 -> V_116 ;
if ( F_14 ( V_2 , V_11 , V_110 ) < 0 ) {
F_42 ( V_2 -> V_113 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_119 ) {
V_55 = V_11 -> V_119 ( V_2 , V_11 ) ;
if ( V_55 < 0 )
return V_55 ;
}
F_44 ( V_11 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_55 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_120 )
continue;
if ( V_11 -> type == V_74 ) {
if ( V_11 -> V_22 < 32 )
V_11 -> V_61 = ( 1 << V_11 -> V_22 ) - 1 ;
else
V_11 -> V_61 = 0xffffffff ;
}
if ( V_11 -> V_121 == 0 )
V_11 -> V_121 = 1 ;
if ( V_11 -> V_122 ) {
V_55 = F_41 ( V_2 , V_11 ) ;
if ( V_55 )
return V_55 ;
}
if ( ! V_11 -> V_123 && ! V_11 -> V_124 )
V_11 -> V_123 = & V_125 ;
if ( ! V_11 -> V_24 && V_11 -> V_108 )
V_11 -> V_24 = F_40 ;
if ( ! V_11 -> V_126 && V_11 -> V_108 )
V_11 -> V_126 = F_40 ;
if ( ! V_11 -> V_24 )
V_11 -> V_24 = F_20 ;
if ( ! V_11 -> V_126 )
V_11 -> V_126 = F_20 ;
if ( ! V_11 -> V_108 )
V_11 -> V_108 = F_20 ;
if ( ! V_11 -> V_127 )
V_11 -> V_127 = F_20 ;
if ( ! V_11 -> V_128 )
V_11 -> V_128 = F_19 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_45 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
F_17 ( & V_2 -> V_41 ) ;
V_2 -> V_42 = true ;
F_18 ( & V_2 -> V_41 ) ;
return 0 ;
}
static void * F_47 ( struct V_129 * V_130 , const char * V_131 )
{
char * * V_132 = ( char * * ) V_130 -> V_30 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_130 -> V_133 ; V_12 ++ ) {
if ( strcmp ( * V_132 , V_131 ) == 0 )
return V_132 ;
V_132 = ( void * ) V_132 + V_130 -> V_134 ;
}
return NULL ;
}
static void F_48 ( struct V_129 * V_130 )
{
unsigned int V_12 ;
const char * const * V_132 ;
F_49 ( L_4 ,
V_130 -> V_135 ) ;
V_132 = V_130 -> V_30 ;
for ( V_12 = 0 ; V_12 < V_130 -> V_133 ; V_12 ++ ) {
F_49 ( L_5 , * V_132 ) ;
V_132 = ( const char * * ) ( ( char * ) V_132 + V_130 -> V_134 ) ;
}
if ( V_130 -> V_133 == 0 )
F_49 ( L_5 , V_130 -> V_135 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_131 ,
int (* F_23)( struct V_1 * V_2 ,
const T_2 * V_47 , T_1 V_6 ,
unsigned long V_51 ) ,
unsigned long V_51 )
{
const struct V_136 * V_137 ;
int V_55 ;
if ( ! F_23 )
return - V_13 ;
V_55 = F_51 ( & V_137 , V_131 , V_3 ) ;
if ( V_55 == 0 ) {
V_55 = F_23 ( V_2 , V_137 -> V_47 , V_137 -> V_6 , V_51 ) ;
F_52 ( V_137 ) ;
}
return V_55 < 0 ? V_55 : 0 ;
}
int F_53 ( struct V_1 * V_2 ,
unsigned long V_138 , unsigned long V_139 )
{
if ( ! V_138 ) {
F_42 ( V_2 -> V_113 ,
L_6 ,
V_2 -> V_30 ) ;
return - V_13 ;
}
if ( ! F_54 ( V_138 , V_139 , V_2 -> V_30 ) ) {
F_42 ( V_2 -> V_113 , L_7 ,
V_2 -> V_30 , V_138 , V_139 ) ;
return - V_140 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
unsigned long V_138 , unsigned long V_139 )
{
int V_55 ;
V_55 = F_53 ( V_2 , V_138 , V_139 ) ;
if ( V_55 == 0 ) {
V_2 -> V_33 = V_138 ;
V_2 -> V_34 = V_139 ;
}
return V_55 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 ) {
F_57 ( V_2 -> V_36 , V_2 ) ;
V_2 -> V_36 = 0 ;
}
if ( V_2 -> V_33 && V_2 -> V_34 ) {
F_58 ( V_2 -> V_33 , V_2 -> V_34 ) ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
}
}
int F_59 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_129 * V_130 ;
int V_55 ;
if ( V_2 -> V_42 )
return - V_56 ;
F_60 ( & V_143 ) ;
for ( V_130 = V_144 ; V_130 ; V_130 = V_130 -> V_145 ) {
if ( ! F_61 ( V_130 -> V_146 ) )
continue;
if ( V_130 -> V_133 ) {
V_2 -> V_31 = F_47 ( V_130 , V_142 -> V_30 ) ;
if ( V_2 -> V_31 )
break;
} else if ( strcmp ( V_130 -> V_135 , V_142 -> V_30 ) == 0 ) {
break;
}
F_62 ( V_130 -> V_146 ) ;
}
if ( V_130 == NULL ) {
for ( V_130 = V_144 ; V_130 ; V_130 = V_130 -> V_145 ) {
if ( ! F_61 ( V_130 -> V_146 ) )
continue;
F_48 ( V_130 ) ;
F_62 ( V_130 -> V_146 ) ;
}
V_55 = - V_140 ;
goto V_147;
}
if ( V_130 -> V_148 == NULL ) {
F_42 ( V_2 -> V_113 ,
L_8 ,
V_130 -> V_135 ) ;
F_62 ( V_130 -> V_146 ) ;
V_55 = - V_149 ;
goto V_147;
}
V_2 -> V_29 = V_130 ;
V_2 -> V_30 = V_2 -> V_31 ? * ( const char * * ) V_2 -> V_31
: V_2 -> V_29 -> V_135 ;
V_55 = V_130 -> V_148 ( V_2 , V_142 ) ;
if ( V_55 >= 0 )
V_55 = F_46 ( V_2 ) ;
if ( V_55 < 0 ) {
F_15 ( V_2 ) ;
F_62 ( V_130 -> V_146 ) ;
}
V_147:
F_63 ( & V_143 ) ;
return V_55 ;
}
int F_64 ( struct V_3 * V_150 ,
struct V_129 * V_29 , unsigned long V_51 )
{
struct V_1 * V_2 ;
int V_55 ;
if ( ! V_150 ) {
F_65 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_29 ) {
F_42 ( V_150 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_29 -> V_151 ) {
F_42 ( V_150 ,
L_11 ,
V_29 -> V_135 ) ;
return - V_13 ;
}
V_2 = F_66 ( V_150 ) ;
if ( F_67 ( V_2 ) ) {
F_42 ( V_150 ,
L_12 ,
V_29 -> V_135 ) ;
return F_68 ( V_2 ) ;
}
V_2 -> V_29 = V_29 ;
V_2 -> V_30 = V_2 -> V_29 -> V_135 ;
V_55 = V_29 -> V_151 ( V_2 , V_51 ) ;
if ( V_55 >= 0 )
V_55 = F_46 ( V_2 ) ;
F_63 ( & V_2 -> V_152 ) ;
if ( V_55 < 0 ) {
F_42 ( V_150 ,
L_13 ,
V_29 -> V_135 ) ;
F_69 ( V_150 ) ;
} else {
F_70 ( V_2 -> V_113 ,
L_14 ,
V_29 -> V_135 , V_2 -> V_30 ) ;
}
return V_55 ;
}
void F_71 ( struct V_3 * V_150 )
{
if ( V_150 == NULL )
return;
F_69 ( V_150 ) ;
}
int F_72 ( struct V_129 * V_29 )
{
F_60 ( & V_143 ) ;
V_29 -> V_145 = V_144 ;
V_144 = V_29 ;
F_63 ( & V_143 ) ;
return 0 ;
}
void F_73 ( struct V_129 * V_29 )
{
struct V_129 * V_153 ;
int V_12 ;
F_60 ( & V_143 ) ;
if ( V_144 == V_29 ) {
V_144 = V_29 -> V_145 ;
} else {
for ( V_153 = V_144 ; V_153 -> V_145 ; V_153 = V_153 -> V_145 ) {
if ( V_153 -> V_145 == V_29 ) {
V_153 -> V_145 = V_29 -> V_145 ;
break;
}
}
}
F_63 ( & V_143 ) ;
for ( V_12 = 0 ; V_12 < V_154 ; V_12 ++ ) {
struct V_1 * V_2 = F_74 ( V_12 ) ;
if ( ! V_2 )
continue;
F_60 ( & V_2 -> V_152 ) ;
if ( V_2 -> V_42 && V_2 -> V_29 == V_29 ) {
if ( V_2 -> V_155 )
F_42 ( V_2 -> V_113 ,
L_15 ,
V_2 -> V_155 ) ;
F_15 ( V_2 ) ;
}
F_63 ( & V_2 -> V_152 ) ;
F_75 ( V_2 ) ;
}
}
