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
static int F_5 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_13 ;
if ( V_9 -> V_10 || V_9 -> V_11 )
return - V_14 ;
if ( ! V_7 -> V_10 || V_7 -> V_10 > 1024 )
return - V_15 ;
if ( F_6 ( V_2 , V_16 ) )
return 0 ;
if ( F_7 ( ! V_2 -> V_17 ) )
return - V_15 ;
V_13 = F_8 ( V_2 , V_9 , V_7 ) ;
if ( V_13 )
goto V_18;
return 0 ;
V_18:
F_3 ( V_2 , V_9 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
int V_13 ;
if ( V_9 -> V_11 != NULL )
F_3 ( V_2 , V_9 ) ;
if ( V_2 -> V_19 -> V_20 ) {
V_13 = V_2 -> V_19 -> V_20 ( V_2 , V_9 ) ;
if ( V_13 ) {
F_3 ( V_2 , V_9 ) ;
return V_13 ;
}
} else {
if ( F_10 ( V_2 -> V_11 == NULL ,
L_1
L_2
L_3 , V_2 -> V_19 ) )
return - V_15 ;
V_9 -> V_11 = F_11 ( V_2 -> V_11 , V_21 ) ;
if ( V_9 -> V_11 )
V_9 -> V_10 = strlen ( V_2 -> V_11 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_22 * V_23 = V_3 ;
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
int V_28 ;
int V_29 ;
V_28 = V_23 -> V_30 ;
if ( V_28 < 0 )
return - V_15 ;
V_29 = 0 ;
F_13 ( & V_2 -> V_31 ) ;
F_14 (list, &dev->maplist) {
if ( V_29 == V_28 ) {
V_25 = F_15 ( V_27 , struct V_24 , V_32 ) ;
break;
}
V_29 ++ ;
}
if ( ! V_25 || ! V_25 -> V_23 ) {
F_16 ( & V_2 -> V_31 ) ;
return - V_15 ;
}
V_23 -> V_30 = V_25 -> V_23 -> V_30 ;
V_23 -> V_33 = V_25 -> V_23 -> V_33 ;
V_23 -> type = V_25 -> V_23 -> type ;
V_23 -> V_34 = V_25 -> V_23 -> V_34 ;
V_23 -> V_35 = ( void * ) ( unsigned long ) V_25 -> V_36 ;
#ifdef F_17
V_23 -> V_37 = F_18 ( V_25 -> V_23 -> V_37 ) ;
#else
V_23 -> V_37 = - 1 ;
#endif
F_16 ( & V_2 -> V_31 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_38 * V_39 = V_3 ;
if ( V_39 -> V_28 == 0 ) {
V_39 -> V_40 = V_5 -> V_41 ;
V_39 -> V_42 = F_20 ( V_5 -> V_42 ) ;
V_39 -> V_43 = F_21 ( F_22 () ,
V_5 -> V_43 ) ;
V_39 -> V_44 = 0 ;
V_39 -> V_45 = 0 ;
return 0 ;
} else {
return - V_15 ;
}
}
static int F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_46 * V_47 = V_3 ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_48 * V_49 = V_3 ;
V_49 -> V_50 = 0 ;
switch ( V_49 -> V_51 ) {
case V_52 :
if ( V_2 -> V_19 -> V_53 )
V_49 -> V_50 = 1 ;
break;
case V_54 :
V_49 -> V_50 = 1 ;
break;
case V_55 :
V_49 -> V_50 = V_2 -> V_56 . V_57 ;
break;
case V_58 :
V_49 -> V_50 = V_2 -> V_56 . V_59 ;
break;
case V_60 :
V_49 -> V_50 |= V_2 -> V_19 -> V_61 ? V_62 : 0 ;
V_49 -> V_50 |= V_2 -> V_19 -> V_63 ? V_64 : 0 ;
break;
case V_65 :
V_49 -> V_50 = V_66 ;
break;
case V_67 :
V_49 -> V_50 = V_2 -> V_56 . V_68 ;
break;
case V_69 :
if ( V_2 -> V_56 . V_70 )
V_49 -> V_50 = V_2 -> V_56 . V_70 ;
else
V_49 -> V_50 = 64 ;
break;
case V_71 :
if ( V_2 -> V_56 . V_72 )
V_49 -> V_50 = V_2 -> V_56 . V_72 ;
else
V_49 -> V_50 = 64 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_73 * V_49 = V_3 ;
switch ( V_49 -> V_51 ) {
case V_74 :
if ( V_49 -> V_50 > 1 )
return - V_15 ;
V_5 -> V_75 = V_49 -> V_50 ;
break;
case V_76 :
if ( V_49 -> V_50 > 1 )
return - V_15 ;
V_5 -> V_77 = V_49 -> V_50 ;
break;
case V_78 :
if ( ! V_79 )
return - V_15 ;
if ( ! F_6 ( V_2 , V_80 ) )
return - V_15 ;
if ( V_49 -> V_50 > 1 )
return - V_15 ;
V_5 -> V_81 = V_49 -> V_50 ;
V_5 -> V_77 = V_49 -> V_50 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_82 * V_83 = V_3 ;
int V_84 , V_85 = 0 ;
if ( V_83 -> V_86 != - 1 ) {
if ( V_83 -> V_86 != V_87 ||
V_83 -> V_88 < 0 || V_83 -> V_88 > V_89 ) {
V_85 = - V_15 ;
goto V_90;
}
V_84 = F_27 ( V_83 -> V_86 ,
V_83 -> V_88 ) ;
V_2 -> V_84 = F_28 ( V_84 , V_2 -> V_84 ) ;
if ( V_83 -> V_88 >= 1 ) {
V_85 = F_9 ( V_2 , V_5 ) ;
if ( V_85 )
goto V_90;
}
}
if ( V_83 -> V_91 != - 1 ) {
if ( V_83 -> V_91 != V_2 -> V_19 -> V_92 ||
V_83 -> V_93 < 0 || V_83 -> V_93 >
V_2 -> V_19 -> V_94 ) {
V_85 = - V_15 ;
goto V_90;
}
}
V_90:
V_83 -> V_86 = V_87 ;
V_83 -> V_88 = V_89 ;
V_83 -> V_91 = V_2 -> V_19 -> V_92 ;
V_83 -> V_93 = V_2 -> V_19 -> V_94 ;
return V_85 ;
}
int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_30 ( L_4 ) ;
return 0 ;
}
static int F_31 ( char T_1 * V_95 , T_2 * V_96 , const char * V_50 )
{
int V_97 ;
V_97 = strlen ( V_50 ) ;
if ( V_97 > * V_96 )
V_97 = * V_96 ;
* V_96 = strlen ( V_50 ) ;
if ( V_97 && V_95 )
if ( F_2 ( V_95 , V_50 , V_97 ) )
return - V_12 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_32 * V_98 = V_3 ;
int V_18 ;
V_98 -> V_99 = V_2 -> V_19 -> V_92 ;
V_98 -> V_100 = V_2 -> V_19 -> V_94 ;
V_98 -> V_101 = V_2 -> V_19 -> V_102 ;
V_18 = F_31 ( V_98 -> V_103 , & V_98 -> V_104 ,
V_2 -> V_19 -> V_103 ) ;
if ( ! V_18 )
V_18 = F_31 ( V_98 -> V_105 , & V_98 -> V_106 ,
V_2 -> V_19 -> V_105 ) ;
if ( ! V_18 )
V_18 = F_31 ( V_98 -> V_107 , & V_98 -> V_108 ,
V_2 -> V_19 -> V_107 ) ;
return V_18 ;
}
static int F_33 ( T_3 V_34 , struct V_4 * V_5 )
{
if ( F_34 ( ( V_34 & V_109 ) && ! F_35 ( V_110 ) ) )
return - V_111 ;
if ( F_34 ( ( V_34 & V_112 ) && ! F_36 ( V_5 ) &&
! V_5 -> V_41 ) )
return - V_111 ;
if ( F_34 ( ( V_34 & V_113 ) && ! V_5 -> V_114 &&
! F_37 ( V_5 ) ) )
return - V_111 ;
if ( F_34 ( ! ( V_34 & V_115 ) &&
F_37 ( V_5 ) ) )
return - V_111 ;
if ( F_34 ( ! ( V_34 & V_116 ) &&
F_36 ( V_5 ) ) )
return - V_111 ;
return 0 ;
}
long F_38 ( struct V_117 * V_118 ,
unsigned int V_119 , unsigned long V_120 )
{
struct V_4 * V_5 = V_118 -> V_121 ;
struct V_1 * V_2 ;
const struct V_122 * V_123 = NULL ;
T_4 * V_124 ;
unsigned int V_125 = F_39 ( V_119 ) ;
int V_85 = - V_15 ;
char V_126 [ 128 ] ;
char * V_127 = NULL ;
unsigned int V_128 , V_129 ;
V_2 = V_5 -> V_94 -> V_2 ;
if ( F_40 ( V_2 ) )
return - V_130 ;
if ( ( V_125 >= V_131 ) &&
( ( V_125 < V_132 ) || ( V_125 >= V_133 ) ) )
goto V_134;
if ( ( V_125 >= V_132 ) && ( V_125 < V_133 ) &&
( V_125 < V_132 + V_2 -> V_19 -> V_135 ) ) {
T_3 V_136 ;
V_123 = & V_2 -> V_19 -> V_137 [ V_125 - V_132 ] ;
V_136 = F_41 ( V_123 -> V_138 ) ;
V_128 = V_129 = F_41 ( V_119 ) ;
if ( V_136 > V_129 )
V_129 = V_136 ;
V_119 = V_123 -> V_138 ;
}
else if ( ( V_125 >= V_133 ) || ( V_125 < V_132 ) ) {
T_3 V_136 ;
V_123 = & V_139 [ V_125 ] ;
V_136 = F_41 ( V_123 -> V_119 ) ;
V_128 = V_129 = F_41 ( V_119 ) ;
if ( V_136 > V_129 )
V_129 = V_136 ;
V_119 = V_123 -> V_119 ;
} else
goto V_134;
F_30 ( L_5 ,
F_42 ( V_140 ) ,
( long ) F_43 ( V_5 -> V_94 -> V_141 -> V_142 ) ,
V_5 -> V_41 , V_123 -> V_103 ) ;
V_124 = V_123 -> V_124 ;
if ( F_34 ( ! V_124 ) ) {
F_30 ( L_6 ) ;
V_85 = - V_15 ;
goto V_134;
}
V_85 = F_33 ( V_123 -> V_34 , V_5 ) ;
if ( F_34 ( V_85 ) )
goto V_134;
if ( V_119 & ( V_143 | V_144 ) ) {
if ( V_129 <= sizeof( V_126 ) ) {
V_127 = V_126 ;
} else {
V_127 = F_44 ( V_129 , V_21 ) ;
if ( ! V_127 ) {
V_85 = - V_145 ;
goto V_134;
}
}
if ( V_129 > V_128 )
memset ( V_127 + V_128 , 0 , V_129 - V_128 ) ;
}
if ( V_119 & V_143 ) {
if ( F_45 ( V_127 , ( void T_1 * ) V_120 ,
V_128 ) != 0 ) {
V_85 = - V_12 ;
goto V_134;
}
} else if ( V_119 & V_144 ) {
memset ( V_127 , 0 , V_128 ) ;
}
if ( V_123 -> V_34 & V_146 )
V_85 = V_124 ( V_2 , V_127 , V_5 ) ;
else {
F_13 ( & V_147 ) ;
V_85 = V_124 ( V_2 , V_127 , V_5 ) ;
F_16 ( & V_147 ) ;
}
if ( V_119 & V_144 ) {
if ( F_2 ( ( void T_1 * ) V_120 , V_127 ,
V_128 ) != 0 )
V_85 = - V_12 ;
}
V_134:
if ( ! V_123 )
F_30 ( L_7 ,
F_42 ( V_140 ) ,
( long ) F_43 ( V_5 -> V_94 -> V_141 -> V_142 ) ,
V_5 -> V_41 , V_119 , V_125 ) ;
if ( V_127 != V_126 )
F_4 ( V_127 ) ;
if ( V_85 )
F_30 ( L_8 , V_85 ) ;
return V_85 ;
}
bool F_46 ( unsigned int V_125 , unsigned int * V_34 )
{
if ( ( V_125 >= V_133 && V_125 < V_131 ) ||
( V_125 < V_132 ) ) {
* V_34 = V_139 [ V_125 ] . V_34 ;
return true ;
}
return false ;
}
