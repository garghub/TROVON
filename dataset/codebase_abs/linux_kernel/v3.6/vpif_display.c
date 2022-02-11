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
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_13 ( & V_47 -> V_48 , & V_8 -> V_49 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_46 * V_47 = F_12 ( V_2 ,
struct V_46 , V_2 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
unsigned long V_50 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_15 ( & V_8 -> V_51 , V_50 ) ;
if ( V_2 -> V_12 == V_13 )
F_16 ( & V_47 -> V_48 ) ;
F_17 ( & V_8 -> V_51 , V_50 ) ;
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
F_23 ( & V_47 -> V_48 ) ;
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
int V_60 ;
if ( F_25 ( & V_8 -> V_49 ) ) {
F_9 ( L_2 ) ;
return - V_61 ;
}
V_8 -> V_62 = V_8 -> V_63 =
F_26 ( V_8 -> V_49 . V_64 ,
struct V_46 , V_48 ) ;
F_27 ( & V_8 -> V_63 -> V_48 ) ;
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
V_60 =
V_55 -> V_71 ( V_33 -> V_40 . V_41 . V_42 ,
V_33 -> V_40 . V_41 . V_72 ) ;
if ( V_60 < 0 ) {
F_9 ( L_4 ) ;
return V_60 ;
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
if ( V_74 == V_33 -> V_39 ) {
F_31 () ;
F_32 ( 1 ) ;
F_33 ( 1 ) ;
if ( V_55 -> V_75 )
F_34 ( 1 ) ;
}
if ( ( V_76 == V_33 -> V_39 )
|| ( V_8 -> V_66 == 2 ) ) {
F_35 () ;
F_36 ( 1 ) ;
F_37 ( 1 ) ;
if ( V_55 -> V_77 )
F_38 ( 1 ) ;
}
V_78 [ V_11 ] [ V_33 -> V_39 ] = 1 ;
return 0 ;
}
static int F_39 ( struct V_5 * V_26 )
{
struct V_3 * V_4 = F_2 ( V_26 ) ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
if ( ! F_40 ( V_26 ) )
return 0 ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
while ( ! F_25 ( & V_8 -> V_49 ) ) {
V_8 -> V_62 = F_26 ( V_8 -> V_49 . V_64 ,
struct V_46 , V_48 ) ;
F_27 ( & V_8 -> V_62 -> V_48 ) ;
F_41 ( & V_8 -> V_62 -> V_2 , V_79 ) ;
}
return 0 ;
}
static void F_42 ( struct V_7 * V_8 )
{
unsigned long V_9 = 0 ;
V_8 -> V_62 = F_26 ( V_8 -> V_49 . V_64 ,
struct V_46 , V_48 ) ;
F_27 ( & V_8 -> V_62 -> V_48 ) ;
V_8 -> V_62 -> V_2 . V_12 = V_13 ;
V_9 = F_7 ( & V_8 -> V_62 -> V_2 , 0 ) ;
V_8 -> V_73 ( V_9 + V_8 -> V_21 ,
V_9 + V_8 -> V_22 ,
V_9 + V_8 -> V_23 ,
V_9 + V_8 -> V_24 ) ;
}
static void F_43 ( int V_80 , struct V_7 * V_8 )
{
if ( 0 == V_80 ) {
if ( V_8 -> V_63 == V_8 -> V_62 )
return;
F_44 ( & V_8 -> V_63 -> V_2 . V_81 . V_82 ) ;
F_41 ( & V_8 -> V_63 -> V_2 ,
V_83 ) ;
V_8 -> V_63 = V_8 -> V_62 ;
} else if ( 1 == V_80 ) {
if ( F_25 ( & V_8 -> V_49 )
|| ( V_8 -> V_63 != V_8 -> V_62 ) ) {
return;
}
F_42 ( V_8 ) ;
}
}
static T_1 F_45 ( int V_84 , void * V_85 )
{
struct V_86 * V_87 = & V_88 ;
struct V_32 * V_33 ;
struct V_7 * V_8 ;
enum V_89 V_68 ;
int V_80 = - 1 , V_90 ;
int V_39 = 0 ;
V_39 = * ( int * ) ( V_85 ) ;
if ( ! F_46 ( V_39 + 2 ) )
return V_91 ;
V_33 = V_87 -> V_87 [ V_39 ] ;
V_68 = V_33 -> V_8 [ V_11 ] . V_15 . V_15 . V_16 . V_68 ;
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
V_8 = & V_33 -> V_8 [ V_90 ] ;
if ( 0 == V_8 -> V_66 )
continue;
if ( 1 == V_33 -> V_40 . V_41 . V_67 ) {
if ( F_25 ( & V_8 -> V_49 ) )
continue;
if ( ! V_78 [ V_90 ] [ V_39 ] ) {
F_44 ( & V_8 -> V_63 -> V_2 .
V_81 . V_82 ) ;
F_41 ( & V_8 -> V_63 -> V_2 ,
V_83 ) ;
V_8 -> V_63 = V_8 -> V_62 ;
}
V_78 [ V_90 ] [ V_39 ] = 0 ;
F_42 ( V_8 ) ;
} else {
if ( V_78 [ V_90 ] [ V_39 ] ) {
V_78 [ V_90 ] [ V_39 ] = 0 ;
continue;
}
if ( 0 == V_90 ) {
V_33 -> V_65 ^= 1 ;
V_80 = F_47 ( V_33 -> V_39 + 2 ) ;
if ( V_80 != V_33 -> V_65 ) {
if ( 0 == V_80 )
V_33 -> V_65 = V_80 ;
return V_93 ;
}
}
F_43 ( V_80 , V_8 ) ;
}
}
return V_93 ;
}
static int F_48 ( struct V_32 * V_33 )
{
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
const struct V_97 * V_98 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_99 ; V_90 ++ ) {
V_98 = & V_100 [ V_90 ] ;
if ( V_98 -> V_72 == 0 ) {
F_49 ( 2 , V_101 , L_5 ) ;
if ( V_98 -> V_102 & V_95 -> V_102 ) {
memcpy ( V_41 , V_98 , sizeof( * V_98 ) ) ;
break;
}
} else {
F_49 ( 2 , V_101 , L_6 ) ;
if ( V_98 -> V_103 == V_95 -> V_103 ) {
memcpy ( V_41 , V_98 , sizeof( * V_98 ) ) ;
break;
}
}
}
if ( V_90 == V_99 ) {
F_49 ( 1 , V_101 , L_7 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
if ( ! V_95 -> V_102 && ! V_95 -> V_103 && ! V_95 -> V_104 . V_105 )
return - V_25 ;
if ( V_95 -> V_102 || V_95 -> V_103 ) {
if ( F_48 ( V_33 ) )
return - V_25 ;
}
V_8 -> V_15 . V_15 . V_16 . V_106 = V_41 -> V_106 ;
V_8 -> V_15 . V_15 . V_16 . V_105 = V_41 -> V_105 ;
F_49 ( 1 , V_101 , L_8 ,
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
static void F_51 ( struct V_32 * V_33 )
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
static int F_52 ( struct V_32 * V_33 ,
struct V_121 * V_122 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
enum V_89 V_68 = V_122 -> V_68 ;
T_2 V_17 , V_107 , V_108 ;
if ( V_122 -> V_118 != V_119 )
goto V_123;
if ( ! ( F_53 ( V_68 ) ) )
goto V_123;
if ( V_122 -> V_111 <= 0 )
goto V_124;
V_17 = V_122 -> V_17 ;
if ( F_50 ( V_33 ) )
return - V_25 ;
V_107 = V_122 -> V_111 ;
V_108 = V_17 / ( V_107 * 2 ) ;
if ( ( V_107 < V_33 -> V_40 . V_41 . V_106 ) ||
( V_108 < V_33 -> V_40 . V_41 . V_105 ) )
goto V_124;
if ( ! F_8 ( V_107 ) ) {
F_9 ( L_9 ) ;
return - V_25 ;
}
V_122 -> V_106 = V_8 -> V_15 . V_15 . V_16 . V_106 ;
V_122 -> V_105 = V_8 -> V_15 . V_15 . V_16 . V_105 ;
return 0 ;
V_123:
F_9 ( L_10 ) ;
return - V_25 ;
V_124:
F_9 ( L_11 ) ;
return - V_25 ;
}
static void F_30 ( struct V_32 * V_33 , int V_125 )
{
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_76 == V_33 -> V_39 ) {
V_8 -> V_73 = V_126 ;
} else {
if ( 2 == V_125 )
V_8 -> V_73 = V_127 ;
else
V_8 -> V_73 = V_128 ;
}
}
static int F_54 ( struct V_129 * V_130 , struct V_131 * V_132 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & ( V_33 -> V_8 [ V_11 ] ) ;
F_49 ( 2 , V_101 , L_12 ) ;
return F_55 ( & V_8 -> V_134 , V_132 ) ;
}
static unsigned int F_56 ( struct V_129 * V_130 , T_3 * V_135 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_8 -> V_66 )
return F_57 ( & V_8 -> V_134 , V_130 , V_135 ) ;
return 0 ;
}
static int F_58 ( struct V_129 * V_130 )
{
struct V_136 * V_137 = F_59 ( V_130 ) ;
struct V_32 * V_33 = NULL ;
struct V_3 * V_4 = NULL ;
V_33 = F_60 ( V_137 ) ;
V_4 = F_61 ( sizeof( struct V_3 ) , V_138 ) ;
if ( V_4 == NULL ) {
F_9 ( L_13 ) ;
return - V_139 ;
}
V_130 -> V_133 = V_4 ;
V_4 -> V_10 = V_33 ;
V_4 -> V_140 = 0 ;
if ( ! V_33 -> V_140 ) {
V_4 -> V_140 = 1 ;
V_33 -> V_140 = 1 ;
memset ( & V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
}
F_62 ( & V_33 -> V_141 ) ;
V_4 -> V_142 [ V_11 ] = 0 ;
V_4 -> V_143 = V_144 ;
F_63 ( & V_33 -> V_143 , & V_4 -> V_143 ) ;
return 0 ;
}
static int F_64 ( struct V_129 * V_130 )
{
struct V_3 * V_4 = V_130 -> V_133 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_4 -> V_142 [ V_11 ] ) {
V_8 -> V_145 = 0 ;
if ( V_74 == V_33 -> V_39 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_76 == V_33 -> V_39 ) ||
( 2 == V_8 -> V_66 ) ) {
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
V_8 -> V_66 = 0 ;
F_65 ( & V_8 -> V_134 ) ;
F_66 ( V_8 -> V_45 ) ;
V_8 -> V_116 =
V_37 . V_116 [ V_33 -> V_39 ] ;
}
F_67 ( & V_33 -> V_141 ) ;
if ( V_4 -> V_140 )
V_33 -> V_140 = 0 ;
F_68 ( & V_33 -> V_143 , V_4 -> V_143 ) ;
V_130 -> V_133 = NULL ;
V_4 -> V_140 = 0 ;
F_69 ( V_4 ) ;
return 0 ;
}
static int F_70 ( struct V_129 * V_129 , void * V_146 ,
struct V_147 * V_148 )
{
struct V_54 * V_98 = V_56 -> V_57 ;
V_148 -> V_149 = V_150 | V_151 ;
F_71 ( V_148 -> V_152 , L_14 , sizeof( V_148 -> V_152 ) ) ;
F_71 ( V_148 -> V_153 , L_15 , sizeof( V_148 -> V_153 ) ) ;
F_71 ( V_148 -> V_154 , V_98 -> V_155 , sizeof( V_148 -> V_154 ) ) ;
return 0 ;
}
static int F_72 ( struct V_129 * V_129 , void * V_146 ,
struct V_156 * V_15 )
{
if ( V_15 -> V_157 != 0 ) {
F_9 ( L_16 ) ;
return - V_25 ;
}
V_15 -> type = V_120 ;
strcpy ( V_15 -> V_158 , L_17 ) ;
V_15 -> V_118 = V_119 ;
return 0 ;
}
static int F_73 ( struct V_129 * V_129 , void * V_146 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_8 -> V_15 . type != V_15 -> type )
return - V_25 ;
if ( F_50 ( V_33 ) )
return - V_25 ;
* V_15 = V_8 -> V_15 ;
return 0 ;
}
static int F_74 ( struct V_129 * V_129 , void * V_146 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_146 ;
struct V_121 * V_122 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
int V_60 = 0 ;
if ( ( V_74 == V_33 -> V_39 )
|| ( V_76 == V_33 -> V_39 ) ) {
if ( ! V_4 -> V_140 ) {
F_49 ( 1 , V_101 , L_18 ) ;
return - V_159 ;
}
V_60 = F_75 ( & V_33 -> V_143 , V_4 -> V_143 ) ;
if ( 0 != V_60 )
return V_60 ;
V_4 -> V_140 = 1 ;
}
if ( V_8 -> V_66 ) {
F_49 ( 1 , V_101 , L_19 ) ;
return - V_159 ;
}
V_122 = & V_15 -> V_15 . V_16 ;
V_60 = F_52 ( V_33 , V_122 ) ;
if ( V_60 )
return V_60 ;
V_8 -> V_15 . V_15 . V_16 = * V_122 ;
V_8 -> V_15 = * V_15 ;
return 0 ;
}
static int F_76 ( struct V_129 * V_129 , void * V_146 ,
struct V_27 * V_15 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_121 * V_122 = & V_15 -> V_15 . V_16 ;
int V_60 = 0 ;
V_60 = F_52 ( V_33 , V_122 ) ;
if ( V_60 ) {
* V_122 = V_8 -> V_15 . V_15 . V_16 ;
V_122 -> V_17 = V_122 -> V_106 * V_122 -> V_105 * 2 ;
}
return V_60 ;
}
static int F_77 ( struct V_129 * V_129 , void * V_146 ,
struct V_160 * V_161 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 ;
enum V_89 V_68 ;
struct V_5 * V_6 ;
T_4 V_157 = 0 ;
if ( ( V_74 == V_33 -> V_39 )
|| ( V_76 == V_33 -> V_39 ) ) {
if ( ! V_4 -> V_140 ) {
F_9 ( L_18 ) ;
return - V_159 ;
}
}
if ( V_120 != V_161 -> type )
return - V_25 ;
V_157 = V_11 ;
V_8 = & V_33 -> V_8 [ V_157 ] ;
if ( V_8 -> V_15 . type != V_161 -> type || ! V_56 )
return - V_25 ;
if ( 0 != V_8 -> V_145 )
return - V_159 ;
if ( V_161 -> type == V_120 ) {
if ( V_8 -> V_15 . V_15 . V_16 . V_68 == V_70 )
V_68 = V_110 ;
else
V_68 = V_8 -> V_15 . V_15 . V_16 . V_68 ;
} else {
V_68 = V_162 ;
}
V_8 -> V_45 = F_78 ( V_56 ) ;
if ( ! V_8 -> V_45 ) {
F_9 ( L_20 ) ;
return - V_25 ;
}
V_6 = & V_8 -> V_134 ;
V_6 -> type = V_120 ;
V_6 -> V_163 = V_164 | V_165 ;
V_6 -> V_166 = V_4 ;
V_6 -> V_167 = & V_168 ;
V_6 -> V_169 = & V_170 ;
V_6 -> V_171 = sizeof( struct V_46 ) ;
F_79 ( V_6 ) ;
V_4 -> V_142 [ V_157 ] = 1 ;
V_8 -> V_145 = 1 ;
V_8 -> V_36 = V_161 -> V_36 ;
F_23 ( & V_8 -> V_49 ) ;
return F_80 ( & V_8 -> V_134 , V_161 ) ;
}
static int F_81 ( struct V_129 * V_129 , void * V_146 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_8 -> V_15 . type != V_173 -> type )
return - V_25 ;
return F_82 ( & V_8 -> V_134 , V_173 ) ;
}
static int F_83 ( struct V_129 * V_129 , void * V_146 , struct V_172 * V_47 )
{
struct V_3 * V_4 = NULL ;
struct V_32 * V_33 = NULL ;
struct V_7 * V_8 = NULL ;
if ( ! V_47 || ! V_146 )
return - V_25 ;
V_4 = V_146 ;
V_33 = V_4 -> V_10 ;
if ( ! V_33 )
return - V_25 ;
V_8 = & ( V_33 -> V_8 [ V_11 ] ) ;
if ( V_8 -> V_15 . type != V_47 -> type )
return - V_25 ;
if ( ! V_4 -> V_142 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_174 ;
}
return F_84 ( & V_8 -> V_134 , V_47 ) ;
}
static int F_85 ( struct V_129 * V_129 , void * V_146 , T_5 * V_175 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
int V_60 = 0 ;
if ( ! ( * V_175 & V_176 ) )
return - V_25 ;
if ( V_8 -> V_66 ) {
F_9 ( L_22 ) ;
return - V_159 ;
}
V_33 -> V_96 . V_102 = * V_175 ;
V_33 -> V_96 . V_103 = V_177 ;
memset ( & V_33 -> V_96 . V_104 , 0 , sizeof( V_33 -> V_96 . V_104 ) ) ;
if ( F_50 ( V_33 ) )
return - V_25 ;
if ( ( V_33 -> V_40 . V_41 . V_106 *
V_33 -> V_40 . V_41 . V_105 * 2 ) >
V_37 . V_38 [ V_33 -> V_39 ] ) {
F_9 ( L_23 ) ;
return - V_25 ;
}
V_8 -> V_15 . V_15 . V_16 . V_111 = V_8 -> V_15 . V_15 . V_16 . V_106 ;
F_51 ( V_33 ) ;
V_60 = F_86 ( & V_88 . V_178 , 1 , V_96 ,
V_179 , * V_175 ) ;
if ( V_60 < 0 ) {
F_9 ( L_24 ) ;
return V_60 ;
}
V_60 = F_86 ( & V_88 . V_178 , 1 , V_180 ,
V_181 , * V_175 ) ;
if ( V_60 < 0 )
F_9 ( L_25 ) ;
return V_60 ;
}
static int F_87 ( struct V_129 * V_129 , void * V_146 , T_5 * V_182 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
* V_182 = V_33 -> V_96 . V_102 ;
return 0 ;
}
static int F_88 ( struct V_129 * V_129 , void * V_146 , struct V_172 * V_183 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
return F_89 ( & V_8 -> V_134 , V_183 ,
( V_129 -> V_184 & V_185 ) ) ;
}
static int F_90 ( struct V_129 * V_129 , void * V_146 ,
enum V_186 V_187 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_32 * V_188 = V_88 . V_87 [ ! V_33 -> V_39 ] ;
int V_60 = 0 ;
if ( V_187 != V_120 ) {
F_9 ( L_26 ) ;
return - V_25 ;
}
if ( ! V_4 -> V_142 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_174 ;
}
if ( V_8 -> V_66 ) {
F_9 ( L_27 ) ;
return - V_159 ;
}
if ( ( V_33 -> V_39 == V_74
&& V_188 -> V_8 [ V_11 ] . V_66 &&
V_33 -> V_40 . V_41 . V_42 == 0 )
|| ( ( V_33 -> V_39 == V_76 )
&& ( 2 == V_188 -> V_8 [ V_11 ] . V_66 ) ) ) {
F_9 ( L_28 ) ;
return - V_159 ;
}
V_60 = F_52 ( V_33 , & V_8 -> V_15 . V_15 . V_16 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_91 ( & V_8 -> V_134 , V_187 ) ;
if ( V_60 < 0 ) {
F_9 ( L_29 ) ;
return V_60 ;
}
return V_60 ;
}
static int F_92 ( struct V_129 * V_129 , void * V_146 ,
enum V_186 V_187 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_54 * V_55 =
V_56 -> V_57 ;
if ( V_187 != V_120 ) {
F_9 ( L_26 ) ;
return - V_25 ;
}
if ( ! V_4 -> V_142 [ V_11 ] ) {
F_9 ( L_21 ) ;
return - V_174 ;
}
if ( ! V_8 -> V_66 ) {
F_9 ( L_27 ) ;
return - V_25 ;
}
if ( V_187 == V_120 ) {
if ( V_74 == V_33 -> V_39 ) {
if ( V_55 -> V_75 )
F_34 ( 0 ) ;
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( ( V_76 == V_33 -> V_39 ) ||
( 2 == V_8 -> V_66 ) ) {
if ( V_55 -> V_77 )
F_38 ( 0 ) ;
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
}
V_8 -> V_66 = 0 ;
return F_93 ( & V_8 -> V_134 , V_187 ) ;
}
static int F_94 ( struct V_129 * V_129 , void * V_146 ,
struct V_189 * V_190 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
if ( V_120 != V_190 -> type )
return - V_25 ;
V_190 -> V_191 . V_192 = V_190 -> V_191 . V_193 = 0 ;
V_190 -> V_194 . V_192 = V_190 -> V_194 . V_193 = 0 ;
V_190 -> V_194 . V_105 = V_190 -> V_191 . V_105 = V_8 -> V_105 ;
V_190 -> V_194 . V_106 = V_190 -> V_191 . V_106 = V_8 -> V_106 ;
return 0 ;
}
static int F_95 ( struct V_129 * V_129 , void * V_4 ,
struct V_195 * V_196 )
{
struct V_54 * V_98 = V_56 -> V_57 ;
if ( V_196 -> V_157 >= V_98 -> V_197 ) {
F_49 ( 1 , V_101 , L_30 ) ;
return - V_25 ;
}
strcpy ( V_196 -> V_198 , V_98 -> V_196 [ V_196 -> V_157 ] ) ;
V_196 -> type = V_199 ;
V_196 -> V_182 = V_176 ;
return 0 ;
}
static int F_96 ( struct V_129 * V_129 , void * V_146 , unsigned int V_90 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
int V_60 = 0 ;
if ( V_8 -> V_66 ) {
F_9 ( L_19 ) ;
return - V_159 ;
}
V_60 = F_86 ( & V_88 . V_178 , 1 , V_96 ,
V_200 , 0 , V_90 , 0 ) ;
if ( V_60 < 0 )
F_9 ( L_24 ) ;
V_95 -> V_201 = V_90 ;
return V_60 ;
}
static int F_97 ( struct V_129 * V_129 , void * V_146 , unsigned int * V_90 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
* V_90 = V_95 -> V_201 ;
return 0 ;
}
static int F_98 ( struct V_129 * V_129 , void * V_146 , enum V_202 * V_183 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
* V_183 = F_99 ( & V_33 -> V_143 ) ;
return 0 ;
}
static int F_100 ( struct V_129 * V_129 , void * V_146 , enum V_202 V_183 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
return F_101 ( & V_33 -> V_143 , & V_4 -> V_143 , V_183 ) ;
}
static int F_102 ( struct V_129 * V_129 , void * V_146 ,
struct V_203 * V_204 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
return F_103 ( V_88 . V_205 [ V_95 -> V_201 ] ,
V_96 , V_206 , V_204 ) ;
}
static int F_104 ( struct V_129 * V_129 , void * V_146 ,
struct V_207 * V_204 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_7 * V_8 = & V_33 -> V_8 [ V_11 ] ;
struct V_94 * V_95 = & V_33 -> V_96 ;
int V_60 = 0 ;
if ( V_8 -> V_66 ) {
F_49 ( 1 , V_101 , L_22 ) ;
return - V_159 ;
}
V_60 = F_75 ( & V_33 -> V_143 , V_4 -> V_143 ) ;
if ( V_60 != 0 )
return V_60 ;
V_4 -> V_140 = 1 ;
if ( F_105 ( & V_8 -> V_52 ) )
return - V_208 ;
V_33 -> V_96 . V_103 = V_204 -> V_204 ;
V_33 -> V_96 . V_102 = V_209 ;
memset ( & V_33 -> V_96 . V_104 , 0 , sizeof( V_33 -> V_96 . V_104 ) ) ;
if ( F_50 ( V_33 ) ) {
V_60 = - V_25 ;
} else {
F_51 ( V_33 ) ;
V_60 = F_103 ( V_88 . V_205 [ V_95 -> V_201 ] ,
V_96 , V_210 , V_204 ) ;
}
F_19 ( & V_8 -> V_52 ) ;
return V_60 ;
}
static int F_106 ( struct V_129 * V_129 , void * V_146 ,
struct V_207 * V_204 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
V_204 -> V_204 = V_33 -> V_96 . V_103 ;
return 0 ;
}
static int F_107 ( struct V_129 * V_129 , void * V_146 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_58 * V_40 = & V_33 -> V_40 ;
struct V_97 * V_41 = & V_40 -> V_41 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_213 * V_214 = & V_95 -> V_104 ;
int V_60 ;
if ( V_212 -> type != V_215 ) {
F_49 ( 2 , V_101 , L_31 ) ;
return - V_25 ;
}
V_60 = F_103 ( V_88 . V_205 [ V_95 -> V_201 ] ,
V_96 , V_216 , V_212 ) ;
if ( V_60 == - V_217 ) {
F_49 ( 2 , V_101 , L_32
L_33 ) ;
return - V_25 ;
}
if ( V_60 < 0 ) {
F_49 ( 2 , V_101 , L_34 ) ;
return V_60 ;
}
if ( ! ( V_212 -> V_214 . V_106 && V_212 -> V_214 . V_105 &&
( V_212 -> V_214 . V_218 ||
V_212 -> V_214 . V_219 ||
V_212 -> V_214 . V_220 ) &&
V_212 -> V_214 . V_221 &&
( V_212 -> V_214 . V_222 ||
V_212 -> V_214 . V_223 ) ) ) {
F_49 ( 2 , V_101 , L_35
L_36
L_37
L_38
L_39 ) ;
return - V_25 ;
}
* V_214 = V_212 -> V_214 ;
V_41 -> V_224 = V_214 -> V_218 + V_214 -> V_219 +
V_214 -> V_220 - 8 ;
V_41 -> V_225 = V_214 -> V_106 ;
V_41 -> V_226 = 1 ;
V_41 -> V_227 = V_214 -> V_223 + V_214 -> V_222 + 1 ;
if ( V_214 -> V_228 ) {
if ( V_214 -> V_229 || V_214 -> V_230 || V_214 -> V_231 ) {
V_41 -> V_232 = V_214 -> V_105 * 2 +
V_214 -> V_221 + V_214 -> V_223 + V_214 -> V_222 +
V_214 -> V_230 + V_214 -> V_231 +
V_214 -> V_229 ;
V_41 -> V_233 = V_41 -> V_232 / 2 -
( V_214 -> V_221 - 1 ) ;
V_41 -> V_234 = V_41 -> V_232 / 2 + 1 ;
V_41 -> V_235 = V_41 -> V_234 + V_214 -> V_231 +
V_214 -> V_229 + 1 ;
V_41 -> V_236 = V_41 -> V_232 -
( V_214 -> V_230 - 1 ) ;
} else {
F_49 ( 2 , V_101 , L_40
L_41 ) ;
return - V_25 ;
}
} else {
V_41 -> V_232 = V_214 -> V_105 + V_214 -> V_221 +
V_214 -> V_223 + V_214 -> V_222 ;
V_41 -> V_233 = V_41 -> V_232 - ( V_214 -> V_221 - 1 ) ;
}
strncpy ( V_41 -> V_198 , L_42 ,
V_237 ) ;
V_41 -> V_106 = V_214 -> V_106 ;
V_41 -> V_105 = V_214 -> V_105 ;
V_41 -> V_67 = V_214 -> V_228 ? 0 : 1 ;
V_41 -> V_42 = 0 ;
V_41 -> V_238 = 0 ;
V_41 -> V_239 = 0 ;
V_41 -> V_72 = 1 ;
V_41 -> V_102 = 0 ;
V_41 -> V_103 = V_177 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = V_177 ;
return 0 ;
}
static int F_108 ( struct V_129 * V_129 , void * V_146 ,
struct V_211 * V_212 )
{
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
struct V_213 * V_214 = & V_95 -> V_104 ;
V_212 -> V_214 = * V_214 ;
return 0 ;
}
static int F_109 ( struct V_129 * V_129 , void * V_146 ,
struct V_240 * V_241 )
{
V_241 -> V_242 = V_243 ;
V_241 -> V_244 = 0 ;
if ( V_241 -> V_245 . type != V_246 &&
V_241 -> V_245 . type != V_247 ) {
F_49 ( 2 , V_101 , L_43 ) ;
return - V_25 ;
}
return F_86 ( & V_88 . V_178 , 0 , V_180 ,
V_248 , V_241 ) ;
}
static int F_110 ( struct V_129 * V_129 , void * V_146 ,
struct V_249 * V_250 ) {
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
return F_103 ( V_88 . V_205 [ V_95 -> V_201 ] , V_180 ,
V_251 , V_250 ) ;
}
static int F_111 ( struct V_129 * V_129 , void * V_146 ,
struct V_249 * V_250 ) {
struct V_3 * V_4 = V_146 ;
struct V_32 * V_33 = V_4 -> V_10 ;
struct V_94 * V_95 = & V_33 -> V_96 ;
return F_103 ( V_88 . V_205 [ V_95 -> V_201 ] , V_180 ,
V_252 , V_250 ) ;
}
static int F_112 ( struct V_129 * V_130 , void * V_146 )
{
F_113 ( & V_88 . V_178 , 0 , V_180 , V_253 ) ;
return 0 ;
}
static int F_114 ( void )
{
int V_254 ;
int V_255 ;
int V_256 ;
int V_257 = 0 , V_90 , V_258 ;
if ( ( V_259 > 0 ) &&
( V_259 < V_37 . V_44 ) )
V_259 = V_37 . V_44 ;
if ( ( V_260 > 0 ) &&
( V_260 < V_37 . V_44 ) )
V_260 = V_37 . V_44 ;
if ( V_261 < V_37 . V_262 [ V_74 ] )
V_261 =
V_37 . V_262 [ V_74 ] ;
if ( V_263 < V_37 . V_262 [ V_76 ] )
V_263 =
V_37 . V_262 [ V_76 ] ;
V_37 . V_116 [ V_74 ] = V_259 ;
if ( V_259 ) {
V_37 . V_38 [ V_74 ] =
V_261 ;
}
V_37 . V_116 [ V_76 ] = V_260 ;
if ( V_260 ) {
V_37 . V_38 [ V_76 ] =
V_263 ;
}
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ ) {
V_88 . V_87 [ V_90 ] =
F_61 ( sizeof( struct V_32 ) , V_138 ) ;
if ( ! V_88 . V_87 [ V_90 ] ) {
V_254 = V_90 ;
V_257 = - V_139 ;
goto V_265;
}
}
V_254 = V_264 ;
V_255 = V_266 ;
V_256 = V_37 . V_116 [ V_90 - 1 ] ;
return 0 ;
V_265:
for ( V_258 = 0 ; V_258 < V_254 ; V_258 ++ )
F_69 ( V_88 . V_87 [ V_258 ] ) ;
return V_257 ;
}
static T_6 int F_115 ( struct V_267 * V_268 )
{
struct V_269 * V_270 ;
struct V_54 * V_98 ;
int V_90 , V_258 = 0 , V_271 , V_6 , V_272 , V_257 = 0 ;
struct V_273 * V_274 ;
struct V_7 * V_8 ;
struct V_32 * V_33 ;
struct V_136 * V_275 ;
struct V_276 * V_277 ;
int V_278 ;
T_7 V_34 ;
V_56 = & V_268 -> V_87 ;
V_257 = F_114 () ;
if ( V_257 ) {
F_116 ( V_56 -> V_152 , L_44 ) ;
return V_257 ;
}
V_257 = F_117 ( V_56 , & V_88 . V_178 ) ;
if ( V_257 ) {
F_116 ( V_56 -> V_152 , L_45 ) ;
return V_257 ;
}
V_271 = 0 ;
while ( ( V_277 = F_118 ( V_268 , V_279 , V_271 ) ) ) {
for ( V_90 = V_277 -> V_280 ; V_90 <= V_277 -> V_281 ; V_90 ++ ) {
if ( F_119 ( V_90 , F_45 , V_282 ,
L_46 ,
( void * ) ( & V_88 . V_87 [ V_271 ] -> V_39 ) ) ) {
V_257 = - V_159 ;
goto V_283;
}
}
V_271 ++ ;
}
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_275 = F_120 () ;
if ( V_275 == NULL ) {
for ( V_258 = 0 ; V_258 < V_90 ; V_258 ++ ) {
V_33 = V_88 . V_87 [ V_258 ] ;
F_121 ( V_33 -> V_284 ) ;
}
V_257 = - V_139 ;
goto V_283;
}
* V_275 = V_285 ;
V_275 -> V_178 = & V_88 . V_178 ;
V_275 -> V_286 = F_121 ;
snprintf ( V_275 -> V_198 , sizeof( V_275 -> V_198 ) ,
L_47 ,
V_287 ) ;
V_33 -> V_284 = V_275 ;
}
V_277 = F_118 ( V_268 , V_288 , 0 ) ;
if ( V_277 ) {
V_34 = F_122 ( V_277 ) ;
for ( V_258 = 0 ; V_258 < V_264 ; V_258 ++ ) {
V_33 = V_88 . V_87 [ V_258 ] ;
V_33 -> V_39 = V_258 ;
V_37 . V_43 [ V_33 -> V_39 ] = 0 ;
if ( V_34 )
V_37 . V_43 [ V_33 -> V_39 ] =
V_34 / 2 ;
}
}
for ( V_258 = 0 ; V_258 < V_264 ; V_258 ++ ) {
V_33 = V_88 . V_87 [ V_258 ] ;
F_123 ( & V_33 -> V_141 , 0 ) ;
for ( V_271 = 0 ; V_271 < V_92 ; V_271 ++ ) {
V_33 -> V_8 [ V_271 ] . V_116 = 0 ;
V_8 = & V_33 -> V_8 [ V_271 ] ;
V_8 -> V_145 = 0 ;
V_8 -> V_66 = 0 ;
F_124 ( & V_8 -> V_51 ) ;
F_125 ( & V_8 -> V_52 ) ;
V_8 -> V_116 = 0 ;
V_8 -> V_73 = NULL ;
V_8 -> V_21 = V_8 -> V_22 = 0 ;
V_8 -> V_23 = V_8 -> V_24 = 0 ;
V_8 -> V_63 = V_8 -> V_62 = NULL ;
memset ( & V_8 -> V_15 , 0 , sizeof( V_8 -> V_15 ) ) ;
V_8 -> V_116 = V_37 . V_116 [ V_271 ] ;
}
V_33 -> V_140 = 0 ;
V_33 -> V_39 = V_258 ;
if ( V_258 < 2 )
V_33 -> V_8 [ V_11 ] . V_116 =
V_37 . V_116 [ V_33 -> V_39 ] ;
else
V_33 -> V_8 [ V_11 ] . V_116 = 0 ;
memset ( & V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
F_126 ( & V_33 -> V_143 ) ;
V_33 -> V_8 [ V_11 ] . V_15 . type =
V_120 ;
F_127 ( V_289 , & V_33 -> V_284 -> V_50 ) ;
V_33 -> V_284 -> V_52 = & V_8 -> V_52 ;
F_49 ( 1 , V_101 , L_48 ,
( int ) V_33 , ( int ) & V_33 -> V_284 ) ;
V_257 = F_128 ( V_33 -> V_284 ,
V_290 , ( V_258 ? 3 : 2 ) ) ;
if ( V_257 < 0 )
goto V_291;
F_129 ( V_33 -> V_284 , V_33 ) ;
}
V_274 = F_130 ( 1 ) ;
V_98 = V_268 -> V_87 . V_57 ;
V_278 = V_98 -> V_278 ;
V_270 = V_98 -> V_292 ;
V_88 . V_205 = F_61 ( sizeof( struct V_293 * ) * V_278 ,
V_138 ) ;
if ( V_88 . V_205 == NULL ) {
F_9 ( L_49 ) ;
V_257 = - V_139 ;
goto V_291;
}
for ( V_90 = 0 ; V_90 < V_278 ; V_90 ++ ) {
V_88 . V_205 [ V_90 ] = F_131 ( & V_88 . V_178 ,
V_274 ,
& V_270 [ V_90 ] . V_294 ,
NULL ) ;
if ( ! V_88 . V_205 [ V_90 ] ) {
F_9 ( L_50 ) ;
goto V_295;
}
if ( V_88 . V_205 [ V_90 ] )
V_88 . V_205 [ V_90 ] -> V_296 = 1 << V_90 ;
}
F_132 ( & V_88 . V_178 ,
L_51 ) ;
return 0 ;
V_295:
F_69 ( V_88 . V_205 ) ;
V_291:
for ( V_271 = 0 ; V_271 < V_258 ; V_271 ++ ) {
V_33 = V_88 . V_87 [ V_271 ] ;
F_133 ( V_33 -> V_284 ) ;
F_121 ( V_33 -> V_284 ) ;
V_33 -> V_284 = NULL ;
}
V_283:
F_134 ( & V_88 . V_178 ) ;
F_9 ( L_52 ) ;
for ( V_6 = V_271 ; V_271 >= 0 ; V_271 -- ) {
for ( V_272 = V_90 ; V_272 >= V_277 -> V_280 ; V_272 -- )
F_135 ( V_272 , ( void * ) ( & V_88 . V_87 [ V_271 ] -> V_39 ) ) ;
V_277 = F_118 ( V_268 , V_279 , V_271 - 1 ) ;
V_272 = V_277 -> V_281 ;
}
return V_257 ;
}
static int F_136 ( struct V_267 * V_297 )
{
struct V_32 * V_33 ;
int V_90 ;
F_134 ( & V_88 . V_178 ) ;
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
F_133 ( V_33 -> V_284 ) ;
V_33 -> V_284 = NULL ;
}
return 0 ;
}
static int F_137 ( struct V_297 * V_87 )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
if ( F_138 ( & V_33 -> V_141 ) && V_8 -> V_145 ) {
if ( V_33 -> V_39 == V_74 ) {
F_33 ( 0 ) ;
F_32 ( 0 ) ;
}
if ( V_33 -> V_39 == V_76 ||
V_8 -> V_66 == 2 ) {
F_37 ( 0 ) ;
F_36 ( 0 ) ;
}
}
F_19 ( & V_8 -> V_52 ) ;
}
return 0 ;
}
static int F_139 ( struct V_297 * V_87 )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ ) {
V_33 = V_88 . V_87 [ V_90 ] ;
V_8 = & V_33 -> V_8 [ V_11 ] ;
F_21 ( & V_8 -> V_52 ) ;
if ( F_138 ( & V_33 -> V_141 ) && V_8 -> V_145 ) {
if ( V_33 -> V_39 == V_74 ) {
F_33 ( 1 ) ;
F_32 ( 1 ) ;
}
if ( V_33 -> V_39 == V_76 ||
V_8 -> V_66 == 2 ) {
F_37 ( 1 ) ;
F_36 ( 1 ) ;
}
}
F_19 ( & V_8 -> V_52 ) ;
}
return 0 ;
}
static T_6 int F_140 ( void )
{
return F_141 ( & V_298 ) ;
}
static void F_142 ( void )
{
struct V_267 * V_268 ;
struct V_276 * V_277 ;
int V_299 ;
int V_90 = 0 ;
V_268 = F_12 ( V_56 , struct V_267 , V_87 ) ;
while ( ( V_277 = F_118 ( V_268 , V_279 , V_90 ) ) ) {
for ( V_299 = V_277 -> V_280 ; V_299 <= V_277 -> V_281 ; V_299 ++ )
F_135 ( V_299 ,
( void * ) ( & V_88 . V_87 [ V_90 ] -> V_39 ) ) ;
V_90 ++ ;
}
F_143 ( & V_298 ) ;
F_69 ( V_88 . V_205 ) ;
for ( V_90 = 0 ; V_90 < V_264 ; V_90 ++ )
F_69 ( V_88 . V_87 [ V_90 ] ) ;
}
