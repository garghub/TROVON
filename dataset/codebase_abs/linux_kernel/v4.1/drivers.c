int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 == V_2 -> V_4 )
return 0 ;
if ( V_2 -> V_4 )
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
F_12 ( V_2 -> V_29 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = false ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = NULL ;
V_2 -> V_39 = NULL ;
V_2 -> V_40 = NULL ;
V_2 -> V_41 = NULL ;
F_3 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = false ;
V_2 -> V_44 ++ ;
if ( V_2 -> V_30 )
V_2 -> V_30 -> V_45 ( V_2 ) ;
F_11 ( V_2 ) ;
F_18 ( & V_2 -> V_42 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_46 * V_47 , unsigned int * V_48 )
{
return - V_13 ;
}
int V_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_46 * V_47 ,
unsigned int * V_48 )
{
unsigned int V_49 = F_21 ( V_47 -> V_50 ) ;
int V_12 ;
if ( ! V_11 -> V_23 )
return - V_13 ;
for ( V_12 = 0 ; V_12 < V_47 -> V_51 ; V_12 ++ )
V_48 [ V_12 ] = V_11 -> V_23 [ V_49 ] ;
return V_47 -> V_51 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_46 * V_47 ,
int (* F_23)( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_46 * V_47 ,
unsigned long V_52 ) ,
unsigned long V_52 )
{
unsigned long V_53 = V_54 + F_24 ( V_55 ) ;
int V_56 ;
while ( F_25 ( V_54 , V_53 ) ) {
V_56 = F_23 ( V_2 , V_11 , V_47 , V_52 ) ;
if ( V_56 != - V_57 )
return V_56 ;
F_26 () ;
}
return - V_58 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_46 * V_47 ,
unsigned int * V_48 ,
unsigned int V_59 )
{
unsigned int V_60 = 1 << F_21 ( V_47 -> V_50 ) ;
if ( ! V_59 )
V_59 = V_60 ;
switch ( V_48 [ 0 ] ) {
case V_61 :
V_11 -> V_62 &= ~ V_59 ;
break;
case V_63 :
V_11 -> V_62 |= V_59 ;
break;
case V_64 :
V_48 [ 1 ] = ( V_11 -> V_62 & V_59 ) ? V_65 : V_66 ;
return V_47 -> V_51 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_28 ( struct V_10 * V_11 ,
unsigned int * V_48 )
{
unsigned int V_67 = ( V_11 -> V_22 < 32 ) ? ( ( 1 << V_11 -> V_22 ) - 1 )
: 0xffffffff ;
unsigned int V_59 = V_48 [ 0 ] & V_67 ;
unsigned int V_68 = V_48 [ 1 ] ;
if ( V_59 ) {
V_11 -> V_69 &= ~ V_59 ;
V_11 -> V_69 |= ( V_68 & V_59 ) ;
}
return V_59 ;
}
unsigned int F_29 ( struct V_10 * V_11 )
{
struct V_70 * V_71 = & V_11 -> V_28 -> V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
switch ( V_11 -> type ) {
case V_74 :
case V_75 :
case V_76 :
V_73 = 8 * F_30 ( V_11 ) ;
V_72 = F_31 ( V_71 -> V_77 , V_73 ) ;
break;
default:
V_72 = V_71 -> V_77 ;
break;
}
return F_32 ( V_11 , V_72 ) ;
}
unsigned int F_33 ( struct V_10 * V_11 ,
unsigned int V_78 )
{
struct V_79 * V_28 = V_11 -> V_28 ;
struct V_70 * V_71 = & V_28 -> V_71 ;
if ( V_78 == 0 ) {
unsigned int V_80 = F_34 ( V_11 ) ;
V_78 = V_80 / F_29 ( V_11 ) ;
}
if ( V_71 -> V_81 == V_82 ) {
unsigned int V_83 = 0 ;
if ( V_28 -> V_84 < V_71 -> V_85 )
V_83 = V_71 -> V_85 - V_28 -> V_84 ;
if ( V_78 > V_83 )
V_78 = V_83 ;
}
return V_78 ;
}
unsigned int F_35 ( struct V_10 * V_11 ,
unsigned int V_86 )
{
struct V_79 * V_28 = V_11 -> V_28 ;
struct V_70 * V_71 = & V_28 -> V_71 ;
if ( V_71 -> V_81 == V_82 ) {
unsigned int V_78 = ( V_86 / V_71 -> V_77 ) + 1 ;
unsigned int V_83 = F_33 ( V_11 , V_78 ) ;
unsigned int V_87 =
F_36 ( V_11 , V_28 -> V_88 ) ;
unsigned long long V_89 = 0 ;
if ( V_83 ) {
V_89 = ( ( unsigned long long ) V_83 *
V_71 -> V_77 ) - V_87 ;
}
if ( V_89 < V_86 )
V_86 = V_89 ;
}
return V_86 ;
}
void F_37 ( struct V_10 * V_11 ,
unsigned int V_90 )
{
struct V_79 * V_28 = V_11 -> V_28 ;
struct V_70 * V_71 = & V_28 -> V_71 ;
unsigned int V_91 = F_29 ( V_11 ) ;
if ( ! ( V_11 -> V_92 & V_93 ) ) {
V_28 -> V_94 += F_36 ( V_11 , V_90 ) ;
V_28 -> V_94 %= V_71 -> V_95 ;
}
V_28 -> V_88 += V_90 ;
if ( V_28 -> V_88 >= V_91 ) {
unsigned int V_78 = V_28 -> V_88 / V_91 ;
if ( V_28 -> V_84 < ( V_96 - V_78 ) )
V_28 -> V_84 += V_78 ;
else
V_28 -> V_84 = V_96 ;
V_28 -> V_88 %= V_91 ;
V_28 -> V_97 |= V_98 ;
}
}
unsigned int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_97 = V_11 -> V_28 -> V_97 ;
if ( V_97 == 0 )
return V_97 ;
if ( V_97 & V_99 )
V_11 -> V_100 ( V_2 , V_11 ) ;
F_39 ( V_2 , V_11 ) ;
return V_97 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_46 * V_47 , unsigned int * V_48 )
{
struct V_46 V_101 ;
int V_56 ;
static const unsigned V_102 = 32 ;
unsigned V_49 = F_21 ( V_47 -> V_50 ) ;
const unsigned V_103 =
( V_49 < V_102 ) ? 0 : V_49 ;
unsigned int V_104 [ 2 ] ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_47 = V_105 ;
V_101 . V_50 = V_103 ;
V_101 . V_51 = 2 ;
V_101 . V_106 = V_47 -> V_106 ;
if ( V_47 -> V_47 == V_107 ) {
if ( ! ( V_11 -> V_92 & V_108 ) )
return - V_13 ;
V_104 [ 0 ] = 1 << ( V_49 - V_103 ) ;
V_104 [ 1 ] = V_48 [ 0 ] ? ( 1 << ( V_49 - V_103 ) )
: 0 ;
}
V_56 = V_11 -> V_109 ( V_2 , V_11 , & V_101 , V_104 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_47 -> V_47 == V_110 )
V_48 [ 0 ] = ( V_104 [ 1 ] >> ( V_49 - V_103 ) ) & 1 ;
return 1 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_79 * V_28 ;
unsigned int V_111 ;
int V_56 ;
if ( ( V_11 -> V_92 & ( V_112 | V_113 ) ) == 0 ) {
F_42 ( V_2 -> V_114 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_115 ) {
F_42 ( V_2 -> V_114 ,
L_2 ) ;
return - V_13 ;
}
V_28 = F_6 ( sizeof( * V_28 ) , V_8 ) ;
if ( ! V_28 )
return - V_14 ;
F_43 ( & V_28 -> V_116 ) ;
V_11 -> V_28 = V_28 ;
V_28 -> V_117 = V_118 * 1024 ;
V_111 = V_119 * 1024 ;
if ( V_111 > V_28 -> V_117 )
V_111 = V_28 -> V_117 ;
if ( F_14 ( V_2 , V_11 , V_111 ) < 0 ) {
F_42 ( V_2 -> V_114 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_120 ) {
V_56 = V_11 -> V_120 ( V_2 , V_11 ) ;
if ( V_56 < 0 )
return V_56 ;
}
F_44 ( V_11 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_56 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_121 )
continue;
if ( V_11 -> type == V_75 ) {
if ( V_11 -> V_22 < 32 )
V_11 -> V_62 = ( 1 << V_11 -> V_22 ) - 1 ;
else
V_11 -> V_62 = 0xffffffff ;
}
if ( V_11 -> V_122 == 0 )
V_11 -> V_122 = 1 ;
if ( V_11 -> V_123 ) {
V_56 = F_41 ( V_2 , V_11 ) ;
if ( V_56 )
return V_56 ;
}
if ( ! V_11 -> V_124 && ! V_11 -> V_125 )
V_11 -> V_124 = & V_126 ;
if ( ! V_11 -> V_24 && V_11 -> V_109 )
V_11 -> V_24 = F_40 ;
if ( ! V_11 -> V_127 && V_11 -> V_109 )
V_11 -> V_127 = F_40 ;
if ( ! V_11 -> V_24 )
V_11 -> V_24 = F_20 ;
if ( ! V_11 -> V_127 )
V_11 -> V_127 = F_20 ;
if ( ! V_11 -> V_109 )
V_11 -> V_109 = F_20 ;
if ( ! V_11 -> V_128 )
V_11 -> V_128 = F_20 ;
if ( ! V_11 -> V_129 )
V_11 -> V_129 = F_19 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_45 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
F_17 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = true ;
F_18 ( & V_2 -> V_42 ) ;
return 0 ;
}
static void * F_47 ( struct V_130 * V_131 , const char * V_132 )
{
char * * V_133 = ( char * * ) V_131 -> V_31 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_131 -> V_134 ; V_12 ++ ) {
if ( strcmp ( * V_133 , V_132 ) == 0 )
return V_133 ;
V_133 = ( void * ) V_133 + V_131 -> V_135 ;
}
return NULL ;
}
static void F_48 ( struct V_130 * V_131 )
{
unsigned int V_12 ;
const char * const * V_133 ;
F_49 ( L_4 ,
V_131 -> V_136 ) ;
V_133 = V_131 -> V_31 ;
for ( V_12 = 0 ; V_12 < V_131 -> V_134 ; V_12 ++ ) {
F_49 ( L_5 , * V_133 ) ;
V_133 = ( const char * * ) ( ( char * ) V_133 + V_131 -> V_135 ) ;
}
if ( V_131 -> V_134 == 0 )
F_49 ( L_5 , V_131 -> V_136 ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_132 ,
int (* F_23)( struct V_1 * V_2 ,
const T_2 * V_48 , T_1 V_6 ,
unsigned long V_52 ) ,
unsigned long V_52 )
{
const struct V_137 * V_138 ;
int V_56 ;
if ( ! F_23 )
return - V_13 ;
V_56 = F_51 ( & V_138 , V_132 , V_3 ) ;
if ( V_56 == 0 ) {
V_56 = F_23 ( V_2 , V_138 -> V_48 , V_138 -> V_6 , V_52 ) ;
F_52 ( V_138 ) ;
}
return V_56 < 0 ? V_56 : 0 ;
}
int F_53 ( struct V_1 * V_2 ,
unsigned long V_139 , unsigned long V_140 )
{
if ( ! V_139 ) {
F_42 ( V_2 -> V_114 ,
L_6 ,
V_2 -> V_31 ) ;
return - V_13 ;
}
if ( ! F_54 ( V_139 , V_140 , V_2 -> V_31 ) ) {
F_42 ( V_2 -> V_114 , L_7 ,
V_2 -> V_31 , V_139 , V_140 ) ;
return - V_141 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
unsigned long V_139 , unsigned long V_140 )
{
int V_56 ;
V_56 = F_53 ( V_2 , V_139 , V_140 ) ;
if ( V_56 == 0 ) {
V_2 -> V_34 = V_139 ;
V_2 -> V_35 = V_140 ;
}
return V_56 ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 ) {
F_57 ( V_2 -> V_37 , V_2 ) ;
V_2 -> V_37 = 0 ;
}
if ( V_2 -> V_34 && V_2 -> V_35 ) {
F_58 ( V_2 -> V_34 , V_2 -> V_35 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
}
}
int F_59 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_130 * V_131 ;
int V_56 ;
if ( V_2 -> V_43 )
return - V_57 ;
F_60 ( & V_144 ) ;
for ( V_131 = V_145 ; V_131 ; V_131 = V_131 -> V_146 ) {
if ( ! F_61 ( V_131 -> V_147 ) )
continue;
if ( V_131 -> V_134 ) {
V_2 -> V_32 = F_47 ( V_131 , V_143 -> V_31 ) ;
if ( V_2 -> V_32 )
break;
} else if ( strcmp ( V_131 -> V_136 , V_143 -> V_31 ) == 0 ) {
break;
}
F_62 ( V_131 -> V_147 ) ;
}
if ( ! V_131 ) {
for ( V_131 = V_145 ; V_131 ; V_131 = V_131 -> V_146 ) {
if ( ! F_61 ( V_131 -> V_147 ) )
continue;
F_48 ( V_131 ) ;
F_62 ( V_131 -> V_147 ) ;
}
V_56 = - V_141 ;
goto V_148;
}
if ( ! V_131 -> V_149 ) {
F_42 ( V_2 -> V_114 ,
L_8 ,
V_131 -> V_136 ) ;
F_62 ( V_131 -> V_147 ) ;
V_56 = - V_150 ;
goto V_148;
}
V_2 -> V_30 = V_131 ;
V_2 -> V_31 = V_2 -> V_32 ? * ( const char * * ) V_2 -> V_32
: V_2 -> V_30 -> V_136 ;
V_56 = V_131 -> V_149 ( V_2 , V_143 ) ;
if ( V_56 >= 0 )
V_56 = F_46 ( V_2 ) ;
if ( V_56 < 0 ) {
F_15 ( V_2 ) ;
F_62 ( V_131 -> V_147 ) ;
}
V_148:
F_63 ( & V_144 ) ;
return V_56 ;
}
int F_64 ( struct V_3 * V_151 ,
struct V_130 * V_30 , unsigned long V_52 )
{
struct V_1 * V_2 ;
int V_56 ;
if ( ! V_151 ) {
F_65 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_30 ) {
F_42 ( V_151 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_30 -> V_152 ) {
F_42 ( V_151 ,
L_11 ,
V_30 -> V_136 ) ;
return - V_13 ;
}
V_2 = F_66 ( V_151 ) ;
if ( F_67 ( V_2 ) ) {
F_42 ( V_151 ,
L_12 ,
V_30 -> V_136 ) ;
return F_68 ( V_2 ) ;
}
V_2 -> V_30 = V_30 ;
V_2 -> V_31 = V_2 -> V_30 -> V_136 ;
V_56 = V_30 -> V_152 ( V_2 , V_52 ) ;
if ( V_56 >= 0 )
V_56 = F_46 ( V_2 ) ;
F_63 ( & V_2 -> V_153 ) ;
if ( V_56 < 0 ) {
F_42 ( V_151 ,
L_13 ,
V_30 -> V_136 ) ;
F_69 ( V_151 ) ;
} else {
F_70 ( V_2 -> V_114 ,
L_14 ,
V_30 -> V_136 , V_2 -> V_31 ) ;
}
return V_56 ;
}
void F_71 ( struct V_3 * V_151 )
{
if ( ! V_151 )
return;
F_69 ( V_151 ) ;
}
int F_72 ( struct V_130 * V_30 )
{
F_60 ( & V_144 ) ;
V_30 -> V_146 = V_145 ;
V_145 = V_30 ;
F_63 ( & V_144 ) ;
return 0 ;
}
void F_73 ( struct V_130 * V_30 )
{
struct V_130 * V_154 ;
int V_12 ;
F_60 ( & V_144 ) ;
if ( V_145 == V_30 ) {
V_145 = V_30 -> V_146 ;
} else {
for ( V_154 = V_145 ; V_154 -> V_146 ; V_154 = V_154 -> V_146 ) {
if ( V_154 -> V_146 == V_30 ) {
V_154 -> V_146 = V_30 -> V_146 ;
break;
}
}
}
F_63 ( & V_144 ) ;
for ( V_12 = 0 ; V_12 < V_155 ; V_12 ++ ) {
struct V_1 * V_2 = F_74 ( V_12 ) ;
if ( ! V_2 )
continue;
F_60 ( & V_2 -> V_153 ) ;
if ( V_2 -> V_43 && V_2 -> V_30 == V_30 ) {
if ( V_2 -> V_156 )
F_42 ( V_2 -> V_114 ,
L_15 ,
V_2 -> V_156 ) ;
F_15 ( V_2 ) ;
}
F_63 ( & V_2 -> V_153 ) ;
F_75 ( V_2 ) ;
}
}
