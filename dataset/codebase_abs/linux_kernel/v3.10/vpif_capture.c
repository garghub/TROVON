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
unsigned long V_47 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_4 ) ;
F_13 ( & V_11 -> V_48 , V_47 ) ;
F_14 ( & V_46 -> V_49 , & V_11 -> V_50 ) ;
F_15 ( & V_11 -> V_48 , V_47 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_45 * V_46 = F_12 ( V_2 ,
struct V_45 , V_2 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_47 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_13 ( & V_11 -> V_48 , V_47 ) ;
if ( V_2 -> V_15 == V_16 )
F_17 ( & V_46 -> V_49 ) ;
F_15 ( & V_11 -> V_48 , V_47 ) ;
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
F_23 ( & V_46 -> V_49 ) ;
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
unsigned long V_47 ;
int V_59 ;
F_13 ( & V_11 -> V_48 , V_47 ) ;
if ( F_25 ( & V_11 -> V_50 ) ) {
F_15 ( & V_11 -> V_48 , V_47 ) ;
F_3 ( 1 , V_13 , L_5 ) ;
return - V_60 ;
}
V_11 -> V_61 = V_11 -> V_62 = F_26 ( V_11 -> V_50 . V_63 ,
struct V_45 , V_49 ) ;
F_27 ( & V_11 -> V_61 -> V_49 ) ;
F_15 ( & V_11 -> V_48 , V_47 ) ;
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
if ( V_54 -> V_70 ) {
V_59 = V_54 ->
V_70 ( V_58 -> V_40 . V_41 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_7 ) ;
return V_59 ;
}
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
V_72 [ V_14 ] [ V_8 -> V_38 ] = 1 ;
if ( ( V_73 == V_8 -> V_38 ) ) {
F_31 () ;
F_32 ( 1 ) ;
F_33 ( 1 ) ;
}
if ( ( V_74 == V_8 -> V_38 ) ||
( V_11 -> V_65 == 2 ) ) {
F_34 () ;
F_35 ( 1 ) ;
F_36 ( 1 ) ;
}
return 0 ;
}
static int F_37 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_47 ;
if ( ! F_38 ( V_27 ) )
return 0 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_13 ( & V_11 -> V_48 , V_47 ) ;
while ( ! F_25 ( & V_11 -> V_50 ) ) {
V_11 -> V_62 = F_26 ( V_11 -> V_50 . V_63 ,
struct V_45 , V_49 ) ;
F_27 ( & V_11 -> V_62 -> V_49 ) ;
F_39 ( & V_11 -> V_62 -> V_2 , V_75 ) ;
}
F_15 ( & V_11 -> V_48 , V_47 ) ;
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
F_43 ( & V_11 -> V_48 ) ;
V_11 -> V_62 = F_26 ( V_11 -> V_50 . V_63 ,
struct V_45 , V_49 ) ;
F_27 ( & V_11 -> V_62 -> V_49 ) ;
F_44 ( & V_11 -> V_48 ) ;
V_11 -> V_62 -> V_2 . V_15 = V_16 ;
V_12 = F_8 ( & V_11 -> V_62 -> V_2 , 0 ) ;
V_11 -> V_71 ( V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ,
V_12 + V_11 -> V_24 ,
V_12 + V_11 -> V_25 ) ;
}
static T_1 F_45 ( int V_79 , void * V_80 )
{
struct V_81 * V_82 = & V_83 ;
struct V_10 * V_11 ;
struct V_7 * V_8 ;
enum V_84 V_67 ;
int V_38 = 0 ;
int V_85 = - 1 , V_86 ;
V_38 = * ( int * ) ( V_80 ) ;
if ( ! F_46 ( V_38 ) )
return V_87 ;
V_8 = V_82 -> V_82 [ V_38 ] ;
V_67 = V_8 -> V_11 [ V_14 ] . V_18 . V_18 . V_19 . V_67 ;
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ ) {
V_11 = & V_8 -> V_11 [ V_86 ] ;
if ( 0 == V_11 -> V_65 )
continue;
if ( 1 == V_8 -> V_39 . V_40 . V_66 ) {
F_43 ( & V_11 -> V_48 ) ;
if ( F_25 ( & V_11 -> V_50 ) ) {
F_44 ( & V_11 -> V_48 ) ;
continue;
}
F_44 ( & V_11 -> V_48 ) ;
if ( ! V_72 [ V_86 ] [ V_38 ] )
F_40 ( V_11 ) ;
V_72 [ V_86 ] [ V_38 ] = 0 ;
F_42 ( V_11 ) ;
V_72 [ V_86 ] [ V_38 ] = 0 ;
} else {
if ( V_72 [ V_86 ] [ V_38 ] ) {
V_72 [ V_86 ] [ V_38 ] = 0 ;
continue;
}
if ( 0 == V_86 ) {
V_8 -> V_64 ^= 1 ;
V_85 = F_47 ( V_8 -> V_38 ) ;
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
F_43 ( & V_11 -> V_48 ) ;
if ( F_25 ( & V_11 -> V_50 ) ||
( V_11 -> V_61 != V_11 -> V_62 ) ) {
F_44 ( & V_11 -> V_48 ) ;
continue;
}
F_44 ( & V_11 -> V_48 ) ;
F_42 ( V_11 ) ;
}
}
}
return V_89 ;
}
static int F_48 ( struct V_7 * V_8 )
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
if ( ! memcmp ( & V_91 -> V_100 , & V_93 -> V_100 ,
sizeof( V_93 -> V_100 ) ) ) {
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
static void F_49 ( struct V_7 * V_8 )
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
static inline enum V_84 F_50 (
struct V_121 * V_114 )
{
return ( V_114 -> V_115 == V_116 ) ? V_68 :
V_109 ;
}
static int F_51 ( struct V_7 * V_8 ,
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
if ( ! ( F_52 ( V_67 ) ) ) {
if ( ! V_124 ) {
F_3 ( 2 , V_13 , L_17 ) ;
goto exit;
}
V_67 = F_50 ( & V_57 -> V_114 ) ;
} else if ( V_67 == V_69 )
V_67 = F_50 ( & V_57 -> V_114 ) ;
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
if ( ! F_53 ( V_105 , 8 ) ) {
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
if ( V_74 == V_8 -> V_38 )
V_11 -> V_71 = V_126 ;
else if ( 2 == V_125 )
V_11 -> V_71 = V_127 ;
else
V_11 -> V_71 = V_128 ;
}
static int F_54 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
int V_59 ;
F_3 ( 2 , V_13 , L_22 ) ;
if ( F_55 ( & V_11 -> V_51 ) )
return - V_134 ;
V_59 = F_56 ( & V_11 -> V_135 , V_132 ) ;
F_19 ( & V_11 -> V_51 ) ;
return V_59 ;
}
static unsigned int F_57 ( struct V_129 * V_130 , T_3 * V_136 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
unsigned int V_137 = 0 ;
F_3 ( 2 , V_13 , L_23 ) ;
if ( V_11 -> V_65 ) {
F_21 ( & V_11 -> V_51 ) ;
V_137 = F_58 ( & V_11 -> V_135 , V_130 , V_136 ) ;
F_19 ( & V_11 -> V_51 ) ;
}
return V_137 ;
}
static int F_59 ( struct V_129 * V_130 )
{
struct V_138 * V_139 = F_60 ( V_130 ) ;
struct V_10 * V_11 ;
struct V_92 * V_93 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
F_3 ( 2 , V_13 , L_24 ) ;
V_8 = F_61 ( V_139 ) ;
V_93 = & V_8 -> V_94 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
V_4 = F_62 ( sizeof( struct V_3 ) , V_140 ) ;
if ( NULL == V_4 ) {
F_63 ( L_25 ) ;
return - V_141 ;
}
if ( F_55 ( & V_11 -> V_51 ) ) {
F_64 ( V_4 ) ;
return - V_134 ;
}
V_130 -> V_133 = V_4 ;
V_4 -> V_9 = V_8 ;
V_4 -> V_142 = 0 ;
if ( ! V_8 -> V_142 ) {
V_4 -> V_142 = 1 ;
V_8 -> V_142 = 1 ;
memset ( & ( V_8 -> V_39 ) , 0 , sizeof( struct V_57 ) ) ;
}
V_8 -> V_143 ++ ;
V_4 -> V_144 [ V_14 ] = 0 ;
V_4 -> V_145 = V_146 ;
F_65 ( & V_8 -> V_145 , & V_4 -> V_145 ) ;
F_19 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_66 ( struct V_129 * V_130 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
F_3 ( 2 , V_13 , L_26 ) ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_4 -> V_144 [ V_14 ] ) {
V_11 -> V_147 = 0 ;
if ( V_73 == V_8 -> V_38 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_74 == V_8 -> V_38 ) ||
( 2 == V_11 -> V_65 ) ) {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
V_11 -> V_65 = 0 ;
F_67 ( & V_11 -> V_135 ) ;
F_68 ( V_11 -> V_44 ) ;
}
V_8 -> V_143 -- ;
F_69 ( & V_8 -> V_145 , V_4 -> V_145 ) ;
if ( V_4 -> V_142 )
V_8 -> V_142 = 0 ;
F_19 ( & V_11 -> V_51 ) ;
V_130 -> V_133 = NULL ;
F_64 ( V_4 ) ;
return 0 ;
}
static int F_70 ( struct V_129 * V_129 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
T_4 V_95 = 0 ;
struct V_5 * V_6 ;
int V_59 ;
F_3 ( 2 , V_13 , L_27 ) ;
if ( ( V_73 == V_8 -> V_38 )
|| ( V_74 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_142 ) {
F_3 ( 1 , V_13 , L_28 ) ;
return - V_151 ;
}
}
if ( V_120 != V_150 -> type || ! V_55 )
return - V_26 ;
V_95 = V_14 ;
V_11 = & V_8 -> V_11 [ V_95 ] ;
if ( 0 != V_11 -> V_147 )
return - V_151 ;
V_11 -> V_44 = F_71 ( V_55 ) ;
if ( F_72 ( V_11 -> V_44 ) ) {
F_63 ( L_29 ) ;
return F_73 ( V_11 -> V_44 ) ;
}
V_6 = & V_11 -> V_135 ;
V_6 -> type = V_120 ;
V_6 -> V_152 = V_153 | V_154 ;
V_6 -> V_155 = V_4 ;
V_6 -> V_156 = & V_157 ;
V_6 -> V_158 = & V_159 ;
V_6 -> V_160 = sizeof( struct V_45 ) ;
V_6 -> V_161 = V_162 ;
V_59 = F_74 ( V_6 ) ;
if ( V_59 ) {
F_63 ( L_30 ) ;
F_68 ( V_11 -> V_44 ) ;
return V_59 ;
}
V_4 -> V_144 [ V_95 ] = 1 ;
V_11 -> V_147 = 1 ;
V_11 -> V_35 = V_150 -> V_35 ;
F_23 ( & V_11 -> V_50 ) ;
return F_75 ( & V_11 -> V_135 , V_150 ) ;
}
static int F_76 ( struct V_129 * V_129 , void * V_148 ,
struct V_163 * V_46 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_31 ) ;
if ( V_11 -> V_18 . type != V_46 -> type )
return - V_26 ;
if ( V_11 -> V_35 != V_34 ) {
F_3 ( 1 , V_13 , L_32 ) ;
return - V_26 ;
}
return F_77 ( & V_11 -> V_135 , V_46 ) ;
}
static int F_78 ( struct V_129 * V_129 , void * V_148 , struct V_163 * V_46 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_163 V_164 = * V_46 ;
F_3 ( 2 , V_13 , L_33 ) ;
if ( V_11 -> V_18 . type != V_164 . type ) {
F_63 ( L_34 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_144 [ V_14 ] ) {
F_63 ( L_35 ) ;
return - V_165 ;
}
return F_79 ( & V_11 -> V_135 , V_46 ) ;
}
static int F_80 ( struct V_129 * V_129 , void * V_148 , struct V_163 * V_46 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_36 ) ;
return F_81 ( & V_11 -> V_135 , V_46 ,
( V_129 -> V_166 & V_167 ) ) ;
}
static int F_82 ( struct V_129 * V_129 , void * V_148 ,
enum V_168 V_169 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_7 * V_170 = V_83 . V_82 [ ! V_8 -> V_38 ] ;
struct V_57 * V_58 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_37 ) ;
V_58 = & V_8 -> V_39 ;
if ( V_169 != V_120 ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_144 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_165 ;
}
if ( V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_40 ) ;
return - V_151 ;
}
if ( ( V_8 -> V_38 == V_73 &&
V_170 -> V_11 [ V_14 ] . V_65 &&
V_58 -> V_40 . V_41 == 0 ) ||
( ( V_8 -> V_38 == V_74 ) &&
( 2 == V_170 -> V_11 [ V_14 ] . V_65 ) ) ) {
F_3 ( 1 , V_13 , L_41 ) ;
return - V_151 ;
}
V_59 = F_51 ( V_8 , & V_11 -> V_18 . V_18 . V_19 , 0 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_172 , 1 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 ) {
F_3 ( 1 , V_13 , L_42 ) ;
return V_59 ;
}
V_59 = F_84 ( & V_11 -> V_135 , V_169 ) ;
if ( V_59 ) {
F_3 ( 1 , V_13 , L_43 ) ;
return V_59 ;
}
return V_59 ;
}
static int F_85 ( struct V_129 * V_129 , void * V_148 ,
enum V_168 V_169 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 ;
F_3 ( 2 , V_13 , L_44 ) ;
if ( V_169 != V_120 ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_144 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_165 ;
}
if ( ! V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_40 ) ;
return - V_26 ;
}
if ( V_73 == V_8 -> V_38 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
} else {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
V_11 -> V_65 = 0 ;
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_172 , 0 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 )
F_3 ( 1 , V_13 , L_45 ) ;
return F_86 ( & V_11 -> V_135 , V_169 ) ;
}
static int F_87 (
struct V_53 * V_175 ,
struct V_176 * V_177 ,
int V_178 )
{
struct V_179 * V_180 ;
const char * V_181 ;
int V_86 ;
F_3 ( 2 , V_13 , L_46 ) ;
V_181 = V_177 -> V_182 [ V_178 ] . V_181 ;
if ( V_181 == NULL )
return - 1 ;
for ( V_86 = 0 ; V_86 < V_175 -> V_183 ; V_86 ++ ) {
V_180 = & V_175 -> V_180 [ V_86 ] ;
if ( ! strcmp ( V_180 -> V_184 , V_181 ) )
return V_86 ;
}
return - 1 ;
}
static int F_88 (
struct V_53 * V_175 ,
struct V_7 * V_8 ,
int V_95 )
{
struct V_176 * V_177 =
& V_175 -> V_185 [ V_8 -> V_38 ] ;
struct V_179 * V_180 = NULL ;
struct V_186 * V_171 = NULL ;
T_2 V_187 = 0 , V_188 = 0 ;
int V_189 ;
int V_59 ;
V_189 = F_87 ( V_175 , V_177 , V_95 ) ;
if ( V_189 >= 0 ) {
V_171 = V_83 . V_171 [ V_189 ] ;
V_180 = & V_175 -> V_180 [ V_189 ] ;
}
if ( V_171 && V_175 -> V_190 ) {
V_59 = V_175 -> V_190 ( V_8 -> V_38 ,
V_180 -> V_184 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_47 \
L_48 ,
V_180 -> V_184 , V_95 ) ;
return V_59 ;
}
}
if ( V_171 ) {
V_187 = V_177 -> V_182 [ V_95 ] . V_191 ;
V_188 = V_177 -> V_182 [ V_95 ] . V_192 ;
V_59 = F_83 ( V_171 , V_94 , V_193 ,
V_187 , V_188 , 0 ) ;
if ( V_59 < 0 && V_59 != - V_173 ) {
F_3 ( 1 , V_13 , L_49 ) ;
return V_59 ;
}
}
V_8 -> V_194 = V_95 ;
V_8 -> V_171 = V_171 ;
V_8 -> V_39 . V_114 = V_177 -> V_195 ;
V_8 -> V_196 -> V_197 = V_177 -> V_182 [ V_95 ] . V_187 . V_198 ;
return 0 ;
}
static int F_89 ( struct V_129 * V_129 , void * V_148 , T_5 * V_199 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_50 ) ;
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_200 , V_199 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_201 ;
if ( V_59 ) {
F_3 ( 1 , V_13 , L_51 ) ;
return V_59 ;
}
return 0 ;
}
static int F_90 ( struct V_129 * V_129 , void * V_148 , T_5 * V_198 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( 2 , V_13 , L_52 ) ;
* V_198 = V_8 -> V_94 . V_99 ;
return 0 ;
}
static int F_91 ( struct V_129 * V_129 , void * V_148 , T_5 V_199 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_53 ) ;
if ( V_11 -> V_65 ) {
F_63 ( L_54 ) ;
return - V_151 ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( V_74 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_142 ) {
F_3 ( 1 , V_13 , L_28 ) ;
return - V_151 ;
}
}
V_59 = F_92 ( & V_8 -> V_145 , V_4 -> V_145 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_142 = 1 ;
V_8 -> V_94 . V_99 = V_199 ;
memset ( & V_8 -> V_94 . V_100 , 0 , sizeof( V_8 -> V_94 . V_100 ) ) ;
if ( F_48 ( V_8 ) ) {
F_63 ( L_55 ) ;
return - V_26 ;
}
F_49 ( V_8 ) ;
V_59 = F_83 ( V_8 -> V_171 , V_202 , V_203 , V_199 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 ) {
F_3 ( 1 , V_13 , L_56 ) ;
return V_59 ;
}
return 0 ;
}
static int F_93 ( struct V_129 * V_129 , void * V_148 ,
struct V_204 * V_187 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
struct V_176 * V_177 ;
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
V_177 = & V_91 -> V_185 [ V_8 -> V_38 ] ;
if ( V_187 -> V_95 >= V_177 -> V_205 ) {
F_3 ( 1 , V_13 , L_57 ) ;
return - V_26 ;
}
memcpy ( V_187 , & V_177 -> V_182 [ V_187 -> V_95 ] . V_187 ,
sizeof( * V_187 ) ) ;
return 0 ;
}
static int F_94 ( struct V_129 * V_129 , void * V_148 , unsigned int * V_95 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
* V_95 = V_8 -> V_194 ;
return 0 ;
}
static int F_95 ( struct V_129 * V_129 , void * V_148 , unsigned int V_95 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
struct V_176 * V_177 ;
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 ;
V_177 = & V_91 -> V_185 [ V_8 -> V_38 ] ;
if ( V_95 >= V_177 -> V_205 )
return - V_26 ;
if ( V_11 -> V_65 ) {
F_63 ( L_58 ) ;
return - V_151 ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( V_74 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_142 ) {
F_3 ( 1 , V_13 , L_28 ) ;
return - V_151 ;
}
}
V_59 = F_92 ( & V_8 -> V_145 , V_4 -> V_145 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_142 = 1 ;
return F_88 ( V_91 , V_8 , V_95 ) ;
}
static int F_96 ( struct V_129 * V_129 , void * V_148 ,
struct V_206 * V_18 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_18 -> V_95 != 0 ) {
F_3 ( 1 , V_13 , L_59 ) ;
return - V_26 ;
}
if ( V_8 -> V_39 . V_114 . V_115 == V_116 ) {
V_18 -> type = V_120 ;
strcpy ( V_18 -> V_207 , L_60 ) ;
V_18 -> V_117 = V_118 ;
} else {
V_18 -> type = V_120 ;
strcpy ( V_18 -> V_207 , L_61 ) ;
V_18 -> V_117 = V_119 ;
}
return 0 ;
}
static int F_97 ( struct V_129 * V_129 , void * V_148 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_122 * V_123 = & V_18 -> V_18 . V_19 ;
return F_51 ( V_8 , V_123 , 1 ) ;
}
static int F_98 ( struct V_129 * V_129 , void * V_148 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_11 -> V_18 . type != V_18 -> type )
return - V_26 ;
* V_18 = V_11 -> V_18 ;
return 0 ;
}
static int F_99 ( struct V_129 * V_129 , void * V_148 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_122 * V_123 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_62 , V_208 ) ;
if ( V_11 -> V_65 ) {
F_3 ( 1 , V_13 , L_63 ) ;
return - V_151 ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( V_74 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_142 ) {
F_3 ( 1 , V_13 , L_28 ) ;
return - V_151 ;
}
}
V_59 = F_92 ( & V_8 -> V_145 , V_4 -> V_145 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_142 = 1 ;
V_123 = & V_18 -> V_18 . V_19 ;
V_59 = F_51 ( V_8 , V_123 , 0 ) ;
if ( V_59 )
return V_59 ;
V_11 -> V_18 = * V_18 ;
return 0 ;
}
static int F_100 ( struct V_129 * V_129 , void * V_148 ,
struct V_209 * V_210 )
{
struct V_53 * V_91 = V_55 -> V_56 ;
V_210 -> V_211 = V_212 | V_213 ;
V_210 -> V_214 = V_210 -> V_211 | V_215 ;
snprintf ( V_210 -> V_216 , sizeof( V_210 -> V_216 ) , L_64 , F_101 ( V_55 ) ) ;
snprintf ( V_210 -> V_217 , sizeof( V_210 -> V_217 ) , L_65 ,
F_101 ( V_55 ) ) ;
F_102 ( V_210 -> V_218 , V_91 -> V_219 , sizeof( V_210 -> V_218 ) ) ;
return 0 ;
}
static int F_103 ( struct V_129 * V_129 , void * V_148 ,
enum V_220 * V_145 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
* V_145 = F_104 ( & V_8 -> V_145 ) ;
return 0 ;
}
static int F_105 ( struct V_129 * V_129 , void * V_148 , enum V_220 V_221 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_106 ( & V_8 -> V_145 , & V_4 -> V_145 , V_221 ) ;
}
static int F_107 ( struct V_129 * V_129 , void * V_148 ,
struct V_222 * V_223 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_120 != V_223 -> type )
return - V_26 ;
V_223 -> V_224 . V_225 = 0 ;
V_223 -> V_224 . V_226 = 0 ;
V_223 -> V_224 . V_102 = V_11 -> V_102 ;
V_223 -> V_224 . V_101 = V_11 -> V_101 ;
V_223 -> V_227 = V_223 -> V_224 ;
return 0 ;
}
static int
F_108 ( struct V_129 * V_129 , void * V_148 ,
struct V_228 * V_229 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_230 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_26 ;
return V_59 ;
}
static int
F_109 ( struct V_129 * V_129 , void * V_148 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_232 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_201 ;
return V_59 ;
}
static int F_110 ( struct V_129 * V_129 , void * V_148 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_57 * V_39 = & V_8 -> V_39 ;
struct V_90 * V_40 = & V_39 -> V_40 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
struct V_233 * V_234 = & V_93 -> V_100 . V_234 ;
int V_59 ;
if ( V_229 -> type != V_235 ) {
F_3 ( 2 , V_13 , L_66 ) ;
return - V_26 ;
}
V_59 = F_83 ( V_8 -> V_171 , V_94 , V_236 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
V_59 = 0 ;
if ( V_59 < 0 ) {
F_3 ( 2 , V_13 , L_67 ) ;
return V_59 ;
}
if ( ! ( V_229 -> V_234 . V_101 && V_229 -> V_234 . V_102 &&
( V_229 -> V_234 . V_237 ||
V_229 -> V_234 . V_238 ||
V_229 -> V_234 . V_239 ) &&
V_229 -> V_234 . V_240 &&
( V_229 -> V_234 . V_241 ||
V_229 -> V_234 . V_242 ) ) ) {
F_3 ( 2 , V_13 , L_68
L_69
L_70
L_71
L_72 ) ;
return - V_26 ;
}
V_93 -> V_100 = * V_229 ;
V_40 -> V_243 = V_234 -> V_237 + V_234 -> V_238 +
V_234 -> V_239 - 8 ;
V_40 -> V_244 = V_234 -> V_101 ;
V_40 -> V_245 = 1 ;
V_40 -> V_246 = V_234 -> V_242 + V_234 -> V_241 + 1 ;
if ( V_234 -> V_247 ) {
if ( V_234 -> V_248 || V_234 -> V_249 || V_234 -> V_250 ) {
V_40 -> V_251 = V_234 -> V_102 * 2 +
V_234 -> V_240 + V_234 -> V_242 + V_234 -> V_241 +
V_234 -> V_249 + V_234 -> V_250 +
V_234 -> V_248 ;
V_40 -> V_252 = V_40 -> V_251 / 2 -
( V_234 -> V_240 - 1 ) ;
V_40 -> V_253 = V_40 -> V_251 / 2 + 1 ;
V_40 -> V_254 = V_40 -> V_253 + V_234 -> V_250 +
V_234 -> V_248 + 1 ;
V_40 -> V_255 = V_40 -> V_251 -
( V_234 -> V_249 - 1 ) ;
} else {
F_3 ( 2 , V_13 , L_73
L_74 ) ;
return - V_26 ;
}
} else {
V_40 -> V_251 = V_234 -> V_102 + V_234 -> V_240 +
V_234 -> V_242 + V_234 -> V_241 ;
V_40 -> V_252 = V_40 -> V_251 - ( V_234 -> V_240 - 1 ) ;
}
strncpy ( V_40 -> V_184 , L_75 , V_256 ) ;
V_40 -> V_101 = V_234 -> V_101 ;
V_40 -> V_102 = V_234 -> V_102 ;
V_40 -> V_66 = V_234 -> V_247 ? 0 : 1 ;
V_40 -> V_41 = 0 ;
V_40 -> V_257 = 0 ;
V_40 -> V_258 = 0 ;
V_40 -> V_98 = 1 ;
V_40 -> V_99 = 0 ;
V_93 -> V_99 = 0 ;
return 0 ;
}
static int F_111 ( struct V_129 * V_129 , void * V_148 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_92 * V_93 = & V_8 -> V_94 ;
* V_229 = V_93 -> V_100 ;
return 0 ;
}
static int F_112 ( struct V_129 * V_129 , void * V_148 ,
struct V_259 * V_260 )
{
V_260 -> V_261 = V_262 ;
V_260 -> V_263 = 0 ;
if ( V_260 -> V_264 . type != V_265 &&
V_260 -> V_264 . type != V_266 ) {
F_3 ( 2 , V_13 , L_76 ) ;
return - V_26 ;
}
return F_113 ( & V_83 . V_267 , 0 , V_202 ,
V_268 , V_260 ) ;
}
static int F_114 ( struct V_129 * V_129 , void * V_148 ,
struct V_269 * V_270 ) {
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_83 ( V_8 -> V_171 , V_202 , V_271 , V_270 ) ;
}
static int F_115 ( struct V_129 * V_129 , void * V_148 ,
const struct V_269 * V_270 )
{
struct V_3 * V_4 = V_148 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_83 ( V_8 -> V_171 , V_202 , V_272 , V_270 ) ;
}
static int F_116 ( struct V_129 * V_130 , void * V_148 )
{
F_117 ( & V_83 . V_267 , 0 , V_202 , V_273 ) ;
return 0 ;
}
static int F_118 ( void )
{
int V_274 = 0 , V_86 , V_275 ;
int V_276 ;
if ( ( V_277 > 0 ) &&
( V_277 < V_36 . V_43 ) )
V_277 = V_36 . V_43 ;
if ( ( V_278 > 0 ) &&
( V_278 < V_36 . V_43 ) )
V_278 = V_36 . V_43 ;
if ( V_279 < V_36 . V_280 [ V_73 ] )
V_279 =
V_36 . V_280 [ V_73 ] ;
if ( V_281 < V_36 . V_280 [ V_74 ] )
V_281 =
V_36 . V_280 [ V_74 ] ;
V_36 . V_112 [ V_73 ] = V_277 ;
V_36 . V_112 [ V_74 ] = V_278 ;
if ( V_277 ) {
V_36 . V_37 [ V_73 ]
= V_279 ;
}
if ( V_278 ) {
V_36 . V_37 [ V_74 ]
= V_281 ;
}
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_83 . V_82 [ V_86 ] =
F_62 ( sizeof( * V_83 . V_82 [ V_86 ] ) , V_140 ) ;
if ( ! V_83 . V_82 [ V_86 ] ) {
V_276 = V_86 ;
V_274 = - V_141 ;
goto V_283;
}
}
return 0 ;
V_283:
for ( V_275 = 0 ; V_275 < V_276 ; V_275 ++ )
F_64 ( V_83 . V_82 [ V_275 ] ) ;
return V_274 ;
}
static T_6 int F_119 ( struct V_284 * V_285 )
{
struct V_179 * V_286 ;
struct V_53 * V_91 ;
int V_86 , V_275 , V_287 , V_274 ;
int V_288 = 0 ;
struct V_289 * V_290 ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
struct V_138 * V_291 ;
struct V_292 * V_137 ;
int V_183 ;
T_7 V_33 ;
V_55 = & V_285 -> V_82 ;
V_274 = F_118 () ;
if ( V_274 ) {
F_120 ( V_55 -> V_216 , L_77 ) ;
return V_274 ;
}
V_274 = F_121 ( V_55 , & V_83 . V_267 ) ;
if ( V_274 ) {
F_120 ( V_55 -> V_216 , L_78 ) ;
return V_274 ;
}
while ( ( V_137 = F_122 ( V_285 , V_293 , V_288 ) ) ) {
for ( V_86 = V_137 -> V_294 ; V_86 <= V_137 -> V_295 ; V_86 ++ ) {
if ( F_123 ( V_86 , F_45 , V_296 ,
L_79 , ( void * )
( & V_83 . V_82 [ V_288 ] -> V_38 ) ) ) {
V_274 = - V_151 ;
for ( V_275 = 0 ; V_275 < V_86 ; V_275 ++ )
F_124 ( V_275 , ( void * )
( & V_83 . V_82 [ V_288 ] -> V_38 ) ) ;
goto V_297;
}
}
V_288 ++ ;
}
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_291 = F_125 () ;
if ( NULL == V_291 ) {
for ( V_275 = 0 ; V_275 < V_86 ; V_275 ++ ) {
V_8 = V_83 . V_82 [ V_275 ] ;
F_126 ( V_8 -> V_196 ) ;
}
V_274 = - V_141 ;
goto V_297;
}
* V_291 = V_298 ;
V_291 -> V_267 = & V_83 . V_267 ;
V_291 -> V_299 = F_126 ;
snprintf ( V_291 -> V_184 , sizeof( V_291 -> V_184 ) ,
L_80 ,
V_300 ) ;
V_8 -> V_196 = V_291 ;
}
V_137 = F_122 ( V_285 , V_301 , 0 ) ;
if ( V_137 ) {
V_33 = F_127 ( V_137 ) ;
for ( V_275 = 0 ; V_275 < V_282 ; V_275 ++ ) {
V_8 = V_83 . V_82 [ V_275 ] ;
V_8 -> V_38 = V_275 ;
V_36 . V_42 [ V_8 -> V_38 ] = 0 ;
if ( V_33 )
V_36 . V_42 [ V_8 -> V_38 ] =
V_33 / 2 ;
}
}
V_290 = F_128 ( 1 ) ;
V_91 = V_285 -> V_82 . V_56 ;
V_183 = V_91 -> V_183 ;
V_83 . V_171 = F_62 ( sizeof( struct V_186 * ) * V_183 ,
V_140 ) ;
if ( V_83 . V_171 == NULL ) {
F_63 ( L_81 ) ;
V_274 = - V_141 ;
goto V_302;
}
for ( V_86 = 0 ; V_86 < V_183 ; V_86 ++ ) {
V_286 = & V_91 -> V_180 [ V_86 ] ;
V_83 . V_171 [ V_86 ] =
F_129 ( & V_83 . V_267 ,
V_290 ,
& V_286 -> V_303 ,
NULL ) ;
if ( ! V_83 . V_171 [ V_86 ] ) {
F_63 ( L_82 ) ;
goto V_304;
}
F_130 ( & V_83 . V_267 , L_83 ,
V_286 -> V_184 ) ;
}
for ( V_275 = 0 ; V_275 < V_282 ; V_275 ++ ) {
V_8 = V_83 . V_82 [ V_275 ] ;
V_8 -> V_38 = V_275 ;
V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
F_131 ( & V_11 -> V_48 ) ;
F_132 ( & V_11 -> V_51 ) ;
V_8 -> V_196 -> V_51 = & V_11 -> V_51 ;
F_133 ( & V_8 -> V_145 ) ;
F_134 ( V_8 -> V_196 , V_8 ) ;
V_274 = F_88 ( V_91 , V_8 , 0 ) ;
if ( V_274 )
goto V_305;
V_274 = F_135 ( V_8 -> V_196 ,
V_306 , ( V_275 ? 1 : 0 ) ) ;
if ( V_274 )
goto V_305;
}
F_130 ( & V_83 . V_267 , L_84 ) ;
return 0 ;
V_305:
for ( V_287 = 0 ; V_287 < V_275 ; V_287 ++ ) {
V_8 = V_83 . V_82 [ V_287 ] ;
F_136 ( V_8 -> V_196 ) ;
}
V_304:
F_64 ( V_83 . V_171 ) ;
V_302:
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
F_126 ( V_8 -> V_196 ) ;
}
V_297:
F_137 ( & V_83 . V_267 ) ;
for ( V_86 = 0 ; V_86 < V_288 ; V_86 ++ ) {
V_137 = F_122 ( V_285 , V_293 , V_86 ) ;
for ( V_275 = V_137 -> V_294 ; V_275 <= V_137 -> V_295 ; V_275 ++ )
F_124 ( V_275 , ( void * ) ( & V_83 . V_82 [ V_86 ] -> V_38 ) ) ;
}
return V_274 ;
}
static int F_138 ( struct V_284 * V_307 )
{
int V_86 ;
struct V_7 * V_8 ;
F_137 ( & V_83 . V_267 ) ;
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
F_136 ( V_8 -> V_196 ) ;
}
return 0 ;
}
static int F_139 ( struct V_307 * V_82 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_143 && V_11 -> V_147 ) {
if ( V_8 -> V_38 == V_73 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( V_8 -> V_38 == V_74 ||
V_11 -> V_65 == 2 ) {
F_36 ( 0 ) ;
F_35 ( 0 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
static int F_140 ( struct V_307 * V_82 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ ) {
V_8 = V_83 . V_82 [ V_86 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_143 && V_11 -> V_147 ) {
if ( V_8 -> V_38 == V_73 ) {
F_33 ( 1 ) ;
F_32 ( 1 ) ;
}
if ( V_8 -> V_38 == V_74 ||
V_11 -> V_65 == 2 ) {
F_36 ( 1 ) ;
F_35 ( 1 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
static T_6 int F_141 ( void )
{
return F_142 ( & V_308 ) ;
}
static void F_143 ( void )
{
struct V_284 * V_285 ;
struct V_292 * V_137 ;
int V_309 ;
int V_86 = 0 ;
V_285 = F_12 ( V_55 , struct V_284 , V_82 ) ;
while ( ( V_137 = F_122 ( V_285 , V_293 , V_86 ) ) ) {
for ( V_309 = V_137 -> V_294 ; V_309 <= V_137 -> V_295 ; V_309 ++ )
F_124 ( V_309 ,
( void * ) ( & V_83 . V_82 [ V_86 ] -> V_38 ) ) ;
V_86 ++ ;
}
F_144 ( & V_308 ) ;
F_64 ( V_83 . V_171 ) ;
for ( V_86 = 0 ; V_86 < V_282 ; V_86 ++ )
F_64 ( V_83 . V_82 [ V_86 ] ) ;
}
