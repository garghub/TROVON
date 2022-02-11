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
return F_48 ( F_27 ( F_49 ( V_52 ) -> V_50 ) , V_52 -> V_96 , V_52 ) ;
}
static int F_50 ( struct V_7 * V_26 , int type , int V_97 , int V_98 )
{
return sizeof( struct V_99 ) + 4 * F_25 ( V_26 , type , V_97 , V_98 ) ;
}
static struct V_48 * F_51 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_99 * * V_100 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_101 ;
struct V_99 * V_102 ;
if ( ! V_52 )
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
if ( ! V_52 )
return NULL ;
V_102 = (struct V_99 * ) F_39 ( V_52 , sizeof( struct V_99 ) ) ;
V_102 -> V_103 = type ;
V_102 -> V_104 = 0 ;
V_102 -> V_105 = 0 ;
V_102 -> V_106 = V_26 -> V_107 ;
V_101 = F_42 ( V_52 ) ;
V_101 -> V_93 = F_40 ( F_52 ( V_101 -> V_93 ) + 1 ) ;
* V_100 = V_102 ;
return V_52 ;
}
static struct V_48 * F_53 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_101 ;
struct V_99 * V_102 = NULL ;
struct V_27 * V_28 , * V_108 , * V_109 , * * V_110 ;
int V_45 , V_111 , V_112 , V_113 , V_114 ;
if ( V_26 -> V_107 == V_115 )
return V_52 ;
if ( F_54 ( V_26 -> V_107 ) && ! V_116 )
return V_52 ;
V_113 = type == V_31 ||
type == V_32 ;
V_114 = type == V_32 ||
type == V_41 ;
V_111 = V_45 = 0 ;
V_110 = V_30 ? & V_26 -> V_117 : & V_26 -> V_46 ;
if ( ! * V_110 )
goto V_118;
V_101 = V_52 ? F_42 ( V_52 ) : NULL ;
if ( V_114 ) {
if ( V_101 && V_101 -> V_93 &&
F_55 ( V_52 ) < F_50 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
}
}
V_112 = 1 ;
V_109 = NULL ;
for ( V_28 = * V_110 ; V_28 ; V_28 = V_108 ) {
T_1 * V_119 ;
V_108 = V_28 -> V_47 ;
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_109 = V_28 ;
continue;
}
if ( V_113 )
V_28 -> V_34 = 0 ;
if ( F_55 ( V_52 ) < sizeof( T_1 ) +
V_112 * sizeof( struct V_99 ) ) {
if ( V_114 && ! V_112 )
break;
if ( V_102 )
V_102 -> V_105 = F_40 ( V_45 ) ;
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
V_112 = 1 ;
V_45 = 0 ;
}
if ( V_112 ) {
V_52 = F_51 ( V_52 , V_26 , type , & V_102 ) ;
V_112 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_119 = ( T_1 * ) F_39 ( V_52 , sizeof( T_1 ) ) ;
* V_119 = V_28 -> V_120 ;
V_45 ++ ; V_111 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_109 )
V_109 -> V_47 = V_28 -> V_47 ;
else
* V_110 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
continue;
}
}
V_109 = V_28 ;
}
V_118:
if ( ! V_111 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_121 || V_113 ) {
if ( V_52 && F_55 ( V_52 ) < sizeof( struct V_99 ) ) {
F_43 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_51 ( V_52 , V_26 , type , & V_102 ) ;
}
}
if ( V_102 )
V_102 -> V_105 = F_40 ( V_45 ) ;
if ( V_113 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
int type ;
if ( ! V_26 ) {
F_58 () ;
F_59 (in_dev, pmc) {
if ( V_26 -> V_107 == V_115 )
continue;
if ( F_54 ( V_26 -> V_107 ) &&
! V_116 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_60 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_43 ( V_52 ) ;
}
static void F_61 ( struct V_27 * * V_122 )
{
struct V_27 * V_109 , * V_108 , * V_28 ;
V_109 = NULL ;
for ( V_28 = * V_122 ; V_28 ; V_28 = V_108 ) {
V_108 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_109 )
V_109 -> V_47 = V_28 -> V_47 ;
else
* V_122 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
} else
V_109 = V_28 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_123 , * V_124 ;
struct V_48 * V_52 = NULL ;
int type , V_125 ;
F_58 () ;
F_11 ( & V_2 -> V_126 ) ;
V_123 = NULL ;
for ( V_26 = V_2 -> V_127 ; V_26 ; V_26 = V_124 ) {
V_124 = V_26 -> V_128 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_125 = V_44 ;
V_52 = F_53 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_53 ( V_52 , V_26 , V_125 , 1 , 1 ) ;
}
if ( V_26 -> V_121 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_53 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_121 -- ;
if ( V_26 -> V_121 == 0 ) {
F_61 ( & V_26 -> V_117 ) ;
F_61 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_121 == 0 && ! V_26 -> V_117 && ! V_26 -> V_46 ) {
if ( V_123 )
V_123 -> V_128 = V_124 ;
else
V_2 -> V_127 = V_124 ;
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
} else
V_123 = V_26 ;
}
F_14 ( & V_2 -> V_126 ) ;
F_59 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_125 = V_42 ;
} else {
type = V_42 ;
V_125 = V_44 ;
}
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_53 ( V_52 , V_26 , V_125 , 0 , 1 ) ;
if ( V_26 -> V_121 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_121 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_60 () ;
if ( ! V_52 )
return;
( void ) F_43 ( V_52 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_129 ;
struct V_94 * V_130 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
T_1 V_131 = V_26 ? V_26 -> V_107 : 0 ;
struct V_60 V_61 ;
T_1 V_73 ;
int V_62 , V_63 ;
if ( type == V_89 )
return F_57 ( V_2 , V_26 ) ;
if ( F_54 ( V_131 ) && ! V_116 )
return 0 ;
if ( type == V_132 )
V_73 = V_133 ;
else
V_73 = V_131 ;
V_54 = F_30 ( V_59 , & V_61 , NULL , V_73 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_31 ( V_54 ) )
return - 1 ;
V_62 = F_28 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_29 ( V_134 + V_62 + V_63 , V_66 ) ;
if ( ! V_52 ) {
F_64 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_68 = V_69 ;
F_33 ( V_52 , & V_54 -> V_73 ) ;
F_36 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_129 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_129 -> V_75 = 4 ;
V_129 -> V_76 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_129 -> V_77 = 0xc0 ;
V_129 -> V_78 = F_40 ( V_79 ) ;
V_129 -> V_80 = 1 ;
V_129 -> V_81 = V_73 ;
V_129 -> V_82 = V_61 . V_82 ;
V_129 -> V_83 = V_71 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_85 * ) & V_129 [ 1 ] ) [ 0 ] = V_86 ;
( ( V_85 * ) & V_129 [ 1 ] ) [ 1 ] = 4 ;
( ( V_85 * ) & V_129 [ 1 ] ) [ 2 ] = 0 ;
( ( V_85 * ) & V_129 [ 1 ] ) [ 3 ] = 0 ;
V_130 = (struct V_94 * ) F_39 ( V_52 , sizeof( struct V_94 ) ) ;
V_130 -> type = type ;
V_130 -> V_135 = 0 ;
V_130 -> V_91 = 0 ;
V_130 -> V_131 = V_131 ;
V_130 -> V_91 = F_47 ( ( void * ) V_130 , sizeof( struct V_94 ) ) ;
return F_48 ( V_59 , V_52 -> V_96 , V_52 ) ;
}
static void F_65 ( unsigned long V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_136 ;
V_2 -> V_21 = 0 ;
F_57 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_66 ( unsigned long V_136 )
{
struct V_1 * V_2 = (struct V_1 * ) V_136 ;
F_62 ( V_2 ) ;
if ( V_2 -> V_137 ) {
V_2 -> V_137 -- ;
F_21 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_137 = V_2 -> V_138 ? : V_139 ;
F_21 ( V_2 , 1 ) ;
}
static void F_68 ( unsigned long V_136 )
{
struct V_7 * V_8 = (struct V_7 * ) V_136 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_69 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_70 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_63 ( V_2 , V_8 , V_140 ) ;
else if ( F_3 ( V_2 ) )
F_63 ( V_2 , V_8 , V_141 ) ;
else
F_63 ( V_2 , V_8 , V_89 ) ;
F_6 ( V_8 ) ;
}
static int F_71 ( struct V_7 * V_26 , int V_142 , T_1 * V_143 )
{
struct V_27 * V_28 ;
int V_144 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_142 )
break;
for ( V_144 = 0 ; V_144 < V_142 ; V_144 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_143 [ V_144 ] == V_28 -> V_120 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_142 )
return 0 ;
return 1 ;
}
static int F_72 ( struct V_7 * V_26 , int V_142 , T_1 * V_143 )
{
struct V_27 * V_28 ;
int V_144 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_71 ( V_26 , V_142 , V_143 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_142 )
break;
for ( V_144 = 0 ; V_144 < V_142 ; V_144 ++ )
if ( V_143 [ V_144 ] == V_28 -> V_120 ) {
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
static bool F_73 ( struct V_1 * V_2 , T_1 V_131 )
{
struct V_7 * V_8 ;
if ( V_131 == V_115 )
return false ;
if ( F_54 ( V_131 ) && ! V_116 )
return false ;
F_58 () ;
F_59 (in_dev, im) {
if ( V_8 -> V_107 == V_131 ) {
F_10 ( V_8 ) ;
break;
}
}
F_60 () ;
return false ;
}
static bool F_74 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_145 )
{
struct V_94 * V_130 = F_44 ( V_52 ) ;
struct V_146 * V_147 = F_75 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_131 = V_130 -> V_131 ;
int V_17 ;
int V_148 = 0 ;
if ( V_145 == 8 ) {
if ( V_130 -> V_135 == 0 ) {
V_17 = V_149 ;
V_2 -> V_150 = V_19 +
V_151 ;
V_131 = 0 ;
} else {
V_17 = V_130 -> V_135 * ( V_152 / V_153 ) ;
V_2 -> V_154 = V_19 +
V_155 ;
}
V_2 -> V_137 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
} else if ( V_145 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_149 ;
V_131 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_78 ( V_147 -> V_135 ) * ( V_152 / V_153 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_79 ( V_52 , sizeof( struct V_146 ) ) )
return true ;
V_147 = F_75 ( V_52 ) ;
if ( V_147 -> V_142 ) {
if ( ! F_79 ( V_52 , sizeof( struct V_146 )
+ F_52 ( V_147 -> V_142 ) * sizeof( T_1 ) ) )
return true ;
V_147 = F_75 ( V_52 ) ;
}
V_17 = F_78 ( V_147 -> V_135 ) * ( V_152 / V_153 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_147 -> V_156 )
V_2 -> V_138 = V_147 -> V_156 ;
if ( ! V_131 ) {
if ( V_147 -> V_142 )
return true ;
F_19 ( V_2 ) ;
return false ;
}
V_148 = V_147 -> V_142 != 0 ;
}
F_58 () ;
F_59 (in_dev, im) {
int V_157 ;
if ( V_131 && V_131 != V_8 -> V_107 )
continue;
if ( V_8 -> V_107 == V_115 )
continue;
if ( F_54 ( V_8 -> V_107 ) &&
! V_116 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_148 ;
else
V_8 -> V_33 = V_148 ;
V_157 = ! V_8 -> V_33 ||
F_72 ( V_8 , F_52 ( V_147 -> V_142 ) , V_147 -> V_143 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_157 )
F_22 ( V_8 , V_17 ) ;
}
F_60 () ;
return false ;
}
int F_80 ( struct V_48 * V_52 )
{
struct V_94 * V_130 ;
struct V_1 * V_2 = F_81 ( V_52 -> V_50 ) ;
int V_145 = V_52 -> V_145 ;
bool V_158 = true ;
if ( ! V_2 )
goto V_159;
if ( ! F_79 ( V_52 , sizeof( struct V_94 ) ) )
goto V_159;
if ( F_82 ( V_52 ) )
goto V_159;
V_130 = F_44 ( V_52 ) ;
switch ( V_130 -> type ) {
case V_160 :
V_158 = F_74 ( V_2 , V_52 , V_145 ) ;
break;
case V_140 :
case V_141 :
if ( F_83 ( F_84 ( V_52 ) ) )
break;
if ( V_52 -> V_161 == V_162 ||
V_52 -> V_161 == V_163 )
V_158 = F_73 ( V_2 , V_130 -> V_131 ) ;
break;
case V_164 :
#ifdef F_85
return F_86 ( V_52 ) ;
#endif
case V_89 :
case V_165 :
case V_166 :
case V_132 :
case V_167 :
case V_168 :
break;
default:
break;
}
V_159:
if ( V_158 )
F_32 ( V_52 ) ;
else
F_87 ( V_52 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , T_1 V_169 )
{
char V_170 [ V_171 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_89 ( V_169 , V_170 , V_50 , 0 ) == 0 )
F_90 ( V_50 , V_170 ) ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_169 )
{
char V_170 [ V_171 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_89 ( V_169 , V_170 , V_50 , 0 ) == 0 )
F_92 ( V_50 , V_170 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
V_26 = F_94 ( sizeof( * V_26 ) , V_172 ) ;
if ( ! V_26 )
return;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_20 ( V_2 ) ;
V_26 -> V_107 = V_8 -> V_107 ;
V_26 -> V_121 = V_2 -> V_138 ? : V_139 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_117 = V_8 -> V_117 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_117 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_121 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_126 ) ;
V_26 -> V_128 = V_2 -> V_127 ;
V_2 -> V_127 = V_26 ;
F_14 ( & V_2 -> V_126 ) ;
}
static void F_95 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_7 * V_26 , * V_123 ;
struct V_27 * V_28 , * V_108 ;
F_11 ( & V_2 -> V_126 ) ;
V_123 = NULL ;
for ( V_26 = V_2 -> V_127 ; V_26 ; V_26 = V_26 -> V_128 ) {
if ( V_26 -> V_107 == V_107 )
break;
V_123 = V_26 ;
}
if ( V_26 ) {
if ( V_123 )
V_123 -> V_128 = V_26 -> V_128 ;
else
V_2 -> V_127 = V_26 -> V_128 ;
}
F_14 ( & V_2 -> V_126 ) ;
if ( V_26 ) {
for ( V_28 = V_26 -> V_117 ; V_28 ; V_28 = V_108 ) {
V_108 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_173 ;
F_11 ( & V_2 -> V_126 ) ;
V_26 = V_2 -> V_127 ;
V_2 -> V_127 = NULL ;
F_14 ( & V_2 -> V_126 ) ;
for (; V_26 ; V_26 = V_173 ) {
V_173 = V_26 -> V_128 ;
F_96 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
}
F_58 () ;
F_59 (in_dev, pmc) {
struct V_27 * V_28 , * V_108 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_117 ;
V_26 -> V_117 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_108 ) {
V_108 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
}
F_60 () ;
}
static void F_97 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_98
int V_15 ;
#endif
if ( V_8 -> V_174 ) {
V_8 -> V_174 = 0 ;
F_91 ( V_2 , V_8 -> V_107 ) ;
}
#ifdef F_98
if ( V_8 -> V_107 == V_115 )
return;
if ( F_54 ( V_8 -> V_107 ) && ! V_116 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_175 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_63 ( V_2 , V_8 , V_132 ) ;
return;
}
F_93 ( V_2 , V_8 ) ;
F_67 ( V_2 ) ;
}
#endif
}
static void F_99 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
if ( V_8 -> V_174 == 0 ) {
V_8 -> V_174 = 1 ;
F_88 ( V_2 , V_8 -> V_107 ) ;
}
#ifdef F_98
if ( V_8 -> V_107 == V_115 )
return;
if ( F_54 ( V_8 -> V_107 ) && ! V_116 )
return;
if ( V_2 -> V_175 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_176 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_121 = V_2 -> V_138 ? : V_139 ;
F_67 ( V_2 ) ;
#endif
}
static T_2 F_100 ( const struct V_7 * V_8 )
{
return F_101 ( ( V_177 T_2 ) V_8 -> V_107 , V_178 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_179 ;
T_2 V_180 ;
V_179 = F_103 ( V_2 -> V_179 ) ;
if ( V_179 ) {
V_180 = F_100 ( V_8 ) ;
V_8 -> V_181 = V_179 [ V_180 ] ;
F_104 ( V_179 [ V_180 ] , V_8 ) ;
return;
}
if ( V_2 -> V_182 < 4 )
return;
V_179 = F_94 ( sizeof( struct V_7 * ) << V_178 ,
V_172 ) ;
if ( ! V_179 )
return;
F_105 (in_dev, im) {
V_180 = F_100 ( V_8 ) ;
V_8 -> V_181 = V_179 [ V_180 ] ;
F_106 ( V_179 [ V_180 ] , V_8 ) ;
}
F_104 ( V_2 -> V_179 , V_179 ) ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_179 = F_103 ( V_2 -> V_179 ) ;
struct V_7 * V_183 ;
if ( ! V_179 )
return;
V_179 += F_100 ( V_8 ) ;
while ( ( V_183 = F_103 ( * V_179 ) ) != V_8 )
V_179 = & V_183 -> V_181 ;
* V_179 = V_8 -> V_181 ;
}
void F_108 ( struct V_1 * V_2 , T_1 V_169 )
{
struct V_7 * V_8 ;
F_109 () ;
F_105 (in_dev, im) {
if ( V_8 -> V_107 == V_169 ) {
V_8 -> V_184 ++ ;
F_110 ( V_2 , & V_169 , V_39 , 0 , NULL , 0 ) ;
goto V_185;
}
}
V_8 = F_94 ( sizeof( * V_8 ) , V_172 ) ;
if ( ! V_8 )
goto V_185;
V_8 -> V_184 = 1 ;
V_8 -> V_10 = V_2 ;
F_20 ( V_2 ) ;
V_8 -> V_107 = V_169 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_111 ( & V_8 -> V_9 , 1 ) ;
F_112 ( & V_8 -> V_12 ) ;
#ifdef F_98
F_113 ( & V_8 -> V_13 , F_68 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_139 ;
#endif
V_8 -> V_186 = V_2 -> V_187 ;
V_2 -> V_182 ++ ;
F_104 ( V_2 -> V_187 , V_8 ) ;
F_102 ( V_2 , V_8 ) ;
#ifdef F_98
F_95 ( V_2 , V_8 -> V_107 ) ;
#endif
F_99 ( V_8 ) ;
if ( ! V_2 -> V_175 )
F_114 ( V_2 ) ;
V_185:
return;
}
static int F_115 ( struct V_48 * V_52 )
{
const struct V_55 * V_129 ;
unsigned int V_145 ;
unsigned int V_188 = F_116 ( V_52 ) + sizeof( * V_129 ) ;
if ( ! F_79 ( V_52 , V_188 ) )
return - V_189 ;
V_129 = F_38 ( V_52 ) ;
if ( V_129 -> V_75 != 4 || F_117 ( V_52 ) < sizeof( * V_129 ) )
return - V_189 ;
V_188 += F_117 ( V_52 ) - sizeof( * V_129 ) ;
if ( ! F_79 ( V_52 , V_188 ) )
return - V_189 ;
V_129 = F_38 ( V_52 ) ;
if ( F_118 ( F_119 ( ( V_85 * ) V_129 , V_129 -> V_76 ) ) )
return - V_189 ;
V_145 = F_116 ( V_52 ) + F_52 ( V_129 -> V_84 ) ;
if ( V_52 -> V_145 < V_145 || V_145 < V_188 )
return - V_189 ;
F_120 ( V_52 , V_188 ) ;
return 0 ;
}
static int F_121 ( struct V_48 * V_52 )
{
unsigned int V_145 = F_122 ( V_52 ) ;
V_145 += sizeof( struct V_57 ) ;
return F_79 ( V_52 , V_145 ) ? 0 : - V_189 ;
}
static int F_123 ( struct V_48 * V_52 )
{
unsigned int V_145 = F_122 ( V_52 ) ;
V_145 += sizeof( struct V_94 ) ;
if ( V_52 -> V_145 < V_145 )
return - V_189 ;
if ( V_52 -> V_145 != V_145 ) {
V_145 += sizeof( struct V_146 ) - sizeof( struct V_94 ) ;
if ( V_52 -> V_145 < V_145 || ! F_79 ( V_52 , V_145 ) )
return - V_189 ;
}
if ( ! F_44 ( V_52 ) -> V_131 &&
F_38 ( V_52 ) -> V_81 != F_124 ( V_190 ) )
return - V_189 ;
return 0 ;
}
static int F_125 ( struct V_48 * V_52 )
{
switch ( F_44 ( V_52 ) -> type ) {
case V_132 :
case V_140 :
case V_141 :
return 0 ;
case V_89 :
return F_121 ( V_52 ) ;
case V_160 :
return F_123 ( V_52 ) ;
default:
return - V_191 ;
}
}
static inline T_4 F_126 ( struct V_48 * V_52 )
{
return F_82 ( V_52 ) ;
}
static int F_127 ( struct V_48 * V_52 , struct V_48 * * V_192 )
{
struct V_48 * V_193 ;
unsigned int V_194 ;
unsigned int V_145 = F_122 ( V_52 ) + sizeof( struct V_94 ) ;
int V_195 = - V_189 ;
V_194 = F_52 ( F_38 ( V_52 ) -> V_84 ) - F_117 ( V_52 ) ;
V_193 = F_128 ( V_52 , V_194 ,
F_126 ) ;
if ( ! V_193 )
goto V_196;
if ( ! F_79 ( V_193 , V_145 ) )
goto V_196;
V_195 = F_125 ( V_193 ) ;
if ( V_195 )
goto V_196;
if ( V_192 )
* V_192 = V_193 ;
else if ( V_193 != V_52 )
F_32 ( V_193 ) ;
V_195 = 0 ;
V_196:
if ( V_195 && V_193 && V_193 != V_52 )
F_32 ( V_193 ) ;
return V_195 ;
}
int F_129 ( struct V_48 * V_52 , struct V_48 * * V_192 )
{
int V_195 = F_115 ( V_52 ) ;
if ( V_195 < 0 )
return V_195 ;
if ( F_38 ( V_52 ) -> V_83 != V_71 )
return - V_191 ;
return F_127 ( V_52 , V_192 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
#ifdef F_98
struct V_7 * V_8 ;
int type ;
F_109 () ;
F_105 (in_dev, im) {
if ( V_8 -> V_107 == V_115 )
continue;
if ( F_54 ( V_8 -> V_107 ) &&
! V_116 )
continue;
if ( F_2 ( V_2 ) )
type = V_140 ;
else if ( F_3 ( V_2 ) )
type = V_141 ;
else
type = V_89 ;
F_63 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_131 ( struct V_1 * V_2 , T_1 V_169 )
{
struct V_7 * V_144 ;
struct V_7 T_3 * * V_197 ;
F_109 () ;
for ( V_197 = & V_2 -> V_187 ;
( V_144 = F_103 ( * V_197 ) ) != NULL ;
V_197 = & V_144 -> V_186 ) {
if ( V_144 -> V_107 == V_169 ) {
if ( -- V_144 -> V_184 == 0 ) {
F_107 ( V_2 , V_144 ) ;
* V_197 = V_144 -> V_186 ;
V_2 -> V_182 -- ;
F_97 ( V_144 ) ;
F_96 ( V_144 ) ;
if ( ! V_2 -> V_175 )
F_114 ( V_2 ) ;
F_6 ( V_144 ) ;
return;
}
break;
}
}
}
void F_132 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_109 () ;
F_105 (in_dev, pmc)
F_97 ( V_26 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_109 () ;
F_105 (in_dev, pmc)
F_99 ( V_26 ) ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_109 () ;
F_105 (in_dev, pmc)
F_97 ( V_26 ) ;
#ifdef F_98
V_2 -> V_137 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_76 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
#endif
F_131 ( V_2 , V_115 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
F_109 () ;
#ifdef F_98
F_113 ( & V_2 -> V_22 , F_65 ,
( unsigned long ) V_2 ) ;
F_113 ( & V_2 -> V_24 , F_66 ,
( unsigned long ) V_2 ) ;
V_2 -> V_138 = V_139 ;
#endif
F_112 ( & V_2 -> V_126 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_109 () ;
#ifdef F_98
V_2 -> V_138 = V_139 ;
#endif
F_108 ( V_2 , V_115 ) ;
F_105 (in_dev, pmc)
F_99 ( V_26 ) ;
}
void F_137 ( struct V_1 * V_2 )
{
struct V_7 * V_144 ;
F_109 () ;
F_134 ( V_2 ) ;
while ( ( V_144 = F_103 ( V_2 -> V_187 ) ) != NULL ) {
V_2 -> V_187 = V_144 -> V_186 ;
V_2 -> V_182 -- ;
F_96 ( V_144 ) ;
F_6 ( V_144 ) ;
}
}
static struct V_1 * F_138 ( struct V_59 * V_59 , struct V_198 * V_199 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_200 = NULL ;
if ( V_199 -> V_201 ) {
V_200 = F_139 ( V_59 , V_199 -> V_201 ) ;
return V_200 ;
}
if ( V_199 -> V_202 . V_203 ) {
V_50 = F_140 ( V_59 , V_199 -> V_202 . V_203 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_141 ( V_59 ,
V_199 -> V_204 . V_203 ,
0 , 0 , 0 ) ;
if ( ! F_31 ( V_54 ) ) {
V_50 = V_54 -> V_73 . V_50 ;
F_64 ( V_54 ) ;
}
}
if ( V_50 ) {
V_199 -> V_201 = V_50 -> V_72 ;
V_200 = F_142 ( V_50 ) ;
}
return V_200 ;
}
static int F_143 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_205 )
{
struct V_27 * V_28 , * V_109 ;
int V_206 = 0 ;
V_109 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_120 == * V_205 )
break;
V_109 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_207 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_114 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_98
struct V_1 * V_2 = V_26 -> V_10 ;
#endif
if ( V_109 )
V_109 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_98
if ( V_28 -> V_208 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_138 ? : V_139 ;
V_28 -> V_47 = V_26 -> V_117 ;
V_26 -> V_117 = V_28 ;
V_206 = 1 ;
} else
#endif
F_56 ( V_28 ) ;
}
return V_206 ;
}
static int F_144 ( struct V_1 * V_2 , T_1 * V_209 , int V_35 ,
int V_38 , T_1 * V_205 , int V_210 )
{
struct V_7 * V_26 ;
int V_211 = 0 ;
int V_144 , V_196 ;
if ( ! V_2 )
return - V_212 ;
F_58 () ;
F_59 (in_dev, pmc) {
if ( * V_209 == V_26 -> V_107 )
break;
}
if ( ! V_26 ) {
F_60 () ;
return - V_207 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_60 () ;
#ifdef F_98
F_145 ( V_26 ) ;
#endif
if ( ! V_210 ) {
V_196 = - V_189 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_213;
V_26 -> V_38 [ V_35 ] -- ;
}
V_196 = 0 ;
for ( V_144 = 0 ; V_144 < V_38 ; V_144 ++ ) {
int V_206 = F_143 ( V_26 , V_35 , & V_205 [ V_144 ] ) ;
V_211 |= V_206 > 0 ;
if ( ! V_196 && V_206 < 0 )
V_196 = V_206 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_98
struct V_27 * V_28 ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_98
V_26 -> V_121 = V_2 -> V_138 ? : V_139 ;
V_2 -> V_137 = V_26 -> V_121 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_67 ( V_26 -> V_10 ) ;
} else if ( F_146 ( V_26 ) || V_211 ) {
F_67 ( V_26 -> V_10 ) ;
#endif
}
V_213:
F_14 ( & V_26 -> V_12 ) ;
return V_196 ;
}
static int F_147 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_205 )
{
struct V_27 * V_28 , * V_109 ;
V_109 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_120 == * V_205 )
break;
V_109 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_94 ( sizeof( * V_28 ) , V_66 ) ;
if ( ! V_28 )
return - V_214 ;
V_28 -> V_120 = * V_205 ;
if ( V_109 ) {
V_109 -> V_47 = V_28 ;
} else
V_26 -> V_46 = V_28 ;
}
V_28 -> V_37 [ V_35 ] ++ ;
if ( V_28 -> V_37 [ V_35 ] == 1 ) {
F_114 ( V_26 -> V_10 ) ;
}
return 0 ;
}
static void F_145 ( struct V_7 * V_26 )
{
struct V_27 * V_28 ;
int V_215 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_208 = V_215 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_208 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_146 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_216 ;
int V_215 = V_26 -> V_38 [ V_39 ] ;
int V_156 = V_26 -> V_10 -> V_138 ;
int V_217 , V_206 ;
V_206 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_217 = V_215 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_217 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_217 ) {
if ( ! V_28 -> V_208 ) {
struct V_27 * V_218 = NULL ;
for ( V_216 = V_26 -> V_117 ; V_216 ; V_216 = V_216 -> V_47 ) {
if ( V_216 -> V_120 == V_28 -> V_120 )
break;
V_218 = V_216 ;
}
if ( V_216 ) {
if ( V_218 )
V_218 -> V_47 = V_216 -> V_47 ;
else
V_26 -> V_117 = V_216 -> V_47 ;
F_56 ( V_216 ) ;
}
V_28 -> V_43 = V_156 ;
V_206 ++ ;
}
} else if ( V_28 -> V_208 ) {
V_28 -> V_43 = 0 ;
for ( V_216 = V_26 -> V_117 ; V_216 ; V_216 = V_216 -> V_47 )
if ( V_216 -> V_120 == V_28 -> V_120 )
break;
if ( ! V_216 ) {
V_216 = F_148 ( sizeof( * V_216 ) , V_66 ) ;
if ( ! V_216 )
continue;
* V_216 = * V_28 ;
V_216 -> V_47 = V_26 -> V_117 ;
V_26 -> V_117 = V_216 ;
}
V_216 -> V_43 = V_156 ;
V_206 ++ ;
}
}
return V_206 ;
}
static int F_110 ( struct V_1 * V_2 , T_1 * V_209 , int V_35 ,
int V_38 , T_1 * V_205 , int V_210 )
{
struct V_7 * V_26 ;
int V_219 ;
int V_144 , V_196 ;
if ( ! V_2 )
return - V_212 ;
F_58 () ;
F_59 (in_dev, pmc) {
if ( * V_209 == V_26 -> V_107 )
break;
}
if ( ! V_26 ) {
F_60 () ;
return - V_207 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_60 () ;
#ifdef F_98
F_145 ( V_26 ) ;
#endif
V_219 = V_26 -> V_35 == V_39 ;
if ( ! V_210 )
V_26 -> V_38 [ V_35 ] ++ ;
V_196 = 0 ;
for ( V_144 = 0 ; V_144 < V_38 ; V_144 ++ ) {
V_196 = F_147 ( V_26 , V_35 , & V_205 [ V_144 ] ) ;
if ( V_196 )
break;
}
if ( V_196 ) {
int V_220 ;
if ( ! V_210 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_220 = 0 ; V_220 < V_144 ; V_220 ++ )
( void ) F_143 ( V_26 , V_35 , & V_205 [ V_220 ] ) ;
} else if ( V_219 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_98
struct V_27 * V_28 ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_98
V_26 -> V_121 = V_2 -> V_138 ? : V_139 ;
V_2 -> V_137 = V_26 -> V_121 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_67 ( V_2 ) ;
} else if ( F_146 ( V_26 ) ) {
F_67 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_196 ;
}
static void F_96 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_221 ;
for ( V_28 = V_26 -> V_117 ; V_28 ; V_28 = V_221 ) {
V_221 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
V_26 -> V_117 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_221 ) {
V_221 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
}
int F_149 ( struct V_222 * V_96 , struct V_198 * V_199 )
{
T_1 V_169 = V_199 -> V_204 . V_203 ;
struct V_223 * V_224 , * V_144 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
int V_72 ;
int V_227 = 0 ;
int V_196 ;
F_109 () ;
if ( ! F_152 ( V_169 ) )
return - V_189 ;
V_2 = F_138 ( V_59 , V_199 ) ;
if ( ! V_2 ) {
V_196 = - V_212 ;
goto V_228;
}
V_196 = - V_229 ;
V_72 = V_199 -> V_201 ;
F_105 (inet, i) {
if ( V_144 -> V_230 . V_204 . V_203 == V_169 &&
V_144 -> V_230 . V_201 == V_72 )
goto V_228;
V_227 ++ ;
}
V_196 = - V_214 ;
if ( V_227 >= V_231 )
goto V_228;
V_224 = F_153 ( V_96 , sizeof( * V_224 ) , V_172 ) ;
if ( ! V_224 )
goto V_228;
memcpy ( & V_224 -> V_230 , V_199 , sizeof( * V_199 ) ) ;
V_224 -> V_186 = V_226 -> V_187 ;
V_224 -> V_232 = NULL ;
V_224 -> V_35 = V_39 ;
F_104 ( V_226 -> V_187 , V_224 ) ;
F_108 ( V_2 , V_169 ) ;
V_196 = 0 ;
V_228:
return V_196 ;
}
static int F_154 ( struct V_222 * V_96 , struct V_223 * V_224 ,
struct V_1 * V_2 )
{
struct V_233 * V_28 = F_103 ( V_224 -> V_232 ) ;
int V_196 ;
if ( ! V_28 ) {
return F_144 ( V_2 , & V_224 -> V_230 . V_204 . V_203 ,
V_224 -> V_35 , 0 , NULL , 0 ) ;
}
V_196 = F_144 ( V_2 , & V_224 -> V_230 . V_204 . V_203 ,
V_224 -> V_35 , V_28 -> V_234 , V_28 -> V_235 , 0 ) ;
F_106 ( V_224 -> V_232 , NULL ) ;
F_155 ( F_156 ( V_28 -> V_236 ) , & V_96 -> V_237 ) ;
F_9 ( V_28 , V_11 ) ;
return V_196 ;
}
int F_157 ( struct V_222 * V_96 , struct V_198 * V_199 )
{
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_223 * V_224 ;
struct V_223 T_3 * * V_238 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
T_1 V_131 = V_199 -> V_204 . V_203 ;
T_2 V_72 ;
int V_195 = - V_239 ;
F_109 () ;
V_2 = F_138 ( V_59 , V_199 ) ;
if ( ! V_199 -> V_201 && ! V_199 -> V_202 . V_203 && ! V_2 ) {
V_195 = - V_212 ;
goto V_185;
}
V_72 = V_199 -> V_201 ;
for ( V_238 = & V_226 -> V_187 ;
( V_224 = F_103 ( * V_238 ) ) != NULL ;
V_238 = & V_224 -> V_186 ) {
if ( V_224 -> V_230 . V_204 . V_203 != V_131 )
continue;
if ( V_72 ) {
if ( V_224 -> V_230 . V_201 != V_72 )
continue;
} else if ( V_199 -> V_202 . V_203 && V_199 -> V_202 . V_203 !=
V_224 -> V_230 . V_202 . V_203 )
continue;
( void ) F_154 ( V_96 , V_224 , V_2 ) ;
* V_238 = V_224 -> V_186 ;
if ( V_2 )
F_131 ( V_2 , V_131 ) ;
F_155 ( sizeof( * V_224 ) , & V_96 -> V_237 ) ;
F_9 ( V_224 , V_11 ) ;
return 0 ;
}
V_185:
return V_195 ;
}
int F_158 ( int V_240 , int V_241 , struct V_222 * V_96 , struct
V_242 * V_243 , int V_72 )
{
int V_196 ;
struct V_198 V_199 ;
T_1 V_169 = V_243 -> V_204 ;
struct V_223 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_233 * V_244 ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
int V_245 = 0 ;
int V_144 , V_220 , V_206 ;
if ( ! F_152 ( V_169 ) )
return - V_189 ;
F_109 () ;
V_199 . V_204 . V_203 = V_243 -> V_204 ;
V_199 . V_202 . V_203 = V_243 -> V_246 ;
V_199 . V_201 = V_72 ;
V_2 = F_138 ( V_59 , & V_199 ) ;
if ( ! V_2 ) {
V_196 = - V_212 ;
goto V_228;
}
V_196 = - V_239 ;
F_105 (inet, pmc) {
if ( ( V_26 -> V_230 . V_204 . V_203 ==
V_199 . V_204 . V_203 ) &&
( V_26 -> V_230 . V_201 == V_199 . V_201 ) )
break;
}
if ( ! V_26 ) {
V_196 = - V_189 ;
goto V_228;
}
if ( V_26 -> V_232 ) {
if ( V_26 -> V_35 != V_241 ) {
V_196 = - V_189 ;
goto V_228;
}
} else if ( V_26 -> V_35 != V_241 ) {
F_110 ( V_2 , & V_243 -> V_204 , V_241 , 0 , NULL , 0 ) ;
F_144 ( V_2 , & V_243 -> V_204 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_241 ;
}
V_244 = F_103 ( V_26 -> V_232 ) ;
if ( ! V_240 ) {
if ( ! V_244 )
goto V_228;
V_206 = ! 0 ;
for ( V_144 = 0 ; V_144 < V_244 -> V_234 ; V_144 ++ ) {
V_206 = memcmp ( & V_244 -> V_235 [ V_144 ] , & V_243 -> V_247 ,
sizeof( T_1 ) ) ;
if ( V_206 == 0 )
break;
}
if ( V_206 )
goto V_228;
if ( V_244 -> V_234 == 1 && V_241 == V_36 ) {
V_245 = 1 ;
goto V_228;
}
F_144 ( V_2 , & V_243 -> V_204 , V_241 , 1 ,
& V_243 -> V_247 , 1 ) ;
for ( V_220 = V_144 + 1 ; V_220 < V_244 -> V_234 ; V_220 ++ )
V_244 -> V_235 [ V_220 - 1 ] = V_244 -> V_235 [ V_220 ] ;
V_244 -> V_234 -- ;
V_196 = 0 ;
goto V_228;
}
if ( V_244 && V_244 -> V_234 >= V_248 ) {
V_196 = - V_214 ;
goto V_228;
}
if ( ! V_244 || V_244 -> V_234 == V_244 -> V_236 ) {
struct V_233 * V_249 ;
int V_227 = V_250 ;
if ( V_244 )
V_227 += V_244 -> V_236 ;
V_249 = F_153 ( V_96 , F_156 ( V_227 ) , V_172 ) ;
if ( ! V_249 ) {
V_196 = - V_214 ;
goto V_228;
}
V_249 -> V_236 = V_227 ;
V_249 -> V_234 = V_227 - V_250 ;
if ( V_244 ) {
for ( V_144 = 0 ; V_144 < V_244 -> V_234 ; V_144 ++ )
V_249 -> V_235 [ V_144 ] = V_244 -> V_235 [ V_144 ] ;
F_155 ( F_156 ( V_244 -> V_236 ) , & V_96 -> V_237 ) ;
F_9 ( V_244 , V_11 ) ;
}
F_104 ( V_26 -> V_232 , V_249 ) ;
V_244 = V_249 ;
}
V_206 = 1 ;
for ( V_144 = 0 ; V_144 < V_244 -> V_234 ; V_144 ++ ) {
V_206 = memcmp ( & V_244 -> V_235 [ V_144 ] , & V_243 -> V_247 ,
sizeof( T_1 ) ) ;
if ( V_206 == 0 )
break;
}
if ( V_206 == 0 )
goto V_228;
for ( V_220 = V_244 -> V_234 - 1 ; V_220 >= V_144 ; V_220 -- )
V_244 -> V_235 [ V_220 + 1 ] = V_244 -> V_235 [ V_220 ] ;
V_244 -> V_235 [ V_144 ] = V_243 -> V_247 ;
V_244 -> V_234 ++ ;
V_196 = 0 ;
F_110 ( V_2 , & V_243 -> V_204 , V_241 , 1 ,
& V_243 -> V_247 , 1 ) ;
V_228:
if ( V_245 )
V_196 = F_157 ( V_96 , & V_199 ) ;
return V_196 ;
}
int F_159 ( struct V_222 * V_96 , struct V_251 * V_252 , int V_72 )
{
int V_196 = 0 ;
struct V_198 V_199 ;
T_1 V_169 = V_252 -> V_253 ;
struct V_223 * V_26 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_233 * V_249 , * V_244 ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
int V_245 = 0 ;
if ( ! F_152 ( V_169 ) )
return - V_189 ;
if ( V_252 -> V_254 != V_36 &&
V_252 -> V_254 != V_39 )
return - V_189 ;
F_109 () ;
V_199 . V_204 . V_203 = V_252 -> V_253 ;
V_199 . V_202 . V_203 = V_252 -> V_255 ;
V_199 . V_201 = V_72 ;
V_2 = F_138 ( V_59 , & V_199 ) ;
if ( ! V_2 ) {
V_196 = - V_212 ;
goto V_228;
}
if ( V_252 -> V_254 == V_36 && V_252 -> V_256 == 0 ) {
V_245 = 1 ;
goto V_228;
}
F_105 (inet, pmc) {
if ( V_26 -> V_230 . V_204 . V_203 == V_252 -> V_253 &&
V_26 -> V_230 . V_201 == V_199 . V_201 )
break;
}
if ( ! V_26 ) {
V_196 = - V_189 ;
goto V_228;
}
if ( V_252 -> V_256 ) {
V_249 = F_153 ( V_96 , F_156 ( V_252 -> V_256 ) ,
V_172 ) ;
if ( ! V_249 ) {
V_196 = - V_214 ;
goto V_228;
}
V_249 -> V_236 = V_249 -> V_234 = V_252 -> V_256 ;
memcpy ( V_249 -> V_235 , V_252 -> V_257 ,
V_252 -> V_256 * sizeof( V_252 -> V_257 [ 0 ] ) ) ;
V_196 = F_110 ( V_2 , & V_252 -> V_253 ,
V_252 -> V_254 , V_249 -> V_234 , V_249 -> V_235 , 0 ) ;
if ( V_196 ) {
F_160 ( V_96 , V_249 , F_156 ( V_249 -> V_236 ) ) ;
goto V_228;
}
} else {
V_249 = NULL ;
( void ) F_110 ( V_2 , & V_252 -> V_253 ,
V_252 -> V_254 , 0 , NULL , 0 ) ;
}
V_244 = F_103 ( V_26 -> V_232 ) ;
if ( V_244 ) {
( void ) F_144 ( V_2 , & V_252 -> V_253 , V_26 -> V_35 ,
V_244 -> V_234 , V_244 -> V_235 , 0 ) ;
F_155 ( F_156 ( V_244 -> V_236 ) , & V_96 -> V_237 ) ;
F_9 ( V_244 , V_11 ) ;
} else
( void ) F_144 ( V_2 , & V_252 -> V_253 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_104 ( V_26 -> V_232 , V_249 ) ;
V_26 -> V_35 = V_252 -> V_254 ;
V_196 = 0 ;
V_228:
if ( V_245 )
V_196 = F_157 ( V_96 , & V_199 ) ;
return V_196 ;
}
int F_161 ( struct V_222 * V_96 , struct V_251 * V_252 ,
struct V_251 T_5 * V_258 , int T_5 * V_259 )
{
int V_196 , V_145 , V_227 , V_260 ;
struct V_198 V_199 ;
T_1 V_169 = V_252 -> V_253 ;
struct V_223 * V_26 ;
struct V_1 * V_2 ;
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_233 * V_244 ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
F_109 () ;
if ( ! F_152 ( V_169 ) )
return - V_189 ;
V_199 . V_204 . V_203 = V_252 -> V_253 ;
V_199 . V_202 . V_203 = V_252 -> V_255 ;
V_199 . V_201 = 0 ;
V_2 = F_138 ( V_59 , & V_199 ) ;
if ( ! V_2 ) {
V_196 = - V_212 ;
goto V_228;
}
V_196 = - V_239 ;
F_105 (inet, pmc) {
if ( V_26 -> V_230 . V_204 . V_203 == V_252 -> V_253 &&
V_26 -> V_230 . V_201 == V_199 . V_201 )
break;
}
if ( ! V_26 )
goto V_228;
V_252 -> V_254 = V_26 -> V_35 ;
V_244 = F_103 ( V_26 -> V_232 ) ;
if ( ! V_244 ) {
V_145 = 0 ;
V_227 = 0 ;
} else {
V_227 = V_244 -> V_234 ;
}
V_260 = V_227 < V_252 -> V_256 ? V_227 : V_252 -> V_256 ;
V_145 = V_260 * sizeof( V_244 -> V_235 [ 0 ] ) ;
V_252 -> V_256 = V_227 ;
if ( F_162 ( F_163 ( V_260 ) , V_259 ) ||
F_164 ( V_258 , V_252 , F_163 ( 0 ) ) ) {
return - V_261 ;
}
if ( V_145 &&
F_164 ( & V_258 -> V_257 [ 0 ] , V_244 -> V_235 , V_145 ) )
return - V_261 ;
return 0 ;
V_228:
return V_196 ;
}
int F_165 ( struct V_222 * V_96 , struct V_262 * V_263 ,
struct V_262 T_5 * V_258 , int T_5 * V_259 )
{
int V_196 , V_144 , V_227 , V_260 ;
struct V_264 * V_265 ;
T_1 V_169 ;
struct V_223 * V_26 ;
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_233 * V_244 ;
F_109 () ;
V_265 = (struct V_264 * ) & V_263 -> V_266 ;
if ( V_265 -> V_267 != V_268 )
return - V_189 ;
V_169 = V_265 -> V_269 . V_203 ;
if ( ! F_152 ( V_169 ) )
return - V_189 ;
V_196 = - V_239 ;
F_105 (inet, pmc) {
if ( V_26 -> V_230 . V_204 . V_203 == V_169 &&
V_26 -> V_230 . V_201 == V_263 -> V_270 )
break;
}
if ( ! V_26 )
goto V_228;
V_263 -> V_271 = V_26 -> V_35 ;
V_244 = F_103 ( V_26 -> V_232 ) ;
V_227 = V_244 ? V_244 -> V_234 : 0 ;
V_260 = V_227 < V_263 -> V_272 ? V_227 : V_263 -> V_272 ;
V_263 -> V_272 = V_227 ;
if ( F_162 ( F_166 ( V_260 ) , V_259 ) ||
F_164 ( V_258 , V_263 , F_166 ( 0 ) ) ) {
return - V_261 ;
}
for ( V_144 = 0 ; V_144 < V_260 ; V_144 ++ ) {
struct V_273 V_274 ;
V_265 = (struct V_264 * ) & V_274 ;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
V_265 -> V_267 = V_268 ;
V_265 -> V_269 . V_203 = V_244 -> V_235 [ V_144 ] ;
if ( F_164 ( & V_258 -> V_275 [ V_144 ] , & V_274 , sizeof( V_274 ) ) )
return - V_261 ;
}
return 0 ;
V_228:
return V_196 ;
}
int F_167 ( struct V_222 * V_96 , T_1 V_276 , T_1 V_277 , int V_278 )
{
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_223 * V_26 ;
struct V_233 * V_244 ;
int V_144 ;
int V_195 ;
V_195 = 1 ;
if ( ! F_152 ( V_276 ) )
goto V_185;
F_58 () ;
F_59 (inet, pmc) {
if ( V_26 -> V_230 . V_204 . V_203 == V_276 &&
V_26 -> V_230 . V_201 == V_278 )
break;
}
V_195 = V_226 -> V_279 ;
if ( ! V_26 )
goto V_280;
V_244 = F_168 ( V_26 -> V_232 ) ;
V_195 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_244 )
goto V_280;
for ( V_144 = 0 ; V_144 < V_244 -> V_234 ; V_144 ++ ) {
if ( V_244 -> V_235 [ V_144 ] == V_277 )
break;
}
V_195 = 0 ;
if ( V_26 -> V_35 == V_36 && V_144 >= V_244 -> V_234 )
goto V_280;
if ( V_26 -> V_35 == V_39 && V_144 < V_244 -> V_234 )
goto V_280;
V_195 = 1 ;
V_280:
F_60 () ;
V_185:
return V_195 ;
}
void F_169 ( struct V_222 * V_96 )
{
struct V_225 * V_226 = F_150 ( V_96 ) ;
struct V_223 * V_224 ;
struct V_59 * V_59 = F_151 ( V_96 ) ;
if ( ! V_226 -> V_187 )
return;
F_170 () ;
while ( ( V_224 = F_103 ( V_226 -> V_187 ) ) != NULL ) {
struct V_1 * V_2 ;
V_226 -> V_187 = V_224 -> V_186 ;
V_2 = F_139 ( V_59 , V_224 -> V_230 . V_201 ) ;
( void ) F_154 ( V_96 , V_224 , V_2 ) ;
if ( V_2 )
F_131 ( V_2 , V_224 -> V_230 . V_204 . V_203 ) ;
F_155 ( sizeof( * V_224 ) , & V_96 -> V_237 ) ;
F_9 ( V_224 , V_11 ) ;
}
F_171 () ;
}
int F_172 ( struct V_1 * V_2 , T_1 V_281 , T_1 V_282 , V_85 V_283 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_179 ;
struct V_27 * V_28 ;
int V_206 = 0 ;
V_179 = F_168 ( V_2 -> V_179 ) ;
if ( V_179 ) {
T_2 V_180 = F_101 ( ( V_177 T_2 ) V_281 , V_178 ) ;
for ( V_8 = F_168 ( V_179 [ V_180 ] ) ;
V_8 != NULL ;
V_8 = F_168 ( V_8 -> V_181 ) ) {
if ( V_8 -> V_107 == V_281 )
break;
}
} else {
F_59 (in_dev, im) {
if ( V_8 -> V_107 == V_281 )
break;
}
}
if ( V_8 && V_283 == V_71 ) {
V_206 = 1 ;
} else if ( V_8 ) {
if ( V_282 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_120 == V_282 )
break;
}
if ( V_28 )
V_206 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_206 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_206 = 1 ;
}
return V_206 ;
}
static inline struct V_7 * F_173 ( struct V_284 * V_285 )
{
struct V_59 * V_59 = F_174 ( V_285 ) ;
struct V_7 * V_8 = NULL ;
struct V_286 * V_287 = F_175 ( V_285 ) ;
V_287 -> V_2 = NULL ;
F_176 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_81 ( V_287 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_168 ( V_2 -> V_187 ) ;
if ( V_8 ) {
V_287 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_177 ( struct V_284 * V_285 , struct V_7 * V_8 )
{
struct V_286 * V_287 = F_175 ( V_285 ) ;
V_8 = F_168 ( V_8 -> V_186 ) ;
while ( ! V_8 ) {
V_287 -> V_50 = F_178 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_50 ) {
V_287 -> V_2 = NULL ;
break;
}
V_287 -> V_2 = F_81 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_2 )
continue;
V_8 = F_168 ( V_287 -> V_2 -> V_187 ) ;
}
return V_8 ;
}
static struct V_7 * F_179 ( struct V_284 * V_285 , T_6 V_288 )
{
struct V_7 * V_8 = F_173 ( V_285 ) ;
if ( V_8 )
while ( V_288 && ( V_8 = F_177 ( V_285 , V_8 ) ) != NULL )
-- V_288 ;
return V_288 ? NULL : V_8 ;
}
static void * F_180 ( struct V_284 * V_285 , T_6 * V_288 )
__acquires( V_11 )
{
F_58 () ;
return * V_288 ? F_179 ( V_285 , * V_288 - 1 ) : V_289 ;
}
static void * F_181 ( struct V_284 * V_285 , void * V_290 , T_6 * V_288 )
{
struct V_7 * V_8 ;
if ( V_290 == V_289 )
V_8 = F_173 ( V_285 ) ;
else
V_8 = F_177 ( V_285 , V_290 ) ;
++ * V_288 ;
return V_8 ;
}
static void F_182 ( struct V_284 * V_285 , void * V_290 )
__releases( V_11 )
{
struct V_286 * V_287 = F_175 ( V_285 ) ;
V_287 -> V_2 = NULL ;
V_287 -> V_50 = NULL ;
F_60 () ;
}
static int F_183 ( struct V_284 * V_285 , void * V_290 )
{
if ( V_290 == V_289 )
F_184 ( V_285 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_290 ;
struct V_286 * V_287 = F_175 ( V_285 ) ;
char * V_291 ;
long V_210 ;
#ifdef F_98
V_291 = F_2 ( V_287 -> V_2 ) ? L_2 :
F_3 ( V_287 -> V_2 ) ? L_3 :
L_4 ;
#else
V_291 = L_5 ;
#endif
if ( F_185 ( V_287 -> V_2 -> V_187 ) == V_8 ) {
F_186 ( V_285 , L_6 ,
V_287 -> V_50 -> V_72 , V_287 -> V_50 -> V_292 , V_287 -> V_2 -> V_182 , V_291 ) ;
}
V_210 = V_8 -> V_13 . V_25 - V_19 ;
F_186 ( V_285 ,
L_7 ,
V_8 -> V_107 , V_8 -> V_184 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_187 ( V_210 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_188 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_189 ( V_293 , V_294 , & V_295 ,
sizeof( struct V_286 ) ) ;
}
static inline struct V_27 * F_190 ( struct V_284 * V_285 )
{
struct V_59 * V_59 = F_174 ( V_285 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_296 * V_287 = F_191 ( V_285 ) ;
V_287 -> V_200 = NULL ;
V_287 -> V_8 = NULL ;
F_176 (net, state->dev) {
struct V_1 * V_200 ;
V_200 = F_81 ( V_287 -> V_50 ) ;
if ( F_118 ( ! V_200 ) )
continue;
V_8 = F_168 ( V_200 -> V_187 ) ;
if ( F_192 ( V_8 ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_192 ( V_28 ) ) {
V_287 -> V_8 = V_8 ;
V_287 -> V_200 = V_200 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_193 ( struct V_284 * V_285 , struct V_27 * V_28 )
{
struct V_296 * V_287 = F_191 ( V_285 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_287 -> V_8 -> V_12 ) ;
V_287 -> V_8 = V_287 -> V_8 -> V_128 ;
while ( ! V_287 -> V_8 ) {
V_287 -> V_50 = F_178 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_50 ) {
V_287 -> V_200 = NULL ;
goto V_185;
}
V_287 -> V_200 = F_81 ( V_287 -> V_50 ) ;
if ( ! V_287 -> V_200 )
continue;
V_287 -> V_8 = F_168 ( V_287 -> V_200 -> V_187 ) ;
}
if ( ! V_287 -> V_8 )
break;
F_11 ( & V_287 -> V_8 -> V_12 ) ;
V_28 = V_287 -> V_8 -> V_46 ;
}
V_185:
return V_28 ;
}
static struct V_27 * F_194 ( struct V_284 * V_285 , T_6 V_288 )
{
struct V_27 * V_28 = F_190 ( V_285 ) ;
if ( V_28 )
while ( V_288 && ( V_28 = F_193 ( V_285 , V_28 ) ) != NULL )
-- V_288 ;
return V_288 ? NULL : V_28 ;
}
static void * F_195 ( struct V_284 * V_285 , T_6 * V_288 )
__acquires( V_11 )
{
F_58 () ;
return * V_288 ? F_194 ( V_285 , * V_288 - 1 ) : V_289 ;
}
static void * F_196 ( struct V_284 * V_285 , void * V_290 , T_6 * V_288 )
{
struct V_27 * V_28 ;
if ( V_290 == V_289 )
V_28 = F_190 ( V_285 ) ;
else
V_28 = F_193 ( V_285 , V_290 ) ;
++ * V_288 ;
return V_28 ;
}
static void F_197 ( struct V_284 * V_285 , void * V_290 )
__releases( V_11 )
{
struct V_296 * V_287 = F_191 ( V_285 ) ;
if ( F_192 ( V_287 -> V_8 ) ) {
F_14 ( & V_287 -> V_8 -> V_12 ) ;
V_287 -> V_8 = NULL ;
}
V_287 -> V_200 = NULL ;
V_287 -> V_50 = NULL ;
F_60 () ;
}
static int F_198 ( struct V_284 * V_285 , void * V_290 )
{
struct V_27 * V_28 = (struct V_27 * ) V_290 ;
struct V_296 * V_287 = F_191 ( V_285 ) ;
if ( V_290 == V_289 ) {
F_184 ( V_285 , L_8 ) ;
} else {
F_186 ( V_285 ,
L_9
L_10 ,
V_287 -> V_50 -> V_72 , V_287 -> V_50 -> V_292 ,
F_199 ( V_287 -> V_8 -> V_107 ) ,
F_199 ( V_28 -> V_120 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_200 ( struct V_293 * V_293 , struct V_294 * V_294 )
{
return F_189 ( V_293 , V_294 , & V_297 ,
sizeof( struct V_296 ) ) ;
}
static int T_7 F_201 ( struct V_59 * V_59 )
{
struct V_298 * V_299 ;
int V_196 ;
V_299 = F_202 ( L_11 , V_300 , V_59 -> V_301 , & V_302 ) ;
if ( ! V_299 )
goto V_303;
V_299 = F_202 ( L_12 , V_300 , V_59 -> V_301 ,
& V_304 ) ;
if ( ! V_299 )
goto V_305;
V_196 = F_203 ( & V_59 -> V_306 . V_307 , V_268 ,
V_308 , 0 , V_59 ) ;
if ( V_196 < 0 ) {
F_204 ( L_13 ,
V_196 ) ;
goto V_309;
}
return 0 ;
V_309:
F_205 ( L_12 , V_59 -> V_301 ) ;
V_305:
F_205 ( L_11 , V_59 -> V_301 ) ;
V_303:
return - V_310 ;
}
static void T_8 F_206 ( struct V_59 * V_59 )
{
F_205 ( L_12 , V_59 -> V_301 ) ;
F_205 ( L_11 , V_59 -> V_301 ) ;
F_207 ( V_59 -> V_306 . V_307 ) ;
}
static int F_208 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_314 )
{
struct V_49 * V_50 = F_209 ( V_314 ) ;
struct V_1 * V_2 ;
switch ( V_313 ) {
case V_315 :
V_2 = F_142 ( V_50 ) ;
if ( V_2 )
F_130 ( V_2 ) ;
break;
default:
break;
}
return V_316 ;
}
int T_9 F_210 ( void )
{
#if F_211 ( V_317 )
int V_196 ;
V_196 = F_212 ( & V_318 ) ;
if ( V_196 )
return V_196 ;
V_196 = F_213 ( & V_319 ) ;
if ( V_196 )
goto V_320;
return 0 ;
V_320:
F_214 ( & V_318 ) ;
return V_196 ;
#else
return F_213 ( & V_319 ) ;
#endif
}
