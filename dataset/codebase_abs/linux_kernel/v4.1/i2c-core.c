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
V_6 . V_35 = F_10 ( V_30 ) ;
V_6 . V_18 = - 1 ;
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
struct V_42 V_43 ;
struct V_2 * V_3 ;
T_3 V_64 = V_54 >> 16 ;
T_4 V_65 = V_54 & V_66 ;
T_1 V_31 ;
int V_33 ;
V_31 = F_30 ( V_6 -> V_67 , V_6 -> V_68 , & V_3 ) ;
if ( F_21 ( V_31 ) )
return V_31 ;
if ( ! V_57 || V_3 -> type != V_7 ) {
V_31 = V_69 ;
goto V_70;
}
V_9 = & V_3 -> V_4 . V_10 ;
if ( V_9 -> type != V_12 ) {
V_31 = V_69 ;
goto V_70;
}
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_26 = V_26 ;
V_43 . V_11 = V_9 -> V_13 ;
V_43 . V_16 = 0 ;
if ( V_9 -> V_14 == V_15 )
V_43 . V_16 |= V_17 ;
switch ( V_64 ) {
case V_71 :
if ( V_65 == V_72 ) {
V_33 = F_31 ( & V_43 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_73 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_32 ( & V_43 , V_61 -> V_73 ) ;
}
break;
case V_74 :
if ( V_65 == V_72 ) {
V_33 = F_33 ( & V_43 , V_55 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_73 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_34 ( & V_43 , V_55 ,
V_61 -> V_73 ) ;
}
break;
case V_75 :
if ( V_65 == V_72 ) {
V_33 = F_35 ( & V_43 , V_55 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_76 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_36 ( & V_43 , V_55 ,
V_61 -> V_76 ) ;
}
break;
case V_77 :
if ( V_65 == V_72 ) {
V_33 = F_37 ( & V_43 , V_55 ,
V_61 -> V_4 ) ;
if ( V_33 >= 0 ) {
V_61 -> V_51 = V_33 ;
V_33 = 0 ;
}
} else {
V_33 = F_38 ( & V_43 , V_55 ,
V_61 -> V_51 , V_61 -> V_4 ) ;
}
break;
case V_78 :
if ( V_65 == V_72 ) {
V_33 = F_23 ( & V_43 , V_55 ,
V_61 -> V_4 , V_6 -> V_79 ) ;
if ( V_33 > 0 )
V_33 = 0 ;
} else {
V_33 = F_28 ( & V_43 , V_55 ,
V_61 -> V_4 , V_6 -> V_79 ) ;
}
break;
default:
F_39 ( L_5 , V_64 ) ;
V_31 = V_69 ;
goto V_70;
}
V_61 -> V_33 = V_33 ;
V_70:
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
while ( V_106 ++ < V_108 * 2 ) {
if ( V_98 ) {
if ( V_101 -> V_104 && V_101 -> V_104 ( V_39 ) )
break;
if ( ! V_101 -> V_109 ( V_39 ) ) {
F_17 ( & V_39 -> V_38 ,
L_13 ) ;
V_31 = - V_110 ;
break;
}
}
V_98 = ! V_98 ;
V_101 -> V_111 ( V_39 , V_98 ) ;
F_71 ( V_112 ) ;
}
if ( V_101 -> V_113 )
V_101 -> V_113 ( V_39 ) ;
return V_31 ;
}
int F_72 ( struct V_25 * V_39 )
{
V_39 -> V_96 -> V_111 ( V_39 , 1 ) ;
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
if ( ! V_43 -> V_18 && V_38 -> V_116 ) {
int V_18 = F_76 ( V_38 -> V_116 , 0 ) ;
if ( V_18 == - V_117 )
return V_18 ;
if ( V_18 < 0 )
V_18 = 0 ;
V_43 -> V_18 = V_18 ;
}
V_90 = F_55 ( V_38 -> V_90 ) ;
if ( ! V_90 -> V_118 || ! V_90 -> V_91 )
return - V_80 ;
if ( ! F_77 ( & V_43 -> V_38 ) )
F_78 ( & V_43 -> V_38 ,
V_43 -> V_16 & V_119 ) ;
F_60 ( V_38 , L_15 ) ;
V_33 = F_79 ( V_38 -> V_116 , false ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_80 ( & V_43 -> V_38 , true ) ;
if ( V_33 != - V_117 ) {
V_33 = V_90 -> V_118 ( V_43 , F_50 ( V_90 -> V_91 ,
V_43 ) ) ;
if ( V_33 )
F_81 ( & V_43 -> V_38 , true ) ;
}
return V_33 ;
}
static int F_82 ( struct V_86 * V_38 )
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
F_81 ( & V_43 -> V_38 , true ) ;
return V_33 ;
}
static void F_83 ( struct V_86 * V_38 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_89 * V_90 ;
if ( ! V_43 || ! V_38 -> V_90 )
return;
V_90 = F_55 ( V_38 -> V_90 ) ;
if ( V_90 -> V_120 )
V_90 -> V_120 ( V_43 ) ;
}
static void F_84 ( struct V_86 * V_38 )
{
F_27 ( F_57 ( V_38 ) ) ;
}
static T_7
F_85 ( struct V_86 * V_38 , struct V_121 * V_122 , char * V_52 )
{
return sprintf ( V_52 , L_17 , V_38 -> type == & V_123 ?
F_57 ( V_38 ) -> V_85 : F_86 ( V_38 ) -> V_85 ) ;
}
static T_7
F_87 ( struct V_86 * V_38 , struct V_121 * V_122 , char * V_52 )
{
struct V_42 * V_43 = F_57 ( V_38 ) ;
int V_51 ;
V_51 = F_88 ( V_38 , V_52 , V_124 - 1 ) ;
if ( V_51 != - V_80 )
return V_51 ;
return sprintf ( V_52 , L_18 , V_95 , V_43 -> V_85 ) ;
}
struct V_42 * F_52 ( struct V_86 * V_38 )
{
return ( V_38 -> type == & V_123 )
? F_57 ( V_38 )
: NULL ;
}
static int F_89 ( const struct V_42 * V_43 )
{
if ( V_43 -> V_16 & V_17 ) {
if ( V_43 -> V_11 > 0x3ff )
return - V_125 ;
} else {
if ( V_43 -> V_11 == 0x00 || V_43 -> V_11 > 0x7f )
return - V_125 ;
}
return 0 ;
}
static int F_90 ( unsigned short V_11 )
{
if ( V_11 < 0x08 || V_11 > 0x77 )
return - V_125 ;
return 0 ;
}
static int F_91 ( struct V_86 * V_38 , void * V_126 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
int V_11 = * ( int * ) V_126 ;
if ( V_43 && V_43 -> V_11 == V_11 )
return - V_110 ;
return 0 ;
}
static int F_92 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_40 = F_93 ( V_26 ) ;
int V_127 ;
V_127 = F_94 ( & V_26 -> V_38 , & V_11 ,
F_91 ) ;
if ( ! V_127 && V_40 )
V_127 = F_92 ( V_40 , V_11 ) ;
return V_127 ;
}
static int F_95 ( struct V_86 * V_38 , void * V_126 )
{
int V_127 ;
if ( V_38 -> type == & V_128 )
V_127 = F_94 ( V_38 , V_126 ,
F_95 ) ;
else
V_127 = F_91 ( V_38 , V_126 ) ;
return V_127 ;
}
static int F_96 ( struct V_25 * V_26 , int V_11 )
{
struct V_25 * V_40 = F_93 ( V_26 ) ;
int V_127 = 0 ;
if ( V_40 )
V_127 = F_92 ( V_40 , V_11 ) ;
if ( ! V_127 )
V_127 = F_94 ( & V_26 -> V_38 , & V_11 ,
F_95 ) ;
return V_127 ;
}
void F_97 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_93 ( V_26 ) ;
if ( V_40 )
F_97 ( V_40 ) ;
else
F_98 ( & V_26 -> V_129 ) ;
}
static int F_99 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_93 ( V_26 ) ;
if ( V_40 )
return F_99 ( V_40 ) ;
else
return F_100 ( & V_26 -> V_129 ) ;
}
void F_101 ( struct V_25 * V_26 )
{
struct V_25 * V_40 = F_93 ( V_26 ) ;
if ( V_40 )
F_101 ( V_40 ) ;
else
F_102 ( & V_26 -> V_129 ) ;
}
static void F_103 ( struct V_25 * V_39 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_104 ( & V_43 -> V_38 ) ;
if ( V_30 ) {
F_105 ( & V_43 -> V_38 , L_19 , F_106 ( V_30 ) ) ;
return;
}
F_105 ( & V_43 -> V_38 , L_20 , F_107 ( V_39 ) ,
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
V_43 -> V_38 . V_130 = V_6 -> V_130 ;
if ( V_6 -> V_131 )
V_43 -> V_38 . V_131 = * V_6 -> V_131 ;
V_43 -> V_16 = V_6 -> V_16 ;
V_43 -> V_11 = V_6 -> V_11 ;
V_43 -> V_18 = V_6 -> V_18 ;
F_14 ( V_43 -> V_85 , V_6 -> type , sizeof( V_43 -> V_85 ) ) ;
V_33 = F_89 ( V_43 ) ;
if ( V_33 ) {
F_17 ( & V_39 -> V_38 , L_21 ,
V_43 -> V_16 & V_17 ? 10 : 7 , V_43 -> V_11 ) ;
goto V_132;
}
V_33 = F_96 ( V_39 , V_43 -> V_11 ) ;
if ( V_33 )
goto V_133;
V_43 -> V_38 . V_40 = & V_43 -> V_26 -> V_38 ;
V_43 -> V_38 . V_134 = & V_135 ;
V_43 -> V_38 . type = & V_123 ;
V_43 -> V_38 . V_116 = V_6 -> V_116 ;
V_43 -> V_38 . V_35 = V_6 -> V_35 ;
F_103 ( V_39 , V_43 ) ;
V_33 = F_108 ( & V_43 -> V_38 ) ;
if ( V_33 )
goto V_133;
F_60 ( & V_39 -> V_38 , L_22 ,
V_43 -> V_85 , F_15 ( & V_43 -> V_38 ) ) ;
return V_43 ;
V_133:
F_17 ( & V_39 -> V_38 , L_23
L_24 , V_43 -> V_85 , V_43 -> V_11 , V_33 ) ;
V_132:
F_27 ( V_43 ) ;
return NULL ;
}
void F_109 ( struct V_42 * V_43 )
{
F_110 ( & V_43 -> V_38 ) ;
}
static int F_111 ( struct V_42 * V_43 ,
const struct V_83 * V_84 )
{
return 0 ;
}
static int F_112 ( struct V_42 * V_43 )
{
return 0 ;
}
struct V_42 * F_113 ( struct V_25 * V_26 , T_8 V_136 )
{
struct V_5 V_6 = {
F_114 ( L_25 , V_136 ) ,
} ;
return F_16 ( V_26 , & V_6 ) ;
}
static void F_115 ( struct V_86 * V_38 )
{
struct V_25 * V_39 = F_86 ( V_38 ) ;
F_116 ( & V_39 -> V_137 ) ;
}
static inline unsigned int F_117 ( struct V_25 * V_26 )
{
unsigned int V_138 = 0 ;
while ( ( V_26 = F_93 ( V_26 ) ) )
V_138 ++ ;
return V_138 ;
}
static T_7
F_118 ( struct V_86 * V_38 , struct V_121 * V_122 ,
const char * V_52 , T_9 V_139 )
{
struct V_25 * V_39 = F_86 ( V_38 ) ;
struct V_5 V_6 ;
struct V_42 * V_43 ;
char * V_140 , V_141 ;
int V_142 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_140 = strchr ( V_52 , ' ' ) ;
if ( ! V_140 ) {
F_17 ( V_38 , L_26 , L_27 ) ;
return - V_125 ;
}
if ( V_140 - V_52 > V_143 - 1 ) {
F_17 ( V_38 , L_28 , L_27 ) ;
return - V_125 ;
}
memcpy ( V_6 . type , V_52 , V_140 - V_52 ) ;
V_142 = sscanf ( ++ V_140 , L_29 , & V_6 . V_11 , & V_141 ) ;
if ( V_142 < 1 ) {
F_17 ( V_38 , L_30 , L_27 ) ;
return - V_125 ;
}
if ( V_142 > 1 && V_141 != '\n' ) {
F_17 ( V_38 , L_31 , L_27 ) ;
return - V_125 ;
}
V_43 = F_16 ( V_39 , & V_6 ) ;
if ( ! V_43 )
return - V_125 ;
F_119 ( & V_39 -> V_144 ) ;
F_120 ( & V_43 -> V_145 , & V_39 -> V_146 ) ;
F_121 ( & V_39 -> V_144 ) ;
F_122 ( V_38 , L_32 , L_27 ,
V_6 . type , V_6 . V_11 ) ;
return V_139 ;
}
static T_7
F_123 ( struct V_86 * V_38 , struct V_121 * V_122 ,
const char * V_52 , T_9 V_139 )
{
struct V_25 * V_39 = F_86 ( V_38 ) ;
struct V_42 * V_43 , * V_147 ;
unsigned short V_11 ;
char V_141 ;
int V_142 ;
V_142 = sscanf ( V_52 , L_29 , & V_11 , & V_141 ) ;
if ( V_142 < 1 ) {
F_17 ( V_38 , L_30 , L_33 ) ;
return - V_125 ;
}
if ( V_142 > 1 && V_141 != '\n' ) {
F_17 ( V_38 , L_31 , L_33 ) ;
return - V_125 ;
}
V_142 = - V_148 ;
F_124 ( & V_39 -> V_144 ,
F_117 ( V_39 ) ) ;
F_125 (client, next, &adap->userspace_clients,
detected) {
if ( V_43 -> V_11 == V_11 ) {
F_122 ( V_38 , L_34 ,
L_33 , V_43 -> V_85 , V_43 -> V_11 ) ;
F_126 ( & V_43 -> V_145 ) ;
F_109 ( V_43 ) ;
V_142 = V_139 ;
break;
}
}
F_121 ( & V_39 -> V_144 ) ;
if ( V_142 < 0 )
F_17 ( V_38 , L_35 ,
L_33 ) ;
return V_142 ;
}
struct V_25 * F_127 ( struct V_86 * V_38 )
{
return ( V_38 -> type == & V_128 )
? F_86 ( V_38 )
: NULL ;
}
static void F_128 ( struct V_25 * V_26 )
{
struct V_149 * V_150 ;
F_129 ( & V_151 ) ;
F_130 (devinfo, &__i2c_board_list, list) {
if ( V_150 -> V_152 == V_26 -> V_153
&& ! F_16 ( V_26 ,
& V_150 -> V_154 ) )
F_17 ( & V_26 -> V_38 ,
L_36 ,
V_150 -> V_154 . V_11 ) ;
}
F_131 ( & V_151 ) ;
}
static struct V_42 * F_132 ( struct V_25 * V_39 ,
struct V_155 * V_156 )
{
struct V_42 * V_127 ;
struct V_5 V_6 = {} ;
struct V_157 V_158 = {} ;
const T_10 * V_11 ;
int V_51 ;
F_60 ( & V_39 -> V_38 , L_37 , V_156 -> V_159 ) ;
if ( F_133 ( V_156 , V_6 . type , sizeof( V_6 . type ) ) < 0 ) {
F_17 ( & V_39 -> V_38 , L_38 ,
V_156 -> V_159 ) ;
return F_134 ( - V_125 ) ;
}
V_11 = F_135 ( V_156 , L_39 , & V_51 ) ;
if ( ! V_11 || ( V_51 < sizeof( int ) ) ) {
F_17 ( & V_39 -> V_38 , L_40 ,
V_156 -> V_159 ) ;
return F_134 ( - V_125 ) ;
}
V_6 . V_11 = F_136 ( V_11 ) ;
if ( V_6 . V_11 > ( 1 << 10 ) - 1 ) {
F_17 ( & V_39 -> V_38 , L_41 ,
V_6 . V_11 , V_156 -> V_159 ) ;
return F_134 ( - V_125 ) ;
}
V_6 . V_116 = F_137 ( V_156 ) ;
V_6 . V_131 = & V_158 ;
if ( F_135 ( V_156 , L_42 , NULL ) )
V_6 . V_16 |= V_119 ;
V_127 = F_16 ( V_39 , & V_6 ) ;
if ( V_127 == NULL ) {
F_17 ( & V_39 -> V_38 , L_43 ,
V_156 -> V_159 ) ;
F_138 ( V_156 ) ;
return F_134 ( - V_125 ) ;
}
return V_127 ;
}
static void F_139 ( struct V_25 * V_39 )
{
struct V_155 * V_156 ;
if ( ! V_39 -> V_38 . V_116 )
return;
F_60 ( & V_39 -> V_38 , L_44 ) ;
F_140 (adap->dev.of_node, node)
F_132 ( V_39 , V_156 ) ;
}
static int F_141 ( struct V_86 * V_38 , void * V_4 )
{
return V_38 -> V_116 == V_4 ;
}
struct V_42 * F_142 ( struct V_155 * V_156 )
{
struct V_86 * V_38 ;
V_38 = F_143 ( & V_135 , NULL , V_156 ,
F_141 ) ;
if ( ! V_38 )
return NULL ;
return F_52 ( V_38 ) ;
}
struct V_25 * F_144 ( struct V_155 * V_156 )
{
struct V_86 * V_38 ;
V_38 = F_143 ( & V_135 , NULL , V_156 ,
F_141 ) ;
if ( ! V_38 )
return NULL ;
return F_127 ( V_38 ) ;
}
static void F_139 ( struct V_25 * V_39 ) { }
static int F_145 ( struct V_89 * V_90 ,
struct V_25 * V_39 )
{
F_146 ( V_39 , V_90 ) ;
if ( V_90 -> V_160 ) {
F_22 ( & V_39 -> V_38 , L_45 ,
V_90 -> V_90 . V_85 ) ;
F_22 ( & V_39 -> V_38 , L_46
L_47 ) ;
V_90 -> V_160 ( V_39 ) ;
}
return 0 ;
}
static int F_147 ( struct V_87 * V_161 , void * V_4 )
{
return F_145 ( F_55 ( V_161 ) , V_4 ) ;
}
static int F_148 ( struct V_25 * V_39 )
{
int V_142 = 0 ;
if ( F_149 ( F_150 ( ! V_135 . V_162 ) ) ) {
V_142 = - V_163 ;
goto V_164;
}
if ( F_149 ( V_39 -> V_85 [ 0 ] == '\0' ) ) {
F_151 ( L_48
L_49 ) ;
return - V_125 ;
}
if ( F_149 ( ! V_39 -> V_165 ) ) {
F_151 ( L_50
L_51 , V_39 -> V_85 ) ;
return - V_125 ;
}
F_152 ( & V_39 -> V_129 ) ;
F_153 ( & V_39 -> V_144 ) ;
F_11 ( & V_39 -> V_146 ) ;
if ( V_39 -> V_166 == 0 )
V_39 -> V_166 = V_167 ;
F_105 ( & V_39 -> V_38 , L_52 , V_39 -> V_153 ) ;
V_39 -> V_38 . V_134 = & V_135 ;
V_39 -> V_38 . type = & V_128 ;
V_142 = F_108 ( & V_39 -> V_38 ) ;
if ( V_142 )
goto V_164;
F_60 ( & V_39 -> V_38 , L_53 , V_39 -> V_85 ) ;
F_154 ( & V_39 -> V_38 ) ;
#ifdef F_155
V_142 = F_156 ( V_168 , & V_39 -> V_38 ,
V_39 -> V_38 . V_40 ) ;
if ( V_142 )
F_22 ( & V_39 -> V_38 ,
L_54 ) ;
#endif
if ( V_39 -> V_96 ) {
struct V_100 * V_101 = V_39 -> V_96 ;
if ( ! V_101 -> V_115 ) {
F_17 ( & V_39 -> V_38 , L_55 ) ;
V_39 -> V_96 = NULL ;
goto V_169;
}
if ( V_101 -> V_115 == F_73 ) {
if ( ! F_157 ( V_101 -> V_97 ) ) {
F_17 ( & V_39 -> V_38 , L_56 ) ;
V_39 -> V_96 = NULL ;
goto V_169;
}
if ( F_157 ( V_101 -> V_99 ) )
V_101 -> V_104 = F_65 ;
else
V_101 -> V_104 = NULL ;
V_101 -> V_109 = F_61 ;
V_101 -> V_111 = F_63 ;
} else if ( ! V_101 -> V_111 || ! V_101 -> V_109 ) {
F_17 ( & V_39 -> V_38 , L_57 ) ;
V_39 -> V_96 = NULL ;
}
}
V_169:
F_139 ( V_39 ) ;
F_18 ( V_39 ) ;
F_41 ( V_39 ) ;
if ( V_39 -> V_153 < V_170 )
F_128 ( V_39 ) ;
F_119 ( & V_171 ) ;
F_158 ( & V_135 , NULL , V_39 , F_147 ) ;
F_121 ( & V_171 ) ;
return 0 ;
V_164:
F_119 ( & V_171 ) ;
F_159 ( & V_172 , V_39 -> V_153 ) ;
F_121 ( & V_171 ) ;
return V_142 ;
}
static int F_160 ( struct V_25 * V_39 )
{
int V_84 ;
F_119 ( & V_171 ) ;
V_84 = F_161 ( & V_172 , V_39 , V_39 -> V_153 , V_39 -> V_153 + 1 ,
V_49 ) ;
F_121 ( & V_171 ) ;
if ( V_84 < 0 )
return V_84 == - V_173 ? - V_110 : V_84 ;
return F_148 ( V_39 ) ;
}
int F_162 ( struct V_25 * V_26 )
{
struct V_86 * V_38 = & V_26 -> V_38 ;
int V_84 ;
if ( V_38 -> V_116 ) {
V_84 = F_163 ( V_38 -> V_116 , L_58 ) ;
if ( V_84 >= 0 ) {
V_26 -> V_153 = V_84 ;
return F_160 ( V_26 ) ;
}
}
F_119 ( & V_171 ) ;
V_84 = F_161 ( & V_172 , V_26 ,
V_170 , 0 , V_49 ) ;
F_121 ( & V_171 ) ;
if ( V_84 < 0 )
return V_84 ;
V_26 -> V_153 = V_84 ;
return F_148 ( V_26 ) ;
}
int F_164 ( struct V_25 * V_39 )
{
if ( V_39 -> V_153 == - 1 )
return F_162 ( V_39 ) ;
return F_160 ( V_39 ) ;
}
static void F_165 ( struct V_89 * V_90 ,
struct V_25 * V_26 )
{
struct V_42 * V_43 , * V_174 ;
F_125 (client, _n, &driver->clients, detected) {
if ( V_43 -> V_26 == V_26 ) {
F_60 ( & V_26 -> V_38 , L_59 ,
V_43 -> V_85 , V_43 -> V_11 ) ;
F_126 ( & V_43 -> V_145 ) ;
F_109 ( V_43 ) ;
}
}
}
static int F_166 ( struct V_86 * V_38 , void * V_175 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
if ( V_43 && strcmp ( V_43 -> V_85 , L_25 ) )
F_109 ( V_43 ) ;
return 0 ;
}
static int F_167 ( struct V_86 * V_38 , void * V_175 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
if ( V_43 )
F_109 ( V_43 ) ;
return 0 ;
}
static int F_168 ( struct V_87 * V_161 , void * V_4 )
{
F_165 ( F_55 ( V_161 ) , V_4 ) ;
return 0 ;
}
void F_169 ( struct V_25 * V_39 )
{
struct V_25 * V_176 ;
struct V_42 * V_43 , * V_147 ;
F_119 ( & V_171 ) ;
V_176 = F_170 ( & V_172 , V_39 -> V_153 ) ;
F_121 ( & V_171 ) ;
if ( V_176 != V_39 ) {
F_171 ( L_60
L_61 , V_39 -> V_85 ) ;
return;
}
F_46 ( V_39 ) ;
F_119 ( & V_171 ) ;
F_158 ( & V_135 , NULL , V_39 ,
F_168 ) ;
F_121 ( & V_171 ) ;
F_124 ( & V_39 -> V_144 ,
F_117 ( V_39 ) ) ;
F_125 (client, next, &adap->userspace_clients,
detected) {
F_60 ( & V_39 -> V_38 , L_59 , V_43 -> V_85 ,
V_43 -> V_11 ) ;
F_126 ( & V_43 -> V_145 ) ;
F_109 ( V_43 ) ;
}
F_121 ( & V_39 -> V_144 ) ;
F_94 ( & V_39 -> V_38 , NULL , F_166 ) ;
F_94 ( & V_39 -> V_38 , NULL , F_167 ) ;
#ifdef F_155
F_172 ( V_168 , & V_39 -> V_38 ,
V_39 -> V_38 . V_40 ) ;
#endif
F_60 ( & V_39 -> V_38 , L_62 , V_39 -> V_85 ) ;
F_173 ( & V_39 -> V_137 ) ;
F_110 ( & V_39 -> V_38 ) ;
F_174 ( & V_39 -> V_137 ) ;
F_119 ( & V_171 ) ;
F_159 ( & V_172 , V_39 -> V_153 ) ;
F_121 ( & V_171 ) ;
memset ( & V_39 -> V_38 , 0 , sizeof( V_39 -> V_38 ) ) ;
}
int F_175 ( void * V_4 , int (* F_176)( struct V_86 * , void * ) )
{
int V_142 ;
F_119 ( & V_171 ) ;
V_142 = F_177 ( & V_135 , NULL , V_4 , F_176 ) ;
F_121 ( & V_171 ) ;
return V_142 ;
}
static int F_178 ( struct V_86 * V_38 , void * V_4 )
{
if ( V_38 -> type != & V_128 )
return 0 ;
return F_145 ( V_4 , F_86 ( V_38 ) ) ;
}
int F_179 ( struct V_177 * V_178 , struct V_89 * V_90 )
{
int V_142 ;
if ( F_149 ( F_150 ( ! V_135 . V_162 ) ) )
return - V_163 ;
V_90 -> V_90 . V_178 = V_178 ;
V_90 -> V_90 . V_134 = & V_135 ;
V_142 = F_180 ( & V_90 -> V_90 ) ;
if ( V_142 )
return V_142 ;
F_171 ( L_63 , V_90 -> V_90 . V_85 ) ;
F_11 ( & V_90 -> V_179 ) ;
F_175 ( V_90 , F_178 ) ;
return 0 ;
}
static int F_181 ( struct V_86 * V_38 , void * V_4 )
{
if ( V_38 -> type == & V_128 )
F_165 ( V_4 , F_86 ( V_38 ) ) ;
return 0 ;
}
void F_182 ( struct V_89 * V_90 )
{
F_175 ( V_90 , F_181 ) ;
F_183 ( & V_90 -> V_90 ) ;
F_171 ( L_64 , V_90 -> V_90 . V_85 ) ;
}
struct V_42 * F_184 ( struct V_42 * V_43 )
{
if ( V_43 && F_185 ( & V_43 -> V_38 ) )
return V_43 ;
return NULL ;
}
void F_186 ( struct V_42 * V_43 )
{
if ( V_43 )
F_187 ( & V_43 -> V_38 ) ;
}
static int F_188 ( struct V_86 * V_38 , void * V_180 )
{
struct V_42 * V_43 = F_52 ( V_38 ) ;
struct V_181 * V_182 = V_180 ;
struct V_89 * V_90 ;
if ( ! V_43 || ! V_43 -> V_38 . V_90 )
return 0 ;
V_90 = F_55 ( V_43 -> V_38 . V_90 ) ;
if ( V_90 -> V_55 )
V_90 -> V_55 ( V_43 , V_182 -> V_44 , V_182 -> V_182 ) ;
return 0 ;
}
void F_189 ( struct V_25 * V_39 , unsigned int V_44 , void * V_182 )
{
struct V_181 V_183 ;
V_183 . V_44 = V_44 ;
V_183 . V_182 = V_182 ;
F_94 ( & V_39 -> V_38 , & V_183 , F_188 ) ;
}
static int F_190 ( struct V_184 * V_185 , unsigned long V_65 ,
void * V_182 )
{
struct V_186 * V_187 = V_182 ;
struct V_25 * V_39 ;
struct V_42 * V_43 ;
switch ( F_191 ( V_65 , V_187 ) ) {
case V_188 :
V_39 = F_144 ( V_187 -> V_189 -> V_40 ) ;
if ( V_39 == NULL )
return V_190 ;
V_43 = F_132 ( V_39 , V_187 -> V_189 ) ;
F_187 ( & V_39 -> V_38 ) ;
if ( F_192 ( V_43 ) ) {
F_151 ( L_65 ,
V_191 , V_187 -> V_189 -> V_159 ) ;
return F_193 ( F_194 ( V_43 ) ) ;
}
break;
case V_192 :
V_43 = F_142 ( V_187 -> V_189 ) ;
if ( V_43 == NULL )
return V_190 ;
F_109 ( V_43 ) ;
F_187 ( & V_43 -> V_38 ) ;
break;
}
return V_190 ;
}
static int T_11 F_195 ( void )
{
int V_193 ;
V_193 = F_196 ( L_58 ) ;
F_197 ( & V_151 ) ;
if ( V_193 >= V_170 )
V_170 = V_193 + 1 ;
F_198 ( & V_151 ) ;
V_193 = F_199 ( & V_135 ) ;
if ( V_193 )
return V_193 ;
#ifdef F_155
V_168 = F_200 ( L_66 ) ;
if ( ! V_168 ) {
V_193 = - V_81 ;
goto V_194;
}
#endif
V_193 = F_201 ( & V_195 ) ;
if ( V_193 )
goto V_196;
if ( F_202 ( V_197 ) )
F_150 ( F_203 ( & V_198 ) ) ;
return 0 ;
V_196:
#ifdef F_155
F_204 ( V_168 ) ;
V_194:
#endif
F_205 ( & V_135 ) ;
return V_193 ;
}
static void T_12 F_206 ( void )
{
if ( F_202 ( V_197 ) )
F_150 ( F_207 ( & V_198 ) ) ;
F_182 ( & V_195 ) ;
#ifdef F_155
F_204 ( V_168 ) ;
#endif
F_205 ( & V_135 ) ;
F_208 () ;
}
static int F_209 ( struct V_25 * V_39 , struct V_46 * V_199 , char * V_200 )
{
F_210 ( & V_39 -> V_38 , L_67 ,
V_200 , V_199 -> V_11 , V_199 -> V_51 ,
V_199 -> V_16 & V_53 ? L_68 : L_69 ) ;
return - V_114 ;
}
static int F_211 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_201 )
{
const struct V_202 * V_203 = V_39 -> V_204 ;
int V_205 = V_203 -> V_206 , V_106 ;
bool V_207 = true ;
if ( V_203 -> V_16 & V_208 ) {
V_205 = 2 ;
if ( V_201 == 2 ) {
if ( V_203 -> V_16 & V_209 && V_47 [ 0 ] . V_16 & V_53 )
return F_209 ( V_39 , & V_47 [ 0 ] , L_70 ) ;
if ( V_203 -> V_16 & V_210 && ! ( V_47 [ 1 ] . V_16 & V_53 ) )
return F_209 ( V_39 , & V_47 [ 1 ] , L_71 ) ;
if ( V_203 -> V_16 & V_211 && V_47 [ 0 ] . V_11 != V_47 [ 1 ] . V_11 )
return F_209 ( V_39 , & V_47 [ 0 ] , L_72 ) ;
if ( F_212 ( V_47 [ 0 ] . V_51 , V_203 -> V_212 ) )
return F_209 ( V_39 , & V_47 [ 0 ] , L_73 ) ;
if ( F_212 ( V_47 [ 1 ] . V_51 , V_203 -> V_213 ) )
return F_209 ( V_39 , & V_47 [ 1 ] , L_73 ) ;
V_207 = false ;
}
}
if ( F_212 ( V_201 , V_205 ) )
return F_209 ( V_39 , & V_47 [ 0 ] , L_74 ) ;
for ( V_106 = 0 ; V_106 < V_201 ; V_106 ++ ) {
T_8 V_51 = V_47 [ V_106 ] . V_51 ;
if ( V_47 [ V_106 ] . V_16 & V_53 ) {
if ( V_207 && F_212 ( V_51 , V_203 -> V_214 ) )
return F_209 ( V_39 , & V_47 [ V_106 ] , L_73 ) ;
} else {
if ( V_207 && F_212 ( V_51 , V_203 -> V_215 ) )
return F_209 ( V_39 , & V_47 [ V_106 ] , L_73 ) ;
}
}
return 0 ;
}
int F_213 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_201 )
{
unsigned long V_216 ;
int V_31 , V_217 ;
if ( V_39 -> V_204 && F_211 ( V_39 , V_47 , V_201 ) )
return - V_114 ;
if ( F_214 ( & V_1 ) ) {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_201 ; V_106 ++ )
if ( V_47 [ V_106 ] . V_16 & V_53 )
F_215 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
else
F_216 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
}
V_216 = V_218 ;
for ( V_31 = 0 , V_217 = 0 ; V_217 <= V_39 -> V_219 ; V_217 ++ ) {
V_31 = V_39 -> V_165 -> V_220 ( V_39 , V_47 , V_201 ) ;
if ( V_31 != - V_163 )
break;
if ( F_217 ( V_218 , V_216 + V_39 -> V_166 ) )
break;
}
if ( F_214 ( & V_1 ) ) {
int V_106 ;
for ( V_106 = 0 ; V_106 < V_31 ; V_106 ++ )
if ( V_47 [ V_106 ] . V_16 & V_53 )
F_218 ( V_39 , & V_47 [ V_106 ] , V_106 ) ;
F_219 ( V_39 , V_106 , V_31 ) ;
}
return V_31 ;
}
int F_25 ( struct V_25 * V_39 , struct V_46 * V_47 , int V_201 )
{
int V_31 ;
if ( V_39 -> V_165 -> V_220 ) {
#ifdef F_220
for ( V_31 = 0 ; V_31 < V_201 ; V_31 ++ ) {
F_60 ( & V_39 -> V_38 , L_75
L_76 , V_31 , ( V_47 [ V_31 ] . V_16 & V_53 )
? 'R' : 'W' , V_47 [ V_31 ] . V_11 , V_47 [ V_31 ] . V_51 ,
( V_47 [ V_31 ] . V_16 & V_221 ) ? L_77 : L_78 ) ;
}
#endif
if ( F_221 () || F_222 () ) {
V_31 = F_99 ( V_39 ) ;
if ( ! V_31 )
return - V_163 ;
} else {
F_97 ( V_39 ) ;
}
V_31 = F_213 ( V_39 , V_47 , V_201 ) ;
F_101 ( V_39 ) ;
return V_31 ;
} else {
F_60 ( & V_39 -> V_38 , L_79 ) ;
return - V_114 ;
}
}
int F_223 ( const struct V_42 * V_43 , const char * V_52 , int V_139 )
{
int V_31 ;
struct V_25 * V_39 = V_43 -> V_26 ;
struct V_46 V_199 ;
V_199 . V_11 = V_43 -> V_11 ;
V_199 . V_16 = V_43 -> V_16 & V_222 ;
V_199 . V_51 = V_139 ;
V_199 . V_52 = ( char * ) V_52 ;
V_31 = F_25 ( V_39 , & V_199 , 1 ) ;
return ( V_31 == 1 ) ? V_139 : V_31 ;
}
int F_224 ( const struct V_42 * V_43 , char * V_52 , int V_139 )
{
struct V_25 * V_39 = V_43 -> V_26 ;
struct V_46 V_199 ;
int V_31 ;
V_199 . V_11 = V_43 -> V_11 ;
V_199 . V_16 = V_43 -> V_16 & V_222 ;
V_199 . V_16 |= V_53 ;
V_199 . V_51 = V_139 ;
V_199 . V_52 = V_52 ;
V_31 = F_25 ( V_39 , & V_199 , 1 ) ;
return ( V_31 == 1 ) ? V_139 : V_31 ;
}
static int F_225 ( struct V_25 * V_39 , unsigned short V_11 )
{
int V_70 ;
union V_223 V_175 ;
#ifdef F_226
if ( V_11 == 0x73 && ( V_39 -> V_224 & V_225 )
&& F_227 ( V_39 , V_226 ) )
V_70 = F_228 ( V_39 , V_11 , 0 , V_227 , 0 ,
V_228 , & V_175 ) ;
else
#endif
if ( ! ( ( V_11 & ~ 0x07 ) == 0x30 || ( V_11 & ~ 0x0f ) == 0x50 )
&& F_227 ( V_39 , V_229 ) )
V_70 = F_228 ( V_39 , V_11 , 0 , V_230 , 0 ,
V_231 , NULL ) ;
else if ( F_227 ( V_39 , V_232 ) )
V_70 = F_228 ( V_39 , V_11 , 0 , V_227 , 0 ,
V_233 , & V_175 ) ;
else {
F_22 ( & V_39 -> V_38 , L_80 ,
V_11 ) ;
V_70 = - V_114 ;
}
return V_70 >= 0 ;
}
static int F_229 ( struct V_42 * V_234 ,
struct V_89 * V_90 )
{
struct V_5 V_6 ;
struct V_25 * V_26 = V_234 -> V_26 ;
int V_11 = V_234 -> V_11 ;
int V_70 ;
V_70 = F_90 ( V_11 ) ;
if ( V_70 ) {
F_22 ( & V_26 -> V_38 , L_81 ,
V_11 ) ;
return V_70 ;
}
if ( F_96 ( V_26 , V_11 ) )
return 0 ;
if ( ! F_225 ( V_26 , V_11 ) )
return 0 ;
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_11 = V_11 ;
V_70 = V_90 -> V_235 ( V_234 , & V_6 ) ;
if ( V_70 ) {
return V_70 == - V_80 ? 0 : V_70 ;
}
if ( V_6 . type [ 0 ] == '\0' ) {
F_17 ( & V_26 -> V_38 , L_82
L_83 , V_90 -> V_90 . V_85 ,
V_11 ) ;
} else {
struct V_42 * V_43 ;
if ( V_26 -> V_224 & V_236 )
F_22 ( & V_26 -> V_38 ,
L_84
L_85
L_86 ,
V_6 . V_11 ) ;
F_60 ( & V_26 -> V_38 , L_87 ,
V_6 . type , V_6 . V_11 ) ;
V_43 = F_16 ( V_26 , & V_6 ) ;
if ( V_43 )
F_120 ( & V_43 -> V_145 , & V_90 -> V_179 ) ;
else
F_17 ( & V_26 -> V_38 , L_88 ,
V_6 . type , V_6 . V_11 ) ;
}
return 0 ;
}
static int F_146 ( struct V_25 * V_26 , struct V_89 * V_90 )
{
const unsigned short * V_237 ;
struct V_42 * V_234 ;
int V_106 , V_70 = 0 ;
int V_238 = F_107 ( V_26 ) ;
V_237 = V_90 -> V_237 ;
if ( ! V_90 -> V_235 || ! V_237 )
return 0 ;
if ( V_26 -> V_224 == V_236 ) {
F_60 ( & V_26 -> V_38 ,
L_89
L_90
L_91 ,
V_90 -> V_90 . V_85 ) ;
return 0 ;
}
if ( ! ( V_26 -> V_224 & V_90 -> V_224 ) )
return 0 ;
V_234 = F_24 ( sizeof( struct V_42 ) , V_49 ) ;
if ( ! V_234 )
return - V_81 ;
V_234 -> V_26 = V_26 ;
for ( V_106 = 0 ; V_237 [ V_106 ] != V_239 ; V_106 += 1 ) {
F_60 ( & V_26 -> V_38 , L_92
L_93 , V_238 , V_237 [ V_106 ] ) ;
V_234 -> V_11 = V_237 [ V_106 ] ;
V_70 = F_229 ( V_234 , V_90 ) ;
if ( F_149 ( V_70 ) )
break;
}
F_27 ( V_234 ) ;
return V_70 ;
}
int F_230 ( struct V_25 * V_39 , unsigned short V_11 )
{
return F_228 ( V_39 , V_11 , 0 , V_227 , 0 ,
V_231 , NULL ) >= 0 ;
}
struct V_42 *
F_231 ( struct V_25 * V_39 ,
struct V_5 * V_6 ,
unsigned short const * V_240 ,
int (* V_118)( struct V_25 * , unsigned short V_11 ) )
{
int V_106 ;
if ( ! V_118 )
V_118 = F_225 ;
for ( V_106 = 0 ; V_240 [ V_106 ] != V_239 ; V_106 ++ ) {
if ( F_90 ( V_240 [ V_106 ] ) < 0 ) {
F_22 ( & V_39 -> V_38 , L_94
L_95 , V_240 [ V_106 ] ) ;
continue;
}
if ( F_96 ( V_39 , V_240 [ V_106 ] ) ) {
F_60 ( & V_39 -> V_38 , L_96
L_97 , V_240 [ V_106 ] ) ;
continue;
}
if ( V_118 ( V_39 , V_240 [ V_106 ] ) )
break;
}
if ( V_240 [ V_106 ] == V_239 ) {
F_60 ( & V_39 -> V_38 , L_98 ) ;
return NULL ;
}
V_6 -> V_11 = V_240 [ V_106 ] ;
return F_16 ( V_39 , V_6 ) ;
}
struct V_25 * F_232 ( int V_153 )
{
struct V_25 * V_26 ;
F_119 ( & V_171 ) ;
V_26 = F_170 ( & V_172 , V_153 ) ;
if ( V_26 && ! F_233 ( V_26 -> V_178 ) )
V_26 = NULL ;
F_121 ( & V_171 ) ;
return V_26 ;
}
void F_234 ( struct V_25 * V_39 )
{
if ( V_39 )
F_235 ( V_39 -> V_178 ) ;
}
static T_4 F_236 ( T_8 V_4 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < 8 ; V_106 ++ ) {
if ( V_4 & 0x8000 )
V_4 = V_4 ^ V_241 ;
V_4 = V_4 << 1 ;
}
return ( T_4 ) ( V_4 >> 8 ) ;
}
static T_4 F_237 ( T_4 V_242 , T_4 * V_162 , T_9 V_139 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_139 ; V_106 ++ )
V_242 = F_236 ( ( V_242 ^ V_162 [ V_106 ] ) << 8 ) ;
return V_242 ;
}
static T_4 F_238 ( T_4 V_243 , struct V_46 * V_199 )
{
T_4 V_11 = ( V_199 -> V_11 << 1 ) | ! ! ( V_199 -> V_16 & V_53 ) ;
V_243 = F_237 ( V_243 , & V_11 , 1 ) ;
return F_237 ( V_243 , V_199 -> V_52 , V_199 -> V_51 ) ;
}
static inline void F_239 ( struct V_46 * V_199 )
{
V_199 -> V_52 [ V_199 -> V_51 ] = F_238 ( 0 , V_199 ) ;
V_199 -> V_51 ++ ;
}
static int F_240 ( T_4 V_244 , struct V_46 * V_199 )
{
T_4 V_245 = V_199 -> V_52 [ -- V_199 -> V_51 ] ;
V_244 = F_238 ( V_244 , V_199 ) ;
if ( V_245 != V_244 ) {
F_171 ( L_99 ,
V_245 , V_244 ) ;
return - V_246 ;
}
return 0 ;
}
T_13 F_31 ( const struct V_42 * V_43 )
{
union V_223 V_4 ;
int V_33 ;
V_33 = F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_227 , 0 ,
V_233 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_247 ;
}
T_13 F_32 ( const struct V_42 * V_43 , T_4 V_248 )
{
return F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_230 , V_248 , V_233 , NULL ) ;
}
T_13 F_33 ( const struct V_42 * V_43 , T_4 V_55 )
{
union V_223 V_4 ;
int V_33 ;
V_33 = F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_227 , V_55 ,
V_228 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_247 ;
}
T_13 F_34 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_248 )
{
union V_223 V_4 ;
V_4 . V_247 = V_248 ;
return F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_230 , V_55 ,
V_228 , & V_4 ) ;
}
T_13 F_35 ( const struct V_42 * V_43 , T_4 V_55 )
{
union V_223 V_4 ;
int V_33 ;
V_33 = F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_227 , V_55 ,
V_249 , & V_4 ) ;
return ( V_33 < 0 ) ? V_33 : V_4 . V_250 ;
}
T_13 F_36 ( const struct V_42 * V_43 , T_4 V_55 ,
T_8 V_248 )
{
union V_223 V_4 ;
V_4 . V_250 = V_248 ;
return F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_230 , V_55 ,
V_249 , & V_4 ) ;
}
T_13 F_37 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 * V_251 )
{
union V_223 V_4 ;
int V_33 ;
V_33 = F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_227 , V_55 ,
V_252 , & V_4 ) ;
if ( V_33 )
return V_33 ;
memcpy ( V_251 , & V_4 . V_253 [ 1 ] , V_4 . V_253 [ 0 ] ) ;
return V_4 . V_253 [ 0 ] ;
}
T_13 F_38 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , const T_4 * V_251 )
{
union V_223 V_4 ;
if ( V_68 > V_254 )
V_68 = V_254 ;
V_4 . V_253 [ 0 ] = V_68 ;
memcpy ( & V_4 . V_253 [ 1 ] , V_251 , V_68 ) ;
return F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_230 , V_55 ,
V_252 , & V_4 ) ;
}
T_13 F_241 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , T_4 * V_251 )
{
union V_223 V_4 ;
int V_33 ;
if ( V_68 > V_254 )
V_68 = V_254 ;
V_4 . V_253 [ 0 ] = V_68 ;
V_33 = F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_227 , V_55 ,
V_255 , & V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
memcpy ( V_251 , & V_4 . V_253 [ 1 ] , V_4 . V_253 [ 0 ] ) ;
return V_4 . V_253 [ 0 ] ;
}
T_13 F_242 ( const struct V_42 * V_43 , T_4 V_55 ,
T_4 V_68 , const T_4 * V_251 )
{
union V_223 V_4 ;
if ( V_68 > V_254 )
V_68 = V_254 ;
V_4 . V_253 [ 0 ] = V_68 ;
memcpy ( V_4 . V_253 + 1 , V_251 , V_68 ) ;
return F_228 ( V_43 -> V_26 , V_43 -> V_11 , V_43 -> V_16 ,
V_230 , V_55 ,
V_255 , & V_4 ) ;
}
static T_13 F_243 ( struct V_25 * V_26 , T_8 V_11 ,
unsigned short V_16 ,
char V_256 , T_4 V_55 , int V_257 ,
union V_223 * V_4 )
{
unsigned char V_258 [ V_254 + 3 ] ;
unsigned char V_259 [ V_254 + 2 ] ;
int V_201 = V_256 == V_227 ? 2 : 1 ;
int V_106 ;
T_4 V_260 = 0 ;
int V_33 ;
struct V_46 V_199 [ 2 ] = {
{
. V_11 = V_11 ,
. V_16 = V_16 ,
. V_51 = 1 ,
. V_52 = V_258 ,
} , {
. V_11 = V_11 ,
. V_16 = V_16 | V_53 ,
. V_51 = 0 ,
. V_52 = V_259 ,
} ,
} ;
V_258 [ 0 ] = V_55 ;
switch ( V_257 ) {
case V_231 :
V_199 [ 0 ] . V_51 = 0 ;
V_199 [ 0 ] . V_16 = V_16 | ( V_256 == V_227 ?
V_53 : 0 ) ;
V_201 = 1 ;
break;
case V_233 :
if ( V_256 == V_227 ) {
V_199 [ 0 ] . V_16 = V_53 | V_16 ;
V_201 = 1 ;
}
break;
case V_228 :
if ( V_256 == V_227 )
V_199 [ 1 ] . V_51 = 1 ;
else {
V_199 [ 0 ] . V_51 = 2 ;
V_258 [ 1 ] = V_4 -> V_247 ;
}
break;
case V_249 :
if ( V_256 == V_227 )
V_199 [ 1 ] . V_51 = 2 ;
else {
V_199 [ 0 ] . V_51 = 3 ;
V_258 [ 1 ] = V_4 -> V_250 & 0xff ;
V_258 [ 2 ] = V_4 -> V_250 >> 8 ;
}
break;
case V_261 :
V_201 = 2 ;
V_256 = V_227 ;
V_199 [ 0 ] . V_51 = 3 ;
V_199 [ 1 ] . V_51 = 2 ;
V_258 [ 1 ] = V_4 -> V_250 & 0xff ;
V_258 [ 2 ] = V_4 -> V_250 >> 8 ;
break;
case V_252 :
if ( V_256 == V_227 ) {
V_199 [ 1 ] . V_16 |= V_221 ;
V_199 [ 1 ] . V_51 = 1 ;
} else {
V_199 [ 0 ] . V_51 = V_4 -> V_253 [ 0 ] + 2 ;
if ( V_199 [ 0 ] . V_51 > V_254 + 2 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_253 [ 0 ] ) ;
return - V_125 ;
}
for ( V_106 = 1 ; V_106 < V_199 [ 0 ] . V_51 ; V_106 ++ )
V_258 [ V_106 ] = V_4 -> V_253 [ V_106 - 1 ] ;
}
break;
case V_262 :
V_201 = 2 ;
V_256 = V_227 ;
if ( V_4 -> V_253 [ 0 ] > V_254 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_253 [ 0 ] ) ;
return - V_125 ;
}
V_199 [ 0 ] . V_51 = V_4 -> V_253 [ 0 ] + 2 ;
for ( V_106 = 1 ; V_106 < V_199 [ 0 ] . V_51 ; V_106 ++ )
V_258 [ V_106 ] = V_4 -> V_253 [ V_106 - 1 ] ;
V_199 [ 1 ] . V_16 |= V_221 ;
V_199 [ 1 ] . V_51 = 1 ;
break;
case V_255 :
if ( V_256 == V_227 ) {
V_199 [ 1 ] . V_51 = V_4 -> V_253 [ 0 ] ;
} else {
V_199 [ 0 ] . V_51 = V_4 -> V_253 [ 0 ] + 1 ;
if ( V_199 [ 0 ] . V_51 > V_254 + 1 ) {
F_17 ( & V_26 -> V_38 ,
L_100 ,
V_4 -> V_253 [ 0 ] ) ;
return - V_125 ;
}
for ( V_106 = 1 ; V_106 <= V_4 -> V_253 [ 0 ] ; V_106 ++ )
V_258 [ V_106 ] = V_4 -> V_253 [ V_106 ] ;
}
break;
default:
F_17 ( & V_26 -> V_38 , L_101 , V_257 ) ;
return - V_114 ;
}
V_106 = ( ( V_16 & V_263 ) && V_257 != V_231
&& V_257 != V_255 ) ;
if ( V_106 ) {
if ( ! ( V_199 [ 0 ] . V_16 & V_53 ) ) {
if ( V_201 == 1 )
F_239 ( & V_199 [ 0 ] ) ;
else
V_260 = F_238 ( 0 , & V_199 [ 0 ] ) ;
}
if ( V_199 [ V_201 - 1 ] . V_16 & V_53 )
V_199 [ V_201 - 1 ] . V_51 ++ ;
}
V_33 = F_25 ( V_26 , V_199 , V_201 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_106 && ( V_199 [ V_201 - 1 ] . V_16 & V_53 ) ) {
V_33 = F_240 ( V_260 , & V_199 [ V_201 - 1 ] ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( V_256 == V_227 )
switch ( V_257 ) {
case V_233 :
V_4 -> V_247 = V_258 [ 0 ] ;
break;
case V_228 :
V_4 -> V_247 = V_259 [ 0 ] ;
break;
case V_249 :
case V_261 :
V_4 -> V_250 = V_259 [ 0 ] | ( V_259 [ 1 ] << 8 ) ;
break;
case V_255 :
for ( V_106 = 0 ; V_106 < V_4 -> V_253 [ 0 ] ; V_106 ++ )
V_4 -> V_253 [ V_106 + 1 ] = V_259 [ V_106 ] ;
break;
case V_252 :
case V_262 :
for ( V_106 = 0 ; V_106 < V_259 [ 0 ] + 1 ; V_106 ++ )
V_4 -> V_253 [ V_106 ] = V_259 [ V_106 ] ;
break;
}
return 0 ;
}
T_13 F_228 ( struct V_25 * V_26 , T_8 V_11 , unsigned short V_16 ,
char V_256 , T_4 V_55 , int V_264 ,
union V_223 * V_4 )
{
unsigned long V_216 ;
int V_217 ;
T_13 V_142 ;
F_244 ( V_26 , V_11 , V_16 , V_256 ,
V_55 , V_264 , V_4 ) ;
F_245 ( V_26 , V_11 , V_16 , V_256 ,
V_55 , V_264 ) ;
V_16 &= V_222 | V_263 | V_265 ;
if ( V_26 -> V_165 -> V_266 ) {
F_97 ( V_26 ) ;
V_216 = V_218 ;
for ( V_142 = 0 , V_217 = 0 ; V_217 <= V_26 -> V_219 ; V_217 ++ ) {
V_142 = V_26 -> V_165 -> V_266 ( V_26 , V_11 , V_16 ,
V_256 , V_55 ,
V_264 , V_4 ) ;
if ( V_142 != - V_163 )
break;
if ( F_217 ( V_218 ,
V_216 + V_26 -> V_166 ) )
break;
}
F_101 ( V_26 ) ;
if ( V_142 != - V_114 || ! V_26 -> V_165 -> V_220 )
goto V_267;
}
V_142 = F_243 ( V_26 , V_11 , V_16 , V_256 ,
V_55 , V_264 , V_4 ) ;
V_267:
F_246 ( V_26 , V_11 , V_16 , V_256 ,
V_55 , V_264 , V_4 ) ;
F_247 ( V_26 , V_11 , V_16 , V_256 ,
V_55 , V_264 , V_142 ) ;
return V_142 ;
}
int F_248 ( struct V_42 * V_43 , T_14 V_268 )
{
int V_31 ;
if ( ! V_43 || ! V_268 )
return - V_125 ;
if ( ! ( V_43 -> V_16 & V_17 ) ) {
V_31 = F_90 ( V_43 -> V_11 ) ;
if ( V_31 )
return V_31 ;
}
if ( ! V_43 -> V_26 -> V_165 -> V_269 )
return - V_114 ;
V_43 -> V_268 = V_268 ;
F_97 ( V_43 -> V_26 ) ;
V_31 = V_43 -> V_26 -> V_165 -> V_269 ( V_43 ) ;
F_101 ( V_43 -> V_26 ) ;
if ( V_31 )
V_43 -> V_268 = NULL ;
return V_31 ;
}
int F_249 ( struct V_42 * V_43 )
{
int V_31 ;
if ( ! V_43 -> V_26 -> V_165 -> V_270 )
return - V_114 ;
F_97 ( V_43 -> V_26 ) ;
V_31 = V_43 -> V_26 -> V_165 -> V_270 ( V_43 ) ;
F_101 ( V_43 -> V_26 ) ;
if ( V_31 == 0 )
V_43 -> V_268 = NULL ;
return V_31 ;
}
