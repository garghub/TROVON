static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 ;
int V_12 ;
struct V_13 * V_14 = & V_5 -> V_15 . V_16 ;
struct V_17 * V_18 = & V_5 -> V_19 [ V_20 ] ;
V_12 = F_2 ( V_5 ,
V_18 ,
V_20 ,
V_21 ) ;
if ( V_12 )
return V_12 ;
if ( F_3 ( V_5 -> V_22 ) ) {
struct V_17 * V_23 = & V_5 -> V_24 [ V_20 ] ;
V_12 = F_2 ( V_5 ,
V_23 ,
V_20 ,
V_21 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_3 > V_5 -> V_19 [ V_20 ] . V_25 ) {
F_4 ( L_1
L_2 ,
V_5 -> V_19 [ V_20 ] . V_25 , V_3 ,
V_2 -> V_26 , V_5 -> V_9 ) ;
return - V_27 ;
}
V_12 = V_8 -> V_28 ( V_5 , V_20 ) ;
if ( V_12 ) {
F_4 ( L_3 ) ;
return V_12 ;
}
V_11 = & V_5 -> V_29 [ V_20 ] ;
V_14 -> V_30 |= V_31 ;
V_14 -> V_32 = F_5 ( V_11 -> V_33 . V_34 ) ;
V_14 -> V_35 = F_6 ( V_11 -> V_33 . V_36 ) ;
F_7 ( L_4 ,
V_2 -> V_26 , V_11 -> V_33 . V_34 ,
( unsigned long long ) V_11 -> V_33 . V_36 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
unsigned int V_37 ,
unsigned int V_38 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 ;
int V_12 ;
struct V_13 * V_14 = & V_5 -> V_15 . V_16 ;
struct V_17 * V_39 = & V_5 -> V_19 [ V_40 ] ;
struct V_41 * V_42 = & V_5 -> V_15 . V_43 [ 1 ] ;
V_12 = F_2 ( V_5 ,
V_39 ,
V_40 ,
V_44 ) ;
if ( V_12 )
return V_12 ;
if ( F_3 ( V_5 -> V_22 ) ) {
struct V_17 * V_45 = & V_5 -> V_24 [ V_40 ] ;
V_12 = F_2 ( V_5 ,
V_45 ,
V_40 ,
V_44 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_3 > V_5 -> V_19 [ V_40 ] . V_25 ) {
F_4 ( L_5
L_6 ,
V_5 -> V_19 [ V_40 ] . V_25 ,
V_3 , V_2 -> V_26 , V_2 -> V_46 ) ;
return - V_27 ;
}
V_12 = V_8 -> V_28 ( V_5 , V_40 ) ;
if ( V_12 != 0 ) {
F_4 ( L_7 ) ;
return V_12 ;
}
V_11 = & V_5 -> V_29 [ V_40 ] ;
if ( V_38 < V_3 ) {
V_14 -> V_30 |= V_47 ;
V_14 -> V_48 = F_5 ( V_11 -> V_33 . V_34 ) ;
V_14 -> V_49 = F_6 ( V_11 -> V_33 . V_36 + V_38 ) ;
F_7 ( L_8
L_9 ,
V_2 -> V_26 , V_11 -> V_33 . V_34 ,
( unsigned long long ) V_11 -> V_33 . V_36 , V_38 ) ;
}
if ( V_37 > 0 ) {
F_7 ( L_10 ,
V_2 -> V_26 , V_37 ) ;
V_42 -> V_50 = V_11 -> V_33 . V_36 ;
V_42 -> V_51 = V_37 ;
V_42 -> V_52 = V_11 -> V_33 . V_52 ;
V_5 -> V_15 . V_53 = 2 ;
}
return 0 ;
}
static void F_9 ( struct V_54 * V_9 ,
struct V_55 * V_56 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
F_10 ( V_8 -> V_57 ,
V_56 -> V_58 , V_59 , V_44 ) ;
memset ( & V_56 -> V_16 , 0 , sizeof( struct V_13 ) ) ;
V_56 -> V_16 . V_30 = V_60 ;
V_56 -> V_53 = 1 ;
if ( V_56 -> V_43 [ 0 ] . V_52 != V_8 -> V_61 -> V_52 ) {
V_56 -> V_43 [ 0 ] . V_52 = V_8 -> V_61 -> V_52 ;
F_7 ( L_11 , V_56 ) ;
}
}
static void F_11 ( struct V_54 * V_9 )
{
if ( ! V_9 -> V_62 )
return;
if ( V_9 -> V_63 )
F_12 ( V_9 -> V_8 -> V_57 ,
V_9 -> V_63 ,
V_64 , V_44 ) ;
if ( V_9 -> V_65 )
F_12 ( V_9 -> V_8 -> V_57 ,
V_9 -> V_65 ,
V_66 , V_21 ) ;
F_13 ( V_9 -> V_62 ) ;
V_9 -> V_63 = 0 ;
V_9 -> V_65 = 0 ;
V_9 -> V_62 = NULL ;
}
static int F_14 ( struct V_54 * V_9 )
{
struct V_7 * V_8 ;
int V_67 , V_68 ;
F_15 ( V_9 -> V_8 == NULL ) ;
V_8 = V_9 -> V_8 ;
V_9 -> V_62 = F_16 ( V_64 +
V_66 , V_69 ) ;
if ( ! V_9 -> V_62 )
goto V_70;
V_9 -> V_71 = V_9 -> V_62 ;
V_9 -> V_72 = V_9 -> V_62 +
V_64 ;
V_9 -> V_63 = F_17 ( V_9 -> V_8 -> V_57 ,
( void * ) V_9 -> V_71 ,
V_64 , V_44 ) ;
V_9 -> V_65 = F_17 ( V_9 -> V_8 -> V_57 ,
( void * ) V_9 -> V_72 ,
V_66 , V_21 ) ;
V_67 = F_18 ( V_8 -> V_57 ,
V_9 -> V_63 ) ;
V_68 = F_18 ( V_8 -> V_57 ,
V_9 -> V_65 ) ;
if ( V_67 || V_68 ) {
if ( V_67 )
V_9 -> V_63 = 0 ;
if ( V_68 )
V_9 -> V_65 = 0 ;
goto V_73;
}
return 0 ;
V_73:
F_11 ( V_9 ) ;
V_70:
F_4 ( L_12 ) ;
return - V_74 ;
}
int F_19 ( struct V_54 * V_9 , struct V_75 * V_76 )
{
int V_77 , V_78 ;
T_1 V_58 ;
struct V_79 * V_80 ;
struct V_41 * V_81 ;
struct V_7 * V_8 = V_9 -> V_8 ;
V_9 -> V_82 = V_76 -> V_83 ;
V_9 -> V_84 = V_76 -> V_83 - 1 ;
V_9 -> V_85 = V_9 -> V_82 >> 2 ;
if ( V_8 -> V_86 ( V_9 , V_76 -> V_87 ) )
goto V_88;
if ( F_14 ( V_9 ) )
goto V_89;
V_9 -> V_90 = F_16 ( V_76 -> V_83 *
sizeof( struct V_79 ) , V_69 ) ;
if ( ! V_9 -> V_90 )
goto V_91;
V_80 = V_9 -> V_90 ;
for ( V_77 = 0 ; V_77 < V_9 -> V_82 ; V_77 ++ , V_80 ++ ) {
V_58 = F_17 ( V_8 -> V_57 , ( void * ) V_80 ,
V_92 , V_21 ) ;
if ( F_18 ( V_8 -> V_57 , V_58 ) )
goto V_93;
V_80 -> V_58 = V_58 ;
V_81 = & V_80 -> V_81 ;
V_81 -> V_50 = V_80 -> V_58 ;
V_81 -> V_51 = V_92 ;
V_81 -> V_52 = V_8 -> V_61 -> V_52 ;
}
V_9 -> V_94 = 0 ;
return 0 ;
V_93:
V_80 = V_9 -> V_90 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ , V_80 ++ )
F_12 ( V_8 -> V_57 , V_80 -> V_58 ,
V_92 , V_21 ) ;
F_13 ( V_9 -> V_90 ) ;
V_9 -> V_90 = NULL ;
V_91:
F_11 ( V_9 ) ;
V_89:
V_8 -> V_95 ( V_9 ) ;
V_88:
F_4 ( L_13 ) ;
return - V_74 ;
}
void F_20 ( struct V_54 * V_9 )
{
int V_77 ;
struct V_79 * V_80 ;
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_9 -> V_90 )
goto V_73;
if ( V_8 -> V_95 )
V_8 -> V_95 ( V_9 ) ;
V_80 = V_9 -> V_90 ;
for ( V_77 = 0 ; V_77 < V_9 -> V_82 ; V_77 ++ , V_80 ++ )
F_12 ( V_8 -> V_57 , V_80 -> V_58 ,
V_92 , V_21 ) ;
F_13 ( V_9 -> V_90 ) ;
V_9 -> V_90 = NULL ;
V_73:
F_11 ( V_9 ) ;
}
static int F_21 ( struct V_96 * V_46 , struct V_97 * V_98 )
{
struct V_54 * V_9 = V_46 -> V_6 ;
struct V_75 * V_76 = V_46 -> V_76 ;
F_7 ( L_14 , V_98 -> V_99 , V_98 -> V_30 ) ;
if ( ( V_98 -> V_30 & V_100 ) != V_100 )
return 0 ;
F_22 ( V_9 -> V_101 != 1 ) ;
F_22 ( F_23 ( & V_9 -> V_102 ) != 0 ) ;
if ( V_76 -> V_103 ) {
F_24 ( L_15 ) ;
return 0 ;
} else
F_24 ( L_16 ,
V_9 -> V_85 ) ;
if ( F_25 ( V_9 , V_9 -> V_85 ) )
return - V_74 ;
return 0 ;
}
int F_26 ( struct V_96 * V_46 ,
struct V_1 * V_2 )
{
struct V_54 * V_9 = V_46 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_3 ;
int V_12 ;
struct V_17 * V_104 , * V_105 ;
struct V_106 * V_14 = (struct V_106 * ) V_2 -> V_14 ;
struct V_107 * V_22 = V_2 -> V_22 ;
struct V_55 * V_56 = & V_5 -> V_15 ;
V_3 = F_27 ( V_14 -> V_108 ) ;
V_56 -> type = V_109 ;
F_9 ( V_9 , V_56 ) ;
if ( V_14 -> V_30 & V_110 ) {
V_104 = & V_5 -> V_19 [ V_20 ] ;
V_105 = & V_5 -> V_24 [ V_20 ] ;
} else {
V_104 = & V_5 -> V_19 [ V_40 ] ;
V_105 = & V_5 -> V_24 [ V_40 ] ;
}
if ( F_28 ( V_22 ) ) {
V_104 -> V_111 = F_29 ( V_22 ) ;
V_104 -> V_112 = F_28 ( V_22 ) ;
}
V_104 -> V_25 = F_30 ( V_22 ) ;
if ( F_3 ( V_22 ) ) {
V_105 -> V_111 = F_31 ( V_22 ) ;
V_105 -> V_112 = F_3 ( V_22 ) ;
V_105 -> V_25 = V_22 -> V_113 -> V_51 ;
}
if ( V_14 -> V_30 & V_110 ) {
V_12 = F_1 ( V_2 , V_3 ) ;
if ( V_12 )
goto V_114;
}
if ( V_14 -> V_30 & V_115 ) {
V_12 = F_8 ( V_2 ,
V_2 -> V_116 ,
V_2 -> V_116 +
V_2 -> V_117 . V_108 ,
V_3 ) ;
if ( V_12 )
goto V_114;
}
V_5 -> V_118 = V_119 ;
V_12 = F_32 ( V_9 , V_56 ) ;
if ( ! V_12 )
return 0 ;
V_114:
F_4 ( L_17 , V_46 , V_2 -> V_26 , V_12 ) ;
return V_12 ;
}
int F_33 ( struct V_96 * V_46 ,
struct V_1 * V_2 ,
struct V_120 * V_14 )
{
struct V_54 * V_9 = V_46 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_55 * V_56 = NULL ;
struct V_10 * V_11 ;
unsigned long V_121 ;
unsigned long V_122 ;
T_2 V_26 ;
int V_12 = 0 ;
struct V_41 * V_42 ;
V_26 = ( V_123 T_2 ) V_14 -> V_26 ;
V_122 = F_34 ( V_14 -> V_124 ) ;
V_121 = F_27 ( V_14 -> V_125 ) ;
F_7 ( L_18 ,
V_126 , ( int ) V_26 , ( int ) V_122 , ( int ) V_121 ) ;
V_56 = F_35 ( V_127 . V_128 , V_129 ) ;
if ( V_56 == NULL ) {
F_4 ( L_19 ) ;
return - V_74 ;
}
V_56 -> type = V_130 ;
V_56 -> V_16 . V_30 = V_60 ;
memcpy ( & V_56 -> V_131 , V_14 , sizeof( struct V_97 ) ) ;
F_36 ( V_2 , V_56 ) ;
V_11 = & V_5 -> V_29 [ V_40 ] ;
V_42 = & V_56 -> V_43 [ 1 ] ;
V_42 -> V_50 = V_11 -> V_33 . V_36 + V_121 ;
V_42 -> V_51 = V_122 ;
V_42 -> V_52 = V_11 -> V_33 . V_52 ;
V_56 -> V_53 = 2 ;
if ( V_121 + V_122 > V_5 -> V_19 [ V_40 ] . V_25 ) {
F_4 ( L_20
L_21 ,
V_121 , V_122 ,
V_5 -> V_19 [ V_40 ] . V_25 , V_26 ) ;
V_12 = - V_27 ;
goto V_132;
}
F_7 ( L_22 ,
V_26 , V_121 , V_122 ) ;
V_12 = F_32 ( V_9 , V_56 ) ;
if ( ! V_12 )
return 0 ;
V_132:
F_37 ( V_127 . V_128 , V_56 ) ;
F_4 ( L_23 , V_46 , V_12 ) ;
return V_12 ;
}
int F_38 ( struct V_96 * V_46 ,
struct V_1 * V_2 )
{
struct V_54 * V_9 = V_46 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_55 * V_133 = & V_5 -> V_15 ;
unsigned long V_122 ;
int V_12 = 0 ;
struct V_7 * V_8 ;
V_133 -> type = V_134 ;
F_9 ( V_9 , V_133 ) ;
V_8 = V_9 -> V_8 ;
V_122 = F_34 ( V_2 -> V_14 -> V_124 ) ;
if ( V_122 > 0 ) {
struct V_41 * V_42 = & V_133 -> V_43 [ 1 ] ;
if ( V_2 != V_46 -> V_135 ) {
F_4 ( L_24 ) ;
goto V_136;
}
F_10 ( V_8 -> V_57 ,
V_9 -> V_63 , V_2 -> V_137 ,
V_44 ) ;
memcpy ( V_9 -> V_71 , V_2 -> V_19 , V_2 -> V_137 ) ;
F_39 ( V_8 -> V_57 ,
V_9 -> V_63 , V_2 -> V_137 ,
V_44 ) ;
V_42 -> V_50 = V_9 -> V_63 ;
V_42 -> V_51 = V_2 -> V_137 ;
V_42 -> V_52 = V_8 -> V_61 -> V_52 ;
V_133 -> V_53 = 2 ;
}
if ( V_2 == V_46 -> V_135 ) {
F_7 ( L_25 ,
V_2 -> V_14 -> V_99 , V_122 ) ;
V_12 = F_40 ( V_9 ) ;
if ( V_12 )
goto V_136;
V_12 = F_21 ( V_46 , V_2 -> V_14 ) ;
if ( V_12 )
goto V_136;
}
V_12 = F_32 ( V_9 , V_133 ) ;
if ( ! V_12 )
return 0 ;
V_136:
F_4 ( L_23 , V_46 , V_12 ) ;
return V_12 ;
}
void F_41 ( struct V_79 * V_80 ,
unsigned long V_138 ,
struct V_54 * V_9 )
{
struct V_97 * V_14 ;
T_1 V_139 ;
int V_140 , V_141 , V_142 , V_12 ;
if ( ( char * ) V_80 == V_9 -> V_72 ) {
V_139 = V_9 -> V_65 ;
V_140 = V_66 ;
} else {
V_139 = V_80 -> V_58 ;
V_140 = V_92 ;
}
F_10 ( V_9 -> V_8 -> V_57 , V_139 ,
V_140 , V_21 ) ;
V_14 = & V_80 -> V_131 ;
F_7 ( L_26 , V_14 -> V_99 ,
V_14 -> V_26 , ( int ) ( V_138 - V_59 ) ) ;
F_42 ( V_9 -> V_96 , V_14 , V_80 -> V_19 ,
V_138 - V_59 ) ;
F_39 ( V_9 -> V_8 -> V_57 , V_139 ,
V_140 , V_21 ) ;
V_9 -> V_101 -- ;
if ( V_139 == V_9 -> V_65 )
return;
V_141 = V_9 -> V_101 ;
if ( V_141 + V_9 -> V_85 <= V_9 -> V_82 ) {
V_142 = F_43 ( V_9 -> V_82 - V_141 ,
V_9 -> V_85 ) ;
V_12 = F_25 ( V_9 , V_142 ) ;
if ( V_12 )
F_4 ( L_27 , V_142 , V_12 ) ;
}
}
void F_44 ( struct V_55 * V_56 ,
struct V_54 * V_9 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_9 -> V_8 ;
if ( V_56 -> type == V_130 ) {
F_12 ( V_8 -> V_57 , V_56 -> V_58 ,
V_59 , V_44 ) ;
F_37 ( V_127 . V_128 , V_56 ) ;
V_56 = NULL ;
}
F_45 ( & V_9 -> V_102 ) ;
if ( V_56 && V_56 -> type == V_134 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_56 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_14 -> V_26 == V_143 )
F_46 ( V_2 ) ;
}
}
void F_47 ( struct V_4 * V_5 )
{
V_5 -> V_118 = V_144 ;
V_5 -> V_145 [ V_20 ] = 0 ;
V_5 -> V_145 [ V_40 ] = 0 ;
V_5 -> V_19 [ V_20 ] . V_25 = 0 ;
V_5 -> V_19 [ V_40 ] . V_25 = 0 ;
V_5 -> V_24 [ V_20 ] . V_25 = 0 ;
V_5 -> V_24 [ V_40 ] . V_25 = 0 ;
memset ( & V_5 -> V_29 [ V_20 ] , 0 ,
sizeof( struct V_10 ) ) ;
memset ( & V_5 -> V_29 [ V_40 ] , 0 ,
sizeof( struct V_10 ) ) ;
}
void F_48 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
int V_146 = 1 ;
int V_147 = 1 ;
int V_148 = F_3 ( V_5 -> V_22 ) ;
if ( V_5 -> V_149 [ V_20 ] . V_150 != NULL ) {
V_146 = 0 ;
F_49 ( V_5 ,
& V_5 -> V_19 [ V_20 ] ,
& V_5 -> V_149 [ V_20 ] ,
V_20 ) ;
}
if ( V_5 -> V_149 [ V_40 ] . V_150 != NULL ) {
V_146 = 0 ;
F_49 ( V_5 ,
& V_5 -> V_19 [ V_40 ] ,
& V_5 -> V_149 [ V_40 ] ,
V_40 ) ;
}
if ( V_5 -> V_151 [ V_20 ] . V_150 != NULL ) {
V_147 = 0 ;
F_49 ( V_5 ,
& V_5 -> V_24 [ V_20 ] ,
& V_5 -> V_151 [ V_20 ] ,
V_20 ) ;
}
if ( V_5 -> V_151 [ V_40 ] . V_150 != NULL ) {
V_147 = 0 ;
F_49 ( V_5 ,
& V_5 -> V_24 [ V_40 ] ,
& V_5 -> V_151 [ V_40 ] ,
V_40 ) ;
}
if ( V_5 -> V_145 [ V_20 ] ) {
V_8 -> V_152 ( V_5 , V_20 ) ;
if ( V_146 )
F_50 ( V_5 ,
& V_5 -> V_19 [ V_20 ] ) ;
if ( V_148 && V_147 )
F_50 ( V_5 ,
& V_5 -> V_24 [ V_20 ] ) ;
}
if ( V_5 -> V_145 [ V_40 ] ) {
V_8 -> V_152 ( V_5 , V_40 ) ;
if ( V_146 )
F_50 ( V_5 ,
& V_5 -> V_19 [ V_40 ] ) ;
if ( V_148 && V_147 )
F_50 ( V_5 ,
& V_5 -> V_24 [ V_40 ] ) ;
}
}
