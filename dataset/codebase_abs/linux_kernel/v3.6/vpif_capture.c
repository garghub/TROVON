static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
F_3 ( 2 , V_13 , L_1 ) ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_2 -> V_15 != V_16 &&
V_2 -> V_15 != V_17 ) {
F_4 ( V_2 , 0 , V_11 -> V_18 . V_18 . V_19 . V_20 ) ;
if ( F_5 ( V_2 , 0 ) &&
F_6 ( V_2 , 0 ) > F_7 ( V_2 , 0 ) )
goto exit;
V_12 = F_8 ( V_2 , 0 ) ;
if ( V_6 -> V_21 ) {
if ( ! F_9 ( ( V_12 + V_11 -> V_22 ) , 8 ) ||
! F_9 ( ( V_12 + V_11 -> V_23 ) , 8 ) ||
! F_9 ( ( V_12 + V_11 -> V_24 ) , 8 ) ||
! F_9 ( ( V_12 + V_11 -> V_25 ) , 8 ) )
goto exit;
}
}
return 0 ;
exit:
F_3 ( 1 , V_13 , L_2 ) ;
return - V_26 ;
}
static int F_10 ( struct V_5 * V_27 ,
const struct V_28 * V_18 ,
unsigned int * V_29 , unsigned int * V_30 ,
unsigned int V_31 [] , void * V_32 [] )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_33 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_3 ) ;
if ( V_34 == V_11 -> V_35 ) {
V_33 = V_36 . V_37 [ V_8 -> V_38 ] ;
if ( V_8 -> V_39 . V_40 . V_41 == 0 ) {
if ( V_36 . V_42 [ V_8 -> V_38 ] )
while ( V_33 * * V_29 >
( V_36 . V_42 [ 0 ]
+ V_36 . V_42 [ 1 ] ) )
( * V_29 ) -- ;
} else {
if ( V_36 . V_42 [ V_8 -> V_38 ] )
while ( V_33 * * V_29 >
V_36 . V_42 [ V_8 -> V_38 ] )
( * V_29 ) -- ;
}
} else {
V_33 = V_11 -> V_18 . V_18 . V_19 . V_20 ;
}
if ( * V_29 < V_36 . V_43 )
* V_29 = V_36 . V_43 ;
* V_30 = 1 ;
V_31 [ 0 ] = V_33 ;
V_32 [ 0 ] = V_11 -> V_44 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_45 * V_46 = F_12 ( V_2 ,
struct V_45 , V_2 ) ;
struct V_10 * V_11 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_4 ) ;
F_13 ( & V_46 -> V_47 , & V_11 -> V_48 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_45 * V_46 = F_12 ( V_2 ,
struct V_45 , V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_49 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_15 ( & V_11 -> V_50 , V_49 ) ;
if ( V_2 -> V_15 == V_16 )
F_16 ( & V_46 -> V_47 ) ;
F_17 ( & V_11 -> V_50 , V_49 ) ;
}
static void F_18 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_19 ( & V_11 -> V_51 ) ;
}
static void F_20 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_12 ( V_2 ,
struct V_45 , V_2 ) ;
F_23 ( & V_46 -> V_47 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_27 , unsigned int V_52 )
{
struct V_53 * V_54 =
V_55 -> V_56 ;
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_57 * V_58 = & V_8 -> V_39 ;
unsigned long V_12 = 0 ;
int V_59 ;
if ( F_25 ( & V_11 -> V_48 ) ) {
F_3 ( 1 , V_13 , L_5 ) ;
return - V_60 ;
}
V_11 -> V_61 = V_11 -> V_62 = F_26 ( V_11 -> V_48 . V_63 ,
struct V_45 , V_47 ) ;
F_27 ( & V_11 -> V_61 -> V_47 ) ;
V_11 -> V_61 -> V_2 . V_15 = V_16 ;
V_8 -> V_64 = 0 ;
V_11 -> V_65 = 1 ;
V_12 = F_8 ( & V_11 -> V_61 -> V_2 , 0 ) ;
F_28 ( V_8 ) ;
if ( ( V_58 -> V_40 . V_66 &&
( ( V_11 -> V_18 . V_18 . V_19 . V_67 != V_68 ) &&
( V_11 -> V_18 . V_18 . V_19 . V_67 != V_69 ) ) ) ||
( ! V_58 -> V_40 . V_66 &&
( V_11 -> V_18 . V_18 . V_19 . V_67 == V_68 ) ) ) {
F_3 ( 1 , V_13 , L_6 ) ;
return - V_26 ;
}
V_59 = V_54 -> V_70
( V_58 -> V_40 . V_41 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_7 ) ;
return V_59 ;
}
V_59 = F_29 ( V_58 , V_8 -> V_38 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_8 ) ;
return V_59 ;
}
V_11 -> V_65 = V_59 ;
F_30 ( V_8 , V_59 ) ;
V_11 -> V_71 ( V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ,
V_12 + V_11 -> V_24 ,
V_12 + V_11 -> V_25 ) ;
if ( ( V_72 == V_8 -> V_38 ) ) {
F_31 () ;
F_32 ( 1 ) ;
F_33 ( 1 ) ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( V_11 -> V_65 == 2 ) ) {
F_34 () ;
F_35 ( 1 ) ;
F_36 ( 1 ) ;
}
V_74 [ V_14 ] [ V_8 -> V_38 ] = 1 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
if ( ! F_38 ( V_27 ) )
return 0 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
while ( ! F_25 ( & V_11 -> V_48 ) ) {
V_11 -> V_62 = F_26 ( V_11 -> V_48 . V_63 ,
struct V_45 , V_47 ) ;
F_27 ( & V_11 -> V_62 -> V_47 ) ;
F_39 ( & V_11 -> V_62 -> V_2 , V_75 ) ;
}
return 0 ;
}
static void F_40 ( struct V_10 * V_11 )
{
F_41 ( & V_11 -> V_61 -> V_2 . V_76 . V_77 ) ;
F_39 ( & V_11 -> V_61 -> V_2 ,
V_78 ) ;
V_11 -> V_61 = V_11 -> V_62 ;
}
static void F_42 ( struct V_10 * V_11 )
{
unsigned long V_12 = 0 ;
V_11 -> V_62 = F_26 ( V_11 -> V_48 . V_63 ,
struct V_45 , V_47 ) ;
F_27 ( & V_11 -> V_62 -> V_47 ) ;
V_11 -> V_62 -> V_2 . V_15 = V_16 ;
V_12 = F_8 ( & V_11 -> V_62 -> V_2 , 0 ) ;
V_11 -> V_71 ( V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ,
V_12 + V_11 -> V_24 ,
V_12 + V_11 -> V_25 ) ;
}
static T_1 F_43 ( int V_79 , void * V_80 )
{
struct V_81 * V_82 = & V_83 ;
struct V_10 * V_11 ;
struct V_7 * V_8 ;
enum V_84 V_67 ;
int V_38 = 0 ;
int V_85 = - 1 , V_86 ;
V_38 = * ( int * ) ( V_80 ) ;
if ( ! F_44 ( V_38 ) )
return V_87 ;
V_8 = V_82 -> V_82 [ V_38 ] ;
V_67 = V_8 -> V_11 [ V_14 ] . V_18 . V_18 . V_19 . V_67 ;
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ ) {
V_11 = & V_8 -> V_11 [ V_86 ] ;
if ( 0 == V_11 -> V_65 )
continue;
if ( 1 == V_8 -> V_39 . V_40 . V_66 ) {
if ( F_25 ( & V_11 -> V_48 ) )
continue;
if ( ! V_74 [ V_86 ] [ V_38 ] )
F_40 ( V_11 ) ;
V_74 [ V_86 ] [ V_38 ] = 0 ;
F_42 ( V_11 ) ;
V_74 [ V_86 ] [ V_38 ] = 0 ;
} else {
if ( V_74 [ V_86 ] [ V_38 ] ) {
V_74 [ V_86 ] [ V_38 ] = 0 ;
continue;
}
if ( 0 == V_86 ) {
V_8 -> V_64 ^= 1 ;
V_85 = F_45 ( V_8 -> V_38 ) ;
if ( V_85 != V_8 -> V_64 ) {
if ( 0 == V_85 )
V_8 -> V_64 = V_85 ;
return V_89 ;
}
}
if ( 0 == V_85 ) {
if ( V_11 -> V_61 == V_11 -> V_62 )
continue;
F_40 ( V_11 ) ;
} else if ( 1 == V_85 ) {
if ( F_25 ( & V_11 -> V_48 ) ||
( V_11 -> V_61 != V_11 -> V_62 ) )
continue;
F_42 ( V_11 ) ;
}
}
}
return V_89 ;
}
static int F_46 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_57 * V_39 = & V_8 -> V_39 ;
const struct V_90 * V_91 ;
struct V_90 * V_40 = & V_39 -> V_40 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
int V_95 ;
F_3 ( 2 , V_13 , L_9 ) ;
for ( V_95 = 0 ; V_95 < V_96 ; V_95 ++ ) {
V_91 = & V_97 [ V_95 ] ;
if ( V_91 -> V_98 == 0 ) {
F_3 ( 2 , V_13 , L_10 ) ;
if ( V_91 -> V_99 & V_93 -> V_99 ) {
memcpy ( V_40 , V_91 , sizeof( * V_91 ) ) ;
break;
}
} else {
F_3 ( 2 , V_13 , L_11 ) ;
if ( V_91 -> V_100 == V_93 -> V_100 ) {
memcpy ( V_40 , V_91 , sizeof( * V_91 ) ) ;
break;
}
}
}
if ( V_95 == V_96 )
return - V_26 ;
V_11 -> V_18 . V_18 . V_19 . V_101 = V_40 -> V_101 ;
V_11 -> V_101 = V_40 -> V_101 ;
V_11 -> V_18 . V_18 . V_19 . V_102 = V_40 -> V_102 ;
V_11 -> V_102 = V_40 -> V_102 ;
V_11 -> V_18 . V_18 . V_19 . V_103 = V_40 -> V_101 ;
V_39 -> V_104 . V_105 = V_40 -> V_101 ;
V_39 -> V_104 . V_106 = V_40 -> V_66 ;
return 0 ;
}
static void F_28 ( struct V_7 * V_8 )
{
unsigned int V_105 , V_107 , V_20 ;
struct V_92 * V_93 = & ( V_8 -> V_94 ) ;
struct V_57 * V_39 = & V_8 -> V_39 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
enum V_84 V_67 = V_11 -> V_18 . V_18 . V_19 . V_67 ;
F_3 ( 2 , V_13 , L_12 ) ;
if ( V_69 == V_67 ) {
if ( V_39 -> V_40 . V_66 )
V_93 -> V_108 = V_68 ;
else
V_93 -> V_108 = V_109 ;
} else
V_93 -> V_108 = V_11 -> V_18 . V_18 . V_19 . V_67 ;
V_20 = V_11 -> V_18 . V_18 . V_19 . V_20 ;
V_105 = V_11 -> V_18 . V_18 . V_19 . V_103 ;
V_107 = V_20 / ( V_105 * 2 ) ;
if ( ( V_68 == V_93 -> V_108 ) ||
( V_109 == V_93 -> V_108 ) ) {
V_11 -> V_22 = 0 ;
V_11 -> V_23 = V_105 ;
V_11 -> V_24 = V_20 / 2 ;
V_11 -> V_25 = V_20 / 2 + V_105 ;
} else if ( V_110 == V_93 -> V_108 ) {
V_11 -> V_22 = 0 ;
V_11 -> V_23 = V_20 / 4 ;
V_11 -> V_24 = V_20 / 2 ;
V_11 -> V_25 = V_11 -> V_24 + V_20 / 4 ;
} else if ( V_111 == V_93 -> V_108 ) {
V_11 -> V_23 = 0 ;
V_11 -> V_22 = V_20 / 4 ;
V_11 -> V_25 = V_20 / 2 ;
V_11 -> V_24 = V_11 -> V_25 + V_20 / 4 ;
}
if ( ( V_68 == V_93 -> V_108 ) ||
( V_109 == V_93 -> V_108 ) )
V_39 -> V_104 . V_106 = 1 ;
else
V_39 -> V_104 . V_106 = 0 ;
if ( 1 == V_39 -> V_40 . V_66 )
V_39 -> V_104 . V_105 =
V_11 -> V_18 . V_18 . V_19 . V_103 ;
else {
if ( ( V_67 == V_69 )
|| ( V_67 == V_109 ) )
V_39 -> V_104 . V_105 =
V_11 -> V_18 . V_18 . V_19 . V_103 * 2 ;
else
V_39 -> V_104 . V_105 =
V_11 -> V_18 . V_18 . V_19 . V_103 ;
}
V_8 -> V_39 . V_104 . V_99 = V_39 -> V_40 . V_99 ;
}
static void F_47 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_13 ) ;
V_11 -> V_18 . V_18 . V_19 . V_67 = V_69 ;
if ( V_36 . V_112 [ V_8 -> V_38 ] == 0 )
V_11 -> V_35 = V_113 ;
else
V_11 -> V_35 = V_34 ;
V_11 -> V_18 . V_18 . V_19 . V_20
= V_36 . V_37 [ V_8 -> V_38 ] ;
if ( V_8 -> V_39 . V_114 . V_115 == V_116 )
V_11 -> V_18 . V_18 . V_19 . V_117 = V_118 ;
else
V_11 -> V_18 . V_18 . V_19 . V_117 = V_119 ;
V_11 -> V_18 . type = V_120 ;
}
static inline enum V_84 F_48 (
struct V_121 * V_114 )
{
return ( V_114 -> V_115 == V_116 ) ? V_68 :
V_109 ;
}
static int F_49 ( struct V_7 * V_8 ,
struct V_122 * V_123 ,
int V_124 )
{
struct V_10 * V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
struct V_57 * V_57 = & V_8 -> V_39 ;
enum V_84 V_67 = V_123 -> V_67 ;
T_2 V_20 , V_105 , V_107 ;
int V_59 = - V_26 ;
F_3 ( 2 , V_13 , L_14 ) ;
if ( V_57 -> V_114 . V_115 == V_116 ) {
if ( V_123 -> V_117 != V_118 ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_15 ) ;
goto exit;
}
V_123 -> V_117 = V_118 ;
}
} else {
if ( V_123 -> V_117 != V_119 ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_16 ) ;
goto exit;
}
V_123 -> V_117 = V_119 ;
}
}
if ( ! ( F_50 ( V_67 ) ) ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_17 ) ;
goto exit;
}
V_67 = F_48 ( & V_57 -> V_114 ) ;
} else if ( V_67 == V_69 )
V_67 = F_48 ( & V_57 -> V_114 ) ;
V_105 = V_123 -> V_103 ;
if ( V_105 < V_57 -> V_40 . V_101 ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_18 ) ;
goto exit;
}
V_105 = V_57 -> V_40 . V_101 ;
}
V_20 = V_123 -> V_20 ;
V_107 = V_20 / ( V_105 * 2 ) ;
if ( V_107 < V_57 -> V_40 . V_102 ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_19 ) ;
goto exit;
}
V_107 = V_57 -> V_40 . V_102 ;
}
if ( ! F_51 ( V_105 , 8 ) ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_20 ) ;
goto exit;
}
V_105 = ( ( ( V_105 + 7 ) / 8 ) * 8 ) ;
}
if ( V_124 ) {
V_123 -> V_103 = V_105 ;
V_123 -> V_20 = V_105 * V_107 * 2 ;
}
V_123 -> V_101 = V_11 -> V_18 . V_18 . V_19 . V_101 ;
V_123 -> V_102 = V_11 -> V_18 . V_18 . V_19 . V_102 ;
return 0 ;
exit:
return V_59 ;
}
static void F_30 ( struct V_7 * V_8 , int V_125 )
{
struct V_10 * V_11 ;
F_3 ( 2 , V_13 , L_21 ) ;
V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
if ( V_73 == V_8 -> V_38 )
V_11 -> V_71 = V_126 ;
else if ( 2 == V_125 )
V_11 -> V_71 = V_127 ;
else
V_11 -> V_71 = V_128 ;
}
static int F_52 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
F_3 ( 2 , V_13 , L_22 ) ;
return F_53 ( & V_11 -> V_134 , V_132 ) ;
}
static unsigned int F_54 ( struct V_129 * V_130 , T_3 * V_135 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
F_3 ( 2 , V_13 , L_23 ) ;
if ( V_11 -> V_65 )
return F_55 ( & V_11 -> V_134 , V_130 , V_135 ) ;
return 0 ;
}
static int F_56 ( struct V_129 * V_130 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
struct V_136 * V_137 = F_57 ( V_130 ) ;
struct V_10 * V_11 ;
struct V_92 * V_93 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
int V_86 ;
F_3 ( 2 , V_13 , L_24 ) ;
V_8 = F_58 ( V_137 ) ;
V_93 = & V_8 -> V_94 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( NULL == V_8 -> V_138 ) {
for ( V_86 = 0 ; V_86 < V_91 -> V_139 ; V_86 ++ ) {
if ( V_83 . V_140 [ V_86 ] ) {
V_8 -> V_138 = & V_91 -> V_141 [ V_86 ] ;
V_93 -> V_142 = 0 ;
break;
}
}
if ( V_86 == V_91 -> V_139 ) {
F_59 ( L_25 ) ;
return - V_143 ;
}
}
V_4 = F_60 ( sizeof( struct V_3 ) , V_144 ) ;
if ( NULL == V_4 ) {
F_59 ( L_26 ) ;
return - V_145 ;
}
V_130 -> V_133 = V_4 ;
V_4 -> V_9 = V_8 ;
V_4 -> V_146 = 0 ;
if ( ! V_8 -> V_146 ) {
V_4 -> V_146 = 1 ;
V_8 -> V_146 = 1 ;
memset ( & ( V_8 -> V_39 ) , 0 , sizeof( struct V_57 ) ) ;
}
V_8 -> V_147 ++ ;
V_4 -> V_148 [ V_14 ] = 0 ;
V_4 -> V_149 = V_150 ;
F_61 ( & V_8 -> V_149 , & V_4 -> V_149 ) ;
return 0 ;
}
static int F_62 ( struct V_129 * V_130 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
F_3 ( 2 , V_13 , L_27 ) ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_4 -> V_148 [ V_14 ] ) {
V_11 -> V_151 = 0 ;
if ( V_72 == V_8 -> V_38 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( 2 == V_11 -> V_65 ) ) {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
V_11 -> V_65 = 0 ;
F_63 ( & V_11 -> V_134 ) ;
F_64 ( V_11 -> V_44 ) ;
}
V_8 -> V_147 -- ;
F_65 ( & V_8 -> V_149 , V_4 -> V_149 ) ;
if ( V_4 -> V_146 )
V_8 -> V_146 = 0 ;
V_130 -> V_133 = NULL ;
F_66 ( V_4 ) ;
return 0 ;
}
static int F_67 ( struct V_129 * V_129 , void * V_152 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
T_4 V_95 = 0 ;
struct V_5 * V_6 ;
F_3 ( 2 , V_13 , L_28 ) ;
if ( ( V_72 == V_8 -> V_38 )
|| ( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_146 ) {
F_3 ( 1 , V_13 , L_29 ) ;
return - V_155 ;
}
}
if ( V_120 != V_154 -> type || ! V_55 )
return - V_26 ;
V_95 = V_14 ;
V_11 = & V_8 -> V_11 [ V_95 ] ;
if ( 0 != V_11 -> V_151 )
return - V_155 ;
V_11 -> V_44 = F_68 ( V_55 ) ;
if ( ! V_11 -> V_44 ) {
F_59 ( L_30 ) ;
return - V_26 ;
}
V_6 = & V_11 -> V_134 ;
V_6 -> type = V_120 ;
V_6 -> V_156 = V_157 | V_158 ;
V_6 -> V_159 = V_4 ;
V_6 -> V_160 = & V_161 ;
V_6 -> V_162 = & V_163 ;
V_6 -> V_164 = sizeof( struct V_45 ) ;
F_69 ( V_6 ) ;
V_4 -> V_148 [ V_95 ] = 1 ;
V_11 -> V_151 = 1 ;
V_11 -> V_35 = V_154 -> V_35 ;
F_23 ( & V_11 -> V_48 ) ;
return F_70 ( & V_11 -> V_134 , V_154 ) ;
}
static int F_71 ( struct V_129 * V_129 , void * V_152 ,
struct V_165 * V_46 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_31 ) ;
if ( V_11 -> V_18 . type != V_46 -> type )
return - V_26 ;
if ( V_11 -> V_35 != V_34 ) {
F_3 ( 1 , V_13 , L_32 ) ;
return - V_26 ;
}
return F_72 ( & V_11 -> V_134 , V_46 ) ;
}
static int F_73 ( struct V_129 * V_129 , void * V_152 , struct V_165 * V_46 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_165 V_166 = * V_46 ;
F_3 ( 2 , V_13 , L_33 ) ;
if ( V_11 -> V_18 . type != V_166 . type ) {
F_59 ( L_34 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_148 [ V_14 ] ) {
F_59 ( L_35 ) ;
return - V_167 ;
}
return F_74 ( & V_11 -> V_134 , V_46 ) ;
}
static int F_75 ( struct V_129 * V_129 , void * V_152 , struct V_165 * V_46 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_36 ) ;
return F_76 ( & V_11 -> V_134 , V_46 ,
( V_129 -> V_168 & V_169 ) ) ;
}
static int F_77 ( struct V_129 * V_129 , void * V_152 ,
enum V_170 V_171 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_7 * V_172 = V_83 . V_82 [ ! V_8 -> V_38 ] ;
struct V_57 * V_58 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_37 ) ;
V_58 = & V_8 -> V_39 ;
if ( V_171 != V_120 ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_148 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_167 ;
}
if ( V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_40 ) ;
return - V_155 ;
}
if ( ( V_8 -> V_38 == V_72 &&
V_172 -> V_11 [ V_14 ] . V_65 &&
V_58 -> V_40 . V_41 == 0 ) ||
( ( V_8 -> V_38 == V_73 ) &&
( 2 == V_172 -> V_11 [ V_14 ] . V_65 ) ) ) {
F_3 ( 1 , V_13 , L_41 ) ;
return - V_155 ;
}
V_59 = F_49 ( V_8 , & V_11 -> V_18 . V_18 . V_19 , 0 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_94 ,
V_174 , 1 ) ;
if ( V_59 && ( V_59 != - V_175 ) ) {
F_3 ( 1 , V_13 , L_42 ) ;
return V_59 ;
}
V_59 = F_79 ( & V_11 -> V_134 , V_171 ) ;
if ( V_59 ) {
F_3 ( 1 , V_13 , L_43 ) ;
return V_59 ;
}
return V_59 ;
}
static int F_80 ( struct V_129 * V_129 , void * V_152 ,
enum V_170 V_171 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 ;
F_3 ( 2 , V_13 , L_44 ) ;
if ( V_171 != V_120 ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_148 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_167 ;
}
if ( ! V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_40 ) ;
return - V_26 ;
}
if ( V_72 == V_8 -> V_38 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
} else {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
V_11 -> V_65 = 0 ;
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_94 ,
V_174 , 0 ) ;
if ( V_59 && ( V_59 != - V_175 ) )
F_3 ( 1 , V_13 , L_45 ) ;
return F_81 ( & V_11 -> V_134 , V_171 ) ;
}
static struct V_176 * F_82 (
struct V_7 * V_8 ,
struct V_53 * V_177 ,
int V_178 ,
int * V_179 )
{
struct V_180 * V_181 ;
struct V_176 * V_141 = NULL ;
const char * V_182 = NULL ;
int V_86 ;
F_3 ( 2 , V_13 , L_46 ) ;
V_181 = & V_177 -> V_183 [ V_8 -> V_38 ] ;
for ( V_86 = 0 ; V_86 < V_181 -> V_184 ; V_86 ++ ) {
if ( V_86 == V_178 ) {
V_182 = V_181 -> V_185 [ V_86 ] . V_182 ;
break;
}
}
if ( V_86 == V_181 -> V_184 || ( NULL == V_182 ) )
return V_141 ;
for ( V_86 = 0 ; V_86 < V_177 -> V_139 ; V_86 ++ ) {
V_141 = & V_177 -> V_141 [ V_86 ] ;
if ( ! strcmp ( V_141 -> V_186 , V_182 ) )
break;
}
if ( V_86 == V_177 -> V_139 )
return V_141 ;
if ( NULL == V_83 . V_140 [ V_86 ] )
return NULL ;
* V_179 = V_86 ;
return V_141 ;
}
static int F_83 ( struct V_129 * V_129 , void * V_152 , T_5 * V_187 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_47 ) ;
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_94 ,
V_188 , V_187 ) ;
if ( V_59 < 0 )
F_3 ( 1 , V_13 , L_48 ) ;
return V_59 ;
}
static int F_84 ( struct V_129 * V_129 , void * V_152 , T_5 * V_189 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( 2 , V_13 , L_49 ) ;
* V_189 = V_8 -> V_94 . V_99 ;
return 0 ;
}
static int F_85 ( struct V_129 * V_129 , void * V_152 , T_5 * V_187 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_50 ) ;
if ( V_11 -> V_65 ) {
F_59 ( L_51 ) ;
return - V_155 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_146 ) {
F_3 ( 1 , V_13 , L_29 ) ;
return - V_155 ;
}
}
V_59 = F_86 ( & V_8 -> V_149 , V_4 -> V_149 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_146 = 1 ;
V_8 -> V_94 . V_99 = * V_187 ;
V_8 -> V_94 . V_100 = V_190 ;
memset ( & V_8 -> V_94 . V_191 , 0 , sizeof( V_8 -> V_94 . V_191 ) ) ;
if ( F_46 ( V_8 ) ) {
F_59 ( L_52 ) ;
return - V_26 ;
}
F_47 ( V_8 ) ;
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_192 ,
V_193 , * V_187 ) ;
if ( V_59 < 0 )
F_3 ( 1 , V_13 , L_48 ) ;
return V_59 ;
}
static int F_87 ( struct V_129 * V_129 , void * V_152 ,
struct V_194 * V_195 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
struct V_180 * V_181 ;
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
V_181 = & V_91 -> V_183 [ V_8 -> V_38 ] ;
if ( V_195 -> V_95 >= V_181 -> V_184 ) {
F_3 ( 1 , V_13 , L_53 ) ;
return - V_26 ;
}
memcpy ( V_195 , & V_181 -> V_185 [ V_195 -> V_95 ] . V_195 ,
sizeof( * V_195 ) ) ;
return 0 ;
}
static int F_88 ( struct V_129 * V_129 , void * V_152 , unsigned int * V_95 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
* V_95 = V_93 -> V_142 ;
return 0 ;
}
static int F_89 ( struct V_129 * V_129 , void * V_152 , unsigned int V_95 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
struct V_180 * V_181 ;
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_92 * V_93 = & V_8 -> V_94 ;
struct V_176 * V_141 ;
int V_59 = 0 , V_196 = 0 ;
T_2 V_195 = 0 , V_197 = 0 ;
V_181 = & V_91 -> V_183 [ V_8 -> V_38 ] ;
if ( V_11 -> V_65 ) {
F_59 ( L_54 ) ;
return - V_155 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_146 ) {
F_3 ( 1 , V_13 , L_29 ) ;
return - V_155 ;
}
}
V_59 = F_86 ( & V_8 -> V_149 , V_4 -> V_149 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_146 = 1 ;
V_141 = F_82 ( V_8 , V_91 , V_95 ,
& V_196 ) ;
if ( NULL == V_141 ) {
F_3 ( 1 , V_13 ,
L_55 ) ;
return - V_26 ;
}
if ( V_91 -> V_198 ) {
V_59 = V_91 -> V_198 ( V_8 -> V_38 ,
V_141 -> V_186 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_56
L_57 ,
V_141 -> V_186 , V_95 ) ;
return V_59 ;
}
}
if ( V_141 -> V_199 ) {
V_195 = V_141 -> V_195 ;
V_197 = V_141 -> V_197 ;
V_59 = F_78 ( V_83 . V_140 [ V_196 ] , V_94 , V_200 ,
V_195 , V_197 , 0 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_58 ) ;
return V_59 ;
}
}
V_93 -> V_142 = V_95 ;
V_8 -> V_138 = V_141 ;
V_8 -> V_173 = V_196 ;
V_8 -> V_39 . V_114 = V_141 -> V_201 ;
V_8 -> V_202 -> V_203 = V_181 -> V_185 [ V_95 ] . V_195 . V_189 ;
return V_59 ;
}
static int F_90 ( struct V_129 * V_129 , void * V_152 ,
struct V_204 * V_18 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_18 -> V_95 != 0 ) {
F_3 ( 1 , V_13 , L_59 ) ;
return - V_26 ;
}
if ( V_8 -> V_39 . V_114 . V_115 == V_116 ) {
V_18 -> type = V_120 ;
strcpy ( V_18 -> V_205 , L_60 ) ;
V_18 -> V_117 = V_118 ;
} else {
V_18 -> type = V_120 ;
strcpy ( V_18 -> V_205 , L_61 ) ;
V_18 -> V_117 = V_119 ;
}
return 0 ;
}
static int F_91 ( struct V_129 * V_129 , void * V_152 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_122 * V_123 = & V_18 -> V_18 . V_19 ;
return F_49 ( V_8 , V_123 , 1 ) ;
}
static int F_92 ( struct V_129 * V_129 , void * V_152 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_11 -> V_18 . type != V_18 -> type )
return - V_26 ;
* V_18 = V_11 -> V_18 ;
return 0 ;
}
static int F_93 ( struct V_129 * V_129 , void * V_152 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_122 * V_123 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_62 , V_206 ) ;
if ( V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_63 ) ;
return - V_155 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_146 ) {
F_3 ( 1 , V_13 , L_29 ) ;
return - V_155 ;
}
}
V_59 = F_86 ( & V_8 -> V_149 , V_4 -> V_149 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_146 = 1 ;
V_123 = & V_18 -> V_18 . V_19 ;
V_59 = F_49 ( V_8 , V_123 , 0 ) ;
if ( V_59 )
return V_59 ;
V_11 -> V_18 = * V_18 ;
return 0 ;
}
static int F_94 ( struct V_129 * V_129 , void * V_152 ,
struct V_207 * V_208 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
V_208 -> V_209 = V_210 | V_211 ;
F_95 ( V_208 -> V_212 , L_64 , sizeof( V_208 -> V_212 ) ) ;
F_95 ( V_208 -> V_213 , L_65 , sizeof( V_208 -> V_213 ) ) ;
F_95 ( V_208 -> V_214 , V_91 -> V_215 , sizeof( V_208 -> V_214 ) ) ;
return 0 ;
}
static int F_96 ( struct V_129 * V_129 , void * V_152 ,
enum V_216 * V_149 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
* V_149 = F_97 ( & V_8 -> V_149 ) ;
return 0 ;
}
static int F_98 ( struct V_129 * V_129 , void * V_152 , enum V_216 V_217 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_99 ( & V_8 -> V_149 , & V_4 -> V_149 , V_217 ) ;
}
static int F_100 ( struct V_129 * V_129 , void * V_152 ,
struct V_218 * V_219 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_120 != V_219 -> type )
return - V_26 ;
V_219 -> V_220 . V_221 = 0 ;
V_219 -> V_220 . V_222 = 0 ;
V_219 -> V_220 . V_102 = V_11 -> V_102 ;
V_219 -> V_220 . V_101 = V_11 -> V_101 ;
V_219 -> V_223 = V_219 -> V_220 ;
return 0 ;
}
static int F_101 ( struct V_129 * V_129 , void * V_152 ,
struct V_224 * V_225 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_78 ( V_83 . V_140 [ V_8 -> V_173 ] ,
V_94 , V_226 , V_225 ) ;
}
static int F_102 ( struct V_129 * V_129 , void * V_152 ,
struct V_227 * V_225 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_78 ( V_83 . V_140 [ V_8 -> V_173 ] ,
V_94 , V_228 , V_225 ) ;
}
static int F_103 ( struct V_129 * V_129 , void * V_152 ,
struct V_227 * V_225 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 = 0 ;
if ( V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_51 ) ;
return - V_155 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_146 ) {
F_3 ( 1 , V_13 , L_29 ) ;
return - V_155 ;
}
}
V_59 = F_86 ( & V_8 -> V_149 , V_4 -> V_149 ) ;
if ( V_59 )
return V_59 ;
V_4 -> V_146 = 1 ;
if ( F_104 ( & V_11 -> V_51 ) )
return - V_229 ;
V_8 -> V_94 . V_100 = V_225 -> V_225 ;
V_8 -> V_94 . V_99 = V_230 ;
memset ( & V_8 -> V_94 . V_191 , 0 , sizeof( V_8 -> V_94 . V_191 ) ) ;
if ( F_46 ( V_8 ) ) {
F_3 ( 1 , V_13 , L_52 ) ;
V_59 = - V_26 ;
} else {
F_47 ( V_8 ) ;
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] ,
V_94 , V_231 , V_225 ) ;
}
F_19 ( & V_11 -> V_51 ) ;
return V_59 ;
}
static int F_105 ( struct V_129 * V_129 , void * V_152 ,
struct V_227 * V_225 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
V_225 -> V_225 = V_8 -> V_94 . V_100 ;
return 0 ;
}
static int F_106 ( struct V_129 * V_129 , void * V_152 ,
struct V_232 * V_233 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_57 * V_39 = & V_8 -> V_39 ;
struct V_90 * V_40 = & V_39 -> V_40 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
struct V_234 * V_235 = & V_93 -> V_191 ;
int V_59 ;
if ( V_233 -> type != V_236 ) {
F_3 ( 2 , V_13 , L_66 ) ;
return - V_26 ;
}
V_59 = F_78 ( V_83 . V_140 [ V_8 -> V_173 ] ,
V_94 , V_237 , V_233 ) ;
if ( V_59 == - V_175 ) {
F_3 ( 2 , V_13 , L_67
L_68 ) ;
return - V_26 ;
}
if ( V_59 < 0 ) {
F_3 ( 2 , V_13 , L_69 ) ;
return V_59 ;
}
if ( ! ( V_233 -> V_235 . V_101 && V_233 -> V_235 . V_102 &&
( V_233 -> V_235 . V_238 ||
V_233 -> V_235 . V_239 ||
V_233 -> V_235 . V_240 ) &&
V_233 -> V_235 . V_241 &&
( V_233 -> V_235 . V_242 ||
V_233 -> V_235 . V_243 ) ) ) {
F_3 ( 2 , V_13 , L_70
L_71
L_72
L_73
L_74 ) ;
return - V_26 ;
}
* V_235 = V_233 -> V_235 ;
V_40 -> V_244 = V_235 -> V_238 + V_235 -> V_239 +
V_235 -> V_240 - 8 ;
V_40 -> V_245 = V_235 -> V_101 ;
V_40 -> V_246 = 1 ;
V_40 -> V_247 = V_235 -> V_243 + V_235 -> V_242 + 1 ;
if ( V_235 -> V_248 ) {
if ( V_235 -> V_249 || V_235 -> V_250 || V_235 -> V_251 ) {
V_40 -> V_252 = V_235 -> V_102 * 2 +
V_235 -> V_241 + V_235 -> V_243 + V_235 -> V_242 +
V_235 -> V_250 + V_235 -> V_251 +
V_235 -> V_249 ;
V_40 -> V_253 = V_40 -> V_252 / 2 -
( V_235 -> V_241 - 1 ) ;
V_40 -> V_254 = V_40 -> V_252 / 2 + 1 ;
V_40 -> V_255 = V_40 -> V_254 + V_235 -> V_251 +
V_235 -> V_249 + 1 ;
V_40 -> V_256 = V_40 -> V_252 -
( V_235 -> V_250 - 1 ) ;
} else {
F_3 ( 2 , V_13 , L_75
L_76 ) ;
return - V_26 ;
}
} else {
V_40 -> V_252 = V_235 -> V_102 + V_235 -> V_241 +
V_235 -> V_243 + V_235 -> V_242 ;
V_40 -> V_253 = V_40 -> V_252 - ( V_235 -> V_241 - 1 ) ;
}
strncpy ( V_40 -> V_186 , L_77 , V_257 ) ;
V_40 -> V_101 = V_235 -> V_101 ;
V_40 -> V_102 = V_235 -> V_102 ;
V_40 -> V_66 = V_235 -> V_248 ? 0 : 1 ;
V_40 -> V_41 = 0 ;
V_40 -> V_258 = 0 ;
V_40 -> V_259 = 0 ;
V_40 -> V_98 = 1 ;
V_40 -> V_99 = 0 ;
V_40 -> V_100 = V_190 ;
V_93 -> V_99 = 0 ;
V_93 -> V_100 = V_190 ;
return 0 ;
}
static int F_107 ( struct V_129 * V_129 , void * V_152 ,
struct V_232 * V_233 )
{
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
struct V_234 * V_235 = & V_93 -> V_191 ;
V_233 -> V_235 = * V_235 ;
return 0 ;
}
static int F_108 ( struct V_129 * V_129 , void * V_152 ,
struct V_260 * V_261 )
{
V_261 -> V_262 = V_263 ;
V_261 -> V_264 = 0 ;
if ( V_261 -> V_265 . type != V_266 &&
V_261 -> V_265 . type != V_267 ) {
F_3 ( 2 , V_13 , L_78 ) ;
return - V_26 ;
}
return F_109 ( & V_83 . V_268 , 0 , V_192 ,
V_269 , V_261 ) ;
}
static int F_110 ( struct V_129 * V_129 , void * V_152 ,
struct V_270 * V_271 ) {
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_192 ,
V_272 , V_271 ) ;
}
static int F_111 ( struct V_129 * V_129 , void * V_152 ,
struct V_270 * V_271 ) {
struct V_3 * V_4 = V_152 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_78 ( V_83 . V_140 [ V_8 -> V_173 ] , V_192 ,
V_273 , V_271 ) ;
}
static int F_112 ( struct V_129 * V_130 , void * V_152 )
{
F_113 ( & V_83 . V_268 , 0 , V_192 , V_274 ) ;
return 0 ;
}
static int F_114 ( void )
{
int V_275 = 0 , V_86 , V_276 ;
int V_277 ;
if ( ( V_278 > 0 ) &&
( V_278 < V_36 . V_43 ) )
V_278 = V_36 . V_43 ;
if ( ( V_279 > 0 ) &&
( V_279 < V_36 . V_43 ) )
V_279 = V_36 . V_43 ;
if ( V_280 < V_36 . V_281 [ V_72 ] )
V_280 =
V_36 . V_281 [ V_72 ] ;
if ( V_282 < V_36 . V_281 [ V_73 ] )
V_282 =
V_36 . V_281 [ V_73 ] ;
V_36 . V_112 [ V_72 ] = V_278 ;
V_36 . V_112 [ V_73 ] = V_279 ;
if ( V_278 ) {
V_36 . V_37 [ V_72 ]
= V_280 ;
}
if ( V_279 ) {
V_36 . V_37 [ V_73 ]
= V_282 ;
}
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ ) {
V_83 . V_82 [ V_86 ] =
F_60 ( sizeof( * V_83 . V_82 [ V_86 ] ) , V_144 ) ;
if ( ! V_83 . V_82 [ V_86 ] ) {
V_277 = V_86 ;
V_275 = - V_145 ;
goto V_284;
}
}
return 0 ;
V_284:
for ( V_276 = 0 ; V_276 < V_277 ; V_276 ++ )
F_66 ( V_83 . V_82 [ V_276 ] ) ;
return V_275 ;
}
static T_6 int F_115 ( struct V_285 * V_286 )
{
struct V_176 * V_287 ;
struct V_53 * V_91 ;
int V_86 , V_276 , V_288 , V_289 , V_6 , V_275 ;
struct V_290 * V_291 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
struct V_136 * V_292 ;
struct V_293 * V_294 ;
int V_139 ;
T_7 V_33 ;
V_55 = & V_286 -> V_82 ;
V_275 = F_114 () ;
if ( V_275 ) {
F_116 ( V_55 -> V_212 , L_79 ) ;
return V_275 ;
}
V_275 = F_117 ( V_55 , & V_83 . V_268 ) ;
if ( V_275 ) {
F_116 ( V_55 -> V_212 , L_80 ) ;
return V_275 ;
}
V_288 = 0 ;
while ( ( V_294 = F_118 ( V_286 , V_295 , V_288 ) ) ) {
for ( V_86 = V_294 -> V_296 ; V_86 <= V_294 -> V_297 ; V_86 ++ ) {
if ( F_119 ( V_86 , F_43 , V_298 ,
L_81 ,
( void * ) ( & V_83 . V_82 [ V_288 ] -> V_38 ) ) ) {
V_275 = - V_155 ;
V_86 -- ;
goto V_299;
}
}
V_288 ++ ;
}
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_292 = F_120 () ;
if ( NULL == V_292 ) {
for ( V_276 = 0 ; V_276 < V_86 ; V_276 ++ ) {
V_8 = V_83 . V_82 [ V_276 ] ;
F_121 ( V_8 -> V_202 ) ;
}
V_275 = - V_145 ;
goto V_300;
}
* V_292 = V_301 ;
V_292 -> V_268 = & V_83 . V_268 ;
V_292 -> V_302 = F_121 ;
snprintf ( V_292 -> V_186 , sizeof( V_292 -> V_186 ) ,
L_82 ,
V_303 ) ;
V_8 -> V_202 = V_292 ;
}
V_294 = F_118 ( V_286 , V_304 , 0 ) ;
if ( V_294 ) {
V_33 = F_122 ( V_294 ) ;
for ( V_276 = 0 ; V_276 < V_283 ; V_276 ++ ) {
V_8 = V_83 . V_82 [ V_276 ] ;
V_8 -> V_38 = V_276 ;
V_36 . V_42 [ V_8 -> V_38 ] = 0 ;
if ( V_33 )
V_36 . V_42 [ V_8 -> V_38 ] =
V_33 / 2 ;
}
}
for ( V_276 = 0 ; V_276 < V_283 ; V_276 ++ ) {
V_8 = V_83 . V_82 [ V_276 ] ;
V_8 -> V_38 = V_276 ;
V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
F_123 ( & V_11 -> V_50 ) ;
F_124 ( & V_11 -> V_51 ) ;
F_125 ( V_305 , & V_8 -> V_202 -> V_49 ) ;
V_8 -> V_202 -> V_51 = & V_11 -> V_51 ;
F_126 ( & V_8 -> V_149 ) ;
V_275 = F_127 ( V_8 -> V_202 ,
V_306 , ( V_276 ? 1 : 0 ) ) ;
if ( V_275 )
goto V_307;
F_128 ( V_8 -> V_202 , V_8 ) ;
}
V_291 = F_129 ( 1 ) ;
V_91 = V_286 -> V_82 . V_56 ;
V_139 = V_91 -> V_139 ;
V_83 . V_140 = F_60 ( sizeof( struct V_308 * ) * V_139 ,
V_144 ) ;
if ( V_83 . V_140 == NULL ) {
F_59 ( L_83 ) ;
V_275 = - V_145 ;
goto V_307;
}
for ( V_86 = 0 ; V_86 < V_139 ; V_86 ++ ) {
V_287 = & V_91 -> V_141 [ V_86 ] ;
V_83 . V_140 [ V_86 ] =
F_130 ( & V_83 . V_268 ,
V_291 ,
& V_287 -> V_309 ,
NULL ) ;
if ( ! V_83 . V_140 [ V_86 ] ) {
F_59 ( L_84 ) ;
goto V_310;
}
F_131 ( & V_83 . V_268 , L_85 ,
V_287 -> V_186 ) ;
if ( V_83 . V_140 [ V_86 ] )
V_83 . V_140 [ V_86 ] -> V_311 = 1 << V_86 ;
}
F_131 ( & V_83 . V_268 , L_86 ) ;
return 0 ;
V_310:
F_66 ( V_83 . V_140 ) ;
V_276 = V_283 ;
V_307:
for ( V_288 = 0 ; V_288 < V_276 ; V_288 ++ ) {
V_8 = V_83 . V_82 [ V_288 ] ;
F_132 ( V_8 -> V_202 ) ;
}
V_300:
V_288 = V_283 - 1 ;
V_294 = F_118 ( V_286 , V_295 , V_288 ) ;
V_86 = V_294 -> V_297 ;
V_299:
for ( V_6 = V_288 ; V_6 >= 0 ; V_6 -- ) {
for ( V_289 = V_86 ; V_289 >= ( int ) V_294 -> V_296 ; V_289 -- )
F_133 ( V_289 , ( void * ) ( & V_83 . V_82 [ V_6 ] -> V_38 ) ) ;
V_294 = F_118 ( V_286 , V_295 , V_6 - 1 ) ;
if ( V_294 )
V_86 = V_294 -> V_297 ;
}
F_134 ( & V_83 . V_268 ) ;
return V_275 ;
}
static int F_135 ( struct V_285 * V_312 )
{
int V_86 ;
struct V_7 * V_8 ;
F_134 ( & V_83 . V_268 ) ;
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
F_132 ( V_8 -> V_202 ) ;
}
return 0 ;
}
static int F_136 ( struct V_312 * V_82 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_147 && V_11 -> V_151 ) {
if ( V_8 -> V_38 == V_72 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( V_8 -> V_38 == V_73 ||
V_11 -> V_65 == 2 ) {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
static int F_137 ( struct V_312 * V_82 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_147 && V_11 -> V_151 ) {
if ( V_8 -> V_38 == V_72 ) {
F_33 ( 1 ) ;
F_32 ( 1 ) ;
}
if ( V_8 -> V_38 == V_73 ||
V_11 -> V_65 == 2 ) {
F_36 ( 1 ) ;
F_35 ( 1 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
static T_6 int F_138 ( void )
{
return F_139 ( & V_313 ) ;
}
static void F_140 ( void )
{
struct V_285 * V_286 ;
struct V_293 * V_294 ;
int V_314 ;
int V_86 = 0 ;
V_286 = F_12 ( V_55 , struct V_285 , V_82 ) ;
while ( ( V_294 = F_118 ( V_286 , V_295 , V_86 ) ) ) {
for ( V_314 = V_294 -> V_296 ; V_314 <= V_294 -> V_297 ; V_314 ++ )
F_133 ( V_314 ,
( void * ) ( & V_83 . V_82 [ V_86 ] -> V_38 ) ) ;
V_86 ++ ;
}
F_141 ( & V_313 ) ;
F_66 ( V_83 . V_140 ) ;
for ( V_86 = 0 ; V_86 < V_283 ; V_86 ++ )
F_66 ( V_83 . V_82 [ V_86 ] ) ;
}
