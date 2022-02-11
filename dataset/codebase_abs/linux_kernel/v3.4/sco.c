static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( L_1 , V_3 , V_3 -> V_4 ) ;
F_3 ( V_3 ) ;
V_3 -> V_5 = V_6 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
}
static void F_7 ( struct V_2 * V_3 , long V_8 )
{
F_2 ( L_2 , V_3 , V_3 -> V_4 , V_8 ) ;
F_8 ( V_3 , & V_3 -> V_9 , V_10 + V_8 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_2 ( L_1 , V_3 , V_3 -> V_4 ) ;
F_10 ( V_3 , & V_3 -> V_9 ) ;
}
static struct V_11 * F_11 ( struct V_12 * V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_13 -> V_16 ;
struct V_11 * V_17 = V_13 -> V_18 ;
if ( V_17 || V_14 )
return V_17 ;
V_17 = F_12 ( sizeof( struct V_11 ) , V_19 ) ;
if ( ! V_17 )
return NULL ;
F_13 ( & V_17 -> V_20 ) ;
V_13 -> V_18 = V_17 ;
V_17 -> V_13 = V_13 ;
V_17 -> V_21 = & V_16 -> V_22 ;
V_17 -> V_23 = & V_13 -> V_23 ;
if ( V_16 -> V_24 > 0 )
V_17 -> V_25 = V_16 -> V_24 ;
else
V_17 -> V_25 = 60 ;
F_2 ( L_3 , V_13 , V_17 ) ;
return V_17 ;
}
static inline struct V_2 * F_14 ( struct V_11 * V_17 )
{
struct V_2 * V_3 = NULL ;
F_15 ( V_17 ) ;
V_3 = V_17 -> V_3 ;
F_16 ( V_17 ) ;
return V_3 ;
}
static int F_17 ( struct V_12 * V_13 , int V_26 )
{
struct V_11 * V_17 = V_13 -> V_18 ;
struct V_2 * V_3 ;
if ( ! V_17 )
return 0 ;
F_2 ( L_4 , V_13 , V_17 , V_26 ) ;
V_3 = F_14 ( V_17 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_9 ( V_3 ) ;
F_18 ( V_3 , V_26 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_13 -> V_18 = NULL ;
F_19 ( V_17 ) ;
return 0 ;
}
static inline int F_20 ( struct V_11 * V_17 , struct V_2 * V_3 , struct V_2 * V_27 )
{
int V_26 = 0 ;
F_15 ( V_17 ) ;
if ( V_17 -> V_3 )
V_26 = - V_28 ;
else
F_21 ( V_17 , V_3 , V_27 ) ;
F_16 ( V_17 ) ;
return V_26 ;
}
static int F_22 ( struct V_2 * V_3 )
{
T_2 * V_21 = & F_23 ( V_3 ) -> V_21 ;
T_2 * V_23 = & F_23 ( V_3 ) -> V_23 ;
struct V_11 * V_17 ;
struct V_12 * V_13 ;
struct V_15 * V_16 ;
int V_26 , type ;
F_2 ( L_5 , F_24 ( V_21 ) , F_24 ( V_23 ) ) ;
V_16 = F_25 ( V_23 , V_21 ) ;
if ( ! V_16 )
return - V_29 ;
F_26 ( V_16 ) ;
if ( F_27 ( V_16 ) && ! V_30 )
type = V_31 ;
else
type = V_32 ;
V_13 = F_28 ( V_16 , type , V_23 , V_33 , V_34 ) ;
if ( F_29 ( V_13 ) ) {
V_26 = F_30 ( V_13 ) ;
goto V_35;
}
V_17 = F_11 ( V_13 , 0 ) ;
if ( ! V_17 ) {
F_31 ( V_13 ) ;
V_26 = - V_36 ;
goto V_35;
}
F_32 ( V_21 , V_17 -> V_21 ) ;
V_26 = F_20 ( V_17 , V_3 , NULL ) ;
if ( V_26 )
goto V_35;
if ( V_13 -> V_37 == V_38 ) {
F_9 ( V_3 ) ;
V_3 -> V_4 = V_38 ;
} else {
V_3 -> V_4 = V_39 ;
F_7 ( V_3 , V_3 -> V_40 ) ;
}
V_35:
F_33 ( V_16 ) ;
F_34 ( V_16 ) ;
return V_26 ;
}
static inline int F_35 ( struct V_2 * V_3 , struct V_41 * V_42 , int V_43 )
{
struct V_11 * V_17 = F_36 ( V_3 ) -> V_17 ;
struct V_44 * V_45 ;
int V_26 , V_46 ;
if ( V_43 > V_17 -> V_25 )
return - V_47 ;
F_2 ( L_6 , V_3 , V_43 ) ;
V_46 = F_37 (unsigned int, conn->mtu, len) ;
V_45 = F_38 ( V_3 , V_46 ,
V_42 -> V_48 & V_49 , & V_26 ) ;
if ( ! V_45 )
return V_26 ;
if ( F_39 ( F_40 ( V_45 , V_46 ) , V_42 -> V_50 , V_46 ) ) {
F_41 ( V_45 ) ;
return - V_51 ;
}
F_42 ( V_17 -> V_13 , V_45 ) ;
return V_46 ;
}
static inline void F_43 ( struct V_11 * V_17 , struct V_44 * V_45 )
{
struct V_2 * V_3 = F_14 ( V_17 ) ;
if ( ! V_3 )
goto V_52;
F_2 ( L_6 , V_3 , V_45 -> V_43 ) ;
if ( V_3 -> V_4 != V_38 )
goto V_52;
if ( ! F_44 ( V_3 , V_45 ) )
return;
V_52:
F_41 ( V_45 ) ;
}
static struct V_2 * F_45 ( T_2 * V_53 )
{
struct V_2 * V_3 ;
struct V_54 * V_55 ;
F_46 (sk, node, &sco_sk_list.head)
if ( ! F_47 ( & F_23 ( V_3 ) -> V_21 , V_53 ) )
goto V_56;
V_3 = NULL ;
V_56:
return V_3 ;
}
static struct V_2 * F_48 ( T_2 * V_21 )
{
struct V_2 * V_3 = NULL , * V_57 = NULL ;
struct V_54 * V_55 ;
F_49 ( & V_58 . V_20 ) ;
F_46 (sk, node, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_59 )
continue;
if ( ! F_47 ( & F_23 ( V_3 ) -> V_21 , V_21 ) )
break;
if ( ! F_47 ( & F_23 ( V_3 ) -> V_21 , V_60 ) )
V_57 = V_3 ;
}
F_50 ( & V_58 . V_20 ) ;
return V_55 ? V_3 : V_57 ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_2 ( L_7 , V_3 ) ;
F_52 ( & V_3 -> V_61 ) ;
F_52 ( & V_3 -> V_62 ) ;
}
static void F_53 ( struct V_2 * V_27 )
{
struct V_2 * V_3 ;
F_2 ( L_8 , V_27 ) ;
while ( ( V_3 = F_54 ( V_27 , NULL ) ) ) {
F_55 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_27 -> V_4 = V_63 ;
F_56 ( V_27 , V_64 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_57 ( V_3 , V_64 ) || V_3 -> V_65 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_4 ) ;
F_58 ( & V_58 , V_3 ) ;
F_56 ( V_3 , V_66 ) ;
F_6 ( V_3 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 , V_3 -> V_4 , V_3 -> V_65 ) ;
switch ( V_3 -> V_4 ) {
case V_59 :
F_53 ( V_3 ) ;
break;
case V_38 :
case V_67 :
if ( F_36 ( V_3 ) -> V_17 ) {
V_3 -> V_4 = V_68 ;
F_7 ( V_3 , V_69 ) ;
F_31 ( F_36 ( V_3 ) -> V_17 -> V_13 ) ;
F_36 ( V_3 ) -> V_17 -> V_13 = NULL ;
} else
F_18 ( V_3 , V_70 ) ;
break;
case V_39 :
case V_68 :
F_18 ( V_3 , V_70 ) ;
break;
default:
F_56 ( V_3 , V_64 ) ;
break;
}
}
static void F_55 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_60 ( V_3 ) ;
F_59 ( V_3 ) ;
F_61 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_62 ( struct V_2 * V_3 , struct V_2 * V_27 )
{
F_2 ( L_7 , V_3 ) ;
if ( V_27 ) {
V_3 -> V_71 = V_27 -> V_71 ;
F_63 ( V_27 , V_3 ) ;
}
}
static struct V_2 * F_64 ( struct V_72 * V_72 , struct V_73 * V_2 , int V_74 , T_3 V_75 )
{
struct V_2 * V_3 ;
V_3 = F_65 ( V_72 , V_76 , V_75 , & V_77 ) ;
if ( ! V_3 )
return NULL ;
F_66 ( V_2 , V_3 ) ;
F_67 ( & F_23 ( V_3 ) -> V_78 ) ;
V_3 -> V_79 = F_51 ;
V_3 -> V_40 = V_80 ;
F_68 ( V_3 , V_64 ) ;
V_3 -> V_81 = V_74 ;
V_3 -> V_4 = V_82 ;
F_69 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_70 ( & V_58 , V_3 ) ;
return V_3 ;
}
static int F_71 ( struct V_72 * V_72 , struct V_73 * V_2 , int V_83 ,
int V_84 )
{
struct V_2 * V_3 ;
F_2 ( L_11 , V_2 ) ;
V_2 -> V_37 = V_85 ;
if ( V_2 -> type != V_86 )
return - V_87 ;
V_2 -> V_88 = & V_89 ;
V_3 = F_64 ( V_72 , V_2 , V_83 , V_19 ) ;
if ( ! V_3 )
return - V_36 ;
F_62 ( V_3 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_73 * V_2 , struct V_90 * V_91 , int V_92 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
T_2 * V_21 = & V_94 -> V_95 ;
int V_26 = 0 ;
F_2 ( L_12 , V_3 , F_24 ( & V_94 -> V_95 ) ) ;
if ( ! V_91 || V_91 -> V_96 != V_97 )
return - V_47 ;
F_60 ( V_3 ) ;
if ( V_3 -> V_4 != V_82 ) {
V_26 = - V_98 ;
goto V_35;
}
F_73 ( & V_58 . V_20 ) ;
if ( F_47 ( V_21 , V_60 ) && F_45 ( V_21 ) ) {
V_26 = - V_99 ;
} else {
F_32 ( & F_23 ( V_3 ) -> V_21 , & V_94 -> V_95 ) ;
V_3 -> V_4 = V_100 ;
}
F_74 ( & V_58 . V_20 ) ;
V_35:
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_75 ( struct V_73 * V_2 , struct V_90 * V_91 , int V_101 , int V_102 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_101 < sizeof( struct V_93 ) ||
V_91 -> V_96 != V_97 )
return - V_47 ;
if ( V_3 -> V_4 != V_82 && V_3 -> V_4 != V_100 )
return - V_98 ;
if ( V_3 -> V_71 != V_86 )
return - V_47 ;
F_60 ( V_3 ) ;
F_32 ( & F_23 ( V_3 ) -> V_23 , & V_94 -> V_95 ) ;
V_26 = F_22 ( V_3 ) ;
if ( V_26 )
goto V_35;
V_26 = F_76 ( V_3 , V_38 ,
F_77 ( V_3 , V_102 & V_103 ) ) ;
V_35:
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_78 ( struct V_73 * V_2 , int V_104 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 = 0 ;
F_2 ( L_13 , V_3 , V_104 ) ;
F_60 ( V_3 ) ;
if ( V_3 -> V_4 != V_100 || V_2 -> type != V_86 ) {
V_26 = - V_98 ;
goto V_35;
}
V_3 -> V_105 = V_104 ;
V_3 -> V_106 = 0 ;
V_3 -> V_4 = V_59 ;
V_35:
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_79 ( struct V_73 * V_2 , struct V_73 * V_107 , int V_102 )
{
F_80 ( V_108 , V_109 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_110 ;
long V_111 ;
int V_26 = 0 ;
F_60 ( V_3 ) ;
V_111 = F_81 ( V_3 , V_102 & V_103 ) ;
F_2 ( L_14 , V_3 , V_111 ) ;
F_82 ( F_83 ( V_3 ) , & V_108 ) ;
while ( 1 ) {
F_84 ( V_112 ) ;
if ( V_3 -> V_4 != V_59 ) {
V_26 = - V_98 ;
break;
}
V_110 = F_54 ( V_3 , V_107 ) ;
if ( V_110 )
break;
if ( ! V_111 ) {
V_26 = - V_113 ;
break;
}
if ( F_85 ( V_109 ) ) {
V_26 = F_86 ( V_111 ) ;
break;
}
F_61 ( V_3 ) ;
V_111 = F_87 ( V_111 ) ;
F_60 ( V_3 ) ;
}
F_88 ( V_114 ) ;
F_89 ( F_83 ( V_3 ) , & V_108 ) ;
if ( V_26 )
goto V_35;
V_107 -> V_37 = V_115 ;
F_2 ( L_15 , V_110 ) ;
V_35:
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_90 ( struct V_73 * V_2 , struct V_90 * V_91 , int * V_43 , int V_116 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_91 -> V_96 = V_97 ;
* V_43 = sizeof( struct V_93 ) ;
if ( V_116 )
F_32 ( & V_94 -> V_95 , & F_23 ( V_3 ) -> V_23 ) ;
else
F_32 ( & V_94 -> V_95 , & F_23 ( V_3 ) -> V_21 ) ;
return 0 ;
}
static int F_91 ( struct V_117 * V_118 , struct V_73 * V_2 ,
struct V_41 * V_42 , T_4 V_43 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_26 = F_92 ( V_3 ) ;
if ( V_26 )
return V_26 ;
if ( V_42 -> V_48 & V_119 )
return - V_120 ;
F_60 ( V_3 ) ;
if ( V_3 -> V_4 == V_38 )
V_26 = F_35 ( V_3 , V_42 , V_43 ) ;
else
V_26 = - V_121 ;
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_93 ( struct V_73 * V_2 , int V_122 , int V_123 , char T_5 * V_124 , unsigned int V_125 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 = 0 ;
F_2 ( L_7 , V_3 ) ;
F_60 ( V_3 ) ;
switch ( V_123 ) {
default:
V_26 = - V_126 ;
break;
}
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_94 ( struct V_73 * V_2 , int V_123 , char T_5 * V_124 , int T_5 * V_125 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_127 V_128 ;
struct V_129 V_130 ;
int V_43 , V_26 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_95 ( V_43 , V_125 ) )
return - V_51 ;
F_60 ( V_3 ) ;
switch ( V_123 ) {
case V_131 :
if ( V_3 -> V_4 != V_38 ) {
V_26 = - V_121 ;
break;
}
V_128 . V_25 = F_36 ( V_3 ) -> V_17 -> V_25 ;
F_2 ( L_17 , V_128 . V_25 ) ;
V_43 = F_37 (unsigned int, len, sizeof(opts)) ;
if ( F_96 ( V_124 , ( char * ) & V_128 , V_43 ) )
V_26 = - V_51 ;
break;
case V_132 :
if ( V_3 -> V_4 != V_38 ) {
V_26 = - V_121 ;
break;
}
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_133 = F_36 ( V_3 ) -> V_17 -> V_13 -> V_134 ;
memcpy ( V_130 . V_135 , F_36 ( V_3 ) -> V_17 -> V_13 -> V_135 , 3 ) ;
V_43 = F_37 (unsigned int, len, sizeof(cinfo)) ;
if ( F_96 ( V_124 , ( char * ) & V_130 , V_43 ) )
V_26 = - V_51 ;
break;
default:
V_26 = - V_126 ;
break;
}
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_97 ( struct V_73 * V_2 , int V_122 , int V_123 , char T_5 * V_124 , int T_5 * V_125 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_26 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_122 == V_136 )
return F_94 ( V_2 , V_123 , V_124 , V_125 ) ;
if ( F_95 ( V_43 , V_125 ) )
return - V_51 ;
F_60 ( V_3 ) ;
switch ( V_123 ) {
default:
V_26 = - V_126 ;
break;
}
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_98 ( struct V_73 * V_2 , int V_137 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_60 ( V_3 ) ;
if ( ! V_3 -> V_138 ) {
V_3 -> V_138 = V_139 ;
F_9 ( V_3 ) ;
F_59 ( V_3 ) ;
if ( F_57 ( V_3 , V_140 ) && V_3 -> V_141 )
V_26 = F_76 ( V_3 , V_63 ,
V_3 -> V_141 ) ;
}
F_61 ( V_3 ) ;
return V_26 ;
}
static int F_99 ( struct V_73 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_26 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_55 ( V_3 ) ;
if ( F_57 ( V_3 , V_140 ) && V_3 -> V_141 ) {
F_60 ( V_3 ) ;
V_26 = F_76 ( V_3 , V_63 , V_3 -> V_141 ) ;
F_61 ( V_3 ) ;
}
F_100 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_26 ;
}
static void F_21 ( struct V_11 * V_17 , struct V_2 * V_3 , struct V_2 * V_27 )
{
F_2 ( L_18 , V_17 ) ;
F_36 ( V_3 ) -> V_17 = V_17 ;
V_17 -> V_3 = V_3 ;
if ( V_27 )
F_101 ( V_27 , V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_26 )
{
struct V_11 * V_17 ;
V_17 = F_36 ( V_3 ) -> V_17 ;
F_2 ( L_19 , V_3 , V_17 , V_26 ) ;
if ( V_17 ) {
F_15 ( V_17 ) ;
V_17 -> V_3 = NULL ;
F_36 ( V_3 ) -> V_17 = NULL ;
F_16 ( V_17 ) ;
if ( V_17 -> V_13 )
F_31 ( V_17 -> V_13 ) ;
}
V_3 -> V_4 = V_63 ;
V_3 -> V_5 = V_26 ;
V_3 -> V_7 ( V_3 ) ;
F_56 ( V_3 , V_64 ) ;
}
static void F_102 ( struct V_11 * V_17 )
{
struct V_2 * V_27 ;
struct V_2 * V_3 = V_17 -> V_3 ;
F_2 ( L_18 , V_17 ) ;
F_15 ( V_17 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_38 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
V_27 = F_48 ( V_17 -> V_21 ) ;
if ( ! V_27 )
goto V_35;
F_3 ( V_27 ) ;
V_3 = F_64 ( F_103 ( V_27 ) , NULL ,
V_142 , V_19 ) ;
if ( ! V_3 ) {
F_4 ( V_27 ) ;
goto V_35;
}
F_62 ( V_3 , V_27 ) ;
F_32 ( & F_23 ( V_3 ) -> V_21 , V_17 -> V_21 ) ;
F_32 ( & F_23 ( V_3 ) -> V_23 , V_17 -> V_23 ) ;
F_104 ( V_17 -> V_13 ) ;
F_21 ( V_17 , V_3 , V_27 ) ;
V_3 -> V_4 = V_38 ;
V_27 -> V_143 ( V_27 , 1 ) ;
F_4 ( V_27 ) ;
}
V_35:
F_16 ( V_17 ) ;
}
int F_105 ( struct V_15 * V_16 , T_2 * V_22 )
{
register struct V_2 * V_3 ;
struct V_54 * V_55 ;
int V_144 = 0 ;
F_2 ( L_20 , V_16 -> V_145 , F_24 ( V_22 ) ) ;
F_49 ( & V_58 . V_20 ) ;
F_46 (sk, node, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_59 )
continue;
if ( ! F_47 ( & F_23 ( V_3 ) -> V_21 , & V_16 -> V_22 ) ||
! F_47 ( & F_23 ( V_3 ) -> V_21 , V_60 ) ) {
V_144 |= V_146 ;
break;
}
}
F_50 ( & V_58 . V_20 ) ;
return V_144 ;
}
int F_106 ( struct V_12 * V_13 , T_1 V_14 )
{
F_2 ( L_21 , V_13 , F_24 ( & V_13 -> V_23 ) , V_14 ) ;
if ( ! V_14 ) {
struct V_11 * V_17 ;
V_17 = F_11 ( V_13 , V_14 ) ;
if ( V_17 )
F_102 ( V_17 ) ;
} else
F_17 ( V_13 , F_107 ( V_14 ) ) ;
return 0 ;
}
int F_108 ( struct V_12 * V_13 , T_1 V_147 )
{
F_2 ( L_22 , V_13 , V_147 ) ;
F_17 ( V_13 , F_107 ( V_147 ) ) ;
return 0 ;
}
int F_109 ( struct V_12 * V_13 , struct V_44 * V_45 )
{
struct V_11 * V_17 = V_13 -> V_18 ;
if ( ! V_17 )
goto V_52;
F_2 ( L_23 , V_17 , V_45 -> V_43 ) ;
if ( V_45 -> V_43 ) {
F_43 ( V_17 , V_45 ) ;
return 0 ;
}
V_52:
F_41 ( V_45 ) ;
return 0 ;
}
static int F_110 ( struct V_148 * V_149 , void * V_150 )
{
struct V_2 * V_3 ;
struct V_54 * V_55 ;
F_49 ( & V_58 . V_20 ) ;
F_46 (sk, node, &sco_sk_list.head) {
F_111 ( V_149 , L_24 , F_24 ( & F_23 ( V_3 ) -> V_21 ) ,
F_24 ( & F_23 ( V_3 ) -> V_23 ) , V_3 -> V_4 ) ;
}
F_50 ( & V_58 . V_20 ) ;
return 0 ;
}
static int F_112 ( struct V_151 * V_151 , struct V_152 * V_152 )
{
return F_113 ( V_152 , F_110 , V_151 -> V_153 ) ;
}
int T_6 F_114 ( void )
{
int V_26 ;
V_26 = F_115 ( & V_77 , 0 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_116 ( V_142 , & V_154 ) ;
if ( V_26 < 0 ) {
F_117 ( L_25 ) ;
goto error;
}
if ( V_155 ) {
V_156 = F_118 ( L_26 , 0444 ,
V_155 , NULL , & V_157 ) ;
if ( ! V_156 )
F_117 ( L_27 ) ;
}
F_119 ( L_28 ) ;
return 0 ;
error:
F_120 ( & V_77 ) ;
return V_26 ;
}
void T_7 F_121 ( void )
{
F_122 ( V_156 ) ;
if ( F_123 ( V_142 ) < 0 )
F_117 ( L_29 ) ;
F_120 ( & V_77 ) ;
}
