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
V_21 = V_20 = V_18 -> V_27 ;
if ( ! F_10 ( V_18 , 4 ) )
goto V_28;
V_19 = F_11 ( * ( ( T_1 * ) V_20 ) ) ;
V_20 += 4 ;
if ( V_19 == 0 ) {
F_12 ( V_18 , 4 ) ;
goto V_29;
}
V_23 = F_13 ( & V_30 , NULL , V_19 ) ;
if ( V_23 == NULL )
goto V_28;
V_25 = V_23 -> V_25 ;
if ( V_25 == NULL )
goto V_28;
if ( V_25 -> V_31 & V_32 ) {
V_26 = F_14 ( 32u , V_18 -> V_33 ) ;
if ( ! F_10 ( V_18 , V_26 ) )
goto V_28;
F_15 ( L_1 , V_25 -> V_34 ) ;
F_16 ( L_2 , V_35 , V_20 , V_26 ) ;
}
F_17 ( V_23 , V_18 , V_20 , V_21 , 0 , V_18 -> V_33 , V_25 -> V_36 ) ;
return 0 ;
V_29:
if ( ! F_10 ( V_18 , 12 ) )
goto V_28;
if ( ( V_18 -> V_27 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_28;
V_7 = F_11 ( * ( T_1 * ) & V_18 -> V_27 [ 4 ] ) ;
V_25 = F_18 ( & V_30 , V_7 ) ;
if ( V_25 != NULL )
V_3 = V_25 -> V_2 ;
else {
struct V_37 * V_38 = (struct V_37 * ) F_19 ( V_18 ) ;
F_20 ( & V_39 ) ;
V_3 = F_2 ( & V_30 , V_38 -> V_40 , 0 , V_7 ) ;
F_21 ( & V_39 ) ;
}
if ( V_3 == NULL )
goto V_28;
F_8 ( V_3 ) ;
if ( ! F_22 ( V_3 , V_41 , V_18 ) )
goto V_42;
F_23 ( V_18 ) ;
return F_24 ( V_3 , V_18 , 1 ) ;
V_42:
F_25 ( V_3 ) ;
V_28:
F_26 ( V_18 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_43 = V_44 ;
F_28 ( & V_39 ) ;
F_29 ( V_3 , & V_45 ) ;
F_30 ( & V_39 ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 , long V_46 )
{
F_28 ( & V_39 ) ;
F_32 ( & V_3 -> V_47 ) ;
F_33 ( V_3 ) ;
F_30 ( & V_39 ) ;
F_34 ( V_3 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
while ( ( V_18 = F_36 ( & V_3 -> V_48 ) ) != NULL )
F_26 ( V_18 ) ;
F_37 ( V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_49 * V_50 , int V_51 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_52 * V_53 = (struct V_52 * ) V_50 ;
int V_54 ;
int V_55 ;
if ( ! F_39 ( V_3 , V_56 ) )
return - V_57 ;
if ( V_51 < sizeof( struct V_52 ) )
return - V_57 ;
if ( V_53 -> V_58 != V_59 )
return - V_57 ;
V_54 = - V_60 ;
F_20 ( & V_39 ) ;
if ( F_2 ( & V_30 , V_53 -> V_61 . V_62 , V_3 -> V_15 , V_53 -> V_63 ) )
goto V_64;
F_21 ( & V_39 ) ;
F_40 ( V_3 ) ;
if ( V_3 -> V_65 != V_66 || V_51 < sizeof( struct V_52 ) )
goto V_67;
V_55 = F_41 ( & V_30 , V_53 -> V_61 . V_62 ) ;
V_54 = - V_68 ;
if ( V_53 -> V_61 . V_62 && V_55 != V_69 &&
V_55 != V_70 && V_55 != V_71 )
goto V_67;
if ( V_53 -> V_61 . V_62 )
V_11 -> V_14 = V_11 -> V_72 = V_53 -> V_61 . V_62 ;
if ( V_55 == V_70 || V_55 == V_71 )
V_11 -> V_72 = 0 ;
F_42 ( V_3 ) ;
F_1 ( V_3 ) -> V_13 = V_53 -> V_63 ;
F_28 ( & V_39 ) ;
F_43 ( V_3 , & V_73 ) ;
F_33 ( V_3 ) ;
F_30 ( & V_39 ) ;
V_54 = 0 ;
F_44 ( V_3 , V_56 ) ;
V_67:
F_45 ( V_3 ) ;
return V_54 ;
V_64:
F_21 ( & V_39 ) ;
return V_54 ;
}
static int F_46 ( struct V_2 * V_3 , struct V_49 * V_50 , int V_51 )
{
struct V_52 * V_74 = (struct V_52 * ) V_50 ;
int V_75 ;
if ( F_39 ( V_3 , V_56 ) )
return - V_57 ;
if ( V_51 < sizeof( * V_74 ) )
return - V_57 ;
if ( F_47 ( V_74 -> V_61 . V_62 ) )
return - V_57 ;
V_75 = F_48 ( V_3 , V_50 , V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
F_40 ( V_3 ) ;
F_1 ( V_3 ) -> V_76 = V_74 -> V_63 ;
F_28 ( & V_39 ) ;
F_32 ( & V_3 -> V_47 ) ;
F_43 ( V_3 , & V_73 ) ;
F_30 ( & V_39 ) ;
F_45 ( V_3 ) ;
return V_75 ;
}
static int F_49 ( struct V_2 * V_3 , int V_77 )
{
if ( F_39 ( V_3 , V_56 ) )
return 0 ;
return F_50 ( V_3 , V_77 ) ;
}
static int F_51 ( struct V_78 * V_2 , struct V_49 * V_50 ,
int * V_79 , int V_80 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_81 = F_1 ( V_3 ) ;
struct V_52 * V_74 = (struct V_52 * ) V_50 ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_58 = V_59 ;
if ( V_80 ) {
if ( ! V_11 -> V_82 )
return - V_83 ;
V_74 -> V_63 = V_81 -> V_76 ;
V_74 -> V_61 . V_62 = V_11 -> V_84 ;
} else {
T_1 V_53 = V_11 -> V_14 ;
if ( ! V_53 )
V_53 = V_11 -> V_72 ;
V_74 -> V_63 = V_81 -> V_13 ;
V_74 -> V_61 . V_62 = V_53 ;
}
* V_79 = sizeof( * V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_75 ;
V_75 = F_53 ( V_3 , V_18 ) ;
if ( V_75 < 0 )
goto V_85;
return 0 ;
V_85:
F_54 ( & V_30 , V_86 ) ;
F_26 ( V_18 ) ;
return - 1 ;
}
static int F_55 ( struct V_87 * V_88 , struct V_2 * V_3 , struct V_89 * V_90 , T_3 V_33 )
{
struct V_17 * V_18 ;
int V_75 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_91 * V_92 = NULL ;
struct V_93 * V_94 ;
int V_95 = 0 ;
T_1 V_40 ;
F_40 ( V_3 ) ;
V_75 = - V_83 ;
if ( F_39 ( V_3 , V_96 ) )
goto V_67;
if ( V_90 -> V_97 ) {
struct V_52 * V_98 = (struct V_52 * ) V_90 -> V_97 ;
V_75 = - V_57 ;
if ( V_90 -> V_99 < sizeof( * V_98 ) )
goto V_67;
if ( V_98 -> V_58 != V_59 ) {
V_75 = - V_100 ;
if ( V_98 -> V_58 != V_101 )
goto V_67;
}
V_40 = V_98 -> V_61 . V_62 ;
} else {
V_75 = - V_102 ;
if ( V_3 -> V_65 != V_103 )
goto V_67;
V_40 = V_11 -> V_84 ;
V_95 = 1 ;
}
V_75 = - V_104 ;
V_18 = F_56 ( V_3 , 2 + V_105 + sizeof( struct V_37 ) +
4 + V_33 , 0 , V_106 ) ;
if ( ! V_18 )
goto error;
F_57 ( V_18 , 2 + V_105 ) ;
F_58 ( V_18 ) ;
F_57 ( V_18 , sizeof( struct V_37 ) ) ;
F_59 ( V_18 ) ;
* ( ( T_1 * ) F_60 ( V_18 , 4 ) ) = 0 ;
V_75 = F_61 ( F_60 ( V_18 , V_33 ) , V_90 -> V_107 , V_33 ) ;
if ( V_75 < 0 ) {
F_26 ( V_18 ) ;
goto error;
}
V_94 = & V_11 -> V_108 . V_109 . V_110 . V_111 ;
if ( V_95 )
V_92 = (struct V_91 * ) F_62 ( V_3 , 0 ) ;
F_63 () ;
if ( V_92 == NULL ) {
const struct V_112 * V_113 ;
V_113 = F_64 ( V_11 -> V_113 ) ;
if ( V_113 && V_113 -> V_114 . V_115 )
V_40 = V_113 -> V_114 . V_116 ;
V_92 = F_65 ( F_6 ( V_3 ) , V_94 , V_3 ,
V_40 , V_11 -> V_72 ,
V_11 -> V_82 , V_11 -> V_117 ,
V_3 -> V_118 , F_66 ( V_3 ) ,
V_3 -> V_15 ) ;
if ( F_67 ( V_92 ) )
goto V_119;
if ( V_95 ) {
F_68 ( V_3 , & V_92 -> V_120 ) ;
} else {
F_69 ( V_18 , & V_92 -> V_120 ) ;
goto V_121;
}
}
F_70 ( V_18 , & V_92 -> V_120 ) ;
V_121:
V_75 = F_71 ( V_18 , & V_11 -> V_108 . V_109 ) ;
F_72 () ;
error:
if ( V_75 >= 0 )
V_75 = V_33 ;
V_67:
F_45 ( V_3 ) ;
return V_75 ;
V_119:
F_72 () ;
F_54 ( F_6 ( V_3 ) , V_122 ) ;
F_26 ( V_18 ) ;
V_75 = - V_123 ;
goto V_67;
}
static int F_73 ( struct V_87 * V_88 , struct V_2 * V_3 , struct V_89 * V_90 ,
T_3 V_33 , int V_124 , int V_77 , int * V_51 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
T_3 V_125 = 0 ;
int V_126 = - V_127 ;
struct V_128 * sin = (struct V_128 * ) V_90 -> V_97 ;
struct V_17 * V_18 ;
if ( V_77 & V_129 )
goto V_67;
if ( V_51 )
* V_51 = sizeof( * sin ) ;
V_18 = F_74 ( V_3 , V_77 , V_124 , & V_126 ) ;
if ( ! V_18 )
goto V_67;
V_125 = V_18 -> V_33 ;
if ( V_33 < V_125 ) {
V_90 -> V_130 |= V_131 ;
V_125 = V_33 ;
}
V_126 = F_75 ( V_18 , 0 , V_90 -> V_107 , V_125 ) ;
if ( V_126 )
goto V_132;
F_76 ( V_90 , V_3 , V_18 ) ;
if ( sin ) {
sin -> V_133 = V_59 ;
sin -> V_134 . V_62 = F_77 ( V_18 ) -> V_135 ;
sin -> V_136 = 0 ;
memset ( & sin -> V_137 , 0 , sizeof( sin -> V_137 ) ) ;
}
if ( V_11 -> V_138 )
F_78 ( V_90 , V_18 ) ;
if ( V_77 & V_131 )
V_125 = V_18 -> V_33 ;
V_132:
F_79 ( V_3 , V_18 ) ;
V_67:
return V_126 ? V_126 : V_125 ;
}
static int T_4 F_80 ( void )
{
int V_126 ;
F_81 ( L_3 ) ;
V_126 = F_82 ( & V_139 , 1 ) ;
if ( V_126 != 0 )
goto V_67;
V_126 = F_83 ( & V_140 , V_44 ) ;
if ( V_126 )
goto V_141;
F_84 ( & V_142 ) ;
return 0 ;
V_141:
F_85 ( & V_139 ) ;
V_67:
return V_126 ;
}
static void T_5 F_86 ( void )
{
F_87 ( & V_142 ) ;
F_88 ( & V_140 , V_44 ) ;
F_85 ( & V_139 ) ;
}
