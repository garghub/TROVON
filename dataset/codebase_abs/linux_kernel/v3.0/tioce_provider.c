static void inline
F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 -> V_7 != V_8 )
return;
V_4 = V_2 -> V_6 -> V_9 . V_10 ;
V_5 = ( unsigned long ) V_3 - V_4 ;
if ( V_5 < 0x45000 ) {
T_2 V_11 ;
if ( V_5 == 0 || V_5 == 0x80 )
V_11 = 0xc0 ;
else if ( V_5 == 0x148 || V_5 == 0x200 )
V_11 = 0x28 ;
else
V_11 = 0x158 ;
F_2 ( ( void T_1 * ) ( V_4 + V_11 ) ) ;
}
}
static void inline
F_3 ( struct V_1 * V_2 , void T_1 * V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 -> V_7 != V_8 )
return;
V_4 = V_2 -> V_6 -> V_9 . V_10 ;
V_5 = ( unsigned long ) V_3 - V_4 ;
if ( V_5 < 0x45000 ) {
if ( V_5 == 0x100 )
F_2 ( ( void T_1 * ) ( V_4 + 0x38 ) ) ;
F_2 ( ( void T_1 * ) ( V_4 + 0xb050 ) ) ;
}
}
static T_2
F_4 ( unsigned long V_12 , int V_13 )
{
T_2 V_14 ;
V_14 = V_12 | ( 1UL << 63 ) ;
if ( V_13 & V_15 )
V_14 |= ( 1UL << 61 ) ;
return V_14 ;
}
static inline void
F_5 ( struct V_16 * V_17 , struct V_18 T_1 * * V_19 ,
struct V_1 * * V_20 , int * V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_6 ;
struct V_1 * V_24 ;
V_22 = F_6 ( V_17 ) ;
V_6 = (struct V_23 * ) V_22 -> V_25 ;
V_24 = (struct V_1 * ) V_6 -> V_26 ;
if ( V_19 )
* V_19 = (struct V_18 T_1 * ) V_6 -> V_9 . V_10 ;
if ( V_20 )
* V_20 = V_24 ;
if ( V_21 )
* V_21 =
( V_17 -> V_27 -> V_28 < V_24 -> V_29 ) ? 0 : 1 ;
}
static T_2
F_7 ( struct V_1 * V_30 , int type , int V_21 ,
T_2 V_12 , int V_31 , int V_13 )
{
int V_32 ;
int V_33 ;
int V_34 ;
int V_35 ;
int V_36 ;
int V_37 ;
T_2 V_38 ;
int V_39 , V_40 ;
T_2 * V_41 ;
T_2 T_1 * V_42 ;
T_2 V_43 ;
struct V_18 T_1 * V_44 ;
T_2 V_45 ;
struct V_46 * V_47 ;
V_44 = (struct V_18 T_1 * ) V_30 -> V_6 -> V_9 . V_10 ;
switch ( type ) {
case V_48 :
V_34 = 64 ;
V_36 = V_49 - 64 ;
V_41 = V_30 -> V_50 ;
V_42 = V_44 -> V_51 ;
V_38 = V_30 -> V_52 ;
V_45 = V_53 ;
V_39 = 1 ;
break;
case V_54 :
V_34 = 0 ;
V_36 = V_55 ;
V_41 = V_30 -> V_56 ;
V_42 = V_44 -> V_57 ;
V_38 = F_8 ( 64 ) ;
V_45 = V_58 ;
V_39 = 0 ;
break;
case V_59 :
V_34 = V_21 * 32 ;
V_36 = 32 ;
V_41 = V_30 -> V_50 ;
V_42 = V_44 -> V_51 ;
V_38 = F_9 ( 16 ) ;
V_45 = V_60 ;
V_39 = 0 ;
break;
default:
return 0 ;
}
V_40 = V_13 & V_15 ;
if ( V_40 && ! V_39 )
return 0 ;
V_37 = F_10 ( V_12 , V_31 , V_38 ) ;
if ( V_37 > V_36 )
return 0 ;
V_35 = V_34 + V_36 - V_37 ;
for ( V_32 = V_34 ; V_32 <= V_35 ; V_32 ++ ) {
if ( F_11 ( V_41 [ V_32 ] ) )
continue;
for ( V_33 = V_32 ; V_33 < V_32 + V_37 ; V_33 ++ )
if ( F_11 ( V_41 [ V_33 ] ) )
break;
if ( V_33 >= V_32 + V_37 )
break;
}
if ( V_32 > V_35 )
return 0 ;
V_47 = F_12 ( sizeof( struct V_46 ) , V_61 ) ;
if ( ! V_47 )
return 0 ;
V_43 = V_12 ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
T_2 V_62 ;
V_62 = F_13 ( V_43 , V_38 , V_40 ) ;
V_41 [ V_32 + V_33 ] = V_62 ;
F_14 ( V_30 , & V_42 [ V_32 + V_33 ] , V_62 ) ;
V_43 += V_38 ;
}
V_47 -> V_63 = 1 ;
V_47 -> V_64 = V_37 * V_38 ;
V_47 -> V_65 = V_12 & ~ F_15 ( V_38 ) ;
V_47 -> V_66 = V_45 + ( V_32 * V_38 ) ;
V_47 -> V_67 = & V_42 [ V_32 ] ;
V_47 -> V_41 = & V_41 [ V_32 ] ;
V_47 -> V_68 = V_37 ;
F_16 ( & V_47 -> V_69 , & V_30 -> V_69 ) ;
return ( V_47 -> V_66 + ( V_12 - V_47 -> V_65 ) ) ;
}
static T_2
F_17 ( struct V_16 * V_17 , T_2 V_12 , int V_13 )
{
int V_70 ;
int V_21 ;
struct V_18 T_1 * V_44 ;
struct V_1 * V_30 ;
T_2 V_71 ;
T_2 V_72 ;
T_3 V_14 ;
if ( V_13 & V_15 )
return 0 ;
V_71 = V_12 & ~ 0x3fffffffUL ;
V_72 = V_12 & 0x3fffffffUL ;
F_5 ( V_17 , & V_44 , & V_30 , & V_21 ) ;
if ( V_30 -> V_73 [ V_21 ] . V_74 == 0 ) {
T_2 V_75 ;
V_30 -> V_73 [ V_21 ] . V_76 = V_71 ;
F_14 ( V_30 , & V_44 -> V_77 [ V_21 ] ,
V_71 ) ;
V_75 = V_44 -> V_77 [ V_21 ] ;
V_70 = 1 ;
} else
V_70 = ( V_30 -> V_73 [ V_21 ] . V_76 == V_71 ) ;
if ( V_70 ) {
V_30 -> V_73 [ V_21 ] . V_74 ++ ;
V_14 = V_78 + V_72 ;
} else
V_14 = 0 ;
return V_14 ;
}
static T_2
F_18 ( T_2 V_14 , int V_79 )
{
T_2 V_80 ;
if ( F_19 ( V_14 ) || F_20 ( V_14 ) )
return V_14 ;
if ( F_21 ( V_14 ) )
V_80 = ( 1UL << 62 ) ;
else
V_80 = ( 1UL << 30 ) ;
return ( V_79 ) ? ( V_14 | V_80 ) : ( V_14 & ~ V_80 ) ;
}
void
F_22 ( struct V_16 * V_17 , T_3 V_14 , int V_81 )
{
int V_32 ;
int V_21 ;
struct V_1 * V_30 ;
struct V_18 T_1 * V_44 ;
unsigned long V_82 ;
V_14 = F_18 ( V_14 , 0 ) ;
F_5 ( V_17 , & V_44 , & V_30 , & V_21 ) ;
if ( F_21 ( V_14 ) )
return;
F_23 ( & V_30 -> V_83 , V_82 ) ;
if ( F_24 ( V_14 ) ) {
if ( -- V_30 -> V_73 [ V_21 ] . V_74 == 0 ) {
V_30 -> V_73 [ V_21 ] . V_76 = 0 ;
F_14 ( V_30 , & V_44 -> V_77 [ V_21 ] ,
0 ) ;
}
} else {
struct V_46 * V_47 ;
F_25 (map, &ce_kern->ce_dmamap_list,
ce_dmamap_list) {
T_2 V_35 ;
V_35 = V_47 -> V_66 + V_47 -> V_64 - 1 ;
if ( V_14 >= V_47 -> V_66 && V_14 <= V_35 )
break;
}
if ( & V_47 -> V_69 == & V_30 -> V_69 ) {
F_26 ( V_84
L_1 ,
V_85 , F_27 ( V_17 ) , V_14 ) ;
} else if ( -- V_47 -> V_63 == 0 ) {
for ( V_32 = 0 ; V_32 < V_47 -> V_68 ; V_32 ++ ) {
V_47 -> V_41 [ V_32 ] = 0 ;
F_14 ( V_30 , & V_47 -> V_67 [ V_32 ] , 0 ) ;
}
F_28 ( & V_47 -> V_69 ) ;
F_29 ( V_47 ) ;
}
}
F_30 ( & V_30 -> V_83 , V_82 ) ;
}
static T_2
F_31 ( struct V_16 * V_17 , T_2 V_86 , T_4 V_87 ,
int V_88 , int V_13 )
{
unsigned long V_82 ;
T_2 V_12 ;
T_2 V_89 = 0 ;
struct V_1 * V_30 ;
struct V_46 * V_47 ;
int V_21 ;
T_2 V_90 ;
V_90 = ( V_88 ) ? V_17 -> V_91 . V_92 : V_17 -> V_90 ;
if ( V_90 < 0x7fffffffUL )
return 0 ;
if ( F_32 ( V_13 ) == V_93 )
V_12 = F_33 ( V_86 ) ;
else
V_12 = V_86 ;
if ( V_90 == ~ 0UL ) {
V_89 = F_4 ( V_12 , V_13 ) ;
if ( V_89 )
goto V_94;
}
F_5 ( V_17 , NULL , & V_30 , & V_21 ) ;
F_23 ( & V_30 -> V_83 , V_82 ) ;
F_25 (map, &ce_kern->ce_dmamap_list, ce_dmamap_list) {
T_2 V_35 ;
V_35 = V_47 -> V_65 + V_47 -> V_64 - 1 ;
if ( V_12 >= V_47 -> V_65 &&
V_12 + V_87 - 1 <= V_35 &&
V_47 -> V_66 <= V_90 ) {
V_47 -> V_63 ++ ;
V_89 = V_47 -> V_66 + ( V_12 - V_47 -> V_65 ) ;
break;
}
}
if ( ! V_89 && ! V_88 && V_90 >= 0xffffffffffUL ) {
if ( V_87 > F_8 ( 64 ) ) {
V_89 = F_7 ( V_30 , V_59 ,
V_21 , V_12 , V_87 ,
V_13 ) ;
if ( ! V_89 )
V_89 =
F_7 ( V_30 , V_54 , - 1 ,
V_12 , V_87 ,
V_13 ) ;
} else {
V_89 = F_7 ( V_30 , V_54 , - 1 ,
V_12 , V_87 ,
V_13 ) ;
if ( ! V_89 )
V_89 =
F_7 ( V_30 , V_59 ,
V_21 , V_12 , V_87 ,
V_13 ) ;
}
}
if ( ! V_89 && V_90 >= 0xffffffffUL )
V_89 = F_17 ( V_17 , V_12 , V_13 ) ;
if ( ! V_89 )
V_89 =
F_7 ( V_30 , V_48 , - 1 , V_12 ,
V_87 , V_13 ) ;
F_30 ( & V_30 -> V_83 , V_82 ) ;
V_94:
if ( V_89 && V_88 )
V_89 = F_18 ( V_89 , 1 ) ;
return V_89 ;
}
static T_2
F_34 ( struct V_16 * V_17 , unsigned long V_86 , T_4 V_87 , int V_13 )
{
return F_31 ( V_17 , V_86 , V_87 , 0 , V_13 ) ;
}
static T_2
F_35 ( struct V_16 * V_17 , unsigned long V_86 , T_4 V_87 , int V_13 )
{
return F_31 ( V_17 , V_86 , V_87 , 1 , V_13 ) ;
}
static T_5
F_36 ( int V_95 , void * V_96 )
{
struct V_23 * V_97 = V_96 ;
struct V_98 V_99 ;
V_99 . V_100 = 0 ;
V_99 . V_101 = 0 ;
F_37 ( V_99 , ( T_2 ) V_102 ,
V_97 -> V_9 . V_103 ,
V_97 -> V_9 . V_104 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_99 . V_101 )
F_38 ( L_2 ) ;
return V_105 ;
}
static void
F_39 ( struct V_1 * V_30 , T_2 V_19 , T_2 V_106 )
{
int V_107 , V_108 , V_109 ;
struct V_18 T_1 * V_44 ;
V_44 = (struct V_18 T_1 * ) V_30 -> V_6 -> V_9 . V_10 ;
V_109 = V_30 -> V_52 ;
V_107 = F_40 ( V_19 , V_109 ) ;
V_108 = V_107 + F_10 ( V_19 , V_106 - V_19 + 1 , V_109 ) - 1 ;
if ( V_107 < 64 )
V_107 = 64 ;
if ( V_108 >= V_49 )
V_108 = V_49 - 1 ;
while ( V_107 <= V_108 ) {
T_2 V_62 ;
V_62 = F_13 ( 0xdeadbeef , V_109 , 0 ) ;
V_30 -> V_50 [ V_107 ] = V_62 ;
F_14 ( V_30 , & V_44 -> V_51 [ V_107 ] ,
V_62 ) ;
V_107 ++ ;
}
}
static struct V_1 *
F_41 ( struct V_23 * V_23 )
{
int V_32 ;
int V_109 ;
int V_91 ;
T_6 V_75 ;
unsigned int V_110 , V_27 ;
struct V_18 T_1 * V_111 ;
struct V_1 * V_112 ;
V_112 = F_12 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_112 ) {
return NULL ;
}
V_112 -> V_6 = V_23 ;
F_42 ( & V_112 -> V_83 ) ;
F_43 ( & V_112 -> V_69 ) ;
V_23 -> V_26 = ( T_2 ) V_112 ;
V_110 = V_23 -> V_9 . V_103 ;
V_27 = V_23 -> V_9 . V_104 ;
F_44 ( V_110 , V_27 , F_45 ( 2 , 0 ) , V_114 , 1 , & V_75 ) ;
V_112 -> V_29 = ( V_115 ) V_75 ;
V_111 = (struct V_18 T_1 * ) V_23 -> V_9 . V_10 ;
F_46 ( V_112 , & V_111 -> V_116 ,
V_117 ) ;
F_47 ( V_112 , & V_111 -> V_116 ,
V_118 ) ;
V_109 = V_112 -> V_52 = F_48 ( 256 ) ;
for ( V_32 = 0 ; V_32 < V_55 ; V_32 ++ ) {
V_112 -> V_56 [ V_32 ] = 0 ;
F_14 ( V_112 , & V_111 -> V_57 [ V_32 ] , 0 ) ;
}
for ( V_32 = 0 ; V_32 < V_49 ; V_32 ++ ) {
V_112 -> V_50 [ V_32 ] = 0 ;
F_14 ( V_112 , & V_111 -> V_51 [ V_32 ] , 0 ) ;
}
for ( V_91 = 1 ; V_91 <= 2 ; V_91 ++ ) {
T_2 V_19 , V_106 ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_119 , 2 , & V_75 ) ;
V_19 = ( T_2 ) V_75 << 16 ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_120 , 2 , & V_75 ) ;
V_106 = ( T_2 ) V_75 << 16 ;
V_106 |= 0xfffffUL ;
if ( V_19 < V_106 )
F_39 ( V_112 , V_19 , V_106 ) ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_121 , 2 , & V_75 ) ;
V_19 = ( ( T_2 ) V_75 & V_122 ) << 16 ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_123 , 4 , & V_75 ) ;
V_19 |= ( T_2 ) V_75 << 32 ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_124 , 2 , & V_75 ) ;
V_106 = ( ( T_2 ) V_75 & V_122 ) << 16 ;
V_106 |= 0xfffffUL ;
F_44 ( V_110 , V_27 , F_45 ( V_91 , 0 ) ,
V_125 , 4 , & V_75 ) ;
V_106 |= ( T_2 ) V_75 << 32 ;
if ( ( V_19 < V_106 ) && F_49 ( V_19 ) )
F_39 ( V_112 , V_19 , V_106 ) ;
}
return V_112 ;
}
static void
F_50 ( struct V_126 * V_126 )
{
struct V_22 * V_22 ;
struct V_23 * V_6 ;
struct V_1 * V_30 ;
struct V_18 T_1 * V_44 ;
T_2 V_127 ;
if ( ! V_126 -> V_128 )
return;
if ( V_126 -> V_129 != V_130 )
return;
V_22 = (struct V_22 * ) V_126 -> V_131 ;
if ( ! V_22 )
return;
V_6 = (struct V_23 * ) V_22 -> V_25 ;
V_44 = (struct V_18 T_1 * ) V_6 -> V_9 . V_10 ;
V_30 = (struct V_1 * ) V_6 -> V_26 ;
if ( V_6 -> V_7 == V_8 ) {
T_2 V_132 = ( 1ULL << V_126 -> V_133 ) ;
T_2 V_100 ;
F_51 ( V_30 , & V_44 -> V_134 , & V_100 ) ;
if ( V_100 & V_132 ) {
T_2 V_135 = ( 1 << 8 ) | V_126 -> V_136 ;
T_2 V_137 = V_126 -> V_138 ;
T_2 V_139 , V_140 ;
V_139 = ( V_137 & V_141 ) >> V_142 ;
V_140 = ( V_137 & V_143 ) ;
F_52 ( F_53 ( V_139 , V_140 ) , V_135 ) ;
}
return;
}
switch ( V_126 -> V_133 ) {
case V_144 :
V_127 = 1UL << V_145 ;
break;
case V_146 :
V_127 = 1UL << V_147 ;
break;
case V_148 :
V_127 = 1UL << V_149 ;
break;
case V_150 :
V_127 = 1UL << V_151 ;
break;
case V_152 :
V_127 = 1UL << V_153 ;
break;
case V_154 :
V_127 = 1UL << V_155 ;
break;
case V_156 :
V_127 = 1UL << V_157 ;
break;
case V_158 :
V_127 = 1UL << V_159 ;
break;
default:
return;
}
F_14 ( V_30 , & V_44 -> V_160 , V_127 ) ;
}
static void
F_54 ( struct V_126 * V_126 )
{
struct V_22 * V_22 ;
struct V_23 * V_6 ;
struct V_1 * V_30 ;
struct V_18 T_1 * V_44 ;
int V_161 ;
T_2 V_162 ;
V_22 = (struct V_22 * ) V_126 -> V_131 ;
if ( ! V_22 )
return;
V_6 = (struct V_23 * ) V_22 -> V_25 ;
V_44 = (struct V_18 T_1 * ) V_6 -> V_9 . V_10 ;
V_30 = (struct V_1 * ) V_6 -> V_26 ;
V_161 = V_126 -> V_133 ;
F_47 ( V_30 , & V_44 -> V_163 , ( 1UL << V_161 ) ) ;
V_162 = ( T_2 ) V_126 -> V_136 << V_164 ;
V_162 |= V_126 -> V_138 ;
F_14 ( V_30 , & V_44 -> V_165 [ V_161 ] , V_162 ) ;
F_46 ( V_30 , & V_44 -> V_163 , ( 1UL << V_161 ) ) ;
F_50 ( V_126 ) ;
}
static void *
F_55 ( struct V_166 * V_167 , struct V_168 * V_169 )
{
struct V_23 * V_23 ;
struct V_1 * V_112 ;
struct V_18 T_1 * V_111 ;
V_23 = F_12 ( sizeof( struct V_23 ) , V_113 ) ;
if ( ! V_23 )
return NULL ;
memcpy ( V_23 , V_167 , sizeof( struct V_23 ) ) ;
V_23 -> V_9 . V_10 = ( unsigned long )
F_56 ( F_57 ( V_23 -> V_9 . V_10 ) ,
sizeof( struct V_23 ) ) ;
V_112 = F_41 ( V_23 ) ;
if ( V_112 == NULL ) {
F_29 ( V_23 ) ;
return NULL ;
}
V_111 = (struct V_18 T_1 * ) V_23 -> V_9 . V_10 ;
F_47 ( V_112 , & V_111 -> V_170 , ~ 0ULL ) ;
F_47 ( V_112 , & V_111 -> V_171 ,
~ 0ULL ) ;
F_47 ( V_112 , & V_111 -> V_172 , 0ULL ) ;
if ( F_58 ( V_173 ,
F_36 ,
V_174 , L_3 , ( void * ) V_23 ) )
F_26 ( V_84
L_4
L_5
L_6 ,
V_85 , V_173 ,
V_23 -> V_9 . V_103 ,
V_23 -> V_9 . V_104 ) ;
F_59 ( V_173 ) ;
return V_23 ;
}
int
F_60 ( void )
{
V_175 [ V_130 ] = & V_176 ;
return 0 ;
}
