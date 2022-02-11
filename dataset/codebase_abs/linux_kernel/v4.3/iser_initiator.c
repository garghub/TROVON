static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 . V_12 ;
struct V_13 * V_14 = & V_4 -> V_15 [ V_16 ] ;
V_8 = F_2 ( V_4 ,
V_14 ,
V_16 ,
V_17 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_4 -> V_18 ) ) {
struct V_13 * V_19 = & V_4 -> V_20 [ V_16 ] ;
V_8 = F_2 ( V_4 ,
V_19 ,
V_16 ,
V_17 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_4 ( V_4 , V_16 ) ;
if ( V_8 ) {
F_5 ( L_1 ) ;
return V_8 ;
}
V_7 = & V_4 -> V_21 [ V_16 ] ;
V_10 -> V_22 |= V_23 ;
V_10 -> V_24 = F_6 ( V_7 -> V_25 ) ;
V_10 -> V_26 = F_7 ( V_7 -> V_27 . V_28 ) ;
F_8 ( L_2 ,
V_2 -> V_29 , V_7 -> V_25 ,
( unsigned long long ) V_7 -> V_27 . V_28 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
unsigned int V_30 ,
unsigned int V_31 ,
unsigned int V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 . V_12 ;
struct V_13 * V_33 = & V_4 -> V_15 [ V_34 ] ;
struct V_35 * V_36 = & V_4 -> V_11 . V_37 [ 1 ] ;
V_8 = F_2 ( V_4 ,
V_33 ,
V_34 ,
V_38 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_4 -> V_18 ) ) {
struct V_13 * V_39 = & V_4 -> V_20 [ V_34 ] ;
V_8 = F_2 ( V_4 ,
V_39 ,
V_34 ,
V_38 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_4 ( V_4 , V_34 ) ;
if ( V_8 != 0 ) {
F_5 ( L_3 ) ;
return V_8 ;
}
V_7 = & V_4 -> V_21 [ V_34 ] ;
if ( V_31 < V_32 ) {
V_10 -> V_22 |= V_40 ;
V_10 -> V_41 = F_6 ( V_7 -> V_25 ) ;
V_10 -> V_42 = F_7 ( V_7 -> V_27 . V_28 + V_31 ) ;
F_8 ( L_4
L_5 ,
V_2 -> V_29 , V_7 -> V_25 ,
( unsigned long long ) V_7 -> V_27 . V_28 , V_31 ) ;
}
if ( V_30 > 0 ) {
F_8 ( L_6 ,
V_2 -> V_29 , V_30 ) ;
V_36 -> V_28 = V_7 -> V_27 . V_28 ;
V_36 -> V_43 = V_30 ;
V_36 -> V_44 = V_7 -> V_27 . V_44 ;
V_4 -> V_11 . V_45 = 2 ;
}
return 0 ;
}
static void F_10 ( struct V_46 * V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = V_46 -> V_51 . V_50 ;
F_11 ( V_50 -> V_52 ,
V_48 -> V_53 , V_54 , V_38 ) ;
memset ( & V_48 -> V_12 , 0 , sizeof( struct V_9 ) ) ;
V_48 -> V_12 . V_22 = V_55 ;
V_48 -> V_45 = 1 ;
}
static void F_12 ( struct V_46 * V_46 )
{
struct V_49 * V_50 = V_46 -> V_51 . V_50 ;
if ( ! V_46 -> V_56 )
return;
if ( V_46 -> V_57 )
F_13 ( V_50 -> V_52 ,
V_46 -> V_57 ,
V_58 , V_38 ) ;
if ( V_46 -> V_59 )
F_13 ( V_50 -> V_52 ,
V_46 -> V_59 ,
V_60 , V_17 ) ;
F_14 ( V_46 -> V_56 ) ;
V_46 -> V_57 = 0 ;
V_46 -> V_59 = 0 ;
V_46 -> V_56 = NULL ;
}
static int F_15 ( struct V_46 * V_46 )
{
struct V_49 * V_50 = V_46 -> V_51 . V_50 ;
int V_61 , V_62 ;
F_16 ( V_50 == NULL ) ;
V_46 -> V_56 = F_17 ( V_58 +
V_60 , V_63 ) ;
if ( ! V_46 -> V_56 )
goto V_64;
V_46 -> V_65 = V_46 -> V_56 ;
V_46 -> V_66 = V_46 -> V_56 +
V_58 ;
V_46 -> V_57 = F_18 ( V_50 -> V_52 ,
V_46 -> V_65 ,
V_58 ,
V_38 ) ;
V_46 -> V_59 = F_18 ( V_50 -> V_52 ,
V_46 -> V_66 ,
V_60 ,
V_17 ) ;
V_61 = F_19 ( V_50 -> V_52 ,
V_46 -> V_57 ) ;
V_62 = F_19 ( V_50 -> V_52 ,
V_46 -> V_59 ) ;
if ( V_61 || V_62 ) {
if ( V_61 )
V_46 -> V_57 = 0 ;
if ( V_62 )
V_46 -> V_59 = 0 ;
goto V_67;
}
return 0 ;
V_67:
F_12 ( V_46 ) ;
V_64:
F_5 ( L_7 ) ;
return - V_68 ;
}
int F_20 ( struct V_46 * V_46 ,
struct V_69 * V_70 )
{
int V_71 , V_72 ;
T_1 V_53 ;
struct V_73 * V_74 ;
struct V_35 * V_75 ;
struct V_51 * V_51 = & V_46 -> V_51 ;
struct V_49 * V_50 = V_51 -> V_50 ;
V_46 -> V_76 = V_70 -> V_77 ;
V_46 -> V_78 = V_70 -> V_77 - 1 ;
V_46 -> V_79 = V_46 -> V_76 >> 2 ;
if ( V_50 -> V_80 -> V_81 ( V_51 , V_70 -> V_82 ,
V_46 -> V_83 ) )
goto V_84;
if ( F_15 ( V_46 ) )
goto V_85;
V_46 -> V_86 = V_70 -> V_77 ;
V_46 -> V_87 = F_17 ( V_46 -> V_86 *
sizeof( struct V_73 ) , V_63 ) ;
if ( ! V_46 -> V_87 )
goto V_88;
V_74 = V_46 -> V_87 ;
for ( V_71 = 0 ; V_71 < V_46 -> V_76 ; V_71 ++ , V_74 ++ ) {
V_53 = F_18 ( V_50 -> V_52 , ( void * ) V_74 ,
V_89 , V_17 ) ;
if ( F_19 ( V_50 -> V_52 , V_53 ) )
goto V_90;
V_74 -> V_53 = V_53 ;
V_75 = & V_74 -> V_75 ;
V_75 -> V_28 = V_74 -> V_53 ;
V_75 -> V_43 = V_89 ;
V_75 -> V_44 = V_50 -> V_91 -> V_92 ;
}
V_46 -> V_93 = 0 ;
return 0 ;
V_90:
V_74 = V_46 -> V_87 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ , V_74 ++ )
F_13 ( V_50 -> V_52 , V_74 -> V_53 ,
V_89 , V_17 ) ;
F_14 ( V_46 -> V_87 ) ;
V_46 -> V_87 = NULL ;
V_88:
F_12 ( V_46 ) ;
V_85:
V_50 -> V_80 -> V_94 ( V_51 ) ;
V_84:
F_5 ( L_8 ) ;
return - V_68 ;
}
void F_21 ( struct V_46 * V_46 )
{
int V_71 ;
struct V_73 * V_74 ;
struct V_51 * V_51 = & V_46 -> V_51 ;
struct V_49 * V_50 = V_51 -> V_50 ;
if ( V_50 -> V_80 -> V_94 )
V_50 -> V_80 -> V_94 ( V_51 ) ;
V_74 = V_46 -> V_87 ;
for ( V_71 = 0 ; V_71 < V_46 -> V_76 ; V_71 ++ , V_74 ++ )
F_13 ( V_50 -> V_52 , V_74 -> V_53 ,
V_89 , V_17 ) ;
F_14 ( V_46 -> V_87 ) ;
V_46 -> V_87 = NULL ;
F_12 ( V_46 ) ;
}
static int F_22 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_46 * V_46 = V_96 -> V_5 ;
struct V_51 * V_51 = & V_46 -> V_51 ;
struct V_69 * V_70 = V_96 -> V_70 ;
F_8 ( L_9 , V_98 -> V_99 , V_98 -> V_22 ) ;
if ( ( V_98 -> V_22 & V_100 ) != V_100 )
return 0 ;
F_23 ( V_51 -> V_101 != 1 ) ;
if ( V_70 -> V_102 ) {
F_24 ( L_10 ) ;
return 0 ;
} else
F_24 ( L_11 ,
V_46 -> V_79 ) ;
if ( F_25 ( V_46 , V_46 -> V_79 ) )
return - V_68 ;
return 0 ;
}
static inline bool F_26 ( T_2 V_103 )
{
return ( ( V_103 % V_104 ) == 0 ) ;
}
int F_27 ( struct V_95 * V_96 ,
struct V_1 * V_2 )
{
struct V_46 * V_46 = V_96 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_32 ;
int V_8 ;
struct V_13 * V_105 , * V_106 ;
struct V_107 * V_10 = (struct V_107 * ) V_2 -> V_10 ;
struct V_108 * V_18 = V_2 -> V_18 ;
struct V_47 * V_48 = & V_4 -> V_11 ;
T_2 V_103 = ++ V_46 -> V_51 . V_103 ;
V_32 = F_28 ( V_10 -> V_109 ) ;
V_48 -> type = V_110 ;
F_10 ( V_46 , V_48 ) ;
if ( V_10 -> V_22 & V_111 ) {
V_105 = & V_4 -> V_15 [ V_16 ] ;
V_106 = & V_4 -> V_20 [ V_16 ] ;
} else {
V_105 = & V_4 -> V_15 [ V_34 ] ;
V_106 = & V_4 -> V_20 [ V_34 ] ;
}
if ( F_29 ( V_18 ) ) {
V_105 -> V_112 = F_30 ( V_18 ) ;
V_105 -> V_113 = F_29 ( V_18 ) ;
}
V_105 -> V_114 = F_31 ( V_18 ) ;
if ( F_3 ( V_18 ) ) {
V_106 -> V_112 = F_32 ( V_18 ) ;
V_106 -> V_113 = F_3 ( V_18 ) ;
V_106 -> V_114 = ( V_105 -> V_114 >>
F_33 ( V_18 -> V_50 -> V_115 ) ) * 8 ;
}
if ( V_10 -> V_22 & V_111 ) {
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
goto V_116;
}
if ( V_10 -> V_22 & V_117 ) {
V_8 = F_9 ( V_2 ,
V_2 -> V_118 ,
V_2 -> V_118 +
V_2 -> V_119 . V_109 ,
V_32 ) ;
if ( V_8 )
goto V_116;
}
V_4 -> V_120 = V_121 ;
V_8 = F_34 ( & V_46 -> V_51 , V_48 ,
F_26 ( V_103 ) ) ;
if ( ! V_8 )
return 0 ;
V_116:
F_5 ( L_12 , V_96 , V_2 -> V_29 , V_8 ) ;
return V_8 ;
}
int F_35 ( struct V_95 * V_96 ,
struct V_1 * V_2 ,
struct V_122 * V_10 )
{
struct V_46 * V_46 = V_96 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_47 * V_48 = NULL ;
struct V_6 * V_7 ;
unsigned long V_123 ;
unsigned long V_124 ;
T_3 V_29 ;
int V_8 ;
struct V_35 * V_36 ;
V_29 = ( V_125 T_3 ) V_10 -> V_29 ;
V_124 = F_36 ( V_10 -> V_126 ) ;
V_123 = F_28 ( V_10 -> V_127 ) ;
F_8 ( L_13 ,
V_128 , ( int ) V_29 , ( int ) V_124 , ( int ) V_123 ) ;
V_48 = F_37 ( V_129 . V_130 , V_131 ) ;
if ( V_48 == NULL ) {
F_5 ( L_14 ) ;
return - V_68 ;
}
V_48 -> type = V_132 ;
V_48 -> V_12 . V_22 = V_55 ;
memcpy ( & V_48 -> V_133 , V_10 , sizeof( struct V_97 ) ) ;
V_8 = F_38 ( V_2 , V_48 ) ;
if ( V_8 )
goto V_134;
V_7 = & V_4 -> V_21 [ V_34 ] ;
V_36 = & V_48 -> V_37 [ 1 ] ;
V_36 -> V_28 = V_7 -> V_27 . V_28 + V_123 ;
V_36 -> V_43 = V_124 ;
V_36 -> V_44 = V_7 -> V_27 . V_44 ;
V_48 -> V_45 = 2 ;
if ( V_123 + V_124 > V_4 -> V_15 [ V_34 ] . V_114 ) {
F_5 ( L_15
L_16 ,
V_123 , V_124 ,
V_4 -> V_15 [ V_34 ] . V_114 , V_29 ) ;
V_8 = - V_135 ;
goto V_134;
}
F_8 ( L_17 ,
V_29 , V_123 , V_124 ) ;
V_8 = F_34 ( & V_46 -> V_51 , V_48 , true ) ;
if ( ! V_8 )
return 0 ;
V_134:
F_39 ( V_129 . V_130 , V_48 ) ;
F_5 ( L_18 , V_96 , V_8 ) ;
return V_8 ;
}
int F_40 ( struct V_95 * V_96 ,
struct V_1 * V_2 )
{
struct V_46 * V_46 = V_96 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_47 * V_136 = & V_4 -> V_11 ;
unsigned long V_124 ;
int V_8 = 0 ;
struct V_49 * V_50 ;
V_136 -> type = V_137 ;
F_10 ( V_46 , V_136 ) ;
V_50 = V_46 -> V_51 . V_50 ;
V_124 = F_36 ( V_2 -> V_10 -> V_126 ) ;
if ( V_124 > 0 ) {
struct V_35 * V_36 = & V_136 -> V_37 [ 1 ] ;
if ( V_2 != V_96 -> V_138 ) {
F_5 ( L_19 ) ;
goto V_139;
}
F_11 ( V_50 -> V_52 ,
V_46 -> V_57 , V_2 -> V_140 ,
V_38 ) ;
memcpy ( V_46 -> V_65 , V_2 -> V_15 , V_2 -> V_140 ) ;
F_41 ( V_50 -> V_52 ,
V_46 -> V_57 , V_2 -> V_140 ,
V_38 ) ;
V_36 -> V_28 = V_46 -> V_57 ;
V_36 -> V_43 = V_2 -> V_140 ;
V_36 -> V_44 = V_50 -> V_91 -> V_92 ;
V_136 -> V_45 = 2 ;
}
if ( V_2 == V_96 -> V_138 ) {
F_8 ( L_20 ,
V_2 -> V_10 -> V_99 , V_124 ) ;
V_8 = F_42 ( V_46 ) ;
if ( V_8 )
goto V_139;
V_8 = F_22 ( V_96 , V_2 -> V_10 ) ;
if ( V_8 )
goto V_139;
}
V_8 = F_34 ( & V_46 -> V_51 , V_136 , true ) ;
if ( ! V_8 )
return 0 ;
V_139:
F_5 ( L_18 , V_96 , V_8 ) ;
return V_8 ;
}
void F_43 ( struct V_73 * V_74 ,
unsigned long V_141 ,
struct V_51 * V_51 )
{
struct V_46 * V_46 = F_44 ( V_51 , struct V_46 ,
V_51 ) ;
struct V_97 * V_10 ;
T_1 V_142 ;
int V_143 , V_144 , V_145 , V_8 ;
if ( ( char * ) V_74 == V_46 -> V_66 ) {
V_142 = V_46 -> V_59 ;
V_143 = V_60 ;
} else {
V_142 = V_74 -> V_53 ;
V_143 = V_89 ;
}
F_11 ( V_51 -> V_50 -> V_52 , V_142 ,
V_143 , V_17 ) ;
V_10 = & V_74 -> V_133 ;
F_8 ( L_21 , V_10 -> V_99 ,
V_10 -> V_29 , ( int ) ( V_141 - V_54 ) ) ;
F_45 ( V_46 -> V_95 , V_10 , V_74 -> V_15 ,
V_141 - V_54 ) ;
F_41 ( V_51 -> V_50 -> V_52 , V_142 ,
V_143 , V_17 ) ;
V_51 -> V_101 -- ;
if ( V_142 == V_46 -> V_59 )
return;
V_144 = V_51 -> V_101 ;
if ( V_144 + V_46 -> V_79 <= V_46 -> V_76 ) {
V_145 = F_46 ( V_46 -> V_76 - V_144 ,
V_46 -> V_79 ) ;
V_8 = F_25 ( V_46 , V_145 ) ;
if ( V_8 )
F_5 ( L_22 , V_145 , V_8 ) ;
}
}
void F_47 ( struct V_47 * V_48 ,
struct V_51 * V_51 )
{
struct V_1 * V_2 ;
struct V_49 * V_50 = V_51 -> V_50 ;
if ( V_48 -> type == V_132 ) {
F_13 ( V_50 -> V_52 , V_48 -> V_53 ,
V_54 , V_38 ) ;
F_39 ( V_129 . V_130 , V_48 ) ;
V_48 = NULL ;
}
if ( V_48 && V_48 -> type == V_137 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_48 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_10 -> V_29 == V_146 )
F_48 ( V_2 ) ;
}
}
void F_49 ( struct V_3 * V_4 )
{
V_4 -> V_120 = V_147 ;
V_4 -> V_148 [ V_16 ] = 0 ;
V_4 -> V_148 [ V_34 ] = 0 ;
V_4 -> V_15 [ V_16 ] . V_114 = 0 ;
V_4 -> V_15 [ V_34 ] . V_114 = 0 ;
V_4 -> V_20 [ V_16 ] . V_114 = 0 ;
V_4 -> V_20 [ V_34 ] . V_114 = 0 ;
memset ( & V_4 -> V_21 [ V_16 ] , 0 ,
sizeof( struct V_6 ) ) ;
memset ( & V_4 -> V_21 [ V_34 ] , 0 ,
sizeof( struct V_6 ) ) ;
}
void F_50 ( struct V_3 * V_4 )
{
int V_149 = 1 ;
int V_150 = 1 ;
int V_151 = F_3 ( V_4 -> V_18 ) ;
if ( V_4 -> V_15 [ V_16 ] . V_152 ) {
V_149 = 0 ;
F_51 ( V_4 ,
& V_4 -> V_15 [ V_16 ] ,
V_16 ) ;
}
if ( V_4 -> V_15 [ V_34 ] . V_152 ) {
V_149 = 0 ;
F_51 ( V_4 ,
& V_4 -> V_15 [ V_34 ] ,
V_34 ) ;
}
if ( V_4 -> V_20 [ V_16 ] . V_152 ) {
V_150 = 0 ;
F_51 ( V_4 ,
& V_4 -> V_20 [ V_16 ] ,
V_16 ) ;
}
if ( V_4 -> V_20 [ V_34 ] . V_152 ) {
V_150 = 0 ;
F_51 ( V_4 ,
& V_4 -> V_20 [ V_34 ] ,
V_34 ) ;
}
if ( V_4 -> V_148 [ V_16 ] ) {
F_52 ( V_4 , V_16 ) ;
if ( V_149 )
F_53 ( V_4 ,
& V_4 -> V_15 [ V_16 ] ,
V_17 ) ;
if ( V_151 && V_150 )
F_53 ( V_4 ,
& V_4 -> V_20 [ V_16 ] ,
V_17 ) ;
}
if ( V_4 -> V_148 [ V_34 ] ) {
F_52 ( V_4 , V_34 ) ;
if ( V_149 )
F_53 ( V_4 ,
& V_4 -> V_15 [ V_34 ] ,
V_38 ) ;
if ( V_151 && V_150 )
F_53 ( V_4 ,
& V_4 -> V_20 [ V_34 ] ,
V_38 ) ;
}
}
