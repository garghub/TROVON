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
unsigned int V_56 , V_57 ;
int V_58 ;
V_56 = F_32 (unsigned int, rds_iwdev->max_wrs, rds_iw_sysctl_max_send_wr + 1 ) ;
V_57 = F_32 (unsigned int, rds_iwdev->max_wrs, rds_iw_sysctl_max_recv_wr + 1 ) ;
F_33 ( V_50 , V_56 - 1 ) ;
F_33 ( V_52 , V_57 - 1 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_59 = F_26 ;
V_48 -> V_60 = V_53 ;
V_48 -> V_61 . V_62 = V_56 ;
V_48 -> V_61 . V_63 = V_57 ;
V_48 -> V_61 . V_64 = V_16 -> V_65 ;
V_48 -> V_61 . V_66 = V_67 ;
V_48 -> V_68 = V_69 ;
V_48 -> V_70 = V_71 ;
V_48 -> V_72 = F_34 ( V_55 , F_30 ,
F_24 ,
V_53 , V_56 , 0 ) ;
if ( F_35 ( V_48 -> V_72 ) ) {
V_58 = F_36 ( V_48 -> V_72 ) ;
V_48 -> V_72 = NULL ;
F_25 ( L_9 , V_58 ) ;
goto V_73;
}
V_48 -> V_74 = F_34 ( V_55 , F_31 ,
F_24 ,
V_53 , V_57 , 0 ) ;
if ( F_35 ( V_48 -> V_74 ) ) {
V_58 = F_36 ( V_48 -> V_74 ) ;
V_48 -> V_74 = NULL ;
F_25 ( L_9 , V_58 ) ;
goto V_73;
}
V_58 = F_37 ( V_48 -> V_72 , V_75 ) ;
if ( V_58 ) {
F_25 ( L_10 , V_58 ) ;
goto V_73;
}
V_58 = F_37 ( V_48 -> V_74 , V_76 ) ;
if ( V_58 ) {
F_25 ( L_11 , V_58 ) ;
goto V_73;
}
V_73:
if ( V_58 ) {
if ( V_48 -> V_72 )
F_38 ( V_48 -> V_72 ) ;
if ( V_48 -> V_74 )
F_38 ( V_48 -> V_74 ) ;
}
return V_58 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_54 * V_55 = V_7 -> V_24 -> V_25 ;
struct V_47 V_48 ;
struct V_15 * V_16 ;
int V_58 ;
V_16 = F_7 ( V_55 , & V_26 ) ;
if ( ! V_16 ) {
F_40 ( V_29 L_12 ,
V_55 -> V_77 ) ;
return - V_78 ;
}
V_7 -> V_79 = V_16 -> V_80 ;
V_7 -> V_81 = V_16 -> V_82 ;
V_58 = F_29 ( & V_48 , V_16 ,
& V_7 -> V_83 , V_84 ,
& V_7 -> V_85 , V_86 ,
V_2 ) ;
if ( V_58 < 0 )
goto V_73;
V_7 -> V_87 = V_48 . V_72 ;
V_7 -> V_88 = V_48 . V_74 ;
V_58 = F_41 ( V_7 -> V_24 , V_7 -> V_79 , & V_48 ) ;
if ( V_58 ) {
F_25 ( L_13 , V_58 ) ;
goto V_73;
}
V_7 -> V_89 = F_42 ( V_55 ,
V_7 -> V_83 . V_90 *
sizeof( struct V_91 ) ,
& V_7 -> V_92 , V_93 ) ;
if ( ! V_7 -> V_89 ) {
V_58 = - V_94 ;
F_25 ( L_14 ) ;
goto V_73;
}
V_7 -> V_95 = F_42 ( V_55 ,
V_7 -> V_85 . V_90 *
sizeof( struct V_91 ) ,
& V_7 -> V_96 , V_93 ) ;
if ( ! V_7 -> V_95 ) {
V_58 = - V_94 ;
F_25 ( L_15 ) ;
goto V_73;
}
V_7 -> V_97 = F_42 ( V_55 , sizeof( struct V_91 ) ,
& V_7 -> V_98 , V_93 ) ;
if ( ! V_7 -> V_97 ) {
V_58 = - V_94 ;
F_25 ( L_16 ) ;
goto V_73;
}
V_7 -> V_99 = F_43 ( V_7 -> V_83 . V_90 * sizeof( struct V_100 ) ) ;
if ( ! V_7 -> V_99 ) {
V_58 = - V_94 ;
F_25 ( L_17 ) ;
goto V_73;
}
F_44 ( V_7 ) ;
V_7 -> V_101 = F_43 ( V_7 -> V_85 . V_90 * sizeof( struct V_102 ) ) ;
if ( ! V_7 -> V_101 ) {
V_58 = - V_94 ;
F_25 ( L_18 ) ;
goto V_73;
}
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
F_47 ( V_2 , V_93 , V_103 , 1 ) ;
F_25 ( L_19 , V_2 , V_7 -> V_79 , V_7 -> V_81 ,
V_7 -> V_87 , V_7 -> V_88 ) ;
V_73:
return V_58 ;
}
static T_1 F_48 ( const struct V_13 * V_14 )
{
T_2 V_104 ;
T_1 V_3 = 0 ;
if ( V_14 -> V_21 == 0 )
return V_105 ;
V_104 = F_49 ( V_14 -> V_39 ) & V_40 ;
if ( V_14 -> V_21 == 3 && V_104 ) {
V_3 = V_105 ;
while ( ( V_104 >>= 1 ) != 0 )
V_3 ++ ;
}
F_40 ( V_29 L_20
L_21 ,
& V_14 -> V_37 ,
V_14 -> V_21 ,
V_14 -> V_22 ) ;
return V_3 ;
}
int F_50 ( struct V_106 * V_107 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_12 -> V_18 . V_2 . V_20 ;
struct V_13 V_108 ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_32 V_33 ;
struct V_15 * V_16 ;
T_1 V_3 ;
int V_17 , V_109 = 1 ;
V_3 = F_48 ( V_14 ) ;
if ( ! V_3 )
goto V_73;
F_25 ( L_22 ,
& V_14 -> V_37 , & V_14 -> V_38 ,
F_13 ( V_3 ) , F_14 ( V_3 ) ) ;
V_2 = F_51 ( V_14 -> V_38 , V_14 -> V_37 , & V_110 ,
V_93 ) ;
if ( F_35 ( V_2 ) ) {
F_25 ( L_23 , F_36 ( V_2 ) ) ;
V_2 = NULL ;
goto V_73;
}
F_52 ( & V_2 -> V_111 ) ;
if ( ! F_53 ( V_2 , V_112 , V_113 ) ) {
if ( F_54 ( V_2 ) == V_114 ) {
F_25 ( L_24 ) ;
F_28 ( V_2 ) ;
F_55 ( V_115 ) ;
} else
if ( F_54 ( V_2 ) == V_113 ) {
F_55 ( V_116 ) ;
}
F_56 ( & V_2 -> V_111 ) ;
goto V_73;
}
V_7 = V_2 -> V_8 ;
F_1 ( V_2 , V_3 ) ;
F_2 ( V_2 , F_6 ( V_14 -> V_23 ) ) ;
if ( V_14 -> V_28 )
F_11 ( V_2 , F_12 ( V_14 -> V_28 ) , NULL ) ;
F_57 ( V_107 -> V_53 ) ;
F_57 ( V_7 -> V_24 ) ;
V_7 -> V_24 = V_107 ;
V_107 -> V_53 = V_2 ;
V_16 = F_7 ( V_107 -> V_25 , & V_26 ) ;
V_7 -> V_117 = V_16 -> V_118 ;
V_109 = 0 ;
V_17 = F_39 ( V_2 ) ;
if ( V_17 ) {
F_58 ( V_2 , L_25 , V_17 ) ;
F_56 ( & V_2 -> V_111 ) ;
goto V_73;
}
F_16 ( V_2 , & V_33 , & V_108 , V_3 ) ;
V_17 = F_59 ( V_107 , & V_33 ) ;
F_56 ( & V_2 -> V_111 ) ;
if ( V_17 ) {
F_58 ( V_2 , L_26 , V_17 ) ;
goto V_73;
}
return 0 ;
V_73:
F_60 ( V_107 , NULL , 0 ) ;
return V_109 ;
}
int F_61 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_53 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_32 V_33 ;
struct V_13 V_14 ;
int V_58 ;
F_1 ( V_2 , V_105 ) ;
V_7 -> V_10 = V_9 ;
V_58 = F_39 ( V_2 ) ;
if ( V_58 ) {
F_58 ( V_2 , L_25 , V_58 ) ;
goto V_73;
}
F_16 ( V_2 , & V_33 , & V_14 , V_119 ) ;
V_58 = F_62 ( V_107 , & V_33 ) ;
if ( V_58 )
F_58 ( V_2 , L_27 , V_58 ) ;
V_73:
if ( V_58 ) {
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_24 == V_107 )
V_58 = 0 ;
}
return V_58 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_15 * V_16 ;
struct V_120 V_121 , V_122 ;
int V_58 ;
V_7 -> V_24 = F_64 ( V_123 , V_2 ,
V_124 , V_71 ) ;
if ( F_35 ( V_7 -> V_24 ) ) {
V_58 = F_36 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
F_25 ( L_28 , V_58 ) ;
goto V_73;
}
F_25 ( L_29 , V_7 -> V_24 , V_2 ) ;
V_121 . V_125 = V_126 ;
V_121 . V_127 . V_128 = ( V_129 T_1 ) V_2 -> V_30 ;
V_121 . V_130 = ( V_129 T_2 ) F_65 ( 0 ) ;
V_58 = F_66 ( V_7 -> V_24 , (struct V_131 * ) & V_121 ) ;
if ( V_58 ) {
F_25 ( L_30 ,
& V_2 -> V_30 , V_58 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
goto V_73;
}
V_16 = F_7 ( V_7 -> V_24 -> V_25 , & V_26 ) ;
V_7 -> V_117 = V_16 -> V_118 ;
V_122 . V_125 = V_126 ;
V_122 . V_127 . V_128 = ( V_129 T_1 ) V_2 -> V_31 ;
V_122 . V_130 = ( V_129 T_2 ) F_65 ( V_132 ) ;
V_58 = F_68 ( V_7 -> V_24 , (struct V_131 * ) & V_121 ,
(struct V_131 * ) & V_122 ,
V_133 ) ;
if ( V_58 ) {
F_25 ( L_31 , V_7 -> V_24 ,
V_58 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
}
V_73:
return V_58 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_17 = 0 ;
struct V_134 V_135 ;
F_25 ( L_32 , V_7 -> V_24 ,
V_7 -> V_79 , V_7 -> V_87 , V_7 -> V_88 ,
V_7 -> V_24 ? V_7 -> V_24 -> V_136 : NULL ) ;
if ( V_7 -> V_24 ) {
struct V_54 * V_55 = V_7 -> V_24 -> V_25 ;
F_25 ( L_33 , V_7 -> V_24 ) ;
V_17 = F_70 ( V_7 -> V_24 ) ;
if ( V_17 ) {
F_25 ( L_34 ,
V_7 -> V_24 , V_17 ) ;
}
if ( V_7 -> V_24 -> V_136 ) {
V_135 . V_137 = V_138 ;
F_71 ( V_7 -> V_24 -> V_136 , & V_135 , V_139 ) ;
}
F_72 ( V_140 ,
F_73 ( & V_7 -> V_83 ) &&
F_73 ( & V_7 -> V_85 ) ) ;
if ( V_7 -> V_89 )
F_74 ( V_55 ,
V_7 -> V_83 . V_90 *
sizeof( struct V_91 ) ,
V_7 -> V_89 ,
V_7 -> V_92 ) ;
if ( V_7 -> V_95 )
F_74 ( V_55 ,
V_7 -> V_85 . V_90 *
sizeof( struct V_91 ) ,
V_7 -> V_95 ,
V_7 -> V_96 ) ;
if ( V_7 -> V_97 )
F_74 ( V_55 , sizeof( struct V_91 ) ,
V_7 -> V_97 , V_7 -> V_98 ) ;
if ( V_7 -> V_99 )
F_75 ( V_7 ) ;
if ( V_7 -> V_101 )
F_76 ( V_7 ) ;
if ( V_7 -> V_24 -> V_136 )
F_77 ( V_7 -> V_24 ) ;
if ( V_7 -> V_87 )
F_38 ( V_7 -> V_87 ) ;
if ( V_7 -> V_88 )
F_38 ( V_7 -> V_88 ) ;
if ( V_7 -> V_16 )
F_78 ( V_7 -> V_16 , V_2 ) ;
F_67 ( V_7 -> V_24 ) ;
V_7 -> V_24 = NULL ;
V_7 -> V_79 = NULL ;
V_7 -> V_81 = NULL ;
V_7 -> V_87 = NULL ;
V_7 -> V_88 = NULL ;
V_7 -> V_89 = NULL ;
V_7 -> V_95 = NULL ;
V_7 -> V_97 = NULL ;
}
F_57 ( V_7 -> V_16 ) ;
if ( V_7 -> V_141 ) {
F_79 ( V_7 -> V_141 ) ;
V_7 -> V_141 = NULL ;
}
F_80 ( V_142 , & V_7 -> V_143 ) ;
#ifdef F_81
F_82 ( & V_7 -> V_144 , 0 ) ;
#else
V_7 -> V_144 = 0 ;
#endif
V_7 -> V_145 = 0 ;
V_7 -> V_10 = 0 ;
F_83 ( & V_7 -> V_41 , 0 ) ;
F_84 ( & V_7 -> V_83 , V_146 ) ;
F_84 ( & V_7 -> V_85 , V_147 ) ;
if ( V_7 -> V_148 ) {
F_85 ( & V_7 -> V_148 -> V_149 ) ;
V_7 -> V_148 = NULL ;
}
F_86 ( V_7 -> V_99 ) ;
V_7 -> V_99 = NULL ;
F_86 ( V_7 -> V_101 ) ;
V_7 -> V_101 = NULL ;
F_25 ( L_35 ) ;
}
int F_87 ( struct V_1 * V_2 , T_3 V_150 )
{
struct V_6 * V_7 ;
unsigned long V_151 ;
V_7 = F_88 ( sizeof( struct V_6 ) , V_150 ) ;
if ( ! V_7 )
return - V_94 ;
F_89 ( & V_7 -> V_152 ) ;
F_90 ( & V_7 -> V_153 , V_154 ,
( unsigned long ) V_7 ) ;
F_91 ( & V_7 -> V_155 ) ;
#ifndef F_81
F_92 ( & V_7 -> V_156 ) ;
#endif
F_84 ( & V_7 -> V_83 , V_146 ) ;
F_84 ( & V_7 -> V_85 , V_147 ) ;
V_7 -> V_2 = V_2 ;
V_2 -> V_8 = V_7 ;
F_93 ( & V_157 , V_151 ) ;
F_94 ( & V_7 -> V_152 , & V_158 ) ;
F_95 ( & V_157 , V_151 ) ;
F_25 ( L_36 , V_2 , V_2 -> V_8 ) ;
return 0 ;
}
void F_96 ( void * V_159 )
{
struct V_6 * V_7 = V_159 ;
T_4 * V_160 ;
F_25 ( L_37 , V_7 ) ;
V_160 = V_7 -> V_16 ? & V_7 -> V_16 -> V_161 : & V_157 ;
F_97 ( V_160 ) ;
F_98 ( & V_7 -> V_152 ) ;
F_99 ( V_160 ) ;
F_100 ( V_7 ) ;
}
void
F_101 ( struct V_1 * V_2 , const char * V_162 , ... )
{
T_5 V_163 ;
F_28 ( V_2 ) ;
va_start ( V_163 , V_162 ) ;
F_102 ( V_162 , V_163 ) ;
va_end ( V_163 ) ;
}
