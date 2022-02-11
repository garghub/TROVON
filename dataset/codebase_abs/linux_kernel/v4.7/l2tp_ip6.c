static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( struct V_4 * V_4 ,
struct V_5 * V_6 ,
int V_7 , T_1 V_8 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip6_bind_table) {
const struct V_5 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_10 == NULL )
continue;
if ( ( V_10 -> V_11 == V_8 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
! ( V_9 && F_7 ( V_9 , V_6 ) ) &&
! ( V_3 -> V_12 && V_3 -> V_12 != V_7 ) )
goto V_13;
}
V_3 = NULL ;
V_13:
return V_3 ;
}
static inline struct V_2 * F_8 ( struct V_4 * V_4 ,
struct V_5 * V_6 ,
int V_7 , T_1 V_8 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_6 , V_7 , V_8 ) ;
if ( V_3 )
F_9 ( V_3 ) ;
return V_3 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_4 * V_4 = F_11 ( V_15 -> V_16 ) ;
struct V_2 * V_3 ;
T_1 V_17 ;
T_1 V_8 ;
unsigned char * V_18 , * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 = NULL ;
int V_24 ;
if ( ! F_12 ( V_15 , 4 ) )
goto V_25;
V_19 = V_18 = V_15 -> V_26 ;
V_17 = F_13 ( * ( ( V_27 * ) V_18 ) ) ;
V_18 += 4 ;
if ( V_17 == 0 ) {
F_14 ( V_15 , 4 ) ;
goto V_28;
}
V_21 = F_15 ( V_4 , NULL , V_17 ) ;
if ( V_21 == NULL )
goto V_25;
V_23 = V_21 -> V_23 ;
if ( V_23 == NULL )
goto V_25;
if ( V_23 -> V_29 & V_30 ) {
V_24 = F_16 ( 32u , V_15 -> V_31 ) ;
if ( ! F_12 ( V_15 , V_24 ) )
goto V_25;
V_19 = V_18 = V_15 -> V_26 ;
V_18 += 4 ;
F_17 ( L_1 , V_23 -> V_32 ) ;
F_18 ( L_2 , V_33 , V_18 , V_24 ) ;
}
F_19 ( V_21 , V_15 , V_18 , V_19 , 0 , V_15 -> V_31 ,
V_23 -> V_34 ) ;
return 0 ;
V_28:
if ( ! F_12 ( V_15 , 12 ) )
goto V_25;
if ( ( V_15 -> V_26 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_25;
V_8 = F_13 ( * ( V_27 * ) & V_15 -> V_26 [ 4 ] ) ;
V_23 = F_20 ( V_4 , V_8 ) ;
if ( V_23 != NULL )
V_3 = V_23 -> V_2 ;
else {
struct V_35 * V_36 = F_21 ( V_15 ) ;
F_22 ( & V_37 ) ;
V_3 = F_2 ( V_4 , & V_36 -> V_38 ,
0 , V_8 ) ;
F_23 ( & V_37 ) ;
}
if ( V_3 == NULL )
goto V_25;
F_9 ( V_3 ) ;
if ( ! F_24 ( V_3 , V_39 , V_15 ) )
goto V_40;
F_25 ( V_15 ) ;
return F_26 ( V_3 , V_15 , 1 ) ;
V_40:
F_27 ( V_3 ) ;
V_25:
F_28 ( V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_30 ( V_3 ) -> V_41 = V_42 ;
F_31 ( & V_37 ) ;
F_32 ( V_3 , & V_43 ) ;
F_33 ( & V_37 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 , long V_44 )
{
F_31 ( & V_37 ) ;
F_35 ( & V_3 -> V_45 ) ;
F_36 ( V_3 ) ;
F_33 ( & V_37 ) ;
F_37 ( V_3 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
if ( V_23 ) {
F_43 ( V_23 ) ;
F_27 ( V_3 ) ;
}
F_44 ( V_3 ) ;
}
static int F_45 ( struct V_2 * V_3 , struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_50 = F_30 ( V_3 ) ;
struct V_51 * V_52 = F_46 ( V_3 ) ;
struct V_53 * V_9 = (struct V_53 * ) V_47 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
V_27 V_54 = 0 ;
int V_55 ;
int V_56 ;
if ( ! F_47 ( V_3 , V_57 ) )
return - V_58 ;
if ( V_9 -> V_59 != V_60 )
return - V_58 ;
if ( V_48 < sizeof( * V_9 ) )
return - V_58 ;
V_55 = F_48 ( & V_9 -> V_61 ) ;
if ( V_55 == V_62 )
return - V_63 ;
if ( V_55 & V_64 )
return - V_63 ;
V_56 = - V_65 ;
F_22 ( & V_37 ) ;
if ( F_2 ( V_4 , & V_9 -> V_61 ,
V_3 -> V_12 , V_9 -> V_66 ) )
goto V_67;
F_23 ( & V_37 ) ;
F_40 ( V_3 ) ;
V_56 = - V_58 ;
if ( V_3 -> V_68 != V_69 )
goto V_70;
F_49 () ;
if ( V_55 != V_71 ) {
struct V_72 * V_16 = NULL ;
if ( V_55 & V_73 ) {
if ( V_48 >= sizeof( struct V_74 ) &&
V_9 -> V_75 ) {
V_3 -> V_12 = V_9 -> V_75 ;
}
if ( ! V_3 -> V_12 )
goto V_76;
V_56 = - V_77 ;
V_16 = F_50 ( F_6 ( V_3 ) ,
V_3 -> V_12 ) ;
if ( ! V_16 )
goto V_76;
}
V_54 = V_78 ;
V_56 = - V_63 ;
if ( ! F_51 ( F_6 ( V_3 ) , & V_9 -> V_61 , V_16 , 0 ) )
goto V_76;
}
F_52 () ;
V_50 -> V_79 = V_50 -> V_80 = V_54 ;
V_3 -> V_81 = V_9 -> V_61 ;
V_52 -> V_82 = V_9 -> V_61 ;
F_1 ( V_3 ) -> V_11 = V_9 -> V_66 ;
F_31 ( & V_37 ) ;
F_53 ( V_3 , & V_83 ) ;
F_36 ( V_3 ) ;
F_33 ( & V_37 ) ;
F_54 ( V_3 , V_57 ) ;
F_42 ( V_3 ) ;
return 0 ;
V_76:
F_52 () ;
V_70:
F_42 ( V_3 ) ;
return V_56 ;
V_67:
F_23 ( & V_37 ) ;
return V_56 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_46 * V_47 ,
int V_48 )
{
struct V_53 * V_84 = (struct V_53 * ) V_47 ;
struct V_74 * V_85 = (struct V_74 * ) V_47 ;
struct V_5 * V_38 ;
int V_55 ;
int V_86 ;
if ( F_47 ( V_3 , V_57 ) )
return - V_58 ;
if ( V_48 < sizeof( * V_84 ) )
return - V_58 ;
if ( V_85 -> V_87 != V_60 )
return - V_58 ;
V_55 = F_48 ( & V_85 -> V_88 ) ;
if ( V_55 & V_64 )
return - V_58 ;
if ( V_55 & V_62 ) {
V_38 = & V_85 -> V_88 ;
if ( F_56 ( V_38 -> V_89 [ 3 ] ) )
return - V_58 ;
}
V_86 = F_57 ( V_3 , V_47 , V_48 ) ;
F_40 ( V_3 ) ;
F_1 ( V_3 ) -> V_90 = V_84 -> V_66 ;
F_31 ( & V_37 ) ;
F_35 ( & V_3 -> V_45 ) ;
F_53 ( V_3 , & V_83 ) ;
F_33 ( & V_37 ) ;
F_42 ( V_3 ) ;
return V_86 ;
}
static int F_58 ( struct V_2 * V_3 , int V_91 )
{
if ( F_47 ( V_3 , V_57 ) )
return 0 ;
return F_59 ( V_3 , V_91 ) ;
}
static int F_60 ( struct V_92 * V_2 , struct V_46 * V_47 ,
int * V_93 , int V_94 )
{
struct V_53 * V_84 = (struct V_53 * ) V_47 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_51 * V_52 = F_46 ( V_3 ) ;
struct V_1 * V_95 = F_1 ( V_3 ) ;
V_84 -> V_59 = V_60 ;
V_84 -> V_96 = 0 ;
V_84 -> V_75 = 0 ;
V_84 -> V_97 = 0 ;
if ( V_94 ) {
if ( ! V_95 -> V_90 )
return - V_98 ;
V_84 -> V_66 = V_95 -> V_90 ;
V_84 -> V_61 = V_3 -> V_99 ;
if ( V_52 -> V_100 )
V_84 -> V_96 = V_52 -> V_101 ;
} else {
if ( F_61 ( & V_3 -> V_81 ) )
V_84 -> V_61 = V_52 -> V_82 ;
else
V_84 -> V_61 = V_3 -> V_81 ;
V_84 -> V_66 = V_95 -> V_11 ;
}
if ( F_48 ( & V_84 -> V_61 ) & V_73 )
V_84 -> V_75 = V_3 -> V_12 ;
* V_93 = sizeof( * V_84 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_86 ;
V_86 = F_63 ( V_3 , V_15 ) ;
if ( V_86 < 0 )
goto V_102;
return 0 ;
V_102:
F_64 ( F_6 ( V_3 ) , V_103 ) ;
F_28 ( V_15 ) ;
return - 1 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_27 * V_104 = NULL ;
int V_56 = 0 ;
V_15 = F_66 ( & V_3 -> V_105 ) ;
if ( V_15 == NULL )
goto V_106;
V_104 = ( V_27 * ) F_67 ( V_15 ) ;
* V_104 = 0 ;
V_56 = F_68 ( V_3 ) ;
V_106:
return V_56 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_107 * V_108 , T_2 V_31 )
{
struct V_109 V_110 ;
F_70 ( struct V_53 * , V_84 , V_108 -> V_111 ) ;
struct V_5 * V_38 , * V_112 , V_113 ;
struct V_51 * V_52 = F_46 ( V_3 ) ;
struct V_109 * V_114 = NULL ;
struct V_109 * V_115 = NULL ;
struct V_116 * V_117 = NULL ;
struct V_118 * V_119 = NULL ;
struct V_120 V_121 ;
struct V_122 V_123 = { 0 } ;
struct V_124 V_125 ;
int V_48 = V_108 -> V_126 ;
int V_127 = 4 ;
int V_128 = V_31 + V_127 ;
int V_56 ;
if ( V_31 > V_129 )
return - V_130 ;
if ( V_108 -> V_131 & V_132 )
return - V_133 ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_121 . V_134 = V_3 -> V_135 ;
V_125 . V_136 = - 1 ;
V_125 . V_137 = - 1 ;
V_125 . V_138 = - 1 ;
if ( V_84 ) {
if ( V_48 < V_139 )
return - V_58 ;
if ( V_84 -> V_59 && V_84 -> V_59 != V_60 )
return - V_140 ;
V_38 = & V_84 -> V_61 ;
if ( V_52 -> V_100 ) {
V_121 . V_117 = V_84 -> V_96 & V_141 ;
if ( V_121 . V_117 & V_142 ) {
V_117 = F_71 ( V_3 , V_121 . V_117 ) ;
if ( V_117 == NULL )
return - V_58 ;
}
}
if ( V_3 -> V_68 == V_143 &&
F_7 ( V_38 , & V_3 -> V_99 ) )
V_38 = & V_3 -> V_99 ;
if ( V_48 >= sizeof( struct V_74 ) &&
V_84 -> V_75 &&
F_48 ( V_38 ) & V_73 )
V_121 . V_144 = V_84 -> V_75 ;
} else {
if ( V_3 -> V_68 != V_143 )
return - V_145 ;
V_38 = & V_3 -> V_99 ;
V_121 . V_117 = V_52 -> V_101 ;
}
if ( V_121 . V_144 == 0 )
V_121 . V_144 = V_3 -> V_12 ;
if ( V_108 -> V_146 ) {
V_115 = & V_110 ;
memset ( V_115 , 0 , sizeof( struct V_109 ) ) ;
V_115 -> V_147 = sizeof( struct V_109 ) ;
V_125 . V_115 = V_115 ;
V_56 = F_72 ( F_6 ( V_3 ) , V_3 , V_108 , & V_121 , & V_125 ,
& V_123 ) ;
if ( V_56 < 0 ) {
F_73 ( V_117 ) ;
return V_56 ;
}
if ( ( V_121 . V_117 & V_142 ) && ! V_117 ) {
V_117 = F_71 ( V_3 , V_121 . V_117 ) ;
if ( V_117 == NULL )
return - V_58 ;
}
if ( ! ( V_115 -> V_148 | V_115 -> V_149 ) )
V_115 = NULL ;
}
if ( ! V_115 ) {
V_115 = F_74 ( V_52 ) ;
V_114 = V_115 ;
}
if ( V_117 )
V_115 = F_75 ( & V_110 , V_117 , V_115 ) ;
V_115 = F_76 ( & V_110 , V_115 ) ;
V_125 . V_115 = V_115 ;
V_121 . V_150 = V_3 -> V_151 ;
if ( ! F_61 ( V_38 ) )
V_121 . V_38 = * V_38 ;
else
V_121 . V_38 . V_152 [ 15 ] = 0x1 ;
if ( F_61 ( & V_121 . V_82 ) && ! F_61 ( & V_52 -> V_82 ) )
V_121 . V_82 = V_52 -> V_82 ;
V_112 = F_77 ( & V_121 , V_115 , & V_113 ) ;
if ( ! V_121 . V_144 && F_78 ( & V_121 . V_38 ) )
V_121 . V_144 = V_52 -> V_153 ;
else if ( ! V_121 . V_144 )
V_121 . V_144 = V_52 -> V_154 ;
F_79 ( V_3 , F_80 ( & V_121 ) ) ;
V_119 = F_81 ( V_3 , & V_121 , V_112 ) ;
if ( F_82 ( V_119 ) ) {
V_56 = F_83 ( V_119 ) ;
goto V_106;
}
if ( V_125 . V_136 < 0 )
V_125 . V_136 = F_84 ( V_52 , & V_121 , V_119 ) ;
if ( V_125 . V_137 < 0 )
V_125 . V_137 = V_52 -> V_137 ;
if ( V_125 . V_138 < 0 )
V_125 . V_138 = V_52 -> V_138 ;
if ( V_108 -> V_131 & V_155 )
goto V_156;
V_157:
F_40 ( V_3 ) ;
V_56 = F_85 ( V_3 , V_158 , V_108 ,
V_128 , V_127 , & V_125 ,
& V_121 , (struct V_159 * ) V_119 ,
V_108 -> V_131 , & V_123 ) ;
if ( V_56 )
F_41 ( V_3 ) ;
else if ( ! ( V_108 -> V_131 & V_160 ) )
V_56 = F_65 ( V_3 ) ;
F_42 ( V_3 ) ;
V_161:
F_86 ( V_119 ) ;
V_106:
F_73 ( V_117 ) ;
F_87 ( V_114 ) ;
return V_56 < 0 ? V_56 : V_31 ;
V_156:
F_88 ( V_119 ) ;
if ( ! ( V_108 -> V_131 & V_162 ) || V_31 )
goto V_157;
V_56 = 0 ;
goto V_161;
}
static int F_89 ( struct V_2 * V_3 , struct V_107 * V_108 , T_2 V_31 ,
int V_163 , int V_91 , int * V_48 )
{
struct V_51 * V_52 = F_46 ( V_3 ) ;
F_70 ( struct V_53 * , V_84 , V_108 -> V_111 ) ;
T_2 V_164 = 0 ;
int V_56 = - V_133 ;
struct V_14 * V_15 ;
if ( V_91 & V_132 )
goto V_106;
if ( V_48 )
* V_48 = sizeof( * V_84 ) ;
if ( V_91 & V_165 )
return F_90 ( V_3 , V_108 , V_31 , V_48 ) ;
V_15 = F_91 ( V_3 , V_91 , V_163 , & V_56 ) ;
if ( ! V_15 )
goto V_106;
V_164 = V_15 -> V_31 ;
if ( V_31 < V_164 ) {
V_108 -> V_131 |= V_166 ;
V_164 = V_31 ;
}
V_56 = F_92 ( V_15 , 0 , V_108 , V_164 ) ;
if ( V_56 )
goto V_161;
F_93 ( V_108 , V_3 , V_15 ) ;
if ( V_84 ) {
V_84 -> V_59 = V_60 ;
V_84 -> V_97 = 0 ;
V_84 -> V_61 = F_21 ( V_15 ) -> V_82 ;
V_84 -> V_96 = 0 ;
V_84 -> V_75 = 0 ;
V_84 -> V_66 = 0 ;
if ( F_48 ( & V_84 -> V_61 ) & V_73 )
V_84 -> V_75 = F_94 ( V_15 ) ;
}
if ( V_52 -> V_167 . V_168 )
F_95 ( V_3 , V_108 , V_15 ) ;
if ( V_91 & V_166 )
V_164 = V_15 -> V_31 ;
V_161:
F_96 ( V_3 , V_15 ) ;
V_106:
return V_56 ? V_56 : V_164 ;
}
static int T_3 F_97 ( void )
{
int V_56 ;
F_98 ( L_3 ) ;
V_56 = F_99 ( & V_169 , 1 ) ;
if ( V_56 != 0 )
goto V_106;
V_56 = F_100 ( & V_170 , V_42 ) ;
if ( V_56 )
goto V_171;
F_101 ( & V_172 ) ;
return 0 ;
V_171:
F_102 ( & V_169 ) ;
V_106:
return V_56 ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_172 ) ;
F_105 ( & V_170 , V_42 ) ;
F_102 ( & V_169 ) ;
}
