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
F_11 ( V_10 -> V_12 , V_8 ) ;
F_12 ( & V_4 -> V_17 ) ;
F_13 ( V_10 ) ;
if ( V_11 )
F_9 ( V_11 ) ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_7 * V_12 = NULL ;
if ( ! V_4 )
goto V_18;
V_12 = F_15 ( V_4 , V_6 ) ;
if ( V_12 != V_8 )
F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
V_18:
if ( V_12 )
F_9 ( V_12 ) ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_19 ,
unsigned long * V_20 )
{
if ( V_19 <= - V_21 ||
V_19 >= V_22 ) {
if ( ! F_17 ( * V_20 ,
V_23 ) )
return 1 ;
* V_20 = V_24 ;
F_7 ( V_25 , V_2 ,
L_5 ) ;
}
return 0 ;
}
bool F_18 ( struct V_26 * V_27 ,
struct V_5 * V_28 ,
int V_29 )
{
struct V_30 * V_30 ;
if ( F_19 ( ! F_20 ( V_27 , V_29 ) ) )
return false ;
V_30 = F_21 ( V_27 ) ;
if ( ! F_22 ( V_30 -> V_31 ) )
return false ;
if ( F_22 ( V_30 -> V_32 ) )
return false ;
if ( F_23 ( V_27 , 0 ) < 0 )
return false ;
if ( F_24 ( V_27 ) < 0 )
return false ;
return true ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_5 * V_33 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_34 * V_35 ;
int V_36 , V_37 = V_38 ;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
switch ( V_35 -> V_40 ) {
case V_41 :
case V_42 :
case V_43 :
if ( F_24 ( V_27 ) < 0 )
break;
F_26 ( V_35 , V_27 -> V_44 ) ;
break;
case V_45 :
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
goto V_18;
V_4 = F_28 ( V_2 , V_35 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
F_29 ( V_35 -> V_47 , V_35 -> V_15 ) ;
F_29 ( V_35 -> V_15 , V_33 -> V_48 -> V_49 ) ;
V_35 -> V_40 = V_41 ;
V_35 -> V_50 = V_51 ;
V_36 = F_30 ( V_27 , V_4 , NULL ) ;
if ( V_36 != V_52 )
V_37 = V_53 ;
break;
default:
goto V_18;
}
V_18:
if ( V_33 )
F_31 ( V_33 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_5 * V_33 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_54 * V_55 ;
int V_37 = V_38 ;
V_55 = (struct V_54 * ) V_27 -> V_39 ;
if ( V_55 -> V_40 != V_45 ) {
F_34 ( L_6 ,
V_55 -> V_15 , V_55 -> V_47 ) ;
goto V_18;
}
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
goto V_18;
V_4 = F_28 ( V_2 , V_55 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_55 = (struct V_54 * ) V_27 -> V_39 ;
F_29 ( V_55 -> V_47 , V_55 -> V_15 ) ;
F_29 ( V_55 -> V_15 , V_33 -> V_48 -> V_49 ) ;
V_55 -> V_40 = V_43 ;
V_55 -> V_50 = V_51 ;
if ( F_30 ( V_27 , V_4 , NULL ) != V_52 )
V_37 = V_53 ;
V_18:
if ( V_33 )
F_31 ( V_33 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
int F_35 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_34 * V_35 ;
struct V_57 * V_58 ;
struct V_30 * V_30 ;
struct V_3 * V_4 = NULL ;
int V_59 = sizeof( struct V_34 ) ;
int V_37 = V_38 ;
if ( F_19 ( ! F_20 ( V_27 , V_59 ) ) )
goto V_18;
V_30 = F_21 ( V_27 ) ;
if ( F_22 ( V_30 -> V_31 ) )
goto V_18;
if ( F_22 ( V_30 -> V_32 ) )
goto V_18;
if ( ! F_37 ( V_2 , V_30 -> V_31 ) )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
if ( ( V_35 -> V_40 == V_41 ||
V_35 -> V_40 == V_45 ) &&
( V_27 -> V_44 >= sizeof( struct V_57 ) ) ) {
if ( F_24 ( V_27 ) < 0 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
V_58 = (struct V_57 * ) V_35 ;
if ( V_58 -> V_60 >= V_61 )
goto V_18;
F_29 ( V_58 -> V_62 [ V_58 -> V_60 ] ,
V_30 -> V_31 ) ;
V_58 -> V_60 ++ ;
}
if ( F_37 ( V_2 , V_35 -> V_47 ) )
return F_25 ( V_2 , V_27 ) ;
if ( V_35 -> V_50 < 2 )
return F_33 ( V_2 , V_27 ) ;
V_4 = F_28 ( V_2 , V_35 -> V_47 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
V_35 -> V_50 -- ;
if ( F_30 ( V_27 , V_4 , V_6 ) != V_52 )
V_37 = V_53 ;
V_18:
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_26 * V_27 , int V_59 )
{
struct V_30 * V_30 ;
if ( F_19 ( ! F_20 ( V_27 , V_59 ) ) )
return - V_63 ;
V_30 = F_21 ( V_27 ) ;
if ( F_22 ( V_30 -> V_31 ) )
return - V_64 ;
if ( F_22 ( V_30 -> V_32 ) )
return - V_64 ;
if ( ! F_37 ( V_2 , V_30 -> V_31 ) )
return - V_65 ;
return 0 ;
}
struct V_7 *
F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_66 * V_67 = V_2 -> V_68 ;
struct V_7 * V_69 = NULL ;
struct V_7 * V_70 = NULL ;
struct V_7 * V_12 , * V_71 = NULL ;
struct V_7 * V_72 = NULL ;
struct V_9 * V_73 , * V_74 = NULL ;
struct V_9 * V_75 = NULL ;
struct V_9 * V_76 ;
bool V_77 = false ;
if ( ! V_4 )
return NULL ;
V_12 = F_15 ( V_4 , V_6 ) ;
if ( V_6 == V_78 || ! F_40 ( & V_2 -> V_79 ) ||
! V_12 )
return V_12 ;
F_3 () ;
V_76 = V_4 -> V_80 ;
if ( V_76 )
V_72 = F_4 ( V_76 -> V_12 ) ;
F_41 (cand, &orig_node->ifinfo_list, list) {
if ( ! F_5 ( & V_73 -> V_13 ) )
continue;
V_71 = F_4 ( V_73 -> V_12 ) ;
if ( ! V_71 )
goto V_81;
if ( ! F_5 ( & V_71 -> V_13 ) ) {
V_71 = NULL ;
goto V_81;
}
if ( ! V_67 -> V_82 ( V_71 ,
V_73 -> V_83 ,
V_12 , V_6 ) )
goto V_81;
if ( V_72 == V_71 )
goto V_81;
if ( ! V_74 ) {
F_42 ( & V_71 -> V_13 ) ;
F_42 ( & V_73 -> V_13 ) ;
V_74 = V_73 ;
V_69 = V_71 ;
}
if ( ! V_76 || V_77 ) {
V_75 = V_73 ;
V_70 = V_71 ;
break;
}
if ( V_76 == V_73 )
V_77 = true ;
V_81:
if ( V_71 ) {
F_9 ( V_71 ) ;
V_71 = NULL ;
}
F_13 ( V_73 ) ;
}
F_6 () ;
if ( V_4 -> V_80 )
F_13 ( V_4 -> V_80 ) ;
if ( V_75 ) {
F_9 ( V_12 ) ;
if ( V_74 ) {
F_9 ( V_69 ) ;
F_13 ( V_74 ) ;
}
V_12 = V_70 ;
V_4 -> V_80 = V_75 ;
} else if ( V_74 ) {
F_9 ( V_12 ) ;
V_12 = V_69 ;
V_4 -> V_80 = V_74 ;
} else {
V_4 -> V_80 = NULL ;
}
return V_12 ;
}
static int F_43 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_3 * V_4 = NULL ;
struct V_84 * V_85 ;
struct V_30 * V_30 = F_21 ( V_27 ) ;
int V_36 , V_86 , V_37 = V_38 ;
V_85 = (struct V_84 * ) V_27 -> V_39 ;
if ( V_85 -> V_50 < 2 ) {
F_34 ( L_7 ,
V_30 -> V_32 , V_85 -> V_87 ) ;
goto V_18;
}
V_4 = F_28 ( V_2 , V_85 -> V_87 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_85 = (struct V_84 * ) V_27 -> V_39 ;
V_85 -> V_50 -- ;
switch ( V_85 -> V_88 ) {
case V_89 :
V_86 = sizeof( struct V_90 ) ;
break;
case V_91 :
V_86 = sizeof( struct V_84 ) ;
break;
default:
V_86 = - 1 ;
break;
}
if ( V_86 > 0 )
F_44 ( V_27 , V_86 ) ;
V_36 = F_30 ( V_27 , V_4 , V_6 ) ;
if ( V_36 == V_92 ) {
F_45 ( V_2 , V_93 ) ;
F_46 ( V_2 , V_94 ,
V_27 -> V_44 + V_46 ) ;
V_37 = V_53 ;
} else if ( V_36 == V_95 ) {
V_37 = V_53 ;
}
V_18:
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
static bool
F_47 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_2 * V_96 , unsigned short V_97 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_33 = NULL ;
bool V_37 = false ;
T_2 * V_98 , V_99 ;
if ( F_48 ( V_2 , V_96 , V_97 ) ) {
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
goto V_18;
V_98 = V_33 -> V_48 -> V_49 ;
V_99 = ( T_2 ) F_40 ( & V_2 -> V_100 . V_101 ) ;
} else {
V_4 = F_49 ( V_2 , NULL , V_96 ,
V_97 ) ;
if ( ! V_4 )
goto V_18;
if ( F_50 ( V_4 -> V_15 , V_85 -> V_87 ) )
goto V_18;
V_98 = V_4 -> V_15 ;
V_99 = ( T_2 ) F_40 ( & V_4 -> V_102 ) ;
}
F_29 ( V_85 -> V_87 , V_98 ) ;
V_85 -> V_103 = V_99 ;
V_37 = true ;
V_18:
if ( V_33 )
F_31 ( V_33 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_26 * V_27 , int V_86 ) {
struct V_84 * V_85 ;
struct V_5 * V_33 ;
struct V_3 * V_4 ;
T_2 V_104 , V_105 ;
struct V_30 * V_30 ;
unsigned short V_97 ;
int V_106 ;
if ( ! F_20 ( V_27 , V_86 + V_46 ) )
return 0 ;
if ( F_23 ( V_27 , sizeof( * V_85 ) ) < 0 )
return 0 ;
V_85 = (struct V_84 * ) V_27 -> V_39 ;
V_97 = F_52 ( V_27 , V_86 ) ;
V_30 = (struct V_30 * ) ( V_27 -> V_39 + V_86 ) ;
if ( F_53 ( V_2 , V_30 -> V_31 , V_97 ) ) {
if ( F_47 ( V_2 , V_85 ,
V_30 -> V_31 , V_97 ) )
F_54 ( F_7 , V_107 ,
V_2 ,
L_8 ,
V_85 -> V_87 ,
V_30 -> V_31 ) ;
return 1 ;
}
V_104 = ( T_2 ) F_40 ( & V_2 -> V_100 . V_101 ) ;
if ( ! F_37 ( V_2 , V_85 -> V_87 ) ) {
V_4 = F_28 ( V_2 ,
V_85 -> V_87 ) ;
if ( ! V_4 )
return 0 ;
V_104 = ( T_2 ) F_40 ( & V_4 -> V_102 ) ;
F_32 ( V_4 ) ;
}
V_106 = F_55 ( V_85 -> V_103 , V_104 ) ;
if ( ! V_106 )
return 1 ;
V_105 = V_85 -> V_103 ;
if ( F_47 ( V_2 , V_85 ,
V_30 -> V_31 , V_97 ) ) {
F_54 ( F_7 , V_107 , V_2 ,
L_9 ,
V_85 -> V_87 , V_30 -> V_31 ,
V_105 , V_104 ) ;
return 1 ;
}
if ( ! F_48 ( V_2 , V_30 -> V_31 , V_97 ) )
return 0 ;
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
return 0 ;
F_29 ( V_85 -> V_87 , V_33 -> V_48 -> V_49 ) ;
F_31 ( V_33 ) ;
V_85 -> V_103 = V_104 ;
return 1 ;
}
int F_56 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_84 * V_85 ;
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
int V_108 , V_59 = sizeof( * V_85 ) ;
V_108 = F_38 ( V_2 , V_27 , V_59 ) ;
if ( V_108 < 0 )
return V_38 ;
V_85 = (struct V_84 * ) V_27 -> V_39 ;
if ( F_37 ( V_2 , V_85 -> V_87 ) )
return V_38 ;
return F_43 ( V_27 , V_6 ) ;
}
int F_57 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_84 * V_85 ;
struct V_90 * V_109 ;
T_2 * V_98 ;
struct V_3 * V_4 = NULL ;
int V_108 , V_59 = sizeof( * V_85 ) ;
bool V_110 ;
V_85 = (struct V_84 * ) V_27 -> V_39 ;
V_109 = (struct V_90 * ) V_27 -> V_39 ;
V_110 = V_85 -> V_88 == V_89 ;
if ( V_110 )
V_59 = sizeof( * V_109 ) ;
V_108 = F_38 ( V_2 , V_27 , V_59 ) ;
if ( V_108 == - V_65 )
F_58 ( V_2 , V_27 ) ;
if ( V_108 < 0 )
return V_38 ;
if ( ! F_51 ( V_2 , V_27 , V_59 ) )
return V_38 ;
if ( F_37 ( V_2 , V_85 -> V_87 ) ) {
if ( V_110 ) {
F_59 ( V_2 ,
V_109 -> V_111 ) ;
V_98 = V_109 -> V_112 ;
V_4 = F_28 ( V_2 , V_98 ) ;
}
if ( F_60 ( V_2 , V_27 ,
V_59 ) )
goto V_113;
if ( F_61 ( V_2 , V_27 ,
V_59 ) )
goto V_113;
F_62 ( V_6 -> V_56 , V_27 , V_6 , V_59 ,
V_4 ) ;
V_113:
if ( V_4 )
F_32 ( V_4 ) ;
return V_53 ;
}
return F_43 ( V_27 , V_6 ) ;
}
int F_63 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_114 * V_115 ;
unsigned char * V_116 ;
T_3 V_117 ;
int V_59 = sizeof( * V_115 ) ;
int V_37 = V_38 ;
if ( F_38 ( V_2 , V_27 , V_59 ) < 0 )
return V_38 ;
if ( F_23 ( V_27 , V_59 ) < 0 )
return V_38 ;
if ( F_24 ( V_27 ) < 0 )
return V_38 ;
V_115 = (struct V_114 * ) V_27 -> V_39 ;
V_116 = ( unsigned char * ) ( V_27 -> V_39 + V_59 ) ;
V_117 = F_64 ( V_115 -> V_118 ) ;
if ( V_117 > V_27 -> V_44 - V_59 )
return V_38 ;
V_37 = F_65 ( V_2 , false , NULL ,
V_115 -> V_112 ,
V_115 -> V_47 ,
V_116 , V_117 ) ;
if ( V_37 != V_53 )
V_37 = F_43 ( V_27 , V_6 ) ;
else
F_66 ( V_27 ) ;
return V_37 ;
}
int F_67 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_3 * V_119 = NULL ;
struct V_120 * V_121 ;
int V_37 = V_38 ;
if ( F_38 ( V_2 , V_27 ,
sizeof( * V_121 ) ) < 0 )
goto V_18;
V_121 = (struct V_120 * ) V_27 -> V_39 ;
V_119 = F_28 ( V_2 , V_121 -> V_15 ) ;
if ( ! V_119 )
goto V_18;
if ( ! F_37 ( V_2 , V_121 -> V_87 ) &&
F_68 ( V_27 , V_6 , V_119 ) ) {
V_37 = V_53 ;
goto V_18;
}
F_45 ( V_2 , V_122 ) ;
F_46 ( V_2 , V_123 , V_27 -> V_44 ) ;
if ( ! F_69 ( & V_27 , V_119 ) )
goto V_18;
if ( V_27 )
F_70 ( V_27 , V_6 -> V_48 ,
& V_6 -> V_124 , NULL ) ;
V_37 = V_53 ;
V_18:
if ( V_119 )
F_32 ( V_119 ) ;
return V_37 ;
}
int F_71 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 -> V_56 ) ;
struct V_3 * V_4 = NULL ;
struct V_125 * V_126 ;
struct V_30 * V_30 ;
int V_59 = sizeof( * V_126 ) ;
int V_37 = V_38 ;
T_1 V_127 ;
T_4 V_128 ;
if ( F_19 ( ! F_20 ( V_27 , V_59 ) ) )
goto V_18;
V_30 = F_21 ( V_27 ) ;
if ( ! F_22 ( V_30 -> V_31 ) )
goto V_18;
if ( F_22 ( V_30 -> V_32 ) )
goto V_18;
if ( F_37 ( V_2 , V_30 -> V_32 ) )
goto V_18;
V_126 = (struct V_125 * ) V_27 -> V_39 ;
if ( F_37 ( V_2 , V_126 -> V_15 ) )
goto V_18;
if ( V_126 -> V_50 < 2 )
goto V_18;
V_4 = F_28 ( V_2 , V_126 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
F_10 ( & V_4 -> V_129 ) ;
V_128 = F_72 ( V_126 -> V_128 ) ;
if ( F_73 ( V_4 -> V_130 , V_4 -> V_131 ,
V_128 ) )
goto V_132;
V_127 = V_128 - V_4 -> V_131 ;
if ( F_16 ( V_2 , V_127 ,
& V_4 -> V_133 ) )
goto V_132;
if ( F_74 ( V_2 , V_4 -> V_130 , V_127 , 1 ) )
V_4 -> V_131 = V_128 ;
F_12 ( & V_4 -> V_129 ) ;
if ( F_75 ( V_2 , V_27 ) )
goto V_18;
F_44 ( V_27 , sizeof( struct V_125 ) ) ;
F_76 ( V_2 , V_27 , 1 ) ;
if ( F_77 ( V_27 , V_4 , V_59 ) )
goto V_18;
if ( F_60 ( V_2 , V_27 , V_59 ) )
goto V_113;
if ( F_61 ( V_2 , V_27 , V_59 ) )
goto V_113;
F_62 ( V_6 -> V_56 , V_27 , V_6 , V_59 ,
V_4 ) ;
V_113:
V_37 = V_53 ;
goto V_18;
V_132:
F_12 ( & V_4 -> V_129 ) ;
V_18:
if ( V_4 )
F_32 ( V_4 ) ;
return V_37 ;
}
