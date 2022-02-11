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
V_7 = F_10 ( V_6 ) -> F_11 ( V_6 ) ;
V_8 =
F_10 ( V_6 ) -> F_12 ( V_6 ) ;
if ( V_7 == V_4 -> V_7 &&
V_8 == V_4 -> V_8 ) {
V_5 = V_6 ;
F_5 ( V_5 ) ;
break;
}
}
F_13 () ;
break;
default:
F_14 ( L_1 ,
V_4 -> V_11 ) ;
break;
}
return V_5 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_21 ) {
V_20 -> V_21 = NULL ;
V_21 -> V_22 -> V_23 ( V_21 , 0 ) ;
}
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , struct V_24 * V_25 ,
T_3 V_26 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
return V_21 -> V_22 -> V_27 ( V_21 , V_25 , V_26 ) ;
}
static int F_17 ( struct V_19 * V_20 , struct V_28 * V_29 ,
int V_30 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_21 -> V_22 -> V_31 )
return V_21 -> V_22 -> V_31 ( V_21 , V_29 , V_30 ) ;
return F_18 ( V_20 , V_29 , V_30 ) ;
}
static int F_19 ( struct V_19 * V_20 , struct V_28 * V_29 ,
int V_30 , int V_32 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_30 < sizeof( V_29 -> V_33 ) )
return - V_34 ;
if ( V_29 -> V_33 == V_35 )
return V_21 -> V_22 -> V_36 ( V_21 , V_32 ) ;
return V_21 -> V_22 -> V_37 ( V_21 , V_29 , V_30 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_38 T_4 * V_39 ,
unsigned int V_40 )
{
struct V_38 V_41 ;
int V_42 = - V_43 ;
struct V_1 * V_5 ;
if ( F_21 ( & V_41 , V_39 , sizeof( struct V_38 ) ) )
return - V_44 ;
V_41 . V_45 [ V_46 - 1 ] = 0 ;
F_22 ( F_23 ( V_21 ) , V_41 . V_45 ) ;
V_5 = F_24 ( F_23 ( V_21 ) , V_41 . V_45 ) ;
if ( ! V_5 )
return - V_47 ;
if ( V_5 -> type == V_14 && V_5 -> V_48 -> V_49 )
V_42 = V_5 -> V_48 -> V_49 ( V_5 , & V_41 , V_40 ) ;
if ( ! V_42 && F_25 ( V_39 , & V_41 , sizeof( struct V_38 ) ) )
V_42 = - V_44 ;
F_26 ( V_5 ) ;
return V_42 ;
}
static int F_27 ( struct V_19 * V_20 , unsigned int V_40 ,
unsigned long V_39 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
switch ( V_40 ) {
case V_50 :
return F_28 ( V_21 , (struct V_51 T_4 * ) V_39 ) ;
case V_52 :
return F_29 ( V_21 , (struct V_53 T_4 * ) V_39 ) ;
case V_54 :
case V_55 :
return F_20 ( V_21 , (struct V_38 T_4 * ) V_39 ,
V_40 ) ;
default:
if ( ! V_21 -> V_22 -> V_56 )
return - V_43 ;
return V_21 -> V_22 -> V_56 ( V_21 , V_40 , V_39 ) ;
}
}
static void F_30 ( struct V_20 * V_21 )
{
F_31 ( & V_57 ) ;
F_32 ( V_21 , & V_58 ) ;
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , 1 ) ;
F_34 ( & V_57 ) ;
}
static void F_35 ( struct V_20 * V_21 )
{
F_31 ( & V_57 ) ;
if ( F_36 ( V_21 ) )
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , - 1 ) ;
F_34 ( & V_57 ) ;
}
static void F_37 ( struct V_20 * V_21 , long V_59 )
{
F_38 ( V_21 ) ;
}
static int F_39 ( struct V_20 * V_21 , struct V_28 * V_60 , int V_26 )
{
struct V_3 V_4 ;
struct V_61 * V_29 = (struct V_61 * ) V_60 ;
int V_62 = 0 ;
struct V_1 * V_5 = NULL ;
if ( V_26 < sizeof( * V_29 ) )
return - V_34 ;
V_29 = (struct V_61 * ) V_60 ;
if ( V_29 -> V_63 != V_64 )
return - V_34 ;
F_40 ( V_21 ) ;
F_41 ( & V_4 , & V_29 -> V_4 ) ;
V_5 = F_1 ( F_23 ( V_21 ) , & V_4 ) ;
if ( ! V_5 ) {
V_62 = - V_47 ;
goto V_65;
}
if ( V_5 -> type != V_14 ) {
V_62 = - V_47 ;
goto V_66;
}
V_21 -> V_67 = V_5 -> V_68 ;
F_42 ( V_21 ) ;
V_66:
F_26 ( V_5 ) ;
V_65:
F_43 ( V_21 ) ;
return V_62 ;
}
static int F_44 ( struct V_20 * V_21 , struct V_28 * V_29 ,
int V_30 )
{
return - V_69 ;
}
static int F_45 ( struct V_20 * V_21 , int V_32 )
{
return 0 ;
}
static int F_46 ( struct V_20 * V_21 , struct V_24 * V_25 , T_3 V_70 )
{
struct V_1 * V_5 ;
unsigned int V_71 ;
struct V_72 * V_73 ;
int V_74 , V_75 ;
int V_62 ;
if ( V_25 -> V_76 & V_77 ) {
F_47 ( L_2 , V_25 -> V_76 ) ;
return - V_78 ;
}
F_40 ( V_21 ) ;
if ( ! V_21 -> V_67 )
V_5 = F_48 ( F_23 ( V_21 ) , V_14 ) ;
else
V_5 = F_49 ( F_23 ( V_21 ) , V_21 -> V_67 ) ;
F_43 ( V_21 ) ;
if ( ! V_5 ) {
F_47 ( L_3 ) ;
V_62 = - V_79 ;
goto V_65;
}
V_71 = V_5 -> V_71 ;
F_47 ( L_4 , V_5 -> V_80 , V_71 ) ;
if ( V_70 > V_71 ) {
F_47 ( L_5 , V_70 , V_71 ) ;
V_62 = - V_34 ;
goto V_81;
}
V_74 = F_50 ( V_5 ) ;
V_75 = V_5 -> V_82 ;
V_73 = F_51 ( V_21 , V_74 + V_75 + V_70 ,
V_25 -> V_76 & V_83 , & V_62 ) ;
if ( ! V_73 )
goto V_81;
F_52 ( V_73 , V_74 ) ;
F_53 ( V_73 ) ;
F_54 ( V_73 ) ;
V_62 = F_55 ( F_56 ( V_73 , V_70 ) , V_25 , V_70 ) ;
if ( V_62 < 0 )
goto V_84;
V_73 -> V_5 = V_5 ;
V_73 -> V_21 = V_21 ;
V_73 -> V_85 = F_57 ( V_86 ) ;
F_26 ( V_5 ) ;
V_62 = F_58 ( V_73 ) ;
if ( V_62 > 0 )
V_62 = F_59 ( V_62 ) ;
return V_62 ? : V_70 ;
V_84:
F_60 ( V_73 ) ;
V_81:
F_26 ( V_5 ) ;
V_65:
return V_62 ;
}
static int F_61 ( struct V_20 * V_21 , struct V_24 * V_25 , T_3 V_26 ,
int V_87 , int V_32 , int * V_30 )
{
T_3 V_88 = 0 ;
int V_62 = - V_78 ;
struct V_72 * V_73 ;
V_73 = F_62 ( V_21 , V_32 , V_87 , & V_62 ) ;
if ( ! V_73 )
goto V_65;
V_88 = V_73 -> V_26 ;
if ( V_26 < V_88 ) {
V_25 -> V_76 |= V_89 ;
V_88 = V_26 ;
}
V_62 = F_63 ( V_73 , 0 , V_25 , V_88 ) ;
if ( V_62 )
goto V_90;
F_64 ( V_25 , V_21 , V_73 ) ;
if ( V_32 & V_89 )
V_88 = V_73 -> V_26 ;
V_90:
F_65 ( V_21 , V_73 ) ;
V_65:
if ( V_62 )
return V_62 ;
return V_88 ;
}
static int F_66 ( struct V_20 * V_21 , struct V_72 * V_73 )
{
V_73 = F_67 ( V_73 , V_91 ) ;
if ( ! V_73 )
return V_92 ;
if ( F_68 ( V_21 , V_73 ) < 0 ) {
F_60 ( V_73 ) ;
return V_92 ;
}
return V_93 ;
}
static void F_69 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_20 * V_21 ;
F_70 ( & V_57 ) ;
F_71 (sk, &raw_head) {
F_72 ( V_21 ) ;
if ( ! V_21 -> V_67 ||
V_21 -> V_67 == V_5 -> V_68 ) {
struct V_72 * V_94 ;
V_94 = F_73 ( V_73 , V_91 ) ;
if ( V_94 )
F_66 ( V_21 , V_94 ) ;
}
F_74 ( V_21 ) ;
}
F_75 ( & V_57 ) ;
}
static int F_76 ( struct V_20 * V_21 , int V_95 , int V_96 ,
char T_4 * V_97 , int T_4 * V_98 )
{
return - V_78 ;
}
static int F_77 ( struct V_20 * V_21 , int V_95 , int V_96 ,
char T_4 * V_97 , unsigned int V_98 )
{
return - V_78 ;
}
static inline struct V_99 * F_78 ( const struct V_20 * V_21 )
{
return F_79 ( V_21 , struct V_99 , V_21 ) ;
}
static void F_80 ( struct V_20 * V_21 )
{
F_31 ( & V_100 ) ;
F_32 ( V_21 , & V_101 ) ;
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , 1 ) ;
F_34 ( & V_100 ) ;
}
static void F_81 ( struct V_20 * V_21 )
{
F_31 ( & V_100 ) ;
if ( F_36 ( V_21 ) )
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , - 1 ) ;
F_34 ( & V_100 ) ;
}
static int F_82 ( struct V_20 * V_21 )
{
struct V_99 * V_102 = F_78 ( V_21 ) ;
V_102 -> V_103 = 1 ;
return 0 ;
}
static void F_83 ( struct V_20 * V_21 , long V_59 )
{
F_38 ( V_21 ) ;
}
static int F_84 ( struct V_20 * V_21 , struct V_28 * V_29 , int V_26 )
{
struct V_61 * V_4 = (struct V_61 * ) V_29 ;
struct V_3 V_104 ;
struct V_99 * V_102 = F_78 ( V_21 ) ;
int V_62 = - V_34 ;
struct V_1 * V_5 ;
F_40 ( V_21 ) ;
V_102 -> V_105 = 0 ;
if ( V_26 < sizeof( * V_4 ) )
goto V_65;
if ( V_4 -> V_63 != V_64 )
goto V_65;
F_41 ( & V_104 , & V_4 -> V_4 ) ;
V_5 = F_1 ( F_23 ( V_21 ) , & V_104 ) ;
if ( ! V_5 ) {
V_62 = - V_47 ;
goto V_65;
}
if ( V_5 -> type != V_14 ) {
V_62 = - V_47 ;
goto V_66;
}
V_102 -> V_106 = V_104 ;
V_102 -> V_105 = 1 ;
V_62 = 0 ;
V_66:
F_26 ( V_5 ) ;
V_65:
F_43 ( V_21 ) ;
return V_62 ;
}
static int F_85 ( struct V_20 * V_21 , int V_40 , unsigned long V_39 )
{
switch ( V_40 ) {
case V_107 :
{
int V_108 = F_86 ( V_21 ) ;
return F_87 ( V_108 , ( int T_4 * ) V_39 ) ;
}
case V_109 :
{
struct V_72 * V_73 ;
unsigned long V_108 ;
V_108 = 0 ;
F_88 ( & V_21 -> V_110 . V_111 ) ;
V_73 = F_89 ( & V_21 -> V_110 ) ;
if ( V_73 ) {
V_108 = V_73 -> V_26 - F_90 ( V_73 ) ;
}
F_91 ( & V_21 -> V_110 . V_111 ) ;
return F_87 ( V_108 , ( int T_4 * ) V_39 ) ;
}
}
return - V_43 ;
}
static int F_92 ( struct V_20 * V_21 , struct V_28 * V_29 ,
int V_26 )
{
struct V_61 * V_4 = (struct V_61 * ) V_29 ;
struct V_99 * V_102 = F_78 ( V_21 ) ;
int V_62 = 0 ;
if ( V_26 < sizeof( * V_4 ) )
return - V_34 ;
if ( V_4 -> V_63 != V_64 )
return - V_34 ;
F_40 ( V_21 ) ;
if ( ! V_102 -> V_105 ) {
V_62 = - V_112 ;
goto V_65;
}
F_41 ( & V_102 -> V_113 , & V_4 -> V_4 ) ;
V_102 -> V_114 = 1 ;
V_65:
F_43 ( V_21 ) ;
return V_62 ;
}
static int F_93 ( struct V_20 * V_21 , int V_32 )
{
struct V_99 * V_102 = F_78 ( V_21 ) ;
F_40 ( V_21 ) ;
V_102 -> V_114 = 0 ;
F_43 ( V_21 ) ;
return 0 ;
}
static int F_94 ( struct V_20 * V_21 , struct V_24 * V_25 , T_3 V_70 )
{
struct V_1 * V_5 ;
unsigned int V_71 ;
struct V_72 * V_73 ;
struct V_115 * V_116 ;
struct V_99 * V_102 = F_78 ( V_21 ) ;
struct V_3 V_113 ;
int V_74 , V_75 ;
int V_62 ;
if ( V_25 -> V_76 & V_77 ) {
F_47 ( L_2 , V_25 -> V_76 ) ;
return - V_78 ;
}
if ( ! V_102 -> V_114 && ! V_25 -> V_117 )
return - V_118 ;
else if ( V_102 -> V_114 && V_25 -> V_117 )
return - V_119 ;
if ( ! V_102 -> V_105 )
V_5 = F_48 ( F_23 ( V_21 ) , V_14 ) ;
else
V_5 = F_1 ( F_23 ( V_21 ) , & V_102 -> V_106 ) ;
if ( ! V_5 ) {
F_47 ( L_3 ) ;
V_62 = - V_79 ;
goto V_65;
}
V_71 = V_5 -> V_71 ;
F_47 ( L_4 , V_5 -> V_80 , V_71 ) ;
if ( V_70 > V_71 ) {
F_47 ( L_5 , V_70 , V_71 ) ;
V_62 = - V_120 ;
goto V_81;
}
V_74 = F_50 ( V_5 ) ;
V_75 = V_5 -> V_82 ;
V_73 = F_51 ( V_21 , V_74 + V_75 + V_70 ,
V_25 -> V_76 & V_83 ,
& V_62 ) ;
if ( ! V_73 )
goto V_81;
F_52 ( V_73 , V_74 ) ;
F_54 ( V_73 ) ;
V_116 = F_95 ( V_73 ) ;
V_116 -> type = V_121 ;
V_116 -> V_122 = V_102 -> V_103 ;
if ( V_25 -> V_117 ) {
F_96 ( struct V_61 * ,
V_123 , V_25 -> V_117 ) ;
F_41 ( & V_113 , & V_123 -> V_4 ) ;
} else {
V_113 = V_102 -> V_113 ;
}
V_116 -> V_124 = V_102 -> V_124 ;
V_116 -> V_125 = V_102 -> V_125 ;
V_116 -> V_126 = V_102 -> V_126 ;
V_116 -> V_127 = V_102 -> V_127 ;
V_62 = F_97 ( V_73 , V_5 , V_86 , & V_113 ,
V_102 -> V_105 ? & V_102 -> V_106 : NULL , V_70 ) ;
if ( V_62 < 0 )
goto V_84;
V_62 = F_55 ( F_56 ( V_73 , V_70 ) , V_25 , V_70 ) ;
if ( V_62 < 0 )
goto V_84;
V_73 -> V_5 = V_5 ;
V_73 -> V_21 = V_21 ;
V_73 -> V_85 = F_57 ( V_86 ) ;
F_26 ( V_5 ) ;
V_62 = F_58 ( V_73 ) ;
if ( V_62 > 0 )
V_62 = F_59 ( V_62 ) ;
return V_62 ? : V_70 ;
V_84:
F_60 ( V_73 ) ;
V_81:
F_26 ( V_5 ) ;
V_65:
return V_62 ;
}
static int F_98 ( struct V_20 * V_21 , struct V_24 * V_25 , T_3 V_26 ,
int V_87 , int V_32 , int * V_30 )
{
T_3 V_88 = 0 ;
int V_62 = - V_78 ;
struct V_72 * V_73 ;
F_96 ( struct V_61 * , V_128 , V_25 -> V_117 ) ;
V_73 = F_62 ( V_21 , V_32 , V_87 , & V_62 ) ;
if ( ! V_73 )
goto V_65;
V_88 = V_73 -> V_26 ;
if ( V_26 < V_88 ) {
V_25 -> V_76 |= V_89 ;
V_88 = V_26 ;
}
V_62 = F_63 ( V_73 , 0 , V_25 , V_88 ) ;
if ( V_62 )
goto V_90;
F_64 ( V_25 , V_21 , V_73 ) ;
if ( V_128 ) {
V_128 -> V_63 = V_64 ;
F_99 ( & V_128 -> V_4 , & F_100 ( V_73 ) -> V_129 ) ;
* V_30 = sizeof( * V_128 ) ;
}
if ( V_32 & V_89 )
V_88 = V_73 -> V_26 ;
V_90:
F_65 ( V_21 , V_73 ) ;
V_65:
if ( V_62 )
return V_62 ;
return V_88 ;
}
static int F_101 ( struct V_20 * V_21 , struct V_72 * V_73 )
{
V_73 = F_67 ( V_73 , V_91 ) ;
if ( ! V_73 )
return V_92 ;
if ( F_68 ( V_21 , V_73 ) < 0 ) {
F_60 ( V_73 ) ;
return V_92 ;
}
return V_93 ;
}
static inline bool
F_102 ( T_5 V_130 , T_1 V_7 , T_1 V_8 ,
struct V_99 * V_102 )
{
if ( ! V_102 -> V_105 )
return true ;
if ( V_102 -> V_106 . V_11 == V_12 &&
V_130 == V_102 -> V_106 . V_13 )
return true ;
if ( V_102 -> V_106 . V_11 == V_15 &&
V_7 == V_102 -> V_106 . V_7 &&
V_8 == V_102 -> V_106 . V_8 )
return true ;
return false ;
}
static int F_103 ( struct V_1 * V_5 , struct V_72 * V_73 )
{
struct V_20 * V_21 , * V_131 = NULL ;
int V_42 = V_93 ;
T_1 V_7 , V_8 ;
T_5 V_130 ;
F_104 ( V_5 -> type != V_14 ) ;
V_7 = F_10 ( V_5 ) -> F_11 ( V_5 ) ;
V_8 = F_10 ( V_5 ) -> F_12 ( V_5 ) ;
V_130 = F_105 ( V_5 -> V_132 ) ;
F_70 ( & V_100 ) ;
F_71 (sk, &dgram_head) {
if ( F_102 ( V_130 , V_7 , V_8 ,
F_78 ( V_21 ) ) ) {
if ( V_131 ) {
struct V_72 * V_94 ;
V_94 = F_73 ( V_73 , V_91 ) ;
if ( V_94 )
F_101 ( V_131 , V_94 ) ;
}
V_131 = V_21 ;
}
}
if ( V_131 ) {
F_101 ( V_131 , V_73 ) ;
} else {
F_60 ( V_73 ) ;
V_42 = V_92 ;
}
F_75 ( & V_100 ) ;
return V_42 ;
}
static int F_106 ( struct V_20 * V_21 , int V_95 , int V_96 ,
char T_4 * V_97 , int T_4 * V_98 )
{
struct V_99 * V_102 = F_78 ( V_21 ) ;
int V_133 , V_26 ;
if ( V_95 != V_134 )
return - V_78 ;
if ( F_107 ( V_26 , V_98 ) )
return - V_44 ;
V_26 = F_108 (unsigned int, len, sizeof(int)) ;
switch ( V_96 ) {
case V_135 :
V_133 = V_102 -> V_103 ;
break;
case V_136 :
if ( ! V_102 -> V_125 )
V_133 = V_137 ;
else if ( V_102 -> V_124 )
V_133 = V_138 ;
else
V_133 = V_139 ;
break;
case V_140 :
if ( ! V_102 -> V_127 )
V_133 = V_141 ;
else
V_133 = V_102 -> V_126 ;
break;
default:
return - V_142 ;
}
if ( F_87 ( V_26 , V_98 ) )
return - V_44 ;
if ( F_25 ( V_97 , & V_133 , V_26 ) )
return - V_44 ;
return 0 ;
}
static int F_109 ( struct V_20 * V_21 , int V_95 , int V_96 ,
char T_4 * V_97 , unsigned int V_98 )
{
struct V_99 * V_102 = F_78 ( V_21 ) ;
struct V_2 * V_2 = F_23 ( V_21 ) ;
int V_133 ;
int V_62 = 0 ;
if ( V_98 < sizeof( int ) )
return - V_34 ;
if ( F_107 ( V_133 , ( int T_4 * ) V_97 ) )
return - V_44 ;
F_40 ( V_21 ) ;
switch ( V_96 ) {
case V_135 :
V_102 -> V_103 = ! ! V_133 ;
break;
case V_136 :
if ( ! F_110 ( V_2 -> V_143 , V_144 ) &&
! F_110 ( V_2 -> V_143 , V_145 ) ) {
V_62 = - V_146 ;
break;
}
switch ( V_133 ) {
case V_137 :
V_102 -> V_125 = 0 ;
break;
case V_138 :
V_102 -> V_125 = 1 ;
V_102 -> V_124 = 1 ;
break;
case V_139 :
V_102 -> V_125 = 1 ;
V_102 -> V_124 = 0 ;
break;
default:
V_62 = - V_34 ;
break;
}
break;
case V_140 :
if ( ! F_110 ( V_2 -> V_143 , V_144 ) &&
! F_110 ( V_2 -> V_143 , V_145 ) ) {
V_62 = - V_146 ;
break;
}
if ( V_133 < V_141 ||
V_133 > V_147 ) {
V_62 = - V_34 ;
} else if ( V_133 == V_141 ) {
V_102 -> V_127 = 0 ;
} else {
V_102 -> V_127 = 1 ;
V_102 -> V_126 = V_133 ;
}
break;
default:
V_62 = - V_142 ;
break;
}
F_43 ( V_21 ) ;
return V_62 ;
}
static int F_111 ( struct V_2 * V_2 , struct V_19 * V_20 ,
int V_85 , int V_148 )
{
struct V_20 * V_21 ;
int V_149 ;
struct V_150 * V_150 ;
const struct V_151 * V_152 ;
if ( ! F_112 ( V_2 , & V_153 ) )
return - V_154 ;
switch ( V_20 -> type ) {
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
goto V_65;
}
V_149 = - V_162 ;
V_21 = F_113 ( V_2 , V_163 , V_164 , V_150 ) ;
if ( ! V_21 )
goto V_65;
V_149 = 0 ;
V_20 -> V_152 = V_152 ;
F_114 ( V_20 , V_21 ) ;
V_21 -> V_165 = V_163 ;
F_115 ( V_21 , V_166 ) ;
if ( V_21 -> V_22 -> V_167 )
V_21 -> V_22 -> V_167 ( V_21 ) ;
if ( V_21 -> V_22 -> V_168 ) {
V_149 = V_21 -> V_22 -> V_168 ( V_21 ) ;
if ( V_149 )
F_38 ( V_21 ) ;
}
V_65:
return V_149 ;
}
static int F_116 ( struct V_72 * V_73 , struct V_1 * V_5 ,
struct V_169 * V_170 , struct V_1 * V_171 )
{
if ( ! F_117 ( V_5 ) )
goto V_172;
F_47 ( L_6 , V_5 -> type , V_5 ) ;
#ifdef F_118
F_119 ( L_7 ,
V_173 , V_73 -> V_174 , V_73 -> V_26 ) ;
#endif
if ( ! F_112 ( F_120 ( V_5 ) , & V_153 ) )
goto V_172;
F_69 ( V_5 , V_73 ) ;
if ( V_5 -> type != V_14 )
goto V_172;
if ( V_73 -> V_175 != V_176 )
return F_103 ( V_5 , V_73 ) ;
V_172:
F_60 ( V_73 ) ;
return V_92 ;
}
static int T_6 F_121 ( void )
{
int V_149 = - V_34 ;
V_149 = F_122 ( & V_156 , 1 ) ;
if ( V_149 )
goto V_65;
V_149 = F_122 ( & V_159 , 1 ) ;
if ( V_149 )
goto V_177;
V_149 = F_123 ( & V_178 ) ;
if ( V_149 )
goto V_179;
F_124 ( & V_180 ) ;
V_149 = 0 ;
goto V_65;
V_179:
F_125 ( & V_159 ) ;
V_177:
F_125 ( & V_156 ) ;
V_65:
return V_149 ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_180 ) ;
F_128 ( V_163 ) ;
F_125 ( & V_159 ) ;
F_125 ( & V_156 ) ;
}
