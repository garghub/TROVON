int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , struct V_5 * V_6 )
{
void * V_7 = NULL ;
int V_8 = 0 ;
T_2 V_9 = 0 ;
F_2 ( & V_2 -> V_10 ) ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = F_3 ( V_4 , V_12 ) ;
if ( ! V_7 ) {
V_8 = - V_13 ;
return V_8 ;
}
V_8 = F_4 ( & V_2 -> V_14 , V_7 , V_6 , V_4 ) ;
if ( V_8 )
goto V_15;
F_5 ( & V_2 -> V_16 ,
& V_9 ,
& V_2 -> V_17 ,
V_7 , F_6 ( V_4 ) ) ;
V_2 -> V_16 . V_18 = NULL ;
V_8 = F_4 ( V_3 , V_2 ,
V_6 , sizeof( struct V_1 ) ) ;
if ( V_8 )
goto V_19;
V_2 -> V_20 = * V_3 ;
return V_8 ;
V_19:
F_7 ( V_2 -> V_14 , V_6 , V_4 ) ;
V_2 -> V_14 = 0 ;
V_15:
V_15 ( V_7 ) ;
return V_8 ;
}
int F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_21 , int V_4 ,
struct V_5 * V_6 )
{
void * V_7 ;
void * V_22 ;
struct V_1 * V_23 ;
int V_24 ;
int V_8 = 0 ;
F_2 ( & V_2 -> V_10 ) ;
F_2 ( & V_2 -> V_11 ) ;
V_23 = F_9 ( V_21 , sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_23 )
return - V_25 ;
V_2 -> V_23 = V_23 ;
if ( V_2 -> V_23 -> V_26 != V_27 ) {
V_8 = - V_25 ;
goto V_28;
}
V_2 -> V_29 = V_23 -> V_14 ;
V_24 = V_2 -> V_23 -> V_16 . V_30 ;
V_22 = F_9 ( V_2 -> V_29 , V_24 , V_6 ) ;
if ( ! V_22 ) {
V_8 = - V_25 ;
goto V_28;
}
V_2 -> V_23 -> V_17 = 0 ;
F_5 ( & V_2 -> V_31 ,
& V_2 -> V_32 ,
& V_2 -> V_23 -> V_17 ,
V_22 ,
F_6 ( V_24 ) ) ;
V_7 = F_3 ( V_4 , V_12 ) ;
if ( ! V_7 ) {
V_8 = - V_13 ;
goto V_33;
}
V_8 = F_4 ( & V_2 -> V_14 , V_7 , V_6 , V_4 ) ;
if ( V_8 )
goto V_15;
V_2 -> V_23 -> V_32 = 0 ;
F_5 ( & V_2 -> V_16 ,
& V_2 -> V_23 -> V_32 ,
& V_2 -> V_17 ,
V_7 , F_6 ( V_4 ) ) ;
V_8 = F_4 ( V_3 , V_2 , V_6 ,
sizeof( struct V_1 ) ) ;
if ( V_8 )
goto V_19;
V_2 -> V_20 = * V_3 ;
return V_8 ;
V_19:
F_7 ( V_2 -> V_14 , V_6 , V_4 ) ;
V_2 -> V_14 = 0 ;
V_15:
V_15 ( V_7 ) ;
V_33:
F_10 ( V_22 , V_24 , V_6 ) ;
V_2 -> V_31 . V_34 = NULL ;
V_28:
F_10 ( V_2 -> V_23 , sizeof( struct V_1 ) , V_6 ) ;
V_2 -> V_23 = NULL ;
return V_8 ;
}
int F_11 ( struct V_5 * V_6 ,
struct V_1 * V_2 , T_3 V_35 )
{
int V_8 = 0 ;
void * V_36 ;
int V_24 ;
T_4 V_37 ;
V_2 -> V_23 = F_9 ( V_35 , sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_2 -> V_23 ) {
V_8 = - V_13 ;
goto error;
}
if ( V_2 -> V_23 -> V_26 != V_27 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_1 ,
V_5 [ V_40 . V_41 ] . V_42 , V_6 -> V_42 ) ;
V_8 = - V_43 ;
goto error;
}
V_37 = V_2 -> V_23 -> V_14 ;
V_24 = V_2 -> V_23 -> V_16 . V_30 ;
V_36 = F_9 ( V_37 , V_24 , V_6 ) ;
if ( ! V_36 )
return - V_25 ;
V_2 -> V_32 = 0 ;
F_5 ( & V_2 -> V_31 ,
& V_2 -> V_32 ,
& V_2 -> V_23 -> V_17 ,
V_36 ,
F_6 ( V_24 ) ) ;
F_5 ( & V_2 -> V_16 ,
& V_2 -> V_23 -> V_32 ,
& V_2 -> V_17 ,
V_2 -> V_16 . V_34 ,
F_6 ( V_2 -> V_16 . V_30 ) ) ;
error:
return V_8 ;
}
static T_5 void
F_13 ( struct V_5 * V_6 )
{
struct V_44 * V_38 = V_6 -> V_38 ;
if ( F_14 ( V_6 ) )
V_38 -> V_45 -> V_46 ( V_38 , V_6 -> V_47 , & V_6 -> V_48 ) ;
else
V_38 -> V_45 -> V_49 ( V_38 , V_6 -> V_47 ) ;
}
int F_15 ( T_4 V_21 , struct V_5 * V_6 )
{
int V_8 = 0 ;
struct V_50 V_51 ;
V_8 = F_11 ( V_6 , V_6 -> V_52 , V_21 ) ;
if ( ! V_8 ) {
V_51 . V_53 = V_54 ;
V_51 . V_55 . V_42 = V_6 -> V_42 ;
V_8 = F_16 ( V_6 , & V_51 ) ;
}
return V_8 ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_50 V_51 ;
int V_56 ;
V_6 -> exit = V_57 ;
V_51 . V_53 = V_58 ;
V_51 . V_59 . V_42 = V_40 . V_41 ;
V_51 . V_55 . V_42 = V_6 -> V_42 ;
V_56 = F_16 ( V_6 , & V_51 ) ;
if ( V_56 )
goto V_60;
F_18 ( V_40 . V_61 , V_6 -> exit == V_62 ,
V_63 ) ;
V_60:
V_6 -> exit = V_64 ;
}
int F_19 ( struct V_5 * V_6 )
{
int V_8 = 0 ;
int V_4 ;
struct V_1 * V_2 ;
V_4 = V_65 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 ) {
V_8 = - V_13 ;
return V_8 ;
}
V_2 -> V_26 = V_27 ;
V_6 -> V_52 = V_2 ;
V_8 = F_1 ( V_2 , & V_6 -> V_66 ,
V_4 , V_6 ) ;
if ( V_8 )
goto V_67;
return V_8 ;
V_67:
V_15 ( V_6 -> V_52 ) ;
V_6 -> V_52 = NULL ;
return V_8 ;
}
static void F_20 ( struct V_68 * V_69 )
{
V_15 ( V_69 ) ;
}
static struct V_68 *
F_21 ( T_4 V_70 , int V_71 , int V_72 )
{
struct V_68 * V_69 ;
struct V_73 * V_73 ;
int V_74 ;
V_69 = F_22 ( V_72 , sizeof( struct V_68 ) , V_12 ) ;
if ( ! V_69 )
return NULL ;
F_23 ( V_69 , V_72 ) ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
V_73 = F_24 ( V_70 >> V_75 ) ;
F_25 ( & V_69 [ V_74 ] , V_73 , V_71 , 0 ) ;
V_70 += V_71 ;
}
return V_69 ;
}
static struct V_76 *
F_26 ( struct V_5 * V_6 , struct V_5 * V_77 )
{
struct V_76 * V_78 ;
int V_79 , V_80 , V_81 , V_8 , V_82 ;
struct V_44 * V_83 = V_77 -> V_38 ;
struct V_44 * V_38 = V_6 -> V_38 ;
V_79 = V_83 -> V_48 -> V_84 >> V_75 ;
V_80 = V_83 -> V_85 -> V_84 >> V_75 ;
V_78 = F_3 ( sizeof( * V_78 ) , V_12 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> V_86 [ V_87 ] = F_21 ( V_83 -> V_48 -> V_70 ,
V_88 , V_79 ) ;
if ( ! V_78 -> V_86 [ V_87 ] )
goto V_89;
V_78 -> V_90 [ V_87 ] = V_79 ;
V_81 = F_27 ( F_28 ( V_83 -> V_85 -> V_84 , ( T_3 ) ( 1 << 30 ) ) ) ;
V_82 = V_80 >> ( V_81 - V_75 ) ;
V_78 -> V_86 [ V_91 ] = F_21 ( V_83 -> V_85 -> V_70 ,
1 << V_81 ,
V_82 ) ;
V_78 -> V_90 [ V_91 ] = V_82 ;
V_8 = F_29 ( & V_38 -> V_39 , V_78 -> V_86 [ V_87 ] ,
V_79 , V_92 ) ;
if ( V_8 != V_79 )
goto V_93;
V_8 = F_29 ( & V_38 -> V_39 , V_78 -> V_86 [ V_91 ] ,
V_82 , V_92 ) ;
if ( V_8 != V_82 )
goto V_94;
V_78 -> V_95 [ V_87 ] = F_30 ( V_78 -> V_86 [ V_87 ] ) ;
V_78 -> V_95 [ V_91 ] = F_30 ( V_78 -> V_86 [ V_91 ] ) ;
V_78 -> V_96 [ V_87 ] = V_79 ;
V_78 -> V_96 [ V_91 ] = V_80 ;
V_78 -> V_97 = V_77 -> V_42 ;
return V_78 ;
V_94:
F_31 ( & V_38 -> V_39 , V_78 -> V_86 [ V_87 ] ,
V_78 -> V_90 [ V_87 ] , V_98 ) ;
V_93:
F_20 ( V_78 -> V_86 [ V_87 ] ) ;
F_20 ( V_78 -> V_86 [ V_91 ] ) ;
V_89:
V_15 ( V_78 ) ;
return NULL ;
}
static void F_32 ( struct V_5 * V_6 , int V_55 )
{
struct V_5 * V_99 = V_6 ;
struct V_5 * V_100 = NULL ;
struct V_76 * V_101 = NULL ;
struct V_76 * V_102 = NULL ;
struct V_76 * V_78 ;
struct V_103 * V_104 , * V_105 ;
struct V_50 V_51 ;
int V_8 ;
T_3 V_106 ;
if ( V_55 < 1 || V_55 > V_40 . V_107 )
return;
V_100 = & V_5 [ V_55 ] ;
if ( ! F_33 ( V_100 ) )
return;
if ( ! F_34 ( & V_100 -> V_78 ) ) {
F_35 (pos, tmp, &dev_i->p2p) {
V_78 = F_36 ( V_104 , struct V_76 , V_108 ) ;
if ( V_78 -> V_97 == V_99 -> V_42 )
return;
}
}
V_101 = F_26 ( V_100 , V_99 ) ;
if ( ! V_101 )
return;
V_102 = F_26 ( V_99 , V_100 ) ;
if ( ! V_102 )
return;
F_37 ( & V_101 -> V_108 , & V_100 -> V_78 ) ;
F_37 ( & V_102 -> V_108 , & V_99 -> V_78 ) ;
V_51 . V_53 = V_109 ;
V_51 . V_59 . V_42 = V_99 -> V_42 ;
V_51 . V_55 . V_42 = V_100 -> V_42 ;
V_51 . V_35 [ 0 ] = V_102 -> V_95 [ V_91 ] ;
V_51 . V_35 [ 1 ] = V_101 -> V_95 [ V_87 ] ;
V_51 . V_35 [ 2 ] = V_101 -> V_95 [ V_91 ] ;
V_51 . V_35 [ 3 ] = V_101 -> V_96 [ V_91 ] << V_75 ;
V_8 = F_16 ( V_100 , & V_51 ) ;
if ( V_8 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_2 , V_110 , __LINE__ , V_8 ) ;
return;
}
V_51 . V_53 = V_109 ;
V_51 . V_59 . V_42 = V_100 -> V_42 ;
V_51 . V_55 . V_42 = V_99 -> V_42 ;
V_106 = V_51 . V_35 [ 0 ] ;
V_51 . V_35 [ 0 ] = V_51 . V_35 [ 2 ] ;
V_51 . V_35 [ 2 ] = V_106 ;
V_51 . V_35 [ 1 ] = V_102 -> V_95 [ V_87 ] ;
V_51 . V_35 [ 3 ] = V_102 -> V_96 [ V_91 ] << V_75 ;
F_16 ( V_99 , & V_51 ) ;
}
static void F_38 ( void )
{
int V_74 , V_111 ;
if ( ! V_40 . V_112 )
return;
for ( V_74 = 1 ; V_74 <= V_40 . V_107 ; V_74 ++ )
if ( ! F_33 ( & V_5 [ V_74 ] ) )
return;
for ( V_74 = 1 ; V_74 <= V_40 . V_107 ; V_74 ++ ) {
for ( V_111 = 1 ; V_111 <= V_40 . V_107 ; V_111 ++ ) {
struct V_5 * V_6 = & V_5 [ V_74 ] ;
if ( V_74 == V_111 )
continue;
F_32 ( V_6 , V_111 ) ;
}
}
}
void F_39 ( struct V_113 * V_114 )
{
struct V_5 * V_6 = F_40 ( V_114 , struct V_5 ,
V_115 ) ;
struct V_116 * V_117 ;
if ( F_33 ( V_6 ) )
return;
V_117 = F_41 ( V_6 ) ;
if ( F_42 ( V_117 ) )
return;
if ( F_43 () ) {
F_44 ( & V_40 . V_118 ) ;
F_38 () ;
F_45 ( & V_40 . V_118 ) ;
}
}
static void
F_46 ( struct V_5 * V_6 , struct V_50 * V_51 ,
const char * V_119 )
{
if ( ! V_40 . V_120 )
return;
if ( V_51 -> V_53 > V_121 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_3 , V_119 , V_51 -> V_53 ) ;
return;
}
F_47 ( & V_6 -> V_38 -> V_39 ,
L_4 ,
V_119 , V_122 [ V_51 -> V_53 ] , V_51 -> V_59 . V_42 , V_51 -> V_59 . V_123 ,
V_51 -> V_55 . V_42 , V_51 -> V_55 . V_123 , V_51 -> V_35 [ 0 ] , V_51 -> V_35 [ 1 ] ,
V_51 -> V_35 [ 2 ] , V_51 -> V_35 [ 3 ] ) ;
}
int F_48 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_6 -> V_52 ;
int V_8 = - V_13 , V_124 = 0 ;
F_46 ( V_6 , V_51 , L_5 ) ;
if ( ! V_2 ) {
V_8 = - V_125 ;
goto error;
}
F_49 ( & V_2 -> V_10 ) ;
while ( ( V_8 = F_50 ( & V_2 -> V_31 ,
V_51 , sizeof( struct V_50 ) ) ) ) {
F_51 ( 1 ) ;
#define F_52 (3 * 1000)
if ( V_124 ++ > ( F_52 ) ) {
V_8 = - V_43 ;
break;
}
}
if ( ! V_8 )
F_53 ( & V_2 -> V_31 ) ;
F_54 ( & V_2 -> V_10 ) ;
if ( ! V_8 ) {
if ( F_55 ( V_6 ) )
F_56 ( V_6 -> V_126 , & V_6 -> V_127 ) ;
else
F_13 ( V_6 ) ;
}
error:
if ( V_8 )
F_57 ( & V_6 -> V_38 -> V_39 ,
L_6 ,
V_110 , __LINE__ , V_8 , V_51 -> V_53 ) ;
return V_8 ;
}
int F_16 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
int V_8 ;
struct V_128 * V_117 = NULL ;
if ( V_51 -> V_53 > V_129 ) {
if ( V_64 != V_6 -> exit )
return - V_43 ;
V_117 = F_58 ( V_6 ) ;
if ( F_42 ( V_117 ) ) {
V_8 = F_59 ( V_117 ) ;
return V_8 ;
}
}
V_8 = F_48 ( V_6 , V_51 ) ;
if ( V_51 -> V_53 > V_129 )
F_60 ( V_117 ) ;
return V_8 ;
}
void F_61 ( struct V_113 * V_114 )
{
F_62 () ;
}
static T_5 void
F_63 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
F_64 ( & V_6 -> V_130 ) ;
F_65 ( & V_6 -> V_115 ) ;
}
static T_5 void
F_66 ( struct V_5 * V_6 , struct V_50 * V_131 )
{
V_6 -> V_132 = true ;
if ( F_43 () )
F_67 ( V_6 -> V_42 , false ) ;
else
F_68 ( V_6 ) ;
F_69 ( & V_6 -> V_130 ,
F_70 ( 1000 ) ) ;
}
static T_5 void
F_71 ( struct V_5 * V_6 , struct V_50 * V_131 )
{
V_6 -> exit = V_62 ;
F_72 ( & V_40 . V_61 ) ;
}
static T_5 void
F_73 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_5 * V_133 ;
T_1 V_3 ;
int V_134 ;
struct V_44 * V_38 ;
F_57 ( & V_6 -> V_38 -> V_39 ,
L_7 ,
V_6 -> V_42 , V_51 -> V_55 . V_42 , V_51 -> V_59 . V_42 ) ;
F_57 ( & V_6 -> V_38 -> V_39 ,
L_8 ,
V_51 -> V_35 [ 0 ] ) ;
V_133 = & V_5 [ V_51 -> V_59 . V_42 ] ;
V_133 -> V_42 = V_51 -> V_59 . V_42 ;
V_133 -> V_38 = V_5 [ V_135 ] . V_38 ;
V_38 = V_133 -> V_38 ;
if ( F_74 ( V_133 ) ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_9 , V_51 -> V_59 . V_42 ) ;
goto V_136;
}
V_133 -> V_48 . V_137 = F_75 ( V_51 -> V_35 [ 1 ] , V_38 -> V_48 -> V_84 ) ;
if ( ! V_133 -> V_48 . V_137 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_10 , V_51 -> V_59 . V_42 ) ;
goto V_138;
}
V_133 -> V_52 = F_3 ( sizeof( * V_133 -> V_52 ) , V_12 ) ;
if ( ! V_133 -> V_52 )
goto V_139;
V_133 -> V_140 = V_51 -> V_35 [ 0 ] ;
V_134 = F_1 ( V_133 -> V_52 , & V_3 ,
V_65 , V_133 ) ;
if ( V_134 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_11 , V_134 ) ;
goto V_141;
}
V_133 -> V_142 = V_38 -> V_45 -> V_143 ( V_38 ) ;
V_133 -> V_144 = V_38 -> V_45 -> V_145 ( V_38 , V_146 ,
L_12 , V_133 ,
V_133 -> V_142 ) ;
if ( F_42 ( V_133 -> V_144 ) )
goto V_141;
V_133 -> V_52 -> V_26 = V_27 ;
V_133 -> V_52 -> V_147 = V_148 ;
V_51 -> V_53 = V_149 ;
V_51 -> V_55 . V_42 = V_51 -> V_59 . V_42 ;
V_51 -> V_59 . V_42 = V_40 . V_41 ;
V_51 -> V_35 [ 0 ] = V_3 ;
V_51 -> V_35 [ 2 ] = V_133 -> V_142 ;
F_16 ( & V_5 [ V_135 ] , V_51 ) ;
return;
V_141:
V_15 ( V_133 -> V_52 ) ;
V_133 -> V_52 = NULL ;
V_139:
V_28 ( V_133 -> V_48 . V_137 ) ;
V_133 -> V_48 . V_137 = NULL ;
V_138:
V_136:
F_12 ( & V_6 -> V_38 -> V_39 ,
L_13 , V_51 -> V_59 . V_42 ) ;
V_51 -> V_53 = V_150 ;
V_51 -> V_55 . V_42 = V_51 -> V_59 . V_42 ;
V_51 -> V_59 . V_42 = V_40 . V_41 ;
F_16 ( & V_5 [ V_135 ] , V_51 ) ;
}
void F_76 ( struct V_113 * V_114 )
{
#define F_77 100
#define F_78 100
struct V_5 * V_77 = F_40 ( V_114 , struct V_5 ,
V_151 . V_114 ) ;
struct V_1 * V_2 = & V_77 -> V_52 [ 0 ] ;
if ( V_2 -> V_147 != V_152 ||
V_2 -> V_23 -> V_147 != V_152 ) {
if ( V_77 -> V_153 ++ == F_77 ) {
F_12 ( & V_77 -> V_38 -> V_39 ,
L_14 ,
V_2 -> V_147 ) ;
goto V_154;
}
F_69 ( & V_77 -> V_151 ,
F_70 ( F_78 ) ) ;
return;
}
F_41 ( V_77 ) ;
return;
V_154:
F_12 ( & V_77 -> V_38 -> V_39 ,
L_15 ,
V_110 , __LINE__ , V_77 -> V_42 , V_2 -> V_147 ) ;
V_2 -> V_23 -> V_147 = V_148 ;
F_79 ( V_77 ) ;
}
static T_5 void
F_80 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_5 * V_77 ;
struct V_1 * V_2 ;
struct V_5 * V_155 = & V_5 [ V_51 -> V_55 . V_42 ] ;
F_57 ( & V_6 -> V_38 -> V_39 ,
L_16 ,
V_6 -> V_42 , V_51 -> V_59 . V_42 , V_51 -> V_55 . V_42 ) ;
F_57 ( & V_6 -> V_38 -> V_39 ,
L_17 , V_51 -> V_35 [ 0 ] ,
V_51 -> V_35 [ 1 ] , V_51 -> V_35 [ 2 ] , V_51 -> V_35 [ 3 ] ) ;
if ( F_43 () ) {
F_44 ( & V_40 . V_118 ) ;
V_51 -> V_35 [ 1 ] = V_40 . V_107 ;
F_16 ( V_155 , V_51 ) ;
F_45 ( & V_40 . V_118 ) ;
return;
}
V_77 = & V_5 [ V_51 -> V_59 . V_42 ] ;
V_77 -> V_38 = V_5 [ V_135 ] . V_38 ;
V_77 -> V_42 = V_51 -> V_59 . V_42 ;
V_2 = & V_77 -> V_52 [ 0 ] ;
if ( ( F_11 ( V_77 , & V_77 -> V_52 [ 0 ] ,
V_51 -> V_35 [ 0 ] ) ) )
goto V_156;
V_77 -> V_47 = V_51 -> V_35 [ 2 ] ;
V_2 -> V_23 -> V_147 = V_152 ;
F_69 ( & V_77 -> V_151 , 0 ) ;
return;
V_156:
F_79 ( V_77 ) ;
}
static T_5 void
F_81 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
if ( F_43 () ) {
struct V_5 * V_155 = & V_5 [ V_51 -> V_55 . V_42 ] ;
F_57 ( & V_6 -> V_38 -> V_39 ,
L_18 , V_6 -> V_42 ) ;
F_16 ( V_155 , V_51 ) ;
}
}
static T_5 void
F_82 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
int V_42 = V_51 -> V_35 [ 0 ] ;
struct V_5 * V_157 = & V_5 [ V_42 ] ;
V_157 -> V_158 = true ;
F_83 ( V_42 ) ;
}
static T_5 void
F_84 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_5 * V_38 = & V_5 [ V_51 -> V_35 [ 0 ] ] ;
F_85 ( & V_38 -> V_159 ) ;
F_72 ( & V_38 -> V_160 ) ;
}
static T_5 void
F_86 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
if ( F_43 () ) {
F_87 ( V_51 -> V_55 . V_42 , V_51 -> V_59 . V_42 ) ;
F_44 ( & V_40 . V_118 ) ;
V_51 -> V_35 [ 1 ] = V_40 . V_107 ;
V_51 -> V_35 [ 2 ] = V_40 . V_161 ;
F_45 ( & V_40 . V_118 ) ;
F_16 ( V_6 , V_51 ) ;
} else {
struct V_162 * V_163 =
(struct V_162 * ) V_51 -> V_35 [ 3 ] ;
F_44 ( & V_40 . V_118 ) ;
V_40 . V_107 = V_51 -> V_35 [ 1 ] ;
V_40 . V_161 = V_51 -> V_35 [ 2 ] ;
F_88 ( V_163 ) ;
F_45 ( & V_40 . V_118 ) ;
}
}
static void
F_89 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
F_12 ( & V_6 -> V_38 -> V_39 ,
L_19 ,
V_51 -> V_53 , V_6 -> V_42 ) ;
}
static void
F_90 ( struct V_5 * V_6 ,
struct V_1 * V_2 , struct V_50 * V_51 )
{
F_46 ( V_6 , V_51 , L_20 ) ;
if ( V_51 -> V_53 > ( T_2 ) V_164 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_19 ,
V_51 -> V_53 , V_6 -> V_42 ) ;
return;
}
V_165 [ V_51 -> V_53 ] ( V_6 , V_51 ) ;
}
void F_91 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_50 V_51 ;
int V_166 ;
do {
V_166 = F_92 ( & V_2 -> V_16 , & V_51 , sizeof( V_51 ) ) ;
if ( ! V_166 )
break;
F_90 ( V_6 , V_2 , & V_51 ) ;
if ( V_129 == V_51 . V_53 )
break;
F_93 ( & V_2 -> V_16 ) ;
} while ( 1 );
}
static void F_94 ( struct V_113 * V_131 )
{
struct V_5 * V_6 = V_40 . V_167 ;
struct V_1 * V_2 = V_6 -> V_52 ;
struct V_168 * V_51 ;
do {
V_51 = NULL ;
F_49 ( & V_2 -> V_11 ) ;
if ( ! F_34 ( & V_40 . V_169 ) ) {
V_51 = F_95 ( & V_40 . V_169 ,
struct V_168 ,
V_170 ) ;
F_96 ( & V_51 -> V_170 ) ;
}
F_54 ( & V_2 -> V_11 ) ;
if ( V_51 ) {
F_90 ( V_6 , V_2 , & V_51 -> V_51 ) ;
V_15 ( V_51 ) ;
}
} while ( V_51 );
}
int
F_97 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
int V_166 ;
struct V_168 * V_51 ;
do {
V_51 = F_98 ( sizeof( * V_51 ) , V_12 ) ;
if ( ! V_51 )
return - V_13 ;
V_166 = F_92 ( & V_2 -> V_16 , & V_51 -> V_51 ,
sizeof( struct V_50 ) ) ;
if ( V_166 != sizeof( struct V_50 ) ) {
V_15 ( V_51 ) ;
F_93 ( & V_2 -> V_16 ) ;
break;
}
F_49 ( & V_2 -> V_11 ) ;
F_37 ( & V_51 -> V_170 , & V_40 . V_169 ) ;
F_54 ( & V_2 -> V_11 ) ;
F_56 ( V_40 . V_171 , & V_40 . V_172 ) ;
F_93 ( & V_2 -> V_16 ) ;
} while ( V_166 == sizeof( struct V_50 ) );
return V_166 ;
}
int F_99 ( struct V_5 * V_6 )
{
int V_8 = 0 ;
void * V_7 ;
struct V_1 * V_2 ;
struct V_116 * V_117 ;
V_8 = F_74 ( V_6 ) ;
if ( V_8 )
goto exit;
F_100 ( & V_40 . V_169 ) ;
snprintf ( V_40 . V_173 , sizeof( V_40 . V_173 ) ,
L_21 , V_6 -> V_42 ) ;
V_40 . V_171 =
F_101 ( V_40 . V_173 , 0 ) ;
if ( ! V_40 . V_171 ) {
V_8 = - V_13 ;
goto V_174;
}
F_102 ( & V_40 . V_172 , F_94 ) ;
V_6 -> V_52 = F_3 ( sizeof( * V_6 -> V_52 ) , V_12 ) ;
if ( ! V_6 -> V_52 ) {
V_8 = - V_13 ;
goto V_175;
}
V_2 = V_6 -> V_52 ;
V_2 -> V_26 = V_27 ;
F_2 ( & V_2 -> V_10 ) ;
F_2 ( & V_2 -> V_11 ) ;
V_7 = F_3 ( V_65 , V_12 ) ;
if ( ! V_7 ) {
V_8 = - V_13 ;
goto V_176;
}
F_5 ( & V_2 -> V_31 ,
& V_2 -> V_32 ,
& V_2 -> V_17 ,
V_7 , F_6 ( V_65 ) ) ;
F_5 ( & V_2 -> V_16 ,
& V_2 -> V_32 ,
& V_2 -> V_17 ,
V_7 , F_6 ( V_65 ) ) ;
V_40 . V_41 = V_6 -> V_42 ;
V_117 = F_41 ( V_6 ) ;
if ( F_42 ( V_117 ) ) {
V_8 = F_59 ( V_117 ) ;
goto V_177;
}
V_40 . V_167 = V_6 ;
return V_8 ;
V_177:
V_15 ( V_7 ) ;
V_176:
V_15 ( V_6 -> V_52 ) ;
V_175:
F_103 ( V_40 . V_171 ) ;
V_174:
F_104 ( V_6 ) ;
exit:
return V_8 ;
}
int F_105 ( struct V_5 * V_6 )
{
struct V_116 * V_117 ;
F_106 () ;
V_117 = F_107 ( V_6 -> V_117 ) ;
F_108 () ;
if ( V_117 )
F_109 ( V_117 ) ;
F_103 ( V_40 . V_171 ) ;
F_104 ( V_6 ) ;
V_15 ( V_6 -> V_52 -> V_31 . V_34 ) ;
V_15 ( V_6 -> V_52 ) ;
V_6 -> V_38 = NULL ;
V_40 . V_167 = NULL ;
return 0 ;
}
void F_110 ( struct V_5 * V_6 )
{
struct V_5 * V_178 ;
struct V_76 * V_78 ;
struct V_103 * V_104 , * V_105 ;
int V_179 ;
F_44 ( & V_40 . V_118 ) ;
F_35 (pos, tmp, &scifdev->p2p) {
V_78 = F_36 ( V_104 , struct V_76 , V_108 ) ;
F_31 ( & V_6 -> V_38 -> V_39 , V_78 -> V_86 [ V_87 ] ,
V_78 -> V_90 [ V_87 ] ,
V_98 ) ;
F_31 ( & V_6 -> V_38 -> V_39 , V_78 -> V_86 [ V_91 ] ,
V_78 -> V_90 [ V_91 ] ,
V_98 ) ;
F_20 ( V_78 -> V_86 [ V_87 ] ) ;
F_20 ( V_78 -> V_86 [ V_91 ] ) ;
F_96 ( V_104 ) ;
V_15 ( V_78 ) ;
}
for ( V_179 = V_135 + 1 ; V_179 <= V_40 . V_107 ; V_179 ++ ) {
V_178 = & V_5 [ V_179 ] ;
F_35 (pos, tmp, &peer_dev->p2p) {
V_78 = F_36 ( V_104 , struct V_76 , V_108 ) ;
if ( V_78 -> V_97 == V_6 -> V_42 ) {
F_31 ( & V_178 -> V_38 -> V_39 ,
V_78 -> V_86 [ V_87 ] ,
V_78 -> V_90 [ V_87 ] ,
V_98 ) ;
F_31 ( & V_178 -> V_38 -> V_39 ,
V_78 -> V_86 [ V_91 ] ,
V_78 -> V_90 [ V_91 ] ,
V_98 ) ;
F_20 ( V_78 -> V_86 [ V_87 ] ) ;
F_20 ( V_78 -> V_86 [ V_91 ] ) ;
F_96 ( V_104 ) ;
V_15 ( V_78 ) ;
}
}
}
F_45 ( & V_40 . V_118 ) ;
}
