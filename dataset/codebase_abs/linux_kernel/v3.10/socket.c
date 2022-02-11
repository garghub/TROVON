static int F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( V_3 ) {
V_2 -> V_3 = NULL ;
V_3 -> V_4 -> V_5 ( V_3 , 0 ) ;
}
return 0 ;
}
void T_1 F_2 ( void )
{
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
F_3 ( V_8 . V_9 + V_6 ) ;
F_4 ( & V_8 . V_10 ) ;
}
static struct V_11 * F_5 ( T_2 V_12 )
{
return V_8 . V_9 + ( V_12 & V_13 ) ;
}
struct V_2 * F_6 ( struct V_14 * V_14 , const struct V_15 * V_16 )
{
struct V_2 * V_17 ;
struct V_2 * V_18 = NULL ;
T_2 V_12 = F_7 ( V_16 ) ;
T_3 V_19 = V_16 -> V_20 ;
struct V_11 * V_9 = F_5 ( V_12 ) ;
F_8 () ;
F_9 (sknode, hlist) {
struct V_21 * V_22 = F_10 ( V_17 ) ;
F_11 ( ! V_22 -> V_23 ) ;
if ( ! F_12 ( F_13 ( V_17 ) , V_14 ) )
continue;
if ( F_14 ( V_12 ) ) {
if ( F_14 ( V_22 -> V_23 ) != F_14 ( V_12 ) )
continue;
} else {
if ( V_22 -> V_24 != V_19 )
continue;
}
if ( F_15 ( V_22 -> V_23 ) &&
F_15 ( V_22 -> V_23 ) != F_15 ( V_12 ) )
continue;
V_18 = V_17 ;
F_16 ( V_17 ) ;
break;
}
F_17 () ;
return V_18 ;
}
void F_18 ( struct V_14 * V_14 , struct V_25 * V_26 )
{
struct V_11 * V_9 = V_8 . V_9 ;
unsigned int V_27 ;
F_8 () ;
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ ) {
struct V_2 * V_17 ;
F_19 (sknode, hlist) {
struct V_25 * V_28 ;
if ( ! F_12 ( F_13 ( V_17 ) , V_14 ) )
continue;
if ( ! F_20 ( V_17 , V_29 ) )
continue;
V_28 = F_21 ( V_26 , V_30 ) ;
if ( V_28 ) {
F_16 ( V_17 ) ;
F_22 ( V_17 , V_28 , 0 ) ;
}
}
V_9 ++ ;
}
F_17 () ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_11 * V_9 = F_5 ( F_10 ( V_3 ) -> V_23 ) ;
F_24 ( & V_8 . V_10 ) ;
F_25 ( V_3 , V_9 ) ;
F_26 ( & V_8 . V_10 ) ;
}
void F_27 ( struct V_2 * V_3 )
{
F_24 ( & V_8 . V_10 ) ;
F_28 ( V_3 ) ;
F_26 ( & V_8 . V_10 ) ;
F_29 ( V_3 ) ;
F_30 () ;
}
static int F_31 ( struct V_1 * V_2 , struct V_31 * V_32 , int V_33 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_32 ;
int V_34 ;
T_2 V_35 ;
T_3 V_36 ;
if ( V_3 -> V_4 -> V_37 )
return V_3 -> V_4 -> V_37 ( V_3 , V_32 , V_33 ) ;
if ( V_33 < sizeof( struct V_15 ) )
return - V_38 ;
if ( V_16 -> V_39 != V_40 )
return - V_41 ;
V_35 = F_7 ( (struct V_15 * ) V_32 ) ;
V_36 = F_15 ( V_35 ) ;
if ( V_36 && F_32 ( F_13 ( V_3 ) , V_36 ) )
return - V_42 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_43 != V_44 || F_14 ( V_22 -> V_23 ) ) {
V_34 = - V_38 ;
goto V_45;
}
F_34 ( F_35 ( V_3 ) ) ;
F_24 ( & V_46 ) ;
V_34 = V_3 -> V_4 -> V_47 ( V_3 , F_14 ( V_35 ) ) ;
if ( V_34 )
goto V_48;
V_22 -> V_23 = F_36 ( V_36 , F_14 ( V_22 -> V_23 ) ) ;
V_22 -> V_24 = V_16 -> V_20 ;
V_3 -> V_4 -> V_49 ( V_3 ) ;
V_48:
F_26 ( & V_46 ) ;
V_45:
F_37 ( V_3 ) ;
return V_34 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_15 V_50 ;
int V_34 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_39 = V_40 ;
V_34 = F_31 ( V_2 , (struct V_31 * ) & V_50 ,
sizeof( struct V_15 ) ) ;
if ( V_34 != - V_38 )
return V_34 ;
F_11 ( ! F_14 ( F_10 ( V_2 -> V_3 ) -> V_23 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_31 * V_32 ,
int V_33 , int V_51 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_32 ;
struct V_52 * V_53 = V_54 ;
long V_55 = F_40 ( V_3 , V_51 & V_56 ) ;
int V_34 ;
if ( F_38 ( V_2 ) )
return - V_57 ;
if ( V_33 < sizeof( struct V_15 ) )
return - V_38 ;
if ( V_16 -> V_39 != V_40 )
return - V_41 ;
F_33 ( V_3 ) ;
switch ( V_2 -> V_58 ) {
case V_59 :
if ( V_3 -> V_43 != V_44 ) {
V_34 = - V_60 ;
goto V_45;
}
break;
case V_61 :
V_34 = - V_62 ;
goto V_45;
default:
V_34 = - V_60 ;
goto V_45;
}
V_22 -> V_63 = F_7 ( V_16 ) ;
V_22 -> V_24 = F_41 ( V_16 ) ;
V_2 -> V_58 = V_61 ;
V_34 = V_3 -> V_4 -> V_64 ( V_3 , V_32 , V_33 ) ;
if ( V_34 ) {
V_2 -> V_58 = V_59 ;
V_22 -> V_63 = 0 ;
goto V_45;
}
while ( V_3 -> V_43 == V_65 ) {
F_42 ( V_66 ) ;
if ( ! V_55 ) {
V_34 = - V_67 ;
goto V_45;
}
if ( F_43 ( V_53 ) ) {
V_34 = F_44 ( V_55 ) ;
goto V_45;
}
F_45 ( F_46 ( V_3 ) , & V_66 ,
V_68 ) ;
F_37 ( V_3 ) ;
V_55 = F_47 ( V_55 ) ;
F_33 ( V_3 ) ;
F_48 ( F_46 ( V_3 ) , & V_66 ) ;
}
if ( ( 1 << V_3 -> V_43 ) & ( V_69 | V_70 ) )
V_34 = 0 ;
else if ( V_3 -> V_43 == V_71 )
V_34 = - V_72 ;
else
V_34 = - V_73 ;
V_2 -> V_58 = V_34 ? V_59 : V_74 ;
V_45:
F_37 ( V_3 ) ;
return V_34 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_1 * V_75 ,
int V_51 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_2 * V_76 ;
int V_34 ;
if ( F_50 ( V_3 -> V_43 != V_77 ) )
return - V_38 ;
V_76 = V_3 -> V_4 -> V_78 ( V_3 , V_51 , & V_34 ) ;
if ( ! V_76 )
return V_34 ;
F_33 ( V_76 ) ;
F_51 ( V_76 , V_75 ) ;
V_75 -> V_58 = V_74 ;
F_37 ( V_76 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_31 * V_32 ,
int * V_79 , int V_80 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
memset ( V_32 , 0 , sizeof( struct V_15 ) ) ;
V_32 -> V_81 = V_40 ;
if ( ! V_80 )
F_53 ( (struct V_15 * ) V_32 ,
V_22 -> V_23 ) ;
* V_79 = sizeof( struct V_15 ) ;
return 0 ;
}
static unsigned int F_54 ( struct V_82 * V_82 , struct V_1 * V_2 ,
T_4 * V_66 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_83 * V_22 = F_55 ( V_3 ) ;
unsigned int V_84 = 0 ;
F_56 ( V_82 , F_46 ( V_3 ) , V_66 ) ;
if ( V_3 -> V_43 == V_44 )
return V_85 ;
if ( ! F_57 ( & V_3 -> V_86 ) )
V_84 |= V_87 | V_88 ;
if ( ! F_57 ( & V_22 -> V_89 ) )
V_84 |= V_90 ;
if ( ! V_84 && V_3 -> V_43 == V_71 )
return V_91 ;
if ( V_3 -> V_43 == V_92 &&
F_58 ( & V_3 -> V_93 ) < V_3 -> V_94 &&
F_58 ( & V_22 -> V_95 ) )
V_84 |= V_96 | V_97 | V_98 ;
return V_84 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_99 ,
unsigned long V_100 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
if ( V_99 == V_101 ) {
struct V_102 * V_103 ;
T_2 V_35 ;
T_3 V_36 ;
if ( F_60 ( V_35 , ( V_104 V_105 * ) V_100 ) )
return - V_106 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_107 )
V_103 = F_61 ( F_13 ( V_3 ) ,
V_3 -> V_107 ) ;
else
V_103 = F_62 ( F_13 ( V_3 ) ) ;
if ( V_103 && ( V_103 -> V_51 & V_108 ) )
V_36 = F_63 ( V_103 , F_15 ( V_35 ) ) ;
else
V_36 = V_109 ;
F_37 ( V_3 ) ;
if ( V_103 )
F_64 ( V_103 ) ;
if ( V_36 == V_109 )
return - V_110 ;
V_35 = F_36 ( V_36 , F_14 ( V_22 -> V_23 ) ) ;
return F_65 ( V_35 , ( V_104 V_105 * ) V_100 ) ;
}
return V_3 -> V_4 -> V_111 ( V_3 , V_99 , V_100 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_112 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_34 = 0 ;
if ( F_38 ( V_2 ) )
return - V_57 ;
F_33 ( V_3 ) ;
if ( V_2 -> V_58 != V_59 ) {
V_34 = - V_38 ;
goto V_45;
}
if ( V_3 -> V_43 != V_77 ) {
V_3 -> V_43 = V_77 ;
V_3 -> V_113 = 0 ;
}
V_3 -> V_114 = V_112 ;
V_45:
F_37 ( V_3 ) ;
return V_34 ;
}
static int F_67 ( struct V_115 * V_116 , struct V_1 * V_2 ,
struct V_117 * V_118 , T_5 V_119 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( F_38 ( V_2 ) )
return - V_120 ;
return V_3 -> V_4 -> V_121 ( V_116 , V_3 , V_118 , V_119 ) ;
}
int F_68 ( struct V_2 * V_3 , unsigned short V_122 )
{
static int V_123 ;
struct V_14 * V_14 = F_13 ( V_3 ) ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
struct V_15 V_124 ;
struct V_2 * V_125 ;
memset ( & V_124 , 0 , sizeof( struct V_15 ) ) ;
V_124 . V_39 = V_40 ;
F_34 ( ! F_69 ( & V_46 ) ) ;
if ( ! V_122 ) {
int V_126 , V_127 , V_128 ;
F_70 ( & V_127 , & V_128 ) ;
for ( V_126 = V_127 ; V_126 <= V_128 ; V_126 ++ ) {
V_123 ++ ;
if ( V_123 < V_127 || V_123 > V_128 )
V_123 = V_127 ;
F_71 ( & V_124 , V_123 ) ;
V_125 = F_6 ( V_14 , & V_124 ) ;
if ( V_125 == NULL ) {
V_122 = V_123 ;
goto V_129;
} else
F_72 ( V_125 ) ;
}
} else {
F_71 ( & V_124 , V_122 ) ;
V_125 = F_6 ( V_14 , & V_124 ) ;
if ( V_125 == NULL )
goto V_129;
else
F_72 ( V_125 ) ;
}
return - V_130 ;
V_129:
V_22 -> V_23 = F_36 ( F_15 ( V_22 -> V_23 ) , V_122 ) ;
return 0 ;
}
static struct V_2 * F_73 ( struct V_131 * V_132 , T_6 V_133 )
{
struct V_14 * V_14 = F_74 ( V_132 ) ;
struct V_11 * V_9 = V_8 . V_9 ;
struct V_2 * V_17 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ ) {
F_9 (sknode, hlist) {
if ( ! F_12 ( V_14 , F_13 ( V_17 ) ) )
continue;
if ( ! V_133 )
return V_17 ;
V_133 -- ;
}
V_9 ++ ;
}
return NULL ;
}
static struct V_2 * F_75 ( struct V_131 * V_132 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_74 ( V_132 ) ;
do
V_3 = F_76 ( V_3 ) ;
while ( V_3 && ! F_12 ( V_14 , F_13 ( V_3 ) ) );
return V_3 ;
}
static void * F_77 ( struct V_131 * V_132 , T_6 * V_133 )
__acquires( T_7 )
{
F_8 () ;
return * V_133 ? F_73 ( V_132 , * V_133 - 1 ) : V_134 ;
}
static void * F_78 ( struct V_131 * V_132 , void * V_135 , T_6 * V_133 )
{
struct V_2 * V_3 ;
if ( V_135 == V_134 )
V_3 = F_73 ( V_132 , 0 ) ;
else
V_3 = F_75 ( V_132 , V_135 ) ;
( * V_133 ) ++ ;
return V_3 ;
}
static void F_79 ( struct V_131 * V_132 , void * V_135 )
__releases( T_7 )
{
F_17 () ;
}
static int F_80 ( struct V_131 * V_132 , void * V_135 )
{
int V_33 ;
if ( V_135 == V_134 )
F_81 ( V_132 , L_1 , L_2
L_3 , & V_33 ) ;
else {
struct V_2 * V_3 = V_135 ;
struct V_21 * V_22 = F_10 ( V_3 ) ;
F_81 ( V_132 , L_4
L_5 ,
V_3 -> V_136 , V_22 -> V_23 , V_22 -> V_63 ,
V_22 -> V_24 , V_3 -> V_43 ,
F_82 ( V_3 ) , F_83 ( V_3 ) ,
F_84 ( F_85 ( V_132 ) , F_86 ( V_3 ) ) ,
F_87 ( V_3 ) ,
F_58 ( & V_3 -> V_137 ) , V_3 ,
F_58 ( & V_3 -> V_138 ) , & V_33 ) ;
}
F_81 ( V_132 , L_6 , 127 - V_33 , L_7 ) ;
return 0 ;
}
static int F_88 ( struct V_139 * V_139 , struct V_82 * V_82 )
{
return F_89 ( V_139 , V_82 , & V_140 ,
sizeof( struct V_141 ) ) ;
}
struct V_2 * F_90 ( struct V_14 * V_14 , T_3 V_19 )
{
struct V_2 * V_3 ;
if ( ! F_12 ( V_14 , & V_142 ) )
return NULL ;
F_8 () ;
V_3 = F_91 ( V_143 . V_3 [ V_19 ] ) ;
if ( V_3 )
F_16 ( V_3 ) ;
F_17 () ;
return V_3 ;
}
int F_92 ( struct V_2 * V_3 , T_3 V_19 )
{
int V_144 = - V_130 ;
if ( ! F_12 ( F_13 ( V_3 ) , & V_142 ) )
return - V_145 ;
if ( ! F_93 ( V_146 ) )
return - V_147 ;
if ( F_38 ( V_3 -> V_148 ) )
return - V_120 ;
F_24 ( & V_149 ) ;
if ( V_143 . V_3 [ V_19 ] == NULL ) {
F_16 ( V_3 ) ;
F_94 ( V_143 . V_3 [ V_19 ] , V_3 ) ;
V_144 = 0 ;
}
F_26 ( & V_149 ) ;
return V_144 ;
}
int F_95 ( struct V_2 * V_3 , T_3 V_19 )
{
int V_144 = - V_150 ;
if ( ! F_93 ( V_146 ) )
return - V_147 ;
F_24 ( & V_149 ) ;
if ( V_143 . V_3 [ V_19 ] == V_3 ) {
F_96 ( V_143 . V_3 [ V_19 ] , NULL ) ;
V_144 = 0 ;
}
F_26 ( & V_149 ) ;
if ( V_144 == 0 ) {
F_30 () ;
F_72 ( V_3 ) ;
}
return V_144 ;
}
void F_29 ( struct V_2 * V_3 )
{
unsigned int V_19 , V_151 = 0 ;
F_24 ( & V_149 ) ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 ++ ) {
if ( V_143 . V_3 [ V_19 ] == V_3 ) {
F_96 ( V_143 . V_3 [ V_19 ] , NULL ) ;
V_151 ++ ;
}
}
F_26 ( & V_149 ) ;
while ( V_151 > 0 ) {
F_97 ( V_3 ) ;
V_151 -- ;
}
}
static struct V_2 * * F_98 ( struct V_131 * V_132 , T_6 V_133 )
{
struct V_14 * V_14 = F_74 ( V_132 ) ;
unsigned int V_6 ;
if ( ! F_12 ( V_14 , & V_142 ) )
return NULL ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
if ( V_143 . V_3 [ V_6 ] == NULL )
continue;
if ( ! V_133 )
return V_143 . V_3 + V_6 ;
V_133 -- ;
}
return NULL ;
}
static struct V_2 * * F_99 ( struct V_131 * V_132 , struct V_2 * * V_3 )
{
struct V_14 * V_14 = F_74 ( V_132 ) ;
unsigned int V_6 ;
F_11 ( ! F_12 ( V_14 , & V_142 ) ) ;
for ( V_6 = ( V_3 - V_143 . V_3 ) + 1 ; V_6 < 256 ; V_6 ++ )
if ( V_143 . V_3 [ V_6 ] )
return V_143 . V_3 + V_6 ;
return NULL ;
}
static void * F_100 ( struct V_131 * V_132 , T_6 * V_133 )
__acquires( V_149 )
{
F_24 ( & V_149 ) ;
return * V_133 ? F_98 ( V_132 , * V_133 - 1 ) : V_134 ;
}
static void * F_101 ( struct V_131 * V_132 , void * V_135 , T_6 * V_133 )
{
struct V_2 * * V_3 ;
if ( V_135 == V_134 )
V_3 = F_98 ( V_132 , 0 ) ;
else
V_3 = F_99 ( V_132 , V_135 ) ;
( * V_133 ) ++ ;
return V_3 ;
}
static void F_102 ( struct V_131 * V_132 , void * V_135 )
__releases( V_149 )
{
F_26 ( & V_149 ) ;
}
static int F_103 ( struct V_131 * V_132 , void * V_135 )
{
int V_33 ;
if ( V_135 == V_134 )
F_81 ( V_132 , L_1 , L_8 , & V_33 ) ;
else {
struct V_2 * * V_152 = V_135 ;
struct V_2 * V_3 = * V_152 ;
F_81 ( V_132 , L_9 ,
( int ) ( V_152 - V_143 . V_3 ) ,
F_84 ( F_85 ( V_132 ) , F_86 ( V_3 ) ) ,
F_87 ( V_3 ) , & V_33 ) ;
}
F_81 ( V_132 , L_6 , 63 - V_33 , L_7 ) ;
return 0 ;
}
static int F_104 ( struct V_139 * V_139 , struct V_82 * V_82 )
{
return F_89 ( V_139 , V_82 , & V_153 ,
sizeof( struct V_141 ) ) ;
}
