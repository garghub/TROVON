T_1 F_1 ( struct V_1 * V_1 , enum V_2 V_3 )
{
return V_1 -> V_4 [ V_3 ] ;
}
void F_2 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
V_1 -> V_4 [ V_3 ] = V_5 ;
}
bool F_3 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
if ( V_5 > F_1 ( V_1 , V_3 ) ) {
F_2 ( V_1 , V_3 , V_5 ) ;
return true ;
}
return false ;
}
void F_4 ( struct V_1 * V_1 )
{
enum V_2 V_3 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_2 ( V_1 , V_3 , 0 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_7 )
{
const unsigned int V_8 = V_9 / 4 ;
if ( F_1 ( V_1 , V_7 ) < V_8 &&
! V_10 . V_11 && ! V_10 . V_12 &&
! V_10 . V_13 )
F_2 ( V_1 , V_7 , V_8 ) ;
}
void F_6 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
const unsigned int V_8 = V_9 / 4 ;
int V_16 ;
T_1 V_5 ;
if ( V_15 -> V_17 . V_18 ) {
V_16 = V_15 -> V_17 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_21 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_21 , V_16 ) ;
F_5 ( V_1 , V_22 ) ;
}
V_5 = F_7 ( V_15 -> V_23 ) ;
if ( F_3 ( V_1 , V_24 , V_5 ) )
F_2 ( V_1 , V_25 , V_5 + 6 ) ;
if ( V_15 -> V_17 . V_26 ) {
V_5 = F_8 ( V_15 -> V_17 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_22 , V_5 ) ;
}
if ( V_15 -> V_27 )
F_3 ( V_1 , V_28 , V_15 -> V_27 -> V_19 ) ;
if ( V_15 -> V_29 ) {
if ( V_15 -> V_29 -> V_30 . V_18 ) {
V_16 = ( int ) V_15 -> V_29 -> V_30 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_31 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_29 -> V_30 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_32 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_31 , V_16 ) ;
F_5 ( V_1 , V_32 ) ;
}
if ( V_15 -> V_29 -> V_33 . V_18 ) {
V_16 = ( int ) V_15 -> V_29 -> V_33 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_34 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_29 -> V_33 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_35 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_34 , V_16 ) ;
F_5 ( V_1 , V_35 ) ;
}
}
if ( V_15 -> V_36 ) {
if ( V_15 -> V_36 -> V_37 . V_18 ) {
V_16 = ( int ) V_15 -> V_36 -> V_37 . V_18 -> V_19 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
F_3 ( V_1 , V_39 ,
V_16 + 1 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
}
if ( V_15 -> V_36 -> V_37 . V_26 ) {
V_16 = F_8 ( V_15 -> V_36 -> V_37 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_40 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_5 ( V_1 , V_40 ) ;
}
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 , V_16 ) ;
F_5 ( V_1 , V_40 ) ;
}
F_3 ( V_1 , V_41 , 6 ) ;
F_3 ( V_1 , V_42 , 22 ) ;
F_3 ( V_1 , V_43 , 12 ) ;
F_3 ( V_1 , V_44 , 21 + 3 ) ;
F_3 ( V_1 , V_45 , 12 ) ;
F_3 ( V_1 , V_46 , 12 ) ;
if ( V_15 -> V_47 )
F_3 ( V_1 , V_48 , strlen ( V_15 -> V_47 ) ) ;
if ( V_15 -> V_49 )
F_3 ( V_1 , V_50 , strlen ( V_15 -> V_49 ) ) ;
if ( V_15 -> V_51 )
F_3 ( V_1 , V_52 ,
F_9 () ) ;
}
void F_10 ( struct V_1 * V_1 , int V_53 )
{
struct V_54 * V_55 = F_11 ( & V_1 -> V_56 ) ;
struct V_14 * V_57 ;
int V_58 = 0 ;
F_4 ( V_1 ) ;
while ( V_55 && V_58 ++ < V_53 ) {
V_57 = F_12 ( V_55 , struct V_14 , V_54 ) ;
if ( ! V_57 -> V_59 )
F_6 ( V_1 , V_57 ) ;
V_55 = F_13 ( & V_57 -> V_54 ) ;
}
}
static void F_14 ( struct V_60 * V_60 ,
unsigned int V_61 , T_2 V_62 )
{
switch ( V_61 ) {
case V_63 :
V_60 -> V_64 += V_62 ;
break;
case V_65 :
V_60 -> V_66 += V_62 ;
break;
case V_67 :
V_60 -> V_68 += V_62 ;
break;
case V_69 :
V_60 -> V_70 += V_62 ;
break;
default:
break;
}
}
static void F_15 ( struct V_60 * V_60 , T_2 V_62 ,
T_2 V_71 )
{
V_60 -> V_62 += V_62 ;
V_60 -> V_71 += V_71 ;
V_60 -> V_72 += 1 ;
}
static void F_16 ( struct V_60 * V_73 , struct V_60 * V_74 )
{
V_73 -> V_62 += V_74 -> V_62 ;
V_73 -> V_64 += V_74 -> V_64 ;
V_73 -> V_66 += V_74 -> V_66 ;
V_73 -> V_68 += V_74 -> V_68 ;
V_73 -> V_70 += V_74 -> V_70 ;
V_73 -> V_72 += V_74 -> V_72 ;
V_73 -> V_71 += V_74 -> V_71 ;
}
static void F_17 ( struct V_60 * V_60 )
{
V_60 -> V_62 = ( V_60 -> V_62 * 7 ) / 8 ;
V_60 -> V_72 = ( V_60 -> V_72 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_75 )
{
T_2 V_76 = V_75 -> V_77 . V_62 ;
T_2 V_78 ;
if ( V_76 == 0 )
return true ;
F_17 ( & V_75 -> V_77 ) ;
if ( V_10 . V_79 )
F_17 ( V_75 -> V_80 ) ;
V_78 = V_76 - V_75 -> V_77 . V_62 ;
V_1 -> V_81 . V_82 -= V_78 ;
if ( ! V_75 -> V_59 )
V_1 -> V_81 . V_83 -= V_78 ;
return V_75 -> V_77 . V_62 == 0 ;
}
static void F_19 ( struct V_1 * V_1 , struct V_14 * V_75 )
{
F_20 ( & V_75 -> V_54 , & V_1 -> V_56 ) ;
if ( V_84 )
F_20 ( & V_75 -> V_85 , & V_1 -> V_86 ) ;
-- V_1 -> V_87 ;
if ( ! V_75 -> V_59 )
-- V_1 -> V_88 ;
F_21 ( V_75 ) ;
}
void F_22 ( struct V_1 * V_1 , bool V_89 , bool V_90 )
{
struct V_54 * V_55 = F_11 ( & V_1 -> V_56 ) ;
struct V_14 * V_57 ;
while ( V_55 ) {
V_57 = F_12 ( V_55 , struct V_14 , V_54 ) ;
V_55 = F_13 ( & V_57 -> V_54 ) ;
if ( ( ( V_89 && V_57 -> V_91 == '.' ) ||
( V_90 && V_57 -> V_91 != '.' ) ||
F_18 ( V_1 , V_57 ) ) ) {
F_19 ( V_1 , V_57 ) ;
}
}
}
void F_23 ( struct V_1 * V_1 )
{
struct V_54 * V_55 = F_11 ( & V_1 -> V_56 ) ;
struct V_14 * V_57 ;
while ( V_55 ) {
V_57 = F_12 ( V_55 , struct V_14 , V_54 ) ;
V_55 = F_13 ( & V_57 -> V_54 ) ;
F_19 ( V_1 , V_57 ) ;
}
}
static struct V_14 * F_24 ( struct V_14 * V_92 ,
bool V_93 )
{
T_3 V_94 = 0 ;
struct V_14 * V_75 ;
if ( V_10 . V_95 )
V_94 = sizeof( struct V_96 ) ;
V_75 = F_25 ( sizeof( * V_75 ) + V_94 ) ;
if ( V_75 != NULL ) {
* V_75 = * V_92 ;
if ( V_10 . V_79 ) {
V_75 -> V_80 = malloc ( sizeof( V_75 -> V_77 ) ) ;
if ( V_75 -> V_80 == NULL ) {
free ( V_75 ) ;
return NULL ;
}
memcpy ( V_75 -> V_80 , & V_75 -> V_77 , sizeof( V_75 -> V_77 ) ) ;
if ( ! V_93 )
memset ( & V_75 -> V_77 , 0 , sizeof( V_75 -> V_77 ) ) ;
}
F_26 ( V_75 -> V_17 . V_26 ) ;
if ( V_75 -> V_29 ) {
V_75 -> V_29 = malloc ( sizeof( * V_75 -> V_29 ) ) ;
if ( V_75 -> V_29 == NULL ) {
F_27 ( V_75 -> V_17 . V_26 ) ;
free ( V_75 -> V_80 ) ;
free ( V_75 ) ;
return NULL ;
}
memcpy ( V_75 -> V_29 , V_92 -> V_29 ,
sizeof( * V_75 -> V_29 ) ) ;
F_26 ( V_75 -> V_29 -> V_30 . V_26 ) ;
F_26 ( V_75 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_75 -> V_36 ) {
F_26 ( V_75 -> V_36 -> V_97 . V_26 ) ;
F_26 ( V_75 -> V_36 -> V_37 . V_26 ) ;
}
if ( V_10 . V_95 )
F_28 ( V_75 -> V_98 ) ;
F_29 ( & V_75 -> V_99 . V_100 ) ;
F_30 ( V_75 -> V_23 ) ;
}
return V_75 ;
}
static T_4 F_31 ( const struct V_101 * V_27 )
{
if ( V_10 . V_102 && V_27 == NULL )
return 1 << V_103 ;
return 0 ;
}
static struct V_14 * F_32 ( struct V_1 * V_1 ,
struct V_14 * V_104 ,
struct V_105 * V_106 ,
bool V_93 )
{
struct V_54 * * V_107 ;
struct V_54 * V_27 = NULL ;
struct V_14 * V_75 ;
T_5 V_108 ;
T_2 V_62 = V_104 -> V_77 . V_62 ;
T_2 V_71 = V_104 -> V_77 . V_71 ;
V_107 = & V_1 -> V_109 -> V_54 ;
while ( * V_107 != NULL ) {
V_27 = * V_107 ;
V_75 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_108 = F_33 ( V_75 , V_104 ) ;
if ( ! V_108 ) {
if ( V_93 )
F_15 ( & V_75 -> V_77 , V_62 , V_71 ) ;
if ( V_10 . V_79 )
F_15 ( V_75 -> V_80 , V_62 , V_71 ) ;
F_34 ( & V_104 -> V_36 ) ;
if ( V_75 -> V_17 . V_26 != V_104 -> V_17 . V_26 ) {
F_35 ( V_75 -> V_17 . V_26 ) ;
V_75 -> V_17 . V_26 = F_26 ( V_104 -> V_17 . V_26 ) ;
}
goto V_110;
}
if ( V_108 < 0 )
V_107 = & ( * V_107 ) -> V_111 ;
else
V_107 = & ( * V_107 ) -> V_112 ;
}
V_75 = F_24 ( V_104 , V_93 ) ;
if ( ! V_75 )
return NULL ;
V_1 -> V_87 ++ ;
F_36 ( & V_75 -> V_85 , V_27 , V_107 ) ;
F_37 ( & V_75 -> V_85 , V_1 -> V_109 ) ;
V_110:
if ( V_93 )
F_14 ( & V_75 -> V_77 , V_106 -> V_61 , V_62 ) ;
if ( V_10 . V_79 )
F_14 ( V_75 -> V_80 , V_106 -> V_61 , V_62 ) ;
return V_75 ;
}
struct V_14 * F_38 ( struct V_1 * V_1 ,
struct V_105 * V_106 ,
struct V_101 * V_113 ,
struct V_29 * V_114 ,
struct V_36 * V_115 ,
T_2 V_62 , T_2 V_71 , T_2 V_51 ,
bool V_93 )
{
struct V_14 V_104 = {
. V_23 = V_106 -> V_23 ,
. V_116 = F_39 ( V_106 -> V_23 ) ,
. V_17 = {
. V_26 = V_106 -> V_26 ,
. V_18 = V_106 -> V_18 ,
} ,
. V_117 = V_106 -> V_117 ,
. V_61 = V_106 -> V_61 ,
. V_118 = V_106 -> V_119 ,
. V_91 = V_106 -> V_91 ,
. V_77 = {
. V_72 = 1 ,
. V_62 = V_62 ,
. V_71 = V_71 ,
} ,
. V_27 = V_113 ,
. V_59 = F_31 ( V_113 ) | V_106 -> V_59 ,
. V_1 = V_1 ,
. V_29 = V_114 ,
. V_36 = V_115 ,
. V_51 = V_51 ,
} ;
return F_32 ( V_1 , & V_104 , V_106 , V_93 ) ;
}
static int
F_40 ( struct V_120 * T_6 V_121 ,
struct V_105 * V_106 V_121 )
{
return 0 ;
}
static int
F_41 ( struct V_120 * T_6 V_121 ,
struct V_105 * V_106 V_121 )
{
return 0 ;
}
static int
F_42 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
struct V_122 * V_123 = T_6 -> V_123 ;
struct V_36 * V_115 ;
V_115 = F_43 ( V_123 , V_106 ) ;
if ( V_115 == NULL )
return - V_124 ;
T_6 -> V_125 = V_115 ;
return 0 ;
}
static int
F_44 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
T_2 V_126 ;
struct V_36 * V_115 = T_6 -> V_125 ;
struct V_1 * V_1 = F_45 ( T_6 -> V_127 ) ;
struct V_14 * V_75 ;
if ( V_115 == NULL )
return - V_128 ;
V_126 = T_6 -> V_123 -> V_71 ;
if ( ! V_126 )
V_126 = 1 ;
V_75 = F_38 ( V_1 , V_106 , T_6 -> V_27 , NULL , V_115 ,
V_126 , V_126 , 0 , true ) ;
if ( ! V_75 )
return - V_124 ;
T_6 -> V_75 = V_75 ;
return 0 ;
}
static int
F_46 ( struct V_120 * T_6 ,
struct V_105 * V_106 V_121 )
{
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_1 * V_1 = F_45 ( V_127 ) ;
struct V_14 * V_75 = T_6 -> V_75 ;
int V_130 = - V_128 ;
if ( V_75 == NULL )
goto V_110;
F_47 ( V_1 , V_75 -> V_59 ) ;
V_130 = F_48 ( V_75 , T_6 -> V_123 ) ;
V_110:
T_6 -> V_125 = NULL ;
T_6 -> V_75 = NULL ;
return V_130 ;
}
static int
F_49 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
struct V_29 * V_114 ;
struct V_122 * V_123 = T_6 -> V_123 ;
V_114 = F_50 ( V_123 , V_106 ) ;
if ( ! V_114 )
return - V_124 ;
T_6 -> V_131 = 0 ;
T_6 -> V_132 = V_123 -> V_133 -> V_134 ;
T_6 -> V_125 = V_114 ;
return 0 ;
}
static int
F_51 ( struct V_120 * T_6 V_121 ,
struct V_105 * V_106 V_121 )
{
T_6 -> V_75 = NULL ;
return 0 ;
}
static int
F_52 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
struct V_29 * V_114 = T_6 -> V_125 ;
int V_135 = T_6 -> V_131 ;
if ( V_114 == NULL )
return 0 ;
if ( T_6 -> V_131 >= T_6 -> V_132 )
return 0 ;
V_106 -> V_26 = V_114 [ V_135 ] . V_33 . V_26 ;
V_106 -> V_18 = V_114 [ V_135 ] . V_33 . V_18 ;
V_106 -> V_119 = V_114 [ V_135 ] . V_33 . V_119 ;
return 1 ;
}
static int
F_53 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
struct V_29 * V_114 ;
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_1 * V_1 = F_45 ( V_127 ) ;
struct V_14 * V_75 = NULL ;
int V_135 = T_6 -> V_131 ;
int V_130 = 0 ;
V_114 = T_6 -> V_125 ;
if ( T_6 -> V_136 && ! ( V_114 [ V_135 ] . V_30 . V_18 && V_114 [ V_135 ] . V_33 . V_18 ) )
goto V_110;
V_75 = F_38 ( V_1 , V_106 , T_6 -> V_27 , & V_114 [ V_135 ] , NULL ,
1 , V_114 -> V_137 . V_138 ? V_114 -> V_137 . V_138 : 1 ,
0 , true ) ;
if ( V_75 == NULL )
return - V_124 ;
F_47 ( V_1 , V_75 -> V_59 ) ;
V_110:
T_6 -> V_75 = V_75 ;
T_6 -> V_131 ++ ;
return V_130 ;
}
static int
F_54 ( struct V_120 * T_6 ,
struct V_105 * V_106 V_121 )
{
F_34 ( & T_6 -> V_125 ) ;
T_6 -> V_75 = NULL ;
return T_6 -> V_131 >= T_6 -> V_132 ? 0 : - 1 ;
}
static int
F_55 ( struct V_120 * T_6 V_121 ,
struct V_105 * V_106 V_121 )
{
return 0 ;
}
static int
F_56 ( struct V_120 * T_6 , struct V_105 * V_106 )
{
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_122 * V_123 = T_6 -> V_123 ;
struct V_14 * V_75 ;
V_75 = F_38 ( F_45 ( V_127 ) , V_106 , T_6 -> V_27 , NULL , NULL ,
V_123 -> V_62 , V_123 -> V_71 ,
V_123 -> V_51 , true ) ;
if ( V_75 == NULL )
return - V_124 ;
T_6 -> V_75 = V_75 ;
return 0 ;
}
static int
F_57 ( struct V_120 * T_6 ,
struct V_105 * V_106 V_121 )
{
struct V_14 * V_75 = T_6 -> V_75 ;
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_122 * V_123 = T_6 -> V_123 ;
if ( V_75 == NULL )
return 0 ;
T_6 -> V_75 = NULL ;
F_47 ( F_45 ( V_127 ) , V_75 -> V_59 ) ;
return F_48 ( V_75 , V_123 ) ;
}
static int
F_58 ( struct V_120 * T_6 V_121 ,
struct V_105 * V_106 V_121 )
{
struct V_14 * * V_139 ;
F_59 ( & V_140 ) ;
V_139 = malloc ( sizeof( * V_139 ) * ( V_141 + 1 ) ) ;
if ( V_139 == NULL )
return - V_124 ;
T_6 -> V_125 = V_139 ;
T_6 -> V_131 = 0 ;
return 0 ;
}
static int
F_60 ( struct V_120 * T_6 ,
struct V_105 * V_106 )
{
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_1 * V_1 = F_45 ( V_127 ) ;
struct V_122 * V_123 = T_6 -> V_123 ;
struct V_14 * * V_139 = T_6 -> V_125 ;
struct V_14 * V_75 ;
int V_130 = 0 ;
V_75 = F_38 ( V_1 , V_106 , T_6 -> V_27 , NULL , NULL ,
V_123 -> V_62 , V_123 -> V_71 ,
V_123 -> V_51 , true ) ;
if ( V_75 == NULL )
return - V_124 ;
T_6 -> V_75 = V_75 ;
V_139 [ T_6 -> V_131 ++ ] = V_75 ;
F_48 ( V_75 , V_123 ) ;
F_59 ( & V_140 ) ;
F_47 ( V_1 , V_75 -> V_59 ) ;
return V_130 ;
}
static int
F_61 ( struct V_120 * T_6 ,
struct V_105 * V_106 )
{
struct V_142 * V_100 ;
V_100 = F_62 ( & V_140 ) ;
if ( V_100 == NULL )
return 0 ;
return F_63 ( V_106 , V_100 , T_6 -> V_136 ) ;
}
static int
F_64 ( struct V_120 * T_6 ,
struct V_105 * V_106 )
{
struct V_129 * V_127 = T_6 -> V_127 ;
struct V_122 * V_123 = T_6 -> V_123 ;
struct V_14 * * V_139 = T_6 -> V_125 ;
struct V_14 * V_75 ;
struct V_14 V_143 = {
. V_1 = F_45 ( V_127 ) ,
. V_117 = V_106 -> V_117 ,
. V_23 = V_106 -> V_23 ,
. V_116 = F_39 ( V_106 -> V_23 ) ,
. V_118 = V_106 -> V_119 ,
. V_17 = {
. V_26 = V_106 -> V_26 ,
. V_18 = V_106 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
} ;
int V_135 ;
struct V_140 V_144 ;
F_65 ( & V_144 , & V_140 ) ;
F_66 ( & V_140 ) ;
for ( V_135 = 0 ; V_135 < T_6 -> V_131 ; V_135 ++ ) {
if ( F_33 ( V_139 [ V_135 ] , & V_143 ) == 0 ) {
T_6 -> V_75 = NULL ;
return 0 ;
}
}
V_75 = F_38 ( F_45 ( V_127 ) , V_106 , T_6 -> V_27 , NULL , NULL ,
V_123 -> V_62 , V_123 -> V_71 ,
V_123 -> V_51 , false ) ;
if ( V_75 == NULL )
return - V_124 ;
T_6 -> V_75 = V_75 ;
V_139 [ T_6 -> V_131 ++ ] = V_75 ;
if ( V_10 . V_95 )
F_67 ( V_75 -> V_98 , & V_144 , V_123 -> V_62 ) ;
return 0 ;
}
static int
F_68 ( struct V_120 * T_6 ,
struct V_105 * V_106 V_121 )
{
F_34 ( & T_6 -> V_125 ) ;
T_6 -> V_75 = NULL ;
return 0 ;
}
int F_69 ( struct V_120 * T_6 , struct V_105 * V_106 ,
int V_145 , void * V_146 )
{
int V_130 , V_147 ;
V_130 = F_70 ( T_6 -> V_123 , & T_6 -> V_27 ,
T_6 -> V_127 , V_106 , V_145 ) ;
if ( V_130 )
return V_130 ;
V_130 = T_6 -> V_148 -> V_149 ( T_6 , V_106 ) ;
if ( V_130 )
goto V_110;
V_130 = T_6 -> V_148 -> V_150 ( T_6 , V_106 ) ;
if ( V_130 )
goto V_110;
if ( T_6 -> V_75 && T_6 -> V_151 ) {
V_130 = T_6 -> V_151 ( T_6 , V_106 , true , V_146 ) ;
if ( V_130 )
goto V_110;
}
while ( T_6 -> V_148 -> V_152 ( T_6 , V_106 ) ) {
V_130 = T_6 -> V_148 -> V_153 ( T_6 , V_106 ) ;
if ( V_130 )
break;
if ( T_6 -> V_75 && T_6 -> V_151 ) {
V_130 = T_6 -> V_151 ( T_6 , V_106 , false , V_146 ) ;
if ( V_130 )
goto V_110;
}
}
V_110:
V_147 = T_6 -> V_148 -> V_154 ( T_6 , V_106 ) ;
if ( ! V_130 )
V_130 = V_147 ;
return V_130 ;
}
T_5
F_33 ( struct V_14 * V_155 , struct V_14 * V_156 )
{
struct V_157 * V_158 ;
T_5 V_108 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_158 ) )
continue;
V_108 = V_158 -> V_108 ( V_158 , V_155 , V_156 ) ;
if ( V_108 )
break;
}
return V_108 ;
}
T_5
F_73 ( struct V_14 * V_155 , struct V_14 * V_156 )
{
struct V_157 * V_158 ;
T_5 V_108 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_158 ) )
continue;
V_108 = V_158 -> V_159 ( V_158 , V_155 , V_156 ) ;
if ( V_108 )
break;
}
return V_108 ;
}
void F_21 ( struct V_14 * V_75 )
{
F_74 ( V_75 -> V_23 ) ;
F_27 ( V_75 -> V_17 . V_26 ) ;
if ( V_75 -> V_29 ) {
F_27 ( V_75 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_75 -> V_29 -> V_33 . V_26 ) ;
F_34 ( & V_75 -> V_29 ) ;
}
if ( V_75 -> V_36 ) {
F_27 ( V_75 -> V_36 -> V_97 . V_26 ) ;
F_27 ( V_75 -> V_36 -> V_37 . V_26 ) ;
F_34 ( & V_75 -> V_36 ) ;
}
F_34 ( & V_75 -> V_80 ) ;
F_75 ( V_75 -> V_47 ) ;
if ( V_75 -> V_49 && V_75 -> V_49 [ 0 ] )
free ( V_75 -> V_49 ) ;
F_76 ( V_75 -> V_98 ) ;
free ( V_75 ) ;
}
static bool F_77 ( struct V_1 * V_1 V_121 ,
struct V_160 * V_161 ,
struct V_14 * V_75 )
{
struct V_54 * * V_107 = & V_161 -> V_54 ;
struct V_54 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_108 ;
while ( * V_107 != NULL ) {
V_27 = * V_107 ;
T_6 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_108 = F_73 ( T_6 , V_75 ) ;
if ( ! V_108 ) {
F_16 ( & T_6 -> V_77 , & V_75 -> V_77 ) ;
if ( V_10 . V_79 )
F_16 ( T_6 -> V_80 , V_75 -> V_80 ) ;
if ( V_10 . V_95 ) {
F_78 ( & V_140 ) ;
F_79 ( & V_140 ,
T_6 -> V_98 ,
V_75 -> V_98 ) ;
}
F_21 ( V_75 ) ;
return false ;
}
if ( V_108 < 0 )
V_107 = & ( * V_107 ) -> V_111 ;
else
V_107 = & ( * V_107 ) -> V_112 ;
}
V_1 -> V_87 ++ ;
F_36 ( & V_75 -> V_85 , V_27 , V_107 ) ;
F_37 ( & V_75 -> V_85 , V_161 ) ;
return true ;
}
static struct V_160 * F_80 ( struct V_1 * V_1 )
{
struct V_160 * V_161 ;
F_81 ( & V_1 -> V_162 ) ;
V_161 = V_1 -> V_109 ;
if ( ++ V_1 -> V_109 > & V_1 -> V_163 [ 1 ] )
V_1 -> V_109 = & V_1 -> V_163 [ 0 ] ;
F_82 ( & V_1 -> V_162 ) ;
return V_161 ;
}
static void F_83 ( struct V_1 * V_1 , struct V_14 * V_75 )
{
F_84 ( V_1 , V_75 ) ;
F_85 ( V_1 , V_75 ) ;
F_86 ( V_1 , V_75 ) ;
}
void F_87 ( struct V_1 * V_1 , struct V_164 * V_165 )
{
struct V_160 * V_161 ;
struct V_54 * V_55 ;
struct V_14 * V_57 ;
if ( ! V_84 )
return;
V_1 -> V_87 = 0 ;
V_161 = F_80 ( V_1 ) ;
V_55 = F_11 ( V_161 ) ;
while ( V_55 ) {
if ( F_88 () )
break;
V_57 = F_12 ( V_55 , struct V_14 , V_85 ) ;
V_55 = F_13 ( & V_57 -> V_85 ) ;
F_20 ( & V_57 -> V_85 , V_161 ) ;
if ( F_77 ( V_1 , & V_1 -> V_86 , V_57 ) ) {
F_83 ( V_1 , V_57 ) ;
}
if ( V_165 )
F_89 ( V_165 , 1 ) ;
}
}
static int F_90 ( struct V_14 * V_166 , struct V_14 * V_167 )
{
struct V_157 * V_158 ;
T_5 V_108 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_158 ) )
continue;
V_108 = V_158 -> V_168 ( V_158 , V_166 , V_167 ) ;
if ( V_108 )
break;
}
return V_108 ;
}
static void F_91 ( struct V_1 * V_1 )
{
V_1 -> V_88 = 0 ;
V_1 -> V_81 . V_83 = 0 ;
}
void F_92 ( struct V_1 * V_1 )
{
V_1 -> V_87 = 0 ;
V_1 -> V_81 . V_82 = 0 ;
F_91 ( V_1 ) ;
}
static void F_93 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_88 ++ ;
V_1 -> V_81 . V_83 += V_15 -> V_77 . V_62 ;
}
void F_94 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_59 )
F_93 ( V_1 , V_15 ) ;
V_1 -> V_87 ++ ;
V_1 -> V_81 . V_82 += V_15 -> V_77 . V_62 ;
}
static void F_95 ( struct V_160 * V_56 ,
struct V_14 * V_75 ,
T_2 V_169 ,
bool V_95 )
{
struct V_54 * * V_107 = & V_56 -> V_54 ;
struct V_54 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_95 )
V_170 . V_168 ( & V_75 -> V_171 , V_75 -> V_98 ,
V_169 , & V_170 ) ;
while ( * V_107 != NULL ) {
V_27 = * V_107 ;
T_6 = F_12 ( V_27 , struct V_14 , V_54 ) ;
if ( F_90 ( V_75 , T_6 ) > 0 )
V_107 = & ( * V_107 ) -> V_111 ;
else
V_107 = & ( * V_107 ) -> V_112 ;
}
F_36 ( & V_75 -> V_54 , V_27 , V_107 ) ;
F_37 ( & V_75 -> V_54 , V_56 ) ;
}
void F_96 ( struct V_1 * V_1 , struct V_164 * V_165 )
{
struct V_160 * V_161 ;
struct V_54 * V_55 ;
struct V_14 * V_57 ;
T_2 V_169 ;
struct V_129 * V_127 = F_97 ( V_1 ) ;
bool V_95 ;
if ( V_127 && ! V_10 . V_172 )
V_95 = V_127 -> V_173 . V_174 & V_175 ;
else
V_95 = V_10 . V_95 ;
V_169 = V_1 -> V_81 . V_82 * ( V_170 . V_176 / 100 ) ;
if ( V_84 )
V_161 = & V_1 -> V_86 ;
else
V_161 = V_1 -> V_109 ;
V_55 = F_11 ( V_161 ) ;
V_1 -> V_56 = V_177 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_55 ) {
V_57 = F_12 ( V_55 , struct V_14 , V_85 ) ;
V_55 = F_13 ( & V_57 -> V_85 ) ;
F_95 ( & V_1 -> V_56 , V_57 , V_169 , V_95 ) ;
F_94 ( V_1 , V_57 ) ;
if ( ! V_57 -> V_59 )
F_6 ( V_1 , V_57 ) ;
if ( V_165 )
F_89 ( V_165 , 1 ) ;
}
}
static void F_98 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_178 V_179 )
{
V_15 -> V_59 &= ~ ( 1 << V_179 ) ;
if ( V_15 -> V_59 )
return;
V_15 -> V_180 = false ;
V_15 -> V_181 = 0 ;
V_15 -> V_182 = 0 ;
V_1 -> V_81 . V_183 += V_15 -> V_77 . V_72 ;
F_93 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_84 ( struct V_1 * V_1 ,
struct V_14 * V_75 )
{
if ( V_1 -> V_184 != NULL &&
( V_75 -> V_17 . V_26 == NULL || V_75 -> V_17 . V_26 -> V_7 != V_1 -> V_184 ) ) {
V_75 -> V_59 |= ( 1 << V_185 ) ;
return true ;
}
return false ;
}
void F_99 ( struct V_1 * V_1 )
{
struct V_54 * V_186 ;
V_1 -> V_81 . V_183 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_186 = F_11 ( & V_1 -> V_56 ) ; V_186 ; V_186 = F_13 ( V_186 ) ) {
struct V_14 * V_15 = F_12 ( V_186 , struct V_14 , V_54 ) ;
if ( V_10 . V_102 && ! V_15 -> V_27 )
continue;
if ( F_84 ( V_1 , V_15 ) )
continue;
F_98 ( V_1 , V_15 , V_185 ) ;
}
}
static bool F_85 ( struct V_1 * V_1 ,
struct V_14 * V_75 )
{
if ( V_1 -> V_187 != NULL &&
V_75 -> V_23 != V_1 -> V_187 ) {
V_75 -> V_59 |= ( 1 << V_188 ) ;
return true ;
}
return false ;
}
void F_100 ( struct V_1 * V_1 )
{
struct V_54 * V_186 ;
V_1 -> V_81 . V_183 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_186 = F_11 ( & V_1 -> V_56 ) ; V_186 ; V_186 = F_13 ( V_186 ) ) {
struct V_14 * V_15 = F_12 ( V_186 , struct V_14 , V_54 ) ;
if ( F_85 ( V_1 , V_15 ) )
continue;
F_98 ( V_1 , V_15 , V_188 ) ;
}
}
static bool F_86 ( struct V_1 * V_1 ,
struct V_14 * V_75 )
{
if ( V_1 -> V_189 != NULL &&
( ! V_75 -> V_17 . V_18 || strstr ( V_75 -> V_17 . V_18 -> V_190 ,
V_1 -> V_189 ) == NULL ) ) {
V_75 -> V_59 |= ( 1 << V_191 ) ;
return true ;
}
return false ;
}
void F_101 ( struct V_1 * V_1 )
{
struct V_54 * V_186 ;
V_1 -> V_81 . V_183 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_186 = F_11 ( & V_1 -> V_56 ) ; V_186 ; V_186 = F_13 ( V_186 ) ) {
struct V_14 * V_15 = F_12 ( V_186 , struct V_14 , V_54 ) ;
if ( F_86 ( V_1 , V_15 ) )
continue;
F_98 ( V_1 , V_15 , V_191 ) ;
}
}
void F_102 ( struct V_192 * V_81 , T_7 type )
{
++ V_81 -> V_72 [ 0 ] ;
++ V_81 -> V_72 [ type ] ;
}
void F_103 ( struct V_1 * V_1 , T_7 type )
{
F_102 ( & V_1 -> V_81 , type ) ;
}
void F_47 ( struct V_1 * V_1 , bool V_59 )
{
F_102 ( & V_1 -> V_81 , V_193 ) ;
if ( ! V_59 )
V_1 -> V_81 . V_183 ++ ;
}
static struct V_14 * F_104 ( struct V_1 * V_1 ,
struct V_14 * V_194 )
{
struct V_160 * V_161 ;
struct V_54 * * V_107 ;
struct V_54 * V_27 = NULL ;
struct V_14 * V_75 ;
T_5 V_108 ;
if ( V_84 )
V_161 = & V_1 -> V_86 ;
else
V_161 = V_1 -> V_109 ;
V_107 = & V_161 -> V_54 ;
while ( * V_107 != NULL ) {
V_27 = * V_107 ;
V_75 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_108 = F_73 ( V_75 , V_194 ) ;
if ( ! V_108 )
goto V_110;
if ( V_108 < 0 )
V_107 = & ( * V_107 ) -> V_111 ;
else
V_107 = & ( * V_107 ) -> V_112 ;
}
V_75 = F_24 ( V_194 , true ) ;
if ( V_75 ) {
memset ( & V_75 -> V_77 , 0 , sizeof( V_75 -> V_77 ) ) ;
V_75 -> V_1 = V_1 ;
F_36 ( & V_75 -> V_85 , V_27 , V_107 ) ;
F_37 ( & V_75 -> V_85 , V_161 ) ;
F_94 ( V_1 , V_75 ) ;
V_75 -> V_195 = true ;
}
V_110:
return V_75 ;
}
static struct V_14 * F_105 ( struct V_1 * V_1 ,
struct V_14 * V_75 )
{
struct V_54 * V_57 ;
if ( V_84 )
V_57 = V_1 -> V_86 . V_54 ;
else
V_57 = V_1 -> V_109 -> V_54 ;
while ( V_57 ) {
struct V_14 * T_6 = F_12 ( V_57 , struct V_14 , V_85 ) ;
T_5 V_108 = F_73 ( T_6 , V_75 ) ;
if ( V_108 < 0 )
V_57 = V_57 -> V_111 ;
else if ( V_108 > 0 )
V_57 = V_57 -> V_112 ;
else
return T_6 ;
}
return NULL ;
}
void F_106 ( struct V_1 * V_196 , struct V_1 * V_197 )
{
struct V_160 * V_161 ;
struct V_54 * V_186 ;
struct V_14 * V_198 , * V_194 ;
if ( V_84 )
V_161 = & V_196 -> V_86 ;
else
V_161 = V_196 -> V_109 ;
for ( V_186 = F_11 ( V_161 ) ; V_186 ; V_186 = F_13 ( V_186 ) ) {
V_198 = F_12 ( V_186 , struct V_14 , V_85 ) ;
V_194 = F_105 ( V_197 , V_198 ) ;
if ( V_194 )
F_107 ( V_194 , V_198 ) ;
}
}
int F_108 ( struct V_1 * V_196 , struct V_1 * V_197 )
{
struct V_160 * V_161 ;
struct V_54 * V_186 ;
struct V_14 * V_198 , * V_194 ;
if ( V_84 )
V_161 = & V_197 -> V_86 ;
else
V_161 = V_197 -> V_109 ;
for ( V_186 = F_11 ( V_161 ) ; V_186 ; V_186 = F_13 ( V_186 ) ) {
V_198 = F_12 ( V_186 , struct V_14 , V_85 ) ;
if ( ! F_109 ( V_198 ) ) {
V_194 = F_104 ( V_196 , V_198 ) ;
if ( V_194 == NULL )
return - 1 ;
F_107 ( V_198 , V_194 ) ;
}
}
return 0 ;
}
void F_110 ( struct V_133 * V_199 , struct V_105 * V_106 ,
struct V_122 * V_123 , bool V_200 )
{
struct V_29 * V_114 ;
if ( V_199 && V_199 -> V_134 && V_199 -> V_56 [ 0 ] . V_137 . V_138 ) {
int V_135 ;
V_114 = F_50 ( V_123 , V_106 ) ;
if ( V_114 ) {
struct V_201 * V_202 = NULL ;
for ( V_135 = V_199 -> V_134 - 1 ; V_135 >= 0 ; V_135 -- ) {
F_111 ( & V_114 [ V_135 ] . V_30 ,
V_200 ? NULL : V_202 ,
V_114 [ V_135 ] . V_137 . V_138 ) ;
V_202 = & V_114 [ V_135 ] . V_33 ;
}
free ( V_114 ) ;
}
}
}
T_3 F_112 ( struct V_203 * V_204 , T_8 * V_205 )
{
struct V_129 * V_198 ;
T_3 V_206 = 0 ;
F_113 (evlist, pos) {
V_206 += fprintf ( V_205 , L_1 , F_114 ( V_198 ) ) ;
V_206 += F_115 ( & F_45 ( V_198 ) -> V_81 , V_205 ) ;
}
return V_206 ;
}
T_2 F_116 ( struct V_1 * V_1 )
{
return V_10 . V_207 ? V_1 -> V_81 . V_83 :
V_1 -> V_81 . V_82 ;
}
int F_117 ( const struct V_208 * T_9 V_121 ,
const char * V_146 , int T_10 V_121 )
{
if ( ! strcmp ( V_146 , L_2 ) )
V_10 . V_207 = true ;
else if ( ! strcmp ( V_146 , L_3 ) )
V_10 . V_207 = false ;
else
return - 1 ;
return 0 ;
}
int F_118 ( const char * V_209 , const char * V_210 )
{
if ( ! strcmp ( V_209 , L_4 ) )
return F_117 ( NULL , V_210 , 0 ) ;
return 0 ;
}
static int F_119 ( struct V_129 * V_127 )
{
struct V_1 * V_1 = F_45 ( V_127 ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_163 [ 0 ] = V_1 -> V_163 [ 1 ] = V_177 ;
V_1 -> V_109 = & V_1 -> V_163 [ 0 ] ;
V_1 -> V_86 = V_177 ;
V_1 -> V_56 = V_177 ;
F_120 ( & V_1 -> V_162 , NULL ) ;
return 0 ;
}
int F_121 ( void )
{
int V_130 = F_122 ( sizeof( struct V_211 ) ,
F_119 , NULL ) ;
if ( V_130 )
fputs ( L_5 , V_212 ) ;
return V_130 ;
}
