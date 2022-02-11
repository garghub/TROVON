void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_4 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 ;
T_1 V_11 ;
if ( V_8 -> V_12 || V_3 -> type != V_13 )
return 1 ;
V_10 = & V_3 -> V_4 . V_14 ;
if ( V_10 -> type != V_15 )
return 1 ;
V_11 = F_6 ( V_6 -> V_16 ,
V_10 -> V_17 . V_18 ,
& V_6 -> V_19 ) ;
if ( ! F_7 ( V_11 ) )
return 1 ;
V_8 -> V_12 = V_10 -> V_20 ;
V_6 -> V_21 = V_10 -> V_22 ;
if ( V_10 -> V_23 == V_24 )
V_8 -> V_25 |= V_26 ;
return 1 ;
}
static int F_8 ( struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_29 V_30 ;
int V_31 ;
if ( F_9 ( V_28 ) || ! V_28 -> V_11 . V_32 ||
F_10 ( V_28 ) )
return - V_33 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 -> V_16 = F_11 ( V_28 ) ;
F_12 ( & V_30 ) ;
V_31 = F_13 ( V_28 , & V_30 ,
F_5 , V_6 ) ;
F_14 ( & V_30 ) ;
if ( V_31 < 0 || ! V_8 -> V_12 )
return - V_33 ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 ,
struct V_7 * V_8 ,
struct V_34 * V_35 ,
T_2 * V_19 )
{
struct V_29 V_30 ;
struct V_36 * V_37 ;
struct V_5 V_6 ;
int V_31 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_8 = V_8 ;
V_31 = F_8 ( V_28 , & V_6 ) ;
if ( V_31 )
return V_31 ;
if ( V_35 ) {
if ( F_16 ( & V_35 -> V_38 ) != V_6 . V_19 )
return - V_39 ;
} else {
struct V_27 * V_40 ;
if ( F_17 ( V_6 . V_19 , & V_40 ) )
return - V_39 ;
if ( F_9 ( V_40 ) ||
! V_40 -> V_11 . V_32 )
return - V_39 ;
}
V_8 -> V_41 = F_18 ( V_28 ) ;
if ( V_19 )
* V_19 = V_6 . V_19 ;
F_12 ( & V_30 ) ;
V_31 = F_13 ( V_28 , & V_30 , NULL , NULL ) ;
if ( V_31 < 0 )
return - V_33 ;
F_19 (entry, &resource_list) {
if ( F_20 ( V_37 -> V_42 ) == V_43 ) {
V_8 -> V_44 = V_37 -> V_42 -> V_45 ;
break;
}
}
F_14 ( & V_30 ) ;
F_21 ( V_8 -> type , F_22 ( & V_28 -> V_38 ) , sizeof( V_8 -> type ) ) ;
return 0 ;
}
static void F_23 ( struct V_34 * V_35 ,
struct V_27 * V_28 ,
struct V_7 * V_8 )
{
V_28 -> V_46 . V_25 . V_47 = true ;
F_24 ( V_28 ) ;
if ( ! F_25 ( V_35 , V_8 ) ) {
V_28 -> V_46 . V_25 . V_47 = false ;
F_26 ( & V_35 -> V_38 ,
L_1 ,
F_22 ( & V_28 -> V_38 ) ) ;
}
}
static T_1 F_27 ( T_2 V_48 , T_3 V_49 ,
void * V_4 , void * * V_50 )
{
struct V_34 * V_35 = V_4 ;
struct V_27 * V_28 ;
struct V_7 V_8 ;
if ( F_17 ( V_48 , & V_28 ) )
return V_51 ;
if ( F_15 ( V_28 , & V_8 , V_35 , NULL ) )
return V_51 ;
F_23 ( V_35 , V_28 , & V_8 ) ;
return V_51 ;
}
static void F_28 ( struct V_34 * V_52 )
{
T_1 V_11 ;
if ( ! F_29 ( & V_52 -> V_38 ) )
return;
V_11 = F_30 ( V_53 , V_54 ,
V_55 ,
F_27 , NULL ,
V_52 , NULL ) ;
if ( F_31 ( V_11 ) )
F_32 ( & V_52 -> V_38 , L_2 ) ;
}
static T_1 F_33 ( T_2 V_48 , T_3 V_49 ,
void * V_4 , void * * V_50 )
{
struct V_5 * V_6 = V_4 ;
struct V_27 * V_28 ;
if ( F_17 ( V_48 , & V_28 ) )
return V_51 ;
if ( F_8 ( V_28 , V_6 ) )
return V_51 ;
if ( V_6 -> V_56 != V_6 -> V_19 )
return V_51 ;
if ( V_6 -> V_21 <= V_6 -> V_57 )
V_6 -> V_57 = V_6 -> V_21 ;
return V_51 ;
}
T_3 F_34 ( struct V_58 * V_38 )
{
struct V_5 V_6 ;
struct V_7 V_59 ;
T_1 V_11 ;
if ( ! F_29 ( V_38 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_56 = F_16 ( V_38 ) ;
V_6 . V_57 = V_60 ;
V_6 . V_8 = & V_59 ;
V_11 = F_30 ( V_53 , V_54 ,
V_55 ,
F_33 , NULL ,
& V_6 , NULL ) ;
if ( F_31 ( V_11 ) ) {
F_32 ( V_38 , L_3 ) ;
return 0 ;
}
return V_6 . V_57 != V_60 ? V_6 . V_57 : 0 ;
}
static int F_35 ( struct V_58 * V_38 , void * V_4 )
{
struct V_34 * V_35 = F_36 ( V_38 ) ;
if ( ! V_35 )
return 0 ;
return F_16 ( V_38 ) == ( T_2 ) V_4 ;
}
static int F_37 ( struct V_58 * V_38 , void * V_4 )
{
return F_38 ( V_38 ) == V_4 ;
}
static struct V_34 * F_39 ( T_2 V_48 )
{
struct V_58 * V_38 ;
V_38 = F_40 ( & V_61 , NULL , V_48 ,
F_35 ) ;
return V_38 ? F_36 ( V_38 ) : NULL ;
}
static struct V_62 * F_41 ( struct V_27 * V_28 )
{
struct V_58 * V_38 ;
V_38 = F_40 ( & V_61 , NULL , V_28 , F_37 ) ;
return V_38 ? F_42 ( V_38 ) : NULL ;
}
static int F_43 ( struct V_63 * V_64 , unsigned long V_65 ,
void * V_66 )
{
struct V_27 * V_28 = V_66 ;
struct V_7 V_8 ;
T_2 V_19 ;
struct V_34 * V_35 ;
struct V_62 * V_67 ;
switch ( V_65 ) {
case V_68 :
if ( F_15 ( V_28 , & V_8 , NULL , & V_19 ) )
break;
V_35 = F_39 ( V_19 ) ;
if ( ! V_35 )
break;
F_23 ( V_35 , V_28 , & V_8 ) ;
break;
case V_69 :
if ( ! F_10 ( V_28 ) )
break;
V_67 = F_41 ( V_28 ) ;
if ( ! V_67 )
break;
F_44 ( V_67 ) ;
F_45 ( & V_67 -> V_38 ) ;
break;
}
return V_70 ;
}
static inline void F_28 ( struct V_34 * V_52 ) { }
static int F_46 ( struct V_62 * V_67 ,
T_4 V_71 , T_4 * V_4 , T_4 V_72 )
{
struct V_73 V_74 [ 2 ] ;
int V_31 ;
T_4 * V_75 ;
V_75 = F_47 ( V_72 , V_76 ) ;
if ( ! V_75 )
return V_77 ;
V_74 [ 0 ] . V_12 = V_67 -> V_12 ;
V_74 [ 0 ] . V_25 = V_67 -> V_25 ;
V_74 [ 0 ] . V_78 = 1 ;
V_74 [ 0 ] . V_79 = & V_71 ;
V_74 [ 1 ] . V_12 = V_67 -> V_12 ;
V_74 [ 1 ] . V_25 = V_67 -> V_25 | V_80 ;
V_74 [ 1 ] . V_78 = V_72 ;
V_74 [ 1 ] . V_79 = V_75 ;
V_31 = F_48 ( V_67 -> V_35 , V_74 , F_49 ( V_74 ) ) ;
if ( V_31 < 0 )
F_26 ( & V_67 -> V_35 -> V_38 , L_4 ) ;
else
memcpy ( V_4 , V_75 , V_72 ) ;
F_50 ( V_75 ) ;
return V_31 ;
}
static int F_51 ( struct V_62 * V_67 ,
T_4 V_71 , T_4 * V_4 , T_4 V_72 )
{
struct V_73 V_74 [ 1 ] ;
T_4 * V_75 ;
int V_31 = V_51 ;
V_75 = F_47 ( V_72 + 1 , V_76 ) ;
if ( ! V_75 )
return V_77 ;
V_75 [ 0 ] = V_71 ;
memcpy ( V_75 + 1 , V_4 , V_72 ) ;
V_74 [ 0 ] . V_12 = V_67 -> V_12 ;
V_74 [ 0 ] . V_25 = V_67 -> V_25 ;
V_74 [ 0 ] . V_78 = V_72 + 1 ;
V_74 [ 0 ] . V_79 = V_75 ;
V_31 = F_48 ( V_67 -> V_35 , V_74 , F_49 ( V_74 ) ) ;
if ( V_31 < 0 )
F_26 ( & V_67 -> V_35 -> V_38 , L_5 ) ;
F_50 ( V_75 ) ;
return V_31 ;
}
static T_1
F_52 ( T_3 V_81 , T_5 V_82 ,
T_3 V_83 , T_6 * V_84 ,
void * V_85 , void * V_86 )
{
struct V_87 * V_88 = (struct V_87 * ) V_84 ;
struct V_89 * V_4 = V_85 ;
struct V_90 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_62 * V_67 ;
struct V_2 * V_3 ;
T_3 V_91 = V_81 >> 16 ;
T_4 V_92 = V_81 & V_93 ;
T_1 V_31 ;
int V_11 ;
V_31 = F_53 ( V_8 -> V_94 , V_8 -> V_95 , & V_3 ) ;
if ( F_31 ( V_31 ) )
return V_31 ;
V_67 = F_47 ( sizeof( * V_67 ) , V_76 ) ;
if ( ! V_67 ) {
V_31 = V_77 ;
goto V_96;
}
if ( ! V_84 || V_3 -> type != V_13 ) {
V_31 = V_97 ;
goto V_96;
}
V_10 = & V_3 -> V_4 . V_14 ;
if ( V_10 -> type != V_15 ) {
V_31 = V_97 ;
goto V_96;
}
V_67 -> V_35 = V_35 ;
V_67 -> V_12 = V_10 -> V_20 ;
if ( V_10 -> V_23 == V_24 )
V_67 -> V_25 |= V_26 ;
switch ( V_91 ) {
case V_98 :
if ( V_92 == V_99 ) {
V_11 = F_54 ( V_67 ) ;
if ( V_11 >= 0 ) {
V_88 -> V_100 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_55 ( V_67 , V_88 -> V_100 ) ;
}
break;
case V_101 :
if ( V_92 == V_99 ) {
V_11 = F_56 ( V_67 , V_82 ) ;
if ( V_11 >= 0 ) {
V_88 -> V_100 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_57 ( V_67 , V_82 ,
V_88 -> V_100 ) ;
}
break;
case V_102 :
if ( V_92 == V_99 ) {
V_11 = F_58 ( V_67 , V_82 ) ;
if ( V_11 >= 0 ) {
V_88 -> V_103 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_59 ( V_67 , V_82 ,
V_88 -> V_103 ) ;
}
break;
case V_104 :
if ( V_92 == V_99 ) {
V_11 = F_60 ( V_67 , V_82 ,
V_88 -> V_4 ) ;
if ( V_11 >= 0 ) {
V_88 -> V_78 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_61 ( V_67 , V_82 ,
V_88 -> V_78 , V_88 -> V_4 ) ;
}
break;
case V_105 :
if ( V_92 == V_99 ) {
V_11 = F_46 ( V_67 , V_82 ,
V_88 -> V_4 , V_8 -> V_106 ) ;
if ( V_11 > 0 )
V_11 = 0 ;
} else {
V_11 = F_51 ( V_67 , V_82 ,
V_88 -> V_4 , V_8 -> V_106 ) ;
}
break;
default:
F_32 ( & V_35 -> V_38 , L_6 ,
V_91 , V_67 -> V_12 ) ;
V_31 = V_97 ;
goto V_96;
}
V_88 -> V_11 = V_11 ;
V_96:
F_50 ( V_67 ) ;
F_62 ( V_3 ) ;
return V_31 ;
}
static int F_63 ( struct V_34 * V_35 )
{
T_2 V_48 ;
struct V_89 * V_4 ;
T_1 V_11 ;
if ( ! V_35 -> V_38 . V_107 )
return - V_39 ;
V_48 = F_16 ( V_35 -> V_38 . V_107 ) ;
if ( ! V_48 )
return - V_39 ;
V_4 = F_47 ( sizeof( struct V_89 ) ,
V_76 ) ;
if ( ! V_4 )
return - V_108 ;
V_4 -> V_35 = V_35 ;
V_11 = F_64 ( V_48 , ( void * ) V_4 ) ;
if ( F_31 ( V_11 ) ) {
F_50 ( V_4 ) ;
return - V_108 ;
}
V_11 = F_65 ( V_48 ,
V_109 ,
& F_52 ,
NULL ,
V_4 ) ;
if ( F_31 ( V_11 ) ) {
F_26 ( & V_35 -> V_38 , L_7 ) ;
F_66 ( V_48 ) ;
F_50 ( V_4 ) ;
return - V_108 ;
}
F_67 ( V_48 ) ;
return 0 ;
}
static void F_68 ( struct V_34 * V_35 )
{
T_2 V_48 ;
struct V_89 * V_4 ;
T_1 V_11 ;
if ( ! V_35 -> V_38 . V_107 )
return;
V_48 = F_16 ( V_35 -> V_38 . V_107 ) ;
if ( ! V_48 )
return;
F_69 ( V_48 ,
V_109 ,
& F_52 ) ;
V_11 = F_70 ( V_48 , ( void * * ) & V_4 ) ;
if ( F_7 ( V_11 ) )
F_50 ( V_4 ) ;
F_66 ( V_48 ) ;
}
static inline void F_68 ( struct V_34 * V_35 )
{ }
static inline int F_63 ( struct V_34 * V_35 )
{ return 0 ; }
static const struct V_110 * F_71 ( const struct V_110 * V_111 ,
const struct V_62 * V_67 )
{
while ( V_111 -> V_112 [ 0 ] ) {
if ( strcmp ( V_67 -> V_112 , V_111 -> V_112 ) == 0 )
return V_111 ;
V_111 ++ ;
}
return NULL ;
}
static int F_72 ( struct V_58 * V_38 , struct V_113 * V_114 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
if ( ! V_67 )
return 0 ;
if ( F_73 ( V_38 , V_114 ) )
return 1 ;
if ( F_74 ( V_38 , V_114 ) )
return 1 ;
V_116 = F_75 ( V_114 ) ;
if ( V_116 -> V_117 )
return F_71 ( V_116 -> V_117 , V_67 ) != NULL ;
return 0 ;
}
static int F_76 ( struct V_58 * V_38 , struct V_118 * V_119 )
{
struct V_62 * V_67 = F_77 ( V_38 ) ;
int V_120 ;
V_120 = F_78 ( V_38 , V_119 ) ;
if ( V_120 != - V_39 )
return V_120 ;
return F_79 ( V_119 , L_8 , V_121 , V_67 -> V_112 ) ;
}
static int F_80 ( struct V_34 * V_52 )
{
return F_81 ( V_52 -> V_122 -> V_123 ) ;
}
static void F_82 ( struct V_34 * V_52 , int V_124 )
{
F_83 ( V_52 -> V_122 -> V_123 , V_124 ) ;
}
static int F_84 ( struct V_34 * V_52 )
{
return F_81 ( V_52 -> V_122 -> V_125 ) ;
}
static int F_85 ( struct V_34 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_122 ;
struct V_58 * V_38 = & V_52 -> V_38 ;
int V_31 = 0 ;
V_31 = F_86 ( V_127 -> V_123 , V_128 |
V_129 , L_9 ) ;
if ( V_31 ) {
F_32 ( V_38 , L_10 , V_127 -> V_123 ) ;
return V_31 ;
}
if ( V_127 -> V_130 ) {
if ( F_86 ( V_127 -> V_125 , V_131 , L_11 ) ) {
F_32 ( V_38 , L_12 ,
V_127 -> V_125 ) ;
V_127 -> V_130 = NULL ;
}
}
return V_31 ;
}
static void F_87 ( struct V_34 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_122 ;
if ( V_127 -> V_130 )
F_88 ( V_127 -> V_125 ) ;
F_88 ( V_127 -> V_123 ) ;
}
static int F_89 ( struct V_34 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_122 ;
int V_132 = 0 , V_124 = 1 , V_31 = 0 ;
if ( V_127 -> V_133 )
V_127 -> V_133 ( V_52 ) ;
V_127 -> V_134 ( V_52 , V_124 ) ;
F_90 ( V_135 ) ;
while ( V_132 ++ < V_136 * 2 ) {
if ( V_124 ) {
if ( V_127 -> V_130 && V_127 -> V_130 ( V_52 ) )
break;
if ( ! V_127 -> V_137 ( V_52 ) ) {
F_26 ( & V_52 -> V_38 ,
L_13 ) ;
V_31 = - V_138 ;
break;
}
}
V_124 = ! V_124 ;
V_127 -> V_134 ( V_52 , V_124 ) ;
F_90 ( V_135 ) ;
}
if ( V_127 -> V_139 )
V_127 -> V_139 ( V_52 ) ;
return V_31 ;
}
int F_91 ( struct V_34 * V_52 )
{
return F_89 ( V_52 ) ;
}
int F_92 ( struct V_34 * V_52 )
{
int V_31 ;
V_31 = F_85 ( V_52 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_89 ( V_52 ) ;
F_87 ( V_52 ) ;
return V_31 ;
}
int F_93 ( struct V_34 * V_52 )
{
if ( ! V_52 -> V_122 )
return - V_140 ;
F_94 ( & V_52 -> V_38 , L_14 ) ;
return V_52 -> V_122 -> V_141 ( V_52 ) ;
}
static void F_95 ( struct V_34 * V_52 )
{
struct V_126 * V_127 = V_52 -> V_122 ;
char * V_142 ;
if ( ! V_127 )
return;
if ( ! V_127 -> V_141 ) {
V_142 = L_15 ;
goto V_96;
}
if ( V_127 -> V_141 == F_92 ) {
if ( ! F_96 ( V_127 -> V_123 ) ) {
V_142 = L_16 ;
goto V_96;
}
if ( F_96 ( V_127 -> V_125 ) )
V_127 -> V_130 = F_84 ;
else
V_127 -> V_130 = NULL ;
V_127 -> V_137 = F_80 ;
V_127 -> V_134 = F_82 ;
} else if ( V_127 -> V_141 == F_91 ) {
if ( ! V_127 -> V_134 || ! V_127 -> V_137 ) {
V_142 = L_17 ;
goto V_96;
}
}
return;
V_96:
F_26 ( & V_52 -> V_38 , L_18 , V_142 ) ;
V_52 -> V_122 = NULL ;
}
static int F_97 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
int V_11 ;
if ( ! V_67 )
return 0 ;
if ( ! V_67 -> V_44 ) {
int V_44 = - V_143 ;
if ( V_38 -> V_144 ) {
V_44 = F_98 ( V_38 -> V_144 , L_19 ) ;
if ( V_44 == - V_33 || V_44 == - V_145 )
V_44 = F_99 ( V_38 -> V_144 , 0 ) ;
} else if ( F_38 ( V_38 ) ) {
V_44 = F_100 ( F_38 ( V_38 ) , 0 ) ;
}
if ( V_44 == - V_146 )
return V_44 ;
if ( V_44 < 0 )
V_44 = 0 ;
V_67 -> V_44 = V_44 ;
}
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( ! V_116 -> V_147 || ! V_116 -> V_117 )
return - V_39 ;
if ( V_67 -> V_25 & V_148 ) {
int V_149 = - V_143 ;
if ( V_38 -> V_144 ) {
V_149 = F_98 ( V_38 -> V_144 , L_20 ) ;
if ( V_149 == - V_146 )
return V_149 ;
}
F_101 ( & V_67 -> V_38 , true ) ;
if ( V_149 > 0 && V_149 != V_67 -> V_44 )
V_11 = F_102 ( V_38 , V_149 ) ;
else if ( V_67 -> V_44 > 0 )
V_11 = F_103 ( V_38 , V_67 -> V_44 ) ;
else
V_11 = 0 ;
if ( V_11 )
F_32 ( & V_67 -> V_38 , L_21 ) ;
}
F_94 ( V_38 , L_22 ) ;
V_11 = F_104 ( V_38 -> V_144 , false ) ;
if ( V_11 < 0 )
goto V_150;
V_11 = F_105 ( & V_67 -> V_38 , true ) ;
if ( V_11 == - V_146 )
goto V_150;
V_11 = V_116 -> V_147 ( V_67 , F_71 ( V_116 -> V_117 , V_67 ) ) ;
if ( V_11 )
goto V_151;
return 0 ;
V_151:
F_106 ( & V_67 -> V_38 , true ) ;
V_150:
F_107 ( & V_67 -> V_38 ) ;
F_101 ( & V_67 -> V_38 , false ) ;
return V_11 ;
}
static int F_108 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
int V_11 = 0 ;
if ( ! V_67 || ! V_38 -> V_116 )
return 0 ;
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( V_116 -> remove ) {
F_94 ( V_38 , L_23 ) ;
V_11 = V_116 -> remove ( V_67 ) ;
}
F_106 ( & V_67 -> V_38 , true ) ;
F_107 ( & V_67 -> V_38 ) ;
F_101 ( & V_67 -> V_38 , false ) ;
return V_11 ;
}
static void F_109 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
if ( ! V_67 || ! V_38 -> V_116 )
return;
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( V_116 -> V_152 )
V_116 -> V_152 ( V_67 ) ;
}
static void F_110 ( struct V_58 * V_38 )
{
F_50 ( F_77 ( V_38 ) ) ;
}
static T_7
F_111 ( struct V_58 * V_38 , struct V_153 * V_154 , char * V_79 )
{
return sprintf ( V_79 , L_24 , V_38 -> type == & V_155 ?
F_77 ( V_38 ) -> V_112 : F_112 ( V_38 ) -> V_112 ) ;
}
static T_7
F_113 ( struct V_58 * V_38 , struct V_153 * V_154 , char * V_79 )
{
struct V_62 * V_67 = F_77 ( V_38 ) ;
int V_78 ;
V_78 = F_114 ( V_38 , V_79 , V_156 - 1 ) ;
if ( V_78 != - V_39 )
return V_78 ;
return sprintf ( V_79 , L_25 , V_121 , V_67 -> V_112 ) ;
}
struct V_62 * F_42 ( struct V_58 * V_38 )
{
return ( V_38 -> type == & V_155 )
? F_77 ( V_38 )
: NULL ;
}
static unsigned short F_115 ( struct V_62 * V_67 )
{
unsigned short V_12 = V_67 -> V_12 ;
if ( V_67 -> V_25 & V_26 )
V_12 |= V_157 ;
if ( V_67 -> V_25 & V_158 )
V_12 |= V_159 ;
return V_12 ;
}
static int F_116 ( unsigned V_12 , unsigned short V_25 )
{
if ( V_25 & V_26 ) {
if ( V_12 > 0x3ff )
return - V_33 ;
} else {
if ( V_12 == 0x00 || V_12 > 0x7f )
return - V_33 ;
}
return 0 ;
}
static int F_117 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_33 ;
return 0 ;
}
static int F_118 ( struct V_58 * V_38 , void * V_160 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
int V_12 = * ( int * ) V_160 ;
if ( V_67 && F_115 ( V_67 ) == V_12 )
return - V_138 ;
return 0 ;
}
static int F_119 ( struct V_34 * V_35 , int V_12 )
{
struct V_34 * V_107 = F_120 ( V_35 ) ;
int V_161 ;
V_161 = F_121 ( & V_35 -> V_38 , & V_12 ,
F_118 ) ;
if ( ! V_161 && V_107 )
V_161 = F_119 ( V_107 , V_12 ) ;
return V_161 ;
}
static int F_122 ( struct V_58 * V_38 , void * V_160 )
{
int V_161 ;
if ( V_38 -> type == & V_162 )
V_161 = F_121 ( V_38 , V_160 ,
F_122 ) ;
else
V_161 = F_118 ( V_38 , V_160 ) ;
return V_161 ;
}
static int F_123 ( struct V_34 * V_35 , int V_12 )
{
struct V_34 * V_107 = F_120 ( V_35 ) ;
int V_161 = 0 ;
if ( V_107 )
V_161 = F_119 ( V_107 , V_12 ) ;
if ( ! V_161 )
V_161 = F_121 ( & V_35 -> V_38 , & V_12 ,
F_122 ) ;
return V_161 ;
}
static void F_124 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
F_125 ( & V_35 -> V_163 ) ;
}
static int F_126 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
return F_127 ( & V_35 -> V_163 ) ;
}
static void F_128 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
F_129 ( & V_35 -> V_163 ) ;
}
static void F_130 ( struct V_34 * V_52 ,
struct V_62 * V_67 )
{
struct V_27 * V_28 = F_38 ( & V_67 -> V_38 ) ;
if ( V_28 ) {
F_131 ( & V_67 -> V_38 , L_26 , F_132 ( V_28 ) ) ;
return;
}
F_131 ( & V_67 -> V_38 , L_27 , F_133 ( V_52 ) ,
F_115 ( V_67 ) ) ;
}
struct V_62 *
F_25 ( struct V_34 * V_52 , struct V_7 const * V_8 )
{
struct V_62 * V_67 ;
int V_11 ;
V_67 = F_47 ( sizeof *V_67 , V_76 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_35 = V_52 ;
V_67 -> V_38 . V_164 = V_8 -> V_164 ;
if ( V_8 -> V_165 )
V_67 -> V_38 . V_165 = * V_8 -> V_165 ;
V_67 -> V_25 = V_8 -> V_25 ;
V_67 -> V_12 = V_8 -> V_12 ;
V_67 -> V_44 = V_8 -> V_44 ;
F_21 ( V_67 -> V_112 , V_8 -> type , sizeof( V_67 -> V_112 ) ) ;
V_11 = F_116 ( V_67 -> V_12 , V_67 -> V_25 ) ;
if ( V_11 ) {
F_26 ( & V_52 -> V_38 , L_28 ,
V_67 -> V_25 & V_26 ? 10 : 7 , V_67 -> V_12 ) ;
goto V_166;
}
V_11 = F_123 ( V_52 , F_115 ( V_67 ) ) ;
if ( V_11 )
goto V_167;
V_67 -> V_38 . V_107 = & V_67 -> V_35 -> V_38 ;
V_67 -> V_38 . V_168 = & V_61 ;
V_67 -> V_38 . type = & V_155 ;
V_67 -> V_38 . V_144 = V_8 -> V_144 ;
V_67 -> V_38 . V_41 = V_8 -> V_41 ;
F_130 ( V_52 , V_67 ) ;
V_11 = F_134 ( & V_67 -> V_38 ) ;
if ( V_11 )
goto V_167;
F_94 ( & V_52 -> V_38 , L_29 ,
V_67 -> V_112 , F_22 ( & V_67 -> V_38 ) ) ;
return V_67 ;
V_167:
F_26 ( & V_52 -> V_38 ,
L_30 ,
V_67 -> V_112 , V_67 -> V_12 , V_11 ) ;
V_166:
F_50 ( V_67 ) ;
return NULL ;
}
void F_44 ( struct V_62 * V_67 )
{
if ( V_67 -> V_38 . V_144 )
F_135 ( V_67 -> V_38 . V_144 , V_169 ) ;
if ( F_38 ( & V_67 -> V_38 ) )
F_136 ( F_38 ( & V_67 -> V_38 ) ) ;
F_137 ( & V_67 -> V_38 ) ;
}
static int F_138 ( struct V_62 * V_67 ,
const struct V_110 * V_111 )
{
return 0 ;
}
static int F_139 ( struct V_62 * V_67 )
{
return 0 ;
}
struct V_62 * F_140 ( struct V_34 * V_35 , T_8 V_170 )
{
struct V_7 V_8 = {
F_141 ( L_31 , V_170 ) ,
} ;
return F_25 ( V_35 , & V_8 ) ;
}
struct V_62 * F_142 ( struct V_62 * V_67 ,
const char * V_112 ,
T_8 V_171 )
{
struct V_172 * V_173 = V_67 -> V_38 . V_144 ;
T_3 V_12 = V_171 ;
int V_132 ;
if ( V_173 ) {
V_132 = F_143 ( V_173 , L_32 , V_112 ) ;
if ( V_132 >= 0 )
F_144 ( V_173 , L_33 , V_132 , & V_12 ) ;
}
F_94 ( & V_67 -> V_35 -> V_38 , L_34 , V_112 , V_12 ) ;
return F_140 ( V_67 -> V_35 , V_12 ) ;
}
static void F_145 ( struct V_58 * V_38 )
{
struct V_34 * V_52 = F_112 ( V_38 ) ;
F_146 ( & V_52 -> V_174 ) ;
}
unsigned int F_147 ( struct V_34 * V_35 )
{
unsigned int V_175 = 0 ;
while ( ( V_35 = F_120 ( V_35 ) ) )
V_175 ++ ;
F_148 ( V_175 >= V_176 ,
L_35 ) ;
return V_175 ;
}
static T_7
F_149 ( struct V_58 * V_38 , struct V_153 * V_154 ,
const char * V_79 , T_9 V_177 )
{
struct V_34 * V_52 = F_112 ( V_38 ) ;
struct V_7 V_8 ;
struct V_62 * V_67 ;
char * V_178 , V_179 ;
int V_42 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_178 = strchr ( V_79 , ' ' ) ;
if ( ! V_178 ) {
F_26 ( V_38 , L_36 , L_37 ) ;
return - V_33 ;
}
if ( V_178 - V_79 > V_180 - 1 ) {
F_26 ( V_38 , L_38 , L_37 ) ;
return - V_33 ;
}
memcpy ( V_8 . type , V_79 , V_178 - V_79 ) ;
V_42 = sscanf ( ++ V_178 , L_39 , & V_8 . V_12 , & V_179 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_40 , L_37 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_179 != '\n' ) {
F_26 ( V_38 , L_41 , L_37 ) ;
return - V_33 ;
}
if ( ( V_8 . V_12 & V_157 ) == V_157 ) {
V_8 . V_12 &= ~ V_157 ;
V_8 . V_25 |= V_26 ;
}
if ( V_8 . V_12 & V_159 ) {
V_8 . V_12 &= ~ V_159 ;
V_8 . V_25 |= V_158 ;
}
V_67 = F_25 ( V_52 , & V_8 ) ;
if ( ! V_67 )
return - V_33 ;
F_150 ( & V_52 -> V_181 ) ;
F_151 ( & V_67 -> V_182 , & V_52 -> V_183 ) ;
F_152 ( & V_52 -> V_181 ) ;
F_153 ( V_38 , L_42 , L_37 ,
V_8 . type , V_8 . V_12 ) ;
return V_177 ;
}
static T_7
F_154 ( struct V_58 * V_38 , struct V_153 * V_154 ,
const char * V_79 , T_9 V_177 )
{
struct V_34 * V_52 = F_112 ( V_38 ) ;
struct V_62 * V_67 , * V_184 ;
unsigned short V_12 ;
char V_179 ;
int V_42 ;
V_42 = sscanf ( V_79 , L_39 , & V_12 , & V_179 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_40 , L_43 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_179 != '\n' ) {
F_26 ( V_38 , L_41 , L_43 ) ;
return - V_33 ;
}
V_42 = - V_143 ;
F_155 ( & V_52 -> V_181 ,
F_147 ( V_52 ) ) ;
F_156 (client, next, &adap->userspace_clients,
detected) {
if ( F_115 ( V_67 ) == V_12 ) {
F_153 ( V_38 , L_44 ,
L_43 , V_67 -> V_112 , V_67 -> V_12 ) ;
F_157 ( & V_67 -> V_182 ) ;
F_44 ( V_67 ) ;
V_42 = V_177 ;
break;
}
}
F_152 ( & V_52 -> V_181 ) ;
if ( V_42 < 0 )
F_26 ( V_38 , L_45 ,
L_43 ) ;
return V_42 ;
}
struct V_34 * F_36 ( struct V_58 * V_38 )
{
return ( V_38 -> type == & V_162 )
? F_112 ( V_38 )
: NULL ;
}
static void F_158 ( struct V_34 * V_35 )
{
struct V_185 * V_186 ;
F_159 ( & V_187 ) ;
F_160 (devinfo, &__i2c_board_list, list) {
if ( V_186 -> V_188 == V_35 -> V_189
&& ! F_25 ( V_35 ,
& V_186 -> V_190 ) )
F_26 ( & V_35 -> V_38 ,
L_46 ,
V_186 -> V_190 . V_12 ) ;
}
F_161 ( & V_187 ) ;
}
static struct V_62 * F_162 ( struct V_34 * V_52 ,
struct V_172 * V_191 )
{
struct V_62 * V_161 ;
struct V_7 V_8 = {} ;
struct V_192 V_193 = {} ;
const T_10 * V_194 ;
T_3 V_12 ;
int V_78 ;
F_94 ( & V_52 -> V_38 , L_47 , V_191 -> V_195 ) ;
if ( F_163 ( V_191 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_26 ( & V_52 -> V_38 , L_48 ,
V_191 -> V_195 ) ;
return F_164 ( - V_33 ) ;
}
V_194 = F_165 ( V_191 , L_33 , & V_78 ) ;
if ( ! V_194 || ( V_78 < sizeof( * V_194 ) ) ) {
F_26 ( & V_52 -> V_38 , L_49 ,
V_191 -> V_195 ) ;
return F_164 ( - V_33 ) ;
}
V_12 = F_166 ( V_194 ) ;
if ( V_12 & V_196 ) {
V_12 &= ~ V_196 ;
V_8 . V_25 |= V_26 ;
}
if ( V_12 & V_197 ) {
V_12 &= ~ V_197 ;
V_8 . V_25 |= V_158 ;
}
if ( F_116 ( V_12 , V_8 . V_25 ) ) {
F_26 ( & V_52 -> V_38 , L_50 ,
V_8 . V_12 , V_191 -> V_195 ) ;
return F_164 ( - V_33 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_144 = F_167 ( V_191 ) ;
V_8 . V_165 = & V_193 ;
if ( F_165 ( V_191 , L_51 , NULL ) )
V_8 . V_25 |= V_148 ;
V_161 = F_25 ( V_52 , & V_8 ) ;
if ( V_161 == NULL ) {
F_26 ( & V_52 -> V_38 , L_52 ,
V_191 -> V_195 ) ;
F_168 ( V_191 ) ;
return F_164 ( - V_33 ) ;
}
return V_161 ;
}
static void F_169 ( struct V_34 * V_52 )
{
struct V_172 * V_168 , * V_191 ;
struct V_62 * V_67 ;
if ( ! V_52 -> V_38 . V_144 )
return;
F_94 ( & V_52 -> V_38 , L_53 ) ;
V_168 = F_170 ( V_52 -> V_38 . V_144 , L_54 ) ;
if ( ! V_168 )
V_168 = F_167 ( V_52 -> V_38 . V_144 ) ;
F_171 (bus, node) {
if ( F_172 ( V_191 , V_169 ) )
continue;
V_67 = F_162 ( V_52 , V_191 ) ;
if ( F_173 ( V_67 ) ) {
F_32 ( & V_52 -> V_38 ,
L_55 ,
V_191 -> V_195 ) ;
F_135 ( V_191 , V_169 ) ;
}
}
F_168 ( V_168 ) ;
}
static int F_174 ( struct V_58 * V_38 , void * V_4 )
{
return V_38 -> V_144 == V_4 ;
}
struct V_62 * F_175 ( struct V_172 * V_191 )
{
struct V_58 * V_38 ;
struct V_62 * V_67 ;
V_38 = F_40 ( & V_61 , NULL , V_191 , F_174 ) ;
if ( ! V_38 )
return NULL ;
V_67 = F_42 ( V_38 ) ;
if ( ! V_67 )
F_45 ( V_38 ) ;
return V_67 ;
}
struct V_34 * F_176 ( struct V_172 * V_191 )
{
struct V_58 * V_38 ;
struct V_34 * V_35 ;
V_38 = F_40 ( & V_61 , NULL , V_191 , F_174 ) ;
if ( ! V_38 )
return NULL ;
V_35 = F_36 ( V_38 ) ;
if ( ! V_35 )
F_45 ( V_38 ) ;
return V_35 ;
}
struct V_34 * F_177 ( struct V_172 * V_191 )
{
struct V_34 * V_35 ;
V_35 = F_176 ( V_191 ) ;
if ( ! V_35 )
return NULL ;
if ( ! F_178 ( V_35 -> V_198 ) ) {
F_45 ( & V_35 -> V_38 ) ;
V_35 = NULL ;
}
return V_35 ;
}
static void F_169 ( struct V_34 * V_52 ) { }
static int F_179 ( struct V_115 * V_116 ,
struct V_34 * V_52 )
{
F_180 ( V_52 , V_116 ) ;
if ( V_116 -> V_199 ) {
F_32 ( & V_52 -> V_38 , L_56 ,
V_116 -> V_116 . V_112 ) ;
F_32 ( & V_52 -> V_38 ,
L_57 ) ;
V_116 -> V_199 ( V_52 ) ;
}
return 0 ;
}
static int F_181 ( struct V_113 * V_200 , void * V_4 )
{
return F_179 ( F_75 ( V_200 ) , V_4 ) ;
}
static int F_182 ( struct V_34 * V_52 )
{
int V_42 = - V_33 ;
if ( F_183 ( ! V_201 ) ) {
V_42 = - V_202 ;
goto V_203;
}
if ( F_184 ( ! V_52 -> V_112 [ 0 ] , L_58 ) )
goto V_203;
if ( ! V_52 -> V_204 ) {
F_185 ( L_59 , V_52 -> V_112 ) ;
goto V_203;
}
if ( ! V_52 -> V_205 )
V_52 -> V_205 = & V_206 ;
F_186 ( & V_52 -> V_163 ) ;
F_186 ( & V_52 -> V_207 ) ;
F_187 ( & V_52 -> V_181 ) ;
F_12 ( & V_52 -> V_183 ) ;
if ( V_52 -> V_208 == 0 )
V_52 -> V_208 = V_209 ;
F_131 ( & V_52 -> V_38 , L_60 , V_52 -> V_189 ) ;
V_52 -> V_38 . V_168 = & V_61 ;
V_52 -> V_38 . type = & V_162 ;
V_42 = F_134 ( & V_52 -> V_38 ) ;
if ( V_42 ) {
F_185 ( L_61 , V_52 -> V_112 , V_42 ) ;
goto V_203;
}
F_94 ( & V_52 -> V_38 , L_62 , V_52 -> V_112 ) ;
F_188 ( & V_52 -> V_38 ) ;
F_189 ( & V_52 -> V_38 , true ) ;
F_190 ( & V_52 -> V_38 ) ;
#ifdef F_191
V_42 = F_192 ( V_210 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
if ( V_42 )
F_32 ( & V_52 -> V_38 ,
L_63 ) ;
#endif
F_95 ( V_52 ) ;
F_169 ( V_52 ) ;
F_28 ( V_52 ) ;
F_63 ( V_52 ) ;
if ( V_52 -> V_189 < V_211 )
F_158 ( V_52 ) ;
F_150 ( & V_212 ) ;
F_193 ( & V_61 , NULL , V_52 , F_181 ) ;
F_152 ( & V_212 ) ;
return 0 ;
V_203:
F_150 ( & V_212 ) ;
F_194 ( & V_213 , V_52 -> V_189 ) ;
F_152 ( & V_212 ) ;
return V_42 ;
}
static int F_195 ( struct V_34 * V_52 )
{
int V_111 ;
F_150 ( & V_212 ) ;
V_111 = F_196 ( & V_213 , V_52 , V_52 -> V_189 , V_52 -> V_189 + 1 , V_76 ) ;
F_152 ( & V_212 ) ;
if ( F_184 ( V_111 < 0 , L_64 ) )
return V_111 == - V_214 ? - V_138 : V_111 ;
return F_182 ( V_52 ) ;
}
int F_197 ( struct V_34 * V_35 )
{
struct V_58 * V_38 = & V_35 -> V_38 ;
int V_111 ;
if ( V_38 -> V_144 ) {
V_111 = F_198 ( V_38 -> V_144 , L_65 ) ;
if ( V_111 >= 0 ) {
V_35 -> V_189 = V_111 ;
return F_195 ( V_35 ) ;
}
}
F_150 ( & V_212 ) ;
V_111 = F_196 ( & V_213 , V_35 ,
V_211 , 0 , V_76 ) ;
F_152 ( & V_212 ) ;
if ( F_184 ( V_111 < 0 , L_64 ) )
return V_111 ;
V_35 -> V_189 = V_111 ;
return F_182 ( V_35 ) ;
}
int F_199 ( struct V_34 * V_52 )
{
if ( V_52 -> V_189 == - 1 )
return F_197 ( V_52 ) ;
return F_195 ( V_52 ) ;
}
static void F_200 ( struct V_115 * V_116 ,
struct V_34 * V_35 )
{
struct V_62 * V_67 , * V_215 ;
F_156 (client, _n, &driver->clients, detected) {
if ( V_67 -> V_35 == V_35 ) {
F_94 ( & V_35 -> V_38 , L_66 ,
V_67 -> V_112 , V_67 -> V_12 ) ;
F_157 ( & V_67 -> V_182 ) ;
F_44 ( V_67 ) ;
}
}
}
static int F_201 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 && strcmp ( V_67 -> V_112 , L_31 ) )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_202 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_203 ( struct V_113 * V_200 , void * V_4 )
{
F_200 ( F_75 ( V_200 ) , V_4 ) ;
return 0 ;
}
void F_204 ( struct V_34 * V_52 )
{
struct V_34 * V_216 ;
struct V_62 * V_67 , * V_184 ;
F_150 ( & V_212 ) ;
V_216 = F_205 ( & V_213 , V_52 -> V_189 ) ;
F_152 ( & V_212 ) ;
if ( V_216 != V_52 ) {
F_206 ( L_67 , V_52 -> V_112 ) ;
return;
}
F_68 ( V_52 ) ;
F_150 ( & V_212 ) ;
F_193 ( & V_61 , NULL , V_52 ,
F_203 ) ;
F_152 ( & V_212 ) ;
F_155 ( & V_52 -> V_181 ,
F_147 ( V_52 ) ) ;
F_156 (client, next, &adap->userspace_clients,
detected) {
F_94 ( & V_52 -> V_38 , L_66 , V_67 -> V_112 ,
V_67 -> V_12 ) ;
F_157 ( & V_67 -> V_182 ) ;
F_44 ( V_67 ) ;
}
F_152 ( & V_52 -> V_181 ) ;
F_121 ( & V_52 -> V_38 , NULL , F_201 ) ;
F_121 ( & V_52 -> V_38 , NULL , F_202 ) ;
#ifdef F_191
F_207 ( V_210 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
#endif
F_94 ( & V_52 -> V_38 , L_68 , V_52 -> V_112 ) ;
F_208 ( & V_52 -> V_38 ) ;
F_209 ( & V_52 -> V_174 ) ;
F_137 ( & V_52 -> V_38 ) ;
F_210 ( & V_52 -> V_174 ) ;
F_150 ( & V_212 ) ;
F_194 ( & V_213 , V_52 -> V_189 ) ;
F_152 ( & V_212 ) ;
memset ( & V_52 -> V_38 , 0 , sizeof( V_52 -> V_38 ) ) ;
}
void F_211 ( struct V_58 * V_38 , struct V_217 * V_218 , bool V_219 )
{
int V_31 ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_31 = F_212 ( V_38 , L_69 , & V_218 -> V_220 ) ;
if ( V_31 && V_219 )
V_218 -> V_220 = 100000 ;
V_31 = F_212 ( V_38 , L_70 , & V_218 -> V_221 ) ;
if ( V_31 && V_219 ) {
if ( V_218 -> V_220 <= 100000 )
V_218 -> V_221 = 1000 ;
else if ( V_218 -> V_220 <= 400000 )
V_218 -> V_221 = 300 ;
else
V_218 -> V_221 = 120 ;
}
V_31 = F_212 ( V_38 , L_71 , & V_218 -> V_222 ) ;
if ( V_31 && V_219 ) {
if ( V_218 -> V_220 <= 400000 )
V_218 -> V_222 = 300 ;
else
V_218 -> V_222 = 120 ;
}
F_212 ( V_38 , L_72 , & V_218 -> V_223 ) ;
V_31 = F_212 ( V_38 , L_73 , & V_218 -> V_224 ) ;
if ( V_31 && V_219 )
V_218 -> V_224 = V_218 -> V_222 ;
}
int F_213 ( void * V_4 , int (* F_214)( struct V_58 * , void * ) )
{
int V_42 ;
F_150 ( & V_212 ) ;
V_42 = F_215 ( & V_61 , NULL , V_4 , F_214 ) ;
F_152 ( & V_212 ) ;
return V_42 ;
}
static int F_216 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type != & V_162 )
return 0 ;
return F_179 ( V_4 , F_112 ( V_38 ) ) ;
}
int F_217 ( struct V_225 * V_198 , struct V_115 * V_116 )
{
int V_42 ;
if ( F_183 ( ! V_201 ) )
return - V_202 ;
V_116 -> V_116 . V_198 = V_198 ;
V_116 -> V_116 . V_168 = & V_61 ;
F_12 ( & V_116 -> V_226 ) ;
V_42 = F_218 ( & V_116 -> V_116 ) ;
if ( V_42 )
return V_42 ;
F_206 ( L_74 , V_116 -> V_116 . V_112 ) ;
F_213 ( V_116 , F_216 ) ;
return 0 ;
}
static int F_219 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type == & V_162 )
F_200 ( V_4 , F_112 ( V_38 ) ) ;
return 0 ;
}
void F_220 ( struct V_115 * V_116 )
{
F_213 ( V_116 , F_219 ) ;
F_221 ( & V_116 -> V_116 ) ;
F_206 ( L_75 , V_116 -> V_116 . V_112 ) ;
}
struct V_62 * F_222 ( struct V_62 * V_67 )
{
if ( V_67 && F_223 ( & V_67 -> V_38 ) )
return V_67 ;
return NULL ;
}
void F_224 ( struct V_62 * V_67 )
{
if ( V_67 )
F_45 ( & V_67 -> V_38 ) ;
}
static int F_225 ( struct V_58 * V_38 , void * V_227 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_228 * V_66 = V_227 ;
struct V_115 * V_116 ;
if ( ! V_67 || ! V_67 -> V_38 . V_116 )
return 0 ;
V_116 = F_75 ( V_67 -> V_38 . V_116 ) ;
if ( V_116 -> V_82 )
V_116 -> V_82 ( V_67 , V_66 -> V_71 , V_66 -> V_66 ) ;
return 0 ;
}
void F_226 ( struct V_34 * V_52 , unsigned int V_71 , void * V_66 )
{
struct V_228 V_229 ;
V_229 . V_71 = V_71 ;
V_229 . V_66 = V_66 ;
F_121 ( & V_52 -> V_38 , & V_229 , F_225 ) ;
}
static int F_227 ( struct V_63 * V_64 , unsigned long V_92 ,
void * V_66 )
{
struct V_230 * V_231 = V_66 ;
struct V_34 * V_52 ;
struct V_62 * V_67 ;
switch ( F_228 ( V_92 , V_231 ) ) {
case V_232 :
V_52 = F_176 ( V_231 -> V_233 -> V_107 ) ;
if ( V_52 == NULL )
return V_70 ;
if ( F_172 ( V_231 -> V_233 , V_169 ) ) {
F_45 ( & V_52 -> V_38 ) ;
return V_70 ;
}
V_67 = F_162 ( V_52 , V_231 -> V_233 ) ;
F_45 ( & V_52 -> V_38 ) ;
if ( F_173 ( V_67 ) ) {
F_26 ( & V_52 -> V_38 , L_76 ,
V_231 -> V_233 -> V_195 ) ;
F_135 ( V_231 -> V_233 , V_169 ) ;
return F_229 ( F_230 ( V_67 ) ) ;
}
break;
case V_234 :
if ( ! F_231 ( V_231 -> V_233 , V_169 ) )
return V_70 ;
V_67 = F_175 ( V_231 -> V_233 ) ;
if ( V_67 == NULL )
return V_70 ;
F_44 ( V_67 ) ;
F_45 ( & V_67 -> V_38 ) ;
break;
}
return V_70 ;
}
static int T_11 F_232 ( void )
{
int V_235 ;
V_235 = F_233 ( L_65 ) ;
F_234 ( & V_187 ) ;
if ( V_235 >= V_211 )
V_211 = V_235 + 1 ;
F_235 ( & V_187 ) ;
V_235 = F_236 ( & V_61 ) ;
if ( V_235 )
return V_235 ;
V_201 = true ;
#ifdef F_191
V_210 = F_237 ( L_77 ) ;
if ( ! V_210 ) {
V_235 = - V_108 ;
goto V_236;
}
#endif
V_235 = F_238 ( & V_237 ) ;
if ( V_235 )
goto V_238;
if ( F_239 ( V_239 ) )
F_183 ( F_240 ( & V_240 ) ) ;
if ( F_239 ( V_241 ) )
F_183 ( F_241 ( & V_242 ) ) ;
return 0 ;
V_238:
#ifdef F_191
F_242 ( V_210 ) ;
V_236:
#endif
V_201 = false ;
F_243 ( & V_61 ) ;
return V_235 ;
}
static void T_12 F_244 ( void )
{
if ( F_239 ( V_241 ) )
F_183 ( F_245 ( & V_242 ) ) ;
if ( F_239 ( V_239 ) )
F_183 ( F_246 ( & V_240 ) ) ;
F_220 ( & V_237 ) ;
#ifdef F_191
F_242 ( V_210 ) ;
#endif
F_243 ( & V_61 ) ;
F_247 () ;
}
static int F_248 ( struct V_34 * V_52 , struct V_73 * V_243 , char * V_244 )
{
F_249 ( & V_52 -> V_38 , L_78 ,
V_244 , V_243 -> V_12 , V_243 -> V_78 ,
V_243 -> V_25 & V_80 ? L_79 : L_80 ) ;
return - V_140 ;
}
static int F_250 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_245 )
{
const struct V_246 * V_247 = V_52 -> V_248 ;
int V_249 = V_247 -> V_250 , V_132 ;
bool V_251 = true ;
if ( V_247 -> V_25 & V_252 ) {
V_249 = 2 ;
if ( V_245 == 2 ) {
if ( V_247 -> V_25 & V_253 && V_74 [ 0 ] . V_25 & V_80 )
return F_248 ( V_52 , & V_74 [ 0 ] , L_81 ) ;
if ( V_247 -> V_25 & V_254 && ! ( V_74 [ 1 ] . V_25 & V_80 ) )
return F_248 ( V_52 , & V_74 [ 1 ] , L_82 ) ;
if ( V_247 -> V_25 & V_255 && V_74 [ 0 ] . V_12 != V_74 [ 1 ] . V_12 )
return F_248 ( V_52 , & V_74 [ 0 ] , L_83 ) ;
if ( F_251 ( V_74 [ 0 ] . V_78 , V_247 -> V_256 ) )
return F_248 ( V_52 , & V_74 [ 0 ] , L_84 ) ;
if ( F_251 ( V_74 [ 1 ] . V_78 , V_247 -> V_257 ) )
return F_248 ( V_52 , & V_74 [ 1 ] , L_84 ) ;
V_251 = false ;
}
}
if ( F_251 ( V_245 , V_249 ) )
return F_248 ( V_52 , & V_74 [ 0 ] , L_85 ) ;
for ( V_132 = 0 ; V_132 < V_245 ; V_132 ++ ) {
T_8 V_78 = V_74 [ V_132 ] . V_78 ;
if ( V_74 [ V_132 ] . V_25 & V_80 ) {
if ( V_251 && F_251 ( V_78 , V_247 -> V_258 ) )
return F_248 ( V_52 , & V_74 [ V_132 ] , L_84 ) ;
} else {
if ( V_251 && F_251 ( V_78 , V_247 -> V_259 ) )
return F_248 ( V_52 , & V_74 [ V_132 ] , L_84 ) ;
}
}
return 0 ;
}
int F_252 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_245 )
{
unsigned long V_260 ;
int V_31 , V_261 ;
if ( V_52 -> V_248 && F_250 ( V_52 , V_74 , V_245 ) )
return - V_140 ;
if ( F_253 ( & V_1 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < V_245 ; V_132 ++ )
if ( V_74 [ V_132 ] . V_25 & V_80 )
F_254 ( V_52 , & V_74 [ V_132 ] , V_132 ) ;
else
F_255 ( V_52 , & V_74 [ V_132 ] , V_132 ) ;
}
V_260 = V_262 ;
for ( V_31 = 0 , V_261 = 0 ; V_261 <= V_52 -> V_263 ; V_261 ++ ) {
V_31 = V_52 -> V_204 -> V_264 ( V_52 , V_74 , V_245 ) ;
if ( V_31 != - V_202 )
break;
if ( F_256 ( V_262 , V_260 + V_52 -> V_208 ) )
break;
}
if ( F_253 ( & V_1 ) ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ )
if ( V_74 [ V_132 ] . V_25 & V_80 )
F_257 ( V_52 , & V_74 [ V_132 ] , V_132 ) ;
F_258 ( V_52 , V_132 , V_31 ) ;
}
return V_31 ;
}
int F_48 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_245 )
{
int V_31 ;
if ( V_52 -> V_204 -> V_264 ) {
#ifdef F_259
for ( V_31 = 0 ; V_31 < V_245 ; V_31 ++ ) {
F_94 ( & V_52 -> V_38 ,
L_86 ,
V_31 , ( V_74 [ V_31 ] . V_25 & V_80 ) ? 'R' : 'W' ,
V_74 [ V_31 ] . V_12 , V_74 [ V_31 ] . V_78 ,
( V_74 [ V_31 ] . V_25 & V_265 ) ? L_87 : L_88 ) ;
}
#endif
if ( F_260 () || F_261 () ) {
V_31 = F_262 ( V_52 , V_266 ) ;
if ( ! V_31 )
return - V_202 ;
} else {
F_263 ( V_52 , V_266 ) ;
}
V_31 = F_252 ( V_52 , V_74 , V_245 ) ;
F_264 ( V_52 , V_266 ) ;
return V_31 ;
} else {
F_94 ( & V_52 -> V_38 , L_89 ) ;
return - V_140 ;
}
}
int F_265 ( const struct V_62 * V_67 , const char * V_79 , int V_177 )
{
int V_31 ;
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_243 ;
V_243 . V_12 = V_67 -> V_12 ;
V_243 . V_25 = V_67 -> V_25 & V_267 ;
V_243 . V_78 = V_177 ;
V_243 . V_79 = ( char * ) V_79 ;
V_31 = F_48 ( V_52 , & V_243 , 1 ) ;
return ( V_31 == 1 ) ? V_177 : V_31 ;
}
int F_266 ( const struct V_62 * V_67 , char * V_79 , int V_177 )
{
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_243 ;
int V_31 ;
V_243 . V_12 = V_67 -> V_12 ;
V_243 . V_25 = V_67 -> V_25 & V_267 ;
V_243 . V_25 |= V_80 ;
V_243 . V_78 = V_177 ;
V_243 . V_79 = V_79 ;
V_31 = F_48 ( V_52 , & V_243 , 1 ) ;
return ( V_31 == 1 ) ? V_177 : V_31 ;
}
static int F_267 ( struct V_34 * V_52 , unsigned short V_12 )
{
int V_96 ;
union V_268 V_59 ;
#ifdef F_268
if ( V_12 == 0x73 && ( V_52 -> V_269 & V_270 )
&& F_269 ( V_52 , V_271 ) )
V_96 = F_270 ( V_52 , V_12 , 0 , V_272 , 0 ,
V_273 , & V_59 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_269 ( V_52 , V_274 ) )
V_96 = F_270 ( V_52 , V_12 , 0 , V_275 , 0 ,
V_276 , NULL ) ;
else if ( F_269 ( V_52 , V_277 ) )
V_96 = F_270 ( V_52 , V_12 , 0 , V_272 , 0 ,
V_278 , & V_59 ) ;
else {
F_32 ( & V_52 -> V_38 , L_90 ,
V_12 ) ;
V_96 = - V_140 ;
}
return V_96 >= 0 ;
}
static int F_271 ( struct V_62 * V_279 ,
struct V_115 * V_116 )
{
struct V_7 V_8 ;
struct V_34 * V_35 = V_279 -> V_35 ;
int V_12 = V_279 -> V_12 ;
int V_96 ;
V_96 = F_117 ( V_12 ) ;
if ( V_96 ) {
F_32 ( & V_35 -> V_38 , L_91 ,
V_12 ) ;
return V_96 ;
}
if ( F_123 ( V_35 , V_12 ) )
return 0 ;
if ( ! F_267 ( V_35 , V_12 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_12 = V_12 ;
V_96 = V_116 -> V_280 ( V_279 , & V_8 ) ;
if ( V_96 ) {
return V_96 == - V_39 ? 0 : V_96 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_26 ( & V_35 -> V_38 ,
L_92 ,
V_116 -> V_116 . V_112 , V_12 ) ;
} else {
struct V_62 * V_67 ;
if ( V_35 -> V_269 & V_281 )
F_32 ( & V_35 -> V_38 ,
L_93
L_94
L_95 ,
V_8 . V_12 ) ;
F_94 ( & V_35 -> V_38 , L_96 ,
V_8 . type , V_8 . V_12 ) ;
V_67 = F_25 ( V_35 , & V_8 ) ;
if ( V_67 )
F_151 ( & V_67 -> V_182 , & V_116 -> V_226 ) ;
else
F_26 ( & V_35 -> V_38 , L_97 ,
V_8 . type , V_8 . V_12 ) ;
}
return 0 ;
}
static int F_180 ( struct V_34 * V_35 , struct V_115 * V_116 )
{
const unsigned short * V_282 ;
struct V_62 * V_279 ;
int V_132 , V_96 = 0 ;
int V_283 = F_133 ( V_35 ) ;
V_282 = V_116 -> V_282 ;
if ( ! V_116 -> V_280 || ! V_282 )
return 0 ;
if ( V_35 -> V_269 == V_281 ) {
F_94 ( & V_35 -> V_38 ,
L_98
L_99 ,
V_116 -> V_116 . V_112 ) ;
return 0 ;
}
if ( ! ( V_35 -> V_269 & V_116 -> V_269 ) )
return 0 ;
V_279 = F_47 ( sizeof( struct V_62 ) , V_76 ) ;
if ( ! V_279 )
return - V_108 ;
V_279 -> V_35 = V_35 ;
for ( V_132 = 0 ; V_282 [ V_132 ] != V_284 ; V_132 += 1 ) {
F_94 ( & V_35 -> V_38 ,
L_100 ,
V_283 , V_282 [ V_132 ] ) ;
V_279 -> V_12 = V_282 [ V_132 ] ;
V_96 = F_271 ( V_279 , V_116 ) ;
if ( F_272 ( V_96 ) )
break;
}
F_50 ( V_279 ) ;
return V_96 ;
}
int F_273 ( struct V_34 * V_52 , unsigned short V_12 )
{
return F_270 ( V_52 , V_12 , 0 , V_272 , 0 ,
V_276 , NULL ) >= 0 ;
}
struct V_62 *
F_274 ( struct V_34 * V_52 ,
struct V_7 * V_8 ,
unsigned short const * V_285 ,
int (* V_147)( struct V_34 * , unsigned short V_12 ) )
{
int V_132 ;
if ( ! V_147 )
V_147 = F_267 ;
for ( V_132 = 0 ; V_285 [ V_132 ] != V_284 ; V_132 ++ ) {
if ( F_117 ( V_285 [ V_132 ] ) < 0 ) {
F_32 ( & V_52 -> V_38 , L_101 ,
V_285 [ V_132 ] ) ;
continue;
}
if ( F_123 ( V_52 , V_285 [ V_132 ] ) ) {
F_94 ( & V_52 -> V_38 ,
L_102 ,
V_285 [ V_132 ] ) ;
continue;
}
if ( V_147 ( V_52 , V_285 [ V_132 ] ) )
break;
}
if ( V_285 [ V_132 ] == V_284 ) {
F_94 ( & V_52 -> V_38 , L_103 ) ;
return NULL ;
}
V_8 -> V_12 = V_285 [ V_132 ] ;
return F_25 ( V_52 , V_8 ) ;
}
struct V_34 * F_275 ( int V_189 )
{
struct V_34 * V_35 ;
F_150 ( & V_212 ) ;
V_35 = F_205 ( & V_213 , V_189 ) ;
if ( ! V_35 )
goto exit;
if ( F_178 ( V_35 -> V_198 ) )
F_223 ( & V_35 -> V_38 ) ;
else
V_35 = NULL ;
exit:
F_152 ( & V_212 ) ;
return V_35 ;
}
void F_276 ( struct V_34 * V_52 )
{
if ( ! V_52 )
return;
F_45 ( & V_52 -> V_38 ) ;
F_277 ( V_52 -> V_198 ) ;
}
static T_4 F_278 ( T_8 V_4 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < 8 ; V_132 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_286 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_279 ( T_4 V_287 , T_4 * V_288 , T_9 V_177 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_177 ; V_132 ++ )
V_287 = F_278 ( ( V_287 ^ V_288 [ V_132 ] ) << 8 ) ;
return V_287 ;
}
static T_4 F_280 ( T_4 V_289 , struct V_73 * V_243 )
{
T_4 V_12 = F_281 ( V_243 ) ;
V_289 = F_279 ( V_289 , & V_12 , 1 ) ;
return F_279 ( V_289 , V_243 -> V_79 , V_243 -> V_78 ) ;
}
static inline void F_282 ( struct V_73 * V_243 )
{
V_243 -> V_79 [ V_243 -> V_78 ] = F_280 ( 0 , V_243 ) ;
V_243 -> V_78 ++ ;
}
static int F_283 ( T_4 V_290 , struct V_73 * V_243 )
{
T_4 V_291 = V_243 -> V_79 [ -- V_243 -> V_78 ] ;
V_290 = F_280 ( V_290 , V_243 ) ;
if ( V_291 != V_290 ) {
F_206 ( L_104 ,
V_291 , V_290 ) ;
return - V_292 ;
}
return 0 ;
}
T_13 F_54 ( const struct V_62 * V_67 )
{
union V_268 V_4 ;
int V_11 ;
V_11 = F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_272 , 0 ,
V_278 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_293 ;
}
T_13 F_55 ( const struct V_62 * V_67 , T_4 V_65 )
{
return F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_275 , V_65 , V_278 , NULL ) ;
}
T_13 F_56 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_268 V_4 ;
int V_11 ;
V_11 = F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_272 , V_82 ,
V_273 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_293 ;
}
T_13 F_57 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_65 )
{
union V_268 V_4 ;
V_4 . V_293 = V_65 ;
return F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_275 , V_82 ,
V_273 , & V_4 ) ;
}
T_13 F_58 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_268 V_4 ;
int V_11 ;
V_11 = F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_272 , V_82 ,
V_294 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_295 ;
}
T_13 F_59 ( const struct V_62 * V_67 , T_4 V_82 ,
T_8 V_65 )
{
union V_268 V_4 ;
V_4 . V_295 = V_65 ;
return F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_275 , V_82 ,
V_294 , & V_4 ) ;
}
T_13 F_60 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 * V_296 )
{
union V_268 V_4 ;
int V_11 ;
V_11 = F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_272 , V_82 ,
V_297 , & V_4 ) ;
if ( V_11 )
return V_11 ;
memcpy ( V_296 , & V_4 . V_298 [ 1 ] , V_4 . V_298 [ 0 ] ) ;
return V_4 . V_298 [ 0 ] ;
}
T_13 F_61 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_296 )
{
union V_268 V_4 ;
if ( V_95 > V_299 )
V_95 = V_299 ;
V_4 . V_298 [ 0 ] = V_95 ;
memcpy ( & V_4 . V_298 [ 1 ] , V_296 , V_95 ) ;
return F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_275 , V_82 ,
V_297 , & V_4 ) ;
}
T_13 F_284 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , T_4 * V_296 )
{
union V_268 V_4 ;
int V_11 ;
if ( V_95 > V_299 )
V_95 = V_299 ;
V_4 . V_298 [ 0 ] = V_95 ;
V_11 = F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_272 , V_82 ,
V_300 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_296 , & V_4 . V_298 [ 1 ] , V_4 . V_298 [ 0 ] ) ;
return V_4 . V_298 [ 0 ] ;
}
T_13 F_285 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_296 )
{
union V_268 V_4 ;
if ( V_95 > V_299 )
V_95 = V_299 ;
V_4 . V_298 [ 0 ] = V_95 ;
memcpy ( V_4 . V_298 + 1 , V_296 , V_95 ) ;
return F_270 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_275 , V_82 ,
V_300 , & V_4 ) ;
}
static T_13 F_286 ( struct V_34 * V_35 , T_8 V_12 ,
unsigned short V_25 ,
char V_301 , T_4 V_82 , int V_302 ,
union V_268 * V_4 )
{
unsigned char V_303 [ V_299 + 3 ] ;
unsigned char V_304 [ V_299 + 2 ] ;
int V_245 = V_301 == V_272 ? 2 : 1 ;
int V_132 ;
T_4 V_305 = 0 ;
int V_11 ;
struct V_73 V_243 [ 2 ] = {
{
. V_12 = V_12 ,
. V_25 = V_25 ,
. V_78 = 1 ,
. V_79 = V_303 ,
} , {
. V_12 = V_12 ,
. V_25 = V_25 | V_80 ,
. V_78 = 0 ,
. V_79 = V_304 ,
} ,
} ;
V_303 [ 0 ] = V_82 ;
switch ( V_302 ) {
case V_276 :
V_243 [ 0 ] . V_78 = 0 ;
V_243 [ 0 ] . V_25 = V_25 | ( V_301 == V_272 ?
V_80 : 0 ) ;
V_245 = 1 ;
break;
case V_278 :
if ( V_301 == V_272 ) {
V_243 [ 0 ] . V_25 = V_80 | V_25 ;
V_245 = 1 ;
}
break;
case V_273 :
if ( V_301 == V_272 )
V_243 [ 1 ] . V_78 = 1 ;
else {
V_243 [ 0 ] . V_78 = 2 ;
V_303 [ 1 ] = V_4 -> V_293 ;
}
break;
case V_294 :
if ( V_301 == V_272 )
V_243 [ 1 ] . V_78 = 2 ;
else {
V_243 [ 0 ] . V_78 = 3 ;
V_303 [ 1 ] = V_4 -> V_295 & 0xff ;
V_303 [ 2 ] = V_4 -> V_295 >> 8 ;
}
break;
case V_306 :
V_245 = 2 ;
V_301 = V_272 ;
V_243 [ 0 ] . V_78 = 3 ;
V_243 [ 1 ] . V_78 = 2 ;
V_303 [ 1 ] = V_4 -> V_295 & 0xff ;
V_303 [ 2 ] = V_4 -> V_295 >> 8 ;
break;
case V_297 :
if ( V_301 == V_272 ) {
V_243 [ 1 ] . V_25 |= V_265 ;
V_243 [ 1 ] . V_78 = 1 ;
} else {
V_243 [ 0 ] . V_78 = V_4 -> V_298 [ 0 ] + 2 ;
if ( V_243 [ 0 ] . V_78 > V_299 + 2 ) {
F_26 ( & V_35 -> V_38 ,
L_105 ,
V_4 -> V_298 [ 0 ] ) ;
return - V_33 ;
}
for ( V_132 = 1 ; V_132 < V_243 [ 0 ] . V_78 ; V_132 ++ )
V_303 [ V_132 ] = V_4 -> V_298 [ V_132 - 1 ] ;
}
break;
case V_307 :
V_245 = 2 ;
V_301 = V_272 ;
if ( V_4 -> V_298 [ 0 ] > V_299 ) {
F_26 ( & V_35 -> V_38 ,
L_105 ,
V_4 -> V_298 [ 0 ] ) ;
return - V_33 ;
}
V_243 [ 0 ] . V_78 = V_4 -> V_298 [ 0 ] + 2 ;
for ( V_132 = 1 ; V_132 < V_243 [ 0 ] . V_78 ; V_132 ++ )
V_303 [ V_132 ] = V_4 -> V_298 [ V_132 - 1 ] ;
V_243 [ 1 ] . V_25 |= V_265 ;
V_243 [ 1 ] . V_78 = 1 ;
break;
case V_300 :
if ( V_301 == V_272 ) {
V_243 [ 1 ] . V_78 = V_4 -> V_298 [ 0 ] ;
} else {
V_243 [ 0 ] . V_78 = V_4 -> V_298 [ 0 ] + 1 ;
if ( V_243 [ 0 ] . V_78 > V_299 + 1 ) {
F_26 ( & V_35 -> V_38 ,
L_105 ,
V_4 -> V_298 [ 0 ] ) ;
return - V_33 ;
}
for ( V_132 = 1 ; V_132 <= V_4 -> V_298 [ 0 ] ; V_132 ++ )
V_303 [ V_132 ] = V_4 -> V_298 [ V_132 ] ;
}
break;
default:
F_26 ( & V_35 -> V_38 , L_106 , V_302 ) ;
return - V_140 ;
}
V_132 = ( ( V_25 & V_308 ) && V_302 != V_276
&& V_302 != V_300 ) ;
if ( V_132 ) {
if ( ! ( V_243 [ 0 ] . V_25 & V_80 ) ) {
if ( V_245 == 1 )
F_282 ( & V_243 [ 0 ] ) ;
else
V_305 = F_280 ( 0 , & V_243 [ 0 ] ) ;
}
if ( V_243 [ V_245 - 1 ] . V_25 & V_80 )
V_243 [ V_245 - 1 ] . V_78 ++ ;
}
V_11 = F_48 ( V_35 , V_243 , V_245 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_132 && ( V_243 [ V_245 - 1 ] . V_25 & V_80 ) ) {
V_11 = F_283 ( V_305 , & V_243 [ V_245 - 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_301 == V_272 )
switch ( V_302 ) {
case V_278 :
V_4 -> V_293 = V_303 [ 0 ] ;
break;
case V_273 :
V_4 -> V_293 = V_304 [ 0 ] ;
break;
case V_294 :
case V_306 :
V_4 -> V_295 = V_304 [ 0 ] | ( V_304 [ 1 ] << 8 ) ;
break;
case V_300 :
for ( V_132 = 0 ; V_132 < V_4 -> V_298 [ 0 ] ; V_132 ++ )
V_4 -> V_298 [ V_132 + 1 ] = V_304 [ V_132 ] ;
break;
case V_297 :
case V_307 :
for ( V_132 = 0 ; V_132 < V_304 [ 0 ] + 1 ; V_132 ++ )
V_4 -> V_298 [ V_132 ] = V_304 [ V_132 ] ;
break;
}
return 0 ;
}
T_13 F_270 ( struct V_34 * V_35 , T_8 V_12 , unsigned short V_25 ,
char V_301 , T_4 V_82 , int V_309 ,
union V_268 * V_4 )
{
unsigned long V_260 ;
int V_261 ;
T_13 V_42 ;
F_287 ( V_35 , V_12 , V_25 , V_301 ,
V_82 , V_309 , V_4 ) ;
F_288 ( V_35 , V_12 , V_25 , V_301 ,
V_82 , V_309 ) ;
V_25 &= V_267 | V_308 | V_310 ;
if ( V_35 -> V_204 -> V_311 ) {
F_263 ( V_35 , V_266 ) ;
V_260 = V_262 ;
for ( V_42 = 0 , V_261 = 0 ; V_261 <= V_35 -> V_263 ; V_261 ++ ) {
V_42 = V_35 -> V_204 -> V_311 ( V_35 , V_12 , V_25 ,
V_301 , V_82 ,
V_309 , V_4 ) ;
if ( V_42 != - V_202 )
break;
if ( F_256 ( V_262 ,
V_260 + V_35 -> V_208 ) )
break;
}
F_264 ( V_35 , V_266 ) ;
if ( V_42 != - V_140 || ! V_35 -> V_204 -> V_264 )
goto V_312;
}
V_42 = F_286 ( V_35 , V_12 , V_25 , V_301 ,
V_82 , V_309 , V_4 ) ;
V_312:
F_289 ( V_35 , V_12 , V_25 , V_301 ,
V_82 , V_309 , V_4 ) ;
F_290 ( V_35 , V_12 , V_25 , V_301 ,
V_82 , V_309 , V_42 ) ;
return V_42 ;
}
T_13 F_291 ( const struct V_62 * V_67 ,
T_4 V_82 , T_4 V_95 , T_4 * V_296 )
{
T_4 V_132 = 0 ;
int V_11 ;
if ( V_95 > V_299 )
V_95 = V_299 ;
if ( F_269 ( V_67 -> V_35 , V_313 ) )
return F_284 ( V_67 , V_82 , V_95 , V_296 ) ;
if ( ! F_269 ( V_67 -> V_35 , V_271 ) )
return - V_140 ;
if ( F_269 ( V_67 -> V_35 , V_314 ) ) {
while ( ( V_132 + 2 ) <= V_95 ) {
V_11 = F_58 ( V_67 , V_82 + V_132 ) ;
if ( V_11 < 0 )
return V_11 ;
V_296 [ V_132 ] = V_11 & 0xff ;
V_296 [ V_132 + 1 ] = V_11 >> 8 ;
V_132 += 2 ;
}
}
while ( V_132 < V_95 ) {
V_11 = F_56 ( V_67 , V_82 + V_132 ) ;
if ( V_11 < 0 )
return V_11 ;
V_296 [ V_132 ] = V_11 ;
V_132 ++ ;
}
return V_132 ;
}
int F_292 ( struct V_62 * V_67 , T_14 V_315 )
{
int V_31 ;
if ( ! V_67 || ! V_315 ) {
F_184 ( 1 , L_107 ) ;
return - V_33 ;
}
if ( ! ( V_67 -> V_25 & V_158 ) )
F_32 ( & V_67 -> V_38 , L_108 ,
V_316 ) ;
if ( ! ( V_67 -> V_25 & V_26 ) ) {
V_31 = F_117 ( V_67 -> V_12 ) ;
if ( V_31 ) {
F_26 ( & V_67 -> V_38 , L_109 , V_316 ) ;
return V_31 ;
}
}
if ( ! V_67 -> V_35 -> V_204 -> V_317 ) {
F_26 ( & V_67 -> V_38 , L_110 , V_316 ) ;
return - V_140 ;
}
V_67 -> V_315 = V_315 ;
F_293 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_204 -> V_317 ( V_67 ) ;
F_294 ( V_67 -> V_35 ) ;
if ( V_31 ) {
V_67 -> V_315 = NULL ;
F_26 ( & V_67 -> V_38 , L_111 , V_316 , V_31 ) ;
}
return V_31 ;
}
int F_295 ( struct V_62 * V_67 )
{
int V_31 ;
if ( ! V_67 -> V_35 -> V_204 -> V_318 ) {
F_26 ( & V_67 -> V_38 , L_110 , V_316 ) ;
return - V_140 ;
}
F_293 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_204 -> V_318 ( V_67 ) ;
F_294 ( V_67 -> V_35 ) ;
if ( V_31 == 0 )
V_67 -> V_315 = NULL ;
else
F_26 ( & V_67 -> V_38 , L_111 , V_316 , V_31 ) ;
return V_31 ;
}
