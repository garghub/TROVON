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
if ( V_23 -> V_24 == 0 ) {
V_23 -> V_25 = V_5 -> V_26 ;
V_23 -> V_27 = F_13 ( V_5 -> V_27 ) ;
V_23 -> V_28 = F_14 ( F_15 () ,
V_5 -> V_28 ) ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = 0 ;
return 0 ;
} else {
return - V_15 ;
}
}
static int F_16 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_31 * V_32 = V_3 ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_33 * V_34 = V_3 ;
V_34 -> V_35 = 0 ;
switch ( V_34 -> V_36 ) {
case V_37 :
if ( V_2 -> V_19 -> V_38 )
V_34 -> V_35 = 1 ;
break;
case V_39 :
V_34 -> V_35 = 1 ;
break;
case V_40 :
V_34 -> V_35 = V_2 -> V_41 . V_42 ;
break;
case V_43 :
V_34 -> V_35 = V_2 -> V_41 . V_44 ;
break;
case V_45 :
V_34 -> V_35 |= V_2 -> V_19 -> V_46 ? V_47 : 0 ;
V_34 -> V_35 |= V_2 -> V_19 -> V_48 ? V_49 : 0 ;
break;
case V_50 :
V_34 -> V_35 = V_51 ;
break;
case V_52 :
V_34 -> V_35 = V_2 -> V_41 . V_53 ;
break;
case V_54 :
if ( V_2 -> V_41 . V_55 )
V_34 -> V_35 = V_2 -> V_41 . V_55 ;
else
V_34 -> V_35 = 64 ;
break;
case V_56 :
if ( V_2 -> V_41 . V_57 )
V_34 -> V_35 = V_2 -> V_41 . V_57 ;
else
V_34 -> V_35 = 64 ;
break;
case V_58 :
V_34 -> V_35 = V_2 -> V_41 . V_59 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_60 * V_34 = V_3 ;
switch ( V_34 -> V_36 ) {
case V_61 :
if ( V_34 -> V_35 > 1 )
return - V_15 ;
V_5 -> V_62 = V_34 -> V_35 ;
break;
case V_63 :
if ( V_34 -> V_35 > 1 )
return - V_15 ;
V_5 -> V_64 = V_34 -> V_35 ;
break;
case V_65 :
if ( ! F_6 ( V_2 , V_66 ) )
return - V_15 ;
if ( V_34 -> V_35 > 1 )
return - V_15 ;
V_5 -> V_67 = V_34 -> V_35 ;
V_5 -> V_64 = V_34 -> V_35 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_68 * V_69 = V_3 ;
int V_70 , V_71 = 0 ;
if ( V_69 -> V_72 != - 1 ) {
if ( V_69 -> V_72 != V_73 ||
V_69 -> V_74 < 0 || V_69 -> V_74 > V_75 ) {
V_71 = - V_15 ;
goto V_76;
}
V_70 = F_20 ( V_69 -> V_72 ,
V_69 -> V_74 ) ;
V_2 -> V_70 = F_21 ( V_70 , V_2 -> V_70 ) ;
if ( V_69 -> V_74 >= 1 ) {
V_71 = F_9 ( V_2 , V_5 ) ;
if ( V_71 )
goto V_76;
}
}
if ( V_69 -> V_77 != - 1 ) {
if ( V_69 -> V_77 != V_2 -> V_19 -> V_78 ||
V_69 -> V_79 < 0 || V_69 -> V_79 >
V_2 -> V_19 -> V_80 ) {
V_71 = - V_15 ;
goto V_76;
}
}
V_76:
V_69 -> V_72 = V_73 ;
V_69 -> V_74 = V_75 ;
V_69 -> V_77 = V_2 -> V_19 -> V_78 ;
V_69 -> V_79 = V_2 -> V_19 -> V_80 ;
return V_71 ;
}
int F_22 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_23 ( L_4 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return - V_15 ;
}
static int F_25 ( char T_1 * V_81 , T_2 * V_82 , const char * V_35 )
{
int V_83 ;
V_83 = strlen ( V_35 ) ;
if ( V_83 > * V_82 )
V_83 = * V_82 ;
* V_82 = strlen ( V_35 ) ;
if ( V_83 && V_81 )
if ( F_2 ( V_81 , V_35 , V_83 ) )
return - V_12 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_26 * V_84 = V_3 ;
int V_18 ;
V_84 -> V_85 = V_2 -> V_19 -> V_78 ;
V_84 -> V_86 = V_2 -> V_19 -> V_80 ;
V_84 -> V_87 = V_2 -> V_19 -> V_88 ;
V_18 = F_25 ( V_84 -> V_89 , & V_84 -> V_90 ,
V_2 -> V_19 -> V_89 ) ;
if ( ! V_18 )
V_18 = F_25 ( V_84 -> V_91 , & V_84 -> V_92 ,
V_2 -> V_19 -> V_91 ) ;
if ( ! V_18 )
V_18 = F_25 ( V_84 -> V_93 , & V_84 -> V_94 ,
V_2 -> V_19 -> V_93 ) ;
return V_18 ;
}
int F_27 ( T_3 V_95 , struct V_4 * V_5 )
{
if ( F_28 ( ( V_95 & V_96 ) && ! F_29 ( V_97 ) ) )
return - V_98 ;
if ( F_28 ( ( V_95 & V_99 ) && ! F_30 ( V_5 ) &&
! V_5 -> V_26 ) )
return - V_98 ;
if ( F_28 ( ( V_95 & V_100 ) && ! V_5 -> V_101 &&
! F_31 ( V_5 ) ) )
return - V_98 ;
if ( F_28 ( ! ( V_95 & V_102 ) &&
F_31 ( V_5 ) ) )
return - V_98 ;
if ( F_28 ( ! ( V_95 & V_103 ) &&
F_30 ( V_5 ) ) )
return - V_98 ;
return 0 ;
}
long F_32 ( struct V_104 * V_105 ,
unsigned int V_106 , unsigned long V_107 )
{
struct V_4 * V_5 = V_105 -> V_108 ;
struct V_1 * V_2 ;
const struct V_109 * V_110 = NULL ;
T_4 * V_111 ;
unsigned int V_112 = F_33 ( V_106 ) ;
int V_71 = - V_15 ;
char V_113 [ 128 ] ;
char * V_114 = NULL ;
unsigned int V_115 , V_116 , V_117 ;
bool V_118 ;
V_2 = V_5 -> V_80 -> V_2 ;
if ( F_34 ( V_2 ) )
return - V_119 ;
V_118 = V_112 >= V_120 && V_112 < V_121 ;
if ( V_118 ) {
if ( V_112 - V_120 >= V_2 -> V_19 -> V_122 )
goto V_123;
V_110 = & V_2 -> V_19 -> V_124 [ V_112 - V_120 ] ;
} else {
if ( V_112 >= V_125 )
goto V_123;
V_110 = & V_126 [ V_112 ] ;
}
V_117 = F_35 ( V_110 -> V_106 ) ;
V_115 = F_35 ( V_106 ) ;
V_116 = F_21 ( V_115 , V_117 ) ;
V_106 = V_110 -> V_106 ;
F_23 ( L_5 ,
F_36 ( V_127 ) ,
( long ) F_37 ( V_5 -> V_80 -> V_128 -> V_129 ) ,
V_5 -> V_26 , V_110 -> V_89 ) ;
V_111 = V_110 -> V_111 ;
if ( F_28 ( ! V_111 ) ) {
F_23 ( L_6 ) ;
V_71 = - V_15 ;
goto V_123;
}
V_71 = F_27 ( V_110 -> V_95 , V_5 ) ;
if ( F_28 ( V_71 ) )
goto V_123;
if ( V_106 & ( V_130 | V_131 ) ) {
if ( V_116 <= sizeof( V_113 ) ) {
V_114 = V_113 ;
} else {
V_114 = F_38 ( V_116 , V_21 ) ;
if ( ! V_114 ) {
V_71 = - V_132 ;
goto V_123;
}
}
if ( V_116 > V_115 )
memset ( V_114 + V_115 , 0 , V_116 - V_115 ) ;
}
if ( V_106 & V_130 ) {
if ( F_39 ( V_114 , ( void T_1 * ) V_107 ,
V_115 ) != 0 ) {
V_71 = - V_12 ;
goto V_123;
}
} else if ( V_106 & V_131 ) {
memset ( V_114 , 0 , V_115 ) ;
}
if ( ( F_6 ( V_2 , V_16 ) && V_118 ) ||
( V_110 -> V_95 & V_133 ) )
V_71 = V_111 ( V_2 , V_114 , V_5 ) ;
else {
F_40 ( & V_134 ) ;
V_71 = V_111 ( V_2 , V_114 , V_5 ) ;
F_41 ( & V_134 ) ;
}
if ( V_106 & V_131 ) {
if ( F_2 ( ( void T_1 * ) V_107 , V_114 ,
V_115 ) != 0 )
V_71 = - V_12 ;
}
V_123:
if ( ! V_110 )
F_23 ( L_7 ,
F_36 ( V_127 ) ,
( long ) F_37 ( V_5 -> V_80 -> V_128 -> V_129 ) ,
V_5 -> V_26 , V_106 , V_112 ) ;
if ( V_114 != V_113 )
F_4 ( V_114 ) ;
if ( V_71 )
F_23 ( L_8 , V_71 ) ;
return V_71 ;
}
bool F_42 ( unsigned int V_112 , unsigned int * V_95 )
{
if ( V_112 >= V_120 && V_112 < V_121 )
return false ;
if ( V_112 >= V_125 )
return false ;
* V_95 = V_126 [ V_112 ] . V_95 ;
return true ;
}
