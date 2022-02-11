static T_1 F_1 ( T_1 V_1 , const T_2 * V_2 , T_3 V_3 )
{
return F_2 ( F_3 ( F_4 ( V_1 , V_2 , V_3 ) ) ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
T_2 * V_6 = & V_5 -> V_7 ;
T_3 V_3 = V_5 -> V_7 - V_8 ;
T_1 * F_4 = ( T_1 * ) ( V_6 + V_3 ) ;
* F_4 = F_1 ( 0 , V_6 , V_3 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
V_5 -> V_9 = V_10 ;
V_5 -> V_11 = V_12 ;
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = V_16 ;
V_5 -> V_7 = V_17 ;
F_5 ( V_5 ) ;
V_5 -> V_18 = V_19 ;
V_5 -> V_20 = V_21 ;
}
static void F_7 ( struct V_4 * V_5 , T_1 V_22 )
{
V_5 -> V_9 = V_10 ;
V_5 -> V_7 = V_23 ;
V_5 -> V_11 = V_24 ;
V_5 -> V_13 = V_25 ;
V_5 -> V_15 = F_2 ( V_22 ) ;
F_5 ( V_5 ) ;
V_5 -> V_18 = V_26 ;
V_5 -> V_20 = V_27 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_28 * V_29 )
{
T_3 V_30 ;
V_5 -> V_9 = V_10 ;
V_5 -> V_7 = V_31 ;
V_5 -> V_11 = V_32 ;
V_5 -> V_13 = V_33 ;
V_5 -> V_15 = F_2 ( V_34 ) ;
V_30 = F_9 ( V_29 , 1 , V_5 -> V_6 , V_35 ) ;
if ( V_30 != V_35 )
return - V_36 ;
F_5 ( V_5 ) ;
V_5 -> V_18 = V_37 ;
V_5 -> V_20 = V_38 ;
return 0 ;
}
static int F_10 ( struct V_39 * V_40 , T_2 * V_41 )
{
T_3 V_42 = F_11 ( V_43 ) ;
int V_44 ;
T_2 V_45 = V_41 [ 1 ] ;
if ( * V_41 != V_46 )
return 0 ;
if ( V_45 == V_47 || V_45 == V_48 )
return 0 ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ )
if ( V_43 [ V_44 ] . V_49 == V_45 )
break;
if ( V_44 != V_42 ) {
F_12 ( V_40 , L_1 , V_45 , V_43 [ V_44 ] . V_50 ) ;
return V_45 ;
}
return 0 ;
}
static int F_13 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_14 ( V_52 ) ;
T_2 V_41 [ V_55 ] ;
int V_56 ;
F_15 ( V_52 , V_54 -> V_57 , V_54 -> V_58 ) ;
F_16 ( V_59 , V_60 ) ;
V_56 = F_17 ( V_52 , V_41 , V_46 ) ;
if ( V_56 < 0 )
return V_56 ;
return F_10 ( & V_52 -> V_40 , V_41 ) ;
}
static int F_18 ( struct V_51 * V_52 )
{
T_2 V_61 = V_62 ;
return F_15 ( V_52 , & V_61 , 1 ) ;
}
static void F_19 ( struct V_63 * V_64 , void * V_65 ,
int V_41 )
{
struct V_66 * V_67 = V_65 ;
struct V_68 * V_69 = V_64 -> V_69 ;
struct V_4 * V_5 = & V_64 -> V_5 ;
T_3 V_30 ;
T_3 V_70 = V_69 -> V_70 ;
if ( V_41 )
goto V_71;
V_30 = F_20 ( V_67 -> V_72 , 1 , & V_5 -> V_6 [ V_73 ] ,
V_70 ) ;
if ( V_30 != V_70 )
V_41 = - V_36 ;
V_71:
F_21 ( V_64 ) ;
F_22 ( V_67 , V_41 ) ;
}
static int F_23 ( struct V_51 * V_52 ,
struct V_4 * V_5 )
{
struct V_53 * V_54 = F_14 ( V_52 ) ;
int V_56 ;
F_24 ( & V_54 -> V_74 ) ;
V_56 = F_13 ( V_52 ) ;
if ( V_56 )
goto V_75;
V_56 = F_15 ( V_52 , ( T_2 * ) V_5 , V_5 -> V_7 + V_76 ) ;
if ( V_56 < 0 )
goto V_75;
F_25 ( V_5 -> V_18 ) ;
V_56 = F_17 ( V_52 , V_5 -> V_6 , V_5 -> V_20 ) ;
if ( V_56 < 0 )
goto V_75;
V_56 = F_18 ( V_52 ) ;
if ( V_56 < 0 )
goto V_75;
F_26 ( & V_54 -> V_74 ) ;
return F_10 ( & V_52 -> V_40 , V_5 -> V_6 ) ;
V_75:
F_26 ( & V_54 -> V_74 ) ;
return V_56 ;
}
static void F_27 ( struct V_77 * V_78 )
{
struct V_63 * V_64 =
F_28 ( V_78 , struct V_63 , V_78 ) ;
struct V_4 * V_5 = & V_64 -> V_5 ;
struct V_51 * V_52 = V_64 -> V_69 -> V_52 ;
int V_41 ;
V_41 = F_23 ( V_52 , V_5 ) ;
V_64 -> V_79 ( V_64 , V_64 -> V_65 , V_41 ) ;
}
static void F_29 ( struct V_63 * V_64 ,
void (* V_79)( struct V_63 * V_64 ,
void * V_65 , int V_41 ) ,
void * V_65 )
{
V_64 -> V_79 = ( void * ) V_79 ;
V_64 -> V_65 = V_65 ;
F_30 ( & V_64 -> V_78 , F_27 ) ;
F_31 ( & V_64 -> V_78 ) ;
}
static unsigned int F_32 ( unsigned int V_80 )
{
if ( V_80 == V_81 )
return V_82 ;
return 0 ;
}
static int F_33 ( struct V_83 * V_84 , const void * V_85 ,
unsigned int V_3 )
{
struct V_68 * V_69 = F_34 ( V_84 ) ;
struct V_4 * V_5 ;
void * V_86 ;
struct V_87 V_88 ;
int V_56 = - V_89 ;
F_35 ( V_69 -> V_86 ) ;
V_69 -> V_86 = NULL ;
if ( F_36 ( V_85 , V_3 , & V_88 ) < 0 ) {
F_12 ( & V_69 -> V_52 -> V_40 , L_2 ) ;
return - V_36 ;
}
V_69 -> V_70 = F_32 ( V_88 . V_80 ) ;
if ( ! V_69 -> V_70 || V_88 . V_90 ) {
V_69 -> V_91 = true ;
return F_37 ( V_69 -> V_92 , V_85 , V_3 ) ;
}
V_5 = F_38 ( sizeof( * V_5 ) , V_93 ) ;
if ( ! V_5 )
return - V_89 ;
V_86 = F_38 ( V_35 , V_93 ) ;
if ( ! V_86 )
goto V_94;
V_69 -> V_91 = false ;
V_69 -> V_80 = V_88 . V_80 ;
F_7 ( V_5 , V_34 ) ;
V_56 = F_23 ( V_69 -> V_52 , V_5 ) ;
if ( V_56 )
goto V_95;
memcpy ( V_86 , & V_5 -> V_6 [ V_73 ] , V_35 ) ;
V_69 -> V_86 = V_86 ;
F_35 ( V_5 ) ;
return 0 ;
V_95:
F_35 ( V_86 ) ;
V_94:
F_35 ( V_5 ) ;
return V_56 ;
}
static int F_39 ( struct V_66 * V_67 )
{
struct V_83 * V_84 = F_40 ( V_67 ) ;
struct V_68 * V_69 = F_34 ( V_84 ) ;
T_3 V_30 ;
int V_56 = 0 ;
if ( V_69 -> V_91 ) {
F_41 ( V_67 , V_69 -> V_92 ) ;
return F_42 ( V_67 ) ;
}
V_30 = F_20 ( V_67 -> V_72 , 1 , V_69 -> V_86 ,
V_35 ) ;
if ( V_30 != V_35 )
V_56 = - V_36 ;
return V_56 ;
}
static int F_43 ( struct V_66 * V_67 )
{
struct V_83 * V_84 = F_40 ( V_67 ) ;
struct V_68 * V_69 = F_34 ( V_84 ) ;
struct V_63 * V_64 ;
T_4 V_96 ;
int V_56 ;
if ( V_69 -> V_91 ) {
F_41 ( V_67 , V_69 -> V_92 ) ;
return F_44 ( V_67 ) ;
}
V_96 = ( V_67 -> V_97 . V_98 & V_99 ) ? V_93 :
V_100 ;
V_64 = F_38 ( sizeof( * V_64 ) , V_96 ) ;
if ( ! V_64 )
return - V_89 ;
V_64 -> V_69 = V_69 ;
V_56 = F_8 ( & V_64 -> V_5 , V_67 -> V_101 ) ;
if ( V_56 )
goto V_71;
F_29 ( V_64 , F_19 , V_67 ) ;
return - V_102 ;
V_71:
F_35 ( V_64 ) ;
return V_56 ;
}
static struct V_51 * F_45 ( void )
{
struct V_53 * V_54 , * V_103 = NULL ;
struct V_51 * V_52 = F_46 ( - V_104 ) ;
int V_105 = V_106 ;
int V_107 ;
F_47 ( & V_108 . V_109 ) ;
if ( F_48 ( & V_108 . V_110 ) ) {
F_49 ( & V_108 . V_109 ) ;
return F_46 ( - V_104 ) ;
}
F_50 (i2c_priv, &driver_data.i2c_client_list,
i2c_client_list_node) {
V_107 = F_51 ( & V_54 -> V_111 ) ;
if ( V_107 < V_105 ) {
V_105 = V_107 ;
V_103 = V_54 ;
}
if ( ! V_105 )
break;
}
if ( V_103 ) {
F_52 ( & V_103 -> V_111 ) ;
V_52 = V_103 -> V_52 ;
}
F_49 ( & V_108 . V_109 ) ;
return V_52 ;
}
static void F_53 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_14 ( V_52 ) ;
F_54 ( & V_54 -> V_111 ) ;
}
static int F_55 ( struct V_83 * V_84 )
{
const char * V_112 = F_56 ( V_84 ) ;
struct V_83 * V_92 ;
struct V_68 * V_69 = F_34 ( V_84 ) ;
V_69 -> V_52 = F_45 () ;
if ( F_57 ( V_69 -> V_52 ) ) {
F_58 ( L_3 ) ;
return F_59 ( V_69 -> V_52 ) ;
}
V_92 = F_60 ( V_112 , 0 , V_113 ) ;
if ( F_57 ( V_92 ) ) {
F_12 ( & V_69 -> V_52 -> V_40 , L_4 ,
V_112 , F_59 ( V_92 ) ) ;
return F_59 ( V_92 ) ;
}
F_61 ( V_92 , F_62 ( V_84 ) ) ;
F_63 ( & V_69 -> V_52 -> V_40 , L_5 ,
F_64 ( F_65 ( V_92 ) ) ) ;
V_69 -> V_92 = V_92 ;
return 0 ;
}
static void F_66 ( struct V_83 * V_84 )
{
struct V_68 * V_69 = F_34 ( V_84 ) ;
F_35 ( V_69 -> V_86 ) ;
F_67 ( V_69 -> V_92 ) ;
F_53 ( V_69 -> V_52 ) ;
}
static unsigned int F_68 ( struct V_83 * V_84 )
{
struct V_68 * V_69 = F_34 ( V_84 ) ;
if ( V_69 -> V_92 )
return F_69 ( V_69 -> V_92 ) ;
return V_35 ;
}
static inline T_3 F_70 ( T_5 V_114 )
{
T_5 V_115 = F_71 ( V_116 * V_114 , V_117 ) ;
return F_71 ( V_115 , 8 ) ;
}
static int F_72 ( struct V_51 * V_52 )
{
struct V_4 * V_5 ;
int V_56 ;
V_5 = F_38 ( sizeof( * V_5 ) , V_93 ) ;
if ( ! V_5 )
return - V_89 ;
F_6 ( V_5 ) ;
V_56 = F_23 ( V_52 , V_5 ) ;
if ( V_56 )
goto V_94;
if ( V_5 -> V_6 [ V_118 ] || V_5 -> V_6 [ V_119 ] ) {
F_12 ( & V_52 -> V_40 , L_6 ) ;
V_56 = - V_120 ;
}
V_94:
F_35 ( V_5 ) ;
return V_56 ;
}
static int F_73 ( struct V_51 * V_52 ,
const struct V_121 * V_122 )
{
struct V_53 * V_54 ;
struct V_39 * V_40 = & V_52 -> V_40 ;
int V_56 ;
T_5 V_114 ;
if ( ! F_74 ( V_52 -> V_123 , V_124 ) ) {
F_12 ( V_40 , L_7 ) ;
return - V_104 ;
}
V_56 = F_75 ( V_52 -> V_123 -> V_40 . V_125 ,
L_8 , & V_114 ) ;
if ( V_56 ) {
F_12 ( V_40 , L_9 ) ;
return V_56 ;
}
if ( V_114 > 1000000L ) {
F_12 ( V_40 , L_10 ,
V_114 ) ;
return - V_36 ;
}
V_54 = F_76 ( V_40 , sizeof( * V_54 ) , V_93 ) ;
if ( ! V_54 )
return - V_89 ;
V_54 -> V_52 = V_52 ;
F_77 ( & V_54 -> V_74 ) ;
V_54 -> V_58 = F_70 ( V_114 ) ;
memset ( V_54 -> V_57 , 0 , sizeof( V_54 -> V_57 ) ) ;
F_78 ( & V_54 -> V_111 , 0 ) ;
F_79 ( V_52 , V_54 ) ;
V_56 = F_72 ( V_52 ) ;
if ( V_56 )
return V_56 ;
F_47 ( & V_108 . V_109 ) ;
F_80 ( & V_54 -> V_126 ,
& V_108 . V_110 ) ;
F_49 ( & V_108 . V_109 ) ;
V_56 = F_81 ( & V_127 ) ;
if ( V_56 ) {
F_47 ( & V_108 . V_109 ) ;
F_82 ( & V_54 -> V_126 ) ;
F_49 ( & V_108 . V_109 ) ;
F_12 ( V_40 , L_11 ,
V_127 . V_97 . V_128 ) ;
} else {
F_63 ( V_40 , L_12 ) ;
}
return V_56 ;
}
static int F_83 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_14 ( V_52 ) ;
if ( F_51 ( & V_54 -> V_111 ) ) {
F_12 ( & V_52 -> V_40 , L_13 ) ;
return - V_129 ;
}
F_84 ( & V_127 ) ;
F_47 ( & V_108 . V_109 ) ;
F_82 ( & V_54 -> V_126 ) ;
F_49 ( & V_108 . V_109 ) ;
return 0 ;
}
static int T_6 F_85 ( void )
{
F_86 ( & V_108 . V_109 ) ;
F_87 ( & V_108 . V_110 ) ;
return F_88 ( & V_130 ) ;
}
static void T_7 F_89 ( void )
{
F_90 () ;
F_91 ( & V_130 ) ;
}
