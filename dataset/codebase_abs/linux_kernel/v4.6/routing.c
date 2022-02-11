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
if ( V_8 && ! F_5 ( & V_8 -> V_13 ) )
V_8 = NULL ;
F_10 ( & V_4 -> V_17 ) ;
V_11 = F_11 ( V_10 -> V_12 , true ) ;
F_12 ( V_10 -> V_12 , V_8 ) ;
F_13 ( & V_4 -> V_17 ) ;
F_14 ( V_10 ) ;
if ( V_11 )
F_9 ( V_11 ) ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_12 = NULL ;
if ( ! V_4 )
goto V_18;
V_12 = F_16 ( V_4 , V_6 ) ;
if ( V_12 != V_8 )
F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
V_18:
if ( V_12 )
F_9 ( V_12 ) ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_20 , unsigned long * V_21 ,
bool * V_22 )
{
if ( V_19 <= - V_20 ||
V_19 >= V_23 ) {
if ( ! F_18 ( * V_21 ,
V_24 ) )
return 1 ;
* V_21 = V_25 ;
if ( V_22 )
* V_22 = true ;
F_7 ( V_26 , V_2 ,
L_5 ) ;
}
return 0 ;
}
bool F_19 ( struct V_27 * V_28 ,
struct V_5 * V_29 ,
int V_30 )
{
struct V_31 * V_31 ;
if ( F_20 ( ! F_21 ( V_28 , V_30 ) ) )
return false ;
V_31 = F_22 ( V_28 ) ;
if ( ! F_23 ( V_31 -> V_32 ) )
return false ;
if ( F_23 ( V_31 -> V_33 ) )
return false ;
if ( F_24 ( V_28 , 0 ) < 0 )
return false ;
if ( F_25 ( V_28 ) < 0 )
return false ;
return true ;
}
static int F_26 ( struct V_1 * V_2 ,
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
if ( F_25 ( V_28 ) < 0 )
break;
F_27 ( V_36 , V_28 -> V_45 ) ;
break;
case V_46 :
V_34 = F_28 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_29 ( V_2 , V_36 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_24 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
F_30 ( V_36 -> V_48 , V_36 -> V_15 ) ;
F_30 ( V_36 -> V_15 , V_34 -> V_49 -> V_50 ) ;
V_36 -> V_41 = V_42 ;
V_36 -> V_51 = V_52 ;
V_37 = F_31 ( V_28 , V_4 , NULL ) ;
if ( V_37 != V_53 )
V_38 = V_54 ;
break;
default:
goto V_18;
}
V_18:
if ( V_34 )
F_32 ( V_34 ) ;
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_34 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_55 * V_56 ;
int V_38 = V_39 ;
V_56 = (struct V_55 * ) V_28 -> V_40 ;
if ( V_56 -> V_41 != V_46 ) {
F_35 ( L_6 ,
V_56 -> V_15 , V_56 -> V_48 ) ;
goto V_18;
}
V_34 = F_28 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_29 ( V_2 , V_56 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_24 ( V_28 , V_47 ) < 0 )
goto V_18;
V_56 = (struct V_55 * ) V_28 -> V_40 ;
F_30 ( V_56 -> V_48 , V_56 -> V_15 ) ;
F_30 ( V_56 -> V_15 , V_34 -> V_49 -> V_50 ) ;
V_56 -> V_41 = V_44 ;
V_56 -> V_51 = V_52 ;
if ( F_31 ( V_28 , V_4 , NULL ) != V_53 )
V_38 = V_54 ;
V_18:
if ( V_34 )
F_32 ( V_34 ) ;
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
int F_36 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_35 * V_36 ;
struct V_58 * V_59 ;
struct V_31 * V_31 ;
struct V_3 * V_4 = NULL ;
int V_60 = sizeof( struct V_35 ) ;
int V_38 = V_39 ;
if ( F_20 ( ! F_21 ( V_28 , V_60 ) ) )
goto V_18;
V_31 = F_22 ( V_28 ) ;
if ( F_23 ( V_31 -> V_32 ) )
goto V_18;
if ( F_23 ( V_31 -> V_33 ) )
goto V_18;
if ( ! F_38 ( V_2 , V_31 -> V_32 ) )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
if ( ( V_36 -> V_41 == V_42 ||
V_36 -> V_41 == V_46 ) &&
( V_28 -> V_45 >= sizeof( struct V_58 ) ) ) {
if ( F_25 ( V_28 ) < 0 )
goto V_18;
if ( F_24 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_59 = (struct V_58 * ) V_36 ;
if ( V_59 -> V_61 >= V_62 )
goto V_18;
F_30 ( V_59 -> V_63 [ V_59 -> V_61 ] ,
V_31 -> V_32 ) ;
V_59 -> V_61 ++ ;
}
if ( F_38 ( V_2 , V_36 -> V_48 ) )
return F_26 ( V_2 , V_28 ) ;
if ( V_36 -> V_51 < 2 )
return F_34 ( V_2 , V_28 ) ;
V_4 = F_29 ( V_2 , V_36 -> V_48 ) ;
if ( ! V_4 )
goto V_18;
if ( F_24 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_36 -> V_51 -- ;
if ( F_31 ( V_28 , V_4 , V_6 ) != V_53 )
V_38 = V_54 ;
V_18:
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_60 )
{
struct V_31 * V_31 ;
if ( F_20 ( ! F_21 ( V_28 , V_60 ) ) )
return - V_64 ;
V_31 = F_22 ( V_28 ) ;
if ( F_23 ( V_31 -> V_32 ) )
return - V_65 ;
if ( F_23 ( V_31 -> V_33 ) )
return - V_65 ;
if ( ! F_38 ( V_2 , V_31 -> V_32 ) )
return - V_66 ;
return 0 ;
}
struct V_7 *
F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_67 * V_68 = V_2 -> V_69 ;
struct V_7 * V_70 = NULL ;
struct V_7 * V_71 = NULL ;
struct V_7 * V_12 , * V_72 = NULL ;
struct V_7 * V_73 = NULL ;
struct V_9 * V_74 , * V_75 = NULL ;
struct V_9 * V_76 = NULL ;
struct V_9 * V_77 ;
bool V_78 = false ;
if ( ! V_4 )
return NULL ;
V_12 = F_16 ( V_4 , V_6 ) ;
if ( ! V_12 )
return V_12 ;
if ( ! ( V_6 == V_79 && F_41 ( & V_2 -> V_80 ) ) )
return V_12 ;
F_3 () ;
V_77 = V_4 -> V_81 ;
if ( V_77 )
V_73 = F_4 ( V_77 -> V_12 ) ;
F_42 (cand, &orig_node->ifinfo_list, list) {
if ( ! F_5 ( & V_74 -> V_13 ) )
continue;
V_72 = F_4 ( V_74 -> V_12 ) ;
if ( ! V_72 )
goto V_82;
if ( ! F_5 ( & V_72 -> V_13 ) ) {
V_72 = NULL ;
goto V_82;
}
if ( ! V_68 -> V_83 ( V_72 ,
V_74 -> V_84 ,
V_12 , V_6 ) )
goto V_82;
if ( V_73 == V_72 )
goto V_82;
if ( ! V_75 ) {
F_43 ( & V_72 -> V_13 ) ;
F_43 ( & V_74 -> V_13 ) ;
V_75 = V_74 ;
V_70 = V_72 ;
}
if ( ! V_77 || V_78 ) {
V_76 = V_74 ;
V_71 = V_72 ;
break;
}
if ( V_77 == V_74 )
V_78 = true ;
V_82:
if ( V_72 ) {
F_9 ( V_72 ) ;
V_72 = NULL ;
}
F_14 ( V_74 ) ;
}
F_6 () ;
if ( V_4 -> V_81 )
F_14 ( V_4 -> V_81 ) ;
if ( V_76 ) {
F_9 ( V_12 ) ;
if ( V_75 ) {
F_9 ( V_70 ) ;
F_14 ( V_75 ) ;
}
V_12 = V_71 ;
V_4 -> V_81 = V_76 ;
} else if ( V_75 ) {
F_9 ( V_12 ) ;
V_12 = V_70 ;
V_4 -> V_81 = V_75 ;
} else {
V_4 -> V_81 = NULL ;
}
return V_12 ;
}
static int F_44 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_85 * V_86 ;
struct V_31 * V_31 = F_22 ( V_28 ) ;
int V_37 , V_87 , V_38 = V_39 ;
V_86 = (struct V_85 * ) V_28 -> V_40 ;
if ( V_86 -> V_51 < 2 ) {
F_35 ( L_7 ,
V_31 -> V_33 , V_86 -> V_88 ) ;
goto V_18;
}
V_4 = F_29 ( V_2 , V_86 -> V_88 ) ;
if ( ! V_4 )
goto V_18;
if ( F_24 ( V_28 , V_47 ) < 0 )
goto V_18;
V_86 = (struct V_85 * ) V_28 -> V_40 ;
V_86 -> V_51 -- ;
switch ( V_86 -> V_89 ) {
case V_90 :
V_87 = sizeof( struct V_91 ) ;
break;
case V_92 :
V_87 = sizeof( struct V_85 ) ;
break;
default:
V_87 = - 1 ;
break;
}
if ( V_87 > 0 )
F_45 ( V_28 , V_87 ) ;
V_37 = F_31 ( V_28 , V_4 , V_6 ) ;
if ( V_37 == V_93 ) {
F_46 ( V_2 , V_94 ) ;
F_47 ( V_2 , V_95 ,
V_28 -> V_45 + V_47 ) ;
V_38 = V_54 ;
} else if ( V_37 == V_96 ) {
V_38 = V_54 ;
}
V_18:
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
static bool
F_48 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_2 * V_97 , unsigned short V_98 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_34 = NULL ;
bool V_38 = false ;
T_2 * V_99 , V_100 ;
if ( F_49 ( V_2 , V_97 , V_98 ) ) {
V_34 = F_28 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_99 = V_34 -> V_49 -> V_50 ;
V_100 = ( T_2 ) F_41 ( & V_2 -> V_101 . V_102 ) ;
} else {
V_4 = F_50 ( V_2 , NULL , V_97 ,
V_98 ) ;
if ( ! V_4 )
goto V_18;
if ( F_51 ( V_4 -> V_15 , V_86 -> V_88 ) )
goto V_18;
V_99 = V_4 -> V_15 ;
V_100 = ( T_2 ) F_41 ( & V_4 -> V_103 ) ;
}
F_30 ( V_86 -> V_88 , V_99 ) ;
V_86 -> V_104 = V_100 ;
V_38 = true ;
V_18:
if ( V_34 )
F_32 ( V_34 ) ;
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_87 ) {
struct V_85 * V_86 ;
struct V_5 * V_34 ;
struct V_3 * V_4 ;
T_2 V_105 , V_106 ;
struct V_31 * V_31 ;
unsigned short V_98 ;
int V_107 ;
if ( ! F_21 ( V_28 , V_87 + V_47 ) )
return 0 ;
if ( F_24 ( V_28 , sizeof( * V_86 ) ) < 0 )
return 0 ;
V_86 = (struct V_85 * ) V_28 -> V_40 ;
V_98 = F_53 ( V_28 , V_87 ) ;
V_31 = (struct V_31 * ) ( V_28 -> V_40 + V_87 ) ;
if ( F_54 ( V_2 , V_31 -> V_32 , V_98 ) ) {
if ( F_48 ( V_2 , V_86 ,
V_31 -> V_32 , V_98 ) )
F_55 ( V_108 ,
V_2 ,
L_8 ,
V_86 -> V_88 ,
V_31 -> V_32 ) ;
return 1 ;
}
V_105 = ( T_2 ) F_41 ( & V_2 -> V_101 . V_102 ) ;
if ( ! F_38 ( V_2 , V_86 -> V_88 ) ) {
V_4 = F_29 ( V_2 ,
V_86 -> V_88 ) ;
if ( ! V_4 )
return 0 ;
V_105 = ( T_2 ) F_41 ( & V_4 -> V_103 ) ;
F_33 ( V_4 ) ;
}
V_107 = F_56 ( V_86 -> V_104 , V_105 ) ;
if ( ! V_107 )
return 1 ;
V_106 = V_86 -> V_104 ;
if ( F_48 ( V_2 , V_86 ,
V_31 -> V_32 , V_98 ) ) {
F_55 ( V_108 , V_2 ,
L_9 ,
V_86 -> V_88 , V_31 -> V_32 ,
V_106 , V_105 ) ;
return 1 ;
}
if ( ! F_49 ( V_2 , V_31 -> V_32 , V_98 ) )
return 0 ;
V_34 = F_28 ( V_2 ) ;
if ( ! V_34 )
return 0 ;
F_30 ( V_86 -> V_88 , V_34 -> V_49 -> V_50 ) ;
F_32 ( V_34 ) ;
V_86 -> V_104 = V_105 ;
return 1 ;
}
int F_57 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_85 * V_86 ;
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
int V_109 , V_60 = sizeof( * V_86 ) ;
V_109 = F_39 ( V_2 , V_28 , V_60 ) ;
if ( V_109 < 0 )
return V_39 ;
V_86 = (struct V_85 * ) V_28 -> V_40 ;
if ( F_38 ( V_2 , V_86 -> V_88 ) )
return V_39 ;
return F_44 ( V_28 , V_6 ) ;
}
int F_58 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_85 * V_86 ;
struct V_91 * V_110 ;
T_2 * V_99 ;
struct V_3 * V_4 = NULL ;
int V_109 , V_60 = sizeof( * V_86 ) ;
enum V_111 V_112 ;
bool V_113 ;
V_86 = (struct V_85 * ) V_28 -> V_40 ;
V_110 = (struct V_91 * ) V_28 -> V_40 ;
V_113 = V_86 -> V_89 == V_90 ;
if ( V_113 )
V_60 = sizeof( * V_110 ) ;
V_109 = F_39 ( V_2 , V_28 , V_60 ) ;
if ( V_109 == - V_66 )
F_59 ( V_2 , V_28 ) ;
if ( V_109 < 0 )
return V_39 ;
if ( ! F_52 ( V_2 , V_28 , V_60 ) )
return V_39 ;
if ( F_38 ( V_2 , V_86 -> V_88 ) ) {
if ( V_113 ) {
V_112 = V_110 -> V_112 ;
F_60 ( V_2 , V_112 ) ;
if ( V_112 == V_114 ) {
V_99 = V_110 -> V_115 ;
V_4 = F_29 ( V_2 ,
V_99 ) ;
}
}
if ( F_61 ( V_2 , V_28 ,
V_60 ) )
goto V_116;
if ( F_62 ( V_2 , V_28 ,
V_60 ) )
goto V_116;
F_63 ( V_6 -> V_57 , V_28 , V_6 , V_60 ,
V_4 ) ;
V_116:
if ( V_4 )
F_33 ( V_4 ) ;
return V_54 ;
}
return F_44 ( V_28 , V_6 ) ;
}
int F_64 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_117 * V_118 ;
unsigned char * V_119 ;
T_3 V_120 ;
int V_60 = sizeof( * V_118 ) ;
int V_38 = V_39 ;
if ( F_39 ( V_2 , V_28 , V_60 ) < 0 )
return V_39 ;
if ( F_24 ( V_28 , V_60 ) < 0 )
return V_39 ;
if ( F_25 ( V_28 ) < 0 )
return V_39 ;
V_118 = (struct V_117 * ) V_28 -> V_40 ;
V_119 = ( unsigned char * ) ( V_28 -> V_40 + V_60 ) ;
V_120 = F_65 ( V_118 -> V_121 ) ;
if ( V_120 > V_28 -> V_45 - V_60 )
return V_39 ;
V_38 = F_66 ( V_2 , false , NULL ,
V_118 -> V_115 ,
V_118 -> V_48 ,
V_119 , V_120 ) ;
if ( V_38 != V_54 )
V_38 = F_44 ( V_28 , V_6 ) ;
else
F_67 ( V_28 ) ;
return V_38 ;
}
int F_68 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_3 * V_122 = NULL ;
struct V_123 * V_124 ;
int V_38 = V_39 ;
if ( F_39 ( V_2 , V_28 ,
sizeof( * V_124 ) ) < 0 )
goto V_18;
V_124 = (struct V_123 * ) V_28 -> V_40 ;
V_122 = F_29 ( V_2 , V_124 -> V_15 ) ;
if ( ! V_122 )
goto V_18;
if ( ! F_38 ( V_2 , V_124 -> V_88 ) &&
F_69 ( V_28 , V_6 , V_122 ) ) {
V_38 = V_54 ;
goto V_18;
}
F_46 ( V_2 , V_125 ) ;
F_47 ( V_2 , V_126 , V_28 -> V_45 ) ;
if ( ! F_70 ( & V_28 , V_122 ) )
goto V_18;
if ( V_28 )
F_71 ( V_28 , V_6 -> V_49 ,
& V_6 -> V_127 , NULL ) ;
V_38 = V_54 ;
V_18:
if ( V_122 )
F_33 ( V_122 ) ;
return V_38 ;
}
int F_72 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_128 * V_129 ;
struct V_31 * V_31 ;
int V_60 = sizeof( * V_129 ) ;
int V_38 = V_39 ;
T_1 V_130 ;
T_4 V_131 ;
if ( F_20 ( ! F_21 ( V_28 , V_60 ) ) )
goto V_18;
V_31 = F_22 ( V_28 ) ;
if ( ! F_23 ( V_31 -> V_32 ) )
goto V_18;
if ( F_23 ( V_31 -> V_33 ) )
goto V_18;
if ( F_38 ( V_2 , V_31 -> V_33 ) )
goto V_18;
V_129 = (struct V_128 * ) V_28 -> V_40 ;
if ( F_38 ( V_2 , V_129 -> V_15 ) )
goto V_18;
if ( V_129 -> V_51 < 2 )
goto V_18;
V_4 = F_29 ( V_2 , V_129 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
F_10 ( & V_4 -> V_132 ) ;
V_131 = F_73 ( V_129 -> V_131 ) ;
if ( F_74 ( V_4 -> V_133 , V_4 -> V_134 ,
V_131 ) )
goto V_135;
V_130 = V_131 - V_4 -> V_134 ;
if ( F_17 ( V_2 , V_130 ,
V_136 ,
& V_4 -> V_137 , NULL ) )
goto V_135;
if ( F_75 ( V_2 , V_4 -> V_133 , V_130 , 1 ) )
V_4 -> V_134 = V_131 ;
F_13 ( & V_4 -> V_132 ) ;
if ( F_76 ( V_2 , V_28 ) )
goto V_18;
F_45 ( V_28 , sizeof( struct V_128 ) ) ;
F_77 ( V_2 , V_28 , 1 ) ;
if ( F_78 ( V_28 , V_4 , V_60 ) )
goto V_18;
if ( F_61 ( V_2 , V_28 , V_60 ) )
goto V_116;
if ( F_62 ( V_2 , V_28 , V_60 ) )
goto V_116;
F_63 ( V_6 -> V_57 , V_28 , V_6 , V_60 ,
V_4 ) ;
V_116:
V_38 = V_54 ;
goto V_18;
V_135:
F_13 ( & V_4 -> V_132 ) ;
V_18:
if ( V_4 )
F_33 ( V_4 ) ;
return V_38 ;
}
