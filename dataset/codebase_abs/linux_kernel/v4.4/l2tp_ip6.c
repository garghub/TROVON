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
struct V_2 * V_3 ;
T_1 V_16 ;
T_1 V_8 ;
unsigned char * V_17 , * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = NULL ;
int V_23 ;
V_18 = V_17 = V_15 -> V_24 ;
if ( ! F_11 ( V_15 , 4 ) )
goto V_25;
V_16 = F_12 ( * ( ( V_26 * ) V_17 ) ) ;
V_17 += 4 ;
if ( V_16 == 0 ) {
F_13 ( V_15 , 4 ) ;
goto V_27;
}
V_20 = F_14 ( & V_28 , NULL , V_16 ) ;
if ( V_20 == NULL )
goto V_25;
V_22 = V_20 -> V_22 ;
if ( V_22 == NULL )
goto V_25;
if ( V_22 -> V_29 & V_30 ) {
V_23 = F_15 ( 32u , V_15 -> V_31 ) ;
if ( ! F_11 ( V_15 , V_23 ) )
goto V_25;
F_16 ( L_1 , V_22 -> V_32 ) ;
F_17 ( L_2 , V_33 , V_17 , V_23 ) ;
}
F_18 ( V_20 , V_15 , V_17 , V_18 , 0 , V_15 -> V_31 ,
V_22 -> V_34 ) ;
return 0 ;
V_27:
if ( ! F_11 ( V_15 , 12 ) )
goto V_25;
if ( ( V_15 -> V_24 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_25;
V_8 = F_12 ( * ( V_26 * ) & V_15 -> V_24 [ 4 ] ) ;
V_22 = F_19 ( & V_28 , V_8 ) ;
if ( V_22 != NULL )
V_3 = V_22 -> V_2 ;
else {
struct V_35 * V_36 = F_20 ( V_15 ) ;
F_21 ( & V_37 ) ;
V_3 = F_2 ( & V_28 , & V_36 -> V_38 ,
0 , V_8 ) ;
F_22 ( & V_37 ) ;
}
if ( V_3 == NULL )
goto V_25;
F_9 ( V_3 ) ;
if ( ! F_23 ( V_3 , V_39 , V_15 ) )
goto V_40;
F_24 ( V_15 ) ;
return F_25 ( V_3 , V_15 , 1 ) ;
V_40:
F_26 ( V_3 ) ;
V_25:
F_27 ( V_15 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
F_29 ( V_3 ) -> V_41 = V_42 ;
F_30 ( & V_37 ) ;
F_31 ( V_3 , & V_43 ) ;
F_32 ( & V_37 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 , long V_44 )
{
F_30 ( & V_37 ) ;
F_34 ( & V_3 -> V_45 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_37 ) ;
F_36 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
if ( V_22 ) {
F_42 ( V_22 ) ;
F_26 ( V_3 ) ;
}
F_43 ( V_3 ) ;
}
static int F_44 ( struct V_2 * V_3 , struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_50 = F_29 ( V_3 ) ;
struct V_51 * V_52 = F_45 ( V_3 ) ;
struct V_53 * V_9 = (struct V_53 * ) V_47 ;
V_26 V_54 = 0 ;
int V_55 ;
int V_56 ;
if ( ! F_46 ( V_3 , V_57 ) )
return - V_58 ;
if ( V_9 -> V_59 != V_60 )
return - V_58 ;
if ( V_48 < sizeof( * V_9 ) )
return - V_58 ;
V_55 = F_47 ( & V_9 -> V_61 ) ;
if ( V_55 == V_62 )
return - V_63 ;
if ( V_55 & V_64 )
return - V_63 ;
V_56 = - V_65 ;
F_21 ( & V_37 ) ;
if ( F_2 ( & V_28 , & V_9 -> V_61 ,
V_3 -> V_12 , V_9 -> V_66 ) )
goto V_67;
F_22 ( & V_37 ) ;
F_39 ( V_3 ) ;
V_56 = - V_58 ;
if ( V_3 -> V_68 != V_69 )
goto V_70;
F_48 () ;
if ( V_55 != V_71 ) {
struct V_72 * V_73 = NULL ;
if ( V_55 & V_74 ) {
if ( V_48 >= sizeof( struct V_75 ) &&
V_9 -> V_76 ) {
V_3 -> V_12 = V_9 -> V_76 ;
}
if ( ! V_3 -> V_12 )
goto V_77;
V_56 = - V_78 ;
V_73 = F_49 ( F_6 ( V_3 ) ,
V_3 -> V_12 ) ;
if ( ! V_73 )
goto V_77;
}
V_54 = V_79 ;
V_56 = - V_63 ;
if ( ! F_50 ( F_6 ( V_3 ) , & V_9 -> V_61 , V_73 , 0 ) )
goto V_77;
}
F_51 () ;
V_50 -> V_80 = V_50 -> V_81 = V_54 ;
V_3 -> V_82 = V_9 -> V_61 ;
V_52 -> V_83 = V_9 -> V_61 ;
F_1 ( V_3 ) -> V_11 = V_9 -> V_66 ;
F_30 ( & V_37 ) ;
F_52 ( V_3 , & V_84 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_37 ) ;
F_53 ( V_3 , V_57 ) ;
F_41 ( V_3 ) ;
return 0 ;
V_77:
F_51 () ;
V_70:
F_41 ( V_3 ) ;
return V_56 ;
V_67:
F_22 ( & V_37 ) ;
return V_56 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_46 * V_47 ,
int V_48 )
{
struct V_53 * V_85 = (struct V_53 * ) V_47 ;
struct V_75 * V_86 = (struct V_75 * ) V_47 ;
struct V_5 * V_38 ;
int V_55 ;
int V_87 ;
if ( F_46 ( V_3 , V_57 ) )
return - V_58 ;
if ( V_48 < sizeof( * V_85 ) )
return - V_58 ;
if ( V_86 -> V_88 != V_60 )
return - V_58 ;
V_55 = F_47 ( & V_86 -> V_89 ) ;
if ( V_55 & V_64 )
return - V_58 ;
if ( V_55 & V_62 ) {
V_38 = & V_86 -> V_89 ;
if ( F_55 ( V_38 -> V_90 [ 3 ] ) )
return - V_58 ;
}
V_87 = F_56 ( V_3 , V_47 , V_48 ) ;
F_39 ( V_3 ) ;
F_1 ( V_3 ) -> V_91 = V_85 -> V_66 ;
F_30 ( & V_37 ) ;
F_34 ( & V_3 -> V_45 ) ;
F_52 ( V_3 , & V_84 ) ;
F_32 ( & V_37 ) ;
F_41 ( V_3 ) ;
return V_87 ;
}
static int F_57 ( struct V_2 * V_3 , int V_92 )
{
if ( F_46 ( V_3 , V_57 ) )
return 0 ;
return F_58 ( V_3 , V_92 ) ;
}
static int F_59 ( struct V_93 * V_2 , struct V_46 * V_47 ,
int * V_94 , int V_95 )
{
struct V_53 * V_85 = (struct V_53 * ) V_47 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_51 * V_52 = F_45 ( V_3 ) ;
struct V_1 * V_96 = F_1 ( V_3 ) ;
V_85 -> V_59 = V_60 ;
V_85 -> V_97 = 0 ;
V_85 -> V_76 = 0 ;
V_85 -> V_98 = 0 ;
if ( V_95 ) {
if ( ! V_96 -> V_91 )
return - V_99 ;
V_85 -> V_66 = V_96 -> V_91 ;
V_85 -> V_61 = V_3 -> V_100 ;
if ( V_52 -> V_101 )
V_85 -> V_97 = V_52 -> V_102 ;
} else {
if ( F_60 ( & V_3 -> V_82 ) )
V_85 -> V_61 = V_52 -> V_83 ;
else
V_85 -> V_61 = V_3 -> V_82 ;
V_85 -> V_66 = V_96 -> V_11 ;
}
if ( F_47 ( & V_85 -> V_61 ) & V_74 )
V_85 -> V_76 = V_3 -> V_12 ;
* V_94 = sizeof( * V_85 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_87 ;
V_87 = F_62 ( V_3 , V_15 ) ;
if ( V_87 < 0 )
goto V_103;
return 0 ;
V_103:
F_63 ( & V_28 , V_104 ) ;
F_27 ( V_15 ) ;
return - 1 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_14 * V_15 ;
V_26 * V_105 = NULL ;
int V_56 = 0 ;
V_15 = F_65 ( & V_3 -> V_106 ) ;
if ( V_15 == NULL )
goto V_107;
V_105 = ( V_26 * ) F_66 ( V_15 ) ;
* V_105 = 0 ;
V_56 = F_67 ( V_3 ) ;
V_107:
return V_56 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_108 * V_109 , T_2 V_31 )
{
struct V_110 V_111 ;
F_69 ( struct V_53 * , V_85 , V_109 -> V_112 ) ;
struct V_5 * V_38 , * V_113 , V_114 ;
struct V_51 * V_52 = F_45 ( V_3 ) ;
struct V_110 * V_115 = NULL ;
struct V_110 * V_116 = NULL ;
struct V_117 * V_118 = NULL ;
struct V_119 * V_120 = NULL ;
struct V_121 V_122 ;
int V_48 = V_109 -> V_123 ;
int V_124 = - 1 ;
int V_125 = - 1 ;
int V_126 = - 1 ;
int V_127 = 4 ;
int V_128 = V_31 + V_127 ;
int V_56 ;
if ( V_31 > V_129 )
return - V_130 ;
if ( V_109 -> V_131 & V_132 )
return - V_133 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_134 = V_3 -> V_135 ;
if ( V_85 ) {
if ( V_48 < V_136 )
return - V_58 ;
if ( V_85 -> V_59 && V_85 -> V_59 != V_60 )
return - V_137 ;
V_38 = & V_85 -> V_61 ;
if ( V_52 -> V_101 ) {
V_122 . V_118 = V_85 -> V_97 & V_138 ;
if ( V_122 . V_118 & V_139 ) {
V_118 = F_70 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_58 ;
}
}
if ( V_3 -> V_68 == V_140 &&
F_7 ( V_38 , & V_3 -> V_100 ) )
V_38 = & V_3 -> V_100 ;
if ( V_48 >= sizeof( struct V_75 ) &&
V_85 -> V_76 &&
F_47 ( V_38 ) & V_74 )
V_122 . V_141 = V_85 -> V_76 ;
} else {
if ( V_3 -> V_68 != V_140 )
return - V_142 ;
V_38 = & V_3 -> V_100 ;
V_122 . V_118 = V_52 -> V_102 ;
}
if ( V_122 . V_141 == 0 )
V_122 . V_141 = V_3 -> V_12 ;
if ( V_109 -> V_143 ) {
V_116 = & V_111 ;
memset ( V_116 , 0 , sizeof( struct V_110 ) ) ;
V_116 -> V_144 = sizeof( struct V_110 ) ;
V_56 = F_71 ( F_6 ( V_3 ) , V_3 , V_109 , & V_122 , V_116 ,
& V_124 , & V_125 , & V_126 ) ;
if ( V_56 < 0 ) {
F_72 ( V_118 ) ;
return V_56 ;
}
if ( ( V_122 . V_118 & V_139 ) && ! V_118 ) {
V_118 = F_70 ( V_3 , V_122 . V_118 ) ;
if ( V_118 == NULL )
return - V_58 ;
}
if ( ! ( V_116 -> V_145 | V_116 -> V_146 ) )
V_116 = NULL ;
}
if ( ! V_116 ) {
V_116 = F_73 ( V_52 ) ;
V_115 = V_116 ;
}
if ( V_118 )
V_116 = F_74 ( & V_111 , V_118 , V_116 ) ;
V_116 = F_75 ( & V_111 , V_116 ) ;
V_122 . V_147 = V_3 -> V_148 ;
if ( ! F_60 ( V_38 ) )
V_122 . V_38 = * V_38 ;
else
V_122 . V_38 . V_149 [ 15 ] = 0x1 ;
if ( F_60 ( & V_122 . V_83 ) && ! F_60 ( & V_52 -> V_83 ) )
V_122 . V_83 = V_52 -> V_83 ;
V_113 = F_76 ( & V_122 , V_116 , & V_114 ) ;
if ( ! V_122 . V_141 && F_77 ( & V_122 . V_38 ) )
V_122 . V_141 = V_52 -> V_150 ;
else if ( ! V_122 . V_141 )
V_122 . V_141 = V_52 -> V_151 ;
F_78 ( V_3 , F_79 ( & V_122 ) ) ;
V_120 = F_80 ( V_3 , & V_122 , V_113 ) ;
if ( F_81 ( V_120 ) ) {
V_56 = F_82 ( V_120 ) ;
goto V_107;
}
if ( V_124 < 0 )
V_124 = F_83 ( V_52 , & V_122 , V_120 ) ;
if ( V_125 < 0 )
V_125 = V_52 -> V_125 ;
if ( V_126 < 0 )
V_126 = V_52 -> V_126 ;
if ( V_109 -> V_131 & V_152 )
goto V_153;
V_154:
F_39 ( V_3 ) ;
V_56 = F_84 ( V_3 , V_155 , V_109 ,
V_128 , V_127 , V_124 , V_125 , V_116 ,
& V_122 , (struct V_156 * ) V_120 ,
V_109 -> V_131 , V_126 ) ;
if ( V_56 )
F_40 ( V_3 ) ;
else if ( ! ( V_109 -> V_131 & V_157 ) )
V_56 = F_64 ( V_3 ) ;
F_41 ( V_3 ) ;
V_158:
F_85 ( V_120 ) ;
V_107:
F_72 ( V_118 ) ;
F_86 ( V_115 ) ;
return V_56 < 0 ? V_56 : V_31 ;
V_153:
F_87 ( V_120 ) ;
if ( ! ( V_109 -> V_131 & V_159 ) || V_31 )
goto V_154;
V_56 = 0 ;
goto V_158;
}
static int F_88 ( struct V_2 * V_3 , struct V_108 * V_109 , T_2 V_31 ,
int V_160 , int V_92 , int * V_48 )
{
struct V_51 * V_52 = F_45 ( V_3 ) ;
F_69 ( struct V_53 * , V_85 , V_109 -> V_112 ) ;
T_2 V_161 = 0 ;
int V_56 = - V_133 ;
struct V_14 * V_15 ;
if ( V_92 & V_132 )
goto V_107;
if ( V_48 )
* V_48 = sizeof( * V_85 ) ;
if ( V_92 & V_162 )
return F_89 ( V_3 , V_109 , V_31 , V_48 ) ;
V_15 = F_90 ( V_3 , V_92 , V_160 , & V_56 ) ;
if ( ! V_15 )
goto V_107;
V_161 = V_15 -> V_31 ;
if ( V_31 < V_161 ) {
V_109 -> V_131 |= V_163 ;
V_161 = V_31 ;
}
V_56 = F_91 ( V_15 , 0 , V_109 , V_161 ) ;
if ( V_56 )
goto V_158;
F_92 ( V_109 , V_3 , V_15 ) ;
if ( V_85 ) {
V_85 -> V_59 = V_60 ;
V_85 -> V_98 = 0 ;
V_85 -> V_61 = F_20 ( V_15 ) -> V_83 ;
V_85 -> V_97 = 0 ;
V_85 -> V_76 = 0 ;
V_85 -> V_66 = 0 ;
if ( F_47 ( & V_85 -> V_61 ) & V_74 )
V_85 -> V_76 = F_93 ( V_15 ) ;
}
if ( V_52 -> V_164 . V_165 )
F_94 ( V_3 , V_109 , V_15 ) ;
if ( V_92 & V_163 )
V_161 = V_15 -> V_31 ;
V_158:
F_95 ( V_3 , V_15 ) ;
V_107:
return V_56 ? V_56 : V_161 ;
}
static int T_3 F_96 ( void )
{
int V_56 ;
F_97 ( L_3 ) ;
V_56 = F_98 ( & V_166 , 1 ) ;
if ( V_56 != 0 )
goto V_107;
V_56 = F_99 ( & V_167 , V_42 ) ;
if ( V_56 )
goto V_168;
F_100 ( & V_169 ) ;
return 0 ;
V_168:
F_101 ( & V_166 ) ;
V_107:
return V_56 ;
}
static void T_4 F_102 ( void )
{
F_103 ( & V_169 ) ;
F_104 ( & V_167 , V_42 ) ;
F_101 ( & V_166 ) ;
}
