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
F_3 ( V_1 , V_48 ,
F_9 () ) ;
}
void F_10 ( struct V_1 * V_1 , int V_49 )
{
struct V_50 * V_51 = F_11 ( & V_1 -> V_52 ) ;
struct V_14 * V_53 ;
int V_54 = 0 ;
F_4 ( V_1 ) ;
while ( V_51 && V_54 ++ < V_49 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_50 ) ;
if ( ! V_53 -> V_55 )
F_6 ( V_1 , V_53 ) ;
V_51 = F_13 ( & V_53 -> V_50 ) ;
}
}
static void F_14 ( struct V_56 * V_56 ,
unsigned int V_57 , T_2 V_58 )
{
switch ( V_57 ) {
case V_59 :
V_56 -> V_60 += V_58 ;
break;
case V_61 :
V_56 -> V_62 += V_58 ;
break;
case V_63 :
V_56 -> V_64 += V_58 ;
break;
case V_65 :
V_56 -> V_66 += V_58 ;
break;
default:
break;
}
}
static void F_15 ( struct V_56 * V_56 , T_2 V_58 ,
T_2 V_67 )
{
V_56 -> V_58 += V_58 ;
V_56 -> V_67 += V_67 ;
V_56 -> V_68 += 1 ;
}
static void F_16 ( struct V_56 * V_69 , struct V_56 * V_70 )
{
V_69 -> V_58 += V_70 -> V_58 ;
V_69 -> V_60 += V_70 -> V_60 ;
V_69 -> V_62 += V_70 -> V_62 ;
V_69 -> V_64 += V_70 -> V_64 ;
V_69 -> V_66 += V_70 -> V_66 ;
V_69 -> V_68 += V_70 -> V_68 ;
V_69 -> V_67 += V_70 -> V_67 ;
}
static void F_17 ( struct V_56 * V_56 )
{
V_56 -> V_58 = ( V_56 -> V_58 * 7 ) / 8 ;
V_56 -> V_68 = ( V_56 -> V_68 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_71 )
{
T_2 V_72 = V_71 -> V_73 . V_58 ;
T_2 V_74 ;
if ( V_72 == 0 )
return true ;
F_17 ( & V_71 -> V_73 ) ;
if ( V_10 . V_75 )
F_17 ( V_71 -> V_76 ) ;
V_74 = V_72 - V_71 -> V_73 . V_58 ;
V_1 -> V_77 . V_78 -= V_74 ;
if ( ! V_71 -> V_55 )
V_1 -> V_77 . V_79 -= V_74 ;
return V_71 -> V_73 . V_58 == 0 ;
}
static void F_19 ( struct V_1 * V_1 , struct V_14 * V_71 )
{
F_20 ( & V_71 -> V_50 , & V_1 -> V_52 ) ;
if ( V_80 )
F_20 ( & V_71 -> V_81 , & V_1 -> V_82 ) ;
-- V_1 -> V_83 ;
if ( ! V_71 -> V_55 )
-- V_1 -> V_84 ;
F_21 ( V_71 ) ;
}
void F_22 ( struct V_1 * V_1 , bool V_85 , bool V_86 )
{
struct V_50 * V_51 = F_11 ( & V_1 -> V_52 ) ;
struct V_14 * V_53 ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_50 ) ;
V_51 = F_13 ( & V_53 -> V_50 ) ;
if ( ( ( V_85 && V_53 -> V_87 == '.' ) ||
( V_86 && V_53 -> V_87 != '.' ) ||
F_18 ( V_1 , V_53 ) ) ) {
F_19 ( V_1 , V_53 ) ;
}
}
}
void F_23 ( struct V_1 * V_1 )
{
struct V_50 * V_51 = F_11 ( & V_1 -> V_52 ) ;
struct V_14 * V_53 ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_50 ) ;
V_51 = F_13 ( & V_53 -> V_50 ) ;
F_19 ( V_1 , V_53 ) ;
}
}
static struct V_14 * F_24 ( struct V_14 * V_88 ,
bool V_89 )
{
T_3 V_90 = 0 ;
struct V_14 * V_71 ;
if ( V_10 . V_91 )
V_90 = sizeof( struct V_92 ) ;
V_71 = F_25 ( sizeof( * V_71 ) + V_90 ) ;
if ( V_71 != NULL ) {
* V_71 = * V_88 ;
if ( V_10 . V_75 ) {
V_71 -> V_76 = malloc ( sizeof( V_71 -> V_73 ) ) ;
if ( V_71 -> V_76 == NULL ) {
free ( V_71 ) ;
return NULL ;
}
memcpy ( V_71 -> V_76 , & V_71 -> V_73 , sizeof( V_71 -> V_73 ) ) ;
if ( ! V_89 )
memset ( & V_71 -> V_73 , 0 , sizeof( V_71 -> V_73 ) ) ;
}
if ( V_71 -> V_17 . V_26 )
V_71 -> V_17 . V_26 -> V_93 = true ;
if ( V_71 -> V_29 ) {
V_71 -> V_29 = malloc ( sizeof( * V_71 -> V_29 ) ) ;
if ( V_71 -> V_29 == NULL ) {
free ( V_71 -> V_76 ) ;
free ( V_71 ) ;
return NULL ;
}
memcpy ( V_71 -> V_29 , V_88 -> V_29 ,
sizeof( * V_71 -> V_29 ) ) ;
if ( V_71 -> V_29 -> V_30 . V_26 )
V_71 -> V_29 -> V_30 . V_26 -> V_93 = true ;
if ( V_71 -> V_29 -> V_33 . V_26 )
V_71 -> V_29 -> V_33 . V_26 -> V_93 = true ;
}
if ( V_71 -> V_36 ) {
if ( V_71 -> V_36 -> V_94 . V_26 )
V_71 -> V_36 -> V_94 . V_26 -> V_93 = true ;
if ( V_71 -> V_36 -> V_37 . V_26 )
V_71 -> V_36 -> V_37 . V_26 -> V_93 = true ;
}
if ( V_10 . V_91 )
F_26 ( V_71 -> V_95 ) ;
F_27 ( & V_71 -> V_96 . V_97 ) ;
F_28 ( V_71 -> V_23 ) ;
}
return V_71 ;
}
static T_4 F_29 ( const struct V_98 * V_27 )
{
if ( V_10 . V_99 && V_27 == NULL )
return 1 << V_100 ;
return 0 ;
}
static struct V_14 * F_30 ( struct V_1 * V_1 ,
struct V_14 * V_101 ,
struct V_102 * V_103 ,
bool V_89 )
{
struct V_50 * * V_104 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_105 ;
T_2 V_58 = V_101 -> V_73 . V_58 ;
T_2 V_67 = V_101 -> V_73 . V_67 ;
V_104 = & V_1 -> V_106 -> V_50 ;
while ( * V_104 != NULL ) {
V_27 = * V_104 ;
V_71 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_105 = F_31 ( V_71 , V_101 ) ;
if ( ! V_105 ) {
if ( V_89 )
F_15 ( & V_71 -> V_73 , V_58 , V_67 ) ;
if ( V_10 . V_75 )
F_15 ( V_71 -> V_76 , V_58 , V_67 ) ;
F_32 ( & V_101 -> V_36 ) ;
if ( V_71 -> V_17 . V_26 != V_101 -> V_17 . V_26 ) {
V_71 -> V_17 . V_26 = V_101 -> V_17 . V_26 ;
if ( V_71 -> V_17 . V_26 )
V_71 -> V_17 . V_26 -> V_93 = true ;
}
goto V_107;
}
if ( V_105 < 0 )
V_104 = & ( * V_104 ) -> V_108 ;
else
V_104 = & ( * V_104 ) -> V_109 ;
}
V_71 = F_24 ( V_101 , V_89 ) ;
if ( ! V_71 )
return NULL ;
V_1 -> V_83 ++ ;
F_33 ( & V_71 -> V_81 , V_27 , V_104 ) ;
F_34 ( & V_71 -> V_81 , V_1 -> V_106 ) ;
V_107:
if ( V_89 )
F_14 ( & V_71 -> V_73 , V_103 -> V_57 , V_58 ) ;
if ( V_10 . V_75 )
F_14 ( V_71 -> V_76 , V_103 -> V_57 , V_58 ) ;
return V_71 ;
}
struct V_14 * F_35 ( struct V_1 * V_1 ,
struct V_102 * V_103 ,
struct V_98 * V_110 ,
struct V_29 * V_111 ,
struct V_36 * V_112 ,
T_2 V_58 , T_2 V_67 , T_2 V_47 ,
bool V_89 )
{
struct V_14 V_101 = {
. V_23 = V_103 -> V_23 ,
. V_113 = F_36 ( V_103 -> V_23 ) ,
. V_17 = {
. V_26 = V_103 -> V_26 ,
. V_18 = V_103 -> V_18 ,
} ,
. V_114 = V_103 -> V_114 ,
. V_57 = V_103 -> V_57 ,
. V_115 = V_103 -> V_116 ,
. V_87 = V_103 -> V_87 ,
. V_73 = {
. V_68 = 1 ,
. V_58 = V_58 ,
. V_67 = V_67 ,
} ,
. V_27 = V_110 ,
. V_55 = F_29 ( V_110 ) | V_103 -> V_55 ,
. V_1 = V_1 ,
. V_29 = V_111 ,
. V_36 = V_112 ,
. V_47 = V_47 ,
} ;
return F_30 ( V_1 , & V_101 , V_103 , V_89 ) ;
}
static int
F_37 ( struct V_117 * T_6 V_118 ,
struct V_102 * V_103 V_118 )
{
return 0 ;
}
static int
F_38 ( struct V_117 * T_6 V_118 ,
struct V_102 * V_103 V_118 )
{
return 0 ;
}
static int
F_39 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
struct V_119 * V_120 = T_6 -> V_120 ;
struct V_36 * V_112 ;
V_112 = F_40 ( V_120 , V_103 ) ;
if ( V_112 == NULL )
return - V_121 ;
T_6 -> V_122 = V_112 ;
return 0 ;
}
static int
F_41 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
T_2 V_123 ;
struct V_36 * V_112 = T_6 -> V_122 ;
struct V_1 * V_1 = F_42 ( T_6 -> V_124 ) ;
struct V_14 * V_71 ;
if ( V_112 == NULL )
return - V_125 ;
V_123 = T_6 -> V_120 -> V_67 ;
if ( ! V_123 )
V_123 = 1 ;
V_71 = F_35 ( V_1 , V_103 , T_6 -> V_27 , NULL , V_112 ,
V_123 , V_123 , 0 , true ) ;
if ( ! V_71 )
return - V_121 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_43 ( struct V_117 * T_6 ,
struct V_102 * V_103 V_118 )
{
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_1 * V_1 = F_42 ( V_124 ) ;
struct V_14 * V_71 = T_6 -> V_71 ;
int V_127 = - V_125 ;
if ( V_71 == NULL )
goto V_107;
F_44 ( V_1 , V_71 -> V_55 ) ;
V_127 = F_45 ( V_71 , T_6 -> V_120 ) ;
V_107:
T_6 -> V_122 = NULL ;
T_6 -> V_71 = NULL ;
return V_127 ;
}
static int
F_46 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
struct V_29 * V_111 ;
struct V_119 * V_120 = T_6 -> V_120 ;
V_111 = F_47 ( V_120 , V_103 ) ;
if ( ! V_111 )
return - V_121 ;
T_6 -> V_128 = 0 ;
T_6 -> V_129 = V_120 -> V_130 -> V_131 ;
T_6 -> V_122 = V_111 ;
return 0 ;
}
static int
F_48 ( struct V_117 * T_6 V_118 ,
struct V_102 * V_103 V_118 )
{
T_6 -> V_71 = NULL ;
return 0 ;
}
static int
F_49 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
struct V_29 * V_111 = T_6 -> V_122 ;
int V_132 = T_6 -> V_128 ;
if ( V_111 == NULL )
return 0 ;
if ( T_6 -> V_128 >= T_6 -> V_129 )
return 0 ;
V_103 -> V_26 = V_111 [ V_132 ] . V_33 . V_26 ;
V_103 -> V_18 = V_111 [ V_132 ] . V_33 . V_18 ;
V_103 -> V_116 = V_111 [ V_132 ] . V_33 . V_116 ;
return 1 ;
}
static int
F_50 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
struct V_29 * V_111 ;
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_1 * V_1 = F_42 ( V_124 ) ;
struct V_14 * V_71 = NULL ;
int V_132 = T_6 -> V_128 ;
int V_127 = 0 ;
V_111 = T_6 -> V_122 ;
if ( T_6 -> V_133 && ! ( V_111 [ V_132 ] . V_30 . V_18 && V_111 [ V_132 ] . V_33 . V_18 ) )
goto V_107;
V_71 = F_35 ( V_1 , V_103 , T_6 -> V_27 , & V_111 [ V_132 ] , NULL ,
1 , 1 , 0 , true ) ;
if ( V_71 == NULL )
return - V_121 ;
F_44 ( V_1 , V_71 -> V_55 ) ;
V_107:
T_6 -> V_71 = V_71 ;
T_6 -> V_128 ++ ;
return V_127 ;
}
static int
F_51 ( struct V_117 * T_6 ,
struct V_102 * V_103 V_118 )
{
F_32 ( & T_6 -> V_122 ) ;
T_6 -> V_71 = NULL ;
return T_6 -> V_128 >= T_6 -> V_129 ? 0 : - 1 ;
}
static int
F_52 ( struct V_117 * T_6 V_118 ,
struct V_102 * V_103 V_118 )
{
return 0 ;
}
static int
F_53 ( struct V_117 * T_6 , struct V_102 * V_103 )
{
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_119 * V_120 = T_6 -> V_120 ;
struct V_14 * V_71 ;
V_71 = F_35 ( F_42 ( V_124 ) , V_103 , T_6 -> V_27 , NULL , NULL ,
V_120 -> V_58 , V_120 -> V_67 ,
V_120 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_121 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_54 ( struct V_117 * T_6 ,
struct V_102 * V_103 V_118 )
{
struct V_14 * V_71 = T_6 -> V_71 ;
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_119 * V_120 = T_6 -> V_120 ;
if ( V_71 == NULL )
return 0 ;
T_6 -> V_71 = NULL ;
F_44 ( F_42 ( V_124 ) , V_71 -> V_55 ) ;
return F_45 ( V_71 , V_120 ) ;
}
static int
F_55 ( struct V_117 * T_6 V_118 ,
struct V_102 * V_103 V_118 )
{
struct V_14 * * V_134 ;
F_56 ( & V_135 ) ;
V_134 = malloc ( sizeof( * V_134 ) * ( V_136 + 1 ) ) ;
if ( V_134 == NULL )
return - V_121 ;
T_6 -> V_122 = V_134 ;
T_6 -> V_128 = 0 ;
return 0 ;
}
static int
F_57 ( struct V_117 * T_6 ,
struct V_102 * V_103 )
{
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_1 * V_1 = F_42 ( V_124 ) ;
struct V_119 * V_120 = T_6 -> V_120 ;
struct V_14 * * V_134 = T_6 -> V_122 ;
struct V_14 * V_71 ;
int V_127 = 0 ;
V_71 = F_35 ( V_1 , V_103 , T_6 -> V_27 , NULL , NULL ,
V_120 -> V_58 , V_120 -> V_67 ,
V_120 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_121 ;
T_6 -> V_71 = V_71 ;
V_134 [ T_6 -> V_128 ++ ] = V_71 ;
F_45 ( V_71 , V_120 ) ;
F_56 ( & V_135 ) ;
F_44 ( V_1 , V_71 -> V_55 ) ;
return V_127 ;
}
static int
F_58 ( struct V_117 * T_6 ,
struct V_102 * V_103 )
{
struct V_137 * V_97 ;
V_97 = F_59 ( & V_135 ) ;
if ( V_97 == NULL )
return 0 ;
return F_60 ( V_103 , V_97 , T_6 -> V_133 ) ;
}
static int
F_61 ( struct V_117 * T_6 ,
struct V_102 * V_103 )
{
struct V_126 * V_124 = T_6 -> V_124 ;
struct V_119 * V_120 = T_6 -> V_120 ;
struct V_14 * * V_134 = T_6 -> V_122 ;
struct V_14 * V_71 ;
struct V_14 V_138 = {
. V_114 = V_103 -> V_114 ,
. V_23 = V_103 -> V_23 ,
. V_113 = F_36 ( V_103 -> V_23 ) ,
. V_115 = V_103 -> V_116 ,
. V_17 = {
. V_26 = V_103 -> V_26 ,
. V_18 = V_103 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
} ;
int V_132 ;
struct V_135 V_139 ;
F_62 ( & V_139 , & V_135 ) ;
F_63 ( & V_135 ) ;
for ( V_132 = 0 ; V_132 < T_6 -> V_128 ; V_132 ++ ) {
if ( F_31 ( V_134 [ V_132 ] , & V_138 ) == 0 ) {
T_6 -> V_71 = NULL ;
return 0 ;
}
}
V_71 = F_35 ( F_42 ( V_124 ) , V_103 , T_6 -> V_27 , NULL , NULL ,
V_120 -> V_58 , V_120 -> V_67 ,
V_120 -> V_47 , false ) ;
if ( V_71 == NULL )
return - V_121 ;
T_6 -> V_71 = V_71 ;
V_134 [ T_6 -> V_128 ++ ] = V_71 ;
if ( V_10 . V_91 )
F_64 ( V_71 -> V_95 , & V_139 , V_120 -> V_58 ) ;
return 0 ;
}
static int
F_65 ( struct V_117 * T_6 ,
struct V_102 * V_103 V_118 )
{
F_32 ( & T_6 -> V_122 ) ;
T_6 -> V_71 = NULL ;
return 0 ;
}
int F_66 ( struct V_117 * T_6 , struct V_102 * V_103 ,
struct V_126 * V_124 , struct V_119 * V_120 ,
int V_140 , void * V_141 )
{
int V_127 , V_142 ;
V_127 = F_67 ( V_120 , & T_6 -> V_27 , V_124 , V_103 ,
V_140 ) ;
if ( V_127 )
return V_127 ;
T_6 -> V_124 = V_124 ;
T_6 -> V_120 = V_120 ;
V_127 = T_6 -> V_143 -> V_144 ( T_6 , V_103 ) ;
if ( V_127 )
goto V_107;
V_127 = T_6 -> V_143 -> V_145 ( T_6 , V_103 ) ;
if ( V_127 )
goto V_107;
if ( T_6 -> V_71 && T_6 -> V_146 ) {
V_127 = T_6 -> V_146 ( T_6 , V_103 , true , V_141 ) ;
if ( V_127 )
goto V_107;
}
while ( T_6 -> V_143 -> V_147 ( T_6 , V_103 ) ) {
V_127 = T_6 -> V_143 -> V_148 ( T_6 , V_103 ) ;
if ( V_127 )
break;
if ( T_6 -> V_71 && T_6 -> V_146 ) {
V_127 = T_6 -> V_146 ( T_6 , V_103 , false , V_141 ) ;
if ( V_127 )
goto V_107;
}
}
V_107:
V_142 = T_6 -> V_143 -> V_149 ( T_6 , V_103 ) ;
if ( ! V_127 )
V_127 = V_142 ;
return V_127 ;
}
T_5
F_31 ( struct V_14 * V_150 , struct V_14 * V_151 )
{
struct V_152 * V_153 ;
T_5 V_105 = 0 ;
F_68 (fmt) {
if ( F_69 ( V_153 ) )
continue;
V_105 = V_153 -> V_105 ( V_153 , V_150 , V_151 ) ;
if ( V_105 )
break;
}
return V_105 ;
}
T_5
F_70 ( struct V_14 * V_150 , struct V_14 * V_151 )
{
struct V_152 * V_153 ;
T_5 V_105 = 0 ;
F_68 (fmt) {
if ( F_69 ( V_153 ) )
continue;
V_105 = V_153 -> V_154 ( V_153 , V_150 , V_151 ) ;
if ( V_105 )
break;
}
return V_105 ;
}
void F_21 ( struct V_14 * V_71 )
{
F_71 ( V_71 -> V_23 ) ;
F_32 ( & V_71 -> V_29 ) ;
F_32 ( & V_71 -> V_36 ) ;
F_32 ( & V_71 -> V_76 ) ;
F_72 ( V_71 -> V_155 ) ;
F_73 ( V_71 -> V_95 ) ;
free ( V_71 ) ;
}
static bool F_74 ( struct V_1 * V_1 V_118 ,
struct V_156 * V_157 ,
struct V_14 * V_71 )
{
struct V_50 * * V_104 = & V_157 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_105 ;
while ( * V_104 != NULL ) {
V_27 = * V_104 ;
T_6 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_105 = F_70 ( T_6 , V_71 ) ;
if ( ! V_105 ) {
F_16 ( & T_6 -> V_73 , & V_71 -> V_73 ) ;
if ( V_10 . V_75 )
F_16 ( T_6 -> V_76 , V_71 -> V_76 ) ;
if ( V_10 . V_91 ) {
F_75 ( & V_135 ) ;
F_76 ( & V_135 ,
T_6 -> V_95 ,
V_71 -> V_95 ) ;
}
F_21 ( V_71 ) ;
return false ;
}
if ( V_105 < 0 )
V_104 = & ( * V_104 ) -> V_108 ;
else
V_104 = & ( * V_104 ) -> V_109 ;
}
V_1 -> V_83 ++ ;
F_33 ( & V_71 -> V_81 , V_27 , V_104 ) ;
F_34 ( & V_71 -> V_81 , V_157 ) ;
return true ;
}
static struct V_156 * F_77 ( struct V_1 * V_1 )
{
struct V_156 * V_157 ;
F_78 ( & V_1 -> V_158 ) ;
V_157 = V_1 -> V_106 ;
if ( ++ V_1 -> V_106 > & V_1 -> V_159 [ 1 ] )
V_1 -> V_106 = & V_1 -> V_159 [ 0 ] ;
F_79 ( & V_1 -> V_158 ) ;
return V_157 ;
}
static void F_80 ( struct V_1 * V_1 , struct V_14 * V_71 )
{
F_81 ( V_1 , V_71 ) ;
F_82 ( V_1 , V_71 ) ;
F_83 ( V_1 , V_71 ) ;
}
void F_84 ( struct V_1 * V_1 , struct V_160 * V_161 )
{
struct V_156 * V_157 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
if ( ! V_80 )
return;
V_1 -> V_83 = 0 ;
V_157 = F_77 ( V_1 ) ;
V_51 = F_11 ( V_157 ) ;
while ( V_51 ) {
if ( F_85 () )
break;
V_53 = F_12 ( V_51 , struct V_14 , V_81 ) ;
V_51 = F_13 ( & V_53 -> V_81 ) ;
F_20 ( & V_53 -> V_81 , V_157 ) ;
if ( F_74 ( V_1 , & V_1 -> V_82 , V_53 ) ) {
F_80 ( V_1 , V_53 ) ;
}
if ( V_161 )
F_86 ( V_161 , 1 ) ;
}
}
static int F_87 ( struct V_14 * V_162 , struct V_14 * V_163 )
{
struct V_152 * V_153 ;
T_5 V_105 = 0 ;
F_68 (fmt) {
if ( F_69 ( V_153 ) )
continue;
V_105 = V_153 -> V_164 ( V_153 , V_162 , V_163 ) ;
if ( V_105 )
break;
}
return V_105 ;
}
static void F_88 ( struct V_1 * V_1 )
{
V_1 -> V_84 = 0 ;
V_1 -> V_77 . V_79 = 0 ;
}
void F_89 ( struct V_1 * V_1 )
{
V_1 -> V_83 = 0 ;
V_1 -> V_77 . V_78 = 0 ;
F_88 ( V_1 ) ;
}
static void F_90 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_84 ++ ;
V_1 -> V_77 . V_79 += V_15 -> V_73 . V_58 ;
}
void F_91 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_55 )
F_90 ( V_1 , V_15 ) ;
V_1 -> V_83 ++ ;
V_1 -> V_77 . V_78 += V_15 -> V_73 . V_58 ;
}
static void F_92 ( struct V_156 * V_52 ,
struct V_14 * V_71 ,
T_2 V_165 )
{
struct V_50 * * V_104 = & V_52 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_10 . V_91 )
V_166 . V_164 ( & V_71 -> V_167 , V_71 -> V_95 ,
V_165 , & V_166 ) ;
while ( * V_104 != NULL ) {
V_27 = * V_104 ;
T_6 = F_12 ( V_27 , struct V_14 , V_50 ) ;
if ( F_87 ( V_71 , T_6 ) > 0 )
V_104 = & ( * V_104 ) -> V_108 ;
else
V_104 = & ( * V_104 ) -> V_109 ;
}
F_33 ( & V_71 -> V_50 , V_27 , V_104 ) ;
F_34 ( & V_71 -> V_50 , V_52 ) ;
}
void F_93 ( struct V_1 * V_1 , struct V_160 * V_161 )
{
struct V_156 * V_157 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
T_2 V_165 ;
V_165 = V_1 -> V_77 . V_78 * ( V_166 . V_168 / 100 ) ;
if ( V_80 )
V_157 = & V_1 -> V_82 ;
else
V_157 = V_1 -> V_106 ;
V_51 = F_11 ( V_157 ) ;
V_1 -> V_52 = V_169 ;
F_89 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_81 ) ;
V_51 = F_13 ( & V_53 -> V_81 ) ;
F_92 ( & V_1 -> V_52 , V_53 , V_165 ) ;
F_91 ( V_1 , V_53 ) ;
if ( ! V_53 -> V_55 )
F_6 ( V_1 , V_53 ) ;
if ( V_161 )
F_86 ( V_161 , 1 ) ;
}
}
static void F_94 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_170 V_171 )
{
V_15 -> V_55 &= ~ ( 1 << V_171 ) ;
if ( V_15 -> V_55 )
return;
V_15 -> V_17 . V_172 = false ;
V_15 -> V_173 = 0 ;
V_15 -> V_174 = 0 ;
V_1 -> V_77 . V_175 += V_15 -> V_73 . V_68 ;
F_90 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_81 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_176 != NULL &&
( V_71 -> V_17 . V_26 == NULL || V_71 -> V_17 . V_26 -> V_7 != V_1 -> V_176 ) ) {
V_71 -> V_55 |= ( 1 << V_177 ) ;
return true ;
}
return false ;
}
void F_95 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_88 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( V_10 . V_99 && ! V_15 -> V_27 )
continue;
if ( F_81 ( V_1 , V_15 ) )
continue;
F_94 ( V_1 , V_15 , V_177 ) ;
}
}
static bool F_82 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_179 != NULL &&
V_71 -> V_23 != V_1 -> V_179 ) {
V_71 -> V_55 |= ( 1 << V_180 ) ;
return true ;
}
return false ;
}
void F_96 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_88 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( F_82 ( V_1 , V_15 ) )
continue;
F_94 ( V_1 , V_15 , V_180 ) ;
}
}
static bool F_83 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_181 != NULL &&
( ! V_71 -> V_17 . V_18 || strstr ( V_71 -> V_17 . V_18 -> V_182 ,
V_1 -> V_181 ) == NULL ) ) {
V_71 -> V_55 |= ( 1 << V_183 ) ;
return true ;
}
return false ;
}
void F_97 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_88 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( F_83 ( V_1 , V_15 ) )
continue;
F_94 ( V_1 , V_15 , V_183 ) ;
}
}
void F_98 ( struct V_184 * V_77 , T_7 type )
{
++ V_77 -> V_68 [ 0 ] ;
++ V_77 -> V_68 [ type ] ;
}
void F_99 ( struct V_1 * V_1 , T_7 type )
{
F_98 ( & V_1 -> V_77 , type ) ;
}
void F_44 ( struct V_1 * V_1 , bool V_55 )
{
F_98 ( & V_1 -> V_77 , V_185 ) ;
if ( ! V_55 )
V_1 -> V_77 . V_175 ++ ;
}
static struct V_14 * F_100 ( struct V_1 * V_1 ,
struct V_14 * V_186 )
{
struct V_156 * V_157 ;
struct V_50 * * V_104 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_105 ;
if ( V_80 )
V_157 = & V_1 -> V_82 ;
else
V_157 = V_1 -> V_106 ;
V_104 = & V_157 -> V_50 ;
while ( * V_104 != NULL ) {
V_27 = * V_104 ;
V_71 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_105 = F_70 ( V_71 , V_186 ) ;
if ( ! V_105 )
goto V_107;
if ( V_105 < 0 )
V_104 = & ( * V_104 ) -> V_108 ;
else
V_104 = & ( * V_104 ) -> V_109 ;
}
V_71 = F_24 ( V_186 , true ) ;
if ( V_71 ) {
memset ( & V_71 -> V_73 , 0 , sizeof( V_71 -> V_73 ) ) ;
V_71 -> V_1 = V_1 ;
F_33 ( & V_71 -> V_81 , V_27 , V_104 ) ;
F_34 ( & V_71 -> V_81 , V_157 ) ;
F_91 ( V_1 , V_71 ) ;
V_71 -> V_187 = true ;
}
V_107:
return V_71 ;
}
static struct V_14 * F_101 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
struct V_50 * V_53 ;
if ( V_80 )
V_53 = V_1 -> V_82 . V_50 ;
else
V_53 = V_1 -> V_106 -> V_50 ;
while ( V_53 ) {
struct V_14 * T_6 = F_12 ( V_53 , struct V_14 , V_81 ) ;
T_5 V_105 = F_70 ( T_6 , V_71 ) ;
if ( V_105 < 0 )
V_53 = V_53 -> V_108 ;
else if ( V_105 > 0 )
V_53 = V_53 -> V_109 ;
else
return T_6 ;
}
return NULL ;
}
void F_102 ( struct V_1 * V_188 , struct V_1 * V_189 )
{
struct V_156 * V_157 ;
struct V_50 * V_178 ;
struct V_14 * V_190 , * V_186 ;
if ( V_80 )
V_157 = & V_188 -> V_82 ;
else
V_157 = V_188 -> V_106 ;
for ( V_178 = F_11 ( V_157 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
V_190 = F_12 ( V_178 , struct V_14 , V_81 ) ;
V_186 = F_101 ( V_189 , V_190 ) ;
if ( V_186 )
F_103 ( V_186 , V_190 ) ;
}
}
int F_104 ( struct V_1 * V_188 , struct V_1 * V_189 )
{
struct V_156 * V_157 ;
struct V_50 * V_178 ;
struct V_14 * V_190 , * V_186 ;
if ( V_80 )
V_157 = & V_189 -> V_82 ;
else
V_157 = V_189 -> V_106 ;
for ( V_178 = F_11 ( V_157 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
V_190 = F_12 ( V_178 , struct V_14 , V_81 ) ;
if ( ! F_105 ( V_190 ) ) {
V_186 = F_100 ( V_188 , V_190 ) ;
if ( V_186 == NULL )
return - 1 ;
F_103 ( V_190 , V_186 ) ;
}
}
return 0 ;
}
T_3 F_106 ( struct V_191 * V_192 , T_8 * V_193 )
{
struct V_126 * V_190 ;
T_3 V_194 = 0 ;
F_107 (evlist, pos) {
V_194 += fprintf ( V_193 , L_1 , F_108 ( V_190 ) ) ;
V_194 += F_109 ( & F_42 ( V_190 ) -> V_77 , V_193 ) ;
}
return V_194 ;
}
T_2 F_110 ( struct V_1 * V_1 )
{
return V_10 . V_195 ? V_1 -> V_77 . V_79 :
V_1 -> V_77 . V_78 ;
}
int F_111 ( const struct V_196 * T_9 V_118 ,
const char * V_141 , int T_10 V_118 )
{
if ( ! strcmp ( V_141 , L_2 ) )
V_10 . V_195 = true ;
else if ( ! strcmp ( V_141 , L_3 ) )
V_10 . V_195 = false ;
else
return - 1 ;
return 0 ;
}
int F_112 ( const char * V_197 , const char * V_198 )
{
if ( ! strcmp ( V_197 , L_4 ) )
return F_111 ( NULL , V_198 , 0 ) ;
return 0 ;
}
static int F_113 ( struct V_126 * V_124 )
{
struct V_1 * V_1 = F_42 ( V_124 ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_159 [ 0 ] = V_1 -> V_159 [ 1 ] = V_169 ;
V_1 -> V_106 = & V_1 -> V_159 [ 0 ] ;
V_1 -> V_82 = V_169 ;
V_1 -> V_52 = V_169 ;
F_114 ( & V_1 -> V_158 , NULL ) ;
return 0 ;
}
int F_115 ( void )
{
int V_127 = F_116 ( sizeof( struct V_199 ) ,
F_113 , NULL ) ;
if ( V_127 )
fputs ( L_5 , V_200 ) ;
return V_127 ;
}
