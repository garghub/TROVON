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
if ( ! V_6 -> V_11 && V_9 -> type == V_12 ) {
V_6 -> V_11 = V_9 -> V_13 ;
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
if ( V_31 < 0 || ! V_6 . V_11 )
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
V_48 [ 0 ] . V_11 = V_44 -> V_11 ;
V_48 [ 0 ] . V_16 = V_44 -> V_16 ;
V_48 [ 0 ] . V_52 = 1 ;
V_48 [ 0 ] . V_53 = & V_45 ;
V_48 [ 1 ] . V_11 = V_44 -> V_11 ;
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
V_48 [ 0 ] . V_11 = V_44 -> V_11 ;
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
if ( V_9 -> type != V_12 ) {
V_31 = V_70 ;
goto V_71;
}
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_26 = V_26 ;
V_44 . V_11 = V_9 -> V_13 ;
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
F_80 ( & V_44 -> V_39 , true ) ;
return V_33 ;
}
static void F_82 ( struct V_87 * V_39 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_39 -> V_91 )
return;
V_91 = F_54 ( V_39 -> V_91 ) ;
if ( V_91 -> V_121 )
V_91 -> V_121 ( V_44 ) ;
}
static void F_83 ( struct V_87 * V_39 )
{
F_26 ( F_56 ( V_39 ) ) ;
}
static T_7
F_84 ( struct V_87 * V_39 , struct V_122 * V_123 , char * V_53 )
{
return sprintf ( V_53 , L_17 , V_39 -> type == & V_124 ?
F_56 ( V_39 ) -> V_86 : F_85 ( V_39 ) -> V_86 ) ;
}
static T_7
F_86 ( struct V_87 * V_39 , struct V_122 * V_123 , char * V_53 )
{
struct V_43 * V_44 = F_56 ( V_39 ) ;
int V_52 ;
V_52 = F_87 ( V_39 , V_53 , V_125 - 1 ) ;
if ( V_52 != - V_81 )
return V_52 ;
return sprintf ( V_53 , L_18 , V_96 , V_44 -> V_86 ) ;
}
struct V_43 * F_51 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_124 )
? F_56 ( V_39 )
: NULL ;
}
static int F_88 ( const struct V_43 * V_44 )
{
if ( V_44 -> V_16 & V_17 ) {
if ( V_44 -> V_11 > 0x3ff )
return - V_126 ;
} else {
if ( V_44 -> V_11 == 0x00 || V_44 -> V_11 > 0x7f )
return - V_126 ;
}
return 0 ;
}
static int F_89 ( unsigned short V_11 )
{
if ( V_11 < 0x08 || V_11 > 0x77 )
return - V_126 ;
return 0 ;
}
static int F_90 ( struct V_87 * V_39 , void * V_127 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
int V_11 = * ( int * ) V_127 ;
if ( V_44 && V_44 -> V_11 == V_11 )
return - V_111 ;
return 0 ;
}
static int F_91 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_41 = F_92 ( V_26 ) ;
int V_128 ;
V_128 = F_93 ( & V_26 -> V_39 , & V_11 ,
F_90 ) ;
if ( ! V_128 && V_41 )
V_128 = F_91 ( V_41 , V_11 ) ;
return V_128 ;
}
static int F_94 ( struct V_87 * V_39 , void * V_127 )
{
int V_128 ;
if ( V_39 -> type == & V_129 )
V_128 = F_93 ( V_39 , V_127 ,
F_94 ) ;
else
V_128 = F_90 ( V_39 , V_127 ) ;
return V_128 ;
}
static int F_95 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_41 = F_92 ( V_26 ) ;
int V_128 = 0 ;
if ( V_41 )
V_128 = F_91 ( V_41 , V_11 ) ;
if ( ! V_128 )
V_128 = F_93 ( & V_26 -> V_39 , & V_11 ,
F_94 ) ;
return V_128 ;
}
void F_96 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_92 ( V_26 ) ;
if ( V_41 )
F_96 ( V_41 ) ;
else
F_97 ( & V_26 -> V_130 ) ;
}
static int F_98 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_92 ( V_26 ) ;
if ( V_41 )
return F_98 ( V_41 ) ;
else
return F_99 ( & V_26 -> V_130 ) ;
}
void F_100 ( struct V_25 * V_26 )
{
struct V_25 * V_41 = F_92 ( V_26 ) ;
if ( V_41 )
F_100 ( V_41 ) ;
else
F_101 ( & V_26 -> V_130 ) ;
}
static void F_102 ( struct V_25 * V_40 ,
struct V_43 * V_44 )
{
struct V_29 * V_30 = F_103 ( & V_44 -> V_39 ) ;
if ( V_30 ) {
F_104 ( & V_44 -> V_39 , L_19 , F_105 ( V_30 ) ) ;
return;
}
F_104 ( & V_44 -> V_39 , L_20 , F_106 ( V_40 ) ,
V_44 -> V_11 | ( ( V_44 -> V_16 & V_17 )
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
V_44 -> V_39 . V_131 = V_6 -> V_131 ;
if ( V_6 -> V_132 )
V_44 -> V_39 . V_132 = * V_6 -> V_132 ;
V_44 -> V_16 = V_6 -> V_16 ;
V_44 -> V_11 = V_6 -> V_11 ;
V_44 -> V_18 = V_6 -> V_18 ;
F_13 ( V_44 -> V_86 , V_6 -> type , sizeof( V_44 -> V_86 ) ) ;
V_33 = F_88 ( V_44 ) ;
if ( V_33 ) {
F_16 ( & V_40 -> V_39 , L_21 ,
V_44 -> V_16 & V_17 ? 10 : 7 , V_44 -> V_11 ) ;
goto V_133;
}
V_33 = F_95 ( V_40 , V_44 -> V_11 ) ;
if ( V_33 )
goto V_134;
V_44 -> V_39 . V_41 = & V_44 -> V_26 -> V_39 ;
V_44 -> V_39 . V_135 = & V_136 ;
V_44 -> V_39 . type = & V_124 ;
V_44 -> V_39 . V_117 = V_6 -> V_117 ;
F_107 ( & V_44 -> V_39 , V_6 -> V_35 . V_36 ) ;
F_102 ( V_40 , V_44 ) ;
V_33 = F_108 ( & V_44 -> V_39 ) ;
if ( V_33 )
goto V_134;
F_59 ( & V_40 -> V_39 , L_22 ,
V_44 -> V_86 , F_14 ( & V_44 -> V_39 ) ) ;
return V_44 ;
V_134:
F_16 ( & V_40 -> V_39 , L_23
L_24 , V_44 -> V_86 , V_44 -> V_11 , V_33 ) ;
V_133:
F_26 ( V_44 ) ;
return NULL ;
}
void F_109 ( struct V_43 * V_44 )
{
F_110 ( & V_44 -> V_39 ) ;
}
static int F_111 ( struct V_43 * V_44 ,
const struct V_84 * V_85 )
{
return 0 ;
}
static int F_112 ( struct V_43 * V_44 )
{
return 0 ;
}
struct V_43 * F_113 ( struct V_25 * V_26 , T_8 V_137 )
{
struct V_5 V_6 = {
F_114 ( L_25 , V_137 ) ,
} ;
return F_15 ( V_26 , & V_6 ) ;
}
static void F_115 ( struct V_87 * V_39 )
{
struct V_25 * V_40 = F_85 ( V_39 ) ;
F_116 ( & V_40 -> V_138 ) ;
}
static inline unsigned int F_117 ( struct V_25 * V_26 )
{
unsigned int V_139 = 0 ;
while ( ( V_26 = F_92 ( V_26 ) ) )
V_139 ++ ;
return V_139 ;
}
static T_7
F_118 ( struct V_87 * V_39 , struct V_122 * V_123 ,
const char * V_53 , T_9 V_140 )
{
struct V_25 * V_40 = F_85 ( V_39 ) ;
struct V_5 V_6 ;
struct V_43 * V_44 ;
char * V_141 , V_142 ;
int V_143 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_141 = strchr ( V_53 , ' ' ) ;
if ( ! V_141 ) {
F_16 ( V_39 , L_26 , L_27 ) ;
return - V_126 ;
}
if ( V_141 - V_53 > V_144 - 1 ) {
F_16 ( V_39 , L_28 , L_27 ) ;
return - V_126 ;
}
memcpy ( V_6 . type , V_53 , V_141 - V_53 ) ;
V_143 = sscanf ( ++ V_141 , L_29 , & V_6 . V_11 , & V_142 ) ;
if ( V_143 < 1 ) {
F_16 ( V_39 , L_30 , L_27 ) ;
return - V_126 ;
}
if ( V_143 > 1 && V_142 != '\n' ) {
F_16 ( V_39 , L_31 , L_27 ) ;
return - V_126 ;
}
V_44 = F_15 ( V_40 , & V_6 ) ;
if ( ! V_44 )
return - V_126 ;
F_119 ( & V_40 -> V_145 ) ;
F_120 ( & V_44 -> V_146 , & V_40 -> V_147 ) ;
F_121 ( & V_40 -> V_145 ) ;
F_122 ( V_39 , L_32 , L_27 ,
V_6 . type , V_6 . V_11 ) ;
return V_140 ;
}
static T_7
F_123 ( struct V_87 * V_39 , struct V_122 * V_123 ,
const char * V_53 , T_9 V_140 )
{
struct V_25 * V_40 = F_85 ( V_39 ) ;
struct V_43 * V_44 , * V_148 ;
unsigned short V_11 ;
char V_142 ;
int V_143 ;
V_143 = sscanf ( V_53 , L_29 , & V_11 , & V_142 ) ;
if ( V_143 < 1 ) {
F_16 ( V_39 , L_30 , L_33 ) ;
return - V_126 ;
}
if ( V_143 > 1 && V_142 != '\n' ) {
F_16 ( V_39 , L_31 , L_33 ) ;
return - V_126 ;
}
V_143 = - V_149 ;
F_124 ( & V_40 -> V_145 ,
F_117 ( V_40 ) ) ;
F_125 (client, next, &adap->userspace_clients,
detected) {
if ( V_44 -> V_11 == V_11 ) {
F_122 ( V_39 , L_34 ,
L_33 , V_44 -> V_86 , V_44 -> V_11 ) ;
F_126 ( & V_44 -> V_146 ) ;
F_109 ( V_44 ) ;
V_143 = V_140 ;
break;
}
}
F_121 ( & V_40 -> V_145 ) ;
if ( V_143 < 0 )
F_16 ( V_39 , L_35 ,
L_33 ) ;
return V_143 ;
}
struct V_25 * F_127 ( struct V_87 * V_39 )
{
return ( V_39 -> type == & V_129 )
? F_85 ( V_39 )
: NULL ;
}
static void F_128 ( struct V_25 * V_26 )
{
struct V_150 * V_151 ;
F_129 ( & V_152 ) ;
F_130 (devinfo, &__i2c_board_list, list) {
if ( V_151 -> V_153 == V_26 -> V_154
&& ! F_15 ( V_26 ,
& V_151 -> V_155 ) )
F_16 ( & V_26 -> V_39 ,
L_36 ,
V_151 -> V_155 . V_11 ) ;
}
F_131 ( & V_152 ) ;
}
static struct V_43 * F_132 ( struct V_25 * V_40 ,
struct V_156 * V_157 )
{
struct V_43 * V_128 ;
struct V_5 V_6 = {} ;
struct V_158 V_159 = {} ;
const T_10 * V_11 ;
int V_52 ;
F_59 ( & V_40 -> V_39 , L_37 , V_157 -> V_160 ) ;
if ( F_133 ( V_157 , V_6 . type , sizeof( V_6 . type ) ) < 0 ) {
F_16 ( & V_40 -> V_39 , L_38 ,
V_157 -> V_160 ) ;
return F_134 ( - V_126 ) ;
}
V_11 = F_135 ( V_157 , L_39 , & V_52 ) ;
if ( ! V_11 || ( V_52 < sizeof( int ) ) ) {
F_16 ( & V_40 -> V_39 , L_40 ,
V_157 -> V_160 ) ;
return F_134 ( - V_126 ) ;
}
V_6 . V_11 = F_136 ( V_11 ) ;
if ( V_6 . V_11 > ( 1 << 10 ) - 1 ) {
F_16 ( & V_40 -> V_39 , L_41 ,
V_6 . V_11 , V_157 -> V_160 ) ;
return F_134 ( - V_126 ) ;
}
V_6 . V_117 = F_137 ( V_157 ) ;
V_6 . V_132 = & V_159 ;
if ( F_135 ( V_157 , L_42 , NULL ) )
V_6 . V_16 |= V_120 ;
V_128 = F_15 ( V_40 , & V_6 ) ;
if ( V_128 == NULL ) {
F_16 ( & V_40 -> V_39 , L_43 ,
V_157 -> V_160 ) ;
F_138 ( V_157 ) ;
return F_134 ( - V_126 ) ;
}
return V_128 ;
}
static void F_139 ( struct V_25 * V_40 )
{
struct V_156 * V_157 ;
if ( ! V_40 -> V_39 . V_117 )
return;
F_59 ( & V_40 -> V_39 , L_44 ) ;
F_140 (adap->dev.of_node, node)
F_132 ( V_40 , V_157 ) ;
}
static int F_141 ( struct V_87 * V_39 , void * V_4 )
{
return V_39 -> V_117 == V_4 ;
}
struct V_43 * F_142 ( struct V_156 * V_157 )
{
struct V_87 * V_39 ;
V_39 = F_143 ( & V_136 , NULL , V_157 ,
F_141 ) ;
if ( ! V_39 )
return NULL ;
return F_51 ( V_39 ) ;
}
struct V_25 * F_144 ( struct V_156 * V_157 )
{
struct V_87 * V_39 ;
V_39 = F_143 ( & V_136 , NULL , V_157 ,
F_141 ) ;
if ( ! V_39 )
return NULL ;
return F_127 ( V_39 ) ;
}
static void F_139 ( struct V_25 * V_40 ) { }
static int F_145 ( struct V_90 * V_91 ,
struct V_25 * V_40 )
{
F_146 ( V_40 , V_91 ) ;
if ( V_91 -> V_161 ) {
F_21 ( & V_40 -> V_39 , L_45 ,
V_91 -> V_91 . V_86 ) ;
F_21 ( & V_40 -> V_39 , L_46
L_47 ) ;
V_91 -> V_161 ( V_40 ) ;
}
return 0 ;
}
static int F_147 ( struct V_88 * V_162 , void * V_4 )
{
return F_145 ( F_54 ( V_162 ) , V_4 ) ;
}
static int F_148 ( struct V_25 * V_40 )
{
int V_143 = 0 ;
if ( F_149 ( F_150 ( ! V_136 . V_163 ) ) ) {
V_143 = - V_164 ;
goto V_165;
}
if ( F_149 ( V_40 -> V_86 [ 0 ] == '\0' ) ) {
F_151 ( L_48
L_49 ) ;
return - V_126 ;
}
if ( F_149 ( ! V_40 -> V_166 ) ) {
F_151 ( L_50
L_51 , V_40 -> V_86 ) ;
return - V_126 ;
}
F_152 ( & V_40 -> V_130 ) ;
F_153 ( & V_40 -> V_145 ) ;
F_10 ( & V_40 -> V_147 ) ;
if ( V_40 -> V_167 == 0 )
V_40 -> V_167 = V_168 ;
F_104 ( & V_40 -> V_39 , L_52 , V_40 -> V_154 ) ;
V_40 -> V_39 . V_135 = & V_136 ;
V_40 -> V_39 . type = & V_129 ;
V_143 = F_108 ( & V_40 -> V_39 ) ;
if ( V_143 )
goto V_165;
F_59 ( & V_40 -> V_39 , L_53 , V_40 -> V_86 ) ;
#ifdef F_154
V_143 = F_155 ( V_169 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
if ( V_143 )
F_21 ( & V_40 -> V_39 ,
L_54 ) ;
#endif
if ( V_40 -> V_97 ) {
struct V_101 * V_102 = V_40 -> V_97 ;
if ( ! V_102 -> V_116 ) {
F_16 ( & V_40 -> V_39 , L_55 ) ;
V_40 -> V_97 = NULL ;
goto V_170;
}
if ( V_102 -> V_116 == F_72 ) {
if ( ! F_156 ( V_102 -> V_98 ) ) {
F_16 ( & V_40 -> V_39 , L_56 ) ;
V_40 -> V_97 = NULL ;
goto V_170;
}
if ( F_156 ( V_102 -> V_100 ) )
V_102 -> V_105 = F_64 ;
else
V_102 -> V_105 = NULL ;
V_102 -> V_110 = F_60 ;
V_102 -> V_112 = F_62 ;
} else if ( ! V_102 -> V_112 || ! V_102 -> V_110 ) {
F_16 ( & V_40 -> V_39 , L_57 ) ;
V_40 -> V_97 = NULL ;
}
}
V_170:
F_139 ( V_40 ) ;
F_17 ( V_40 ) ;
F_40 ( V_40 ) ;
if ( V_40 -> V_154 < V_171 )
F_128 ( V_40 ) ;
F_119 ( & V_172 ) ;
F_157 ( & V_136 , NULL , V_40 , F_147 ) ;
F_121 ( & V_172 ) ;
return 0 ;
V_165:
F_119 ( & V_172 ) ;
F_158 ( & V_173 , V_40 -> V_154 ) ;
F_121 ( & V_172 ) ;
return V_143 ;
}
static int F_159 ( struct V_25 * V_40 )
{
int V_85 ;
F_119 ( & V_172 ) ;
V_85 = F_160 ( & V_173 , V_40 , V_40 -> V_154 , V_40 -> V_154 + 1 ,
V_50 ) ;
F_121 ( & V_172 ) ;
if ( V_85 < 0 )
return V_85 == - V_174 ? - V_111 : V_85 ;
return F_148 ( V_40 ) ;
}
int F_161 ( struct V_25 * V_26 )
{
struct V_87 * V_39 = & V_26 -> V_39 ;
int V_85 ;
if ( V_39 -> V_117 ) {
V_85 = F_162 ( V_39 -> V_117 , L_58 ) ;
if ( V_85 >= 0 ) {
V_26 -> V_154 = V_85 ;
return F_159 ( V_26 ) ;
}
}
F_119 ( & V_172 ) ;
V_85 = F_160 ( & V_173 , V_26 ,
V_171 , 0 , V_50 ) ;
F_121 ( & V_172 ) ;
if ( V_85 < 0 )
return V_85 ;
V_26 -> V_154 = V_85 ;
return F_148 ( V_26 ) ;
}
int F_163 ( struct V_25 * V_40 )
{
if ( V_40 -> V_154 == - 1 )
return F_161 ( V_40 ) ;
return F_159 ( V_40 ) ;
}
static void F_164 ( struct V_90 * V_91 ,
struct V_25 * V_26 )
{
struct V_43 * V_44 , * V_175 ;
F_125 (client, _n, &driver->clients, detected) {
if ( V_44 -> V_26 == V_26 ) {
F_59 ( & V_26 -> V_39 , L_59 ,
V_44 -> V_86 , V_44 -> V_11 ) ;
F_126 ( & V_44 -> V_146 ) ;
F_109 ( V_44 ) ;
}
}
}
static int F_165 ( struct V_87 * V_39 , void * V_176 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
if ( V_44 && strcmp ( V_44 -> V_86 , L_25 ) )
F_109 ( V_44 ) ;
return 0 ;
}
static int F_166 ( struct V_87 * V_39 , void * V_176 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
if ( V_44 )
F_109 ( V_44 ) ;
return 0 ;
}
static int F_167 ( struct V_88 * V_162 , void * V_4 )
{
F_164 ( F_54 ( V_162 ) , V_4 ) ;
return 0 ;
}
void F_168 ( struct V_25 * V_40 )
{
struct V_25 * V_177 ;
struct V_43 * V_44 , * V_148 ;
F_119 ( & V_172 ) ;
V_177 = F_169 ( & V_173 , V_40 -> V_154 ) ;
F_121 ( & V_172 ) ;
if ( V_177 != V_40 ) {
F_170 ( L_60
L_61 , V_40 -> V_86 ) ;
return;
}
F_45 ( V_40 ) ;
F_119 ( & V_172 ) ;
F_157 ( & V_136 , NULL , V_40 ,
F_167 ) ;
F_121 ( & V_172 ) ;
F_124 ( & V_40 -> V_145 ,
F_117 ( V_40 ) ) ;
F_125 (client, next, &adap->userspace_clients,
detected) {
F_59 ( & V_40 -> V_39 , L_59 , V_44 -> V_86 ,
V_44 -> V_11 ) ;
F_126 ( & V_44 -> V_146 ) ;
F_109 ( V_44 ) ;
}
F_121 ( & V_40 -> V_145 ) ;
F_93 ( & V_40 -> V_39 , NULL , F_165 ) ;
F_93 ( & V_40 -> V_39 , NULL , F_166 ) ;
#ifdef F_154
F_171 ( V_169 , & V_40 -> V_39 ,
V_40 -> V_39 . V_41 ) ;
#endif
F_59 ( & V_40 -> V_39 , L_62 , V_40 -> V_86 ) ;
F_172 ( & V_40 -> V_138 ) ;
F_110 ( & V_40 -> V_39 ) ;
F_173 ( & V_40 -> V_138 ) ;
F_119 ( & V_172 ) ;
F_158 ( & V_173 , V_40 -> V_154 ) ;
F_121 ( & V_172 ) ;
memset ( & V_40 -> V_39 , 0 , sizeof( V_40 -> V_39 ) ) ;
}
int F_174 ( void * V_4 , int (* F_175)( struct V_87 * , void * ) )
{
int V_143 ;
F_119 ( & V_172 ) ;
V_143 = F_176 ( & V_136 , NULL , V_4 , F_175 ) ;
F_121 ( & V_172 ) ;
return V_143 ;
}
static int F_177 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type != & V_129 )
return 0 ;
return F_145 ( V_4 , F_85 ( V_39 ) ) ;
}
int F_178 ( struct V_178 * V_179 , struct V_90 * V_91 )
{
int V_143 ;
if ( F_149 ( F_150 ( ! V_136 . V_163 ) ) )
return - V_164 ;
V_91 -> V_91 . V_179 = V_179 ;
V_91 -> V_91 . V_135 = & V_136 ;
V_143 = F_179 ( & V_91 -> V_91 ) ;
if ( V_143 )
return V_143 ;
F_170 ( L_63 , V_91 -> V_91 . V_86 ) ;
F_10 ( & V_91 -> V_180 ) ;
F_174 ( V_91 , F_177 ) ;
return 0 ;
}
static int F_180 ( struct V_87 * V_39 , void * V_4 )
{
if ( V_39 -> type == & V_129 )
F_164 ( V_4 , F_85 ( V_39 ) ) ;
return 0 ;
}
void F_181 ( struct V_90 * V_91 )
{
F_174 ( V_91 , F_180 ) ;
F_182 ( & V_91 -> V_91 ) ;
F_170 ( L_64 , V_91 -> V_91 . V_86 ) ;
}
struct V_43 * F_183 ( struct V_43 * V_44 )
{
if ( V_44 && F_184 ( & V_44 -> V_39 ) )
return V_44 ;
return NULL ;
}
void F_185 ( struct V_43 * V_44 )
{
if ( V_44 )
F_186 ( & V_44 -> V_39 ) ;
}
static int F_187 ( struct V_87 * V_39 , void * V_181 )
{
struct V_43 * V_44 = F_51 ( V_39 ) ;
struct V_182 * V_183 = V_181 ;
struct V_90 * V_91 ;
if ( ! V_44 || ! V_44 -> V_39 . V_91 )
return 0 ;
V_91 = F_54 ( V_44 -> V_39 . V_91 ) ;
if ( V_91 -> V_56 )
V_91 -> V_56 ( V_44 , V_183 -> V_45 , V_183 -> V_183 ) ;
return 0 ;
}
void F_188 ( struct V_25 * V_40 , unsigned int V_45 , void * V_183 )
{
struct V_182 V_184 ;
V_184 . V_45 = V_45 ;
V_184 . V_183 = V_183 ;
F_93 ( & V_40 -> V_39 , & V_184 , F_187 ) ;
}
static int F_189 ( struct V_185 * V_186 , unsigned long V_66 ,
void * V_183 )
{
struct V_187 * V_188 = V_183 ;
struct V_25 * V_40 ;
struct V_43 * V_44 ;
switch ( F_190 ( V_66 , V_188 ) ) {
case V_189 :
V_40 = F_144 ( V_188 -> V_190 -> V_41 ) ;
if ( V_40 == NULL )
return V_191 ;
V_44 = F_132 ( V_40 , V_188 -> V_190 ) ;
F_186 ( & V_40 -> V_39 ) ;
if ( F_191 ( V_44 ) ) {
F_151 ( L_65 ,
V_192 , V_188 -> V_190 -> V_160 ) ;
return F_192 ( F_193 ( V_44 ) ) ;
}
break;
case V_193 :
V_44 = F_142 ( V_188 -> V_190 ) ;
if ( V_44 == NULL )
return V_191 ;
F_109 ( V_44 ) ;
F_186 ( & V_44 -> V_39 ) ;
break;
}
return V_191 ;
}
static int T_11 F_194 ( void )
{
int V_194 ;
V_194 = F_195 ( & V_136 ) ;
if ( V_194 )
return V_194 ;
#ifdef F_154
V_169 = F_196 ( L_66 ) ;
if ( ! V_169 ) {
V_194 = - V_82 ;
goto V_195;
}
#endif
V_194 = F_197 ( & V_196 ) ;
if ( V_194 )
goto V_197;
if ( F_198 ( V_198 ) )
F_150 ( F_199 ( & V_199 ) ) ;
return 0 ;
V_197:
#ifdef F_154
F_200 ( V_169 ) ;
V_195:
#endif
F_201 ( & V_136 ) ;
return V_194 ;
}
static void T_12 F_202 ( void )
{
if ( F_198 ( V_198 ) )
F_150 ( F_203 ( & V_199 ) ) ;
F_181 ( & V_196 ) ;
#ifdef F_154
F_200 ( V_169 ) ;
#endif
F_201 ( & V_136 ) ;
F_204 () ;
}
int F_205 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_200 )
{
unsigned long V_201 ;
int V_31 , V_202 ;
if ( F_206 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_200 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_207 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
else
F_208 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
}
V_201 = V_203 ;
for ( V_31 = 0 , V_202 = 0 ; V_202 <= V_40 -> V_204 ; V_202 ++ ) {
V_31 = V_40 -> V_166 -> V_205 ( V_40 , V_48 , V_200 ) ;
if ( V_31 != - V_164 )
break;
if ( F_209 ( V_203 , V_201 + V_40 -> V_167 ) )
break;
}
if ( F_206 ( & V_1 ) ) {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_31 ; V_107 ++ )
if ( V_48 [ V_107 ] . V_16 & V_54 )
F_210 ( V_40 , & V_48 [ V_107 ] , V_107 ) ;
F_211 ( V_40 , V_107 , V_31 ) ;
}
return V_31 ;
}
int F_24 ( struct V_25 * V_40 , struct V_47 * V_48 , int V_200 )
{
int V_31 ;
if ( V_40 -> V_166 -> V_205 ) {
#ifdef F_212
for ( V_31 = 0 ; V_31 < V_200 ; V_31 ++ ) {
F_59 ( & V_40 -> V_39 , L_67
L_68 , V_31 , ( V_48 [ V_31 ] . V_16 & V_54 )
? 'R' : 'W' , V_48 [ V_31 ] . V_11 , V_48 [ V_31 ] . V_52 ,
( V_48 [ V_31 ] . V_16 & V_206 ) ? L_69 : L_70 ) ;
}
#endif
if ( F_213 () || F_214 () ) {
V_31 = F_98 ( V_40 ) ;
if ( ! V_31 )
return - V_164 ;
} else {
F_96 ( V_40 ) ;
}
V_31 = F_205 ( V_40 , V_48 , V_200 ) ;
F_100 ( V_40 ) ;
return V_31 ;
} else {
F_59 ( & V_40 -> V_39 , L_71 ) ;
return - V_115 ;
}
}
int F_215 ( const struct V_43 * V_44 , const char * V_53 , int V_140 )
{
int V_31 ;
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_207 ;
V_207 . V_11 = V_44 -> V_11 ;
V_207 . V_16 = V_44 -> V_16 & V_208 ;
V_207 . V_52 = V_140 ;
V_207 . V_53 = ( char * ) V_53 ;
V_31 = F_24 ( V_40 , & V_207 , 1 ) ;
return ( V_31 == 1 ) ? V_140 : V_31 ;
}
int F_216 ( const struct V_43 * V_44 , char * V_53 , int V_140 )
{
struct V_25 * V_40 = V_44 -> V_26 ;
struct V_47 V_207 ;
int V_31 ;
V_207 . V_11 = V_44 -> V_11 ;
V_207 . V_16 = V_44 -> V_16 & V_208 ;
V_207 . V_16 |= V_54 ;
V_207 . V_52 = V_140 ;
V_207 . V_53 = V_53 ;
V_31 = F_24 ( V_40 , & V_207 , 1 ) ;
return ( V_31 == 1 ) ? V_140 : V_31 ;
}
static int F_217 ( struct V_25 * V_40 , unsigned short V_11 )
{
int V_71 ;
union V_209 V_176 ;
#ifdef F_218
if ( V_11 == 0x73 && ( V_40 -> V_210 & V_211 )
&& F_219 ( V_40 , V_212 ) )
V_71 = F_220 ( V_40 , V_11 , 0 , V_213 , 0 ,
V_214 , & V_176 ) ;
else
#endif
if ( ! ( ( V_11 & ~ 0x07 ) == 0x30 || ( V_11 & ~ 0x0f ) == 0x50 )
&& F_219 ( V_40 , V_215 ) )
V_71 = F_220 ( V_40 , V_11 , 0 , V_216 , 0 ,
V_217 , NULL ) ;
else if ( F_219 ( V_40 , V_218 ) )
V_71 = F_220 ( V_40 , V_11 , 0 , V_213 , 0 ,
V_219 , & V_176 ) ;
else {
F_21 ( & V_40 -> V_39 , L_72 ,
V_11 ) ;
V_71 = - V_115 ;
}
return V_71 >= 0 ;
}
static int F_221 ( struct V_43 * V_220 ,
struct V_90 * V_91 )
{
struct V_5 V_6 ;
struct V_25 * V_26 = V_220 -> V_26 ;
int V_11 = V_220 -> V_11 ;
int V_71 ;
V_71 = F_89 ( V_11 ) ;
if ( V_71 ) {
F_21 ( & V_26 -> V_39 , L_73 ,
V_11 ) ;
return V_71 ;
}
if ( F_95 ( V_26 , V_11 ) )
return 0 ;
if ( ! F_217 ( V_26 , V_11 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_11 = V_11 ;
V_71 = V_91 -> V_221 ( V_220 , & V_6 ) ;
if ( V_71 ) {
return V_71 == - V_81 ? 0 : V_71 ;
}
if ( V_6 . type [ 0 ] == '\0' ) {
F_16 ( & V_26 -> V_39 , L_74
L_75 , V_91 -> V_91 . V_86 ,
V_11 ) ;
} else {
struct V_43 * V_44 ;
if ( V_26 -> V_210 & V_222 )
F_21 ( & V_26 -> V_39 ,
L_76
L_77
L_78 ,
V_6 . V_11 ) ;
F_59 ( & V_26 -> V_39 , L_79 ,
V_6 . type , V_6 . V_11 ) ;
V_44 = F_15 ( V_26 , & V_6 ) ;
if ( V_44 )
F_120 ( & V_44 -> V_146 , & V_91 -> V_180 ) ;
else
F_16 ( & V_26 -> V_39 , L_80 ,
V_6 . type , V_6 . V_11 ) ;
}
return 0 ;
}
static int F_146 ( struct V_25 * V_26 , struct V_90 * V_91 )
{
const unsigned short * V_223 ;
struct V_43 * V_220 ;
int V_107 , V_71 = 0 ;
int V_224 = F_106 ( V_26 ) ;
V_223 = V_91 -> V_223 ;
if ( ! V_91 -> V_221 || ! V_223 )
return 0 ;
if ( V_26 -> V_210 == V_222 ) {
F_59 ( & V_26 -> V_39 ,
L_81
L_82
L_83 ,
V_91 -> V_91 . V_86 ) ;
return 0 ;
}
if ( ! ( V_26 -> V_210 & V_91 -> V_210 ) )
return 0 ;
V_220 = F_23 ( sizeof( struct V_43 ) , V_50 ) ;
if ( ! V_220 )
return - V_82 ;
V_220 -> V_26 = V_26 ;
for ( V_107 = 0 ; V_223 [ V_107 ] != V_225 ; V_107 += 1 ) {
F_59 ( & V_26 -> V_39 , L_84
L_85 , V_224 , V_223 [ V_107 ] ) ;
V_220 -> V_11 = V_223 [ V_107 ] ;
V_71 = F_221 ( V_220 , V_91 ) ;
if ( F_149 ( V_71 ) )
break;
}
F_26 ( V_220 ) ;
return V_71 ;
}
int F_222 ( struct V_25 * V_40 , unsigned short V_11 )
{
return F_220 ( V_40 , V_11 , 0 , V_213 , 0 ,
V_217 , NULL ) >= 0 ;
}
struct V_43 *
F_223 ( struct V_25 * V_40 ,
struct V_5 * V_6 ,
unsigned short const * V_226 ,
int (* V_119)( struct V_25 * , unsigned short V_11 ) )
{
int V_107 ;
if ( ! V_119 )
V_119 = F_217 ;
for ( V_107 = 0 ; V_226 [ V_107 ] != V_225 ; V_107 ++ ) {
if ( F_89 ( V_226 [ V_107 ] ) < 0 ) {
F_21 ( & V_40 -> V_39 , L_86
L_87 , V_226 [ V_107 ] ) ;
continue;
}
if ( F_95 ( V_40 , V_226 [ V_107 ] ) ) {
F_59 ( & V_40 -> V_39 , L_88
L_89 , V_226 [ V_107 ] ) ;
continue;
}
if ( V_119 ( V_40 , V_226 [ V_107 ] ) )
break;
}
if ( V_226 [ V_107 ] == V_225 ) {
F_59 ( & V_40 -> V_39 , L_90 ) ;
return NULL ;
}
V_6 -> V_11 = V_226 [ V_107 ] ;
return F_15 ( V_40 , V_6 ) ;
}
struct V_25 * F_224 ( int V_154 )
{
struct V_25 * V_26 ;
F_119 ( & V_172 ) ;
V_26 = F_169 ( & V_173 , V_154 ) ;
if ( V_26 && ! F_225 ( V_26 -> V_179 ) )
V_26 = NULL ;
F_121 ( & V_172 ) ;
return V_26 ;
}
void F_226 ( struct V_25 * V_40 )
{
if ( V_40 )
F_227 ( V_40 -> V_179 ) ;
}
static T_4 F_228 ( T_8 V_4 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < 8 ; V_107 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_227 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_229 ( T_4 V_228 , T_4 * V_163 , T_9 V_140 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_140 ; V_107 ++ )
V_228 = F_228 ( ( V_228 ^ V_163 [ V_107 ] ) << 8 ) ;
return V_228 ;
}
static T_4 F_230 ( T_4 V_229 , struct V_47 * V_207 )
{
T_4 V_11 = ( V_207 -> V_11 << 1 ) | ! ! ( V_207 -> V_16 & V_54 ) ;
V_229 = F_229 ( V_229 , & V_11 , 1 ) ;
return F_229 ( V_229 , V_207 -> V_53 , V_207 -> V_52 ) ;
}
static inline void F_231 ( struct V_47 * V_207 )
{
V_207 -> V_53 [ V_207 -> V_52 ] = F_230 ( 0 , V_207 ) ;
V_207 -> V_52 ++ ;
}
static int F_232 ( T_4 V_230 , struct V_47 * V_207 )
{
T_4 V_231 = V_207 -> V_53 [ -- V_207 -> V_52 ] ;
V_230 = F_230 ( V_230 , V_207 ) ;
if ( V_231 != V_230 ) {
F_170 ( L_91 ,
V_231 , V_230 ) ;
return - V_232 ;
}
return 0 ;
}
T_13 F_30 ( const struct V_43 * V_44 )
{
union V_209 V_4 ;
int V_33 ;
V_33 = F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_213 , 0 ,
V_219 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_233 ;
}
T_13 F_31 ( const struct V_43 * V_44 , T_4 V_234 )
{
return F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_216 , V_234 , V_219 , NULL ) ;
}
T_13 F_32 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_209 V_4 ;
int V_33 ;
V_33 = F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_213 , V_56 ,
V_214 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_233 ;
}
T_13 F_33 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_234 )
{
union V_209 V_4 ;
V_4 . V_233 = V_234 ;
return F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_216 , V_56 ,
V_214 , & V_4 ) ;
}
T_13 F_34 ( const struct V_43 * V_44 , T_4 V_56 )
{
union V_209 V_4 ;
int V_33 ;
V_33 = F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_213 , V_56 ,
V_235 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_236 ;
}
T_13 F_35 ( const struct V_43 * V_44 , T_4 V_56 ,
T_8 V_234 )
{
union V_209 V_4 ;
V_4 . V_236 = V_234 ;
return F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_216 , V_56 ,
V_235 , & V_4 ) ;
}
T_13 F_36 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 * V_237 )
{
union V_209 V_4 ;
int V_33 ;
V_33 = F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_213 , V_56 ,
V_238 , & V_4 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_237 , & V_4 . V_239 [ 1 ] , V_4 . V_239 [ 0 ] ) ;
return V_4 . V_239 [ 0 ] ;
}
T_13 F_37 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_237 )
{
union V_209 V_4 ;
if ( V_69 > V_240 )
V_69 = V_240 ;
V_4 . V_239 [ 0 ] = V_69 ;
memcpy ( & V_4 . V_239 [ 1 ] , V_237 , V_69 ) ;
return F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_216 , V_56 ,
V_238 , & V_4 ) ;
}
T_13 F_233 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , T_4 * V_237 )
{
union V_209 V_4 ;
int V_33 ;
if ( V_69 > V_240 )
V_69 = V_240 ;
V_4 . V_239 [ 0 ] = V_69 ;
V_33 = F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_213 , V_56 ,
V_241 , & V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
memcpy ( V_237 , & V_4 . V_239 [ 1 ] , V_4 . V_239 [ 0 ] ) ;
return V_4 . V_239 [ 0 ] ;
}
T_13 F_234 ( const struct V_43 * V_44 , T_4 V_56 ,
T_4 V_69 , const T_4 * V_237 )
{
union V_209 V_4 ;
if ( V_69 > V_240 )
V_69 = V_240 ;
V_4 . V_239 [ 0 ] = V_69 ;
memcpy ( V_4 . V_239 + 1 , V_237 , V_69 ) ;
return F_220 ( V_44 -> V_26 , V_44 -> V_11 , V_44 -> V_16 ,
V_216 , V_56 ,
V_241 , & V_4 ) ;
}
static T_13 F_235 ( struct V_25 * V_26 , T_8 V_11 ,
unsigned short V_16 ,
char V_242 , T_4 V_56 , int V_243 ,
union V_209 * V_4 )
{
unsigned char V_244 [ V_240 + 3 ] ;
unsigned char V_245 [ V_240 + 2 ] ;
int V_200 = V_242 == V_213 ? 2 : 1 ;
int V_107 ;
T_4 V_246 = 0 ;
int V_33 ;
struct V_47 V_207 [ 2 ] = {
{
. V_11 = V_11 ,
. V_16 = V_16 ,
. V_52 = 1 ,
. V_53 = V_244 ,
} , {
. V_11 = V_11 ,
. V_16 = V_16 | V_54 ,
. V_52 = 0 ,
. V_53 = V_245 ,
} ,
} ;
V_244 [ 0 ] = V_56 ;
switch ( V_243 ) {
case V_217 :
V_207 [ 0 ] . V_52 = 0 ;
V_207 [ 0 ] . V_16 = V_16 | ( V_242 == V_213 ?
V_54 : 0 ) ;
V_200 = 1 ;
break;
case V_219 :
if ( V_242 == V_213 ) {
V_207 [ 0 ] . V_16 = V_54 | V_16 ;
V_200 = 1 ;
}
break;
case V_214 :
if ( V_242 == V_213 )
V_207 [ 1 ] . V_52 = 1 ;
else {
V_207 [ 0 ] . V_52 = 2 ;
V_244 [ 1 ] = V_4 -> V_233 ;
}
break;
case V_235 :
if ( V_242 == V_213 )
V_207 [ 1 ] . V_52 = 2 ;
else {
V_207 [ 0 ] . V_52 = 3 ;
V_244 [ 1 ] = V_4 -> V_236 & 0xff ;
V_244 [ 2 ] = V_4 -> V_236 >> 8 ;
}
break;
case V_247 :
V_200 = 2 ;
V_242 = V_213 ;
V_207 [ 0 ] . V_52 = 3 ;
V_207 [ 1 ] . V_52 = 2 ;
V_244 [ 1 ] = V_4 -> V_236 & 0xff ;
V_244 [ 2 ] = V_4 -> V_236 >> 8 ;
break;
case V_238 :
if ( V_242 == V_213 ) {
V_207 [ 1 ] . V_16 |= V_206 ;
V_207 [ 1 ] . V_52 = 1 ;
} else {
V_207 [ 0 ] . V_52 = V_4 -> V_239 [ 0 ] + 2 ;
if ( V_207 [ 0 ] . V_52 > V_240 + 2 ) {
F_16 ( & V_26 -> V_39 ,
L_92 ,
V_4 -> V_239 [ 0 ] ) ;
return - V_126 ;
}
for ( V_107 = 1 ; V_107 < V_207 [ 0 ] . V_52 ; V_107 ++ )
V_244 [ V_107 ] = V_4 -> V_239 [ V_107 - 1 ] ;
}
break;
case V_248 :
V_200 = 2 ;
V_242 = V_213 ;
if ( V_4 -> V_239 [ 0 ] > V_240 ) {
F_16 ( & V_26 -> V_39 ,
L_92 ,
V_4 -> V_239 [ 0 ] ) ;
return - V_126 ;
}
V_207 [ 0 ] . V_52 = V_4 -> V_239 [ 0 ] + 2 ;
for ( V_107 = 1 ; V_107 < V_207 [ 0 ] . V_52 ; V_107 ++ )
V_244 [ V_107 ] = V_4 -> V_239 [ V_107 - 1 ] ;
V_207 [ 1 ] . V_16 |= V_206 ;
V_207 [ 1 ] . V_52 = 1 ;
break;
case V_241 :
if ( V_242 == V_213 ) {
V_207 [ 1 ] . V_52 = V_4 -> V_239 [ 0 ] ;
} else {
V_207 [ 0 ] . V_52 = V_4 -> V_239 [ 0 ] + 1 ;
if ( V_207 [ 0 ] . V_52 > V_240 + 1 ) {
F_16 ( & V_26 -> V_39 ,
L_92 ,
V_4 -> V_239 [ 0 ] ) ;
return - V_126 ;
}
for ( V_107 = 1 ; V_107 <= V_4 -> V_239 [ 0 ] ; V_107 ++ )
V_244 [ V_107 ] = V_4 -> V_239 [ V_107 ] ;
}
break;
default:
F_16 ( & V_26 -> V_39 , L_93 , V_243 ) ;
return - V_115 ;
}
V_107 = ( ( V_16 & V_249 ) && V_243 != V_217
&& V_243 != V_241 ) ;
if ( V_107 ) {
if ( ! ( V_207 [ 0 ] . V_16 & V_54 ) ) {
if ( V_200 == 1 )
F_231 ( & V_207 [ 0 ] ) ;
else
V_246 = F_230 ( 0 , & V_207 [ 0 ] ) ;
}
if ( V_207 [ V_200 - 1 ] . V_16 & V_54 )
V_207 [ V_200 - 1 ] . V_52 ++ ;
}
V_33 = F_24 ( V_26 , V_207 , V_200 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_107 && ( V_207 [ V_200 - 1 ] . V_16 & V_54 ) ) {
V_33 = F_232 ( V_246 , & V_207 [ V_200 - 1 ] ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_242 == V_213 )
switch ( V_243 ) {
case V_219 :
V_4 -> V_233 = V_244 [ 0 ] ;
break;
case V_214 :
V_4 -> V_233 = V_245 [ 0 ] ;
break;
case V_235 :
case V_247 :
V_4 -> V_236 = V_245 [ 0 ] | ( V_245 [ 1 ] << 8 ) ;
break;
case V_241 :
for ( V_107 = 0 ; V_107 < V_4 -> V_239 [ 0 ] ; V_107 ++ )
V_4 -> V_239 [ V_107 + 1 ] = V_245 [ V_107 ] ;
break;
case V_238 :
case V_248 :
for ( V_107 = 0 ; V_107 < V_245 [ 0 ] + 1 ; V_107 ++ )
V_4 -> V_239 [ V_107 ] = V_245 [ V_107 ] ;
break;
}
return 0 ;
}
T_13 F_220 ( struct V_25 * V_26 , T_8 V_11 , unsigned short V_16 ,
char V_242 , T_4 V_56 , int V_250 ,
union V_209 * V_4 )
{
unsigned long V_201 ;
int V_202 ;
T_13 V_143 ;
F_236 ( V_26 , V_11 , V_16 , V_242 ,
V_56 , V_250 , V_4 ) ;
F_237 ( V_26 , V_11 , V_16 , V_242 ,
V_56 , V_250 ) ;
V_16 &= V_208 | V_249 | V_251 ;
if ( V_26 -> V_166 -> V_252 ) {
F_96 ( V_26 ) ;
V_201 = V_203 ;
for ( V_143 = 0 , V_202 = 0 ; V_202 <= V_26 -> V_204 ; V_202 ++ ) {
V_143 = V_26 -> V_166 -> V_252 ( V_26 , V_11 , V_16 ,
V_242 , V_56 ,
V_250 , V_4 ) ;
if ( V_143 != - V_164 )
break;
if ( F_209 ( V_203 ,
V_201 + V_26 -> V_167 ) )
break;
}
F_100 ( V_26 ) ;
if ( V_143 != - V_115 || ! V_26 -> V_166 -> V_205 )
goto V_253;
}
V_143 = F_235 ( V_26 , V_11 , V_16 , V_242 ,
V_56 , V_250 , V_4 ) ;
V_253:
F_238 ( V_26 , V_11 , V_16 , V_242 ,
V_56 , V_250 , V_4 ) ;
F_239 ( V_26 , V_11 , V_16 , V_242 ,
V_56 , V_250 , V_143 ) ;
return V_143 ;
}
int F_240 ( struct V_43 * V_44 , T_14 V_254 )
{
int V_31 ;
if ( ! V_44 || ! V_254 )
return - V_126 ;
if ( ! ( V_44 -> V_16 & V_17 ) ) {
V_31 = F_89 ( V_44 -> V_11 ) ;
if ( V_31 )
return V_31 ;
}
if ( ! V_44 -> V_26 -> V_166 -> V_255 )
return - V_115 ;
V_44 -> V_254 = V_254 ;
F_96 ( V_44 -> V_26 ) ;
V_31 = V_44 -> V_26 -> V_166 -> V_255 ( V_44 ) ;
F_100 ( V_44 -> V_26 ) ;
if ( V_31 )
V_44 -> V_254 = NULL ;
return V_31 ;
}
int F_241 ( struct V_43 * V_44 )
{
int V_31 ;
if ( ! V_44 -> V_26 -> V_166 -> V_256 )
return - V_115 ;
F_96 ( V_44 -> V_26 ) ;
V_31 = V_44 -> V_26 -> V_166 -> V_256 ( V_44 ) ;
F_100 ( V_44 -> V_26 ) ;
if ( V_31 == 0 )
V_44 -> V_254 = NULL ;
return V_31 ;
}
