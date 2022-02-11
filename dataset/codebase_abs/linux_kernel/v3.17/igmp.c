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
static struct V_48 * F_26 ( struct V_49 * V_50 , int V_51 )
{
struct V_48 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
struct V_60 V_61 ;
int V_62 = F_28 ( V_50 ) ;
int V_63 = V_50 -> V_64 ;
while ( 1 ) {
V_52 = F_29 ( V_51 + V_62 + V_63 ,
V_65 | V_66 ) ;
if ( V_52 )
break;
V_51 >>= 1 ;
if ( V_51 < 256 )
return NULL ;
}
V_52 -> V_67 = V_68 ;
F_30 ( V_52 ) = V_51 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_69 , 0 ,
0 , 0 ,
V_70 , 0 , V_50 -> V_71 ) ;
if ( F_32 ( V_54 ) ) {
F_33 ( V_52 ) ;
return NULL ;
}
F_34 ( V_52 , & V_54 -> V_72 ) ;
V_52 -> V_50 = V_50 ;
F_35 ( V_52 , V_62 ) ;
F_36 ( V_52 ) ;
V_56 = F_37 ( V_52 ) ;
F_38 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_56 -> V_73 = 4 ;
V_56 -> V_74 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_56 -> V_75 = 0xc0 ;
V_56 -> V_76 = F_39 ( V_77 ) ;
V_56 -> V_78 = 1 ;
V_56 -> V_79 = V_61 . V_79 ;
V_56 -> V_80 = V_61 . V_80 ;
V_56 -> V_81 = V_70 ;
V_56 -> V_82 = 0 ;
F_40 ( V_52 , NULL ) ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 0 ] = V_84 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 1 ] = 4 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 2 ] = 0 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 3 ] = 0 ;
V_52 -> V_85 = V_52 -> V_86 + sizeof( struct V_55 ) + 4 ;
F_38 ( V_52 , sizeof( * V_58 ) ) ;
V_58 = F_41 ( V_52 ) ;
V_58 -> type = V_87 ;
V_58 -> V_88 = 0 ;
V_58 -> V_89 = 0 ;
V_58 -> V_90 = 0 ;
V_58 -> V_91 = 0 ;
return V_52 ;
}
static int F_42 ( struct V_48 * V_52 )
{
struct V_92 * V_58 = F_43 ( V_52 ) ;
const int V_93 = F_44 ( V_52 ) - F_45 ( V_52 ) ;
V_58 -> V_89 = F_46 ( F_43 ( V_52 ) , V_93 ) ;
return F_47 ( V_52 ) ;
}
static int F_48 ( struct V_7 * V_26 , int type , int V_94 , int V_95 )
{
return sizeof( struct V_96 ) + 4 * F_25 ( V_26 , type , V_94 , V_95 ) ;
}
static struct V_48 * F_49 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_96 * * V_97 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_98 ;
struct V_96 * V_99 ;
if ( ! V_52 )
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
if ( ! V_52 )
return NULL ;
V_99 = (struct V_96 * ) F_38 ( V_52 , sizeof( struct V_96 ) ) ;
V_99 -> V_101 = type ;
V_99 -> V_102 = 0 ;
V_99 -> V_103 = 0 ;
V_99 -> V_104 = V_26 -> V_105 ;
V_98 = F_41 ( V_52 ) ;
V_98 -> V_91 = F_39 ( F_50 ( V_98 -> V_91 ) + 1 ) ;
* V_97 = V_99 ;
return V_52 ;
}
static struct V_48 * F_51 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_98 ;
struct V_96 * V_99 = NULL ;
struct V_27 * V_28 , * V_106 , * V_107 , * * V_108 ;
int V_45 , V_109 , V_110 , V_111 , V_112 ;
if ( V_26 -> V_105 == V_113 )
return V_52 ;
V_111 = type == V_31 ||
type == V_32 ;
V_112 = type == V_32 ||
type == V_41 ;
V_109 = V_45 = 0 ;
V_108 = V_30 ? & V_26 -> V_114 : & V_26 -> V_46 ;
if ( ! * V_108 )
goto V_115;
V_98 = V_52 ? F_41 ( V_52 ) : NULL ;
if ( V_112 ) {
if ( V_98 && V_98 -> V_91 &&
F_52 ( V_52 ) < F_48 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_42 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
}
}
V_110 = 1 ;
V_107 = NULL ;
for ( V_28 = * V_108 ; V_28 ; V_28 = V_106 ) {
T_1 * V_116 ;
V_106 = V_28 -> V_47 ;
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_107 = V_28 ;
continue;
}
if ( V_111 )
V_28 -> V_34 = 0 ;
if ( F_52 ( V_52 ) < sizeof( T_1 ) +
V_110 * sizeof( struct V_96 ) ) {
if ( V_112 && ! V_110 )
break;
if ( V_99 )
V_99 -> V_103 = F_39 ( V_45 ) ;
if ( V_52 )
F_42 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
V_110 = 1 ;
V_45 = 0 ;
}
if ( V_110 ) {
V_52 = F_49 ( V_52 , V_26 , type , & V_99 ) ;
V_110 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_116 = ( T_1 * ) F_38 ( V_52 , sizeof( T_1 ) ) ;
* V_116 = V_28 -> V_117 ;
V_45 ++ ; V_109 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
* V_108 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
continue;
}
}
V_107 = V_28 ;
}
V_115:
if ( ! V_109 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_118 || V_111 ) {
if ( V_52 && F_52 ( V_52 ) < sizeof( struct V_96 ) ) {
F_42 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_49 ( V_52 , V_26 , type , & V_99 ) ;
}
}
if ( V_99 )
V_99 -> V_103 = F_39 ( V_45 ) ;
if ( V_111 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
int type ;
if ( ! V_26 ) {
F_55 () ;
F_56 (in_dev, pmc) {
if ( V_26 -> V_105 == V_113 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_57 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_42 ( V_52 ) ;
}
static void F_58 ( struct V_27 * * V_119 )
{
struct V_27 * V_107 , * V_106 , * V_28 ;
V_107 = NULL ;
for ( V_28 = * V_119 ; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
* V_119 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
} else
V_107 = V_28 ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_120 , * V_121 ;
struct V_48 * V_52 = NULL ;
int type , V_122 ;
F_55 () ;
F_11 ( & V_2 -> V_123 ) ;
V_120 = NULL ;
for ( V_26 = V_2 -> V_124 ; V_26 ; V_26 = V_121 ) {
V_121 = V_26 -> V_125 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_122 = V_44 ;
V_52 = F_51 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_51 ( V_52 , V_26 , V_122 , 1 , 1 ) ;
}
if ( V_26 -> V_118 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_51 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_118 -- ;
if ( V_26 -> V_118 == 0 ) {
F_58 ( & V_26 -> V_114 ) ;
F_58 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_118 == 0 && ! V_26 -> V_114 && ! V_26 -> V_46 ) {
if ( V_120 )
V_120 -> V_125 = V_121 ;
else
V_2 -> V_124 = V_121 ;
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
} else
V_120 = V_26 ;
}
F_14 ( & V_2 -> V_123 ) ;
F_56 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_122 = V_42 ;
} else {
type = V_42 ;
V_122 = V_44 ;
}
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_51 ( V_52 , V_26 , V_122 , 0 , 1 ) ;
if ( V_26 -> V_118 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_118 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_57 () ;
if ( ! V_52 )
return;
( void ) F_42 ( V_52 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_126 ;
struct V_92 * V_127 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
T_1 V_128 = V_26 ? V_26 -> V_105 : 0 ;
struct V_60 V_61 ;
T_1 V_72 ;
int V_62 , V_63 ;
if ( type == V_87 )
return F_54 ( V_2 , V_26 ) ;
else if ( type == V_129 )
V_72 = V_130 ;
else
V_72 = V_128 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_72 , 0 ,
0 , 0 ,
V_70 , 0 , V_50 -> V_71 ) ;
if ( F_32 ( V_54 ) )
return - 1 ;
V_62 = F_28 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_29 ( V_131 + V_62 + V_63 , V_65 ) ;
if ( V_52 == NULL ) {
F_61 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_67 = V_68 ;
F_34 ( V_52 , & V_54 -> V_72 ) ;
F_35 ( V_52 , V_62 ) ;
F_36 ( V_52 ) ;
V_126 = F_37 ( V_52 ) ;
F_38 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_126 -> V_73 = 4 ;
V_126 -> V_74 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_126 -> V_75 = 0xc0 ;
V_126 -> V_76 = F_39 ( V_77 ) ;
V_126 -> V_78 = 1 ;
V_126 -> V_79 = V_72 ;
V_126 -> V_80 = V_61 . V_80 ;
V_126 -> V_81 = V_70 ;
F_40 ( V_52 , NULL ) ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 0 ] = V_84 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 1 ] = 4 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 2 ] = 0 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 3 ] = 0 ;
V_127 = (struct V_92 * ) F_38 ( V_52 , sizeof( struct V_92 ) ) ;
V_127 -> type = type ;
V_127 -> V_132 = 0 ;
V_127 -> V_89 = 0 ;
V_127 -> V_128 = V_128 ;
V_127 -> V_89 = F_46 ( ( void * ) V_127 , sizeof( struct V_92 ) ) ;
return F_47 ( V_52 ) ;
}
static void F_62 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
V_2 -> V_21 = 0 ;
F_54 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_63 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
F_59 ( V_2 ) ;
if ( V_2 -> V_134 ) {
V_2 -> V_134 -- ;
F_21 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_134 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
F_21 ( V_2 , 1 ) ;
}
static void F_65 ( unsigned long V_133 )
{
struct V_7 * V_8 = (struct V_7 * ) V_133 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_66 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_67 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_60 ( V_2 , V_8 , V_137 ) ;
else if ( F_3 ( V_2 ) )
F_60 ( V_2 , V_8 , V_138 ) ;
else
F_60 ( V_2 , V_8 , V_87 ) ;
F_6 ( V_8 ) ;
}
static int F_68 ( struct V_7 * V_26 , int V_139 , T_1 * V_140 )
{
struct V_27 * V_28 ;
int V_141 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_139 )
break;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_140 [ V_141 ] == V_28 -> V_117 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_139 )
return 0 ;
return 1 ;
}
static int F_69 ( struct V_7 * V_26 , int V_139 , T_1 * V_140 )
{
struct V_27 * V_28 ;
int V_141 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_68 ( V_26 , V_139 , V_140 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_139 )
break;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ )
if ( V_140 [ V_141 ] == V_28 -> V_117 ) {
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
static bool F_70 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_7 * V_8 ;
if ( V_128 == V_113 )
return false ;
F_55 () ;
F_56 (in_dev, im) {
if ( V_8 -> V_105 == V_128 ) {
F_10 ( V_8 ) ;
break;
}
}
F_57 () ;
return false ;
}
static bool F_71 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_142 )
{
struct V_92 * V_127 = F_43 ( V_52 ) ;
struct V_143 * V_144 = F_72 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_128 = V_127 -> V_128 ;
int V_17 ;
int V_145 = 0 ;
if ( V_142 == 8 ) {
if ( V_127 -> V_132 == 0 ) {
V_17 = V_146 ;
V_2 -> V_147 = V_19 +
V_148 ;
V_128 = 0 ;
} else {
V_17 = V_127 -> V_132 * ( V_149 / V_150 ) ;
V_2 -> V_151 = V_19 +
V_152 ;
}
V_2 -> V_134 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
} else if ( V_142 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_146 ;
V_128 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_75 ( V_144 -> V_132 ) * ( V_149 / V_150 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_76 ( V_52 , sizeof( struct V_143 ) ) )
return true ;
V_144 = F_72 ( V_52 ) ;
if ( V_144 -> V_139 ) {
if ( ! F_76 ( V_52 , sizeof( struct V_143 )
+ F_50 ( V_144 -> V_139 ) * sizeof( T_1 ) ) )
return true ;
V_144 = F_72 ( V_52 ) ;
}
V_17 = F_75 ( V_144 -> V_132 ) * ( V_149 / V_150 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_144 -> V_153 )
V_2 -> V_135 = V_144 -> V_153 ;
if ( ! V_128 ) {
if ( V_144 -> V_139 )
return false ;
F_19 ( V_2 ) ;
return false ;
}
V_145 = V_144 -> V_139 != 0 ;
}
F_55 () ;
F_56 (in_dev, im) {
int V_154 ;
if ( V_128 && V_128 != V_8 -> V_105 )
continue;
if ( V_8 -> V_105 == V_113 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_145 ;
else
V_8 -> V_33 = V_145 ;
V_154 = ! V_8 -> V_33 ||
F_69 ( V_8 , F_50 ( V_144 -> V_139 ) , V_144 -> V_140 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_154 )
F_22 ( V_8 , V_17 ) ;
}
F_57 () ;
return false ;
}
int F_77 ( struct V_48 * V_52 )
{
struct V_92 * V_127 ;
struct V_1 * V_2 = F_78 ( V_52 -> V_50 ) ;
int V_142 = V_52 -> V_142 ;
bool V_155 = true ;
if ( V_2 == NULL )
goto V_156;
if ( ! F_76 ( V_52 , sizeof( struct V_92 ) ) )
goto V_156;
if ( F_79 ( V_52 ) )
goto V_156;
V_127 = F_43 ( V_52 ) ;
switch ( V_127 -> type ) {
case V_157 :
V_155 = F_71 ( V_2 , V_52 , V_142 ) ;
break;
case V_137 :
case V_138 :
if ( F_80 ( F_81 ( V_52 ) ) )
break;
if ( V_52 -> V_158 == V_159 ||
V_52 -> V_158 == V_160 )
V_155 = F_70 ( V_2 , V_127 -> V_128 ) ;
break;
case V_161 :
#ifdef F_82
return F_83 ( V_52 ) ;
#endif
case V_87 :
case V_162 :
case V_163 :
case V_129 :
case V_164 :
case V_165 :
break;
default:
break;
}
V_156:
if ( V_155 )
F_33 ( V_52 ) ;
else
F_84 ( V_52 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 , T_1 V_166 )
{
char V_167 [ V_168 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_86 ( V_166 , V_167 , V_50 , 0 ) == 0 )
F_87 ( V_50 , V_167 ) ;
}
static void F_88 ( struct V_1 * V_2 , T_1 V_166 )
{
char V_167 [ V_168 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_86 ( V_166 , V_167 , V_50 , 0 ) == 0 )
F_89 ( V_50 , V_167 ) ;
}
static void F_90 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
V_26 = F_91 ( sizeof( * V_26 ) , V_169 ) ;
if ( ! V_26 )
return;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_20 ( V_2 ) ;
V_26 -> V_105 = V_8 -> V_105 ;
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_114 = V_8 -> V_114 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_114 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_118 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_123 ) ;
V_26 -> V_125 = V_2 -> V_124 ;
V_2 -> V_124 = V_26 ;
F_14 ( & V_2 -> V_123 ) ;
}
static void F_92 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_7 * V_26 , * V_120 ;
struct V_27 * V_28 , * V_106 ;
F_11 ( & V_2 -> V_123 ) ;
V_120 = NULL ;
for ( V_26 = V_2 -> V_124 ; V_26 ; V_26 = V_26 -> V_125 ) {
if ( V_26 -> V_105 == V_105 )
break;
V_120 = V_26 ;
}
if ( V_26 ) {
if ( V_120 )
V_120 -> V_125 = V_26 -> V_125 ;
else
V_2 -> V_124 = V_26 -> V_125 ;
}
F_14 ( & V_2 -> V_123 ) ;
if ( V_26 ) {
for ( V_28 = V_26 -> V_114 ; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_170 ;
F_11 ( & V_2 -> V_123 ) ;
V_26 = V_2 -> V_124 ;
V_2 -> V_124 = NULL ;
F_14 ( & V_2 -> V_123 ) ;
for (; V_26 ; V_26 = V_170 ) {
V_170 = V_26 -> V_125 ;
F_93 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
}
F_55 () ;
F_56 (in_dev, pmc) {
struct V_27 * V_28 , * V_106 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_114 ;
V_26 -> V_114 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
}
F_57 () ;
}
static void F_94 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_95
int V_15 ;
#endif
if ( V_8 -> V_171 ) {
V_8 -> V_171 = 0 ;
F_88 ( V_2 , V_8 -> V_105 ) ;
}
#ifdef F_95
if ( V_8 -> V_105 == V_113 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_172 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_60 ( V_2 , V_8 , V_129 ) ;
return;
}
F_90 ( V_2 , V_8 ) ;
F_64 ( V_2 ) ;
}
#endif
}
static void F_96 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
if ( V_8 -> V_171 == 0 ) {
V_8 -> V_171 = 1 ;
F_85 ( V_2 , V_8 -> V_105 ) ;
}
#ifdef F_95
if ( V_8 -> V_105 == V_113 )
return;
if ( V_2 -> V_172 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_173 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
F_64 ( V_2 ) ;
#endif
}
static T_2 F_97 ( const struct V_7 * V_8 )
{
return F_98 ( ( V_174 T_2 ) V_8 -> V_105 , V_175 ) ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_176 ;
T_2 V_177 ;
V_176 = F_100 ( V_2 -> V_176 ) ;
if ( V_176 ) {
V_177 = F_97 ( V_8 ) ;
V_8 -> V_178 = V_176 [ V_177 ] ;
F_101 ( V_176 [ V_177 ] , V_8 ) ;
return;
}
if ( V_2 -> V_179 < 4 )
return;
V_176 = F_91 ( sizeof( struct V_7 * ) << V_175 ,
V_169 ) ;
if ( ! V_176 )
return;
F_102 (in_dev, im) {
V_177 = F_97 ( V_8 ) ;
V_8 -> V_178 = V_176 [ V_177 ] ;
F_103 ( V_176 [ V_177 ] , V_8 ) ;
}
F_101 ( V_2 -> V_176 , V_176 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_176 = F_100 ( V_2 -> V_176 ) ;
struct V_7 * V_180 ;
if ( ! V_176 )
return;
V_176 += F_97 ( V_8 ) ;
while ( ( V_180 = F_100 ( * V_176 ) ) != V_8 )
V_176 = & V_180 -> V_178 ;
* V_176 = V_8 -> V_178 ;
}
void F_105 ( struct V_1 * V_2 , T_1 V_166 )
{
struct V_7 * V_8 ;
F_106 () ;
F_102 (in_dev, im) {
if ( V_8 -> V_105 == V_166 ) {
V_8 -> V_181 ++ ;
F_107 ( V_2 , & V_166 , V_39 , 0 , NULL , 0 ) ;
goto V_182;
}
}
V_8 = F_91 ( sizeof( * V_8 ) , V_169 ) ;
if ( ! V_8 )
goto V_182;
V_8 -> V_181 = 1 ;
V_8 -> V_10 = V_2 ;
F_20 ( V_2 ) ;
V_8 -> V_105 = V_166 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_108 ( & V_8 -> V_9 , 1 ) ;
F_109 ( & V_8 -> V_12 ) ;
#ifdef F_95
F_110 ( & V_8 -> V_13 , F_65 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_136 ;
#endif
V_8 -> V_183 = V_2 -> V_184 ;
V_2 -> V_179 ++ ;
F_101 ( V_2 -> V_184 , V_8 ) ;
F_99 ( V_2 , V_8 ) ;
#ifdef F_95
F_92 ( V_2 , V_8 -> V_105 ) ;
#endif
F_96 ( V_8 ) ;
if ( ! V_2 -> V_172 )
F_111 ( V_2 ) ;
V_182:
return;
}
static void F_112 ( struct V_1 * V_2 )
{
#ifdef F_95
struct V_7 * V_8 ;
int type ;
F_106 () ;
F_102 (in_dev, im) {
if ( V_8 -> V_105 == V_113 )
continue;
if ( F_2 ( V_2 ) )
type = V_137 ;
else if ( F_3 ( V_2 ) )
type = V_138 ;
else
type = V_87 ;
F_60 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_113 ( struct V_1 * V_2 , T_1 V_166 )
{
struct V_7 * V_141 ;
struct V_7 T_3 * * V_185 ;
F_106 () ;
for ( V_185 = & V_2 -> V_184 ;
( V_141 = F_100 ( * V_185 ) ) != NULL ;
V_185 = & V_141 -> V_183 ) {
if ( V_141 -> V_105 == V_166 ) {
if ( -- V_141 -> V_181 == 0 ) {
F_104 ( V_2 , V_141 ) ;
* V_185 = V_141 -> V_183 ;
V_2 -> V_179 -- ;
F_94 ( V_141 ) ;
F_93 ( V_141 ) ;
if ( ! V_2 -> V_172 )
F_111 ( V_2 ) ;
F_6 ( V_141 ) ;
return;
}
break;
}
}
}
void F_114 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_106 () ;
F_102 (in_dev, pmc)
F_94 ( V_26 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_106 () ;
F_102 (in_dev, pmc)
F_96 ( V_26 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_106 () ;
F_102 (in_dev, pmc)
F_94 ( V_26 ) ;
#ifdef F_95
V_2 -> V_134 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_73 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
#endif
F_113 ( V_2 , V_113 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
F_106 () ;
#ifdef F_95
F_110 ( & V_2 -> V_22 , F_62 ,
( unsigned long ) V_2 ) ;
F_110 ( & V_2 -> V_24 , F_63 ,
( unsigned long ) V_2 ) ;
V_2 -> V_135 = V_136 ;
#endif
F_109 ( & V_2 -> V_123 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_106 () ;
F_105 ( V_2 , V_113 ) ;
F_102 (in_dev, pmc)
F_96 ( V_26 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
struct V_7 * V_141 ;
F_106 () ;
F_116 ( V_2 ) ;
while ( ( V_141 = F_100 ( V_2 -> V_184 ) ) != NULL ) {
V_2 -> V_184 = V_141 -> V_183 ;
V_2 -> V_179 -- ;
F_93 ( V_141 ) ;
F_6 ( V_141 ) ;
}
}
static struct V_1 * F_120 ( struct V_59 * V_59 , struct V_186 * V_187 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_188 = NULL ;
if ( V_187 -> V_189 ) {
V_188 = F_121 ( V_59 , V_187 -> V_189 ) ;
return V_188 ;
}
if ( V_187 -> V_190 . V_191 ) {
V_50 = F_122 ( V_59 , V_187 -> V_190 . V_191 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_123 ( V_59 ,
V_187 -> V_192 . V_191 ,
0 , 0 , 0 ) ;
if ( ! F_32 ( V_54 ) ) {
V_50 = V_54 -> V_72 . V_50 ;
F_61 ( V_54 ) ;
}
}
if ( V_50 ) {
V_187 -> V_189 = V_50 -> V_71 ;
V_188 = F_124 ( V_50 ) ;
}
return V_188 ;
}
static int F_125 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_193 )
{
struct V_27 * V_28 , * V_107 ;
int V_194 = 0 ;
V_107 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == * V_193 )
break;
V_107 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_195 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_111 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_95
struct V_1 * V_2 = V_26 -> V_10 ;
#endif
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_95
if ( V_28 -> V_196 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_28 -> V_47 = V_26 -> V_114 ;
V_26 -> V_114 = V_28 ;
V_194 = 1 ;
} else
#endif
F_53 ( V_28 ) ;
}
return V_194 ;
}
static int F_126 ( struct V_1 * V_2 , T_1 * V_197 , int V_35 ,
int V_38 , T_1 * V_193 , int V_198 )
{
struct V_7 * V_26 ;
int V_199 = 0 ;
int V_141 , V_200 ;
if ( ! V_2 )
return - V_201 ;
F_55 () ;
F_56 (in_dev, pmc) {
if ( * V_197 == V_26 -> V_105 )
break;
}
if ( ! V_26 ) {
F_57 () ;
return - V_195 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_57 () ;
#ifdef F_95
F_127 ( V_26 ) ;
#endif
if ( ! V_198 ) {
V_200 = - V_202 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_203;
V_26 -> V_38 [ V_35 ] -- ;
}
V_200 = 0 ;
for ( V_141 = 0 ; V_141 < V_38 ; V_141 ++ ) {
int V_194 = F_125 ( V_26 , V_35 , & V_193 [ V_141 ] ) ;
V_199 |= V_194 > 0 ;
if ( ! V_200 && V_194 < 0 )
V_200 = V_194 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_95
struct V_27 * V_28 ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_95
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_2 -> V_134 = V_26 -> V_118 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_64 ( V_26 -> V_10 ) ;
} else if ( F_128 ( V_26 ) || V_199 ) {
F_64 ( V_26 -> V_10 ) ;
#endif
}
V_203:
F_14 ( & V_26 -> V_12 ) ;
return V_200 ;
}
static int F_129 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_193 )
{
struct V_27 * V_28 , * V_107 ;
V_107 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == * V_193 )
break;
V_107 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_91 ( sizeof( * V_28 ) , V_65 ) ;
if ( ! V_28 )
return - V_204 ;
V_28 -> V_117 = * V_193 ;
if ( V_107 ) {
V_107 -> V_47 = V_28 ;
} else
V_26 -> V_46 = V_28 ;
}
V_28 -> V_37 [ V_35 ] ++ ;
if ( V_28 -> V_37 [ V_35 ] == 1 ) {
F_111 ( V_26 -> V_10 ) ;
}
return 0 ;
}
static void F_127 ( struct V_7 * V_26 )
{
struct V_27 * V_28 ;
int V_205 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_196 = V_205 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_196 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_128 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_206 ;
int V_205 = V_26 -> V_38 [ V_39 ] ;
int V_153 = V_26 -> V_10 -> V_135 ;
int V_207 , V_194 ;
V_194 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_207 = V_205 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_207 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_207 ) {
if ( ! V_28 -> V_196 ) {
struct V_27 * V_208 = NULL ;
for ( V_206 = V_26 -> V_114 ; V_206 ; V_206 = V_206 -> V_47 ) {
if ( V_206 -> V_117 == V_28 -> V_117 )
break;
V_208 = V_206 ;
}
if ( V_206 ) {
if ( V_208 )
V_208 -> V_47 = V_206 -> V_47 ;
else
V_26 -> V_114 = V_206 -> V_47 ;
F_53 ( V_206 ) ;
}
V_28 -> V_43 = V_153 ;
V_194 ++ ;
}
} else if ( V_28 -> V_196 ) {
V_28 -> V_43 = 0 ;
for ( V_206 = V_26 -> V_114 ; V_206 ; V_206 = V_206 -> V_47 )
if ( V_206 -> V_117 == V_28 -> V_117 )
break;
if ( ! V_206 ) {
V_206 = F_130 ( sizeof( * V_206 ) , V_65 ) ;
if ( ! V_206 )
continue;
* V_206 = * V_28 ;
V_206 -> V_47 = V_26 -> V_114 ;
V_26 -> V_114 = V_206 ;
}
V_206 -> V_43 = V_153 ;
V_194 ++ ;
}
}
return V_194 ;
}
static int F_107 ( struct V_1 * V_2 , T_1 * V_197 , int V_35 ,
int V_38 , T_1 * V_193 , int V_198 )
{
struct V_7 * V_26 ;
int V_209 ;
int V_141 , V_200 ;
if ( ! V_2 )
return - V_201 ;
F_55 () ;
F_56 (in_dev, pmc) {
if ( * V_197 == V_26 -> V_105 )
break;
}
if ( ! V_26 ) {
F_57 () ;
return - V_195 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_57 () ;
#ifdef F_95
F_127 ( V_26 ) ;
#endif
V_209 = V_26 -> V_35 == V_39 ;
if ( ! V_198 )
V_26 -> V_38 [ V_35 ] ++ ;
V_200 = 0 ;
for ( V_141 = 0 ; V_141 < V_38 ; V_141 ++ ) {
V_200 = F_129 ( V_26 , V_35 , & V_193 [ V_141 ] ) ;
if ( V_200 )
break;
}
if ( V_200 ) {
int V_210 ;
if ( ! V_198 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_210 = 0 ; V_210 < V_141 ; V_210 ++ )
( void ) F_125 ( V_26 , V_35 , & V_193 [ V_210 ] ) ;
} else if ( V_209 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_95
struct V_27 * V_28 ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_95
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_2 -> V_134 = V_26 -> V_118 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_64 ( V_2 ) ;
} else if ( F_128 ( V_26 ) ) {
F_64 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_200 ;
}
static void F_93 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_211 ;
for ( V_28 = V_26 -> V_114 ; V_28 ; V_28 = V_211 ) {
V_211 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
V_26 -> V_114 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_211 ) {
V_211 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
}
int F_131 ( struct V_212 * V_213 , struct V_186 * V_187 )
{
int V_200 ;
T_1 V_166 = V_187 -> V_192 . V_191 ;
struct V_214 * V_215 = NULL , * V_141 ;
struct V_1 * V_2 ;
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
int V_71 ;
int V_218 = 0 ;
if ( ! F_134 ( V_166 ) )
return - V_202 ;
F_135 () ;
V_2 = F_120 ( V_59 , V_187 ) ;
if ( ! V_2 ) {
V_215 = NULL ;
V_200 = - V_201 ;
goto V_219;
}
V_200 = - V_220 ;
V_71 = V_187 -> V_189 ;
F_102 (inet, i) {
if ( V_141 -> V_221 . V_192 . V_191 == V_166 &&
V_141 -> V_221 . V_189 == V_71 )
goto V_219;
V_218 ++ ;
}
V_200 = - V_204 ;
if ( V_218 >= V_222 )
goto V_219;
V_215 = F_136 ( V_213 , sizeof( * V_215 ) , V_169 ) ;
if ( V_215 == NULL )
goto V_219;
memcpy ( & V_215 -> V_221 , V_187 , sizeof( * V_187 ) ) ;
V_215 -> V_183 = V_217 -> V_184 ;
V_215 -> V_223 = NULL ;
V_215 -> V_35 = V_39 ;
F_101 ( V_217 -> V_184 , V_215 ) ;
F_105 ( V_2 , V_166 ) ;
V_200 = 0 ;
V_219:
F_137 () ;
return V_200 ;
}
static int F_138 ( struct V_212 * V_213 , struct V_214 * V_215 ,
struct V_1 * V_2 )
{
struct V_224 * V_28 = F_100 ( V_215 -> V_223 ) ;
int V_200 ;
if ( V_28 == NULL ) {
return F_126 ( V_2 , & V_215 -> V_221 . V_192 . V_191 ,
V_215 -> V_35 , 0 , NULL , 0 ) ;
}
V_200 = F_126 ( V_2 , & V_215 -> V_221 . V_192 . V_191 ,
V_215 -> V_35 , V_28 -> V_225 , V_28 -> V_226 , 0 ) ;
F_103 ( V_215 -> V_223 , NULL ) ;
F_139 ( F_140 ( V_28 -> V_227 ) , & V_213 -> V_228 ) ;
F_9 ( V_28 , V_11 ) ;
return V_200 ;
}
int F_141 ( struct V_212 * V_213 , struct V_186 * V_187 )
{
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_214 * V_215 ;
struct V_214 T_3 * * V_229 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
T_1 V_128 = V_187 -> V_192 . V_191 ;
T_2 V_71 ;
int V_230 = - V_231 ;
F_135 () ;
V_2 = F_120 ( V_59 , V_187 ) ;
if ( ! V_2 ) {
V_230 = - V_201 ;
goto V_182;
}
V_71 = V_187 -> V_189 ;
for ( V_229 = & V_217 -> V_184 ;
( V_215 = F_100 ( * V_229 ) ) != NULL ;
V_229 = & V_215 -> V_183 ) {
if ( V_215 -> V_221 . V_192 . V_191 != V_128 )
continue;
if ( V_71 ) {
if ( V_215 -> V_221 . V_189 != V_71 )
continue;
} else if ( V_187 -> V_190 . V_191 && V_187 -> V_190 . V_191 !=
V_215 -> V_221 . V_190 . V_191 )
continue;
( void ) F_138 ( V_213 , V_215 , V_2 ) ;
* V_229 = V_215 -> V_183 ;
F_113 ( V_2 , V_128 ) ;
F_137 () ;
F_139 ( sizeof( * V_215 ) , & V_213 -> V_228 ) ;
F_9 ( V_215 , V_11 ) ;
return 0 ;
}
V_182:
F_137 () ;
return V_230 ;
}
int F_142 ( int V_232 , int V_233 , struct V_212 * V_213 , struct
V_234 * V_235 , int V_71 )
{
int V_200 ;
struct V_186 V_187 ;
T_1 V_166 = V_235 -> V_192 ;
struct V_214 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_224 * V_236 ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
int V_237 = 0 ;
int V_141 , V_210 , V_194 ;
if ( ! F_134 ( V_166 ) )
return - V_202 ;
F_135 () ;
V_187 . V_192 . V_191 = V_235 -> V_192 ;
V_187 . V_190 . V_191 = V_235 -> V_238 ;
V_187 . V_189 = V_71 ;
V_2 = F_120 ( V_59 , & V_187 ) ;
if ( ! V_2 ) {
V_200 = - V_201 ;
goto V_219;
}
V_200 = - V_231 ;
F_102 (inet, pmc) {
if ( ( V_26 -> V_221 . V_192 . V_191 ==
V_187 . V_192 . V_191 ) &&
( V_26 -> V_221 . V_189 == V_187 . V_189 ) )
break;
}
if ( ! V_26 ) {
V_200 = - V_202 ;
goto V_219;
}
if ( V_26 -> V_223 ) {
if ( V_26 -> V_35 != V_233 ) {
V_200 = - V_202 ;
goto V_219;
}
} else if ( V_26 -> V_35 != V_233 ) {
F_107 ( V_2 , & V_235 -> V_192 , V_233 , 0 , NULL , 0 ) ;
F_126 ( V_2 , & V_235 -> V_192 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_233 ;
}
V_236 = F_100 ( V_26 -> V_223 ) ;
if ( ! V_232 ) {
if ( ! V_236 )
goto V_219;
V_194 = ! 0 ;
for ( V_141 = 0 ; V_141 < V_236 -> V_225 ; V_141 ++ ) {
V_194 = memcmp ( & V_236 -> V_226 [ V_141 ] , & V_235 -> V_239 ,
sizeof( T_1 ) ) ;
if ( V_194 == 0 )
break;
}
if ( V_194 )
goto V_219;
if ( V_236 -> V_225 == 1 && V_233 == V_36 ) {
V_237 = 1 ;
goto V_219;
}
F_126 ( V_2 , & V_235 -> V_192 , V_233 , 1 ,
& V_235 -> V_239 , 1 ) ;
for ( V_210 = V_141 + 1 ; V_210 < V_236 -> V_225 ; V_210 ++ )
V_236 -> V_226 [ V_210 - 1 ] = V_236 -> V_226 [ V_210 ] ;
V_236 -> V_225 -- ;
V_200 = 0 ;
goto V_219;
}
if ( V_236 && V_236 -> V_225 >= V_240 ) {
V_200 = - V_204 ;
goto V_219;
}
if ( ! V_236 || V_236 -> V_225 == V_236 -> V_227 ) {
struct V_224 * V_241 ;
int V_218 = V_242 ;
if ( V_236 )
V_218 += V_236 -> V_227 ;
V_241 = F_136 ( V_213 , F_140 ( V_218 ) , V_169 ) ;
if ( ! V_241 ) {
V_200 = - V_204 ;
goto V_219;
}
V_241 -> V_227 = V_218 ;
V_241 -> V_225 = V_218 - V_242 ;
if ( V_236 ) {
for ( V_141 = 0 ; V_141 < V_236 -> V_225 ; V_141 ++ )
V_241 -> V_226 [ V_141 ] = V_236 -> V_226 [ V_141 ] ;
F_139 ( F_140 ( V_236 -> V_227 ) , & V_213 -> V_228 ) ;
F_9 ( V_236 , V_11 ) ;
}
F_101 ( V_26 -> V_223 , V_241 ) ;
V_236 = V_241 ;
}
V_194 = 1 ;
for ( V_141 = 0 ; V_141 < V_236 -> V_225 ; V_141 ++ ) {
V_194 = memcmp ( & V_236 -> V_226 [ V_141 ] , & V_235 -> V_239 ,
sizeof( T_1 ) ) ;
if ( V_194 == 0 )
break;
}
if ( V_194 == 0 )
goto V_219;
for ( V_210 = V_236 -> V_225 - 1 ; V_210 >= V_141 ; V_210 -- )
V_236 -> V_226 [ V_210 + 1 ] = V_236 -> V_226 [ V_210 ] ;
V_236 -> V_226 [ V_141 ] = V_235 -> V_239 ;
V_236 -> V_225 ++ ;
V_200 = 0 ;
F_107 ( V_2 , & V_235 -> V_192 , V_233 , 1 ,
& V_235 -> V_239 , 1 ) ;
V_219:
F_137 () ;
if ( V_237 )
return F_141 ( V_213 , & V_187 ) ;
return V_200 ;
}
int F_143 ( struct V_212 * V_213 , struct V_243 * V_244 , int V_71 )
{
int V_200 = 0 ;
struct V_186 V_187 ;
T_1 V_166 = V_244 -> V_245 ;
struct V_214 * V_26 ;
struct V_1 * V_2 ;
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_224 * V_241 , * V_236 ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
int V_237 = 0 ;
if ( ! F_134 ( V_166 ) )
return - V_202 ;
if ( V_244 -> V_246 != V_36 &&
V_244 -> V_246 != V_39 )
return - V_202 ;
F_135 () ;
V_187 . V_192 . V_191 = V_244 -> V_245 ;
V_187 . V_190 . V_191 = V_244 -> V_247 ;
V_187 . V_189 = V_71 ;
V_2 = F_120 ( V_59 , & V_187 ) ;
if ( ! V_2 ) {
V_200 = - V_201 ;
goto V_219;
}
if ( V_244 -> V_246 == V_36 && V_244 -> V_248 == 0 ) {
V_237 = 1 ;
goto V_219;
}
F_102 (inet, pmc) {
if ( V_26 -> V_221 . V_192 . V_191 == V_244 -> V_245 &&
V_26 -> V_221 . V_189 == V_187 . V_189 )
break;
}
if ( ! V_26 ) {
V_200 = - V_202 ;
goto V_219;
}
if ( V_244 -> V_248 ) {
V_241 = F_136 ( V_213 , F_140 ( V_244 -> V_248 ) ,
V_169 ) ;
if ( ! V_241 ) {
V_200 = - V_204 ;
goto V_219;
}
V_241 -> V_227 = V_241 -> V_225 = V_244 -> V_248 ;
memcpy ( V_241 -> V_226 , V_244 -> V_249 ,
V_244 -> V_248 * sizeof( V_244 -> V_249 [ 0 ] ) ) ;
V_200 = F_107 ( V_2 , & V_244 -> V_245 ,
V_244 -> V_246 , V_241 -> V_225 , V_241 -> V_226 , 0 ) ;
if ( V_200 ) {
F_144 ( V_213 , V_241 , F_140 ( V_241 -> V_227 ) ) ;
goto V_219;
}
} else {
V_241 = NULL ;
( void ) F_107 ( V_2 , & V_244 -> V_245 ,
V_244 -> V_246 , 0 , NULL , 0 ) ;
}
V_236 = F_100 ( V_26 -> V_223 ) ;
if ( V_236 ) {
( void ) F_126 ( V_2 , & V_244 -> V_245 , V_26 -> V_35 ,
V_236 -> V_225 , V_236 -> V_226 , 0 ) ;
F_139 ( F_140 ( V_236 -> V_227 ) , & V_213 -> V_228 ) ;
F_9 ( V_236 , V_11 ) ;
} else
( void ) F_126 ( V_2 , & V_244 -> V_245 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_101 ( V_26 -> V_223 , V_241 ) ;
V_26 -> V_35 = V_244 -> V_246 ;
V_200 = 0 ;
V_219:
F_137 () ;
if ( V_237 )
V_200 = F_141 ( V_213 , & V_187 ) ;
return V_200 ;
}
int F_145 ( struct V_212 * V_213 , struct V_243 * V_244 ,
struct V_243 T_4 * V_250 , int T_4 * V_251 )
{
int V_200 , V_142 , V_218 , V_252 ;
struct V_186 V_187 ;
T_1 V_166 = V_244 -> V_245 ;
struct V_214 * V_26 ;
struct V_1 * V_2 ;
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_224 * V_236 ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
if ( ! F_134 ( V_166 ) )
return - V_202 ;
F_135 () ;
V_187 . V_192 . V_191 = V_244 -> V_245 ;
V_187 . V_190 . V_191 = V_244 -> V_247 ;
V_187 . V_189 = 0 ;
V_2 = F_120 ( V_59 , & V_187 ) ;
if ( ! V_2 ) {
V_200 = - V_201 ;
goto V_219;
}
V_200 = - V_231 ;
F_102 (inet, pmc) {
if ( V_26 -> V_221 . V_192 . V_191 == V_244 -> V_245 &&
V_26 -> V_221 . V_189 == V_187 . V_189 )
break;
}
if ( ! V_26 )
goto V_219;
V_244 -> V_246 = V_26 -> V_35 ;
V_236 = F_100 ( V_26 -> V_223 ) ;
F_137 () ;
if ( ! V_236 ) {
V_142 = 0 ;
V_218 = 0 ;
} else {
V_218 = V_236 -> V_225 ;
}
V_252 = V_218 < V_244 -> V_248 ? V_218 : V_244 -> V_248 ;
V_142 = V_252 * sizeof( V_236 -> V_226 [ 0 ] ) ;
V_244 -> V_248 = V_218 ;
if ( F_146 ( F_147 ( V_252 ) , V_251 ) ||
F_148 ( V_250 , V_244 , F_147 ( 0 ) ) ) {
return - V_253 ;
}
if ( V_142 &&
F_148 ( & V_250 -> V_249 [ 0 ] , V_236 -> V_226 , V_142 ) )
return - V_253 ;
return 0 ;
V_219:
F_137 () ;
return V_200 ;
}
int F_149 ( struct V_212 * V_213 , struct V_254 * V_255 ,
struct V_254 T_4 * V_250 , int T_4 * V_251 )
{
int V_200 , V_141 , V_218 , V_252 ;
struct V_256 * V_257 ;
T_1 V_166 ;
struct V_214 * V_26 ;
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_224 * V_236 ;
V_257 = (struct V_256 * ) & V_255 -> V_258 ;
if ( V_257 -> V_259 != V_260 )
return - V_202 ;
V_166 = V_257 -> V_261 . V_191 ;
if ( ! F_134 ( V_166 ) )
return - V_202 ;
F_135 () ;
V_200 = - V_231 ;
F_102 (inet, pmc) {
if ( V_26 -> V_221 . V_192 . V_191 == V_166 &&
V_26 -> V_221 . V_189 == V_255 -> V_262 )
break;
}
if ( ! V_26 )
goto V_219;
V_255 -> V_263 = V_26 -> V_35 ;
V_236 = F_100 ( V_26 -> V_223 ) ;
F_137 () ;
V_218 = V_236 ? V_236 -> V_225 : 0 ;
V_252 = V_218 < V_255 -> V_264 ? V_218 : V_255 -> V_264 ;
V_255 -> V_264 = V_218 ;
if ( F_146 ( F_150 ( V_252 ) , V_251 ) ||
F_148 ( V_250 , V_255 , F_150 ( 0 ) ) ) {
return - V_253 ;
}
for ( V_141 = 0 ; V_141 < V_252 ; V_141 ++ ) {
struct V_265 V_266 ;
V_257 = (struct V_256 * ) & V_266 ;
memset ( & V_266 , 0 , sizeof( V_266 ) ) ;
V_257 -> V_259 = V_260 ;
V_257 -> V_261 . V_191 = V_236 -> V_226 [ V_141 ] ;
if ( F_148 ( & V_250 -> V_267 [ V_141 ] , & V_266 , sizeof( V_266 ) ) )
return - V_253 ;
}
return 0 ;
V_219:
F_137 () ;
return V_200 ;
}
int F_151 ( struct V_212 * V_213 , T_1 V_268 , T_1 V_269 , int V_270 )
{
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_214 * V_26 ;
struct V_224 * V_236 ;
int V_141 ;
int V_230 ;
V_230 = 1 ;
if ( ! F_134 ( V_268 ) )
goto V_182;
F_55 () ;
F_56 (inet, pmc) {
if ( V_26 -> V_221 . V_192 . V_191 == V_268 &&
V_26 -> V_221 . V_189 == V_270 )
break;
}
V_230 = V_217 -> V_271 ;
if ( ! V_26 )
goto V_272;
V_236 = F_152 ( V_26 -> V_223 ) ;
V_230 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_236 )
goto V_272;
for ( V_141 = 0 ; V_141 < V_236 -> V_225 ; V_141 ++ ) {
if ( V_236 -> V_226 [ V_141 ] == V_269 )
break;
}
V_230 = 0 ;
if ( V_26 -> V_35 == V_36 && V_141 >= V_236 -> V_225 )
goto V_272;
if ( V_26 -> V_35 == V_39 && V_141 < V_236 -> V_225 )
goto V_272;
V_230 = 1 ;
V_272:
F_57 () ;
V_182:
return V_230 ;
}
void F_153 ( struct V_212 * V_213 )
{
struct V_216 * V_217 = F_132 ( V_213 ) ;
struct V_214 * V_215 ;
struct V_59 * V_59 = F_133 ( V_213 ) ;
if ( V_217 -> V_184 == NULL )
return;
F_135 () ;
while ( ( V_215 = F_100 ( V_217 -> V_184 ) ) != NULL ) {
struct V_1 * V_2 ;
V_217 -> V_184 = V_215 -> V_183 ;
V_2 = F_121 ( V_59 , V_215 -> V_221 . V_189 ) ;
( void ) F_138 ( V_213 , V_215 , V_2 ) ;
if ( V_2 != NULL )
F_113 ( V_2 , V_215 -> V_221 . V_192 . V_191 ) ;
F_139 ( sizeof( * V_215 ) , & V_213 -> V_228 ) ;
F_9 ( V_215 , V_11 ) ;
}
F_137 () ;
}
int F_154 ( struct V_1 * V_2 , T_1 V_273 , T_1 V_274 , T_5 V_275 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_176 ;
struct V_27 * V_28 ;
int V_194 = 0 ;
V_176 = F_152 ( V_2 -> V_176 ) ;
if ( V_176 ) {
T_2 V_177 = F_98 ( ( V_174 T_2 ) V_273 , V_175 ) ;
for ( V_8 = F_152 ( V_176 [ V_177 ] ) ;
V_8 != NULL ;
V_8 = F_152 ( V_8 -> V_178 ) ) {
if ( V_8 -> V_105 == V_273 )
break;
}
} else {
F_56 (in_dev, im) {
if ( V_8 -> V_105 == V_273 )
break;
}
}
if ( V_8 && V_275 == V_70 ) {
V_194 = 1 ;
} else if ( V_8 ) {
if ( V_274 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == V_274 )
break;
}
if ( V_28 )
V_194 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_194 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_194 = 1 ;
}
return V_194 ;
}
static inline struct V_7 * F_155 ( struct V_276 * V_277 )
{
struct V_59 * V_59 = F_156 ( V_277 ) ;
struct V_7 * V_8 = NULL ;
struct V_278 * V_279 = F_157 ( V_277 ) ;
V_279 -> V_2 = NULL ;
F_158 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_78 ( V_279 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_152 ( V_2 -> V_184 ) ;
if ( V_8 ) {
V_279 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_159 ( struct V_276 * V_277 , struct V_7 * V_8 )
{
struct V_278 * V_279 = F_157 ( V_277 ) ;
V_8 = F_152 ( V_8 -> V_183 ) ;
while ( ! V_8 ) {
V_279 -> V_50 = F_160 ( V_279 -> V_50 ) ;
if ( ! V_279 -> V_50 ) {
V_279 -> V_2 = NULL ;
break;
}
V_279 -> V_2 = F_78 ( V_279 -> V_50 ) ;
if ( ! V_279 -> V_2 )
continue;
V_8 = F_152 ( V_279 -> V_2 -> V_184 ) ;
}
return V_8 ;
}
static struct V_7 * F_161 ( struct V_276 * V_277 , T_6 V_280 )
{
struct V_7 * V_8 = F_155 ( V_277 ) ;
if ( V_8 )
while ( V_280 && ( V_8 = F_159 ( V_277 , V_8 ) ) != NULL )
-- V_280 ;
return V_280 ? NULL : V_8 ;
}
static void * F_162 ( struct V_276 * V_277 , T_6 * V_280 )
__acquires( V_11 )
{
F_55 () ;
return * V_280 ? F_161 ( V_277 , * V_280 - 1 ) : V_281 ;
}
static void * F_163 ( struct V_276 * V_277 , void * V_282 , T_6 * V_280 )
{
struct V_7 * V_8 ;
if ( V_282 == V_281 )
V_8 = F_155 ( V_277 ) ;
else
V_8 = F_159 ( V_277 , V_282 ) ;
++ * V_280 ;
return V_8 ;
}
static void F_164 ( struct V_276 * V_277 , void * V_282 )
__releases( V_11 )
{
struct V_278 * V_279 = F_157 ( V_277 ) ;
V_279 -> V_2 = NULL ;
V_279 -> V_50 = NULL ;
F_57 () ;
}
static int F_165 ( struct V_276 * V_277 , void * V_282 )
{
if ( V_282 == V_281 )
F_166 ( V_277 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_282 ;
struct V_278 * V_279 = F_157 ( V_277 ) ;
char * V_283 ;
long V_198 ;
#ifdef F_95
V_283 = F_2 ( V_279 -> V_2 ) ? L_2 :
F_3 ( V_279 -> V_2 ) ? L_3 :
L_4 ;
#else
V_283 = L_5 ;
#endif
if ( F_152 ( V_279 -> V_2 -> V_184 ) == V_8 ) {
F_167 ( V_277 , L_6 ,
V_279 -> V_50 -> V_71 , V_279 -> V_50 -> V_284 , V_279 -> V_2 -> V_179 , V_283 ) ;
}
V_198 = V_8 -> V_13 . V_25 - V_19 ;
F_167 ( V_277 ,
L_7 ,
V_8 -> V_105 , V_8 -> V_181 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_168 ( V_198 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_169 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
return F_170 ( V_285 , V_286 , & V_287 ,
sizeof( struct V_278 ) ) ;
}
static inline struct V_27 * F_171 ( struct V_276 * V_277 )
{
struct V_59 * V_59 = F_156 ( V_277 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_288 * V_279 = F_172 ( V_277 ) ;
V_279 -> V_188 = NULL ;
V_279 -> V_8 = NULL ;
F_158 (net, state->dev) {
struct V_1 * V_188 ;
V_188 = F_78 ( V_279 -> V_50 ) ;
if ( F_173 ( V_188 == NULL ) )
continue;
V_8 = F_152 ( V_188 -> V_184 ) ;
if ( F_174 ( V_8 != NULL ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_174 ( V_28 != NULL ) ) {
V_279 -> V_8 = V_8 ;
V_279 -> V_188 = V_188 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_175 ( struct V_276 * V_277 , struct V_27 * V_28 )
{
struct V_288 * V_279 = F_172 ( V_277 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_279 -> V_8 -> V_12 ) ;
V_279 -> V_8 = V_279 -> V_8 -> V_125 ;
while ( ! V_279 -> V_8 ) {
V_279 -> V_50 = F_160 ( V_279 -> V_50 ) ;
if ( ! V_279 -> V_50 ) {
V_279 -> V_188 = NULL ;
goto V_182;
}
V_279 -> V_188 = F_78 ( V_279 -> V_50 ) ;
if ( ! V_279 -> V_188 )
continue;
V_279 -> V_8 = F_152 ( V_279 -> V_188 -> V_184 ) ;
}
if ( ! V_279 -> V_8 )
break;
F_11 ( & V_279 -> V_8 -> V_12 ) ;
V_28 = V_279 -> V_8 -> V_46 ;
}
V_182:
return V_28 ;
}
static struct V_27 * F_176 ( struct V_276 * V_277 , T_6 V_280 )
{
struct V_27 * V_28 = F_171 ( V_277 ) ;
if ( V_28 )
while ( V_280 && ( V_28 = F_175 ( V_277 , V_28 ) ) != NULL )
-- V_280 ;
return V_280 ? NULL : V_28 ;
}
static void * F_177 ( struct V_276 * V_277 , T_6 * V_280 )
__acquires( V_11 )
{
F_55 () ;
return * V_280 ? F_176 ( V_277 , * V_280 - 1 ) : V_281 ;
}
static void * F_178 ( struct V_276 * V_277 , void * V_282 , T_6 * V_280 )
{
struct V_27 * V_28 ;
if ( V_282 == V_281 )
V_28 = F_171 ( V_277 ) ;
else
V_28 = F_175 ( V_277 , V_282 ) ;
++ * V_280 ;
return V_28 ;
}
static void F_179 ( struct V_276 * V_277 , void * V_282 )
__releases( V_11 )
{
struct V_288 * V_279 = F_172 ( V_277 ) ;
if ( F_174 ( V_279 -> V_8 != NULL ) ) {
F_14 ( & V_279 -> V_8 -> V_12 ) ;
V_279 -> V_8 = NULL ;
}
V_279 -> V_188 = NULL ;
V_279 -> V_50 = NULL ;
F_57 () ;
}
static int F_180 ( struct V_276 * V_277 , void * V_282 )
{
struct V_27 * V_28 = (struct V_27 * ) V_282 ;
struct V_288 * V_279 = F_172 ( V_277 ) ;
if ( V_282 == V_281 ) {
F_167 ( V_277 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_167 ( V_277 ,
L_16
L_17 ,
V_279 -> V_50 -> V_71 , V_279 -> V_50 -> V_284 ,
F_181 ( V_279 -> V_8 -> V_105 ) ,
F_181 ( V_28 -> V_117 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_182 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
return F_170 ( V_285 , V_286 , & V_289 ,
sizeof( struct V_288 ) ) ;
}
static int T_7 F_183 ( struct V_59 * V_59 )
{
struct V_290 * V_291 ;
V_291 = F_184 ( L_18 , V_292 , V_59 -> V_293 , & V_294 ) ;
if ( ! V_291 )
goto V_295;
V_291 = F_184 ( L_19 , V_292 , V_59 -> V_293 ,
& V_296 ) ;
if ( ! V_291 )
goto V_297;
return 0 ;
V_297:
F_185 ( L_18 , V_59 -> V_293 ) ;
V_295:
return - V_298 ;
}
static void T_8 F_186 ( struct V_59 * V_59 )
{
F_185 ( L_19 , V_59 -> V_293 ) ;
F_185 ( L_18 , V_59 -> V_293 ) ;
}
static int F_187 ( struct V_299 * V_300 ,
unsigned long V_301 , void * V_302 )
{
struct V_49 * V_50 = F_188 ( V_302 ) ;
struct V_1 * V_2 ;
switch ( V_301 ) {
case V_303 :
V_2 = F_124 ( V_50 ) ;
if ( V_2 )
F_112 ( V_2 ) ;
break;
default:
break;
}
return V_304 ;
}
int T_9 F_189 ( void )
{
#if F_190 ( V_305 )
int V_200 ;
V_200 = F_191 ( & V_306 ) ;
if ( V_200 )
return V_200 ;
V_200 = F_192 ( & V_307 ) ;
if ( V_200 )
goto V_308;
return 0 ;
V_308:
F_193 ( & V_306 ) ;
return V_200 ;
#else
return F_192 ( & V_307 ) ;
#endif
}
