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
if ( ! F_21 ( V_31 -> V_33 ) )
return false ;
if ( F_22 ( V_28 , 0 ) < 0 )
return false ;
if ( F_23 ( V_28 ) < 0 )
return false ;
return true ;
}
static int F_24 ( struct V_1 * V_2 ,
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
if ( F_23 ( V_28 ) < 0 )
break;
F_25 ( V_36 , V_28 -> V_45 ) ;
break;
case V_46 :
V_34 = F_26 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_27 ( V_2 , V_36 -> V_16 ) ;
if ( ! V_4 )
goto V_18;
if ( F_22 ( V_28 , V_47 ) < 0 )
goto V_18;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
F_28 ( V_36 -> V_48 , V_36 -> V_16 ) ;
F_28 ( V_36 -> V_16 , V_34 -> V_49 -> V_50 ) ;
V_36 -> V_41 = V_42 ;
V_36 -> V_51 = V_52 ;
V_37 = F_29 ( V_28 , V_4 , NULL ) ;
if ( V_37 == V_53 )
V_38 = V_54 ;
V_28 = NULL ;
break;
case V_55 :
if ( ! F_18 ( V_28 , sizeof( struct V_56 ) ) )
goto V_18;
F_30 ( V_2 , V_28 ) ;
V_38 = V_54 ;
V_28 = NULL ;
goto V_18;
default:
goto V_18;
}
V_18:
if ( V_34 )
F_31 ( V_34 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
F_33 ( V_28 ) ;
return V_38 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_34 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_57 * V_58 ;
int V_37 , V_38 = V_39 ;
V_58 = (struct V_57 * ) V_28 -> V_40 ;
if ( V_58 -> V_41 != V_46 ) {
F_35 ( L_6 ,
V_58 -> V_16 , V_58 -> V_48 ) ;
goto V_18;
}
V_34 = F_26 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_4 = F_27 ( V_2 , V_58 -> V_16 ) ;
if ( ! V_4 )
goto V_18;
if ( F_22 ( V_28 , V_47 ) < 0 )
goto V_18;
V_58 = (struct V_57 * ) V_28 -> V_40 ;
F_28 ( V_58 -> V_48 , V_58 -> V_16 ) ;
F_28 ( V_58 -> V_16 , V_34 -> V_49 -> V_50 ) ;
V_58 -> V_41 = V_44 ;
V_58 -> V_51 = V_52 ;
V_37 = F_29 ( V_28 , V_4 , NULL ) ;
if ( V_37 == V_54 )
V_38 = V_53 ;
V_28 = NULL ;
V_18:
if ( V_34 )
F_31 ( V_34 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
F_33 ( V_28 ) ;
return V_38 ;
}
int F_36 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_35 * V_36 ;
struct V_60 * V_61 ;
struct V_31 * V_31 ;
struct V_3 * V_4 = NULL ;
int V_62 = sizeof( struct V_35 ) ;
int V_37 , V_38 = V_39 ;
if ( F_17 ( ! F_18 ( V_28 , V_62 ) ) )
goto V_63;
V_31 = F_19 ( V_28 ) ;
if ( ! F_21 ( V_31 -> V_32 ) )
goto V_63;
if ( F_38 ( V_31 -> V_33 ) )
goto V_63;
if ( ! F_39 ( V_2 , V_31 -> V_32 ) )
goto V_63;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
if ( ( V_36 -> V_41 == V_42 ||
V_36 -> V_41 == V_46 ) &&
( V_28 -> V_45 >= sizeof( struct V_60 ) ) ) {
if ( F_23 ( V_28 ) < 0 )
goto V_63;
if ( F_22 ( V_28 , V_47 ) < 0 )
goto V_63;
V_31 = F_19 ( V_28 ) ;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_61 = (struct V_60 * ) V_36 ;
if ( V_61 -> V_64 >= V_65 )
goto V_63;
F_28 ( V_61 -> V_66 [ V_61 -> V_64 ] ,
V_31 -> V_32 ) ;
V_61 -> V_64 ++ ;
}
if ( F_39 ( V_2 , V_36 -> V_48 ) )
return F_24 ( V_2 , V_28 ) ;
if ( V_36 -> V_51 < 2 )
return F_34 ( V_2 , V_28 ) ;
V_4 = F_27 ( V_2 , V_36 -> V_48 ) ;
if ( ! V_4 )
goto V_63;
if ( F_22 ( V_28 , V_47 ) < 0 )
goto V_67;
V_36 = (struct V_35 * ) V_28 -> V_40 ;
V_36 -> V_51 -- ;
V_37 = F_29 ( V_28 , V_4 , V_6 ) ;
if ( V_37 == V_53 )
V_38 = V_54 ;
V_28 = NULL ;
V_67:
if ( V_4 )
F_32 ( V_4 ) ;
V_63:
F_33 ( V_28 ) ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_62 )
{
struct V_31 * V_31 ;
if ( F_17 ( ! F_18 ( V_28 , V_62 ) ) )
return - V_68 ;
V_31 = F_19 ( V_28 ) ;
if ( ! F_21 ( V_31 -> V_32 ) )
return - V_69 ;
if ( F_38 ( V_31 -> V_33 ) )
return - V_69 ;
if ( ! F_39 ( V_2 , V_31 -> V_32 ) )
return - V_70 ;
return 0 ;
}
static struct V_9 *
F_41 ( struct V_3 * V_4 )
{
struct V_9 * V_71 ;
F_3 ( & V_4 -> V_12 ) ;
V_71 = V_4 -> V_71 ;
if ( V_71 )
F_5 ( & V_71 -> V_14 ) ;
F_7 ( & V_4 -> V_12 ) ;
return V_71 ;
}
static void
F_42 ( struct V_3 * V_4 ,
struct V_9 * V_72 )
{
struct V_9 * V_73 ;
F_3 ( & V_4 -> V_12 ) ;
V_73 = V_4 -> V_71 ;
if ( V_72 )
F_5 ( & V_72 -> V_14 ) ;
V_4 -> V_71 = V_72 ;
F_7 ( & V_4 -> V_12 ) ;
if ( V_73 )
F_8 ( V_73 ) ;
}
struct V_7 *
F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_74 * V_75 = V_2 -> V_76 ;
struct V_7 * V_77 = NULL ;
struct V_7 * V_78 = NULL ;
struct V_7 * V_13 , * V_79 = NULL ;
struct V_7 * V_80 = NULL ;
struct V_9 * V_81 , * V_82 = NULL ;
struct V_9 * V_83 = NULL ;
struct V_9 * V_84 ;
bool V_85 = false ;
if ( ! V_4 )
return NULL ;
V_13 = F_13 ( V_4 , V_6 ) ;
if ( ! V_13 )
return V_13 ;
if ( ! ( V_6 == V_86 && F_44 ( & V_2 -> V_87 ) ) )
return V_13 ;
F_45 () ;
V_84 = F_41 ( V_4 ) ;
if ( V_84 )
V_80 = F_46 ( V_84 -> V_13 ) ;
F_47 (cand, &orig_node->ifinfo_list, list) {
if ( ! F_48 ( & V_81 -> V_14 ) )
continue;
V_79 = F_46 ( V_81 -> V_13 ) ;
if ( ! V_79 )
goto V_88;
if ( ! F_48 ( & V_79 -> V_14 ) ) {
V_79 = NULL ;
goto V_88;
}
if ( ! V_75 -> V_89 . V_90 ( V_79 ,
V_81 -> V_91 , V_13 ,
V_6 ) )
goto V_88;
if ( V_80 == V_79 )
goto V_88;
if ( ! V_82 ) {
F_5 ( & V_79 -> V_14 ) ;
F_5 ( & V_81 -> V_14 ) ;
V_82 = V_81 ;
V_77 = V_79 ;
}
if ( ! V_84 || V_85 ) {
V_83 = V_81 ;
V_78 = V_79 ;
break;
}
if ( V_84 == V_81 )
V_85 = true ;
V_88:
if ( V_79 ) {
F_11 ( V_79 ) ;
V_79 = NULL ;
}
F_8 ( V_81 ) ;
}
F_49 () ;
if ( V_83 ) {
F_11 ( V_13 ) ;
F_5 ( & V_78 -> V_14 ) ;
V_13 = V_78 ;
F_42 ( V_4 , V_83 ) ;
} else if ( V_82 ) {
F_11 ( V_13 ) ;
F_5 ( & V_77 -> V_14 ) ;
V_13 = V_77 ;
F_42 ( V_4 , V_82 ) ;
} else {
F_42 ( V_4 , NULL ) ;
}
if ( V_82 ) {
F_11 ( V_77 ) ;
F_8 ( V_82 ) ;
}
if ( V_83 ) {
F_11 ( V_78 ) ;
F_8 ( V_83 ) ;
}
if ( V_84 )
F_8 ( V_84 ) ;
return V_13 ;
}
static int F_50 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_3 * V_4 = NULL ;
struct V_92 * V_93 ;
struct V_31 * V_31 = F_19 ( V_28 ) ;
int V_37 , V_94 , V_38 = V_39 ;
unsigned int V_45 ;
V_93 = (struct V_92 * ) V_28 -> V_40 ;
if ( V_93 -> V_51 < 2 ) {
F_35 ( L_7 ,
V_31 -> V_33 , V_93 -> V_95 ) ;
goto V_63;
}
V_4 = F_27 ( V_2 , V_93 -> V_95 ) ;
if ( ! V_4 )
goto V_63;
if ( F_22 ( V_28 , V_47 ) < 0 )
goto V_67;
V_93 = (struct V_92 * ) V_28 -> V_40 ;
V_93 -> V_51 -- ;
switch ( V_93 -> V_96 ) {
case V_97 :
V_94 = sizeof( struct V_98 ) ;
break;
case V_99 :
V_94 = sizeof( struct V_92 ) ;
break;
default:
V_94 = - 1 ;
break;
}
if ( V_94 > 0 )
F_51 ( V_28 , V_94 ) ;
V_45 = V_28 -> V_45 ;
V_37 = F_29 ( V_28 , V_4 , V_6 ) ;
if ( V_37 == V_53 )
V_38 = V_54 ;
V_28 = NULL ;
if ( V_37 == V_53 ) {
F_52 ( V_2 , V_100 ) ;
F_53 ( V_2 , V_101 ,
V_45 + V_47 ) ;
}
V_67:
F_32 ( V_4 ) ;
V_63:
F_33 ( V_28 ) ;
return V_38 ;
}
static bool
F_54 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
T_2 * V_102 , unsigned short V_103 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_34 = NULL ;
bool V_38 = false ;
T_2 * V_104 , V_105 ;
if ( F_55 ( V_2 , V_102 , V_103 ) ) {
V_34 = F_26 ( V_2 ) ;
if ( ! V_34 )
goto V_18;
V_104 = V_34 -> V_49 -> V_50 ;
V_105 = ( T_2 ) F_44 ( & V_2 -> V_106 . V_107 ) ;
} else {
V_4 = F_56 ( V_2 , NULL , V_102 ,
V_103 ) ;
if ( ! V_4 )
goto V_18;
if ( F_57 ( V_4 -> V_16 , V_93 -> V_95 ) )
goto V_18;
V_104 = V_4 -> V_16 ;
V_105 = ( T_2 ) F_44 ( & V_4 -> V_108 ) ;
}
F_28 ( V_93 -> V_95 , V_104 ) ;
V_93 -> V_109 = V_105 ;
V_38 = true ;
V_18:
if ( V_34 )
F_31 ( V_34 ) ;
if ( V_4 )
F_32 ( V_4 ) ;
return V_38 ;
}
static bool F_58 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_94 )
{
struct V_92 * V_93 ;
struct V_5 * V_34 ;
struct V_3 * V_4 ;
T_2 V_110 , V_111 ;
struct V_31 * V_31 ;
unsigned short V_103 ;
int V_112 ;
if ( ! F_18 ( V_28 , V_94 + V_47 ) )
return false ;
if ( F_22 ( V_28 , sizeof( * V_93 ) ) < 0 )
return false ;
V_93 = (struct V_92 * ) V_28 -> V_40 ;
V_103 = F_59 ( V_28 , V_94 ) ;
V_31 = (struct V_31 * ) ( V_28 -> V_40 + V_94 ) ;
if ( F_60 ( V_2 , V_31 -> V_32 , V_103 ) ) {
if ( F_54 ( V_2 , V_93 ,
V_31 -> V_32 , V_103 ) )
F_61 ( V_113 ,
V_2 ,
L_8 ,
V_93 -> V_95 ,
V_31 -> V_32 ) ;
return true ;
}
V_110 = ( T_2 ) F_44 ( & V_2 -> V_106 . V_107 ) ;
if ( ! F_39 ( V_2 , V_93 -> V_95 ) ) {
V_4 = F_27 ( V_2 ,
V_93 -> V_95 ) ;
if ( ! V_4 )
return false ;
V_110 = ( T_2 ) F_44 ( & V_4 -> V_108 ) ;
F_32 ( V_4 ) ;
}
V_112 = F_62 ( V_93 -> V_109 , V_110 ) ;
if ( ! V_112 )
return true ;
V_111 = V_93 -> V_109 ;
if ( F_54 ( V_2 , V_93 ,
V_31 -> V_32 , V_103 ) ) {
F_61 ( V_113 , V_2 ,
L_9 ,
V_93 -> V_95 , V_31 -> V_32 ,
V_111 , V_110 ) ;
return true ;
}
if ( ! F_55 ( V_2 , V_31 -> V_32 , V_103 ) )
return false ;
V_34 = F_26 ( V_2 ) ;
if ( ! V_34 )
return false ;
F_28 ( V_93 -> V_95 , V_34 -> V_49 -> V_50 ) ;
F_31 ( V_34 ) ;
V_93 -> V_109 = V_110 ;
return true ;
}
int F_63 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_92 * V_93 ;
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
int V_114 , V_62 = sizeof( * V_93 ) ;
V_114 = F_40 ( V_2 , V_28 , V_62 ) ;
if ( V_114 < 0 )
goto V_63;
V_93 = (struct V_92 * ) V_28 -> V_40 ;
if ( F_39 ( V_2 , V_93 -> V_95 ) )
goto V_63;
return F_50 ( V_28 , V_6 ) ;
V_63:
F_33 ( V_28 ) ;
return V_39 ;
}
int F_64 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_92 * V_93 ;
struct V_98 * V_115 ;
T_2 * V_104 ;
struct V_3 * V_4 = NULL ;
int V_114 , V_62 = sizeof( * V_93 ) ;
enum V_116 V_117 ;
bool V_118 ;
int V_38 = V_39 ;
V_93 = (struct V_92 * ) V_28 -> V_40 ;
V_115 = (struct V_98 * ) V_28 -> V_40 ;
V_118 = V_93 -> V_96 == V_97 ;
if ( V_118 )
V_62 = sizeof( * V_115 ) ;
V_114 = F_40 ( V_2 , V_28 , V_62 ) ;
if ( V_114 == - V_70 )
F_65 ( V_2 , V_28 ) ;
if ( V_114 < 0 )
goto V_63;
if ( ! F_58 ( V_2 , V_28 , V_62 ) )
goto V_63;
if ( F_39 ( V_2 , V_93 -> V_95 ) ) {
if ( V_118 ) {
V_117 = V_115 -> V_117 ;
F_66 ( V_2 , V_117 ) ;
if ( V_117 == V_119 ) {
V_104 = V_115 -> V_120 ;
V_4 = F_27 ( V_2 ,
V_104 ) ;
}
}
if ( F_67 ( V_2 , V_28 ,
V_62 ) )
goto V_121;
if ( F_68 ( V_2 , V_28 ,
V_62 ) )
goto V_121;
F_69 ( V_6 -> V_59 , V_28 , V_62 ,
V_4 ) ;
V_121:
if ( V_4 )
F_32 ( V_4 ) ;
return V_54 ;
}
V_38 = F_50 ( V_28 , V_6 ) ;
V_28 = NULL ;
V_63:
F_33 ( V_28 ) ;
return V_38 ;
}
int F_70 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_122 * V_123 ;
unsigned char * V_124 ;
T_3 V_125 ;
int V_62 = sizeof( * V_123 ) ;
int V_38 = V_39 ;
if ( F_40 ( V_2 , V_28 , V_62 ) < 0 )
goto V_63;
if ( F_22 ( V_28 , V_62 ) < 0 )
goto V_63;
if ( F_23 ( V_28 ) < 0 )
goto V_63;
V_123 = (struct V_122 * ) V_28 -> V_40 ;
V_124 = ( unsigned char * ) ( V_28 -> V_40 + V_62 ) ;
V_125 = F_71 ( V_123 -> V_126 ) ;
if ( V_125 > V_28 -> V_45 - V_62 )
goto V_63;
V_38 = F_72 ( V_2 , false , NULL ,
V_123 -> V_120 ,
V_123 -> V_48 ,
V_124 , V_125 ) ;
if ( V_38 != V_54 ) {
V_38 = F_50 ( V_28 , V_6 ) ;
V_28 = NULL ;
}
V_63:
F_33 ( V_28 ) ;
return V_38 ;
}
int F_73 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_3 * V_127 = NULL ;
struct V_128 * V_129 ;
int V_38 = V_39 ;
if ( F_40 ( V_2 , V_28 ,
sizeof( * V_129 ) ) < 0 )
goto V_63;
V_129 = (struct V_128 * ) V_28 -> V_40 ;
V_127 = F_27 ( V_2 , V_129 -> V_16 ) ;
if ( ! V_127 )
goto V_63;
V_28 -> V_130 = V_129 -> V_130 + 256 ;
if ( ! F_39 ( V_2 , V_129 -> V_95 ) &&
F_74 ( V_28 , V_6 , V_127 ) ) {
V_28 = NULL ;
V_38 = V_54 ;
goto V_67;
}
F_52 ( V_2 , V_131 ) ;
F_53 ( V_2 , V_132 , V_28 -> V_45 ) ;
if ( ! F_75 ( & V_28 , V_127 ) )
goto V_67;
if ( V_28 ) {
F_76 ( V_28 , V_6 -> V_49 ,
& V_6 -> V_133 , NULL ) ;
V_28 = NULL ;
}
V_38 = V_54 ;
V_67:
F_32 ( V_127 ) ;
V_63:
F_33 ( V_28 ) ;
return V_38 ;
}
int F_77 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_37 ( V_6 -> V_59 ) ;
struct V_3 * V_4 = NULL ;
struct V_134 * V_135 ;
struct V_31 * V_31 ;
int V_62 = sizeof( * V_135 ) ;
int V_38 = V_39 ;
T_1 V_136 ;
T_4 V_137 ;
if ( F_17 ( ! F_18 ( V_28 , V_62 ) ) )
goto V_63;
V_31 = F_19 ( V_28 ) ;
if ( ! F_20 ( V_31 -> V_32 ) )
goto V_63;
if ( F_38 ( V_31 -> V_33 ) )
goto V_63;
if ( F_39 ( V_2 , V_31 -> V_33 ) )
goto V_63;
V_135 = (struct V_134 * ) V_28 -> V_40 ;
if ( F_39 ( V_2 , V_135 -> V_16 ) )
goto V_63;
if ( V_135 -> V_51 < 2 )
goto V_63;
V_4 = F_27 ( V_2 , V_135 -> V_16 ) ;
if ( ! V_4 )
goto V_63;
F_3 ( & V_4 -> V_138 ) ;
V_137 = F_78 ( V_135 -> V_137 ) ;
if ( F_79 ( V_4 -> V_139 , V_4 -> V_140 ,
V_137 ) )
goto V_141;
V_136 = V_137 - V_4 -> V_140 ;
if ( F_14 ( V_2 , V_136 ,
V_142 ,
& V_4 -> V_143 , NULL ) )
goto V_141;
if ( F_80 ( V_2 , V_4 -> V_139 , V_136 , 1 ) )
V_4 -> V_140 = V_137 ;
F_7 ( & V_4 -> V_138 ) ;
if ( F_81 ( V_2 , V_28 ) )
goto V_63;
F_51 ( V_28 , sizeof( struct V_134 ) ) ;
F_82 ( V_2 , V_28 , 1 , false ) ;
if ( F_83 ( V_28 , V_4 , V_62 ) )
goto V_63;
if ( F_67 ( V_2 , V_28 , V_62 ) )
goto V_121;
if ( F_68 ( V_2 , V_28 , V_62 ) )
goto V_121;
F_69 ( V_6 -> V_59 , V_28 , V_62 , V_4 ) ;
V_121:
V_38 = V_54 ;
goto V_18;
V_141:
F_7 ( & V_4 -> V_138 ) ;
V_63:
F_33 ( V_28 ) ;
V_18:
if ( V_4 )
F_32 ( V_4 ) ;
return V_38 ;
}
