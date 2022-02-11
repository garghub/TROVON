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
if ( F_27 ( V_3 ) -> V_32 == V_33 &&
( ! F_28 ( V_15 ) || ! F_26 ( V_15 ) ) ) {
V_25 = - V_34 ;
goto V_35;
}
V_13 = F_29 ( V_15 , type , V_22 , F_27 ( V_3 ) -> V_32 ) ;
if ( F_30 ( V_13 ) ) {
V_25 = F_31 ( V_13 ) ;
goto V_35;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_32 ( V_13 ) ;
V_25 = - V_36 ;
goto V_35;
}
F_33 ( V_20 , V_16 -> V_20 ) ;
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
F_34 ( V_15 ) ;
F_35 ( V_15 ) ;
return V_25 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_41 * V_42 , int V_43 )
{
struct V_11 * V_16 = F_27 ( V_3 ) -> V_16 ;
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
struct V_2 * V_3 ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_23 ( V_3 ) -> V_20 , V_52 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_47 ( T_1 * V_20 )
{
struct V_2 * V_3 = NULL , * V_54 = NULL ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_23 ( V_3 ) -> V_20 , V_20 ) )
break;
if ( ! F_46 ( & F_23 ( V_3 ) -> V_20 , V_56 ) )
V_54 = V_3 ;
}
F_49 ( & V_55 . V_19 ) ;
return V_3 ? V_3 : V_54 ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_2 ( L_7 , V_3 ) ;
F_51 ( & V_3 -> V_57 ) ;
F_51 ( & V_3 -> V_58 ) ;
}
static void F_52 ( struct V_2 * V_26 )
{
struct V_2 * V_3 ;
F_2 ( L_8 , V_26 ) ;
while ( ( V_3 = F_53 ( V_26 , NULL ) ) ) {
F_54 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_26 -> V_4 = V_59 ;
F_55 ( V_26 , V_60 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_56 ( V_3 , V_60 ) || V_3 -> V_61 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_4 ) ;
F_57 ( & V_55 , V_3 ) ;
F_55 ( V_3 , V_62 ) ;
F_6 ( V_3 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 , V_3 -> V_4 , V_3 -> V_61 ) ;
switch ( V_3 -> V_4 ) {
case V_53 :
F_52 ( V_3 ) ;
break;
case V_38 :
case V_63 :
if ( F_27 ( V_3 ) -> V_16 -> V_13 ) {
V_3 -> V_4 = V_64 ;
F_7 ( V_3 , V_65 ) ;
F_32 ( F_27 ( V_3 ) -> V_16 -> V_13 ) ;
F_27 ( V_3 ) -> V_16 -> V_13 = NULL ;
} else
F_18 ( V_3 , V_66 ) ;
break;
case V_67 :
case V_39 :
case V_64 :
F_18 ( V_3 , V_66 ) ;
break;
default:
F_55 ( V_3 , V_60 ) ;
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
V_3 -> V_68 = V_26 -> V_68 ;
F_23 ( V_3 ) -> V_69 = F_23 ( V_26 ) -> V_69 ;
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
F_66 ( & F_23 ( V_3 ) -> V_76 ) ;
V_3 -> V_77 = F_50 ;
V_3 -> V_40 = V_78 ;
F_67 ( V_3 , V_60 ) ;
V_3 -> V_79 = V_72 ;
V_3 -> V_4 = V_80 ;
F_27 ( V_3 ) -> V_32 = V_81 ;
F_68 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_69 ( & V_55 , V_3 ) ;
return V_3 ;
}
static int F_70 ( struct V_70 * V_70 , struct V_71 * V_2 , int V_82 ,
int V_83 )
{
struct V_2 * V_3 ;
F_2 ( L_11 , V_2 ) ;
V_2 -> V_37 = V_84 ;
if ( V_2 -> type != V_85 )
return - V_86 ;
V_2 -> V_87 = & V_88 ;
V_3 = F_63 ( V_70 , V_2 , V_82 , V_89 ) ;
if ( ! V_3 )
return - V_36 ;
F_61 ( V_3 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_71 * V_2 , struct V_90 * V_91 , int V_92 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_12 , V_3 , & V_94 -> V_95 ) ;
if ( ! V_91 || V_91 -> V_96 != V_97 )
return - V_46 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_80 ) {
V_25 = - V_98 ;
goto V_35;
}
if ( V_3 -> V_68 != V_85 ) {
V_25 = - V_46 ;
goto V_35;
}
F_33 ( & F_23 ( V_3 ) -> V_20 , & V_94 -> V_95 ) ;
V_3 -> V_4 = V_99 ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_72 ( struct V_71 * V_2 , struct V_90 * V_91 , int V_100 , int V_69 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_7 , V_3 ) ;
if ( V_100 < sizeof( struct V_93 ) ||
V_91 -> V_96 != V_97 )
return - V_46 ;
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_99 )
return - V_98 ;
if ( V_3 -> V_68 != V_85 )
return - V_46 ;
F_59 ( V_3 ) ;
F_33 ( & F_23 ( V_3 ) -> V_22 , & V_94 -> V_95 ) ;
V_25 = F_22 ( V_3 ) ;
if ( V_25 )
goto V_35;
V_25 = F_73 ( V_3 , V_38 ,
F_74 ( V_3 , V_69 & V_101 ) ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_75 ( struct V_71 * V_2 , int V_102 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_20 = & F_23 ( V_3 ) -> V_20 ;
int V_25 = 0 ;
F_2 ( L_13 , V_3 , V_102 ) ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_99 ) {
V_25 = - V_98 ;
goto V_35;
}
if ( V_3 -> V_68 != V_85 ) {
V_25 = - V_46 ;
goto V_35;
}
F_76 ( & V_55 . V_19 ) ;
if ( F_44 ( V_20 ) ) {
V_25 = - V_103 ;
goto V_104;
}
V_3 -> V_105 = V_102 ;
V_3 -> V_106 = 0 ;
V_3 -> V_4 = V_53 ;
V_104:
F_77 ( & V_55 . V_19 ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_78 ( struct V_71 * V_2 , struct V_71 * V_107 , int V_69 )
{
F_79 ( V_108 , V_109 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_110 ;
long V_111 ;
int V_25 = 0 ;
F_59 ( V_3 ) ;
V_111 = F_80 ( V_3 , V_69 & V_101 ) ;
F_2 ( L_14 , V_3 , V_111 ) ;
F_81 ( F_82 ( V_3 ) , & V_108 ) ;
while ( 1 ) {
F_83 ( V_112 ) ;
if ( V_3 -> V_4 != V_53 ) {
V_25 = - V_98 ;
break;
}
V_110 = F_53 ( V_3 , V_107 ) ;
if ( V_110 )
break;
if ( ! V_111 ) {
V_25 = - V_113 ;
break;
}
if ( F_84 ( V_109 ) ) {
V_25 = F_85 ( V_111 ) ;
break;
}
F_60 ( V_3 ) ;
V_111 = F_86 ( V_111 ) ;
F_59 ( V_3 ) ;
}
F_87 ( V_114 ) ;
F_88 ( F_82 ( V_3 ) , & V_108 ) ;
if ( V_25 )
goto V_35;
V_107 -> V_37 = V_115 ;
F_2 ( L_15 , V_110 ) ;
V_35:
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_89 ( struct V_71 * V_2 , struct V_90 * V_91 , int * V_43 , int V_116 )
{
struct V_93 * V_94 = (struct V_93 * ) V_91 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_91 -> V_96 = V_97 ;
* V_43 = sizeof( struct V_93 ) ;
if ( V_116 )
F_33 ( & V_94 -> V_95 , & F_23 ( V_3 ) -> V_22 ) ;
else
F_33 ( & V_94 -> V_95 , & F_23 ( V_3 ) -> V_20 ) ;
return 0 ;
}
static int F_90 ( struct V_117 * V_118 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_25 = F_91 ( V_3 ) ;
if ( V_25 )
return V_25 ;
if ( V_42 -> V_47 & V_119 )
return - V_34 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 == V_38 )
V_25 = F_36 ( V_3 , V_42 , V_43 ) ;
else
V_25 = - V_120 ;
F_60 ( V_3 ) ;
return V_25 ;
}
static void F_92 ( struct V_12 * V_16 , T_4 V_32 )
{
struct V_14 * V_15 = V_16 -> V_15 ;
F_2 ( L_17 , V_16 ) ;
V_16 -> V_37 = V_63 ;
if ( ! F_26 ( V_15 ) ) {
struct V_121 V_122 ;
F_33 ( & V_122 . V_21 , & V_16 -> V_22 ) ;
V_122 . V_123 = 0x00 ;
F_93 ( V_15 , V_124 , sizeof( V_122 ) , & V_122 ) ;
} else {
struct V_125 V_122 ;
F_33 ( & V_122 . V_21 , & V_16 -> V_22 ) ;
V_122 . V_126 = F_94 ( V_16 -> V_126 ) ;
V_122 . V_127 = F_95 ( 0x00001f40 ) ;
V_122 . V_128 = F_95 ( 0x00001f40 ) ;
V_122 . V_129 = F_94 ( V_32 ) ;
switch ( V_32 & V_130 ) {
case V_131 :
if ( V_16 -> V_126 & V_132 )
V_122 . V_133 = F_96 ( 0x0008 ) ;
else
V_122 . V_133 = F_96 ( 0x000D ) ;
V_122 . V_134 = 0x02 ;
break;
case V_135 :
V_122 . V_133 = F_96 ( 0xffff ) ;
V_122 . V_134 = 0xff ;
break;
}
F_93 ( V_15 , V_136 ,
sizeof( V_122 ) , & V_122 ) ;
}
}
static int F_97 ( struct V_117 * V_118 , struct V_71 * V_2 ,
struct V_41 * V_42 , T_3 V_43 , int V_69 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_137 * V_138 = F_27 ( V_3 ) ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 == V_67 &&
F_98 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ) {
F_92 ( V_138 -> V_16 -> V_13 , V_138 -> V_32 ) ;
V_3 -> V_4 = V_63 ;
V_42 -> V_140 = 0 ;
F_60 ( V_3 ) ;
return 0 ;
}
F_60 ( V_3 ) ;
return F_99 ( V_118 , V_2 , V_42 , V_43 , V_69 ) ;
}
static int F_100 ( struct V_71 * V_2 , int V_141 , int V_142 , char T_5 * V_143 , unsigned int V_144 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_25 = 0 ;
struct V_145 V_146 ;
T_6 V_147 ;
F_2 ( L_7 , V_3 ) ;
F_59 ( V_3 ) ;
switch ( V_142 ) {
case V_148 :
if ( V_3 -> V_4 != V_99 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_101 ( V_147 , ( T_6 T_5 * ) V_143 ) ) {
V_25 = - V_50 ;
break;
}
if ( V_147 )
F_102 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ;
else
F_103 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ;
break;
case V_149 :
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_99 &&
V_3 -> V_4 != V_67 ) {
V_25 = - V_46 ;
break;
}
V_146 . V_32 = F_27 ( V_3 ) -> V_32 ;
V_43 = F_104 (unsigned int, sizeof(voice), optlen) ;
if ( F_105 ( ( char * ) & V_146 , V_143 , V_43 ) ) {
V_25 = - V_50 ;
break;
}
if ( V_146 . V_32 != V_33 &&
V_146 . V_32 != V_81 ) {
V_25 = - V_46 ;
break;
}
F_27 ( V_3 ) -> V_32 = V_146 . V_32 ;
break;
default:
V_25 = - V_150 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_106 ( struct V_71 * V_2 , int V_142 , char T_5 * V_143 , int T_5 * V_144 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_151 V_152 ;
struct V_153 V_154 ;
int V_43 , V_25 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_101 ( V_43 , V_144 ) )
return - V_50 ;
F_59 ( V_3 ) ;
switch ( V_142 ) {
case V_155 :
if ( V_3 -> V_4 != V_38 &&
! ( V_3 -> V_4 == V_67 &&
F_98 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ) ) {
V_25 = - V_120 ;
break;
}
V_152 . V_24 = F_27 ( V_3 ) -> V_16 -> V_24 ;
F_2 ( L_18 , V_152 . V_24 ) ;
V_43 = F_104 (unsigned int, len, sizeof(opts)) ;
if ( F_107 ( V_143 , ( char * ) & V_152 , V_43 ) )
V_25 = - V_50 ;
break;
case V_156 :
if ( V_3 -> V_4 != V_38 &&
! ( V_3 -> V_4 == V_67 &&
F_98 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ) ) {
V_25 = - V_120 ;
break;
}
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_157 = F_27 ( V_3 ) -> V_16 -> V_13 -> V_158 ;
memcpy ( V_154 . V_159 , F_27 ( V_3 ) -> V_16 -> V_13 -> V_159 , 3 ) ;
V_43 = F_104 (unsigned int, len, sizeof(cinfo)) ;
if ( F_107 ( V_143 , ( char * ) & V_154 , V_43 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_150 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_108 ( struct V_71 * V_2 , int V_141 , int V_142 , char T_5 * V_143 , int T_5 * V_144 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_43 , V_25 = 0 ;
struct V_145 V_146 ;
F_2 ( L_7 , V_3 ) ;
if ( V_141 == V_160 )
return F_106 ( V_2 , V_142 , V_143 , V_144 ) ;
if ( F_101 ( V_43 , V_144 ) )
return - V_50 ;
F_59 ( V_3 ) ;
switch ( V_142 ) {
case V_148 :
if ( V_3 -> V_4 != V_99 && V_3 -> V_4 != V_53 ) {
V_25 = - V_46 ;
break;
}
if ( F_109 ( F_98 ( V_139 , & F_23 ( V_3 ) -> V_69 ) ,
( T_6 T_5 * ) V_143 ) )
V_25 = - V_50 ;
break;
case V_149 :
V_146 . V_32 = F_27 ( V_3 ) -> V_32 ;
V_43 = F_104 (unsigned int, len, sizeof(voice)) ;
if ( F_107 ( V_143 , ( char * ) & V_146 , V_43 ) )
V_25 = - V_50 ;
break;
default:
V_25 = - V_150 ;
break;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_110 ( struct V_71 * V_2 , int V_161 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_59 ( V_3 ) ;
if ( ! V_3 -> V_162 ) {
V_3 -> V_162 = V_163 ;
F_9 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( F_56 ( V_3 , V_164 ) && V_3 -> V_165 )
V_25 = F_73 ( V_3 , V_59 ,
V_3 -> V_165 ) ;
}
F_60 ( V_3 ) ;
return V_25 ;
}
static int F_111 ( struct V_71 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_25 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_54 ( V_3 ) ;
if ( F_56 ( V_3 , V_164 ) && V_3 -> V_165 ) {
F_59 ( V_3 ) ;
V_25 = F_73 ( V_3 , V_59 , V_3 -> V_165 ) ;
F_60 ( V_3 ) ;
}
F_112 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_25 ;
}
static void F_21 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_26 )
{
F_2 ( L_17 , V_16 ) ;
F_27 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_26 )
F_113 ( V_26 , V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_25 )
{
struct V_11 * V_16 ;
V_16 = F_27 ( V_3 ) -> V_16 ;
F_2 ( L_19 , V_3 , V_16 , V_25 ) ;
if ( V_16 ) {
F_15 ( V_16 ) ;
V_16 -> V_3 = NULL ;
F_27 ( V_3 ) -> V_16 = NULL ;
F_16 ( V_16 ) ;
if ( V_16 -> V_13 )
F_32 ( V_16 -> V_13 ) ;
}
V_3 -> V_4 = V_59 ;
V_3 -> V_5 = V_25 ;
V_3 -> V_7 ( V_3 ) ;
F_55 ( V_3 , V_60 ) ;
}
static void F_114 ( struct V_11 * V_16 )
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
V_26 = F_47 ( V_16 -> V_20 ) ;
if ( ! V_26 ) {
F_16 ( V_16 ) ;
return;
}
F_3 ( V_26 ) ;
V_3 = F_63 ( F_115 ( V_26 ) , NULL ,
V_166 , V_89 ) ;
if ( ! V_3 ) {
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
return;
}
F_61 ( V_3 , V_26 ) ;
F_33 ( & F_23 ( V_3 ) -> V_20 , V_16 -> V_20 ) ;
F_33 ( & F_23 ( V_3 ) -> V_22 , V_16 -> V_22 ) ;
F_116 ( V_16 -> V_13 ) ;
F_21 ( V_16 , V_3 , V_26 ) ;
if ( F_98 ( V_139 , & F_23 ( V_26 ) -> V_69 ) )
V_3 -> V_4 = V_67 ;
else
V_3 -> V_4 = V_38 ;
V_26 -> V_167 ( V_26 , 1 ) ;
F_4 ( V_26 ) ;
F_16 ( V_16 ) ;
}
}
int F_117 ( struct V_14 * V_15 , T_1 * V_21 , T_7 * V_69 )
{
struct V_2 * V_3 ;
int V_168 = 0 ;
F_2 ( L_20 , V_15 -> V_169 , V_21 ) ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_23 ( V_3 ) -> V_20 , & V_15 -> V_21 ) ||
! F_46 ( & F_23 ( V_3 ) -> V_20 , V_56 ) ) {
V_168 |= V_170 ;
if ( F_98 ( V_139 , & F_23 ( V_3 ) -> V_69 ) )
* V_69 |= V_171 ;
break;
}
}
F_49 ( & V_55 . V_19 ) ;
return V_168 ;
}
void F_118 ( struct V_12 * V_13 , T_7 V_172 )
{
F_2 ( L_21 , V_13 , & V_13 -> V_22 , V_172 ) ;
if ( ! V_172 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_114 ( V_16 ) ;
} else
F_17 ( V_13 , F_119 ( V_172 ) ) ;
}
void F_120 ( struct V_12 * V_13 , T_7 V_173 )
{
F_2 ( L_22 , V_13 , V_173 ) ;
F_17 ( V_13 , F_119 ( V_173 ) ) ;
}
int F_121 ( struct V_12 * V_13 , struct V_44 * V_45 )
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
static int F_122 ( struct V_174 * V_175 , void * V_176 )
{
struct V_2 * V_3 ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
F_123 ( V_175 , L_24 , & F_23 ( V_3 ) -> V_20 ,
& F_23 ( V_3 ) -> V_22 , V_3 -> V_4 ) ;
}
F_49 ( & V_55 . V_19 ) ;
return 0 ;
}
static int F_124 ( struct V_177 * V_177 , struct V_178 * V_178 )
{
return F_125 ( V_178 , F_122 , V_177 -> V_179 ) ;
}
int T_8 F_126 ( void )
{
int V_25 ;
V_25 = F_127 ( & V_75 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_128 ( V_166 , & V_180 ) ;
if ( V_25 < 0 ) {
F_129 ( L_25 ) ;
goto error;
}
V_25 = F_130 ( & V_181 , L_26 , & V_55 , NULL ) ;
if ( V_25 < 0 ) {
F_129 ( L_27 ) ;
F_131 ( V_166 ) ;
goto error;
}
if ( V_182 ) {
V_183 = F_132 ( L_26 , 0444 , V_182 ,
NULL , & V_184 ) ;
if ( ! V_183 )
F_129 ( L_28 ) ;
}
F_133 ( L_29 ) ;
return 0 ;
error:
F_134 ( & V_75 ) ;
return V_25 ;
}
void T_9 F_135 ( void )
{
F_136 ( & V_181 , L_26 ) ;
F_137 ( V_183 ) ;
F_131 ( V_166 ) ;
F_134 ( & V_75 ) ;
}
