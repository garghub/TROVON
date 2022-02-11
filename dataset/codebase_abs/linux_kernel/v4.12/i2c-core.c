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
if ( V_6 -> V_16 != - 1 && V_6 -> V_17 ++ != V_6 -> V_16 )
return 1 ;
V_11 = F_6 ( V_6 -> V_18 ,
V_10 -> V_19 . V_20 ,
& V_6 -> V_21 ) ;
if ( ! F_7 ( V_11 ) )
return 1 ;
V_8 -> V_12 = V_10 -> V_22 ;
V_6 -> V_23 = V_10 -> V_24 ;
if ( V_10 -> V_25 == V_26 )
V_8 -> V_27 |= V_28 ;
return 1 ;
}
static int F_8 ( struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_31 V_32 ;
int V_33 ;
if ( F_9 ( V_30 ) || ! V_30 -> V_11 . V_34 ||
F_10 ( V_30 ) )
return - V_35 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 -> V_18 = F_11 ( V_30 ) ;
F_12 ( & V_32 ) ;
V_33 = F_13 ( V_30 , & V_32 ,
F_5 , V_6 ) ;
F_14 ( & V_32 ) ;
if ( V_33 < 0 || ! V_8 -> V_12 )
return - V_35 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_7 * V_8 ,
struct V_36 * V_37 ,
T_2 * V_21 )
{
struct V_31 V_32 ;
struct V_38 * V_39 ;
struct V_5 V_6 ;
int V_33 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_8 = V_8 ;
V_6 . V_16 = - 1 ;
V_33 = F_8 ( V_30 , & V_6 ) ;
if ( V_33 )
return V_33 ;
if ( V_37 ) {
if ( F_16 ( & V_37 -> V_40 ) != V_6 . V_21 )
return - V_41 ;
} else {
struct V_29 * V_42 ;
if ( F_17 ( V_6 . V_21 , & V_42 ) )
return - V_41 ;
if ( F_9 ( V_42 ) ||
! V_42 -> V_11 . V_34 )
return - V_41 ;
}
V_8 -> V_43 = F_18 ( V_30 ) ;
if ( V_21 )
* V_21 = V_6 . V_21 ;
F_12 ( & V_32 ) ;
V_33 = F_13 ( V_30 , & V_32 , NULL , NULL ) ;
if ( V_33 < 0 )
return - V_35 ;
F_19 (entry, &resource_list) {
if ( F_20 ( V_39 -> V_44 ) == V_45 ) {
V_8 -> V_46 = V_39 -> V_44 -> V_47 ;
break;
}
}
F_14 ( & V_32 ) ;
F_21 ( V_30 , F_22 ( & V_30 -> V_40 ) , V_8 -> type ,
sizeof( V_8 -> type ) ) ;
return 0 ;
}
static void F_23 ( struct V_36 * V_37 ,
struct V_29 * V_30 ,
struct V_7 * V_8 )
{
V_30 -> V_48 . V_27 . V_49 = true ;
F_24 ( V_30 ) ;
if ( ! F_25 ( V_37 , V_8 ) ) {
V_30 -> V_48 . V_27 . V_49 = false ;
F_26 ( & V_37 -> V_40 ,
L_1 ,
F_22 ( & V_30 -> V_40 ) ) ;
}
}
static T_1 F_27 ( T_2 V_50 , T_3 V_51 ,
void * V_4 , void * * V_52 )
{
struct V_36 * V_37 = V_4 ;
struct V_29 * V_30 ;
struct V_7 V_8 ;
if ( F_17 ( V_50 , & V_30 ) )
return V_53 ;
if ( F_15 ( V_30 , & V_8 , V_37 , NULL ) )
return V_53 ;
F_23 ( V_37 , V_30 , & V_8 ) ;
return V_53 ;
}
static void F_28 ( struct V_36 * V_54 )
{
T_1 V_11 ;
if ( ! F_29 ( & V_54 -> V_40 ) )
return;
V_11 = F_30 ( V_55 , V_56 ,
V_57 ,
F_27 , NULL ,
V_54 , NULL ) ;
if ( F_31 ( V_11 ) )
F_32 ( & V_54 -> V_40 , L_2 ) ;
}
static T_1 F_33 ( T_2 V_50 , T_3 V_51 ,
void * V_4 , void * * V_52 )
{
struct V_5 * V_6 = V_4 ;
struct V_29 * V_30 ;
if ( F_17 ( V_50 , & V_30 ) )
return V_53 ;
if ( F_8 ( V_30 , V_6 ) )
return V_53 ;
if ( V_6 -> V_58 != V_6 -> V_21 )
return V_53 ;
if ( V_6 -> V_23 <= V_6 -> V_59 )
V_6 -> V_59 = V_6 -> V_23 ;
return V_53 ;
}
T_3 F_34 ( struct V_60 * V_40 )
{
struct V_5 V_6 ;
struct V_7 V_61 ;
T_1 V_11 ;
if ( ! F_29 ( V_40 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_58 = F_16 ( V_40 ) ;
V_6 . V_59 = V_62 ;
V_6 . V_8 = & V_61 ;
V_6 . V_16 = - 1 ;
V_11 = F_30 ( V_55 , V_56 ,
V_57 ,
F_33 , NULL ,
& V_6 , NULL ) ;
if ( F_31 ( V_11 ) ) {
F_32 ( V_40 , L_3 ) ;
return 0 ;
}
return V_6 . V_59 != V_62 ? V_6 . V_59 : 0 ;
}
static int F_35 ( struct V_60 * V_40 , void * V_4 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
if ( ! V_37 )
return 0 ;
return F_16 ( V_40 ) == ( T_2 ) V_4 ;
}
static int F_37 ( struct V_60 * V_40 , void * V_4 )
{
return F_38 ( V_40 ) == V_4 ;
}
static struct V_36 * F_39 ( T_2 V_50 )
{
struct V_60 * V_40 ;
V_40 = F_40 ( & V_63 , NULL , V_50 ,
F_35 ) ;
return V_40 ? F_36 ( V_40 ) : NULL ;
}
static struct V_64 * F_41 ( struct V_29 * V_30 )
{
struct V_60 * V_40 ;
V_40 = F_40 ( & V_63 , NULL , V_30 , F_37 ) ;
return V_40 ? F_42 ( V_40 ) : NULL ;
}
static int F_43 ( struct V_65 * V_66 , unsigned long V_67 ,
void * V_68 )
{
struct V_29 * V_30 = V_68 ;
struct V_7 V_8 ;
T_2 V_21 ;
struct V_36 * V_37 ;
struct V_64 * V_69 ;
switch ( V_67 ) {
case V_70 :
if ( F_15 ( V_30 , & V_8 , NULL , & V_21 ) )
break;
V_37 = F_39 ( V_21 ) ;
if ( ! V_37 )
break;
F_23 ( V_37 , V_30 , & V_8 ) ;
break;
case V_71 :
if ( ! F_10 ( V_30 ) )
break;
V_69 = F_41 ( V_30 ) ;
if ( ! V_69 )
break;
F_44 ( V_69 ) ;
F_45 ( & V_69 -> V_40 ) ;
break;
}
return V_72 ;
}
struct V_64 * F_46 ( struct V_60 * V_40 , int V_16 ,
struct V_7 * V_8 )
{
struct V_5 V_6 ;
struct V_36 * V_37 ;
struct V_29 * V_30 ;
F_47 ( V_32 ) ;
int V_33 ;
V_30 = F_38 ( V_40 ) ;
if ( ! V_30 )
return NULL ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_8 = V_8 ;
V_6 . V_18 = F_11 ( V_30 ) ;
V_6 . V_16 = V_16 ;
V_33 = F_13 ( V_30 , & V_32 ,
F_5 , & V_6 ) ;
F_14 ( & V_32 ) ;
if ( V_33 < 0 || ! V_8 -> V_12 )
return NULL ;
V_37 = F_39 ( V_6 . V_21 ) ;
if ( ! V_37 )
return NULL ;
return F_25 ( V_37 , V_8 ) ;
}
static inline void F_28 ( struct V_36 * V_54 ) { }
static int F_48 ( struct V_64 * V_69 ,
T_4 V_73 , T_4 * V_4 , T_4 V_74 )
{
struct V_75 V_76 [ 2 ] ;
int V_33 ;
T_4 * V_77 ;
V_77 = F_49 ( V_74 , V_78 ) ;
if ( ! V_77 )
return V_79 ;
V_76 [ 0 ] . V_12 = V_69 -> V_12 ;
V_76 [ 0 ] . V_27 = V_69 -> V_27 ;
V_76 [ 0 ] . V_80 = 1 ;
V_76 [ 0 ] . V_81 = & V_73 ;
V_76 [ 1 ] . V_12 = V_69 -> V_12 ;
V_76 [ 1 ] . V_27 = V_69 -> V_27 | V_82 ;
V_76 [ 1 ] . V_80 = V_74 ;
V_76 [ 1 ] . V_81 = V_77 ;
V_33 = F_50 ( V_69 -> V_37 , V_76 , F_51 ( V_76 ) ) ;
if ( V_33 < 0 )
F_26 ( & V_69 -> V_37 -> V_40 , L_4 ) ;
else
memcpy ( V_4 , V_77 , V_74 ) ;
F_52 ( V_77 ) ;
return V_33 ;
}
static int F_53 ( struct V_64 * V_69 ,
T_4 V_73 , T_4 * V_4 , T_4 V_74 )
{
struct V_75 V_76 [ 1 ] ;
T_4 * V_77 ;
int V_33 = V_53 ;
V_77 = F_49 ( V_74 + 1 , V_78 ) ;
if ( ! V_77 )
return V_79 ;
V_77 [ 0 ] = V_73 ;
memcpy ( V_77 + 1 , V_4 , V_74 ) ;
V_76 [ 0 ] . V_12 = V_69 -> V_12 ;
V_76 [ 0 ] . V_27 = V_69 -> V_27 ;
V_76 [ 0 ] . V_80 = V_74 + 1 ;
V_76 [ 0 ] . V_81 = V_77 ;
V_33 = F_50 ( V_69 -> V_37 , V_76 , F_51 ( V_76 ) ) ;
if ( V_33 < 0 )
F_26 ( & V_69 -> V_37 -> V_40 , L_5 ) ;
F_52 ( V_77 ) ;
return V_33 ;
}
static T_1
F_54 ( T_3 V_83 , T_5 V_84 ,
T_3 V_85 , T_6 * V_86 ,
void * V_87 , void * V_88 )
{
struct V_89 * V_90 = (struct V_89 * ) V_86 ;
struct V_91 * V_4 = V_87 ;
struct V_92 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_64 * V_69 ;
struct V_2 * V_3 ;
T_3 V_93 = V_83 >> 16 ;
T_4 V_94 = V_83 & V_95 ;
T_1 V_33 ;
int V_11 ;
V_33 = F_55 ( V_8 -> V_96 , V_8 -> V_97 , & V_3 ) ;
if ( F_31 ( V_33 ) )
return V_33 ;
V_69 = F_49 ( sizeof( * V_69 ) , V_78 ) ;
if ( ! V_69 ) {
V_33 = V_79 ;
goto V_98;
}
if ( ! V_86 || V_3 -> type != V_13 ) {
V_33 = V_99 ;
goto V_98;
}
V_10 = & V_3 -> V_4 . V_14 ;
if ( V_10 -> type != V_15 ) {
V_33 = V_99 ;
goto V_98;
}
V_69 -> V_37 = V_37 ;
V_69 -> V_12 = V_10 -> V_22 ;
if ( V_10 -> V_25 == V_26 )
V_69 -> V_27 |= V_28 ;
switch ( V_93 ) {
case V_100 :
if ( V_94 == V_101 ) {
V_11 = F_56 ( V_69 ) ;
if ( V_11 >= 0 ) {
V_90 -> V_102 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_57 ( V_69 , V_90 -> V_102 ) ;
}
break;
case V_103 :
if ( V_94 == V_101 ) {
V_11 = F_58 ( V_69 , V_84 ) ;
if ( V_11 >= 0 ) {
V_90 -> V_102 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_59 ( V_69 , V_84 ,
V_90 -> V_102 ) ;
}
break;
case V_104 :
if ( V_94 == V_101 ) {
V_11 = F_60 ( V_69 , V_84 ) ;
if ( V_11 >= 0 ) {
V_90 -> V_105 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_61 ( V_69 , V_84 ,
V_90 -> V_105 ) ;
}
break;
case V_106 :
if ( V_94 == V_101 ) {
V_11 = F_62 ( V_69 , V_84 ,
V_90 -> V_4 ) ;
if ( V_11 >= 0 ) {
V_90 -> V_80 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_63 ( V_69 , V_84 ,
V_90 -> V_80 , V_90 -> V_4 ) ;
}
break;
case V_107 :
if ( V_94 == V_101 ) {
V_11 = F_48 ( V_69 , V_84 ,
V_90 -> V_4 , V_8 -> V_108 ) ;
if ( V_11 > 0 )
V_11 = 0 ;
} else {
V_11 = F_53 ( V_69 , V_84 ,
V_90 -> V_4 , V_8 -> V_108 ) ;
}
break;
default:
F_32 ( & V_37 -> V_40 , L_6 ,
V_93 , V_69 -> V_12 ) ;
V_33 = V_99 ;
goto V_98;
}
V_90 -> V_11 = V_11 ;
V_98:
F_52 ( V_69 ) ;
F_64 ( V_3 ) ;
return V_33 ;
}
static int F_65 ( struct V_36 * V_37 )
{
T_2 V_50 ;
struct V_91 * V_4 ;
T_1 V_11 ;
if ( ! V_37 -> V_40 . V_109 )
return - V_41 ;
V_50 = F_16 ( V_37 -> V_40 . V_109 ) ;
if ( ! V_50 )
return - V_41 ;
V_4 = F_49 ( sizeof( struct V_91 ) ,
V_78 ) ;
if ( ! V_4 )
return - V_110 ;
V_4 -> V_37 = V_37 ;
V_11 = F_66 ( V_50 , ( void * ) V_4 ) ;
if ( F_31 ( V_11 ) ) {
F_52 ( V_4 ) ;
return - V_110 ;
}
V_11 = F_67 ( V_50 ,
V_111 ,
& F_54 ,
NULL ,
V_4 ) ;
if ( F_31 ( V_11 ) ) {
F_26 ( & V_37 -> V_40 , L_7 ) ;
F_68 ( V_50 ) ;
F_52 ( V_4 ) ;
return - V_110 ;
}
F_69 ( V_50 ) ;
return 0 ;
}
static void F_70 ( struct V_36 * V_37 )
{
T_2 V_50 ;
struct V_91 * V_4 ;
T_1 V_11 ;
if ( ! V_37 -> V_40 . V_109 )
return;
V_50 = F_16 ( V_37 -> V_40 . V_109 ) ;
if ( ! V_50 )
return;
F_71 ( V_50 ,
V_111 ,
& F_54 ) ;
V_11 = F_72 ( V_50 , ( void * * ) & V_4 ) ;
if ( F_7 ( V_11 ) )
F_52 ( V_4 ) ;
F_68 ( V_50 ) ;
}
static inline void F_70 ( struct V_36 * V_37 )
{ }
static inline int F_65 ( struct V_36 * V_37 )
{ return 0 ; }
const struct V_112 * F_73 ( const struct V_112 * V_113 ,
const struct V_64 * V_69 )
{
if ( ! ( V_113 && V_69 ) )
return NULL ;
while ( V_113 -> V_114 [ 0 ] ) {
if ( strcmp ( V_69 -> V_114 , V_113 -> V_114 ) == 0 )
return V_113 ;
V_113 ++ ;
}
return NULL ;
}
static int F_74 ( struct V_60 * V_40 , struct V_115 * V_116 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
struct V_117 * V_118 ;
if ( F_75 ( V_116 -> V_119 , V_69 ) )
return 1 ;
if ( F_76 ( V_40 , V_116 ) )
return 1 ;
V_118 = F_77 ( V_116 ) ;
if ( F_73 ( V_118 -> V_120 , V_69 ) )
return 1 ;
return 0 ;
}
static int F_78 ( struct V_60 * V_40 , struct V_121 * V_122 )
{
struct V_64 * V_69 = F_79 ( V_40 ) ;
int V_123 ;
V_123 = F_80 ( V_40 , V_122 ) ;
if ( V_123 != - V_41 )
return V_123 ;
return F_81 ( V_122 , L_8 , V_124 , V_69 -> V_114 ) ;
}
static int F_82 ( struct V_36 * V_54 )
{
return F_83 ( V_54 -> V_125 -> V_126 ) ;
}
static void F_84 ( struct V_36 * V_54 , int V_127 )
{
F_85 ( V_54 -> V_125 -> V_126 , V_127 ) ;
}
static int F_86 ( struct V_36 * V_54 )
{
return F_83 ( V_54 -> V_125 -> V_128 ) ;
}
static int F_87 ( struct V_36 * V_54 )
{
struct V_129 * V_130 = V_54 -> V_125 ;
struct V_60 * V_40 = & V_54 -> V_40 ;
int V_33 = 0 ;
V_33 = F_88 ( V_130 -> V_126 , V_131 |
V_132 , L_9 ) ;
if ( V_33 ) {
F_32 ( V_40 , L_10 , V_130 -> V_126 ) ;
return V_33 ;
}
if ( V_130 -> V_133 ) {
if ( F_88 ( V_130 -> V_128 , V_134 , L_11 ) ) {
F_32 ( V_40 , L_12 ,
V_130 -> V_128 ) ;
V_130 -> V_133 = NULL ;
}
}
return V_33 ;
}
static void F_89 ( struct V_36 * V_54 )
{
struct V_129 * V_130 = V_54 -> V_125 ;
if ( V_130 -> V_133 )
F_90 ( V_130 -> V_128 ) ;
F_90 ( V_130 -> V_126 ) ;
}
static int F_91 ( struct V_36 * V_54 )
{
struct V_129 * V_130 = V_54 -> V_125 ;
int V_135 = 0 , V_127 = 1 , V_33 = 0 ;
if ( V_130 -> V_136 )
V_130 -> V_136 ( V_54 ) ;
V_130 -> V_137 ( V_54 , V_127 ) ;
F_92 ( V_138 ) ;
while ( V_135 ++ < V_139 * 2 ) {
if ( V_127 ) {
if ( V_130 -> V_133 && V_130 -> V_133 ( V_54 ) )
break;
if ( ! V_130 -> V_140 ( V_54 ) ) {
F_26 ( & V_54 -> V_40 ,
L_13 ) ;
V_33 = - V_141 ;
break;
}
}
V_127 = ! V_127 ;
V_130 -> V_137 ( V_54 , V_127 ) ;
F_92 ( V_138 ) ;
}
if ( V_130 -> V_142 )
V_130 -> V_142 ( V_54 ) ;
return V_33 ;
}
int F_93 ( struct V_36 * V_54 )
{
return F_91 ( V_54 ) ;
}
int F_94 ( struct V_36 * V_54 )
{
int V_33 ;
V_33 = F_87 ( V_54 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_91 ( V_54 ) ;
F_89 ( V_54 ) ;
return V_33 ;
}
int F_95 ( struct V_36 * V_54 )
{
if ( ! V_54 -> V_125 )
return - V_143 ;
F_96 ( & V_54 -> V_40 , L_14 ) ;
return V_54 -> V_125 -> V_144 ( V_54 ) ;
}
static void F_97 ( struct V_36 * V_54 )
{
struct V_129 * V_130 = V_54 -> V_125 ;
char * V_145 ;
if ( ! V_130 )
return;
if ( ! V_130 -> V_144 ) {
V_145 = L_15 ;
goto V_98;
}
if ( V_130 -> V_144 == F_94 ) {
if ( ! F_98 ( V_130 -> V_126 ) ) {
V_145 = L_16 ;
goto V_98;
}
if ( F_98 ( V_130 -> V_128 ) )
V_130 -> V_133 = F_86 ;
else
V_130 -> V_133 = NULL ;
V_130 -> V_140 = F_82 ;
V_130 -> V_137 = F_84 ;
} else if ( V_130 -> V_144 == F_93 ) {
if ( ! V_130 -> V_137 || ! V_130 -> V_140 ) {
V_145 = L_17 ;
goto V_98;
}
}
return;
V_98:
F_26 ( & V_54 -> V_40 , L_18 , V_145 ) ;
V_54 -> V_125 = NULL ;
}
static int F_99 ( const struct V_64 * V_69 )
{
struct V_36 * V_54 = V_69 -> V_37 ;
unsigned int V_46 ;
if ( ! V_54 -> V_146 )
return - V_147 ;
if ( V_69 -> V_27 & V_28 )
return - V_35 ;
V_46 = F_100 ( V_54 -> V_146 , V_69 -> V_12 ) ;
if ( ! V_46 )
V_46 = F_101 ( V_54 -> V_146 ,
V_69 -> V_12 ) ;
return V_46 > 0 ? V_46 : - V_147 ;
}
static int F_102 ( struct V_60 * V_40 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
struct V_117 * V_118 ;
int V_11 ;
if ( ! V_69 )
return 0 ;
V_118 = F_77 ( V_40 -> V_118 ) ;
if ( ! V_69 -> V_46 && ! V_118 -> V_148 ) {
int V_46 = - V_149 ;
if ( V_69 -> V_27 & V_150 ) {
F_96 ( V_40 , L_19 ) ;
V_46 = F_99 ( V_69 ) ;
} else if ( V_40 -> V_151 ) {
V_46 = F_103 ( V_40 -> V_151 , L_20 ) ;
if ( V_46 == - V_35 || V_46 == - V_152 )
V_46 = F_104 ( V_40 -> V_151 , 0 ) ;
} else if ( F_38 ( V_40 ) ) {
V_46 = F_105 ( F_38 ( V_40 ) , 0 ) ;
}
if ( V_46 == - V_153 )
return V_46 ;
if ( V_46 < 0 )
V_46 = 0 ;
V_69 -> V_46 = V_46 ;
}
if ( ! V_118 -> V_120 &&
! F_75 ( V_40 -> V_118 -> V_119 , V_69 ) )
return - V_41 ;
if ( V_69 -> V_27 & V_154 ) {
int V_155 = - V_149 ;
if ( V_40 -> V_151 ) {
V_155 = F_103 ( V_40 -> V_151 , L_21 ) ;
if ( V_155 == - V_153 )
return V_155 ;
}
F_106 ( & V_69 -> V_40 , true ) ;
if ( V_155 > 0 && V_155 != V_69 -> V_46 )
V_11 = F_107 ( V_40 , V_155 ) ;
else if ( V_69 -> V_46 > 0 )
V_11 = F_108 ( V_40 , V_69 -> V_46 ) ;
else
V_11 = 0 ;
if ( V_11 )
F_32 ( & V_69 -> V_40 , L_22 ) ;
}
F_96 ( V_40 , L_23 ) ;
V_11 = F_109 ( V_40 -> V_151 , false ) ;
if ( V_11 < 0 )
goto V_156;
V_11 = F_110 ( & V_69 -> V_40 , true ) ;
if ( V_11 == - V_153 )
goto V_156;
if ( V_118 -> V_157 )
V_11 = V_118 -> V_157 ( V_69 ) ;
else if ( V_118 -> V_158 )
V_11 = V_118 -> V_158 ( V_69 ,
F_73 ( V_118 -> V_120 , V_69 ) ) ;
else
V_11 = - V_35 ;
if ( V_11 )
goto V_159;
return 0 ;
V_159:
F_111 ( & V_69 -> V_40 , true ) ;
V_156:
F_112 ( & V_69 -> V_40 ) ;
F_106 ( & V_69 -> V_40 , false ) ;
return V_11 ;
}
static int F_113 ( struct V_60 * V_40 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
struct V_117 * V_118 ;
int V_11 = 0 ;
if ( ! V_69 || ! V_40 -> V_118 )
return 0 ;
V_118 = F_77 ( V_40 -> V_118 ) ;
if ( V_118 -> remove ) {
F_96 ( V_40 , L_24 ) ;
V_11 = V_118 -> remove ( V_69 ) ;
}
F_111 ( & V_69 -> V_40 , true ) ;
F_112 ( & V_69 -> V_40 ) ;
F_106 ( & V_69 -> V_40 , false ) ;
return V_11 ;
}
static void F_114 ( struct V_60 * V_40 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
struct V_117 * V_118 ;
if ( ! V_69 || ! V_40 -> V_118 )
return;
V_118 = F_77 ( V_40 -> V_118 ) ;
if ( V_118 -> V_160 )
V_118 -> V_160 ( V_69 ) ;
}
static void F_115 ( struct V_60 * V_40 )
{
F_52 ( F_79 ( V_40 ) ) ;
}
static T_7
F_116 ( struct V_60 * V_40 , struct V_161 * V_162 , char * V_81 )
{
return sprintf ( V_81 , L_25 , V_40 -> type == & V_163 ?
F_79 ( V_40 ) -> V_114 : F_117 ( V_40 ) -> V_114 ) ;
}
static T_7
F_118 ( struct V_60 * V_40 , struct V_161 * V_162 , char * V_81 )
{
struct V_64 * V_69 = F_79 ( V_40 ) ;
int V_80 ;
V_80 = F_119 ( V_40 , V_81 , V_164 - 1 ) ;
if ( V_80 != - V_41 )
return V_80 ;
return sprintf ( V_81 , L_26 , V_124 , V_69 -> V_114 ) ;
}
struct V_64 * F_42 ( struct V_60 * V_40 )
{
return ( V_40 -> type == & V_163 )
? F_79 ( V_40 )
: NULL ;
}
static unsigned short F_120 ( struct V_64 * V_69 )
{
unsigned short V_12 = V_69 -> V_12 ;
if ( V_69 -> V_27 & V_28 )
V_12 |= V_165 ;
if ( V_69 -> V_27 & V_166 )
V_12 |= V_167 ;
return V_12 ;
}
static int F_121 ( unsigned V_12 , unsigned short V_27 )
{
if ( V_27 & V_28 ) {
if ( V_12 > 0x3ff )
return - V_35 ;
} else {
if ( V_12 == 0x00 || V_12 > 0x7f )
return - V_35 ;
}
return 0 ;
}
static int F_122 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_35 ;
return 0 ;
}
static int F_123 ( struct V_60 * V_40 , void * V_168 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
int V_12 = * ( int * ) V_168 ;
if ( V_69 && F_120 ( V_69 ) == V_12 )
return - V_141 ;
return 0 ;
}
static int F_124 ( struct V_36 * V_37 , int V_12 )
{
struct V_36 * V_109 = F_125 ( V_37 ) ;
int V_169 ;
V_169 = F_126 ( & V_37 -> V_40 , & V_12 ,
F_123 ) ;
if ( ! V_169 && V_109 )
V_169 = F_124 ( V_109 , V_12 ) ;
return V_169 ;
}
static int F_127 ( struct V_60 * V_40 , void * V_168 )
{
int V_169 ;
if ( V_40 -> type == & V_170 )
V_169 = F_126 ( V_40 , V_168 ,
F_127 ) ;
else
V_169 = F_123 ( V_40 , V_168 ) ;
return V_169 ;
}
static int F_128 ( struct V_36 * V_37 , int V_12 )
{
struct V_36 * V_109 = F_125 ( V_37 ) ;
int V_169 = 0 ;
if ( V_109 )
V_169 = F_124 ( V_109 , V_12 ) ;
if ( ! V_169 )
V_169 = F_126 ( & V_37 -> V_40 , & V_12 ,
F_127 ) ;
return V_169 ;
}
static void F_129 ( struct V_36 * V_37 ,
unsigned int V_27 )
{
F_130 ( & V_37 -> V_171 ) ;
}
static int F_131 ( struct V_36 * V_37 ,
unsigned int V_27 )
{
return F_132 ( & V_37 -> V_171 ) ;
}
static void F_133 ( struct V_36 * V_37 ,
unsigned int V_27 )
{
F_134 ( & V_37 -> V_171 ) ;
}
static void F_135 ( struct V_36 * V_54 ,
struct V_64 * V_69 )
{
struct V_29 * V_30 = F_38 ( & V_69 -> V_40 ) ;
if ( V_30 ) {
F_136 ( & V_69 -> V_40 , L_27 , F_137 ( V_30 ) ) ;
return;
}
F_136 ( & V_69 -> V_40 , L_28 , F_138 ( V_54 ) ,
F_120 ( V_69 ) ) ;
}
static int F_139 ( const struct V_172 * V_173 ,
unsigned int V_174 )
{
struct V_175 * V_176 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_174 ; V_135 ++ ) {
const struct V_172 * V_177 = & V_173 [ V_135 ] ;
if ( F_20 ( V_177 ) != V_45 )
continue;
if ( V_177 -> V_27 & V_178 ) {
V_176 = F_140 ( V_177 -> V_47 ) ;
if ( ! V_176 )
break;
F_141 ( V_176 , V_177 -> V_27 & V_178 ) ;
}
return V_177 -> V_47 ;
}
return 0 ;
}
struct V_64 *
F_25 ( struct V_36 * V_54 , struct V_7 const * V_8 )
{
struct V_64 * V_69 ;
int V_11 ;
V_69 = F_49 ( sizeof *V_69 , V_78 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_37 = V_54 ;
V_69 -> V_40 . V_179 = V_8 -> V_179 ;
if ( V_8 -> V_180 )
V_69 -> V_40 . V_180 = * V_8 -> V_180 ;
V_69 -> V_27 = V_8 -> V_27 ;
V_69 -> V_12 = V_8 -> V_12 ;
V_69 -> V_46 = V_8 -> V_46 ;
if ( ! V_69 -> V_46 )
V_69 -> V_46 = F_139 ( V_8 -> V_173 ,
V_8 -> V_174 ) ;
F_142 ( V_69 -> V_114 , V_8 -> type , sizeof( V_69 -> V_114 ) ) ;
V_11 = F_121 ( V_69 -> V_12 , V_69 -> V_27 ) ;
if ( V_11 ) {
F_26 ( & V_54 -> V_40 , L_29 ,
V_69 -> V_27 & V_28 ? 10 : 7 , V_69 -> V_12 ) ;
goto V_181;
}
V_11 = F_128 ( V_54 , F_120 ( V_69 ) ) ;
if ( V_11 )
goto V_182;
V_69 -> V_40 . V_109 = & V_69 -> V_37 -> V_40 ;
V_69 -> V_40 . V_183 = & V_63 ;
V_69 -> V_40 . type = & V_163 ;
V_69 -> V_40 . V_151 = V_8 -> V_151 ;
V_69 -> V_40 . V_43 = V_8 -> V_43 ;
F_135 ( V_54 , V_69 ) ;
if ( V_8 -> V_184 ) {
V_11 = F_143 ( & V_69 -> V_40 , V_8 -> V_184 ) ;
if ( V_11 ) {
F_26 ( & V_54 -> V_40 ,
L_30 ,
V_69 -> V_114 , V_11 ) ;
goto V_182;
}
}
V_11 = F_144 ( & V_69 -> V_40 ) ;
if ( V_11 )
goto V_185;
F_96 ( & V_54 -> V_40 , L_31 ,
V_69 -> V_114 , F_22 ( & V_69 -> V_40 ) ) ;
return V_69 ;
V_185:
if ( V_8 -> V_184 )
F_145 ( & V_69 -> V_40 ) ;
V_182:
F_26 ( & V_54 -> V_40 ,
L_32 ,
V_69 -> V_114 , V_69 -> V_12 , V_11 ) ;
V_181:
F_52 ( V_69 ) ;
return NULL ;
}
void F_44 ( struct V_64 * V_69 )
{
if ( V_69 -> V_40 . V_151 )
F_146 ( V_69 -> V_40 . V_151 , V_186 ) ;
if ( F_38 ( & V_69 -> V_40 ) )
F_147 ( F_38 ( & V_69 -> V_40 ) ) ;
F_148 ( & V_69 -> V_40 ) ;
}
static int F_149 ( struct V_64 * V_69 ,
const struct V_112 * V_113 )
{
return 0 ;
}
static int F_150 ( struct V_64 * V_69 )
{
return 0 ;
}
struct V_64 * F_151 ( struct V_36 * V_37 , T_8 V_187 )
{
struct V_7 V_8 = {
F_152 ( L_33 , V_187 ) ,
} ;
return F_25 ( V_37 , & V_8 ) ;
}
struct V_64 * F_153 ( struct V_64 * V_69 ,
const char * V_114 ,
T_8 V_188 )
{
struct V_189 * V_190 = V_69 -> V_40 . V_151 ;
T_3 V_12 = V_188 ;
int V_135 ;
if ( V_190 ) {
V_135 = F_154 ( V_190 , L_34 , V_114 ) ;
if ( V_135 >= 0 )
F_155 ( V_190 , L_35 , V_135 , & V_12 ) ;
}
F_96 ( & V_69 -> V_37 -> V_40 , L_36 , V_114 , V_12 ) ;
return F_151 ( V_69 -> V_37 , V_12 ) ;
}
static void F_156 ( struct V_60 * V_40 )
{
struct V_36 * V_54 = F_117 ( V_40 ) ;
F_157 ( & V_54 -> V_191 ) ;
}
unsigned int F_158 ( struct V_36 * V_37 )
{
unsigned int V_192 = 0 ;
while ( ( V_37 = F_125 ( V_37 ) ) )
V_192 ++ ;
F_159 ( V_192 >= V_193 ,
L_37 ) ;
return V_192 ;
}
static T_7
F_160 ( struct V_60 * V_40 , struct V_161 * V_162 ,
const char * V_81 , T_9 V_194 )
{
struct V_36 * V_54 = F_117 ( V_40 ) ;
struct V_7 V_8 ;
struct V_64 * V_69 ;
char * V_195 , V_196 ;
int V_44 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_195 = strchr ( V_81 , ' ' ) ;
if ( ! V_195 ) {
F_26 ( V_40 , L_38 , L_39 ) ;
return - V_35 ;
}
if ( V_195 - V_81 > V_197 - 1 ) {
F_26 ( V_40 , L_40 , L_39 ) ;
return - V_35 ;
}
memcpy ( V_8 . type , V_81 , V_195 - V_81 ) ;
V_44 = sscanf ( ++ V_195 , L_41 , & V_8 . V_12 , & V_196 ) ;
if ( V_44 < 1 ) {
F_26 ( V_40 , L_42 , L_39 ) ;
return - V_35 ;
}
if ( V_44 > 1 && V_196 != '\n' ) {
F_26 ( V_40 , L_43 , L_39 ) ;
return - V_35 ;
}
if ( ( V_8 . V_12 & V_165 ) == V_165 ) {
V_8 . V_12 &= ~ V_165 ;
V_8 . V_27 |= V_28 ;
}
if ( V_8 . V_12 & V_167 ) {
V_8 . V_12 &= ~ V_167 ;
V_8 . V_27 |= V_166 ;
}
V_69 = F_25 ( V_54 , & V_8 ) ;
if ( ! V_69 )
return - V_35 ;
F_161 ( & V_54 -> V_198 ) ;
F_162 ( & V_69 -> V_199 , & V_54 -> V_200 ) ;
F_163 ( & V_54 -> V_198 ) ;
F_164 ( V_40 , L_44 , L_39 ,
V_8 . type , V_8 . V_12 ) ;
return V_194 ;
}
static T_7
F_165 ( struct V_60 * V_40 , struct V_161 * V_162 ,
const char * V_81 , T_9 V_194 )
{
struct V_36 * V_54 = F_117 ( V_40 ) ;
struct V_64 * V_69 , * V_201 ;
unsigned short V_12 ;
char V_196 ;
int V_44 ;
V_44 = sscanf ( V_81 , L_41 , & V_12 , & V_196 ) ;
if ( V_44 < 1 ) {
F_26 ( V_40 , L_42 , L_45 ) ;
return - V_35 ;
}
if ( V_44 > 1 && V_196 != '\n' ) {
F_26 ( V_40 , L_43 , L_45 ) ;
return - V_35 ;
}
V_44 = - V_149 ;
F_166 ( & V_54 -> V_198 ,
F_158 ( V_54 ) ) ;
F_167 (client, next, &adap->userspace_clients,
detected) {
if ( F_120 ( V_69 ) == V_12 ) {
F_164 ( V_40 , L_46 ,
L_45 , V_69 -> V_114 , V_69 -> V_12 ) ;
F_168 ( & V_69 -> V_199 ) ;
F_44 ( V_69 ) ;
V_44 = V_194 ;
break;
}
}
F_163 ( & V_54 -> V_198 ) ;
if ( V_44 < 0 )
F_26 ( V_40 , L_47 ,
L_45 ) ;
return V_44 ;
}
struct V_36 * F_36 ( struct V_60 * V_40 )
{
return ( V_40 -> type == & V_170 )
? F_117 ( V_40 )
: NULL ;
}
static void F_169 ( struct V_36 * V_37 )
{
struct V_202 * V_203 ;
F_170 ( & V_204 ) ;
F_171 (devinfo, &__i2c_board_list, list) {
if ( V_203 -> V_205 == V_37 -> V_206
&& ! F_25 ( V_37 ,
& V_203 -> V_207 ) )
F_26 ( & V_37 -> V_40 ,
L_48 ,
V_203 -> V_207 . V_12 ) ;
}
F_172 ( & V_204 ) ;
}
static struct V_64 * F_173 ( struct V_36 * V_54 ,
struct V_189 * V_208 )
{
struct V_64 * V_169 ;
struct V_7 V_8 = {} ;
struct V_209 V_210 = {} ;
const T_10 * V_211 ;
T_3 V_12 ;
int V_80 ;
F_96 ( & V_54 -> V_40 , L_49 , V_208 -> V_212 ) ;
if ( F_174 ( V_208 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_26 ( & V_54 -> V_40 , L_50 ,
V_208 -> V_212 ) ;
return F_175 ( - V_35 ) ;
}
V_211 = F_176 ( V_208 , L_35 , & V_80 ) ;
if ( ! V_211 || ( V_80 < sizeof( * V_211 ) ) ) {
F_26 ( & V_54 -> V_40 , L_51 ,
V_208 -> V_212 ) ;
return F_175 ( - V_35 ) ;
}
V_12 = F_177 ( V_211 ) ;
if ( V_12 & V_213 ) {
V_12 &= ~ V_213 ;
V_8 . V_27 |= V_28 ;
}
if ( V_12 & V_214 ) {
V_12 &= ~ V_214 ;
V_8 . V_27 |= V_166 ;
}
if ( F_121 ( V_12 , V_8 . V_27 ) ) {
F_26 ( & V_54 -> V_40 , L_52 ,
V_12 , V_208 -> V_212 ) ;
return F_175 ( - V_35 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_151 = F_178 ( V_208 ) ;
V_8 . V_180 = & V_210 ;
if ( F_179 ( V_208 , L_53 ) )
V_8 . V_27 |= V_150 ;
if ( F_176 ( V_208 , L_54 , NULL ) )
V_8 . V_27 |= V_154 ;
V_169 = F_25 ( V_54 , & V_8 ) ;
if ( V_169 == NULL ) {
F_26 ( & V_54 -> V_40 , L_55 ,
V_208 -> V_212 ) ;
F_180 ( V_208 ) ;
return F_175 ( - V_35 ) ;
}
return V_169 ;
}
static void F_181 ( struct V_36 * V_54 )
{
struct V_189 * V_183 , * V_208 ;
struct V_64 * V_69 ;
if ( ! V_54 -> V_40 . V_151 )
return;
F_96 ( & V_54 -> V_40 , L_56 ) ;
V_183 = F_182 ( V_54 -> V_40 . V_151 , L_57 ) ;
if ( ! V_183 )
V_183 = F_178 ( V_54 -> V_40 . V_151 ) ;
F_183 (bus, node) {
if ( F_184 ( V_208 , V_186 ) )
continue;
V_69 = F_173 ( V_54 , V_208 ) ;
if ( F_185 ( V_69 ) ) {
F_32 ( & V_54 -> V_40 ,
L_58 ,
V_208 -> V_212 ) ;
F_146 ( V_208 , V_186 ) ;
}
}
F_180 ( V_183 ) ;
}
static int F_186 ( struct V_60 * V_40 , void * V_4 )
{
return V_40 -> V_151 == V_4 ;
}
struct V_64 * F_187 ( struct V_189 * V_208 )
{
struct V_60 * V_40 ;
struct V_64 * V_69 ;
V_40 = F_40 ( & V_63 , NULL , V_208 , F_186 ) ;
if ( ! V_40 )
return NULL ;
V_69 = F_42 ( V_40 ) ;
if ( ! V_69 )
F_45 ( V_40 ) ;
return V_69 ;
}
struct V_36 * F_188 ( struct V_189 * V_208 )
{
struct V_60 * V_40 ;
struct V_36 * V_37 ;
V_40 = F_40 ( & V_63 , NULL , V_208 , F_186 ) ;
if ( ! V_40 )
return NULL ;
V_37 = F_36 ( V_40 ) ;
if ( ! V_37 )
F_45 ( V_40 ) ;
return V_37 ;
}
struct V_36 * F_189 ( struct V_189 * V_208 )
{
struct V_36 * V_37 ;
V_37 = F_188 ( V_208 ) ;
if ( ! V_37 )
return NULL ;
if ( ! F_190 ( V_37 -> V_215 ) ) {
F_45 ( & V_37 -> V_40 ) ;
V_37 = NULL ;
}
return V_37 ;
}
static const struct V_216 *
F_191 ( const struct V_216 * V_217 ,
struct V_64 * V_69 )
{
const char * V_114 ;
for (; V_217 -> V_218 [ 0 ] ; V_217 ++ ) {
if ( F_192 ( V_69 -> V_114 , V_217 -> V_218 ) )
return V_217 ;
V_114 = strchr ( V_217 -> V_218 , ',' ) ;
if ( ! V_114 )
V_114 = V_217 -> V_218 ;
else
V_114 ++ ;
if ( F_192 ( V_69 -> V_114 , V_114 ) )
return V_217 ;
}
return NULL ;
}
const struct V_216
* F_75 ( const struct V_216 * V_217 ,
struct V_64 * V_69 )
{
const struct V_216 * V_219 ;
if ( ! ( V_69 && V_217 ) )
return NULL ;
V_219 = F_193 ( V_217 , & V_69 -> V_40 ) ;
if ( V_219 )
return V_219 ;
return F_191 ( V_217 , V_69 ) ;
}
static void F_181 ( struct V_36 * V_54 ) { }
static int F_194 ( struct V_117 * V_118 ,
struct V_36 * V_54 )
{
F_195 ( V_54 , V_118 ) ;
if ( V_118 -> V_220 ) {
F_32 ( & V_54 -> V_40 , L_59 ,
V_118 -> V_118 . V_114 ) ;
F_32 ( & V_54 -> V_40 ,
L_60 ) ;
V_118 -> V_220 ( V_54 ) ;
}
return 0 ;
}
static int F_196 ( struct V_115 * V_221 , void * V_4 )
{
return F_194 ( F_77 ( V_221 ) , V_4 ) ;
}
static void F_197 ( struct V_36 * V_54 )
{
struct V_222 * V_223 = V_54 -> V_146 ;
T_11 V_224 ;
if ( ! V_223 )
return;
for ( V_224 = 0 ; V_224 < V_225 ; V_224 ++ )
F_198 ( F_100 ( V_223 , V_224 ) ) ;
F_199 ( V_223 ) ;
V_54 -> V_146 = NULL ;
}
static int F_200 ( struct V_222 * V_226 ,
unsigned int V_227 ,
T_11 V_228 )
{
F_201 ( V_227 , & V_229 , V_230 ) ;
return 0 ;
}
static int F_202 ( struct V_36 * V_54 )
{
struct V_222 * V_223 ;
if ( ! F_203 ( V_54 , V_231 ) )
return 0 ;
V_223 = F_204 ( V_54 -> V_40 . V_43 ,
V_225 ,
& V_232 , V_54 ) ;
if ( ! V_223 )
return - V_110 ;
V_54 -> V_146 = V_223 ;
return 0 ;
}
int F_205 ( struct V_36 * V_54 , unsigned short V_12 )
{
int V_46 ;
if ( ! V_54 )
return - V_35 ;
V_46 = F_100 ( V_54 -> V_146 , V_12 ) ;
if ( V_46 <= 0 )
return - V_147 ;
F_206 ( V_46 ) ;
return 0 ;
}
static int F_207 ( struct V_36 * V_54 )
{
int V_44 = - V_35 ;
if ( F_208 ( ! V_233 ) ) {
V_44 = - V_234 ;
goto V_235;
}
if ( F_209 ( ! V_54 -> V_114 [ 0 ] , L_61 ) )
goto V_235;
if ( ! V_54 -> V_236 ) {
F_210 ( L_62 , V_54 -> V_114 ) ;
goto V_235;
}
if ( ! V_54 -> V_237 )
V_54 -> V_237 = & V_238 ;
F_211 ( & V_54 -> V_171 ) ;
F_211 ( & V_54 -> V_239 ) ;
F_212 ( & V_54 -> V_198 ) ;
F_12 ( & V_54 -> V_200 ) ;
if ( V_54 -> V_240 == 0 )
V_54 -> V_240 = V_241 ;
V_44 = F_202 ( V_54 ) ;
if ( V_44 ) {
F_210 ( L_63 ,
V_54 -> V_114 , V_44 ) ;
goto V_235;
}
F_136 ( & V_54 -> V_40 , L_64 , V_54 -> V_206 ) ;
V_54 -> V_40 . V_183 = & V_63 ;
V_54 -> V_40 . type = & V_170 ;
V_44 = F_144 ( & V_54 -> V_40 ) ;
if ( V_44 ) {
F_210 ( L_65 , V_54 -> V_114 , V_44 ) ;
goto V_235;
}
F_96 ( & V_54 -> V_40 , L_66 , V_54 -> V_114 ) ;
F_213 ( & V_54 -> V_40 ) ;
F_214 ( & V_54 -> V_40 , true ) ;
F_215 ( & V_54 -> V_40 ) ;
#ifdef F_216
V_44 = F_217 ( V_242 , & V_54 -> V_40 ,
V_54 -> V_40 . V_109 ) ;
if ( V_44 )
F_32 ( & V_54 -> V_40 ,
L_67 ) ;
#endif
F_97 ( V_54 ) ;
F_181 ( V_54 ) ;
F_28 ( V_54 ) ;
F_65 ( V_54 ) ;
if ( V_54 -> V_206 < V_243 )
F_169 ( V_54 ) ;
F_161 ( & V_244 ) ;
F_218 ( & V_63 , NULL , V_54 , F_196 ) ;
F_163 ( & V_244 ) ;
return 0 ;
V_235:
F_161 ( & V_244 ) ;
F_219 ( & V_245 , V_54 -> V_206 ) ;
F_163 ( & V_244 ) ;
return V_44 ;
}
static int F_220 ( struct V_36 * V_54 )
{
int V_113 ;
F_161 ( & V_244 ) ;
V_113 = F_221 ( & V_245 , V_54 , V_54 -> V_206 , V_54 -> V_206 + 1 , V_78 ) ;
F_163 ( & V_244 ) ;
if ( F_209 ( V_113 < 0 , L_68 ) )
return V_113 == - V_246 ? - V_141 : V_113 ;
return F_207 ( V_54 ) ;
}
int F_222 ( struct V_36 * V_37 )
{
struct V_60 * V_40 = & V_37 -> V_40 ;
int V_113 ;
if ( V_40 -> V_151 ) {
V_113 = F_223 ( V_40 -> V_151 , L_69 ) ;
if ( V_113 >= 0 ) {
V_37 -> V_206 = V_113 ;
return F_220 ( V_37 ) ;
}
}
F_161 ( & V_244 ) ;
V_113 = F_221 ( & V_245 , V_37 ,
V_243 , 0 , V_78 ) ;
F_163 ( & V_244 ) ;
if ( F_209 ( V_113 < 0 , L_68 ) )
return V_113 ;
V_37 -> V_206 = V_113 ;
return F_207 ( V_37 ) ;
}
int F_224 ( struct V_36 * V_54 )
{
if ( V_54 -> V_206 == - 1 )
return F_222 ( V_54 ) ;
return F_220 ( V_54 ) ;
}
static void F_225 ( struct V_117 * V_118 ,
struct V_36 * V_37 )
{
struct V_64 * V_69 , * V_247 ;
F_167 (client, _n, &driver->clients, detected) {
if ( V_69 -> V_37 == V_37 ) {
F_96 ( & V_37 -> V_40 , L_70 ,
V_69 -> V_114 , V_69 -> V_12 ) ;
F_168 ( & V_69 -> V_199 ) ;
F_44 ( V_69 ) ;
}
}
}
static int F_226 ( struct V_60 * V_40 , void * V_61 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
if ( V_69 && strcmp ( V_69 -> V_114 , L_33 ) )
F_44 ( V_69 ) ;
return 0 ;
}
static int F_227 ( struct V_60 * V_40 , void * V_61 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
if ( V_69 )
F_44 ( V_69 ) ;
return 0 ;
}
static int F_228 ( struct V_115 * V_221 , void * V_4 )
{
F_225 ( F_77 ( V_221 ) , V_4 ) ;
return 0 ;
}
void F_229 ( struct V_36 * V_54 )
{
struct V_36 * V_248 ;
struct V_64 * V_69 , * V_201 ;
F_161 ( & V_244 ) ;
V_248 = F_230 ( & V_245 , V_54 -> V_206 ) ;
F_163 ( & V_244 ) ;
if ( V_248 != V_54 ) {
F_231 ( L_71 , V_54 -> V_114 ) ;
return;
}
F_70 ( V_54 ) ;
F_161 ( & V_244 ) ;
F_218 ( & V_63 , NULL , V_54 ,
F_228 ) ;
F_163 ( & V_244 ) ;
F_166 ( & V_54 -> V_198 ,
F_158 ( V_54 ) ) ;
F_167 (client, next, &adap->userspace_clients,
detected) {
F_96 ( & V_54 -> V_40 , L_70 , V_69 -> V_114 ,
V_69 -> V_12 ) ;
F_168 ( & V_69 -> V_199 ) ;
F_44 ( V_69 ) ;
}
F_163 ( & V_54 -> V_198 ) ;
F_126 ( & V_54 -> V_40 , NULL , F_226 ) ;
F_126 ( & V_54 -> V_40 , NULL , F_227 ) ;
#ifdef F_216
F_232 ( V_242 , & V_54 -> V_40 ,
V_54 -> V_40 . V_109 ) ;
#endif
F_96 ( & V_54 -> V_40 , L_72 , V_54 -> V_114 ) ;
F_233 ( & V_54 -> V_40 ) ;
F_197 ( V_54 ) ;
F_234 ( & V_54 -> V_191 ) ;
F_148 ( & V_54 -> V_40 ) ;
F_235 ( & V_54 -> V_191 ) ;
F_161 ( & V_244 ) ;
F_219 ( & V_245 , V_54 -> V_206 ) ;
F_163 ( & V_244 ) ;
memset ( & V_54 -> V_40 , 0 , sizeof( V_54 -> V_40 ) ) ;
}
void F_236 ( struct V_60 * V_40 , struct V_249 * V_250 , bool V_251 )
{
int V_33 ;
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
V_33 = F_237 ( V_40 , L_73 , & V_250 -> V_252 ) ;
if ( V_33 && V_251 )
V_250 -> V_252 = 100000 ;
V_33 = F_237 ( V_40 , L_74 , & V_250 -> V_253 ) ;
if ( V_33 && V_251 ) {
if ( V_250 -> V_252 <= 100000 )
V_250 -> V_253 = 1000 ;
else if ( V_250 -> V_252 <= 400000 )
V_250 -> V_253 = 300 ;
else
V_250 -> V_253 = 120 ;
}
V_33 = F_237 ( V_40 , L_75 , & V_250 -> V_254 ) ;
if ( V_33 && V_251 ) {
if ( V_250 -> V_252 <= 400000 )
V_250 -> V_254 = 300 ;
else
V_250 -> V_254 = 120 ;
}
F_237 ( V_40 , L_76 , & V_250 -> V_255 ) ;
V_33 = F_237 ( V_40 , L_77 , & V_250 -> V_256 ) ;
if ( V_33 && V_251 )
V_250 -> V_256 = V_250 -> V_254 ;
}
int F_238 ( void * V_4 , int (* F_239)( struct V_60 * , void * ) )
{
int V_44 ;
F_161 ( & V_244 ) ;
V_44 = F_240 ( & V_63 , NULL , V_4 , F_239 ) ;
F_163 ( & V_244 ) ;
return V_44 ;
}
static int F_241 ( struct V_60 * V_40 , void * V_4 )
{
if ( V_40 -> type != & V_170 )
return 0 ;
return F_194 ( V_4 , F_117 ( V_40 ) ) ;
}
int F_242 ( struct V_257 * V_215 , struct V_117 * V_118 )
{
int V_44 ;
if ( F_208 ( ! V_233 ) )
return - V_234 ;
V_118 -> V_118 . V_215 = V_215 ;
V_118 -> V_118 . V_183 = & V_63 ;
F_12 ( & V_118 -> V_258 ) ;
V_44 = F_243 ( & V_118 -> V_118 ) ;
if ( V_44 )
return V_44 ;
F_231 ( L_78 , V_118 -> V_118 . V_114 ) ;
F_238 ( V_118 , F_241 ) ;
return 0 ;
}
static int F_244 ( struct V_60 * V_40 , void * V_4 )
{
if ( V_40 -> type == & V_170 )
F_225 ( V_4 , F_117 ( V_40 ) ) ;
return 0 ;
}
void F_245 ( struct V_117 * V_118 )
{
F_238 ( V_118 , F_244 ) ;
F_246 ( & V_118 -> V_118 ) ;
F_231 ( L_79 , V_118 -> V_118 . V_114 ) ;
}
struct V_64 * F_247 ( struct V_64 * V_69 )
{
if ( V_69 && F_248 ( & V_69 -> V_40 ) )
return V_69 ;
return NULL ;
}
void F_249 ( struct V_64 * V_69 )
{
if ( V_69 )
F_45 ( & V_69 -> V_40 ) ;
}
static int F_250 ( struct V_60 * V_40 , void * V_259 )
{
struct V_64 * V_69 = F_42 ( V_40 ) ;
struct V_260 * V_68 = V_259 ;
struct V_117 * V_118 ;
if ( ! V_69 || ! V_69 -> V_40 . V_118 )
return 0 ;
V_118 = F_77 ( V_69 -> V_40 . V_118 ) ;
if ( V_118 -> V_84 )
V_118 -> V_84 ( V_69 , V_68 -> V_73 , V_68 -> V_68 ) ;
return 0 ;
}
void F_251 ( struct V_36 * V_54 , unsigned int V_73 , void * V_68 )
{
struct V_260 V_261 ;
V_261 . V_73 = V_73 ;
V_261 . V_68 = V_68 ;
F_126 ( & V_54 -> V_40 , & V_261 , F_250 ) ;
}
static int F_252 ( struct V_65 * V_66 , unsigned long V_94 ,
void * V_68 )
{
struct V_262 * V_263 = V_68 ;
struct V_36 * V_54 ;
struct V_64 * V_69 ;
switch ( F_253 ( V_94 , V_263 ) ) {
case V_264 :
V_54 = F_188 ( V_263 -> V_265 -> V_109 ) ;
if ( V_54 == NULL )
return V_72 ;
if ( F_184 ( V_263 -> V_265 , V_186 ) ) {
F_45 ( & V_54 -> V_40 ) ;
return V_72 ;
}
V_69 = F_173 ( V_54 , V_263 -> V_265 ) ;
F_45 ( & V_54 -> V_40 ) ;
if ( F_185 ( V_69 ) ) {
F_26 ( & V_54 -> V_40 , L_80 ,
V_263 -> V_265 -> V_212 ) ;
F_146 ( V_263 -> V_265 , V_186 ) ;
return F_254 ( F_255 ( V_69 ) ) ;
}
break;
case V_266 :
if ( ! F_256 ( V_263 -> V_265 , V_186 ) )
return V_72 ;
V_69 = F_187 ( V_263 -> V_265 ) ;
if ( V_69 == NULL )
return V_72 ;
F_44 ( V_69 ) ;
F_45 ( & V_69 -> V_40 ) ;
break;
}
return V_72 ;
}
static int T_12 F_257 ( void )
{
int V_267 ;
V_267 = F_258 ( L_69 ) ;
F_259 ( & V_204 ) ;
if ( V_267 >= V_243 )
V_243 = V_267 + 1 ;
F_260 ( & V_204 ) ;
V_267 = F_261 ( & V_63 ) ;
if ( V_267 )
return V_267 ;
V_233 = true ;
#ifdef F_216
V_242 = F_262 ( L_81 ) ;
if ( ! V_242 ) {
V_267 = - V_110 ;
goto V_268;
}
#endif
V_267 = F_263 ( & V_269 ) ;
if ( V_267 )
goto V_270;
if ( F_264 ( V_271 ) )
F_208 ( F_265 ( & V_272 ) ) ;
if ( F_264 ( V_273 ) )
F_208 ( F_266 ( & V_274 ) ) ;
return 0 ;
V_270:
#ifdef F_216
F_267 ( V_242 ) ;
V_268:
#endif
V_233 = false ;
F_268 ( & V_63 ) ;
return V_267 ;
}
static void T_13 F_269 ( void )
{
if ( F_264 ( V_273 ) )
F_208 ( F_270 ( & V_274 ) ) ;
if ( F_264 ( V_271 ) )
F_208 ( F_271 ( & V_272 ) ) ;
F_245 ( & V_269 ) ;
#ifdef F_216
F_267 ( V_242 ) ;
#endif
F_268 ( & V_63 ) ;
F_272 () ;
}
static int F_273 ( struct V_36 * V_54 , struct V_75 * V_275 , char * V_276 )
{
F_274 ( & V_54 -> V_40 , L_82 ,
V_276 , V_275 -> V_12 , V_275 -> V_80 ,
V_275 -> V_27 & V_82 ? L_83 : L_84 ) ;
return - V_143 ;
}
static int F_275 ( struct V_36 * V_54 , struct V_75 * V_76 , int V_277 )
{
const struct V_278 * V_279 = V_54 -> V_280 ;
int V_281 = V_279 -> V_282 , V_135 ;
bool V_283 = true ;
if ( V_279 -> V_27 & V_284 ) {
V_281 = 2 ;
if ( V_277 == 2 ) {
if ( V_279 -> V_27 & V_285 && V_76 [ 0 ] . V_27 & V_82 )
return F_273 ( V_54 , & V_76 [ 0 ] , L_85 ) ;
if ( V_279 -> V_27 & V_286 && ! ( V_76 [ 1 ] . V_27 & V_82 ) )
return F_273 ( V_54 , & V_76 [ 1 ] , L_86 ) ;
if ( V_279 -> V_27 & V_287 && V_76 [ 0 ] . V_12 != V_76 [ 1 ] . V_12 )
return F_273 ( V_54 , & V_76 [ 0 ] , L_87 ) ;
if ( F_276 ( V_76 [ 0 ] . V_80 , V_279 -> V_288 ) )
return F_273 ( V_54 , & V_76 [ 0 ] , L_88 ) ;
if ( F_276 ( V_76 [ 1 ] . V_80 , V_279 -> V_289 ) )
return F_273 ( V_54 , & V_76 [ 1 ] , L_88 ) ;
V_283 = false ;
}
}
if ( F_276 ( V_277 , V_281 ) )
return F_273 ( V_54 , & V_76 [ 0 ] , L_89 ) ;
for ( V_135 = 0 ; V_135 < V_277 ; V_135 ++ ) {
T_8 V_80 = V_76 [ V_135 ] . V_80 ;
if ( V_76 [ V_135 ] . V_27 & V_82 ) {
if ( V_283 && F_276 ( V_80 , V_279 -> V_290 ) )
return F_273 ( V_54 , & V_76 [ V_135 ] , L_88 ) ;
} else {
if ( V_283 && F_276 ( V_80 , V_279 -> V_291 ) )
return F_273 ( V_54 , & V_76 [ V_135 ] , L_88 ) ;
}
}
return 0 ;
}
int F_277 ( struct V_36 * V_54 , struct V_75 * V_76 , int V_277 )
{
unsigned long V_292 ;
int V_33 , V_293 ;
if ( V_54 -> V_280 && F_275 ( V_54 , V_76 , V_277 ) )
return - V_143 ;
if ( F_278 ( & V_1 ) ) {
int V_135 ;
for ( V_135 = 0 ; V_135 < V_277 ; V_135 ++ )
if ( V_76 [ V_135 ] . V_27 & V_82 )
F_279 ( V_54 , & V_76 [ V_135 ] , V_135 ) ;
else
F_280 ( V_54 , & V_76 [ V_135 ] , V_135 ) ;
}
V_292 = V_294 ;
for ( V_33 = 0 , V_293 = 0 ; V_293 <= V_54 -> V_295 ; V_293 ++ ) {
V_33 = V_54 -> V_236 -> V_296 ( V_54 , V_76 , V_277 ) ;
if ( V_33 != - V_234 )
break;
if ( F_281 ( V_294 , V_292 + V_54 -> V_240 ) )
break;
}
if ( F_278 ( & V_1 ) ) {
int V_135 ;
for ( V_135 = 0 ; V_135 < V_33 ; V_135 ++ )
if ( V_76 [ V_135 ] . V_27 & V_82 )
F_282 ( V_54 , & V_76 [ V_135 ] , V_135 ) ;
F_283 ( V_54 , V_135 , V_33 ) ;
}
return V_33 ;
}
int F_50 ( struct V_36 * V_54 , struct V_75 * V_76 , int V_277 )
{
int V_33 ;
if ( V_54 -> V_236 -> V_296 ) {
#ifdef F_284
for ( V_33 = 0 ; V_33 < V_277 ; V_33 ++ ) {
F_96 ( & V_54 -> V_40 ,
L_90 ,
V_33 , ( V_76 [ V_33 ] . V_27 & V_82 ) ? 'R' : 'W' ,
V_76 [ V_33 ] . V_12 , V_76 [ V_33 ] . V_80 ,
( V_76 [ V_33 ] . V_27 & V_297 ) ? L_91 : L_92 ) ;
}
#endif
if ( F_285 () || F_286 () ) {
V_33 = F_287 ( V_54 , V_298 ) ;
if ( ! V_33 )
return - V_234 ;
} else {
F_288 ( V_54 , V_298 ) ;
}
V_33 = F_277 ( V_54 , V_76 , V_277 ) ;
F_289 ( V_54 , V_298 ) ;
return V_33 ;
} else {
F_96 ( & V_54 -> V_40 , L_93 ) ;
return - V_143 ;
}
}
int F_290 ( const struct V_64 * V_69 , const char * V_81 , int V_194 )
{
int V_33 ;
struct V_36 * V_54 = V_69 -> V_37 ;
struct V_75 V_275 ;
V_275 . V_12 = V_69 -> V_12 ;
V_275 . V_27 = V_69 -> V_27 & V_299 ;
V_275 . V_80 = V_194 ;
V_275 . V_81 = ( char * ) V_81 ;
V_33 = F_50 ( V_54 , & V_275 , 1 ) ;
return ( V_33 == 1 ) ? V_194 : V_33 ;
}
int F_291 ( const struct V_64 * V_69 , char * V_81 , int V_194 )
{
struct V_36 * V_54 = V_69 -> V_37 ;
struct V_75 V_275 ;
int V_33 ;
V_275 . V_12 = V_69 -> V_12 ;
V_275 . V_27 = V_69 -> V_27 & V_299 ;
V_275 . V_27 |= V_82 ;
V_275 . V_80 = V_194 ;
V_275 . V_81 = V_81 ;
V_33 = F_50 ( V_54 , & V_275 , 1 ) ;
return ( V_33 == 1 ) ? V_194 : V_33 ;
}
static int F_292 ( struct V_36 * V_54 , unsigned short V_12 )
{
int V_98 ;
union V_300 V_61 ;
#ifdef F_293
if ( V_12 == 0x73 && ( V_54 -> V_301 & V_302 )
&& F_203 ( V_54 , V_303 ) )
V_98 = F_294 ( V_54 , V_12 , 0 , V_304 , 0 ,
V_305 , & V_61 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_203 ( V_54 , V_306 ) )
V_98 = F_294 ( V_54 , V_12 , 0 , V_307 , 0 ,
V_308 , NULL ) ;
else if ( F_203 ( V_54 , V_309 ) )
V_98 = F_294 ( V_54 , V_12 , 0 , V_304 , 0 ,
V_310 , & V_61 ) ;
else {
F_32 ( & V_54 -> V_40 , L_94 ,
V_12 ) ;
V_98 = - V_143 ;
}
return V_98 >= 0 ;
}
static int F_295 ( struct V_64 * V_311 ,
struct V_117 * V_118 )
{
struct V_7 V_8 ;
struct V_36 * V_37 = V_311 -> V_37 ;
int V_12 = V_311 -> V_12 ;
int V_98 ;
V_98 = F_122 ( V_12 ) ;
if ( V_98 ) {
F_32 ( & V_37 -> V_40 , L_95 ,
V_12 ) ;
return V_98 ;
}
if ( F_128 ( V_37 , V_12 ) )
return 0 ;
if ( ! F_292 ( V_37 , V_12 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_12 = V_12 ;
V_98 = V_118 -> V_312 ( V_311 , & V_8 ) ;
if ( V_98 ) {
return V_98 == - V_41 ? 0 : V_98 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_26 ( & V_37 -> V_40 ,
L_96 ,
V_118 -> V_118 . V_114 , V_12 ) ;
} else {
struct V_64 * V_69 ;
if ( V_37 -> V_301 & V_313 )
F_32 ( & V_37 -> V_40 ,
L_97
L_98
L_99 ,
V_8 . V_12 ) ;
F_96 ( & V_37 -> V_40 , L_100 ,
V_8 . type , V_8 . V_12 ) ;
V_69 = F_25 ( V_37 , & V_8 ) ;
if ( V_69 )
F_162 ( & V_69 -> V_199 , & V_118 -> V_258 ) ;
else
F_26 ( & V_37 -> V_40 , L_101 ,
V_8 . type , V_8 . V_12 ) ;
}
return 0 ;
}
static int F_195 ( struct V_36 * V_37 , struct V_117 * V_118 )
{
const unsigned short * V_314 ;
struct V_64 * V_311 ;
int V_135 , V_98 = 0 ;
int V_315 = F_138 ( V_37 ) ;
V_314 = V_118 -> V_314 ;
if ( ! V_118 -> V_312 || ! V_314 )
return 0 ;
if ( V_37 -> V_301 == V_313 ) {
F_96 ( & V_37 -> V_40 ,
L_102
L_103 ,
V_118 -> V_118 . V_114 ) ;
return 0 ;
}
if ( ! ( V_37 -> V_301 & V_118 -> V_301 ) )
return 0 ;
V_311 = F_49 ( sizeof( struct V_64 ) , V_78 ) ;
if ( ! V_311 )
return - V_110 ;
V_311 -> V_37 = V_37 ;
for ( V_135 = 0 ; V_314 [ V_135 ] != V_316 ; V_135 += 1 ) {
F_96 ( & V_37 -> V_40 ,
L_104 ,
V_315 , V_314 [ V_135 ] ) ;
V_311 -> V_12 = V_314 [ V_135 ] ;
V_98 = F_295 ( V_311 , V_118 ) ;
if ( F_296 ( V_98 ) )
break;
}
F_52 ( V_311 ) ;
return V_98 ;
}
int F_297 ( struct V_36 * V_54 , unsigned short V_12 )
{
return F_294 ( V_54 , V_12 , 0 , V_304 , 0 ,
V_308 , NULL ) >= 0 ;
}
struct V_64 *
F_298 ( struct V_36 * V_54 ,
struct V_7 * V_8 ,
unsigned short const * V_317 ,
int (* V_158)( struct V_36 * , unsigned short V_12 ) )
{
int V_135 ;
if ( ! V_158 )
V_158 = F_292 ;
for ( V_135 = 0 ; V_317 [ V_135 ] != V_316 ; V_135 ++ ) {
if ( F_122 ( V_317 [ V_135 ] ) < 0 ) {
F_32 ( & V_54 -> V_40 , L_105 ,
V_317 [ V_135 ] ) ;
continue;
}
if ( F_128 ( V_54 , V_317 [ V_135 ] ) ) {
F_96 ( & V_54 -> V_40 ,
L_106 ,
V_317 [ V_135 ] ) ;
continue;
}
if ( V_158 ( V_54 , V_317 [ V_135 ] ) )
break;
}
if ( V_317 [ V_135 ] == V_316 ) {
F_96 ( & V_54 -> V_40 , L_107 ) ;
return NULL ;
}
V_8 -> V_12 = V_317 [ V_135 ] ;
return F_25 ( V_54 , V_8 ) ;
}
struct V_36 * F_299 ( int V_206 )
{
struct V_36 * V_37 ;
F_161 ( & V_244 ) ;
V_37 = F_230 ( & V_245 , V_206 ) ;
if ( ! V_37 )
goto exit;
if ( F_190 ( V_37 -> V_215 ) )
F_248 ( & V_37 -> V_40 ) ;
else
V_37 = NULL ;
exit:
F_163 ( & V_244 ) ;
return V_37 ;
}
void F_300 ( struct V_36 * V_54 )
{
if ( ! V_54 )
return;
F_45 ( & V_54 -> V_40 ) ;
F_301 ( V_54 -> V_215 ) ;
}
static T_4 F_302 ( T_8 V_4 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < 8 ; V_135 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_318 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_303 ( T_4 V_319 , T_4 * V_320 , T_9 V_194 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_194 ; V_135 ++ )
V_319 = F_302 ( ( V_319 ^ V_320 [ V_135 ] ) << 8 ) ;
return V_319 ;
}
static T_4 F_304 ( T_4 V_321 , struct V_75 * V_275 )
{
T_4 V_12 = F_305 ( V_275 ) ;
V_321 = F_303 ( V_321 , & V_12 , 1 ) ;
return F_303 ( V_321 , V_275 -> V_81 , V_275 -> V_80 ) ;
}
static inline void F_306 ( struct V_75 * V_275 )
{
V_275 -> V_81 [ V_275 -> V_80 ] = F_304 ( 0 , V_275 ) ;
V_275 -> V_80 ++ ;
}
static int F_307 ( T_4 V_322 , struct V_75 * V_275 )
{
T_4 V_323 = V_275 -> V_81 [ -- V_275 -> V_80 ] ;
V_322 = F_304 ( V_322 , V_275 ) ;
if ( V_323 != V_322 ) {
F_231 ( L_108 ,
V_323 , V_322 ) ;
return - V_324 ;
}
return 0 ;
}
T_14 F_56 ( const struct V_64 * V_69 )
{
union V_300 V_4 ;
int V_11 ;
V_11 = F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_304 , 0 ,
V_310 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_325 ;
}
T_14 F_57 ( const struct V_64 * V_69 , T_4 V_67 )
{
return F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_307 , V_67 , V_310 , NULL ) ;
}
T_14 F_58 ( const struct V_64 * V_69 , T_4 V_84 )
{
union V_300 V_4 ;
int V_11 ;
V_11 = F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_304 , V_84 ,
V_305 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_325 ;
}
T_14 F_59 ( const struct V_64 * V_69 , T_4 V_84 ,
T_4 V_67 )
{
union V_300 V_4 ;
V_4 . V_325 = V_67 ;
return F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_307 , V_84 ,
V_305 , & V_4 ) ;
}
T_14 F_60 ( const struct V_64 * V_69 , T_4 V_84 )
{
union V_300 V_4 ;
int V_11 ;
V_11 = F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_304 , V_84 ,
V_326 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_327 ;
}
T_14 F_61 ( const struct V_64 * V_69 , T_4 V_84 ,
T_8 V_67 )
{
union V_300 V_4 ;
V_4 . V_327 = V_67 ;
return F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_307 , V_84 ,
V_326 , & V_4 ) ;
}
T_14 F_62 ( const struct V_64 * V_69 , T_4 V_84 ,
T_4 * V_328 )
{
union V_300 V_4 ;
int V_11 ;
V_11 = F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_304 , V_84 ,
V_329 , & V_4 ) ;
if ( V_11 )
return V_11 ;
memcpy ( V_328 , & V_4 . V_330 [ 1 ] , V_4 . V_330 [ 0 ] ) ;
return V_4 . V_330 [ 0 ] ;
}
T_14 F_63 ( const struct V_64 * V_69 , T_4 V_84 ,
T_4 V_97 , const T_4 * V_328 )
{
union V_300 V_4 ;
if ( V_97 > V_331 )
V_97 = V_331 ;
V_4 . V_330 [ 0 ] = V_97 ;
memcpy ( & V_4 . V_330 [ 1 ] , V_328 , V_97 ) ;
return F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_307 , V_84 ,
V_329 , & V_4 ) ;
}
T_14 F_308 ( const struct V_64 * V_69 , T_4 V_84 ,
T_4 V_97 , T_4 * V_328 )
{
union V_300 V_4 ;
int V_11 ;
if ( V_97 > V_331 )
V_97 = V_331 ;
V_4 . V_330 [ 0 ] = V_97 ;
V_11 = F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_304 , V_84 ,
V_332 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_328 , & V_4 . V_330 [ 1 ] , V_4 . V_330 [ 0 ] ) ;
return V_4 . V_330 [ 0 ] ;
}
T_14 F_309 ( const struct V_64 * V_69 , T_4 V_84 ,
T_4 V_97 , const T_4 * V_328 )
{
union V_300 V_4 ;
if ( V_97 > V_331 )
V_97 = V_331 ;
V_4 . V_330 [ 0 ] = V_97 ;
memcpy ( V_4 . V_330 + 1 , V_328 , V_97 ) ;
return F_294 ( V_69 -> V_37 , V_69 -> V_12 , V_69 -> V_27 ,
V_307 , V_84 ,
V_332 , & V_4 ) ;
}
static T_14 F_310 ( struct V_36 * V_37 , T_8 V_12 ,
unsigned short V_27 ,
char V_333 , T_4 V_84 , int V_334 ,
union V_300 * V_4 )
{
unsigned char V_335 [ V_331 + 3 ] ;
unsigned char V_336 [ V_331 + 2 ] ;
int V_277 = V_333 == V_304 ? 2 : 1 ;
int V_135 ;
T_4 V_337 = 0 ;
int V_11 ;
struct V_75 V_275 [ 2 ] = {
{
. V_12 = V_12 ,
. V_27 = V_27 ,
. V_80 = 1 ,
. V_81 = V_335 ,
} , {
. V_12 = V_12 ,
. V_27 = V_27 | V_82 ,
. V_80 = 0 ,
. V_81 = V_336 ,
} ,
} ;
V_335 [ 0 ] = V_84 ;
switch ( V_334 ) {
case V_308 :
V_275 [ 0 ] . V_80 = 0 ;
V_275 [ 0 ] . V_27 = V_27 | ( V_333 == V_304 ?
V_82 : 0 ) ;
V_277 = 1 ;
break;
case V_310 :
if ( V_333 == V_304 ) {
V_275 [ 0 ] . V_27 = V_82 | V_27 ;
V_277 = 1 ;
}
break;
case V_305 :
if ( V_333 == V_304 )
V_275 [ 1 ] . V_80 = 1 ;
else {
V_275 [ 0 ] . V_80 = 2 ;
V_335 [ 1 ] = V_4 -> V_325 ;
}
break;
case V_326 :
if ( V_333 == V_304 )
V_275 [ 1 ] . V_80 = 2 ;
else {
V_275 [ 0 ] . V_80 = 3 ;
V_335 [ 1 ] = V_4 -> V_327 & 0xff ;
V_335 [ 2 ] = V_4 -> V_327 >> 8 ;
}
break;
case V_338 :
V_277 = 2 ;
V_333 = V_304 ;
V_275 [ 0 ] . V_80 = 3 ;
V_275 [ 1 ] . V_80 = 2 ;
V_335 [ 1 ] = V_4 -> V_327 & 0xff ;
V_335 [ 2 ] = V_4 -> V_327 >> 8 ;
break;
case V_329 :
if ( V_333 == V_304 ) {
V_275 [ 1 ] . V_27 |= V_297 ;
V_275 [ 1 ] . V_80 = 1 ;
} else {
V_275 [ 0 ] . V_80 = V_4 -> V_330 [ 0 ] + 2 ;
if ( V_275 [ 0 ] . V_80 > V_331 + 2 ) {
F_26 ( & V_37 -> V_40 ,
L_109 ,
V_4 -> V_330 [ 0 ] ) ;
return - V_35 ;
}
for ( V_135 = 1 ; V_135 < V_275 [ 0 ] . V_80 ; V_135 ++ )
V_335 [ V_135 ] = V_4 -> V_330 [ V_135 - 1 ] ;
}
break;
case V_339 :
V_277 = 2 ;
V_333 = V_304 ;
if ( V_4 -> V_330 [ 0 ] > V_331 ) {
F_26 ( & V_37 -> V_40 ,
L_109 ,
V_4 -> V_330 [ 0 ] ) ;
return - V_35 ;
}
V_275 [ 0 ] . V_80 = V_4 -> V_330 [ 0 ] + 2 ;
for ( V_135 = 1 ; V_135 < V_275 [ 0 ] . V_80 ; V_135 ++ )
V_335 [ V_135 ] = V_4 -> V_330 [ V_135 - 1 ] ;
V_275 [ 1 ] . V_27 |= V_297 ;
V_275 [ 1 ] . V_80 = 1 ;
break;
case V_332 :
if ( V_333 == V_304 ) {
V_275 [ 1 ] . V_80 = V_4 -> V_330 [ 0 ] ;
} else {
V_275 [ 0 ] . V_80 = V_4 -> V_330 [ 0 ] + 1 ;
if ( V_275 [ 0 ] . V_80 > V_331 + 1 ) {
F_26 ( & V_37 -> V_40 ,
L_109 ,
V_4 -> V_330 [ 0 ] ) ;
return - V_35 ;
}
for ( V_135 = 1 ; V_135 <= V_4 -> V_330 [ 0 ] ; V_135 ++ )
V_335 [ V_135 ] = V_4 -> V_330 [ V_135 ] ;
}
break;
default:
F_26 ( & V_37 -> V_40 , L_110 , V_334 ) ;
return - V_143 ;
}
V_135 = ( ( V_27 & V_340 ) && V_334 != V_308
&& V_334 != V_332 ) ;
if ( V_135 ) {
if ( ! ( V_275 [ 0 ] . V_27 & V_82 ) ) {
if ( V_277 == 1 )
F_306 ( & V_275 [ 0 ] ) ;
else
V_337 = F_304 ( 0 , & V_275 [ 0 ] ) ;
}
if ( V_275 [ V_277 - 1 ] . V_27 & V_82 )
V_275 [ V_277 - 1 ] . V_80 ++ ;
}
V_11 = F_50 ( V_37 , V_275 , V_277 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_135 && ( V_275 [ V_277 - 1 ] . V_27 & V_82 ) ) {
V_11 = F_307 ( V_337 , & V_275 [ V_277 - 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_333 == V_304 )
switch ( V_334 ) {
case V_310 :
V_4 -> V_325 = V_335 [ 0 ] ;
break;
case V_305 :
V_4 -> V_325 = V_336 [ 0 ] ;
break;
case V_326 :
case V_338 :
V_4 -> V_327 = V_336 [ 0 ] | ( V_336 [ 1 ] << 8 ) ;
break;
case V_332 :
for ( V_135 = 0 ; V_135 < V_4 -> V_330 [ 0 ] ; V_135 ++ )
V_4 -> V_330 [ V_135 + 1 ] = V_336 [ V_135 ] ;
break;
case V_329 :
case V_339 :
for ( V_135 = 0 ; V_135 < V_336 [ 0 ] + 1 ; V_135 ++ )
V_4 -> V_330 [ V_135 ] = V_336 [ V_135 ] ;
break;
}
return 0 ;
}
T_14 F_294 ( struct V_36 * V_37 , T_8 V_12 , unsigned short V_27 ,
char V_333 , T_4 V_84 , int V_341 ,
union V_300 * V_4 )
{
unsigned long V_292 ;
int V_293 ;
T_14 V_44 ;
F_311 ( V_37 , V_12 , V_27 , V_333 ,
V_84 , V_341 , V_4 ) ;
F_312 ( V_37 , V_12 , V_27 , V_333 ,
V_84 , V_341 ) ;
V_27 &= V_299 | V_340 | V_342 ;
if ( V_37 -> V_236 -> V_343 ) {
F_288 ( V_37 , V_298 ) ;
V_292 = V_294 ;
for ( V_44 = 0 , V_293 = 0 ; V_293 <= V_37 -> V_295 ; V_293 ++ ) {
V_44 = V_37 -> V_236 -> V_343 ( V_37 , V_12 , V_27 ,
V_333 , V_84 ,
V_341 , V_4 ) ;
if ( V_44 != - V_234 )
break;
if ( F_281 ( V_294 ,
V_292 + V_37 -> V_240 ) )
break;
}
F_289 ( V_37 , V_298 ) ;
if ( V_44 != - V_143 || ! V_37 -> V_236 -> V_296 )
goto V_344;
}
V_44 = F_310 ( V_37 , V_12 , V_27 , V_333 ,
V_84 , V_341 , V_4 ) ;
V_344:
F_313 ( V_37 , V_12 , V_27 , V_333 ,
V_84 , V_341 , V_4 ) ;
F_314 ( V_37 , V_12 , V_27 , V_333 ,
V_84 , V_341 , V_44 ) ;
return V_44 ;
}
T_14 F_315 ( const struct V_64 * V_69 ,
T_4 V_84 , T_4 V_97 , T_4 * V_328 )
{
T_4 V_135 = 0 ;
int V_11 ;
if ( V_97 > V_331 )
V_97 = V_331 ;
if ( F_203 ( V_69 -> V_37 , V_345 ) )
return F_308 ( V_69 , V_84 , V_97 , V_328 ) ;
if ( ! F_203 ( V_69 -> V_37 , V_303 ) )
return - V_143 ;
if ( F_203 ( V_69 -> V_37 , V_346 ) ) {
while ( ( V_135 + 2 ) <= V_97 ) {
V_11 = F_60 ( V_69 , V_84 + V_135 ) ;
if ( V_11 < 0 )
return V_11 ;
V_328 [ V_135 ] = V_11 & 0xff ;
V_328 [ V_135 + 1 ] = V_11 >> 8 ;
V_135 += 2 ;
}
}
while ( V_135 < V_97 ) {
V_11 = F_58 ( V_69 , V_84 + V_135 ) ;
if ( V_11 < 0 )
return V_11 ;
V_328 [ V_135 ] = V_11 ;
V_135 ++ ;
}
return V_135 ;
}
int F_316 ( struct V_64 * V_69 , T_15 V_347 )
{
int V_33 ;
if ( ! V_69 || ! V_347 ) {
F_209 ( 1 , L_111 ) ;
return - V_35 ;
}
if ( ! ( V_69 -> V_27 & V_166 ) )
F_32 ( & V_69 -> V_40 , L_112 ,
V_348 ) ;
if ( ! ( V_69 -> V_27 & V_28 ) ) {
V_33 = F_122 ( V_69 -> V_12 ) ;
if ( V_33 ) {
F_26 ( & V_69 -> V_40 , L_113 , V_348 ) ;
return V_33 ;
}
}
if ( ! V_69 -> V_37 -> V_236 -> V_349 ) {
F_26 ( & V_69 -> V_40 , L_114 , V_348 ) ;
return - V_143 ;
}
V_69 -> V_347 = V_347 ;
F_317 ( V_69 -> V_37 ) ;
V_33 = V_69 -> V_37 -> V_236 -> V_349 ( V_69 ) ;
F_318 ( V_69 -> V_37 ) ;
if ( V_33 ) {
V_69 -> V_347 = NULL ;
F_26 ( & V_69 -> V_40 , L_115 , V_348 , V_33 ) ;
}
return V_33 ;
}
int F_319 ( struct V_64 * V_69 )
{
int V_33 ;
if ( ! V_69 -> V_37 -> V_236 -> V_350 ) {
F_26 ( & V_69 -> V_40 , L_114 , V_348 ) ;
return - V_143 ;
}
F_317 ( V_69 -> V_37 ) ;
V_33 = V_69 -> V_37 -> V_236 -> V_350 ( V_69 ) ;
F_318 ( V_69 -> V_37 ) ;
if ( V_33 == 0 )
V_69 -> V_347 = NULL ;
else
F_26 ( & V_69 -> V_40 , L_115 , V_348 , V_33 ) ;
return V_33 ;
}
bool F_320 ( struct V_60 * V_40 )
{
if ( F_321 ( V_351 ) && V_40 -> V_151 ) {
struct V_189 * V_352 ;
T_3 V_353 ;
F_322 (dev->of_node, child) {
F_323 ( V_352 , L_35 , & V_353 ) ;
if ( V_353 & V_214 ) {
F_180 ( V_352 ) ;
return true ;
}
}
} else if ( F_321 ( V_273 ) && F_16 ( V_40 ) ) {
F_96 ( V_40 , L_116 ) ;
}
return false ;
}
