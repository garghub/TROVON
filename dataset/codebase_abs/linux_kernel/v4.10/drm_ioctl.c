static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
if ( V_7 -> V_10 >= V_9 -> V_10 ) {
if ( F_2 ( V_7 -> V_11 , V_9 -> V_11 , V_9 -> V_10 ) )
return - V_12 ;
}
V_7 -> V_10 = V_9 -> V_10 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_4 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
V_9 -> V_10 = 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
int V_13 ;
if ( V_9 -> V_11 != NULL )
F_3 ( V_2 , V_9 ) ;
if ( V_2 -> V_14 -> V_15 ) {
V_13 = V_2 -> V_14 -> V_15 ( V_2 , V_9 ) ;
if ( V_13 ) {
F_3 ( V_2 , V_9 ) ;
return V_13 ;
}
} else {
F_6 ( ! V_2 -> V_11 ) ;
V_9 -> V_11 = F_7 ( V_2 -> V_11 , V_16 ) ;
if ( V_9 -> V_11 )
V_9 -> V_10 = strlen ( V_2 -> V_11 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_17 * V_18 = V_3 ;
if ( V_18 -> V_19 == 0 ) {
V_18 -> V_20 = V_5 -> V_21 ;
V_18 -> V_22 = F_9 ( V_23 ) ;
V_18 -> V_24 = V_25 ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
return 0 ;
} else {
return - V_28 ;
}
}
static int F_10 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_29 * V_30 = V_3 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_31 * V_32 = V_3 ;
struct V_33 * V_34 ;
V_32 -> V_35 = 0 ;
switch ( V_32 -> V_36 ) {
case V_37 :
V_32 -> V_35 = V_38 ;
return 0 ;
case V_39 :
V_32 -> V_35 |= V_2 -> V_14 -> V_40 ? V_41 : 0 ;
V_32 -> V_35 |= V_2 -> V_14 -> V_42 ? V_43 : 0 ;
return 0 ;
}
if ( ! F_12 ( V_2 , V_44 ) )
return - V_45 ;
switch ( V_32 -> V_36 ) {
case V_46 :
if ( V_2 -> V_14 -> V_47 )
V_32 -> V_35 = 1 ;
break;
case V_48 :
V_32 -> V_35 = 1 ;
break;
case V_49 :
V_32 -> V_35 = V_2 -> V_50 . V_51 ;
break;
case V_52 :
V_32 -> V_35 = V_2 -> V_50 . V_53 ;
break;
case V_54 :
V_32 -> V_35 = V_2 -> V_50 . V_55 ;
break;
case V_56 :
V_32 -> V_35 = 1 ;
F_13 (crtc, dev) {
if ( ! V_34 -> V_57 -> V_58 )
V_32 -> V_35 = 0 ;
}
break;
case V_59 :
if ( V_2 -> V_50 . V_60 )
V_32 -> V_35 = V_2 -> V_50 . V_60 ;
else
V_32 -> V_35 = 64 ;
break;
case V_61 :
if ( V_2 -> V_50 . V_62 )
V_32 -> V_35 = V_2 -> V_50 . V_62 ;
else
V_32 -> V_35 = 64 ;
break;
case V_63 :
V_32 -> V_35 = V_2 -> V_50 . V_64 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_65 * V_32 = V_3 ;
switch ( V_32 -> V_36 ) {
case V_66 :
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_67 = V_32 -> V_35 ;
break;
case V_68 :
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_69 = V_32 -> V_35 ;
break;
case V_70 :
if ( ! F_12 ( V_2 , V_71 ) )
return - V_28 ;
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_72 = V_32 -> V_35 ;
V_5 -> V_69 = V_32 -> V_35 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_73 * V_74 = V_3 ;
int V_75 , V_76 = 0 ;
if ( V_74 -> V_77 != - 1 ) {
if ( V_74 -> V_77 != V_78 ||
V_74 -> V_79 < 0 || V_74 -> V_79 > V_80 ) {
V_76 = - V_28 ;
goto V_81;
}
V_75 = F_16 ( V_74 -> V_77 ,
V_74 -> V_79 ) ;
V_2 -> V_75 = F_17 ( V_75 , V_2 -> V_75 ) ;
if ( V_74 -> V_79 >= 1 ) {
V_76 = F_5 ( V_2 , V_5 ) ;
if ( V_76 )
goto V_81;
}
}
if ( V_74 -> V_82 != - 1 ) {
if ( V_74 -> V_82 != V_2 -> V_14 -> V_83 ||
V_74 -> V_84 < 0 || V_74 -> V_84 >
V_2 -> V_14 -> V_85 ) {
V_76 = - V_28 ;
goto V_81;
}
}
V_81:
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = V_80 ;
V_74 -> V_82 = V_2 -> V_14 -> V_83 ;
V_74 -> V_84 = V_2 -> V_14 -> V_85 ;
return V_76 ;
}
int F_18 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_19 ( L_1 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return - V_28 ;
}
static int F_21 ( char T_1 * V_86 , T_2 * V_87 , const char * V_35 )
{
int V_88 ;
V_88 = strlen ( V_35 ) ;
if ( V_88 > * V_87 )
V_88 = * V_87 ;
* V_87 = strlen ( V_35 ) ;
if ( V_88 && V_86 )
if ( F_2 ( V_86 , V_35 , V_88 ) )
return - V_12 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_22 * V_89 = V_3 ;
int V_90 ;
V_89 -> V_91 = V_2 -> V_14 -> V_83 ;
V_89 -> V_92 = V_2 -> V_14 -> V_85 ;
V_89 -> V_93 = V_2 -> V_14 -> V_94 ;
V_90 = F_21 ( V_89 -> V_95 , & V_89 -> V_96 ,
V_2 -> V_14 -> V_95 ) ;
if ( ! V_90 )
V_90 = F_21 ( V_89 -> V_97 , & V_89 -> V_98 ,
V_2 -> V_14 -> V_97 ) ;
if ( ! V_90 )
V_90 = F_21 ( V_89 -> V_99 , & V_89 -> V_100 ,
V_2 -> V_14 -> V_99 ) ;
return V_90 ;
}
int F_23 ( T_3 V_101 , struct V_4 * V_5 )
{
if ( F_24 ( ( V_101 & V_102 ) && ! F_25 ( V_103 ) ) )
return - V_104 ;
if ( F_24 ( ( V_101 & V_105 ) && ! F_26 ( V_5 ) &&
! V_5 -> V_21 ) )
return - V_104 ;
if ( F_24 ( ( V_101 & V_106 ) &&
! F_27 ( V_5 ) &&
! F_28 ( V_5 ) ) )
return - V_104 ;
if ( F_24 ( ! ( V_101 & V_107 ) &&
F_28 ( V_5 ) ) )
return - V_104 ;
if ( F_24 ( ! ( V_101 & V_108 ) &&
F_26 ( V_5 ) ) )
return - V_104 ;
return 0 ;
}
long F_29 ( struct V_109 * V_110 ,
unsigned int V_111 , unsigned long V_112 )
{
struct V_4 * V_5 = V_110 -> V_113 ;
struct V_1 * V_2 ;
const struct V_114 * V_115 = NULL ;
T_4 * V_116 ;
unsigned int V_117 = F_30 ( V_111 ) ;
int V_76 = - V_28 ;
char V_118 [ 128 ] ;
char * V_119 = NULL ;
unsigned int V_120 , V_121 , V_122 , V_123 ;
bool V_124 ;
V_2 = V_5 -> V_85 -> V_2 ;
if ( F_31 ( V_2 ) )
return - V_125 ;
V_124 = V_117 >= V_126 && V_117 < V_127 ;
if ( V_124 ) {
if ( V_117 - V_126 >= V_2 -> V_14 -> V_128 )
goto V_129;
V_115 = & V_2 -> V_14 -> V_130 [ V_117 - V_126 ] ;
} else {
if ( V_117 >= V_131 )
goto V_129;
V_115 = & V_132 [ V_117 ] ;
}
V_122 = F_32 ( V_115 -> V_111 ) ;
V_121 = V_120 = F_32 ( V_111 ) ;
if ( ( V_111 & V_115 -> V_111 & V_133 ) == 0 )
V_120 = 0 ;
if ( ( V_111 & V_115 -> V_111 & V_134 ) == 0 )
V_121 = 0 ;
V_123 = F_17 ( F_17 ( V_120 , V_121 ) , V_122 ) ;
F_19 ( L_2 ,
F_33 ( V_23 ) ,
( long ) F_34 ( V_5 -> V_85 -> V_135 -> V_136 ) ,
V_5 -> V_21 , V_115 -> V_95 ) ;
V_116 = V_115 -> V_116 ;
if ( F_24 ( ! V_116 ) ) {
F_19 ( L_3 ) ;
V_76 = - V_28 ;
goto V_129;
}
V_76 = F_23 ( V_115 -> V_101 , V_5 ) ;
if ( F_24 ( V_76 ) )
goto V_129;
if ( V_123 <= sizeof( V_118 ) ) {
V_119 = V_118 ;
} else {
V_119 = F_35 ( V_123 , V_16 ) ;
if ( ! V_119 ) {
V_76 = - V_137 ;
goto V_129;
}
}
if ( F_36 ( V_119 , ( void T_1 * ) V_112 , V_120 ) != 0 ) {
V_76 = - V_12 ;
goto V_129;
}
if ( V_123 > V_120 )
memset ( V_119 + V_120 , 0 , V_123 - V_120 ) ;
if ( ( ! F_12 ( V_2 , V_138 ) && V_124 ) ||
( V_115 -> V_101 & V_139 ) )
V_76 = V_116 ( V_2 , V_119 , V_5 ) ;
else {
F_37 ( & V_140 ) ;
V_76 = V_116 ( V_2 , V_119 , V_5 ) ;
F_38 ( & V_140 ) ;
}
if ( F_2 ( ( void T_1 * ) V_112 , V_119 , V_121 ) != 0 )
V_76 = - V_12 ;
V_129:
if ( ! V_115 )
F_19 ( L_4 ,
F_33 ( V_23 ) ,
( long ) F_34 ( V_5 -> V_85 -> V_135 -> V_136 ) ,
V_5 -> V_21 , V_111 , V_117 ) ;
if ( V_119 != V_118 )
F_4 ( V_119 ) ;
if ( V_76 )
F_19 ( L_5 , V_76 ) ;
return V_76 ;
}
bool F_39 ( unsigned int V_117 , unsigned int * V_101 )
{
if ( V_117 >= V_126 && V_117 < V_127 )
return false ;
if ( V_117 >= V_131 )
return false ;
* V_101 = V_132 [ V_117 ] . V_101 ;
return true ;
}
