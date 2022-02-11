static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_6 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_10 * V_11 ;
unsigned long V_12 ;
F_6 ( 2 , V_13 , L_1 ) ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_7 ( V_3 , 0 , V_11 -> V_15 . V_15 . V_16 . V_17 ) ;
if ( F_8 ( V_3 , 0 ) > F_9 ( V_3 , 0 ) )
return - V_18 ;
V_5 -> V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_12 = F_10 ( V_3 , 0 ) ;
if ( ! F_11 ( ( V_12 + V_11 -> V_20 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_21 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_22 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_23 ) , 8 ) ) {
F_6 ( 1 , V_13 , L_2 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_24 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int V_27 [] , struct V_28 * V_29 [] )
{
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
unsigned V_30 = V_11 -> V_15 . V_15 . V_16 . V_17 ;
F_6 ( 2 , V_13 , L_3 ) ;
if ( * V_26 ) {
if ( V_27 [ 0 ] < V_30 )
return - V_18 ;
V_30 = V_27 [ 0 ] ;
}
if ( V_24 -> V_31 + * V_25 < 3 )
* V_25 = 3 - V_24 -> V_31 ;
* V_26 = 1 ;
V_27 [ 0 ] = V_30 ;
F_13 ( V_9 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( V_3 -> V_6 ) ;
struct V_1 * V_32 = F_1 ( V_5 ) ;
struct V_10 * V_11 ;
unsigned long V_33 ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_6 ( 2 , V_13 , L_4 ) ;
F_15 ( & V_11 -> V_34 , V_33 ) ;
F_16 ( & V_32 -> V_35 , & V_11 -> V_36 ) ;
F_17 ( & V_11 -> V_34 , V_33 ) ;
}
static int F_18 ( struct V_6 * V_24 , unsigned int V_37 )
{
struct V_38 * V_39 =
V_40 -> V_41 ;
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_42 * V_43 = & V_9 -> V_44 ;
struct V_1 * V_32 , * V_45 ;
unsigned long V_12 , V_33 ;
int V_46 ;
F_15 ( & V_11 -> V_34 , V_33 ) ;
V_9 -> V_47 = 0 ;
if ( V_39 -> V_48 ) {
V_46 = V_39 ->
V_48 ( V_43 -> V_49 . V_50 ) ;
if ( V_46 < 0 ) {
F_6 ( 1 , V_13 , L_5 ) ;
goto V_51;
}
}
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_54 , 1 ) ;
if ( V_46 && V_46 != - V_55 && V_46 != - V_56 ) {
F_6 ( 1 , V_13 , L_6 ) ;
goto V_51;
}
V_46 = F_20 ( V_43 , V_9 -> V_57 ) ;
if ( V_46 < 0 ) {
F_6 ( 1 , V_13 , L_7 ) ;
goto V_51;
}
V_50 = V_46 ;
F_21 ( V_9 , V_46 ) ;
V_11 -> V_58 = V_11 -> V_59 = F_22 ( V_11 -> V_36 . V_60 ,
struct V_1 , V_35 ) ;
F_23 ( & V_11 -> V_58 -> V_35 ) ;
F_17 ( & V_11 -> V_34 , V_33 ) ;
V_12 = F_10 ( & V_11 -> V_58 -> V_3 . V_61 , 0 ) ;
V_11 -> V_62 ( V_12 + V_11 -> V_20 ,
V_12 + V_11 -> V_21 ,
V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ) ;
V_63 [ V_14 ] [ V_9 -> V_57 ] = 1 ;
if ( V_64 == V_9 -> V_57 ) {
F_24 () ;
F_25 ( 1 ) ;
F_26 ( 1 ) ;
}
if ( V_65 == V_9 -> V_57 ||
V_50 == 2 ) {
F_27 () ;
F_28 ( 1 ) ;
F_29 ( 1 ) ;
}
return 0 ;
V_51:
F_30 (buf, tmp, &common->dma_queue, list) {
F_23 ( & V_32 -> V_35 ) ;
F_31 ( & V_32 -> V_3 . V_61 , V_66 ) ;
}
F_17 ( & V_11 -> V_34 , V_33 ) ;
return V_46 ;
}
static void F_32 ( struct V_6 * V_24 )
{
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 ;
unsigned long V_33 ;
int V_46 ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( V_64 == V_9 -> V_57 ) {
F_26 ( 0 ) ;
F_25 ( 0 ) ;
}
if ( V_65 == V_9 -> V_57 ||
V_50 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
V_50 = 0 ;
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_54 , 0 ) ;
if ( V_46 && V_46 != - V_55 && V_46 != - V_56 )
F_6 ( 1 , V_13 , L_8 ) ;
F_15 ( & V_11 -> V_34 , V_33 ) ;
if ( V_11 -> V_58 == V_11 -> V_59 ) {
F_31 ( & V_11 -> V_58 -> V_3 . V_61 ,
V_67 ) ;
} else {
if ( V_11 -> V_58 != NULL )
F_31 ( & V_11 -> V_58 -> V_3 . V_61 ,
V_67 ) ;
if ( V_11 -> V_59 != NULL )
F_31 ( & V_11 -> V_59 -> V_3 . V_61 ,
V_67 ) ;
}
while ( ! F_33 ( & V_11 -> V_36 ) ) {
V_11 -> V_59 = F_22 ( V_11 -> V_36 . V_60 ,
struct V_1 , V_35 ) ;
F_23 ( & V_11 -> V_59 -> V_35 ) ;
F_31 ( & V_11 -> V_59 -> V_3 . V_61 ,
V_67 ) ;
}
F_17 ( & V_11 -> V_34 , V_33 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
V_11 -> V_58 -> V_3 . V_61 . V_68 = F_35 () ;
F_31 ( & V_11 -> V_58 -> V_3 . V_61 , V_69 ) ;
V_11 -> V_58 = V_11 -> V_59 ;
}
static void F_36 ( struct V_10 * V_11 )
{
unsigned long V_12 = 0 ;
F_37 ( & V_11 -> V_34 ) ;
V_11 -> V_59 = F_22 ( V_11 -> V_36 . V_60 ,
struct V_1 , V_35 ) ;
F_23 ( & V_11 -> V_59 -> V_35 ) ;
F_38 ( & V_11 -> V_34 ) ;
V_12 = F_10 ( & V_11 -> V_59 -> V_3 . V_61 , 0 ) ;
V_11 -> V_62 ( V_12 + V_11 -> V_20 ,
V_12 + V_11 -> V_21 ,
V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ) ;
}
static T_1 F_39 ( int V_70 , void * V_71 )
{
struct V_72 * V_73 = & V_74 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_57 = 0 ;
int V_75 = - 1 , V_76 ;
V_57 = * ( int * ) ( V_71 ) ;
if ( ! F_40 ( V_57 ) )
return V_77 ;
V_9 = V_73 -> V_73 [ V_57 ] ;
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
V_11 = & V_9 -> V_11 [ V_76 ] ;
if ( 1 == V_9 -> V_44 . V_49 . V_79 ) {
F_37 ( & V_11 -> V_34 ) ;
if ( F_33 ( & V_11 -> V_36 ) ) {
F_38 ( & V_11 -> V_34 ) ;
continue;
}
F_38 ( & V_11 -> V_34 ) ;
if ( ! V_63 [ V_76 ] [ V_57 ] )
F_34 ( V_11 ) ;
V_63 [ V_76 ] [ V_57 ] = 0 ;
F_36 ( V_11 ) ;
V_63 [ V_76 ] [ V_57 ] = 0 ;
} else {
if ( V_63 [ V_76 ] [ V_57 ] ) {
V_63 [ V_76 ] [ V_57 ] = 0 ;
continue;
}
if ( 0 == V_76 ) {
V_9 -> V_47 ^= 1 ;
V_75 = F_41 ( V_9 -> V_57 ) ;
if ( V_75 != V_9 -> V_47 ) {
if ( 0 == V_75 )
V_9 -> V_47 = V_75 ;
return V_80 ;
}
}
if ( 0 == V_75 ) {
if ( V_11 -> V_58 == V_11 -> V_59 )
continue;
F_34 ( V_11 ) ;
} else if ( 1 == V_75 ) {
F_37 ( & V_11 -> V_34 ) ;
if ( F_33 ( & V_11 -> V_36 ) ||
( V_11 -> V_58 != V_11 -> V_59 ) ) {
F_38 ( & V_11 -> V_34 ) ;
continue;
}
F_38 ( & V_11 -> V_34 ) ;
F_36 ( V_11 ) ;
}
}
}
return V_80 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_42 * V_44 = & V_9 -> V_44 ;
const struct V_81 * V_82 ;
struct V_81 * V_49 = & V_44 -> V_49 ;
struct V_83 * V_84 = & V_9 -> V_53 ;
int V_85 ;
F_6 ( 2 , V_13 , L_9 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ ) {
V_82 = & V_87 [ V_85 ] ;
if ( V_82 -> V_88 == 0 ) {
F_6 ( 2 , V_13 , L_10 ) ;
if ( V_82 -> V_89 & V_84 -> V_89 ) {
memcpy ( V_49 , V_82 , sizeof( * V_82 ) ) ;
break;
}
} else {
F_6 ( 2 , V_13 , L_11 ) ;
if ( ! memcmp ( & V_82 -> V_90 , & V_84 -> V_90 ,
sizeof( V_84 -> V_90 ) ) ) {
memcpy ( V_49 , V_82 , sizeof( * V_82 ) ) ;
break;
}
}
}
if ( V_85 == V_86 )
return - V_18 ;
V_11 -> V_15 . V_15 . V_16 . V_91 = V_49 -> V_91 ;
V_11 -> V_91 = V_49 -> V_91 ;
V_11 -> V_15 . V_15 . V_16 . V_92 = V_49 -> V_92 ;
V_11 -> V_92 = V_49 -> V_92 ;
V_11 -> V_15 . V_15 . V_16 . V_17 = V_11 -> V_92 * V_11 -> V_91 * 2 ;
V_11 -> V_15 . V_15 . V_16 . V_93 = V_49 -> V_91 ;
V_44 -> V_94 . V_95 = V_49 -> V_91 ;
V_44 -> V_94 . V_96 = V_49 -> V_79 ;
if ( V_84 -> V_89 )
V_11 -> V_15 . V_15 . V_16 . V_97 = V_98 ;
else
V_11 -> V_15 . V_15 . V_16 . V_97 = V_99 ;
if ( V_9 -> V_44 . V_49 . V_79 )
V_11 -> V_15 . V_15 . V_16 . V_19 = V_100 ;
else
V_11 -> V_15 . V_15 . V_16 . V_19 = V_101 ;
if ( V_9 -> V_44 . V_102 . V_103 == V_104 )
V_11 -> V_15 . V_15 . V_16 . V_105 = V_106 ;
else
V_11 -> V_15 . V_15 . V_16 . V_105 = V_107 ;
V_11 -> V_15 . type = V_108 ;
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
unsigned int V_95 , V_17 ;
struct V_83 * V_84 = & ( V_9 -> V_53 ) ;
struct V_42 * V_44 = & V_9 -> V_44 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
enum V_109 V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
F_6 ( 2 , V_13 , L_12 ) ;
if ( V_110 == V_19 ) {
if ( V_44 -> V_49 . V_79 )
V_84 -> V_111 = V_100 ;
else
V_84 -> V_111 = V_101 ;
} else
V_84 -> V_111 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_17 = V_11 -> V_15 . V_15 . V_16 . V_17 ;
V_95 = V_11 -> V_15 . V_15 . V_16 . V_93 ;
if ( ( V_100 == V_84 -> V_111 ) ||
( V_101 == V_84 -> V_111 ) ) {
V_11 -> V_20 = 0 ;
V_11 -> V_21 = V_95 ;
V_11 -> V_22 = V_17 / 2 ;
V_11 -> V_23 = V_17 / 2 + V_95 ;
} else if ( V_112 == V_84 -> V_111 ) {
V_11 -> V_20 = 0 ;
V_11 -> V_21 = V_17 / 4 ;
V_11 -> V_22 = V_17 / 2 ;
V_11 -> V_23 = V_11 -> V_22 + V_17 / 4 ;
} else if ( V_113 == V_84 -> V_111 ) {
V_11 -> V_21 = 0 ;
V_11 -> V_20 = V_17 / 4 ;
V_11 -> V_23 = V_17 / 2 ;
V_11 -> V_22 = V_11 -> V_23 + V_17 / 4 ;
}
if ( ( V_100 == V_84 -> V_111 ) ||
( V_101 == V_84 -> V_111 ) )
V_44 -> V_94 . V_96 = 1 ;
else
V_44 -> V_94 . V_96 = 0 ;
if ( 1 == V_44 -> V_49 . V_79 )
V_44 -> V_94 . V_95 =
V_11 -> V_15 . V_15 . V_16 . V_93 ;
else {
if ( ( V_19 == V_110 )
|| ( V_19 == V_101 ) )
V_44 -> V_94 . V_95 =
V_11 -> V_15 . V_15 . V_16 . V_93 * 2 ;
else
V_44 -> V_94 . V_95 =
V_11 -> V_15 . V_15 . V_16 . V_93 ;
}
V_9 -> V_44 . V_94 . V_89 = V_44 -> V_49 . V_89 ;
}
static inline enum V_109 F_43 (
struct V_114 * V_102 )
{
return ( V_102 -> V_103 == V_104 ) ? V_100 :
V_101 ;
}
static void F_21 ( struct V_8 * V_9 , int V_115 )
{
struct V_10 * V_11 ;
F_6 ( 2 , V_13 , L_13 ) ;
V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
if ( V_65 == V_9 -> V_57 )
V_11 -> V_62 = V_116 ;
else if ( 2 == V_115 )
V_11 -> V_62 = V_117 ;
else
V_11 -> V_62 = V_118 ;
}
static int F_44 (
struct V_38 * V_119 ,
struct V_120 * V_121 ,
int V_122 )
{
struct V_123 * V_124 ;
const char * V_125 ;
int V_76 ;
F_6 ( 2 , V_13 , L_14 ) ;
V_125 = V_121 -> V_126 [ V_122 ] . V_125 ;
if ( V_125 == NULL )
return - 1 ;
for ( V_76 = 0 ; V_76 < V_119 -> V_127 ; V_76 ++ ) {
V_124 = & V_119 -> V_124 [ V_76 ] ;
if ( ! strcmp ( V_124 -> V_128 , V_125 ) )
return V_76 ;
}
return - 1 ;
}
static int F_45 (
struct V_38 * V_119 ,
struct V_8 * V_9 ,
int V_85 )
{
struct V_120 * V_121 =
& V_119 -> V_129 [ V_9 -> V_57 ] ;
struct V_123 * V_124 = NULL ;
struct V_130 * V_52 = NULL ;
T_2 V_131 = 0 , V_132 = 0 ;
int V_133 ;
int V_46 ;
V_133 = F_44 ( V_119 , V_121 , V_85 ) ;
if ( V_133 >= 0 ) {
V_52 = V_74 . V_52 [ V_133 ] ;
V_124 = & V_119 -> V_124 [ V_133 ] ;
}
if ( V_52 && V_119 -> V_134 ) {
V_46 = V_119 -> V_134 ( V_9 -> V_57 ,
V_124 -> V_128 ) ;
if ( V_46 < 0 ) {
F_6 ( 1 , V_13 , L_15 \
L_16 ,
V_124 -> V_128 , V_85 ) ;
return V_46 ;
}
}
if ( V_52 ) {
V_131 = V_121 -> V_126 [ V_85 ] . V_135 ;
V_132 = V_121 -> V_126 [ V_85 ] . V_136 ;
V_46 = F_19 ( V_52 , V_53 , V_137 ,
V_131 , V_132 , 0 ) ;
if ( V_46 < 0 && V_46 != - V_55 ) {
F_6 ( 1 , V_13 , L_17 ) ;
return V_46 ;
}
}
V_9 -> V_138 = V_85 ;
V_9 -> V_52 = V_52 ;
V_9 -> V_44 . V_102 = V_121 -> V_139 ;
V_9 -> V_140 . V_141 = V_121 -> V_126 [ V_85 ] . V_131 . V_142 ;
return 0 ;
}
static int F_46 ( struct V_143 * V_143 , void * V_144 , T_3 * V_145 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
int V_46 = 0 ;
F_6 ( 2 , V_13 , L_18 ) ;
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_148 , V_145 ) ;
if ( V_46 == - V_55 || V_46 == - V_56 )
return - V_149 ;
if ( V_46 ) {
F_6 ( 1 , V_13 , L_19 ) ;
return V_46 ;
}
return 0 ;
}
static int F_49 ( struct V_143 * V_143 , void * V_144 , T_3 * V_142 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
F_6 ( 2 , V_13 , L_20 ) ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_152 )
return - V_149 ;
* V_142 = V_9 -> V_53 . V_89 ;
return 0 ;
}
static int F_50 ( struct V_143 * V_143 , void * V_144 , T_3 V_145 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
int V_46 ;
F_6 ( 2 , V_13 , L_21 ) ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_152 )
return - V_149 ;
if ( F_51 ( & V_11 -> V_153 ) )
return - V_154 ;
V_9 -> V_53 . V_89 = V_145 ;
memset ( & V_9 -> V_53 . V_90 , 0 , sizeof( V_9 -> V_53 . V_90 ) ) ;
if ( F_42 ( V_9 ) ) {
F_52 ( L_22 ) ;
return - V_18 ;
}
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_155 , V_145 ) ;
if ( V_46 && V_46 != - V_55 && V_46 != - V_56 ) {
F_6 ( 1 , V_13 , L_23 ) ;
return V_46 ;
}
return 0 ;
}
static int F_53 ( struct V_143 * V_143 , void * V_144 ,
struct V_150 * V_131 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_120 * V_121 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
if ( V_131 -> V_85 >= V_121 -> V_156 )
return - V_18 ;
memcpy ( V_131 , & V_121 -> V_126 [ V_131 -> V_85 ] . V_131 ,
sizeof( * V_131 ) ) ;
return 0 ;
}
static int F_54 ( struct V_143 * V_143 , void * V_144 , unsigned int * V_85 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
* V_85 = V_9 -> V_138 ;
return 0 ;
}
static int F_55 ( struct V_143 * V_143 , void * V_144 , unsigned int V_85 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_120 * V_121 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
if ( V_85 >= V_121 -> V_156 )
return - V_18 ;
if ( F_51 ( & V_11 -> V_153 ) )
return - V_154 ;
return F_45 ( V_82 , V_9 , V_85 ) ;
}
static int F_56 ( struct V_143 * V_143 , void * V_144 ,
struct V_157 * V_15 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
if ( V_15 -> V_85 != 0 ) {
F_6 ( 1 , V_13 , L_24 ) ;
return - V_18 ;
}
if ( V_9 -> V_44 . V_102 . V_103 == V_104 ) {
V_15 -> type = V_108 ;
strcpy ( V_15 -> V_158 , L_25 ) ;
V_15 -> V_105 = V_106 ;
} else {
V_15 -> type = V_108 ;
strcpy ( V_15 -> V_158 , L_26 ) ;
V_15 -> V_105 = V_107 ;
}
return 0 ;
}
static int F_57 ( struct V_143 * V_143 , void * V_144 ,
struct V_159 * V_15 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_160 * V_161 = & V_15 -> V_15 . V_16 ;
struct V_10 * V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
struct V_42 * V_42 = & V_9 -> V_44 ;
if ( V_42 -> V_102 . V_103 == V_104 ) {
if ( V_161 -> V_105 != V_106 )
V_161 -> V_105 = V_106 ;
} else {
if ( V_161 -> V_105 != V_107 )
V_161 -> V_105 = V_107 ;
}
V_11 -> V_15 . V_15 . V_16 . V_105 = V_161 -> V_105 ;
F_42 ( V_9 ) ;
V_161 -> V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_161 -> V_97 = V_11 -> V_15 . V_15 . V_16 . V_97 ;
V_161 -> V_93 = V_11 -> V_15 . V_15 . V_16 . V_91 ;
V_161 -> V_91 = V_11 -> V_15 . V_15 . V_16 . V_91 ;
V_161 -> V_92 = V_11 -> V_15 . V_15 . V_16 . V_92 ;
V_161 -> V_17 = V_161 -> V_93 * V_161 -> V_92 * 2 ;
V_161 -> V_144 = 0 ;
return 0 ;
}
static int F_58 ( struct V_143 * V_143 , void * V_144 ,
struct V_159 * V_15 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( V_11 -> V_15 . type != V_15 -> type )
return - V_18 ;
* V_15 = V_11 -> V_15 ;
return 0 ;
}
static int F_59 ( struct V_143 * V_143 , void * V_144 ,
struct V_159 * V_15 )
{
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
int V_46 ;
F_6 ( 2 , V_13 , L_27 , V_162 ) ;
if ( F_51 ( & V_11 -> V_153 ) )
return - V_154 ;
V_46 = F_57 ( V_143 , V_144 , V_15 ) ;
if ( V_46 )
return V_46 ;
V_11 -> V_15 = * V_15 ;
return 0 ;
}
static int F_60 ( struct V_143 * V_143 , void * V_144 ,
struct V_163 * V_164 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
V_164 -> V_165 = V_166 | V_167 ;
V_164 -> V_151 = V_164 -> V_165 | V_168 ;
F_61 ( V_164 -> V_169 , V_170 , sizeof( V_164 -> V_169 ) ) ;
snprintf ( V_164 -> V_171 , sizeof( V_164 -> V_171 ) , L_28 ,
F_62 ( V_40 ) ) ;
F_61 ( V_164 -> V_172 , V_82 -> V_173 , sizeof( V_164 -> V_172 ) ) ;
return 0 ;
}
static int
F_63 ( struct V_143 * V_143 , void * V_144 ,
struct V_174 * V_175 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
int V_46 ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_176 )
return - V_149 ;
V_175 -> V_177 = 0 ;
V_46 = F_19 ( V_9 -> V_52 , V_177 , V_178 , V_175 ) ;
if ( V_46 == - V_55 || V_46 == - V_56 )
return - V_18 ;
return V_46 ;
}
static int
F_64 ( struct V_143 * V_143 , void * V_144 ,
struct V_179 * V_175 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
int V_46 ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_176 )
return - V_149 ;
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_180 , V_175 ) ;
if ( V_46 == - V_55 || V_46 == - V_56 )
return - V_149 ;
return V_46 ;
}
static int F_65 ( struct V_143 * V_143 , void * V_144 ,
struct V_179 * V_175 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_42 * V_44 = & V_9 -> V_44 ;
struct V_81 * V_49 = & V_44 -> V_49 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_83 * V_84 = & V_9 -> V_53 ;
struct V_181 * V_182 = & V_84 -> V_90 . V_182 ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
int V_46 ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_176 )
return - V_149 ;
if ( V_175 -> type != V_183 ) {
F_6 ( 2 , V_13 , L_29 ) ;
return - V_18 ;
}
if ( F_51 ( & V_11 -> V_153 ) )
return - V_154 ;
V_46 = F_19 ( V_9 -> V_52 , V_53 , V_184 , V_175 ) ;
if ( V_46 == - V_55 || V_46 == - V_56 )
V_46 = 0 ;
if ( V_46 < 0 ) {
F_6 ( 2 , V_13 , L_30 ) ;
return V_46 ;
}
if ( ! ( V_175 -> V_182 . V_91 && V_175 -> V_182 . V_92 &&
( V_175 -> V_182 . V_185 ||
V_175 -> V_182 . V_186 ||
V_175 -> V_182 . V_187 ) &&
V_175 -> V_182 . V_188 &&
( V_175 -> V_182 . V_189 ||
V_175 -> V_182 . V_190 ) ) ) {
F_6 ( 2 , V_13 , L_31
L_32
L_33
L_34
L_35 ) ;
return - V_18 ;
}
V_84 -> V_90 = * V_175 ;
V_49 -> V_191 = F_66 ( V_182 ) - 8 ;
V_49 -> V_192 = V_182 -> V_91 ;
V_49 -> V_193 = 1 ;
V_49 -> V_194 = V_182 -> V_190 + V_182 -> V_189 + 1 ;
V_49 -> V_195 = F_67 ( V_182 ) ;
if ( V_182 -> V_196 ) {
if ( V_182 -> V_197 || V_182 -> V_198 || V_182 -> V_199 ) {
V_49 -> V_200 = V_49 -> V_195 / 2 -
( V_182 -> V_188 - 1 ) ;
V_49 -> V_201 = V_49 -> V_195 / 2 + 1 ;
V_49 -> V_202 = V_49 -> V_201 + V_182 -> V_199 +
V_182 -> V_197 + 1 ;
V_49 -> V_203 = V_49 -> V_195 -
( V_182 -> V_198 - 1 ) ;
} else {
F_6 ( 2 , V_13 , L_36
L_37 ) ;
return - V_18 ;
}
} else {
V_49 -> V_200 = V_49 -> V_195 - ( V_182 -> V_188 - 1 ) ;
}
strncpy ( V_49 -> V_128 , L_38 , V_204 ) ;
V_49 -> V_91 = V_182 -> V_91 ;
V_49 -> V_92 = V_182 -> V_92 ;
V_49 -> V_79 = V_182 -> V_196 ? 0 : 1 ;
V_49 -> V_50 = 0 ;
V_49 -> V_205 = 0 ;
V_49 -> V_206 = 0 ;
V_49 -> V_88 = 1 ;
V_49 -> V_89 = 0 ;
V_84 -> V_89 = 0 ;
return 0 ;
}
static int F_68 ( struct V_143 * V_143 , void * V_144 ,
struct V_179 * V_175 )
{
struct V_38 * V_82 = V_40 -> V_41 ;
struct V_146 * V_147 = F_47 ( V_143 ) ;
struct V_8 * V_9 = F_48 ( V_147 ) ;
struct V_83 * V_84 = & V_9 -> V_53 ;
struct V_120 * V_121 ;
struct V_150 V_131 ;
if ( V_82 -> V_129 [ V_9 -> V_57 ] . V_126 == NULL )
return - V_149 ;
V_121 = & V_82 -> V_129 [ V_9 -> V_57 ] ;
V_131 = V_121 -> V_126 [ V_9 -> V_138 ] . V_131 ;
if ( V_131 . V_151 != V_176 )
return - V_149 ;
* V_175 = V_84 -> V_90 ;
return 0 ;
}
static int F_69 ( struct V_143 * V_207 , void * V_144 )
{
F_70 ( & V_74 . V_208 , 0 , V_209 , V_210 ) ;
return 0 ;
}
static int F_71 ( void )
{
int V_51 , V_76 , V_211 ;
int V_212 ;
for ( V_76 = 0 ; V_76 < V_213 ; V_76 ++ ) {
V_74 . V_73 [ V_76 ] =
F_72 ( sizeof( * V_74 . V_73 [ V_76 ] ) , V_214 ) ;
if ( ! V_74 . V_73 [ V_76 ] ) {
V_212 = V_76 ;
V_51 = - V_215 ;
goto V_216;
}
}
return 0 ;
V_216:
for ( V_211 = 0 ; V_211 < V_212 ; V_211 ++ )
F_73 ( V_74 . V_73 [ V_211 ] ) ;
return V_51 ;
}
static int F_74 ( struct V_217 * V_218 ,
struct V_130 * V_219 ,
struct V_220 * V_221 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_74 . V_82 -> V_127 ; V_76 ++ )
if ( ! strcmp ( V_74 . V_82 -> V_124 [ V_76 ] . V_128 ,
V_219 -> V_128 ) ) {
V_74 . V_52 [ V_76 ] = V_219 ;
return 0 ;
}
return - V_18 ;
}
static int F_75 ( void )
{
struct V_10 * V_11 ;
struct V_146 * V_147 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_211 , V_51 , V_222 ;
for ( V_211 = 0 ; V_211 < V_213 ; V_211 ++ ) {
V_9 = V_74 . V_73 [ V_211 ] ;
V_9 -> V_57 = V_211 ;
V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
F_76 ( & V_11 -> V_34 ) ;
F_77 ( & V_11 -> V_223 ) ;
V_51 = F_45 ( V_74 . V_82 , V_9 , 0 ) ;
if ( V_51 )
goto V_224;
V_9 -> V_53 . V_89 = V_225 ;
memset ( & V_9 -> V_53 . V_90 , 0 , sizeof( V_9 -> V_53 . V_90 ) ) ;
F_42 ( V_9 ) ;
V_7 = & V_11 -> V_153 ;
V_7 -> type = V_108 ;
V_7 -> V_226 = V_227 | V_228 | V_229 ;
V_7 -> V_230 = V_9 ;
V_7 -> V_231 = & V_232 ;
V_7 -> V_233 = & V_234 ;
V_7 -> V_235 = sizeof( struct V_1 ) ;
V_7 -> V_236 = V_237 ;
V_7 -> V_238 = 1 ;
V_7 -> V_223 = & V_11 -> V_223 ;
V_7 -> V_73 = V_40 ;
V_51 = F_78 ( V_7 ) ;
if ( V_51 ) {
F_52 ( L_39 ) ;
goto V_224;
}
F_79 ( & V_11 -> V_36 ) ;
V_147 = & V_9 -> V_140 ;
F_61 ( V_147 -> V_128 , V_170 , sizeof( V_147 -> V_128 ) ) ;
V_147 -> V_239 = V_240 ;
V_147 -> V_241 = & V_242 ;
V_147 -> V_243 = & V_244 ;
V_147 -> V_208 = & V_74 . V_208 ;
V_147 -> V_245 = V_246 ;
V_147 -> V_247 = V_7 ;
V_147 -> V_223 = & V_11 -> V_223 ;
F_80 ( & V_9 -> V_140 , V_9 ) ;
V_51 = F_81 ( V_147 ,
V_248 , ( V_211 ? 1 : 0 ) ) ;
if ( V_51 )
goto V_224;
}
F_82 ( & V_74 . V_208 , L_40 ) ;
return 0 ;
V_224:
for ( V_222 = 0 ; V_222 < V_211 ; V_222 ++ ) {
V_9 = V_74 . V_73 [ V_222 ] ;
V_11 = & V_9 -> V_11 [ V_222 ] ;
F_83 ( & V_9 -> V_140 ) ;
}
F_73 ( V_74 . V_52 ) ;
F_84 ( & V_74 . V_208 ) ;
return V_51 ;
}
static int F_85 ( struct V_217 * V_218 )
{
return F_75 () ;
}
static T_4 int F_86 ( struct V_249 * V_250 )
{
struct V_123 * V_251 ;
struct V_252 * V_253 ;
struct V_254 * V_255 ;
int V_127 ;
int V_256 = 0 ;
int V_76 , V_51 ;
V_40 = & V_250 -> V_73 ;
V_51 = F_71 () ;
if ( V_51 ) {
F_87 ( V_40 -> V_169 , L_41 ) ;
return V_51 ;
}
V_51 = F_88 ( V_40 , & V_74 . V_208 ) ;
if ( V_51 ) {
F_87 ( V_40 -> V_169 , L_42 ) ;
return V_51 ;
}
while ( ( V_255 = F_89 ( V_250 , V_257 , V_256 ) ) ) {
V_51 = F_90 ( & V_250 -> V_73 , V_255 -> V_258 , F_39 ,
V_259 , V_170 ,
( void * ) ( & V_74 . V_73 [ V_256 ] ->
V_57 ) ) ;
if ( V_51 ) {
V_51 = - V_18 ;
goto V_260;
}
V_256 ++ ;
}
V_74 . V_82 = V_250 -> V_73 . V_41 ;
V_127 = V_74 . V_82 -> V_127 ;
V_74 . V_52 = F_72 ( sizeof( struct V_130 * ) * V_127 ,
V_214 ) ;
if ( V_74 . V_52 == NULL ) {
F_52 ( L_43 ) ;
V_51 = - V_215 ;
goto V_260;
}
if ( ! V_74 . V_82 -> V_261 ) {
V_253 = F_91 ( 1 ) ;
for ( V_76 = 0 ; V_76 < V_127 ; V_76 ++ ) {
V_251 = & V_74 . V_82 -> V_124 [ V_76 ] ;
V_74 . V_52 [ V_76 ] =
F_92 ( & V_74 . V_208 ,
V_253 ,
& V_251 ->
V_262 ,
NULL ) ;
if ( ! V_74 . V_52 [ V_76 ] ) {
F_52 ( L_44 ) ;
V_51 = - V_56 ;
goto V_263;
}
F_82 ( & V_74 . V_208 ,
L_45 ,
V_251 -> V_128 ) ;
}
F_75 () ;
} else {
V_74 . V_218 . V_264 = V_74 . V_82 -> V_221 ;
V_74 . V_218 . V_265 = V_74 . V_82 -> V_261 [ 0 ] ;
V_74 . V_218 . V_266 = F_74 ;
V_74 . V_218 . V_267 = F_85 ;
V_51 = F_93 ( & V_74 . V_208 ,
& V_74 . V_218 ) ;
if ( V_51 ) {
F_52 ( L_46 ) ;
V_51 = - V_18 ;
goto V_263;
}
}
return 0 ;
V_263:
F_73 ( V_74 . V_52 ) ;
V_260:
F_84 ( & V_74 . V_208 ) ;
return V_51 ;
}
static int F_94 ( struct V_249 * V_28 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_76 ;
F_84 ( & V_74 . V_208 ) ;
F_73 ( V_74 . V_52 ) ;
for ( V_76 = 0 ; V_76 < V_213 ; V_76 ++ ) {
V_9 = V_74 . V_73 [ V_76 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_83 ( & V_9 -> V_140 ) ;
F_73 ( V_74 . V_73 [ V_76 ] ) ;
}
return 0 ;
}
static int F_95 ( struct V_28 * V_73 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_213 ; V_76 ++ ) {
V_9 = V_74 . V_73 [ V_76 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( ! F_96 ( & V_11 -> V_153 ) )
continue;
F_97 ( & V_11 -> V_223 ) ;
if ( V_9 -> V_57 == V_64 ) {
F_26 ( 0 ) ;
F_25 ( 0 ) ;
}
if ( V_9 -> V_57 == V_65 ||
V_50 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_98 ( & V_11 -> V_223 ) ;
}
return 0 ;
}
static int F_99 ( struct V_28 * V_73 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_213 ; V_76 ++ ) {
V_9 = V_74 . V_73 [ V_76 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( ! F_96 ( & V_11 -> V_153 ) )
continue;
F_97 ( & V_11 -> V_223 ) ;
if ( V_9 -> V_57 == V_64 ) {
F_26 ( 1 ) ;
F_25 ( 1 ) ;
}
if ( V_9 -> V_57 == V_65 ||
V_50 == 2 ) {
F_29 ( 1 ) ;
F_28 ( 1 ) ;
}
F_98 ( & V_11 -> V_223 ) ;
}
return 0 ;
}
