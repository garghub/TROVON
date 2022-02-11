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
( ! V_9 || F_7 ( V_9 , V_6 ) ) &&
( ! V_3 -> V_12 || ! V_7 ||
V_3 -> V_12 == V_7 ) )
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
V_3 = F_2 ( V_4 , & V_36 -> V_38 , F_23 ( V_15 ) ,
V_8 ) ;
if ( ! V_3 ) {
F_24 ( & V_37 ) ;
goto V_25;
}
F_9 ( V_3 ) ;
F_24 ( & V_37 ) ;
}
if ( ! F_25 ( V_3 , V_39 , V_15 ) )
goto V_40;
F_26 ( V_15 ) ;
return F_27 ( V_3 , V_15 , 1 ) ;
V_40:
F_28 ( V_3 ) ;
V_25:
F_29 ( V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
F_31 ( V_3 ) -> V_41 = V_42 ;
F_32 ( & V_37 ) ;
F_33 ( V_3 , & V_43 ) ;
F_34 ( & V_37 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , long V_44 )
{
F_32 ( & V_37 ) ;
F_36 ( & V_3 -> V_45 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_37 ) ;
F_38 ( V_3 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
if ( V_23 ) {
F_44 ( V_23 ) ;
F_28 ( V_3 ) ;
}
F_45 ( V_3 ) ;
}
static int F_46 ( struct V_2 * V_3 , struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_50 = F_31 ( V_3 ) ;
struct V_51 * V_52 = F_47 ( V_3 ) ;
struct V_53 * V_9 = (struct V_53 * ) V_47 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
V_27 V_54 = 0 ;
int V_55 ;
int V_56 ;
int V_57 ;
if ( V_9 -> V_58 != V_59 )
return - V_60 ;
if ( V_48 < sizeof( * V_9 ) )
return - V_60 ;
V_56 = F_48 ( & V_9 -> V_61 ) ;
if ( V_56 == V_62 )
return - V_63 ;
if ( V_56 & V_64 )
return - V_63 ;
F_41 ( V_3 ) ;
V_57 = - V_60 ;
if ( ! F_49 ( V_3 , V_65 ) )
goto V_66;
if ( V_3 -> V_67 != V_68 )
goto V_66;
V_55 = V_3 -> V_12 ;
F_50 () ;
if ( V_56 != V_69 ) {
struct V_70 * V_16 = NULL ;
if ( V_56 & V_71 ) {
if ( V_9 -> V_72 )
V_55 = V_9 -> V_72 ;
if ( ! V_55 )
goto V_73;
V_57 = - V_74 ;
V_16 = F_51 ( F_6 ( V_3 ) , V_55 ) ;
if ( ! V_16 )
goto V_73;
}
V_54 = V_75 ;
V_57 = - V_63 ;
if ( ! F_52 ( F_6 ( V_3 ) , & V_9 -> V_61 , V_16 , 0 ) )
goto V_73;
}
F_53 () ;
F_32 ( & V_37 ) ;
if ( F_2 ( V_4 , & V_9 -> V_61 , V_55 ,
V_9 -> V_76 ) ) {
F_34 ( & V_37 ) ;
V_57 = - V_77 ;
goto V_66;
}
V_50 -> V_78 = V_54 ;
V_50 -> V_79 = V_54 ;
V_3 -> V_12 = V_55 ;
V_3 -> V_80 = V_9 -> V_61 ;
V_52 -> V_81 = V_9 -> V_61 ;
F_1 ( V_3 ) -> V_11 = V_9 -> V_76 ;
F_54 ( V_3 , & V_82 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_37 ) ;
F_55 ( V_3 , V_65 ) ;
F_43 ( V_3 ) ;
return 0 ;
V_73:
F_53 () ;
V_66:
F_43 ( V_3 ) ;
return V_57 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_46 * V_47 ,
int V_48 )
{
struct V_53 * V_83 = (struct V_53 * ) V_47 ;
struct V_84 * V_85 = (struct V_84 * ) V_47 ;
struct V_5 * V_38 ;
int V_56 ;
int V_86 ;
if ( V_48 < sizeof( * V_83 ) )
return - V_60 ;
if ( V_85 -> V_87 != V_59 )
return - V_60 ;
V_56 = F_48 ( & V_85 -> V_88 ) ;
if ( V_56 & V_64 )
return - V_60 ;
if ( V_56 & V_62 ) {
V_38 = & V_85 -> V_88 ;
if ( F_57 ( V_38 -> V_89 [ 3 ] ) )
return - V_60 ;
}
F_41 ( V_3 ) ;
if ( F_49 ( V_3 , V_65 ) ) {
V_86 = - V_60 ;
goto V_90;
}
V_86 = F_58 ( V_3 , V_47 , V_48 ) ;
if ( V_86 < 0 )
goto V_90;
F_1 ( V_3 ) -> V_91 = V_83 -> V_76 ;
F_32 ( & V_37 ) ;
F_36 ( & V_3 -> V_45 ) ;
F_54 ( V_3 , & V_82 ) ;
F_34 ( & V_37 ) ;
V_90:
F_43 ( V_3 ) ;
return V_86 ;
}
static int F_59 ( struct V_2 * V_3 , int V_92 )
{
if ( F_49 ( V_3 , V_65 ) )
return 0 ;
return F_60 ( V_3 , V_92 ) ;
}
static int F_61 ( struct V_93 * V_2 , struct V_46 * V_47 ,
int * V_94 , int V_95 )
{
struct V_53 * V_83 = (struct V_53 * ) V_47 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_51 * V_52 = F_47 ( V_3 ) ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
V_83 -> V_58 = V_59 ;
V_83 -> V_97 = 0 ;
V_83 -> V_72 = 0 ;
V_83 -> V_98 = 0 ;
if ( V_95 ) {
if ( ! V_96 -> V_91 )
return - V_99 ;
V_83 -> V_76 = V_96 -> V_91 ;
V_83 -> V_61 = V_3 -> V_100 ;
if ( V_52 -> V_101 )
V_83 -> V_97 = V_52 -> V_102 ;
} else {
if ( F_62 ( & V_3 -> V_80 ) )
V_83 -> V_61 = V_52 -> V_81 ;
else
V_83 -> V_61 = V_3 -> V_80 ;
V_83 -> V_76 = V_96 -> V_11 ;
}
if ( F_48 ( & V_83 -> V_61 ) & V_71 )
V_83 -> V_72 = V_3 -> V_12 ;
* V_94 = sizeof( * V_83 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_86 ;
V_86 = F_64 ( V_3 , V_15 ) ;
if ( V_86 < 0 )
goto V_103;
return 0 ;
V_103:
F_65 ( F_6 ( V_3 ) , V_104 ) ;
F_29 ( V_15 ) ;
return - 1 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_27 * V_105 = NULL ;
int V_57 = 0 ;
V_15 = F_67 ( & V_3 -> V_106 ) ;
if ( V_15 == NULL )
goto V_107;
V_105 = ( V_27 * ) F_68 ( V_15 ) ;
* V_105 = 0 ;
V_57 = F_69 ( V_3 ) ;
V_107:
return V_57 ;
}
static int F_70 ( struct V_2 * V_3 , struct V_108 * V_109 , T_2 V_31 )
{
struct V_110 V_111 ;
F_71 ( struct V_53 * , V_83 , V_109 -> V_112 ) ;
struct V_5 * V_38 , * V_113 , V_114 ;
struct V_51 * V_52 = F_47 ( V_3 ) ;
struct V_110 * V_115 = NULL ;
struct V_110 * V_116 = NULL ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 = NULL ;
struct V_121 V_122 ;
struct V_123 V_124 = { 0 } ;
struct V_125 V_126 ;
int V_48 = V_109 -> V_127 ;
int V_128 = 4 ;
int V_129 = V_31 + V_128 ;
int V_57 ;
if ( V_31 > V_130 )
return - V_131 ;
if ( V_109 -> V_132 & V_133 )
return - V_134 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_135 = V_3 -> V_136 ;
V_126 . V_137 = - 1 ;
V_126 . V_138 = - 1 ;
V_126 . V_139 = - 1 ;
if ( V_83 ) {
if ( V_48 < V_140 )
return - V_60 ;
if ( V_83 -> V_58 && V_83 -> V_58 != V_59 )
return - V_141 ;
V_38 = & V_83 -> V_61 ;
if ( V_52 -> V_101 ) {
V_122 . V_118 = V_83 -> V_97 & V_142 ;
if ( V_122 . V_118 & V_143 ) {
V_118 = F_72 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_60 ;
}
}
if ( V_3 -> V_67 == V_144 &&
F_7 ( V_38 , & V_3 -> V_100 ) )
V_38 = & V_3 -> V_100 ;
if ( V_48 >= sizeof( struct V_84 ) &&
V_83 -> V_72 &&
F_48 ( V_38 ) & V_71 )
V_122 . V_145 = V_83 -> V_72 ;
} else {
if ( V_3 -> V_67 != V_144 )
return - V_146 ;
V_38 = & V_3 -> V_100 ;
V_122 . V_118 = V_52 -> V_102 ;
}
if ( V_122 . V_145 == 0 )
V_122 . V_145 = V_3 -> V_12 ;
if ( V_109 -> V_147 ) {
V_116 = & V_111 ;
memset ( V_116 , 0 , sizeof( struct V_110 ) ) ;
V_116 -> V_148 = sizeof( struct V_110 ) ;
V_126 . V_116 = V_116 ;
V_57 = F_73 ( F_6 ( V_3 ) , V_3 , V_109 , & V_122 , & V_126 ,
& V_124 ) ;
if ( V_57 < 0 ) {
F_74 ( V_118 ) ;
return V_57 ;
}
if ( ( V_122 . V_118 & V_143 ) && ! V_118 ) {
V_118 = F_72 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_60 ;
}
if ( ! ( V_116 -> V_149 | V_116 -> V_150 ) )
V_116 = NULL ;
}
if ( ! V_116 ) {
V_116 = F_75 ( V_52 ) ;
V_115 = V_116 ;
}
if ( V_118 )
V_116 = F_76 ( & V_111 , V_118 , V_116 ) ;
V_116 = F_77 ( & V_111 , V_116 ) ;
V_126 . V_116 = V_116 ;
V_122 . V_151 = V_3 -> V_152 ;
if ( ! F_62 ( V_38 ) )
V_122 . V_38 = * V_38 ;
else
V_122 . V_38 . V_153 [ 15 ] = 0x1 ;
if ( F_62 ( & V_122 . V_81 ) && ! F_62 ( & V_52 -> V_81 ) )
V_122 . V_81 = V_52 -> V_81 ;
V_113 = F_78 ( & V_122 , V_116 , & V_114 ) ;
if ( ! V_122 . V_145 && F_79 ( & V_122 . V_38 ) )
V_122 . V_145 = V_52 -> V_154 ;
else if ( ! V_122 . V_145 )
V_122 . V_145 = V_52 -> V_155 ;
F_80 ( V_3 , F_81 ( & V_122 ) ) ;
if ( V_126 . V_138 < 0 )
V_126 . V_138 = V_52 -> V_138 ;
V_122 . V_118 = F_82 ( V_126 . V_138 , V_122 . V_118 ) ;
V_120 = F_83 ( V_3 , & V_122 , V_113 ) ;
if ( F_84 ( V_120 ) ) {
V_57 = F_85 ( V_120 ) ;
goto V_107;
}
if ( V_126 . V_137 < 0 )
V_126 . V_137 = F_86 ( V_52 , & V_122 , V_120 ) ;
if ( V_126 . V_139 < 0 )
V_126 . V_139 = V_52 -> V_139 ;
if ( V_109 -> V_132 & V_156 )
goto V_157;
V_158:
F_41 ( V_3 ) ;
V_57 = F_87 ( V_3 , V_159 , V_109 ,
V_129 , V_128 , & V_126 ,
& V_122 , (struct V_160 * ) V_120 ,
V_109 -> V_132 , & V_124 ) ;
if ( V_57 )
F_42 ( V_3 ) ;
else if ( ! ( V_109 -> V_132 & V_161 ) )
V_57 = F_66 ( V_3 ) ;
F_43 ( V_3 ) ;
V_162:
F_88 ( V_120 ) ;
V_107:
F_74 ( V_118 ) ;
F_89 ( V_115 ) ;
return V_57 < 0 ? V_57 : V_31 ;
V_157:
F_90 ( V_120 ) ;
if ( ! ( V_109 -> V_132 & V_163 ) || V_31 )
goto V_158;
V_57 = 0 ;
goto V_162;
}
static int F_91 ( struct V_2 * V_3 , struct V_108 * V_109 , T_2 V_31 ,
int V_164 , int V_92 , int * V_48 )
{
struct V_51 * V_52 = F_47 ( V_3 ) ;
F_71 ( struct V_53 * , V_83 , V_109 -> V_112 ) ;
T_2 V_165 = 0 ;
int V_57 = - V_134 ;
struct V_14 * V_15 ;
if ( V_92 & V_133 )
goto V_107;
if ( V_48 )
* V_48 = sizeof( * V_83 ) ;
if ( V_92 & V_166 )
return F_92 ( V_3 , V_109 , V_31 , V_48 ) ;
V_15 = F_93 ( V_3 , V_92 , V_164 , & V_57 ) ;
if ( ! V_15 )
goto V_107;
V_165 = V_15 -> V_31 ;
if ( V_31 < V_165 ) {
V_109 -> V_132 |= V_167 ;
V_165 = V_31 ;
}
V_57 = F_94 ( V_15 , 0 , V_109 , V_165 ) ;
if ( V_57 )
goto V_162;
F_95 ( V_109 , V_3 , V_15 ) ;
if ( V_83 ) {
V_83 -> V_58 = V_59 ;
V_83 -> V_98 = 0 ;
V_83 -> V_61 = F_21 ( V_15 ) -> V_81 ;
V_83 -> V_97 = 0 ;
V_83 -> V_72 = 0 ;
V_83 -> V_76 = 0 ;
if ( F_48 ( & V_83 -> V_61 ) & V_71 )
V_83 -> V_72 = F_23 ( V_15 ) ;
}
if ( V_52 -> V_168 . V_169 )
F_96 ( V_3 , V_109 , V_15 ) ;
if ( V_92 & V_167 )
V_165 = V_15 -> V_31 ;
V_162:
F_97 ( V_3 , V_15 ) ;
V_107:
return V_57 ? V_57 : V_165 ;
}
static int T_3 F_98 ( void )
{
int V_57 ;
F_99 ( L_3 ) ;
V_57 = F_100 ( & V_170 , 1 ) ;
if ( V_57 != 0 )
goto V_107;
V_57 = F_101 ( & V_171 , V_42 ) ;
if ( V_57 )
goto V_172;
F_102 ( & V_173 ) ;
return 0 ;
V_172:
F_103 ( & V_170 ) ;
V_107:
return V_57 ;
}
static void T_4 F_104 ( void )
{
F_105 ( & V_173 ) ;
F_106 ( & V_171 , V_42 ) ;
F_103 ( & V_170 ) ;
}
