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
V_18 -> V_22 = F_9 ( V_5 -> V_22 ) ;
V_18 -> V_23 = F_10 ( F_11 () ,
V_5 -> V_23 ) ;
V_18 -> V_24 = 0 ;
V_18 -> V_25 = 0 ;
return 0 ;
} else {
return - V_26 ;
}
}
static int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_27 * V_28 = V_3 ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_29 * V_30 = V_3 ;
V_30 -> V_31 = 0 ;
switch ( V_30 -> V_32 ) {
case V_33 :
if ( V_2 -> V_14 -> V_34 )
V_30 -> V_31 = 1 ;
break;
case V_35 :
V_30 -> V_31 = 1 ;
break;
case V_36 :
V_30 -> V_31 = V_2 -> V_37 . V_38 ;
break;
case V_39 :
V_30 -> V_31 = V_2 -> V_37 . V_40 ;
break;
case V_41 :
V_30 -> V_31 |= V_2 -> V_14 -> V_42 ? V_43 : 0 ;
V_30 -> V_31 |= V_2 -> V_14 -> V_44 ? V_45 : 0 ;
break;
case V_46 :
V_30 -> V_31 = V_47 ;
break;
case V_48 :
V_30 -> V_31 = V_2 -> V_37 . V_49 ;
break;
case V_50 :
if ( V_2 -> V_37 . V_51 )
V_30 -> V_31 = V_2 -> V_37 . V_51 ;
else
V_30 -> V_31 = 64 ;
break;
case V_52 :
if ( V_2 -> V_37 . V_53 )
V_30 -> V_31 = V_2 -> V_37 . V_53 ;
else
V_30 -> V_31 = 64 ;
break;
case V_54 :
V_30 -> V_31 = V_2 -> V_37 . V_55 ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_56 * V_30 = V_3 ;
switch ( V_30 -> V_32 ) {
case V_57 :
if ( V_30 -> V_31 > 1 )
return - V_26 ;
V_5 -> V_58 = V_30 -> V_31 ;
break;
case V_59 :
if ( V_30 -> V_31 > 1 )
return - V_26 ;
V_5 -> V_60 = V_30 -> V_31 ;
break;
case V_61 :
if ( ! F_15 ( V_2 , V_62 ) )
return - V_26 ;
if ( V_30 -> V_31 > 1 )
return - V_26 ;
V_5 -> V_63 = V_30 -> V_31 ;
V_5 -> V_60 = V_30 -> V_31 ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_64 * V_65 = V_3 ;
int V_66 , V_67 = 0 ;
if ( V_65 -> V_68 != - 1 ) {
if ( V_65 -> V_68 != V_69 ||
V_65 -> V_70 < 0 || V_65 -> V_70 > V_71 ) {
V_67 = - V_26 ;
goto V_72;
}
V_66 = F_17 ( V_65 -> V_68 ,
V_65 -> V_70 ) ;
V_2 -> V_66 = F_18 ( V_66 , V_2 -> V_66 ) ;
if ( V_65 -> V_70 >= 1 ) {
V_67 = F_5 ( V_2 , V_5 ) ;
if ( V_67 )
goto V_72;
}
}
if ( V_65 -> V_73 != - 1 ) {
if ( V_65 -> V_73 != V_2 -> V_14 -> V_74 ||
V_65 -> V_75 < 0 || V_65 -> V_75 >
V_2 -> V_14 -> V_76 ) {
V_67 = - V_26 ;
goto V_72;
}
}
V_72:
V_65 -> V_68 = V_69 ;
V_65 -> V_70 = V_71 ;
V_65 -> V_73 = V_2 -> V_14 -> V_74 ;
V_65 -> V_75 = V_2 -> V_14 -> V_76 ;
return V_67 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_20 ( L_1 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
return - V_26 ;
}
static int F_22 ( char T_1 * V_77 , T_2 * V_78 , const char * V_31 )
{
int V_79 ;
V_79 = strlen ( V_31 ) ;
if ( V_79 > * V_78 )
V_79 = * V_78 ;
* V_78 = strlen ( V_31 ) ;
if ( V_79 && V_77 )
if ( F_2 ( V_77 , V_31 , V_79 ) )
return - V_12 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct F_23 * V_80 = V_3 ;
int V_81 ;
V_80 -> V_82 = V_2 -> V_14 -> V_74 ;
V_80 -> V_83 = V_2 -> V_14 -> V_76 ;
V_80 -> V_84 = V_2 -> V_14 -> V_85 ;
V_81 = F_22 ( V_80 -> V_86 , & V_80 -> V_87 ,
V_2 -> V_14 -> V_86 ) ;
if ( ! V_81 )
V_81 = F_22 ( V_80 -> V_88 , & V_80 -> V_89 ,
V_2 -> V_14 -> V_88 ) ;
if ( ! V_81 )
V_81 = F_22 ( V_80 -> V_90 , & V_80 -> V_91 ,
V_2 -> V_14 -> V_90 ) ;
return V_81 ;
}
int F_24 ( T_3 V_92 , struct V_4 * V_5 )
{
if ( F_25 ( ( V_92 & V_93 ) && ! F_26 ( V_94 ) ) )
return - V_95 ;
if ( F_25 ( ( V_92 & V_96 ) && ! F_27 ( V_5 ) &&
! V_5 -> V_21 ) )
return - V_95 ;
if ( F_25 ( ( V_92 & V_97 ) &&
! F_28 ( V_5 ) &&
! F_29 ( V_5 ) ) )
return - V_95 ;
if ( F_25 ( ! ( V_92 & V_98 ) &&
F_29 ( V_5 ) ) )
return - V_95 ;
if ( F_25 ( ! ( V_92 & V_99 ) &&
F_27 ( V_5 ) ) )
return - V_95 ;
return 0 ;
}
long F_30 ( struct V_100 * V_101 ,
unsigned int V_102 , unsigned long V_103 )
{
struct V_4 * V_5 = V_101 -> V_104 ;
struct V_1 * V_2 ;
const struct V_105 * V_106 = NULL ;
T_4 * V_107 ;
unsigned int V_108 = F_31 ( V_102 ) ;
int V_67 = - V_26 ;
char V_109 [ 128 ] ;
char * V_110 = NULL ;
unsigned int V_111 , V_112 , V_113 , V_114 ;
bool V_115 ;
V_2 = V_5 -> V_76 -> V_2 ;
if ( F_32 ( V_2 ) )
return - V_116 ;
V_115 = V_108 >= V_117 && V_108 < V_118 ;
if ( V_115 ) {
if ( V_108 - V_117 >= V_2 -> V_14 -> V_119 )
goto V_120;
V_106 = & V_2 -> V_14 -> V_121 [ V_108 - V_117 ] ;
} else {
if ( V_108 >= V_122 )
goto V_120;
V_106 = & V_123 [ V_108 ] ;
}
V_113 = F_33 ( V_106 -> V_102 ) ;
V_112 = V_111 = F_33 ( V_102 ) ;
if ( ( V_102 & V_106 -> V_102 & V_124 ) == 0 )
V_111 = 0 ;
if ( ( V_102 & V_106 -> V_102 & V_125 ) == 0 )
V_112 = 0 ;
V_114 = F_18 ( F_18 ( V_111 , V_112 ) , V_113 ) ;
F_20 ( L_2 ,
F_34 ( V_126 ) ,
( long ) F_35 ( V_5 -> V_76 -> V_127 -> V_128 ) ,
V_5 -> V_21 , V_106 -> V_86 ) ;
V_107 = V_106 -> V_107 ;
if ( F_25 ( ! V_107 ) ) {
F_20 ( L_3 ) ;
V_67 = - V_26 ;
goto V_120;
}
V_67 = F_24 ( V_106 -> V_92 , V_5 ) ;
if ( F_25 ( V_67 ) )
goto V_120;
if ( V_114 <= sizeof( V_109 ) ) {
V_110 = V_109 ;
} else {
V_110 = F_36 ( V_114 , V_16 ) ;
if ( ! V_110 ) {
V_67 = - V_129 ;
goto V_120;
}
}
if ( F_37 ( V_110 , ( void T_1 * ) V_103 , V_111 ) != 0 ) {
V_67 = - V_12 ;
goto V_120;
}
if ( V_114 > V_111 )
memset ( V_110 + V_111 , 0 , V_114 - V_111 ) ;
if ( ( F_15 ( V_2 , V_130 ) && V_115 ) ||
( V_106 -> V_92 & V_131 ) )
V_67 = V_107 ( V_2 , V_110 , V_5 ) ;
else {
F_38 ( & V_132 ) ;
V_67 = V_107 ( V_2 , V_110 , V_5 ) ;
F_39 ( & V_132 ) ;
}
if ( F_2 ( ( void T_1 * ) V_103 , V_110 , V_112 ) != 0 )
V_67 = - V_12 ;
V_120:
if ( ! V_106 )
F_20 ( L_4 ,
F_34 ( V_126 ) ,
( long ) F_35 ( V_5 -> V_76 -> V_127 -> V_128 ) ,
V_5 -> V_21 , V_102 , V_108 ) ;
if ( V_110 != V_109 )
F_4 ( V_110 ) ;
if ( V_67 )
F_20 ( L_5 , V_67 ) ;
return V_67 ;
}
bool F_40 ( unsigned int V_108 , unsigned int * V_92 )
{
if ( V_108 >= V_117 && V_108 < V_118 )
return false ;
if ( V_108 >= V_122 )
return false ;
* V_92 = V_123 [ V_108 ] . V_92 ;
return true ;
}
