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
( ! V_3 -> V_13 || ! V_6 ||
V_3 -> V_13 == V_6 ) )
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
if ( ! F_11 ( V_16 , 4 ) )
goto V_26;
V_20 = V_19 = V_16 -> V_27 ;
V_18 = F_12 ( * ( ( T_1 * ) V_19 ) ) ;
V_19 += 4 ;
if ( V_18 == 0 ) {
F_13 ( V_16 , 4 ) ;
goto V_28;
}
V_22 = F_14 ( V_4 , NULL , V_18 ) ;
if ( V_22 == NULL )
goto V_26;
V_24 = V_22 -> V_24 ;
if ( V_24 == NULL )
goto V_26;
if ( V_24 -> V_29 & V_30 ) {
V_25 = F_15 ( 32u , V_16 -> V_31 ) ;
if ( ! F_11 ( V_16 , V_25 ) )
goto V_26;
V_20 = V_19 = V_16 -> V_27 ;
V_19 += 4 ;
F_16 ( L_1 , V_24 -> V_32 ) ;
F_17 ( L_2 , V_33 , V_19 , V_25 ) ;
}
F_18 ( V_22 , V_16 , V_19 , V_20 , 0 , V_16 -> V_31 , V_24 -> V_34 ) ;
return 0 ;
V_28:
if ( ! F_11 ( V_16 , 12 ) )
goto V_26;
if ( ( V_16 -> V_27 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_26;
V_7 = F_12 ( * ( T_1 * ) & V_16 -> V_27 [ 4 ] ) ;
V_24 = F_19 ( V_4 , V_7 ) ;
if ( V_24 != NULL )
V_3 = V_24 -> V_2 ;
else {
struct V_35 * V_36 = (struct V_35 * ) F_20 ( V_16 ) ;
F_21 ( & V_37 ) ;
V_3 = F_2 ( V_4 , V_36 -> V_38 , F_22 ( V_16 ) ,
V_7 ) ;
if ( ! V_3 ) {
F_23 ( & V_37 ) ;
goto V_26;
}
F_8 ( V_3 ) ;
F_23 ( & V_37 ) ;
}
if ( ! F_24 ( V_3 , V_39 , V_16 ) )
goto V_40;
F_25 ( V_16 ) ;
return F_26 ( V_3 , V_16 , 1 ) ;
V_40:
F_27 ( V_3 ) ;
V_26:
F_28 ( V_16 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_41 = V_42 ;
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
struct V_15 * V_16 ;
struct V_23 * V_24 = F_38 ( V_3 ) ;
while ( ( V_16 = F_39 ( & V_3 -> V_46 ) ) != NULL )
F_28 ( V_16 ) ;
if ( V_24 ) {
F_40 ( V_24 ) ;
F_27 ( V_3 ) ;
}
F_41 ( V_3 ) ;
}
static int F_42 ( struct V_2 * V_3 , struct V_47 * V_48 , int V_49 )
{
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_50 * V_51 = (struct V_50 * ) V_48 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
int V_52 ;
int V_53 ;
if ( V_49 < sizeof( struct V_50 ) )
return - V_54 ;
if ( V_51 -> V_55 != V_56 )
return - V_54 ;
F_43 ( V_3 ) ;
V_52 = - V_54 ;
if ( ! F_44 ( V_3 , V_57 ) )
goto V_58;
if ( V_3 -> V_59 != V_60 || V_49 < sizeof( struct V_50 ) )
goto V_58;
V_53 = F_45 ( V_4 , V_51 -> V_61 . V_62 ) ;
V_52 = - V_63 ;
if ( V_51 -> V_61 . V_62 && V_53 != V_64 &&
V_53 != V_65 && V_53 != V_66 )
goto V_58;
if ( V_51 -> V_61 . V_62 )
V_9 -> V_12 = V_9 -> V_67 = V_51 -> V_61 . V_62 ;
if ( V_53 == V_65 || V_53 == V_66 )
V_9 -> V_67 = 0 ;
F_30 ( & V_37 ) ;
if ( F_2 ( V_4 , V_51 -> V_61 . V_62 ,
V_3 -> V_13 , V_51 -> V_68 ) ) {
F_32 ( & V_37 ) ;
V_52 = - V_69 ;
goto V_58;
}
F_46 ( V_3 ) ;
F_1 ( V_3 ) -> V_11 = V_51 -> V_68 ;
F_47 ( V_3 , & V_70 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_37 ) ;
V_52 = 0 ;
F_48 ( V_3 , V_57 ) ;
V_58:
F_49 ( V_3 ) ;
return V_52 ;
}
static int F_50 ( struct V_2 * V_3 , struct V_47 * V_48 , int V_49 )
{
struct V_50 * V_71 = (struct V_50 * ) V_48 ;
int V_72 ;
if ( V_49 < sizeof( * V_71 ) )
return - V_54 ;
if ( F_51 ( V_71 -> V_61 . V_62 ) )
return - V_54 ;
F_43 ( V_3 ) ;
if ( F_44 ( V_3 , V_57 ) ) {
V_72 = - V_54 ;
goto V_73;
}
V_72 = F_52 ( V_3 , V_48 , V_49 ) ;
if ( V_72 < 0 )
goto V_73;
F_1 ( V_3 ) -> V_74 = V_71 -> V_68 ;
F_30 ( & V_37 ) ;
F_34 ( & V_3 -> V_45 ) ;
F_47 ( V_3 , & V_70 ) ;
F_32 ( & V_37 ) ;
V_73:
F_49 ( V_3 ) ;
return V_72 ;
}
static int F_53 ( struct V_2 * V_3 , int V_75 )
{
if ( F_44 ( V_3 , V_57 ) )
return 0 ;
return F_54 ( V_3 , V_75 ) ;
}
static int F_55 ( struct V_76 * V_2 , struct V_47 * V_48 ,
int * V_77 , int V_78 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_1 * V_79 = F_1 ( V_3 ) ;
struct V_50 * V_71 = (struct V_50 * ) V_48 ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
V_71 -> V_55 = V_56 ;
if ( V_78 ) {
if ( ! V_9 -> V_80 )
return - V_81 ;
V_71 -> V_68 = V_79 -> V_74 ;
V_71 -> V_61 . V_62 = V_9 -> V_82 ;
} else {
T_1 V_51 = V_9 -> V_12 ;
if ( ! V_51 )
V_51 = V_9 -> V_67 ;
V_71 -> V_68 = V_79 -> V_11 ;
V_71 -> V_61 . V_62 = V_51 ;
}
* V_77 = sizeof( * V_71 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
int V_72 ;
V_72 = F_57 ( V_3 , V_16 ) ;
if ( V_72 < 0 )
goto V_83;
return 0 ;
V_83:
F_58 ( F_6 ( V_3 ) , V_84 ) ;
F_28 ( V_16 ) ;
return - 1 ;
}
static int F_59 ( struct V_2 * V_3 , struct V_85 * V_86 , T_3 V_31 )
{
struct V_15 * V_16 ;
int V_72 ;
struct V_8 * V_9 = F_4 ( V_3 ) ;
struct V_87 * V_88 = NULL ;
struct V_89 * V_90 ;
int V_91 = 0 ;
T_1 V_38 ;
F_43 ( V_3 ) ;
V_72 = - V_81 ;
if ( F_44 ( V_3 , V_92 ) )
goto V_58;
if ( V_86 -> V_93 ) {
F_60 ( struct V_50 * , V_94 , V_86 -> V_93 ) ;
V_72 = - V_54 ;
if ( V_86 -> V_95 < sizeof( * V_94 ) )
goto V_58;
if ( V_94 -> V_55 != V_56 ) {
V_72 = - V_96 ;
if ( V_94 -> V_55 != V_97 )
goto V_58;
}
V_38 = V_94 -> V_61 . V_62 ;
} else {
V_72 = - V_98 ;
if ( V_3 -> V_59 != V_99 )
goto V_58;
V_38 = V_9 -> V_82 ;
V_91 = 1 ;
}
V_72 = - V_100 ;
V_16 = F_61 ( V_3 , 2 + V_101 + sizeof( struct V_35 ) +
4 + V_31 , 0 , V_102 ) ;
if ( ! V_16 )
goto error;
F_62 ( V_16 , 2 + V_101 ) ;
F_63 ( V_16 ) ;
F_62 ( V_16 , sizeof( struct V_35 ) ) ;
F_64 ( V_16 ) ;
* ( ( T_1 * ) F_65 ( V_16 , 4 ) ) = 0 ;
V_72 = F_66 ( F_65 ( V_16 , V_31 ) , V_86 , V_31 ) ;
if ( V_72 < 0 ) {
F_28 ( V_16 ) ;
goto error;
}
V_90 = & V_9 -> V_103 . V_104 . V_105 . V_106 ;
if ( V_91 )
V_88 = (struct V_87 * ) F_67 ( V_3 , 0 ) ;
F_68 () ;
if ( V_88 == NULL ) {
const struct V_107 * V_108 ;
V_108 = F_69 ( V_9 -> V_108 ) ;
if ( V_108 && V_108 -> V_109 . V_110 )
V_38 = V_108 -> V_109 . V_111 ;
V_88 = F_70 ( F_6 ( V_3 ) , V_90 , V_3 ,
V_38 , V_9 -> V_67 ,
V_9 -> V_80 , V_9 -> V_112 ,
V_3 -> V_113 , F_71 ( V_3 ) ,
V_3 -> V_13 ) ;
if ( F_72 ( V_88 ) )
goto V_114;
if ( V_91 ) {
F_73 ( V_3 , & V_88 -> V_115 ) ;
} else {
F_74 ( V_16 , & V_88 -> V_115 ) ;
goto V_116;
}
}
F_75 ( V_16 , & V_88 -> V_115 ) ;
V_116:
V_72 = F_76 ( V_3 , V_16 , & V_9 -> V_103 . V_104 ) ;
F_77 () ;
error:
if ( V_72 >= 0 )
V_72 = V_31 ;
V_58:
F_49 ( V_3 ) ;
return V_72 ;
V_114:
F_77 () ;
F_58 ( F_6 ( V_3 ) , V_117 ) ;
F_28 ( V_16 ) ;
V_72 = - V_118 ;
goto V_58;
}
static int F_78 ( struct V_2 * V_3 , struct V_85 * V_86 ,
T_3 V_31 , int V_119 , int V_75 , int * V_49 )
{
struct V_8 * V_9 = F_4 ( V_3 ) ;
T_3 V_120 = 0 ;
int V_121 = - V_122 ;
F_60 ( struct V_123 * , sin , V_86 -> V_93 ) ;
struct V_15 * V_16 ;
if ( V_75 & V_124 )
goto V_58;
V_16 = F_79 ( V_3 , V_75 , V_119 , & V_121 ) ;
if ( ! V_16 )
goto V_58;
V_120 = V_16 -> V_31 ;
if ( V_31 < V_120 ) {
V_86 -> V_125 |= V_126 ;
V_120 = V_31 ;
}
V_121 = F_80 ( V_16 , 0 , V_86 , V_120 ) ;
if ( V_121 )
goto V_127;
F_81 ( V_86 , V_3 , V_16 ) ;
if ( sin ) {
sin -> V_128 = V_56 ;
sin -> V_129 . V_62 = F_82 ( V_16 ) -> V_130 ;
sin -> V_131 = 0 ;
memset ( & sin -> V_132 , 0 , sizeof( sin -> V_132 ) ) ;
* V_49 = sizeof( * sin ) ;
}
if ( V_9 -> V_133 )
F_83 ( V_86 , V_16 ) ;
if ( V_75 & V_126 )
V_120 = V_16 -> V_31 ;
V_127:
F_84 ( V_3 , V_16 ) ;
V_58:
return V_121 ? V_121 : V_120 ;
}
static int T_4 F_85 ( void )
{
int V_121 ;
F_86 ( L_3 ) ;
V_121 = F_87 ( & V_134 , 1 ) ;
if ( V_121 != 0 )
goto V_58;
V_121 = F_88 ( & V_135 , V_42 ) ;
if ( V_121 )
goto V_136;
F_89 ( & V_137 ) ;
return 0 ;
V_136:
F_90 ( & V_134 ) ;
V_58:
return V_121 ;
}
static void T_5 F_91 ( void )
{
F_92 ( & V_137 ) ;
F_93 ( & V_135 , V_42 ) ;
F_90 ( & V_134 ) ;
}
