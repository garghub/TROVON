static inline struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
V_5 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
return F_1 ( V_6 , struct V_5 , V_7 ) ;
}
struct V_8 * F_2 ( struct V_8 * V_9 )
{
F_3 ( & V_9 -> V_10 ) ;
return V_9 ;
}
struct V_8 *
F_4 ( struct V_8 * V_9 )
{
return F_5 ( & V_9 -> V_10 ) ? V_9 : NULL ;
}
void F_6 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_18 != - 1 )
F_8 ( V_13 , V_9 -> V_18 ) ;
V_9 -> V_18 = - 1 ;
F_9 ( & V_12 -> V_17 ) ;
}
static void F_10 ( struct V_10 * V_10 )
{
struct V_8 * V_9 =
F_1 ( V_10 , struct V_8 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_18 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
V_9 -> V_19 = false ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_21 ) {
struct V_2 * V_3 = & V_9 -> V_21 -> V_4 ;
F_12 ( V_3 , false , false , false , NULL ) ;
if ( ! F_13 ( & V_9 -> V_22 ) &&
V_9 -> V_15 -> V_23 != NULL ) {
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
V_9 -> V_15 -> V_23 ( V_9 , false , & V_25 ) ;
}
V_9 -> V_26 = false ;
F_11 ( & V_9 -> V_22 ) ;
F_14 ( V_3 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
if ( F_16 ( V_9 -> V_27 != NULL ) ) {
V_9 -> V_27 ( V_9 ) ;
F_17 ( & V_12 -> V_28 ) ;
F_18 ( & V_9 -> V_29 ) ;
F_19 ( & V_12 -> V_28 ) ;
}
V_18 = V_9 -> V_18 ;
if ( V_9 -> V_30 != NULL )
V_9 -> V_30 ( V_9 ) ;
else
F_20 ( V_9 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_18 != - 1 )
F_8 ( V_13 , V_18 ) ;
}
void F_21 ( struct V_8 * * V_31 )
{
struct V_8 * V_9 = * V_31 ;
struct V_11 * V_12 = V_9 -> V_12 ;
* V_31 = NULL ;
F_7 ( & V_12 -> V_17 ) ;
F_22 ( & V_9 -> V_10 , F_10 ) ;
F_9 ( & V_12 -> V_17 ) ;
}
int F_23 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_32 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
F_24 ( V_9 -> V_18 != - 1 ) ;
F_25 ( V_33 ) ;
F_7 ( & V_12 -> V_17 ) ;
V_32 = F_26 ( V_13 , V_9 , 1 , 0 , V_34 ) ;
if ( V_32 >= 0 )
V_9 -> V_18 = V_32 ;
F_9 ( & V_12 -> V_17 ) ;
F_27 () ;
return V_32 < 0 ? V_32 : 0 ;
}
int F_28 ( struct V_11 * V_12 , struct V_8 * V_9 ,
bool V_35 ,
void (* V_30) ( struct V_8 * V_9 ) ,
const struct V_36 * V_15 )
{
F_29 ( & V_9 -> V_10 ) ;
V_9 -> V_27 = NULL ;
V_9 -> V_30 = V_30 ;
V_9 -> V_19 = false ;
V_9 -> V_12 = V_12 ;
V_9 -> V_15 = V_15 ;
F_30 ( & V_9 -> V_20 ) ;
F_30 ( & V_9 -> V_22 ) ;
F_30 ( & V_9 -> V_29 ) ;
V_9 -> V_18 = - 1 ;
V_9 -> V_21 = NULL ;
V_9 -> V_37 = 0 ;
V_9 -> V_26 = false ;
V_9 -> V_38 = false ;
if ( V_35 )
return 0 ;
else
return F_23 ( V_9 ) ;
}
void F_31 ( struct V_8 * V_9 ,
void (* V_27) ( struct V_8 * ) )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_7 ( & V_12 -> V_17 ) ;
V_9 -> V_19 = true ;
V_9 -> V_27 = V_27 ;
F_9 ( & V_12 -> V_17 ) ;
}
struct V_8 * F_32 ( struct V_11 * V_12 ,
struct V_13 * V_13 , int V_18 )
{
struct V_8 * V_9 ;
F_33 ( & V_12 -> V_17 ) ;
V_9 = F_34 ( V_13 , V_18 ) ;
if ( V_9 && V_9 -> V_19 )
F_3 ( & V_9 -> V_10 ) ;
else
V_9 = NULL ;
F_35 ( & V_12 -> V_17 ) ;
if ( F_36 ( V_9 == NULL ) )
return NULL ;
return V_9 ;
}
int F_37 ( struct V_11 * V_12 ,
struct V_39 * V_40 ,
T_1 V_41 ,
const struct V_42
* V_43 ,
struct V_8 * * V_31 )
{
struct V_44 * V_4 ;
struct V_8 * V_9 ;
int V_32 = - V_45 ;
V_4 = F_38 ( V_40 , V_41 ) ;
if ( F_36 ( V_4 == NULL ) )
return - V_45 ;
if ( F_36 ( F_39 ( V_4 ) != V_43 -> V_46 ) )
goto V_47;
V_9 = V_43 -> V_48 ( V_4 ) ;
F_33 ( & V_12 -> V_17 ) ;
if ( ! V_9 -> V_19 || V_9 -> V_30 != V_43 -> V_30 ) {
F_35 ( & V_12 -> V_17 ) ;
goto V_47;
}
F_3 ( & V_9 -> V_10 ) ;
F_35 ( & V_12 -> V_17 ) ;
* V_31 = V_9 ;
V_32 = 0 ;
V_47:
F_40 ( & V_4 ) ;
return V_32 ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_39 * V_40 ,
T_1 V_41 ,
struct V_49 * * V_50 ,
struct V_1 * * V_51 )
{
struct V_8 * V_9 ;
int V_32 ;
F_24 ( * V_50 || * V_51 ) ;
V_32 = F_37 ( V_12 , V_40 , V_41 ,
V_52 ,
& V_9 ) ;
if ( ! V_32 ) {
* V_50 = F_42 ( V_9 ) ;
return 0 ;
}
* V_50 = NULL ;
V_32 = F_43 ( V_40 , V_41 , V_51 ) ;
return V_32 ;
}
static T_2 F_44 ( struct V_11 * V_12 , T_2 V_53 ,
bool V_54 )
{
static T_2 V_55 , V_56 ;
T_2 V_57 = F_45 ( V_53 ) >> V_58 ;
T_2 V_59 = F_46 ( V_57 * sizeof( void * ) ) ;
if ( F_36 ( V_55 == 0 ) ) {
T_2 V_60 = F_46 ( V_61 ) ;
V_55 = V_60 +
F_46 ( sizeof( struct V_1 ) ) ;
V_56 = V_60 +
F_46 ( sizeof( struct V_5 ) ) ;
}
if ( V_12 -> V_62 == V_63 )
V_59 +=
F_46 ( V_57 * sizeof( V_64 ) ) ;
return ( ( V_54 ) ? V_56 : V_55 ) +
V_59 ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_20 ( V_6 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_5 * V_65 = V_5 ( V_3 ) ;
F_49 ( V_65 , V_66 ) ;
}
int F_50 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_53 , struct V_67 * V_68 ,
bool V_69 ,
void (* F_51) ( struct V_2 * V_3 ) )
{
struct V_70 * V_71 = & V_12 -> V_71 ;
T_2 V_72 ;
int V_32 ;
bool V_54 = ( F_51 == & F_48 ) ;
F_24 ( ! F_51 && ( ! V_54 && ( F_51 != F_47 ) ) ) ;
V_72 = F_44 ( V_12 , V_53 , V_54 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_30 ( & V_6 -> V_73 ) ;
V_32 = F_52 ( V_71 , & V_6 -> V_4 , V_53 ,
V_74 , V_68 ,
0 , V_69 ,
NULL , V_72 , NULL , F_51 ) ;
return V_32 ;
}
static void F_53 ( struct V_44 * * V_75 )
{
struct V_5 * V_65 ;
struct V_44 * V_4 = * V_75 ;
struct V_2 * V_3 ;
* V_75 = NULL ;
if ( F_36 ( V_4 == NULL ) )
return;
V_65 = F_1 ( V_4 , struct V_5 ,
V_66 . V_4 ) ;
V_3 = & V_65 -> V_7 . V_4 ;
F_54 ( & V_3 ) ;
}
static void F_55 ( struct V_44 * V_4 ,
enum V_76 V_77 )
{
struct V_5 * V_78 ;
V_78 = F_1 ( V_4 , struct V_5 , V_66 . V_4 ) ;
switch ( V_77 ) {
case V_79 :
F_56 ( & V_78 -> V_7 . V_4 ) ;
break;
default:
F_57 () ;
}
}
int F_58 ( struct V_11 * V_12 ,
struct V_39 * V_40 ,
T_1 V_53 ,
bool V_80 ,
T_1 * V_41 ,
struct V_1 * * V_81 )
{
struct V_5 * V_78 ;
struct V_2 * V_82 ;
int V_32 ;
V_78 = F_59 ( sizeof( * V_78 ) , V_33 ) ;
if ( F_36 ( V_78 == NULL ) ) {
F_60 ( L_1 ) ;
return - V_83 ;
}
V_32 = F_50 ( V_12 , & V_78 -> V_7 , V_53 ,
( V_12 -> V_84 ) ?
& V_85 :
& V_86 , true ,
& F_48 ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_82 = F_61 ( & V_78 -> V_7 . V_4 ) ;
V_32 = F_62 ( V_40 ,
V_53 ,
& V_78 -> V_66 ,
V_80 ,
V_87 ,
& F_53 ,
& F_55 ) ;
if ( F_36 ( V_32 != 0 ) ) {
F_54 ( & V_82 ) ;
goto V_88;
}
* V_81 = & V_78 -> V_7 ;
* V_41 = V_78 -> V_66 . V_4 . V_89 . V_90 ;
V_88:
return V_32 ;
}
int F_63 ( struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_5 * V_65 ;
if ( F_36 ( V_3 -> V_91 != F_48 ) )
return - V_92 ;
V_65 = V_5 ( V_3 ) ;
if ( F_16 ( F_64 ( V_40 , & V_65 -> V_66 . V_4 ) ) )
return 0 ;
F_60 ( L_2 ) ;
return - V_92 ;
}
static int F_65 ( struct V_5 * V_78 ,
struct V_39 * V_40 ,
T_1 V_93 )
{
struct V_2 * V_3 = & V_78 -> V_7 . V_4 ;
bool V_94 ;
int V_32 ;
if ( V_93 & V_95 ) {
struct V_70 * V_71 = V_3 -> V_71 ;
F_66 ( & V_71 -> V_96 ) ;
V_32 = F_67 ( V_3 , false , true ,
! ! ( V_93 & V_97 ) ) ;
F_68 ( & V_71 -> V_96 ) ;
return V_32 ;
}
V_32 = F_69
( V_3 , ! ! ( V_93 & V_97 ) ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_32 = F_70 ( V_40 , & V_78 -> V_66 . V_4 ,
V_79 , & V_94 ) ;
if ( V_32 != 0 || V_94 )
F_56 ( & V_78 -> V_7 . V_4 ) ;
return V_32 ;
}
static int F_71 ( T_1 V_41 ,
struct V_39 * V_40 ,
T_1 V_93 )
{
if ( ! ( V_93 & V_95 ) )
return F_72 ( V_40 , V_41 ,
V_79 ) ;
return 0 ;
}
int F_73 ( struct V_98 * V_99 , void * V_100 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 =
(struct V_103 * ) V_100 ;
struct V_1 * V_105 ;
struct V_5 * V_78 ;
struct V_39 * V_40 = F_74 ( V_102 ) -> V_40 ;
int V_32 ;
if ( ( V_104 -> V_93 & ( V_106 | V_107 ) ) == 0
|| ( V_104 -> V_93 & ~ ( V_106 | V_107 |
V_97 |
V_95 ) ) != 0 ) {
F_60 ( L_3 ) ;
return - V_45 ;
}
switch ( V_104 -> V_108 ) {
case V_109 :
V_32 = F_43 ( V_40 , V_104 -> V_41 , & V_105 ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_78 = F_1 ( V_105 , struct V_5 ,
V_7 ) ;
V_32 = F_65 ( V_78 , V_40 , V_104 -> V_93 ) ;
F_15 ( & V_105 ) ;
if ( F_36 ( V_32 != 0 && V_32 != - V_110 &&
V_32 != - V_111 ) ) {
F_60 ( L_4 ,
( unsigned int ) V_104 -> V_41 ) ;
return V_32 ;
}
break;
case V_112 :
V_32 = F_71 ( V_104 -> V_41 , V_40 ,
V_104 -> V_93 ) ;
if ( F_36 ( V_32 != 0 ) ) {
F_60 ( L_5 ,
( unsigned int ) V_104 -> V_41 ) ;
return V_32 ;
}
break;
default:
F_60 ( L_6 ) ;
return - V_45 ;
}
return 0 ;
}
int F_75 ( struct V_98 * V_99 , void * V_100 ,
struct V_101 * V_102 )
{
struct V_11 * V_12 = F_76 ( V_99 ) ;
union V_113 * V_104 =
(union V_113 * ) V_100 ;
struct V_114 * V_115 = & V_104 -> V_115 ;
struct V_116 * V_117 = & V_104 -> V_117 ;
struct V_1 * V_105 ;
T_1 V_41 ;
int V_32 ;
V_32 = F_77 ( & V_12 -> V_118 , true ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_32 = F_58 ( V_12 , F_74 ( V_102 ) -> V_40 ,
V_115 -> V_53 , false , & V_41 , & V_105 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_119;
V_117 -> V_41 = V_41 ;
V_117 -> V_120 = F_78 ( & V_105 -> V_4 . V_121 ) ;
V_117 -> V_122 = V_41 ;
V_117 -> V_123 = 0 ;
F_15 ( & V_105 ) ;
V_119:
F_79 ( & V_12 -> V_118 ) ;
return V_32 ;
}
int F_80 ( struct V_98 * V_99 , void * V_100 ,
struct V_101 * V_102 )
{
struct V_124 * V_104 =
(struct V_124 * ) V_100 ;
return F_72 ( F_74 ( V_102 ) -> V_40 ,
V_104 -> V_41 ,
V_125 ) ;
}
int F_43 ( struct V_39 * V_40 ,
T_1 V_41 , struct V_1 * * V_126 )
{
struct V_5 * V_65 ;
struct V_44 * V_4 ;
V_4 = F_38 ( V_40 , V_41 ) ;
if ( F_36 ( V_4 == NULL ) ) {
F_81 ( V_127 L_7 ,
( unsigned long ) V_41 ) ;
return - V_128 ;
}
if ( F_36 ( F_39 ( V_4 ) != V_87 ) ) {
F_40 ( & V_4 ) ;
F_81 ( V_127 L_7 ,
( unsigned long ) V_41 ) ;
return - V_45 ;
}
V_65 = F_1 ( V_4 , struct V_5 ,
V_66 . V_4 ) ;
( void ) F_61 ( & V_65 -> V_7 . V_4 ) ;
F_40 ( & V_4 ) ;
* V_126 = & V_65 -> V_7 ;
return 0 ;
}
int F_82 ( struct V_39 * V_40 ,
struct V_1 * V_105 ,
T_1 * V_41 )
{
struct V_5 * V_78 ;
if ( V_105 -> V_4 . V_91 != F_48 )
return - V_45 ;
V_78 = F_1 ( V_105 , struct V_5 , V_7 ) ;
* V_41 = V_78 -> V_66 . V_4 . V_89 . V_90 ;
return F_70 ( V_40 , & V_78 -> V_66 . V_4 ,
V_125 , NULL ) ;
}
static void F_83 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_129 * V_130 ;
int V_32 ;
F_84 ( L_8 , V_131 ) ;
V_130 = F_1 ( V_9 , struct V_129 , V_9 ) ;
V_32 = F_85 ( V_12 , V_130 -> V_132 ) ;
F_86 ( V_32 != 0 ) ;
}
static int F_87 ( struct V_11 * V_12 ,
struct V_129 * V_130 ,
void (* V_30) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_130 -> V_9 ;
int V_32 ;
V_32 = F_28 ( V_12 , V_9 , false , V_30 ,
& V_133 ) ;
if ( F_36 ( V_32 != 0 ) ) {
if ( V_30 == NULL )
F_20 ( V_130 ) ;
else
V_30 ( & V_130 -> V_9 ) ;
return V_32 ;
}
V_32 = F_88 ( V_12 , & V_130 -> V_132 ) ;
if ( V_32 ) {
F_21 ( & V_9 ) ;
return V_32 ;
}
F_84 ( L_9 , V_131 ) ;
F_31 ( & V_130 -> V_9 , F_83 ) ;
return 0 ;
}
static void F_89 ( struct V_8 * V_9 )
{
struct V_134 * V_130 =
F_1 ( V_9 , struct V_134 , V_130 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_90 ( V_130 , V_4 ) ;
F_91 ( F_92 ( V_12 ) ,
V_135 ) ;
}
static void F_93 ( struct V_44 * * V_75 )
{
struct V_44 * V_4 = * V_75 ;
struct V_134 * V_130 =
F_1 ( V_4 , struct V_134 , V_4 ) ;
struct V_8 * V_9 = & V_130 -> V_130 . V_9 ;
* V_75 = NULL ;
F_21 ( & V_9 ) ;
}
int F_94 ( struct V_98 * V_99 , void * V_100 ,
struct V_101 * V_102 )
{
struct V_11 * V_12 = F_76 ( V_99 ) ;
struct V_8 * V_9 ;
struct V_134 * V_130 ;
struct V_136 * V_104 = (struct V_136 * ) V_100 ;
struct V_39 * V_40 = F_74 ( V_102 ) -> V_40 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_137 ] ;
int V_32 = 0 ;
V_9 = F_32 ( V_12 , V_13 , V_104 -> V_132 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_45 ;
if ( V_9 -> V_30 != & F_89 ) {
V_32 = - V_45 ;
goto V_126;
}
V_130 = F_1 ( V_9 , struct V_134 , V_130 . V_9 ) ;
if ( V_130 -> V_4 . V_40 != V_40 ) {
V_32 = - V_45 ;
goto V_126;
}
F_72 ( V_40 , V_130 -> V_4 . V_89 . V_90 , V_125 ) ;
V_126:
F_21 ( & V_9 ) ;
return V_32 ;
}
int F_95 ( struct V_98 * V_99 , void * V_100 ,
struct V_101 * V_102 )
{
struct V_11 * V_12 = F_76 ( V_99 ) ;
struct V_134 * V_130 ;
struct V_8 * V_9 ;
struct V_8 * V_82 ;
struct V_136 * V_104 = (struct V_136 * ) V_100 ;
struct V_39 * V_40 = F_74 ( V_102 ) -> V_40 ;
int V_32 ;
if ( F_36 ( V_135 == 0 ) )
V_135 = F_46 ( sizeof( * V_130 ) ) + 128 ;
V_32 = F_77 ( & V_12 -> V_118 , true ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_32 = F_96 ( F_92 ( V_12 ) ,
V_135 ,
false , true ) ;
if ( F_36 ( V_32 != 0 ) ) {
if ( V_32 != - V_110 )
F_60 ( L_10
L_11 ) ;
goto V_138;
}
V_130 = F_97 ( sizeof( * V_130 ) , V_33 ) ;
if ( F_36 ( V_130 == NULL ) ) {
F_91 ( F_92 ( V_12 ) ,
V_135 ) ;
V_32 = - V_83 ;
goto V_138;
}
V_9 = & V_130 -> V_130 . V_9 ;
V_130 -> V_4 . V_80 = false ;
V_130 -> V_4 . V_40 = NULL ;
V_32 = F_87 ( V_12 , & V_130 -> V_130 , F_89 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_138;
V_82 = F_2 ( V_9 ) ;
V_32 = F_98 ( V_40 , & V_130 -> V_4 , false , V_139 ,
& F_93 , NULL ) ;
if ( F_36 ( V_32 != 0 ) ) {
F_21 ( & V_82 ) ;
goto V_140;
}
V_104 -> V_132 = V_9 -> V_18 ;
V_140:
F_21 ( & V_9 ) ;
V_138:
F_79 ( & V_12 -> V_118 ) ;
return V_32 ;
}
int F_99 ( struct V_11 * V_12 ,
struct V_39 * V_40 ,
T_1 * V_141 , struct V_8 * * V_126 )
{
struct V_134 * V_130 ;
struct V_8 * V_9 ;
int V_32 ;
V_9 = F_32 ( V_12 , & V_12 -> V_14 [ V_137 ] ,
* V_141 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_45 ;
if ( V_9 -> V_30 != & F_89 ) {
V_32 = - V_45 ;
goto V_142;
}
V_130 = F_1 ( V_9 , struct V_134 , V_130 . V_9 ) ;
if ( V_130 -> V_4 . V_40 != V_40 ) {
V_32 = - V_92 ;
goto V_142;
}
* V_141 = V_130 -> V_130 . V_132 ;
* V_126 = V_9 ;
return 0 ;
V_142:
F_21 ( & V_9 ) ;
return V_32 ;
}
int F_100 ( struct V_101 * V_102 ,
struct V_98 * V_99 ,
struct V_143 * args )
{
struct V_11 * V_12 = F_76 ( V_99 ) ;
struct V_1 * V_105 ;
int V_32 ;
args -> V_144 = args -> V_145 * ( ( args -> V_146 + 7 ) / 8 ) ;
args -> V_53 = args -> V_144 * args -> V_147 ;
V_32 = F_77 ( & V_12 -> V_118 , true ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
V_32 = F_58 ( V_12 , F_74 ( V_102 ) -> V_40 ,
args -> V_53 , false , & args -> V_41 ,
& V_105 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_119;
F_15 ( & V_105 ) ;
V_119:
F_79 ( & V_12 -> V_118 ) ;
return V_32 ;
}
int F_101 ( struct V_101 * V_102 ,
struct V_98 * V_99 , T_1 V_41 ,
T_3 * V_148 )
{
struct V_39 * V_40 = F_74 ( V_102 ) -> V_40 ;
struct V_1 * V_51 ;
int V_32 ;
V_32 = F_43 ( V_40 , V_41 , & V_51 ) ;
if ( V_32 != 0 )
return - V_45 ;
* V_148 = F_78 ( & V_51 -> V_4 . V_121 ) ;
F_15 ( & V_51 ) ;
return 0 ;
}
int F_102 ( struct V_101 * V_102 ,
struct V_98 * V_99 ,
T_1 V_41 )
{
return F_72 ( F_74 ( V_102 ) -> V_40 ,
V_41 , V_125 ) ;
}
static int F_103 ( struct V_8 * V_9 ,
bool V_69 )
{
unsigned long V_53 =
( V_9 -> V_149 + V_150 - 1 ) & V_151 ;
struct V_1 * V_21 ;
int V_32 ;
if ( F_16 ( V_9 -> V_21 ) ) {
F_24 ( V_9 -> V_21 -> V_4 . V_57 * V_150 < V_53 ) ;
return 0 ;
}
V_21 = F_59 ( sizeof( * V_21 ) , V_33 ) ;
if ( F_36 ( V_21 == NULL ) )
return - V_83 ;
V_32 = F_50 ( V_9 -> V_12 , V_21 , V_9 -> V_149 ,
V_9 -> V_15 -> V_152 ,
V_69 ,
& F_47 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_119;
V_9 -> V_21 = V_21 ;
V_119:
return V_32 ;
}
static int F_104 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_32 = 0 ;
const struct V_36 * V_15 = V_9 -> V_15 ;
if ( F_36 ( V_9 -> V_18 == - 1 ) ) {
V_32 = V_15 -> V_153 ( V_9 ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
}
if ( V_15 -> V_154 &&
( ( V_15 -> V_155 && F_13 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_155 && V_25 -> V_3 != NULL ) ) ) {
V_32 = V_15 -> V_154 ( V_9 , V_25 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_156;
if ( V_15 -> V_155 )
F_105 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_73 ) ;
}
V_9 -> V_38 = true ;
return 0 ;
V_156:
V_15 -> V_91 ( V_9 ) ;
return V_32 ;
}
void F_106 ( struct V_8 * V_9 ,
struct V_1 * V_157 ,
unsigned long V_158 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_13 ( & V_9 -> V_20 ) )
return;
if ( V_157 && V_157 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_107 ( & V_9 -> V_21 -> V_4 . V_159 -> V_160 . V_4 ) ;
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
V_9 -> V_21 = F_108 ( V_157 ) ;
F_107 ( & V_157 -> V_4 . V_159 -> V_160 . V_4 ) ;
F_105 ( & V_9 -> V_22 , & V_157 -> V_73 ) ;
}
if ( V_157 )
V_9 -> V_37 = V_158 ;
if ( ! V_9 -> V_15 -> V_161 || V_9 -> V_18 == - 1 )
return;
F_7 ( & V_12 -> V_17 ) ;
F_105 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_162 [ V_9 -> V_15 -> V_16 ] ) ;
F_9 ( & V_12 -> V_17 ) ;
}
static int
F_109 ( struct V_8 * V_9 ,
bool V_69 ,
struct V_24 * V_25 )
{
struct V_163 V_164 ;
bool V_26 = false ;
int V_32 ;
if ( F_36 ( V_9 -> V_21 == NULL ) ) {
V_32 = F_103 ( V_9 , V_69 ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
}
F_30 ( & V_164 ) ;
V_25 -> V_3 = F_61 ( & V_9 -> V_21 -> V_4 ) ;
F_105 ( & V_25 -> V_165 , & V_164 ) ;
V_32 = F_110 ( NULL , & V_164 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_166;
if ( V_9 -> V_15 -> V_155 && F_13 ( & V_9 -> V_22 ) )
return 0 ;
V_26 = V_9 -> V_26 ;
V_32 = F_111 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_152 ,
true , false ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_167;
return 0 ;
V_167:
F_112 ( NULL , & V_164 ) ;
V_166:
F_54 ( & V_25 -> V_3 ) ;
if ( V_26 )
F_15 ( & V_9 -> V_21 ) ;
return V_32 ;
}
int F_113 ( struct V_8 * V_9 , bool V_168 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_32 ;
F_7 ( & V_12 -> V_17 ) ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_155 && V_9 -> V_21 == NULL &&
! V_168 ) {
V_32 = F_103 ( V_9 , true ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
}
return 0 ;
}
static void
F_114 ( struct V_24 * V_25 )
{
struct V_163 V_164 ;
if ( F_16 ( V_25 -> V_3 == NULL ) )
return;
F_30 ( & V_164 ) ;
F_105 ( & V_25 -> V_165 , & V_164 ) ;
F_112 ( NULL , & V_164 ) ;
F_54 ( & V_25 -> V_3 ) ;
}
int F_115 ( struct V_8 * V_9 , bool V_69 )
{
struct V_24 V_25 ;
const struct V_36 * V_15 = V_9 -> V_15 ;
int V_32 ;
F_24 ( ! V_15 -> V_161 ) ;
V_25 . V_3 = NULL ;
V_32 = F_109 ( V_9 , V_69 , & V_25 ) ;
if ( F_36 ( V_32 != 0 ) )
return V_32 ;
if ( F_36 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_155 || ! F_13 ( & V_9 -> V_22 ) ) ) ) {
V_32 = V_15 -> V_23 ( V_9 , V_9 -> V_38 , & V_25 ) ;
if ( F_36 ( V_32 != 0 ) )
goto V_169;
F_11 ( & V_9 -> V_22 ) ;
}
V_32 = V_15 -> V_91 ( V_9 ) ;
V_9 -> V_26 = true ;
V_9 -> V_38 = false ;
V_169:
F_114 ( & V_25 ) ;
return V_32 ;
}
int F_116 ( struct V_8 * V_9 )
{
int V_32 ;
struct V_8 * V_170 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_163 * V_171 = & V_12 -> V_162 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
unsigned V_172 = 0 ;
if ( F_16 ( ! V_9 -> V_15 -> V_161 ) )
return 0 ;
V_25 . V_3 = NULL ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_32 = F_104 ( V_9 , & V_25 ) ;
if ( F_16 ( V_32 != - V_111 ) )
break;
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_171 ) || ! V_9 -> V_15 -> V_161 ) {
F_60 ( L_12
L_13 , V_9 -> V_15 -> V_173 ) ;
V_32 = - V_111 ;
F_9 ( & V_12 -> V_17 ) ;
break;
}
V_170 = F_2
( F_117 ( V_171 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_170 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_32 = F_115 ( V_170 , true ) ;
if ( F_36 ( V_32 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_105 ( & V_170 -> V_20 , V_171 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_32 == - V_110 ||
++ V_172 > V_174 ) {
F_21 ( & V_170 ) ;
goto V_167;
}
}
F_21 ( & V_170 ) ;
} while ( 1 );
if ( F_36 ( V_32 != 0 ) )
goto V_167;
else if ( ! V_9 -> V_15 -> V_155 && V_9 -> V_21 ) {
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_167:
return V_32 ;
}
void F_118 ( struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_70 * V_71 = V_3 -> V_71 ;
struct V_177 * V_178 = V_71 -> V_178 ;
struct V_175 * V_179 ;
struct V_11 * V_12 =
F_1 ( V_71 , struct V_11 , V_71 ) ;
if ( V_176 == NULL )
F_119 ( NULL , V_12 , & V_176 , NULL ) ;
else
V_178 -> V_180 ( V_176 ) ;
F_66 ( & V_71 -> V_96 ) ;
V_179 = V_3 -> V_181 ;
V_3 -> V_181 = V_176 ;
F_68 ( & V_71 -> V_96 ) ;
if ( V_179 )
F_120 ( & V_179 ) ;
}
void F_121 ( struct V_2 * V_3 ,
struct V_182 * V_183 )
{
struct V_1 * V_105 ;
if ( V_183 == NULL )
return;
if ( V_3 -> V_91 != F_47 &&
V_3 -> V_91 != F_48 )
return;
V_105 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_183 -> V_184 != V_185 ) {
struct V_8 * V_9 , * V_186 ;
struct V_70 * V_71 = V_3 -> V_71 ;
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
F_122 (res, n, &dma_buf->res_list, mob_head) {
if ( F_36 ( V_9 -> V_15 -> V_23 == NULL ) )
continue;
( void ) V_9 -> V_15 -> V_23 ( V_9 , true , & V_25 ) ;
V_9 -> V_26 = true ;
V_9 -> V_38 = false ;
F_11 ( & V_9 -> V_22 ) ;
}
F_66 ( & V_71 -> V_96 ) ;
( void ) F_67 ( V_3 , false , false , false ) ;
F_68 ( & V_71 -> V_96 ) ;
}
}
bool F_123 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_155 ;
}
static void F_124 ( struct V_11 * V_12 ,
enum V_187 type )
{
struct V_163 * V_171 = & V_12 -> V_162 [ type ] ;
struct V_8 * V_170 ;
unsigned V_172 = 0 ;
int V_32 ;
do {
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_171 ) )
goto V_138;
V_170 = F_2 (
F_117 ( V_171 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_170 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_32 = F_115 ( V_170 , false ) ;
if ( F_36 ( V_32 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_105 ( & V_170 -> V_20 , V_171 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( ++ V_172 > V_174 ) {
F_21 ( & V_170 ) ;
return;
}
}
F_21 ( & V_170 ) ;
} while ( 1 );
V_138:
F_9 ( & V_12 -> V_17 ) ;
}
void F_125 ( struct V_11 * V_12 )
{
enum V_187 type ;
F_17 ( & V_12 -> V_188 ) ;
for ( type = 0 ; type < V_189 ; ++ type )
F_124 ( V_12 , type ) ;
F_19 ( & V_12 -> V_188 ) ;
}
