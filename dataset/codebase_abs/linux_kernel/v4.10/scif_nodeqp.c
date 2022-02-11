int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
int V_4 , struct V_5 * V_6 )
{
void * V_7 = V_2 -> V_8 . V_9 ;
int V_10 = 0 ;
T_2 V_11 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_13 ) ;
if ( ! V_7 ) {
V_7 = F_3 ( V_4 , V_14 ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
return V_10 ;
}
}
V_10 = F_4 ( & V_2 -> V_16 , V_7 , V_6 , V_4 ) ;
if ( V_10 )
goto V_17;
F_5 ( & V_2 -> V_8 ,
& V_11 ,
& V_2 -> V_18 ,
V_7 , F_6 ( V_4 ) ) ;
V_2 -> V_8 . V_19 = NULL ;
V_10 = F_4 ( V_3 , V_2 ,
V_6 , sizeof( struct V_1 ) ) ;
if ( V_10 )
goto V_20;
V_2 -> V_21 = * V_3 ;
return V_10 ;
V_20:
F_7 ( V_2 -> V_16 , V_6 , V_4 ) ;
V_2 -> V_16 = 0 ;
V_17:
V_17 ( V_7 ) ;
return V_10 ;
}
int F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_22 , int V_4 ,
struct V_5 * V_6 )
{
void * V_7 ;
void * V_23 ;
struct V_1 * V_24 ;
int V_25 ;
int V_10 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_13 ) ;
V_24 = F_9 ( V_22 , sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_24 )
return - V_26 ;
V_2 -> V_24 = V_24 ;
if ( V_2 -> V_24 -> V_27 != V_28 ) {
V_10 = - V_26 ;
goto V_29;
}
V_2 -> V_30 = V_24 -> V_16 ;
V_25 = V_2 -> V_24 -> V_8 . V_31 ;
V_23 = F_9 ( V_2 -> V_30 , V_25 , V_6 ) ;
if ( ! V_23 ) {
V_10 = - V_26 ;
goto V_29;
}
V_2 -> V_24 -> V_18 = 0 ;
F_5 ( & V_2 -> V_32 ,
& V_2 -> V_33 ,
& V_2 -> V_24 -> V_18 ,
V_23 ,
F_6 ( V_25 ) ) ;
V_7 = F_3 ( V_4 , V_14 ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
goto V_34;
}
V_10 = F_4 ( & V_2 -> V_16 , V_7 , V_6 , V_4 ) ;
if ( V_10 )
goto V_17;
V_2 -> V_24 -> V_33 = 0 ;
F_5 ( & V_2 -> V_8 ,
& V_2 -> V_24 -> V_33 ,
& V_2 -> V_18 ,
V_7 , F_6 ( V_4 ) ) ;
V_10 = F_4 ( V_3 , V_2 , V_6 ,
sizeof( struct V_1 ) ) ;
if ( V_10 )
goto V_20;
V_2 -> V_21 = * V_3 ;
return V_10 ;
V_20:
F_7 ( V_2 -> V_16 , V_6 , V_4 ) ;
V_2 -> V_16 = 0 ;
V_17:
V_17 ( V_7 ) ;
V_34:
F_10 ( V_23 , V_25 , V_6 ) ;
V_2 -> V_32 . V_9 = NULL ;
V_29:
F_10 ( V_2 -> V_24 , sizeof( struct V_1 ) , V_6 ) ;
V_2 -> V_24 = NULL ;
return V_10 ;
}
int F_11 ( struct V_5 * V_6 ,
struct V_1 * V_2 , T_3 V_35 )
{
int V_10 = 0 ;
void * V_36 ;
int V_25 ;
T_4 V_37 ;
V_2 -> V_24 = F_9 ( V_35 , sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_2 -> V_24 ) {
V_10 = - V_15 ;
goto error;
}
if ( V_2 -> V_24 -> V_27 != V_28 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_1 ,
V_5 [ V_40 . V_41 ] . V_42 , V_6 -> V_42 ) ;
V_10 = - V_43 ;
goto error;
}
V_37 = V_2 -> V_24 -> V_16 ;
V_25 = V_2 -> V_24 -> V_8 . V_31 ;
V_36 = F_9 ( V_37 , V_25 , V_6 ) ;
if ( ! V_36 )
return - V_26 ;
V_2 -> V_33 = 0 ;
F_5 ( & V_2 -> V_32 ,
& V_2 -> V_33 ,
& V_2 -> V_24 -> V_18 ,
V_36 ,
F_6 ( V_25 ) ) ;
V_2 -> V_24 -> V_33 = V_2 -> V_8 . V_44 ;
F_5 ( & V_2 -> V_8 ,
& V_2 -> V_24 -> V_33 ,
& V_2 -> V_18 ,
V_2 -> V_8 . V_9 ,
F_6 ( V_2 -> V_8 . V_31 ) ) ;
error:
return V_10 ;
}
static T_5 void
F_13 ( struct V_5 * V_6 )
{
struct V_45 * V_38 = V_6 -> V_38 ;
if ( F_14 ( V_6 ) )
V_38 -> V_46 -> V_47 ( V_38 , V_6 -> V_48 , & V_6 -> V_49 ) ;
else
V_38 -> V_46 -> V_50 ( V_38 , V_6 -> V_48 ) ;
}
int F_15 ( T_4 V_22 , struct V_5 * V_6 )
{
int V_10 = 0 ;
struct V_51 V_52 ;
V_10 = F_11 ( V_6 , V_6 -> V_53 , V_22 ) ;
if ( ! V_10 ) {
V_52 . V_54 = V_55 ;
V_52 . V_56 . V_42 = V_6 -> V_42 ;
V_10 = F_16 ( V_6 , & V_52 ) ;
}
return V_10 ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_51 V_52 ;
int V_57 ;
V_6 -> exit = V_58 ;
V_52 . V_54 = V_59 ;
V_52 . V_60 . V_42 = V_40 . V_41 ;
V_52 . V_56 . V_42 = V_6 -> V_42 ;
V_57 = F_16 ( V_6 , & V_52 ) ;
if ( V_57 )
goto V_61;
F_18 ( V_40 . V_62 , V_6 -> exit == V_63 ,
V_64 ) ;
V_61:
V_6 -> exit = V_65 ;
}
int F_19 ( struct V_5 * V_6 )
{
int V_10 = 0 ;
int V_4 ;
struct V_1 * V_2 ;
V_4 = V_66 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 ) {
V_10 = - V_15 ;
return V_10 ;
}
V_2 -> V_27 = V_28 ;
V_6 -> V_53 = V_2 ;
V_10 = F_1 ( V_2 , & V_6 -> V_67 ,
V_4 , V_6 ) ;
if ( V_10 )
goto V_68;
return V_10 ;
V_68:
V_17 ( V_6 -> V_53 ) ;
V_6 -> V_53 = NULL ;
return V_10 ;
}
static void F_20 ( struct V_69 * V_70 )
{
V_17 ( V_70 ) ;
}
static struct V_69 *
F_21 ( T_4 V_71 , int V_72 , int V_73 )
{
struct V_69 * V_70 ;
struct V_74 * V_74 ;
int V_75 ;
V_70 = F_22 ( V_73 , sizeof( struct V_69 ) , V_14 ) ;
if ( ! V_70 )
return NULL ;
F_23 ( V_70 , V_73 ) ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ ) {
V_74 = F_24 ( V_71 >> V_76 ) ;
F_25 ( & V_70 [ V_75 ] , V_74 , V_72 , 0 ) ;
V_71 += V_72 ;
}
return V_70 ;
}
static struct V_77 *
F_26 ( struct V_5 * V_6 , struct V_5 * V_78 )
{
struct V_77 * V_79 ;
int V_80 , V_81 , V_82 , V_10 , V_83 ;
struct V_45 * V_84 = V_78 -> V_38 ;
struct V_45 * V_38 = V_6 -> V_38 ;
V_80 = V_84 -> V_49 -> V_85 >> V_76 ;
V_81 = V_84 -> V_86 -> V_85 >> V_76 ;
V_79 = F_3 ( sizeof( * V_79 ) , V_14 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> V_87 [ V_88 ] = F_21 ( V_84 -> V_49 -> V_71 ,
V_89 , V_80 ) ;
if ( ! V_79 -> V_87 [ V_88 ] )
goto V_90;
V_79 -> V_91 [ V_88 ] = V_80 ;
V_82 = F_27 ( F_28 ( V_84 -> V_86 -> V_85 , ( T_3 ) ( 1 << 30 ) ) ) ;
V_83 = V_81 >> ( V_82 - V_76 ) ;
V_79 -> V_87 [ V_92 ] = F_21 ( V_84 -> V_86 -> V_71 ,
1 << V_82 ,
V_83 ) ;
V_79 -> V_91 [ V_92 ] = V_83 ;
V_10 = F_29 ( & V_38 -> V_39 , V_79 -> V_87 [ V_88 ] ,
V_80 , V_93 ) ;
if ( V_10 != V_80 )
goto V_94;
V_10 = F_29 ( & V_38 -> V_39 , V_79 -> V_87 [ V_92 ] ,
V_83 , V_93 ) ;
if ( V_10 != V_83 )
goto V_95;
V_79 -> V_96 [ V_88 ] = F_30 ( V_79 -> V_87 [ V_88 ] ) ;
V_79 -> V_96 [ V_92 ] = F_30 ( V_79 -> V_87 [ V_92 ] ) ;
V_79 -> V_97 [ V_88 ] = V_80 ;
V_79 -> V_97 [ V_92 ] = V_81 ;
V_79 -> V_98 = V_78 -> V_42 ;
return V_79 ;
V_95:
F_31 ( & V_38 -> V_39 , V_79 -> V_87 [ V_88 ] ,
V_79 -> V_91 [ V_88 ] , V_99 ) ;
V_94:
F_20 ( V_79 -> V_87 [ V_88 ] ) ;
F_20 ( V_79 -> V_87 [ V_92 ] ) ;
V_90:
V_17 ( V_79 ) ;
return NULL ;
}
static void F_32 ( struct V_5 * V_6 ,
struct V_77 * V_79 )
{
struct V_45 * V_38 = V_6 -> V_38 ;
F_31 ( & V_38 -> V_39 , V_79 -> V_87 [ V_88 ] ,
V_79 -> V_91 [ V_88 ] , V_99 ) ;
F_31 ( & V_38 -> V_39 , V_79 -> V_87 [ V_92 ] ,
V_79 -> V_91 [ V_92 ] , V_99 ) ;
F_20 ( V_79 -> V_87 [ V_88 ] ) ;
F_20 ( V_79 -> V_87 [ V_92 ] ) ;
V_17 ( V_79 ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_56 )
{
struct V_5 * V_100 = V_6 ;
struct V_5 * V_101 = NULL ;
struct V_77 * V_102 = NULL ;
struct V_77 * V_103 = NULL ;
struct V_77 * V_79 ;
struct V_104 * V_105 , * V_106 ;
struct V_51 V_52 ;
int V_10 ;
T_3 V_107 ;
if ( V_56 < 1 || V_56 > V_40 . V_108 )
return;
V_101 = & V_5 [ V_56 ] ;
if ( ! F_34 ( V_101 ) )
return;
if ( ! F_35 ( & V_101 -> V_79 ) ) {
F_36 (pos, tmp, &dev_i->p2p) {
V_79 = F_37 ( V_105 , struct V_77 , V_109 ) ;
if ( V_79 -> V_98 == V_100 -> V_42 )
return;
}
}
V_102 = F_26 ( V_101 , V_100 ) ;
if ( ! V_102 )
return;
V_103 = F_26 ( V_100 , V_101 ) ;
if ( ! V_103 ) {
F_32 ( V_101 , V_102 ) ;
return;
}
F_38 ( & V_102 -> V_109 , & V_101 -> V_79 ) ;
F_38 ( & V_103 -> V_109 , & V_100 -> V_79 ) ;
V_52 . V_54 = V_110 ;
V_52 . V_60 . V_42 = V_100 -> V_42 ;
V_52 . V_56 . V_42 = V_101 -> V_42 ;
V_52 . V_35 [ 0 ] = V_103 -> V_96 [ V_92 ] ;
V_52 . V_35 [ 1 ] = V_102 -> V_96 [ V_88 ] ;
V_52 . V_35 [ 2 ] = V_102 -> V_96 [ V_92 ] ;
V_52 . V_35 [ 3 ] = V_102 -> V_97 [ V_92 ] << V_76 ;
V_10 = F_16 ( V_101 , & V_52 ) ;
if ( V_10 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_2 , V_111 , __LINE__ , V_10 ) ;
return;
}
V_52 . V_54 = V_110 ;
V_52 . V_60 . V_42 = V_101 -> V_42 ;
V_52 . V_56 . V_42 = V_100 -> V_42 ;
V_107 = V_52 . V_35 [ 0 ] ;
V_52 . V_35 [ 0 ] = V_52 . V_35 [ 2 ] ;
V_52 . V_35 [ 2 ] = V_107 ;
V_52 . V_35 [ 1 ] = V_103 -> V_96 [ V_88 ] ;
V_52 . V_35 [ 3 ] = V_103 -> V_97 [ V_92 ] << V_76 ;
F_16 ( V_100 , & V_52 ) ;
}
static void F_39 ( void )
{
int V_75 , V_112 ;
if ( ! V_40 . V_113 )
return;
for ( V_75 = 1 ; V_75 <= V_40 . V_108 ; V_75 ++ )
if ( ! F_34 ( & V_5 [ V_75 ] ) )
return;
for ( V_75 = 1 ; V_75 <= V_40 . V_108 ; V_75 ++ ) {
for ( V_112 = 1 ; V_112 <= V_40 . V_108 ; V_112 ++ ) {
struct V_5 * V_6 = & V_5 [ V_75 ] ;
if ( V_75 == V_112 )
continue;
F_33 ( V_6 , V_112 ) ;
}
}
}
static void
F_40 ( struct V_5 * V_6 , struct V_51 * V_52 ,
const char * V_114 )
{
if ( ! V_40 . V_115 )
return;
if ( V_52 -> V_54 > V_116 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_3 , V_114 , V_52 -> V_54 ) ;
return;
}
F_41 ( & V_6 -> V_38 -> V_39 ,
L_4 ,
V_114 , V_117 [ V_52 -> V_54 ] , V_52 -> V_60 . V_42 , V_52 -> V_60 . V_118 ,
V_52 -> V_56 . V_42 , V_52 -> V_56 . V_118 , V_52 -> V_35 [ 0 ] , V_52 -> V_35 [ 1 ] ,
V_52 -> V_35 [ 2 ] , V_52 -> V_35 [ 3 ] ) ;
}
int F_42 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_6 -> V_53 ;
int V_10 = - V_15 , V_119 = 0 ;
F_40 ( V_6 , V_52 , L_5 ) ;
if ( ! V_2 ) {
V_10 = - V_120 ;
goto error;
}
F_43 ( & V_2 -> V_12 ) ;
while ( ( V_10 = F_44 ( & V_2 -> V_32 ,
V_52 , sizeof( struct V_51 ) ) ) ) {
F_45 ( 1 ) ;
#define F_46 (3 * 1000)
if ( V_119 ++ > ( F_46 ) ) {
V_10 = - V_43 ;
break;
}
}
if ( ! V_10 )
F_47 ( & V_2 -> V_32 ) ;
F_48 ( & V_2 -> V_12 ) ;
if ( ! V_10 ) {
if ( F_49 ( V_6 ) )
F_50 ( V_6 -> V_121 , & V_6 -> V_122 ) ;
else
F_13 ( V_6 ) ;
}
error:
if ( V_10 )
F_51 ( & V_6 -> V_38 -> V_39 ,
L_6 ,
V_111 , __LINE__ , V_10 , V_52 -> V_54 ) ;
return V_10 ;
}
int F_16 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
int V_10 ;
struct V_123 * V_124 = NULL ;
if ( V_52 -> V_54 > V_125 ) {
if ( V_65 != V_6 -> exit )
return - V_43 ;
V_124 = F_52 ( V_6 ) ;
if ( F_53 ( V_124 ) ) {
V_10 = F_54 ( V_124 ) ;
return V_10 ;
}
}
V_10 = F_42 ( V_6 , V_52 ) ;
if ( V_52 -> V_54 > V_125 )
F_55 ( V_124 ) ;
return V_10 ;
}
void F_56 ( struct V_126 * V_127 )
{
F_57 () ;
F_58 () ;
F_59 () ;
F_60 () ;
}
static T_5 void
F_61 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
F_62 ( & V_6 -> V_128 ) ;
F_63 ( V_6 ) ;
if ( F_64 () ) {
F_65 ( & V_40 . V_129 ) ;
F_39 () ;
F_66 ( & V_40 . V_129 ) ;
}
}
static T_5 void
F_67 ( struct V_5 * V_6 , struct V_51 * V_130 )
{
V_6 -> V_131 = true ;
if ( F_64 () )
F_68 ( V_6 -> V_42 , false ) ;
else
F_69 ( V_6 ) ;
F_70 ( & V_6 -> V_128 ,
F_71 ( 1000 ) ) ;
}
static T_5 void
F_72 ( struct V_5 * V_6 , struct V_51 * V_130 )
{
V_6 -> exit = V_63 ;
F_73 ( & V_40 . V_62 ) ;
}
static T_5 void
F_74 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_5 * V_132 ;
T_1 V_3 ;
int V_133 ;
struct V_45 * V_38 ;
F_51 ( & V_6 -> V_38 -> V_39 ,
L_7 ,
V_6 -> V_42 , V_52 -> V_56 . V_42 , V_52 -> V_60 . V_42 ) ;
F_51 ( & V_6 -> V_38 -> V_39 ,
L_8 ,
V_52 -> V_35 [ 0 ] ) ;
V_132 = & V_5 [ V_52 -> V_60 . V_42 ] ;
V_132 -> V_42 = V_52 -> V_60 . V_42 ;
V_132 -> V_38 = V_5 [ V_134 ] . V_38 ;
V_38 = V_132 -> V_38 ;
if ( F_75 ( V_132 ) ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_9 , V_52 -> V_60 . V_42 ) ;
goto V_135;
}
V_132 -> V_49 . V_136 = F_76 ( V_52 -> V_35 [ 1 ] , V_38 -> V_49 -> V_85 ) ;
if ( ! V_132 -> V_49 . V_136 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_10 , V_52 -> V_60 . V_42 ) ;
goto V_137;
}
V_132 -> V_53 = F_3 ( sizeof( * V_132 -> V_53 ) , V_14 ) ;
if ( ! V_132 -> V_53 )
goto V_138;
V_132 -> V_139 = V_52 -> V_35 [ 0 ] ;
V_133 = F_1 ( V_132 -> V_53 , & V_3 ,
V_66 , V_132 ) ;
if ( V_133 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_11 , V_133 ) ;
goto V_140;
}
V_132 -> V_141 = V_38 -> V_46 -> V_142 ( V_38 ) ;
V_132 -> V_143 = V_38 -> V_46 -> V_144 ( V_38 , V_145 ,
L_12 , V_132 ,
V_132 -> V_141 ) ;
if ( F_53 ( V_132 -> V_143 ) )
goto V_140;
V_132 -> V_53 -> V_27 = V_28 ;
V_132 -> V_53 -> V_146 = V_147 ;
V_52 -> V_54 = V_148 ;
V_52 -> V_56 . V_42 = V_52 -> V_60 . V_42 ;
V_52 -> V_60 . V_42 = V_40 . V_41 ;
V_52 -> V_35 [ 0 ] = V_3 ;
V_52 -> V_35 [ 2 ] = V_132 -> V_141 ;
F_16 ( & V_5 [ V_134 ] , V_52 ) ;
return;
V_140:
V_17 ( V_132 -> V_53 ) ;
V_132 -> V_53 = NULL ;
V_138:
V_29 ( V_132 -> V_49 . V_136 ) ;
V_132 -> V_49 . V_136 = NULL ;
V_137:
V_135:
F_12 ( & V_6 -> V_38 -> V_39 ,
L_13 , V_52 -> V_60 . V_42 ) ;
V_52 -> V_54 = V_149 ;
V_52 -> V_56 . V_42 = V_52 -> V_60 . V_42 ;
V_52 -> V_60 . V_42 = V_40 . V_41 ;
F_16 ( & V_5 [ V_134 ] , V_52 ) ;
}
void F_77 ( struct V_126 * V_127 )
{
#define F_78 100
#define F_79 100
struct V_5 * V_78 = F_80 ( V_127 , struct V_5 ,
V_150 . V_127 ) ;
struct V_1 * V_2 = & V_78 -> V_53 [ 0 ] ;
if ( V_2 -> V_146 != V_151 ||
V_2 -> V_24 -> V_146 != V_151 ) {
if ( V_78 -> V_152 ++ == F_78 ) {
F_12 ( & V_78 -> V_38 -> V_39 ,
L_14 ,
V_2 -> V_146 ) ;
goto V_153;
}
F_70 ( & V_78 -> V_150 ,
F_71 ( F_79 ) ) ;
return;
}
return;
V_153:
F_12 ( & V_78 -> V_38 -> V_39 ,
L_15 ,
V_111 , __LINE__ , V_78 -> V_42 , V_2 -> V_146 ) ;
V_2 -> V_24 -> V_146 = V_147 ;
F_81 ( V_78 ) ;
F_82 ( V_78 ) ;
}
static T_5 void
F_83 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_5 * V_78 ;
struct V_1 * V_2 ;
struct V_5 * V_154 = & V_5 [ V_52 -> V_56 . V_42 ] ;
F_51 ( & V_6 -> V_38 -> V_39 ,
L_16 ,
V_6 -> V_42 , V_52 -> V_60 . V_42 , V_52 -> V_56 . V_42 ) ;
F_51 ( & V_6 -> V_38 -> V_39 ,
L_17 , V_52 -> V_35 [ 0 ] ,
V_52 -> V_35 [ 1 ] , V_52 -> V_35 [ 2 ] , V_52 -> V_35 [ 3 ] ) ;
if ( F_64 () ) {
F_65 ( & V_40 . V_129 ) ;
V_52 -> V_35 [ 1 ] = V_40 . V_108 ;
F_16 ( V_154 , V_52 ) ;
F_66 ( & V_40 . V_129 ) ;
return;
}
V_78 = & V_5 [ V_52 -> V_60 . V_42 ] ;
V_78 -> V_38 = V_5 [ V_134 ] . V_38 ;
V_78 -> V_42 = V_52 -> V_60 . V_42 ;
V_2 = & V_78 -> V_53 [ 0 ] ;
if ( ( F_11 ( V_78 , & V_78 -> V_53 [ 0 ] ,
V_52 -> V_35 [ 0 ] ) ) )
goto V_155;
V_78 -> V_48 = V_52 -> V_35 [ 2 ] ;
V_2 -> V_24 -> V_146 = V_151 ;
F_63 ( V_78 ) ;
F_70 ( & V_78 -> V_150 , 0 ) ;
return;
V_155:
F_82 ( V_78 ) ;
}
static T_5 void
F_84 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
if ( F_64 () ) {
struct V_5 * V_154 = & V_5 [ V_52 -> V_56 . V_42 ] ;
F_51 ( & V_6 -> V_38 -> V_39 ,
L_18 , V_6 -> V_42 ) ;
F_16 ( V_154 , V_52 ) ;
}
}
static T_5 void
F_85 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
int V_42 = V_52 -> V_35 [ 0 ] ;
struct V_5 * V_156 = & V_5 [ V_42 ] ;
V_156 -> V_157 = true ;
F_86 ( V_42 ) ;
}
static T_5 void
F_87 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_5 * V_38 = & V_5 [ V_52 -> V_35 [ 0 ] ] ;
F_88 ( & V_38 -> V_158 ) ;
F_73 ( & V_38 -> V_159 ) ;
}
static T_5 void
F_89 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
if ( F_64 () ) {
F_90 ( V_52 -> V_56 . V_42 , V_52 -> V_60 . V_42 ) ;
F_65 ( & V_40 . V_129 ) ;
V_52 -> V_35 [ 1 ] = V_40 . V_108 ;
V_52 -> V_35 [ 2 ] = V_40 . V_160 ;
F_66 ( & V_40 . V_129 ) ;
F_16 ( V_6 , V_52 ) ;
} else {
struct V_161 * V_162 =
(struct V_161 * ) V_52 -> V_35 [ 3 ] ;
F_65 ( & V_40 . V_129 ) ;
V_40 . V_108 = V_52 -> V_35 [ 1 ] ;
V_40 . V_160 = V_52 -> V_35 [ 2 ] ;
F_91 ( V_162 ) ;
F_66 ( & V_40 . V_129 ) ;
}
}
static void
F_92 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
F_12 ( & V_6 -> V_38 -> V_39 ,
L_19 ,
V_52 -> V_54 , V_6 -> V_42 ) ;
}
static void
F_93 ( struct V_5 * V_6 ,
struct V_1 * V_2 , struct V_51 * V_52 )
{
F_40 ( V_6 , V_52 , L_20 ) ;
if ( V_52 -> V_54 > ( T_2 ) V_163 ) {
F_12 ( & V_6 -> V_38 -> V_39 ,
L_19 ,
V_52 -> V_54 , V_6 -> V_42 ) ;
return;
}
V_164 [ V_52 -> V_54 ] ( V_6 , V_52 ) ;
}
void F_94 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_51 V_52 ;
int V_165 ;
do {
V_165 = F_95 ( & V_2 -> V_8 , & V_52 , sizeof( V_52 ) ) ;
if ( ! V_165 )
break;
F_93 ( V_6 , V_2 , & V_52 ) ;
if ( V_125 == V_52 . V_54 )
break;
F_96 ( & V_2 -> V_8 ) ;
} while ( 1 );
}
static void F_97 ( struct V_126 * V_130 )
{
struct V_5 * V_6 = V_40 . V_166 ;
struct V_1 * V_2 = V_6 -> V_53 ;
struct V_167 * V_52 ;
do {
V_52 = NULL ;
F_43 ( & V_2 -> V_13 ) ;
if ( ! F_35 ( & V_40 . V_168 ) ) {
V_52 = F_98 ( & V_40 . V_168 ,
struct V_167 ,
V_169 ) ;
F_99 ( & V_52 -> V_169 ) ;
}
F_48 ( & V_2 -> V_13 ) ;
if ( V_52 ) {
F_93 ( V_6 , V_2 , & V_52 -> V_52 ) ;
V_17 ( V_52 ) ;
}
} while ( V_52 );
}
int
F_100 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
int V_165 ;
struct V_167 * V_52 ;
do {
V_52 = F_101 ( sizeof( * V_52 ) , V_14 ) ;
if ( ! V_52 )
return - V_15 ;
V_165 = F_95 ( & V_2 -> V_8 , & V_52 -> V_52 ,
sizeof( struct V_51 ) ) ;
if ( V_165 != sizeof( struct V_51 ) ) {
V_17 ( V_52 ) ;
F_96 ( & V_2 -> V_8 ) ;
break;
}
F_43 ( & V_2 -> V_13 ) ;
F_38 ( & V_52 -> V_169 , & V_40 . V_168 ) ;
F_48 ( & V_2 -> V_13 ) ;
F_50 ( V_40 . V_170 , & V_40 . V_171 ) ;
F_96 ( & V_2 -> V_8 ) ;
} while ( V_165 == sizeof( struct V_51 ) );
return V_165 ;
}
int F_102 ( struct V_5 * V_6 )
{
int V_10 = 0 ;
void * V_7 ;
struct V_1 * V_2 ;
V_10 = F_75 ( V_6 ) ;
if ( V_10 )
goto exit;
F_103 ( & V_40 . V_168 ) ;
snprintf ( V_40 . V_172 , sizeof( V_40 . V_172 ) ,
L_21 , V_6 -> V_42 ) ;
V_40 . V_170 =
F_104 ( V_40 . V_172 , 0 ) ;
if ( ! V_40 . V_170 ) {
V_10 = - V_15 ;
goto V_173;
}
F_105 ( & V_40 . V_171 , F_97 ) ;
V_6 -> V_53 = F_3 ( sizeof( * V_6 -> V_53 ) , V_14 ) ;
if ( ! V_6 -> V_53 ) {
V_10 = - V_15 ;
goto V_174;
}
V_2 = V_6 -> V_53 ;
V_2 -> V_27 = V_28 ;
F_2 ( & V_2 -> V_12 ) ;
F_2 ( & V_2 -> V_13 ) ;
V_7 = F_3 ( V_66 , V_14 ) ;
if ( ! V_7 ) {
V_10 = - V_15 ;
goto V_175;
}
F_5 ( & V_2 -> V_32 ,
& V_2 -> V_33 ,
& V_2 -> V_18 ,
V_7 , F_6 ( V_66 ) ) ;
F_5 ( & V_2 -> V_8 ,
& V_2 -> V_33 ,
& V_2 -> V_18 ,
V_7 , F_6 ( V_66 ) ) ;
V_40 . V_41 = V_6 -> V_42 ;
F_63 ( V_6 ) ;
V_40 . V_166 = V_6 ;
return V_10 ;
V_175:
V_17 ( V_6 -> V_53 ) ;
V_174:
F_106 ( V_40 . V_170 ) ;
V_173:
F_107 ( V_6 ) ;
exit:
return V_10 ;
}
int F_108 ( struct V_5 * V_6 )
{
F_81 ( V_6 ) ;
F_106 ( V_40 . V_170 ) ;
F_107 ( V_6 ) ;
V_17 ( V_6 -> V_53 -> V_32 . V_9 ) ;
V_17 ( V_6 -> V_53 ) ;
V_6 -> V_38 = NULL ;
V_40 . V_166 = NULL ;
return 0 ;
}
void F_109 ( struct V_5 * V_6 )
{
struct V_5 * V_176 ;
struct V_77 * V_79 ;
struct V_104 * V_105 , * V_106 ;
int V_177 ;
F_65 ( & V_40 . V_129 ) ;
F_36 (pos, tmp, &scifdev->p2p) {
V_79 = F_37 ( V_105 , struct V_77 , V_109 ) ;
F_31 ( & V_6 -> V_38 -> V_39 , V_79 -> V_87 [ V_88 ] ,
V_79 -> V_91 [ V_88 ] ,
V_99 ) ;
F_31 ( & V_6 -> V_38 -> V_39 , V_79 -> V_87 [ V_92 ] ,
V_79 -> V_91 [ V_92 ] ,
V_99 ) ;
F_20 ( V_79 -> V_87 [ V_88 ] ) ;
F_20 ( V_79 -> V_87 [ V_92 ] ) ;
F_99 ( V_105 ) ;
V_17 ( V_79 ) ;
}
for ( V_177 = V_134 + 1 ; V_177 <= V_40 . V_108 ; V_177 ++ ) {
V_176 = & V_5 [ V_177 ] ;
F_36 (pos, tmp, &peer_dev->p2p) {
V_79 = F_37 ( V_105 , struct V_77 , V_109 ) ;
if ( V_79 -> V_98 == V_6 -> V_42 ) {
F_31 ( & V_176 -> V_38 -> V_39 ,
V_79 -> V_87 [ V_88 ] ,
V_79 -> V_91 [ V_88 ] ,
V_99 ) ;
F_31 ( & V_176 -> V_38 -> V_39 ,
V_79 -> V_87 [ V_92 ] ,
V_79 -> V_91 [ V_92 ] ,
V_99 ) ;
F_20 ( V_79 -> V_87 [ V_88 ] ) ;
F_20 ( V_79 -> V_87 [ V_92 ] ) ;
F_99 ( V_105 ) ;
V_17 ( V_79 ) ;
}
}
}
F_66 ( & V_40 . V_129 ) ;
}
