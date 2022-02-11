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
V_87 -> V_99 = 0 ;
if ( V_96 ) {
if ( ! V_97 -> V_92 )
return - V_100 ;
V_87 -> V_68 = V_97 -> V_92 ;
V_87 -> V_63 = V_54 -> V_40 ;
if ( V_54 -> V_101 )
V_87 -> V_98 = V_54 -> V_102 ;
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
goto V_103;
return 0 ;
V_103:
F_61 ( & V_30 , V_104 ) ;
F_27 ( V_17 ) ;
return - 1 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_16 * V_17 ;
V_28 * V_105 = NULL ;
int V_58 = 0 ;
V_17 = F_63 ( & V_3 -> V_106 ) ;
if ( V_17 == NULL )
goto V_107;
V_105 = ( V_28 * ) F_64 ( V_17 ) ;
* V_105 = 0 ;
V_58 = F_65 ( V_3 ) ;
V_107:
return V_58 ;
}
static int F_66 ( struct V_108 * V_109 , struct V_2 * V_3 ,
struct V_110 * V_111 , T_2 V_33 )
{
struct V_112 V_113 ;
struct V_55 * V_87 =
(struct V_55 * ) V_111 -> V_114 ;
struct V_5 * V_40 , * V_115 , V_116 ;
struct V_53 * V_54 = F_43 ( V_3 ) ;
struct V_112 * V_117 = NULL ;
struct V_118 * V_119 = NULL ;
struct V_120 * V_121 = NULL ;
struct V_122 V_123 ;
int V_50 = V_111 -> V_124 ;
int V_125 = - 1 ;
int V_126 = - 1 ;
int V_127 = - 1 ;
int V_128 = 4 ;
int V_129 = V_33 + V_128 ;
int V_58 ;
if ( V_33 > V_130 )
return - V_131 ;
if ( V_111 -> V_132 & V_133 )
return - V_134 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_135 = V_3 -> V_136 ;
if ( V_87 ) {
if ( V_50 < V_137 )
return - V_60 ;
if ( V_87 -> V_61 && V_87 -> V_61 != V_62 )
return - V_138 ;
V_40 = & V_87 -> V_63 ;
if ( V_54 -> V_101 ) {
V_123 . V_119 = V_87 -> V_98 & V_139 ;
if ( V_123 . V_119 & V_140 ) {
V_119 = F_67 ( V_3 , V_123 . V_119 ) ;
if ( V_119 == NULL )
return - V_60 ;
V_40 = & V_119 -> V_121 ;
}
}
if ( V_3 -> V_70 == V_141 &&
F_7 ( V_40 , & V_54 -> V_40 ) )
V_40 = & V_54 -> V_40 ;
if ( V_50 >= sizeof( struct V_77 ) &&
V_87 -> V_78 &&
F_45 ( V_40 ) & V_76 )
V_123 . V_142 = V_87 -> V_78 ;
} else {
if ( V_3 -> V_70 != V_141 )
return - V_143 ;
V_40 = & V_54 -> V_40 ;
V_123 . V_119 = V_54 -> V_102 ;
}
if ( V_123 . V_142 == 0 )
V_123 . V_142 = V_3 -> V_14 ;
if ( V_111 -> V_144 ) {
V_117 = & V_113 ;
memset ( V_117 , 0 , sizeof( struct V_112 ) ) ;
V_117 -> V_145 = sizeof( struct V_112 ) ;
V_58 = F_68 ( F_6 ( V_3 ) , V_3 , V_111 , & V_123 , V_117 ,
& V_125 , & V_126 , & V_127 ) ;
if ( V_58 < 0 ) {
F_69 ( V_119 ) ;
return V_58 ;
}
if ( ( V_123 . V_119 & V_140 ) && ! V_119 ) {
V_119 = F_67 ( V_3 , V_123 . V_119 ) ;
if ( V_119 == NULL )
return - V_60 ;
}
if ( ! ( V_117 -> V_146 | V_117 -> V_147 ) )
V_117 = NULL ;
}
if ( V_117 == NULL )
V_117 = V_54 -> V_117 ;
if ( V_119 )
V_117 = F_70 ( & V_113 , V_119 , V_117 ) ;
V_117 = F_71 ( & V_113 , V_117 ) ;
V_123 . V_148 = V_3 -> V_149 ;
if ( ! F_58 ( V_40 ) )
V_123 . V_40 = * V_40 ;
else
V_123 . V_40 . V_150 [ 15 ] = 0x1 ;
if ( F_58 ( & V_123 . V_85 ) && ! F_58 ( & V_54 -> V_85 ) )
V_123 . V_85 = V_54 -> V_85 ;
V_115 = F_72 ( & V_123 , V_117 , & V_116 ) ;
if ( ! V_123 . V_142 && F_73 ( & V_123 . V_40 ) )
V_123 . V_142 = V_54 -> V_151 ;
else if ( ! V_123 . V_142 )
V_123 . V_142 = V_54 -> V_152 ;
F_74 ( V_3 , F_75 ( & V_123 ) ) ;
V_121 = F_76 ( V_3 , & V_123 , V_115 , true ) ;
if ( F_77 ( V_121 ) ) {
V_58 = F_78 ( V_121 ) ;
goto V_107;
}
if ( V_125 < 0 ) {
if ( F_73 ( & V_123 . V_40 ) )
V_125 = V_54 -> V_153 ;
else
V_125 = V_54 -> V_154 ;
if ( V_125 < 0 )
V_125 = F_79 ( V_121 ) ;
}
if ( V_126 < 0 )
V_126 = V_54 -> V_126 ;
if ( V_127 < 0 )
V_127 = V_54 -> V_127 ;
if ( V_111 -> V_132 & V_155 )
goto V_156;
V_157:
F_38 ( V_3 ) ;
V_58 = F_80 ( V_3 , V_158 , V_111 -> V_159 ,
V_129 , V_128 , V_125 , V_126 , V_117 ,
& V_123 , (struct V_160 * ) V_121 ,
V_111 -> V_132 , V_127 ) ;
if ( V_58 )
F_39 ( V_3 ) ;
else if ( ! ( V_111 -> V_132 & V_161 ) )
V_58 = F_62 ( V_3 ) ;
F_40 ( V_3 ) ;
V_162:
F_81 ( V_121 ) ;
V_107:
F_69 ( V_119 ) ;
return V_58 < 0 ? V_58 : V_33 ;
V_156:
F_82 ( V_121 ) ;
if ( ! ( V_111 -> V_132 & V_163 ) || V_33 )
goto V_157;
V_58 = 0 ;
goto V_162;
}
static int F_83 ( struct V_108 * V_109 , struct V_2 * V_3 ,
struct V_110 * V_111 , T_2 V_33 , int V_164 ,
int V_93 , int * V_50 )
{
struct V_51 * V_52 = F_29 ( V_3 ) ;
struct V_55 * V_87 = (struct V_55 * ) V_111 -> V_114 ;
T_2 V_165 = 0 ;
int V_58 = - V_134 ;
struct V_16 * V_17 ;
if ( V_93 & V_133 )
goto V_107;
if ( V_50 )
* V_50 = sizeof( * V_87 ) ;
if ( V_93 & V_166 )
return F_84 ( V_3 , V_111 , V_33 ) ;
V_17 = F_85 ( V_3 , V_93 , V_164 , & V_58 ) ;
if ( ! V_17 )
goto V_107;
V_165 = V_17 -> V_33 ;
if ( V_33 < V_165 ) {
V_111 -> V_132 |= V_167 ;
V_165 = V_33 ;
}
V_58 = F_86 ( V_17 , 0 , V_111 -> V_159 , V_165 ) ;
if ( V_58 )
goto V_162;
F_87 ( V_111 , V_3 , V_17 ) ;
if ( V_87 ) {
V_87 -> V_61 = V_62 ;
V_87 -> V_99 = 0 ;
V_87 -> V_63 = F_20 ( V_17 ) -> V_85 ;
V_87 -> V_98 = 0 ;
V_87 -> V_78 = 0 ;
if ( F_45 ( & V_87 -> V_63 ) & V_76 )
V_87 -> V_78 = F_88 ( V_17 ) -> V_168 ;
}
if ( V_52 -> V_169 )
F_89 ( V_111 , V_17 ) ;
if ( V_93 & V_167 )
V_165 = V_17 -> V_33 ;
V_162:
F_90 ( V_3 , V_17 ) ;
V_107:
return V_58 ? V_58 : V_165 ;
}
static int T_3 F_91 ( void )
{
int V_58 ;
F_92 ( L_3 ) ;
V_58 = F_93 ( & V_170 , 1 ) ;
if ( V_58 != 0 )
goto V_107;
V_58 = F_94 ( & V_171 , V_44 ) ;
if ( V_58 )
goto V_172;
F_95 ( & V_173 ) ;
return 0 ;
V_172:
F_96 ( & V_170 ) ;
V_107:
return V_58 ;
}
static void T_4 F_97 ( void )
{
F_98 ( & V_173 ) ;
F_99 ( & V_171 , V_44 ) ;
F_96 ( & V_170 ) ;
}
