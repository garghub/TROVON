static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_9 * V_10 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
F_6 ( V_3 , 0 , V_10 -> V_12 . V_12 . V_13 . V_14 ) ;
if ( F_7 ( V_3 , 0 ) > F_8 ( V_3 , 0 ) )
return - V_15 ;
V_5 -> V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
if ( V_3 -> V_8 -> type != V_17 ) {
unsigned long V_18 = F_9 ( V_3 , 0 ) ;
if ( ! F_10 ( V_18 + V_10 -> V_19 ) ||
! F_10 ( V_18 + V_10 -> V_20 ) ||
! F_10 ( V_18 + V_10 -> V_21 ) ||
! F_10 ( V_18 + V_10 -> V_22 ) ) {
F_11 ( L_1 ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_12 ( struct V_8 * V_23 ,
unsigned int * V_24 , unsigned int * V_25 ,
unsigned int V_26 [] , struct V_27 * V_28 [] )
{
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
unsigned V_29 = V_10 -> V_12 . V_12 . V_13 . V_14 ;
if ( * V_25 ) {
if ( V_26 [ 0 ] < V_29 )
return - V_15 ;
V_29 = V_26 [ 0 ] ;
}
if ( V_23 -> V_30 + * V_24 < 3 )
* V_24 = 3 - V_23 -> V_30 ;
* V_25 = 1 ;
V_26 [ 0 ] = V_29 ;
F_13 ( V_7 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_1 * V_31 = F_1 ( V_5 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_9 * V_10 ;
unsigned long V_32 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
F_15 ( & V_10 -> V_33 , V_32 ) ;
F_16 ( & V_31 -> V_34 , & V_10 -> V_35 ) ;
F_17 ( & V_10 -> V_33 , V_32 ) ;
}
static int F_18 ( struct V_8 * V_23 , unsigned int V_36 )
{
struct V_37 * V_38 =
V_39 -> V_40 ;
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_41 * V_42 = & V_7 -> V_43 ;
struct V_1 * V_31 , * V_44 ;
unsigned long V_18 , V_32 ;
int V_45 ;
F_15 ( & V_10 -> V_33 , V_32 ) ;
V_7 -> V_46 = 0 ;
if ( V_38 -> V_47 ) {
V_45 = V_38 -> V_47 ( V_7 -> V_43 . V_48 .
V_49 , V_7 -> V_43 . V_48 . V_50 ) ;
if ( V_45 < 0 ) {
F_11 ( L_2 ) ;
goto V_51;
}
}
V_45 = F_19 ( V_42 , V_7 -> V_52 + 2 ) ;
if ( V_45 < 0 )
goto V_51;
V_49 = V_45 ;
F_20 ( V_7 , V_45 ) ;
V_10 -> V_53 = V_10 -> V_54 =
F_21 ( V_10 -> V_35 . V_55 ,
struct V_1 , V_34 ) ;
F_22 ( & V_10 -> V_54 -> V_34 ) ;
F_17 ( & V_10 -> V_33 , V_32 ) ;
V_18 = F_9 ( & V_10 -> V_54 -> V_3 . V_56 , 0 ) ;
V_10 -> V_57 ( ( V_18 + V_10 -> V_19 ) ,
( V_18 + V_10 -> V_20 ) ,
( V_18 + V_10 -> V_21 ) ,
( V_18 + V_10 -> V_22 ) ) ;
V_58 [ V_11 ] [ V_7 -> V_52 ] = 1 ;
if ( V_59 == V_7 -> V_52 ) {
F_23 () ;
F_24 ( 1 ) ;
F_25 ( 1 ) ;
if ( V_38 -> V_60 [ V_59 ] . V_61 )
F_26 ( 1 ) ;
}
if ( V_62 == V_7 -> V_52 || V_49 == 2 ) {
F_27 () ;
F_28 ( 1 ) ;
F_29 ( 1 ) ;
if ( V_38 -> V_60 [ V_62 ] . V_61 )
F_30 ( 1 ) ;
}
return 0 ;
V_51:
F_31 (buf, tmp, &common->dma_queue, list) {
F_22 ( & V_31 -> V_34 ) ;
F_32 ( & V_31 -> V_3 . V_56 , V_63 ) ;
}
F_17 ( & V_10 -> V_33 , V_32 ) ;
return V_45 ;
}
static void F_33 ( struct V_8 * V_23 )
{
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 ;
unsigned long V_32 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_59 == V_7 -> V_52 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_62 == V_7 -> V_52 || V_49 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_15 ( & V_10 -> V_33 , V_32 ) ;
if ( V_10 -> V_54 == V_10 -> V_53 ) {
F_32 ( & V_10 -> V_54 -> V_3 . V_56 ,
V_64 ) ;
} else {
if ( V_10 -> V_54 )
F_32 ( & V_10 -> V_54 -> V_3 . V_56 ,
V_64 ) ;
if ( V_10 -> V_53 )
F_32 ( & V_10 -> V_53 -> V_3 . V_56 ,
V_64 ) ;
}
while ( ! F_34 ( & V_10 -> V_35 ) ) {
V_10 -> V_53 = F_21 ( V_10 -> V_35 . V_55 ,
struct V_1 , V_34 ) ;
F_22 ( & V_10 -> V_53 -> V_34 ) ;
F_32 ( & V_10 -> V_53 -> V_3 . V_56 ,
V_64 ) ;
}
F_17 ( & V_10 -> V_33 , V_32 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
unsigned long V_18 ;
F_36 ( & V_10 -> V_33 ) ;
V_10 -> V_53 = F_21 ( V_10 -> V_35 . V_55 ,
struct V_1 , V_34 ) ;
F_22 ( & V_10 -> V_53 -> V_34 ) ;
F_37 ( & V_10 -> V_33 ) ;
V_18 = F_9 ( & V_10 -> V_53 -> V_3 . V_56 , 0 ) ;
V_10 -> V_57 ( V_18 + V_10 -> V_19 ,
V_18 + V_10 -> V_20 ,
V_18 + V_10 -> V_21 ,
V_18 + V_10 -> V_22 ) ;
}
static void F_38 ( int V_65 , struct V_9 * V_10 )
{
if ( 0 == V_65 ) {
if ( V_10 -> V_54 == V_10 -> V_53 )
return;
V_10 -> V_54 -> V_3 . V_56 . V_66 = F_39 () ;
F_32 ( & V_10 -> V_54 -> V_3 . V_56 ,
V_67 ) ;
V_10 -> V_54 = V_10 -> V_53 ;
} else if ( 1 == V_65 ) {
F_36 ( & V_10 -> V_33 ) ;
if ( F_34 ( & V_10 -> V_35 )
|| ( V_10 -> V_54 != V_10 -> V_53 ) ) {
F_37 ( & V_10 -> V_33 ) ;
return;
}
F_37 ( & V_10 -> V_33 ) ;
F_35 ( V_10 ) ;
}
}
static T_1 F_40 ( int V_68 , void * V_69 )
{
struct V_70 * V_71 = & V_72 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_65 = - 1 , V_73 ;
int V_52 ;
V_52 = * ( int * ) ( V_69 ) ;
if ( ! F_41 ( V_52 + 2 ) )
return V_74 ;
V_7 = V_71 -> V_71 [ V_52 ] ;
for ( V_73 = 0 ; V_73 < V_75 ; V_73 ++ ) {
V_10 = & V_7 -> V_10 [ V_73 ] ;
if ( 1 == V_7 -> V_43 . V_48 . V_76 ) {
F_36 ( & V_10 -> V_33 ) ;
if ( F_34 ( & V_10 -> V_35 ) ) {
F_37 ( & V_10 -> V_33 ) ;
continue;
}
F_37 ( & V_10 -> V_33 ) ;
if ( ! V_58 [ V_73 ] [ V_52 ] ) {
V_10 -> V_54 -> V_3 . V_56 . V_66 =
F_39 () ;
F_32 ( & V_10 -> V_54 -> V_3 . V_56 ,
V_67 ) ;
V_10 -> V_54 = V_10 -> V_53 ;
}
V_58 [ V_73 ] [ V_52 ] = 0 ;
F_35 ( V_10 ) ;
} else {
if ( V_58 [ V_73 ] [ V_52 ] ) {
V_58 [ V_73 ] [ V_52 ] = 0 ;
continue;
}
if ( 0 == V_73 ) {
V_7 -> V_46 ^= 1 ;
V_65 = F_42 ( V_7 -> V_52 + 2 ) ;
if ( V_65 != V_7 -> V_46 ) {
if ( 0 == V_65 )
V_7 -> V_46 = V_65 ;
return V_77 ;
}
}
F_38 ( V_65 , V_10 ) ;
}
}
return V_77 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_78 * V_79 = & V_7 -> V_80 ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_81 * V_48 = & V_43 -> V_48 ;
const struct V_81 * V_82 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_83 ; V_73 ++ ) {
V_82 = & V_84 [ V_73 ] ;
if ( V_82 -> V_50 == 0 ) {
F_44 ( 2 , V_85 , L_3 ) ;
if ( V_82 -> V_86 & V_79 -> V_86 ) {
memcpy ( V_48 , V_82 , sizeof( * V_82 ) ) ;
break;
}
}
}
if ( V_73 == V_83 ) {
F_44 ( 1 , V_85 , L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_78 * V_79 = & V_7 -> V_80 ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_81 * V_48 = & V_43 -> V_48 ;
if ( ! V_79 -> V_86 && ! V_79 -> V_87 . V_88 . V_89 )
return - V_15 ;
if ( V_79 -> V_86 ) {
if ( F_43 ( V_7 ) )
return - V_15 ;
}
V_10 -> V_12 . V_12 . V_13 . V_90 = V_91 ;
V_10 -> V_12 . V_12 . V_13 . V_92 = V_48 -> V_92 ;
V_10 -> V_12 . V_12 . V_13 . V_89 = V_48 -> V_89 ;
F_44 ( 1 , V_85 , L_5 ,
V_10 -> V_12 . V_12 . V_13 . V_92 , V_10 -> V_12 . V_12 . V_13 . V_89 ) ;
V_10 -> V_89 = V_48 -> V_89 ;
V_10 -> V_92 = V_48 -> V_92 ;
V_10 -> V_12 . V_12 . V_13 . V_14 = V_10 -> V_89 * V_10 -> V_92 * 2 ;
if ( V_79 -> V_86 )
V_10 -> V_12 . V_12 . V_13 . V_93 = V_94 ;
else
V_10 -> V_12 . V_12 . V_13 . V_93 = V_95 ;
if ( V_7 -> V_43 . V_48 . V_76 )
V_10 -> V_12 . V_12 . V_13 . V_16 = V_96 ;
else
V_10 -> V_12 . V_12 . V_13 . V_16 = V_97 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_41 * V_43 = & V_7 -> V_43 ;
enum V_98 V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
struct V_78 * V_79 = & V_7 -> V_80 ;
unsigned int V_99 , V_14 ;
if ( V_100 == V_10 -> V_12 . V_12 . V_13 . V_16 ) {
if ( V_7 -> V_43 . V_48 . V_76 )
V_79 -> V_101 = V_96 ;
else
V_79 -> V_101 = V_97 ;
} else {
V_79 -> V_101 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
}
V_14 = V_10 -> V_12 . V_12 . V_13 . V_14 ;
V_99 = V_10 -> V_12 . V_12 . V_13 . V_102 ;
if ( ( V_96 == V_79 -> V_101 ) ||
( V_97 == V_79 -> V_101 ) ) {
V_10 -> V_19 = 0 ;
V_10 -> V_20 = V_99 ;
V_10 -> V_21 = V_14 / 2 ;
V_10 -> V_22 = V_14 / 2 + V_99 ;
} else if ( V_103 == V_79 -> V_101 ) {
V_10 -> V_19 = 0 ;
V_10 -> V_20 = V_14 / 4 ;
V_10 -> V_21 = V_14 / 2 ;
V_10 -> V_22 = V_10 -> V_21 + V_14 / 4 ;
} else if ( V_104 == V_79 -> V_101 ) {
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_14 / 4 ;
V_10 -> V_22 = V_14 / 2 ;
V_10 -> V_21 = V_10 -> V_22 + V_14 / 4 ;
}
if ( ( V_96 == V_79 -> V_101 ) ||
( V_97 == V_79 -> V_101 ) ) {
V_43 -> V_105 . V_106 = 1 ;
} else {
V_43 -> V_105 . V_106 = 0 ;
}
if ( V_7 -> V_43 . V_48 . V_76 == 1 ) {
V_43 -> V_105 . V_99 =
V_10 -> V_12 . V_12 . V_13 . V_102 ;
} else {
if ( ( V_16 == V_100 ) ||
( V_16 == V_97 ) )
V_43 -> V_105 . V_99 =
V_10 -> V_12 . V_12 . V_13 . V_102 * 2 ;
else
V_43 -> V_105 . V_99 =
V_10 -> V_12 . V_12 . V_13 . V_102 ;
}
V_7 -> V_43 . V_105 . V_86 = V_7 -> V_43 . V_48 . V_86 ;
}
static void F_20 ( struct V_6 * V_7 , int V_107 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_62 == V_7 -> V_52 ) {
V_10 -> V_57 = V_108 ;
} else {
if ( 2 == V_107 )
V_10 -> V_57 = V_109 ;
else
V_10 -> V_57 = V_110 ;
}
}
static int F_46 ( struct V_111 * V_111 , void * V_112 ,
struct V_113 * V_114 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
V_114 -> V_115 = V_116 | V_117 ;
V_114 -> V_118 = V_114 -> V_115 | V_119 ;
F_47 ( V_114 -> V_120 , V_121 , sizeof( V_114 -> V_120 ) ) ;
snprintf ( V_114 -> V_122 , sizeof( V_114 -> V_122 ) , L_6 ,
F_48 ( V_39 ) ) ;
F_47 ( V_114 -> V_123 , V_82 -> V_124 , sizeof( V_114 -> V_123 ) ) ;
return 0 ;
}
static int F_49 ( struct V_111 * V_111 , void * V_112 ,
struct V_125 * V_12 )
{
if ( V_12 -> V_126 != 0 )
return - V_15 ;
V_12 -> type = V_127 ;
strcpy ( V_12 -> V_128 , L_7 ) ;
V_12 -> V_90 = V_91 ;
V_12 -> V_32 = 0 ;
return 0 ;
}
static int F_50 ( struct V_111 * V_111 , void * V_112 ,
struct V_129 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_10 -> V_12 . type != V_12 -> type )
return - V_15 ;
if ( F_45 ( V_7 ) )
return - V_15 ;
* V_12 = V_10 -> V_12 ;
return 0 ;
}
static int F_53 ( struct V_111 * V_111 , void * V_112 ,
struct V_129 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_132 * V_133 = & V_12 -> V_12 . V_13 ;
if ( V_133 -> V_90 != V_91 )
V_133 -> V_90 = V_10 -> V_12 . V_12 . V_13 . V_90 ;
if ( F_45 ( V_7 ) )
return - V_15 ;
V_133 -> V_93 = V_10 -> V_12 . V_12 . V_13 . V_93 ;
V_133 -> V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
V_133 -> V_102 = V_10 -> V_12 . V_12 . V_13 . V_92 ;
V_133 -> V_92 = V_10 -> V_12 . V_12 . V_13 . V_92 ;
V_133 -> V_89 = V_10 -> V_12 . V_12 . V_13 . V_89 ;
V_133 -> V_14 = V_133 -> V_102 * V_133 -> V_89 * 2 ;
return 0 ;
}
static int F_54 ( struct V_111 * V_111 , void * V_112 ,
struct V_129 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_132 * V_133 = & V_12 -> V_12 . V_13 ;
int V_45 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
V_45 = F_53 ( V_111 , V_112 , V_12 ) ;
if ( V_45 )
return V_45 ;
V_10 -> V_12 . V_12 . V_13 = * V_133 ;
V_10 -> V_12 = * V_12 ;
return 0 ;
}
static int F_56 ( struct V_111 * V_111 , void * V_112 , T_2 V_136 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_45 ;
if ( ! V_82 -> V_60 [ V_7 -> V_52 ] . V_141 )
return - V_142 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_118 != V_144 )
return - V_142 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
if ( ! ( V_136 & V_145 ) )
return - V_15 ;
V_7 -> V_80 . V_86 = V_136 ;
memset ( & V_7 -> V_80 . V_87 , 0 , sizeof( V_7 -> V_80 . V_87 ) ) ;
if ( F_45 ( V_7 ) )
return - V_15 ;
V_10 -> V_12 . V_12 . V_13 . V_102 = V_10 -> V_12 . V_12 . V_13 . V_92 ;
V_45 = F_57 ( & V_72 . V_146 , 1 , V_80 ,
V_147 , V_136 ) ;
if ( V_45 < 0 ) {
F_11 ( L_8 ) ;
return V_45 ;
}
V_45 = F_57 ( & V_72 . V_146 , 1 , V_80 ,
V_148 , V_136 ) ;
if ( V_45 < 0 )
F_11 ( L_9 ) ;
return V_45 ;
}
static int F_58 ( struct V_111 * V_111 , void * V_112 , T_2 * V_149 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
if ( ! V_82 -> V_60 [ V_7 -> V_52 ] . V_141 )
return - V_142 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_118 != V_144 )
return - V_142 ;
* V_149 = V_7 -> V_80 . V_86 ;
return 0 ;
}
static int F_59 ( struct V_111 * V_111 , void * V_150 ,
struct V_139 * V_140 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
if ( V_140 -> V_126 >= V_138 -> V_151 ) {
F_44 ( 1 , V_85 , L_10 ) ;
return - V_15 ;
}
* V_140 = V_138 -> V_141 [ V_140 -> V_126 ] . V_140 ;
return 0 ;
}
static int
F_60 ( struct V_37 * V_152 ,
struct V_137 * V_138 , int V_126 )
{
struct V_153 * V_154 ;
const char * V_155 ;
int V_73 ;
F_44 ( 2 , V_85 , L_11 ) ;
if ( ! V_138 -> V_141 )
return - 1 ;
V_155 = V_138 -> V_141 [ V_126 ] . V_155 ;
if ( ! V_155 )
return - 1 ;
for ( V_73 = 0 ; V_73 < V_152 -> V_156 ; V_73 ++ ) {
V_154 = & V_152 -> V_157 [ V_73 ] ;
if ( ! strcmp ( V_154 -> V_158 , V_155 ) )
return V_73 ;
}
return - 1 ;
}
static int F_61 ( struct V_37 * V_152 ,
struct V_6 * V_7 , int V_126 )
{
struct V_137 * V_138 =
& V_152 -> V_60 [ V_7 -> V_52 ] ;
struct V_159 * V_160 = NULL ;
T_3 V_161 = 0 , V_140 = 0 ;
int V_162 ;
int V_45 ;
V_162 = F_60 ( V_152 , V_138 , V_126 ) ;
if ( V_162 >= 0 )
V_160 = V_72 . V_160 [ V_162 ] ;
if ( V_160 ) {
V_161 = V_138 -> V_141 [ V_126 ] . V_163 ;
V_140 = V_138 -> V_141 [ V_126 ] . V_164 ;
V_45 = F_62 ( V_160 , V_80 , V_165 , V_161 , V_140 , 0 ) ;
if ( V_45 < 0 && V_45 != - V_166 ) {
F_11 ( L_12 ) ;
return V_45 ;
}
}
V_7 -> V_143 = V_126 ;
V_7 -> V_160 = V_160 ;
if ( V_138 -> V_141 )
V_7 -> V_167 . V_168 = V_138 -> V_141 [ V_126 ] . V_140 . V_149 ;
return 0 ;
}
static int F_63 ( struct V_111 * V_111 , void * V_112 , unsigned int V_73 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
if ( V_73 >= V_138 -> V_151 )
return - V_15 ;
return F_61 ( V_82 , V_7 , V_73 ) ;
}
static int F_64 ( struct V_111 * V_111 , void * V_112 , unsigned int * V_73 )
{
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
* V_73 = V_7 -> V_143 ;
return 0 ;
}
static int
F_65 ( struct V_111 * V_111 , void * V_112 ,
struct V_169 * V_170 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_45 ;
if ( ! V_82 -> V_60 [ V_7 -> V_52 ] . V_141 )
return - V_142 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_118 != V_171 )
return - V_142 ;
V_170 -> V_172 = 0 ;
V_45 = F_62 ( V_7 -> V_160 , V_172 , V_173 , V_170 ) ;
if ( V_45 == - V_166 || V_45 == - V_174 )
return - V_15 ;
return V_45 ;
}
static int F_66 ( struct V_111 * V_111 , void * V_112 ,
struct V_175 * V_170 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_81 * V_48 = & V_43 -> V_48 ;
struct V_78 * V_79 = & V_7 -> V_80 ;
struct V_176 * V_88 = & V_79 -> V_87 . V_88 ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_45 ;
if ( ! V_82 -> V_60 [ V_7 -> V_52 ] . V_141 )
return - V_142 ;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_118 != V_171 )
return - V_142 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
if ( V_170 -> type != V_177 ) {
F_44 ( 2 , V_85 , L_13 ) ;
return - V_15 ;
}
V_45 = F_62 ( V_7 -> V_160 , V_80 , V_178 , V_170 ) ;
if ( V_45 == - V_166 || V_45 == - V_174 )
V_45 = 0 ;
if ( V_45 < 0 ) {
F_44 ( 2 , V_85 , L_14 ) ;
return V_45 ;
}
if ( ! ( V_170 -> V_88 . V_92 && V_170 -> V_88 . V_89 &&
( V_170 -> V_88 . V_179 ||
V_170 -> V_88 . V_180 ||
V_170 -> V_88 . V_181 ) &&
V_170 -> V_88 . V_182 &&
( V_170 -> V_88 . V_183 ||
V_170 -> V_88 . V_184 ) ) ) {
F_44 ( 2 , V_85 , L_15 ) ;
return - V_15 ;
}
V_79 -> V_87 = * V_170 ;
V_48 -> V_185 = F_67 ( V_88 ) - 8 ;
V_48 -> V_186 = V_88 -> V_92 ;
V_48 -> V_187 = 1 ;
V_48 -> V_188 = V_88 -> V_184 + V_88 -> V_183 + 1 ;
V_48 -> V_189 = F_68 ( V_88 ) ;
if ( V_88 -> V_190 ) {
if ( V_88 -> V_191 || V_88 -> V_192 || V_88 -> V_193 ) {
V_48 -> V_194 = V_48 -> V_189 / 2 -
( V_88 -> V_182 - 1 ) ;
V_48 -> V_195 = V_48 -> V_189 / 2 + 1 ;
V_48 -> V_196 = V_48 -> V_195 + V_88 -> V_193 +
V_88 -> V_191 + 1 ;
V_48 -> V_197 = V_48 -> V_189 -
( V_88 -> V_192 - 1 ) ;
} else {
F_44 ( 2 , V_85 , L_16 ) ;
return - V_15 ;
}
} else {
V_48 -> V_194 = V_48 -> V_189 - ( V_88 -> V_182 - 1 ) ;
}
strncpy ( V_48 -> V_158 , L_17 ,
V_198 ) ;
V_48 -> V_92 = V_88 -> V_92 ;
V_48 -> V_89 = V_88 -> V_89 ;
V_48 -> V_76 = V_88 -> V_190 ? 0 : 1 ;
V_48 -> V_49 = 0 ;
V_48 -> V_199 = 0 ;
V_48 -> V_200 = 0 ;
V_48 -> V_50 = 1 ;
V_48 -> V_86 = 0 ;
V_79 -> V_86 = 0 ;
return 0 ;
}
static int F_69 ( struct V_111 * V_111 , void * V_112 ,
struct V_175 * V_170 )
{
struct V_37 * V_82 = V_39 -> V_40 ;
struct V_130 * V_131 = F_51 ( V_111 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_78 * V_79 = & V_7 -> V_80 ;
struct V_139 V_140 ;
if ( ! V_82 -> V_60 [ V_7 -> V_52 ] . V_141 )
goto error;
V_138 = & V_82 -> V_60 [ V_7 -> V_52 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_118 != V_171 )
goto error;
* V_170 = V_79 -> V_87 ;
return 0 ;
error:
return - V_142 ;
}
static int F_70 ( struct V_111 * V_201 , void * V_112 )
{
F_71 ( & V_72 . V_146 , 0 , V_202 , V_203 ) ;
return 0 ;
}
static int F_72 ( void )
{
int V_204 ;
int V_51 , V_73 , V_205 ;
for ( V_73 = 0 ; V_73 < V_206 ; V_73 ++ ) {
V_72 . V_71 [ V_73 ] =
F_73 ( sizeof( struct V_6 ) , V_207 ) ;
if ( ! V_72 . V_71 [ V_73 ] ) {
V_204 = V_73 ;
V_51 = - V_208 ;
goto V_209;
}
}
return 0 ;
V_209:
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ )
F_74 ( V_72 . V_71 [ V_205 ] ) ;
return V_51 ;
}
static int F_75 ( struct V_210 * V_211 ,
struct V_159 * V_212 ,
struct V_213 * V_214 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_72 . V_82 -> V_156 ; V_73 ++ )
if ( ! strcmp ( V_72 . V_82 -> V_157 [ V_73 ] . V_158 ,
V_212 -> V_158 ) ) {
V_72 . V_160 [ V_73 ] = V_212 ;
V_72 . V_160 [ V_73 ] -> V_215 = 1 << V_73 ;
return 0 ;
}
return - V_15 ;
}
static int F_76 ( void )
{
struct V_9 * V_10 ;
struct V_130 * V_131 ;
struct V_6 * V_7 ;
struct V_8 * V_216 ;
int V_205 , V_51 , V_217 ;
for ( V_205 = 0 ; V_205 < V_206 ; V_205 ++ ) {
V_7 = V_72 . V_71 [ V_205 ] ;
for ( V_217 = 0 ; V_217 < V_75 ; V_217 ++ ) {
V_10 = & V_7 -> V_10 [ V_217 ] ;
F_77 ( & V_10 -> V_33 ) ;
F_78 ( & V_10 -> V_218 ) ;
V_10 -> V_57 = NULL ;
V_10 -> V_19 = 0 ;
V_10 -> V_20 = 0 ;
V_10 -> V_21 = 0 ;
V_10 -> V_22 = 0 ;
V_10 -> V_54 = NULL ;
V_10 -> V_53 = NULL ;
memset ( & V_10 -> V_12 , 0 , sizeof( V_10 -> V_12 ) ) ;
}
V_7 -> V_219 = 0 ;
if ( V_72 . V_82 -> V_156 )
V_7 -> V_160 = V_72 . V_160 [ 0 ] ;
V_7 -> V_52 = V_205 ;
memset ( & V_7 -> V_43 , 0 , sizeof( V_7 -> V_43 ) ) ;
V_7 -> V_10 [ V_11 ] . V_12 . type =
V_127 ;
V_51 = F_61 ( V_72 . V_82 , V_7 , 0 ) ;
if ( V_51 )
goto V_220;
V_7 -> V_80 . V_86 = V_221 ;
memset ( & V_7 -> V_80 . V_87 , 0 , sizeof( V_7 -> V_80 . V_87 ) ) ;
F_45 ( V_7 ) ;
V_216 = & V_10 -> V_134 ;
V_216 -> type = V_127 ;
V_216 -> V_222 = V_223 | V_224 | V_225 ;
V_216 -> V_226 = V_7 ;
V_216 -> V_227 = & V_228 ;
V_216 -> V_229 = & V_230 ;
V_216 -> V_231 = sizeof( struct V_1 ) ;
V_216 -> V_232 = V_233 ;
V_216 -> V_234 = 1 ;
V_216 -> V_218 = & V_10 -> V_218 ;
V_216 -> V_71 = V_39 ;
V_51 = F_79 ( V_216 ) ;
if ( V_51 ) {
F_11 ( L_18 ) ;
goto V_220;
}
F_80 ( & V_10 -> V_35 ) ;
F_44 ( 1 , V_85 , L_19 ,
V_7 , & V_7 -> V_167 ) ;
V_131 = & V_7 -> V_167 ;
F_47 ( V_131 -> V_158 , V_121 , sizeof( V_131 -> V_158 ) ) ;
V_131 -> V_235 = V_236 ;
V_131 -> V_237 = & V_238 ;
V_131 -> V_239 = & V_240 ;
V_131 -> V_146 = & V_72 . V_146 ;
V_131 -> V_241 = V_242 ;
V_131 -> V_243 = V_216 ;
V_131 -> V_218 = & V_10 -> V_218 ;
F_81 ( & V_7 -> V_167 , V_7 ) ;
V_51 = F_82 ( V_131 , V_244 ,
( V_205 ? 3 : 2 ) ) ;
if ( V_51 < 0 )
goto V_220;
}
return 0 ;
V_220:
for ( V_217 = 0 ; V_217 < V_205 ; V_217 ++ ) {
V_7 = V_72 . V_71 [ V_217 ] ;
V_10 = & V_7 -> V_10 [ V_217 ] ;
F_83 ( & V_7 -> V_167 ) ;
}
return V_51 ;
}
static int F_84 ( struct V_210 * V_211 )
{
return F_76 () ;
}
static T_4 int F_85 ( struct V_245 * V_246 )
{
struct V_153 * V_247 ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
int V_156 ;
int V_252 = 0 ;
int V_73 , V_51 ;
if ( ! V_246 -> V_71 . V_40 ) {
F_86 ( & V_246 -> V_71 , L_20 ) ;
return - V_15 ;
}
if ( ! V_246 -> V_71 . V_40 ) {
F_86 ( & V_246 -> V_71 , L_20 ) ;
return - V_15 ;
}
V_39 = & V_246 -> V_71 ;
V_51 = F_72 () ;
if ( V_51 ) {
F_87 ( V_39 -> V_120 , L_21 ) ;
return V_51 ;
}
V_51 = F_88 ( V_39 , & V_72 . V_146 ) ;
if ( V_51 ) {
F_87 ( V_39 -> V_120 , L_22 ) ;
return V_51 ;
}
while ( ( V_251 = F_89 ( V_246 , V_253 , V_252 ) ) ) {
V_51 = F_90 ( & V_246 -> V_71 , V_251 -> V_254 , F_40 ,
V_255 , V_121 ,
( void * ) ( & V_72 . V_71 [ V_252 ] ->
V_52 ) ) ;
if ( V_51 ) {
V_51 = - V_15 ;
F_11 ( L_23 ) ;
goto V_256;
}
V_252 ++ ;
}
V_72 . V_82 = V_246 -> V_71 . V_40 ;
V_156 = V_72 . V_82 -> V_156 ;
V_247 = V_72 . V_82 -> V_157 ;
V_72 . V_160 = F_91 ( V_156 , sizeof( * V_72 . V_160 ) , V_207 ) ;
if ( ! V_72 . V_160 ) {
V_51 = - V_208 ;
goto V_256;
}
if ( ! V_72 . V_82 -> V_257 ) {
V_249 = F_92 ( V_72 . V_82 -> V_258 ) ;
for ( V_73 = 0 ; V_73 < V_156 ; V_73 ++ ) {
V_72 . V_160 [ V_73 ] =
F_93 ( & V_72 . V_146 ,
V_249 ,
& V_247 [ V_73 ] .
V_259 ,
NULL ) ;
if ( ! V_72 . V_160 [ V_73 ] ) {
F_11 ( L_24 ) ;
V_51 = - V_174 ;
goto V_260;
}
if ( V_72 . V_160 [ V_73 ] )
V_72 . V_160 [ V_73 ] -> V_215 = 1 << V_73 ;
}
F_76 () ;
} else {
V_72 . V_211 . V_261 = V_72 . V_82 -> V_214 ;
V_72 . V_211 . V_262 = V_72 . V_82 -> V_257 [ 0 ] ;
V_72 . V_211 . V_263 = F_75 ;
V_72 . V_211 . V_264 = F_84 ;
V_51 = F_94 ( & V_72 . V_146 ,
& V_72 . V_211 ) ;
if ( V_51 ) {
F_11 ( L_25 ) ;
V_51 = - V_15 ;
goto V_260;
}
}
return 0 ;
V_260:
F_74 ( V_72 . V_160 ) ;
V_256:
F_95 ( & V_72 . V_146 ) ;
return V_51 ;
}
static int F_96 ( struct V_245 * V_27 )
{
struct V_6 * V_7 ;
int V_73 ;
F_95 ( & V_72 . V_146 ) ;
F_74 ( V_72 . V_160 ) ;
for ( V_73 = 0 ; V_73 < V_206 ; V_73 ++ ) {
V_7 = V_72 . V_71 [ V_73 ] ;
F_83 ( & V_7 -> V_167 ) ;
F_74 ( V_72 . V_71 [ V_73 ] ) ;
}
return 0 ;
}
static int F_97 ( struct V_27 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_206 ; V_73 ++ ) {
V_7 = V_72 . V_71 [ V_73 ] ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( ! F_98 ( & V_10 -> V_134 ) )
continue;
F_99 ( & V_10 -> V_218 ) ;
if ( V_7 -> V_52 == V_59 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_7 -> V_52 == V_62 ||
V_49 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_100 ( & V_10 -> V_218 ) ;
}
return 0 ;
}
static int F_101 ( struct V_27 * V_71 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_206 ; V_73 ++ ) {
V_7 = V_72 . V_71 [ V_73 ] ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( ! F_98 ( & V_10 -> V_134 ) )
continue;
F_99 ( & V_10 -> V_218 ) ;
if ( V_7 -> V_52 == V_59 ) {
F_25 ( 1 ) ;
F_24 ( 1 ) ;
}
if ( V_7 -> V_52 == V_62 ||
V_49 == 2 ) {
F_29 ( 1 ) ;
F_28 ( 1 ) ;
}
F_100 ( & V_10 -> V_218 ) ;
}
return 0 ;
}
