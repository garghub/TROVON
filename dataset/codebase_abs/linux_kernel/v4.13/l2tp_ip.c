static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static struct V_2 * F_2 ( const struct V_4 * V_4 , T_1 V_5 ,
T_1 V_6 , int V_7 , T_2 V_8 )
{
struct V_2 * V_3 ;
F_3 (sk, &l2tp_ip_bind_table) {
const struct V_1 * V_9 = F_1 ( V_3 ) ;
const struct V_10 * V_11 = F_4 ( V_3 ) ;
if ( ! F_5 ( F_6 ( V_3 ) , V_4 ) )
continue;
if ( V_3 -> V_12 && V_7 && V_3 -> V_12 != V_7 )
continue;
if ( V_11 -> V_13 && V_5 &&
V_11 -> V_13 != V_5 )
continue;
if ( V_11 -> V_14 && V_6 && V_11 -> V_14 != V_6 )
continue;
if ( V_9 -> V_15 != V_8 )
continue;
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
V_24 = F_12 ( V_4 , NULL , V_20 , true ) ;
if ( ! V_24 )
goto V_28;
V_26 = V_24 -> V_26 ;
if ( ! V_26 )
goto V_31;
if ( V_26 -> V_32 & V_33 ) {
V_27 = F_13 ( 32u , V_18 -> V_34 ) ;
if ( ! F_9 ( V_18 , V_27 ) )
goto V_31;
V_22 = V_21 = V_18 -> V_29 ;
V_21 += 4 ;
F_14 ( L_1 , V_26 -> V_35 ) ;
F_15 ( L_2 , V_36 , V_21 , V_27 ) ;
}
F_16 ( V_24 , V_18 , V_21 , V_22 , 0 , V_18 -> V_34 , V_26 -> V_37 ) ;
F_17 ( V_24 ) ;
return 0 ;
V_30:
if ( ! F_9 ( V_18 , 12 ) )
goto V_28;
if ( ( V_18 -> V_29 [ 0 ] & 0xc0 ) != 0xc0 )
goto V_28;
V_8 = F_10 ( * ( T_1 * ) & V_18 -> V_29 [ 4 ] ) ;
V_26 = F_18 ( V_4 , V_8 ) ;
if ( V_26 ) {
V_3 = V_26 -> V_2 ;
F_19 ( V_3 ) ;
} else {
struct V_38 * V_39 = (struct V_38 * ) F_20 ( V_18 ) ;
F_21 ( & V_40 ) ;
V_3 = F_2 ( V_4 , V_39 -> V_41 , V_39 -> V_42 ,
F_22 ( V_18 ) , V_8 ) ;
if ( ! V_3 ) {
F_23 ( & V_40 ) ;
goto V_28;
}
F_19 ( V_3 ) ;
F_23 ( & V_40 ) ;
}
if ( ! F_24 ( V_3 , V_43 , V_18 ) )
goto V_44;
F_25 ( V_18 ) ;
return F_26 ( V_3 , V_18 , 1 ) ;
V_31:
if ( V_24 -> V_45 )
V_24 -> V_45 ( V_24 ) ;
F_17 ( V_24 ) ;
goto V_28;
V_44:
F_27 ( V_3 ) ;
V_28:
F_28 ( V_18 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) -> V_46 = V_47 ;
F_30 ( & V_40 ) ;
F_31 ( V_3 , & V_48 ) ;
F_32 ( & V_40 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 , long V_49 )
{
F_30 ( & V_40 ) ;
F_34 ( & V_3 -> V_50 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_40 ) ;
F_36 ( V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_25 * V_26 = F_38 ( V_3 ) ;
while ( ( V_18 = F_39 ( & V_3 -> V_51 ) ) != NULL )
F_28 ( V_18 ) ;
if ( V_26 ) {
F_40 ( V_26 ) ;
F_27 ( V_3 ) ;
}
F_41 ( V_3 ) ;
}
static int F_42 ( struct V_2 * V_3 , struct V_52 * V_53 , int V_54 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_55 * V_56 = (struct V_55 * ) V_53 ;
struct V_4 * V_4 = F_6 ( V_3 ) ;
int V_57 ;
int V_58 ;
if ( V_54 < sizeof( struct V_55 ) )
return - V_59 ;
if ( V_56 -> V_60 != V_61 )
return - V_59 ;
F_43 ( V_3 ) ;
V_57 = - V_59 ;
if ( ! F_44 ( V_3 , V_62 ) )
goto V_63;
if ( V_3 -> V_64 != V_65 )
goto V_63;
V_58 = F_45 ( V_4 , V_56 -> V_66 . V_67 ) ;
V_57 = - V_68 ;
if ( V_56 -> V_66 . V_67 && V_58 != V_69 &&
V_58 != V_70 && V_58 != V_71 )
goto V_63;
if ( V_56 -> V_66 . V_67 )
V_11 -> V_13 = V_11 -> V_72 = V_56 -> V_66 . V_67 ;
if ( V_58 == V_70 || V_58 == V_71 )
V_11 -> V_72 = 0 ;
F_30 ( & V_40 ) ;
if ( F_2 ( V_4 , V_56 -> V_66 . V_67 , 0 ,
V_3 -> V_12 , V_56 -> V_73 ) ) {
F_32 ( & V_40 ) ;
V_57 = - V_74 ;
goto V_63;
}
F_46 ( V_3 ) ;
F_1 ( V_3 ) -> V_15 = V_56 -> V_73 ;
F_47 ( V_3 , & V_75 ) ;
F_35 ( V_3 ) ;
F_32 ( & V_40 ) ;
V_57 = 0 ;
F_48 ( V_3 , V_62 ) ;
V_63:
F_49 ( V_3 ) ;
return V_57 ;
}
static int F_50 ( struct V_2 * V_3 , struct V_52 * V_53 , int V_54 )
{
struct V_55 * V_76 = (struct V_55 * ) V_53 ;
int V_77 ;
if ( V_54 < sizeof( * V_76 ) )
return - V_59 ;
if ( F_51 ( V_76 -> V_66 . V_67 ) )
return - V_59 ;
F_43 ( V_3 ) ;
if ( F_44 ( V_3 , V_62 ) ) {
V_77 = - V_59 ;
goto V_78;
}
V_77 = F_52 ( V_3 , V_53 , V_54 ) ;
if ( V_77 < 0 )
goto V_78;
F_1 ( V_3 ) -> V_79 = V_76 -> V_73 ;
F_30 ( & V_40 ) ;
F_34 ( & V_3 -> V_50 ) ;
F_47 ( V_3 , & V_75 ) ;
F_32 ( & V_40 ) ;
V_78:
F_49 ( V_3 ) ;
return V_77 ;
}
static int F_53 ( struct V_2 * V_3 , int V_80 )
{
if ( F_44 ( V_3 , V_62 ) )
return 0 ;
return F_54 ( V_3 , V_80 ) ;
}
static int F_55 ( struct V_81 * V_2 , struct V_52 * V_53 ,
int * V_82 , int V_83 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_84 = F_1 ( V_3 ) ;
struct V_55 * V_76 = (struct V_55 * ) V_53 ;
memset ( V_76 , 0 , sizeof( * V_76 ) ) ;
V_76 -> V_60 = V_61 ;
if ( V_83 ) {
if ( ! V_11 -> V_85 )
return - V_86 ;
V_76 -> V_73 = V_84 -> V_79 ;
V_76 -> V_66 . V_67 = V_11 -> V_14 ;
} else {
T_1 V_56 = V_11 -> V_13 ;
if ( ! V_56 )
V_56 = V_11 -> V_72 ;
V_76 -> V_73 = V_84 -> V_15 ;
V_76 -> V_66 . V_67 = V_56 ;
}
* V_82 = sizeof( * V_76 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
int V_77 ;
V_77 = F_57 ( V_3 , V_18 ) ;
if ( V_77 < 0 )
goto V_87;
return 0 ;
V_87:
F_58 ( F_6 ( V_3 ) , V_88 ) ;
F_28 ( V_18 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 , struct V_89 * V_90 , T_3 V_34 )
{
struct V_17 * V_18 ;
int V_77 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
struct V_91 * V_92 = NULL ;
struct V_93 * V_94 ;
int V_95 = 0 ;
T_1 V_41 ;
F_43 ( V_3 ) ;
V_77 = - V_86 ;
if ( F_44 ( V_3 , V_96 ) )
goto V_63;
if ( V_90 -> V_97 ) {
F_60 ( struct V_55 * , V_98 , V_90 -> V_97 ) ;
V_77 = - V_59 ;
if ( V_90 -> V_99 < sizeof( * V_98 ) )
goto V_63;
if ( V_98 -> V_60 != V_61 ) {
V_77 = - V_100 ;
if ( V_98 -> V_60 != V_101 )
goto V_63;
}
V_41 = V_98 -> V_66 . V_67 ;
} else {
V_77 = - V_102 ;
if ( V_3 -> V_64 != V_103 )
goto V_63;
V_41 = V_11 -> V_14 ;
V_95 = 1 ;
}
V_77 = - V_104 ;
V_18 = F_61 ( V_3 , 2 + V_105 + sizeof( struct V_38 ) +
4 + V_34 , 0 , V_106 ) ;
if ( ! V_18 )
goto error;
F_62 ( V_18 , 2 + V_105 ) ;
F_63 ( V_18 ) ;
F_62 ( V_18 , sizeof( struct V_38 ) ) ;
F_64 ( V_18 ) ;
* ( ( T_1 * ) F_65 ( V_18 , 4 ) ) = 0 ;
V_77 = F_66 ( F_65 ( V_18 , V_34 ) , V_90 , V_34 ) ;
if ( V_77 < 0 ) {
F_28 ( V_18 ) ;
goto error;
}
V_94 = & V_11 -> V_107 . V_108 . V_109 . V_110 ;
if ( V_95 )
V_92 = (struct V_91 * ) F_67 ( V_3 , 0 ) ;
F_68 () ;
if ( V_92 == NULL ) {
const struct V_111 * V_112 ;
V_112 = F_69 ( V_11 -> V_112 ) ;
if ( V_112 && V_112 -> V_113 . V_114 )
V_41 = V_112 -> V_113 . V_115 ;
V_92 = F_70 ( F_6 ( V_3 ) , V_94 , V_3 ,
V_41 , V_11 -> V_72 ,
V_11 -> V_85 , V_11 -> V_116 ,
V_3 -> V_117 , F_71 ( V_3 ) ,
V_3 -> V_12 ) ;
if ( F_72 ( V_92 ) )
goto V_118;
if ( V_95 ) {
F_73 ( V_3 , & V_92 -> V_119 ) ;
} else {
F_74 ( V_18 , & V_92 -> V_119 ) ;
goto V_120;
}
}
F_75 ( V_18 , & V_92 -> V_119 ) ;
V_120:
V_77 = F_76 ( V_3 , V_18 , & V_11 -> V_107 . V_108 ) ;
F_77 () ;
error:
if ( V_77 >= 0 )
V_77 = V_34 ;
V_63:
F_49 ( V_3 ) ;
return V_77 ;
V_118:
F_77 () ;
F_58 ( F_6 ( V_3 ) , V_121 ) ;
F_28 ( V_18 ) ;
V_77 = - V_122 ;
goto V_63;
}
static int F_78 ( struct V_2 * V_3 , struct V_89 * V_90 ,
T_3 V_34 , int V_123 , int V_80 , int * V_54 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
T_3 V_124 = 0 ;
int V_125 = - V_126 ;
F_60 ( struct V_127 * , sin , V_90 -> V_97 ) ;
struct V_17 * V_18 ;
if ( V_80 & V_128 )
goto V_63;
V_18 = F_79 ( V_3 , V_80 , V_123 , & V_125 ) ;
if ( ! V_18 )
goto V_63;
V_124 = V_18 -> V_34 ;
if ( V_34 < V_124 ) {
V_90 -> V_129 |= V_130 ;
V_124 = V_34 ;
}
V_125 = F_80 ( V_18 , 0 , V_90 , V_124 ) ;
if ( V_125 )
goto V_131;
F_81 ( V_90 , V_3 , V_18 ) ;
if ( sin ) {
sin -> V_132 = V_61 ;
sin -> V_133 . V_67 = F_82 ( V_18 ) -> V_42 ;
sin -> V_134 = 0 ;
memset ( & sin -> V_135 , 0 , sizeof( sin -> V_135 ) ) ;
* V_54 = sizeof( * sin ) ;
}
if ( V_11 -> V_136 )
F_83 ( V_90 , V_18 ) ;
if ( V_80 & V_130 )
V_124 = V_18 -> V_34 ;
V_131:
F_84 ( V_3 , V_18 ) ;
V_63:
return V_125 ? V_125 : V_124 ;
}
int F_85 ( struct V_2 * V_3 , int V_137 , unsigned long V_138 )
{
struct V_17 * V_18 ;
int V_139 ;
switch ( V_137 ) {
case V_140 :
V_139 = F_86 ( V_3 ) ;
break;
case V_141 :
F_87 ( & V_3 -> V_142 . V_143 ) ;
V_18 = F_88 ( & V_3 -> V_142 ) ;
V_139 = V_18 ? V_18 -> V_34 : 0 ;
F_89 ( & V_3 -> V_142 . V_143 ) ;
break;
default:
return - V_144 ;
}
return F_90 ( V_139 , ( int V_145 * ) V_138 ) ;
}
static int T_4 F_91 ( void )
{
int V_125 ;
F_92 ( L_3 ) ;
V_125 = F_93 ( & V_146 , 1 ) ;
if ( V_125 != 0 )
goto V_63;
V_125 = F_94 ( & V_147 , V_47 ) ;
if ( V_125 )
goto V_148;
F_95 ( & V_149 ) ;
return 0 ;
V_148:
F_96 ( & V_146 ) ;
V_63:
return V_125 ;
}
static void T_5 F_97 ( void )
{
F_98 ( & V_149 ) ;
F_99 ( & V_147 , V_47 ) ;
F_96 ( & V_146 ) ;
}
