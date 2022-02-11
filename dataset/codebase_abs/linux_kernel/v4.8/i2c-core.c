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
if ( V_10 -> V_21 == V_22 )
V_8 -> V_23 |= V_24 ;
return 1 ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_7 * V_8 ,
T_2 * V_19 )
{
struct V_27 V_28 ;
struct V_29 * V_30 ;
struct V_5 V_6 ;
int V_31 ;
if ( F_9 ( V_26 ) || ! V_26 -> V_11 . V_32 ||
F_10 ( V_26 ) )
return - V_33 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_34 = F_11 ( V_26 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_16 = F_12 ( V_26 ) ;
V_6 . V_8 = V_8 ;
F_13 ( & V_28 ) ;
V_31 = F_14 ( V_26 , & V_28 ,
F_5 , & V_6 ) ;
F_15 ( & V_28 ) ;
if ( V_31 < 0 || ! V_8 -> V_12 )
return - V_33 ;
* V_19 = V_6 . V_19 ;
V_31 = F_14 ( V_26 , & V_28 , NULL , NULL ) ;
if ( V_31 < 0 )
return - V_33 ;
F_16 (entry, &resource_list) {
if ( F_17 ( V_30 -> V_35 ) == V_36 ) {
V_8 -> V_37 = V_30 -> V_35 -> V_38 ;
break;
}
}
F_15 ( & V_28 ) ;
F_18 ( V_8 -> type , F_19 ( & V_26 -> V_39 ) , sizeof( V_8 -> type ) ) ;
return 0 ;
}
static void F_20 ( struct V_40 * V_41 ,
struct V_25 * V_26 ,
struct V_7 * V_8 )
{
V_26 -> V_42 . V_23 . V_43 = true ;
F_21 ( V_26 ) ;
if ( ! F_22 ( V_41 , V_8 ) ) {
V_26 -> V_42 . V_23 . V_43 = false ;
F_23 ( & V_41 -> V_39 ,
L_1 ,
F_19 ( & V_26 -> V_39 ) ) ;
}
}
static T_1 F_24 ( T_2 V_44 , T_3 V_45 ,
void * V_4 , void * * V_46 )
{
struct V_40 * V_41 = V_4 ;
struct V_25 * V_26 ;
T_2 V_19 ;
struct V_7 V_8 ;
if ( F_25 ( V_44 , & V_26 ) )
return V_47 ;
if ( F_8 ( V_26 , & V_8 , & V_19 ) )
return V_47 ;
if ( V_19 != F_26 ( & V_41 -> V_39 ) )
return V_47 ;
F_20 ( V_41 , V_26 , & V_8 ) ;
return V_47 ;
}
static void F_27 ( struct V_40 * V_48 )
{
T_1 V_11 ;
if ( ! F_28 ( & V_48 -> V_39 ) )
return;
V_11 = F_29 ( V_49 , V_50 ,
V_51 ,
F_24 , NULL ,
V_48 , NULL ) ;
if ( F_30 ( V_11 ) )
F_31 ( & V_48 -> V_39 , L_2 ) ;
}
static int F_32 ( struct V_52 * V_39 , void * V_4 )
{
struct V_40 * V_41 = F_33 ( V_39 ) ;
if ( ! V_41 )
return 0 ;
return F_26 ( V_39 ) == ( T_2 ) V_4 ;
}
static int F_34 ( struct V_52 * V_39 , void * V_4 )
{
return F_35 ( V_39 ) == V_4 ;
}
static struct V_40 * F_36 ( T_2 V_44 )
{
struct V_52 * V_39 ;
V_39 = F_37 ( & V_53 , NULL , V_44 ,
F_32 ) ;
return V_39 ? F_33 ( V_39 ) : NULL ;
}
static struct V_54 * F_38 ( struct V_25 * V_26 )
{
struct V_52 * V_39 ;
V_39 = F_37 ( & V_53 , NULL , V_26 , F_34 ) ;
return V_39 ? F_39 ( V_39 ) : NULL ;
}
static int F_40 ( struct V_55 * V_56 , unsigned long V_57 ,
void * V_58 )
{
struct V_25 * V_26 = V_58 ;
struct V_7 V_8 ;
T_2 V_19 ;
struct V_40 * V_41 ;
struct V_54 * V_59 ;
switch ( V_57 ) {
case V_60 :
if ( F_8 ( V_26 , & V_8 , & V_19 ) )
break;
V_41 = F_36 ( V_19 ) ;
if ( ! V_41 )
break;
F_20 ( V_41 , V_26 , & V_8 ) ;
break;
case V_61 :
if ( ! F_10 ( V_26 ) )
break;
V_59 = F_38 ( V_26 ) ;
if ( ! V_59 )
break;
F_41 ( V_59 ) ;
F_42 ( & V_59 -> V_39 ) ;
break;
}
return V_62 ;
}
static inline void F_27 ( struct V_40 * V_48 ) { }
static int F_43 ( struct V_54 * V_59 ,
T_4 V_63 , T_4 * V_4 , T_4 V_64 )
{
struct V_65 V_66 [ 2 ] ;
int V_31 ;
T_4 * V_67 ;
V_67 = F_44 ( V_64 , V_68 ) ;
if ( ! V_67 )
return V_69 ;
V_66 [ 0 ] . V_12 = V_59 -> V_12 ;
V_66 [ 0 ] . V_23 = V_59 -> V_23 ;
V_66 [ 0 ] . V_70 = 1 ;
V_66 [ 0 ] . V_71 = & V_63 ;
V_66 [ 1 ] . V_12 = V_59 -> V_12 ;
V_66 [ 1 ] . V_23 = V_59 -> V_23 | V_72 ;
V_66 [ 1 ] . V_70 = V_64 ;
V_66 [ 1 ] . V_71 = V_67 ;
V_31 = F_45 ( V_59 -> V_41 , V_66 , F_46 ( V_66 ) ) ;
if ( V_31 < 0 )
F_23 ( & V_59 -> V_41 -> V_39 , L_3 ) ;
else
memcpy ( V_4 , V_67 , V_64 ) ;
F_47 ( V_67 ) ;
return V_31 ;
}
static int F_48 ( struct V_54 * V_59 ,
T_4 V_63 , T_4 * V_4 , T_4 V_64 )
{
struct V_65 V_66 [ 1 ] ;
T_4 * V_67 ;
int V_31 = V_47 ;
V_67 = F_44 ( V_64 + 1 , V_68 ) ;
if ( ! V_67 )
return V_69 ;
V_67 [ 0 ] = V_63 ;
memcpy ( V_67 + 1 , V_4 , V_64 ) ;
V_66 [ 0 ] . V_12 = V_59 -> V_12 ;
V_66 [ 0 ] . V_23 = V_59 -> V_23 ;
V_66 [ 0 ] . V_70 = V_64 + 1 ;
V_66 [ 0 ] . V_71 = V_67 ;
V_31 = F_45 ( V_59 -> V_41 , V_66 , F_46 ( V_66 ) ) ;
if ( V_31 < 0 )
F_23 ( & V_59 -> V_41 -> V_39 , L_4 ) ;
F_47 ( V_67 ) ;
return V_31 ;
}
static T_1
F_49 ( T_3 V_73 , T_5 V_74 ,
T_3 V_75 , T_6 * V_76 ,
void * V_77 , void * V_78 )
{
struct V_79 * V_80 = (struct V_79 * ) V_76 ;
struct V_81 * V_4 = V_77 ;
struct V_82 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_54 * V_59 ;
struct V_2 * V_3 ;
T_3 V_83 = V_73 >> 16 ;
T_4 V_84 = V_73 & V_85 ;
T_1 V_31 ;
int V_11 ;
V_31 = F_50 ( V_8 -> V_86 , V_8 -> V_87 , & V_3 ) ;
if ( F_30 ( V_31 ) )
return V_31 ;
V_59 = F_44 ( sizeof( * V_59 ) , V_68 ) ;
if ( ! V_59 ) {
V_31 = V_69 ;
goto V_88;
}
if ( ! V_76 || V_3 -> type != V_13 ) {
V_31 = V_89 ;
goto V_88;
}
V_10 = & V_3 -> V_4 . V_14 ;
if ( V_10 -> type != V_15 ) {
V_31 = V_89 ;
goto V_88;
}
V_59 -> V_41 = V_41 ;
V_59 -> V_12 = V_10 -> V_20 ;
if ( V_10 -> V_21 == V_22 )
V_59 -> V_23 |= V_24 ;
switch ( V_83 ) {
case V_90 :
if ( V_84 == V_91 ) {
V_11 = F_51 ( V_59 ) ;
if ( V_11 >= 0 ) {
V_80 -> V_92 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_52 ( V_59 , V_80 -> V_92 ) ;
}
break;
case V_93 :
if ( V_84 == V_91 ) {
V_11 = F_53 ( V_59 , V_74 ) ;
if ( V_11 >= 0 ) {
V_80 -> V_92 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_54 ( V_59 , V_74 ,
V_80 -> V_92 ) ;
}
break;
case V_94 :
if ( V_84 == V_91 ) {
V_11 = F_55 ( V_59 , V_74 ) ;
if ( V_11 >= 0 ) {
V_80 -> V_95 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_56 ( V_59 , V_74 ,
V_80 -> V_95 ) ;
}
break;
case V_96 :
if ( V_84 == V_91 ) {
V_11 = F_57 ( V_59 , V_74 ,
V_80 -> V_4 ) ;
if ( V_11 >= 0 ) {
V_80 -> V_70 = V_11 ;
V_11 = 0 ;
}
} else {
V_11 = F_58 ( V_59 , V_74 ,
V_80 -> V_70 , V_80 -> V_4 ) ;
}
break;
case V_97 :
if ( V_84 == V_91 ) {
V_11 = F_43 ( V_59 , V_74 ,
V_80 -> V_4 , V_8 -> V_98 ) ;
if ( V_11 > 0 )
V_11 = 0 ;
} else {
V_11 = F_48 ( V_59 , V_74 ,
V_80 -> V_4 , V_8 -> V_98 ) ;
}
break;
default:
F_31 ( & V_41 -> V_39 , L_5 ,
V_83 , V_59 -> V_12 ) ;
V_31 = V_89 ;
goto V_88;
}
V_80 -> V_11 = V_11 ;
V_88:
F_47 ( V_59 ) ;
F_59 ( V_3 ) ;
return V_31 ;
}
static int F_60 ( struct V_40 * V_41 )
{
T_2 V_44 ;
struct V_81 * V_4 ;
T_1 V_11 ;
if ( ! V_41 -> V_39 . V_99 )
return - V_100 ;
V_44 = F_26 ( V_41 -> V_39 . V_99 ) ;
if ( ! V_44 )
return - V_100 ;
V_4 = F_44 ( sizeof( struct V_81 ) ,
V_68 ) ;
if ( ! V_4 )
return - V_101 ;
V_4 -> V_41 = V_41 ;
V_11 = F_61 ( V_44 , ( void * ) V_4 ) ;
if ( F_30 ( V_11 ) ) {
F_47 ( V_4 ) ;
return - V_101 ;
}
V_11 = F_62 ( V_44 ,
V_102 ,
& F_49 ,
NULL ,
V_4 ) ;
if ( F_30 ( V_11 ) ) {
F_23 ( & V_41 -> V_39 , L_6 ) ;
F_63 ( V_44 ) ;
F_47 ( V_4 ) ;
return - V_101 ;
}
F_64 ( V_44 ) ;
return 0 ;
}
static void F_65 ( struct V_40 * V_41 )
{
T_2 V_44 ;
struct V_81 * V_4 ;
T_1 V_11 ;
if ( ! V_41 -> V_39 . V_99 )
return;
V_44 = F_26 ( V_41 -> V_39 . V_99 ) ;
if ( ! V_44 )
return;
F_66 ( V_44 ,
V_102 ,
& F_49 ) ;
V_11 = F_67 ( V_44 , ( void * * ) & V_4 ) ;
if ( F_7 ( V_11 ) )
F_47 ( V_4 ) ;
F_63 ( V_44 ) ;
}
static inline void F_65 ( struct V_40 * V_41 )
{ }
static inline int F_60 ( struct V_40 * V_41 )
{ return 0 ; }
static const struct V_103 * F_68 ( const struct V_103 * V_104 ,
const struct V_54 * V_59 )
{
while ( V_104 -> V_105 [ 0 ] ) {
if ( strcmp ( V_59 -> V_105 , V_104 -> V_105 ) == 0 )
return V_104 ;
V_104 ++ ;
}
return NULL ;
}
static int F_69 ( struct V_52 * V_39 , struct V_106 * V_107 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
struct V_108 * V_109 ;
if ( ! V_59 )
return 0 ;
if ( F_70 ( V_39 , V_107 ) )
return 1 ;
if ( F_71 ( V_39 , V_107 ) )
return 1 ;
V_109 = F_72 ( V_107 ) ;
if ( V_109 -> V_110 )
return F_68 ( V_109 -> V_110 , V_59 ) != NULL ;
return 0 ;
}
static int F_73 ( struct V_52 * V_39 , struct V_111 * V_112 )
{
struct V_54 * V_59 = F_74 ( V_39 ) ;
int V_113 ;
V_113 = F_75 ( V_39 , V_112 ) ;
if ( V_113 != - V_100 )
return V_113 ;
return F_76 ( V_112 , L_7 , V_114 , V_59 -> V_105 ) ;
}
static int F_77 ( struct V_40 * V_48 )
{
return F_78 ( V_48 -> V_115 -> V_116 ) ;
}
static void F_79 ( struct V_40 * V_48 , int V_117 )
{
F_80 ( V_48 -> V_115 -> V_116 , V_117 ) ;
}
static int F_81 ( struct V_40 * V_48 )
{
return F_78 ( V_48 -> V_115 -> V_118 ) ;
}
static int F_82 ( struct V_40 * V_48 )
{
struct V_119 * V_120 = V_48 -> V_115 ;
struct V_52 * V_39 = & V_48 -> V_39 ;
int V_31 = 0 ;
V_31 = F_83 ( V_120 -> V_116 , V_121 |
V_122 , L_8 ) ;
if ( V_31 ) {
F_31 ( V_39 , L_9 , V_120 -> V_116 ) ;
return V_31 ;
}
if ( V_120 -> V_123 ) {
if ( F_83 ( V_120 -> V_118 , V_124 , L_10 ) ) {
F_31 ( V_39 , L_11 ,
V_120 -> V_118 ) ;
V_120 -> V_123 = NULL ;
}
}
return V_31 ;
}
static void F_84 ( struct V_40 * V_48 )
{
struct V_119 * V_120 = V_48 -> V_115 ;
if ( V_120 -> V_123 )
F_85 ( V_120 -> V_118 ) ;
F_85 ( V_120 -> V_116 ) ;
}
static int F_86 ( struct V_40 * V_48 )
{
struct V_119 * V_120 = V_48 -> V_115 ;
int V_125 = 0 , V_117 = 1 , V_31 = 0 ;
if ( V_120 -> V_126 )
V_120 -> V_126 ( V_48 ) ;
V_120 -> V_127 ( V_48 , V_117 ) ;
F_87 ( V_128 ) ;
while ( V_125 ++ < V_129 * 2 ) {
if ( V_117 ) {
if ( V_120 -> V_123 && V_120 -> V_123 ( V_48 ) )
break;
if ( ! V_120 -> V_130 ( V_48 ) ) {
F_23 ( & V_48 -> V_39 ,
L_12 ) ;
V_31 = - V_131 ;
break;
}
}
V_117 = ! V_117 ;
V_120 -> V_127 ( V_48 , V_117 ) ;
F_87 ( V_128 ) ;
}
if ( V_120 -> V_132 )
V_120 -> V_132 ( V_48 ) ;
return V_31 ;
}
int F_88 ( struct V_40 * V_48 )
{
return F_86 ( V_48 ) ;
}
int F_89 ( struct V_40 * V_48 )
{
int V_31 ;
V_31 = F_82 ( V_48 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_86 ( V_48 ) ;
F_84 ( V_48 ) ;
return V_31 ;
}
int F_90 ( struct V_40 * V_48 )
{
if ( ! V_48 -> V_115 )
return - V_133 ;
F_91 ( & V_48 -> V_39 , L_13 ) ;
return V_48 -> V_115 -> V_134 ( V_48 ) ;
}
static void F_92 ( struct V_40 * V_48 )
{
struct V_119 * V_120 = V_48 -> V_115 ;
char * V_135 ;
if ( ! V_120 )
return;
if ( ! V_120 -> V_134 ) {
V_135 = L_14 ;
goto V_88;
}
if ( V_120 -> V_134 == F_89 ) {
if ( ! F_93 ( V_120 -> V_116 ) ) {
V_135 = L_15 ;
goto V_88;
}
if ( F_93 ( V_120 -> V_118 ) )
V_120 -> V_123 = F_81 ;
else
V_120 -> V_123 = NULL ;
V_120 -> V_130 = F_77 ;
V_120 -> V_127 = F_79 ;
} else if ( V_120 -> V_134 == F_88 ) {
if ( ! V_120 -> V_127 || ! V_120 -> V_130 ) {
V_135 = L_16 ;
goto V_88;
}
}
return;
V_88:
F_23 ( & V_48 -> V_39 , L_17 , V_135 ) ;
V_48 -> V_115 = NULL ;
}
static int F_94 ( struct V_52 * V_39 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
struct V_108 * V_109 ;
int V_11 ;
if ( ! V_59 )
return 0 ;
if ( ! V_59 -> V_37 ) {
int V_37 = - V_136 ;
if ( V_39 -> V_137 ) {
V_37 = F_95 ( V_39 -> V_137 , L_18 ) ;
if ( V_37 == - V_33 || V_37 == - V_138 )
V_37 = F_96 ( V_39 -> V_137 , 0 ) ;
} else if ( F_35 ( V_39 ) ) {
V_37 = F_97 ( F_35 ( V_39 ) , 0 ) ;
}
if ( V_37 == - V_139 )
return V_37 ;
if ( V_37 < 0 )
V_37 = 0 ;
V_59 -> V_37 = V_37 ;
}
V_109 = F_72 ( V_39 -> V_109 ) ;
if ( ! V_109 -> V_140 || ! V_109 -> V_110 )
return - V_100 ;
if ( V_59 -> V_23 & V_141 ) {
int V_142 = - V_136 ;
if ( V_39 -> V_137 ) {
V_142 = F_95 ( V_39 -> V_137 , L_19 ) ;
if ( V_142 == - V_139 )
return V_142 ;
}
F_98 ( & V_59 -> V_39 , true ) ;
if ( V_142 > 0 && V_142 != V_59 -> V_37 )
V_11 = F_99 ( V_39 , V_142 ) ;
else if ( V_59 -> V_37 > 0 )
V_11 = F_100 ( V_39 , V_59 -> V_37 ) ;
else
V_11 = 0 ;
if ( V_11 )
F_31 ( & V_59 -> V_39 , L_20 ) ;
}
F_91 ( V_39 , L_21 ) ;
V_11 = F_101 ( V_39 -> V_137 , false ) ;
if ( V_11 < 0 )
goto V_143;
V_11 = F_102 ( & V_59 -> V_39 , true ) ;
if ( V_11 == - V_139 )
goto V_143;
V_11 = V_109 -> V_140 ( V_59 , F_68 ( V_109 -> V_110 , V_59 ) ) ;
if ( V_11 )
goto V_144;
return 0 ;
V_144:
F_103 ( & V_59 -> V_39 , true ) ;
V_143:
F_104 ( & V_59 -> V_39 ) ;
F_98 ( & V_59 -> V_39 , false ) ;
return V_11 ;
}
static int F_105 ( struct V_52 * V_39 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
struct V_108 * V_109 ;
int V_11 = 0 ;
if ( ! V_59 || ! V_39 -> V_109 )
return 0 ;
V_109 = F_72 ( V_39 -> V_109 ) ;
if ( V_109 -> remove ) {
F_91 ( V_39 , L_22 ) ;
V_11 = V_109 -> remove ( V_59 ) ;
}
F_103 ( & V_59 -> V_39 , true ) ;
F_104 ( & V_59 -> V_39 ) ;
F_98 ( & V_59 -> V_39 , false ) ;
return V_11 ;
}
static void F_106 ( struct V_52 * V_39 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
struct V_108 * V_109 ;
if ( ! V_59 || ! V_39 -> V_109 )
return;
V_109 = F_72 ( V_39 -> V_109 ) ;
if ( V_109 -> V_145 )
V_109 -> V_145 ( V_59 ) ;
}
static void F_107 ( struct V_52 * V_39 )
{
F_47 ( F_74 ( V_39 ) ) ;
}
static T_7
F_108 ( struct V_52 * V_39 , struct V_146 * V_147 , char * V_71 )
{
return sprintf ( V_71 , L_23 , V_39 -> type == & V_148 ?
F_74 ( V_39 ) -> V_105 : F_109 ( V_39 ) -> V_105 ) ;
}
static T_7
F_110 ( struct V_52 * V_39 , struct V_146 * V_147 , char * V_71 )
{
struct V_54 * V_59 = F_74 ( V_39 ) ;
int V_70 ;
V_70 = F_111 ( V_39 , V_71 , V_149 - 1 ) ;
if ( V_70 != - V_100 )
return V_70 ;
return sprintf ( V_71 , L_24 , V_114 , V_59 -> V_105 ) ;
}
struct V_54 * F_39 ( struct V_52 * V_39 )
{
return ( V_39 -> type == & V_148 )
? F_74 ( V_39 )
: NULL ;
}
static unsigned short F_112 ( struct V_54 * V_59 )
{
unsigned short V_12 = V_59 -> V_12 ;
if ( V_59 -> V_23 & V_24 )
V_12 |= V_150 ;
if ( V_59 -> V_23 & V_151 )
V_12 |= V_152 ;
return V_12 ;
}
static int F_113 ( unsigned V_12 , unsigned short V_23 )
{
if ( V_23 & V_24 ) {
if ( V_12 > 0x3ff )
return - V_33 ;
} else {
if ( V_12 == 0x00 || V_12 > 0x7f )
return - V_33 ;
}
return 0 ;
}
static int F_114 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_33 ;
return 0 ;
}
static int F_115 ( struct V_52 * V_39 , void * V_153 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
int V_12 = * ( int * ) V_153 ;
if ( V_59 && F_112 ( V_59 ) == V_12 )
return - V_131 ;
return 0 ;
}
static int F_116 ( struct V_40 * V_41 , int V_12 )
{
struct V_40 * V_99 = F_117 ( V_41 ) ;
int V_154 ;
V_154 = F_118 ( & V_41 -> V_39 , & V_12 ,
F_115 ) ;
if ( ! V_154 && V_99 )
V_154 = F_116 ( V_99 , V_12 ) ;
return V_154 ;
}
static int F_119 ( struct V_52 * V_39 , void * V_153 )
{
int V_154 ;
if ( V_39 -> type == & V_155 )
V_154 = F_118 ( V_39 , V_153 ,
F_119 ) ;
else
V_154 = F_115 ( V_39 , V_153 ) ;
return V_154 ;
}
static int F_120 ( struct V_40 * V_41 , int V_12 )
{
struct V_40 * V_99 = F_117 ( V_41 ) ;
int V_154 = 0 ;
if ( V_99 )
V_154 = F_116 ( V_99 , V_12 ) ;
if ( ! V_154 )
V_154 = F_118 ( & V_41 -> V_39 , & V_12 ,
F_119 ) ;
return V_154 ;
}
static void F_121 ( struct V_40 * V_41 ,
unsigned int V_23 )
{
F_122 ( & V_41 -> V_156 ) ;
}
static int F_123 ( struct V_40 * V_41 ,
unsigned int V_23 )
{
return F_124 ( & V_41 -> V_156 ) ;
}
static void F_125 ( struct V_40 * V_41 ,
unsigned int V_23 )
{
F_126 ( & V_41 -> V_156 ) ;
}
static void F_127 ( struct V_40 * V_48 ,
struct V_54 * V_59 )
{
struct V_25 * V_26 = F_35 ( & V_59 -> V_39 ) ;
if ( V_26 ) {
F_128 ( & V_59 -> V_39 , L_25 , F_129 ( V_26 ) ) ;
return;
}
F_128 ( & V_59 -> V_39 , L_26 , F_130 ( V_48 ) ,
F_112 ( V_59 ) ) ;
}
struct V_54 *
F_22 ( struct V_40 * V_48 , struct V_7 const * V_8 )
{
struct V_54 * V_59 ;
int V_11 ;
V_59 = F_44 ( sizeof *V_59 , V_68 ) ;
if ( ! V_59 )
return NULL ;
V_59 -> V_41 = V_48 ;
V_59 -> V_39 . V_157 = V_8 -> V_157 ;
if ( V_8 -> V_158 )
V_59 -> V_39 . V_158 = * V_8 -> V_158 ;
V_59 -> V_23 = V_8 -> V_23 ;
V_59 -> V_12 = V_8 -> V_12 ;
V_59 -> V_37 = V_8 -> V_37 ;
F_18 ( V_59 -> V_105 , V_8 -> type , sizeof( V_59 -> V_105 ) ) ;
V_11 = F_113 ( V_59 -> V_12 , V_59 -> V_23 ) ;
if ( V_11 ) {
F_23 ( & V_48 -> V_39 , L_27 ,
V_59 -> V_23 & V_24 ? 10 : 7 , V_59 -> V_12 ) ;
goto V_159;
}
V_11 = F_120 ( V_48 , F_112 ( V_59 ) ) ;
if ( V_11 )
goto V_160;
V_59 -> V_39 . V_99 = & V_59 -> V_41 -> V_39 ;
V_59 -> V_39 . V_161 = & V_53 ;
V_59 -> V_39 . type = & V_148 ;
V_59 -> V_39 . V_137 = V_8 -> V_137 ;
V_59 -> V_39 . V_34 = V_8 -> V_34 ;
F_127 ( V_48 , V_59 ) ;
V_11 = F_131 ( & V_59 -> V_39 ) ;
if ( V_11 )
goto V_160;
F_91 ( & V_48 -> V_39 , L_28 ,
V_59 -> V_105 , F_19 ( & V_59 -> V_39 ) ) ;
return V_59 ;
V_160:
F_23 ( & V_48 -> V_39 , L_29
L_30 , V_59 -> V_105 , V_59 -> V_12 , V_11 ) ;
V_159:
F_47 ( V_59 ) ;
return NULL ;
}
void F_41 ( struct V_54 * V_59 )
{
if ( V_59 -> V_39 . V_137 )
F_132 ( V_59 -> V_39 . V_137 , V_162 ) ;
if ( F_35 ( & V_59 -> V_39 ) )
F_133 ( F_35 ( & V_59 -> V_39 ) ) ;
F_134 ( & V_59 -> V_39 ) ;
}
static int F_135 ( struct V_54 * V_59 ,
const struct V_103 * V_104 )
{
return 0 ;
}
static int F_136 ( struct V_54 * V_59 )
{
return 0 ;
}
struct V_54 * F_137 ( struct V_40 * V_41 , T_8 V_163 )
{
struct V_7 V_8 = {
F_138 ( L_31 , V_163 ) ,
} ;
return F_22 ( V_41 , & V_8 ) ;
}
struct V_54 * F_139 ( struct V_54 * V_59 ,
const char * V_105 ,
T_8 V_164 )
{
struct V_165 * V_166 = V_59 -> V_39 . V_137 ;
T_3 V_12 = V_164 ;
int V_125 ;
if ( V_166 ) {
V_125 = F_140 ( V_166 , L_32 , V_105 ) ;
if ( V_125 >= 0 )
F_141 ( V_166 , L_33 , V_125 , & V_12 ) ;
}
F_91 ( & V_59 -> V_41 -> V_39 , L_34 , V_105 , V_12 ) ;
return F_137 ( V_59 -> V_41 , V_12 ) ;
}
static void F_142 ( struct V_52 * V_39 )
{
struct V_40 * V_48 = F_109 ( V_39 ) ;
F_143 ( & V_48 -> V_167 ) ;
}
static inline unsigned int F_144 ( struct V_40 * V_41 )
{
unsigned int V_168 = 0 ;
while ( ( V_41 = F_117 ( V_41 ) ) )
V_168 ++ ;
return V_168 ;
}
static T_7
F_145 ( struct V_52 * V_39 , struct V_146 * V_147 ,
const char * V_71 , T_9 V_169 )
{
struct V_40 * V_48 = F_109 ( V_39 ) ;
struct V_7 V_8 ;
struct V_54 * V_59 ;
char * V_170 , V_171 ;
int V_35 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_170 = strchr ( V_71 , ' ' ) ;
if ( ! V_170 ) {
F_23 ( V_39 , L_35 , L_36 ) ;
return - V_33 ;
}
if ( V_170 - V_71 > V_172 - 1 ) {
F_23 ( V_39 , L_37 , L_36 ) ;
return - V_33 ;
}
memcpy ( V_8 . type , V_71 , V_170 - V_71 ) ;
V_35 = sscanf ( ++ V_170 , L_38 , & V_8 . V_12 , & V_171 ) ;
if ( V_35 < 1 ) {
F_23 ( V_39 , L_39 , L_36 ) ;
return - V_33 ;
}
if ( V_35 > 1 && V_171 != '\n' ) {
F_23 ( V_39 , L_40 , L_36 ) ;
return - V_33 ;
}
if ( ( V_8 . V_12 & V_150 ) == V_150 ) {
V_8 . V_12 &= ~ V_150 ;
V_8 . V_23 |= V_24 ;
}
if ( V_8 . V_12 & V_152 ) {
V_8 . V_12 &= ~ V_152 ;
V_8 . V_23 |= V_151 ;
}
V_59 = F_22 ( V_48 , & V_8 ) ;
if ( ! V_59 )
return - V_33 ;
F_146 ( & V_48 -> V_173 ) ;
F_147 ( & V_59 -> V_174 , & V_48 -> V_175 ) ;
F_148 ( & V_48 -> V_173 ) ;
F_149 ( V_39 , L_41 , L_36 ,
V_8 . type , V_8 . V_12 ) ;
return V_169 ;
}
static T_7
F_150 ( struct V_52 * V_39 , struct V_146 * V_147 ,
const char * V_71 , T_9 V_169 )
{
struct V_40 * V_48 = F_109 ( V_39 ) ;
struct V_54 * V_59 , * V_176 ;
unsigned short V_12 ;
char V_171 ;
int V_35 ;
V_35 = sscanf ( V_71 , L_38 , & V_12 , & V_171 ) ;
if ( V_35 < 1 ) {
F_23 ( V_39 , L_39 , L_42 ) ;
return - V_33 ;
}
if ( V_35 > 1 && V_171 != '\n' ) {
F_23 ( V_39 , L_40 , L_42 ) ;
return - V_33 ;
}
V_35 = - V_136 ;
F_151 ( & V_48 -> V_173 ,
F_144 ( V_48 ) ) ;
F_152 (client, next, &adap->userspace_clients,
detected) {
if ( F_112 ( V_59 ) == V_12 ) {
F_149 ( V_39 , L_43 ,
L_42 , V_59 -> V_105 , V_59 -> V_12 ) ;
F_153 ( & V_59 -> V_174 ) ;
F_41 ( V_59 ) ;
V_35 = V_169 ;
break;
}
}
F_148 ( & V_48 -> V_173 ) ;
if ( V_35 < 0 )
F_23 ( V_39 , L_44 ,
L_42 ) ;
return V_35 ;
}
struct V_40 * F_33 ( struct V_52 * V_39 )
{
return ( V_39 -> type == & V_155 )
? F_109 ( V_39 )
: NULL ;
}
static void F_154 ( struct V_40 * V_41 )
{
struct V_177 * V_178 ;
F_155 ( & V_179 ) ;
F_156 (devinfo, &__i2c_board_list, list) {
if ( V_178 -> V_180 == V_41 -> V_181
&& ! F_22 ( V_41 ,
& V_178 -> V_182 ) )
F_23 ( & V_41 -> V_39 ,
L_45 ,
V_178 -> V_182 . V_12 ) ;
}
F_157 ( & V_179 ) ;
}
static struct V_54 * F_158 ( struct V_40 * V_48 ,
struct V_165 * V_183 )
{
struct V_54 * V_154 ;
struct V_7 V_8 = {} ;
struct V_184 V_185 = {} ;
const T_10 * V_186 ;
T_3 V_12 ;
int V_70 ;
F_91 ( & V_48 -> V_39 , L_46 , V_183 -> V_187 ) ;
if ( F_159 ( V_183 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_23 ( & V_48 -> V_39 , L_47 ,
V_183 -> V_187 ) ;
return F_160 ( - V_33 ) ;
}
V_186 = F_161 ( V_183 , L_33 , & V_70 ) ;
if ( ! V_186 || ( V_70 < sizeof( * V_186 ) ) ) {
F_23 ( & V_48 -> V_39 , L_48 ,
V_183 -> V_187 ) ;
return F_160 ( - V_33 ) ;
}
V_12 = F_162 ( V_186 ) ;
if ( V_12 & V_188 ) {
V_12 &= ~ V_188 ;
V_8 . V_23 |= V_24 ;
}
if ( V_12 & V_189 ) {
V_12 &= ~ V_189 ;
V_8 . V_23 |= V_151 ;
}
if ( F_113 ( V_12 , V_8 . V_23 ) ) {
F_23 ( & V_48 -> V_39 , L_49 ,
V_8 . V_12 , V_183 -> V_187 ) ;
return F_160 ( - V_33 ) ;
}
V_8 . V_12 = V_12 ;
V_8 . V_137 = F_163 ( V_183 ) ;
V_8 . V_158 = & V_185 ;
if ( F_161 ( V_183 , L_50 , NULL ) )
V_8 . V_23 |= V_141 ;
V_154 = F_22 ( V_48 , & V_8 ) ;
if ( V_154 == NULL ) {
F_23 ( & V_48 -> V_39 , L_51 ,
V_183 -> V_187 ) ;
F_164 ( V_183 ) ;
return F_160 ( - V_33 ) ;
}
return V_154 ;
}
static void F_165 ( struct V_40 * V_48 )
{
struct V_165 * V_183 ;
if ( ! V_48 -> V_39 . V_137 )
return;
F_91 ( & V_48 -> V_39 , L_52 ) ;
F_166 (adap->dev.of_node, node) {
if ( F_167 ( V_183 , V_162 ) )
continue;
F_158 ( V_48 , V_183 ) ;
}
}
static int F_168 ( struct V_52 * V_39 , void * V_4 )
{
return V_39 -> V_137 == V_4 ;
}
struct V_54 * F_169 ( struct V_165 * V_183 )
{
struct V_52 * V_39 ;
struct V_54 * V_59 ;
V_39 = F_37 ( & V_53 , NULL , V_183 , F_168 ) ;
if ( ! V_39 )
return NULL ;
V_59 = F_39 ( V_39 ) ;
if ( ! V_59 )
F_42 ( V_39 ) ;
return V_59 ;
}
struct V_40 * F_170 ( struct V_165 * V_183 )
{
struct V_52 * V_39 ;
struct V_40 * V_41 ;
V_39 = F_37 ( & V_53 , NULL , V_183 , F_168 ) ;
if ( ! V_39 )
return NULL ;
V_41 = F_33 ( V_39 ) ;
if ( ! V_41 )
F_42 ( V_39 ) ;
return V_41 ;
}
struct V_40 * F_171 ( struct V_165 * V_183 )
{
struct V_40 * V_41 ;
V_41 = F_170 ( V_183 ) ;
if ( ! V_41 )
return NULL ;
if ( ! F_172 ( V_41 -> V_190 ) ) {
F_42 ( & V_41 -> V_39 ) ;
V_41 = NULL ;
}
return V_41 ;
}
static void F_165 ( struct V_40 * V_48 ) { }
static int F_173 ( struct V_108 * V_109 ,
struct V_40 * V_48 )
{
F_174 ( V_48 , V_109 ) ;
if ( V_109 -> V_191 ) {
F_31 ( & V_48 -> V_39 , L_53 ,
V_109 -> V_109 . V_105 ) ;
F_31 ( & V_48 -> V_39 , L_54
L_55 ) ;
V_109 -> V_191 ( V_48 ) ;
}
return 0 ;
}
static int F_175 ( struct V_106 * V_192 , void * V_4 )
{
return F_173 ( F_72 ( V_192 ) , V_4 ) ;
}
static int F_176 ( struct V_40 * V_48 )
{
int V_35 = - V_33 ;
if ( F_177 ( ! V_193 ) ) {
V_35 = - V_194 ;
goto V_195;
}
if ( F_178 ( ! V_48 -> V_105 [ 0 ] , L_56 ) )
goto V_195;
if ( ! V_48 -> V_196 ) {
F_179 ( L_57 , V_48 -> V_105 ) ;
goto V_195;
}
if ( ! V_48 -> V_197 ) {
V_48 -> V_197 = F_121 ;
V_48 -> V_198 = F_123 ;
V_48 -> V_199 = F_125 ;
}
F_180 ( & V_48 -> V_156 ) ;
F_180 ( & V_48 -> V_200 ) ;
F_181 ( & V_48 -> V_173 ) ;
F_13 ( & V_48 -> V_175 ) ;
if ( V_48 -> V_201 == 0 )
V_48 -> V_201 = V_202 ;
F_128 ( & V_48 -> V_39 , L_58 , V_48 -> V_181 ) ;
V_48 -> V_39 . V_161 = & V_53 ;
V_48 -> V_39 . type = & V_155 ;
V_35 = F_131 ( & V_48 -> V_39 ) ;
if ( V_35 ) {
F_179 ( L_59 , V_48 -> V_105 , V_35 ) ;
goto V_195;
}
F_91 ( & V_48 -> V_39 , L_60 , V_48 -> V_105 ) ;
F_182 ( & V_48 -> V_39 ) ;
F_183 ( & V_48 -> V_39 , true ) ;
F_184 ( & V_48 -> V_39 ) ;
#ifdef F_185
V_35 = F_186 ( V_203 , & V_48 -> V_39 ,
V_48 -> V_39 . V_99 ) ;
if ( V_35 )
F_31 ( & V_48 -> V_39 ,
L_61 ) ;
#endif
F_92 ( V_48 ) ;
F_165 ( V_48 ) ;
F_27 ( V_48 ) ;
F_60 ( V_48 ) ;
if ( V_48 -> V_181 < V_204 )
F_154 ( V_48 ) ;
F_146 ( & V_205 ) ;
F_187 ( & V_53 , NULL , V_48 , F_175 ) ;
F_148 ( & V_205 ) ;
return 0 ;
V_195:
F_146 ( & V_205 ) ;
F_188 ( & V_206 , V_48 -> V_181 ) ;
F_148 ( & V_205 ) ;
return V_35 ;
}
static int F_189 ( struct V_40 * V_48 )
{
int V_104 ;
F_146 ( & V_205 ) ;
V_104 = F_190 ( & V_206 , V_48 , V_48 -> V_181 , V_48 -> V_181 + 1 , V_68 ) ;
F_148 ( & V_205 ) ;
if ( F_178 ( V_104 < 0 , L_62 ) )
return V_104 == - V_207 ? - V_131 : V_104 ;
return F_176 ( V_48 ) ;
}
int F_191 ( struct V_40 * V_41 )
{
struct V_52 * V_39 = & V_41 -> V_39 ;
int V_104 ;
if ( V_39 -> V_137 ) {
V_104 = F_192 ( V_39 -> V_137 , L_63 ) ;
if ( V_104 >= 0 ) {
V_41 -> V_181 = V_104 ;
return F_189 ( V_41 ) ;
}
}
F_146 ( & V_205 ) ;
V_104 = F_190 ( & V_206 , V_41 ,
V_204 , 0 , V_68 ) ;
F_148 ( & V_205 ) ;
if ( F_178 ( V_104 < 0 , L_62 ) )
return V_104 ;
V_41 -> V_181 = V_104 ;
return F_176 ( V_41 ) ;
}
int F_193 ( struct V_40 * V_48 )
{
if ( V_48 -> V_181 == - 1 )
return F_191 ( V_48 ) ;
return F_189 ( V_48 ) ;
}
static void F_194 ( struct V_108 * V_109 ,
struct V_40 * V_41 )
{
struct V_54 * V_59 , * V_208 ;
F_152 (client, _n, &driver->clients, detected) {
if ( V_59 -> V_41 == V_41 ) {
F_91 ( & V_41 -> V_39 , L_64 ,
V_59 -> V_105 , V_59 -> V_12 ) ;
F_153 ( & V_59 -> V_174 ) ;
F_41 ( V_59 ) ;
}
}
}
static int F_195 ( struct V_52 * V_39 , void * V_209 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
if ( V_59 && strcmp ( V_59 -> V_105 , L_31 ) )
F_41 ( V_59 ) ;
return 0 ;
}
static int F_196 ( struct V_52 * V_39 , void * V_209 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
if ( V_59 )
F_41 ( V_59 ) ;
return 0 ;
}
static int F_197 ( struct V_106 * V_192 , void * V_4 )
{
F_194 ( F_72 ( V_192 ) , V_4 ) ;
return 0 ;
}
void F_198 ( struct V_40 * V_48 )
{
struct V_40 * V_210 ;
struct V_54 * V_59 , * V_176 ;
F_146 ( & V_205 ) ;
V_210 = F_199 ( & V_206 , V_48 -> V_181 ) ;
F_148 ( & V_205 ) ;
if ( V_210 != V_48 ) {
F_200 ( L_65 , V_48 -> V_105 ) ;
return;
}
F_65 ( V_48 ) ;
F_146 ( & V_205 ) ;
F_187 ( & V_53 , NULL , V_48 ,
F_197 ) ;
F_148 ( & V_205 ) ;
F_151 ( & V_48 -> V_173 ,
F_144 ( V_48 ) ) ;
F_152 (client, next, &adap->userspace_clients,
detected) {
F_91 ( & V_48 -> V_39 , L_64 , V_59 -> V_105 ,
V_59 -> V_12 ) ;
F_153 ( & V_59 -> V_174 ) ;
F_41 ( V_59 ) ;
}
F_148 ( & V_48 -> V_173 ) ;
F_118 ( & V_48 -> V_39 , NULL , F_195 ) ;
F_118 ( & V_48 -> V_39 , NULL , F_196 ) ;
#ifdef F_185
F_201 ( V_203 , & V_48 -> V_39 ,
V_48 -> V_39 . V_99 ) ;
#endif
F_91 ( & V_48 -> V_39 , L_66 , V_48 -> V_105 ) ;
F_202 ( & V_48 -> V_39 ) ;
F_203 ( & V_48 -> V_167 ) ;
F_134 ( & V_48 -> V_39 ) ;
F_204 ( & V_48 -> V_167 ) ;
F_146 ( & V_205 ) ;
F_188 ( & V_206 , V_48 -> V_181 ) ;
F_148 ( & V_205 ) ;
memset ( & V_48 -> V_39 , 0 , sizeof( V_48 -> V_39 ) ) ;
}
void F_205 ( struct V_52 * V_39 , struct V_211 * V_212 , bool V_213 )
{
int V_31 ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
V_31 = F_206 ( V_39 , L_67 , & V_212 -> V_214 ) ;
if ( V_31 && V_213 )
V_212 -> V_214 = 100000 ;
V_31 = F_206 ( V_39 , L_68 , & V_212 -> V_215 ) ;
if ( V_31 && V_213 ) {
if ( V_212 -> V_214 <= 100000 )
V_212 -> V_215 = 1000 ;
else if ( V_212 -> V_214 <= 400000 )
V_212 -> V_215 = 300 ;
else
V_212 -> V_215 = 120 ;
}
V_31 = F_206 ( V_39 , L_69 , & V_212 -> V_216 ) ;
if ( V_31 && V_213 ) {
if ( V_212 -> V_214 <= 400000 )
V_212 -> V_216 = 300 ;
else
V_212 -> V_216 = 120 ;
}
F_206 ( V_39 , L_70 , & V_212 -> V_217 ) ;
V_31 = F_206 ( V_39 , L_71 , & V_212 -> V_218 ) ;
if ( V_31 && V_213 )
V_212 -> V_218 = V_212 -> V_216 ;
}
int F_207 ( void * V_4 , int (* F_208)( struct V_52 * , void * ) )
{
int V_35 ;
F_146 ( & V_205 ) ;
V_35 = F_209 ( & V_53 , NULL , V_4 , F_208 ) ;
F_148 ( & V_205 ) ;
return V_35 ;
}
static int F_210 ( struct V_52 * V_39 , void * V_4 )
{
if ( V_39 -> type != & V_155 )
return 0 ;
return F_173 ( V_4 , F_109 ( V_39 ) ) ;
}
int F_211 ( struct V_219 * V_190 , struct V_108 * V_109 )
{
int V_35 ;
if ( F_177 ( ! V_193 ) )
return - V_194 ;
V_109 -> V_109 . V_190 = V_190 ;
V_109 -> V_109 . V_161 = & V_53 ;
V_35 = F_212 ( & V_109 -> V_109 ) ;
if ( V_35 )
return V_35 ;
F_200 ( L_72 , V_109 -> V_109 . V_105 ) ;
F_13 ( & V_109 -> V_220 ) ;
F_207 ( V_109 , F_210 ) ;
return 0 ;
}
static int F_213 ( struct V_52 * V_39 , void * V_4 )
{
if ( V_39 -> type == & V_155 )
F_194 ( V_4 , F_109 ( V_39 ) ) ;
return 0 ;
}
void F_214 ( struct V_108 * V_109 )
{
F_207 ( V_109 , F_213 ) ;
F_215 ( & V_109 -> V_109 ) ;
F_200 ( L_73 , V_109 -> V_109 . V_105 ) ;
}
struct V_54 * F_216 ( struct V_54 * V_59 )
{
if ( V_59 && F_217 ( & V_59 -> V_39 ) )
return V_59 ;
return NULL ;
}
void F_218 ( struct V_54 * V_59 )
{
if ( V_59 )
F_42 ( & V_59 -> V_39 ) ;
}
static int F_219 ( struct V_52 * V_39 , void * V_221 )
{
struct V_54 * V_59 = F_39 ( V_39 ) ;
struct V_222 * V_58 = V_221 ;
struct V_108 * V_109 ;
if ( ! V_59 || ! V_59 -> V_39 . V_109 )
return 0 ;
V_109 = F_72 ( V_59 -> V_39 . V_109 ) ;
if ( V_109 -> V_74 )
V_109 -> V_74 ( V_59 , V_58 -> V_63 , V_58 -> V_58 ) ;
return 0 ;
}
void F_220 ( struct V_40 * V_48 , unsigned int V_63 , void * V_58 )
{
struct V_222 V_223 ;
V_223 . V_63 = V_63 ;
V_223 . V_58 = V_58 ;
F_118 ( & V_48 -> V_39 , & V_223 , F_219 ) ;
}
static int F_221 ( struct V_55 * V_56 , unsigned long V_84 ,
void * V_58 )
{
struct V_224 * V_225 = V_58 ;
struct V_40 * V_48 ;
struct V_54 * V_59 ;
switch ( F_222 ( V_84 , V_225 ) ) {
case V_226 :
V_48 = F_170 ( V_225 -> V_227 -> V_99 ) ;
if ( V_48 == NULL )
return V_62 ;
if ( F_167 ( V_225 -> V_227 , V_162 ) ) {
F_42 ( & V_48 -> V_39 ) ;
return V_62 ;
}
V_59 = F_158 ( V_48 , V_225 -> V_227 ) ;
F_42 ( & V_48 -> V_39 ) ;
if ( F_223 ( V_59 ) ) {
F_23 ( & V_48 -> V_39 , L_74 ,
V_225 -> V_227 -> V_187 ) ;
return F_224 ( F_225 ( V_59 ) ) ;
}
break;
case V_228 :
if ( ! F_226 ( V_225 -> V_227 , V_162 ) )
return V_62 ;
V_59 = F_169 ( V_225 -> V_227 ) ;
if ( V_59 == NULL )
return V_62 ;
F_41 ( V_59 ) ;
F_42 ( & V_59 -> V_39 ) ;
break;
}
return V_62 ;
}
static int T_11 F_227 ( void )
{
int V_229 ;
V_229 = F_228 ( L_63 ) ;
F_229 ( & V_179 ) ;
if ( V_229 >= V_204 )
V_204 = V_229 + 1 ;
F_230 ( & V_179 ) ;
V_229 = F_231 ( & V_53 ) ;
if ( V_229 )
return V_229 ;
V_193 = true ;
#ifdef F_185
V_203 = F_232 ( L_75 ) ;
if ( ! V_203 ) {
V_229 = - V_101 ;
goto V_230;
}
#endif
V_229 = F_233 ( & V_231 ) ;
if ( V_229 )
goto V_232;
if ( F_234 ( V_233 ) )
F_177 ( F_235 ( & V_234 ) ) ;
if ( F_234 ( V_235 ) )
F_177 ( F_236 ( & V_236 ) ) ;
return 0 ;
V_232:
#ifdef F_185
F_237 ( V_203 ) ;
V_230:
#endif
V_193 = false ;
F_238 ( & V_53 ) ;
return V_229 ;
}
static void T_12 F_239 ( void )
{
if ( F_234 ( V_235 ) )
F_177 ( F_240 ( & V_236 ) ) ;
if ( F_234 ( V_233 ) )
F_177 ( F_241 ( & V_234 ) ) ;
F_214 ( & V_231 ) ;
#ifdef F_185
F_237 ( V_203 ) ;
#endif
F_238 ( & V_53 ) ;
F_242 () ;
}
static int F_243 ( struct V_40 * V_48 , struct V_65 * V_237 , char * V_238 )
{
F_244 ( & V_48 -> V_39 , L_76 ,
V_238 , V_237 -> V_12 , V_237 -> V_70 ,
V_237 -> V_23 & V_72 ? L_77 : L_78 ) ;
return - V_133 ;
}
static int F_245 ( struct V_40 * V_48 , struct V_65 * V_66 , int V_239 )
{
const struct V_240 * V_241 = V_48 -> V_242 ;
int V_243 = V_241 -> V_244 , V_125 ;
bool V_245 = true ;
if ( V_241 -> V_23 & V_246 ) {
V_243 = 2 ;
if ( V_239 == 2 ) {
if ( V_241 -> V_23 & V_247 && V_66 [ 0 ] . V_23 & V_72 )
return F_243 ( V_48 , & V_66 [ 0 ] , L_79 ) ;
if ( V_241 -> V_23 & V_248 && ! ( V_66 [ 1 ] . V_23 & V_72 ) )
return F_243 ( V_48 , & V_66 [ 1 ] , L_80 ) ;
if ( V_241 -> V_23 & V_249 && V_66 [ 0 ] . V_12 != V_66 [ 1 ] . V_12 )
return F_243 ( V_48 , & V_66 [ 0 ] , L_81 ) ;
if ( F_246 ( V_66 [ 0 ] . V_70 , V_241 -> V_250 ) )
return F_243 ( V_48 , & V_66 [ 0 ] , L_82 ) ;
if ( F_246 ( V_66 [ 1 ] . V_70 , V_241 -> V_251 ) )
return F_243 ( V_48 , & V_66 [ 1 ] , L_82 ) ;
V_245 = false ;
}
}
if ( F_246 ( V_239 , V_243 ) )
return F_243 ( V_48 , & V_66 [ 0 ] , L_83 ) ;
for ( V_125 = 0 ; V_125 < V_239 ; V_125 ++ ) {
T_8 V_70 = V_66 [ V_125 ] . V_70 ;
if ( V_66 [ V_125 ] . V_23 & V_72 ) {
if ( V_245 && F_246 ( V_70 , V_241 -> V_252 ) )
return F_243 ( V_48 , & V_66 [ V_125 ] , L_82 ) ;
} else {
if ( V_245 && F_246 ( V_70 , V_241 -> V_253 ) )
return F_243 ( V_48 , & V_66 [ V_125 ] , L_82 ) ;
}
}
return 0 ;
}
int F_247 ( struct V_40 * V_48 , struct V_65 * V_66 , int V_239 )
{
unsigned long V_254 ;
int V_31 , V_255 ;
if ( V_48 -> V_242 && F_245 ( V_48 , V_66 , V_239 ) )
return - V_133 ;
if ( F_248 ( & V_1 ) ) {
int V_125 ;
for ( V_125 = 0 ; V_125 < V_239 ; V_125 ++ )
if ( V_66 [ V_125 ] . V_23 & V_72 )
F_249 ( V_48 , & V_66 [ V_125 ] , V_125 ) ;
else
F_250 ( V_48 , & V_66 [ V_125 ] , V_125 ) ;
}
V_254 = V_256 ;
for ( V_31 = 0 , V_255 = 0 ; V_255 <= V_48 -> V_257 ; V_255 ++ ) {
V_31 = V_48 -> V_196 -> V_258 ( V_48 , V_66 , V_239 ) ;
if ( V_31 != - V_194 )
break;
if ( F_251 ( V_256 , V_254 + V_48 -> V_201 ) )
break;
}
if ( F_248 ( & V_1 ) ) {
int V_125 ;
for ( V_125 = 0 ; V_125 < V_31 ; V_125 ++ )
if ( V_66 [ V_125 ] . V_23 & V_72 )
F_252 ( V_48 , & V_66 [ V_125 ] , V_125 ) ;
F_253 ( V_48 , V_125 , V_31 ) ;
}
return V_31 ;
}
int F_45 ( struct V_40 * V_48 , struct V_65 * V_66 , int V_239 )
{
int V_31 ;
if ( V_48 -> V_196 -> V_258 ) {
#ifdef F_254
for ( V_31 = 0 ; V_31 < V_239 ; V_31 ++ ) {
F_91 ( & V_48 -> V_39 , L_84
L_85 , V_31 , ( V_66 [ V_31 ] . V_23 & V_72 )
? 'R' : 'W' , V_66 [ V_31 ] . V_12 , V_66 [ V_31 ] . V_70 ,
( V_66 [ V_31 ] . V_23 & V_259 ) ? L_86 : L_87 ) ;
}
#endif
if ( F_255 () || F_256 () ) {
V_31 = V_48 -> V_198 ( V_48 , V_260 ) ;
if ( ! V_31 )
return - V_194 ;
} else {
F_257 ( V_48 , V_260 ) ;
}
V_31 = F_247 ( V_48 , V_66 , V_239 ) ;
F_258 ( V_48 , V_260 ) ;
return V_31 ;
} else {
F_91 ( & V_48 -> V_39 , L_88 ) ;
return - V_133 ;
}
}
int F_259 ( const struct V_54 * V_59 , const char * V_71 , int V_169 )
{
int V_31 ;
struct V_40 * V_48 = V_59 -> V_41 ;
struct V_65 V_237 ;
V_237 . V_12 = V_59 -> V_12 ;
V_237 . V_23 = V_59 -> V_23 & V_261 ;
V_237 . V_70 = V_169 ;
V_237 . V_71 = ( char * ) V_71 ;
V_31 = F_45 ( V_48 , & V_237 , 1 ) ;
return ( V_31 == 1 ) ? V_169 : V_31 ;
}
int F_260 ( const struct V_54 * V_59 , char * V_71 , int V_169 )
{
struct V_40 * V_48 = V_59 -> V_41 ;
struct V_65 V_237 ;
int V_31 ;
V_237 . V_12 = V_59 -> V_12 ;
V_237 . V_23 = V_59 -> V_23 & V_261 ;
V_237 . V_23 |= V_72 ;
V_237 . V_70 = V_169 ;
V_237 . V_71 = V_71 ;
V_31 = F_45 ( V_48 , & V_237 , 1 ) ;
return ( V_31 == 1 ) ? V_169 : V_31 ;
}
static int F_261 ( struct V_40 * V_48 , unsigned short V_12 )
{
int V_88 ;
union V_262 V_209 ;
#ifdef F_262
if ( V_12 == 0x73 && ( V_48 -> V_263 & V_264 )
&& F_263 ( V_48 , V_265 ) )
V_88 = F_264 ( V_48 , V_12 , 0 , V_266 , 0 ,
V_267 , & V_209 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_263 ( V_48 , V_268 ) )
V_88 = F_264 ( V_48 , V_12 , 0 , V_269 , 0 ,
V_270 , NULL ) ;
else if ( F_263 ( V_48 , V_271 ) )
V_88 = F_264 ( V_48 , V_12 , 0 , V_266 , 0 ,
V_272 , & V_209 ) ;
else {
F_31 ( & V_48 -> V_39 , L_89 ,
V_12 ) ;
V_88 = - V_133 ;
}
return V_88 >= 0 ;
}
static int F_265 ( struct V_54 * V_273 ,
struct V_108 * V_109 )
{
struct V_7 V_8 ;
struct V_40 * V_41 = V_273 -> V_41 ;
int V_12 = V_273 -> V_12 ;
int V_88 ;
V_88 = F_114 ( V_12 ) ;
if ( V_88 ) {
F_31 ( & V_41 -> V_39 , L_90 ,
V_12 ) ;
return V_88 ;
}
if ( F_120 ( V_41 , V_12 ) )
return 0 ;
if ( ! F_261 ( V_41 , V_12 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_12 = V_12 ;
V_88 = V_109 -> V_274 ( V_273 , & V_8 ) ;
if ( V_88 ) {
return V_88 == - V_100 ? 0 : V_88 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_23 ( & V_41 -> V_39 , L_91
L_92 , V_109 -> V_109 . V_105 ,
V_12 ) ;
} else {
struct V_54 * V_59 ;
if ( V_41 -> V_263 & V_275 )
F_31 ( & V_41 -> V_39 ,
L_93
L_94
L_95 ,
V_8 . V_12 ) ;
F_91 ( & V_41 -> V_39 , L_96 ,
V_8 . type , V_8 . V_12 ) ;
V_59 = F_22 ( V_41 , & V_8 ) ;
if ( V_59 )
F_147 ( & V_59 -> V_174 , & V_109 -> V_220 ) ;
else
F_23 ( & V_41 -> V_39 , L_97 ,
V_8 . type , V_8 . V_12 ) ;
}
return 0 ;
}
static int F_174 ( struct V_40 * V_41 , struct V_108 * V_109 )
{
const unsigned short * V_276 ;
struct V_54 * V_273 ;
int V_125 , V_88 = 0 ;
int V_277 = F_130 ( V_41 ) ;
V_276 = V_109 -> V_276 ;
if ( ! V_109 -> V_274 || ! V_276 )
return 0 ;
if ( V_41 -> V_263 == V_275 ) {
F_91 ( & V_41 -> V_39 ,
L_98
L_99
L_100 ,
V_109 -> V_109 . V_105 ) ;
return 0 ;
}
if ( ! ( V_41 -> V_263 & V_109 -> V_263 ) )
return 0 ;
V_273 = F_44 ( sizeof( struct V_54 ) , V_68 ) ;
if ( ! V_273 )
return - V_101 ;
V_273 -> V_41 = V_41 ;
for ( V_125 = 0 ; V_276 [ V_125 ] != V_278 ; V_125 += 1 ) {
F_91 ( & V_41 -> V_39 , L_101
L_102 , V_277 , V_276 [ V_125 ] ) ;
V_273 -> V_12 = V_276 [ V_125 ] ;
V_88 = F_265 ( V_273 , V_109 ) ;
if ( F_266 ( V_88 ) )
break;
}
F_47 ( V_273 ) ;
return V_88 ;
}
int F_267 ( struct V_40 * V_48 , unsigned short V_12 )
{
return F_264 ( V_48 , V_12 , 0 , V_266 , 0 ,
V_270 , NULL ) >= 0 ;
}
struct V_54 *
F_268 ( struct V_40 * V_48 ,
struct V_7 * V_8 ,
unsigned short const * V_279 ,
int (* V_140)( struct V_40 * , unsigned short V_12 ) )
{
int V_125 ;
if ( ! V_140 )
V_140 = F_261 ;
for ( V_125 = 0 ; V_279 [ V_125 ] != V_278 ; V_125 ++ ) {
if ( F_114 ( V_279 [ V_125 ] ) < 0 ) {
F_31 ( & V_48 -> V_39 , L_103
L_104 , V_279 [ V_125 ] ) ;
continue;
}
if ( F_120 ( V_48 , V_279 [ V_125 ] ) ) {
F_91 ( & V_48 -> V_39 , L_105
L_106 , V_279 [ V_125 ] ) ;
continue;
}
if ( V_140 ( V_48 , V_279 [ V_125 ] ) )
break;
}
if ( V_279 [ V_125 ] == V_278 ) {
F_91 ( & V_48 -> V_39 , L_107 ) ;
return NULL ;
}
V_8 -> V_12 = V_279 [ V_125 ] ;
return F_22 ( V_48 , V_8 ) ;
}
struct V_40 * F_269 ( int V_181 )
{
struct V_40 * V_41 ;
F_146 ( & V_205 ) ;
V_41 = F_199 ( & V_206 , V_181 ) ;
if ( ! V_41 )
goto exit;
if ( F_172 ( V_41 -> V_190 ) )
F_217 ( & V_41 -> V_39 ) ;
else
V_41 = NULL ;
exit:
F_148 ( & V_205 ) ;
return V_41 ;
}
void F_270 ( struct V_40 * V_48 )
{
if ( ! V_48 )
return;
F_42 ( & V_48 -> V_39 ) ;
F_271 ( V_48 -> V_190 ) ;
}
static T_4 F_272 ( T_8 V_4 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < 8 ; V_125 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_280 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_273 ( T_4 V_281 , T_4 * V_282 , T_9 V_169 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_169 ; V_125 ++ )
V_281 = F_272 ( ( V_281 ^ V_282 [ V_125 ] ) << 8 ) ;
return V_281 ;
}
static T_4 F_274 ( T_4 V_283 , struct V_65 * V_237 )
{
T_4 V_12 = F_275 ( V_237 ) ;
V_283 = F_273 ( V_283 , & V_12 , 1 ) ;
return F_273 ( V_283 , V_237 -> V_71 , V_237 -> V_70 ) ;
}
static inline void F_276 ( struct V_65 * V_237 )
{
V_237 -> V_71 [ V_237 -> V_70 ] = F_274 ( 0 , V_237 ) ;
V_237 -> V_70 ++ ;
}
static int F_277 ( T_4 V_284 , struct V_65 * V_237 )
{
T_4 V_285 = V_237 -> V_71 [ -- V_237 -> V_70 ] ;
V_284 = F_274 ( V_284 , V_237 ) ;
if ( V_285 != V_284 ) {
F_200 ( L_108 ,
V_285 , V_284 ) ;
return - V_286 ;
}
return 0 ;
}
T_13 F_51 ( const struct V_54 * V_59 )
{
union V_262 V_4 ;
int V_11 ;
V_11 = F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_266 , 0 ,
V_272 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_287 ;
}
T_13 F_52 ( const struct V_54 * V_59 , T_4 V_57 )
{
return F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_269 , V_57 , V_272 , NULL ) ;
}
T_13 F_53 ( const struct V_54 * V_59 , T_4 V_74 )
{
union V_262 V_4 ;
int V_11 ;
V_11 = F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_266 , V_74 ,
V_267 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_287 ;
}
T_13 F_54 ( const struct V_54 * V_59 , T_4 V_74 ,
T_4 V_57 )
{
union V_262 V_4 ;
V_4 . V_287 = V_57 ;
return F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_269 , V_74 ,
V_267 , & V_4 ) ;
}
T_13 F_55 ( const struct V_54 * V_59 , T_4 V_74 )
{
union V_262 V_4 ;
int V_11 ;
V_11 = F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_266 , V_74 ,
V_288 , & V_4 ) ;
return ( V_11 < 0 ) ? V_11 : V_4 . V_289 ;
}
T_13 F_56 ( const struct V_54 * V_59 , T_4 V_74 ,
T_8 V_57 )
{
union V_262 V_4 ;
V_4 . V_289 = V_57 ;
return F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_269 , V_74 ,
V_288 , & V_4 ) ;
}
T_13 F_57 ( const struct V_54 * V_59 , T_4 V_74 ,
T_4 * V_290 )
{
union V_262 V_4 ;
int V_11 ;
V_11 = F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_266 , V_74 ,
V_291 , & V_4 ) ;
if ( V_11 )
return V_11 ;
memcpy ( V_290 , & V_4 . V_292 [ 1 ] , V_4 . V_292 [ 0 ] ) ;
return V_4 . V_292 [ 0 ] ;
}
T_13 F_58 ( const struct V_54 * V_59 , T_4 V_74 ,
T_4 V_87 , const T_4 * V_290 )
{
union V_262 V_4 ;
if ( V_87 > V_293 )
V_87 = V_293 ;
V_4 . V_292 [ 0 ] = V_87 ;
memcpy ( & V_4 . V_292 [ 1 ] , V_290 , V_87 ) ;
return F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_269 , V_74 ,
V_291 , & V_4 ) ;
}
T_13 F_278 ( const struct V_54 * V_59 , T_4 V_74 ,
T_4 V_87 , T_4 * V_290 )
{
union V_262 V_4 ;
int V_11 ;
if ( V_87 > V_293 )
V_87 = V_293 ;
V_4 . V_292 [ 0 ] = V_87 ;
V_11 = F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_266 , V_74 ,
V_294 , & V_4 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_290 , & V_4 . V_292 [ 1 ] , V_4 . V_292 [ 0 ] ) ;
return V_4 . V_292 [ 0 ] ;
}
T_13 F_279 ( const struct V_54 * V_59 , T_4 V_74 ,
T_4 V_87 , const T_4 * V_290 )
{
union V_262 V_4 ;
if ( V_87 > V_293 )
V_87 = V_293 ;
V_4 . V_292 [ 0 ] = V_87 ;
memcpy ( V_4 . V_292 + 1 , V_290 , V_87 ) ;
return F_264 ( V_59 -> V_41 , V_59 -> V_12 , V_59 -> V_23 ,
V_269 , V_74 ,
V_294 , & V_4 ) ;
}
static T_13 F_280 ( struct V_40 * V_41 , T_8 V_12 ,
unsigned short V_23 ,
char V_295 , T_4 V_74 , int V_296 ,
union V_262 * V_4 )
{
unsigned char V_297 [ V_293 + 3 ] ;
unsigned char V_298 [ V_293 + 2 ] ;
int V_239 = V_295 == V_266 ? 2 : 1 ;
int V_125 ;
T_4 V_299 = 0 ;
int V_11 ;
struct V_65 V_237 [ 2 ] = {
{
. V_12 = V_12 ,
. V_23 = V_23 ,
. V_70 = 1 ,
. V_71 = V_297 ,
} , {
. V_12 = V_12 ,
. V_23 = V_23 | V_72 ,
. V_70 = 0 ,
. V_71 = V_298 ,
} ,
} ;
V_297 [ 0 ] = V_74 ;
switch ( V_296 ) {
case V_270 :
V_237 [ 0 ] . V_70 = 0 ;
V_237 [ 0 ] . V_23 = V_23 | ( V_295 == V_266 ?
V_72 : 0 ) ;
V_239 = 1 ;
break;
case V_272 :
if ( V_295 == V_266 ) {
V_237 [ 0 ] . V_23 = V_72 | V_23 ;
V_239 = 1 ;
}
break;
case V_267 :
if ( V_295 == V_266 )
V_237 [ 1 ] . V_70 = 1 ;
else {
V_237 [ 0 ] . V_70 = 2 ;
V_297 [ 1 ] = V_4 -> V_287 ;
}
break;
case V_288 :
if ( V_295 == V_266 )
V_237 [ 1 ] . V_70 = 2 ;
else {
V_237 [ 0 ] . V_70 = 3 ;
V_297 [ 1 ] = V_4 -> V_289 & 0xff ;
V_297 [ 2 ] = V_4 -> V_289 >> 8 ;
}
break;
case V_300 :
V_239 = 2 ;
V_295 = V_266 ;
V_237 [ 0 ] . V_70 = 3 ;
V_237 [ 1 ] . V_70 = 2 ;
V_297 [ 1 ] = V_4 -> V_289 & 0xff ;
V_297 [ 2 ] = V_4 -> V_289 >> 8 ;
break;
case V_291 :
if ( V_295 == V_266 ) {
V_237 [ 1 ] . V_23 |= V_259 ;
V_237 [ 1 ] . V_70 = 1 ;
} else {
V_237 [ 0 ] . V_70 = V_4 -> V_292 [ 0 ] + 2 ;
if ( V_237 [ 0 ] . V_70 > V_293 + 2 ) {
F_23 ( & V_41 -> V_39 ,
L_109 ,
V_4 -> V_292 [ 0 ] ) ;
return - V_33 ;
}
for ( V_125 = 1 ; V_125 < V_237 [ 0 ] . V_70 ; V_125 ++ )
V_297 [ V_125 ] = V_4 -> V_292 [ V_125 - 1 ] ;
}
break;
case V_301 :
V_239 = 2 ;
V_295 = V_266 ;
if ( V_4 -> V_292 [ 0 ] > V_293 ) {
F_23 ( & V_41 -> V_39 ,
L_109 ,
V_4 -> V_292 [ 0 ] ) ;
return - V_33 ;
}
V_237 [ 0 ] . V_70 = V_4 -> V_292 [ 0 ] + 2 ;
for ( V_125 = 1 ; V_125 < V_237 [ 0 ] . V_70 ; V_125 ++ )
V_297 [ V_125 ] = V_4 -> V_292 [ V_125 - 1 ] ;
V_237 [ 1 ] . V_23 |= V_259 ;
V_237 [ 1 ] . V_70 = 1 ;
break;
case V_294 :
if ( V_295 == V_266 ) {
V_237 [ 1 ] . V_70 = V_4 -> V_292 [ 0 ] ;
} else {
V_237 [ 0 ] . V_70 = V_4 -> V_292 [ 0 ] + 1 ;
if ( V_237 [ 0 ] . V_70 > V_293 + 1 ) {
F_23 ( & V_41 -> V_39 ,
L_109 ,
V_4 -> V_292 [ 0 ] ) ;
return - V_33 ;
}
for ( V_125 = 1 ; V_125 <= V_4 -> V_292 [ 0 ] ; V_125 ++ )
V_297 [ V_125 ] = V_4 -> V_292 [ V_125 ] ;
}
break;
default:
F_23 ( & V_41 -> V_39 , L_110 , V_296 ) ;
return - V_133 ;
}
V_125 = ( ( V_23 & V_302 ) && V_296 != V_270
&& V_296 != V_294 ) ;
if ( V_125 ) {
if ( ! ( V_237 [ 0 ] . V_23 & V_72 ) ) {
if ( V_239 == 1 )
F_276 ( & V_237 [ 0 ] ) ;
else
V_299 = F_274 ( 0 , & V_237 [ 0 ] ) ;
}
if ( V_237 [ V_239 - 1 ] . V_23 & V_72 )
V_237 [ V_239 - 1 ] . V_70 ++ ;
}
V_11 = F_45 ( V_41 , V_237 , V_239 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_125 && ( V_237 [ V_239 - 1 ] . V_23 & V_72 ) ) {
V_11 = F_277 ( V_299 , & V_237 [ V_239 - 1 ] ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_295 == V_266 )
switch ( V_296 ) {
case V_272 :
V_4 -> V_287 = V_297 [ 0 ] ;
break;
case V_267 :
V_4 -> V_287 = V_298 [ 0 ] ;
break;
case V_288 :
case V_300 :
V_4 -> V_289 = V_298 [ 0 ] | ( V_298 [ 1 ] << 8 ) ;
break;
case V_294 :
for ( V_125 = 0 ; V_125 < V_4 -> V_292 [ 0 ] ; V_125 ++ )
V_4 -> V_292 [ V_125 + 1 ] = V_298 [ V_125 ] ;
break;
case V_291 :
case V_301 :
for ( V_125 = 0 ; V_125 < V_298 [ 0 ] + 1 ; V_125 ++ )
V_4 -> V_292 [ V_125 ] = V_298 [ V_125 ] ;
break;
}
return 0 ;
}
T_13 F_264 ( struct V_40 * V_41 , T_8 V_12 , unsigned short V_23 ,
char V_295 , T_4 V_74 , int V_303 ,
union V_262 * V_4 )
{
unsigned long V_254 ;
int V_255 ;
T_13 V_35 ;
F_281 ( V_41 , V_12 , V_23 , V_295 ,
V_74 , V_303 , V_4 ) ;
F_282 ( V_41 , V_12 , V_23 , V_295 ,
V_74 , V_303 ) ;
V_23 &= V_261 | V_302 | V_304 ;
if ( V_41 -> V_196 -> V_305 ) {
F_257 ( V_41 , V_260 ) ;
V_254 = V_256 ;
for ( V_35 = 0 , V_255 = 0 ; V_255 <= V_41 -> V_257 ; V_255 ++ ) {
V_35 = V_41 -> V_196 -> V_305 ( V_41 , V_12 , V_23 ,
V_295 , V_74 ,
V_303 , V_4 ) ;
if ( V_35 != - V_194 )
break;
if ( F_251 ( V_256 ,
V_254 + V_41 -> V_201 ) )
break;
}
F_258 ( V_41 , V_260 ) ;
if ( V_35 != - V_133 || ! V_41 -> V_196 -> V_258 )
goto V_306;
}
V_35 = F_280 ( V_41 , V_12 , V_23 , V_295 ,
V_74 , V_303 , V_4 ) ;
V_306:
F_283 ( V_41 , V_12 , V_23 , V_295 ,
V_74 , V_303 , V_4 ) ;
F_284 ( V_41 , V_12 , V_23 , V_295 ,
V_74 , V_303 , V_35 ) ;
return V_35 ;
}
T_13 F_285 ( const struct V_54 * V_59 ,
T_4 V_74 , T_4 V_87 , T_4 * V_290 )
{
T_4 V_125 = 0 ;
int V_11 ;
if ( V_87 > V_293 )
V_87 = V_293 ;
if ( F_263 ( V_59 -> V_41 , V_307 ) )
return F_278 ( V_59 , V_74 , V_87 , V_290 ) ;
if ( ! F_263 ( V_59 -> V_41 , V_265 ) )
return - V_133 ;
if ( F_263 ( V_59 -> V_41 , V_308 ) ) {
while ( ( V_125 + 2 ) <= V_87 ) {
V_11 = F_55 ( V_59 , V_74 + V_125 ) ;
if ( V_11 < 0 )
return V_11 ;
V_290 [ V_125 ] = V_11 & 0xff ;
V_290 [ V_125 + 1 ] = V_11 >> 8 ;
V_125 += 2 ;
}
}
while ( V_125 < V_87 ) {
V_11 = F_53 ( V_59 , V_74 + V_125 ) ;
if ( V_11 < 0 )
return V_11 ;
V_290 [ V_125 ] = V_11 ;
V_125 ++ ;
}
return V_125 ;
}
int F_286 ( struct V_54 * V_59 , T_14 V_309 )
{
int V_31 ;
if ( ! V_59 || ! V_309 ) {
F_178 ( 1 , L_111 ) ;
return - V_33 ;
}
if ( ! ( V_59 -> V_23 & V_151 ) )
F_31 ( & V_59 -> V_39 , L_112 ,
V_310 ) ;
if ( ! ( V_59 -> V_23 & V_24 ) ) {
V_31 = F_114 ( V_59 -> V_12 ) ;
if ( V_31 ) {
F_23 ( & V_59 -> V_39 , L_113 , V_310 ) ;
return V_31 ;
}
}
if ( ! V_59 -> V_41 -> V_196 -> V_311 ) {
F_23 ( & V_59 -> V_39 , L_114 , V_310 ) ;
return - V_133 ;
}
V_59 -> V_309 = V_309 ;
F_287 ( V_59 -> V_41 ) ;
V_31 = V_59 -> V_41 -> V_196 -> V_311 ( V_59 ) ;
F_288 ( V_59 -> V_41 ) ;
if ( V_31 ) {
V_59 -> V_309 = NULL ;
F_23 ( & V_59 -> V_39 , L_115 , V_310 , V_31 ) ;
}
return V_31 ;
}
int F_289 ( struct V_54 * V_59 )
{
int V_31 ;
if ( ! V_59 -> V_41 -> V_196 -> V_312 ) {
F_23 ( & V_59 -> V_39 , L_114 , V_310 ) ;
return - V_133 ;
}
F_287 ( V_59 -> V_41 ) ;
V_31 = V_59 -> V_41 -> V_196 -> V_312 ( V_59 ) ;
F_288 ( V_59 -> V_41 ) ;
if ( V_31 == 0 )
V_59 -> V_309 = NULL ;
else
F_23 ( & V_59 -> V_39 , L_115 , V_310 , V_31 ) ;
return V_31 ;
}
