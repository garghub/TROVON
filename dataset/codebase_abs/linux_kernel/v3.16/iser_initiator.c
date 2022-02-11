static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
struct V_9 * V_10 ;
int V_11 ;
struct V_12 * V_13 = & V_4 -> V_14 . V_15 ;
struct V_16 * V_17 = & V_4 -> V_18 [ V_19 ] ;
V_11 = F_2 ( V_4 ,
V_17 ,
V_19 ,
V_20 ) ;
if ( V_11 )
return V_11 ;
if ( F_3 ( V_4 -> V_21 ) ) {
struct V_16 * V_22 = & V_4 -> V_23 [ V_19 ] ;
V_11 = F_2 ( V_4 ,
V_22 ,
V_19 ,
V_20 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = V_7 -> V_24 ( V_4 , V_19 ) ;
if ( V_11 ) {
F_4 ( L_1 ) ;
return V_11 ;
}
V_10 = & V_4 -> V_25 [ V_19 ] ;
V_13 -> V_26 |= V_27 ;
V_13 -> V_28 = F_5 ( V_10 -> V_29 . V_30 ) ;
V_13 -> V_31 = F_6 ( V_10 -> V_29 . V_32 ) ;
F_7 ( L_2 ,
V_2 -> V_33 , V_10 -> V_29 . V_30 ,
( unsigned long long ) V_10 -> V_29 . V_32 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
unsigned int V_34 ,
unsigned int V_35 ,
unsigned int V_36 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
struct V_9 * V_10 ;
int V_11 ;
struct V_12 * V_13 = & V_4 -> V_14 . V_15 ;
struct V_16 * V_37 = & V_4 -> V_18 [ V_38 ] ;
struct V_39 * V_40 = & V_4 -> V_14 . V_41 [ 1 ] ;
V_11 = F_2 ( V_4 ,
V_37 ,
V_38 ,
V_42 ) ;
if ( V_11 )
return V_11 ;
if ( F_3 ( V_4 -> V_21 ) ) {
struct V_16 * V_43 = & V_4 -> V_23 [ V_38 ] ;
V_11 = F_2 ( V_4 ,
V_43 ,
V_38 ,
V_42 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = V_7 -> V_24 ( V_4 , V_38 ) ;
if ( V_11 != 0 ) {
F_4 ( L_3 ) ;
return V_11 ;
}
V_10 = & V_4 -> V_25 [ V_38 ] ;
if ( V_35 < V_36 ) {
V_13 -> V_26 |= V_44 ;
V_13 -> V_45 = F_5 ( V_10 -> V_29 . V_30 ) ;
V_13 -> V_46 = F_6 ( V_10 -> V_29 . V_32 + V_35 ) ;
F_7 ( L_4
L_5 ,
V_2 -> V_33 , V_10 -> V_29 . V_30 ,
( unsigned long long ) V_10 -> V_29 . V_32 , V_35 ) ;
}
if ( V_34 > 0 ) {
F_7 ( L_6 ,
V_2 -> V_33 , V_34 ) ;
V_40 -> V_47 = V_10 -> V_29 . V_32 ;
V_40 -> V_48 = V_34 ;
V_40 -> V_49 = V_10 -> V_29 . V_49 ;
V_4 -> V_14 . V_50 = 2 ;
}
return 0 ;
}
static void F_9 ( struct V_51 * V_8 ,
struct V_52 * V_53 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
F_10 ( V_7 -> V_54 ,
V_53 -> V_55 , V_56 , V_42 ) ;
memset ( & V_53 -> V_15 , 0 , sizeof( struct V_12 ) ) ;
V_53 -> V_15 . V_26 = V_57 ;
V_53 -> V_50 = 1 ;
if ( V_53 -> V_41 [ 0 ] . V_49 != V_7 -> V_58 -> V_49 ) {
V_53 -> V_41 [ 0 ] . V_49 = V_7 -> V_58 -> V_49 ;
F_7 ( L_7 , V_53 ) ;
}
}
static void F_11 ( struct V_51 * V_8 )
{
if ( ! V_8 -> V_59 )
return;
if ( V_8 -> V_60 )
F_12 ( V_8 -> V_7 -> V_54 ,
V_8 -> V_60 ,
V_61 , V_42 ) ;
if ( V_8 -> V_62 )
F_12 ( V_8 -> V_7 -> V_54 ,
V_8 -> V_62 ,
V_63 , V_20 ) ;
F_13 ( V_8 -> V_59 ) ;
V_8 -> V_60 = 0 ;
V_8 -> V_62 = 0 ;
V_8 -> V_59 = NULL ;
}
static int F_14 ( struct V_51 * V_8 )
{
struct V_6 * V_7 ;
int V_64 , V_65 ;
F_15 ( V_8 -> V_7 == NULL ) ;
V_7 = V_8 -> V_7 ;
V_8 -> V_59 = F_16 ( V_61 +
V_63 , V_66 ) ;
if ( ! V_8 -> V_59 )
goto V_67;
V_8 -> V_68 = V_8 -> V_59 ;
V_8 -> V_69 = V_8 -> V_59 +
V_61 ;
V_8 -> V_60 = F_17 ( V_8 -> V_7 -> V_54 ,
( void * ) V_8 -> V_68 ,
V_61 , V_42 ) ;
V_8 -> V_62 = F_17 ( V_8 -> V_7 -> V_54 ,
( void * ) V_8 -> V_69 ,
V_63 , V_20 ) ;
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
int F_19 ( struct V_51 * V_8 , struct V_72 * V_73 )
{
int V_74 , V_75 ;
T_1 V_55 ;
struct V_76 * V_77 ;
struct V_39 * V_78 ;
struct V_6 * V_7 = V_8 -> V_7 ;
V_8 -> V_79 = V_73 -> V_80 ;
V_8 -> V_81 = V_73 -> V_80 - 1 ;
V_8 -> V_82 = V_8 -> V_79 >> 2 ;
if ( V_7 -> V_83 ( V_8 , V_73 -> V_84 ) )
goto V_85;
if ( F_14 ( V_8 ) )
goto V_86;
V_8 -> V_87 = F_16 ( V_73 -> V_80 *
sizeof( struct V_76 ) , V_66 ) ;
if ( ! V_8 -> V_87 )
goto V_88;
V_77 = V_8 -> V_87 ;
for ( V_74 = 0 ; V_74 < V_8 -> V_79 ; V_74 ++ , V_77 ++ ) {
V_55 = F_17 ( V_7 -> V_54 , ( void * ) V_77 ,
V_89 , V_20 ) ;
if ( F_18 ( V_7 -> V_54 , V_55 ) )
goto V_90;
V_77 -> V_55 = V_55 ;
V_78 = & V_77 -> V_78 ;
V_78 -> V_47 = V_77 -> V_55 ;
V_78 -> V_48 = V_89 ;
V_78 -> V_49 = V_7 -> V_58 -> V_49 ;
}
V_8 -> V_91 = 0 ;
return 0 ;
V_90:
V_77 = V_8 -> V_87 ;
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ , V_77 ++ )
F_12 ( V_7 -> V_54 , V_77 -> V_55 ,
V_89 , V_20 ) ;
F_13 ( V_8 -> V_87 ) ;
V_8 -> V_87 = NULL ;
V_88:
F_11 ( V_8 ) ;
V_86:
V_7 -> V_92 ( V_8 ) ;
V_85:
F_4 ( L_9 ) ;
return - V_71 ;
}
void F_20 ( struct V_51 * V_8 )
{
int V_74 ;
struct V_76 * V_77 ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( ! V_8 -> V_87 )
goto V_70;
if ( V_7 -> V_92 )
V_7 -> V_92 ( V_8 ) ;
V_77 = V_8 -> V_87 ;
for ( V_74 = 0 ; V_74 < V_8 -> V_79 ; V_74 ++ , V_77 ++ )
F_12 ( V_7 -> V_54 , V_77 -> V_55 ,
V_89 , V_20 ) ;
F_13 ( V_8 -> V_87 ) ;
V_8 -> V_87 = NULL ;
V_70:
F_11 ( V_8 ) ;
}
static int F_21 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
struct V_51 * V_8 = V_94 -> V_5 ;
struct V_72 * V_73 = V_94 -> V_73 ;
F_7 ( L_10 , V_96 -> V_97 , V_96 -> V_26 ) ;
if ( ( V_96 -> V_26 & V_98 ) != V_98 )
return 0 ;
F_22 ( V_8 -> V_99 != 1 ) ;
F_22 ( F_23 ( & V_8 -> V_100 ) != 0 ) ;
if ( V_73 -> V_101 ) {
F_24 ( L_11 ) ;
return 0 ;
} else
F_24 ( L_12 ,
V_8 -> V_82 ) ;
if ( F_25 ( V_8 , V_8 -> V_82 ) )
return - V_71 ;
return 0 ;
}
int F_26 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_51 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_36 ;
int V_11 ;
struct V_16 * V_102 , * V_103 ;
struct V_104 * V_13 = (struct V_104 * ) V_2 -> V_13 ;
struct V_105 * V_21 = V_2 -> V_21 ;
struct V_52 * V_53 = & V_4 -> V_14 ;
V_36 = F_27 ( V_13 -> V_106 ) ;
V_53 -> type = V_107 ;
F_9 ( V_8 , V_53 ) ;
if ( V_13 -> V_26 & V_108 ) {
V_102 = & V_4 -> V_18 [ V_19 ] ;
V_103 = & V_4 -> V_23 [ V_19 ] ;
} else {
V_102 = & V_4 -> V_18 [ V_38 ] ;
V_103 = & V_4 -> V_23 [ V_38 ] ;
}
if ( F_28 ( V_21 ) ) {
V_102 -> V_109 = F_29 ( V_21 ) ;
V_102 -> V_110 = F_28 ( V_21 ) ;
}
V_102 -> V_111 = F_30 ( V_21 ) ;
if ( F_3 ( V_21 ) ) {
V_103 -> V_109 = F_31 ( V_21 ) ;
V_103 -> V_110 = F_3 ( V_21 ) ;
V_103 -> V_111 = V_102 -> V_111 >>
F_32 ( V_21 -> V_7 -> V_112 ) * 8 ;
}
if ( V_13 -> V_26 & V_108 ) {
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_113;
}
if ( V_13 -> V_26 & V_114 ) {
V_11 = F_8 ( V_2 ,
V_2 -> V_115 ,
V_2 -> V_115 +
V_2 -> V_116 . V_106 ,
V_36 ) ;
if ( V_11 )
goto V_113;
}
V_4 -> V_117 = V_118 ;
V_11 = F_33 ( V_8 , V_53 ) ;
if ( ! V_11 )
return 0 ;
V_113:
F_4 ( L_13 , V_94 , V_2 -> V_33 , V_11 ) ;
return V_11 ;
}
int F_34 ( struct V_93 * V_94 ,
struct V_1 * V_2 ,
struct V_119 * V_13 )
{
struct V_51 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_53 = NULL ;
struct V_9 * V_10 ;
unsigned long V_120 ;
unsigned long V_121 ;
T_2 V_33 ;
int V_11 = 0 ;
struct V_39 * V_40 ;
V_33 = ( V_122 T_2 ) V_13 -> V_33 ;
V_121 = F_35 ( V_13 -> V_123 ) ;
V_120 = F_27 ( V_13 -> V_124 ) ;
F_7 ( L_14 ,
V_125 , ( int ) V_33 , ( int ) V_121 , ( int ) V_120 ) ;
V_53 = F_36 ( V_126 . V_127 , V_128 ) ;
if ( V_53 == NULL ) {
F_4 ( L_15 ) ;
return - V_71 ;
}
V_53 -> type = V_129 ;
V_53 -> V_15 . V_26 = V_57 ;
memcpy ( & V_53 -> V_130 , V_13 , sizeof( struct V_95 ) ) ;
F_37 ( V_2 , V_53 ) ;
V_10 = & V_4 -> V_25 [ V_38 ] ;
V_40 = & V_53 -> V_41 [ 1 ] ;
V_40 -> V_47 = V_10 -> V_29 . V_32 + V_120 ;
V_40 -> V_48 = V_121 ;
V_40 -> V_49 = V_10 -> V_29 . V_49 ;
V_53 -> V_50 = 2 ;
if ( V_120 + V_121 > V_4 -> V_18 [ V_38 ] . V_111 ) {
F_4 ( L_16
L_17 ,
V_120 , V_121 ,
V_4 -> V_18 [ V_38 ] . V_111 , V_33 ) ;
V_11 = - V_131 ;
goto V_132;
}
F_7 ( L_18 ,
V_33 , V_120 , V_121 ) ;
V_11 = F_33 ( V_8 , V_53 ) ;
if ( ! V_11 )
return 0 ;
V_132:
F_38 ( V_126 . V_127 , V_53 ) ;
F_4 ( L_19 , V_94 , V_11 ) ;
return V_11 ;
}
int F_39 ( struct V_93 * V_94 ,
struct V_1 * V_2 )
{
struct V_51 * V_8 = V_94 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_52 * V_133 = & V_4 -> V_14 ;
unsigned long V_121 ;
int V_11 = 0 ;
struct V_6 * V_7 ;
V_133 -> type = V_134 ;
F_9 ( V_8 , V_133 ) ;
V_7 = V_8 -> V_7 ;
V_121 = F_35 ( V_2 -> V_13 -> V_123 ) ;
if ( V_121 > 0 ) {
struct V_39 * V_40 = & V_133 -> V_41 [ 1 ] ;
if ( V_2 != V_94 -> V_135 ) {
F_4 ( L_20 ) ;
goto V_136;
}
F_10 ( V_7 -> V_54 ,
V_8 -> V_60 , V_2 -> V_137 ,
V_42 ) ;
memcpy ( V_8 -> V_68 , V_2 -> V_18 , V_2 -> V_137 ) ;
F_40 ( V_7 -> V_54 ,
V_8 -> V_60 , V_2 -> V_137 ,
V_42 ) ;
V_40 -> V_47 = V_8 -> V_60 ;
V_40 -> V_48 = V_2 -> V_137 ;
V_40 -> V_49 = V_7 -> V_58 -> V_49 ;
V_133 -> V_50 = 2 ;
}
if ( V_2 == V_94 -> V_135 ) {
F_7 ( L_21 ,
V_2 -> V_13 -> V_97 , V_121 ) ;
V_11 = F_41 ( V_8 ) ;
if ( V_11 )
goto V_136;
V_11 = F_21 ( V_94 , V_2 -> V_13 ) ;
if ( V_11 )
goto V_136;
}
V_11 = F_33 ( V_8 , V_133 ) ;
if ( ! V_11 )
return 0 ;
V_136:
F_4 ( L_19 , V_94 , V_11 ) ;
return V_11 ;
}
void F_42 ( struct V_76 * V_77 ,
unsigned long V_138 ,
struct V_51 * V_8 )
{
struct V_95 * V_13 ;
T_1 V_139 ;
int V_140 , V_141 , V_142 , V_11 ;
if ( ( char * ) V_77 == V_8 -> V_69 ) {
V_139 = V_8 -> V_62 ;
V_140 = V_63 ;
} else {
V_139 = V_77 -> V_55 ;
V_140 = V_89 ;
}
F_10 ( V_8 -> V_7 -> V_54 , V_139 ,
V_140 , V_20 ) ;
V_13 = & V_77 -> V_130 ;
F_7 ( L_22 , V_13 -> V_97 ,
V_13 -> V_33 , ( int ) ( V_138 - V_56 ) ) ;
F_43 ( V_8 -> V_93 , V_13 , V_77 -> V_18 ,
V_138 - V_56 ) ;
F_40 ( V_8 -> V_7 -> V_54 , V_139 ,
V_140 , V_20 ) ;
V_8 -> V_99 -- ;
if ( V_139 == V_8 -> V_62 )
return;
V_141 = V_8 -> V_99 ;
if ( V_141 + V_8 -> V_82 <= V_8 -> V_79 ) {
V_142 = F_44 ( V_8 -> V_79 - V_141 ,
V_8 -> V_82 ) ;
V_11 = F_25 ( V_8 , V_142 ) ;
if ( V_11 )
F_4 ( L_23 , V_142 , V_11 ) ;
}
}
void F_45 ( struct V_52 * V_53 ,
struct V_51 * V_8 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 = V_8 -> V_7 ;
if ( V_53 -> type == V_129 ) {
F_12 ( V_7 -> V_54 , V_53 -> V_55 ,
V_56 , V_42 ) ;
F_38 ( V_126 . V_127 , V_53 ) ;
V_53 = NULL ;
}
F_46 ( & V_8 -> V_100 ) ;
if ( V_53 && V_53 -> type == V_134 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_53 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_13 -> V_33 == V_143 )
F_47 ( V_2 ) ;
}
}
void F_48 ( struct V_3 * V_4 )
{
V_4 -> V_117 = V_144 ;
V_4 -> V_145 [ V_19 ] = 0 ;
V_4 -> V_145 [ V_38 ] = 0 ;
V_4 -> V_18 [ V_19 ] . V_111 = 0 ;
V_4 -> V_18 [ V_38 ] . V_111 = 0 ;
V_4 -> V_23 [ V_19 ] . V_111 = 0 ;
V_4 -> V_23 [ V_38 ] . V_111 = 0 ;
memset ( & V_4 -> V_25 [ V_19 ] , 0 ,
sizeof( struct V_9 ) ) ;
memset ( & V_4 -> V_25 [ V_38 ] , 0 ,
sizeof( struct V_9 ) ) ;
}
void F_49 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_7 ;
int V_146 = 1 ;
int V_147 = 1 ;
int V_148 = F_3 ( V_4 -> V_21 ) ;
if ( V_4 -> V_149 [ V_19 ] . V_150 != NULL ) {
V_146 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_18 [ V_19 ] ,
& V_4 -> V_149 [ V_19 ] ,
V_19 ) ;
}
if ( V_4 -> V_149 [ V_38 ] . V_150 != NULL ) {
V_146 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_18 [ V_38 ] ,
& V_4 -> V_149 [ V_38 ] ,
V_38 ) ;
}
if ( V_4 -> V_151 [ V_19 ] . V_150 != NULL ) {
V_147 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_23 [ V_19 ] ,
& V_4 -> V_151 [ V_19 ] ,
V_19 ) ;
}
if ( V_4 -> V_151 [ V_38 ] . V_150 != NULL ) {
V_147 = 0 ;
F_50 ( V_4 ,
& V_4 -> V_23 [ V_38 ] ,
& V_4 -> V_151 [ V_38 ] ,
V_38 ) ;
}
if ( V_4 -> V_145 [ V_19 ] ) {
V_7 -> V_152 ( V_4 , V_19 ) ;
if ( V_146 )
F_51 ( V_4 ,
& V_4 -> V_18 [ V_19 ] ) ;
if ( V_148 && V_147 )
F_51 ( V_4 ,
& V_4 -> V_23 [ V_19 ] ) ;
}
if ( V_4 -> V_145 [ V_38 ] ) {
V_7 -> V_152 ( V_4 , V_38 ) ;
if ( V_146 )
F_51 ( V_4 ,
& V_4 -> V_18 [ V_38 ] ) ;
if ( V_148 && V_147 )
F_51 ( V_4 ,
& V_4 -> V_23 [ V_38 ] ) ;
}
}
