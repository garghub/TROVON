static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_5 * V_6 = V_2 -> V_5 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_8 = & V_4 -> V_10 -> V_8 [ V_11 ] ;
if ( V_2 -> V_12 != V_13 &&
V_2 -> V_12 != V_14 ) {
F_3 ( V_2 , 0 , V_8 -> V_15 . V_15 . V_16 . V_17 ) ;
if ( F_4 ( V_2 , 0 ) &&
F_5 ( V_2 , 0 ) > F_6 ( V_2 , 0 ) )
goto V_18;
V_9 = F_7 ( V_2 , 0 ) ;
if ( V_6 -> V_19 &&
( V_20 != V_6 -> type ) ) {
if ( ! F_8 ( V_9 + V_8 -> V_21 ) ||
! F_8 ( V_9 + V_8 -> V_22 ) ||
! F_8 ( V_9 + V_8 -> V_23 ) ||
! F_8 ( V_9 + V_8 -> V_24 ) )
goto V_18;
}
}
return 0 ;
V_18:
F_9 ( L_1 ) ;
return - V_25 ;
}
static int F_10 ( struct V_5 * V_26 ,
const struct V_27 * V_15 ,
unsigned int * V_28 , unsigned int * V_29 ,
unsigned int V_30 [] , void * V_31 [] )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
unsigned long V_34 ;
if ( V_35 == V_8 -> V_36 ) {
V_34 = V_37 . V_38 [ V_33 -> V_39 ] ;
if ( V_33 -> V_40 . V_41 . V_42 == 0 ) {
if ( V_37 . V_43 [ V_33 -> V_39 ] )
while ( V_34 * * V_28 >
( V_37 . V_43 [ 0 ]
+ V_37 . V_43 [ 1 ] ) )
( * V_28 ) -- ;
} else {
if ( V_37 . V_43 [ V_33 -> V_39 ] )
while ( V_34 * * V_28 >
V_37 . V_43 [ V_33 -> V_39 ] )
( * V_28 ) -- ;
}
} else {
V_34 = V_8 -> V_15 . V_15 . V_16 . V_17 ;
}
if ( * V_28 < V_37 . V_44 )
* V_28 = V_37 . V_44 ;
* V_29 = 1 ;
V_30 [ 0 ] = V_34 ;
V_31 [ 0 ] = V_8 -> V_45 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_46 * V_47 = F_12 ( V_2 ,
struct V_46 , V_2 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_13 ( & V_8 -> V_49 , V_48 ) ;
F_14 ( & V_47 -> V_50 , & V_8 -> V_51 ) ;
F_15 ( & V_8 -> V_49 , V_48 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_46 * V_47 = F_12 ( V_2 ,
struct V_46 , V_2 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_13 ( & V_8 -> V_49 , V_48 ) ;
if ( V_2 -> V_12 == V_13 )
F_17 ( & V_47 -> V_50 ) ;
F_15 ( & V_8 -> V_49 , V_48 ) ;
}
static void F_18 ( struct V_5 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_19 ( & V_8 -> V_52 ) ;
}
static void F_20 ( struct V_5 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_12 ( V_2 ,
struct V_46 , V_2 ) ;
F_23 ( & V_47 -> V_50 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_26 , unsigned int V_53 )
{
struct V_54 * V_55 =
V_56 -> V_57 ;
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_58 * V_59 = & V_33 -> V_40 ;
unsigned long V_9 = 0 ;
unsigned long V_48 ;
int V_60 ;
F_13 ( & V_8 -> V_49 , V_48 ) ;
if ( F_25 ( & V_8 -> V_51 ) ) {
F_15 ( & V_8 -> V_49 , V_48 ) ;
F_9 ( L_2 ) ;
return - V_61 ;
}
V_8 -> V_62 = V_8 -> V_63 =
F_26 ( V_8 -> V_51 . V_64 ,
struct V_46 , V_50 ) ;
F_27 ( & V_8 -> V_63 -> V_50 ) ;
F_15 ( & V_8 -> V_49 , V_48 ) ;
V_8 -> V_63 -> V_2 . V_12 = V_13 ;
V_33 -> V_65 = 0 ;
V_8 -> V_66 = 1 ;
V_9 = F_7 ( & V_8 -> V_63 -> V_2 , 0 ) ;
F_28 ( V_33 ) ;
if ( ( V_33 -> V_40 . V_41 . V_67 &&
( ( V_8 -> V_15 . V_15 . V_16 . V_68 != V_69 )
&& ( V_8 -> V_15 . V_15 . V_16 . V_68 != V_70 ) ) )
|| ( ! V_33 -> V_40 . V_41 . V_67
&& ( V_8 -> V_15 . V_15 . V_16 . V_68 == V_69 ) ) ) {
F_9 ( L_3 ) ;
return - V_25 ;
}
if ( V_55 -> V_71 ) {
V_60 = V_55 -> V_71 ( V_33 -> V_40 . V_41 .
V_42 , V_33 -> V_40 . V_41 . V_72 ) ;
if ( V_60 < 0 ) {
F_9 ( L_4 ) ;
return V_60 ;
}
}
V_60 = F_29 ( V_59 , V_33 -> V_39 + 2 ) ;
if ( V_60 < 0 )
return V_60 ;
V_8 -> V_66 = V_60 ;
F_30 ( V_33 , V_60 ) ;
V_8 -> V_73 ( ( V_9 + V_8 -> V_21 ) ,
( V_9 + V_8 -> V_22 ) ,
( V_9 + V_8 -> V_23 ) ,
( V_9 + V_8 -> V_24 ) ) ;
V_74 [ V_11 ] [ V_33 -> V_39 ] = 1 ;
if ( V_75 == V_33 -> V_39 ) {
F_31 () ;
F_32 ( 1 ) ;
F_33 ( 1 ) ;
if ( V_55 -> V_76 [ V_75 ] . V_77 )
F_34 ( 1 ) ;
}
if ( ( V_78 == V_33 -> V_39 )
|| ( V_8 -> V_66 == 2 ) ) {
F_35 () ;
F_36 ( 1 ) ;
F_37 ( 1 ) ;
if ( V_55 -> V_76 [ V_78 ] . V_77 )
F_38 ( 1 ) ;
}
return 0 ;
}
static int F_39 ( struct V_5 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
if ( ! F_40 ( V_26 ) )
return 0 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_13 ( & V_8 -> V_49 , V_48 ) ;
while ( ! F_25 ( & V_8 -> V_51 ) ) {
V_8 -> V_62 = F_26 ( V_8 -> V_51 . V_64 ,
struct V_46 , V_50 ) ;
F_27 ( & V_8 -> V_62 -> V_50 ) ;
F_41 ( & V_8 -> V_62 -> V_2 , V_79 ) ;
}
F_15 ( & V_8 -> V_49 , V_48 ) ;
return 0 ;
}
static void F_42 ( struct V_7 * V_8 )
{
unsigned long V_9 = 0 ;
F_43 ( & V_8 -> V_49 ) ;
V_8 -> V_62 = F_26 ( V_8 -> V_51 . V_64 ,
struct V_46 , V_50 ) ;
F_27 ( & V_8 -> V_62 -> V_50 ) ;
F_44 ( & V_8 -> V_49 ) ;
V_8 -> V_62 -> V_2 . V_12 = V_13 ;
V_9 = F_7 ( & V_8 -> V_62 -> V_2 , 0 ) ;
V_8 -> V_73 ( V_9 + V_8 -> V_21 ,
V_9 + V_8 -> V_22 ,
V_9 + V_8 -> V_23 ,
V_9 + V_8 -> V_24 ) ;
}
static void F_45 ( int V_80 , struct V_7 * V_8 )
{
if ( 0 == V_80 ) {
if ( V_8 -> V_63 == V_8 -> V_62 )
return;
F_46 ( & V_8 -> V_63 -> V_2 . V_81 . V_82 ) ;
F_41 ( & V_8 -> V_63 -> V_2 ,
V_83 ) ;
V_8 -> V_63 = V_8 -> V_62 ;
} else if ( 1 == V_80 ) {
F_43 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_51 )
|| ( V_8 -> V_63 != V_8 -> V_62 ) ) {
F_44 ( & V_8 -> V_49 ) ;
return;
}
F_44 ( & V_8 -> V_49 ) ;
F_42 ( V_8 ) ;
}
}
static T_1 F_47 ( int V_84 , void * V_85 )
{
struct V_86 * V_87 = & V_88 ;
struct V_32 * V_33 ;
struct V_7 * V_8 ;
enum V_89 V_68 ;
int V_80 = - 1 , V_90 ;
int V_39 = 0 ;
V_39 = * ( int * ) ( V_85 ) ;
if ( ! F_48 ( V_39 + 2 ) )
return V_91 ;
V_33 = V_87 -> V_87 [ V_39 ] ;
V_68 = V_33 -> V_8 [ V_11 ] . V_15 . V_15 . V_16 . V_68 ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
V_8 = & V_33 -> V_8 [ V_90 ] ;
if ( 0 == V_8 -> V_66 )
continue;
if ( 1 == V_33 -> V_40 . V_41 . V_67 ) {
F_43 ( & V_8 -> V_49 ) ;
if ( F_25 ( & V_8 -> V_51 ) ) {
F_44 ( & V_8 -> V_49 ) ;
continue;
}
F_44 ( & V_8 -> V_49 ) ;
if ( ! V_74 [ V_90 ] [ V_39 ] ) {
F_46 ( & V_8 -> V_63 -> V_2 .
V_81 . V_82 ) ;
F_41 ( & V_8 -> V_63 -> V_2 ,
V_83 ) ;
V_8 -> V_63 = V_8 -> V_62 ;
}
V_74 [ V_90 ] [ V_39 ] = 0 ;
F_42 ( V_8 ) ;
} else {
if ( V_74 [ V_90 ] [ V_39 ] ) {
V_74 [ V_90 ] [ V_39 ] = 0 ;
continue;
}
if ( 0 == V_90 ) {
V_33 -> V_65 ^= 1 ;
V_80 = F_49 ( V_33 -> V_39 + 2 ) ;
if ( V_80 != V_33 -> V_65 ) {
if ( 0 == V_80 )
V_33 -> V_65 = V_80 ;
return V_93 ;
}
}
F_45 ( V_80 , V_8 ) ;
}
}
return V_93 ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
const struct V_97 * V_98 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_99 ; V_90 ++ ) {
V_98 = & V_100 [ V_90 ] ;
if ( V_98 -> V_72 == 0 ) {
F_51 ( 2 , V_101 , L_5 ) ;
if ( V_98 -> V_102 & V_95 -> V_102 ) {
memcpy ( V_41 , V_98 , sizeof( * V_98 ) ) ;
break;
}
}
}
if ( V_90 == V_99 ) {
F_51 ( 1 , V_101 , L_6 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_52 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
if ( ! V_95 -> V_102 && ! V_95 -> V_103 . V_104 . V_105 )
return - V_25 ;
if ( V_95 -> V_102 ) {
if ( F_50 ( V_33 ) )
return - V_25 ;
}
V_8 -> V_15 . V_15 . V_16 . V_106 = V_41 -> V_106 ;
V_8 -> V_15 . V_15 . V_16 . V_105 = V_41 -> V_105 ;
F_51 ( 1 , V_101 , L_7 ,
V_8 -> V_15 . V_15 . V_16 . V_106 , V_8 -> V_15 . V_15 . V_16 . V_105 ) ;
V_8 -> V_105 = V_41 -> V_105 ;
V_8 -> V_106 = V_41 -> V_106 ;
return 0 ;
}
static void F_28 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_58 * V_40 = & V_33 -> V_40 ;
enum V_89 V_68 = V_8 -> V_15 . V_15 . V_16 . V_68 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
unsigned int V_107 , V_108 , V_17 ;
if ( V_70 == V_8 -> V_15 . V_15 . V_16 . V_68 ) {
if ( V_33 -> V_40 . V_41 . V_67 )
V_95 -> V_109 = V_69 ;
else
V_95 -> V_109 = V_110 ;
} else {
V_95 -> V_109 = V_8 -> V_15 . V_15 . V_16 . V_68 ;
}
V_17 = V_8 -> V_15 . V_15 . V_16 . V_17 ;
V_107 = V_8 -> V_15 . V_15 . V_16 . V_111 ;
V_108 = V_17 / ( V_107 * 2 ) ;
if ( ( V_69 == V_95 -> V_109 ) ||
( V_110 == V_95 -> V_109 ) ) {
V_8 -> V_21 = 0 ;
V_8 -> V_22 = V_107 ;
V_8 -> V_23 = V_17 / 2 ;
V_8 -> V_24 = V_17 / 2 + V_107 ;
} else if ( V_112 == V_95 -> V_109 ) {
V_8 -> V_21 = 0 ;
V_8 -> V_22 = V_17 / 4 ;
V_8 -> V_23 = V_17 / 2 ;
V_8 -> V_24 = V_8 -> V_23 + V_17 / 4 ;
} else if ( V_113 == V_95 -> V_109 ) {
V_8 -> V_22 = 0 ;
V_8 -> V_21 = V_17 / 4 ;
V_8 -> V_24 = V_17 / 2 ;
V_8 -> V_23 = V_8 -> V_24 + V_17 / 4 ;
}
if ( ( V_69 == V_95 -> V_109 ) ||
( V_110 == V_95 -> V_109 ) ) {
V_40 -> V_114 . V_115 = 1 ;
} else {
V_40 -> V_114 . V_115 = 0 ;
}
if ( V_33 -> V_40 . V_41 . V_67 == 1 ) {
V_40 -> V_114 . V_107 =
V_8 -> V_15 . V_15 . V_16 . V_111 ;
} else {
if ( ( V_68 == V_70 ) ||
( V_68 == V_110 ) )
V_40 -> V_114 . V_107 =
V_8 -> V_15 . V_15 . V_16 . V_111 * 2 ;
else
V_40 -> V_114 . V_107 =
V_8 -> V_15 . V_15 . V_16 . V_111 ;
}
V_33 -> V_40 . V_114 . V_102 = V_33 -> V_40 . V_41 . V_102 ;
}
static void F_53 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
V_8 -> V_15 . V_15 . V_16 . V_68 = V_70 ;
if ( V_37 . V_116 [ V_33 -> V_39 ] == 0 )
V_8 -> V_36 = V_117 ;
else
V_8 -> V_36 = V_35 ;
V_8 -> V_15 . V_15 . V_16 . V_17 =
V_37 . V_38 [ V_33 -> V_39 ] ;
V_8 -> V_15 . V_15 . V_16 . V_118 = V_119 ;
V_8 -> V_15 . type = V_120 ;
}
static int F_54 ( struct V_32 * V_33 ,
struct V_121 * V_122 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
enum V_89 V_68 = V_122 -> V_68 ;
T_2 V_17 , V_107 , V_108 ;
if ( V_122 -> V_118 != V_119 )
goto V_123;
if ( ! ( F_55 ( V_68 ) ) )
goto V_123;
if ( V_122 -> V_111 <= 0 )
goto V_124;
V_17 = V_122 -> V_17 ;
if ( F_52 ( V_33 ) )
return - V_25 ;
V_107 = V_122 -> V_111 ;
V_108 = V_17 / ( V_107 * 2 ) ;
if ( ( V_107 < V_33 -> V_40 . V_41 . V_106 ) ||
( V_108 < V_33 -> V_40 . V_41 . V_105 ) )
goto V_124;
if ( ! F_8 ( V_107 ) ) {
F_9 ( L_8 ) ;
return - V_25 ;
}
V_122 -> V_106 = V_8 -> V_15 . V_15 . V_16 . V_106 ;
V_122 -> V_105 = V_8 -> V_15 . V_15 . V_16 . V_105 ;
return 0 ;
V_123:
F_9 ( L_9 ) ;
return - V_25 ;
V_124:
F_9 ( L_10 ) ;
return - V_25 ;
}
static void F_30 ( struct V_32 * V_33 , int V_125 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_78 == V_33 -> V_39 ) {
V_8 -> V_73 = V_126 ;
} else {
if ( 2 == V_125 )
V_8 -> V_73 = V_127 ;
else
V_8 -> V_73 = V_128 ;
}
}
static int F_56 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & ( V_33 -> V_8 [ V_11 ] ) ;
int V_60 ;
F_51 ( 2 , V_101 , L_11 ) ;
if ( F_57 ( & V_8 -> V_52 ) )
return - V_134 ;
V_60 = F_58 ( & V_8 -> V_135 , V_132 ) ;
F_19 ( & V_8 -> V_52 ) ;
return V_60 ;
}
static unsigned int F_59 ( struct V_129 * V_130 , T_3 * V_136 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
unsigned int V_137 = 0 ;
if ( V_8 -> V_66 ) {
F_21 ( & V_8 -> V_52 ) ;
V_137 = F_60 ( & V_8 -> V_135 , V_130 , V_136 ) ;
F_19 ( & V_8 -> V_52 ) ;
}
return V_137 ;
}
static int F_61 ( struct V_129 * V_130 )
{
struct V_138 * V_139 = F_62 ( V_130 ) ;
struct V_32 * V_33 = F_63 ( V_139 ) ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_3 * V_4 ;
V_4 = F_64 ( sizeof( struct V_3 ) , V_140 ) ;
if ( V_4 == NULL ) {
F_9 ( L_12 ) ;
return - V_141 ;
}
if ( F_57 ( & V_8 -> V_52 ) ) {
F_65 ( V_4 ) ;
return - V_134 ;
}
V_130 -> V_133 = V_4 ;
V_4 -> V_10 = V_33 ;
V_4 -> V_142 = 0 ;
if ( ! V_33 -> V_142 ) {
V_4 -> V_142 = 1 ;
V_33 -> V_142 = 1 ;
memset ( & V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
}
F_66 ( & V_33 -> V_143 ) ;
V_4 -> V_144 [ V_11 ] = 0 ;
V_4 -> V_145 = V_146 ;
F_67 ( & V_33 -> V_145 , & V_4 -> V_145 ) ;
F_19 ( & V_8 -> V_52 ) ;
return 0 ;
}
static int F_68 ( struct V_129 * V_130 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
if ( V_4 -> V_144 [ V_11 ] ) {
V_8 -> V_147 = 0 ;
if ( V_75 == V_33 -> V_39 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_78 == V_33 -> V_39 ) ||
( 2 == V_8 -> V_66 ) ) {
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
V_8 -> V_66 = 0 ;
F_69 ( & V_8 -> V_135 ) ;
F_70 ( V_8 -> V_45 ) ;
V_8 -> V_116 =
V_37 . V_116 [ V_33 -> V_39 ] ;
}
F_71 ( & V_33 -> V_143 ) ;
if ( V_4 -> V_142 )
V_33 -> V_142 = 0 ;
F_72 ( & V_33 -> V_145 , V_4 -> V_145 ) ;
V_130 -> V_133 = NULL ;
V_4 -> V_142 = 0 ;
F_19 ( & V_8 -> V_52 ) ;
F_65 ( V_4 ) ;
return 0 ;
}
static int F_73 ( struct V_129 * V_129 , void * V_148 ,
struct V_149 * V_150 )
{
struct V_54 * V_98 = V_56 -> V_57 ;
V_150 -> V_151 = V_152 | V_153 ;
V_150 -> V_154 = V_150 -> V_151 | V_155 ;
snprintf ( V_150 -> V_156 , sizeof( V_150 -> V_156 ) , L_13 , F_74 ( V_56 ) ) ;
snprintf ( V_150 -> V_157 , sizeof( V_150 -> V_157 ) , L_14 ,
F_74 ( V_56 ) ) ;
F_75 ( V_150 -> V_158 , V_98 -> V_159 , sizeof( V_150 -> V_158 ) ) ;
return 0 ;
}
static int F_76 ( struct V_129 * V_129 , void * V_148 ,
struct V_160 * V_15 )
{
if ( V_15 -> V_161 != 0 ) {
F_9 ( L_15 ) ;
return - V_25 ;
}
V_15 -> type = V_120 ;
strcpy ( V_15 -> V_162 , L_16 ) ;
V_15 -> V_118 = V_119 ;
return 0 ;
}
static int F_77 ( struct V_129 * V_129 , void * V_148 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_8 -> V_15 . type != V_15 -> type )
return - V_25 ;
if ( F_52 ( V_33 ) )
return - V_25 ;
* V_15 = V_8 -> V_15 ;
return 0 ;
}
static int F_78 ( struct V_129 * V_129 , void * V_148 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_148 ;
struct V_121 * V_122 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
int V_60 = 0 ;
if ( ( V_75 == V_33 -> V_39 )
|| ( V_78 == V_33 -> V_39 ) ) {
if ( ! V_4 -> V_142 ) {
F_51 ( 1 , V_101 , L_17 ) ;
return - V_163 ;
}
V_60 = F_79 ( & V_33 -> V_145 , V_4 -> V_145 ) ;
if ( 0 != V_60 )
return V_60 ;
V_4 -> V_142 = 1 ;
}
if ( V_8 -> V_66 ) {
F_51 ( 1 , V_101 , L_18 ) ;
return - V_163 ;
}
V_122 = & V_15 -> V_15 . V_16 ;
V_60 = F_54 ( V_33 , V_122 ) ;
if ( V_60 )
return V_60 ;
V_8 -> V_15 . V_15 . V_16 = * V_122 ;
V_8 -> V_15 = * V_15 ;
return 0 ;
}
static int F_80 ( struct V_129 * V_129 , void * V_148 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_121 * V_122 = & V_15 -> V_15 . V_16 ;
int V_60 = 0 ;
V_60 = F_54 ( V_33 , V_122 ) ;
if ( V_60 ) {
* V_122 = V_8 -> V_15 . V_15 . V_16 ;
V_122 -> V_17 = V_122 -> V_106 * V_122 -> V_105 * 2 ;
}
return V_60 ;
}
static int F_81 ( struct V_129 * V_129 , void * V_148 ,
struct V_164 * V_165 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
enum V_89 V_68 ;
struct V_5 * V_6 ;
T_4 V_161 = 0 ;
int V_60 ;
if ( ( V_75 == V_33 -> V_39 )
|| ( V_78 == V_33 -> V_39 ) ) {
if ( ! V_4 -> V_142 ) {
F_9 ( L_17 ) ;
return - V_163 ;
}
}
if ( V_120 != V_165 -> type )
return - V_25 ;
V_161 = V_11 ;
V_8 = & V_33 -> V_8 [ V_161 ] ;
if ( V_8 -> V_15 . type != V_165 -> type || ! V_56 )
return - V_25 ;
if ( 0 != V_8 -> V_147 )
return - V_163 ;
if ( V_165 -> type == V_120 ) {
if ( V_8 -> V_15 . V_15 . V_16 . V_68 == V_70 )
V_68 = V_110 ;
else
V_68 = V_8 -> V_15 . V_15 . V_16 . V_68 ;
} else {
V_68 = V_166 ;
}
V_8 -> V_45 = F_82 ( V_56 ) ;
if ( F_83 ( V_8 -> V_45 ) ) {
F_9 ( L_19 ) ;
return F_84 ( V_8 -> V_45 ) ;
}
V_6 = & V_8 -> V_135 ;
V_6 -> type = V_120 ;
V_6 -> V_167 = V_168 | V_169 ;
V_6 -> V_170 = V_4 ;
V_6 -> V_171 = & V_172 ;
V_6 -> V_173 = & V_174 ;
V_6 -> V_175 = sizeof( struct V_46 ) ;
V_6 -> V_176 = V_177 ;
V_60 = F_85 ( V_6 ) ;
if ( V_60 ) {
F_9 ( L_20 ) ;
F_70 ( V_8 -> V_45 ) ;
return V_60 ;
}
V_4 -> V_144 [ V_161 ] = 1 ;
V_8 -> V_147 = 1 ;
V_8 -> V_36 = V_165 -> V_36 ;
F_23 ( & V_8 -> V_51 ) ;
return F_86 ( & V_8 -> V_135 , V_165 ) ;
}
static int F_87 ( struct V_129 * V_129 , void * V_148 ,
struct V_178 * V_179 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_8 -> V_15 . type != V_179 -> type )
return - V_25 ;
return F_88 ( & V_8 -> V_135 , V_179 ) ;
}
static int F_89 ( struct V_129 * V_129 , void * V_148 , struct V_178 * V_47 )
{
struct V_3 * V_4 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_7 * V_8 = NULL ;
if ( ! V_47 || ! V_148 )
return - V_25 ;
V_4 = V_148 ;
V_33 = V_4 -> V_10 ;
if ( ! V_33 )
return - V_25 ;
V_8 = & ( V_33 -> V_8 [ V_11 ] ) ;
if ( V_8 -> V_15 . type != V_47 -> type )
return - V_25 ;
if ( ! V_4 -> V_144 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_180 ;
}
return F_90 ( & V_8 -> V_135 , V_47 ) ;
}
static int F_91 ( struct V_129 * V_129 , void * V_148 , T_5 V_181 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
int V_60 = 0 ;
if ( ! ( V_181 & V_182 ) )
return - V_25 ;
if ( V_8 -> V_66 ) {
F_9 ( L_22 ) ;
return - V_163 ;
}
V_33 -> V_96 . V_102 = V_181 ;
memset ( & V_33 -> V_96 . V_103 , 0 , sizeof( V_33 -> V_96 . V_103 ) ) ;
if ( F_52 ( V_33 ) )
return - V_25 ;
if ( ( V_33 -> V_40 . V_41 . V_106 *
V_33 -> V_40 . V_41 . V_105 * 2 ) >
V_37 . V_38 [ V_33 -> V_39 ] ) {
F_9 ( L_23 ) ;
return - V_25 ;
}
V_8 -> V_15 . V_15 . V_16 . V_111 = V_8 -> V_15 . V_15 . V_16 . V_106 ;
F_53 ( V_33 ) ;
V_60 = F_92 ( & V_88 . V_183 , 1 , V_96 ,
V_184 , V_181 ) ;
if ( V_60 < 0 ) {
F_9 ( L_24 ) ;
return V_60 ;
}
V_60 = F_92 ( & V_88 . V_183 , 1 , V_185 ,
V_186 , V_181 ) ;
if ( V_60 < 0 )
F_9 ( L_25 ) ;
return V_60 ;
}
static int F_93 ( struct V_129 * V_129 , void * V_148 , T_5 * V_187 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
* V_187 = V_33 -> V_96 . V_102 ;
return 0 ;
}
static int F_94 ( struct V_129 * V_129 , void * V_148 , struct V_178 * V_188 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
return F_95 ( & V_8 -> V_135 , V_188 ,
( V_129 -> V_189 & V_190 ) ) ;
}
static int F_96 ( struct V_129 * V_129 , void * V_148 ,
enum V_191 V_192 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_32 * V_193 = V_88 . V_87 [ ! V_33 -> V_39 ] ;
int V_60 = 0 ;
if ( V_192 != V_120 ) {
F_9 ( L_26 ) ;
return - V_25 ;
}
if ( ! V_4 -> V_144 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_180 ;
}
if ( V_8 -> V_66 ) {
F_9 ( L_27 ) ;
return - V_163 ;
}
if ( ( V_33 -> V_39 == V_75
&& V_193 -> V_8 [ V_11 ] . V_66 &&
V_33 -> V_40 . V_41 . V_42 == 0 )
|| ( ( V_33 -> V_39 == V_78 )
&& ( 2 == V_193 -> V_8 [ V_11 ] . V_66 ) ) ) {
F_9 ( L_28 ) ;
return - V_163 ;
}
V_60 = F_54 ( V_33 , & V_8 -> V_15 . V_15 . V_16 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_97 ( & V_8 -> V_135 , V_192 ) ;
if ( V_60 < 0 ) {
F_9 ( L_29 ) ;
return V_60 ;
}
return V_60 ;
}
static int F_98 ( struct V_129 * V_129 , void * V_148 ,
enum V_191 V_192 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_54 * V_55 =
V_56 -> V_57 ;
if ( V_192 != V_120 ) {
F_9 ( L_26 ) ;
return - V_25 ;
}
if ( ! V_4 -> V_144 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_180 ;
}
if ( ! V_8 -> V_66 ) {
F_9 ( L_27 ) ;
return - V_25 ;
}
if ( V_192 == V_120 ) {
if ( V_75 == V_33 -> V_39 ) {
if ( V_55 ->
V_76 [ V_75 ] . V_77 )
F_34 ( 0 ) ;
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_78 == V_33 -> V_39 ) ||
( 2 == V_8 -> V_66 ) ) {
if ( V_55 ->
V_76 [ V_78 ] . V_77 )
F_38 ( 0 ) ;
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
}
V_8 -> V_66 = 0 ;
return F_99 ( & V_8 -> V_135 , V_192 ) ;
}
static int F_100 ( struct V_129 * V_129 , void * V_148 ,
struct V_194 * V_195 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_120 != V_195 -> type )
return - V_25 ;
V_195 -> V_196 . V_197 = V_195 -> V_196 . V_198 = 0 ;
V_195 -> V_199 . V_197 = V_195 -> V_199 . V_198 = 0 ;
V_195 -> V_199 . V_105 = V_195 -> V_196 . V_105 = V_8 -> V_105 ;
V_195 -> V_199 . V_106 = V_195 -> V_196 . V_106 = V_8 -> V_106 ;
return 0 ;
}
static int F_101 ( struct V_129 * V_129 , void * V_4 ,
struct V_200 * V_201 )
{
struct V_54 * V_98 = V_56 -> V_57 ;
struct V_202 * V_203 ;
struct V_3 * V_204 = V_4 ;
struct V_32 * V_33 = V_204 -> V_10 ;
V_203 = & V_98 -> V_76 [ V_33 -> V_39 ] ;
if ( V_201 -> V_161 >= V_203 -> V_205 ) {
F_51 ( 1 , V_101 , L_30 ) ;
return - V_25 ;
}
* V_201 = V_203 -> V_206 [ V_201 -> V_161 ] . V_201 ;
return 0 ;
}
static int
F_102 ( struct V_54 * V_207 ,
struct V_202 * V_203 , int V_161 )
{
struct V_208 * V_209 ;
const char * V_210 ;
int V_90 ;
F_51 ( 2 , V_101 , L_31 ) ;
if ( V_203 -> V_206 == NULL )
return - 1 ;
V_210 = V_203 -> V_206 [ V_161 ] . V_210 ;
if ( V_210 == NULL )
return - 1 ;
for ( V_90 = 0 ; V_90 < V_207 -> V_211 ; V_90 ++ ) {
V_209 = & V_207 -> V_212 [ V_90 ] ;
if ( ! strcmp ( V_209 -> V_213 , V_210 ) )
return V_90 ;
}
return - 1 ;
}
static int F_103 ( struct V_54 * V_207 ,
struct V_32 * V_33 , int V_161 )
{
struct V_202 * V_203 =
& V_207 -> V_76 [ V_33 -> V_39 ] ;
struct V_208 * V_209 = NULL ;
struct V_214 * V_215 = NULL ;
T_2 V_216 = 0 , V_201 = 0 ;
int V_217 ;
int V_60 ;
V_217 = F_102 ( V_207 , V_203 , V_161 ) ;
if ( V_217 >= 0 ) {
V_215 = V_88 . V_215 [ V_217 ] ;
V_209 = & V_207 -> V_212 [ V_217 ] ;
}
if ( V_215 ) {
V_216 = V_203 -> V_206 [ V_161 ] . V_218 ;
V_201 = V_203 -> V_206 [ V_161 ] . V_219 ;
V_60 = F_104 ( V_215 , V_96 , V_220 , V_216 , V_201 , 0 ) ;
if ( V_60 < 0 && V_60 != - V_221 ) {
F_9 ( L_32 ) ;
return V_60 ;
}
}
V_33 -> V_222 = V_161 ;
V_33 -> V_215 = V_215 ;
if ( V_203 -> V_206 != NULL )
V_33 -> V_223 -> V_224 = V_203 -> V_206 [ V_161 ] . V_201 . V_187 ;
return 0 ;
}
static int F_105 ( struct V_129 * V_129 , void * V_148 , unsigned int V_90 )
{
struct V_54 * V_98 = V_56 -> V_57 ;
struct V_202 * V_203 ;
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
V_203 = & V_98 -> V_76 [ V_33 -> V_39 ] ;
if ( V_90 >= V_203 -> V_205 )
return - V_25 ;
if ( V_8 -> V_66 ) {
F_9 ( L_18 ) ;
return - V_163 ;
}
return F_103 ( V_98 , V_33 , V_90 ) ;
}
static int F_106 ( struct V_129 * V_129 , void * V_148 , unsigned int * V_90 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
* V_90 = V_33 -> V_222 ;
return 0 ;
}
static int F_107 ( struct V_129 * V_129 , void * V_148 , enum V_225 * V_188 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
* V_188 = F_108 ( & V_33 -> V_145 ) ;
return 0 ;
}
static int F_109 ( struct V_129 * V_129 , void * V_148 , enum V_225 V_188 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
return F_110 ( & V_33 -> V_145 , & V_4 -> V_145 , V_188 ) ;
}
static int
F_111 ( struct V_129 * V_129 , void * V_148 ,
struct V_226 * V_227 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
int V_60 ;
V_60 = F_104 ( V_33 -> V_215 , V_96 , V_228 , V_227 ) ;
if ( V_60 == - V_221 || V_60 == - V_229 )
return - V_25 ;
return V_60 ;
}
static int F_112 ( struct V_129 * V_129 , void * V_148 ,
struct V_230 * V_227 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_231 * V_104 = & V_95 -> V_103 . V_104 ;
int V_60 ;
if ( V_227 -> type != V_232 ) {
F_51 ( 2 , V_101 , L_33 ) ;
return - V_25 ;
}
V_60 = F_104 ( V_33 -> V_215 , V_96 , V_233 , V_227 ) ;
if ( V_60 == - V_221 || V_60 == - V_229 )
V_60 = 0 ;
if ( V_60 < 0 ) {
F_51 ( 2 , V_101 , L_34 ) ;
return V_60 ;
}
if ( ! ( V_227 -> V_104 . V_106 && V_227 -> V_104 . V_105 &&
( V_227 -> V_104 . V_234 ||
V_227 -> V_104 . V_235 ||
V_227 -> V_104 . V_236 ) &&
V_227 -> V_104 . V_237 &&
( V_227 -> V_104 . V_238 ||
V_227 -> V_104 . V_239 ) ) ) {
F_51 ( 2 , V_101 , L_35
L_36
L_37
L_38
L_39 ) ;
return - V_25 ;
}
V_95 -> V_103 = * V_227 ;
V_41 -> V_240 = F_113 ( V_104 ) - 8 ;
V_41 -> V_241 = V_104 -> V_106 ;
V_41 -> V_242 = 1 ;
V_41 -> V_243 = V_104 -> V_239 + V_104 -> V_238 + 1 ;
V_41 -> V_244 = F_114 ( V_104 ) ;
if ( V_104 -> V_245 ) {
if ( V_104 -> V_246 || V_104 -> V_247 || V_104 -> V_248 ) {
V_41 -> V_249 = V_41 -> V_244 / 2 -
( V_104 -> V_237 - 1 ) ;
V_41 -> V_250 = V_41 -> V_244 / 2 + 1 ;
V_41 -> V_251 = V_41 -> V_250 + V_104 -> V_248 +
V_104 -> V_246 + 1 ;
V_41 -> V_252 = V_41 -> V_244 -
( V_104 -> V_247 - 1 ) ;
} else {
F_51 ( 2 , V_101 , L_40
L_41 ) ;
return - V_25 ;
}
} else {
V_41 -> V_249 = V_41 -> V_244 - ( V_104 -> V_237 - 1 ) ;
}
strncpy ( V_41 -> V_213 , L_42 ,
V_253 ) ;
V_41 -> V_106 = V_104 -> V_106 ;
V_41 -> V_105 = V_104 -> V_105 ;
V_41 -> V_67 = V_104 -> V_245 ? 0 : 1 ;
V_41 -> V_42 = 0 ;
V_41 -> V_254 = 0 ;
V_41 -> V_255 = 0 ;
V_41 -> V_72 = 1 ;
V_41 -> V_102 = 0 ;
V_95 -> V_102 = 0 ;
return 0 ;
}
static int F_115 ( struct V_129 * V_129 , void * V_148 ,
struct V_230 * V_227 )
{
struct V_3 * V_4 = V_148 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
* V_227 = V_95 -> V_103 ;
return 0 ;
}
static int F_116 ( struct V_129 * V_130 , void * V_148 )
{
F_117 ( & V_88 . V_183 , 0 , V_185 , V_256 ) ;
return 0 ;
}
static int F_118 ( void )
{
int V_257 ;
int V_258 ;
int V_259 ;
int V_260 = 0 , V_90 , V_261 ;
if ( ( V_262 > 0 ) &&
( V_262 < V_37 . V_44 ) )
V_262 = V_37 . V_44 ;
if ( ( V_263 > 0 ) &&
( V_263 < V_37 . V_44 ) )
V_263 = V_37 . V_44 ;
if ( V_264 < V_37 . V_265 [ V_75 ] )
V_264 =
V_37 . V_265 [ V_75 ] ;
if ( V_266 < V_37 . V_265 [ V_78 ] )
V_266 =
V_37 . V_265 [ V_78 ] ;
V_37 . V_116 [ V_75 ] = V_262 ;
if ( V_262 ) {
V_37 . V_38 [ V_75 ] =
V_264 ;
}
V_37 . V_116 [ V_78 ] = V_263 ;
if ( V_263 ) {
V_37 . V_38 [ V_78 ] =
V_266 ;
}
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_88 . V_87 [ V_90 ] =
F_64 ( sizeof( struct V_32 ) , V_140 ) ;
if ( ! V_88 . V_87 [ V_90 ] ) {
V_257 = V_90 ;
V_260 = - V_141 ;
goto V_268;
}
}
V_257 = V_267 ;
V_258 = V_269 ;
V_259 = V_37 . V_116 [ V_90 - 1 ] ;
return 0 ;
V_268:
for ( V_261 = 0 ; V_261 < V_257 ; V_261 ++ )
F_65 ( V_88 . V_87 [ V_261 ] ) ;
return V_260 ;
}
static int F_119 ( struct V_270 * V_271 ,
struct V_214 * V_272 ,
struct V_273 * V_274 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_88 . V_98 -> V_211 ; V_90 ++ )
if ( ! strcmp ( V_88 . V_98 -> V_212 [ V_90 ] . V_213 ,
V_272 -> V_213 ) ) {
V_88 . V_215 [ V_90 ] = V_272 ;
V_88 . V_215 [ V_90 ] -> V_275 = 1 << V_90 ;
return 0 ;
}
return - V_25 ;
}
static int F_120 ( void )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
int V_261 , V_260 , V_276 ;
for ( V_261 = 0 ; V_261 < V_267 ; V_261 ++ ) {
V_33 = V_88 . V_87 [ V_261 ] ;
F_121 ( & V_33 -> V_143 , 0 ) ;
for ( V_276 = 0 ; V_276 < V_92 ; V_276 ++ ) {
V_33 -> V_8 [ V_276 ] . V_116 = 0 ;
V_8 = & V_33 -> V_8 [ V_276 ] ;
V_8 -> V_147 = 0 ;
V_8 -> V_66 = 0 ;
F_122 ( & V_8 -> V_49 ) ;
F_123 ( & V_8 -> V_52 ) ;
V_8 -> V_116 = 0 ;
V_8 -> V_73 = NULL ;
V_8 -> V_21 = 0 ;
V_8 -> V_22 = 0 ;
V_8 -> V_23 = 0 ;
V_8 -> V_24 = 0 ;
V_8 -> V_63 = NULL ;
V_8 -> V_62 = NULL ;
memset ( & V_8 -> V_15 , 0 , sizeof( V_8 -> V_15 ) ) ;
V_8 -> V_116 = V_37 . V_116 [ V_276 ] ;
}
V_33 -> V_142 = 0 ;
if ( V_88 . V_98 -> V_211 )
V_33 -> V_215 = V_88 . V_215 [ 0 ] ;
V_33 -> V_39 = V_261 ;
if ( V_261 < 2 )
V_33 -> V_8 [ V_11 ] . V_116 =
V_37 . V_116 [ V_33 -> V_39 ] ;
else
V_33 -> V_8 [ V_11 ] . V_116 = 0 ;
memset ( & V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
F_124 ( & V_33 -> V_145 ) ;
V_33 -> V_8 [ V_11 ] . V_15 . type =
V_120 ;
V_33 -> V_223 -> V_52 = & V_8 -> V_52 ;
F_125 ( V_33 -> V_223 , V_33 ) ;
V_260 = F_103 ( V_88 . V_98 , V_33 , 0 ) ;
if ( V_260 )
goto V_277;
F_51 ( 1 , V_101 , L_43 ,
( int ) V_33 , ( int ) & V_33 -> V_223 ) ;
V_260 = F_126 ( V_33 -> V_223 ,
V_278 , ( V_261 ? 3 : 2 ) ) ;
if ( V_260 < 0 )
goto V_277;
}
return 0 ;
V_277:
for ( V_276 = 0 ; V_276 < V_261 ; V_276 ++ ) {
V_33 = V_88 . V_87 [ V_276 ] ;
F_127 ( V_33 -> V_223 ) ;
F_128 ( V_33 -> V_223 ) ;
V_33 -> V_223 = NULL ;
}
return V_260 ;
}
static int F_129 ( struct V_270 * V_271 )
{
return F_120 () ;
}
static T_6 int F_130 ( struct V_279 * V_280 )
{
struct V_208 * V_281 ;
int V_90 , V_261 = 0 , V_260 = 0 ;
int V_282 = 0 ;
struct V_283 * V_284 ;
struct V_32 * V_33 ;
struct V_138 * V_285 ;
struct V_286 * V_137 ;
int V_211 ;
T_7 V_34 ;
V_56 = & V_280 -> V_87 ;
V_260 = F_118 () ;
if ( V_260 ) {
F_131 ( V_56 -> V_156 , L_44 ) ;
return V_260 ;
}
V_260 = F_132 ( V_56 , & V_88 . V_183 ) ;
if ( V_260 ) {
F_131 ( V_56 -> V_156 , L_45 ) ;
return V_260 ;
}
while ( ( V_137 = F_133 ( V_280 , V_287 , V_282 ) ) ) {
V_260 = F_134 ( & V_280 -> V_87 , V_137 -> V_288 , F_47 ,
V_289 , L_46 ,
( void * ) ( & V_88 . V_87 [ V_282 ] ->
V_39 ) ) ;
if ( V_260 ) {
V_260 = - V_25 ;
F_9 ( L_47 ) ;
goto V_290;
}
V_282 ++ ;
}
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_285 = F_135 () ;
if ( V_285 == NULL ) {
for ( V_261 = 0 ; V_261 < V_90 ; V_261 ++ ) {
V_33 = V_88 . V_87 [ V_261 ] ;
F_128 ( V_33 -> V_223 ) ;
}
V_260 = - V_141 ;
goto V_290;
}
* V_285 = V_291 ;
V_285 -> V_183 = & V_88 . V_183 ;
V_285 -> V_292 = F_128 ;
V_285 -> V_293 = V_294 ;
snprintf ( V_285 -> V_213 , sizeof( V_285 -> V_213 ) ,
L_48 ,
V_295 ) ;
V_33 -> V_223 = V_285 ;
}
V_137 = F_133 ( V_280 , V_296 , 0 ) ;
if ( V_137 ) {
V_34 = F_136 ( V_137 ) ;
for ( V_261 = 0 ; V_261 < V_267 ; V_261 ++ ) {
V_33 = V_88 . V_87 [ V_261 ] ;
V_33 -> V_39 = V_261 ;
V_37 . V_43 [ V_33 -> V_39 ] = 0 ;
if ( V_34 )
V_37 . V_43 [ V_33 -> V_39 ] =
V_34 / 2 ;
}
}
V_88 . V_98 = V_280 -> V_87 . V_57 ;
V_211 = V_88 . V_98 -> V_211 ;
V_281 = V_88 . V_98 -> V_212 ;
V_88 . V_215 = F_64 ( sizeof( struct V_214 * ) * V_211 ,
V_140 ) ;
if ( V_88 . V_215 == NULL ) {
F_9 ( L_49 ) ;
V_260 = - V_141 ;
goto V_297;
}
if ( ! V_88 . V_98 -> V_298 ) {
V_284 = F_137 ( 1 ) ;
for ( V_90 = 0 ; V_90 < V_211 ; V_90 ++ ) {
V_88 . V_215 [ V_90 ] =
F_138 ( & V_88 . V_183 ,
V_284 ,
& V_281 [ V_90 ] .
V_299 ,
NULL ) ;
if ( ! V_88 . V_215 [ V_90 ] ) {
F_9 ( L_50 ) ;
V_260 = - V_229 ;
goto V_300;
}
if ( V_88 . V_215 [ V_90 ] )
V_88 . V_215 [ V_90 ] -> V_275 = 1 << V_90 ;
}
F_120 () ;
} else {
V_88 . V_271 . V_301 = V_88 . V_98 -> V_274 ;
V_88 . V_271 . V_302 = V_88 . V_98 -> V_298 [ 0 ] ;
V_88 . V_271 . V_303 = F_119 ;
V_88 . V_271 . V_304 = F_129 ;
V_260 = F_139 ( & V_88 . V_183 ,
& V_88 . V_271 ) ;
if ( V_260 ) {
F_9 ( L_51 ) ;
V_260 = - V_25 ;
goto V_300;
}
}
return 0 ;
V_300:
F_65 ( V_88 . V_215 ) ;
V_297:
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
F_128 ( V_33 -> V_223 ) ;
}
V_290:
F_140 ( & V_88 . V_183 ) ;
return V_260 ;
}
static int F_141 ( struct V_279 * V_305 )
{
struct V_32 * V_33 ;
int V_90 ;
F_140 ( & V_88 . V_183 ) ;
F_65 ( V_88 . V_215 ) ;
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
F_127 ( V_33 -> V_223 ) ;
V_33 -> V_223 = NULL ;
F_65 ( V_88 . V_87 [ V_90 ] ) ;
}
return 0 ;
}
static int F_142 ( struct V_305 * V_87 )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
if ( F_143 ( & V_33 -> V_143 ) && V_8 -> V_147 ) {
if ( V_33 -> V_39 == V_75 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( V_33 -> V_39 == V_78 ||
V_8 -> V_66 == 2 ) {
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
}
F_19 ( & V_8 -> V_52 ) ;
}
return 0 ;
}
static int F_144 ( struct V_305 * V_87 )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_267 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
if ( F_143 ( & V_33 -> V_143 ) && V_8 -> V_147 ) {
if ( V_33 -> V_39 == V_75 ) {
F_33 ( 1 ) ;
F_32 ( 1 ) ;
}
if ( V_33 -> V_39 == V_78 ||
V_8 -> V_66 == 2 ) {
F_37 ( 1 ) ;
F_36 ( 1 ) ;
}
}
F_19 ( & V_8 -> V_52 ) ;
}
return 0 ;
}
