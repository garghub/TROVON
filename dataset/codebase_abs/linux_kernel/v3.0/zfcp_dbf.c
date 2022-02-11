static inline unsigned int F_1 ( unsigned int V_1 )
{
return sizeof( struct V_2 ) + V_1 - V_3 ;
}
static inline
void F_2 ( struct V_4 * V_5 , void * V_6 , T_1 V_7 , char * V_8 ,
T_2 V_9 )
{
struct V_2 * V_10 = & V_5 -> V_11 ;
T_1 V_1 = 0 , V_12 ;
F_3 ( & V_5 -> V_13 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 = V_9 ;
memcpy ( V_10 -> V_8 , V_8 , V_15 ) ;
while ( V_1 < V_7 ) {
V_12 = F_4 ( ( T_1 ) V_3 ,
( T_1 ) ( V_7 - V_1 ) ) ;
memcpy ( V_10 -> V_6 , V_6 + V_1 , V_12 ) ;
F_5 ( V_5 -> V_16 , 1 , V_10 , F_1 ( V_12 ) ) ;
V_1 += V_12 ;
V_10 -> V_17 ++ ;
}
F_6 ( & V_5 -> V_13 ) ;
}
void F_7 ( char * V_18 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_21 -> V_5 ;
struct V_22 * V_23 = & V_20 -> V_24 -> V_25 ;
struct V_26 * V_27 = & V_20 -> V_24 -> V_28 ;
struct V_29 * V_30 = & V_5 -> V_31 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_33 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_35 ;
V_30 -> V_14 = V_20 -> V_9 ;
V_30 -> V_36 = V_20 -> V_37 ;
V_30 -> V_38 = V_20 -> V_39 ;
V_30 -> V_40 = V_20 -> V_41 ;
V_30 -> V_42 . V_43 . V_44 = V_20 -> V_45 ;
V_30 -> V_42 . V_43 . V_46 = V_23 -> V_46 ;
V_30 -> V_42 . V_43 . V_47 = V_27 -> V_47 ;
memcpy ( V_30 -> V_42 . V_43 . V_48 , & V_23 -> V_48 ,
V_49 ) ;
memcpy ( V_30 -> V_42 . V_43 . V_50 , & V_27 -> V_50 ,
V_51 ) ;
if ( V_20 -> V_39 != V_52 ) {
V_30 -> V_53 = V_27 -> V_54 ;
F_2 ( V_5 , ( char * ) V_23 + V_27 -> V_55 ,
V_30 -> V_53 , L_1 , V_20 -> V_9 ) ;
}
F_5 ( V_5 -> V_56 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_33 , V_32 ) ;
}
void F_10 ( char * V_18 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_21 -> V_5 ;
struct V_57 * V_58 = V_20 -> V_6 ;
struct V_29 * V_30 = & V_5 -> V_31 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_33 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_59 ;
V_30 -> V_14 = V_20 -> V_9 ;
V_30 -> V_36 = V_20 -> V_37 ;
V_30 -> V_38 = V_20 -> V_39 ;
if ( ! V_58 )
goto log;
V_30 -> V_42 . V_60 . V_61 = V_58 -> V_61 ;
V_30 -> V_42 . V_60 . V_62 = V_58 -> V_62 ;
V_30 -> V_42 . V_60 . V_63 = F_11 ( V_58 -> V_63 ) ;
V_30 -> V_42 . V_60 . V_64 = V_58 -> V_65 ;
memcpy ( & V_30 -> V_42 . V_60 . V_66 , & V_58 -> V_66 ,
sizeof( V_30 -> V_42 . V_60 . V_66 ) ) ;
V_30 -> V_53 = ( ! V_58 -> V_7 ) ? 0 : V_58 -> V_7 -
F_12 ( struct V_57 , V_67 ) ;
if ( V_30 -> V_53 )
F_2 ( V_5 , V_58 -> V_67 . V_6 , V_30 -> V_53 ,
L_2 , V_20 -> V_9 ) ;
log:
F_5 ( V_5 -> V_56 , 2 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_33 , V_32 ) ;
}
void F_13 ( char * V_18 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_21 -> V_5 ;
struct V_29 * V_30 = & V_5 -> V_31 ;
struct V_57 * V_68 = V_20 -> V_6 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_33 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_69 ;
V_30 -> V_14 = V_20 -> V_9 ;
V_30 -> V_36 = V_20 -> V_37 ;
V_30 -> V_38 = V_20 -> V_39 ;
memcpy ( & V_30 -> V_42 . V_70 , & V_68 -> V_67 . V_71 ,
sizeof( struct V_72 ) ) ;
F_5 ( V_5 -> V_56 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_33 , V_32 ) ;
}
static void F_14 ( struct V_73 * V_30 ,
struct V_74 * V_21 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
V_30 -> V_79 = F_15 ( & V_21 -> V_37 ) ;
if ( V_76 ) {
V_30 -> V_80 = F_15 ( & V_76 -> V_37 ) ;
V_30 -> V_81 = V_76 -> V_81 ;
V_30 -> V_63 = V_76 -> V_63 ;
}
if ( V_78 ) {
V_30 -> V_82 = F_15 ( & F_16 ( V_78 ) -> V_37 ) ;
V_30 -> V_64 = F_17 ( V_78 ) ;
}
}
void F_18 ( char * V_18 , struct V_74 * V_21 ,
struct V_75 * V_76 , struct V_77 * V_78 ,
T_3 V_83 , T_3 V_84 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_73 * V_30 = & V_5 -> V_85 ;
struct V_86 * V_87 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_88 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_89 ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_14 ( V_30 , V_21 , V_76 , V_78 ) ;
F_19 (entry, &adapter->erp_ready_head)
V_30 -> V_42 . V_90 . V_91 ++ ;
F_19 (entry, &adapter->erp_running_head)
V_30 -> V_42 . V_90 . V_92 ++ ;
V_30 -> V_42 . V_90 . V_83 = V_83 ;
V_30 -> V_42 . V_90 . V_84 = V_84 ;
F_5 ( V_5 -> V_30 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_88 , V_32 ) ;
}
void F_20 ( char * V_18 , struct V_93 * V_94 )
{
struct V_4 * V_5 = V_94 -> V_21 -> V_5 ;
struct V_73 * V_30 = & V_5 -> V_85 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_88 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_95 ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_14 ( V_30 , V_94 -> V_21 , V_94 -> V_76 , V_94 -> V_78 ) ;
V_30 -> V_42 . V_96 . V_14 = V_94 -> V_14 ;
V_30 -> V_42 . V_96 . V_97 = V_94 -> V_37 ;
V_30 -> V_42 . V_96 . V_98 = V_94 -> V_99 ;
V_30 -> V_42 . V_96 . V_100 = V_94 -> V_101 ;
if ( V_94 -> V_78 )
V_30 -> V_42 . V_96 . V_102 =
F_15 ( & F_16 ( V_94 -> V_78 ) -> V_103 ) ;
else if ( V_94 -> V_76 )
V_30 -> V_42 . V_96 . V_102 = F_15 ( & V_94 -> V_76 -> V_103 ) ;
else
V_30 -> V_42 . V_96 . V_102 = F_15 ( & V_94 -> V_21 -> V_103 ) ;
F_5 ( V_5 -> V_30 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_88 , V_32 ) ;
}
static inline
void F_21 ( char * V_18 , struct V_4 * V_5 , void * V_6 , T_3 V_34 , T_1 V_104 ,
T_2 V_9 , T_4 V_63 )
{
struct F_21 * V_30 = & V_5 -> V_105 ;
T_1 V_106 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_107 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_34 ;
V_30 -> V_14 = V_9 ;
V_30 -> V_63 = V_63 ;
V_106 = F_4 ( V_104 , ( T_1 ) V_108 ) ;
memcpy ( V_30 -> V_67 , V_6 , V_106 ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_5 ( V_5 -> V_109 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_107 , V_32 ) ;
}
void F_22 ( char * V_18 , struct V_19 * V_110 , T_4 V_63 )
{
struct V_4 * V_5 = V_110 -> V_21 -> V_5 ;
struct V_111 * V_112 = V_110 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_112 -> V_20 -> V_7 + V_113 ) ;
F_21 ( V_18 , V_5 , F_23 ( V_112 -> V_20 ) , V_114 , V_7 ,
V_110 -> V_9 , V_63 ) ;
}
void F_24 ( char * V_18 , struct V_19 * V_110 )
{
struct V_4 * V_5 = V_110 -> V_21 -> V_5 ;
struct V_111 * V_112 = V_110 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_112 -> V_115 -> V_7 + V_113 ) ;
F_21 ( V_18 , V_5 , F_23 ( V_112 -> V_115 ) , V_116 , V_7 ,
V_110 -> V_9 , 0 ) ;
}
void F_25 ( char * V_18 , struct V_19 * V_110 )
{
struct V_4 * V_5 = V_110 -> V_21 -> V_5 ;
struct V_57 * V_58 =
(struct V_57 * ) V_110 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_58 -> V_7 -
F_12 ( struct V_57 , V_67 ) ) ;
F_21 ( V_18 , V_5 , V_58 -> V_67 . V_6 , V_117 , V_7 ,
V_110 -> V_9 , F_11 ( V_58 -> V_63 ) ) ;
}
void F_26 ( char * V_18 , struct V_118 * V_119 , struct V_19 * V_110 )
{
struct V_74 * V_21 =
(struct V_74 * ) V_119 -> V_120 -> V_121 -> V_122 [ 0 ] ;
struct V_4 * V_5 = V_21 -> V_5 ;
struct F_26 * V_30 = & V_5 -> V_123 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_128 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_129 ;
V_30 -> V_130 = V_119 -> V_131 ;
V_30 -> V_132 = V_119 -> V_133 ;
V_30 -> V_134 = V_119 -> V_135 ;
V_30 -> V_136 = V_119 -> V_120 -> V_34 ;
V_30 -> V_137 = V_119 -> V_120 -> V_64 ;
V_30 -> V_138 = ( unsigned long ) V_119 -> V_138 ;
memcpy ( V_30 -> V_139 , V_119 -> V_140 ,
F_4 ( ( int ) V_119 -> V_141 , V_142 ) ) ;
if ( V_110 ) {
V_30 -> V_14 = V_110 -> V_9 ;
V_125 = (struct V_124 * )
& ( V_110 -> V_24 -> V_143 . V_144 . V_125 ) ;
memcpy ( & V_30 -> V_125 , V_125 , V_145 ) ;
if ( V_125 -> V_115 . V_146 & V_147 ) {
V_127 = (struct V_126 * ) & V_125 [ 1 ] ;
V_30 -> V_127 = V_127 -> V_148 ;
}
if ( V_125 -> V_115 . V_146 & V_149 ) {
V_30 -> V_53 = F_4 ( ( T_1 ) V_150 ,
( T_1 ) V_3 ) ;
F_2 ( V_5 , V_119 -> V_151 , V_30 -> V_53 ,
L_3 , V_110 -> V_9 ) ;
}
}
F_5 ( V_5 -> V_152 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_128 , V_32 ) ;
}
static T_5 * F_27 ( const char * V_153 , int V_154 , int V_155 )
{
struct V_156 * V_157 ;
V_157 = F_28 ( V_153 , V_154 , 1 , V_155 ) ;
if ( ! V_157 )
return NULL ;
F_29 ( V_157 , & V_158 ) ;
F_30 ( V_157 , 3 ) ;
return V_157 ;
}
static void F_31 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_32 ( V_5 -> V_152 ) ;
F_32 ( V_5 -> V_109 ) ;
F_32 ( V_5 -> V_56 ) ;
F_32 ( V_5 -> V_16 ) ;
F_32 ( V_5 -> V_30 ) ;
F_33 ( V_5 ) ;
}
int F_34 ( struct V_74 * V_21 )
{
char V_153 [ V_159 ] ;
struct V_4 * V_5 ;
V_5 = F_35 ( sizeof( struct V_4 ) , V_160 ) ;
if ( ! V_5 )
return - V_161 ;
F_36 ( & V_5 -> V_13 ) ;
F_36 ( & V_5 -> V_33 ) ;
F_36 ( & V_5 -> V_107 ) ;
F_36 ( & V_5 -> V_128 ) ;
F_36 ( & V_5 -> V_88 ) ;
sprintf ( V_153 , L_4 , F_37 ( & V_21 -> V_162 -> V_163 ) ) ;
V_5 -> V_30 = F_27 ( V_153 , V_164 , sizeof( struct V_73 ) ) ;
if ( ! V_5 -> V_30 )
goto V_165;
sprintf ( V_153 , L_5 , F_37 ( & V_21 -> V_162 -> V_163 ) ) ;
V_5 -> V_56 = F_27 ( V_153 , V_164 , sizeof( struct V_29 ) ) ;
if ( ! V_5 -> V_56 )
goto V_165;
sprintf ( V_153 , L_6 , F_37 ( & V_21 -> V_162 -> V_163 ) ) ;
V_5 -> V_16 = F_27 ( V_153 , V_164 * 2 , sizeof( struct V_2 ) ) ;
if ( ! V_5 -> V_16 )
goto V_165;
sprintf ( V_153 , L_7 , F_37 ( & V_21 -> V_162 -> V_163 ) ) ;
V_5 -> V_109 = F_27 ( V_153 , V_164 , sizeof( struct F_21 ) ) ;
if ( ! V_5 -> V_109 )
goto V_165;
sprintf ( V_153 , L_8 , F_37 ( & V_21 -> V_162 -> V_163 ) ) ;
V_5 -> V_152 = F_27 ( V_153 , V_164 , sizeof( struct F_26 ) ) ;
if ( ! V_5 -> V_152 )
goto V_165;
V_21 -> V_5 = V_5 ;
return 0 ;
V_165:
F_31 ( V_5 ) ;
return - V_161 ;
}
void F_38 ( struct V_74 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
V_21 -> V_5 = NULL ;
F_31 ( V_5 ) ;
}
