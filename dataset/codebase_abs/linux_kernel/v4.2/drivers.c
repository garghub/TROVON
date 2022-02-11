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
if ( F_12 ( V_11 ) )
F_13 ( V_11 -> V_7 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_26 ) {
F_15 ( V_2 , V_11 , 0 ) ;
F_13 ( V_11 -> V_26 ) ;
}
F_13 ( V_11 -> V_23 ) ;
}
F_13 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = 0 ;
}
F_13 ( V_2 -> V_7 ) ;
F_13 ( V_2 -> V_27 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_27 = NULL ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = NULL ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = false ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = NULL ;
V_2 -> V_39 = NULL ;
F_3 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_18 ( & V_2 -> V_40 ) ;
V_2 -> V_41 = false ;
V_2 -> V_42 ++ ;
if ( V_2 -> V_28 )
V_2 -> V_28 -> V_43 ( V_2 ) ;
F_11 ( V_2 ) ;
F_19 ( & V_2 -> V_40 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_21 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
return - V_13 ;
}
int V_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_44 * V_45 ,
unsigned int * V_46 )
{
unsigned int V_47 = F_22 ( V_45 -> V_48 ) ;
int V_12 ;
if ( ! V_11 -> V_23 )
return - V_13 ;
for ( V_12 = 0 ; V_12 < V_45 -> V_49 ; V_12 ++ )
V_46 [ V_12 ] = V_11 -> V_23 [ V_47 ] ;
return V_45 -> V_49 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_44 * V_45 ,
int (* F_24)( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_44 * V_45 ,
unsigned long V_50 ) ,
unsigned long V_50 )
{
unsigned long V_51 = V_52 + F_25 ( V_53 ) ;
int V_54 ;
while ( F_26 ( V_52 , V_51 ) ) {
V_54 = F_24 ( V_2 , V_11 , V_45 , V_50 ) ;
if ( V_54 != - V_55 )
return V_54 ;
F_27 () ;
}
return - V_56 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_44 * V_45 ,
unsigned int * V_46 ,
unsigned int V_57 )
{
unsigned int V_58 = 1 << F_22 ( V_45 -> V_48 ) ;
if ( ! V_57 )
V_57 = V_58 ;
switch ( V_46 [ 0 ] ) {
case V_59 :
V_11 -> V_60 &= ~ V_57 ;
break;
case V_61 :
V_11 -> V_60 |= V_57 ;
break;
case V_62 :
V_46 [ 1 ] = ( V_11 -> V_60 & V_57 ) ? V_63 : V_64 ;
return V_45 -> V_49 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_29 ( struct V_10 * V_11 ,
unsigned int * V_46 )
{
unsigned int V_65 = ( V_11 -> V_22 < 32 ) ? ( ( 1 << V_11 -> V_22 ) - 1 )
: 0xffffffff ;
unsigned int V_57 = V_46 [ 0 ] & V_65 ;
unsigned int V_66 = V_46 [ 1 ] ;
if ( V_57 ) {
V_11 -> V_67 &= ~ V_57 ;
V_11 -> V_67 |= ( V_66 & V_57 ) ;
}
return V_57 ;
}
unsigned int F_30 ( struct V_10 * V_11 )
{
struct V_68 * V_69 = & V_11 -> V_26 -> V_69 ;
unsigned int V_70 ;
unsigned int V_71 ;
switch ( V_11 -> type ) {
case V_72 :
case V_73 :
case V_74 :
V_71 = 8 * F_31 ( V_11 ) ;
V_70 = F_32 ( V_69 -> V_75 , V_71 ) ;
break;
default:
V_70 = V_69 -> V_75 ;
break;
}
return F_33 ( V_11 , V_70 ) ;
}
unsigned int F_34 ( struct V_10 * V_11 ,
unsigned int V_76 )
{
struct V_77 * V_26 = V_11 -> V_26 ;
struct V_68 * V_69 = & V_26 -> V_69 ;
if ( V_76 == 0 ) {
unsigned int V_78 = F_35 ( V_11 ) ;
V_76 = V_78 / F_30 ( V_11 ) ;
}
if ( V_69 -> V_79 == V_80 ) {
unsigned int V_81 = 0 ;
if ( V_26 -> V_82 < V_69 -> V_83 )
V_81 = V_69 -> V_83 - V_26 -> V_82 ;
if ( V_76 > V_81 )
V_76 = V_81 ;
}
return V_76 ;
}
unsigned int F_36 ( struct V_10 * V_11 ,
unsigned int V_84 )
{
struct V_77 * V_26 = V_11 -> V_26 ;
struct V_68 * V_69 = & V_26 -> V_69 ;
if ( V_69 -> V_79 == V_80 ) {
unsigned int V_76 = ( V_84 / V_69 -> V_75 ) + 1 ;
unsigned int V_81 = F_34 ( V_11 , V_76 ) ;
unsigned int V_85 =
F_37 ( V_11 , V_26 -> V_86 ) ;
unsigned long long V_87 = 0 ;
if ( V_81 ) {
V_87 = ( ( unsigned long long ) V_81 *
V_69 -> V_75 ) - V_85 ;
}
if ( V_87 < V_84 )
V_84 = V_87 ;
}
return V_84 ;
}
void F_38 ( struct V_10 * V_11 ,
unsigned int V_88 )
{
struct V_77 * V_26 = V_11 -> V_26 ;
struct V_68 * V_69 = & V_26 -> V_69 ;
unsigned int V_89 = F_30 ( V_11 ) ;
if ( ! ( V_11 -> V_90 & V_91 ) ) {
V_26 -> V_92 += F_37 ( V_11 , V_88 ) ;
V_26 -> V_92 %= V_69 -> V_93 ;
}
V_26 -> V_86 += V_88 ;
if ( V_26 -> V_86 >= V_89 ) {
unsigned int V_76 = V_26 -> V_86 / V_89 ;
if ( V_26 -> V_82 < ( V_94 - V_76 ) )
V_26 -> V_82 += V_76 ;
else
V_26 -> V_82 = V_94 ;
V_26 -> V_86 %= V_89 ;
V_26 -> V_95 |= V_96 ;
}
}
unsigned int F_39 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_95 = V_11 -> V_26 -> V_95 ;
if ( V_95 == 0 )
return V_95 ;
if ( V_95 & V_97 )
V_11 -> V_98 ( V_2 , V_11 ) ;
F_40 ( V_2 , V_11 ) ;
return V_95 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
struct V_44 V_99 ;
int V_54 ;
static const unsigned V_100 = 32 ;
unsigned V_47 = F_22 ( V_45 -> V_48 ) ;
const unsigned V_101 =
( V_47 < V_100 ) ? 0 : V_47 ;
unsigned int V_102 [ 2 ] ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_45 = V_103 ;
V_99 . V_48 = V_101 ;
V_99 . V_49 = 2 ;
V_99 . V_104 = V_45 -> V_104 ;
if ( V_45 -> V_45 == V_105 ) {
if ( ! ( V_11 -> V_90 & V_106 ) )
return - V_13 ;
V_102 [ 0 ] = 1 << ( V_47 - V_101 ) ;
V_102 [ 1 ] = V_46 [ 0 ] ? ( 1 << ( V_47 - V_101 ) )
: 0 ;
}
V_54 = V_11 -> V_107 ( V_2 , V_11 , & V_99 , V_102 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( V_45 -> V_45 == V_108 )
V_46 [ 0 ] = ( V_102 [ 1 ] >> ( V_47 - V_101 ) ) & 1 ;
return 1 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_77 * V_26 ;
unsigned int V_109 ;
int V_54 ;
if ( ( V_11 -> V_90 & ( V_110 | V_111 ) ) == 0 ) {
F_43 ( V_2 -> V_112 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_113 ) {
F_43 ( V_2 -> V_112 ,
L_2 ) ;
return - V_13 ;
}
V_26 = F_6 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
return - V_14 ;
F_44 ( & V_26 -> V_114 ) ;
V_11 -> V_26 = V_26 ;
V_26 -> V_115 = V_116 * 1024 ;
V_109 = V_117 * 1024 ;
if ( V_109 > V_26 -> V_115 )
V_109 = V_26 -> V_115 ;
if ( F_15 ( V_2 , V_11 , V_109 ) < 0 ) {
F_43 ( V_2 -> V_112 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_118 ) {
V_54 = V_11 -> V_118 ( V_2 , V_11 ) ;
if ( V_54 < 0 )
return V_54 ;
}
F_45 ( V_11 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_54 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_119 )
continue;
if ( V_11 -> type == V_73 ) {
if ( V_11 -> V_22 < 32 )
V_11 -> V_60 = ( 1 << V_11 -> V_22 ) - 1 ;
else
V_11 -> V_60 = 0xffffffff ;
}
if ( V_11 -> V_120 == 0 )
V_11 -> V_120 = 1 ;
if ( V_11 -> V_121 ) {
V_54 = F_42 ( V_2 , V_11 ) ;
if ( V_54 )
return V_54 ;
}
if ( ! V_11 -> V_122 && ! V_11 -> V_123 )
V_11 -> V_122 = & V_124 ;
if ( ! V_11 -> V_24 && V_11 -> V_107 )
V_11 -> V_24 = F_41 ;
if ( ! V_11 -> V_125 && V_11 -> V_107 )
V_11 -> V_125 = F_41 ;
if ( ! V_11 -> V_24 )
V_11 -> V_24 = F_21 ;
if ( ! V_11 -> V_125 )
V_11 -> V_125 = F_21 ;
if ( ! V_11 -> V_107 )
V_11 -> V_107 = F_21 ;
if ( ! V_11 -> V_126 )
V_11 -> V_126 = F_21 ;
if ( ! V_11 -> V_127 )
V_11 -> V_127 = F_20 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_46 ( V_2 ) ;
if ( V_54 < 0 )
return V_54 ;
F_18 ( & V_2 -> V_40 ) ;
V_2 -> V_41 = true ;
F_19 ( & V_2 -> V_40 ) ;
return 0 ;
}
static void * F_48 ( struct V_128 * V_129 , const char * V_130 )
{
char * * V_131 = ( char * * ) V_129 -> V_29 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_129 -> V_132 ; V_12 ++ ) {
if ( strcmp ( * V_131 , V_130 ) == 0 )
return V_131 ;
V_131 = ( void * ) V_131 + V_129 -> V_133 ;
}
return NULL ;
}
static void F_49 ( struct V_128 * V_129 )
{
unsigned int V_12 ;
const char * const * V_131 ;
F_50 ( L_4 ,
V_129 -> V_134 ) ;
V_131 = V_129 -> V_29 ;
for ( V_12 = 0 ; V_12 < V_129 -> V_132 ; V_12 ++ ) {
F_50 ( L_5 , * V_131 ) ;
V_131 = ( const char * * ) ( ( char * ) V_131 + V_129 -> V_133 ) ;
}
if ( V_129 -> V_132 == 0 )
F_50 ( L_5 , V_129 -> V_134 ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_130 ,
int (* F_24)( struct V_1 * V_2 ,
const T_2 * V_46 , T_1 V_6 ,
unsigned long V_50 ) ,
unsigned long V_50 )
{
const struct V_135 * V_136 ;
int V_54 ;
if ( ! F_24 )
return - V_13 ;
V_54 = F_52 ( & V_136 , V_130 , V_3 ) ;
if ( V_54 == 0 ) {
V_54 = F_24 ( V_2 , V_136 -> V_46 , V_136 -> V_6 , V_50 ) ;
F_53 ( V_136 ) ;
}
return V_54 < 0 ? V_54 : 0 ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned long V_137 , unsigned long V_138 )
{
if ( ! V_137 ) {
F_43 ( V_2 -> V_112 ,
L_6 ,
V_2 -> V_29 ) ;
return - V_13 ;
}
if ( ! F_55 ( V_137 , V_138 , V_2 -> V_29 ) ) {
F_43 ( V_2 -> V_112 , L_7 ,
V_2 -> V_29 , V_137 , V_138 ) ;
return - V_139 ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
unsigned long V_137 , unsigned long V_138 )
{
int V_54 ;
V_54 = F_54 ( V_2 , V_137 , V_138 ) ;
if ( V_54 == 0 ) {
V_2 -> V_32 = V_137 ;
V_2 -> V_33 = V_138 ;
}
return V_54 ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 ) {
F_58 ( V_2 -> V_35 , V_2 ) ;
V_2 -> V_35 = 0 ;
}
if ( V_2 -> V_32 && V_2 -> V_33 ) {
F_59 ( V_2 -> V_32 , V_2 -> V_33 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
}
}
int F_60 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_128 * V_129 ;
int V_54 ;
if ( V_2 -> V_41 )
return - V_55 ;
F_61 ( & V_142 ) ;
for ( V_129 = V_143 ; V_129 ; V_129 = V_129 -> V_144 ) {
if ( ! F_62 ( V_129 -> V_145 ) )
continue;
if ( V_129 -> V_132 ) {
V_2 -> V_30 = F_48 ( V_129 , V_141 -> V_29 ) ;
if ( V_2 -> V_30 )
break;
} else if ( strcmp ( V_129 -> V_134 , V_141 -> V_29 ) == 0 ) {
break;
}
F_63 ( V_129 -> V_145 ) ;
}
if ( ! V_129 ) {
for ( V_129 = V_143 ; V_129 ; V_129 = V_129 -> V_144 ) {
if ( ! F_62 ( V_129 -> V_145 ) )
continue;
F_49 ( V_129 ) ;
F_63 ( V_129 -> V_145 ) ;
}
V_54 = - V_139 ;
goto V_146;
}
if ( ! V_129 -> V_147 ) {
F_43 ( V_2 -> V_112 ,
L_8 ,
V_129 -> V_134 ) ;
F_63 ( V_129 -> V_145 ) ;
V_54 = - V_148 ;
goto V_146;
}
V_2 -> V_28 = V_129 ;
V_2 -> V_29 = V_2 -> V_30 ? * ( const char * * ) V_2 -> V_30
: V_2 -> V_28 -> V_134 ;
V_54 = V_129 -> V_147 ( V_2 , V_141 ) ;
if ( V_54 >= 0 )
V_54 = F_47 ( V_2 ) ;
if ( V_54 < 0 ) {
F_16 ( V_2 ) ;
F_63 ( V_129 -> V_145 ) ;
}
V_146:
F_64 ( & V_142 ) ;
return V_54 ;
}
int F_65 ( struct V_3 * V_149 ,
struct V_128 * V_28 , unsigned long V_50 )
{
struct V_1 * V_2 ;
int V_54 ;
if ( ! V_149 ) {
F_66 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_28 ) {
F_43 ( V_149 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_28 -> V_150 ) {
F_43 ( V_149 ,
L_11 ,
V_28 -> V_134 ) ;
return - V_13 ;
}
V_2 = F_67 ( V_149 ) ;
if ( F_68 ( V_2 ) ) {
F_43 ( V_149 ,
L_12 ,
V_28 -> V_134 ) ;
return F_69 ( V_2 ) ;
}
V_2 -> V_28 = V_28 ;
V_2 -> V_29 = V_2 -> V_28 -> V_134 ;
V_54 = V_28 -> V_150 ( V_2 , V_50 ) ;
if ( V_54 >= 0 )
V_54 = F_47 ( V_2 ) ;
F_64 ( & V_2 -> V_151 ) ;
if ( V_54 < 0 ) {
F_43 ( V_149 ,
L_13 ,
V_28 -> V_134 ) ;
F_70 ( V_149 ) ;
} else {
F_71 ( V_2 -> V_112 ,
L_14 ,
V_28 -> V_134 , V_2 -> V_29 ) ;
}
return V_54 ;
}
void F_72 ( struct V_3 * V_149 )
{
if ( ! V_149 )
return;
F_70 ( V_149 ) ;
}
int F_73 ( struct V_128 * V_28 )
{
F_61 ( & V_142 ) ;
V_28 -> V_144 = V_143 ;
V_143 = V_28 ;
F_64 ( & V_142 ) ;
return 0 ;
}
void F_74 ( struct V_128 * V_28 )
{
struct V_128 * V_152 ;
int V_12 ;
F_61 ( & V_142 ) ;
if ( V_143 == V_28 ) {
V_143 = V_28 -> V_144 ;
} else {
for ( V_152 = V_143 ; V_152 -> V_144 ; V_152 = V_152 -> V_144 ) {
if ( V_152 -> V_144 == V_28 ) {
V_152 -> V_144 = V_28 -> V_144 ;
break;
}
}
}
F_64 ( & V_142 ) ;
for ( V_12 = 0 ; V_12 < V_153 ; V_12 ++ ) {
struct V_1 * V_2 = F_75 ( V_12 ) ;
if ( ! V_2 )
continue;
F_61 ( & V_2 -> V_151 ) ;
if ( V_2 -> V_41 && V_2 -> V_28 == V_28 ) {
if ( V_2 -> V_154 )
F_43 ( V_2 -> V_112 ,
L_15 ,
V_2 -> V_154 ) ;
F_16 ( V_2 ) ;
}
F_64 ( & V_2 -> V_151 ) ;
F_76 ( V_2 ) ;
}
}
