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
T_2 V_12 ;
if ( V_8 -> V_13 || V_3 -> type != V_14 )
return 1 ;
V_10 = & V_3 -> V_4 . V_15 ;
if ( V_10 -> type != V_16 )
return 1 ;
V_12 = F_6 ( V_6 -> V_17 ,
V_10 -> V_18 . V_19 ,
& V_11 ) ;
if ( F_7 ( V_12 ) && V_11 == V_6 -> V_11 ) {
V_8 -> V_13 = V_10 -> V_20 ;
if ( V_10 -> V_21 == V_22 )
V_8 -> V_23 |= V_24 ;
}
return 1 ;
}
static T_2 F_8 ( T_1 V_25 , T_3 V_26 ,
void * V_4 , void * * V_27 )
{
struct V_28 * V_29 = V_4 ;
struct V_30 V_31 ;
struct V_5 V_6 ;
struct V_32 * V_33 ;
struct V_7 V_8 ;
struct V_34 * V_35 ;
int V_36 ;
if ( F_9 ( V_25 , & V_35 ) )
return V_37 ;
if ( F_10 ( V_35 ) || ! V_35 -> V_12 . V_38 )
return V_37 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_39 = F_11 ( V_35 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_11 = F_12 ( & V_29 -> V_40 ) ;
V_6 . V_17 = V_25 ;
V_6 . V_8 = & V_8 ;
F_13 ( & V_31 ) ;
V_36 = F_14 ( V_35 , & V_31 ,
F_5 , & V_6 ) ;
F_15 ( & V_31 ) ;
if ( V_36 < 0 || ! V_8 . V_13 )
return V_37 ;
V_36 = F_14 ( V_35 , & V_31 , NULL , NULL ) ;
if ( V_36 < 0 )
return V_37 ;
F_16 (entry, &resource_list) {
if ( F_17 ( V_33 -> V_41 ) == V_42 ) {
V_8 . V_43 = V_33 -> V_41 -> V_44 ;
break;
}
}
F_15 ( & V_31 ) ;
V_35 -> V_45 . V_23 . V_46 = true ;
F_18 ( V_8 . type , F_19 ( & V_35 -> V_40 ) , sizeof( V_8 . type ) ) ;
if ( ! F_20 ( V_29 , & V_8 ) ) {
V_35 -> V_45 . V_23 . V_46 = false ;
F_21 ( & V_29 -> V_40 ,
L_1 ,
F_19 ( & V_35 -> V_40 ) ) ;
}
return V_37 ;
}
static void F_22 ( struct V_28 * V_47 )
{
T_2 V_12 ;
if ( ! F_23 ( & V_47 -> V_40 ) )
return;
V_12 = F_24 ( V_48 , V_49 ,
V_50 ,
F_8 , NULL ,
V_47 , NULL ) ;
if ( F_25 ( V_12 ) )
F_26 ( & V_47 -> V_40 , L_2 ) ;
}
static inline void F_22 ( struct V_28 * V_47 ) { }
static int F_27 ( struct V_51 * V_52 ,
T_4 V_53 , T_4 * V_4 , T_4 V_54 )
{
struct V_55 V_56 [ 2 ] ;
int V_36 ;
T_4 * V_57 ;
V_57 = F_28 ( V_54 , V_58 ) ;
if ( ! V_57 )
return V_59 ;
V_56 [ 0 ] . V_13 = V_52 -> V_13 ;
V_56 [ 0 ] . V_23 = V_52 -> V_23 ;
V_56 [ 0 ] . V_60 = 1 ;
V_56 [ 0 ] . V_61 = & V_53 ;
V_56 [ 1 ] . V_13 = V_52 -> V_13 ;
V_56 [ 1 ] . V_23 = V_52 -> V_23 | V_62 ;
V_56 [ 1 ] . V_60 = V_54 ;
V_56 [ 1 ] . V_61 = V_57 ;
V_36 = F_29 ( V_52 -> V_29 , V_56 , F_30 ( V_56 ) ) ;
if ( V_36 < 0 )
F_21 ( & V_52 -> V_29 -> V_40 , L_3 ) ;
else
memcpy ( V_4 , V_57 , V_54 ) ;
F_31 ( V_57 ) ;
return V_36 ;
}
static int F_32 ( struct V_51 * V_52 ,
T_4 V_53 , T_4 * V_4 , T_4 V_54 )
{
struct V_55 V_56 [ 1 ] ;
T_4 * V_57 ;
int V_36 = V_37 ;
V_57 = F_28 ( V_54 + 1 , V_58 ) ;
if ( ! V_57 )
return V_59 ;
V_57 [ 0 ] = V_53 ;
memcpy ( V_57 + 1 , V_4 , V_54 ) ;
V_56 [ 0 ] . V_13 = V_52 -> V_13 ;
V_56 [ 0 ] . V_23 = V_52 -> V_23 ;
V_56 [ 0 ] . V_60 = V_54 + 1 ;
V_56 [ 0 ] . V_61 = V_57 ;
V_36 = F_29 ( V_52 -> V_29 , V_56 , F_30 ( V_56 ) ) ;
if ( V_36 < 0 )
F_21 ( & V_52 -> V_29 -> V_40 , L_4 ) ;
F_31 ( V_57 ) ;
return V_36 ;
}
static T_2
F_33 ( T_3 V_63 , T_5 V_64 ,
T_3 V_65 , T_6 * V_66 ,
void * V_67 , void * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_66 ;
struct V_71 * V_4 = V_67 ;
struct V_72 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_51 * V_52 ;
struct V_2 * V_3 ;
T_3 V_73 = V_63 >> 16 ;
T_4 V_74 = V_63 & V_75 ;
T_2 V_36 ;
int V_12 ;
V_36 = F_34 ( V_8 -> V_76 , V_8 -> V_77 , & V_3 ) ;
if ( F_25 ( V_36 ) )
return V_36 ;
V_52 = F_28 ( sizeof( * V_52 ) , V_58 ) ;
if ( ! V_52 ) {
V_36 = V_59 ;
goto V_78;
}
if ( ! V_66 || V_3 -> type != V_14 ) {
V_36 = V_79 ;
goto V_78;
}
V_10 = & V_3 -> V_4 . V_15 ;
if ( V_10 -> type != V_16 ) {
V_36 = V_79 ;
goto V_78;
}
V_52 -> V_29 = V_29 ;
V_52 -> V_13 = V_10 -> V_20 ;
if ( V_10 -> V_21 == V_22 )
V_52 -> V_23 |= V_24 ;
switch ( V_73 ) {
case V_80 :
if ( V_74 == V_81 ) {
V_12 = F_35 ( V_52 ) ;
if ( V_12 >= 0 ) {
V_70 -> V_82 = V_12 ;
V_12 = 0 ;
}
} else {
V_12 = F_36 ( V_52 , V_70 -> V_82 ) ;
}
break;
case V_83 :
if ( V_74 == V_81 ) {
V_12 = F_37 ( V_52 , V_64 ) ;
if ( V_12 >= 0 ) {
V_70 -> V_82 = V_12 ;
V_12 = 0 ;
}
} else {
V_12 = F_38 ( V_52 , V_64 ,
V_70 -> V_82 ) ;
}
break;
case V_84 :
if ( V_74 == V_81 ) {
V_12 = F_39 ( V_52 , V_64 ) ;
if ( V_12 >= 0 ) {
V_70 -> V_85 = V_12 ;
V_12 = 0 ;
}
} else {
V_12 = F_40 ( V_52 , V_64 ,
V_70 -> V_85 ) ;
}
break;
case V_86 :
if ( V_74 == V_81 ) {
V_12 = F_41 ( V_52 , V_64 ,
V_70 -> V_4 ) ;
if ( V_12 >= 0 ) {
V_70 -> V_60 = V_12 ;
V_12 = 0 ;
}
} else {
V_12 = F_42 ( V_52 , V_64 ,
V_70 -> V_60 , V_70 -> V_4 ) ;
}
break;
case V_87 :
if ( V_74 == V_81 ) {
V_12 = F_27 ( V_52 , V_64 ,
V_70 -> V_4 , V_8 -> V_88 ) ;
if ( V_12 > 0 )
V_12 = 0 ;
} else {
V_12 = F_32 ( V_52 , V_64 ,
V_70 -> V_4 , V_8 -> V_88 ) ;
}
break;
default:
F_43 ( L_5 , V_73 ) ;
V_36 = V_79 ;
goto V_78;
}
V_70 -> V_12 = V_12 ;
V_78:
F_31 ( V_52 ) ;
F_44 ( V_3 ) ;
return V_36 ;
}
static int F_45 ( struct V_28 * V_29 )
{
T_1 V_25 ;
struct V_71 * V_4 ;
T_2 V_12 ;
if ( ! V_29 -> V_40 . V_89 )
return - V_90 ;
V_25 = F_12 ( V_29 -> V_40 . V_89 ) ;
if ( ! V_25 )
return - V_90 ;
V_4 = F_28 ( sizeof( struct V_71 ) ,
V_58 ) ;
if ( ! V_4 )
return - V_91 ;
V_4 -> V_29 = V_29 ;
V_12 = F_46 ( V_25 , ( void * ) V_4 ) ;
if ( F_25 ( V_12 ) ) {
F_31 ( V_4 ) ;
return - V_91 ;
}
V_12 = F_47 ( V_25 ,
V_92 ,
& F_33 ,
NULL ,
V_4 ) ;
if ( F_25 ( V_12 ) ) {
F_21 ( & V_29 -> V_40 , L_6 ) ;
F_48 ( V_25 ) ;
F_31 ( V_4 ) ;
return - V_91 ;
}
F_49 ( V_25 ) ;
return 0 ;
}
static void F_50 ( struct V_28 * V_29 )
{
T_1 V_25 ;
struct V_71 * V_4 ;
T_2 V_12 ;
if ( ! V_29 -> V_40 . V_89 )
return;
V_25 = F_12 ( V_29 -> V_40 . V_89 ) ;
if ( ! V_25 )
return;
F_51 ( V_25 ,
V_92 ,
& F_33 ) ;
V_12 = F_52 ( V_25 , ( void * * ) & V_4 ) ;
if ( F_7 ( V_12 ) )
F_31 ( V_4 ) ;
F_48 ( V_25 ) ;
}
static inline void F_50 ( struct V_28 * V_29 )
{ }
static inline int F_45 ( struct V_28 * V_29 )
{ return 0 ; }
static const struct V_93 * F_53 ( const struct V_93 * V_94 ,
const struct V_51 * V_52 )
{
while ( V_94 -> V_95 [ 0 ] ) {
if ( strcmp ( V_52 -> V_95 , V_94 -> V_95 ) == 0 )
return V_94 ;
V_94 ++ ;
}
return NULL ;
}
static int F_54 ( struct V_96 * V_40 , struct V_97 * V_98 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_99 * V_100 ;
if ( ! V_52 )
return 0 ;
if ( F_56 ( V_40 , V_98 ) )
return 1 ;
if ( F_57 ( V_40 , V_98 ) )
return 1 ;
V_100 = F_58 ( V_98 ) ;
if ( V_100 -> V_101 )
return F_53 ( V_100 -> V_101 , V_52 ) != NULL ;
return 0 ;
}
static int F_59 ( struct V_96 * V_40 , struct V_102 * V_103 )
{
struct V_51 * V_52 = F_60 ( V_40 ) ;
int V_104 ;
V_104 = F_61 ( V_40 , V_103 ) ;
if ( V_104 != - V_90 )
return V_104 ;
if ( F_62 ( V_103 , L_7 ,
V_105 , V_52 -> V_95 ) )
return - V_91 ;
F_63 ( V_40 , L_8 ) ;
return 0 ;
}
static int F_64 ( struct V_28 * V_47 )
{
return F_65 ( V_47 -> V_106 -> V_107 ) ;
}
static void F_66 ( struct V_28 * V_47 , int V_108 )
{
F_67 ( V_47 -> V_106 -> V_107 , V_108 ) ;
}
static int F_68 ( struct V_28 * V_47 )
{
return F_65 ( V_47 -> V_106 -> V_109 ) ;
}
static int F_69 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
struct V_96 * V_40 = & V_47 -> V_40 ;
int V_36 = 0 ;
V_36 = F_70 ( V_111 -> V_107 , V_112 |
V_113 , L_9 ) ;
if ( V_36 ) {
F_26 ( V_40 , L_10 , V_111 -> V_107 ) ;
return V_36 ;
}
if ( V_111 -> V_114 ) {
if ( F_70 ( V_111 -> V_109 , V_115 , L_11 ) ) {
F_26 ( V_40 , L_12 ,
V_111 -> V_109 ) ;
V_111 -> V_114 = NULL ;
}
}
return V_36 ;
}
static void F_71 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
if ( V_111 -> V_114 )
F_72 ( V_111 -> V_109 ) ;
F_72 ( V_111 -> V_107 ) ;
}
static int F_73 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
int V_116 = 0 , V_108 = 1 , V_36 = 0 ;
if ( V_111 -> V_117 )
V_111 -> V_117 ( V_47 ) ;
V_111 -> V_118 ( V_47 , V_108 ) ;
F_74 ( V_119 ) ;
while ( V_116 ++ < V_120 * 2 ) {
if ( V_108 ) {
if ( V_111 -> V_114 && V_111 -> V_114 ( V_47 ) )
break;
if ( ! V_111 -> V_121 ( V_47 ) ) {
F_21 ( & V_47 -> V_40 ,
L_13 ) ;
V_36 = - V_122 ;
break;
}
}
V_108 = ! V_108 ;
V_111 -> V_118 ( V_47 , V_108 ) ;
F_74 ( V_119 ) ;
}
if ( V_111 -> V_123 )
V_111 -> V_123 ( V_47 ) ;
return V_36 ;
}
int F_75 ( struct V_28 * V_47 )
{
return F_73 ( V_47 ) ;
}
int F_76 ( struct V_28 * V_47 )
{
int V_36 ;
V_36 = F_69 ( V_47 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_73 ( V_47 ) ;
F_71 ( V_47 ) ;
return V_36 ;
}
int F_77 ( struct V_28 * V_47 )
{
if ( ! V_47 -> V_106 )
return - V_124 ;
F_63 ( & V_47 -> V_40 , L_14 ) ;
return V_47 -> V_106 -> V_125 ( V_47 ) ;
}
static int F_78 ( struct V_96 * V_40 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_99 * V_100 ;
int V_12 ;
if ( ! V_52 )
return 0 ;
if ( ! V_52 -> V_43 ) {
int V_43 = - V_126 ;
if ( V_40 -> V_127 ) {
V_43 = F_79 ( V_40 -> V_127 , L_15 ) ;
if ( V_43 == - V_128 || V_43 == - V_129 )
V_43 = F_80 ( V_40 -> V_127 , 0 ) ;
} else if ( F_81 ( V_40 ) ) {
V_43 = F_82 ( F_81 ( V_40 ) , 0 ) ;
}
if ( V_43 == - V_130 )
return V_43 ;
if ( V_43 < 0 )
V_43 = 0 ;
V_52 -> V_43 = V_43 ;
}
V_100 = F_58 ( V_40 -> V_100 ) ;
if ( ! V_100 -> V_131 || ! V_100 -> V_101 )
return - V_90 ;
if ( V_52 -> V_23 & V_132 ) {
int V_133 = - V_126 ;
if ( V_40 -> V_127 ) {
V_133 = F_79 ( V_40 -> V_127 , L_16 ) ;
if ( V_133 == - V_130 )
return V_133 ;
}
F_83 ( & V_52 -> V_40 , true ) ;
if ( V_133 > 0 && V_133 != V_52 -> V_43 )
V_12 = F_84 ( V_40 , V_133 ) ;
else if ( V_52 -> V_43 > 0 )
V_12 = F_85 ( V_40 , V_52 -> V_43 ) ;
else
V_12 = 0 ;
if ( V_12 )
F_26 ( & V_52 -> V_40 , L_17 ) ;
}
F_63 ( V_40 , L_18 ) ;
V_12 = F_86 ( V_40 -> V_127 , false ) ;
if ( V_12 < 0 )
goto V_134;
V_12 = F_87 ( & V_52 -> V_40 , true ) ;
if ( V_12 == - V_130 )
goto V_134;
V_12 = V_100 -> V_131 ( V_52 , F_53 ( V_100 -> V_101 , V_52 ) ) ;
if ( V_12 )
goto V_135;
return 0 ;
V_135:
F_88 ( & V_52 -> V_40 , true ) ;
V_134:
F_89 ( & V_52 -> V_40 ) ;
F_83 ( & V_52 -> V_40 , false ) ;
return V_12 ;
}
static int F_90 ( struct V_96 * V_40 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_99 * V_100 ;
int V_12 = 0 ;
if ( ! V_52 || ! V_40 -> V_100 )
return 0 ;
V_100 = F_58 ( V_40 -> V_100 ) ;
if ( V_100 -> remove ) {
F_63 ( V_40 , L_19 ) ;
V_12 = V_100 -> remove ( V_52 ) ;
}
F_88 ( & V_52 -> V_40 , true ) ;
F_89 ( & V_52 -> V_40 ) ;
F_83 ( & V_52 -> V_40 , false ) ;
return V_12 ;
}
static void F_91 ( struct V_96 * V_40 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_99 * V_100 ;
if ( ! V_52 || ! V_40 -> V_100 )
return;
V_100 = F_58 ( V_40 -> V_100 ) ;
if ( V_100 -> V_136 )
V_100 -> V_136 ( V_52 ) ;
}
static void F_92 ( struct V_96 * V_40 )
{
F_31 ( F_60 ( V_40 ) ) ;
}
static T_7
F_93 ( struct V_96 * V_40 , struct V_137 * V_138 , char * V_61 )
{
return sprintf ( V_61 , L_20 , V_40 -> type == & V_139 ?
F_60 ( V_40 ) -> V_95 : F_94 ( V_40 ) -> V_95 ) ;
}
static T_7
F_95 ( struct V_96 * V_40 , struct V_137 * V_138 , char * V_61 )
{
struct V_51 * V_52 = F_60 ( V_40 ) ;
int V_60 ;
V_60 = F_96 ( V_40 , V_61 , V_140 - 1 ) ;
if ( V_60 != - V_90 )
return V_60 ;
return sprintf ( V_61 , L_21 , V_105 , V_52 -> V_95 ) ;
}
struct V_51 * F_55 ( struct V_96 * V_40 )
{
return ( V_40 -> type == & V_139 )
? F_60 ( V_40 )
: NULL ;
}
static unsigned short F_97 ( struct V_51 * V_52 )
{
unsigned short V_13 = V_52 -> V_13 ;
if ( V_52 -> V_23 & V_24 )
V_13 |= V_141 ;
if ( V_52 -> V_23 & V_142 )
V_13 |= V_143 ;
return V_13 ;
}
static int F_98 ( unsigned V_13 , unsigned short V_23 )
{
if ( V_23 & V_24 ) {
if ( V_13 > 0x3ff )
return - V_128 ;
} else {
if ( V_13 == 0x00 || V_13 > 0x7f )
return - V_128 ;
}
return 0 ;
}
static int F_99 ( unsigned short V_13 )
{
if ( V_13 < 0x08 || V_13 > 0x77 )
return - V_128 ;
return 0 ;
}
static int F_100 ( struct V_96 * V_40 , void * V_144 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
int V_13 = * ( int * ) V_144 ;
if ( V_52 && F_97 ( V_52 ) == V_13 )
return - V_122 ;
return 0 ;
}
static int F_101 ( struct V_28 * V_29 , int V_13 )
{
struct V_28 * V_89 = F_102 ( V_29 ) ;
int V_145 ;
V_145 = F_103 ( & V_29 -> V_40 , & V_13 ,
F_100 ) ;
if ( ! V_145 && V_89 )
V_145 = F_101 ( V_89 , V_13 ) ;
return V_145 ;
}
static int F_104 ( struct V_96 * V_40 , void * V_144 )
{
int V_145 ;
if ( V_40 -> type == & V_146 )
V_145 = F_103 ( V_40 , V_144 ,
F_104 ) ;
else
V_145 = F_100 ( V_40 , V_144 ) ;
return V_145 ;
}
static int F_105 ( struct V_28 * V_29 , int V_13 )
{
struct V_28 * V_89 = F_102 ( V_29 ) ;
int V_145 = 0 ;
if ( V_89 )
V_145 = F_101 ( V_89 , V_13 ) ;
if ( ! V_145 )
V_145 = F_103 ( & V_29 -> V_40 , & V_13 ,
F_104 ) ;
return V_145 ;
}
void F_106 ( struct V_28 * V_29 )
{
struct V_28 * V_89 = F_102 ( V_29 ) ;
if ( V_89 )
F_106 ( V_89 ) ;
else
F_107 ( & V_29 -> V_147 ) ;
}
static int F_108 ( struct V_28 * V_29 )
{
struct V_28 * V_89 = F_102 ( V_29 ) ;
if ( V_89 )
return F_108 ( V_89 ) ;
else
return F_109 ( & V_29 -> V_147 ) ;
}
void F_110 ( struct V_28 * V_29 )
{
struct V_28 * V_89 = F_102 ( V_29 ) ;
if ( V_89 )
F_110 ( V_89 ) ;
else
F_111 ( & V_29 -> V_147 ) ;
}
static void F_112 ( struct V_28 * V_47 ,
struct V_51 * V_52 )
{
struct V_34 * V_35 = F_81 ( & V_52 -> V_40 ) ;
if ( V_35 ) {
F_113 ( & V_52 -> V_40 , L_22 , F_114 ( V_35 ) ) ;
return;
}
F_113 ( & V_52 -> V_40 , L_23 , F_115 ( V_47 ) ,
F_97 ( V_52 ) ) ;
}
struct V_51 *
F_20 ( struct V_28 * V_47 , struct V_7 const * V_8 )
{
struct V_51 * V_52 ;
int V_12 ;
V_52 = F_28 ( sizeof *V_52 , V_58 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_29 = V_47 ;
V_52 -> V_40 . V_148 = V_8 -> V_148 ;
if ( V_8 -> V_149 )
V_52 -> V_40 . V_149 = * V_8 -> V_149 ;
V_52 -> V_23 = V_8 -> V_23 ;
V_52 -> V_13 = V_8 -> V_13 ;
V_52 -> V_43 = V_8 -> V_43 ;
F_18 ( V_52 -> V_95 , V_8 -> type , sizeof( V_52 -> V_95 ) ) ;
V_12 = F_98 ( V_52 -> V_13 , V_52 -> V_23 ) ;
if ( V_12 ) {
F_21 ( & V_47 -> V_40 , L_24 ,
V_52 -> V_23 & V_24 ? 10 : 7 , V_52 -> V_13 ) ;
goto V_150;
}
V_12 = F_105 ( V_47 , F_97 ( V_52 ) ) ;
if ( V_12 )
goto V_151;
V_52 -> V_40 . V_89 = & V_52 -> V_29 -> V_40 ;
V_52 -> V_40 . V_152 = & V_153 ;
V_52 -> V_40 . type = & V_139 ;
V_52 -> V_40 . V_127 = V_8 -> V_127 ;
V_52 -> V_40 . V_39 = V_8 -> V_39 ;
F_112 ( V_47 , V_52 ) ;
V_12 = F_116 ( & V_52 -> V_40 ) ;
if ( V_12 )
goto V_151;
F_63 ( & V_47 -> V_40 , L_25 ,
V_52 -> V_95 , F_19 ( & V_52 -> V_40 ) ) ;
return V_52 ;
V_151:
F_21 ( & V_47 -> V_40 , L_26
L_27 , V_52 -> V_95 , V_52 -> V_13 , V_12 ) ;
V_150:
F_31 ( V_52 ) ;
return NULL ;
}
void F_117 ( struct V_51 * V_52 )
{
if ( V_52 -> V_40 . V_127 )
F_118 ( V_52 -> V_40 . V_127 , V_154 ) ;
F_119 ( & V_52 -> V_40 ) ;
}
static int F_120 ( struct V_51 * V_52 ,
const struct V_93 * V_94 )
{
return 0 ;
}
static int F_121 ( struct V_51 * V_52 )
{
return 0 ;
}
struct V_51 * F_122 ( struct V_28 * V_29 , T_8 V_155 )
{
struct V_7 V_8 = {
F_123 ( L_28 , V_155 ) ,
} ;
return F_20 ( V_29 , & V_8 ) ;
}
static void F_124 ( struct V_96 * V_40 )
{
struct V_28 * V_47 = F_94 ( V_40 ) ;
F_125 ( & V_47 -> V_156 ) ;
}
static inline unsigned int F_126 ( struct V_28 * V_29 )
{
unsigned int V_157 = 0 ;
while ( ( V_29 = F_102 ( V_29 ) ) )
V_157 ++ ;
return V_157 ;
}
static T_7
F_127 ( struct V_96 * V_40 , struct V_137 * V_138 ,
const char * V_61 , T_9 V_158 )
{
struct V_28 * V_47 = F_94 ( V_40 ) ;
struct V_7 V_8 ;
struct V_51 * V_52 ;
char * V_159 , V_160 ;
int V_41 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_159 = strchr ( V_61 , ' ' ) ;
if ( ! V_159 ) {
F_21 ( V_40 , L_29 , L_30 ) ;
return - V_128 ;
}
if ( V_159 - V_61 > V_161 - 1 ) {
F_21 ( V_40 , L_31 , L_30 ) ;
return - V_128 ;
}
memcpy ( V_8 . type , V_61 , V_159 - V_61 ) ;
V_41 = sscanf ( ++ V_159 , L_32 , & V_8 . V_13 , & V_160 ) ;
if ( V_41 < 1 ) {
F_21 ( V_40 , L_33 , L_30 ) ;
return - V_128 ;
}
if ( V_41 > 1 && V_160 != '\n' ) {
F_21 ( V_40 , L_34 , L_30 ) ;
return - V_128 ;
}
if ( ( V_8 . V_13 & V_141 ) == V_141 ) {
V_8 . V_13 &= ~ V_141 ;
V_8 . V_23 |= V_24 ;
}
if ( V_8 . V_13 & V_143 ) {
V_8 . V_13 &= ~ V_143 ;
V_8 . V_23 |= V_142 ;
}
V_52 = F_20 ( V_47 , & V_8 ) ;
if ( ! V_52 )
return - V_128 ;
F_128 ( & V_47 -> V_162 ) ;
F_129 ( & V_52 -> V_163 , & V_47 -> V_164 ) ;
F_130 ( & V_47 -> V_162 ) ;
F_131 ( V_40 , L_35 , L_30 ,
V_8 . type , V_8 . V_13 ) ;
return V_158 ;
}
static T_7
F_132 ( struct V_96 * V_40 , struct V_137 * V_138 ,
const char * V_61 , T_9 V_158 )
{
struct V_28 * V_47 = F_94 ( V_40 ) ;
struct V_51 * V_52 , * V_165 ;
unsigned short V_13 ;
char V_160 ;
int V_41 ;
V_41 = sscanf ( V_61 , L_32 , & V_13 , & V_160 ) ;
if ( V_41 < 1 ) {
F_21 ( V_40 , L_33 , L_36 ) ;
return - V_128 ;
}
if ( V_41 > 1 && V_160 != '\n' ) {
F_21 ( V_40 , L_34 , L_36 ) ;
return - V_128 ;
}
V_41 = - V_126 ;
F_133 ( & V_47 -> V_162 ,
F_126 ( V_47 ) ) ;
F_134 (client, next, &adap->userspace_clients,
detected) {
if ( F_97 ( V_52 ) == V_13 ) {
F_131 ( V_40 , L_37 ,
L_36 , V_52 -> V_95 , V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
V_41 = V_158 ;
break;
}
}
F_130 ( & V_47 -> V_162 ) ;
if ( V_41 < 0 )
F_21 ( V_40 , L_38 ,
L_36 ) ;
return V_41 ;
}
struct V_28 * F_136 ( struct V_96 * V_40 )
{
return ( V_40 -> type == & V_146 )
? F_94 ( V_40 )
: NULL ;
}
static void F_137 ( struct V_28 * V_29 )
{
struct V_166 * V_167 ;
F_138 ( & V_168 ) ;
F_139 (devinfo, &__i2c_board_list, list) {
if ( V_167 -> V_169 == V_29 -> V_170
&& ! F_20 ( V_29 ,
& V_167 -> V_171 ) )
F_21 ( & V_29 -> V_40 ,
L_39 ,
V_167 -> V_171 . V_13 ) ;
}
F_140 ( & V_168 ) ;
}
static struct V_51 * F_141 ( struct V_28 * V_47 ,
struct V_172 * V_173 )
{
struct V_51 * V_145 ;
struct V_7 V_8 = {} ;
struct V_174 V_175 = {} ;
const T_10 * V_176 ;
T_3 V_13 ;
int V_60 ;
F_63 ( & V_47 -> V_40 , L_40 , V_173 -> V_177 ) ;
if ( F_142 ( V_173 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_21 ( & V_47 -> V_40 , L_41 ,
V_173 -> V_177 ) ;
return F_143 ( - V_128 ) ;
}
V_176 = F_144 ( V_173 , L_42 , & V_60 ) ;
if ( ! V_176 || ( V_60 < sizeof( * V_176 ) ) ) {
F_21 ( & V_47 -> V_40 , L_43 ,
V_173 -> V_177 ) ;
return F_143 ( - V_128 ) ;
}
V_13 = F_145 ( V_176 ) ;
if ( V_13 & V_178 ) {
V_13 &= ~ V_178 ;
V_8 . V_23 |= V_24 ;
}
if ( V_13 & V_179 ) {
V_13 &= ~ V_179 ;
V_8 . V_23 |= V_142 ;
}
if ( F_98 ( V_13 , V_8 . V_23 ) ) {
F_21 ( & V_47 -> V_40 , L_44 ,
V_8 . V_13 , V_173 -> V_177 ) ;
return F_143 ( - V_128 ) ;
}
V_8 . V_13 = V_13 ;
V_8 . V_127 = F_146 ( V_173 ) ;
V_8 . V_149 = & V_175 ;
if ( F_144 ( V_173 , L_45 , NULL ) )
V_8 . V_23 |= V_132 ;
V_145 = F_20 ( V_47 , & V_8 ) ;
if ( V_145 == NULL ) {
F_21 ( & V_47 -> V_40 , L_46 ,
V_173 -> V_177 ) ;
F_147 ( V_173 ) ;
return F_143 ( - V_128 ) ;
}
return V_145 ;
}
static void F_148 ( struct V_28 * V_47 )
{
struct V_172 * V_173 ;
if ( ! V_47 -> V_40 . V_127 )
return;
F_63 ( & V_47 -> V_40 , L_47 ) ;
F_149 (adap->dev.of_node, node) {
if ( F_150 ( V_173 , V_154 ) )
continue;
F_141 ( V_47 , V_173 ) ;
}
}
static int F_151 ( struct V_96 * V_40 , void * V_4 )
{
return V_40 -> V_127 == V_4 ;
}
struct V_51 * F_152 ( struct V_172 * V_173 )
{
struct V_96 * V_40 ;
struct V_51 * V_52 ;
V_40 = F_153 ( & V_153 , NULL , V_173 , F_151 ) ;
if ( ! V_40 )
return NULL ;
V_52 = F_55 ( V_40 ) ;
if ( ! V_52 )
F_154 ( V_40 ) ;
return V_52 ;
}
struct V_28 * F_155 ( struct V_172 * V_173 )
{
struct V_96 * V_40 ;
struct V_28 * V_29 ;
V_40 = F_153 ( & V_153 , NULL , V_173 , F_151 ) ;
if ( ! V_40 )
return NULL ;
V_29 = F_136 ( V_40 ) ;
if ( ! V_29 )
F_154 ( V_40 ) ;
return V_29 ;
}
struct V_28 * F_156 ( struct V_172 * V_173 )
{
struct V_28 * V_29 ;
V_29 = F_155 ( V_173 ) ;
if ( ! V_29 )
return NULL ;
if ( ! F_157 ( V_29 -> V_180 ) ) {
F_154 ( & V_29 -> V_40 ) ;
V_29 = NULL ;
}
return V_29 ;
}
static void F_148 ( struct V_28 * V_47 ) { }
static int F_158 ( struct V_99 * V_100 ,
struct V_28 * V_47 )
{
F_159 ( V_47 , V_100 ) ;
if ( V_100 -> V_181 ) {
F_26 ( & V_47 -> V_40 , L_48 ,
V_100 -> V_100 . V_95 ) ;
F_26 ( & V_47 -> V_40 , L_49
L_50 ) ;
V_100 -> V_181 ( V_47 ) ;
}
return 0 ;
}
static int F_160 ( struct V_97 * V_182 , void * V_4 )
{
return F_158 ( F_58 ( V_182 ) , V_4 ) ;
}
static int F_161 ( struct V_28 * V_47 )
{
int V_41 = 0 ;
if ( F_162 ( F_163 ( ! V_153 . V_183 ) ) ) {
V_41 = - V_184 ;
goto V_185;
}
if ( F_162 ( V_47 -> V_95 [ 0 ] == '\0' ) ) {
F_164 ( L_51
L_52 ) ;
return - V_128 ;
}
if ( F_162 ( ! V_47 -> V_186 ) ) {
F_164 ( L_53
L_54 , V_47 -> V_95 ) ;
return - V_128 ;
}
F_165 ( & V_47 -> V_147 ) ;
F_166 ( & V_47 -> V_162 ) ;
F_13 ( & V_47 -> V_164 ) ;
if ( V_47 -> V_187 == 0 )
V_47 -> V_187 = V_188 ;
F_113 ( & V_47 -> V_40 , L_55 , V_47 -> V_170 ) ;
V_47 -> V_40 . V_152 = & V_153 ;
V_47 -> V_40 . type = & V_146 ;
V_41 = F_116 ( & V_47 -> V_40 ) ;
if ( V_41 )
goto V_185;
F_63 ( & V_47 -> V_40 , L_56 , V_47 -> V_95 ) ;
F_167 ( & V_47 -> V_40 ) ;
#ifdef F_168
V_41 = F_169 ( V_189 , & V_47 -> V_40 ,
V_47 -> V_40 . V_89 ) ;
if ( V_41 )
F_26 ( & V_47 -> V_40 ,
L_57 ) ;
#endif
if ( V_47 -> V_106 ) {
struct V_110 * V_111 = V_47 -> V_106 ;
if ( ! V_111 -> V_125 ) {
F_21 ( & V_47 -> V_40 , L_58 ) ;
V_47 -> V_106 = NULL ;
goto V_190;
}
if ( V_111 -> V_125 == F_76 ) {
if ( ! F_170 ( V_111 -> V_107 ) ) {
F_21 ( & V_47 -> V_40 , L_59 ) ;
V_47 -> V_106 = NULL ;
goto V_190;
}
if ( F_170 ( V_111 -> V_109 ) )
V_111 -> V_114 = F_68 ;
else
V_111 -> V_114 = NULL ;
V_111 -> V_121 = F_64 ;
V_111 -> V_118 = F_66 ;
} else if ( ! V_111 -> V_118 || ! V_111 -> V_121 ) {
F_21 ( & V_47 -> V_40 , L_60 ) ;
V_47 -> V_106 = NULL ;
}
}
V_190:
F_148 ( V_47 ) ;
F_22 ( V_47 ) ;
F_45 ( V_47 ) ;
if ( V_47 -> V_170 < V_191 )
F_137 ( V_47 ) ;
F_128 ( & V_192 ) ;
F_171 ( & V_153 , NULL , V_47 , F_160 ) ;
F_130 ( & V_192 ) ;
return 0 ;
V_185:
F_128 ( & V_192 ) ;
F_172 ( & V_193 , V_47 -> V_170 ) ;
F_130 ( & V_192 ) ;
return V_41 ;
}
static int F_173 ( struct V_28 * V_47 )
{
int V_94 ;
F_128 ( & V_192 ) ;
V_94 = F_174 ( & V_193 , V_47 , V_47 -> V_170 , V_47 -> V_170 + 1 ,
V_58 ) ;
F_130 ( & V_192 ) ;
if ( V_94 < 0 )
return V_94 == - V_194 ? - V_122 : V_94 ;
return F_161 ( V_47 ) ;
}
int F_175 ( struct V_28 * V_29 )
{
struct V_96 * V_40 = & V_29 -> V_40 ;
int V_94 ;
if ( V_40 -> V_127 ) {
V_94 = F_176 ( V_40 -> V_127 , L_61 ) ;
if ( V_94 >= 0 ) {
V_29 -> V_170 = V_94 ;
return F_173 ( V_29 ) ;
}
}
F_128 ( & V_192 ) ;
V_94 = F_174 ( & V_193 , V_29 ,
V_191 , 0 , V_58 ) ;
F_130 ( & V_192 ) ;
if ( V_94 < 0 )
return V_94 ;
V_29 -> V_170 = V_94 ;
return F_161 ( V_29 ) ;
}
int F_177 ( struct V_28 * V_47 )
{
if ( V_47 -> V_170 == - 1 )
return F_175 ( V_47 ) ;
return F_173 ( V_47 ) ;
}
static void F_178 ( struct V_99 * V_100 ,
struct V_28 * V_29 )
{
struct V_51 * V_52 , * V_195 ;
F_134 (client, _n, &driver->clients, detected) {
if ( V_52 -> V_29 == V_29 ) {
F_63 ( & V_29 -> V_40 , L_62 ,
V_52 -> V_95 , V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
}
}
}
static int F_179 ( struct V_96 * V_40 , void * V_196 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
if ( V_52 && strcmp ( V_52 -> V_95 , L_28 ) )
F_117 ( V_52 ) ;
return 0 ;
}
static int F_180 ( struct V_96 * V_40 , void * V_196 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
if ( V_52 )
F_117 ( V_52 ) ;
return 0 ;
}
static int F_181 ( struct V_97 * V_182 , void * V_4 )
{
F_178 ( F_58 ( V_182 ) , V_4 ) ;
return 0 ;
}
void F_182 ( struct V_28 * V_47 )
{
struct V_28 * V_197 ;
struct V_51 * V_52 , * V_165 ;
F_128 ( & V_192 ) ;
V_197 = F_183 ( & V_193 , V_47 -> V_170 ) ;
F_130 ( & V_192 ) ;
if ( V_197 != V_47 ) {
F_184 ( L_63
L_64 , V_47 -> V_95 ) ;
return;
}
F_50 ( V_47 ) ;
F_128 ( & V_192 ) ;
F_171 ( & V_153 , NULL , V_47 ,
F_181 ) ;
F_130 ( & V_192 ) ;
F_133 ( & V_47 -> V_162 ,
F_126 ( V_47 ) ) ;
F_134 (client, next, &adap->userspace_clients,
detected) {
F_63 ( & V_47 -> V_40 , L_62 , V_52 -> V_95 ,
V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
}
F_130 ( & V_47 -> V_162 ) ;
F_103 ( & V_47 -> V_40 , NULL , F_179 ) ;
F_103 ( & V_47 -> V_40 , NULL , F_180 ) ;
#ifdef F_168
F_185 ( V_189 , & V_47 -> V_40 ,
V_47 -> V_40 . V_89 ) ;
#endif
F_63 ( & V_47 -> V_40 , L_65 , V_47 -> V_95 ) ;
F_186 ( & V_47 -> V_156 ) ;
F_119 ( & V_47 -> V_40 ) ;
F_187 ( & V_47 -> V_156 ) ;
F_128 ( & V_192 ) ;
F_172 ( & V_193 , V_47 -> V_170 ) ;
F_130 ( & V_192 ) ;
memset ( & V_47 -> V_40 , 0 , sizeof( V_47 -> V_40 ) ) ;
}
int F_188 ( void * V_4 , int (* F_189)( struct V_96 * , void * ) )
{
int V_41 ;
F_128 ( & V_192 ) ;
V_41 = F_190 ( & V_153 , NULL , V_4 , F_189 ) ;
F_130 ( & V_192 ) ;
return V_41 ;
}
static int F_191 ( struct V_96 * V_40 , void * V_4 )
{
if ( V_40 -> type != & V_146 )
return 0 ;
return F_158 ( V_4 , F_94 ( V_40 ) ) ;
}
int F_192 ( struct V_198 * V_180 , struct V_99 * V_100 )
{
int V_41 ;
if ( F_162 ( F_163 ( ! V_153 . V_183 ) ) )
return - V_184 ;
V_100 -> V_100 . V_180 = V_180 ;
V_100 -> V_100 . V_152 = & V_153 ;
V_41 = F_193 ( & V_100 -> V_100 ) ;
if ( V_41 )
return V_41 ;
F_184 ( L_66 , V_100 -> V_100 . V_95 ) ;
F_13 ( & V_100 -> V_199 ) ;
F_188 ( V_100 , F_191 ) ;
return 0 ;
}
static int F_194 ( struct V_96 * V_40 , void * V_4 )
{
if ( V_40 -> type == & V_146 )
F_178 ( V_4 , F_94 ( V_40 ) ) ;
return 0 ;
}
void F_195 ( struct V_99 * V_100 )
{
F_188 ( V_100 , F_194 ) ;
F_196 ( & V_100 -> V_100 ) ;
F_184 ( L_67 , V_100 -> V_100 . V_95 ) ;
}
struct V_51 * F_197 ( struct V_51 * V_52 )
{
if ( V_52 && F_198 ( & V_52 -> V_40 ) )
return V_52 ;
return NULL ;
}
void F_199 ( struct V_51 * V_52 )
{
if ( V_52 )
F_154 ( & V_52 -> V_40 ) ;
}
static int F_200 ( struct V_96 * V_40 , void * V_200 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_201 * V_202 = V_200 ;
struct V_99 * V_100 ;
if ( ! V_52 || ! V_52 -> V_40 . V_100 )
return 0 ;
V_100 = F_58 ( V_52 -> V_40 . V_100 ) ;
if ( V_100 -> V_64 )
V_100 -> V_64 ( V_52 , V_202 -> V_53 , V_202 -> V_202 ) ;
return 0 ;
}
void F_201 ( struct V_28 * V_47 , unsigned int V_53 , void * V_202 )
{
struct V_201 V_203 ;
V_203 . V_53 = V_53 ;
V_203 . V_202 = V_202 ;
F_103 ( & V_47 -> V_40 , & V_203 , F_200 ) ;
}
static int F_202 ( struct V_204 * V_205 , unsigned long V_74 ,
void * V_202 )
{
struct V_206 * V_207 = V_202 ;
struct V_28 * V_47 ;
struct V_51 * V_52 ;
switch ( F_203 ( V_74 , V_207 ) ) {
case V_208 :
V_47 = F_155 ( V_207 -> V_209 -> V_89 ) ;
if ( V_47 == NULL )
return V_210 ;
if ( F_150 ( V_207 -> V_209 , V_154 ) ) {
F_154 ( & V_47 -> V_40 ) ;
return V_210 ;
}
V_52 = F_141 ( V_47 , V_207 -> V_209 ) ;
F_154 ( & V_47 -> V_40 ) ;
if ( F_204 ( V_52 ) ) {
F_164 ( L_68 ,
V_211 , V_207 -> V_209 -> V_177 ) ;
return F_205 ( F_206 ( V_52 ) ) ;
}
break;
case V_212 :
if ( ! F_207 ( V_207 -> V_209 , V_154 ) )
return V_210 ;
V_52 = F_152 ( V_207 -> V_209 ) ;
if ( V_52 == NULL )
return V_210 ;
F_117 ( V_52 ) ;
F_154 ( & V_52 -> V_40 ) ;
break;
}
return V_210 ;
}
static int T_11 F_208 ( void )
{
int V_213 ;
V_213 = F_209 ( L_61 ) ;
F_210 ( & V_168 ) ;
if ( V_213 >= V_191 )
V_191 = V_213 + 1 ;
F_211 ( & V_168 ) ;
V_213 = F_212 ( & V_153 ) ;
if ( V_213 )
return V_213 ;
#ifdef F_168
V_189 = F_213 ( L_69 ) ;
if ( ! V_189 ) {
V_213 = - V_91 ;
goto V_214;
}
#endif
V_213 = F_214 ( & V_215 ) ;
if ( V_213 )
goto V_216;
if ( F_215 ( V_217 ) )
F_163 ( F_216 ( & V_218 ) ) ;
return 0 ;
V_216:
#ifdef F_168
F_217 ( V_189 ) ;
V_214:
#endif
F_218 ( & V_153 ) ;
return V_213 ;
}
static void T_12 F_219 ( void )
{
if ( F_215 ( V_217 ) )
F_163 ( F_220 ( & V_218 ) ) ;
F_195 ( & V_215 ) ;
#ifdef F_168
F_217 ( V_189 ) ;
#endif
F_218 ( & V_153 ) ;
F_221 () ;
}
static int F_222 ( struct V_28 * V_47 , struct V_55 * V_219 , char * V_220 )
{
F_223 ( & V_47 -> V_40 , L_70 ,
V_220 , V_219 -> V_13 , V_219 -> V_60 ,
V_219 -> V_23 & V_62 ? L_71 : L_72 ) ;
return - V_124 ;
}
static int F_224 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_221 )
{
const struct V_222 * V_223 = V_47 -> V_224 ;
int V_225 = V_223 -> V_226 , V_116 ;
bool V_227 = true ;
if ( V_223 -> V_23 & V_228 ) {
V_225 = 2 ;
if ( V_221 == 2 ) {
if ( V_223 -> V_23 & V_229 && V_56 [ 0 ] . V_23 & V_62 )
return F_222 ( V_47 , & V_56 [ 0 ] , L_73 ) ;
if ( V_223 -> V_23 & V_230 && ! ( V_56 [ 1 ] . V_23 & V_62 ) )
return F_222 ( V_47 , & V_56 [ 1 ] , L_74 ) ;
if ( V_223 -> V_23 & V_231 && V_56 [ 0 ] . V_13 != V_56 [ 1 ] . V_13 )
return F_222 ( V_47 , & V_56 [ 0 ] , L_75 ) ;
if ( F_225 ( V_56 [ 0 ] . V_60 , V_223 -> V_232 ) )
return F_222 ( V_47 , & V_56 [ 0 ] , L_76 ) ;
if ( F_225 ( V_56 [ 1 ] . V_60 , V_223 -> V_233 ) )
return F_222 ( V_47 , & V_56 [ 1 ] , L_76 ) ;
V_227 = false ;
}
}
if ( F_225 ( V_221 , V_225 ) )
return F_222 ( V_47 , & V_56 [ 0 ] , L_77 ) ;
for ( V_116 = 0 ; V_116 < V_221 ; V_116 ++ ) {
T_8 V_60 = V_56 [ V_116 ] . V_60 ;
if ( V_56 [ V_116 ] . V_23 & V_62 ) {
if ( V_227 && F_225 ( V_60 , V_223 -> V_234 ) )
return F_222 ( V_47 , & V_56 [ V_116 ] , L_76 ) ;
} else {
if ( V_227 && F_225 ( V_60 , V_223 -> V_235 ) )
return F_222 ( V_47 , & V_56 [ V_116 ] , L_76 ) ;
}
}
return 0 ;
}
int F_226 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_221 )
{
unsigned long V_236 ;
int V_36 , V_237 ;
if ( V_47 -> V_224 && F_224 ( V_47 , V_56 , V_221 ) )
return - V_124 ;
if ( F_227 ( & V_1 ) ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_221 ; V_116 ++ )
if ( V_56 [ V_116 ] . V_23 & V_62 )
F_228 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
else
F_229 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
}
V_236 = V_238 ;
for ( V_36 = 0 , V_237 = 0 ; V_237 <= V_47 -> V_239 ; V_237 ++ ) {
V_36 = V_47 -> V_186 -> V_240 ( V_47 , V_56 , V_221 ) ;
if ( V_36 != - V_184 )
break;
if ( F_230 ( V_238 , V_236 + V_47 -> V_187 ) )
break;
}
if ( F_227 ( & V_1 ) ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_36 ; V_116 ++ )
if ( V_56 [ V_116 ] . V_23 & V_62 )
F_231 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
F_232 ( V_47 , V_116 , V_36 ) ;
}
return V_36 ;
}
int F_29 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_221 )
{
int V_36 ;
if ( V_47 -> V_186 -> V_240 ) {
#ifdef F_233
for ( V_36 = 0 ; V_36 < V_221 ; V_36 ++ ) {
F_63 ( & V_47 -> V_40 , L_78
L_79 , V_36 , ( V_56 [ V_36 ] . V_23 & V_62 )
? 'R' : 'W' , V_56 [ V_36 ] . V_13 , V_56 [ V_36 ] . V_60 ,
( V_56 [ V_36 ] . V_23 & V_241 ) ? L_80 : L_81 ) ;
}
#endif
if ( F_234 () || F_235 () ) {
V_36 = F_108 ( V_47 ) ;
if ( ! V_36 )
return - V_184 ;
} else {
F_106 ( V_47 ) ;
}
V_36 = F_226 ( V_47 , V_56 , V_221 ) ;
F_110 ( V_47 ) ;
return V_36 ;
} else {
F_63 ( & V_47 -> V_40 , L_82 ) ;
return - V_124 ;
}
}
int F_236 ( const struct V_51 * V_52 , const char * V_61 , int V_158 )
{
int V_36 ;
struct V_28 * V_47 = V_52 -> V_29 ;
struct V_55 V_219 ;
V_219 . V_13 = V_52 -> V_13 ;
V_219 . V_23 = V_52 -> V_23 & V_242 ;
V_219 . V_60 = V_158 ;
V_219 . V_61 = ( char * ) V_61 ;
V_36 = F_29 ( V_47 , & V_219 , 1 ) ;
return ( V_36 == 1 ) ? V_158 : V_36 ;
}
int F_237 ( const struct V_51 * V_52 , char * V_61 , int V_158 )
{
struct V_28 * V_47 = V_52 -> V_29 ;
struct V_55 V_219 ;
int V_36 ;
V_219 . V_13 = V_52 -> V_13 ;
V_219 . V_23 = V_52 -> V_23 & V_242 ;
V_219 . V_23 |= V_62 ;
V_219 . V_60 = V_158 ;
V_219 . V_61 = V_61 ;
V_36 = F_29 ( V_47 , & V_219 , 1 ) ;
return ( V_36 == 1 ) ? V_158 : V_36 ;
}
static int F_238 ( struct V_28 * V_47 , unsigned short V_13 )
{
int V_78 ;
union V_243 V_196 ;
#ifdef F_239
if ( V_13 == 0x73 && ( V_47 -> V_244 & V_245 )
&& F_240 ( V_47 , V_246 ) )
V_78 = F_241 ( V_47 , V_13 , 0 , V_247 , 0 ,
V_248 , & V_196 ) ;
else
#endif
if ( ! ( ( V_13 & ~ 0x07 ) == 0x30 || ( V_13 & ~ 0x0f ) == 0x50 )
&& F_240 ( V_47 , V_249 ) )
V_78 = F_241 ( V_47 , V_13 , 0 , V_250 , 0 ,
V_251 , NULL ) ;
else if ( F_240 ( V_47 , V_252 ) )
V_78 = F_241 ( V_47 , V_13 , 0 , V_247 , 0 ,
V_253 , & V_196 ) ;
else {
F_26 ( & V_47 -> V_40 , L_83 ,
V_13 ) ;
V_78 = - V_124 ;
}
return V_78 >= 0 ;
}
static int F_242 ( struct V_51 * V_254 ,
struct V_99 * V_100 )
{
struct V_7 V_8 ;
struct V_28 * V_29 = V_254 -> V_29 ;
int V_13 = V_254 -> V_13 ;
int V_78 ;
V_78 = F_99 ( V_13 ) ;
if ( V_78 ) {
F_26 ( & V_29 -> V_40 , L_84 ,
V_13 ) ;
return V_78 ;
}
if ( F_105 ( V_29 , V_13 ) )
return 0 ;
if ( ! F_238 ( V_29 , V_13 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_13 = V_13 ;
V_78 = V_100 -> V_255 ( V_254 , & V_8 ) ;
if ( V_78 ) {
return V_78 == - V_90 ? 0 : V_78 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_21 ( & V_29 -> V_40 , L_85
L_86 , V_100 -> V_100 . V_95 ,
V_13 ) ;
} else {
struct V_51 * V_52 ;
if ( V_29 -> V_244 & V_256 )
F_26 ( & V_29 -> V_40 ,
L_87
L_88
L_89 ,
V_8 . V_13 ) ;
F_63 ( & V_29 -> V_40 , L_90 ,
V_8 . type , V_8 . V_13 ) ;
V_52 = F_20 ( V_29 , & V_8 ) ;
if ( V_52 )
F_129 ( & V_52 -> V_163 , & V_100 -> V_199 ) ;
else
F_21 ( & V_29 -> V_40 , L_91 ,
V_8 . type , V_8 . V_13 ) ;
}
return 0 ;
}
static int F_159 ( struct V_28 * V_29 , struct V_99 * V_100 )
{
const unsigned short * V_257 ;
struct V_51 * V_254 ;
int V_116 , V_78 = 0 ;
int V_258 = F_115 ( V_29 ) ;
V_257 = V_100 -> V_257 ;
if ( ! V_100 -> V_255 || ! V_257 )
return 0 ;
if ( V_29 -> V_244 == V_256 ) {
F_63 ( & V_29 -> V_40 ,
L_92
L_93
L_94 ,
V_100 -> V_100 . V_95 ) ;
return 0 ;
}
if ( ! ( V_29 -> V_244 & V_100 -> V_244 ) )
return 0 ;
V_254 = F_28 ( sizeof( struct V_51 ) , V_58 ) ;
if ( ! V_254 )
return - V_91 ;
V_254 -> V_29 = V_29 ;
for ( V_116 = 0 ; V_257 [ V_116 ] != V_259 ; V_116 += 1 ) {
F_63 ( & V_29 -> V_40 , L_95
L_96 , V_258 , V_257 [ V_116 ] ) ;
V_254 -> V_13 = V_257 [ V_116 ] ;
V_78 = F_242 ( V_254 , V_100 ) ;
if ( F_162 ( V_78 ) )
break;
}
F_31 ( V_254 ) ;
return V_78 ;
}
int F_243 ( struct V_28 * V_47 , unsigned short V_13 )
{
return F_241 ( V_47 , V_13 , 0 , V_247 , 0 ,
V_251 , NULL ) >= 0 ;
}
struct V_51 *
F_244 ( struct V_28 * V_47 ,
struct V_7 * V_8 ,
unsigned short const * V_260 ,
int (* V_131)( struct V_28 * , unsigned short V_13 ) )
{
int V_116 ;
if ( ! V_131 )
V_131 = F_238 ;
for ( V_116 = 0 ; V_260 [ V_116 ] != V_259 ; V_116 ++ ) {
if ( F_99 ( V_260 [ V_116 ] ) < 0 ) {
F_26 ( & V_47 -> V_40 , L_97
L_98 , V_260 [ V_116 ] ) ;
continue;
}
if ( F_105 ( V_47 , V_260 [ V_116 ] ) ) {
F_63 ( & V_47 -> V_40 , L_99
L_100 , V_260 [ V_116 ] ) ;
continue;
}
if ( V_131 ( V_47 , V_260 [ V_116 ] ) )
break;
}
if ( V_260 [ V_116 ] == V_259 ) {
F_63 ( & V_47 -> V_40 , L_101 ) ;
return NULL ;
}
V_8 -> V_13 = V_260 [ V_116 ] ;
return F_20 ( V_47 , V_8 ) ;
}
struct V_28 * F_245 ( int V_170 )
{
struct V_28 * V_29 ;
F_128 ( & V_192 ) ;
V_29 = F_183 ( & V_193 , V_170 ) ;
if ( ! V_29 )
goto exit;
if ( F_157 ( V_29 -> V_180 ) )
F_198 ( & V_29 -> V_40 ) ;
else
V_29 = NULL ;
exit:
F_130 ( & V_192 ) ;
return V_29 ;
}
void F_246 ( struct V_28 * V_47 )
{
if ( ! V_47 )
return;
F_154 ( & V_47 -> V_40 ) ;
F_247 ( V_47 -> V_180 ) ;
}
static T_4 F_248 ( T_8 V_4 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < 8 ; V_116 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_261 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_249 ( T_4 V_262 , T_4 * V_183 , T_9 V_158 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_158 ; V_116 ++ )
V_262 = F_248 ( ( V_262 ^ V_183 [ V_116 ] ) << 8 ) ;
return V_262 ;
}
static T_4 F_250 ( T_4 V_263 , struct V_55 * V_219 )
{
T_4 V_13 = ( V_219 -> V_13 << 1 ) | ! ! ( V_219 -> V_23 & V_62 ) ;
V_263 = F_249 ( V_263 , & V_13 , 1 ) ;
return F_249 ( V_263 , V_219 -> V_61 , V_219 -> V_60 ) ;
}
static inline void F_251 ( struct V_55 * V_219 )
{
V_219 -> V_61 [ V_219 -> V_60 ] = F_250 ( 0 , V_219 ) ;
V_219 -> V_60 ++ ;
}
static int F_252 ( T_4 V_264 , struct V_55 * V_219 )
{
T_4 V_265 = V_219 -> V_61 [ -- V_219 -> V_60 ] ;
V_264 = F_250 ( V_264 , V_219 ) ;
if ( V_265 != V_264 ) {
F_184 ( L_102 ,
V_265 , V_264 ) ;
return - V_266 ;
}
return 0 ;
}
T_13 F_35 ( const struct V_51 * V_52 )
{
union V_243 V_4 ;
int V_12 ;
V_12 = F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_247 , 0 ,
V_253 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_267 ;
}
T_13 F_36 ( const struct V_51 * V_52 , T_4 V_268 )
{
return F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_250 , V_268 , V_253 , NULL ) ;
}
T_13 F_37 ( const struct V_51 * V_52 , T_4 V_64 )
{
union V_243 V_4 ;
int V_12 ;
V_12 = F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_247 , V_64 ,
V_248 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_267 ;
}
T_13 F_38 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_268 )
{
union V_243 V_4 ;
V_4 . V_267 = V_268 ;
return F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_250 , V_64 ,
V_248 , & V_4 ) ;
}
T_13 F_39 ( const struct V_51 * V_52 , T_4 V_64 )
{
union V_243 V_4 ;
int V_12 ;
V_12 = F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_247 , V_64 ,
V_269 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_270 ;
}
T_13 F_40 ( const struct V_51 * V_52 , T_4 V_64 ,
T_8 V_268 )
{
union V_243 V_4 ;
V_4 . V_270 = V_268 ;
return F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_250 , V_64 ,
V_269 , & V_4 ) ;
}
T_13 F_41 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 * V_271 )
{
union V_243 V_4 ;
int V_12 ;
V_12 = F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_247 , V_64 ,
V_272 , & V_4 ) ;
if ( V_12 )
return V_12 ;
memcpy ( V_271 , & V_4 . V_273 [ 1 ] , V_4 . V_273 [ 0 ] ) ;
return V_4 . V_273 [ 0 ] ;
}
T_13 F_42 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , const T_4 * V_271 )
{
union V_243 V_4 ;
if ( V_77 > V_274 )
V_77 = V_274 ;
V_4 . V_273 [ 0 ] = V_77 ;
memcpy ( & V_4 . V_273 [ 1 ] , V_271 , V_77 ) ;
return F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_250 , V_64 ,
V_272 , & V_4 ) ;
}
T_13 F_253 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , T_4 * V_271 )
{
union V_243 V_4 ;
int V_12 ;
if ( V_77 > V_274 )
V_77 = V_274 ;
V_4 . V_273 [ 0 ] = V_77 ;
V_12 = F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_247 , V_64 ,
V_275 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
memcpy ( V_271 , & V_4 . V_273 [ 1 ] , V_4 . V_273 [ 0 ] ) ;
return V_4 . V_273 [ 0 ] ;
}
T_13 F_254 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , const T_4 * V_271 )
{
union V_243 V_4 ;
if ( V_77 > V_274 )
V_77 = V_274 ;
V_4 . V_273 [ 0 ] = V_77 ;
memcpy ( V_4 . V_273 + 1 , V_271 , V_77 ) ;
return F_241 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_250 , V_64 ,
V_275 , & V_4 ) ;
}
static T_13 F_255 ( struct V_28 * V_29 , T_8 V_13 ,
unsigned short V_23 ,
char V_276 , T_4 V_64 , int V_277 ,
union V_243 * V_4 )
{
unsigned char V_278 [ V_274 + 3 ] ;
unsigned char V_279 [ V_274 + 2 ] ;
int V_221 = V_276 == V_247 ? 2 : 1 ;
int V_116 ;
T_4 V_280 = 0 ;
int V_12 ;
struct V_55 V_219 [ 2 ] = {
{
. V_13 = V_13 ,
. V_23 = V_23 ,
. V_60 = 1 ,
. V_61 = V_278 ,
} , {
. V_13 = V_13 ,
. V_23 = V_23 | V_62 ,
. V_60 = 0 ,
. V_61 = V_279 ,
} ,
} ;
V_278 [ 0 ] = V_64 ;
switch ( V_277 ) {
case V_251 :
V_219 [ 0 ] . V_60 = 0 ;
V_219 [ 0 ] . V_23 = V_23 | ( V_276 == V_247 ?
V_62 : 0 ) ;
V_221 = 1 ;
break;
case V_253 :
if ( V_276 == V_247 ) {
V_219 [ 0 ] . V_23 = V_62 | V_23 ;
V_221 = 1 ;
}
break;
case V_248 :
if ( V_276 == V_247 )
V_219 [ 1 ] . V_60 = 1 ;
else {
V_219 [ 0 ] . V_60 = 2 ;
V_278 [ 1 ] = V_4 -> V_267 ;
}
break;
case V_269 :
if ( V_276 == V_247 )
V_219 [ 1 ] . V_60 = 2 ;
else {
V_219 [ 0 ] . V_60 = 3 ;
V_278 [ 1 ] = V_4 -> V_270 & 0xff ;
V_278 [ 2 ] = V_4 -> V_270 >> 8 ;
}
break;
case V_281 :
V_221 = 2 ;
V_276 = V_247 ;
V_219 [ 0 ] . V_60 = 3 ;
V_219 [ 1 ] . V_60 = 2 ;
V_278 [ 1 ] = V_4 -> V_270 & 0xff ;
V_278 [ 2 ] = V_4 -> V_270 >> 8 ;
break;
case V_272 :
if ( V_276 == V_247 ) {
V_219 [ 1 ] . V_23 |= V_241 ;
V_219 [ 1 ] . V_60 = 1 ;
} else {
V_219 [ 0 ] . V_60 = V_4 -> V_273 [ 0 ] + 2 ;
if ( V_219 [ 0 ] . V_60 > V_274 + 2 ) {
F_21 ( & V_29 -> V_40 ,
L_103 ,
V_4 -> V_273 [ 0 ] ) ;
return - V_128 ;
}
for ( V_116 = 1 ; V_116 < V_219 [ 0 ] . V_60 ; V_116 ++ )
V_278 [ V_116 ] = V_4 -> V_273 [ V_116 - 1 ] ;
}
break;
case V_282 :
V_221 = 2 ;
V_276 = V_247 ;
if ( V_4 -> V_273 [ 0 ] > V_274 ) {
F_21 ( & V_29 -> V_40 ,
L_103 ,
V_4 -> V_273 [ 0 ] ) ;
return - V_128 ;
}
V_219 [ 0 ] . V_60 = V_4 -> V_273 [ 0 ] + 2 ;
for ( V_116 = 1 ; V_116 < V_219 [ 0 ] . V_60 ; V_116 ++ )
V_278 [ V_116 ] = V_4 -> V_273 [ V_116 - 1 ] ;
V_219 [ 1 ] . V_23 |= V_241 ;
V_219 [ 1 ] . V_60 = 1 ;
break;
case V_275 :
if ( V_276 == V_247 ) {
V_219 [ 1 ] . V_60 = V_4 -> V_273 [ 0 ] ;
} else {
V_219 [ 0 ] . V_60 = V_4 -> V_273 [ 0 ] + 1 ;
if ( V_219 [ 0 ] . V_60 > V_274 + 1 ) {
F_21 ( & V_29 -> V_40 ,
L_103 ,
V_4 -> V_273 [ 0 ] ) ;
return - V_128 ;
}
for ( V_116 = 1 ; V_116 <= V_4 -> V_273 [ 0 ] ; V_116 ++ )
V_278 [ V_116 ] = V_4 -> V_273 [ V_116 ] ;
}
break;
default:
F_21 ( & V_29 -> V_40 , L_104 , V_277 ) ;
return - V_124 ;
}
V_116 = ( ( V_23 & V_283 ) && V_277 != V_251
&& V_277 != V_275 ) ;
if ( V_116 ) {
if ( ! ( V_219 [ 0 ] . V_23 & V_62 ) ) {
if ( V_221 == 1 )
F_251 ( & V_219 [ 0 ] ) ;
else
V_280 = F_250 ( 0 , & V_219 [ 0 ] ) ;
}
if ( V_219 [ V_221 - 1 ] . V_23 & V_62 )
V_219 [ V_221 - 1 ] . V_60 ++ ;
}
V_12 = F_29 ( V_29 , V_219 , V_221 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_116 && ( V_219 [ V_221 - 1 ] . V_23 & V_62 ) ) {
V_12 = F_252 ( V_280 , & V_219 [ V_221 - 1 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( V_276 == V_247 )
switch ( V_277 ) {
case V_253 :
V_4 -> V_267 = V_278 [ 0 ] ;
break;
case V_248 :
V_4 -> V_267 = V_279 [ 0 ] ;
break;
case V_269 :
case V_281 :
V_4 -> V_270 = V_279 [ 0 ] | ( V_279 [ 1 ] << 8 ) ;
break;
case V_275 :
for ( V_116 = 0 ; V_116 < V_4 -> V_273 [ 0 ] ; V_116 ++ )
V_4 -> V_273 [ V_116 + 1 ] = V_279 [ V_116 ] ;
break;
case V_272 :
case V_282 :
for ( V_116 = 0 ; V_116 < V_279 [ 0 ] + 1 ; V_116 ++ )
V_4 -> V_273 [ V_116 ] = V_279 [ V_116 ] ;
break;
}
return 0 ;
}
T_13 F_241 ( struct V_28 * V_29 , T_8 V_13 , unsigned short V_23 ,
char V_276 , T_4 V_64 , int V_284 ,
union V_243 * V_4 )
{
unsigned long V_236 ;
int V_237 ;
T_13 V_41 ;
F_256 ( V_29 , V_13 , V_23 , V_276 ,
V_64 , V_284 , V_4 ) ;
F_257 ( V_29 , V_13 , V_23 , V_276 ,
V_64 , V_284 ) ;
V_23 &= V_242 | V_283 | V_285 ;
if ( V_29 -> V_186 -> V_286 ) {
F_106 ( V_29 ) ;
V_236 = V_238 ;
for ( V_41 = 0 , V_237 = 0 ; V_237 <= V_29 -> V_239 ; V_237 ++ ) {
V_41 = V_29 -> V_186 -> V_286 ( V_29 , V_13 , V_23 ,
V_276 , V_64 ,
V_284 , V_4 ) ;
if ( V_41 != - V_184 )
break;
if ( F_230 ( V_238 ,
V_236 + V_29 -> V_187 ) )
break;
}
F_110 ( V_29 ) ;
if ( V_41 != - V_124 || ! V_29 -> V_186 -> V_240 )
goto V_287;
}
V_41 = F_255 ( V_29 , V_13 , V_23 , V_276 ,
V_64 , V_284 , V_4 ) ;
V_287:
F_258 ( V_29 , V_13 , V_23 , V_276 ,
V_64 , V_284 , V_4 ) ;
F_259 ( V_29 , V_13 , V_23 , V_276 ,
V_64 , V_284 , V_41 ) ;
return V_41 ;
}
T_13 F_260 ( const struct V_51 * V_52 ,
T_4 V_64 , T_4 V_77 , T_4 * V_271 )
{
T_4 V_116 = 0 ;
int V_12 ;
if ( V_77 > V_274 )
V_77 = V_274 ;
if ( F_240 ( V_52 -> V_29 , V_288 ) )
return F_253 ( V_52 , V_64 , V_77 , V_271 ) ;
if ( ! F_240 ( V_52 -> V_29 , V_246 ) )
return - V_124 ;
if ( F_240 ( V_52 -> V_29 , V_289 ) ) {
while ( ( V_116 + 2 ) <= V_77 ) {
V_12 = F_39 ( V_52 , V_64 + V_116 ) ;
if ( V_12 < 0 )
return V_12 ;
V_271 [ V_116 ] = V_12 & 0xff ;
V_271 [ V_116 + 1 ] = V_12 >> 8 ;
V_116 += 2 ;
}
}
while ( V_116 < V_77 ) {
V_12 = F_37 ( V_52 , V_64 + V_116 ) ;
if ( V_12 < 0 )
return V_12 ;
V_271 [ V_116 ] = V_12 ;
V_116 ++ ;
}
return V_116 ;
}
int F_261 ( struct V_51 * V_52 , T_14 V_290 )
{
int V_36 ;
if ( ! V_52 || ! V_290 ) {
F_262 ( 1 , L_105 ) ;
return - V_128 ;
}
if ( ! ( V_52 -> V_23 & V_142 ) )
F_26 ( & V_52 -> V_40 , L_106 ,
V_211 ) ;
if ( ! ( V_52 -> V_23 & V_24 ) ) {
V_36 = F_99 ( V_52 -> V_13 ) ;
if ( V_36 ) {
F_21 ( & V_52 -> V_40 , L_107 , V_211 ) ;
return V_36 ;
}
}
if ( ! V_52 -> V_29 -> V_186 -> V_291 ) {
F_21 ( & V_52 -> V_40 , L_108 , V_211 ) ;
return - V_124 ;
}
V_52 -> V_290 = V_290 ;
F_106 ( V_52 -> V_29 ) ;
V_36 = V_52 -> V_29 -> V_186 -> V_291 ( V_52 ) ;
F_110 ( V_52 -> V_29 ) ;
if ( V_36 ) {
V_52 -> V_290 = NULL ;
F_21 ( & V_52 -> V_40 , L_109 , V_211 , V_36 ) ;
}
return V_36 ;
}
int F_263 ( struct V_51 * V_52 )
{
int V_36 ;
if ( ! V_52 -> V_29 -> V_186 -> V_292 ) {
F_21 ( & V_52 -> V_40 , L_108 , V_211 ) ;
return - V_124 ;
}
F_106 ( V_52 -> V_29 ) ;
V_36 = V_52 -> V_29 -> V_186 -> V_292 ( V_52 ) ;
F_110 ( V_52 -> V_29 ) ;
if ( V_36 == 0 )
V_52 -> V_290 = NULL ;
else
F_21 ( & V_52 -> V_40 , L_109 , V_211 , V_36 ) ;
return V_36 ;
}
