static const struct V_1 * F_1 ( void )
{
const struct V_2 * V_3 = F_2 () ;
return F_3 ( V_3 , struct V_1 , V_4 ) ;
}
struct V_5 *
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
if ( V_7 -> V_20 && V_8 > 0 ) {
V_13 -> V_21 = F_9 ( V_8 , V_15 ) ;
if ( ! V_13 -> V_21 )
goto V_22;
V_14 = F_10 ( V_13 -> V_21 , V_7 -> V_20 , V_8 ) ;
if ( V_14 )
goto V_23;
}
F_11 ( V_9 , V_10 ,
V_11 , V_12 ,
V_8 ,
V_7 -> type ,
V_7 -> V_17 ,
V_7 -> V_18 ) ;
return V_13 ;
V_23:
F_12 ( V_13 -> V_21 ) ;
V_22:
F_12 ( V_13 ) ;
return NULL ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_6 * V_7 )
{
T_2 V_9 , V_10 , V_11 , V_12 ;
struct V_26 * V_27 ;
struct V_5 * V_13 ;
T_2 V_28 = V_7 -> V_28 ;
V_9 = F_14 () ;
V_10 = V_25 -> V_29 . V_30 ;
if ( ! V_7 -> V_31 ) {
V_11 = V_25 -> V_32 . V_33 ;
V_12 = V_25 -> V_32 . V_30 ;
} else {
V_11 = V_7 -> V_31 ;
V_12 = V_7 -> V_34 ;
}
V_27 = V_25 -> V_35 ;
if ( V_28 > V_36 )
V_28 = V_36 ;
V_28 = F_15 ( V_27 , V_28 ) ;
if ( V_28 == 0 && V_7 -> V_17 == V_37 )
return V_28 ;
V_13 = F_4 ( V_7 , V_28 ,
V_9 , V_10 ,
V_11 , V_12 ) ;
if ( ! V_13 ) {
F_16 ( V_27 , V_28 ) ;
return - V_38 ;
}
F_17 ( V_27 , V_13 ) ;
return F_1 () -> F_18 ( V_13 ) ;
}
static void F_19 ( struct V_26 * V_27 ,
struct V_5 * V_13 )
{
V_27 -> V_39 += V_13 -> V_8 ;
}
static void F_20 ( struct V_26 * V_27 ,
struct V_5 * V_13 )
{
V_27 -> V_39 -= V_13 -> V_8 ;
V_27 -> V_40 += V_13 -> V_8 ;
}
void F_17 ( struct V_26 * V_27 , struct V_5 * V_13 )
{
F_21 ( & V_27 -> V_41 ) ;
V_13 -> V_16 . V_40 = F_8 ( V_27 -> V_40 ) ;
V_13 -> V_16 . V_42 = F_8 ( V_27 -> V_42 ) ;
F_22 ( & V_27 -> V_41 ) ;
}
T_2 F_15 ( struct V_26 * V_27 , T_2 V_43 )
{
T_2 V_44 ;
F_21 ( & V_27 -> V_41 ) ;
V_44 = V_27 -> V_45 - ( V_27 -> V_46 - V_27 -> V_47 ) ;
if ( V_44 > V_43 )
V_44 = V_43 ;
V_27 -> V_46 += V_44 ;
F_22 ( & V_27 -> V_41 ) ;
return V_44 ;
}
void F_16 ( struct V_26 * V_27 , T_2 V_43 )
{
F_21 ( & V_27 -> V_41 ) ;
V_27 -> V_46 -= V_43 ;
F_22 ( & V_27 -> V_41 ) ;
}
static int F_23 ( struct V_24 * V_25 ,
int type ,
struct V_48 * V_16 )
{
struct V_6 V_7 = {
. V_17 = V_49 ,
. type = type ,
} ;
return F_13 ( V_25 , & V_7 ) ;
}
static T_3
F_24 ( struct V_24 * V_25 ,
struct V_50 * V_20 ,
T_1 V_8 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
struct V_5 * V_13 ;
T_1 V_51 , V_52 = 0 ;
int V_14 = - V_53 ;
F_21 ( & V_27 -> V_54 ) ;
while ( V_52 < V_8 && ! F_25 ( & V_27 -> V_55 ) ) {
V_13 = F_26 ( & V_27 -> V_55 ,
struct V_5 , V_56 ) ;
V_51 = V_8 - V_52 ;
if ( V_51 > V_13 -> V_8 - V_13 -> V_57 )
V_51 = V_13 -> V_8 - V_13 -> V_57 ;
F_22 ( & V_27 -> V_54 ) ;
V_14 = F_27 ( V_20 , V_13 -> V_21 + V_13 -> V_57 , V_51 ) ;
if ( V_14 )
goto V_23;
F_21 ( & V_27 -> V_54 ) ;
V_52 += V_51 ;
V_13 -> V_57 += V_51 ;
if ( V_13 -> V_57 == V_13 -> V_8 ) {
F_20 ( V_27 , V_13 ) ;
F_28 ( & V_13 -> V_56 ) ;
F_29 ( V_13 ) ;
}
}
F_22 ( & V_27 -> V_54 ) ;
F_23 ( V_25 , V_58 ,
NULL ) ;
return V_52 ;
V_23:
if ( V_52 )
V_14 = V_52 ;
return V_14 ;
}
T_3
F_30 ( struct V_24 * V_25 ,
struct V_50 * V_20 ,
T_1 V_8 , int V_18 )
{
if ( V_18 & V_59 )
return - V_60 ;
return F_24 ( V_25 , V_20 , V_8 ) ;
}
int
F_31 ( struct V_24 * V_25 ,
struct V_50 * V_20 ,
T_1 V_8 , int V_18 )
{
return - V_60 ;
}
T_4 F_32 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
T_4 V_51 ;
F_21 ( & V_27 -> V_54 ) ;
V_51 = V_27 -> V_39 ;
F_22 ( & V_27 -> V_54 ) ;
return V_51 ;
}
static T_4 F_33 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
T_4 V_51 ;
V_51 = V_27 -> V_45 - ( V_27 -> V_46 - V_27 -> V_47 ) ;
if ( V_51 < 0 )
V_51 = 0 ;
return V_51 ;
}
T_4 F_34 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
T_4 V_51 ;
F_21 ( & V_27 -> V_41 ) ;
V_51 = F_33 ( V_25 ) ;
F_22 ( & V_27 -> V_41 ) ;
return V_51 ;
}
int F_35 ( struct V_24 * V_25 ,
struct V_24 * V_61 )
{
struct V_26 * V_27 ;
V_27 = F_5 ( sizeof( * V_27 ) , V_15 ) ;
if ( ! V_27 )
return - V_38 ;
V_25 -> V_35 = V_27 ;
V_27 -> V_25 = V_25 ;
if ( V_61 ) {
struct V_26 * V_62 = V_61 -> V_35 ;
V_27 -> V_63 = V_62 -> V_63 ;
V_27 -> V_64 = V_62 -> V_64 ;
V_27 -> V_65 = V_62 -> V_65 ;
V_27 -> V_45 = V_62 -> V_45 ;
} else {
V_27 -> V_63 = V_66 ;
V_27 -> V_64 = V_67 ;
V_27 -> V_65 = V_68 ;
}
V_27 -> V_42 = V_27 -> V_63 ;
F_36 ( & V_27 -> V_54 ) ;
F_36 ( & V_27 -> V_41 ) ;
F_37 ( & V_27 -> V_55 ) ;
return 0 ;
}
T_5 F_38 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
return V_27 -> V_63 ;
}
T_5 F_39 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
return V_27 -> V_64 ;
}
T_5 F_40 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
return V_27 -> V_65 ;
}
void F_41 ( struct V_24 * V_25 , T_5 V_69 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
if ( V_69 > V_70 )
V_69 = V_70 ;
if ( V_69 < V_27 -> V_64 )
V_27 -> V_64 = V_69 ;
if ( V_69 > V_27 -> V_65 )
V_27 -> V_65 = V_69 ;
V_27 -> V_63 = V_69 ;
V_27 -> V_42 = V_69 ;
}
void F_42 ( struct V_24 * V_25 , T_5 V_69 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
if ( V_69 > V_70 )
V_69 = V_70 ;
if ( V_69 > V_27 -> V_63 )
V_27 -> V_63 = V_69 ;
V_27 -> V_64 = V_69 ;
}
void F_43 ( struct V_24 * V_25 , T_5 V_69 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
if ( V_69 > V_70 )
V_69 = V_70 ;
if ( V_69 < V_27 -> V_63 )
V_27 -> V_63 = V_69 ;
V_27 -> V_65 = V_69 ;
}
int
F_44 ( struct V_24 * V_25 ,
T_1 V_71 ,
bool * V_72 )
{
if ( F_45 ( V_25 ) )
* V_72 = true ;
else
* V_72 = false ;
return 0 ;
}
int
F_46 ( struct V_24 * V_25 ,
T_1 V_71 ,
bool * V_73 )
{
T_4 V_74 ;
V_74 = F_47 ( V_25 ) ;
if ( V_74 > 0 )
* V_73 = true ;
else if ( V_74 == 0 )
* V_73 = false ;
return 0 ;
}
int F_48 ( struct V_24 * V_25 ,
T_1 V_71 , struct V_75 * V_76 )
{
return 0 ;
}
int F_49 ( struct V_24 * V_25 ,
T_1 V_71 , struct V_75 * V_76 )
{
return 0 ;
}
int F_50 ( struct V_24 * V_25 ,
T_1 V_71 , struct V_75 * V_76 )
{
return 0 ;
}
int F_51 ( struct V_24 * V_25 ,
T_1 V_71 , T_3 V_77 , bool V_78 ,
struct V_75 * V_76 )
{
return 0 ;
}
int F_52 ( struct V_24 * V_25 ,
struct V_79 * V_76 )
{
return 0 ;
}
int F_53 ( struct V_24 * V_25 ,
struct V_79 * V_76 )
{
return 0 ;
}
int F_54 ( struct V_24 * V_25 ,
struct V_79 * V_76 )
{
return 0 ;
}
int F_55 ( struct V_24 * V_25 ,
T_3 V_80 , struct V_79 * V_76 )
{
return 0 ;
}
T_5 F_56 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
return V_27 -> V_63 ;
}
bool F_57 ( struct V_24 * V_25 )
{
return true ;
}
bool F_58 ( T_2 V_81 , T_2 V_82 )
{
return true ;
}
int F_59 ( struct V_24 * V_25 ,
struct V_83 * V_84 )
{
return - V_60 ;
}
bool F_60 ( T_2 V_81 , T_2 V_82 )
{
return false ;
}
int F_61 ( struct V_24 * V_25 )
{
struct V_6 V_7 = {
. V_17 = V_85 ,
. type = V_58 ,
} ;
return F_13 ( V_25 , & V_7 ) ;
}
int F_62 ( struct V_24 * V_25 , int V_86 )
{
struct V_6 V_7 = {
. V_17 = V_87 ,
. type = V_58 ,
. V_18 = ( V_86 & V_88 ?
V_89 : 0 ) |
( V_86 & V_90 ?
V_91 : 0 ) ,
} ;
return F_13 ( V_25 , & V_7 ) ;
}
int
F_63 ( struct V_24 * V_25 ,
struct V_83 * V_32 ,
struct V_50 * V_20 ,
T_1 V_92 )
{
return - V_60 ;
}
T_3
F_64 ( struct V_24 * V_25 ,
struct V_50 * V_20 ,
T_1 V_8 )
{
struct V_6 V_7 = {
. V_17 = V_37 ,
. type = V_58 ,
. V_20 = V_20 ,
. V_28 = V_8 ,
} ;
return F_13 ( V_25 , & V_7 ) ;
}
void F_65 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_35 ;
F_12 ( V_27 ) ;
}
static int F_66 ( struct V_24 * V_25 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_93 ,
. type = V_58 ,
. V_19 = ! ! V_13 ,
} ;
if ( V_13 && F_67 ( V_13 -> V_16 . V_17 ) == V_93 )
return 0 ;
return F_13 ( V_25 , & V_7 ) ;
}
static int F_68 ( struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_93 ,
. type = F_67 ( V_13 -> V_16 . type ) ,
. V_19 = true ,
} ;
if ( F_67 ( V_13 -> V_16 . V_17 ) == V_93 )
return 0 ;
V_13 = F_4 ( & V_7 , 0 ,
F_69 ( V_13 -> V_16 . V_11 ) ,
F_69 ( V_13 -> V_16 . V_12 ) ,
F_69 ( V_13 -> V_16 . V_9 ) ,
F_69 ( V_13 -> V_16 . V_10 ) ) ;
if ( ! V_13 )
return - V_38 ;
return F_1 () -> F_18 ( V_13 ) ;
}
static void F_70 ( struct V_94 * V_95 , long V_96 )
{
if ( V_96 ) {
F_71 ( V_97 ) ;
do {
F_72 ( F_73 ( V_95 ) , & V_97 ,
V_98 ) ;
if ( F_74 ( V_95 , & V_96 ,
F_75 ( V_95 , V_99 ) ) )
break;
} while ( ! F_76 ( V_100 ) && V_96 );
F_77 ( F_73 ( V_95 ) , & V_97 ) ;
}
}
static void F_78 ( struct V_24 * V_25 ,
bool V_101 )
{
struct V_94 * V_95 = F_79 ( V_25 ) ;
F_80 ( V_95 , V_99 ) ;
V_25 -> V_102 = V_103 ;
if ( F_45 ( V_25 ) <= 0 )
V_95 -> V_104 = V_105 ;
V_95 -> V_106 ( V_95 ) ;
if ( V_25 -> V_107 &&
( ! V_101 || F_81 ( & V_25 -> V_108 ) ) ) {
V_25 -> V_107 = false ;
F_82 ( V_25 ) ;
F_83 ( V_95 ) ;
}
}
static void F_84 ( struct V_109 * V_110 )
{
struct V_24 * V_25 =
F_3 ( V_110 , struct V_24 , V_108 . V_110 ) ;
struct V_94 * V_95 = F_79 ( V_25 ) ;
F_85 ( V_95 ) ;
F_86 ( V_95 ) ;
if ( ! F_75 ( V_95 , V_99 ) ) {
( void ) F_66 ( V_25 , NULL ) ;
F_78 ( V_25 , false ) ;
}
V_25 -> V_107 = false ;
F_87 ( V_95 ) ;
F_83 ( V_95 ) ;
}
static bool F_88 ( struct V_24 * V_25 )
{
struct V_94 * V_95 = & V_25 -> V_95 ;
if ( ! ( V_95 -> V_104 == V_111 ||
V_95 -> V_104 == V_105 ) )
return true ;
if ( ( V_25 -> V_102 & V_103 ) == V_103 ) {
( void ) F_66 ( V_25 , NULL ) ;
return true ;
}
if ( ( V_95 -> V_112 & V_103 ) != V_103 )
( void ) F_62 ( V_25 , V_103 ) ;
if ( F_75 ( V_95 , V_113 ) && ! ( V_100 -> V_18 & V_114 ) )
F_70 ( V_95 , V_95 -> V_115 ) ;
if ( F_75 ( V_95 , V_99 ) ) {
return true ;
}
F_85 ( V_95 ) ;
F_89 ( & V_25 -> V_108 ,
F_84 ) ;
V_25 -> V_107 = true ;
F_90 ( & V_25 -> V_108 , V_116 ) ;
return false ;
}
void F_91 ( struct V_24 * V_25 )
{
struct V_94 * V_95 = & V_25 -> V_95 ;
bool V_117 = true ;
F_86 ( V_95 ) ;
if ( V_95 -> V_118 == V_119 )
V_117 = F_88 ( V_25 ) ;
F_87 ( V_95 ) ;
if ( V_117 )
F_82 ( V_25 ) ;
}
static int
F_92 ( struct V_94 * V_95 ,
struct V_5 * V_13 )
{
struct V_24 * V_25 = F_93 ( V_95 ) ;
int V_14 ;
int V_120 ;
switch ( F_67 ( V_13 -> V_16 . V_17 ) ) {
case V_121 :
V_95 -> V_104 = V_111 ;
V_95 -> V_122 -> V_123 = V_111 ;
F_94 ( V_25 ) ;
V_95 -> V_106 ( V_95 ) ;
break;
case V_124 :
break;
case V_93 :
V_120 = V_125 ;
V_14 = 0 ;
goto V_126;
default:
V_120 = V_127 ;
V_14 = - V_128 ;
goto V_126;
}
return 0 ;
V_126:
F_66 ( V_25 , V_13 ) ;
V_95 -> V_104 = V_129 ;
V_95 -> V_130 = V_120 ;
V_95 -> V_131 ( V_95 ) ;
return V_14 ;
}
static int
F_95 ( struct V_94 * V_95 ,
struct V_5 * V_13 )
{
struct V_24 * V_25 = F_93 ( V_95 ) ;
struct V_26 * V_27 = V_25 -> V_35 ;
int V_14 = 0 ;
switch ( F_67 ( V_13 -> V_16 . V_17 ) ) {
case V_37 :
V_13 -> V_8 = F_69 ( V_13 -> V_16 . V_8 ) ;
V_13 -> V_57 = 0 ;
F_21 ( & V_27 -> V_54 ) ;
F_19 ( V_27 , V_13 ) ;
F_96 ( & V_13 -> V_56 , & V_27 -> V_55 ) ;
F_22 ( & V_27 -> V_54 ) ;
V_95 -> V_132 ( V_95 ) ;
return V_14 ;
case V_49 :
V_95 -> V_133 ( V_95 ) ;
break;
case V_87 :
if ( F_69 ( V_13 -> V_16 . V_18 ) & V_89 )
V_25 -> V_102 |= V_88 ;
if ( F_69 ( V_13 -> V_16 . V_18 ) & V_91 )
V_25 -> V_102 |= V_90 ;
if ( V_25 -> V_102 == V_103 &&
F_45 ( V_25 ) <= 0 )
V_95 -> V_104 = V_105 ;
if ( F_69 ( V_13 -> V_16 . V_18 ) )
V_95 -> V_106 ( V_95 ) ;
break;
case V_93 :
F_78 ( V_25 , true ) ;
break;
default:
V_14 = - V_128 ;
break;
}
F_29 ( V_13 ) ;
return V_14 ;
}
static void
F_97 ( struct V_94 * V_95 ,
struct V_5 * V_13 )
{
struct V_24 * V_25 = F_93 ( V_95 ) ;
if ( F_67 ( V_13 -> V_16 . V_17 ) == V_93 )
F_78 ( V_25 , true ) ;
}
static int
F_98 ( struct V_24 * V_25 ,
struct V_5 * V_13 )
{
struct V_6 V_7 = {
. V_17 = V_121 ,
. type = V_58 ,
. V_31 = F_69 ( V_13 -> V_16 . V_9 ) ,
. V_34 = F_69 ( V_13 -> V_16 . V_10 ) ,
. V_19 = true ,
} ;
return F_13 ( V_25 , & V_7 ) ;
}
static int
F_99 ( struct V_94 * V_95 , struct V_5 * V_13 )
{
struct V_24 * V_25 = F_93 ( V_95 ) ;
struct V_24 * V_134 ;
struct V_94 * V_135 ;
if ( F_67 ( V_13 -> V_16 . V_17 ) != V_85 ) {
F_66 ( V_25 , V_13 ) ;
return - V_128 ;
}
if ( F_100 ( V_95 ) ) {
F_66 ( V_25 , V_13 ) ;
return - V_38 ;
}
V_135 = F_101 ( F_102 ( V_95 ) , NULL , V_95 , V_15 ,
V_95 -> V_118 , 0 ) ;
if ( ! V_135 ) {
F_66 ( V_25 , V_13 ) ;
return - V_38 ;
}
V_95 -> V_136 ++ ;
F_103 ( V_135 , V_137 ) ;
V_135 -> V_104 = V_111 ;
V_134 = F_93 ( V_135 ) ;
F_104 ( & V_134 -> V_29 , F_69 ( V_13 -> V_16 . V_11 ) ,
F_69 ( V_13 -> V_16 . V_12 ) ) ;
F_104 ( & V_134 -> V_32 , F_69 ( V_13 -> V_16 . V_9 ) ,
F_69 ( V_13 -> V_16 . V_10 ) ) ;
F_94 ( V_134 ) ;
F_105 ( V_95 , V_135 ) ;
F_98 ( V_134 , V_13 ) ;
F_87 ( V_135 ) ;
V_95 -> V_132 ( V_95 ) ;
return 0 ;
}
static bool F_106 ( struct V_94 * V_95 ,
struct V_5 * V_13 )
{
struct V_24 * V_25 = F_93 ( V_95 ) ;
struct V_26 * V_27 = V_25 -> V_35 ;
bool V_138 ;
F_21 ( & V_27 -> V_41 ) ;
V_27 -> V_45 = F_69 ( V_13 -> V_16 . V_42 ) ;
V_27 -> V_47 = F_69 ( V_13 -> V_16 . V_40 ) ;
V_138 = F_33 ( V_25 ) ;
F_22 ( & V_27 -> V_41 ) ;
return V_138 ;
}
void F_107 ( struct V_5 * V_13 )
{
struct V_83 V_139 , V_140 ;
struct V_24 * V_25 ;
struct V_94 * V_95 ;
bool V_138 ;
F_104 ( & V_139 , F_69 ( V_13 -> V_16 . V_9 ) ,
F_69 ( V_13 -> V_16 . V_10 ) ) ;
F_104 ( & V_140 , F_69 ( V_13 -> V_16 . V_11 ) ,
F_69 ( V_13 -> V_16 . V_12 ) ) ;
F_108 ( V_139 . V_33 , V_139 . V_30 ,
V_140 . V_33 , V_140 . V_30 ,
F_69 ( V_13 -> V_16 . V_8 ) ,
F_67 ( V_13 -> V_16 . type ) ,
F_67 ( V_13 -> V_16 . V_17 ) ,
F_69 ( V_13 -> V_16 . V_18 ) ,
F_69 ( V_13 -> V_16 . V_42 ) ,
F_69 ( V_13 -> V_16 . V_40 ) ) ;
if ( F_67 ( V_13 -> V_16 . type ) != V_58 ) {
( void ) F_68 ( V_13 ) ;
goto V_141;
}
V_95 = F_109 ( & V_139 , & V_140 ) ;
if ( ! V_95 ) {
V_95 = F_110 ( & V_140 ) ;
if ( ! V_95 ) {
( void ) F_68 ( V_13 ) ;
goto V_141;
}
}
V_25 = F_93 ( V_95 ) ;
V_138 = F_106 ( V_95 , V_13 ) ;
F_86 ( V_95 ) ;
V_25 -> V_29 . V_33 = V_140 . V_33 ;
if ( V_138 )
V_95 -> V_133 ( V_95 ) ;
switch ( V_95 -> V_104 ) {
case V_142 :
F_99 ( V_95 , V_13 ) ;
F_29 ( V_13 ) ;
break;
case V_143 :
F_92 ( V_95 , V_13 ) ;
F_29 ( V_13 ) ;
break;
case V_111 :
F_95 ( V_95 , V_13 ) ;
break;
case V_105 :
F_97 ( V_95 , V_13 ) ;
F_29 ( V_13 ) ;
break;
default:
F_29 ( V_13 ) ;
break;
}
F_87 ( V_95 ) ;
F_83 ( V_95 ) ;
return;
V_141:
F_29 ( V_13 ) ;
}
void F_29 ( struct V_5 * V_13 )
{
F_12 ( V_13 -> V_21 ) ;
F_12 ( V_13 ) ;
}
