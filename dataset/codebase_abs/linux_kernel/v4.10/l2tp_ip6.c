static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( struct V_4 * V_4 ,
struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int V_8 , T_1 V_9 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip6_bind_table) {
const struct V_5 * V_10 = F_4 ( V_3 ) ;
const struct V_5 * V_11 = & V_3 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( V_13 == NULL )
continue;
if ( ( V_13 -> V_14 == V_9 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
( ! V_10 || F_7 ( V_10 ) || F_8 ( V_10 , V_6 ) ) &&
( ! V_7 || F_7 ( V_11 ) || F_8 ( V_11 , V_7 ) ) &&
( ! V_3 -> V_15 || ! V_8 ||
V_3 -> V_15 == V_8 ) )
goto V_16;
}
V_3 = NULL ;
V_16:
return V_3 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_4 * V_4 = F_10 ( V_18 -> V_19 ) ;
struct V_2 * V_3 ;
T_1 V_20 ;
T_1 V_9 ;
unsigned char * V_21 , * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = NULL ;
int V_27 ;
if ( ! F_11 ( V_18 , 4 ) )
goto V_28;
V_22 = V_21 = V_18 -> V_29 ;
V_20 = F_12 ( * ( ( V_30 * ) V_21 ) ) ;
V_21 += 4 ;
if ( V_20 == 0 ) {
F_13 ( V_18 , 4 ) ;
goto V_31;
}
V_24 = F_14 ( V_4 , NULL , V_20 ) ;
if ( V_24 == NULL )
goto V_28;
V_26 = V_24 -> V_26 ;
if ( V_26 == NULL )
goto V_28;
if ( V_26 -> V_32 & V_33 ) {
V_27 = F_15 ( 32u , V_18 -> V_34 ) ;
if ( ! F_11 ( V_18 , V_27 ) )
goto V_28;
V_22 = V_21 = V_18 -> V_29 ;
V_21 += 4 ;
F_16 ( L_1 , V_26 -> V_35 ) ;
F_17 ( L_2 , V_36 , V_21 , V_27 ) ;
}
F_18 ( V_24 , V_18 , V_21 , V_22 , 0 , V_18 -> V_34 ,
V_26 -> V_37 ) ;
return 0 ;
V_31:
if ( ! F_11 ( V_18 , 12 ) )
goto V_28;
if ( ( V_18 -> V_29 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_28;
V_9 = F_12 ( * ( V_30 * ) & V_18 -> V_29 [ 4 ] ) ;
V_26 = F_19 ( V_4 , V_9 ) ;
if ( V_26 != NULL )
V_3 = V_26 -> V_2 ;
else {
struct V_38 * V_39 = F_20 ( V_18 ) ;
F_21 ( & V_40 ) ;
V_3 = F_2 ( V_4 , & V_39 -> V_41 , & V_39 -> V_42 ,
F_22 ( V_18 ) , V_9 ) ;
if ( ! V_3 ) {
F_23 ( & V_40 ) ;
goto V_28;
}
F_24 ( V_3 ) ;
F_23 ( & V_40 ) ;
}
if ( ! F_25 ( V_3 , V_43 , V_18 ) )
goto V_44;
F_26 ( V_18 ) ;
return F_27 ( V_3 , V_18 , 1 ) ;
V_44:
F_28 ( V_3 ) ;
V_28:
F_29 ( V_18 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
F_31 ( V_3 ) -> V_45 = V_46 ;
F_32 ( & V_40 ) ;
F_33 ( V_3 , & V_47 ) ;
F_34 ( & V_40 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , long V_48 )
{
F_32 ( & V_40 ) ;
F_36 ( & V_3 -> V_49 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_40 ) ;
F_38 ( V_3 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
if ( V_26 ) {
F_44 ( V_26 ) ;
F_28 ( V_3 ) ;
}
F_45 ( V_3 ) ;
}
static int F_46 ( struct V_2 * V_3 , struct V_50 * V_51 , int V_52 )
{
struct V_53 * V_54 = F_31 ( V_3 ) ;
struct V_55 * V_56 = F_47 ( V_3 ) ;
struct V_57 * V_58 = (struct V_57 * ) V_51 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
V_30 V_59 = 0 ;
int V_60 ;
int V_61 ;
int V_62 ;
if ( V_58 -> V_63 != V_64 )
return - V_65 ;
if ( V_52 < sizeof( * V_58 ) )
return - V_65 ;
V_61 = F_48 ( & V_58 -> V_66 ) ;
if ( V_61 == V_67 )
return - V_68 ;
if ( V_61 & V_69 )
return - V_68 ;
F_41 ( V_3 ) ;
V_62 = - V_65 ;
if ( ! F_49 ( V_3 , V_70 ) )
goto V_71;
if ( V_3 -> V_72 != V_73 )
goto V_71;
V_60 = V_3 -> V_15 ;
F_50 () ;
if ( V_61 != V_74 ) {
struct V_75 * V_19 = NULL ;
if ( V_61 & V_76 ) {
if ( V_58 -> V_77 )
V_60 = V_58 -> V_77 ;
if ( ! V_60 )
goto V_78;
V_62 = - V_79 ;
V_19 = F_51 ( F_6 ( V_3 ) , V_60 ) ;
if ( ! V_19 )
goto V_78;
}
V_59 = V_80 ;
V_62 = - V_68 ;
if ( ! F_52 ( F_6 ( V_3 ) , & V_58 -> V_66 , V_19 , 0 ) )
goto V_78;
}
F_53 () ;
F_32 ( & V_40 ) ;
if ( F_2 ( V_4 , & V_58 -> V_66 , NULL , V_60 ,
V_58 -> V_81 ) ) {
F_34 ( & V_40 ) ;
V_62 = - V_82 ;
goto V_71;
}
V_54 -> V_83 = V_59 ;
V_54 -> V_84 = V_59 ;
V_3 -> V_15 = V_60 ;
V_3 -> V_85 = V_58 -> V_66 ;
V_56 -> V_42 = V_58 -> V_66 ;
F_1 ( V_3 ) -> V_14 = V_58 -> V_81 ;
F_54 ( V_3 , & V_86 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_40 ) ;
F_55 ( V_3 , V_70 ) ;
F_43 ( V_3 ) ;
return 0 ;
V_78:
F_53 () ;
V_71:
F_43 ( V_3 ) ;
return V_62 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_50 * V_51 ,
int V_52 )
{
struct V_57 * V_87 = (struct V_57 * ) V_51 ;
struct V_88 * V_89 = (struct V_88 * ) V_51 ;
struct V_5 * V_41 ;
int V_61 ;
int V_90 ;
if ( V_52 < sizeof( * V_87 ) )
return - V_65 ;
if ( V_89 -> V_91 != V_64 )
return - V_65 ;
V_61 = F_48 ( & V_89 -> V_92 ) ;
if ( V_61 & V_69 )
return - V_65 ;
if ( V_61 & V_67 ) {
V_41 = & V_89 -> V_92 ;
if ( F_57 ( V_41 -> V_93 [ 3 ] ) )
return - V_65 ;
}
F_41 ( V_3 ) ;
if ( F_49 ( V_3 , V_70 ) ) {
V_90 = - V_65 ;
goto V_94;
}
V_90 = F_58 ( V_3 , V_51 , V_52 ) ;
if ( V_90 < 0 )
goto V_94;
F_1 ( V_3 ) -> V_95 = V_87 -> V_81 ;
F_32 ( & V_40 ) ;
F_36 ( & V_3 -> V_49 ) ;
F_54 ( V_3 , & V_86 ) ;
F_34 ( & V_40 ) ;
V_94:
F_43 ( V_3 ) ;
return V_90 ;
}
static int F_59 ( struct V_2 * V_3 , int V_96 )
{
if ( F_49 ( V_3 , V_70 ) )
return 0 ;
return F_60 ( V_3 , V_96 ) ;
}
static int F_61 ( struct V_97 * V_2 , struct V_50 * V_51 ,
int * V_98 , int V_99 )
{
struct V_57 * V_87 = (struct V_57 * ) V_51 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_55 * V_56 = F_47 ( V_3 ) ;
struct V_1 * V_100 = F_1 ( V_3 ) ;
V_87 -> V_63 = V_64 ;
V_87 -> V_101 = 0 ;
V_87 -> V_77 = 0 ;
V_87 -> V_102 = 0 ;
if ( V_99 ) {
if ( ! V_100 -> V_95 )
return - V_103 ;
V_87 -> V_81 = V_100 -> V_95 ;
V_87 -> V_66 = V_3 -> V_12 ;
if ( V_56 -> V_104 )
V_87 -> V_101 = V_56 -> V_105 ;
} else {
if ( F_7 ( & V_3 -> V_85 ) )
V_87 -> V_66 = V_56 -> V_42 ;
else
V_87 -> V_66 = V_3 -> V_85 ;
V_87 -> V_81 = V_100 -> V_14 ;
}
if ( F_48 ( & V_87 -> V_66 ) & V_76 )
V_87 -> V_77 = V_3 -> V_15 ;
* V_98 = sizeof( * V_87 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_90 ;
V_90 = F_63 ( V_3 , V_18 ) ;
if ( V_90 < 0 )
goto V_106;
return 0 ;
V_106:
F_64 ( F_6 ( V_3 ) , V_107 ) ;
F_29 ( V_18 ) ;
return - 1 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
V_30 * V_108 = NULL ;
int V_62 = 0 ;
V_18 = F_66 ( & V_3 -> V_109 ) ;
if ( V_18 == NULL )
goto V_110;
V_108 = ( V_30 * ) F_67 ( V_18 ) ;
* V_108 = 0 ;
V_62 = F_68 ( V_3 ) ;
V_110:
return V_62 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_111 * V_112 , T_2 V_34 )
{
struct V_113 V_114 ;
F_70 ( struct V_57 * , V_87 , V_112 -> V_115 ) ;
struct V_5 * V_41 , * V_116 , V_117 ;
struct V_55 * V_56 = F_47 ( V_3 ) ;
struct V_113 * V_118 = NULL ;
struct V_113 * V_119 = NULL ;
struct V_120 * V_121 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_124 V_125 ;
struct V_126 V_127 = { 0 } ;
struct V_128 V_129 ;
int V_52 = V_112 -> V_130 ;
int V_131 = 4 ;
int V_132 = V_34 + V_131 ;
int V_62 ;
if ( V_34 > V_133 )
return - V_134 ;
if ( V_112 -> V_135 & V_136 )
return - V_137 ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_138 = V_3 -> V_139 ;
V_125 . V_140 = V_3 -> V_141 ;
V_129 . V_142 = - 1 ;
V_129 . V_143 = - 1 ;
V_129 . V_144 = - 1 ;
if ( V_87 ) {
if ( V_52 < V_145 )
return - V_65 ;
if ( V_87 -> V_63 && V_87 -> V_63 != V_64 )
return - V_146 ;
V_41 = & V_87 -> V_66 ;
if ( V_56 -> V_104 ) {
V_125 . V_121 = V_87 -> V_101 & V_147 ;
if ( V_125 . V_121 & V_148 ) {
V_121 = F_71 ( V_3 , V_125 . V_121 ) ;
if ( V_121 == NULL )
return - V_65 ;
}
}
if ( V_3 -> V_72 == V_149 &&
F_8 ( V_41 , & V_3 -> V_12 ) )
V_41 = & V_3 -> V_12 ;
if ( V_52 >= sizeof( struct V_88 ) &&
V_87 -> V_77 &&
F_48 ( V_41 ) & V_76 )
V_125 . V_150 = V_87 -> V_77 ;
} else {
if ( V_3 -> V_72 != V_149 )
return - V_151 ;
V_41 = & V_3 -> V_12 ;
V_125 . V_121 = V_56 -> V_105 ;
}
if ( V_125 . V_150 == 0 )
V_125 . V_150 = V_3 -> V_15 ;
if ( V_112 -> V_152 ) {
V_119 = & V_114 ;
memset ( V_119 , 0 , sizeof( struct V_113 ) ) ;
V_119 -> V_153 = sizeof( struct V_113 ) ;
V_129 . V_119 = V_119 ;
V_62 = F_72 ( F_6 ( V_3 ) , V_3 , V_112 , & V_125 , & V_129 ,
& V_127 ) ;
if ( V_62 < 0 ) {
F_73 ( V_121 ) ;
return V_62 ;
}
if ( ( V_125 . V_121 & V_148 ) && ! V_121 ) {
V_121 = F_71 ( V_3 , V_125 . V_121 ) ;
if ( V_121 == NULL )
return - V_65 ;
}
if ( ! ( V_119 -> V_154 | V_119 -> V_155 ) )
V_119 = NULL ;
}
if ( ! V_119 ) {
V_119 = F_74 ( V_56 ) ;
V_118 = V_119 ;
}
if ( V_121 )
V_119 = F_75 ( & V_114 , V_121 , V_119 ) ;
V_119 = F_76 ( & V_114 , V_119 ) ;
V_129 . V_119 = V_119 ;
V_125 . V_156 = V_3 -> V_157 ;
if ( ! F_7 ( V_41 ) )
V_125 . V_41 = * V_41 ;
else
V_125 . V_41 . V_158 [ 15 ] = 0x1 ;
if ( F_7 ( & V_125 . V_42 ) && ! F_7 ( & V_56 -> V_42 ) )
V_125 . V_42 = V_56 -> V_42 ;
V_116 = F_77 ( & V_125 , V_119 , & V_117 ) ;
if ( ! V_125 . V_150 && F_78 ( & V_125 . V_41 ) )
V_125 . V_150 = V_56 -> V_159 ;
else if ( ! V_125 . V_150 )
V_125 . V_150 = V_56 -> V_160 ;
F_79 ( V_3 , F_80 ( & V_125 ) ) ;
if ( V_129 . V_143 < 0 )
V_129 . V_143 = V_56 -> V_143 ;
V_125 . V_121 = F_81 ( V_129 . V_143 , V_125 . V_121 ) ;
V_123 = F_82 ( V_3 , & V_125 , V_116 ) ;
if ( F_83 ( V_123 ) ) {
V_62 = F_84 ( V_123 ) ;
goto V_110;
}
if ( V_129 . V_142 < 0 )
V_129 . V_142 = F_85 ( V_56 , & V_125 , V_123 ) ;
if ( V_129 . V_144 < 0 )
V_129 . V_144 = V_56 -> V_144 ;
if ( V_112 -> V_135 & V_161 )
goto V_162;
V_163:
F_41 ( V_3 ) ;
V_62 = F_86 ( V_3 , V_164 , V_112 ,
V_132 , V_131 , & V_129 ,
& V_125 , (struct V_165 * ) V_123 ,
V_112 -> V_135 , & V_127 ) ;
if ( V_62 )
F_42 ( V_3 ) ;
else if ( ! ( V_112 -> V_135 & V_166 ) )
V_62 = F_65 ( V_3 ) ;
F_43 ( V_3 ) ;
V_167:
F_87 ( V_123 ) ;
V_110:
F_73 ( V_121 ) ;
F_88 ( V_118 ) ;
return V_62 < 0 ? V_62 : V_34 ;
V_162:
F_89 ( V_123 ) ;
if ( ! ( V_112 -> V_135 & V_168 ) || V_34 )
goto V_163;
V_62 = 0 ;
goto V_167;
}
static int F_90 ( struct V_2 * V_3 , struct V_111 * V_112 , T_2 V_34 ,
int V_169 , int V_96 , int * V_52 )
{
struct V_55 * V_56 = F_47 ( V_3 ) ;
F_70 ( struct V_57 * , V_87 , V_112 -> V_115 ) ;
T_2 V_170 = 0 ;
int V_62 = - V_137 ;
struct V_17 * V_18 ;
if ( V_96 & V_136 )
goto V_110;
if ( V_52 )
* V_52 = sizeof( * V_87 ) ;
if ( V_96 & V_171 )
return F_91 ( V_3 , V_112 , V_34 , V_52 ) ;
V_18 = F_92 ( V_3 , V_96 , V_169 , & V_62 ) ;
if ( ! V_18 )
goto V_110;
V_170 = V_18 -> V_34 ;
if ( V_34 < V_170 ) {
V_112 -> V_135 |= V_172 ;
V_170 = V_34 ;
}
V_62 = F_93 ( V_18 , 0 , V_112 , V_170 ) ;
if ( V_62 )
goto V_167;
F_94 ( V_112 , V_3 , V_18 ) ;
if ( V_87 ) {
V_87 -> V_63 = V_64 ;
V_87 -> V_102 = 0 ;
V_87 -> V_66 = F_20 ( V_18 ) -> V_42 ;
V_87 -> V_101 = 0 ;
V_87 -> V_77 = 0 ;
V_87 -> V_81 = 0 ;
if ( F_48 ( & V_87 -> V_66 ) & V_76 )
V_87 -> V_77 = F_22 ( V_18 ) ;
}
if ( V_56 -> V_173 . V_174 )
F_95 ( V_3 , V_112 , V_18 ) ;
if ( V_96 & V_172 )
V_170 = V_18 -> V_34 ;
V_167:
F_96 ( V_3 , V_18 ) ;
V_110:
return V_62 ? V_62 : V_170 ;
}
static int T_3 F_97 ( void )
{
int V_62 ;
F_98 ( L_3 ) ;
V_62 = F_99 ( & V_175 , 1 ) ;
if ( V_62 != 0 )
goto V_110;
V_62 = F_100 ( & V_176 , V_46 ) ;
if ( V_62 )
goto V_177;
F_101 ( & V_178 ) ;
return 0 ;
V_177:
F_102 ( & V_175 ) ;
V_110:
return V_62 ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_178 ) ;
F_105 ( & V_176 , V_46 ) ;
F_102 ( & V_175 ) ;
}
