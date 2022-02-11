static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 64 ) ;
F_2 ( sizeof( struct V_8 ) != 960 ) ;
F_2 ( sizeof( struct V_9 ) != 128 ) ;
F_2 ( sizeof( struct V_10 ) != 4096 ) ;
F_2 ( sizeof( struct V_11 ) != 512 ) ;
}
static int F_3 ( struct V_12 * V_12 , struct V_10 * V_10 )
{
struct V_8 * V_13 ;
struct V_14 * V_15 ;
int V_16 , V_17 ;
V_17 = F_4 ( V_18 , 4 , V_12 -> V_19 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_13 = & V_10 -> V_20 [ V_16 ] ;
V_15 = & V_12 -> V_20 [ V_16 ] ;
V_15 -> V_21 = V_13 -> V_21 ;
V_15 -> V_22 = V_13 -> V_22 ;
V_15 -> V_23 = V_13 -> V_23 ;
V_15 -> V_24 = V_13 -> V_24 ;
V_15 -> V_25 = V_13 -> V_25 ;
V_15 -> V_26 = F_5 ( V_13 -> V_26 ) ;
V_15 -> V_27 = F_5 ( V_13 -> V_27 ) ;
V_15 -> V_28 = F_5 ( V_13 -> V_28 ) ;
V_15 -> V_29 = F_5 ( V_13 -> V_29 ) ;
V_15 -> V_30 = F_5 ( V_13 -> V_30 ) ;
V_15 -> V_31 = F_6 ( V_13 -> V_31 ) ;
V_15 -> V_32 = F_6 ( V_13 -> V_32 ) ;
V_15 -> V_33 = F_6 ( V_13 -> V_33 ) ;
V_15 -> V_34 = F_6 ( V_13 -> V_34 ) ;
V_15 -> V_35 = F_6 ( V_13 -> V_35 ) ;
V_15 -> V_36 = F_6 ( V_13 -> V_36 ) ;
V_15 -> V_37 = F_6 ( V_13 -> V_37 ) ;
V_15 -> V_38 = F_6 ( V_13 -> V_38 ) ;
V_15 -> V_39 = F_5 ( V_13 -> V_39 ) ;
if ( V_15 -> V_22 == V_40 ) {
memcpy ( V_15 -> V_41 . V_42 , V_13 -> V_41 . V_42 , 8 ) ;
V_15 -> V_41 . V_43 . V_44 =
F_5 ( V_13 -> V_41 . V_43 . V_44 ) ;
if ( V_15 -> V_41 . V_43 . V_44 > V_45 ) {
F_7 ( L_1 ) ;
return - V_46 ;
}
memcpy ( V_15 -> V_41 . V_43 . V_47 , V_13 -> V_41 . V_43 . V_47 ,
V_15 -> V_41 . V_43 . V_44 ) ;
}
}
return 0 ;
}
static int V_1 ( struct V_48 * V_49 , struct V_12 * V_12 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_10 * V_10 ;
struct V_54 V_55 = {} ;
int V_56 ;
V_55 . V_57 . V_58 = V_59 ;
V_55 . V_57 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_57 . V_62 = 0 ;
V_10 = F_9 ( sizeof( struct V_10 ) , V_63 ) ;
if ( ! V_10 )
return - V_64 ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_10 , sizeof( struct V_10 ) ) ;
if ( V_56 ) {
V_56 = - V_68 ;
goto V_69;
}
V_12 -> V_70 = V_10 -> V_70 ;
V_12 -> V_71 = V_10 -> V_71 ;
V_12 -> V_19 = V_10 -> V_19 ;
V_12 -> V_72 = F_6 ( V_10 -> V_72 ) ;
V_12 -> V_73 = F_6 ( V_10 -> V_73 ) ;
memcpy ( & V_12 -> V_74 , & V_10 -> V_74 ,
sizeof( struct V_9 ) ) ;
V_56 = F_3 ( V_12 , V_10 ) ;
V_69:
F_11 ( V_10 ) ;
return V_56 ;
}
static int F_12 ( struct V_48 * V_49 , T_1 V_75 , V_18 V_76 ,
T_2 * V_77 , void * V_78 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_18 V_79 = F_13 ( V_51 -> V_65 -> V_66 ) << 9 ;
V_18 V_80 = V_79 / sizeof( T_1 ) ;
T_1 V_81 = V_75 ;
void * V_82 ;
int V_56 = 0 ;
V_55 . V_83 . V_58 = V_84 ;
V_55 . V_83 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_82 = F_9 ( V_79 , V_63 ) ;
if ( ! V_82 )
return - V_64 ;
while ( V_76 ) {
V_18 V_85 = F_14 ( V_80 , V_76 ) ;
V_55 . V_83 . V_75 = F_15 ( V_81 ) ;
V_55 . V_83 . V_76 = F_8 ( V_85 ) ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 ,
(struct V_67 * ) & V_55 , V_82 , V_79 ) ;
if ( V_56 ) {
F_16 ( V_51 -> V_65 -> V_86 , L_2 ,
V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_77 ( V_81 , V_85 , V_82 , V_78 ) ) {
V_56 = - V_87 ;
goto V_69;
}
V_81 += V_85 ;
V_76 -= V_85 ;
}
V_69:
F_11 ( V_82 ) ;
return V_56 ;
}
static int F_17 ( struct V_48 * V_49 , struct V_88 V_89 ,
int V_90 , T_3 * V_91 ,
void * V_78 )
{
struct V_92 * V_52 = V_49 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_93 * V_65 = V_51 -> V_65 ;
struct V_54 V_55 = {} ;
struct V_11 * V_94 ;
int V_95 = sizeof( struct V_11 ) + V_90 ;
int V_56 = 0 ;
V_55 . V_96 . V_58 = V_97 ;
V_55 . V_96 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_96 . V_98 = F_15 ( V_89 . V_89 ) ;
V_94 = F_18 ( V_95 , V_63 ) ;
if ( ! V_94 )
return - V_64 ;
V_56 = F_10 ( V_65 -> V_66 , (struct V_67 * ) & V_55 ,
V_94 , V_95 ) ;
if ( V_56 ) {
F_16 ( V_65 -> V_86 , L_3 , V_56 ) ;
V_56 = - V_68 ;
goto V_69;
}
if ( V_94 -> V_99 [ 0 ] != 'B' || V_94 -> V_99 [ 1 ] != 'B' ||
V_94 -> V_99 [ 2 ] != 'L' || V_94 -> V_99 [ 3 ] != 'T' ) {
F_16 ( V_65 -> V_86 , L_4 ) ;
V_56 = - V_46 ;
goto V_69;
}
if ( F_5 ( V_94 -> V_100 ) != 1 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 , L_5 ) ;
goto V_69;
}
if ( F_6 ( V_94 -> V_101 ) != V_90 ) {
V_56 = - V_46 ;
F_16 ( V_65 -> V_86 , L_6 ,
F_6 ( V_94 -> V_101 ) , V_90 ) ;
goto V_69;
}
V_89 = F_19 ( V_49 , V_89 ) ;
V_56 = V_91 ( V_89 , V_90 , V_94 -> V_102 , V_78 ) ;
V_69:
F_11 ( V_94 ) ;
return V_56 ;
}
static int F_20 ( struct V_48 * V_49 , struct V_103 * V_104 ,
int type )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
struct V_54 V_55 = {} ;
int V_56 = 0 ;
V_55 . V_105 . V_58 = V_106 ;
V_55 . V_105 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_105 . V_98 = F_15 ( V_104 -> V_88 . V_89 ) ;
V_55 . V_105 . V_76 = F_21 ( V_104 -> V_107 - 1 ) ;
V_55 . V_105 . V_108 = type ;
V_56 = F_10 ( V_51 -> V_65 -> V_66 , (struct V_67 * ) & V_55 ,
NULL , 0 ) ;
if ( V_56 )
F_16 ( V_51 -> V_65 -> V_86 , L_7 , V_56 ) ;
return V_56 ;
}
static inline void F_22 ( struct V_109 * V_110 , struct V_103 * V_104 ,
struct V_50 * V_51 , struct V_54 * V_55 )
{
V_55 -> V_111 . V_58 = V_104 -> V_58 ;
V_55 -> V_111 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 -> V_111 . V_98 = F_15 ( V_104 -> V_88 . V_89 ) ;
V_55 -> V_111 . V_112 = F_21 ( V_104 -> V_113 ) ;
V_55 -> V_111 . V_114 = F_21 ( V_104 -> V_107 - 1 ) ;
if ( V_104 -> V_58 == V_115 || V_104 -> V_58 == V_116 )
V_55 -> V_117 . V_75 = F_15 ( F_23 ( V_51 ,
V_104 -> V_118 -> V_119 . V_120 ) ) ;
}
static void F_24 ( struct V_109 * V_110 , int error )
{
struct V_103 * V_104 = V_110 -> V_121 ;
F_25 ( V_104 , error ) ;
F_11 ( V_110 -> V_122 ) ;
F_26 ( V_110 ) ;
}
static int F_27 ( struct V_48 * V_86 , struct V_103 * V_104 )
{
struct V_92 * V_52 = V_86 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_109 * V_110 ;
struct V_118 * V_118 = V_104 -> V_118 ;
struct V_54 * V_122 ;
V_110 = F_28 ( V_52 , F_29 ( V_118 ) , 0 ) ;
if ( F_30 ( V_110 ) )
return - V_64 ;
V_122 = F_18 ( sizeof( struct V_54 ) , V_63 ) ;
if ( ! V_122 ) {
F_26 ( V_110 ) ;
return - V_64 ;
}
V_110 -> V_123 = V_124 ;
V_110 -> V_125 = F_31 ( V_118 ) ;
if ( F_32 ( V_118 ) )
V_110 -> V_126 = F_33 ( V_52 , V_118 ) ;
V_110 -> V_127 = V_118 -> V_119 . V_128 ;
V_110 -> V_118 = V_110 -> V_129 = V_118 ;
F_22 ( V_110 , V_104 , V_51 , V_122 ) ;
V_110 -> V_122 = ( unsigned char * ) V_122 ;
V_110 -> V_130 = sizeof( struct V_54 ) ;
V_110 -> V_131 = ( void * ) 0 ;
V_110 -> V_121 = V_104 ;
F_34 ( V_52 , NULL , V_110 , 0 , F_24 ) ;
return 0 ;
}
static int F_35 ( struct V_48 * V_86 , struct V_103 * V_104 )
{
struct V_92 * V_52 = V_86 -> V_52 ;
struct V_50 * V_51 = V_52 -> V_53 ;
struct V_54 V_55 = {} ;
V_55 . V_132 . V_58 = V_133 ;
V_55 . V_132 . V_60 = F_8 ( V_51 -> V_61 ) ;
V_55 . V_132 . V_98 = F_15 ( V_104 -> V_88 . V_89 ) ;
V_55 . V_132 . V_114 = F_21 ( V_104 -> V_107 - 1 ) ;
return F_10 ( V_52 , (struct V_67 * ) & V_55 , NULL , 0 ) ;
}
static void * F_36 ( struct V_48 * V_49 , char * V_134 )
{
struct V_50 * V_51 = V_49 -> V_52 -> V_53 ;
return F_37 ( V_134 , V_51 -> V_65 -> V_86 , V_135 , V_135 , 0 ) ;
}
static void F_38 ( void * V_136 )
{
struct V_137 * V_137 = V_136 ;
F_39 ( V_137 ) ;
}
static void * F_40 ( struct V_48 * V_86 , void * V_136 ,
T_4 V_138 , T_5 * V_139 )
{
return F_41 ( V_136 , V_138 , V_139 ) ;
}
static void F_42 ( void * V_136 , void * V_140 ,
T_5 V_139 )
{
F_43 ( V_136 , V_140 , V_139 ) ;
}
int F_44 ( struct V_92 * V_52 , char * V_141 )
{
return F_45 ( V_52 , V_141 , & V_142 ) ;
}
void F_46 ( struct V_92 * V_52 , char * V_141 )
{
F_47 ( V_141 ) ;
}
int F_48 ( struct V_50 * V_51 , struct V_143 * V_42 )
{
struct V_93 * V_65 = V_51 -> V_65 ;
struct V_144 * V_145 = F_49 ( V_65 -> V_86 ) ;
if ( V_145 -> V_146 == V_147 &&
V_145 -> V_148 == V_149 &&
V_42 -> V_150 [ 0 ] == 0x1 )
return 1 ;
if ( V_145 -> V_146 == V_147 &&
V_145 -> V_148 == V_151 &&
V_42 -> V_150 [ 0 ] == 0x1 )
return 1 ;
return 0 ;
}
