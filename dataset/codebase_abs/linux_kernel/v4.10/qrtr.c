static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
F_2 ( F_3 ( struct V_1 , V_3 ) != 0 ) ;
return F_4 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_5 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 , struct V_5 , V_7 ) ;
if ( V_6 -> V_8 != V_9 )
F_6 ( & V_10 , V_6 -> V_8 ) ;
F_7 ( & V_6 -> V_11 ) ;
F_8 ( & V_12 ) ;
F_9 ( & V_6 -> V_13 ) ;
F_10 ( V_6 ) ;
}
static struct V_5 * F_11 ( struct V_5 * V_6 )
{
if ( V_6 )
F_12 ( & V_6 -> V_7 ) ;
return V_6 ;
}
static void F_13 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_14 ( & V_6 -> V_7 , F_5 , & V_12 ) ;
}
static int F_15 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
int V_16 = - V_17 ;
F_16 ( & V_6 -> V_18 ) ;
if ( V_6 -> V_19 )
V_16 = V_6 -> V_19 -> V_20 ( V_6 -> V_19 , V_15 ) ;
else
F_17 ( V_15 ) ;
F_8 ( & V_6 -> V_18 ) ;
return V_16 ;
}
static struct V_5 * F_18 ( unsigned int V_8 )
{
struct V_5 * V_6 ;
F_16 ( & V_12 ) ;
V_6 = F_19 ( & V_10 , V_8 ) ;
V_6 = F_11 ( V_6 ) ;
F_8 ( & V_12 ) ;
return V_6 ;
}
static void F_20 ( struct V_5 * V_6 , unsigned int V_8 )
{
if ( V_6 -> V_8 != V_9 || V_8 == V_9 )
return;
F_16 ( & V_12 ) ;
F_21 ( & V_10 , V_8 , V_6 ) ;
V_6 -> V_8 = V_8 ;
F_8 ( & V_12 ) ;
}
int F_22 ( struct V_21 * V_19 , const void * V_22 , T_1 V_23 )
{
struct V_5 * V_6 = V_19 -> V_6 ;
const struct V_24 * V_25 = V_22 ;
struct V_14 * V_15 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int type ;
unsigned int V_28 ;
unsigned int V_29 ;
if ( V_23 < V_30 || V_23 & 3 )
return - V_31 ;
V_28 = F_23 ( V_25 -> V_32 ) ;
V_27 = F_23 ( V_25 -> V_27 ) ;
type = F_23 ( V_25 -> type ) ;
V_29 = F_23 ( V_25 -> V_33 ) ;
V_26 = ( V_27 + 3 ) & ~ 3 ;
if ( V_28 != V_34 )
return - V_31 ;
if ( V_23 != V_26 + V_30 )
return - V_31 ;
if ( V_29 != V_35 && type != V_36 )
return - V_31 ;
V_15 = F_24 ( NULL , V_23 ) ;
if ( ! V_15 )
return - V_37 ;
F_25 ( V_15 ) ;
memcpy ( F_26 ( V_15 , V_23 ) , V_22 , V_23 ) ;
F_27 ( & V_6 -> V_13 , V_15 ) ;
F_28 ( & V_6 -> V_38 ) ;
return 0 ;
}
static struct V_14 * F_29 ( T_2 V_39 ,
T_2 V_40 , T_2 V_41 )
{
const int V_42 = 20 ;
struct V_24 * V_43 ;
struct V_14 * V_15 ;
T_3 * V_44 ;
V_15 = F_30 ( V_30 + V_42 , V_45 ) ;
if ( ! V_15 )
return NULL ;
F_25 ( V_15 ) ;
V_43 = (struct V_24 * ) F_26 ( V_15 , V_30 ) ;
V_43 -> V_32 = F_31 ( V_34 ) ;
V_43 -> type = F_31 ( V_46 ) ;
V_43 -> V_47 = F_31 ( V_39 ) ;
V_43 -> V_48 = F_31 ( V_35 ) ;
V_43 -> V_49 = F_31 ( 0 ) ;
V_43 -> V_27 = F_31 ( V_42 ) ;
V_43 -> V_50 = F_31 ( V_40 ) ;
V_43 -> V_33 = F_31 ( V_35 ) ;
V_44 = ( T_3 * ) F_26 ( V_15 , V_42 ) ;
memset ( V_44 , 0 , V_42 ) ;
V_44 [ 0 ] = F_31 ( V_46 ) ;
V_44 [ 1 ] = F_31 ( V_39 ) ;
V_44 [ 2 ] = F_31 ( V_41 ) ;
return V_15 ;
}
static void F_32 ( struct V_51 * V_38 )
{
struct V_5 * V_6 = F_4 ( V_38 , struct V_5 , V_38 ) ;
struct V_14 * V_15 ;
while ( ( V_15 = F_33 ( & V_6 -> V_13 ) ) != NULL ) {
const struct V_24 * V_25 ;
T_2 V_40 , V_52 ;
struct V_1 * V_53 ;
T_2 V_39 ;
int V_54 ;
V_25 = ( const struct V_24 * ) F_34 ( V_15 ) ;
V_39 = F_23 ( V_25 -> V_47 ) ;
V_40 = F_23 ( V_25 -> V_50 ) ;
V_52 = F_23 ( V_25 -> V_33 ) ;
V_54 = ! ! V_25 -> V_49 ;
F_20 ( V_6 , V_39 ) ;
V_53 = F_35 ( V_52 ) ;
if ( ! V_53 ) {
F_17 ( V_15 ) ;
} else {
if ( F_36 ( & V_53 -> V_3 , V_15 ) )
F_17 ( V_15 ) ;
F_37 ( V_53 ) ;
}
if ( V_54 ) {
V_15 = F_29 ( V_40 , V_6 -> V_8 , V_52 ) ;
if ( ! V_15 )
break;
if ( F_15 ( V_6 , V_15 ) )
break;
}
}
}
int F_38 ( struct V_21 * V_19 , unsigned int V_8 )
{
struct V_5 * V_6 ;
if ( ! V_19 || ! V_19 -> V_20 )
return - V_31 ;
V_6 = F_39 ( sizeof( * V_6 ) , V_45 ) ;
if ( ! V_6 )
return - V_37 ;
F_40 ( & V_6 -> V_38 , F_32 ) ;
F_41 ( & V_6 -> V_7 ) ;
F_42 ( & V_6 -> V_18 ) ;
F_43 ( & V_6 -> V_13 ) ;
V_6 -> V_8 = V_9 ;
V_6 -> V_19 = V_19 ;
F_20 ( V_6 , V_8 ) ;
F_16 ( & V_12 ) ;
F_44 ( & V_6 -> V_11 , & V_55 ) ;
F_8 ( & V_12 ) ;
V_19 -> V_6 = V_6 ;
return 0 ;
}
void F_45 ( struct V_21 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_6 ;
F_16 ( & V_6 -> V_18 ) ;
V_6 -> V_19 = NULL ;
F_8 ( & V_6 -> V_18 ) ;
F_13 ( V_6 ) ;
V_19 -> V_6 = NULL ;
}
static struct V_1 * F_35 ( int V_41 )
{
struct V_1 * V_53 ;
if ( V_41 == V_35 )
V_41 = 0 ;
F_16 ( & V_56 ) ;
V_53 = F_46 ( & V_57 , V_41 ) ;
if ( V_53 )
F_47 ( & V_53 -> V_3 ) ;
F_8 ( & V_56 ) ;
return V_53 ;
}
static void F_37 ( struct V_1 * V_53 )
{
F_48 ( & V_53 -> V_3 ) ;
}
static void F_49 ( struct V_1 * V_53 )
{
int V_41 = V_53 -> V_58 . V_59 ;
if ( V_41 == V_35 )
V_41 = 0 ;
F_50 ( & V_53 -> V_3 ) ;
F_16 ( & V_56 ) ;
F_51 ( & V_57 , V_41 ) ;
F_8 ( & V_56 ) ;
}
static int F_52 ( struct V_1 * V_53 , int * V_41 )
{
int V_16 ;
F_16 ( & V_56 ) ;
if ( ! * V_41 ) {
V_16 = F_53 ( & V_57 , V_53 ,
V_60 , V_61 + 1 ,
V_62 ) ;
if ( V_16 >= 0 )
* V_41 = V_16 ;
} else if ( * V_41 < V_60 && ! F_54 ( V_63 ) ) {
V_16 = - V_64 ;
} else if ( * V_41 == V_35 ) {
V_16 = F_53 ( & V_57 , V_53 , 0 , 1 , V_62 ) ;
} else {
V_16 = F_53 ( & V_57 , V_53 , * V_41 , * V_41 + 1 , V_62 ) ;
if ( V_16 >= 0 )
* V_41 = V_16 ;
}
F_8 ( & V_56 ) ;
if ( V_16 == - V_65 )
return - V_66 ;
else if ( V_16 < 0 )
return V_16 ;
F_47 ( & V_53 -> V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_67 * V_2 ,
const struct V_68 * V_69 , int V_70 )
{
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_41 ;
int V_16 ;
if ( ! V_70 && V_69 -> V_59 == V_53 -> V_58 . V_59 )
return 0 ;
V_41 = V_69 -> V_59 ;
V_16 = F_52 ( V_53 , & V_41 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_70 )
F_49 ( V_53 ) ;
V_53 -> V_58 . V_59 = V_41 ;
F_56 ( V_3 , V_71 ) ;
return 0 ;
}
static int F_57 ( struct V_67 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_68 V_69 ;
if ( ! F_58 ( V_3 , V_71 ) )
return 0 ;
V_69 . V_72 = V_73 ;
V_69 . V_74 = V_75 ;
V_69 . V_59 = 0 ;
return F_55 ( V_2 , & V_69 , 1 ) ;
}
static int F_59 ( struct V_67 * V_2 , struct V_76 * V_77 , int V_23 )
{
F_60 ( struct V_68 * , V_69 , V_77 ) ;
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_16 ;
if ( V_23 < sizeof( * V_69 ) || V_69 -> V_72 != V_73 )
return - V_31 ;
if ( V_69 -> V_74 != V_53 -> V_58 . V_74 )
return - V_31 ;
F_61 ( V_3 ) ;
V_16 = F_55 ( V_2 , V_69 , F_58 ( V_3 , V_71 ) ) ;
F_62 ( V_3 ) ;
return V_16 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
const struct V_24 * V_25 ;
struct V_1 * V_53 ;
V_25 = ( const struct V_24 * ) F_34 ( V_15 ) ;
V_53 = F_35 ( F_23 ( V_25 -> V_33 ) ) ;
if ( ! V_53 || & V_53 -> V_3 == V_15 -> V_3 ) {
F_17 ( V_15 ) ;
return - V_17 ;
}
if ( F_36 ( & V_53 -> V_3 , V_15 ) ) {
F_37 ( V_53 ) ;
F_17 ( V_15 ) ;
return - V_65 ;
}
F_37 ( V_53 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_14 * V_78 ;
F_16 ( & V_12 ) ;
F_65 (node, &qrtr_all_nodes, item) {
V_78 = F_66 ( V_15 , V_45 ) ;
if ( ! V_78 )
break;
F_67 ( V_78 , V_15 -> V_3 ) ;
F_15 ( V_6 , V_78 ) ;
}
F_8 ( & V_12 ) ;
F_63 ( V_6 , V_15 ) ;
return 0 ;
}
static int F_68 ( struct V_67 * V_2 , struct V_79 * V_80 , T_1 V_23 )
{
F_60 ( struct V_68 * , V_69 , V_80 -> V_81 ) ;
int (* F_69)( struct V_5 * , struct V_14 * );
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_5 * V_6 ;
struct V_24 * V_43 ;
struct V_14 * V_15 ;
T_1 V_82 ;
int V_16 ;
if ( V_80 -> V_83 & ~ ( V_84 ) )
return - V_31 ;
if ( V_23 > 65535 )
return - V_85 ;
F_61 ( V_3 ) ;
if ( V_69 ) {
if ( V_80 -> V_86 < sizeof( * V_69 ) ) {
F_62 ( V_3 ) ;
return - V_31 ;
}
if ( V_69 -> V_72 != V_73 ) {
F_62 ( V_3 ) ;
return - V_31 ;
}
V_16 = F_57 ( V_2 ) ;
if ( V_16 ) {
F_62 ( V_3 ) ;
return V_16 ;
}
} else if ( V_3 -> V_87 == V_88 ) {
V_69 = & V_53 -> V_89 ;
} else {
F_62 ( V_3 ) ;
return - V_90 ;
}
V_6 = NULL ;
if ( V_69 -> V_74 == V_91 ) {
F_69 = F_64 ;
} else if ( V_69 -> V_74 == V_53 -> V_58 . V_74 ) {
F_69 = F_63 ;
} else {
F_69 = F_15 ;
V_6 = F_18 ( V_69 -> V_74 ) ;
if ( ! V_6 ) {
F_62 ( V_3 ) ;
return - V_92 ;
}
}
V_82 = ( V_23 + 3 ) & ~ 3 ;
V_15 = F_70 ( V_3 , V_82 + V_30 ,
V_80 -> V_83 & V_84 , & V_16 ) ;
if ( ! V_15 )
goto V_93;
F_25 ( V_15 ) ;
F_26 ( V_15 , V_23 + V_30 ) ;
V_43 = (struct V_24 * ) F_34 ( V_15 ) ;
V_43 -> V_32 = F_31 ( V_34 ) ;
V_43 -> V_47 = F_31 ( V_53 -> V_58 . V_74 ) ;
V_43 -> V_48 = F_31 ( V_53 -> V_58 . V_59 ) ;
V_43 -> V_49 = F_31 ( 0 ) ;
V_43 -> V_27 = F_31 ( V_23 ) ;
V_43 -> V_50 = F_31 ( V_69 -> V_74 ) ;
V_43 -> V_33 = F_31 ( V_69 -> V_59 ) ;
V_16 = F_71 ( V_15 , V_30 ,
& V_80 -> V_94 , V_23 ) ;
if ( V_16 ) {
F_17 ( V_15 ) ;
goto V_93;
}
if ( V_82 != V_23 ) {
F_72 ( V_15 , V_82 - V_23 ) ;
F_26 ( V_15 , V_82 - V_23 ) ;
}
if ( V_53 -> V_58 . V_59 == V_35 ) {
if ( V_23 < 4 ) {
V_16 = - V_31 ;
F_17 ( V_15 ) ;
goto V_93;
}
F_73 ( V_15 , V_30 , & V_43 -> type , 4 ) ;
} else {
V_43 -> type = F_31 ( V_36 ) ;
}
V_16 = F_69 ( V_6 , V_15 ) ;
if ( V_16 >= 0 )
V_16 = V_23 ;
V_93:
F_13 ( V_6 ) ;
F_62 ( V_3 ) ;
return V_16 ;
}
static int F_74 ( struct V_67 * V_2 , struct V_79 * V_80 ,
T_1 V_27 , int V_95 )
{
F_60 ( struct V_68 * , V_69 , V_80 -> V_81 ) ;
const struct V_24 * V_25 ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_14 * V_15 ;
int V_96 , V_16 ;
F_61 ( V_3 ) ;
if ( F_58 ( V_3 , V_71 ) ) {
F_62 ( V_3 ) ;
return - V_97 ;
}
V_15 = F_75 ( V_3 , V_95 & ~ V_84 ,
V_95 & V_84 , & V_16 ) ;
if ( ! V_15 ) {
F_62 ( V_3 ) ;
return V_16 ;
}
V_25 = ( const struct V_24 * ) F_34 ( V_15 ) ;
V_96 = F_23 ( V_25 -> V_27 ) ;
if ( V_96 > V_27 ) {
V_96 = V_27 ;
V_80 -> V_83 |= V_98 ;
}
V_16 = F_76 ( V_15 , V_30 , V_80 , V_96 ) ;
if ( V_16 < 0 )
goto V_99;
V_16 = V_96 ;
if ( V_69 ) {
V_69 -> V_72 = V_73 ;
V_69 -> V_74 = F_23 ( V_25 -> V_47 ) ;
V_69 -> V_59 = F_23 ( V_25 -> V_48 ) ;
V_80 -> V_86 = sizeof( * V_69 ) ;
}
V_99:
F_77 ( V_3 , V_15 ) ;
F_62 ( V_3 ) ;
return V_16 ;
}
static int F_78 ( struct V_67 * V_2 , struct V_76 * V_77 ,
int V_23 , int V_95 )
{
F_60 ( struct V_68 * , V_69 , V_77 ) ;
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_16 ;
if ( V_23 < sizeof( * V_69 ) || V_69 -> V_72 != V_73 )
return - V_31 ;
F_61 ( V_3 ) ;
V_3 -> V_87 = V_100 ;
V_2 -> V_101 = V_102 ;
V_16 = F_57 ( V_2 ) ;
if ( V_16 ) {
F_62 ( V_3 ) ;
return V_16 ;
}
V_53 -> V_89 = * V_69 ;
V_2 -> V_101 = V_103 ;
V_3 -> V_87 = V_88 ;
F_62 ( V_3 ) ;
return 0 ;
}
static int F_79 ( struct V_67 * V_2 , struct V_76 * V_77 ,
int * V_23 , int V_89 )
{
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_68 V_104 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_61 ( V_3 ) ;
if ( V_89 ) {
if ( V_3 -> V_87 != V_88 ) {
F_62 ( V_3 ) ;
return - V_90 ;
}
V_104 = V_53 -> V_89 ;
} else {
V_104 = V_53 -> V_58 ;
}
F_62 ( V_3 ) ;
* V_23 = sizeof( V_104 ) ;
V_104 . V_72 = V_73 ;
memcpy ( V_77 , & V_104 , sizeof( V_104 ) ) ;
return 0 ;
}
static int F_80 ( struct V_67 * V_2 , unsigned int V_105 , unsigned long V_106 )
{
void T_4 * V_107 = ( void T_4 * ) V_106 ;
struct V_1 * V_53 = F_1 ( V_2 -> V_3 ) ;
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_68 * V_108 ;
struct V_14 * V_15 ;
struct V_109 V_110 ;
long V_23 = 0 ;
int V_16 = 0 ;
F_61 ( V_3 ) ;
switch ( V_105 ) {
case V_111 :
V_23 = V_3 -> V_112 - F_81 ( V_3 ) ;
if ( V_23 < 0 )
V_23 = 0 ;
V_16 = F_82 ( V_23 , ( int T_4 * ) V_107 ) ;
break;
case V_113 :
V_15 = F_83 ( & V_3 -> V_114 ) ;
if ( V_15 )
V_23 = V_15 -> V_23 - V_30 ;
V_16 = F_82 ( V_23 , ( int T_4 * ) V_107 ) ;
break;
case V_115 :
if ( F_84 ( & V_110 , V_107 , sizeof( V_110 ) ) ) {
V_16 = - V_116 ;
break;
}
V_108 = (struct V_68 * ) & V_110 . V_117 ;
* V_108 = V_53 -> V_58 ;
if ( F_85 ( V_107 , & V_110 , sizeof( V_110 ) ) ) {
V_16 = - V_116 ;
break;
}
break;
case V_118 :
V_16 = F_86 ( V_3 , V_107 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_16 = - V_31 ;
break;
default:
V_16 = - V_128 ;
break;
}
F_62 ( V_3 ) ;
return V_16 ;
}
static int F_87 ( struct V_67 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_1 * V_53 ;
if ( ! V_3 )
return 0 ;
F_61 ( V_3 ) ;
V_53 = F_1 ( V_3 ) ;
V_3 -> V_129 = V_130 ;
if ( ! F_58 ( V_3 , V_131 ) )
V_3 -> V_132 ( V_3 ) ;
F_88 ( V_3 , V_131 ) ;
V_2 -> V_3 = NULL ;
if ( ! F_58 ( V_3 , V_71 ) )
F_49 ( V_53 ) ;
F_9 ( & V_3 -> V_114 ) ;
F_62 ( V_3 ) ;
F_48 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_133 * V_133 , struct V_67 * V_2 ,
int V_134 , int V_135 )
{
struct V_1 * V_53 ;
struct V_2 * V_3 ;
if ( V_2 -> type != V_136 )
return - V_137 ;
V_3 = F_90 ( V_133 , V_73 , V_45 , & V_138 , V_135 ) ;
if ( ! V_3 )
return - V_37 ;
F_88 ( V_3 , V_71 ) ;
F_91 ( V_2 , V_3 ) ;
V_2 -> V_139 = & V_140 ;
V_53 = F_1 ( V_3 ) ;
V_53 -> V_58 . V_72 = V_73 ;
V_53 -> V_58 . V_74 = V_75 ;
V_53 -> V_58 . V_59 = 0 ;
return 0 ;
}
static int F_92 ( struct V_14 * V_15 , struct V_141 * V_142 )
{
struct V_143 * V_144 [ V_145 + 1 ] ;
struct V_146 * V_147 ;
int V_16 ;
if ( ! F_93 ( V_15 , V_63 ) )
return - V_148 ;
if ( ! F_93 ( V_15 , V_149 ) )
return - V_148 ;
F_94 () ;
V_16 = F_95 ( V_142 , sizeof( * V_147 ) , V_144 , V_145 , V_150 ) ;
if ( V_16 < 0 )
return V_16 ;
V_147 = F_96 ( V_142 ) ;
if ( ! V_144 [ V_151 ] )
return - V_31 ;
V_75 = F_97 ( V_144 [ V_151 ] ) ;
return 0 ;
}
static int T_5 F_98 ( void )
{
int V_16 ;
V_16 = F_99 ( & V_138 , 1 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_100 ( & V_152 ) ;
if ( V_16 ) {
F_101 ( & V_138 ) ;
return V_16 ;
}
F_102 ( V_153 , V_154 , F_92 , NULL , NULL ) ;
return 0 ;
}
static void T_6 F_103 ( void )
{
F_104 ( V_153 , V_154 ) ;
F_105 ( V_152 . V_155 ) ;
F_101 ( & V_138 ) ;
}
