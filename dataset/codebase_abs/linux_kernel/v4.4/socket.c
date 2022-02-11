static struct V_1 *
F_1 ( struct V_2 * V_2 , const struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
struct V_1 * V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 [ V_10 ] ;
switch ( V_4 -> V_11 ) {
case V_12 :
F_2 ( V_9 , V_4 -> V_13 ) ;
F_3 () ;
V_5 = F_4 ( V_2 , V_14 , V_9 ) ;
if ( V_5 )
F_5 ( V_5 ) ;
F_6 () ;
break;
case V_15 :
if ( V_4 -> V_7 == F_7 ( V_16 ) ||
V_4 -> V_8 == F_7 ( V_17 ) ||
V_4 -> V_8 == F_7 ( V_18 ) )
break;
F_8 () ;
F_9 (net, tmp) {
if ( V_6 -> type != V_14 )
continue;
V_7 = V_6 -> V_19 -> V_7 ;
V_8 = V_6 -> V_19 -> V_8 ;
if ( V_7 == V_4 -> V_7 &&
V_8 == V_4 -> V_8 ) {
V_5 = V_6 ;
F_5 ( V_5 ) ;
break;
}
}
F_10 () ;
break;
default:
F_11 ( L_1 ,
V_4 -> V_11 ) ;
break;
}
return V_5 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
if ( V_22 ) {
V_21 -> V_22 = NULL ;
V_22 -> V_23 -> V_24 ( V_22 , 0 ) ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 , struct V_25 * V_26 ,
T_3 V_27 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
return V_22 -> V_23 -> V_28 ( V_22 , V_26 , V_27 ) ;
}
static int F_14 ( struct V_20 * V_21 , struct V_29 * V_30 ,
int V_31 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
if ( V_22 -> V_23 -> V_32 )
return V_22 -> V_23 -> V_32 ( V_22 , V_30 , V_31 ) ;
return F_15 ( V_21 , V_30 , V_31 ) ;
}
static int F_16 ( struct V_20 * V_21 , struct V_29 * V_30 ,
int V_31 , int V_33 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
if ( V_31 < sizeof( V_30 -> V_34 ) )
return - V_35 ;
if ( V_30 -> V_34 == V_36 )
return V_22 -> V_23 -> V_37 ( V_22 , V_33 ) ;
return V_22 -> V_23 -> V_38 ( V_22 , V_30 , V_31 ) ;
}
static int F_17 ( struct V_21 * V_22 , struct V_39 T_4 * V_40 ,
unsigned int V_41 )
{
struct V_39 V_42 ;
int V_43 = - V_44 ;
struct V_1 * V_5 ;
if ( F_18 ( & V_42 , V_40 , sizeof( struct V_39 ) ) )
return - V_45 ;
V_42 . V_46 [ V_47 - 1 ] = 0 ;
F_19 ( F_20 ( V_22 ) , V_42 . V_46 ) ;
V_5 = F_21 ( F_20 ( V_22 ) , V_42 . V_46 ) ;
if ( ! V_5 )
return - V_48 ;
if ( V_5 -> type == V_14 && V_5 -> V_49 -> V_50 )
V_43 = V_5 -> V_49 -> V_50 ( V_5 , & V_42 , V_41 ) ;
if ( ! V_43 && F_22 ( V_40 , & V_42 , sizeof( struct V_39 ) ) )
V_43 = - V_45 ;
F_23 ( V_5 ) ;
return V_43 ;
}
static int F_24 ( struct V_20 * V_21 , unsigned int V_41 ,
unsigned long V_40 )
{
struct V_21 * V_22 = V_21 -> V_22 ;
switch ( V_41 ) {
case V_51 :
return F_25 ( V_22 , (struct V_52 T_4 * ) V_40 ) ;
case V_53 :
return F_26 ( V_22 , (struct V_54 T_4 * ) V_40 ) ;
case V_55 :
case V_56 :
return F_17 ( V_22 , (struct V_39 T_4 * ) V_40 ,
V_41 ) ;
default:
if ( ! V_22 -> V_23 -> V_57 )
return - V_44 ;
return V_22 -> V_23 -> V_57 ( V_22 , V_41 , V_40 ) ;
}
}
static void F_27 ( struct V_21 * V_22 )
{
F_28 ( & V_58 ) ;
F_29 ( V_22 , & V_59 ) ;
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , 1 ) ;
F_31 ( & V_58 ) ;
}
static void F_32 ( struct V_21 * V_22 )
{
F_28 ( & V_58 ) ;
if ( F_33 ( V_22 ) )
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , - 1 ) ;
F_31 ( & V_58 ) ;
}
static void F_34 ( struct V_21 * V_22 , long V_60 )
{
F_35 ( V_22 ) ;
}
static int F_36 ( struct V_21 * V_22 , struct V_29 * V_61 , int V_27 )
{
struct V_3 V_4 ;
struct V_62 * V_30 = (struct V_62 * ) V_61 ;
int V_63 = 0 ;
struct V_1 * V_5 = NULL ;
if ( V_27 < sizeof( * V_30 ) )
return - V_35 ;
V_30 = (struct V_62 * ) V_61 ;
if ( V_30 -> V_64 != V_65 )
return - V_35 ;
F_37 ( V_22 ) ;
F_38 ( & V_4 , & V_30 -> V_4 ) ;
V_5 = F_1 ( F_20 ( V_22 ) , & V_4 ) ;
if ( ! V_5 ) {
V_63 = - V_48 ;
goto V_66;
}
V_22 -> V_67 = V_5 -> V_68 ;
F_39 ( V_22 ) ;
F_23 ( V_5 ) ;
V_66:
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_41 ( struct V_21 * V_22 , struct V_29 * V_30 ,
int V_31 )
{
return - V_69 ;
}
static int F_42 ( struct V_21 * V_22 , int V_33 )
{
return 0 ;
}
static int F_43 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_70 )
{
struct V_1 * V_5 ;
unsigned int V_71 ;
struct V_72 * V_73 ;
int V_74 , V_75 ;
int V_63 ;
if ( V_26 -> V_76 & V_77 ) {
F_44 ( L_2 , V_26 -> V_76 ) ;
return - V_78 ;
}
F_37 ( V_22 ) ;
if ( ! V_22 -> V_67 )
V_5 = F_45 ( F_20 ( V_22 ) , V_14 ) ;
else
V_5 = F_46 ( F_20 ( V_22 ) , V_22 -> V_67 ) ;
F_40 ( V_22 ) ;
if ( ! V_5 ) {
F_44 ( L_3 ) ;
V_63 = - V_79 ;
goto V_66;
}
V_71 = V_80 ;
F_44 ( L_4 , V_5 -> V_81 , V_71 ) ;
if ( V_70 > V_71 ) {
F_44 ( L_5 , V_70 , V_71 ) ;
V_63 = - V_82 ;
goto V_83;
}
V_74 = F_47 ( V_5 ) ;
V_75 = V_5 -> V_84 ;
V_73 = F_48 ( V_22 , V_74 + V_75 + V_70 ,
V_26 -> V_76 & V_85 , & V_63 ) ;
if ( ! V_73 )
goto V_83;
F_49 ( V_73 , V_74 ) ;
F_50 ( V_73 ) ;
F_51 ( V_73 ) ;
V_63 = F_52 ( F_53 ( V_73 , V_70 ) , V_26 , V_70 ) ;
if ( V_63 < 0 )
goto V_86;
V_73 -> V_5 = V_5 ;
V_73 -> V_22 = V_22 ;
V_73 -> V_87 = F_54 ( V_88 ) ;
F_23 ( V_5 ) ;
V_63 = F_55 ( V_73 ) ;
if ( V_63 > 0 )
V_63 = F_56 ( V_63 ) ;
return V_63 ? : V_70 ;
V_86:
F_57 ( V_73 ) ;
V_83:
F_23 ( V_5 ) ;
V_66:
return V_63 ;
}
static int F_58 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_27 ,
int V_89 , int V_33 , int * V_31 )
{
T_3 V_90 = 0 ;
int V_63 = - V_78 ;
struct V_72 * V_73 ;
V_73 = F_59 ( V_22 , V_33 , V_89 , & V_63 ) ;
if ( ! V_73 )
goto V_66;
V_90 = V_73 -> V_27 ;
if ( V_27 < V_90 ) {
V_26 -> V_76 |= V_91 ;
V_90 = V_27 ;
}
V_63 = F_60 ( V_73 , 0 , V_26 , V_90 ) ;
if ( V_63 )
goto V_92;
F_61 ( V_26 , V_22 , V_73 ) ;
if ( V_33 & V_91 )
V_90 = V_73 -> V_27 ;
V_92:
F_62 ( V_22 , V_73 ) ;
V_66:
if ( V_63 )
return V_63 ;
return V_90 ;
}
static int F_63 ( struct V_21 * V_22 , struct V_72 * V_73 )
{
V_73 = F_64 ( V_73 , V_93 ) ;
if ( ! V_73 )
return V_94 ;
if ( F_65 ( V_22 , V_73 ) < 0 ) {
F_57 ( V_73 ) ;
return V_94 ;
}
return V_95 ;
}
static void F_66 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_21 * V_22 ;
F_67 ( & V_58 ) ;
F_68 (sk, &raw_head) {
F_69 ( V_22 ) ;
if ( ! V_22 -> V_67 ||
V_22 -> V_67 == V_5 -> V_68 ) {
struct V_72 * V_96 ;
V_96 = F_70 ( V_73 , V_93 ) ;
if ( V_96 )
F_63 ( V_22 , V_96 ) ;
}
F_71 ( V_22 ) ;
}
F_72 ( & V_58 ) ;
}
static int F_73 ( struct V_21 * V_22 , int V_97 , int V_98 ,
char T_4 * V_99 , int T_4 * V_100 )
{
return - V_78 ;
}
static int F_74 ( struct V_21 * V_22 , int V_97 , int V_98 ,
char T_4 * V_99 , unsigned int V_100 )
{
return - V_78 ;
}
static inline struct V_101 * F_75 ( const struct V_21 * V_22 )
{
return F_76 ( V_22 , struct V_101 , V_22 ) ;
}
static void F_77 ( struct V_21 * V_22 )
{
F_28 ( & V_102 ) ;
F_29 ( V_22 , & V_103 ) ;
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , 1 ) ;
F_31 ( & V_102 ) ;
}
static void F_78 ( struct V_21 * V_22 )
{
F_28 ( & V_102 ) ;
if ( F_33 ( V_22 ) )
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , - 1 ) ;
F_31 ( & V_102 ) ;
}
static int F_79 ( struct V_21 * V_22 )
{
struct V_101 * V_104 = F_75 ( V_22 ) ;
V_104 -> V_105 = 1 ;
return 0 ;
}
static void F_80 ( struct V_21 * V_22 , long V_60 )
{
F_35 ( V_22 ) ;
}
static int F_81 ( struct V_21 * V_22 , struct V_29 * V_30 , int V_27 )
{
struct V_62 * V_4 = (struct V_62 * ) V_30 ;
struct V_3 V_106 ;
struct V_101 * V_104 = F_75 ( V_22 ) ;
int V_63 = - V_35 ;
struct V_1 * V_5 ;
F_37 ( V_22 ) ;
V_104 -> V_107 = 0 ;
if ( V_27 < sizeof( * V_4 ) )
goto V_66;
if ( V_4 -> V_64 != V_65 )
goto V_66;
F_38 ( & V_106 , & V_4 -> V_4 ) ;
V_5 = F_1 ( F_20 ( V_22 ) , & V_106 ) ;
if ( ! V_5 ) {
V_63 = - V_48 ;
goto V_66;
}
if ( V_5 -> type != V_14 ) {
V_63 = - V_48 ;
goto V_108;
}
V_104 -> V_109 = V_106 ;
V_104 -> V_107 = 1 ;
V_63 = 0 ;
V_108:
F_23 ( V_5 ) ;
V_66:
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_82 ( struct V_21 * V_22 , int V_41 , unsigned long V_40 )
{
switch ( V_41 ) {
case V_110 :
{
int V_111 = F_83 ( V_22 ) ;
return F_84 ( V_111 , ( int T_4 * ) V_40 ) ;
}
case V_112 :
{
struct V_72 * V_73 ;
unsigned long V_111 ;
V_111 = 0 ;
F_85 ( & V_22 -> V_113 . V_114 ) ;
V_73 = F_86 ( & V_22 -> V_113 ) ;
if ( V_73 ) {
V_111 = V_73 -> V_27 - F_87 ( V_73 ) ;
}
F_88 ( & V_22 -> V_113 . V_114 ) ;
return F_84 ( V_111 , ( int T_4 * ) V_40 ) ;
}
}
return - V_44 ;
}
static int F_89 ( struct V_21 * V_22 , struct V_29 * V_30 ,
int V_27 )
{
struct V_62 * V_4 = (struct V_62 * ) V_30 ;
struct V_101 * V_104 = F_75 ( V_22 ) ;
int V_63 = 0 ;
if ( V_27 < sizeof( * V_4 ) )
return - V_35 ;
if ( V_4 -> V_64 != V_65 )
return - V_35 ;
F_37 ( V_22 ) ;
if ( ! V_104 -> V_107 ) {
V_63 = - V_115 ;
goto V_66;
}
F_38 ( & V_104 -> V_116 , & V_4 -> V_4 ) ;
V_104 -> V_117 = 1 ;
V_66:
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_90 ( struct V_21 * V_22 , int V_33 )
{
struct V_101 * V_104 = F_75 ( V_22 ) ;
F_37 ( V_22 ) ;
V_104 -> V_117 = 0 ;
F_40 ( V_22 ) ;
return 0 ;
}
static int F_91 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_70 )
{
struct V_1 * V_5 ;
unsigned int V_71 ;
struct V_72 * V_73 ;
struct V_118 * V_119 ;
struct V_101 * V_104 = F_75 ( V_22 ) ;
struct V_3 V_116 ;
int V_74 , V_75 ;
int V_63 ;
if ( V_26 -> V_76 & V_77 ) {
F_44 ( L_2 , V_26 -> V_76 ) ;
return - V_78 ;
}
if ( ! V_104 -> V_117 && ! V_26 -> V_120 )
return - V_121 ;
else if ( V_104 -> V_117 && V_26 -> V_120 )
return - V_122 ;
if ( ! V_104 -> V_107 )
V_5 = F_45 ( F_20 ( V_22 ) , V_14 ) ;
else
V_5 = F_1 ( F_20 ( V_22 ) , & V_104 -> V_109 ) ;
if ( ! V_5 ) {
F_44 ( L_3 ) ;
V_63 = - V_79 ;
goto V_66;
}
V_71 = V_80 ;
F_44 ( L_4 , V_5 -> V_81 , V_71 ) ;
if ( V_70 > V_71 ) {
F_44 ( L_5 , V_70 , V_71 ) ;
V_63 = - V_82 ;
goto V_83;
}
V_74 = F_47 ( V_5 ) ;
V_75 = V_5 -> V_84 ;
V_73 = F_48 ( V_22 , V_74 + V_75 + V_70 ,
V_26 -> V_76 & V_85 ,
& V_63 ) ;
if ( ! V_73 )
goto V_83;
F_49 ( V_73 , V_74 ) ;
F_51 ( V_73 ) ;
V_119 = F_92 ( V_73 ) ;
V_119 -> type = V_123 ;
V_119 -> V_124 = V_104 -> V_105 ;
if ( V_26 -> V_120 ) {
F_93 ( struct V_62 * ,
V_125 , V_26 -> V_120 ) ;
F_38 ( & V_116 , & V_125 -> V_4 ) ;
} else {
V_116 = V_104 -> V_116 ;
}
V_119 -> V_126 = V_104 -> V_126 ;
V_119 -> V_127 = V_104 -> V_127 ;
V_119 -> V_128 = V_104 -> V_128 ;
V_119 -> V_129 = V_104 -> V_129 ;
V_63 = F_94 ( V_73 , V_5 , & V_116 ,
V_104 -> V_107 ? & V_104 -> V_109 : NULL , V_70 ) ;
if ( V_63 < 0 )
goto V_86;
V_63 = F_52 ( F_53 ( V_73 , V_70 ) , V_26 , V_70 ) ;
if ( V_63 < 0 )
goto V_86;
V_73 -> V_5 = V_5 ;
V_73 -> V_22 = V_22 ;
V_73 -> V_87 = F_54 ( V_88 ) ;
F_23 ( V_5 ) ;
V_63 = F_55 ( V_73 ) ;
if ( V_63 > 0 )
V_63 = F_56 ( V_63 ) ;
return V_63 ? : V_70 ;
V_86:
F_57 ( V_73 ) ;
V_83:
F_23 ( V_5 ) ;
V_66:
return V_63 ;
}
static int F_95 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_27 ,
int V_89 , int V_33 , int * V_31 )
{
T_3 V_90 = 0 ;
int V_63 = - V_78 ;
struct V_72 * V_73 ;
F_93 ( struct V_62 * , V_130 , V_26 -> V_120 ) ;
V_73 = F_59 ( V_22 , V_33 , V_89 , & V_63 ) ;
if ( ! V_73 )
goto V_66;
V_90 = V_73 -> V_27 ;
if ( V_27 < V_90 ) {
V_26 -> V_76 |= V_91 ;
V_90 = V_27 ;
}
V_63 = F_60 ( V_73 , 0 , V_26 , V_90 ) ;
if ( V_63 )
goto V_92;
F_61 ( V_26 , V_22 , V_73 ) ;
if ( V_130 ) {
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> V_64 = V_65 ;
F_96 ( & V_130 -> V_4 , & F_97 ( V_73 ) -> V_131 ) ;
* V_31 = sizeof( * V_130 ) ;
}
if ( V_33 & V_91 )
V_90 = V_73 -> V_27 ;
V_92:
F_62 ( V_22 , V_73 ) ;
V_66:
if ( V_63 )
return V_63 ;
return V_90 ;
}
static int F_98 ( struct V_21 * V_22 , struct V_72 * V_73 )
{
V_73 = F_64 ( V_73 , V_93 ) ;
if ( ! V_73 )
return V_94 ;
if ( F_65 ( V_22 , V_73 ) < 0 ) {
F_57 ( V_73 ) ;
return V_94 ;
}
return V_95 ;
}
static inline bool
F_99 ( T_5 V_132 , T_1 V_7 , T_1 V_8 ,
struct V_101 * V_104 )
{
if ( ! V_104 -> V_107 )
return true ;
if ( V_104 -> V_109 . V_11 == V_12 &&
V_132 == V_104 -> V_109 . V_13 )
return true ;
if ( V_104 -> V_109 . V_11 == V_15 &&
V_7 == V_104 -> V_109 . V_7 &&
V_8 == V_104 -> V_109 . V_8 )
return true ;
return false ;
}
static int F_100 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_21 * V_22 , * V_133 = NULL ;
int V_43 = V_95 ;
T_1 V_7 , V_8 ;
T_5 V_132 ;
F_101 ( V_5 -> type != V_14 ) ;
V_7 = V_5 -> V_19 -> V_7 ;
V_8 = V_5 -> V_19 -> V_8 ;
V_132 = V_5 -> V_19 -> V_13 ;
F_67 ( & V_102 ) ;
F_68 (sk, &dgram_head) {
if ( F_99 ( V_132 , V_7 , V_8 ,
F_75 ( V_22 ) ) ) {
if ( V_133 ) {
struct V_72 * V_96 ;
V_96 = F_70 ( V_73 , V_93 ) ;
if ( V_96 )
F_98 ( V_133 , V_96 ) ;
}
V_133 = V_22 ;
}
}
if ( V_133 ) {
F_98 ( V_133 , V_73 ) ;
} else {
F_57 ( V_73 ) ;
V_43 = V_94 ;
}
F_72 ( & V_102 ) ;
return V_43 ;
}
static int F_102 ( struct V_21 * V_22 , int V_97 , int V_98 ,
char T_4 * V_99 , int T_4 * V_100 )
{
struct V_101 * V_104 = F_75 ( V_22 ) ;
int V_134 , V_27 ;
if ( V_97 != V_135 )
return - V_78 ;
if ( F_103 ( V_27 , V_100 ) )
return - V_45 ;
V_27 = F_104 (unsigned int, len, sizeof(int)) ;
switch ( V_98 ) {
case V_136 :
V_134 = V_104 -> V_105 ;
break;
case V_137 :
if ( ! V_104 -> V_127 )
V_134 = V_138 ;
else if ( V_104 -> V_126 )
V_134 = V_139 ;
else
V_134 = V_140 ;
break;
case V_141 :
if ( ! V_104 -> V_129 )
V_134 = V_142 ;
else
V_134 = V_104 -> V_128 ;
break;
default:
return - V_143 ;
}
if ( F_84 ( V_27 , V_100 ) )
return - V_45 ;
if ( F_22 ( V_99 , & V_134 , V_27 ) )
return - V_45 ;
return 0 ;
}
static int F_105 ( struct V_21 * V_22 , int V_97 , int V_98 ,
char T_4 * V_99 , unsigned int V_100 )
{
struct V_101 * V_104 = F_75 ( V_22 ) ;
struct V_2 * V_2 = F_20 ( V_22 ) ;
int V_134 ;
int V_63 = 0 ;
if ( V_100 < sizeof( int ) )
return - V_35 ;
if ( F_103 ( V_134 , ( int T_4 * ) V_99 ) )
return - V_45 ;
F_37 ( V_22 ) ;
switch ( V_98 ) {
case V_136 :
V_104 -> V_105 = ! ! V_134 ;
break;
case V_137 :
if ( ! F_106 ( V_2 -> V_144 , V_145 ) &&
! F_106 ( V_2 -> V_144 , V_146 ) ) {
V_63 = - V_147 ;
break;
}
switch ( V_134 ) {
case V_138 :
V_104 -> V_127 = 0 ;
break;
case V_139 :
V_104 -> V_127 = 1 ;
V_104 -> V_126 = 1 ;
break;
case V_140 :
V_104 -> V_127 = 1 ;
V_104 -> V_126 = 0 ;
break;
default:
V_63 = - V_35 ;
break;
}
break;
case V_141 :
if ( ! F_106 ( V_2 -> V_144 , V_145 ) &&
! F_106 ( V_2 -> V_144 , V_146 ) ) {
V_63 = - V_147 ;
break;
}
if ( V_134 < V_142 ||
V_134 > V_148 ) {
V_63 = - V_35 ;
} else if ( V_134 == V_142 ) {
V_104 -> V_129 = 0 ;
} else {
V_104 -> V_129 = 1 ;
V_104 -> V_128 = V_134 ;
}
break;
default:
V_63 = - V_143 ;
break;
}
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_107 ( struct V_2 * V_2 , struct V_20 * V_21 ,
int V_87 , int V_149 )
{
struct V_21 * V_22 ;
int V_150 ;
struct V_151 * V_151 ;
const struct V_152 * V_153 ;
if ( ! F_108 ( V_2 , & V_154 ) )
return - V_155 ;
switch ( V_21 -> type ) {
case V_156 :
V_151 = & V_157 ;
V_153 = & V_158 ;
break;
case V_159 :
V_151 = & V_160 ;
V_153 = & V_161 ;
break;
default:
V_150 = - V_162 ;
goto V_66;
}
V_150 = - V_163 ;
V_22 = F_109 ( V_2 , V_164 , V_165 , V_151 , V_149 ) ;
if ( ! V_22 )
goto V_66;
V_150 = 0 ;
V_21 -> V_153 = V_153 ;
F_110 ( V_21 , V_22 ) ;
V_22 -> V_166 = V_164 ;
F_111 ( V_22 , V_167 ) ;
if ( V_22 -> V_23 -> V_168 )
V_22 -> V_23 -> V_168 ( V_22 ) ;
if ( V_22 -> V_23 -> V_169 ) {
V_150 = V_22 -> V_23 -> V_169 ( V_22 ) ;
if ( V_150 )
F_35 ( V_22 ) ;
}
V_66:
return V_150 ;
}
static int F_112 ( struct V_72 * V_73 , struct V_1 * V_5 ,
struct V_170 * V_171 , struct V_1 * V_172 )
{
if ( ! F_113 ( V_5 ) )
goto V_173;
F_44 ( L_6 , V_5 -> type , V_5 ) ;
#ifdef F_114
F_115 ( L_7 ,
V_174 , V_73 -> V_175 , V_73 -> V_27 ) ;
#endif
if ( ! F_108 ( F_116 ( V_5 ) , & V_154 ) )
goto V_173;
F_66 ( V_5 , V_73 ) ;
if ( V_5 -> type != V_14 )
goto V_173;
if ( V_73 -> V_176 != V_177 )
return F_100 ( V_5 , V_73 ) ;
V_173:
F_57 ( V_73 ) ;
return V_94 ;
}
static int T_6 F_117 ( void )
{
int V_150 = - V_35 ;
V_150 = F_118 ( & V_157 , 1 ) ;
if ( V_150 )
goto V_66;
V_150 = F_118 ( & V_160 , 1 ) ;
if ( V_150 )
goto V_178;
V_150 = F_119 ( & V_179 ) ;
if ( V_150 )
goto V_180;
F_120 ( & V_181 ) ;
V_150 = 0 ;
goto V_66;
V_180:
F_121 ( & V_160 ) ;
V_178:
F_121 ( & V_157 ) ;
V_66:
return V_150 ;
}
static void T_7 F_122 ( void )
{
F_123 ( & V_181 ) ;
F_124 ( V_164 ) ;
F_121 ( & V_160 ) ;
F_121 ( & V_157 ) ;
}
