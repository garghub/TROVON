static inline void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
F_2 ( V_2 -> V_4 -> V_5 , V_2 -> V_6 , V_3 ) ;
}
static void F_3 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_4 ( V_9 ) ;
}
static struct V_8 * F_5 ( void * V_5 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_6 ( V_12 ) ;
if ( ! V_9 ) {
F_7 ( L_1 ) ;
return NULL ;
}
F_8 ( V_9 , 20 ) ;
F_9 ( ( unsigned long ) V_9 -> V_13 & 3 , L_2 ) ;
V_11 = F_10 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_11 ( V_14 , L_3 , V_15 , V_9 ) ;
return V_9 ;
}
static inline void F_12 ( struct V_16 * V_4 ,
struct V_8 * V_9 )
{
F_13 ( V_4 -> V_5 -> V_17 , V_9 ) ;
F_14 ( V_9 , sizeof( struct V_18 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_11 ( V_14 , L_4 , V_15 ,
V_2 -> V_19 , V_9 ) ;
F_12 ( V_2 -> V_4 , V_9 ) ;
if ( ! V_2 -> V_20 . V_21 ) {
F_7 ( L_5 , V_2 -> V_19 ) ;
F_16 ( V_9 ) ;
return;
}
V_2 -> V_20 . V_21 ( V_2 -> V_4 -> V_5 , V_9 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return false ;
if ( V_2 -> V_23 >= V_2 -> V_24 )
return false ;
F_11 ( V_14 , L_6 ,
V_2 -> V_19 ) ;
return true ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_18 * V_25 ;
V_25 = (struct V_18 * ) V_9 -> V_13 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_19 = V_2 -> V_19 ;
V_25 -> V_26 = F_19 ( V_9 -> V_26 - sizeof( * V_25 ) ) ;
F_20 ( & V_2 -> V_4 -> V_27 ) ;
V_25 -> V_28 = V_2 -> V_28 ++ ;
if ( F_17 ( V_2 ) )
V_25 -> V_29 |= V_30 ;
F_21 ( & V_2 -> V_4 -> V_27 ) ;
}
static int F_22 ( struct V_16 * V_4 ,
struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_31 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
int V_32 ;
F_11 ( V_14 , L_4 , V_15 ,
V_2 -> V_19 , V_9 ) ;
F_18 ( V_2 , V_9 ) ;
V_32 = F_23 ( V_4 -> V_5 -> V_17 , V_9 ) ;
if ( V_32 )
goto V_33;
V_32 = F_24 ( V_4 -> V_5 ,
V_2 -> V_6 ,
V_2 -> V_19 ,
V_9 -> V_26 ,
V_9 ) ;
if ( F_25 ( V_32 ) )
goto V_33;
return 0 ;
V_33:
F_7 ( L_7 , V_32 ) ;
F_20 ( & V_4 -> V_27 ) ;
V_2 -> V_23 += V_31 ;
F_21 ( & V_4 -> V_27 ) ;
if ( V_32 == - V_34 ) {
F_20 ( & V_4 -> V_27 ) ;
F_26 ( & V_2 -> V_35 , V_9 ) ;
F_21 ( & V_4 -> V_27 ) ;
return V_32 ;
}
V_11 -> V_36 = true ;
F_15 ( V_2 , V_9 ) ;
return V_32 ;
}
static struct V_8 * F_27 ( struct V_16 * V_4 ,
struct V_1 * V_2 ,
T_1 * V_31 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_37 ;
int V_38 ;
unsigned int V_39 ;
F_28 ( & V_4 -> V_27 ) ;
V_9 = F_29 ( & V_2 -> V_35 ) ;
if ( ! V_9 )
return NULL ;
V_11 = F_10 ( V_9 ) ;
V_39 = V_9 -> V_26 ;
if ( F_30 ( V_39 <= V_4 -> V_40 ) ) {
V_37 = 1 ;
} else {
V_37 = V_39 / V_4 -> V_40 ;
V_38 = V_39 % V_4 -> V_40 ;
if ( V_38 )
V_37 ++ ;
}
F_11 ( V_14 , L_8 ,
V_37 , V_2 -> V_23 ) ;
if ( V_2 -> V_23 < V_37 ) {
F_26 ( & V_2 -> V_35 , V_9 ) ;
return NULL ;
}
V_2 -> V_23 -= V_37 ;
* V_31 = V_37 ;
return V_9 ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ,
struct V_1 , V_43 ) ;
struct V_16 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
T_1 V_31 = 0 ;
int V_32 ;
while ( true ) {
if ( V_2 -> V_44 )
F_1 ( V_2 , 0 ) ;
F_20 ( & V_4 -> V_27 ) ;
if ( V_2 -> V_22 )
V_9 = F_27 ( V_4 , V_2 ,
& V_31 ) ;
else
V_9 = F_29 ( & V_2 -> V_35 ) ;
F_21 ( & V_4 -> V_27 ) ;
if ( ! V_9 )
break;
V_32 = F_22 ( V_4 , V_2 , V_9 , V_31 ) ;
if ( V_32 == - V_34 )
break;
}
}
int F_33 ( struct V_16 * V_4 ,
enum V_45 V_19 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_4 -> V_46 [ V_19 ] ;
if ( V_19 >= V_47 ) {
F_7 ( L_9 , V_19 ) ;
return - V_48 ;
}
F_34 ( V_9 , sizeof( struct V_18 ) ) ;
F_20 ( & V_4 -> V_27 ) ;
F_35 ( & V_2 -> V_35 , V_9 ) ;
F_21 ( & V_4 -> V_27 ) ;
F_36 ( V_4 -> V_5 -> V_49 , & V_2 -> V_43 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_19 )
{
struct V_16 * V_4 = V_5 -> V_4 ;
struct V_1 * V_2 = & V_4 -> V_46 [ V_19 ] ;
bool V_50 ;
F_15 ( V_2 , V_9 ) ;
F_20 ( & V_4 -> V_27 ) ;
V_50 = V_4 -> V_50 ;
F_21 ( & V_4 -> V_27 ) ;
if ( ! V_2 -> V_22 && ! V_50 )
F_36 ( V_5 -> V_49 , & V_2 -> V_43 ) ;
return 0 ;
}
static void F_38 ( struct V_16 * V_4 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_20 ( & V_4 -> V_27 ) ;
for (; ; ) {
V_9 = F_29 ( & V_2 -> V_35 ) ;
if ( ! V_9 )
break;
V_11 = F_10 ( V_9 ) ;
V_11 -> V_36 = true ;
F_15 ( V_2 , V_9 ) ;
}
F_21 ( & V_4 -> V_27 ) ;
F_39 ( & V_2 -> V_43 ) ;
}
static void
F_40 ( struct V_16 * V_4 ,
const struct V_51 * V_52 ,
int V_26 ,
enum V_45 V_19 )
{
struct V_1 * V_2 ;
int V_53 , V_54 ;
if ( V_26 % sizeof( * V_52 ) )
F_7 ( L_10 , V_26 ) ;
V_54 = V_26 / sizeof( * V_52 ) ;
F_20 ( & V_4 -> V_27 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ , V_52 ++ ) {
if ( V_52 -> V_19 >= V_47 )
break;
F_11 ( V_14 , L_11 ,
V_52 -> V_19 , V_52 -> V_31 ) ;
V_2 = & V_4 -> V_46 [ V_52 -> V_19 ] ;
V_2 -> V_23 += V_52 -> V_31 ;
if ( V_2 -> V_23 && ! F_41 ( & V_2 -> V_35 ) )
F_36 ( V_4 -> V_5 -> V_49 , & V_2 -> V_43 ) ;
}
F_21 ( & V_4 -> V_27 ) ;
}
static int F_42 ( struct V_16 * V_4 ,
T_1 * V_55 ,
int V_56 ,
enum V_45 V_57 )
{
int V_58 = 0 ;
struct V_59 * V_60 ;
T_1 * V_61 ;
int V_62 ;
T_2 V_26 ;
V_61 = V_55 ;
V_62 = V_56 ;
while ( V_56 > 0 ) {
V_60 = (struct V_59 * ) V_55 ;
if ( V_56 < sizeof( V_60 -> V_25 ) ) {
V_58 = - V_63 ;
break;
}
if ( V_60 -> V_25 . V_26 > V_56 ) {
F_7 ( L_12 ,
V_60 -> V_25 . V_26 ) ;
V_58 = - V_63 ;
break;
}
switch ( V_60 -> V_25 . V_64 ) {
case V_65 :
V_26 = sizeof( struct V_51 ) ;
if ( V_60 -> V_25 . V_26 < V_26 ) {
F_7 ( L_13 ) ;
V_58 = - V_63 ;
break;
}
F_40 ( V_4 ,
V_60 -> V_66 ,
V_60 -> V_25 . V_26 ,
V_57 ) ;
break;
default:
F_7 ( L_14 ,
V_60 -> V_25 . V_64 , V_60 -> V_25 . V_26 ) ;
break;
}
if ( V_58 )
break;
V_55 += sizeof( V_60 -> V_25 ) + V_60 -> V_25 . V_26 ;
V_56 -= sizeof( V_60 -> V_25 ) + V_60 -> V_25 . V_26 ;
}
if ( V_58 )
F_43 ( V_14 , L_15 , L_16 ,
V_61 , V_62 ) ;
return V_58 ;
}
static int F_44 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
T_1 V_67 )
{
int V_58 = 0 ;
struct V_16 * V_4 = V_5 -> V_4 ;
struct V_18 * V_25 ;
struct V_1 * V_2 ;
T_3 V_68 ;
T_4 V_69 = 0 ;
T_2 V_70 ;
T_1 V_19 ;
bool V_71 ;
V_25 = (struct V_18 * ) V_9 -> V_13 ;
F_14 ( V_9 , sizeof( * V_25 ) ) ;
V_19 = V_25 -> V_19 ;
if ( V_19 >= V_47 ) {
F_7 ( L_17 , V_19 ) ;
F_43 ( V_14 , L_18 , L_16 ,
V_25 , sizeof( * V_25 ) ) ;
V_58 = - V_63 ;
goto V_72;
}
V_2 = & V_4 -> V_46 [ V_19 ] ;
if ( V_2 -> V_44 )
F_1 ( V_2 , 1 ) ;
V_68 = F_45 ( V_25 -> V_26 ) ;
if ( V_68 + sizeof( * V_25 ) > V_73 ) {
F_7 ( L_19 ,
V_68 + sizeof( * V_25 ) ) ;
F_43 ( V_14 , L_20 , L_16 ,
V_25 , sizeof( * V_25 ) ) ;
V_58 = - V_63 ;
goto V_72;
}
if ( V_9 -> V_26 < V_68 ) {
F_11 ( V_14 ,
L_21 ,
V_9 -> V_26 , V_68 ) ;
F_43 ( V_14 , L_20 ,
L_16 , V_25 , sizeof( * V_25 ) ) ;
V_58 = - V_63 ;
goto V_72;
}
V_71 = V_25 -> V_29 & V_74 ;
if ( V_71 ) {
T_1 * V_75 ;
V_69 = V_25 -> V_69 ;
V_70 = sizeof( struct V_76 ) ;
if ( ( V_69 < V_70 ) ||
( V_69 > V_68 ) ) {
F_7 ( L_22 ,
V_69 ) ;
V_58 = - V_77 ;
goto V_72;
}
V_75 = ( T_1 * ) V_25 ;
V_75 += sizeof( * V_25 ) ;
V_75 += V_68 ;
V_75 -= V_69 ;
V_58 = F_42 ( V_4 , V_75 ,
V_69 , V_25 -> V_19 ) ;
if ( V_58 )
goto V_72;
F_46 ( V_9 , V_9 -> V_26 - V_69 ) ;
}
if ( ( ( int ) V_68 - ( int ) V_69 ) <= 0 )
goto V_72;
if ( V_19 == V_78 ) {
struct V_79 * V_80 = (struct V_79 * ) V_9 -> V_13 ;
switch ( F_45 ( V_80 -> V_25 . V_81 ) ) {
default:
if ( F_47 ( & V_4 -> V_82 ) ) {
F_7 ( L_23 ) ;
V_58 = - V_63 ;
F_48 ( & V_4 -> V_82 ) ;
goto V_72;
}
V_4 -> V_83 =
F_49 ( int , V_9 -> V_26 ,
V_84 ) ;
memcpy ( V_4 -> V_85 , V_9 -> V_13 ,
V_4 -> V_83 ) ;
F_48 ( & V_4 -> V_82 ) ;
break;
case V_86 :
V_4 -> V_87 . V_88 ( V_5 ) ;
}
goto V_72;
}
F_11 ( V_14 , L_24 ,
V_19 , V_9 ) ;
V_2 -> V_20 . V_89 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_72:
F_4 ( V_9 ) ;
return V_58 ;
}
static void F_50 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_7 ( L_25 ) ;
F_4 ( V_9 ) ;
}
static const char * F_51 ( enum V_90 V_64 )
{
switch ( V_64 ) {
case V_91 :
return L_26 ;
case V_92 :
return L_27 ;
case V_93 :
return L_28 ;
case V_94 :
return L_29 ;
case V_95 :
return L_30 ;
case V_96 :
return L_31 ;
case V_97 :
return L_32 ;
case V_98 :
return L_33 ;
case V_99 :
return L_34 ;
case V_100 :
return L_35 ;
case V_101 :
return L_36 ;
}
return L_37 ;
}
static void F_52 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_53 ;
for ( V_53 = V_78 ; V_53 < V_47 ; V_53 ++ ) {
V_2 = & V_4 -> V_46 [ V_53 ] ;
V_2 -> V_102 = V_103 ;
V_2 -> V_104 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_19 = V_53 ;
F_53 ( & V_2 -> V_35 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_22 = true ;
F_54 ( & V_2 -> V_43 , F_31 ) ;
}
}
static void F_55 ( struct V_16 * V_4 )
{
struct V_106 * V_107 ;
V_107 = & V_4 -> V_108 [ 0 ] ;
V_107 ++ ;
V_107 -> V_102 = V_93 ;
V_107 -> V_109 = V_4 -> V_110 ;
}
static T_1 F_56 ( struct V_16 * V_4 ,
T_3 V_102 )
{
T_1 V_111 = 0 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_47 ; V_53 ++ ) {
if ( V_4 -> V_108 [ V_53 ] . V_102 == V_102 )
V_111 =
V_4 -> V_108 [ V_53 ] . V_109 ;
}
return V_111 ;
}
int F_57 ( struct V_16 * V_4 )
{
int V_58 = 0 ;
struct V_112 V_113 ;
struct V_114 V_115 ;
struct V_79 * V_80 ;
T_3 V_81 ;
T_3 V_116 ;
T_3 V_117 ;
F_58 ( V_4 -> V_82 ) ;
V_58 = F_59 ( V_4 -> V_5 ) ;
if ( V_58 ) {
F_60 ( L_38 , V_58 ) ;
goto V_118;
}
V_58 = F_61 ( & V_4 -> V_82 ,
V_119 ) ;
if ( V_58 <= 0 ) {
if ( V_58 == 0 )
V_58 = - V_120 ;
F_60 ( L_39 , V_58 ) ;
goto V_121;
}
if ( V_4 -> V_83 < sizeof( V_80 -> V_25 ) + sizeof( V_80 -> V_122 ) ) {
F_60 ( L_40 ,
V_4 -> V_83 ) ;
V_58 = - V_123 ;
goto V_121;
}
V_80 = (struct V_79 * ) V_4 -> V_85 ;
V_81 = F_45 ( V_80 -> V_25 . V_81 ) ;
V_116 = F_45 ( V_80 -> V_122 . V_116 ) ;
V_117 = F_45 ( V_80 -> V_122 . V_117 ) ;
if ( V_81 != V_124 ) {
F_60 ( L_41 , V_81 ) ;
V_58 = - V_123 ;
goto V_121;
}
V_4 -> V_110 = V_116 ;
V_4 -> V_40 = V_117 ;
F_11 ( V_14 ,
L_42 ,
V_4 -> V_110 ,
V_4 -> V_40 ) ;
if ( ( V_4 -> V_110 == 0 ) ||
( V_4 -> V_40 == 0 ) ) {
V_58 = - V_123 ;
F_60 ( L_43 ) ;
goto V_121;
}
F_55 ( V_4 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_113 . V_20 . V_21 = F_3 ;
V_113 . V_20 . V_89 = F_50 ;
V_113 . V_125 = V_126 ;
V_113 . V_102 = V_92 ;
V_58 = F_62 ( V_4 , & V_113 , & V_115 ) ;
if ( V_58 ) {
F_60 ( L_44 , V_58 ) ;
goto V_121;
}
return 0 ;
V_121:
F_63 ( V_4 -> V_5 ) ;
V_118:
return V_58 ;
}
int F_62 ( struct V_16 * V_4 ,
struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_79 * V_80 ;
struct V_127 * V_128 ;
struct V_129 V_130 ;
struct V_129 * V_131 = & V_130 ;
enum V_45 V_132 = V_47 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_133 = 0 ;
int V_56 , V_58 ;
bool V_134 = false ;
T_3 V_81 , V_102 , V_29 = 0 ;
T_1 V_135 = 0 ;
if ( V_113 -> V_102 == V_92 ) {
V_134 = true ;
V_132 = V_78 ;
V_133 = V_84 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
goto V_136;
}
V_135 = F_56 ( V_4 ,
V_113 -> V_102 ) ;
if ( ! V_135 )
F_7 ( L_45 ,
F_51 ( V_113 -> V_102 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_60 ( L_46 ) ;
return - V_137 ;
}
V_56 = sizeof( V_80 -> V_25 ) + sizeof( V_80 -> V_138 ) ;
F_64 ( V_9 , V_56 ) ;
memset ( V_9 -> V_13 , 0 , V_56 ) ;
V_80 = (struct V_79 * ) V_9 -> V_13 ;
V_80 -> V_25 . V_81 =
F_19 ( V_139 ) ;
V_29 |= F_65 ( V_135 , V_140 ) ;
V_128 = & V_80 -> V_138 ;
V_128 -> V_29 = F_19 ( V_29 ) ;
V_128 -> V_102 = F_19 ( V_113 -> V_102 ) ;
if ( V_113 -> V_102 != V_93 ) {
V_29 |= V_141 ;
V_134 = true ;
}
F_58 ( V_4 -> V_82 ) ;
V_58 = F_33 ( V_4 , V_78 , V_9 ) ;
if ( V_58 ) {
F_4 ( V_9 ) ;
return V_58 ;
}
V_58 = F_61 ( & V_4 -> V_82 ,
V_142 ) ;
if ( V_58 <= 0 ) {
if ( V_58 == 0 )
V_58 = - V_120 ;
F_60 ( L_47 , V_58 ) ;
return V_58 ;
}
V_80 = (struct V_79 * ) V_4 -> V_85 ;
V_131 = & V_80 -> V_143 ;
V_81 = F_45 ( V_80 -> V_25 . V_81 ) ;
V_102 = F_45 ( V_131 -> V_102 ) ;
if ( ( V_81 != V_144 ) ||
( V_4 -> V_83 < sizeof( V_80 -> V_25 ) +
sizeof( V_80 -> V_143 ) ) ) {
F_60 ( L_48 , V_81 ) ;
return - V_77 ;
}
F_11 ( V_14 ,
L_49 ,
F_51 ( V_102 ) ,
V_131 -> V_58 , V_131 -> V_19 ) ;
V_115 -> V_145 = V_131 -> V_58 ;
if ( V_131 -> V_58 != V_146 ) {
F_60 ( L_50 ,
F_51 ( V_102 ) ,
V_131 -> V_58 ) ;
return - V_77 ;
}
V_132 = (enum V_45 ) V_131 -> V_19 ;
V_133 = F_45 ( V_131 -> V_133 ) ;
V_136:
if ( V_132 >= V_47 )
return - V_77 ;
if ( V_133 == 0 )
return - V_77 ;
V_2 = & V_4 -> V_46 [ V_132 ] ;
V_2 -> V_19 = V_132 ;
if ( V_2 -> V_102 != V_103 )
return - V_77 ;
V_115 -> V_19 = V_132 ;
V_115 -> V_147 = F_45 ( V_131 -> V_133 ) ;
V_2 -> V_102 = V_113 -> V_102 ;
V_2 -> V_105 = V_113 -> V_125 ;
V_2 -> V_104 = F_45 ( V_131 -> V_133 ) ;
V_2 -> V_23 = V_135 ;
V_2 -> V_148 = V_4 -> V_40 ;
V_2 -> V_24 = V_2 -> V_104 /
V_4 -> V_40 ;
if ( V_2 -> V_104 % V_4 -> V_40 )
V_2 -> V_24 ++ ;
V_2 -> V_20 = V_113 -> V_20 ;
V_58 = F_66 ( V_4 -> V_5 ,
V_2 -> V_102 ,
& V_2 -> V_6 ,
& V_2 -> V_149 ,
& V_2 -> V_44 ,
& V_2 -> V_150 ) ;
if ( V_58 )
return V_58 ;
F_11 ( V_14 ,
L_51 ,
F_51 ( V_2 -> V_102 ) , V_2 -> V_6 ,
V_2 -> V_149 , V_2 -> V_19 ) ;
F_11 ( V_14 ,
L_52 ,
V_2 -> V_19 , V_2 -> V_44 , V_2 -> V_150 ) ;
if ( V_134 && V_2 -> V_22 ) {
V_2 -> V_22 = false ;
F_11 ( V_14 ,
L_53 ,
F_51 ( V_2 -> V_102 ) , V_132 ) ;
}
return V_58 ;
}
struct V_8 * F_67 ( int V_151 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_151 + sizeof( struct V_18 ) ) ;
if ( ! V_9 ) {
F_7 ( L_54 ) ;
return NULL ;
}
F_8 ( V_9 , sizeof( struct V_18 ) ) ;
if ( ! F_68 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_7 ( L_55 ) ;
return V_9 ;
}
int F_69 ( struct V_16 * V_4 )
{
struct V_8 * V_9 ;
int V_58 = 0 ;
struct V_79 * V_80 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_137 ;
F_64 ( V_9 , sizeof( V_80 -> V_25 ) + sizeof( V_80 -> V_152 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_26 ) ;
V_80 = (struct V_79 * ) V_9 -> V_13 ;
V_80 -> V_25 . V_81 =
F_19 ( V_153 ) ;
F_11 ( V_14 , L_56 ) ;
V_58 = F_33 ( V_4 , V_78 , V_9 ) ;
if ( V_58 ) {
F_4 ( V_9 ) ;
return V_58 ;
}
return 0 ;
}
void F_70 ( struct V_16 * V_4 )
{
int V_53 ;
struct V_1 * V_2 ;
F_20 ( & V_4 -> V_27 ) ;
V_4 -> V_50 = true ;
F_21 ( & V_4 -> V_27 ) ;
for ( V_53 = V_78 ; V_53 < V_47 ; V_53 ++ ) {
V_2 = & V_4 -> V_46 [ V_53 ] ;
F_38 ( V_4 , V_2 ) ;
}
F_63 ( V_4 -> V_5 ) ;
F_52 ( V_4 ) ;
}
struct V_16 * F_71 ( struct V_7 * V_5 ,
struct V_154 * V_87 )
{
struct V_155 V_156 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = NULL ;
V_4 = F_72 ( sizeof( struct V_16 ) , V_157 ) ;
if ( ! V_4 )
return F_73 ( - V_137 ) ;
F_74 ( & V_4 -> V_27 ) ;
memcpy ( & V_4 -> V_87 , V_87 , sizeof( struct V_154 ) ) ;
F_52 ( V_4 ) ;
V_156 . V_158 = F_44 ;
V_156 . V_159 = F_37 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_46 [ V_78 ] ;
F_75 ( V_5 , & V_156 ) ;
F_76 ( V_5 , & V_2 -> V_6 , & V_2 -> V_149 ) ;
F_77 ( & V_4 -> V_82 ) ;
return V_4 ;
}
void F_78 ( struct V_16 * V_4 )
{
F_79 ( V_4 ) ;
}
