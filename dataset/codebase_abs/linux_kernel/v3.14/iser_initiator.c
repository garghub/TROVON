static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_10 -> V_8 ;
struct V_11 * V_12 ;
int V_13 ;
struct V_14 * V_15 = & V_5 -> V_16 . V_17 ;
struct V_18 * V_19 = & V_5 -> V_20 [ V_21 ] ;
V_13 = F_2 ( V_5 ,
V_19 ,
V_21 ,
V_22 ) ;
if ( V_13 )
return V_13 ;
if ( V_3 > V_5 -> V_20 [ V_21 ] . V_23 ) {
F_3 ( L_1
L_2 ,
V_5 -> V_20 [ V_21 ] . V_23 , V_3 ,
V_2 -> V_24 , V_5 -> V_9 ) ;
return - V_25 ;
}
V_13 = V_8 -> V_26 ( V_5 , V_21 ) ;
if ( V_13 ) {
F_3 ( L_3 ) ;
return V_13 ;
}
V_12 = & V_5 -> V_27 [ V_21 ] ;
V_15 -> V_28 |= V_29 ;
V_15 -> V_30 = F_4 ( V_12 -> V_31 . V_32 ) ;
V_15 -> V_33 = F_5 ( V_12 -> V_31 . V_34 ) ;
F_6 ( L_4 ,
V_2 -> V_24 , V_12 -> V_31 . V_32 ,
( unsigned long long ) V_12 -> V_31 . V_34 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 ,
unsigned int V_35 ,
unsigned int V_36 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_10 -> V_8 ;
struct V_11 * V_12 ;
int V_13 ;
struct V_14 * V_15 = & V_5 -> V_16 . V_17 ;
struct V_18 * V_37 = & V_5 -> V_20 [ V_38 ] ;
struct V_39 * V_40 = & V_5 -> V_16 . V_41 [ 1 ] ;
V_13 = F_2 ( V_5 ,
V_37 ,
V_38 ,
V_42 ) ;
if ( V_13 )
return V_13 ;
if ( V_3 > V_5 -> V_20 [ V_38 ] . V_23 ) {
F_3 ( L_5
L_6 ,
V_5 -> V_20 [ V_38 ] . V_23 ,
V_3 , V_2 -> V_24 , V_2 -> V_43 ) ;
return - V_25 ;
}
V_13 = V_8 -> V_26 ( V_5 , V_38 ) ;
if ( V_13 != 0 ) {
F_3 ( L_7 ) ;
return V_13 ;
}
V_12 = & V_5 -> V_27 [ V_38 ] ;
if ( V_36 < V_3 ) {
V_15 -> V_28 |= V_44 ;
V_15 -> V_45 = F_4 ( V_12 -> V_31 . V_32 ) ;
V_15 -> V_46 = F_5 ( V_12 -> V_31 . V_34 + V_36 ) ;
F_6 ( L_8
L_9 ,
V_2 -> V_24 , V_12 -> V_31 . V_32 ,
( unsigned long long ) V_12 -> V_31 . V_34 , V_36 ) ;
}
if ( V_35 > 0 ) {
F_6 ( L_10 ,
V_2 -> V_24 , V_35 ) ;
V_40 -> V_47 = V_12 -> V_31 . V_34 ;
V_40 -> V_48 = V_35 ;
V_40 -> V_49 = V_12 -> V_31 . V_49 ;
V_5 -> V_16 . V_50 = 2 ;
}
return 0 ;
}
static void F_8 ( struct V_9 * V_10 ,
struct V_51 * V_52 )
{
struct V_7 * V_8 = V_10 -> V_8 ;
F_9 ( V_8 -> V_53 ,
V_52 -> V_54 , V_55 , V_42 ) ;
memset ( & V_52 -> V_17 , 0 , sizeof( struct V_14 ) ) ;
V_52 -> V_17 . V_28 = V_56 ;
V_52 -> V_50 = 1 ;
if ( V_52 -> V_41 [ 0 ] . V_49 != V_8 -> V_57 -> V_49 ) {
V_52 -> V_41 [ 0 ] . V_49 = V_8 -> V_57 -> V_49 ;
F_6 ( L_11 , V_52 ) ;
}
}
static void F_10 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_58 )
return;
if ( V_10 -> V_59 )
F_11 ( V_10 -> V_8 -> V_53 ,
V_10 -> V_59 ,
V_60 , V_42 ) ;
if ( V_10 -> V_61 )
F_11 ( V_10 -> V_8 -> V_53 ,
V_10 -> V_61 ,
V_62 , V_22 ) ;
F_12 ( V_10 -> V_58 ) ;
V_10 -> V_59 = 0 ;
V_10 -> V_61 = 0 ;
V_10 -> V_58 = NULL ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
int V_63 , V_64 ;
F_14 ( V_10 -> V_8 == NULL ) ;
V_8 = V_10 -> V_8 ;
V_10 -> V_58 = F_15 ( V_60 +
V_62 , V_65 ) ;
if ( ! V_10 -> V_58 )
goto V_66;
V_10 -> V_67 = V_10 -> V_58 ;
V_10 -> V_68 = V_10 -> V_58 +
V_60 ;
V_10 -> V_59 = F_16 ( V_10 -> V_8 -> V_53 ,
( void * ) V_10 -> V_67 ,
V_60 , V_42 ) ;
V_10 -> V_61 = F_16 ( V_10 -> V_8 -> V_53 ,
( void * ) V_10 -> V_68 ,
V_62 , V_22 ) ;
V_63 = F_17 ( V_8 -> V_53 ,
V_10 -> V_59 ) ;
V_64 = F_17 ( V_8 -> V_53 ,
V_10 -> V_61 ) ;
if ( V_63 || V_64 ) {
if ( V_63 )
V_10 -> V_59 = 0 ;
if ( V_64 )
V_10 -> V_61 = 0 ;
goto V_69;
}
return 0 ;
V_69:
F_10 ( V_10 ) ;
V_66:
F_3 ( L_12 ) ;
return - V_70 ;
}
int F_18 ( struct V_9 * V_10 , struct V_71 * V_72 )
{
int V_73 , V_74 ;
T_1 V_54 ;
struct V_75 * V_76 ;
struct V_39 * V_77 ;
struct V_7 * V_8 = V_10 -> V_8 ;
V_10 -> V_78 = V_72 -> V_79 ;
V_10 -> V_80 = V_72 -> V_79 - 1 ;
V_10 -> V_81 = V_10 -> V_78 >> 2 ;
if ( V_8 -> V_82 ( V_10 , V_72 -> V_83 ) )
goto V_84;
if ( F_13 ( V_10 ) )
goto V_85;
V_10 -> V_86 = F_15 ( V_72 -> V_79 *
sizeof( struct V_75 ) , V_65 ) ;
if ( ! V_10 -> V_86 )
goto V_87;
V_76 = V_10 -> V_86 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_78 ; V_73 ++ , V_76 ++ ) {
V_54 = F_16 ( V_8 -> V_53 , ( void * ) V_76 ,
V_88 , V_22 ) ;
if ( F_17 ( V_8 -> V_53 , V_54 ) )
goto V_89;
V_76 -> V_54 = V_54 ;
V_77 = & V_76 -> V_77 ;
V_77 -> V_47 = V_76 -> V_54 ;
V_77 -> V_48 = V_88 ;
V_77 -> V_49 = V_8 -> V_57 -> V_49 ;
}
V_10 -> V_90 = 0 ;
return 0 ;
V_89:
V_76 = V_10 -> V_86 ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ , V_76 ++ )
F_11 ( V_8 -> V_53 , V_76 -> V_54 ,
V_88 , V_22 ) ;
F_12 ( V_10 -> V_86 ) ;
V_10 -> V_86 = NULL ;
V_87:
F_10 ( V_10 ) ;
V_85:
V_8 -> V_91 ( V_10 ) ;
V_84:
F_3 ( L_13 ) ;
return - V_70 ;
}
void F_19 ( struct V_9 * V_10 )
{
int V_73 ;
struct V_75 * V_76 ;
struct V_7 * V_8 = V_10 -> V_8 ;
if ( ! V_10 -> V_86 )
goto V_69;
if ( V_8 -> V_91 )
V_8 -> V_91 ( V_10 ) ;
V_76 = V_10 -> V_86 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_78 ; V_73 ++ , V_76 ++ )
F_11 ( V_8 -> V_53 , V_76 -> V_54 ,
V_88 , V_22 ) ;
F_12 ( V_10 -> V_86 ) ;
V_10 -> V_86 = NULL ;
V_69:
F_10 ( V_10 ) ;
}
static int F_20 ( struct V_92 * V_43 , struct V_93 * V_94 )
{
struct V_95 * V_9 = V_43 -> V_6 ;
struct V_71 * V_72 = V_43 -> V_72 ;
F_6 ( L_14 , V_94 -> V_96 , V_94 -> V_28 ) ;
if ( ( V_94 -> V_28 & V_97 ) != V_97 )
return 0 ;
F_21 ( V_9 -> V_10 -> V_98 != 1 ) ;
F_21 ( F_22 ( & V_9 -> V_10 -> V_99 ) != 0 ) ;
if ( V_72 -> V_100 ) {
F_23 ( L_15 ) ;
return 0 ;
} else
F_23 ( L_16 ,
V_9 -> V_10 -> V_81 ) ;
if ( F_24 ( V_9 -> V_10 ,
V_9 -> V_10 -> V_81 ) )
return - V_70 ;
return 0 ;
}
int F_25 ( struct V_92 * V_43 ,
struct V_1 * V_2 )
{
struct V_95 * V_9 = V_43 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_3 ;
int V_13 ;
struct V_18 * V_101 ;
struct V_102 * V_15 = (struct V_102 * ) V_2 -> V_15 ;
struct V_103 * V_104 = V_2 -> V_104 ;
struct V_51 * V_52 = & V_5 -> V_16 ;
V_3 = F_26 ( V_15 -> V_105 ) ;
V_52 -> type = V_106 ;
F_8 ( V_9 -> V_10 , V_52 ) ;
if ( V_15 -> V_28 & V_107 )
V_101 = & V_5 -> V_20 [ V_21 ] ;
else
V_101 = & V_5 -> V_20 [ V_38 ] ;
if ( F_27 ( V_104 ) ) {
V_101 -> V_108 = F_28 ( V_104 ) ;
V_101 -> V_109 = F_27 ( V_104 ) ;
}
V_101 -> V_23 = F_29 ( V_104 ) ;
if ( V_15 -> V_28 & V_107 ) {
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 )
goto V_110;
}
if ( V_15 -> V_28 & V_111 ) {
V_13 = F_7 ( V_2 ,
V_2 -> V_112 ,
V_2 -> V_112 +
V_2 -> V_113 . V_105 ,
V_3 ) ;
if ( V_13 )
goto V_110;
}
V_5 -> V_114 = V_115 ;
V_13 = F_30 ( V_9 -> V_10 , V_52 ) ;
if ( ! V_13 )
return 0 ;
V_110:
F_3 ( L_17 , V_43 , V_2 -> V_24 , V_13 ) ;
return V_13 ;
}
int F_31 ( struct V_92 * V_43 ,
struct V_1 * V_2 ,
struct V_116 * V_15 )
{
struct V_95 * V_9 = V_43 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_51 * V_52 = NULL ;
struct V_11 * V_12 ;
unsigned long V_117 ;
unsigned long V_118 ;
T_2 V_24 ;
int V_13 = 0 ;
struct V_39 * V_40 ;
V_24 = ( V_119 T_2 ) V_15 -> V_24 ;
V_118 = F_32 ( V_15 -> V_120 ) ;
V_117 = F_26 ( V_15 -> V_121 ) ;
F_6 ( L_18 ,
V_122 , ( int ) V_24 , ( int ) V_118 , ( int ) V_117 ) ;
V_52 = F_33 ( V_123 . V_124 , V_125 ) ;
if ( V_52 == NULL ) {
F_3 ( L_19 ) ;
return - V_70 ;
}
V_52 -> type = V_126 ;
V_52 -> V_17 . V_28 = V_56 ;
memcpy ( & V_52 -> V_127 , V_15 , sizeof( struct V_93 ) ) ;
F_34 ( V_2 , V_52 ) ;
V_12 = & V_5 -> V_27 [ V_38 ] ;
V_40 = & V_52 -> V_41 [ 1 ] ;
V_40 -> V_47 = V_12 -> V_31 . V_34 + V_117 ;
V_40 -> V_48 = V_118 ;
V_40 -> V_49 = V_12 -> V_31 . V_49 ;
V_52 -> V_50 = 2 ;
if ( V_117 + V_118 > V_5 -> V_20 [ V_38 ] . V_23 ) {
F_3 ( L_20
L_21 ,
V_117 , V_118 ,
V_5 -> V_20 [ V_38 ] . V_23 , V_24 ) ;
V_13 = - V_25 ;
goto V_128;
}
F_6 ( L_22 ,
V_24 , V_117 , V_118 ) ;
V_13 = F_30 ( V_9 -> V_10 , V_52 ) ;
if ( ! V_13 )
return 0 ;
V_128:
F_35 ( V_123 . V_124 , V_52 ) ;
F_3 ( L_23 , V_43 , V_13 ) ;
return V_13 ;
}
int F_36 ( struct V_92 * V_43 ,
struct V_1 * V_2 )
{
struct V_95 * V_9 = V_43 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_51 * V_129 = & V_5 -> V_16 ;
unsigned long V_118 ;
int V_13 = 0 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = V_9 -> V_10 ;
V_129 -> type = V_130 ;
F_8 ( V_9 -> V_10 , V_129 ) ;
V_8 = V_9 -> V_10 -> V_8 ;
V_118 = F_32 ( V_2 -> V_15 -> V_120 ) ;
if ( V_118 > 0 ) {
struct V_39 * V_40 = & V_129 -> V_41 [ 1 ] ;
if ( V_2 != V_43 -> V_131 ) {
F_3 ( L_24 ) ;
goto V_132;
}
F_9 ( V_8 -> V_53 ,
V_10 -> V_59 , V_2 -> V_133 ,
V_42 ) ;
memcpy ( V_9 -> V_10 -> V_67 , V_2 -> V_20 ,
V_2 -> V_133 ) ;
F_37 ( V_8 -> V_53 ,
V_10 -> V_59 , V_2 -> V_133 ,
V_42 ) ;
V_40 -> V_47 = V_9 -> V_10 -> V_59 ;
V_40 -> V_48 = V_2 -> V_133 ;
V_40 -> V_49 = V_8 -> V_57 -> V_49 ;
V_129 -> V_50 = 2 ;
}
if ( V_2 == V_43 -> V_131 ) {
F_6 ( L_25 ,
V_2 -> V_15 -> V_96 , V_118 ) ;
V_13 = F_38 ( V_9 -> V_10 ) ;
if ( V_13 )
goto V_132;
V_13 = F_20 ( V_43 , V_2 -> V_15 ) ;
if ( V_13 )
goto V_132;
}
V_13 = F_30 ( V_9 -> V_10 , V_129 ) ;
if ( ! V_13 )
return 0 ;
V_132:
F_3 ( L_23 , V_43 , V_13 ) ;
return V_13 ;
}
void F_39 ( struct V_75 * V_76 ,
unsigned long V_134 ,
struct V_9 * V_10 )
{
struct V_95 * V_43 = V_10 -> V_9 ;
struct V_93 * V_15 ;
T_1 V_135 ;
int V_136 , V_137 , V_138 , V_13 ;
if ( ( char * ) V_76 == V_10 -> V_68 ) {
V_135 = V_10 -> V_61 ;
V_136 = V_62 ;
} else {
V_135 = V_76 -> V_54 ;
V_136 = V_88 ;
}
F_9 ( V_10 -> V_8 -> V_53 , V_135 ,
V_136 , V_22 ) ;
V_15 = & V_76 -> V_127 ;
F_6 ( L_26 , V_15 -> V_96 ,
V_15 -> V_24 , ( int ) ( V_134 - V_55 ) ) ;
F_40 ( V_43 -> V_92 , V_15 ,
V_76 -> V_20 , V_134 - V_55 ) ;
F_37 ( V_10 -> V_8 -> V_53 , V_135 ,
V_136 , V_22 ) ;
V_43 -> V_10 -> V_98 -- ;
if ( V_135 == V_10 -> V_61 )
return;
V_137 = V_10 -> V_98 ;
if ( V_137 + V_10 -> V_81 <= V_10 -> V_78 ) {
V_138 = F_41 ( V_10 -> V_78 - V_137 ,
V_10 -> V_81 ) ;
V_13 = F_24 ( V_10 , V_138 ) ;
if ( V_13 )
F_3 ( L_27 , V_138 , V_13 ) ;
}
}
void F_42 ( struct V_51 * V_52 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 = V_10 -> V_8 ;
if ( V_52 -> type == V_126 ) {
F_11 ( V_8 -> V_53 , V_52 -> V_54 ,
V_55 , V_42 ) ;
F_35 ( V_123 . V_124 , V_52 ) ;
V_52 = NULL ;
}
F_43 ( & V_10 -> V_99 ) ;
if ( V_52 && V_52 -> type == V_130 ) {
V_2 = ( void * ) ( ( long ) ( void * ) V_52 -
sizeof( struct V_1 ) ) ;
if ( V_2 -> V_15 -> V_24 == V_139 )
F_44 ( V_2 ) ;
}
}
void F_45 ( struct V_4 * V_5 )
{
V_5 -> V_114 = V_140 ;
V_5 -> V_141 [ V_21 ] = 0 ;
V_5 -> V_141 [ V_38 ] = 0 ;
V_5 -> V_20 [ V_21 ] . V_23 = 0 ;
V_5 -> V_20 [ V_38 ] . V_23 = 0 ;
memset ( & V_5 -> V_27 [ V_21 ] , 0 ,
sizeof( struct V_11 ) ) ;
memset ( & V_5 -> V_27 [ V_38 ] , 0 ,
sizeof( struct V_11 ) ) ;
}
void F_46 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 -> V_10 -> V_8 ;
int V_142 = 1 ;
if ( V_5 -> V_143 [ V_21 ] . V_144 != NULL ) {
V_142 = 0 ;
F_47 ( V_5 , V_21 ) ;
}
if ( V_5 -> V_143 [ V_38 ] . V_144 != NULL ) {
V_142 = 0 ;
F_47 ( V_5 , V_38 ) ;
}
if ( V_5 -> V_141 [ V_21 ] )
V_8 -> V_145 ( V_5 , V_21 ) ;
if ( V_5 -> V_141 [ V_38 ] )
V_8 -> V_145 ( V_5 , V_38 ) ;
if ( V_142 )
F_48 ( V_5 ) ;
}
