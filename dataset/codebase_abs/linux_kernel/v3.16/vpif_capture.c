static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_4 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_5 ( 2 , V_11 , L_1 ) ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_6 ( V_3 , 0 , V_9 -> V_13 . V_13 . V_14 . V_15 ) ;
if ( F_7 ( V_3 , 0 ) > F_8 ( V_3 , 0 ) )
return - V_16 ;
V_3 -> V_17 . V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_10 = F_9 ( V_3 , 0 ) ;
if ( ! F_10 ( ( V_10 + V_9 -> V_19 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_20 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_21 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_22 ) , 8 ) ) {
F_5 ( 1 , V_11 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_4 * V_23 ,
const struct V_24 * V_13 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int V_27 [] , void * V_28 [] )
{
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_5 ( 2 , V_11 , L_3 ) ;
if ( V_13 && V_13 -> V_13 . V_14 . V_15 < V_9 -> V_13 . V_13 . V_14 . V_15 )
return - V_16 ;
if ( V_23 -> V_29 + * V_25 < 3 )
* V_25 = 3 - V_23 -> V_29 ;
* V_26 = 1 ;
V_27 [ 0 ] = V_13 ? V_13 -> V_13 . V_14 . V_15 : V_9 -> V_13 . V_13 . V_14 . V_15 ;
V_28 [ 0 ] = V_9 -> V_30 ;
F_12 ( V_7 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 -> V_4 ) ;
struct V_1 * V_31 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
unsigned long V_32 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_5 ( 2 , V_11 , L_4 ) ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
F_15 ( & V_31 -> V_34 , & V_9 -> V_35 ) ;
F_16 ( & V_9 -> V_33 , V_32 ) ;
}
static int F_17 ( struct V_4 * V_23 , unsigned int V_36 )
{
struct V_37 * V_38 =
V_39 -> V_40 ;
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_41 * V_42 = & V_7 -> V_43 ;
struct V_1 * V_31 , * V_44 ;
unsigned long V_10 , V_32 ;
int V_45 ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
V_7 -> V_46 = 0 ;
if ( V_38 -> V_47 ) {
V_45 = V_38 ->
V_47 ( V_42 -> V_48 . V_49 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_5 ) ;
goto V_50;
}
}
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_53 , 1 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 ) {
F_5 ( 1 , V_11 , L_6 ) ;
goto V_50;
}
V_45 = F_19 ( V_42 , V_7 -> V_56 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_7 ) ;
goto V_50;
}
V_49 = V_45 ;
F_20 ( V_7 , V_45 ) ;
V_9 -> V_57 = V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_57 -> V_34 ) ;
F_16 ( & V_9 -> V_33 , V_32 ) ;
V_9 -> V_57 -> V_3 . V_60 = V_61 ;
V_10 = F_9 ( & V_9 -> V_57 -> V_3 , 0 ) ;
V_9 -> V_62 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
V_63 [ V_12 ] [ V_7 -> V_56 ] = 1 ;
if ( V_64 == V_7 -> V_56 ) {
F_23 () ;
F_24 ( 1 ) ;
F_25 ( 1 ) ;
}
if ( V_65 == V_7 -> V_56 ||
V_49 == 2 ) {
F_26 () ;
F_27 ( 1 ) ;
F_28 ( 1 ) ;
}
return 0 ;
V_50:
F_29 (buf, tmp, &common->dma_queue, list) {
F_22 ( & V_31 -> V_34 ) ;
F_30 ( & V_31 -> V_3 , V_66 ) ;
}
F_16 ( & V_9 -> V_33 , V_32 ) ;
return V_45 ;
}
static void F_31 ( struct V_4 * V_23 )
{
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 ;
unsigned long V_32 ;
int V_45 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( V_64 == V_7 -> V_56 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_65 == V_7 -> V_56 ||
V_49 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
V_49 = 0 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_53 , 0 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 )
F_5 ( 1 , V_11 , L_8 ) ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
if ( V_9 -> V_57 == V_9 -> V_58 ) {
F_30 ( & V_9 -> V_57 -> V_3 , V_67 ) ;
} else {
if ( V_9 -> V_57 != NULL )
F_30 ( & V_9 -> V_57 -> V_3 ,
V_67 ) ;
if ( V_9 -> V_58 != NULL )
F_30 ( & V_9 -> V_58 -> V_3 ,
V_67 ) ;
}
while ( ! F_32 ( & V_9 -> V_35 ) ) {
V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_58 -> V_34 ) ;
F_30 ( & V_9 -> V_58 -> V_3 , V_67 ) ;
}
F_16 ( & V_9 -> V_33 , V_32 ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
F_34 ( & V_9 -> V_57 -> V_3 . V_17 . V_68 ) ;
F_30 ( & V_9 -> V_57 -> V_3 ,
V_69 ) ;
V_9 -> V_57 = V_9 -> V_58 ;
}
static void F_35 ( struct V_8 * V_9 )
{
unsigned long V_10 = 0 ;
F_36 ( & V_9 -> V_33 ) ;
V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_58 -> V_34 ) ;
F_37 ( & V_9 -> V_33 ) ;
V_9 -> V_58 -> V_3 . V_60 = V_61 ;
V_10 = F_9 ( & V_9 -> V_58 -> V_3 , 0 ) ;
V_9 -> V_62 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
}
static T_1 F_38 ( int V_70 , void * V_71 )
{
struct V_72 * V_73 = & V_74 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
enum V_75 V_18 ;
int V_56 = 0 ;
int V_76 = - 1 , V_77 ;
V_56 = * ( int * ) ( V_71 ) ;
if ( ! F_39 ( V_56 ) )
return V_78 ;
V_7 = V_73 -> V_73 [ V_56 ] ;
V_18 = V_7 -> V_9 [ V_12 ] . V_13 . V_13 . V_14 . V_18 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
V_9 = & V_7 -> V_9 [ V_77 ] ;
if ( 1 == V_7 -> V_43 . V_48 . V_80 ) {
F_36 ( & V_9 -> V_33 ) ;
if ( F_32 ( & V_9 -> V_35 ) ) {
F_37 ( & V_9 -> V_33 ) ;
continue;
}
F_37 ( & V_9 -> V_33 ) ;
if ( ! V_63 [ V_77 ] [ V_56 ] )
F_33 ( V_9 ) ;
V_63 [ V_77 ] [ V_56 ] = 0 ;
F_35 ( V_9 ) ;
V_63 [ V_77 ] [ V_56 ] = 0 ;
} else {
if ( V_63 [ V_77 ] [ V_56 ] ) {
V_63 [ V_77 ] [ V_56 ] = 0 ;
continue;
}
if ( 0 == V_77 ) {
V_7 -> V_46 ^= 1 ;
V_76 = F_40 ( V_7 -> V_56 ) ;
if ( V_76 != V_7 -> V_46 ) {
if ( 0 == V_76 )
V_7 -> V_46 = V_76 ;
return V_81 ;
}
}
if ( 0 == V_76 ) {
if ( V_9 -> V_57 == V_9 -> V_58 )
continue;
F_33 ( V_9 ) ;
} else if ( 1 == V_76 ) {
F_36 ( & V_9 -> V_33 ) ;
if ( F_32 ( & V_9 -> V_35 ) ||
( V_9 -> V_57 != V_9 -> V_58 ) ) {
F_37 ( & V_9 -> V_33 ) ;
continue;
}
F_37 ( & V_9 -> V_33 ) ;
F_35 ( V_9 ) ;
}
}
}
return V_81 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_41 * V_43 = & V_7 -> V_43 ;
const struct V_82 * V_83 ;
struct V_82 * V_48 = & V_43 -> V_48 ;
struct V_84 * V_85 = & V_7 -> V_52 ;
int V_86 ;
F_5 ( 2 , V_11 , L_9 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
V_83 = & V_88 [ V_86 ] ;
if ( V_83 -> V_89 == 0 ) {
F_5 ( 2 , V_11 , L_10 ) ;
if ( V_83 -> V_90 & V_85 -> V_90 ) {
memcpy ( V_48 , V_83 , sizeof( * V_83 ) ) ;
break;
}
} else {
F_5 ( 2 , V_11 , L_11 ) ;
if ( ! memcmp ( & V_83 -> V_91 , & V_85 -> V_91 ,
sizeof( V_85 -> V_91 ) ) ) {
memcpy ( V_48 , V_83 , sizeof( * V_83 ) ) ;
break;
}
}
}
if ( V_86 == V_87 )
return - V_16 ;
V_9 -> V_13 . V_13 . V_14 . V_92 = V_48 -> V_92 ;
V_9 -> V_92 = V_48 -> V_92 ;
V_9 -> V_13 . V_13 . V_14 . V_93 = V_48 -> V_93 ;
V_9 -> V_93 = V_48 -> V_93 ;
V_9 -> V_13 . V_13 . V_14 . V_94 = V_48 -> V_92 ;
V_43 -> V_95 . V_96 = V_48 -> V_92 ;
V_43 -> V_95 . V_97 = V_48 -> V_80 ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
unsigned int V_96 , V_98 , V_15 ;
struct V_84 * V_85 = & ( V_7 -> V_52 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
enum V_75 V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
F_5 ( 2 , V_11 , L_12 ) ;
if ( V_99 == V_18 ) {
if ( V_43 -> V_48 . V_80 )
V_85 -> V_100 = V_101 ;
else
V_85 -> V_100 = V_102 ;
} else
V_85 -> V_100 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_15 = V_9 -> V_13 . V_13 . V_14 . V_15 ;
V_96 = V_9 -> V_13 . V_13 . V_14 . V_94 ;
V_98 = V_15 / ( V_96 * 2 ) ;
if ( ( V_101 == V_85 -> V_100 ) ||
( V_102 == V_85 -> V_100 ) ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_96 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_15 / 2 + V_96 ;
} else if ( V_103 == V_85 -> V_100 ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_15 / 4 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_9 -> V_21 + V_15 / 4 ;
} else if ( V_104 == V_85 -> V_100 ) {
V_9 -> V_20 = 0 ;
V_9 -> V_19 = V_15 / 4 ;
V_9 -> V_22 = V_15 / 2 ;
V_9 -> V_21 = V_9 -> V_22 + V_15 / 4 ;
}
if ( ( V_101 == V_85 -> V_100 ) ||
( V_102 == V_85 -> V_100 ) )
V_43 -> V_95 . V_97 = 1 ;
else
V_43 -> V_95 . V_97 = 0 ;
if ( 1 == V_43 -> V_48 . V_80 )
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 ;
else {
if ( ( V_18 == V_99 )
|| ( V_18 == V_102 ) )
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 * 2 ;
else
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 ;
}
V_7 -> V_43 . V_95 . V_90 = V_43 -> V_48 . V_90 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
F_5 ( 2 , V_11 , L_13 ) ;
V_9 -> V_13 . V_13 . V_14 . V_18 = V_99 ;
V_9 -> V_13 . V_13 . V_14 . V_15
= V_105 . V_106 [ V_7 -> V_56 ] ;
if ( V_7 -> V_43 . V_107 . V_108 == V_109 )
V_9 -> V_13 . V_13 . V_14 . V_110 = V_111 ;
else
V_9 -> V_13 . V_13 . V_14 . V_110 = V_112 ;
V_9 -> V_13 . type = V_113 ;
}
static inline enum V_75 F_43 (
struct V_114 * V_107 )
{
return ( V_107 -> V_108 == V_109 ) ? V_101 :
V_102 ;
}
static int F_44 ( struct V_6 * V_7 ,
struct V_115 * V_116 ,
int V_117 )
{
struct V_8 * V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
struct V_41 * V_41 = & V_7 -> V_43 ;
enum V_75 V_18 = V_116 -> V_18 ;
T_2 V_15 , V_96 , V_98 ;
int V_45 = - V_16 ;
F_5 ( 2 , V_11 , L_14 ) ;
if ( V_41 -> V_107 . V_108 == V_109 ) {
if ( V_116 -> V_110 != V_111 ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_15 ) ;
goto exit;
}
V_116 -> V_110 = V_111 ;
}
} else {
if ( V_116 -> V_110 != V_112 ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_16 ) ;
goto exit;
}
V_116 -> V_110 = V_112 ;
}
}
if ( ! ( F_45 ( V_18 ) ) ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_17 ) ;
goto exit;
}
V_18 = F_43 ( & V_41 -> V_107 ) ;
} else if ( V_18 == V_99 )
V_18 = F_43 ( & V_41 -> V_107 ) ;
V_96 = V_116 -> V_94 ;
if ( V_96 < V_41 -> V_48 . V_92 ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_18 ) ;
goto exit;
}
V_96 = V_41 -> V_48 . V_92 ;
}
V_15 = V_116 -> V_15 ;
V_98 = V_15 / ( V_96 * 2 ) ;
if ( V_98 < V_41 -> V_48 . V_93 ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_19 ) ;
goto exit;
}
V_98 = V_41 -> V_48 . V_93 ;
}
if ( ! F_46 ( V_96 , 8 ) ) {
if ( ! V_117 ) {
F_5 ( 2 , V_11 , L_20 ) ;
goto exit;
}
V_96 = ( ( ( V_96 + 7 ) / 8 ) * 8 ) ;
}
if ( V_117 ) {
V_116 -> V_94 = V_96 ;
V_116 -> V_15 = V_96 * V_98 * 2 ;
}
V_116 -> V_92 = V_9 -> V_13 . V_13 . V_14 . V_92 ;
V_116 -> V_93 = V_9 -> V_13 . V_13 . V_14 . V_93 ;
return 0 ;
exit:
return V_45 ;
}
static void F_20 ( struct V_6 * V_7 , int V_118 )
{
struct V_8 * V_9 ;
F_5 ( 2 , V_11 , L_21 ) ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
if ( V_65 == V_7 -> V_56 )
V_9 -> V_62 = V_119 ;
else if ( 2 == V_118 )
V_9 -> V_62 = V_120 ;
else
V_9 -> V_62 = V_121 ;
}
static int F_47 (
struct V_37 * V_122 ,
struct V_123 * V_124 ,
int V_125 )
{
struct V_126 * V_127 ;
const char * V_128 ;
int V_77 ;
F_5 ( 2 , V_11 , L_22 ) ;
V_128 = V_124 -> V_129 [ V_125 ] . V_128 ;
if ( V_128 == NULL )
return - 1 ;
for ( V_77 = 0 ; V_77 < V_122 -> V_130 ; V_77 ++ ) {
V_127 = & V_122 -> V_127 [ V_77 ] ;
if ( ! strcmp ( V_127 -> V_131 , V_128 ) )
return V_77 ;
}
return - 1 ;
}
static int F_48 (
struct V_37 * V_122 ,
struct V_6 * V_7 ,
int V_86 )
{
struct V_123 * V_124 =
& V_122 -> V_132 [ V_7 -> V_56 ] ;
struct V_126 * V_127 = NULL ;
struct V_133 * V_51 = NULL ;
T_2 V_134 = 0 , V_135 = 0 ;
int V_136 ;
int V_45 ;
V_136 = F_47 ( V_122 , V_124 , V_86 ) ;
if ( V_136 >= 0 ) {
V_51 = V_74 . V_51 [ V_136 ] ;
V_127 = & V_122 -> V_127 [ V_136 ] ;
}
if ( V_51 && V_122 -> V_137 ) {
V_45 = V_122 -> V_137 ( V_7 -> V_56 ,
V_127 -> V_131 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_23 \
L_24 ,
V_127 -> V_131 , V_86 ) ;
return V_45 ;
}
}
if ( V_51 ) {
V_134 = V_124 -> V_129 [ V_86 ] . V_138 ;
V_135 = V_124 -> V_129 [ V_86 ] . V_139 ;
V_45 = F_18 ( V_51 , V_52 , V_140 ,
V_134 , V_135 , 0 ) ;
if ( V_45 < 0 && V_45 != - V_54 ) {
F_5 ( 1 , V_11 , L_25 ) ;
return V_45 ;
}
}
V_7 -> V_141 = V_86 ;
V_7 -> V_51 = V_51 ;
V_7 -> V_43 . V_107 = V_124 -> V_142 ;
V_7 -> V_143 -> V_144 = V_124 -> V_129 [ V_86 ] . V_134 . V_145 ;
return 0 ;
}
static int F_49 ( struct V_146 * V_146 , void * V_147 , T_3 * V_148 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
int V_45 = 0 ;
F_5 ( 2 , V_11 , L_26 ) ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_151 , V_148 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_152 ;
if ( V_45 ) {
F_5 ( 1 , V_11 , L_27 ) ;
return V_45 ;
}
return 0 ;
}
static int F_52 ( struct V_146 * V_146 , void * V_147 , T_3 * V_145 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
F_5 ( 2 , V_11 , L_28 ) ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_155 )
return - V_152 ;
* V_145 = V_7 -> V_52 . V_90 ;
return 0 ;
}
static int F_53 ( struct V_146 * V_146 , void * V_147 , T_3 V_148 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
int V_45 ;
F_5 ( 2 , V_11 , L_29 ) ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_155 )
return - V_152 ;
if ( F_54 ( & V_9 -> V_156 ) )
return - V_157 ;
V_7 -> V_52 . V_90 = V_148 ;
memset ( & V_7 -> V_52 . V_91 , 0 , sizeof( V_7 -> V_52 . V_91 ) ) ;
if ( F_41 ( V_7 ) ) {
F_55 ( L_30 ) ;
return - V_16 ;
}
F_42 ( V_7 ) ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_158 , V_148 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 ) {
F_5 ( 1 , V_11 , L_31 ) ;
return V_45 ;
}
return 0 ;
}
static int F_56 ( struct V_146 * V_146 , void * V_147 ,
struct V_153 * V_134 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_123 * V_124 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
if ( V_134 -> V_86 >= V_124 -> V_159 ) {
F_5 ( 1 , V_11 , L_32 ) ;
return - V_16 ;
}
memcpy ( V_134 , & V_124 -> V_129 [ V_134 -> V_86 ] . V_134 ,
sizeof( * V_134 ) ) ;
return 0 ;
}
static int F_57 ( struct V_146 * V_146 , void * V_147 , unsigned int * V_86 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
* V_86 = V_7 -> V_141 ;
return 0 ;
}
static int F_58 ( struct V_146 * V_146 , void * V_147 , unsigned int V_86 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_123 * V_124 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
if ( V_86 >= V_124 -> V_159 )
return - V_16 ;
if ( F_54 ( & V_9 -> V_156 ) )
return - V_157 ;
return F_48 ( V_83 , V_7 , V_86 ) ;
}
static int F_59 ( struct V_146 * V_146 , void * V_147 ,
struct V_160 * V_13 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
if ( V_13 -> V_86 != 0 ) {
F_5 ( 1 , V_11 , L_33 ) ;
return - V_16 ;
}
if ( V_7 -> V_43 . V_107 . V_108 == V_109 ) {
V_13 -> type = V_113 ;
strcpy ( V_13 -> V_161 , L_34 ) ;
V_13 -> V_110 = V_111 ;
} else {
V_13 -> type = V_113 ;
strcpy ( V_13 -> V_161 , L_35 ) ;
V_13 -> V_110 = V_112 ;
}
return 0 ;
}
static int F_60 ( struct V_146 * V_146 , void * V_147 ,
struct V_24 * V_13 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_115 * V_116 = & V_13 -> V_13 . V_14 ;
return F_44 ( V_7 , V_116 , 1 ) ;
}
static int F_61 ( struct V_146 * V_146 , void * V_147 ,
struct V_24 * V_13 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( V_9 -> V_13 . type != V_13 -> type )
return - V_16 ;
* V_13 = V_9 -> V_13 ;
return 0 ;
}
static int F_62 ( struct V_146 * V_146 , void * V_147 ,
struct V_24 * V_13 )
{
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_115 * V_116 ;
int V_45 = 0 ;
F_5 ( 2 , V_11 , L_36 , V_162 ) ;
if ( F_54 ( & V_9 -> V_156 ) )
return - V_157 ;
V_116 = & V_13 -> V_13 . V_14 ;
V_45 = F_44 ( V_7 , V_116 , 0 ) ;
if ( V_45 )
return V_45 ;
V_9 -> V_13 = * V_13 ;
return 0 ;
}
static int F_63 ( struct V_146 * V_146 , void * V_147 ,
struct V_163 * V_164 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
V_164 -> V_165 = V_166 | V_167 ;
V_164 -> V_154 = V_164 -> V_165 | V_168 ;
F_64 ( V_164 -> V_169 , V_170 , sizeof( V_164 -> V_169 ) ) ;
snprintf ( V_164 -> V_171 , sizeof( V_164 -> V_171 ) , L_37 ,
F_65 ( V_39 ) ) ;
F_64 ( V_164 -> V_172 , V_83 -> V_173 , sizeof( V_164 -> V_172 ) ) ;
return 0 ;
}
static int
F_66 ( struct V_146 * V_146 , void * V_147 ,
struct V_174 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
int V_45 ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_176 )
return - V_152 ;
V_175 -> V_177 = 0 ;
V_45 = F_18 ( V_7 -> V_51 , V_177 , V_178 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_16 ;
return V_45 ;
}
static int
F_67 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
int V_45 ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_176 )
return - V_152 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_180 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_152 ;
return V_45 ;
}
static int F_68 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_82 * V_48 = & V_43 -> V_48 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_84 * V_85 = & V_7 -> V_52 ;
struct V_181 * V_182 = & V_85 -> V_91 . V_182 ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
int V_45 ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_176 )
return - V_152 ;
if ( V_175 -> type != V_183 ) {
F_5 ( 2 , V_11 , L_38 ) ;
return - V_16 ;
}
if ( F_54 ( & V_9 -> V_156 ) )
return - V_157 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_184 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
V_45 = 0 ;
if ( V_45 < 0 ) {
F_5 ( 2 , V_11 , L_39 ) ;
return V_45 ;
}
if ( ! ( V_175 -> V_182 . V_92 && V_175 -> V_182 . V_93 &&
( V_175 -> V_182 . V_185 ||
V_175 -> V_182 . V_186 ||
V_175 -> V_182 . V_187 ) &&
V_175 -> V_182 . V_188 &&
( V_175 -> V_182 . V_189 ||
V_175 -> V_182 . V_190 ) ) ) {
F_5 ( 2 , V_11 , L_40
L_41
L_42
L_43
L_44 ) ;
return - V_16 ;
}
V_85 -> V_91 = * V_175 ;
V_48 -> V_191 = F_69 ( V_182 ) - 8 ;
V_48 -> V_192 = V_182 -> V_92 ;
V_48 -> V_193 = 1 ;
V_48 -> V_194 = V_182 -> V_190 + V_182 -> V_189 + 1 ;
V_48 -> V_195 = F_70 ( V_182 ) ;
if ( V_182 -> V_196 ) {
if ( V_182 -> V_197 || V_182 -> V_198 || V_182 -> V_199 ) {
V_48 -> V_200 = V_48 -> V_195 / 2 -
( V_182 -> V_188 - 1 ) ;
V_48 -> V_201 = V_48 -> V_195 / 2 + 1 ;
V_48 -> V_202 = V_48 -> V_201 + V_182 -> V_199 +
V_182 -> V_197 + 1 ;
V_48 -> V_203 = V_48 -> V_195 -
( V_182 -> V_198 - 1 ) ;
} else {
F_5 ( 2 , V_11 , L_45
L_46 ) ;
return - V_16 ;
}
} else {
V_48 -> V_200 = V_48 -> V_195 - ( V_182 -> V_188 - 1 ) ;
}
strncpy ( V_48 -> V_131 , L_47 , V_204 ) ;
V_48 -> V_92 = V_182 -> V_92 ;
V_48 -> V_93 = V_182 -> V_93 ;
V_48 -> V_80 = V_182 -> V_196 ? 0 : 1 ;
V_48 -> V_49 = 0 ;
V_48 -> V_205 = 0 ;
V_48 -> V_206 = 0 ;
V_48 -> V_89 = 1 ;
V_48 -> V_90 = 0 ;
V_85 -> V_90 = 0 ;
return 0 ;
}
static int F_71 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_149 * V_150 = F_50 ( V_146 ) ;
struct V_6 * V_7 = F_51 ( V_150 ) ;
struct V_84 * V_85 = & V_7 -> V_52 ;
struct V_123 * V_124 ;
struct V_153 V_134 ;
if ( V_83 -> V_132 [ V_7 -> V_56 ] . V_129 == NULL )
return - V_152 ;
V_124 = & V_83 -> V_132 [ V_7 -> V_56 ] ;
V_134 = V_124 -> V_129 [ V_7 -> V_141 ] . V_134 ;
if ( V_134 . V_154 != V_176 )
return - V_152 ;
* V_175 = V_85 -> V_91 ;
return 0 ;
}
static int F_72 ( struct V_146 * V_207 , void * V_147 )
{
F_73 ( & V_74 . V_208 , 0 , V_209 , V_210 ) ;
return 0 ;
}
static int F_74 ( void )
{
int V_50 = 0 , V_77 , V_211 ;
int V_212 ;
if ( ( V_213 > 0 ) &&
( V_213 < V_105 . V_214 ) )
V_213 = V_105 . V_214 ;
if ( ( V_215 > 0 ) &&
( V_215 < V_105 . V_214 ) )
V_215 = V_105 . V_214 ;
if ( V_216 < V_105 . V_217 [ V_64 ] )
V_216 =
V_105 . V_217 [ V_64 ] ;
if ( V_218 < V_105 . V_217 [ V_65 ] )
V_218 =
V_105 . V_217 [ V_65 ] ;
V_105 . V_219 [ V_64 ] = V_213 ;
V_105 . V_219 [ V_65 ] = V_215 ;
if ( V_213 ) {
V_105 . V_106 [ V_64 ]
= V_216 ;
}
if ( V_215 ) {
V_105 . V_106 [ V_65 ]
= V_218 ;
}
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_74 . V_73 [ V_77 ] =
F_75 ( sizeof( * V_74 . V_73 [ V_77 ] ) , V_221 ) ;
if ( ! V_74 . V_73 [ V_77 ] ) {
V_212 = V_77 ;
V_50 = - V_222 ;
goto V_223;
}
}
return 0 ;
V_223:
for ( V_211 = 0 ; V_211 < V_212 ; V_211 ++ )
F_76 ( V_74 . V_73 [ V_211 ] ) ;
return V_50 ;
}
static int F_77 ( struct V_224 * V_225 ,
struct V_133 * V_226 ,
struct V_227 * V_228 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_74 . V_83 -> V_130 ; V_77 ++ )
if ( ! strcmp ( V_74 . V_83 -> V_127 [ V_77 ] . V_131 ,
V_226 -> V_131 ) ) {
V_74 . V_51 [ V_77 ] = V_226 ;
return 0 ;
}
return - V_16 ;
}
static int F_78 ( void )
{
struct V_8 * V_9 ;
struct V_149 * V_150 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
int V_77 , V_211 , V_50 , V_229 ;
for ( V_211 = 0 ; V_211 < V_220 ; V_211 ++ ) {
V_7 = V_74 . V_73 [ V_211 ] ;
V_7 -> V_56 = V_211 ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
F_79 ( & V_9 -> V_33 ) ;
F_80 ( & V_9 -> V_230 ) ;
V_50 = F_48 ( V_74 . V_83 , V_7 , 0 ) ;
if ( V_50 )
goto V_231;
V_5 = & V_9 -> V_156 ;
V_5 -> type = V_113 ;
V_5 -> V_232 = V_233 | V_234 | V_235 ;
V_5 -> V_236 = V_7 ;
V_5 -> V_237 = & V_238 ;
V_5 -> V_239 = & V_240 ;
V_5 -> V_241 = sizeof( struct V_1 ) ;
V_5 -> V_242 = V_243 ;
V_5 -> V_244 = 1 ;
V_5 -> V_230 = & V_9 -> V_230 ;
V_50 = F_81 ( V_5 ) ;
if ( V_50 ) {
F_55 ( L_48 ) ;
goto V_231;
}
V_9 -> V_30 = F_82 ( V_39 ) ;
if ( F_83 ( V_9 -> V_30 ) ) {
F_55 ( L_49 ) ;
V_50 = F_84 ( V_9 -> V_30 ) ;
goto V_231;
}
F_85 ( & V_9 -> V_35 ) ;
V_150 = V_7 -> V_143 ;
F_64 ( V_150 -> V_131 , V_170 , sizeof( V_150 -> V_131 ) ) ;
V_150 -> V_245 = V_246 ;
V_150 -> V_247 = & V_248 ;
V_150 -> V_249 = & V_250 ;
V_150 -> V_208 = & V_74 . V_208 ;
V_150 -> V_251 = V_252 ;
V_150 -> V_253 = V_5 ;
V_150 -> V_230 = & V_9 -> V_230 ;
F_86 ( V_254 , & V_150 -> V_32 ) ;
F_87 ( V_7 -> V_143 , V_7 ) ;
V_50 = F_88 ( V_150 ,
V_255 , ( V_211 ? 1 : 0 ) ) ;
if ( V_50 )
goto V_231;
}
F_89 ( & V_74 . V_208 , L_50 ) ;
return 0 ;
V_231:
for ( V_229 = 0 ; V_229 < V_211 ; V_229 ++ ) {
V_7 = V_74 . V_73 [ V_229 ] ;
V_9 = & V_7 -> V_9 [ V_229 ] ;
F_90 ( V_9 -> V_30 ) ;
F_91 ( V_7 -> V_143 ) ;
}
F_76 ( V_74 . V_51 ) ;
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_246 ( V_7 -> V_143 ) ;
}
F_92 ( & V_74 . V_208 ) ;
return V_50 ;
}
static int F_93 ( struct V_224 * V_225 )
{
return F_78 () ;
}
static T_4 int F_94 ( struct V_256 * V_257 )
{
struct V_126 * V_258 ;
int V_77 , V_211 , V_50 ;
int V_259 = 0 ;
struct V_260 * V_261 ;
struct V_6 * V_7 ;
struct V_149 * V_262 ;
struct V_263 * V_264 ;
int V_130 ;
V_39 = & V_257 -> V_73 ;
V_50 = F_74 () ;
if ( V_50 ) {
F_95 ( V_39 -> V_169 , L_51 ) ;
return V_50 ;
}
V_50 = F_96 ( V_39 , & V_74 . V_208 ) ;
if ( V_50 ) {
F_95 ( V_39 -> V_169 , L_52 ) ;
return V_50 ;
}
while ( ( V_264 = F_97 ( V_257 , V_265 , V_259 ) ) ) {
V_50 = F_98 ( & V_257 -> V_73 , V_264 -> V_266 , F_38 ,
V_267 , V_170 ,
( void * ) ( & V_74 . V_73 [ V_259 ] ->
V_56 ) ) ;
if ( V_50 ) {
V_50 = - V_16 ;
goto V_268;
}
V_259 ++ ;
}
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_262 = F_99 () ;
if ( NULL == V_262 ) {
for ( V_211 = 0 ; V_211 < V_77 ; V_211 ++ ) {
V_7 = V_74 . V_73 [ V_211 ] ;
V_246 ( V_7 -> V_143 ) ;
}
V_50 = - V_222 ;
goto V_268;
}
V_7 -> V_143 = V_262 ;
}
V_74 . V_83 = V_257 -> V_73 . V_40 ;
V_130 = V_74 . V_83 -> V_130 ;
V_74 . V_51 = F_75 ( sizeof( struct V_133 * ) * V_130 ,
V_221 ) ;
if ( V_74 . V_51 == NULL ) {
F_55 ( L_53 ) ;
V_50 = - V_222 ;
goto V_269;
}
if ( ! V_74 . V_83 -> V_270 ) {
V_261 = F_100 ( 1 ) ;
for ( V_77 = 0 ; V_77 < V_130 ; V_77 ++ ) {
V_258 = & V_74 . V_83 -> V_127 [ V_77 ] ;
V_74 . V_51 [ V_77 ] =
F_101 ( & V_74 . V_208 ,
V_261 ,
& V_258 ->
V_271 ,
NULL ) ;
if ( ! V_74 . V_51 [ V_77 ] ) {
F_55 ( L_54 ) ;
V_50 = - V_55 ;
goto V_272;
}
F_89 ( & V_74 . V_208 ,
L_55 ,
V_258 -> V_131 ) ;
}
F_78 () ;
} else {
V_74 . V_225 . V_273 = V_74 . V_83 -> V_228 ;
V_74 . V_225 . V_274 = V_74 . V_83 -> V_270 [ 0 ] ;
V_74 . V_225 . V_275 = F_77 ;
V_74 . V_225 . V_276 = F_93 ;
V_50 = F_102 ( & V_74 . V_208 ,
& V_74 . V_225 ) ;
if ( V_50 ) {
F_55 ( L_56 ) ;
V_50 = - V_16 ;
goto V_272;
}
}
return 0 ;
V_272:
F_76 ( V_74 . V_51 ) ;
V_269:
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_246 ( V_7 -> V_143 ) ;
}
V_268:
F_92 ( & V_74 . V_208 ) ;
return V_50 ;
}
static int F_103 ( struct V_256 * V_277 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
F_92 ( & V_74 . V_208 ) ;
F_76 ( V_74 . V_51 ) ;
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_77 ] ;
F_90 ( V_9 -> V_30 ) ;
F_91 ( V_7 -> V_143 ) ;
F_76 ( V_74 . V_73 [ V_77 ] ) ;
}
return 0 ;
}
static int F_104 ( struct V_277 * V_73 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_105 ( & V_9 -> V_156 ) )
continue;
F_106 ( & V_9 -> V_230 ) ;
if ( V_7 -> V_56 == V_64 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_7 -> V_56 == V_65 ||
V_49 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_107 ( & V_9 -> V_230 ) ;
}
return 0 ;
}
static int F_108 ( struct V_277 * V_73 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_220 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_105 ( & V_9 -> V_156 ) )
continue;
F_106 ( & V_9 -> V_230 ) ;
if ( V_7 -> V_56 == V_64 ) {
F_25 ( 1 ) ;
F_24 ( 1 ) ;
}
if ( V_7 -> V_56 == V_65 ||
V_49 == 2 ) {
F_28 ( 1 ) ;
F_27 ( 1 ) ;
}
F_107 ( & V_9 -> V_230 ) ;
}
return 0 ;
}
