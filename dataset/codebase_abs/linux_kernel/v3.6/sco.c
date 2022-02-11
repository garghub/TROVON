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
static struct V_11 * F_11 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_11 * V_16 = V_13 -> V_17 ;
if ( V_16 )
return V_16 ;
V_16 = F_12 ( sizeof( struct V_11 ) , V_18 ) ;
if ( ! V_16 )
return NULL ;
F_13 ( & V_16 -> V_19 ) ;
V_13 -> V_17 = V_16 ;
V_16 -> V_13 = V_13 ;
V_16 -> V_20 = & V_15 -> V_21 ;
V_16 -> V_22 = & V_13 -> V_22 ;
if ( V_15 -> V_23 > 0 )
V_16 -> V_24 = V_15 -> V_23 ;
else
V_16 -> V_24 = 60 ;
F_2 ( L_3 , V_13 , V_16 ) ;
return V_16 ;
}
static struct V_2 * F_14 ( struct V_11 * V_16 )
{
struct V_2 * V_3 = NULL ;
F_15 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
F_16 ( V_16 ) ;
return V_3 ;
}
static int F_17 ( struct V_12 * V_13 , int V_25 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
struct V_2 * V_3 ;
if ( ! V_16 )
return 0 ;
F_2 ( L_4 , V_13 , V_16 , V_25 ) ;
V_3 = F_14 ( V_16 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_9 ( V_3 ) ;
F_18 ( V_3 , V_25 ) ;
F_4 ( V_3 ) ;
F_15 ( V_16 ) ;
V_16 -> V_3 = NULL ;
F_19 ( V_3 ) -> V_16 = NULL ;
F_16 ( V_16 ) ;
if ( V_16 -> V_13 )
F_20 ( V_16 -> V_13 ) ;
F_5 ( V_3 ) ;
}
V_13 -> V_17 = NULL ;
F_21 ( V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_26 )
{
int V_25 = 0 ;
F_15 ( V_16 ) ;
if ( V_16 -> V_3 )
V_25 = - V_27 ;
else
F_23 ( V_16 , V_3 , V_26 ) ;
F_16 ( V_16 ) ;
return V_25 ;
}
static int F_24 ( struct V_2 * V_3 )
{
T_1 * V_20 = & F_25 ( V_3 ) -> V_20 ;
T_1 * V_22 = & F_25 ( V_3 ) -> V_22 ;
struct V_11 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_25 , type ;
F_2 ( L_5 , F_26 ( V_20 ) , F_26 ( V_22 ) ) ;
V_15 = F_27 ( V_22 , V_20 ) ;
if ( ! V_15 )
return - V_28 ;
F_28 ( V_15 ) ;
if ( F_29 ( V_15 ) && ! V_29 )
type = V_30 ;
else
type = V_31 ;
V_13 = F_30 ( V_15 , type , V_22 , V_32 , V_33 ,
V_34 ) ;
if ( F_31 ( V_13 ) ) {
V_25 = F_32 ( V_13 ) ;
goto V_35;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_20 ( V_13 ) ;
V_25 = - V_36 ;
goto V_35;
}
F_33 ( V_20 , V_16 -> V_20 ) ;
V_25 = F_22 ( V_16 , V_3 , NULL ) ;
if ( V_25 )
goto V_35;
if ( V_13 -> V_37 == V_38 ) {
F_9 ( V_3 ) ;
V_3 -> V_4 = V_38 ;
} else {
V_3 -> V_4 = V_39 ;
F_7 ( V_3 , V_3 -> V_40 ) ;
}
V_35:
F_34 ( V_15 ) ;
F_35 ( V_15 ) ;
return V_25 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_41 * V_42 , int V_43 )
{
struct V_11 * V_16 = F_19 ( V_3 ) -> V_16 ;
struct V_44 * V_45 ;
int V_25 ;
if ( V_43 > V_16 -> V_24 )
return - V_46 ;
F_2 ( L_6 , V_3 , V_43 ) ;
V_45 = F_37 ( V_3 , V_43 , V_42 -> V_47 & V_48 , & V_25 ) ;
if ( ! V_45 )
return V_25 ;
if ( F_38 ( F_39 ( V_45 , V_43 ) , V_42 -> V_49 , V_43 ) ) {
F_40 ( V_45 ) ;
return - V_50 ;
}
F_41 ( V_16 -> V_13 , V_45 ) ;
return V_43 ;
}
static void F_42 ( struct V_11 * V_16 , struct V_44 * V_45 )
{
struct V_2 * V_3 = F_14 ( V_16 ) ;
if ( ! V_3 )
goto V_51;
F_2 ( L_6 , V_3 , V_45 -> V_43 ) ;
if ( V_3 -> V_4 != V_38 )
goto V_51;
if ( ! F_43 ( V_3 , V_45 ) )
return;
V_51:
F_40 ( V_45 ) ;
}
static struct V_2 * F_44 ( T_1 * V_52 )
{
struct V_53 * V_54 ;
struct V_2 * V_3 ;
F_45 (sk, node, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_55 )
continue;
if ( ! F_46 ( & F_25 ( V_3 ) -> V_20 , V_52 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_47 ( T_1 * V_20 )
{
struct V_2 * V_3 = NULL , * V_56 = NULL ;
struct V_53 * V_54 ;
F_48 ( & V_57 . V_19 ) ;
F_45 (sk, node, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_55 )
continue;
if ( ! F_46 ( & F_25 ( V_3 ) -> V_20 , V_20 ) )
break;
if ( ! F_46 ( & F_25 ( V_3 ) -> V_20 , V_58 ) )
V_56 = V_3 ;
}
F_49 ( & V_57 . V_19 ) ;
return V_54 ? V_3 : V_56 ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_2 ( L_7 , V_3 ) ;
F_51 ( & V_3 -> V_59 ) ;
F_51 ( & V_3 -> V_60 ) ;
}
static void F_52 ( struct V_2 * V_26 )
{
struct V_2 * V_3 ;
F_2 ( L_8 , V_26 ) ;
while ( ( V_3 = F_53 ( V_26 , NULL ) ) ) {
F_54 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_26 -> V_4 = V_61 ;
F_55 ( V_26 , V_62 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_56 ( V_3 , V_62 ) || V_3 -> V_63 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_4 ) ;
F_57 ( & V_57 , V_3 ) ;
F_55 ( V_3 , V_64 ) ;
F_6 ( V_3 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 , V_3 -> V_4 , V_3 -> V_63 ) ;
switch ( V_3 -> V_4 ) {
case V_55 :
F_52 ( V_3 ) ;
break;
case V_38 :
case V_65 :
if ( F_19 ( V_3 ) -> V_16 ) {
V_3 -> V_4 = V_66 ;
F_7 ( V_3 , V_67 ) ;
F_20 ( F_19 ( V_3 ) -> V_16 -> V_13 ) ;
F_19 ( V_3 ) -> V_16 -> V_13 = NULL ;
} else
F_18 ( V_3 , V_68 ) ;
break;
case V_39 :
case V_66 :
F_18 ( V_3 , V_68 ) ;
break;
default:
F_55 ( V_3 , V_62 ) ;
break;
}
}
static void F_54 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_59 ( V_3 ) ;
F_58 ( V_3 ) ;
F_60 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_61 ( struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_7 , V_3 ) ;
if ( V_26 ) {
V_3 -> V_69 = V_26 -> V_69 ;
F_62 ( V_26 , V_3 ) ;
}
}
static struct V_2 * F_63 ( struct V_70 * V_70 , struct V_71 * V_2 , int V_72 , T_2 V_73 )
{
struct V_2 * V_3 ;
V_3 = F_64 ( V_70 , V_74 , V_73 , & V_75 ) ;
if ( ! V_3 )
return NULL ;
F_65 ( V_2 , V_3 ) ;
F_66 ( & F_25 ( V_3 ) -> V_76 ) ;
V_3 -> V_77 = F_50 ;
V_3 -> V_40 = V_78 ;
F_67 ( V_3 , V_62 ) ;
V_3 -> V_79 = V_72 ;
V_3 -> V_4 = V_80 ;
F_68 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_69 ( & V_57 , V_3 ) ;
return V_3 ;
}
static int F_70 ( struct V_70 * V_70 , struct V_71 * V_2 , int V_81 ,
int V_82 )
{
struct V_2 * V_3 ;
F_2 ( L_11 , V_2 ) ;
V_2 -> V_37 = V_83 ;
if ( V_2 -> type != V_84 )
return - V_85 ;
V_2 -> V_86 = & V_87 ;
V_3 = F_63 ( V_70 , V_2 , V_81 , V_18 ) ;
if ( ! V_3 )
return - V_36 ;
F_61 ( V_3 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_71 * V_2 , struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_12 , V_3 , F_26 ( & V_92 -> V_93 ) ) ;
if ( ! V_89 || V_89 -> V_94 != V_95 )
return - V_46 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_80 ) {
V_25 = - V_96 ;
goto V_35;
}
if ( V_3 -> V_69 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_33 ( & F_25 ( V_3 ) -> V_20 , & V_92 -> V_93 ) ;
V_3 -> V_4 = V_97 ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_72 ( struct V_71 * V_2 , struct V_88 * V_89 , int V_98 , int V_99 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_98 < sizeof( struct V_91 ) ||
V_89 -> V_94 != V_95 )
return - V_46 ;
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_97 )
return - V_96 ;
if ( V_3 -> V_69 != V_84 )
return - V_46 ;
F_59 ( V_3 ) ;
F_33 ( & F_25 ( V_3 ) -> V_22 , & V_92 -> V_93 ) ;
V_25 = F_24 ( V_3 ) ;
if ( V_25 )
goto V_35;
V_25 = F_73 ( V_3 , V_38 ,
F_74 ( V_3 , V_99 & V_100 ) ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_75 ( struct V_71 * V_2 , int V_101 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_20 = & F_25 ( V_3 ) -> V_20 ;
int V_25 = 0 ;
F_2 ( L_13 , V_3 , V_101 ) ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_97 ) {
V_25 = - V_96 ;
goto V_35;
}
if ( V_3 -> V_69 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_76 ( & V_57 . V_19 ) ;
if ( F_44 ( V_20 ) ) {
V_25 = - V_102 ;
goto V_103;
}
V_3 -> V_104 = V_101 ;
V_3 -> V_105 = 0 ;
V_3 -> V_4 = V_55 ;
V_103:
F_77 ( & V_57 . V_19 ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_78 ( struct V_71 * V_2 , struct V_71 * V_106 , int V_99 )
{
F_79 ( V_107 , V_108 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_109 ;
long V_110 ;
int V_25 = 0 ;
F_59 ( V_3 ) ;
V_110 = F_80 ( V_3 , V_99 & V_100 ) ;
F_2 ( L_14 , V_3 , V_110 ) ;
F_81 ( F_82 ( V_3 ) , & V_107 ) ;
while ( 1 ) {
F_83 ( V_111 ) ;
if ( V_3 -> V_4 != V_55 ) {
V_25 = - V_96 ;
break;
}
V_109 = F_53 ( V_3 , V_106 ) ;
if ( V_109 )
break;
if ( ! V_110 ) {
V_25 = - V_112 ;
break;
}
if ( F_84 ( V_108 ) ) {
V_25 = F_85 ( V_110 ) ;
break;
}
F_60 ( V_3 ) ;
V_110 = F_86 ( V_110 ) ;
F_59 ( V_3 ) ;
}
F_87 ( V_113 ) ;
F_88 ( F_82 ( V_3 ) , & V_107 ) ;
if ( V_25 )
goto V_35;
V_106 -> V_37 = V_114 ;
F_2 ( L_15 , V_109 ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_89 ( struct V_71 * V_2 , struct V_88 * V_89 , int * V_43 , int V_115 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_89 -> V_94 = V_95 ;
* V_43 = sizeof( struct V_91 ) ;
if ( V_115 )
F_33 ( & V_92 -> V_93 , & F_25 ( V_3 ) -> V_22 ) ;
else
F_33 ( & V_92 -> V_93 , & F_25 ( V_3 ) -> V_20 ) ;
return 0 ;
}
static int F_90 ( struct V_116 * V_117 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_25 = F_91 ( V_3 ) ;
if ( V_25 )
return V_25 ;
if ( V_42 -> V_47 & V_118 )
return - V_119 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 == V_38 )
V_25 = F_36 ( V_3 , V_42 , V_43 ) ;
else
V_25 = - V_120 ;
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_92 ( struct V_71 * V_2 , int V_121 , int V_122 , char T_4 * V_123 , unsigned int V_124 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
F_59 ( V_3 ) ;
switch ( V_122 ) {
default:
V_25 = - V_125 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_93 ( struct V_71 * V_2 , int V_122 , char T_4 * V_123 , int T_4 * V_124 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_126 V_127 ;
struct V_128 V_129 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_94 ( V_43 , V_124 ) )
return - V_50 ;
F_59 ( V_3 ) ;
switch ( V_122 ) {
case V_130 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_120 ;
break;
}
V_127 . V_24 = F_19 ( V_3 ) -> V_16 -> V_24 ;
F_2 ( L_17 , V_127 . V_24 ) ;
V_43 = F_95 (unsigned int, len, sizeof(opts)) ;
if ( F_96 ( V_123 , ( char * ) & V_127 , V_43 ) )
V_25 = - V_50 ;
break;
case V_131 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_120 ;
break;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_132 = F_19 ( V_3 ) -> V_16 -> V_13 -> V_133 ;
memcpy ( V_129 . V_134 , F_19 ( V_3 ) -> V_16 -> V_13 -> V_134 , 3 ) ;
V_43 = F_95 (unsigned int, len, sizeof(cinfo)) ;
if ( F_96 ( V_123 , ( char * ) & V_129 , V_43 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_125 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_97 ( struct V_71 * V_2 , int V_121 , int V_122 , char T_4 * V_123 , int T_4 * V_124 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_121 == V_135 )
return F_93 ( V_2 , V_122 , V_123 , V_124 ) ;
if ( F_94 ( V_43 , V_124 ) )
return - V_50 ;
F_59 ( V_3 ) ;
switch ( V_122 ) {
default:
V_25 = - V_125 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_98 ( struct V_71 * V_2 , int V_136 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_59 ( V_3 ) ;
if ( ! V_3 -> V_137 ) {
V_3 -> V_137 = V_138 ;
F_9 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( F_56 ( V_3 , V_139 ) && V_3 -> V_140 )
V_25 = F_73 ( V_3 , V_61 ,
V_3 -> V_140 ) ;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_99 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_54 ( V_3 ) ;
if ( F_56 ( V_3 , V_139 ) && V_3 -> V_140 ) {
F_59 ( V_3 ) ;
V_25 = F_73 ( V_3 , V_61 , V_3 -> V_140 ) ;
F_60 ( V_3 ) ;
}
F_100 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_25 ;
}
static void F_23 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_18 , V_16 ) ;
F_19 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_26 )
F_101 ( V_26 , V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_25 )
{
struct V_11 * V_16 ;
V_16 = F_19 ( V_3 ) -> V_16 ;
F_2 ( L_19 , V_3 , V_16 , V_25 ) ;
V_3 -> V_4 = V_61 ;
V_3 -> V_5 = V_25 ;
V_3 -> V_7 ( V_3 ) ;
F_55 ( V_3 , V_62 ) ;
}
static void F_102 ( struct V_11 * V_16 )
{
struct V_2 * V_26 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_18 , V_16 ) ;
F_15 ( V_16 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_38 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
V_26 = F_47 ( V_16 -> V_20 ) ;
if ( ! V_26 )
goto V_35;
F_3 ( V_26 ) ;
V_3 = F_63 ( F_103 ( V_26 ) , NULL ,
V_141 , V_18 ) ;
if ( ! V_3 ) {
F_4 ( V_26 ) ;
goto V_35;
}
F_61 ( V_3 , V_26 ) ;
F_33 ( & F_25 ( V_3 ) -> V_20 , V_16 -> V_20 ) ;
F_33 ( & F_25 ( V_3 ) -> V_22 , V_16 -> V_22 ) ;
F_104 ( V_16 -> V_13 ) ;
F_23 ( V_16 , V_3 , V_26 ) ;
V_3 -> V_4 = V_38 ;
V_26 -> V_142 ( V_26 , 1 ) ;
F_4 ( V_26 ) ;
}
V_35:
F_16 ( V_16 ) ;
}
int F_105 ( struct V_14 * V_15 , T_1 * V_21 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
int V_143 = 0 ;
F_2 ( L_20 , V_15 -> V_144 , F_26 ( V_21 ) ) ;
F_48 ( & V_57 . V_19 ) ;
F_45 (sk, node, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_55 )
continue;
if ( ! F_46 ( & F_25 ( V_3 ) -> V_20 , & V_15 -> V_21 ) ||
! F_46 ( & F_25 ( V_3 ) -> V_20 , V_58 ) ) {
V_143 |= V_145 ;
break;
}
}
F_49 ( & V_57 . V_19 ) ;
return V_143 ;
}
int F_106 ( struct V_12 * V_13 , T_5 V_146 )
{
F_2 ( L_21 , V_13 , F_26 ( & V_13 -> V_22 ) , V_146 ) ;
if ( ! V_146 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_102 ( V_16 ) ;
} else
F_17 ( V_13 , F_107 ( V_146 ) ) ;
return 0 ;
}
int F_108 ( struct V_12 * V_13 , T_5 V_147 )
{
F_2 ( L_22 , V_13 , V_147 ) ;
F_17 ( V_13 , F_107 ( V_147 ) ) ;
return 0 ;
}
int F_109 ( struct V_12 * V_13 , struct V_44 * V_45 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
if ( ! V_16 )
goto V_51;
F_2 ( L_23 , V_16 , V_45 -> V_43 ) ;
if ( V_45 -> V_43 ) {
F_42 ( V_16 , V_45 ) ;
return 0 ;
}
V_51:
F_40 ( V_45 ) ;
return 0 ;
}
static int F_110 ( struct V_148 * V_149 , void * V_150 )
{
struct V_2 * V_3 ;
struct V_53 * V_54 ;
F_48 ( & V_57 . V_19 ) ;
F_45 (sk, node, &sco_sk_list.head) {
F_111 ( V_149 , L_24 , F_26 ( & F_25 ( V_3 ) -> V_20 ) ,
F_26 ( & F_25 ( V_3 ) -> V_22 ) , V_3 -> V_4 ) ;
}
F_49 ( & V_57 . V_19 ) ;
return 0 ;
}
static int F_112 ( struct V_151 * V_151 , struct V_152 * V_152 )
{
return F_113 ( V_152 , F_110 , V_151 -> V_153 ) ;
}
int T_6 F_114 ( void )
{
int V_25 ;
V_25 = F_115 ( & V_75 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_116 ( V_141 , & V_154 ) ;
if ( V_25 < 0 ) {
F_117 ( L_25 ) ;
goto error;
}
if ( V_155 ) {
V_156 = F_118 ( L_26 , 0444 , V_155 ,
NULL , & V_157 ) ;
if ( ! V_156 )
F_117 ( L_27 ) ;
}
F_119 ( L_28 ) ;
return 0 ;
error:
F_120 ( & V_75 ) ;
return V_25 ;
}
void T_7 F_121 ( void )
{
F_122 ( V_156 ) ;
if ( F_123 ( V_141 ) < 0 )
F_117 ( L_29 ) ;
F_120 ( & V_75 ) ;
}
