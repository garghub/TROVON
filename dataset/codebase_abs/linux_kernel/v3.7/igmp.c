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
const int V_87 = V_48 -> V_88 - V_48 -> V_79 ;
V_54 -> V_83 = F_39 ( F_38 ( V_48 ) , V_87 ) ;
return F_40 ( V_48 ) ;
}
static int F_41 ( struct V_1 * V_22 , int type , int V_89 , int V_90 )
{
return sizeof( struct V_91 ) + 4 * F_20 ( V_22 , type , V_89 , V_90 ) ;
}
static struct V_44 * F_42 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , struct V_91 * * V_92 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_93 ;
struct V_91 * V_94 ;
if ( ! V_48 )
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
if ( ! V_48 )
return NULL ;
V_94 = (struct V_91 * ) F_33 ( V_48 , sizeof( struct V_91 ) ) ;
V_94 -> V_96 = type ;
V_94 -> V_97 = 0 ;
V_94 -> V_98 = 0 ;
V_94 -> V_99 = V_22 -> V_100 ;
V_93 = F_36 ( V_48 ) ;
V_93 -> V_85 = F_34 ( F_43 ( V_93 -> V_85 ) + 1 ) ;
* V_92 = V_94 ;
return V_48 ;
}
static struct V_44 * F_44 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , int V_25 , int V_26 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_93 ;
struct V_91 * V_94 = NULL ;
struct V_23 * V_24 , * V_101 , * V_102 , * * V_103 ;
int V_41 , V_104 , V_105 , V_106 , V_107 ;
if ( V_22 -> V_100 == V_108 )
return V_48 ;
V_106 = type == V_27 ||
type == V_28 ;
V_107 = type == V_28 ||
type == V_37 ;
V_104 = V_41 = 0 ;
V_103 = V_26 ? & V_22 -> V_109 : & V_22 -> V_42 ;
if ( ! * V_103 )
goto V_110;
V_93 = V_48 ? F_36 ( V_48 ) : NULL ;
if ( V_107 ) {
if ( V_93 && V_93 -> V_85 &&
F_45 ( V_48 ) < F_41 ( V_22 , type , V_25 , V_26 ) ) {
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
}
}
V_105 = 1 ;
V_102 = NULL ;
for ( V_24 = * V_103 ; V_24 ; V_24 = V_101 ) {
T_1 * V_111 ;
V_101 = V_24 -> V_43 ;
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) ) {
V_102 = V_24 ;
continue;
}
if ( V_106 )
V_24 -> V_30 = 0 ;
if ( F_45 ( V_48 ) < sizeof( T_1 ) +
V_105 * sizeof( struct V_91 ) ) {
if ( V_107 && ! V_105 )
break;
if ( V_94 )
V_94 -> V_98 = F_34 ( V_41 ) ;
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
V_105 = 1 ;
V_41 = 0 ;
}
if ( V_105 ) {
V_48 = F_42 ( V_48 , V_22 , type , & V_94 ) ;
V_105 = 0 ;
}
if ( ! V_48 )
return NULL ;
V_111 = ( T_1 * ) F_33 ( V_48 , sizeof( T_1 ) ) ;
* V_111 = V_24 -> V_112 ;
V_41 ++ ; V_104 ++ ;
if ( ( type == V_38 ||
type == V_40 ) && V_24 -> V_39 ) {
V_24 -> V_39 -- ;
if ( ( V_26 || V_25 ) && V_24 -> V_39 == 0 ) {
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
* V_103 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
continue;
}
}
V_102 = V_24 ;
}
V_110:
if ( ! V_104 ) {
if ( type == V_38 ||
type == V_40 )
return V_48 ;
if ( V_22 -> V_113 || V_106 ) {
if ( V_48 && F_45 ( V_48 ) < sizeof( struct V_91 ) ) {
F_37 ( V_48 ) ;
V_48 = NULL ;
}
V_48 = F_42 ( V_48 , V_22 , type , & V_94 ) ;
}
}
if ( V_94 )
V_94 -> V_98 = F_34 ( V_41 ) ;
if ( V_106 )
V_22 -> V_29 = 0 ;
return V_48 ;
}
static int F_47 ( struct V_14 * V_15 , struct V_1 * V_22 )
{
struct V_44 * V_48 = NULL ;
int type ;
if ( ! V_22 ) {
F_48 () ;
F_49 (in_dev, pmc) {
if ( V_22 -> V_100 == V_108 )
continue;
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
F_50 () ;
} else {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
if ( ! V_48 )
return 0 ;
return F_37 ( V_48 ) ;
}
static void F_51 ( struct V_23 * * V_114 )
{
struct V_23 * V_102 , * V_101 , * V_24 ;
V_102 = NULL ;
for ( V_24 = * V_114 ; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
if ( V_24 -> V_39 == 0 ) {
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
* V_114 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
} else
V_102 = V_24 ;
}
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_115 , * V_116 ;
struct V_44 * V_48 = NULL ;
int type , V_117 ;
F_48 () ;
F_6 ( & V_15 -> V_118 ) ;
V_115 = NULL ;
for ( V_22 = V_15 -> V_119 ; V_22 ; V_22 = V_116 ) {
V_116 = V_22 -> V_120 ;
if ( V_22 -> V_31 == V_32 ) {
type = V_40 ;
V_117 = V_40 ;
V_48 = F_44 ( V_48 , V_22 , type , 1 , 0 ) ;
V_48 = F_44 ( V_48 , V_22 , V_117 , 1 , 1 ) ;
}
if ( V_22 -> V_113 ) {
if ( V_22 -> V_31 == V_35 ) {
type = V_36 ;
V_48 = F_44 ( V_48 , V_22 , type , 1 , 0 ) ;
}
V_22 -> V_113 -- ;
if ( V_22 -> V_113 == 0 ) {
F_51 ( & V_22 -> V_109 ) ;
F_51 ( & V_22 -> V_42 ) ;
}
}
if ( V_22 -> V_113 == 0 && ! V_22 -> V_109 && ! V_22 -> V_42 ) {
if ( V_115 )
V_115 -> V_120 = V_116 ;
else
V_15 -> V_119 = V_116 ;
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
} else
V_115 = V_22 ;
}
F_9 ( & V_15 -> V_118 ) ;
F_49 (in_dev, pmc) {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] ) {
type = V_40 ;
V_117 = V_38 ;
} else {
type = V_38 ;
V_117 = V_40 ;
}
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
V_48 = F_44 ( V_48 , V_22 , V_117 , 0 , 1 ) ;
if ( V_22 -> V_113 ) {
if ( V_22 -> V_31 == V_35 )
type = V_37 ;
else
type = V_36 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
V_22 -> V_113 -- ;
}
F_9 ( & V_22 -> V_6 ) ;
}
F_50 () ;
if ( ! V_48 )
return;
( void ) F_37 ( V_48 ) ;
}
static int F_53 ( struct V_14 * V_15 , struct V_1 * V_22 ,
int type )
{
struct V_44 * V_48 ;
struct V_51 * V_121 ;
struct V_86 * V_122 ;
struct V_49 * V_50 ;
struct V_45 * V_46 = V_15 -> V_46 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
T_1 V_123 = V_22 ? V_22 -> V_100 : 0 ;
struct V_56 V_57 ;
T_1 V_66 ;
int V_58 , V_59 ;
if ( type == V_81 )
return F_47 ( V_15 , V_22 ) ;
else if ( type == V_124 )
V_66 = V_125 ;
else
V_66 = V_123 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_66 , 0 ,
0 , 0 ,
V_64 , 0 , V_46 -> V_65 ) ;
if ( F_27 ( V_50 ) )
return - 1 ;
V_58 = F_23 ( V_46 ) ;
V_59 = V_46 -> V_60 ;
V_48 = F_24 ( V_126 + V_58 + V_59 , V_61 ) ;
if ( V_48 == NULL ) {
F_54 ( V_50 ) ;
return - 1 ;
}
F_29 ( V_48 , & V_50 -> V_66 ) ;
F_30 ( V_48 , V_58 ) ;
F_31 ( V_48 ) ;
V_121 = F_32 ( V_48 ) ;
F_33 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_121 -> V_67 = 4 ;
V_121 -> V_68 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_121 -> V_69 = 0xc0 ;
V_121 -> V_70 = F_34 ( V_71 ) ;
V_121 -> V_72 = 1 ;
V_121 -> V_73 = V_66 ;
V_121 -> V_74 = V_57 . V_74 ;
V_121 -> V_75 = V_64 ;
F_35 ( V_121 , & V_50 -> V_66 , NULL ) ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 0 ] = V_78 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 1 ] = 4 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 2 ] = 0 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 3 ] = 0 ;
V_122 = (struct V_86 * ) F_33 ( V_48 , sizeof( struct V_86 ) ) ;
V_122 -> type = type ;
V_122 -> V_127 = 0 ;
V_122 -> V_83 = 0 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_83 = F_39 ( ( void * ) V_122 , sizeof( struct V_86 ) ) ;
return F_40 ( V_48 ) ;
}
static void F_55 ( unsigned long V_128 )
{
struct V_14 * V_15 = (struct V_14 * ) V_128 ;
V_15 -> V_17 = 0 ;
F_47 ( V_15 , NULL ) ;
F_56 ( V_15 ) ;
}
static void F_57 ( unsigned long V_128 )
{
struct V_14 * V_15 = (struct V_14 * ) V_128 ;
F_52 ( V_15 ) ;
if ( V_15 -> V_129 ) {
V_15 -> V_129 -- ;
F_16 ( V_15 , V_130 ) ;
}
F_56 ( V_15 ) ;
}
static void F_58 ( struct V_14 * V_15 )
{
if ( F_59 ( V_15 ) || F_60 ( V_15 ) )
return;
V_15 -> V_129 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
F_16 ( V_15 , 1 ) ;
}
static void F_61 ( unsigned long V_128 )
{
struct V_1 * V_2 = (struct V_1 * ) V_128 ;
struct V_14 * V_15 = V_2 -> V_4 ;
F_62 ( & V_2 -> V_6 ) ;
V_2 -> V_8 = 0 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 -- ;
F_10 ( V_2 , V_130 ) ;
}
V_2 -> V_9 = 1 ;
F_63 ( & V_2 -> V_6 ) ;
if ( F_59 ( V_15 ) )
F_53 ( V_15 , V_2 , V_133 ) ;
else if ( F_60 ( V_15 ) )
F_53 ( V_15 , V_2 , V_134 ) ;
else
F_53 ( V_15 , V_2 , V_81 ) ;
F_1 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_22 , int V_135 , T_1 * V_136 )
{
struct V_23 * V_24 ;
int V_137 , V_41 ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_135 )
break;
for ( V_137 = 0 ; V_137 < V_135 ; V_137 ++ ) {
if ( V_24 -> V_33 [ V_32 ] ||
V_22 -> V_34 [ V_35 ] !=
V_24 -> V_33 [ V_35 ] )
break;
if ( V_136 [ V_137 ] == V_24 -> V_112 ) {
V_41 ++ ;
break;
}
}
}
V_22 -> V_29 = 0 ;
if ( V_41 == V_135 )
return 0 ;
return 1 ;
}
static int F_65 ( struct V_1 * V_22 , int V_135 , T_1 * V_136 )
{
struct V_23 * V_24 ;
int V_137 , V_41 ;
if ( V_22 -> V_31 == V_35 )
return F_64 ( V_22 , V_135 , V_136 ) ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_135 )
break;
for ( V_137 = 0 ; V_137 < V_135 ; V_137 ++ )
if ( V_136 [ V_137 ] == V_24 -> V_112 ) {
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
static bool F_66 ( struct V_14 * V_15 , T_1 V_123 )
{
struct V_1 * V_2 ;
if ( V_123 == V_108 )
return false ;
F_48 () ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_123 ) {
F_5 ( V_2 ) ;
break;
}
}
F_50 () ;
return false ;
}
static bool F_67 ( struct V_14 * V_15 , struct V_44 * V_48 ,
int V_138 )
{
struct V_86 * V_122 = F_38 ( V_48 ) ;
struct V_139 * V_140 = F_68 ( V_48 ) ;
struct V_1 * V_2 ;
T_1 V_123 = V_122 -> V_123 ;
int V_11 ;
int V_141 = 0 ;
if ( V_138 == 8 ) {
if ( V_122 -> V_127 == 0 ) {
V_11 = V_142 ;
V_15 -> V_143 = V_13 +
V_144 ;
V_123 = 0 ;
} else {
V_11 = V_122 -> V_127 * ( V_145 / V_146 ) ;
V_15 -> V_147 = V_13 +
V_148 ;
}
V_15 -> V_129 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_56 ( V_15 ) ;
F_69 ( V_15 ) ;
} else if ( V_138 < 12 ) {
return true ;
} else if ( F_59 ( V_15 ) ) {
V_11 = V_142 ;
V_123 = 0 ;
} else if ( F_60 ( V_15 ) ) {
V_11 = F_70 ( V_140 -> V_127 ) * ( V_145 / V_146 ) ;
if ( ! V_11 )
V_11 = 1 ;
} else {
if ( ! F_71 ( V_48 , sizeof( struct V_139 ) ) )
return true ;
V_140 = F_68 ( V_48 ) ;
if ( V_140 -> V_135 ) {
if ( ! F_71 ( V_48 , sizeof( struct V_139 )
+ F_43 ( V_140 -> V_135 ) * sizeof( T_1 ) ) )
return true ;
V_140 = F_68 ( V_48 ) ;
}
V_11 = F_70 ( V_140 -> V_127 ) * ( V_145 / V_146 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_15 -> V_16 = V_11 ;
if ( V_140 -> V_149 )
V_15 -> V_131 = V_140 -> V_149 ;
if ( ! V_123 ) {
if ( V_140 -> V_135 )
return false ;
F_14 ( V_15 ) ;
return false ;
}
V_141 = V_140 -> V_135 != 0 ;
}
F_48 () ;
F_49 (in_dev, im) {
int V_150 ;
if ( V_123 && V_123 != V_2 -> V_100 )
continue;
if ( V_2 -> V_100 == V_108 )
continue;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_2 -> V_29 = V_2 -> V_29 && V_141 ;
else
V_2 -> V_29 = V_141 ;
V_150 = ! V_2 -> V_29 ||
F_65 ( V_2 , F_43 ( V_140 -> V_135 ) , V_140 -> V_136 ) ;
F_9 ( & V_2 -> V_6 ) ;
if ( V_150 )
F_17 ( V_2 , V_11 ) ;
}
F_50 () ;
return false ;
}
int F_72 ( struct V_44 * V_48 )
{
struct V_86 * V_122 ;
struct V_14 * V_15 = F_73 ( V_48 -> V_46 ) ;
int V_138 = V_48 -> V_138 ;
bool V_151 = true ;
if ( V_15 == NULL )
goto V_152;
if ( ! F_71 ( V_48 , sizeof( struct V_86 ) ) )
goto V_152;
switch ( V_48 -> V_153 ) {
case V_154 :
if ( ! F_74 ( V_48 -> V_83 ) )
break;
case V_155 :
V_48 -> V_83 = 0 ;
if ( F_75 ( V_48 ) )
goto V_152;
}
V_122 = F_38 ( V_48 ) ;
switch ( V_122 -> type ) {
case V_156 :
V_151 = F_67 ( V_15 , V_48 , V_138 ) ;
break;
case V_133 :
case V_134 :
if ( F_76 ( F_77 ( V_48 ) ) )
break;
if ( V_48 -> V_157 == V_158 ||
V_48 -> V_157 == V_159 )
V_151 = F_66 ( V_15 , V_122 -> V_123 ) ;
break;
case V_160 :
#ifdef F_78
return F_79 ( V_48 ) ;
#endif
case V_81 :
case V_161 :
case V_162 :
case V_124 :
case V_163 :
case V_164 :
break;
default:
break;
}
V_152:
if ( V_151 )
F_28 ( V_48 ) ;
else
F_80 ( V_48 ) ;
return 0 ;
}
static void F_81 ( struct V_14 * V_15 , T_1 V_165 )
{
char V_166 [ V_167 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_82 ( V_165 , V_166 , V_46 , 0 ) == 0 )
F_83 ( V_46 , V_166 ) ;
}
static void F_84 ( struct V_14 * V_15 , T_1 V_165 )
{
char V_166 [ V_167 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_82 ( V_165 , V_166 , V_46 , 0 ) == 0 )
F_85 ( V_46 , V_166 ) ;
}
static void F_86 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_1 * V_22 ;
V_22 = F_87 ( sizeof( * V_22 ) , V_168 ) ;
if ( ! V_22 )
return;
F_6 ( & V_2 -> V_6 ) ;
V_22 -> V_4 = V_2 -> V_4 ;
F_15 ( V_15 ) ;
V_22 -> V_100 = V_2 -> V_100 ;
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_22 -> V_31 = V_2 -> V_31 ;
if ( V_22 -> V_31 == V_32 ) {
struct V_23 * V_24 ;
V_22 -> V_109 = V_2 -> V_109 ;
V_22 -> V_42 = V_2 -> V_42 ;
V_2 -> V_109 = V_2 -> V_42 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = V_22 -> V_113 ;
}
F_9 ( & V_2 -> V_6 ) ;
F_6 ( & V_15 -> V_118 ) ;
V_22 -> V_120 = V_15 -> V_119 ;
V_15 -> V_119 = V_22 ;
F_9 ( & V_15 -> V_118 ) ;
}
static void F_88 ( struct V_14 * V_15 , T_1 V_100 )
{
struct V_1 * V_22 , * V_115 ;
struct V_23 * V_24 , * V_101 ;
F_6 ( & V_15 -> V_118 ) ;
V_115 = NULL ;
for ( V_22 = V_15 -> V_119 ; V_22 ; V_22 = V_22 -> V_120 ) {
if ( V_22 -> V_100 == V_100 )
break;
V_115 = V_22 ;
}
if ( V_22 ) {
if ( V_115 )
V_115 -> V_120 = V_22 -> V_120 ;
else
V_15 -> V_119 = V_22 -> V_120 ;
}
F_9 ( & V_15 -> V_118 ) ;
if ( V_22 ) {
for ( V_24 = V_22 -> V_109 ; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
}
}
static void F_69 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_169 ;
F_6 ( & V_15 -> V_118 ) ;
V_22 = V_15 -> V_119 ;
V_15 -> V_119 = NULL ;
F_9 ( & V_15 -> V_118 ) ;
for (; V_22 ; V_22 = V_169 ) {
V_169 = V_22 -> V_120 ;
F_89 ( V_22 ) ;
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
}
F_48 () ;
F_49 (in_dev, pmc) {
struct V_23 * V_24 , * V_101 ;
F_6 ( & V_22 -> V_6 ) ;
V_24 = V_22 -> V_109 ;
V_22 -> V_109 = NULL ;
F_9 ( & V_22 -> V_6 ) ;
for (; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
}
F_50 () ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
#ifdef F_91
int V_9 ;
#endif
if ( V_2 -> V_170 ) {
V_2 -> V_170 = 0 ;
F_84 ( V_15 , V_2 -> V_100 ) ;
}
#ifdef F_91
if ( V_2 -> V_100 == V_108 )
return;
V_9 = V_2 -> V_9 ;
F_5 ( V_2 ) ;
if ( ! V_15 -> V_171 ) {
if ( F_59 ( V_15 ) )
return;
if ( F_60 ( V_15 ) ) {
if ( V_9 )
F_53 ( V_15 , V_2 , V_124 ) ;
return;
}
F_86 ( V_15 , V_2 ) ;
F_58 ( V_15 ) ;
}
#endif
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
if ( V_2 -> V_170 == 0 ) {
V_2 -> V_170 = 1 ;
F_81 ( V_15 , V_2 -> V_100 ) ;
}
#ifdef F_91
if ( V_2 -> V_100 == V_108 )
return;
if ( V_15 -> V_171 )
return;
if ( F_59 ( V_15 ) || F_60 ( V_15 ) ) {
F_6 ( & V_2 -> V_6 ) ;
F_10 ( V_2 , V_172 ) ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
V_2 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
F_58 ( V_15 ) ;
#endif
}
void F_93 ( struct V_14 * V_15 , T_1 V_165 )
{
struct V_1 * V_2 ;
F_94 () ;
F_95 (in_dev, im) {
if ( V_2 -> V_100 == V_165 ) {
V_2 -> V_173 ++ ;
F_96 ( V_15 , & V_165 , V_35 , 0 , NULL , 0 ) ;
goto V_174;
}
}
V_2 = F_87 ( sizeof( * V_2 ) , V_168 ) ;
if ( ! V_2 )
goto V_174;
V_2 -> V_173 = 1 ;
V_2 -> V_4 = V_15 ;
F_15 ( V_15 ) ;
V_2 -> V_100 = V_165 ;
V_2 -> V_31 = V_35 ;
V_2 -> V_34 [ V_35 ] = 1 ;
F_97 ( & V_2 -> V_3 , 1 ) ;
F_98 ( & V_2 -> V_6 ) ;
#ifdef F_91
F_99 ( & V_2 -> V_7 , & F_61 , ( unsigned long ) V_2 ) ;
V_2 -> V_10 = V_132 ;
#endif
V_2 -> V_175 = V_15 -> V_176 ;
V_15 -> V_177 ++ ;
F_100 ( V_15 -> V_176 , V_2 ) ;
#ifdef F_91
F_88 ( V_15 , V_2 -> V_100 ) ;
#endif
F_92 ( V_2 ) ;
if ( ! V_15 -> V_171 )
F_101 ( V_15 ) ;
V_174:
return;
}
void F_102 ( struct V_14 * V_15 )
{
#ifdef F_91
struct V_1 * V_2 ;
int type ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_108 )
continue;
if ( F_59 ( V_15 ) )
type = V_133 ;
else if ( F_60 ( V_15 ) )
type = V_134 ;
else
type = V_81 ;
F_53 ( V_15 , V_2 , type ) ;
}
#endif
}
void F_103 ( struct V_14 * V_15 , T_1 V_165 )
{
struct V_1 * V_137 ;
struct V_1 T_2 * * V_178 ;
F_94 () ;
for ( V_178 = & V_15 -> V_176 ;
( V_137 = F_104 ( * V_178 ) ) != NULL ;
V_178 = & V_137 -> V_175 ) {
if ( V_137 -> V_100 == V_165 ) {
if ( -- V_137 -> V_173 == 0 ) {
* V_178 = V_137 -> V_175 ;
V_15 -> V_177 -- ;
F_90 ( V_137 ) ;
F_89 ( V_137 ) ;
if ( ! V_15 -> V_171 )
F_101 ( V_15 ) ;
F_1 ( V_137 ) ;
return;
}
break;
}
}
}
void F_105 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_90 ( V_22 ) ;
}
void F_106 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_92 ( V_22 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_90 ( V_22 ) ;
#ifdef F_91
V_15 -> V_129 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_56 ( V_15 ) ;
V_15 -> V_17 = 0 ;
if ( F_7 ( & V_15 -> V_18 ) )
F_56 ( V_15 ) ;
F_69 ( V_15 ) ;
#endif
F_103 ( V_15 , V_108 ) ;
}
void F_108 ( struct V_14 * V_15 )
{
F_94 () ;
V_15 -> V_119 = NULL ;
#ifdef F_91
V_15 -> V_17 = 0 ;
F_99 ( & V_15 -> V_18 , F_55 ,
( unsigned long ) V_15 ) ;
V_15 -> V_129 = 0 ;
V_15 -> V_177 = 0 ;
F_99 ( & V_15 -> V_20 , F_57 ,
( unsigned long ) V_15 ) ;
V_15 -> V_131 = V_132 ;
#endif
F_98 ( & V_15 -> V_118 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_93 ( V_15 , V_108 ) ;
F_95 (in_dev, pmc)
F_92 ( V_22 ) ;
}
void F_110 ( struct V_14 * V_15 )
{
struct V_1 * V_137 ;
F_94 () ;
F_107 ( V_15 ) ;
while ( ( V_137 = F_104 ( V_15 -> V_176 ) ) != NULL ) {
V_15 -> V_176 = V_137 -> V_175 ;
V_15 -> V_177 -- ;
F_89 ( V_137 ) ;
F_1 ( V_137 ) ;
}
}
static struct V_14 * F_111 ( struct V_55 * V_55 , struct V_179 * V_180 )
{
struct V_45 * V_46 = NULL ;
struct V_14 * V_181 = NULL ;
if ( V_180 -> V_182 ) {
V_181 = F_112 ( V_55 , V_180 -> V_182 ) ;
return V_181 ;
}
if ( V_180 -> V_183 . V_184 ) {
V_46 = F_113 ( V_55 , V_180 -> V_183 . V_184 , false ) ;
if ( ! V_46 )
return NULL ;
}
if ( ! V_46 ) {
struct V_49 * V_50 = F_114 ( V_55 ,
V_180 -> V_185 . V_184 ,
0 , 0 , 0 ) ;
if ( ! F_27 ( V_50 ) ) {
V_46 = V_50 -> V_66 . V_46 ;
F_54 ( V_50 ) ;
}
}
if ( V_46 ) {
V_180 -> V_182 = V_46 -> V_65 ;
V_181 = F_115 ( V_46 ) ;
}
return V_181 ;
}
static int F_116 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_186 )
{
struct V_23 * V_24 , * V_102 ;
int V_187 = 0 ;
V_102 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == * V_186 )
break;
V_102 = V_24 ;
}
if ( ! V_24 || V_24 -> V_33 [ V_31 ] == 0 ) {
return - V_188 ;
}
V_24 -> V_33 [ V_31 ] -- ;
if ( V_24 -> V_33 [ V_31 ] == 0 ) {
F_101 ( V_22 -> V_4 ) ;
}
if ( ! V_24 -> V_33 [ V_32 ] && ! V_24 -> V_33 [ V_35 ] ) {
#ifdef F_91
struct V_14 * V_15 = V_22 -> V_4 ;
#endif
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
V_22 -> V_42 = V_24 -> V_43 ;
#ifdef F_91
if ( V_24 -> V_189 &&
! F_59 ( V_15 ) && ! F_60 ( V_15 ) ) {
V_24 -> V_39 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_24 -> V_43 = V_22 -> V_109 ;
V_22 -> V_109 = V_24 ;
V_187 = 1 ;
} else
#endif
F_46 ( V_24 ) ;
}
return V_187 ;
}
static int F_117 ( struct V_14 * V_15 , T_1 * V_190 , int V_31 ,
int V_34 , T_1 * V_186 , int V_191 )
{
struct V_1 * V_22 ;
int V_192 = 0 ;
int V_137 , V_193 ;
if ( ! V_15 )
return - V_194 ;
F_48 () ;
F_49 (in_dev, pmc) {
if ( * V_190 == V_22 -> V_100 )
break;
}
if ( ! V_22 ) {
F_50 () ;
return - V_188 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_50 () ;
#ifdef F_91
F_118 ( V_22 ) ;
#endif
if ( ! V_191 ) {
V_193 = - V_195 ;
if ( ! V_22 -> V_34 [ V_31 ] )
goto V_196;
V_22 -> V_34 [ V_31 ] -- ;
}
V_193 = 0 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
int V_187 = F_116 ( V_22 , V_31 , & V_186 [ V_137 ] ) ;
V_192 |= V_187 > 0 ;
if ( ! V_193 && V_187 < 0 )
V_193 = V_187 ;
}
if ( V_22 -> V_31 == V_35 &&
V_22 -> V_34 [ V_35 ] == 0 &&
V_22 -> V_34 [ V_32 ] ) {
#ifdef F_91
struct V_23 * V_24 ;
#endif
V_22 -> V_31 = V_32 ;
#ifdef F_91
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_15 -> V_129 = V_22 -> V_113 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_58 ( V_22 -> V_4 ) ;
} else if ( F_119 ( V_22 ) || V_192 ) {
F_58 ( V_22 -> V_4 ) ;
#endif
}
V_196:
F_9 ( & V_22 -> V_6 ) ;
return V_193 ;
}
static int F_120 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_186 )
{
struct V_23 * V_24 , * V_102 ;
V_102 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == * V_186 )
break;
V_102 = V_24 ;
}
if ( ! V_24 ) {
V_24 = F_87 ( sizeof( * V_24 ) , V_61 ) ;
if ( ! V_24 )
return - V_197 ;
V_24 -> V_112 = * V_186 ;
if ( V_102 ) {
V_102 -> V_43 = V_24 ;
} else
V_22 -> V_42 = V_24 ;
}
V_24 -> V_33 [ V_31 ] ++ ;
if ( V_24 -> V_33 [ V_31 ] == 1 ) {
F_101 ( V_22 -> V_4 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
int V_198 = V_22 -> V_34 [ V_35 ] ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
if ( V_22 -> V_34 [ V_35 ] ) {
V_24 -> V_189 = V_198 ==
V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_24 -> V_189 = V_24 -> V_33 [ V_32 ] != 0 ;
}
static int F_119 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_199 ;
int V_198 = V_22 -> V_34 [ V_35 ] ;
int V_149 = V_22 -> V_4 -> V_131 ;
int V_200 , V_187 ;
V_187 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_22 -> V_34 [ V_35 ] ) {
V_200 = V_198 == V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_200 = V_24 -> V_33 [ V_32 ] != 0 ;
if ( V_200 ) {
if ( ! V_24 -> V_189 ) {
struct V_23 * V_201 = NULL ;
for ( V_199 = V_22 -> V_109 ; V_199 ; V_199 = V_199 -> V_43 ) {
if ( V_199 -> V_112 == V_24 -> V_112 )
break;
V_201 = V_199 ;
}
if ( V_199 ) {
if ( V_201 )
V_201 -> V_43 = V_199 -> V_43 ;
else
V_22 -> V_109 = V_199 -> V_43 ;
F_46 ( V_199 ) ;
}
V_24 -> V_39 = V_149 ;
V_187 ++ ;
}
} else if ( V_24 -> V_189 ) {
V_24 -> V_39 = 0 ;
for ( V_199 = V_22 -> V_109 ; V_199 ; V_199 = V_199 -> V_43 )
if ( V_199 -> V_112 == V_24 -> V_112 )
break;
if ( ! V_199 ) {
V_199 = F_121 ( sizeof( * V_199 ) , V_61 ) ;
if ( ! V_199 )
continue;
* V_199 = * V_24 ;
V_199 -> V_43 = V_22 -> V_109 ;
V_22 -> V_109 = V_199 ;
}
V_199 -> V_39 = V_149 ;
V_187 ++ ;
}
}
return V_187 ;
}
static int F_96 ( struct V_14 * V_15 , T_1 * V_190 , int V_31 ,
int V_34 , T_1 * V_186 , int V_191 )
{
struct V_1 * V_22 ;
int V_202 ;
int V_137 , V_193 ;
if ( ! V_15 )
return - V_194 ;
F_48 () ;
F_49 (in_dev, pmc) {
if ( * V_190 == V_22 -> V_100 )
break;
}
if ( ! V_22 ) {
F_50 () ;
return - V_188 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_50 () ;
#ifdef F_91
F_118 ( V_22 ) ;
#endif
V_202 = V_22 -> V_31 == V_35 ;
if ( ! V_191 )
V_22 -> V_34 [ V_31 ] ++ ;
V_193 = 0 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
V_193 = F_120 ( V_22 , V_31 , & V_186 [ V_137 ] ) ;
if ( V_193 )
break;
}
if ( V_193 ) {
int V_203 ;
if ( ! V_191 )
V_22 -> V_34 [ V_31 ] -- ;
for ( V_203 = 0 ; V_203 < V_137 ; V_203 ++ )
( void ) F_116 ( V_22 , V_31 , & V_186 [ V_203 ] ) ;
} else if ( V_202 != ( V_22 -> V_34 [ V_35 ] != 0 ) ) {
#ifdef F_91
struct V_23 * V_24 ;
V_15 = V_22 -> V_4 ;
#endif
if ( V_22 -> V_34 [ V_35 ] )
V_22 -> V_31 = V_35 ;
else if ( V_22 -> V_34 [ V_32 ] )
V_22 -> V_31 = V_32 ;
#ifdef F_91
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_15 -> V_129 = V_22 -> V_113 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_58 ( V_15 ) ;
} else if ( F_119 ( V_22 ) ) {
F_58 ( V_15 ) ;
#endif
}
F_9 ( & V_22 -> V_6 ) ;
return V_193 ;
}
static void F_89 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_204 ;
for ( V_24 = V_22 -> V_109 ; V_24 ; V_24 = V_204 ) {
V_204 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
V_22 -> V_109 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_204 ) {
V_204 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
V_22 -> V_42 = NULL ;
V_22 -> V_31 = V_35 ;
V_22 -> V_34 [ V_32 ] = 0 ;
V_22 -> V_34 [ V_35 ] = 1 ;
}
int F_122 ( struct V_205 * V_206 , struct V_179 * V_180 )
{
int V_193 ;
T_1 V_165 = V_180 -> V_185 . V_184 ;
struct V_207 * V_208 = NULL , * V_137 ;
struct V_14 * V_15 ;
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
int V_65 ;
int V_211 = 0 ;
if ( ! F_125 ( V_165 ) )
return - V_195 ;
F_126 () ;
V_15 = F_111 ( V_55 , V_180 ) ;
if ( ! V_15 ) {
V_208 = NULL ;
V_193 = - V_194 ;
goto V_212;
}
V_193 = - V_213 ;
V_65 = V_180 -> V_182 ;
F_95 (inet, i) {
if ( V_137 -> V_214 . V_185 . V_184 == V_165 &&
V_137 -> V_214 . V_182 == V_65 )
goto V_212;
V_211 ++ ;
}
V_193 = - V_197 ;
if ( V_211 >= V_215 )
goto V_212;
V_208 = F_127 ( V_206 , sizeof( * V_208 ) , V_168 ) ;
if ( V_208 == NULL )
goto V_212;
memcpy ( & V_208 -> V_214 , V_180 , sizeof( * V_180 ) ) ;
V_208 -> V_175 = V_210 -> V_176 ;
V_208 -> V_216 = NULL ;
V_208 -> V_31 = V_35 ;
F_100 ( V_210 -> V_176 , V_208 ) ;
F_93 ( V_15 , V_165 ) ;
V_193 = 0 ;
V_212:
F_128 () ;
return V_193 ;
}
static int F_129 ( struct V_205 * V_206 , struct V_207 * V_208 ,
struct V_14 * V_15 )
{
struct V_217 * V_24 = F_104 ( V_208 -> V_216 ) ;
int V_193 ;
if ( V_24 == NULL ) {
return F_117 ( V_15 , & V_208 -> V_214 . V_185 . V_184 ,
V_208 -> V_31 , 0 , NULL , 0 ) ;
}
V_193 = F_117 ( V_15 , & V_208 -> V_214 . V_185 . V_184 ,
V_208 -> V_31 , V_24 -> V_218 , V_24 -> V_219 , 0 ) ;
F_130 ( V_208 -> V_216 , NULL ) ;
F_131 ( F_132 ( V_24 -> V_220 ) , & V_206 -> V_221 ) ;
F_4 ( V_24 , V_5 ) ;
return V_193 ;
}
int F_133 ( struct V_205 * V_206 , struct V_179 * V_180 )
{
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_207 * V_208 ;
struct V_207 T_2 * * V_222 ;
struct V_14 * V_15 ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
T_1 V_123 = V_180 -> V_185 . V_184 ;
T_3 V_65 ;
int V_223 = - V_224 ;
F_126 () ;
V_15 = F_111 ( V_55 , V_180 ) ;
V_65 = V_180 -> V_182 ;
for ( V_222 = & V_210 -> V_176 ;
( V_208 = F_104 ( * V_222 ) ) != NULL ;
V_222 = & V_208 -> V_175 ) {
if ( V_208 -> V_214 . V_185 . V_184 != V_123 )
continue;
if ( V_65 ) {
if ( V_208 -> V_214 . V_182 != V_65 )
continue;
} else if ( V_180 -> V_183 . V_184 && V_180 -> V_183 . V_184 !=
V_208 -> V_214 . V_183 . V_184 )
continue;
( void ) F_129 ( V_206 , V_208 , V_15 ) ;
* V_222 = V_208 -> V_175 ;
if ( V_15 )
F_103 ( V_15 , V_123 ) ;
F_128 () ;
F_131 ( sizeof( * V_208 ) , & V_206 -> V_221 ) ;
F_4 ( V_208 , V_5 ) ;
return 0 ;
}
if ( ! V_15 )
V_223 = - V_194 ;
F_128 () ;
return V_223 ;
}
int F_134 ( int V_225 , int V_226 , struct V_205 * V_206 , struct
V_227 * V_228 , int V_65 )
{
int V_193 ;
struct V_179 V_180 ;
T_1 V_165 = V_228 -> V_185 ;
struct V_207 * V_22 ;
struct V_14 * V_15 = NULL ;
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_217 * V_229 ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
int V_230 = 0 ;
int V_137 , V_203 , V_187 ;
if ( ! F_125 ( V_165 ) )
return - V_195 ;
F_126 () ;
V_180 . V_185 . V_184 = V_228 -> V_185 ;
V_180 . V_183 . V_184 = V_228 -> V_231 ;
V_180 . V_182 = V_65 ;
V_15 = F_111 ( V_55 , & V_180 ) ;
if ( ! V_15 ) {
V_193 = - V_194 ;
goto V_212;
}
V_193 = - V_224 ;
F_95 (inet, pmc) {
if ( ( V_22 -> V_214 . V_185 . V_184 ==
V_180 . V_185 . V_184 ) &&
( V_22 -> V_214 . V_182 == V_180 . V_182 ) )
break;
}
if ( ! V_22 ) {
V_193 = - V_195 ;
goto V_212;
}
if ( V_22 -> V_216 ) {
if ( V_22 -> V_31 != V_226 ) {
V_193 = - V_195 ;
goto V_212;
}
} else if ( V_22 -> V_31 != V_226 ) {
F_96 ( V_15 , & V_228 -> V_185 , V_226 , 0 , NULL , 0 ) ;
F_117 ( V_15 , & V_228 -> V_185 , V_22 -> V_31 , 0 ,
NULL , 0 ) ;
V_22 -> V_31 = V_226 ;
}
V_229 = F_104 ( V_22 -> V_216 ) ;
if ( ! V_225 ) {
if ( ! V_229 )
goto V_212;
V_187 = ! 0 ;
for ( V_137 = 0 ; V_137 < V_229 -> V_218 ; V_137 ++ ) {
V_187 = memcmp ( & V_229 -> V_219 [ V_137 ] , & V_228 -> V_232 ,
sizeof( T_1 ) ) ;
if ( V_187 == 0 )
break;
}
if ( V_187 )
goto V_212;
if ( V_229 -> V_218 == 1 && V_226 == V_32 ) {
V_230 = 1 ;
goto V_212;
}
F_117 ( V_15 , & V_228 -> V_185 , V_226 , 1 ,
& V_228 -> V_232 , 1 ) ;
for ( V_203 = V_137 + 1 ; V_203 < V_229 -> V_218 ; V_203 ++ )
V_229 -> V_219 [ V_203 - 1 ] = V_229 -> V_219 [ V_203 ] ;
V_229 -> V_218 -- ;
V_193 = 0 ;
goto V_212;
}
if ( V_229 && V_229 -> V_218 >= V_233 ) {
V_193 = - V_197 ;
goto V_212;
}
if ( ! V_229 || V_229 -> V_218 == V_229 -> V_220 ) {
struct V_217 * V_234 ;
int V_211 = V_235 ;
if ( V_229 )
V_211 += V_229 -> V_220 ;
V_234 = F_127 ( V_206 , F_132 ( V_211 ) , V_168 ) ;
if ( ! V_234 ) {
V_193 = - V_197 ;
goto V_212;
}
V_234 -> V_220 = V_211 ;
V_234 -> V_218 = V_211 - V_235 ;
if ( V_229 ) {
for ( V_137 = 0 ; V_137 < V_229 -> V_218 ; V_137 ++ )
V_234 -> V_219 [ V_137 ] = V_229 -> V_219 [ V_137 ] ;
F_131 ( F_132 ( V_229 -> V_220 ) , & V_206 -> V_221 ) ;
F_4 ( V_229 , V_5 ) ;
}
F_100 ( V_22 -> V_216 , V_234 ) ;
V_229 = V_234 ;
}
V_187 = 1 ;
for ( V_137 = 0 ; V_137 < V_229 -> V_218 ; V_137 ++ ) {
V_187 = memcmp ( & V_229 -> V_219 [ V_137 ] , & V_228 -> V_232 ,
sizeof( T_1 ) ) ;
if ( V_187 == 0 )
break;
}
if ( V_187 == 0 )
goto V_212;
for ( V_203 = V_229 -> V_218 - 1 ; V_203 >= V_137 ; V_203 -- )
V_229 -> V_219 [ V_203 + 1 ] = V_229 -> V_219 [ V_203 ] ;
V_229 -> V_219 [ V_137 ] = V_228 -> V_232 ;
V_229 -> V_218 ++ ;
V_193 = 0 ;
F_96 ( V_15 , & V_228 -> V_185 , V_226 , 1 ,
& V_228 -> V_232 , 1 ) ;
V_212:
F_128 () ;
if ( V_230 )
return F_133 ( V_206 , & V_180 ) ;
return V_193 ;
}
int F_135 ( struct V_205 * V_206 , struct V_236 * V_237 , int V_65 )
{
int V_193 = 0 ;
struct V_179 V_180 ;
T_1 V_165 = V_237 -> V_238 ;
struct V_207 * V_22 ;
struct V_14 * V_15 ;
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_217 * V_234 , * V_229 ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
int V_230 = 0 ;
if ( ! F_125 ( V_165 ) )
return - V_195 ;
if ( V_237 -> V_239 != V_32 &&
V_237 -> V_239 != V_35 )
return - V_195 ;
F_126 () ;
V_180 . V_185 . V_184 = V_237 -> V_238 ;
V_180 . V_183 . V_184 = V_237 -> V_240 ;
V_180 . V_182 = V_65 ;
V_15 = F_111 ( V_55 , & V_180 ) ;
if ( ! V_15 ) {
V_193 = - V_194 ;
goto V_212;
}
if ( V_237 -> V_239 == V_32 && V_237 -> V_241 == 0 ) {
V_230 = 1 ;
goto V_212;
}
F_95 (inet, pmc) {
if ( V_22 -> V_214 . V_185 . V_184 == V_237 -> V_238 &&
V_22 -> V_214 . V_182 == V_180 . V_182 )
break;
}
if ( ! V_22 ) {
V_193 = - V_195 ;
goto V_212;
}
if ( V_237 -> V_241 ) {
V_234 = F_127 ( V_206 , F_132 ( V_237 -> V_241 ) ,
V_168 ) ;
if ( ! V_234 ) {
V_193 = - V_197 ;
goto V_212;
}
V_234 -> V_220 = V_234 -> V_218 = V_237 -> V_241 ;
memcpy ( V_234 -> V_219 , V_237 -> V_242 ,
V_237 -> V_241 * sizeof( V_237 -> V_242 [ 0 ] ) ) ;
V_193 = F_96 ( V_15 , & V_237 -> V_238 ,
V_237 -> V_239 , V_234 -> V_218 , V_234 -> V_219 , 0 ) ;
if ( V_193 ) {
F_136 ( V_206 , V_234 , F_132 ( V_234 -> V_220 ) ) ;
goto V_212;
}
} else {
V_234 = NULL ;
( void ) F_96 ( V_15 , & V_237 -> V_238 ,
V_237 -> V_239 , 0 , NULL , 0 ) ;
}
V_229 = F_104 ( V_22 -> V_216 ) ;
if ( V_229 ) {
( void ) F_117 ( V_15 , & V_237 -> V_238 , V_22 -> V_31 ,
V_229 -> V_218 , V_229 -> V_219 , 0 ) ;
F_131 ( F_132 ( V_229 -> V_220 ) , & V_206 -> V_221 ) ;
F_4 ( V_229 , V_5 ) ;
} else
( void ) F_117 ( V_15 , & V_237 -> V_238 , V_22 -> V_31 ,
0 , NULL , 0 ) ;
F_100 ( V_22 -> V_216 , V_234 ) ;
V_22 -> V_31 = V_237 -> V_239 ;
V_193 = 0 ;
V_212:
F_128 () ;
if ( V_230 )
V_193 = F_133 ( V_206 , & V_180 ) ;
return V_193 ;
}
int F_137 ( struct V_205 * V_206 , struct V_236 * V_237 ,
struct V_236 T_4 * V_243 , int T_4 * V_244 )
{
int V_193 , V_138 , V_211 , V_245 ;
struct V_179 V_180 ;
T_1 V_165 = V_237 -> V_238 ;
struct V_207 * V_22 ;
struct V_14 * V_15 ;
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_217 * V_229 ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
if ( ! F_125 ( V_165 ) )
return - V_195 ;
F_126 () ;
V_180 . V_185 . V_184 = V_237 -> V_238 ;
V_180 . V_183 . V_184 = V_237 -> V_240 ;
V_180 . V_182 = 0 ;
V_15 = F_111 ( V_55 , & V_180 ) ;
if ( ! V_15 ) {
V_193 = - V_194 ;
goto V_212;
}
V_193 = - V_224 ;
F_95 (inet, pmc) {
if ( V_22 -> V_214 . V_185 . V_184 == V_237 -> V_238 &&
V_22 -> V_214 . V_182 == V_180 . V_182 )
break;
}
if ( ! V_22 )
goto V_212;
V_237 -> V_239 = V_22 -> V_31 ;
V_229 = F_104 ( V_22 -> V_216 ) ;
F_128 () ;
if ( ! V_229 ) {
V_138 = 0 ;
V_211 = 0 ;
} else {
V_211 = V_229 -> V_218 ;
}
V_245 = V_211 < V_237 -> V_241 ? V_211 : V_237 -> V_241 ;
V_138 = V_245 * sizeof( V_229 -> V_219 [ 0 ] ) ;
V_237 -> V_241 = V_211 ;
if ( F_138 ( F_139 ( V_245 ) , V_244 ) ||
F_140 ( V_243 , V_237 , F_139 ( 0 ) ) ) {
return - V_246 ;
}
if ( V_138 &&
F_140 ( & V_243 -> V_242 [ 0 ] , V_229 -> V_219 , V_138 ) )
return - V_246 ;
return 0 ;
V_212:
F_128 () ;
return V_193 ;
}
int F_141 ( struct V_205 * V_206 , struct V_247 * V_248 ,
struct V_247 T_4 * V_243 , int T_4 * V_244 )
{
int V_193 , V_137 , V_211 , V_245 ;
struct V_249 * V_250 ;
T_1 V_165 ;
struct V_207 * V_22 ;
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_217 * V_229 ;
V_250 = (struct V_249 * ) & V_248 -> V_251 ;
if ( V_250 -> V_252 != V_253 )
return - V_195 ;
V_165 = V_250 -> V_254 . V_184 ;
if ( ! F_125 ( V_165 ) )
return - V_195 ;
F_126 () ;
V_193 = - V_224 ;
F_95 (inet, pmc) {
if ( V_22 -> V_214 . V_185 . V_184 == V_165 &&
V_22 -> V_214 . V_182 == V_248 -> V_255 )
break;
}
if ( ! V_22 )
goto V_212;
V_248 -> V_256 = V_22 -> V_31 ;
V_229 = F_104 ( V_22 -> V_216 ) ;
F_128 () ;
V_211 = V_229 ? V_229 -> V_218 : 0 ;
V_245 = V_211 < V_248 -> V_257 ? V_211 : V_248 -> V_257 ;
V_248 -> V_257 = V_211 ;
if ( F_138 ( F_142 ( V_245 ) , V_244 ) ||
F_140 ( V_243 , V_248 , F_142 ( 0 ) ) ) {
return - V_246 ;
}
for ( V_137 = 0 ; V_137 < V_245 ; V_137 ++ ) {
struct V_258 V_259 ;
V_250 = (struct V_249 * ) & V_259 ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_250 -> V_252 = V_253 ;
V_250 -> V_254 . V_184 = V_229 -> V_219 [ V_137 ] ;
if ( F_140 ( & V_243 -> V_260 [ V_137 ] , & V_259 , sizeof( V_259 ) ) )
return - V_246 ;
}
return 0 ;
V_212:
F_128 () ;
return V_193 ;
}
int F_143 ( struct V_205 * V_206 , T_1 V_261 , T_1 V_262 , int V_263 )
{
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_207 * V_22 ;
struct V_217 * V_229 ;
int V_137 ;
int V_223 ;
V_223 = 1 ;
if ( ! F_125 ( V_261 ) )
goto V_174;
F_48 () ;
F_49 (inet, pmc) {
if ( V_22 -> V_214 . V_185 . V_184 == V_261 &&
V_22 -> V_214 . V_182 == V_263 )
break;
}
V_223 = V_210 -> V_264 ;
if ( ! V_22 )
goto V_265;
V_229 = F_144 ( V_22 -> V_216 ) ;
V_223 = ( V_22 -> V_31 == V_35 ) ;
if ( ! V_229 )
goto V_265;
for ( V_137 = 0 ; V_137 < V_229 -> V_218 ; V_137 ++ ) {
if ( V_229 -> V_219 [ V_137 ] == V_262 )
break;
}
V_223 = 0 ;
if ( V_22 -> V_31 == V_32 && V_137 >= V_229 -> V_218 )
goto V_265;
if ( V_22 -> V_31 == V_35 && V_137 < V_229 -> V_218 )
goto V_265;
V_223 = 1 ;
V_265:
F_50 () ;
V_174:
return V_223 ;
}
void F_145 ( struct V_205 * V_206 )
{
struct V_209 * V_210 = F_123 ( V_206 ) ;
struct V_207 * V_208 ;
struct V_55 * V_55 = F_124 ( V_206 ) ;
if ( V_210 -> V_176 == NULL )
return;
F_126 () ;
while ( ( V_208 = F_104 ( V_210 -> V_176 ) ) != NULL ) {
struct V_14 * V_15 ;
V_210 -> V_176 = V_208 -> V_175 ;
V_15 = F_112 ( V_55 , V_208 -> V_214 . V_182 ) ;
( void ) F_129 ( V_206 , V_208 , V_15 ) ;
if ( V_15 != NULL )
F_103 ( V_15 , V_208 -> V_214 . V_185 . V_184 ) ;
F_131 ( sizeof( * V_208 ) , & V_206 -> V_221 ) ;
F_4 ( V_208 , V_5 ) ;
}
F_128 () ;
}
int F_146 ( struct V_14 * V_15 , T_1 V_266 , T_1 V_267 , T_5 V_268 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_187 = 0 ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_266 )
break;
}
if ( V_2 && V_268 == V_64 ) {
V_187 = 1 ;
} else if ( V_2 ) {
if ( V_267 ) {
for ( V_24 = V_2 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == V_267 )
break;
}
if ( V_24 )
V_187 = V_24 -> V_33 [ V_32 ] ||
V_24 -> V_33 [ V_35 ] !=
V_2 -> V_34 [ V_35 ] ;
else
V_187 = V_2 -> V_34 [ V_35 ] != 0 ;
} else
V_187 = 1 ;
}
return V_187 ;
}
static inline struct V_1 * F_147 ( struct V_269 * V_270 )
{
struct V_55 * V_55 = F_148 ( V_270 ) ;
struct V_1 * V_2 = NULL ;
struct V_271 * V_272 = F_149 ( V_270 ) ;
V_272 -> V_15 = NULL ;
F_150 (net, state->dev) {
struct V_14 * V_15 ;
V_15 = F_73 ( V_272 -> V_46 ) ;
if ( ! V_15 )
continue;
V_2 = F_144 ( V_15 -> V_176 ) ;
if ( V_2 ) {
V_272 -> V_15 = V_15 ;
break;
}
}
return V_2 ;
}
static struct V_1 * F_151 ( struct V_269 * V_270 , struct V_1 * V_2 )
{
struct V_271 * V_272 = F_149 ( V_270 ) ;
V_2 = F_144 ( V_2 -> V_175 ) ;
while ( ! V_2 ) {
V_272 -> V_46 = F_152 ( V_272 -> V_46 ) ;
if ( ! V_272 -> V_46 ) {
V_272 -> V_15 = NULL ;
break;
}
V_272 -> V_15 = F_73 ( V_272 -> V_46 ) ;
if ( ! V_272 -> V_15 )
continue;
V_2 = F_144 ( V_272 -> V_15 -> V_176 ) ;
}
return V_2 ;
}
static struct V_1 * F_153 ( struct V_269 * V_270 , T_6 V_273 )
{
struct V_1 * V_2 = F_147 ( V_270 ) ;
if ( V_2 )
while ( V_273 && ( V_2 = F_151 ( V_270 , V_2 ) ) != NULL )
-- V_273 ;
return V_273 ? NULL : V_2 ;
}
static void * F_154 ( struct V_269 * V_270 , T_6 * V_273 )
__acquires( V_5 )
{
F_48 () ;
return * V_273 ? F_153 ( V_270 , * V_273 - 1 ) : V_274 ;
}
static void * F_155 ( struct V_269 * V_270 , void * V_275 , T_6 * V_273 )
{
struct V_1 * V_2 ;
if ( V_275 == V_274 )
V_2 = F_147 ( V_270 ) ;
else
V_2 = F_151 ( V_270 , V_275 ) ;
++ * V_273 ;
return V_2 ;
}
static void F_156 ( struct V_269 * V_270 , void * V_275 )
__releases( V_5 )
{
struct V_271 * V_272 = F_149 ( V_270 ) ;
V_272 -> V_15 = NULL ;
V_272 -> V_46 = NULL ;
F_50 () ;
}
static int F_157 ( struct V_269 * V_270 , void * V_275 )
{
if ( V_275 == V_274 )
F_158 ( V_270 ,
L_1 ) ;
else {
struct V_1 * V_2 = (struct V_1 * ) V_275 ;
struct V_271 * V_272 = F_149 ( V_270 ) ;
char * V_276 ;
long V_191 ;
#ifdef F_91
V_276 = F_59 ( V_272 -> V_15 ) ? L_2 :
F_60 ( V_272 -> V_15 ) ? L_3 :
L_4 ;
#else
V_276 = L_5 ;
#endif
if ( F_144 ( V_272 -> V_15 -> V_176 ) == V_2 ) {
F_159 ( V_270 , L_6 ,
V_272 -> V_46 -> V_65 , V_272 -> V_46 -> V_277 , V_272 -> V_15 -> V_177 , V_276 ) ;
}
V_191 = V_2 -> V_7 . V_21 - V_13 ;
F_159 ( V_270 ,
L_7 ,
V_2 -> V_100 , V_2 -> V_173 ,
V_2 -> V_8 ,
V_2 -> V_8 ? F_160 ( V_191 ) : 0 ,
V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_161 ( struct V_278 * V_278 , struct V_279 * V_279 )
{
return F_162 ( V_278 , V_279 , & V_280 ,
sizeof( struct V_271 ) ) ;
}
static inline struct V_23 * F_163 ( struct V_269 * V_270 )
{
struct V_55 * V_55 = F_148 ( V_270 ) ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_281 * V_272 = F_164 ( V_270 ) ;
V_272 -> V_181 = NULL ;
V_272 -> V_2 = NULL ;
F_150 (net, state->dev) {
struct V_14 * V_181 ;
V_181 = F_73 ( V_272 -> V_46 ) ;
if ( F_165 ( V_181 == NULL ) )
continue;
V_2 = F_144 ( V_181 -> V_176 ) ;
if ( F_166 ( V_2 != NULL ) ) {
F_6 ( & V_2 -> V_6 ) ;
V_24 = V_2 -> V_42 ;
if ( F_166 ( V_24 != NULL ) ) {
V_272 -> V_2 = V_2 ;
V_272 -> V_181 = V_181 ;
break;
}
F_9 ( & V_2 -> V_6 ) ;
}
}
return V_24 ;
}
static struct V_23 * F_167 ( struct V_269 * V_270 , struct V_23 * V_24 )
{
struct V_281 * V_272 = F_164 ( V_270 ) ;
V_24 = V_24 -> V_43 ;
while ( ! V_24 ) {
F_9 ( & V_272 -> V_2 -> V_6 ) ;
V_272 -> V_2 = V_272 -> V_2 -> V_120 ;
while ( ! V_272 -> V_2 ) {
V_272 -> V_46 = F_152 ( V_272 -> V_46 ) ;
if ( ! V_272 -> V_46 ) {
V_272 -> V_181 = NULL ;
goto V_174;
}
V_272 -> V_181 = F_73 ( V_272 -> V_46 ) ;
if ( ! V_272 -> V_181 )
continue;
V_272 -> V_2 = F_144 ( V_272 -> V_181 -> V_176 ) ;
}
if ( ! V_272 -> V_2 )
break;
F_6 ( & V_272 -> V_2 -> V_6 ) ;
V_24 = V_272 -> V_2 -> V_42 ;
}
V_174:
return V_24 ;
}
static struct V_23 * F_168 ( struct V_269 * V_270 , T_6 V_273 )
{
struct V_23 * V_24 = F_163 ( V_270 ) ;
if ( V_24 )
while ( V_273 && ( V_24 = F_167 ( V_270 , V_24 ) ) != NULL )
-- V_273 ;
return V_273 ? NULL : V_24 ;
}
static void * F_169 ( struct V_269 * V_270 , T_6 * V_273 )
__acquires( V_5 )
{
F_48 () ;
return * V_273 ? F_168 ( V_270 , * V_273 - 1 ) : V_274 ;
}
static void * F_170 ( struct V_269 * V_270 , void * V_275 , T_6 * V_273 )
{
struct V_23 * V_24 ;
if ( V_275 == V_274 )
V_24 = F_163 ( V_270 ) ;
else
V_24 = F_167 ( V_270 , V_275 ) ;
++ * V_273 ;
return V_24 ;
}
static void F_171 ( struct V_269 * V_270 , void * V_275 )
__releases( V_5 )
{
struct V_281 * V_272 = F_164 ( V_270 ) ;
if ( F_166 ( V_272 -> V_2 != NULL ) ) {
F_9 ( & V_272 -> V_2 -> V_6 ) ;
V_272 -> V_2 = NULL ;
}
V_272 -> V_181 = NULL ;
V_272 -> V_46 = NULL ;
F_50 () ;
}
static int F_172 ( struct V_269 * V_270 , void * V_275 )
{
struct V_23 * V_24 = (struct V_23 * ) V_275 ;
struct V_281 * V_272 = F_164 ( V_270 ) ;
if ( V_275 == V_274 ) {
F_159 ( V_270 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_159 ( V_270 ,
L_16
L_17 ,
V_272 -> V_46 -> V_65 , V_272 -> V_46 -> V_277 ,
F_173 ( V_272 -> V_2 -> V_100 ) ,
F_173 ( V_24 -> V_112 ) ,
V_24 -> V_33 [ V_32 ] ,
V_24 -> V_33 [ V_35 ] ) ;
}
return 0 ;
}
static int F_174 ( struct V_278 * V_278 , struct V_279 * V_279 )
{
return F_162 ( V_278 , V_279 , & V_282 ,
sizeof( struct V_281 ) ) ;
}
static int T_7 F_175 ( struct V_55 * V_55 )
{
struct V_283 * V_284 ;
V_284 = F_176 ( V_55 , L_18 , V_285 , & V_286 ) ;
if ( ! V_284 )
goto V_287;
V_284 = F_176 ( V_55 , L_19 , V_285 , & V_288 ) ;
if ( ! V_284 )
goto V_289;
return 0 ;
V_289:
F_177 ( V_55 , L_18 ) ;
V_287:
return - V_290 ;
}
static void T_8 F_178 ( struct V_55 * V_55 )
{
F_177 ( V_55 , L_19 ) ;
F_177 ( V_55 , L_18 ) ;
}
int T_9 F_179 ( void )
{
return F_180 ( & V_291 ) ;
}
