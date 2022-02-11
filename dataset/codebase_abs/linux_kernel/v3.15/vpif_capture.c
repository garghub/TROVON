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
V_11 -> V_60 = V_11 -> V_61 = F_25 ( V_11 -> V_50 . V_62 ,
struct V_45 , V_49 ) ;
F_26 ( & V_11 -> V_60 -> V_49 ) ;
F_15 ( & V_11 -> V_48 , V_47 ) ;
V_11 -> V_60 -> V_2 . V_15 = V_16 ;
V_8 -> V_63 = 0 ;
V_11 -> V_64 = 1 ;
V_12 = F_8 ( & V_11 -> V_60 -> V_2 , 0 ) ;
F_27 ( V_8 ) ;
if ( ( V_58 -> V_40 . V_65 &&
( ( V_11 -> V_18 . V_18 . V_19 . V_66 != V_67 ) &&
( V_11 -> V_18 . V_18 . V_19 . V_66 != V_68 ) ) ) ||
( ! V_58 -> V_40 . V_65 &&
( V_11 -> V_18 . V_18 . V_19 . V_66 == V_67 ) ) ) {
F_3 ( 1 , V_13 , L_5 ) ;
return - V_26 ;
}
if ( V_54 -> V_69 ) {
V_59 = V_54 ->
V_69 ( V_58 -> V_40 . V_41 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_6 ) ;
return V_59 ;
}
}
V_59 = F_28 ( V_58 , V_8 -> V_38 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_7 ) ;
return V_59 ;
}
V_11 -> V_64 = V_59 ;
F_29 ( V_8 , V_59 ) ;
V_11 -> V_70 ( V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ,
V_12 + V_11 -> V_24 ,
V_12 + V_11 -> V_25 ) ;
V_71 [ V_14 ] [ V_8 -> V_38 ] = 1 ;
if ( ( V_72 == V_8 -> V_38 ) ) {
F_30 () ;
F_31 ( 1 ) ;
F_32 ( 1 ) ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( V_11 -> V_64 == 2 ) ) {
F_33 () ;
F_34 ( 1 ) ;
F_35 ( 1 ) ;
}
return 0 ;
}
static int F_36 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_2 ( V_27 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_47 ;
if ( ! F_37 ( V_27 ) )
return 0 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_72 == V_8 -> V_38 ) {
F_32 ( 0 ) ;
F_31 ( 0 ) ;
}
if ( ( V_73 == V_8 -> V_38 ) ||
( 2 == V_11 -> V_64 ) ) {
F_35 ( 0 ) ;
F_34 ( 0 ) ;
}
V_11 -> V_64 = 0 ;
F_13 ( & V_11 -> V_48 , V_47 ) ;
if ( V_11 -> V_60 == V_11 -> V_61 ) {
F_38 ( & V_11 -> V_60 -> V_2 , V_74 ) ;
} else {
if ( V_11 -> V_60 != NULL )
F_38 ( & V_11 -> V_60 -> V_2 ,
V_74 ) ;
if ( V_11 -> V_61 != NULL )
F_38 ( & V_11 -> V_61 -> V_2 ,
V_74 ) ;
}
while ( ! F_39 ( & V_11 -> V_50 ) ) {
V_11 -> V_61 = F_25 ( V_11 -> V_50 . V_62 ,
struct V_45 , V_49 ) ;
F_26 ( & V_11 -> V_61 -> V_49 ) ;
F_38 ( & V_11 -> V_61 -> V_2 , V_74 ) ;
}
F_15 ( & V_11 -> V_48 , V_47 ) ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 )
{
F_41 ( & V_11 -> V_60 -> V_2 . V_75 . V_76 ) ;
F_38 ( & V_11 -> V_60 -> V_2 ,
V_77 ) ;
V_11 -> V_60 = V_11 -> V_61 ;
}
static void F_42 ( struct V_10 * V_11 )
{
unsigned long V_12 = 0 ;
F_43 ( & V_11 -> V_48 ) ;
V_11 -> V_61 = F_25 ( V_11 -> V_50 . V_62 ,
struct V_45 , V_49 ) ;
F_26 ( & V_11 -> V_61 -> V_49 ) ;
F_44 ( & V_11 -> V_48 ) ;
V_11 -> V_61 -> V_2 . V_15 = V_16 ;
V_12 = F_8 ( & V_11 -> V_61 -> V_2 , 0 ) ;
V_11 -> V_70 ( V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ,
V_12 + V_11 -> V_24 ,
V_12 + V_11 -> V_25 ) ;
}
static T_1 F_45 ( int V_78 , void * V_79 )
{
struct V_80 * V_81 = & V_82 ;
struct V_10 * V_11 ;
struct V_7 * V_8 ;
enum V_83 V_66 ;
int V_38 = 0 ;
int V_84 = - 1 , V_85 ;
V_38 = * ( int * ) ( V_79 ) ;
if ( ! F_46 ( V_38 ) )
return V_86 ;
V_8 = V_81 -> V_81 [ V_38 ] ;
V_66 = V_8 -> V_11 [ V_14 ] . V_18 . V_18 . V_19 . V_66 ;
for ( V_85 = 0 ; V_85 < V_87 ; V_85 ++ ) {
V_11 = & V_8 -> V_11 [ V_85 ] ;
if ( 0 == V_11 -> V_64 )
continue;
if ( 1 == V_8 -> V_39 . V_40 . V_65 ) {
F_43 ( & V_11 -> V_48 ) ;
if ( F_39 ( & V_11 -> V_50 ) ) {
F_44 ( & V_11 -> V_48 ) ;
continue;
}
F_44 ( & V_11 -> V_48 ) ;
if ( ! V_71 [ V_85 ] [ V_38 ] )
F_40 ( V_11 ) ;
V_71 [ V_85 ] [ V_38 ] = 0 ;
F_42 ( V_11 ) ;
V_71 [ V_85 ] [ V_38 ] = 0 ;
} else {
if ( V_71 [ V_85 ] [ V_38 ] ) {
V_71 [ V_85 ] [ V_38 ] = 0 ;
continue;
}
if ( 0 == V_85 ) {
V_8 -> V_63 ^= 1 ;
V_84 = F_47 ( V_8 -> V_38 ) ;
if ( V_84 != V_8 -> V_63 ) {
if ( 0 == V_84 )
V_8 -> V_63 = V_84 ;
return V_88 ;
}
}
if ( 0 == V_84 ) {
if ( V_11 -> V_60 == V_11 -> V_61 )
continue;
F_40 ( V_11 ) ;
} else if ( 1 == V_84 ) {
F_43 ( & V_11 -> V_48 ) ;
if ( F_39 ( & V_11 -> V_50 ) ||
( V_11 -> V_60 != V_11 -> V_61 ) ) {
F_44 ( & V_11 -> V_48 ) ;
continue;
}
F_44 ( & V_11 -> V_48 ) ;
F_42 ( V_11 ) ;
}
}
}
return V_88 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_57 * V_39 = & V_8 -> V_39 ;
const struct V_89 * V_90 ;
struct V_89 * V_40 = & V_39 -> V_40 ;
struct V_91 * V_92 = & V_8 -> V_93 ;
int V_94 ;
F_3 ( 2 , V_13 , L_8 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
V_90 = & V_96 [ V_94 ] ;
if ( V_90 -> V_97 == 0 ) {
F_3 ( 2 , V_13 , L_9 ) ;
if ( V_90 -> V_98 & V_92 -> V_98 ) {
memcpy ( V_40 , V_90 , sizeof( * V_90 ) ) ;
break;
}
} else {
F_3 ( 2 , V_13 , L_10 ) ;
if ( ! memcmp ( & V_90 -> V_99 , & V_92 -> V_99 ,
sizeof( V_92 -> V_99 ) ) ) {
memcpy ( V_40 , V_90 , sizeof( * V_90 ) ) ;
break;
}
}
}
if ( V_94 == V_95 )
return - V_26 ;
V_11 -> V_18 . V_18 . V_19 . V_100 = V_40 -> V_100 ;
V_11 -> V_100 = V_40 -> V_100 ;
V_11 -> V_18 . V_18 . V_19 . V_101 = V_40 -> V_101 ;
V_11 -> V_101 = V_40 -> V_101 ;
V_11 -> V_18 . V_18 . V_19 . V_102 = V_40 -> V_100 ;
V_39 -> V_103 . V_104 = V_40 -> V_100 ;
V_39 -> V_103 . V_105 = V_40 -> V_65 ;
return 0 ;
}
static void F_27 ( struct V_7 * V_8 )
{
unsigned int V_104 , V_106 , V_20 ;
struct V_91 * V_92 = & ( V_8 -> V_93 ) ;
struct V_57 * V_39 = & V_8 -> V_39 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
enum V_83 V_66 = V_11 -> V_18 . V_18 . V_19 . V_66 ;
F_3 ( 2 , V_13 , L_11 ) ;
if ( V_68 == V_66 ) {
if ( V_39 -> V_40 . V_65 )
V_92 -> V_107 = V_67 ;
else
V_92 -> V_107 = V_108 ;
} else
V_92 -> V_107 = V_11 -> V_18 . V_18 . V_19 . V_66 ;
V_20 = V_11 -> V_18 . V_18 . V_19 . V_20 ;
V_104 = V_11 -> V_18 . V_18 . V_19 . V_102 ;
V_106 = V_20 / ( V_104 * 2 ) ;
if ( ( V_67 == V_92 -> V_107 ) ||
( V_108 == V_92 -> V_107 ) ) {
V_11 -> V_22 = 0 ;
V_11 -> V_23 = V_104 ;
V_11 -> V_24 = V_20 / 2 ;
V_11 -> V_25 = V_20 / 2 + V_104 ;
} else if ( V_109 == V_92 -> V_107 ) {
V_11 -> V_22 = 0 ;
V_11 -> V_23 = V_20 / 4 ;
V_11 -> V_24 = V_20 / 2 ;
V_11 -> V_25 = V_11 -> V_24 + V_20 / 4 ;
} else if ( V_110 == V_92 -> V_107 ) {
V_11 -> V_23 = 0 ;
V_11 -> V_22 = V_20 / 4 ;
V_11 -> V_25 = V_20 / 2 ;
V_11 -> V_24 = V_11 -> V_25 + V_20 / 4 ;
}
if ( ( V_67 == V_92 -> V_107 ) ||
( V_108 == V_92 -> V_107 ) )
V_39 -> V_103 . V_105 = 1 ;
else
V_39 -> V_103 . V_105 = 0 ;
if ( 1 == V_39 -> V_40 . V_65 )
V_39 -> V_103 . V_104 =
V_11 -> V_18 . V_18 . V_19 . V_102 ;
else {
if ( ( V_66 == V_68 )
|| ( V_66 == V_108 ) )
V_39 -> V_103 . V_104 =
V_11 -> V_18 . V_18 . V_19 . V_102 * 2 ;
else
V_39 -> V_103 . V_104 =
V_11 -> V_18 . V_18 . V_19 . V_102 ;
}
V_8 -> V_39 . V_103 . V_98 = V_39 -> V_40 . V_98 ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_12 ) ;
V_11 -> V_18 . V_18 . V_19 . V_66 = V_68 ;
if ( V_36 . V_111 [ V_8 -> V_38 ] == 0 )
V_11 -> V_35 = V_112 ;
else
V_11 -> V_35 = V_34 ;
V_11 -> V_18 . V_18 . V_19 . V_20
= V_36 . V_37 [ V_8 -> V_38 ] ;
if ( V_8 -> V_39 . V_113 . V_114 == V_115 )
V_11 -> V_18 . V_18 . V_19 . V_116 = V_117 ;
else
V_11 -> V_18 . V_18 . V_19 . V_116 = V_118 ;
V_11 -> V_18 . type = V_119 ;
}
static inline enum V_83 F_50 (
struct V_120 * V_113 )
{
return ( V_113 -> V_114 == V_115 ) ? V_67 :
V_108 ;
}
static int F_51 ( struct V_7 * V_8 ,
struct V_121 * V_122 ,
int V_123 )
{
struct V_10 * V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
struct V_57 * V_57 = & V_8 -> V_39 ;
enum V_83 V_66 = V_122 -> V_66 ;
T_2 V_20 , V_104 , V_106 ;
int V_59 = - V_26 ;
F_3 ( 2 , V_13 , L_13 ) ;
if ( V_57 -> V_113 . V_114 == V_115 ) {
if ( V_122 -> V_116 != V_117 ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_14 ) ;
goto exit;
}
V_122 -> V_116 = V_117 ;
}
} else {
if ( V_122 -> V_116 != V_118 ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_15 ) ;
goto exit;
}
V_122 -> V_116 = V_118 ;
}
}
if ( ! ( F_52 ( V_66 ) ) ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_16 ) ;
goto exit;
}
V_66 = F_50 ( & V_57 -> V_113 ) ;
} else if ( V_66 == V_68 )
V_66 = F_50 ( & V_57 -> V_113 ) ;
V_104 = V_122 -> V_102 ;
if ( V_104 < V_57 -> V_40 . V_100 ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_17 ) ;
goto exit;
}
V_104 = V_57 -> V_40 . V_100 ;
}
V_20 = V_122 -> V_20 ;
V_106 = V_20 / ( V_104 * 2 ) ;
if ( V_106 < V_57 -> V_40 . V_101 ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_18 ) ;
goto exit;
}
V_106 = V_57 -> V_40 . V_101 ;
}
if ( ! F_53 ( V_104 , 8 ) ) {
if ( ! V_123 ) {
F_3 ( 2 , V_13 , L_19 ) ;
goto exit;
}
V_104 = ( ( ( V_104 + 7 ) / 8 ) * 8 ) ;
}
if ( V_123 ) {
V_122 -> V_102 = V_104 ;
V_122 -> V_20 = V_104 * V_106 * 2 ;
}
V_122 -> V_100 = V_11 -> V_18 . V_18 . V_19 . V_100 ;
V_122 -> V_101 = V_11 -> V_18 . V_18 . V_19 . V_101 ;
return 0 ;
exit:
return V_59 ;
}
static void F_29 ( struct V_7 * V_8 , int V_124 )
{
struct V_10 * V_11 ;
F_3 ( 2 , V_13 , L_20 ) ;
V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
if ( V_73 == V_8 -> V_38 )
V_11 -> V_70 = V_125 ;
else if ( 2 == V_124 )
V_11 -> V_70 = V_126 ;
else
V_11 -> V_70 = V_127 ;
}
static int F_54 ( struct V_128 * V_129 , struct V_130 * V_131 )
{
struct V_3 * V_4 = V_129 -> V_132 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
int V_59 ;
F_3 ( 2 , V_13 , L_21 ) ;
if ( F_55 ( & V_11 -> V_51 ) )
return - V_133 ;
V_59 = F_56 ( & V_11 -> V_134 , V_131 ) ;
F_19 ( & V_11 -> V_51 ) ;
return V_59 ;
}
static unsigned int F_57 ( struct V_128 * V_129 , T_3 * V_135 )
{
struct V_3 * V_4 = V_129 -> V_132 ;
struct V_7 * V_9 = V_4 -> V_9 ;
struct V_10 * V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
unsigned int V_136 = 0 ;
F_3 ( 2 , V_13 , L_22 ) ;
if ( V_11 -> V_64 ) {
F_21 ( & V_11 -> V_51 ) ;
V_136 = F_58 ( & V_11 -> V_134 , V_129 , V_135 ) ;
F_19 ( & V_11 -> V_51 ) ;
}
return V_136 ;
}
static int F_59 ( struct V_128 * V_129 )
{
struct V_137 * V_138 = F_60 ( V_129 ) ;
struct V_10 * V_11 ;
struct V_91 * V_92 ;
struct V_7 * V_8 ;
struct V_3 * V_4 ;
F_3 ( 2 , V_13 , L_23 ) ;
V_8 = F_61 ( V_138 ) ;
V_92 = & V_8 -> V_93 ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
V_4 = F_62 ( sizeof( struct V_3 ) , V_139 ) ;
if ( NULL == V_4 ) {
F_63 ( L_24 ) ;
return - V_140 ;
}
if ( F_55 ( & V_11 -> V_51 ) ) {
F_64 ( V_4 ) ;
return - V_133 ;
}
V_129 -> V_132 = V_4 ;
V_4 -> V_9 = V_8 ;
V_4 -> V_141 = 0 ;
if ( ! V_8 -> V_141 ) {
V_4 -> V_141 = 1 ;
V_8 -> V_141 = 1 ;
memset ( & ( V_8 -> V_39 ) , 0 , sizeof( struct V_57 ) ) ;
}
V_8 -> V_142 ++ ;
V_4 -> V_143 [ V_14 ] = 0 ;
V_4 -> V_144 = V_145 ;
F_65 ( & V_8 -> V_144 , & V_4 -> V_144 ) ;
F_19 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_66 ( struct V_128 * V_129 )
{
struct V_3 * V_4 = V_129 -> V_132 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
F_3 ( 2 , V_13 , L_25 ) ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_4 -> V_143 [ V_14 ] ) {
V_11 -> V_146 = 0 ;
F_67 ( & V_11 -> V_134 ) ;
F_68 ( V_11 -> V_44 ) ;
}
V_8 -> V_142 -- ;
F_69 ( & V_8 -> V_144 , V_4 -> V_144 ) ;
if ( V_4 -> V_141 )
V_8 -> V_141 = 0 ;
F_19 ( & V_11 -> V_51 ) ;
V_129 -> V_132 = NULL ;
F_64 ( V_4 ) ;
return 0 ;
}
static int F_70 ( struct V_128 * V_128 , void * V_147 ,
struct V_148 * V_149 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
T_4 V_94 = 0 ;
struct V_5 * V_6 ;
int V_59 ;
F_3 ( 2 , V_13 , L_26 ) ;
if ( ( V_72 == V_8 -> V_38 )
|| ( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_141 ) {
F_3 ( 1 , V_13 , L_27 ) ;
return - V_150 ;
}
}
if ( V_119 != V_149 -> type || ! V_55 )
return - V_26 ;
V_94 = V_14 ;
V_11 = & V_8 -> V_11 [ V_94 ] ;
if ( 0 != V_11 -> V_146 )
return - V_150 ;
V_11 -> V_44 = F_71 ( V_55 ) ;
if ( F_72 ( V_11 -> V_44 ) ) {
F_63 ( L_28 ) ;
return F_73 ( V_11 -> V_44 ) ;
}
V_6 = & V_11 -> V_134 ;
V_6 -> type = V_119 ;
V_6 -> V_151 = V_152 | V_153 ;
V_6 -> V_154 = V_4 ;
V_6 -> V_155 = & V_156 ;
V_6 -> V_157 = & V_158 ;
V_6 -> V_159 = sizeof( struct V_45 ) ;
V_6 -> V_160 = V_161 ;
V_6 -> V_162 = 1 ;
V_59 = F_74 ( V_6 ) ;
if ( V_59 ) {
F_63 ( L_29 ) ;
F_68 ( V_11 -> V_44 ) ;
return V_59 ;
}
V_4 -> V_143 [ V_94 ] = 1 ;
V_11 -> V_146 = 1 ;
V_11 -> V_35 = V_149 -> V_35 ;
F_23 ( & V_11 -> V_50 ) ;
return F_75 ( & V_11 -> V_134 , V_149 ) ;
}
static int F_76 ( struct V_128 * V_128 , void * V_147 ,
struct V_163 * V_46 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_30 ) ;
if ( V_11 -> V_18 . type != V_46 -> type )
return - V_26 ;
if ( V_11 -> V_35 != V_34 ) {
F_3 ( 1 , V_13 , L_31 ) ;
return - V_26 ;
}
return F_77 ( & V_11 -> V_134 , V_46 ) ;
}
static int F_78 ( struct V_128 * V_128 , void * V_147 , struct V_163 * V_46 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_163 V_164 = * V_46 ;
F_3 ( 2 , V_13 , L_32 ) ;
if ( V_11 -> V_18 . type != V_164 . type ) {
F_63 ( L_33 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_143 [ V_14 ] ) {
F_63 ( L_34 ) ;
return - V_165 ;
}
return F_79 ( & V_11 -> V_134 , V_46 ) ;
}
static int F_80 ( struct V_128 * V_128 , void * V_147 , struct V_163 * V_46 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
F_3 ( 2 , V_13 , L_35 ) ;
return F_81 ( & V_11 -> V_134 , V_46 ,
( V_128 -> V_166 & V_167 ) ) ;
}
static int F_82 ( struct V_128 * V_128 , void * V_147 ,
enum V_168 V_169 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_7 * V_170 = V_82 . V_81 [ ! V_8 -> V_38 ] ;
struct V_57 * V_58 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_36 ) ;
V_58 = & V_8 -> V_39 ;
if ( V_169 != V_119 ) {
F_3 ( 1 , V_13 , L_37 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_143 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_165 ;
}
if ( V_11 -> V_64 ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_150 ;
}
if ( ( V_8 -> V_38 == V_72 &&
V_170 -> V_11 [ V_14 ] . V_64 &&
V_58 -> V_40 . V_41 == 0 ) ||
( ( V_8 -> V_38 == V_73 ) &&
( 2 == V_170 -> V_11 [ V_14 ] . V_64 ) ) ) {
F_3 ( 1 , V_13 , L_40 ) ;
return - V_150 ;
}
V_59 = F_51 ( V_8 , & V_11 -> V_18 . V_18 . V_19 , 0 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_172 , 1 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 ) {
F_3 ( 1 , V_13 , L_41 ) ;
return V_59 ;
}
V_59 = F_84 ( & V_11 -> V_134 , V_169 ) ;
if ( V_59 ) {
F_3 ( 1 , V_13 , L_42 ) ;
return V_59 ;
}
return V_59 ;
}
static int F_85 ( struct V_128 * V_128 , void * V_147 ,
enum V_168 V_169 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 ;
F_3 ( 2 , V_13 , L_43 ) ;
if ( V_169 != V_119 ) {
F_3 ( 1 , V_13 , L_37 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_143 [ V_14 ] ) {
F_3 ( 1 , V_13 , L_38 ) ;
return - V_165 ;
}
if ( ! V_11 -> V_64 ) {
F_3 ( 1 , V_13 , L_39 ) ;
return - V_26 ;
}
if ( V_72 == V_8 -> V_38 ) {
F_32 ( 0 ) ;
F_31 ( 0 ) ;
} else {
F_35 ( 0 ) ;
F_34 ( 0 ) ;
}
V_11 -> V_64 = 0 ;
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_172 , 0 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 )
F_3 ( 1 , V_13 , L_44 ) ;
return F_86 ( & V_11 -> V_134 , V_169 ) ;
}
static int F_87 (
struct V_53 * V_175 ,
struct V_176 * V_177 ,
int V_178 )
{
struct V_179 * V_180 ;
const char * V_181 ;
int V_85 ;
F_3 ( 2 , V_13 , L_45 ) ;
V_181 = V_177 -> V_182 [ V_178 ] . V_181 ;
if ( V_181 == NULL )
return - 1 ;
for ( V_85 = 0 ; V_85 < V_175 -> V_183 ; V_85 ++ ) {
V_180 = & V_175 -> V_180 [ V_85 ] ;
if ( ! strcmp ( V_180 -> V_184 , V_181 ) )
return V_85 ;
}
return - 1 ;
}
static int F_88 (
struct V_53 * V_175 ,
struct V_7 * V_8 ,
int V_94 )
{
struct V_176 * V_177 =
& V_175 -> V_185 [ V_8 -> V_38 ] ;
struct V_179 * V_180 = NULL ;
struct V_186 * V_171 = NULL ;
T_2 V_187 = 0 , V_188 = 0 ;
int V_189 ;
int V_59 ;
V_189 = F_87 ( V_175 , V_177 , V_94 ) ;
if ( V_189 >= 0 ) {
V_171 = V_82 . V_171 [ V_189 ] ;
V_180 = & V_175 -> V_180 [ V_189 ] ;
}
if ( V_171 && V_175 -> V_190 ) {
V_59 = V_175 -> V_190 ( V_8 -> V_38 ,
V_180 -> V_184 ) ;
if ( V_59 < 0 ) {
F_3 ( 1 , V_13 , L_46 \
L_47 ,
V_180 -> V_184 , V_94 ) ;
return V_59 ;
}
}
if ( V_171 ) {
V_187 = V_177 -> V_182 [ V_94 ] . V_191 ;
V_188 = V_177 -> V_182 [ V_94 ] . V_192 ;
V_59 = F_83 ( V_171 , V_93 , V_193 ,
V_187 , V_188 , 0 ) ;
if ( V_59 < 0 && V_59 != - V_173 ) {
F_3 ( 1 , V_13 , L_48 ) ;
return V_59 ;
}
}
V_8 -> V_194 = V_94 ;
V_8 -> V_171 = V_171 ;
V_8 -> V_39 . V_113 = V_177 -> V_195 ;
V_8 -> V_196 -> V_197 = V_177 -> V_182 [ V_94 ] . V_187 . V_198 ;
return 0 ;
}
static int F_89 ( struct V_128 * V_128 , void * V_147 , T_5 * V_199 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_49 ) ;
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_200 , V_199 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_201 ;
if ( V_59 ) {
F_3 ( 1 , V_13 , L_50 ) ;
return V_59 ;
}
return 0 ;
}
static int F_90 ( struct V_128 * V_128 , void * V_147 , T_5 * V_198 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
F_3 ( 2 , V_13 , L_51 ) ;
* V_198 = V_8 -> V_93 . V_98 ;
return 0 ;
}
static int F_91 ( struct V_128 * V_128 , void * V_147 , T_5 V_199 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_52 ) ;
if ( V_11 -> V_64 ) {
F_63 ( L_53 ) ;
return - V_150 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_141 ) {
F_3 ( 1 , V_13 , L_27 ) ;
return - V_150 ;
}
}
V_59 = F_92 ( & V_8 -> V_144 , V_4 -> V_144 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_141 = 1 ;
V_8 -> V_93 . V_98 = V_199 ;
memset ( & V_8 -> V_93 . V_99 , 0 , sizeof( V_8 -> V_93 . V_99 ) ) ;
if ( F_48 ( V_8 ) ) {
F_63 ( L_54 ) ;
return - V_26 ;
}
F_49 ( V_8 ) ;
V_59 = F_83 ( V_8 -> V_171 , V_202 , V_203 , V_199 ) ;
if ( V_59 && V_59 != - V_173 && V_59 != - V_174 ) {
F_3 ( 1 , V_13 , L_55 ) ;
return V_59 ;
}
return 0 ;
}
static int F_93 ( struct V_128 * V_128 , void * V_147 ,
struct V_204 * V_187 )
{
struct V_53 * V_90 = V_55 -> V_56 ;
struct V_176 * V_177 ;
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
V_177 = & V_90 -> V_185 [ V_8 -> V_38 ] ;
if ( V_187 -> V_94 >= V_177 -> V_205 ) {
F_3 ( 1 , V_13 , L_56 ) ;
return - V_26 ;
}
memcpy ( V_187 , & V_177 -> V_182 [ V_187 -> V_94 ] . V_187 ,
sizeof( * V_187 ) ) ;
return 0 ;
}
static int F_94 ( struct V_128 * V_128 , void * V_147 , unsigned int * V_94 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
* V_94 = V_8 -> V_194 ;
return 0 ;
}
static int F_95 ( struct V_128 * V_128 , void * V_147 , unsigned int V_94 )
{
struct V_53 * V_90 = V_55 -> V_56 ;
struct V_176 * V_177 ;
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
int V_59 ;
V_177 = & V_90 -> V_185 [ V_8 -> V_38 ] ;
if ( V_94 >= V_177 -> V_205 )
return - V_26 ;
if ( V_11 -> V_64 ) {
F_63 ( L_57 ) ;
return - V_150 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_141 ) {
F_3 ( 1 , V_13 , L_27 ) ;
return - V_150 ;
}
}
V_59 = F_92 ( & V_8 -> V_144 , V_4 -> V_144 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_141 = 1 ;
return F_88 ( V_90 , V_8 , V_94 ) ;
}
static int F_96 ( struct V_128 * V_128 , void * V_147 ,
struct V_206 * V_18 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_18 -> V_94 != 0 ) {
F_3 ( 1 , V_13 , L_58 ) ;
return - V_26 ;
}
if ( V_8 -> V_39 . V_113 . V_114 == V_115 ) {
V_18 -> type = V_119 ;
strcpy ( V_18 -> V_207 , L_59 ) ;
V_18 -> V_116 = V_117 ;
} else {
V_18 -> type = V_119 ;
strcpy ( V_18 -> V_207 , L_60 ) ;
V_18 -> V_116 = V_118 ;
}
return 0 ;
}
static int F_97 ( struct V_128 * V_128 , void * V_147 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_121 * V_122 = & V_18 -> V_18 . V_19 ;
return F_51 ( V_8 , V_122 , 1 ) ;
}
static int F_98 ( struct V_128 * V_128 , void * V_147 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_11 -> V_18 . type != V_18 -> type )
return - V_26 ;
* V_18 = V_11 -> V_18 ;
return 0 ;
}
static int F_99 ( struct V_128 * V_128 , void * V_147 ,
struct V_28 * V_18 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
struct V_121 * V_122 ;
int V_59 = 0 ;
F_3 ( 2 , V_13 , L_61 , V_208 ) ;
if ( V_11 -> V_64 ) {
F_3 ( 1 , V_13 , L_62 ) ;
return - V_150 ;
}
if ( ( V_72 == V_8 -> V_38 ) ||
( V_73 == V_8 -> V_38 ) ) {
if ( ! V_4 -> V_141 ) {
F_3 ( 1 , V_13 , L_27 ) ;
return - V_150 ;
}
}
V_59 = F_92 ( & V_8 -> V_144 , V_4 -> V_144 ) ;
if ( 0 != V_59 )
return V_59 ;
V_4 -> V_141 = 1 ;
V_122 = & V_18 -> V_18 . V_19 ;
V_59 = F_51 ( V_8 , V_122 , 0 ) ;
if ( V_59 )
return V_59 ;
V_11 -> V_18 = * V_18 ;
return 0 ;
}
static int F_100 ( struct V_128 * V_128 , void * V_147 ,
struct V_209 * V_210 )
{
struct V_53 * V_90 = V_55 -> V_56 ;
V_210 -> V_211 = V_212 | V_213 ;
V_210 -> V_214 = V_210 -> V_211 | V_215 ;
snprintf ( V_210 -> V_216 , sizeof( V_210 -> V_216 ) , L_63 , F_101 ( V_55 ) ) ;
snprintf ( V_210 -> V_217 , sizeof( V_210 -> V_217 ) , L_64 ,
F_101 ( V_55 ) ) ;
F_102 ( V_210 -> V_218 , V_90 -> V_219 , sizeof( V_210 -> V_218 ) ) ;
return 0 ;
}
static int F_103 ( struct V_128 * V_128 , void * V_147 ,
enum V_220 * V_144 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
* V_144 = F_104 ( & V_8 -> V_144 ) ;
return 0 ;
}
static int F_105 ( struct V_128 * V_128 , void * V_147 , enum V_220 V_221 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
return F_106 ( & V_8 -> V_144 , & V_4 -> V_144 , V_221 ) ;
}
static int F_107 ( struct V_128 * V_128 , void * V_147 ,
struct V_222 * V_223 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 [ V_14 ] ;
if ( V_119 != V_223 -> type )
return - V_26 ;
V_223 -> V_224 . V_225 = 0 ;
V_223 -> V_224 . V_226 = 0 ;
V_223 -> V_224 . V_101 = V_11 -> V_101 ;
V_223 -> V_224 . V_100 = V_11 -> V_100 ;
V_223 -> V_227 = V_223 -> V_224 ;
return 0 ;
}
static int
F_108 ( struct V_128 * V_128 , void * V_147 ,
struct V_228 * V_229 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_230 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_26 ;
return V_59 ;
}
static int
F_109 ( struct V_128 * V_128 , void * V_147 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_59 ;
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_232 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
return - V_201 ;
return V_59 ;
}
static int F_110 ( struct V_128 * V_128 , void * V_147 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_57 * V_39 = & V_8 -> V_39 ;
struct V_89 * V_40 = & V_39 -> V_40 ;
struct V_91 * V_92 = & V_8 -> V_93 ;
struct V_233 * V_234 = & V_92 -> V_99 . V_234 ;
int V_59 ;
if ( V_229 -> type != V_235 ) {
F_3 ( 2 , V_13 , L_65 ) ;
return - V_26 ;
}
V_59 = F_83 ( V_8 -> V_171 , V_93 , V_236 , V_229 ) ;
if ( V_59 == - V_173 || V_59 == - V_174 )
V_59 = 0 ;
if ( V_59 < 0 ) {
F_3 ( 2 , V_13 , L_66 ) ;
return V_59 ;
}
if ( ! ( V_229 -> V_234 . V_100 && V_229 -> V_234 . V_101 &&
( V_229 -> V_234 . V_237 ||
V_229 -> V_234 . V_238 ||
V_229 -> V_234 . V_239 ) &&
V_229 -> V_234 . V_240 &&
( V_229 -> V_234 . V_241 ||
V_229 -> V_234 . V_242 ) ) ) {
F_3 ( 2 , V_13 , L_67
L_68
L_69
L_70
L_71 ) ;
return - V_26 ;
}
V_92 -> V_99 = * V_229 ;
V_40 -> V_243 = F_111 ( V_234 ) - 8 ;
V_40 -> V_244 = V_234 -> V_100 ;
V_40 -> V_245 = 1 ;
V_40 -> V_246 = V_234 -> V_242 + V_234 -> V_241 + 1 ;
V_40 -> V_247 = F_112 ( V_234 ) ;
if ( V_234 -> V_248 ) {
if ( V_234 -> V_249 || V_234 -> V_250 || V_234 -> V_251 ) {
V_40 -> V_252 = V_40 -> V_247 / 2 -
( V_234 -> V_240 - 1 ) ;
V_40 -> V_253 = V_40 -> V_247 / 2 + 1 ;
V_40 -> V_254 = V_40 -> V_253 + V_234 -> V_251 +
V_234 -> V_249 + 1 ;
V_40 -> V_255 = V_40 -> V_247 -
( V_234 -> V_250 - 1 ) ;
} else {
F_3 ( 2 , V_13 , L_72
L_73 ) ;
return - V_26 ;
}
} else {
V_40 -> V_252 = V_40 -> V_247 - ( V_234 -> V_240 - 1 ) ;
}
strncpy ( V_40 -> V_184 , L_74 , V_256 ) ;
V_40 -> V_100 = V_234 -> V_100 ;
V_40 -> V_101 = V_234 -> V_101 ;
V_40 -> V_65 = V_234 -> V_248 ? 0 : 1 ;
V_40 -> V_41 = 0 ;
V_40 -> V_257 = 0 ;
V_40 -> V_258 = 0 ;
V_40 -> V_97 = 1 ;
V_40 -> V_98 = 0 ;
V_92 -> V_98 = 0 ;
return 0 ;
}
static int F_113 ( struct V_128 * V_128 , void * V_147 ,
struct V_231 * V_229 )
{
struct V_3 * V_4 = V_147 ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_91 * V_92 = & V_8 -> V_93 ;
* V_229 = V_92 -> V_99 ;
return 0 ;
}
static int F_114 ( struct V_128 * V_129 , void * V_147 )
{
F_115 ( & V_82 . V_259 , 0 , V_202 , V_260 ) ;
return 0 ;
}
static int F_116 ( void )
{
int V_261 = 0 , V_85 , V_262 ;
int V_263 ;
if ( ( V_264 > 0 ) &&
( V_264 < V_36 . V_43 ) )
V_264 = V_36 . V_43 ;
if ( ( V_265 > 0 ) &&
( V_265 < V_36 . V_43 ) )
V_265 = V_36 . V_43 ;
if ( V_266 < V_36 . V_267 [ V_72 ] )
V_266 =
V_36 . V_267 [ V_72 ] ;
if ( V_268 < V_36 . V_267 [ V_73 ] )
V_268 =
V_36 . V_267 [ V_73 ] ;
V_36 . V_111 [ V_72 ] = V_264 ;
V_36 . V_111 [ V_73 ] = V_265 ;
if ( V_264 ) {
V_36 . V_37 [ V_72 ]
= V_266 ;
}
if ( V_265 ) {
V_36 . V_37 [ V_73 ]
= V_268 ;
}
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_82 . V_81 [ V_85 ] =
F_62 ( sizeof( * V_82 . V_81 [ V_85 ] ) , V_139 ) ;
if ( ! V_82 . V_81 [ V_85 ] ) {
V_263 = V_85 ;
V_261 = - V_140 ;
goto V_270;
}
}
return 0 ;
V_270:
for ( V_262 = 0 ; V_262 < V_263 ; V_262 ++ )
F_64 ( V_82 . V_81 [ V_262 ] ) ;
return V_261 ;
}
static int F_117 ( struct V_271 * V_272 ,
struct V_186 * V_273 ,
struct V_274 * V_275 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_82 . V_90 -> V_183 ; V_85 ++ )
if ( ! strcmp ( V_82 . V_90 -> V_180 [ V_85 ] . V_184 ,
V_273 -> V_184 ) ) {
V_82 . V_171 [ V_85 ] = V_273 ;
return 0 ;
}
return - V_26 ;
}
static int F_118 ( void )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_85 , V_262 , V_261 , V_276 ;
for ( V_262 = 0 ; V_262 < V_269 ; V_262 ++ ) {
V_8 = V_82 . V_81 [ V_262 ] ;
V_8 -> V_38 = V_262 ;
V_11 = & ( V_8 -> V_11 [ V_14 ] ) ;
F_119 ( & V_11 -> V_48 ) ;
F_120 ( & V_11 -> V_51 ) ;
V_8 -> V_196 -> V_51 = & V_11 -> V_51 ;
F_121 ( & V_8 -> V_144 ) ;
F_122 ( V_8 -> V_196 , V_8 ) ;
V_261 = F_88 ( V_82 . V_90 , V_8 , 0 ) ;
if ( V_261 )
goto V_277;
V_261 = F_123 ( V_8 -> V_196 ,
V_278 , ( V_262 ? 1 : 0 ) ) ;
if ( V_261 )
goto V_277;
}
F_124 ( & V_82 . V_259 , L_75 ) ;
return 0 ;
V_277:
for ( V_276 = 0 ; V_276 < V_262 ; V_276 ++ ) {
V_8 = V_82 . V_81 [ V_276 ] ;
F_125 ( V_8 -> V_196 ) ;
}
F_64 ( V_82 . V_171 ) ;
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
F_126 ( V_8 -> V_196 ) ;
}
F_127 ( & V_82 . V_259 ) ;
return V_261 ;
}
static int F_128 ( struct V_271 * V_272 )
{
return F_118 () ;
}
static T_6 int F_129 ( struct V_279 * V_280 )
{
struct V_179 * V_281 ;
int V_85 , V_262 , V_261 ;
int V_282 = 0 ;
struct V_283 * V_284 ;
struct V_7 * V_8 ;
struct V_137 * V_285 ;
struct V_286 * V_136 ;
int V_183 ;
T_7 V_33 ;
V_55 = & V_280 -> V_81 ;
V_261 = F_116 () ;
if ( V_261 ) {
F_130 ( V_55 -> V_216 , L_76 ) ;
return V_261 ;
}
V_261 = F_131 ( V_55 , & V_82 . V_259 ) ;
if ( V_261 ) {
F_130 ( V_55 -> V_216 , L_77 ) ;
return V_261 ;
}
while ( ( V_136 = F_132 ( V_280 , V_287 , V_282 ) ) ) {
V_261 = F_133 ( & V_280 -> V_81 , V_136 -> V_288 , F_45 ,
V_289 , L_78 ,
( void * ) ( & V_82 . V_81 [ V_282 ] ->
V_38 ) ) ;
if ( V_261 ) {
V_261 = - V_26 ;
goto V_290;
}
V_282 ++ ;
}
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
V_285 = F_134 () ;
if ( NULL == V_285 ) {
for ( V_262 = 0 ; V_262 < V_85 ; V_262 ++ ) {
V_8 = V_82 . V_81 [ V_262 ] ;
F_126 ( V_8 -> V_196 ) ;
}
V_261 = - V_140 ;
goto V_290;
}
* V_285 = V_291 ;
V_285 -> V_259 = & V_82 . V_259 ;
V_285 -> V_292 = F_126 ;
snprintf ( V_285 -> V_184 , sizeof( V_285 -> V_184 ) ,
L_79 ,
V_293 ) ;
V_8 -> V_196 = V_285 ;
}
V_136 = F_132 ( V_280 , V_294 , 0 ) ;
if ( V_136 ) {
V_33 = F_135 ( V_136 ) ;
for ( V_262 = 0 ; V_262 < V_269 ; V_262 ++ ) {
V_8 = V_82 . V_81 [ V_262 ] ;
V_8 -> V_38 = V_262 ;
V_36 . V_42 [ V_8 -> V_38 ] = 0 ;
if ( V_33 )
V_36 . V_42 [ V_8 -> V_38 ] =
V_33 / 2 ;
}
}
V_82 . V_90 = V_280 -> V_81 . V_56 ;
V_183 = V_82 . V_90 -> V_183 ;
V_82 . V_171 = F_62 ( sizeof( struct V_186 * ) * V_183 ,
V_139 ) ;
if ( V_82 . V_171 == NULL ) {
F_63 ( L_80 ) ;
V_261 = - V_140 ;
goto V_295;
}
if ( ! V_82 . V_90 -> V_296 ) {
V_284 = F_136 ( 1 ) ;
for ( V_85 = 0 ; V_85 < V_183 ; V_85 ++ ) {
V_281 = & V_82 . V_90 -> V_180 [ V_85 ] ;
V_82 . V_171 [ V_85 ] =
F_137 ( & V_82 . V_259 ,
V_284 ,
& V_281 ->
V_297 ,
NULL ) ;
if ( ! V_82 . V_171 [ V_85 ] ) {
F_63 ( L_81 ) ;
V_261 = - V_174 ;
goto V_298;
}
F_124 ( & V_82 . V_259 ,
L_82 ,
V_281 -> V_184 ) ;
}
F_118 () ;
} else {
V_82 . V_272 . V_299 = V_82 . V_90 -> V_275 ;
V_82 . V_272 . V_300 = V_82 . V_90 -> V_296 [ 0 ] ;
V_82 . V_272 . V_301 = F_117 ;
V_82 . V_272 . V_302 = F_128 ;
V_261 = F_138 ( & V_82 . V_259 ,
& V_82 . V_272 ) ;
if ( V_261 ) {
F_63 ( L_83 ) ;
V_261 = - V_26 ;
goto V_298;
}
}
return 0 ;
V_298:
F_64 ( V_82 . V_171 ) ;
V_295:
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
F_126 ( V_8 -> V_196 ) ;
}
V_290:
F_127 ( & V_82 . V_259 ) ;
return V_261 ;
}
static int F_139 ( struct V_279 * V_303 )
{
struct V_7 * V_8 ;
int V_85 ;
F_127 ( & V_82 . V_259 ) ;
F_64 ( V_82 . V_171 ) ;
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
F_125 ( V_8 -> V_196 ) ;
F_64 ( V_82 . V_81 [ V_85 ] ) ;
}
return 0 ;
}
static int F_140 ( struct V_303 * V_81 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_142 && V_11 -> V_146 ) {
if ( V_8 -> V_38 == V_72 ) {
F_32 ( 0 ) ;
F_31 ( 0 ) ;
}
if ( V_8 -> V_38 == V_73 ||
V_11 -> V_64 == 2 ) {
F_35 ( 0 ) ;
F_34 ( 0 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
static int F_141 ( struct V_303 * V_81 )
{
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_269 ; V_85 ++ ) {
V_8 = V_82 . V_81 [ V_85 ] ;
V_11 = & V_8 -> V_11 [ V_14 ] ;
F_21 ( & V_11 -> V_51 ) ;
if ( V_8 -> V_142 && V_11 -> V_146 ) {
if ( V_8 -> V_38 == V_72 ) {
F_32 ( 1 ) ;
F_31 ( 1 ) ;
}
if ( V_8 -> V_38 == V_73 ||
V_11 -> V_64 == 2 ) {
F_35 ( 1 ) ;
F_34 ( 1 ) ;
}
}
F_19 ( & V_11 -> V_51 ) ;
}
return 0 ;
}
