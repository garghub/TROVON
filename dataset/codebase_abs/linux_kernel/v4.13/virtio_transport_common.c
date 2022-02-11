static const struct V_1 * F_1 ( void )
{
const struct V_2 * V_3 = F_2 () ;
return F_3 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 *
F_4 ( struct V_6 * V_7 ,
T_1 V_8 ,
T_2 V_9 ,
T_2 V_10 ,
T_2 V_11 ,
T_2 V_12 )
{
struct V_5 * V_13 ;
int V_14 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_16 . type = F_6 ( V_7 -> type ) ;
V_13 -> V_16 . V_17 = F_6 ( V_7 -> V_17 ) ;
V_13 -> V_16 . V_9 = F_7 ( V_9 ) ;
V_13 -> V_16 . V_11 = F_7 ( V_11 ) ;
V_13 -> V_16 . V_10 = F_8 ( V_10 ) ;
V_13 -> V_16 . V_12 = F_8 ( V_12 ) ;
V_13 -> V_16 . V_18 = F_8 ( V_7 -> V_18 ) ;
V_13 -> V_8 = V_8 ;
V_13 -> V_16 . V_8 = F_8 ( V_8 ) ;
V_13 -> V_19 = V_7 -> V_19 ;
V_13 -> V_20 = V_7 -> V_20 ;
if ( V_7 -> V_21 && V_8 > 0 ) {
V_13 -> V_22 = F_9 ( V_8 , V_15 ) ;
if ( ! V_13 -> V_22 )
goto V_23;
V_14 = F_10 ( V_13 -> V_22 , V_7 -> V_21 , V_8 ) ;
if ( V_14 )
goto V_24;
}
F_11 ( V_9 , V_10 ,
V_11 , V_12 ,
V_8 ,
V_7 -> type ,
V_7 -> V_17 ,
V_7 -> V_18 ) ;
return V_13 ;
V_24:
F_12 ( V_13 -> V_22 ) ;
V_23:
F_12 ( V_13 ) ;
return NULL ;
}
static struct V_25 * F_13 ( void * V_26 )
{
struct V_5 * V_13 = V_26 ;
struct V_27 * V_16 ;
struct V_25 * V_28 ;
V_28 = F_14 ( sizeof( * V_16 ) + sizeof( V_13 -> V_16 ) + V_13 -> V_8 ,
V_29 ) ;
if ( ! V_28 )
return NULL ;
V_16 = F_15 ( V_28 , sizeof( * V_16 ) ) ;
V_16 -> V_9 = V_13 -> V_16 . V_9 ;
V_16 -> V_10 = V_13 -> V_16 . V_10 ;
V_16 -> V_11 = V_13 -> V_16 . V_11 ;
V_16 -> V_12 = V_13 -> V_16 . V_12 ;
V_16 -> V_4 = F_6 ( V_30 ) ;
V_16 -> V_8 = F_6 ( sizeof( V_13 -> V_16 ) ) ;
memset ( V_16 -> V_31 , 0 , sizeof( V_16 -> V_31 ) ) ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_32 :
case V_33 :
V_16 -> V_17 = F_6 ( V_34 ) ;
break;
case V_35 :
case V_36 :
V_16 -> V_17 = F_6 ( V_37 ) ;
break;
case V_38 :
V_16 -> V_17 = F_6 ( V_39 ) ;
break;
case V_40 :
case V_41 :
V_16 -> V_17 = F_6 ( V_42 ) ;
break;
default:
V_16 -> V_17 = F_6 ( V_43 ) ;
break;
}
F_17 ( V_28 , & V_13 -> V_16 , sizeof( V_13 -> V_16 ) ) ;
if ( V_13 -> V_8 ) {
F_17 ( V_28 , V_13 -> V_22 , V_13 -> V_8 ) ;
}
return V_28 ;
}
void F_18 ( struct V_5 * V_13 )
{
F_19 ( F_13 , V_13 ) ;
}
static int F_20 ( struct V_44 * V_20 ,
struct V_6 * V_7 )
{
T_2 V_9 , V_10 , V_11 , V_12 ;
struct V_45 * V_46 ;
struct V_5 * V_13 ;
T_2 V_47 = V_7 -> V_47 ;
V_9 = F_21 () ;
V_10 = V_20 -> V_48 . V_49 ;
if ( ! V_7 -> V_50 ) {
V_11 = V_20 -> V_51 . V_52 ;
V_12 = V_20 -> V_51 . V_49 ;
} else {
V_11 = V_7 -> V_50 ;
V_12 = V_7 -> V_53 ;
}
V_46 = V_20 -> V_54 ;
if ( V_47 > V_55 )
V_47 = V_55 ;
V_47 = F_22 ( V_46 , V_47 ) ;
if ( V_47 == 0 && V_7 -> V_17 == V_38 )
return V_47 ;
V_13 = F_4 ( V_7 , V_47 ,
V_9 , V_10 ,
V_11 , V_12 ) ;
if ( ! V_13 ) {
F_23 ( V_46 , V_47 ) ;
return - V_56 ;
}
F_24 ( V_46 , V_13 ) ;
return F_1 () -> F_25 ( V_13 ) ;
}
static void F_26 ( struct V_45 * V_46 ,
struct V_5 * V_13 )
{
V_46 -> V_57 += V_13 -> V_8 ;
}
static void F_27 ( struct V_45 * V_46 ,
struct V_5 * V_13 )
{
V_46 -> V_57 -= V_13 -> V_8 ;
V_46 -> V_58 += V_13 -> V_8 ;
}
void F_24 ( struct V_45 * V_46 , struct V_5 * V_13 )
{
F_28 ( & V_46 -> V_59 ) ;
V_13 -> V_16 . V_58 = F_8 ( V_46 -> V_58 ) ;
V_13 -> V_16 . V_60 = F_8 ( V_46 -> V_60 ) ;
F_29 ( & V_46 -> V_59 ) ;
}
T_2 F_22 ( struct V_45 * V_46 , T_2 V_61 )
{
T_2 V_62 ;
F_28 ( & V_46 -> V_59 ) ;
V_62 = V_46 -> V_63 - ( V_46 -> V_64 - V_46 -> V_65 ) ;
if ( V_62 > V_61 )
V_62 = V_61 ;
V_46 -> V_64 += V_62 ;
F_29 ( & V_46 -> V_59 ) ;
return V_62 ;
}
void F_23 ( struct V_45 * V_46 , T_2 V_61 )
{
F_28 ( & V_46 -> V_59 ) ;
V_46 -> V_64 -= V_61 ;
F_29 ( & V_46 -> V_59 ) ;
}
static int F_30 ( struct V_44 * V_20 ,
int type ,
struct V_66 * V_16 )
{
struct V_6 V_7 = {
. V_17 = V_40 ,
. type = type ,
. V_20 = V_20 ,
} ;
return F_20 ( V_20 , & V_7 ) ;
}
static T_3
F_31 ( struct V_44 * V_20 ,
struct V_67 * V_21 ,
T_1 V_8 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
struct V_5 * V_13 ;
T_1 V_68 , V_69 = 0 ;
int V_14 = - V_70 ;
F_28 ( & V_46 -> V_71 ) ;
while ( V_69 < V_8 && ! F_32 ( & V_46 -> V_72 ) ) {
V_13 = F_33 ( & V_46 -> V_72 ,
struct V_5 , V_73 ) ;
V_68 = V_8 - V_69 ;
if ( V_68 > V_13 -> V_8 - V_13 -> V_74 )
V_68 = V_13 -> V_8 - V_13 -> V_74 ;
F_29 ( & V_46 -> V_71 ) ;
V_14 = F_34 ( V_21 , V_13 -> V_22 + V_13 -> V_74 , V_68 ) ;
if ( V_14 )
goto V_24;
F_28 ( & V_46 -> V_71 ) ;
V_69 += V_68 ;
V_13 -> V_74 += V_68 ;
if ( V_13 -> V_74 == V_13 -> V_8 ) {
F_27 ( V_46 , V_13 ) ;
F_35 ( & V_13 -> V_73 ) ;
F_36 ( V_13 ) ;
}
}
F_29 ( & V_46 -> V_71 ) ;
F_30 ( V_20 , V_75 ,
NULL ) ;
return V_69 ;
V_24:
if ( V_69 )
V_14 = V_69 ;
return V_14 ;
}
T_3
F_37 ( struct V_44 * V_20 ,
struct V_67 * V_21 ,
T_1 V_8 , int V_18 )
{
if ( V_18 & V_76 )
return - V_77 ;
return F_31 ( V_20 , V_21 , V_8 ) ;
}
int
F_38 ( struct V_44 * V_20 ,
struct V_67 * V_21 ,
T_1 V_8 , int V_18 )
{
return - V_77 ;
}
T_4 F_39 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
T_4 V_68 ;
F_28 ( & V_46 -> V_71 ) ;
V_68 = V_46 -> V_57 ;
F_29 ( & V_46 -> V_71 ) ;
return V_68 ;
}
static T_4 F_40 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
T_4 V_68 ;
V_68 = V_46 -> V_63 - ( V_46 -> V_64 - V_46 -> V_65 ) ;
if ( V_68 < 0 )
V_68 = 0 ;
return V_68 ;
}
T_4 F_41 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
T_4 V_68 ;
F_28 ( & V_46 -> V_59 ) ;
V_68 = F_40 ( V_20 ) ;
F_29 ( & V_46 -> V_59 ) ;
return V_68 ;
}
int F_42 ( struct V_44 * V_20 ,
struct V_44 * V_78 )
{
struct V_45 * V_46 ;
V_46 = F_5 ( sizeof( * V_46 ) , V_15 ) ;
if ( ! V_46 )
return - V_56 ;
V_20 -> V_54 = V_46 ;
V_46 -> V_20 = V_20 ;
if ( V_78 ) {
struct V_45 * V_79 = V_78 -> V_54 ;
V_46 -> V_80 = V_79 -> V_80 ;
V_46 -> V_81 = V_79 -> V_81 ;
V_46 -> V_82 = V_79 -> V_82 ;
V_46 -> V_63 = V_79 -> V_63 ;
} else {
V_46 -> V_80 = V_83 ;
V_46 -> V_81 = V_84 ;
V_46 -> V_82 = V_85 ;
}
V_46 -> V_60 = V_46 -> V_80 ;
F_43 ( & V_46 -> V_71 ) ;
F_43 ( & V_46 -> V_59 ) ;
F_44 ( & V_46 -> V_72 ) ;
return 0 ;
}
T_5 F_45 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
return V_46 -> V_80 ;
}
T_5 F_46 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
return V_46 -> V_81 ;
}
T_5 F_47 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
return V_46 -> V_82 ;
}
void F_48 ( struct V_44 * V_20 , T_5 V_86 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
if ( V_86 > V_87 )
V_86 = V_87 ;
if ( V_86 < V_46 -> V_81 )
V_46 -> V_81 = V_86 ;
if ( V_86 > V_46 -> V_82 )
V_46 -> V_82 = V_86 ;
V_46 -> V_80 = V_86 ;
V_46 -> V_60 = V_86 ;
}
void F_49 ( struct V_44 * V_20 , T_5 V_86 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
if ( V_86 > V_87 )
V_86 = V_87 ;
if ( V_86 > V_46 -> V_80 )
V_46 -> V_80 = V_86 ;
V_46 -> V_81 = V_86 ;
}
void F_50 ( struct V_44 * V_20 , T_5 V_86 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
if ( V_86 > V_87 )
V_86 = V_87 ;
if ( V_86 < V_46 -> V_80 )
V_46 -> V_80 = V_86 ;
V_46 -> V_82 = V_86 ;
}
int
F_51 ( struct V_44 * V_20 ,
T_1 V_88 ,
bool * V_89 )
{
if ( F_52 ( V_20 ) )
* V_89 = true ;
else
* V_89 = false ;
return 0 ;
}
int
F_53 ( struct V_44 * V_20 ,
T_1 V_88 ,
bool * V_90 )
{
T_4 V_91 ;
V_91 = F_54 ( V_20 ) ;
if ( V_91 > 0 )
* V_90 = true ;
else if ( V_91 == 0 )
* V_90 = false ;
return 0 ;
}
int F_55 ( struct V_44 * V_20 ,
T_1 V_88 , struct V_92 * V_93 )
{
return 0 ;
}
int F_56 ( struct V_44 * V_20 ,
T_1 V_88 , struct V_92 * V_93 )
{
return 0 ;
}
int F_57 ( struct V_44 * V_20 ,
T_1 V_88 , struct V_92 * V_93 )
{
return 0 ;
}
int F_58 ( struct V_44 * V_20 ,
T_1 V_88 , T_3 V_94 , bool V_95 ,
struct V_92 * V_93 )
{
return 0 ;
}
int F_59 ( struct V_44 * V_20 ,
struct V_96 * V_93 )
{
return 0 ;
}
int F_60 ( struct V_44 * V_20 ,
struct V_96 * V_93 )
{
return 0 ;
}
int F_61 ( struct V_44 * V_20 ,
struct V_96 * V_93 )
{
return 0 ;
}
int F_62 ( struct V_44 * V_20 ,
T_3 V_97 , struct V_96 * V_93 )
{
return 0 ;
}
T_5 F_63 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
return V_46 -> V_80 ;
}
bool F_64 ( struct V_44 * V_20 )
{
return true ;
}
bool F_65 ( T_2 V_98 , T_2 V_99 )
{
return true ;
}
int F_66 ( struct V_44 * V_20 ,
struct V_100 * V_101 )
{
return - V_77 ;
}
bool F_67 ( T_2 V_98 , T_2 V_99 )
{
return false ;
}
int F_68 ( struct V_44 * V_20 )
{
struct V_6 V_7 = {
. V_17 = V_32 ,
. type = V_75 ,
. V_20 = V_20 ,
} ;
return F_20 ( V_20 , & V_7 ) ;
}
int F_69 ( struct V_44 * V_20 , int V_102 )
{
struct V_6 V_7 = {
. V_17 = V_36 ,
. type = V_75 ,
. V_18 = ( V_102 & V_103 ?
V_104 : 0 ) |
( V_102 & V_105 ?
V_106 : 0 ) ,
. V_20 = V_20 ,
} ;
return F_20 ( V_20 , & V_7 ) ;
}
int
F_70 ( struct V_44 * V_20 ,
struct V_100 * V_51 ,
struct V_67 * V_21 ,
T_1 V_107 )
{
return - V_77 ;
}
T_3
F_71 ( struct V_44 * V_20 ,
struct V_67 * V_21 ,
T_1 V_8 )
{
struct V_6 V_7 = {
. V_17 = V_38 ,
. type = V_75 ,
. V_21 = V_21 ,
. V_47 = V_8 ,
. V_20 = V_20 ,
} ;
return F_20 ( V_20 , & V_7 ) ;
}
void F_72 ( struct V_44 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_54 ;
F_12 ( V_46 ) ;
}
static int F_73 ( struct V_44 * V_20 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_35 ,
. type = V_75 ,
. V_19 = ! ! V_13 ,
. V_20 = V_20 ,
} ;
if ( V_13 && F_16 ( V_13 -> V_16 . V_17 ) == V_35 )
return 0 ;
return F_20 ( V_20 , & V_7 ) ;
}
static int F_74 ( struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_35 ,
. type = F_16 ( V_13 -> V_16 . type ) ,
. V_19 = true ,
} ;
if ( F_16 ( V_13 -> V_16 . V_17 ) == V_35 )
return 0 ;
V_13 = F_4 ( & V_7 , 0 ,
F_75 ( V_13 -> V_16 . V_11 ) ,
F_76 ( V_13 -> V_16 . V_12 ) ,
F_75 ( V_13 -> V_16 . V_9 ) ,
F_76 ( V_13 -> V_16 . V_10 ) ) ;
if ( ! V_13 )
return - V_56 ;
return F_1 () -> F_25 ( V_13 ) ;
}
static void F_77 ( struct V_108 * V_109 , long V_110 )
{
if ( V_110 ) {
F_78 ( V_111 , V_112 ) ;
F_79 ( F_80 ( V_109 ) , & V_111 ) ;
do {
if ( F_81 ( V_109 , & V_110 ,
F_82 ( V_109 , V_113 ) , & V_111 ) )
break;
} while ( ! F_83 ( V_114 ) && V_110 );
F_84 ( F_80 ( V_109 ) , & V_111 ) ;
}
}
static void F_85 ( struct V_44 * V_20 ,
bool V_115 )
{
struct V_108 * V_109 = F_86 ( V_20 ) ;
F_87 ( V_109 , V_113 ) ;
V_20 -> V_116 = V_117 ;
if ( F_52 ( V_20 ) <= 0 )
V_109 -> V_118 = V_119 ;
V_109 -> V_120 ( V_109 ) ;
if ( V_20 -> V_121 &&
( ! V_115 || F_88 ( & V_20 -> V_122 ) ) ) {
V_20 -> V_121 = false ;
F_89 ( V_20 ) ;
F_90 ( V_109 ) ;
}
}
static void F_91 ( struct V_123 * V_124 )
{
struct V_44 * V_20 =
F_3 ( V_124 , struct V_44 , V_122 . V_124 ) ;
struct V_108 * V_109 = F_86 ( V_20 ) ;
F_92 ( V_109 ) ;
F_93 ( V_109 ) ;
if ( ! F_82 ( V_109 , V_113 ) ) {
( void ) F_73 ( V_20 , NULL ) ;
F_85 ( V_20 , false ) ;
}
V_20 -> V_121 = false ;
F_94 ( V_109 ) ;
F_90 ( V_109 ) ;
}
static bool F_95 ( struct V_44 * V_20 )
{
struct V_108 * V_109 = & V_20 -> V_109 ;
if ( ! ( V_109 -> V_118 == V_125 ||
V_109 -> V_118 == V_119 ) )
return true ;
if ( ( V_20 -> V_116 & V_117 ) == V_117 ) {
( void ) F_73 ( V_20 , NULL ) ;
return true ;
}
if ( ( V_109 -> V_126 & V_117 ) != V_117 )
( void ) F_69 ( V_20 , V_117 ) ;
if ( F_82 ( V_109 , V_127 ) && ! ( V_114 -> V_18 & V_128 ) )
F_77 ( V_109 , V_109 -> V_129 ) ;
if ( F_82 ( V_109 , V_113 ) ) {
return true ;
}
F_92 ( V_109 ) ;
F_96 ( & V_20 -> V_122 ,
F_91 ) ;
V_20 -> V_121 = true ;
F_97 ( & V_20 -> V_122 , V_130 ) ;
return false ;
}
void F_98 ( struct V_44 * V_20 )
{
struct V_108 * V_109 = & V_20 -> V_109 ;
bool V_131 = true ;
F_93 ( V_109 ) ;
if ( V_109 -> V_132 == V_133 )
V_131 = F_95 ( V_20 ) ;
F_94 ( V_109 ) ;
if ( V_131 )
F_89 ( V_20 ) ;
}
static int
F_99 ( struct V_108 * V_109 ,
struct V_5 * V_13 )
{
struct V_44 * V_20 = F_100 ( V_109 ) ;
int V_14 ;
int V_134 ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_33 :
V_109 -> V_118 = V_125 ;
V_109 -> V_135 -> V_136 = V_125 ;
F_101 ( V_20 ) ;
V_109 -> V_120 ( V_109 ) ;
break;
case V_137 :
break;
case V_35 :
V_134 = V_138 ;
V_14 = 0 ;
goto V_139;
default:
V_134 = V_140 ;
V_14 = - V_141 ;
goto V_139;
}
return 0 ;
V_139:
F_73 ( V_20 , V_13 ) ;
V_109 -> V_118 = V_142 ;
V_109 -> V_143 = V_134 ;
V_109 -> V_144 ( V_109 ) ;
return V_14 ;
}
static int
F_102 ( struct V_108 * V_109 ,
struct V_5 * V_13 )
{
struct V_44 * V_20 = F_100 ( V_109 ) ;
struct V_45 * V_46 = V_20 -> V_54 ;
int V_14 = 0 ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_38 :
V_13 -> V_8 = F_76 ( V_13 -> V_16 . V_8 ) ;
V_13 -> V_74 = 0 ;
F_28 ( & V_46 -> V_71 ) ;
F_26 ( V_46 , V_13 ) ;
F_103 ( & V_13 -> V_73 , & V_46 -> V_72 ) ;
F_29 ( & V_46 -> V_71 ) ;
V_109 -> V_145 ( V_109 ) ;
return V_14 ;
case V_40 :
V_109 -> V_146 ( V_109 ) ;
break;
case V_36 :
if ( F_76 ( V_13 -> V_16 . V_18 ) & V_104 )
V_20 -> V_116 |= V_103 ;
if ( F_76 ( V_13 -> V_16 . V_18 ) & V_106 )
V_20 -> V_116 |= V_105 ;
if ( V_20 -> V_116 == V_117 &&
F_52 ( V_20 ) <= 0 )
V_109 -> V_118 = V_119 ;
if ( F_76 ( V_13 -> V_16 . V_18 ) )
V_109 -> V_120 ( V_109 ) ;
break;
case V_35 :
F_85 ( V_20 , true ) ;
break;
default:
V_14 = - V_141 ;
break;
}
F_36 ( V_13 ) ;
return V_14 ;
}
static void
F_104 ( struct V_108 * V_109 ,
struct V_5 * V_13 )
{
struct V_44 * V_20 = F_100 ( V_109 ) ;
if ( F_16 ( V_13 -> V_16 . V_17 ) == V_35 )
F_85 ( V_20 , true ) ;
}
static int
F_105 ( struct V_44 * V_20 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_33 ,
. type = V_75 ,
. V_50 = F_75 ( V_13 -> V_16 . V_9 ) ,
. V_53 = F_76 ( V_13 -> V_16 . V_10 ) ,
. V_19 = true ,
. V_20 = V_20 ,
} ;
return F_20 ( V_20 , & V_7 ) ;
}
static int
F_106 ( struct V_108 * V_109 , struct V_5 * V_13 )
{
struct V_44 * V_20 = F_100 ( V_109 ) ;
struct V_44 * V_147 ;
struct V_108 * V_148 ;
if ( F_16 ( V_13 -> V_16 . V_17 ) != V_32 ) {
F_73 ( V_20 , V_13 ) ;
return - V_141 ;
}
if ( F_107 ( V_109 ) ) {
F_73 ( V_20 , V_13 ) ;
return - V_56 ;
}
V_148 = F_108 ( F_109 ( V_109 ) , NULL , V_109 , V_15 ,
V_109 -> V_132 , 0 ) ;
if ( ! V_148 ) {
F_73 ( V_20 , V_13 ) ;
return - V_56 ;
}
V_109 -> V_149 ++ ;
F_110 ( V_148 , V_150 ) ;
V_148 -> V_118 = V_125 ;
V_147 = F_100 ( V_148 ) ;
F_111 ( & V_147 -> V_48 , F_75 ( V_13 -> V_16 . V_11 ) ,
F_76 ( V_13 -> V_16 . V_12 ) ) ;
F_111 ( & V_147 -> V_51 , F_75 ( V_13 -> V_16 . V_9 ) ,
F_76 ( V_13 -> V_16 . V_10 ) ) ;
F_101 ( V_147 ) ;
F_112 ( V_109 , V_148 ) ;
F_105 ( V_147 , V_13 ) ;
F_94 ( V_148 ) ;
V_109 -> V_145 ( V_109 ) ;
return 0 ;
}
static bool F_113 ( struct V_108 * V_109 ,
struct V_5 * V_13 )
{
struct V_44 * V_20 = F_100 ( V_109 ) ;
struct V_45 * V_46 = V_20 -> V_54 ;
bool V_151 ;
F_28 ( & V_46 -> V_59 ) ;
V_46 -> V_63 = F_76 ( V_13 -> V_16 . V_60 ) ;
V_46 -> V_65 = F_76 ( V_13 -> V_16 . V_58 ) ;
V_151 = F_40 ( V_20 ) ;
F_29 ( & V_46 -> V_59 ) ;
return V_151 ;
}
void F_114 ( struct V_5 * V_13 )
{
struct V_100 V_152 , V_153 ;
struct V_44 * V_20 ;
struct V_108 * V_109 ;
bool V_151 ;
F_111 ( & V_152 , F_75 ( V_13 -> V_16 . V_9 ) ,
F_76 ( V_13 -> V_16 . V_10 ) ) ;
F_111 ( & V_153 , F_75 ( V_13 -> V_16 . V_11 ) ,
F_76 ( V_13 -> V_16 . V_12 ) ) ;
F_115 ( V_152 . V_52 , V_152 . V_49 ,
V_153 . V_52 , V_153 . V_49 ,
F_76 ( V_13 -> V_16 . V_8 ) ,
F_16 ( V_13 -> V_16 . type ) ,
F_16 ( V_13 -> V_16 . V_17 ) ,
F_76 ( V_13 -> V_16 . V_18 ) ,
F_76 ( V_13 -> V_16 . V_60 ) ,
F_76 ( V_13 -> V_16 . V_58 ) ) ;
if ( F_16 ( V_13 -> V_16 . type ) != V_75 ) {
( void ) F_74 ( V_13 ) ;
goto V_154;
}
V_109 = F_116 ( & V_152 , & V_153 ) ;
if ( ! V_109 ) {
V_109 = F_117 ( & V_153 ) ;
if ( ! V_109 ) {
( void ) F_74 ( V_13 ) ;
goto V_154;
}
}
V_20 = F_100 ( V_109 ) ;
V_151 = F_113 ( V_109 , V_13 ) ;
F_93 ( V_109 ) ;
V_20 -> V_48 . V_52 = V_153 . V_52 ;
if ( V_151 )
V_109 -> V_146 ( V_109 ) ;
switch ( V_109 -> V_118 ) {
case V_155 :
F_106 ( V_109 , V_13 ) ;
F_36 ( V_13 ) ;
break;
case V_156 :
F_99 ( V_109 , V_13 ) ;
F_36 ( V_13 ) ;
break;
case V_125 :
F_102 ( V_109 , V_13 ) ;
break;
case V_119 :
F_104 ( V_109 , V_13 ) ;
F_36 ( V_13 ) ;
break;
default:
F_36 ( V_13 ) ;
break;
}
F_94 ( V_109 ) ;
F_90 ( V_109 ) ;
return;
V_154:
F_36 ( V_13 ) ;
}
void F_36 ( struct V_5 * V_13 )
{
F_12 ( V_13 -> V_22 ) ;
F_12 ( V_13 ) ;
}
