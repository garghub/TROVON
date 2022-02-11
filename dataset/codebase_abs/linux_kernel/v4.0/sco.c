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
static void F_14 ( struct V_2 * V_3 , int V_22 )
{
struct V_11 * V_16 ;
V_16 = F_15 ( V_3 ) -> V_16 ;
F_2 ( L_4 , V_3 , V_16 , V_22 ) ;
if ( V_16 ) {
F_16 ( V_16 ) ;
V_16 -> V_3 = NULL ;
F_15 ( V_3 ) -> V_16 = NULL ;
F_17 ( V_16 ) ;
if ( V_16 -> V_13 )
F_18 ( V_16 -> V_13 ) ;
}
V_3 -> V_4 = V_23 ;
V_3 -> V_5 = V_22 ;
V_3 -> V_7 ( V_3 ) ;
F_19 ( V_3 , V_24 ) ;
}
static int F_20 ( struct V_12 * V_13 , int V_22 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
struct V_2 * V_3 ;
if ( ! V_16 )
return 0 ;
F_2 ( L_5 , V_13 , V_16 , V_22 ) ;
F_16 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
F_17 ( V_16 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_9 ( V_3 ) ;
F_14 ( V_3 , V_22 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_13 -> V_17 = NULL ;
F_21 ( V_16 ) ;
return 0 ;
}
static void F_22 ( struct V_11 * V_16 , struct V_2 * V_3 , struct V_2 * V_25 )
{
F_2 ( L_6 , V_16 ) ;
F_15 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_25 )
F_23 ( V_25 , V_3 ) ;
}
static int F_24 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_25 )
{
int V_22 = 0 ;
F_16 ( V_16 ) ;
if ( V_16 -> V_3 )
V_22 = - V_26 ;
else
F_22 ( V_16 , V_3 , V_25 ) ;
F_17 ( V_16 ) ;
return V_22 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_22 , type ;
F_2 ( L_7 , & F_15 ( V_3 ) -> V_27 , & F_15 ( V_3 ) -> V_28 ) ;
V_15 = F_26 ( & F_15 ( V_3 ) -> V_28 , & F_15 ( V_3 ) -> V_27 ) ;
if ( ! V_15 )
return - V_29 ;
F_27 ( V_15 ) ;
if ( F_28 ( V_15 ) && ! V_30 )
type = V_31 ;
else
type = V_32 ;
if ( F_15 ( V_3 ) -> V_33 == V_34 &&
( ! F_29 ( V_15 ) || ! F_28 ( V_15 ) ) ) {
V_22 = - V_35 ;
goto V_36;
}
V_13 = F_30 ( V_15 , type , & F_15 ( V_3 ) -> V_28 ,
F_15 ( V_3 ) -> V_33 ) ;
if ( F_31 ( V_13 ) ) {
V_22 = F_32 ( V_13 ) ;
goto V_36;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_18 ( V_13 ) ;
V_22 = - V_37 ;
goto V_36;
}
F_33 ( & F_15 ( V_3 ) -> V_27 , & V_13 -> V_27 ) ;
V_22 = F_24 ( V_16 , V_3 , NULL ) ;
if ( V_22 )
goto V_36;
if ( V_13 -> V_38 == V_39 ) {
F_9 ( V_3 ) ;
V_3 -> V_4 = V_39 ;
} else {
V_3 -> V_4 = V_40 ;
F_7 ( V_3 , V_3 -> V_41 ) ;
}
V_36:
F_34 ( V_15 ) ;
F_35 ( V_15 ) ;
return V_22 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_42 * V_43 , int V_44 )
{
struct V_11 * V_16 = F_15 ( V_3 ) -> V_16 ;
struct V_45 * V_46 ;
int V_22 ;
if ( V_44 > V_16 -> V_21 )
return - V_47 ;
F_2 ( L_8 , V_3 , V_44 ) ;
V_46 = F_37 ( V_3 , V_44 , V_43 -> V_48 & V_49 , & V_22 ) ;
if ( ! V_46 )
return V_22 ;
if ( F_38 ( F_39 ( V_46 , V_44 ) , V_43 , V_44 ) ) {
F_40 ( V_46 ) ;
return - V_50 ;
}
F_41 ( V_16 -> V_13 , V_46 ) ;
return V_44 ;
}
static void F_42 ( struct V_11 * V_16 , struct V_45 * V_46 )
{
struct V_2 * V_3 ;
F_16 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
F_17 ( V_16 ) ;
if ( ! V_3 )
goto V_51;
F_2 ( L_8 , V_3 , V_46 -> V_44 ) ;
if ( V_3 -> V_4 != V_39 )
goto V_51;
if ( ! F_43 ( V_3 , V_46 ) )
return;
V_51:
F_40 ( V_46 ) ;
}
static struct V_2 * F_44 ( T_1 * V_52 )
{
struct V_2 * V_3 ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_15 ( V_3 ) -> V_27 , V_52 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_47 ( T_1 * V_27 )
{
struct V_2 * V_3 = NULL , * V_54 = NULL ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_15 ( V_3 ) -> V_27 , V_27 ) )
break;
if ( ! F_46 ( & F_15 ( V_3 ) -> V_27 , V_56 ) )
V_54 = V_3 ;
}
F_49 ( & V_55 . V_19 ) ;
return V_3 ? V_3 : V_54 ;
}
static void F_50 ( struct V_2 * V_3 )
{
F_2 ( L_9 , V_3 ) ;
F_51 ( & V_3 -> V_57 ) ;
F_51 ( & V_3 -> V_58 ) ;
}
static void F_52 ( struct V_2 * V_25 )
{
struct V_2 * V_3 ;
F_2 ( L_10 , V_25 ) ;
while ( ( V_3 = F_53 ( V_25 , NULL ) ) ) {
F_54 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_25 -> V_4 = V_23 ;
F_19 ( V_25 , V_24 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_55 ( V_3 , V_24 ) || V_3 -> V_59 )
return;
F_2 ( L_11 , V_3 , V_3 -> V_4 ) ;
F_56 ( & V_55 , V_3 ) ;
F_19 ( V_3 , V_60 ) ;
F_6 ( V_3 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
F_2 ( L_12 , V_3 , V_3 -> V_4 , V_3 -> V_59 ) ;
switch ( V_3 -> V_4 ) {
case V_53 :
F_52 ( V_3 ) ;
break;
case V_39 :
case V_61 :
if ( F_15 ( V_3 ) -> V_16 -> V_13 ) {
V_3 -> V_4 = V_62 ;
F_7 ( V_3 , V_63 ) ;
F_18 ( F_15 ( V_3 ) -> V_16 -> V_13 ) ;
F_15 ( V_3 ) -> V_16 -> V_13 = NULL ;
} else
F_14 ( V_3 , V_64 ) ;
break;
case V_65 :
case V_40 :
case V_62 :
F_14 ( V_3 , V_64 ) ;
break;
default:
F_19 ( V_3 , V_24 ) ;
break;
}
}
static void F_54 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_58 ( V_3 ) ;
F_57 ( V_3 ) ;
F_59 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_60 ( struct V_2 * V_3 , struct V_2 * V_25 )
{
F_2 ( L_9 , V_3 ) ;
if ( V_25 ) {
V_3 -> V_66 = V_25 -> V_66 ;
F_61 ( V_3 ) -> V_67 = F_61 ( V_25 ) -> V_67 ;
F_62 ( V_25 , V_3 ) ;
}
}
static struct V_2 * F_63 ( struct V_68 * V_68 , struct V_69 * V_2 , int V_70 , T_2 V_71 )
{
struct V_2 * V_3 ;
V_3 = F_64 ( V_68 , V_72 , V_71 , & V_73 ) ;
if ( ! V_3 )
return NULL ;
F_65 ( V_2 , V_3 ) ;
F_66 ( & F_61 ( V_3 ) -> V_74 ) ;
V_3 -> V_75 = F_50 ;
V_3 -> V_41 = V_76 ;
F_67 ( V_3 , V_24 ) ;
V_3 -> V_77 = V_70 ;
V_3 -> V_4 = V_78 ;
F_15 ( V_3 ) -> V_33 = V_79 ;
F_68 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_69 ( & V_55 , V_3 ) ;
return V_3 ;
}
static int F_70 ( struct V_68 * V_68 , struct V_69 * V_2 , int V_80 ,
int V_81 )
{
struct V_2 * V_3 ;
F_2 ( L_13 , V_2 ) ;
V_2 -> V_38 = V_82 ;
if ( V_2 -> type != V_83 )
return - V_84 ;
V_2 -> V_85 = & V_86 ;
V_3 = F_63 ( V_68 , V_2 , V_80 , V_87 ) ;
if ( ! V_3 )
return - V_37 ;
F_60 ( V_3 , NULL ) ;
return 0 ;
}
static int F_71 ( struct V_69 * V_2 , struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_14 , V_3 , & V_92 -> V_93 ) ;
if ( ! V_89 || V_89 -> V_94 != V_95 )
return - V_47 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_78 ) {
V_22 = - V_96 ;
goto V_36;
}
if ( V_3 -> V_66 != V_83 ) {
V_22 = - V_47 ;
goto V_36;
}
F_33 ( & F_15 ( V_3 ) -> V_27 , & V_92 -> V_93 ) ;
V_3 -> V_4 = V_97 ;
V_36:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_72 ( struct V_69 * V_2 , struct V_88 * V_89 , int V_98 , int V_67 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_9 , V_3 ) ;
if ( V_98 < sizeof( struct V_91 ) ||
V_89 -> V_94 != V_95 )
return - V_47 ;
if ( V_3 -> V_4 != V_78 && V_3 -> V_4 != V_97 )
return - V_96 ;
if ( V_3 -> V_66 != V_83 )
return - V_47 ;
F_58 ( V_3 ) ;
F_33 ( & F_15 ( V_3 ) -> V_28 , & V_92 -> V_93 ) ;
V_22 = F_25 ( V_3 ) ;
if ( V_22 )
goto V_36;
V_22 = F_73 ( V_3 , V_39 ,
F_74 ( V_3 , V_67 & V_99 ) ) ;
V_36:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_75 ( struct V_69 * V_2 , int V_100 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_27 = & F_15 ( V_3 ) -> V_27 ;
int V_22 = 0 ;
F_2 ( L_15 , V_3 , V_100 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 != V_97 ) {
V_22 = - V_96 ;
goto V_36;
}
if ( V_3 -> V_66 != V_83 ) {
V_22 = - V_47 ;
goto V_36;
}
F_76 ( & V_55 . V_19 ) ;
if ( F_44 ( V_27 ) ) {
V_22 = - V_101 ;
goto V_102;
}
V_3 -> V_103 = V_100 ;
V_3 -> V_104 = 0 ;
V_3 -> V_4 = V_53 ;
V_102:
F_77 ( & V_55 . V_19 ) ;
V_36:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_78 ( struct V_69 * V_2 , struct V_69 * V_105 , int V_67 )
{
F_79 ( V_106 , V_107 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_108 ;
long V_109 ;
int V_22 = 0 ;
F_58 ( V_3 ) ;
V_109 = F_80 ( V_3 , V_67 & V_99 ) ;
F_2 ( L_16 , V_3 , V_109 ) ;
F_81 ( F_82 ( V_3 ) , & V_106 ) ;
while ( 1 ) {
if ( V_3 -> V_4 != V_53 ) {
V_22 = - V_96 ;
break;
}
V_108 = F_53 ( V_3 , V_105 ) ;
if ( V_108 )
break;
if ( ! V_109 ) {
V_22 = - V_110 ;
break;
}
if ( F_83 ( V_111 ) ) {
V_22 = F_84 ( V_109 ) ;
break;
}
F_59 ( V_3 ) ;
V_109 = F_85 ( & V_106 , V_112 , V_109 ) ;
F_58 ( V_3 ) ;
}
F_86 ( F_82 ( V_3 ) , & V_106 ) ;
if ( V_22 )
goto V_36;
V_105 -> V_38 = V_113 ;
F_2 ( L_17 , V_108 ) ;
V_36:
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_87 ( struct V_69 * V_2 , struct V_88 * V_89 , int * V_44 , int V_114 )
{
struct V_91 * V_92 = (struct V_91 * ) V_89 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_18 , V_2 , V_3 ) ;
V_89 -> V_94 = V_95 ;
* V_44 = sizeof( struct V_91 ) ;
if ( V_114 )
F_33 ( & V_92 -> V_93 , & F_15 ( V_3 ) -> V_28 ) ;
else
F_33 ( & V_92 -> V_93 , & F_15 ( V_3 ) -> V_27 ) ;
return 0 ;
}
static int F_88 ( struct V_115 * V_116 , struct V_69 * V_2 ,
struct V_42 * V_43 , T_3 V_44 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_18 , V_2 , V_3 ) ;
V_22 = F_89 ( V_3 ) ;
if ( V_22 )
return V_22 ;
if ( V_43 -> V_48 & V_117 )
return - V_35 ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_39 )
V_22 = F_36 ( V_3 , V_43 , V_44 ) ;
else
V_22 = - V_118 ;
F_59 ( V_3 ) ;
return V_22 ;
}
static void F_90 ( struct V_12 * V_16 , T_4 V_33 )
{
struct V_14 * V_15 = V_16 -> V_15 ;
F_2 ( L_6 , V_16 ) ;
V_16 -> V_38 = V_61 ;
if ( ! F_28 ( V_15 ) ) {
struct V_119 V_120 ;
F_33 ( & V_120 . V_121 , & V_16 -> V_28 ) ;
V_120 . V_122 = 0x00 ;
F_91 ( V_15 , V_123 , sizeof( V_120 ) , & V_120 ) ;
} else {
struct V_124 V_120 ;
F_33 ( & V_120 . V_121 , & V_16 -> V_28 ) ;
V_120 . V_125 = F_92 ( V_16 -> V_125 ) ;
V_120 . V_126 = F_93 ( 0x00001f40 ) ;
V_120 . V_127 = F_93 ( 0x00001f40 ) ;
V_120 . V_128 = F_92 ( V_33 ) ;
switch ( V_33 & V_129 ) {
case V_130 :
if ( V_16 -> V_125 & V_131 )
V_120 . V_132 = F_92 ( 0x0008 ) ;
else
V_120 . V_132 = F_92 ( 0x000D ) ;
V_120 . V_133 = 0x02 ;
break;
case V_134 :
V_120 . V_132 = F_92 ( 0xffff ) ;
V_120 . V_133 = 0xff ;
break;
}
F_91 ( V_15 , V_135 ,
sizeof( V_120 ) , & V_120 ) ;
}
}
static int F_94 ( struct V_115 * V_116 , struct V_69 * V_2 ,
struct V_42 * V_43 , T_3 V_44 , int V_67 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_136 * V_137 = F_15 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( V_3 -> V_4 == V_65 &&
F_95 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ) {
F_90 ( V_137 -> V_16 -> V_13 , V_137 -> V_33 ) ;
V_3 -> V_4 = V_61 ;
F_59 ( V_3 ) ;
return 0 ;
}
F_59 ( V_3 ) ;
return F_96 ( V_116 , V_2 , V_43 , V_44 , V_67 ) ;
}
static int F_97 ( struct V_69 * V_2 , int V_139 , int V_140 , char T_5 * V_141 , unsigned int V_142 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_44 , V_22 = 0 ;
struct V_143 V_144 ;
T_6 V_145 ;
F_2 ( L_9 , V_3 ) ;
F_58 ( V_3 ) ;
switch ( V_140 ) {
case V_146 :
if ( V_3 -> V_4 != V_97 && V_3 -> V_4 != V_53 ) {
V_22 = - V_47 ;
break;
}
if ( F_98 ( V_145 , ( T_6 T_5 * ) V_141 ) ) {
V_22 = - V_50 ;
break;
}
if ( V_145 )
F_99 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ;
else
F_100 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ;
break;
case V_147 :
if ( V_3 -> V_4 != V_78 && V_3 -> V_4 != V_97 &&
V_3 -> V_4 != V_65 ) {
V_22 = - V_47 ;
break;
}
V_144 . V_33 = F_15 ( V_3 ) -> V_33 ;
V_44 = F_101 (unsigned int, sizeof(voice), optlen) ;
if ( F_102 ( ( char * ) & V_144 , V_141 , V_44 ) ) {
V_22 = - V_50 ;
break;
}
if ( V_144 . V_33 != V_34 &&
V_144 . V_33 != V_79 ) {
V_22 = - V_47 ;
break;
}
F_15 ( V_3 ) -> V_33 = V_144 . V_33 ;
break;
default:
V_22 = - V_148 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_103 ( struct V_69 * V_2 , int V_140 , char T_5 * V_141 , int T_5 * V_142 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_149 V_150 ;
struct V_151 V_152 ;
int V_44 , V_22 = 0 ;
F_2 ( L_9 , V_3 ) ;
if ( F_98 ( V_44 , V_142 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_140 ) {
case V_153 :
if ( V_3 -> V_4 != V_39 &&
! ( V_3 -> V_4 == V_65 &&
F_95 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ) ) {
V_22 = - V_118 ;
break;
}
V_150 . V_21 = F_15 ( V_3 ) -> V_16 -> V_21 ;
F_2 ( L_19 , V_150 . V_21 ) ;
V_44 = F_101 (unsigned int, len, sizeof(opts)) ;
if ( F_104 ( V_141 , ( char * ) & V_150 , V_44 ) )
V_22 = - V_50 ;
break;
case V_154 :
if ( V_3 -> V_4 != V_39 &&
! ( V_3 -> V_4 == V_65 &&
F_95 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ) ) {
V_22 = - V_118 ;
break;
}
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_155 = F_15 ( V_3 ) -> V_16 -> V_13 -> V_156 ;
memcpy ( V_152 . V_157 , F_15 ( V_3 ) -> V_16 -> V_13 -> V_157 , 3 ) ;
V_44 = F_101 (unsigned int, len, sizeof(cinfo)) ;
if ( F_104 ( V_141 , ( char * ) & V_152 , V_44 ) )
V_22 = - V_50 ;
break;
default:
V_22 = - V_148 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_105 ( struct V_69 * V_2 , int V_139 , int V_140 , char T_5 * V_141 , int T_5 * V_142 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_44 , V_22 = 0 ;
struct V_143 V_144 ;
F_2 ( L_9 , V_3 ) ;
if ( V_139 == V_158 )
return F_103 ( V_2 , V_140 , V_141 , V_142 ) ;
if ( F_98 ( V_44 , V_142 ) )
return - V_50 ;
F_58 ( V_3 ) ;
switch ( V_140 ) {
case V_146 :
if ( V_3 -> V_4 != V_97 && V_3 -> V_4 != V_53 ) {
V_22 = - V_47 ;
break;
}
if ( F_106 ( F_95 ( V_138 , & F_61 ( V_3 ) -> V_67 ) ,
( T_6 T_5 * ) V_141 ) )
V_22 = - V_50 ;
break;
case V_147 :
V_144 . V_33 = F_15 ( V_3 ) -> V_33 ;
V_44 = F_101 (unsigned int, len, sizeof(voice)) ;
if ( F_104 ( V_141 , ( char * ) & V_144 , V_44 ) )
V_22 = - V_50 ;
break;
default:
V_22 = - V_148 ;
break;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_107 ( struct V_69 * V_2 , int V_159 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_18 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_58 ( V_3 ) ;
if ( ! V_3 -> V_160 ) {
V_3 -> V_160 = V_161 ;
F_9 ( V_3 ) ;
F_57 ( V_3 ) ;
if ( F_55 ( V_3 , V_162 ) && V_3 -> V_163 &&
! ( V_111 -> V_67 & V_164 ) )
V_22 = F_73 ( V_3 , V_23 ,
V_3 -> V_163 ) ;
}
F_59 ( V_3 ) ;
return V_22 ;
}
static int F_108 ( struct V_69 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_18 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_54 ( V_3 ) ;
if ( F_55 ( V_3 , V_162 ) && V_3 -> V_163 &&
! ( V_111 -> V_67 & V_164 ) ) {
F_58 ( V_3 ) ;
V_22 = F_73 ( V_3 , V_23 , V_3 -> V_163 ) ;
F_59 ( V_3 ) ;
}
F_109 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_22 ;
}
static void F_110 ( struct V_11 * V_16 )
{
struct V_2 * V_25 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_6 , V_16 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_39 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
F_16 ( V_16 ) ;
V_25 = F_47 ( & V_16 -> V_13 -> V_27 ) ;
if ( ! V_25 ) {
F_17 ( V_16 ) ;
return;
}
F_3 ( V_25 ) ;
V_3 = F_63 ( F_111 ( V_25 ) , NULL ,
V_165 , V_87 ) ;
if ( ! V_3 ) {
F_4 ( V_25 ) ;
F_17 ( V_16 ) ;
return;
}
F_60 ( V_3 , V_25 ) ;
F_33 ( & F_15 ( V_3 ) -> V_27 , & V_16 -> V_13 -> V_27 ) ;
F_33 ( & F_15 ( V_3 ) -> V_28 , & V_16 -> V_13 -> V_28 ) ;
F_112 ( V_16 -> V_13 ) ;
F_22 ( V_16 , V_3 , V_25 ) ;
if ( F_95 ( V_138 , & F_61 ( V_25 ) -> V_67 ) )
V_3 -> V_4 = V_65 ;
else
V_3 -> V_4 = V_39 ;
V_25 -> V_166 ( V_25 ) ;
F_4 ( V_25 ) ;
F_17 ( V_16 ) ;
}
}
int F_113 ( struct V_14 * V_15 , T_1 * V_121 , T_7 * V_67 )
{
struct V_2 * V_3 ;
int V_167 = 0 ;
F_2 ( L_20 , V_15 -> V_168 , V_121 ) ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_53 )
continue;
if ( ! F_46 ( & F_15 ( V_3 ) -> V_27 , & V_15 -> V_121 ) ||
! F_46 ( & F_15 ( V_3 ) -> V_27 , V_56 ) ) {
V_167 |= V_169 ;
if ( F_95 ( V_138 , & F_61 ( V_3 ) -> V_67 ) )
* V_67 |= V_170 ;
break;
}
}
F_49 ( & V_55 . V_19 ) ;
return V_167 ;
}
void F_114 ( struct V_12 * V_13 , T_7 V_171 )
{
F_2 ( L_21 , V_13 , & V_13 -> V_28 , V_171 ) ;
if ( ! V_171 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_110 ( V_16 ) ;
} else
F_20 ( V_13 , F_115 ( V_171 ) ) ;
}
void F_116 ( struct V_12 * V_13 , T_7 V_172 )
{
F_2 ( L_22 , V_13 , V_172 ) ;
F_20 ( V_13 , F_115 ( V_172 ) ) ;
}
int F_117 ( struct V_12 * V_13 , struct V_45 * V_46 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
if ( ! V_16 )
goto V_51;
F_2 ( L_23 , V_16 , V_46 -> V_44 ) ;
if ( V_46 -> V_44 ) {
F_42 ( V_16 , V_46 ) ;
return 0 ;
}
V_51:
F_40 ( V_46 ) ;
return 0 ;
}
static int F_118 ( struct V_173 * V_174 , void * V_175 )
{
struct V_2 * V_3 ;
F_48 ( & V_55 . V_19 ) ;
F_45 (sk, &sco_sk_list.head) {
F_119 ( V_174 , L_24 , & F_15 ( V_3 ) -> V_27 ,
& F_15 ( V_3 ) -> V_28 , V_3 -> V_4 ) ;
}
F_49 ( & V_55 . V_19 ) ;
return 0 ;
}
static int F_120 ( struct V_176 * V_176 , struct V_177 * V_177 )
{
return F_121 ( V_177 , F_118 , V_176 -> V_178 ) ;
}
int T_8 F_122 ( void )
{
int V_22 ;
F_123 ( sizeof( struct V_91 ) > sizeof( struct V_88 ) ) ;
V_22 = F_124 ( & V_73 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_125 ( V_165 , & V_179 ) ;
if ( V_22 < 0 ) {
F_126 ( L_25 ) ;
goto error;
}
V_22 = F_127 ( & V_180 , L_26 , & V_55 , NULL ) ;
if ( V_22 < 0 ) {
F_126 ( L_27 ) ;
F_128 ( V_165 ) ;
goto error;
}
F_129 ( L_28 ) ;
if ( F_130 ( V_181 ) )
return 0 ;
V_182 = F_131 ( L_26 , 0444 , V_181 ,
NULL , & V_183 ) ;
return 0 ;
error:
F_132 ( & V_73 ) ;
return V_22 ;
}
void T_9 F_133 ( void )
{
F_134 ( & V_180 , L_26 ) ;
F_135 ( V_182 ) ;
F_128 ( V_165 ) ;
F_132 ( & V_73 ) ;
}
