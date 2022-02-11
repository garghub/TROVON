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
F_21 ( V_28 , F_22 ( & V_28 -> V_38 ) , V_8 -> type ,
sizeof( V_8 -> type ) ) ;
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
F_137 ( V_67 -> V_112 , V_8 -> type , sizeof( V_67 -> V_112 ) ) ;
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
if ( V_8 -> V_174 ) {
V_11 = F_138 ( & V_67 -> V_38 , V_8 -> V_174 ) ;
if ( V_11 ) {
F_26 ( & V_52 -> V_38 ,
L_30 ,
V_67 -> V_112 , V_11 ) ;
goto V_172;
}
}
V_11 = F_139 ( & V_67 -> V_38 ) ;
if ( V_11 )
goto V_175;
F_94 ( & V_52 -> V_38 , L_31 ,
V_67 -> V_112 , F_22 ( & V_67 -> V_38 ) ) ;
return V_67 ;
V_175:
if ( V_8 -> V_174 )
F_140 ( & V_67 -> V_38 ) ;
V_172:
F_26 ( & V_52 -> V_38 ,
L_32 ,
V_67 -> V_112 , V_67 -> V_12 , V_11 ) ;
V_171:
F_50 ( V_67 ) ;
return NULL ;
}
void F_44 ( struct V_62 * V_67 )
{
if ( V_67 -> V_38 . V_148 )
F_141 ( V_67 -> V_38 . V_148 , V_176 ) ;
if ( F_38 ( & V_67 -> V_38 ) )
F_142 ( F_38 ( & V_67 -> V_38 ) ) ;
F_143 ( & V_67 -> V_38 ) ;
}
static int F_144 ( struct V_62 * V_67 ,
const struct V_110 * V_111 )
{
return 0 ;
}
static int F_145 ( struct V_62 * V_67 )
{
return 0 ;
}
struct V_62 * F_146 ( struct V_34 * V_35 , T_8 V_177 )
{
struct V_7 V_8 = {
F_147 ( L_33 , V_177 ) ,
} ;
return F_25 ( V_35 , & V_8 ) ;
}
struct V_62 * F_148 ( struct V_62 * V_67 ,
const char * V_112 ,
T_8 V_178 )
{
struct V_179 * V_180 = V_67 -> V_38 . V_148 ;
T_3 V_12 = V_178 ;
int V_133 ;
if ( V_180 ) {
V_133 = F_149 ( V_180 , L_34 , V_112 ) ;
if ( V_133 >= 0 )
F_150 ( V_180 , L_35 , V_133 , & V_12 ) ;
}
F_94 ( & V_67 -> V_35 -> V_38 , L_36 , V_112 , V_12 ) ;
return F_146 ( V_67 -> V_35 , V_12 ) ;
}
static void F_151 ( struct V_58 * V_38 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
F_152 ( & V_52 -> V_181 ) ;
}
unsigned int F_153 ( struct V_34 * V_35 )
{
unsigned int V_182 = 0 ;
while ( ( V_35 = F_123 ( V_35 ) ) )
V_182 ++ ;
F_154 ( V_182 >= V_183 ,
L_37 ) ;
return V_182 ;
}
static T_7
F_155 ( struct V_58 * V_38 , struct V_158 * V_159 ,
const char * V_79 , T_9 V_184 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
struct V_7 V_8 ;
struct V_62 * V_67 ;
char * V_185 , V_186 ;
int V_42 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_185 = strchr ( V_79 , ' ' ) ;
if ( ! V_185 ) {
F_26 ( V_38 , L_38 , L_39 ) ;
return - V_33 ;
}
if ( V_185 - V_79 > V_187 - 1 ) {
F_26 ( V_38 , L_40 , L_39 ) ;
return - V_33 ;
}
memcpy ( V_8 . type , V_79 , V_185 - V_79 ) ;
V_42 = sscanf ( ++ V_185 , L_41 , & V_8 . V_12 , & V_186 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_42 , L_39 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_186 != '\n' ) {
F_26 ( V_38 , L_43 , L_39 ) ;
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
F_156 ( & V_52 -> V_188 ) ;
F_157 ( & V_67 -> V_189 , & V_52 -> V_190 ) ;
F_158 ( & V_52 -> V_188 ) ;
F_159 ( V_38 , L_44 , L_39 ,
V_8 . type , V_8 . V_12 ) ;
return V_184 ;
}
static T_7
F_160 ( struct V_58 * V_38 , struct V_158 * V_159 ,
const char * V_79 , T_9 V_184 )
{
struct V_34 * V_52 = F_115 ( V_38 ) ;
struct V_62 * V_67 , * V_191 ;
unsigned short V_12 ;
char V_186 ;
int V_42 ;
V_42 = sscanf ( V_79 , L_41 , & V_12 , & V_186 ) ;
if ( V_42 < 1 ) {
F_26 ( V_38 , L_42 , L_45 ) ;
return - V_33 ;
}
if ( V_42 > 1 && V_186 != '\n' ) {
F_26 ( V_38 , L_43 , L_45 ) ;
return - V_33 ;
}
V_42 = - V_146 ;
F_161 ( & V_52 -> V_188 ,
F_153 ( V_52 ) ) ;
F_162 (client, next, &adap->userspace_clients,
detected) {
if ( F_118 ( V_67 ) == V_12 ) {
F_159 ( V_38 , L_46 ,
L_45 , V_67 -> V_112 , V_67 -> V_12 ) ;
F_163 ( & V_67 -> V_189 ) ;
F_44 ( V_67 ) ;
V_42 = V_184 ;
break;
}
}
F_158 ( & V_52 -> V_188 ) ;
if ( V_42 < 0 )
F_26 ( V_38 , L_47 ,
L_45 ) ;
return V_42 ;
}
struct V_34 * F_36 ( struct V_58 * V_38 )
{
return ( V_38 -> type == & V_167 )
? F_115 ( V_38 )
: NULL ;
}
static void F_164 ( struct V_34 * V_35 )
{
struct V_192 * V_193 ;
F_165 ( & V_194 ) ;
F_166 (devinfo, &__i2c_board_list, list) {
if ( V_193 -> V_195 == V_35 -> V_196
&& ! F_25 ( V_35 ,
& V_193 -> V_197 ) )
F_26 ( & V_35 -> V_38 ,
L_48 ,
V_193 -> V_197 . V_12 ) ;
}
F_167 ( & V_194 ) ;
}
static struct V_62 * F_168 ( struct V_34 * V_52 ,
struct V_179 * V_198 )
{
struct V_62 * V_166 ;
struct V_7 V_8 = {} ;
struct V_199 V_200 = {} ;
const T_10 * V_201 ;
T_3 V_12 ;
int V_78 ;
F_94 ( & V_52 -> V_38 , L_49 , V_198 -> V_202 ) ;
if ( F_169 ( V_198 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_26 ( & V_52 -> V_38 , L_50 ,
V_198 -> V_202 ) ;
return F_170 ( - V_33 ) ;
}
V_201 = F_171 ( V_198 , L_35 , & V_78 ) ;
if ( ! V_201 || ( V_78 < sizeof( * V_201 ) ) ) {
F_26 ( & V_52 -> V_38 , L_51 ,
V_198 -> V_202 ) ;
return F_170 ( - V_33 ) ;
}
V_12 = F_172 ( V_201 ) ;
if ( V_12 & V_203 ) {
V_12 &= ~ V_203 ;
V_8 . V_25 |= V_26 ;
}
if ( V_12 & V_204 ) {
V_12 &= ~ V_204 ;
V_8 . V_25 |= V_163 ;
}
if ( F_119 ( V_12 , V_8 . V_25 ) ) {
F_26 ( & V_52 -> V_38 , L_52 ,
V_12 , V_198 -> V_202 ) ;
return F_170 ( - V_33 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_148 = F_173 ( V_198 ) ;
V_8 . V_170 = & V_200 ;
if ( F_174 ( V_198 , L_53 ) )
V_8 . V_25 |= V_147 ;
if ( F_171 ( V_198 , L_54 , NULL ) )
V_8 . V_25 |= V_151 ;
V_166 = F_25 ( V_52 , & V_8 ) ;
if ( V_166 == NULL ) {
F_26 ( & V_52 -> V_38 , L_55 ,
V_198 -> V_202 ) ;
F_175 ( V_198 ) ;
return F_170 ( - V_33 ) ;
}
return V_166 ;
}
static void F_176 ( struct V_34 * V_52 )
{
struct V_179 * V_173 , * V_198 ;
struct V_62 * V_67 ;
if ( ! V_52 -> V_38 . V_148 )
return;
F_94 ( & V_52 -> V_38 , L_56 ) ;
V_173 = F_177 ( V_52 -> V_38 . V_148 , L_57 ) ;
if ( ! V_173 )
V_173 = F_173 ( V_52 -> V_38 . V_148 ) ;
F_178 (bus, node) {
if ( F_179 ( V_198 , V_176 ) )
continue;
V_67 = F_168 ( V_52 , V_198 ) ;
if ( F_180 ( V_67 ) ) {
F_32 ( & V_52 -> V_38 ,
L_58 ,
V_198 -> V_202 ) ;
F_141 ( V_198 , V_176 ) ;
}
}
F_175 ( V_173 ) ;
}
static int F_181 ( struct V_58 * V_38 , void * V_4 )
{
return V_38 -> V_148 == V_4 ;
}
struct V_62 * F_182 ( struct V_179 * V_198 )
{
struct V_58 * V_38 ;
struct V_62 * V_67 ;
V_38 = F_40 ( & V_61 , NULL , V_198 , F_181 ) ;
if ( ! V_38 )
return NULL ;
V_67 = F_42 ( V_38 ) ;
if ( ! V_67 )
F_45 ( V_38 ) ;
return V_67 ;
}
struct V_34 * F_183 ( struct V_179 * V_198 )
{
struct V_58 * V_38 ;
struct V_34 * V_35 ;
V_38 = F_40 ( & V_61 , NULL , V_198 , F_181 ) ;
if ( ! V_38 )
return NULL ;
V_35 = F_36 ( V_38 ) ;
if ( ! V_35 )
F_45 ( V_38 ) ;
return V_35 ;
}
struct V_34 * F_184 ( struct V_179 * V_198 )
{
struct V_34 * V_35 ;
V_35 = F_183 ( V_198 ) ;
if ( ! V_35 )
return NULL ;
if ( ! F_185 ( V_35 -> V_205 ) ) {
F_45 ( & V_35 -> V_38 ) ;
V_35 = NULL ;
}
return V_35 ;
}
static const struct V_206 *
F_186 ( const struct V_206 * V_207 ,
struct V_62 * V_67 )
{
const char * V_112 ;
for (; V_207 -> V_208 [ 0 ] ; V_207 ++ ) {
if ( F_187 ( V_67 -> V_112 , V_207 -> V_208 ) )
return V_207 ;
V_112 = strchr ( V_207 -> V_208 , ',' ) ;
if ( ! V_112 )
V_112 = V_207 -> V_208 ;
else
V_112 ++ ;
if ( F_187 ( V_67 -> V_112 , V_112 ) )
return V_207 ;
}
return NULL ;
}
const struct V_206
* F_73 ( const struct V_206 * V_207 ,
struct V_62 * V_67 )
{
const struct V_206 * V_209 ;
if ( ! ( V_67 && V_207 ) )
return NULL ;
V_209 = F_188 ( V_207 , & V_67 -> V_38 ) ;
if ( V_209 )
return V_209 ;
return F_186 ( V_207 , V_67 ) ;
}
static void F_176 ( struct V_34 * V_52 ) { }
static int F_189 ( struct V_115 * V_116 ,
struct V_34 * V_52 )
{
F_190 ( V_52 , V_116 ) ;
if ( V_116 -> V_210 ) {
F_32 ( & V_52 -> V_38 , L_59 ,
V_116 -> V_116 . V_112 ) ;
F_32 ( & V_52 -> V_38 ,
L_60 ) ;
V_116 -> V_210 ( V_52 ) ;
}
return 0 ;
}
static int F_191 ( struct V_113 * V_211 , void * V_4 )
{
return F_189 ( F_75 ( V_211 ) , V_4 ) ;
}
static void F_192 ( struct V_34 * V_52 )
{
struct V_212 * V_213 = V_52 -> V_144 ;
T_11 V_214 ;
if ( ! V_213 )
return;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ )
F_193 ( F_98 ( V_213 , V_214 ) ) ;
F_194 ( V_213 ) ;
V_52 -> V_144 = NULL ;
}
static int F_195 ( struct V_212 * V_216 ,
unsigned int V_217 ,
T_11 V_218 )
{
F_196 ( V_217 , & V_219 , V_220 ) ;
return 0 ;
}
static int F_197 ( struct V_34 * V_52 )
{
struct V_212 * V_213 ;
if ( ! F_198 ( V_52 , V_221 ) )
return 0 ;
V_213 = F_199 ( V_52 -> V_38 . V_41 ,
V_215 ,
& V_222 , V_52 ) ;
if ( ! V_213 )
return - V_108 ;
V_52 -> V_144 = V_213 ;
return 0 ;
}
int F_200 ( struct V_34 * V_52 , unsigned short V_12 )
{
int V_44 ;
if ( ! V_52 )
return - V_33 ;
V_44 = F_98 ( V_52 -> V_144 , V_12 ) ;
if ( V_44 <= 0 )
return - V_145 ;
F_201 ( V_44 ) ;
return 0 ;
}
static int F_202 ( struct V_34 * V_52 )
{
int V_42 = - V_33 ;
if ( F_203 ( ! V_223 ) ) {
V_42 = - V_224 ;
goto V_225;
}
if ( F_204 ( ! V_52 -> V_112 [ 0 ] , L_61 ) )
goto V_225;
if ( ! V_52 -> V_226 ) {
F_205 ( L_62 , V_52 -> V_112 ) ;
goto V_225;
}
if ( ! V_52 -> V_227 )
V_52 -> V_227 = & V_228 ;
F_206 ( & V_52 -> V_168 ) ;
F_206 ( & V_52 -> V_229 ) ;
F_207 ( & V_52 -> V_188 ) ;
F_12 ( & V_52 -> V_190 ) ;
if ( V_52 -> V_230 == 0 )
V_52 -> V_230 = V_231 ;
V_42 = F_197 ( V_52 ) ;
if ( V_42 ) {
F_205 ( L_63 ,
V_52 -> V_112 , V_42 ) ;
goto V_225;
}
F_134 ( & V_52 -> V_38 , L_64 , V_52 -> V_196 ) ;
V_52 -> V_38 . V_173 = & V_61 ;
V_52 -> V_38 . type = & V_167 ;
V_42 = F_139 ( & V_52 -> V_38 ) ;
if ( V_42 ) {
F_205 ( L_65 , V_52 -> V_112 , V_42 ) ;
goto V_225;
}
F_94 ( & V_52 -> V_38 , L_66 , V_52 -> V_112 ) ;
F_208 ( & V_52 -> V_38 ) ;
F_209 ( & V_52 -> V_38 , true ) ;
F_210 ( & V_52 -> V_38 ) ;
#ifdef F_211
V_42 = F_212 ( V_232 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
if ( V_42 )
F_32 ( & V_52 -> V_38 ,
L_67 ) ;
#endif
F_95 ( V_52 ) ;
F_176 ( V_52 ) ;
F_28 ( V_52 ) ;
F_63 ( V_52 ) ;
if ( V_52 -> V_196 < V_233 )
F_164 ( V_52 ) ;
F_156 ( & V_234 ) ;
F_213 ( & V_61 , NULL , V_52 , F_191 ) ;
F_158 ( & V_234 ) ;
return 0 ;
V_225:
F_156 ( & V_234 ) ;
F_214 ( & V_235 , V_52 -> V_196 ) ;
F_158 ( & V_234 ) ;
return V_42 ;
}
static int F_215 ( struct V_34 * V_52 )
{
int V_111 ;
F_156 ( & V_234 ) ;
V_111 = F_216 ( & V_235 , V_52 , V_52 -> V_196 , V_52 -> V_196 + 1 , V_76 ) ;
F_158 ( & V_234 ) ;
if ( F_204 ( V_111 < 0 , L_68 ) )
return V_111 == - V_236 ? - V_139 : V_111 ;
return F_202 ( V_52 ) ;
}
int F_217 ( struct V_34 * V_35 )
{
struct V_58 * V_38 = & V_35 -> V_38 ;
int V_111 ;
if ( V_38 -> V_148 ) {
V_111 = F_218 ( V_38 -> V_148 , L_69 ) ;
if ( V_111 >= 0 ) {
V_35 -> V_196 = V_111 ;
return F_215 ( V_35 ) ;
}
}
F_156 ( & V_234 ) ;
V_111 = F_216 ( & V_235 , V_35 ,
V_233 , 0 , V_76 ) ;
F_158 ( & V_234 ) ;
if ( F_204 ( V_111 < 0 , L_68 ) )
return V_111 ;
V_35 -> V_196 = V_111 ;
return F_202 ( V_35 ) ;
}
int F_219 ( struct V_34 * V_52 )
{
if ( V_52 -> V_196 == - 1 )
return F_217 ( V_52 ) ;
return F_215 ( V_52 ) ;
}
static void F_220 ( struct V_115 * V_116 ,
struct V_34 * V_35 )
{
struct V_62 * V_67 , * V_237 ;
F_162 (client, _n, &driver->clients, detected) {
if ( V_67 -> V_35 == V_35 ) {
F_94 ( & V_35 -> V_38 , L_70 ,
V_67 -> V_112 , V_67 -> V_12 ) ;
F_163 ( & V_67 -> V_189 ) ;
F_44 ( V_67 ) ;
}
}
}
static int F_221 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 && strcmp ( V_67 -> V_112 , L_33 ) )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_222 ( struct V_58 * V_38 , void * V_59 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
if ( V_67 )
F_44 ( V_67 ) ;
return 0 ;
}
static int F_223 ( struct V_113 * V_211 , void * V_4 )
{
F_220 ( F_75 ( V_211 ) , V_4 ) ;
return 0 ;
}
void F_224 ( struct V_34 * V_52 )
{
struct V_34 * V_238 ;
struct V_62 * V_67 , * V_191 ;
F_156 ( & V_234 ) ;
V_238 = F_225 ( & V_235 , V_52 -> V_196 ) ;
F_158 ( & V_234 ) ;
if ( V_238 != V_52 ) {
F_226 ( L_71 , V_52 -> V_112 ) ;
return;
}
F_68 ( V_52 ) ;
F_156 ( & V_234 ) ;
F_213 ( & V_61 , NULL , V_52 ,
F_223 ) ;
F_158 ( & V_234 ) ;
F_161 ( & V_52 -> V_188 ,
F_153 ( V_52 ) ) ;
F_162 (client, next, &adap->userspace_clients,
detected) {
F_94 ( & V_52 -> V_38 , L_70 , V_67 -> V_112 ,
V_67 -> V_12 ) ;
F_163 ( & V_67 -> V_189 ) ;
F_44 ( V_67 ) ;
}
F_158 ( & V_52 -> V_188 ) ;
F_124 ( & V_52 -> V_38 , NULL , F_221 ) ;
F_124 ( & V_52 -> V_38 , NULL , F_222 ) ;
#ifdef F_211
F_227 ( V_232 , & V_52 -> V_38 ,
V_52 -> V_38 . V_107 ) ;
#endif
F_94 ( & V_52 -> V_38 , L_72 , V_52 -> V_112 ) ;
F_228 ( & V_52 -> V_38 ) ;
F_192 ( V_52 ) ;
F_229 ( & V_52 -> V_181 ) ;
F_143 ( & V_52 -> V_38 ) ;
F_230 ( & V_52 -> V_181 ) ;
F_156 ( & V_234 ) ;
F_214 ( & V_235 , V_52 -> V_196 ) ;
F_158 ( & V_234 ) ;
memset ( & V_52 -> V_38 , 0 , sizeof( V_52 -> V_38 ) ) ;
}
void F_231 ( struct V_58 * V_38 , struct V_239 * V_240 , bool V_241 )
{
int V_31 ;
memset ( V_240 , 0 , sizeof( * V_240 ) ) ;
V_31 = F_232 ( V_38 , L_73 , & V_240 -> V_242 ) ;
if ( V_31 && V_241 )
V_240 -> V_242 = 100000 ;
V_31 = F_232 ( V_38 , L_74 , & V_240 -> V_243 ) ;
if ( V_31 && V_241 ) {
if ( V_240 -> V_242 <= 100000 )
V_240 -> V_243 = 1000 ;
else if ( V_240 -> V_242 <= 400000 )
V_240 -> V_243 = 300 ;
else
V_240 -> V_243 = 120 ;
}
V_31 = F_232 ( V_38 , L_75 , & V_240 -> V_244 ) ;
if ( V_31 && V_241 ) {
if ( V_240 -> V_242 <= 400000 )
V_240 -> V_244 = 300 ;
else
V_240 -> V_244 = 120 ;
}
F_232 ( V_38 , L_76 , & V_240 -> V_245 ) ;
V_31 = F_232 ( V_38 , L_77 , & V_240 -> V_246 ) ;
if ( V_31 && V_241 )
V_240 -> V_246 = V_240 -> V_244 ;
}
int F_233 ( void * V_4 , int (* F_234)( struct V_58 * , void * ) )
{
int V_42 ;
F_156 ( & V_234 ) ;
V_42 = F_235 ( & V_61 , NULL , V_4 , F_234 ) ;
F_158 ( & V_234 ) ;
return V_42 ;
}
static int F_236 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type != & V_167 )
return 0 ;
return F_189 ( V_4 , F_115 ( V_38 ) ) ;
}
int F_237 ( struct V_247 * V_205 , struct V_115 * V_116 )
{
int V_42 ;
if ( F_203 ( ! V_223 ) )
return - V_224 ;
V_116 -> V_116 . V_205 = V_205 ;
V_116 -> V_116 . V_173 = & V_61 ;
F_12 ( & V_116 -> V_248 ) ;
V_42 = F_238 ( & V_116 -> V_116 ) ;
if ( V_42 )
return V_42 ;
F_226 ( L_78 , V_116 -> V_116 . V_112 ) ;
F_233 ( V_116 , F_236 ) ;
return 0 ;
}
static int F_239 ( struct V_58 * V_38 , void * V_4 )
{
if ( V_38 -> type == & V_167 )
F_220 ( V_4 , F_115 ( V_38 ) ) ;
return 0 ;
}
void F_240 ( struct V_115 * V_116 )
{
F_233 ( V_116 , F_239 ) ;
F_241 ( & V_116 -> V_116 ) ;
F_226 ( L_79 , V_116 -> V_116 . V_112 ) ;
}
struct V_62 * F_242 ( struct V_62 * V_67 )
{
if ( V_67 && F_243 ( & V_67 -> V_38 ) )
return V_67 ;
return NULL ;
}
void F_244 ( struct V_62 * V_67 )
{
if ( V_67 )
F_45 ( & V_67 -> V_38 ) ;
}
static int F_245 ( struct V_58 * V_38 , void * V_249 )
{
struct V_62 * V_67 = F_42 ( V_38 ) ;
struct V_250 * V_66 = V_249 ;
struct V_115 * V_116 ;
if ( ! V_67 || ! V_67 -> V_38 . V_116 )
return 0 ;
V_116 = F_75 ( V_67 -> V_38 . V_116 ) ;
if ( V_116 -> V_82 )
V_116 -> V_82 ( V_67 , V_66 -> V_71 , V_66 -> V_66 ) ;
return 0 ;
}
void F_246 ( struct V_34 * V_52 , unsigned int V_71 , void * V_66 )
{
struct V_250 V_251 ;
V_251 . V_71 = V_71 ;
V_251 . V_66 = V_66 ;
F_124 ( & V_52 -> V_38 , & V_251 , F_245 ) ;
}
static int F_247 ( struct V_63 * V_64 , unsigned long V_92 ,
void * V_66 )
{
struct V_252 * V_253 = V_66 ;
struct V_34 * V_52 ;
struct V_62 * V_67 ;
switch ( F_248 ( V_92 , V_253 ) ) {
case V_254 :
V_52 = F_183 ( V_253 -> V_255 -> V_107 ) ;
if ( V_52 == NULL )
return V_70 ;
if ( F_179 ( V_253 -> V_255 , V_176 ) ) {
F_45 ( & V_52 -> V_38 ) ;
return V_70 ;
}
V_67 = F_168 ( V_52 , V_253 -> V_255 ) ;
F_45 ( & V_52 -> V_38 ) ;
if ( F_180 ( V_67 ) ) {
F_26 ( & V_52 -> V_38 , L_80 ,
V_253 -> V_255 -> V_202 ) ;
F_141 ( V_253 -> V_255 , V_176 ) ;
return F_249 ( F_250 ( V_67 ) ) ;
}
break;
case V_256 :
if ( ! F_251 ( V_253 -> V_255 , V_176 ) )
return V_70 ;
V_67 = F_182 ( V_253 -> V_255 ) ;
if ( V_67 == NULL )
return V_70 ;
F_44 ( V_67 ) ;
F_45 ( & V_67 -> V_38 ) ;
break;
}
return V_70 ;
}
static int T_12 F_252 ( void )
{
int V_257 ;
V_257 = F_253 ( L_69 ) ;
F_254 ( & V_194 ) ;
if ( V_257 >= V_233 )
V_233 = V_257 + 1 ;
F_255 ( & V_194 ) ;
V_257 = F_256 ( & V_61 ) ;
if ( V_257 )
return V_257 ;
V_223 = true ;
#ifdef F_211
V_232 = F_257 ( L_81 ) ;
if ( ! V_232 ) {
V_257 = - V_108 ;
goto V_258;
}
#endif
V_257 = F_258 ( & V_259 ) ;
if ( V_257 )
goto V_260;
if ( F_259 ( V_261 ) )
F_203 ( F_260 ( & V_262 ) ) ;
if ( F_259 ( V_263 ) )
F_203 ( F_261 ( & V_264 ) ) ;
return 0 ;
V_260:
#ifdef F_211
F_262 ( V_232 ) ;
V_258:
#endif
V_223 = false ;
F_263 ( & V_61 ) ;
return V_257 ;
}
static void T_13 F_264 ( void )
{
if ( F_259 ( V_263 ) )
F_203 ( F_265 ( & V_264 ) ) ;
if ( F_259 ( V_261 ) )
F_203 ( F_266 ( & V_262 ) ) ;
F_240 ( & V_259 ) ;
#ifdef F_211
F_262 ( V_232 ) ;
#endif
F_263 ( & V_61 ) ;
F_267 () ;
}
static int F_268 ( struct V_34 * V_52 , struct V_73 * V_265 , char * V_266 )
{
F_269 ( & V_52 -> V_38 , L_82 ,
V_266 , V_265 -> V_12 , V_265 -> V_78 ,
V_265 -> V_25 & V_80 ? L_83 : L_84 ) ;
return - V_141 ;
}
static int F_270 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_267 )
{
const struct V_268 * V_269 = V_52 -> V_270 ;
int V_271 = V_269 -> V_272 , V_133 ;
bool V_273 = true ;
if ( V_269 -> V_25 & V_274 ) {
V_271 = 2 ;
if ( V_267 == 2 ) {
if ( V_269 -> V_25 & V_275 && V_74 [ 0 ] . V_25 & V_80 )
return F_268 ( V_52 , & V_74 [ 0 ] , L_85 ) ;
if ( V_269 -> V_25 & V_276 && ! ( V_74 [ 1 ] . V_25 & V_80 ) )
return F_268 ( V_52 , & V_74 [ 1 ] , L_86 ) ;
if ( V_269 -> V_25 & V_277 && V_74 [ 0 ] . V_12 != V_74 [ 1 ] . V_12 )
return F_268 ( V_52 , & V_74 [ 0 ] , L_87 ) ;
if ( F_271 ( V_74 [ 0 ] . V_78 , V_269 -> V_278 ) )
return F_268 ( V_52 , & V_74 [ 0 ] , L_88 ) ;
if ( F_271 ( V_74 [ 1 ] . V_78 , V_269 -> V_279 ) )
return F_268 ( V_52 , & V_74 [ 1 ] , L_88 ) ;
V_273 = false ;
}
}
if ( F_271 ( V_267 , V_271 ) )
return F_268 ( V_52 , & V_74 [ 0 ] , L_89 ) ;
for ( V_133 = 0 ; V_133 < V_267 ; V_133 ++ ) {
T_8 V_78 = V_74 [ V_133 ] . V_78 ;
if ( V_74 [ V_133 ] . V_25 & V_80 ) {
if ( V_273 && F_271 ( V_78 , V_269 -> V_280 ) )
return F_268 ( V_52 , & V_74 [ V_133 ] , L_88 ) ;
} else {
if ( V_273 && F_271 ( V_78 , V_269 -> V_281 ) )
return F_268 ( V_52 , & V_74 [ V_133 ] , L_88 ) ;
}
}
return 0 ;
}
int F_272 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_267 )
{
unsigned long V_282 ;
int V_31 , V_283 ;
if ( V_52 -> V_270 && F_270 ( V_52 , V_74 , V_267 ) )
return - V_141 ;
if ( F_273 ( & V_1 ) ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_267 ; V_133 ++ )
if ( V_74 [ V_133 ] . V_25 & V_80 )
F_274 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
else
F_275 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
}
V_282 = V_284 ;
for ( V_31 = 0 , V_283 = 0 ; V_283 <= V_52 -> V_285 ; V_283 ++ ) {
V_31 = V_52 -> V_226 -> V_286 ( V_52 , V_74 , V_267 ) ;
if ( V_31 != - V_224 )
break;
if ( F_276 ( V_284 , V_282 + V_52 -> V_230 ) )
break;
}
if ( F_273 ( & V_1 ) ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_31 ; V_133 ++ )
if ( V_74 [ V_133 ] . V_25 & V_80 )
F_277 ( V_52 , & V_74 [ V_133 ] , V_133 ) ;
F_278 ( V_52 , V_133 , V_31 ) ;
}
return V_31 ;
}
int F_48 ( struct V_34 * V_52 , struct V_73 * V_74 , int V_267 )
{
int V_31 ;
if ( V_52 -> V_226 -> V_286 ) {
#ifdef F_279
for ( V_31 = 0 ; V_31 < V_267 ; V_31 ++ ) {
F_94 ( & V_52 -> V_38 ,
L_90 ,
V_31 , ( V_74 [ V_31 ] . V_25 & V_80 ) ? 'R' : 'W' ,
V_74 [ V_31 ] . V_12 , V_74 [ V_31 ] . V_78 ,
( V_74 [ V_31 ] . V_25 & V_287 ) ? L_91 : L_92 ) ;
}
#endif
if ( F_280 () || F_281 () ) {
V_31 = F_282 ( V_52 , V_288 ) ;
if ( ! V_31 )
return - V_224 ;
} else {
F_283 ( V_52 , V_288 ) ;
}
V_31 = F_272 ( V_52 , V_74 , V_267 ) ;
F_284 ( V_52 , V_288 ) ;
return V_31 ;
} else {
F_94 ( & V_52 -> V_38 , L_93 ) ;
return - V_141 ;
}
}
int F_285 ( const struct V_62 * V_67 , const char * V_79 , int V_184 )
{
int V_31 ;
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_265 ;
V_265 . V_12 = V_67 -> V_12 ;
V_265 . V_25 = V_67 -> V_25 & V_289 ;
V_265 . V_78 = V_184 ;
V_265 . V_79 = ( char * ) V_79 ;
V_31 = F_48 ( V_52 , & V_265 , 1 ) ;
return ( V_31 == 1 ) ? V_184 : V_31 ;
}
int F_286 ( const struct V_62 * V_67 , char * V_79 , int V_184 )
{
struct V_34 * V_52 = V_67 -> V_35 ;
struct V_73 V_265 ;
int V_31 ;
V_265 . V_12 = V_67 -> V_12 ;
V_265 . V_25 = V_67 -> V_25 & V_289 ;
V_265 . V_25 |= V_80 ;
V_265 . V_78 = V_184 ;
V_265 . V_79 = V_79 ;
V_31 = F_48 ( V_52 , & V_265 , 1 ) ;
return ( V_31 == 1 ) ? V_184 : V_31 ;
}
static int F_287 ( struct V_34 * V_52 , unsigned short V_12 )
{
int V_96 ;
union V_290 V_59 ;
#ifdef F_288
if ( V_12 == 0x73 && ( V_52 -> V_291 & V_292 )
&& F_198 ( V_52 , V_293 ) )
V_96 = F_289 ( V_52 , V_12 , 0 , V_294 , 0 ,
V_295 , & V_59 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_198 ( V_52 , V_296 ) )
V_96 = F_289 ( V_52 , V_12 , 0 , V_297 , 0 ,
V_298 , NULL ) ;
else if ( F_198 ( V_52 , V_299 ) )
V_96 = F_289 ( V_52 , V_12 , 0 , V_294 , 0 ,
V_300 , & V_59 ) ;
else {
F_32 ( & V_52 -> V_38 , L_94 ,
V_12 ) ;
V_96 = - V_141 ;
}
return V_96 >= 0 ;
}
static int F_290 ( struct V_62 * V_301 ,
struct V_115 * V_116 )
{
struct V_7 V_8 ;
struct V_34 * V_35 = V_301 -> V_35 ;
int V_12 = V_301 -> V_12 ;
int V_96 ;
V_96 = F_120 ( V_12 ) ;
if ( V_96 ) {
F_32 ( & V_35 -> V_38 , L_95 ,
V_12 ) ;
return V_96 ;
}
if ( F_126 ( V_35 , V_12 ) )
return 0 ;
if ( ! F_287 ( V_35 , V_12 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_12 = V_12 ;
V_96 = V_116 -> V_302 ( V_301 , & V_8 ) ;
if ( V_96 ) {
return V_96 == - V_39 ? 0 : V_96 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_26 ( & V_35 -> V_38 ,
L_96 ,
V_116 -> V_116 . V_112 , V_12 ) ;
} else {
struct V_62 * V_67 ;
if ( V_35 -> V_291 & V_303 )
F_32 ( & V_35 -> V_38 ,
L_97
L_98
L_99 ,
V_8 . V_12 ) ;
F_94 ( & V_35 -> V_38 , L_100 ,
V_8 . type , V_8 . V_12 ) ;
V_67 = F_25 ( V_35 , & V_8 ) ;
if ( V_67 )
F_157 ( & V_67 -> V_189 , & V_116 -> V_248 ) ;
else
F_26 ( & V_35 -> V_38 , L_101 ,
V_8 . type , V_8 . V_12 ) ;
}
return 0 ;
}
static int F_190 ( struct V_34 * V_35 , struct V_115 * V_116 )
{
const unsigned short * V_304 ;
struct V_62 * V_301 ;
int V_133 , V_96 = 0 ;
int V_305 = F_136 ( V_35 ) ;
V_304 = V_116 -> V_304 ;
if ( ! V_116 -> V_302 || ! V_304 )
return 0 ;
if ( V_35 -> V_291 == V_303 ) {
F_94 ( & V_35 -> V_38 ,
L_102
L_103 ,
V_116 -> V_116 . V_112 ) ;
return 0 ;
}
if ( ! ( V_35 -> V_291 & V_116 -> V_291 ) )
return 0 ;
V_301 = F_47 ( sizeof( struct V_62 ) , V_76 ) ;
if ( ! V_301 )
return - V_108 ;
V_301 -> V_35 = V_35 ;
for ( V_133 = 0 ; V_304 [ V_133 ] != V_306 ; V_133 += 1 ) {
F_94 ( & V_35 -> V_38 ,
L_104 ,
V_305 , V_304 [ V_133 ] ) ;
V_301 -> V_12 = V_304 [ V_133 ] ;
V_96 = F_290 ( V_301 , V_116 ) ;
if ( F_291 ( V_96 ) )
break;
}
F_50 ( V_301 ) ;
return V_96 ;
}
int F_292 ( struct V_34 * V_52 , unsigned short V_12 )
{
return F_289 ( V_52 , V_12 , 0 , V_294 , 0 ,
V_298 , NULL ) >= 0 ;
}
struct V_62 *
F_293 ( struct V_34 * V_52 ,
struct V_7 * V_8 ,
unsigned short const * V_307 ,
int (* V_155)( struct V_34 * , unsigned short V_12 ) )
{
int V_133 ;
if ( ! V_155 )
V_155 = F_287 ;
for ( V_133 = 0 ; V_307 [ V_133 ] != V_306 ; V_133 ++ ) {
if ( F_120 ( V_307 [ V_133 ] ) < 0 ) {
F_32 ( & V_52 -> V_38 , L_105 ,
V_307 [ V_133 ] ) ;
continue;
}
if ( F_126 ( V_52 , V_307 [ V_133 ] ) ) {
F_94 ( & V_52 -> V_38 ,
L_106 ,
V_307 [ V_133 ] ) ;
continue;
}
if ( V_155 ( V_52 , V_307 [ V_133 ] ) )
break;
}
if ( V_307 [ V_133 ] == V_306 ) {
F_94 ( & V_52 -> V_38 , L_107 ) ;
return NULL ;
}
V_8 -> V_12 = V_307 [ V_133 ] ;
return F_25 ( V_52 , V_8 ) ;
}
struct V_34 * F_294 ( int V_196 )
{
struct V_34 * V_35 ;
F_156 ( & V_234 ) ;
V_35 = F_225 ( & V_235 , V_196 ) ;
if ( ! V_35 )
goto exit;
if ( F_185 ( V_35 -> V_205 ) )
F_243 ( & V_35 -> V_38 ) ;
else
V_35 = NULL ;
exit:
F_158 ( & V_234 ) ;
return V_35 ;
}
void F_295 ( struct V_34 * V_52 )
{
if ( ! V_52 )
return;
F_45 ( & V_52 -> V_38 ) ;
F_296 ( V_52 -> V_205 ) ;
}
static T_4 F_297 ( T_8 V_4 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < 8 ; V_133 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_308 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_298 ( T_4 V_309 , T_4 * V_310 , T_9 V_184 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_184 ; V_133 ++ )
V_309 = F_297 ( ( V_309 ^ V_310 [ V_133 ] ) << 8 ) ;
return V_309 ;
}
static T_4 F_299 ( T_4 V_311 , struct V_73 * V_265 )
{
T_4 V_12 = F_300 ( V_265 ) ;
V_311 = F_298 ( V_311 , & V_12 , 1 ) ;
return F_298 ( V_311 , V_265 -> V_79 , V_265 -> V_78 ) ;
}
static inline void F_301 ( struct V_73 * V_265 )
{
V_265 -> V_79 [ V_265 -> V_78 ] = F_299 ( 0 , V_265 ) ;
V_265 -> V_78 ++ ;
}
static int F_302 ( T_4 V_312 , struct V_73 * V_265 )
{
T_4 V_313 = V_265 -> V_79 [ -- V_265 -> V_78 ] ;
V_312 = F_299 ( V_312 , V_265 ) ;
if ( V_313 != V_312 ) {
F_226 ( L_108 ,
V_313 , V_312 ) ;
return - V_314 ;
}
return 0 ;
}
T_14 F_54 ( const struct V_62 * V_67 )
{
union V_290 V_4 ;
int V_11 ;
V_11 = F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_294 , 0 ,
V_300 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_315 ;
}
T_14 F_55 ( const struct V_62 * V_67 , T_4 V_65 )
{
return F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_297 , V_65 , V_300 , NULL ) ;
}
T_14 F_56 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_290 V_4 ;
int V_11 ;
V_11 = F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_294 , V_82 ,
V_295 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_315 ;
}
T_14 F_57 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_65 )
{
union V_290 V_4 ;
V_4 . V_315 = V_65 ;
return F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_297 , V_82 ,
V_295 , & V_4 ) ;
}
T_14 F_58 ( const struct V_62 * V_67 , T_4 V_82 )
{
union V_290 V_4 ;
int V_11 ;
V_11 = F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_294 , V_82 ,
V_316 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_317 ;
}
T_14 F_59 ( const struct V_62 * V_67 , T_4 V_82 ,
T_8 V_65 )
{
union V_290 V_4 ;
V_4 . V_317 = V_65 ;
return F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_297 , V_82 ,
V_316 , & V_4 ) ;
}
T_14 F_60 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 * V_318 )
{
union V_290 V_4 ;
int V_11 ;
V_11 = F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_294 , V_82 ,
V_319 , & V_4 ) ;
if ( V_11 )
return V_11 ;
memcpy ( V_318 , & V_4 . V_320 [ 1 ] , V_4 . V_320 [ 0 ] ) ;
return V_4 . V_320 [ 0 ] ;
}
T_14 F_61 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_318 )
{
union V_290 V_4 ;
if ( V_95 > V_321 )
V_95 = V_321 ;
V_4 . V_320 [ 0 ] = V_95 ;
memcpy ( & V_4 . V_320 [ 1 ] , V_318 , V_95 ) ;
return F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_297 , V_82 ,
V_319 , & V_4 ) ;
}
T_14 F_303 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , T_4 * V_318 )
{
union V_290 V_4 ;
int V_11 ;
if ( V_95 > V_321 )
V_95 = V_321 ;
V_4 . V_320 [ 0 ] = V_95 ;
V_11 = F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_294 , V_82 ,
V_322 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_318 , & V_4 . V_320 [ 1 ] , V_4 . V_320 [ 0 ] ) ;
return V_4 . V_320 [ 0 ] ;
}
T_14 F_304 ( const struct V_62 * V_67 , T_4 V_82 ,
T_4 V_95 , const T_4 * V_318 )
{
union V_290 V_4 ;
if ( V_95 > V_321 )
V_95 = V_321 ;
V_4 . V_320 [ 0 ] = V_95 ;
memcpy ( V_4 . V_320 + 1 , V_318 , V_95 ) ;
return F_289 ( V_67 -> V_35 , V_67 -> V_12 , V_67 -> V_25 ,
V_297 , V_82 ,
V_322 , & V_4 ) ;
}
static T_14 F_305 ( struct V_34 * V_35 , T_8 V_12 ,
unsigned short V_25 ,
char V_323 , T_4 V_82 , int V_324 ,
union V_290 * V_4 )
{
unsigned char V_325 [ V_321 + 3 ] ;
unsigned char V_326 [ V_321 + 2 ] ;
int V_267 = V_323 == V_294 ? 2 : 1 ;
int V_133 ;
T_4 V_327 = 0 ;
int V_11 ;
struct V_73 V_265 [ 2 ] = {
{
. V_12 = V_12 ,
. V_25 = V_25 ,
. V_78 = 1 ,
. V_79 = V_325 ,
} , {
. V_12 = V_12 ,
. V_25 = V_25 | V_80 ,
. V_78 = 0 ,
. V_79 = V_326 ,
} ,
} ;
V_325 [ 0 ] = V_82 ;
switch ( V_324 ) {
case V_298 :
V_265 [ 0 ] . V_78 = 0 ;
V_265 [ 0 ] . V_25 = V_25 | ( V_323 == V_294 ?
V_80 : 0 ) ;
V_267 = 1 ;
break;
case V_300 :
if ( V_323 == V_294 ) {
V_265 [ 0 ] . V_25 = V_80 | V_25 ;
V_267 = 1 ;
}
break;
case V_295 :
if ( V_323 == V_294 )
V_265 [ 1 ] . V_78 = 1 ;
else {
V_265 [ 0 ] . V_78 = 2 ;
V_325 [ 1 ] = V_4 -> V_315 ;
}
break;
case V_316 :
if ( V_323 == V_294 )
V_265 [ 1 ] . V_78 = 2 ;
else {
V_265 [ 0 ] . V_78 = 3 ;
V_325 [ 1 ] = V_4 -> V_317 & 0xff ;
V_325 [ 2 ] = V_4 -> V_317 >> 8 ;
}
break;
case V_328 :
V_267 = 2 ;
V_323 = V_294 ;
V_265 [ 0 ] . V_78 = 3 ;
V_265 [ 1 ] . V_78 = 2 ;
V_325 [ 1 ] = V_4 -> V_317 & 0xff ;
V_325 [ 2 ] = V_4 -> V_317 >> 8 ;
break;
case V_319 :
if ( V_323 == V_294 ) {
V_265 [ 1 ] . V_25 |= V_287 ;
V_265 [ 1 ] . V_78 = 1 ;
} else {
V_265 [ 0 ] . V_78 = V_4 -> V_320 [ 0 ] + 2 ;
if ( V_265 [ 0 ] . V_78 > V_321 + 2 ) {
F_26 ( & V_35 -> V_38 ,
L_109 ,
V_4 -> V_320 [ 0 ] ) ;
return - V_33 ;
}
for ( V_133 = 1 ; V_133 < V_265 [ 0 ] . V_78 ; V_133 ++ )
V_325 [ V_133 ] = V_4 -> V_320 [ V_133 - 1 ] ;
}
break;
case V_329 :
V_267 = 2 ;
V_323 = V_294 ;
if ( V_4 -> V_320 [ 0 ] > V_321 ) {
F_26 ( & V_35 -> V_38 ,
L_109 ,
V_4 -> V_320 [ 0 ] ) ;
return - V_33 ;
}
V_265 [ 0 ] . V_78 = V_4 -> V_320 [ 0 ] + 2 ;
for ( V_133 = 1 ; V_133 < V_265 [ 0 ] . V_78 ; V_133 ++ )
V_325 [ V_133 ] = V_4 -> V_320 [ V_133 - 1 ] ;
V_265 [ 1 ] . V_25 |= V_287 ;
V_265 [ 1 ] . V_78 = 1 ;
break;
case V_322 :
if ( V_323 == V_294 ) {
V_265 [ 1 ] . V_78 = V_4 -> V_320 [ 0 ] ;
} else {
V_265 [ 0 ] . V_78 = V_4 -> V_320 [ 0 ] + 1 ;
if ( V_265 [ 0 ] . V_78 > V_321 + 1 ) {
F_26 ( & V_35 -> V_38 ,
L_109 ,
V_4 -> V_320 [ 0 ] ) ;
return - V_33 ;
}
for ( V_133 = 1 ; V_133 <= V_4 -> V_320 [ 0 ] ; V_133 ++ )
V_325 [ V_133 ] = V_4 -> V_320 [ V_133 ] ;
}
break;
default:
F_26 ( & V_35 -> V_38 , L_110 , V_324 ) ;
return - V_141 ;
}
V_133 = ( ( V_25 & V_330 ) && V_324 != V_298
&& V_324 != V_322 ) ;
if ( V_133 ) {
if ( ! ( V_265 [ 0 ] . V_25 & V_80 ) ) {
if ( V_267 == 1 )
F_301 ( & V_265 [ 0 ] ) ;
else
V_327 = F_299 ( 0 , & V_265 [ 0 ] ) ;
}
if ( V_265 [ V_267 - 1 ] . V_25 & V_80 )
V_265 [ V_267 - 1 ] . V_78 ++ ;
}
V_11 = F_48 ( V_35 , V_265 , V_267 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_133 && ( V_265 [ V_267 - 1 ] . V_25 & V_80 ) ) {
V_11 = F_302 ( V_327 , & V_265 [ V_267 - 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_323 == V_294 )
switch ( V_324 ) {
case V_300 :
V_4 -> V_315 = V_325 [ 0 ] ;
break;
case V_295 :
V_4 -> V_315 = V_326 [ 0 ] ;
break;
case V_316 :
case V_328 :
V_4 -> V_317 = V_326 [ 0 ] | ( V_326 [ 1 ] << 8 ) ;
break;
case V_322 :
for ( V_133 = 0 ; V_133 < V_4 -> V_320 [ 0 ] ; V_133 ++ )
V_4 -> V_320 [ V_133 + 1 ] = V_326 [ V_133 ] ;
break;
case V_319 :
case V_329 :
for ( V_133 = 0 ; V_133 < V_326 [ 0 ] + 1 ; V_133 ++ )
V_4 -> V_320 [ V_133 ] = V_326 [ V_133 ] ;
break;
}
return 0 ;
}
T_14 F_289 ( struct V_34 * V_35 , T_8 V_12 , unsigned short V_25 ,
char V_323 , T_4 V_82 , int V_331 ,
union V_290 * V_4 )
{
unsigned long V_282 ;
int V_283 ;
T_14 V_42 ;
F_306 ( V_35 , V_12 , V_25 , V_323 ,
V_82 , V_331 , V_4 ) ;
F_307 ( V_35 , V_12 , V_25 , V_323 ,
V_82 , V_331 ) ;
V_25 &= V_289 | V_330 | V_332 ;
if ( V_35 -> V_226 -> V_333 ) {
F_283 ( V_35 , V_288 ) ;
V_282 = V_284 ;
for ( V_42 = 0 , V_283 = 0 ; V_283 <= V_35 -> V_285 ; V_283 ++ ) {
V_42 = V_35 -> V_226 -> V_333 ( V_35 , V_12 , V_25 ,
V_323 , V_82 ,
V_331 , V_4 ) ;
if ( V_42 != - V_224 )
break;
if ( F_276 ( V_284 ,
V_282 + V_35 -> V_230 ) )
break;
}
F_284 ( V_35 , V_288 ) ;
if ( V_42 != - V_141 || ! V_35 -> V_226 -> V_286 )
goto V_334;
}
V_42 = F_305 ( V_35 , V_12 , V_25 , V_323 ,
V_82 , V_331 , V_4 ) ;
V_334:
F_308 ( V_35 , V_12 , V_25 , V_323 ,
V_82 , V_331 , V_4 ) ;
F_309 ( V_35 , V_12 , V_25 , V_323 ,
V_82 , V_331 , V_42 ) ;
return V_42 ;
}
T_14 F_310 ( const struct V_62 * V_67 ,
T_4 V_82 , T_4 V_95 , T_4 * V_318 )
{
T_4 V_133 = 0 ;
int V_11 ;
if ( V_95 > V_321 )
V_95 = V_321 ;
if ( F_198 ( V_67 -> V_35 , V_335 ) )
return F_303 ( V_67 , V_82 , V_95 , V_318 ) ;
if ( ! F_198 ( V_67 -> V_35 , V_293 ) )
return - V_141 ;
if ( F_198 ( V_67 -> V_35 , V_336 ) ) {
while ( ( V_133 + 2 ) <= V_95 ) {
V_11 = F_58 ( V_67 , V_82 + V_133 ) ;
if ( V_11 < 0 )
return V_11 ;
V_318 [ V_133 ] = V_11 & 0xff ;
V_318 [ V_133 + 1 ] = V_11 >> 8 ;
V_133 += 2 ;
}
}
while ( V_133 < V_95 ) {
V_11 = F_56 ( V_67 , V_82 + V_133 ) ;
if ( V_11 < 0 )
return V_11 ;
V_318 [ V_133 ] = V_11 ;
V_133 ++ ;
}
return V_133 ;
}
int F_311 ( struct V_62 * V_67 , T_15 V_337 )
{
int V_31 ;
if ( ! V_67 || ! V_337 ) {
F_204 ( 1 , L_111 ) ;
return - V_33 ;
}
if ( ! ( V_67 -> V_25 & V_163 ) )
F_32 ( & V_67 -> V_38 , L_112 ,
V_338 ) ;
if ( ! ( V_67 -> V_25 & V_26 ) ) {
V_31 = F_120 ( V_67 -> V_12 ) ;
if ( V_31 ) {
F_26 ( & V_67 -> V_38 , L_113 , V_338 ) ;
return V_31 ;
}
}
if ( ! V_67 -> V_35 -> V_226 -> V_339 ) {
F_26 ( & V_67 -> V_38 , L_114 , V_338 ) ;
return - V_141 ;
}
V_67 -> V_337 = V_337 ;
F_312 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_226 -> V_339 ( V_67 ) ;
F_313 ( V_67 -> V_35 ) ;
if ( V_31 ) {
V_67 -> V_337 = NULL ;
F_26 ( & V_67 -> V_38 , L_115 , V_338 , V_31 ) ;
}
return V_31 ;
}
int F_314 ( struct V_62 * V_67 )
{
int V_31 ;
if ( ! V_67 -> V_35 -> V_226 -> V_340 ) {
F_26 ( & V_67 -> V_38 , L_114 , V_338 ) ;
return - V_141 ;
}
F_312 ( V_67 -> V_35 ) ;
V_31 = V_67 -> V_35 -> V_226 -> V_340 ( V_67 ) ;
F_313 ( V_67 -> V_35 ) ;
if ( V_31 == 0 )
V_67 -> V_337 = NULL ;
else
F_26 ( & V_67 -> V_38 , L_115 , V_338 , V_31 ) ;
return V_31 ;
}
bool F_315 ( struct V_58 * V_38 )
{
if ( F_316 ( V_341 ) && V_38 -> V_148 ) {
struct V_179 * V_342 ;
T_3 V_343 ;
F_317 (dev->of_node, child) {
F_318 ( V_342 , L_35 , & V_343 ) ;
if ( V_343 & V_204 ) {
F_175 ( V_342 ) ;
return true ;
}
}
} else if ( F_316 ( V_263 ) && F_16 ( V_38 ) ) {
F_94 ( V_38 , L_116 ) ;
}
return false ;
}
