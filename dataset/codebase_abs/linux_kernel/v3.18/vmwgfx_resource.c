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
V_25 . V_26 = false ;
V_9 -> V_15 -> V_23 ( V_9 , false , & V_25 ) ;
}
V_9 -> V_27 = false ;
F_11 ( & V_9 -> V_22 ) ;
F_14 ( V_3 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
if ( F_16 ( V_9 -> V_28 != NULL ) ) {
V_9 -> V_28 ( V_9 ) ;
F_17 ( & V_12 -> V_29 ) ;
F_18 ( & V_9 -> V_30 ) ;
F_19 ( & V_12 -> V_29 ) ;
}
V_18 = V_9 -> V_18 ;
if ( V_9 -> V_31 != NULL )
V_9 -> V_31 ( V_9 ) ;
else
F_20 ( V_9 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_18 != - 1 )
F_8 ( V_13 , V_18 ) ;
}
void F_21 ( struct V_8 * * V_32 )
{
struct V_8 * V_9 = * V_32 ;
struct V_11 * V_12 = V_9 -> V_12 ;
* V_32 = NULL ;
F_7 ( & V_12 -> V_17 ) ;
F_22 ( & V_9 -> V_10 , F_10 ) ;
F_9 ( & V_12 -> V_17 ) ;
}
int F_23 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
F_24 ( V_9 -> V_18 != - 1 ) ;
F_25 ( V_34 ) ;
F_7 ( & V_12 -> V_17 ) ;
V_33 = F_26 ( V_13 , V_9 , 1 , 0 , V_35 ) ;
if ( V_33 >= 0 )
V_9 -> V_18 = V_33 ;
F_9 ( & V_12 -> V_17 ) ;
F_27 () ;
return V_33 < 0 ? V_33 : 0 ;
}
int F_28 ( struct V_11 * V_12 , struct V_8 * V_9 ,
bool V_36 ,
void (* V_31) ( struct V_8 * V_9 ) ,
const struct V_37 * V_15 )
{
F_29 ( & V_9 -> V_10 ) ;
V_9 -> V_28 = NULL ;
V_9 -> V_31 = V_31 ;
V_9 -> V_19 = false ;
V_9 -> V_12 = V_12 ;
V_9 -> V_15 = V_15 ;
F_30 ( & V_9 -> V_20 ) ;
F_30 ( & V_9 -> V_22 ) ;
F_30 ( & V_9 -> V_30 ) ;
V_9 -> V_18 = - 1 ;
V_9 -> V_21 = NULL ;
V_9 -> V_38 = 0 ;
V_9 -> V_27 = false ;
V_9 -> V_39 = false ;
if ( V_36 )
return 0 ;
else
return F_23 ( V_9 ) ;
}
void F_31 ( struct V_8 * V_9 ,
void (* V_28) ( struct V_8 * ) )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_7 ( & V_12 -> V_17 ) ;
V_9 -> V_19 = true ;
V_9 -> V_28 = V_28 ;
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
struct V_40 * V_41 ,
T_1 V_42 ,
const struct V_43
* V_44 ,
struct V_8 * * V_32 )
{
struct V_45 * V_4 ;
struct V_8 * V_9 ;
int V_33 = - V_46 ;
V_4 = F_38 ( V_41 , V_42 ) ;
if ( F_36 ( V_4 == NULL ) )
return - V_46 ;
if ( F_36 ( F_39 ( V_4 ) != V_44 -> V_47 ) )
goto V_48;
V_9 = V_44 -> V_49 ( V_4 ) ;
F_33 ( & V_12 -> V_17 ) ;
if ( ! V_9 -> V_19 || V_9 -> V_31 != V_44 -> V_31 ) {
F_35 ( & V_12 -> V_17 ) ;
goto V_48;
}
F_3 ( & V_9 -> V_10 ) ;
F_35 ( & V_12 -> V_17 ) ;
* V_32 = V_9 ;
V_33 = 0 ;
V_48:
F_40 ( & V_4 ) ;
return V_33 ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 V_42 ,
struct V_50 * * V_51 ,
struct V_1 * * V_52 )
{
struct V_8 * V_9 ;
int V_33 ;
F_24 ( * V_51 || * V_52 ) ;
V_33 = F_37 ( V_12 , V_41 , V_42 ,
V_53 ,
& V_9 ) ;
if ( ! V_33 ) {
* V_51 = F_42 ( V_9 ) ;
return 0 ;
}
* V_51 = NULL ;
V_33 = F_43 ( V_41 , V_42 , V_52 ) ;
return V_33 ;
}
static T_2 F_44 ( struct V_11 * V_12 , T_2 V_54 ,
bool V_55 )
{
static T_2 V_56 , V_57 ;
T_2 V_58 = F_45 ( V_54 ) >> V_59 ;
T_2 V_60 = F_46 ( V_58 * sizeof( void * ) ) ;
if ( F_36 ( V_56 == 0 ) ) {
T_2 V_61 = F_46 ( V_62 ) ;
V_56 = V_61 +
F_46 ( sizeof( struct V_1 ) ) ;
V_57 = V_61 +
F_46 ( sizeof( struct V_5 ) ) ;
}
if ( V_12 -> V_63 == V_64 )
V_60 +=
F_46 ( V_58 * sizeof( V_65 ) ) ;
return ( ( V_55 ) ? V_57 : V_56 ) +
V_60 ;
}
void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_20 ( V_6 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_5 * V_66 = V_5 ( V_3 ) ;
F_49 ( V_66 , V_67 ) ;
}
int F_50 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_54 , struct V_68 * V_69 ,
bool V_70 ,
void (* F_51) ( struct V_2 * V_3 ) )
{
struct V_71 * V_72 = & V_12 -> V_72 ;
T_2 V_73 ;
int V_33 ;
bool V_55 = ( F_51 == & F_48 ) ;
F_24 ( ! F_51 && ( ! V_55 && ( F_51 != F_47 ) ) ) ;
V_73 = F_44 ( V_12 , V_54 , V_55 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_30 ( & V_6 -> V_74 ) ;
V_33 = F_52 ( V_72 , & V_6 -> V_4 , V_54 ,
V_75 , V_69 ,
0 , V_70 ,
NULL , V_73 , NULL , NULL , F_51 ) ;
return V_33 ;
}
static void F_53 ( struct V_45 * * V_76 )
{
struct V_5 * V_66 ;
struct V_45 * V_4 = * V_76 ;
struct V_2 * V_3 ;
* V_76 = NULL ;
if ( F_36 ( V_4 == NULL ) )
return;
V_66 = F_1 ( V_4 , struct V_5 ,
V_67 . V_4 ) ;
V_3 = & V_66 -> V_7 . V_4 ;
F_54 ( & V_3 ) ;
}
static void F_55 ( struct V_45 * V_4 ,
enum V_77 V_78 )
{
struct V_5 * V_79 ;
V_79 = F_1 ( V_4 , struct V_5 , V_67 . V_4 ) ;
switch ( V_78 ) {
case V_80 :
F_56 ( & V_79 -> V_7 . V_4 ) ;
break;
default:
F_57 () ;
}
}
int F_58 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 V_54 ,
bool V_81 ,
T_1 * V_42 ,
struct V_1 * * V_82 )
{
struct V_5 * V_79 ;
struct V_2 * V_83 ;
int V_33 ;
V_79 = F_59 ( sizeof( * V_79 ) , V_34 ) ;
if ( F_36 ( V_79 == NULL ) ) {
F_60 ( L_1 ) ;
return - V_84 ;
}
V_33 = F_50 ( V_12 , & V_79 -> V_7 , V_54 ,
( V_12 -> V_85 ) ?
& V_86 :
& V_87 , true ,
& F_48 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_83 = F_61 ( & V_79 -> V_7 . V_4 ) ;
V_33 = F_62 ( V_41 ,
V_54 ,
& V_79 -> V_67 ,
V_81 ,
V_88 ,
& F_53 ,
& F_55 ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_54 ( & V_83 ) ;
goto V_89;
}
* V_82 = & V_79 -> V_7 ;
* V_42 = V_79 -> V_67 . V_4 . V_90 . V_91 ;
V_89:
return V_33 ;
}
int F_63 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_5 * V_66 ;
if ( F_36 ( V_3 -> V_92 != F_48 ) )
return - V_93 ;
V_66 = V_5 ( V_3 ) ;
if ( F_16 ( F_64 ( V_41 , & V_66 -> V_67 . V_4 ) ) )
return 0 ;
F_60 ( L_2 ) ;
return - V_93 ;
}
static int F_65 ( struct V_5 * V_79 ,
struct V_40 * V_41 ,
T_1 V_94 )
{
struct V_2 * V_3 = & V_79 -> V_7 . V_4 ;
bool V_95 ;
int V_33 ;
if ( V_94 & V_96 ) {
bool V_97 = ! ! ( V_94 & V_98 ) ;
long V_99 ;
if ( V_97 )
return F_66 ( V_3 -> V_100 , true ) ? 0 : - V_101 ;
V_99 = F_67 ( V_3 -> V_100 , true , true , V_102 ) ;
if ( ! V_99 )
return - V_101 ;
else if ( V_99 < 0 )
return V_99 ;
return 0 ;
}
V_33 = F_68
( V_3 , ! ! ( V_94 & V_98 ) ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_69 ( V_41 , & V_79 -> V_67 . V_4 ,
V_80 , & V_95 ) ;
if ( V_33 != 0 || V_95 )
F_56 ( & V_79 -> V_7 . V_4 ) ;
return V_33 ;
}
static int F_70 ( T_1 V_42 ,
struct V_40 * V_41 ,
T_1 V_94 )
{
if ( ! ( V_94 & V_96 ) )
return F_71 ( V_41 , V_42 ,
V_80 ) ;
return 0 ;
}
int F_72 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 =
(struct V_108 * ) V_105 ;
struct V_1 * V_110 ;
struct V_5 * V_79 ;
struct V_40 * V_41 = F_73 ( V_107 ) -> V_41 ;
int V_33 ;
if ( ( V_109 -> V_94 & ( V_111 | V_112 ) ) == 0
|| ( V_109 -> V_94 & ~ ( V_111 | V_112 |
V_98 |
V_96 ) ) != 0 ) {
F_60 ( L_3 ) ;
return - V_46 ;
}
switch ( V_109 -> V_113 ) {
case V_114 :
V_33 = F_43 ( V_41 , V_109 -> V_42 , & V_110 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_79 = F_1 ( V_110 , struct V_5 ,
V_7 ) ;
V_33 = F_65 ( V_79 , V_41 , V_109 -> V_94 ) ;
F_15 ( & V_110 ) ;
if ( F_36 ( V_33 != 0 && V_33 != - V_115 &&
V_33 != - V_101 ) ) {
F_60 ( L_4 ,
( unsigned int ) V_109 -> V_42 ) ;
return V_33 ;
}
break;
case V_116 :
V_33 = F_70 ( V_109 -> V_42 , V_41 ,
V_109 -> V_94 ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_60 ( L_5 ,
( unsigned int ) V_109 -> V_42 ) ;
return V_33 ;
}
break;
default:
F_60 ( L_6 ) ;
return - V_46 ;
}
return 0 ;
}
int F_74 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_11 * V_12 = F_75 ( V_104 ) ;
union V_117 * V_109 =
(union V_117 * ) V_105 ;
struct V_118 * V_119 = & V_109 -> V_119 ;
struct V_120 * V_121 = & V_109 -> V_121 ;
struct V_1 * V_110 ;
T_1 V_42 ;
int V_33 ;
V_33 = F_76 ( & V_12 -> V_122 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_58 ( V_12 , F_73 ( V_107 ) -> V_41 ,
V_119 -> V_54 , false , & V_42 , & V_110 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_123;
V_121 -> V_42 = V_42 ;
V_121 -> V_124 = F_77 ( & V_110 -> V_4 . V_125 ) ;
V_121 -> V_126 = V_42 ;
V_121 -> V_127 = 0 ;
F_15 ( & V_110 ) ;
V_123:
F_78 ( & V_12 -> V_122 ) ;
return V_33 ;
}
int F_79 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_128 * V_109 =
(struct V_128 * ) V_105 ;
return F_71 ( F_73 ( V_107 ) -> V_41 ,
V_109 -> V_42 ,
V_129 ) ;
}
int F_43 ( struct V_40 * V_41 ,
T_1 V_42 , struct V_1 * * V_130 )
{
struct V_5 * V_66 ;
struct V_45 * V_4 ;
V_4 = F_38 ( V_41 , V_42 ) ;
if ( F_36 ( V_4 == NULL ) ) {
F_80 ( V_131 L_7 ,
( unsigned long ) V_42 ) ;
return - V_132 ;
}
if ( F_36 ( F_39 ( V_4 ) != V_88 ) ) {
F_40 ( & V_4 ) ;
F_80 ( V_131 L_7 ,
( unsigned long ) V_42 ) ;
return - V_46 ;
}
V_66 = F_1 ( V_4 , struct V_5 ,
V_67 . V_4 ) ;
( void ) F_61 ( & V_66 -> V_7 . V_4 ) ;
F_40 ( & V_4 ) ;
* V_130 = & V_66 -> V_7 ;
return 0 ;
}
int F_81 ( struct V_40 * V_41 ,
struct V_1 * V_110 ,
T_1 * V_42 )
{
struct V_5 * V_79 ;
if ( V_110 -> V_4 . V_92 != F_48 )
return - V_46 ;
V_79 = F_1 ( V_110 , struct V_5 , V_7 ) ;
* V_42 = V_79 -> V_67 . V_4 . V_90 . V_91 ;
return F_69 ( V_41 , & V_79 -> V_67 . V_4 ,
V_129 , NULL ) ;
}
static void F_82 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_133 * V_134 ;
int V_33 ;
F_83 ( L_8 , V_135 ) ;
V_134 = F_1 ( V_9 , struct V_133 , V_9 ) ;
V_33 = F_84 ( V_12 , V_134 -> V_136 ) ;
F_85 ( V_33 != 0 ) ;
}
static int F_86 ( struct V_11 * V_12 ,
struct V_133 * V_134 ,
void (* V_31) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_134 -> V_9 ;
int V_33 ;
V_33 = F_28 ( V_12 , V_9 , false , V_31 ,
& V_137 ) ;
if ( F_36 ( V_33 != 0 ) ) {
if ( V_31 == NULL )
F_20 ( V_134 ) ;
else
V_31 ( & V_134 -> V_9 ) ;
return V_33 ;
}
V_33 = F_87 ( V_12 , & V_134 -> V_136 ) ;
if ( V_33 ) {
F_21 ( & V_9 ) ;
return V_33 ;
}
F_83 ( L_9 , V_135 ) ;
F_31 ( & V_134 -> V_9 , F_82 ) ;
return 0 ;
}
static void F_88 ( struct V_8 * V_9 )
{
struct V_138 * V_134 =
F_1 ( V_9 , struct V_138 , V_134 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_89 ( V_134 , V_4 ) ;
F_90 ( F_91 ( V_12 ) ,
V_139 ) ;
}
static void F_92 ( struct V_45 * * V_76 )
{
struct V_45 * V_4 = * V_76 ;
struct V_138 * V_134 =
F_1 ( V_4 , struct V_138 , V_4 ) ;
struct V_8 * V_9 = & V_134 -> V_134 . V_9 ;
* V_76 = NULL ;
F_21 ( & V_9 ) ;
}
int F_93 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_11 * V_12 = F_75 ( V_104 ) ;
struct V_8 * V_9 ;
struct V_138 * V_134 ;
struct V_140 * V_109 = (struct V_140 * ) V_105 ;
struct V_40 * V_41 = F_73 ( V_107 ) -> V_41 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_141 ] ;
int V_33 = 0 ;
V_9 = F_32 ( V_12 , V_13 , V_109 -> V_136 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_46 ;
if ( V_9 -> V_31 != & F_88 ) {
V_33 = - V_46 ;
goto V_130;
}
V_134 = F_1 ( V_9 , struct V_138 , V_134 . V_9 ) ;
if ( V_134 -> V_4 . V_41 != V_41 ) {
V_33 = - V_46 ;
goto V_130;
}
F_71 ( V_41 , V_134 -> V_4 . V_90 . V_91 , V_129 ) ;
V_130:
F_21 ( & V_9 ) ;
return V_33 ;
}
int F_94 ( struct V_103 * V_104 , void * V_105 ,
struct V_106 * V_107 )
{
struct V_11 * V_12 = F_75 ( V_104 ) ;
struct V_138 * V_134 ;
struct V_8 * V_9 ;
struct V_8 * V_83 ;
struct V_140 * V_109 = (struct V_140 * ) V_105 ;
struct V_40 * V_41 = F_73 ( V_107 ) -> V_41 ;
int V_33 ;
if ( F_36 ( V_139 == 0 ) )
V_139 = F_46 ( sizeof( * V_134 ) ) + 128 ;
V_33 = F_76 ( & V_12 -> V_122 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_95 ( F_91 ( V_12 ) ,
V_139 ,
false , true ) ;
if ( F_36 ( V_33 != 0 ) ) {
if ( V_33 != - V_115 )
F_60 ( L_10
L_11 ) ;
goto V_142;
}
V_134 = F_96 ( sizeof( * V_134 ) , V_34 ) ;
if ( F_36 ( V_134 == NULL ) ) {
F_90 ( F_91 ( V_12 ) ,
V_139 ) ;
V_33 = - V_84 ;
goto V_142;
}
V_9 = & V_134 -> V_134 . V_9 ;
V_134 -> V_4 . V_81 = false ;
V_134 -> V_4 . V_41 = NULL ;
V_33 = F_86 ( V_12 , & V_134 -> V_134 , F_88 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_142;
V_83 = F_2 ( V_9 ) ;
V_33 = F_97 ( V_41 , & V_134 -> V_4 , false , V_143 ,
& F_92 , NULL ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_21 ( & V_83 ) ;
goto V_144;
}
V_109 -> V_136 = V_9 -> V_18 ;
V_144:
F_21 ( & V_9 ) ;
V_142:
F_78 ( & V_12 -> V_122 ) ;
return V_33 ;
}
int F_98 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 * V_145 , struct V_8 * * V_130 )
{
struct V_138 * V_134 ;
struct V_8 * V_9 ;
int V_33 ;
V_9 = F_32 ( V_12 , & V_12 -> V_14 [ V_141 ] ,
* V_145 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_46 ;
if ( V_9 -> V_31 != & F_88 ) {
V_33 = - V_46 ;
goto V_146;
}
V_134 = F_1 ( V_9 , struct V_138 , V_134 . V_9 ) ;
if ( V_134 -> V_4 . V_41 != V_41 ) {
V_33 = - V_93 ;
goto V_146;
}
* V_145 = V_134 -> V_134 . V_136 ;
* V_130 = V_9 ;
return 0 ;
V_146:
F_21 ( & V_9 ) ;
return V_33 ;
}
int F_99 ( struct V_106 * V_107 ,
struct V_103 * V_104 ,
struct V_147 * args )
{
struct V_11 * V_12 = F_75 ( V_104 ) ;
struct V_1 * V_110 ;
int V_33 ;
args -> V_148 = args -> V_149 * ( ( args -> V_150 + 7 ) / 8 ) ;
args -> V_54 = args -> V_148 * args -> V_151 ;
V_33 = F_76 ( & V_12 -> V_122 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_58 ( V_12 , F_73 ( V_107 ) -> V_41 ,
args -> V_54 , false , & args -> V_42 ,
& V_110 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_123;
F_15 ( & V_110 ) ;
V_123:
F_78 ( & V_12 -> V_122 ) ;
return V_33 ;
}
int F_100 ( struct V_106 * V_107 ,
struct V_103 * V_104 , T_1 V_42 ,
T_3 * V_152 )
{
struct V_40 * V_41 = F_73 ( V_107 ) -> V_41 ;
struct V_1 * V_52 ;
int V_33 ;
V_33 = F_43 ( V_41 , V_42 , & V_52 ) ;
if ( V_33 != 0 )
return - V_46 ;
* V_152 = F_77 ( & V_52 -> V_4 . V_125 ) ;
F_15 ( & V_52 ) ;
return 0 ;
}
int F_101 ( struct V_106 * V_107 ,
struct V_103 * V_104 ,
T_1 V_42 )
{
return F_71 ( F_73 ( V_107 ) -> V_41 ,
V_42 , V_129 ) ;
}
static int F_102 ( struct V_8 * V_9 ,
bool V_70 )
{
unsigned long V_54 =
( V_9 -> V_153 + V_154 - 1 ) & V_155 ;
struct V_1 * V_21 ;
int V_33 ;
if ( F_16 ( V_9 -> V_21 ) ) {
F_24 ( V_9 -> V_21 -> V_4 . V_58 * V_154 < V_54 ) ;
return 0 ;
}
V_21 = F_59 ( sizeof( * V_21 ) , V_34 ) ;
if ( F_36 ( V_21 == NULL ) )
return - V_84 ;
V_33 = F_50 ( V_9 -> V_12 , V_21 , V_9 -> V_153 ,
V_9 -> V_15 -> V_156 ,
V_70 ,
& F_47 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_123;
V_9 -> V_21 = V_21 ;
V_123:
return V_33 ;
}
static int F_103 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_33 = 0 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
if ( F_36 ( V_9 -> V_18 == - 1 ) ) {
V_33 = V_15 -> V_157 ( V_9 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
}
if ( V_15 -> V_158 &&
( ( V_15 -> V_159 && F_13 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_159 && V_25 -> V_3 != NULL ) ) ) {
V_33 = V_15 -> V_158 ( V_9 , V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_160;
if ( V_15 -> V_159 )
F_104 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_74 ) ;
}
V_9 -> V_39 = true ;
return 0 ;
V_160:
V_15 -> V_92 ( V_9 ) ;
return V_33 ;
}
void F_105 ( struct V_8 * V_9 ,
struct V_1 * V_161 ,
unsigned long V_162 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_13 ( & V_9 -> V_20 ) )
return;
if ( V_161 && V_161 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_106 ( & V_9 -> V_21 -> V_4 . V_100 -> V_163 . V_4 ) ;
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
V_9 -> V_21 = F_107 ( V_161 ) ;
F_106 ( & V_161 -> V_4 . V_100 -> V_163 . V_4 ) ;
F_104 ( & V_9 -> V_22 , & V_161 -> V_74 ) ;
}
if ( V_161 )
V_9 -> V_38 = V_162 ;
if ( ! V_9 -> V_15 -> V_164 || V_9 -> V_18 == - 1 )
return;
F_7 ( & V_12 -> V_17 ) ;
F_104 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_165 [ V_9 -> V_15 -> V_16 ] ) ;
F_9 ( & V_12 -> V_17 ) ;
}
static int
F_108 ( struct V_8 * V_9 ,
bool V_70 ,
struct V_24 * V_25 )
{
struct V_166 V_167 ;
bool V_27 = false ;
int V_33 ;
if ( F_36 ( V_9 -> V_21 == NULL ) ) {
V_33 = F_102 ( V_9 , V_70 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
}
F_30 ( & V_167 ) ;
V_25 -> V_3 = F_61 ( & V_9 -> V_21 -> V_4 ) ;
V_25 -> V_26 = false ;
F_104 ( & V_25 -> V_168 , & V_167 ) ;
V_33 = F_109 ( NULL , & V_167 , V_70 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_169;
if ( V_9 -> V_15 -> V_159 && F_13 ( & V_9 -> V_22 ) )
return 0 ;
V_27 = V_9 -> V_27 ;
V_33 = F_110 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_156 ,
true , false ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_170;
return 0 ;
V_170:
F_111 ( NULL , & V_167 ) ;
V_169:
F_54 ( & V_25 -> V_3 ) ;
if ( V_27 )
F_15 ( & V_9 -> V_21 ) ;
return V_33 ;
}
int F_112 ( struct V_8 * V_9 , bool V_171 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_7 ( & V_12 -> V_17 ) ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_159 && V_9 -> V_21 == NULL &&
! V_171 ) {
V_33 = F_102 ( V_9 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
}
return 0 ;
}
static void
F_113 ( struct V_24 * V_25 )
{
struct V_166 V_167 ;
if ( F_16 ( V_25 -> V_3 == NULL ) )
return;
F_30 ( & V_167 ) ;
F_104 ( & V_25 -> V_168 , & V_167 ) ;
F_111 ( NULL , & V_167 ) ;
F_54 ( & V_25 -> V_3 ) ;
}
int F_114 ( struct V_8 * V_9 , bool V_70 )
{
struct V_24 V_25 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
int V_33 ;
F_24 ( ! V_15 -> V_164 ) ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
V_33 = F_108 ( V_9 , V_70 , & V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
if ( F_36 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_159 || ! F_13 ( & V_9 -> V_22 ) ) ) ) {
V_33 = V_15 -> V_23 ( V_9 , V_9 -> V_39 , & V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_172;
F_11 ( & V_9 -> V_22 ) ;
}
V_33 = V_15 -> V_92 ( V_9 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
V_172:
F_113 ( & V_25 ) ;
return V_33 ;
}
int F_115 ( struct V_8 * V_9 )
{
int V_33 ;
struct V_8 * V_173 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_166 * V_174 = & V_12 -> V_165 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
unsigned V_175 = 0 ;
if ( F_16 ( ! V_9 -> V_15 -> V_164 ) )
return 0 ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_33 = F_103 ( V_9 , & V_25 ) ;
if ( F_16 ( V_33 != - V_101 ) )
break;
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_174 ) || ! V_9 -> V_15 -> V_164 ) {
F_60 ( L_12
L_13 , V_9 -> V_15 -> V_176 ) ;
V_33 = - V_101 ;
F_9 ( & V_12 -> V_17 ) ;
break;
}
V_173 = F_2
( F_116 ( V_174 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_173 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_114 ( V_173 , true ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_104 ( & V_173 -> V_20 , V_174 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_33 == - V_115 ||
++ V_175 > V_177 ) {
F_21 ( & V_173 ) ;
goto V_170;
}
}
F_21 ( & V_173 ) ;
} while ( 1 );
if ( F_36 ( V_33 != 0 ) )
goto V_170;
else if ( ! V_9 -> V_15 -> V_159 && V_9 -> V_21 ) {
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_170:
return V_33 ;
}
void F_117 ( struct V_2 * V_3 ,
struct V_178 * V_179 )
{
struct V_71 * V_72 = V_3 -> V_72 ;
struct V_11 * V_12 =
F_1 ( V_72 , struct V_11 , V_72 ) ;
if ( V_179 == NULL ) {
F_118 ( NULL , V_12 , & V_179 , NULL ) ;
F_119 ( V_3 -> V_100 , & V_179 -> V_4 ) ;
F_120 ( & V_179 -> V_4 ) ;
} else
F_119 ( V_3 -> V_100 , & V_179 -> V_4 ) ;
}
void F_121 ( struct V_2 * V_3 ,
struct V_180 * V_181 )
{
struct V_1 * V_110 ;
if ( V_181 == NULL )
return;
if ( V_3 -> V_92 != F_47 &&
V_3 -> V_92 != F_48 )
return;
V_110 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_181 -> V_182 != V_183 ) {
struct V_8 * V_9 , * V_184 ;
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
V_25 . V_26 = false ;
F_122 (res, n, &dma_buf->res_list, mob_head) {
if ( F_36 ( V_9 -> V_15 -> V_23 == NULL ) )
continue;
( void ) V_9 -> V_15 -> V_23 ( V_9 , true , & V_25 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
F_11 ( & V_9 -> V_22 ) ;
}
( void ) F_123 ( V_3 , false , false , false ) ;
}
}
bool F_124 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_159 ;
}
static void F_125 ( struct V_11 * V_12 ,
enum V_185 type )
{
struct V_166 * V_174 = & V_12 -> V_165 [ type ] ;
struct V_8 * V_173 ;
unsigned V_175 = 0 ;
int V_33 ;
do {
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_174 ) )
goto V_142;
V_173 = F_2 (
F_116 ( V_174 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_173 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_114 ( V_173 , false ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_104 ( & V_173 -> V_20 , V_174 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( ++ V_175 > V_177 ) {
F_21 ( & V_173 ) ;
return;
}
}
F_21 ( & V_173 ) ;
} while ( 1 );
V_142:
F_9 ( & V_12 -> V_17 ) ;
}
void F_126 ( struct V_11 * V_12 )
{
enum V_185 type ;
F_17 ( & V_12 -> V_186 ) ;
for ( type = 0 ; type < V_187 ; ++ type )
F_125 ( V_12 , type ) ;
F_19 ( & V_12 -> V_186 ) ;
}
