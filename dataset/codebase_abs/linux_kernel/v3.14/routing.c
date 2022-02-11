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
memcpy ( V_35 -> V_47 , V_35 -> V_15 , V_48 ) ;
memcpy ( V_35 -> V_15 , V_33 -> V_49 -> V_50 , V_48 ) ;
V_35 -> V_40 = V_41 ;
V_35 -> V_51 = V_52 ;
V_36 = F_29 ( V_27 , V_4 , NULL ) ;
if ( V_36 != V_53 )
V_37 = V_54 ;
break;
default:
goto V_18;
}
V_18:
if ( V_33 )
F_30 ( V_33 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_5 * V_33 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_55 * V_56 ;
int V_37 = V_38 ;
V_56 = (struct V_55 * ) V_27 -> V_39 ;
if ( V_56 -> V_40 != V_45 ) {
F_33 ( L_6 ,
V_56 -> V_15 , V_56 -> V_47 ) ;
goto V_18;
}
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
goto V_18;
V_4 = F_28 ( V_2 , V_56 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_56 = (struct V_55 * ) V_27 -> V_39 ;
memcpy ( V_56 -> V_47 , V_56 -> V_15 , V_48 ) ;
memcpy ( V_56 -> V_15 , V_33 -> V_49 -> V_50 ,
V_48 ) ;
V_56 -> V_40 = V_43 ;
V_56 -> V_51 = V_52 ;
if ( F_29 ( V_27 , V_4 , NULL ) != V_53 )
V_37 = V_54 ;
V_18:
if ( V_33 )
F_30 ( V_33 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
int F_34 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_34 * V_35 ;
struct V_58 * V_59 ;
struct V_30 * V_30 ;
struct V_3 * V_4 = NULL ;
int V_60 = sizeof( struct V_34 ) ;
int V_37 = V_38 ;
if ( F_19 ( ! F_20 ( V_27 , V_60 ) ) )
goto V_18;
V_30 = F_21 ( V_27 ) ;
if ( F_22 ( V_30 -> V_31 ) )
goto V_18;
if ( F_22 ( V_30 -> V_32 ) )
goto V_18;
if ( ! F_36 ( V_2 , V_30 -> V_31 ) )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
if ( ( V_35 -> V_40 == V_41 ||
V_35 -> V_40 == V_45 ) &&
( V_27 -> V_44 >= sizeof( struct V_58 ) ) ) {
if ( F_24 ( V_27 ) < 0 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
V_59 = (struct V_58 * ) V_35 ;
if ( V_59 -> V_61 >= V_62 )
goto V_18;
memcpy ( & ( V_59 -> V_63 [ V_59 -> V_61 ] ) ,
V_30 -> V_31 , V_48 ) ;
V_59 -> V_61 ++ ;
}
if ( F_36 ( V_2 , V_35 -> V_47 ) )
return F_25 ( V_2 , V_27 ) ;
if ( V_35 -> V_51 < 2 )
return F_32 ( V_2 , V_27 ) ;
V_4 = F_28 ( V_2 , V_35 -> V_47 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_35 = (struct V_34 * ) V_27 -> V_39 ;
V_35 -> V_51 -- ;
if ( F_29 ( V_27 , V_4 , V_6 ) != V_53 )
V_37 = V_54 ;
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_26 * V_27 , int V_60 )
{
struct V_30 * V_30 ;
if ( F_19 ( ! F_20 ( V_27 , V_60 ) ) )
return - V_64 ;
V_30 = F_21 ( V_27 ) ;
if ( F_22 ( V_30 -> V_31 ) )
return - V_65 ;
if ( F_22 ( V_30 -> V_32 ) )
return - V_65 ;
if ( ! F_36 ( V_2 , V_30 -> V_31 ) )
return - V_66 ;
return 0 ;
}
struct V_7 *
F_38 ( struct V_1 * V_2 ,
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
V_12 = F_15 ( V_4 , V_6 ) ;
if ( V_6 == V_79 || ! F_39 ( & V_2 -> V_80 ) ||
! V_12 )
return V_12 ;
F_3 () ;
V_77 = V_4 -> V_81 ;
if ( V_77 )
V_73 = F_4 ( V_77 -> V_12 ) ;
F_40 (cand, &orig_node->ifinfo_list, list) {
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
F_41 ( & V_72 -> V_13 ) ;
F_41 ( & V_74 -> V_13 ) ;
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
F_13 ( V_74 ) ;
}
F_6 () ;
if ( V_4 -> V_81 )
F_13 ( V_4 -> V_81 ) ;
if ( V_76 ) {
F_9 ( V_12 ) ;
if ( V_75 ) {
F_9 ( V_70 ) ;
F_13 ( V_75 ) ;
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
static int F_42 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_85 * V_86 ;
struct V_30 * V_30 = F_21 ( V_27 ) ;
int V_36 , V_87 , V_37 = V_38 ;
V_86 = (struct V_85 * ) V_27 -> V_39 ;
if ( V_86 -> V_51 < 2 ) {
F_33 ( L_7 ,
V_30 -> V_32 , V_86 -> V_88 ) ;
goto V_18;
}
V_4 = F_28 ( V_2 , V_86 -> V_88 ) ;
if ( ! V_4 )
goto V_18;
if ( F_23 ( V_27 , V_46 ) < 0 )
goto V_18;
V_86 = (struct V_85 * ) V_27 -> V_39 ;
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
F_43 ( V_27 , V_87 ) ;
V_36 = F_29 ( V_27 , V_4 , V_6 ) ;
if ( V_36 == V_93 ) {
F_44 ( V_2 , V_94 ) ;
F_45 ( V_2 , V_95 ,
V_27 -> V_44 + V_46 ) ;
V_37 = V_54 ;
} else if ( V_36 == V_96 ) {
V_37 = V_54 ;
}
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
static bool
F_46 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_2 * V_97 , unsigned short V_98 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_33 = NULL ;
bool V_37 = false ;
T_2 * V_99 , V_100 ;
if ( F_47 ( V_2 , V_97 , V_98 ) ) {
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
goto V_18;
V_99 = V_33 -> V_49 -> V_50 ;
V_100 = ( T_2 ) F_39 ( & V_2 -> V_101 . V_102 ) ;
} else {
V_4 = F_48 ( V_2 , NULL , V_97 ,
V_98 ) ;
if ( ! V_4 )
goto V_18;
if ( F_49 ( V_4 -> V_15 , V_86 -> V_88 ) )
goto V_18;
V_99 = V_4 -> V_15 ;
V_100 = ( T_2 ) F_39 ( & V_4 -> V_103 ) ;
}
memcpy ( V_86 -> V_88 , V_99 , V_48 ) ;
V_86 -> V_104 = V_100 ;
V_37 = true ;
V_18:
if ( V_33 )
F_30 ( V_33 ) ;
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_26 * V_27 , int V_87 ) {
struct V_85 * V_86 ;
struct V_5 * V_33 ;
struct V_3 * V_4 ;
T_2 V_105 , V_106 ;
struct V_30 * V_30 ;
unsigned short V_98 ;
int V_107 ;
if ( ! F_20 ( V_27 , V_87 + V_46 ) )
return 0 ;
if ( F_23 ( V_27 , sizeof( * V_86 ) ) < 0 )
return 0 ;
V_86 = (struct V_85 * ) V_27 -> V_39 ;
V_98 = F_51 ( V_27 , V_87 ) ;
V_30 = (struct V_30 * ) ( V_27 -> V_39 + V_87 ) ;
if ( F_52 ( V_2 , V_30 -> V_31 , V_98 ) ) {
if ( F_46 ( V_2 , V_86 ,
V_30 -> V_31 , V_98 ) )
F_53 ( F_7 , V_108 ,
V_2 ,
L_8 ,
V_86 -> V_88 ,
V_30 -> V_31 ) ;
return 1 ;
}
V_105 = ( T_2 ) F_39 ( & V_2 -> V_101 . V_102 ) ;
if ( ! F_36 ( V_2 , V_86 -> V_88 ) ) {
V_4 = F_28 ( V_2 ,
V_86 -> V_88 ) ;
if ( ! V_4 )
return 0 ;
V_105 = ( T_2 ) F_39 ( & V_4 -> V_103 ) ;
F_31 ( V_4 ) ;
}
V_107 = F_54 ( V_86 -> V_104 , V_105 ) ;
if ( ! V_107 )
return 1 ;
V_106 = V_86 -> V_104 ;
if ( F_46 ( V_2 , V_86 ,
V_30 -> V_31 , V_98 ) ) {
F_53 ( F_7 , V_108 , V_2 ,
L_9 ,
V_86 -> V_88 , V_30 -> V_31 ,
V_106 , V_105 ) ;
return 1 ;
}
if ( ! F_47 ( V_2 , V_30 -> V_31 , V_98 ) )
return 0 ;
V_33 = F_27 ( V_2 ) ;
if ( ! V_33 )
return 0 ;
memcpy ( V_86 -> V_88 , V_33 -> V_49 -> V_50 , V_48 ) ;
F_30 ( V_33 ) ;
V_86 -> V_104 = V_105 ;
return 1 ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_85 * V_86 ;
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
int V_109 , V_60 = sizeof( * V_86 ) ;
V_109 = F_37 ( V_2 , V_27 , V_60 ) ;
if ( V_109 < 0 )
return V_38 ;
V_86 = (struct V_85 * ) V_27 -> V_39 ;
if ( F_36 ( V_2 , V_86 -> V_88 ) )
return V_38 ;
return F_42 ( V_27 , V_6 ) ;
}
int F_56 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_85 * V_86 ;
struct V_91 * V_110 ;
T_2 * V_99 ;
struct V_3 * V_4 = NULL ;
int V_109 , V_60 = sizeof( * V_86 ) ;
bool V_111 ;
V_86 = (struct V_85 * ) V_27 -> V_39 ;
V_110 = (struct V_91 * ) V_27 -> V_39 ;
V_111 = V_86 -> V_89 == V_90 ;
if ( V_111 )
V_60 = sizeof( * V_110 ) ;
V_109 = F_37 ( V_2 , V_27 , V_60 ) ;
if ( V_109 == - V_66 )
F_57 ( V_2 , V_27 ) ;
if ( V_109 < 0 )
return V_38 ;
if ( ! F_50 ( V_2 , V_27 , V_60 ) )
return V_38 ;
if ( F_36 ( V_2 , V_86 -> V_88 ) ) {
if ( V_111 ) {
F_58 ( V_2 ,
V_110 -> V_112 ) ;
V_99 = V_110 -> V_113 ;
V_4 = F_28 ( V_2 , V_99 ) ;
}
if ( F_59 ( V_2 , V_27 ,
V_60 ) )
goto V_114;
if ( F_60 ( V_2 , V_27 ,
V_60 ) )
goto V_114;
F_61 ( V_6 -> V_57 , V_27 , V_6 , V_60 ,
V_4 ) ;
V_114:
if ( V_4 )
F_31 ( V_4 ) ;
return V_54 ;
}
return F_42 ( V_27 , V_6 ) ;
}
int F_62 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_115 * V_116 ;
unsigned char * V_117 ;
T_3 V_118 ;
int V_60 = sizeof( * V_116 ) ;
int V_37 = V_38 ;
if ( F_37 ( V_2 , V_27 , V_60 ) < 0 )
return V_38 ;
if ( F_23 ( V_27 , V_60 ) < 0 )
return V_38 ;
if ( F_24 ( V_27 ) < 0 )
return V_38 ;
V_116 = (struct V_115 * ) V_27 -> V_39 ;
V_117 = ( unsigned char * ) ( V_27 -> V_39 + V_60 ) ;
V_118 = F_63 ( V_116 -> V_119 ) ;
if ( V_118 > V_27 -> V_44 - V_60 )
return V_38 ;
V_37 = F_64 ( V_2 , false , NULL ,
V_116 -> V_113 ,
V_116 -> V_47 ,
V_117 , V_118 ) ;
if ( V_37 != V_54 )
V_37 = F_42 ( V_27 , V_6 ) ;
else
F_65 ( V_27 ) ;
return V_37 ;
}
int F_66 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_3 * V_120 = NULL ;
struct V_121 * V_122 ;
int V_37 = V_38 ;
if ( F_37 ( V_2 , V_27 ,
sizeof( * V_122 ) ) < 0 )
goto V_18;
V_122 = (struct V_121 * ) V_27 -> V_39 ;
V_120 = F_28 ( V_2 , V_122 -> V_15 ) ;
if ( ! V_120 )
goto V_18;
if ( ! F_36 ( V_2 , V_122 -> V_88 ) &&
F_67 ( V_27 , V_6 , V_120 ) ) {
V_37 = V_54 ;
goto V_18;
}
F_44 ( V_2 , V_123 ) ;
F_45 ( V_2 , V_124 , V_27 -> V_44 ) ;
if ( ! F_68 ( & V_27 , V_120 ) )
goto V_18;
if ( V_27 )
F_69 ( V_27 , V_6 -> V_49 ,
& V_6 -> V_125 , NULL ) ;
V_37 = V_54 ;
V_18:
if ( V_120 )
F_31 ( V_120 ) ;
return V_37 ;
}
int F_70 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 -> V_57 ) ;
struct V_3 * V_4 = NULL ;
struct V_126 * V_127 ;
struct V_30 * V_30 ;
int V_60 = sizeof( * V_127 ) ;
int V_37 = V_38 ;
T_1 V_128 ;
T_4 V_129 ;
if ( F_19 ( ! F_20 ( V_27 , V_60 ) ) )
goto V_18;
V_30 = F_21 ( V_27 ) ;
if ( ! F_22 ( V_30 -> V_31 ) )
goto V_18;
if ( F_22 ( V_30 -> V_32 ) )
goto V_18;
if ( F_36 ( V_2 , V_30 -> V_32 ) )
goto V_18;
V_127 = (struct V_126 * ) V_27 -> V_39 ;
if ( F_36 ( V_2 , V_127 -> V_15 ) )
goto V_18;
if ( V_127 -> V_51 < 2 )
goto V_18;
V_4 = F_28 ( V_2 , V_127 -> V_15 ) ;
if ( ! V_4 )
goto V_18;
F_10 ( & V_4 -> V_130 ) ;
V_129 = F_71 ( V_127 -> V_129 ) ;
if ( F_72 ( V_4 -> V_131 , V_4 -> V_132 ,
V_129 ) )
goto V_133;
V_128 = V_129 - V_4 -> V_132 ;
if ( F_16 ( V_2 , V_128 ,
& V_4 -> V_134 ) )
goto V_133;
if ( F_73 ( V_2 , V_4 -> V_131 , V_128 , 1 ) )
V_4 -> V_132 = V_129 ;
F_12 ( & V_4 -> V_130 ) ;
if ( F_74 ( V_2 , V_27 ) )
goto V_18;
F_43 ( V_27 , sizeof( struct V_126 ) ) ;
F_75 ( V_2 , V_27 , 1 ) ;
if ( F_76 ( V_27 , V_4 , V_60 ) )
goto V_18;
if ( F_59 ( V_2 , V_27 , V_60 ) )
goto V_114;
if ( F_60 ( V_2 , V_27 , V_60 ) )
goto V_114;
F_61 ( V_6 -> V_57 , V_27 , V_6 , V_60 ,
V_4 ) ;
V_114:
V_37 = V_54 ;
goto V_18;
V_133:
F_12 ( & V_4 -> V_130 ) ;
V_18:
if ( V_4 )
F_31 ( V_4 ) ;
return V_37 ;
}
