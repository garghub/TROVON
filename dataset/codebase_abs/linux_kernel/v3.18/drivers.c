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
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_12 ;
struct V_10 * V_11 ;
if ( V_2 -> V_15 ) {
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> V_24 & V_25 )
F_12 ( V_11 -> V_7 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_26 ) {
F_14 ( V_2 , V_11 , 0 ) ;
F_12 ( V_11 -> V_26 ) ;
}
F_12 ( V_11 -> V_23 ) ;
}
F_12 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = 0 ;
}
F_12 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_27 = NULL ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = NULL ;
V_2 -> V_30 = NULL ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = false ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = NULL ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = NULL ;
F_3 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_39 ) ;
V_2 -> V_40 = false ;
V_2 -> V_41 ++ ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_42 ( V_2 ) ;
F_11 ( V_2 ) ;
F_18 ( & V_2 -> V_39 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
return - V_13 ;
}
int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_43 * V_44 , unsigned int * V_45 )
{
return - V_13 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
unsigned int V_46 = F_22 ( V_44 -> V_47 ) ;
int V_12 ;
if ( ! V_11 -> V_23 )
return - V_13 ;
for ( V_12 = 0 ; V_12 < V_44 -> V_48 ; V_12 ++ )
V_45 [ V_12 ] = V_11 -> V_23 [ V_46 ] ;
return V_44 -> V_48 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_43 * V_44 ,
int (* F_24)( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_43 * V_44 ,
unsigned long V_49 ) ,
unsigned long V_49 )
{
unsigned long V_50 = V_51 + F_25 ( V_52 ) ;
int V_53 ;
while ( F_26 ( V_51 , V_50 ) ) {
V_53 = F_24 ( V_2 , V_11 , V_44 , V_49 ) ;
if ( V_53 != - V_54 )
return V_53 ;
F_27 () ;
}
return - V_55 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_43 * V_44 ,
unsigned int * V_45 ,
unsigned int V_56 )
{
unsigned int V_57 = 1 << F_22 ( V_44 -> V_47 ) ;
if ( ! V_56 )
V_56 = V_57 ;
switch ( V_45 [ 0 ] ) {
case V_58 :
V_11 -> V_59 &= ~ V_56 ;
break;
case V_60 :
V_11 -> V_59 |= V_56 ;
break;
case V_61 :
V_45 [ 1 ] = ( V_11 -> V_59 & V_56 ) ? V_62 : V_63 ;
return V_44 -> V_48 ;
default:
return - V_13 ;
}
return 0 ;
}
unsigned int F_29 ( struct V_10 * V_11 ,
unsigned int * V_45 )
{
unsigned int V_64 = ( V_11 -> V_22 < 32 ) ? ( ( 1 << V_11 -> V_22 ) - 1 )
: 0xffffffff ;
unsigned int V_56 = V_45 [ 0 ] & V_64 ;
unsigned int V_65 = V_45 [ 1 ] ;
if ( V_56 ) {
V_11 -> V_66 &= ~ V_56 ;
V_11 -> V_66 |= ( V_65 & V_56 ) ;
}
return V_56 ;
}
unsigned int F_30 ( struct V_10 * V_11 )
{
struct V_67 * V_68 = & V_11 -> V_26 -> V_68 ;
unsigned int V_69 ;
unsigned int V_70 ;
switch ( V_11 -> type ) {
case V_71 :
case V_72 :
case V_73 :
V_70 = 8 * F_31 ( V_11 ) ;
V_69 = ( V_68 -> V_74 + V_70 - 1 ) /
V_70 ;
break;
default:
V_69 = V_68 -> V_74 ;
break;
}
return V_69 * F_31 ( V_11 ) ;
}
void F_32 ( struct V_10 * V_11 ,
unsigned int V_75 )
{
struct V_76 * V_26 = V_11 -> V_26 ;
unsigned int V_77 = F_30 ( V_11 ) ;
V_26 -> V_78 += V_75 ;
if ( V_26 -> V_78 >= V_77 ) {
V_26 -> V_78 %= V_77 ;
V_26 -> V_79 |= V_80 ;
}
}
unsigned int F_33 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
unsigned int V_79 = V_11 -> V_26 -> V_79 ;
if ( V_79 == 0 )
return V_79 ;
if ( V_79 & ( V_81 | V_82 | V_83 ) )
V_11 -> V_84 ( V_2 , V_11 ) ;
F_34 ( V_2 , V_11 ) ;
return V_79 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_43 * V_44 , unsigned int * V_45 )
{
struct V_43 V_85 ;
int V_53 ;
static const unsigned V_86 = 32 ;
unsigned V_46 = F_22 ( V_44 -> V_47 ) ;
const unsigned V_87 =
( V_46 < V_86 ) ? 0 : V_46 ;
unsigned int V_88 [ 2 ] ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_44 = V_89 ;
V_85 . V_47 = V_87 ;
V_85 . V_48 = 2 ;
V_85 . V_90 = V_44 -> V_90 ;
if ( V_44 -> V_44 == V_91 ) {
if ( ! ( V_11 -> V_92 & V_93 ) )
return - V_13 ;
V_88 [ 0 ] = 1 << ( V_46 - V_87 ) ;
V_88 [ 1 ] = V_45 [ 0 ] ? ( 1 << ( V_46 - V_87 ) )
: 0 ;
}
V_53 = V_11 -> V_94 ( V_2 , V_11 , & V_85 , V_88 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_44 -> V_44 == V_95 )
V_45 [ 0 ] = ( V_88 [ 1 ] >> ( V_46 - V_87 ) ) & 1 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_76 * V_26 ;
unsigned int V_96 ;
int V_53 ;
if ( ( V_11 -> V_92 & ( V_97 | V_98 ) ) == 0 ) {
F_37 ( V_2 -> V_99 ,
L_1 ) ;
return - V_13 ;
}
if ( ! V_11 -> V_100 ) {
F_37 ( V_2 -> V_99 ,
L_2 ) ;
return - V_13 ;
}
V_26 = F_6 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
return - V_14 ;
F_38 ( & V_26 -> V_101 ) ;
V_11 -> V_26 = V_26 ;
V_26 -> V_102 = V_103 * 1024 ;
V_96 = V_104 * 1024 ;
if ( V_96 > V_26 -> V_102 )
V_96 = V_26 -> V_102 ;
if ( F_14 ( V_2 , V_11 , V_96 ) < 0 ) {
F_37 ( V_2 -> V_99 , L_3 ) ;
return - V_14 ;
}
if ( V_11 -> V_105 ) {
V_53 = V_11 -> V_105 ( V_2 , V_11 ) ;
if ( V_53 < 0 )
return V_53 ;
}
F_39 ( V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_53 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_2 -> V_16 ; V_12 ++ ) {
V_11 = & V_2 -> V_15 [ V_12 ] ;
if ( V_11 -> type == V_106 )
continue;
if ( V_11 -> type == V_72 ) {
if ( V_11 -> V_22 < 32 )
V_11 -> V_59 = ( 1 << V_11 -> V_22 ) - 1 ;
else
V_11 -> V_59 = 0xffffffff ;
}
if ( V_11 -> V_107 == 0 )
V_11 -> V_107 = 1 ;
if ( V_11 -> V_108 ) {
V_53 = F_36 ( V_2 , V_11 ) ;
if ( V_53 )
return V_53 ;
}
if ( ! V_11 -> V_109 && ! V_11 -> V_110 )
V_11 -> V_109 = & V_111 ;
if ( ! V_11 -> V_112 && V_11 -> V_94 )
V_11 -> V_112 = F_35 ;
if ( ! V_11 -> V_113 && V_11 -> V_94 )
V_11 -> V_113 = F_35 ;
if ( ! V_11 -> V_112 )
V_11 -> V_112 = F_20 ;
if ( ! V_11 -> V_113 )
V_11 -> V_113 = F_20 ;
if ( ! V_11 -> V_94 )
V_11 -> V_94 = F_20 ;
if ( ! V_11 -> V_114 )
V_11 -> V_114 = F_20 ;
if ( ! V_11 -> V_115 )
V_11 -> V_115 = F_19 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_53 ;
V_53 = F_40 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
F_17 ( & V_2 -> V_39 ) ;
V_2 -> V_40 = true ;
F_18 ( & V_2 -> V_39 ) ;
return 0 ;
}
static void * F_42 ( struct V_116 * V_117 , const char * V_118 )
{
char * * V_119 = ( char * * ) V_117 -> V_28 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_117 -> V_120 ; V_12 ++ ) {
if ( strcmp ( * V_119 , V_118 ) == 0 )
return V_119 ;
V_119 = ( void * ) V_119 + V_117 -> V_121 ;
}
return NULL ;
}
static void F_43 ( struct V_116 * V_117 )
{
unsigned int V_12 ;
const char * const * V_119 ;
F_44 ( L_4 ,
V_117 -> V_122 ) ;
V_119 = V_117 -> V_28 ;
for ( V_12 = 0 ; V_12 < V_117 -> V_120 ; V_12 ++ ) {
F_44 ( L_5 , * V_119 ) ;
V_119 = ( const char * * ) ( ( char * ) V_119 + V_117 -> V_121 ) ;
}
if ( V_117 -> V_120 == 0 )
F_44 ( L_5 , V_117 -> V_122 ) ;
}
int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
const char * V_118 ,
int (* F_24)( struct V_1 * V_2 ,
const T_2 * V_45 , T_1 V_6 ,
unsigned long V_49 ) ,
unsigned long V_49 )
{
const struct V_123 * V_124 ;
int V_53 ;
if ( ! F_24 )
return - V_13 ;
V_53 = F_46 ( & V_124 , V_118 , V_3 ) ;
if ( V_53 == 0 ) {
V_53 = F_24 ( V_2 , V_124 -> V_45 , V_124 -> V_6 , V_49 ) ;
F_47 ( V_124 ) ;
}
return V_53 < 0 ? V_53 : 0 ;
}
int F_48 ( struct V_1 * V_2 ,
unsigned long V_125 , unsigned long V_126 )
{
if ( ! V_125 ) {
F_37 ( V_2 -> V_99 ,
L_6 ,
V_2 -> V_28 ) ;
return - V_13 ;
}
if ( ! F_49 ( V_125 , V_126 , V_2 -> V_28 ) ) {
F_37 ( V_2 -> V_99 , L_7 ,
V_2 -> V_28 , V_125 , V_126 ) ;
return - V_127 ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned long V_125 , unsigned long V_126 )
{
int V_53 ;
V_53 = F_48 ( V_2 , V_125 , V_126 ) ;
if ( V_53 == 0 ) {
V_2 -> V_31 = V_125 ;
V_2 -> V_32 = V_126 ;
}
return V_53 ;
}
void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 ) {
F_52 ( V_2 -> V_34 , V_2 ) ;
V_2 -> V_34 = 0 ;
}
if ( V_2 -> V_31 && V_2 -> V_32 ) {
F_53 ( V_2 -> V_31 , V_2 -> V_32 ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 0 ;
}
}
int F_54 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
struct V_116 * V_117 ;
int V_53 ;
if ( V_2 -> V_40 )
return - V_54 ;
F_55 ( & V_130 ) ;
for ( V_117 = V_131 ; V_117 ; V_117 = V_117 -> V_132 ) {
if ( ! F_56 ( V_117 -> V_133 ) )
continue;
if ( V_117 -> V_120 ) {
V_2 -> V_29 = F_42 ( V_117 , V_129 -> V_28 ) ;
if ( V_2 -> V_29 )
break;
} else if ( strcmp ( V_117 -> V_122 , V_129 -> V_28 ) == 0 ) {
break;
}
F_57 ( V_117 -> V_133 ) ;
}
if ( V_117 == NULL ) {
for ( V_117 = V_131 ; V_117 ; V_117 = V_117 -> V_132 ) {
if ( ! F_56 ( V_117 -> V_133 ) )
continue;
F_43 ( V_117 ) ;
F_57 ( V_117 -> V_133 ) ;
}
V_53 = - V_127 ;
goto V_134;
}
if ( V_117 -> V_135 == NULL ) {
F_37 ( V_2 -> V_99 ,
L_8 ,
V_117 -> V_122 ) ;
F_57 ( V_117 -> V_133 ) ;
V_53 = - V_136 ;
goto V_134;
}
V_2 -> V_27 = V_117 ;
V_2 -> V_28 = V_2 -> V_29 ? * ( const char * * ) V_2 -> V_29
: V_2 -> V_27 -> V_122 ;
V_53 = V_117 -> V_135 ( V_2 , V_129 ) ;
if ( V_53 >= 0 )
V_53 = F_41 ( V_2 ) ;
if ( V_53 < 0 ) {
F_15 ( V_2 ) ;
F_57 ( V_117 -> V_133 ) ;
}
V_134:
F_58 ( & V_130 ) ;
return V_53 ;
}
int F_59 ( struct V_3 * V_137 ,
struct V_116 * V_27 , unsigned long V_49 )
{
struct V_1 * V_2 ;
int V_53 ;
if ( ! V_137 ) {
F_60 ( L_9 ) ;
return - V_13 ;
}
if ( ! V_27 ) {
F_37 ( V_137 ,
L_10 ) ;
return - V_13 ;
}
if ( ! V_27 -> V_138 ) {
F_37 ( V_137 ,
L_11 ,
V_27 -> V_122 ) ;
return - V_13 ;
}
V_2 = F_61 ( V_137 ) ;
if ( F_62 ( V_2 ) ) {
F_37 ( V_137 ,
L_12 ,
V_27 -> V_122 ) ;
return F_63 ( V_2 ) ;
}
V_2 -> V_27 = V_27 ;
V_2 -> V_28 = V_2 -> V_27 -> V_122 ;
V_53 = V_27 -> V_138 ( V_2 , V_49 ) ;
if ( V_53 >= 0 )
V_53 = F_41 ( V_2 ) ;
F_58 ( & V_2 -> V_139 ) ;
if ( V_53 < 0 ) {
F_37 ( V_137 ,
L_13 ,
V_27 -> V_122 ) ;
F_64 ( V_137 ) ;
} else {
F_65 ( V_2 -> V_99 ,
L_14 ,
V_27 -> V_122 , V_2 -> V_28 ) ;
}
return V_53 ;
}
void F_66 ( struct V_3 * V_137 )
{
if ( V_137 == NULL )
return;
F_64 ( V_137 ) ;
}
int F_67 ( struct V_116 * V_27 )
{
F_55 ( & V_130 ) ;
V_27 -> V_132 = V_131 ;
V_131 = V_27 ;
F_58 ( & V_130 ) ;
return 0 ;
}
void F_68 ( struct V_116 * V_27 )
{
struct V_116 * V_140 ;
int V_12 ;
F_55 ( & V_130 ) ;
if ( V_131 == V_27 ) {
V_131 = V_27 -> V_132 ;
} else {
for ( V_140 = V_131 ; V_140 -> V_132 ; V_140 = V_140 -> V_132 ) {
if ( V_140 -> V_132 == V_27 ) {
V_140 -> V_132 = V_27 -> V_132 ;
break;
}
}
}
F_58 ( & V_130 ) ;
for ( V_12 = 0 ; V_12 < V_141 ; V_12 ++ ) {
struct V_1 * V_2 = F_69 ( V_12 ) ;
if ( ! V_2 )
continue;
F_55 ( & V_2 -> V_139 ) ;
if ( V_2 -> V_40 && V_2 -> V_27 == V_27 ) {
if ( V_2 -> V_142 )
F_37 ( V_2 -> V_99 ,
L_15 ,
V_2 -> V_142 ) ;
F_15 ( V_2 ) ;
}
F_58 ( & V_2 -> V_139 ) ;
F_70 ( V_2 ) ;
}
}
