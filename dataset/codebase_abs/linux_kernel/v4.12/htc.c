static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
}
static struct V_3 * F_3 ( void * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_4 ( V_7 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( V_4 , 20 ) ;
F_6 ( ( unsigned long ) V_4 -> V_8 & 3 , L_1 ) ;
V_6 = F_7 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_2 , V_9 , L_2 , V_10 , V_4 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_7 ( V_4 ) ;
F_10 ( V_12 -> V_2 -> V_13 , V_6 -> V_14 , V_4 -> V_15 , V_16 ) ;
F_11 ( V_4 , sizeof( struct V_17 ) ) ;
}
static void F_12 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_19 -> V_12 -> V_2 ;
F_8 ( V_2 , V_9 , L_3 , V_10 ,
V_19 -> V_20 , V_4 ) ;
F_9 ( V_19 -> V_12 , V_4 ) ;
if ( ! V_19 -> V_21 . V_22 ) {
F_13 ( V_2 , L_4 , V_19 -> V_20 ) ;
F_14 ( V_4 ) ;
return;
}
V_19 -> V_21 . V_22 ( V_19 -> V_12 -> V_2 , V_4 ) ;
}
static void F_15 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_17 * V_23 ;
V_23 = (struct V_17 * ) V_4 -> V_8 ;
V_23 -> V_20 = V_19 -> V_20 ;
V_23 -> V_15 = F_16 ( V_4 -> V_15 - sizeof( * V_23 ) ) ;
V_23 -> V_24 = 0 ;
V_23 -> V_24 |= V_25 ;
F_17 ( & V_19 -> V_12 -> V_26 ) ;
V_23 -> V_27 = V_19 -> V_27 ++ ;
F_18 ( & V_19 -> V_12 -> V_26 ) ;
}
int F_19 ( struct V_11 * V_12 ,
enum V_28 V_20 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_19 = & V_12 -> V_29 [ V_20 ] ;
struct V_5 * V_6 = F_7 ( V_4 ) ;
struct V_30 V_31 ;
struct V_32 * V_13 = V_12 -> V_2 -> V_13 ;
int V_33 = 0 ;
int V_34 ;
if ( V_12 -> V_2 -> V_35 == V_36 )
return - V_37 ;
if ( V_20 >= V_38 ) {
F_13 ( V_2 , L_5 , V_20 ) ;
return - V_39 ;
}
F_20 ( V_4 , sizeof( struct V_17 ) ) ;
if ( V_19 -> V_40 ) {
V_33 = F_21 ( V_4 -> V_15 , V_12 -> V_41 ) ;
F_17 ( & V_12 -> V_26 ) ;
if ( V_19 -> V_42 < V_33 ) {
F_8 ( V_2 , V_9 ,
L_6 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
V_34 = - V_43 ;
goto V_44;
}
V_19 -> V_42 -= V_33 ;
F_8 ( V_2 , V_9 ,
L_7 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
}
F_15 ( V_19 , V_4 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_14 = F_22 ( V_13 , V_4 -> V_8 , V_4 -> V_15 , V_16 ) ;
V_34 = F_23 ( V_13 , V_6 -> V_14 ) ;
if ( V_34 ) {
V_34 = - V_45 ;
goto V_46;
}
V_31 . V_47 = V_19 -> V_20 ;
V_31 . V_48 = V_4 ;
V_31 . V_49 = V_4 -> V_8 ;
V_31 . V_14 = V_6 -> V_14 ;
V_31 . V_15 = V_4 -> V_15 ;
V_34 = F_24 ( V_12 -> V_2 , V_19 -> V_50 , & V_31 , 1 ) ;
if ( V_34 )
goto V_51;
return 0 ;
V_51:
F_10 ( V_13 , V_6 -> V_14 , V_4 -> V_15 , V_16 ) ;
V_46:
if ( V_19 -> V_40 ) {
F_17 ( & V_12 -> V_26 ) ;
V_19 -> V_42 += V_33 ;
F_8 ( V_2 , V_9 ,
L_8 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
if ( V_19 -> V_21 . V_52 )
V_19 -> V_21 . V_52 ( V_12 -> V_2 ) ;
}
V_44:
F_11 ( V_4 , sizeof( struct V_17 ) ) ;
return V_34 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_5 * V_6 ;
struct V_18 * V_19 ;
if ( F_26 ( ! V_4 ) )
return;
V_6 = F_7 ( V_4 ) ;
V_19 = & V_12 -> V_29 [ V_6 -> V_20 ] ;
F_12 ( V_19 , V_4 ) ;
}
static void
F_27 ( struct V_11 * V_12 ,
const struct V_53 * V_54 ,
int V_15 ,
enum V_28 V_20 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_19 ;
int V_55 , V_56 ;
if ( V_15 % sizeof( * V_54 ) )
F_13 ( V_2 , L_9 , V_15 ) ;
V_56 = V_15 / sizeof( * V_54 ) ;
F_17 ( & V_12 -> V_26 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ , V_54 ++ ) {
if ( V_54 -> V_20 >= V_38 )
break;
V_19 = & V_12 -> V_29 [ V_54 -> V_20 ] ;
V_19 -> V_42 += V_54 -> V_33 ;
F_8 ( V_2 , V_9 , L_10 ,
V_54 -> V_20 , V_54 -> V_33 , V_19 -> V_42 ) ;
if ( V_19 -> V_21 . V_52 ) {
F_18 ( & V_12 -> V_26 ) ;
V_19 -> V_21 . V_52 ( V_12 -> V_2 ) ;
F_17 ( & V_12 -> V_26 ) ;
}
}
F_18 ( & V_12 -> V_26 ) ;
}
static int F_28 ( struct V_11 * V_12 ,
T_1 * V_57 ,
int V_58 ,
enum V_28 V_59 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_60 = 0 ;
struct V_61 * V_62 ;
T_1 * V_63 ;
int V_64 ;
T_2 V_15 ;
V_63 = V_57 ;
V_64 = V_58 ;
while ( V_58 > 0 ) {
V_62 = (struct V_61 * ) V_57 ;
if ( V_58 < sizeof( V_62 -> V_23 ) ) {
V_60 = - V_65 ;
break;
}
if ( V_62 -> V_23 . V_15 > V_58 ) {
F_13 ( V_2 , L_11 ,
V_62 -> V_23 . V_15 ) ;
V_60 = - V_65 ;
break;
}
switch ( V_62 -> V_23 . V_66 ) {
case V_67 :
V_15 = sizeof( struct V_53 ) ;
if ( V_62 -> V_23 . V_15 < V_15 ) {
F_13 ( V_2 , L_12 ) ;
V_60 = - V_65 ;
break;
}
F_27 ( V_12 ,
V_62 -> V_68 ,
V_62 -> V_23 . V_15 ,
V_59 ) ;
break;
default:
F_13 ( V_2 , L_13 ,
V_62 -> V_23 . V_66 , V_62 -> V_23 . V_15 ) ;
break;
}
if ( V_60 )
break;
V_57 += sizeof( V_62 -> V_23 ) + V_62 -> V_23 . V_15 ;
V_58 -= sizeof( V_62 -> V_23 ) + V_62 -> V_23 . V_15 ;
}
if ( V_60 )
F_29 ( V_2 , V_9 , L_14 , L_15 ,
V_63 , V_64 ) ;
return V_60 ;
}
void F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_60 = 0 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_17 * V_23 ;
struct V_18 * V_19 ;
T_3 V_69 ;
T_4 V_70 = 0 ;
T_2 V_71 ;
T_1 V_20 ;
bool V_72 ;
V_23 = (struct V_17 * ) V_4 -> V_8 ;
F_11 ( V_4 , sizeof( * V_23 ) ) ;
V_20 = V_23 -> V_20 ;
if ( V_20 >= V_38 ) {
F_13 ( V_2 , L_16 , V_20 ) ;
F_29 ( V_2 , V_9 , L_17 , L_15 ,
V_23 , sizeof( * V_23 ) ) ;
goto V_73;
}
V_19 = & V_12 -> V_29 [ V_20 ] ;
V_69 = F_31 ( V_23 -> V_15 ) ;
if ( V_69 + sizeof( * V_23 ) > V_74 ) {
F_13 ( V_2 , L_18 ,
V_69 + sizeof( * V_23 ) ) ;
F_29 ( V_2 , V_9 , L_19 , L_15 ,
V_23 , sizeof( * V_23 ) ) ;
goto V_73;
}
if ( V_4 -> V_15 < V_69 ) {
F_8 ( V_2 , V_9 ,
L_20 ,
V_4 -> V_15 , V_69 ) ;
F_29 ( V_2 , V_9 , L_19 ,
L_15 , V_23 , sizeof( * V_23 ) ) ;
goto V_73;
}
V_72 = V_23 -> V_24 & V_75 ;
if ( V_72 ) {
T_1 * V_76 ;
V_70 = V_23 -> V_70 ;
V_71 = sizeof( struct V_77 ) ;
if ( ( V_70 < V_71 ) ||
( V_70 > V_69 ) ) {
F_13 ( V_2 , L_21 ,
V_70 ) ;
goto V_73;
}
V_76 = ( T_1 * ) V_23 ;
V_76 += sizeof( * V_23 ) ;
V_76 += V_69 ;
V_76 -= V_70 ;
V_60 = F_28 ( V_12 , V_76 ,
V_70 , V_23 -> V_20 ) ;
if ( V_60 )
goto V_73;
F_32 ( V_4 , V_4 -> V_15 - V_70 ) ;
}
if ( ( ( int ) V_69 - ( int ) V_70 ) <= 0 )
goto V_73;
if ( V_20 == V_78 ) {
struct V_79 * V_80 = (struct V_79 * ) V_4 -> V_8 ;
switch ( F_31 ( V_80 -> V_23 . V_81 ) ) {
case V_82 :
case V_83 :
if ( F_33 ( & V_12 -> V_84 ) ) {
F_13 ( V_2 , L_22 ) ;
F_34 ( & V_12 -> V_84 ) ;
goto V_73;
}
V_12 -> V_85 =
F_35 ( int , V_4 -> V_15 ,
V_86 ) ;
memcpy ( V_12 -> V_87 , V_4 -> V_8 ,
V_12 -> V_85 ) ;
F_34 ( & V_12 -> V_84 ) ;
break;
case V_88 :
V_12 -> V_89 . V_90 ( V_2 ) ;
break;
default:
F_13 ( V_2 , L_23 ) ;
break;
}
goto V_73;
}
F_8 ( V_2 , V_9 , L_24 ,
V_20 , V_4 ) ;
V_19 -> V_21 . V_91 ( V_2 , V_4 ) ;
V_4 = NULL ;
V_73:
F_2 ( V_4 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_13 ( V_2 , L_25 ) ;
F_2 ( V_4 ) ;
}
static const char * F_37 ( enum V_92 V_66 )
{
switch ( V_66 ) {
case V_93 :
return L_26 ;
case V_94 :
return L_27 ;
case V_95 :
return L_28 ;
case V_96 :
return L_29 ;
case V_97 :
return L_30 ;
case V_98 :
return L_31 ;
case V_99 :
return L_32 ;
case V_100 :
return L_33 ;
case V_101 :
return L_34 ;
case V_102 :
return L_35 ;
case V_103 :
return L_36 ;
}
return L_37 ;
}
static void F_38 ( struct V_11 * V_12 )
{
struct V_18 * V_19 ;
int V_55 ;
for ( V_55 = V_78 ; V_55 < V_38 ; V_55 ++ ) {
V_19 = & V_12 -> V_29 [ V_55 ] ;
V_19 -> V_104 = V_105 ;
V_19 -> V_106 = 0 ;
V_19 -> V_107 = 0 ;
V_19 -> V_20 = V_55 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_40 = true ;
}
}
static T_1 F_39 ( struct V_11 * V_12 ,
T_3 V_104 )
{
T_1 V_108 = 0 ;
if ( V_104 == V_95 )
V_108 = V_12 -> V_109 ;
return V_108 ;
}
int F_40 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_55 , V_60 = 0 ;
unsigned long V_110 ;
struct V_111 V_112 ;
struct V_113 V_114 ;
struct V_79 * V_80 ;
T_3 V_81 ;
T_3 V_115 ;
T_3 V_116 ;
V_110 = F_41 ( & V_12 -> V_84 ,
V_117 ) ;
if ( ! V_110 ) {
F_13 ( V_2 , L_38 ) ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ )
F_42 ( V_12 -> V_2 , V_55 , 1 ) ;
V_110 =
F_41 ( & V_12 -> V_84 ,
V_117 ) ;
if ( ! V_110 )
V_60 = - V_119 ;
}
if ( V_60 < 0 ) {
F_43 ( V_2 , L_39 , V_60 ) ;
return V_60 ;
}
if ( V_12 -> V_85 < sizeof( V_80 -> V_23 ) + sizeof( V_80 -> V_120 ) ) {
F_43 ( V_2 , L_40 ,
V_12 -> V_85 ) ;
return - V_37 ;
}
V_80 = (struct V_79 * ) V_12 -> V_87 ;
V_81 = F_31 ( V_80 -> V_23 . V_81 ) ;
V_115 = F_31 ( V_80 -> V_120 . V_115 ) ;
V_116 = F_31 ( V_80 -> V_120 . V_116 ) ;
if ( V_81 != V_82 ) {
F_43 ( V_2 , L_41 , V_81 ) ;
return - V_37 ;
}
V_12 -> V_109 = V_115 ;
V_12 -> V_41 = V_116 ;
F_8 ( V_2 , V_9 ,
L_42 ,
V_12 -> V_109 ,
V_12 -> V_41 ) ;
if ( ( V_12 -> V_109 == 0 ) ||
( V_12 -> V_41 == 0 ) ) {
F_43 ( V_2 , L_43 ) ;
return - V_37 ;
}
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_112 . V_21 . V_22 = F_1 ;
V_112 . V_21 . V_91 = F_36 ;
V_112 . V_121 = V_122 ;
V_112 . V_104 = V_94 ;
V_60 = F_44 ( V_12 , & V_112 , & V_114 ) ;
if ( V_60 ) {
F_43 ( V_2 , L_44 ,
V_60 ) ;
return V_60 ;
}
return 0 ;
}
int F_44 ( struct V_11 * V_12 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_79 * V_80 ;
struct V_123 * V_124 ;
struct V_125 V_126 ;
struct V_125 * V_127 = & V_126 ;
enum V_28 V_128 = V_38 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_129 = 0 ;
int V_58 , V_60 ;
unsigned long V_110 ;
bool V_130 = false ;
T_3 V_81 , V_104 , V_24 = 0 ;
T_1 V_131 = 0 ;
if ( V_112 -> V_104 == V_94 ) {
V_130 = true ;
V_128 = V_78 ;
V_129 = V_86 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
goto V_132;
}
V_131 = F_39 ( V_12 ,
V_112 -> V_104 ) ;
if ( ! V_131 )
F_8 ( V_2 , V_133 ,
L_45 ,
F_37 ( V_112 -> V_104 ) ) ;
V_4 = F_3 ( V_12 -> V_2 ) ;
if ( ! V_4 ) {
F_43 ( V_2 , L_46 ) ;
return - V_134 ;
}
V_58 = sizeof( V_80 -> V_23 ) + sizeof( V_80 -> V_135 ) ;
F_45 ( V_4 , V_58 ) ;
memset ( V_4 -> V_8 , 0 , V_58 ) ;
V_80 = (struct V_79 * ) V_4 -> V_8 ;
V_80 -> V_23 . V_81 =
F_16 ( V_136 ) ;
V_24 |= F_46 ( V_131 , V_137 ) ;
if ( V_112 -> V_104 != V_95 ) {
V_24 |= V_138 ;
V_130 = true ;
}
V_124 = & V_80 -> V_135 ;
V_124 -> V_24 = F_16 ( V_24 ) ;
V_124 -> V_104 = F_16 ( V_112 -> V_104 ) ;
F_47 ( & V_12 -> V_84 ) ;
V_60 = F_19 ( V_12 , V_78 , V_4 ) ;
if ( V_60 ) {
F_2 ( V_4 ) ;
return V_60 ;
}
V_110 = F_41 ( & V_12 -> V_84 ,
V_139 ) ;
if ( ! V_110 ) {
F_43 ( V_2 , L_47 ) ;
return - V_119 ;
}
V_80 = (struct V_79 * ) V_12 -> V_87 ;
V_127 = & V_80 -> V_140 ;
V_81 = F_31 ( V_80 -> V_23 . V_81 ) ;
V_104 = F_31 ( V_127 -> V_104 ) ;
if ( ( V_81 != V_83 ) ||
( V_12 -> V_85 < sizeof( V_80 -> V_23 ) +
sizeof( V_80 -> V_140 ) ) ) {
F_43 ( V_2 , L_48 , V_81 ) ;
return - V_141 ;
}
F_8 ( V_2 , V_9 ,
L_49 ,
F_37 ( V_104 ) ,
V_127 -> V_60 , V_127 -> V_20 ) ;
V_114 -> V_142 = V_127 -> V_60 ;
if ( V_127 -> V_60 != V_143 ) {
F_43 ( V_2 , L_50 ,
F_37 ( V_104 ) ,
V_127 -> V_60 ) ;
return - V_141 ;
}
V_128 = (enum V_28 ) V_127 -> V_20 ;
V_129 = F_31 ( V_127 -> V_129 ) ;
V_132:
if ( V_128 >= V_38 )
return - V_141 ;
if ( V_129 == 0 )
return - V_141 ;
V_19 = & V_12 -> V_29 [ V_128 ] ;
V_19 -> V_20 = V_128 ;
if ( V_19 -> V_104 != V_105 )
return - V_141 ;
V_114 -> V_20 = V_128 ;
V_114 -> V_144 = F_31 ( V_127 -> V_129 ) ;
V_19 -> V_104 = V_112 -> V_104 ;
V_19 -> V_107 = V_112 -> V_121 ;
V_19 -> V_106 = F_31 ( V_127 -> V_129 ) ;
V_19 -> V_42 = V_131 ;
V_19 -> V_21 = V_112 -> V_21 ;
V_60 = F_48 ( V_12 -> V_2 ,
V_19 -> V_104 ,
& V_19 -> V_50 ,
& V_19 -> V_145 ) ;
if ( V_60 )
return V_60 ;
F_8 ( V_2 , V_133 ,
L_51 ,
F_37 ( V_19 -> V_104 ) , V_19 -> V_50 ,
V_19 -> V_145 , V_19 -> V_20 ) ;
if ( V_130 && V_19 -> V_40 ) {
V_19 -> V_40 = false ;
F_8 ( V_2 , V_133 ,
L_52 ,
F_37 ( V_19 -> V_104 ) , V_128 ) ;
}
return V_60 ;
}
struct V_3 * F_49 ( struct V_1 * V_2 , int V_146 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( V_146 + sizeof( struct V_17 ) ) ;
if ( ! V_4 )
return NULL ;
F_5 ( V_4 , sizeof( struct V_17 ) ) ;
if ( ! F_50 ( ( unsigned long ) V_4 -> V_8 , 4 ) )
F_13 ( V_2 , L_53 ) ;
return V_4 ;
}
int F_51 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_60 = 0 ;
struct V_79 * V_80 ;
V_4 = F_3 ( V_12 -> V_2 ) ;
if ( ! V_4 )
return - V_134 ;
F_45 ( V_4 , sizeof( V_80 -> V_23 ) + sizeof( V_80 -> V_147 ) ) ;
memset ( V_4 -> V_8 , 0 , V_4 -> V_15 ) ;
V_80 = (struct V_79 * ) V_4 -> V_8 ;
V_80 -> V_23 . V_81 =
F_16 ( V_148 ) ;
F_8 ( V_2 , V_9 , L_54 ) ;
V_60 = F_19 ( V_12 , V_78 , V_4 ) ;
if ( V_60 ) {
F_2 ( V_4 ) ;
return V_60 ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = NULL ;
struct V_11 * V_12 = & V_2 -> V_12 ;
F_53 ( & V_12 -> V_26 ) ;
F_38 ( V_12 ) ;
V_12 -> V_2 = V_2 ;
V_19 = & V_12 -> V_29 [ V_78 ] ;
F_54 ( V_2 , & V_19 -> V_50 , & V_19 -> V_145 ) ;
F_55 ( & V_12 -> V_84 ) ;
return 0 ;
}
