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
default:
return - V_15 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_78 * V_79 = V_3 ;
int V_80 , V_81 = 0 ;
if ( V_79 -> V_82 != - 1 ) {
if ( V_79 -> V_82 != V_83 ||
V_79 -> V_84 < 0 || V_79 -> V_84 > V_85 ) {
V_81 = - V_15 ;
goto V_86;
}
V_80 = F_27 ( V_79 -> V_82 ,
V_79 -> V_84 ) ;
V_2 -> V_80 = F_28 ( V_80 , V_2 -> V_80 ) ;
if ( V_79 -> V_84 >= 1 ) {
V_81 = F_9 ( V_2 , V_5 ) ;
if ( V_81 )
goto V_86;
}
}
if ( V_79 -> V_87 != - 1 ) {
if ( V_79 -> V_87 != V_2 -> V_19 -> V_88 ||
V_79 -> V_89 < 0 || V_79 -> V_89 >
V_2 -> V_19 -> V_90 ) {
V_81 = - V_15 ;
goto V_86;
}
}
V_86:
V_79 -> V_82 = V_83 ;
V_79 -> V_84 = V_85 ;
V_79 -> V_87 = V_2 -> V_19 -> V_88 ;
V_79 -> V_89 = V_2 -> V_19 -> V_90 ;
return V_81 ;
}
int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_30 ( L_4 ) ;
return 0 ;
}
static int F_31 ( char T_1 * V_91 , T_2 * V_92 , const char * V_50 )
{
int V_93 ;
V_93 = strlen ( V_50 ) ;
if ( V_93 > * V_92 )
V_93 = * V_92 ;
* V_92 = strlen ( V_50 ) ;
if ( V_93 && V_91 )
if ( F_2 ( V_91 , V_50 , V_93 ) )
return - V_12 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_32 * V_94 = V_3 ;
int V_18 ;
V_94 -> V_95 = V_2 -> V_19 -> V_88 ;
V_94 -> V_96 = V_2 -> V_19 -> V_90 ;
V_94 -> V_97 = V_2 -> V_19 -> V_98 ;
V_18 = F_31 ( V_94 -> V_99 , & V_94 -> V_100 ,
V_2 -> V_19 -> V_99 ) ;
if ( ! V_18 )
V_18 = F_31 ( V_94 -> V_101 , & V_94 -> V_102 ,
V_2 -> V_19 -> V_101 ) ;
if ( ! V_18 )
V_18 = F_31 ( V_94 -> V_103 , & V_94 -> V_104 ,
V_2 -> V_19 -> V_103 ) ;
return V_18 ;
}
static int F_33 ( T_3 V_34 , struct V_4 * V_5 )
{
if ( F_34 ( ( V_34 & V_105 ) && ! F_35 ( V_106 ) ) )
return - V_107 ;
if ( F_34 ( ( V_34 & V_108 ) && ! F_36 ( V_5 ) &&
! V_5 -> V_41 ) )
return - V_107 ;
if ( F_34 ( ( V_34 & V_109 ) && ! V_5 -> V_110 &&
! F_37 ( V_5 ) ) )
return - V_107 ;
if ( F_34 ( ! ( V_34 & V_111 ) &&
F_37 ( V_5 ) ) )
return - V_107 ;
if ( F_34 ( ! ( V_34 & V_112 ) &&
F_36 ( V_5 ) ) )
return - V_107 ;
return 0 ;
}
long F_38 ( struct V_113 * V_114 ,
unsigned int V_115 , unsigned long V_116 )
{
struct V_4 * V_5 = V_114 -> V_117 ;
struct V_1 * V_2 ;
const struct V_118 * V_119 = NULL ;
T_4 * V_120 ;
unsigned int V_121 = F_39 ( V_115 ) ;
int V_81 = - V_15 ;
char V_122 [ 128 ] ;
char * V_123 = NULL ;
unsigned int V_124 , V_125 ;
V_2 = V_5 -> V_90 -> V_2 ;
if ( F_40 ( V_2 ) )
return - V_126 ;
if ( ( V_121 >= V_127 ) &&
( ( V_121 < V_128 ) || ( V_121 >= V_129 ) ) )
goto V_130;
if ( ( V_121 >= V_128 ) && ( V_121 < V_129 ) &&
( V_121 < V_128 + V_2 -> V_19 -> V_131 ) ) {
T_3 V_132 ;
V_119 = & V_2 -> V_19 -> V_133 [ V_121 - V_128 ] ;
V_132 = F_41 ( V_119 -> V_134 ) ;
V_124 = V_125 = F_41 ( V_115 ) ;
if ( V_132 > V_125 )
V_125 = V_132 ;
V_115 = V_119 -> V_134 ;
}
else if ( ( V_121 >= V_129 ) || ( V_121 < V_128 ) ) {
T_3 V_132 ;
V_119 = & V_135 [ V_121 ] ;
V_132 = F_41 ( V_119 -> V_115 ) ;
V_124 = V_125 = F_41 ( V_115 ) ;
if ( V_132 > V_125 )
V_125 = V_132 ;
V_115 = V_119 -> V_115 ;
} else
goto V_130;
F_30 ( L_5 ,
F_42 ( V_136 ) ,
( long ) F_43 ( V_5 -> V_90 -> V_137 -> V_138 ) ,
V_5 -> V_41 , V_119 -> V_99 ) ;
V_120 = V_119 -> V_120 ;
if ( F_34 ( ! V_120 ) ) {
F_30 ( L_6 ) ;
V_81 = - V_15 ;
goto V_130;
}
V_81 = F_33 ( V_119 -> V_34 , V_5 ) ;
if ( F_34 ( V_81 ) )
goto V_130;
if ( V_115 & ( V_139 | V_140 ) ) {
if ( V_125 <= sizeof( V_122 ) ) {
V_123 = V_122 ;
} else {
V_123 = F_44 ( V_125 , V_21 ) ;
if ( ! V_123 ) {
V_81 = - V_141 ;
goto V_130;
}
}
if ( V_125 > V_124 )
memset ( V_123 + V_124 , 0 , V_125 - V_124 ) ;
}
if ( V_115 & V_139 ) {
if ( F_45 ( V_123 , ( void T_1 * ) V_116 ,
V_124 ) != 0 ) {
V_81 = - V_12 ;
goto V_130;
}
} else if ( V_115 & V_140 ) {
memset ( V_123 , 0 , V_124 ) ;
}
if ( V_119 -> V_34 & V_142 )
V_81 = V_120 ( V_2 , V_123 , V_5 ) ;
else {
F_13 ( & V_143 ) ;
V_81 = V_120 ( V_2 , V_123 , V_5 ) ;
F_16 ( & V_143 ) ;
}
if ( V_115 & V_140 ) {
if ( F_2 ( ( void T_1 * ) V_116 , V_123 ,
V_124 ) != 0 )
V_81 = - V_12 ;
}
V_130:
if ( ! V_119 )
F_30 ( L_7 ,
F_42 ( V_136 ) ,
( long ) F_43 ( V_5 -> V_90 -> V_137 -> V_138 ) ,
V_5 -> V_41 , V_115 , V_121 ) ;
if ( V_123 != V_122 )
F_4 ( V_123 ) ;
if ( V_81 )
F_30 ( L_8 , V_81 ) ;
return V_81 ;
}
bool F_46 ( unsigned int V_121 , unsigned int * V_34 )
{
if ( ( V_121 >= V_129 && V_121 < V_127 ) ||
( V_121 < V_128 ) ) {
* V_34 = V_135 [ V_121 ] . V_34 ;
return true ;
}
return false ;
}
