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
static int F_16 ( struct V_24 * V_25 , struct V_19 * V_20 ,
struct V_26 * V_27 , T_3 V_28 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
return V_21 -> V_22 -> V_29 ( V_25 , V_21 , V_27 , V_28 ) ;
}
static int F_17 ( struct V_19 * V_20 , struct V_30 * V_31 ,
int V_32 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_21 -> V_22 -> V_33 )
return V_21 -> V_22 -> V_33 ( V_21 , V_31 , V_32 ) ;
return F_18 ( V_20 , V_31 , V_32 ) ;
}
static int F_19 ( struct V_19 * V_20 , struct V_30 * V_31 ,
int V_32 , int V_34 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
if ( V_32 < sizeof( V_31 -> V_35 ) )
return - V_36 ;
if ( V_31 -> V_35 == V_37 )
return V_21 -> V_22 -> V_38 ( V_21 , V_34 ) ;
return V_21 -> V_22 -> V_39 ( V_21 , V_31 , V_32 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_40 T_4 * V_41 ,
unsigned int V_42 )
{
struct V_40 V_43 ;
int V_44 = - V_45 ;
struct V_1 * V_5 ;
if ( F_21 ( & V_43 , V_41 , sizeof( struct V_40 ) ) )
return - V_46 ;
V_43 . V_47 [ V_48 - 1 ] = 0 ;
F_22 ( F_23 ( V_21 ) , V_43 . V_47 ) ;
V_5 = F_24 ( F_23 ( V_21 ) , V_43 . V_47 ) ;
if ( ! V_5 )
return - V_49 ;
if ( V_5 -> type == V_14 && V_5 -> V_50 -> V_51 )
V_44 = V_5 -> V_50 -> V_51 ( V_5 , & V_43 , V_42 ) ;
if ( ! V_44 && F_25 ( V_41 , & V_43 , sizeof( struct V_40 ) ) )
V_44 = - V_46 ;
F_26 ( V_5 ) ;
return V_44 ;
}
static int F_27 ( struct V_19 * V_20 , unsigned int V_42 ,
unsigned long V_41 )
{
struct V_20 * V_21 = V_20 -> V_21 ;
switch ( V_42 ) {
case V_52 :
return F_28 ( V_21 , (struct V_53 T_4 * ) V_41 ) ;
case V_54 :
return F_29 ( V_21 , (struct V_55 T_4 * ) V_41 ) ;
case V_56 :
case V_57 :
return F_20 ( V_21 , (struct V_40 T_4 * ) V_41 ,
V_42 ) ;
default:
if ( ! V_21 -> V_22 -> V_58 )
return - V_45 ;
return V_21 -> V_22 -> V_58 ( V_21 , V_42 , V_41 ) ;
}
}
static void F_30 ( struct V_20 * V_21 )
{
F_31 ( & V_59 ) ;
F_32 ( V_21 , & V_60 ) ;
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , 1 ) ;
F_34 ( & V_59 ) ;
}
static void F_35 ( struct V_20 * V_21 )
{
F_31 ( & V_59 ) ;
if ( F_36 ( V_21 ) )
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , - 1 ) ;
F_34 ( & V_59 ) ;
}
static void F_37 ( struct V_20 * V_21 , long V_61 )
{
F_38 ( V_21 ) ;
}
static int F_39 ( struct V_20 * V_21 , struct V_30 * V_62 , int V_28 )
{
struct V_3 V_4 ;
struct V_63 * V_31 = (struct V_63 * ) V_62 ;
int V_64 = 0 ;
struct V_1 * V_5 = NULL ;
if ( V_28 < sizeof( * V_31 ) )
return - V_36 ;
V_31 = (struct V_63 * ) V_62 ;
if ( V_31 -> V_65 != V_66 )
return - V_36 ;
F_40 ( V_21 ) ;
F_41 ( & V_4 , & V_31 -> V_4 ) ;
V_5 = F_1 ( F_23 ( V_21 ) , & V_4 ) ;
if ( ! V_5 ) {
V_64 = - V_49 ;
goto V_67;
}
if ( V_5 -> type != V_14 ) {
V_64 = - V_49 ;
goto V_68;
}
V_21 -> V_69 = V_5 -> V_70 ;
F_42 ( V_21 ) ;
V_68:
F_26 ( V_5 ) ;
V_67:
F_43 ( V_21 ) ;
return V_64 ;
}
static int F_44 ( struct V_20 * V_21 , struct V_30 * V_31 ,
int V_32 )
{
return - V_71 ;
}
static int F_45 ( struct V_20 * V_21 , int V_34 )
{
return 0 ;
}
static int F_46 ( struct V_24 * V_25 , struct V_20 * V_21 ,
struct V_26 * V_27 , T_3 V_72 )
{
struct V_1 * V_5 ;
unsigned int V_73 ;
struct V_74 * V_75 ;
int V_76 , V_77 ;
int V_64 ;
if ( V_27 -> V_78 & V_79 ) {
F_47 ( L_2 , V_27 -> V_78 ) ;
return - V_80 ;
}
F_40 ( V_21 ) ;
if ( ! V_21 -> V_69 )
V_5 = F_48 ( F_23 ( V_21 ) , V_14 ) ;
else
V_5 = F_49 ( F_23 ( V_21 ) , V_21 -> V_69 ) ;
F_43 ( V_21 ) ;
if ( ! V_5 ) {
F_47 ( L_3 ) ;
V_64 = - V_81 ;
goto V_67;
}
V_73 = V_5 -> V_73 ;
F_47 ( L_4 , V_5 -> V_82 , V_73 ) ;
if ( V_72 > V_73 ) {
F_47 ( L_5 , V_72 , V_73 ) ;
V_64 = - V_36 ;
goto V_83;
}
V_76 = F_50 ( V_5 ) ;
V_77 = V_5 -> V_84 ;
V_75 = F_51 ( V_21 , V_76 + V_77 + V_72 ,
V_27 -> V_78 & V_85 , & V_64 ) ;
if ( ! V_75 )
goto V_83;
F_52 ( V_75 , V_76 ) ;
F_53 ( V_75 ) ;
F_54 ( V_75 ) ;
V_64 = F_55 ( F_56 ( V_75 , V_72 ) , V_27 , V_72 ) ;
if ( V_64 < 0 )
goto V_86;
V_75 -> V_5 = V_5 ;
V_75 -> V_21 = V_21 ;
V_75 -> V_87 = F_57 ( V_88 ) ;
F_26 ( V_5 ) ;
V_64 = F_58 ( V_75 ) ;
if ( V_64 > 0 )
V_64 = F_59 ( V_64 ) ;
return V_64 ? : V_72 ;
V_86:
F_60 ( V_75 ) ;
V_83:
F_26 ( V_5 ) ;
V_67:
return V_64 ;
}
static int F_61 ( struct V_24 * V_25 , struct V_20 * V_21 , struct V_26 * V_27 ,
T_3 V_28 , int V_89 , int V_34 , int * V_32 )
{
T_3 V_90 = 0 ;
int V_64 = - V_80 ;
struct V_74 * V_75 ;
V_75 = F_62 ( V_21 , V_34 , V_89 , & V_64 ) ;
if ( ! V_75 )
goto V_67;
V_90 = V_75 -> V_28 ;
if ( V_28 < V_90 ) {
V_27 -> V_78 |= V_91 ;
V_90 = V_28 ;
}
V_64 = F_63 ( V_75 , 0 , V_27 , V_90 ) ;
if ( V_64 )
goto V_92;
F_64 ( V_27 , V_21 , V_75 ) ;
if ( V_34 & V_91 )
V_90 = V_75 -> V_28 ;
V_92:
F_65 ( V_21 , V_75 ) ;
V_67:
if ( V_64 )
return V_64 ;
return V_90 ;
}
static int F_66 ( struct V_20 * V_21 , struct V_74 * V_75 )
{
V_75 = F_67 ( V_75 , V_93 ) ;
if ( ! V_75 )
return V_94 ;
if ( F_68 ( V_21 , V_75 ) < 0 ) {
F_60 ( V_75 ) ;
return V_94 ;
}
return V_95 ;
}
static void F_69 ( struct V_1 * V_5 , struct V_74 * V_75 )
{
struct V_20 * V_21 ;
F_70 ( & V_59 ) ;
F_71 (sk, &raw_head) {
F_72 ( V_21 ) ;
if ( ! V_21 -> V_69 ||
V_21 -> V_69 == V_5 -> V_70 ) {
struct V_74 * V_96 ;
V_96 = F_73 ( V_75 , V_93 ) ;
if ( V_96 )
F_66 ( V_21 , V_96 ) ;
}
F_74 ( V_21 ) ;
}
F_75 ( & V_59 ) ;
}
static int F_76 ( struct V_20 * V_21 , int V_97 , int V_98 ,
char T_4 * V_99 , int T_4 * V_100 )
{
return - V_80 ;
}
static int F_77 ( struct V_20 * V_21 , int V_97 , int V_98 ,
char T_4 * V_99 , unsigned int V_100 )
{
return - V_80 ;
}
static inline struct V_101 * F_78 ( const struct V_20 * V_21 )
{
return F_79 ( V_21 , struct V_101 , V_21 ) ;
}
static void F_80 ( struct V_20 * V_21 )
{
F_31 ( & V_102 ) ;
F_32 ( V_21 , & V_103 ) ;
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , 1 ) ;
F_34 ( & V_102 ) ;
}
static void F_81 ( struct V_20 * V_21 )
{
F_31 ( & V_102 ) ;
if ( F_36 ( V_21 ) )
F_33 ( F_23 ( V_21 ) , V_21 -> V_22 , - 1 ) ;
F_34 ( & V_102 ) ;
}
static int F_82 ( struct V_20 * V_21 )
{
struct V_101 * V_104 = F_78 ( V_21 ) ;
V_104 -> V_105 = 1 ;
return 0 ;
}
static void F_83 ( struct V_20 * V_21 , long V_61 )
{
F_38 ( V_21 ) ;
}
static int F_84 ( struct V_20 * V_21 , struct V_30 * V_31 , int V_28 )
{
struct V_63 * V_4 = (struct V_63 * ) V_31 ;
struct V_3 V_106 ;
struct V_101 * V_104 = F_78 ( V_21 ) ;
int V_64 = - V_36 ;
struct V_1 * V_5 ;
F_40 ( V_21 ) ;
V_104 -> V_107 = 0 ;
if ( V_28 < sizeof( * V_4 ) )
goto V_67;
if ( V_4 -> V_65 != V_66 )
goto V_67;
F_41 ( & V_106 , & V_4 -> V_4 ) ;
V_5 = F_1 ( F_23 ( V_21 ) , & V_106 ) ;
if ( ! V_5 ) {
V_64 = - V_49 ;
goto V_67;
}
if ( V_5 -> type != V_14 ) {
V_64 = - V_49 ;
goto V_68;
}
V_104 -> V_108 = V_106 ;
V_104 -> V_107 = 1 ;
V_64 = 0 ;
V_68:
F_26 ( V_5 ) ;
V_67:
F_43 ( V_21 ) ;
return V_64 ;
}
static int F_85 ( struct V_20 * V_21 , int V_42 , unsigned long V_41 )
{
switch ( V_42 ) {
case V_109 :
{
int V_110 = F_86 ( V_21 ) ;
return F_87 ( V_110 , ( int T_4 * ) V_41 ) ;
}
case V_111 :
{
struct V_74 * V_75 ;
unsigned long V_110 ;
V_110 = 0 ;
F_88 ( & V_21 -> V_112 . V_113 ) ;
V_75 = F_89 ( & V_21 -> V_112 ) ;
if ( V_75 ) {
V_110 = V_75 -> V_28 - F_90 ( V_75 ) ;
}
F_91 ( & V_21 -> V_112 . V_113 ) ;
return F_87 ( V_110 , ( int T_4 * ) V_41 ) ;
}
}
return - V_45 ;
}
static int F_92 ( struct V_20 * V_21 , struct V_30 * V_31 ,
int V_28 )
{
struct V_63 * V_4 = (struct V_63 * ) V_31 ;
struct V_101 * V_104 = F_78 ( V_21 ) ;
int V_64 = 0 ;
if ( V_28 < sizeof( * V_4 ) )
return - V_36 ;
if ( V_4 -> V_65 != V_66 )
return - V_36 ;
F_40 ( V_21 ) ;
if ( ! V_104 -> V_107 ) {
V_64 = - V_114 ;
goto V_67;
}
F_41 ( & V_104 -> V_115 , & V_4 -> V_4 ) ;
V_104 -> V_116 = 1 ;
V_67:
F_43 ( V_21 ) ;
return V_64 ;
}
static int F_93 ( struct V_20 * V_21 , int V_34 )
{
struct V_101 * V_104 = F_78 ( V_21 ) ;
F_40 ( V_21 ) ;
V_104 -> V_116 = 0 ;
F_43 ( V_21 ) ;
return 0 ;
}
static int F_94 ( struct V_24 * V_25 , struct V_20 * V_21 ,
struct V_26 * V_27 , T_3 V_72 )
{
struct V_1 * V_5 ;
unsigned int V_73 ;
struct V_74 * V_75 ;
struct V_117 * V_118 ;
struct V_101 * V_104 = F_78 ( V_21 ) ;
struct V_3 V_115 ;
int V_76 , V_77 ;
int V_64 ;
if ( V_27 -> V_78 & V_79 ) {
F_47 ( L_2 , V_27 -> V_78 ) ;
return - V_80 ;
}
if ( ! V_104 -> V_116 && ! V_27 -> V_119 )
return - V_120 ;
else if ( V_104 -> V_116 && V_27 -> V_119 )
return - V_121 ;
if ( ! V_104 -> V_107 )
V_5 = F_48 ( F_23 ( V_21 ) , V_14 ) ;
else
V_5 = F_1 ( F_23 ( V_21 ) , & V_104 -> V_108 ) ;
if ( ! V_5 ) {
F_47 ( L_3 ) ;
V_64 = - V_81 ;
goto V_67;
}
V_73 = V_5 -> V_73 ;
F_47 ( L_4 , V_5 -> V_82 , V_73 ) ;
if ( V_72 > V_73 ) {
F_47 ( L_5 , V_72 , V_73 ) ;
V_64 = - V_122 ;
goto V_83;
}
V_76 = F_50 ( V_5 ) ;
V_77 = V_5 -> V_84 ;
V_75 = F_51 ( V_21 , V_76 + V_77 + V_72 ,
V_27 -> V_78 & V_85 ,
& V_64 ) ;
if ( ! V_75 )
goto V_83;
F_52 ( V_75 , V_76 ) ;
F_54 ( V_75 ) ;
V_118 = F_95 ( V_75 ) ;
V_118 -> type = V_123 ;
V_118 -> V_124 = V_104 -> V_105 ;
if ( V_27 -> V_119 ) {
F_96 ( struct V_63 * ,
V_125 , V_27 -> V_119 ) ;
F_41 ( & V_115 , & V_125 -> V_4 ) ;
} else {
V_115 = V_104 -> V_115 ;
}
V_118 -> V_126 = V_104 -> V_126 ;
V_118 -> V_127 = V_104 -> V_127 ;
V_118 -> V_128 = V_104 -> V_128 ;
V_118 -> V_129 = V_104 -> V_129 ;
V_64 = F_97 ( V_75 , V_5 , V_88 , & V_115 ,
V_104 -> V_107 ? & V_104 -> V_108 : NULL , V_72 ) ;
if ( V_64 < 0 )
goto V_86;
V_64 = F_55 ( F_56 ( V_75 , V_72 ) , V_27 , V_72 ) ;
if ( V_64 < 0 )
goto V_86;
V_75 -> V_5 = V_5 ;
V_75 -> V_21 = V_21 ;
V_75 -> V_87 = F_57 ( V_88 ) ;
F_26 ( V_5 ) ;
V_64 = F_58 ( V_75 ) ;
if ( V_64 > 0 )
V_64 = F_59 ( V_64 ) ;
return V_64 ? : V_72 ;
V_86:
F_60 ( V_75 ) ;
V_83:
F_26 ( V_5 ) ;
V_67:
return V_64 ;
}
static int F_98 ( struct V_24 * V_25 , struct V_20 * V_21 ,
struct V_26 * V_27 , T_3 V_28 , int V_89 ,
int V_34 , int * V_32 )
{
T_3 V_90 = 0 ;
int V_64 = - V_80 ;
struct V_74 * V_75 ;
F_96 ( struct V_63 * , V_130 , V_27 -> V_119 ) ;
V_75 = F_62 ( V_21 , V_34 , V_89 , & V_64 ) ;
if ( ! V_75 )
goto V_67;
V_90 = V_75 -> V_28 ;
if ( V_28 < V_90 ) {
V_27 -> V_78 |= V_91 ;
V_90 = V_28 ;
}
V_64 = F_63 ( V_75 , 0 , V_27 , V_90 ) ;
if ( V_64 )
goto V_92;
F_64 ( V_27 , V_21 , V_75 ) ;
if ( V_130 ) {
V_130 -> V_65 = V_66 ;
F_99 ( & V_130 -> V_4 , & F_100 ( V_75 ) -> V_131 ) ;
* V_32 = sizeof( * V_130 ) ;
}
if ( V_34 & V_91 )
V_90 = V_75 -> V_28 ;
V_92:
F_65 ( V_21 , V_75 ) ;
V_67:
if ( V_64 )
return V_64 ;
return V_90 ;
}
static int F_101 ( struct V_20 * V_21 , struct V_74 * V_75 )
{
V_75 = F_67 ( V_75 , V_93 ) ;
if ( ! V_75 )
return V_94 ;
if ( F_68 ( V_21 , V_75 ) < 0 ) {
F_60 ( V_75 ) ;
return V_94 ;
}
return V_95 ;
}
static inline bool
F_102 ( T_5 V_132 , T_1 V_7 , T_1 V_8 ,
struct V_101 * V_104 )
{
if ( ! V_104 -> V_107 )
return true ;
if ( V_104 -> V_108 . V_11 == V_12 &&
V_132 == V_104 -> V_108 . V_13 )
return true ;
if ( V_104 -> V_108 . V_11 == V_15 &&
V_7 == V_104 -> V_108 . V_7 &&
V_8 == V_104 -> V_108 . V_8 )
return true ;
return false ;
}
static int F_103 ( struct V_1 * V_5 , struct V_74 * V_75 )
{
struct V_20 * V_21 , * V_133 = NULL ;
int V_44 = V_95 ;
T_1 V_7 , V_8 ;
T_5 V_132 ;
F_104 ( V_5 -> type != V_14 ) ;
V_7 = F_10 ( V_5 ) -> F_11 ( V_5 ) ;
V_8 = F_10 ( V_5 ) -> F_12 ( V_5 ) ;
V_132 = F_105 ( V_5 -> V_134 ) ;
F_70 ( & V_102 ) ;
F_71 (sk, &dgram_head) {
if ( F_102 ( V_132 , V_7 , V_8 ,
F_78 ( V_21 ) ) ) {
if ( V_133 ) {
struct V_74 * V_96 ;
V_96 = F_73 ( V_75 , V_93 ) ;
if ( V_96 )
F_101 ( V_133 , V_96 ) ;
}
V_133 = V_21 ;
}
}
if ( V_133 ) {
F_101 ( V_133 , V_75 ) ;
} else {
F_60 ( V_75 ) ;
V_44 = V_94 ;
}
F_75 ( & V_102 ) ;
return V_44 ;
}
static int F_106 ( struct V_20 * V_21 , int V_97 , int V_98 ,
char T_4 * V_99 , int T_4 * V_100 )
{
struct V_101 * V_104 = F_78 ( V_21 ) ;
int V_135 , V_28 ;
if ( V_97 != V_136 )
return - V_80 ;
if ( F_107 ( V_28 , V_100 ) )
return - V_46 ;
V_28 = F_108 (unsigned int, len, sizeof(int)) ;
switch ( V_98 ) {
case V_137 :
V_135 = V_104 -> V_105 ;
break;
case V_138 :
if ( ! V_104 -> V_127 )
V_135 = V_139 ;
else if ( V_104 -> V_126 )
V_135 = V_140 ;
else
V_135 = V_141 ;
break;
case V_142 :
if ( ! V_104 -> V_129 )
V_135 = V_143 ;
else
V_135 = V_104 -> V_128 ;
break;
default:
return - V_144 ;
}
if ( F_87 ( V_28 , V_100 ) )
return - V_46 ;
if ( F_25 ( V_99 , & V_135 , V_28 ) )
return - V_46 ;
return 0 ;
}
static int F_109 ( struct V_20 * V_21 , int V_97 , int V_98 ,
char T_4 * V_99 , unsigned int V_100 )
{
struct V_101 * V_104 = F_78 ( V_21 ) ;
struct V_2 * V_2 = F_23 ( V_21 ) ;
int V_135 ;
int V_64 = 0 ;
if ( V_100 < sizeof( int ) )
return - V_36 ;
if ( F_107 ( V_135 , ( int T_4 * ) V_99 ) )
return - V_46 ;
F_40 ( V_21 ) ;
switch ( V_98 ) {
case V_137 :
V_104 -> V_105 = ! ! V_135 ;
break;
case V_138 :
if ( ! F_110 ( V_2 -> V_145 , V_146 ) &&
! F_110 ( V_2 -> V_145 , V_147 ) ) {
V_64 = - V_148 ;
break;
}
switch ( V_135 ) {
case V_139 :
V_104 -> V_127 = 0 ;
break;
case V_140 :
V_104 -> V_127 = 1 ;
V_104 -> V_126 = 1 ;
break;
case V_141 :
V_104 -> V_127 = 1 ;
V_104 -> V_126 = 0 ;
break;
default:
V_64 = - V_36 ;
break;
}
break;
case V_142 :
if ( ! F_110 ( V_2 -> V_145 , V_146 ) &&
! F_110 ( V_2 -> V_145 , V_147 ) ) {
V_64 = - V_148 ;
break;
}
if ( V_135 < V_143 ||
V_135 > V_149 ) {
V_64 = - V_36 ;
} else if ( V_135 == V_143 ) {
V_104 -> V_129 = 0 ;
} else {
V_104 -> V_129 = 1 ;
V_104 -> V_128 = V_135 ;
}
break;
default:
V_64 = - V_144 ;
break;
}
F_43 ( V_21 ) ;
return V_64 ;
}
static int F_111 ( struct V_2 * V_2 , struct V_19 * V_20 ,
int V_87 , int V_150 )
{
struct V_20 * V_21 ;
int V_151 ;
struct V_152 * V_152 ;
const struct V_153 * V_154 ;
if ( ! F_112 ( V_2 , & V_155 ) )
return - V_156 ;
switch ( V_20 -> type ) {
case V_157 :
V_152 = & V_158 ;
V_154 = & V_159 ;
break;
case V_160 :
V_152 = & V_161 ;
V_154 = & V_162 ;
break;
default:
V_151 = - V_163 ;
goto V_67;
}
V_151 = - V_164 ;
V_21 = F_113 ( V_2 , V_165 , V_166 , V_152 ) ;
if ( ! V_21 )
goto V_67;
V_151 = 0 ;
V_20 -> V_154 = V_154 ;
F_114 ( V_20 , V_21 ) ;
V_21 -> V_167 = V_165 ;
F_115 ( V_21 , V_168 ) ;
if ( V_21 -> V_22 -> V_169 )
V_21 -> V_22 -> V_169 ( V_21 ) ;
if ( V_21 -> V_22 -> V_170 ) {
V_151 = V_21 -> V_22 -> V_170 ( V_21 ) ;
if ( V_151 )
F_38 ( V_21 ) ;
}
V_67:
return V_151 ;
}
static int F_116 ( struct V_74 * V_75 , struct V_1 * V_5 ,
struct V_171 * V_172 , struct V_1 * V_173 )
{
if ( ! F_117 ( V_5 ) )
goto V_174;
F_47 ( L_6 , V_5 -> type , V_5 ) ;
#ifdef F_118
F_119 ( L_7 ,
V_175 , V_75 -> V_176 , V_75 -> V_28 ) ;
#endif
if ( ! F_112 ( F_120 ( V_5 ) , & V_155 ) )
goto V_174;
F_69 ( V_5 , V_75 ) ;
if ( V_5 -> type != V_14 )
goto V_174;
if ( V_75 -> V_177 != V_178 )
return F_103 ( V_5 , V_75 ) ;
V_174:
F_60 ( V_75 ) ;
return V_94 ;
}
static int T_6 F_121 ( void )
{
int V_151 = - V_36 ;
V_151 = F_122 ( & V_158 , 1 ) ;
if ( V_151 )
goto V_67;
V_151 = F_122 ( & V_161 , 1 ) ;
if ( V_151 )
goto V_179;
V_151 = F_123 ( & V_180 ) ;
if ( V_151 )
goto V_181;
F_124 ( & V_182 ) ;
V_151 = 0 ;
goto V_67;
V_181:
F_125 ( & V_161 ) ;
V_179:
F_125 ( & V_158 ) ;
V_67:
return V_151 ;
}
static void T_7 F_126 ( void )
{
F_127 ( & V_182 ) ;
F_128 ( V_165 ) ;
F_125 ( & V_161 ) ;
F_125 ( & V_158 ) ;
}
