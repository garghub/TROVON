int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_3 V_10 = {
. V_11 = V_12
} ;
int V_13 = - V_14 ;
if ( V_6 && V_6 -> F_1 )
return V_6 -> F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_15 & V_16 )
return V_13 ;
F_2 (dev, lower_dev, iter) {
V_13 = F_1 ( V_7 , V_4 ) ;
if ( V_13 )
break;
if ( V_10 . V_11 == V_12 )
V_10 = * V_4 ;
else if ( memcmp ( & V_10 , V_4 , sizeof( * V_4 ) ) )
return - V_17 ;
}
return V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_13 = - V_14 ;
if ( V_6 && V_6 -> V_18 )
return V_6 -> V_18 ( V_2 , V_4 ) ;
if ( V_4 -> V_15 & V_16 )
return V_13 ;
F_2 (dev, lower_dev, iter) {
V_13 = F_3 ( V_7 , V_4 ) ;
if ( V_13 )
break;
}
return V_13 ;
}
static void F_4 ( struct V_19 * V_20 )
{
struct V_21 * V_22 =
F_5 ( V_20 , struct V_21 , V_20 ) ;
int V_13 ;
F_6 () ;
V_13 = V_18 ( V_22 -> V_2 , & V_22 -> V_4 ) ;
if ( V_13 && V_13 != - V_14 )
F_7 ( V_22 -> V_2 , L_1 ,
V_13 , V_22 -> V_4 . V_11 ) ;
F_8 () ;
F_9 ( V_22 -> V_2 ) ;
F_10 ( V_20 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 ;
V_22 = F_12 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
F_13 ( & V_22 -> V_20 , F_4 ) ;
F_14 ( V_2 ) ;
V_22 -> V_2 = V_2 ;
memcpy ( & V_22 -> V_4 , V_4 , sizeof( V_22 -> V_4 ) ) ;
F_15 ( & V_22 -> V_20 ) ;
return 0 ;
}
int V_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 ;
if ( ! F_16 () ) {
return F_11 ( V_2 , V_4 ) ;
}
V_4 -> V_25 = V_26 ;
V_13 = F_3 ( V_2 , V_4 ) ;
if ( V_13 ) {
if ( V_13 != - V_14 ) {
V_4 -> V_25 = V_27 ;
F_3 ( V_2 , V_4 ) ;
}
return V_13 ;
}
V_4 -> V_25 = V_28 ;
V_13 = F_3 ( V_2 , V_4 ) ;
F_17 ( V_13 , L_2 ,
V_2 -> V_29 , V_4 -> V_11 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_13 = - V_14 ;
if ( V_6 && V_6 -> V_32 )
return V_6 -> V_32 ( V_2 , V_31 ) ;
F_2 (dev, lower_dev, iter) {
V_13 = F_18 ( V_7 , V_31 ) ;
if ( V_13 )
break;
}
return V_13 ;
}
int V_32 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
int V_13 ;
F_19 () ;
V_31 -> V_25 = V_26 ;
V_13 = F_18 ( V_2 , V_31 ) ;
if ( V_13 ) {
if ( V_13 != - V_14 ) {
V_31 -> V_25 = V_27 ;
F_18 ( V_2 , V_31 ) ;
}
return V_13 ;
}
V_31 -> V_25 = V_28 ;
V_13 = F_18 ( V_2 , V_31 ) ;
F_17 ( V_13 , L_3 , V_2 -> V_29 , V_31 -> V_11 ) ;
return V_13 ;
}
int F_20 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_13 = - V_14 ;
if ( V_6 && V_6 -> F_20 )
return V_6 -> F_20 ( V_2 , V_31 ) ;
F_2 (dev, lower_dev, iter) {
V_13 = F_20 ( V_7 , V_31 ) ;
if ( V_13 )
break;
}
return V_13 ;
}
int F_21 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_13 = - V_14 ;
if ( V_6 && V_6 -> F_21 )
return V_6 -> F_21 ( V_2 , V_31 ) ;
F_2 (dev, lower_dev, iter) {
V_13 = F_21 ( V_7 , V_31 ) ;
break;
}
return V_13 ;
}
int F_22 ( struct V_33 * V_34 )
{
int V_13 ;
F_23 ( & V_35 ) ;
V_13 = F_24 ( & V_36 , V_34 ) ;
F_25 ( & V_35 ) ;
return V_13 ;
}
int F_26 ( struct V_33 * V_34 )
{
int V_13 ;
F_23 ( & V_35 ) ;
V_13 = F_27 ( & V_36 , V_34 ) ;
F_25 ( & V_35 ) ;
return V_13 ;
}
int F_28 ( unsigned long V_37 , struct V_1 * V_2 ,
struct V_38 * V_39 )
{
int V_13 ;
V_39 -> V_2 = V_2 ;
F_23 ( & V_35 ) ;
V_13 = F_29 ( & V_36 , V_37 , V_39 ) ;
F_25 ( & V_35 ) ;
return V_13 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_42 V_43 ;
V_43 . V_15 = V_41 -> V_15 ;
if ( V_41 -> V_44 == 0 && V_41 -> V_45 == 0 ) {
return 0 ;
} else if ( V_41 -> V_44 == V_41 -> V_45 ) {
V_43 . V_46 = V_41 -> V_44 ;
if ( F_31 ( V_41 -> V_47 , V_48 ,
sizeof( V_43 ) , & V_43 ) )
return - V_49 ;
} else {
V_43 . V_46 = V_41 -> V_44 ;
V_43 . V_15 |= V_50 ;
if ( F_31 ( V_41 -> V_47 , V_48 ,
sizeof( V_43 ) , & V_43 ) )
return - V_49 ;
V_43 . V_46 = V_41 -> V_45 ;
V_43 . V_15 &= ~ V_50 ;
V_43 . V_15 |= V_51 ;
if ( F_31 ( V_41 -> V_47 , V_48 ,
sizeof( V_43 ) , & V_43 ) )
return - V_49 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_40 * V_41 =
F_5 ( V_31 , struct V_40 , V_31 ) ;
struct V_52 * V_53 = & V_41 -> V_31 . V_54 . V_53 ;
int V_13 = 0 ;
if ( V_53 -> V_55 > V_53 -> V_56 )
return - V_57 ;
if ( V_41 -> V_58 & V_59 ) {
V_41 -> V_15 = V_53 -> V_15 ;
for ( V_41 -> V_44 = V_41 -> V_45 = V_53 -> V_55 ;
V_41 -> V_44 <= V_53 -> V_56 ;
V_41 -> V_44 ++ , V_41 -> V_45 ++ ) {
V_13 = F_30 ( V_2 , V_41 ) ;
if ( V_13 )
return V_13 ;
}
} else if ( V_41 -> V_58 & V_60 ) {
if ( V_41 -> V_44 > V_53 -> V_55 &&
V_41 -> V_44 >= V_53 -> V_56 ) {
if ( ( V_41 -> V_44 - 1 ) == V_53 -> V_56 &&
V_41 -> V_15 == V_53 -> V_15 ) {
V_41 -> V_44 = V_53 -> V_55 ;
} else {
V_13 = F_30 ( V_2 , V_41 ) ;
V_41 -> V_15 = V_53 -> V_15 ;
V_41 -> V_44 = V_53 -> V_55 ;
V_41 -> V_45 = V_53 -> V_56 ;
}
} else if ( V_41 -> V_45 <= V_53 -> V_55 &&
V_41 -> V_45 < V_53 -> V_56 ) {
if ( ( V_41 -> V_45 + 1 ) == V_53 -> V_55 &&
V_41 -> V_15 == V_53 -> V_15 ) {
V_41 -> V_45 = V_53 -> V_56 ;
} else {
V_13 = F_30 ( V_2 , V_41 ) ;
V_41 -> V_15 = V_53 -> V_15 ;
V_41 -> V_44 = V_53 -> V_55 ;
V_41 -> V_45 = V_53 -> V_56 ;
}
} else {
V_13 = - V_57 ;
}
}
return V_13 ;
}
static int F_33 ( struct V_61 * V_47 , struct V_1 * V_2 ,
T_1 V_58 )
{
struct V_40 V_41 = {
. V_31 = {
. V_11 = V_62 ,
. V_63 = F_32 ,
} ,
. V_47 = V_47 ,
. V_58 = V_58 ,
} ;
int V_13 = 0 ;
if ( ( V_58 & V_59 ) ||
( V_58 & V_60 ) ) {
V_13 = F_21 ( V_2 , & V_41 . V_31 ) ;
if ( V_13 )
goto V_64;
if ( V_58 & V_60 )
V_13 = F_30 ( V_2 , & V_41 ) ;
}
V_64:
return V_13 == - V_14 ? 0 : V_13 ;
}
int F_34 ( struct V_61 * V_47 , T_1 V_65 , T_1 V_66 ,
struct V_1 * V_2 , T_1 V_58 ,
int V_67 )
{
struct V_3 V_4 = {
. V_11 = V_68 ,
} ;
T_2 V_69 = V_70 ;
T_1 V_71 = V_72 | V_73 ;
int V_13 ;
V_13 = F_1 ( V_2 , & V_4 ) ;
if ( V_13 && V_13 != - V_14 )
return V_13 ;
return F_35 ( V_47 , V_65 , V_66 , V_2 , V_69 ,
V_4 . V_54 . V_74 , V_71 , V_67 ,
V_58 , F_33 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_75 * V_75 ,
unsigned long V_76 )
{
struct V_3 V_4 = {
. V_11 = V_68 ,
} ;
T_3 V_77 = F_37 ( V_75 ) ;
int V_13 ;
V_13 = F_1 ( V_2 , & V_4 ) ;
if ( V_13 )
return V_13 ;
if ( V_77 )
V_4 . V_54 . V_74 |= V_76 ;
else
V_4 . V_54 . V_74 &= ~ V_76 ;
return V_18 ( V_2 , & V_4 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_75 * V_78 )
{
struct V_75 * V_4 ;
int V_79 ;
int V_13 ;
V_13 = F_39 ( V_78 , V_80 ,
V_81 ) ;
if ( V_13 )
return V_13 ;
F_40 (attr, protinfo, rem) {
switch ( F_41 ( V_4 ) ) {
case V_82 :
V_13 = F_36 ( V_2 , V_4 ,
V_72 ) ;
break;
case V_83 :
V_13 = F_36 ( V_2 , V_4 ,
V_73 ) ;
break;
default:
V_13 = - V_14 ;
break;
}
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_75 * V_84 ,
int (* F_43)( struct V_1 * V_2 ,
struct V_30 * V_31 ) )
{
struct V_75 * V_4 ;
struct V_42 * V_43 ;
struct V_30 V_31 = {
. V_11 = V_62 ,
} ;
struct V_52 * V_53 = & V_31 . V_54 . V_53 ;
int V_79 ;
int V_13 ;
F_40 (attr, afspec, rem) {
if ( F_41 ( V_4 ) != V_48 )
continue;
if ( F_44 ( V_4 ) != sizeof( struct V_42 ) )
return - V_57 ;
V_43 = F_45 ( V_4 ) ;
if ( ! V_43 -> V_46 || V_43 -> V_46 >= V_85 )
return - V_57 ;
V_53 -> V_15 = V_43 -> V_15 ;
if ( V_43 -> V_15 & V_50 ) {
if ( V_53 -> V_55 )
return - V_57 ;
V_53 -> V_55 = V_43 -> V_46 ;
} else if ( V_43 -> V_15 & V_51 ) {
if ( ! V_53 -> V_55 )
return - V_57 ;
V_53 -> V_56 = V_43 -> V_46 ;
if ( V_53 -> V_56 <= V_53 -> V_55 )
return - V_57 ;
V_13 = F_43 ( V_2 , & V_31 ) ;
if ( V_13 )
return V_13 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
} else {
if ( V_53 -> V_55 )
return - V_57 ;
V_53 -> V_55 = V_43 -> V_46 ;
V_53 -> V_56 = V_43 -> V_46 ;
V_13 = F_43 ( V_2 , & V_31 ) ;
if ( V_13 )
return V_13 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
}
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_86 * V_87 , T_2 V_15 )
{
struct V_75 * V_78 ;
struct V_75 * V_84 ;
int V_13 = 0 ;
V_78 = F_47 ( V_87 , sizeof( struct V_88 ) ,
V_89 ) ;
if ( V_78 ) {
V_13 = F_38 ( V_2 , V_78 ) ;
if ( V_13 )
return V_13 ;
}
V_84 = F_47 ( V_87 , sizeof( struct V_88 ) ,
V_90 ) ;
if ( V_84 )
V_13 = F_42 ( V_2 , V_84 ,
V_32 ) ;
return V_13 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_86 * V_87 , T_2 V_15 )
{
struct V_75 * V_84 ;
V_84 = F_47 ( V_87 , sizeof( struct V_88 ) ,
V_90 ) ;
if ( V_84 )
return F_42 ( V_2 , V_84 ,
F_20 ) ;
return 0 ;
}
int F_49 ( struct V_91 * V_92 , struct V_75 * V_93 [] ,
struct V_1 * V_2 , const unsigned char * V_94 ,
T_2 V_46 , T_2 V_95 )
{
struct V_30 V_31 = {
. V_11 = V_96 ,
. V_54 . V_97 = {
. V_94 = V_94 ,
. V_46 = V_46 ,
} ,
} ;
return V_32 ( V_2 , & V_31 ) ;
}
int F_50 ( struct V_91 * V_92 , struct V_75 * V_93 [] ,
struct V_1 * V_2 , const unsigned char * V_94 ,
T_2 V_46 )
{
struct V_30 V_31 = {
. V_11 = V_96 ,
. V_54 . V_97 = {
. V_94 = V_94 ,
. V_46 = V_46 ,
} ,
} ;
return F_20 ( V_2 , & V_31 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_98 * V_41 =
F_5 ( V_31 , struct V_98 , V_31 ) ;
T_1 V_99 = F_52 ( V_41 -> V_63 -> V_47 ) . V_99 ;
T_1 V_66 = V_41 -> V_63 -> V_87 -> V_100 ;
struct V_86 * V_87 ;
struct V_91 * V_92 ;
if ( V_41 -> V_101 < V_41 -> V_63 -> args [ 0 ] )
goto V_102;
V_87 = F_53 ( V_41 -> V_47 , V_99 , V_66 , V_103 ,
sizeof( * V_92 ) , V_104 ) ;
if ( ! V_87 )
return - V_49 ;
V_92 = F_54 ( V_87 ) ;
V_92 -> V_105 = V_106 ;
V_92 -> V_107 = 0 ;
V_92 -> V_108 = 0 ;
V_92 -> V_109 = V_110 ;
V_92 -> V_111 = 0 ;
V_92 -> V_112 = V_2 -> V_113 ;
V_92 -> V_114 = V_31 -> V_54 . V_97 . V_114 ;
if ( F_31 ( V_41 -> V_47 , V_115 , V_116 , V_31 -> V_54 . V_97 . V_94 ) )
goto V_117;
if ( V_31 -> V_54 . V_97 . V_46 && F_55 ( V_41 -> V_47 , V_118 , V_31 -> V_54 . V_97 . V_46 ) )
goto V_117;
F_56 ( V_41 -> V_47 , V_87 ) ;
V_102:
V_41 -> V_101 ++ ;
return 0 ;
V_117:
F_57 ( V_41 -> V_47 , V_87 ) ;
return - V_49 ;
}
int F_58 ( struct V_61 * V_47 , struct V_119 * V_63 ,
struct V_1 * V_2 ,
struct V_1 * V_120 , int V_101 )
{
struct V_98 V_41 = {
. V_31 = {
. V_11 = V_96 ,
. V_63 = F_51 ,
} ,
. V_47 = V_47 ,
. V_63 = V_63 ,
. V_101 = V_101 ,
} ;
F_21 ( V_2 , & V_41 . V_31 ) ;
return V_41 . V_101 ;
}
static struct V_1 * F_59 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_7 ;
struct V_1 * V_121 ;
struct V_8 * V_9 ;
if ( V_6 && V_6 -> F_1 )
return V_2 ;
F_2 (dev, lower_dev, iter) {
V_121 = F_59 ( V_7 ) ;
if ( V_121 )
return V_121 ;
}
return NULL ;
}
static struct V_1 * F_60 ( struct V_122 * V_123 )
{
struct V_3 V_4 = {
. V_11 = V_124 ,
} ;
struct V_3 V_125 ;
struct V_1 * V_2 = NULL ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_123 -> V_127 ; V_126 ++ ) {
const struct V_128 * V_129 = & V_123 -> V_128 [ V_126 ] ;
if ( ! V_129 -> V_130 )
return NULL ;
V_2 = F_59 ( V_129 -> V_130 ) ;
if ( ! V_2 )
return NULL ;
if ( F_1 ( V_2 , & V_4 ) )
return NULL ;
if ( V_126 > 0 &&
! F_61 ( & V_125 . V_54 . V_131 , & V_4 . V_54 . V_131 ) )
return NULL ;
V_125 = V_4 ;
}
return V_2 ;
}
int F_62 ( T_1 V_132 , int V_133 , struct V_122 * V_123 ,
T_3 V_134 , T_3 type , T_1 V_67 , T_1 V_135 )
{
struct V_30 V_136 = {
. V_11 = V_137 ,
. V_54 . V_138 = {
. V_132 = V_132 ,
. V_133 = V_133 ,
. V_123 = V_123 ,
. V_134 = V_134 ,
. type = type ,
. V_67 = V_67 ,
. V_135 = V_135 ,
} ,
} ;
struct V_1 * V_2 ;
int V_13 = 0 ;
#ifdef F_63
if ( V_123 -> V_139 -> V_140 . V_141 )
return 0 ;
#endif
if ( V_123 -> V_139 -> V_140 . V_142 )
return 0 ;
V_2 = F_60 ( V_123 ) ;
if ( ! V_2 )
return 0 ;
V_13 = V_32 ( V_2 , & V_136 ) ;
if ( ! V_13 )
V_123 -> V_143 |= V_144 ;
return V_13 == - V_14 ? 0 : V_13 ;
}
int F_64 ( T_1 V_132 , int V_133 , struct V_122 * V_123 ,
T_3 V_134 , T_3 type , T_1 V_135 )
{
struct V_30 V_136 = {
. V_11 = V_137 ,
. V_54 . V_138 = {
. V_132 = V_132 ,
. V_133 = V_133 ,
. V_123 = V_123 ,
. V_134 = V_134 ,
. type = type ,
. V_67 = 0 ,
. V_135 = V_135 ,
} ,
} ;
struct V_1 * V_2 ;
int V_13 = 0 ;
if ( ! ( V_123 -> V_143 & V_144 ) )
return 0 ;
V_2 = F_60 ( V_123 ) ;
if ( ! V_2 )
return 0 ;
V_13 = F_20 ( V_2 , & V_136 ) ;
if ( ! V_13 )
V_123 -> V_143 &= ~ V_144 ;
return V_13 == - V_14 ? 0 : V_13 ;
}
void F_65 ( struct V_122 * V_123 )
{
F_66 ( V_123 -> V_139 ) ;
V_123 -> V_139 -> V_140 . V_142 = true ;
}
static bool F_67 ( struct V_1 * V_145 ,
struct V_1 * V_146 )
{
struct V_3 V_147 = {
. V_11 = V_124 ,
. V_15 = V_16 ,
} ;
struct V_3 V_148 = {
. V_11 = V_124 ,
. V_15 = V_16 ,
} ;
if ( F_1 ( V_145 , & V_147 ) ||
F_1 ( V_146 , & V_148 ) )
return false ;
return F_61 ( & V_147 . V_54 . V_131 , & V_148 . V_54 . V_131 ) ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
struct V_1 * V_149 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
F_2 (group_dev, lower_dev, iter) {
if ( V_7 == V_2 )
continue;
if ( F_67 ( V_2 , V_7 ) )
return V_7 -> V_150 ;
return F_68 ( V_2 , V_7 ) ;
}
return V_2 -> V_113 ;
}
static void F_69 ( struct V_1 * V_149 ,
T_1 V_151 , T_1 * V_152 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
F_2 (group_dev, lower_dev, iter) {
if ( V_7 -> V_150 == V_151 ) {
if ( ! * V_152 )
* V_152 = V_7 -> V_113 ;
V_7 -> V_150 = * V_152 ;
}
F_69 ( V_7 , V_151 , V_152 ) ;
}
}
void F_70 ( struct V_1 * V_2 ,
struct V_1 * V_149 ,
bool V_153 )
{
T_1 V_154 = V_2 -> V_113 ;
T_1 V_152 = 0 ;
if ( V_149 && V_153 ) {
V_154 = F_68 ( V_2 , V_149 ) ;
} else if ( V_149 && ! V_153 ) {
if ( V_2 -> V_150 == V_154 )
F_69 ( V_149 , V_154 ,
& V_152 ) ;
}
V_2 -> V_150 = V_154 ;
}
