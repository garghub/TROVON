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
F_31 ( & V_3 -> V_49 ) ;
F_29 ( & V_40 ) ;
F_32 ( V_3 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
while ( ( V_18 = F_34 ( & V_3 -> V_50 ) ) != NULL )
F_25 ( V_18 ) ;
F_35 ( V_3 ) ;
}
static int F_36 ( struct V_2 * V_3 , struct V_51 * V_52 , int V_53 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_52 ;
int V_56 = - V_57 ;
int V_58 ;
V_56 = - V_59 ;
F_19 ( & V_40 ) ;
if ( F_2 ( & V_31 , V_55 -> V_60 . V_61 , V_3 -> V_15 , V_55 -> V_62 ) )
goto V_63;
F_20 ( & V_40 ) ;
F_37 ( V_3 ) ;
if ( V_3 -> V_64 != V_65 || V_53 < sizeof( struct V_54 ) )
goto V_66;
V_58 = F_38 ( & V_31 , V_55 -> V_60 . V_61 ) ;
V_56 = - V_67 ;
if ( V_55 -> V_60 . V_61 && V_58 != V_68 &&
V_58 != V_69 && V_58 != V_70 )
goto V_66;
V_11 -> V_14 = V_11 -> V_71 = V_55 -> V_60 . V_61 ;
if ( V_58 == V_69 || V_58 == V_70 )
V_11 -> V_71 = 0 ;
F_39 ( V_3 ) ;
F_1 ( V_3 ) -> V_13 = V_55 -> V_62 ;
F_27 ( & V_40 ) ;
F_40 ( V_3 , & V_72 ) ;
F_41 ( V_3 ) ;
F_29 ( & V_40 ) ;
V_56 = 0 ;
V_66:
F_42 ( V_3 ) ;
return V_56 ;
V_63:
F_20 ( & V_40 ) ;
return V_56 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_51 * V_52 , int V_53 )
{
struct V_54 * V_73 = (struct V_54 * ) V_52 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_1 V_78 ;
int V_79 , V_80 ;
V_80 = - V_57 ;
if ( V_53 < sizeof( * V_73 ) )
goto V_66;
V_80 = - V_81 ;
if ( V_73 -> V_82 != V_83 )
goto V_66;
F_37 ( V_3 ) ;
F_39 ( V_3 ) ;
V_79 = V_3 -> V_15 ;
V_78 = V_11 -> V_71 ;
V_80 = - V_57 ;
if ( F_44 ( V_73 -> V_60 . V_61 ) )
goto V_66;
V_75 = & V_11 -> V_84 . V_85 . V_86 . V_87 ;
V_77 = F_45 ( V_75 , V_73 -> V_60 . V_61 , V_78 ,
F_46 ( V_3 ) , V_79 ,
V_45 ,
0 , 0 , V_3 , true ) ;
if ( F_47 ( V_77 ) ) {
V_80 = F_48 ( V_77 ) ;
if ( V_80 == - V_88 )
F_49 ( & V_31 , V_89 ) ;
goto V_66;
}
V_80 = - V_88 ;
if ( V_77 -> V_90 & ( V_91 | V_92 ) ) {
F_50 ( V_77 ) ;
goto V_66;
}
F_1 ( V_3 ) -> V_93 = V_73 -> V_62 ;
if ( ! V_11 -> V_71 )
V_11 -> V_71 = V_75 -> V_78 ;
if ( ! V_11 -> V_14 )
V_11 -> V_14 = V_75 -> V_78 ;
V_11 -> V_94 = V_75 -> V_41 ;
V_3 -> V_64 = V_95 ;
V_11 -> V_96 = V_97 ;
F_51 ( V_3 , & V_77 -> V_98 ) ;
F_27 ( & V_40 ) ;
F_31 ( & V_3 -> V_48 ) ;
F_40 ( V_3 , & V_72 ) ;
F_29 ( & V_40 ) ;
V_80 = 0 ;
V_66:
F_42 ( V_3 ) ;
return V_80 ;
}
static int F_52 ( struct V_99 * V_2 , struct V_51 * V_52 ,
int * V_100 , int V_101 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_102 = F_1 ( V_3 ) ;
struct V_54 * V_73 = (struct V_54 * ) V_52 ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_73 -> V_82 = V_83 ;
if ( V_101 ) {
if ( ! V_11 -> V_103 )
return - V_104 ;
V_73 -> V_62 = V_102 -> V_93 ;
V_73 -> V_60 . V_61 = V_11 -> V_94 ;
} else {
T_1 V_55 = V_11 -> V_14 ;
if ( ! V_55 )
V_55 = V_11 -> V_71 ;
V_73 -> V_62 = V_102 -> V_13 ;
V_73 -> V_60 . V_61 = V_55 ;
}
* V_100 = sizeof( * V_73 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_80 ;
if ( ! F_21 ( V_3 , V_42 , V_18 ) )
goto V_105;
F_22 ( V_18 ) ;
V_80 = F_54 ( V_3 , V_18 ) ;
if ( V_80 < 0 )
goto V_105;
return 0 ;
V_105:
F_55 ( & V_31 , V_106 ) ;
F_25 ( V_18 ) ;
return - 1 ;
}
static int F_56 ( struct V_107 * V_108 , struct V_2 * V_3 , struct V_109 * V_110 , T_3 V_34 )
{
struct V_17 * V_18 ;
int V_80 ;
struct V_1 * V_73 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_76 * V_77 = NULL ;
struct V_74 * V_75 ;
int V_111 = 0 ;
T_1 V_41 ;
F_37 ( V_3 ) ;
V_80 = - V_104 ;
if ( F_57 ( V_3 , V_112 ) )
goto V_66;
if ( V_110 -> V_113 ) {
struct V_54 * V_114 = (struct V_54 * ) V_110 -> V_113 ;
V_80 = - V_57 ;
if ( V_110 -> V_115 < sizeof( * V_114 ) )
goto V_66;
if ( V_114 -> V_82 != V_83 ) {
V_80 = - V_81 ;
if ( V_114 -> V_82 != V_116 )
goto V_66;
}
V_41 = V_114 -> V_60 . V_61 ;
} else {
if ( V_3 -> V_64 != V_95 )
return - V_117 ;
V_41 = V_11 -> V_94 ;
V_111 = 1 ;
}
V_80 = - V_118 ;
V_18 = F_58 ( V_3 , 2 + V_119 + sizeof( struct V_38 ) +
4 + V_34 , 0 , V_120 ) ;
if ( ! V_18 )
goto error;
F_59 ( V_18 , 2 + V_119 ) ;
F_60 ( V_18 ) ;
F_59 ( V_18 , sizeof( struct V_38 ) ) ;
F_61 ( V_18 ) ;
* ( ( T_1 * ) F_62 ( V_18 , 4 ) ) = 0 ;
V_80 = F_63 ( F_62 ( V_18 , V_34 ) , V_110 -> V_121 , V_34 ) ;
if ( V_80 < 0 ) {
F_25 ( V_18 ) ;
goto error;
}
V_75 = & V_11 -> V_84 . V_85 . V_86 . V_87 ;
if ( V_111 )
V_77 = (struct V_76 * ) F_64 ( V_3 , 0 ) ;
F_65 () ;
if ( V_77 == NULL ) {
const struct V_122 * V_123 ;
V_123 = F_66 ( V_11 -> V_123 ) ;
if ( V_123 && V_123 -> V_124 . V_125 )
V_41 = V_123 -> V_124 . V_126 ;
V_77 = F_67 ( F_6 ( V_3 ) , V_75 , V_3 ,
V_41 , V_11 -> V_71 ,
V_11 -> V_103 , V_11 -> V_127 ,
V_3 -> V_128 , F_46 ( V_3 ) ,
V_3 -> V_15 ) ;
if ( F_47 ( V_77 ) )
goto V_129;
if ( V_111 )
F_68 ( V_3 , & V_77 -> V_98 ) ;
else
F_69 ( & V_77 -> V_98 ) ;
}
F_70 ( V_18 , & V_77 -> V_98 ) ;
V_80 = F_71 ( V_18 , & V_11 -> V_84 . V_85 ) ;
F_72 () ;
error:
if ( V_80 >= 0 ) {
V_73 -> V_130 ++ ;
V_73 -> V_131 += V_34 ;
V_80 = V_34 ;
} else {
V_73 -> V_132 ++ ;
}
V_66:
F_42 ( V_3 ) ;
return V_80 ;
V_129:
F_72 () ;
F_55 ( F_6 ( V_3 ) , V_89 ) ;
F_25 ( V_18 ) ;
V_80 = - V_133 ;
goto V_66;
}
static int F_73 ( struct V_107 * V_108 , struct V_2 * V_3 , struct V_109 * V_110 ,
T_3 V_34 , int V_134 , int V_135 , int * V_53 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_102 = F_1 ( V_3 ) ;
T_3 V_136 = 0 ;
int V_137 = - V_138 ;
struct V_139 * sin = (struct V_139 * ) V_110 -> V_113 ;
struct V_17 * V_18 ;
if ( V_135 & V_140 )
goto V_66;
if ( V_53 )
* V_53 = sizeof( * sin ) ;
V_18 = F_74 ( V_3 , V_135 , V_134 , & V_137 ) ;
if ( ! V_18 )
goto V_66;
V_136 = V_18 -> V_34 ;
if ( V_34 < V_136 ) {
V_110 -> V_141 |= V_142 ;
V_136 = V_34 ;
}
V_137 = F_75 ( V_18 , 0 , V_110 -> V_121 , V_136 ) ;
if ( V_137 )
goto V_143;
F_76 ( V_110 , V_3 , V_18 ) ;
if ( sin ) {
sin -> V_144 = V_83 ;
sin -> V_145 . V_61 = F_77 ( V_18 ) -> V_78 ;
sin -> V_146 = 0 ;
memset ( & sin -> V_147 , 0 , sizeof( sin -> V_147 ) ) ;
}
if ( V_11 -> V_148 )
F_78 ( V_110 , V_18 ) ;
if ( V_135 & V_142 )
V_136 = V_18 -> V_34 ;
V_143:
F_79 ( V_3 , V_18 ) ;
V_66:
if ( V_137 ) {
V_102 -> V_149 ++ ;
return V_137 ;
}
V_102 -> V_150 ++ ;
V_102 -> V_151 += V_136 ;
return V_136 ;
}
static int T_4 F_80 ( void )
{
int V_137 ;
F_15 ( V_152 L_4 ) ;
V_137 = F_81 ( & V_153 , 1 ) ;
if ( V_137 != 0 )
goto V_66;
V_137 = F_82 ( & V_154 , V_45 ) ;
if ( V_137 )
goto V_155;
F_83 ( & V_156 ) ;
return 0 ;
V_155:
F_84 ( & V_153 ) ;
V_66:
return V_137 ;
}
static void T_5 F_85 ( void )
{
F_86 ( & V_156 ) ;
F_87 ( & V_154 , V_45 ) ;
F_84 ( & V_153 ) ;
}
