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
} else if ( ! V_6 -> V_18 ) {
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
V_6 . V_35 = F_10 ( V_30 ) ;
F_11 ( & V_28 ) ;
V_31 = F_12 ( V_30 , & V_28 ,
F_5 , & V_6 ) ;
F_13 ( & V_28 ) ;
if ( V_31 < 0 || ! V_6 . V_11 )
return V_32 ;
V_30 -> V_36 . V_16 . V_37 = true ;
F_14 ( V_6 . type , F_15 ( & V_30 -> V_38 ) , sizeof( V_6 . type ) ) ;
if ( ! F_16 ( V_26 , & V_6 ) ) {
V_30 -> V_36 . V_16 . V_37 = false ;
F_17 ( & V_26 -> V_38 ,
L_1 ,
F_15 ( & V_30 -> V_38 ) ) ;
}
return V_32 ;
}
static void F_18 ( struct V_25 * V_39 )
{
T_2 V_22 ;
T_1 V_33 ;
if ( ! V_39 -> V_38 . V_40 )
return;
V_22 = F_19 ( V_39 -> V_38 . V_40 ) ;
if ( ! V_22 )
return;
V_33 = F_20 ( V_41 , V_22 , 1 ,
F_7 , NULL ,
V_39 , NULL ) ;
if ( F_21 ( V_33 ) )
F_22 ( & V_39 -> V_38 , L_2 ) ;
}
static inline void F_18 ( struct V_25 * V_39 ) { }
static int F_23 ( struct V_42 * V_43 ,
T_4 V_44 , T_4 * V_4 , T_4 V_45 )
{
struct V_46 V_47 [ 2 ] ;
int V_31 ;
T_4 * V_48 ;
V_48 = F_24 ( V_45 , V_49 ) ;
if ( ! V_48 )
return V_50 ;
V_47 [ 0 ] . V_11 = V_43 -> V_11 ;
V_47 [ 0 ] . V_16 = V_43 -> V_16 ;
V_47 [ 0 ] . V_51 = 1 ;
V_47 [ 0 ] . V_52 = & V_44 ;
V_47 [ 1 ] . V_11 = V_43 -> V_11 ;
V_47 [ 1 ] . V_16 = V_43 -> V_16 | V_53 ;
V_47 [ 1 ] . V_51 = V_45 ;
V_47 [ 1 ] . V_52 = V_48 ;
V_31 = F_25 ( V_43 -> V_26 , V_47 , F_26 ( V_47 ) ) ;
if ( V_31 < 0 )
F_17 ( & V_43 -> V_26 -> V_38 , L_3 ) ;
else
memcpy ( V_4 , V_48 , V_45 ) ;
F_27 ( V_48 ) ;
return V_31 ;
}
static int F_28 ( struct V_42 * V_43 ,
T_4 V_44 , T_4 * V_4 , T_4 V_45 )
{
struct V_46 V_47 [ 1 ] ;
T_4 * V_48 ;
int V_31 = V_32 ;
V_48 = F_24 ( V_45 + 1 , V_49 ) ;
if ( ! V_48 )
return V_50 ;
V_48 [ 0 ] = V_44 ;
memcpy ( V_48 + 1 , V_4 , V_45 ) ;
V_47 [ 0 ] . V_11 = V_43 -> V_11 ;
V_47 [ 0 ] . V_16 = V_43 -> V_16 ;
V_47 [ 0 ] . V_51 = V_45 + 1 ;
V_47 [ 0 ] . V_52 = V_48 ;
V_31 = F_25 ( V_43 -> V_26 , V_47 , F_26 ( V_47 ) ) ;
if ( V_31 < 0 )
F_17 ( & V_43 -> V_26 -> V_38 , L_4 ) ;
F_27 ( V_48 ) ;
return V_31 ;
}
static T_1
F_29 ( T_3 V_54 , T_5 V_55 ,
T_3 V_56 , T_6 * V_57 ,
void * V_58 , void * V_59 )
{
struct V_60 * V_61 = (struct V_60 * ) V_57 ;
struct V_62 * V_4 = V_58 ;
struct V_63 * V_6 = & V_4 -> V_6 ;
struct V_8 * V_9 ;
struct V_25 * V_26 = V_4 -> V_26 ;
struct V_42 * V_43 ;
struct V_2 * V_3 ;
T_3 V_64 = V_54 >> 16 ;
T_4 V_65 = V_54 & V_66 ;
T_1 V_31 ;
int V_33 ;
V_31 = F_30 ( V_6 -> V_67 , V_6 -> V_68 , & V_3 ) ;
if ( F_21 ( V_31 ) )
return V_31 ;
V_43 = F_24 ( sizeof( * V_43 ) , V_49 ) ;
if ( ! V_43 ) {
V_31 = V_50 ;
goto V_69;
}
if ( ! V_57 || V_3 -> type != V_7 ) {
V_31 = V_70 ;
goto V_69;
}
V_9 = & V_3 -> V_4 . V_10 ;
if ( V_9 -> type != V_12 ) {
V_31 = V_70 ;
goto V_69;
}
V_43 -> V_26 = V_26 ;
V_43 -> V_11 = V_9 -> V_13 ;
if ( V_9 -> V_14 == V_15 )
V_43 -> V_16 |= V_17 ;
switch ( V_64 ) {
case V_71 :
if ( V_65 == V_72 ) {
V_33 = F_31 ( V_43 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_73 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_32 ( V_43 , V_61 -> V_73 ) ;
}
break;
case V_74 :
if ( V_65 == V_72 ) {
V_33 = F_33 ( V_43 , V_55 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_73 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_34 ( V_43 , V_55 ,
V_61 -> V_73 ) ;
}
break;
case V_75 :
if ( V_65 == V_72 ) {
V_33 = F_35 ( V_43 , V_55 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_76 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_36 ( V_43 , V_55 ,
V_61 -> V_76 ) ;
}
break;
case V_77 :
if ( V_65 == V_72 ) {
V_33 = F_37 ( V_43 , V_55 ,
V_61 -> V_4 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_51 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_38 ( V_43 , V_55 ,
V_61 -> V_51 , V_61 -> V_4 ) ;
}
break;
case V_78 :
if ( V_65 == V_72 ) {
V_33 = F_23 ( V_43 , V_55 ,
V_61 -> V_4 , V_6 -> V_79 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
} else {
V_33 = F_28 ( V_43 , V_55 ,
V_61 -> V_4 , V_6 -> V_79 ) ;
}
break;
default:
F_39 ( L_5 , V_64 ) ;
V_31 = V_70 ;
goto V_69;
}
V_61 -> V_33 = V_33 ;
V_69:
F_27 ( V_43 ) ;
F_40 ( V_3 ) ;
return V_31 ;
}
static int F_41 ( struct V_25 * V_26 )
{
T_2 V_22 ;
struct V_62 * V_4 ;
T_1 V_33 ;
if ( ! V_26 -> V_38 . V_40 )
return - V_80 ;
V_22 = F_19 ( V_26 -> V_38 . V_40 ) ;
if ( ! V_22 )
return - V_80 ;
V_4 = F_24 ( sizeof( struct V_62 ) ,
V_49 ) ;
if ( ! V_4 )
return - V_81 ;
V_4 -> V_26 = V_26 ;
V_33 = F_42 ( V_22 , ( void * ) V_4 ) ;
if ( F_21 ( V_33 ) ) {
F_27 ( V_4 ) ;
return - V_81 ;
}
V_33 = F_43 ( V_22 ,
V_82 ,
& F_29 ,
NULL ,
V_4 ) ;
if ( F_21 ( V_33 ) ) {
F_17 ( & V_26 -> V_38 , L_6 ) ;
F_44 ( V_22 ) ;
F_27 ( V_4 ) ;
return - V_81 ;
}
F_45 ( V_22 ) ;
return 0 ;
}
static void F_46 ( struct V_25 * V_26 )
{
T_2 V_22 ;
struct V_62 * V_4 ;
T_1 V_33 ;
if ( ! V_26 -> V_38 . V_40 )
return;
V_22 = F_19 ( V_26 -> V_38 . V_40 ) ;
if ( ! V_22 )
return;
F_47 ( V_22 ,
V_82 ,
& F_29 ) ;
V_33 = F_48 ( V_22 , ( void * * ) & V_4 ) ;
if ( F_49 ( V_33 ) )
F_27 ( V_4 ) ;
F_44 ( V_22 ) ;
}
static inline void F_46 ( struct V_25 * V_26 )
{ }
static inline int F_41 ( struct V_25 * V_26 )
{ return 0 ; }
static const struct V_83 * F_50 ( const struct V_83 * V_84 ,
const struct V_42 * V_43 )
{
while ( V_84 -> V_85 [ 0 ] ) {
if ( strcmp ( V_43 -> V_85 , V_84 -> V_85 ) == 0 )
return V_84 ;
V_84 ++ ;
}
return NULL ;
}
static int F_51 ( struct V_86 * V_38 , struct V_87 * V_88 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_89 * V_90 ;
if ( ! V_43 )
return 0 ;
if ( F_53 ( V_38 , V_88 ) )
return 1 ;
if ( F_54 ( V_38 , V_88 ) )
return 1 ;
V_90 = F_55 ( V_88 ) ;
if ( V_90 -> V_91 )
return F_50 ( V_90 -> V_91 , V_43 ) != NULL ;
return 0 ;
}
static int F_56 ( struct V_86 * V_38 , struct V_92 * V_93 )
{
struct V_42 * V_43 = F_57 ( V_38 ) ;
int V_94 ;
V_94 = F_58 ( V_38 , V_93 ) ;
if ( V_94 != - V_80 )
return V_94 ;
if ( F_59 ( V_93 , L_7 ,
V_95 , V_43 -> V_85 ) )
return - V_81 ;
F_60 ( V_38 , L_8 ) ;
return 0 ;
}
static int F_61 ( struct V_25 * V_39 )
{
return F_62 ( V_39 -> V_96 -> V_97 ) ;
}
static void F_63 ( struct V_25 * V_39 , int V_98 )
{
F_64 ( V_39 -> V_96 -> V_97 , V_98 ) ;
}
static int F_65 ( struct V_25 * V_39 )
{
return F_62 ( V_39 -> V_96 -> V_99 ) ;
}
static int F_66 ( struct V_25 * V_39 )
{
struct V_100 * V_101 = V_39 -> V_96 ;
struct V_86 * V_38 = & V_39 -> V_38 ;
int V_31 = 0 ;
V_31 = F_67 ( V_101 -> V_97 , V_102 |
V_103 , L_9 ) ;
if ( V_31 ) {
F_22 ( V_38 , L_10 , V_101 -> V_97 ) ;
return V_31 ;
}
if ( V_101 -> V_104 ) {
if ( F_67 ( V_101 -> V_99 , V_105 , L_11 ) ) {
F_22 ( V_38 , L_12 ,
V_101 -> V_99 ) ;
V_101 -> V_104 = NULL ;
}
}
return V_31 ;
}
static void F_68 ( struct V_25 * V_39 )
{
struct V_100 * V_101 = V_39 -> V_96 ;
if ( V_101 -> V_104 )
F_69 ( V_101 -> V_99 ) ;
F_69 ( V_101 -> V_97 ) ;
}
static int F_70 ( struct V_25 * V_39 )
{
struct V_100 * V_101 = V_39 -> V_96 ;
int V_106 = 0 , V_98 = 1 , V_31 = 0 ;
if ( V_101 -> V_107 )
V_101 -> V_107 ( V_39 ) ;
V_101 -> V_108 ( V_39 , V_98 ) ;
F_71 ( V_109 ) ;
while ( V_106 ++ < V_110 * 2 ) {
if ( V_98 ) {
if ( V_101 -> V_104 && V_101 -> V_104 ( V_39 ) )
break;
if ( ! V_101 -> V_111 ( V_39 ) ) {
F_17 ( & V_39 -> V_38 ,
L_13 ) ;
V_31 = - V_112 ;
break;
}
}
V_98 = ! V_98 ;
V_101 -> V_108 ( V_39 , V_98 ) ;
F_71 ( V_109 ) ;
}
if ( V_101 -> V_113 )
V_101 -> V_113 ( V_39 ) ;
return V_31 ;
}
int F_72 ( struct V_25 * V_39 )
{
return F_70 ( V_39 ) ;
}
int F_73 ( struct V_25 * V_39 )
{
int V_31 ;
V_31 = F_66 ( V_39 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_70 ( V_39 ) ;
F_68 ( V_39 ) ;
return V_31 ;
}
int F_74 ( struct V_25 * V_39 )
{
if ( ! V_39 -> V_96 )
return - V_114 ;
F_60 ( & V_39 -> V_38 , L_14 ) ;
return V_39 -> V_96 -> V_115 ( V_39 ) ;
}
static int F_75 ( struct V_86 * V_38 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_89 * V_90 ;
int V_33 ;
if ( ! V_43 )
return 0 ;
if ( ! V_43 -> V_18 ) {
int V_18 = - V_116 ;
if ( V_38 -> V_117 )
V_18 = F_76 ( V_38 -> V_117 , 0 ) ;
else if ( F_77 ( V_38 ) )
V_18 = F_78 ( F_77 ( V_38 ) , 0 ) ;
if ( V_18 == - V_118 )
return V_18 ;
if ( V_18 < 0 )
V_18 = 0 ;
V_43 -> V_18 = V_18 ;
}
V_90 = F_55 ( V_38 -> V_90 ) ;
if ( ! V_90 -> V_119 || ! V_90 -> V_91 )
return - V_80 ;
if ( ! F_79 ( & V_43 -> V_38 ) )
F_80 ( & V_43 -> V_38 ,
V_43 -> V_16 & V_120 ) ;
F_60 ( V_38 , L_15 ) ;
V_33 = F_81 ( V_38 -> V_117 , false ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_82 ( & V_43 -> V_38 , true ) ;
if ( V_33 != - V_118 ) {
V_33 = V_90 -> V_119 ( V_43 , F_50 ( V_90 -> V_91 ,
V_43 ) ) ;
if ( V_33 )
F_83 ( & V_43 -> V_38 , true ) ;
}
return V_33 ;
}
static int F_84 ( struct V_86 * V_38 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_89 * V_90 ;
int V_33 = 0 ;
if ( ! V_43 || ! V_38 -> V_90 )
return 0 ;
V_90 = F_55 ( V_38 -> V_90 ) ;
if ( V_90 -> remove ) {
F_60 ( V_38 , L_16 ) ;
V_33 = V_90 -> remove ( V_43 ) ;
}
F_83 ( & V_43 -> V_38 , true ) ;
return V_33 ;
}
static void F_85 ( struct V_86 * V_38 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_89 * V_90 ;
if ( ! V_43 || ! V_38 -> V_90 )
return;
V_90 = F_55 ( V_38 -> V_90 ) ;
if ( V_90 -> V_121 )
V_90 -> V_121 ( V_43 ) ;
}
static void F_86 ( struct V_86 * V_38 )
{
F_27 ( F_57 ( V_38 ) ) ;
}
static T_7
F_87 ( struct V_86 * V_38 , struct V_122 * V_123 , char * V_52 )
{
return sprintf ( V_52 , L_17 , V_38 -> type == & V_124 ?
F_57 ( V_38 ) -> V_85 : F_88 ( V_38 ) -> V_85 ) ;
}
static T_7
F_89 ( struct V_86 * V_38 , struct V_122 * V_123 , char * V_52 )
{
struct V_42 * V_43 = F_57 ( V_38 ) ;
int V_51 ;
V_51 = F_90 ( V_38 , V_52 , V_125 - 1 ) ;
if ( V_51 != - V_80 )
return V_51 ;
return sprintf ( V_52 , L_18 , V_95 , V_43 -> V_85 ) ;
}
struct V_42 * F_52 ( struct V_86 * V_38 )
{
return ( V_38 -> type == & V_124 )
? F_57 ( V_38 )
: NULL ;
}
static int F_91 ( const struct V_42 * V_43 )
{
if ( V_43 -> V_16 & V_17 ) {
if ( V_43 -> V_11 > 0x3ff )
return - V_126 ;
} else {
if ( V_43 -> V_11 == 0x00 || V_43 -> V_11 > 0x7f )
return - V_126 ;
}
return 0 ;
}
static int F_92 ( unsigned short V_11 )
{
if ( V_11 < 0x08 || V_11 > 0x77 )
return - V_126 ;
return 0 ;
}
static int F_93 ( struct V_86 * V_38 , void * V_127 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
int V_11 = * ( int * ) V_127 ;
if ( V_43 && V_43 -> V_11 == V_11 )
return - V_112 ;
return 0 ;
}
static int F_94 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_40 = F_95 ( V_26 ) ;
int V_128 ;
V_128 = F_96 ( & V_26 -> V_38 , & V_11 ,
F_93 ) ;
if ( ! V_128 && V_40 )
V_128 = F_94 ( V_40 , V_11 ) ;
return V_128 ;
}
static int F_97 ( struct V_86 * V_38 , void * V_127 )
{
int V_128 ;
if ( V_38 -> type == & V_129 )
V_128 = F_96 ( V_38 , V_127 ,
F_97 ) ;
else
V_128 = F_93 ( V_38 , V_127 ) ;
return V_128 ;
}
static int F_98 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_40 = F_95 ( V_26 ) ;
int V_128 = 0 ;
if ( V_40 )
V_128 = F_94 ( V_40 , V_11 ) ;
if ( ! V_128 )
V_128 = F_96 ( & V_26 -> V_38 , & V_11 ,
F_97 ) ;
return V_128 ;
}
void F_99 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_95 ( V_26 ) ;
if ( V_40 )
F_99 ( V_40 ) ;
else
F_100 ( & V_26 -> V_130 ) ;
}
static int F_101 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_95 ( V_26 ) ;
if ( V_40 )
return F_101 ( V_40 ) ;
else
return F_102 ( & V_26 -> V_130 ) ;
}
void F_103 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_95 ( V_26 ) ;
if ( V_40 )
F_103 ( V_40 ) ;
else
F_104 ( & V_26 -> V_130 ) ;
}
static void F_105 ( struct V_25 * V_39 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_77 ( & V_43 -> V_38 ) ;
if ( V_30 ) {
F_106 ( & V_43 -> V_38 , L_19 , F_107 ( V_30 ) ) ;
return;
}
F_106 ( & V_43 -> V_38 , L_20 , F_108 ( V_39 ) ,
V_43 -> V_11 | ( ( V_43 -> V_16 & V_17 )
? 0xa000 : 0 ) ) ;
}
struct V_42 *
F_16 ( struct V_25 * V_39 , struct V_5 const * V_6 )
{
struct V_42 * V_43 ;
int V_33 ;
V_43 = F_24 ( sizeof *V_43 , V_49 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_26 = V_39 ;
V_43 -> V_38 . V_131 = V_6 -> V_131 ;
if ( V_6 -> V_132 )
V_43 -> V_38 . V_132 = * V_6 -> V_132 ;
V_43 -> V_16 = V_6 -> V_16 ;
V_43 -> V_11 = V_6 -> V_11 ;
V_43 -> V_18 = V_6 -> V_18 ;
F_14 ( V_43 -> V_85 , V_6 -> type , sizeof( V_43 -> V_85 ) ) ;
V_33 = F_91 ( V_43 ) ;
if ( V_33 ) {
F_17 ( & V_39 -> V_38 , L_21 ,
V_43 -> V_16 & V_17 ? 10 : 7 , V_43 -> V_11 ) ;
goto V_133;
}
V_33 = F_98 ( V_39 , V_43 -> V_11 ) ;
if ( V_33 )
goto V_134;
V_43 -> V_38 . V_40 = & V_43 -> V_26 -> V_38 ;
V_43 -> V_38 . V_135 = & V_136 ;
V_43 -> V_38 . type = & V_124 ;
V_43 -> V_38 . V_117 = V_6 -> V_117 ;
V_43 -> V_38 . V_35 = V_6 -> V_35 ;
F_105 ( V_39 , V_43 ) ;
V_33 = F_109 ( & V_43 -> V_38 ) ;
if ( V_33 )
goto V_134;
F_60 ( & V_39 -> V_38 , L_22 ,
V_43 -> V_85 , F_15 ( & V_43 -> V_38 ) ) ;
return V_43 ;
V_134:
F_17 ( & V_39 -> V_38 , L_23
L_24 , V_43 -> V_85 , V_43 -> V_11 , V_33 ) ;
V_133:
F_27 ( V_43 ) ;
return NULL ;
}
void F_110 ( struct V_42 * V_43 )
{
if ( V_43 -> V_38 . V_117 )
F_111 ( V_43 -> V_38 . V_117 , V_137 ) ;
F_112 ( & V_43 -> V_38 ) ;
}
static int F_113 ( struct V_42 * V_43 ,
const struct V_83 * V_84 )
{
return 0 ;
}
static int F_114 ( struct V_42 * V_43 )
{
return 0 ;
}
struct V_42 * F_115 ( struct V_25 * V_26 , T_8 V_138 )
{
struct V_5 V_6 = {
F_116 ( L_25 , V_138 ) ,
} ;
return F_16 ( V_26 , & V_6 ) ;
}
static void F_117 ( struct V_86 * V_38 )
{
struct V_25 * V_39 = F_88 ( V_38 ) ;
F_118 ( & V_39 -> V_139 ) ;
}
static inline unsigned int F_119 ( struct V_25 * V_26 )
{
unsigned int V_140 = 0 ;
while ( ( V_26 = F_95 ( V_26 ) ) )
V_140 ++ ;
return V_140 ;
}
static T_7
F_120 ( struct V_86 * V_38 , struct V_122 * V_123 ,
const char * V_52 , T_9 V_141 )
{
struct V_25 * V_39 = F_88 ( V_38 ) ;
struct V_5 V_6 ;
struct V_42 * V_43 ;
char * V_142 , V_143 ;
int V_144 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_142 = strchr ( V_52 , ' ' ) ;
if ( ! V_142 ) {
F_17 ( V_38 , L_26 , L_27 ) ;
return - V_126 ;
}
if ( V_142 - V_52 > V_145 - 1 ) {
F_17 ( V_38 , L_28 , L_27 ) ;
return - V_126 ;
}
memcpy ( V_6 . type , V_52 , V_142 - V_52 ) ;
V_144 = sscanf ( ++ V_142 , L_29 , & V_6 . V_11 , & V_143 ) ;
if ( V_144 < 1 ) {
F_17 ( V_38 , L_30 , L_27 ) ;
return - V_126 ;
}
if ( V_144 > 1 && V_143 != '\n' ) {
F_17 ( V_38 , L_31 , L_27 ) ;
return - V_126 ;
}
V_43 = F_16 ( V_39 , & V_6 ) ;
if ( ! V_43 )
return - V_126 ;
F_121 ( & V_39 -> V_146 ) ;
F_122 ( & V_43 -> V_147 , & V_39 -> V_148 ) ;
F_123 ( & V_39 -> V_146 ) ;
F_124 ( V_38 , L_32 , L_27 ,
V_6 . type , V_6 . V_11 ) ;
return V_141 ;
}
static T_7
F_125 ( struct V_86 * V_38 , struct V_122 * V_123 ,
const char * V_52 , T_9 V_141 )
{
struct V_25 * V_39 = F_88 ( V_38 ) ;
struct V_42 * V_43 , * V_149 ;
unsigned short V_11 ;
char V_143 ;
int V_144 ;
V_144 = sscanf ( V_52 , L_29 , & V_11 , & V_143 ) ;
if ( V_144 < 1 ) {
F_17 ( V_38 , L_30 , L_33 ) ;
return - V_126 ;
}
if ( V_144 > 1 && V_143 != '\n' ) {
F_17 ( V_38 , L_31 , L_33 ) ;
return - V_126 ;
}
V_144 = - V_116 ;
F_126 ( & V_39 -> V_146 ,
F_119 ( V_39 ) ) ;
F_127 (client, next, &adap->userspace_clients,
detected) {
if ( V_43 -> V_11 == V_11 ) {
F_124 ( V_38 , L_34 ,
L_33 , V_43 -> V_85 , V_43 -> V_11 ) ;
F_128 ( & V_43 -> V_147 ) ;
F_110 ( V_43 ) ;
V_144 = V_141 ;
break;
}
}
F_123 ( & V_39 -> V_146 ) ;
if ( V_144 < 0 )
F_17 ( V_38 , L_35 ,
L_33 ) ;
return V_144 ;
}
struct V_25 * F_129 ( struct V_86 * V_38 )
{
return ( V_38 -> type == & V_129 )
? F_88 ( V_38 )
: NULL ;
}
static void F_130 ( struct V_25 * V_26 )
{
struct V_150 * V_151 ;
F_131 ( & V_152 ) ;
F_132 (devinfo, &__i2c_board_list, list) {
if ( V_151 -> V_153 == V_26 -> V_154
&& ! F_16 ( V_26 ,
& V_151 -> V_155 ) )
F_17 ( & V_26 -> V_38 ,
L_36 ,
V_151 -> V_155 . V_11 ) ;
}
F_133 ( & V_152 ) ;
}
static struct V_42 * F_134 ( struct V_25 * V_39 ,
struct V_156 * V_157 )
{
struct V_42 * V_128 ;
struct V_5 V_6 = {} ;
struct V_158 V_159 = {} ;
const T_10 * V_11 ;
int V_51 ;
F_60 ( & V_39 -> V_38 , L_37 , V_157 -> V_160 ) ;
if ( F_135 ( V_157 , V_6 . type , sizeof( V_6 . type ) ) < 0 ) {
F_17 ( & V_39 -> V_38 , L_38 ,
V_157 -> V_160 ) ;
return F_136 ( - V_126 ) ;
}
V_11 = F_137 ( V_157 , L_39 , & V_51 ) ;
if ( ! V_11 || ( V_51 < sizeof( * V_11 ) ) ) {
F_17 ( & V_39 -> V_38 , L_40 ,
V_157 -> V_160 ) ;
return F_136 ( - V_126 ) ;
}
V_6 . V_11 = F_138 ( V_11 ) ;
if ( V_6 . V_11 > ( 1 << 10 ) - 1 ) {
F_17 ( & V_39 -> V_38 , L_41 ,
V_6 . V_11 , V_157 -> V_160 ) ;
return F_136 ( - V_126 ) ;
}
V_6 . V_117 = F_139 ( V_157 ) ;
V_6 . V_132 = & V_159 ;
if ( F_137 ( V_157 , L_42 , NULL ) )
V_6 . V_16 |= V_120 ;
V_128 = F_16 ( V_39 , & V_6 ) ;
if ( V_128 == NULL ) {
F_17 ( & V_39 -> V_38 , L_43 ,
V_157 -> V_160 ) ;
F_140 ( V_157 ) ;
return F_136 ( - V_126 ) ;
}
return V_128 ;
}
static void F_141 ( struct V_25 * V_39 )
{
struct V_156 * V_157 ;
if ( ! V_39 -> V_38 . V_117 )
return;
F_60 ( & V_39 -> V_38 , L_44 ) ;
F_142 (adap->dev.of_node, node) {
if ( F_143 ( V_157 , V_137 ) )
continue;
F_134 ( V_39 , V_157 ) ;
}
}
static int F_144 ( struct V_86 * V_38 , void * V_4 )
{
return V_38 -> V_117 == V_4 ;
}
struct V_42 * F_145 ( struct V_156 * V_157 )
{
struct V_86 * V_38 ;
struct V_42 * V_43 ;
V_38 = F_146 ( & V_136 , NULL , V_157 , F_144 ) ;
if ( ! V_38 )
return NULL ;
V_43 = F_52 ( V_38 ) ;
if ( ! V_43 )
F_147 ( V_38 ) ;
return V_43 ;
}
struct V_25 * F_148 ( struct V_156 * V_157 )
{
struct V_86 * V_38 ;
struct V_25 * V_26 ;
V_38 = F_146 ( & V_136 , NULL , V_157 , F_144 ) ;
if ( ! V_38 )
return NULL ;
V_26 = F_129 ( V_38 ) ;
if ( ! V_26 )
F_147 ( V_38 ) ;
return V_26 ;
}
static void F_141 ( struct V_25 * V_39 ) { }
static int F_149 ( struct V_89 * V_90 ,
struct V_25 * V_39 )
{
F_150 ( V_39 , V_90 ) ;
if ( V_90 -> V_161 ) {
F_22 ( & V_39 -> V_38 , L_45 ,
V_90 -> V_90 . V_85 ) ;
F_22 ( & V_39 -> V_38 , L_46
L_47 ) ;
V_90 -> V_161 ( V_39 ) ;
}
return 0 ;
}
static int F_151 ( struct V_87 * V_162 , void * V_4 )
{
return F_149 ( F_55 ( V_162 ) , V_4 ) ;
}
static int F_152 ( struct V_25 * V_39 )
{
int V_144 = 0 ;
if ( F_153 ( F_154 ( ! V_136 . V_163 ) ) ) {
V_144 = - V_164 ;
goto V_165;
}
if ( F_153 ( V_39 -> V_85 [ 0 ] == '\0' ) ) {
F_155 ( L_48
L_49 ) ;
return - V_126 ;
}
if ( F_153 ( ! V_39 -> V_166 ) ) {
F_155 ( L_50
L_51 , V_39 -> V_85 ) ;
return - V_126 ;
}
F_156 ( & V_39 -> V_130 ) ;
F_157 ( & V_39 -> V_146 ) ;
F_11 ( & V_39 -> V_148 ) ;
if ( V_39 -> V_167 == 0 )
V_39 -> V_167 = V_168 ;
F_106 ( & V_39 -> V_38 , L_52 , V_39 -> V_154 ) ;
V_39 -> V_38 . V_135 = & V_136 ;
V_39 -> V_38 . type = & V_129 ;
V_144 = F_109 ( & V_39 -> V_38 ) ;
if ( V_144 )
goto V_165;
F_60 ( & V_39 -> V_38 , L_53 , V_39 -> V_85 ) ;
F_158 ( & V_39 -> V_38 ) ;
#ifdef F_159
V_144 = F_160 ( V_169 , & V_39 -> V_38 ,
V_39 -> V_38 . V_40 ) ;
if ( V_144 )
F_22 ( & V_39 -> V_38 ,
L_54 ) ;
#endif
if ( V_39 -> V_96 ) {
struct V_100 * V_101 = V_39 -> V_96 ;
if ( ! V_101 -> V_115 ) {
F_17 ( & V_39 -> V_38 , L_55 ) ;
V_39 -> V_96 = NULL ;
goto V_170;
}
if ( V_101 -> V_115 == F_73 ) {
if ( ! F_161 ( V_101 -> V_97 ) ) {
F_17 ( & V_39 -> V_38 , L_56 ) ;
V_39 -> V_96 = NULL ;
goto V_170;
}
if ( F_161 ( V_101 -> V_99 ) )
V_101 -> V_104 = F_65 ;
else
V_101 -> V_104 = NULL ;
V_101 -> V_111 = F_61 ;
V_101 -> V_108 = F_63 ;
} else if ( ! V_101 -> V_108 || ! V_101 -> V_111 ) {
F_17 ( & V_39 -> V_38 , L_57 ) ;
V_39 -> V_96 = NULL ;
}
}
V_170:
F_141 ( V_39 ) ;
F_18 ( V_39 ) ;
F_41 ( V_39 ) ;
if ( V_39 -> V_154 < V_171 )
F_130 ( V_39 ) ;
F_121 ( & V_172 ) ;
F_162 ( & V_136 , NULL , V_39 , F_151 ) ;
F_123 ( & V_172 ) ;
return 0 ;
V_165:
F_121 ( & V_172 ) ;
F_163 ( & V_173 , V_39 -> V_154 ) ;
F_123 ( & V_172 ) ;
return V_144 ;
}
static int F_164 ( struct V_25 * V_39 )
{
int V_84 ;
F_121 ( & V_172 ) ;
V_84 = F_165 ( & V_173 , V_39 , V_39 -> V_154 , V_39 -> V_154 + 1 ,
V_49 ) ;
F_123 ( & V_172 ) ;
if ( V_84 < 0 )
return V_84 == - V_174 ? - V_112 : V_84 ;
return F_152 ( V_39 ) ;
}
int F_166 ( struct V_25 * V_26 )
{
struct V_86 * V_38 = & V_26 -> V_38 ;
int V_84 ;
if ( V_38 -> V_117 ) {
V_84 = F_167 ( V_38 -> V_117 , L_58 ) ;
if ( V_84 >= 0 ) {
V_26 -> V_154 = V_84 ;
return F_164 ( V_26 ) ;
}
}
F_121 ( & V_172 ) ;
V_84 = F_165 ( & V_173 , V_26 ,
V_171 , 0 , V_49 ) ;
F_123 ( & V_172 ) ;
if ( V_84 < 0 )
return V_84 ;
V_26 -> V_154 = V_84 ;
return F_152 ( V_26 ) ;
}
int F_168 ( struct V_25 * V_39 )
{
if ( V_39 -> V_154 == - 1 )
return F_166 ( V_39 ) ;
return F_164 ( V_39 ) ;
}
static void F_169 ( struct V_89 * V_90 ,
struct V_25 * V_26 )
{
struct V_42 * V_43 , * V_175 ;
F_127 (client, _n, &driver->clients, detected) {
if ( V_43 -> V_26 == V_26 ) {
F_60 ( & V_26 -> V_38 , L_59 ,
V_43 -> V_85 , V_43 -> V_11 ) ;
F_128 ( & V_43 -> V_147 ) ;
F_110 ( V_43 ) ;
}
}
}
static int F_170 ( struct V_86 * V_38 , void * V_176 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
if ( V_43 && strcmp ( V_43 -> V_85 , L_25 ) )
F_110 ( V_43 ) ;
return 0 ;
}
static int F_171 ( struct V_86 * V_38 , void * V_176 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
if ( V_43 )
F_110 ( V_43 ) ;
return 0 ;
}
static int F_172 ( struct V_87 * V_162 , void * V_4 )
{
F_169 ( F_55 ( V_162 ) , V_4 ) ;
return 0 ;
}
void F_173 ( struct V_25 * V_39 )
{
struct V_25 * V_177 ;
struct V_42 * V_43 , * V_149 ;
F_121 ( & V_172 ) ;
V_177 = F_174 ( & V_173 , V_39 -> V_154 ) ;
F_123 ( & V_172 ) ;
if ( V_177 != V_39 ) {
F_175 ( L_60
L_61 , V_39 -> V_85 ) ;
return;
}
F_46 ( V_39 ) ;
F_121 ( & V_172 ) ;
F_162 ( & V_136 , NULL , V_39 ,
F_172 ) ;
F_123 ( & V_172 ) ;
F_126 ( & V_39 -> V_146 ,
F_119 ( V_39 ) ) ;
F_127 (client, next, &adap->userspace_clients,
detected) {
F_60 ( & V_39 -> V_38 , L_59 , V_43 -> V_85 ,
V_43 -> V_11 ) ;
F_128 ( & V_43 -> V_147 ) ;
F_110 ( V_43 ) ;
}
F_123 ( & V_39 -> V_146 ) ;
F_96 ( & V_39 -> V_38 , NULL , F_170 ) ;
F_96 ( & V_39 -> V_38 , NULL , F_171 ) ;
#ifdef F_159
F_176 ( V_169 , & V_39 -> V_38 ,
V_39 -> V_38 . V_40 ) ;
#endif
F_60 ( & V_39 -> V_38 , L_62 , V_39 -> V_85 ) ;
F_177 ( & V_39 -> V_139 ) ;
F_112 ( & V_39 -> V_38 ) ;
F_178 ( & V_39 -> V_139 ) ;
F_121 ( & V_172 ) ;
F_163 ( & V_173 , V_39 -> V_154 ) ;
F_123 ( & V_172 ) ;
memset ( & V_39 -> V_38 , 0 , sizeof( V_39 -> V_38 ) ) ;
}
int F_179 ( void * V_4 , int (* F_180)( struct V_86 * , void * ) )
{
int V_144 ;
F_121 ( & V_172 ) ;
V_144 = F_181 ( & V_136 , NULL , V_4 , F_180 ) ;
F_123 ( & V_172 ) ;
return V_144 ;
}
static int F_182 ( struct V_86 * V_38 , void * V_4 )
{
if ( V_38 -> type != & V_129 )
return 0 ;
return F_149 ( V_4 , F_88 ( V_38 ) ) ;
}
int F_183 ( struct V_178 * V_179 , struct V_89 * V_90 )
{
int V_144 ;
if ( F_153 ( F_154 ( ! V_136 . V_163 ) ) )
return - V_164 ;
V_90 -> V_90 . V_179 = V_179 ;
V_90 -> V_90 . V_135 = & V_136 ;
V_144 = F_184 ( & V_90 -> V_90 ) ;
if ( V_144 )
return V_144 ;
F_175 ( L_63 , V_90 -> V_90 . V_85 ) ;
F_11 ( & V_90 -> V_180 ) ;
F_179 ( V_90 , F_182 ) ;
return 0 ;
}
static int F_185 ( struct V_86 * V_38 , void * V_4 )
{
if ( V_38 -> type == & V_129 )
F_169 ( V_4 , F_88 ( V_38 ) ) ;
return 0 ;
}
void F_186 ( struct V_89 * V_90 )
{
F_179 ( V_90 , F_185 ) ;
F_187 ( & V_90 -> V_90 ) ;
F_175 ( L_64 , V_90 -> V_90 . V_85 ) ;
}
struct V_42 * F_188 ( struct V_42 * V_43 )
{
if ( V_43 && F_189 ( & V_43 -> V_38 ) )
return V_43 ;
return NULL ;
}
void F_190 ( struct V_42 * V_43 )
{
if ( V_43 )
F_147 ( & V_43 -> V_38 ) ;
}
static int F_191 ( struct V_86 * V_38 , void * V_181 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_182 * V_183 = V_181 ;
struct V_89 * V_90 ;
if ( ! V_43 || ! V_43 -> V_38 . V_90 )
return 0 ;
V_90 = F_55 ( V_43 -> V_38 . V_90 ) ;
if ( V_90 -> V_55 )
V_90 -> V_55 ( V_43 , V_183 -> V_44 , V_183 -> V_183 ) ;
return 0 ;
}
void F_192 ( struct V_25 * V_39 , unsigned int V_44 , void * V_183 )
{
struct V_182 V_184 ;
V_184 . V_44 = V_44 ;
V_184 . V_183 = V_183 ;
F_96 ( & V_39 -> V_38 , & V_184 , F_191 ) ;
}
static int F_193 ( struct V_185 * V_186 , unsigned long V_65 ,
void * V_183 )
{
struct V_187 * V_188 = V_183 ;
struct V_25 * V_39 ;
struct V_42 * V_43 ;
switch ( F_194 ( V_65 , V_188 ) ) {
case V_189 :
V_39 = F_148 ( V_188 -> V_190 -> V_40 ) ;
if ( V_39 == NULL )
return V_191 ;
if ( F_143 ( V_188 -> V_190 , V_137 ) ) {
F_147 ( & V_39 -> V_38 ) ;
return V_191 ;
}
V_43 = F_134 ( V_39 , V_188 -> V_190 ) ;
F_147 ( & V_39 -> V_38 ) ;
if ( F_195 ( V_43 ) ) {
F_155 ( L_65 ,
V_192 , V_188 -> V_190 -> V_160 ) ;
return F_196 ( F_197 ( V_43 ) ) ;
}
break;
case V_193 :
if ( ! F_198 ( V_188 -> V_190 , V_137 ) )
return V_191 ;
V_43 = F_145 ( V_188 -> V_190 ) ;
if ( V_43 == NULL )
return V_191 ;
F_110 ( V_43 ) ;
F_147 ( & V_43 -> V_38 ) ;
break;
}
return V_191 ;
}
static int T_11 F_199 ( void )
{
int V_194 ;
V_194 = F_200 ( L_58 ) ;
F_201 ( & V_152 ) ;
if ( V_194 >= V_171 )
V_171 = V_194 + 1 ;
F_202 ( & V_152 ) ;
V_194 = F_203 ( & V_136 ) ;
if ( V_194 )
return V_194 ;
#ifdef F_159
V_169 = F_204 ( L_66 ) ;
if ( ! V_169 ) {
V_194 = - V_81 ;
goto V_195;
}
#endif
V_194 = F_205 ( & V_196 ) ;
if ( V_194 )
goto V_197;
if ( F_206 ( V_198 ) )
F_154 ( F_207 ( & V_199 ) ) ;
return 0 ;
V_197:
#ifdef F_159
F_208 ( V_169 ) ;
V_195:
#endif
F_209 ( & V_136 ) ;
return V_194 ;
}
static void T_12 F_210 ( void )
{
if ( F_206 ( V_198 ) )
F_154 ( F_211 ( & V_199 ) ) ;
F_186 ( & V_196 ) ;
#ifdef F_159
F_208 ( V_169 ) ;
#endif
F_209 ( & V_136 ) ;
F_212 () ;
}
static int F_213 ( struct V_25 * V_39 , struct V_46 * V_200 , char * V_201 )
{
F_214 ( & V_39 -> V_38 , L_67 ,
V_201 , V_200 -> V_11 , V_200 -> V_51 ,
V_200 -> V_16 & V_53 ? L_68 : L_69 ) ;
return - V_114 ;
}
static int F_215 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_202 )
{
const struct V_203 * V_204 = V_39 -> V_205 ;
int V_206 = V_204 -> V_207 , V_106 ;
bool V_208 = true ;
if ( V_204 -> V_16 & V_209 ) {
V_206 = 2 ;
if ( V_202 == 2 ) {
if ( V_204 -> V_16 & V_210 && V_47 [ 0 ] . V_16 & V_53 )
return F_213 ( V_39 , & V_47 [ 0 ] , L_70 ) ;
if ( V_204 -> V_16 & V_211 && ! ( V_47 [ 1 ] . V_16 & V_53 ) )
return F_213 ( V_39 , & V_47 [ 1 ] , L_71 ) ;
if ( V_204 -> V_16 & V_212 && V_47 [ 0 ] . V_11 != V_47 [ 1 ] . V_11 )
return F_213 ( V_39 , & V_47 [ 0 ] , L_72 ) ;
if ( F_216 ( V_47 [ 0 ] . V_51 , V_204 -> V_213 ) )
return F_213 ( V_39 , & V_47 [ 0 ] , L_73 ) ;
if ( F_216 ( V_47 [ 1 ] . V_51 , V_204 -> V_214 ) )
return F_213 ( V_39 , & V_47 [ 1 ] , L_73 ) ;
V_208 = false ;
}
}
if ( F_216 ( V_202 , V_206 ) )
return F_213 ( V_39 , & V_47 [ 0 ] , L_74 ) ;
for ( V_106 = 0 ; V_106 < V_202 ; V_106 ++ ) {
T_8 V_51 = V_47 [ V_106 ] . V_51 ;
if ( V_47 [ V_106 ] . V_16 & V_53 ) {
if ( V_208 && F_216 ( V_51 , V_204 -> V_215 ) )
return F_213 ( V_39 , & V_47 [ V_106 ] , L_73 ) ;
} else {
if ( V_208 && F_216 ( V_51 , V_204 -> V_216 ) )
return F_213 ( V_39 , & V_47 [ V_106 ] , L_73 ) ;
}
}
return 0 ;
}
int F_217 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_202 )
{
unsigned long V_217 ;
int V_31 , V_218 ;
if ( V_39 -> V_205 && F_215 ( V_39 , V_47 , V_202 ) )
return - V_114 ;
if ( F_218 ( & V_1 ) ) {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_202 ; V_106 ++ )
if ( V_47 [ V_106 ] . V_16 & V_53 )
F_219 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
else
F_220 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
}
V_217 = V_219 ;
for ( V_31 = 0 , V_218 = 0 ; V_218 <= V_39 -> V_220 ; V_218 ++ ) {
V_31 = V_39 -> V_166 -> V_221 ( V_39 , V_47 , V_202 ) ;
if ( V_31 != - V_164 )
break;
if ( F_221 ( V_219 , V_217 + V_39 -> V_167 ) )
break;
}
if ( F_218 ( & V_1 ) ) {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_31 ; V_106 ++ )
if ( V_47 [ V_106 ] . V_16 & V_53 )
F_222 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
F_223 ( V_39 , V_106 , V_31 ) ;
}
return V_31 ;
}
int F_25 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_202 )
{
int V_31 ;
if ( V_39 -> V_166 -> V_221 ) {
#ifdef F_224
for ( V_31 = 0 ; V_31 < V_202 ; V_31 ++ ) {
F_60 ( & V_39 -> V_38 , L_75
L_76 , V_31 , ( V_47 [ V_31 ] . V_16 & V_53 )
? 'R' : 'W' , V_47 [ V_31 ] . V_11 , V_47 [ V_31 ] . V_51 ,
( V_47 [ V_31 ] . V_16 & V_222 ) ? L_77 : L_78 ) ;
}
#endif
if ( F_225 () || F_226 () ) {
V_31 = F_101 ( V_39 ) ;
if ( ! V_31 )
return - V_164 ;
} else {
F_99 ( V_39 ) ;
}
V_31 = F_217 ( V_39 , V_47 , V_202 ) ;
F_103 ( V_39 ) ;
return V_31 ;
} else {
F_60 ( & V_39 -> V_38 , L_79 ) ;
return - V_114 ;
}
}
int F_227 ( const struct V_42 * V_43 , const char * V_52 , int V_141 )
{
int V_31 ;
struct V_25 * V_39 = V_43 -> V_26 ;
struct V_46 V_200 ;
V_200 . V_11 = V_43 -> V_11 ;
V_200 . V_16 = V_43 -> V_16 & V_223 ;
V_200 . V_51 = V_141 ;
V_200 . V_52 = ( char * ) V_52 ;
V_31 = F_25 ( V_39 , & V_200 , 1 ) ;
return ( V_31 == 1 ) ? V_141 : V_31 ;
}
int F_228 ( const struct V_42 * V_43 , char * V_52 , int V_141 )
{
struct V_25 * V_39 = V_43 -> V_26 ;
struct V_46 V_200 ;
int V_31 ;
V_200 . V_11 = V_43 -> V_11 ;
V_200 . V_16 = V_43 -> V_16 & V_223 ;
V_200 . V_16 |= V_53 ;
V_200 . V_51 = V_141 ;
V_200 . V_52 = V_52 ;
V_31 = F_25 ( V_39 , & V_200 , 1 ) ;
return ( V_31 == 1 ) ? V_141 : V_31 ;
}
static int F_229 ( struct V_25 * V_39 , unsigned short V_11 )
{
int V_69 ;
union V_224 V_176 ;
#ifdef F_230
if ( V_11 == 0x73 && ( V_39 -> V_225 & V_226 )
&& F_231 ( V_39 , V_227 ) )
V_69 = F_232 ( V_39 , V_11 , 0 , V_228 , 0 ,
V_229 , & V_176 ) ;
else
#endif
if ( ! ( ( V_11 & ~ 0x07 ) == 0x30 || ( V_11 & ~ 0x0f ) == 0x50 )
&& F_231 ( V_39 , V_230 ) )
V_69 = F_232 ( V_39 , V_11 , 0 , V_231 , 0 ,
V_232 , NULL ) ;
else if ( F_231 ( V_39 , V_233 ) )
V_69 = F_232 ( V_39 , V_11 , 0 , V_228 , 0 ,
V_234 , & V_176 ) ;
else {
F_22 ( & V_39 -> V_38 , L_80 ,
V_11 ) ;
V_69 = - V_114 ;
}
return V_69 >= 0 ;
}
static int F_233 ( struct V_42 * V_235 ,
struct V_89 * V_90 )
{
struct V_5 V_6 ;
struct V_25 * V_26 = V_235 -> V_26 ;
int V_11 = V_235 -> V_11 ;
int V_69 ;
V_69 = F_92 ( V_11 ) ;
if ( V_69 ) {
F_22 ( & V_26 -> V_38 , L_81 ,
V_11 ) ;
return V_69 ;
}
if ( F_98 ( V_26 , V_11 ) )
return 0 ;
if ( ! F_229 ( V_26 , V_11 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_11 = V_11 ;
V_69 = V_90 -> V_236 ( V_235 , & V_6 ) ;
if ( V_69 ) {
return V_69 == - V_80 ? 0 : V_69 ;
}
if ( V_6 . type [ 0 ] == '\0' ) {
F_17 ( & V_26 -> V_38 , L_82
L_83 , V_90 -> V_90 . V_85 ,
V_11 ) ;
} else {
struct V_42 * V_43 ;
if ( V_26 -> V_225 & V_237 )
F_22 ( & V_26 -> V_38 ,
L_84
L_85
L_86 ,
V_6 . V_11 ) ;
F_60 ( & V_26 -> V_38 , L_87 ,
V_6 . type , V_6 . V_11 ) ;
V_43 = F_16 ( V_26 , & V_6 ) ;
if ( V_43 )
F_122 ( & V_43 -> V_147 , & V_90 -> V_180 ) ;
else
F_17 ( & V_26 -> V_38 , L_88 ,
V_6 . type , V_6 . V_11 ) ;
}
return 0 ;
}
static int F_150 ( struct V_25 * V_26 , struct V_89 * V_90 )
{
const unsigned short * V_238 ;
struct V_42 * V_235 ;
int V_106 , V_69 = 0 ;
int V_239 = F_108 ( V_26 ) ;
V_238 = V_90 -> V_238 ;
if ( ! V_90 -> V_236 || ! V_238 )
return 0 ;
if ( V_26 -> V_225 == V_237 ) {
F_60 ( & V_26 -> V_38 ,
L_89
L_90
L_91 ,
V_90 -> V_90 . V_85 ) ;
return 0 ;
}
if ( ! ( V_26 -> V_225 & V_90 -> V_225 ) )
return 0 ;
V_235 = F_24 ( sizeof( struct V_42 ) , V_49 ) ;
if ( ! V_235 )
return - V_81 ;
V_235 -> V_26 = V_26 ;
for ( V_106 = 0 ; V_238 [ V_106 ] != V_240 ; V_106 += 1 ) {
F_60 ( & V_26 -> V_38 , L_92
L_93 , V_239 , V_238 [ V_106 ] ) ;
V_235 -> V_11 = V_238 [ V_106 ] ;
V_69 = F_233 ( V_235 , V_90 ) ;
if ( F_153 ( V_69 ) )
break;
}
F_27 ( V_235 ) ;
return V_69 ;
}
int F_234 ( struct V_25 * V_39 , unsigned short V_11 )
{
return F_232 ( V_39 , V_11 , 0 , V_228 , 0 ,
V_232 , NULL ) >= 0 ;
}
struct V_42 *
F_235 ( struct V_25 * V_39 ,
struct V_5 * V_6 ,
unsigned short const * V_241 ,
int (* V_119)( struct V_25 * , unsigned short V_11 ) )
{
int V_106 ;
if ( ! V_119 )
V_119 = F_229 ;
for ( V_106 = 0 ; V_241 [ V_106 ] != V_240 ; V_106 ++ ) {
if ( F_92 ( V_241 [ V_106 ] ) < 0 ) {
F_22 ( & V_39 -> V_38 , L_94
L_95 , V_241 [ V_106 ] ) ;
continue;
}
if ( F_98 ( V_39 , V_241 [ V_106 ] ) ) {
F_60 ( & V_39 -> V_38 , L_96
L_97 , V_241 [ V_106 ] ) ;
continue;
}
if ( V_119 ( V_39 , V_241 [ V_106 ] ) )
break;
}
if ( V_241 [ V_106 ] == V_240 ) {
F_60 ( & V_39 -> V_38 , L_98 ) ;
return NULL ;
}
V_6 -> V_11 = V_241 [ V_106 ] ;
return F_16 ( V_39 , V_6 ) ;
}
struct V_25 * F_236 ( int V_154 )
{
struct V_25 * V_26 ;
F_121 ( & V_172 ) ;
V_26 = F_174 ( & V_173 , V_154 ) ;
if ( V_26 && ! F_237 ( V_26 -> V_179 ) )
V_26 = NULL ;
F_123 ( & V_172 ) ;
return V_26 ;
}
void F_238 ( struct V_25 * V_39 )
{
if ( V_39 )
F_239 ( V_39 -> V_179 ) ;
}
static T_4 F_240 ( T_8 V_4 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < 8 ; V_106 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_242 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_241 ( T_4 V_243 , T_4 * V_163 , T_9 V_141 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_141 ; V_106 ++ )
V_243 = F_240 ( ( V_243 ^ V_163 [ V_106 ] ) << 8 ) ;
return V_243 ;
}
static T_4 F_242 ( T_4 V_244 , struct V_46 * V_200 )
{
T_4 V_11 = ( V_200 -> V_11 << 1 ) | ! ! ( V_200 -> V_16 & V_53 ) ;
V_244 = F_241 ( V_244 , & V_11 , 1 ) ;
return F_241 ( V_244 , V_200 -> V_52 , V_200 -> V_51 ) ;
}
static inline void F_243 ( struct V_46 * V_200 )
{
V_200 -> V_52 [ V_200 -> V_51 ] = F_242 ( 0 , V_200 ) ;
V_200 -> V_51 ++ ;
}
static int F_244 ( T_4 V_245 , struct V_46 * V_200 )
{
T_4 V_246 = V_200 -> V_52 [ -- V_200 -> V_51 ] ;
V_245 = F_242 ( V_245 , V_200 ) ;
if ( V_246 != V_245 ) {
F_175 ( L_99 ,
V_246 , V_245 ) ;
return - V_247 ;
}
return 0 ;
}
T_13 F_31 ( const struct V_42 * V_43 )
{
union V_224 V_4 ;
int V_33 ;
V_33 = F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_228 , 0 ,
V_234 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_248 ;
}
T_13 F_32 ( const struct V_42 * V_43 , T_4 V_249 )
{
return F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_231 , V_249 , V_234 , NULL ) ;
}
T_13 F_33 ( const struct V_42 * V_43 , T_4 V_55 )
{
union V_224 V_4 ;
int V_33 ;
V_33 = F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_228 , V_55 ,
V_229 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_248 ;
}
T_13 F_34 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_249 )
{
union V_224 V_4 ;
V_4 . V_248 = V_249 ;
return F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_231 , V_55 ,
V_229 , & V_4 ) ;
}
T_13 F_35 ( const struct V_42 * V_43 , T_4 V_55 )
{
union V_224 V_4 ;
int V_33 ;
V_33 = F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_228 , V_55 ,
V_250 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_251 ;
}
T_13 F_36 ( const struct V_42 * V_43 , T_4 V_55 ,
T_8 V_249 )
{
union V_224 V_4 ;
V_4 . V_251 = V_249 ;
return F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_231 , V_55 ,
V_250 , & V_4 ) ;
}
T_13 F_37 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 * V_252 )
{
union V_224 V_4 ;
int V_33 ;
V_33 = F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_228 , V_55 ,
V_253 , & V_4 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_252 , & V_4 . V_254 [ 1 ] , V_4 . V_254 [ 0 ] ) ;
return V_4 . V_254 [ 0 ] ;
}
T_13 F_38 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , const T_4 * V_252 )
{
union V_224 V_4 ;
if ( V_68 > V_255 )
V_68 = V_255 ;
V_4 . V_254 [ 0 ] = V_68 ;
memcpy ( & V_4 . V_254 [ 1 ] , V_252 , V_68 ) ;
return F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_231 , V_55 ,
V_253 , & V_4 ) ;
}
T_13 F_245 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , T_4 * V_252 )
{
union V_224 V_4 ;
int V_33 ;
if ( V_68 > V_255 )
V_68 = V_255 ;
V_4 . V_254 [ 0 ] = V_68 ;
V_33 = F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_228 , V_55 ,
V_256 , & V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
memcpy ( V_252 , & V_4 . V_254 [ 1 ] , V_4 . V_254 [ 0 ] ) ;
return V_4 . V_254 [ 0 ] ;
}
T_13 F_246 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , const T_4 * V_252 )
{
union V_224 V_4 ;
if ( V_68 > V_255 )
V_68 = V_255 ;
V_4 . V_254 [ 0 ] = V_68 ;
memcpy ( V_4 . V_254 + 1 , V_252 , V_68 ) ;
return F_232 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_231 , V_55 ,
V_256 , & V_4 ) ;
}
static T_13 F_247 ( struct V_25 * V_26 , T_8 V_11 ,
unsigned short V_16 ,
char V_257 , T_4 V_55 , int V_258 ,
union V_224 * V_4 )
{
unsigned char V_259 [ V_255 + 3 ] ;
unsigned char V_260 [ V_255 + 2 ] ;
int V_202 = V_257 == V_228 ? 2 : 1 ;
int V_106 ;
T_4 V_261 = 0 ;
int V_33 ;
struct V_46 V_200 [ 2 ] = {
{
. V_11 = V_11 ,
. V_16 = V_16 ,
. V_51 = 1 ,
. V_52 = V_259 ,
} , {
. V_11 = V_11 ,
. V_16 = V_16 | V_53 ,
. V_51 = 0 ,
. V_52 = V_260 ,
} ,
} ;
V_259 [ 0 ] = V_55 ;
switch ( V_258 ) {
case V_232 :
V_200 [ 0 ] . V_51 = 0 ;
V_200 [ 0 ] . V_16 = V_16 | ( V_257 == V_228 ?
V_53 : 0 ) ;
V_202 = 1 ;
break;
case V_234 :
if ( V_257 == V_228 ) {
V_200 [ 0 ] . V_16 = V_53 | V_16 ;
V_202 = 1 ;
}
break;
case V_229 :
if ( V_257 == V_228 )
V_200 [ 1 ] . V_51 = 1 ;
else {
V_200 [ 0 ] . V_51 = 2 ;
V_259 [ 1 ] = V_4 -> V_248 ;
}
break;
case V_250 :
if ( V_257 == V_228 )
V_200 [ 1 ] . V_51 = 2 ;
else {
V_200 [ 0 ] . V_51 = 3 ;
V_259 [ 1 ] = V_4 -> V_251 & 0xff ;
V_259 [ 2 ] = V_4 -> V_251 >> 8 ;
}
break;
case V_262 :
V_202 = 2 ;
V_257 = V_228 ;
V_200 [ 0 ] . V_51 = 3 ;
V_200 [ 1 ] . V_51 = 2 ;
V_259 [ 1 ] = V_4 -> V_251 & 0xff ;
V_259 [ 2 ] = V_4 -> V_251 >> 8 ;
break;
case V_253 :
if ( V_257 == V_228 ) {
V_200 [ 1 ] . V_16 |= V_222 ;
V_200 [ 1 ] . V_51 = 1 ;
} else {
V_200 [ 0 ] . V_51 = V_4 -> V_254 [ 0 ] + 2 ;
if ( V_200 [ 0 ] . V_51 > V_255 + 2 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_254 [ 0 ] ) ;
return - V_126 ;
}
for ( V_106 = 1 ; V_106 < V_200 [ 0 ] . V_51 ; V_106 ++ )
V_259 [ V_106 ] = V_4 -> V_254 [ V_106 - 1 ] ;
}
break;
case V_263 :
V_202 = 2 ;
V_257 = V_228 ;
if ( V_4 -> V_254 [ 0 ] > V_255 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_254 [ 0 ] ) ;
return - V_126 ;
}
V_200 [ 0 ] . V_51 = V_4 -> V_254 [ 0 ] + 2 ;
for ( V_106 = 1 ; V_106 < V_200 [ 0 ] . V_51 ; V_106 ++ )
V_259 [ V_106 ] = V_4 -> V_254 [ V_106 - 1 ] ;
V_200 [ 1 ] . V_16 |= V_222 ;
V_200 [ 1 ] . V_51 = 1 ;
break;
case V_256 :
if ( V_257 == V_228 ) {
V_200 [ 1 ] . V_51 = V_4 -> V_254 [ 0 ] ;
} else {
V_200 [ 0 ] . V_51 = V_4 -> V_254 [ 0 ] + 1 ;
if ( V_200 [ 0 ] . V_51 > V_255 + 1 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_254 [ 0 ] ) ;
return - V_126 ;
}
for ( V_106 = 1 ; V_106 <= V_4 -> V_254 [ 0 ] ; V_106 ++ )
V_259 [ V_106 ] = V_4 -> V_254 [ V_106 ] ;
}
break;
default:
F_17 ( & V_26 -> V_38 , L_101 , V_258 ) ;
return - V_114 ;
}
V_106 = ( ( V_16 & V_264 ) && V_258 != V_232
&& V_258 != V_256 ) ;
if ( V_106 ) {
if ( ! ( V_200 [ 0 ] . V_16 & V_53 ) ) {
if ( V_202 == 1 )
F_243 ( & V_200 [ 0 ] ) ;
else
V_261 = F_242 ( 0 , & V_200 [ 0 ] ) ;
}
if ( V_200 [ V_202 - 1 ] . V_16 & V_53 )
V_200 [ V_202 - 1 ] . V_51 ++ ;
}
V_33 = F_25 ( V_26 , V_200 , V_202 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_106 && ( V_200 [ V_202 - 1 ] . V_16 & V_53 ) ) {
V_33 = F_244 ( V_261 , & V_200 [ V_202 - 1 ] ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_257 == V_228 )
switch ( V_258 ) {
case V_234 :
V_4 -> V_248 = V_259 [ 0 ] ;
break;
case V_229 :
V_4 -> V_248 = V_260 [ 0 ] ;
break;
case V_250 :
case V_262 :
V_4 -> V_251 = V_260 [ 0 ] | ( V_260 [ 1 ] << 8 ) ;
break;
case V_256 :
for ( V_106 = 0 ; V_106 < V_4 -> V_254 [ 0 ] ; V_106 ++ )
V_4 -> V_254 [ V_106 + 1 ] = V_260 [ V_106 ] ;
break;
case V_253 :
case V_263 :
for ( V_106 = 0 ; V_106 < V_260 [ 0 ] + 1 ; V_106 ++ )
V_4 -> V_254 [ V_106 ] = V_260 [ V_106 ] ;
break;
}
return 0 ;
}
T_13 F_232 ( struct V_25 * V_26 , T_8 V_11 , unsigned short V_16 ,
char V_257 , T_4 V_55 , int V_265 ,
union V_224 * V_4 )
{
unsigned long V_217 ;
int V_218 ;
T_13 V_144 ;
F_248 ( V_26 , V_11 , V_16 , V_257 ,
V_55 , V_265 , V_4 ) ;
F_249 ( V_26 , V_11 , V_16 , V_257 ,
V_55 , V_265 ) ;
V_16 &= V_223 | V_264 | V_266 ;
if ( V_26 -> V_166 -> V_267 ) {
F_99 ( V_26 ) ;
V_217 = V_219 ;
for ( V_144 = 0 , V_218 = 0 ; V_218 <= V_26 -> V_220 ; V_218 ++ ) {
V_144 = V_26 -> V_166 -> V_267 ( V_26 , V_11 , V_16 ,
V_257 , V_55 ,
V_265 , V_4 ) ;
if ( V_144 != - V_164 )
break;
if ( F_221 ( V_219 ,
V_217 + V_26 -> V_167 ) )
break;
}
F_103 ( V_26 ) ;
if ( V_144 != - V_114 || ! V_26 -> V_166 -> V_221 )
goto V_268;
}
V_144 = F_247 ( V_26 , V_11 , V_16 , V_257 ,
V_55 , V_265 , V_4 ) ;
V_268:
F_250 ( V_26 , V_11 , V_16 , V_257 ,
V_55 , V_265 , V_4 ) ;
F_251 ( V_26 , V_11 , V_16 , V_257 ,
V_55 , V_265 , V_144 ) ;
return V_144 ;
}
int F_252 ( struct V_42 * V_43 , T_14 V_269 )
{
int V_31 ;
if ( ! V_43 || ! V_269 ) {
F_253 ( 1 , L_102 ) ;
return - V_126 ;
}
if ( ! ( V_43 -> V_16 & V_17 ) ) {
V_31 = F_92 ( V_43 -> V_11 ) ;
if ( V_31 ) {
F_17 ( & V_43 -> V_38 , L_103 , V_192 ) ;
return V_31 ;
}
}
if ( ! V_43 -> V_26 -> V_166 -> V_270 ) {
F_17 ( & V_43 -> V_38 , L_104 , V_192 ) ;
return - V_114 ;
}
V_43 -> V_269 = V_269 ;
F_99 ( V_43 -> V_26 ) ;
V_31 = V_43 -> V_26 -> V_166 -> V_270 ( V_43 ) ;
F_103 ( V_43 -> V_26 ) ;
if ( V_31 ) {
V_43 -> V_269 = NULL ;
F_17 ( & V_43 -> V_38 , L_105 , V_192 , V_31 ) ;
}
return V_31 ;
}
int F_254 ( struct V_42 * V_43 )
{
int V_31 ;
if ( ! V_43 -> V_26 -> V_166 -> V_271 ) {
F_17 ( & V_43 -> V_38 , L_104 , V_192 ) ;
return - V_114 ;
}
F_99 ( V_43 -> V_26 ) ;
V_31 = V_43 -> V_26 -> V_166 -> V_271 ( V_43 ) ;
F_103 ( V_43 -> V_26 ) ;
if ( V_31 == 0 )
V_43 -> V_269 = NULL ;
else
F_17 ( & V_43 -> V_38 , L_105 , V_192 , V_31 ) ;
return V_31 ;
}
