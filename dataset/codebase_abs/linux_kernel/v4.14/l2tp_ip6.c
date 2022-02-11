static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( const struct V_4 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int V_8 , T_1 V_9 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip6_bind_table) {
const struct V_5 * V_10 = F_4 ( V_3 ) ;
const struct V_5 * V_11 = & V_3 -> V_12 ;
const struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( ! F_5 ( F_6 ( V_3 ) , V_4 ) )
continue;
if ( V_3 -> V_14 && V_8 && V_3 -> V_14 != V_8 )
continue;
if ( V_10 && ! F_7 ( V_10 ) &&
! F_7 ( V_6 ) && ! F_8 ( V_10 , V_6 ) )
continue;
if ( ! F_7 ( V_11 ) && V_7 &&
! F_7 ( V_7 ) && ! F_8 ( V_11 , V_7 ) )
continue;
if ( V_13 -> V_15 != V_9 )
continue;
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
struct V_27 * V_28 ;
int V_29 ;
if ( ! F_11 ( V_18 , 4 ) )
goto V_30;
V_22 = V_21 = V_18 -> V_31 ;
V_20 = F_12 ( * ( ( V_32 * ) V_21 ) ) ;
V_21 += 4 ;
if ( V_20 == 0 ) {
F_13 ( V_18 , 4 ) ;
goto V_33;
}
V_24 = F_14 ( V_4 , NULL , V_20 , true ) ;
if ( ! V_24 )
goto V_30;
V_26 = V_24 -> V_26 ;
if ( ! V_26 )
goto V_34;
if ( V_26 -> V_35 & V_36 ) {
V_29 = F_15 ( 32u , V_18 -> V_37 ) ;
if ( ! F_11 ( V_18 , V_29 ) )
goto V_34;
V_22 = V_21 = V_18 -> V_31 ;
V_21 += 4 ;
F_16 ( L_1 , V_26 -> V_38 ) ;
F_17 ( L_2 , V_39 , V_21 , V_29 ) ;
}
F_18 ( V_24 , V_18 , V_21 , V_22 , 0 , V_18 -> V_37 ,
V_26 -> V_40 ) ;
F_19 ( V_24 ) ;
return 0 ;
V_33:
if ( ! F_11 ( V_18 , 12 ) )
goto V_30;
if ( ( V_18 -> V_31 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_30;
V_9 = F_12 ( * ( V_32 * ) & V_18 -> V_31 [ 4 ] ) ;
V_28 = F_20 ( V_18 ) ;
F_21 ( & V_41 ) ;
V_3 = F_2 ( V_4 , & V_28 -> V_42 , & V_28 -> V_43 ,
F_22 ( V_18 ) , V_9 ) ;
if ( ! V_3 ) {
F_23 ( & V_41 ) ;
goto V_30;
}
F_24 ( V_3 ) ;
F_23 ( & V_41 ) ;
if ( ! F_25 ( V_3 , V_44 , V_18 ) )
goto V_45;
F_26 ( V_18 ) ;
return F_27 ( V_3 , V_18 , 1 ) ;
V_34:
if ( V_24 -> V_46 )
V_24 -> V_46 ( V_24 ) ;
F_19 ( V_24 ) ;
goto V_30;
V_45:
F_28 ( V_3 ) ;
V_30:
F_29 ( V_18 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
F_31 ( V_3 ) -> V_47 = V_48 ;
F_32 ( & V_41 ) ;
F_33 ( V_3 , & V_49 ) ;
F_34 ( & V_41 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , long V_50 )
{
F_32 ( & V_41 ) ;
F_36 ( & V_3 -> V_51 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_41 ) ;
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
static int F_46 ( struct V_2 * V_3 , struct V_52 * V_53 , int V_54 )
{
struct V_55 * V_56 = F_31 ( V_3 ) ;
struct V_57 * V_58 = F_47 ( V_3 ) ;
struct V_59 * V_60 = (struct V_59 * ) V_53 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
V_32 V_61 = 0 ;
int V_62 ;
int V_63 ;
int V_64 ;
if ( V_60 -> V_65 != V_66 )
return - V_67 ;
if ( V_54 < sizeof( * V_60 ) )
return - V_67 ;
V_63 = F_48 ( & V_60 -> V_68 ) ;
if ( V_63 == V_69 )
return - V_70 ;
if ( V_63 & V_71 )
return - V_70 ;
F_41 ( V_3 ) ;
V_64 = - V_67 ;
if ( ! F_49 ( V_3 , V_72 ) )
goto V_73;
if ( V_3 -> V_74 != V_75 )
goto V_73;
V_62 = V_3 -> V_14 ;
F_50 () ;
if ( V_63 != V_76 ) {
struct V_77 * V_19 = NULL ;
if ( V_63 & V_78 ) {
if ( V_60 -> V_79 )
V_62 = V_60 -> V_79 ;
if ( ! V_62 )
goto V_80;
V_64 = - V_81 ;
V_19 = F_51 ( F_6 ( V_3 ) , V_62 ) ;
if ( ! V_19 )
goto V_80;
}
V_61 = V_82 ;
V_64 = - V_70 ;
if ( ! F_52 ( F_6 ( V_3 ) , & V_60 -> V_68 , V_19 , 0 ) )
goto V_80;
}
F_53 () ;
F_32 ( & V_41 ) ;
if ( F_2 ( V_4 , & V_60 -> V_68 , NULL , V_62 ,
V_60 -> V_83 ) ) {
F_34 ( & V_41 ) ;
V_64 = - V_84 ;
goto V_73;
}
V_56 -> V_85 = V_61 ;
V_56 -> V_86 = V_61 ;
V_3 -> V_14 = V_62 ;
V_3 -> V_87 = V_60 -> V_68 ;
V_58 -> V_43 = V_60 -> V_68 ;
F_1 ( V_3 ) -> V_15 = V_60 -> V_83 ;
F_54 ( V_3 , & V_88 ) ;
F_37 ( V_3 ) ;
F_34 ( & V_41 ) ;
F_55 ( V_3 , V_72 ) ;
F_43 ( V_3 ) ;
return 0 ;
V_80:
F_53 () ;
V_73:
F_43 ( V_3 ) ;
return V_64 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_52 * V_53 ,
int V_54 )
{
struct V_59 * V_89 = (struct V_59 * ) V_53 ;
struct V_90 * V_91 = (struct V_90 * ) V_53 ;
struct V_5 * V_42 ;
int V_63 ;
int V_92 ;
if ( V_54 < sizeof( * V_89 ) )
return - V_67 ;
if ( V_91 -> V_93 != V_66 )
return - V_67 ;
V_63 = F_48 ( & V_91 -> V_94 ) ;
if ( V_63 & V_71 )
return - V_67 ;
if ( V_63 & V_69 ) {
V_42 = & V_91 -> V_94 ;
if ( F_57 ( V_42 -> V_95 [ 3 ] ) )
return - V_67 ;
}
F_41 ( V_3 ) ;
if ( F_49 ( V_3 , V_72 ) ) {
V_92 = - V_67 ;
goto V_96;
}
V_92 = F_58 ( V_3 , V_53 , V_54 ) ;
if ( V_92 < 0 )
goto V_96;
F_1 ( V_3 ) -> V_97 = V_89 -> V_83 ;
F_32 ( & V_41 ) ;
F_36 ( & V_3 -> V_51 ) ;
F_54 ( V_3 , & V_88 ) ;
F_34 ( & V_41 ) ;
V_96:
F_43 ( V_3 ) ;
return V_92 ;
}
static int F_59 ( struct V_2 * V_3 , int V_98 )
{
if ( F_49 ( V_3 , V_72 ) )
return 0 ;
return F_60 ( V_3 , V_98 ) ;
}
static int F_61 ( struct V_99 * V_2 , struct V_52 * V_53 ,
int * V_100 , int V_101 )
{
struct V_59 * V_89 = (struct V_59 * ) V_53 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_57 * V_58 = F_47 ( V_3 ) ;
struct V_1 * V_102 = F_1 ( V_3 ) ;
V_89 -> V_65 = V_66 ;
V_89 -> V_103 = 0 ;
V_89 -> V_79 = 0 ;
V_89 -> V_104 = 0 ;
if ( V_101 ) {
if ( ! V_102 -> V_97 )
return - V_105 ;
V_89 -> V_83 = V_102 -> V_97 ;
V_89 -> V_68 = V_3 -> V_12 ;
if ( V_58 -> V_106 )
V_89 -> V_103 = V_58 -> V_107 ;
} else {
if ( F_7 ( & V_3 -> V_87 ) )
V_89 -> V_68 = V_58 -> V_43 ;
else
V_89 -> V_68 = V_3 -> V_87 ;
V_89 -> V_83 = V_102 -> V_15 ;
}
if ( F_48 ( & V_89 -> V_68 ) & V_78 )
V_89 -> V_79 = V_3 -> V_14 ;
* V_100 = sizeof( * V_89 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_92 ;
V_92 = F_63 ( V_3 , V_18 ) ;
if ( V_92 < 0 )
goto V_108;
return 0 ;
V_108:
F_64 ( F_6 ( V_3 ) , V_109 ) ;
F_29 ( V_18 ) ;
return - 1 ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
V_32 * V_110 = NULL ;
int V_64 = 0 ;
V_18 = F_66 ( & V_3 -> V_111 ) ;
if ( V_18 == NULL )
goto V_112;
V_110 = ( V_32 * ) F_67 ( V_18 ) ;
* V_110 = 0 ;
V_64 = F_68 ( V_3 ) ;
V_112:
return V_64 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_113 * V_114 , T_2 V_37 )
{
struct V_115 V_116 ;
F_70 ( struct V_59 * , V_89 , V_114 -> V_117 ) ;
struct V_5 * V_42 , * V_118 , V_119 ;
struct V_57 * V_58 = F_47 ( V_3 ) ;
struct V_115 * V_120 = NULL ;
struct V_115 * V_121 = NULL ;
struct V_122 * V_123 = NULL ;
struct V_124 * V_125 = NULL ;
struct V_126 V_127 ;
struct V_128 V_129 = { 0 } ;
struct V_130 V_131 ;
int V_54 = V_114 -> V_132 ;
int V_133 = 4 ;
int V_134 = V_37 + V_133 ;
int V_64 ;
if ( V_37 > V_135 )
return - V_136 ;
if ( V_114 -> V_137 & V_138 )
return - V_139 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_140 = V_3 -> V_141 ;
V_127 . V_142 = V_3 -> V_143 ;
V_131 . V_144 = - 1 ;
V_131 . V_145 = - 1 ;
V_131 . V_146 = - 1 ;
if ( V_89 ) {
if ( V_54 < V_147 )
return - V_67 ;
if ( V_89 -> V_65 && V_89 -> V_65 != V_66 )
return - V_148 ;
V_42 = & V_89 -> V_68 ;
if ( V_58 -> V_106 ) {
V_127 . V_123 = V_89 -> V_103 & V_149 ;
if ( V_127 . V_123 & V_150 ) {
V_123 = F_71 ( V_3 , V_127 . V_123 ) ;
if ( V_123 == NULL )
return - V_67 ;
}
}
if ( V_3 -> V_74 == V_151 &&
F_8 ( V_42 , & V_3 -> V_12 ) )
V_42 = & V_3 -> V_12 ;
if ( V_54 >= sizeof( struct V_90 ) &&
V_89 -> V_79 &&
F_48 ( V_42 ) & V_78 )
V_127 . V_152 = V_89 -> V_79 ;
} else {
if ( V_3 -> V_74 != V_151 )
return - V_153 ;
V_42 = & V_3 -> V_12 ;
V_127 . V_123 = V_58 -> V_107 ;
}
if ( V_127 . V_152 == 0 )
V_127 . V_152 = V_3 -> V_14 ;
if ( V_114 -> V_154 ) {
V_121 = & V_116 ;
memset ( V_121 , 0 , sizeof( struct V_115 ) ) ;
V_121 -> V_155 = sizeof( struct V_115 ) ;
V_131 . V_121 = V_121 ;
V_64 = F_72 ( F_6 ( V_3 ) , V_3 , V_114 , & V_127 , & V_131 ,
& V_129 ) ;
if ( V_64 < 0 ) {
F_73 ( V_123 ) ;
return V_64 ;
}
if ( ( V_127 . V_123 & V_150 ) && ! V_123 ) {
V_123 = F_71 ( V_3 , V_127 . V_123 ) ;
if ( V_123 == NULL )
return - V_67 ;
}
if ( ! ( V_121 -> V_156 | V_121 -> V_157 ) )
V_121 = NULL ;
}
if ( ! V_121 ) {
V_121 = F_74 ( V_58 ) ;
V_120 = V_121 ;
}
if ( V_123 )
V_121 = F_75 ( & V_116 , V_123 , V_121 ) ;
V_121 = F_76 ( & V_116 , V_121 ) ;
V_131 . V_121 = V_121 ;
V_127 . V_158 = V_3 -> V_159 ;
if ( ! F_7 ( V_42 ) )
V_127 . V_42 = * V_42 ;
else
V_127 . V_42 . V_160 [ 15 ] = 0x1 ;
if ( F_7 ( & V_127 . V_43 ) && ! F_7 ( & V_58 -> V_43 ) )
V_127 . V_43 = V_58 -> V_43 ;
V_118 = F_77 ( & V_127 , V_121 , & V_119 ) ;
if ( ! V_127 . V_152 && F_78 ( & V_127 . V_42 ) )
V_127 . V_152 = V_58 -> V_161 ;
else if ( ! V_127 . V_152 )
V_127 . V_152 = V_58 -> V_162 ;
F_79 ( V_3 , F_80 ( & V_127 ) ) ;
if ( V_131 . V_145 < 0 )
V_131 . V_145 = V_58 -> V_145 ;
V_127 . V_123 = F_81 ( V_131 . V_145 , V_127 . V_123 ) ;
V_125 = F_82 ( V_3 , & V_127 , V_118 ) ;
if ( F_83 ( V_125 ) ) {
V_64 = F_84 ( V_125 ) ;
goto V_112;
}
if ( V_131 . V_144 < 0 )
V_131 . V_144 = F_85 ( V_58 , & V_127 , V_125 ) ;
if ( V_131 . V_146 < 0 )
V_131 . V_146 = V_58 -> V_146 ;
if ( V_114 -> V_137 & V_163 )
goto V_164;
V_165:
F_41 ( V_3 ) ;
V_64 = F_86 ( V_3 , V_166 , V_114 ,
V_134 , V_133 , & V_131 ,
& V_127 , (struct V_167 * ) V_125 ,
V_114 -> V_137 , & V_129 ) ;
if ( V_64 )
F_42 ( V_3 ) ;
else if ( ! ( V_114 -> V_137 & V_168 ) )
V_64 = F_65 ( V_3 ) ;
F_43 ( V_3 ) ;
V_169:
F_87 ( V_125 ) ;
V_112:
F_73 ( V_123 ) ;
F_88 ( V_120 ) ;
return V_64 < 0 ? V_64 : V_37 ;
V_164:
if ( V_114 -> V_137 & V_170 )
F_89 ( V_125 , & V_127 . V_42 ) ;
if ( ! ( V_114 -> V_137 & V_170 ) || V_37 )
goto V_165;
V_64 = 0 ;
goto V_169;
}
static int F_90 ( struct V_2 * V_3 , struct V_113 * V_114 , T_2 V_37 ,
int V_171 , int V_98 , int * V_54 )
{
struct V_57 * V_58 = F_47 ( V_3 ) ;
F_70 ( struct V_59 * , V_89 , V_114 -> V_117 ) ;
T_2 V_172 = 0 ;
int V_64 = - V_139 ;
struct V_17 * V_18 ;
if ( V_98 & V_138 )
goto V_112;
if ( V_54 )
* V_54 = sizeof( * V_89 ) ;
if ( V_98 & V_173 )
return F_91 ( V_3 , V_114 , V_37 , V_54 ) ;
V_18 = F_92 ( V_3 , V_98 , V_171 , & V_64 ) ;
if ( ! V_18 )
goto V_112;
V_172 = V_18 -> V_37 ;
if ( V_37 < V_172 ) {
V_114 -> V_137 |= V_174 ;
V_172 = V_37 ;
}
V_64 = F_93 ( V_18 , 0 , V_114 , V_172 ) ;
if ( V_64 )
goto V_169;
F_94 ( V_114 , V_3 , V_18 ) ;
if ( V_89 ) {
V_89 -> V_65 = V_66 ;
V_89 -> V_104 = 0 ;
V_89 -> V_68 = F_20 ( V_18 ) -> V_43 ;
V_89 -> V_103 = 0 ;
V_89 -> V_79 = 0 ;
V_89 -> V_83 = 0 ;
if ( F_48 ( & V_89 -> V_68 ) & V_78 )
V_89 -> V_79 = F_22 ( V_18 ) ;
}
if ( V_58 -> V_175 . V_176 )
F_95 ( V_3 , V_114 , V_18 ) ;
if ( V_98 & V_174 )
V_172 = V_18 -> V_37 ;
V_169:
F_96 ( V_3 , V_18 ) ;
V_112:
return V_64 ? V_64 : V_172 ;
}
static int T_3 F_97 ( void )
{
int V_64 ;
F_98 ( L_3 ) ;
V_64 = F_99 ( & V_177 , 1 ) ;
if ( V_64 != 0 )
goto V_112;
V_64 = F_100 ( & V_178 , V_48 ) ;
if ( V_64 )
goto V_179;
F_101 ( & V_180 ) ;
return 0 ;
V_179:
F_102 ( & V_177 ) ;
V_112:
return V_64 ;
}
static void T_4 F_103 ( void )
{
F_104 ( & V_180 ) ;
F_105 ( & V_178 , V_48 ) ;
F_102 ( & V_177 ) ;
}
