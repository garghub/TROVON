static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( struct V_4 * V_4 , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_8 * V_9 ;
struct V_2 * V_3 ;
F_3 (sk, node, &l2tp_ip_bind_table) {
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_12 == NULL )
continue;
if ( ( V_12 -> V_13 == V_7 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
! ( V_11 -> V_14 && V_11 -> V_14 != V_5 ) &&
! ( V_3 -> V_15 && V_3 -> V_15 != V_6 ) )
goto V_16;
}
V_3 = NULL ;
V_16:
return V_3 ;
}
static inline struct V_2 * F_7 ( struct V_4 * V_4 , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_5 , V_6 , V_7 ) ;
if ( V_3 )
F_8 ( V_3 ) ;
return V_3 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_2 * V_3 ;
T_2 V_19 ;
T_2 V_7 ;
unsigned char * V_20 , * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = NULL ;
int V_26 ;
int V_27 ;
V_21 = V_20 = V_18 -> V_28 ;
if ( ! F_10 ( V_18 , 4 ) )
goto V_29;
V_19 = F_11 ( * ( ( T_1 * ) V_20 ) ) ;
V_20 += 4 ;
if ( V_19 == 0 ) {
F_12 ( V_18 , 4 ) ;
goto V_30;
}
V_23 = F_13 ( & V_31 , NULL , V_19 ) ;
if ( V_23 == NULL )
goto V_29;
V_25 = V_23 -> V_25 ;
if ( V_25 == NULL )
goto V_29;
if ( V_25 -> V_32 & V_33 ) {
V_26 = F_14 ( 32u , V_18 -> V_34 ) ;
if ( ! F_10 ( V_18 , V_26 ) )
goto V_29;
F_15 ( V_35 L_1 , V_25 -> V_36 ) ;
V_27 = 0 ;
do {
F_15 ( L_2 , V_20 [ V_27 ] ) ;
} while ( ++ V_27 < V_26 );
F_15 ( L_3 ) ;
}
F_16 ( V_23 , V_18 , V_20 , V_21 , 0 , V_18 -> V_34 , V_25 -> V_37 ) ;
return 0 ;
V_30:
if ( ! F_10 ( V_18 , 12 ) )
goto V_29;
if ( ( V_18 -> V_28 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_29;
V_7 = F_11 ( * ( T_1 * ) & V_18 -> V_28 [ 4 ] ) ;
V_25 = F_17 ( & V_31 , V_7 ) ;
if ( V_25 != NULL )
V_3 = V_25 -> V_2 ;
else {
struct V_38 * V_39 = (struct V_38 * ) F_18 ( V_18 ) ;
F_19 ( & V_40 ) ;
V_3 = F_2 ( & V_31 , V_39 -> V_41 , 0 , V_7 ) ;
F_20 ( & V_40 ) ;
}
if ( V_3 == NULL )
goto V_29;
F_8 ( V_3 ) ;
if ( ! F_21 ( V_3 , V_42 , V_18 ) )
goto V_43;
F_22 ( V_18 ) ;
return F_23 ( V_3 , V_18 , 1 ) ;
V_43:
F_24 ( V_3 ) ;
V_29:
F_25 ( V_18 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_44 = V_45 ;
F_27 ( & V_40 ) ;
F_28 ( V_3 , & V_46 ) ;
F_29 ( & V_40 ) ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 , long V_47 )
{
F_27 ( & V_40 ) ;
F_31 ( & V_3 -> V_48 ) ;
F_32 ( V_3 ) ;
F_29 ( & V_40 ) ;
F_33 ( V_3 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
while ( ( V_18 = F_35 ( & V_3 -> V_49 ) ) != NULL )
F_25 ( V_18 ) ;
F_36 ( V_3 ) ;
}
static int F_37 ( struct V_2 * V_3 , struct V_50 * V_51 , int V_52 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_53 * V_54 = (struct V_53 * ) V_51 ;
int V_55 = - V_56 ;
int V_57 ;
V_55 = - V_58 ;
F_19 ( & V_40 ) ;
if ( F_2 ( & V_31 , V_54 -> V_59 . V_60 , V_3 -> V_15 , V_54 -> V_61 ) )
goto V_62;
F_20 ( & V_40 ) ;
F_38 ( V_3 ) ;
if ( V_3 -> V_63 != V_64 || V_52 < sizeof( struct V_53 ) )
goto V_65;
V_57 = F_39 ( & V_31 , V_54 -> V_59 . V_60 ) ;
V_55 = - V_66 ;
if ( V_54 -> V_59 . V_60 && V_57 != V_67 &&
V_57 != V_68 && V_57 != V_69 )
goto V_65;
if ( V_54 -> V_59 . V_60 )
V_11 -> V_14 = V_11 -> V_70 = V_54 -> V_59 . V_60 ;
if ( V_57 == V_68 || V_57 == V_69 )
V_11 -> V_70 = 0 ;
F_40 ( V_3 ) ;
F_1 ( V_3 ) -> V_13 = V_54 -> V_61 ;
F_27 ( & V_40 ) ;
F_41 ( V_3 , & V_71 ) ;
F_32 ( V_3 ) ;
F_29 ( & V_40 ) ;
V_55 = 0 ;
V_65:
F_42 ( V_3 ) ;
return V_55 ;
V_62:
F_20 ( & V_40 ) ;
return V_55 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_50 * V_51 , int V_52 )
{
struct V_53 * V_72 = (struct V_53 * ) V_51 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
T_1 V_77 ;
int V_78 , V_79 ;
V_79 = - V_56 ;
if ( V_52 < sizeof( * V_72 ) )
goto V_65;
V_79 = - V_80 ;
if ( V_72 -> V_81 != V_82 )
goto V_65;
F_38 ( V_3 ) ;
F_40 ( V_3 ) ;
V_78 = V_3 -> V_15 ;
V_77 = V_11 -> V_70 ;
V_79 = - V_56 ;
if ( F_44 ( V_72 -> V_59 . V_60 ) )
goto V_65;
V_74 = & V_11 -> V_83 . V_84 . V_85 . V_86 ;
V_76 = F_45 ( V_74 , V_72 -> V_59 . V_60 , V_77 ,
F_46 ( V_3 ) , V_78 ,
V_45 ,
0 , 0 , V_3 , true ) ;
if ( F_47 ( V_76 ) ) {
V_79 = F_48 ( V_76 ) ;
if ( V_79 == - V_87 )
F_49 ( & V_31 , V_88 ) ;
goto V_65;
}
V_79 = - V_87 ;
if ( V_76 -> V_89 & ( V_90 | V_91 ) ) {
F_50 ( V_76 ) ;
goto V_65;
}
F_1 ( V_3 ) -> V_92 = V_72 -> V_61 ;
if ( ! V_11 -> V_70 )
V_11 -> V_70 = V_74 -> V_77 ;
if ( ! V_11 -> V_14 )
V_11 -> V_14 = V_74 -> V_77 ;
V_11 -> V_93 = V_74 -> V_41 ;
V_3 -> V_63 = V_94 ;
V_11 -> V_95 = V_96 ;
F_51 ( V_3 , & V_76 -> V_97 ) ;
F_27 ( & V_40 ) ;
F_31 ( & V_3 -> V_48 ) ;
F_41 ( V_3 , & V_71 ) ;
F_29 ( & V_40 ) ;
V_79 = 0 ;
V_65:
F_42 ( V_3 ) ;
return V_79 ;
}
static int F_52 ( struct V_98 * V_2 , struct V_50 * V_51 ,
int * V_99 , int V_100 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_101 = F_1 ( V_3 ) ;
struct V_53 * V_72 = (struct V_53 * ) V_51 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_81 = V_82 ;
if ( V_100 ) {
if ( ! V_11 -> V_102 )
return - V_103 ;
V_72 -> V_61 = V_101 -> V_92 ;
V_72 -> V_59 . V_60 = V_11 -> V_93 ;
} else {
T_1 V_54 = V_11 -> V_14 ;
if ( ! V_54 )
V_54 = V_11 -> V_70 ;
V_72 -> V_61 = V_101 -> V_13 ;
V_72 -> V_59 . V_60 = V_54 ;
}
* V_99 = sizeof( * V_72 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_79 ;
V_79 = F_54 ( V_3 , V_18 ) ;
if ( V_79 < 0 )
goto V_104;
return 0 ;
V_104:
F_55 ( & V_31 , V_105 ) ;
F_25 ( V_18 ) ;
return - 1 ;
}
static int F_56 ( struct V_106 * V_107 , struct V_2 * V_3 , struct V_108 * V_109 , T_3 V_34 )
{
struct V_17 * V_18 ;
int V_79 ;
struct V_1 * V_72 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_75 * V_76 = NULL ;
struct V_73 * V_74 ;
int V_110 = 0 ;
T_1 V_41 ;
F_38 ( V_3 ) ;
V_79 = - V_103 ;
if ( F_57 ( V_3 , V_111 ) )
goto V_65;
if ( V_109 -> V_112 ) {
struct V_53 * V_113 = (struct V_53 * ) V_109 -> V_112 ;
V_79 = - V_56 ;
if ( V_109 -> V_114 < sizeof( * V_113 ) )
goto V_65;
if ( V_113 -> V_81 != V_82 ) {
V_79 = - V_80 ;
if ( V_113 -> V_81 != V_115 )
goto V_65;
}
V_41 = V_113 -> V_59 . V_60 ;
} else {
V_79 = - V_116 ;
if ( V_3 -> V_63 != V_94 )
goto V_65;
V_41 = V_11 -> V_93 ;
V_110 = 1 ;
}
V_79 = - V_117 ;
V_18 = F_58 ( V_3 , 2 + V_118 + sizeof( struct V_38 ) +
4 + V_34 , 0 , V_119 ) ;
if ( ! V_18 )
goto error;
F_59 ( V_18 , 2 + V_118 ) ;
F_60 ( V_18 ) ;
F_59 ( V_18 , sizeof( struct V_38 ) ) ;
F_61 ( V_18 ) ;
* ( ( T_1 * ) F_62 ( V_18 , 4 ) ) = 0 ;
V_79 = F_63 ( F_62 ( V_18 , V_34 ) , V_109 -> V_120 , V_34 ) ;
if ( V_79 < 0 ) {
F_25 ( V_18 ) ;
goto error;
}
V_74 = & V_11 -> V_83 . V_84 . V_85 . V_86 ;
if ( V_110 )
V_76 = (struct V_75 * ) F_64 ( V_3 , 0 ) ;
F_65 () ;
if ( V_76 == NULL ) {
const struct V_121 * V_122 ;
V_122 = F_66 ( V_11 -> V_122 ) ;
if ( V_122 && V_122 -> V_123 . V_124 )
V_41 = V_122 -> V_123 . V_125 ;
V_76 = F_67 ( F_6 ( V_3 ) , V_74 , V_3 ,
V_41 , V_11 -> V_70 ,
V_11 -> V_102 , V_11 -> V_126 ,
V_3 -> V_127 , F_46 ( V_3 ) ,
V_3 -> V_15 ) ;
if ( F_47 ( V_76 ) )
goto V_128;
if ( V_110 )
F_68 ( V_3 , & V_76 -> V_97 ) ;
else
F_69 ( & V_76 -> V_97 ) ;
}
F_70 ( V_18 , & V_76 -> V_97 ) ;
V_79 = F_71 ( V_18 , & V_11 -> V_83 . V_84 ) ;
F_72 () ;
error:
if ( V_79 >= 0 ) {
V_72 -> V_129 ++ ;
V_72 -> V_130 += V_34 ;
V_79 = V_34 ;
} else {
V_72 -> V_131 ++ ;
}
V_65:
F_42 ( V_3 ) ;
return V_79 ;
V_128:
F_72 () ;
F_55 ( F_6 ( V_3 ) , V_88 ) ;
F_25 ( V_18 ) ;
V_79 = - V_132 ;
goto V_65;
}
static int F_73 ( struct V_106 * V_107 , struct V_2 * V_3 , struct V_108 * V_109 ,
T_3 V_34 , int V_133 , int V_134 , int * V_52 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_101 = F_1 ( V_3 ) ;
T_3 V_135 = 0 ;
int V_136 = - V_137 ;
struct V_138 * sin = (struct V_138 * ) V_109 -> V_112 ;
struct V_17 * V_18 ;
if ( V_134 & V_139 )
goto V_65;
if ( V_52 )
* V_52 = sizeof( * sin ) ;
V_18 = F_74 ( V_3 , V_134 , V_133 , & V_136 ) ;
if ( ! V_18 )
goto V_65;
V_135 = V_18 -> V_34 ;
if ( V_34 < V_135 ) {
V_109 -> V_140 |= V_141 ;
V_135 = V_34 ;
}
V_136 = F_75 ( V_18 , 0 , V_109 -> V_120 , V_135 ) ;
if ( V_136 )
goto V_142;
F_76 ( V_109 , V_3 , V_18 ) ;
if ( sin ) {
sin -> V_143 = V_82 ;
sin -> V_144 . V_60 = F_77 ( V_18 ) -> V_77 ;
sin -> V_145 = 0 ;
memset ( & sin -> V_146 , 0 , sizeof( sin -> V_146 ) ) ;
}
if ( V_11 -> V_147 )
F_78 ( V_109 , V_18 ) ;
if ( V_134 & V_141 )
V_135 = V_18 -> V_34 ;
V_142:
F_79 ( V_3 , V_18 ) ;
V_65:
if ( V_136 ) {
V_101 -> V_148 ++ ;
return V_136 ;
}
V_101 -> V_149 ++ ;
V_101 -> V_150 += V_135 ;
return V_135 ;
}
static int T_4 F_80 ( void )
{
int V_136 ;
F_15 ( V_151 L_4 ) ;
V_136 = F_81 ( & V_152 , 1 ) ;
if ( V_136 != 0 )
goto V_65;
V_136 = F_82 ( & V_153 , V_45 ) ;
if ( V_136 )
goto V_154;
F_83 ( & V_155 ) ;
return 0 ;
V_154:
F_84 ( & V_152 ) ;
V_65:
return V_136 ;
}
static void T_5 F_85 ( void )
{
F_86 ( & V_155 ) ;
F_87 ( & V_153 , V_45 ) ;
F_84 ( & V_152 ) ;
}
