static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( struct V_4 * V_4 , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip_bind_table) {
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_10 == NULL )
continue;
if ( ( V_10 -> V_11 == V_7 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
! ( V_9 -> V_12 && V_9 -> V_12 != V_5 ) &&
! ( V_3 -> V_13 && V_3 -> V_13 != V_6 ) )
goto V_14;
}
V_3 = NULL ;
V_14:
return V_3 ;
}
static inline struct V_2 * F_7 ( struct V_4 * V_4 , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_2 * V_3 = F_2 ( V_4 , V_5 , V_6 , V_7 ) ;
if ( V_3 )
F_8 ( V_3 ) ;
return V_3 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_4 * V_4 = F_10 ( V_16 -> V_17 ) ;
struct V_2 * V_3 ;
T_2 V_18 ;
T_2 V_7 ;
unsigned char * V_19 , * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 = NULL ;
int V_25 ;
V_20 = V_19 = V_16 -> V_26 ;
if ( ! F_11 ( V_16 , 4 ) )
goto V_27;
V_18 = F_12 ( * ( ( T_1 * ) V_19 ) ) ;
V_19 += 4 ;
if ( V_18 == 0 ) {
F_13 ( V_16 , 4 ) ;
goto V_28;
}
V_22 = F_14 ( V_4 , NULL , V_18 ) ;
if ( V_22 == NULL )
goto V_27;
V_24 = V_22 -> V_24 ;
if ( V_24 == NULL )
goto V_27;
if ( V_24 -> V_29 & V_30 ) {
V_25 = F_15 ( 32u , V_16 -> V_31 ) ;
if ( ! F_11 ( V_16 , V_25 ) )
goto V_27;
F_16 ( L_1 , V_24 -> V_32 ) ;
F_17 ( L_2 , V_33 , V_19 , V_25 ) ;
}
F_18 ( V_22 , V_16 , V_19 , V_20 , 0 , V_16 -> V_31 , V_24 -> V_34 ) ;
return 0 ;
V_28:
if ( ! F_11 ( V_16 , 12 ) )
goto V_27;
if ( ( V_16 -> V_26 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_27;
V_7 = F_12 ( * ( T_1 * ) & V_16 -> V_26 [ 4 ] ) ;
V_24 = F_19 ( V_4 , V_7 ) ;
if ( V_24 != NULL )
V_3 = V_24 -> V_2 ;
else {
struct V_35 * V_36 = (struct V_35 * ) F_20 ( V_16 ) ;
F_21 ( & V_37 ) ;
V_3 = F_2 ( V_4 , V_36 -> V_38 , 0 , V_7 ) ;
F_22 ( & V_37 ) ;
}
if ( V_3 == NULL )
goto V_27;
F_8 ( V_3 ) ;
if ( ! F_23 ( V_3 , V_39 , V_16 ) )
goto V_40;
F_24 ( V_16 ) ;
return F_25 ( V_3 , V_16 , 1 ) ;
V_40:
F_26 ( V_3 ) ;
V_27:
F_27 ( V_16 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_41 = V_42 ;
F_29 ( & V_37 ) ;
F_30 ( V_3 , & V_43 ) ;
F_31 ( & V_37 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 , long V_44 )
{
F_29 ( & V_37 ) ;
F_33 ( & V_3 -> V_45 ) ;
F_34 ( V_3 ) ;
F_31 ( & V_37 ) ;
F_35 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
struct V_23 * V_24 = F_37 ( V_3 ) ;
while ( ( V_16 = F_38 ( & V_3 -> V_46 ) ) != NULL )
F_27 ( V_16 ) ;
if ( V_24 ) {
F_39 ( V_24 ) ;
F_26 ( V_3 ) ;
}
F_40 ( V_3 ) ;
}
static int F_41 ( struct V_2 * V_3 , struct V_47 * V_48 , int V_49 )
{
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
int V_52 ;
int V_53 ;
if ( ! F_42 ( V_3 , V_54 ) )
return - V_55 ;
if ( V_49 < sizeof( struct V_50 ) )
return - V_55 ;
if ( V_51 -> V_56 != V_57 )
return - V_55 ;
V_52 = - V_58 ;
F_21 ( & V_37 ) ;
if ( F_2 ( V_4 , V_51 -> V_59 . V_60 ,
V_3 -> V_13 , V_51 -> V_61 ) )
goto V_62;
F_22 ( & V_37 ) ;
F_43 ( V_3 ) ;
if ( V_3 -> V_63 != V_64 || V_49 < sizeof( struct V_50 ) )
goto V_65;
V_53 = F_44 ( V_4 , V_51 -> V_59 . V_60 ) ;
V_52 = - V_66 ;
if ( V_51 -> V_59 . V_60 && V_53 != V_67 &&
V_53 != V_68 && V_53 != V_69 )
goto V_65;
if ( V_51 -> V_59 . V_60 )
V_9 -> V_12 = V_9 -> V_70 = V_51 -> V_59 . V_60 ;
if ( V_53 == V_68 || V_53 == V_69 )
V_9 -> V_70 = 0 ;
F_45 ( V_3 ) ;
F_1 ( V_3 ) -> V_11 = V_51 -> V_61 ;
F_29 ( & V_37 ) ;
F_46 ( V_3 , & V_71 ) ;
F_34 ( V_3 ) ;
F_31 ( & V_37 ) ;
V_52 = 0 ;
F_47 ( V_3 , V_54 ) ;
V_65:
F_48 ( V_3 ) ;
return V_52 ;
V_62:
F_22 ( & V_37 ) ;
return V_52 ;
}
static int F_49 ( struct V_2 * V_3 , struct V_47 * V_48 , int V_49 )
{
struct V_50 * V_72 = (struct V_50 * ) V_48 ;
int V_73 ;
if ( F_42 ( V_3 , V_54 ) )
return - V_55 ;
if ( V_49 < sizeof( * V_72 ) )
return - V_55 ;
if ( F_50 ( V_72 -> V_59 . V_60 ) )
return - V_55 ;
V_73 = F_51 ( V_3 , V_48 , V_49 ) ;
if ( V_73 < 0 )
return V_73 ;
F_43 ( V_3 ) ;
F_1 ( V_3 ) -> V_74 = V_72 -> V_61 ;
F_29 ( & V_37 ) ;
F_33 ( & V_3 -> V_45 ) ;
F_46 ( V_3 , & V_71 ) ;
F_31 ( & V_37 ) ;
F_48 ( V_3 ) ;
return V_73 ;
}
static int F_52 ( struct V_2 * V_3 , int V_75 )
{
if ( F_42 ( V_3 , V_54 ) )
return 0 ;
return F_53 ( V_3 , V_75 ) ;
}
static int F_54 ( struct V_76 * V_2 , struct V_47 * V_48 ,
int * V_77 , int V_78 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_50 * V_72 = (struct V_50 * ) V_48 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_56 = V_57 ;
if ( V_78 ) {
if ( ! V_9 -> V_80 )
return - V_81 ;
V_72 -> V_61 = V_79 -> V_74 ;
V_72 -> V_59 . V_60 = V_9 -> V_82 ;
} else {
T_1 V_51 = V_9 -> V_12 ;
if ( ! V_51 )
V_51 = V_9 -> V_70 ;
V_72 -> V_61 = V_79 -> V_11 ;
V_72 -> V_59 . V_60 = V_51 ;
}
* V_77 = sizeof( * V_72 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
int V_73 ;
V_73 = F_56 ( V_3 , V_16 ) ;
if ( V_73 < 0 )
goto V_83;
return 0 ;
V_83:
F_57 ( F_6 ( V_3 ) , V_84 ) ;
F_27 ( V_16 ) ;
return - 1 ;
}
static int F_58 ( struct V_85 * V_86 , struct V_2 * V_3 , struct V_87 * V_88 , T_3 V_31 )
{
struct V_15 * V_16 ;
int V_73 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_89 * V_90 = NULL ;
struct V_91 * V_92 ;
int V_93 = 0 ;
T_1 V_38 ;
F_43 ( V_3 ) ;
V_73 = - V_81 ;
if ( F_42 ( V_3 , V_94 ) )
goto V_65;
if ( V_88 -> V_95 ) {
struct V_50 * V_96 = (struct V_50 * ) V_88 -> V_95 ;
V_73 = - V_55 ;
if ( V_88 -> V_97 < sizeof( * V_96 ) )
goto V_65;
if ( V_96 -> V_56 != V_57 ) {
V_73 = - V_98 ;
if ( V_96 -> V_56 != V_99 )
goto V_65;
}
V_38 = V_96 -> V_59 . V_60 ;
} else {
V_73 = - V_100 ;
if ( V_3 -> V_63 != V_101 )
goto V_65;
V_38 = V_9 -> V_82 ;
V_93 = 1 ;
}
V_73 = - V_102 ;
V_16 = F_59 ( V_3 , 2 + V_103 + sizeof( struct V_35 ) +
4 + V_31 , 0 , V_104 ) ;
if ( ! V_16 )
goto error;
F_60 ( V_16 , 2 + V_103 ) ;
F_61 ( V_16 ) ;
F_60 ( V_16 , sizeof( struct V_35 ) ) ;
F_62 ( V_16 ) ;
* ( ( T_1 * ) F_63 ( V_16 , 4 ) ) = 0 ;
V_73 = F_64 ( F_63 ( V_16 , V_31 ) , V_88 -> V_105 , V_31 ) ;
if ( V_73 < 0 ) {
F_27 ( V_16 ) ;
goto error;
}
V_92 = & V_9 -> V_106 . V_107 . V_108 . V_109 ;
if ( V_93 )
V_90 = (struct V_89 * ) F_65 ( V_3 , 0 ) ;
F_66 () ;
if ( V_90 == NULL ) {
const struct V_110 * V_111 ;
V_111 = F_67 ( V_9 -> V_111 ) ;
if ( V_111 && V_111 -> V_112 . V_113 )
V_38 = V_111 -> V_112 . V_114 ;
V_90 = F_68 ( F_6 ( V_3 ) , V_92 , V_3 ,
V_38 , V_9 -> V_70 ,
V_9 -> V_80 , V_9 -> V_115 ,
V_3 -> V_116 , F_69 ( V_3 ) ,
V_3 -> V_13 ) ;
if ( F_70 ( V_90 ) )
goto V_117;
if ( V_93 ) {
F_71 ( V_3 , & V_90 -> V_118 ) ;
} else {
F_72 ( V_16 , & V_90 -> V_118 ) ;
goto V_119;
}
}
F_73 ( V_16 , & V_90 -> V_118 ) ;
V_119:
V_73 = F_74 ( V_16 , & V_9 -> V_106 . V_107 ) ;
F_75 () ;
error:
if ( V_73 >= 0 )
V_73 = V_31 ;
V_65:
F_48 ( V_3 ) ;
return V_73 ;
V_117:
F_75 () ;
F_57 ( F_6 ( V_3 ) , V_120 ) ;
F_27 ( V_16 ) ;
V_73 = - V_121 ;
goto V_65;
}
static int F_76 ( struct V_85 * V_86 , struct V_2 * V_3 , struct V_87 * V_88 ,
T_3 V_31 , int V_122 , int V_75 , int * V_49 )
{
struct V_8 * V_9 = F_4 ( V_3 ) ;
T_3 V_123 = 0 ;
int V_124 = - V_125 ;
struct V_126 * sin = (struct V_126 * ) V_88 -> V_95 ;
struct V_15 * V_16 ;
if ( V_75 & V_127 )
goto V_65;
V_16 = F_77 ( V_3 , V_75 , V_122 , & V_124 ) ;
if ( ! V_16 )
goto V_65;
V_123 = V_16 -> V_31 ;
if ( V_31 < V_123 ) {
V_88 -> V_128 |= V_129 ;
V_123 = V_31 ;
}
V_124 = F_78 ( V_16 , 0 , V_88 -> V_105 , V_123 ) ;
if ( V_124 )
goto V_130;
F_79 ( V_88 , V_3 , V_16 ) ;
if ( sin ) {
sin -> V_131 = V_57 ;
sin -> V_132 . V_60 = F_80 ( V_16 ) -> V_133 ;
sin -> V_134 = 0 ;
memset ( & sin -> V_135 , 0 , sizeof( sin -> V_135 ) ) ;
* V_49 = sizeof( * sin ) ;
}
if ( V_9 -> V_136 )
F_81 ( V_88 , V_16 ) ;
if ( V_75 & V_129 )
V_123 = V_16 -> V_31 ;
V_130:
F_82 ( V_3 , V_16 ) ;
V_65:
return V_124 ? V_124 : V_123 ;
}
static int T_4 F_83 ( void )
{
int V_124 ;
F_84 ( L_3 ) ;
V_124 = F_85 ( & V_137 , 1 ) ;
if ( V_124 != 0 )
goto V_65;
V_124 = F_86 ( & V_138 , V_42 ) ;
if ( V_124 )
goto V_139;
F_87 ( & V_140 ) ;
return 0 ;
V_139:
F_88 ( & V_137 ) ;
V_65:
return V_124 ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_140 ) ;
F_91 ( & V_138 , V_42 ) ;
F_88 ( & V_137 ) ;
}
