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
void F_14 ( struct V_73 * V_21 , T_2 V_9 , T_1 V_74 ,
void * * V_10 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_2 * V_67 = & V_5 -> V_11 ;
unsigned long V_32 ;
T_1 V_7 ;
if ( ! V_10 )
return;
F_8 ( & V_5 -> V_13 , V_32 ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
memcpy ( V_67 -> V_8 , L_3 , 7 ) ;
V_67 -> V_14 = V_9 ;
V_67 -> V_17 = 0 ;
V_7 = F_4 ( ( T_1 ) sizeof( struct V_75 ) ,
( T_1 ) V_3 ) ;
while ( V_67 -> V_17 < V_74 && ( char * ) V_10 [ V_67 -> V_17 ] ) {
memcpy ( V_67 -> V_6 , ( char * ) V_10 [ V_67 -> V_17 ] , V_7 ) ;
F_5 ( V_5 -> V_16 , 1 , V_67 , F_1 ( V_7 ) ) ;
V_67 -> V_17 ++ ;
}
F_9 ( & V_5 -> V_13 , V_32 ) ;
}
void F_15 ( char * V_18 , struct V_73 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_29 * V_30 = & V_5 -> V_31 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_33 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_76 ;
F_5 ( V_5 -> V_56 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_33 , V_32 ) ;
}
static void F_16 ( struct V_77 * V_30 ,
struct V_73 * V_21 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
V_30 -> V_82 = F_17 ( & V_21 -> V_37 ) ;
if ( V_79 ) {
V_30 -> V_83 = F_17 ( & V_79 -> V_37 ) ;
V_30 -> V_84 = V_79 -> V_84 ;
V_30 -> V_63 = V_79 -> V_63 ;
}
if ( V_81 ) {
V_30 -> V_85 = F_17 ( & F_18 ( V_81 ) -> V_37 ) ;
V_30 -> V_64 = F_19 ( V_81 ) ;
}
}
void F_20 ( char * V_18 , struct V_73 * V_21 ,
struct V_78 * V_79 , struct V_80 * V_81 ,
T_3 V_86 , T_3 V_87 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_77 * V_30 = & V_5 -> V_88 ;
struct V_89 * V_90 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_91 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_92 ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_16 ( V_30 , V_21 , V_79 , V_81 ) ;
F_21 (entry, &adapter->erp_ready_head)
V_30 -> V_42 . V_93 . V_94 ++ ;
F_21 (entry, &adapter->erp_running_head)
V_30 -> V_42 . V_93 . V_95 ++ ;
V_30 -> V_42 . V_93 . V_86 = V_86 ;
V_30 -> V_42 . V_93 . V_87 = V_87 ;
F_5 ( V_5 -> V_30 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_91 , V_32 ) ;
}
void F_22 ( char * V_18 , struct V_96 * V_97 )
{
struct V_4 * V_5 = V_97 -> V_21 -> V_5 ;
struct V_77 * V_30 = & V_5 -> V_88 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_91 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_98 ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_16 ( V_30 , V_97 -> V_21 , V_97 -> V_79 , V_97 -> V_81 ) ;
V_30 -> V_42 . V_99 . V_14 = V_97 -> V_14 ;
V_30 -> V_42 . V_99 . V_100 = V_97 -> V_37 ;
V_30 -> V_42 . V_99 . V_101 = V_97 -> V_102 ;
V_30 -> V_42 . V_99 . V_103 = V_97 -> V_104 ;
if ( V_97 -> V_81 )
V_30 -> V_42 . V_99 . V_105 =
F_17 ( & F_18 ( V_97 -> V_81 ) -> V_106 ) ;
else if ( V_97 -> V_79 )
V_30 -> V_42 . V_99 . V_105 = F_17 ( & V_97 -> V_79 -> V_106 ) ;
else
V_30 -> V_42 . V_99 . V_105 = F_17 ( & V_97 -> V_21 -> V_106 ) ;
F_5 ( V_5 -> V_30 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_91 , V_32 ) ;
}
static inline
void F_23 ( char * V_18 , struct V_4 * V_5 , void * V_6 , T_3 V_34 , T_1 V_107 ,
T_2 V_9 , T_4 V_63 )
{
struct F_23 * V_30 = & V_5 -> V_108 ;
T_1 V_109 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_110 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_34 = V_34 ;
V_30 -> V_14 = V_9 ;
V_30 -> V_63 = V_63 ;
V_109 = F_4 ( V_107 , ( T_1 ) V_111 ) ;
memcpy ( V_30 -> V_67 , V_6 , V_109 ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
F_5 ( V_5 -> V_112 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_110 , V_32 ) ;
}
void F_24 ( char * V_18 , struct V_19 * V_113 , T_4 V_63 )
{
struct V_4 * V_5 = V_113 -> V_21 -> V_5 ;
struct V_114 * V_115 = V_113 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_115 -> V_20 -> V_7 + V_116 ) ;
F_23 ( V_18 , V_5 , F_25 ( V_115 -> V_20 ) , V_117 , V_7 ,
V_113 -> V_9 , V_63 ) ;
}
void F_26 ( char * V_18 , struct V_19 * V_113 )
{
struct V_4 * V_5 = V_113 -> V_21 -> V_5 ;
struct V_114 * V_115 = V_113 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_115 -> V_118 -> V_7 + V_116 ) ;
F_23 ( V_18 , V_5 , F_25 ( V_115 -> V_118 ) , V_119 , V_7 ,
V_113 -> V_9 , 0 ) ;
}
void F_27 ( char * V_18 , struct V_19 * V_113 )
{
struct V_4 * V_5 = V_113 -> V_21 -> V_5 ;
struct V_57 * V_58 =
(struct V_57 * ) V_113 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) ( V_58 -> V_7 -
F_12 ( struct V_57 , V_67 ) ) ;
F_23 ( V_18 , V_5 , V_58 -> V_67 . V_6 , V_120 , V_7 ,
V_113 -> V_9 , F_11 ( V_58 -> V_63 ) ) ;
}
void F_28 ( char * V_18 , struct V_121 * V_122 , struct V_19 * V_113 )
{
struct V_73 * V_21 =
(struct V_73 * ) V_122 -> V_123 -> V_124 -> V_125 [ 0 ] ;
struct V_4 * V_5 = V_21 -> V_5 ;
struct F_28 * V_30 = & V_5 -> V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
unsigned long V_32 ;
F_8 ( & V_5 -> V_131 , V_32 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
memcpy ( V_30 -> V_18 , V_18 , V_15 ) ;
V_30 -> V_34 = V_132 ;
V_30 -> V_133 = V_122 -> V_134 ;
V_30 -> V_135 = V_122 -> V_136 ;
V_30 -> V_137 = V_122 -> V_138 ;
V_30 -> V_139 = V_122 -> V_123 -> V_34 ;
V_30 -> V_140 = ( T_4 ) V_122 -> V_123 -> V_64 ;
V_30 -> V_141 = ( unsigned long ) V_122 -> V_141 ;
memcpy ( V_30 -> V_142 , V_122 -> V_143 ,
F_4 ( ( int ) V_122 -> V_144 , V_145 ) ) ;
if ( V_113 ) {
V_30 -> V_14 = V_113 -> V_9 ;
V_128 = (struct V_127 * )
& ( V_113 -> V_24 -> V_146 . V_147 . V_128 ) ;
memcpy ( & V_30 -> V_128 , V_128 , V_148 ) ;
if ( V_128 -> V_118 . V_149 & V_150 ) {
V_130 = (struct V_129 * ) & V_128 [ 1 ] ;
V_30 -> V_130 = V_130 -> V_151 ;
}
if ( V_128 -> V_118 . V_149 & V_152 ) {
V_30 -> V_53 = F_4 ( ( T_1 ) V_153 ,
( T_1 ) V_3 ) ;
F_2 ( V_5 , V_122 -> V_154 , V_30 -> V_53 ,
L_4 , V_113 -> V_9 ) ;
}
}
F_5 ( V_5 -> V_155 , 1 , V_30 , sizeof( * V_30 ) ) ;
F_9 ( & V_5 -> V_131 , V_32 ) ;
}
static T_5 * F_29 ( const char * V_156 , int V_157 , int V_158 )
{
struct V_159 * V_160 ;
V_160 = F_30 ( V_156 , V_157 , 1 , V_158 ) ;
if ( ! V_160 )
return NULL ;
F_31 ( V_160 , & V_161 ) ;
F_32 ( V_160 , V_162 ) ;
return V_160 ;
}
static void F_33 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_34 ( V_5 -> V_155 ) ;
F_34 ( V_5 -> V_112 ) ;
F_34 ( V_5 -> V_56 ) ;
F_34 ( V_5 -> V_16 ) ;
F_34 ( V_5 -> V_30 ) ;
F_35 ( V_5 ) ;
}
int F_36 ( struct V_73 * V_21 )
{
char V_156 [ V_163 ] ;
struct V_4 * V_5 ;
V_5 = F_37 ( sizeof( struct V_4 ) , V_164 ) ;
if ( ! V_5 )
return - V_165 ;
F_38 ( & V_5 -> V_13 ) ;
F_38 ( & V_5 -> V_33 ) ;
F_38 ( & V_5 -> V_110 ) ;
F_38 ( & V_5 -> V_131 ) ;
F_38 ( & V_5 -> V_91 ) ;
sprintf ( V_156 , L_5 , F_39 ( & V_21 -> V_166 -> V_167 ) ) ;
V_5 -> V_30 = F_29 ( V_156 , V_168 , sizeof( struct V_77 ) ) ;
if ( ! V_5 -> V_30 )
goto V_169;
sprintf ( V_156 , L_6 , F_39 ( & V_21 -> V_166 -> V_167 ) ) ;
V_5 -> V_56 = F_29 ( V_156 , V_168 , sizeof( struct V_29 ) ) ;
if ( ! V_5 -> V_56 )
goto V_169;
sprintf ( V_156 , L_7 , F_39 ( & V_21 -> V_166 -> V_167 ) ) ;
V_5 -> V_16 = F_29 ( V_156 , V_168 * 2 , sizeof( struct V_2 ) ) ;
if ( ! V_5 -> V_16 )
goto V_169;
sprintf ( V_156 , L_8 , F_39 ( & V_21 -> V_166 -> V_167 ) ) ;
V_5 -> V_112 = F_29 ( V_156 , V_168 , sizeof( struct F_23 ) ) ;
if ( ! V_5 -> V_112 )
goto V_169;
sprintf ( V_156 , L_9 , F_39 ( & V_21 -> V_166 -> V_167 ) ) ;
V_5 -> V_155 = F_29 ( V_156 , V_168 , sizeof( struct F_28 ) ) ;
if ( ! V_5 -> V_155 )
goto V_169;
V_21 -> V_5 = V_5 ;
return 0 ;
V_169:
F_33 ( V_5 ) ;
return - V_165 ;
}
void F_40 ( struct V_73 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
V_21 -> V_5 = NULL ;
F_33 ( V_5 ) ;
}
