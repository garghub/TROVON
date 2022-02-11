static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
T_3 free ;
if ( ! V_4 )
return 0 ;
if ( ! V_2 -> V_5 )
return 0 ;
free = F_2 ( V_2 ) ;
if ( V_4 > free ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static T_3 F_5 ( struct V_1 * V_3 ,
int V_7 , char T_4 * V_2 ,
T_2 V_8 , T_5 * V_9 )
{
T_2 V_10 ;
T_3 V_11 ;
T_3 V_12 = 0 ;
if ( ! V_3 -> V_5 )
return 0 ;
if ( V_3 -> error ) {
V_12 = V_3 -> error ;
F_6 ( V_3 ) ;
return V_12 ;
}
for ( V_10 = V_8 ; V_10 > 0 ; V_10 -= V_12 ) {
if ( V_7 && F_7 ( V_3 ) ) {
V_12 = - V_13 ;
break;
}
V_12 = F_8 ( V_3 -> V_14 ,
! F_7 ( V_3 ) ||
( V_3 -> error != 0 ) ) ;
if ( V_12 < 0 )
break;
if ( V_3 -> error ) {
V_12 = V_3 -> error ;
F_6 ( V_3 ) ;
break;
}
V_11 = F_9 ( V_3 ) ;
if ( V_11 > V_10 )
V_11 = V_10 ;
V_12 = F_10 ( V_3 , V_2 , V_11 ) ;
if ( V_12 < 0 )
break;
V_2 += V_12 ;
}
return ( V_8 - V_10 ) ? ( V_8 - V_10 ) : V_12 ;
}
static struct V_15 * F_11 ( struct V_16 * V_17 , int type )
{
struct V_18 * V_19 , * V_20 ;
V_19 = V_17 -> V_21 ( V_17 ) ;
if ( ! V_19 )
return NULL ;
F_12 (pos, head)
if ( F_13 ( V_20 ) -> V_22 == type )
return F_13 ( V_20 ) ;
return NULL ;
}
static int F_14 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
struct V_15 * V_30 ;
F_3 ( L_2 , V_31 ) ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
if ( V_28 -> exit ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_34 ;
}
if ( ( V_24 -> V_35 & V_36 ) == V_37 ) {
if ( ! ( V_28 -> V_38 & V_39 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_40 ;
}
}
if ( ( V_24 -> V_35 & V_36 ) == V_41 ) {
void * V_42 ;
if ( ! V_26 -> V_43 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_44 ;
}
V_42 = F_17 ( V_45 ) ;
if ( ! V_42 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_46 ;
}
F_18 ( & V_28 -> V_47 , V_42 , V_45 ) ;
V_26 -> V_43 -- ;
}
if ( ( V_24 -> V_35 & V_36 ) == V_48 ) {
V_28 -> V_49 = V_28 -> V_17 -> V_50 ;
if ( ! V_28 -> V_17 -> V_51 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_40 ;
}
V_30 = F_11 ( V_28 -> V_17 , V_52 ) ;
if ( ! V_30 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_53 ;
}
V_28 -> V_17 -> V_54 ( V_28 -> V_17 ) ;
V_28 -> V_17 -> V_55 ( V_28 -> V_17 , V_30 ) ;
}
V_26 -> V_56 ++ ;
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
F_20 ( & V_28 -> V_32 ) ;
if ( ( V_24 -> V_35 & V_36 ) == V_48 ) {
V_28 -> V_17 -> V_54 ( V_28 -> V_17 ) ;
V_28 -> V_17 -> V_55 ( V_28 -> V_17 ,
V_28 -> V_49 ) ;
}
if ( ( V_24 -> V_35 & V_36 ) == V_41 ) {
V_26 -> V_43 ++ ;
if ( V_28 -> V_47 . V_5 ) {
void * V_42 = V_28 -> V_47 . V_5 ;
F_21 () ;
F_22 ( & V_28 -> V_57 ) ;
V_28 -> V_47 . V_5 = NULL ;
F_23 ( & V_28 -> V_57 ) ;
F_24 ( V_42 ) ;
}
}
V_26 -> V_56 -- ;
if ( V_26 -> V_56 == 1 && V_28 -> exit == 1 ) {
F_25 ( V_24 -> V_58 ) ;
V_24 -> V_58 = NULL ;
F_16 ( & V_28 -> V_32 ) ;
F_26 ( & V_26 -> V_59 ) ;
} else
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static T_3 F_27 ( struct V_24 * V_24 , const char T_4 * V_2 ,
T_2 V_8 , T_5 * V_9 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
int V_12 ;
if ( ! V_28 -> V_17 -> V_51 )
return - V_40 ;
if ( ( V_24 -> V_35 & V_36 ) != V_48 )
return - V_53 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
if ( V_28 -> exit ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_34 ;
}
V_12 = V_28 -> V_17 -> V_51 ( V_28 -> V_17 , V_2 , V_8 ) ;
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static T_3 F_28 ( struct V_24 * V_24 , char T_4 * V_2 , T_2 V_8 ,
T_5 * V_9 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
if ( V_28 -> exit )
return - V_34 ;
return F_5 ( & V_28 -> V_47 ,
V_24 -> V_35 & V_60 ,
V_2 , V_8 , V_9 ) ;
}
static int F_29 ( struct V_28 * V_28 ,
unsigned long V_61 )
{
struct V_1 * V_2 = & V_28 -> V_47 ;
void * V_62 ;
void * V_63 ;
F_3 ( L_2 , V_31 ) ;
if ( V_2 -> V_61 == V_61 )
return 0 ;
if ( ! V_61 )
return - V_53 ;
V_62 = F_17 ( V_61 ) ;
if ( ! V_62 )
return - V_46 ;
V_63 = V_2 -> V_5 ;
F_22 ( & V_28 -> V_57 ) ;
V_2 -> V_5 = V_62 ;
V_2 -> V_61 = V_61 ;
F_30 ( V_2 ) ;
F_23 ( & V_28 -> V_57 ) ;
F_24 ( V_63 ) ;
return 0 ;
}
static inline void F_31 ( struct V_64
* V_65 , int V_66 )
{
F_22 ( & V_65 -> V_67 -> V_57 ) ;
V_65 -> V_66 = V_66 ;
F_23 ( & V_65 -> V_67 -> V_57 ) ;
}
static int F_32 ( struct V_64 * V_65 ,
unsigned long V_61 )
{
struct V_1 * V_2 = & V_65 -> V_68 ;
void * V_62 ;
void * V_63 ;
if ( V_2 -> V_61 == V_61 )
return 0 ;
if ( ! V_61 )
return - V_53 ;
if ( V_65 -> V_66 >= V_69 )
return - V_44 ;
V_62 = F_17 ( V_61 ) ;
if ( ! V_62 )
return - V_46 ;
V_63 = V_2 -> V_5 ;
F_22 ( & V_65 -> V_67 -> V_57 ) ;
V_2 -> V_5 = V_62 ;
V_2 -> V_61 = V_61 ;
F_30 ( V_2 ) ;
F_23 ( & V_65 -> V_67 -> V_57 ) ;
F_24 ( V_63 ) ;
return 0 ;
}
static void F_33 ( unsigned long V_5 )
{
struct V_64 * V_65 = (struct V_64 * ) V_5 ;
V_65 -> V_68 . error = - V_70 ;
F_22 ( & V_65 -> V_67 -> V_57 ) ;
V_65 -> V_66 = V_71 ;
F_23 ( & V_65 -> V_67 -> V_57 ) ;
F_26 ( & V_65 -> V_68 . V_14 ) ;
}
static void F_34 ( struct V_64 * V_65 )
{
struct V_72 * V_73 = & V_65 -> V_74 . V_75 ;
F_35 ( & V_65 -> V_76 ) ;
if ( V_73 -> V_77 ) {
V_65 -> V_76 . V_78 = F_33 ;
V_65 -> V_76 . V_5 = ( unsigned long ) V_65 ;
V_65 -> V_76 . V_79 =
V_80 + 1 + ( V_81 / 2 + V_81 * V_73 -> V_77 ) / 1000 ;
F_36 ( & V_65 -> V_76 ) ;
}
}
static int F_37 ( const T_1 * V_82 , T_2 V_83 ,
const T_1 * V_84 , T_2 V_85 ,
struct V_86 * V_87 ,
enum V_88 V_89 )
{
struct V_64 * V_65 = V_87 -> V_29 ;
int V_12 ;
if ( V_65 -> V_68 . error ) {
F_26 ( & V_65 -> V_68 . V_14 ) ;
return 0 ;
}
F_38 ( & V_65 -> V_67 -> V_57 ) ;
if ( V_65 -> V_66 != V_69 ) {
F_39 ( & V_65 -> V_67 -> V_57 ) ;
return 0 ;
}
F_35 ( & V_65 -> V_76 ) ;
F_3 ( L_3 ,
V_82 [ 0 ] , V_82 [ 1 ] ,
V_82 [ 2 ] , V_82 [ 3 ] , V_82 [ 4 ] , V_82 [ 5 ] ) ;
V_12 = F_1 ( & V_65 -> V_68 , V_82 ,
V_83 ) ;
if ( V_12 == V_83 ) {
V_12 = F_1 ( & V_65 -> V_68 , V_84 ,
V_85 ) ;
}
if ( V_12 < 0 ) {
F_6 ( & V_65 -> V_68 ) ;
V_65 -> V_68 . error = V_12 ;
}
if ( V_65 -> V_74 . V_75 . V_90 & V_91 )
V_65 -> V_66 = V_92 ;
F_39 ( & V_65 -> V_67 -> V_57 ) ;
F_26 ( & V_65 -> V_68 . V_14 ) ;
return 0 ;
}
static int F_40 ( const T_1 * V_82 , T_2 V_83 ,
const T_1 * V_84 , T_2 V_85 ,
struct V_93 * V_94 ,
enum V_88 V_89 )
{
struct V_64 * V_65 = V_94 -> V_29 ;
struct V_1 * V_68 ;
int V_12 ;
F_38 ( & V_65 -> V_67 -> V_57 ) ;
if ( V_65 -> V_74 . V_95 . V_96 == V_97 ) {
F_39 ( & V_65 -> V_67 -> V_57 ) ;
return 0 ;
}
if ( V_65 -> V_74 . V_95 . V_96 == V_98
|| V_65 -> V_74 . V_95 . V_96 == V_99 )
V_68 = & V_65 -> V_68 ;
else
V_68 = & V_65 -> V_67 -> V_47 ;
if ( V_68 -> error ) {
F_39 ( & V_65 -> V_67 -> V_57 ) ;
F_26 ( & V_68 -> V_14 ) ;
return 0 ;
}
V_12 = F_1 ( V_68 , V_82 , V_83 ) ;
if ( V_12 == V_83 )
V_12 = F_1 ( V_68 , V_84 , V_85 ) ;
if ( V_12 < 0 ) {
F_6 ( V_68 ) ;
V_68 -> error = V_12 ;
}
F_39 ( & V_65 -> V_67 -> V_57 ) ;
F_26 ( & V_68 -> V_14 ) ;
return 0 ;
}
static int F_41 ( struct V_64 * V_65 )
{
struct V_100 * V_94 ;
F_31 ( V_65 , V_101 ) ;
switch ( V_65 -> type ) {
case V_102 :
F_35 ( & V_65 -> V_76 ) ;
V_65 -> V_94 . V_75 -> V_103 ( V_65 -> V_94 . V_75 ) ;
break;
case V_104 :
F_42 (feed, &dmxdevfilter->feed.ts, next)
V_94 -> V_105 -> V_103 ( V_94 -> V_105 ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_43 ( struct V_64 * V_87 )
{
struct V_100 * V_94 ;
int V_12 ;
F_31 ( V_87 , V_69 ) ;
switch ( V_87 -> type ) {
case V_102 :
return V_87 -> V_94 . V_75 -> V_106 ( V_87 -> V_94 . V_75 ) ;
case V_104 :
F_42 (feed, &filter->feed.ts, next) {
V_12 = V_94 -> V_105 -> V_106 ( V_94 -> V_105 ) ;
if ( V_12 < 0 ) {
F_41 ( V_87 ) ;
return V_12 ;
}
}
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_44 ( struct V_64 * V_87 )
{
int V_107 ;
struct V_28 * V_28 = V_87 -> V_67 ;
T_6 V_108 = V_87 -> V_74 . V_75 . V_108 ;
for ( V_107 = 0 ; V_107 < V_28 -> V_109 ; V_107 ++ )
if ( V_28 -> V_87 [ V_107 ] . V_66 >= V_69 &&
V_28 -> V_87 [ V_107 ] . type == V_102 &&
V_28 -> V_87 [ V_107 ] . V_74 . V_75 . V_108 == V_108 ) {
F_43 ( & V_28 -> V_87 [ V_107 ] ) ;
return 0 ;
}
V_87 -> V_67 -> V_17 -> V_110 ( V_28 -> V_17 ,
V_87 -> V_94 . V_75 ) ;
return 0 ;
}
static int F_45 ( struct V_64 * V_65 )
{
struct V_100 * V_94 ;
struct V_16 * V_17 ;
if ( V_65 -> V_66 < V_69 )
return 0 ;
switch ( V_65 -> type ) {
case V_102 :
if ( ! V_65 -> V_94 . V_75 )
break;
F_41 ( V_65 ) ;
if ( V_65 -> V_87 . V_75 )
V_65 -> V_94 . V_75 ->
V_111 ( V_65 -> V_94 . V_75 ,
V_65 -> V_87 . V_75 ) ;
F_44 ( V_65 ) ;
V_65 -> V_94 . V_75 = NULL ;
break;
case V_104 :
F_41 ( V_65 ) ;
V_17 = V_65 -> V_67 -> V_17 ;
F_42 (feed, &dmxdevfilter->feed.ts, next) {
V_17 -> V_112 ( V_17 , V_94 -> V_105 ) ;
V_94 -> V_105 = NULL ;
}
break;
default:
if ( V_65 -> V_66 == V_113 )
return 0 ;
return - V_53 ;
}
F_6 ( & V_65 -> V_68 ) ;
return 0 ;
}
static void F_46 ( struct V_64 * V_65 )
{
struct V_100 * V_94 , * V_114 ;
F_47 (feed, tmp, &dmxdevfilter->feed.ts, next) {
F_48 ( & V_94 -> V_115 ) ;
F_49 ( V_94 ) ;
}
F_50 ( ! F_51 ( & V_65 -> V_94 . V_105 ) ) ;
}
static inline int F_52 ( struct V_64 * V_65 )
{
if ( V_65 -> V_66 < V_101 )
return 0 ;
if ( V_65 -> type == V_104 )
F_46 ( V_65 ) ;
V_65 -> type = V_116 ;
F_31 ( V_65 , V_113 ) ;
return 0 ;
}
static int F_53 ( struct V_28 * V_28 ,
struct V_64 * V_87 ,
struct V_100 * V_94 )
{
struct V_117 V_77 = { 0 } ;
struct V_118 * V_73 = & V_87 -> V_74 . V_95 ;
T_7 V_119 ;
int V_12 ;
int V_120 ;
T_8 V_121 ;
struct V_93 * V_122 ;
V_94 -> V_105 = NULL ;
V_119 = V_73 -> V_96 ;
V_121 = V_73 -> V_123 ;
if ( V_121 < V_124 )
V_120 = V_125 ;
else
V_120 = 0 ;
if ( V_119 == V_126 )
V_120 |= V_127 ;
else if ( V_119 == V_99 )
V_120 |= V_127 | V_128 ;
else if ( V_119 == V_98 )
V_120 |= V_127 | V_128 | V_129 ;
V_12 = V_28 -> V_17 -> V_130 ( V_28 -> V_17 , & V_94 -> V_105 ,
F_40 ) ;
if ( V_12 < 0 )
return V_12 ;
V_122 = V_94 -> V_105 ;
V_122 -> V_29 = V_87 ;
V_12 = V_122 -> V_131 ( V_122 , V_94 -> V_108 , V_120 , V_121 , 32768 , V_77 ) ;
if ( V_12 < 0 ) {
V_28 -> V_17 -> V_112 ( V_28 -> V_17 , V_122 ) ;
return V_12 ;
}
V_12 = V_122 -> V_106 ( V_122 ) ;
if ( V_12 < 0 ) {
V_28 -> V_17 -> V_112 ( V_28 -> V_17 , V_122 ) ;
return V_12 ;
}
return 0 ;
}
static int F_54 ( struct V_64 * V_87 )
{
struct V_28 * V_28 = V_87 -> V_67 ;
struct V_100 * V_94 ;
void * V_42 ;
int V_12 , V_107 ;
if ( V_87 -> V_66 < V_101 )
return - V_53 ;
if ( V_87 -> V_66 >= V_69 )
F_45 ( V_87 ) ;
if ( ! V_87 -> V_68 . V_5 ) {
V_42 = F_17 ( V_87 -> V_68 . V_61 ) ;
if ( ! V_42 )
return - V_46 ;
F_22 ( & V_87 -> V_67 -> V_57 ) ;
V_87 -> V_68 . V_5 = V_42 ;
F_23 ( & V_87 -> V_67 -> V_57 ) ;
}
F_6 ( & V_87 -> V_68 ) ;
switch ( V_87 -> type ) {
case V_102 :
{
struct V_72 * V_73 = & V_87 -> V_74 . V_75 ;
struct V_86 * * V_132 = & V_87 -> V_87 . V_75 ;
struct V_133 * * V_134 = & V_87 -> V_94 . V_75 ;
* V_132 = NULL ;
* V_134 = NULL ;
for ( V_107 = 0 ; V_107 < V_28 -> V_109 ; V_107 ++ ) {
if ( V_28 -> V_87 [ V_107 ] . V_66 >= V_69 &&
V_28 -> V_87 [ V_107 ] . type == V_102 &&
V_28 -> V_87 [ V_107 ] . V_74 . V_75 . V_108 == V_73 -> V_108 ) {
* V_134 = V_28 -> V_87 [ V_107 ] . V_94 . V_75 ;
break;
}
}
if ( ! * V_134 ) {
V_12 = V_28 -> V_17 -> V_135 ( V_28 -> V_17 ,
V_134 ,
F_37 ) ;
if ( V_12 < 0 ) {
F_55 ( L_4 ,
V_31 ) ;
return V_12 ;
}
V_12 = ( * V_134 ) -> V_131 ( * V_134 , V_73 -> V_108 , 32768 ,
( V_73 -> V_90 & V_136 ) ? 1 : 0 ) ;
if ( V_12 < 0 ) {
F_55 ( L_5 ,
V_31 ) ;
F_44 ( V_87 ) ;
return V_12 ;
}
} else {
F_41 ( V_87 ) ;
}
V_12 = ( * V_134 ) -> V_137 ( * V_134 , V_132 ) ;
if ( V_12 < 0 ) {
F_44 ( V_87 ) ;
V_87 -> V_94 . V_75 -> V_106 ( * V_134 ) ;
F_3 ( L_6 ) ;
return V_12 ;
}
( * V_132 ) -> V_29 = V_87 ;
memcpy ( & ( ( * V_132 ) -> V_138 [ 3 ] ) ,
& ( V_73 -> V_87 . V_87 [ 1 ] ) , V_139 - 1 ) ;
memcpy ( & ( * V_132 ) -> V_140 [ 3 ] ,
& V_73 -> V_87 . V_141 [ 1 ] , V_139 - 1 ) ;
memcpy ( & ( * V_132 ) -> V_142 [ 3 ] ,
& V_73 -> V_87 . V_143 [ 1 ] , V_139 - 1 ) ;
( * V_132 ) -> V_138 [ 0 ] = V_73 -> V_87 . V_87 [ 0 ] ;
( * V_132 ) -> V_140 [ 0 ] = V_73 -> V_87 . V_141 [ 0 ] ;
( * V_132 ) -> V_142 [ 0 ] = V_73 -> V_87 . V_143 [ 0 ] ;
( * V_132 ) -> V_140 [ 1 ] = 0 ;
( * V_132 ) -> V_140 [ 2 ] = 0 ;
V_87 -> V_10 = 0 ;
V_12 = V_87 -> V_94 . V_75 -> V_106 ( V_87 -> V_94 . V_75 ) ;
if ( V_12 < 0 )
return V_12 ;
F_34 ( V_87 ) ;
break;
}
case V_104 :
F_42 (feed, &filter->feed.ts, next) {
V_12 = F_53 ( V_28 , V_87 , V_94 ) ;
if ( V_12 < 0 ) {
F_45 ( V_87 ) ;
return V_12 ;
}
}
break;
default:
return - V_53 ;
}
F_31 ( V_87 , V_69 ) ;
return 0 ;
}
static int F_56 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
int V_107 ;
struct V_64 * V_65 ;
if ( ! V_28 -> V_87 )
return - V_53 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
for ( V_107 = 0 ; V_107 < V_28 -> V_109 ; V_107 ++ )
if ( V_28 -> V_87 [ V_107 ] . V_66 == V_144 )
break;
if ( V_107 == V_28 -> V_109 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_145 ;
}
V_65 = & V_28 -> V_87 [ V_107 ] ;
F_57 ( & V_65 -> V_32 ) ;
V_24 -> V_27 = V_65 ;
F_18 ( & V_65 -> V_68 , NULL , 8192 ) ;
V_65 -> type = V_116 ;
F_31 ( V_65 , V_113 ) ;
F_58 ( & V_65 -> V_76 ) ;
V_26 -> V_56 ++ ;
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_28 * V_28 ,
struct V_64 * V_65 )
{
F_20 ( & V_28 -> V_32 ) ;
F_20 ( & V_65 -> V_32 ) ;
F_45 ( V_65 ) ;
F_52 ( V_65 ) ;
if ( V_65 -> V_68 . V_5 ) {
void * V_42 = V_65 -> V_68 . V_5 ;
F_22 ( & V_28 -> V_57 ) ;
V_65 -> V_68 . V_5 = NULL ;
F_23 ( & V_28 -> V_57 ) ;
F_24 ( V_42 ) ;
}
F_31 ( V_65 , V_144 ) ;
F_26 ( & V_65 -> V_68 . V_14 ) ;
F_16 ( & V_65 -> V_32 ) ;
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static inline void F_60 ( T_9 * V_87 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_139 ; V_107 ++ )
V_87 -> V_143 [ V_107 ] ^= 0xff ;
}
static int F_61 ( struct V_28 * V_28 ,
struct V_64 * V_87 , T_6 V_108 )
{
struct V_100 * V_94 ;
if ( ( V_87 -> type != V_104 ) ||
( V_87 -> V_66 < V_101 ) )
return - V_53 ;
if ( ( V_87 -> V_74 . V_95 . V_96 != V_99 ) &&
( ! F_51 ( & V_87 -> V_94 . V_105 ) ) )
return - V_53 ;
V_94 = F_62 ( sizeof( struct V_100 ) , V_146 ) ;
if ( V_94 == NULL )
return - V_46 ;
V_94 -> V_108 = V_108 ;
F_63 ( & V_94 -> V_115 , & V_87 -> V_94 . V_105 ) ;
if ( V_87 -> V_66 >= V_69 )
return F_53 ( V_28 , V_87 , V_94 ) ;
return 0 ;
}
static int F_64 ( struct V_28 * V_28 ,
struct V_64 * V_87 , T_6 V_108 )
{
struct V_100 * V_94 , * V_114 ;
if ( ( V_87 -> type != V_104 ) ||
( V_87 -> V_66 < V_101 ) )
return - V_53 ;
F_47 (feed, tmp, &filter->feed.ts, next) {
if ( ( V_94 -> V_108 == V_108 ) && ( V_94 -> V_105 != NULL ) ) {
V_94 -> V_105 -> V_103 ( V_94 -> V_105 ) ;
V_87 -> V_67 -> V_17 -> V_112 ( V_87 -> V_67 -> V_17 ,
V_94 -> V_105 ) ;
F_48 ( & V_94 -> V_115 ) ;
F_49 ( V_94 ) ;
}
}
return 0 ;
}
static int F_65 ( struct V_28 * V_28 ,
struct V_64 * V_65 ,
struct V_72 * V_74 )
{
F_3 ( L_2 , V_31 ) ;
F_45 ( V_65 ) ;
V_65 -> type = V_102 ;
memcpy ( & V_65 -> V_74 . V_75 ,
V_74 , sizeof( struct V_72 ) ) ;
F_60 ( & V_65 -> V_74 . V_75 . V_87 ) ;
F_31 ( V_65 , V_101 ) ;
if ( V_74 -> V_90 & V_147 )
return F_54 ( V_65 ) ;
return 0 ;
}
static int F_66 ( struct V_28 * V_28 ,
struct V_64 * V_65 ,
struct V_118 * V_74 )
{
int V_12 ;
F_45 ( V_65 ) ;
F_52 ( V_65 ) ;
if ( V_74 -> V_123 > V_124 || V_74 -> V_123 < 0 )
return - V_53 ;
V_65 -> type = V_104 ;
memcpy ( & V_65 -> V_74 , V_74 ,
sizeof( struct V_118 ) ) ;
F_67 ( & V_65 -> V_94 . V_105 ) ;
F_31 ( V_65 , V_101 ) ;
V_12 = F_61 ( V_28 , V_65 ,
V_65 -> V_74 . V_95 . V_108 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_74 -> V_90 & V_147 )
return F_54 ( V_65 ) ;
return 0 ;
}
static T_3 F_68 ( struct V_64 * V_148 ,
struct V_24 * V_24 , char T_4 * V_2 ,
T_2 V_8 , T_5 * V_9 )
{
int V_149 , V_150 ;
int V_151 = 0 ;
if ( V_148 -> V_10 <= 0 ) {
V_150 = 3 + V_148 -> V_10 ;
if ( V_150 > V_8 )
V_150 = V_8 ;
V_149 = F_5 ( & V_148 -> V_68 ,
V_24 -> V_35 & V_60 ,
V_2 , V_150 , V_9 ) ;
if ( V_149 < 0 ) {
V_148 -> V_10 = 0 ;
return V_149 ;
}
if ( F_69 ( V_148 -> V_152 - V_148 -> V_10 , V_2 , V_149 ) )
return - V_153 ;
V_2 += V_149 ;
V_151 = V_149 ;
V_8 -= V_149 ;
V_148 -> V_10 -= V_149 ;
if ( V_148 -> V_10 > - 3 )
return V_151 ;
V_148 -> V_10 = ( ( V_148 -> V_152 [ 1 ] << 8 ) | V_148 -> V_152 [ 2 ] ) & 0xfff ;
if ( ! V_8 )
return V_151 ;
}
if ( V_8 > V_148 -> V_10 )
V_8 = V_148 -> V_10 ;
V_149 = F_5 ( & V_148 -> V_68 ,
V_24 -> V_35 & V_60 ,
V_2 , V_8 , V_9 ) ;
if ( V_149 < 0 )
return V_149 ;
V_148 -> V_10 -= V_149 ;
return ( V_149 + V_151 ) ;
}
static T_3
F_70 ( struct V_24 * V_24 , char T_4 * V_2 , T_2 V_8 ,
T_5 * V_9 )
{
struct V_64 * V_65 = V_24 -> V_27 ;
int V_12 ;
if ( F_15 ( & V_65 -> V_32 ) )
return - V_33 ;
if ( V_65 -> type == V_102 )
V_12 = F_68 ( V_65 , V_24 , V_2 , V_8 , V_9 ) ;
else
V_12 = F_5 ( & V_65 -> V_68 ,
V_24 -> V_35 & V_60 ,
V_2 , V_8 , V_9 ) ;
F_16 ( & V_65 -> V_32 ) ;
return V_12 ;
}
static int F_71 ( struct V_24 * V_24 ,
unsigned int V_154 , void * V_155 )
{
struct V_64 * V_65 = V_24 -> V_27 ;
struct V_28 * V_28 = V_65 -> V_67 ;
unsigned long V_156 = ( unsigned long ) V_155 ;
int V_12 = 0 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
switch ( V_154 ) {
case V_157 :
if ( F_15 ( & V_65 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
if ( V_65 -> V_66 < V_101 )
V_12 = - V_53 ;
else
V_12 = F_54 ( V_65 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_158 :
if ( F_15 ( & V_65 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_45 ( V_65 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_159 :
if ( F_15 ( & V_65 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_65 ( V_28 , V_65 , V_155 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_160 :
if ( F_15 ( & V_65 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_66 ( V_28 , V_65 , V_155 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_161 :
if ( F_15 ( & V_65 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_32 ( V_65 , V_156 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_162 :
if ( ! V_28 -> V_17 -> V_163 ) {
V_12 = - V_53 ;
break;
}
V_28 -> V_17 -> V_163 ( V_28 -> V_17 , V_155 ) ;
break;
case V_164 :
if ( ! V_28 -> V_17 -> V_165 ) {
V_12 = - V_53 ;
break;
}
V_12 = V_28 -> V_17 -> V_165 ( V_28 -> V_17 , V_155 ) ;
break;
case V_166 :
if ( ! V_28 -> V_17 -> V_167 ) {
V_12 = - V_53 ;
break;
}
V_12 = V_28 -> V_17 -> V_167 ( V_28 -> V_17 , V_155 ) ;
break;
case V_168 :
if ( ! V_28 -> V_17 -> V_169 ) {
V_12 = - V_53 ;
break;
}
V_12 = V_28 -> V_17 -> V_169 ( V_28 -> V_17 ,
( (struct V_170 * ) V_155 ) -> V_171 ,
& ( (struct V_170 * ) V_155 ) -> V_172 ,
& ( (struct V_170 * ) V_155 ) -> V_173 ) ;
break;
case V_174 :
if ( F_15 ( & V_65 -> V_32 ) ) {
V_12 = - V_33 ;
break;
}
V_12 = F_61 ( V_28 , V_65 , * ( T_6 * ) V_155 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
case V_175 :
if ( F_15 ( & V_65 -> V_32 ) ) {
V_12 = - V_33 ;
break;
}
V_12 = F_64 ( V_28 , V_65 , * ( T_6 * ) V_155 ) ;
F_16 ( & V_65 -> V_32 ) ;
break;
default:
V_12 = - V_53 ;
break;
}
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static long F_72 ( struct V_24 * V_24 , unsigned int V_154 ,
unsigned long V_156 )
{
return F_73 ( V_24 , V_154 , V_156 , F_71 ) ;
}
static unsigned int F_74 ( struct V_24 * V_24 , T_10 * V_176 )
{
struct V_64 * V_65 = V_24 -> V_27 ;
unsigned int V_141 = 0 ;
if ( ! V_65 )
return - V_53 ;
F_75 ( V_24 , & V_65 -> V_68 . V_14 , V_176 ) ;
if ( V_65 -> V_66 != V_69 &&
V_65 -> V_66 != V_92 &&
V_65 -> V_66 != V_71 )
return 0 ;
if ( V_65 -> V_68 . error )
V_141 |= ( V_177 | V_178 | V_179 | V_180 ) ;
if ( ! F_7 ( & V_65 -> V_68 ) )
V_141 |= ( V_177 | V_178 | V_179 ) ;
return V_141 ;
}
static int F_76 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_64 * V_65 = V_24 -> V_27 ;
struct V_28 * V_28 = V_65 -> V_67 ;
int V_12 ;
V_12 = F_59 ( V_28 , V_65 ) ;
F_20 ( & V_28 -> V_32 ) ;
V_28 -> V_26 -> V_56 -- ;
if( V_28 -> V_26 -> V_56 == 1 && V_28 -> exit == 1 ) {
F_25 ( V_24 -> V_58 ) ;
V_24 -> V_58 = NULL ;
F_16 ( & V_28 -> V_32 ) ;
F_26 ( & V_28 -> V_26 -> V_59 ) ;
} else
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static int F_77 ( struct V_24 * V_24 ,
unsigned int V_154 , void * V_155 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
unsigned long V_156 = ( unsigned long ) V_155 ;
int V_12 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
switch ( V_154 ) {
case V_161 :
V_12 = F_29 ( V_28 , V_156 ) ;
break;
default:
V_12 = - V_53 ;
break;
}
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static long F_78 ( struct V_24 * V_24 ,
unsigned int V_154 , unsigned long V_156 )
{
return F_73 ( V_24 , V_154 , V_156 , F_77 ) ;
}
static unsigned int F_79 ( struct V_24 * V_24 , T_10 * V_176 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
unsigned int V_141 = 0 ;
F_3 ( L_2 , V_31 ) ;
F_75 ( V_24 , & V_28 -> V_47 . V_14 , V_176 ) ;
if ( ( V_24 -> V_35 & V_36 ) == V_41 ) {
if ( V_28 -> V_47 . error )
V_141 |= ( V_177 | V_178 | V_179 | V_180 ) ;
if ( ! F_7 ( & V_28 -> V_47 ) )
V_141 |= ( V_177 | V_178 | V_179 ) ;
} else
V_141 |= ( V_181 | V_182 | V_179 ) ;
return V_141 ;
}
int F_80 ( struct V_28 * V_28 , struct V_183 * V_183 )
{
int V_107 ;
if ( V_28 -> V_17 -> V_184 ( V_28 -> V_17 ) < 0 )
return - V_185 ;
V_28 -> V_87 = F_17 ( V_28 -> V_109 * sizeof( struct V_64 ) ) ;
if ( ! V_28 -> V_87 )
return - V_46 ;
F_57 ( & V_28 -> V_32 ) ;
F_81 ( & V_28 -> V_57 ) ;
for ( V_107 = 0 ; V_107 < V_28 -> V_109 ; V_107 ++ ) {
V_28 -> V_87 [ V_107 ] . V_67 = V_28 ;
V_28 -> V_87 [ V_107 ] . V_68 . V_5 = NULL ;
F_31 ( & V_28 -> V_87 [ V_107 ] ,
V_144 ) ;
}
F_82 ( V_183 , & V_28 -> V_26 , & V_186 , V_28 ,
V_187 ) ;
F_82 ( V_183 , & V_28 -> V_188 , & V_189 ,
V_28 , V_190 ) ;
F_18 ( & V_28 -> V_47 , NULL , 8192 ) ;
return 0 ;
}
void F_83 ( struct V_28 * V_28 )
{
V_28 -> exit = 1 ;
if ( V_28 -> V_26 -> V_56 > 1 ) {
F_84 ( V_28 -> V_26 -> V_59 ,
V_28 -> V_26 -> V_56 == 1 ) ;
}
if ( V_28 -> V_188 -> V_56 > 1 ) {
F_84 ( V_28 -> V_188 -> V_59 ,
V_28 -> V_188 -> V_56 == 1 ) ;
}
F_85 ( V_28 -> V_26 ) ;
F_85 ( V_28 -> V_188 ) ;
F_24 ( V_28 -> V_87 ) ;
V_28 -> V_87 = NULL ;
V_28 -> V_17 -> V_191 ( V_28 -> V_17 ) ;
}
