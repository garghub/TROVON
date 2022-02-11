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
F_15 ( V_2 , 1 ) ;
F_4 ( V_7 , & V_24 ) ;
V_24 . V_33 = V_34 ;
V_25 = F_5 ( V_7 -> V_16 -> V_17 , & V_24 , V_35 ) ;
if ( V_25 )
F_6 ( V_19 L_7 , V_25 ) ;
V_25 = F_16 ( V_7 -> V_36 , V_2 -> V_37 ) ;
if ( V_25 )
F_6 ( V_38 L_8 ,
V_25 ) ;
if ( V_23 ) {
T_2 V_39 = F_17 ( & V_23 -> V_39 ) ;
if ( V_39 )
F_18 ( V_2 , F_19 ( V_39 ) ,
NULL ) ;
}
F_20 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_22 * V_23 ,
T_1 V_42 ,
T_1 V_43 ,
T_1 V_44 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_45 * V_36 = V_7 -> V_36 ;
memset ( V_41 , 0 , sizeof( struct V_40 ) ) ;
V_41 -> V_46 =
F_22 ( T_1 , V_36 -> V_43 , V_43 ) ;
V_41 -> V_47 =
F_22 ( T_1 , V_36 -> V_44 , V_44 ) ;
V_41 -> V_48 = F_22 (unsigned int, rds_ib_retry_count, 7 ) ;
V_41 -> V_49 = 7 ;
if ( V_23 ) {
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_50 = V_2 -> V_37 ;
V_23 -> V_51 = V_2 -> V_32 ;
V_23 -> V_29 = F_10 ( V_42 ) ;
V_23 -> V_30 = F_11 ( V_42 ) ;
V_23 -> V_52 = F_23 ( V_53 ) ;
V_23 -> V_39 = F_24 ( V_7 ) ;
if ( V_7 -> V_10 ) {
unsigned int V_5 ;
V_5 = F_25 ( F_26 ( & V_7 -> V_54 ) ) ;
V_23 -> V_31 = F_27 ( V_5 ) ;
F_28 ( F_29 ( V_5 ) , & V_7 -> V_54 ) ;
}
V_41 -> V_28 = V_23 ;
V_41 -> V_27 = sizeof( * V_23 ) ;
}
}
static void F_30 ( struct V_55 * V_21 , void * V_56 )
{
F_31 ( L_9 ,
V_21 -> V_21 , F_32 ( V_21 -> V_21 ) , V_56 ) ;
}
static void F_33 ( struct V_55 * V_21 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_31 ( L_10 , V_2 , V_7 , V_21 -> V_21 ,
F_32 ( V_21 -> V_21 ) ) ;
switch ( V_21 -> V_21 ) {
case V_57 :
F_34 ( V_7 -> V_16 , V_57 ) ;
break;
default:
F_31 ( L_11
L_12 ,
V_21 -> V_21 , F_32 ( V_21 -> V_21 ) ,
& V_2 -> V_37 , & V_2 -> V_32 ) ;
F_35 ( V_2 ) ;
break;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_58 * V_59 = V_7 -> V_16 -> V_60 ;
struct V_61 V_12 ;
struct V_62 V_63 = {} ;
struct V_45 * V_36 ;
int V_13 ;
V_36 = F_37 ( V_59 ) ;
if ( ! V_36 )
return - V_64 ;
F_38 ( V_36 , V_2 ) ;
if ( V_36 -> V_65 < V_7 -> V_66 . V_67 + 1 )
F_39 ( & V_7 -> V_66 , V_36 -> V_65 - 1 ) ;
if ( V_36 -> V_65 < V_7 -> V_68 . V_67 + 1 )
F_39 ( & V_7 -> V_68 , V_36 -> V_65 - 1 ) ;
V_7 -> V_69 = V_36 -> V_70 ;
V_7 -> V_71 = V_36 -> V_72 ;
V_63 . V_73 = V_7 -> V_66 . V_67 + 1 ;
V_7 -> V_74 = F_40 ( V_59 , V_75 ,
F_30 , V_2 ,
& V_63 ) ;
if ( F_41 ( V_7 -> V_74 ) ) {
V_13 = F_42 ( V_7 -> V_74 ) ;
V_7 -> V_74 = NULL ;
F_31 ( L_13 , V_13 ) ;
goto V_76;
}
V_63 . V_73 = V_7 -> V_68 . V_67 ;
V_7 -> V_77 = F_40 ( V_59 , V_78 ,
F_30 , V_2 ,
& V_63 ) ;
if ( F_41 ( V_7 -> V_77 ) ) {
V_13 = F_42 ( V_7 -> V_77 ) ;
V_7 -> V_77 = NULL ;
F_31 ( L_14 , V_13 ) ;
goto V_76;
}
V_13 = F_43 ( V_7 -> V_74 , V_79 ) ;
if ( V_13 ) {
F_31 ( L_15 , V_13 ) ;
goto V_76;
}
V_13 = F_43 ( V_7 -> V_77 , V_80 ) ;
if ( V_13 ) {
F_31 ( L_16 , V_13 ) ;
goto V_76;
}
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_81 = F_33 ;
V_12 . V_82 = V_2 ;
V_12 . V_83 . V_84 = V_7 -> V_66 . V_67 + 1 ;
V_12 . V_83 . V_85 = V_7 -> V_68 . V_67 + 1 ;
V_12 . V_83 . V_86 = V_36 -> V_87 ;
V_12 . V_83 . V_88 = V_89 ;
V_12 . V_90 = V_91 ;
V_12 . V_92 = V_93 ;
V_12 . V_94 = V_7 -> V_74 ;
V_12 . V_95 = V_7 -> V_77 ;
V_13 = F_44 ( V_7 -> V_16 , V_7 -> V_69 , & V_12 ) ;
if ( V_13 ) {
F_31 ( L_17 , V_13 ) ;
goto V_76;
}
V_7 -> V_96 = F_45 ( V_59 ,
V_7 -> V_66 . V_67 *
sizeof( struct V_97 ) ,
& V_7 -> V_98 , V_99 ) ;
if ( ! V_7 -> V_96 ) {
V_13 = - V_100 ;
F_31 ( L_18 ) ;
goto V_76;
}
V_7 -> V_101 = F_45 ( V_59 ,
V_7 -> V_68 . V_67 *
sizeof( struct V_97 ) ,
& V_7 -> V_102 , V_99 ) ;
if ( ! V_7 -> V_101 ) {
V_13 = - V_100 ;
F_31 ( L_19 ) ;
goto V_76;
}
V_7 -> V_103 = F_45 ( V_59 , sizeof( struct V_97 ) ,
& V_7 -> V_104 , V_99 ) ;
if ( ! V_7 -> V_103 ) {
V_13 = - V_100 ;
F_31 ( L_20 ) ;
goto V_76;
}
V_7 -> V_105 = F_46 ( V_7 -> V_66 . V_67 * sizeof( struct V_106 ) ,
F_47 ( V_59 ) ) ;
if ( ! V_7 -> V_105 ) {
V_13 = - V_100 ;
F_31 ( L_21 ) ;
goto V_76;
}
V_7 -> V_107 = F_46 ( V_7 -> V_68 . V_67 * sizeof( struct V_108 ) ,
F_47 ( V_59 ) ) ;
if ( ! V_7 -> V_107 ) {
V_13 = - V_100 ;
F_31 ( L_22 ) ;
goto V_76;
}
F_48 ( V_7 ) ;
F_31 ( L_23 , V_2 , V_7 -> V_69 , V_7 -> V_71 ,
V_7 -> V_74 , V_7 -> V_77 ) ;
V_76:
F_49 ( V_36 ) ;
return V_13 ;
}
static T_1 F_50 ( struct V_20 * V_21 )
{
const struct V_22 * V_23 = V_21 -> V_26 . V_2 . V_28 ;
T_3 V_109 ;
T_1 V_3 = 0 ;
if ( ! V_21 -> V_26 . V_2 . V_27 ) {
F_6 ( V_19 L_24
L_25 ) ;
return 0 ;
}
if ( V_21 -> V_26 . V_2 . V_27 < sizeof ( * V_23 ) ||
V_23 -> V_29 == 0 )
return V_110 ;
V_109 = F_51 ( V_23 -> V_52 ) & V_53 ;
if ( V_23 -> V_29 == 3 && V_109 ) {
V_3 = V_110 ;
while ( ( V_109 >>= 1 ) != 0 )
V_3 ++ ;
} else
F_52 ( V_19 L_26 ,
& V_23 -> V_50 ,
V_23 -> V_29 ,
V_23 -> V_30 ) ;
return V_3 ;
}
int F_53 ( struct V_111 * V_112 ,
struct V_20 * V_21 )
{
T_2 V_113 = V_112 -> V_114 . V_115 -> V_116 . V_117 . V_118 ;
T_2 V_119 = V_112 -> V_114 . V_115 -> V_120 . V_117 . V_118 ;
const struct V_22 * V_23 = V_21 -> V_26 . V_2 . V_28 ;
struct V_22 V_121 ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_40 V_41 ;
T_1 V_3 ;
int V_25 = 1 , V_122 = 1 ;
V_3 = F_50 ( V_21 ) ;
if ( ! V_3 )
goto V_76;
F_31 ( L_27
L_28 , & V_23 -> V_50 , & V_23 -> V_51 ,
F_10 ( V_3 ) , F_11 ( V_3 ) ,
( unsigned long long ) F_19 ( V_113 ) ,
( unsigned long long ) F_19 ( V_119 ) ) ;
V_2 = F_54 ( V_23 -> V_51 , V_23 -> V_50 , & V_123 ,
V_99 ) ;
if ( F_41 ( V_2 ) ) {
F_31 ( L_29 , F_42 ( V_2 ) ) ;
V_2 = NULL ;
goto V_76;
}
F_55 ( & V_2 -> V_124 ) ;
if ( ! F_56 ( V_2 , V_125 , V_126 ) ) {
if ( F_57 ( V_2 ) == V_127 ) {
F_31 ( L_30 ) ;
F_35 ( V_2 ) ;
F_58 ( V_128 ) ;
} else
if ( F_57 ( V_2 ) == V_126 ) {
F_58 ( V_129 ) ;
}
goto V_76;
}
V_7 = V_2 -> V_8 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( V_2 , F_9 ( V_23 -> V_31 ) ) ;
if ( V_23 -> V_39 )
F_18 ( V_2 , F_19 ( V_23 -> V_39 ) , NULL ) ;
F_59 ( V_112 -> V_130 ) ;
F_59 ( V_7 -> V_16 ) ;
V_7 -> V_16 = V_112 ;
V_112 -> V_130 = V_2 ;
V_122 = 0 ;
V_25 = F_36 ( V_2 ) ;
if ( V_25 ) {
F_60 ( V_2 , L_31 , V_25 ) ;
goto V_76;
}
F_21 ( V_2 , & V_41 , & V_121 , V_3 ,
V_21 -> V_26 . V_2 . V_46 ,
V_21 -> V_26 . V_2 . V_47 ) ;
V_25 = F_61 ( V_112 , & V_41 ) ;
if ( V_25 )
F_60 ( V_2 , L_32 , V_25 ) ;
V_76:
if ( V_2 )
F_62 ( & V_2 -> V_124 ) ;
if ( V_25 )
F_63 ( V_112 , NULL , 0 ) ;
return V_122 ;
}
int F_64 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = V_112 -> V_130 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_40 V_41 ;
struct V_22 V_23 ;
int V_13 ;
F_1 ( V_2 , V_110 ) ;
V_7 -> V_10 = V_9 ;
V_13 = F_36 ( V_2 ) ;
if ( V_13 ) {
F_60 ( V_2 , L_31 , V_13 ) ;
goto V_76;
}
F_21 ( V_2 , & V_41 , & V_23 , V_131 ,
V_132 , V_132 ) ;
V_13 = F_65 ( V_112 , & V_41 ) ;
if ( V_13 )
F_60 ( V_2 , L_33 , V_13 ) ;
V_76:
if ( V_13 ) {
if ( V_7 -> V_16 == V_112 )
V_13 = 0 ;
}
return V_13 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_133 V_134 , V_135 ;
int V_13 ;
V_7 -> V_16 = F_67 ( V_136 , V_2 ,
V_137 , V_93 ) ;
if ( F_41 ( V_7 -> V_16 ) ) {
V_13 = F_42 ( V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
F_31 ( L_34 , V_13 ) ;
goto V_76;
}
F_31 ( L_35 , V_7 -> V_16 , V_2 ) ;
V_134 . V_138 = V_139 ;
V_134 . V_140 . V_141 = ( V_142 T_1 ) V_2 -> V_37 ;
V_134 . V_143 = ( V_142 T_3 ) F_68 ( 0 ) ;
V_135 . V_138 = V_139 ;
V_135 . V_140 . V_141 = ( V_142 T_1 ) V_2 -> V_32 ;
V_135 . V_143 = ( V_142 T_3 ) F_68 ( V_144 ) ;
V_13 = F_69 ( V_7 -> V_16 , (struct V_145 * ) & V_134 ,
(struct V_145 * ) & V_135 ,
V_146 ) ;
if ( V_13 ) {
F_31 ( L_36 , V_7 -> V_16 ,
V_13 ) ;
F_70 ( V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
}
V_76:
return V_13 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_25 = 0 ;
F_31 ( L_37 , V_7 -> V_16 ,
V_7 -> V_69 , V_7 -> V_74 , V_7 -> V_77 ,
V_7 -> V_16 ? V_7 -> V_16 -> V_17 : NULL ) ;
if ( V_7 -> V_16 ) {
struct V_58 * V_59 = V_7 -> V_16 -> V_60 ;
F_31 ( L_38 , V_7 -> V_16 ) ;
V_25 = F_72 ( V_7 -> V_16 ) ;
if ( V_25 ) {
F_31 ( L_39 ,
V_7 -> V_16 , V_25 ) ;
}
F_73 ( V_147 ,
F_74 ( & V_7 -> V_68 ) &&
( F_26 ( & V_7 -> V_148 ) == 0 ) ) ;
F_75 ( & V_7 -> V_149 ) ;
if ( V_7 -> V_96 )
F_76 ( V_59 ,
V_7 -> V_66 . V_67 *
sizeof( struct V_97 ) ,
V_7 -> V_96 ,
V_7 -> V_98 ) ;
if ( V_7 -> V_101 )
F_76 ( V_59 ,
V_7 -> V_68 . V_67 *
sizeof( struct V_97 ) ,
V_7 -> V_101 ,
V_7 -> V_102 ) ;
if ( V_7 -> V_103 )
F_76 ( V_59 , sizeof( struct V_97 ) ,
V_7 -> V_103 , V_7 -> V_104 ) ;
if ( V_7 -> V_105 )
F_77 ( V_7 ) ;
if ( V_7 -> V_107 )
F_78 ( V_7 ) ;
if ( V_7 -> V_16 -> V_17 )
F_79 ( V_7 -> V_16 ) ;
if ( V_7 -> V_74 )
F_80 ( V_7 -> V_74 ) ;
if ( V_7 -> V_77 )
F_80 ( V_7 -> V_77 ) ;
F_70 ( V_7 -> V_16 ) ;
if ( V_7 -> V_36 )
F_81 ( V_7 -> V_36 , V_2 ) ;
V_7 -> V_16 = NULL ;
V_7 -> V_69 = NULL ;
V_7 -> V_71 = NULL ;
V_7 -> V_74 = NULL ;
V_7 -> V_77 = NULL ;
V_7 -> V_96 = NULL ;
V_7 -> V_101 = NULL ;
V_7 -> V_103 = NULL ;
}
F_59 ( V_7 -> V_36 ) ;
if ( V_7 -> V_150 ) {
struct V_151 * V_152 ;
V_152 = F_82 ( V_7 -> V_150 , struct V_151 , V_56 ) ;
F_83 ( V_152 ) ;
V_7 -> V_150 = NULL ;
}
F_84 ( V_153 , & V_7 -> V_154 ) ;
#ifdef F_85
F_86 ( & V_7 -> V_155 , 0 ) ;
#else
V_7 -> V_155 = 0 ;
#endif
V_7 -> V_156 = 0 ;
V_7 -> V_10 = 0 ;
F_87 ( & V_7 -> V_54 , 0 ) ;
F_88 ( & V_7 -> V_66 , V_157 ) ;
F_88 ( & V_7 -> V_68 , V_158 ) ;
if ( V_7 -> V_159 ) {
F_89 ( & V_7 -> V_159 -> V_160 ) ;
V_7 -> V_159 = NULL ;
}
F_90 ( V_7 -> V_105 ) ;
V_7 -> V_105 = NULL ;
F_90 ( V_7 -> V_107 ) ;
V_7 -> V_107 = NULL ;
}
int F_91 ( struct V_1 * V_2 , T_4 V_161 )
{
struct V_6 * V_7 ;
unsigned long V_162 ;
int V_13 ;
V_7 = F_92 ( sizeof( struct V_6 ) , V_161 ) ;
if ( ! V_7 )
return - V_100 ;
V_13 = F_93 ( V_7 ) ;
if ( V_13 ) {
F_94 ( V_7 ) ;
return V_13 ;
}
F_95 ( & V_7 -> V_163 ) ;
F_96 ( & V_7 -> V_149 , V_164 ,
( unsigned long ) V_7 ) ;
F_97 ( & V_7 -> V_165 ) ;
#ifndef F_85
F_98 ( & V_7 -> V_166 ) ;
#endif
F_87 ( & V_7 -> V_148 , 0 ) ;
F_88 ( & V_7 -> V_66 , V_157 ) ;
F_88 ( & V_7 -> V_68 , V_158 ) ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 = V_7 ;
F_99 ( & V_167 , V_162 ) ;
F_100 ( & V_7 -> V_163 , & V_168 ) ;
F_101 ( & V_167 , V_162 ) ;
F_31 ( L_40 , V_2 , V_2 -> V_8 ) ;
return 0 ;
}
void F_102 ( void * V_169 )
{
struct V_6 * V_7 = V_169 ;
T_5 * V_170 ;
F_31 ( L_41 , V_7 ) ;
V_170 = V_7 -> V_36 ? & V_7 -> V_36 -> V_171 : & V_167 ;
F_103 ( V_170 ) ;
F_104 ( & V_7 -> V_163 ) ;
F_105 ( V_170 ) ;
F_106 ( V_7 ) ;
F_94 ( V_7 ) ;
}
void
F_107 ( struct V_1 * V_2 , const char * V_172 , ... )
{
T_6 V_173 ;
F_35 ( V_2 ) ;
va_start ( V_173 , V_172 ) ;
F_108 ( V_172 , V_173 ) ;
va_end ( V_173 ) ;
}
