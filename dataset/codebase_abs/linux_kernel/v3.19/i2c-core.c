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
if ( V_3 -> type == V_7 ) {
struct V_8 * V_9 ;
V_9 = & V_3 -> V_4 . V_10 ;
if ( V_9 -> type == V_11 ) {
V_6 -> V_12 = V_9 -> V_13 ;
if ( V_9 -> V_14 == V_15 )
V_6 -> V_16 |= V_17 ;
}
} else if ( V_6 -> V_18 < 0 ) {
struct V_19 V_20 ;
if ( F_6 ( V_3 , 0 , & V_20 ) )
V_6 -> V_18 = V_20 . V_21 ;
}
return 1 ;
}
static T_1 F_7 ( T_2 V_22 , T_3 V_23 ,
void * V_4 , void * * V_24 )
{
struct V_25 * V_26 = V_4 ;
struct V_27 V_28 ;
struct V_5 V_6 ;
struct V_29 * V_30 ;
int V_31 ;
if ( F_8 ( V_22 , & V_30 ) )
return V_32 ;
if ( F_9 ( V_30 ) || ! V_30 -> V_33 . V_34 )
return V_32 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_35 . V_36 = V_30 ;
V_6 . V_18 = - 1 ;
F_10 ( & V_28 ) ;
V_31 = F_11 ( V_30 , & V_28 ,
F_5 , & V_6 ) ;
F_12 ( & V_28 ) ;
if ( V_31 < 0 || ! V_6 . V_12 )
return V_32 ;
V_30 -> V_37 . V_16 . V_38 = true ;
F_13 ( V_6 . type , F_14 ( & V_30 -> V_39 ) , sizeof( V_6 . type ) ) ;
if ( ! F_15 ( V_26 , & V_6 ) ) {
V_30 -> V_37 . V_16 . V_38 = false ;
F_16 ( & V_26 -> V_39 ,
L_1 ,
F_14 ( & V_30 -> V_39 ) ) ;
}
return V_32 ;
}
static void F_17 ( struct V_25 * V_40 )
{
T_2 V_22 ;
T_1 V_33 ;
if ( ! V_40 -> V_39 . V_41 )
return;
V_22 = F_18 ( V_40 -> V_39 . V_41 ) ;
if ( ! V_22 )
return;
V_33 = F_19 ( V_42 , V_22 , 1 ,
F_7 , NULL ,
V_40 , NULL ) ;
if ( F_20 ( V_33 ) )
F_21 ( & V_40 -> V_39 , L_2 ) ;
}
static inline void F_17 ( struct V_25 * V_40 ) { }
static int F_22 ( struct V_43 * V_44 ,
T_4 V_45 , T_4 * V_4 , T_4 V_46 )
{
struct V_47 V_48 [ 2 ] ;
int V_31 ;
T_4 * V_49 ;
V_49 = F_23 ( V_46 , V_50 ) ;
if ( ! V_49 )
return V_51 ;
V_48 [ 0 ] . V_12 = V_44 -> V_12 ;
V_48 [ 0 ] . V_16 = V_44 -> V_16 ;
V_48 [ 0 ] . V_52 = 1 ;
V_48 [ 0 ] . V_53 = & V_45 ;
V_48 [ 1 ] . V_12 = V_44 -> V_12 ;
V_48 [ 1 ] . V_16 = V_44 -> V_16 | V_54 ;
V_48 [ 1 ] . V_52 = V_46 ;
V_48 [ 1 ] . V_53 = V_49 ;
V_31 = F_24 ( V_44 -> V_26 , V_48 , F_25 ( V_48 ) ) ;
if ( V_31 < 0 )
F_16 ( & V_44 -> V_26 -> V_39 , L_3 ) ;
else
memcpy ( V_4 , V_49 , V_46 ) ;
F_26 ( V_49 ) ;
return V_31 ;
}
static int F_27 ( struct V_43 * V_44 ,
T_4 V_45 , T_4 * V_4 , T_4 V_46 )
{
struct V_47 V_48 [ 1 ] ;
T_4 * V_49 ;
int V_31 = V_32 ;
V_49 = F_23 ( V_46 + 1 , V_50 ) ;
if ( ! V_49 )
return V_51 ;
V_49 [ 0 ] = V_45 ;
memcpy ( V_49 + 1 , V_4 , V_46 ) ;
V_48 [ 0 ] . V_12 = V_44 -> V_12 ;
V_48 [ 0 ] . V_16 = V_44 -> V_16 ;
V_48 [ 0 ] . V_52 = V_46 + 1 ;
V_48 [ 0 ] . V_53 = V_49 ;
V_31 = F_24 ( V_44 -> V_26 , V_48 , F_25 ( V_48 ) ) ;
if ( V_31 < 0 )
F_16 ( & V_44 -> V_26 -> V_39 , L_4 ) ;
F_26 ( V_49 ) ;
return V_31 ;
}
static T_1
F_28 ( T_3 V_55 , T_5 V_56 ,
T_3 V_57 , T_6 * V_58 ,
void * V_59 , void * V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_58 ;
struct V_63 * V_4 = V_59 ;
struct V_64 * V_6 = & V_4 -> V_6 ;
struct V_8 * V_9 ;
struct V_25 * V_26 = V_4 -> V_26 ;
struct V_43 V_44 ;
struct V_2 * V_3 ;
T_3 V_65 = V_55 >> 16 ;
T_4 V_66 = V_55 & V_67 ;
T_1 V_31 ;
int V_33 ;
V_31 = F_29 ( V_6 -> V_68 , V_6 -> V_69 , & V_3 ) ;
if ( F_20 ( V_31 ) )
return V_31 ;
if ( ! V_58 || V_3 -> type != V_7 ) {
V_31 = V_70 ;
goto V_71;
}
V_9 = & V_3 -> V_4 . V_10 ;
if ( V_9 -> type != V_11 ) {
V_31 = V_70 ;
goto V_71;
}
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_26 = V_26 ;
V_44 . V_12 = V_9 -> V_13 ;
V_44 . V_16 = 0 ;
if ( V_9 -> V_14 == V_15 )
V_44 . V_16 |= V_17 ;
switch ( V_65 ) {
case V_72 :
if ( V_66 == V_73 ) {
V_33 = F_30 ( & V_44 ) ;
if ( V_33 >= 0 ) {
V_62 -> V_74 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_31 ( & V_44 , V_62 -> V_74 ) ;
}
break;
case V_75 :
if ( V_66 == V_73 ) {
V_33 = F_32 ( & V_44 , V_56 ) ;
if ( V_33 >= 0 ) {
V_62 -> V_74 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_33 ( & V_44 , V_56 ,
V_62 -> V_74 ) ;
}
break;
case V_76 :
if ( V_66 == V_73 ) {
V_33 = F_34 ( & V_44 , V_56 ) ;
if ( V_33 >= 0 ) {
V_62 -> V_77 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_35 ( & V_44 , V_56 ,
V_62 -> V_77 ) ;
}
break;
case V_78 :
if ( V_66 == V_73 ) {
V_33 = F_36 ( & V_44 , V_56 ,
V_62 -> V_4 ) ;
if ( V_33 >= 0 ) {
V_62 -> V_52 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_37 ( & V_44 , V_56 ,
V_62 -> V_52 , V_62 -> V_4 ) ;
}
break;
case V_79 :
if ( V_66 == V_73 ) {
V_33 = F_22 ( & V_44 , V_56 ,
V_62 -> V_4 , V_6 -> V_80 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
} else {
V_33 = F_27 ( & V_44 , V_56 ,
V_62 -> V_4 , V_6 -> V_80 ) ;
}
break;
default:
F_38 ( L_5 , V_65 ) ;
V_31 = V_70 ;
goto V_71;
}
V_62 -> V_33 = V_33 ;
V_71:
F_39 ( V_3 ) ;
return V_31 ;
}
static int F_40 ( struct V_25 * V_26 )
{
T_2 V_22 ;
struct V_63 * V_4 ;
T_1 V_33 ;
if ( ! V_26 -> V_39 . V_41 )
return - V_81 ;
V_22 = F_18 ( V_26 -> V_39 . V_41 ) ;
if ( ! V_22 )
return - V_81 ;
V_4 = F_23 ( sizeof( struct V_63 ) ,
V_50 ) ;
if ( ! V_4 )
return - V_82 ;
V_4 -> V_26 = V_26 ;
V_33 = F_41 ( V_22 , ( void * ) V_4 ) ;
if ( F_20 ( V_33 ) ) {
F_26 ( V_4 ) ;
return - V_82 ;
}
V_33 = F_42 ( V_22 ,
V_83 ,
& F_28 ,
NULL ,
V_4 ) ;
if ( F_20 ( V_33 ) ) {
F_16 ( & V_26 -> V_39 , L_6 ) ;
F_43 ( V_22 ) ;
F_26 ( V_4 ) ;
return - V_82 ;
}
F_44 ( V_22 ) ;
return 0 ;
}
static void F_45 ( struct V_25 * V_26 )
{
T_2 V_22 ;
struct V_63 * V_4 ;
T_1 V_33 ;
if ( ! V_26 -> V_39 . V_41 )
return;
V_22 = F_18 ( V_26 -> V_39 . V_41 ) ;
if ( ! V_22 )
return;
F_46 ( V_22 ,
V_83 ,
& F_28 ) ;
V_33 = F_47 ( V_22 , ( void * * ) & V_4 ) ;
if ( F_48 ( V_33 ) )
F_26 ( V_4 ) ;
F_43 ( V_22 ) ;
}
static inline void F_45 ( struct V_25 * V_26 )
{ }
static inline int F_40 ( struct V_25 * V_26 )
{ return 0 ; }
static const struct V_84 * F_49 ( const struct V_84 * V_85 ,
const struct V_43 * V_44 )
{
while ( V_85 -> V_86 [ 0 ] ) {
if ( strcmp ( V_44 -> V_86 , V_85 -> V_86 ) == 0 )
return V_85 ;
V_85 ++ ;
}
return NULL ;
}
static int F_50 ( struct V_87 * V_39 , struct V_88 * V_89 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 )
return 0 ;
if ( F_52 ( V_39 , V_89 ) )
return 1 ;
if ( F_53 ( V_39 , V_89 ) )
return 1 ;
V_91 = F_54 ( V_89 ) ;
if ( V_91 -> V_92 )
return F_49 ( V_91 -> V_92 , V_44 ) != NULL ;
return 0 ;
}
static int F_55 ( struct V_87 * V_39 , struct V_93 * V_94 )
{
struct V_43 * V_44 = F_56 ( V_39 ) ;
int V_95 ;
V_95 = F_57 ( V_39 , V_94 ) ;
if ( V_95 != - V_81 )
return V_95 ;
if ( F_58 ( V_94 , L_7 ,
V_96 , V_44 -> V_86 ) )
return - V_82 ;
F_59 ( V_39 , L_8 ) ;
return 0 ;
}
static int F_60 ( struct V_25 * V_40 )
{
return F_61 ( V_40 -> V_97 -> V_98 ) ;
}
static void F_62 ( struct V_25 * V_40 , int V_99 )
{
F_63 ( V_40 -> V_97 -> V_98 , V_99 ) ;
}
static int F_64 ( struct V_25 * V_40 )
{
return F_61 ( V_40 -> V_97 -> V_100 ) ;
}
static int F_65 ( struct V_25 * V_40 )
{
struct V_101 * V_102 = V_40 -> V_97 ;
struct V_87 * V_39 = & V_40 -> V_39 ;
int V_31 = 0 ;
V_31 = F_66 ( V_102 -> V_98 , V_103 |
V_104 , L_9 ) ;
if ( V_31 ) {
F_21 ( V_39 , L_10 , V_102 -> V_98 ) ;
return V_31 ;
}
if ( V_102 -> V_105 ) {
if ( F_66 ( V_102 -> V_100 , V_106 , L_11 ) ) {
F_21 ( V_39 , L_12 ,
V_102 -> V_100 ) ;
V_102 -> V_105 = NULL ;
}
}
return V_31 ;
}
static void F_67 ( struct V_25 * V_40 )
{
struct V_101 * V_102 = V_40 -> V_97 ;
if ( V_102 -> V_105 )
F_68 ( V_102 -> V_100 ) ;
F_68 ( V_102 -> V_98 ) ;
}
static int F_69 ( struct V_25 * V_40 )
{
struct V_101 * V_102 = V_40 -> V_97 ;
int V_107 = 0 , V_99 = 1 , V_31 = 0 ;
if ( V_102 -> V_108 )
V_102 -> V_108 ( V_102 ) ;
while ( V_107 ++ < V_109 * 2 ) {
if ( V_99 ) {
if ( V_102 -> V_105 && V_102 -> V_105 ( V_40 ) )
break;
if ( ! V_102 -> V_110 ( V_40 ) ) {
F_16 ( & V_40 -> V_39 ,
L_13 ) ;
V_31 = - V_111 ;
break;
}
}
V_99 = ! V_99 ;
V_102 -> V_112 ( V_40 , V_99 ) ;
F_70 ( V_113 ) ;
}
if ( V_102 -> V_114 )
V_102 -> V_114 ( V_102 ) ;
return V_31 ;
}
int F_71 ( struct V_25 * V_40 )
{
V_40 -> V_97 -> V_112 ( V_40 , 1 ) ;
return F_69 ( V_40 ) ;
}
int F_72 ( struct V_25 * V_40 )
{
int V_31 ;
V_31 = F_65 ( V_40 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_69 ( V_40 ) ;
F_67 ( V_40 ) ;
return V_31 ;
}
int F_73 ( struct V_25 * V_40 )
{
if ( ! V_40 -> V_97 )
return - V_115 ;
F_59 ( & V_40 -> V_39 , L_14 ) ;
return V_40 -> V_97 -> V_116 ( V_40 ) ;
}
static int F_74 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
int V_33 ;
if ( ! V_44 )
return 0 ;
if ( ! V_44 -> V_18 && V_39 -> V_117 ) {
int V_18 = F_75 ( V_39 -> V_117 , 0 ) ;
if ( V_18 == - V_118 )
return V_18 ;
if ( V_18 < 0 )
V_18 = 0 ;
V_44 -> V_18 = V_18 ;
}
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_119 || ! V_91 -> V_92 )
return - V_81 ;
if ( ! F_76 ( & V_44 -> V_39 ) )
F_77 ( & V_44 -> V_39 ,
V_44 -> V_16 & V_120 ) ;
F_59 ( V_39 , L_15 ) ;
V_33 = F_78 ( V_39 -> V_117 , false ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_79 ( & V_44 -> V_39 , true ) ;
if ( V_33 != - V_118 ) {
V_33 = V_91 -> V_119 ( V_44 , F_49 ( V_91 -> V_92 ,
V_44 ) ) ;
if ( V_33 )
F_80 ( & V_44 -> V_39 , true ) ;
}
return V_33 ;
}
static int F_81 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
int V_33 = 0 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( V_91 -> remove ) {
F_59 ( V_39 , L_16 ) ;
V_33 = V_91 -> remove ( V_44 ) ;
}
if ( V_39 -> V_117 )
F_82 ( V_44 -> V_18 ) ;
F_80 ( & V_44 -> V_39 , true ) ;
return V_33 ;
}
static void F_83 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return;
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( V_91 -> V_121 )
V_91 -> V_121 ( V_44 ) ;
}
static int F_84 ( struct V_87 * V_39 , T_7 V_122 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_123 )
return 0 ;
return V_91 -> V_123 ( V_44 , V_122 ) ;
}
static int F_85 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_124 )
return 0 ;
return V_91 -> V_124 ( V_44 ) ;
}
static int F_86 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_87 ( V_39 ) ;
else
return F_84 ( V_39 , V_127 ) ;
}
static int F_88 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_89 ( V_39 ) ;
else
return F_85 ( V_39 ) ;
}
static int F_90 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_91 ( V_39 ) ;
else
return F_84 ( V_39 , V_128 ) ;
}
static int F_92 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_93 ( V_39 ) ;
else
return F_85 ( V_39 ) ;
}
static int F_94 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_95 ( V_39 ) ;
else
return F_84 ( V_39 , V_129 ) ;
}
static int F_96 ( struct V_87 * V_39 )
{
const struct V_125 * V_126 = V_39 -> V_91 ? V_39 -> V_91 -> V_126 : NULL ;
if ( V_126 )
return F_97 ( V_39 ) ;
else
return F_85 ( V_39 ) ;
}
static void F_98 ( struct V_87 * V_39 )
{
F_26 ( F_56 ( V_39 ) ) ;
}
static T_8
F_99 ( struct V_87 * V_39 , struct V_130 * V_131 , char * V_53 )
{
return sprintf ( V_53 , L_17 , V_39 -> type == & V_132 ?
F_56 ( V_39 ) -> V_86 : F_100 ( V_39 ) -> V_86 ) ;
}
static T_8
F_101 ( struct V_87 * V_39 , struct V_130 * V_131 , char * V_53 )
{
struct V_43 * V_44 = F_56 ( V_39 ) ;
int V_52 ;
V_52 = F_102 ( V_39 , V_53 , V_133 - 1 ) ;
if ( V_52 != - V_81 )
return V_52 ;
return sprintf ( V_53 , L_18 , V_96 , V_44 -> V_86 ) ;
}
struct V_43 * F_51 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_132 )
? F_56 ( V_39 )
: NULL ;
}
static int F_103 ( const struct V_43 * V_44 )
{
if ( V_44 -> V_16 & V_17 ) {
if ( V_44 -> V_12 > 0x3ff )
return - V_134 ;
} else {
if ( V_44 -> V_12 == 0x00 || V_44 -> V_12 > 0x7f )
return - V_134 ;
}
return 0 ;
}
static int F_104 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_134 ;
return 0 ;
}
static int F_105 ( struct V_87 * V_39 , void * V_135 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
int V_12 = * ( int * ) V_135 ;
if ( V_44 && V_44 -> V_12 == V_12 )
return - V_111 ;
return 0 ;
}
static int F_106 ( struct V_25 * V_26 , int V_12 )
{
struct V_25 * V_41 = F_107 ( V_26 ) ;
int V_136 ;
V_136 = F_108 ( & V_26 -> V_39 , & V_12 ,
F_105 ) ;
if ( ! V_136 && V_41 )
V_136 = F_106 ( V_41 , V_12 ) ;
return V_136 ;
}
static int F_109 ( struct V_87 * V_39 , void * V_135 )
{
int V_136 ;
if ( V_39 -> type == & V_137 )
V_136 = F_108 ( V_39 , V_135 ,
F_109 ) ;
else
V_136 = F_105 ( V_39 , V_135 ) ;
return V_136 ;
}
static int F_110 ( struct V_25 * V_26 , int V_12 )
{
struct V_25 * V_41 = F_107 ( V_26 ) ;
int V_136 = 0 ;
if ( V_41 )
V_136 = F_106 ( V_41 , V_12 ) ;
if ( ! V_136 )
V_136 = F_108 ( & V_26 -> V_39 , & V_12 ,
F_109 ) ;
return V_136 ;
}
void F_111 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_107 ( V_26 ) ;
if ( V_41 )
F_111 ( V_41 ) ;
else
F_112 ( & V_26 -> V_138 ) ;
}
static int F_113 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_107 ( V_26 ) ;
if ( V_41 )
return F_113 ( V_41 ) ;
else
return F_114 ( & V_26 -> V_138 ) ;
}
void F_115 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_107 ( V_26 ) ;
if ( V_41 )
F_115 ( V_41 ) ;
else
F_116 ( & V_26 -> V_138 ) ;
}
static void F_117 ( struct V_25 * V_40 ,
struct V_43 * V_44 )
{
struct V_29 * V_30 = F_118 ( & V_44 -> V_39 ) ;
if ( V_30 ) {
F_119 ( & V_44 -> V_39 , L_19 , F_120 ( V_30 ) ) ;
return;
}
F_119 ( & V_44 -> V_39 , L_20 , F_121 ( V_40 ) ,
V_44 -> V_12 | ( ( V_44 -> V_16 & V_17 )
? 0xa000 : 0 ) ) ;
}
struct V_43 *
F_15 ( struct V_25 * V_40 , struct V_5 const * V_6 )
{
struct V_43 * V_44 ;
int V_33 ;
V_44 = F_23 ( sizeof *V_44 , V_50 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_26 = V_40 ;
V_44 -> V_39 . V_139 = V_6 -> V_139 ;
if ( V_6 -> V_140 )
V_44 -> V_39 . V_140 = * V_6 -> V_140 ;
V_44 -> V_16 = V_6 -> V_16 ;
V_44 -> V_12 = V_6 -> V_12 ;
V_44 -> V_18 = V_6 -> V_18 ;
F_13 ( V_44 -> V_86 , V_6 -> type , sizeof( V_44 -> V_86 ) ) ;
V_33 = F_103 ( V_44 ) ;
if ( V_33 ) {
F_16 ( & V_40 -> V_39 , L_21 ,
V_44 -> V_16 & V_17 ? 10 : 7 , V_44 -> V_12 ) ;
goto V_141;
}
V_33 = F_110 ( V_40 , V_44 -> V_12 ) ;
if ( V_33 )
goto V_142;
V_44 -> V_39 . V_41 = & V_44 -> V_26 -> V_39 ;
V_44 -> V_39 . V_143 = & V_144 ;
V_44 -> V_39 . type = & V_132 ;
V_44 -> V_39 . V_117 = V_6 -> V_117 ;
F_122 ( & V_44 -> V_39 , V_6 -> V_35 . V_36 ) ;
F_117 ( V_40 , V_44 ) ;
V_33 = F_123 ( & V_44 -> V_39 ) ;
if ( V_33 )
goto V_142;
F_59 ( & V_40 -> V_39 , L_22 ,
V_44 -> V_86 , F_14 ( & V_44 -> V_39 ) ) ;
return V_44 ;
V_142:
F_16 ( & V_40 -> V_39 , L_23
L_24 , V_44 -> V_86 , V_44 -> V_12 , V_33 ) ;
V_141:
F_26 ( V_44 ) ;
return NULL ;
}
void F_124 ( struct V_43 * V_44 )
{
F_125 ( & V_44 -> V_39 ) ;
}
static int F_126 ( struct V_43 * V_44 ,
const struct V_84 * V_85 )
{
return 0 ;
}
static int F_127 ( struct V_43 * V_44 )
{
return 0 ;
}
struct V_43 * F_128 ( struct V_25 * V_26 , T_9 V_145 )
{
struct V_5 V_6 = {
F_129 ( L_25 , V_145 ) ,
} ;
return F_15 ( V_26 , & V_6 ) ;
}
static void F_130 ( struct V_87 * V_39 )
{
struct V_25 * V_40 = F_100 ( V_39 ) ;
F_131 ( & V_40 -> V_146 ) ;
}
static inline unsigned int F_132 ( struct V_25 * V_26 )
{
unsigned int V_147 = 0 ;
while ( ( V_26 = F_107 ( V_26 ) ) )
V_147 ++ ;
return V_147 ;
}
static T_8
F_133 ( struct V_87 * V_39 , struct V_130 * V_131 ,
const char * V_53 , T_10 V_148 )
{
struct V_25 * V_40 = F_100 ( V_39 ) ;
struct V_5 V_6 ;
struct V_43 * V_44 ;
char * V_149 , V_150 ;
int V_151 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_149 = strchr ( V_53 , ' ' ) ;
if ( ! V_149 ) {
F_16 ( V_39 , L_26 , L_27 ) ;
return - V_134 ;
}
if ( V_149 - V_53 > V_152 - 1 ) {
F_16 ( V_39 , L_28 , L_27 ) ;
return - V_134 ;
}
memcpy ( V_6 . type , V_53 , V_149 - V_53 ) ;
V_151 = sscanf ( ++ V_149 , L_29 , & V_6 . V_12 , & V_150 ) ;
if ( V_151 < 1 ) {
F_16 ( V_39 , L_30 , L_27 ) ;
return - V_134 ;
}
if ( V_151 > 1 && V_150 != '\n' ) {
F_16 ( V_39 , L_31 , L_27 ) ;
return - V_134 ;
}
V_44 = F_15 ( V_40 , & V_6 ) ;
if ( ! V_44 )
return - V_134 ;
F_134 ( & V_40 -> V_153 ) ;
F_135 ( & V_44 -> V_154 , & V_40 -> V_155 ) ;
F_136 ( & V_40 -> V_153 ) ;
F_137 ( V_39 , L_32 , L_27 ,
V_6 . type , V_6 . V_12 ) ;
return V_148 ;
}
static T_8
F_138 ( struct V_87 * V_39 , struct V_130 * V_131 ,
const char * V_53 , T_10 V_148 )
{
struct V_25 * V_40 = F_100 ( V_39 ) ;
struct V_43 * V_44 , * V_156 ;
unsigned short V_12 ;
char V_150 ;
int V_151 ;
V_151 = sscanf ( V_53 , L_29 , & V_12 , & V_150 ) ;
if ( V_151 < 1 ) {
F_16 ( V_39 , L_30 , L_33 ) ;
return - V_134 ;
}
if ( V_151 > 1 && V_150 != '\n' ) {
F_16 ( V_39 , L_31 , L_33 ) ;
return - V_134 ;
}
V_151 = - V_157 ;
F_139 ( & V_40 -> V_153 ,
F_132 ( V_40 ) ) ;
F_140 (client, next, &adap->userspace_clients,
detected) {
if ( V_44 -> V_12 == V_12 ) {
F_137 ( V_39 , L_34 ,
L_33 , V_44 -> V_86 , V_44 -> V_12 ) ;
F_141 ( & V_44 -> V_154 ) ;
F_124 ( V_44 ) ;
V_151 = V_148 ;
break;
}
}
F_136 ( & V_40 -> V_153 ) ;
if ( V_151 < 0 )
F_16 ( V_39 , L_35 ,
L_33 ) ;
return V_151 ;
}
struct V_25 * F_142 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_137 )
? F_100 ( V_39 )
: NULL ;
}
static void F_143 ( struct V_25 * V_26 )
{
struct V_158 * V_159 ;
F_144 ( & V_160 ) ;
F_145 (devinfo, &__i2c_board_list, list) {
if ( V_159 -> V_161 == V_26 -> V_162
&& ! F_15 ( V_26 ,
& V_159 -> V_163 ) )
F_16 ( & V_26 -> V_39 ,
L_36 ,
V_159 -> V_163 . V_12 ) ;
}
F_146 ( & V_160 ) ;
}
static struct V_43 * F_147 ( struct V_25 * V_40 ,
struct V_164 * V_165 )
{
struct V_43 * V_136 ;
struct V_5 V_6 = {} ;
struct V_166 V_167 = {} ;
const T_11 * V_12 ;
int V_52 ;
F_59 ( & V_40 -> V_39 , L_37 , V_165 -> V_168 ) ;
if ( F_148 ( V_165 , V_6 . type , sizeof( V_6 . type ) ) < 0 ) {
F_16 ( & V_40 -> V_39 , L_38 ,
V_165 -> V_168 ) ;
return F_149 ( - V_134 ) ;
}
V_12 = F_150 ( V_165 , L_39 , & V_52 ) ;
if ( ! V_12 || ( V_52 < sizeof( int ) ) ) {
F_16 ( & V_40 -> V_39 , L_40 ,
V_165 -> V_168 ) ;
return F_149 ( - V_134 ) ;
}
V_6 . V_12 = F_151 ( V_12 ) ;
if ( V_6 . V_12 > ( 1 << 10 ) - 1 ) {
F_16 ( & V_40 -> V_39 , L_41 ,
V_6 . V_12 , V_165 -> V_168 ) ;
return F_149 ( - V_134 ) ;
}
V_6 . V_117 = F_152 ( V_165 ) ;
V_6 . V_140 = & V_167 ;
if ( F_150 ( V_165 , L_42 , NULL ) )
V_6 . V_16 |= V_120 ;
F_153 ( L_43 , V_96 , V_6 . type ) ;
V_136 = F_15 ( V_40 , & V_6 ) ;
if ( V_136 == NULL ) {
F_16 ( & V_40 -> V_39 , L_44 ,
V_165 -> V_168 ) ;
F_154 ( V_165 ) ;
return F_149 ( - V_134 ) ;
}
return V_136 ;
}
static void F_155 ( struct V_25 * V_40 )
{
struct V_164 * V_165 ;
if ( ! V_40 -> V_39 . V_117 )
return;
F_59 ( & V_40 -> V_39 , L_45 ) ;
F_156 (adap->dev.of_node, node)
F_147 ( V_40 , V_165 ) ;
}
static int F_157 ( struct V_87 * V_39 , void * V_4 )
{
return V_39 -> V_117 == V_4 ;
}
struct V_43 * F_158 ( struct V_164 * V_165 )
{
struct V_87 * V_39 ;
V_39 = F_159 ( & V_144 , NULL , V_165 ,
F_157 ) ;
if ( ! V_39 )
return NULL ;
return F_51 ( V_39 ) ;
}
struct V_25 * F_160 ( struct V_164 * V_165 )
{
struct V_87 * V_39 ;
V_39 = F_159 ( & V_144 , NULL , V_165 ,
F_157 ) ;
if ( ! V_39 )
return NULL ;
return F_142 ( V_39 ) ;
}
static void F_155 ( struct V_25 * V_40 ) { }
static int F_161 ( struct V_90 * V_91 ,
struct V_25 * V_40 )
{
F_162 ( V_40 , V_91 ) ;
if ( V_91 -> V_169 ) {
F_21 ( & V_40 -> V_39 , L_46 ,
V_91 -> V_91 . V_86 ) ;
F_21 ( & V_40 -> V_39 , L_47
L_48 ) ;
V_91 -> V_169 ( V_40 ) ;
}
return 0 ;
}
static int F_163 ( struct V_88 * V_170 , void * V_4 )
{
return F_161 ( F_54 ( V_170 ) , V_4 ) ;
}
static int F_164 ( struct V_25 * V_40 )
{
int V_151 = 0 ;
if ( F_165 ( F_166 ( ! V_144 . V_171 ) ) ) {
V_151 = - V_172 ;
goto V_173;
}
if ( F_165 ( V_40 -> V_86 [ 0 ] == '\0' ) ) {
F_167 ( L_49
L_50 ) ;
return - V_134 ;
}
if ( F_165 ( ! V_40 -> V_174 ) ) {
F_167 ( L_51
L_52 , V_40 -> V_86 ) ;
return - V_134 ;
}
F_168 ( & V_40 -> V_138 ) ;
F_169 ( & V_40 -> V_153 ) ;
F_10 ( & V_40 -> V_155 ) ;
if ( V_40 -> V_175 == 0 )
V_40 -> V_175 = V_176 ;
F_119 ( & V_40 -> V_39 , L_53 , V_40 -> V_162 ) ;
V_40 -> V_39 . V_143 = & V_144 ;
V_40 -> V_39 . type = & V_137 ;
V_151 = F_123 ( & V_40 -> V_39 ) ;
if ( V_151 )
goto V_173;
F_59 ( & V_40 -> V_39 , L_54 , V_40 -> V_86 ) ;
#ifdef F_170
V_151 = F_171 ( V_177 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
if ( V_151 )
F_21 ( & V_40 -> V_39 ,
L_55 ) ;
#endif
if ( V_40 -> V_97 ) {
struct V_101 * V_102 = V_40 -> V_97 ;
if ( ! V_102 -> V_116 ) {
F_16 ( & V_40 -> V_39 , L_56 ) ;
V_40 -> V_97 = NULL ;
goto V_178;
}
if ( V_102 -> V_116 == F_72 ) {
if ( ! F_172 ( V_102 -> V_98 ) ) {
F_16 ( & V_40 -> V_39 , L_57 ) ;
V_40 -> V_97 = NULL ;
goto V_178;
}
if ( F_172 ( V_102 -> V_100 ) )
V_102 -> V_105 = F_64 ;
else
V_102 -> V_105 = NULL ;
V_102 -> V_110 = F_60 ;
V_102 -> V_112 = F_62 ;
} else if ( ! V_102 -> V_112 || ! V_102 -> V_110 ) {
F_16 ( & V_40 -> V_39 , L_58 ) ;
V_40 -> V_97 = NULL ;
}
}
V_178:
F_155 ( V_40 ) ;
F_17 ( V_40 ) ;
F_40 ( V_40 ) ;
if ( V_40 -> V_162 < V_179 )
F_143 ( V_40 ) ;
F_134 ( & V_180 ) ;
F_173 ( & V_144 , NULL , V_40 , F_163 ) ;
F_136 ( & V_180 ) ;
return 0 ;
V_173:
F_134 ( & V_180 ) ;
F_174 ( & V_181 , V_40 -> V_162 ) ;
F_136 ( & V_180 ) ;
return V_151 ;
}
static int F_175 ( struct V_25 * V_40 )
{
int V_85 ;
F_134 ( & V_180 ) ;
V_85 = F_176 ( & V_181 , V_40 , V_40 -> V_162 , V_40 -> V_162 + 1 ,
V_50 ) ;
F_136 ( & V_180 ) ;
if ( V_85 < 0 )
return V_85 == - V_182 ? - V_111 : V_85 ;
return F_164 ( V_40 ) ;
}
int F_177 ( struct V_25 * V_26 )
{
struct V_87 * V_39 = & V_26 -> V_39 ;
int V_85 ;
if ( V_39 -> V_117 ) {
V_85 = F_178 ( V_39 -> V_117 , L_59 ) ;
if ( V_85 >= 0 ) {
V_26 -> V_162 = V_85 ;
return F_175 ( V_26 ) ;
}
}
F_134 ( & V_180 ) ;
V_85 = F_176 ( & V_181 , V_26 ,
V_179 , 0 , V_50 ) ;
F_136 ( & V_180 ) ;
if ( V_85 < 0 )
return V_85 ;
V_26 -> V_162 = V_85 ;
return F_164 ( V_26 ) ;
}
int F_179 ( struct V_25 * V_40 )
{
if ( V_40 -> V_162 == - 1 )
return F_177 ( V_40 ) ;
return F_175 ( V_40 ) ;
}
static void F_180 ( struct V_90 * V_91 ,
struct V_25 * V_26 )
{
struct V_43 * V_44 , * V_183 ;
F_140 (client, _n, &driver->clients, detected) {
if ( V_44 -> V_26 == V_26 ) {
F_59 ( & V_26 -> V_39 , L_60 ,
V_44 -> V_86 , V_44 -> V_12 ) ;
F_141 ( & V_44 -> V_154 ) ;
F_124 ( V_44 ) ;
}
}
}
static int F_181 ( struct V_87 * V_39 , void * V_184 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
if ( V_44 && strcmp ( V_44 -> V_86 , L_25 ) )
F_124 ( V_44 ) ;
return 0 ;
}
static int F_182 ( struct V_87 * V_39 , void * V_184 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
if ( V_44 )
F_124 ( V_44 ) ;
return 0 ;
}
static int F_183 ( struct V_88 * V_170 , void * V_4 )
{
F_180 ( F_54 ( V_170 ) , V_4 ) ;
return 0 ;
}
void F_184 ( struct V_25 * V_40 )
{
struct V_25 * V_185 ;
struct V_43 * V_44 , * V_156 ;
F_134 ( & V_180 ) ;
V_185 = F_185 ( & V_181 , V_40 -> V_162 ) ;
F_136 ( & V_180 ) ;
if ( V_185 != V_40 ) {
F_186 ( L_61
L_62 , V_40 -> V_86 ) ;
return;
}
F_45 ( V_40 ) ;
F_134 ( & V_180 ) ;
F_173 ( & V_144 , NULL , V_40 ,
F_183 ) ;
F_136 ( & V_180 ) ;
F_139 ( & V_40 -> V_153 ,
F_132 ( V_40 ) ) ;
F_140 (client, next, &adap->userspace_clients,
detected) {
F_59 ( & V_40 -> V_39 , L_60 , V_44 -> V_86 ,
V_44 -> V_12 ) ;
F_141 ( & V_44 -> V_154 ) ;
F_124 ( V_44 ) ;
}
F_136 ( & V_40 -> V_153 ) ;
F_108 ( & V_40 -> V_39 , NULL , F_181 ) ;
F_108 ( & V_40 -> V_39 , NULL , F_182 ) ;
#ifdef F_170
F_187 ( V_177 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
#endif
F_59 ( & V_40 -> V_39 , L_63 , V_40 -> V_86 ) ;
F_188 ( & V_40 -> V_146 ) ;
F_125 ( & V_40 -> V_39 ) ;
F_189 ( & V_40 -> V_146 ) ;
F_134 ( & V_180 ) ;
F_174 ( & V_181 , V_40 -> V_162 ) ;
F_136 ( & V_180 ) ;
memset ( & V_40 -> V_39 , 0 , sizeof( V_40 -> V_39 ) ) ;
}
int F_190 ( void * V_4 , int (* F_191)( struct V_87 * , void * ) )
{
int V_151 ;
F_134 ( & V_180 ) ;
V_151 = F_192 ( & V_144 , NULL , V_4 , F_191 ) ;
F_136 ( & V_180 ) ;
return V_151 ;
}
static int F_193 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type != & V_137 )
return 0 ;
return F_161 ( V_4 , F_100 ( V_39 ) ) ;
}
int F_194 ( struct V_186 * V_187 , struct V_90 * V_91 )
{
int V_151 ;
if ( F_165 ( F_166 ( ! V_144 . V_171 ) ) )
return - V_172 ;
V_91 -> V_91 . V_187 = V_187 ;
V_91 -> V_91 . V_143 = & V_144 ;
V_151 = F_195 ( & V_91 -> V_91 ) ;
if ( V_151 )
return V_151 ;
if ( V_91 -> V_123 )
F_196 ( L_64 ,
V_91 -> V_91 . V_86 ) ;
if ( V_91 -> V_124 )
F_196 ( L_65 ,
V_91 -> V_91 . V_86 ) ;
F_186 ( L_66 , V_91 -> V_91 . V_86 ) ;
F_10 ( & V_91 -> V_188 ) ;
F_190 ( V_91 , F_193 ) ;
return 0 ;
}
static int F_197 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type == & V_137 )
F_180 ( V_4 , F_100 ( V_39 ) ) ;
return 0 ;
}
void F_198 ( struct V_90 * V_91 )
{
F_190 ( V_91 , F_197 ) ;
F_199 ( & V_91 -> V_91 ) ;
F_186 ( L_67 , V_91 -> V_91 . V_86 ) ;
}
struct V_43 * F_200 ( struct V_43 * V_44 )
{
if ( V_44 && F_201 ( & V_44 -> V_39 ) )
return V_44 ;
return NULL ;
}
void F_202 ( struct V_43 * V_44 )
{
if ( V_44 )
F_203 ( & V_44 -> V_39 ) ;
}
static int F_204 ( struct V_87 * V_39 , void * V_189 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_190 * V_191 = V_189 ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_44 -> V_39 . V_91 )
return 0 ;
V_91 = F_54 ( V_44 -> V_39 . V_91 ) ;
if ( V_91 -> V_56 )
V_91 -> V_56 ( V_44 , V_191 -> V_45 , V_191 -> V_191 ) ;
return 0 ;
}
void F_205 ( struct V_25 * V_40 , unsigned int V_45 , void * V_191 )
{
struct V_190 V_192 ;
V_192 . V_45 = V_45 ;
V_192 . V_191 = V_191 ;
F_108 ( & V_40 -> V_39 , & V_192 , F_204 ) ;
}
static int F_206 ( struct V_193 * V_194 , unsigned long V_66 ,
void * V_191 )
{
struct V_195 * V_196 = V_191 ;
struct V_25 * V_40 ;
struct V_43 * V_44 ;
switch ( F_207 ( V_66 , V_196 ) ) {
case V_197 :
V_40 = F_160 ( V_196 -> V_198 -> V_41 ) ;
if ( V_40 == NULL )
return V_199 ;
V_44 = F_147 ( V_40 , V_196 -> V_198 ) ;
F_203 ( & V_40 -> V_39 ) ;
if ( F_208 ( V_44 ) ) {
F_167 ( L_68 ,
V_200 , V_196 -> V_198 -> V_168 ) ;
return F_209 ( F_210 ( V_44 ) ) ;
}
break;
case V_201 :
V_44 = F_158 ( V_196 -> V_198 ) ;
if ( V_44 == NULL )
return V_199 ;
F_124 ( V_44 ) ;
F_203 ( & V_44 -> V_39 ) ;
break;
}
return V_199 ;
}
static int T_12 F_211 ( void )
{
int V_202 ;
V_202 = F_212 ( & V_144 ) ;
if ( V_202 )
return V_202 ;
#ifdef F_170
V_177 = F_213 ( L_69 ) ;
if ( ! V_177 ) {
V_202 = - V_82 ;
goto V_203;
}
#endif
V_202 = F_214 ( & V_204 ) ;
if ( V_202 )
goto V_205;
if ( F_215 ( V_206 ) )
F_166 ( F_216 ( & V_207 ) ) ;
return 0 ;
V_205:
#ifdef F_170
F_217 ( V_177 ) ;
V_203:
#endif
F_218 ( & V_144 ) ;
return V_202 ;
}
static void T_13 F_219 ( void )
{
if ( F_215 ( V_206 ) )
F_166 ( F_220 ( & V_207 ) ) ;
F_198 ( & V_204 ) ;
#ifdef F_170
F_217 ( V_177 ) ;
#endif
F_218 ( & V_144 ) ;
F_221 () ;
}
int F_222 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_208 )
{
unsigned long V_209 ;
int V_31 , V_210 ;
if ( F_223 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_208 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_224 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
else
F_225 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
}
V_209 = V_211 ;
for ( V_31 = 0 , V_210 = 0 ; V_210 <= V_40 -> V_212 ; V_210 ++ ) {
V_31 = V_40 -> V_174 -> V_213 ( V_40 , V_48 , V_208 ) ;
if ( V_31 != - V_172 )
break;
if ( F_226 ( V_211 , V_209 + V_40 -> V_175 ) )
break;
}
if ( F_223 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_31 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_227 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
F_228 ( V_40 , V_107 , V_31 ) ;
}
return V_31 ;
}
int F_24 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_208 )
{
int V_31 ;
if ( V_40 -> V_174 -> V_213 ) {
#ifdef F_229
for ( V_31 = 0 ; V_31 < V_208 ; V_31 ++ ) {
F_59 ( & V_40 -> V_39 , L_70
L_71 , V_31 , ( V_48 [ V_31 ] . V_16 & V_54 )
? 'R' : 'W' , V_48 [ V_31 ] . V_12 , V_48 [ V_31 ] . V_52 ,
( V_48 [ V_31 ] . V_16 & V_214 ) ? L_72 : L_73 ) ;
}
#endif
if ( F_230 () || F_231 () ) {
V_31 = F_113 ( V_40 ) ;
if ( ! V_31 )
return - V_172 ;
} else {
F_111 ( V_40 ) ;
}
V_31 = F_222 ( V_40 , V_48 , V_208 ) ;
F_115 ( V_40 ) ;
return V_31 ;
} else {
F_59 ( & V_40 -> V_39 , L_74 ) ;
return - V_115 ;
}
}
int F_232 ( const struct V_43 * V_44 , const char * V_53 , int V_148 )
{
int V_31 ;
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_215 ;
V_215 . V_12 = V_44 -> V_12 ;
V_215 . V_16 = V_44 -> V_16 & V_216 ;
V_215 . V_52 = V_148 ;
V_215 . V_53 = ( char * ) V_53 ;
V_31 = F_24 ( V_40 , & V_215 , 1 ) ;
return ( V_31 == 1 ) ? V_148 : V_31 ;
}
int F_233 ( const struct V_43 * V_44 , char * V_53 , int V_148 )
{
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_215 ;
int V_31 ;
V_215 . V_12 = V_44 -> V_12 ;
V_215 . V_16 = V_44 -> V_16 & V_216 ;
V_215 . V_16 |= V_54 ;
V_215 . V_52 = V_148 ;
V_215 . V_53 = V_53 ;
V_31 = F_24 ( V_40 , & V_215 , 1 ) ;
return ( V_31 == 1 ) ? V_148 : V_31 ;
}
static int F_234 ( struct V_25 * V_40 , unsigned short V_12 )
{
int V_71 ;
union V_217 V_184 ;
#ifdef F_235
if ( V_12 == 0x73 && ( V_40 -> V_218 & V_219 )
&& F_236 ( V_40 , V_220 ) )
V_71 = F_237 ( V_40 , V_12 , 0 , V_221 , 0 ,
V_222 , & V_184 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_236 ( V_40 , V_223 ) )
V_71 = F_237 ( V_40 , V_12 , 0 , V_224 , 0 ,
V_225 , NULL ) ;
else if ( F_236 ( V_40 , V_226 ) )
V_71 = F_237 ( V_40 , V_12 , 0 , V_221 , 0 ,
V_227 , & V_184 ) ;
else {
F_21 ( & V_40 -> V_39 , L_75 ,
V_12 ) ;
V_71 = - V_115 ;
}
return V_71 >= 0 ;
}
static int F_238 ( struct V_43 * V_228 ,
struct V_90 * V_91 )
{
struct V_5 V_6 ;
struct V_25 * V_26 = V_228 -> V_26 ;
int V_12 = V_228 -> V_12 ;
int V_71 ;
V_71 = F_104 ( V_12 ) ;
if ( V_71 ) {
F_21 ( & V_26 -> V_39 , L_76 ,
V_12 ) ;
return V_71 ;
}
if ( F_110 ( V_26 , V_12 ) )
return 0 ;
if ( ! F_234 ( V_26 , V_12 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_12 = V_12 ;
V_71 = V_91 -> V_229 ( V_228 , & V_6 ) ;
if ( V_71 ) {
return V_71 == - V_81 ? 0 : V_71 ;
}
if ( V_6 . type [ 0 ] == '\0' ) {
F_16 ( & V_26 -> V_39 , L_77
L_78 , V_91 -> V_91 . V_86 ,
V_12 ) ;
} else {
struct V_43 * V_44 ;
if ( V_26 -> V_218 & V_230 )
F_21 ( & V_26 -> V_39 ,
L_79
L_80
L_81 ,
V_6 . V_12 ) ;
F_59 ( & V_26 -> V_39 , L_82 ,
V_6 . type , V_6 . V_12 ) ;
V_44 = F_15 ( V_26 , & V_6 ) ;
if ( V_44 )
F_135 ( & V_44 -> V_154 , & V_91 -> V_188 ) ;
else
F_16 ( & V_26 -> V_39 , L_83 ,
V_6 . type , V_6 . V_12 ) ;
}
return 0 ;
}
static int F_162 ( struct V_25 * V_26 , struct V_90 * V_91 )
{
const unsigned short * V_231 ;
struct V_43 * V_228 ;
int V_107 , V_71 = 0 ;
int V_232 = F_121 ( V_26 ) ;
V_231 = V_91 -> V_231 ;
if ( ! V_91 -> V_229 || ! V_231 )
return 0 ;
if ( V_26 -> V_218 == V_230 ) {
F_59 ( & V_26 -> V_39 ,
L_84
L_85
L_86 ,
V_91 -> V_91 . V_86 ) ;
return 0 ;
}
if ( ! ( V_26 -> V_218 & V_91 -> V_218 ) )
return 0 ;
V_228 = F_23 ( sizeof( struct V_43 ) , V_50 ) ;
if ( ! V_228 )
return - V_82 ;
V_228 -> V_26 = V_26 ;
for ( V_107 = 0 ; V_231 [ V_107 ] != V_233 ; V_107 += 1 ) {
F_59 ( & V_26 -> V_39 , L_87
L_88 , V_232 , V_231 [ V_107 ] ) ;
V_228 -> V_12 = V_231 [ V_107 ] ;
V_71 = F_238 ( V_228 , V_91 ) ;
if ( F_165 ( V_71 ) )
break;
}
F_26 ( V_228 ) ;
return V_71 ;
}
int F_239 ( struct V_25 * V_40 , unsigned short V_12 )
{
return F_237 ( V_40 , V_12 , 0 , V_221 , 0 ,
V_225 , NULL ) >= 0 ;
}
struct V_43 *
F_240 ( struct V_25 * V_40 ,
struct V_5 * V_6 ,
unsigned short const * V_234 ,
int (* V_119)( struct V_25 * , unsigned short V_12 ) )
{
int V_107 ;
if ( ! V_119 )
V_119 = F_234 ;
for ( V_107 = 0 ; V_234 [ V_107 ] != V_233 ; V_107 ++ ) {
if ( F_104 ( V_234 [ V_107 ] ) < 0 ) {
F_21 ( & V_40 -> V_39 , L_89
L_90 , V_234 [ V_107 ] ) ;
continue;
}
if ( F_110 ( V_40 , V_234 [ V_107 ] ) ) {
F_59 ( & V_40 -> V_39 , L_91
L_92 , V_234 [ V_107 ] ) ;
continue;
}
if ( V_119 ( V_40 , V_234 [ V_107 ] ) )
break;
}
if ( V_234 [ V_107 ] == V_233 ) {
F_59 ( & V_40 -> V_39 , L_93 ) ;
return NULL ;
}
V_6 -> V_12 = V_234 [ V_107 ] ;
return F_15 ( V_40 , V_6 ) ;
}
struct V_25 * F_241 ( int V_162 )
{
struct V_25 * V_26 ;
F_134 ( & V_180 ) ;
V_26 = F_185 ( & V_181 , V_162 ) ;
if ( V_26 && ! F_242 ( V_26 -> V_187 ) )
V_26 = NULL ;
F_136 ( & V_180 ) ;
return V_26 ;
}
void F_243 ( struct V_25 * V_40 )
{
if ( V_40 )
F_244 ( V_40 -> V_187 ) ;
}
static T_4 F_245 ( T_9 V_4 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_235 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_246 ( T_4 V_236 , T_4 * V_171 , T_10 V_148 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_148 ; V_107 ++ )
V_236 = F_245 ( ( V_236 ^ V_171 [ V_107 ] ) << 8 ) ;
return V_236 ;
}
static T_4 F_247 ( T_4 V_237 , struct V_47 * V_215 )
{
T_4 V_12 = ( V_215 -> V_12 << 1 ) | ! ! ( V_215 -> V_16 & V_54 ) ;
V_237 = F_246 ( V_237 , & V_12 , 1 ) ;
return F_246 ( V_237 , V_215 -> V_53 , V_215 -> V_52 ) ;
}
static inline void F_248 ( struct V_47 * V_215 )
{
V_215 -> V_53 [ V_215 -> V_52 ] = F_247 ( 0 , V_215 ) ;
V_215 -> V_52 ++ ;
}
static int F_249 ( T_4 V_238 , struct V_47 * V_215 )
{
T_4 V_239 = V_215 -> V_53 [ -- V_215 -> V_52 ] ;
V_238 = F_247 ( V_238 , V_215 ) ;
if ( V_239 != V_238 ) {
F_186 ( L_94 ,
V_239 , V_238 ) ;
return - V_240 ;
}
return 0 ;
}
T_14 F_30 ( const struct V_43 * V_44 )
{
union V_217 V_4 ;
int V_33 ;
V_33 = F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_221 , 0 ,
V_227 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_241 ;
}
T_14 F_31 ( const struct V_43 * V_44 , T_4 V_242 )
{
return F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_224 , V_242 , V_227 , NULL ) ;
}
T_14 F_32 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_217 V_4 ;
int V_33 ;
V_33 = F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_221 , V_56 ,
V_222 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_241 ;
}
T_14 F_33 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_242 )
{
union V_217 V_4 ;
V_4 . V_241 = V_242 ;
return F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_224 , V_56 ,
V_222 , & V_4 ) ;
}
T_14 F_34 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_217 V_4 ;
int V_33 ;
V_33 = F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_221 , V_56 ,
V_243 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_244 ;
}
T_14 F_35 ( const struct V_43 * V_44 , T_4 V_56 ,
T_9 V_242 )
{
union V_217 V_4 ;
V_4 . V_244 = V_242 ;
return F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_224 , V_56 ,
V_243 , & V_4 ) ;
}
T_14 F_36 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 * V_245 )
{
union V_217 V_4 ;
int V_33 ;
V_33 = F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_221 , V_56 ,
V_246 , & V_4 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_245 , & V_4 . V_247 [ 1 ] , V_4 . V_247 [ 0 ] ) ;
return V_4 . V_247 [ 0 ] ;
}
T_14 F_37 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_245 )
{
union V_217 V_4 ;
if ( V_69 > V_248 )
V_69 = V_248 ;
V_4 . V_247 [ 0 ] = V_69 ;
memcpy ( & V_4 . V_247 [ 1 ] , V_245 , V_69 ) ;
return F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_224 , V_56 ,
V_246 , & V_4 ) ;
}
T_14 F_250 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , T_4 * V_245 )
{
union V_217 V_4 ;
int V_33 ;
if ( V_69 > V_248 )
V_69 = V_248 ;
V_4 . V_247 [ 0 ] = V_69 ;
V_33 = F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_221 , V_56 ,
V_249 , & V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
memcpy ( V_245 , & V_4 . V_247 [ 1 ] , V_4 . V_247 [ 0 ] ) ;
return V_4 . V_247 [ 0 ] ;
}
T_14 F_251 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_245 )
{
union V_217 V_4 ;
if ( V_69 > V_248 )
V_69 = V_248 ;
V_4 . V_247 [ 0 ] = V_69 ;
memcpy ( V_4 . V_247 + 1 , V_245 , V_69 ) ;
return F_237 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_224 , V_56 ,
V_249 , & V_4 ) ;
}
static T_14 F_252 ( struct V_25 * V_26 , T_9 V_12 ,
unsigned short V_16 ,
char V_250 , T_4 V_56 , int V_251 ,
union V_217 * V_4 )
{
unsigned char V_252 [ V_248 + 3 ] ;
unsigned char V_253 [ V_248 + 2 ] ;
int V_208 = V_250 == V_221 ? 2 : 1 ;
int V_107 ;
T_4 V_254 = 0 ;
int V_33 ;
struct V_47 V_215 [ 2 ] = {
{
. V_12 = V_12 ,
. V_16 = V_16 ,
. V_52 = 1 ,
. V_53 = V_252 ,
} , {
. V_12 = V_12 ,
. V_16 = V_16 | V_54 ,
. V_52 = 0 ,
. V_53 = V_253 ,
} ,
} ;
V_252 [ 0 ] = V_56 ;
switch ( V_251 ) {
case V_225 :
V_215 [ 0 ] . V_52 = 0 ;
V_215 [ 0 ] . V_16 = V_16 | ( V_250 == V_221 ?
V_54 : 0 ) ;
V_208 = 1 ;
break;
case V_227 :
if ( V_250 == V_221 ) {
V_215 [ 0 ] . V_16 = V_54 | V_16 ;
V_208 = 1 ;
}
break;
case V_222 :
if ( V_250 == V_221 )
V_215 [ 1 ] . V_52 = 1 ;
else {
V_215 [ 0 ] . V_52 = 2 ;
V_252 [ 1 ] = V_4 -> V_241 ;
}
break;
case V_243 :
if ( V_250 == V_221 )
V_215 [ 1 ] . V_52 = 2 ;
else {
V_215 [ 0 ] . V_52 = 3 ;
V_252 [ 1 ] = V_4 -> V_244 & 0xff ;
V_252 [ 2 ] = V_4 -> V_244 >> 8 ;
}
break;
case V_255 :
V_208 = 2 ;
V_250 = V_221 ;
V_215 [ 0 ] . V_52 = 3 ;
V_215 [ 1 ] . V_52 = 2 ;
V_252 [ 1 ] = V_4 -> V_244 & 0xff ;
V_252 [ 2 ] = V_4 -> V_244 >> 8 ;
break;
case V_246 :
if ( V_250 == V_221 ) {
V_215 [ 1 ] . V_16 |= V_214 ;
V_215 [ 1 ] . V_52 = 1 ;
} else {
V_215 [ 0 ] . V_52 = V_4 -> V_247 [ 0 ] + 2 ;
if ( V_215 [ 0 ] . V_52 > V_248 + 2 ) {
F_16 ( & V_26 -> V_39 ,
L_95 ,
V_4 -> V_247 [ 0 ] ) ;
return - V_134 ;
}
for ( V_107 = 1 ; V_107 < V_215 [ 0 ] . V_52 ; V_107 ++ )
V_252 [ V_107 ] = V_4 -> V_247 [ V_107 - 1 ] ;
}
break;
case V_256 :
V_208 = 2 ;
V_250 = V_221 ;
if ( V_4 -> V_247 [ 0 ] > V_248 ) {
F_16 ( & V_26 -> V_39 ,
L_95 ,
V_4 -> V_247 [ 0 ] ) ;
return - V_134 ;
}
V_215 [ 0 ] . V_52 = V_4 -> V_247 [ 0 ] + 2 ;
for ( V_107 = 1 ; V_107 < V_215 [ 0 ] . V_52 ; V_107 ++ )
V_252 [ V_107 ] = V_4 -> V_247 [ V_107 - 1 ] ;
V_215 [ 1 ] . V_16 |= V_214 ;
V_215 [ 1 ] . V_52 = 1 ;
break;
case V_249 :
if ( V_250 == V_221 ) {
V_215 [ 1 ] . V_52 = V_4 -> V_247 [ 0 ] ;
} else {
V_215 [ 0 ] . V_52 = V_4 -> V_247 [ 0 ] + 1 ;
if ( V_215 [ 0 ] . V_52 > V_248 + 1 ) {
F_16 ( & V_26 -> V_39 ,
L_95 ,
V_4 -> V_247 [ 0 ] ) ;
return - V_134 ;
}
for ( V_107 = 1 ; V_107 <= V_4 -> V_247 [ 0 ] ; V_107 ++ )
V_252 [ V_107 ] = V_4 -> V_247 [ V_107 ] ;
}
break;
default:
F_16 ( & V_26 -> V_39 , L_96 , V_251 ) ;
return - V_115 ;
}
V_107 = ( ( V_16 & V_257 ) && V_251 != V_225
&& V_251 != V_249 ) ;
if ( V_107 ) {
if ( ! ( V_215 [ 0 ] . V_16 & V_54 ) ) {
if ( V_208 == 1 )
F_248 ( & V_215 [ 0 ] ) ;
else
V_254 = F_247 ( 0 , & V_215 [ 0 ] ) ;
}
if ( V_215 [ V_208 - 1 ] . V_16 & V_54 )
V_215 [ V_208 - 1 ] . V_52 ++ ;
}
V_33 = F_24 ( V_26 , V_215 , V_208 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_107 && ( V_215 [ V_208 - 1 ] . V_16 & V_54 ) ) {
V_33 = F_249 ( V_254 , & V_215 [ V_208 - 1 ] ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_250 == V_221 )
switch ( V_251 ) {
case V_227 :
V_4 -> V_241 = V_252 [ 0 ] ;
break;
case V_222 :
V_4 -> V_241 = V_253 [ 0 ] ;
break;
case V_243 :
case V_255 :
V_4 -> V_244 = V_253 [ 0 ] | ( V_253 [ 1 ] << 8 ) ;
break;
case V_249 :
for ( V_107 = 0 ; V_107 < V_4 -> V_247 [ 0 ] ; V_107 ++ )
V_4 -> V_247 [ V_107 + 1 ] = V_253 [ V_107 ] ;
break;
case V_246 :
case V_256 :
for ( V_107 = 0 ; V_107 < V_253 [ 0 ] + 1 ; V_107 ++ )
V_4 -> V_247 [ V_107 ] = V_253 [ V_107 ] ;
break;
}
return 0 ;
}
T_14 F_237 ( struct V_25 * V_26 , T_9 V_12 , unsigned short V_16 ,
char V_250 , T_4 V_56 , int V_258 ,
union V_217 * V_4 )
{
unsigned long V_209 ;
int V_210 ;
T_14 V_151 ;
F_253 ( V_26 , V_12 , V_16 , V_250 ,
V_56 , V_258 , V_4 ) ;
F_254 ( V_26 , V_12 , V_16 , V_250 ,
V_56 , V_258 ) ;
V_16 &= V_216 | V_257 | V_259 ;
if ( V_26 -> V_174 -> V_260 ) {
F_111 ( V_26 ) ;
V_209 = V_211 ;
for ( V_151 = 0 , V_210 = 0 ; V_210 <= V_26 -> V_212 ; V_210 ++ ) {
V_151 = V_26 -> V_174 -> V_260 ( V_26 , V_12 , V_16 ,
V_250 , V_56 ,
V_258 , V_4 ) ;
if ( V_151 != - V_172 )
break;
if ( F_226 ( V_211 ,
V_209 + V_26 -> V_175 ) )
break;
}
F_115 ( V_26 ) ;
if ( V_151 != - V_115 || ! V_26 -> V_174 -> V_213 )
goto V_261;
}
V_151 = F_252 ( V_26 , V_12 , V_16 , V_250 ,
V_56 , V_258 , V_4 ) ;
V_261:
F_255 ( V_26 , V_12 , V_16 , V_250 ,
V_56 , V_258 , V_4 ) ;
F_256 ( V_26 , V_12 , V_16 , V_250 ,
V_56 , V_258 , V_151 ) ;
return V_151 ;
}
int F_257 ( struct V_43 * V_44 , T_15 V_262 )
{
int V_31 ;
if ( ! V_44 || ! V_262 )
return - V_134 ;
if ( ! ( V_44 -> V_16 & V_17 ) ) {
V_31 = F_104 ( V_44 -> V_12 ) ;
if ( V_31 )
return V_31 ;
}
if ( ! V_44 -> V_26 -> V_174 -> V_263 )
return - V_115 ;
V_44 -> V_262 = V_262 ;
F_111 ( V_44 -> V_26 ) ;
V_31 = V_44 -> V_26 -> V_174 -> V_263 ( V_44 ) ;
F_115 ( V_44 -> V_26 ) ;
if ( V_31 )
V_44 -> V_262 = NULL ;
return V_31 ;
}
int F_258 ( struct V_43 * V_44 )
{
int V_31 ;
if ( ! V_44 -> V_26 -> V_174 -> V_264 )
return - V_115 ;
F_111 ( V_44 -> V_26 ) ;
V_31 = V_44 -> V_26 -> V_174 -> V_264 ( V_44 ) ;
F_115 ( V_44 -> V_26 ) ;
if ( V_31 == 0 )
V_44 -> V_262 = NULL ;
return V_31 ;
}
