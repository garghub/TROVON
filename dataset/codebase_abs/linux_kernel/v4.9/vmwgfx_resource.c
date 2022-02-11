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
F_7 ( & V_12 -> V_17 ) ;
V_9 -> V_19 = false ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_21 ) {
struct V_2 * V_3 = & V_9 -> V_21 -> V_4 ;
F_12 ( V_3 , false , false , NULL ) ;
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
F_17 ( & V_12 -> V_29 ) ;
F_18 ( & V_9 -> V_30 ) ;
F_19 ( & V_12 -> V_29 ) ;
V_9 -> V_28 ( V_9 ) ;
}
V_18 = V_9 -> V_18 ;
if ( V_9 -> V_31 != NULL )
V_9 -> V_31 ( V_9 ) ;
else
F_20 ( V_9 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_18 != - 1 )
F_8 ( V_13 , V_18 ) ;
F_9 ( & V_12 -> V_17 ) ;
}
void F_21 ( struct V_8 * * V_32 )
{
struct V_8 * V_9 = * V_32 ;
* V_32 = NULL ;
F_22 ( & V_9 -> V_10 , F_10 ) ;
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
static struct V_8 * F_32 ( struct V_11 * V_12 ,
struct V_13 * V_13 , int V_18 )
{
struct V_8 * V_9 ;
F_33 ( & V_12 -> V_17 ) ;
V_9 = F_34 ( V_13 , V_18 ) ;
if ( ! V_9 || ! V_9 -> V_19 || ! F_5 ( & V_9 -> V_10 ) )
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
V_33 = F_43 ( V_41 , V_42 , V_52 , NULL ) ;
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
struct V_1 * * V_82 ,
struct V_45 * * V_76 )
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
if ( V_76 ) {
* V_76 = & V_79 -> V_67 . V_4 ;
F_3 ( & ( * V_76 ) -> V_90 ) ;
}
* V_42 = V_79 -> V_67 . V_4 . V_91 . V_92 ;
V_89:
return V_33 ;
}
int F_63 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_5 * V_66 ;
if ( F_36 ( V_3 -> V_93 != F_48 ) )
return - V_94 ;
V_66 = V_5 ( V_3 ) ;
if ( F_16 ( F_64 ( V_41 , & V_66 -> V_67 . V_4 ) ) )
return 0 ;
F_60 ( L_2 ) ;
return - V_94 ;
}
static int F_65 ( struct V_5 * V_79 ,
struct V_40 * V_41 ,
T_1 V_95 )
{
struct V_2 * V_3 = & V_79 -> V_7 . V_4 ;
bool V_96 ;
int V_33 ;
if ( V_95 & V_97 ) {
bool V_98 = ! ! ( V_95 & V_99 ) ;
long V_100 ;
V_100 = F_66 ( V_3 -> V_101 , true , true ,
V_98 ? 0 : V_102 ) ;
if ( ! V_100 )
return - V_103 ;
else if ( V_100 < 0 )
return V_100 ;
return 0 ;
}
V_33 = F_67
( V_3 , ! ! ( V_95 & V_99 ) ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_68 ( V_41 , & V_79 -> V_67 . V_4 ,
V_80 , & V_96 ) ;
if ( V_33 != 0 || V_96 )
F_56 ( & V_79 -> V_7 . V_4 ) ;
return V_33 ;
}
static int F_69 ( T_1 V_42 ,
struct V_40 * V_41 ,
T_1 V_95 )
{
if ( ! ( V_95 & V_97 ) )
return F_70 ( V_41 , V_42 ,
V_80 ) ;
return 0 ;
}
int F_71 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 =
(struct V_109 * ) V_106 ;
struct V_1 * V_111 ;
struct V_5 * V_79 ;
struct V_40 * V_41 = F_72 ( V_108 ) -> V_41 ;
struct V_45 * V_112 ;
int V_33 ;
if ( ( V_110 -> V_95 & ( V_113 | V_114 ) ) == 0
|| ( V_110 -> V_95 & ~ ( V_113 | V_114 |
V_99 |
V_97 ) ) != 0 ) {
F_60 ( L_3 ) ;
return - V_46 ;
}
switch ( V_110 -> V_115 ) {
case V_116 :
V_33 = F_43 ( V_41 , V_110 -> V_42 , & V_111 ,
& V_112 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_79 = F_1 ( V_111 , struct V_5 ,
V_7 ) ;
V_33 = F_65 ( V_79 , V_41 , V_110 -> V_95 ) ;
F_15 ( & V_111 ) ;
F_40 ( & V_112 ) ;
if ( F_36 ( V_33 != 0 && V_33 != - V_117 &&
V_33 != - V_103 ) ) {
F_60 ( L_4 ,
( unsigned int ) V_110 -> V_42 ) ;
return V_33 ;
}
break;
case V_118 :
V_33 = F_69 ( V_110 -> V_42 , V_41 ,
V_110 -> V_95 ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_60 ( L_5 ,
( unsigned int ) V_110 -> V_42 ) ;
return V_33 ;
}
break;
default:
F_60 ( L_6 ) ;
return - V_46 ;
}
return 0 ;
}
int F_73 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = F_74 ( V_105 ) ;
union V_119 * V_110 =
(union V_119 * ) V_106 ;
struct V_120 * V_121 = & V_110 -> V_121 ;
struct V_122 * V_123 = & V_110 -> V_123 ;
struct V_1 * V_111 ;
T_1 V_42 ;
int V_33 ;
V_33 = F_75 ( & V_12 -> V_124 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_58 ( V_12 , F_72 ( V_108 ) -> V_41 ,
V_121 -> V_54 , false , & V_42 , & V_111 ,
NULL ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_125;
V_123 -> V_42 = V_42 ;
V_123 -> V_126 = F_76 ( & V_111 -> V_4 . V_127 ) ;
V_123 -> V_128 = V_42 ;
V_123 -> V_129 = 0 ;
F_15 ( & V_111 ) ;
V_125:
F_77 ( & V_12 -> V_124 ) ;
return V_33 ;
}
int F_78 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_130 * V_110 =
(struct V_130 * ) V_106 ;
return F_70 ( F_72 ( V_108 ) -> V_41 ,
V_110 -> V_42 ,
V_131 ) ;
}
int F_43 ( struct V_40 * V_41 ,
T_1 V_42 , struct V_1 * * V_132 ,
struct V_45 * * V_76 )
{
struct V_5 * V_66 ;
struct V_45 * V_4 ;
V_4 = F_38 ( V_41 , V_42 ) ;
if ( F_36 ( V_4 == NULL ) ) {
F_79 ( V_133 L_7 ,
( unsigned long ) V_42 ) ;
return - V_134 ;
}
if ( F_36 ( F_39 ( V_4 ) != V_88 ) ) {
F_40 ( & V_4 ) ;
F_79 ( V_133 L_7 ,
( unsigned long ) V_42 ) ;
return - V_46 ;
}
V_66 = F_1 ( V_4 , struct V_5 ,
V_67 . V_4 ) ;
( void ) F_61 ( & V_66 -> V_7 . V_4 ) ;
if ( V_76 )
* V_76 = V_4 ;
else
F_40 ( & V_4 ) ;
* V_132 = & V_66 -> V_7 ;
return 0 ;
}
int F_80 ( struct V_40 * V_41 ,
struct V_1 * V_111 ,
T_1 * V_42 )
{
struct V_5 * V_79 ;
if ( V_111 -> V_4 . V_93 != F_48 )
return - V_46 ;
V_79 = F_1 ( V_111 , struct V_5 , V_7 ) ;
* V_42 = V_79 -> V_67 . V_4 . V_91 . V_92 ;
return F_68 ( V_41 , & V_79 -> V_67 . V_4 ,
V_131 , NULL ) ;
}
static void F_81 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_135 * V_136 ;
int V_33 ;
F_82 ( L_8 , V_137 ) ;
V_136 = F_1 ( V_9 , struct V_135 , V_9 ) ;
V_33 = F_83 ( V_12 , V_136 -> V_138 ) ;
F_84 ( V_33 != 0 ) ;
}
static int F_85 ( struct V_11 * V_12 ,
struct V_135 * V_136 ,
void (* V_31) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_136 -> V_9 ;
int V_33 ;
V_33 = F_28 ( V_12 , V_9 , false , V_31 ,
& V_139 ) ;
if ( F_36 ( V_33 != 0 ) ) {
if ( V_31 == NULL )
F_20 ( V_136 ) ;
else
V_31 ( & V_136 -> V_9 ) ;
return V_33 ;
}
V_33 = F_86 ( V_12 , & V_136 -> V_138 ) ;
if ( V_33 ) {
F_21 ( & V_9 ) ;
return V_33 ;
}
F_82 ( L_9 , V_137 ) ;
F_31 ( & V_136 -> V_9 , F_81 ) ;
return 0 ;
}
static void F_87 ( struct V_8 * V_9 )
{
struct V_140 * V_136 =
F_1 ( V_9 , struct V_140 , V_136 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_88 ( V_136 , V_4 ) ;
F_89 ( F_90 ( V_12 ) ,
V_141 ) ;
}
static void F_91 ( struct V_45 * * V_76 )
{
struct V_45 * V_4 = * V_76 ;
struct V_140 * V_136 =
F_1 ( V_4 , struct V_140 , V_4 ) ;
struct V_8 * V_9 = & V_136 -> V_136 . V_9 ;
* V_76 = NULL ;
F_21 ( & V_9 ) ;
}
int F_92 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = F_74 ( V_105 ) ;
struct V_8 * V_9 ;
struct V_140 * V_136 ;
struct V_142 * V_110 = (struct V_142 * ) V_106 ;
struct V_40 * V_41 = F_72 ( V_108 ) -> V_41 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_143 ] ;
int V_33 = 0 ;
V_9 = F_32 ( V_12 , V_13 , V_110 -> V_138 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_46 ;
if ( V_9 -> V_31 != & F_87 ) {
V_33 = - V_46 ;
goto V_132;
}
V_136 = F_1 ( V_9 , struct V_140 , V_136 . V_9 ) ;
if ( V_136 -> V_4 . V_41 != V_41 ) {
V_33 = - V_46 ;
goto V_132;
}
F_70 ( V_41 , V_136 -> V_4 . V_91 . V_92 , V_131 ) ;
V_132:
F_21 ( & V_9 ) ;
return V_33 ;
}
int F_93 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = F_74 ( V_105 ) ;
struct V_140 * V_136 ;
struct V_8 * V_9 ;
struct V_8 * V_83 ;
struct V_142 * V_110 = (struct V_142 * ) V_106 ;
struct V_40 * V_41 = F_72 ( V_108 ) -> V_41 ;
int V_33 ;
if ( F_36 ( V_141 == 0 ) )
V_141 = F_46 ( sizeof( * V_136 ) ) + 128 ;
V_33 = F_75 ( & V_12 -> V_124 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_94 ( F_90 ( V_12 ) ,
V_141 ,
false , true ) ;
F_77 ( & V_12 -> V_124 ) ;
if ( F_36 ( V_33 != 0 ) ) {
if ( V_33 != - V_117 )
F_60 ( L_10
L_11 ) ;
goto V_144;
}
V_136 = F_95 ( sizeof( * V_136 ) , V_34 ) ;
if ( F_36 ( V_136 == NULL ) ) {
F_89 ( F_90 ( V_12 ) ,
V_141 ) ;
V_33 = - V_84 ;
goto V_144;
}
V_9 = & V_136 -> V_136 . V_9 ;
V_136 -> V_4 . V_81 = false ;
V_136 -> V_4 . V_41 = NULL ;
V_33 = F_85 ( V_12 , & V_136 -> V_136 , F_87 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_144;
V_83 = F_2 ( V_9 ) ;
V_33 = F_96 ( V_41 , & V_136 -> V_4 , false , V_145 ,
& F_91 , NULL ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_21 ( & V_83 ) ;
goto V_146;
}
V_110 -> V_138 = V_9 -> V_18 ;
V_146:
F_21 ( & V_9 ) ;
V_144:
return V_33 ;
}
int F_97 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 * V_147 , struct V_8 * * V_132 )
{
struct V_140 * V_136 ;
struct V_8 * V_9 ;
int V_33 ;
V_9 = F_32 ( V_12 , & V_12 -> V_14 [ V_143 ] ,
* V_147 ) ;
if ( F_36 ( V_9 == NULL ) )
return - V_46 ;
if ( V_9 -> V_31 != & F_87 ) {
V_33 = - V_46 ;
goto V_148;
}
V_136 = F_1 ( V_9 , struct V_140 , V_136 . V_9 ) ;
if ( V_136 -> V_4 . V_41 != V_41 ) {
V_33 = - V_94 ;
goto V_148;
}
* V_147 = V_136 -> V_136 . V_138 ;
* V_132 = V_9 ;
return 0 ;
V_148:
F_21 ( & V_9 ) ;
return V_33 ;
}
int F_98 ( struct V_107 * V_108 ,
struct V_104 * V_105 ,
struct V_149 * args )
{
struct V_11 * V_12 = F_74 ( V_105 ) ;
struct V_1 * V_111 ;
int V_33 ;
args -> V_150 = args -> V_151 * ( ( args -> V_152 + 7 ) / 8 ) ;
args -> V_54 = args -> V_150 * args -> V_153 ;
V_33 = F_75 ( & V_12 -> V_124 , true ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_58 ( V_12 , F_72 ( V_108 ) -> V_41 ,
args -> V_54 , false , & args -> V_42 ,
& V_111 , NULL ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_125;
F_15 ( & V_111 ) ;
V_125:
F_77 ( & V_12 -> V_124 ) ;
return V_33 ;
}
int F_99 ( struct V_107 * V_108 ,
struct V_104 * V_105 , T_1 V_42 ,
T_3 * V_154 )
{
struct V_40 * V_41 = F_72 ( V_108 ) -> V_41 ;
struct V_1 * V_52 ;
int V_33 ;
V_33 = F_43 ( V_41 , V_42 , & V_52 , NULL ) ;
if ( V_33 != 0 )
return - V_46 ;
* V_154 = F_76 ( & V_52 -> V_4 . V_127 ) ;
F_15 ( & V_52 ) ;
return 0 ;
}
int F_100 ( struct V_107 * V_108 ,
struct V_104 * V_105 ,
T_1 V_42 )
{
return F_70 ( F_72 ( V_108 ) -> V_41 ,
V_42 , V_131 ) ;
}
static int F_101 ( struct V_8 * V_9 ,
bool V_70 )
{
unsigned long V_54 =
( V_9 -> V_155 + V_156 - 1 ) & V_157 ;
struct V_1 * V_21 ;
int V_33 ;
if ( F_16 ( V_9 -> V_21 ) ) {
F_24 ( V_9 -> V_21 -> V_4 . V_58 * V_156 < V_54 ) ;
return 0 ;
}
V_21 = F_59 ( sizeof( * V_21 ) , V_34 ) ;
if ( F_36 ( V_21 == NULL ) )
return - V_84 ;
V_33 = F_50 ( V_9 -> V_12 , V_21 , V_9 -> V_155 ,
V_9 -> V_15 -> V_158 ,
V_70 ,
& F_47 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_125;
V_9 -> V_21 = V_21 ;
V_125:
return V_33 ;
}
static int F_102 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_33 = 0 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
if ( F_36 ( V_9 -> V_18 == - 1 ) ) {
V_33 = V_15 -> V_159 ( V_9 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
}
if ( V_15 -> V_160 &&
( ( V_15 -> V_161 && F_13 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_161 && V_25 -> V_3 != NULL ) ) ) {
V_33 = V_15 -> V_160 ( V_9 , V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_162;
if ( V_15 -> V_161 )
F_103 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_74 ) ;
}
V_9 -> V_39 = true ;
return 0 ;
V_162:
V_15 -> V_93 ( V_9 ) ;
return V_33 ;
}
void F_104 ( struct V_8 * V_9 ,
bool V_163 ,
struct V_1 * V_164 ,
unsigned long V_165 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_13 ( & V_9 -> V_20 ) )
return;
if ( V_163 && V_164 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_105 ( & V_9 -> V_21 -> V_4 . V_101 -> V_166 . V_4 ) ;
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
if ( V_164 ) {
V_9 -> V_21 = F_106 ( V_164 ) ;
F_105 ( & V_164 -> V_4 . V_101 -> V_166 . V_4 ) ;
F_103 ( & V_9 -> V_22 , & V_164 -> V_74 ) ;
} else {
V_9 -> V_21 = NULL ;
}
}
if ( V_163 )
V_9 -> V_38 = V_165 ;
if ( ! V_9 -> V_15 -> V_167 || V_9 -> V_18 == - 1 || V_9 -> V_168 )
return;
F_7 ( & V_12 -> V_17 ) ;
F_103 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_169 [ V_9 -> V_15 -> V_16 ] ) ;
F_9 ( & V_12 -> V_17 ) ;
}
static int
F_107 ( struct V_8 * V_9 ,
bool V_70 ,
struct V_24 * V_25 )
{
struct V_170 V_171 ;
bool V_27 = false ;
int V_33 ;
if ( F_36 ( V_9 -> V_21 == NULL ) ) {
V_33 = F_101 ( V_9 , V_70 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
}
F_30 ( & V_171 ) ;
V_25 -> V_3 = F_61 ( & V_9 -> V_21 -> V_4 ) ;
V_25 -> V_26 = false ;
F_103 ( & V_25 -> V_172 , & V_171 ) ;
V_33 = F_108 ( NULL , & V_171 , V_70 , NULL ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_173;
if ( V_9 -> V_15 -> V_161 && F_13 ( & V_9 -> V_22 ) )
return 0 ;
V_27 = V_9 -> V_27 ;
V_33 = F_109 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_158 ,
true , false ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_174;
return 0 ;
V_174:
F_110 ( NULL , & V_171 ) ;
V_173:
F_54 ( & V_25 -> V_3 ) ;
if ( V_27 )
F_15 ( & V_9 -> V_21 ) ;
return V_33 ;
}
int F_111 ( struct V_8 * V_9 , bool V_70 ,
bool V_175 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_7 ( & V_12 -> V_17 ) ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_161 && V_9 -> V_21 == NULL &&
! V_175 ) {
V_33 = F_101 ( V_9 , V_70 ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_60 ( L_12
L_13 ,
( unsigned long ) V_9 -> V_155 ) ;
return V_33 ;
}
}
return 0 ;
}
static void
F_112 ( struct V_24 * V_25 )
{
struct V_170 V_171 ;
if ( F_16 ( V_25 -> V_3 == NULL ) )
return;
F_30 ( & V_171 ) ;
F_103 ( & V_25 -> V_172 , & V_171 ) ;
F_110 ( NULL , & V_171 ) ;
F_54 ( & V_25 -> V_3 ) ;
}
static int F_113 ( struct V_8 * V_9 , bool V_70 )
{
struct V_24 V_25 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
int V_33 ;
F_24 ( ! V_15 -> V_167 ) ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
V_33 = F_107 ( V_9 , V_70 , & V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
return V_33 ;
if ( F_36 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_161 || ! F_13 ( & V_9 -> V_22 ) ) ) ) {
V_33 = V_15 -> V_23 ( V_9 , V_9 -> V_39 , & V_25 ) ;
if ( F_36 ( V_33 != 0 ) )
goto V_176;
F_11 ( & V_9 -> V_22 ) ;
}
V_33 = V_15 -> V_93 ( V_9 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
V_176:
F_112 ( & V_25 ) ;
return V_33 ;
}
int F_114 ( struct V_8 * V_9 )
{
int V_33 ;
struct V_8 * V_177 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_170 * V_178 = & V_12 -> V_169 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
unsigned V_179 = 0 ;
if ( ! V_9 -> V_15 -> V_159 )
return 0 ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_33 = F_102 ( V_9 , & V_25 ) ;
if ( F_16 ( V_33 != - V_103 ) )
break;
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_178 ) || ! V_9 -> V_15 -> V_167 ) {
F_60 ( L_14
L_15 , V_9 -> V_15 -> V_180 ) ;
V_33 = - V_103 ;
F_9 ( & V_12 -> V_17 ) ;
break;
}
V_177 = F_2
( F_115 ( V_178 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_177 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_113 ( V_177 , true ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_103 ( & V_177 -> V_20 , V_178 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_33 == - V_117 ||
++ V_179 > V_181 ) {
F_21 ( & V_177 ) ;
goto V_174;
}
}
F_21 ( & V_177 ) ;
} while ( 1 );
if ( F_36 ( V_33 != 0 ) )
goto V_174;
else if ( ! V_9 -> V_15 -> V_161 && V_9 -> V_21 ) {
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_174:
return V_33 ;
}
void F_116 ( struct V_2 * V_3 ,
struct V_182 * V_183 )
{
struct V_71 * V_72 = V_3 -> V_72 ;
struct V_11 * V_12 =
F_1 ( V_72 , struct V_11 , V_72 ) ;
if ( V_183 == NULL ) {
F_117 ( NULL , V_12 , & V_183 , NULL ) ;
F_118 ( V_3 -> V_101 , & V_183 -> V_4 ) ;
F_119 ( & V_183 -> V_4 ) ;
} else
F_118 ( V_3 -> V_101 , & V_183 -> V_4 ) ;
}
void F_120 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_111 ;
if ( V_185 == NULL )
return;
if ( V_3 -> V_93 != F_47 &&
V_3 -> V_93 != F_48 )
return;
V_111 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_185 -> V_186 != V_187 ) {
struct V_8 * V_9 , * V_188 ;
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
V_25 . V_26 = false ;
F_121 (res, n, &dma_buf->res_list, mob_head) {
if ( F_36 ( V_9 -> V_15 -> V_23 == NULL ) )
continue;
( void ) V_9 -> V_15 -> V_23 ( V_9 , true , & V_25 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
F_11 ( & V_9 -> V_22 ) ;
}
( void ) F_122 ( V_3 , false , false ) ;
}
}
int F_123 ( struct V_1 * V_189 )
{
struct V_8 * V_190 ;
struct V_11 * V_12 ;
struct {
T_4 V_191 ;
T_5 V_192 ;
} * V_193 ;
if ( ! V_189 || ! V_189 -> V_190 )
return 0 ;
V_190 = V_189 -> V_190 ;
V_12 = V_190 -> V_12 ;
V_193 = F_124 ( V_12 , sizeof( * V_193 ) , V_190 -> V_18 ) ;
if ( F_36 ( V_193 == NULL ) ) {
F_60 ( L_16
L_17 ) ;
return - V_84 ;
}
V_193 -> V_191 . V_18 = V_194 ;
V_193 -> V_191 . V_54 = sizeof( V_193 -> V_192 ) ;
V_193 -> V_192 . V_195 = V_190 -> V_18 ;
F_125 ( V_12 , sizeof( * V_193 ) ) ;
V_189 -> V_190 = NULL ;
return 0 ;
}
void F_126 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_189 ;
struct V_71 * V_72 = V_3 -> V_72 ;
struct V_11 * V_12 ;
V_12 = F_1 ( V_72 , struct V_11 , V_72 ) ;
F_17 ( & V_12 -> V_29 ) ;
V_189 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_185 == NULL || ! V_189 || ! V_189 -> V_190 ) {
F_19 ( & V_12 -> V_29 ) ;
return;
}
if ( V_185 -> V_186 == V_196 && V_3 -> V_185 . V_186 == V_187 ) {
struct V_182 * V_183 ;
( void ) F_123 ( V_189 ) ;
F_19 ( & V_12 -> V_29 ) ;
( void ) F_117 ( NULL , V_12 , & V_183 , NULL ) ;
F_116 ( V_3 , V_183 ) ;
if ( V_183 != NULL )
F_127 ( & V_183 ) ;
( void ) F_122 ( V_3 , false , false ) ;
} else
F_19 ( & V_12 -> V_29 ) ;
}
bool F_128 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_161 ;
}
static void F_129 ( struct V_11 * V_12 ,
enum V_197 type )
{
struct V_170 * V_178 = & V_12 -> V_169 [ type ] ;
struct V_8 * V_177 ;
unsigned V_179 = 0 ;
int V_33 ;
do {
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_178 ) )
goto V_198;
V_177 = F_2 (
F_115 ( V_178 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_177 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_113 ( V_177 , false ) ;
if ( F_36 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_103 ( & V_177 -> V_20 , V_178 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( ++ V_179 > V_181 ) {
F_21 ( & V_177 ) ;
return;
}
}
F_21 ( & V_177 ) ;
} while ( 1 );
V_198:
F_9 ( & V_12 -> V_17 ) ;
}
void F_130 ( struct V_11 * V_12 )
{
enum V_197 type ;
F_17 ( & V_12 -> V_199 ) ;
for ( type = 0 ; type < V_200 ; ++ type )
F_129 ( V_12 , type ) ;
F_19 ( & V_12 -> V_199 ) ;
}
int F_131 ( struct V_8 * V_9 , bool V_70 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_132 ( & V_12 -> V_124 , V_70 ) ;
F_17 ( & V_12 -> V_199 ) ;
V_33 = F_111 ( V_9 , V_70 , false ) ;
if ( V_33 )
goto V_173;
if ( V_9 -> V_168 == 0 ) {
struct V_1 * V_201 = NULL ;
if ( V_9 -> V_21 ) {
V_201 = V_9 -> V_21 ;
F_12 ( & V_201 -> V_4 , V_70 , false , NULL ) ;
if ( ! V_201 -> V_168 ) {
V_33 = F_109
( & V_201 -> V_4 ,
V_9 -> V_15 -> V_158 ,
V_70 , false ) ;
if ( V_33 ) {
F_14 ( & V_201 -> V_4 ) ;
goto V_174;
}
}
F_133 ( V_201 , true ) ;
}
V_33 = F_114 ( V_9 ) ;
if ( V_201 )
F_14 ( & V_201 -> V_4 ) ;
if ( V_33 )
goto V_174;
}
V_9 -> V_168 ++ ;
V_174:
F_104 ( V_9 , false , NULL , 0UL ) ;
V_173:
F_19 ( & V_12 -> V_199 ) ;
F_134 ( & V_12 -> V_124 ) ;
return V_33 ;
}
void F_135 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_75 ( & V_12 -> V_124 , false ) ;
F_17 ( & V_12 -> V_199 ) ;
V_33 = F_111 ( V_9 , false , true ) ;
F_84 ( V_33 ) ;
F_84 ( V_9 -> V_168 == 0 ) ;
if ( -- V_9 -> V_168 == 0 && V_9 -> V_21 ) {
struct V_1 * V_201 = V_9 -> V_21 ;
F_12 ( & V_201 -> V_4 , false , false , NULL ) ;
F_133 ( V_201 , false ) ;
F_14 ( & V_201 -> V_4 ) ;
}
F_104 ( V_9 , false , NULL , 0UL ) ;
F_19 ( & V_12 -> V_199 ) ;
F_77 ( & V_12 -> V_124 ) ;
}
enum V_197 V_197 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_16 ;
}
