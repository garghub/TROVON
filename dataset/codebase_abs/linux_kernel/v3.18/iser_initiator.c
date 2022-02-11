static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_9 . V_7 ;
struct V_10 * V_11 ;
int V_12 ;
struct V_13 * V_14 = & V_4 -> V_15 . V_16 ;
struct V_17 * V_18 = & V_4 -> V_19 [ V_20 ] ;
V_12 = F_2 ( V_4 ,
V_18 ,
V_20 ,
V_21 ) ;
if ( V_12 )
return V_12 ;
if ( F_3 ( V_4 -> V_22 ) ) {
struct V_17 * V_23 = & V_4 -> V_24 [ V_20 ] ;
V_12 = F_2 ( V_4 ,
V_23 ,
V_20 ,
V_21 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = V_7 -> V_25 ( V_4 , V_20 ) ;
if ( V_12 ) {
F_4 ( L_1 ) ;
return V_12 ;
}
V_11 = & V_4 -> V_26 [ V_20 ] ;
V_14 -> V_27 |= V_28 ;
V_14 -> V_29 = F_5 ( V_11 -> V_30 . V_31 ) ;
V_14 -> V_32 = F_6 ( V_11 -> V_30 . V_33 ) ;
F_7 ( L_2 ,
V_2 -> V_34 , V_11 -> V_30 . V_31 ,
( unsigned long long ) V_11 -> V_30 . V_33 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
unsigned int V_35 ,
unsigned int V_36 ,
unsigned int V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_9 . V_7 ;
struct V_10 * V_11 ;
int V_12 ;
struct V_13 * V_14 = & V_4 -> V_15 . V_16 ;
struct V_17 * V_38 = & V_4 -> V_19 [ V_39 ] ;
struct V_40 * V_41 = & V_4 -> V_15 . V_42 [ 1 ] ;
V_12 = F_2 ( V_4 ,
V_38 ,
V_39 ,
V_43 ) ;
if ( V_12 )
return V_12 ;
if ( F_3 ( V_4 -> V_22 ) ) {
struct V_17 * V_44 = & V_4 -> V_24 [ V_39 ] ;
V_12 = F_2 ( V_4 ,
V_44 ,
V_39 ,
V_43 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = V_7 -> V_25 ( V_4 , V_39 ) ;
if ( V_12 != 0 ) {
F_4 ( L_3 ) ;
return V_12 ;
}
V_11 = & V_4 -> V_26 [ V_39 ] ;
if ( V_36 < V_37 ) {
V_14 -> V_27 |= V_45 ;
V_14 -> V_46 = F_5 ( V_11 -> V_30 . V_31 ) ;
V_14 -> V_47 = F_6 ( V_11 -> V_30 . V_33 + V_36 ) ;
F_7 ( L_4
L_5 ,
V_2 -> V_34 , V_11 -> V_30 . V_31 ,
( unsigned long long ) V_11 -> V_30 . V_33 , V_36 ) ;
}
if ( V_35 > 0 ) {
F_7 ( L_6 ,
V_2 -> V_34 , V_35 ) ;
V_41 -> V_48 = V_11 -> V_30 . V_33 ;
V_41 -> V_49 = V_35 ;
V_41 -> V_50 = V_11 -> V_30 . V_50 ;
V_4 -> V_15 . V_51 = 2 ;
}
return 0 ;
}
static void F_9 ( struct V_8 * V_8 ,
struct V_52 * V_53 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
F_10 ( V_7 -> V_54 ,
V_53 -> V_55 , V_56 , V_43 ) ;
memset ( & V_53 -> V_16 , 0 , sizeof( struct V_13 ) ) ;
V_53 -> V_16 . V_27 = V_57 ;
V_53 -> V_51 = 1 ;
if ( V_53 -> V_42 [ 0 ] . V_50 != V_7 -> V_58 -> V_50 ) {
V_53 -> V_42 [ 0 ] . V_50 = V_7 -> V_58 -> V_50 ;
F_7 ( L_7 , V_53 ) ;
}
}
static void F_11 ( struct V_8 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
if ( ! V_8 -> V_59 )
return;
if ( V_8 -> V_60 )
F_12 ( V_7 -> V_54 ,
V_8 -> V_60 ,
V_61 , V_43 ) ;
if ( V_8 -> V_62 )
F_12 ( V_7 -> V_54 ,
V_8 -> V_62 ,
V_63 , V_21 ) ;
F_13 ( V_8 -> V_59 ) ;
V_8 -> V_60 = 0 ;
V_8 -> V_62 = 0 ;
V_8 -> V_59 = NULL ;
}
static int F_14 ( struct V_8 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
int V_64 , V_65 ;
F_15 ( V_7 == NULL ) ;
V_8 -> V_59 = F_16 ( V_61 +
V_63 , V_66 ) ;
if ( ! V_8 -> V_59 )
goto V_67;
V_8 -> V_68 = V_8 -> V_59 ;
V_8 -> V_69 = V_8 -> V_59 +
V_61 ;
V_8 -> V_60 = F_17 ( V_7 -> V_54 ,
V_8 -> V_68 ,
V_61 ,
V_43 ) ;
V_8 -> V_62 = F_17 ( V_7 -> V_54 ,
V_8 -> V_69 ,
V_63 ,
V_21 ) ;
V_64 = F_18 ( V_7 -> V_54 ,
V_8 -> V_60 ) ;
V_65 = F_18 ( V_7 -> V_54 ,
V_8 -> V_62 ) ;
if ( V_64 || V_65 ) {
if ( V_64 )
V_8 -> V_60 = 0 ;
if ( V_65 )
V_8 -> V_62 = 0 ;
goto V_70;
}
return 0 ;
V_70:
F_11 ( V_8 ) ;
V_67:
F_4 ( L_8 ) ;
return - V_71 ;
}
int F_19 ( struct V_8 * V_8 ,
struct V_72 * V_73 )
{
int V_74 , V_75 ;
T_1 V_55 ;
struct V_76 * V_77 ;
struct V_40 * V_78 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_6 * V_7 = V_9 -> V_7 ;
V_8 -> V_79 = V_73 -> V_80 ;
V_8 -> V_81 = V_73 -> V_80 - 1 ;
V_8 -> V_82 = V_8 -> V_79 >> 2 ;
if ( V_7 -> V_83 ( V_9 , V_73 -> V_84 ) )
goto V_85;
if ( F_14 ( V_8 ) )
goto V_86;
V_8 -> V_87 = V_73 -> V_80 ;
V_8 -> V_88 = F_16 ( V_8 -> V_87 *
sizeof( struct V_76 ) , V_66 ) ;
if ( ! V_8 -> V_88 )
goto V_89;
V_77 = V_8 -> V_88 ;
for ( V_74 = 0 ; V_74 < V_8 -> V_79 ; V_74 ++ , V_77 ++ ) {
V_55 = F_17 ( V_7 -> V_54 , ( void * ) V_77 ,
V_90 , V_21 ) ;
if ( F_18 ( V_7 -> V_54 , V_55 ) )
goto V_91;
V_77 -> V_55 = V_55 ;
V_78 = & V_77 -> V_78 ;
V_78 -> V_48 = V_77 -> V_55 ;
V_78 -> V_49 = V_90 ;
V_78 -> V_50 = V_7 -> V_58 -> V_50 ;
}
V_8 -> V_92 = 0 ;
return 0 ;
V_91:
V_77 = V_8 -> V_88 ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ , V_77 ++ )
F_12 ( V_7 -> V_54 , V_77 -> V_55 ,
V_90 , V_21 ) ;
F_13 ( V_8 -> V_88 ) ;
V_8 -> V_88 = NULL ;
V_89:
F_11 ( V_8 ) ;
V_86:
V_7 -> V_93 ( V_9 ) ;
V_85:
F_4 ( L_9 ) ;
return - V_71 ;
}
void F_20 ( struct V_8 * V_8 )
{
int V_74 ;
struct V_76 * V_77 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_6 * V_7 = V_9 -> V_7 ;
if ( ! V_8 -> V_88 )
goto V_70;
if ( V_7 -> V_93 )
V_7 -> V_93 ( V_9 ) ;
V_77 = V_8 -> V_88 ;
for ( V_74 = 0 ; V_74 < V_8 -> V_79 ; V_74 ++ , V_77 ++ )
F_12 ( V_7 -> V_54 , V_77 -> V_55 ,
V_90 , V_21 ) ;
F_13 ( V_8 -> V_88 ) ;
V_8 -> V_88 = NULL ;
V_70:
F_11 ( V_8 ) ;
}
static int F_21 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_8 * V_8 = V_95 -> V_5 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_72 * V_73 = V_95 -> V_73 ;
F_7 ( L_10 , V_97 -> V_98 , V_97 -> V_27 ) ;
if ( ( V_97 -> V_27 & V_99 ) != V_99 )
return 0 ;
F_22 ( V_9 -> V_100 != 1 ) ;
if ( V_73 -> V_101 ) {
F_23 ( L_11 ) ;
return 0 ;
} else
F_23 ( L_12 ,
V_8 -> V_82 ) ;
if ( F_24 ( V_8 , V_8 -> V_82 ) )
return - V_71 ;
return 0 ;
}
static inline bool F_25 ( int V_102 )
{
return ( ( V_102 % V_103 ) == 0 ) ;
}
int F_26 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_8 * V_8 = V_95 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_37 ;
int V_12 ;
struct V_17 * V_104 , * V_105 ;
struct V_106 * V_14 = (struct V_106 * ) V_2 -> V_14 ;
struct V_107 * V_22 = V_2 -> V_22 ;
struct V_52 * V_53 = & V_4 -> V_15 ;
static unsigned V_102 ;
V_37 = F_27 ( V_14 -> V_108 ) ;
V_53 -> type = V_109 ;
F_9 ( V_8 , V_53 ) ;
if ( V_14 -> V_27 & V_110 ) {
V_104 = & V_4 -> V_19 [ V_20 ] ;
V_105 = & V_4 -> V_24 [ V_20 ] ;
} else {
V_104 = & V_4 -> V_19 [ V_39 ] ;
V_105 = & V_4 -> V_24 [ V_39 ] ;
}
if ( F_28 ( V_22 ) ) {
V_104 -> V_111 = F_29 ( V_22 ) ;
V_104 -> V_112 = F_28 ( V_22 ) ;
}
V_104 -> V_113 = F_30 ( V_22 ) ;
if ( F_3 ( V_22 ) ) {
V_105 -> V_111 = F_31 ( V_22 ) ;
V_105 -> V_112 = F_3 ( V_22 ) ;
V_105 -> V_113 = V_104 -> V_113 >>
F_32 ( V_22 -> V_7 -> V_114 ) * 8 ;
}
if ( V_14 -> V_27 & V_110 ) {
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
goto V_115;
}
if ( V_14 -> V_27 & V_116 ) {
V_12 = F_8 ( V_2 ,
V_2 -> V_117 ,
V_2 -> V_117 +
V_2 -> V_118 . V_108 ,
V_37 ) ;
if ( V_12 )
goto V_115;
}
V_4 -> V_119 = V_120 ;
V_12 = F_33 ( & V_8 -> V_9 , V_53 ,
F_25 ( ++ V_102 ) ) ;
if ( ! V_12 )
return 0 ;
V_115:
F_4 ( L_13 , V_95 , V_2 -> V_34 , V_12 ) ;
return V_12 ;
}
int F_34 ( struct V_94 * V_95 ,
struct V_1 * V_2 ,
struct V_121 * V_14 )
{
struct V_8 * V_8 = V_95 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = NULL ;
struct V_10 * V_11 ;
unsigned long V_122 ;
unsigned long V_123 ;
T_2 V_34 ;
int V_12 = 0 ;
struct V_40 * V_41 ;
V_34 = ( V_124 T_2 ) V_14 -> V_34 ;
V_123 = F_35 ( V_14 -> V_125 ) ;
V_122 = F_27 ( V_14 -> V_126 ) ;
F_7 ( L_14 ,
V_127 , ( int ) V_34 , ( int ) V_123 , ( int ) V_122 ) ;
V_53 = F_36 ( V_128 . V_129 , V_130 ) ;
if ( V_53 == NULL ) {
F_4 ( L_15 ) ;
return - V_71 ;
}
V_53 -> type = V_131 ;
V_53 -> V_16 . V_27 = V_57 ;
memcpy ( & V_53 -> V_132 , V_14 , sizeof( struct V_96 ) ) ;
F_37 ( V_2 , V_53 ) ;
V_11 = & V_4 -> V_26 [ V_39 ] ;
V_41 = & V_53 -> V_42 [ 1 ] ;
V_41 -> V_48 = V_11 -> V_30 . V_33 + V_122 ;
V_41 -> V_49 = V_123 ;
V_41 -> V_50 = V_11 -> V_30 . V_50 ;
V_53 -> V_51 = 2 ;
if ( V_122 + V_123 > V_4 -> V_19 [ V_39 ] . V_113 ) {
F_4 ( L_16
L_17 ,
V_122 , V_123 ,
V_4 -> V_19 [ V_39 ] . V_113 , V_34 ) ;
V_12 = - V_133 ;
goto V_134;
}
F_7 ( L_18 ,
V_34 , V_122 , V_123 ) ;
V_12 = F_33 ( & V_8 -> V_9 , V_53 , true ) ;
if ( ! V_12 )
return 0 ;
V_134:
F_38 ( V_128 . V_129 , V_53 ) ;
F_4 ( L_19 , V_95 , V_12 ) ;
return V_12 ;
}
int F_39 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_8 * V_8 = V_95 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_135 = & V_4 -> V_15 ;
unsigned long V_123 ;
int V_12 = 0 ;
struct V_6 * V_7 ;
V_135 -> type = V_136 ;
F_9 ( V_8 , V_135 ) ;
V_7 = V_8 -> V_9 . V_7 ;
V_123 = F_35 ( V_2 -> V_14 -> V_125 ) ;
if ( V_123 > 0 ) {
struct V_40 * V_41 = & V_135 -> V_42 [ 1 ] ;
if ( V_2 != V_95 -> V_137 ) {
F_4 ( L_20 ) ;
goto V_138;
}
F_10 ( V_7 -> V_54 ,
V_8 -> V_60 , V_2 -> V_139 ,
V_43 ) ;
memcpy ( V_8 -> V_68 , V_2 -> V_19 , V_2 -> V_139 ) ;
F_40 ( V_7 -> V_54 ,
V_8 -> V_60 , V_2 -> V_139 ,
V_43 ) ;
V_41 -> V_48 = V_8 -> V_60 ;
V_41 -> V_49 = V_2 -> V_139 ;
V_41 -> V_50 = V_7 -> V_58 -> V_50 ;
V_135 -> V_51 = 2 ;
}
if ( V_2 == V_95 -> V_137 ) {
F_7 ( L_21 ,
V_2 -> V_14 -> V_98 , V_123 ) ;
V_12 = F_41 ( V_8 ) ;
if ( V_12 )
goto V_138;
V_12 = F_21 ( V_95 , V_2 -> V_14 ) ;
if ( V_12 )
goto V_138;
}
V_12 = F_33 ( & V_8 -> V_9 , V_135 , true ) ;
if ( ! V_12 )
return 0 ;
V_138:
F_4 ( L_19 , V_95 , V_12 ) ;
return V_12 ;
}
void F_42 ( struct V_76 * V_77 ,
unsigned long V_140 ,
struct V_9 * V_9 )
{
struct V_8 * V_8 = F_43 ( V_9 , struct V_8 ,
V_9 ) ;
struct V_96 * V_14 ;
T_1 V_141 ;
int V_142 , V_143 , V_144 , V_12 ;
if ( ( char * ) V_77 == V_8 -> V_69 ) {
V_141 = V_8 -> V_62 ;
V_142 = V_63 ;
} else {
V_141 = V_77 -> V_55 ;
V_142 = V_90 ;
}
F_10 ( V_9 -> V_7 -> V_54 , V_141 ,
V_142 , V_21 ) ;
V_14 = & V_77 -> V_132 ;
F_7 ( L_22 , V_14 -> V_98 ,
V_14 -> V_34 , ( int ) ( V_140 - V_56 ) ) ;
F_44 ( V_8 -> V_94 , V_14 , V_77 -> V_19 ,
V_140 - V_56 ) ;
F_40 ( V_9 -> V_7 -> V_54 , V_141 ,
V_142 , V_21 ) ;
V_9 -> V_100 -- ;
if ( V_141 == V_8 -> V_62 )
return;
V_143 = V_9 -> V_100 ;
if ( V_143 + V_8 -> V_82 <= V_8 -> V_79 ) {
V_144 = F_45 ( V_8 -> V_79 - V_143 ,
V_8 -> V_82 ) ;
V_12 = F_24 ( V_8 , V_144 ) ;
if ( V_12 )
F_4 ( L_23 , V_144 , V_12 ) ;
}
}
void F_46 ( struct V_52 * V_53 ,
struct V_9 * V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_9 -> V_7 ;
if ( V_53 -> type == V_131 ) {
F_12 ( V_7 -> V_54 , V_53 -> V_55 ,
V_56 , V_43 ) ;
F_38 ( V_128 . V_129 , V_53 ) ;
V_53 = NULL ;
}
if ( V_53 && V_53 -> type == V_136 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_53 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_14 -> V_34 == V_145 )
F_47 ( V_2 ) ;
}
}
void F_48 ( struct V_3 * V_4 )
{
V_4 -> V_119 = V_146 ;
V_4 -> V_147 [ V_20 ] = 0 ;
V_4 -> V_147 [ V_39 ] = 0 ;
V_4 -> V_19 [ V_20 ] . V_113 = 0 ;
V_4 -> V_19 [ V_39 ] . V_113 = 0 ;
V_4 -> V_24 [ V_20 ] . V_113 = 0 ;
V_4 -> V_24 [ V_39 ] . V_113 = 0 ;
memset ( & V_4 -> V_26 [ V_20 ] , 0 ,
sizeof( struct V_10 ) ) ;
memset ( & V_4 -> V_26 [ V_39 ] , 0 ,
sizeof( struct V_10 ) ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 . V_7 ;
int V_148 = 1 ;
int V_149 = 1 ;
int V_150 = F_3 ( V_4 -> V_22 ) ;
if ( V_4 -> V_151 [ V_20 ] . V_152 != NULL ) {
V_148 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_19 [ V_20 ] ,
& V_4 -> V_151 [ V_20 ] ,
V_20 ) ;
}
if ( V_4 -> V_151 [ V_39 ] . V_152 != NULL ) {
V_148 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_19 [ V_39 ] ,
& V_4 -> V_151 [ V_39 ] ,
V_39 ) ;
}
if ( V_4 -> V_153 [ V_20 ] . V_152 != NULL ) {
V_149 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_24 [ V_20 ] ,
& V_4 -> V_153 [ V_20 ] ,
V_20 ) ;
}
if ( V_4 -> V_153 [ V_39 ] . V_152 != NULL ) {
V_149 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_24 [ V_39 ] ,
& V_4 -> V_153 [ V_39 ] ,
V_39 ) ;
}
if ( V_4 -> V_147 [ V_20 ] ) {
V_7 -> V_154 ( V_4 , V_20 ) ;
if ( V_148 )
F_51 ( V_4 ,
& V_4 -> V_19 [ V_20 ] ) ;
if ( V_150 && V_149 )
F_51 ( V_4 ,
& V_4 -> V_24 [ V_20 ] ) ;
}
if ( V_4 -> V_147 [ V_39 ] ) {
V_7 -> V_154 ( V_4 , V_39 ) ;
if ( V_148 )
F_51 ( V_4 ,
& V_4 -> V_19 [ V_39 ] ) ;
if ( V_150 && V_149 )
F_51 ( V_4 ,
& V_4 -> V_24 [ V_39 ] ) ;
}
}
