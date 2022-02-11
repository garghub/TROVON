static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( struct V_4 * V_4 ,
struct V_5 * V_6 ,
int V_7 , T_1 V_8 )
{
struct V_9 * V_10 ;
struct V_2 * V_3 ;
F_3 (sk, node, &l2tp_ip6_bind_table) {
struct V_5 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 == NULL )
continue;
if ( ( V_12 -> V_13 == V_8 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
! ( V_11 && F_7 ( V_11 , V_6 ) ) &&
! ( V_3 -> V_14 && V_3 -> V_14 != V_7 ) )
goto V_15;
}
V_3 = NULL ;
V_15:
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
static int F_10 ( struct V_16 * V_17 )
{
struct V_2 * V_3 ;
T_1 V_18 ;
T_1 V_8 ;
unsigned char * V_19 , * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 = NULL ;
int V_25 ;
V_20 = V_19 = V_17 -> V_26 ;
if ( ! F_11 ( V_17 , 4 ) )
goto V_27;
V_18 = F_12 ( * ( ( V_28 * ) V_19 ) ) ;
V_19 += 4 ;
if ( V_18 == 0 ) {
F_13 ( V_17 , 4 ) ;
goto V_29;
}
V_22 = F_14 ( & V_30 , NULL , V_18 ) ;
if ( V_22 == NULL )
goto V_27;
V_24 = V_22 -> V_24 ;
if ( V_24 == NULL )
goto V_27;
if ( V_24 -> V_31 & V_32 ) {
V_25 = F_15 ( 32u , V_17 -> V_33 ) ;
if ( ! F_11 ( V_17 , V_25 ) )
goto V_27;
F_16 ( L_1 , V_24 -> V_34 ) ;
F_17 ( L_2 , V_35 , V_19 , V_25 ) ;
}
F_18 ( V_22 , V_17 , V_19 , V_20 , 0 , V_17 -> V_33 ,
V_24 -> V_36 ) ;
return 0 ;
V_29:
if ( ! F_11 ( V_17 , 12 ) )
goto V_27;
if ( ( V_17 -> V_26 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_27;
V_8 = F_12 ( * ( V_28 * ) & V_17 -> V_26 [ 4 ] ) ;
V_24 = F_19 ( & V_30 , V_8 ) ;
if ( V_24 != NULL )
V_3 = V_24 -> V_2 ;
else {
struct V_37 * V_38 = F_20 ( V_17 ) ;
F_21 ( & V_39 ) ;
V_3 = F_2 ( & V_30 , & V_38 -> V_40 ,
0 , V_8 ) ;
F_22 ( & V_39 ) ;
}
if ( V_3 == NULL )
goto V_27;
F_9 ( V_3 ) ;
if ( ! F_23 ( V_3 , V_41 , V_17 ) )
goto V_42;
F_24 ( V_17 ) ;
return F_25 ( V_3 , V_17 , 1 ) ;
V_42:
F_26 ( V_3 ) ;
V_27:
F_27 ( V_17 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
F_29 ( V_3 ) -> V_43 = V_44 ;
F_30 ( & V_39 ) ;
F_31 ( V_3 , & V_45 ) ;
F_32 ( & V_39 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 , long V_46 )
{
F_30 ( & V_39 ) ;
F_34 ( & V_3 -> V_47 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_39 ) ;
F_36 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
}
static int F_42 ( struct V_2 * V_3 , struct V_48 * V_49 , int V_50 )
{
struct V_51 * V_52 = F_29 ( V_3 ) ;
struct V_53 * V_54 = F_43 ( V_3 ) ;
struct V_55 * V_11 = (struct V_55 * ) V_49 ;
V_28 V_56 = 0 ;
int V_57 ;
int V_58 ;
if ( ! F_44 ( V_3 , V_59 ) )
return - V_60 ;
if ( V_11 -> V_61 != V_62 )
return - V_60 ;
if ( V_50 < sizeof( * V_11 ) )
return - V_60 ;
V_57 = F_45 ( & V_11 -> V_63 ) ;
if ( V_57 == V_64 )
return - V_65 ;
if ( V_57 & V_66 )
return - V_65 ;
V_58 = - V_67 ;
F_21 ( & V_39 ) ;
if ( F_2 ( & V_30 , & V_11 -> V_63 ,
V_3 -> V_14 , V_11 -> V_68 ) )
goto V_69;
F_22 ( & V_39 ) ;
F_38 ( V_3 ) ;
V_58 = - V_60 ;
if ( V_3 -> V_70 != V_71 )
goto V_72;
F_46 () ;
if ( V_57 != V_73 ) {
struct V_74 * V_75 = NULL ;
if ( V_57 & V_76 ) {
if ( V_50 >= sizeof( struct V_77 ) &&
V_11 -> V_78 ) {
V_3 -> V_14 = V_11 -> V_78 ;
}
if ( ! V_3 -> V_14 )
goto V_79;
V_58 = - V_80 ;
V_75 = F_47 ( F_6 ( V_3 ) ,
V_3 -> V_14 ) ;
if ( ! V_75 )
goto V_79;
}
V_56 = V_81 ;
V_58 = - V_65 ;
if ( ! F_48 ( F_6 ( V_3 ) , & V_11 -> V_63 , V_75 , 0 ) )
goto V_79;
}
F_49 () ;
V_52 -> V_82 = V_52 -> V_83 = V_56 ;
V_54 -> V_84 = V_11 -> V_63 ;
V_54 -> V_85 = V_11 -> V_63 ;
F_1 ( V_3 ) -> V_13 = V_11 -> V_68 ;
F_30 ( & V_39 ) ;
F_50 ( V_3 , & V_86 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_39 ) ;
F_51 ( V_3 , V_59 ) ;
F_40 ( V_3 ) ;
return 0 ;
V_79:
F_49 () ;
V_72:
F_40 ( V_3 ) ;
return V_58 ;
V_69:
F_22 ( & V_39 ) ;
return V_58 ;
}
static int F_52 ( struct V_2 * V_3 , struct V_48 * V_49 ,
int V_50 )
{
struct V_55 * V_87 = (struct V_55 * ) V_49 ;
struct V_77 * V_88 = (struct V_77 * ) V_49 ;
struct V_5 * V_40 ;
int V_57 ;
int V_89 ;
if ( F_44 ( V_3 , V_59 ) )
return - V_60 ;
if ( V_50 < sizeof( * V_87 ) )
return - V_60 ;
V_57 = F_45 ( & V_88 -> V_90 ) ;
if ( V_57 & V_66 )
return - V_60 ;
if ( V_57 & V_64 ) {
V_40 = & V_88 -> V_90 ;
if ( F_53 ( V_40 -> V_91 [ 3 ] ) )
return - V_60 ;
}
V_89 = F_54 ( V_3 , V_49 , V_50 ) ;
F_38 ( V_3 ) ;
F_1 ( V_3 ) -> V_92 = V_87 -> V_68 ;
F_30 ( & V_39 ) ;
F_34 ( & V_3 -> V_47 ) ;
F_50 ( V_3 , & V_86 ) ;
F_32 ( & V_39 ) ;
F_40 ( V_3 ) ;
return V_89 ;
}
static int F_55 ( struct V_2 * V_3 , int V_93 )
{
if ( F_44 ( V_3 , V_59 ) )
return 0 ;
return F_56 ( V_3 , V_93 ) ;
}
static int F_57 ( struct V_94 * V_2 , struct V_48 * V_49 ,
int * V_95 , int V_96 )
{
struct V_55 * V_87 = (struct V_55 * ) V_49 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_53 * V_54 = F_43 ( V_3 ) ;
struct V_1 * V_97 = F_1 ( V_3 ) ;
V_87 -> V_61 = V_62 ;
V_87 -> V_98 = 0 ;
V_87 -> V_78 = 0 ;
if ( V_96 ) {
if ( ! V_97 -> V_92 )
return - V_99 ;
V_87 -> V_68 = V_97 -> V_92 ;
V_87 -> V_63 = V_54 -> V_40 ;
if ( V_54 -> V_100 )
V_87 -> V_98 = V_54 -> V_101 ;
} else {
if ( F_58 ( & V_54 -> V_84 ) )
V_87 -> V_63 = V_54 -> V_85 ;
else
V_87 -> V_63 = V_54 -> V_84 ;
V_87 -> V_68 = V_97 -> V_13 ;
}
if ( F_45 ( & V_87 -> V_63 ) & V_76 )
V_87 -> V_78 = V_3 -> V_14 ;
* V_95 = sizeof( * V_87 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
int V_89 ;
V_89 = F_60 ( V_3 , V_17 ) ;
if ( V_89 < 0 )
goto V_102;
return 0 ;
V_102:
F_61 ( & V_30 , V_103 ) ;
F_27 ( V_17 ) ;
return - 1 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_16 * V_17 ;
V_28 * V_104 = NULL ;
int V_58 = 0 ;
V_17 = F_63 ( & V_3 -> V_105 ) ;
if ( V_17 == NULL )
goto V_106;
V_104 = ( V_28 * ) F_64 ( V_17 ) ;
* V_104 = 0 ;
V_58 = F_65 ( V_3 ) ;
V_106:
return V_58 ;
}
static int F_66 ( struct V_107 * V_108 , struct V_2 * V_3 ,
struct V_109 * V_110 , T_2 V_33 )
{
struct V_111 V_112 ;
struct V_55 * V_87 =
(struct V_55 * ) V_110 -> V_113 ;
struct V_5 * V_40 , * V_114 , V_115 ;
struct V_53 * V_54 = F_43 ( V_3 ) ;
struct V_111 * V_116 = NULL ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 = NULL ;
struct V_121 V_122 ;
int V_50 = V_110 -> V_123 ;
int V_124 = - 1 ;
int V_125 = - 1 ;
int V_126 = - 1 ;
int V_127 = 4 ;
int V_128 = V_33 + V_127 ;
int V_58 ;
if ( V_33 > V_129 )
return - V_130 ;
if ( V_110 -> V_131 & V_132 )
return - V_133 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_134 = V_3 -> V_135 ;
if ( V_87 ) {
if ( V_50 < V_136 )
return - V_60 ;
if ( V_87 -> V_61 && V_87 -> V_61 != V_62 )
return - V_137 ;
V_40 = & V_87 -> V_63 ;
if ( V_54 -> V_100 ) {
V_122 . V_118 = V_87 -> V_98 & V_138 ;
if ( V_122 . V_118 & V_139 ) {
V_118 = F_67 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_60 ;
V_40 = & V_118 -> V_120 ;
}
}
if ( V_3 -> V_70 == V_140 &&
F_7 ( V_40 , & V_54 -> V_40 ) )
V_40 = & V_54 -> V_40 ;
if ( V_50 >= sizeof( struct V_77 ) &&
V_87 -> V_78 &&
F_45 ( V_40 ) & V_76 )
V_122 . V_141 = V_87 -> V_78 ;
} else {
if ( V_3 -> V_70 != V_140 )
return - V_142 ;
V_40 = & V_54 -> V_40 ;
V_122 . V_118 = V_54 -> V_101 ;
}
if ( V_122 . V_141 == 0 )
V_122 . V_141 = V_3 -> V_14 ;
if ( V_110 -> V_143 ) {
V_116 = & V_112 ;
memset ( V_116 , 0 , sizeof( struct V_111 ) ) ;
V_116 -> V_144 = sizeof( struct V_111 ) ;
V_58 = F_68 ( F_6 ( V_3 ) , V_3 , V_110 , & V_122 , V_116 ,
& V_124 , & V_125 , & V_126 ) ;
if ( V_58 < 0 ) {
F_69 ( V_118 ) ;
return V_58 ;
}
if ( ( V_122 . V_118 & V_139 ) && ! V_118 ) {
V_118 = F_67 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_60 ;
}
if ( ! ( V_116 -> V_145 | V_116 -> V_146 ) )
V_116 = NULL ;
}
if ( V_116 == NULL )
V_116 = V_54 -> V_116 ;
if ( V_118 )
V_116 = F_70 ( & V_112 , V_118 , V_116 ) ;
V_116 = F_71 ( & V_112 , V_116 ) ;
V_122 . V_147 = V_3 -> V_148 ;
if ( ! F_58 ( V_40 ) )
V_122 . V_40 = * V_40 ;
else
V_122 . V_40 . V_149 [ 15 ] = 0x1 ;
if ( F_58 ( & V_122 . V_85 ) && ! F_58 ( & V_54 -> V_85 ) )
V_122 . V_85 = V_54 -> V_85 ;
V_114 = F_72 ( & V_122 , V_116 , & V_115 ) ;
if ( ! V_122 . V_141 && F_73 ( & V_122 . V_40 ) )
V_122 . V_141 = V_54 -> V_150 ;
else if ( ! V_122 . V_141 )
V_122 . V_141 = V_54 -> V_151 ;
F_74 ( V_3 , F_75 ( & V_122 ) ) ;
V_120 = F_76 ( V_3 , & V_122 , V_114 , true ) ;
if ( F_77 ( V_120 ) ) {
V_58 = F_78 ( V_120 ) ;
goto V_106;
}
if ( V_124 < 0 ) {
if ( F_73 ( & V_122 . V_40 ) )
V_124 = V_54 -> V_152 ;
else
V_124 = V_54 -> V_153 ;
if ( V_124 < 0 )
V_124 = F_79 ( V_120 ) ;
}
if ( V_125 < 0 )
V_125 = V_54 -> V_125 ;
if ( V_126 < 0 )
V_126 = V_54 -> V_126 ;
if ( V_110 -> V_131 & V_154 )
goto V_155;
V_156:
F_38 ( V_3 ) ;
V_58 = F_80 ( V_3 , V_157 , V_110 -> V_158 ,
V_128 , V_127 , V_124 , V_125 , V_116 ,
& V_122 , (struct V_159 * ) V_120 ,
V_110 -> V_131 , V_126 ) ;
if ( V_58 )
F_39 ( V_3 ) ;
else if ( ! ( V_110 -> V_131 & V_160 ) )
V_58 = F_62 ( V_3 ) ;
F_40 ( V_3 ) ;
V_161:
F_81 ( V_120 ) ;
V_106:
F_69 ( V_118 ) ;
return V_58 < 0 ? V_58 : V_33 ;
V_155:
F_82 ( V_120 ) ;
if ( ! ( V_110 -> V_131 & V_162 ) || V_33 )
goto V_156;
V_58 = 0 ;
goto V_161;
}
static int F_83 ( struct V_107 * V_108 , struct V_2 * V_3 ,
struct V_109 * V_110 , T_2 V_33 , int V_163 ,
int V_93 , int * V_50 )
{
struct V_51 * V_52 = F_29 ( V_3 ) ;
struct V_55 * V_87 = (struct V_55 * ) V_110 -> V_113 ;
T_2 V_164 = 0 ;
int V_58 = - V_133 ;
struct V_16 * V_17 ;
if ( V_93 & V_132 )
goto V_106;
if ( V_50 )
* V_50 = sizeof( * V_87 ) ;
if ( V_93 & V_165 )
return F_84 ( V_3 , V_110 , V_33 ) ;
V_17 = F_85 ( V_3 , V_93 , V_163 , & V_58 ) ;
if ( ! V_17 )
goto V_106;
V_164 = V_17 -> V_33 ;
if ( V_33 < V_164 ) {
V_110 -> V_131 |= V_166 ;
V_164 = V_33 ;
}
V_58 = F_86 ( V_17 , 0 , V_110 -> V_158 , V_164 ) ;
if ( V_58 )
goto V_161;
F_87 ( V_110 , V_3 , V_17 ) ;
if ( V_87 ) {
V_87 -> V_61 = V_62 ;
V_87 -> V_167 = 0 ;
V_87 -> V_63 = F_20 ( V_17 ) -> V_85 ;
V_87 -> V_98 = 0 ;
V_87 -> V_78 = 0 ;
if ( F_45 ( & V_87 -> V_63 ) & V_76 )
V_87 -> V_78 = F_88 ( V_17 ) -> V_168 ;
}
if ( V_52 -> V_169 )
F_89 ( V_110 , V_17 ) ;
if ( V_93 & V_166 )
V_164 = V_17 -> V_33 ;
V_161:
F_90 ( V_3 , V_17 ) ;
V_106:
return V_58 ? V_58 : V_164 ;
}
static int T_3 F_91 ( void )
{
int V_58 ;
F_92 ( L_3 ) ;
V_58 = F_93 ( & V_170 , 1 ) ;
if ( V_58 != 0 )
goto V_106;
V_58 = F_94 ( & V_171 , V_44 ) ;
if ( V_58 )
goto V_172;
F_95 ( & V_173 ) ;
return 0 ;
V_172:
F_96 ( & V_170 ) ;
V_106:
return V_58 ;
}
static void T_4 F_97 ( void )
{
F_98 ( & V_173 ) ;
F_99 ( & V_171 , V_44 ) ;
F_96 ( & V_170 ) ;
}
