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
unsigned V_6 ;
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
struct V_17 * V_18 ;
struct V_2 * V_19 ;
struct V_2 * V_20 = NULL ;
T_2 V_12 = F_7 ( V_16 ) ;
T_3 V_21 = V_16 -> V_22 ;
struct V_11 * V_9 = F_5 ( V_12 ) ;
F_8 () ;
F_9 (sknode, node, hlist) {
struct V_23 * V_24 = F_10 ( V_19 ) ;
F_11 ( ! V_24 -> V_25 ) ;
if ( ! F_12 ( F_13 ( V_19 ) , V_14 ) )
continue;
if ( F_14 ( V_12 ) ) {
if ( F_14 ( V_24 -> V_25 ) != F_14 ( V_12 ) )
continue;
} else {
if ( V_24 -> V_26 != V_21 )
continue;
}
if ( F_15 ( V_24 -> V_25 ) &&
F_15 ( V_24 -> V_25 ) != F_15 ( V_12 ) )
continue;
V_20 = V_19 ;
F_16 ( V_19 ) ;
break;
}
F_17 () ;
return V_20 ;
}
void F_18 ( struct V_14 * V_14 , struct V_27 * V_28 )
{
struct V_11 * V_9 = V_8 . V_9 ;
unsigned V_29 ;
F_8 () ;
for ( V_29 = 0 ; V_29 < V_7 ; V_29 ++ ) {
struct V_17 * V_18 ;
struct V_2 * V_19 ;
F_19 (sknode, node, hlist) {
struct V_27 * V_30 ;
if ( ! F_12 ( F_13 ( V_19 ) , V_14 ) )
continue;
if ( ! F_20 ( V_19 , V_31 ) )
continue;
V_30 = F_21 ( V_28 , V_32 ) ;
if ( V_30 ) {
F_16 ( V_19 ) ;
F_22 ( V_19 , V_30 , 0 ) ;
}
}
V_9 ++ ;
}
F_17 () ;
}
void F_23 ( struct V_2 * V_3 )
{
struct V_11 * V_9 = F_5 ( F_10 ( V_3 ) -> V_25 ) ;
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
static int F_31 ( struct V_1 * V_2 , struct V_33 * V_34 , int V_35 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_34 ;
int V_36 ;
T_2 V_37 ;
T_3 V_38 ;
if ( V_3 -> V_4 -> V_39 )
return V_3 -> V_4 -> V_39 ( V_3 , V_34 , V_35 ) ;
if ( V_35 < sizeof( struct V_15 ) )
return - V_40 ;
if ( V_16 -> V_41 != V_42 )
return - V_43 ;
V_37 = F_7 ( (struct V_15 * ) V_34 ) ;
V_38 = F_15 ( V_37 ) ;
if ( V_38 && F_32 ( F_13 ( V_3 ) , V_38 ) )
return - V_44 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_45 != V_46 || F_14 ( V_24 -> V_25 ) ) {
V_36 = - V_40 ;
goto V_47;
}
F_34 ( F_35 ( V_3 ) ) ;
F_24 ( & V_48 ) ;
V_36 = V_3 -> V_4 -> V_49 ( V_3 , F_14 ( V_37 ) ) ;
if ( V_36 )
goto V_50;
V_24 -> V_25 = F_36 ( V_38 , F_14 ( V_24 -> V_25 ) ) ;
V_24 -> V_26 = V_16 -> V_22 ;
V_3 -> V_4 -> V_51 ( V_3 ) ;
V_50:
F_26 ( & V_48 ) ;
V_47:
F_37 ( V_3 ) ;
return V_36 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_15 V_52 ;
int V_36 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_41 = V_42 ;
V_36 = F_31 ( V_2 , (struct V_33 * ) & V_52 ,
sizeof( struct V_15 ) ) ;
if ( V_36 != - V_40 )
return V_36 ;
F_11 ( ! F_14 ( F_10 ( V_2 -> V_3 ) -> V_25 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_33 * V_34 ,
int V_35 , int V_53 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_34 ;
struct V_54 * V_55 = V_56 ;
long V_57 = F_40 ( V_3 , V_53 & V_58 ) ;
int V_36 ;
if ( F_38 ( V_2 ) )
return - V_59 ;
if ( V_35 < sizeof( struct V_15 ) )
return - V_40 ;
if ( V_16 -> V_41 != V_42 )
return - V_43 ;
F_33 ( V_3 ) ;
switch ( V_2 -> V_60 ) {
case V_61 :
if ( V_3 -> V_45 != V_46 ) {
V_36 = - V_62 ;
goto V_47;
}
break;
case V_63 :
V_36 = - V_64 ;
goto V_47;
default:
V_36 = - V_62 ;
goto V_47;
}
V_24 -> V_65 = F_7 ( V_16 ) ;
V_24 -> V_26 = F_41 ( V_16 ) ;
V_2 -> V_60 = V_63 ;
V_36 = V_3 -> V_4 -> V_66 ( V_3 , V_34 , V_35 ) ;
if ( V_36 ) {
V_2 -> V_60 = V_61 ;
V_24 -> V_65 = 0 ;
goto V_47;
}
while ( V_3 -> V_45 == V_67 ) {
F_42 ( V_68 ) ;
if ( ! V_57 ) {
V_36 = - V_69 ;
goto V_47;
}
if ( F_43 ( V_55 ) ) {
V_36 = F_44 ( V_57 ) ;
goto V_47;
}
F_45 ( F_46 ( V_3 ) , & V_68 ,
V_70 ) ;
F_37 ( V_3 ) ;
V_57 = F_47 ( V_57 ) ;
F_33 ( V_3 ) ;
F_48 ( F_46 ( V_3 ) , & V_68 ) ;
}
if ( ( 1 << V_3 -> V_45 ) & ( V_71 | V_72 ) )
V_36 = 0 ;
else if ( V_3 -> V_45 == V_73 )
V_36 = - V_74 ;
else
V_36 = - V_75 ;
V_2 -> V_60 = V_36 ? V_61 : V_76 ;
V_47:
F_37 ( V_3 ) ;
return V_36 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_1 * V_77 ,
int V_53 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_2 * V_78 ;
int V_36 ;
if ( F_50 ( V_3 -> V_45 != V_79 ) )
return - V_40 ;
V_78 = V_3 -> V_4 -> V_80 ( V_3 , V_53 , & V_36 ) ;
if ( ! V_78 )
return V_36 ;
F_33 ( V_78 ) ;
F_51 ( V_78 , V_77 ) ;
V_77 -> V_60 = V_76 ;
F_37 ( V_78 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_33 * V_34 ,
int * V_81 , int V_82 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
memset ( V_34 , 0 , sizeof( struct V_15 ) ) ;
V_34 -> V_83 = V_42 ;
if ( ! V_82 )
F_53 ( (struct V_15 * ) V_34 ,
V_24 -> V_25 ) ;
* V_81 = sizeof( struct V_15 ) ;
return 0 ;
}
static unsigned int F_54 ( struct V_84 * V_84 , struct V_1 * V_2 ,
T_4 * V_68 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_85 * V_24 = F_55 ( V_3 ) ;
unsigned int V_86 = 0 ;
F_56 ( V_84 , F_46 ( V_3 ) , V_68 ) ;
if ( V_3 -> V_45 == V_46 )
return V_87 ;
if ( ! F_57 ( & V_3 -> V_88 ) )
V_86 |= V_89 | V_90 ;
if ( ! F_57 ( & V_24 -> V_91 ) )
V_86 |= V_92 ;
if ( ! V_86 && V_3 -> V_45 == V_73 )
return V_93 ;
if ( V_3 -> V_45 == V_94 &&
F_58 ( & V_3 -> V_95 ) < V_3 -> V_96 &&
F_58 ( & V_24 -> V_97 ) )
V_86 |= V_98 | V_99 | V_100 ;
return V_86 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_101 ,
unsigned long V_102 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
if ( V_101 == V_103 ) {
struct V_104 * V_105 ;
T_2 V_37 ;
T_3 V_38 ;
if ( F_60 ( V_37 , ( V_106 V_107 * ) V_102 ) )
return - V_108 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_109 )
V_105 = F_61 ( F_13 ( V_3 ) ,
V_3 -> V_109 ) ;
else
V_105 = F_62 ( F_13 ( V_3 ) ) ;
if ( V_105 && ( V_105 -> V_53 & V_110 ) )
V_38 = F_63 ( V_105 , F_15 ( V_37 ) ) ;
else
V_38 = V_111 ;
F_37 ( V_3 ) ;
if ( V_105 )
F_64 ( V_105 ) ;
if ( V_38 == V_111 )
return - V_112 ;
V_37 = F_36 ( V_38 , F_14 ( V_24 -> V_25 ) ) ;
return F_65 ( V_37 , ( V_106 V_107 * ) V_102 ) ;
}
return V_3 -> V_4 -> V_113 ( V_3 , V_101 , V_102 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_114 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_36 = 0 ;
if ( F_38 ( V_2 ) )
return - V_59 ;
F_33 ( V_3 ) ;
if ( V_2 -> V_60 != V_61 ) {
V_36 = - V_40 ;
goto V_47;
}
if ( V_3 -> V_45 != V_79 ) {
V_3 -> V_45 = V_79 ;
V_3 -> V_115 = 0 ;
}
V_3 -> V_116 = V_114 ;
V_47:
F_37 ( V_3 ) ;
return V_36 ;
}
static int F_67 ( struct V_117 * V_118 , struct V_1 * V_2 ,
struct V_119 * V_120 , T_5 V_121 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( F_38 ( V_2 ) )
return - V_122 ;
return V_3 -> V_4 -> V_123 ( V_118 , V_3 , V_120 , V_121 ) ;
}
int F_68 ( struct V_2 * V_3 , unsigned short V_124 )
{
static int V_125 ;
struct V_14 * V_14 = F_13 ( V_3 ) ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
struct V_15 V_126 ;
struct V_2 * V_127 ;
memset ( & V_126 , 0 , sizeof( struct V_15 ) ) ;
V_126 . V_41 = V_42 ;
F_34 ( ! F_69 ( & V_48 ) ) ;
if ( ! V_124 ) {
int V_128 , V_129 , V_130 ;
F_70 ( & V_129 , & V_130 ) ;
for ( V_128 = V_129 ; V_128 <= V_130 ; V_128 ++ ) {
V_125 ++ ;
if ( V_125 < V_129 || V_125 > V_130 )
V_125 = V_129 ;
F_71 ( & V_126 , V_125 ) ;
V_127 = F_6 ( V_14 , & V_126 ) ;
if ( V_127 == NULL ) {
V_124 = V_125 ;
goto V_131;
} else
F_72 ( V_127 ) ;
}
} else {
F_71 ( & V_126 , V_124 ) ;
V_127 = F_6 ( V_14 , & V_126 ) ;
if ( V_127 == NULL )
goto V_131;
else
F_72 ( V_127 ) ;
}
return - V_132 ;
V_131:
V_24 -> V_25 = F_36 ( F_15 ( V_24 -> V_25 ) , V_124 ) ;
return 0 ;
}
static struct V_2 * F_73 ( struct V_133 * V_134 , T_6 V_135 )
{
struct V_14 * V_14 = F_74 ( V_134 ) ;
struct V_11 * V_9 = V_8 . V_9 ;
struct V_17 * V_18 ;
struct V_2 * V_19 ;
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_7 ; V_29 ++ ) {
F_9 (sknode, node, hlist) {
if ( ! F_12 ( V_14 , F_13 ( V_19 ) ) )
continue;
if ( ! V_135 )
return V_19 ;
V_135 -- ;
}
V_9 ++ ;
}
return NULL ;
}
static struct V_2 * F_75 ( struct V_133 * V_134 , struct V_2 * V_3 )
{
struct V_14 * V_14 = F_74 ( V_134 ) ;
do
V_3 = F_76 ( V_3 ) ;
while ( V_3 && ! F_12 ( V_14 , F_13 ( V_3 ) ) );
return V_3 ;
}
static void * F_77 ( struct V_133 * V_134 , T_6 * V_135 )
__acquires( T_7 )
{
F_8 () ;
return * V_135 ? F_73 ( V_134 , * V_135 - 1 ) : V_136 ;
}
static void * F_78 ( struct V_133 * V_134 , void * V_137 , T_6 * V_135 )
{
struct V_2 * V_3 ;
if ( V_137 == V_136 )
V_3 = F_73 ( V_134 , 0 ) ;
else
V_3 = F_75 ( V_134 , V_137 ) ;
( * V_135 ) ++ ;
return V_3 ;
}
static void F_79 ( struct V_133 * V_134 , void * V_137 )
__releases( T_7 )
{
F_17 () ;
}
static int F_80 ( struct V_133 * V_134 , void * V_137 )
{
int V_35 ;
if ( V_137 == V_136 )
F_81 ( V_134 , L_1 , L_2
L_3 , & V_35 ) ;
else {
struct V_2 * V_3 = V_137 ;
struct V_23 * V_24 = F_10 ( V_3 ) ;
F_81 ( V_134 , L_4
L_5 ,
V_3 -> V_138 , V_24 -> V_25 , V_24 -> V_65 ,
V_24 -> V_26 , V_3 -> V_45 ,
F_82 ( V_3 ) , F_83 ( V_3 ) ,
F_84 ( V_3 ) , F_85 ( V_3 ) ,
F_58 ( & V_3 -> V_139 ) , V_3 ,
F_58 ( & V_3 -> V_140 ) , & V_35 ) ;
}
F_81 ( V_134 , L_6 , 127 - V_35 , L_7 ) ;
return 0 ;
}
static int F_86 ( struct V_141 * V_141 , struct V_84 * V_84 )
{
return F_87 ( V_141 , V_84 , & V_142 ,
sizeof( struct V_143 ) ) ;
}
struct V_2 * F_88 ( struct V_14 * V_14 , T_3 V_21 )
{
struct V_2 * V_3 ;
if ( ! F_12 ( V_14 , & V_144 ) )
return NULL ;
F_8 () ;
V_3 = F_89 ( V_145 . V_3 [ V_21 ] ) ;
if ( V_3 )
F_16 ( V_3 ) ;
F_17 () ;
return V_3 ;
}
int F_90 ( struct V_2 * V_3 , T_3 V_21 )
{
int V_146 = - V_132 ;
if ( ! F_12 ( F_13 ( V_3 ) , & V_144 ) )
return - V_147 ;
if ( ! F_91 ( V_148 ) )
return - V_149 ;
if ( F_38 ( V_3 -> V_150 ) )
return - V_122 ;
F_24 ( & V_151 ) ;
if ( V_145 . V_3 [ V_21 ] == NULL ) {
F_16 ( V_3 ) ;
F_92 ( V_145 . V_3 [ V_21 ] , V_3 ) ;
V_146 = 0 ;
}
F_26 ( & V_151 ) ;
return V_146 ;
}
int F_93 ( struct V_2 * V_3 , T_3 V_21 )
{
int V_146 = - V_152 ;
if ( ! F_91 ( V_148 ) )
return - V_149 ;
F_24 ( & V_151 ) ;
if ( V_145 . V_3 [ V_21 ] == V_3 ) {
F_92 ( V_145 . V_3 [ V_21 ] , NULL ) ;
V_146 = 0 ;
}
F_26 ( & V_151 ) ;
if ( V_146 == 0 ) {
F_30 () ;
F_72 ( V_3 ) ;
}
return V_146 ;
}
void F_29 ( struct V_2 * V_3 )
{
unsigned V_21 , V_153 = 0 ;
F_24 ( & V_151 ) ;
for ( V_21 = 0 ; V_21 < 256 ; V_21 ++ ) {
if ( V_145 . V_3 [ V_21 ] == V_3 ) {
F_92 ( V_145 . V_3 [ V_21 ] , NULL ) ;
V_153 ++ ;
}
}
F_26 ( & V_151 ) ;
while ( V_153 > 0 ) {
F_94 ( V_3 ) ;
V_153 -- ;
}
}
static struct V_2 * * F_95 ( struct V_133 * V_134 , T_6 V_135 )
{
struct V_14 * V_14 = F_74 ( V_134 ) ;
unsigned V_6 ;
if ( ! F_12 ( V_14 , & V_144 ) )
return NULL ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
if ( V_145 . V_3 [ V_6 ] == NULL )
continue;
if ( ! V_135 )
return V_145 . V_3 + V_6 ;
V_135 -- ;
}
return NULL ;
}
static struct V_2 * * F_96 ( struct V_133 * V_134 , struct V_2 * * V_3 )
{
struct V_14 * V_14 = F_74 ( V_134 ) ;
unsigned V_6 ;
F_11 ( ! F_12 ( V_14 , & V_144 ) ) ;
for ( V_6 = ( V_3 - V_145 . V_3 ) + 1 ; V_6 < 256 ; V_6 ++ )
if ( V_145 . V_3 [ V_6 ] )
return V_145 . V_3 + V_6 ;
return NULL ;
}
static void * F_97 ( struct V_133 * V_134 , T_6 * V_135 )
__acquires( V_151 )
{
F_24 ( & V_151 ) ;
return * V_135 ? F_95 ( V_134 , * V_135 - 1 ) : V_136 ;
}
static void * F_98 ( struct V_133 * V_134 , void * V_137 , T_6 * V_135 )
{
struct V_2 * * V_3 ;
if ( V_137 == V_136 )
V_3 = F_95 ( V_134 , 0 ) ;
else
V_3 = F_96 ( V_134 , V_137 ) ;
( * V_135 ) ++ ;
return V_3 ;
}
static void F_99 ( struct V_133 * V_134 , void * V_137 )
__releases( V_151 )
{
F_26 ( & V_151 ) ;
}
static int F_100 ( struct V_133 * V_134 , void * V_137 )
{
int V_35 ;
if ( V_137 == V_136 )
F_81 ( V_134 , L_1 , L_8 , & V_35 ) ;
else {
struct V_2 * * V_154 = V_137 ;
struct V_2 * V_3 = * V_154 ;
F_81 ( V_134 , L_9 ,
( int ) ( V_154 - V_145 . V_3 ) , F_84 ( V_3 ) ,
F_85 ( V_3 ) , & V_35 ) ;
}
F_81 ( V_134 , L_6 , 63 - V_35 , L_7 ) ;
return 0 ;
}
static int F_101 ( struct V_141 * V_141 , struct V_84 * V_84 )
{
return F_87 ( V_141 , V_84 , & V_155 ,
sizeof( struct V_143 ) ) ;
}
