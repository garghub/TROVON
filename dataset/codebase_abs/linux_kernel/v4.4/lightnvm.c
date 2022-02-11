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
}
return 0 ;
}
static int V_1 ( struct V_40 * V_41 , struct V_12 * V_12 )
{
struct V_42 * V_43 = V_41 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
struct V_10 * V_10 ;
struct V_48 V_49 = {} ;
int V_50 ;
V_49 . V_51 . V_52 = V_53 ;
V_49 . V_51 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_49 . V_51 . V_56 = 0 ;
V_10 = F_8 ( sizeof( struct V_10 ) , V_57 ) ;
if ( ! V_10 )
return - V_58 ;
V_50 = F_9 ( V_47 -> V_59 , (struct V_60 * ) & V_49 ,
V_10 , sizeof( struct V_10 ) ) ;
if ( V_50 ) {
V_50 = - V_61 ;
goto V_62;
}
V_12 -> V_63 = V_10 -> V_63 ;
V_12 -> V_64 = V_10 -> V_64 ;
V_12 -> V_19 = V_10 -> V_19 ;
V_12 -> V_65 = F_6 ( V_10 -> V_65 ) ;
V_12 -> V_66 = F_6 ( V_10 -> V_66 ) ;
memcpy ( & V_12 -> V_67 , & V_10 -> V_67 ,
sizeof( struct V_9 ) ) ;
V_50 = F_3 ( V_12 , V_10 ) ;
V_62:
F_10 ( V_10 ) ;
return V_50 ;
}
static int F_11 ( struct V_40 * V_41 , T_1 V_68 , V_18 V_69 ,
T_2 * V_70 , void * V_71 )
{
struct V_42 * V_43 = V_41 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
struct V_48 V_49 = {} ;
V_18 V_72 = F_12 ( V_47 -> V_59 ) << 9 ;
V_18 V_73 = V_72 / sizeof( T_1 ) ;
T_1 V_74 = V_68 ;
void * V_75 ;
int V_50 = 0 ;
V_49 . V_76 . V_52 = V_77 ;
V_49 . V_76 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_75 = F_8 ( V_72 , V_57 ) ;
if ( ! V_75 )
return - V_58 ;
while ( V_69 ) {
V_18 V_78 = F_13 ( V_73 , V_69 ) ;
V_49 . V_76 . V_68 = F_14 ( V_74 ) ;
V_49 . V_76 . V_69 = F_7 ( V_78 ) ;
V_50 = F_9 ( V_47 -> V_59 ,
(struct V_60 * ) & V_49 , V_75 , V_72 ) ;
if ( V_50 ) {
F_15 ( V_47 -> V_47 , L_1 ,
V_50 ) ;
V_50 = - V_61 ;
goto V_62;
}
if ( V_70 ( V_74 , V_78 , V_75 , V_71 ) ) {
V_50 = - V_79 ;
goto V_62;
}
V_74 += V_78 ;
V_69 -= V_78 ;
}
V_62:
F_10 ( V_75 ) ;
return V_50 ;
}
static int F_16 ( struct V_40 * V_41 , struct V_80 V_81 ,
int V_82 , T_3 * V_83 ,
void * V_71 )
{
struct V_84 * V_44 = V_41 -> V_44 ;
struct V_42 * V_43 = V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
struct V_48 V_49 = {} ;
struct V_11 * V_85 ;
int V_86 = sizeof( struct V_11 ) + V_82 ;
int V_50 = 0 ;
V_49 . V_87 . V_52 = V_88 ;
V_49 . V_87 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_49 . V_87 . V_89 = F_14 ( V_81 . V_81 ) ;
V_85 = F_17 ( V_86 , V_57 ) ;
if ( ! V_85 )
return - V_58 ;
V_50 = F_9 ( V_47 -> V_59 , (struct V_60 * ) & V_49 ,
V_85 , V_86 ) ;
if ( V_50 ) {
F_15 ( V_47 -> V_47 , L_2 , V_50 ) ;
V_50 = - V_61 ;
goto V_62;
}
if ( V_85 -> V_90 [ 0 ] != 'B' || V_85 -> V_90 [ 1 ] != 'B' ||
V_85 -> V_90 [ 2 ] != 'L' || V_85 -> V_90 [ 3 ] != 'T' ) {
F_15 ( V_47 -> V_47 , L_3 ) ;
V_50 = - V_91 ;
goto V_62;
}
if ( F_5 ( V_85 -> V_92 ) != 1 ) {
V_50 = - V_91 ;
F_15 ( V_47 -> V_47 , L_4 ) ;
goto V_62;
}
if ( F_6 ( V_85 -> V_93 ) != V_82 ) {
V_50 = - V_91 ;
F_15 ( V_47 -> V_47 , L_5 ,
F_6 ( V_85 -> V_93 ) , V_82 ) ;
goto V_62;
}
V_81 = F_18 ( V_41 , V_81 ) ;
V_50 = V_83 ( V_81 , V_82 , V_85 -> V_94 , V_71 ) ;
if ( V_50 ) {
V_50 = - V_79 ;
goto V_62;
}
V_62:
F_10 ( V_85 ) ;
return V_50 ;
}
static int F_19 ( struct V_40 * V_41 , struct V_95 * V_96 ,
int type )
{
struct V_42 * V_43 = V_41 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
struct V_48 V_49 = {} ;
int V_50 = 0 ;
V_49 . V_97 . V_52 = V_98 ;
V_49 . V_97 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_49 . V_97 . V_89 = F_14 ( V_96 -> V_80 . V_81 ) ;
V_49 . V_97 . V_69 = F_20 ( V_96 -> V_99 - 1 ) ;
V_49 . V_97 . V_100 = type ;
V_50 = F_9 ( V_47 -> V_59 , (struct V_60 * ) & V_49 ,
NULL , 0 ) ;
if ( V_50 )
F_15 ( V_47 -> V_47 , L_6 , V_50 ) ;
return V_50 ;
}
static inline void F_21 ( struct V_101 * V_102 , struct V_95 * V_96 ,
struct V_42 * V_43 , struct V_48 * V_49 )
{
V_49 -> V_103 . V_52 = V_96 -> V_52 ;
V_49 -> V_103 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_49 -> V_103 . V_89 = F_14 ( V_96 -> V_80 . V_81 ) ;
V_49 -> V_103 . V_104 = F_20 ( V_96 -> V_105 ) ;
V_49 -> V_103 . V_106 = F_20 ( V_96 -> V_99 - 1 ) ;
if ( V_96 -> V_52 == V_107 || V_96 -> V_52 == V_108 )
V_49 -> V_109 . V_68 = F_14 ( F_22 ( V_43 ,
V_96 -> V_110 -> V_111 . V_112 ) ) ;
}
static void F_23 ( struct V_101 * V_102 , int error )
{
struct V_95 * V_96 = V_102 -> V_113 ;
struct V_40 * V_47 = V_96 -> V_47 ;
if ( V_47 -> V_114 && V_47 -> V_114 -> V_115 ( V_96 , error ) )
F_24 ( L_7 ,
V_102 -> V_116 , ( unsigned long ) V_102 -> V_117 ) ;
F_10 ( V_102 -> V_118 ) ;
F_25 ( V_102 ) ;
}
static int F_26 ( struct V_40 * V_47 , struct V_95 * V_96 )
{
struct V_84 * V_44 = V_47 -> V_44 ;
struct V_42 * V_43 = V_44 -> V_45 ;
struct V_101 * V_102 ;
struct V_110 * V_110 = V_96 -> V_110 ;
struct V_48 * V_118 ;
V_102 = F_27 ( V_44 , F_28 ( V_110 ) , V_57 , 0 ) ;
if ( F_29 ( V_102 ) )
return - V_58 ;
V_118 = F_17 ( sizeof( struct V_48 ) , V_57 ) ;
if ( ! V_118 ) {
F_25 ( V_102 ) ;
return - V_58 ;
}
V_102 -> V_119 = V_120 ;
V_102 -> V_121 = F_30 ( V_110 ) ;
if ( F_31 ( V_110 ) )
V_102 -> V_122 = F_32 ( V_44 , V_110 ) ;
V_102 -> V_123 = V_110 -> V_111 . V_124 ;
V_102 -> V_110 = V_102 -> V_125 = V_110 ;
F_21 ( V_102 , V_96 , V_43 , V_118 ) ;
V_102 -> V_118 = ( unsigned char * ) V_118 ;
V_102 -> V_126 = sizeof( struct V_48 ) ;
V_102 -> V_117 = ( void * ) 0 ;
V_102 -> V_113 = V_96 ;
F_33 ( V_44 , NULL , V_102 , 0 , F_23 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_47 , struct V_95 * V_96 )
{
struct V_84 * V_44 = V_47 -> V_44 ;
struct V_42 * V_43 = V_44 -> V_45 ;
struct V_48 V_49 = {} ;
V_49 . V_127 . V_52 = V_128 ;
V_49 . V_127 . V_54 = F_7 ( V_43 -> V_55 ) ;
V_49 . V_127 . V_89 = F_14 ( V_96 -> V_80 . V_81 ) ;
V_49 . V_127 . V_106 = F_20 ( V_96 -> V_99 - 1 ) ;
return F_9 ( V_44 , (struct V_60 * ) & V_49 , NULL , 0 ) ;
}
static void * F_35 ( struct V_40 * V_41 , char * V_129 )
{
struct V_42 * V_43 = V_41 -> V_44 -> V_45 ;
struct V_46 * V_47 = V_43 -> V_47 ;
return F_36 ( V_129 , V_47 -> V_47 , V_130 , V_130 , 0 ) ;
}
static void F_37 ( void * V_131 )
{
struct V_132 * V_132 = V_131 ;
F_38 ( V_132 ) ;
}
static void * F_39 ( struct V_40 * V_47 , void * V_131 ,
T_4 V_133 , T_5 * V_134 )
{
return F_40 ( V_131 , V_133 , V_134 ) ;
}
static void F_41 ( void * V_131 , void * V_135 ,
T_5 V_134 )
{
F_42 ( V_131 , V_135 , V_134 ) ;
}
int F_43 ( struct V_84 * V_44 , char * V_136 )
{
return F_44 ( V_44 , V_136 , & V_137 ) ;
}
void F_45 ( struct V_84 * V_44 , char * V_136 )
{
F_46 ( V_136 ) ;
}
int F_47 ( struct V_42 * V_43 , struct V_138 * V_139 )
{
struct V_46 * V_47 = V_43 -> V_47 ;
struct V_140 * V_141 = F_48 ( V_47 -> V_47 ) ;
if ( V_141 -> V_142 == V_143 &&
V_141 -> V_144 == V_145 &&
V_139 -> V_146 [ 0 ] == 0x1 )
return 1 ;
if ( V_141 -> V_142 == V_143 &&
V_141 -> V_144 == V_147 &&
V_139 -> V_146 [ 0 ] == 0x1 )
return 1 ;
return 0 ;
}
