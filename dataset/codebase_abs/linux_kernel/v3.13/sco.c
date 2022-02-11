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
if ( V_15 -> V_20 > 0 )
V_16 -> V_21 = V_15 -> V_20 ;
else
V_16 -> V_21 = 60 ;
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
static int F_17 ( struct V_12 * V_13 , int V_22 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
struct V_2 * V_3 ;
if ( ! V_16 )
return 0 ;
F_2 ( L_4 , V_13 , V_16 , V_22 ) ;
V_3 = F_14 ( V_16 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_9 ( V_3 ) ;
F_18 ( V_3 , V_22 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_13 -> V_17 = NULL ;
F_19 ( V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_23 )
{
int V_22 = 0 ;
F_15 ( V_16 ) ;
if ( V_16 -> V_3 )
V_22 = - V_24 ;
else
F_21 ( V_16 , V_3 , V_23 ) ;
F_16 ( V_16 ) ;
return V_22 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_22 , type ;
F_2 ( L_5 , & F_23 ( V_3 ) -> V_25 , & F_23 ( V_3 ) -> V_26 ) ;
V_15 = F_24 ( & F_23 ( V_3 ) -> V_26 , & F_23 ( V_3 ) -> V_25 ) ;
if ( ! V_15 )
return - V_27 ;
F_25 ( V_15 ) ;
if ( F_26 ( V_15 ) && ! V_28 )
type = V_29 ;
else
type = V_30 ;
if ( F_23 ( V_3 ) -> V_31 == V_32 &&
( ! F_27 ( V_15 ) || ! F_26 ( V_15 ) ) ) {
V_22 = - V_33 ;
goto V_34;
}
V_13 = F_28 ( V_15 , type , & F_23 ( V_3 ) -> V_26 ,
F_23 ( V_3 ) -> V_31 ) ;
if ( F_29 ( V_13 ) ) {
V_22 = F_30 ( V_13 ) ;
goto V_34;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_31 ( V_13 ) ;
V_22 = - V_35 ;
goto V_34;
}
F_32 ( & F_23 ( V_3 ) -> V_25 , & V_13 -> V_25 ) ;
V_22 = F_20 ( V_16 , V_3 , NULL ) ;
if ( V_22 )
goto V_34;
if ( V_13 -> V_36 == V_37 ) {
F_9 ( V_3 ) ;
V_3 -> V_4 = V_37 ;
} else {
V_3 -> V_4 = V_38 ;
F_7 ( V_3 , V_3 -> V_39 ) ;
}
V_34:
F_33 ( V_15 ) ;
F_34 ( V_15 ) ;
return V_22 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_40 * V_41 , int V_42 )
{
struct V_11 * V_16 = F_23 ( V_3 ) -> V_16 ;
struct V_43 * V_44 ;
int V_22 ;
if ( V_42 > V_16 -> V_21 )
return - V_45 ;
F_2 ( L_6 , V_3 , V_42 ) ;
V_44 = F_36 ( V_3 , V_42 , V_41 -> V_46 & V_47 , & V_22 ) ;
if ( ! V_44 )
return V_22 ;
if ( F_37 ( F_38 ( V_44 , V_42 ) , V_41 -> V_48 , V_42 ) ) {
F_39 ( V_44 ) ;
return - V_49 ;
}
F_40 ( V_16 -> V_13 , V_44 ) ;
return V_42 ;
}
static void F_41 ( struct V_11 * V_16 , struct V_43 * V_44 )
{
struct V_2 * V_3 = F_14 ( V_16 ) ;
if ( ! V_3 )
goto V_50;
F_2 ( L_6 , V_3 , V_44 -> V_42 ) ;
if ( V_3 -> V_4 != V_37 )
goto V_50;
if ( ! F_42 ( V_3 , V_44 ) )
return;
V_50:
F_39 ( V_44 ) ;
}
static struct V_2 * F_43 ( T_1 * V_51 )
{
struct V_2 * V_3 ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_52 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_25 , V_51 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_46 ( T_1 * V_25 )
{
struct V_2 * V_3 = NULL , * V_53 = NULL ;
F_47 ( & V_54 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_52 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_25 , V_25 ) )
break;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_25 , V_55 ) )
V_53 = V_3 ;
}
F_48 ( & V_54 . V_19 ) ;
return V_3 ? V_3 : V_53 ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_2 ( L_7 , V_3 ) ;
F_50 ( & V_3 -> V_56 ) ;
F_50 ( & V_3 -> V_57 ) ;
}
static void F_51 ( struct V_2 * V_23 )
{
struct V_2 * V_3 ;
F_2 ( L_8 , V_23 ) ;
while ( ( V_3 = F_52 ( V_23 , NULL ) ) ) {
F_53 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_23 -> V_4 = V_58 ;
F_54 ( V_23 , V_59 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_55 ( V_3 , V_59 ) || V_3 -> V_60 )
return;
F_2 ( L_9 , V_3 , V_3 -> V_4 ) ;
F_56 ( & V_54 , V_3 ) ;
F_54 ( V_3 , V_61 ) ;
F_6 ( V_3 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_2 ( L_10 , V_3 , V_3 -> V_4 , V_3 -> V_60 ) ;
switch ( V_3 -> V_4 ) {
case V_52 :
F_51 ( V_3 ) ;
break;
case V_37 :
case V_62 :
if ( F_23 ( V_3 ) -> V_16 -> V_13 ) {
V_3 -> V_4 = V_63 ;
F_7 ( V_3 , V_64 ) ;
F_31 ( F_23 ( V_3 ) -> V_16 -> V_13 ) ;
F_23 ( V_3 ) -> V_16 -> V_13 = NULL ;
} else
F_18 ( V_3 , V_65 ) ;
break;
case V_66 :
case V_38 :
case V_63 :
F_18 ( V_3 , V_65 ) ;
break;
default:
F_54 ( V_3 , V_59 ) ;
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
static void F_60 ( struct V_2 * V_3 , struct V_2 * V_23 )
{
F_2 ( L_7 , V_3 ) ;
if ( V_23 ) {
V_3 -> V_67 = V_23 -> V_67 ;
F_61 ( V_3 ) -> V_68 = F_61 ( V_23 ) -> V_68 ;
F_62 ( V_23 , V_3 ) ;
}
}
static struct V_2 * F_63 ( struct V_69 * V_69 , struct V_70 * V_2 , int V_71 , T_2 V_72 )
{
struct V_2 * V_3 ;
V_3 = F_64 ( V_69 , V_73 , V_72 , & V_74 ) ;
if ( ! V_3 )
return NULL ;
F_65 ( V_2 , V_3 ) ;
F_66 ( & F_61 ( V_3 ) -> V_75 ) ;
V_3 -> V_76 = F_49 ;
V_3 -> V_39 = V_77 ;
F_67 ( V_3 , V_59 ) ;
V_3 -> V_78 = V_71 ;
V_3 -> V_4 = V_79 ;
F_23 ( V_3 ) -> V_31 = V_80 ;
F_68 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_69 ( & V_54 , V_3 ) ;
return V_3 ;
}
static int F_70 ( struct V_69 * V_69 , struct V_70 * V_2 , int V_81 ,
int V_82 )
{
struct V_2 * V_3 ;
F_2 ( L_11 , V_2 ) ;
V_2 -> V_36 = V_83 ;
if ( V_2 -> type != V_84 )
return - V_85 ;
V_2 -> V_86 = & V_87 ;
V_3 = F_63 ( V_69 , V_2 , V_81 , V_88 ) ;
if ( ! V_3 )
return - V_35 ;
F_60 ( V_3 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_70 * V_2 , struct V_89 * V_90 , int V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_12 , V_3 , & V_93 -> V_94 ) ;
if ( ! V_90 || V_90 -> V_95 != V_96 )
return - V_45 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_79 ) {
V_22 = - V_97 ;
goto V_34;
}
if ( V_3 -> V_67 != V_84 ) {
V_22 = - V_45 ;
goto V_34;
}
F_32 ( & F_23 ( V_3 ) -> V_25 , & V_93 -> V_94 ) ;
V_3 -> V_4 = V_98 ;
V_34:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_72 ( struct V_70 * V_2 , struct V_89 * V_90 , int V_99 , int V_68 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_7 , V_3 ) ;
if ( V_99 < sizeof( struct V_92 ) ||
V_90 -> V_95 != V_96 )
return - V_45 ;
if ( V_3 -> V_4 != V_79 && V_3 -> V_4 != V_98 )
return - V_97 ;
if ( V_3 -> V_67 != V_84 )
return - V_45 ;
F_58 ( V_3 ) ;
F_32 ( & F_23 ( V_3 ) -> V_26 , & V_93 -> V_94 ) ;
V_22 = F_22 ( V_3 ) ;
if ( V_22 )
goto V_34;
V_22 = F_73 ( V_3 , V_37 ,
F_74 ( V_3 , V_68 & V_100 ) ) ;
V_34:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_75 ( struct V_70 * V_2 , int V_101 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_25 = & F_23 ( V_3 ) -> V_25 ;
int V_22 = 0 ;
F_2 ( L_13 , V_3 , V_101 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_98 ) {
V_22 = - V_97 ;
goto V_34;
}
if ( V_3 -> V_67 != V_84 ) {
V_22 = - V_45 ;
goto V_34;
}
F_76 ( & V_54 . V_19 ) ;
if ( F_43 ( V_25 ) ) {
V_22 = - V_102 ;
goto V_103;
}
V_3 -> V_104 = V_101 ;
V_3 -> V_105 = 0 ;
V_3 -> V_4 = V_52 ;
V_103:
F_77 ( & V_54 . V_19 ) ;
V_34:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_78 ( struct V_70 * V_2 , struct V_70 * V_106 , int V_68 )
{
F_79 ( V_107 , V_108 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_109 ;
long V_110 ;
int V_22 = 0 ;
F_58 ( V_3 ) ;
V_110 = F_80 ( V_3 , V_68 & V_100 ) ;
F_2 ( L_14 , V_3 , V_110 ) ;
F_81 ( F_82 ( V_3 ) , & V_107 ) ;
while ( 1 ) {
F_83 ( V_111 ) ;
if ( V_3 -> V_4 != V_52 ) {
V_22 = - V_97 ;
break;
}
V_109 = F_52 ( V_3 , V_106 ) ;
if ( V_109 )
break;
if ( ! V_110 ) {
V_22 = - V_112 ;
break;
}
if ( F_84 ( V_108 ) ) {
V_22 = F_85 ( V_110 ) ;
break;
}
F_59 ( V_3 ) ;
V_110 = F_86 ( V_110 ) ;
F_58 ( V_3 ) ;
}
F_87 ( V_113 ) ;
F_88 ( F_82 ( V_3 ) , & V_107 ) ;
if ( V_22 )
goto V_34;
V_106 -> V_36 = V_114 ;
F_2 ( L_15 , V_109 ) ;
V_34:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_89 ( struct V_70 * V_2 , struct V_89 * V_90 , int * V_42 , int V_115 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_90 -> V_95 = V_96 ;
* V_42 = sizeof( struct V_92 ) ;
if ( V_115 )
F_32 ( & V_93 -> V_94 , & F_23 ( V_3 ) -> V_26 ) ;
else
F_32 ( & V_93 -> V_94 , & F_23 ( V_3 ) -> V_25 ) ;
return 0 ;
}
static int F_90 ( struct V_116 * V_117 , struct V_70 * V_2 ,
struct V_40 * V_41 , T_3 V_42 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_16 , V_2 , V_3 ) ;
V_22 = F_91 ( V_3 ) ;
if ( V_22 )
return V_22 ;
if ( V_41 -> V_46 & V_118 )
return - V_33 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_37 )
V_22 = F_35 ( V_3 , V_41 , V_42 ) ;
else
V_22 = - V_119 ;
F_59 ( V_3 ) ;
return V_22 ;
}
static void F_92 ( struct V_12 * V_16 , T_4 V_31 )
{
struct V_14 * V_15 = V_16 -> V_15 ;
F_2 ( L_17 , V_16 ) ;
V_16 -> V_36 = V_62 ;
if ( ! F_26 ( V_15 ) ) {
struct V_120 V_121 ;
F_32 ( & V_121 . V_122 , & V_16 -> V_26 ) ;
V_121 . V_123 = 0x00 ;
F_93 ( V_15 , V_124 , sizeof( V_121 ) , & V_121 ) ;
} else {
struct V_125 V_121 ;
F_32 ( & V_121 . V_122 , & V_16 -> V_26 ) ;
V_121 . V_126 = F_94 ( V_16 -> V_126 ) ;
V_121 . V_127 = F_95 ( 0x00001f40 ) ;
V_121 . V_128 = F_95 ( 0x00001f40 ) ;
V_121 . V_129 = F_94 ( V_31 ) ;
switch ( V_31 & V_130 ) {
case V_131 :
if ( V_16 -> V_126 & V_132 )
V_121 . V_133 = F_96 ( 0x0008 ) ;
else
V_121 . V_133 = F_96 ( 0x000D ) ;
V_121 . V_134 = 0x02 ;
break;
case V_135 :
V_121 . V_133 = F_96 ( 0xffff ) ;
V_121 . V_134 = 0xff ;
break;
}
F_93 ( V_15 , V_136 ,
sizeof( V_121 ) , & V_121 ) ;
}
}
static int F_97 ( struct V_116 * V_117 , struct V_70 * V_2 ,
struct V_40 * V_41 , T_3 V_42 , int V_68 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_137 * V_138 = F_23 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_66 &&
F_98 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ) {
F_92 ( V_138 -> V_16 -> V_13 , V_138 -> V_31 ) ;
V_3 -> V_4 = V_62 ;
F_59 ( V_3 ) ;
return 0 ;
}
F_59 ( V_3 ) ;
return F_99 ( V_117 , V_2 , V_41 , V_42 , V_68 ) ;
}
static int F_100 ( struct V_70 * V_2 , int V_140 , int V_141 , char T_5 * V_142 , unsigned int V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_42 , V_22 = 0 ;
struct V_144 V_145 ;
T_6 V_146 ;
F_2 ( L_7 , V_3 ) ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_147 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_52 ) {
V_22 = - V_45 ;
break;
}
if ( F_101 ( V_146 , ( T_6 T_5 * ) V_142 ) ) {
V_22 = - V_49 ;
break;
}
if ( V_146 )
F_102 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ;
else
F_103 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ;
break;
case V_148 :
if ( V_3 -> V_4 != V_79 && V_3 -> V_4 != V_98 &&
V_3 -> V_4 != V_66 ) {
V_22 = - V_45 ;
break;
}
V_145 . V_31 = F_23 ( V_3 ) -> V_31 ;
V_42 = F_104 (unsigned int, sizeof(voice), optlen) ;
if ( F_105 ( ( char * ) & V_145 , V_142 , V_42 ) ) {
V_22 = - V_49 ;
break;
}
if ( V_145 . V_31 != V_32 &&
V_145 . V_31 != V_80 ) {
V_22 = - V_45 ;
break;
}
F_23 ( V_3 ) -> V_31 = V_145 . V_31 ;
break;
default:
V_22 = - V_149 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_106 ( struct V_70 * V_2 , int V_141 , char T_5 * V_142 , int T_5 * V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_150 V_151 ;
struct V_152 V_153 ;
int V_42 , V_22 = 0 ;
F_2 ( L_7 , V_3 ) ;
if ( F_101 ( V_42 , V_143 ) )
return - V_49 ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_154 :
if ( V_3 -> V_4 != V_37 &&
! ( V_3 -> V_4 == V_66 &&
F_98 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ) ) {
V_22 = - V_119 ;
break;
}
V_151 . V_21 = F_23 ( V_3 ) -> V_16 -> V_21 ;
F_2 ( L_18 , V_151 . V_21 ) ;
V_42 = F_104 (unsigned int, len, sizeof(opts)) ;
if ( F_107 ( V_142 , ( char * ) & V_151 , V_42 ) )
V_22 = - V_49 ;
break;
case V_155 :
if ( V_3 -> V_4 != V_37 &&
! ( V_3 -> V_4 == V_66 &&
F_98 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ) ) {
V_22 = - V_119 ;
break;
}
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
V_153 . V_156 = F_23 ( V_3 ) -> V_16 -> V_13 -> V_157 ;
memcpy ( V_153 . V_158 , F_23 ( V_3 ) -> V_16 -> V_13 -> V_158 , 3 ) ;
V_42 = F_104 (unsigned int, len, sizeof(cinfo)) ;
if ( F_107 ( V_142 , ( char * ) & V_153 , V_42 ) )
V_22 = - V_49 ;
break;
default:
V_22 = - V_149 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_108 ( struct V_70 * V_2 , int V_140 , int V_141 , char T_5 * V_142 , int T_5 * V_143 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_42 , V_22 = 0 ;
struct V_144 V_145 ;
F_2 ( L_7 , V_3 ) ;
if ( V_140 == V_159 )
return F_106 ( V_2 , V_141 , V_142 , V_143 ) ;
if ( F_101 ( V_42 , V_143 ) )
return - V_49 ;
F_58 ( V_3 ) ;
switch ( V_141 ) {
case V_147 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_52 ) {
V_22 = - V_45 ;
break;
}
if ( F_109 ( F_98 ( V_139 , & F_61 ( V_3 ) -> V_68 ) ,
( T_6 T_5 * ) V_142 ) )
V_22 = - V_49 ;
break;
case V_148 :
V_145 . V_31 = F_23 ( V_3 ) -> V_31 ;
V_42 = F_104 (unsigned int, len, sizeof(voice)) ;
if ( F_107 ( V_142 , ( char * ) & V_145 , V_42 ) )
V_22 = - V_49 ;
break;
default:
V_22 = - V_149 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_110 ( struct V_70 * V_2 , int V_160 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_58 ( V_3 ) ;
if ( ! V_3 -> V_161 ) {
V_3 -> V_161 = V_162 ;
F_9 ( V_3 ) ;
F_57 ( V_3 ) ;
if ( F_55 ( V_3 , V_163 ) && V_3 -> V_164 )
V_22 = F_73 ( V_3 , V_58 ,
V_3 -> V_164 ) ;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_111 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_16 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_53 ( V_3 ) ;
if ( F_55 ( V_3 , V_163 ) && V_3 -> V_164 ) {
F_58 ( V_3 ) ;
V_22 = F_73 ( V_3 , V_58 , V_3 -> V_164 ) ;
F_59 ( V_3 ) ;
}
F_112 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_22 ;
}
static void F_21 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_23 )
{
F_2 ( L_17 , V_16 ) ;
F_23 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_23 )
F_113 ( V_23 , V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 , int V_22 )
{
struct V_11 * V_16 ;
V_16 = F_23 ( V_3 ) -> V_16 ;
F_2 ( L_19 , V_3 , V_16 , V_22 ) ;
if ( V_16 ) {
F_15 ( V_16 ) ;
V_16 -> V_3 = NULL ;
F_23 ( V_3 ) -> V_16 = NULL ;
F_16 ( V_16 ) ;
if ( V_16 -> V_13 )
F_31 ( V_16 -> V_13 ) ;
}
V_3 -> V_4 = V_58 ;
V_3 -> V_5 = V_22 ;
V_3 -> V_7 ( V_3 ) ;
F_54 ( V_3 , V_59 ) ;
}
static void F_114 ( struct V_11 * V_16 )
{
struct V_2 * V_23 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_17 , V_16 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_37 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
F_15 ( V_16 ) ;
V_23 = F_46 ( & V_16 -> V_13 -> V_25 ) ;
if ( ! V_23 ) {
F_16 ( V_16 ) ;
return;
}
F_3 ( V_23 ) ;
V_3 = F_63 ( F_115 ( V_23 ) , NULL ,
V_165 , V_88 ) ;
if ( ! V_3 ) {
F_4 ( V_23 ) ;
F_16 ( V_16 ) ;
return;
}
F_60 ( V_3 , V_23 ) ;
F_32 ( & F_23 ( V_3 ) -> V_25 , & V_16 -> V_13 -> V_25 ) ;
F_32 ( & F_23 ( V_3 ) -> V_26 , & V_16 -> V_13 -> V_26 ) ;
F_116 ( V_16 -> V_13 ) ;
F_21 ( V_16 , V_3 , V_23 ) ;
if ( F_98 ( V_139 , & F_61 ( V_23 ) -> V_68 ) )
V_3 -> V_4 = V_66 ;
else
V_3 -> V_4 = V_37 ;
V_23 -> V_166 ( V_23 , 1 ) ;
F_4 ( V_23 ) ;
F_16 ( V_16 ) ;
}
}
int F_117 ( struct V_14 * V_15 , T_1 * V_122 , T_7 * V_68 )
{
struct V_2 * V_3 ;
int V_167 = 0 ;
F_2 ( L_20 , V_15 -> V_168 , V_122 ) ;
F_47 ( & V_54 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_52 )
continue;
if ( ! F_45 ( & F_23 ( V_3 ) -> V_25 , & V_15 -> V_122 ) ||
! F_45 ( & F_23 ( V_3 ) -> V_25 , V_55 ) ) {
V_167 |= V_169 ;
if ( F_98 ( V_139 , & F_61 ( V_3 ) -> V_68 ) )
* V_68 |= V_170 ;
break;
}
}
F_48 ( & V_54 . V_19 ) ;
return V_167 ;
}
void F_118 ( struct V_12 * V_13 , T_7 V_171 )
{
F_2 ( L_21 , V_13 , & V_13 -> V_26 , V_171 ) ;
if ( ! V_171 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_114 ( V_16 ) ;
} else
F_17 ( V_13 , F_119 ( V_171 ) ) ;
}
void F_120 ( struct V_12 * V_13 , T_7 V_172 )
{
F_2 ( L_22 , V_13 , V_172 ) ;
F_17 ( V_13 , F_119 ( V_172 ) ) ;
}
int F_121 ( struct V_12 * V_13 , struct V_43 * V_44 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
if ( ! V_16 )
goto V_50;
F_2 ( L_23 , V_16 , V_44 -> V_42 ) ;
if ( V_44 -> V_42 ) {
F_41 ( V_16 , V_44 ) ;
return 0 ;
}
V_50:
F_39 ( V_44 ) ;
return 0 ;
}
static int F_122 ( struct V_173 * V_174 , void * V_175 )
{
struct V_2 * V_3 ;
F_47 ( & V_54 . V_19 ) ;
F_44 (sk, &sco_sk_list.head) {
F_123 ( V_174 , L_24 , & F_23 ( V_3 ) -> V_25 ,
& F_23 ( V_3 ) -> V_26 , V_3 -> V_4 ) ;
}
F_48 ( & V_54 . V_19 ) ;
return 0 ;
}
static int F_124 ( struct V_176 * V_176 , struct V_177 * V_177 )
{
return F_125 ( V_177 , F_122 , V_176 -> V_178 ) ;
}
int T_8 F_126 ( void )
{
int V_22 ;
V_22 = F_127 ( & V_74 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_128 ( V_165 , & V_179 ) ;
if ( V_22 < 0 ) {
F_129 ( L_25 ) ;
goto error;
}
V_22 = F_130 ( & V_180 , L_26 , & V_54 , NULL ) ;
if ( V_22 < 0 ) {
F_129 ( L_27 ) ;
F_131 ( V_165 ) ;
goto error;
}
F_132 ( L_28 ) ;
if ( F_133 ( V_181 ) )
return 0 ;
V_182 = F_134 ( L_26 , 0444 , V_181 ,
NULL , & V_183 ) ;
return 0 ;
error:
F_135 ( & V_74 ) ;
return V_22 ;
}
void T_9 F_136 ( void )
{
F_137 ( & V_180 , L_26 ) ;
F_138 ( V_182 ) ;
F_131 ( V_165 ) ;
F_135 ( & V_74 ) ;
}
