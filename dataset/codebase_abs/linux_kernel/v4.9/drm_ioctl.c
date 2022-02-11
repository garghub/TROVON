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
if ( V_2 -> V_14 -> V_38 )
V_32 -> V_35 = 1 ;
break;
case V_39 :
V_32 -> V_35 = 1 ;
break;
case V_40 :
V_32 -> V_35 = V_2 -> V_41 . V_42 ;
break;
case V_43 :
V_32 -> V_35 = V_2 -> V_41 . V_44 ;
break;
case V_45 :
V_32 -> V_35 |= V_2 -> V_14 -> V_46 ? V_47 : 0 ;
V_32 -> V_35 |= V_2 -> V_14 -> V_48 ? V_49 : 0 ;
break;
case V_50 :
V_32 -> V_35 = V_51 ;
break;
case V_52 :
V_32 -> V_35 = V_2 -> V_41 . V_53 ;
break;
case V_54 :
if ( F_12 ( V_2 , V_55 ) ) {
V_32 -> V_35 = 1 ;
F_13 (crtc, dev) {
if ( ! V_34 -> V_56 -> V_57 )
V_32 -> V_35 = 0 ;
}
}
break;
case V_58 :
if ( V_2 -> V_41 . V_59 )
V_32 -> V_35 = V_2 -> V_41 . V_59 ;
else
V_32 -> V_35 = 64 ;
break;
case V_60 :
if ( V_2 -> V_41 . V_61 )
V_32 -> V_35 = V_2 -> V_41 . V_61 ;
else
V_32 -> V_35 = 64 ;
break;
case V_62 :
V_32 -> V_35 = V_2 -> V_41 . V_63 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_64 * V_32 = V_3 ;
switch ( V_32 -> V_36 ) {
case V_65 :
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_66 = V_32 -> V_35 ;
break;
case V_67 :
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_68 = V_32 -> V_35 ;
break;
case V_69 :
if ( ! F_12 ( V_2 , V_70 ) )
return - V_28 ;
if ( V_32 -> V_35 > 1 )
return - V_28 ;
V_5 -> V_71 = V_32 -> V_35 ;
V_5 -> V_68 = V_32 -> V_35 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_72 * V_73 = V_3 ;
int V_74 , V_75 = 0 ;
if ( V_73 -> V_76 != - 1 ) {
if ( V_73 -> V_76 != V_77 ||
V_73 -> V_78 < 0 || V_73 -> V_78 > V_79 ) {
V_75 = - V_28 ;
goto V_80;
}
V_74 = F_16 ( V_73 -> V_76 ,
V_73 -> V_78 ) ;
V_2 -> V_74 = F_17 ( V_74 , V_2 -> V_74 ) ;
if ( V_73 -> V_78 >= 1 ) {
V_75 = F_5 ( V_2 , V_5 ) ;
if ( V_75 )
goto V_80;
}
}
if ( V_73 -> V_81 != - 1 ) {
if ( V_73 -> V_81 != V_2 -> V_14 -> V_82 ||
V_73 -> V_83 < 0 || V_73 -> V_83 >
V_2 -> V_14 -> V_84 ) {
V_75 = - V_28 ;
goto V_80;
}
}
V_80:
V_73 -> V_76 = V_77 ;
V_73 -> V_78 = V_79 ;
V_73 -> V_81 = V_2 -> V_14 -> V_82 ;
V_73 -> V_83 = V_2 -> V_14 -> V_84 ;
return V_75 ;
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
static int F_21 ( char T_1 * V_85 , T_2 * V_86 , const char * V_35 )
{
int V_87 ;
V_87 = strlen ( V_35 ) ;
if ( V_87 > * V_86 )
V_87 = * V_86 ;
* V_86 = strlen ( V_35 ) ;
if ( V_87 && V_85 )
if ( F_2 ( V_85 , V_35 , V_87 ) )
return - V_12 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_22 * V_88 = V_3 ;
int V_89 ;
V_88 -> V_90 = V_2 -> V_14 -> V_82 ;
V_88 -> V_91 = V_2 -> V_14 -> V_84 ;
V_88 -> V_92 = V_2 -> V_14 -> V_93 ;
V_89 = F_21 ( V_88 -> V_94 , & V_88 -> V_95 ,
V_2 -> V_14 -> V_94 ) ;
if ( ! V_89 )
V_89 = F_21 ( V_88 -> V_96 , & V_88 -> V_97 ,
V_2 -> V_14 -> V_96 ) ;
if ( ! V_89 )
V_89 = F_21 ( V_88 -> V_98 , & V_88 -> V_99 ,
V_2 -> V_14 -> V_98 ) ;
return V_89 ;
}
int F_23 ( T_3 V_100 , struct V_4 * V_5 )
{
if ( F_24 ( ( V_100 & V_101 ) && ! F_25 ( V_102 ) ) )
return - V_103 ;
if ( F_24 ( ( V_100 & V_104 ) && ! F_26 ( V_5 ) &&
! V_5 -> V_21 ) )
return - V_103 ;
if ( F_24 ( ( V_100 & V_105 ) &&
! F_27 ( V_5 ) &&
! F_28 ( V_5 ) ) )
return - V_103 ;
if ( F_24 ( ! ( V_100 & V_106 ) &&
F_28 ( V_5 ) ) )
return - V_103 ;
if ( F_24 ( ! ( V_100 & V_107 ) &&
F_26 ( V_5 ) ) )
return - V_103 ;
return 0 ;
}
long F_29 ( struct V_108 * V_109 ,
unsigned int V_110 , unsigned long V_111 )
{
struct V_4 * V_5 = V_109 -> V_112 ;
struct V_1 * V_2 ;
const struct V_113 * V_114 = NULL ;
T_4 * V_115 ;
unsigned int V_116 = F_30 ( V_110 ) ;
int V_75 = - V_28 ;
char V_117 [ 128 ] ;
char * V_118 = NULL ;
unsigned int V_119 , V_120 , V_121 , V_122 ;
bool V_123 ;
V_2 = V_5 -> V_84 -> V_2 ;
if ( F_31 ( V_2 ) )
return - V_124 ;
V_123 = V_116 >= V_125 && V_116 < V_126 ;
if ( V_123 ) {
if ( V_116 - V_125 >= V_2 -> V_14 -> V_127 )
goto V_128;
V_114 = & V_2 -> V_14 -> V_129 [ V_116 - V_125 ] ;
} else {
if ( V_116 >= V_130 )
goto V_128;
V_114 = & V_131 [ V_116 ] ;
}
V_121 = F_32 ( V_114 -> V_110 ) ;
V_120 = V_119 = F_32 ( V_110 ) ;
if ( ( V_110 & V_114 -> V_110 & V_132 ) == 0 )
V_119 = 0 ;
if ( ( V_110 & V_114 -> V_110 & V_133 ) == 0 )
V_120 = 0 ;
V_122 = F_17 ( F_17 ( V_119 , V_120 ) , V_121 ) ;
F_19 ( L_2 ,
F_33 ( V_23 ) ,
( long ) F_34 ( V_5 -> V_84 -> V_134 -> V_135 ) ,
V_5 -> V_21 , V_114 -> V_94 ) ;
V_115 = V_114 -> V_115 ;
if ( F_24 ( ! V_115 ) ) {
F_19 ( L_3 ) ;
V_75 = - V_28 ;
goto V_128;
}
V_75 = F_23 ( V_114 -> V_100 , V_5 ) ;
if ( F_24 ( V_75 ) )
goto V_128;
if ( V_122 <= sizeof( V_117 ) ) {
V_118 = V_117 ;
} else {
V_118 = F_35 ( V_122 , V_16 ) ;
if ( ! V_118 ) {
V_75 = - V_136 ;
goto V_128;
}
}
if ( F_36 ( V_118 , ( void T_1 * ) V_111 , V_119 ) != 0 ) {
V_75 = - V_12 ;
goto V_128;
}
if ( V_122 > V_119 )
memset ( V_118 + V_119 , 0 , V_122 - V_119 ) ;
if ( ( ! F_12 ( V_2 , V_137 ) && V_123 ) ||
( V_114 -> V_100 & V_138 ) )
V_75 = V_115 ( V_2 , V_118 , V_5 ) ;
else {
F_37 ( & V_139 ) ;
V_75 = V_115 ( V_2 , V_118 , V_5 ) ;
F_38 ( & V_139 ) ;
}
if ( F_2 ( ( void T_1 * ) V_111 , V_118 , V_120 ) != 0 )
V_75 = - V_12 ;
V_128:
if ( ! V_114 )
F_19 ( L_4 ,
F_33 ( V_23 ) ,
( long ) F_34 ( V_5 -> V_84 -> V_134 -> V_135 ) ,
V_5 -> V_21 , V_110 , V_116 ) ;
if ( V_118 != V_117 )
F_4 ( V_118 ) ;
if ( V_75 )
F_19 ( L_5 , V_75 ) ;
return V_75 ;
}
bool F_39 ( unsigned int V_116 , unsigned int * V_100 )
{
if ( V_116 >= V_125 && V_116 < V_126 )
return false ;
if ( V_116 >= V_130 )
return false ;
* V_100 = V_131 [ V_116 ] . V_100 ;
return true ;
}
