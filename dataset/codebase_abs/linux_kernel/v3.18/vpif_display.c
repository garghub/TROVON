static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_7 * V_8 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_5 ( V_3 , 0 , V_8 -> V_10 . V_10 . V_11 . V_12 ) ;
if ( F_6 ( V_3 , 0 ) > F_7 ( V_3 , 0 ) )
return - V_13 ;
V_3 -> V_14 . V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
if ( V_3 -> V_6 -> type != V_16 ) {
unsigned long V_17 = F_8 ( V_3 , 0 ) ;
if ( ! F_9 ( V_17 + V_8 -> V_18 ) ||
! F_9 ( V_17 + V_8 -> V_19 ) ||
! F_9 ( V_17 + V_8 -> V_20 ) ||
! F_9 ( V_17 + V_8 -> V_21 ) ) {
F_10 ( L_1 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_11 ( struct V_6 * V_22 ,
const struct V_23 * V_10 ,
unsigned int * V_24 , unsigned int * V_25 ,
unsigned int V_26 [] , void * V_27 [] )
{
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_10 && V_10 -> V_10 . V_11 . V_12 < V_8 -> V_10 . V_10 . V_11 . V_12 )
return - V_13 ;
if ( V_22 -> V_28 + * V_24 < 3 )
* V_24 = 3 - V_22 -> V_28 ;
* V_25 = 1 ;
V_26 [ 0 ] = V_10 ? V_10 -> V_10 . V_11 . V_12 : V_8 -> V_10 . V_10 . V_11 . V_12 ;
V_27 [ 0 ] = V_8 -> V_29 ;
F_12 ( V_5 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_7 * V_8 ;
unsigned long V_31 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_14 ( & V_8 -> V_32 , V_31 ) ;
F_15 ( & V_30 -> V_33 , & V_8 -> V_34 ) ;
F_16 ( & V_8 -> V_32 , V_31 ) ;
}
static int F_17 ( struct V_6 * V_22 , unsigned int V_35 )
{
struct V_36 * V_37 =
V_38 -> V_39 ;
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_40 * V_41 = & V_5 -> V_42 ;
struct V_1 * V_30 , * V_43 ;
unsigned long V_17 , V_31 ;
int V_44 ;
F_14 ( & V_8 -> V_32 , V_31 ) ;
V_5 -> V_45 = 0 ;
if ( V_37 -> V_46 ) {
V_44 = V_37 -> V_46 ( V_5 -> V_42 . V_47 .
V_48 , V_5 -> V_42 . V_47 . V_49 ) ;
if ( V_44 < 0 ) {
F_10 ( L_2 ) ;
goto V_50;
}
}
V_44 = F_18 ( V_41 , V_5 -> V_51 + 2 ) ;
if ( V_44 < 0 )
goto V_50;
V_48 = V_44 ;
F_19 ( V_5 , V_44 ) ;
V_8 -> V_52 = V_8 -> V_53 =
F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_53 -> V_33 ) ;
F_16 ( & V_8 -> V_32 , V_31 ) ;
V_17 = F_8 ( & V_8 -> V_53 -> V_3 , 0 ) ;
V_8 -> V_55 ( ( V_17 + V_8 -> V_18 ) ,
( V_17 + V_8 -> V_19 ) ,
( V_17 + V_8 -> V_20 ) ,
( V_17 + V_8 -> V_21 ) ) ;
V_56 [ V_9 ] [ V_5 -> V_51 ] = 1 ;
if ( V_57 == V_5 -> V_51 ) {
F_22 () ;
F_23 ( 1 ) ;
F_24 ( 1 ) ;
if ( V_37 -> V_58 [ V_57 ] . V_59 )
F_25 ( 1 ) ;
}
if ( V_60 == V_5 -> V_51 || V_48 == 2 ) {
F_26 () ;
F_27 ( 1 ) ;
F_28 ( 1 ) ;
if ( V_37 -> V_58 [ V_60 ] . V_59 )
F_29 ( 1 ) ;
}
return 0 ;
V_50:
F_30 (buf, tmp, &common->dma_queue, list) {
F_21 ( & V_30 -> V_33 ) ;
F_31 ( & V_30 -> V_3 , V_61 ) ;
}
F_16 ( & V_8 -> V_32 , V_31 ) ;
return V_44 ;
}
static void F_32 ( struct V_6 * V_22 )
{
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 ;
unsigned long V_31 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_57 == V_5 -> V_51 ) {
F_24 ( 0 ) ;
F_23 ( 0 ) ;
}
if ( V_60 == V_5 -> V_51 || V_48 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_14 ( & V_8 -> V_32 , V_31 ) ;
if ( V_8 -> V_53 == V_8 -> V_52 ) {
F_31 ( & V_8 -> V_53 -> V_3 , V_62 ) ;
} else {
if ( V_8 -> V_53 != NULL )
F_31 ( & V_8 -> V_53 -> V_3 ,
V_62 ) ;
if ( V_8 -> V_52 != NULL )
F_31 ( & V_8 -> V_52 -> V_3 ,
V_62 ) ;
}
while ( ! F_33 ( & V_8 -> V_34 ) ) {
V_8 -> V_52 = F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_52 -> V_33 ) ;
F_31 ( & V_8 -> V_52 -> V_3 , V_62 ) ;
}
F_16 ( & V_8 -> V_32 , V_31 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
unsigned long V_17 = 0 ;
F_35 ( & V_8 -> V_32 ) ;
V_8 -> V_52 = F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_52 -> V_33 ) ;
F_36 ( & V_8 -> V_32 ) ;
V_17 = F_8 ( & V_8 -> V_52 -> V_3 , 0 ) ;
V_8 -> V_55 ( V_17 + V_8 -> V_18 ,
V_17 + V_8 -> V_19 ,
V_17 + V_8 -> V_20 ,
V_17 + V_8 -> V_21 ) ;
}
static void F_37 ( int V_63 , struct V_7 * V_8 )
{
if ( 0 == V_63 ) {
if ( V_8 -> V_53 == V_8 -> V_52 )
return;
F_38 ( & V_8 -> V_53 -> V_3 . V_14 . V_64 ) ;
F_31 ( & V_8 -> V_53 -> V_3 ,
V_65 ) ;
V_8 -> V_53 = V_8 -> V_52 ;
} else if ( 1 == V_63 ) {
F_35 ( & V_8 -> V_32 ) ;
if ( F_33 ( & V_8 -> V_34 )
|| ( V_8 -> V_53 != V_8 -> V_52 ) ) {
F_36 ( & V_8 -> V_32 ) ;
return;
}
F_36 ( & V_8 -> V_32 ) ;
F_34 ( V_8 ) ;
}
}
static T_1 F_39 ( int V_66 , void * V_67 )
{
struct V_68 * V_69 = & V_70 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_63 = - 1 , V_71 ;
int V_51 = 0 ;
V_51 = * ( int * ) ( V_67 ) ;
if ( ! F_40 ( V_51 + 2 ) )
return V_72 ;
V_5 = V_69 -> V_69 [ V_51 ] ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
V_8 = & V_5 -> V_8 [ V_71 ] ;
if ( 1 == V_5 -> V_42 . V_47 . V_74 ) {
F_35 ( & V_8 -> V_32 ) ;
if ( F_33 ( & V_8 -> V_34 ) ) {
F_36 ( & V_8 -> V_32 ) ;
continue;
}
F_36 ( & V_8 -> V_32 ) ;
if ( ! V_56 [ V_71 ] [ V_51 ] ) {
F_38 ( & V_8 -> V_53 -> V_3 .
V_14 . V_64 ) ;
F_31 ( & V_8 -> V_53 -> V_3 ,
V_65 ) ;
V_8 -> V_53 = V_8 -> V_52 ;
}
V_56 [ V_71 ] [ V_51 ] = 0 ;
F_34 ( V_8 ) ;
} else {
if ( V_56 [ V_71 ] [ V_51 ] ) {
V_56 [ V_71 ] [ V_51 ] = 0 ;
continue;
}
if ( 0 == V_71 ) {
V_5 -> V_45 ^= 1 ;
V_63 = F_41 ( V_5 -> V_51 + 2 ) ;
if ( V_63 != V_5 -> V_45 ) {
if ( 0 == V_63 )
V_5 -> V_45 = V_63 ;
return V_75 ;
}
}
F_37 ( V_63 , V_8 ) ;
}
}
return V_75 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_79 * V_47 = & V_42 -> V_47 ;
const struct V_79 * V_80 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_81 ; V_71 ++ ) {
V_80 = & V_82 [ V_71 ] ;
if ( V_80 -> V_49 == 0 ) {
F_43 ( 2 , V_83 , L_3 ) ;
if ( V_80 -> V_84 & V_77 -> V_84 ) {
memcpy ( V_47 , V_80 , sizeof( * V_80 ) ) ;
break;
}
}
}
if ( V_71 == V_81 ) {
F_43 ( 1 , V_83 , L_4 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_79 * V_47 = & V_42 -> V_47 ;
if ( ! V_77 -> V_84 && ! V_77 -> V_85 . V_86 . V_87 )
return - V_13 ;
if ( V_77 -> V_84 ) {
if ( F_42 ( V_5 ) )
return - V_13 ;
}
V_8 -> V_10 . V_10 . V_11 . V_88 = V_89 ;
V_8 -> V_10 . V_10 . V_11 . V_90 = V_47 -> V_90 ;
V_8 -> V_10 . V_10 . V_11 . V_87 = V_47 -> V_87 ;
F_43 ( 1 , V_83 , L_5 ,
V_8 -> V_10 . V_10 . V_11 . V_90 , V_8 -> V_10 . V_10 . V_11 . V_87 ) ;
V_8 -> V_87 = V_47 -> V_87 ;
V_8 -> V_90 = V_47 -> V_90 ;
V_8 -> V_10 . V_10 . V_11 . V_12 = V_8 -> V_87 * V_8 -> V_90 * 2 ;
if ( V_77 -> V_84 )
V_8 -> V_10 . V_10 . V_11 . V_91 = V_92 ;
else
V_8 -> V_10 . V_10 . V_11 . V_91 = V_93 ;
if ( V_5 -> V_42 . V_47 . V_74 )
V_8 -> V_10 . V_10 . V_11 . V_15 = V_94 ;
else
V_8 -> V_10 . V_10 . V_11 . V_15 = V_95 ;
return 0 ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_40 * V_42 = & V_5 -> V_42 ;
enum V_96 V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
struct V_76 * V_77 = & V_5 -> V_78 ;
unsigned int V_97 , V_12 ;
if ( V_98 == V_8 -> V_10 . V_10 . V_11 . V_15 ) {
if ( V_5 -> V_42 . V_47 . V_74 )
V_77 -> V_99 = V_94 ;
else
V_77 -> V_99 = V_95 ;
} else {
V_77 -> V_99 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
}
V_12 = V_8 -> V_10 . V_10 . V_11 . V_12 ;
V_97 = V_8 -> V_10 . V_10 . V_11 . V_100 ;
if ( ( V_94 == V_77 -> V_99 ) ||
( V_95 == V_77 -> V_99 ) ) {
V_8 -> V_18 = 0 ;
V_8 -> V_19 = V_97 ;
V_8 -> V_20 = V_12 / 2 ;
V_8 -> V_21 = V_12 / 2 + V_97 ;
} else if ( V_101 == V_77 -> V_99 ) {
V_8 -> V_18 = 0 ;
V_8 -> V_19 = V_12 / 4 ;
V_8 -> V_20 = V_12 / 2 ;
V_8 -> V_21 = V_8 -> V_20 + V_12 / 4 ;
} else if ( V_102 == V_77 -> V_99 ) {
V_8 -> V_19 = 0 ;
V_8 -> V_18 = V_12 / 4 ;
V_8 -> V_21 = V_12 / 2 ;
V_8 -> V_20 = V_8 -> V_21 + V_12 / 4 ;
}
if ( ( V_94 == V_77 -> V_99 ) ||
( V_95 == V_77 -> V_99 ) ) {
V_42 -> V_103 . V_104 = 1 ;
} else {
V_42 -> V_103 . V_104 = 0 ;
}
if ( V_5 -> V_42 . V_47 . V_74 == 1 ) {
V_42 -> V_103 . V_97 =
V_8 -> V_10 . V_10 . V_11 . V_100 ;
} else {
if ( ( V_15 == V_98 ) ||
( V_15 == V_95 ) )
V_42 -> V_103 . V_97 =
V_8 -> V_10 . V_10 . V_11 . V_100 * 2 ;
else
V_42 -> V_103 . V_97 =
V_8 -> V_10 . V_10 . V_11 . V_100 ;
}
V_5 -> V_42 . V_103 . V_84 = V_5 -> V_42 . V_47 . V_84 ;
}
static void F_19 ( struct V_4 * V_5 , int V_105 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_60 == V_5 -> V_51 ) {
V_8 -> V_55 = V_106 ;
} else {
if ( 2 == V_105 )
V_8 -> V_55 = V_107 ;
else
V_8 -> V_55 = V_108 ;
}
}
static int F_45 ( struct V_109 * V_109 , void * V_110 ,
struct V_111 * V_112 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
V_112 -> V_113 = V_114 | V_115 ;
V_112 -> V_116 = V_112 -> V_113 | V_117 ;
F_46 ( V_112 -> V_118 , V_119 , sizeof( V_112 -> V_118 ) ) ;
snprintf ( V_112 -> V_120 , sizeof( V_112 -> V_120 ) , L_6 ,
F_47 ( V_38 ) ) ;
F_46 ( V_112 -> V_121 , V_80 -> V_122 , sizeof( V_112 -> V_121 ) ) ;
return 0 ;
}
static int F_48 ( struct V_109 * V_109 , void * V_110 ,
struct V_123 * V_10 )
{
if ( V_10 -> V_124 != 0 )
return - V_13 ;
V_10 -> type = V_125 ;
strcpy ( V_10 -> V_126 , L_7 ) ;
V_10 -> V_88 = V_89 ;
V_10 -> V_31 = 0 ;
return 0 ;
}
static int F_49 ( struct V_109 * V_109 , void * V_110 ,
struct V_23 * V_10 )
{
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_8 -> V_10 . type != V_10 -> type )
return - V_13 ;
if ( F_44 ( V_5 ) )
return - V_13 ;
* V_10 = V_8 -> V_10 ;
return 0 ;
}
static int F_52 ( struct V_109 * V_109 , void * V_110 ,
struct V_23 * V_10 )
{
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_129 * V_130 = & V_10 -> V_10 . V_11 ;
if ( V_130 -> V_88 != V_89 )
V_130 -> V_88 = V_8 -> V_10 . V_10 . V_11 . V_88 ;
if ( F_44 ( V_5 ) )
return - V_13 ;
V_130 -> V_91 = V_8 -> V_10 . V_10 . V_11 . V_91 ;
V_130 -> V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
V_130 -> V_100 = V_8 -> V_10 . V_10 . V_11 . V_90 ;
V_130 -> V_90 = V_8 -> V_10 . V_10 . V_11 . V_90 ;
V_130 -> V_87 = V_8 -> V_10 . V_10 . V_11 . V_87 ;
V_130 -> V_12 = V_130 -> V_100 * V_130 -> V_87 * 2 ;
return 0 ;
}
static int F_53 ( struct V_109 * V_109 , void * V_110 ,
struct V_23 * V_10 )
{
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_129 * V_130 = & V_10 -> V_10 . V_11 ;
int V_44 ;
if ( F_54 ( & V_8 -> V_131 ) )
return - V_132 ;
V_44 = F_52 ( V_109 , V_110 , V_10 ) ;
if ( V_44 )
return V_44 ;
V_8 -> V_10 . V_10 . V_11 = * V_130 ;
V_8 -> V_10 = * V_10 ;
return 0 ;
}
static int F_55 ( struct V_109 * V_109 , void * V_110 , T_2 V_133 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_134 * V_135 ;
struct V_136 V_137 ;
int V_44 ;
if ( V_80 -> V_58 [ V_5 -> V_51 ] . V_138 == NULL )
return - V_139 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
V_137 = V_135 -> V_138 [ V_5 -> V_140 ] . V_137 ;
if ( V_137 . V_116 != V_141 )
return - V_139 ;
if ( F_54 ( & V_8 -> V_131 ) )
return - V_132 ;
if ( ! ( V_133 & V_142 ) )
return - V_13 ;
V_5 -> V_78 . V_84 = V_133 ;
memset ( & V_5 -> V_78 . V_85 , 0 , sizeof( V_5 -> V_78 . V_85 ) ) ;
if ( F_44 ( V_5 ) )
return - V_13 ;
V_8 -> V_10 . V_10 . V_11 . V_100 = V_8 -> V_10 . V_10 . V_11 . V_90 ;
V_44 = F_56 ( & V_70 . V_143 , 1 , V_78 ,
V_144 , V_133 ) ;
if ( V_44 < 0 ) {
F_10 ( L_8 ) ;
return V_44 ;
}
V_44 = F_56 ( & V_70 . V_143 , 1 , V_78 ,
V_145 , V_133 ) ;
if ( V_44 < 0 )
F_10 ( L_9 ) ;
return V_44 ;
}
static int F_57 ( struct V_109 * V_109 , void * V_110 , T_2 * V_146 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_134 * V_135 ;
struct V_136 V_137 ;
if ( V_80 -> V_58 [ V_5 -> V_51 ] . V_138 == NULL )
return - V_139 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
V_137 = V_135 -> V_138 [ V_5 -> V_140 ] . V_137 ;
if ( V_137 . V_116 != V_141 )
return - V_139 ;
* V_146 = V_5 -> V_78 . V_84 ;
return 0 ;
}
static int F_58 ( struct V_109 * V_109 , void * V_147 ,
struct V_136 * V_137 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_134 * V_135 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
if ( V_137 -> V_124 >= V_135 -> V_148 ) {
F_43 ( 1 , V_83 , L_10 ) ;
return - V_13 ;
}
* V_137 = V_135 -> V_138 [ V_137 -> V_124 ] . V_137 ;
return 0 ;
}
static int
F_59 ( struct V_36 * V_149 ,
struct V_134 * V_135 , int V_124 )
{
struct V_150 * V_151 ;
const char * V_152 ;
int V_71 ;
F_43 ( 2 , V_83 , L_11 ) ;
if ( V_135 -> V_138 == NULL )
return - 1 ;
V_152 = V_135 -> V_138 [ V_124 ] . V_152 ;
if ( V_152 == NULL )
return - 1 ;
for ( V_71 = 0 ; V_71 < V_149 -> V_153 ; V_71 ++ ) {
V_151 = & V_149 -> V_154 [ V_71 ] ;
if ( ! strcmp ( V_151 -> V_155 , V_152 ) )
return V_71 ;
}
return - 1 ;
}
static int F_60 ( struct V_36 * V_149 ,
struct V_4 * V_5 , int V_124 )
{
struct V_134 * V_135 =
& V_149 -> V_58 [ V_5 -> V_51 ] ;
struct V_156 * V_157 = NULL ;
T_3 V_158 = 0 , V_137 = 0 ;
int V_159 ;
int V_44 ;
V_159 = F_59 ( V_149 , V_135 , V_124 ) ;
if ( V_159 >= 0 )
V_157 = V_70 . V_157 [ V_159 ] ;
if ( V_157 ) {
V_158 = V_135 -> V_138 [ V_124 ] . V_160 ;
V_137 = V_135 -> V_138 [ V_124 ] . V_161 ;
V_44 = F_61 ( V_157 , V_78 , V_162 , V_158 , V_137 , 0 ) ;
if ( V_44 < 0 && V_44 != - V_163 ) {
F_10 ( L_12 ) ;
return V_44 ;
}
}
V_5 -> V_140 = V_124 ;
V_5 -> V_157 = V_157 ;
if ( V_135 -> V_138 != NULL )
V_5 -> V_164 -> V_165 = V_135 -> V_138 [ V_124 ] . V_137 . V_146 ;
return 0 ;
}
static int F_62 ( struct V_109 * V_109 , void * V_110 , unsigned int V_71 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_134 * V_135 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( F_54 ( & V_8 -> V_131 ) )
return - V_132 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
if ( V_71 >= V_135 -> V_148 )
return - V_13 ;
return F_60 ( V_80 , V_5 , V_71 ) ;
}
static int F_63 ( struct V_109 * V_109 , void * V_110 , unsigned int * V_71 )
{
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
* V_71 = V_5 -> V_140 ;
return 0 ;
}
static int
F_64 ( struct V_109 * V_109 , void * V_110 ,
struct V_166 * V_167 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_134 * V_135 ;
struct V_136 V_137 ;
int V_44 ;
if ( V_80 -> V_58 [ V_5 -> V_51 ] . V_138 == NULL )
return - V_139 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
V_137 = V_135 -> V_138 [ V_5 -> V_140 ] . V_137 ;
if ( V_137 . V_116 != V_168 )
return - V_139 ;
V_167 -> V_169 = 0 ;
V_44 = F_61 ( V_5 -> V_157 , V_169 , V_170 , V_167 ) ;
if ( V_44 == - V_163 || V_44 == - V_171 )
return - V_13 ;
return V_44 ;
}
static int F_65 ( struct V_109 * V_109 , void * V_110 ,
struct V_172 * V_167 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_79 * V_47 = & V_42 -> V_47 ;
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_173 * V_86 = & V_77 -> V_85 . V_86 ;
struct V_134 * V_135 ;
struct V_136 V_137 ;
int V_44 ;
if ( V_80 -> V_58 [ V_5 -> V_51 ] . V_138 == NULL )
return - V_139 ;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
V_137 = V_135 -> V_138 [ V_5 -> V_140 ] . V_137 ;
if ( V_137 . V_116 != V_168 )
return - V_139 ;
if ( F_54 ( & V_8 -> V_131 ) )
return - V_132 ;
if ( V_167 -> type != V_174 ) {
F_43 ( 2 , V_83 , L_13 ) ;
return - V_13 ;
}
V_44 = F_61 ( V_5 -> V_157 , V_78 , V_175 , V_167 ) ;
if ( V_44 == - V_163 || V_44 == - V_171 )
V_44 = 0 ;
if ( V_44 < 0 ) {
F_43 ( 2 , V_83 , L_14 ) ;
return V_44 ;
}
if ( ! ( V_167 -> V_86 . V_90 && V_167 -> V_86 . V_87 &&
( V_167 -> V_86 . V_176 ||
V_167 -> V_86 . V_177 ||
V_167 -> V_86 . V_178 ) &&
V_167 -> V_86 . V_179 &&
( V_167 -> V_86 . V_180 ||
V_167 -> V_86 . V_181 ) ) ) {
F_43 ( 2 , V_83 , L_15
L_16
L_17
L_18
L_19 ) ;
return - V_13 ;
}
V_77 -> V_85 = * V_167 ;
V_47 -> V_182 = F_66 ( V_86 ) - 8 ;
V_47 -> V_183 = V_86 -> V_90 ;
V_47 -> V_184 = 1 ;
V_47 -> V_185 = V_86 -> V_181 + V_86 -> V_180 + 1 ;
V_47 -> V_186 = F_67 ( V_86 ) ;
if ( V_86 -> V_187 ) {
if ( V_86 -> V_188 || V_86 -> V_189 || V_86 -> V_190 ) {
V_47 -> V_191 = V_47 -> V_186 / 2 -
( V_86 -> V_179 - 1 ) ;
V_47 -> V_192 = V_47 -> V_186 / 2 + 1 ;
V_47 -> V_193 = V_47 -> V_192 + V_86 -> V_190 +
V_86 -> V_188 + 1 ;
V_47 -> V_194 = V_47 -> V_186 -
( V_86 -> V_189 - 1 ) ;
} else {
F_43 ( 2 , V_83 , L_20
L_21 ) ;
return - V_13 ;
}
} else {
V_47 -> V_191 = V_47 -> V_186 - ( V_86 -> V_179 - 1 ) ;
}
strncpy ( V_47 -> V_155 , L_22 ,
V_195 ) ;
V_47 -> V_90 = V_86 -> V_90 ;
V_47 -> V_87 = V_86 -> V_87 ;
V_47 -> V_74 = V_86 -> V_187 ? 0 : 1 ;
V_47 -> V_48 = 0 ;
V_47 -> V_196 = 0 ;
V_47 -> V_197 = 0 ;
V_47 -> V_49 = 1 ;
V_47 -> V_84 = 0 ;
V_77 -> V_84 = 0 ;
return 0 ;
}
static int F_68 ( struct V_109 * V_109 , void * V_110 ,
struct V_172 * V_167 )
{
struct V_36 * V_80 = V_38 -> V_39 ;
struct V_127 * V_128 = F_50 ( V_109 ) ;
struct V_4 * V_5 = F_51 ( V_128 ) ;
struct V_134 * V_135 ;
struct V_76 * V_77 = & V_5 -> V_78 ;
struct V_136 V_137 ;
if ( V_80 -> V_58 [ V_5 -> V_51 ] . V_138 == NULL )
goto error;
V_135 = & V_80 -> V_58 [ V_5 -> V_51 ] ;
V_137 = V_135 -> V_138 [ V_5 -> V_140 ] . V_137 ;
if ( V_137 . V_116 != V_168 )
goto error;
* V_167 = V_77 -> V_85 ;
return 0 ;
error:
return - V_139 ;
}
static int F_69 ( struct V_109 * V_198 , void * V_110 )
{
F_70 ( & V_70 . V_143 , 0 , V_199 , V_200 ) ;
return 0 ;
}
static int F_71 ( void )
{
int V_201 ;
int V_50 , V_71 , V_202 ;
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_70 . V_69 [ V_71 ] =
F_72 ( sizeof( struct V_4 ) , V_204 ) ;
if ( ! V_70 . V_69 [ V_71 ] ) {
V_201 = V_71 ;
V_50 = - V_205 ;
goto V_206;
}
}
return 0 ;
V_206:
for ( V_202 = 0 ; V_202 < V_201 ; V_202 ++ )
F_73 ( V_70 . V_69 [ V_202 ] ) ;
return V_50 ;
}
static int F_74 ( struct V_207 * V_208 ,
struct V_156 * V_209 ,
struct V_210 * V_211 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 . V_80 -> V_153 ; V_71 ++ )
if ( ! strcmp ( V_70 . V_80 -> V_154 [ V_71 ] . V_155 ,
V_209 -> V_155 ) ) {
V_70 . V_157 [ V_71 ] = V_209 ;
V_70 . V_157 [ V_71 ] -> V_212 = 1 << V_71 ;
return 0 ;
}
return - V_13 ;
}
static int F_75 ( void )
{
struct V_7 * V_8 ;
struct V_127 * V_128 ;
struct V_4 * V_5 ;
struct V_6 * V_213 ;
int V_202 , V_50 , V_214 ;
for ( V_202 = 0 ; V_202 < V_203 ; V_202 ++ ) {
V_5 = V_70 . V_69 [ V_202 ] ;
for ( V_214 = 0 ; V_214 < V_73 ; V_214 ++ ) {
V_8 = & V_5 -> V_8 [ V_214 ] ;
F_76 ( & V_8 -> V_32 ) ;
F_77 ( & V_8 -> V_215 ) ;
V_8 -> V_55 = NULL ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = 0 ;
V_8 -> V_20 = 0 ;
V_8 -> V_21 = 0 ;
V_8 -> V_53 = NULL ;
V_8 -> V_52 = NULL ;
memset ( & V_8 -> V_10 , 0 , sizeof( V_8 -> V_10 ) ) ;
}
V_5 -> V_216 = 0 ;
if ( V_70 . V_80 -> V_153 )
V_5 -> V_157 = V_70 . V_157 [ 0 ] ;
V_5 -> V_51 = V_202 ;
memset ( & V_5 -> V_42 , 0 , sizeof( V_5 -> V_42 ) ) ;
V_5 -> V_8 [ V_9 ] . V_10 . type =
V_125 ;
V_50 = F_60 ( V_70 . V_80 , V_5 , 0 ) ;
if ( V_50 )
goto V_217;
V_5 -> V_78 . V_84 = V_218 ;
memset ( & V_5 -> V_78 . V_85 , 0 , sizeof( V_5 -> V_78 . V_85 ) ) ;
F_44 ( V_5 ) ;
V_213 = & V_8 -> V_131 ;
V_213 -> type = V_125 ;
V_213 -> V_219 = V_220 | V_221 | V_222 ;
V_213 -> V_223 = V_5 ;
V_213 -> V_224 = & V_225 ;
V_213 -> V_226 = & V_227 ;
V_213 -> V_228 = sizeof( struct V_1 ) ;
V_213 -> V_229 = V_230 ;
V_213 -> V_231 = 1 ;
V_213 -> V_215 = & V_8 -> V_215 ;
V_50 = F_78 ( V_213 ) ;
if ( V_50 ) {
F_10 ( L_23 ) ;
goto V_217;
}
V_8 -> V_29 = F_79 ( V_38 ) ;
if ( F_80 ( V_8 -> V_29 ) ) {
F_10 ( L_24 ) ;
V_50 = F_81 ( V_8 -> V_29 ) ;
goto V_217;
}
F_82 ( & V_8 -> V_34 ) ;
F_43 ( 1 , V_83 , L_25 ,
V_5 , & V_5 -> V_164 ) ;
V_128 = V_5 -> V_164 ;
F_46 ( V_128 -> V_155 , V_119 , sizeof( V_128 -> V_155 ) ) ;
V_128 -> V_232 = V_233 ;
V_128 -> V_234 = & V_235 ;
V_128 -> V_236 = & V_237 ;
V_128 -> V_143 = & V_70 . V_143 ;
V_128 -> V_238 = V_239 ;
V_128 -> V_240 = V_213 ;
V_128 -> V_215 = & V_8 -> V_215 ;
F_83 ( V_5 -> V_164 , V_5 ) ;
V_50 = F_84 ( V_128 , V_241 ,
( V_202 ? 3 : 2 ) ) ;
if ( V_50 < 0 )
goto V_217;
}
return 0 ;
V_217:
for ( V_214 = 0 ; V_214 < V_202 ; V_214 ++ ) {
V_5 = V_70 . V_69 [ V_214 ] ;
V_8 = & V_5 -> V_8 [ V_214 ] ;
F_85 ( V_8 -> V_29 ) ;
F_86 ( V_5 -> V_164 ) ;
V_233 ( V_5 -> V_164 ) ;
V_5 -> V_164 = NULL ;
}
return V_50 ;
}
static int F_87 ( struct V_207 * V_208 )
{
return F_75 () ;
}
static T_4 int F_88 ( struct V_242 * V_243 )
{
struct V_150 * V_244 ;
int V_71 , V_202 = 0 , V_50 = 0 ;
int V_245 = 0 ;
struct V_246 * V_247 ;
struct V_4 * V_5 ;
struct V_127 * V_248 ;
struct V_249 * V_250 ;
int V_153 ;
V_38 = & V_243 -> V_69 ;
V_50 = F_71 () ;
if ( V_50 ) {
F_89 ( V_38 -> V_118 , L_26 ) ;
return V_50 ;
}
V_50 = F_90 ( V_38 , & V_70 . V_143 ) ;
if ( V_50 ) {
F_89 ( V_38 -> V_118 , L_27 ) ;
return V_50 ;
}
while ( ( V_250 = F_91 ( V_243 , V_251 , V_245 ) ) ) {
V_50 = F_92 ( & V_243 -> V_69 , V_250 -> V_252 , F_39 ,
V_253 , V_119 ,
( void * ) ( & V_70 . V_69 [ V_245 ] ->
V_51 ) ) ;
if ( V_50 ) {
V_50 = - V_13 ;
F_10 ( L_28 ) ;
goto V_254;
}
V_245 ++ ;
}
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_5 = V_70 . V_69 [ V_71 ] ;
V_248 = F_93 () ;
if ( V_248 == NULL ) {
for ( V_202 = 0 ; V_202 < V_71 ; V_202 ++ ) {
V_5 = V_70 . V_69 [ V_202 ] ;
V_233 ( V_5 -> V_164 ) ;
}
V_50 = - V_205 ;
goto V_254;
}
V_5 -> V_164 = V_248 ;
}
V_70 . V_80 = V_243 -> V_69 . V_39 ;
V_153 = V_70 . V_80 -> V_153 ;
V_244 = V_70 . V_80 -> V_154 ;
V_70 . V_157 = F_72 ( sizeof( struct V_156 * ) * V_153 ,
V_204 ) ;
if ( V_70 . V_157 == NULL ) {
F_10 ( L_29 ) ;
V_50 = - V_205 ;
goto V_255;
}
if ( ! V_70 . V_80 -> V_256 ) {
V_247 = F_94 ( 1 ) ;
for ( V_71 = 0 ; V_71 < V_153 ; V_71 ++ ) {
V_70 . V_157 [ V_71 ] =
F_95 ( & V_70 . V_143 ,
V_247 ,
& V_244 [ V_71 ] .
V_257 ,
NULL ) ;
if ( ! V_70 . V_157 [ V_71 ] ) {
F_10 ( L_30 ) ;
V_50 = - V_171 ;
goto V_258;
}
if ( V_70 . V_157 [ V_71 ] )
V_70 . V_157 [ V_71 ] -> V_212 = 1 << V_71 ;
}
F_75 () ;
} else {
V_70 . V_208 . V_259 = V_70 . V_80 -> V_211 ;
V_70 . V_208 . V_260 = V_70 . V_80 -> V_256 [ 0 ] ;
V_70 . V_208 . V_261 = F_74 ;
V_70 . V_208 . V_262 = F_87 ;
V_50 = F_96 ( & V_70 . V_143 ,
& V_70 . V_208 ) ;
if ( V_50 ) {
F_10 ( L_31 ) ;
V_50 = - V_13 ;
goto V_258;
}
}
return 0 ;
V_258:
F_73 ( V_70 . V_157 ) ;
V_255:
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_5 = V_70 . V_69 [ V_71 ] ;
V_233 ( V_5 -> V_164 ) ;
}
V_254:
F_97 ( & V_70 . V_143 ) ;
return V_50 ;
}
static int F_98 ( struct V_242 * V_263 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_71 ;
F_97 ( & V_70 . V_143 ) ;
F_73 ( V_70 . V_157 ) ;
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_5 = V_70 . V_69 [ V_71 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_85 ( V_8 -> V_29 ) ;
F_86 ( V_5 -> V_164 ) ;
V_5 -> V_164 = NULL ;
F_73 ( V_70 . V_69 [ V_71 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_263 * V_69 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_5 = V_70 . V_69 [ V_71 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( ! F_100 ( & V_8 -> V_131 ) )
continue;
F_101 ( & V_8 -> V_215 ) ;
if ( V_5 -> V_51 == V_57 ) {
F_24 ( 0 ) ;
F_23 ( 0 ) ;
}
if ( V_5 -> V_51 == V_60 ||
V_48 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_102 ( & V_8 -> V_215 ) ;
}
return 0 ;
}
static int F_103 ( struct V_263 * V_69 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_203 ; V_71 ++ ) {
V_5 = V_70 . V_69 [ V_71 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( ! F_100 ( & V_8 -> V_131 ) )
continue;
F_101 ( & V_8 -> V_215 ) ;
if ( V_5 -> V_51 == V_57 ) {
F_24 ( 1 ) ;
F_23 ( 1 ) ;
}
if ( V_5 -> V_51 == V_60 ||
V_48 == 2 ) {
F_28 ( 1 ) ;
F_27 ( 1 ) ;
}
F_102 ( & V_8 -> V_215 ) ;
}
return 0 ;
}
