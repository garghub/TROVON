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
V_14 -> V_29 = F_5 ( V_11 -> V_30 ) ;
V_14 -> V_31 = F_6 ( V_11 -> V_32 . V_33 ) ;
F_7 ( L_2 ,
V_2 -> V_34 , V_11 -> V_30 ,
( unsigned long long ) V_11 -> V_32 . V_33 ) ;
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
V_14 -> V_46 = F_5 ( V_11 -> V_30 ) ;
V_14 -> V_47 = F_6 ( V_11 -> V_32 . V_33 + V_36 ) ;
F_7 ( L_4
L_5 ,
V_2 -> V_34 , V_11 -> V_30 ,
( unsigned long long ) V_11 -> V_32 . V_33 , V_36 ) ;
}
if ( V_35 > 0 ) {
F_7 ( L_6 ,
V_2 -> V_34 , V_35 ) ;
V_41 -> V_33 = V_11 -> V_32 . V_33 ;
V_41 -> V_48 = V_35 ;
V_41 -> V_49 = V_11 -> V_32 . V_49 ;
V_4 -> V_15 . V_50 = 2 ;
}
return 0 ;
}
static void F_9 ( struct V_8 * V_8 ,
struct V_51 * V_52 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
F_10 ( V_7 -> V_53 ,
V_52 -> V_54 , V_55 , V_43 ) ;
memset ( & V_52 -> V_16 , 0 , sizeof( struct V_13 ) ) ;
V_52 -> V_16 . V_27 = V_56 ;
V_52 -> V_50 = 1 ;
if ( V_52 -> V_42 [ 0 ] . V_49 != V_7 -> V_57 -> V_49 ) {
V_52 -> V_42 [ 0 ] . V_49 = V_7 -> V_57 -> V_49 ;
F_7 ( L_7 , V_52 ) ;
}
}
static void F_11 ( struct V_8 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
if ( ! V_8 -> V_58 )
return;
if ( V_8 -> V_59 )
F_12 ( V_7 -> V_53 ,
V_8 -> V_59 ,
V_60 , V_43 ) ;
if ( V_8 -> V_61 )
F_12 ( V_7 -> V_53 ,
V_8 -> V_61 ,
V_62 , V_21 ) ;
F_13 ( V_8 -> V_58 ) ;
V_8 -> V_59 = 0 ;
V_8 -> V_61 = 0 ;
V_8 -> V_58 = NULL ;
}
static int F_14 ( struct V_8 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_7 ;
int V_63 , V_64 ;
F_15 ( V_7 == NULL ) ;
V_8 -> V_58 = F_16 ( V_60 +
V_62 , V_65 ) ;
if ( ! V_8 -> V_58 )
goto V_66;
V_8 -> V_67 = V_8 -> V_58 ;
V_8 -> V_68 = V_8 -> V_58 +
V_60 ;
V_8 -> V_59 = F_17 ( V_7 -> V_53 ,
V_8 -> V_67 ,
V_60 ,
V_43 ) ;
V_8 -> V_61 = F_17 ( V_7 -> V_53 ,
V_8 -> V_68 ,
V_62 ,
V_21 ) ;
V_63 = F_18 ( V_7 -> V_53 ,
V_8 -> V_59 ) ;
V_64 = F_18 ( V_7 -> V_53 ,
V_8 -> V_61 ) ;
if ( V_63 || V_64 ) {
if ( V_63 )
V_8 -> V_59 = 0 ;
if ( V_64 )
V_8 -> V_61 = 0 ;
goto V_69;
}
return 0 ;
V_69:
F_11 ( V_8 ) ;
V_66:
F_4 ( L_8 ) ;
return - V_70 ;
}
int F_19 ( struct V_8 * V_8 ,
struct V_71 * V_72 )
{
int V_73 , V_74 ;
T_1 V_54 ;
struct V_75 * V_76 ;
struct V_40 * V_77 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_6 * V_7 = V_9 -> V_7 ;
V_8 -> V_78 = V_72 -> V_79 ;
V_8 -> V_80 = V_72 -> V_79 - 1 ;
V_8 -> V_81 = V_8 -> V_78 >> 2 ;
if ( V_7 -> V_82 ( V_9 , V_72 -> V_83 ) )
goto V_84;
if ( F_14 ( V_8 ) )
goto V_85;
V_8 -> V_86 = V_72 -> V_79 ;
V_8 -> V_87 = F_16 ( V_8 -> V_86 *
sizeof( struct V_75 ) , V_65 ) ;
if ( ! V_8 -> V_87 )
goto V_88;
V_76 = V_8 -> V_87 ;
for ( V_73 = 0 ; V_73 < V_8 -> V_78 ; V_73 ++ , V_76 ++ ) {
V_54 = F_17 ( V_7 -> V_53 , ( void * ) V_76 ,
V_89 , V_21 ) ;
if ( F_18 ( V_7 -> V_53 , V_54 ) )
goto V_90;
V_76 -> V_54 = V_54 ;
V_77 = & V_76 -> V_77 ;
V_77 -> V_33 = V_76 -> V_54 ;
V_77 -> V_48 = V_89 ;
V_77 -> V_49 = V_7 -> V_57 -> V_49 ;
}
V_8 -> V_91 = 0 ;
return 0 ;
V_90:
V_76 = V_8 -> V_87 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ , V_76 ++ )
F_12 ( V_7 -> V_53 , V_76 -> V_54 ,
V_89 , V_21 ) ;
F_13 ( V_8 -> V_87 ) ;
V_8 -> V_87 = NULL ;
V_88:
F_11 ( V_8 ) ;
V_85:
V_7 -> V_92 ( V_9 ) ;
V_84:
F_4 ( L_9 ) ;
return - V_70 ;
}
void F_20 ( struct V_8 * V_8 )
{
int V_73 ;
struct V_75 * V_76 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_6 * V_7 = V_9 -> V_7 ;
if ( V_7 -> V_92 )
V_7 -> V_92 ( V_9 ) ;
V_76 = V_8 -> V_87 ;
for ( V_73 = 0 ; V_73 < V_8 -> V_78 ; V_73 ++ , V_76 ++ )
F_12 ( V_7 -> V_53 , V_76 -> V_54 ,
V_89 , V_21 ) ;
F_13 ( V_8 -> V_87 ) ;
V_8 -> V_87 = NULL ;
F_11 ( V_8 ) ;
}
static int F_21 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
struct V_8 * V_8 = V_94 -> V_5 ;
struct V_9 * V_9 = & V_8 -> V_9 ;
struct V_71 * V_72 = V_94 -> V_72 ;
F_7 ( L_10 , V_96 -> V_97 , V_96 -> V_27 ) ;
if ( ( V_96 -> V_27 & V_98 ) != V_98 )
return 0 ;
F_22 ( V_9 -> V_99 != 1 ) ;
if ( V_72 -> V_100 ) {
F_23 ( L_11 ) ;
return 0 ;
} else
F_23 ( L_12 ,
V_8 -> V_81 ) ;
if ( F_24 ( V_8 , V_8 -> V_81 ) )
return - V_70 ;
return 0 ;
}
static inline bool F_25 ( T_2 V_101 )
{
return ( ( V_101 % V_102 ) == 0 ) ;
}
int F_26 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_8 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_37 ;
int V_12 ;
struct V_17 * V_103 , * V_104 ;
struct V_105 * V_14 = (struct V_105 * ) V_2 -> V_14 ;
struct V_106 * V_22 = V_2 -> V_22 ;
struct V_51 * V_52 = & V_4 -> V_15 ;
T_2 V_101 = ++ V_8 -> V_9 . V_101 ;
V_37 = F_27 ( V_14 -> V_107 ) ;
V_52 -> type = V_108 ;
F_9 ( V_8 , V_52 ) ;
if ( V_14 -> V_27 & V_109 ) {
V_103 = & V_4 -> V_19 [ V_20 ] ;
V_104 = & V_4 -> V_24 [ V_20 ] ;
} else {
V_103 = & V_4 -> V_19 [ V_39 ] ;
V_104 = & V_4 -> V_24 [ V_39 ] ;
}
if ( F_28 ( V_22 ) ) {
V_103 -> V_110 = F_29 ( V_22 ) ;
V_103 -> V_111 = F_28 ( V_22 ) ;
}
V_103 -> V_112 = F_30 ( V_22 ) ;
if ( F_3 ( V_22 ) ) {
V_104 -> V_110 = F_31 ( V_22 ) ;
V_104 -> V_111 = F_3 ( V_22 ) ;
V_104 -> V_112 = ( V_103 -> V_112 >>
F_32 ( V_22 -> V_7 -> V_113 ) ) * 8 ;
}
if ( V_14 -> V_27 & V_109 ) {
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
goto V_114;
}
if ( V_14 -> V_27 & V_115 ) {
V_12 = F_8 ( V_2 ,
V_2 -> V_116 ,
V_2 -> V_116 +
V_2 -> V_117 . V_107 ,
V_37 ) ;
if ( V_12 )
goto V_114;
}
V_4 -> V_118 = V_119 ;
V_12 = F_33 ( & V_8 -> V_9 , V_52 ,
F_25 ( V_101 ) ) ;
if ( ! V_12 )
return 0 ;
V_114:
F_4 ( L_13 , V_94 , V_2 -> V_34 , V_12 ) ;
return V_12 ;
}
int F_34 ( struct V_93 * V_94 ,
struct V_1 * V_2 ,
struct V_120 * V_14 )
{
struct V_8 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_51 * V_52 = NULL ;
struct V_10 * V_11 ;
unsigned long V_121 ;
unsigned long V_122 ;
T_3 V_34 ;
int V_12 = 0 ;
struct V_40 * V_41 ;
V_34 = ( V_123 T_3 ) V_14 -> V_34 ;
V_122 = F_35 ( V_14 -> V_124 ) ;
V_121 = F_27 ( V_14 -> V_125 ) ;
F_7 ( L_14 ,
V_126 , ( int ) V_34 , ( int ) V_122 , ( int ) V_121 ) ;
V_52 = F_36 ( V_127 . V_128 , V_129 ) ;
if ( V_52 == NULL ) {
F_4 ( L_15 ) ;
return - V_70 ;
}
V_52 -> type = V_130 ;
V_52 -> V_16 . V_27 = V_56 ;
memcpy ( & V_52 -> V_131 , V_14 , sizeof( struct V_95 ) ) ;
F_37 ( V_2 , V_52 ) ;
V_11 = & V_4 -> V_26 [ V_39 ] ;
V_41 = & V_52 -> V_42 [ 1 ] ;
V_41 -> V_33 = V_11 -> V_32 . V_33 + V_121 ;
V_41 -> V_48 = V_122 ;
V_41 -> V_49 = V_11 -> V_32 . V_49 ;
V_52 -> V_50 = 2 ;
if ( V_121 + V_122 > V_4 -> V_19 [ V_39 ] . V_112 ) {
F_4 ( L_16
L_17 ,
V_121 , V_122 ,
V_4 -> V_19 [ V_39 ] . V_112 , V_34 ) ;
V_12 = - V_132 ;
goto V_133;
}
F_7 ( L_18 ,
V_34 , V_121 , V_122 ) ;
V_12 = F_33 ( & V_8 -> V_9 , V_52 , true ) ;
if ( ! V_12 )
return 0 ;
V_133:
F_38 ( V_127 . V_128 , V_52 ) ;
F_4 ( L_19 , V_94 , V_12 ) ;
return V_12 ;
}
int F_39 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_8 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_51 * V_134 = & V_4 -> V_15 ;
unsigned long V_122 ;
int V_12 = 0 ;
struct V_6 * V_7 ;
V_134 -> type = V_135 ;
F_9 ( V_8 , V_134 ) ;
V_7 = V_8 -> V_9 . V_7 ;
V_122 = F_35 ( V_2 -> V_14 -> V_124 ) ;
if ( V_122 > 0 ) {
struct V_40 * V_41 = & V_134 -> V_42 [ 1 ] ;
if ( V_2 != V_94 -> V_136 ) {
F_4 ( L_20 ) ;
goto V_137;
}
F_10 ( V_7 -> V_53 ,
V_8 -> V_59 , V_2 -> V_138 ,
V_43 ) ;
memcpy ( V_8 -> V_67 , V_2 -> V_19 , V_2 -> V_138 ) ;
F_40 ( V_7 -> V_53 ,
V_8 -> V_59 , V_2 -> V_138 ,
V_43 ) ;
V_41 -> V_33 = V_8 -> V_59 ;
V_41 -> V_48 = V_2 -> V_138 ;
V_41 -> V_49 = V_7 -> V_57 -> V_49 ;
V_134 -> V_50 = 2 ;
}
if ( V_2 == V_94 -> V_136 ) {
F_7 ( L_21 ,
V_2 -> V_14 -> V_97 , V_122 ) ;
V_12 = F_41 ( V_8 ) ;
if ( V_12 )
goto V_137;
V_12 = F_21 ( V_94 , V_2 -> V_14 ) ;
if ( V_12 )
goto V_137;
}
V_12 = F_33 ( & V_8 -> V_9 , V_134 , true ) ;
if ( ! V_12 )
return 0 ;
V_137:
F_4 ( L_19 , V_94 , V_12 ) ;
return V_12 ;
}
void F_42 ( struct V_75 * V_76 ,
unsigned long V_139 ,
struct V_9 * V_9 )
{
struct V_8 * V_8 = F_43 ( V_9 , struct V_8 ,
V_9 ) ;
struct V_95 * V_14 ;
T_1 V_140 ;
int V_141 , V_142 , V_143 , V_12 ;
if ( ( char * ) V_76 == V_8 -> V_68 ) {
V_140 = V_8 -> V_61 ;
V_141 = V_62 ;
} else {
V_140 = V_76 -> V_54 ;
V_141 = V_89 ;
}
F_10 ( V_9 -> V_7 -> V_53 , V_140 ,
V_141 , V_21 ) ;
V_14 = & V_76 -> V_131 ;
F_7 ( L_22 , V_14 -> V_97 ,
V_14 -> V_34 , ( int ) ( V_139 - V_55 ) ) ;
F_44 ( V_8 -> V_93 , V_14 , V_76 -> V_19 ,
V_139 - V_55 ) ;
F_40 ( V_9 -> V_7 -> V_53 , V_140 ,
V_141 , V_21 ) ;
V_9 -> V_99 -- ;
if ( V_140 == V_8 -> V_61 )
return;
V_142 = V_9 -> V_99 ;
if ( V_142 + V_8 -> V_81 <= V_8 -> V_78 ) {
V_143 = F_45 ( V_8 -> V_78 - V_142 ,
V_8 -> V_81 ) ;
V_12 = F_24 ( V_8 , V_143 ) ;
if ( V_12 )
F_4 ( L_23 , V_143 , V_12 ) ;
}
}
void F_46 ( struct V_51 * V_52 ,
struct V_9 * V_9 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_9 -> V_7 ;
if ( V_52 -> type == V_130 ) {
F_12 ( V_7 -> V_53 , V_52 -> V_54 ,
V_55 , V_43 ) ;
F_38 ( V_127 . V_128 , V_52 ) ;
V_52 = NULL ;
}
if ( V_52 && V_52 -> type == V_135 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_52 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_14 -> V_34 == V_144 )
F_47 ( V_2 ) ;
}
}
void F_48 ( struct V_3 * V_4 )
{
V_4 -> V_118 = V_145 ;
V_4 -> V_146 [ V_20 ] = 0 ;
V_4 -> V_146 [ V_39 ] = 0 ;
V_4 -> V_19 [ V_20 ] . V_112 = 0 ;
V_4 -> V_19 [ V_39 ] . V_112 = 0 ;
V_4 -> V_24 [ V_20 ] . V_112 = 0 ;
V_4 -> V_24 [ V_39 ] . V_112 = 0 ;
memset ( & V_4 -> V_26 [ V_20 ] , 0 ,
sizeof( struct V_10 ) ) ;
memset ( & V_4 -> V_26 [ V_39 ] , 0 ,
sizeof( struct V_10 ) ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 . V_7 ;
int V_147 = 1 ;
int V_148 = 1 ;
int V_149 = F_3 ( V_4 -> V_22 ) ;
if ( V_4 -> V_19 [ V_20 ] . V_150 ) {
V_147 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_19 [ V_20 ] ,
V_20 ) ;
}
if ( V_4 -> V_19 [ V_39 ] . V_150 ) {
V_147 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_19 [ V_39 ] ,
V_39 ) ;
}
if ( V_4 -> V_24 [ V_20 ] . V_150 ) {
V_148 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_24 [ V_20 ] ,
V_20 ) ;
}
if ( V_4 -> V_24 [ V_39 ] . V_150 ) {
V_148 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_24 [ V_39 ] ,
V_39 ) ;
}
if ( V_4 -> V_146 [ V_20 ] ) {
V_7 -> V_151 ( V_4 , V_20 ) ;
if ( V_147 )
F_51 ( V_4 ,
& V_4 -> V_19 [ V_20 ] ,
V_21 ) ;
if ( V_149 && V_148 )
F_51 ( V_4 ,
& V_4 -> V_24 [ V_20 ] ,
V_21 ) ;
}
if ( V_4 -> V_146 [ V_39 ] ) {
V_7 -> V_151 ( V_4 , V_39 ) ;
if ( V_147 )
F_51 ( V_4 ,
& V_4 -> V_19 [ V_39 ] ,
V_43 ) ;
if ( V_149 && V_148 )
F_51 ( V_4 ,
& V_4 -> V_24 [ V_39 ] ,
V_43 ) ;
}
}
