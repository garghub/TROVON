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
unsigned char * V_27 , * V_28 ;
struct V_29 * V_16 ;
struct V_25 * V_30 ;
V_30 = F_14 ( sizeof( * V_16 ) + sizeof( V_13 -> V_16 ) + V_13 -> V_8 ,
V_31 ) ;
if ( ! V_30 )
return NULL ;
V_16 = (struct V_29 * ) F_15 ( V_30 , sizeof( * V_16 ) ) ;
V_16 -> V_9 = V_13 -> V_16 . V_9 ;
V_16 -> V_10 = V_13 -> V_16 . V_10 ;
V_16 -> V_11 = V_13 -> V_16 . V_11 ;
V_16 -> V_12 = V_13 -> V_16 . V_12 ;
V_16 -> V_4 = F_6 ( V_32 ) ;
V_16 -> V_8 = F_6 ( sizeof( V_13 -> V_16 ) ) ;
memset ( V_16 -> V_33 , 0 , sizeof( V_16 -> V_33 ) ) ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_34 :
case V_35 :
V_16 -> V_17 = F_6 ( V_36 ) ;
break;
case V_37 :
case V_38 :
V_16 -> V_17 = F_6 ( V_39 ) ;
break;
case V_40 :
V_16 -> V_17 = F_6 ( V_41 ) ;
break;
case V_42 :
case V_43 :
V_16 -> V_17 = F_6 ( V_44 ) ;
break;
default:
V_16 -> V_17 = F_6 ( V_45 ) ;
break;
}
V_27 = F_15 ( V_30 , sizeof( V_13 -> V_16 ) ) ;
memcpy ( V_27 , & V_13 -> V_16 , sizeof( V_13 -> V_16 ) ) ;
if ( V_13 -> V_8 ) {
V_28 = F_15 ( V_30 , V_13 -> V_8 ) ;
memcpy ( V_28 , V_13 -> V_22 , V_13 -> V_8 ) ;
}
return V_30 ;
}
void F_17 ( struct V_5 * V_13 )
{
F_18 ( F_13 , V_13 ) ;
}
static int F_19 ( struct V_46 * V_20 ,
struct V_6 * V_7 )
{
T_2 V_9 , V_10 , V_11 , V_12 ;
struct V_47 * V_48 ;
struct V_5 * V_13 ;
T_2 V_49 = V_7 -> V_49 ;
V_9 = F_20 () ;
V_10 = V_20 -> V_50 . V_51 ;
if ( ! V_7 -> V_52 ) {
V_11 = V_20 -> V_53 . V_54 ;
V_12 = V_20 -> V_53 . V_51 ;
} else {
V_11 = V_7 -> V_52 ;
V_12 = V_7 -> V_55 ;
}
V_48 = V_20 -> V_56 ;
if ( V_49 > V_57 )
V_49 = V_57 ;
V_49 = F_21 ( V_48 , V_49 ) ;
if ( V_49 == 0 && V_7 -> V_17 == V_40 )
return V_49 ;
V_13 = F_4 ( V_7 , V_49 ,
V_9 , V_10 ,
V_11 , V_12 ) ;
if ( ! V_13 ) {
F_22 ( V_48 , V_49 ) ;
return - V_58 ;
}
F_23 ( V_48 , V_13 ) ;
return F_1 () -> F_24 ( V_13 ) ;
}
static void F_25 ( struct V_47 * V_48 ,
struct V_5 * V_13 )
{
V_48 -> V_59 += V_13 -> V_8 ;
}
static void F_26 ( struct V_47 * V_48 ,
struct V_5 * V_13 )
{
V_48 -> V_59 -= V_13 -> V_8 ;
V_48 -> V_60 += V_13 -> V_8 ;
}
void F_23 ( struct V_47 * V_48 , struct V_5 * V_13 )
{
F_27 ( & V_48 -> V_61 ) ;
V_13 -> V_16 . V_60 = F_8 ( V_48 -> V_60 ) ;
V_13 -> V_16 . V_62 = F_8 ( V_48 -> V_62 ) ;
F_28 ( & V_48 -> V_61 ) ;
}
T_2 F_21 ( struct V_47 * V_48 , T_2 V_63 )
{
T_2 V_64 ;
F_27 ( & V_48 -> V_61 ) ;
V_64 = V_48 -> V_65 - ( V_48 -> V_66 - V_48 -> V_67 ) ;
if ( V_64 > V_63 )
V_64 = V_63 ;
V_48 -> V_66 += V_64 ;
F_28 ( & V_48 -> V_61 ) ;
return V_64 ;
}
void F_22 ( struct V_47 * V_48 , T_2 V_63 )
{
F_27 ( & V_48 -> V_61 ) ;
V_48 -> V_66 -= V_63 ;
F_28 ( & V_48 -> V_61 ) ;
}
static int F_29 ( struct V_46 * V_20 ,
int type ,
struct V_68 * V_16 )
{
struct V_6 V_7 = {
. V_17 = V_42 ,
. type = type ,
. V_20 = V_20 ,
} ;
return F_19 ( V_20 , & V_7 ) ;
}
static T_3
F_30 ( struct V_46 * V_20 ,
struct V_69 * V_21 ,
T_1 V_8 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
struct V_5 * V_13 ;
T_1 V_70 , V_71 = 0 ;
int V_14 = - V_72 ;
F_27 ( & V_48 -> V_73 ) ;
while ( V_71 < V_8 && ! F_31 ( & V_48 -> V_74 ) ) {
V_13 = F_32 ( & V_48 -> V_74 ,
struct V_5 , V_75 ) ;
V_70 = V_8 - V_71 ;
if ( V_70 > V_13 -> V_8 - V_13 -> V_76 )
V_70 = V_13 -> V_8 - V_13 -> V_76 ;
F_28 ( & V_48 -> V_73 ) ;
V_14 = F_33 ( V_21 , V_13 -> V_22 + V_13 -> V_76 , V_70 ) ;
if ( V_14 )
goto V_24;
F_27 ( & V_48 -> V_73 ) ;
V_71 += V_70 ;
V_13 -> V_76 += V_70 ;
if ( V_13 -> V_76 == V_13 -> V_8 ) {
F_26 ( V_48 , V_13 ) ;
F_34 ( & V_13 -> V_75 ) ;
F_35 ( V_13 ) ;
}
}
F_28 ( & V_48 -> V_73 ) ;
F_29 ( V_20 , V_77 ,
NULL ) ;
return V_71 ;
V_24:
if ( V_71 )
V_14 = V_71 ;
return V_14 ;
}
T_3
F_36 ( struct V_46 * V_20 ,
struct V_69 * V_21 ,
T_1 V_8 , int V_18 )
{
if ( V_18 & V_78 )
return - V_79 ;
return F_30 ( V_20 , V_21 , V_8 ) ;
}
int
F_37 ( struct V_46 * V_20 ,
struct V_69 * V_21 ,
T_1 V_8 , int V_18 )
{
return - V_79 ;
}
T_4 F_38 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
T_4 V_70 ;
F_27 ( & V_48 -> V_73 ) ;
V_70 = V_48 -> V_59 ;
F_28 ( & V_48 -> V_73 ) ;
return V_70 ;
}
static T_4 F_39 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
T_4 V_70 ;
V_70 = V_48 -> V_65 - ( V_48 -> V_66 - V_48 -> V_67 ) ;
if ( V_70 < 0 )
V_70 = 0 ;
return V_70 ;
}
T_4 F_40 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
T_4 V_70 ;
F_27 ( & V_48 -> V_61 ) ;
V_70 = F_39 ( V_20 ) ;
F_28 ( & V_48 -> V_61 ) ;
return V_70 ;
}
int F_41 ( struct V_46 * V_20 ,
struct V_46 * V_80 )
{
struct V_47 * V_48 ;
V_48 = F_5 ( sizeof( * V_48 ) , V_15 ) ;
if ( ! V_48 )
return - V_58 ;
V_20 -> V_56 = V_48 ;
V_48 -> V_20 = V_20 ;
if ( V_80 ) {
struct V_47 * V_81 = V_80 -> V_56 ;
V_48 -> V_82 = V_81 -> V_82 ;
V_48 -> V_83 = V_81 -> V_83 ;
V_48 -> V_84 = V_81 -> V_84 ;
V_48 -> V_65 = V_81 -> V_65 ;
} else {
V_48 -> V_82 = V_85 ;
V_48 -> V_83 = V_86 ;
V_48 -> V_84 = V_87 ;
}
V_48 -> V_62 = V_48 -> V_82 ;
F_42 ( & V_48 -> V_73 ) ;
F_42 ( & V_48 -> V_61 ) ;
F_43 ( & V_48 -> V_74 ) ;
return 0 ;
}
T_5 F_44 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
return V_48 -> V_82 ;
}
T_5 F_45 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
return V_48 -> V_83 ;
}
T_5 F_46 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
return V_48 -> V_84 ;
}
void F_47 ( struct V_46 * V_20 , T_5 V_88 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
if ( V_88 > V_89 )
V_88 = V_89 ;
if ( V_88 < V_48 -> V_83 )
V_48 -> V_83 = V_88 ;
if ( V_88 > V_48 -> V_84 )
V_48 -> V_84 = V_88 ;
V_48 -> V_82 = V_88 ;
V_48 -> V_62 = V_88 ;
}
void F_48 ( struct V_46 * V_20 , T_5 V_88 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
if ( V_88 > V_89 )
V_88 = V_89 ;
if ( V_88 > V_48 -> V_82 )
V_48 -> V_82 = V_88 ;
V_48 -> V_83 = V_88 ;
}
void F_49 ( struct V_46 * V_20 , T_5 V_88 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
if ( V_88 > V_89 )
V_88 = V_89 ;
if ( V_88 < V_48 -> V_82 )
V_48 -> V_82 = V_88 ;
V_48 -> V_84 = V_88 ;
}
int
F_50 ( struct V_46 * V_20 ,
T_1 V_90 ,
bool * V_91 )
{
if ( F_51 ( V_20 ) )
* V_91 = true ;
else
* V_91 = false ;
return 0 ;
}
int
F_52 ( struct V_46 * V_20 ,
T_1 V_90 ,
bool * V_92 )
{
T_4 V_93 ;
V_93 = F_53 ( V_20 ) ;
if ( V_93 > 0 )
* V_92 = true ;
else if ( V_93 == 0 )
* V_92 = false ;
return 0 ;
}
int F_54 ( struct V_46 * V_20 ,
T_1 V_90 , struct V_94 * V_95 )
{
return 0 ;
}
int F_55 ( struct V_46 * V_20 ,
T_1 V_90 , struct V_94 * V_95 )
{
return 0 ;
}
int F_56 ( struct V_46 * V_20 ,
T_1 V_90 , struct V_94 * V_95 )
{
return 0 ;
}
int F_57 ( struct V_46 * V_20 ,
T_1 V_90 , T_3 V_96 , bool V_97 ,
struct V_94 * V_95 )
{
return 0 ;
}
int F_58 ( struct V_46 * V_20 ,
struct V_98 * V_95 )
{
return 0 ;
}
int F_59 ( struct V_46 * V_20 ,
struct V_98 * V_95 )
{
return 0 ;
}
int F_60 ( struct V_46 * V_20 ,
struct V_98 * V_95 )
{
return 0 ;
}
int F_61 ( struct V_46 * V_20 ,
T_3 V_99 , struct V_98 * V_95 )
{
return 0 ;
}
T_5 F_62 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
return V_48 -> V_82 ;
}
bool F_63 ( struct V_46 * V_20 )
{
return true ;
}
bool F_64 ( T_2 V_100 , T_2 V_101 )
{
return true ;
}
int F_65 ( struct V_46 * V_20 ,
struct V_102 * V_103 )
{
return - V_79 ;
}
bool F_66 ( T_2 V_100 , T_2 V_101 )
{
return false ;
}
int F_67 ( struct V_46 * V_20 )
{
struct V_6 V_7 = {
. V_17 = V_34 ,
. type = V_77 ,
. V_20 = V_20 ,
} ;
return F_19 ( V_20 , & V_7 ) ;
}
int F_68 ( struct V_46 * V_20 , int V_104 )
{
struct V_6 V_7 = {
. V_17 = V_38 ,
. type = V_77 ,
. V_18 = ( V_104 & V_105 ?
V_106 : 0 ) |
( V_104 & V_107 ?
V_108 : 0 ) ,
. V_20 = V_20 ,
} ;
return F_19 ( V_20 , & V_7 ) ;
}
int
F_69 ( struct V_46 * V_20 ,
struct V_102 * V_53 ,
struct V_69 * V_21 ,
T_1 V_109 )
{
return - V_79 ;
}
T_3
F_70 ( struct V_46 * V_20 ,
struct V_69 * V_21 ,
T_1 V_8 )
{
struct V_6 V_7 = {
. V_17 = V_40 ,
. type = V_77 ,
. V_21 = V_21 ,
. V_49 = V_8 ,
. V_20 = V_20 ,
} ;
return F_19 ( V_20 , & V_7 ) ;
}
void F_71 ( struct V_46 * V_20 )
{
struct V_47 * V_48 = V_20 -> V_56 ;
F_12 ( V_48 ) ;
}
static int F_72 ( struct V_46 * V_20 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_37 ,
. type = V_77 ,
. V_19 = ! ! V_13 ,
. V_20 = V_20 ,
} ;
if ( V_13 && F_16 ( V_13 -> V_16 . V_17 ) == V_37 )
return 0 ;
return F_19 ( V_20 , & V_7 ) ;
}
static int F_73 ( struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_37 ,
. type = F_16 ( V_13 -> V_16 . type ) ,
. V_19 = true ,
} ;
if ( F_16 ( V_13 -> V_16 . V_17 ) == V_37 )
return 0 ;
V_13 = F_4 ( & V_7 , 0 ,
F_74 ( V_13 -> V_16 . V_11 ) ,
F_75 ( V_13 -> V_16 . V_12 ) ,
F_74 ( V_13 -> V_16 . V_9 ) ,
F_75 ( V_13 -> V_16 . V_10 ) ) ;
if ( ! V_13 )
return - V_58 ;
return F_1 () -> F_24 ( V_13 ) ;
}
static void F_76 ( struct V_110 * V_111 , long V_112 )
{
if ( V_112 ) {
F_77 ( V_113 , V_114 ) ;
F_78 ( F_79 ( V_111 ) , & V_113 ) ;
do {
if ( F_80 ( V_111 , & V_112 ,
F_81 ( V_111 , V_115 ) , & V_113 ) )
break;
} while ( ! F_82 ( V_116 ) && V_112 );
F_83 ( F_79 ( V_111 ) , & V_113 ) ;
}
}
static void F_84 ( struct V_46 * V_20 ,
bool V_117 )
{
struct V_110 * V_111 = F_85 ( V_20 ) ;
F_86 ( V_111 , V_115 ) ;
V_20 -> V_118 = V_119 ;
if ( F_51 ( V_20 ) <= 0 )
V_111 -> V_120 = V_121 ;
V_111 -> V_122 ( V_111 ) ;
if ( V_20 -> V_123 &&
( ! V_117 || F_87 ( & V_20 -> V_124 ) ) ) {
V_20 -> V_123 = false ;
F_88 ( V_20 ) ;
F_89 ( V_111 ) ;
}
}
static void F_90 ( struct V_125 * V_126 )
{
struct V_46 * V_20 =
F_3 ( V_126 , struct V_46 , V_124 . V_126 ) ;
struct V_110 * V_111 = F_85 ( V_20 ) ;
F_91 ( V_111 ) ;
F_92 ( V_111 ) ;
if ( ! F_81 ( V_111 , V_115 ) ) {
( void ) F_72 ( V_20 , NULL ) ;
F_84 ( V_20 , false ) ;
}
V_20 -> V_123 = false ;
F_93 ( V_111 ) ;
F_89 ( V_111 ) ;
}
static bool F_94 ( struct V_46 * V_20 )
{
struct V_110 * V_111 = & V_20 -> V_111 ;
if ( ! ( V_111 -> V_120 == V_127 ||
V_111 -> V_120 == V_121 ) )
return true ;
if ( ( V_20 -> V_118 & V_119 ) == V_119 ) {
( void ) F_72 ( V_20 , NULL ) ;
return true ;
}
if ( ( V_111 -> V_128 & V_119 ) != V_119 )
( void ) F_68 ( V_20 , V_119 ) ;
if ( F_81 ( V_111 , V_129 ) && ! ( V_116 -> V_18 & V_130 ) )
F_76 ( V_111 , V_111 -> V_131 ) ;
if ( F_81 ( V_111 , V_115 ) ) {
return true ;
}
F_91 ( V_111 ) ;
F_95 ( & V_20 -> V_124 ,
F_90 ) ;
V_20 -> V_123 = true ;
F_96 ( & V_20 -> V_124 , V_132 ) ;
return false ;
}
void F_97 ( struct V_46 * V_20 )
{
struct V_110 * V_111 = & V_20 -> V_111 ;
bool V_133 = true ;
F_92 ( V_111 ) ;
if ( V_111 -> V_134 == V_135 )
V_133 = F_94 ( V_20 ) ;
F_93 ( V_111 ) ;
if ( V_133 )
F_88 ( V_20 ) ;
}
static int
F_98 ( struct V_110 * V_111 ,
struct V_5 * V_13 )
{
struct V_46 * V_20 = F_99 ( V_111 ) ;
int V_14 ;
int V_136 ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_35 :
V_111 -> V_120 = V_127 ;
V_111 -> V_137 -> V_138 = V_127 ;
F_100 ( V_20 ) ;
V_111 -> V_122 ( V_111 ) ;
break;
case V_139 :
break;
case V_37 :
V_136 = V_140 ;
V_14 = 0 ;
goto V_141;
default:
V_136 = V_142 ;
V_14 = - V_143 ;
goto V_141;
}
return 0 ;
V_141:
F_72 ( V_20 , V_13 ) ;
V_111 -> V_120 = V_144 ;
V_111 -> V_145 = V_136 ;
V_111 -> V_146 ( V_111 ) ;
return V_14 ;
}
static int
F_101 ( struct V_110 * V_111 ,
struct V_5 * V_13 )
{
struct V_46 * V_20 = F_99 ( V_111 ) ;
struct V_47 * V_48 = V_20 -> V_56 ;
int V_14 = 0 ;
switch ( F_16 ( V_13 -> V_16 . V_17 ) ) {
case V_40 :
V_13 -> V_8 = F_75 ( V_13 -> V_16 . V_8 ) ;
V_13 -> V_76 = 0 ;
F_27 ( & V_48 -> V_73 ) ;
F_25 ( V_48 , V_13 ) ;
F_102 ( & V_13 -> V_75 , & V_48 -> V_74 ) ;
F_28 ( & V_48 -> V_73 ) ;
V_111 -> V_147 ( V_111 ) ;
return V_14 ;
case V_42 :
V_111 -> V_148 ( V_111 ) ;
break;
case V_38 :
if ( F_75 ( V_13 -> V_16 . V_18 ) & V_106 )
V_20 -> V_118 |= V_105 ;
if ( F_75 ( V_13 -> V_16 . V_18 ) & V_108 )
V_20 -> V_118 |= V_107 ;
if ( V_20 -> V_118 == V_119 &&
F_51 ( V_20 ) <= 0 )
V_111 -> V_120 = V_121 ;
if ( F_75 ( V_13 -> V_16 . V_18 ) )
V_111 -> V_122 ( V_111 ) ;
break;
case V_37 :
F_84 ( V_20 , true ) ;
break;
default:
V_14 = - V_143 ;
break;
}
F_35 ( V_13 ) ;
return V_14 ;
}
static void
F_103 ( struct V_110 * V_111 ,
struct V_5 * V_13 )
{
struct V_46 * V_20 = F_99 ( V_111 ) ;
if ( F_16 ( V_13 -> V_16 . V_17 ) == V_37 )
F_84 ( V_20 , true ) ;
}
static int
F_104 ( struct V_46 * V_20 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_35 ,
. type = V_77 ,
. V_52 = F_74 ( V_13 -> V_16 . V_9 ) ,
. V_55 = F_75 ( V_13 -> V_16 . V_10 ) ,
. V_19 = true ,
. V_20 = V_20 ,
} ;
return F_19 ( V_20 , & V_7 ) ;
}
static int
F_105 ( struct V_110 * V_111 , struct V_5 * V_13 )
{
struct V_46 * V_20 = F_99 ( V_111 ) ;
struct V_46 * V_149 ;
struct V_110 * V_150 ;
if ( F_16 ( V_13 -> V_16 . V_17 ) != V_34 ) {
F_72 ( V_20 , V_13 ) ;
return - V_143 ;
}
if ( F_106 ( V_111 ) ) {
F_72 ( V_20 , V_13 ) ;
return - V_58 ;
}
V_150 = F_107 ( F_108 ( V_111 ) , NULL , V_111 , V_15 ,
V_111 -> V_134 , 0 ) ;
if ( ! V_150 ) {
F_72 ( V_20 , V_13 ) ;
return - V_58 ;
}
V_111 -> V_151 ++ ;
F_109 ( V_150 , V_152 ) ;
V_150 -> V_120 = V_127 ;
V_149 = F_99 ( V_150 ) ;
F_110 ( & V_149 -> V_50 , F_74 ( V_13 -> V_16 . V_11 ) ,
F_75 ( V_13 -> V_16 . V_12 ) ) ;
F_110 ( & V_149 -> V_53 , F_74 ( V_13 -> V_16 . V_9 ) ,
F_75 ( V_13 -> V_16 . V_10 ) ) ;
F_100 ( V_149 ) ;
F_111 ( V_111 , V_150 ) ;
F_104 ( V_149 , V_13 ) ;
F_93 ( V_150 ) ;
V_111 -> V_147 ( V_111 ) ;
return 0 ;
}
static bool F_112 ( struct V_110 * V_111 ,
struct V_5 * V_13 )
{
struct V_46 * V_20 = F_99 ( V_111 ) ;
struct V_47 * V_48 = V_20 -> V_56 ;
bool V_153 ;
F_27 ( & V_48 -> V_61 ) ;
V_48 -> V_65 = F_75 ( V_13 -> V_16 . V_62 ) ;
V_48 -> V_67 = F_75 ( V_13 -> V_16 . V_60 ) ;
V_153 = F_39 ( V_20 ) ;
F_28 ( & V_48 -> V_61 ) ;
return V_153 ;
}
void F_113 ( struct V_5 * V_13 )
{
struct V_102 V_154 , V_155 ;
struct V_46 * V_20 ;
struct V_110 * V_111 ;
bool V_153 ;
F_110 ( & V_154 , F_74 ( V_13 -> V_16 . V_9 ) ,
F_75 ( V_13 -> V_16 . V_10 ) ) ;
F_110 ( & V_155 , F_74 ( V_13 -> V_16 . V_11 ) ,
F_75 ( V_13 -> V_16 . V_12 ) ) ;
F_114 ( V_154 . V_54 , V_154 . V_51 ,
V_155 . V_54 , V_155 . V_51 ,
F_75 ( V_13 -> V_16 . V_8 ) ,
F_16 ( V_13 -> V_16 . type ) ,
F_16 ( V_13 -> V_16 . V_17 ) ,
F_75 ( V_13 -> V_16 . V_18 ) ,
F_75 ( V_13 -> V_16 . V_62 ) ,
F_75 ( V_13 -> V_16 . V_60 ) ) ;
if ( F_16 ( V_13 -> V_16 . type ) != V_77 ) {
( void ) F_73 ( V_13 ) ;
goto V_156;
}
V_111 = F_115 ( & V_154 , & V_155 ) ;
if ( ! V_111 ) {
V_111 = F_116 ( & V_155 ) ;
if ( ! V_111 ) {
( void ) F_73 ( V_13 ) ;
goto V_156;
}
}
V_20 = F_99 ( V_111 ) ;
V_153 = F_112 ( V_111 , V_13 ) ;
F_92 ( V_111 ) ;
V_20 -> V_50 . V_54 = V_155 . V_54 ;
if ( V_153 )
V_111 -> V_148 ( V_111 ) ;
switch ( V_111 -> V_120 ) {
case V_157 :
F_105 ( V_111 , V_13 ) ;
F_35 ( V_13 ) ;
break;
case V_158 :
F_98 ( V_111 , V_13 ) ;
F_35 ( V_13 ) ;
break;
case V_127 :
F_101 ( V_111 , V_13 ) ;
break;
case V_121 :
F_103 ( V_111 , V_13 ) ;
F_35 ( V_13 ) ;
break;
default:
F_35 ( V_13 ) ;
break;
}
F_93 ( V_111 ) ;
F_89 ( V_111 ) ;
return;
V_156:
F_35 ( V_13 ) ;
}
void F_35 ( struct V_5 * V_13 )
{
F_12 ( V_13 -> V_22 ) ;
F_12 ( V_13 ) ;
}
