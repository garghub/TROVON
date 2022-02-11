static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) ) {
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 , V_5 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_6 ) ;
if ( F_7 ( & V_2 -> V_7 ) )
F_8 ( & V_2 -> V_3 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_9 ( & V_2 -> V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_11 )
{
int V_12 = F_11 () % V_11 ;
V_2 -> V_8 = 1 ;
if ( ! F_12 ( & V_2 -> V_7 , V_13 + V_12 + 2 ) )
F_13 ( & V_2 -> V_3 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
int V_12 = F_11 () % V_15 -> V_16 ;
V_15 -> V_17 = 1 ;
if ( ! F_12 ( & V_15 -> V_18 , V_13 + V_12 + 2 ) )
F_15 ( V_15 ) ;
}
static void F_16 ( struct V_14 * V_15 , int V_19 )
{
int V_12 = F_11 () % V_19 ;
if ( ! F_12 ( & V_15 -> V_20 , V_13 + V_12 + 2 ) )
F_15 ( V_15 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_11 )
{
F_6 ( & V_2 -> V_6 ) ;
V_2 -> V_10 = 0 ;
if ( F_7 ( & V_2 -> V_7 ) ) {
if ( ( long ) ( V_2 -> V_7 . V_21 - V_13 ) < V_11 ) {
F_18 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = 1 ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
F_8 ( & V_2 -> V_3 ) ;
}
F_10 ( V_2 , V_11 ) ;
F_9 ( & V_2 -> V_6 ) ;
}
static int F_19 ( struct V_1 * V_22 , struct V_23 * V_24 , int type ,
int V_25 , int V_26 )
{
switch ( type ) {
case V_27 :
case V_28 :
if ( V_25 || V_26 )
return 0 ;
if ( ! ( V_22 -> V_29 && ! V_24 -> V_30 ) ) {
if ( V_22 -> V_31 == V_32 )
return 1 ;
if ( V_24 -> V_33 [ V_32 ] )
return type == V_27 ;
return V_22 -> V_34 [ V_35 ] ==
V_24 -> V_33 [ V_35 ] ;
}
return 0 ;
case V_36 :
if ( V_25 || V_26 )
return 0 ;
return V_24 -> V_33 [ V_32 ] != 0 ;
case V_37 :
if ( V_25 || V_26 )
return 0 ;
if ( V_22 -> V_34 [ V_35 ] == 0 ||
V_24 -> V_33 [ V_32 ] )
return 0 ;
return V_22 -> V_34 [ V_35 ] ==
V_24 -> V_33 [ V_35 ] ;
case V_38 :
if ( V_25 || ! V_24 -> V_39 )
return 0 ;
return ( V_22 -> V_31 == V_32 ) ^ V_26 ;
case V_40 :
if ( V_22 -> V_31 == V_32 )
return V_25 || ( V_24 -> V_39 && V_26 ) ;
return V_24 -> V_39 && ! V_25 && ! V_26 ;
}
return 0 ;
}
static int
F_20 ( struct V_1 * V_22 , int type , int V_25 , int V_26 )
{
struct V_23 * V_24 ;
int V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) )
continue;
V_41 ++ ;
}
return V_41 ;
}
static struct V_44 * F_21 ( struct V_45 * V_46 , int V_47 )
{
struct V_44 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
struct V_56 V_57 ;
int V_58 = F_23 ( V_46 ) ;
int V_59 = V_46 -> V_60 ;
while ( 1 ) {
V_48 = F_24 ( V_47 + V_58 + V_59 ,
V_61 | V_62 ) ;
if ( V_48 )
break;
V_47 >>= 1 ;
if ( V_47 < 256 )
return NULL ;
}
F_25 ( V_48 ) = V_47 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_63 , 0 ,
0 , 0 ,
V_64 , 0 , V_46 -> V_65 ) ;
if ( F_27 ( V_50 ) ) {
F_28 ( V_48 ) ;
return NULL ;
}
F_29 ( V_48 , & V_50 -> V_66 ) ;
V_48 -> V_46 = V_46 ;
F_30 ( V_48 , V_58 ) ;
F_31 ( V_48 ) ;
V_52 = F_32 ( V_48 ) ;
F_33 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_52 -> V_67 = 4 ;
V_52 -> V_68 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_52 -> V_69 = 0xc0 ;
V_52 -> V_70 = F_34 ( V_71 ) ;
V_52 -> V_72 = 1 ;
V_52 -> V_73 = V_57 . V_73 ;
V_52 -> V_74 = V_57 . V_74 ;
V_52 -> V_75 = V_64 ;
V_52 -> V_76 = 0 ;
F_35 ( V_52 , & V_50 -> V_66 , NULL ) ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 0 ] = V_78 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 1 ] = 4 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 2 ] = 0 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 3 ] = 0 ;
V_48 -> V_79 = V_48 -> V_80 + sizeof( struct V_51 ) + 4 ;
F_33 ( V_48 , sizeof( * V_54 ) ) ;
V_54 = F_36 ( V_48 ) ;
V_54 -> type = V_81 ;
V_54 -> V_82 = 0 ;
V_54 -> V_83 = 0 ;
V_54 -> V_84 = 0 ;
V_54 -> V_85 = 0 ;
return V_48 ;
}
static int F_37 ( struct V_44 * V_48 )
{
struct V_86 * V_54 = F_38 ( V_48 ) ;
const int V_87 = F_39 ( V_48 ) - F_40 ( V_48 ) ;
V_54 -> V_83 = F_41 ( F_38 ( V_48 ) , V_87 ) ;
return F_42 ( V_48 ) ;
}
static int F_43 ( struct V_1 * V_22 , int type , int V_88 , int V_89 )
{
return sizeof( struct V_90 ) + 4 * F_20 ( V_22 , type , V_88 , V_89 ) ;
}
static struct V_44 * F_44 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , struct V_90 * * V_91 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_92 ;
struct V_90 * V_93 ;
if ( ! V_48 )
V_48 = F_21 ( V_46 , V_46 -> V_94 ) ;
if ( ! V_48 )
return NULL ;
V_93 = (struct V_90 * ) F_33 ( V_48 , sizeof( struct V_90 ) ) ;
V_93 -> V_95 = type ;
V_93 -> V_96 = 0 ;
V_93 -> V_97 = 0 ;
V_93 -> V_98 = V_22 -> V_99 ;
V_92 = F_36 ( V_48 ) ;
V_92 -> V_85 = F_34 ( F_45 ( V_92 -> V_85 ) + 1 ) ;
* V_91 = V_93 ;
return V_48 ;
}
static struct V_44 * F_46 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , int V_25 , int V_26 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_92 ;
struct V_90 * V_93 = NULL ;
struct V_23 * V_24 , * V_100 , * V_101 , * * V_102 ;
int V_41 , V_103 , V_104 , V_105 , V_106 ;
if ( V_22 -> V_99 == V_107 )
return V_48 ;
V_105 = type == V_27 ||
type == V_28 ;
V_106 = type == V_28 ||
type == V_37 ;
V_103 = V_41 = 0 ;
V_102 = V_26 ? & V_22 -> V_108 : & V_22 -> V_42 ;
if ( ! * V_102 )
goto V_109;
V_92 = V_48 ? F_36 ( V_48 ) : NULL ;
if ( V_106 ) {
if ( V_92 && V_92 -> V_85 &&
F_47 ( V_48 ) < F_43 ( V_22 , type , V_25 , V_26 ) ) {
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_94 ) ;
}
}
V_104 = 1 ;
V_101 = NULL ;
for ( V_24 = * V_102 ; V_24 ; V_24 = V_100 ) {
T_1 * V_110 ;
V_100 = V_24 -> V_43 ;
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) ) {
V_101 = V_24 ;
continue;
}
if ( V_105 )
V_24 -> V_30 = 0 ;
if ( F_47 ( V_48 ) < sizeof( T_1 ) +
V_104 * sizeof( struct V_90 ) ) {
if ( V_106 && ! V_104 )
break;
if ( V_93 )
V_93 -> V_97 = F_34 ( V_41 ) ;
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_94 ) ;
V_104 = 1 ;
V_41 = 0 ;
}
if ( V_104 ) {
V_48 = F_44 ( V_48 , V_22 , type , & V_93 ) ;
V_104 = 0 ;
}
if ( ! V_48 )
return NULL ;
V_110 = ( T_1 * ) F_33 ( V_48 , sizeof( T_1 ) ) ;
* V_110 = V_24 -> V_111 ;
V_41 ++ ; V_103 ++ ;
if ( ( type == V_38 ||
type == V_40 ) && V_24 -> V_39 ) {
V_24 -> V_39 -- ;
if ( ( V_26 || V_25 ) && V_24 -> V_39 == 0 ) {
if ( V_101 )
V_101 -> V_43 = V_24 -> V_43 ;
else
* V_102 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
continue;
}
}
V_101 = V_24 ;
}
V_109:
if ( ! V_103 ) {
if ( type == V_38 ||
type == V_40 )
return V_48 ;
if ( V_22 -> V_112 || V_105 ) {
if ( V_48 && F_47 ( V_48 ) < sizeof( struct V_90 ) ) {
F_37 ( V_48 ) ;
V_48 = NULL ;
}
V_48 = F_44 ( V_48 , V_22 , type , & V_93 ) ;
}
}
if ( V_93 )
V_93 -> V_97 = F_34 ( V_41 ) ;
if ( V_105 )
V_22 -> V_29 = 0 ;
return V_48 ;
}
static int F_49 ( struct V_14 * V_15 , struct V_1 * V_22 )
{
struct V_44 * V_48 = NULL ;
int type ;
if ( ! V_22 ) {
F_50 () ;
F_51 (in_dev, pmc) {
if ( V_22 -> V_99 == V_107 )
continue;
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_46 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
F_52 () ;
} else {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_46 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
if ( ! V_48 )
return 0 ;
return F_37 ( V_48 ) ;
}
static void F_53 ( struct V_23 * * V_113 )
{
struct V_23 * V_101 , * V_100 , * V_24 ;
V_101 = NULL ;
for ( V_24 = * V_113 ; V_24 ; V_24 = V_100 ) {
V_100 = V_24 -> V_43 ;
if ( V_24 -> V_39 == 0 ) {
if ( V_101 )
V_101 -> V_43 = V_24 -> V_43 ;
else
* V_113 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
} else
V_101 = V_24 ;
}
}
static void F_54 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_114 , * V_115 ;
struct V_44 * V_48 = NULL ;
int type , V_116 ;
F_50 () ;
F_6 ( & V_15 -> V_117 ) ;
V_114 = NULL ;
for ( V_22 = V_15 -> V_118 ; V_22 ; V_22 = V_115 ) {
V_115 = V_22 -> V_119 ;
if ( V_22 -> V_31 == V_32 ) {
type = V_40 ;
V_116 = V_40 ;
V_48 = F_46 ( V_48 , V_22 , type , 1 , 0 ) ;
V_48 = F_46 ( V_48 , V_22 , V_116 , 1 , 1 ) ;
}
if ( V_22 -> V_112 ) {
if ( V_22 -> V_31 == V_35 ) {
type = V_36 ;
V_48 = F_46 ( V_48 , V_22 , type , 1 , 0 ) ;
}
V_22 -> V_112 -- ;
if ( V_22 -> V_112 == 0 ) {
F_53 ( & V_22 -> V_108 ) ;
F_53 ( & V_22 -> V_42 ) ;
}
}
if ( V_22 -> V_112 == 0 && ! V_22 -> V_108 && ! V_22 -> V_42 ) {
if ( V_114 )
V_114 -> V_119 = V_115 ;
else
V_15 -> V_118 = V_115 ;
F_3 ( V_22 -> V_4 ) ;
F_48 ( V_22 ) ;
} else
V_114 = V_22 ;
}
F_9 ( & V_15 -> V_117 ) ;
F_51 (in_dev, pmc) {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] ) {
type = V_40 ;
V_116 = V_38 ;
} else {
type = V_38 ;
V_116 = V_40 ;
}
V_48 = F_46 ( V_48 , V_22 , type , 0 , 0 ) ;
V_48 = F_46 ( V_48 , V_22 , V_116 , 0 , 1 ) ;
if ( V_22 -> V_112 ) {
if ( V_22 -> V_31 == V_35 )
type = V_37 ;
else
type = V_36 ;
V_48 = F_46 ( V_48 , V_22 , type , 0 , 0 ) ;
V_22 -> V_112 -- ;
}
F_9 ( & V_22 -> V_6 ) ;
}
F_52 () ;
if ( ! V_48 )
return;
( void ) F_37 ( V_48 ) ;
}
static int F_55 ( struct V_14 * V_15 , struct V_1 * V_22 ,
int type )
{
struct V_44 * V_48 ;
struct V_51 * V_120 ;
struct V_86 * V_121 ;
struct V_49 * V_50 ;
struct V_45 * V_46 = V_15 -> V_46 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
T_1 V_122 = V_22 ? V_22 -> V_99 : 0 ;
struct V_56 V_57 ;
T_1 V_66 ;
int V_58 , V_59 ;
if ( type == V_81 )
return F_49 ( V_15 , V_22 ) ;
else if ( type == V_123 )
V_66 = V_124 ;
else
V_66 = V_122 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_66 , 0 ,
0 , 0 ,
V_64 , 0 , V_46 -> V_65 ) ;
if ( F_27 ( V_50 ) )
return - 1 ;
V_58 = F_23 ( V_46 ) ;
V_59 = V_46 -> V_60 ;
V_48 = F_24 ( V_125 + V_58 + V_59 , V_61 ) ;
if ( V_48 == NULL ) {
F_56 ( V_50 ) ;
return - 1 ;
}
F_29 ( V_48 , & V_50 -> V_66 ) ;
F_30 ( V_48 , V_58 ) ;
F_31 ( V_48 ) ;
V_120 = F_32 ( V_48 ) ;
F_33 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_120 -> V_67 = 4 ;
V_120 -> V_68 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_120 -> V_69 = 0xc0 ;
V_120 -> V_70 = F_34 ( V_71 ) ;
V_120 -> V_72 = 1 ;
V_120 -> V_73 = V_66 ;
V_120 -> V_74 = V_57 . V_74 ;
V_120 -> V_75 = V_64 ;
F_35 ( V_120 , & V_50 -> V_66 , NULL ) ;
( ( V_77 * ) & V_120 [ 1 ] ) [ 0 ] = V_78 ;
( ( V_77 * ) & V_120 [ 1 ] ) [ 1 ] = 4 ;
( ( V_77 * ) & V_120 [ 1 ] ) [ 2 ] = 0 ;
( ( V_77 * ) & V_120 [ 1 ] ) [ 3 ] = 0 ;
V_121 = (struct V_86 * ) F_33 ( V_48 , sizeof( struct V_86 ) ) ;
V_121 -> type = type ;
V_121 -> V_126 = 0 ;
V_121 -> V_83 = 0 ;
V_121 -> V_122 = V_122 ;
V_121 -> V_83 = F_41 ( ( void * ) V_121 , sizeof( struct V_86 ) ) ;
return F_42 ( V_48 ) ;
}
static void F_57 ( unsigned long V_127 )
{
struct V_14 * V_15 = (struct V_14 * ) V_127 ;
V_15 -> V_17 = 0 ;
F_49 ( V_15 , NULL ) ;
F_58 ( V_15 ) ;
}
static void F_59 ( unsigned long V_127 )
{
struct V_14 * V_15 = (struct V_14 * ) V_127 ;
F_54 ( V_15 ) ;
if ( V_15 -> V_128 ) {
V_15 -> V_128 -- ;
F_16 ( V_15 , V_129 ) ;
}
F_58 ( V_15 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
if ( F_61 ( V_15 ) || F_62 ( V_15 ) )
return;
V_15 -> V_128 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
F_16 ( V_15 , 1 ) ;
}
static void F_63 ( unsigned long V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
struct V_14 * V_15 = V_2 -> V_4 ;
F_64 ( & V_2 -> V_6 ) ;
V_2 -> V_8 = 0 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 -- ;
F_10 ( V_2 , V_129 ) ;
}
V_2 -> V_9 = 1 ;
F_65 ( & V_2 -> V_6 ) ;
if ( F_61 ( V_15 ) )
F_55 ( V_15 , V_2 , V_132 ) ;
else if ( F_62 ( V_15 ) )
F_55 ( V_15 , V_2 , V_133 ) ;
else
F_55 ( V_15 , V_2 , V_81 ) ;
F_1 ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_22 , int V_134 , T_1 * V_135 )
{
struct V_23 * V_24 ;
int V_136 , V_41 ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_134 )
break;
for ( V_136 = 0 ; V_136 < V_134 ; V_136 ++ ) {
if ( V_24 -> V_33 [ V_32 ] ||
V_22 -> V_34 [ V_35 ] !=
V_24 -> V_33 [ V_35 ] )
break;
if ( V_135 [ V_136 ] == V_24 -> V_111 ) {
V_41 ++ ;
break;
}
}
}
V_22 -> V_29 = 0 ;
if ( V_41 == V_134 )
return 0 ;
return 1 ;
}
static int F_67 ( struct V_1 * V_22 , int V_134 , T_1 * V_135 )
{
struct V_23 * V_24 ;
int V_136 , V_41 ;
if ( V_22 -> V_31 == V_35 )
return F_66 ( V_22 , V_134 , V_135 ) ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_134 )
break;
for ( V_136 = 0 ; V_136 < V_134 ; V_136 ++ )
if ( V_135 [ V_136 ] == V_24 -> V_111 ) {
V_24 -> V_30 = 1 ;
V_41 ++ ;
break;
}
}
if ( ! V_41 ) {
V_22 -> V_29 = 0 ;
return 0 ;
}
V_22 -> V_29 = 1 ;
return 1 ;
}
static bool F_68 ( struct V_14 * V_15 , T_1 V_122 )
{
struct V_1 * V_2 ;
if ( V_122 == V_107 )
return false ;
F_50 () ;
F_51 (in_dev, im) {
if ( V_2 -> V_99 == V_122 ) {
F_5 ( V_2 ) ;
break;
}
}
F_52 () ;
return false ;
}
static bool F_69 ( struct V_14 * V_15 , struct V_44 * V_48 ,
int V_137 )
{
struct V_86 * V_121 = F_38 ( V_48 ) ;
struct V_138 * V_139 = F_70 ( V_48 ) ;
struct V_1 * V_2 ;
T_1 V_122 = V_121 -> V_122 ;
int V_11 ;
int V_140 = 0 ;
if ( V_137 == 8 ) {
if ( V_121 -> V_126 == 0 ) {
V_11 = V_141 ;
V_15 -> V_142 = V_13 +
V_143 ;
V_122 = 0 ;
} else {
V_11 = V_121 -> V_126 * ( V_144 / V_145 ) ;
V_15 -> V_146 = V_13 +
V_147 ;
}
V_15 -> V_128 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_58 ( V_15 ) ;
F_71 ( V_15 ) ;
} else if ( V_137 < 12 ) {
return true ;
} else if ( F_61 ( V_15 ) ) {
V_11 = V_141 ;
V_122 = 0 ;
} else if ( F_62 ( V_15 ) ) {
V_11 = F_72 ( V_139 -> V_126 ) * ( V_144 / V_145 ) ;
if ( ! V_11 )
V_11 = 1 ;
} else {
if ( ! F_73 ( V_48 , sizeof( struct V_138 ) ) )
return true ;
V_139 = F_70 ( V_48 ) ;
if ( V_139 -> V_134 ) {
if ( ! F_73 ( V_48 , sizeof( struct V_138 )
+ F_45 ( V_139 -> V_134 ) * sizeof( T_1 ) ) )
return true ;
V_139 = F_70 ( V_48 ) ;
}
V_11 = F_72 ( V_139 -> V_126 ) * ( V_144 / V_145 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_15 -> V_16 = V_11 ;
if ( V_139 -> V_148 )
V_15 -> V_130 = V_139 -> V_148 ;
if ( ! V_122 ) {
if ( V_139 -> V_134 )
return false ;
F_14 ( V_15 ) ;
return false ;
}
V_140 = V_139 -> V_134 != 0 ;
}
F_50 () ;
F_51 (in_dev, im) {
int V_149 ;
if ( V_122 && V_122 != V_2 -> V_99 )
continue;
if ( V_2 -> V_99 == V_107 )
continue;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_2 -> V_29 = V_2 -> V_29 && V_140 ;
else
V_2 -> V_29 = V_140 ;
V_149 = ! V_2 -> V_29 ||
F_67 ( V_2 , F_45 ( V_139 -> V_134 ) , V_139 -> V_135 ) ;
F_9 ( & V_2 -> V_6 ) ;
if ( V_149 )
F_17 ( V_2 , V_11 ) ;
}
F_52 () ;
return false ;
}
int F_74 ( struct V_44 * V_48 )
{
struct V_86 * V_121 ;
struct V_14 * V_15 = F_75 ( V_48 -> V_46 ) ;
int V_137 = V_48 -> V_137 ;
bool V_150 = true ;
if ( V_15 == NULL )
goto V_151;
if ( ! F_73 ( V_48 , sizeof( struct V_86 ) ) )
goto V_151;
switch ( V_48 -> V_152 ) {
case V_153 :
if ( ! F_76 ( V_48 -> V_83 ) )
break;
case V_154 :
V_48 -> V_83 = 0 ;
if ( F_77 ( V_48 ) )
goto V_151;
}
V_121 = F_38 ( V_48 ) ;
switch ( V_121 -> type ) {
case V_155 :
V_150 = F_69 ( V_15 , V_48 , V_137 ) ;
break;
case V_132 :
case V_133 :
if ( F_78 ( F_79 ( V_48 ) ) )
break;
if ( V_48 -> V_156 == V_157 ||
V_48 -> V_156 == V_158 )
V_150 = F_68 ( V_15 , V_121 -> V_122 ) ;
break;
case V_159 :
#ifdef F_80
return F_81 ( V_48 ) ;
#endif
case V_81 :
case V_160 :
case V_161 :
case V_123 :
case V_162 :
case V_163 :
break;
default:
break;
}
V_151:
if ( V_150 )
F_28 ( V_48 ) ;
else
F_82 ( V_48 ) ;
return 0 ;
}
static void F_83 ( struct V_14 * V_15 , T_1 V_164 )
{
char V_165 [ V_166 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_84 ( V_164 , V_165 , V_46 , 0 ) == 0 )
F_85 ( V_46 , V_165 ) ;
}
static void F_86 ( struct V_14 * V_15 , T_1 V_164 )
{
char V_165 [ V_166 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_84 ( V_164 , V_165 , V_46 , 0 ) == 0 )
F_87 ( V_46 , V_165 ) ;
}
static void F_88 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_1 * V_22 ;
V_22 = F_89 ( sizeof( * V_22 ) , V_167 ) ;
if ( ! V_22 )
return;
F_6 ( & V_2 -> V_6 ) ;
V_22 -> V_4 = V_2 -> V_4 ;
F_15 ( V_15 ) ;
V_22 -> V_99 = V_2 -> V_99 ;
V_22 -> V_112 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
V_22 -> V_31 = V_2 -> V_31 ;
if ( V_22 -> V_31 == V_32 ) {
struct V_23 * V_24 ;
V_22 -> V_108 = V_2 -> V_108 ;
V_22 -> V_42 = V_2 -> V_42 ;
V_2 -> V_108 = V_2 -> V_42 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = V_22 -> V_112 ;
}
F_9 ( & V_2 -> V_6 ) ;
F_6 ( & V_15 -> V_117 ) ;
V_22 -> V_119 = V_15 -> V_118 ;
V_15 -> V_118 = V_22 ;
F_9 ( & V_15 -> V_117 ) ;
}
static void F_90 ( struct V_14 * V_15 , T_1 V_99 )
{
struct V_1 * V_22 , * V_114 ;
struct V_23 * V_24 , * V_100 ;
F_6 ( & V_15 -> V_117 ) ;
V_114 = NULL ;
for ( V_22 = V_15 -> V_118 ; V_22 ; V_22 = V_22 -> V_119 ) {
if ( V_22 -> V_99 == V_99 )
break;
V_114 = V_22 ;
}
if ( V_22 ) {
if ( V_114 )
V_114 -> V_119 = V_22 -> V_119 ;
else
V_15 -> V_118 = V_22 -> V_119 ;
}
F_9 ( & V_15 -> V_117 ) ;
if ( V_22 ) {
for ( V_24 = V_22 -> V_108 ; V_24 ; V_24 = V_100 ) {
V_100 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
}
F_3 ( V_22 -> V_4 ) ;
F_48 ( V_22 ) ;
}
}
static void F_71 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_168 ;
F_6 ( & V_15 -> V_117 ) ;
V_22 = V_15 -> V_118 ;
V_15 -> V_118 = NULL ;
F_9 ( & V_15 -> V_117 ) ;
for (; V_22 ; V_22 = V_168 ) {
V_168 = V_22 -> V_119 ;
F_91 ( V_22 ) ;
F_3 ( V_22 -> V_4 ) ;
F_48 ( V_22 ) ;
}
F_50 () ;
F_51 (in_dev, pmc) {
struct V_23 * V_24 , * V_100 ;
F_6 ( & V_22 -> V_6 ) ;
V_24 = V_22 -> V_108 ;
V_22 -> V_108 = NULL ;
F_9 ( & V_22 -> V_6 ) ;
for (; V_24 ; V_24 = V_100 ) {
V_100 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
}
}
F_52 () ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
#ifdef F_93
int V_9 ;
#endif
if ( V_2 -> V_169 ) {
V_2 -> V_169 = 0 ;
F_86 ( V_15 , V_2 -> V_99 ) ;
}
#ifdef F_93
if ( V_2 -> V_99 == V_107 )
return;
V_9 = V_2 -> V_9 ;
F_5 ( V_2 ) ;
if ( ! V_15 -> V_170 ) {
if ( F_61 ( V_15 ) )
return;
if ( F_62 ( V_15 ) ) {
if ( V_9 )
F_55 ( V_15 , V_2 , V_123 ) ;
return;
}
F_88 ( V_15 , V_2 ) ;
F_60 ( V_15 ) ;
}
#endif
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
if ( V_2 -> V_169 == 0 ) {
V_2 -> V_169 = 1 ;
F_83 ( V_15 , V_2 -> V_99 ) ;
}
#ifdef F_93
if ( V_2 -> V_99 == V_107 )
return;
if ( V_15 -> V_170 )
return;
if ( F_61 ( V_15 ) || F_62 ( V_15 ) ) {
F_6 ( & V_2 -> V_6 ) ;
F_10 ( V_2 , V_171 ) ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
V_2 -> V_112 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
F_60 ( V_15 ) ;
#endif
}
static T_2 F_95 ( const struct V_1 * V_2 )
{
return F_96 ( ( V_172 T_2 ) V_2 -> V_99 , V_173 ) ;
}
static void F_97 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_1 T_3 * * V_174 ;
T_2 V_175 ;
V_174 = F_98 ( V_15 -> V_174 ) ;
if ( V_174 ) {
V_175 = F_95 ( V_2 ) ;
V_2 -> V_176 = V_174 [ V_175 ] ;
F_99 ( V_174 [ V_175 ] , V_2 ) ;
return;
}
if ( V_15 -> V_177 < 4 )
return;
V_174 = F_89 ( sizeof( struct V_1 * ) << V_173 ,
V_167 ) ;
if ( ! V_174 )
return;
F_100 (in_dev, im) {
V_175 = F_95 ( V_2 ) ;
V_2 -> V_176 = V_174 [ V_175 ] ;
F_101 ( V_174 [ V_175 ] , V_2 ) ;
}
F_99 ( V_15 -> V_174 , V_174 ) ;
}
static void F_102 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_1 T_3 * * V_174 = F_98 ( V_15 -> V_174 ) ;
struct V_1 * V_178 ;
if ( ! V_174 )
return;
V_174 += F_95 ( V_2 ) ;
while ( ( V_178 = F_98 ( * V_174 ) ) != V_2 )
V_174 = & V_178 -> V_176 ;
* V_174 = V_2 -> V_176 ;
}
void F_103 ( struct V_14 * V_15 , T_1 V_164 )
{
struct V_1 * V_2 ;
F_104 () ;
F_100 (in_dev, im) {
if ( V_2 -> V_99 == V_164 ) {
V_2 -> V_179 ++ ;
F_105 ( V_15 , & V_164 , V_35 , 0 , NULL , 0 ) ;
goto V_180;
}
}
V_2 = F_89 ( sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
goto V_180;
V_2 -> V_179 = 1 ;
V_2 -> V_4 = V_15 ;
F_15 ( V_15 ) ;
V_2 -> V_99 = V_164 ;
V_2 -> V_31 = V_35 ;
V_2 -> V_34 [ V_35 ] = 1 ;
F_106 ( & V_2 -> V_3 , 1 ) ;
F_107 ( & V_2 -> V_6 ) ;
#ifdef F_93
F_108 ( & V_2 -> V_7 , & F_63 , ( unsigned long ) V_2 ) ;
V_2 -> V_10 = V_131 ;
#endif
V_2 -> V_181 = V_15 -> V_182 ;
V_15 -> V_177 ++ ;
F_99 ( V_15 -> V_182 , V_2 ) ;
F_97 ( V_15 , V_2 ) ;
#ifdef F_93
F_90 ( V_15 , V_2 -> V_99 ) ;
#endif
F_94 ( V_2 ) ;
if ( ! V_15 -> V_170 )
F_109 ( V_15 ) ;
V_180:
return;
}
void F_110 ( struct V_14 * V_15 )
{
#ifdef F_93
struct V_1 * V_2 ;
int type ;
F_51 (in_dev, im) {
if ( V_2 -> V_99 == V_107 )
continue;
if ( F_61 ( V_15 ) )
type = V_132 ;
else if ( F_62 ( V_15 ) )
type = V_133 ;
else
type = V_81 ;
F_55 ( V_15 , V_2 , type ) ;
}
#endif
}
void F_111 ( struct V_14 * V_15 , T_1 V_164 )
{
struct V_1 * V_136 ;
struct V_1 T_3 * * V_183 ;
F_104 () ;
for ( V_183 = & V_15 -> V_182 ;
( V_136 = F_98 ( * V_183 ) ) != NULL ;
V_183 = & V_136 -> V_181 ) {
if ( V_136 -> V_99 == V_164 ) {
if ( -- V_136 -> V_179 == 0 ) {
F_102 ( V_15 , V_136 ) ;
* V_183 = V_136 -> V_181 ;
V_15 -> V_177 -- ;
F_92 ( V_136 ) ;
F_91 ( V_136 ) ;
if ( ! V_15 -> V_170 )
F_109 ( V_15 ) ;
F_1 ( V_136 ) ;
return;
}
break;
}
}
}
void F_112 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_104 () ;
F_100 (in_dev, pmc)
F_92 ( V_22 ) ;
}
void F_113 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_104 () ;
F_100 (in_dev, pmc)
F_94 ( V_22 ) ;
}
void F_114 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_104 () ;
F_100 (in_dev, pmc)
F_92 ( V_22 ) ;
#ifdef F_93
V_15 -> V_128 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_58 ( V_15 ) ;
V_15 -> V_17 = 0 ;
if ( F_7 ( & V_15 -> V_18 ) )
F_58 ( V_15 ) ;
F_71 ( V_15 ) ;
#endif
F_111 ( V_15 , V_107 ) ;
}
void F_115 ( struct V_14 * V_15 )
{
F_104 () ;
#ifdef F_93
F_108 ( & V_15 -> V_18 , F_57 ,
( unsigned long ) V_15 ) ;
F_108 ( & V_15 -> V_20 , F_59 ,
( unsigned long ) V_15 ) ;
V_15 -> V_130 = V_131 ;
#endif
F_107 ( & V_15 -> V_117 ) ;
}
void F_116 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_104 () ;
F_103 ( V_15 , V_107 ) ;
F_100 (in_dev, pmc)
F_94 ( V_22 ) ;
}
void F_117 ( struct V_14 * V_15 )
{
struct V_1 * V_136 ;
F_104 () ;
F_114 ( V_15 ) ;
while ( ( V_136 = F_98 ( V_15 -> V_182 ) ) != NULL ) {
V_15 -> V_182 = V_136 -> V_181 ;
V_15 -> V_177 -- ;
F_91 ( V_136 ) ;
F_1 ( V_136 ) ;
}
}
static struct V_14 * F_118 ( struct V_55 * V_55 , struct V_184 * V_185 )
{
struct V_45 * V_46 = NULL ;
struct V_14 * V_186 = NULL ;
if ( V_185 -> V_187 ) {
V_186 = F_119 ( V_55 , V_185 -> V_187 ) ;
return V_186 ;
}
if ( V_185 -> V_188 . V_189 ) {
V_46 = F_120 ( V_55 , V_185 -> V_188 . V_189 , false ) ;
if ( ! V_46 )
return NULL ;
}
if ( ! V_46 ) {
struct V_49 * V_50 = F_121 ( V_55 ,
V_185 -> V_190 . V_189 ,
0 , 0 , 0 ) ;
if ( ! F_27 ( V_50 ) ) {
V_46 = V_50 -> V_66 . V_46 ;
F_56 ( V_50 ) ;
}
}
if ( V_46 ) {
V_185 -> V_187 = V_46 -> V_65 ;
V_186 = F_122 ( V_46 ) ;
}
return V_186 ;
}
static int F_123 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_191 )
{
struct V_23 * V_24 , * V_101 ;
int V_192 = 0 ;
V_101 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_111 == * V_191 )
break;
V_101 = V_24 ;
}
if ( ! V_24 || V_24 -> V_33 [ V_31 ] == 0 ) {
return - V_193 ;
}
V_24 -> V_33 [ V_31 ] -- ;
if ( V_24 -> V_33 [ V_31 ] == 0 ) {
F_109 ( V_22 -> V_4 ) ;
}
if ( ! V_24 -> V_33 [ V_32 ] && ! V_24 -> V_33 [ V_35 ] ) {
#ifdef F_93
struct V_14 * V_15 = V_22 -> V_4 ;
#endif
if ( V_101 )
V_101 -> V_43 = V_24 -> V_43 ;
else
V_22 -> V_42 = V_24 -> V_43 ;
#ifdef F_93
if ( V_24 -> V_194 &&
! F_61 ( V_15 ) && ! F_62 ( V_15 ) ) {
V_24 -> V_39 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
V_24 -> V_43 = V_22 -> V_108 ;
V_22 -> V_108 = V_24 ;
V_192 = 1 ;
} else
#endif
F_48 ( V_24 ) ;
}
return V_192 ;
}
static int F_124 ( struct V_14 * V_15 , T_1 * V_195 , int V_31 ,
int V_34 , T_1 * V_191 , int V_196 )
{
struct V_1 * V_22 ;
int V_197 = 0 ;
int V_136 , V_198 ;
if ( ! V_15 )
return - V_199 ;
F_50 () ;
F_51 (in_dev, pmc) {
if ( * V_195 == V_22 -> V_99 )
break;
}
if ( ! V_22 ) {
F_52 () ;
return - V_193 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_52 () ;
#ifdef F_93
F_125 ( V_22 ) ;
#endif
if ( ! V_196 ) {
V_198 = - V_200 ;
if ( ! V_22 -> V_34 [ V_31 ] )
goto V_201;
V_22 -> V_34 [ V_31 ] -- ;
}
V_198 = 0 ;
for ( V_136 = 0 ; V_136 < V_34 ; V_136 ++ ) {
int V_192 = F_123 ( V_22 , V_31 , & V_191 [ V_136 ] ) ;
V_197 |= V_192 > 0 ;
if ( ! V_198 && V_192 < 0 )
V_198 = V_192 ;
}
if ( V_22 -> V_31 == V_35 &&
V_22 -> V_34 [ V_35 ] == 0 &&
V_22 -> V_34 [ V_32 ] ) {
#ifdef F_93
struct V_23 * V_24 ;
#endif
V_22 -> V_31 = V_32 ;
#ifdef F_93
V_22 -> V_112 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
V_15 -> V_128 = V_22 -> V_112 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_60 ( V_22 -> V_4 ) ;
} else if ( F_126 ( V_22 ) || V_197 ) {
F_60 ( V_22 -> V_4 ) ;
#endif
}
V_201:
F_9 ( & V_22 -> V_6 ) ;
return V_198 ;
}
static int F_127 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_191 )
{
struct V_23 * V_24 , * V_101 ;
V_101 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_111 == * V_191 )
break;
V_101 = V_24 ;
}
if ( ! V_24 ) {
V_24 = F_89 ( sizeof( * V_24 ) , V_61 ) ;
if ( ! V_24 )
return - V_202 ;
V_24 -> V_111 = * V_191 ;
if ( V_101 ) {
V_101 -> V_43 = V_24 ;
} else
V_22 -> V_42 = V_24 ;
}
V_24 -> V_33 [ V_31 ] ++ ;
if ( V_24 -> V_33 [ V_31 ] == 1 ) {
F_109 ( V_22 -> V_4 ) ;
}
return 0 ;
}
static void F_125 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
int V_203 = V_22 -> V_34 [ V_35 ] ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
if ( V_22 -> V_34 [ V_35 ] ) {
V_24 -> V_194 = V_203 ==
V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_24 -> V_194 = V_24 -> V_33 [ V_32 ] != 0 ;
}
static int F_126 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_204 ;
int V_203 = V_22 -> V_34 [ V_35 ] ;
int V_148 = V_22 -> V_4 -> V_130 ;
int V_205 , V_192 ;
V_192 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_22 -> V_34 [ V_35 ] ) {
V_205 = V_203 == V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_205 = V_24 -> V_33 [ V_32 ] != 0 ;
if ( V_205 ) {
if ( ! V_24 -> V_194 ) {
struct V_23 * V_206 = NULL ;
for ( V_204 = V_22 -> V_108 ; V_204 ; V_204 = V_204 -> V_43 ) {
if ( V_204 -> V_111 == V_24 -> V_111 )
break;
V_206 = V_204 ;
}
if ( V_204 ) {
if ( V_206 )
V_206 -> V_43 = V_204 -> V_43 ;
else
V_22 -> V_108 = V_204 -> V_43 ;
F_48 ( V_204 ) ;
}
V_24 -> V_39 = V_148 ;
V_192 ++ ;
}
} else if ( V_24 -> V_194 ) {
V_24 -> V_39 = 0 ;
for ( V_204 = V_22 -> V_108 ; V_204 ; V_204 = V_204 -> V_43 )
if ( V_204 -> V_111 == V_24 -> V_111 )
break;
if ( ! V_204 ) {
V_204 = F_128 ( sizeof( * V_204 ) , V_61 ) ;
if ( ! V_204 )
continue;
* V_204 = * V_24 ;
V_204 -> V_43 = V_22 -> V_108 ;
V_22 -> V_108 = V_204 ;
}
V_204 -> V_39 = V_148 ;
V_192 ++ ;
}
}
return V_192 ;
}
static int F_105 ( struct V_14 * V_15 , T_1 * V_195 , int V_31 ,
int V_34 , T_1 * V_191 , int V_196 )
{
struct V_1 * V_22 ;
int V_207 ;
int V_136 , V_198 ;
if ( ! V_15 )
return - V_199 ;
F_50 () ;
F_51 (in_dev, pmc) {
if ( * V_195 == V_22 -> V_99 )
break;
}
if ( ! V_22 ) {
F_52 () ;
return - V_193 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_52 () ;
#ifdef F_93
F_125 ( V_22 ) ;
#endif
V_207 = V_22 -> V_31 == V_35 ;
if ( ! V_196 )
V_22 -> V_34 [ V_31 ] ++ ;
V_198 = 0 ;
for ( V_136 = 0 ; V_136 < V_34 ; V_136 ++ ) {
V_198 = F_127 ( V_22 , V_31 , & V_191 [ V_136 ] ) ;
if ( V_198 )
break;
}
if ( V_198 ) {
int V_208 ;
if ( ! V_196 )
V_22 -> V_34 [ V_31 ] -- ;
for ( V_208 = 0 ; V_208 < V_136 ; V_208 ++ )
( void ) F_123 ( V_22 , V_31 , & V_191 [ V_208 ] ) ;
} else if ( V_207 != ( V_22 -> V_34 [ V_35 ] != 0 ) ) {
#ifdef F_93
struct V_23 * V_24 ;
V_15 = V_22 -> V_4 ;
#endif
if ( V_22 -> V_34 [ V_35 ] )
V_22 -> V_31 = V_35 ;
else if ( V_22 -> V_34 [ V_32 ] )
V_22 -> V_31 = V_32 ;
#ifdef F_93
V_22 -> V_112 = V_15 -> V_130 ? V_15 -> V_130 :
V_131 ;
V_15 -> V_128 = V_22 -> V_112 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_60 ( V_15 ) ;
} else if ( F_126 ( V_22 ) ) {
F_60 ( V_15 ) ;
#endif
}
F_9 ( & V_22 -> V_6 ) ;
return V_198 ;
}
static void F_91 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_209 ;
for ( V_24 = V_22 -> V_108 ; V_24 ; V_24 = V_209 ) {
V_209 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
}
V_22 -> V_108 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_209 ) {
V_209 = V_24 -> V_43 ;
F_48 ( V_24 ) ;
}
V_22 -> V_42 = NULL ;
V_22 -> V_31 = V_35 ;
V_22 -> V_34 [ V_32 ] = 0 ;
V_22 -> V_34 [ V_35 ] = 1 ;
}
int F_129 ( struct V_210 * V_211 , struct V_184 * V_185 )
{
int V_198 ;
T_1 V_164 = V_185 -> V_190 . V_189 ;
struct V_212 * V_213 = NULL , * V_136 ;
struct V_14 * V_15 ;
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
int V_65 ;
int V_216 = 0 ;
if ( ! F_132 ( V_164 ) )
return - V_200 ;
F_133 () ;
V_15 = F_118 ( V_55 , V_185 ) ;
if ( ! V_15 ) {
V_213 = NULL ;
V_198 = - V_199 ;
goto V_217;
}
V_198 = - V_218 ;
V_65 = V_185 -> V_187 ;
F_100 (inet, i) {
if ( V_136 -> V_219 . V_190 . V_189 == V_164 &&
V_136 -> V_219 . V_187 == V_65 )
goto V_217;
V_216 ++ ;
}
V_198 = - V_202 ;
if ( V_216 >= V_220 )
goto V_217;
V_213 = F_134 ( V_211 , sizeof( * V_213 ) , V_167 ) ;
if ( V_213 == NULL )
goto V_217;
memcpy ( & V_213 -> V_219 , V_185 , sizeof( * V_185 ) ) ;
V_213 -> V_181 = V_215 -> V_182 ;
V_213 -> V_221 = NULL ;
V_213 -> V_31 = V_35 ;
F_99 ( V_215 -> V_182 , V_213 ) ;
F_103 ( V_15 , V_164 ) ;
V_198 = 0 ;
V_217:
F_135 () ;
return V_198 ;
}
static int F_136 ( struct V_210 * V_211 , struct V_212 * V_213 ,
struct V_14 * V_15 )
{
struct V_222 * V_24 = F_98 ( V_213 -> V_221 ) ;
int V_198 ;
if ( V_24 == NULL ) {
return F_124 ( V_15 , & V_213 -> V_219 . V_190 . V_189 ,
V_213 -> V_31 , 0 , NULL , 0 ) ;
}
V_198 = F_124 ( V_15 , & V_213 -> V_219 . V_190 . V_189 ,
V_213 -> V_31 , V_24 -> V_223 , V_24 -> V_224 , 0 ) ;
F_101 ( V_213 -> V_221 , NULL ) ;
F_137 ( F_138 ( V_24 -> V_225 ) , & V_211 -> V_226 ) ;
F_4 ( V_24 , V_5 ) ;
return V_198 ;
}
int F_139 ( struct V_210 * V_211 , struct V_184 * V_185 )
{
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_212 * V_213 ;
struct V_212 T_3 * * V_227 ;
struct V_14 * V_15 ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
T_1 V_122 = V_185 -> V_190 . V_189 ;
T_2 V_65 ;
int V_228 = - V_229 ;
F_133 () ;
V_15 = F_118 ( V_55 , V_185 ) ;
V_65 = V_185 -> V_187 ;
for ( V_227 = & V_215 -> V_182 ;
( V_213 = F_98 ( * V_227 ) ) != NULL ;
V_227 = & V_213 -> V_181 ) {
if ( V_213 -> V_219 . V_190 . V_189 != V_122 )
continue;
if ( V_65 ) {
if ( V_213 -> V_219 . V_187 != V_65 )
continue;
} else if ( V_185 -> V_188 . V_189 && V_185 -> V_188 . V_189 !=
V_213 -> V_219 . V_188 . V_189 )
continue;
( void ) F_136 ( V_211 , V_213 , V_15 ) ;
* V_227 = V_213 -> V_181 ;
if ( V_15 )
F_111 ( V_15 , V_122 ) ;
F_135 () ;
F_137 ( sizeof( * V_213 ) , & V_211 -> V_226 ) ;
F_4 ( V_213 , V_5 ) ;
return 0 ;
}
if ( ! V_15 )
V_228 = - V_199 ;
F_135 () ;
return V_228 ;
}
int F_140 ( int V_230 , int V_231 , struct V_210 * V_211 , struct
V_232 * V_233 , int V_65 )
{
int V_198 ;
struct V_184 V_185 ;
T_1 V_164 = V_233 -> V_190 ;
struct V_212 * V_22 ;
struct V_14 * V_15 = NULL ;
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_222 * V_234 ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
int V_235 = 0 ;
int V_136 , V_208 , V_192 ;
if ( ! F_132 ( V_164 ) )
return - V_200 ;
F_133 () ;
V_185 . V_190 . V_189 = V_233 -> V_190 ;
V_185 . V_188 . V_189 = V_233 -> V_236 ;
V_185 . V_187 = V_65 ;
V_15 = F_118 ( V_55 , & V_185 ) ;
if ( ! V_15 ) {
V_198 = - V_199 ;
goto V_217;
}
V_198 = - V_229 ;
F_100 (inet, pmc) {
if ( ( V_22 -> V_219 . V_190 . V_189 ==
V_185 . V_190 . V_189 ) &&
( V_22 -> V_219 . V_187 == V_185 . V_187 ) )
break;
}
if ( ! V_22 ) {
V_198 = - V_200 ;
goto V_217;
}
if ( V_22 -> V_221 ) {
if ( V_22 -> V_31 != V_231 ) {
V_198 = - V_200 ;
goto V_217;
}
} else if ( V_22 -> V_31 != V_231 ) {
F_105 ( V_15 , & V_233 -> V_190 , V_231 , 0 , NULL , 0 ) ;
F_124 ( V_15 , & V_233 -> V_190 , V_22 -> V_31 , 0 ,
NULL , 0 ) ;
V_22 -> V_31 = V_231 ;
}
V_234 = F_98 ( V_22 -> V_221 ) ;
if ( ! V_230 ) {
if ( ! V_234 )
goto V_217;
V_192 = ! 0 ;
for ( V_136 = 0 ; V_136 < V_234 -> V_223 ; V_136 ++ ) {
V_192 = memcmp ( & V_234 -> V_224 [ V_136 ] , & V_233 -> V_237 ,
sizeof( T_1 ) ) ;
if ( V_192 == 0 )
break;
}
if ( V_192 )
goto V_217;
if ( V_234 -> V_223 == 1 && V_231 == V_32 ) {
V_235 = 1 ;
goto V_217;
}
F_124 ( V_15 , & V_233 -> V_190 , V_231 , 1 ,
& V_233 -> V_237 , 1 ) ;
for ( V_208 = V_136 + 1 ; V_208 < V_234 -> V_223 ; V_208 ++ )
V_234 -> V_224 [ V_208 - 1 ] = V_234 -> V_224 [ V_208 ] ;
V_234 -> V_223 -- ;
V_198 = 0 ;
goto V_217;
}
if ( V_234 && V_234 -> V_223 >= V_238 ) {
V_198 = - V_202 ;
goto V_217;
}
if ( ! V_234 || V_234 -> V_223 == V_234 -> V_225 ) {
struct V_222 * V_239 ;
int V_216 = V_240 ;
if ( V_234 )
V_216 += V_234 -> V_225 ;
V_239 = F_134 ( V_211 , F_138 ( V_216 ) , V_167 ) ;
if ( ! V_239 ) {
V_198 = - V_202 ;
goto V_217;
}
V_239 -> V_225 = V_216 ;
V_239 -> V_223 = V_216 - V_240 ;
if ( V_234 ) {
for ( V_136 = 0 ; V_136 < V_234 -> V_223 ; V_136 ++ )
V_239 -> V_224 [ V_136 ] = V_234 -> V_224 [ V_136 ] ;
F_137 ( F_138 ( V_234 -> V_225 ) , & V_211 -> V_226 ) ;
F_4 ( V_234 , V_5 ) ;
}
F_99 ( V_22 -> V_221 , V_239 ) ;
V_234 = V_239 ;
}
V_192 = 1 ;
for ( V_136 = 0 ; V_136 < V_234 -> V_223 ; V_136 ++ ) {
V_192 = memcmp ( & V_234 -> V_224 [ V_136 ] , & V_233 -> V_237 ,
sizeof( T_1 ) ) ;
if ( V_192 == 0 )
break;
}
if ( V_192 == 0 )
goto V_217;
for ( V_208 = V_234 -> V_223 - 1 ; V_208 >= V_136 ; V_208 -- )
V_234 -> V_224 [ V_208 + 1 ] = V_234 -> V_224 [ V_208 ] ;
V_234 -> V_224 [ V_136 ] = V_233 -> V_237 ;
V_234 -> V_223 ++ ;
V_198 = 0 ;
F_105 ( V_15 , & V_233 -> V_190 , V_231 , 1 ,
& V_233 -> V_237 , 1 ) ;
V_217:
F_135 () ;
if ( V_235 )
return F_139 ( V_211 , & V_185 ) ;
return V_198 ;
}
int F_141 ( struct V_210 * V_211 , struct V_241 * V_242 , int V_65 )
{
int V_198 = 0 ;
struct V_184 V_185 ;
T_1 V_164 = V_242 -> V_243 ;
struct V_212 * V_22 ;
struct V_14 * V_15 ;
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_222 * V_239 , * V_234 ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
int V_235 = 0 ;
if ( ! F_132 ( V_164 ) )
return - V_200 ;
if ( V_242 -> V_244 != V_32 &&
V_242 -> V_244 != V_35 )
return - V_200 ;
F_133 () ;
V_185 . V_190 . V_189 = V_242 -> V_243 ;
V_185 . V_188 . V_189 = V_242 -> V_245 ;
V_185 . V_187 = V_65 ;
V_15 = F_118 ( V_55 , & V_185 ) ;
if ( ! V_15 ) {
V_198 = - V_199 ;
goto V_217;
}
if ( V_242 -> V_244 == V_32 && V_242 -> V_246 == 0 ) {
V_235 = 1 ;
goto V_217;
}
F_100 (inet, pmc) {
if ( V_22 -> V_219 . V_190 . V_189 == V_242 -> V_243 &&
V_22 -> V_219 . V_187 == V_185 . V_187 )
break;
}
if ( ! V_22 ) {
V_198 = - V_200 ;
goto V_217;
}
if ( V_242 -> V_246 ) {
V_239 = F_134 ( V_211 , F_138 ( V_242 -> V_246 ) ,
V_167 ) ;
if ( ! V_239 ) {
V_198 = - V_202 ;
goto V_217;
}
V_239 -> V_225 = V_239 -> V_223 = V_242 -> V_246 ;
memcpy ( V_239 -> V_224 , V_242 -> V_247 ,
V_242 -> V_246 * sizeof( V_242 -> V_247 [ 0 ] ) ) ;
V_198 = F_105 ( V_15 , & V_242 -> V_243 ,
V_242 -> V_244 , V_239 -> V_223 , V_239 -> V_224 , 0 ) ;
if ( V_198 ) {
F_142 ( V_211 , V_239 , F_138 ( V_239 -> V_225 ) ) ;
goto V_217;
}
} else {
V_239 = NULL ;
( void ) F_105 ( V_15 , & V_242 -> V_243 ,
V_242 -> V_244 , 0 , NULL , 0 ) ;
}
V_234 = F_98 ( V_22 -> V_221 ) ;
if ( V_234 ) {
( void ) F_124 ( V_15 , & V_242 -> V_243 , V_22 -> V_31 ,
V_234 -> V_223 , V_234 -> V_224 , 0 ) ;
F_137 ( F_138 ( V_234 -> V_225 ) , & V_211 -> V_226 ) ;
F_4 ( V_234 , V_5 ) ;
} else
( void ) F_124 ( V_15 , & V_242 -> V_243 , V_22 -> V_31 ,
0 , NULL , 0 ) ;
F_99 ( V_22 -> V_221 , V_239 ) ;
V_22 -> V_31 = V_242 -> V_244 ;
V_198 = 0 ;
V_217:
F_135 () ;
if ( V_235 )
V_198 = F_139 ( V_211 , & V_185 ) ;
return V_198 ;
}
int F_143 ( struct V_210 * V_211 , struct V_241 * V_242 ,
struct V_241 T_4 * V_248 , int T_4 * V_249 )
{
int V_198 , V_137 , V_216 , V_250 ;
struct V_184 V_185 ;
T_1 V_164 = V_242 -> V_243 ;
struct V_212 * V_22 ;
struct V_14 * V_15 ;
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_222 * V_234 ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
if ( ! F_132 ( V_164 ) )
return - V_200 ;
F_133 () ;
V_185 . V_190 . V_189 = V_242 -> V_243 ;
V_185 . V_188 . V_189 = V_242 -> V_245 ;
V_185 . V_187 = 0 ;
V_15 = F_118 ( V_55 , & V_185 ) ;
if ( ! V_15 ) {
V_198 = - V_199 ;
goto V_217;
}
V_198 = - V_229 ;
F_100 (inet, pmc) {
if ( V_22 -> V_219 . V_190 . V_189 == V_242 -> V_243 &&
V_22 -> V_219 . V_187 == V_185 . V_187 )
break;
}
if ( ! V_22 )
goto V_217;
V_242 -> V_244 = V_22 -> V_31 ;
V_234 = F_98 ( V_22 -> V_221 ) ;
F_135 () ;
if ( ! V_234 ) {
V_137 = 0 ;
V_216 = 0 ;
} else {
V_216 = V_234 -> V_223 ;
}
V_250 = V_216 < V_242 -> V_246 ? V_216 : V_242 -> V_246 ;
V_137 = V_250 * sizeof( V_234 -> V_224 [ 0 ] ) ;
V_242 -> V_246 = V_216 ;
if ( F_144 ( F_145 ( V_250 ) , V_249 ) ||
F_146 ( V_248 , V_242 , F_145 ( 0 ) ) ) {
return - V_251 ;
}
if ( V_137 &&
F_146 ( & V_248 -> V_247 [ 0 ] , V_234 -> V_224 , V_137 ) )
return - V_251 ;
return 0 ;
V_217:
F_135 () ;
return V_198 ;
}
int F_147 ( struct V_210 * V_211 , struct V_252 * V_253 ,
struct V_252 T_4 * V_248 , int T_4 * V_249 )
{
int V_198 , V_136 , V_216 , V_250 ;
struct V_254 * V_255 ;
T_1 V_164 ;
struct V_212 * V_22 ;
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_222 * V_234 ;
V_255 = (struct V_254 * ) & V_253 -> V_256 ;
if ( V_255 -> V_257 != V_258 )
return - V_200 ;
V_164 = V_255 -> V_259 . V_189 ;
if ( ! F_132 ( V_164 ) )
return - V_200 ;
F_133 () ;
V_198 = - V_229 ;
F_100 (inet, pmc) {
if ( V_22 -> V_219 . V_190 . V_189 == V_164 &&
V_22 -> V_219 . V_187 == V_253 -> V_260 )
break;
}
if ( ! V_22 )
goto V_217;
V_253 -> V_261 = V_22 -> V_31 ;
V_234 = F_98 ( V_22 -> V_221 ) ;
F_135 () ;
V_216 = V_234 ? V_234 -> V_223 : 0 ;
V_250 = V_216 < V_253 -> V_262 ? V_216 : V_253 -> V_262 ;
V_253 -> V_262 = V_216 ;
if ( F_144 ( F_148 ( V_250 ) , V_249 ) ||
F_146 ( V_248 , V_253 , F_148 ( 0 ) ) ) {
return - V_251 ;
}
for ( V_136 = 0 ; V_136 < V_250 ; V_136 ++ ) {
struct V_263 V_264 ;
V_255 = (struct V_254 * ) & V_264 ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
V_255 -> V_257 = V_258 ;
V_255 -> V_259 . V_189 = V_234 -> V_224 [ V_136 ] ;
if ( F_146 ( & V_248 -> V_265 [ V_136 ] , & V_264 , sizeof( V_264 ) ) )
return - V_251 ;
}
return 0 ;
V_217:
F_135 () ;
return V_198 ;
}
int F_149 ( struct V_210 * V_211 , T_1 V_266 , T_1 V_267 , int V_268 )
{
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_212 * V_22 ;
struct V_222 * V_234 ;
int V_136 ;
int V_228 ;
V_228 = 1 ;
if ( ! F_132 ( V_266 ) )
goto V_180;
F_50 () ;
F_51 (inet, pmc) {
if ( V_22 -> V_219 . V_190 . V_189 == V_266 &&
V_22 -> V_219 . V_187 == V_268 )
break;
}
V_228 = V_215 -> V_269 ;
if ( ! V_22 )
goto V_270;
V_234 = F_150 ( V_22 -> V_221 ) ;
V_228 = ( V_22 -> V_31 == V_35 ) ;
if ( ! V_234 )
goto V_270;
for ( V_136 = 0 ; V_136 < V_234 -> V_223 ; V_136 ++ ) {
if ( V_234 -> V_224 [ V_136 ] == V_267 )
break;
}
V_228 = 0 ;
if ( V_22 -> V_31 == V_32 && V_136 >= V_234 -> V_223 )
goto V_270;
if ( V_22 -> V_31 == V_35 && V_136 < V_234 -> V_223 )
goto V_270;
V_228 = 1 ;
V_270:
F_52 () ;
V_180:
return V_228 ;
}
void F_151 ( struct V_210 * V_211 )
{
struct V_214 * V_215 = F_130 ( V_211 ) ;
struct V_212 * V_213 ;
struct V_55 * V_55 = F_131 ( V_211 ) ;
if ( V_215 -> V_182 == NULL )
return;
F_133 () ;
while ( ( V_213 = F_98 ( V_215 -> V_182 ) ) != NULL ) {
struct V_14 * V_15 ;
V_215 -> V_182 = V_213 -> V_181 ;
V_15 = F_119 ( V_55 , V_213 -> V_219 . V_187 ) ;
( void ) F_136 ( V_211 , V_213 , V_15 ) ;
if ( V_15 != NULL )
F_111 ( V_15 , V_213 -> V_219 . V_190 . V_189 ) ;
F_137 ( sizeof( * V_213 ) , & V_211 -> V_226 ) ;
F_4 ( V_213 , V_5 ) ;
}
F_135 () ;
}
int F_152 ( struct V_14 * V_15 , T_1 V_271 , T_1 V_272 , T_5 V_273 )
{
struct V_1 * V_2 ;
struct V_1 T_3 * * V_174 ;
struct V_23 * V_24 ;
int V_192 = 0 ;
V_174 = F_150 ( V_15 -> V_174 ) ;
if ( V_174 ) {
T_2 V_175 = F_96 ( ( V_172 T_2 ) V_271 , V_173 ) ;
for ( V_2 = F_150 ( V_174 [ V_175 ] ) ;
V_2 != NULL ;
V_2 = F_150 ( V_2 -> V_176 ) ) {
if ( V_2 -> V_99 == V_271 )
break;
}
} else {
F_51 (in_dev, im) {
if ( V_2 -> V_99 == V_271 )
break;
}
}
if ( V_2 && V_273 == V_64 ) {
V_192 = 1 ;
} else if ( V_2 ) {
if ( V_272 ) {
for ( V_24 = V_2 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_111 == V_272 )
break;
}
if ( V_24 )
V_192 = V_24 -> V_33 [ V_32 ] ||
V_24 -> V_33 [ V_35 ] !=
V_2 -> V_34 [ V_35 ] ;
else
V_192 = V_2 -> V_34 [ V_35 ] != 0 ;
} else
V_192 = 1 ;
}
return V_192 ;
}
static inline struct V_1 * F_153 ( struct V_274 * V_275 )
{
struct V_55 * V_55 = F_154 ( V_275 ) ;
struct V_1 * V_2 = NULL ;
struct V_276 * V_277 = F_155 ( V_275 ) ;
V_277 -> V_15 = NULL ;
F_156 (net, state->dev) {
struct V_14 * V_15 ;
V_15 = F_75 ( V_277 -> V_46 ) ;
if ( ! V_15 )
continue;
V_2 = F_150 ( V_15 -> V_182 ) ;
if ( V_2 ) {
V_277 -> V_15 = V_15 ;
break;
}
}
return V_2 ;
}
static struct V_1 * F_157 ( struct V_274 * V_275 , struct V_1 * V_2 )
{
struct V_276 * V_277 = F_155 ( V_275 ) ;
V_2 = F_150 ( V_2 -> V_181 ) ;
while ( ! V_2 ) {
V_277 -> V_46 = F_158 ( V_277 -> V_46 ) ;
if ( ! V_277 -> V_46 ) {
V_277 -> V_15 = NULL ;
break;
}
V_277 -> V_15 = F_75 ( V_277 -> V_46 ) ;
if ( ! V_277 -> V_15 )
continue;
V_2 = F_150 ( V_277 -> V_15 -> V_182 ) ;
}
return V_2 ;
}
static struct V_1 * F_159 ( struct V_274 * V_275 , T_6 V_278 )
{
struct V_1 * V_2 = F_153 ( V_275 ) ;
if ( V_2 )
while ( V_278 && ( V_2 = F_157 ( V_275 , V_2 ) ) != NULL )
-- V_278 ;
return V_278 ? NULL : V_2 ;
}
static void * F_160 ( struct V_274 * V_275 , T_6 * V_278 )
__acquires( V_5 )
{
F_50 () ;
return * V_278 ? F_159 ( V_275 , * V_278 - 1 ) : V_279 ;
}
static void * F_161 ( struct V_274 * V_275 , void * V_280 , T_6 * V_278 )
{
struct V_1 * V_2 ;
if ( V_280 == V_279 )
V_2 = F_153 ( V_275 ) ;
else
V_2 = F_157 ( V_275 , V_280 ) ;
++ * V_278 ;
return V_2 ;
}
static void F_162 ( struct V_274 * V_275 , void * V_280 )
__releases( V_5 )
{
struct V_276 * V_277 = F_155 ( V_275 ) ;
V_277 -> V_15 = NULL ;
V_277 -> V_46 = NULL ;
F_52 () ;
}
static int F_163 ( struct V_274 * V_275 , void * V_280 )
{
if ( V_280 == V_279 )
F_164 ( V_275 ,
L_1 ) ;
else {
struct V_1 * V_2 = (struct V_1 * ) V_280 ;
struct V_276 * V_277 = F_155 ( V_275 ) ;
char * V_281 ;
long V_196 ;
#ifdef F_93
V_281 = F_61 ( V_277 -> V_15 ) ? L_2 :
F_62 ( V_277 -> V_15 ) ? L_3 :
L_4 ;
#else
V_281 = L_5 ;
#endif
if ( F_150 ( V_277 -> V_15 -> V_182 ) == V_2 ) {
F_165 ( V_275 , L_6 ,
V_277 -> V_46 -> V_65 , V_277 -> V_46 -> V_282 , V_277 -> V_15 -> V_177 , V_281 ) ;
}
V_196 = V_2 -> V_7 . V_21 - V_13 ;
F_165 ( V_275 ,
L_7 ,
V_2 -> V_99 , V_2 -> V_179 ,
V_2 -> V_8 ,
V_2 -> V_8 ? F_166 ( V_196 ) : 0 ,
V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_167 ( struct V_283 * V_283 , struct V_284 * V_284 )
{
return F_168 ( V_283 , V_284 , & V_285 ,
sizeof( struct V_276 ) ) ;
}
static inline struct V_23 * F_169 ( struct V_274 * V_275 )
{
struct V_55 * V_55 = F_154 ( V_275 ) ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_286 * V_277 = F_170 ( V_275 ) ;
V_277 -> V_186 = NULL ;
V_277 -> V_2 = NULL ;
F_156 (net, state->dev) {
struct V_14 * V_186 ;
V_186 = F_75 ( V_277 -> V_46 ) ;
if ( F_171 ( V_186 == NULL ) )
continue;
V_2 = F_150 ( V_186 -> V_182 ) ;
if ( F_172 ( V_2 != NULL ) ) {
F_6 ( & V_2 -> V_6 ) ;
V_24 = V_2 -> V_42 ;
if ( F_172 ( V_24 != NULL ) ) {
V_277 -> V_2 = V_2 ;
V_277 -> V_186 = V_186 ;
break;
}
F_9 ( & V_2 -> V_6 ) ;
}
}
return V_24 ;
}
static struct V_23 * F_173 ( struct V_274 * V_275 , struct V_23 * V_24 )
{
struct V_286 * V_277 = F_170 ( V_275 ) ;
V_24 = V_24 -> V_43 ;
while ( ! V_24 ) {
F_9 ( & V_277 -> V_2 -> V_6 ) ;
V_277 -> V_2 = V_277 -> V_2 -> V_119 ;
while ( ! V_277 -> V_2 ) {
V_277 -> V_46 = F_158 ( V_277 -> V_46 ) ;
if ( ! V_277 -> V_46 ) {
V_277 -> V_186 = NULL ;
goto V_180;
}
V_277 -> V_186 = F_75 ( V_277 -> V_46 ) ;
if ( ! V_277 -> V_186 )
continue;
V_277 -> V_2 = F_150 ( V_277 -> V_186 -> V_182 ) ;
}
if ( ! V_277 -> V_2 )
break;
F_6 ( & V_277 -> V_2 -> V_6 ) ;
V_24 = V_277 -> V_2 -> V_42 ;
}
V_180:
return V_24 ;
}
static struct V_23 * F_174 ( struct V_274 * V_275 , T_6 V_278 )
{
struct V_23 * V_24 = F_169 ( V_275 ) ;
if ( V_24 )
while ( V_278 && ( V_24 = F_173 ( V_275 , V_24 ) ) != NULL )
-- V_278 ;
return V_278 ? NULL : V_24 ;
}
static void * F_175 ( struct V_274 * V_275 , T_6 * V_278 )
__acquires( V_5 )
{
F_50 () ;
return * V_278 ? F_174 ( V_275 , * V_278 - 1 ) : V_279 ;
}
static void * F_176 ( struct V_274 * V_275 , void * V_280 , T_6 * V_278 )
{
struct V_23 * V_24 ;
if ( V_280 == V_279 )
V_24 = F_169 ( V_275 ) ;
else
V_24 = F_173 ( V_275 , V_280 ) ;
++ * V_278 ;
return V_24 ;
}
static void F_177 ( struct V_274 * V_275 , void * V_280 )
__releases( V_5 )
{
struct V_286 * V_277 = F_170 ( V_275 ) ;
if ( F_172 ( V_277 -> V_2 != NULL ) ) {
F_9 ( & V_277 -> V_2 -> V_6 ) ;
V_277 -> V_2 = NULL ;
}
V_277 -> V_186 = NULL ;
V_277 -> V_46 = NULL ;
F_52 () ;
}
static int F_178 ( struct V_274 * V_275 , void * V_280 )
{
struct V_23 * V_24 = (struct V_23 * ) V_280 ;
struct V_286 * V_277 = F_170 ( V_275 ) ;
if ( V_280 == V_279 ) {
F_165 ( V_275 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_165 ( V_275 ,
L_16
L_17 ,
V_277 -> V_46 -> V_65 , V_277 -> V_46 -> V_282 ,
F_179 ( V_277 -> V_2 -> V_99 ) ,
F_179 ( V_24 -> V_111 ) ,
V_24 -> V_33 [ V_32 ] ,
V_24 -> V_33 [ V_35 ] ) ;
}
return 0 ;
}
static int F_180 ( struct V_283 * V_283 , struct V_284 * V_284 )
{
return F_168 ( V_283 , V_284 , & V_287 ,
sizeof( struct V_286 ) ) ;
}
static int T_7 F_181 ( struct V_55 * V_55 )
{
struct V_288 * V_289 ;
V_289 = F_182 ( L_18 , V_290 , V_55 -> V_291 , & V_292 ) ;
if ( ! V_289 )
goto V_293;
V_289 = F_182 ( L_19 , V_290 , V_55 -> V_291 ,
& V_294 ) ;
if ( ! V_289 )
goto V_295;
return 0 ;
V_295:
F_183 ( L_18 , V_55 -> V_291 ) ;
V_293:
return - V_296 ;
}
static void T_8 F_184 ( struct V_55 * V_55 )
{
F_183 ( L_19 , V_55 -> V_291 ) ;
F_183 ( L_18 , V_55 -> V_291 ) ;
}
int T_9 F_185 ( void )
{
return F_186 ( & V_297 ) ;
}
