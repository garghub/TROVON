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
int F_32 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 V_42 ,
const struct V_43
* V_44 ,
struct V_8 * * V_32 )
{
struct V_45 * V_4 ;
struct V_8 * V_9 ;
int V_33 = - V_46 ;
V_4 = F_33 ( V_41 , V_42 ) ;
if ( F_34 ( V_4 == NULL ) )
return - V_46 ;
if ( F_34 ( F_35 ( V_4 ) != V_44 -> V_47 ) )
goto V_48;
V_9 = V_44 -> V_49 ( V_4 ) ;
F_36 ( & V_12 -> V_17 ) ;
if ( ! V_9 -> V_19 || V_9 -> V_31 != V_44 -> V_31 ) {
F_37 ( & V_12 -> V_17 ) ;
goto V_48;
}
F_3 ( & V_9 -> V_10 ) ;
F_37 ( & V_12 -> V_17 ) ;
* V_32 = V_9 ;
V_33 = 0 ;
V_48:
F_38 ( & V_4 ) ;
return V_33 ;
}
int F_39 ( struct V_11 * V_12 ,
struct V_40 * V_41 ,
T_1 V_42 ,
struct V_50 * * V_51 ,
struct V_1 * * V_52 )
{
struct V_8 * V_9 ;
int V_33 ;
F_24 ( * V_51 || * V_52 ) ;
V_33 = F_32 ( V_12 , V_41 , V_42 ,
V_53 ,
& V_9 ) ;
if ( ! V_33 ) {
* V_51 = F_40 ( V_9 ) ;
return 0 ;
}
* V_51 = NULL ;
V_33 = F_41 ( V_41 , V_42 , V_52 , NULL ) ;
return V_33 ;
}
static T_2 F_42 ( struct V_11 * V_12 , T_2 V_54 ,
bool V_55 )
{
static T_2 V_56 , V_57 ;
T_2 V_58 = F_43 ( V_54 ) >> V_59 ;
T_2 V_60 = F_44 ( V_58 * sizeof( void * ) ) ;
if ( F_34 ( V_56 == 0 ) ) {
T_2 V_61 = F_44 ( V_62 ) ;
V_56 = V_61 +
F_44 ( sizeof( struct V_1 ) ) ;
V_57 = V_61 +
F_44 ( sizeof( struct V_5 ) ) ;
}
if ( V_12 -> V_63 == V_64 )
V_60 +=
F_44 ( V_58 * sizeof( V_65 ) ) ;
return ( ( V_55 ) ? V_57 : V_56 ) +
V_60 ;
}
void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_20 ( V_6 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_5 * V_66 = V_5 ( V_3 ) ;
F_47 ( V_66 , V_67 ) ;
}
int F_48 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_54 , struct V_68 * V_69 ,
bool V_70 ,
void (* F_49) ( struct V_2 * V_3 ) )
{
struct V_71 * V_72 = & V_12 -> V_72 ;
T_2 V_73 ;
int V_33 ;
bool V_55 = ( F_49 == & F_46 ) ;
F_24 ( ! F_49 && ( ! V_55 && ( F_49 != F_45 ) ) ) ;
V_73 = F_42 ( V_12 , V_54 , V_55 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_30 ( & V_6 -> V_74 ) ;
V_33 = F_50 ( V_72 , & V_6 -> V_4 , V_54 ,
V_75 , V_69 ,
0 , V_70 ,
NULL , V_73 , NULL , NULL , F_49 ) ;
return V_33 ;
}
static void F_51 ( struct V_45 * * V_76 )
{
struct V_5 * V_66 ;
struct V_45 * V_4 = * V_76 ;
struct V_2 * V_3 ;
* V_76 = NULL ;
if ( F_34 ( V_4 == NULL ) )
return;
V_66 = F_1 ( V_4 , struct V_5 ,
V_67 . V_4 ) ;
V_3 = & V_66 -> V_7 . V_4 ;
F_52 ( & V_3 ) ;
}
static void F_53 ( struct V_45 * V_4 ,
enum V_77 V_78 )
{
struct V_5 * V_79 ;
V_79 = F_1 ( V_4 , struct V_5 , V_67 . V_4 ) ;
switch ( V_78 ) {
case V_80 :
F_54 ( & V_79 -> V_7 . V_4 ) ;
break;
default:
F_55 () ;
}
}
int F_56 ( struct V_11 * V_12 ,
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
V_79 = F_57 ( sizeof( * V_79 ) , V_34 ) ;
if ( F_34 ( ! V_79 ) ) {
F_58 ( L_1 ) ;
return - V_84 ;
}
V_33 = F_48 ( V_12 , & V_79 -> V_7 , V_54 ,
( V_12 -> V_85 ) ?
& V_86 :
& V_87 , true ,
& F_46 ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
V_83 = F_59 ( & V_79 -> V_7 . V_4 ) ;
V_33 = F_60 ( V_41 ,
V_54 ,
& V_79 -> V_67 ,
V_81 ,
V_88 ,
& F_51 ,
& F_53 ) ;
if ( F_34 ( V_33 != 0 ) ) {
F_52 ( & V_83 ) ;
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
int F_61 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_5 * V_66 ;
if ( F_34 ( V_3 -> V_93 != F_46 ) )
return - V_94 ;
V_66 = V_5 ( V_3 ) ;
if ( F_16 ( F_62 ( V_41 , & V_66 -> V_67 . V_4 ) ) )
return 0 ;
F_58 ( L_2 ) ;
return - V_94 ;
}
static int F_63 ( struct V_5 * V_79 ,
struct V_40 * V_41 ,
T_1 V_95 )
{
struct V_2 * V_3 = & V_79 -> V_7 . V_4 ;
bool V_96 ;
int V_33 ;
if ( V_95 & V_97 ) {
bool V_98 = ! ! ( V_95 & V_99 ) ;
long V_100 ;
V_100 = F_64 ( V_3 -> V_101 , true , true ,
V_98 ? 0 : V_102 ) ;
if ( ! V_100 )
return - V_103 ;
else if ( V_100 < 0 )
return V_100 ;
return 0 ;
}
V_33 = F_65
( V_3 , ! ! ( V_95 & V_99 ) ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_66 ( V_41 , & V_79 -> V_67 . V_4 ,
V_80 , & V_96 , false ) ;
if ( V_33 != 0 || V_96 )
F_54 ( & V_79 -> V_7 . V_4 ) ;
return V_33 ;
}
static int F_67 ( T_1 V_42 ,
struct V_40 * V_41 ,
T_1 V_95 )
{
if ( ! ( V_95 & V_97 ) )
return F_68 ( V_41 , V_42 ,
V_80 ) ;
return 0 ;
}
int F_69 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 =
(struct V_109 * ) V_106 ;
struct V_1 * V_111 ;
struct V_5 * V_79 ;
struct V_40 * V_41 = F_70 ( V_108 ) -> V_41 ;
struct V_45 * V_112 ;
int V_33 ;
if ( ( V_110 -> V_95 & ( V_113 | V_114 ) ) == 0
|| ( V_110 -> V_95 & ~ ( V_113 | V_114 |
V_99 |
V_97 ) ) != 0 ) {
F_58 ( L_3 ) ;
return - V_46 ;
}
switch ( V_110 -> V_115 ) {
case V_116 :
V_33 = F_41 ( V_41 , V_110 -> V_42 , & V_111 ,
& V_112 ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
V_79 = F_1 ( V_111 , struct V_5 ,
V_7 ) ;
V_33 = F_63 ( V_79 , V_41 , V_110 -> V_95 ) ;
F_15 ( & V_111 ) ;
F_38 ( & V_112 ) ;
if ( F_34 ( V_33 != 0 && V_33 != - V_117 &&
V_33 != - V_103 ) ) {
F_58 ( L_4 ,
( unsigned int ) V_110 -> V_42 ) ;
return V_33 ;
}
break;
case V_118 :
V_33 = F_67 ( V_110 -> V_42 , V_41 ,
V_110 -> V_95 ) ;
if ( F_34 ( V_33 != 0 ) ) {
F_58 ( L_5 ,
( unsigned int ) V_110 -> V_42 ) ;
return V_33 ;
}
break;
default:
F_58 ( L_6 ) ;
return - V_46 ;
}
return 0 ;
}
int F_71 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_11 * V_12 = F_72 ( V_105 ) ;
union V_119 * V_110 =
(union V_119 * ) V_106 ;
struct V_120 * V_121 = & V_110 -> V_121 ;
struct V_122 * V_123 = & V_110 -> V_123 ;
struct V_1 * V_111 ;
T_1 V_42 ;
int V_33 ;
V_33 = F_73 ( & V_12 -> V_124 , true ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_56 ( V_12 , F_70 ( V_108 ) -> V_41 ,
V_121 -> V_54 , false , & V_42 , & V_111 ,
NULL ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_125;
V_123 -> V_42 = V_42 ;
V_123 -> V_126 = F_74 ( & V_111 -> V_4 . V_127 ) ;
V_123 -> V_128 = V_42 ;
V_123 -> V_129 = 0 ;
F_15 ( & V_111 ) ;
V_125:
F_75 ( & V_12 -> V_124 ) ;
return V_33 ;
}
int F_76 ( struct V_104 * V_105 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_130 * V_110 =
(struct V_130 * ) V_106 ;
return F_68 ( F_70 ( V_108 ) -> V_41 ,
V_110 -> V_42 ,
V_131 ) ;
}
int F_41 ( struct V_40 * V_41 ,
T_1 V_42 , struct V_1 * * V_132 ,
struct V_45 * * V_76 )
{
struct V_5 * V_66 ;
struct V_45 * V_4 ;
V_4 = F_33 ( V_41 , V_42 ) ;
if ( F_34 ( V_4 == NULL ) ) {
F_77 ( L_7 ,
( unsigned long ) V_42 ) ;
return - V_133 ;
}
if ( F_34 ( F_35 ( V_4 ) != V_88 ) ) {
F_38 ( & V_4 ) ;
F_77 ( L_7 ,
( unsigned long ) V_42 ) ;
return - V_46 ;
}
V_66 = F_1 ( V_4 , struct V_5 ,
V_67 . V_4 ) ;
( void ) F_59 ( & V_66 -> V_7 . V_4 ) ;
if ( V_76 )
* V_76 = V_4 ;
else
F_38 ( & V_4 ) ;
* V_132 = & V_66 -> V_7 ;
return 0 ;
}
int F_78 ( struct V_40 * V_41 ,
struct V_1 * V_111 ,
T_1 * V_42 )
{
struct V_5 * V_79 ;
if ( V_111 -> V_4 . V_93 != F_46 )
return - V_46 ;
V_79 = F_1 ( V_111 , struct V_5 , V_7 ) ;
* V_42 = V_79 -> V_67 . V_4 . V_91 . V_92 ;
return F_66 ( V_41 , & V_79 -> V_67 . V_4 ,
V_131 , NULL , false ) ;
}
int F_79 ( struct V_107 * V_108 ,
struct V_104 * V_105 ,
struct V_134 * args )
{
struct V_11 * V_12 = F_72 ( V_105 ) ;
struct V_1 * V_111 ;
int V_33 ;
args -> V_135 = args -> V_136 * ( ( args -> V_137 + 7 ) / 8 ) ;
args -> V_54 = args -> V_135 * args -> V_138 ;
V_33 = F_73 ( & V_12 -> V_124 , true ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
V_33 = F_56 ( V_12 , F_70 ( V_108 ) -> V_41 ,
args -> V_54 , false , & args -> V_42 ,
& V_111 , NULL ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_125;
F_15 ( & V_111 ) ;
V_125:
F_75 ( & V_12 -> V_124 ) ;
return V_33 ;
}
int F_80 ( struct V_107 * V_108 ,
struct V_104 * V_105 , T_1 V_42 ,
T_3 * V_139 )
{
struct V_40 * V_41 = F_70 ( V_108 ) -> V_41 ;
struct V_1 * V_52 ;
int V_33 ;
V_33 = F_41 ( V_41 , V_42 , & V_52 , NULL ) ;
if ( V_33 != 0 )
return - V_46 ;
* V_139 = F_74 ( & V_52 -> V_4 . V_127 ) ;
F_15 ( & V_52 ) ;
return 0 ;
}
int F_81 ( struct V_107 * V_108 ,
struct V_104 * V_105 ,
T_1 V_42 )
{
return F_68 ( F_70 ( V_108 ) -> V_41 ,
V_42 , V_131 ) ;
}
static int F_82 ( struct V_8 * V_9 ,
bool V_70 )
{
unsigned long V_54 =
( V_9 -> V_140 + V_141 - 1 ) & V_142 ;
struct V_1 * V_21 ;
int V_33 ;
if ( F_16 ( V_9 -> V_21 ) ) {
F_24 ( V_9 -> V_21 -> V_4 . V_58 * V_141 < V_54 ) ;
return 0 ;
}
V_21 = F_57 ( sizeof( * V_21 ) , V_34 ) ;
if ( F_34 ( ! V_21 ) )
return - V_84 ;
V_33 = F_48 ( V_9 -> V_12 , V_21 , V_9 -> V_140 ,
V_9 -> V_15 -> V_143 ,
V_70 ,
& F_45 ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_125;
V_9 -> V_21 = V_21 ;
V_125:
return V_33 ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_33 = 0 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
if ( F_34 ( V_9 -> V_18 == - 1 ) ) {
V_33 = V_15 -> V_144 ( V_9 ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
}
if ( V_15 -> V_145 &&
( ( V_15 -> V_146 && F_13 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_146 && V_25 -> V_3 != NULL ) ) ) {
V_33 = V_15 -> V_145 ( V_9 , V_25 ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_147;
if ( V_15 -> V_146 )
F_84 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_74 ) ;
}
V_9 -> V_39 = true ;
return 0 ;
V_147:
V_15 -> V_93 ( V_9 ) ;
return V_33 ;
}
void F_85 ( struct V_8 * V_9 ,
bool V_148 ,
struct V_1 * V_149 ,
unsigned long V_150 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_13 ( & V_9 -> V_20 ) )
return;
if ( V_148 && V_149 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_86 ( & V_9 -> V_21 -> V_4 . V_101 -> V_151 . V_4 ) ;
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
if ( V_149 ) {
V_9 -> V_21 = F_87 ( V_149 ) ;
F_86 ( & V_149 -> V_4 . V_101 -> V_151 . V_4 ) ;
F_84 ( & V_9 -> V_22 , & V_149 -> V_74 ) ;
} else {
V_9 -> V_21 = NULL ;
}
}
if ( V_148 )
V_9 -> V_38 = V_150 ;
if ( ! V_9 -> V_15 -> V_152 || V_9 -> V_18 == - 1 || V_9 -> V_153 )
return;
F_7 ( & V_12 -> V_17 ) ;
F_84 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_154 [ V_9 -> V_15 -> V_16 ] ) ;
F_9 ( & V_12 -> V_17 ) ;
}
static int
F_88 ( struct V_8 * V_9 ,
bool V_70 ,
struct V_24 * V_25 )
{
struct V_155 V_156 ;
bool V_27 = false ;
int V_33 ;
if ( F_34 ( V_9 -> V_21 == NULL ) ) {
V_33 = F_82 ( V_9 , V_70 ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
}
F_30 ( & V_156 ) ;
V_25 -> V_3 = F_59 ( & V_9 -> V_21 -> V_4 ) ;
V_25 -> V_26 = false ;
F_84 ( & V_25 -> V_157 , & V_156 ) ;
V_33 = F_89 ( NULL , & V_156 , V_70 , NULL ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_158;
if ( V_9 -> V_15 -> V_146 && F_13 ( & V_9 -> V_22 ) )
return 0 ;
V_27 = V_9 -> V_27 ;
V_33 = F_90 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_143 ,
true , false ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_159;
return 0 ;
V_159:
F_91 ( NULL , & V_156 ) ;
V_158:
F_52 ( & V_25 -> V_3 ) ;
if ( V_27 )
F_15 ( & V_9 -> V_21 ) ;
return V_33 ;
}
int F_92 ( struct V_8 * V_9 , bool V_70 ,
bool V_160 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_7 ( & V_12 -> V_17 ) ;
F_11 ( & V_9 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_146 && V_9 -> V_21 == NULL &&
! V_160 ) {
V_33 = F_82 ( V_9 , V_70 ) ;
if ( F_34 ( V_33 != 0 ) ) {
F_58 ( L_8
L_9 ,
( unsigned long ) V_9 -> V_140 ) ;
return V_33 ;
}
}
return 0 ;
}
static void
F_93 ( struct V_24 * V_25 )
{
struct V_155 V_156 ;
if ( F_16 ( V_25 -> V_3 == NULL ) )
return;
F_30 ( & V_156 ) ;
F_84 ( & V_25 -> V_157 , & V_156 ) ;
F_91 ( NULL , & V_156 ) ;
F_52 ( & V_25 -> V_3 ) ;
}
static int F_94 ( struct V_8 * V_9 , bool V_70 )
{
struct V_24 V_25 ;
const struct V_37 * V_15 = V_9 -> V_15 ;
int V_33 ;
F_24 ( ! V_15 -> V_152 ) ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
V_33 = F_88 ( V_9 , V_70 , & V_25 ) ;
if ( F_34 ( V_33 != 0 ) )
return V_33 ;
if ( F_34 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_146 || ! F_13 ( & V_9 -> V_22 ) ) ) ) {
V_33 = V_15 -> V_23 ( V_9 , V_9 -> V_39 , & V_25 ) ;
if ( F_34 ( V_33 != 0 ) )
goto V_161;
F_11 ( & V_9 -> V_22 ) ;
}
V_33 = V_15 -> V_93 ( V_9 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
V_161:
F_93 ( & V_25 ) ;
return V_33 ;
}
int F_95 ( struct V_8 * V_9 )
{
int V_33 ;
struct V_8 * V_162 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_155 * V_163 = & V_12 -> V_154 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
unsigned V_164 = 0 ;
if ( ! V_9 -> V_15 -> V_144 )
return 0 ;
V_25 . V_3 = NULL ;
V_25 . V_26 = false ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_33 = F_83 ( V_9 , & V_25 ) ;
if ( F_16 ( V_33 != - V_103 ) )
break;
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_163 ) || ! V_9 -> V_15 -> V_152 ) {
F_58 ( L_10
L_11 , V_9 -> V_15 -> V_165 ) ;
V_33 = - V_103 ;
F_9 ( & V_12 -> V_17 ) ;
break;
}
V_162 = F_2
( F_96 ( V_163 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_162 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_94 ( V_162 , true ) ;
if ( F_34 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_84 ( & V_162 -> V_20 , V_163 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( V_33 == - V_117 ||
++ V_164 > V_166 ) {
F_21 ( & V_162 ) ;
goto V_159;
}
}
F_21 ( & V_162 ) ;
} while ( 1 );
if ( F_34 ( V_33 != 0 ) )
goto V_159;
else if ( ! V_9 -> V_15 -> V_146 && V_9 -> V_21 ) {
F_11 ( & V_9 -> V_22 ) ;
F_15 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_159:
return V_33 ;
}
void F_97 ( struct V_2 * V_3 ,
struct V_167 * V_168 )
{
struct V_71 * V_72 = V_3 -> V_72 ;
struct V_11 * V_12 =
F_1 ( V_72 , struct V_11 , V_72 ) ;
if ( V_168 == NULL ) {
F_98 ( NULL , V_12 , & V_168 , NULL ) ;
F_99 ( V_3 -> V_101 , & V_168 -> V_4 ) ;
F_100 ( & V_168 -> V_4 ) ;
} else
F_99 ( V_3 -> V_101 , & V_168 -> V_4 ) ;
}
void F_101 ( struct V_2 * V_3 ,
struct V_169 * V_170 )
{
struct V_1 * V_111 ;
if ( V_170 == NULL )
return;
if ( V_3 -> V_93 != F_45 &&
V_3 -> V_93 != F_46 )
return;
V_111 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_170 -> V_171 != V_172 ) {
struct V_8 * V_9 , * V_173 ;
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
V_25 . V_26 = false ;
F_102 (res, n, &dma_buf->res_list, mob_head) {
if ( F_34 ( V_9 -> V_15 -> V_23 == NULL ) )
continue;
( void ) V_9 -> V_15 -> V_23 ( V_9 , true , & V_25 ) ;
V_9 -> V_27 = true ;
V_9 -> V_39 = false ;
F_11 ( & V_9 -> V_22 ) ;
}
( void ) F_103 ( V_3 , false , false ) ;
}
}
int F_104 ( struct V_1 * V_174 )
{
struct V_8 * V_175 ;
struct V_11 * V_12 ;
struct {
T_4 V_176 ;
T_5 V_177 ;
} * V_178 ;
if ( ! V_174 || ! V_174 -> V_175 )
return 0 ;
V_175 = V_174 -> V_175 ;
V_12 = V_175 -> V_12 ;
V_178 = F_105 ( V_12 , sizeof( * V_178 ) , V_175 -> V_18 ) ;
if ( F_34 ( V_178 == NULL ) ) {
F_58 ( L_12
L_13 ) ;
return - V_84 ;
}
V_178 -> V_176 . V_18 = V_179 ;
V_178 -> V_176 . V_54 = sizeof( V_178 -> V_177 ) ;
V_178 -> V_177 . V_180 = V_175 -> V_18 ;
F_106 ( V_12 , sizeof( * V_178 ) ) ;
V_174 -> V_175 = NULL ;
return 0 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_169 * V_170 )
{
struct V_1 * V_174 ;
struct V_71 * V_72 = V_3 -> V_72 ;
struct V_11 * V_12 ;
V_12 = F_1 ( V_72 , struct V_11 , V_72 ) ;
F_17 ( & V_12 -> V_29 ) ;
V_174 = F_1 ( V_3 , struct V_1 , V_4 ) ;
if ( V_170 == NULL || ! V_174 || ! V_174 -> V_175 ) {
F_19 ( & V_12 -> V_29 ) ;
return;
}
if ( V_170 -> V_171 == V_181 && V_3 -> V_170 . V_171 == V_172 ) {
struct V_167 * V_168 ;
( void ) F_104 ( V_174 ) ;
F_19 ( & V_12 -> V_29 ) ;
( void ) F_98 ( NULL , V_12 , & V_168 , NULL ) ;
F_97 ( V_3 , V_168 ) ;
if ( V_168 != NULL )
F_108 ( & V_168 ) ;
( void ) F_103 ( V_3 , false , false ) ;
} else
F_19 ( & V_12 -> V_29 ) ;
}
bool F_109 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_146 ;
}
static void F_110 ( struct V_11 * V_12 ,
enum V_182 type )
{
struct V_155 * V_163 = & V_12 -> V_154 [ type ] ;
struct V_8 * V_162 ;
unsigned V_164 = 0 ;
int V_33 ;
do {
F_7 ( & V_12 -> V_17 ) ;
if ( F_13 ( V_163 ) )
goto V_183;
V_162 = F_2 (
F_96 ( V_163 , struct V_8 ,
V_20 ) ) ;
F_11 ( & V_162 -> V_20 ) ;
F_9 ( & V_12 -> V_17 ) ;
V_33 = F_94 ( V_162 , false ) ;
if ( F_34 ( V_33 != 0 ) ) {
F_7 ( & V_12 -> V_17 ) ;
F_84 ( & V_162 -> V_20 , V_163 ) ;
F_9 ( & V_12 -> V_17 ) ;
if ( ++ V_164 > V_166 ) {
F_21 ( & V_162 ) ;
return;
}
}
F_21 ( & V_162 ) ;
} while ( 1 );
V_183:
F_9 ( & V_12 -> V_17 ) ;
}
void F_111 ( struct V_11 * V_12 )
{
enum V_182 type ;
F_17 ( & V_12 -> V_184 ) ;
for ( type = 0 ; type < V_185 ; ++ type )
F_110 ( V_12 , type ) ;
F_19 ( & V_12 -> V_184 ) ;
}
int F_112 ( struct V_8 * V_9 , bool V_70 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
F_113 ( & V_12 -> V_124 , V_70 ) ;
F_17 ( & V_12 -> V_184 ) ;
V_33 = F_92 ( V_9 , V_70 , false ) ;
if ( V_33 )
goto V_158;
if ( V_9 -> V_153 == 0 ) {
struct V_1 * V_186 = NULL ;
if ( V_9 -> V_21 ) {
V_186 = V_9 -> V_21 ;
F_12 ( & V_186 -> V_4 , V_70 , false , NULL ) ;
if ( ! V_186 -> V_153 ) {
V_33 = F_90
( & V_186 -> V_4 ,
V_9 -> V_15 -> V_143 ,
V_70 , false ) ;
if ( V_33 ) {
F_14 ( & V_186 -> V_4 ) ;
goto V_159;
}
}
F_114 ( V_186 , true ) ;
}
V_33 = F_95 ( V_9 ) ;
if ( V_186 )
F_14 ( & V_186 -> V_4 ) ;
if ( V_33 )
goto V_159;
}
V_9 -> V_153 ++ ;
V_159:
F_85 ( V_9 , false , NULL , 0UL ) ;
V_158:
F_19 ( & V_12 -> V_184 ) ;
F_115 ( & V_12 -> V_124 ) ;
return V_33 ;
}
void F_116 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_33 ;
( void ) F_73 ( & V_12 -> V_124 , false ) ;
F_17 ( & V_12 -> V_184 ) ;
V_33 = F_92 ( V_9 , false , true ) ;
F_117 ( V_33 ) ;
F_117 ( V_9 -> V_153 == 0 ) ;
if ( -- V_9 -> V_153 == 0 && V_9 -> V_21 ) {
struct V_1 * V_186 = V_9 -> V_21 ;
( void ) F_12 ( & V_186 -> V_4 , false , false , NULL ) ;
F_114 ( V_186 , false ) ;
F_14 ( & V_186 -> V_4 ) ;
}
F_85 ( V_9 , false , NULL , 0UL ) ;
F_19 ( & V_12 -> V_184 ) ;
F_75 ( & V_12 -> V_124 ) ;
}
enum V_182 V_182 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_16 ;
}
