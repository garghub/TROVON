static char * F_1 ( enum V_1 type )
{
return F_2 ( V_2 ,
F_3 ( V_2 ) , type ) ;
}
static void F_4 ( struct V_3 * V_4 , unsigned int V_5 )
{
V_4 -> V_6 = V_5 ;
}
static void F_5 ( struct V_3 * V_4 , T_1 V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
if ( V_11 && V_7 != 0 ) {
V_9 -> V_12 = 1 ;
F_6 ( V_4 , V_7 ) ;
} else {
V_9 -> V_12 = 0 ;
}
}
static void
F_7 ( struct V_8 * V_9 , struct V_13 * V_14 )
{
int V_15 ;
V_14 -> V_16 = V_17 ;
V_15 = F_8 ( V_9 -> V_18 -> V_19 , V_14 , V_20 ) ;
if ( V_15 )
F_9 ( V_21 L_1 , - V_15 ) ;
}
void F_10 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
const struct V_24 * V_25 = NULL ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_13 V_26 ;
int V_27 ;
if ( V_23 -> V_28 . V_4 . V_29 >= sizeof( * V_25 ) ) {
V_25 = V_23 -> V_28 . V_4 . V_30 ;
if ( V_25 -> V_31 ) {
F_4 ( V_4 ,
F_11 ( V_25 -> V_31 ,
V_25 -> V_32 ) ) ;
F_5 ( V_4 , F_12 ( V_25 -> V_33 ) ) ;
}
}
if ( V_4 -> V_6 < F_11 ( 3 , 1 ) ) {
F_9 ( V_21 L_2
L_3 ,
& V_4 -> V_34 ,
F_13 ( V_4 -> V_6 ) ,
F_14 ( V_4 -> V_6 ) ) ;
F_15 ( V_4 ) ;
return;
} else {
F_9 ( V_21 L_4 ,
& V_4 -> V_34 ,
F_13 ( V_4 -> V_6 ) ,
F_14 ( V_4 -> V_6 ) ,
V_9 -> V_12 ? L_5 : L_6 ) ;
}
F_16 ( V_9 ) ;
F_17 ( V_9 ) ;
F_18 ( V_4 , 1 ) ;
F_7 ( V_9 , & V_26 ) ;
V_26 . V_35 = V_36 ;
V_27 = F_8 ( V_9 -> V_18 -> V_19 , & V_26 , V_37 ) ;
if ( V_27 )
F_9 ( V_21 L_7 , V_27 ) ;
V_27 = F_19 ( V_9 -> V_38 , V_4 -> V_39 ) ;
if ( V_27 )
F_9 ( V_40 L_8 ,
V_27 ) ;
if ( V_25 && V_25 -> V_41 )
F_20 ( V_4 , F_21 ( V_25 -> V_41 ) , NULL ) ;
F_22 ( V_4 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_42 * V_43 ,
struct V_24 * V_25 ,
T_1 V_44 ,
T_1 V_45 ,
T_1 V_46 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_47 * V_38 = V_9 -> V_38 ;
memset ( V_43 , 0 , sizeof( struct V_42 ) ) ;
V_43 -> V_48 =
F_24 ( T_1 , V_38 -> V_45 , V_45 ) ;
V_43 -> V_49 =
F_24 ( T_1 , V_38 -> V_46 , V_46 ) ;
V_43 -> V_50 = F_24 (unsigned int, rds_ib_retry_count, 7 ) ;
V_43 -> V_51 = 7 ;
if ( V_25 ) {
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_52 = V_4 -> V_39 ;
V_25 -> V_53 = V_4 -> V_34 ;
V_25 -> V_31 = F_13 ( V_44 ) ;
V_25 -> V_32 = F_14 ( V_44 ) ;
V_25 -> V_54 = F_25 ( V_55 ) ;
V_25 -> V_41 = F_26 ( V_9 ) ;
if ( V_9 -> V_12 ) {
unsigned int V_7 ;
V_7 = F_27 ( F_28 ( & V_9 -> V_56 ) ) ;
V_25 -> V_33 = F_29 ( V_7 ) ;
F_30 ( F_31 ( V_7 ) , & V_9 -> V_56 ) ;
}
V_43 -> V_30 = V_25 ;
V_43 -> V_29 = sizeof( * V_25 ) ;
}
}
static void F_32 ( struct V_57 * V_23 , void * V_58 )
{
F_33 ( L_9 ,
V_23 -> V_23 , F_1 ( V_23 -> V_23 ) , V_58 ) ;
}
static void F_34 ( struct V_57 * V_23 , void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_8 * V_9 = V_4 -> V_10 ;
F_33 ( L_10 , V_4 , V_9 , V_23 -> V_23 ,
F_1 ( V_23 -> V_23 ) ) ;
switch ( V_23 -> V_23 ) {
case V_59 :
F_35 ( V_9 -> V_18 , V_59 ) ;
break;
default:
F_33 ( L_11
L_12 ,
V_23 -> V_23 , F_1 ( V_23 -> V_23 ) ,
& V_4 -> V_39 , & V_4 -> V_34 ) ;
F_36 ( V_4 ) ;
break;
}
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_60 * V_61 = V_9 -> V_18 -> V_62 ;
struct V_63 V_14 ;
struct V_47 * V_38 ;
int V_15 ;
V_38 = F_38 ( V_61 ) ;
if ( ! V_38 )
return - V_64 ;
F_39 ( V_38 , V_4 ) ;
if ( V_38 -> V_65 < V_9 -> V_66 . V_67 + 1 )
F_40 ( & V_9 -> V_66 , V_38 -> V_65 - 1 ) ;
if ( V_38 -> V_65 < V_9 -> V_68 . V_67 + 1 )
F_40 ( & V_9 -> V_68 , V_38 -> V_65 - 1 ) ;
V_9 -> V_69 = V_38 -> V_70 ;
V_9 -> V_71 = V_38 -> V_72 ;
V_9 -> V_73 = F_41 ( V_61 , V_74 ,
F_32 , V_4 ,
V_9 -> V_66 . V_67 + 1 , 0 ) ;
if ( F_42 ( V_9 -> V_73 ) ) {
V_15 = F_43 ( V_9 -> V_73 ) ;
V_9 -> V_73 = NULL ;
F_33 ( L_13 , V_15 ) ;
goto V_75;
}
V_9 -> V_76 = F_41 ( V_61 , V_77 ,
F_32 , V_4 ,
V_9 -> V_68 . V_67 , 0 ) ;
if ( F_42 ( V_9 -> V_76 ) ) {
V_15 = F_43 ( V_9 -> V_76 ) ;
V_9 -> V_76 = NULL ;
F_33 ( L_14 , V_15 ) ;
goto V_75;
}
V_15 = F_44 ( V_9 -> V_73 , V_78 ) ;
if ( V_15 ) {
F_33 ( L_15 , V_15 ) ;
goto V_75;
}
V_15 = F_44 ( V_9 -> V_76 , V_79 ) ;
if ( V_15 ) {
F_33 ( L_16 , V_15 ) ;
goto V_75;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_80 = F_34 ;
V_14 . V_81 = V_4 ;
V_14 . V_82 . V_83 = V_9 -> V_66 . V_67 + 1 ;
V_14 . V_82 . V_84 = V_9 -> V_68 . V_67 + 1 ;
V_14 . V_82 . V_85 = V_38 -> V_86 ;
V_14 . V_82 . V_87 = V_88 ;
V_14 . V_89 = V_90 ;
V_14 . V_91 = V_92 ;
V_14 . V_93 = V_9 -> V_73 ;
V_14 . V_94 = V_9 -> V_76 ;
V_15 = F_45 ( V_9 -> V_18 , V_9 -> V_69 , & V_14 ) ;
if ( V_15 ) {
F_33 ( L_17 , V_15 ) ;
goto V_75;
}
V_9 -> V_95 = F_46 ( V_61 ,
V_9 -> V_66 . V_67 *
sizeof( struct V_96 ) ,
& V_9 -> V_97 , V_98 ) ;
if ( ! V_9 -> V_95 ) {
V_15 = - V_99 ;
F_33 ( L_18 ) ;
goto V_75;
}
V_9 -> V_100 = F_46 ( V_61 ,
V_9 -> V_68 . V_67 *
sizeof( struct V_96 ) ,
& V_9 -> V_101 , V_98 ) ;
if ( ! V_9 -> V_100 ) {
V_15 = - V_99 ;
F_33 ( L_19 ) ;
goto V_75;
}
V_9 -> V_102 = F_46 ( V_61 , sizeof( struct V_96 ) ,
& V_9 -> V_103 , V_98 ) ;
if ( ! V_9 -> V_102 ) {
V_15 = - V_99 ;
F_33 ( L_20 ) ;
goto V_75;
}
V_9 -> V_104 = F_47 ( V_9 -> V_66 . V_67 * sizeof( struct V_105 ) ,
F_48 ( V_61 ) ) ;
if ( ! V_9 -> V_104 ) {
V_15 = - V_99 ;
F_33 ( L_21 ) ;
goto V_75;
}
V_9 -> V_106 = F_47 ( V_9 -> V_68 . V_67 * sizeof( struct V_107 ) ,
F_48 ( V_61 ) ) ;
if ( ! V_9 -> V_106 ) {
V_15 = - V_99 ;
F_33 ( L_22 ) ;
goto V_75;
}
F_49 ( V_9 ) ;
F_33 ( L_23 , V_4 , V_9 -> V_69 , V_9 -> V_71 ,
V_9 -> V_73 , V_9 -> V_76 ) ;
V_75:
F_50 ( V_38 ) ;
return V_15 ;
}
static T_1 F_51 ( struct V_22 * V_23 )
{
const struct V_24 * V_25 = V_23 -> V_28 . V_4 . V_30 ;
T_2 V_108 ;
T_1 V_5 = 0 ;
if ( ! V_23 -> V_28 . V_4 . V_29 ) {
F_9 ( V_21 L_24
L_25 ) ;
return 0 ;
}
if ( V_23 -> V_28 . V_4 . V_29 < sizeof ( * V_25 ) ||
V_25 -> V_31 == 0 )
return V_109 ;
V_108 = F_52 ( V_25 -> V_54 ) & V_55 ;
if ( V_25 -> V_31 == 3 && V_108 ) {
V_5 = V_109 ;
while ( ( V_108 >>= 1 ) != 0 )
V_5 ++ ;
}
F_53 ( V_21 L_26
L_27 ,
& V_25 -> V_52 ,
V_25 -> V_31 ,
V_25 -> V_32 ) ;
return V_5 ;
}
int F_54 ( struct V_110 * V_111 ,
struct V_22 * V_23 )
{
T_3 V_112 = V_111 -> V_113 . V_114 -> V_115 . V_116 . V_117 ;
T_3 V_118 = V_111 -> V_113 . V_114 -> V_119 . V_116 . V_117 ;
const struct V_24 * V_25 = V_23 -> V_28 . V_4 . V_30 ;
struct V_24 V_120 ;
struct V_3 * V_4 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_42 V_43 ;
T_1 V_5 ;
int V_27 = 1 , V_121 = 1 ;
V_5 = F_51 ( V_23 ) ;
if ( ! V_5 )
goto V_75;
F_33 ( L_28
L_29 , & V_25 -> V_52 , & V_25 -> V_53 ,
F_13 ( V_5 ) , F_14 ( V_5 ) ,
( unsigned long long ) F_21 ( V_112 ) ,
( unsigned long long ) F_21 ( V_118 ) ) ;
V_4 = F_55 ( V_25 -> V_53 , V_25 -> V_52 , & V_122 ,
V_98 ) ;
if ( F_42 ( V_4 ) ) {
F_33 ( L_30 , F_43 ( V_4 ) ) ;
V_4 = NULL ;
goto V_75;
}
F_56 ( & V_4 -> V_123 ) ;
if ( ! F_57 ( V_4 , V_124 , V_125 ) ) {
if ( F_58 ( V_4 ) == V_126 ) {
F_33 ( L_31 ) ;
F_36 ( V_4 ) ;
F_59 ( V_127 ) ;
} else
if ( F_58 ( V_4 ) == V_125 ) {
F_59 ( V_128 ) ;
}
goto V_75;
}
V_9 = V_4 -> V_10 ;
F_4 ( V_4 , V_5 ) ;
F_5 ( V_4 , F_12 ( V_25 -> V_33 ) ) ;
if ( V_25 -> V_41 )
F_20 ( V_4 , F_21 ( V_25 -> V_41 ) , NULL ) ;
F_60 ( V_111 -> V_129 ) ;
F_60 ( V_9 -> V_18 ) ;
V_9 -> V_18 = V_111 ;
V_111 -> V_129 = V_4 ;
V_121 = 0 ;
V_27 = F_37 ( V_4 ) ;
if ( V_27 ) {
F_61 ( V_4 , L_32 , V_27 ) ;
goto V_75;
}
F_23 ( V_4 , & V_43 , & V_120 , V_5 ,
V_23 -> V_28 . V_4 . V_48 ,
V_23 -> V_28 . V_4 . V_49 ) ;
V_27 = F_62 ( V_111 , & V_43 ) ;
if ( V_27 )
F_61 ( V_4 , L_33 , V_27 ) ;
V_75:
if ( V_4 )
F_63 ( & V_4 -> V_123 ) ;
if ( V_27 )
F_64 ( V_111 , NULL , 0 ) ;
return V_121 ;
}
int F_65 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = V_111 -> V_129 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_42 V_43 ;
struct V_24 V_25 ;
int V_15 ;
F_4 ( V_4 , V_109 ) ;
V_9 -> V_12 = V_11 ;
V_15 = F_37 ( V_4 ) ;
if ( V_15 ) {
F_61 ( V_4 , L_32 , V_15 ) ;
goto V_75;
}
F_23 ( V_4 , & V_43 , & V_25 , V_130 ,
V_131 , V_131 ) ;
V_15 = F_66 ( V_111 , & V_43 ) ;
if ( V_15 )
F_61 ( V_4 , L_34 , V_15 ) ;
V_75:
if ( V_15 ) {
if ( V_9 -> V_18 == V_111 )
V_15 = 0 ;
}
return V_15 ;
}
int F_67 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_132 V_133 , V_134 ;
int V_15 ;
V_9 -> V_18 = F_68 ( V_135 , V_4 ,
V_136 , V_92 ) ;
if ( F_42 ( V_9 -> V_18 ) ) {
V_15 = F_43 ( V_9 -> V_18 ) ;
V_9 -> V_18 = NULL ;
F_33 ( L_35 , V_15 ) ;
goto V_75;
}
F_33 ( L_36 , V_9 -> V_18 , V_4 ) ;
V_133 . V_137 = V_138 ;
V_133 . V_139 . V_140 = ( V_141 T_1 ) V_4 -> V_39 ;
V_133 . V_142 = ( V_141 T_2 ) F_69 ( 0 ) ;
V_134 . V_137 = V_138 ;
V_134 . V_139 . V_140 = ( V_141 T_1 ) V_4 -> V_34 ;
V_134 . V_142 = ( V_141 T_2 ) F_69 ( V_143 ) ;
V_15 = F_70 ( V_9 -> V_18 , (struct V_144 * ) & V_133 ,
(struct V_144 * ) & V_134 ,
V_145 ) ;
if ( V_15 ) {
F_33 ( L_37 , V_9 -> V_18 ,
V_15 ) ;
F_71 ( V_9 -> V_18 ) ;
V_9 -> V_18 = NULL ;
}
V_75:
return V_15 ;
}
void F_72 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
int V_27 = 0 ;
F_33 ( L_38 , V_9 -> V_18 ,
V_9 -> V_69 , V_9 -> V_73 , V_9 -> V_76 ,
V_9 -> V_18 ? V_9 -> V_18 -> V_19 : NULL ) ;
if ( V_9 -> V_18 ) {
struct V_60 * V_61 = V_9 -> V_18 -> V_62 ;
F_33 ( L_39 , V_9 -> V_18 ) ;
V_27 = F_73 ( V_9 -> V_18 ) ;
if ( V_27 ) {
F_33 ( L_40 ,
V_9 -> V_18 , V_27 ) ;
}
F_74 ( V_146 ,
F_75 ( & V_9 -> V_68 ) &&
( F_28 ( & V_9 -> V_147 ) == 0 ) ) ;
F_76 ( & V_9 -> V_148 ) ;
if ( V_9 -> V_95 )
F_77 ( V_61 ,
V_9 -> V_66 . V_67 *
sizeof( struct V_96 ) ,
V_9 -> V_95 ,
V_9 -> V_97 ) ;
if ( V_9 -> V_100 )
F_77 ( V_61 ,
V_9 -> V_68 . V_67 *
sizeof( struct V_96 ) ,
V_9 -> V_100 ,
V_9 -> V_101 ) ;
if ( V_9 -> V_102 )
F_77 ( V_61 , sizeof( struct V_96 ) ,
V_9 -> V_102 , V_9 -> V_103 ) ;
if ( V_9 -> V_104 )
F_78 ( V_9 ) ;
if ( V_9 -> V_106 )
F_79 ( V_9 ) ;
if ( V_9 -> V_18 -> V_19 )
F_80 ( V_9 -> V_18 ) ;
if ( V_9 -> V_73 )
F_81 ( V_9 -> V_73 ) ;
if ( V_9 -> V_76 )
F_81 ( V_9 -> V_76 ) ;
F_71 ( V_9 -> V_18 ) ;
if ( V_9 -> V_38 )
F_82 ( V_9 -> V_38 , V_4 ) ;
V_9 -> V_18 = NULL ;
V_9 -> V_69 = NULL ;
V_9 -> V_71 = NULL ;
V_9 -> V_73 = NULL ;
V_9 -> V_76 = NULL ;
V_9 -> V_95 = NULL ;
V_9 -> V_100 = NULL ;
V_9 -> V_102 = NULL ;
}
F_60 ( V_9 -> V_38 ) ;
if ( V_9 -> V_149 ) {
struct V_150 * V_151 ;
V_151 = F_83 ( V_9 -> V_149 , struct V_150 , V_58 ) ;
F_84 ( V_151 ) ;
V_9 -> V_149 = NULL ;
}
F_85 ( V_152 , & V_9 -> V_153 ) ;
#ifdef F_86
F_87 ( & V_9 -> V_154 , 0 ) ;
#else
V_9 -> V_154 = 0 ;
#endif
V_9 -> V_155 = 0 ;
V_9 -> V_12 = 0 ;
F_88 ( & V_9 -> V_56 , 0 ) ;
F_89 ( & V_9 -> V_66 , V_156 ) ;
F_89 ( & V_9 -> V_68 , V_157 ) ;
if ( V_9 -> V_158 ) {
F_90 ( & V_9 -> V_158 -> V_159 ) ;
V_9 -> V_158 = NULL ;
}
F_91 ( V_9 -> V_104 ) ;
V_9 -> V_104 = NULL ;
F_91 ( V_9 -> V_106 ) ;
V_9 -> V_106 = NULL ;
}
int F_92 ( struct V_3 * V_4 , T_4 V_160 )
{
struct V_8 * V_9 ;
unsigned long V_161 ;
int V_15 ;
V_9 = F_93 ( sizeof( struct V_8 ) , V_98 ) ;
if ( ! V_9 )
return - V_99 ;
V_15 = F_94 ( V_9 ) ;
if ( V_15 ) {
F_95 ( V_9 ) ;
return V_15 ;
}
F_96 ( & V_9 -> V_162 ) ;
F_97 ( & V_9 -> V_148 , V_163 ,
( unsigned long ) V_9 ) ;
F_98 ( & V_9 -> V_164 ) ;
#ifndef F_86
F_99 ( & V_9 -> V_165 ) ;
#endif
F_88 ( & V_9 -> V_147 , 0 ) ;
F_89 ( & V_9 -> V_66 , V_156 ) ;
F_89 ( & V_9 -> V_68 , V_157 ) ;
V_9 -> V_4 = V_4 ;
V_4 -> V_10 = V_9 ;
F_100 ( & V_166 , V_161 ) ;
F_101 ( & V_9 -> V_162 , & V_167 ) ;
F_102 ( & V_166 , V_161 ) ;
F_33 ( L_41 , V_4 , V_4 -> V_10 ) ;
return 0 ;
}
void F_103 ( void * V_168 )
{
struct V_8 * V_9 = V_168 ;
T_5 * V_169 ;
F_33 ( L_42 , V_9 ) ;
V_169 = V_9 -> V_38 ? & V_9 -> V_38 -> V_170 : & V_166 ;
F_104 ( V_169 ) ;
F_105 ( & V_9 -> V_162 ) ;
F_106 ( V_169 ) ;
F_107 ( V_9 ) ;
F_95 ( V_9 ) ;
}
void
F_108 ( struct V_3 * V_4 , const char * V_171 , ... )
{
T_6 V_172 ;
F_36 ( V_4 ) ;
va_start ( V_172 , V_171 ) ;
F_109 ( V_171 , V_172 ) ;
va_end ( V_172 ) ;
}
