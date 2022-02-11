static int F_1 ( struct V_1 * V_2 , void * V_3 ,
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
if ( V_2 -> V_15 -> V_16 ) {
V_14 = V_2 -> V_15 -> V_16 ( V_2 , V_9 ) ;
if ( V_14 ) {
F_5 ( V_2 , V_9 ) ;
return V_14 ;
}
} else {
F_8 ( ! V_2 -> V_12 ) ;
V_9 -> V_12 = F_9 ( V_2 -> V_12 , V_17 ) ;
if ( V_9 -> V_12 )
V_9 -> V_11 = strlen ( V_2 -> V_12 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_18 * V_19 = V_3 ;
if ( V_19 -> V_20 == 0 ) {
V_19 -> V_21 = V_5 -> V_22 ;
V_19 -> V_23 = F_11 ( V_24 ) ;
V_19 -> V_25 = V_26 ;
V_19 -> V_27 = 0 ;
V_19 -> V_28 = 0 ;
return 0 ;
} else {
return - V_29 ;
}
}
static int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_30 * V_31 = V_3 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_32 * V_33 = V_3 ;
struct V_34 * V_35 ;
V_33 -> V_36 = 0 ;
switch ( V_33 -> V_37 ) {
case V_38 :
V_33 -> V_36 = V_39 ;
return 0 ;
case V_40 :
V_33 -> V_36 |= V_2 -> V_15 -> V_41 ? V_42 : 0 ;
V_33 -> V_36 |= V_2 -> V_15 -> V_43 ? V_44 : 0 ;
return 0 ;
}
if ( ! F_14 ( V_2 , V_45 ) )
return - V_46 ;
switch ( V_33 -> V_37 ) {
case V_47 :
if ( V_2 -> V_15 -> V_48 )
V_33 -> V_36 = 1 ;
break;
case V_49 :
V_33 -> V_36 = 1 ;
break;
case V_50 :
V_33 -> V_36 = V_2 -> V_51 . V_52 ;
break;
case V_53 :
V_33 -> V_36 = V_2 -> V_51 . V_54 ;
break;
case V_55 :
V_33 -> V_36 = V_2 -> V_51 . V_56 ;
break;
case V_57 :
V_33 -> V_36 = 1 ;
F_15 (crtc, dev) {
if ( ! V_35 -> V_58 -> V_59 )
V_33 -> V_36 = 0 ;
}
break;
case V_60 :
if ( V_2 -> V_51 . V_61 )
V_33 -> V_36 = V_2 -> V_51 . V_61 ;
else
V_33 -> V_36 = 64 ;
break;
case V_62 :
if ( V_2 -> V_51 . V_63 )
V_33 -> V_36 = V_2 -> V_51 . V_63 ;
else
V_33 -> V_36 = 64 ;
break;
case V_64 :
V_33 -> V_36 = V_2 -> V_51 . V_65 ;
break;
case V_66 :
V_33 -> V_36 = 1 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_67 * V_33 = V_3 ;
switch ( V_33 -> V_37 ) {
case V_68 :
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_69 = V_33 -> V_36 ;
break;
case V_70 :
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_71 = V_33 -> V_36 ;
break;
case V_72 :
if ( ! F_14 ( V_2 , V_73 ) )
return - V_29 ;
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_74 = V_33 -> V_36 ;
V_5 -> V_71 = V_33 -> V_36 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_75 * V_76 = V_3 ;
int V_77 , V_78 = 0 ;
F_2 ( & V_2 -> V_10 ) ;
if ( V_76 -> V_79 != - 1 ) {
if ( V_76 -> V_79 != V_80 ||
V_76 -> V_81 < 0 || V_76 -> V_81 > V_82 ) {
V_78 = - V_29 ;
goto V_83;
}
V_77 = F_18 ( V_76 -> V_79 ,
V_76 -> V_81 ) ;
V_2 -> V_77 = F_19 ( V_77 , V_2 -> V_77 ) ;
if ( V_76 -> V_81 >= 1 ) {
V_78 = F_7 ( V_2 , V_5 ) ;
if ( V_78 )
goto V_83;
}
}
if ( V_76 -> V_84 != - 1 ) {
if ( V_76 -> V_84 != V_2 -> V_15 -> V_85 ||
V_76 -> V_86 < 0 || V_76 -> V_86 >
V_2 -> V_15 -> V_87 ) {
V_78 = - V_29 ;
goto V_83;
}
}
V_83:
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_82 ;
V_76 -> V_84 = V_2 -> V_15 -> V_85 ;
V_76 -> V_86 = V_2 -> V_15 -> V_87 ;
F_4 ( & V_2 -> V_10 ) ;
return V_78 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_21 ( L_1 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return - V_29 ;
}
static int F_23 ( char T_1 * V_88 , T_2 * V_89 , const char * V_36 )
{
int V_90 ;
V_90 = strlen ( V_36 ) ;
if ( V_90 > * V_89 )
V_90 = * V_89 ;
* V_89 = strlen ( V_36 ) ;
if ( V_90 && V_88 )
if ( F_3 ( V_88 , V_36 , V_90 ) )
return - V_13 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_24 * V_91 = V_3 ;
int V_92 ;
V_91 -> V_93 = V_2 -> V_15 -> V_85 ;
V_91 -> V_94 = V_2 -> V_15 -> V_87 ;
V_91 -> V_95 = V_2 -> V_15 -> V_96 ;
V_92 = F_23 ( V_91 -> V_97 , & V_91 -> V_98 ,
V_2 -> V_15 -> V_97 ) ;
if ( ! V_92 )
V_92 = F_23 ( V_91 -> V_99 , & V_91 -> V_100 ,
V_2 -> V_15 -> V_99 ) ;
if ( ! V_92 )
V_92 = F_23 ( V_91 -> V_101 , & V_91 -> V_102 ,
V_2 -> V_15 -> V_101 ) ;
return V_92 ;
}
int F_25 ( T_3 V_103 , struct V_4 * V_5 )
{
if ( F_26 ( ( V_103 & V_104 ) && ! F_27 ( V_105 ) ) )
return - V_106 ;
if ( F_26 ( ( V_103 & V_107 ) && ! F_28 ( V_5 ) &&
! V_5 -> V_22 ) )
return - V_106 ;
if ( F_26 ( ( V_103 & V_108 ) &&
! F_29 ( V_5 ) &&
! F_30 ( V_5 ) ) )
return - V_106 ;
if ( F_26 ( ! ( V_103 & V_109 ) &&
F_30 ( V_5 ) ) )
return - V_106 ;
if ( F_26 ( ! ( V_103 & V_110 ) &&
F_28 ( V_5 ) ) )
return - V_106 ;
return 0 ;
}
long F_31 ( struct V_111 * V_112 ,
unsigned int V_113 , unsigned long V_114 )
{
struct V_4 * V_5 = V_112 -> V_115 ;
struct V_1 * V_2 ;
const struct V_116 * V_117 = NULL ;
T_4 * V_118 ;
unsigned int V_119 = F_32 ( V_113 ) ;
int V_78 = - V_29 ;
char V_120 [ 128 ] ;
char * V_121 = NULL ;
unsigned int V_122 , V_123 , V_124 , V_125 ;
bool V_126 ;
V_2 = V_5 -> V_87 -> V_2 ;
if ( F_33 ( V_2 ) )
return - V_127 ;
V_126 = V_119 >= V_128 && V_119 < V_129 ;
if ( V_126 ) {
if ( V_119 - V_128 >= V_2 -> V_15 -> V_130 )
goto V_131;
V_117 = & V_2 -> V_15 -> V_132 [ V_119 - V_128 ] ;
} else {
if ( V_119 >= V_133 )
goto V_131;
V_117 = & V_134 [ V_119 ] ;
}
V_124 = F_34 ( V_117 -> V_113 ) ;
V_123 = V_122 = F_34 ( V_113 ) ;
if ( ( V_113 & V_117 -> V_113 & V_135 ) == 0 )
V_122 = 0 ;
if ( ( V_113 & V_117 -> V_113 & V_136 ) == 0 )
V_123 = 0 ;
V_125 = F_19 ( F_19 ( V_122 , V_123 ) , V_124 ) ;
F_21 ( L_2 ,
F_35 ( V_24 ) ,
( long ) F_36 ( V_5 -> V_87 -> V_137 -> V_138 ) ,
V_5 -> V_22 , V_117 -> V_97 ) ;
V_118 = V_117 -> V_118 ;
if ( F_26 ( ! V_118 ) ) {
F_21 ( L_3 ) ;
V_78 = - V_29 ;
goto V_131;
}
V_78 = F_25 ( V_117 -> V_103 , V_5 ) ;
if ( F_26 ( V_78 ) )
goto V_131;
if ( V_125 <= sizeof( V_120 ) ) {
V_121 = V_120 ;
} else {
V_121 = F_37 ( V_125 , V_17 ) ;
if ( ! V_121 ) {
V_78 = - V_139 ;
goto V_131;
}
}
if ( F_38 ( V_121 , ( void T_1 * ) V_114 , V_122 ) != 0 ) {
V_78 = - V_13 ;
goto V_131;
}
if ( V_125 > V_122 )
memset ( V_121 + V_122 , 0 , V_125 - V_122 ) ;
if ( ! F_14 ( V_2 , V_140 ) ||
( V_117 -> V_103 & V_141 ) )
V_78 = V_118 ( V_2 , V_121 , V_5 ) ;
else {
F_2 ( & V_142 ) ;
V_78 = V_118 ( V_2 , V_121 , V_5 ) ;
F_4 ( & V_142 ) ;
}
if ( F_3 ( ( void T_1 * ) V_114 , V_121 , V_123 ) != 0 )
V_78 = - V_13 ;
V_131:
if ( ! V_117 )
F_21 ( L_4 ,
F_35 ( V_24 ) ,
( long ) F_36 ( V_5 -> V_87 -> V_137 -> V_138 ) ,
V_5 -> V_22 , V_113 , V_119 ) ;
if ( V_121 != V_120 )
F_6 ( V_121 ) ;
if ( V_78 )
F_21 ( L_5 , V_78 ) ;
return V_78 ;
}
bool F_39 ( unsigned int V_119 , unsigned int * V_103 )
{
if ( V_119 >= V_128 && V_119 < V_129 )
return false ;
if ( V_119 >= V_133 )
return false ;
* V_103 = V_134 [ V_119 ] . V_103 ;
return true ;
}
