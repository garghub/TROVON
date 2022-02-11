int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
F_2 ( & V_9 -> V_2 -> V_10 ) ;
if ( V_7 -> V_11 >= V_9 -> V_11 ) {
if ( F_3 ( V_7 -> V_12 , V_9 -> V_12 , V_9 -> V_11 ) ) {
F_4 ( & V_9 -> V_2 -> V_10 ) ;
return - V_13 ;
}
}
V_7 -> V_11 = V_9 -> V_11 ;
F_4 ( & V_9 -> V_2 -> V_10 ) ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_6 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
V_9 -> V_11 = 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
int V_14 ;
if ( V_9 -> V_12 != NULL )
F_5 ( V_2 , V_9 ) ;
if ( V_2 -> V_2 && F_8 ( V_2 -> V_2 ) ) {
V_14 = F_9 ( V_2 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , V_9 ) ;
return V_14 ;
}
} else {
F_10 ( ! V_2 -> V_12 ) ;
V_9 -> V_12 = F_11 ( V_2 -> V_12 , V_15 ) ;
if ( V_9 -> V_12 )
V_9 -> V_11 = strlen ( V_2 -> V_12 ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_16 * V_17 = V_3 ;
if ( V_17 -> V_18 == 0 ) {
V_17 -> V_19 = V_5 -> V_20 ;
V_17 -> V_21 = F_13 ( V_22 ) ;
V_17 -> V_23 = V_24 ;
V_17 -> V_25 = 0 ;
V_17 -> V_26 = 0 ;
return 0 ;
} else {
return - V_27 ;
}
}
static int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 = V_3 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_30 * V_31 = V_3 ;
struct V_32 * V_33 ;
V_31 -> V_34 = 0 ;
switch ( V_31 -> V_35 ) {
case V_36 :
V_31 -> V_34 = V_37 ;
return 0 ;
case V_38 :
V_31 -> V_34 |= V_2 -> V_39 -> V_40 ? V_41 : 0 ;
V_31 -> V_34 |= V_2 -> V_39 -> V_42 ? V_43 : 0 ;
return 0 ;
case V_44 :
V_31 -> V_34 = F_16 ( V_2 , V_45 ) ;
return 0 ;
}
if ( ! F_16 ( V_2 , V_46 ) )
return - V_47 ;
switch ( V_31 -> V_35 ) {
case V_48 :
if ( V_2 -> V_39 -> V_49 )
V_31 -> V_34 = 1 ;
break;
case V_50 :
V_31 -> V_34 = 1 ;
break;
case V_51 :
V_31 -> V_34 = V_2 -> V_52 . V_53 ;
break;
case V_54 :
V_31 -> V_34 = V_2 -> V_52 . V_55 ;
break;
case V_56 :
V_31 -> V_34 = V_2 -> V_52 . V_57 ;
break;
case V_58 :
V_31 -> V_34 = 1 ;
F_17 (crtc, dev) {
if ( ! V_33 -> V_59 -> V_60 )
V_31 -> V_34 = 0 ;
}
break;
case V_61 :
if ( V_2 -> V_52 . V_62 )
V_31 -> V_34 = V_2 -> V_52 . V_62 ;
else
V_31 -> V_34 = 64 ;
break;
case V_63 :
if ( V_2 -> V_52 . V_64 )
V_31 -> V_34 = V_2 -> V_52 . V_64 ;
else
V_31 -> V_34 = 64 ;
break;
case V_65 :
V_31 -> V_34 = V_2 -> V_52 . V_66 ;
break;
case V_67 :
V_31 -> V_34 = 1 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_68 * V_31 = V_3 ;
switch ( V_31 -> V_35 ) {
case V_69 :
if ( V_31 -> V_34 > 1 )
return - V_27 ;
V_5 -> V_70 = V_31 -> V_34 ;
break;
case V_71 :
if ( V_31 -> V_34 > 1 )
return - V_27 ;
V_5 -> V_72 = V_31 -> V_34 ;
break;
case V_73 :
if ( ! F_16 ( V_2 , V_74 ) )
return - V_27 ;
if ( V_31 -> V_34 > 1 )
return - V_27 ;
V_5 -> V_75 = V_31 -> V_34 ;
V_5 -> V_72 = V_31 -> V_34 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_76 * V_77 = V_3 ;
int V_78 , V_79 = 0 ;
F_2 ( & V_2 -> V_10 ) ;
if ( V_77 -> V_80 != - 1 ) {
if ( V_77 -> V_80 != V_81 ||
V_77 -> V_82 < 0 || V_77 -> V_82 > V_83 ) {
V_79 = - V_27 ;
goto V_84;
}
V_78 = F_20 ( V_77 -> V_80 ,
V_77 -> V_82 ) ;
V_2 -> V_78 = F_21 ( V_78 , V_2 -> V_78 ) ;
if ( V_77 -> V_82 >= 1 ) {
V_79 = F_7 ( V_2 , V_5 ) ;
if ( V_79 )
goto V_84;
}
}
if ( V_77 -> V_85 != - 1 ) {
if ( V_77 -> V_85 != V_2 -> V_39 -> V_86 ||
V_77 -> V_87 < 0 || V_77 -> V_87 >
V_2 -> V_39 -> V_88 ) {
V_79 = - V_27 ;
goto V_84;
}
}
V_84:
V_77 -> V_80 = V_81 ;
V_77 -> V_82 = V_83 ;
V_77 -> V_85 = V_2 -> V_39 -> V_86 ;
V_77 -> V_87 = V_2 -> V_39 -> V_88 ;
F_4 ( & V_2 -> V_10 ) ;
return V_79 ;
}
int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_23 ( L_1 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return - V_27 ;
}
static int F_25 ( char T_1 * V_89 , T_2 * V_90 , const char * V_34 )
{
int V_91 ;
V_91 = strlen ( V_34 ) ;
if ( V_91 > * V_90 )
V_91 = * V_90 ;
* V_90 = strlen ( V_34 ) ;
if ( V_91 && V_89 )
if ( F_3 ( V_89 , V_34 , V_91 ) )
return - V_13 ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_26 * V_92 = V_3 ;
int V_93 ;
V_92 -> V_94 = V_2 -> V_39 -> V_86 ;
V_92 -> V_95 = V_2 -> V_39 -> V_88 ;
V_92 -> V_96 = V_2 -> V_39 -> V_97 ;
V_93 = F_25 ( V_92 -> V_98 , & V_92 -> V_99 ,
V_2 -> V_39 -> V_98 ) ;
if ( ! V_93 )
V_93 = F_25 ( V_92 -> V_100 , & V_92 -> V_101 ,
V_2 -> V_39 -> V_100 ) ;
if ( ! V_93 )
V_93 = F_25 ( V_92 -> V_102 , & V_92 -> V_103 ,
V_2 -> V_39 -> V_102 ) ;
return V_93 ;
}
int F_27 ( T_3 V_104 , struct V_4 * V_5 )
{
if ( F_28 ( ( V_104 & V_105 ) && ! F_29 ( V_106 ) ) )
return - V_107 ;
if ( F_28 ( ( V_104 & V_108 ) && ! F_30 ( V_5 ) &&
! V_5 -> V_20 ) )
return - V_107 ;
if ( F_28 ( ( V_104 & V_109 ) &&
! F_31 ( V_5 ) &&
! F_32 ( V_5 ) ) )
return - V_107 ;
if ( F_28 ( ! ( V_104 & V_110 ) &&
F_32 ( V_5 ) ) )
return - V_107 ;
if ( F_28 ( ! ( V_104 & V_111 ) &&
F_30 ( V_5 ) ) )
return - V_107 ;
return 0 ;
}
long F_33 ( struct V_112 * V_112 , T_4 * V_113 , void * V_114 ,
T_3 V_104 )
{
struct V_4 * V_5 = V_112 -> V_115 ;
struct V_1 * V_2 = V_5 -> V_88 -> V_2 ;
int V_79 ;
if ( F_34 ( V_2 ) )
return - V_116 ;
V_79 = F_27 ( V_104 , V_5 ) ;
if ( F_28 ( V_79 ) )
return V_79 ;
if ( ! F_16 ( V_2 , V_117 ) ||
( V_104 & V_118 ) )
V_79 = V_113 ( V_2 , V_114 , V_5 ) ;
else {
F_2 ( & V_119 ) ;
V_79 = V_113 ( V_2 , V_114 , V_5 ) ;
F_4 ( & V_119 ) ;
}
return V_79 ;
}
long F_35 ( struct V_112 * V_120 ,
unsigned int V_121 , unsigned long V_122 )
{
struct V_4 * V_5 = V_120 -> V_115 ;
struct V_1 * V_2 ;
const struct V_123 * V_124 = NULL ;
T_4 * V_113 ;
unsigned int V_125 = F_36 ( V_121 ) ;
int V_79 = - V_27 ;
char V_126 [ 128 ] ;
char * V_114 = NULL ;
unsigned int V_127 , V_128 , V_129 , V_130 ;
bool V_131 ;
V_2 = V_5 -> V_88 -> V_2 ;
if ( F_34 ( V_2 ) )
return - V_116 ;
V_131 = V_125 >= V_132 && V_125 < V_133 ;
if ( V_131 ) {
if ( V_125 - V_132 >= V_2 -> V_39 -> V_134 )
goto V_135;
V_124 = & V_2 -> V_39 -> V_136 [ V_125 - V_132 ] ;
} else {
if ( V_125 >= V_137 )
goto V_135;
V_124 = & V_138 [ V_125 ] ;
}
V_129 = F_37 ( V_124 -> V_121 ) ;
V_128 = V_127 = F_37 ( V_121 ) ;
if ( ( V_121 & V_124 -> V_121 & V_139 ) == 0 )
V_127 = 0 ;
if ( ( V_121 & V_124 -> V_121 & V_140 ) == 0 )
V_128 = 0 ;
V_130 = F_21 ( F_21 ( V_127 , V_128 ) , V_129 ) ;
F_23 ( L_2 ,
F_38 ( V_22 ) ,
( long ) F_39 ( V_5 -> V_88 -> V_141 -> V_142 ) ,
V_5 -> V_20 , V_124 -> V_98 ) ;
V_113 = V_124 -> V_113 ;
if ( F_28 ( ! V_113 ) ) {
F_23 ( L_3 ) ;
V_79 = - V_27 ;
goto V_135;
}
if ( V_130 <= sizeof( V_126 ) ) {
V_114 = V_126 ;
} else {
V_114 = F_40 ( V_130 , V_15 ) ;
if ( ! V_114 ) {
V_79 = - V_143 ;
goto V_135;
}
}
if ( F_41 ( V_114 , ( void T_1 * ) V_122 , V_127 ) != 0 ) {
V_79 = - V_13 ;
goto V_135;
}
if ( V_130 > V_127 )
memset ( V_114 + V_127 , 0 , V_130 - V_127 ) ;
V_79 = F_33 ( V_120 , V_113 , V_114 , V_124 -> V_104 ) ;
if ( F_3 ( ( void T_1 * ) V_122 , V_114 , V_128 ) != 0 )
V_79 = - V_13 ;
V_135:
if ( ! V_124 )
F_23 ( L_4 ,
F_38 ( V_22 ) ,
( long ) F_39 ( V_5 -> V_88 -> V_141 -> V_142 ) ,
V_5 -> V_20 , V_121 , V_125 ) ;
if ( V_114 != V_126 )
F_6 ( V_114 ) ;
if ( V_79 )
F_23 ( L_5 , V_79 ) ;
return V_79 ;
}
bool F_42 ( unsigned int V_125 , unsigned int * V_104 )
{
if ( V_125 >= V_132 && V_125 < V_133 )
return false ;
if ( V_125 >= V_137 )
return false ;
* V_104 = V_138 [ V_125 ] . V_104 ;
return true ;
}
