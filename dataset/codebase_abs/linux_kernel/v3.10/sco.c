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
V_3 = F_62 ( V_70 , V_2 , V_81 , V_88 ) ;
if ( ! V_3 )
return - V_36 ;
F_60 ( V_3 , NULL ) ;
return 0 ;
}
static int F_70 ( struct V_71 * V_2 , struct V_89 * V_90 , int V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_12 , V_3 , & V_93 -> V_94 ) ;
if ( ! V_90 || V_90 -> V_95 != V_96 )
return - V_46 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_80 ) {
V_25 = - V_97 ;
goto V_35;
}
if ( V_3 -> V_68 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_31 ( & F_23 ( V_3 ) -> V_20 , & V_93 -> V_94 ) ;
V_3 -> V_4 = V_98 ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_71 ( struct V_71 * V_2 , struct V_89 * V_90 , int V_99 , int V_69 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_7 , V_3 ) ;
if ( V_99 < sizeof( struct V_92 ) ||
V_90 -> V_95 != V_96 )
return - V_46 ;
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_98 )
return - V_97 ;
if ( V_3 -> V_68 != V_84 )
return - V_46 ;
F_58 ( V_3 ) ;
F_31 ( & F_23 ( V_3 ) -> V_22 , & V_93 -> V_94 ) ;
V_25 = F_22 ( V_3 ) ;
if ( V_25 )
goto V_35;
V_25 = F_72 ( V_3 , V_38 ,
F_73 ( V_3 , V_69 & V_100 ) ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_74 ( struct V_71 * V_2 , int V_101 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_20 = & F_23 ( V_3 ) -> V_20 ;
int V_25 = 0 ;
F_2 ( L_13 , V_3 , V_101 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_98 ) {
V_25 = - V_97 ;
goto V_35;
}
if ( V_3 -> V_68 != V_84 ) {
V_25 = - V_46 ;
goto V_35;
}
F_75 ( & V_55 . V_19 ) ;
if ( F_43 ( V_20 ) ) {
V_25 = - V_102 ;
goto V_103;
}
V_3 -> V_104 = V_101 ;
V_3 -> V_105 = 0 ;
V_3 -> V_4 = V_53 ;
V_103:
F_76 ( & V_55 . V_19 ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_77 ( struct V_71 * V_2 , struct V_71 * V_106 , int V_69 )
{
F_78 ( V_107 , V_108 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_109 ;
long V_110 ;
int V_25 = 0 ;
F_58 ( V_3 ) ;
V_110 = F_79 ( V_3 , V_69 & V_100 ) ;
F_2 ( L_14 , V_3 , V_110 ) ;
F_80 ( F_81 ( V_3 ) , & V_107 ) ;
while ( 1 ) {
F_82 ( V_111 ) ;
if ( V_3 -> V_4 != V_53 ) {
V_25 = - V_97 ;
break;
}
V_109 = F_52 ( V_3 , V_106 ) ;
if ( V_109 )
break;
if ( ! V_110 ) {
V_25 = - V_112 ;
break;
}
if ( F_83 ( V_108 ) ) {
V_25 = F_84 ( V_110 ) ;
break;
}
F_59 ( V_3 ) ;
V_110 = F_85 ( V_110 ) ;
F_58 ( V_3 ) ;
}
F_86 ( V_113 ) ;
F_87 ( F_81 ( V_3 ) , & V_107 ) ;
if ( V_25 )
goto V_35;
V_106 -> V_37 = V_114 ;
F_2 ( L_15 , V_109 ) ;
V_35:
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_88 ( struct V_71 * V_2 , struct V_89 * V_90 , int * V_43 , int V_115 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_90 -> V_95 = V_96 ;
* V_43 = sizeof( struct V_92 ) ;
if ( V_115 )
F_31 ( & V_93 -> V_94 , & F_23 ( V_3 ) -> V_22 ) ;
else
F_31 ( & V_93 -> V_94 , & F_23 ( V_3 ) -> V_20 ) ;
return 0 ;
}
static int F_89 ( struct V_116 * V_117 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_25 = F_90 ( V_3 ) ;
if ( V_25 )
return V_25 ;
if ( V_42 -> V_47 & V_118 )
return - V_119 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_38 )
V_25 = F_34 ( V_3 , V_42 , V_43 ) ;
else
V_25 = - V_120 ;
F_59 ( V_3 ) ;
return V_25 ;
}
static void F_91 ( struct V_12 * V_16 , int V_121 )
{
struct V_14 * V_15 = V_16 -> V_15 ;
F_2 ( L_17 , V_16 ) ;
V_16 -> V_37 = V_63 ;
if ( ! F_26 ( V_15 ) ) {
struct V_122 V_123 ;
F_31 ( & V_123 . V_21 , & V_16 -> V_22 ) ;
if ( F_92 ( V_15 ) && ( V_121 & V_124 ) )
V_123 . V_125 = 0x00 ;
else
V_123 . V_125 = 0x01 ;
F_93 ( V_15 , V_126 , sizeof( V_123 ) , & V_123 ) ;
} else {
struct V_127 V_123 ;
F_31 ( & V_123 . V_21 , & V_16 -> V_22 ) ;
V_123 . V_128 = F_94 ( V_16 -> V_128 ) ;
V_123 . V_129 = F_95 ( 0x00001f40 ) ;
V_123 . V_130 = F_95 ( 0x00001f40 ) ;
V_123 . V_131 = F_96 ( 0xffff ) ;
V_123 . V_132 = F_94 ( V_15 -> V_133 ) ;
V_123 . V_134 = 0xff ;
F_93 ( V_15 , V_135 ,
sizeof( V_123 ) , & V_123 ) ;
}
}
static int F_97 ( struct V_116 * V_117 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 , int V_69 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_136 * V_137 = F_35 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_67 &&
F_98 ( V_138 , & F_23 ( V_3 ) -> V_69 ) ) {
F_91 ( V_137 -> V_16 -> V_13 , 0 ) ;
V_3 -> V_4 = V_63 ;
V_42 -> V_139 = 0 ;
F_59 ( V_3 ) ;
return 0 ;
}
F_59 ( V_3 ) ;
return F_99 ( V_117 , V_2 , V_42 , V_43 , V_69 ) ;
}
static int F_100 ( struct V_71 * V_2 , int V_140 , int V_141 , char T_4 * V_142 , unsigned int V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
T_5 V_144 ;
F_2 ( L_7 , V_3 ) ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_145 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_101 ( V_144 , ( T_5 T_4 * ) V_142 ) ) {
V_25 = - V_50 ;
break;
}
if ( V_144 )
F_102 ( V_138 , & F_23 ( V_3 ) -> V_69 ) ;
else
F_103 ( V_138 , & F_23 ( V_3 ) -> V_69 ) ;
break;
default:
V_25 = - V_146 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_104 ( struct V_71 * V_2 , int V_141 , char T_4 * V_142 , int T_4 * V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_147 V_148 ;
struct V_149 V_150 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_101 ( V_43 , V_143 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_151 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_120 ;
break;
}
V_148 . V_24 = F_35 ( V_3 ) -> V_16 -> V_24 ;
F_2 ( L_18 , V_148 . V_24 ) ;
V_43 = F_105 (unsigned int, len, sizeof(opts)) ;
if ( F_106 ( V_142 , ( char * ) & V_148 , V_43 ) )
V_25 = - V_50 ;
break;
case V_152 :
if ( V_3 -> V_4 != V_38 ) {
V_25 = - V_120 ;
break;
}
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
V_150 . V_153 = F_35 ( V_3 ) -> V_16 -> V_13 -> V_154 ;
memcpy ( V_150 . V_155 , F_35 ( V_3 ) -> V_16 -> V_13 -> V_155 , 3 ) ;
V_43 = F_105 (unsigned int, len, sizeof(cinfo)) ;
if ( F_106 ( V_142 , ( char * ) & V_150 , V_43 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_146 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_107 ( struct V_71 * V_2 , int V_140 , int V_141 , char T_4 * V_142 , int T_4 * V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( V_140 == V_156 )
return F_104 ( V_2 , V_141 , V_142 , V_143 ) ;
if ( F_101 ( V_43 , V_143 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_145 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_108 ( F_98 ( V_138 , & F_23 ( V_3 ) -> V_69 ) ,
( T_5 T_4 * ) V_142 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_146 ;
break;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_109 ( struct V_71 * V_2 , int V_157 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_58 ( V_3 ) ;
if ( ! V_3 -> V_158 ) {
V_3 -> V_158 = V_159 ;
F_9 ( V_3 ) ;
F_57 ( V_3 ) ;
if ( F_55 ( V_3 , V_160 ) && V_3 -> V_161 )
V_25 = F_72 ( V_3 , V_59 ,
V_3 -> V_161 ) ;
}
F_59 ( V_3 ) ;
return V_25 ;
}
static int F_110 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_53 ( V_3 ) ;
if ( F_55 ( V_3 , V_160 ) && V_3 -> V_161 ) {
F_58 ( V_3 ) ;
V_25 = F_72 ( V_3 , V_59 , V_3 -> V_161 ) ;
F_59 ( V_3 ) ;
}
F_111 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_25 ;
}
static void F_21 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_17 , V_16 ) ;
F_35 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_26 )
F_112 ( V_26 , V_3 ) ;
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
static void F_113 ( struct V_11 * V_16 )
{
struct V_2 * V_26 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_17 , V_16 ) ;
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
V_3 = F_62 ( F_114 ( V_26 ) , NULL ,
V_162 , V_88 ) ;
if ( ! V_3 ) {
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
return;
}
F_60 ( V_3 , V_26 ) ;
F_31 ( & F_23 ( V_3 ) -> V_20 , V_16 -> V_20 ) ;
F_31 ( & F_23 ( V_3 ) -> V_22 , V_16 -> V_22 ) ;
F_115 ( V_16 -> V_13 ) ;
F_21 ( V_16 , V_3 , V_26 ) ;
if ( F_98 ( V_138 , & F_23 ( V_26 ) -> V_69 ) )
V_3 -> V_4 = V_67 ;
else
V_3 -> V_4 = V_38 ;
V_26 -> V_163 ( V_26 , 1 ) ;
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
}
}
int F_116 ( struct V_14 * V_15 , T_1 * V_21 , T_6 * V_69 )
{
struct V_2 * V_3 ;
int V_164 = 0 ;
F_2 ( L_20 , V_15 -> V_165 , V_21 ) ;
F_47 ( & V_55 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_20 , & V_15 -> V_21 ) ||
! F_45 ( & F_23 ( V_3 ) -> V_20 , V_56 ) ) {
V_164 |= V_166 ;
if ( F_98 ( V_138 , & F_23 ( V_3 ) -> V_69 ) )
* V_69 |= V_167 ;
break;
}
}
F_48 ( & V_55 . V_19 ) ;
return V_164 ;
}
void F_117 ( struct V_12 * V_13 , T_6 V_168 )
{
F_2 ( L_21 , V_13 , & V_13 -> V_22 , V_168 ) ;
if ( ! V_168 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_113 ( V_16 ) ;
} else
F_17 ( V_13 , F_118 ( V_168 ) ) ;
}
void F_119 ( struct V_12 * V_13 , T_6 V_169 )
{
F_2 ( L_22 , V_13 , V_169 ) ;
F_17 ( V_13 , F_118 ( V_169 ) ) ;
}
int F_120 ( struct V_12 * V_13 , struct V_44 * V_45 )
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
static int F_121 ( struct V_170 * V_171 , void * V_172 )
{
struct V_2 * V_3 ;
F_47 ( & V_55 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
F_122 ( V_171 , L_24 , & F_23 ( V_3 ) -> V_20 ,
& F_23 ( V_3 ) -> V_22 , V_3 -> V_4 ) ;
}
F_48 ( & V_55 . V_19 ) ;
return 0 ;
}
static int F_123 ( struct V_173 * V_173 , struct V_174 * V_174 )
{
return F_124 ( V_174 , F_121 , V_173 -> V_175 ) ;
}
int T_7 F_125 ( void )
{
int V_25 ;
V_25 = F_126 ( & V_75 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_127 ( V_162 , & V_176 ) ;
if ( V_25 < 0 ) {
F_128 ( L_25 ) ;
goto error;
}
V_25 = F_129 ( & V_177 , L_26 , & V_55 , NULL ) ;
if ( V_25 < 0 ) {
F_128 ( L_27 ) ;
F_130 ( V_162 ) ;
goto error;
}
if ( V_178 ) {
V_179 = F_131 ( L_26 , 0444 , V_178 ,
NULL , & V_180 ) ;
if ( ! V_179 )
F_128 ( L_28 ) ;
}
F_132 ( L_29 ) ;
return 0 ;
error:
F_133 ( & V_75 ) ;
return V_25 ;
}
void T_8 F_134 ( void )
{
F_135 ( & V_177 , L_26 ) ;
F_136 ( V_179 ) ;
F_130 ( V_162 ) ;
F_133 ( & V_75 ) ;
}
