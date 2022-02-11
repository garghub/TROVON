static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_7 * V_11 ;
V_10 = F_2 ( V_4 , V_6 ) ;
if ( ! V_10 )
return;
F_3 ( & V_4 -> V_12 ) ;
V_11 = F_4 ( V_10 -> V_13 , true ) ;
if ( V_8 )
F_5 ( & V_8 -> V_14 ) ;
F_6 ( V_10 -> V_13 , V_8 ) ;
F_7 ( & V_4 -> V_12 ) ;
F_8 ( V_10 ) ;
if ( ( V_11 ) && ( ! V_8 ) ) {
F_9 ( V_15 , V_2 ,
L_1 , V_4 -> V_16 ) ;
F_10 ( V_2 , V_4 , - 1 ,
L_2 ) ;
} else if ( ( ! V_11 ) && ( V_8 ) ) {
F_9 ( V_15 , V_2 ,
L_3 ,
V_4 -> V_16 , V_8 -> V_17 ) ;
} else if ( V_8 && V_11 ) {
F_9 ( V_15 , V_2 ,
L_4 ,
V_4 -> V_16 , V_8 -> V_17 ,
V_11 -> V_17 ) ;
}
if ( V_11 )
F_11 ( V_11 ) ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_13 = NULL ;
if ( ! V_4 )
goto V_18;
V_13 = F_13 ( V_4 , V_6 ) ;
if ( V_13 != V_8 )
F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
V_18:
if ( V_13 )
F_11 ( V_13 ) ;
}
bool F_14 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_20 , unsigned long * V_21 ,
bool * V_22 )
{
if ( V_19 <= - V_20 ||
V_19 >= V_23 ) {
if ( ! F_15 ( * V_21 ,
V_24 ) )
return true ;
* V_21 = V_25 ;
if ( V_22 )
* V_22 = true ;
F_9 ( V_26 , V_2 ,
L_5 ) ;
}
return false ;
}
bool F_16 ( struct V_27 * V_28 ,
struct V_5 * V_29 ,
int V_30 )
{
struct V_31 * V_31 ;
if ( F_17 ( ! F_18 ( V_28 , V_30 ) ) )
return false ;
V_31 = F_19 ( V_28 ) ;
if ( ! F_20 ( V_31 -> V_32 ) )
return false ;
if ( F_20 ( V_31 -> V_33 ) )
return false ;
if ( F_21 ( V_28 , 0 ) < 0 )
return false ;
if ( F_22 ( V_28 ) < 0 )
return false ;
return true ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_34 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_35 * V_36 ;
int V_37 , V_38 = V_39 ;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
switch ( V_36 -> V_41 ) {
case V_42 :
case V_43 :
case V_44 :
if ( F_22 ( V_28 ) < 0 )
break;
F_24 ( V_36 , V_28 -> V_45 ) ;
break;
case V_46 :
V_34 = F_25 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_26 ( V_2 , V_36 -> V_16 ) ;
if ( ! V_4 )
goto V_18;
if ( F_21 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
F_27 ( V_36 -> V_48 , V_36 -> V_16 ) ;
F_27 ( V_36 -> V_16 , V_34 -> V_49 -> V_50 ) ;
V_36 -> V_41 = V_42 ;
V_36 -> V_51 = V_52 ;
V_37 = F_28 ( V_28 , V_4 , NULL ) ;
if ( V_37 == - 1 )
goto V_18;
V_38 = V_53 ;
break;
case V_54 :
if ( ! F_18 ( V_28 , sizeof( struct V_55 ) ) )
goto V_18;
F_29 ( V_2 , V_28 ) ;
V_38 = V_53 ;
goto V_18;
default:
goto V_18;
}
V_18:
if ( V_34 )
F_30 ( V_34 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_34 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_56 * V_57 ;
int V_37 , V_38 = V_39 ;
V_57 = (struct V_56 * ) V_28 -> V_40 ;
if ( V_57 -> V_41 != V_46 ) {
F_33 ( L_6 ,
V_57 -> V_16 , V_57 -> V_48 ) ;
goto V_18;
}
V_34 = F_25 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_26 ( V_2 , V_57 -> V_16 ) ;
if ( ! V_4 )
goto V_18;
if ( F_21 ( V_28 , V_47 ) < 0 )
goto V_18;
V_57 = (struct V_56 * ) V_28 -> V_40 ;
F_27 ( V_57 -> V_48 , V_57 -> V_16 ) ;
F_27 ( V_57 -> V_16 , V_34 -> V_49 -> V_50 ) ;
V_57 -> V_41 = V_44 ;
V_57 -> V_51 = V_52 ;
V_37 = F_28 ( V_28 , V_4 , NULL ) ;
if ( V_37 != - 1 )
V_38 = V_53 ;
V_18:
if ( V_34 )
F_30 ( V_34 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
int F_34 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_35 * V_36 ;
struct V_59 * V_60 ;
struct V_31 * V_31 ;
struct V_3 * V_4 = NULL ;
int V_61 = sizeof( struct V_35 ) ;
int V_37 , V_38 = V_39 ;
if ( F_17 ( ! F_18 ( V_28 , V_61 ) ) )
goto V_18;
V_31 = F_19 ( V_28 ) ;
if ( F_20 ( V_31 -> V_32 ) )
goto V_18;
if ( F_20 ( V_31 -> V_33 ) )
goto V_18;
if ( ! F_36 ( V_2 , V_31 -> V_32 ) )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
if ( ( V_36 -> V_41 == V_42 ||
V_36 -> V_41 == V_46 ) &&
( V_28 -> V_45 >= sizeof( struct V_59 ) ) ) {
if ( F_22 ( V_28 ) < 0 )
goto V_18;
if ( F_21 ( V_28 , V_47 ) < 0 )
goto V_18;
V_31 = F_19 ( V_28 ) ;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_60 = (struct V_59 * ) V_36 ;
if ( V_60 -> V_62 >= V_63 )
goto V_18;
F_27 ( V_60 -> V_64 [ V_60 -> V_62 ] ,
V_31 -> V_32 ) ;
V_60 -> V_62 ++ ;
}
if ( F_36 ( V_2 , V_36 -> V_48 ) )
return F_23 ( V_2 , V_28 ) ;
if ( V_36 -> V_51 < 2 )
return F_32 ( V_2 , V_28 ) ;
V_4 = F_26 ( V_2 , V_36 -> V_48 ) ;
if ( ! V_4 )
goto V_18;
if ( F_21 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_36 -> V_51 -- ;
V_37 = F_28 ( V_28 , V_4 , V_6 ) ;
if ( V_37 != - 1 )
V_38 = V_53 ;
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_61 )
{
struct V_31 * V_31 ;
if ( F_17 ( ! F_18 ( V_28 , V_61 ) ) )
return - V_65 ;
V_31 = F_19 ( V_28 ) ;
if ( F_20 ( V_31 -> V_32 ) )
return - V_66 ;
if ( F_20 ( V_31 -> V_33 ) )
return - V_66 ;
if ( ! F_36 ( V_2 , V_31 -> V_32 ) )
return - V_67 ;
return 0 ;
}
static struct V_9 *
F_38 ( struct V_3 * V_4 )
{
struct V_9 * V_68 ;
F_3 ( & V_4 -> V_12 ) ;
V_68 = V_4 -> V_68 ;
if ( V_68 )
F_5 ( & V_68 -> V_14 ) ;
F_7 ( & V_4 -> V_12 ) ;
return V_68 ;
}
static void
F_39 ( struct V_3 * V_4 ,
struct V_9 * V_69 )
{
struct V_9 * V_70 ;
F_3 ( & V_4 -> V_12 ) ;
V_70 = V_4 -> V_68 ;
if ( V_69 )
F_5 ( & V_69 -> V_14 ) ;
V_4 -> V_68 = V_69 ;
F_7 ( & V_4 -> V_12 ) ;
if ( V_70 )
F_8 ( V_70 ) ;
}
struct V_7 *
F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_71 * V_72 = V_2 -> V_73 ;
struct V_7 * V_74 = NULL ;
struct V_7 * V_75 = NULL ;
struct V_7 * V_13 , * V_76 = NULL ;
struct V_7 * V_77 = NULL ;
struct V_9 * V_78 , * V_79 = NULL ;
struct V_9 * V_80 = NULL ;
struct V_9 * V_81 ;
bool V_82 = false ;
if ( ! V_4 )
return NULL ;
V_13 = F_13 ( V_4 , V_6 ) ;
if ( ! V_13 )
return V_13 ;
if ( ! ( V_6 == V_83 && F_41 ( & V_2 -> V_84 ) ) )
return V_13 ;
F_42 () ;
V_81 = F_38 ( V_4 ) ;
if ( V_81 )
V_77 = F_43 ( V_81 -> V_13 ) ;
F_44 (cand, &orig_node->ifinfo_list, list) {
if ( ! F_45 ( & V_78 -> V_14 ) )
continue;
V_76 = F_43 ( V_78 -> V_13 ) ;
if ( ! V_76 )
goto V_85;
if ( ! F_45 ( & V_76 -> V_14 ) ) {
V_76 = NULL ;
goto V_85;
}
if ( ! V_72 -> V_86 . V_87 ( V_76 ,
V_78 -> V_88 , V_13 ,
V_6 ) )
goto V_85;
if ( V_77 == V_76 )
goto V_85;
if ( ! V_79 ) {
F_5 ( & V_76 -> V_14 ) ;
F_5 ( & V_78 -> V_14 ) ;
V_79 = V_78 ;
V_74 = V_76 ;
}
if ( ! V_81 || V_82 ) {
V_80 = V_78 ;
V_75 = V_76 ;
break;
}
if ( V_81 == V_78 )
V_82 = true ;
V_85:
if ( V_76 ) {
F_11 ( V_76 ) ;
V_76 = NULL ;
}
F_8 ( V_78 ) ;
}
F_46 () ;
if ( V_80 ) {
F_11 ( V_13 ) ;
F_5 ( & V_75 -> V_14 ) ;
V_13 = V_75 ;
F_39 ( V_4 , V_80 ) ;
} else if ( V_79 ) {
F_11 ( V_13 ) ;
F_5 ( & V_74 -> V_14 ) ;
V_13 = V_74 ;
F_39 ( V_4 , V_79 ) ;
} else {
F_39 ( V_4 , NULL ) ;
}
if ( V_79 ) {
F_11 ( V_74 ) ;
F_8 ( V_79 ) ;
}
if ( V_80 ) {
F_11 ( V_75 ) ;
F_8 ( V_80 ) ;
}
if ( V_81 )
F_8 ( V_81 ) ;
return V_13 ;
}
static int F_47 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_3 * V_4 = NULL ;
struct V_89 * V_90 ;
struct V_31 * V_31 = F_19 ( V_28 ) ;
int V_37 , V_91 , V_38 = V_39 ;
unsigned int V_45 ;
V_90 = (struct V_89 * ) V_28 -> V_40 ;
if ( V_90 -> V_51 < 2 ) {
F_33 ( L_7 ,
V_31 -> V_33 , V_90 -> V_92 ) ;
goto V_18;
}
V_4 = F_26 ( V_2 , V_90 -> V_92 ) ;
if ( ! V_4 )
goto V_18;
if ( F_21 ( V_28 , V_47 ) < 0 )
goto V_18;
V_90 = (struct V_89 * ) V_28 -> V_40 ;
V_90 -> V_51 -- ;
switch ( V_90 -> V_93 ) {
case V_94 :
V_91 = sizeof( struct V_95 ) ;
break;
case V_96 :
V_91 = sizeof( struct V_89 ) ;
break;
default:
V_91 = - 1 ;
break;
}
if ( V_91 > 0 )
F_48 ( V_28 , V_91 ) ;
V_45 = V_28 -> V_45 ;
V_37 = F_28 ( V_28 , V_4 , V_6 ) ;
if ( V_37 == - 1 )
goto V_18;
if ( V_37 == V_97 ) {
F_49 ( V_2 , V_98 ) ;
F_50 ( V_2 , V_99 ,
V_45 + V_47 ) ;
}
V_38 = V_53 ;
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
static bool
F_51 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_2 * V_100 , unsigned short V_101 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_34 = NULL ;
bool V_38 = false ;
T_2 * V_102 , V_103 ;
if ( F_52 ( V_2 , V_100 , V_101 ) ) {
V_34 = F_25 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_102 = V_34 -> V_49 -> V_50 ;
V_103 = ( T_2 ) F_41 ( & V_2 -> V_104 . V_105 ) ;
} else {
V_4 = F_53 ( V_2 , NULL , V_100 ,
V_101 ) ;
if ( ! V_4 )
goto V_18;
if ( F_54 ( V_4 -> V_16 , V_90 -> V_92 ) )
goto V_18;
V_102 = V_4 -> V_16 ;
V_103 = ( T_2 ) F_41 ( & V_4 -> V_106 ) ;
}
F_27 ( V_90 -> V_92 , V_102 ) ;
V_90 -> V_107 = V_103 ;
V_38 = true ;
V_18:
if ( V_34 )
F_30 ( V_34 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_91 )
{
struct V_89 * V_90 ;
struct V_5 * V_34 ;
struct V_3 * V_4 ;
T_2 V_108 , V_109 ;
struct V_31 * V_31 ;
unsigned short V_101 ;
int V_110 ;
if ( ! F_18 ( V_28 , V_91 + V_47 ) )
return false ;
if ( F_21 ( V_28 , sizeof( * V_90 ) ) < 0 )
return false ;
V_90 = (struct V_89 * ) V_28 -> V_40 ;
V_101 = F_56 ( V_28 , V_91 ) ;
V_31 = (struct V_31 * ) ( V_28 -> V_40 + V_91 ) ;
if ( F_57 ( V_2 , V_31 -> V_32 , V_101 ) ) {
if ( F_51 ( V_2 , V_90 ,
V_31 -> V_32 , V_101 ) )
F_58 ( V_111 ,
V_2 ,
L_8 ,
V_90 -> V_92 ,
V_31 -> V_32 ) ;
return true ;
}
V_108 = ( T_2 ) F_41 ( & V_2 -> V_104 . V_105 ) ;
if ( ! F_36 ( V_2 , V_90 -> V_92 ) ) {
V_4 = F_26 ( V_2 ,
V_90 -> V_92 ) ;
if ( ! V_4 )
return false ;
V_108 = ( T_2 ) F_41 ( & V_4 -> V_106 ) ;
F_31 ( V_4 ) ;
}
V_110 = F_59 ( V_90 -> V_107 , V_108 ) ;
if ( ! V_110 )
return true ;
V_109 = V_90 -> V_107 ;
if ( F_51 ( V_2 , V_90 ,
V_31 -> V_32 , V_101 ) ) {
F_58 ( V_111 , V_2 ,
L_9 ,
V_90 -> V_92 , V_31 -> V_32 ,
V_109 , V_108 ) ;
return true ;
}
if ( ! F_52 ( V_2 , V_31 -> V_32 , V_101 ) )
return false ;
V_34 = F_25 ( V_2 ) ;
if ( ! V_34 )
return false ;
F_27 ( V_90 -> V_92 , V_34 -> V_49 -> V_50 ) ;
F_30 ( V_34 ) ;
V_90 -> V_107 = V_108 ;
return true ;
}
int F_60 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_89 * V_90 ;
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
int V_112 , V_61 = sizeof( * V_90 ) ;
V_112 = F_37 ( V_2 , V_28 , V_61 ) ;
if ( V_112 < 0 )
return V_39 ;
V_90 = (struct V_89 * ) V_28 -> V_40 ;
if ( F_36 ( V_2 , V_90 -> V_92 ) )
return V_39 ;
return F_47 ( V_28 , V_6 ) ;
}
int F_61 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_89 * V_90 ;
struct V_95 * V_113 ;
T_2 * V_102 ;
struct V_3 * V_4 = NULL ;
int V_112 , V_61 = sizeof( * V_90 ) ;
enum V_114 V_115 ;
bool V_116 ;
V_90 = (struct V_89 * ) V_28 -> V_40 ;
V_113 = (struct V_95 * ) V_28 -> V_40 ;
V_116 = V_90 -> V_93 == V_94 ;
if ( V_116 )
V_61 = sizeof( * V_113 ) ;
V_112 = F_37 ( V_2 , V_28 , V_61 ) ;
if ( V_112 == - V_67 )
F_62 ( V_2 , V_28 ) ;
if ( V_112 < 0 )
return V_39 ;
if ( ! F_55 ( V_2 , V_28 , V_61 ) )
return V_39 ;
if ( F_36 ( V_2 , V_90 -> V_92 ) ) {
if ( V_116 ) {
V_115 = V_113 -> V_115 ;
F_63 ( V_2 , V_115 ) ;
if ( V_115 == V_117 ) {
V_102 = V_113 -> V_118 ;
V_4 = F_26 ( V_2 ,
V_102 ) ;
}
}
if ( F_64 ( V_2 , V_28 ,
V_61 ) )
goto V_119;
if ( F_65 ( V_2 , V_28 ,
V_61 ) )
goto V_119;
F_66 ( V_6 -> V_58 , V_28 , V_61 ,
V_4 ) ;
V_119:
if ( V_4 )
F_31 ( V_4 ) ;
return V_53 ;
}
return F_47 ( V_28 , V_6 ) ;
}
int F_67 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_120 * V_121 ;
unsigned char * V_122 ;
T_3 V_123 ;
int V_61 = sizeof( * V_121 ) ;
int V_38 = V_39 ;
if ( F_37 ( V_2 , V_28 , V_61 ) < 0 )
return V_39 ;
if ( F_21 ( V_28 , V_61 ) < 0 )
return V_39 ;
if ( F_22 ( V_28 ) < 0 )
return V_39 ;
V_121 = (struct V_120 * ) V_28 -> V_40 ;
V_122 = ( unsigned char * ) ( V_28 -> V_40 + V_61 ) ;
V_123 = F_68 ( V_121 -> V_124 ) ;
if ( V_123 > V_28 -> V_45 - V_61 )
return V_39 ;
V_38 = F_69 ( V_2 , false , NULL ,
V_121 -> V_118 ,
V_121 -> V_48 ,
V_122 , V_123 ) ;
if ( V_38 != V_53 )
V_38 = F_47 ( V_28 , V_6 ) ;
else
F_70 ( V_28 ) ;
return V_38 ;
}
int F_71 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_3 * V_125 = NULL ;
struct V_126 * V_127 ;
int V_38 = V_39 ;
if ( F_37 ( V_2 , V_28 ,
sizeof( * V_127 ) ) < 0 )
goto V_18;
V_127 = (struct V_126 * ) V_28 -> V_40 ;
V_125 = F_26 ( V_2 , V_127 -> V_16 ) ;
if ( ! V_125 )
goto V_18;
V_28 -> V_128 = V_127 -> V_128 + 256 ;
if ( ! F_36 ( V_2 , V_127 -> V_92 ) &&
F_72 ( V_28 , V_6 , V_125 ) ) {
V_38 = V_53 ;
goto V_18;
}
F_49 ( V_2 , V_129 ) ;
F_50 ( V_2 , V_130 , V_28 -> V_45 ) ;
if ( ! F_73 ( & V_28 , V_125 ) )
goto V_18;
if ( V_28 )
F_74 ( V_28 , V_6 -> V_49 ,
& V_6 -> V_131 , NULL ) ;
V_38 = V_53 ;
V_18:
if ( V_125 )
F_31 ( V_125 ) ;
return V_38 ;
}
int F_75 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_58 ) ;
struct V_3 * V_4 = NULL ;
struct V_132 * V_133 ;
struct V_31 * V_31 ;
int V_61 = sizeof( * V_133 ) ;
int V_38 = V_39 ;
T_1 V_134 ;
T_4 V_135 ;
if ( F_17 ( ! F_18 ( V_28 , V_61 ) ) )
goto V_18;
V_31 = F_19 ( V_28 ) ;
if ( ! F_20 ( V_31 -> V_32 ) )
goto V_18;
if ( F_20 ( V_31 -> V_33 ) )
goto V_18;
if ( F_36 ( V_2 , V_31 -> V_33 ) )
goto V_18;
V_133 = (struct V_132 * ) V_28 -> V_40 ;
if ( F_36 ( V_2 , V_133 -> V_16 ) )
goto V_18;
if ( V_133 -> V_51 < 2 )
goto V_18;
V_4 = F_26 ( V_2 , V_133 -> V_16 ) ;
if ( ! V_4 )
goto V_18;
F_3 ( & V_4 -> V_136 ) ;
V_135 = F_76 ( V_133 -> V_135 ) ;
if ( F_77 ( V_4 -> V_137 , V_4 -> V_138 ,
V_135 ) )
goto V_139;
V_134 = V_135 - V_4 -> V_138 ;
if ( F_14 ( V_2 , V_134 ,
V_140 ,
& V_4 -> V_141 , NULL ) )
goto V_139;
if ( F_78 ( V_2 , V_4 -> V_137 , V_134 , 1 ) )
V_4 -> V_138 = V_135 ;
F_7 ( & V_4 -> V_136 ) ;
if ( F_79 ( V_2 , V_28 ) )
goto V_18;
F_48 ( V_28 , sizeof( struct V_132 ) ) ;
F_80 ( V_2 , V_28 , 1 ) ;
if ( F_81 ( V_28 , V_4 , V_61 ) )
goto V_18;
if ( F_64 ( V_2 , V_28 , V_61 ) )
goto V_119;
if ( F_65 ( V_2 , V_28 , V_61 ) )
goto V_119;
F_66 ( V_6 -> V_58 , V_28 , V_61 , V_4 ) ;
V_119:
V_38 = V_53 ;
goto V_18;
V_139:
F_7 ( & V_4 -> V_136 ) ;
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_38 ;
}
