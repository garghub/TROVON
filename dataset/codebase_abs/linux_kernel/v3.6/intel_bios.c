static void * F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 ;
int V_5 = 0 ;
T_2 V_6 , V_7 ;
T_1 V_8 ;
V_5 += V_2 -> V_9 ;
V_6 = V_2 -> V_10 ;
while ( V_5 < V_6 ) {
V_8 = * ( V_4 + V_5 ) ;
V_5 ++ ;
V_7 = * ( ( T_2 * ) ( V_4 + V_5 ) ) ;
V_5 += 2 ;
if ( V_8 == V_3 )
return V_4 + V_5 ;
V_5 += V_7 ;
}
return NULL ;
}
static T_2
F_2 ( void * V_11 )
{
T_2 * V_12 , V_13 ;
V_12 = ( T_2 * ) ( ( char * ) V_11 - 2 ) ;
V_13 = * V_12 ;
return V_13 ;
}
static void F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_18 = ( V_17 -> V_19 << 8 ) |
V_17 -> V_20 ;
V_15 -> V_21 = V_15 -> V_18 +
( ( V_17 -> V_22 << 8 ) | V_17 -> V_23 ) ;
V_15 -> V_24 = V_15 -> V_21 +
V_17 -> V_25 ;
V_15 -> V_26 = V_15 -> V_18 +
( ( V_17 -> V_27 << 8 ) | V_17 -> V_28 ) ;
V_15 -> V_29 = ( V_17 -> V_30 << 8 ) |
V_17 -> V_31 ;
V_15 -> V_32 = V_15 -> V_29 +
V_17 -> V_33 ;
V_15 -> V_34 = V_15 -> V_32 +
V_17 -> V_35 ;
V_15 -> V_36 = V_15 -> V_29 +
( ( V_17 -> V_37 << 8 ) | V_17 -> V_38 ) ;
V_15 -> clock = V_17 -> clock * 10 ;
V_15 -> type = V_39 ;
if ( V_17 -> V_40 )
V_15 -> V_41 |= V_42 ;
else
V_15 -> V_41 |= V_43 ;
if ( V_17 -> V_44 )
V_15 -> V_41 |= V_45 ;
else
V_15 -> V_41 |= V_46 ;
if ( V_15 -> V_24 > V_15 -> V_26 )
V_15 -> V_26 = V_15 -> V_24 + 1 ;
if ( V_15 -> V_34 > V_15 -> V_36 )
V_15 -> V_36 = V_15 -> V_34 + 1 ;
F_4 ( V_15 ) ;
}
static void F_5 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_49 * V_50 = NULL ;
struct V_49 * V_51 ;
T_1 V_52 = 0 ;
void * V_53 = NULL ;
struct V_54 * V_55
= F_1 ( V_2 , V_56 ) ;
V_48 -> V_51 = NULL ;
if ( V_55 )
V_52 = V_55 -> V_57 ;
else
return;
V_53 = F_1 ( V_2 , V_58 ) ;
V_50 = (struct V_49 * ) ( V_53 + 1 ) + V_52 ;
V_51 = F_6 ( sizeof( * V_50 ) , V_59 ) ;
if ( ! V_51 ) {
F_7 ( V_48 -> V_60 -> V_60 , L_1 ) ;
return;
}
memcpy ( V_51 , V_50 , sizeof( * V_50 ) ) ;
V_48 -> V_51 = V_51 ;
}
static void F_8 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_54 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
V_48 -> V_66 = 0 ;
V_48 -> V_67 = 0 ;
V_61 = F_1 ( V_2 , V_56 ) ;
if ( ! V_61 )
return;
V_48 -> V_66 = V_61 -> V_68 ;
if ( V_61 -> V_57 == 0xff )
return;
V_63 = F_1 ( V_2 , V_69 ) ;
if ( ! V_63 )
return;
V_65 = & V_63 -> V_70 [ V_61 -> V_57 ] ;
V_17 = & V_65 -> V_17 ;
V_15 = F_6 ( sizeof( * V_15 ) ,
V_59 ) ;
if ( V_15 == NULL ) {
F_7 ( V_48 -> V_60 -> V_60 , L_2 ) ;
return;
}
V_48 -> V_67 = 1 ;
F_3 ( V_15 , V_17 ) ;
if ( V_15 -> V_26 > 0 && V_15 -> V_36 > 0 ) {
V_48 -> V_71 = V_15 ;
F_9 ( V_15 ) ;
} else {
F_10 ( V_48 -> V_60 -> V_60 , L_3 ) ;
V_48 -> V_67 = 0 ;
F_11 ( V_15 ) ;
}
return;
}
static void F_12 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_72 * V_73 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
V_48 -> V_74 = NULL ;
V_73 = F_1 ( V_2 , V_75 ) ;
if ( ! V_73 )
return;
V_17 = F_1 ( V_2 , V_76 ) ;
if ( ! V_17 )
return;
V_15 = F_6 ( sizeof( * V_15 ) , V_59 ) ;
if ( ! V_15 )
return;
F_3 ( V_15 ,
V_17 + V_73 -> V_57 ) ;
V_48 -> V_74 = V_15 ;
return;
}
static void F_13 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_77 * V_78 ;
V_48 -> V_79 = 1 ;
V_48 -> V_80 = 1 ;
V_78 = F_1 ( V_2 , V_81 ) ;
if ( V_78 ) {
V_48 -> V_79 = V_78 -> V_79 ;
V_48 -> V_80 = V_78 -> V_80 ;
V_48 -> V_82 = V_78 -> V_83 ;
if ( V_48 -> V_82 ) {
V_48 -> V_84
= V_78 -> V_85 ? 100 : 96 ;
}
}
}
static void
F_14 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_92 , V_93 , V_94 ;
T_2 V_13 ;
V_89 = F_1 ( V_2 , V_95 ) ;
if ( ! V_89 ) {
F_15 ( L_4 ) ;
return;
}
if ( V_89 -> V_96 != sizeof( * V_91 ) ) {
F_15 ( L_5 ) ;
return;
}
V_13 = F_2 ( V_89 ) ;
V_93 = ( V_13 - sizeof( * V_89 ) ) /
sizeof( * V_91 ) ;
V_94 = 0 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_91 = & ( V_89 -> V_97 [ V_92 ] ) ;
if ( ! V_91 -> V_98 ) {
continue;
}
if ( V_91 -> V_99 != V_100 &&
V_91 -> V_99 != V_101 ) {
continue;
}
if ( V_91 -> V_102 != V_103 &&
V_91 -> V_102 != V_104 ) {
F_15 ( L_6 ) ;
continue;
}
F_15 ( L_7
L_8 ,
V_91 -> V_99 ,
( V_91 -> V_102 == V_103 ) ?
L_9 : L_10 ) ;
V_87 = & ( V_48 -> V_105 [ V_91 -> V_102 - 1 ] ) ;
if ( ! V_87 -> V_106 ) {
V_87 -> V_102 = V_91 -> V_102 ;
V_87 -> V_99 = V_91 -> V_99 ;
V_87 -> V_107 = V_91 -> V_107 ;
V_87 -> V_108 = V_91 -> V_108 ;
V_87 -> V_109 = V_91 -> V_109 ;
V_87 -> V_106 = 1 ;
F_15 ( L_11 ,
V_87 -> V_102 ,
V_87 -> V_99 ,
V_87 -> V_107 ,
V_87 -> V_108 ,
V_87 -> V_109 ) ;
} else {
F_15 ( L_12
L_13 ) ;
}
if ( V_91 -> V_110 ) {
F_15 ( L_14
L_15 ) ;
}
V_94 ++ ;
}
if ( ! V_94 ) {
F_15 ( L_16 ) ;
}
return;
}
static void
F_16 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_111 * V_112 ;
V_112 = F_1 ( V_2 , V_113 ) ;
if ( ! V_112 )
return;
if ( V_112 -> V_114 )
V_48 -> V_115 = true ;
else
V_48 -> V_115 = false ;
}
static void
F_17 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 , * V_116 ;
int V_92 , V_93 , V_94 ;
T_2 V_13 ;
V_89 = F_1 ( V_2 , V_95 ) ;
if ( ! V_89 ) {
F_15 ( L_17 ) ;
return;
}
if ( V_89 -> V_96 != sizeof( * V_91 ) ) {
F_15 ( L_5 ) ;
return;
}
V_13 = F_2 ( V_89 ) ;
V_93 = ( V_13 - sizeof( * V_89 ) ) /
sizeof( * V_91 ) ;
V_94 = 0 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_91 = & ( V_89 -> V_97 [ V_92 ] ) ;
if ( ! V_91 -> V_98 ) {
continue;
}
V_94 ++ ;
}
if ( ! V_94 ) {
F_15 ( L_18 ) ;
return;
}
V_48 -> V_117 = F_18 ( V_94 , sizeof( * V_91 ) , V_59 ) ;
if ( ! V_48 -> V_117 ) {
F_15 ( L_19 ) ;
return;
}
V_48 -> V_118 = V_94 ;
V_94 = 0 ;
for ( V_92 = 0 ; V_92 < V_93 ; V_92 ++ ) {
V_91 = & ( V_89 -> V_97 [ V_92 ] ) ;
if ( ! V_91 -> V_98 ) {
continue;
}
V_116 = V_48 -> V_117 + V_94 ;
V_94 ++ ;
memcpy ( ( void * ) V_116 , ( void * ) V_91 ,
sizeof( * V_91 ) ) ;
}
return;
}
int F_19 ( struct V_119 * V_60 )
{
struct V_47 * V_48 = V_60 -> V_120 ;
struct V_121 * V_122 = V_60 -> V_122 ;
struct V_123 * V_124 = NULL ;
struct V_1 * V_2 = NULL ;
T_1 T_3 * V_125 = NULL ;
T_4 V_126 ;
int V_92 ;
if ( V_48 -> V_127 . V_124 ) {
struct V_123 * V_124 = V_48 -> V_127 . V_124 ;
if ( memcmp ( V_124 -> V_128 , L_20 , 4 ) == 0 ) {
F_15 ( L_21 ,
V_124 -> V_128 ) ;
V_2 = (struct V_1 * ) ( ( char * ) V_124 + V_124 -> V_129 ) ;
} else
V_48 -> V_127 . V_124 = NULL ;
}
if ( V_2 == NULL ) {
V_125 = F_20 ( V_122 , & V_126 ) ;
if ( ! V_125 )
return - 1 ;
for ( V_92 = 0 ; V_92 + 4 < V_126 ; V_92 ++ ) {
if ( ! memcmp ( V_125 + V_92 , L_20 , 4 ) ) {
V_124 = (struct V_123 * ) ( V_125 + V_92 ) ;
break;
}
}
if ( ! V_124 ) {
F_7 ( V_60 -> V_60 , L_22 ) ;
F_21 ( V_122 , V_125 ) ;
return - 1 ;
}
V_2 = (struct V_1 * ) ( V_125 + V_92 + V_124 -> V_129 ) ;
}
F_13 ( V_48 , V_2 ) ;
F_16 ( V_48 , V_2 ) ;
F_8 ( V_48 , V_2 ) ;
F_12 ( V_48 , V_2 ) ;
F_14 ( V_48 , V_2 ) ;
F_17 ( V_48 , V_2 ) ;
F_5 ( V_48 , V_2 ) ;
if ( V_125 )
F_21 ( V_122 , V_125 ) ;
return 0 ;
}
void F_22 ( struct V_119 * V_60 )
{
struct V_47 * V_48 = V_60 -> V_120 ;
F_11 ( V_48 -> V_74 ) ;
F_11 ( V_48 -> V_71 ) ;
F_11 ( V_48 -> V_51 ) ;
}
