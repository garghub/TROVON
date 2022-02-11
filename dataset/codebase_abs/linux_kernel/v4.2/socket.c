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
V_71 = V_5 -> V_71 ;
F_44 ( L_4 , V_5 -> V_80 , V_71 ) ;
if ( V_70 > V_71 ) {
F_44 ( L_5 , V_70 , V_71 ) ;
V_63 = - V_81 ;
goto V_82;
}
V_74 = F_47 ( V_5 ) ;
V_75 = V_5 -> V_83 ;
V_73 = F_48 ( V_22 , V_74 + V_75 + V_70 ,
V_26 -> V_76 & V_84 , & V_63 ) ;
if ( ! V_73 )
goto V_82;
F_49 ( V_73 , V_74 ) ;
F_50 ( V_73 ) ;
F_51 ( V_73 ) ;
V_63 = F_52 ( F_53 ( V_73 , V_70 ) , V_26 , V_70 ) ;
if ( V_63 < 0 )
goto V_85;
V_73 -> V_5 = V_5 ;
V_73 -> V_22 = V_22 ;
V_73 -> V_86 = F_54 ( V_87 ) ;
F_23 ( V_5 ) ;
V_63 = F_55 ( V_73 ) ;
if ( V_63 > 0 )
V_63 = F_56 ( V_63 ) ;
return V_63 ? : V_70 ;
V_85:
F_57 ( V_73 ) ;
V_82:
F_23 ( V_5 ) ;
V_66:
return V_63 ;
}
static int F_58 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_27 ,
int V_88 , int V_33 , int * V_31 )
{
T_3 V_89 = 0 ;
int V_63 = - V_78 ;
struct V_72 * V_73 ;
V_73 = F_59 ( V_22 , V_33 , V_88 , & V_63 ) ;
if ( ! V_73 )
goto V_66;
V_89 = V_73 -> V_27 ;
if ( V_27 < V_89 ) {
V_26 -> V_76 |= V_90 ;
V_89 = V_27 ;
}
V_63 = F_60 ( V_73 , 0 , V_26 , V_89 ) ;
if ( V_63 )
goto V_91;
F_61 ( V_26 , V_22 , V_73 ) ;
if ( V_33 & V_90 )
V_89 = V_73 -> V_27 ;
V_91:
F_62 ( V_22 , V_73 ) ;
V_66:
if ( V_63 )
return V_63 ;
return V_89 ;
}
static int F_63 ( struct V_21 * V_22 , struct V_72 * V_73 )
{
V_73 = F_64 ( V_73 , V_92 ) ;
if ( ! V_73 )
return V_93 ;
if ( F_65 ( V_22 , V_73 ) < 0 ) {
F_57 ( V_73 ) ;
return V_93 ;
}
return V_94 ;
}
static void F_66 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_21 * V_22 ;
F_67 ( & V_58 ) ;
F_68 (sk, &raw_head) {
F_69 ( V_22 ) ;
if ( ! V_22 -> V_67 ||
V_22 -> V_67 == V_5 -> V_68 ) {
struct V_72 * V_95 ;
V_95 = F_70 ( V_73 , V_92 ) ;
if ( V_95 )
F_63 ( V_22 , V_95 ) ;
}
F_71 ( V_22 ) ;
}
F_72 ( & V_58 ) ;
}
static int F_73 ( struct V_21 * V_22 , int V_96 , int V_97 ,
char T_4 * V_98 , int T_4 * V_99 )
{
return - V_78 ;
}
static int F_74 ( struct V_21 * V_22 , int V_96 , int V_97 ,
char T_4 * V_98 , unsigned int V_99 )
{
return - V_78 ;
}
static inline struct V_100 * F_75 ( const struct V_21 * V_22 )
{
return F_76 ( V_22 , struct V_100 , V_22 ) ;
}
static void F_77 ( struct V_21 * V_22 )
{
F_28 ( & V_101 ) ;
F_29 ( V_22 , & V_102 ) ;
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , 1 ) ;
F_31 ( & V_101 ) ;
}
static void F_78 ( struct V_21 * V_22 )
{
F_28 ( & V_101 ) ;
if ( F_33 ( V_22 ) )
F_30 ( F_20 ( V_22 ) , V_22 -> V_23 , - 1 ) ;
F_31 ( & V_101 ) ;
}
static int F_79 ( struct V_21 * V_22 )
{
struct V_100 * V_103 = F_75 ( V_22 ) ;
V_103 -> V_104 = 1 ;
return 0 ;
}
static void F_80 ( struct V_21 * V_22 , long V_60 )
{
F_35 ( V_22 ) ;
}
static int F_81 ( struct V_21 * V_22 , struct V_29 * V_30 , int V_27 )
{
struct V_62 * V_4 = (struct V_62 * ) V_30 ;
struct V_3 V_105 ;
struct V_100 * V_103 = F_75 ( V_22 ) ;
int V_63 = - V_35 ;
struct V_1 * V_5 ;
F_37 ( V_22 ) ;
V_103 -> V_106 = 0 ;
if ( V_27 < sizeof( * V_4 ) )
goto V_66;
if ( V_4 -> V_64 != V_65 )
goto V_66;
F_38 ( & V_105 , & V_4 -> V_4 ) ;
V_5 = F_1 ( F_20 ( V_22 ) , & V_105 ) ;
if ( ! V_5 ) {
V_63 = - V_48 ;
goto V_66;
}
if ( V_5 -> type != V_14 ) {
V_63 = - V_48 ;
goto V_107;
}
V_103 -> V_108 = V_105 ;
V_103 -> V_106 = 1 ;
V_63 = 0 ;
V_107:
F_23 ( V_5 ) ;
V_66:
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_82 ( struct V_21 * V_22 , int V_41 , unsigned long V_40 )
{
switch ( V_41 ) {
case V_109 :
{
int V_110 = F_83 ( V_22 ) ;
return F_84 ( V_110 , ( int T_4 * ) V_40 ) ;
}
case V_111 :
{
struct V_72 * V_73 ;
unsigned long V_110 ;
V_110 = 0 ;
F_85 ( & V_22 -> V_112 . V_113 ) ;
V_73 = F_86 ( & V_22 -> V_112 ) ;
if ( V_73 ) {
V_110 = V_73 -> V_27 - F_87 ( V_73 ) ;
}
F_88 ( & V_22 -> V_112 . V_113 ) ;
return F_84 ( V_110 , ( int T_4 * ) V_40 ) ;
}
}
return - V_44 ;
}
static int F_89 ( struct V_21 * V_22 , struct V_29 * V_30 ,
int V_27 )
{
struct V_62 * V_4 = (struct V_62 * ) V_30 ;
struct V_100 * V_103 = F_75 ( V_22 ) ;
int V_63 = 0 ;
if ( V_27 < sizeof( * V_4 ) )
return - V_35 ;
if ( V_4 -> V_64 != V_65 )
return - V_35 ;
F_37 ( V_22 ) ;
if ( ! V_103 -> V_106 ) {
V_63 = - V_114 ;
goto V_66;
}
F_38 ( & V_103 -> V_115 , & V_4 -> V_4 ) ;
V_103 -> V_116 = 1 ;
V_66:
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_90 ( struct V_21 * V_22 , int V_33 )
{
struct V_100 * V_103 = F_75 ( V_22 ) ;
F_37 ( V_22 ) ;
V_103 -> V_116 = 0 ;
F_40 ( V_22 ) ;
return 0 ;
}
static int F_91 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_70 )
{
struct V_1 * V_5 ;
unsigned int V_71 ;
struct V_72 * V_73 ;
struct V_117 * V_118 ;
struct V_100 * V_103 = F_75 ( V_22 ) ;
struct V_3 V_115 ;
int V_74 , V_75 ;
int V_63 ;
if ( V_26 -> V_76 & V_77 ) {
F_44 ( L_2 , V_26 -> V_76 ) ;
return - V_78 ;
}
if ( ! V_103 -> V_116 && ! V_26 -> V_119 )
return - V_120 ;
else if ( V_103 -> V_116 && V_26 -> V_119 )
return - V_121 ;
if ( ! V_103 -> V_106 )
V_5 = F_45 ( F_20 ( V_22 ) , V_14 ) ;
else
V_5 = F_1 ( F_20 ( V_22 ) , & V_103 -> V_108 ) ;
if ( ! V_5 ) {
F_44 ( L_3 ) ;
V_63 = - V_79 ;
goto V_66;
}
V_71 = V_5 -> V_71 ;
F_44 ( L_4 , V_5 -> V_80 , V_71 ) ;
if ( V_70 > V_71 ) {
F_44 ( L_5 , V_70 , V_71 ) ;
V_63 = - V_81 ;
goto V_82;
}
V_74 = F_47 ( V_5 ) ;
V_75 = V_5 -> V_83 ;
V_73 = F_48 ( V_22 , V_74 + V_75 + V_70 ,
V_26 -> V_76 & V_84 ,
& V_63 ) ;
if ( ! V_73 )
goto V_82;
F_49 ( V_73 , V_74 ) ;
F_51 ( V_73 ) ;
V_118 = F_92 ( V_73 ) ;
V_118 -> type = V_122 ;
V_118 -> V_123 = V_103 -> V_104 ;
if ( V_26 -> V_119 ) {
F_93 ( struct V_62 * ,
V_124 , V_26 -> V_119 ) ;
F_38 ( & V_115 , & V_124 -> V_4 ) ;
} else {
V_115 = V_103 -> V_115 ;
}
V_118 -> V_125 = V_103 -> V_125 ;
V_118 -> V_126 = V_103 -> V_126 ;
V_118 -> V_127 = V_103 -> V_127 ;
V_118 -> V_128 = V_103 -> V_128 ;
V_63 = F_94 ( V_73 , V_5 , V_87 , & V_115 ,
V_103 -> V_106 ? & V_103 -> V_108 : NULL , V_70 ) ;
if ( V_63 < 0 )
goto V_85;
V_63 = F_52 ( F_53 ( V_73 , V_70 ) , V_26 , V_70 ) ;
if ( V_63 < 0 )
goto V_85;
V_73 -> V_5 = V_5 ;
V_73 -> V_22 = V_22 ;
V_73 -> V_86 = F_54 ( V_87 ) ;
F_23 ( V_5 ) ;
V_63 = F_55 ( V_73 ) ;
if ( V_63 > 0 )
V_63 = F_56 ( V_63 ) ;
return V_63 ? : V_70 ;
V_85:
F_57 ( V_73 ) ;
V_82:
F_23 ( V_5 ) ;
V_66:
return V_63 ;
}
static int F_95 ( struct V_21 * V_22 , struct V_25 * V_26 , T_3 V_27 ,
int V_88 , int V_33 , int * V_31 )
{
T_3 V_89 = 0 ;
int V_63 = - V_78 ;
struct V_72 * V_73 ;
F_93 ( struct V_62 * , V_129 , V_26 -> V_119 ) ;
V_73 = F_59 ( V_22 , V_33 , V_88 , & V_63 ) ;
if ( ! V_73 )
goto V_66;
V_89 = V_73 -> V_27 ;
if ( V_27 < V_89 ) {
V_26 -> V_76 |= V_90 ;
V_89 = V_27 ;
}
V_63 = F_60 ( V_73 , 0 , V_26 , V_89 ) ;
if ( V_63 )
goto V_91;
F_61 ( V_26 , V_22 , V_73 ) ;
if ( V_129 ) {
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> V_64 = V_65 ;
F_96 ( & V_129 -> V_4 , & F_97 ( V_73 ) -> V_130 ) ;
* V_31 = sizeof( * V_129 ) ;
}
if ( V_33 & V_90 )
V_89 = V_73 -> V_27 ;
V_91:
F_62 ( V_22 , V_73 ) ;
V_66:
if ( V_63 )
return V_63 ;
return V_89 ;
}
static int F_98 ( struct V_21 * V_22 , struct V_72 * V_73 )
{
V_73 = F_64 ( V_73 , V_92 ) ;
if ( ! V_73 )
return V_93 ;
if ( F_65 ( V_22 , V_73 ) < 0 ) {
F_57 ( V_73 ) ;
return V_93 ;
}
return V_94 ;
}
static inline bool
F_99 ( T_5 V_131 , T_1 V_7 , T_1 V_8 ,
struct V_100 * V_103 )
{
if ( ! V_103 -> V_106 )
return true ;
if ( V_103 -> V_108 . V_11 == V_12 &&
V_131 == V_103 -> V_108 . V_13 )
return true ;
if ( V_103 -> V_108 . V_11 == V_15 &&
V_7 == V_103 -> V_108 . V_7 &&
V_8 == V_103 -> V_108 . V_8 )
return true ;
return false ;
}
static int F_100 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_21 * V_22 , * V_132 = NULL ;
int V_43 = V_94 ;
T_1 V_7 , V_8 ;
T_5 V_131 ;
F_101 ( V_5 -> type != V_14 ) ;
V_7 = V_5 -> V_19 -> V_7 ;
V_8 = V_5 -> V_19 -> V_8 ;
V_131 = V_5 -> V_19 -> V_13 ;
F_67 ( & V_101 ) ;
F_68 (sk, &dgram_head) {
if ( F_99 ( V_131 , V_7 , V_8 ,
F_75 ( V_22 ) ) ) {
if ( V_132 ) {
struct V_72 * V_95 ;
V_95 = F_70 ( V_73 , V_92 ) ;
if ( V_95 )
F_98 ( V_132 , V_95 ) ;
}
V_132 = V_22 ;
}
}
if ( V_132 ) {
F_98 ( V_132 , V_73 ) ;
} else {
F_57 ( V_73 ) ;
V_43 = V_93 ;
}
F_72 ( & V_101 ) ;
return V_43 ;
}
static int F_102 ( struct V_21 * V_22 , int V_96 , int V_97 ,
char T_4 * V_98 , int T_4 * V_99 )
{
struct V_100 * V_103 = F_75 ( V_22 ) ;
int V_133 , V_27 ;
if ( V_96 != V_134 )
return - V_78 ;
if ( F_103 ( V_27 , V_99 ) )
return - V_45 ;
V_27 = F_104 (unsigned int, len, sizeof(int)) ;
switch ( V_97 ) {
case V_135 :
V_133 = V_103 -> V_104 ;
break;
case V_136 :
if ( ! V_103 -> V_126 )
V_133 = V_137 ;
else if ( V_103 -> V_125 )
V_133 = V_138 ;
else
V_133 = V_139 ;
break;
case V_140 :
if ( ! V_103 -> V_128 )
V_133 = V_141 ;
else
V_133 = V_103 -> V_127 ;
break;
default:
return - V_142 ;
}
if ( F_84 ( V_27 , V_99 ) )
return - V_45 ;
if ( F_22 ( V_98 , & V_133 , V_27 ) )
return - V_45 ;
return 0 ;
}
static int F_105 ( struct V_21 * V_22 , int V_96 , int V_97 ,
char T_4 * V_98 , unsigned int V_99 )
{
struct V_100 * V_103 = F_75 ( V_22 ) ;
struct V_2 * V_2 = F_20 ( V_22 ) ;
int V_133 ;
int V_63 = 0 ;
if ( V_99 < sizeof( int ) )
return - V_35 ;
if ( F_103 ( V_133 , ( int T_4 * ) V_98 ) )
return - V_45 ;
F_37 ( V_22 ) ;
switch ( V_97 ) {
case V_135 :
V_103 -> V_104 = ! ! V_133 ;
break;
case V_136 :
if ( ! F_106 ( V_2 -> V_143 , V_144 ) &&
! F_106 ( V_2 -> V_143 , V_145 ) ) {
V_63 = - V_146 ;
break;
}
switch ( V_133 ) {
case V_137 :
V_103 -> V_126 = 0 ;
break;
case V_138 :
V_103 -> V_126 = 1 ;
V_103 -> V_125 = 1 ;
break;
case V_139 :
V_103 -> V_126 = 1 ;
V_103 -> V_125 = 0 ;
break;
default:
V_63 = - V_35 ;
break;
}
break;
case V_140 :
if ( ! F_106 ( V_2 -> V_143 , V_144 ) &&
! F_106 ( V_2 -> V_143 , V_145 ) ) {
V_63 = - V_146 ;
break;
}
if ( V_133 < V_141 ||
V_133 > V_147 ) {
V_63 = - V_35 ;
} else if ( V_133 == V_141 ) {
V_103 -> V_128 = 0 ;
} else {
V_103 -> V_128 = 1 ;
V_103 -> V_127 = V_133 ;
}
break;
default:
V_63 = - V_142 ;
break;
}
F_40 ( V_22 ) ;
return V_63 ;
}
static int F_107 ( struct V_2 * V_2 , struct V_20 * V_21 ,
int V_86 , int V_148 )
{
struct V_21 * V_22 ;
int V_149 ;
struct V_150 * V_150 ;
const struct V_151 * V_152 ;
if ( ! F_108 ( V_2 , & V_153 ) )
return - V_154 ;
switch ( V_21 -> type ) {
case V_155 :
V_150 = & V_156 ;
V_152 = & V_157 ;
break;
case V_158 :
V_150 = & V_159 ;
V_152 = & V_160 ;
break;
default:
V_149 = - V_161 ;
goto V_66;
}
V_149 = - V_162 ;
V_22 = F_109 ( V_2 , V_163 , V_164 , V_150 , V_148 ) ;
if ( ! V_22 )
goto V_66;
V_149 = 0 ;
V_21 -> V_152 = V_152 ;
F_110 ( V_21 , V_22 ) ;
V_22 -> V_165 = V_163 ;
F_111 ( V_22 , V_166 ) ;
if ( V_22 -> V_23 -> V_167 )
V_22 -> V_23 -> V_167 ( V_22 ) ;
if ( V_22 -> V_23 -> V_168 ) {
V_149 = V_22 -> V_23 -> V_168 ( V_22 ) ;
if ( V_149 )
F_35 ( V_22 ) ;
}
V_66:
return V_149 ;
}
static int F_112 ( struct V_72 * V_73 , struct V_1 * V_5 ,
struct V_169 * V_170 , struct V_1 * V_171 )
{
if ( ! F_113 ( V_5 ) )
goto V_172;
F_44 ( L_6 , V_5 -> type , V_5 ) ;
#ifdef F_114
F_115 ( L_7 ,
V_173 , V_73 -> V_174 , V_73 -> V_27 ) ;
#endif
if ( ! F_108 ( F_116 ( V_5 ) , & V_153 ) )
goto V_172;
F_66 ( V_5 , V_73 ) ;
if ( V_5 -> type != V_14 )
goto V_172;
if ( V_73 -> V_175 != V_176 )
return F_100 ( V_5 , V_73 ) ;
V_172:
F_57 ( V_73 ) ;
return V_93 ;
}
static int T_6 F_117 ( void )
{
int V_149 = - V_35 ;
V_149 = F_118 ( & V_156 , 1 ) ;
if ( V_149 )
goto V_66;
V_149 = F_118 ( & V_159 , 1 ) ;
if ( V_149 )
goto V_177;
V_149 = F_119 ( & V_178 ) ;
if ( V_149 )
goto V_179;
F_120 ( & V_180 ) ;
V_149 = 0 ;
goto V_66;
V_179:
F_121 ( & V_159 ) ;
V_177:
F_121 ( & V_156 ) ;
V_66:
return V_149 ;
}
static void T_7 F_122 ( void )
{
F_123 ( & V_180 ) ;
F_124 ( V_163 ) ;
F_121 ( & V_159 ) ;
F_121 ( & V_156 ) ;
}
