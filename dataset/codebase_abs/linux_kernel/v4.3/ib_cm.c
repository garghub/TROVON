static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
V_2 -> V_4 = V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_9 && V_5 != 0 ) {
V_7 -> V_10 = 1 ;
F_3 ( V_2 , V_5 ) ;
} else {
V_7 -> V_10 = 0 ;
}
}
static void
F_4 ( struct V_6 * V_7 , struct V_11 * V_12 )
{
int V_13 ;
V_12 -> V_14 = V_15 ;
V_13 = F_5 ( V_7 -> V_16 -> V_17 , V_12 , V_18 ) ;
if ( V_13 )
F_6 ( V_19 L_1 , - V_13 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
const struct V_22 * V_23 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_11 V_24 ;
int V_25 ;
if ( V_21 -> V_26 . V_2 . V_27 >= sizeof( * V_23 ) ) {
V_23 = V_21 -> V_26 . V_2 . V_28 ;
if ( V_23 -> V_29 ) {
F_1 ( V_2 ,
F_8 ( V_23 -> V_29 ,
V_23 -> V_30 ) ) ;
F_2 ( V_2 , F_9 ( V_23 -> V_31 ) ) ;
}
}
if ( V_2 -> V_4 < F_8 ( 3 , 1 ) ) {
F_6 ( V_19 L_2
L_3 ,
& V_2 -> V_32 ,
F_10 ( V_2 -> V_4 ) ,
F_11 ( V_2 -> V_4 ) ) ;
F_12 ( V_2 ) ;
return;
} else {
F_6 ( V_19 L_4 ,
& V_2 -> V_32 ,
F_10 ( V_2 -> V_4 ) ,
F_11 ( V_2 -> V_4 ) ,
V_7 -> V_10 ? L_5 : L_6 ) ;
}
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
F_15 ( V_2 , 1 , V_33 ) ;
F_4 ( V_7 , & V_24 ) ;
V_24 . V_34 = V_35 ;
V_25 = F_5 ( V_7 -> V_16 -> V_17 , & V_24 , V_36 ) ;
if ( V_25 )
F_6 ( V_19 L_7 , V_25 ) ;
V_25 = F_16 ( V_7 -> V_37 , V_2 -> V_38 ) ;
if ( V_25 )
F_6 ( V_39 L_8 ,
V_25 ) ;
if ( V_23 ) {
T_2 V_40 = F_17 ( & V_23 -> V_40 ) ;
if ( V_40 )
F_18 ( V_2 , F_19 ( V_40 ) ,
NULL ) ;
}
F_20 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_22 * V_23 ,
T_1 V_43 ,
T_1 V_44 ,
T_1 V_45 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_46 * V_37 = V_7 -> V_37 ;
memset ( V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 -> V_47 =
F_22 ( T_1 , V_37 -> V_44 , V_44 ) ;
V_42 -> V_48 =
F_22 ( T_1 , V_37 -> V_45 , V_45 ) ;
V_42 -> V_49 = F_22 (unsigned int, rds_ib_retry_count, 7 ) ;
V_42 -> V_50 = 7 ;
if ( V_23 ) {
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_51 = V_2 -> V_38 ;
V_23 -> V_52 = V_2 -> V_32 ;
V_23 -> V_29 = F_10 ( V_43 ) ;
V_23 -> V_30 = F_11 ( V_43 ) ;
V_23 -> V_53 = F_23 ( V_54 ) ;
V_23 -> V_40 = F_24 ( V_7 ) ;
if ( V_7 -> V_10 ) {
unsigned int V_5 ;
V_5 = F_25 ( F_26 ( & V_7 -> V_55 ) ) ;
V_23 -> V_31 = F_27 ( V_5 ) ;
F_28 ( F_29 ( V_5 ) , & V_7 -> V_55 ) ;
}
V_42 -> V_28 = V_23 ;
V_42 -> V_27 = sizeof( * V_23 ) ;
}
}
static void F_30 ( struct V_56 * V_21 , void * V_57 )
{
F_31 ( L_9 ,
V_21 -> V_21 , F_32 ( V_21 -> V_21 ) , V_57 ) ;
}
static void F_33 ( struct V_56 * V_21 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_31 ( L_10 , V_2 , V_7 , V_21 -> V_21 ,
F_32 ( V_21 -> V_21 ) ) ;
switch ( V_21 -> V_21 ) {
case V_58 :
F_34 ( V_7 -> V_16 , V_58 ) ;
break;
default:
F_31 ( L_11
L_12 ,
V_21 -> V_21 , F_32 ( V_21 -> V_21 ) ,
& V_2 -> V_38 , & V_2 -> V_32 ) ;
F_35 ( V_2 ) ;
break;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_59 * V_60 = V_7 -> V_16 -> V_61 ;
struct V_62 V_12 ;
struct V_63 V_64 = {} ;
struct V_46 * V_37 ;
int V_13 ;
V_37 = F_37 ( V_60 ) ;
if ( ! V_37 )
return - V_65 ;
F_38 ( V_37 , V_2 ) ;
if ( V_37 -> V_66 < V_7 -> V_67 . V_68 + 1 )
F_39 ( & V_7 -> V_67 , V_37 -> V_66 - 1 ) ;
if ( V_37 -> V_66 < V_7 -> V_69 . V_68 + 1 )
F_39 ( & V_7 -> V_69 , V_37 -> V_66 - 1 ) ;
V_7 -> V_70 = V_37 -> V_71 ;
V_64 . V_72 = V_7 -> V_67 . V_68 + 1 ;
V_7 -> V_73 = F_40 ( V_60 , V_74 ,
F_30 , V_2 ,
& V_64 ) ;
if ( F_41 ( V_7 -> V_73 ) ) {
V_13 = F_42 ( V_7 -> V_73 ) ;
V_7 -> V_73 = NULL ;
F_31 ( L_13 , V_13 ) ;
goto V_75;
}
V_64 . V_72 = V_7 -> V_69 . V_68 ;
V_7 -> V_76 = F_40 ( V_60 , V_77 ,
F_30 , V_2 ,
& V_64 ) ;
if ( F_41 ( V_7 -> V_76 ) ) {
V_13 = F_42 ( V_7 -> V_76 ) ;
V_7 -> V_76 = NULL ;
F_31 ( L_14 , V_13 ) ;
goto V_75;
}
V_13 = F_43 ( V_7 -> V_73 , V_78 ) ;
if ( V_13 ) {
F_31 ( L_15 , V_13 ) ;
goto V_75;
}
V_13 = F_43 ( V_7 -> V_76 , V_79 ) ;
if ( V_13 ) {
F_31 ( L_16 , V_13 ) ;
goto V_75;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_80 = F_33 ;
V_12 . V_81 = V_2 ;
V_12 . V_82 . V_83 = V_7 -> V_67 . V_68 + 1 ;
V_12 . V_82 . V_84 = V_7 -> V_69 . V_68 + 1 ;
V_12 . V_82 . V_85 = V_37 -> V_86 ;
V_12 . V_82 . V_87 = V_88 ;
V_12 . V_89 = V_90 ;
V_12 . V_91 = V_92 ;
V_12 . V_93 = V_7 -> V_73 ;
V_12 . V_94 = V_7 -> V_76 ;
V_13 = F_44 ( V_7 -> V_16 , V_7 -> V_70 , & V_12 ) ;
if ( V_13 ) {
F_31 ( L_17 , V_13 ) ;
goto V_75;
}
V_7 -> V_95 = F_45 ( V_60 ,
V_7 -> V_67 . V_68 *
sizeof( struct V_96 ) ,
& V_7 -> V_97 , V_33 ) ;
if ( ! V_7 -> V_95 ) {
V_13 = - V_98 ;
F_31 ( L_18 ) ;
goto V_75;
}
V_7 -> V_99 = F_45 ( V_60 ,
V_7 -> V_69 . V_68 *
sizeof( struct V_96 ) ,
& V_7 -> V_100 , V_33 ) ;
if ( ! V_7 -> V_99 ) {
V_13 = - V_98 ;
F_31 ( L_19 ) ;
goto V_75;
}
V_7 -> V_101 = F_45 ( V_60 , sizeof( struct V_96 ) ,
& V_7 -> V_102 , V_33 ) ;
if ( ! V_7 -> V_101 ) {
V_13 = - V_98 ;
F_31 ( L_20 ) ;
goto V_75;
}
V_7 -> V_103 = F_46 ( V_7 -> V_67 . V_68 * sizeof( struct V_104 ) ,
F_47 ( V_60 ) ) ;
if ( ! V_7 -> V_103 ) {
V_13 = - V_98 ;
F_31 ( L_21 ) ;
goto V_75;
}
V_7 -> V_105 = F_46 ( V_7 -> V_69 . V_68 * sizeof( struct V_106 ) ,
F_47 ( V_60 ) ) ;
if ( ! V_7 -> V_105 ) {
V_13 = - V_98 ;
F_31 ( L_22 ) ;
goto V_75;
}
F_48 ( V_7 ) ;
F_31 ( L_23 , V_2 , V_7 -> V_70 ,
V_7 -> V_73 , V_7 -> V_76 ) ;
V_75:
F_49 ( V_37 ) ;
return V_13 ;
}
static T_1 F_50 ( struct V_20 * V_21 )
{
const struct V_22 * V_23 = V_21 -> V_26 . V_2 . V_28 ;
T_3 V_107 ;
T_1 V_3 = 0 ;
if ( ! V_21 -> V_26 . V_2 . V_27 ) {
F_6 ( V_19 L_24
L_25 ) ;
return 0 ;
}
if ( V_21 -> V_26 . V_2 . V_27 < sizeof ( * V_23 ) ||
V_23 -> V_29 == 0 )
return V_108 ;
V_107 = F_51 ( V_23 -> V_53 ) & V_54 ;
if ( V_23 -> V_29 == 3 && V_107 ) {
V_3 = V_108 ;
while ( ( V_107 >>= 1 ) != 0 )
V_3 ++ ;
} else
F_52 ( V_19 L_26 ,
& V_23 -> V_51 ,
V_23 -> V_29 ,
V_23 -> V_30 ) ;
return V_3 ;
}
int F_53 ( struct V_109 * V_110 ,
struct V_20 * V_21 )
{
T_2 V_111 = V_110 -> V_112 . V_113 -> V_114 . V_115 . V_116 ;
T_2 V_117 = V_110 -> V_112 . V_113 -> V_118 . V_115 . V_116 ;
const struct V_22 * V_23 = V_21 -> V_26 . V_2 . V_28 ;
struct V_22 V_119 ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_41 V_42 ;
T_1 V_3 ;
int V_25 = 1 , V_120 = 1 ;
V_3 = F_50 ( V_21 ) ;
if ( ! V_3 )
goto V_75;
F_31 ( L_27
L_28 , & V_23 -> V_51 , & V_23 -> V_52 ,
F_10 ( V_3 ) , F_11 ( V_3 ) ,
( unsigned long long ) F_19 ( V_111 ) ,
( unsigned long long ) F_19 ( V_117 ) ) ;
V_2 = F_54 ( & V_121 , V_23 -> V_52 , V_23 -> V_51 ,
& V_122 , V_33 ) ;
if ( F_41 ( V_2 ) ) {
F_31 ( L_29 , F_42 ( V_2 ) ) ;
V_2 = NULL ;
goto V_75;
}
F_55 ( & V_2 -> V_123 ) ;
if ( ! F_56 ( V_2 , V_124 , V_125 ) ) {
if ( F_57 ( V_2 ) == V_126 ) {
F_31 ( L_30 ) ;
F_35 ( V_2 ) ;
F_58 ( V_127 ) ;
} else
if ( F_57 ( V_2 ) == V_125 ) {
F_58 ( V_128 ) ;
}
goto V_75;
}
V_7 = V_2 -> V_8 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( V_2 , F_9 ( V_23 -> V_31 ) ) ;
if ( V_23 -> V_40 )
F_18 ( V_2 , F_19 ( V_23 -> V_40 ) , NULL ) ;
F_59 ( V_110 -> V_129 ) ;
F_59 ( V_7 -> V_16 ) ;
V_7 -> V_16 = V_110 ;
V_110 -> V_129 = V_2 ;
V_120 = 0 ;
V_25 = F_36 ( V_2 ) ;
if ( V_25 ) {
F_60 ( V_2 , L_31 , V_25 ) ;
goto V_75;
}
F_21 ( V_2 , & V_42 , & V_119 , V_3 ,
V_21 -> V_26 . V_2 . V_47 ,
V_21 -> V_26 . V_2 . V_48 ) ;
V_25 = F_61 ( V_110 , & V_42 ) ;
if ( V_25 )
F_60 ( V_2 , L_32 , V_25 ) ;
V_75:
if ( V_2 )
F_62 ( & V_2 -> V_123 ) ;
if ( V_25 )
F_63 ( V_110 , NULL , 0 ) ;
return V_120 ;
}
int F_64 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_129 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_41 V_42 ;
struct V_22 V_23 ;
int V_13 ;
F_1 ( V_2 , V_108 ) ;
V_7 -> V_10 = V_9 ;
V_13 = F_36 ( V_2 ) ;
if ( V_13 ) {
F_60 ( V_2 , L_31 , V_13 ) ;
goto V_75;
}
F_21 ( V_2 , & V_42 , & V_23 , V_130 ,
V_131 , V_131 ) ;
V_13 = F_65 ( V_110 , & V_42 ) ;
if ( V_13 )
F_60 ( V_2 , L_33 , V_13 ) ;
V_75:
if ( V_13 ) {
if ( V_7 -> V_16 == V_110 )
V_13 = 0 ;
}
return V_13 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_132 V_133 , V_134 ;
int V_13 ;
V_7 -> V_16 = F_67 ( V_135 , V_2 ,
V_136 , V_92 ) ;
if ( F_41 ( V_7 -> V_16 ) ) {
V_13 = F_42 ( V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
F_31 ( L_34 , V_13 ) ;
goto V_75;
}
F_31 ( L_35 , V_7 -> V_16 , V_2 ) ;
V_133 . V_137 = V_138 ;
V_133 . V_139 . V_140 = ( V_141 T_1 ) V_2 -> V_38 ;
V_133 . V_142 = ( V_141 T_3 ) F_68 ( 0 ) ;
V_134 . V_137 = V_138 ;
V_134 . V_139 . V_140 = ( V_141 T_1 ) V_2 -> V_32 ;
V_134 . V_142 = ( V_141 T_3 ) F_68 ( V_143 ) ;
V_13 = F_69 ( V_7 -> V_16 , (struct V_144 * ) & V_133 ,
(struct V_144 * ) & V_134 ,
V_145 ) ;
if ( V_13 ) {
F_31 ( L_36 , V_7 -> V_16 ,
V_13 ) ;
F_70 ( V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
}
V_75:
return V_13 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_25 = 0 ;
F_31 ( L_37 , V_7 -> V_16 ,
V_7 -> V_70 , V_7 -> V_73 , V_7 -> V_76 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : NULL ) ;
if ( V_7 -> V_16 ) {
struct V_59 * V_60 = V_7 -> V_16 -> V_61 ;
F_31 ( L_38 , V_7 -> V_16 ) ;
V_25 = F_72 ( V_7 -> V_16 ) ;
if ( V_25 ) {
F_31 ( L_39 ,
V_7 -> V_16 , V_25 ) ;
}
F_73 ( V_146 ,
F_74 ( & V_7 -> V_69 ) &&
( F_26 ( & V_7 -> V_147 ) == 0 ) ) ;
F_75 ( & V_7 -> V_148 ) ;
if ( V_7 -> V_16 -> V_17 )
F_76 ( V_7 -> V_16 ) ;
if ( V_7 -> V_73 )
F_77 ( V_7 -> V_73 ) ;
if ( V_7 -> V_76 )
F_77 ( V_7 -> V_76 ) ;
if ( V_7 -> V_95 )
F_78 ( V_60 ,
V_7 -> V_67 . V_68 *
sizeof( struct V_96 ) ,
V_7 -> V_95 ,
V_7 -> V_97 ) ;
if ( V_7 -> V_99 )
F_78 ( V_60 ,
V_7 -> V_69 . V_68 *
sizeof( struct V_96 ) ,
V_7 -> V_99 ,
V_7 -> V_100 ) ;
if ( V_7 -> V_101 )
F_78 ( V_60 , sizeof( struct V_96 ) ,
V_7 -> V_101 , V_7 -> V_102 ) ;
if ( V_7 -> V_103 )
F_79 ( V_7 ) ;
if ( V_7 -> V_105 )
F_80 ( V_7 ) ;
F_70 ( V_7 -> V_16 ) ;
if ( V_7 -> V_37 )
F_81 ( V_7 -> V_37 , V_2 ) ;
V_7 -> V_16 = NULL ;
V_7 -> V_70 = NULL ;
V_7 -> V_73 = NULL ;
V_7 -> V_76 = NULL ;
V_7 -> V_95 = NULL ;
V_7 -> V_99 = NULL ;
V_7 -> V_101 = NULL ;
}
F_59 ( V_7 -> V_37 ) ;
if ( V_7 -> V_149 ) {
struct V_150 * V_151 ;
V_151 = F_82 ( V_7 -> V_149 , struct V_150 , V_57 ) ;
F_83 ( V_151 ) ;
V_7 -> V_149 = NULL ;
}
F_84 ( V_152 , & V_7 -> V_153 ) ;
#ifdef F_85
F_86 ( & V_7 -> V_154 , 0 ) ;
#else
V_7 -> V_154 = 0 ;
#endif
V_7 -> V_155 = 0 ;
V_7 -> V_10 = 0 ;
F_87 ( & V_7 -> V_55 , 0 ) ;
F_88 ( & V_7 -> V_67 , V_156 ) ;
F_88 ( & V_7 -> V_69 , V_157 ) ;
if ( V_7 -> V_158 ) {
F_89 ( & V_7 -> V_158 -> V_159 ) ;
V_7 -> V_158 = NULL ;
}
F_90 ( V_7 -> V_103 ) ;
V_7 -> V_103 = NULL ;
F_90 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
}
int F_91 ( struct V_1 * V_2 , T_4 V_160 )
{
struct V_6 * V_7 ;
unsigned long V_161 ;
int V_13 ;
V_7 = F_92 ( sizeof( struct V_6 ) , V_160 ) ;
if ( ! V_7 )
return - V_98 ;
V_13 = F_93 ( V_7 ) ;
if ( V_13 ) {
F_94 ( V_7 ) ;
return V_13 ;
}
F_95 ( & V_7 -> V_162 ) ;
F_96 ( & V_7 -> V_148 , V_163 ,
( unsigned long ) V_7 ) ;
F_97 ( & V_7 -> V_164 ) ;
#ifndef F_85
F_98 ( & V_7 -> V_165 ) ;
#endif
F_87 ( & V_7 -> V_147 , 0 ) ;
F_88 ( & V_7 -> V_67 , V_156 ) ;
F_88 ( & V_7 -> V_69 , V_157 ) ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 = V_7 ;
F_99 ( & V_166 , V_161 ) ;
F_100 ( & V_7 -> V_162 , & V_167 ) ;
F_101 ( & V_166 , V_161 ) ;
F_31 ( L_40 , V_2 , V_2 -> V_8 ) ;
return 0 ;
}
void F_102 ( void * V_168 )
{
struct V_6 * V_7 = V_168 ;
T_5 * V_169 ;
F_31 ( L_41 , V_7 ) ;
V_169 = V_7 -> V_37 ? & V_7 -> V_37 -> V_170 : & V_166 ;
F_103 ( V_169 ) ;
F_104 ( & V_7 -> V_162 ) ;
F_105 ( V_169 ) ;
F_106 ( V_7 ) ;
F_94 ( V_7 ) ;
}
void
F_107 ( struct V_1 * V_2 , const char * V_171 , ... )
{
T_6 V_172 ;
F_35 ( V_2 ) ;
va_start ( V_172 , V_171 ) ;
F_108 ( V_171 , V_172 ) ;
va_end ( V_172 ) ;
}
