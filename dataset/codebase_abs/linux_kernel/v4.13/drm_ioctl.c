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
int F_10 ( struct V_1 * V_2 , void * V_3 ,
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
case V_45 :
V_33 -> V_36 = F_14 ( V_2 , V_46 ) ;
return 0 ;
}
if ( ! F_14 ( V_2 , V_47 ) )
return - V_48 ;
switch ( V_33 -> V_37 ) {
case V_49 :
if ( V_2 -> V_15 -> V_50 )
V_33 -> V_36 = 1 ;
break;
case V_51 :
V_33 -> V_36 = 1 ;
break;
case V_52 :
V_33 -> V_36 = V_2 -> V_53 . V_54 ;
break;
case V_55 :
V_33 -> V_36 = V_2 -> V_53 . V_56 ;
break;
case V_57 :
V_33 -> V_36 = V_2 -> V_53 . V_58 ;
break;
case V_59 :
V_33 -> V_36 = 1 ;
F_15 (crtc, dev) {
if ( ! V_35 -> V_60 -> V_61 )
V_33 -> V_36 = 0 ;
}
break;
case V_62 :
if ( V_2 -> V_53 . V_63 )
V_33 -> V_36 = V_2 -> V_53 . V_63 ;
else
V_33 -> V_36 = 64 ;
break;
case V_64 :
if ( V_2 -> V_53 . V_65 )
V_33 -> V_36 = V_2 -> V_53 . V_65 ;
else
V_33 -> V_36 = 64 ;
break;
case V_66 :
V_33 -> V_36 = V_2 -> V_53 . V_67 ;
break;
case V_68 :
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
struct V_69 * V_33 = V_3 ;
switch ( V_33 -> V_37 ) {
case V_70 :
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_71 = V_33 -> V_36 ;
break;
case V_72 :
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_73 = V_33 -> V_36 ;
break;
case V_74 :
if ( ! F_14 ( V_2 , V_75 ) )
return - V_29 ;
if ( V_33 -> V_36 > 1 )
return - V_29 ;
V_5 -> V_76 = V_33 -> V_36 ;
V_5 -> V_73 = V_33 -> V_36 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_77 * V_78 = V_3 ;
int V_79 , V_80 = 0 ;
F_2 ( & V_2 -> V_10 ) ;
if ( V_78 -> V_81 != - 1 ) {
if ( V_78 -> V_81 != V_82 ||
V_78 -> V_83 < 0 || V_78 -> V_83 > V_84 ) {
V_80 = - V_29 ;
goto V_85;
}
V_79 = F_18 ( V_78 -> V_81 ,
V_78 -> V_83 ) ;
V_2 -> V_79 = F_19 ( V_79 , V_2 -> V_79 ) ;
if ( V_78 -> V_83 >= 1 ) {
V_80 = F_7 ( V_2 , V_5 ) ;
if ( V_80 )
goto V_85;
}
}
if ( V_78 -> V_86 != - 1 ) {
if ( V_78 -> V_86 != V_2 -> V_15 -> V_87 ||
V_78 -> V_88 < 0 || V_78 -> V_88 >
V_2 -> V_15 -> V_89 ) {
V_80 = - V_29 ;
goto V_85;
}
}
V_85:
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = V_84 ;
V_78 -> V_86 = V_2 -> V_15 -> V_87 ;
V_78 -> V_88 = V_2 -> V_15 -> V_89 ;
F_4 ( & V_2 -> V_10 ) ;
return V_80 ;
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
static int F_23 ( char T_1 * V_90 , T_2 * V_91 , const char * V_36 )
{
int V_92 ;
V_92 = strlen ( V_36 ) ;
if ( V_92 > * V_91 )
V_92 = * V_91 ;
* V_91 = strlen ( V_36 ) ;
if ( V_92 && V_90 )
if ( F_3 ( V_90 , V_36 , V_92 ) )
return - V_13 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_24 * V_93 = V_3 ;
int V_94 ;
V_93 -> V_95 = V_2 -> V_15 -> V_87 ;
V_93 -> V_96 = V_2 -> V_15 -> V_89 ;
V_93 -> V_97 = V_2 -> V_15 -> V_98 ;
V_94 = F_23 ( V_93 -> V_99 , & V_93 -> V_100 ,
V_2 -> V_15 -> V_99 ) ;
if ( ! V_94 )
V_94 = F_23 ( V_93 -> V_101 , & V_93 -> V_102 ,
V_2 -> V_15 -> V_101 ) ;
if ( ! V_94 )
V_94 = F_23 ( V_93 -> V_103 , & V_93 -> V_104 ,
V_2 -> V_15 -> V_103 ) ;
return V_94 ;
}
int F_25 ( T_3 V_105 , struct V_4 * V_5 )
{
if ( F_26 ( ( V_105 & V_106 ) && ! F_27 ( V_107 ) ) )
return - V_108 ;
if ( F_26 ( ( V_105 & V_109 ) && ! F_28 ( V_5 ) &&
! V_5 -> V_22 ) )
return - V_108 ;
if ( F_26 ( ( V_105 & V_110 ) &&
! F_29 ( V_5 ) &&
! F_30 ( V_5 ) ) )
return - V_108 ;
if ( F_26 ( ! ( V_105 & V_111 ) &&
F_30 ( V_5 ) ) )
return - V_108 ;
if ( F_26 ( ! ( V_105 & V_112 ) &&
F_28 ( V_5 ) ) )
return - V_108 ;
return 0 ;
}
long F_31 ( struct V_113 * V_113 , T_4 * V_114 , void * V_115 ,
T_3 V_105 )
{
struct V_4 * V_5 = V_113 -> V_116 ;
struct V_1 * V_2 = V_5 -> V_89 -> V_2 ;
int V_80 ;
if ( F_32 ( V_2 ) )
return - V_117 ;
V_80 = F_25 ( V_105 , V_5 ) ;
if ( F_26 ( V_80 ) )
return V_80 ;
if ( ! F_14 ( V_2 , V_118 ) ||
( V_105 & V_119 ) )
V_80 = V_114 ( V_2 , V_115 , V_5 ) ;
else {
F_2 ( & V_120 ) ;
V_80 = V_114 ( V_2 , V_115 , V_5 ) ;
F_4 ( & V_120 ) ;
}
return V_80 ;
}
long F_33 ( struct V_113 * V_121 ,
unsigned int V_122 , unsigned long V_123 )
{
struct V_4 * V_5 = V_121 -> V_116 ;
struct V_1 * V_2 ;
const struct V_124 * V_125 = NULL ;
T_4 * V_114 ;
unsigned int V_126 = F_34 ( V_122 ) ;
int V_80 = - V_29 ;
char V_127 [ 128 ] ;
char * V_115 = NULL ;
unsigned int V_128 , V_129 , V_130 , V_131 ;
bool V_132 ;
V_2 = V_5 -> V_89 -> V_2 ;
if ( F_32 ( V_2 ) )
return - V_117 ;
V_132 = V_126 >= V_133 && V_126 < V_134 ;
if ( V_132 ) {
if ( V_126 - V_133 >= V_2 -> V_15 -> V_135 )
goto V_136;
V_125 = & V_2 -> V_15 -> V_137 [ V_126 - V_133 ] ;
} else {
if ( V_126 >= V_138 )
goto V_136;
V_125 = & V_139 [ V_126 ] ;
}
V_130 = F_35 ( V_125 -> V_122 ) ;
V_129 = V_128 = F_35 ( V_122 ) ;
if ( ( V_122 & V_125 -> V_122 & V_140 ) == 0 )
V_128 = 0 ;
if ( ( V_122 & V_125 -> V_122 & V_141 ) == 0 )
V_129 = 0 ;
V_131 = F_19 ( F_19 ( V_128 , V_129 ) , V_130 ) ;
F_21 ( L_2 ,
F_36 ( V_24 ) ,
( long ) F_37 ( V_5 -> V_89 -> V_142 -> V_143 ) ,
V_5 -> V_22 , V_125 -> V_99 ) ;
V_114 = V_125 -> V_114 ;
if ( F_26 ( ! V_114 ) ) {
F_21 ( L_3 ) ;
V_80 = - V_29 ;
goto V_136;
}
if ( V_131 <= sizeof( V_127 ) ) {
V_115 = V_127 ;
} else {
V_115 = F_38 ( V_131 , V_17 ) ;
if ( ! V_115 ) {
V_80 = - V_144 ;
goto V_136;
}
}
if ( F_39 ( V_115 , ( void T_1 * ) V_123 , V_128 ) != 0 ) {
V_80 = - V_13 ;
goto V_136;
}
if ( V_131 > V_128 )
memset ( V_115 + V_128 , 0 , V_131 - V_128 ) ;
V_80 = F_31 ( V_121 , V_114 , V_115 , V_125 -> V_105 ) ;
if ( F_3 ( ( void T_1 * ) V_123 , V_115 , V_129 ) != 0 )
V_80 = - V_13 ;
V_136:
if ( ! V_125 )
F_21 ( L_4 ,
F_36 ( V_24 ) ,
( long ) F_37 ( V_5 -> V_89 -> V_142 -> V_143 ) ,
V_5 -> V_22 , V_122 , V_126 ) ;
if ( V_115 != V_127 )
F_6 ( V_115 ) ;
if ( V_80 )
F_21 ( L_5 , V_80 ) ;
return V_80 ;
}
bool F_40 ( unsigned int V_126 , unsigned int * V_105 )
{
if ( V_126 >= V_133 && V_126 < V_134 )
return false ;
if ( V_126 >= V_138 )
return false ;
* V_105 = V_139 [ V_126 ] . V_105 ;
return true ;
}
