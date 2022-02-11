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
static void F_20 ( struct V_12 * V_13 , int V_22 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
struct V_2 * V_3 ;
if ( ! V_16 )
return;
F_2 ( L_5 , V_13 , V_16 , V_22 ) ;
F_16 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
F_17 ( V_16 ) ;
if ( V_3 ) {
F_21 ( V_3 ) ;
F_3 ( V_3 ) ;
F_9 ( V_3 ) ;
F_14 ( V_3 , V_22 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
}
V_13 -> V_17 = NULL ;
F_22 ( V_16 ) ;
}
static void F_23 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_25 )
{
F_2 ( L_6 , V_16 ) ;
F_15 ( V_3 ) -> V_16 = V_16 ;
V_16 -> V_3 = V_3 ;
if ( V_25 )
F_24 ( V_25 , V_3 ) ;
}
static int F_25 ( struct V_11 * V_16 , struct V_2 * V_3 ,
struct V_2 * V_25 )
{
int V_22 = 0 ;
F_16 ( V_16 ) ;
if ( V_16 -> V_3 )
V_22 = - V_26 ;
else
F_23 ( V_16 , V_3 , V_25 ) ;
F_17 ( V_16 ) ;
return V_22 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_11 * V_16 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_22 , type ;
F_2 ( L_7 , & F_15 ( V_3 ) -> V_27 , & F_15 ( V_3 ) -> V_28 ) ;
V_15 = F_27 ( & F_15 ( V_3 ) -> V_28 , & F_15 ( V_3 ) -> V_27 , V_29 ) ;
if ( ! V_15 )
return - V_30 ;
F_28 ( V_15 ) ;
if ( F_29 ( V_15 ) && ! V_31 )
type = V_32 ;
else
type = V_33 ;
if ( F_15 ( V_3 ) -> V_34 == V_35 &&
( ! F_30 ( V_15 ) || ! F_29 ( V_15 ) ) ) {
V_22 = - V_36 ;
goto V_37;
}
V_13 = F_31 ( V_15 , type , & F_15 ( V_3 ) -> V_28 ,
F_15 ( V_3 ) -> V_34 ) ;
if ( F_32 ( V_13 ) ) {
V_22 = F_33 ( V_13 ) ;
goto V_37;
}
V_16 = F_11 ( V_13 ) ;
if ( ! V_16 ) {
F_18 ( V_13 ) ;
V_22 = - V_38 ;
goto V_37;
}
F_34 ( & F_15 ( V_3 ) -> V_27 , & V_13 -> V_27 ) ;
V_22 = F_25 ( V_16 , V_3 , NULL ) ;
if ( V_22 )
goto V_37;
if ( V_13 -> V_39 == V_40 ) {
F_9 ( V_3 ) ;
V_3 -> V_4 = V_40 ;
} else {
V_3 -> V_4 = V_41 ;
F_7 ( V_3 , V_3 -> V_42 ) ;
}
V_37:
F_35 ( V_15 ) ;
F_36 ( V_15 ) ;
return V_22 ;
}
static int F_37 ( struct V_2 * V_3 , struct V_43 * V_44 , int V_45 )
{
struct V_11 * V_16 = F_15 ( V_3 ) -> V_16 ;
struct V_46 * V_47 ;
int V_22 ;
if ( V_45 > V_16 -> V_21 )
return - V_48 ;
F_2 ( L_8 , V_3 , V_45 ) ;
V_47 = F_38 ( V_3 , V_45 , V_44 -> V_49 & V_50 , & V_22 ) ;
if ( ! V_47 )
return V_22 ;
if ( F_39 ( F_40 ( V_47 , V_45 ) , V_44 , V_45 ) ) {
F_41 ( V_47 ) ;
return - V_51 ;
}
F_42 ( V_16 -> V_13 , V_47 ) ;
return V_45 ;
}
static void F_43 ( struct V_11 * V_16 , struct V_46 * V_47 )
{
struct V_2 * V_3 ;
F_16 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
F_17 ( V_16 ) ;
if ( ! V_3 )
goto V_52;
F_2 ( L_8 , V_3 , V_47 -> V_45 ) ;
if ( V_3 -> V_4 != V_40 )
goto V_52;
if ( ! F_44 ( V_3 , V_47 ) )
return;
V_52:
F_41 ( V_47 ) ;
}
static struct V_2 * F_45 ( T_1 * V_53 )
{
struct V_2 * V_3 ;
F_46 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_54 )
continue;
if ( ! F_47 ( & F_15 ( V_3 ) -> V_27 , V_53 ) )
return V_3 ;
}
return NULL ;
}
static struct V_2 * F_48 ( T_1 * V_27 )
{
struct V_2 * V_3 = NULL , * V_55 = NULL ;
F_49 ( & V_56 . V_19 ) ;
F_46 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_54 )
continue;
if ( ! F_47 ( & F_15 ( V_3 ) -> V_27 , V_27 ) )
break;
if ( ! F_47 ( & F_15 ( V_3 ) -> V_27 , V_57 ) )
V_55 = V_3 ;
}
F_50 ( & V_56 . V_19 ) ;
return V_3 ? V_3 : V_55 ;
}
static void F_51 ( struct V_2 * V_3 )
{
F_2 ( L_9 , V_3 ) ;
F_52 ( & V_3 -> V_58 ) ;
F_52 ( & V_3 -> V_59 ) ;
}
static void F_53 ( struct V_2 * V_25 )
{
struct V_2 * V_3 ;
F_2 ( L_10 , V_25 ) ;
while ( ( V_3 = F_54 ( V_25 , NULL ) ) ) {
F_55 ( V_3 ) ;
F_5 ( V_3 ) ;
}
V_25 -> V_4 = V_23 ;
F_19 ( V_25 , V_24 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( ! F_56 ( V_3 , V_24 ) || V_3 -> V_60 )
return;
F_2 ( L_11 , V_3 , V_3 -> V_4 ) ;
F_57 ( & V_56 , V_3 ) ;
F_19 ( V_3 , V_61 ) ;
F_6 ( V_3 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_2 ( L_12 , V_3 , V_3 -> V_4 , V_3 -> V_60 ) ;
switch ( V_3 -> V_4 ) {
case V_54 :
F_53 ( V_3 ) ;
break;
case V_40 :
case V_62 :
if ( F_15 ( V_3 ) -> V_16 -> V_13 ) {
V_3 -> V_4 = V_63 ;
F_7 ( V_3 , V_64 ) ;
F_16 ( F_15 ( V_3 ) -> V_16 ) ;
F_18 ( F_15 ( V_3 ) -> V_16 -> V_13 ) ;
F_15 ( V_3 ) -> V_16 -> V_13 = NULL ;
F_17 ( F_15 ( V_3 ) -> V_16 ) ;
} else
F_14 ( V_3 , V_65 ) ;
break;
case V_66 :
case V_41 :
case V_63 :
F_14 ( V_3 , V_65 ) ;
break;
default:
F_19 ( V_3 , V_24 ) ;
break;
}
}
static void F_55 ( struct V_2 * V_3 )
{
F_9 ( V_3 ) ;
F_59 ( V_3 ) ;
F_58 ( V_3 ) ;
F_60 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static void F_61 ( struct V_2 * V_3 , struct V_2 * V_25 )
{
F_2 ( L_9 , V_3 ) ;
if ( V_25 ) {
V_3 -> V_67 = V_25 -> V_67 ;
F_62 ( V_3 ) -> V_68 = F_62 ( V_25 ) -> V_68 ;
F_63 ( V_25 , V_3 ) ;
}
}
static struct V_2 * F_64 ( struct V_69 * V_69 , struct V_70 * V_2 ,
int V_71 , T_2 V_72 , int V_73 )
{
struct V_2 * V_3 ;
V_3 = F_65 ( V_69 , V_74 , V_72 , & V_75 , V_73 ) ;
if ( ! V_3 )
return NULL ;
F_66 ( V_2 , V_3 ) ;
F_67 ( & F_62 ( V_3 ) -> V_76 ) ;
V_3 -> V_77 = F_51 ;
V_3 -> V_42 = V_78 ;
F_68 ( V_3 , V_24 ) ;
V_3 -> V_79 = V_71 ;
V_3 -> V_4 = V_80 ;
F_15 ( V_3 ) -> V_34 = V_81 ;
F_69 ( & V_3 -> V_9 , F_1 , ( unsigned long ) V_3 ) ;
F_70 ( & V_56 , V_3 ) ;
return V_3 ;
}
static int F_71 ( struct V_69 * V_69 , struct V_70 * V_2 , int V_82 ,
int V_73 )
{
struct V_2 * V_3 ;
F_2 ( L_13 , V_2 ) ;
V_2 -> V_39 = V_83 ;
if ( V_2 -> type != V_84 )
return - V_85 ;
V_2 -> V_86 = & V_87 ;
V_3 = F_64 ( V_69 , V_2 , V_82 , V_88 , V_73 ) ;
if ( ! V_3 )
return - V_38 ;
F_61 ( V_3 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_70 * V_2 , struct V_89 * V_90 ,
int V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_14 , V_3 , & V_93 -> V_94 ) ;
if ( ! V_90 || V_90 -> V_95 != V_96 )
return - V_48 ;
if ( V_91 < sizeof( struct V_92 ) )
return - V_48 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_80 ) {
V_22 = - V_97 ;
goto V_37;
}
if ( V_3 -> V_67 != V_84 ) {
V_22 = - V_48 ;
goto V_37;
}
F_34 ( & F_15 ( V_3 ) -> V_27 , & V_93 -> V_94 ) ;
V_3 -> V_4 = V_98 ;
V_37:
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_73 ( struct V_70 * V_2 , struct V_89 * V_90 , int V_99 , int V_68 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_9 , V_3 ) ;
if ( V_99 < sizeof( struct V_92 ) ||
V_90 -> V_95 != V_96 )
return - V_48 ;
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_98 )
return - V_97 ;
if ( V_3 -> V_67 != V_84 )
return - V_48 ;
F_59 ( V_3 ) ;
F_34 ( & F_15 ( V_3 ) -> V_28 , & V_93 -> V_94 ) ;
V_22 = F_26 ( V_3 ) ;
if ( V_22 )
goto V_37;
V_22 = F_74 ( V_3 , V_40 ,
F_75 ( V_3 , V_68 & V_100 ) ) ;
V_37:
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_76 ( struct V_70 * V_2 , int V_101 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
T_1 * V_27 = & F_15 ( V_3 ) -> V_27 ;
int V_22 = 0 ;
F_2 ( L_15 , V_3 , V_101 ) ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 != V_98 ) {
V_22 = - V_97 ;
goto V_37;
}
if ( V_3 -> V_67 != V_84 ) {
V_22 = - V_48 ;
goto V_37;
}
F_77 ( & V_56 . V_19 ) ;
if ( F_45 ( V_27 ) ) {
V_22 = - V_102 ;
goto V_103;
}
V_3 -> V_104 = V_101 ;
V_3 -> V_105 = 0 ;
V_3 -> V_4 = V_54 ;
V_103:
F_78 ( & V_56 . V_19 ) ;
V_37:
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_79 ( struct V_70 * V_2 , struct V_70 * V_106 ,
int V_68 )
{
F_80 ( V_107 , V_108 ) ;
struct V_2 * V_3 = V_2 -> V_3 , * V_109 ;
long V_110 ;
int V_22 = 0 ;
F_59 ( V_3 ) ;
V_110 = F_81 ( V_3 , V_68 & V_100 ) ;
F_2 ( L_16 , V_3 , V_110 ) ;
F_82 ( F_83 ( V_3 ) , & V_107 ) ;
while ( 1 ) {
if ( V_3 -> V_4 != V_54 ) {
V_22 = - V_97 ;
break;
}
V_109 = F_54 ( V_3 , V_106 ) ;
if ( V_109 )
break;
if ( ! V_110 ) {
V_22 = - V_111 ;
break;
}
if ( F_84 ( V_112 ) ) {
V_22 = F_85 ( V_110 ) ;
break;
}
F_60 ( V_3 ) ;
V_110 = F_86 ( & V_107 , V_113 , V_110 ) ;
F_59 ( V_3 ) ;
}
F_87 ( F_83 ( V_3 ) , & V_107 ) ;
if ( V_22 )
goto V_37;
V_106 -> V_39 = V_114 ;
F_2 ( L_17 , V_109 ) ;
V_37:
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_88 ( struct V_70 * V_2 , struct V_89 * V_90 ,
int * V_45 , int V_115 )
{
struct V_92 * V_93 = (struct V_92 * ) V_90 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_18 , V_2 , V_3 ) ;
V_90 -> V_95 = V_96 ;
* V_45 = sizeof( struct V_92 ) ;
if ( V_115 )
F_34 ( & V_93 -> V_94 , & F_15 ( V_3 ) -> V_28 ) ;
else
F_34 ( & V_93 -> V_94 , & F_15 ( V_3 ) -> V_27 ) ;
return 0 ;
}
static int F_89 ( struct V_70 * V_2 , struct V_43 * V_44 ,
T_3 V_45 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 ;
F_2 ( L_18 , V_2 , V_3 ) ;
V_22 = F_90 ( V_3 ) ;
if ( V_22 )
return V_22 ;
if ( V_44 -> V_49 & V_116 )
return - V_36 ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 == V_40 )
V_22 = F_37 ( V_3 , V_44 , V_45 ) ;
else
V_22 = - V_117 ;
F_60 ( V_3 ) ;
return V_22 ;
}
static void F_91 ( struct V_12 * V_16 , T_4 V_34 )
{
struct V_14 * V_15 = V_16 -> V_15 ;
F_2 ( L_6 , V_16 ) ;
V_16 -> V_39 = V_62 ;
if ( ! F_29 ( V_15 ) ) {
struct V_118 V_119 ;
F_34 ( & V_119 . V_120 , & V_16 -> V_28 ) ;
V_119 . V_121 = 0x00 ;
F_92 ( V_15 , V_122 , sizeof( V_119 ) , & V_119 ) ;
} else {
struct V_123 V_119 ;
F_34 ( & V_119 . V_120 , & V_16 -> V_28 ) ;
V_119 . V_124 = F_93 ( V_16 -> V_124 ) ;
V_119 . V_125 = F_94 ( 0x00001f40 ) ;
V_119 . V_126 = F_94 ( 0x00001f40 ) ;
V_119 . V_127 = F_93 ( V_34 ) ;
switch ( V_34 & V_128 ) {
case V_129 :
if ( V_16 -> V_124 & V_130 )
V_119 . V_131 = F_93 ( 0x0008 ) ;
else
V_119 . V_131 = F_93 ( 0x000D ) ;
V_119 . V_132 = 0x02 ;
break;
case V_133 :
V_119 . V_131 = F_93 ( 0xffff ) ;
V_119 . V_132 = 0xff ;
break;
}
F_92 ( V_15 , V_134 ,
sizeof( V_119 ) , & V_119 ) ;
}
}
static int F_95 ( struct V_70 * V_2 , struct V_43 * V_44 ,
T_3 V_45 , int V_68 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_135 * V_136 = F_15 ( V_3 ) ;
F_59 ( V_3 ) ;
if ( V_3 -> V_4 == V_66 &&
F_96 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ) {
F_91 ( V_136 -> V_16 -> V_13 , V_136 -> V_34 ) ;
V_3 -> V_4 = V_62 ;
F_60 ( V_3 ) ;
return 0 ;
}
F_60 ( V_3 ) ;
return F_97 ( V_2 , V_44 , V_45 , V_68 ) ;
}
static int F_98 ( struct V_70 * V_2 , int V_138 , int V_139 ,
char T_5 * V_140 , unsigned int V_141 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_45 , V_22 = 0 ;
struct V_142 V_143 ;
T_6 V_144 ;
F_2 ( L_9 , V_3 ) ;
F_59 ( V_3 ) ;
switch ( V_139 ) {
case V_145 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_54 ) {
V_22 = - V_48 ;
break;
}
if ( F_99 ( V_144 , ( T_6 T_5 * ) V_140 ) ) {
V_22 = - V_51 ;
break;
}
if ( V_144 )
F_100 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ;
else
F_101 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ;
break;
case V_146 :
if ( V_3 -> V_4 != V_80 && V_3 -> V_4 != V_98 &&
V_3 -> V_4 != V_66 ) {
V_22 = - V_48 ;
break;
}
V_143 . V_34 = F_15 ( V_3 ) -> V_34 ;
V_45 = F_102 (unsigned int, sizeof(voice), optlen) ;
if ( F_103 ( ( char * ) & V_143 , V_140 , V_45 ) ) {
V_22 = - V_51 ;
break;
}
if ( V_143 . V_34 != V_35 &&
V_143 . V_34 != V_81 ) {
V_22 = - V_48 ;
break;
}
F_15 ( V_3 ) -> V_34 = V_143 . V_34 ;
break;
default:
V_22 = - V_147 ;
break;
}
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_104 ( struct V_70 * V_2 , int V_139 ,
char T_5 * V_140 , int T_5 * V_141 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_148 V_149 ;
struct V_150 V_151 ;
int V_45 , V_22 = 0 ;
F_2 ( L_9 , V_3 ) ;
if ( F_99 ( V_45 , V_141 ) )
return - V_51 ;
F_59 ( V_3 ) ;
switch ( V_139 ) {
case V_152 :
if ( V_3 -> V_4 != V_40 &&
! ( V_3 -> V_4 == V_66 &&
F_96 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ) ) {
V_22 = - V_117 ;
break;
}
V_149 . V_21 = F_15 ( V_3 ) -> V_16 -> V_21 ;
F_2 ( L_19 , V_149 . V_21 ) ;
V_45 = F_102 (unsigned int, len, sizeof(opts)) ;
if ( F_105 ( V_140 , ( char * ) & V_149 , V_45 ) )
V_22 = - V_51 ;
break;
case V_153 :
if ( V_3 -> V_4 != V_40 &&
! ( V_3 -> V_4 == V_66 &&
F_96 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ) ) {
V_22 = - V_117 ;
break;
}
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_154 = F_15 ( V_3 ) -> V_16 -> V_13 -> V_155 ;
memcpy ( V_151 . V_156 , F_15 ( V_3 ) -> V_16 -> V_13 -> V_156 , 3 ) ;
V_45 = F_102 (unsigned int, len, sizeof(cinfo)) ;
if ( F_105 ( V_140 , ( char * ) & V_151 , V_45 ) )
V_22 = - V_51 ;
break;
default:
V_22 = - V_147 ;
break;
}
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_106 ( struct V_70 * V_2 , int V_138 , int V_139 ,
char T_5 * V_140 , int T_5 * V_141 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_45 , V_22 = 0 ;
struct V_142 V_143 ;
F_2 ( L_9 , V_3 ) ;
if ( V_138 == V_157 )
return F_104 ( V_2 , V_139 , V_140 , V_141 ) ;
if ( F_99 ( V_45 , V_141 ) )
return - V_51 ;
F_59 ( V_3 ) ;
switch ( V_139 ) {
case V_145 :
if ( V_3 -> V_4 != V_98 && V_3 -> V_4 != V_54 ) {
V_22 = - V_48 ;
break;
}
if ( F_107 ( F_96 ( V_137 , & F_62 ( V_3 ) -> V_68 ) ,
( T_6 T_5 * ) V_140 ) )
V_22 = - V_51 ;
break;
case V_146 :
V_143 . V_34 = F_15 ( V_3 ) -> V_34 ;
V_45 = F_102 (unsigned int, len, sizeof(voice)) ;
if ( F_105 ( V_140 , ( char * ) & V_143 , V_45 ) )
V_22 = - V_51 ;
break;
default:
V_22 = - V_147 ;
break;
}
F_60 ( V_3 ) ;
return V_22 ;
}
static int F_108 ( struct V_70 * V_2 , int V_158 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_18 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_21 ( V_3 ) ;
F_59 ( V_3 ) ;
if ( ! V_3 -> V_159 ) {
V_3 -> V_159 = V_160 ;
F_9 ( V_3 ) ;
F_58 ( V_3 ) ;
if ( F_56 ( V_3 , V_161 ) && V_3 -> V_162 &&
! ( V_112 -> V_68 & V_163 ) )
V_22 = F_74 ( V_3 , V_23 ,
V_3 -> V_162 ) ;
}
F_60 ( V_3 ) ;
F_6 ( V_3 ) ;
return V_22 ;
}
static int F_109 ( struct V_70 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
int V_22 = 0 ;
F_2 ( L_18 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_55 ( V_3 ) ;
if ( F_56 ( V_3 , V_161 ) && V_3 -> V_162 &&
! ( V_112 -> V_68 & V_163 ) ) {
F_59 ( V_3 ) ;
V_22 = F_74 ( V_3 , V_23 , V_3 -> V_162 ) ;
F_60 ( V_3 ) ;
}
F_110 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_22 ;
}
static void F_111 ( struct V_11 * V_16 )
{
struct V_2 * V_25 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_2 ( L_6 , V_16 ) ;
if ( V_3 ) {
F_9 ( V_3 ) ;
F_3 ( V_3 ) ;
V_3 -> V_4 = V_40 ;
V_3 -> V_7 ( V_3 ) ;
F_4 ( V_3 ) ;
} else {
F_16 ( V_16 ) ;
if ( ! V_16 -> V_13 ) {
F_17 ( V_16 ) ;
return;
}
V_25 = F_48 ( & V_16 -> V_13 -> V_27 ) ;
if ( ! V_25 ) {
F_17 ( V_16 ) ;
return;
}
F_3 ( V_25 ) ;
V_3 = F_64 ( F_112 ( V_25 ) , NULL ,
V_164 , V_88 , 0 ) ;
if ( ! V_3 ) {
F_4 ( V_25 ) ;
F_17 ( V_16 ) ;
return;
}
F_61 ( V_3 , V_25 ) ;
F_34 ( & F_15 ( V_3 ) -> V_27 , & V_16 -> V_13 -> V_27 ) ;
F_34 ( & F_15 ( V_3 ) -> V_28 , & V_16 -> V_13 -> V_28 ) ;
F_113 ( V_16 -> V_13 ) ;
F_23 ( V_16 , V_3 , V_25 ) ;
if ( F_96 ( V_137 , & F_62 ( V_25 ) -> V_68 ) )
V_3 -> V_4 = V_66 ;
else
V_3 -> V_4 = V_40 ;
V_25 -> V_165 ( V_25 ) ;
F_4 ( V_25 ) ;
F_17 ( V_16 ) ;
}
}
int F_114 ( struct V_14 * V_15 , T_1 * V_120 , T_7 * V_68 )
{
struct V_2 * V_3 ;
int V_166 = 0 ;
F_2 ( L_20 , V_15 -> V_167 , V_120 ) ;
F_49 ( & V_56 . V_19 ) ;
F_46 (sk, &sco_sk_list.head) {
if ( V_3 -> V_4 != V_54 )
continue;
if ( ! F_47 ( & F_15 ( V_3 ) -> V_27 , & V_15 -> V_120 ) ||
! F_47 ( & F_15 ( V_3 ) -> V_27 , V_57 ) ) {
V_166 |= V_168 ;
if ( F_96 ( V_137 , & F_62 ( V_3 ) -> V_68 ) )
* V_68 |= V_169 ;
break;
}
}
F_50 ( & V_56 . V_19 ) ;
return V_166 ;
}
static void F_115 ( struct V_12 * V_13 , T_7 V_170 )
{
if ( V_13 -> type != V_33 && V_13 -> type != V_32 )
return;
F_2 ( L_21 , V_13 , & V_13 -> V_28 , V_170 ) ;
if ( ! V_170 ) {
struct V_11 * V_16 ;
V_16 = F_11 ( V_13 ) ;
if ( V_16 )
F_111 ( V_16 ) ;
} else
F_20 ( V_13 , F_116 ( V_170 ) ) ;
}
static void F_117 ( struct V_12 * V_13 , T_7 V_171 )
{
if ( V_13 -> type != V_33 && V_13 -> type != V_32 )
return;
F_2 ( L_22 , V_13 , V_171 ) ;
F_20 ( V_13 , F_116 ( V_171 ) ) ;
}
void F_118 ( struct V_12 * V_13 , struct V_46 * V_47 )
{
struct V_11 * V_16 = V_13 -> V_17 ;
if ( ! V_16 )
goto V_52;
F_2 ( L_23 , V_16 , V_47 -> V_45 ) ;
if ( V_47 -> V_45 ) {
F_43 ( V_16 , V_47 ) ;
return;
}
V_52:
F_41 ( V_47 ) ;
}
static int F_119 ( struct V_172 * V_173 , void * V_174 )
{
struct V_2 * V_3 ;
F_49 ( & V_56 . V_19 ) ;
F_46 (sk, &sco_sk_list.head) {
F_120 ( V_173 , L_24 , & F_15 ( V_3 ) -> V_27 ,
& F_15 ( V_3 ) -> V_28 , V_3 -> V_4 ) ;
}
F_50 ( & V_56 . V_19 ) ;
return 0 ;
}
static int F_121 ( struct V_175 * V_175 , struct V_176 * V_176 )
{
return F_122 ( V_176 , F_119 , V_175 -> V_177 ) ;
}
int T_8 F_123 ( void )
{
int V_22 ;
F_124 ( sizeof( struct V_92 ) > sizeof( struct V_89 ) ) ;
V_22 = F_125 ( & V_75 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_126 ( V_164 , & V_178 ) ;
if ( V_22 < 0 ) {
F_127 ( L_25 ) ;
goto error;
}
V_22 = F_128 ( & V_179 , L_26 , & V_56 , NULL ) ;
if ( V_22 < 0 ) {
F_127 ( L_27 ) ;
F_129 ( V_164 ) ;
goto error;
}
F_130 ( L_28 ) ;
F_131 ( & V_180 ) ;
if ( F_132 ( V_181 ) )
return 0 ;
V_182 = F_133 ( L_26 , 0444 , V_181 ,
NULL , & V_183 ) ;
return 0 ;
error:
F_134 ( & V_75 ) ;
return V_22 ;
}
void F_135 ( void )
{
F_136 ( & V_179 , L_26 ) ;
F_137 ( V_182 ) ;
F_138 ( & V_180 ) ;
F_129 ( V_164 ) ;
F_134 ( & V_75 ) ;
}
