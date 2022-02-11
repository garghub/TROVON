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
return F_62 ( V_103 , L_7 , V_105 , V_52 -> V_95 ) ;
}
static int F_63 ( struct V_28 * V_47 )
{
return F_64 ( V_47 -> V_106 -> V_107 ) ;
}
static void F_65 ( struct V_28 * V_47 , int V_108 )
{
F_66 ( V_47 -> V_106 -> V_107 , V_108 ) ;
}
static int F_67 ( struct V_28 * V_47 )
{
return F_64 ( V_47 -> V_106 -> V_109 ) ;
}
static int F_68 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
struct V_96 * V_40 = & V_47 -> V_40 ;
int V_36 = 0 ;
V_36 = F_69 ( V_111 -> V_107 , V_112 |
V_113 , L_8 ) ;
if ( V_36 ) {
F_26 ( V_40 , L_9 , V_111 -> V_107 ) ;
return V_36 ;
}
if ( V_111 -> V_114 ) {
if ( F_69 ( V_111 -> V_109 , V_115 , L_10 ) ) {
F_26 ( V_40 , L_11 ,
V_111 -> V_109 ) ;
V_111 -> V_114 = NULL ;
}
}
return V_36 ;
}
static void F_70 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
if ( V_111 -> V_114 )
F_71 ( V_111 -> V_109 ) ;
F_71 ( V_111 -> V_107 ) ;
}
static int F_72 ( struct V_28 * V_47 )
{
struct V_110 * V_111 = V_47 -> V_106 ;
int V_116 = 0 , V_108 = 1 , V_36 = 0 ;
if ( V_111 -> V_117 )
V_111 -> V_117 ( V_47 ) ;
V_111 -> V_118 ( V_47 , V_108 ) ;
F_73 ( V_119 ) ;
while ( V_116 ++ < V_120 * 2 ) {
if ( V_108 ) {
if ( V_111 -> V_114 && V_111 -> V_114 ( V_47 ) )
break;
if ( ! V_111 -> V_121 ( V_47 ) ) {
F_21 ( & V_47 -> V_40 ,
L_12 ) ;
V_36 = - V_122 ;
break;
}
}
V_108 = ! V_108 ;
V_111 -> V_118 ( V_47 , V_108 ) ;
F_73 ( V_119 ) ;
}
if ( V_111 -> V_123 )
V_111 -> V_123 ( V_47 ) ;
return V_36 ;
}
int F_74 ( struct V_28 * V_47 )
{
return F_72 ( V_47 ) ;
}
int F_75 ( struct V_28 * V_47 )
{
int V_36 ;
V_36 = F_68 ( V_47 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_72 ( V_47 ) ;
F_70 ( V_47 ) ;
return V_36 ;
}
int F_76 ( struct V_28 * V_47 )
{
if ( ! V_47 -> V_106 )
return - V_124 ;
F_77 ( & V_47 -> V_40 , L_13 ) ;
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
V_43 = F_79 ( V_40 -> V_127 , L_14 ) ;
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
V_133 = F_79 ( V_40 -> V_127 , L_15 ) ;
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
F_26 ( & V_52 -> V_40 , L_16 ) ;
}
F_77 ( V_40 , L_17 ) ;
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
F_77 ( V_40 , L_18 ) ;
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
return sprintf ( V_61 , L_19 , V_40 -> type == & V_139 ?
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
return sprintf ( V_61 , L_20 , V_105 , V_52 -> V_95 ) ;
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
static void F_106 ( struct V_28 * V_29 ,
unsigned int V_23 )
{
F_107 ( & V_29 -> V_147 ) ;
}
static int F_108 ( struct V_28 * V_29 ,
unsigned int V_23 )
{
return F_109 ( & V_29 -> V_147 ) ;
}
static void F_110 ( struct V_28 * V_29 ,
unsigned int V_23 )
{
F_111 ( & V_29 -> V_147 ) ;
}
static void F_112 ( struct V_28 * V_47 ,
struct V_51 * V_52 )
{
struct V_34 * V_35 = F_81 ( & V_52 -> V_40 ) ;
if ( V_35 ) {
F_113 ( & V_52 -> V_40 , L_21 , F_114 ( V_35 ) ) ;
return;
}
F_113 ( & V_52 -> V_40 , L_22 , F_115 ( V_47 ) ,
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
F_21 ( & V_47 -> V_40 , L_23 ,
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
F_77 ( & V_47 -> V_40 , L_24 ,
V_52 -> V_95 , F_19 ( & V_52 -> V_40 ) ) ;
return V_52 ;
V_151:
F_21 ( & V_47 -> V_40 , L_25
L_26 , V_52 -> V_95 , V_52 -> V_13 , V_12 ) ;
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
F_123 ( L_27 , V_155 ) ,
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
F_21 ( V_40 , L_28 , L_29 ) ;
return - V_128 ;
}
if ( V_159 - V_61 > V_161 - 1 ) {
F_21 ( V_40 , L_30 , L_29 ) ;
return - V_128 ;
}
memcpy ( V_8 . type , V_61 , V_159 - V_61 ) ;
V_41 = sscanf ( ++ V_159 , L_31 , & V_8 . V_13 , & V_160 ) ;
if ( V_41 < 1 ) {
F_21 ( V_40 , L_32 , L_29 ) ;
return - V_128 ;
}
if ( V_41 > 1 && V_160 != '\n' ) {
F_21 ( V_40 , L_33 , L_29 ) ;
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
F_131 ( V_40 , L_34 , L_29 ,
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
V_41 = sscanf ( V_61 , L_31 , & V_13 , & V_160 ) ;
if ( V_41 < 1 ) {
F_21 ( V_40 , L_32 , L_35 ) ;
return - V_128 ;
}
if ( V_41 > 1 && V_160 != '\n' ) {
F_21 ( V_40 , L_33 , L_35 ) ;
return - V_128 ;
}
V_41 = - V_126 ;
F_133 ( & V_47 -> V_162 ,
F_126 ( V_47 ) ) ;
F_134 (client, next, &adap->userspace_clients,
detected) {
if ( F_97 ( V_52 ) == V_13 ) {
F_131 ( V_40 , L_36 ,
L_35 , V_52 -> V_95 , V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
V_41 = V_158 ;
break;
}
}
F_130 ( & V_47 -> V_162 ) ;
if ( V_41 < 0 )
F_21 ( V_40 , L_37 ,
L_35 ) ;
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
L_38 ,
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
F_77 ( & V_47 -> V_40 , L_39 , V_173 -> V_177 ) ;
if ( F_142 ( V_173 , V_8 . type , sizeof( V_8 . type ) ) < 0 ) {
F_21 ( & V_47 -> V_40 , L_40 ,
V_173 -> V_177 ) ;
return F_143 ( - V_128 ) ;
}
V_176 = F_144 ( V_173 , L_41 , & V_60 ) ;
if ( ! V_176 || ( V_60 < sizeof( * V_176 ) ) ) {
F_21 ( & V_47 -> V_40 , L_42 ,
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
F_21 ( & V_47 -> V_40 , L_43 ,
V_8 . V_13 , V_173 -> V_177 ) ;
return F_143 ( - V_128 ) ;
}
V_8 . V_13 = V_13 ;
V_8 . V_127 = F_146 ( V_173 ) ;
V_8 . V_149 = & V_175 ;
if ( F_144 ( V_173 , L_44 , NULL ) )
V_8 . V_23 |= V_132 ;
V_145 = F_20 ( V_47 , & V_8 ) ;
if ( V_145 == NULL ) {
F_21 ( & V_47 -> V_40 , L_45 ,
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
F_77 ( & V_47 -> V_40 , L_46 ) ;
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
F_26 ( & V_47 -> V_40 , L_47 ,
V_100 -> V_100 . V_95 ) ;
F_26 ( & V_47 -> V_40 , L_48
L_49 ) ;
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
if ( F_162 ( ! V_183 ) ) {
V_41 = - V_184 ;
goto V_185;
}
if ( F_163 ( V_47 -> V_95 [ 0 ] == '\0' ) ) {
F_164 ( L_50
L_51 ) ;
return - V_128 ;
}
if ( F_163 ( ! V_47 -> V_186 ) ) {
F_164 ( L_52
L_53 , V_47 -> V_95 ) ;
return - V_128 ;
}
if ( ! V_47 -> V_187 ) {
V_47 -> V_187 = F_106 ;
V_47 -> V_188 = F_108 ;
V_47 -> V_189 = F_110 ;
}
F_165 ( & V_47 -> V_147 ) ;
F_165 ( & V_47 -> V_190 ) ;
F_166 ( & V_47 -> V_162 ) ;
F_13 ( & V_47 -> V_164 ) ;
if ( V_47 -> V_191 == 0 )
V_47 -> V_191 = V_192 ;
F_113 ( & V_47 -> V_40 , L_54 , V_47 -> V_170 ) ;
V_47 -> V_40 . V_152 = & V_153 ;
V_47 -> V_40 . type = & V_146 ;
V_41 = F_116 ( & V_47 -> V_40 ) ;
if ( V_41 )
goto V_185;
F_77 ( & V_47 -> V_40 , L_55 , V_47 -> V_95 ) ;
F_167 ( & V_47 -> V_40 ) ;
F_168 ( & V_47 -> V_40 , true ) ;
F_169 ( & V_47 -> V_40 ) ;
#ifdef F_170
V_41 = F_171 ( V_193 , & V_47 -> V_40 ,
V_47 -> V_40 . V_89 ) ;
if ( V_41 )
F_26 ( & V_47 -> V_40 ,
L_56 ) ;
#endif
if ( V_47 -> V_106 ) {
struct V_110 * V_111 = V_47 -> V_106 ;
if ( ! V_111 -> V_125 ) {
F_21 ( & V_47 -> V_40 , L_57 ) ;
V_47 -> V_106 = NULL ;
goto V_194;
}
if ( V_111 -> V_125 == F_75 ) {
if ( ! F_172 ( V_111 -> V_107 ) ) {
F_21 ( & V_47 -> V_40 , L_58 ) ;
V_47 -> V_106 = NULL ;
goto V_194;
}
if ( F_172 ( V_111 -> V_109 ) )
V_111 -> V_114 = F_67 ;
else
V_111 -> V_114 = NULL ;
V_111 -> V_121 = F_63 ;
V_111 -> V_118 = F_65 ;
} else if ( V_111 -> V_125 == F_74 ) {
if ( ! V_111 -> V_118 || ! V_111 -> V_121 ) {
F_21 ( & V_47 -> V_40 , L_59 ) ;
V_47 -> V_106 = NULL ;
}
}
}
V_194:
F_148 ( V_47 ) ;
F_22 ( V_47 ) ;
F_45 ( V_47 ) ;
if ( V_47 -> V_170 < V_195 )
F_137 ( V_47 ) ;
F_128 ( & V_196 ) ;
F_173 ( & V_153 , NULL , V_47 , F_160 ) ;
F_130 ( & V_196 ) ;
return 0 ;
V_185:
F_128 ( & V_196 ) ;
F_174 ( & V_197 , V_47 -> V_170 ) ;
F_130 ( & V_196 ) ;
return V_41 ;
}
static int F_175 ( struct V_28 * V_47 )
{
int V_94 ;
F_128 ( & V_196 ) ;
V_94 = F_176 ( & V_197 , V_47 , V_47 -> V_170 , V_47 -> V_170 + 1 ,
V_58 ) ;
F_130 ( & V_196 ) ;
if ( V_94 < 0 )
return V_94 == - V_198 ? - V_122 : V_94 ;
return F_161 ( V_47 ) ;
}
int F_177 ( struct V_28 * V_29 )
{
struct V_96 * V_40 = & V_29 -> V_40 ;
int V_94 ;
if ( V_40 -> V_127 ) {
V_94 = F_178 ( V_40 -> V_127 , L_60 ) ;
if ( V_94 >= 0 ) {
V_29 -> V_170 = V_94 ;
return F_175 ( V_29 ) ;
}
}
F_128 ( & V_196 ) ;
V_94 = F_176 ( & V_197 , V_29 ,
V_195 , 0 , V_58 ) ;
F_130 ( & V_196 ) ;
if ( V_94 < 0 )
return V_94 ;
V_29 -> V_170 = V_94 ;
return F_161 ( V_29 ) ;
}
int F_179 ( struct V_28 * V_47 )
{
if ( V_47 -> V_170 == - 1 )
return F_177 ( V_47 ) ;
return F_175 ( V_47 ) ;
}
static void F_180 ( struct V_99 * V_100 ,
struct V_28 * V_29 )
{
struct V_51 * V_52 , * V_199 ;
F_134 (client, _n, &driver->clients, detected) {
if ( V_52 -> V_29 == V_29 ) {
F_77 ( & V_29 -> V_40 , L_61 ,
V_52 -> V_95 , V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
}
}
}
static int F_181 ( struct V_96 * V_40 , void * V_200 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
if ( V_52 && strcmp ( V_52 -> V_95 , L_27 ) )
F_117 ( V_52 ) ;
return 0 ;
}
static int F_182 ( struct V_96 * V_40 , void * V_200 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
if ( V_52 )
F_117 ( V_52 ) ;
return 0 ;
}
static int F_183 ( struct V_97 * V_182 , void * V_4 )
{
F_180 ( F_58 ( V_182 ) , V_4 ) ;
return 0 ;
}
void F_184 ( struct V_28 * V_47 )
{
struct V_28 * V_201 ;
struct V_51 * V_52 , * V_165 ;
F_128 ( & V_196 ) ;
V_201 = F_185 ( & V_197 , V_47 -> V_170 ) ;
F_130 ( & V_196 ) ;
if ( V_201 != V_47 ) {
F_186 ( L_62
L_63 , V_47 -> V_95 ) ;
return;
}
F_50 ( V_47 ) ;
F_128 ( & V_196 ) ;
F_173 ( & V_153 , NULL , V_47 ,
F_183 ) ;
F_130 ( & V_196 ) ;
F_133 ( & V_47 -> V_162 ,
F_126 ( V_47 ) ) ;
F_134 (client, next, &adap->userspace_clients,
detected) {
F_77 ( & V_47 -> V_40 , L_61 , V_52 -> V_95 ,
V_52 -> V_13 ) ;
F_135 ( & V_52 -> V_163 ) ;
F_117 ( V_52 ) ;
}
F_130 ( & V_47 -> V_162 ) ;
F_103 ( & V_47 -> V_40 , NULL , F_181 ) ;
F_103 ( & V_47 -> V_40 , NULL , F_182 ) ;
#ifdef F_170
F_187 ( V_193 , & V_47 -> V_40 ,
V_47 -> V_40 . V_89 ) ;
#endif
F_77 ( & V_47 -> V_40 , L_64 , V_47 -> V_95 ) ;
F_188 ( & V_47 -> V_40 ) ;
F_189 ( & V_47 -> V_156 ) ;
F_119 ( & V_47 -> V_40 ) ;
F_190 ( & V_47 -> V_156 ) ;
F_128 ( & V_196 ) ;
F_174 ( & V_197 , V_47 -> V_170 ) ;
F_130 ( & V_196 ) ;
memset ( & V_47 -> V_40 , 0 , sizeof( V_47 -> V_40 ) ) ;
}
void F_191 ( struct V_96 * V_40 , struct V_202 * V_203 , bool V_204 )
{
int V_36 ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_36 = F_192 ( V_40 , L_65 , & V_203 -> V_205 ) ;
if ( V_36 && V_204 )
V_203 -> V_205 = 100000 ;
V_36 = F_192 ( V_40 , L_66 , & V_203 -> V_206 ) ;
if ( V_36 && V_204 ) {
if ( V_203 -> V_205 <= 100000 )
V_203 -> V_206 = 1000 ;
else if ( V_203 -> V_205 <= 400000 )
V_203 -> V_206 = 300 ;
else
V_203 -> V_206 = 120 ;
}
V_36 = F_192 ( V_40 , L_67 , & V_203 -> V_207 ) ;
if ( V_36 && V_204 ) {
if ( V_203 -> V_205 <= 400000 )
V_203 -> V_207 = 300 ;
else
V_203 -> V_207 = 120 ;
}
F_192 ( V_40 , L_68 , & V_203 -> V_208 ) ;
V_36 = F_192 ( V_40 , L_69 , & V_203 -> V_209 ) ;
if ( V_36 && V_204 )
V_203 -> V_209 = V_203 -> V_207 ;
}
int F_193 ( void * V_4 , int (* F_194)( struct V_96 * , void * ) )
{
int V_41 ;
F_128 ( & V_196 ) ;
V_41 = F_195 ( & V_153 , NULL , V_4 , F_194 ) ;
F_130 ( & V_196 ) ;
return V_41 ;
}
static int F_196 ( struct V_96 * V_40 , void * V_4 )
{
if ( V_40 -> type != & V_146 )
return 0 ;
return F_158 ( V_4 , F_94 ( V_40 ) ) ;
}
int F_197 ( struct V_210 * V_180 , struct V_99 * V_100 )
{
int V_41 ;
if ( F_162 ( ! V_183 ) )
return - V_184 ;
V_100 -> V_100 . V_180 = V_180 ;
V_100 -> V_100 . V_152 = & V_153 ;
V_41 = F_198 ( & V_100 -> V_100 ) ;
if ( V_41 )
return V_41 ;
F_186 ( L_70 , V_100 -> V_100 . V_95 ) ;
F_13 ( & V_100 -> V_211 ) ;
F_193 ( V_100 , F_196 ) ;
return 0 ;
}
static int F_199 ( struct V_96 * V_40 , void * V_4 )
{
if ( V_40 -> type == & V_146 )
F_180 ( V_4 , F_94 ( V_40 ) ) ;
return 0 ;
}
void F_200 ( struct V_99 * V_100 )
{
F_193 ( V_100 , F_199 ) ;
F_201 ( & V_100 -> V_100 ) ;
F_186 ( L_71 , V_100 -> V_100 . V_95 ) ;
}
struct V_51 * F_202 ( struct V_51 * V_52 )
{
if ( V_52 && F_203 ( & V_52 -> V_40 ) )
return V_52 ;
return NULL ;
}
void F_204 ( struct V_51 * V_52 )
{
if ( V_52 )
F_154 ( & V_52 -> V_40 ) ;
}
static int F_205 ( struct V_96 * V_40 , void * V_212 )
{
struct V_51 * V_52 = F_55 ( V_40 ) ;
struct V_213 * V_214 = V_212 ;
struct V_99 * V_100 ;
if ( ! V_52 || ! V_52 -> V_40 . V_100 )
return 0 ;
V_100 = F_58 ( V_52 -> V_40 . V_100 ) ;
if ( V_100 -> V_64 )
V_100 -> V_64 ( V_52 , V_214 -> V_53 , V_214 -> V_214 ) ;
return 0 ;
}
void F_206 ( struct V_28 * V_47 , unsigned int V_53 , void * V_214 )
{
struct V_213 V_215 ;
V_215 . V_53 = V_53 ;
V_215 . V_214 = V_214 ;
F_103 ( & V_47 -> V_40 , & V_215 , F_205 ) ;
}
static int F_207 ( struct V_216 * V_217 , unsigned long V_74 ,
void * V_214 )
{
struct V_218 * V_219 = V_214 ;
struct V_28 * V_47 ;
struct V_51 * V_52 ;
switch ( F_208 ( V_74 , V_219 ) ) {
case V_220 :
V_47 = F_155 ( V_219 -> V_221 -> V_89 ) ;
if ( V_47 == NULL )
return V_222 ;
if ( F_150 ( V_219 -> V_221 , V_154 ) ) {
F_154 ( & V_47 -> V_40 ) ;
return V_222 ;
}
V_52 = F_141 ( V_47 , V_219 -> V_221 ) ;
F_154 ( & V_47 -> V_40 ) ;
if ( F_209 ( V_52 ) ) {
F_164 ( L_72 ,
V_223 , V_219 -> V_221 -> V_177 ) ;
return F_210 ( F_211 ( V_52 ) ) ;
}
break;
case V_224 :
if ( ! F_212 ( V_219 -> V_221 , V_154 ) )
return V_222 ;
V_52 = F_152 ( V_219 -> V_221 ) ;
if ( V_52 == NULL )
return V_222 ;
F_117 ( V_52 ) ;
F_154 ( & V_52 -> V_40 ) ;
break;
}
return V_222 ;
}
static int T_11 F_213 ( void )
{
int V_225 ;
V_225 = F_214 ( L_60 ) ;
F_215 ( & V_168 ) ;
if ( V_225 >= V_195 )
V_195 = V_225 + 1 ;
F_216 ( & V_168 ) ;
V_225 = F_217 ( & V_153 ) ;
if ( V_225 )
return V_225 ;
V_183 = true ;
#ifdef F_170
V_193 = F_218 ( L_73 ) ;
if ( ! V_193 ) {
V_225 = - V_91 ;
goto V_226;
}
#endif
V_225 = F_219 ( & V_227 ) ;
if ( V_225 )
goto V_228;
if ( F_220 ( V_229 ) )
F_162 ( F_221 ( & V_230 ) ) ;
return 0 ;
V_228:
#ifdef F_170
F_222 ( V_193 ) ;
V_226:
#endif
V_183 = false ;
F_223 ( & V_153 ) ;
return V_225 ;
}
static void T_12 F_224 ( void )
{
if ( F_220 ( V_229 ) )
F_162 ( F_225 ( & V_230 ) ) ;
F_200 ( & V_227 ) ;
#ifdef F_170
F_222 ( V_193 ) ;
#endif
F_223 ( & V_153 ) ;
F_226 () ;
}
static int F_227 ( struct V_28 * V_47 , struct V_55 * V_231 , char * V_232 )
{
F_228 ( & V_47 -> V_40 , L_74 ,
V_232 , V_231 -> V_13 , V_231 -> V_60 ,
V_231 -> V_23 & V_62 ? L_75 : L_76 ) ;
return - V_124 ;
}
static int F_229 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_233 )
{
const struct V_234 * V_235 = V_47 -> V_236 ;
int V_237 = V_235 -> V_238 , V_116 ;
bool V_239 = true ;
if ( V_235 -> V_23 & V_240 ) {
V_237 = 2 ;
if ( V_233 == 2 ) {
if ( V_235 -> V_23 & V_241 && V_56 [ 0 ] . V_23 & V_62 )
return F_227 ( V_47 , & V_56 [ 0 ] , L_77 ) ;
if ( V_235 -> V_23 & V_242 && ! ( V_56 [ 1 ] . V_23 & V_62 ) )
return F_227 ( V_47 , & V_56 [ 1 ] , L_78 ) ;
if ( V_235 -> V_23 & V_243 && V_56 [ 0 ] . V_13 != V_56 [ 1 ] . V_13 )
return F_227 ( V_47 , & V_56 [ 0 ] , L_79 ) ;
if ( F_230 ( V_56 [ 0 ] . V_60 , V_235 -> V_244 ) )
return F_227 ( V_47 , & V_56 [ 0 ] , L_80 ) ;
if ( F_230 ( V_56 [ 1 ] . V_60 , V_235 -> V_245 ) )
return F_227 ( V_47 , & V_56 [ 1 ] , L_80 ) ;
V_239 = false ;
}
}
if ( F_230 ( V_233 , V_237 ) )
return F_227 ( V_47 , & V_56 [ 0 ] , L_81 ) ;
for ( V_116 = 0 ; V_116 < V_233 ; V_116 ++ ) {
T_8 V_60 = V_56 [ V_116 ] . V_60 ;
if ( V_56 [ V_116 ] . V_23 & V_62 ) {
if ( V_239 && F_230 ( V_60 , V_235 -> V_246 ) )
return F_227 ( V_47 , & V_56 [ V_116 ] , L_80 ) ;
} else {
if ( V_239 && F_230 ( V_60 , V_235 -> V_247 ) )
return F_227 ( V_47 , & V_56 [ V_116 ] , L_80 ) ;
}
}
return 0 ;
}
int F_231 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_233 )
{
unsigned long V_248 ;
int V_36 , V_249 ;
if ( V_47 -> V_236 && F_229 ( V_47 , V_56 , V_233 ) )
return - V_124 ;
if ( F_232 ( & V_1 ) ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_233 ; V_116 ++ )
if ( V_56 [ V_116 ] . V_23 & V_62 )
F_233 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
else
F_234 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
}
V_248 = V_250 ;
for ( V_36 = 0 , V_249 = 0 ; V_249 <= V_47 -> V_251 ; V_249 ++ ) {
V_36 = V_47 -> V_186 -> V_252 ( V_47 , V_56 , V_233 ) ;
if ( V_36 != - V_184 )
break;
if ( F_235 ( V_250 , V_248 + V_47 -> V_191 ) )
break;
}
if ( F_232 ( & V_1 ) ) {
int V_116 ;
for ( V_116 = 0 ; V_116 < V_36 ; V_116 ++ )
if ( V_56 [ V_116 ] . V_23 & V_62 )
F_236 ( V_47 , & V_56 [ V_116 ] , V_116 ) ;
F_237 ( V_47 , V_116 , V_36 ) ;
}
return V_36 ;
}
int F_29 ( struct V_28 * V_47 , struct V_55 * V_56 , int V_233 )
{
int V_36 ;
if ( V_47 -> V_186 -> V_252 ) {
#ifdef F_238
for ( V_36 = 0 ; V_36 < V_233 ; V_36 ++ ) {
F_77 ( & V_47 -> V_40 , L_82
L_83 , V_36 , ( V_56 [ V_36 ] . V_23 & V_62 )
? 'R' : 'W' , V_56 [ V_36 ] . V_13 , V_56 [ V_36 ] . V_60 ,
( V_56 [ V_36 ] . V_23 & V_253 ) ? L_84 : L_85 ) ;
}
#endif
if ( F_239 () || F_240 () ) {
V_36 = V_47 -> V_188 ( V_47 , V_254 ) ;
if ( ! V_36 )
return - V_184 ;
} else {
F_241 ( V_47 , V_254 ) ;
}
V_36 = F_231 ( V_47 , V_56 , V_233 ) ;
F_242 ( V_47 , V_254 ) ;
return V_36 ;
} else {
F_77 ( & V_47 -> V_40 , L_86 ) ;
return - V_124 ;
}
}
int F_243 ( const struct V_51 * V_52 , const char * V_61 , int V_158 )
{
int V_36 ;
struct V_28 * V_47 = V_52 -> V_29 ;
struct V_55 V_231 ;
V_231 . V_13 = V_52 -> V_13 ;
V_231 . V_23 = V_52 -> V_23 & V_255 ;
V_231 . V_60 = V_158 ;
V_231 . V_61 = ( char * ) V_61 ;
V_36 = F_29 ( V_47 , & V_231 , 1 ) ;
return ( V_36 == 1 ) ? V_158 : V_36 ;
}
int F_244 ( const struct V_51 * V_52 , char * V_61 , int V_158 )
{
struct V_28 * V_47 = V_52 -> V_29 ;
struct V_55 V_231 ;
int V_36 ;
V_231 . V_13 = V_52 -> V_13 ;
V_231 . V_23 = V_52 -> V_23 & V_255 ;
V_231 . V_23 |= V_62 ;
V_231 . V_60 = V_158 ;
V_231 . V_61 = V_61 ;
V_36 = F_29 ( V_47 , & V_231 , 1 ) ;
return ( V_36 == 1 ) ? V_158 : V_36 ;
}
static int F_245 ( struct V_28 * V_47 , unsigned short V_13 )
{
int V_78 ;
union V_256 V_200 ;
#ifdef F_246
if ( V_13 == 0x73 && ( V_47 -> V_257 & V_258 )
&& F_247 ( V_47 , V_259 ) )
V_78 = F_248 ( V_47 , V_13 , 0 , V_260 , 0 ,
V_261 , & V_200 ) ;
else
#endif
if ( ! ( ( V_13 & ~ 0x07 ) == 0x30 || ( V_13 & ~ 0x0f ) == 0x50 )
&& F_247 ( V_47 , V_262 ) )
V_78 = F_248 ( V_47 , V_13 , 0 , V_263 , 0 ,
V_264 , NULL ) ;
else if ( F_247 ( V_47 , V_265 ) )
V_78 = F_248 ( V_47 , V_13 , 0 , V_260 , 0 ,
V_266 , & V_200 ) ;
else {
F_26 ( & V_47 -> V_40 , L_87 ,
V_13 ) ;
V_78 = - V_124 ;
}
return V_78 >= 0 ;
}
static int F_249 ( struct V_51 * V_267 ,
struct V_99 * V_100 )
{
struct V_7 V_8 ;
struct V_28 * V_29 = V_267 -> V_29 ;
int V_13 = V_267 -> V_13 ;
int V_78 ;
V_78 = F_99 ( V_13 ) ;
if ( V_78 ) {
F_26 ( & V_29 -> V_40 , L_88 ,
V_13 ) ;
return V_78 ;
}
if ( F_105 ( V_29 , V_13 ) )
return 0 ;
if ( ! F_245 ( V_29 , V_13 ) )
return 0 ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 . V_13 = V_13 ;
V_78 = V_100 -> V_268 ( V_267 , & V_8 ) ;
if ( V_78 ) {
return V_78 == - V_90 ? 0 : V_78 ;
}
if ( V_8 . type [ 0 ] == '\0' ) {
F_21 ( & V_29 -> V_40 , L_89
L_90 , V_100 -> V_100 . V_95 ,
V_13 ) ;
} else {
struct V_51 * V_52 ;
if ( V_29 -> V_257 & V_269 )
F_26 ( & V_29 -> V_40 ,
L_91
L_92
L_93 ,
V_8 . V_13 ) ;
F_77 ( & V_29 -> V_40 , L_94 ,
V_8 . type , V_8 . V_13 ) ;
V_52 = F_20 ( V_29 , & V_8 ) ;
if ( V_52 )
F_129 ( & V_52 -> V_163 , & V_100 -> V_211 ) ;
else
F_21 ( & V_29 -> V_40 , L_95 ,
V_8 . type , V_8 . V_13 ) ;
}
return 0 ;
}
static int F_159 ( struct V_28 * V_29 , struct V_99 * V_100 )
{
const unsigned short * V_270 ;
struct V_51 * V_267 ;
int V_116 , V_78 = 0 ;
int V_271 = F_115 ( V_29 ) ;
V_270 = V_100 -> V_270 ;
if ( ! V_100 -> V_268 || ! V_270 )
return 0 ;
if ( V_29 -> V_257 == V_269 ) {
F_77 ( & V_29 -> V_40 ,
L_96
L_97
L_98 ,
V_100 -> V_100 . V_95 ) ;
return 0 ;
}
if ( ! ( V_29 -> V_257 & V_100 -> V_257 ) )
return 0 ;
V_267 = F_28 ( sizeof( struct V_51 ) , V_58 ) ;
if ( ! V_267 )
return - V_91 ;
V_267 -> V_29 = V_29 ;
for ( V_116 = 0 ; V_270 [ V_116 ] != V_272 ; V_116 += 1 ) {
F_77 ( & V_29 -> V_40 , L_99
L_100 , V_271 , V_270 [ V_116 ] ) ;
V_267 -> V_13 = V_270 [ V_116 ] ;
V_78 = F_249 ( V_267 , V_100 ) ;
if ( F_163 ( V_78 ) )
break;
}
F_31 ( V_267 ) ;
return V_78 ;
}
int F_250 ( struct V_28 * V_47 , unsigned short V_13 )
{
return F_248 ( V_47 , V_13 , 0 , V_260 , 0 ,
V_264 , NULL ) >= 0 ;
}
struct V_51 *
F_251 ( struct V_28 * V_47 ,
struct V_7 * V_8 ,
unsigned short const * V_273 ,
int (* V_131)( struct V_28 * , unsigned short V_13 ) )
{
int V_116 ;
if ( ! V_131 )
V_131 = F_245 ;
for ( V_116 = 0 ; V_273 [ V_116 ] != V_272 ; V_116 ++ ) {
if ( F_99 ( V_273 [ V_116 ] ) < 0 ) {
F_26 ( & V_47 -> V_40 , L_101
L_102 , V_273 [ V_116 ] ) ;
continue;
}
if ( F_105 ( V_47 , V_273 [ V_116 ] ) ) {
F_77 ( & V_47 -> V_40 , L_103
L_104 , V_273 [ V_116 ] ) ;
continue;
}
if ( V_131 ( V_47 , V_273 [ V_116 ] ) )
break;
}
if ( V_273 [ V_116 ] == V_272 ) {
F_77 ( & V_47 -> V_40 , L_105 ) ;
return NULL ;
}
V_8 -> V_13 = V_273 [ V_116 ] ;
return F_20 ( V_47 , V_8 ) ;
}
struct V_28 * F_252 ( int V_170 )
{
struct V_28 * V_29 ;
F_128 ( & V_196 ) ;
V_29 = F_185 ( & V_197 , V_170 ) ;
if ( ! V_29 )
goto exit;
if ( F_157 ( V_29 -> V_180 ) )
F_203 ( & V_29 -> V_40 ) ;
else
V_29 = NULL ;
exit:
F_130 ( & V_196 ) ;
return V_29 ;
}
void F_253 ( struct V_28 * V_47 )
{
if ( ! V_47 )
return;
F_154 ( & V_47 -> V_40 ) ;
F_254 ( V_47 -> V_180 ) ;
}
static T_4 F_255 ( T_8 V_4 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < 8 ; V_116 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_274 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_256 ( T_4 V_275 , T_4 * V_276 , T_9 V_158 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_158 ; V_116 ++ )
V_275 = F_255 ( ( V_275 ^ V_276 [ V_116 ] ) << 8 ) ;
return V_275 ;
}
static T_4 F_257 ( T_4 V_277 , struct V_55 * V_231 )
{
T_4 V_13 = F_258 ( V_231 ) ;
V_277 = F_256 ( V_277 , & V_13 , 1 ) ;
return F_256 ( V_277 , V_231 -> V_61 , V_231 -> V_60 ) ;
}
static inline void F_259 ( struct V_55 * V_231 )
{
V_231 -> V_61 [ V_231 -> V_60 ] = F_257 ( 0 , V_231 ) ;
V_231 -> V_60 ++ ;
}
static int F_260 ( T_4 V_278 , struct V_55 * V_231 )
{
T_4 V_279 = V_231 -> V_61 [ -- V_231 -> V_60 ] ;
V_278 = F_257 ( V_278 , V_231 ) ;
if ( V_279 != V_278 ) {
F_186 ( L_106 ,
V_279 , V_278 ) ;
return - V_280 ;
}
return 0 ;
}
T_13 F_35 ( const struct V_51 * V_52 )
{
union V_256 V_4 ;
int V_12 ;
V_12 = F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_260 , 0 ,
V_266 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_281 ;
}
T_13 F_36 ( const struct V_51 * V_52 , T_4 V_282 )
{
return F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_263 , V_282 , V_266 , NULL ) ;
}
T_13 F_37 ( const struct V_51 * V_52 , T_4 V_64 )
{
union V_256 V_4 ;
int V_12 ;
V_12 = F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_260 , V_64 ,
V_261 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_281 ;
}
T_13 F_38 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_282 )
{
union V_256 V_4 ;
V_4 . V_281 = V_282 ;
return F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_263 , V_64 ,
V_261 , & V_4 ) ;
}
T_13 F_39 ( const struct V_51 * V_52 , T_4 V_64 )
{
union V_256 V_4 ;
int V_12 ;
V_12 = F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_260 , V_64 ,
V_283 , & V_4 ) ;
return ( V_12 < 0 ) ? V_12 : V_4 . V_284 ;
}
T_13 F_40 ( const struct V_51 * V_52 , T_4 V_64 ,
T_8 V_282 )
{
union V_256 V_4 ;
V_4 . V_284 = V_282 ;
return F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_263 , V_64 ,
V_283 , & V_4 ) ;
}
T_13 F_41 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 * V_285 )
{
union V_256 V_4 ;
int V_12 ;
V_12 = F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_260 , V_64 ,
V_286 , & V_4 ) ;
if ( V_12 )
return V_12 ;
memcpy ( V_285 , & V_4 . V_287 [ 1 ] , V_4 . V_287 [ 0 ] ) ;
return V_4 . V_287 [ 0 ] ;
}
T_13 F_42 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , const T_4 * V_285 )
{
union V_256 V_4 ;
if ( V_77 > V_288 )
V_77 = V_288 ;
V_4 . V_287 [ 0 ] = V_77 ;
memcpy ( & V_4 . V_287 [ 1 ] , V_285 , V_77 ) ;
return F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_263 , V_64 ,
V_286 , & V_4 ) ;
}
T_13 F_261 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , T_4 * V_285 )
{
union V_256 V_4 ;
int V_12 ;
if ( V_77 > V_288 )
V_77 = V_288 ;
V_4 . V_287 [ 0 ] = V_77 ;
V_12 = F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_260 , V_64 ,
V_289 , & V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
memcpy ( V_285 , & V_4 . V_287 [ 1 ] , V_4 . V_287 [ 0 ] ) ;
return V_4 . V_287 [ 0 ] ;
}
T_13 F_262 ( const struct V_51 * V_52 , T_4 V_64 ,
T_4 V_77 , const T_4 * V_285 )
{
union V_256 V_4 ;
if ( V_77 > V_288 )
V_77 = V_288 ;
V_4 . V_287 [ 0 ] = V_77 ;
memcpy ( V_4 . V_287 + 1 , V_285 , V_77 ) ;
return F_248 ( V_52 -> V_29 , V_52 -> V_13 , V_52 -> V_23 ,
V_263 , V_64 ,
V_289 , & V_4 ) ;
}
static T_13 F_263 ( struct V_28 * V_29 , T_8 V_13 ,
unsigned short V_23 ,
char V_290 , T_4 V_64 , int V_291 ,
union V_256 * V_4 )
{
unsigned char V_292 [ V_288 + 3 ] ;
unsigned char V_293 [ V_288 + 2 ] ;
int V_233 = V_290 == V_260 ? 2 : 1 ;
int V_116 ;
T_4 V_294 = 0 ;
int V_12 ;
struct V_55 V_231 [ 2 ] = {
{
. V_13 = V_13 ,
. V_23 = V_23 ,
. V_60 = 1 ,
. V_61 = V_292 ,
} , {
. V_13 = V_13 ,
. V_23 = V_23 | V_62 ,
. V_60 = 0 ,
. V_61 = V_293 ,
} ,
} ;
V_292 [ 0 ] = V_64 ;
switch ( V_291 ) {
case V_264 :
V_231 [ 0 ] . V_60 = 0 ;
V_231 [ 0 ] . V_23 = V_23 | ( V_290 == V_260 ?
V_62 : 0 ) ;
V_233 = 1 ;
break;
case V_266 :
if ( V_290 == V_260 ) {
V_231 [ 0 ] . V_23 = V_62 | V_23 ;
V_233 = 1 ;
}
break;
case V_261 :
if ( V_290 == V_260 )
V_231 [ 1 ] . V_60 = 1 ;
else {
V_231 [ 0 ] . V_60 = 2 ;
V_292 [ 1 ] = V_4 -> V_281 ;
}
break;
case V_283 :
if ( V_290 == V_260 )
V_231 [ 1 ] . V_60 = 2 ;
else {
V_231 [ 0 ] . V_60 = 3 ;
V_292 [ 1 ] = V_4 -> V_284 & 0xff ;
V_292 [ 2 ] = V_4 -> V_284 >> 8 ;
}
break;
case V_295 :
V_233 = 2 ;
V_290 = V_260 ;
V_231 [ 0 ] . V_60 = 3 ;
V_231 [ 1 ] . V_60 = 2 ;
V_292 [ 1 ] = V_4 -> V_284 & 0xff ;
V_292 [ 2 ] = V_4 -> V_284 >> 8 ;
break;
case V_286 :
if ( V_290 == V_260 ) {
V_231 [ 1 ] . V_23 |= V_253 ;
V_231 [ 1 ] . V_60 = 1 ;
} else {
V_231 [ 0 ] . V_60 = V_4 -> V_287 [ 0 ] + 2 ;
if ( V_231 [ 0 ] . V_60 > V_288 + 2 ) {
F_21 ( & V_29 -> V_40 ,
L_107 ,
V_4 -> V_287 [ 0 ] ) ;
return - V_128 ;
}
for ( V_116 = 1 ; V_116 < V_231 [ 0 ] . V_60 ; V_116 ++ )
V_292 [ V_116 ] = V_4 -> V_287 [ V_116 - 1 ] ;
}
break;
case V_296 :
V_233 = 2 ;
V_290 = V_260 ;
if ( V_4 -> V_287 [ 0 ] > V_288 ) {
F_21 ( & V_29 -> V_40 ,
L_107 ,
V_4 -> V_287 [ 0 ] ) ;
return - V_128 ;
}
V_231 [ 0 ] . V_60 = V_4 -> V_287 [ 0 ] + 2 ;
for ( V_116 = 1 ; V_116 < V_231 [ 0 ] . V_60 ; V_116 ++ )
V_292 [ V_116 ] = V_4 -> V_287 [ V_116 - 1 ] ;
V_231 [ 1 ] . V_23 |= V_253 ;
V_231 [ 1 ] . V_60 = 1 ;
break;
case V_289 :
if ( V_290 == V_260 ) {
V_231 [ 1 ] . V_60 = V_4 -> V_287 [ 0 ] ;
} else {
V_231 [ 0 ] . V_60 = V_4 -> V_287 [ 0 ] + 1 ;
if ( V_231 [ 0 ] . V_60 > V_288 + 1 ) {
F_21 ( & V_29 -> V_40 ,
L_107 ,
V_4 -> V_287 [ 0 ] ) ;
return - V_128 ;
}
for ( V_116 = 1 ; V_116 <= V_4 -> V_287 [ 0 ] ; V_116 ++ )
V_292 [ V_116 ] = V_4 -> V_287 [ V_116 ] ;
}
break;
default:
F_21 ( & V_29 -> V_40 , L_108 , V_291 ) ;
return - V_124 ;
}
V_116 = ( ( V_23 & V_297 ) && V_291 != V_264
&& V_291 != V_289 ) ;
if ( V_116 ) {
if ( ! ( V_231 [ 0 ] . V_23 & V_62 ) ) {
if ( V_233 == 1 )
F_259 ( & V_231 [ 0 ] ) ;
else
V_294 = F_257 ( 0 , & V_231 [ 0 ] ) ;
}
if ( V_231 [ V_233 - 1 ] . V_23 & V_62 )
V_231 [ V_233 - 1 ] . V_60 ++ ;
}
V_12 = F_29 ( V_29 , V_231 , V_233 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_116 && ( V_231 [ V_233 - 1 ] . V_23 & V_62 ) ) {
V_12 = F_260 ( V_294 , & V_231 [ V_233 - 1 ] ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( V_290 == V_260 )
switch ( V_291 ) {
case V_266 :
V_4 -> V_281 = V_292 [ 0 ] ;
break;
case V_261 :
V_4 -> V_281 = V_293 [ 0 ] ;
break;
case V_283 :
case V_295 :
V_4 -> V_284 = V_293 [ 0 ] | ( V_293 [ 1 ] << 8 ) ;
break;
case V_289 :
for ( V_116 = 0 ; V_116 < V_4 -> V_287 [ 0 ] ; V_116 ++ )
V_4 -> V_287 [ V_116 + 1 ] = V_293 [ V_116 ] ;
break;
case V_286 :
case V_296 :
for ( V_116 = 0 ; V_116 < V_293 [ 0 ] + 1 ; V_116 ++ )
V_4 -> V_287 [ V_116 ] = V_293 [ V_116 ] ;
break;
}
return 0 ;
}
T_13 F_248 ( struct V_28 * V_29 , T_8 V_13 , unsigned short V_23 ,
char V_290 , T_4 V_64 , int V_298 ,
union V_256 * V_4 )
{
unsigned long V_248 ;
int V_249 ;
T_13 V_41 ;
F_264 ( V_29 , V_13 , V_23 , V_290 ,
V_64 , V_298 , V_4 ) ;
F_265 ( V_29 , V_13 , V_23 , V_290 ,
V_64 , V_298 ) ;
V_23 &= V_255 | V_297 | V_299 ;
if ( V_29 -> V_186 -> V_300 ) {
F_241 ( V_29 , V_254 ) ;
V_248 = V_250 ;
for ( V_41 = 0 , V_249 = 0 ; V_249 <= V_29 -> V_251 ; V_249 ++ ) {
V_41 = V_29 -> V_186 -> V_300 ( V_29 , V_13 , V_23 ,
V_290 , V_64 ,
V_298 , V_4 ) ;
if ( V_41 != - V_184 )
break;
if ( F_235 ( V_250 ,
V_248 + V_29 -> V_191 ) )
break;
}
F_242 ( V_29 , V_254 ) ;
if ( V_41 != - V_124 || ! V_29 -> V_186 -> V_252 )
goto V_301;
}
V_41 = F_263 ( V_29 , V_13 , V_23 , V_290 ,
V_64 , V_298 , V_4 ) ;
V_301:
F_266 ( V_29 , V_13 , V_23 , V_290 ,
V_64 , V_298 , V_4 ) ;
F_267 ( V_29 , V_13 , V_23 , V_290 ,
V_64 , V_298 , V_41 ) ;
return V_41 ;
}
T_13 F_268 ( const struct V_51 * V_52 ,
T_4 V_64 , T_4 V_77 , T_4 * V_285 )
{
T_4 V_116 = 0 ;
int V_12 ;
if ( V_77 > V_288 )
V_77 = V_288 ;
if ( F_247 ( V_52 -> V_29 , V_302 ) )
return F_261 ( V_52 , V_64 , V_77 , V_285 ) ;
if ( ! F_247 ( V_52 -> V_29 , V_259 ) )
return - V_124 ;
if ( F_247 ( V_52 -> V_29 , V_303 ) ) {
while ( ( V_116 + 2 ) <= V_77 ) {
V_12 = F_39 ( V_52 , V_64 + V_116 ) ;
if ( V_12 < 0 )
return V_12 ;
V_285 [ V_116 ] = V_12 & 0xff ;
V_285 [ V_116 + 1 ] = V_12 >> 8 ;
V_116 += 2 ;
}
}
while ( V_116 < V_77 ) {
V_12 = F_37 ( V_52 , V_64 + V_116 ) ;
if ( V_12 < 0 )
return V_12 ;
V_285 [ V_116 ] = V_12 ;
V_116 ++ ;
}
return V_116 ;
}
int F_269 ( struct V_51 * V_52 , T_14 V_304 )
{
int V_36 ;
if ( ! V_52 || ! V_304 ) {
F_270 ( 1 , L_109 ) ;
return - V_128 ;
}
if ( ! ( V_52 -> V_23 & V_142 ) )
F_26 ( & V_52 -> V_40 , L_110 ,
V_223 ) ;
if ( ! ( V_52 -> V_23 & V_24 ) ) {
V_36 = F_99 ( V_52 -> V_13 ) ;
if ( V_36 ) {
F_21 ( & V_52 -> V_40 , L_111 , V_223 ) ;
return V_36 ;
}
}
if ( ! V_52 -> V_29 -> V_186 -> V_305 ) {
F_21 ( & V_52 -> V_40 , L_112 , V_223 ) ;
return - V_124 ;
}
V_52 -> V_304 = V_304 ;
F_271 ( V_52 -> V_29 ) ;
V_36 = V_52 -> V_29 -> V_186 -> V_305 ( V_52 ) ;
F_272 ( V_52 -> V_29 ) ;
if ( V_36 ) {
V_52 -> V_304 = NULL ;
F_21 ( & V_52 -> V_40 , L_113 , V_223 , V_36 ) ;
}
return V_36 ;
}
int F_273 ( struct V_51 * V_52 )
{
int V_36 ;
if ( ! V_52 -> V_29 -> V_186 -> V_306 ) {
F_21 ( & V_52 -> V_40 , L_112 , V_223 ) ;
return - V_124 ;
}
F_271 ( V_52 -> V_29 ) ;
V_36 = V_52 -> V_29 -> V_186 -> V_306 ( V_52 ) ;
F_272 ( V_52 -> V_29 ) ;
if ( V_36 == 0 )
V_52 -> V_304 = NULL ;
else
F_21 ( & V_52 -> V_40 , L_113 , V_223 , V_36 ) ;
return V_36 ;
}
