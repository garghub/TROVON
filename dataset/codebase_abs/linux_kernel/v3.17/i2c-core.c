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
T_1 V_31 = V_32 ;
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
return 0 ;
}
static void F_44 ( struct V_25 * V_26 )
{
T_2 V_22 ;
struct V_63 * V_4 ;
T_1 V_33 ;
if ( ! V_26 -> V_39 . V_41 )
return;
V_22 = F_18 ( V_26 -> V_39 . V_41 ) ;
if ( ! V_22 )
return;
F_45 ( V_22 ,
V_83 ,
& F_28 ) ;
V_33 = F_46 ( V_22 , ( void * * ) & V_4 ) ;
if ( F_47 ( V_33 ) )
F_26 ( V_4 ) ;
F_43 ( V_22 ) ;
}
static inline void F_44 ( struct V_25 * V_26 )
{ }
static inline int F_40 ( struct V_25 * V_26 )
{ return 0 ; }
static const struct V_84 * F_48 ( const struct V_84 * V_85 ,
const struct V_43 * V_44 )
{
while ( V_85 -> V_86 [ 0 ] ) {
if ( strcmp ( V_44 -> V_86 , V_85 -> V_86 ) == 0 )
return V_85 ;
V_85 ++ ;
}
return NULL ;
}
static int F_49 ( struct V_87 * V_39 , struct V_88 * V_89 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 )
return 0 ;
if ( F_51 ( V_39 , V_89 ) )
return 1 ;
if ( F_52 ( V_39 , V_89 ) )
return 1 ;
V_91 = F_53 ( V_89 ) ;
if ( V_91 -> V_92 )
return F_48 ( V_91 -> V_92 , V_44 ) != NULL ;
return 0 ;
}
static int F_54 ( struct V_87 * V_39 , struct V_93 * V_94 )
{
struct V_43 * V_44 = F_55 ( V_39 ) ;
int V_95 ;
V_95 = F_56 ( V_39 , V_94 ) ;
if ( V_95 != - V_81 )
return V_95 ;
if ( F_57 ( V_94 , L_7 ,
V_96 , V_44 -> V_86 ) )
return - V_82 ;
F_58 ( V_39 , L_8 ) ;
return 0 ;
}
static int F_59 ( struct V_25 * V_40 )
{
return F_60 ( V_40 -> V_97 -> V_98 ) ;
}
static void F_61 ( struct V_25 * V_40 , int V_99 )
{
F_62 ( V_40 -> V_97 -> V_98 , V_99 ) ;
}
static int F_63 ( struct V_25 * V_40 )
{
return F_60 ( V_40 -> V_97 -> V_100 ) ;
}
static int F_64 ( struct V_25 * V_40 )
{
struct V_101 * V_102 = V_40 -> V_97 ;
struct V_87 * V_39 = & V_40 -> V_39 ;
int V_31 = 0 ;
V_31 = F_65 ( V_102 -> V_98 , V_103 |
V_104 , L_9 ) ;
if ( V_31 ) {
F_21 ( V_39 , L_10 , V_102 -> V_98 ) ;
return V_31 ;
}
if ( V_102 -> V_105 ) {
if ( F_65 ( V_102 -> V_100 , V_106 , L_11 ) ) {
F_21 ( V_39 , L_12 ,
V_102 -> V_100 ) ;
V_102 -> V_105 = NULL ;
}
}
return V_31 ;
}
static void F_66 ( struct V_25 * V_40 )
{
struct V_101 * V_102 = V_40 -> V_97 ;
if ( V_102 -> V_105 )
F_67 ( V_102 -> V_100 ) ;
F_67 ( V_102 -> V_98 ) ;
}
static int F_68 ( struct V_25 * V_40 )
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
F_69 ( V_113 ) ;
}
if ( V_102 -> V_114 )
V_102 -> V_114 ( V_102 ) ;
return V_31 ;
}
int F_70 ( struct V_25 * V_40 )
{
V_40 -> V_97 -> V_112 ( V_40 , 1 ) ;
return F_68 ( V_40 ) ;
}
int F_71 ( struct V_25 * V_40 )
{
int V_31 ;
V_31 = F_64 ( V_40 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_68 ( V_40 ) ;
F_66 ( V_40 ) ;
return V_31 ;
}
int F_72 ( struct V_25 * V_40 )
{
if ( ! V_40 -> V_97 )
return - V_115 ;
F_58 ( & V_40 -> V_39 , L_14 ) ;
return V_40 -> V_97 -> V_116 ( V_40 ) ;
}
static int F_73 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
int V_33 ;
if ( ! V_44 )
return 0 ;
V_91 = F_53 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_117 || ! V_91 -> V_92 )
return - V_81 ;
if ( ! F_74 ( & V_44 -> V_39 ) )
F_75 ( & V_44 -> V_39 ,
V_44 -> V_16 & V_118 ) ;
F_58 ( V_39 , L_15 ) ;
V_33 = F_76 ( V_39 -> V_119 , false ) ;
if ( V_33 < 0 )
return V_33 ;
F_77 ( & V_44 -> V_39 , true ) ;
V_33 = V_91 -> V_117 ( V_44 , F_48 ( V_91 -> V_92 , V_44 ) ) ;
if ( V_33 )
F_78 ( & V_44 -> V_39 , true ) ;
return V_33 ;
}
static int F_79 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
int V_33 = 0 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_53 ( V_39 -> V_91 ) ;
if ( V_91 -> remove ) {
F_58 ( V_39 , L_16 ) ;
V_33 = V_91 -> remove ( V_44 ) ;
}
F_78 ( & V_44 -> V_39 , true ) ;
return V_33 ;
}
static void F_80 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return;
V_91 = F_53 ( V_39 -> V_91 ) ;
if ( V_91 -> V_120 )
V_91 -> V_120 ( V_44 ) ;
}
static int F_81 ( struct V_87 * V_39 , T_7 V_121 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_53 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_122 )
return 0 ;
return V_91 -> V_122 ( V_44 , V_121 ) ;
}
static int F_82 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return 0 ;
V_91 = F_53 ( V_39 -> V_91 ) ;
if ( ! V_91 -> V_123 )
return 0 ;
return V_91 -> V_123 ( V_44 ) ;
}
static int F_83 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_84 ( V_39 ) ;
else
return F_81 ( V_39 , V_126 ) ;
}
static int F_85 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_86 ( V_39 ) ;
else
return F_82 ( V_39 ) ;
}
static int F_87 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_88 ( V_39 ) ;
else
return F_81 ( V_39 , V_127 ) ;
}
static int F_89 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_90 ( V_39 ) ;
else
return F_82 ( V_39 ) ;
}
static int F_91 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_92 ( V_39 ) ;
else
return F_81 ( V_39 , V_128 ) ;
}
static int F_93 ( struct V_87 * V_39 )
{
const struct V_124 * V_125 = V_39 -> V_91 ? V_39 -> V_91 -> V_125 : NULL ;
if ( V_125 )
return F_94 ( V_39 ) ;
else
return F_82 ( V_39 ) ;
}
static void F_95 ( struct V_87 * V_39 )
{
F_26 ( F_55 ( V_39 ) ) ;
}
static T_8
F_96 ( struct V_87 * V_39 , struct V_129 * V_130 , char * V_53 )
{
return sprintf ( V_53 , L_17 , V_39 -> type == & V_131 ?
F_55 ( V_39 ) -> V_86 : F_97 ( V_39 ) -> V_86 ) ;
}
static T_8
F_98 ( struct V_87 * V_39 , struct V_129 * V_130 , char * V_53 )
{
struct V_43 * V_44 = F_55 ( V_39 ) ;
int V_52 ;
V_52 = F_99 ( V_39 , V_53 , V_132 - 1 ) ;
if ( V_52 != - V_81 )
return V_52 ;
return sprintf ( V_53 , L_18 , V_96 , V_44 -> V_86 ) ;
}
struct V_43 * F_50 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_131 )
? F_55 ( V_39 )
: NULL ;
}
static int F_100 ( const struct V_43 * V_44 )
{
if ( V_44 -> V_16 & V_17 ) {
if ( V_44 -> V_12 > 0x3ff )
return - V_133 ;
} else {
if ( V_44 -> V_12 == 0x00 || V_44 -> V_12 > 0x7f )
return - V_133 ;
}
return 0 ;
}
static int F_101 ( unsigned short V_12 )
{
if ( V_12 < 0x08 || V_12 > 0x77 )
return - V_133 ;
return 0 ;
}
static int F_102 ( struct V_87 * V_39 , void * V_134 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
int V_12 = * ( int * ) V_134 ;
if ( V_44 && V_44 -> V_12 == V_12 )
return - V_111 ;
return 0 ;
}
static int F_103 ( struct V_25 * V_26 , int V_12 )
{
struct V_25 * V_41 = F_104 ( V_26 ) ;
int V_135 ;
V_135 = F_105 ( & V_26 -> V_39 , & V_12 ,
F_102 ) ;
if ( ! V_135 && V_41 )
V_135 = F_103 ( V_41 , V_12 ) ;
return V_135 ;
}
static int F_106 ( struct V_87 * V_39 , void * V_134 )
{
int V_135 ;
if ( V_39 -> type == & V_136 )
V_135 = F_105 ( V_39 , V_134 ,
F_106 ) ;
else
V_135 = F_102 ( V_39 , V_134 ) ;
return V_135 ;
}
static int F_107 ( struct V_25 * V_26 , int V_12 )
{
struct V_25 * V_41 = F_104 ( V_26 ) ;
int V_135 = 0 ;
if ( V_41 )
V_135 = F_103 ( V_41 , V_12 ) ;
if ( ! V_135 )
V_135 = F_105 ( & V_26 -> V_39 , & V_12 ,
F_106 ) ;
return V_135 ;
}
void F_108 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_104 ( V_26 ) ;
if ( V_41 )
F_108 ( V_41 ) ;
else
F_109 ( & V_26 -> V_137 ) ;
}
static int F_110 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_104 ( V_26 ) ;
if ( V_41 )
return F_110 ( V_41 ) ;
else
return F_111 ( & V_26 -> V_137 ) ;
}
void F_112 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_104 ( V_26 ) ;
if ( V_41 )
F_112 ( V_41 ) ;
else
F_113 ( & V_26 -> V_137 ) ;
}
static void F_114 ( struct V_25 * V_40 ,
struct V_43 * V_44 )
{
struct V_29 * V_30 = F_115 ( & V_44 -> V_39 ) ;
if ( V_30 ) {
F_116 ( & V_44 -> V_39 , L_19 , F_117 ( V_30 ) ) ;
return;
}
F_116 ( & V_44 -> V_39 , L_20 , F_118 ( V_40 ) ,
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
V_44 -> V_39 . V_138 = V_6 -> V_138 ;
if ( V_6 -> V_139 )
V_44 -> V_39 . V_139 = * V_6 -> V_139 ;
V_44 -> V_16 = V_6 -> V_16 ;
V_44 -> V_12 = V_6 -> V_12 ;
V_44 -> V_18 = V_6 -> V_18 ;
F_13 ( V_44 -> V_86 , V_6 -> type , sizeof( V_44 -> V_86 ) ) ;
V_33 = F_100 ( V_44 ) ;
if ( V_33 ) {
F_16 ( & V_40 -> V_39 , L_21 ,
V_44 -> V_16 & V_17 ? 10 : 7 , V_44 -> V_12 ) ;
goto V_140;
}
V_33 = F_107 ( V_40 , V_44 -> V_12 ) ;
if ( V_33 )
goto V_141;
V_44 -> V_39 . V_41 = & V_44 -> V_26 -> V_39 ;
V_44 -> V_39 . V_142 = & V_143 ;
V_44 -> V_39 . type = & V_131 ;
V_44 -> V_39 . V_119 = V_6 -> V_119 ;
F_119 ( & V_44 -> V_39 , V_6 -> V_35 . V_36 ) ;
F_114 ( V_40 , V_44 ) ;
V_33 = F_120 ( & V_44 -> V_39 ) ;
if ( V_33 )
goto V_141;
F_58 ( & V_40 -> V_39 , L_22 ,
V_44 -> V_86 , F_14 ( & V_44 -> V_39 ) ) ;
return V_44 ;
V_141:
F_16 ( & V_40 -> V_39 , L_23
L_24 , V_44 -> V_86 , V_44 -> V_12 , V_33 ) ;
V_140:
F_26 ( V_44 ) ;
return NULL ;
}
void F_121 ( struct V_43 * V_44 )
{
F_122 ( & V_44 -> V_39 ) ;
}
static int F_123 ( struct V_43 * V_44 ,
const struct V_84 * V_85 )
{
return 0 ;
}
static int F_124 ( struct V_43 * V_44 )
{
return 0 ;
}
struct V_43 * F_125 ( struct V_25 * V_26 , T_9 V_144 )
{
struct V_5 V_6 = {
F_126 ( L_25 , V_144 ) ,
} ;
return F_15 ( V_26 , & V_6 ) ;
}
static void F_127 ( struct V_87 * V_39 )
{
struct V_25 * V_40 = F_97 ( V_39 ) ;
F_128 ( & V_40 -> V_145 ) ;
}
static inline unsigned int F_129 ( struct V_25 * V_26 )
{
unsigned int V_146 = 0 ;
while ( ( V_26 = F_104 ( V_26 ) ) )
V_146 ++ ;
return V_146 ;
}
static T_8
F_130 ( struct V_87 * V_39 , struct V_129 * V_130 ,
const char * V_53 , T_10 V_147 )
{
struct V_25 * V_40 = F_97 ( V_39 ) ;
struct V_5 V_6 ;
struct V_43 * V_44 ;
char * V_148 , V_149 ;
int V_150 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_148 = strchr ( V_53 , ' ' ) ;
if ( ! V_148 ) {
F_16 ( V_39 , L_26 , L_27 ) ;
return - V_133 ;
}
if ( V_148 - V_53 > V_151 - 1 ) {
F_16 ( V_39 , L_28 , L_27 ) ;
return - V_133 ;
}
memcpy ( V_6 . type , V_53 , V_148 - V_53 ) ;
V_150 = sscanf ( ++ V_148 , L_29 , & V_6 . V_12 , & V_149 ) ;
if ( V_150 < 1 ) {
F_16 ( V_39 , L_30 , L_27 ) ;
return - V_133 ;
}
if ( V_150 > 1 && V_149 != '\n' ) {
F_16 ( V_39 , L_31 , L_27 ) ;
return - V_133 ;
}
V_44 = F_15 ( V_40 , & V_6 ) ;
if ( ! V_44 )
return - V_133 ;
F_131 ( & V_40 -> V_152 ) ;
F_132 ( & V_44 -> V_153 , & V_40 -> V_154 ) ;
F_133 ( & V_40 -> V_152 ) ;
F_134 ( V_39 , L_32 , L_27 ,
V_6 . type , V_6 . V_12 ) ;
return V_147 ;
}
static T_8
F_135 ( struct V_87 * V_39 , struct V_129 * V_130 ,
const char * V_53 , T_10 V_147 )
{
struct V_25 * V_40 = F_97 ( V_39 ) ;
struct V_43 * V_44 , * V_155 ;
unsigned short V_12 ;
char V_149 ;
int V_150 ;
V_150 = sscanf ( V_53 , L_29 , & V_12 , & V_149 ) ;
if ( V_150 < 1 ) {
F_16 ( V_39 , L_30 , L_33 ) ;
return - V_133 ;
}
if ( V_150 > 1 && V_149 != '\n' ) {
F_16 ( V_39 , L_31 , L_33 ) ;
return - V_133 ;
}
V_150 = - V_156 ;
F_136 ( & V_40 -> V_152 ,
F_129 ( V_40 ) ) ;
F_137 (client, next, &adap->userspace_clients,
detected) {
if ( V_44 -> V_12 == V_12 ) {
F_134 ( V_39 , L_34 ,
L_33 , V_44 -> V_86 , V_44 -> V_12 ) ;
F_138 ( & V_44 -> V_153 ) ;
F_121 ( V_44 ) ;
V_150 = V_147 ;
break;
}
}
F_133 ( & V_40 -> V_152 ) ;
if ( V_150 < 0 )
F_16 ( V_39 , L_35 ,
L_33 ) ;
return V_150 ;
}
struct V_25 * F_139 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_136 )
? F_97 ( V_39 )
: NULL ;
}
static void F_140 ( struct V_25 * V_26 )
{
struct V_157 * V_158 ;
F_141 ( & V_159 ) ;
F_142 (devinfo, &__i2c_board_list, list) {
if ( V_158 -> V_160 == V_26 -> V_161
&& ! F_15 ( V_26 ,
& V_158 -> V_162 ) )
F_16 ( & V_26 -> V_39 ,
L_36 ,
V_158 -> V_162 . V_12 ) ;
}
F_143 ( & V_159 ) ;
}
static void F_144 ( struct V_25 * V_40 )
{
void * V_135 ;
struct V_163 * V_164 ;
if ( ! V_40 -> V_39 . V_119 )
return;
F_58 ( & V_40 -> V_39 , L_37 ) ;
F_145 (adap->dev.of_node, node) {
struct V_5 V_6 = {} ;
struct V_165 V_166 = {} ;
const T_11 * V_12 ;
int V_52 ;
F_58 ( & V_40 -> V_39 , L_38 , V_164 -> V_167 ) ;
if ( F_146 ( V_164 , V_6 . type , sizeof( V_6 . type ) ) < 0 ) {
F_16 ( & V_40 -> V_39 , L_39 ,
V_164 -> V_167 ) ;
continue;
}
V_12 = F_147 ( V_164 , L_40 , & V_52 ) ;
if ( ! V_12 || ( V_52 < sizeof( int ) ) ) {
F_16 ( & V_40 -> V_39 , L_41 ,
V_164 -> V_167 ) ;
continue;
}
V_6 . V_12 = F_148 ( V_12 ) ;
if ( V_6 . V_12 > ( 1 << 10 ) - 1 ) {
F_16 ( & V_40 -> V_39 , L_42 ,
V_6 . V_12 , V_164 -> V_167 ) ;
continue;
}
V_6 . V_18 = F_149 ( V_164 , 0 ) ;
V_6 . V_119 = F_150 ( V_164 ) ;
V_6 . V_139 = & V_166 ;
if ( F_147 ( V_164 , L_43 , NULL ) )
V_6 . V_16 |= V_118 ;
F_151 ( L_44 , V_96 , V_6 . type ) ;
V_135 = F_15 ( V_40 , & V_6 ) ;
if ( V_135 == NULL ) {
F_16 ( & V_40 -> V_39 , L_45 ,
V_164 -> V_167 ) ;
F_152 ( V_164 ) ;
F_153 ( V_6 . V_18 ) ;
continue;
}
}
}
static int F_154 ( struct V_87 * V_39 , void * V_4 )
{
return V_39 -> V_119 == V_4 ;
}
struct V_43 * F_155 ( struct V_163 * V_164 )
{
struct V_87 * V_39 ;
V_39 = F_156 ( & V_143 , NULL , V_164 ,
F_154 ) ;
if ( ! V_39 )
return NULL ;
return F_50 ( V_39 ) ;
}
struct V_25 * F_157 ( struct V_163 * V_164 )
{
struct V_87 * V_39 ;
V_39 = F_156 ( & V_143 , NULL , V_164 ,
F_154 ) ;
if ( ! V_39 )
return NULL ;
return F_139 ( V_39 ) ;
}
static void F_144 ( struct V_25 * V_40 ) { }
static int F_158 ( struct V_90 * V_91 ,
struct V_25 * V_40 )
{
F_159 ( V_40 , V_91 ) ;
if ( V_91 -> V_168 ) {
F_21 ( & V_40 -> V_39 , L_46 ,
V_91 -> V_91 . V_86 ) ;
F_21 ( & V_40 -> V_39 , L_47
L_48 ) ;
V_91 -> V_168 ( V_40 ) ;
}
return 0 ;
}
static int F_160 ( struct V_88 * V_169 , void * V_4 )
{
return F_158 ( F_53 ( V_169 ) , V_4 ) ;
}
static int F_161 ( struct V_25 * V_40 )
{
int V_150 = 0 ;
if ( F_162 ( F_163 ( ! V_143 . V_170 ) ) ) {
V_150 = - V_171 ;
goto V_172;
}
if ( F_162 ( V_40 -> V_86 [ 0 ] == '\0' ) ) {
F_164 ( L_49
L_50 ) ;
return - V_133 ;
}
if ( F_162 ( ! V_40 -> V_173 ) ) {
F_164 ( L_51
L_52 , V_40 -> V_86 ) ;
return - V_133 ;
}
F_165 ( & V_40 -> V_137 ) ;
F_166 ( & V_40 -> V_152 ) ;
F_10 ( & V_40 -> V_154 ) ;
if ( V_40 -> V_174 == 0 )
V_40 -> V_174 = V_175 ;
F_116 ( & V_40 -> V_39 , L_53 , V_40 -> V_161 ) ;
V_40 -> V_39 . V_142 = & V_143 ;
V_40 -> V_39 . type = & V_136 ;
V_150 = F_120 ( & V_40 -> V_39 ) ;
if ( V_150 )
goto V_172;
F_58 ( & V_40 -> V_39 , L_54 , V_40 -> V_86 ) ;
#ifdef F_167
V_150 = F_168 ( V_176 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
if ( V_150 )
F_21 ( & V_40 -> V_39 ,
L_55 ) ;
#endif
if ( V_40 -> V_97 ) {
struct V_101 * V_102 = V_40 -> V_97 ;
if ( ! V_102 -> V_116 ) {
F_16 ( & V_40 -> V_39 , L_56 ) ;
V_40 -> V_97 = NULL ;
goto V_177;
}
if ( V_102 -> V_116 == F_71 ) {
if ( ! F_169 ( V_102 -> V_98 ) ) {
F_16 ( & V_40 -> V_39 , L_57 ) ;
V_40 -> V_97 = NULL ;
goto V_177;
}
if ( F_169 ( V_102 -> V_100 ) )
V_102 -> V_105 = F_63 ;
else
V_102 -> V_105 = NULL ;
V_102 -> V_110 = F_59 ;
V_102 -> V_112 = F_61 ;
} else if ( ! V_102 -> V_112 || ! V_102 -> V_110 ) {
F_16 ( & V_40 -> V_39 , L_58 ) ;
V_40 -> V_97 = NULL ;
}
}
V_177:
F_144 ( V_40 ) ;
F_17 ( V_40 ) ;
F_40 ( V_40 ) ;
if ( V_40 -> V_161 < V_178 )
F_140 ( V_40 ) ;
F_131 ( & V_179 ) ;
F_170 ( & V_143 , NULL , V_40 , F_160 ) ;
F_133 ( & V_179 ) ;
return 0 ;
V_172:
F_131 ( & V_179 ) ;
F_171 ( & V_180 , V_40 -> V_161 ) ;
F_133 ( & V_179 ) ;
return V_150 ;
}
static int F_172 ( struct V_25 * V_40 )
{
int V_85 ;
F_131 ( & V_179 ) ;
V_85 = F_173 ( & V_180 , V_40 , V_40 -> V_161 , V_40 -> V_161 + 1 ,
V_50 ) ;
F_133 ( & V_179 ) ;
if ( V_85 < 0 )
return V_85 == - V_181 ? - V_111 : V_85 ;
return F_161 ( V_40 ) ;
}
int F_174 ( struct V_25 * V_26 )
{
struct V_87 * V_39 = & V_26 -> V_39 ;
int V_85 ;
if ( V_39 -> V_119 ) {
V_85 = F_175 ( V_39 -> V_119 , L_59 ) ;
if ( V_85 >= 0 ) {
V_26 -> V_161 = V_85 ;
return F_172 ( V_26 ) ;
}
}
F_131 ( & V_179 ) ;
V_85 = F_173 ( & V_180 , V_26 ,
V_178 , 0 , V_50 ) ;
F_133 ( & V_179 ) ;
if ( V_85 < 0 )
return V_85 ;
V_26 -> V_161 = V_85 ;
return F_161 ( V_26 ) ;
}
int F_176 ( struct V_25 * V_40 )
{
if ( V_40 -> V_161 == - 1 )
return F_174 ( V_40 ) ;
return F_172 ( V_40 ) ;
}
static void F_177 ( struct V_90 * V_91 ,
struct V_25 * V_26 )
{
struct V_43 * V_44 , * V_182 ;
F_137 (client, _n, &driver->clients, detected) {
if ( V_44 -> V_26 == V_26 ) {
F_58 ( & V_26 -> V_39 , L_60 ,
V_44 -> V_86 , V_44 -> V_12 ) ;
F_138 ( & V_44 -> V_153 ) ;
F_121 ( V_44 ) ;
}
}
}
static int F_178 ( struct V_87 * V_39 , void * V_183 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
if ( V_44 && strcmp ( V_44 -> V_86 , L_25 ) )
F_121 ( V_44 ) ;
return 0 ;
}
static int F_179 ( struct V_87 * V_39 , void * V_183 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
if ( V_44 )
F_121 ( V_44 ) ;
return 0 ;
}
static int F_180 ( struct V_88 * V_169 , void * V_4 )
{
F_177 ( F_53 ( V_169 ) , V_4 ) ;
return 0 ;
}
void F_181 ( struct V_25 * V_40 )
{
struct V_25 * V_184 ;
struct V_43 * V_44 , * V_155 ;
F_131 ( & V_179 ) ;
V_184 = F_182 ( & V_180 , V_40 -> V_161 ) ;
F_133 ( & V_179 ) ;
if ( V_184 != V_40 ) {
F_183 ( L_61
L_62 , V_40 -> V_86 ) ;
return;
}
F_44 ( V_40 ) ;
F_131 ( & V_179 ) ;
F_170 ( & V_143 , NULL , V_40 ,
F_180 ) ;
F_133 ( & V_179 ) ;
F_136 ( & V_40 -> V_152 ,
F_129 ( V_40 ) ) ;
F_137 (client, next, &adap->userspace_clients,
detected) {
F_58 ( & V_40 -> V_39 , L_60 , V_44 -> V_86 ,
V_44 -> V_12 ) ;
F_138 ( & V_44 -> V_153 ) ;
F_121 ( V_44 ) ;
}
F_133 ( & V_40 -> V_152 ) ;
F_105 ( & V_40 -> V_39 , NULL , F_178 ) ;
F_105 ( & V_40 -> V_39 , NULL , F_179 ) ;
#ifdef F_167
F_184 ( V_176 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
#endif
F_58 ( & V_40 -> V_39 , L_63 , V_40 -> V_86 ) ;
F_185 ( & V_40 -> V_145 ) ;
F_122 ( & V_40 -> V_39 ) ;
F_186 ( & V_40 -> V_145 ) ;
F_131 ( & V_179 ) ;
F_171 ( & V_180 , V_40 -> V_161 ) ;
F_133 ( & V_179 ) ;
memset ( & V_40 -> V_39 , 0 , sizeof( V_40 -> V_39 ) ) ;
}
int F_187 ( void * V_4 , int (* F_188)( struct V_87 * , void * ) )
{
int V_150 ;
F_131 ( & V_179 ) ;
V_150 = F_189 ( & V_143 , NULL , V_4 , F_188 ) ;
F_133 ( & V_179 ) ;
return V_150 ;
}
static int F_190 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type != & V_136 )
return 0 ;
return F_158 ( V_4 , F_97 ( V_39 ) ) ;
}
int F_191 ( struct V_185 * V_186 , struct V_90 * V_91 )
{
int V_150 ;
if ( F_162 ( F_163 ( ! V_143 . V_170 ) ) )
return - V_171 ;
V_91 -> V_91 . V_186 = V_186 ;
V_91 -> V_91 . V_142 = & V_143 ;
V_150 = F_192 ( & V_91 -> V_91 ) ;
if ( V_150 )
return V_150 ;
if ( V_91 -> V_122 )
F_193 ( L_64 ,
V_91 -> V_91 . V_86 ) ;
if ( V_91 -> V_123 )
F_193 ( L_65 ,
V_91 -> V_91 . V_86 ) ;
F_183 ( L_66 , V_91 -> V_91 . V_86 ) ;
F_10 ( & V_91 -> V_187 ) ;
F_187 ( V_91 , F_190 ) ;
return 0 ;
}
static int F_194 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type == & V_136 )
F_177 ( V_4 , F_97 ( V_39 ) ) ;
return 0 ;
}
void F_195 ( struct V_90 * V_91 )
{
F_187 ( V_91 , F_194 ) ;
F_196 ( & V_91 -> V_91 ) ;
F_183 ( L_67 , V_91 -> V_91 . V_86 ) ;
}
struct V_43 * F_197 ( struct V_43 * V_44 )
{
if ( V_44 && F_198 ( & V_44 -> V_39 ) )
return V_44 ;
return NULL ;
}
void F_199 ( struct V_43 * V_44 )
{
if ( V_44 )
F_200 ( & V_44 -> V_39 ) ;
}
static int F_201 ( struct V_87 * V_39 , void * V_188 )
{
struct V_43 * V_44 = F_50 ( V_39 ) ;
struct V_189 * V_190 = V_188 ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_44 -> V_39 . V_91 )
return 0 ;
V_91 = F_53 ( V_44 -> V_39 . V_91 ) ;
if ( V_91 -> V_56 )
V_91 -> V_56 ( V_44 , V_190 -> V_45 , V_190 -> V_190 ) ;
return 0 ;
}
void F_202 ( struct V_25 * V_40 , unsigned int V_45 , void * V_190 )
{
struct V_189 V_191 ;
V_191 . V_45 = V_45 ;
V_191 . V_190 = V_190 ;
F_105 ( & V_40 -> V_39 , & V_191 , F_201 ) ;
}
static int T_12 F_203 ( void )
{
int V_192 ;
V_192 = F_204 ( & V_143 ) ;
if ( V_192 )
return V_192 ;
#ifdef F_167
V_176 = F_205 ( L_68 ) ;
if ( ! V_176 ) {
V_192 = - V_82 ;
goto V_193;
}
#endif
V_192 = F_206 ( & V_194 ) ;
if ( V_192 )
goto V_195;
return 0 ;
V_195:
#ifdef F_167
F_207 ( V_176 ) ;
V_193:
#endif
F_208 ( & V_143 ) ;
return V_192 ;
}
static void T_13 F_209 ( void )
{
F_195 ( & V_194 ) ;
#ifdef F_167
F_207 ( V_176 ) ;
#endif
F_208 ( & V_143 ) ;
F_210 () ;
}
int F_211 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_196 )
{
unsigned long V_197 ;
int V_31 , V_198 ;
if ( F_212 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_196 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_213 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
else
F_214 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
}
V_197 = V_199 ;
for ( V_31 = 0 , V_198 = 0 ; V_198 <= V_40 -> V_200 ; V_198 ++ ) {
V_31 = V_40 -> V_173 -> V_201 ( V_40 , V_48 , V_196 ) ;
if ( V_31 != - V_171 )
break;
if ( F_215 ( V_199 , V_197 + V_40 -> V_174 ) )
break;
}
if ( F_212 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_31 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_216 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
F_217 ( V_40 , V_107 , V_31 ) ;
}
return V_31 ;
}
int F_24 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_196 )
{
int V_31 ;
if ( V_40 -> V_173 -> V_201 ) {
#ifdef F_218
for ( V_31 = 0 ; V_31 < V_196 ; V_31 ++ ) {
F_58 ( & V_40 -> V_39 , L_69
L_70 , V_31 , ( V_48 [ V_31 ] . V_16 & V_54 )
? 'R' : 'W' , V_48 [ V_31 ] . V_12 , V_48 [ V_31 ] . V_52 ,
( V_48 [ V_31 ] . V_16 & V_202 ) ? L_71 : L_72 ) ;
}
#endif
if ( F_219 () || F_220 () ) {
V_31 = F_110 ( V_40 ) ;
if ( ! V_31 )
return - V_171 ;
} else {
F_108 ( V_40 ) ;
}
V_31 = F_211 ( V_40 , V_48 , V_196 ) ;
F_112 ( V_40 ) ;
return V_31 ;
} else {
F_58 ( & V_40 -> V_39 , L_73 ) ;
return - V_115 ;
}
}
int F_221 ( const struct V_43 * V_44 , const char * V_53 , int V_147 )
{
int V_31 ;
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_203 ;
V_203 . V_12 = V_44 -> V_12 ;
V_203 . V_16 = V_44 -> V_16 & V_204 ;
V_203 . V_52 = V_147 ;
V_203 . V_53 = ( char * ) V_53 ;
V_31 = F_24 ( V_40 , & V_203 , 1 ) ;
return ( V_31 == 1 ) ? V_147 : V_31 ;
}
int F_222 ( const struct V_43 * V_44 , char * V_53 , int V_147 )
{
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_203 ;
int V_31 ;
V_203 . V_12 = V_44 -> V_12 ;
V_203 . V_16 = V_44 -> V_16 & V_204 ;
V_203 . V_16 |= V_54 ;
V_203 . V_52 = V_147 ;
V_203 . V_53 = V_53 ;
V_31 = F_24 ( V_40 , & V_203 , 1 ) ;
return ( V_31 == 1 ) ? V_147 : V_31 ;
}
static int F_223 ( struct V_25 * V_40 , unsigned short V_12 )
{
int V_71 ;
union V_205 V_183 ;
#ifdef F_224
if ( V_12 == 0x73 && ( V_40 -> V_206 & V_207 )
&& F_225 ( V_40 , V_208 ) )
V_71 = F_226 ( V_40 , V_12 , 0 , V_209 , 0 ,
V_210 , & V_183 ) ;
else
#endif
if ( ! ( ( V_12 & ~ 0x07 ) == 0x30 || ( V_12 & ~ 0x0f ) == 0x50 )
&& F_225 ( V_40 , V_211 ) )
V_71 = F_226 ( V_40 , V_12 , 0 , V_212 , 0 ,
V_213 , NULL ) ;
else if ( F_225 ( V_40 , V_214 ) )
V_71 = F_226 ( V_40 , V_12 , 0 , V_209 , 0 ,
V_215 , & V_183 ) ;
else {
F_21 ( & V_40 -> V_39 , L_74 ,
V_12 ) ;
V_71 = - V_115 ;
}
return V_71 >= 0 ;
}
static int F_227 ( struct V_43 * V_216 ,
struct V_90 * V_91 )
{
struct V_5 V_6 ;
struct V_25 * V_26 = V_216 -> V_26 ;
int V_12 = V_216 -> V_12 ;
int V_71 ;
V_71 = F_101 ( V_12 ) ;
if ( V_71 ) {
F_21 ( & V_26 -> V_39 , L_75 ,
V_12 ) ;
return V_71 ;
}
if ( F_107 ( V_26 , V_12 ) )
return 0 ;
if ( ! F_223 ( V_26 , V_12 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_12 = V_12 ;
V_71 = V_91 -> V_217 ( V_216 , & V_6 ) ;
if ( V_71 ) {
return V_71 == - V_81 ? 0 : V_71 ;
}
if ( V_6 . type [ 0 ] == '\0' ) {
F_16 ( & V_26 -> V_39 , L_76
L_77 , V_91 -> V_91 . V_86 ,
V_12 ) ;
} else {
struct V_43 * V_44 ;
if ( V_26 -> V_206 & V_218 )
F_21 ( & V_26 -> V_39 ,
L_78
L_79
L_80 ,
V_6 . V_12 ) ;
F_58 ( & V_26 -> V_39 , L_81 ,
V_6 . type , V_6 . V_12 ) ;
V_44 = F_15 ( V_26 , & V_6 ) ;
if ( V_44 )
F_132 ( & V_44 -> V_153 , & V_91 -> V_187 ) ;
else
F_16 ( & V_26 -> V_39 , L_82 ,
V_6 . type , V_6 . V_12 ) ;
}
return 0 ;
}
static int F_159 ( struct V_25 * V_26 , struct V_90 * V_91 )
{
const unsigned short * V_219 ;
struct V_43 * V_216 ;
int V_107 , V_71 = 0 ;
int V_220 = F_118 ( V_26 ) ;
V_219 = V_91 -> V_219 ;
if ( ! V_91 -> V_217 || ! V_219 )
return 0 ;
if ( V_26 -> V_206 == V_218 ) {
F_58 ( & V_26 -> V_39 ,
L_83
L_84
L_85 ,
V_91 -> V_91 . V_86 ) ;
return 0 ;
}
if ( ! ( V_26 -> V_206 & V_91 -> V_206 ) )
return 0 ;
V_216 = F_23 ( sizeof( struct V_43 ) , V_50 ) ;
if ( ! V_216 )
return - V_82 ;
V_216 -> V_26 = V_26 ;
for ( V_107 = 0 ; V_219 [ V_107 ] != V_221 ; V_107 += 1 ) {
F_58 ( & V_26 -> V_39 , L_86
L_87 , V_220 , V_219 [ V_107 ] ) ;
V_216 -> V_12 = V_219 [ V_107 ] ;
V_71 = F_227 ( V_216 , V_91 ) ;
if ( F_162 ( V_71 ) )
break;
}
F_26 ( V_216 ) ;
return V_71 ;
}
int F_228 ( struct V_25 * V_40 , unsigned short V_12 )
{
return F_226 ( V_40 , V_12 , 0 , V_209 , 0 ,
V_213 , NULL ) >= 0 ;
}
struct V_43 *
F_229 ( struct V_25 * V_40 ,
struct V_5 * V_6 ,
unsigned short const * V_222 ,
int (* V_117)( struct V_25 * , unsigned short V_12 ) )
{
int V_107 ;
if ( ! V_117 )
V_117 = F_223 ;
for ( V_107 = 0 ; V_222 [ V_107 ] != V_221 ; V_107 ++ ) {
if ( F_101 ( V_222 [ V_107 ] ) < 0 ) {
F_21 ( & V_40 -> V_39 , L_88
L_89 , V_222 [ V_107 ] ) ;
continue;
}
if ( F_107 ( V_40 , V_222 [ V_107 ] ) ) {
F_58 ( & V_40 -> V_39 , L_90
L_91 , V_222 [ V_107 ] ) ;
continue;
}
if ( V_117 ( V_40 , V_222 [ V_107 ] ) )
break;
}
if ( V_222 [ V_107 ] == V_221 ) {
F_58 ( & V_40 -> V_39 , L_92 ) ;
return NULL ;
}
V_6 -> V_12 = V_222 [ V_107 ] ;
return F_15 ( V_40 , V_6 ) ;
}
struct V_25 * F_230 ( int V_161 )
{
struct V_25 * V_26 ;
F_131 ( & V_179 ) ;
V_26 = F_182 ( & V_180 , V_161 ) ;
if ( V_26 && ! F_231 ( V_26 -> V_186 ) )
V_26 = NULL ;
F_133 ( & V_179 ) ;
return V_26 ;
}
void F_232 ( struct V_25 * V_40 )
{
if ( V_40 )
F_233 ( V_40 -> V_186 ) ;
}
static T_4 F_234 ( T_9 V_4 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_223 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_235 ( T_4 V_224 , T_4 * V_170 , T_10 V_147 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_147 ; V_107 ++ )
V_224 = F_234 ( ( V_224 ^ V_170 [ V_107 ] ) << 8 ) ;
return V_224 ;
}
static T_4 F_236 ( T_4 V_225 , struct V_47 * V_203 )
{
T_4 V_12 = ( V_203 -> V_12 << 1 ) | ! ! ( V_203 -> V_16 & V_54 ) ;
V_225 = F_235 ( V_225 , & V_12 , 1 ) ;
return F_235 ( V_225 , V_203 -> V_53 , V_203 -> V_52 ) ;
}
static inline void F_237 ( struct V_47 * V_203 )
{
V_203 -> V_53 [ V_203 -> V_52 ] = F_236 ( 0 , V_203 ) ;
V_203 -> V_52 ++ ;
}
static int F_238 ( T_4 V_226 , struct V_47 * V_203 )
{
T_4 V_227 = V_203 -> V_53 [ -- V_203 -> V_52 ] ;
V_226 = F_236 ( V_226 , V_203 ) ;
if ( V_227 != V_226 ) {
F_183 ( L_93 ,
V_227 , V_226 ) ;
return - V_228 ;
}
return 0 ;
}
T_14 F_30 ( const struct V_43 * V_44 )
{
union V_205 V_4 ;
int V_33 ;
V_33 = F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_209 , 0 ,
V_215 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_229 ;
}
T_14 F_31 ( const struct V_43 * V_44 , T_4 V_230 )
{
return F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_212 , V_230 , V_215 , NULL ) ;
}
T_14 F_32 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_205 V_4 ;
int V_33 ;
V_33 = F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_209 , V_56 ,
V_210 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_229 ;
}
T_14 F_33 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_230 )
{
union V_205 V_4 ;
V_4 . V_229 = V_230 ;
return F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_212 , V_56 ,
V_210 , & V_4 ) ;
}
T_14 F_34 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_205 V_4 ;
int V_33 ;
V_33 = F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_209 , V_56 ,
V_231 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_232 ;
}
T_14 F_35 ( const struct V_43 * V_44 , T_4 V_56 ,
T_9 V_230 )
{
union V_205 V_4 ;
V_4 . V_232 = V_230 ;
return F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_212 , V_56 ,
V_231 , & V_4 ) ;
}
T_14 F_36 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 * V_233 )
{
union V_205 V_4 ;
int V_33 ;
V_33 = F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_209 , V_56 ,
V_234 , & V_4 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_233 , & V_4 . V_235 [ 1 ] , V_4 . V_235 [ 0 ] ) ;
return V_4 . V_235 [ 0 ] ;
}
T_14 F_37 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_233 )
{
union V_205 V_4 ;
if ( V_69 > V_236 )
V_69 = V_236 ;
V_4 . V_235 [ 0 ] = V_69 ;
memcpy ( & V_4 . V_235 [ 1 ] , V_233 , V_69 ) ;
return F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_212 , V_56 ,
V_234 , & V_4 ) ;
}
T_14 F_239 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , T_4 * V_233 )
{
union V_205 V_4 ;
int V_33 ;
if ( V_69 > V_236 )
V_69 = V_236 ;
V_4 . V_235 [ 0 ] = V_69 ;
V_33 = F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_209 , V_56 ,
V_237 , & V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
memcpy ( V_233 , & V_4 . V_235 [ 1 ] , V_4 . V_235 [ 0 ] ) ;
return V_4 . V_235 [ 0 ] ;
}
T_14 F_240 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_233 )
{
union V_205 V_4 ;
if ( V_69 > V_236 )
V_69 = V_236 ;
V_4 . V_235 [ 0 ] = V_69 ;
memcpy ( V_4 . V_235 + 1 , V_233 , V_69 ) ;
return F_226 ( V_44 -> V_26 , V_44 -> V_12 , V_44 -> V_16 ,
V_212 , V_56 ,
V_237 , & V_4 ) ;
}
static T_14 F_241 ( struct V_25 * V_26 , T_9 V_12 ,
unsigned short V_16 ,
char V_238 , T_4 V_56 , int V_239 ,
union V_205 * V_4 )
{
unsigned char V_240 [ V_236 + 3 ] ;
unsigned char V_241 [ V_236 + 2 ] ;
int V_196 = V_238 == V_209 ? 2 : 1 ;
int V_107 ;
T_4 V_242 = 0 ;
int V_33 ;
struct V_47 V_203 [ 2 ] = {
{
. V_12 = V_12 ,
. V_16 = V_16 ,
. V_52 = 1 ,
. V_53 = V_240 ,
} , {
. V_12 = V_12 ,
. V_16 = V_16 | V_54 ,
. V_52 = 0 ,
. V_53 = V_241 ,
} ,
} ;
V_240 [ 0 ] = V_56 ;
switch ( V_239 ) {
case V_213 :
V_203 [ 0 ] . V_52 = 0 ;
V_203 [ 0 ] . V_16 = V_16 | ( V_238 == V_209 ?
V_54 : 0 ) ;
V_196 = 1 ;
break;
case V_215 :
if ( V_238 == V_209 ) {
V_203 [ 0 ] . V_16 = V_54 | V_16 ;
V_196 = 1 ;
}
break;
case V_210 :
if ( V_238 == V_209 )
V_203 [ 1 ] . V_52 = 1 ;
else {
V_203 [ 0 ] . V_52 = 2 ;
V_240 [ 1 ] = V_4 -> V_229 ;
}
break;
case V_231 :
if ( V_238 == V_209 )
V_203 [ 1 ] . V_52 = 2 ;
else {
V_203 [ 0 ] . V_52 = 3 ;
V_240 [ 1 ] = V_4 -> V_232 & 0xff ;
V_240 [ 2 ] = V_4 -> V_232 >> 8 ;
}
break;
case V_243 :
V_196 = 2 ;
V_238 = V_209 ;
V_203 [ 0 ] . V_52 = 3 ;
V_203 [ 1 ] . V_52 = 2 ;
V_240 [ 1 ] = V_4 -> V_232 & 0xff ;
V_240 [ 2 ] = V_4 -> V_232 >> 8 ;
break;
case V_234 :
if ( V_238 == V_209 ) {
V_203 [ 1 ] . V_16 |= V_202 ;
V_203 [ 1 ] . V_52 = 1 ;
} else {
V_203 [ 0 ] . V_52 = V_4 -> V_235 [ 0 ] + 2 ;
if ( V_203 [ 0 ] . V_52 > V_236 + 2 ) {
F_16 ( & V_26 -> V_39 ,
L_94 ,
V_4 -> V_235 [ 0 ] ) ;
return - V_133 ;
}
for ( V_107 = 1 ; V_107 < V_203 [ 0 ] . V_52 ; V_107 ++ )
V_240 [ V_107 ] = V_4 -> V_235 [ V_107 - 1 ] ;
}
break;
case V_244 :
V_196 = 2 ;
V_238 = V_209 ;
if ( V_4 -> V_235 [ 0 ] > V_236 ) {
F_16 ( & V_26 -> V_39 ,
L_94 ,
V_4 -> V_235 [ 0 ] ) ;
return - V_133 ;
}
V_203 [ 0 ] . V_52 = V_4 -> V_235 [ 0 ] + 2 ;
for ( V_107 = 1 ; V_107 < V_203 [ 0 ] . V_52 ; V_107 ++ )
V_240 [ V_107 ] = V_4 -> V_235 [ V_107 - 1 ] ;
V_203 [ 1 ] . V_16 |= V_202 ;
V_203 [ 1 ] . V_52 = 1 ;
break;
case V_237 :
if ( V_238 == V_209 ) {
V_203 [ 1 ] . V_52 = V_4 -> V_235 [ 0 ] ;
} else {
V_203 [ 0 ] . V_52 = V_4 -> V_235 [ 0 ] + 1 ;
if ( V_203 [ 0 ] . V_52 > V_236 + 1 ) {
F_16 ( & V_26 -> V_39 ,
L_94 ,
V_4 -> V_235 [ 0 ] ) ;
return - V_133 ;
}
for ( V_107 = 1 ; V_107 <= V_4 -> V_235 [ 0 ] ; V_107 ++ )
V_240 [ V_107 ] = V_4 -> V_235 [ V_107 ] ;
}
break;
default:
F_16 ( & V_26 -> V_39 , L_95 , V_239 ) ;
return - V_115 ;
}
V_107 = ( ( V_16 & V_245 ) && V_239 != V_213
&& V_239 != V_237 ) ;
if ( V_107 ) {
if ( ! ( V_203 [ 0 ] . V_16 & V_54 ) ) {
if ( V_196 == 1 )
F_237 ( & V_203 [ 0 ] ) ;
else
V_242 = F_236 ( 0 , & V_203 [ 0 ] ) ;
}
if ( V_203 [ V_196 - 1 ] . V_16 & V_54 )
V_203 [ V_196 - 1 ] . V_52 ++ ;
}
V_33 = F_24 ( V_26 , V_203 , V_196 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_107 && ( V_203 [ V_196 - 1 ] . V_16 & V_54 ) ) {
V_33 = F_238 ( V_242 , & V_203 [ V_196 - 1 ] ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_238 == V_209 )
switch ( V_239 ) {
case V_215 :
V_4 -> V_229 = V_240 [ 0 ] ;
break;
case V_210 :
V_4 -> V_229 = V_241 [ 0 ] ;
break;
case V_231 :
case V_243 :
V_4 -> V_232 = V_241 [ 0 ] | ( V_241 [ 1 ] << 8 ) ;
break;
case V_237 :
for ( V_107 = 0 ; V_107 < V_4 -> V_235 [ 0 ] ; V_107 ++ )
V_4 -> V_235 [ V_107 + 1 ] = V_241 [ V_107 ] ;
break;
case V_234 :
case V_244 :
for ( V_107 = 0 ; V_107 < V_241 [ 0 ] + 1 ; V_107 ++ )
V_4 -> V_235 [ V_107 ] = V_241 [ V_107 ] ;
break;
}
return 0 ;
}
T_14 F_226 ( struct V_25 * V_26 , T_9 V_12 , unsigned short V_16 ,
char V_238 , T_4 V_56 , int V_246 ,
union V_205 * V_4 )
{
unsigned long V_197 ;
int V_198 ;
T_14 V_150 ;
F_242 ( V_26 , V_12 , V_16 , V_238 ,
V_56 , V_246 , V_4 ) ;
F_243 ( V_26 , V_12 , V_16 , V_238 ,
V_56 , V_246 ) ;
V_16 &= V_204 | V_245 | V_247 ;
if ( V_26 -> V_173 -> V_248 ) {
F_108 ( V_26 ) ;
V_197 = V_199 ;
for ( V_150 = 0 , V_198 = 0 ; V_198 <= V_26 -> V_200 ; V_198 ++ ) {
V_150 = V_26 -> V_173 -> V_248 ( V_26 , V_12 , V_16 ,
V_238 , V_56 ,
V_246 , V_4 ) ;
if ( V_150 != - V_171 )
break;
if ( F_215 ( V_199 ,
V_197 + V_26 -> V_174 ) )
break;
}
F_112 ( V_26 ) ;
if ( V_150 != - V_115 || ! V_26 -> V_173 -> V_201 )
goto V_249;
}
V_150 = F_241 ( V_26 , V_12 , V_16 , V_238 ,
V_56 , V_246 , V_4 ) ;
V_249:
F_244 ( V_26 , V_12 , V_16 , V_238 ,
V_56 , V_246 , V_4 ) ;
F_245 ( V_26 , V_12 , V_16 , V_238 ,
V_56 , V_246 , V_150 ) ;
return V_150 ;
}
