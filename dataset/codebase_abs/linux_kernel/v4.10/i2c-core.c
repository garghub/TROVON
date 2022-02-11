int F_1 ( void )
{
F_2 ( & V_1 ) ;
return 0 ;
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
const struct V_110 * F_71 ( const struct V_110 * V_111 ,
const struct V_62 * V_67 )
{
if ( ! ( V_111 && V_67 ) )
return NULL ;
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
if ( F_73 ( V_114 -> V_117 , V_67 ) )
return 1 ;
if ( F_74 ( V_38 , V_114 ) )
return 1 ;
V_116 = F_75 ( V_114 ) ;
if ( F_71 ( V_116 -> V_118 , V_67 ) )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_58 * V_38 , struct V_119 * V_120 )
{
struct V_62 * V_67 = F_77 ( V_38 ) ;
int V_121 ;
V_121 = F_78 ( V_38 , V_120 ) ;
if ( V_121 != - V_39 )
return V_121 ;
return F_79 ( V_120 , L_8 , V_122 , V_67 -> V_112 ) ;
}
static int F_80 ( struct V_34 * V_52 )
{
return F_81 ( V_52 -> V_123 -> V_124 ) ;
}
static void F_82 ( struct V_34 * V_52 , int V_125 )
{
F_83 ( V_52 -> V_123 -> V_124 , V_125 ) ;
}
static int F_84 ( struct V_34 * V_52 )
{
return F_81 ( V_52 -> V_123 -> V_126 ) ;
}
static int F_85 ( struct V_34 * V_52 )
{
struct V_127 * V_128 = V_52 -> V_123 ;
struct V_58 * V_38 = & V_52 -> V_38 ;
int V_31 = 0 ;
V_31 = F_86 ( V_128 -> V_124 , V_129 |
V_130 , L_9 ) ;
if ( V_31 ) {
F_32 ( V_38 , L_10 , V_128 -> V_124 ) ;
return V_31 ;
}
if ( V_128 -> V_131 ) {
if ( F_86 ( V_128 -> V_126 , V_132 , L_11 ) ) {
F_32 ( V_38 , L_12 ,
V_128 -> V_126 ) ;
V_128 -> V_131 = NULL ;
}
}
return V_31 ;
}
static void F_87 ( struct V_34 * V_52 )
{
struct V_127 * V_128 = V_52 -> V_123 ;
if ( V_128 -> V_131 )
F_88 ( V_128 -> V_126 ) ;
F_88 ( V_128 -> V_124 ) ;
}
static int F_89 ( struct V_34 * V_52 )
{
struct V_127 * V_128 = V_52 -> V_123 ;
int V_133 = 0 , V_125 = 1 , V_31 = 0 ;
if ( V_128 -> V_134 )
V_128 -> V_134 ( V_52 ) ;
V_128 -> V_135 ( V_52 , V_125 ) ;
F_90 ( V_136 ) ;
while ( V_133 ++ < V_137 * 2 ) {
if ( V_125 ) {
if ( V_128 -> V_131 && V_128 -> V_131 ( V_52 ) )
break;
if ( ! V_128 -> V_138 ( V_52 ) ) {
F_26 ( & V_52 -> V_38 ,
L_13 ) ;
V_31 = - V_139 ;
break;
}
}
V_125 = ! V_125 ;
V_128 -> V_135 ( V_52 , V_125 ) ;
F_90 ( V_136 ) ;
}
if ( V_128 -> V_140 )
V_128 -> V_140 ( V_52 ) ;
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
if ( ! V_52 -> V_123 )
return - V_141 ;
F_94 ( & V_52 -> V_38 , L_14 ) ;
return V_52 -> V_123 -> V_142 ( V_52 ) ;
}
static void F_95 ( struct V_34 * V_52 )
{
struct V_127 * V_128 = V_52 -> V_123 ;
char * V_143 ;
if ( ! V_128 )
return;
if ( ! V_128 -> V_142 ) {
V_143 = L_15 ;
goto V_96;
}
if ( V_128 -> V_142 == F_92 ) {
if ( ! F_96 ( V_128 -> V_124 ) ) {
V_143 = L_16 ;
goto V_96;
}
if ( F_96 ( V_128 -> V_126 ) )
V_128 -> V_131 = F_84 ;
else
V_128 -> V_131 = NULL ;
V_128 -> V_138 = F_80 ;
V_128 -> V_135 = F_82 ;
} else if ( V_128 -> V_142 == F_91 ) {
if ( ! V_128 -> V_135 || ! V_128 -> V_138 ) {
V_143 = L_17 ;
goto V_96;
}
}
return;
V_96:
F_26 ( & V_52 -> V_38 , L_18 , V_143 ) ;
V_52 -> V_123 = NULL ;
}
static int F_97 ( const struct V_62 * V_67 )
{
struct V_34 * V_52 = V_67 -> V_35 ;
unsigned int V_44 ;
if ( ! V_52 -> V_144 )
return - V_145 ;
if ( V_67 -> V_25 & V_26 )
return - V_33 ;
V_44 = F_98 ( V_52 -> V_144 , V_67 -> V_12 ) ;
if ( ! V_44 )
V_44 = F_99 ( V_52 -> V_144 ,
V_67 -> V_12 ) ;
return V_44 > 0 ? V_44 : - V_145 ;
}
static int F_100 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
int V_11 ;
if ( ! V_67 )
return 0 ;
if ( ! V_67 -> V_44 ) {
int V_44 = - V_146 ;
if ( V_67 -> V_25 & V_147 ) {
F_94 ( V_38 , L_19 ) ;
V_44 = F_97 ( V_67 ) ;
} else if ( V_38 -> V_148 ) {
V_44 = F_101 ( V_38 -> V_148 , L_20 ) ;
if ( V_44 == - V_33 || V_44 == - V_149 )
V_44 = F_102 ( V_38 -> V_148 , 0 ) ;
} else if ( F_38 ( V_38 ) ) {
V_44 = F_103 ( F_38 ( V_38 ) , 0 ) ;
}
if ( V_44 == - V_150 )
return V_44 ;
if ( V_44 < 0 )
V_44 = 0 ;
V_67 -> V_44 = V_44 ;
}
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( ! V_116 -> V_118 &&
! F_73 ( V_38 -> V_116 -> V_117 , V_67 ) )
return - V_39 ;
if ( V_67 -> V_25 & V_151 ) {
int V_152 = - V_146 ;
if ( V_38 -> V_148 ) {
V_152 = F_101 ( V_38 -> V_148 , L_21 ) ;
if ( V_152 == - V_150 )
return V_152 ;
}
F_104 ( & V_67 -> V_38 , true ) ;
if ( V_152 > 0 && V_152 != V_67 -> V_44 )
V_11 = F_105 ( V_38 , V_152 ) ;
else if ( V_67 -> V_44 > 0 )
V_11 = F_106 ( V_38 , V_67 -> V_44 ) ;
else
V_11 = 0 ;
if ( V_11 )
F_32 ( & V_67 -> V_38 , L_22 ) ;
}
F_94 ( V_38 , L_23 ) ;
V_11 = F_107 ( V_38 -> V_148 , false ) ;
if ( V_11 < 0 )
goto V_153;
V_11 = F_108 ( & V_67 -> V_38 , true ) ;
if ( V_11 == - V_150 )
goto V_153;
if ( V_116 -> V_154 )
V_11 = V_116 -> V_154 ( V_67 ) ;
else if ( V_116 -> V_155 )
V_11 = V_116 -> V_155 ( V_67 ,
F_71 ( V_116 -> V_118 , V_67 ) ) ;
else
V_11 = - V_33 ;
if ( V_11 )
goto V_156;
return 0 ;
V_156:
F_109 ( & V_67 -> V_38 , true ) ;
V_153:
F_110 ( & V_67 -> V_38 ) ;
F_104 ( & V_67 -> V_38 , false ) ;
return V_11 ;
}
static int F_111 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
int V_11 = 0 ;
if ( ! V_67 || ! V_38 -> V_116 )
return 0 ;
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( V_116 -> remove ) {
F_94 ( V_38 , L_24 ) ;
V_11 = V_116 -> remove ( V_67 ) ;
}
F_109 ( & V_67 -> V_38 , true ) ;
F_110 ( & V_67 -> V_38 ) ;
F_104 ( & V_67 -> V_38 , false ) ;
return V_11 ;
}
static void F_112 ( struct V_58 * V_38 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_115 * V_116 ;
if ( ! V_67 || ! V_38 -> V_116 )
return;
V_116 = F_75 ( V_38 -> V_116 ) ;
if ( V_116 -> V_157 )
V_116 -> V_157 ( V_67 ) ;
}
static void F_113 ( struct V_58 * V_38 )
{
F_50 ( F_77 ( V_38 ) ) ;
}
static T_7
F_114 ( struct V_58 * V_38 , struct V_158 * V_159 , char * V_79 )
{
return sprintf ( V_79 , L_25 , V_38 -> type == & V_160 ?
F_77 ( V_38 ) -> V_112 : F_115 ( V_38 ) -> V_112 ) ;
}
static T_7
F_116 ( struct V_58 * V_38 , struct V_158 * V_159 , char * V_79 )
{
struct V_62 * V_67 = F_77 ( V_38 ) ;
int V_78 ;
V_78 = F_117 ( V_38 , V_79 , V_161 - 1 ) ;
if ( V_78 != - V_39 )
return V_78 ;
return sprintf ( V_79 , L_26 , V_122 , V_67 -> V_112 ) ;
}
struct V_62 * F_42 ( struct V_58 * V_38 )
{
return ( V_38 -> type == & V_160 )
? F_77 ( V_38 )
: NULL ;
}
static unsigned short F_118 ( struct V_62 * V_67 )
{
unsigned short V_12 = V_67 -> V_12 ;
if ( V_67 -> V_25 & V_26 )
V_12 |= V_162 ;
if ( V_67 -> V_25 & V_163 )
V_12 |= V_164 ;
return V_12 ;
}
static int F_119 ( unsigned V_12 , unsigned short V_25 )
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
static int F_120 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_33 ;
return 0 ;
}
static int F_121 ( struct V_58 * V_38 , void * V_165 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
int V_12 = * ( int * ) V_165 ;
if ( V_67 && F_118 ( V_67 ) == V_12 )
return - V_139 ;
return 0 ;
}
static int F_122 ( struct V_34 * V_35 , int V_12 )
{
struct V_34 * V_107 = F_123 ( V_35 ) ;
int V_166 ;
V_166 = F_124 ( & V_35 -> V_38 , & V_12 ,
F_121 ) ;
if ( ! V_166 && V_107 )
V_166 = F_122 ( V_107 , V_12 ) ;
return V_166 ;
}
static int F_125 ( struct V_58 * V_38 , void * V_165 )
{
int V_166 ;
if ( V_38 -> type == & V_167 )
V_166 = F_124 ( V_38 , V_165 ,
F_125 ) ;
else
V_166 = F_121 ( V_38 , V_165 ) ;
return V_166 ;
}
static int F_126 ( struct V_34 * V_35 , int V_12 )
{
struct V_34 * V_107 = F_123 ( V_35 ) ;
int V_166 = 0 ;
if ( V_107 )
V_166 = F_122 ( V_107 , V_12 ) ;
if ( ! V_166 )
V_166 = F_124 ( & V_35 -> V_38 , & V_12 ,
F_125 ) ;
return V_166 ;
}
static void F_127 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
F_128 ( & V_35 -> V_168 ) ;
}
static int F_129 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
return F_130 ( & V_35 -> V_168 ) ;
}
static void F_131 ( struct V_34 * V_35 ,
unsigned int V_25 )
{
F_132 ( & V_35 -> V_168 ) ;
}
static void F_133 ( struct V_34 * V_52 ,
struct V_62 * V_67 )
{
struct V_27 * V_28 = F_38 ( & V_67 -> V_38 ) ;
if ( V_28 ) {
F_134 ( & V_67 -> V_38 , L_27 , F_135 ( V_28 ) ) ;
return;
}
F_134 ( & V_67 -> V_38 , L_28 , F_136 ( V_52 ) ,
F_118 ( V_67 ) ) ;
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
V_67 -> V_38 . V_169 = V_8 -> V_169 ;
if ( V_8 -> V_170 )
V_67 -> V_38 . V_170 = * V_8 -> V_170 ;
V_67 -> V_25 = V_8 -> V_25 ;
V_67 -> V_12 = V_8 -> V_12 ;
V_67 -> V_44 = V_8 -> V_44 ;
F_21 ( V_67 -> V_112 , V_8 -> type , sizeof( V_67 -> V_112 ) ) ;
V_11 = F_119 ( V_67 -> V_12 , V_67 -> V_25 ) ;
if ( V_11 ) {
F_26 ( & V_52 -> V_38 , L_29 ,
V_67 -> V_25 & V_26 ? 10 : 7 , V_67 -> V_12 ) ;
goto V_171;
}
V_11 = F_126 ( V_52 , F_118 ( V_67 ) ) ;
if ( V_11 )
goto V_172;
V_67 -> V_38 . V_107 = & V_67 -> V_35 -> V_38 ;
V_67 -> V_38 . V_173 = & V_61 ;
V_67 -> V_38 . type = & V_160 ;
V_67 -> V_38 . V_148 = V_8 -> V_148 ;
V_67 -> V_38 . V_41 = V_8 -> V_41 ;
F_133 ( V_52 , V_67 ) ;
V_11 = F_137 ( & V_67 -> V_38 ) ;
if ( V_11 )
goto V_172;
F_94 ( & V_52 -> V_38 , L_30 ,
V_67 -> V_112 , F_22 ( & V_67 -> V_38 ) ) ;
return V_67 ;
V_172:
F_26 ( & V_52 -> V_38 ,
L_31 ,
V_67 -> V_112 , V_67 -> V_12 , V_11 ) ;
V_171:
F_50 ( V_67 ) ;
return NULL ;
}
void F_44 ( struct V_62 * V_67 )
{
if ( V_67 -> V_38 . V_148 )
F_138 ( V_67 -> V_38 . V_148 , V_174 ) ;
if ( F_38 ( & V_67 -> V_38 ) )
F_139 ( F_38 ( & V_67 -> V_38 ) ) ;
F_140 ( & V_67 -> V_38 ) ;
}
static int F_141 ( struct V_62 * V_67 ,
const struct V_110 * V_111 )
{
return 0 ;
}
static int F_142 ( struct V_62 * V_67 )
{
return 0 ;
}
struct V_62 * F_143 ( struct V_34 * V_35 , T_8 V_175 )
{
struct V_7 V_8 = {
F_144 ( L_32 , V_175 ) ,
} ;
return F_25 ( V_35 , & V_8 ) ;
}
struct V_62 * F_145 ( struct V_62 * V_67 ,
const char * V_112 ,
T_8 V_176 )
{
struct V_177 * V_178 = V_67 -> V_38 . V_148 ;
T_3 V_12 = V_176 ;
int V_133 ;
if ( V_178 ) {
V_133 = F_146 ( V_178 , L_33 , V_112 ) ;
if ( V_133 >= 0 )
F_147 ( V_178 , L_34 , V_133 , & V_12 ) ;
}
F_94 ( & V_67 -> V_35 -> V_38 , L_35 , V_112 , V_12 ) ;
return F_143 ( V_67 -> V_35 , V_12 ) ;
}
static void F_148 ( struct V_58 * V_38 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
F_149 ( & V_52 -> V_179 ) ;
}
unsigned int F_150 ( struct V_34 * V_35 )
{
unsigned int V_180 = 0 ;
while ( ( V_35 = F_123 ( V_35 ) ) )
V_180 ++ ;
F_151 ( V_180 >= V_181 ,
L_36 ) ;
return V_180 ;
}
static T_7
F_152 ( struct V_58 * V_38 , struct V_158 * V_159 ,
const char * V_79 , T_9 V_182 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
struct V_7 V_8 ;
struct V_62 * V_67 ;
char * V_183 , V_184 ;
int V_42 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_183 = strchr ( V_79 , ' ' ) ;
if ( ! V_183 ) {
F_26 ( V_38 , L_37 , L_38 ) ;
return - V_33 ;
}
if ( V_183 - V_79 > V_185 - 1 ) {
F_26 ( V_38 , L_39 , L_38 ) ;
return - V_33 ;
}
memcpy ( V_8 . type , V_79 , V_183 - V_79 ) ;
V_42 = sscanf ( ++ V_183 , L_40 , & V_8 . V_12 , & V_184 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_41 , L_38 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_184 != '\n' ) {
F_26 ( V_38 , L_42 , L_38 ) ;
return - V_33 ;
}
if ( ( V_8 . V_12 & V_162 ) == V_162 ) {
V_8 . V_12 &= ~ V_162 ;
V_8 . V_25 |= V_26 ;
}
if ( V_8 . V_12 & V_164 ) {
V_8 . V_12 &= ~ V_164 ;
V_8 . V_25 |= V_163 ;
}
V_67 = F_25 ( V_52 , & V_8 ) ;
if ( ! V_67 )
return - V_33 ;
F_153 ( & V_52 -> V_186 ) ;
F_154 ( & V_67 -> V_187 , & V_52 -> V_188 ) ;
F_155 ( & V_52 -> V_186 ) ;
F_156 ( V_38 , L_43 , L_38 ,
V_8 . type , V_8 . V_12 ) ;
return V_182 ;
}
static T_7
F_157 ( struct V_58 * V_38 , struct V_158 * V_159 ,
const char * V_79 , T_9 V_182 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
struct V_62 * V_67 , * V_189 ;
unsigned short V_12 ;
char V_184 ;
int V_42 ;
V_42 = sscanf ( V_79 , L_40 , & V_12 , & V_184 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_41 , L_44 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_184 != '\n' ) {
F_26 ( V_38 , L_42 , L_44 ) ;
return - V_33 ;
}
V_42 = - V_146 ;
F_158 ( & V_52 -> V_186 ,
F_150 ( V_52 ) ) ;
F_159 (client, next, &adap->userspace_clients,
detected) {
if ( F_118 ( V_67 ) == V_12 ) {
F_156 ( V_38 , L_45 ,
L_44 , V_67 -> V_112 , V_67 -> V_12 ) ;
F_160 ( & V_67 -> V_187 ) ;
F_44 ( V_67 ) ;
V_42 = V_182 ;
break;
}
}
F_155 ( & V_52 -> V_186 ) ;
if ( V_42 < 0 )
F_26 ( V_38 , L_46 ,
L_44 ) ;
return V_42 ;
}
struct V_34 * F_36 ( struct V_58 * V_38 )
{
return ( V_38 -> type == & V_167 )
? F_115 ( V_38 )
: NULL ;
}
static void F_161 ( struct V_34 * V_35 )
{
struct V_190 * V_191 ;
F_162 ( & V_192 ) ;
F_163 (devinfo, &__i2c_board_list, list) {
if ( V_191 -> V_193 == V_35 -> V_194
&& ! F_25 ( V_35 ,
& V_191 -> V_195 ) )
F_26 ( & V_35 -> V_38 ,
L_47 ,
V_191 -> V_195 . V_12 ) ;
}
F_164 ( & V_192 ) ;
}
static struct V_62 * F_165 ( struct V_34 * V_52 ,
struct V_177 * V_196 )
{
struct V_62 * V_166 ;
struct V_7 V_8 = {} ;
struct V_197 V_198 = {} ;
const T_10 * V_199 ;
T_3 V_12 ;
int V_78 ;
F_94 ( & V_52 -> V_38 , L_48 , V_196 -> V_200 ) ;
if ( F_166 ( V_196 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_26 ( & V_52 -> V_38 , L_49 ,
V_196 -> V_200 ) ;
return F_167 ( - V_33 ) ;
}
V_199 = F_168 ( V_196 , L_34 , & V_78 ) ;
if ( ! V_199 || ( V_78 < sizeof( * V_199 ) ) ) {
F_26 ( & V_52 -> V_38 , L_50 ,
V_196 -> V_200 ) ;
return F_167 ( - V_33 ) ;
}
V_12 = F_169 ( V_199 ) ;
if ( V_12 & V_201 ) {
V_12 &= ~ V_201 ;
V_8 . V_25 |= V_26 ;
}
if ( V_12 & V_202 ) {
V_12 &= ~ V_202 ;
V_8 . V_25 |= V_163 ;
}
if ( F_119 ( V_12 , V_8 . V_25 ) ) {
F_26 ( & V_52 -> V_38 , L_51 ,
V_12 , V_196 -> V_200 ) ;
return F_167 ( - V_33 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_148 = F_170 ( V_196 ) ;
V_8 . V_170 = & V_198 ;
if ( F_171 ( V_196 , L_52 ) )
V_8 . V_25 |= V_147 ;
if ( F_168 ( V_196 , L_53 , NULL ) )
V_8 . V_25 |= V_151 ;
V_166 = F_25 ( V_52 , & V_8 ) ;
if ( V_166 == NULL ) {
F_26 ( & V_52 -> V_38 , L_54 ,
V_196 -> V_200 ) ;
F_172 ( V_196 ) ;
return F_167 ( - V_33 ) ;
}
return V_166 ;
}
static void F_173 ( struct V_34 * V_52 )
{
struct V_177 * V_173 , * V_196 ;
struct V_62 * V_67 ;
if ( ! V_52 -> V_38 . V_148 )
return;
F_94 ( & V_52 -> V_38 , L_55 ) ;
V_173 = F_174 ( V_52 -> V_38 . V_148 , L_56 ) ;
if ( ! V_173 )
V_173 = F_170 ( V_52 -> V_38 . V_148 ) ;
F_175 (bus, node) {
if ( F_176 ( V_196 , V_174 ) )
continue;
V_67 = F_165 ( V_52 , V_196 ) ;
if ( F_177 ( V_67 ) ) {
F_32 ( & V_52 -> V_38 ,
L_57 ,
V_196 -> V_200 ) ;
F_138 ( V_196 , V_174 ) ;
}
}
F_172 ( V_173 ) ;
}
static int F_178 ( struct V_58 * V_38 , void * V_4 )
{
return V_38 -> V_148 == V_4 ;
}
struct V_62 * F_179 ( struct V_177 * V_196 )
{
struct V_58 * V_38 ;
struct V_62 * V_67 ;
V_38 = F_40 ( & V_61 , NULL , V_196 , F_178 ) ;
if ( ! V_38 )
return NULL ;
V_67 = F_42 ( V_38 ) ;
if ( ! V_67 )
F_45 ( V_38 ) ;
return V_67 ;
}
struct V_34 * F_180 ( struct V_177 * V_196 )
{
struct V_58 * V_38 ;
struct V_34 * V_35 ;
V_38 = F_40 ( & V_61 , NULL , V_196 , F_178 ) ;
if ( ! V_38 )
return NULL ;
V_35 = F_36 ( V_38 ) ;
if ( ! V_35 )
F_45 ( V_38 ) ;
return V_35 ;
}
struct V_34 * F_181 ( struct V_177 * V_196 )
{
struct V_34 * V_35 ;
V_35 = F_180 ( V_196 ) ;
if ( ! V_35 )
return NULL ;
if ( ! F_182 ( V_35 -> V_203 ) ) {
F_45 ( & V_35 -> V_38 ) ;
V_35 = NULL ;
}
return V_35 ;
}
static const struct V_204 *
F_183 ( const struct V_204 * V_205 ,
struct V_62 * V_67 )
{
const char * V_112 ;
for (; V_205 -> V_206 [ 0 ] ; V_205 ++ ) {
if ( F_184 ( V_67 -> V_112 , V_205 -> V_206 ) )
return V_205 ;
V_112 = strchr ( V_205 -> V_206 , ',' ) ;
if ( ! V_112 )
V_112 = V_205 -> V_206 ;
else
V_112 ++ ;
if ( F_184 ( V_67 -> V_112 , V_112 ) )
return V_205 ;
}
return NULL ;
}
const struct V_204
* F_73 ( const struct V_204 * V_205 ,
struct V_62 * V_67 )
{
const struct V_204 * V_207 ;
if ( ! ( V_67 && V_205 ) )
return NULL ;
V_207 = F_185 ( V_205 , & V_67 -> V_38 ) ;
if ( V_207 )
return V_207 ;
return F_183 ( V_205 , V_67 ) ;
}
static void F_173 ( struct V_34 * V_52 ) { }
static int F_186 ( struct V_115 * V_116 ,
struct V_34 * V_52 )
{
F_187 ( V_52 , V_116 ) ;
if ( V_116 -> V_208 ) {
F_32 ( & V_52 -> V_38 , L_58 ,
V_116 -> V_116 . V_112 ) ;
F_32 ( & V_52 -> V_38 ,
L_59 ) ;
V_116 -> V_208 ( V_52 ) ;
}
return 0 ;
}
static int F_188 ( struct V_113 * V_209 , void * V_4 )
{
return F_186 ( F_75 ( V_209 ) , V_4 ) ;
}
static void F_189 ( struct V_34 * V_52 )
{
struct V_210 * V_211 = V_52 -> V_144 ;
T_11 V_212 ;
if ( ! V_211 )
return;
for ( V_212 = 0 ; V_212 < V_213 ; V_212 ++ )
F_190 ( F_98 ( V_211 , V_212 ) ) ;
F_191 ( V_211 ) ;
V_52 -> V_144 = NULL ;
}
static int F_192 ( struct V_210 * V_214 ,
unsigned int V_215 ,
T_11 V_216 )
{
F_193 ( V_215 , & V_217 , V_218 ) ;
return 0 ;
}
static int F_194 ( struct V_34 * V_52 )
{
struct V_210 * V_211 ;
if ( ! F_195 ( V_52 , V_219 ) )
return 0 ;
V_211 = F_196 ( V_52 -> V_38 . V_41 ,
V_213 ,
& V_220 , V_52 ) ;
if ( ! V_211 )
return - V_108 ;
V_52 -> V_144 = V_211 ;
return 0 ;
}
int F_197 ( struct V_34 * V_52 , unsigned short V_12 )
{
int V_44 ;
if ( ! V_52 )
return - V_33 ;
V_44 = F_98 ( V_52 -> V_144 , V_12 ) ;
if ( V_44 <= 0 )
return - V_145 ;
F_198 ( V_44 ) ;
return 0 ;
}
static int F_199 ( struct V_34 * V_52 )
{
int V_42 = - V_33 ;
if ( F_200 ( ! V_221 ) ) {
V_42 = - V_222 ;
goto V_223;
}
if ( F_201 ( ! V_52 -> V_112 [ 0 ] , L_60 ) )
goto V_223;
if ( ! V_52 -> V_224 ) {
F_202 ( L_61 , V_52 -> V_112 ) ;
goto V_223;
}
if ( ! V_52 -> V_225 )
V_52 -> V_225 = & V_226 ;
F_203 ( & V_52 -> V_168 ) ;
F_203 ( & V_52 -> V_227 ) ;
F_204 ( & V_52 -> V_186 ) ;
F_12 ( & V_52 -> V_188 ) ;
if ( V_52 -> V_228 == 0 )
V_52 -> V_228 = V_229 ;
V_42 = F_194 ( V_52 ) ;
if ( V_42 ) {
F_202 ( L_62 ,
V_52 -> V_112 , V_42 ) ;
goto V_223;
}
F_134 ( & V_52 -> V_38 , L_63 , V_52 -> V_194 ) ;
V_52 -> V_38 . V_173 = & V_61 ;
V_52 -> V_38 . type = & V_167 ;
V_42 = F_137 ( & V_52 -> V_38 ) ;
if ( V_42 ) {
F_202 ( L_64 , V_52 -> V_112 , V_42 ) ;
goto V_223;
}
F_94 ( & V_52 -> V_38 , L_65 , V_52 -> V_112 ) ;
F_205 ( & V_52 -> V_38 ) ;
F_206 ( & V_52 -> V_38 , true ) ;
F_207 ( & V_52 -> V_38 ) ;
#ifdef F_208
V_42 = F_209 ( V_230 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
if ( V_42 )
F_32 ( & V_52 -> V_38 ,
L_66 ) ;
#endif
F_95 ( V_52 ) ;
F_173 ( V_52 ) ;
F_28 ( V_52 ) ;
F_63 ( V_52 ) ;
if ( V_52 -> V_194 < V_231 )
F_161 ( V_52 ) ;
F_153 ( & V_232 ) ;
F_210 ( & V_61 , NULL , V_52 , F_188 ) ;
F_155 ( & V_232 ) ;
return 0 ;
V_223:
F_153 ( & V_232 ) ;
F_211 ( & V_233 , V_52 -> V_194 ) ;
F_155 ( & V_232 ) ;
return V_42 ;
}
static int F_212 ( struct V_34 * V_52 )
{
int V_111 ;
F_153 ( & V_232 ) ;
V_111 = F_213 ( & V_233 , V_52 , V_52 -> V_194 , V_52 -> V_194 + 1 , V_76 ) ;
F_155 ( & V_232 ) ;
if ( F_201 ( V_111 < 0 , L_67 ) )
return V_111 == - V_234 ? - V_139 : V_111 ;
return F_199 ( V_52 ) ;
}
int F_214 ( struct V_34 * V_35 )
{
struct V_58 * V_38 = & V_35 -> V_38 ;
int V_111 ;
if ( V_38 -> V_148 ) {
V_111 = F_215 ( V_38 -> V_148 , L_68 ) ;
if ( V_111 >= 0 ) {
V_35 -> V_194 = V_111 ;
return F_212 ( V_35 ) ;
}
}
F_153 ( & V_232 ) ;
V_111 = F_213 ( & V_233 , V_35 ,
V_231 , 0 , V_76 ) ;
F_155 ( & V_232 ) ;
if ( F_201 ( V_111 < 0 , L_67 ) )
return V_111 ;
V_35 -> V_194 = V_111 ;
return F_199 ( V_35 ) ;
}
int F_216 ( struct V_34 * V_52 )
{
if ( V_52 -> V_194 == - 1 )
return F_214 ( V_52 ) ;
return F_212 ( V_52 ) ;
}
static void F_217 ( struct V_115 * V_116 ,
struct V_34 * V_35 )
{
struct V_62 * V_67 , * V_235 ;
F_159 (client, _n, &driver->clients, detected) {
if ( V_67 -> V_35 == V_35 ) {
F_94 ( & V_35 -> V_38 , L_69 ,
V_67 -> V_112 , V_67 -> V_12 ) ;
F_160 ( & V_67 -> V_187 ) ;
F_44 ( V_67 ) ;
}
}
}
static int F_218 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 && strcmp ( V_67 -> V_112 , L_32 ) )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_219 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_220 ( struct V_113 * V_209 , void * V_4 )
{
F_217 ( F_75 ( V_209 ) , V_4 ) ;
return 0 ;
}
void F_221 ( struct V_34 * V_52 )
{
struct V_34 * V_236 ;
struct V_62 * V_67 , * V_189 ;
F_153 ( & V_232 ) ;
V_236 = F_222 ( & V_233 , V_52 -> V_194 ) ;
F_155 ( & V_232 ) ;
if ( V_236 != V_52 ) {
F_223 ( L_70 , V_52 -> V_112 ) ;
return;
}
F_68 ( V_52 ) ;
F_153 ( & V_232 ) ;
F_210 ( & V_61 , NULL , V_52 ,
F_220 ) ;
F_155 ( & V_232 ) ;
F_158 ( & V_52 -> V_186 ,
F_150 ( V_52 ) ) ;
F_159 (client, next, &adap->userspace_clients,
detected) {
F_94 ( & V_52 -> V_38 , L_69 , V_67 -> V_112 ,
V_67 -> V_12 ) ;
F_160 ( & V_67 -> V_187 ) ;
F_44 ( V_67 ) ;
}
F_155 ( & V_52 -> V_186 ) ;
F_124 ( & V_52 -> V_38 , NULL , F_218 ) ;
F_124 ( & V_52 -> V_38 , NULL , F_219 ) ;
#ifdef F_208
F_224 ( V_230 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
#endif
F_94 ( & V_52 -> V_38 , L_71 , V_52 -> V_112 ) ;
F_225 ( & V_52 -> V_38 ) ;
F_189 ( V_52 ) ;
F_226 ( & V_52 -> V_179 ) ;
F_140 ( & V_52 -> V_38 ) ;
F_227 ( & V_52 -> V_179 ) ;
F_153 ( & V_232 ) ;
F_211 ( & V_233 , V_52 -> V_194 ) ;
F_155 ( & V_232 ) ;
memset ( & V_52 -> V_38 , 0 , sizeof( V_52 -> V_38 ) ) ;
}
void F_228 ( struct V_58 * V_38 , struct V_237 * V_238 , bool V_239 )
{
int V_31 ;
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
V_31 = F_229 ( V_38 , L_72 , & V_238 -> V_240 ) ;
if ( V_31 && V_239 )
V_238 -> V_240 = 100000 ;
V_31 = F_229 ( V_38 , L_73 , & V_238 -> V_241 ) ;
if ( V_31 && V_239 ) {
if ( V_238 -> V_240 <= 100000 )
V_238 -> V_241 = 1000 ;
else if ( V_238 -> V_240 <= 400000 )
V_238 -> V_241 = 300 ;
else
V_238 -> V_241 = 120 ;
}
V_31 = F_229 ( V_38 , L_74 , & V_238 -> V_242 ) ;
if ( V_31 && V_239 ) {
if ( V_238 -> V_240 <= 400000 )
V_238 -> V_242 = 300 ;
else
V_238 -> V_242 = 120 ;
}
F_229 ( V_38 , L_75 , & V_238 -> V_243 ) ;
V_31 = F_229 ( V_38 , L_76 , & V_238 -> V_244 ) ;
if ( V_31 && V_239 )
V_238 -> V_244 = V_238 -> V_242 ;
}
int F_230 ( void * V_4 , int (* F_231)( struct V_58 * , void * ) )
{
int V_42 ;
F_153 ( & V_232 ) ;
V_42 = F_232 ( & V_61 , NULL , V_4 , F_231 ) ;
F_155 ( & V_232 ) ;
return V_42 ;
}
static int F_233 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type != & V_167 )
return 0 ;
return F_186 ( V_4 , F_115 ( V_38 ) ) ;
}
int F_234 ( struct V_245 * V_203 , struct V_115 * V_116 )
{
int V_42 ;
if ( F_200 ( ! V_221 ) )
return - V_222 ;
V_116 -> V_116 . V_203 = V_203 ;
V_116 -> V_116 . V_173 = & V_61 ;
F_12 ( & V_116 -> V_246 ) ;
V_42 = F_235 ( & V_116 -> V_116 ) ;
if ( V_42 )
return V_42 ;
F_223 ( L_77 , V_116 -> V_116 . V_112 ) ;
F_230 ( V_116 , F_233 ) ;
return 0 ;
}
static int F_236 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type == & V_167 )
F_217 ( V_4 , F_115 ( V_38 ) ) ;
return 0 ;
}
void F_237 ( struct V_115 * V_116 )
{
F_230 ( V_116 , F_236 ) ;
F_238 ( & V_116 -> V_116 ) ;
F_223 ( L_78 , V_116 -> V_116 . V_112 ) ;
}
struct V_62 * F_239 ( struct V_62 * V_67 )
{
if ( V_67 && F_240 ( & V_67 -> V_38 ) )
return V_67 ;
return NULL ;
}
void F_241 ( struct V_62 * V_67 )
{
if ( V_67 )
F_45 ( & V_67 -> V_38 ) ;
}
static int F_242 ( struct V_58 * V_38 , void * V_247 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_248 * V_66 = V_247 ;
struct V_115 * V_116 ;
if ( ! V_67 || ! V_67 -> V_38 . V_116 )
return 0 ;
V_116 = F_75 ( V_67 -> V_38 . V_116 ) ;
if ( V_116 -> V_82 )
V_116 -> V_82 ( V_67 , V_66 -> V_71 , V_66 -> V_66 ) ;
return 0 ;
}
void F_243 ( struct V_34 * V_52 , unsigned int V_71 , void * V_66 )
{
struct V_248 V_249 ;
V_249 . V_71 = V_71 ;
V_249 . V_66 = V_66 ;
F_124 ( & V_52 -> V_38 , & V_249 , F_242 ) ;
}
static int F_244 ( struct V_63 * V_64 , unsigned long V_92 ,
void * V_66 )
{
struct V_250 * V_251 = V_66 ;
struct V_34 * V_52 ;
struct V_62 * V_67 ;
switch ( F_245 ( V_92 , V_251 ) ) {
case V_252 :
V_52 = F_180 ( V_251 -> V_253 -> V_107 ) ;
if ( V_52 == NULL )
return V_70 ;
if ( F_176 ( V_251 -> V_253 , V_174 ) ) {
F_45 ( & V_52 -> V_38 ) ;
return V_70 ;
}
V_67 = F_165 ( V_52 , V_251 -> V_253 ) ;
F_45 ( & V_52 -> V_38 ) ;
if ( F_177 ( V_67 ) ) {
F_26 ( & V_52 -> V_38 , L_79 ,
V_251 -> V_253 -> V_200 ) ;
F_138 ( V_251 -> V_253 , V_174 ) ;
return F_246 ( F_247 ( V_67 ) ) ;
}
break;
case V_254 :
if ( ! F_248 ( V_251 -> V_253 , V_174 ) )
return V_70 ;
V_67 = F_179 ( V_251 -> V_253 ) ;
if ( V_67 == NULL )
return V_70 ;
F_44 ( V_67 ) ;
F_45 ( & V_67 -> V_38 ) ;
break;
}
return V_70 ;
}
static int T_12 F_249 ( void )
{
int V_255 ;
V_255 = F_250 ( L_68 ) ;
F_251 ( & V_192 ) ;
if ( V_255 >= V_231 )
V_231 = V_255 + 1 ;
F_252 ( & V_192 ) ;
V_255 = F_253 ( & V_61 ) ;
if ( V_255 )
return V_255 ;
V_221 = true ;
#ifdef F_208
V_230 = F_254 ( L_80 ) ;
if ( ! V_230 ) {
V_255 = - V_108 ;
goto V_256;
}
#endif
V_255 = F_255 ( & V_257 ) ;
if ( V_255 )
goto V_258;
if ( F_256 ( V_259 ) )
F_200 ( F_257 ( & V_260 ) ) ;
if ( F_256 ( V_261 ) )
F_200 ( F_258 ( & V_262 ) ) ;
return 0 ;
V_258:
#ifdef F_208
F_259 ( V_230 ) ;
V_256:
#endif
V_221 = false ;
F_260 ( & V_61 ) ;
return V_255 ;
}
static void T_13 F_261 ( void )
{
if ( F_256 ( V_261 ) )
F_200 ( F_262 ( & V_262 ) ) ;
if ( F_256 ( V_259 ) )
F_200 ( F_263 ( & V_260 ) ) ;
F_237 ( & V_257 ) ;
#ifdef F_208
F_259 ( V_230 ) ;
#endif
F_260 ( & V_61 ) ;
F_264 () ;
}
static int F_265 ( struct V_34 * V_52 , struct V_73 * V_263 , char * V_264 )
{
F_266 ( & V_52 -> V_38 , L_81 ,
V_264 , V_263 -> V_12 , V_263 -> V_78 ,
V_263 -> V_25 & V_80 ? L_82 : L_83 ) ;
return - V_141 ;
}
static int F_267 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_265 )
{
const struct V_266 * V_267 = V_52 -> V_268 ;
int V_269 = V_267 -> V_270 , V_133 ;
bool V_271 = true ;
if ( V_267 -> V_25 & V_272 ) {
V_269 = 2 ;
if ( V_265 == 2 ) {
if ( V_267 -> V_25 & V_273 && V_74 [ 0 ] . V_25 & V_80 )
return F_265 ( V_52 , & V_74 [ 0 ] , L_84 ) ;
if ( V_267 -> V_25 & V_274 && ! ( V_74 [ 1 ] . V_25 & V_80 ) )
return F_265 ( V_52 , & V_74 [ 1 ] , L_85 ) ;
if ( V_267 -> V_25 & V_275 && V_74 [ 0 ] . V_12 != V_74 [ 1 ] . V_12 )
return F_265 ( V_52 , & V_74 [ 0 ] , L_86 ) ;
if ( F_268 ( V_74 [ 0 ] . V_78 , V_267 -> V_276 ) )
return F_265 ( V_52 , & V_74 [ 0 ] , L_87 ) ;
if ( F_268 ( V_74 [ 1 ] . V_78 , V_267 -> V_277 ) )
return F_265 ( V_52 , & V_74 [ 1 ] , L_87 ) ;
V_271 = false ;
}
}
if ( F_268 ( V_265 , V_269 ) )
return F_265 ( V_52 , & V_74 [ 0 ] , L_88 ) ;
for ( V_133 = 0 ; V_133 < V_265 ; V_133 ++ ) {
T_8 V_78 = V_74 [ V_133 ] . V_78 ;
if ( V_74 [ V_133 ] . V_25 & V_80 ) {
if ( V_271 && F_268 ( V_78 , V_267 -> V_278 ) )
return F_265 ( V_52 , & V_74 [ V_133 ] , L_87 ) ;
} else {
if ( V_271 && F_268 ( V_78 , V_267 -> V_279 ) )
return F_265 ( V_52 , & V_74 [ V_133 ] , L_87 ) ;
}
}
return 0 ;
}
int F_269 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_265 )
{
unsigned long V_280 ;
int V_31 , V_281 ;
if ( V_52 -> V_268 && F_267 ( V_52 , V_74 , V_265 ) )
return - V_141 ;
if ( F_270 ( & V_1 ) ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_265 ; V_133 ++ )
if ( V_74 [ V_133 ] . V_25 & V_80 )
F_271 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
else
F_272 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
}
V_280 = V_282 ;
for ( V_31 = 0 , V_281 = 0 ; V_281 <= V_52 -> V_283 ; V_281 ++ ) {
V_31 = V_52 -> V_224 -> V_284 ( V_52 , V_74 , V_265 ) ;
if ( V_31 != - V_222 )
break;
if ( F_273 ( V_282 , V_280 + V_52 -> V_228 ) )
break;
}
if ( F_270 ( & V_1 ) ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_31 ; V_133 ++ )
if ( V_74 [ V_133 ] . V_25 & V_80 )
F_274 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
F_275 ( V_52 , V_133 , V_31 ) ;
}
return V_31 ;
}
int F_48 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_265 )
{
int V_31 ;
if ( V_52 -> V_224 -> V_284 ) {
#ifdef F_276
for ( V_31 = 0 ; V_31 < V_265 ; V_31 ++ ) {
F_94 ( & V_52 -> V_38 ,
L_89 ,
V_31 , ( V_74 [ V_31 ] . V_25 & V_80 ) ? 'R' : 'W' ,
V_74 [ V_31 ] . V_12 , V_74 [ V_31 ] . V_78 ,
( V_74 [ V_31 ] . V_25 & V_285 ) ? L_90 : L_91 ) ;
}
#endif
if ( F_277 () || F_278 () ) {
V_31 = F_279 ( V_52 , V_286 ) ;
if ( ! V_31 )
return - V_222 ;
} else {
F_280 ( V_52 , V_286 ) ;
}
V_31 = F_269 ( V_52 , V_74 , V_265 ) ;
F_281 ( V_52 , V_286 ) ;
return V_31 ;
} else {
F_94 ( & V_52 -> V_38 , L_92 ) ;
return - V_141 ;
}
}
int F_282 ( const struct V_62 * V_67 , const char * V_79 , int V_182 )
{
int V_31 ;
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_263 ;
V_263 . V_12 = V_67 -> V_12 ;
V_263 . V_25 = V_67 -> V_25 & V_287 ;
V_263 . V_78 = V_182 ;
V_263 . V_79 = ( char * ) V_79 ;
V_31 = F_48 ( V_52 , & V_263 , 1 ) ;
return ( V_31 == 1 ) ? V_182 : V_31 ;
}
int F_283 ( const struct V_62 * V_67 , char * V_79 , int V_182 )
{
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_263 ;
int V_31 ;
V_263 . V_12 = V_67 -> V_12 ;
V_263 . V_25 = V_67 -> V_25 & V_287 ;
V_263 . V_25 |= V_80 ;
V_263 . V_78 = V_182 ;
V_263 . V_79 = V_79 ;
V_31 = F_48 ( V_52 , & V_263 , 1 ) ;
return ( V_31 == 1 ) ? V_182 : V_31 ;
}
static int F_284 ( struct V_34 * V_52 , unsigned short V_12 )
{
int V_96 ;
union V_288 V_59 ;
#ifdef F_285
if ( V_12 == 0x73 && ( V_52 -> V_289 & V_290 )
&& F_195 ( V_52 , V_291 ) )
V_96 = F_286 ( V_52 , V_12 , 0 , V_292 , 0 ,
V_293 , & V_59 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_195 ( V_52 , V_294 ) )
V_96 = F_286 ( V_52 , V_12 , 0 , V_295 , 0 ,
V_296 , NULL ) ;
else if ( F_195 ( V_52 , V_297 ) )
V_96 = F_286 ( V_52 , V_12 , 0 , V_292 , 0 ,
V_298 , & V_59 ) ;
else {
F_32 ( & V_52 -> V_38 , L_93 ,
V_12 ) ;
V_96 = - V_141 ;
}
return V_96 >= 0 ;
}
static int F_287 ( struct V_62 * V_299 ,
struct V_115 * V_116 )
{
struct V_7 V_8 ;
struct V_34 * V_35 = V_299 -> V_35 ;
int V_12 = V_299 -> V_12 ;
int V_96 ;
V_96 = F_120 ( V_12 ) ;
if ( V_96 ) {
F_32 ( & V_35 -> V_38 , L_94 ,
V_12 ) ;
return V_96 ;
}
if ( F_126 ( V_35 , V_12 ) )
return 0 ;
if ( ! F_284 ( V_35 , V_12 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_12 = V_12 ;
V_96 = V_116 -> V_300 ( V_299 , & V_8 ) ;
if ( V_96 ) {
return V_96 == - V_39 ? 0 : V_96 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_26 ( & V_35 -> V_38 ,
L_95 ,
V_116 -> V_116 . V_112 , V_12 ) ;
} else {
struct V_62 * V_67 ;
if ( V_35 -> V_289 & V_301 )
F_32 ( & V_35 -> V_38 ,
L_96
L_97
L_98 ,
V_8 . V_12 ) ;
F_94 ( & V_35 -> V_38 , L_99 ,
V_8 . type , V_8 . V_12 ) ;
V_67 = F_25 ( V_35 , & V_8 ) ;
if ( V_67 )
F_154 ( & V_67 -> V_187 , & V_116 -> V_246 ) ;
else
F_26 ( & V_35 -> V_38 , L_100 ,
V_8 . type , V_8 . V_12 ) ;
}
return 0 ;
}
static int F_187 ( struct V_34 * V_35 , struct V_115 * V_116 )
{
const unsigned short * V_302 ;
struct V_62 * V_299 ;
int V_133 , V_96 = 0 ;
int V_303 = F_136 ( V_35 ) ;
V_302 = V_116 -> V_302 ;
if ( ! V_116 -> V_300 || ! V_302 )
return 0 ;
if ( V_35 -> V_289 == V_301 ) {
F_94 ( & V_35 -> V_38 ,
L_101
L_102 ,
V_116 -> V_116 . V_112 ) ;
return 0 ;
}
if ( ! ( V_35 -> V_289 & V_116 -> V_289 ) )
return 0 ;
V_299 = F_47 ( sizeof( struct V_62 ) , V_76 ) ;
if ( ! V_299 )
return - V_108 ;
V_299 -> V_35 = V_35 ;
for ( V_133 = 0 ; V_302 [ V_133 ] != V_304 ; V_133 += 1 ) {
F_94 ( & V_35 -> V_38 ,
L_103 ,
V_303 , V_302 [ V_133 ] ) ;
V_299 -> V_12 = V_302 [ V_133 ] ;
V_96 = F_287 ( V_299 , V_116 ) ;
if ( F_288 ( V_96 ) )
break;
}
F_50 ( V_299 ) ;
return V_96 ;
}
int F_289 ( struct V_34 * V_52 , unsigned short V_12 )
{
return F_286 ( V_52 , V_12 , 0 , V_292 , 0 ,
V_296 , NULL ) >= 0 ;
}
struct V_62 *
F_290 ( struct V_34 * V_52 ,
struct V_7 * V_8 ,
unsigned short const * V_305 ,
int (* V_155)( struct V_34 * , unsigned short V_12 ) )
{
int V_133 ;
if ( ! V_155 )
V_155 = F_284 ;
for ( V_133 = 0 ; V_305 [ V_133 ] != V_304 ; V_133 ++ ) {
if ( F_120 ( V_305 [ V_133 ] ) < 0 ) {
F_32 ( & V_52 -> V_38 , L_104 ,
V_305 [ V_133 ] ) ;
continue;
}
if ( F_126 ( V_52 , V_305 [ V_133 ] ) ) {
F_94 ( & V_52 -> V_38 ,
L_105 ,
V_305 [ V_133 ] ) ;
continue;
}
if ( V_155 ( V_52 , V_305 [ V_133 ] ) )
break;
}
if ( V_305 [ V_133 ] == V_304 ) {
F_94 ( & V_52 -> V_38 , L_106 ) ;
return NULL ;
}
V_8 -> V_12 = V_305 [ V_133 ] ;
return F_25 ( V_52 , V_8 ) ;
}
struct V_34 * F_291 ( int V_194 )
{
struct V_34 * V_35 ;
F_153 ( & V_232 ) ;
V_35 = F_222 ( & V_233 , V_194 ) ;
if ( ! V_35 )
goto exit;
if ( F_182 ( V_35 -> V_203 ) )
F_240 ( & V_35 -> V_38 ) ;
else
V_35 = NULL ;
exit:
F_155 ( & V_232 ) ;
return V_35 ;
}
void F_292 ( struct V_34 * V_52 )
{
if ( ! V_52 )
return;
F_45 ( & V_52 -> V_38 ) ;
F_293 ( V_52 -> V_203 ) ;
}
static T_4 F_294 ( T_8 V_4 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < 8 ; V_133 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_306 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_295 ( T_4 V_307 , T_4 * V_308 , T_9 V_182 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_182 ; V_133 ++ )
V_307 = F_294 ( ( V_307 ^ V_308 [ V_133 ] ) << 8 ) ;
return V_307 ;
}
static T_4 F_296 ( T_4 V_309 , struct V_73 * V_263 )
{
T_4 V_12 = F_297 ( V_263 ) ;
V_309 = F_295 ( V_309 , & V_12 , 1 ) ;
return F_295 ( V_309 , V_263 -> V_79 , V_263 -> V_78 ) ;
}
static inline void F_298 ( struct V_73 * V_263 )
{
V_263 -> V_79 [ V_263 -> V_78 ] = F_296 ( 0 , V_263 ) ;
V_263 -> V_78 ++ ;
}
static int F_299 ( T_4 V_310 , struct V_73 * V_263 )
{
T_4 V_311 = V_263 -> V_79 [ -- V_263 -> V_78 ] ;
V_310 = F_296 ( V_310 , V_263 ) ;
if ( V_311 != V_310 ) {
F_223 ( L_107 ,
V_311 , V_310 ) ;
return - V_312 ;
}
return 0 ;
}
T_14 F_54 ( const struct V_62 * V_67 )
{
union V_288 V_4 ;
int V_11 ;
V_11 = F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_292 , 0 ,
V_298 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_313 ;
}
T_14 F_55 ( const struct V_62 * V_67 , T_4 V_65 )
{
return F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_295 , V_65 , V_298 , NULL ) ;
}
T_14 F_56 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_288 V_4 ;
int V_11 ;
V_11 = F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_292 , V_82 ,
V_293 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_313 ;
}
T_14 F_57 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_65 )
{
union V_288 V_4 ;
V_4 . V_313 = V_65 ;
return F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_295 , V_82 ,
V_293 , & V_4 ) ;
}
T_14 F_58 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_288 V_4 ;
int V_11 ;
V_11 = F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_292 , V_82 ,
V_314 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_315 ;
}
T_14 F_59 ( const struct V_62 * V_67 , T_4 V_82 ,
T_8 V_65 )
{
union V_288 V_4 ;
V_4 . V_315 = V_65 ;
return F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_295 , V_82 ,
V_314 , & V_4 ) ;
}
T_14 F_60 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 * V_316 )
{
union V_288 V_4 ;
int V_11 ;
V_11 = F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_292 , V_82 ,
V_317 , & V_4 ) ;
if ( V_11 )
return V_11 ;
memcpy ( V_316 , & V_4 . V_318 [ 1 ] , V_4 . V_318 [ 0 ] ) ;
return V_4 . V_318 [ 0 ] ;
}
T_14 F_61 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_316 )
{
union V_288 V_4 ;
if ( V_95 > V_319 )
V_95 = V_319 ;
V_4 . V_318 [ 0 ] = V_95 ;
memcpy ( & V_4 . V_318 [ 1 ] , V_316 , V_95 ) ;
return F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_295 , V_82 ,
V_317 , & V_4 ) ;
}
T_14 F_300 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , T_4 * V_316 )
{
union V_288 V_4 ;
int V_11 ;
if ( V_95 > V_319 )
V_95 = V_319 ;
V_4 . V_318 [ 0 ] = V_95 ;
V_11 = F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_292 , V_82 ,
V_320 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_316 , & V_4 . V_318 [ 1 ] , V_4 . V_318 [ 0 ] ) ;
return V_4 . V_318 [ 0 ] ;
}
T_14 F_301 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_316 )
{
union V_288 V_4 ;
if ( V_95 > V_319 )
V_95 = V_319 ;
V_4 . V_318 [ 0 ] = V_95 ;
memcpy ( V_4 . V_318 + 1 , V_316 , V_95 ) ;
return F_286 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_295 , V_82 ,
V_320 , & V_4 ) ;
}
static T_14 F_302 ( struct V_34 * V_35 , T_8 V_12 ,
unsigned short V_25 ,
char V_321 , T_4 V_82 , int V_322 ,
union V_288 * V_4 )
{
unsigned char V_323 [ V_319 + 3 ] ;
unsigned char V_324 [ V_319 + 2 ] ;
int V_265 = V_321 == V_292 ? 2 : 1 ;
int V_133 ;
T_4 V_325 = 0 ;
int V_11 ;
struct V_73 V_263 [ 2 ] = {
{
. V_12 = V_12 ,
. V_25 = V_25 ,
. V_78 = 1 ,
. V_79 = V_323 ,
} , {
. V_12 = V_12 ,
. V_25 = V_25 | V_80 ,
. V_78 = 0 ,
. V_79 = V_324 ,
} ,
} ;
V_323 [ 0 ] = V_82 ;
switch ( V_322 ) {
case V_296 :
V_263 [ 0 ] . V_78 = 0 ;
V_263 [ 0 ] . V_25 = V_25 | ( V_321 == V_292 ?
V_80 : 0 ) ;
V_265 = 1 ;
break;
case V_298 :
if ( V_321 == V_292 ) {
V_263 [ 0 ] . V_25 = V_80 | V_25 ;
V_265 = 1 ;
}
break;
case V_293 :
if ( V_321 == V_292 )
V_263 [ 1 ] . V_78 = 1 ;
else {
V_263 [ 0 ] . V_78 = 2 ;
V_323 [ 1 ] = V_4 -> V_313 ;
}
break;
case V_314 :
if ( V_321 == V_292 )
V_263 [ 1 ] . V_78 = 2 ;
else {
V_263 [ 0 ] . V_78 = 3 ;
V_323 [ 1 ] = V_4 -> V_315 & 0xff ;
V_323 [ 2 ] = V_4 -> V_315 >> 8 ;
}
break;
case V_326 :
V_265 = 2 ;
V_321 = V_292 ;
V_263 [ 0 ] . V_78 = 3 ;
V_263 [ 1 ] . V_78 = 2 ;
V_323 [ 1 ] = V_4 -> V_315 & 0xff ;
V_323 [ 2 ] = V_4 -> V_315 >> 8 ;
break;
case V_317 :
if ( V_321 == V_292 ) {
V_263 [ 1 ] . V_25 |= V_285 ;
V_263 [ 1 ] . V_78 = 1 ;
} else {
V_263 [ 0 ] . V_78 = V_4 -> V_318 [ 0 ] + 2 ;
if ( V_263 [ 0 ] . V_78 > V_319 + 2 ) {
F_26 ( & V_35 -> V_38 ,
L_108 ,
V_4 -> V_318 [ 0 ] ) ;
return - V_33 ;
}
for ( V_133 = 1 ; V_133 < V_263 [ 0 ] . V_78 ; V_133 ++ )
V_323 [ V_133 ] = V_4 -> V_318 [ V_133 - 1 ] ;
}
break;
case V_327 :
V_265 = 2 ;
V_321 = V_292 ;
if ( V_4 -> V_318 [ 0 ] > V_319 ) {
F_26 ( & V_35 -> V_38 ,
L_108 ,
V_4 -> V_318 [ 0 ] ) ;
return - V_33 ;
}
V_263 [ 0 ] . V_78 = V_4 -> V_318 [ 0 ] + 2 ;
for ( V_133 = 1 ; V_133 < V_263 [ 0 ] . V_78 ; V_133 ++ )
V_323 [ V_133 ] = V_4 -> V_318 [ V_133 - 1 ] ;
V_263 [ 1 ] . V_25 |= V_285 ;
V_263 [ 1 ] . V_78 = 1 ;
break;
case V_320 :
if ( V_321 == V_292 ) {
V_263 [ 1 ] . V_78 = V_4 -> V_318 [ 0 ] ;
} else {
V_263 [ 0 ] . V_78 = V_4 -> V_318 [ 0 ] + 1 ;
if ( V_263 [ 0 ] . V_78 > V_319 + 1 ) {
F_26 ( & V_35 -> V_38 ,
L_108 ,
V_4 -> V_318 [ 0 ] ) ;
return - V_33 ;
}
for ( V_133 = 1 ; V_133 <= V_4 -> V_318 [ 0 ] ; V_133 ++ )
V_323 [ V_133 ] = V_4 -> V_318 [ V_133 ] ;
}
break;
default:
F_26 ( & V_35 -> V_38 , L_109 , V_322 ) ;
return - V_141 ;
}
V_133 = ( ( V_25 & V_328 ) && V_322 != V_296
&& V_322 != V_320 ) ;
if ( V_133 ) {
if ( ! ( V_263 [ 0 ] . V_25 & V_80 ) ) {
if ( V_265 == 1 )
F_298 ( & V_263 [ 0 ] ) ;
else
V_325 = F_296 ( 0 , & V_263 [ 0 ] ) ;
}
if ( V_263 [ V_265 - 1 ] . V_25 & V_80 )
V_263 [ V_265 - 1 ] . V_78 ++ ;
}
V_11 = F_48 ( V_35 , V_263 , V_265 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_133 && ( V_263 [ V_265 - 1 ] . V_25 & V_80 ) ) {
V_11 = F_299 ( V_325 , & V_263 [ V_265 - 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_321 == V_292 )
switch ( V_322 ) {
case V_298 :
V_4 -> V_313 = V_323 [ 0 ] ;
break;
case V_293 :
V_4 -> V_313 = V_324 [ 0 ] ;
break;
case V_314 :
case V_326 :
V_4 -> V_315 = V_324 [ 0 ] | ( V_324 [ 1 ] << 8 ) ;
break;
case V_320 :
for ( V_133 = 0 ; V_133 < V_4 -> V_318 [ 0 ] ; V_133 ++ )
V_4 -> V_318 [ V_133 + 1 ] = V_324 [ V_133 ] ;
break;
case V_317 :
case V_327 :
for ( V_133 = 0 ; V_133 < V_324 [ 0 ] + 1 ; V_133 ++ )
V_4 -> V_318 [ V_133 ] = V_324 [ V_133 ] ;
break;
}
return 0 ;
}
T_14 F_286 ( struct V_34 * V_35 , T_8 V_12 , unsigned short V_25 ,
char V_321 , T_4 V_82 , int V_329 ,
union V_288 * V_4 )
{
unsigned long V_280 ;
int V_281 ;
T_14 V_42 ;
F_303 ( V_35 , V_12 , V_25 , V_321 ,
V_82 , V_329 , V_4 ) ;
F_304 ( V_35 , V_12 , V_25 , V_321 ,
V_82 , V_329 ) ;
V_25 &= V_287 | V_328 | V_330 ;
if ( V_35 -> V_224 -> V_331 ) {
F_280 ( V_35 , V_286 ) ;
V_280 = V_282 ;
for ( V_42 = 0 , V_281 = 0 ; V_281 <= V_35 -> V_283 ; V_281 ++ ) {
V_42 = V_35 -> V_224 -> V_331 ( V_35 , V_12 , V_25 ,
V_321 , V_82 ,
V_329 , V_4 ) ;
if ( V_42 != - V_222 )
break;
if ( F_273 ( V_282 ,
V_280 + V_35 -> V_228 ) )
break;
}
F_281 ( V_35 , V_286 ) ;
if ( V_42 != - V_141 || ! V_35 -> V_224 -> V_284 )
goto V_332;
}
V_42 = F_302 ( V_35 , V_12 , V_25 , V_321 ,
V_82 , V_329 , V_4 ) ;
V_332:
F_305 ( V_35 , V_12 , V_25 , V_321 ,
V_82 , V_329 , V_4 ) ;
F_306 ( V_35 , V_12 , V_25 , V_321 ,
V_82 , V_329 , V_42 ) ;
return V_42 ;
}
T_14 F_307 ( const struct V_62 * V_67 ,
T_4 V_82 , T_4 V_95 , T_4 * V_316 )
{
T_4 V_133 = 0 ;
int V_11 ;
if ( V_95 > V_319 )
V_95 = V_319 ;
if ( F_195 ( V_67 -> V_35 , V_333 ) )
return F_300 ( V_67 , V_82 , V_95 , V_316 ) ;
if ( ! F_195 ( V_67 -> V_35 , V_291 ) )
return - V_141 ;
if ( F_195 ( V_67 -> V_35 , V_334 ) ) {
while ( ( V_133 + 2 ) <= V_95 ) {
V_11 = F_58 ( V_67 , V_82 + V_133 ) ;
if ( V_11 < 0 )
return V_11 ;
V_316 [ V_133 ] = V_11 & 0xff ;
V_316 [ V_133 + 1 ] = V_11 >> 8 ;
V_133 += 2 ;
}
}
while ( V_133 < V_95 ) {
V_11 = F_56 ( V_67 , V_82 + V_133 ) ;
if ( V_11 < 0 )
return V_11 ;
V_316 [ V_133 ] = V_11 ;
V_133 ++ ;
}
return V_133 ;
}
int F_308 ( struct V_62 * V_67 , T_15 V_335 )
{
int V_31 ;
if ( ! V_67 || ! V_335 ) {
F_201 ( 1 , L_110 ) ;
return - V_33 ;
}
if ( ! ( V_67 -> V_25 & V_163 ) )
F_32 ( & V_67 -> V_38 , L_111 ,
V_336 ) ;
if ( ! ( V_67 -> V_25 & V_26 ) ) {
V_31 = F_120 ( V_67 -> V_12 ) ;
if ( V_31 ) {
F_26 ( & V_67 -> V_38 , L_112 , V_336 ) ;
return V_31 ;
}
}
if ( ! V_67 -> V_35 -> V_224 -> V_337 ) {
F_26 ( & V_67 -> V_38 , L_113 , V_336 ) ;
return - V_141 ;
}
V_67 -> V_335 = V_335 ;
F_309 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_224 -> V_337 ( V_67 ) ;
F_310 ( V_67 -> V_35 ) ;
if ( V_31 ) {
V_67 -> V_335 = NULL ;
F_26 ( & V_67 -> V_38 , L_114 , V_336 , V_31 ) ;
}
return V_31 ;
}
int F_311 ( struct V_62 * V_67 )
{
int V_31 ;
if ( ! V_67 -> V_35 -> V_224 -> V_338 ) {
F_26 ( & V_67 -> V_38 , L_113 , V_336 ) ;
return - V_141 ;
}
F_309 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_224 -> V_338 ( V_67 ) ;
F_310 ( V_67 -> V_35 ) ;
if ( V_31 == 0 )
V_67 -> V_335 = NULL ;
else
F_26 ( & V_67 -> V_38 , L_114 , V_336 , V_31 ) ;
return V_31 ;
}
