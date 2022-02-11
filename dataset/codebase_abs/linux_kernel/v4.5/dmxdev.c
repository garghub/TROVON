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
F_16 ( & V_28 -> V_32 ) ;
F_25 ( & V_26 -> V_58 ) ;
} else
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static T_3 F_26 ( struct V_24 * V_24 , const char T_4 * V_2 ,
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
static T_3 F_27 ( struct V_24 * V_24 , char T_4 * V_2 , T_2 V_8 ,
T_5 * V_9 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
if ( V_28 -> exit )
return - V_34 ;
return F_5 ( & V_28 -> V_47 ,
V_24 -> V_35 & V_59 ,
V_2 , V_8 , V_9 ) ;
}
static int F_28 ( struct V_28 * V_28 ,
unsigned long V_60 )
{
struct V_1 * V_2 = & V_28 -> V_47 ;
void * V_61 ;
void * V_62 ;
F_3 ( L_2 , V_31 ) ;
if ( V_2 -> V_60 == V_60 )
return 0 ;
if ( ! V_60 )
return - V_53 ;
V_61 = F_17 ( V_60 ) ;
if ( ! V_61 )
return - V_46 ;
V_62 = V_2 -> V_5 ;
F_22 ( & V_28 -> V_57 ) ;
V_2 -> V_5 = V_61 ;
V_2 -> V_60 = V_60 ;
F_29 ( V_2 ) ;
F_23 ( & V_28 -> V_57 ) ;
F_24 ( V_62 ) ;
return 0 ;
}
static inline void F_30 ( struct V_63
* V_64 , int V_65 )
{
F_22 ( & V_64 -> V_66 -> V_57 ) ;
V_64 -> V_65 = V_65 ;
F_23 ( & V_64 -> V_66 -> V_57 ) ;
}
static int F_31 ( struct V_63 * V_64 ,
unsigned long V_60 )
{
struct V_1 * V_2 = & V_64 -> V_67 ;
void * V_61 ;
void * V_62 ;
if ( V_2 -> V_60 == V_60 )
return 0 ;
if ( ! V_60 )
return - V_53 ;
if ( V_64 -> V_65 >= V_68 )
return - V_44 ;
V_61 = F_17 ( V_60 ) ;
if ( ! V_61 )
return - V_46 ;
V_62 = V_2 -> V_5 ;
F_22 ( & V_64 -> V_66 -> V_57 ) ;
V_2 -> V_5 = V_61 ;
V_2 -> V_60 = V_60 ;
F_29 ( V_2 ) ;
F_23 ( & V_64 -> V_66 -> V_57 ) ;
F_24 ( V_62 ) ;
return 0 ;
}
static void F_32 ( unsigned long V_5 )
{
struct V_63 * V_64 = (struct V_63 * ) V_5 ;
V_64 -> V_67 . error = - V_69 ;
F_22 ( & V_64 -> V_66 -> V_57 ) ;
V_64 -> V_65 = V_70 ;
F_23 ( & V_64 -> V_66 -> V_57 ) ;
F_25 ( & V_64 -> V_67 . V_14 ) ;
}
static void F_33 ( struct V_63 * V_64 )
{
struct V_71 * V_72 = & V_64 -> V_73 . V_74 ;
F_34 ( & V_64 -> V_75 ) ;
if ( V_72 -> V_76 ) {
V_64 -> V_75 . V_77 = F_32 ;
V_64 -> V_75 . V_5 = ( unsigned long ) V_64 ;
V_64 -> V_75 . V_78 =
V_79 + 1 + ( V_80 / 2 + V_80 * V_72 -> V_76 ) / 1000 ;
F_35 ( & V_64 -> V_75 ) ;
}
}
static int F_36 ( const T_1 * V_81 , T_2 V_82 ,
const T_1 * V_83 , T_2 V_84 ,
struct V_85 * V_86 )
{
struct V_63 * V_64 = V_86 -> V_29 ;
int V_12 ;
if ( V_64 -> V_67 . error ) {
F_25 ( & V_64 -> V_67 . V_14 ) ;
return 0 ;
}
F_37 ( & V_64 -> V_66 -> V_57 ) ;
if ( V_64 -> V_65 != V_68 ) {
F_38 ( & V_64 -> V_66 -> V_57 ) ;
return 0 ;
}
F_34 ( & V_64 -> V_75 ) ;
F_3 ( L_3 , 6 , V_81 ) ;
V_12 = F_1 ( & V_64 -> V_67 , V_81 ,
V_82 ) ;
if ( V_12 == V_82 ) {
V_12 = F_1 ( & V_64 -> V_67 , V_83 ,
V_84 ) ;
}
if ( V_12 < 0 )
V_64 -> V_67 . error = V_12 ;
if ( V_64 -> V_73 . V_74 . V_87 & V_88 )
V_64 -> V_65 = V_89 ;
F_38 ( & V_64 -> V_66 -> V_57 ) ;
F_25 ( & V_64 -> V_67 . V_14 ) ;
return 0 ;
}
static int F_39 ( const T_1 * V_81 , T_2 V_82 ,
const T_1 * V_83 , T_2 V_84 ,
struct V_90 * V_91 )
{
struct V_63 * V_64 = V_91 -> V_29 ;
struct V_1 * V_67 ;
int V_12 ;
F_37 ( & V_64 -> V_66 -> V_57 ) ;
if ( V_64 -> V_73 . V_92 . V_93 == V_94 ) {
F_38 ( & V_64 -> V_66 -> V_57 ) ;
return 0 ;
}
if ( V_64 -> V_73 . V_92 . V_93 == V_95
|| V_64 -> V_73 . V_92 . V_93 == V_96 )
V_67 = & V_64 -> V_67 ;
else
V_67 = & V_64 -> V_66 -> V_47 ;
if ( V_67 -> error ) {
F_38 ( & V_64 -> V_66 -> V_57 ) ;
F_25 ( & V_67 -> V_14 ) ;
return 0 ;
}
V_12 = F_1 ( V_67 , V_81 , V_82 ) ;
if ( V_12 == V_82 )
V_12 = F_1 ( V_67 , V_83 , V_84 ) ;
if ( V_12 < 0 )
V_67 -> error = V_12 ;
F_38 ( & V_64 -> V_66 -> V_57 ) ;
F_25 ( & V_67 -> V_14 ) ;
return 0 ;
}
static int F_40 ( struct V_63 * V_64 )
{
struct V_97 * V_91 ;
F_30 ( V_64 , V_98 ) ;
switch ( V_64 -> type ) {
case V_99 :
F_34 ( & V_64 -> V_75 ) ;
V_64 -> V_91 . V_74 -> V_100 ( V_64 -> V_91 . V_74 ) ;
break;
case V_101 :
F_41 (feed, &dmxdevfilter->feed.ts, next)
V_91 -> V_102 -> V_100 ( V_91 -> V_102 ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_42 ( struct V_63 * V_86 )
{
struct V_97 * V_91 ;
int V_12 ;
F_30 ( V_86 , V_68 ) ;
switch ( V_86 -> type ) {
case V_99 :
return V_86 -> V_91 . V_74 -> V_103 ( V_86 -> V_91 . V_74 ) ;
case V_101 :
F_41 (feed, &filter->feed.ts, next) {
V_12 = V_91 -> V_102 -> V_103 ( V_91 -> V_102 ) ;
if ( V_12 < 0 ) {
F_40 ( V_86 ) ;
return V_12 ;
}
}
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_43 ( struct V_63 * V_86 )
{
int V_104 ;
struct V_28 * V_28 = V_86 -> V_66 ;
T_6 V_105 = V_86 -> V_73 . V_74 . V_105 ;
for ( V_104 = 0 ; V_104 < V_28 -> V_106 ; V_104 ++ )
if ( V_28 -> V_86 [ V_104 ] . V_65 >= V_68 &&
V_28 -> V_86 [ V_104 ] . type == V_99 &&
V_28 -> V_86 [ V_104 ] . V_73 . V_74 . V_105 == V_105 ) {
F_42 ( & V_28 -> V_86 [ V_104 ] ) ;
return 0 ;
}
V_86 -> V_66 -> V_17 -> V_107 ( V_28 -> V_17 ,
V_86 -> V_91 . V_74 ) ;
return 0 ;
}
static int F_44 ( struct V_63 * V_64 )
{
struct V_97 * V_91 ;
struct V_16 * V_17 ;
if ( V_64 -> V_65 < V_68 )
return 0 ;
switch ( V_64 -> type ) {
case V_99 :
if ( ! V_64 -> V_91 . V_74 )
break;
F_40 ( V_64 ) ;
if ( V_64 -> V_86 . V_74 )
V_64 -> V_91 . V_74 ->
V_108 ( V_64 -> V_91 . V_74 ,
V_64 -> V_86 . V_74 ) ;
F_43 ( V_64 ) ;
V_64 -> V_91 . V_74 = NULL ;
break;
case V_101 :
F_40 ( V_64 ) ;
V_17 = V_64 -> V_66 -> V_17 ;
F_41 (feed, &dmxdevfilter->feed.ts, next) {
V_17 -> V_109 ( V_17 , V_91 -> V_102 ) ;
V_91 -> V_102 = NULL ;
}
break;
default:
if ( V_64 -> V_65 == V_110 )
return 0 ;
return - V_53 ;
}
F_6 ( & V_64 -> V_67 ) ;
return 0 ;
}
static void F_45 ( struct V_63 * V_64 )
{
struct V_97 * V_91 , * V_111 ;
F_46 (feed, tmp, &dmxdevfilter->feed.ts, next) {
F_47 ( & V_91 -> V_112 ) ;
F_48 ( V_91 ) ;
}
F_49 ( ! F_50 ( & V_64 -> V_91 . V_102 ) ) ;
}
static inline int F_51 ( struct V_63 * V_64 )
{
if ( V_64 -> V_65 < V_98 )
return 0 ;
if ( V_64 -> type == V_101 )
F_45 ( V_64 ) ;
V_64 -> type = V_113 ;
F_30 ( V_64 , V_110 ) ;
return 0 ;
}
static int F_52 ( struct V_28 * V_28 ,
struct V_63 * V_86 ,
struct V_97 * V_91 )
{
struct V_114 V_76 = { 0 } ;
struct V_115 * V_72 = & V_86 -> V_73 . V_92 ;
T_7 V_116 ;
int V_12 ;
int V_117 ;
enum V_118 V_119 ;
struct V_90 * V_120 ;
V_91 -> V_102 = NULL ;
V_116 = V_72 -> V_93 ;
V_119 = V_72 -> V_121 ;
if ( V_119 < V_122 )
V_117 = V_123 ;
else
V_117 = 0 ;
if ( V_116 == V_124 )
V_117 |= V_125 ;
else if ( V_116 == V_96 )
V_117 |= V_125 | V_126 ;
else if ( V_116 == V_95 )
V_117 |= V_125 | V_126 | V_127 ;
V_12 = V_28 -> V_17 -> V_128 ( V_28 -> V_17 , & V_91 -> V_102 ,
F_39 ) ;
if ( V_12 < 0 )
return V_12 ;
V_120 = V_91 -> V_102 ;
V_120 -> V_29 = V_86 ;
V_12 = V_120 -> V_129 ( V_120 , V_91 -> V_105 , V_117 , V_119 , 32768 , V_76 ) ;
if ( V_12 < 0 ) {
V_28 -> V_17 -> V_109 ( V_28 -> V_17 , V_120 ) ;
return V_12 ;
}
V_12 = V_120 -> V_103 ( V_120 ) ;
if ( V_12 < 0 ) {
V_28 -> V_17 -> V_109 ( V_28 -> V_17 , V_120 ) ;
return V_12 ;
}
return 0 ;
}
static int F_53 ( struct V_63 * V_86 )
{
struct V_28 * V_28 = V_86 -> V_66 ;
struct V_97 * V_91 ;
void * V_42 ;
int V_12 , V_104 ;
if ( V_86 -> V_65 < V_98 )
return - V_53 ;
if ( V_86 -> V_65 >= V_68 )
F_44 ( V_86 ) ;
if ( ! V_86 -> V_67 . V_5 ) {
V_42 = F_17 ( V_86 -> V_67 . V_60 ) ;
if ( ! V_42 )
return - V_46 ;
F_22 ( & V_86 -> V_66 -> V_57 ) ;
V_86 -> V_67 . V_5 = V_42 ;
F_23 ( & V_86 -> V_66 -> V_57 ) ;
}
F_6 ( & V_86 -> V_67 ) ;
switch ( V_86 -> type ) {
case V_99 :
{
struct V_71 * V_72 = & V_86 -> V_73 . V_74 ;
struct V_85 * * V_130 = & V_86 -> V_86 . V_74 ;
struct V_131 * * V_132 = & V_86 -> V_91 . V_74 ;
* V_130 = NULL ;
* V_132 = NULL ;
for ( V_104 = 0 ; V_104 < V_28 -> V_106 ; V_104 ++ ) {
if ( V_28 -> V_86 [ V_104 ] . V_65 >= V_68 &&
V_28 -> V_86 [ V_104 ] . type == V_99 &&
V_28 -> V_86 [ V_104 ] . V_73 . V_74 . V_105 == V_72 -> V_105 ) {
* V_132 = V_28 -> V_86 [ V_104 ] . V_91 . V_74 ;
break;
}
}
if ( ! * V_132 ) {
V_12 = V_28 -> V_17 -> V_133 ( V_28 -> V_17 ,
V_132 ,
F_36 ) ;
if ( V_12 < 0 ) {
F_54 ( L_4 ,
V_31 ) ;
return V_12 ;
}
V_12 = ( * V_132 ) -> V_129 ( * V_132 , V_72 -> V_105 , 32768 ,
( V_72 -> V_87 & V_134 ) ? 1 : 0 ) ;
if ( V_12 < 0 ) {
F_54 ( L_5 ,
V_31 ) ;
F_43 ( V_86 ) ;
return V_12 ;
}
} else {
F_40 ( V_86 ) ;
}
V_12 = ( * V_132 ) -> V_135 ( * V_132 , V_130 ) ;
if ( V_12 < 0 ) {
F_43 ( V_86 ) ;
V_86 -> V_91 . V_74 -> V_103 ( * V_132 ) ;
F_3 ( L_6 ) ;
return V_12 ;
}
( * V_130 ) -> V_29 = V_86 ;
memcpy ( & ( ( * V_130 ) -> V_136 [ 3 ] ) ,
& ( V_72 -> V_86 . V_86 [ 1 ] ) , V_137 - 1 ) ;
memcpy ( & ( * V_130 ) -> V_138 [ 3 ] ,
& V_72 -> V_86 . V_139 [ 1 ] , V_137 - 1 ) ;
memcpy ( & ( * V_130 ) -> V_140 [ 3 ] ,
& V_72 -> V_86 . V_141 [ 1 ] , V_137 - 1 ) ;
( * V_130 ) -> V_136 [ 0 ] = V_72 -> V_86 . V_86 [ 0 ] ;
( * V_130 ) -> V_138 [ 0 ] = V_72 -> V_86 . V_139 [ 0 ] ;
( * V_130 ) -> V_140 [ 0 ] = V_72 -> V_86 . V_141 [ 0 ] ;
( * V_130 ) -> V_138 [ 1 ] = 0 ;
( * V_130 ) -> V_138 [ 2 ] = 0 ;
V_86 -> V_10 = 0 ;
V_12 = V_86 -> V_91 . V_74 -> V_103 ( V_86 -> V_91 . V_74 ) ;
if ( V_12 < 0 )
return V_12 ;
F_33 ( V_86 ) ;
break;
}
case V_101 :
F_41 (feed, &filter->feed.ts, next) {
V_12 = F_52 ( V_28 , V_86 , V_91 ) ;
if ( V_12 < 0 ) {
F_44 ( V_86 ) ;
return V_12 ;
}
}
break;
default:
return - V_53 ;
}
F_30 ( V_86 , V_68 ) ;
return 0 ;
}
static int F_55 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
int V_104 ;
struct V_63 * V_64 ;
if ( ! V_28 -> V_86 )
return - V_53 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
for ( V_104 = 0 ; V_104 < V_28 -> V_106 ; V_104 ++ )
if ( V_28 -> V_86 [ V_104 ] . V_65 == V_142 )
break;
if ( V_104 == V_28 -> V_106 ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_143 ;
}
V_64 = & V_28 -> V_86 [ V_104 ] ;
F_56 ( & V_64 -> V_32 ) ;
V_24 -> V_27 = V_64 ;
F_18 ( & V_64 -> V_67 , NULL , 8192 ) ;
V_64 -> type = V_113 ;
F_30 ( V_64 , V_110 ) ;
F_57 ( & V_64 -> V_75 ) ;
V_26 -> V_56 ++ ;
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static int F_58 ( struct V_28 * V_28 ,
struct V_63 * V_64 )
{
F_20 ( & V_28 -> V_32 ) ;
F_20 ( & V_64 -> V_32 ) ;
F_44 ( V_64 ) ;
F_51 ( V_64 ) ;
if ( V_64 -> V_67 . V_5 ) {
void * V_42 = V_64 -> V_67 . V_5 ;
F_22 ( & V_28 -> V_57 ) ;
V_64 -> V_67 . V_5 = NULL ;
F_23 ( & V_28 -> V_57 ) ;
F_24 ( V_42 ) ;
}
F_30 ( V_64 , V_142 ) ;
F_25 ( & V_64 -> V_67 . V_14 ) ;
F_16 ( & V_64 -> V_32 ) ;
F_16 ( & V_28 -> V_32 ) ;
return 0 ;
}
static inline void F_59 ( T_8 * V_86 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_137 ; V_104 ++ )
V_86 -> V_141 [ V_104 ] ^= 0xff ;
}
static int F_60 ( struct V_28 * V_28 ,
struct V_63 * V_86 , T_6 V_105 )
{
struct V_97 * V_91 ;
if ( ( V_86 -> type != V_101 ) ||
( V_86 -> V_65 < V_98 ) )
return - V_53 ;
if ( ( V_86 -> V_73 . V_92 . V_93 != V_96 ) &&
( ! F_50 ( & V_86 -> V_91 . V_102 ) ) )
return - V_53 ;
V_91 = F_61 ( sizeof( struct V_97 ) , V_144 ) ;
if ( V_91 == NULL )
return - V_46 ;
V_91 -> V_105 = V_105 ;
F_62 ( & V_91 -> V_112 , & V_86 -> V_91 . V_102 ) ;
if ( V_86 -> V_65 >= V_68 )
return F_52 ( V_28 , V_86 , V_91 ) ;
return 0 ;
}
static int F_63 ( struct V_28 * V_28 ,
struct V_63 * V_86 , T_6 V_105 )
{
struct V_97 * V_91 , * V_111 ;
if ( ( V_86 -> type != V_101 ) ||
( V_86 -> V_65 < V_98 ) )
return - V_53 ;
F_46 (feed, tmp, &filter->feed.ts, next) {
if ( ( V_91 -> V_105 == V_105 ) && ( V_91 -> V_102 != NULL ) ) {
V_91 -> V_102 -> V_100 ( V_91 -> V_102 ) ;
V_86 -> V_66 -> V_17 -> V_109 ( V_86 -> V_66 -> V_17 ,
V_91 -> V_102 ) ;
F_47 ( & V_91 -> V_112 ) ;
F_48 ( V_91 ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_28 * V_28 ,
struct V_63 * V_64 ,
struct V_71 * V_73 )
{
F_3 ( L_7 ,
V_31 , V_73 -> V_105 , V_73 -> V_87 , V_73 -> V_76 ) ;
F_44 ( V_64 ) ;
V_64 -> type = V_99 ;
memcpy ( & V_64 -> V_73 . V_74 ,
V_73 , sizeof( struct V_71 ) ) ;
F_59 ( & V_64 -> V_73 . V_74 . V_86 ) ;
F_30 ( V_64 , V_98 ) ;
if ( V_73 -> V_87 & V_145 )
return F_53 ( V_64 ) ;
return 0 ;
}
static int F_65 ( struct V_28 * V_28 ,
struct V_63 * V_64 ,
struct V_115 * V_73 )
{
int V_12 ;
F_44 ( V_64 ) ;
F_51 ( V_64 ) ;
if ( ( unsigned ) V_73 -> V_121 > V_122 )
return - V_53 ;
V_64 -> type = V_101 ;
memcpy ( & V_64 -> V_73 , V_73 ,
sizeof( struct V_115 ) ) ;
F_66 ( & V_64 -> V_91 . V_102 ) ;
F_30 ( V_64 , V_98 ) ;
V_12 = F_60 ( V_28 , V_64 ,
V_64 -> V_73 . V_92 . V_105 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_73 -> V_87 & V_145 )
return F_53 ( V_64 ) ;
return 0 ;
}
static T_3 F_67 ( struct V_63 * V_146 ,
struct V_24 * V_24 , char T_4 * V_2 ,
T_2 V_8 , T_5 * V_9 )
{
int V_147 , V_148 ;
int V_149 = 0 ;
if ( V_146 -> V_10 <= 0 ) {
V_148 = 3 + V_146 -> V_10 ;
if ( V_148 > V_8 )
V_148 = V_8 ;
V_147 = F_5 ( & V_146 -> V_67 ,
V_24 -> V_35 & V_59 ,
V_2 , V_148 , V_9 ) ;
if ( V_147 < 0 ) {
V_146 -> V_10 = 0 ;
return V_147 ;
}
if ( F_68 ( V_146 -> V_150 - V_146 -> V_10 , V_2 , V_147 ) )
return - V_151 ;
V_2 += V_147 ;
V_149 = V_147 ;
V_8 -= V_147 ;
V_146 -> V_10 -= V_147 ;
if ( V_146 -> V_10 > - 3 )
return V_149 ;
V_146 -> V_10 = ( ( V_146 -> V_150 [ 1 ] << 8 ) | V_146 -> V_150 [ 2 ] ) & 0xfff ;
if ( ! V_8 )
return V_149 ;
}
if ( V_8 > V_146 -> V_10 )
V_8 = V_146 -> V_10 ;
V_147 = F_5 ( & V_146 -> V_67 ,
V_24 -> V_35 & V_59 ,
V_2 , V_8 , V_9 ) ;
if ( V_147 < 0 )
return V_147 ;
V_146 -> V_10 -= V_147 ;
return ( V_147 + V_149 ) ;
}
static T_3
F_69 ( struct V_24 * V_24 , char T_4 * V_2 , T_2 V_8 ,
T_5 * V_9 )
{
struct V_63 * V_64 = V_24 -> V_27 ;
int V_12 ;
if ( F_15 ( & V_64 -> V_32 ) )
return - V_33 ;
if ( V_64 -> type == V_99 )
V_12 = F_67 ( V_64 , V_24 , V_2 , V_8 , V_9 ) ;
else
V_12 = F_5 ( & V_64 -> V_67 ,
V_24 -> V_35 & V_59 ,
V_2 , V_8 , V_9 ) ;
F_16 ( & V_64 -> V_32 ) ;
return V_12 ;
}
static int F_70 ( struct V_24 * V_24 ,
unsigned int V_152 , void * V_153 )
{
struct V_63 * V_64 = V_24 -> V_27 ;
struct V_28 * V_28 = V_64 -> V_66 ;
unsigned long V_154 = ( unsigned long ) V_153 ;
int V_12 = 0 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
switch ( V_152 ) {
case V_155 :
if ( F_15 ( & V_64 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
if ( V_64 -> V_65 < V_98 )
V_12 = - V_53 ;
else
V_12 = F_53 ( V_64 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_156 :
if ( F_15 ( & V_64 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_44 ( V_64 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_157 :
if ( F_15 ( & V_64 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_64 ( V_28 , V_64 , V_153 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_158 :
if ( F_15 ( & V_64 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_65 ( V_28 , V_64 , V_153 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_159 :
if ( F_15 ( & V_64 -> V_32 ) ) {
F_16 ( & V_28 -> V_32 ) ;
return - V_33 ;
}
V_12 = F_31 ( V_64 , V_154 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_160 :
if ( ! V_28 -> V_17 -> V_161 ) {
V_12 = - V_53 ;
break;
}
V_28 -> V_17 -> V_161 ( V_28 -> V_17 , V_153 ) ;
break;
#if 0
case DMX_GET_CAPS:
if (!dmxdev->demux->get_caps) {
ret = -EINVAL;
break;
}
ret = dmxdev->demux->get_caps(dmxdev->demux, parg);
break;
case DMX_SET_SOURCE:
if (!dmxdev->demux->set_source) {
ret = -EINVAL;
break;
}
ret = dmxdev->demux->set_source(dmxdev->demux, parg);
break;
#endif
case V_162 :
if ( ! V_28 -> V_17 -> V_163 ) {
V_12 = - V_53 ;
break;
}
V_12 = V_28 -> V_17 -> V_163 ( V_28 -> V_17 ,
( (struct V_164 * ) V_153 ) -> V_165 ,
& ( (struct V_164 * ) V_153 ) -> V_166 ,
& ( (struct V_164 * ) V_153 ) -> V_167 ) ;
break;
case V_168 :
if ( F_15 ( & V_64 -> V_32 ) ) {
V_12 = - V_33 ;
break;
}
V_12 = F_60 ( V_28 , V_64 , * ( T_6 * ) V_153 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
case V_169 :
if ( F_15 ( & V_64 -> V_32 ) ) {
V_12 = - V_33 ;
break;
}
V_12 = F_63 ( V_28 , V_64 , * ( T_6 * ) V_153 ) ;
F_16 ( & V_64 -> V_32 ) ;
break;
default:
V_12 = - V_53 ;
break;
}
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static long F_71 ( struct V_24 * V_24 , unsigned int V_152 ,
unsigned long V_154 )
{
return F_72 ( V_24 , V_152 , V_154 , F_70 ) ;
}
static unsigned int F_73 ( struct V_24 * V_24 , T_9 * V_170 )
{
struct V_63 * V_64 = V_24 -> V_27 ;
unsigned int V_139 = 0 ;
if ( ( ! V_64 ) || V_64 -> V_66 -> exit )
return V_171 ;
F_74 ( V_24 , & V_64 -> V_67 . V_14 , V_170 ) ;
if ( V_64 -> V_65 != V_68 &&
V_64 -> V_65 != V_89 &&
V_64 -> V_65 != V_70 )
return 0 ;
if ( V_64 -> V_67 . error )
V_139 |= ( V_172 | V_173 | V_174 | V_171 ) ;
if ( ! F_7 ( & V_64 -> V_67 ) )
V_139 |= ( V_172 | V_173 | V_174 ) ;
return V_139 ;
}
static int F_75 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
struct V_63 * V_64 = V_24 -> V_27 ;
struct V_28 * V_28 = V_64 -> V_66 ;
int V_12 ;
V_12 = F_58 ( V_28 , V_64 ) ;
F_20 ( & V_28 -> V_32 ) ;
V_28 -> V_26 -> V_56 -- ;
if( V_28 -> V_26 -> V_56 == 1 && V_28 -> exit == 1 ) {
F_16 ( & V_28 -> V_32 ) ;
F_25 ( & V_28 -> V_26 -> V_58 ) ;
} else
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static int F_76 ( struct V_24 * V_24 ,
unsigned int V_152 , void * V_153 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
unsigned long V_154 = ( unsigned long ) V_153 ;
int V_12 ;
if ( F_15 ( & V_28 -> V_32 ) )
return - V_33 ;
switch ( V_152 ) {
case V_159 :
V_12 = F_28 ( V_28 , V_154 ) ;
break;
default:
V_12 = - V_53 ;
break;
}
F_16 ( & V_28 -> V_32 ) ;
return V_12 ;
}
static long F_77 ( struct V_24 * V_24 ,
unsigned int V_152 , unsigned long V_154 )
{
return F_72 ( V_24 , V_152 , V_154 , F_76 ) ;
}
static unsigned int F_78 ( struct V_24 * V_24 , T_9 * V_170 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_28 * V_28 = V_26 -> V_29 ;
unsigned int V_139 = 0 ;
F_3 ( L_2 , V_31 ) ;
if ( V_28 -> exit )
return V_171 ;
F_74 ( V_24 , & V_28 -> V_47 . V_14 , V_170 ) ;
if ( ( V_24 -> V_35 & V_36 ) == V_41 ) {
if ( V_28 -> V_47 . error )
V_139 |= ( V_172 | V_173 | V_174 | V_171 ) ;
if ( ! F_7 ( & V_28 -> V_47 ) )
V_139 |= ( V_172 | V_173 | V_174 ) ;
} else
V_139 |= ( V_175 | V_176 | V_174 ) ;
return V_139 ;
}
int F_79 ( struct V_28 * V_28 , struct V_177 * V_177 )
{
int V_104 ;
if ( V_28 -> V_17 -> V_178 ( V_28 -> V_17 ) < 0 )
return - V_179 ;
V_28 -> V_86 = F_17 ( V_28 -> V_106 * sizeof( struct V_63 ) ) ;
if ( ! V_28 -> V_86 )
return - V_46 ;
F_56 ( & V_28 -> V_32 ) ;
F_80 ( & V_28 -> V_57 ) ;
for ( V_104 = 0 ; V_104 < V_28 -> V_106 ; V_104 ++ ) {
V_28 -> V_86 [ V_104 ] . V_66 = V_28 ;
V_28 -> V_86 [ V_104 ] . V_67 . V_5 = NULL ;
F_30 ( & V_28 -> V_86 [ V_104 ] ,
V_142 ) ;
}
F_81 ( V_177 , & V_28 -> V_26 , & V_180 , V_28 ,
V_181 , V_28 -> V_106 ) ;
F_81 ( V_177 , & V_28 -> V_182 , & V_183 ,
V_28 , V_184 , V_28 -> V_106 ) ;
F_18 ( & V_28 -> V_47 , NULL , 8192 ) ;
return 0 ;
}
void F_82 ( struct V_28 * V_28 )
{
V_28 -> exit = 1 ;
if ( V_28 -> V_26 -> V_56 > 1 ) {
F_83 ( V_28 -> V_26 -> V_58 ,
V_28 -> V_26 -> V_56 == 1 ) ;
}
if ( V_28 -> V_182 -> V_56 > 1 ) {
F_83 ( V_28 -> V_182 -> V_58 ,
V_28 -> V_182 -> V_56 == 1 ) ;
}
F_84 ( V_28 -> V_26 ) ;
F_84 ( V_28 -> V_182 ) ;
F_24 ( V_28 -> V_86 ) ;
V_28 -> V_86 = NULL ;
V_28 -> V_17 -> V_185 ( V_28 -> V_17 ) ;
}
