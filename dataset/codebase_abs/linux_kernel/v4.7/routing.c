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
F_3 () ;
V_11 = F_4 ( V_10 -> V_12 ) ;
if ( V_11 && ! F_5 ( & V_11 -> V_13 ) )
V_11 = NULL ;
F_6 () ;
if ( ( V_11 ) && ( ! V_8 ) ) {
F_7 ( V_14 , V_2 ,
L_1 , V_4 -> V_15 ) ;
F_8 ( V_2 , V_4 , - 1 ,
L_2 ) ;
} else if ( ( ! V_11 ) && ( V_8 ) ) {
F_7 ( V_14 , V_2 ,
L_3 ,
V_4 -> V_15 , V_8 -> V_16 ) ;
} else if ( V_8 && V_11 ) {
F_7 ( V_14 , V_2 ,
L_4 ,
V_4 -> V_15 , V_8 -> V_16 ,
V_11 -> V_16 ) ;
}
if ( V_11 )
F_9 ( V_11 ) ;
F_10 ( & V_4 -> V_17 ) ;
V_11 = F_11 ( V_10 -> V_12 , true ) ;
if ( V_8 )
F_12 ( & V_8 -> V_13 ) ;
F_13 ( V_10 -> V_12 , V_8 ) ;
F_14 ( & V_4 -> V_17 ) ;
F_15 ( V_10 ) ;
if ( V_11 )
F_9 ( V_11 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_12 = NULL ;
if ( ! V_4 )
goto V_18;
V_12 = F_17 ( V_4 , V_6 ) ;
if ( V_12 != V_8 )
F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
V_18:
if ( V_12 )
F_9 ( V_12 ) ;
}
bool F_18 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_20 , unsigned long * V_21 ,
bool * V_22 )
{
if ( V_19 <= - V_20 ||
V_19 >= V_23 ) {
if ( ! F_19 ( * V_21 ,
V_24 ) )
return true ;
* V_21 = V_25 ;
if ( V_22 )
* V_22 = true ;
F_7 ( V_26 , V_2 ,
L_5 ) ;
}
return false ;
}
bool F_20 ( struct V_27 * V_28 ,
struct V_5 * V_29 ,
int V_30 )
{
struct V_31 * V_31 ;
if ( F_21 ( ! F_22 ( V_28 , V_30 ) ) )
return false ;
V_31 = F_23 ( V_28 ) ;
if ( ! F_24 ( V_31 -> V_32 ) )
return false ;
if ( F_24 ( V_31 -> V_33 ) )
return false ;
if ( F_25 ( V_28 , 0 ) < 0 )
return false ;
if ( F_26 ( V_28 ) < 0 )
return false ;
return true ;
}
static int F_27 ( struct V_1 * V_2 ,
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
if ( F_26 ( V_28 ) < 0 )
break;
F_28 ( V_36 , V_28 -> V_45 ) ;
break;
case V_46 :
V_34 = F_29 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_30 ( V_2 , V_36 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_25 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
F_31 ( V_36 -> V_48 , V_36 -> V_15 ) ;
F_31 ( V_36 -> V_15 , V_34 -> V_49 -> V_50 ) ;
V_36 -> V_41 = V_42 ;
V_36 -> V_51 = V_52 ;
V_37 = F_32 ( V_28 , V_4 , NULL ) ;
if ( V_37 != V_53 )
V_38 = V_54 ;
break;
default:
goto V_18;
}
V_18:
if ( V_34 )
F_33 ( V_34 ) ;
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_34 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_55 * V_56 ;
int V_38 = V_39 ;
V_56 = (struct V_55 * ) V_28 -> V_40 ;
if ( V_56 -> V_41 != V_46 ) {
F_36 ( L_6 ,
V_56 -> V_15 , V_56 -> V_48 ) ;
goto V_18;
}
V_34 = F_29 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_30 ( V_2 , V_56 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_25 ( V_28 , V_47 ) < 0 )
goto V_18;
V_56 = (struct V_55 * ) V_28 -> V_40 ;
F_31 ( V_56 -> V_48 , V_56 -> V_15 ) ;
F_31 ( V_56 -> V_15 , V_34 -> V_49 -> V_50 ) ;
V_56 -> V_41 = V_44 ;
V_56 -> V_51 = V_52 ;
if ( F_32 ( V_28 , V_4 , NULL ) != V_53 )
V_38 = V_54 ;
V_18:
if ( V_34 )
F_33 ( V_34 ) ;
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
int F_37 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_35 * V_36 ;
struct V_58 * V_59 ;
struct V_31 * V_31 ;
struct V_3 * V_4 = NULL ;
int V_60 = sizeof( struct V_35 ) ;
int V_38 = V_39 ;
if ( F_21 ( ! F_22 ( V_28 , V_60 ) ) )
goto V_18;
V_31 = F_23 ( V_28 ) ;
if ( F_24 ( V_31 -> V_32 ) )
goto V_18;
if ( F_24 ( V_31 -> V_33 ) )
goto V_18;
if ( ! F_39 ( V_2 , V_31 -> V_32 ) )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
if ( ( V_36 -> V_41 == V_42 ||
V_36 -> V_41 == V_46 ) &&
( V_28 -> V_45 >= sizeof( struct V_58 ) ) ) {
if ( F_26 ( V_28 ) < 0 )
goto V_18;
if ( F_25 ( V_28 , V_47 ) < 0 )
goto V_18;
V_31 = F_23 ( V_28 ) ;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_59 = (struct V_58 * ) V_36 ;
if ( V_59 -> V_61 >= V_62 )
goto V_18;
F_31 ( V_59 -> V_63 [ V_59 -> V_61 ] ,
V_31 -> V_32 ) ;
V_59 -> V_61 ++ ;
}
if ( F_39 ( V_2 , V_36 -> V_48 ) )
return F_27 ( V_2 , V_28 ) ;
if ( V_36 -> V_51 < 2 )
return F_35 ( V_2 , V_28 ) ;
V_4 = F_30 ( V_2 , V_36 -> V_48 ) ;
if ( ! V_4 )
goto V_18;
if ( F_25 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_36 -> V_51 -- ;
if ( F_32 ( V_28 , V_4 , V_6 ) != V_53 )
V_38 = V_54 ;
V_18:
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_60 )
{
struct V_31 * V_31 ;
if ( F_21 ( ! F_22 ( V_28 , V_60 ) ) )
return - V_64 ;
V_31 = F_23 ( V_28 ) ;
if ( F_24 ( V_31 -> V_32 ) )
return - V_65 ;
if ( F_24 ( V_31 -> V_33 ) )
return - V_65 ;
if ( ! F_39 ( V_2 , V_31 -> V_32 ) )
return - V_66 ;
return 0 ;
}
static void
F_41 ( struct V_3 * V_4 ,
struct V_9 * V_67 )
{
struct V_9 * V_68 ;
F_10 ( & V_4 -> V_17 ) ;
V_68 = V_4 -> V_69 ;
if ( V_67 )
F_12 ( & V_67 -> V_13 ) ;
V_4 -> V_69 = V_67 ;
F_14 ( & V_4 -> V_17 ) ;
if ( V_68 )
F_15 ( V_68 ) ;
}
struct V_7 *
F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_70 * V_71 = V_2 -> V_72 ;
struct V_7 * V_73 = NULL ;
struct V_7 * V_74 = NULL ;
struct V_7 * V_12 , * V_75 = NULL ;
struct V_7 * V_76 = NULL ;
struct V_9 * V_77 , * V_78 = NULL ;
struct V_9 * V_79 = NULL ;
struct V_9 * V_80 ;
bool V_81 = false ;
if ( ! V_4 )
return NULL ;
V_12 = F_17 ( V_4 , V_6 ) ;
if ( ! V_12 )
return V_12 ;
if ( ! ( V_6 == V_82 && F_43 ( & V_2 -> V_83 ) ) )
return V_12 ;
F_3 () ;
V_80 = V_4 -> V_69 ;
if ( V_80 )
V_76 = F_4 ( V_80 -> V_12 ) ;
F_44 (cand, &orig_node->ifinfo_list, list) {
if ( ! F_5 ( & V_77 -> V_13 ) )
continue;
V_75 = F_4 ( V_77 -> V_12 ) ;
if ( ! V_75 )
goto V_84;
if ( ! F_5 ( & V_75 -> V_13 ) ) {
V_75 = NULL ;
goto V_84;
}
if ( ! V_71 -> V_85 ( V_75 ,
V_77 -> V_86 ,
V_12 , V_6 ) )
goto V_84;
if ( V_76 == V_75 )
goto V_84;
if ( ! V_78 ) {
F_12 ( & V_75 -> V_13 ) ;
F_12 ( & V_77 -> V_13 ) ;
V_78 = V_77 ;
V_73 = V_75 ;
}
if ( ! V_80 || V_81 ) {
V_79 = V_77 ;
V_74 = V_75 ;
break;
}
if ( V_80 == V_77 )
V_81 = true ;
V_84:
if ( V_75 ) {
F_9 ( V_75 ) ;
V_75 = NULL ;
}
F_15 ( V_77 ) ;
}
F_6 () ;
if ( V_79 ) {
F_9 ( V_12 ) ;
F_12 ( & V_74 -> V_13 ) ;
V_12 = V_74 ;
F_41 ( V_4 , V_79 ) ;
} else if ( V_78 ) {
F_9 ( V_12 ) ;
F_12 ( & V_73 -> V_13 ) ;
V_12 = V_73 ;
F_41 ( V_4 , V_78 ) ;
} else {
F_41 ( V_4 , NULL ) ;
}
if ( V_78 ) {
F_9 ( V_73 ) ;
F_15 ( V_78 ) ;
}
if ( V_79 ) {
F_9 ( V_74 ) ;
F_15 ( V_79 ) ;
}
return V_12 ;
}
static int F_45 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_87 * V_88 ;
struct V_31 * V_31 = F_23 ( V_28 ) ;
int V_37 , V_89 , V_38 = V_39 ;
unsigned int V_45 ;
V_88 = (struct V_87 * ) V_28 -> V_40 ;
if ( V_88 -> V_51 < 2 ) {
F_36 ( L_7 ,
V_31 -> V_33 , V_88 -> V_90 ) ;
goto V_18;
}
V_4 = F_30 ( V_2 , V_88 -> V_90 ) ;
if ( ! V_4 )
goto V_18;
if ( F_25 ( V_28 , V_47 ) < 0 )
goto V_18;
V_88 = (struct V_87 * ) V_28 -> V_40 ;
V_88 -> V_51 -- ;
switch ( V_88 -> V_91 ) {
case V_92 :
V_89 = sizeof( struct V_93 ) ;
break;
case V_94 :
V_89 = sizeof( struct V_87 ) ;
break;
default:
V_89 = - 1 ;
break;
}
if ( V_89 > 0 )
F_46 ( V_28 , V_89 ) ;
V_45 = V_28 -> V_45 ;
V_37 = F_32 ( V_28 , V_4 , V_6 ) ;
if ( V_37 == V_95 ) {
F_47 ( V_2 , V_96 ) ;
F_48 ( V_2 , V_97 ,
V_45 + V_47 ) ;
V_38 = V_54 ;
} else if ( V_37 == V_98 ) {
V_38 = V_54 ;
}
V_18:
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
static bool
F_49 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
T_2 * V_99 , unsigned short V_100 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_34 = NULL ;
bool V_38 = false ;
T_2 * V_101 , V_102 ;
if ( F_50 ( V_2 , V_99 , V_100 ) ) {
V_34 = F_29 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_101 = V_34 -> V_49 -> V_50 ;
V_102 = ( T_2 ) F_43 ( & V_2 -> V_103 . V_104 ) ;
} else {
V_4 = F_51 ( V_2 , NULL , V_99 ,
V_100 ) ;
if ( ! V_4 )
goto V_18;
if ( F_52 ( V_4 -> V_15 , V_88 -> V_90 ) )
goto V_18;
V_101 = V_4 -> V_15 ;
V_102 = ( T_2 ) F_43 ( & V_4 -> V_105 ) ;
}
F_31 ( V_88 -> V_90 , V_101 ) ;
V_88 -> V_106 = V_102 ;
V_38 = true ;
V_18:
if ( V_34 )
F_33 ( V_34 ) ;
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
static bool F_53 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_89 )
{
struct V_87 * V_88 ;
struct V_5 * V_34 ;
struct V_3 * V_4 ;
T_2 V_107 , V_108 ;
struct V_31 * V_31 ;
unsigned short V_100 ;
int V_109 ;
if ( ! F_22 ( V_28 , V_89 + V_47 ) )
return false ;
if ( F_25 ( V_28 , sizeof( * V_88 ) ) < 0 )
return false ;
V_88 = (struct V_87 * ) V_28 -> V_40 ;
V_100 = F_54 ( V_28 , V_89 ) ;
V_31 = (struct V_31 * ) ( V_28 -> V_40 + V_89 ) ;
if ( F_55 ( V_2 , V_31 -> V_32 , V_100 ) ) {
if ( F_49 ( V_2 , V_88 ,
V_31 -> V_32 , V_100 ) )
F_56 ( V_110 ,
V_2 ,
L_8 ,
V_88 -> V_90 ,
V_31 -> V_32 ) ;
return true ;
}
V_107 = ( T_2 ) F_43 ( & V_2 -> V_103 . V_104 ) ;
if ( ! F_39 ( V_2 , V_88 -> V_90 ) ) {
V_4 = F_30 ( V_2 ,
V_88 -> V_90 ) ;
if ( ! V_4 )
return false ;
V_107 = ( T_2 ) F_43 ( & V_4 -> V_105 ) ;
F_34 ( V_4 ) ;
}
V_109 = F_57 ( V_88 -> V_106 , V_107 ) ;
if ( ! V_109 )
return true ;
V_108 = V_88 -> V_106 ;
if ( F_49 ( V_2 , V_88 ,
V_31 -> V_32 , V_100 ) ) {
F_56 ( V_110 , V_2 ,
L_9 ,
V_88 -> V_90 , V_31 -> V_32 ,
V_108 , V_107 ) ;
return true ;
}
if ( ! F_50 ( V_2 , V_31 -> V_32 , V_100 ) )
return false ;
V_34 = F_29 ( V_2 ) ;
if ( ! V_34 )
return false ;
F_31 ( V_88 -> V_90 , V_34 -> V_49 -> V_50 ) ;
F_33 ( V_34 ) ;
V_88 -> V_106 = V_107 ;
return true ;
}
int F_58 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_87 * V_88 ;
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
int V_111 , V_60 = sizeof( * V_88 ) ;
V_111 = F_40 ( V_2 , V_28 , V_60 ) ;
if ( V_111 < 0 )
return V_39 ;
V_88 = (struct V_87 * ) V_28 -> V_40 ;
if ( F_39 ( V_2 , V_88 -> V_90 ) )
return V_39 ;
return F_45 ( V_28 , V_6 ) ;
}
int F_59 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_87 * V_88 ;
struct V_93 * V_112 ;
T_2 * V_101 ;
struct V_3 * V_4 = NULL ;
int V_111 , V_60 = sizeof( * V_88 ) ;
enum V_113 V_114 ;
bool V_115 ;
V_88 = (struct V_87 * ) V_28 -> V_40 ;
V_112 = (struct V_93 * ) V_28 -> V_40 ;
V_115 = V_88 -> V_91 == V_92 ;
if ( V_115 )
V_60 = sizeof( * V_112 ) ;
V_111 = F_40 ( V_2 , V_28 , V_60 ) ;
if ( V_111 == - V_66 )
F_60 ( V_2 , V_28 ) ;
if ( V_111 < 0 )
return V_39 ;
if ( ! F_53 ( V_2 , V_28 , V_60 ) )
return V_39 ;
if ( F_39 ( V_2 , V_88 -> V_90 ) ) {
if ( V_115 ) {
V_114 = V_112 -> V_114 ;
F_61 ( V_2 , V_114 ) ;
if ( V_114 == V_116 ) {
V_101 = V_112 -> V_117 ;
V_4 = F_30 ( V_2 ,
V_101 ) ;
}
}
if ( F_62 ( V_2 , V_28 ,
V_60 ) )
goto V_118;
if ( F_63 ( V_2 , V_28 ,
V_60 ) )
goto V_118;
F_64 ( V_6 -> V_57 , V_28 , V_60 ,
V_4 ) ;
V_118:
if ( V_4 )
F_34 ( V_4 ) ;
return V_54 ;
}
return F_45 ( V_28 , V_6 ) ;
}
int F_65 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_119 * V_120 ;
unsigned char * V_121 ;
T_3 V_122 ;
int V_60 = sizeof( * V_120 ) ;
int V_38 = V_39 ;
if ( F_40 ( V_2 , V_28 , V_60 ) < 0 )
return V_39 ;
if ( F_25 ( V_28 , V_60 ) < 0 )
return V_39 ;
if ( F_26 ( V_28 ) < 0 )
return V_39 ;
V_120 = (struct V_119 * ) V_28 -> V_40 ;
V_121 = ( unsigned char * ) ( V_28 -> V_40 + V_60 ) ;
V_122 = F_66 ( V_120 -> V_123 ) ;
if ( V_122 > V_28 -> V_45 - V_60 )
return V_39 ;
V_38 = F_67 ( V_2 , false , NULL ,
V_120 -> V_117 ,
V_120 -> V_48 ,
V_121 , V_122 ) ;
if ( V_38 != V_54 )
V_38 = F_45 ( V_28 , V_6 ) ;
else
F_68 ( V_28 ) ;
return V_38 ;
}
int F_69 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_3 * V_124 = NULL ;
struct V_125 * V_126 ;
int V_38 = V_39 ;
if ( F_40 ( V_2 , V_28 ,
sizeof( * V_126 ) ) < 0 )
goto V_18;
V_126 = (struct V_125 * ) V_28 -> V_40 ;
V_124 = F_30 ( V_2 , V_126 -> V_15 ) ;
if ( ! V_124 )
goto V_18;
if ( ! F_39 ( V_2 , V_126 -> V_90 ) &&
F_70 ( V_28 , V_6 , V_124 ) ) {
V_38 = V_54 ;
goto V_18;
}
F_47 ( V_2 , V_127 ) ;
F_48 ( V_2 , V_128 , V_28 -> V_45 ) ;
if ( ! F_71 ( & V_28 , V_124 ) )
goto V_18;
if ( V_28 )
F_72 ( V_28 , V_6 -> V_49 ,
& V_6 -> V_129 , NULL ) ;
V_38 = V_54 ;
V_18:
if ( V_124 )
F_34 ( V_124 ) ;
return V_38 ;
}
int F_73 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_38 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_130 * V_131 ;
struct V_31 * V_31 ;
int V_60 = sizeof( * V_131 ) ;
int V_38 = V_39 ;
T_1 V_132 ;
T_4 V_133 ;
if ( F_21 ( ! F_22 ( V_28 , V_60 ) ) )
goto V_18;
V_31 = F_23 ( V_28 ) ;
if ( ! F_24 ( V_31 -> V_32 ) )
goto V_18;
if ( F_24 ( V_31 -> V_33 ) )
goto V_18;
if ( F_39 ( V_2 , V_31 -> V_33 ) )
goto V_18;
V_131 = (struct V_130 * ) V_28 -> V_40 ;
if ( F_39 ( V_2 , V_131 -> V_15 ) )
goto V_18;
if ( V_131 -> V_51 < 2 )
goto V_18;
V_4 = F_30 ( V_2 , V_131 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
F_10 ( & V_4 -> V_134 ) ;
V_133 = F_74 ( V_131 -> V_133 ) ;
if ( F_75 ( V_4 -> V_135 , V_4 -> V_136 ,
V_133 ) )
goto V_137;
V_132 = V_133 - V_4 -> V_136 ;
if ( F_18 ( V_2 , V_132 ,
V_138 ,
& V_4 -> V_139 , NULL ) )
goto V_137;
if ( F_76 ( V_2 , V_4 -> V_135 , V_132 , 1 ) )
V_4 -> V_136 = V_133 ;
F_14 ( & V_4 -> V_134 ) ;
if ( F_77 ( V_2 , V_28 ) )
goto V_18;
F_46 ( V_28 , sizeof( struct V_130 ) ) ;
F_78 ( V_2 , V_28 , 1 ) ;
if ( F_79 ( V_28 , V_4 , V_60 ) )
goto V_18;
if ( F_62 ( V_2 , V_28 , V_60 ) )
goto V_118;
if ( F_63 ( V_2 , V_28 , V_60 ) )
goto V_118;
F_64 ( V_6 -> V_57 , V_28 , V_60 , V_4 ) ;
V_118:
V_38 = V_54 ;
goto V_18;
V_137:
F_14 ( & V_4 -> V_134 ) ;
V_18:
if ( V_4 )
F_34 ( V_4 ) ;
return V_38 ;
}
