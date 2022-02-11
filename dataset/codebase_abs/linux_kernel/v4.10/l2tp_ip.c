static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( const struct V_4 * V_4 , T_1 V_5 ,
T_1 V_6 , int V_7 , T_2 V_8 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip_bind_table) {
struct V_9 * V_10 = F_4 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 == NULL )
continue;
if ( ( V_11 -> V_12 == V_8 ) &&
F_5 ( F_6 ( V_3 ) , V_4 ) &&
! ( V_10 -> V_13 && V_10 -> V_13 != V_5 ) &&
( ! V_10 -> V_14 || ! V_6 || V_10 -> V_14 == V_6 ) &&
( ! V_3 -> V_15 || ! V_7 ||
V_3 -> V_15 == V_7 ) )
goto V_16;
}
V_3 = NULL ;
V_16:
return V_3 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_4 * V_4 = F_8 ( V_18 -> V_19 ) ;
struct V_2 * V_3 ;
T_2 V_20 ;
T_2 V_8 ;
unsigned char * V_21 , * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = NULL ;
int V_27 ;
if ( ! F_9 ( V_18 , 4 ) )
goto V_28;
V_22 = V_21 = V_18 -> V_29 ;
V_20 = F_10 ( * ( ( T_1 * ) V_21 ) ) ;
V_21 += 4 ;
if ( V_20 == 0 ) {
F_11 ( V_18 , 4 ) ;
goto V_30;
}
V_24 = F_12 ( V_4 , NULL , V_20 ) ;
if ( V_24 == NULL )
goto V_28;
V_26 = V_24 -> V_26 ;
if ( V_26 == NULL )
goto V_28;
if ( V_26 -> V_31 & V_32 ) {
V_27 = F_13 ( 32u , V_18 -> V_33 ) ;
if ( ! F_9 ( V_18 , V_27 ) )
goto V_28;
V_22 = V_21 = V_18 -> V_29 ;
V_21 += 4 ;
F_14 ( L_1 , V_26 -> V_34 ) ;
F_15 ( L_2 , V_35 , V_21 , V_27 ) ;
}
F_16 ( V_24 , V_18 , V_21 , V_22 , 0 , V_18 -> V_33 , V_26 -> V_36 ) ;
return 0 ;
V_30:
if ( ! F_9 ( V_18 , 12 ) )
goto V_28;
if ( ( V_18 -> V_29 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_28;
V_8 = F_10 ( * ( T_1 * ) & V_18 -> V_29 [ 4 ] ) ;
V_26 = F_17 ( V_4 , V_8 ) ;
if ( V_26 != NULL )
V_3 = V_26 -> V_2 ;
else {
struct V_37 * V_38 = (struct V_37 * ) F_18 ( V_18 ) ;
F_19 ( & V_39 ) ;
V_3 = F_2 ( V_4 , V_38 -> V_40 , V_38 -> V_41 ,
F_20 ( V_18 ) , V_8 ) ;
if ( ! V_3 ) {
F_21 ( & V_39 ) ;
goto V_28;
}
F_22 ( V_3 ) ;
F_21 ( & V_39 ) ;
}
if ( ! F_23 ( V_3 , V_42 , V_18 ) )
goto V_43;
F_24 ( V_18 ) ;
return F_25 ( V_3 , V_18 , 1 ) ;
V_43:
F_26 ( V_3 ) ;
V_28:
F_27 ( V_18 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_44 = V_45 ;
F_29 ( & V_39 ) ;
F_30 ( V_3 , & V_46 ) ;
F_31 ( & V_39 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 , long V_47 )
{
F_29 ( & V_39 ) ;
F_33 ( & V_3 -> V_48 ) ;
F_34 ( V_3 ) ;
F_31 ( & V_39 ) ;
F_35 ( V_3 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_25 * V_26 = F_37 ( V_3 ) ;
while ( ( V_18 = F_38 ( & V_3 -> V_49 ) ) != NULL )
F_27 ( V_18 ) ;
if ( V_26 ) {
F_39 ( V_26 ) ;
F_26 ( V_3 ) ;
}
F_40 ( V_3 ) ;
}
static int F_41 ( struct V_2 * V_3 , struct V_50 * V_51 , int V_52 )
{
struct V_9 * V_10 = F_4 ( V_3 ) ;
struct V_53 * V_54 = (struct V_53 * ) V_51 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
int V_55 ;
int V_56 ;
if ( V_52 < sizeof( struct V_53 ) )
return - V_57 ;
if ( V_54 -> V_58 != V_59 )
return - V_57 ;
F_42 ( V_3 ) ;
V_55 = - V_57 ;
if ( ! F_43 ( V_3 , V_60 ) )
goto V_61;
if ( V_3 -> V_62 != V_63 || V_52 < sizeof( struct V_53 ) )
goto V_61;
V_56 = F_44 ( V_4 , V_54 -> V_64 . V_65 ) ;
V_55 = - V_66 ;
if ( V_54 -> V_64 . V_65 && V_56 != V_67 &&
V_56 != V_68 && V_56 != V_69 )
goto V_61;
if ( V_54 -> V_64 . V_65 )
V_10 -> V_13 = V_10 -> V_70 = V_54 -> V_64 . V_65 ;
if ( V_56 == V_68 || V_56 == V_69 )
V_10 -> V_70 = 0 ;
F_29 ( & V_39 ) ;
if ( F_2 ( V_4 , V_54 -> V_64 . V_65 , 0 ,
V_3 -> V_15 , V_54 -> V_71 ) ) {
F_31 ( & V_39 ) ;
V_55 = - V_72 ;
goto V_61;
}
F_45 ( V_3 ) ;
F_1 ( V_3 ) -> V_12 = V_54 -> V_71 ;
F_46 ( V_3 , & V_73 ) ;
F_34 ( V_3 ) ;
F_31 ( & V_39 ) ;
V_55 = 0 ;
F_47 ( V_3 , V_60 ) ;
V_61:
F_48 ( V_3 ) ;
return V_55 ;
}
static int F_49 ( struct V_2 * V_3 , struct V_50 * V_51 , int V_52 )
{
struct V_53 * V_74 = (struct V_53 * ) V_51 ;
int V_75 ;
if ( V_52 < sizeof( * V_74 ) )
return - V_57 ;
if ( F_50 ( V_74 -> V_64 . V_65 ) )
return - V_57 ;
F_42 ( V_3 ) ;
if ( F_43 ( V_3 , V_60 ) ) {
V_75 = - V_57 ;
goto V_76;
}
V_75 = F_51 ( V_3 , V_51 , V_52 ) ;
if ( V_75 < 0 )
goto V_76;
F_1 ( V_3 ) -> V_77 = V_74 -> V_71 ;
F_29 ( & V_39 ) ;
F_33 ( & V_3 -> V_48 ) ;
F_46 ( V_3 , & V_73 ) ;
F_31 ( & V_39 ) ;
V_76:
F_48 ( V_3 ) ;
return V_75 ;
}
static int F_52 ( struct V_2 * V_3 , int V_78 )
{
if ( F_43 ( V_3 , V_60 ) )
return 0 ;
return F_53 ( V_3 , V_78 ) ;
}
static int F_54 ( struct V_79 * V_2 , struct V_50 * V_51 ,
int * V_80 , int V_81 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_9 * V_10 = F_4 ( V_3 ) ;
struct V_1 * V_82 = F_1 ( V_3 ) ;
struct V_53 * V_74 = (struct V_53 * ) V_51 ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_58 = V_59 ;
if ( V_81 ) {
if ( ! V_10 -> V_83 )
return - V_84 ;
V_74 -> V_71 = V_82 -> V_77 ;
V_74 -> V_64 . V_65 = V_10 -> V_14 ;
} else {
T_1 V_54 = V_10 -> V_13 ;
if ( ! V_54 )
V_54 = V_10 -> V_70 ;
V_74 -> V_71 = V_82 -> V_12 ;
V_74 -> V_64 . V_65 = V_54 ;
}
* V_80 = sizeof( * V_74 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_75 ;
V_75 = F_56 ( V_3 , V_18 ) ;
if ( V_75 < 0 )
goto V_85;
return 0 ;
V_85:
F_57 ( F_6 ( V_3 ) , V_86 ) ;
F_27 ( V_18 ) ;
return - 1 ;
}
static int F_58 ( struct V_2 * V_3 , struct V_87 * V_88 , T_3 V_33 )
{
struct V_17 * V_18 ;
int V_75 ;
struct V_9 * V_10 = F_4 ( V_3 ) ;
struct V_89 * V_90 = NULL ;
struct V_91 * V_92 ;
int V_93 = 0 ;
T_1 V_40 ;
F_42 ( V_3 ) ;
V_75 = - V_84 ;
if ( F_43 ( V_3 , V_94 ) )
goto V_61;
if ( V_88 -> V_95 ) {
F_59 ( struct V_53 * , V_96 , V_88 -> V_95 ) ;
V_75 = - V_57 ;
if ( V_88 -> V_97 < sizeof( * V_96 ) )
goto V_61;
if ( V_96 -> V_58 != V_59 ) {
V_75 = - V_98 ;
if ( V_96 -> V_58 != V_99 )
goto V_61;
}
V_40 = V_96 -> V_64 . V_65 ;
} else {
V_75 = - V_100 ;
if ( V_3 -> V_62 != V_101 )
goto V_61;
V_40 = V_10 -> V_14 ;
V_93 = 1 ;
}
V_75 = - V_102 ;
V_18 = F_60 ( V_3 , 2 + V_103 + sizeof( struct V_37 ) +
4 + V_33 , 0 , V_104 ) ;
if ( ! V_18 )
goto error;
F_61 ( V_18 , 2 + V_103 ) ;
F_62 ( V_18 ) ;
F_61 ( V_18 , sizeof( struct V_37 ) ) ;
F_63 ( V_18 ) ;
* ( ( T_1 * ) F_64 ( V_18 , 4 ) ) = 0 ;
V_75 = F_65 ( F_64 ( V_18 , V_33 ) , V_88 , V_33 ) ;
if ( V_75 < 0 ) {
F_27 ( V_18 ) ;
goto error;
}
V_92 = & V_10 -> V_105 . V_106 . V_107 . V_108 ;
if ( V_93 )
V_90 = (struct V_89 * ) F_66 ( V_3 , 0 ) ;
F_67 () ;
if ( V_90 == NULL ) {
const struct V_109 * V_110 ;
V_110 = F_68 ( V_10 -> V_110 ) ;
if ( V_110 && V_110 -> V_111 . V_112 )
V_40 = V_110 -> V_111 . V_113 ;
V_90 = F_69 ( F_6 ( V_3 ) , V_92 , V_3 ,
V_40 , V_10 -> V_70 ,
V_10 -> V_83 , V_10 -> V_114 ,
V_3 -> V_115 , F_70 ( V_3 ) ,
V_3 -> V_15 ) ;
if ( F_71 ( V_90 ) )
goto V_116;
if ( V_93 ) {
F_72 ( V_3 , & V_90 -> V_117 ) ;
} else {
F_73 ( V_18 , & V_90 -> V_117 ) ;
goto V_118;
}
}
F_74 ( V_18 , & V_90 -> V_117 ) ;
V_118:
V_75 = F_75 ( V_3 , V_18 , & V_10 -> V_105 . V_106 ) ;
F_76 () ;
error:
if ( V_75 >= 0 )
V_75 = V_33 ;
V_61:
F_48 ( V_3 ) ;
return V_75 ;
V_116:
F_76 () ;
F_57 ( F_6 ( V_3 ) , V_119 ) ;
F_27 ( V_18 ) ;
V_75 = - V_120 ;
goto V_61;
}
static int F_77 ( struct V_2 * V_3 , struct V_87 * V_88 ,
T_3 V_33 , int V_121 , int V_78 , int * V_52 )
{
struct V_9 * V_10 = F_4 ( V_3 ) ;
T_3 V_122 = 0 ;
int V_123 = - V_124 ;
F_59 ( struct V_125 * , sin , V_88 -> V_95 ) ;
struct V_17 * V_18 ;
if ( V_78 & V_126 )
goto V_61;
V_18 = F_78 ( V_3 , V_78 , V_121 , & V_123 ) ;
if ( ! V_18 )
goto V_61;
V_122 = V_18 -> V_33 ;
if ( V_33 < V_122 ) {
V_88 -> V_127 |= V_128 ;
V_122 = V_33 ;
}
V_123 = F_79 ( V_18 , 0 , V_88 , V_122 ) ;
if ( V_123 )
goto V_129;
F_80 ( V_88 , V_3 , V_18 ) ;
if ( sin ) {
sin -> V_130 = V_59 ;
sin -> V_131 . V_65 = F_81 ( V_18 ) -> V_41 ;
sin -> V_132 = 0 ;
memset ( & sin -> V_133 , 0 , sizeof( sin -> V_133 ) ) ;
* V_52 = sizeof( * sin ) ;
}
if ( V_10 -> V_134 )
F_82 ( V_88 , V_18 ) ;
if ( V_78 & V_128 )
V_122 = V_18 -> V_33 ;
V_129:
F_83 ( V_3 , V_18 ) ;
V_61:
return V_123 ? V_123 : V_122 ;
}
int F_84 ( struct V_2 * V_3 , int V_135 , unsigned long V_136 )
{
struct V_17 * V_18 ;
int V_137 ;
switch ( V_135 ) {
case V_138 :
V_137 = F_85 ( V_3 ) ;
break;
case V_139 :
F_86 ( & V_3 -> V_140 . V_141 ) ;
V_18 = F_87 ( & V_3 -> V_140 ) ;
V_137 = V_18 ? V_18 -> V_33 : 0 ;
F_88 ( & V_3 -> V_140 . V_141 ) ;
break;
default:
return - V_142 ;
}
return F_89 ( V_137 , ( int V_143 * ) V_136 ) ;
}
static int T_4 F_90 ( void )
{
int V_123 ;
F_91 ( L_3 ) ;
V_123 = F_92 ( & V_144 , 1 ) ;
if ( V_123 != 0 )
goto V_61;
V_123 = F_93 ( & V_145 , V_45 ) ;
if ( V_123 )
goto V_146;
F_94 ( & V_147 ) ;
return 0 ;
V_146:
F_95 ( & V_144 ) ;
V_61:
return V_123 ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_147 ) ;
F_98 ( & V_145 , V_45 ) ;
F_95 ( & V_144 ) ;
}
