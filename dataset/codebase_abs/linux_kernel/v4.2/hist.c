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
F_26 ( V_71 -> V_17 . V_26 ) ;
if ( V_71 -> V_29 ) {
V_71 -> V_29 = malloc ( sizeof( * V_71 -> V_29 ) ) ;
if ( V_71 -> V_29 == NULL ) {
F_27 ( V_71 -> V_17 . V_26 ) ;
free ( V_71 -> V_76 ) ;
free ( V_71 ) ;
return NULL ;
}
memcpy ( V_71 -> V_29 , V_88 -> V_29 ,
sizeof( * V_71 -> V_29 ) ) ;
F_26 ( V_71 -> V_29 -> V_30 . V_26 ) ;
F_26 ( V_71 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_71 -> V_36 ) {
F_26 ( V_71 -> V_36 -> V_93 . V_26 ) ;
F_26 ( V_71 -> V_36 -> V_37 . V_26 ) ;
}
if ( V_10 . V_91 )
F_28 ( V_71 -> V_94 ) ;
F_29 ( & V_71 -> V_95 . V_96 ) ;
F_30 ( V_71 -> V_23 ) ;
}
return V_71 ;
}
static T_4 F_31 ( const struct V_97 * V_27 )
{
if ( V_10 . V_98 && V_27 == NULL )
return 1 << V_99 ;
return 0 ;
}
static struct V_14 * F_32 ( struct V_1 * V_1 ,
struct V_14 * V_100 ,
struct V_101 * V_102 ,
bool V_89 )
{
struct V_50 * * V_103 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_104 ;
T_2 V_58 = V_100 -> V_73 . V_58 ;
T_2 V_67 = V_100 -> V_73 . V_67 ;
V_103 = & V_1 -> V_105 -> V_50 ;
while ( * V_103 != NULL ) {
V_27 = * V_103 ;
V_71 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_104 = F_33 ( V_71 , V_100 ) ;
if ( ! V_104 ) {
if ( V_89 )
F_15 ( & V_71 -> V_73 , V_58 , V_67 ) ;
if ( V_10 . V_75 )
F_15 ( V_71 -> V_76 , V_58 , V_67 ) ;
F_34 ( & V_100 -> V_36 ) ;
if ( V_71 -> V_17 . V_26 != V_100 -> V_17 . V_26 ) {
F_35 ( V_71 -> V_17 . V_26 ) ;
V_71 -> V_17 . V_26 = F_26 ( V_100 -> V_17 . V_26 ) ;
}
goto V_106;
}
if ( V_104 < 0 )
V_103 = & ( * V_103 ) -> V_107 ;
else
V_103 = & ( * V_103 ) -> V_108 ;
}
V_71 = F_24 ( V_100 , V_89 ) ;
if ( ! V_71 )
return NULL ;
V_1 -> V_83 ++ ;
F_36 ( & V_71 -> V_81 , V_27 , V_103 ) ;
F_37 ( & V_71 -> V_81 , V_1 -> V_105 ) ;
V_106:
if ( V_89 )
F_14 ( & V_71 -> V_73 , V_102 -> V_57 , V_58 ) ;
if ( V_10 . V_75 )
F_14 ( V_71 -> V_76 , V_102 -> V_57 , V_58 ) ;
return V_71 ;
}
struct V_14 * F_38 ( struct V_1 * V_1 ,
struct V_101 * V_102 ,
struct V_97 * V_109 ,
struct V_29 * V_110 ,
struct V_36 * V_111 ,
T_2 V_58 , T_2 V_67 , T_2 V_47 ,
bool V_89 )
{
struct V_14 V_100 = {
. V_23 = V_102 -> V_23 ,
. V_112 = F_39 ( V_102 -> V_23 ) ,
. V_17 = {
. V_26 = V_102 -> V_26 ,
. V_18 = V_102 -> V_18 ,
} ,
. V_113 = V_102 -> V_113 ,
. V_57 = V_102 -> V_57 ,
. V_114 = V_102 -> V_115 ,
. V_87 = V_102 -> V_87 ,
. V_73 = {
. V_68 = 1 ,
. V_58 = V_58 ,
. V_67 = V_67 ,
} ,
. V_27 = V_109 ,
. V_55 = F_31 ( V_109 ) | V_102 -> V_55 ,
. V_1 = V_1 ,
. V_29 = V_110 ,
. V_36 = V_111 ,
. V_47 = V_47 ,
} ;
return F_32 ( V_1 , & V_100 , V_102 , V_89 ) ;
}
static int
F_40 ( struct V_116 * T_6 V_117 ,
struct V_101 * V_102 V_117 )
{
return 0 ;
}
static int
F_41 ( struct V_116 * T_6 V_117 ,
struct V_101 * V_102 V_117 )
{
return 0 ;
}
static int
F_42 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
struct V_118 * V_119 = T_6 -> V_119 ;
struct V_36 * V_111 ;
V_111 = F_43 ( V_119 , V_102 ) ;
if ( V_111 == NULL )
return - V_120 ;
T_6 -> V_121 = V_111 ;
return 0 ;
}
static int
F_44 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
T_2 V_122 ;
struct V_36 * V_111 = T_6 -> V_121 ;
struct V_1 * V_1 = F_45 ( T_6 -> V_123 ) ;
struct V_14 * V_71 ;
if ( V_111 == NULL )
return - V_124 ;
V_122 = T_6 -> V_119 -> V_67 ;
if ( ! V_122 )
V_122 = 1 ;
V_71 = F_38 ( V_1 , V_102 , T_6 -> V_27 , NULL , V_111 ,
V_122 , V_122 , 0 , true ) ;
if ( ! V_71 )
return - V_120 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_46 ( struct V_116 * T_6 ,
struct V_101 * V_102 V_117 )
{
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_1 * V_1 = F_45 ( V_123 ) ;
struct V_14 * V_71 = T_6 -> V_71 ;
int V_126 = - V_124 ;
if ( V_71 == NULL )
goto V_106;
F_47 ( V_1 , V_71 -> V_55 ) ;
V_126 = F_48 ( V_71 , T_6 -> V_119 ) ;
V_106:
T_6 -> V_121 = NULL ;
T_6 -> V_71 = NULL ;
return V_126 ;
}
static int
F_49 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
struct V_29 * V_110 ;
struct V_118 * V_119 = T_6 -> V_119 ;
V_110 = F_50 ( V_119 , V_102 ) ;
if ( ! V_110 )
return - V_120 ;
T_6 -> V_127 = 0 ;
T_6 -> V_128 = V_119 -> V_129 -> V_130 ;
T_6 -> V_121 = V_110 ;
return 0 ;
}
static int
F_51 ( struct V_116 * T_6 V_117 ,
struct V_101 * V_102 V_117 )
{
T_6 -> V_71 = NULL ;
return 0 ;
}
static int
F_52 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
struct V_29 * V_110 = T_6 -> V_121 ;
int V_131 = T_6 -> V_127 ;
if ( V_110 == NULL )
return 0 ;
if ( T_6 -> V_127 >= T_6 -> V_128 )
return 0 ;
V_102 -> V_26 = V_110 [ V_131 ] . V_33 . V_26 ;
V_102 -> V_18 = V_110 [ V_131 ] . V_33 . V_18 ;
V_102 -> V_115 = V_110 [ V_131 ] . V_33 . V_115 ;
return 1 ;
}
static int
F_53 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
struct V_29 * V_110 ;
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_1 * V_1 = F_45 ( V_123 ) ;
struct V_14 * V_71 = NULL ;
int V_131 = T_6 -> V_127 ;
int V_126 = 0 ;
V_110 = T_6 -> V_121 ;
if ( T_6 -> V_132 && ! ( V_110 [ V_131 ] . V_30 . V_18 && V_110 [ V_131 ] . V_33 . V_18 ) )
goto V_106;
V_71 = F_38 ( V_1 , V_102 , T_6 -> V_27 , & V_110 [ V_131 ] , NULL ,
1 , 1 , 0 , true ) ;
if ( V_71 == NULL )
return - V_120 ;
F_47 ( V_1 , V_71 -> V_55 ) ;
V_106:
T_6 -> V_71 = V_71 ;
T_6 -> V_127 ++ ;
return V_126 ;
}
static int
F_54 ( struct V_116 * T_6 ,
struct V_101 * V_102 V_117 )
{
F_34 ( & T_6 -> V_121 ) ;
T_6 -> V_71 = NULL ;
return T_6 -> V_127 >= T_6 -> V_128 ? 0 : - 1 ;
}
static int
F_55 ( struct V_116 * T_6 V_117 ,
struct V_101 * V_102 V_117 )
{
return 0 ;
}
static int
F_56 ( struct V_116 * T_6 , struct V_101 * V_102 )
{
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_118 * V_119 = T_6 -> V_119 ;
struct V_14 * V_71 ;
V_71 = F_38 ( F_45 ( V_123 ) , V_102 , T_6 -> V_27 , NULL , NULL ,
V_119 -> V_58 , V_119 -> V_67 ,
V_119 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_120 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_57 ( struct V_116 * T_6 ,
struct V_101 * V_102 V_117 )
{
struct V_14 * V_71 = T_6 -> V_71 ;
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_118 * V_119 = T_6 -> V_119 ;
if ( V_71 == NULL )
return 0 ;
T_6 -> V_71 = NULL ;
F_47 ( F_45 ( V_123 ) , V_71 -> V_55 ) ;
return F_48 ( V_71 , V_119 ) ;
}
static int
F_58 ( struct V_116 * T_6 V_117 ,
struct V_101 * V_102 V_117 )
{
struct V_14 * * V_133 ;
F_59 ( & V_134 ) ;
V_133 = malloc ( sizeof( * V_133 ) * ( V_135 + 1 ) ) ;
if ( V_133 == NULL )
return - V_120 ;
T_6 -> V_121 = V_133 ;
T_6 -> V_127 = 0 ;
return 0 ;
}
static int
F_60 ( struct V_116 * T_6 ,
struct V_101 * V_102 )
{
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_1 * V_1 = F_45 ( V_123 ) ;
struct V_118 * V_119 = T_6 -> V_119 ;
struct V_14 * * V_133 = T_6 -> V_121 ;
struct V_14 * V_71 ;
int V_126 = 0 ;
V_71 = F_38 ( V_1 , V_102 , T_6 -> V_27 , NULL , NULL ,
V_119 -> V_58 , V_119 -> V_67 ,
V_119 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_120 ;
T_6 -> V_71 = V_71 ;
V_133 [ T_6 -> V_127 ++ ] = V_71 ;
F_48 ( V_71 , V_119 ) ;
F_59 ( & V_134 ) ;
F_47 ( V_1 , V_71 -> V_55 ) ;
return V_126 ;
}
static int
F_61 ( struct V_116 * T_6 ,
struct V_101 * V_102 )
{
struct V_136 * V_96 ;
V_96 = F_62 ( & V_134 ) ;
if ( V_96 == NULL )
return 0 ;
return F_63 ( V_102 , V_96 , T_6 -> V_132 ) ;
}
static int
F_64 ( struct V_116 * T_6 ,
struct V_101 * V_102 )
{
struct V_125 * V_123 = T_6 -> V_123 ;
struct V_118 * V_119 = T_6 -> V_119 ;
struct V_14 * * V_133 = T_6 -> V_121 ;
struct V_14 * V_71 ;
struct V_14 V_137 = {
. V_113 = V_102 -> V_113 ,
. V_23 = V_102 -> V_23 ,
. V_112 = F_39 ( V_102 -> V_23 ) ,
. V_114 = V_102 -> V_115 ,
. V_17 = {
. V_26 = V_102 -> V_26 ,
. V_18 = V_102 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
} ;
int V_131 ;
struct V_134 V_138 ;
F_65 ( & V_138 , & V_134 ) ;
F_66 ( & V_134 ) ;
for ( V_131 = 0 ; V_131 < T_6 -> V_127 ; V_131 ++ ) {
if ( F_33 ( V_133 [ V_131 ] , & V_137 ) == 0 ) {
T_6 -> V_71 = NULL ;
return 0 ;
}
}
V_71 = F_38 ( F_45 ( V_123 ) , V_102 , T_6 -> V_27 , NULL , NULL ,
V_119 -> V_58 , V_119 -> V_67 ,
V_119 -> V_47 , false ) ;
if ( V_71 == NULL )
return - V_120 ;
T_6 -> V_71 = V_71 ;
V_133 [ T_6 -> V_127 ++ ] = V_71 ;
if ( V_10 . V_91 )
F_67 ( V_71 -> V_94 , & V_138 , V_119 -> V_58 ) ;
return 0 ;
}
static int
F_68 ( struct V_116 * T_6 ,
struct V_101 * V_102 V_117 )
{
F_34 ( & T_6 -> V_121 ) ;
T_6 -> V_71 = NULL ;
return 0 ;
}
int F_69 ( struct V_116 * T_6 , struct V_101 * V_102 ,
int V_139 , void * V_140 )
{
int V_126 , V_141 ;
V_126 = F_70 ( T_6 -> V_119 , & T_6 -> V_27 ,
T_6 -> V_123 , V_102 , V_139 ) ;
if ( V_126 )
return V_126 ;
V_126 = T_6 -> V_142 -> V_143 ( T_6 , V_102 ) ;
if ( V_126 )
goto V_106;
V_126 = T_6 -> V_142 -> V_144 ( T_6 , V_102 ) ;
if ( V_126 )
goto V_106;
if ( T_6 -> V_71 && T_6 -> V_145 ) {
V_126 = T_6 -> V_145 ( T_6 , V_102 , true , V_140 ) ;
if ( V_126 )
goto V_106;
}
while ( T_6 -> V_142 -> V_146 ( T_6 , V_102 ) ) {
V_126 = T_6 -> V_142 -> V_147 ( T_6 , V_102 ) ;
if ( V_126 )
break;
if ( T_6 -> V_71 && T_6 -> V_145 ) {
V_126 = T_6 -> V_145 ( T_6 , V_102 , false , V_140 ) ;
if ( V_126 )
goto V_106;
}
}
V_106:
V_141 = T_6 -> V_142 -> V_148 ( T_6 , V_102 ) ;
if ( ! V_126 )
V_126 = V_141 ;
return V_126 ;
}
T_5
F_33 ( struct V_14 * V_149 , struct V_14 * V_150 )
{
struct V_151 * V_152 ;
T_5 V_104 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_152 ) )
continue;
V_104 = V_152 -> V_104 ( V_152 , V_149 , V_150 ) ;
if ( V_104 )
break;
}
return V_104 ;
}
T_5
F_73 ( struct V_14 * V_149 , struct V_14 * V_150 )
{
struct V_151 * V_152 ;
T_5 V_104 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_152 ) )
continue;
V_104 = V_152 -> V_153 ( V_152 , V_149 , V_150 ) ;
if ( V_104 )
break;
}
return V_104 ;
}
void F_21 ( struct V_14 * V_71 )
{
F_74 ( V_71 -> V_23 ) ;
F_27 ( V_71 -> V_17 . V_26 ) ;
if ( V_71 -> V_29 ) {
F_27 ( V_71 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_71 -> V_29 -> V_33 . V_26 ) ;
F_34 ( & V_71 -> V_29 ) ;
}
if ( V_71 -> V_36 ) {
F_27 ( V_71 -> V_36 -> V_93 . V_26 ) ;
F_27 ( V_71 -> V_36 -> V_37 . V_26 ) ;
F_34 ( & V_71 -> V_36 ) ;
}
F_34 ( & V_71 -> V_76 ) ;
F_75 ( V_71 -> V_154 ) ;
F_76 ( V_71 -> V_94 ) ;
free ( V_71 ) ;
}
static bool F_77 ( struct V_1 * V_1 V_117 ,
struct V_155 * V_156 ,
struct V_14 * V_71 )
{
struct V_50 * * V_103 = & V_156 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_104 ;
while ( * V_103 != NULL ) {
V_27 = * V_103 ;
T_6 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_104 = F_73 ( T_6 , V_71 ) ;
if ( ! V_104 ) {
F_16 ( & T_6 -> V_73 , & V_71 -> V_73 ) ;
if ( V_10 . V_75 )
F_16 ( T_6 -> V_76 , V_71 -> V_76 ) ;
if ( V_10 . V_91 ) {
F_78 ( & V_134 ) ;
F_79 ( & V_134 ,
T_6 -> V_94 ,
V_71 -> V_94 ) ;
}
F_21 ( V_71 ) ;
return false ;
}
if ( V_104 < 0 )
V_103 = & ( * V_103 ) -> V_107 ;
else
V_103 = & ( * V_103 ) -> V_108 ;
}
V_1 -> V_83 ++ ;
F_36 ( & V_71 -> V_81 , V_27 , V_103 ) ;
F_37 ( & V_71 -> V_81 , V_156 ) ;
return true ;
}
static struct V_155 * F_80 ( struct V_1 * V_1 )
{
struct V_155 * V_156 ;
F_81 ( & V_1 -> V_157 ) ;
V_156 = V_1 -> V_105 ;
if ( ++ V_1 -> V_105 > & V_1 -> V_158 [ 1 ] )
V_1 -> V_105 = & V_1 -> V_158 [ 0 ] ;
F_82 ( & V_1 -> V_157 ) ;
return V_156 ;
}
static void F_83 ( struct V_1 * V_1 , struct V_14 * V_71 )
{
F_84 ( V_1 , V_71 ) ;
F_85 ( V_1 , V_71 ) ;
F_86 ( V_1 , V_71 ) ;
}
void F_87 ( struct V_1 * V_1 , struct V_159 * V_160 )
{
struct V_155 * V_156 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
if ( ! V_80 )
return;
V_1 -> V_83 = 0 ;
V_156 = F_80 ( V_1 ) ;
V_51 = F_11 ( V_156 ) ;
while ( V_51 ) {
if ( F_88 () )
break;
V_53 = F_12 ( V_51 , struct V_14 , V_81 ) ;
V_51 = F_13 ( & V_53 -> V_81 ) ;
F_20 ( & V_53 -> V_81 , V_156 ) ;
if ( F_77 ( V_1 , & V_1 -> V_82 , V_53 ) ) {
F_83 ( V_1 , V_53 ) ;
}
if ( V_160 )
F_89 ( V_160 , 1 ) ;
}
}
static int F_90 ( struct V_14 * V_161 , struct V_14 * V_162 )
{
struct V_151 * V_152 ;
T_5 V_104 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_152 ) )
continue;
V_104 = V_152 -> V_163 ( V_152 , V_161 , V_162 ) ;
if ( V_104 )
break;
}
return V_104 ;
}
static void F_91 ( struct V_1 * V_1 )
{
V_1 -> V_84 = 0 ;
V_1 -> V_77 . V_79 = 0 ;
}
void F_92 ( struct V_1 * V_1 )
{
V_1 -> V_83 = 0 ;
V_1 -> V_77 . V_78 = 0 ;
F_91 ( V_1 ) ;
}
static void F_93 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_84 ++ ;
V_1 -> V_77 . V_79 += V_15 -> V_73 . V_58 ;
}
void F_94 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_55 )
F_93 ( V_1 , V_15 ) ;
V_1 -> V_83 ++ ;
V_1 -> V_77 . V_78 += V_15 -> V_73 . V_58 ;
}
static void F_95 ( struct V_155 * V_52 ,
struct V_14 * V_71 ,
T_2 V_164 )
{
struct V_50 * * V_103 = & V_52 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_10 . V_91 )
V_165 . V_163 ( & V_71 -> V_166 , V_71 -> V_94 ,
V_164 , & V_165 ) ;
while ( * V_103 != NULL ) {
V_27 = * V_103 ;
T_6 = F_12 ( V_27 , struct V_14 , V_50 ) ;
if ( F_90 ( V_71 , T_6 ) > 0 )
V_103 = & ( * V_103 ) -> V_107 ;
else
V_103 = & ( * V_103 ) -> V_108 ;
}
F_36 ( & V_71 -> V_50 , V_27 , V_103 ) ;
F_37 ( & V_71 -> V_50 , V_52 ) ;
}
void F_96 ( struct V_1 * V_1 , struct V_159 * V_160 )
{
struct V_155 * V_156 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
T_2 V_164 ;
V_164 = V_1 -> V_77 . V_78 * ( V_165 . V_167 / 100 ) ;
if ( V_80 )
V_156 = & V_1 -> V_82 ;
else
V_156 = V_1 -> V_105 ;
V_51 = F_11 ( V_156 ) ;
V_1 -> V_52 = V_168 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_81 ) ;
V_51 = F_13 ( & V_53 -> V_81 ) ;
F_95 ( & V_1 -> V_52 , V_53 , V_164 ) ;
F_94 ( V_1 , V_53 ) ;
if ( ! V_53 -> V_55 )
F_6 ( V_1 , V_53 ) ;
if ( V_160 )
F_89 ( V_160 , 1 ) ;
}
}
static void F_97 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_169 V_170 )
{
V_15 -> V_55 &= ~ ( 1 << V_170 ) ;
if ( V_15 -> V_55 )
return;
V_15 -> V_171 = false ;
V_15 -> V_172 = 0 ;
V_15 -> V_173 = 0 ;
V_1 -> V_77 . V_174 += V_15 -> V_73 . V_68 ;
F_93 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_84 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_175 != NULL &&
( V_71 -> V_17 . V_26 == NULL || V_71 -> V_17 . V_26 -> V_7 != V_1 -> V_175 ) ) {
V_71 -> V_55 |= ( 1 << V_176 ) ;
return true ;
}
return false ;
}
void F_98 ( struct V_1 * V_1 )
{
struct V_50 * V_177 ;
V_1 -> V_77 . V_174 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_177 = F_11 ( & V_1 -> V_52 ) ; V_177 ; V_177 = F_13 ( V_177 ) ) {
struct V_14 * V_15 = F_12 ( V_177 , struct V_14 , V_50 ) ;
if ( V_10 . V_98 && ! V_15 -> V_27 )
continue;
if ( F_84 ( V_1 , V_15 ) )
continue;
F_97 ( V_1 , V_15 , V_176 ) ;
}
}
static bool F_85 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_178 != NULL &&
V_71 -> V_23 != V_1 -> V_178 ) {
V_71 -> V_55 |= ( 1 << V_179 ) ;
return true ;
}
return false ;
}
void F_99 ( struct V_1 * V_1 )
{
struct V_50 * V_177 ;
V_1 -> V_77 . V_174 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_177 = F_11 ( & V_1 -> V_52 ) ; V_177 ; V_177 = F_13 ( V_177 ) ) {
struct V_14 * V_15 = F_12 ( V_177 , struct V_14 , V_50 ) ;
if ( F_85 ( V_1 , V_15 ) )
continue;
F_97 ( V_1 , V_15 , V_179 ) ;
}
}
static bool F_86 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_180 != NULL &&
( ! V_71 -> V_17 . V_18 || strstr ( V_71 -> V_17 . V_18 -> V_181 ,
V_1 -> V_180 ) == NULL ) ) {
V_71 -> V_55 |= ( 1 << V_182 ) ;
return true ;
}
return false ;
}
void F_100 ( struct V_1 * V_1 )
{
struct V_50 * V_177 ;
V_1 -> V_77 . V_174 = 0 ;
F_91 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_177 = F_11 ( & V_1 -> V_52 ) ; V_177 ; V_177 = F_13 ( V_177 ) ) {
struct V_14 * V_15 = F_12 ( V_177 , struct V_14 , V_50 ) ;
if ( F_86 ( V_1 , V_15 ) )
continue;
F_97 ( V_1 , V_15 , V_182 ) ;
}
}
void F_101 ( struct V_183 * V_77 , T_7 type )
{
++ V_77 -> V_68 [ 0 ] ;
++ V_77 -> V_68 [ type ] ;
}
void F_102 ( struct V_1 * V_1 , T_7 type )
{
F_101 ( & V_1 -> V_77 , type ) ;
}
void F_47 ( struct V_1 * V_1 , bool V_55 )
{
F_101 ( & V_1 -> V_77 , V_184 ) ;
if ( ! V_55 )
V_1 -> V_77 . V_174 ++ ;
}
static struct V_14 * F_103 ( struct V_1 * V_1 ,
struct V_14 * V_185 )
{
struct V_155 * V_156 ;
struct V_50 * * V_103 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_104 ;
if ( V_80 )
V_156 = & V_1 -> V_82 ;
else
V_156 = V_1 -> V_105 ;
V_103 = & V_156 -> V_50 ;
while ( * V_103 != NULL ) {
V_27 = * V_103 ;
V_71 = F_12 ( V_27 , struct V_14 , V_81 ) ;
V_104 = F_73 ( V_71 , V_185 ) ;
if ( ! V_104 )
goto V_106;
if ( V_104 < 0 )
V_103 = & ( * V_103 ) -> V_107 ;
else
V_103 = & ( * V_103 ) -> V_108 ;
}
V_71 = F_24 ( V_185 , true ) ;
if ( V_71 ) {
memset ( & V_71 -> V_73 , 0 , sizeof( V_71 -> V_73 ) ) ;
V_71 -> V_1 = V_1 ;
F_36 ( & V_71 -> V_81 , V_27 , V_103 ) ;
F_37 ( & V_71 -> V_81 , V_156 ) ;
F_94 ( V_1 , V_71 ) ;
V_71 -> V_186 = true ;
}
V_106:
return V_71 ;
}
static struct V_14 * F_104 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
struct V_50 * V_53 ;
if ( V_80 )
V_53 = V_1 -> V_82 . V_50 ;
else
V_53 = V_1 -> V_105 -> V_50 ;
while ( V_53 ) {
struct V_14 * T_6 = F_12 ( V_53 , struct V_14 , V_81 ) ;
T_5 V_104 = F_73 ( T_6 , V_71 ) ;
if ( V_104 < 0 )
V_53 = V_53 -> V_107 ;
else if ( V_104 > 0 )
V_53 = V_53 -> V_108 ;
else
return T_6 ;
}
return NULL ;
}
void F_105 ( struct V_1 * V_187 , struct V_1 * V_188 )
{
struct V_155 * V_156 ;
struct V_50 * V_177 ;
struct V_14 * V_189 , * V_185 ;
if ( V_80 )
V_156 = & V_187 -> V_82 ;
else
V_156 = V_187 -> V_105 ;
for ( V_177 = F_11 ( V_156 ) ; V_177 ; V_177 = F_13 ( V_177 ) ) {
V_189 = F_12 ( V_177 , struct V_14 , V_81 ) ;
V_185 = F_104 ( V_188 , V_189 ) ;
if ( V_185 )
F_106 ( V_185 , V_189 ) ;
}
}
int F_107 ( struct V_1 * V_187 , struct V_1 * V_188 )
{
struct V_155 * V_156 ;
struct V_50 * V_177 ;
struct V_14 * V_189 , * V_185 ;
if ( V_80 )
V_156 = & V_188 -> V_82 ;
else
V_156 = V_188 -> V_105 ;
for ( V_177 = F_11 ( V_156 ) ; V_177 ; V_177 = F_13 ( V_177 ) ) {
V_189 = F_12 ( V_177 , struct V_14 , V_81 ) ;
if ( ! F_108 ( V_189 ) ) {
V_185 = F_103 ( V_187 , V_189 ) ;
if ( V_185 == NULL )
return - 1 ;
F_106 ( V_189 , V_185 ) ;
}
}
return 0 ;
}
T_3 F_109 ( struct V_190 * V_191 , T_8 * V_192 )
{
struct V_125 * V_189 ;
T_3 V_193 = 0 ;
F_110 (evlist, pos) {
V_193 += fprintf ( V_192 , L_1 , F_111 ( V_189 ) ) ;
V_193 += F_112 ( & F_45 ( V_189 ) -> V_77 , V_192 ) ;
}
return V_193 ;
}
T_2 F_113 ( struct V_1 * V_1 )
{
return V_10 . V_194 ? V_1 -> V_77 . V_79 :
V_1 -> V_77 . V_78 ;
}
int F_114 ( const struct V_195 * T_9 V_117 ,
const char * V_140 , int T_10 V_117 )
{
if ( ! strcmp ( V_140 , L_2 ) )
V_10 . V_194 = true ;
else if ( ! strcmp ( V_140 , L_3 ) )
V_10 . V_194 = false ;
else
return - 1 ;
return 0 ;
}
int F_115 ( const char * V_196 , const char * V_197 )
{
if ( ! strcmp ( V_196 , L_4 ) )
return F_114 ( NULL , V_197 , 0 ) ;
return 0 ;
}
static int F_116 ( struct V_125 * V_123 )
{
struct V_1 * V_1 = F_45 ( V_123 ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_158 [ 0 ] = V_1 -> V_158 [ 1 ] = V_168 ;
V_1 -> V_105 = & V_1 -> V_158 [ 0 ] ;
V_1 -> V_82 = V_168 ;
V_1 -> V_52 = V_168 ;
F_117 ( & V_1 -> V_157 , NULL ) ;
return 0 ;
}
int F_118 ( void )
{
int V_126 = F_119 ( sizeof( struct V_198 ) ,
F_116 , NULL ) ;
if ( V_126 )
fputs ( L_5 , V_199 ) ;
return V_126 ;
}
