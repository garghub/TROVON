static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
V_3 = F_4 (
V_2 ,
V_5 ) ;
else
V_3 = F_4 (
V_2 ,
V_6 ) ;
V_4 = F_5 ( V_3 ) ;
if ( V_4 <= 0 )
V_4 = 1 ;
return V_4 ;
}
static void F_6 ( struct V_7 * V_8 )
{
if ( F_7 ( & V_8 -> V_9 ) ) {
F_8 ( V_8 -> V_10 ) ;
F_9 ( V_8 , V_11 ) ;
}
}
static void F_10 ( struct V_7 * V_8 )
{
F_11 ( & V_8 -> V_12 ) ;
if ( F_12 ( & V_8 -> V_13 ) )
F_13 ( & V_8 -> V_9 ) ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = 0 ;
F_14 ( & V_8 -> V_12 ) ;
}
static void F_15 ( struct V_7 * V_8 , int V_17 )
{
int V_18 = F_16 () % V_17 ;
V_8 -> V_14 = 1 ;
if ( ! F_17 ( & V_8 -> V_13 , V_19 + V_18 + 2 ) )
F_18 ( & V_8 -> V_9 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_18 = F_16 () % V_2 -> V_20 ;
V_2 -> V_21 = 1 ;
if ( ! F_17 ( & V_2 -> V_22 , V_19 + V_18 + 2 ) )
F_20 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_23 )
{
int V_18 = F_16 () % V_23 ;
if ( ! F_17 ( & V_2 -> V_24 , V_19 + V_18 + 2 ) )
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_7 * V_8 , int V_17 )
{
F_11 ( & V_8 -> V_12 ) ;
V_8 -> V_16 = 0 ;
if ( F_12 ( & V_8 -> V_13 ) ) {
if ( ( long ) ( V_8 -> V_13 . V_25 - V_19 ) < V_17 ) {
F_23 ( & V_8 -> V_13 ) ;
V_8 -> V_14 = 1 ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
F_13 ( & V_8 -> V_9 ) ;
}
F_15 ( V_8 , V_17 ) ;
F_14 ( & V_8 -> V_12 ) ;
}
static int F_24 ( struct V_7 * V_26 , struct V_27 * V_28 , int type ,
int V_29 , int V_30 )
{
switch ( type ) {
case V_31 :
case V_32 :
if ( V_29 || V_30 )
return 0 ;
if ( ! ( V_26 -> V_33 && ! V_28 -> V_34 ) ) {
if ( V_26 -> V_35 == V_36 )
return 1 ;
if ( V_28 -> V_37 [ V_36 ] )
return type == V_31 ;
return V_26 -> V_38 [ V_39 ] ==
V_28 -> V_37 [ V_39 ] ;
}
return 0 ;
case V_40 :
if ( V_29 || V_30 )
return 0 ;
return V_28 -> V_37 [ V_36 ] != 0 ;
case V_41 :
if ( V_29 || V_30 )
return 0 ;
if ( V_26 -> V_38 [ V_39 ] == 0 ||
V_28 -> V_37 [ V_36 ] )
return 0 ;
return V_26 -> V_38 [ V_39 ] ==
V_28 -> V_37 [ V_39 ] ;
case V_42 :
if ( V_29 || ! V_28 -> V_43 )
return 0 ;
return ( V_26 -> V_35 == V_36 ) ^ V_30 ;
case V_44 :
if ( V_26 -> V_35 == V_36 )
return V_29 || ( V_28 -> V_43 && V_30 ) ;
return V_28 -> V_43 && ! V_29 && ! V_30 ;
}
return 0 ;
}
static int
F_25 ( struct V_7 * V_26 , int type , int V_29 , int V_30 )
{
struct V_27 * V_28 ;
int V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) )
continue;
V_45 ++ ;
}
return V_45 ;
}
static struct V_48 * F_26 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_48 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
struct V_60 V_61 ;
int V_62 = F_28 ( V_50 ) ;
int V_63 = V_50 -> V_64 ;
unsigned int V_65 = V_51 ;
while ( 1 ) {
V_52 = F_29 ( V_65 + V_62 + V_63 ,
V_66 | V_67 ) ;
if ( V_52 )
break;
V_65 >>= 1 ;
if ( V_65 < 256 )
return NULL ;
}
V_52 -> V_68 = V_69 ;
V_54 = F_30 ( V_59 , & V_61 , NULL , V_70 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_31 ( V_54 ) ) {
F_32 ( V_52 ) ;
return NULL ;
}
F_33 ( V_52 , & V_54 -> V_73 ) ;
V_52 -> V_50 = V_50 ;
V_52 -> V_74 = F_34 ( V_52 ) -
F_35 ( V_51 , F_34 ( V_52 ) ) ;
F_36 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_56 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_56 -> V_75 = 4 ;
V_56 -> V_76 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_56 -> V_77 = 0xc0 ;
V_56 -> V_78 = F_40 ( V_79 ) ;
V_56 -> V_80 = 1 ;
V_56 -> V_81 = V_61 . V_81 ;
V_56 -> V_82 = V_61 . V_82 ;
V_56 -> V_83 = V_71 ;
V_56 -> V_84 = 0 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 0 ] = V_86 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 1 ] = 4 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 2 ] = 0 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 3 ] = 0 ;
V_52 -> V_87 = V_52 -> V_88 + sizeof( struct V_55 ) + 4 ;
F_39 ( V_52 , sizeof( * V_58 ) ) ;
V_58 = F_42 ( V_52 ) ;
V_58 -> type = V_89 ;
V_58 -> V_90 = 0 ;
V_58 -> V_91 = 0 ;
V_58 -> V_92 = 0 ;
V_58 -> V_93 = 0 ;
return V_52 ;
}
static int F_43 ( struct V_48 * V_52 )
{
struct V_94 * V_58 = F_44 ( V_52 ) ;
const int V_95 = F_45 ( V_52 ) - F_46 ( V_52 ) ;
V_58 -> V_91 = F_47 ( F_44 ( V_52 ) , V_95 ) ;
return F_48 ( V_52 ) ;
}
static int F_49 ( struct V_7 * V_26 , int type , int V_96 , int V_97 )
{
return sizeof( struct V_98 ) + 4 * F_25 ( V_26 , type , V_96 , V_97 ) ;
}
static struct V_48 * F_50 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_98 * * V_99 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_100 ;
struct V_98 * V_101 ;
if ( ! V_52 )
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
if ( ! V_52 )
return NULL ;
V_101 = (struct V_98 * ) F_39 ( V_52 , sizeof( struct V_98 ) ) ;
V_101 -> V_102 = type ;
V_101 -> V_103 = 0 ;
V_101 -> V_104 = 0 ;
V_101 -> V_105 = V_26 -> V_106 ;
V_100 = F_42 ( V_52 ) ;
V_100 -> V_93 = F_40 ( F_51 ( V_100 -> V_93 ) + 1 ) ;
* V_99 = V_101 ;
return V_52 ;
}
static struct V_48 * F_52 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_100 ;
struct V_98 * V_101 = NULL ;
struct V_27 * V_28 , * V_107 , * V_108 , * * V_109 ;
int V_45 , V_110 , V_111 , V_112 , V_113 ;
if ( V_26 -> V_106 == V_114 )
return V_52 ;
if ( F_53 ( V_26 -> V_106 ) && ! V_115 )
return V_52 ;
V_112 = type == V_31 ||
type == V_32 ;
V_113 = type == V_32 ||
type == V_41 ;
V_110 = V_45 = 0 ;
V_109 = V_30 ? & V_26 -> V_116 : & V_26 -> V_46 ;
if ( ! * V_109 )
goto V_117;
V_100 = V_52 ? F_42 ( V_52 ) : NULL ;
if ( V_113 ) {
if ( V_100 && V_100 -> V_93 &&
F_54 ( V_52 ) < F_49 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
}
}
V_111 = 1 ;
V_108 = NULL ;
for ( V_28 = * V_109 ; V_28 ; V_28 = V_107 ) {
T_1 * V_118 ;
V_107 = V_28 -> V_47 ;
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_108 = V_28 ;
continue;
}
if ( V_112 )
V_28 -> V_34 = 0 ;
if ( F_54 ( V_52 ) < sizeof( T_1 ) +
V_111 * sizeof( struct V_98 ) ) {
if ( V_113 && ! V_111 )
break;
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
V_111 = 1 ;
V_45 = 0 ;
}
if ( V_111 ) {
V_52 = F_50 ( V_52 , V_26 , type , & V_101 ) ;
V_111 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_118 = ( T_1 * ) F_39 ( V_52 , sizeof( T_1 ) ) ;
* V_118 = V_28 -> V_119 ;
V_45 ++ ; V_110 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_109 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
continue;
}
}
V_108 = V_28 ;
}
V_117:
if ( ! V_110 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_120 || V_112 ) {
if ( V_52 && F_54 ( V_52 ) < sizeof( struct V_98 ) ) {
F_43 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_50 ( V_52 , V_26 , type , & V_101 ) ;
}
}
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_112 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
int type ;
if ( ! V_26 ) {
F_57 () ;
F_58 (in_dev, pmc) {
if ( V_26 -> V_106 == V_114 )
continue;
if ( F_53 ( V_26 -> V_106 ) &&
! V_115 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_59 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_43 ( V_52 ) ;
}
static void F_60 ( struct V_27 * * V_121 )
{
struct V_27 * V_108 , * V_107 , * V_28 ;
V_108 = NULL ;
for ( V_28 = * V_121 ; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_121 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
} else
V_108 = V_28 ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_122 , * V_123 ;
struct V_48 * V_52 = NULL ;
int type , V_124 ;
F_57 () ;
F_11 ( & V_2 -> V_125 ) ;
V_122 = NULL ;
for ( V_26 = V_2 -> V_126 ; V_26 ; V_26 = V_123 ) {
V_123 = V_26 -> V_127 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_124 = V_44 ;
V_52 = F_52 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_52 ( V_52 , V_26 , V_124 , 1 , 1 ) ;
}
if ( V_26 -> V_120 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_52 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_120 -- ;
if ( V_26 -> V_120 == 0 ) {
F_60 ( & V_26 -> V_116 ) ;
F_60 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_120 == 0 && ! V_26 -> V_116 && ! V_26 -> V_46 ) {
if ( V_122 )
V_122 -> V_127 = V_123 ;
else
V_2 -> V_126 = V_123 ;
F_8 ( V_26 -> V_10 ) ;
F_55 ( V_26 ) ;
} else
V_122 = V_26 ;
}
F_14 ( & V_2 -> V_125 ) ;
F_58 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_124 = V_42 ;
} else {
type = V_42 ;
V_124 = V_44 ;
}
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_52 ( V_52 , V_26 , V_124 , 0 , 1 ) ;
if ( V_26 -> V_120 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_120 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_59 () ;
if ( ! V_52 )
return;
( void ) F_43 ( V_52 ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_128 ;
struct V_94 * V_129 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
T_1 V_130 = V_26 ? V_26 -> V_106 : 0 ;
struct V_60 V_61 ;
T_1 V_73 ;
int V_62 , V_63 ;
if ( type == V_89 )
return F_56 ( V_2 , V_26 ) ;
if ( F_53 ( V_130 ) && ! V_115 )
return 0 ;
if ( type == V_131 )
V_73 = V_132 ;
else
V_73 = V_130 ;
V_54 = F_30 ( V_59 , & V_61 , NULL , V_73 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_31 ( V_54 ) )
return - 1 ;
V_62 = F_28 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_29 ( V_133 + V_62 + V_63 , V_66 ) ;
if ( ! V_52 ) {
F_63 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_68 = V_69 ;
F_33 ( V_52 , & V_54 -> V_73 ) ;
F_36 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_128 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_128 -> V_75 = 4 ;
V_128 -> V_76 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_128 -> V_77 = 0xc0 ;
V_128 -> V_78 = F_40 ( V_79 ) ;
V_128 -> V_80 = 1 ;
V_128 -> V_81 = V_73 ;
V_128 -> V_82 = V_61 . V_82 ;
V_128 -> V_83 = V_71 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_85 * ) & V_128 [ 1 ] ) [ 0 ] = V_86 ;
( ( V_85 * ) & V_128 [ 1 ] ) [ 1 ] = 4 ;
( ( V_85 * ) & V_128 [ 1 ] ) [ 2 ] = 0 ;
( ( V_85 * ) & V_128 [ 1 ] ) [ 3 ] = 0 ;
V_129 = (struct V_94 * ) F_39 ( V_52 , sizeof( struct V_94 ) ) ;
V_129 -> type = type ;
V_129 -> V_134 = 0 ;
V_129 -> V_91 = 0 ;
V_129 -> V_130 = V_130 ;
V_129 -> V_91 = F_47 ( ( void * ) V_129 , sizeof( struct V_94 ) ) ;
return F_48 ( V_52 ) ;
}
static void F_64 ( unsigned long V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 ;
V_2 -> V_21 = 0 ;
F_56 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_65 ( unsigned long V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_135 ;
F_61 ( V_2 ) ;
if ( V_2 -> V_136 ) {
V_2 -> V_136 -- ;
F_21 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_136 = V_2 -> V_137 ? : V_138 ;
F_21 ( V_2 , 1 ) ;
}
static void F_67 ( unsigned long V_135 )
{
struct V_7 * V_8 = (struct V_7 * ) V_135 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_68 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_69 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_62 ( V_2 , V_8 , V_139 ) ;
else if ( F_3 ( V_2 ) )
F_62 ( V_2 , V_8 , V_140 ) ;
else
F_62 ( V_2 , V_8 , V_89 ) ;
F_6 ( V_8 ) ;
}
static int F_70 ( struct V_7 * V_26 , int V_141 , T_1 * V_142 )
{
struct V_27 * V_28 ;
int V_143 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_141 )
break;
for ( V_143 = 0 ; V_143 < V_141 ; V_143 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_142 [ V_143 ] == V_28 -> V_119 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_141 )
return 0 ;
return 1 ;
}
static int F_71 ( struct V_7 * V_26 , int V_141 , T_1 * V_142 )
{
struct V_27 * V_28 ;
int V_143 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_70 ( V_26 , V_141 , V_142 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_141 )
break;
for ( V_143 = 0 ; V_143 < V_141 ; V_143 ++ )
if ( V_142 [ V_143 ] == V_28 -> V_119 ) {
V_28 -> V_34 = 1 ;
V_45 ++ ;
break;
}
}
if ( ! V_45 ) {
V_26 -> V_33 = 0 ;
return 0 ;
}
V_26 -> V_33 = 1 ;
return 1 ;
}
static bool F_72 ( struct V_1 * V_2 , T_1 V_130 )
{
struct V_7 * V_8 ;
if ( V_130 == V_114 )
return false ;
if ( F_53 ( V_130 ) && ! V_115 )
return false ;
F_57 () ;
F_58 (in_dev, im) {
if ( V_8 -> V_106 == V_130 ) {
F_10 ( V_8 ) ;
break;
}
}
F_59 () ;
return false ;
}
static bool F_73 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_144 )
{
struct V_94 * V_129 = F_44 ( V_52 ) ;
struct V_145 * V_146 = F_74 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_130 = V_129 -> V_130 ;
int V_17 ;
int V_147 = 0 ;
if ( V_144 == 8 ) {
if ( V_129 -> V_134 == 0 ) {
V_17 = V_148 ;
V_2 -> V_149 = V_19 +
V_150 ;
V_130 = 0 ;
} else {
V_17 = V_129 -> V_134 * ( V_151 / V_152 ) ;
V_2 -> V_153 = V_19 +
V_154 ;
}
V_2 -> V_136 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
} else if ( V_144 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_148 ;
V_130 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_77 ( V_146 -> V_134 ) * ( V_151 / V_152 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_78 ( V_52 , sizeof( struct V_145 ) ) )
return true ;
V_146 = F_74 ( V_52 ) ;
if ( V_146 -> V_141 ) {
if ( ! F_78 ( V_52 , sizeof( struct V_145 )
+ F_51 ( V_146 -> V_141 ) * sizeof( T_1 ) ) )
return true ;
V_146 = F_74 ( V_52 ) ;
}
V_17 = F_77 ( V_146 -> V_134 ) * ( V_151 / V_152 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_146 -> V_155 )
V_2 -> V_137 = V_146 -> V_155 ;
if ( ! V_130 ) {
if ( V_146 -> V_141 )
return true ;
F_19 ( V_2 ) ;
return false ;
}
V_147 = V_146 -> V_141 != 0 ;
}
F_57 () ;
F_58 (in_dev, im) {
int V_156 ;
if ( V_130 && V_130 != V_8 -> V_106 )
continue;
if ( V_8 -> V_106 == V_114 )
continue;
if ( F_53 ( V_8 -> V_106 ) &&
! V_115 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_147 ;
else
V_8 -> V_33 = V_147 ;
V_156 = ! V_8 -> V_33 ||
F_71 ( V_8 , F_51 ( V_146 -> V_141 ) , V_146 -> V_142 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_156 )
F_22 ( V_8 , V_17 ) ;
}
F_59 () ;
return false ;
}
int F_79 ( struct V_48 * V_52 )
{
struct V_94 * V_129 ;
struct V_1 * V_2 = F_80 ( V_52 -> V_50 ) ;
int V_144 = V_52 -> V_144 ;
bool V_157 = true ;
if ( ! V_2 )
goto V_158;
if ( ! F_78 ( V_52 , sizeof( struct V_94 ) ) )
goto V_158;
if ( F_81 ( V_52 ) )
goto V_158;
V_129 = F_44 ( V_52 ) ;
switch ( V_129 -> type ) {
case V_159 :
V_157 = F_73 ( V_2 , V_52 , V_144 ) ;
break;
case V_139 :
case V_140 :
if ( F_82 ( F_83 ( V_52 ) ) )
break;
if ( V_52 -> V_160 == V_161 ||
V_52 -> V_160 == V_162 )
V_157 = F_72 ( V_2 , V_129 -> V_130 ) ;
break;
case V_163 :
#ifdef F_84
return F_85 ( V_52 ) ;
#endif
case V_89 :
case V_164 :
case V_165 :
case V_131 :
case V_166 :
case V_167 :
break;
default:
break;
}
V_158:
if ( V_157 )
F_32 ( V_52 ) ;
else
F_86 ( V_52 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , T_1 V_168 )
{
char V_169 [ V_170 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_88 ( V_168 , V_169 , V_50 , 0 ) == 0 )
F_89 ( V_50 , V_169 ) ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_168 )
{
char V_169 [ V_170 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_88 ( V_168 , V_169 , V_50 , 0 ) == 0 )
F_91 ( V_50 , V_169 ) ;
}
static void F_92 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
V_26 = F_93 ( sizeof( * V_26 ) , V_171 ) ;
if ( ! V_26 )
return;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_20 ( V_2 ) ;
V_26 -> V_106 = V_8 -> V_106 ;
V_26 -> V_120 = V_2 -> V_137 ? : V_138 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_116 = V_8 -> V_116 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_116 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_120 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_125 ) ;
V_26 -> V_127 = V_2 -> V_126 ;
V_2 -> V_126 = V_26 ;
F_14 ( & V_2 -> V_125 ) ;
}
static void F_94 ( struct V_1 * V_2 , T_1 V_106 )
{
struct V_7 * V_26 , * V_122 ;
struct V_27 * V_28 , * V_107 ;
F_11 ( & V_2 -> V_125 ) ;
V_122 = NULL ;
for ( V_26 = V_2 -> V_126 ; V_26 ; V_26 = V_26 -> V_127 ) {
if ( V_26 -> V_106 == V_106 )
break;
V_122 = V_26 ;
}
if ( V_26 ) {
if ( V_122 )
V_122 -> V_127 = V_26 -> V_127 ;
else
V_2 -> V_126 = V_26 -> V_127 ;
}
F_14 ( & V_2 -> V_125 ) ;
if ( V_26 ) {
for ( V_28 = V_26 -> V_116 ; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
}
F_8 ( V_26 -> V_10 ) ;
F_55 ( V_26 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_172 ;
F_11 ( & V_2 -> V_125 ) ;
V_26 = V_2 -> V_126 ;
V_2 -> V_126 = NULL ;
F_14 ( & V_2 -> V_125 ) ;
for (; V_26 ; V_26 = V_172 ) {
V_172 = V_26 -> V_127 ;
F_95 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_55 ( V_26 ) ;
}
F_57 () ;
F_58 (in_dev, pmc) {
struct V_27 * V_28 , * V_107 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_116 ;
V_26 -> V_116 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
}
}
F_59 () ;
}
static void F_96 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_97
int V_15 ;
#endif
if ( V_8 -> V_173 ) {
V_8 -> V_173 = 0 ;
F_90 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_97
if ( V_8 -> V_106 == V_114 )
return;
if ( F_53 ( V_8 -> V_106 ) && ! V_115 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_174 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_62 ( V_2 , V_8 , V_131 ) ;
return;
}
F_92 ( V_2 , V_8 ) ;
F_66 ( V_2 ) ;
}
#endif
}
static void F_98 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
if ( V_8 -> V_173 == 0 ) {
V_8 -> V_173 = 1 ;
F_87 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_97
if ( V_8 -> V_106 == V_114 )
return;
if ( F_53 ( V_8 -> V_106 ) && ! V_115 )
return;
if ( V_2 -> V_174 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_175 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_120 = V_2 -> V_137 ? : V_138 ;
F_66 ( V_2 ) ;
#endif
}
static T_2 F_99 ( const struct V_7 * V_8 )
{
return F_100 ( ( V_176 T_2 ) V_8 -> V_106 , V_177 ) ;
}
static void F_101 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_178 ;
T_2 V_179 ;
V_178 = F_102 ( V_2 -> V_178 ) ;
if ( V_178 ) {
V_179 = F_99 ( V_8 ) ;
V_8 -> V_180 = V_178 [ V_179 ] ;
F_103 ( V_178 [ V_179 ] , V_8 ) ;
return;
}
if ( V_2 -> V_181 < 4 )
return;
V_178 = F_93 ( sizeof( struct V_7 * ) << V_177 ,
V_171 ) ;
if ( ! V_178 )
return;
F_104 (in_dev, im) {
V_179 = F_99 ( V_8 ) ;
V_8 -> V_180 = V_178 [ V_179 ] ;
F_105 ( V_178 [ V_179 ] , V_8 ) ;
}
F_103 ( V_2 -> V_178 , V_178 ) ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_178 = F_102 ( V_2 -> V_178 ) ;
struct V_7 * V_182 ;
if ( ! V_178 )
return;
V_178 += F_99 ( V_8 ) ;
while ( ( V_182 = F_102 ( * V_178 ) ) != V_8 )
V_178 = & V_182 -> V_180 ;
* V_178 = V_8 -> V_180 ;
}
void F_107 ( struct V_1 * V_2 , T_1 V_168 )
{
struct V_7 * V_8 ;
F_108 () ;
F_104 (in_dev, im) {
if ( V_8 -> V_106 == V_168 ) {
V_8 -> V_183 ++ ;
F_109 ( V_2 , & V_168 , V_39 , 0 , NULL , 0 ) ;
goto V_184;
}
}
V_8 = F_93 ( sizeof( * V_8 ) , V_171 ) ;
if ( ! V_8 )
goto V_184;
V_8 -> V_183 = 1 ;
V_8 -> V_10 = V_2 ;
F_20 ( V_2 ) ;
V_8 -> V_106 = V_168 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_110 ( & V_8 -> V_9 , 1 ) ;
F_111 ( & V_8 -> V_12 ) ;
#ifdef F_97
F_112 ( & V_8 -> V_13 , F_67 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_138 ;
#endif
V_8 -> V_185 = V_2 -> V_186 ;
V_2 -> V_181 ++ ;
F_103 ( V_2 -> V_186 , V_8 ) ;
F_101 ( V_2 , V_8 ) ;
#ifdef F_97
F_94 ( V_2 , V_8 -> V_106 ) ;
#endif
F_98 ( V_8 ) ;
if ( ! V_2 -> V_174 )
F_113 ( V_2 ) ;
V_184:
return;
}
static int F_114 ( struct V_48 * V_52 )
{
const struct V_55 * V_128 ;
unsigned int V_144 ;
unsigned int V_187 = F_115 ( V_52 ) + sizeof( * V_128 ) ;
if ( ! F_78 ( V_52 , V_187 ) )
return - V_188 ;
V_128 = F_38 ( V_52 ) ;
if ( V_128 -> V_75 != 4 || F_116 ( V_52 ) < sizeof( * V_128 ) )
return - V_188 ;
V_187 += F_116 ( V_52 ) - sizeof( * V_128 ) ;
if ( ! F_78 ( V_52 , V_187 ) )
return - V_188 ;
V_128 = F_38 ( V_52 ) ;
if ( F_117 ( F_118 ( ( V_85 * ) V_128 , V_128 -> V_76 ) ) )
return - V_188 ;
V_144 = F_115 ( V_52 ) + F_51 ( V_128 -> V_84 ) ;
if ( V_52 -> V_144 < V_144 || V_144 < V_187 )
return - V_188 ;
F_119 ( V_52 , V_187 ) ;
return 0 ;
}
static int F_120 ( struct V_48 * V_52 )
{
unsigned int V_144 = F_121 ( V_52 ) ;
V_144 += sizeof( struct V_57 ) ;
return F_78 ( V_52 , V_144 ) ? 0 : - V_188 ;
}
static int F_122 ( struct V_48 * V_52 )
{
unsigned int V_144 = F_121 ( V_52 ) ;
V_144 += sizeof( struct V_94 ) ;
if ( V_52 -> V_144 < V_144 )
return - V_188 ;
if ( V_52 -> V_144 != V_144 ) {
V_144 += sizeof( struct V_145 ) - sizeof( struct V_94 ) ;
if ( V_52 -> V_144 < V_144 || ! F_78 ( V_52 , V_144 ) )
return - V_188 ;
}
if ( ! F_44 ( V_52 ) -> V_130 &&
F_38 ( V_52 ) -> V_81 != F_123 ( V_189 ) )
return - V_188 ;
return 0 ;
}
static int F_124 ( struct V_48 * V_52 )
{
switch ( F_44 ( V_52 ) -> type ) {
case V_131 :
case V_139 :
case V_140 :
return 0 ;
case V_89 :
return F_120 ( V_52 ) ;
case V_159 :
return F_122 ( V_52 ) ;
default:
return - V_190 ;
}
}
static inline T_4 F_125 ( struct V_48 * V_52 )
{
return F_81 ( V_52 ) ;
}
static int F_126 ( struct V_48 * V_52 , struct V_48 * * V_191 )
{
struct V_48 * V_192 ;
unsigned int V_193 ;
unsigned int V_144 = F_121 ( V_52 ) + sizeof( struct V_94 ) ;
int V_194 = - V_188 ;
V_193 = F_51 ( F_38 ( V_52 ) -> V_84 ) - F_116 ( V_52 ) ;
V_192 = F_127 ( V_52 , V_193 ,
F_125 ) ;
if ( ! V_192 )
goto V_195;
if ( ! F_78 ( V_192 , V_144 ) )
goto V_195;
V_194 = F_124 ( V_192 ) ;
if ( V_194 )
goto V_195;
if ( V_191 )
* V_191 = V_192 ;
else if ( V_192 != V_52 )
F_32 ( V_192 ) ;
V_194 = 0 ;
V_195:
if ( V_194 && V_192 && V_192 != V_52 )
F_32 ( V_192 ) ;
return V_194 ;
}
int F_128 ( struct V_48 * V_52 , struct V_48 * * V_191 )
{
int V_194 = F_114 ( V_52 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( F_38 ( V_52 ) -> V_83 != V_71 )
return - V_190 ;
return F_126 ( V_52 , V_191 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
#ifdef F_97
struct V_7 * V_8 ;
int type ;
F_108 () ;
F_104 (in_dev, im) {
if ( V_8 -> V_106 == V_114 )
continue;
if ( F_53 ( V_8 -> V_106 ) &&
! V_115 )
continue;
if ( F_2 ( V_2 ) )
type = V_139 ;
else if ( F_3 ( V_2 ) )
type = V_140 ;
else
type = V_89 ;
F_62 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_130 ( struct V_1 * V_2 , T_1 V_168 )
{
struct V_7 * V_143 ;
struct V_7 T_3 * * V_196 ;
F_108 () ;
for ( V_196 = & V_2 -> V_186 ;
( V_143 = F_102 ( * V_196 ) ) != NULL ;
V_196 = & V_143 -> V_185 ) {
if ( V_143 -> V_106 == V_168 ) {
if ( -- V_143 -> V_183 == 0 ) {
F_106 ( V_2 , V_143 ) ;
* V_196 = V_143 -> V_185 ;
V_2 -> V_181 -- ;
F_96 ( V_143 ) ;
F_95 ( V_143 ) ;
if ( ! V_2 -> V_174 )
F_113 ( V_2 ) ;
F_6 ( V_143 ) ;
return;
}
break;
}
}
}
void F_131 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_108 () ;
F_104 (in_dev, pmc)
F_96 ( V_26 ) ;
}
void F_132 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_108 () ;
F_104 (in_dev, pmc)
F_98 ( V_26 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_108 () ;
F_104 (in_dev, pmc)
F_96 ( V_26 ) ;
#ifdef F_97
V_2 -> V_136 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_75 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
#endif
F_130 ( V_2 , V_114 ) ;
}
void F_134 ( struct V_1 * V_2 )
{
F_108 () ;
#ifdef F_97
F_112 ( & V_2 -> V_22 , F_64 ,
( unsigned long ) V_2 ) ;
F_112 ( & V_2 -> V_24 , F_65 ,
( unsigned long ) V_2 ) ;
V_2 -> V_137 = V_138 ;
#endif
F_111 ( & V_2 -> V_125 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_108 () ;
#ifdef F_97
V_2 -> V_137 = V_138 ;
#endif
F_107 ( V_2 , V_114 ) ;
F_104 (in_dev, pmc)
F_98 ( V_26 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
struct V_7 * V_143 ;
F_108 () ;
F_133 ( V_2 ) ;
while ( ( V_143 = F_102 ( V_2 -> V_186 ) ) != NULL ) {
V_2 -> V_186 = V_143 -> V_185 ;
V_2 -> V_181 -- ;
F_95 ( V_143 ) ;
F_6 ( V_143 ) ;
}
}
static struct V_1 * F_137 ( struct V_59 * V_59 , struct V_197 * V_198 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_199 = NULL ;
if ( V_198 -> V_200 ) {
V_199 = F_138 ( V_59 , V_198 -> V_200 ) ;
return V_199 ;
}
if ( V_198 -> V_201 . V_202 ) {
V_50 = F_139 ( V_59 , V_198 -> V_201 . V_202 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_140 ( V_59 ,
V_198 -> V_203 . V_202 ,
0 , 0 , 0 ) ;
if ( ! F_31 ( V_54 ) ) {
V_50 = V_54 -> V_73 . V_50 ;
F_63 ( V_54 ) ;
}
}
if ( V_50 ) {
V_198 -> V_200 = V_50 -> V_72 ;
V_199 = F_141 ( V_50 ) ;
}
return V_199 ;
}
static int F_142 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_204 )
{
struct V_27 * V_28 , * V_108 ;
int V_205 = 0 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_119 == * V_204 )
break;
V_108 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_206 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_113 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_97
struct V_1 * V_2 = V_26 -> V_10 ;
#endif
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_97
if ( V_28 -> V_207 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_137 ? : V_138 ;
V_28 -> V_47 = V_26 -> V_116 ;
V_26 -> V_116 = V_28 ;
V_205 = 1 ;
} else
#endif
F_55 ( V_28 ) ;
}
return V_205 ;
}
static int F_143 ( struct V_1 * V_2 , T_1 * V_208 , int V_35 ,
int V_38 , T_1 * V_204 , int V_209 )
{
struct V_7 * V_26 ;
int V_210 = 0 ;
int V_143 , V_195 ;
if ( ! V_2 )
return - V_211 ;
F_57 () ;
F_58 (in_dev, pmc) {
if ( * V_208 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_59 () ;
return - V_206 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_59 () ;
#ifdef F_97
F_144 ( V_26 ) ;
#endif
if ( ! V_209 ) {
V_195 = - V_188 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_212;
V_26 -> V_38 [ V_35 ] -- ;
}
V_195 = 0 ;
for ( V_143 = 0 ; V_143 < V_38 ; V_143 ++ ) {
int V_205 = F_142 ( V_26 , V_35 , & V_204 [ V_143 ] ) ;
V_210 |= V_205 > 0 ;
if ( ! V_195 && V_205 < 0 )
V_195 = V_205 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_97
struct V_27 * V_28 ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_97
V_26 -> V_120 = V_2 -> V_137 ? : V_138 ;
V_2 -> V_136 = V_26 -> V_120 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_66 ( V_26 -> V_10 ) ;
} else if ( F_145 ( V_26 ) || V_210 ) {
F_66 ( V_26 -> V_10 ) ;
#endif
}
V_212:
F_14 ( & V_26 -> V_12 ) ;
return V_195 ;
}
static int F_146 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_204 )
{
struct V_27 * V_28 , * V_108 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_119 == * V_204 )
break;
V_108 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_93 ( sizeof( * V_28 ) , V_66 ) ;
if ( ! V_28 )
return - V_213 ;
V_28 -> V_119 = * V_204 ;
if ( V_108 ) {
V_108 -> V_47 = V_28 ;
} else
V_26 -> V_46 = V_28 ;
}
V_28 -> V_37 [ V_35 ] ++ ;
if ( V_28 -> V_37 [ V_35 ] == 1 ) {
F_113 ( V_26 -> V_10 ) ;
}
return 0 ;
}
static void F_144 ( struct V_7 * V_26 )
{
struct V_27 * V_28 ;
int V_214 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_207 = V_214 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_207 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_145 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_215 ;
int V_214 = V_26 -> V_38 [ V_39 ] ;
int V_155 = V_26 -> V_10 -> V_137 ;
int V_216 , V_205 ;
V_205 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_216 = V_214 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_216 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_216 ) {
if ( ! V_28 -> V_207 ) {
struct V_27 * V_217 = NULL ;
for ( V_215 = V_26 -> V_116 ; V_215 ; V_215 = V_215 -> V_47 ) {
if ( V_215 -> V_119 == V_28 -> V_119 )
break;
V_217 = V_215 ;
}
if ( V_215 ) {
if ( V_217 )
V_217 -> V_47 = V_215 -> V_47 ;
else
V_26 -> V_116 = V_215 -> V_47 ;
F_55 ( V_215 ) ;
}
V_28 -> V_43 = V_155 ;
V_205 ++ ;
}
} else if ( V_28 -> V_207 ) {
V_28 -> V_43 = 0 ;
for ( V_215 = V_26 -> V_116 ; V_215 ; V_215 = V_215 -> V_47 )
if ( V_215 -> V_119 == V_28 -> V_119 )
break;
if ( ! V_215 ) {
V_215 = F_147 ( sizeof( * V_215 ) , V_66 ) ;
if ( ! V_215 )
continue;
* V_215 = * V_28 ;
V_215 -> V_47 = V_26 -> V_116 ;
V_26 -> V_116 = V_215 ;
}
V_215 -> V_43 = V_155 ;
V_205 ++ ;
}
}
return V_205 ;
}
static int F_109 ( struct V_1 * V_2 , T_1 * V_208 , int V_35 ,
int V_38 , T_1 * V_204 , int V_209 )
{
struct V_7 * V_26 ;
int V_218 ;
int V_143 , V_195 ;
if ( ! V_2 )
return - V_211 ;
F_57 () ;
F_58 (in_dev, pmc) {
if ( * V_208 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_59 () ;
return - V_206 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_59 () ;
#ifdef F_97
F_144 ( V_26 ) ;
#endif
V_218 = V_26 -> V_35 == V_39 ;
if ( ! V_209 )
V_26 -> V_38 [ V_35 ] ++ ;
V_195 = 0 ;
for ( V_143 = 0 ; V_143 < V_38 ; V_143 ++ ) {
V_195 = F_146 ( V_26 , V_35 , & V_204 [ V_143 ] ) ;
if ( V_195 )
break;
}
if ( V_195 ) {
int V_219 ;
if ( ! V_209 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_219 = 0 ; V_219 < V_143 ; V_219 ++ )
( void ) F_142 ( V_26 , V_35 , & V_204 [ V_219 ] ) ;
} else if ( V_218 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_97
struct V_27 * V_28 ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_97
V_26 -> V_120 = V_2 -> V_137 ? : V_138 ;
V_2 -> V_136 = V_26 -> V_120 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_66 ( V_2 ) ;
} else if ( F_145 ( V_26 ) ) {
F_66 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_195 ;
}
static void F_95 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_220 ;
for ( V_28 = V_26 -> V_116 ; V_28 ; V_28 = V_220 ) {
V_220 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
}
V_26 -> V_116 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_220 ) {
V_220 = V_28 -> V_47 ;
F_55 ( V_28 ) ;
}
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
}
int F_148 ( struct V_221 * V_222 , struct V_197 * V_198 )
{
T_1 V_168 = V_198 -> V_203 . V_202 ;
struct V_223 * V_224 , * V_143 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
int V_72 ;
int V_227 = 0 ;
int V_195 ;
F_108 () ;
if ( ! F_151 ( V_168 ) )
return - V_188 ;
V_2 = F_137 ( V_59 , V_198 ) ;
if ( ! V_2 ) {
V_195 = - V_211 ;
goto V_228;
}
V_195 = - V_229 ;
V_72 = V_198 -> V_200 ;
F_104 (inet, i) {
if ( V_143 -> V_230 . V_203 . V_202 == V_168 &&
V_143 -> V_230 . V_200 == V_72 )
goto V_228;
V_227 ++ ;
}
V_195 = - V_213 ;
if ( V_227 >= V_231 )
goto V_228;
V_224 = F_152 ( V_222 , sizeof( * V_224 ) , V_171 ) ;
if ( ! V_224 )
goto V_228;
memcpy ( & V_224 -> V_230 , V_198 , sizeof( * V_198 ) ) ;
V_224 -> V_185 = V_226 -> V_186 ;
V_224 -> V_232 = NULL ;
V_224 -> V_35 = V_39 ;
F_103 ( V_226 -> V_186 , V_224 ) ;
F_107 ( V_2 , V_168 ) ;
V_195 = 0 ;
V_228:
return V_195 ;
}
static int F_153 ( struct V_221 * V_222 , struct V_223 * V_224 ,
struct V_1 * V_2 )
{
struct V_233 * V_28 = F_102 ( V_224 -> V_232 ) ;
int V_195 ;
if ( ! V_28 ) {
return F_143 ( V_2 , & V_224 -> V_230 . V_203 . V_202 ,
V_224 -> V_35 , 0 , NULL , 0 ) ;
}
V_195 = F_143 ( V_2 , & V_224 -> V_230 . V_203 . V_202 ,
V_224 -> V_35 , V_28 -> V_234 , V_28 -> V_235 , 0 ) ;
F_105 ( V_224 -> V_232 , NULL ) ;
F_154 ( F_155 ( V_28 -> V_236 ) , & V_222 -> V_237 ) ;
F_9 ( V_28 , V_11 ) ;
return V_195 ;
}
int F_156 ( struct V_221 * V_222 , struct V_197 * V_198 )
{
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_223 * V_224 ;
struct V_223 T_3 * * V_238 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
T_1 V_130 = V_198 -> V_203 . V_202 ;
T_2 V_72 ;
int V_194 = - V_239 ;
F_108 () ;
V_2 = F_137 ( V_59 , V_198 ) ;
if ( ! V_2 ) {
V_194 = - V_211 ;
goto V_184;
}
V_72 = V_198 -> V_200 ;
for ( V_238 = & V_226 -> V_186 ;
( V_224 = F_102 ( * V_238 ) ) != NULL ;
V_238 = & V_224 -> V_185 ) {
if ( V_224 -> V_230 . V_203 . V_202 != V_130 )
continue;
if ( V_72 ) {
if ( V_224 -> V_230 . V_200 != V_72 )
continue;
} else if ( V_198 -> V_201 . V_202 && V_198 -> V_201 . V_202 !=
V_224 -> V_230 . V_201 . V_202 )
continue;
( void ) F_153 ( V_222 , V_224 , V_2 ) ;
* V_238 = V_224 -> V_185 ;
F_130 ( V_2 , V_130 ) ;
F_154 ( sizeof( * V_224 ) , & V_222 -> V_237 ) ;
F_9 ( V_224 , V_11 ) ;
return 0 ;
}
V_184:
return V_194 ;
}
int F_157 ( int V_240 , int V_241 , struct V_221 * V_222 , struct
V_242 * V_243 , int V_72 )
{
int V_195 ;
struct V_197 V_198 ;
T_1 V_168 = V_243 -> V_203 ;
struct V_223 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_233 * V_244 ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
int V_245 = 0 ;
int V_143 , V_219 , V_205 ;
if ( ! F_151 ( V_168 ) )
return - V_188 ;
F_108 () ;
V_198 . V_203 . V_202 = V_243 -> V_203 ;
V_198 . V_201 . V_202 = V_243 -> V_246 ;
V_198 . V_200 = V_72 ;
V_2 = F_137 ( V_59 , & V_198 ) ;
if ( ! V_2 ) {
V_195 = - V_211 ;
goto V_228;
}
V_195 = - V_239 ;
F_104 (inet, pmc) {
if ( ( V_26 -> V_230 . V_203 . V_202 ==
V_198 . V_203 . V_202 ) &&
( V_26 -> V_230 . V_200 == V_198 . V_200 ) )
break;
}
if ( ! V_26 ) {
V_195 = - V_188 ;
goto V_228;
}
if ( V_26 -> V_232 ) {
if ( V_26 -> V_35 != V_241 ) {
V_195 = - V_188 ;
goto V_228;
}
} else if ( V_26 -> V_35 != V_241 ) {
F_109 ( V_2 , & V_243 -> V_203 , V_241 , 0 , NULL , 0 ) ;
F_143 ( V_2 , & V_243 -> V_203 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_241 ;
}
V_244 = F_102 ( V_26 -> V_232 ) ;
if ( ! V_240 ) {
if ( ! V_244 )
goto V_228;
V_205 = ! 0 ;
for ( V_143 = 0 ; V_143 < V_244 -> V_234 ; V_143 ++ ) {
V_205 = memcmp ( & V_244 -> V_235 [ V_143 ] , & V_243 -> V_247 ,
sizeof( T_1 ) ) ;
if ( V_205 == 0 )
break;
}
if ( V_205 )
goto V_228;
if ( V_244 -> V_234 == 1 && V_241 == V_36 ) {
V_245 = 1 ;
goto V_228;
}
F_143 ( V_2 , & V_243 -> V_203 , V_241 , 1 ,
& V_243 -> V_247 , 1 ) ;
for ( V_219 = V_143 + 1 ; V_219 < V_244 -> V_234 ; V_219 ++ )
V_244 -> V_235 [ V_219 - 1 ] = V_244 -> V_235 [ V_219 ] ;
V_244 -> V_234 -- ;
V_195 = 0 ;
goto V_228;
}
if ( V_244 && V_244 -> V_234 >= V_248 ) {
V_195 = - V_213 ;
goto V_228;
}
if ( ! V_244 || V_244 -> V_234 == V_244 -> V_236 ) {
struct V_233 * V_249 ;
int V_227 = V_250 ;
if ( V_244 )
V_227 += V_244 -> V_236 ;
V_249 = F_152 ( V_222 , F_155 ( V_227 ) , V_171 ) ;
if ( ! V_249 ) {
V_195 = - V_213 ;
goto V_228;
}
V_249 -> V_236 = V_227 ;
V_249 -> V_234 = V_227 - V_250 ;
if ( V_244 ) {
for ( V_143 = 0 ; V_143 < V_244 -> V_234 ; V_143 ++ )
V_249 -> V_235 [ V_143 ] = V_244 -> V_235 [ V_143 ] ;
F_154 ( F_155 ( V_244 -> V_236 ) , & V_222 -> V_237 ) ;
F_9 ( V_244 , V_11 ) ;
}
F_103 ( V_26 -> V_232 , V_249 ) ;
V_244 = V_249 ;
}
V_205 = 1 ;
for ( V_143 = 0 ; V_143 < V_244 -> V_234 ; V_143 ++ ) {
V_205 = memcmp ( & V_244 -> V_235 [ V_143 ] , & V_243 -> V_247 ,
sizeof( T_1 ) ) ;
if ( V_205 == 0 )
break;
}
if ( V_205 == 0 )
goto V_228;
for ( V_219 = V_244 -> V_234 - 1 ; V_219 >= V_143 ; V_219 -- )
V_244 -> V_235 [ V_219 + 1 ] = V_244 -> V_235 [ V_219 ] ;
V_244 -> V_235 [ V_143 ] = V_243 -> V_247 ;
V_244 -> V_234 ++ ;
V_195 = 0 ;
F_109 ( V_2 , & V_243 -> V_203 , V_241 , 1 ,
& V_243 -> V_247 , 1 ) ;
V_228:
if ( V_245 )
V_195 = F_156 ( V_222 , & V_198 ) ;
return V_195 ;
}
int F_158 ( struct V_221 * V_222 , struct V_251 * V_252 , int V_72 )
{
int V_195 = 0 ;
struct V_197 V_198 ;
T_1 V_168 = V_252 -> V_253 ;
struct V_223 * V_26 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_233 * V_249 , * V_244 ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
int V_245 = 0 ;
if ( ! F_151 ( V_168 ) )
return - V_188 ;
if ( V_252 -> V_254 != V_36 &&
V_252 -> V_254 != V_39 )
return - V_188 ;
F_108 () ;
V_198 . V_203 . V_202 = V_252 -> V_253 ;
V_198 . V_201 . V_202 = V_252 -> V_255 ;
V_198 . V_200 = V_72 ;
V_2 = F_137 ( V_59 , & V_198 ) ;
if ( ! V_2 ) {
V_195 = - V_211 ;
goto V_228;
}
if ( V_252 -> V_254 == V_36 && V_252 -> V_256 == 0 ) {
V_245 = 1 ;
goto V_228;
}
F_104 (inet, pmc) {
if ( V_26 -> V_230 . V_203 . V_202 == V_252 -> V_253 &&
V_26 -> V_230 . V_200 == V_198 . V_200 )
break;
}
if ( ! V_26 ) {
V_195 = - V_188 ;
goto V_228;
}
if ( V_252 -> V_256 ) {
V_249 = F_152 ( V_222 , F_155 ( V_252 -> V_256 ) ,
V_171 ) ;
if ( ! V_249 ) {
V_195 = - V_213 ;
goto V_228;
}
V_249 -> V_236 = V_249 -> V_234 = V_252 -> V_256 ;
memcpy ( V_249 -> V_235 , V_252 -> V_257 ,
V_252 -> V_256 * sizeof( V_252 -> V_257 [ 0 ] ) ) ;
V_195 = F_109 ( V_2 , & V_252 -> V_253 ,
V_252 -> V_254 , V_249 -> V_234 , V_249 -> V_235 , 0 ) ;
if ( V_195 ) {
F_159 ( V_222 , V_249 , F_155 ( V_249 -> V_236 ) ) ;
goto V_228;
}
} else {
V_249 = NULL ;
( void ) F_109 ( V_2 , & V_252 -> V_253 ,
V_252 -> V_254 , 0 , NULL , 0 ) ;
}
V_244 = F_102 ( V_26 -> V_232 ) ;
if ( V_244 ) {
( void ) F_143 ( V_2 , & V_252 -> V_253 , V_26 -> V_35 ,
V_244 -> V_234 , V_244 -> V_235 , 0 ) ;
F_154 ( F_155 ( V_244 -> V_236 ) , & V_222 -> V_237 ) ;
F_9 ( V_244 , V_11 ) ;
} else
( void ) F_143 ( V_2 , & V_252 -> V_253 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_103 ( V_26 -> V_232 , V_249 ) ;
V_26 -> V_35 = V_252 -> V_254 ;
V_195 = 0 ;
V_228:
if ( V_245 )
V_195 = F_156 ( V_222 , & V_198 ) ;
return V_195 ;
}
int F_160 ( struct V_221 * V_222 , struct V_251 * V_252 ,
struct V_251 T_5 * V_258 , int T_5 * V_259 )
{
int V_195 , V_144 , V_227 , V_260 ;
struct V_197 V_198 ;
T_1 V_168 = V_252 -> V_253 ;
struct V_223 * V_26 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_233 * V_244 ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
if ( ! F_151 ( V_168 ) )
return - V_188 ;
F_161 () ;
V_198 . V_203 . V_202 = V_252 -> V_253 ;
V_198 . V_201 . V_202 = V_252 -> V_255 ;
V_198 . V_200 = 0 ;
V_2 = F_137 ( V_59 , & V_198 ) ;
if ( ! V_2 ) {
V_195 = - V_211 ;
goto V_228;
}
V_195 = - V_239 ;
F_104 (inet, pmc) {
if ( V_26 -> V_230 . V_203 . V_202 == V_252 -> V_253 &&
V_26 -> V_230 . V_200 == V_198 . V_200 )
break;
}
if ( ! V_26 )
goto V_228;
V_252 -> V_254 = V_26 -> V_35 ;
V_244 = F_102 ( V_26 -> V_232 ) ;
F_162 () ;
if ( ! V_244 ) {
V_144 = 0 ;
V_227 = 0 ;
} else {
V_227 = V_244 -> V_234 ;
}
V_260 = V_227 < V_252 -> V_256 ? V_227 : V_252 -> V_256 ;
V_144 = V_260 * sizeof( V_244 -> V_235 [ 0 ] ) ;
V_252 -> V_256 = V_227 ;
if ( F_163 ( F_164 ( V_260 ) , V_259 ) ||
F_165 ( V_258 , V_252 , F_164 ( 0 ) ) ) {
return - V_261 ;
}
if ( V_144 &&
F_165 ( & V_258 -> V_257 [ 0 ] , V_244 -> V_235 , V_144 ) )
return - V_261 ;
return 0 ;
V_228:
F_162 () ;
return V_195 ;
}
int F_166 ( struct V_221 * V_222 , struct V_262 * V_263 ,
struct V_262 T_5 * V_258 , int T_5 * V_259 )
{
int V_195 , V_143 , V_227 , V_260 ;
struct V_264 * V_265 ;
T_1 V_168 ;
struct V_223 * V_26 ;
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_233 * V_244 ;
V_265 = (struct V_264 * ) & V_263 -> V_266 ;
if ( V_265 -> V_267 != V_268 )
return - V_188 ;
V_168 = V_265 -> V_269 . V_202 ;
if ( ! F_151 ( V_168 ) )
return - V_188 ;
F_161 () ;
V_195 = - V_239 ;
F_104 (inet, pmc) {
if ( V_26 -> V_230 . V_203 . V_202 == V_168 &&
V_26 -> V_230 . V_200 == V_263 -> V_270 )
break;
}
if ( ! V_26 )
goto V_228;
V_263 -> V_271 = V_26 -> V_35 ;
V_244 = F_102 ( V_26 -> V_232 ) ;
F_162 () ;
V_227 = V_244 ? V_244 -> V_234 : 0 ;
V_260 = V_227 < V_263 -> V_272 ? V_227 : V_263 -> V_272 ;
V_263 -> V_272 = V_227 ;
if ( F_163 ( F_167 ( V_260 ) , V_259 ) ||
F_165 ( V_258 , V_263 , F_167 ( 0 ) ) ) {
return - V_261 ;
}
for ( V_143 = 0 ; V_143 < V_260 ; V_143 ++ ) {
struct V_273 V_274 ;
V_265 = (struct V_264 * ) & V_274 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_265 -> V_267 = V_268 ;
V_265 -> V_269 . V_202 = V_244 -> V_235 [ V_143 ] ;
if ( F_165 ( & V_258 -> V_275 [ V_143 ] , & V_274 , sizeof( V_274 ) ) )
return - V_261 ;
}
return 0 ;
V_228:
F_162 () ;
return V_195 ;
}
int F_168 ( struct V_221 * V_222 , T_1 V_276 , T_1 V_277 , int V_278 )
{
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_223 * V_26 ;
struct V_233 * V_244 ;
int V_143 ;
int V_194 ;
V_194 = 1 ;
if ( ! F_151 ( V_276 ) )
goto V_184;
F_57 () ;
F_58 (inet, pmc) {
if ( V_26 -> V_230 . V_203 . V_202 == V_276 &&
V_26 -> V_230 . V_200 == V_278 )
break;
}
V_194 = V_226 -> V_279 ;
if ( ! V_26 )
goto V_280;
V_244 = F_169 ( V_26 -> V_232 ) ;
V_194 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_244 )
goto V_280;
for ( V_143 = 0 ; V_143 < V_244 -> V_234 ; V_143 ++ ) {
if ( V_244 -> V_235 [ V_143 ] == V_277 )
break;
}
V_194 = 0 ;
if ( V_26 -> V_35 == V_36 && V_143 >= V_244 -> V_234 )
goto V_280;
if ( V_26 -> V_35 == V_39 && V_143 < V_244 -> V_234 )
goto V_280;
V_194 = 1 ;
V_280:
F_59 () ;
V_184:
return V_194 ;
}
void F_170 ( struct V_221 * V_222 )
{
struct V_225 * V_226 = F_149 ( V_222 ) ;
struct V_223 * V_224 ;
struct V_59 * V_59 = F_150 ( V_222 ) ;
if ( ! V_226 -> V_186 )
return;
F_161 () ;
while ( ( V_224 = F_102 ( V_226 -> V_186 ) ) != NULL ) {
struct V_1 * V_2 ;
V_226 -> V_186 = V_224 -> V_185 ;
V_2 = F_138 ( V_59 , V_224 -> V_230 . V_200 ) ;
( void ) F_153 ( V_222 , V_224 , V_2 ) ;
if ( V_2 )
F_130 ( V_2 , V_224 -> V_230 . V_203 . V_202 ) ;
F_154 ( sizeof( * V_224 ) , & V_222 -> V_237 ) ;
F_9 ( V_224 , V_11 ) ;
}
F_162 () ;
}
int F_171 ( struct V_1 * V_2 , T_1 V_281 , T_1 V_282 , T_6 V_283 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_178 ;
struct V_27 * V_28 ;
int V_205 = 0 ;
V_178 = F_169 ( V_2 -> V_178 ) ;
if ( V_178 ) {
T_2 V_179 = F_100 ( ( V_176 T_2 ) V_281 , V_177 ) ;
for ( V_8 = F_169 ( V_178 [ V_179 ] ) ;
V_8 != NULL ;
V_8 = F_169 ( V_8 -> V_180 ) ) {
if ( V_8 -> V_106 == V_281 )
break;
}
} else {
F_58 (in_dev, im) {
if ( V_8 -> V_106 == V_281 )
break;
}
}
if ( V_8 && V_283 == V_71 ) {
V_205 = 1 ;
} else if ( V_8 ) {
if ( V_282 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_119 == V_282 )
break;
}
if ( V_28 )
V_205 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_205 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_205 = 1 ;
}
return V_205 ;
}
static inline struct V_7 * F_172 ( struct V_284 * V_285 )
{
struct V_59 * V_59 = F_173 ( V_285 ) ;
struct V_7 * V_8 = NULL ;
struct V_286 * V_287 = F_174 ( V_285 ) ;
V_287 -> V_2 = NULL ;
F_175 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_80 ( V_287 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_169 ( V_2 -> V_186 ) ;
if ( V_8 ) {
V_287 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_176 ( struct V_284 * V_285 , struct V_7 * V_8 )
{
struct V_286 * V_287 = F_174 ( V_285 ) ;
V_8 = F_169 ( V_8 -> V_185 ) ;
while ( ! V_8 ) {
V_287 -> V_50 = F_177 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_50 ) {
V_287 -> V_2 = NULL ;
break;
}
V_287 -> V_2 = F_80 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_2 )
continue;
V_8 = F_169 ( V_287 -> V_2 -> V_186 ) ;
}
return V_8 ;
}
static struct V_7 * F_178 ( struct V_284 * V_285 , T_7 V_288 )
{
struct V_7 * V_8 = F_172 ( V_285 ) ;
if ( V_8 )
while ( V_288 && ( V_8 = F_176 ( V_285 , V_8 ) ) != NULL )
-- V_288 ;
return V_288 ? NULL : V_8 ;
}
static void * F_179 ( struct V_284 * V_285 , T_7 * V_288 )
__acquires( V_11 )
{
F_57 () ;
return * V_288 ? F_178 ( V_285 , * V_288 - 1 ) : V_289 ;
}
static void * F_180 ( struct V_284 * V_285 , void * V_290 , T_7 * V_288 )
{
struct V_7 * V_8 ;
if ( V_290 == V_289 )
V_8 = F_172 ( V_285 ) ;
else
V_8 = F_176 ( V_285 , V_290 ) ;
++ * V_288 ;
return V_8 ;
}
static void F_181 ( struct V_284 * V_285 , void * V_290 )
__releases( V_11 )
{
struct V_286 * V_287 = F_174 ( V_285 ) ;
V_287 -> V_2 = NULL ;
V_287 -> V_50 = NULL ;
F_59 () ;
}
static int F_182 ( struct V_284 * V_285 , void * V_290 )
{
if ( V_290 == V_289 )
F_183 ( V_285 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_290 ;
struct V_286 * V_287 = F_174 ( V_285 ) ;
char * V_291 ;
long V_209 ;
#ifdef F_97
V_291 = F_2 ( V_287 -> V_2 ) ? L_2 :
F_3 ( V_287 -> V_2 ) ? L_3 :
L_4 ;
#else
V_291 = L_5 ;
#endif
if ( F_184 ( V_287 -> V_2 -> V_186 ) == V_8 ) {
F_185 ( V_285 , L_6 ,
V_287 -> V_50 -> V_72 , V_287 -> V_50 -> V_292 , V_287 -> V_2 -> V_181 , V_291 ) ;
}
V_209 = V_8 -> V_13 . V_25 - V_19 ;
F_185 ( V_285 ,
L_7 ,
V_8 -> V_106 , V_8 -> V_183 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_186 ( V_209 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_187 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_188 ( V_293 , V_294 , & V_295 ,
sizeof( struct V_286 ) ) ;
}
static inline struct V_27 * F_189 ( struct V_284 * V_285 )
{
struct V_59 * V_59 = F_173 ( V_285 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_296 * V_287 = F_190 ( V_285 ) ;
V_287 -> V_199 = NULL ;
V_287 -> V_8 = NULL ;
F_175 (net, state->dev) {
struct V_1 * V_199 ;
V_199 = F_80 ( V_287 -> V_50 ) ;
if ( F_117 ( ! V_199 ) )
continue;
V_8 = F_169 ( V_199 -> V_186 ) ;
if ( F_191 ( V_8 ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_191 ( V_28 ) ) {
V_287 -> V_8 = V_8 ;
V_287 -> V_199 = V_199 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_192 ( struct V_284 * V_285 , struct V_27 * V_28 )
{
struct V_296 * V_287 = F_190 ( V_285 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_287 -> V_8 -> V_12 ) ;
V_287 -> V_8 = V_287 -> V_8 -> V_127 ;
while ( ! V_287 -> V_8 ) {
V_287 -> V_50 = F_177 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_50 ) {
V_287 -> V_199 = NULL ;
goto V_184;
}
V_287 -> V_199 = F_80 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_199 )
continue;
V_287 -> V_8 = F_169 ( V_287 -> V_199 -> V_186 ) ;
}
if ( ! V_287 -> V_8 )
break;
F_11 ( & V_287 -> V_8 -> V_12 ) ;
V_28 = V_287 -> V_8 -> V_46 ;
}
V_184:
return V_28 ;
}
static struct V_27 * F_193 ( struct V_284 * V_285 , T_7 V_288 )
{
struct V_27 * V_28 = F_189 ( V_285 ) ;
if ( V_28 )
while ( V_288 && ( V_28 = F_192 ( V_285 , V_28 ) ) != NULL )
-- V_288 ;
return V_288 ? NULL : V_28 ;
}
static void * F_194 ( struct V_284 * V_285 , T_7 * V_288 )
__acquires( V_11 )
{
F_57 () ;
return * V_288 ? F_193 ( V_285 , * V_288 - 1 ) : V_289 ;
}
static void * F_195 ( struct V_284 * V_285 , void * V_290 , T_7 * V_288 )
{
struct V_27 * V_28 ;
if ( V_290 == V_289 )
V_28 = F_189 ( V_285 ) ;
else
V_28 = F_192 ( V_285 , V_290 ) ;
++ * V_288 ;
return V_28 ;
}
static void F_196 ( struct V_284 * V_285 , void * V_290 )
__releases( V_11 )
{
struct V_296 * V_287 = F_190 ( V_285 ) ;
if ( F_191 ( V_287 -> V_8 ) ) {
F_14 ( & V_287 -> V_8 -> V_12 ) ;
V_287 -> V_8 = NULL ;
}
V_287 -> V_199 = NULL ;
V_287 -> V_50 = NULL ;
F_59 () ;
}
static int F_197 ( struct V_284 * V_285 , void * V_290 )
{
struct V_27 * V_28 = (struct V_27 * ) V_290 ;
struct V_296 * V_287 = F_190 ( V_285 ) ;
if ( V_290 == V_289 ) {
F_183 ( V_285 , L_8 ) ;
} else {
F_185 ( V_285 ,
L_9
L_10 ,
V_287 -> V_50 -> V_72 , V_287 -> V_50 -> V_292 ,
F_198 ( V_287 -> V_8 -> V_106 ) ,
F_198 ( V_28 -> V_119 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_199 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_188 ( V_293 , V_294 , & V_297 ,
sizeof( struct V_296 ) ) ;
}
static int T_8 F_200 ( struct V_59 * V_59 )
{
struct V_298 * V_299 ;
int V_195 ;
V_299 = F_201 ( L_11 , V_300 , V_59 -> V_301 , & V_302 ) ;
if ( ! V_299 )
goto V_303;
V_299 = F_201 ( L_12 , V_300 , V_59 -> V_301 ,
& V_304 ) ;
if ( ! V_299 )
goto V_305;
V_195 = F_202 ( & V_59 -> V_306 . V_307 , V_268 ,
V_308 , 0 , V_59 ) ;
if ( V_195 < 0 ) {
F_203 ( L_13 ,
V_195 ) ;
goto V_309;
}
return 0 ;
V_309:
F_204 ( L_12 , V_59 -> V_301 ) ;
V_305:
F_204 ( L_11 , V_59 -> V_301 ) ;
V_303:
return - V_310 ;
}
static void T_9 F_205 ( struct V_59 * V_59 )
{
F_204 ( L_12 , V_59 -> V_301 ) ;
F_204 ( L_11 , V_59 -> V_301 ) ;
F_206 ( V_59 -> V_306 . V_307 ) ;
}
static int F_207 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_314 )
{
struct V_49 * V_50 = F_208 ( V_314 ) ;
struct V_1 * V_2 ;
switch ( V_313 ) {
case V_315 :
V_2 = F_141 ( V_50 ) ;
if ( V_2 )
F_129 ( V_2 ) ;
break;
default:
break;
}
return V_316 ;
}
int T_10 F_209 ( void )
{
#if F_210 ( V_317 )
int V_195 ;
V_195 = F_211 ( & V_318 ) ;
if ( V_195 )
return V_195 ;
V_195 = F_212 ( & V_319 ) ;
if ( V_195 )
goto V_320;
return 0 ;
V_320:
F_213 ( & V_318 ) ;
return V_195 ;
#else
return F_212 ( & V_319 ) ;
#endif
}
