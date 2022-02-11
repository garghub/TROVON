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
void F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
const struct V_13 * V_14 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_15 * V_16 ;
int V_17 ;
if ( V_12 -> V_18 . V_2 . V_19 ) {
V_14 = V_12 -> V_18 . V_2 . V_20 ;
F_1 ( V_2 ,
F_5 ( V_14 -> V_21 ,
V_14 -> V_22 ) ) ;
F_2 ( V_2 , F_6 ( V_14 -> V_23 ) ) ;
}
V_16 = F_7 ( V_7 -> V_24 -> V_25 , & V_26 ) ;
V_17 = F_8 ( V_16 , V_7 -> V_24 ) ;
if ( V_17 )
F_9 ( V_27 L_1 , V_17 ) ;
F_10 ( V_16 , V_2 ) ;
if ( V_14 && V_14 -> V_28 )
F_11 ( V_2 , F_12 ( V_14 -> V_28 ) , NULL ) ;
F_9 ( V_29 L_2 ,
& V_2 -> V_30 , & V_2 -> V_31 ,
F_13 ( V_2 -> V_4 ) ,
F_14 ( V_2 -> V_4 ) ,
V_7 -> V_10 ? L_3 : L_4 ) ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_13 * V_14 ,
T_1 V_34 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
memset ( V_33 , 0 , sizeof( struct V_32 ) ) ;
V_33 -> V_35 = 1 ;
V_33 -> V_36 = 1 ;
if ( V_14 ) {
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_37 = V_2 -> V_30 ;
V_14 -> V_38 = V_2 -> V_31 ;
V_14 -> V_21 = F_13 ( V_34 ) ;
V_14 -> V_22 = F_14 ( V_34 ) ;
V_14 -> V_39 = F_17 ( V_40 ) ;
V_14 -> V_28 = F_18 ( V_7 ) ;
if ( V_7 -> V_10 ) {
unsigned int V_5 ;
V_5 = F_19 ( F_20 ( & V_7 -> V_41 ) ) ;
V_14 -> V_23 = F_21 ( V_5 ) ;
F_22 ( F_23 ( V_5 ) , & V_7 -> V_41 ) ;
}
V_33 -> V_20 = V_14 ;
V_33 -> V_19 = sizeof( * V_14 ) ;
}
}
static void F_24 ( struct V_42 * V_12 , void * V_43 )
{
F_25 ( L_5 , V_12 -> V_12 , V_43 ) ;
}
static void F_26 ( struct V_42 * V_12 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_6 * V_7 = V_2 -> V_8 ;
F_25 ( L_6 , V_2 , V_7 , V_12 -> V_12 ) ;
switch ( V_12 -> V_12 ) {
case V_44 :
F_27 ( V_7 -> V_24 , V_44 ) ;
break;
case V_45 :
case V_46 :
default:
F_25 ( L_7
L_8 ,
V_12 -> V_12 , & V_2 -> V_30 ,
& V_2 -> V_31 ) ;
F_28 ( V_2 ) ;
break;
}
}
static int F_29 ( struct V_47 * V_48 ,
struct V_15 * V_16 ,
struct V_49 * V_50 ,
void (* F_30)( struct V_51 * , void * ) ,
struct V_49 * V_52 ,
void (* F_31)( struct V_51 * , void * ) ,
void * V_53 )
{
struct V_54 * V_55 = V_16 -> V_55 ;
struct V_56 V_57 = {} ;
unsigned int V_58 , V_59 ;
int V_60 ;
V_58 = F_32 (unsigned int, rds_iwdev->max_wrs, rds_iw_sysctl_max_send_wr + 1 ) ;
V_59 = F_32 (unsigned int, rds_iwdev->max_wrs, rds_iw_sysctl_max_recv_wr + 1 ) ;
F_33 ( V_50 , V_58 - 1 ) ;
F_33 ( V_52 , V_59 - 1 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_61 = F_26 ;
V_48 -> V_62 = V_53 ;
V_48 -> V_63 . V_64 = V_58 ;
V_48 -> V_63 . V_65 = V_59 ;
V_48 -> V_63 . V_66 = V_16 -> V_67 ;
V_48 -> V_63 . V_68 = V_69 ;
V_48 -> V_70 = V_71 ;
V_48 -> V_72 = V_73 ;
V_57 . V_74 = V_58 ;
V_48 -> V_75 = F_34 ( V_55 , F_30 ,
F_24 ,
V_53 , & V_57 ) ;
if ( F_35 ( V_48 -> V_75 ) ) {
V_60 = F_36 ( V_48 -> V_75 ) ;
V_48 -> V_75 = NULL ;
F_25 ( L_9 , V_60 ) ;
goto V_76;
}
V_57 . V_74 = V_59 ;
V_48 -> V_77 = F_34 ( V_55 , F_31 ,
F_24 ,
V_53 , & V_57 ) ;
if ( F_35 ( V_48 -> V_77 ) ) {
V_60 = F_36 ( V_48 -> V_77 ) ;
V_48 -> V_77 = NULL ;
F_25 ( L_9 , V_60 ) ;
goto V_76;
}
V_60 = F_37 ( V_48 -> V_75 , V_78 ) ;
if ( V_60 ) {
F_25 ( L_10 , V_60 ) ;
goto V_76;
}
V_60 = F_37 ( V_48 -> V_77 , V_79 ) ;
if ( V_60 ) {
F_25 ( L_11 , V_60 ) ;
goto V_76;
}
V_76:
if ( V_60 ) {
if ( V_48 -> V_75 )
F_38 ( V_48 -> V_75 ) ;
if ( V_48 -> V_77 )
F_38 ( V_48 -> V_77 ) ;
}
return V_60 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_54 * V_55 = V_7 -> V_24 -> V_25 ;
struct V_47 V_48 ;
struct V_15 * V_16 ;
int V_60 ;
V_16 = F_7 ( V_55 , & V_26 ) ;
if ( ! V_16 ) {
F_40 ( V_29 L_12 ,
V_55 -> V_80 ) ;
return - V_81 ;
}
V_7 -> V_82 = V_16 -> V_83 ;
V_7 -> V_84 = V_16 -> V_85 ;
V_60 = F_29 ( & V_48 , V_16 ,
& V_7 -> V_86 , V_87 ,
& V_7 -> V_88 , V_89 ,
V_2 ) ;
if ( V_60 < 0 )
goto V_76;
V_7 -> V_90 = V_48 . V_75 ;
V_7 -> V_91 = V_48 . V_77 ;
V_60 = F_41 ( V_7 -> V_24 , V_7 -> V_82 , & V_48 ) ;
if ( V_60 ) {
F_25 ( L_13 , V_60 ) ;
goto V_76;
}
V_7 -> V_92 = F_42 ( V_55 ,
V_7 -> V_86 . V_93 *
sizeof( struct V_94 ) ,
& V_7 -> V_95 , V_96 ) ;
if ( ! V_7 -> V_92 ) {
V_60 = - V_97 ;
F_25 ( L_14 ) ;
goto V_76;
}
V_7 -> V_98 = F_42 ( V_55 ,
V_7 -> V_88 . V_93 *
sizeof( struct V_94 ) ,
& V_7 -> V_99 , V_96 ) ;
if ( ! V_7 -> V_98 ) {
V_60 = - V_97 ;
F_25 ( L_15 ) ;
goto V_76;
}
V_7 -> V_100 = F_42 ( V_55 , sizeof( struct V_94 ) ,
& V_7 -> V_101 , V_96 ) ;
if ( ! V_7 -> V_100 ) {
V_60 = - V_97 ;
F_25 ( L_16 ) ;
goto V_76;
}
V_7 -> V_102 = F_43 ( V_7 -> V_86 . V_93 * sizeof( struct V_103 ) ) ;
if ( ! V_7 -> V_102 ) {
V_60 = - V_97 ;
F_25 ( L_17 ) ;
goto V_76;
}
F_44 ( V_7 ) ;
V_7 -> V_104 = F_43 ( V_7 -> V_88 . V_93 * sizeof( struct V_105 ) ) ;
if ( ! V_7 -> V_104 ) {
V_60 = - V_97 ;
F_25 ( L_18 ) ;
goto V_76;
}
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_2 , V_96 , V_106 , 1 ) ;
F_25 ( L_19 , V_2 , V_7 -> V_82 , V_7 -> V_84 ,
V_7 -> V_90 , V_7 -> V_91 ) ;
V_76:
return V_60 ;
}
static T_1 F_48 ( const struct V_13 * V_14 )
{
T_2 V_107 ;
T_1 V_3 = 0 ;
if ( V_14 -> V_21 == 0 )
return V_108 ;
V_107 = F_49 ( V_14 -> V_39 ) & V_40 ;
if ( V_14 -> V_21 == 3 && V_107 ) {
V_3 = V_108 ;
while ( ( V_107 >>= 1 ) != 0 )
V_3 ++ ;
}
F_40 ( V_29 L_20
L_21 ,
& V_14 -> V_37 ,
V_14 -> V_21 ,
V_14 -> V_22 ) ;
return V_3 ;
}
int F_50 ( struct V_109 * V_110 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_12 -> V_18 . V_2 . V_20 ;
struct V_13 V_111 ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_32 V_33 ;
struct V_15 * V_16 ;
T_1 V_3 ;
int V_17 , V_112 = 1 ;
V_3 = F_48 ( V_14 ) ;
if ( ! V_3 )
goto V_76;
F_25 ( L_22 ,
& V_14 -> V_37 , & V_14 -> V_38 ,
F_13 ( V_3 ) , F_14 ( V_3 ) ) ;
V_2 = F_51 ( V_14 -> V_38 , V_14 -> V_37 , & V_113 ,
V_96 ) ;
if ( F_35 ( V_2 ) ) {
F_25 ( L_23 , F_36 ( V_2 ) ) ;
V_2 = NULL ;
goto V_76;
}
F_52 ( & V_2 -> V_114 ) ;
if ( ! F_53 ( V_2 , V_115 , V_116 ) ) {
if ( F_54 ( V_2 ) == V_117 ) {
F_25 ( L_24 ) ;
F_28 ( V_2 ) ;
F_55 ( V_118 ) ;
} else
if ( F_54 ( V_2 ) == V_116 ) {
F_55 ( V_119 ) ;
}
F_56 ( & V_2 -> V_114 ) ;
goto V_76;
}
V_7 = V_2 -> V_8 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( V_2 , F_6 ( V_14 -> V_23 ) ) ;
if ( V_14 -> V_28 )
F_11 ( V_2 , F_12 ( V_14 -> V_28 ) , NULL ) ;
F_57 ( V_110 -> V_53 ) ;
F_57 ( V_7 -> V_24 ) ;
V_7 -> V_24 = V_110 ;
V_110 -> V_53 = V_2 ;
V_16 = F_7 ( V_110 -> V_25 , & V_26 ) ;
V_7 -> V_120 = V_16 -> V_121 ;
V_112 = 0 ;
V_17 = F_39 ( V_2 ) ;
if ( V_17 ) {
F_58 ( V_2 , L_25 , V_17 ) ;
F_56 ( & V_2 -> V_114 ) ;
goto V_76;
}
F_16 ( V_2 , & V_33 , & V_111 , V_3 ) ;
V_17 = F_59 ( V_110 , & V_33 ) ;
F_56 ( & V_2 -> V_114 ) ;
if ( V_17 ) {
F_58 ( V_2 , L_26 , V_17 ) ;
goto V_76;
}
return 0 ;
V_76:
F_60 ( V_110 , NULL , 0 ) ;
return V_112 ;
}
int F_61 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = V_110 -> V_53 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_32 V_33 ;
struct V_13 V_14 ;
int V_60 ;
F_1 ( V_2 , V_108 ) ;
V_7 -> V_10 = V_9 ;
V_60 = F_39 ( V_2 ) ;
if ( V_60 ) {
F_58 ( V_2 , L_25 , V_60 ) ;
goto V_76;
}
F_16 ( V_2 , & V_33 , & V_14 , V_122 ) ;
V_60 = F_62 ( V_110 , & V_33 ) ;
if ( V_60 )
F_58 ( V_2 , L_27 , V_60 ) ;
V_76:
if ( V_60 ) {
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_24 == V_110 )
V_60 = 0 ;
}
return V_60 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_15 * V_16 ;
struct V_123 V_124 , V_125 ;
int V_60 ;
V_7 -> V_24 = F_64 ( V_126 , V_2 ,
V_127 , V_73 ) ;
if ( F_35 ( V_7 -> V_24 ) ) {
V_60 = F_36 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
F_25 ( L_28 , V_60 ) ;
goto V_76;
}
F_25 ( L_29 , V_7 -> V_24 , V_2 ) ;
V_124 . V_128 = V_129 ;
V_124 . V_130 . V_131 = ( V_132 T_1 ) V_2 -> V_30 ;
V_124 . V_133 = ( V_132 T_2 ) F_65 ( 0 ) ;
V_60 = F_66 ( V_7 -> V_24 , (struct V_134 * ) & V_124 ) ;
if ( V_60 ) {
F_25 ( L_30 ,
& V_2 -> V_30 , V_60 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
goto V_76;
}
V_16 = F_7 ( V_7 -> V_24 -> V_25 , & V_26 ) ;
V_7 -> V_120 = V_16 -> V_121 ;
V_125 . V_128 = V_129 ;
V_125 . V_130 . V_131 = ( V_132 T_1 ) V_2 -> V_31 ;
V_125 . V_133 = ( V_132 T_2 ) F_65 ( V_135 ) ;
V_60 = F_68 ( V_7 -> V_24 , (struct V_134 * ) & V_124 ,
(struct V_134 * ) & V_125 ,
V_136 ) ;
if ( V_60 ) {
F_25 ( L_31 , V_7 -> V_24 ,
V_60 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
}
V_76:
return V_60 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_17 = 0 ;
struct V_137 V_138 ;
F_25 ( L_32 , V_7 -> V_24 ,
V_7 -> V_82 , V_7 -> V_90 , V_7 -> V_91 ,
V_7 -> V_24 ? V_7 -> V_24 -> V_139 : NULL ) ;
if ( V_7 -> V_24 ) {
struct V_54 * V_55 = V_7 -> V_24 -> V_25 ;
F_25 ( L_33 , V_7 -> V_24 ) ;
V_17 = F_70 ( V_7 -> V_24 ) ;
if ( V_17 ) {
F_25 ( L_34 ,
V_7 -> V_24 , V_17 ) ;
}
if ( V_7 -> V_24 -> V_139 ) {
V_138 . V_140 = V_141 ;
F_71 ( V_7 -> V_24 -> V_139 , & V_138 , V_142 ) ;
}
F_72 ( V_143 ,
F_73 ( & V_7 -> V_86 ) &&
F_73 ( & V_7 -> V_88 ) ) ;
if ( V_7 -> V_92 )
F_74 ( V_55 ,
V_7 -> V_86 . V_93 *
sizeof( struct V_94 ) ,
V_7 -> V_92 ,
V_7 -> V_95 ) ;
if ( V_7 -> V_98 )
F_74 ( V_55 ,
V_7 -> V_88 . V_93 *
sizeof( struct V_94 ) ,
V_7 -> V_98 ,
V_7 -> V_99 ) ;
if ( V_7 -> V_100 )
F_74 ( V_55 , sizeof( struct V_94 ) ,
V_7 -> V_100 , V_7 -> V_101 ) ;
if ( V_7 -> V_102 )
F_75 ( V_7 ) ;
if ( V_7 -> V_104 )
F_76 ( V_7 ) ;
if ( V_7 -> V_24 -> V_139 )
F_77 ( V_7 -> V_24 ) ;
if ( V_7 -> V_90 )
F_38 ( V_7 -> V_90 ) ;
if ( V_7 -> V_91 )
F_38 ( V_7 -> V_91 ) ;
if ( V_7 -> V_16 )
F_78 ( V_7 -> V_16 , V_2 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
V_7 -> V_82 = NULL ;
V_7 -> V_84 = NULL ;
V_7 -> V_90 = NULL ;
V_7 -> V_91 = NULL ;
V_7 -> V_92 = NULL ;
V_7 -> V_98 = NULL ;
V_7 -> V_100 = NULL ;
}
F_57 ( V_7 -> V_16 ) ;
if ( V_7 -> V_144 ) {
F_79 ( V_7 -> V_144 ) ;
V_7 -> V_144 = NULL ;
}
F_80 ( V_145 , & V_7 -> V_146 ) ;
#ifdef F_81
F_82 ( & V_7 -> V_147 , 0 ) ;
#else
V_7 -> V_147 = 0 ;
#endif
V_7 -> V_148 = 0 ;
V_7 -> V_10 = 0 ;
F_83 ( & V_7 -> V_41 , 0 ) ;
F_84 ( & V_7 -> V_86 , V_149 ) ;
F_84 ( & V_7 -> V_88 , V_150 ) ;
if ( V_7 -> V_151 ) {
F_85 ( & V_7 -> V_151 -> V_152 ) ;
V_7 -> V_151 = NULL ;
}
F_86 ( V_7 -> V_102 ) ;
V_7 -> V_102 = NULL ;
F_86 ( V_7 -> V_104 ) ;
V_7 -> V_104 = NULL ;
F_25 ( L_35 ) ;
}
int F_87 ( struct V_1 * V_2 , T_3 V_153 )
{
struct V_6 * V_7 ;
unsigned long V_154 ;
V_7 = F_88 ( sizeof( struct V_6 ) , V_153 ) ;
if ( ! V_7 )
return - V_97 ;
F_89 ( & V_7 -> V_155 ) ;
F_90 ( & V_7 -> V_156 , V_157 ,
( unsigned long ) V_7 ) ;
F_91 ( & V_7 -> V_158 ) ;
#ifndef F_81
F_92 ( & V_7 -> V_159 ) ;
#endif
F_84 ( & V_7 -> V_86 , V_149 ) ;
F_84 ( & V_7 -> V_88 , V_150 ) ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 = V_7 ;
F_93 ( & V_160 , V_154 ) ;
F_94 ( & V_7 -> V_155 , & V_161 ) ;
F_95 ( & V_160 , V_154 ) ;
F_25 ( L_36 , V_2 , V_2 -> V_8 ) ;
return 0 ;
}
void F_96 ( void * V_162 )
{
struct V_6 * V_7 = V_162 ;
T_4 * V_163 ;
F_25 ( L_37 , V_7 ) ;
V_163 = V_7 -> V_16 ? & V_7 -> V_16 -> V_164 : & V_160 ;
F_97 ( V_163 ) ;
F_98 ( & V_7 -> V_155 ) ;
F_99 ( V_163 ) ;
F_100 ( V_7 ) ;
}
void
F_101 ( struct V_1 * V_2 , const char * V_165 , ... )
{
T_5 V_166 ;
F_28 ( V_2 ) ;
va_start ( V_166 , V_165 ) ;
F_102 ( V_165 , V_166 ) ;
va_end ( V_166 ) ;
}
