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
void F_19 ( struct V_1 * V_1 , bool V_80 , bool V_81 )
{
struct V_50 * V_51 = F_11 ( & V_1 -> V_52 ) ;
struct V_14 * V_53 ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_50 ) ;
V_51 = F_13 ( & V_53 -> V_50 ) ;
if ( ( ( V_80 && V_53 -> V_82 == '.' ) ||
( V_81 && V_53 -> V_82 != '.' ) ||
F_18 ( V_1 , V_53 ) ) &&
! V_53 -> V_83 ) {
F_20 ( & V_53 -> V_50 , & V_1 -> V_52 ) ;
if ( V_84 )
F_20 ( & V_53 -> V_85 , & V_1 -> V_86 ) ;
-- V_1 -> V_87 ;
if ( ! V_53 -> V_55 )
-- V_1 -> V_88 ;
F_21 ( V_53 ) ;
}
}
}
static struct V_14 * F_22 ( struct V_14 * V_89 ,
bool V_90 )
{
T_3 V_91 = 0 ;
struct V_14 * V_71 ;
if ( V_10 . V_92 || V_10 . V_75 )
V_91 = sizeof( struct V_93 ) ;
V_71 = F_23 ( sizeof( * V_71 ) + V_91 ) ;
if ( V_71 != NULL ) {
* V_71 = * V_89 ;
if ( V_10 . V_75 ) {
V_71 -> V_76 = malloc ( sizeof( V_71 -> V_73 ) ) ;
if ( V_71 -> V_76 == NULL ) {
free ( V_71 ) ;
return NULL ;
}
memcpy ( V_71 -> V_76 , & V_71 -> V_73 , sizeof( V_71 -> V_73 ) ) ;
if ( ! V_90 )
memset ( & V_71 -> V_73 , 0 , sizeof( V_71 -> V_73 ) ) ;
}
if ( V_71 -> V_17 . V_26 )
V_71 -> V_17 . V_26 -> V_94 = true ;
if ( V_71 -> V_29 ) {
V_71 -> V_29 = malloc ( sizeof( * V_71 -> V_29 ) ) ;
if ( V_71 -> V_29 == NULL ) {
free ( V_71 -> V_76 ) ;
free ( V_71 ) ;
return NULL ;
}
memcpy ( V_71 -> V_29 , V_89 -> V_29 ,
sizeof( * V_71 -> V_29 ) ) ;
if ( V_71 -> V_29 -> V_30 . V_26 )
V_71 -> V_29 -> V_30 . V_26 -> V_94 = true ;
if ( V_71 -> V_29 -> V_33 . V_26 )
V_71 -> V_29 -> V_33 . V_26 -> V_94 = true ;
}
if ( V_71 -> V_36 ) {
if ( V_71 -> V_36 -> V_95 . V_26 )
V_71 -> V_36 -> V_95 . V_26 -> V_94 = true ;
if ( V_71 -> V_36 -> V_37 . V_26 )
V_71 -> V_36 -> V_37 . V_26 -> V_94 = true ;
}
if ( V_10 . V_92 )
F_24 ( V_71 -> V_96 ) ;
F_25 ( & V_71 -> V_97 . V_98 ) ;
}
return V_71 ;
}
static T_4 F_26 ( const struct V_99 * V_27 )
{
if ( V_10 . V_100 && V_27 == NULL )
return 1 << V_101 ;
return 0 ;
}
static struct V_14 * F_27 ( struct V_1 * V_1 ,
struct V_14 * V_102 ,
struct V_103 * V_104 ,
bool V_90 )
{
struct V_50 * * V_105 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_106 ;
T_2 V_58 = V_102 -> V_73 . V_58 ;
T_2 V_67 = V_102 -> V_73 . V_67 ;
V_105 = & V_1 -> V_107 -> V_50 ;
while ( * V_105 != NULL ) {
V_27 = * V_105 ;
V_71 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_106 = F_28 ( V_71 , V_102 ) ;
if ( ! V_106 ) {
if ( V_90 )
F_15 ( & V_71 -> V_73 , V_58 , V_67 ) ;
if ( V_10 . V_75 )
F_15 ( V_71 -> V_76 , V_58 , V_67 ) ;
F_29 ( & V_102 -> V_36 ) ;
if ( V_71 -> V_17 . V_26 != V_102 -> V_17 . V_26 ) {
V_71 -> V_17 . V_26 = V_102 -> V_17 . V_26 ;
if ( V_71 -> V_17 . V_26 )
V_71 -> V_17 . V_26 -> V_94 = true ;
}
goto V_108;
}
if ( V_106 < 0 )
V_105 = & ( * V_105 ) -> V_109 ;
else
V_105 = & ( * V_105 ) -> V_110 ;
}
V_71 = F_22 ( V_102 , V_90 ) ;
if ( ! V_71 )
return NULL ;
F_30 ( & V_71 -> V_85 , V_27 , V_105 ) ;
F_31 ( & V_71 -> V_85 , V_1 -> V_107 ) ;
V_108:
if ( V_90 )
F_14 ( & V_71 -> V_73 , V_104 -> V_57 , V_58 ) ;
if ( V_10 . V_75 )
F_14 ( V_71 -> V_76 , V_104 -> V_57 , V_58 ) ;
return V_71 ;
}
struct V_14 * F_32 ( struct V_1 * V_1 ,
struct V_103 * V_104 ,
struct V_99 * V_111 ,
struct V_29 * V_112 ,
struct V_36 * V_113 ,
T_2 V_58 , T_2 V_67 , T_2 V_47 ,
bool V_90 )
{
struct V_14 V_102 = {
. V_23 = V_104 -> V_23 ,
. V_114 = F_33 ( V_104 -> V_23 ) ,
. V_17 = {
. V_26 = V_104 -> V_26 ,
. V_18 = V_104 -> V_18 ,
} ,
. V_115 = V_104 -> V_115 ,
. V_57 = V_104 -> V_57 ,
. V_116 = V_104 -> V_117 ,
. V_82 = V_104 -> V_82 ,
. V_73 = {
. V_68 = 1 ,
. V_58 = V_58 ,
. V_67 = V_67 ,
} ,
. V_27 = V_111 ,
. V_55 = F_26 ( V_111 ) | V_104 -> V_55 ,
. V_1 = V_1 ,
. V_29 = V_112 ,
. V_36 = V_113 ,
. V_47 = V_47 ,
} ;
return F_27 ( V_1 , & V_102 , V_104 , V_90 ) ;
}
static int
F_34 ( struct V_118 * T_6 V_119 ,
struct V_103 * V_104 V_119 )
{
return 0 ;
}
static int
F_35 ( struct V_118 * T_6 V_119 ,
struct V_103 * V_104 V_119 )
{
return 0 ;
}
static int
F_36 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
struct V_120 * V_121 = T_6 -> V_121 ;
struct V_36 * V_113 ;
V_113 = F_37 ( V_121 , V_104 ) ;
if ( V_113 == NULL )
return - V_122 ;
T_6 -> V_123 = V_113 ;
return 0 ;
}
static int
F_38 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
T_2 V_124 ;
struct V_36 * V_113 = T_6 -> V_123 ;
struct V_14 * V_71 ;
if ( V_113 == NULL )
return - V_125 ;
V_124 = T_6 -> V_121 -> V_67 ;
if ( ! V_124 )
V_124 = 1 ;
V_71 = F_32 ( & T_6 -> V_126 -> V_1 , V_104 , T_6 -> V_27 , NULL , V_113 ,
V_124 , V_124 , 0 , true ) ;
if ( ! V_71 )
return - V_122 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_39 ( struct V_118 * T_6 ,
struct V_103 * V_104 V_119 )
{
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_14 * V_71 = T_6 -> V_71 ;
int V_128 = - V_125 ;
if ( V_71 == NULL )
goto V_108;
F_40 ( & V_126 -> V_1 , V_71 -> V_55 ) ;
V_128 = F_41 ( V_71 , T_6 -> V_121 ) ;
V_108:
T_6 -> V_123 = NULL ;
T_6 -> V_71 = NULL ;
return V_128 ;
}
static int
F_42 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
struct V_29 * V_112 ;
struct V_120 * V_121 = T_6 -> V_121 ;
V_112 = F_43 ( V_121 , V_104 ) ;
if ( ! V_112 )
return - V_122 ;
T_6 -> V_129 = 0 ;
T_6 -> V_130 = V_121 -> V_131 -> V_132 ;
T_6 -> V_123 = V_112 ;
return 0 ;
}
static int
F_44 ( struct V_118 * T_6 V_119 ,
struct V_103 * V_104 V_119 )
{
T_6 -> V_71 = NULL ;
return 0 ;
}
static int
F_45 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
struct V_29 * V_112 = T_6 -> V_123 ;
int V_133 = T_6 -> V_129 ;
if ( V_112 == NULL )
return 0 ;
if ( T_6 -> V_129 >= T_6 -> V_130 )
return 0 ;
V_104 -> V_26 = V_112 [ V_133 ] . V_33 . V_26 ;
V_104 -> V_18 = V_112 [ V_133 ] . V_33 . V_18 ;
V_104 -> V_117 = V_112 [ V_133 ] . V_33 . V_117 ;
return 1 ;
}
static int
F_46 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
struct V_29 * V_112 ;
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_14 * V_71 = NULL ;
int V_133 = T_6 -> V_129 ;
int V_128 = 0 ;
V_112 = T_6 -> V_123 ;
if ( T_6 -> V_134 && ! ( V_112 [ V_133 ] . V_30 . V_18 && V_112 [ V_133 ] . V_33 . V_18 ) )
goto V_108;
V_71 = F_32 ( & V_126 -> V_1 , V_104 , T_6 -> V_27 , & V_112 [ V_133 ] , NULL ,
1 , 1 , 0 , true ) ;
if ( V_71 == NULL )
return - V_122 ;
F_40 ( & V_126 -> V_1 , V_71 -> V_55 ) ;
V_108:
T_6 -> V_71 = V_71 ;
T_6 -> V_129 ++ ;
return V_128 ;
}
static int
F_47 ( struct V_118 * T_6 ,
struct V_103 * V_104 V_119 )
{
F_29 ( & T_6 -> V_123 ) ;
T_6 -> V_71 = NULL ;
return T_6 -> V_129 >= T_6 -> V_130 ? 0 : - 1 ;
}
static int
F_48 ( struct V_118 * T_6 V_119 ,
struct V_103 * V_104 V_119 )
{
return 0 ;
}
static int
F_49 ( struct V_118 * T_6 , struct V_103 * V_104 )
{
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_120 * V_121 = T_6 -> V_121 ;
struct V_14 * V_71 ;
V_71 = F_32 ( & V_126 -> V_1 , V_104 , T_6 -> V_27 , NULL , NULL ,
V_121 -> V_58 , V_121 -> V_67 ,
V_121 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_122 ;
T_6 -> V_71 = V_71 ;
return 0 ;
}
static int
F_50 ( struct V_118 * T_6 ,
struct V_103 * V_104 V_119 )
{
struct V_14 * V_71 = T_6 -> V_71 ;
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_120 * V_121 = T_6 -> V_121 ;
if ( V_71 == NULL )
return 0 ;
T_6 -> V_71 = NULL ;
F_40 ( & V_126 -> V_1 , V_71 -> V_55 ) ;
return F_41 ( V_71 , V_121 ) ;
}
static int
F_51 ( struct V_118 * T_6 V_119 ,
struct V_103 * V_104 V_119 )
{
struct V_14 * * V_135 ;
F_52 ( & V_136 ) ;
V_135 = malloc ( sizeof( * V_135 ) * ( V_137 + 1 ) ) ;
if ( V_135 == NULL )
return - V_122 ;
T_6 -> V_123 = V_135 ;
T_6 -> V_129 = 0 ;
return 0 ;
}
static int
F_53 ( struct V_118 * T_6 ,
struct V_103 * V_104 )
{
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_120 * V_121 = T_6 -> V_121 ;
struct V_14 * * V_135 = T_6 -> V_123 ;
struct V_14 * V_71 ;
int V_128 = 0 ;
V_71 = F_32 ( & V_126 -> V_1 , V_104 , T_6 -> V_27 , NULL , NULL ,
V_121 -> V_58 , V_121 -> V_67 ,
V_121 -> V_47 , true ) ;
if ( V_71 == NULL )
return - V_122 ;
T_6 -> V_71 = V_71 ;
V_135 [ T_6 -> V_129 ++ ] = V_71 ;
F_54 ( V_71 -> V_96 , & V_136 , V_121 -> V_58 ) ;
F_52 ( & V_136 ) ;
F_40 ( & V_126 -> V_1 , V_71 -> V_55 ) ;
return V_128 ;
}
static int
F_55 ( struct V_118 * T_6 ,
struct V_103 * V_104 )
{
struct V_138 * V_98 ;
V_98 = F_56 ( & V_136 ) ;
if ( V_98 == NULL )
return 0 ;
return F_57 ( V_104 , V_98 , T_6 -> V_134 ) ;
}
static int
F_58 ( struct V_118 * T_6 ,
struct V_103 * V_104 )
{
struct V_127 * V_126 = T_6 -> V_126 ;
struct V_120 * V_121 = T_6 -> V_121 ;
struct V_14 * * V_135 = T_6 -> V_123 ;
struct V_14 * V_71 ;
struct V_14 V_139 = {
. V_115 = V_104 -> V_115 ,
. V_23 = V_104 -> V_23 ,
. V_114 = F_33 ( V_104 -> V_23 ) ,
. V_116 = V_104 -> V_117 ,
. V_17 = {
. V_26 = V_104 -> V_26 ,
. V_18 = V_104 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
} ;
int V_133 ;
struct V_136 V_140 ;
F_59 ( & V_140 , & V_136 ) ;
F_60 ( & V_136 ) ;
for ( V_133 = 0 ; V_133 < T_6 -> V_129 ; V_133 ++ ) {
if ( F_28 ( V_135 [ V_133 ] , & V_139 ) == 0 ) {
T_6 -> V_71 = NULL ;
return 0 ;
}
}
V_71 = F_32 ( & V_126 -> V_1 , V_104 , T_6 -> V_27 , NULL , NULL ,
V_121 -> V_58 , V_121 -> V_67 ,
V_121 -> V_47 , false ) ;
if ( V_71 == NULL )
return - V_122 ;
T_6 -> V_71 = V_71 ;
V_135 [ T_6 -> V_129 ++ ] = V_71 ;
F_54 ( V_71 -> V_96 , & V_140 , V_121 -> V_58 ) ;
return 0 ;
}
static int
F_61 ( struct V_118 * T_6 ,
struct V_103 * V_104 V_119 )
{
F_29 ( & T_6 -> V_123 ) ;
T_6 -> V_71 = NULL ;
return 0 ;
}
int F_62 ( struct V_118 * T_6 , struct V_103 * V_104 ,
struct V_127 * V_126 , struct V_120 * V_121 ,
int V_141 , void * V_142 )
{
int V_128 , V_143 ;
V_128 = F_63 ( V_121 , & T_6 -> V_27 , V_126 , V_104 ,
V_141 ) ;
if ( V_128 )
return V_128 ;
T_6 -> V_126 = V_126 ;
T_6 -> V_121 = V_121 ;
V_128 = T_6 -> V_144 -> V_145 ( T_6 , V_104 ) ;
if ( V_128 )
goto V_108;
V_128 = T_6 -> V_144 -> V_146 ( T_6 , V_104 ) ;
if ( V_128 )
goto V_108;
if ( T_6 -> V_71 && T_6 -> V_147 ) {
V_128 = T_6 -> V_147 ( T_6 , V_104 , true , V_142 ) ;
if ( V_128 )
goto V_108;
}
while ( T_6 -> V_144 -> V_148 ( T_6 , V_104 ) ) {
V_128 = T_6 -> V_144 -> V_149 ( T_6 , V_104 ) ;
if ( V_128 )
break;
if ( T_6 -> V_71 && T_6 -> V_147 ) {
V_128 = T_6 -> V_147 ( T_6 , V_104 , false , V_142 ) ;
if ( V_128 )
goto V_108;
}
}
V_108:
V_143 = T_6 -> V_144 -> V_150 ( T_6 , V_104 ) ;
if ( ! V_128 )
V_128 = V_143 ;
return V_128 ;
}
T_5
F_28 ( struct V_14 * V_151 , struct V_14 * V_152 )
{
struct V_153 * V_154 ;
T_5 V_106 = 0 ;
F_64 (fmt) {
if ( F_65 ( V_154 ) )
continue;
V_106 = V_154 -> V_106 ( V_151 , V_152 ) ;
if ( V_106 )
break;
}
return V_106 ;
}
T_5
F_66 ( struct V_14 * V_151 , struct V_14 * V_152 )
{
struct V_153 * V_154 ;
T_5 V_106 = 0 ;
F_64 (fmt) {
if ( F_65 ( V_154 ) )
continue;
V_106 = V_154 -> V_155 ( V_151 , V_152 ) ;
if ( V_106 )
break;
}
return V_106 ;
}
void F_21 ( struct V_14 * V_71 )
{
F_29 ( & V_71 -> V_29 ) ;
F_29 ( & V_71 -> V_36 ) ;
F_29 ( & V_71 -> V_76 ) ;
F_67 ( V_71 -> V_156 ) ;
free ( V_71 ) ;
}
static bool F_68 ( struct V_1 * V_1 V_119 ,
struct V_157 * V_158 ,
struct V_14 * V_71 )
{
struct V_50 * * V_105 = & V_158 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_106 ;
while ( * V_105 != NULL ) {
V_27 = * V_105 ;
T_6 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_106 = F_66 ( T_6 , V_71 ) ;
if ( ! V_106 ) {
F_16 ( & T_6 -> V_73 , & V_71 -> V_73 ) ;
if ( V_10 . V_75 )
F_16 ( T_6 -> V_76 , V_71 -> V_76 ) ;
if ( V_10 . V_92 ) {
F_69 ( & V_136 ) ;
F_70 ( & V_136 ,
T_6 -> V_96 ,
V_71 -> V_96 ) ;
}
F_21 ( V_71 ) ;
return false ;
}
if ( V_106 < 0 )
V_105 = & ( * V_105 ) -> V_109 ;
else
V_105 = & ( * V_105 ) -> V_110 ;
}
F_30 ( & V_71 -> V_85 , V_27 , V_105 ) ;
F_31 ( & V_71 -> V_85 , V_158 ) ;
return true ;
}
static struct V_157 * F_71 ( struct V_1 * V_1 )
{
struct V_157 * V_158 ;
F_72 ( & V_1 -> V_159 ) ;
V_158 = V_1 -> V_107 ;
if ( ++ V_1 -> V_107 > & V_1 -> V_160 [ 1 ] )
V_1 -> V_107 = & V_1 -> V_160 [ 0 ] ;
F_73 ( & V_1 -> V_159 ) ;
return V_158 ;
}
static void F_74 ( struct V_1 * V_1 , struct V_14 * V_71 )
{
F_75 ( V_1 , V_71 ) ;
F_76 ( V_1 , V_71 ) ;
F_77 ( V_1 , V_71 ) ;
}
void F_78 ( struct V_1 * V_1 , struct V_161 * V_162 )
{
struct V_157 * V_158 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
if ( ! V_84 )
return;
V_158 = F_71 ( V_1 ) ;
V_51 = F_11 ( V_158 ) ;
while ( V_51 ) {
if ( F_79 () )
break;
V_53 = F_12 ( V_51 , struct V_14 , V_85 ) ;
V_51 = F_13 ( & V_53 -> V_85 ) ;
F_20 ( & V_53 -> V_85 , V_158 ) ;
if ( F_68 ( V_1 , & V_1 -> V_86 , V_53 ) ) {
F_74 ( V_1 , V_53 ) ;
}
if ( V_162 )
F_80 ( V_162 , 1 ) ;
}
}
static int F_81 ( struct V_14 * V_163 , struct V_14 * V_164 )
{
struct V_153 * V_154 ;
T_5 V_106 = 0 ;
F_64 (fmt) {
if ( F_65 ( V_154 ) )
continue;
V_106 = V_154 -> V_165 ( V_163 , V_164 ) ;
if ( V_106 )
break;
}
return V_106 ;
}
static void F_82 ( struct V_1 * V_1 )
{
V_1 -> V_88 = 0 ;
V_1 -> V_77 . V_79 = 0 ;
}
void F_83 ( struct V_1 * V_1 )
{
V_1 -> V_87 = 0 ;
V_1 -> V_77 . V_78 = 0 ;
F_82 ( V_1 ) ;
}
static void F_84 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_88 ++ ;
V_1 -> V_77 . V_79 += V_15 -> V_73 . V_58 ;
}
void F_85 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_55 )
F_84 ( V_1 , V_15 ) ;
V_1 -> V_87 ++ ;
V_1 -> V_77 . V_78 += V_15 -> V_73 . V_58 ;
}
static void F_86 ( struct V_157 * V_52 ,
struct V_14 * V_71 ,
T_2 V_166 )
{
struct V_50 * * V_105 = & V_52 -> V_50 ;
struct V_50 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_10 . V_92 )
V_167 . V_165 ( & V_71 -> V_168 , V_71 -> V_96 ,
V_166 , & V_167 ) ;
while ( * V_105 != NULL ) {
V_27 = * V_105 ;
T_6 = F_12 ( V_27 , struct V_14 , V_50 ) ;
if ( F_81 ( V_71 , T_6 ) > 0 )
V_105 = & ( * V_105 ) -> V_109 ;
else
V_105 = & ( * V_105 ) -> V_110 ;
}
F_30 ( & V_71 -> V_50 , V_27 , V_105 ) ;
F_31 ( & V_71 -> V_50 , V_52 ) ;
}
void F_87 ( struct V_1 * V_1 )
{
struct V_157 * V_158 ;
struct V_50 * V_51 ;
struct V_14 * V_53 ;
T_2 V_166 ;
V_166 = V_1 -> V_77 . V_78 * ( V_167 . V_169 / 100 ) ;
if ( V_84 )
V_158 = & V_1 -> V_86 ;
else
V_158 = V_1 -> V_107 ;
V_51 = F_11 ( V_158 ) ;
V_1 -> V_52 = V_170 ;
F_83 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_51 ) {
V_53 = F_12 ( V_51 , struct V_14 , V_85 ) ;
V_51 = F_13 ( & V_53 -> V_85 ) ;
F_86 ( & V_1 -> V_52 , V_53 , V_166 ) ;
F_85 ( V_1 , V_53 ) ;
if ( ! V_53 -> V_55 )
F_6 ( V_1 , V_53 ) ;
}
}
static void F_88 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_171 V_172 )
{
V_15 -> V_55 &= ~ ( 1 << V_172 ) ;
if ( V_15 -> V_55 )
return;
V_15 -> V_17 . V_173 = false ;
V_15 -> V_174 = 0 ;
V_1 -> V_77 . V_175 += V_15 -> V_73 . V_68 ;
F_84 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_75 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_176 != NULL &&
( V_71 -> V_17 . V_26 == NULL || V_71 -> V_17 . V_26 -> V_7 != V_1 -> V_176 ) ) {
V_71 -> V_55 |= ( 1 << V_177 ) ;
return true ;
}
return false ;
}
void F_89 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_82 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( V_10 . V_100 && ! V_15 -> V_27 )
continue;
if ( F_75 ( V_1 , V_15 ) )
continue;
F_88 ( V_1 , V_15 , V_177 ) ;
}
}
static bool F_76 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
if ( V_1 -> V_179 != NULL &&
V_71 -> V_23 != V_1 -> V_179 ) {
V_71 -> V_55 |= ( 1 << V_180 ) ;
return true ;
}
return false ;
}
void F_90 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_82 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( F_76 ( V_1 , V_15 ) )
continue;
F_88 ( V_1 , V_15 , V_180 ) ;
}
}
static bool F_77 ( struct V_1 * V_1 ,
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
void F_91 ( struct V_1 * V_1 )
{
struct V_50 * V_178 ;
V_1 -> V_77 . V_175 = 0 ;
F_82 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_178 = F_11 ( & V_1 -> V_52 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
struct V_14 * V_15 = F_12 ( V_178 , struct V_14 , V_50 ) ;
if ( F_77 ( V_1 , V_15 ) )
continue;
F_88 ( V_1 , V_15 , V_183 ) ;
}
}
void F_92 ( struct V_184 * V_77 , T_7 type )
{
++ V_77 -> V_68 [ 0 ] ;
++ V_77 -> V_68 [ type ] ;
}
void F_93 ( struct V_1 * V_1 , T_7 type )
{
F_92 ( & V_1 -> V_77 , type ) ;
}
void F_40 ( struct V_1 * V_1 , bool V_55 )
{
F_92 ( & V_1 -> V_77 , V_185 ) ;
if ( ! V_55 )
V_1 -> V_77 . V_175 ++ ;
}
static struct V_14 * F_94 ( struct V_1 * V_1 ,
struct V_14 * V_186 )
{
struct V_157 * V_158 ;
struct V_50 * * V_105 ;
struct V_50 * V_27 = NULL ;
struct V_14 * V_71 ;
T_5 V_106 ;
if ( V_84 )
V_158 = & V_1 -> V_86 ;
else
V_158 = V_1 -> V_107 ;
V_105 = & V_158 -> V_50 ;
while ( * V_105 != NULL ) {
V_27 = * V_105 ;
V_71 = F_12 ( V_27 , struct V_14 , V_85 ) ;
V_106 = F_66 ( V_71 , V_186 ) ;
if ( ! V_106 )
goto V_108;
if ( V_106 < 0 )
V_105 = & ( * V_105 ) -> V_109 ;
else
V_105 = & ( * V_105 ) -> V_110 ;
}
V_71 = F_22 ( V_186 , true ) ;
if ( V_71 ) {
memset ( & V_71 -> V_73 , 0 , sizeof( V_71 -> V_73 ) ) ;
V_71 -> V_1 = V_1 ;
F_30 ( & V_71 -> V_85 , V_27 , V_105 ) ;
F_31 ( & V_71 -> V_85 , V_158 ) ;
F_85 ( V_1 , V_71 ) ;
V_71 -> V_187 = true ;
}
V_108:
return V_71 ;
}
static struct V_14 * F_95 ( struct V_1 * V_1 ,
struct V_14 * V_71 )
{
struct V_50 * V_53 ;
if ( V_84 )
V_53 = V_1 -> V_86 . V_50 ;
else
V_53 = V_1 -> V_107 -> V_50 ;
while ( V_53 ) {
struct V_14 * T_6 = F_12 ( V_53 , struct V_14 , V_85 ) ;
T_5 V_106 = F_66 ( T_6 , V_71 ) ;
if ( V_106 < 0 )
V_53 = V_53 -> V_109 ;
else if ( V_106 > 0 )
V_53 = V_53 -> V_110 ;
else
return T_6 ;
}
return NULL ;
}
void F_96 ( struct V_1 * V_188 , struct V_1 * V_189 )
{
struct V_157 * V_158 ;
struct V_50 * V_178 ;
struct V_14 * V_190 , * V_186 ;
if ( V_84 )
V_158 = & V_188 -> V_86 ;
else
V_158 = V_188 -> V_107 ;
for ( V_178 = F_11 ( V_158 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
V_190 = F_12 ( V_178 , struct V_14 , V_85 ) ;
V_186 = F_95 ( V_189 , V_190 ) ;
if ( V_186 )
F_97 ( V_186 , V_190 ) ;
}
}
int F_98 ( struct V_1 * V_188 , struct V_1 * V_189 )
{
struct V_157 * V_158 ;
struct V_50 * V_178 ;
struct V_14 * V_190 , * V_186 ;
if ( V_84 )
V_158 = & V_189 -> V_86 ;
else
V_158 = V_189 -> V_107 ;
for ( V_178 = F_11 ( V_158 ) ; V_178 ; V_178 = F_13 ( V_178 ) ) {
V_190 = F_12 ( V_178 , struct V_14 , V_85 ) ;
if ( ! F_99 ( V_190 ) ) {
V_186 = F_94 ( V_188 , V_190 ) ;
if ( V_186 == NULL )
return - 1 ;
F_97 ( V_190 , V_186 ) ;
}
}
return 0 ;
}
T_2 F_100 ( struct V_1 * V_1 )
{
return V_10 . V_191 ? V_1 -> V_77 . V_79 :
V_1 -> V_77 . V_78 ;
}
int F_101 ( const struct V_192 * T_8 V_119 ,
const char * V_142 , int T_9 V_119 )
{
if ( ! strcmp ( V_142 , L_1 ) )
V_10 . V_191 = true ;
else if ( ! strcmp ( V_142 , L_2 ) )
V_10 . V_191 = false ;
else
return - 1 ;
return 0 ;
}
int F_102 ( const char * V_193 , const char * V_194 )
{
if ( ! strcmp ( V_193 , L_3 ) )
return F_101 ( NULL , V_194 , 0 ) ;
return 0 ;
}
