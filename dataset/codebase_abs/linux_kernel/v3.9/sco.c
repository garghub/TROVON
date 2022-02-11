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
F_5 ( V_3 ) ;
}
V_13 -> V_17 = NULL ;
F_19 ( V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_26 )
{
int V_25 = 0 ;
F_15 ( V_16 ) ;
if ( V_16 -> V_3 )
V_25 = - V_27 ;
else
F_21 ( V_16 , V_3 , V_26 ) ;
F_16 ( V_16 ) ;
return V_25 ;
}
static int F_22 ( struct V_2 * V_3 )
{
T_1 * V_20 = & F_23 ( V_3 ) -> V_20 ;
T_1 * V_22 = & F_23 ( V_3 ) -> V_22 ;
struct V_11 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_25 , type ;
F_2 ( L_5 , V_20 , V_22 ) ;
V_15 = F_24 ( V_22 , V_20 ) ;
if ( ! V_15 )
return - V_28 ;
F_25 ( V_15 ) ;
if ( F_26 ( V_15 ) && ! V_29 )
type = V_30 ;
else
type = V_31 ;
V_13 = F_27 ( V_15 , type , V_22 , V_32 , V_33 ,
V_34 ) ;
if ( F_28 ( V_13 ) ) {
V_25 = F_29 ( V_13 ) ;
goto V_35;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_30 ( V_13 ) ;
V_25 = - V_36 ;
goto V_35;
}
F_31 ( V_20 , V_16 -> V_20 ) ;
V_25 = F_20 ( V_16 , V_3 , NULL ) ;
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
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
return V_25 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_41 * V_42 , int V_43 )
{
struct V_11 * V_16 = F_35 ( V_3 ) -> V_16 ;
struct V_44 * V_45 ;
int V_25 ;
if ( V_43 > V_16 -> V_24 )
return - V_46 ;
F_2 ( L_6 , V_3 , V_43 ) ;
V_45 = F_36 ( V_3 , V_43 , V_42 -> V_47 & V_48 , & V_25 ) ;
if ( ! V_45 )
return V_25 ;
if ( F_37 ( F_38 ( V_45 , V_43 ) , V_42 -> V_49 , V_43 ) ) {
F_39 ( V_45 ) ;
return - V_50 ;
}
F_40 ( V_16 -> V_13 , V_45 ) ;
return V_43 ;
}
static void F_41 ( struct V_11 * V_16 , struct V_44 * V_45 )
{
struct V_2 * V_3 = F_14 ( V_16 ) ;
if ( ! V_3 )
goto V_51;
F_2 ( L_6 , V_3 , V_45 -> V_43 ) ;
if ( V_3 -> V_4 != V_38 )
goto V_51;
if ( ! F_42 ( V_3 , V_45 ) )
return;
V_51:
F_39 ( V_45 ) ;
}
static struct V_2 * F_43 ( T_1 * V_52 )
{
struct V_2 * V_3 ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_20 , V_52 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_46 ( T_1 * V_20 )
{
struct V_2 * V_3 = NULL , * V_54 = NULL ;
F_47 ( & V_55 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_20 , V_20 ) )
break;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_20 , V_56 ) )
V_54 = V_3 ;
}
F_48 ( & V_55 . V_19 ) ;
return V_3 ? V_3 : V_54 ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_2 ( L_7 , V_3 ) ;
F_50 ( & V_3 -> V_57 ) ;
F_50 ( & V_3 -> V_58 ) ;
}
static void F_51 ( struct V_2 * V_26 )
{
struct V_2 * V_3 ;
F_2 ( L_8 , V_26 ) ;
while ( ( V_3 = F_52 ( V_26 , NULL ) ) ) {
F_53 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_26 -> V_4 = V_59 ;
F_54 ( V_26 , V_60 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_55 ( V_3 , V_60 ) || V_3 -> V_61 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_4 ) ;
F_56 ( & V_55 , V_3 ) ;
F_54 ( V_3 , V_62 ) ;
F_6 ( V_3 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 , V_3 -> V_4 , V_3 -> V_61 ) ;
switch ( V_3 -> V_4 ) {
case V_53 :
F_51 ( V_3 ) ;
break;
case V_38 :
case V_63 :
if ( F_35 ( V_3 ) -> V_16 -> V_13 ) {
V_3 -> V_4 = V_64 ;
F_7 ( V_3 , V_65 ) ;
F_30 ( F_35 ( V_3 ) -> V_16 -> V_13 ) ;
F_35 ( V_3 ) -> V_16 -> V_13 = NULL ;
} else
F_18 ( V_3 , V_66 ) ;
break;
case V_67 :
case V_39 :
case V_64 :
F_18 ( V_3 , V_66 ) ;
break;
default:
F_54 ( V_3 , V_60 ) ;
break;
}
}
static void F_53 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_58 ( V_3 ) ;
F_57 ( V_3 ) ;
F_59 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_7 , V_3 ) ;
if ( V_26 ) {
V_3 -> V_68 = V_26 -> V_68 ;
F_23 ( V_3 ) -> V_69 = F_23 ( V_26 ) -> V_69 ;
F_61 ( V_26 , V_3 ) ;
}
}
static struct V_2 * F_62 ( struct V_70 * V_70 , struct V_71 * V_2 , int V_72 , T_2 V_73 )
{
struct V_2 * V_3 ;
V_3 = F_63 ( V_70 , V_74 , V_73 , & V_75 ) ;
if ( ! V_3 )
return NULL ;
F_64 ( V_2 , V_3 ) ;
F_65 ( & F_23 ( V_3 ) -> V_76 ) ;
V_3 -> V_77 = F_49 ;
V_3 -> V_40 = V_78 ;
F_66 ( V_3 , V_60 ) ;
V_3 -> V_79 = V_72 ;
V_3 -> V_4 = V_80 ;
F_67 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_68 ( & V_55 , V_3 ) ;
return V_3 ;
}
static int F_69 ( struct V_70 * V_70 , struct V_71 * V_2 , int V_81 ,
int V_82 )
{
struct V_2 * V_3 ;
F_2 ( L_11 , V_2 ) ;
V_2 -> V_37 = V_83 ;
if ( V_2 -> type != V_84 )
return - V_85 ;
V_2 -> V_86 = & V_87 ;
V_3 = F_62 ( V_70 , V_2 , V_81 , V_18 ) ;
if ( ! V_3 )
return - V_36 ;
F_60 ( V_3 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_71 * V_2 , struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_12 , V_3 , & V_92 -> V_93 ) ;
if ( ! V_89 || V_89 -> V_94 != V_95 )
return - V_46 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_80 ) {
V_25 = - V_96 ;
goto V_35;
}
if ( V_3 -> V_68 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_31 ( & F_23 ( V_3 ) -> V_20 , & V_92 -> V_93 ) ;
V_3 -> V_4 = V_97 ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_71 ( struct V_71 * V_2 , struct V_88 * V_89 , int V_98 , int V_69 )
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
if ( V_3 -> V_68 != V_84 )
return - V_46 ;
F_58 ( V_3 ) ;
F_31 ( & F_23 ( V_3 ) -> V_22 , & V_92 -> V_93 ) ;
V_25 = F_22 ( V_3 ) ;
if ( V_25 )
goto V_35;
V_25 = F_72 ( V_3 , V_38 ,
F_73 ( V_3 , V_69 & V_99 ) ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_74 ( struct V_71 * V_2 , int V_100 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_20 = & F_23 ( V_3 ) -> V_20 ;
int V_25 = 0 ;
F_2 ( L_13 , V_3 , V_100 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_97 ) {
V_25 = - V_96 ;
goto V_35;
}
if ( V_3 -> V_68 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_75 ( & V_55 . V_19 ) ;
if ( F_43 ( V_20 ) ) {
V_25 = - V_101 ;
goto V_102;
}
V_3 -> V_103 = V_100 ;
V_3 -> V_104 = 0 ;
V_3 -> V_4 = V_53 ;
V_102:
F_76 ( & V_55 . V_19 ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_77 ( struct V_71 * V_2 , struct V_71 * V_105 , int V_69 )
{
F_78 ( V_106 , V_107 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_108 ;
long V_109 ;
int V_25 = 0 ;
F_58 ( V_3 ) ;
V_109 = F_79 ( V_3 , V_69 & V_99 ) ;
F_2 ( L_14 , V_3 , V_109 ) ;
F_80 ( F_81 ( V_3 ) , & V_106 ) ;
while ( 1 ) {
F_82 ( V_110 ) ;
if ( V_3 -> V_4 != V_53 ) {
V_25 = - V_96 ;
break;
}
V_108 = F_52 ( V_3 , V_105 ) ;
if ( V_108 )
break;
if ( ! V_109 ) {
V_25 = - V_111 ;
break;
}
if ( F_83 ( V_107 ) ) {
V_25 = F_84 ( V_109 ) ;
break;
}
F_59 ( V_3 ) ;
V_109 = F_85 ( V_109 ) ;
F_58 ( V_3 ) ;
}
F_86 ( V_112 ) ;
F_87 ( F_81 ( V_3 ) , & V_106 ) ;
if ( V_25 )
goto V_35;
V_105 -> V_37 = V_113 ;
F_2 ( L_15 , V_108 ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_88 ( struct V_71 * V_2 , struct V_88 * V_89 , int * V_43 , int V_114 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_89 -> V_94 = V_95 ;
* V_43 = sizeof( struct V_91 ) ;
if ( V_114 )
F_31 ( & V_92 -> V_93 , & F_23 ( V_3 ) -> V_22 ) ;
else
F_31 ( & V_92 -> V_93 , & F_23 ( V_3 ) -> V_20 ) ;
return 0 ;
}
static int F_89 ( struct V_115 * V_116 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_25 = F_90 ( V_3 ) ;
if ( V_25 )
return V_25 ;
if ( V_42 -> V_47 & V_117 )
return - V_118 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_38 )
V_25 = F_34 ( V_3 , V_42 , V_43 ) ;
else
V_25 = - V_119 ;
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_91 ( struct V_115 * V_116 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 , int V_69 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_120 * V_121 = F_35 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_67 &&
F_92 ( V_122 , & F_23 ( V_3 ) -> V_69 ) ) {
F_93 ( V_121 -> V_16 -> V_13 , 0 ) ;
V_3 -> V_4 = V_63 ;
V_42 -> V_123 = 0 ;
F_59 ( V_3 ) ;
return 0 ;
}
F_59 ( V_3 ) ;
return F_94 ( V_116 , V_2 , V_42 , V_43 , V_69 ) ;
}
static int F_95 ( struct V_71 * V_2 , int V_124 , int V_125 , char T_4 * V_126 , unsigned int V_127 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
T_5 V_128 ;
F_2 ( L_7 , V_3 ) ;
F_58 ( V_3 ) ;
switch ( V_125 ) {
case V_129 :
if ( V_3 -> V_4 != V_97 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_96 ( V_128 , ( T_5 T_4 * ) V_126 ) ) {
V_25 = - V_50 ;
break;
}
if ( V_128 )
F_97 ( V_122 , & F_23 ( V_3 ) -> V_69 ) ;
else
F_98 ( V_122 , & F_23 ( V_3 ) -> V_69 ) ;
break;
default:
V_25 = - V_130 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_99 ( struct V_71 * V_2 , int V_125 , char T_4 * V_126 , int T_4 * V_127 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_131 V_132 ;
struct V_133 V_134 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_96 ( V_43 , V_127 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_125 ) {
case V_135 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_119 ;
break;
}
V_132 . V_24 = F_35 ( V_3 ) -> V_16 -> V_24 ;
F_2 ( L_17 , V_132 . V_24 ) ;
V_43 = F_100 (unsigned int, len, sizeof(opts)) ;
if ( F_101 ( V_126 , ( char * ) & V_132 , V_43 ) )
V_25 = - V_50 ;
break;
case V_136 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_119 ;
break;
}
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_137 = F_35 ( V_3 ) -> V_16 -> V_13 -> V_138 ;
memcpy ( V_134 . V_139 , F_35 ( V_3 ) -> V_16 -> V_13 -> V_139 , 3 ) ;
V_43 = F_100 (unsigned int, len, sizeof(cinfo)) ;
if ( F_101 ( V_126 , ( char * ) & V_134 , V_43 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_130 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_102 ( struct V_71 * V_2 , int V_124 , int V_125 , char T_4 * V_126 , int T_4 * V_127 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_124 == V_140 )
return F_99 ( V_2 , V_125 , V_126 , V_127 ) ;
if ( F_96 ( V_43 , V_127 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_125 ) {
case V_129 :
if ( V_3 -> V_4 != V_97 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_103 ( F_92 ( V_122 , & F_23 ( V_3 ) -> V_69 ) ,
( T_5 T_4 * ) V_126 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_130 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_104 ( struct V_71 * V_2 , int V_141 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_58 ( V_3 ) ;
if ( ! V_3 -> V_142 ) {
V_3 -> V_142 = V_143 ;
F_9 ( V_3 ) ;
F_57 ( V_3 ) ;
if ( F_55 ( V_3 , V_144 ) && V_3 -> V_145 )
V_25 = F_72 ( V_3 , V_59 ,
V_3 -> V_145 ) ;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_105 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_53 ( V_3 ) ;
if ( F_55 ( V_3 , V_144 ) && V_3 -> V_145 ) {
F_58 ( V_3 ) ;
V_25 = F_72 ( V_3 , V_59 , V_3 -> V_145 ) ;
F_59 ( V_3 ) ;
}
F_106 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_25 ;
}
static void F_21 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_18 , V_16 ) ;
F_35 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_26 )
F_107 ( V_26 , V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_25 )
{
struct V_11 * V_16 ;
V_16 = F_35 ( V_3 ) -> V_16 ;
F_2 ( L_19 , V_3 , V_16 , V_25 ) ;
if ( V_16 ) {
F_15 ( V_16 ) ;
V_16 -> V_3 = NULL ;
F_35 ( V_3 ) -> V_16 = NULL ;
F_16 ( V_16 ) ;
if ( V_16 -> V_13 )
F_30 ( V_16 -> V_13 ) ;
}
V_3 -> V_4 = V_59 ;
V_3 -> V_5 = V_25 ;
V_3 -> V_7 ( V_3 ) ;
F_54 ( V_3 , V_60 ) ;
}
static void F_108 ( struct V_11 * V_16 )
{
struct V_2 * V_26 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_18 , V_16 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_38 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
F_15 ( V_16 ) ;
V_26 = F_46 ( V_16 -> V_20 ) ;
if ( ! V_26 ) {
F_16 ( V_16 ) ;
return;
}
F_3 ( V_26 ) ;
V_3 = F_62 ( F_109 ( V_26 ) , NULL ,
V_146 , V_18 ) ;
if ( ! V_3 ) {
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
return;
}
F_60 ( V_3 , V_26 ) ;
F_31 ( & F_23 ( V_3 ) -> V_20 , V_16 -> V_20 ) ;
F_31 ( & F_23 ( V_3 ) -> V_22 , V_16 -> V_22 ) ;
F_110 ( V_16 -> V_13 ) ;
F_21 ( V_16 , V_3 , V_26 ) ;
if ( F_92 ( V_122 , & F_23 ( V_26 ) -> V_69 ) )
V_3 -> V_4 = V_67 ;
else
V_3 -> V_4 = V_38 ;
V_26 -> V_147 ( V_26 , 1 ) ;
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
}
}
int F_111 ( struct V_14 * V_15 , T_1 * V_21 , T_6 * V_69 )
{
struct V_2 * V_3 ;
int V_148 = 0 ;
F_2 ( L_20 , V_15 -> V_149 , V_21 ) ;
F_47 ( & V_55 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_20 , & V_15 -> V_21 ) ||
! F_45 ( & F_23 ( V_3 ) -> V_20 , V_56 ) ) {
V_148 |= V_150 ;
if ( F_92 ( V_122 , & F_23 ( V_3 ) -> V_69 ) )
* V_69 |= V_151 ;
break;
}
}
F_48 ( & V_55 . V_19 ) ;
return V_148 ;
}
void F_112 ( struct V_12 * V_13 , T_6 V_152 )
{
F_2 ( L_21 , V_13 , & V_13 -> V_22 , V_152 ) ;
if ( ! V_152 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_108 ( V_16 ) ;
} else
F_17 ( V_13 , F_113 ( V_152 ) ) ;
}
void F_114 ( struct V_12 * V_13 , T_6 V_153 )
{
F_2 ( L_22 , V_13 , V_153 ) ;
F_17 ( V_13 , F_113 ( V_153 ) ) ;
}
int F_115 ( struct V_12 * V_13 , struct V_44 * V_45 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
if ( ! V_16 )
goto V_51;
F_2 ( L_23 , V_16 , V_45 -> V_43 ) ;
if ( V_45 -> V_43 ) {
F_41 ( V_16 , V_45 ) ;
return 0 ;
}
V_51:
F_39 ( V_45 ) ;
return 0 ;
}
static int F_116 ( struct V_154 * V_155 , void * V_156 )
{
struct V_2 * V_3 ;
F_47 ( & V_55 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
F_117 ( V_155 , L_24 , & F_23 ( V_3 ) -> V_20 ,
& F_23 ( V_3 ) -> V_22 , V_3 -> V_4 ) ;
}
F_48 ( & V_55 . V_19 ) ;
return 0 ;
}
static int F_118 ( struct V_157 * V_157 , struct V_158 * V_158 )
{
return F_119 ( V_158 , F_116 , V_157 -> V_159 ) ;
}
int T_7 F_120 ( void )
{
int V_25 ;
V_25 = F_121 ( & V_75 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_122 ( V_146 , & V_160 ) ;
if ( V_25 < 0 ) {
F_123 ( L_25 ) ;
goto error;
}
V_25 = F_124 ( V_161 , & V_162 , L_26 , & V_55 , NULL ) ;
if ( V_25 < 0 ) {
F_123 ( L_27 ) ;
F_125 ( V_146 ) ;
goto error;
}
if ( V_163 ) {
V_164 = F_126 ( L_26 , 0444 , V_163 ,
NULL , & V_165 ) ;
if ( ! V_164 )
F_123 ( L_28 ) ;
}
F_127 ( L_29 ) ;
return 0 ;
error:
F_128 ( & V_75 ) ;
return V_25 ;
}
void T_8 F_129 ( void )
{
F_130 ( & V_162 , L_26 ) ;
F_131 ( V_164 ) ;
if ( F_125 ( V_146 ) < 0 )
F_123 ( L_30 ) ;
F_128 ( & V_75 ) ;
}
