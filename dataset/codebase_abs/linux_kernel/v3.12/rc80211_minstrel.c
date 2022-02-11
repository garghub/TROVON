static inline int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 ;
for ( V_4 = V_3 ; V_4 >= 0 ; V_4 -- )
if ( V_2 -> V_5 [ V_4 ] . V_3 == V_3 )
break;
return V_4 ;
}
static inline void
F_2 ( struct V_1 * V_2 , int V_4 , T_1 * V_6 )
{
int V_7 = V_8 ;
while ( V_7 > 0 && V_2 -> V_5 [ V_4 ] . V_9 > V_2 -> V_5 [ V_6 [ V_7 - 1 ] ] . V_9 )
V_7 -- ;
if ( V_7 < V_8 - 1 )
memmove ( & V_6 [ V_7 + 1 ] , & V_6 [ V_7 ] , V_8 - ( V_7 + 1 ) ) ;
if ( V_7 < V_8 )
V_6 [ V_7 ] = V_4 ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_12 , int V_13 )
{
struct V_14 * V_5 = & V_2 -> V_5 [ V_13 ] ;
V_11 -> V_15 [ V_12 ] . V_13 = V_5 -> V_3 ;
V_11 -> V_15 [ V_12 ] . V_16 = V_5 -> V_17 ;
V_11 -> V_15 [ V_12 ] . V_18 = V_5 -> V_19 ;
V_11 -> V_15 [ V_12 ] . V_20 = V_5 -> V_21 ;
}
static void
F_4 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_4 = 0 ;
V_11 = F_5 ( sizeof( * V_11 ) , V_24 ) ;
if ( ! V_11 )
return;
F_3 ( V_2 , V_11 , V_4 ++ , V_2 -> V_25 [ 0 ] ) ;
if ( V_23 -> V_26 -> V_27 >= 3 ) {
F_3 ( V_2 , V_11 , V_4 ++ , V_2 -> V_25 [ 1 ] ) ;
}
if ( V_23 -> V_26 -> V_27 >= 2 ) {
F_3 ( V_2 , V_11 , V_4 ++ , V_2 -> V_28 ) ;
}
V_11 -> V_15 [ V_4 ] . V_13 = V_2 -> V_29 ;
V_11 -> V_15 [ V_4 ] . V_16 = V_23 -> V_30 ;
V_11 -> V_15 [ V_4 ] . V_18 = V_23 -> V_30 ;
V_11 -> V_15 [ V_4 ] . V_20 = V_23 -> V_30 ;
F_6 ( V_23 -> V_26 , V_2 -> V_31 , V_11 ) ;
}
static void
F_7 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
T_1 V_32 [ V_8 ] ;
T_1 V_33 = 0 ;
T_2 V_34 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ )
V_32 [ V_4 ] = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_35 ; V_4 ++ ) {
struct V_14 * V_36 = & V_2 -> V_5 [ V_4 ] ;
V_34 = V_36 -> V_37 ;
if ( ! V_34 )
V_34 = 1000000 ;
if ( F_8 ( V_36 -> V_38 > 0 ) ) {
V_36 -> V_39 = 0 ;
V_36 -> V_40 = F_9 ( V_36 -> V_41 , V_36 -> V_38 ) ;
V_36 -> V_42 += V_36 -> V_41 ;
V_36 -> V_43 += V_36 -> V_38 ;
V_36 -> V_44 = F_10 ( V_36 -> V_44 ,
V_36 -> V_40 ,
V_45 ) ;
} else
V_36 -> V_39 ++ ;
V_36 -> V_46 = V_36 -> V_41 ;
V_36 -> V_47 = V_36 -> V_38 ;
V_36 -> V_41 = 0 ;
V_36 -> V_38 = 0 ;
if ( V_36 -> V_44 < F_9 ( 10 , 100 ) )
V_36 -> V_9 = 0 ;
else
V_36 -> V_9 = V_36 -> V_44 * ( 1000000 / V_34 ) ;
if ( V_36 -> V_44 > F_9 ( 95 , 100 ) ||
V_36 -> V_44 < F_9 ( 10 , 100 ) ) {
V_36 -> V_17 = V_36 -> V_48 >> 1 ;
if ( V_36 -> V_17 > 2 )
V_36 -> V_17 = 2 ;
V_36 -> V_49 = 4 ;
} else {
V_36 -> V_49 = - 1 ;
V_36 -> V_17 = V_36 -> V_48 ;
}
if ( ! V_36 -> V_17 )
V_36 -> V_17 = 2 ;
F_2 ( V_2 , V_4 , V_32 ) ;
if ( V_36 -> V_44 >= F_9 ( 95 , 100 ) ) {
if ( V_36 -> V_9 >= V_2 -> V_5 [ V_33 ] . V_9 )
V_33 = V_4 ;
} else {
if ( V_36 -> V_44 >= V_2 -> V_5 [ V_33 ] . V_44 )
V_33 = V_4 ;
}
}
memcpy ( V_2 -> V_25 , V_32 , sizeof( V_2 -> V_25 ) ) ;
V_2 -> V_28 = V_33 ;
V_2 -> V_50 = V_51 ;
F_4 ( V_23 , V_2 ) ;
}
static void
F_11 ( void * V_52 , struct V_53 * V_54 ,
struct V_55 * V_31 , void * V_56 ,
struct V_57 * V_58 )
{
struct V_22 * V_23 = V_52 ;
struct V_1 * V_2 = V_56 ;
struct V_59 * V_60 = F_12 ( V_58 ) ;
struct V_61 * V_62 = V_60 -> V_63 . V_64 ;
int V_4 , V_65 ;
int V_41 ;
V_41 = ! ! ( V_60 -> V_66 & V_67 ) ;
for ( V_4 = 0 ; V_4 < V_68 ; V_4 ++ ) {
if ( V_62 [ V_4 ] . V_13 < 0 )
break;
V_65 = F_1 ( V_2 , V_62 [ V_4 ] . V_13 ) ;
if ( V_65 < 0 )
continue;
V_2 -> V_5 [ V_65 ] . V_38 += V_62 [ V_4 ] . V_16 ;
if ( ( V_4 != V_68 - 1 ) && ( V_62 [ V_4 + 1 ] . V_13 < 0 ) )
V_2 -> V_5 [ V_65 ] . V_41 += V_41 ;
}
if ( ( V_60 -> V_66 & V_69 ) && ( V_4 >= 0 ) )
V_2 -> V_70 ++ ;
if ( V_2 -> V_71 > 0 )
V_2 -> V_71 -- ;
if ( F_13 ( V_51 , V_2 -> V_50 +
( V_23 -> V_72 * V_73 ) / 1000 ) )
F_7 ( V_23 , V_2 ) ;
}
static inline unsigned int
F_14 ( struct V_14 * V_36 ,
struct V_59 * V_60 )
{
unsigned int V_74 = V_36 -> V_17 ;
if ( V_60 -> V_75 . V_76 )
V_74 = F_15 ( 2U , F_16 ( V_36 -> V_21 , V_74 ) ) ;
else if ( V_60 -> V_75 . V_77 )
V_74 = F_15 ( 2U , F_16 ( V_36 -> V_19 , V_74 ) ) ;
return V_74 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
unsigned int V_78 ;
V_78 = F_18 ( V_2 , V_2 -> V_79 , V_2 -> V_80 ) ;
V_2 -> V_79 ++ ;
if ( ( int ) V_2 -> V_79 >= V_2 -> V_35 ) {
V_2 -> V_79 = 0 ;
V_2 -> V_80 ++ ;
if ( V_2 -> V_80 >= V_81 )
V_2 -> V_80 = 0 ;
}
return V_78 ;
}
static void
F_19 ( void * V_52 , struct V_55 * V_31 ,
void * V_56 , struct V_82 * V_83 )
{
struct V_57 * V_58 = V_83 -> V_58 ;
struct V_59 * V_60 = F_12 ( V_58 ) ;
struct V_1 * V_2 = V_56 ;
struct V_22 * V_23 = V_52 ;
struct V_61 * V_15 = & V_60 -> V_75 . V_64 [ 0 ] ;
struct V_14 * V_84 , * V_36 ;
unsigned int V_65 ;
bool V_85 ;
bool V_86 ;
int V_87 ;
int V_88 ;
if ( F_20 ( V_31 , V_56 , V_83 ) )
return;
V_85 = V_23 -> V_89 &&
! V_83 -> V_90 &&
! V_83 -> V_91 -> V_77 ;
if ( V_85 )
V_88 = V_23 -> V_92 ;
else
V_88 = V_23 -> V_93 ;
V_2 -> V_94 ++ ;
V_87 = ( V_2 -> V_94 * V_88 / 100 ) -
( V_2 -> V_70 + V_2 -> V_71 / 2 ) ;
V_86 = V_2 -> V_86 ;
V_2 -> V_86 = false ;
if ( V_87 < 0 || ( ! V_85 && V_86 ) )
return;
if ( V_2 -> V_94 >= 10000 ) {
V_2 -> V_71 = 0 ;
V_2 -> V_70 = 0 ;
V_2 -> V_94 = 0 ;
} else if ( V_87 > V_2 -> V_35 * 2 ) {
V_2 -> V_70 += ( V_87 - V_2 -> V_35 * 2 ) ;
}
V_65 = F_17 ( V_2 ) ;
V_84 = & V_2 -> V_5 [ V_65 ] ;
V_36 = & V_2 -> V_5 [ V_2 -> V_25 [ 0 ] ] ;
if ( V_85 &&
V_84 -> V_37 > V_36 -> V_37 &&
V_84 -> V_39 < 20 ) {
V_60 -> V_66 |= V_69 ;
V_15 ++ ;
V_2 -> V_71 ++ ;
} else {
if ( ! V_84 -> V_49 != 0 )
return;
V_2 -> V_70 ++ ;
if ( V_84 -> V_49 > 0 )
V_84 -> V_49 -- ;
}
if ( ! V_85 &&
( V_2 -> V_5 [ V_65 ] . V_44 > F_9 ( 95 , 100 ) ) )
return;
V_2 -> V_86 = true ;
V_15 -> V_13 = V_2 -> V_5 [ V_65 ] . V_3 ;
V_15 -> V_16 = F_14 ( & V_2 -> V_5 [ V_65 ] , V_60 ) ;
}
static void
F_21 ( enum V_95 V_96 ,
struct V_14 * V_97 ,
struct V_98 * V_15 ,
struct V_99 * V_100 )
{
int V_101 = ! ! ( V_15 -> V_66 & V_102 ) ;
int V_103 = F_22 ( V_100 ) ;
V_97 -> V_37 = F_23 ( V_96 , 1200 ,
F_24 ( V_15 -> V_104 , 1 << V_103 ) , V_101 , 1 ,
V_103 ) ;
V_97 -> V_105 = F_23 ( V_96 , 10 ,
F_24 ( V_15 -> V_104 , 1 << V_103 ) , V_101 , 1 ,
V_103 ) ;
}
static void
F_25 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_106 , V_107 ;
T_1 V_108 [ 8 ] ;
V_2 -> V_80 = 0 ;
V_2 -> V_79 = 0 ;
memset ( V_2 -> V_109 , 0xff , V_81 * V_2 -> V_35 ) ;
for ( V_106 = 0 ; V_106 < V_81 ; V_106 ++ ) {
for ( V_4 = 0 ; V_4 < V_2 -> V_35 ; V_4 ++ ) {
F_26 ( V_108 , sizeof( V_108 ) ) ;
V_107 = ( V_4 + V_108 [ V_4 & 7 ] ) % V_2 -> V_35 ;
while ( F_18 ( V_2 , V_107 , V_106 ) != 0xff )
V_107 = ( V_107 + 1 ) % V_2 -> V_35 ;
F_18 ( V_2 , V_107 , V_106 ) = V_4 ;
}
}
}
static void
F_27 ( void * V_52 , struct V_53 * V_54 ,
struct V_99 * V_100 ,
struct V_55 * V_31 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_22 * V_23 = V_52 ;
struct V_98 * V_110 ;
unsigned int V_4 , V_111 = 0 ;
unsigned int V_112 = 9 ;
T_2 V_113 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_29 = F_28 ( V_54 , V_31 ) ;
V_110 = & V_54 -> V_114 [ V_2 -> V_29 ] ;
V_2 -> V_115 = F_23 ( V_54 -> V_96 , 10 ,
V_110 -> V_104 ,
! ! ( V_110 -> V_66 & V_102 ) , 1 ,
F_22 ( V_100 ) ) ;
V_113 = F_29 ( & V_23 -> V_26 -> V_116 . V_100 ) ;
memset ( V_2 -> V_25 , 0 , sizeof( V_2 -> V_25 ) ) ;
V_2 -> V_28 = 0 ;
for ( V_4 = 0 ; V_4 < V_54 -> V_117 ; V_4 ++ ) {
struct V_14 * V_36 = & V_2 -> V_5 [ V_111 ] ;
unsigned int V_118 = 0 , V_119 = 0 , V_120 = 0 ;
unsigned int V_121 ;
unsigned int V_122 = V_23 -> V_123 ;
int V_103 ;
if ( ! F_30 ( V_31 , V_54 -> V_96 , V_4 ) )
continue;
if ( ( V_113 & V_54 -> V_114 [ V_4 ] . V_66 ) != V_113 )
continue;
V_111 ++ ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_3 = V_4 ;
V_103 = F_22 ( V_100 ) ;
V_36 -> V_104 = F_24 ( V_54 -> V_114 [ V_4 ] . V_104 ,
( 1 << V_103 ) * 5 ) ;
F_21 ( V_54 -> V_96 , V_36 , & V_54 -> V_114 [ V_4 ] ,
V_100 ) ;
V_36 -> V_49 = - 1 ;
V_36 -> V_48 = 1 ;
V_36 -> V_19 = 1 ;
V_36 -> V_21 = 1 ;
V_118 = V_36 -> V_37 + V_2 -> V_115 ;
do {
V_121 = V_36 -> V_105 + V_36 -> V_37 ;
V_121 += ( V_112 * V_122 ) >> 1 ;
V_122 = F_16 ( ( V_122 << 1 ) | 1 , V_23 -> V_124 ) ;
V_118 += V_121 ;
V_119 += V_121 + V_2 -> V_115 ;
V_120 += V_121 + 2 * V_2 -> V_115 ;
if ( ( V_119 < V_23 -> V_125 ) &&
( V_36 -> V_19 < V_23 -> V_30 ) )
V_36 -> V_19 ++ ;
if ( ( V_120 < V_23 -> V_125 ) &&
( V_36 -> V_21 < V_23 -> V_30 ) )
V_36 -> V_21 ++ ;
} while ( ( V_118 < V_23 -> V_125 ) &&
( ++ V_36 -> V_48 < V_23 -> V_30 ) );
V_36 -> V_17 = V_36 -> V_48 ;
if ( ! ( V_54 -> V_114 [ V_4 ] . V_66 & V_102 ) )
V_36 -> V_19 = V_36 -> V_48 ;
}
for ( V_4 = V_111 ; V_4 < V_54 -> V_117 ; V_4 ++ ) {
struct V_14 * V_36 = & V_2 -> V_5 [ V_4 ] ;
V_36 -> V_3 = - 1 ;
}
V_2 -> V_35 = V_111 ;
V_2 -> V_50 = V_51 ;
F_25 ( V_2 ) ;
F_4 ( V_23 , V_2 ) ;
}
static void *
F_31 ( void * V_52 , struct V_55 * V_31 , T_3 V_126 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_22 * V_23 = V_52 ;
struct V_127 * V_26 = V_23 -> V_26 ;
int V_27 = 0 ;
int V_4 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_126 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_128 ; V_4 ++ ) {
V_54 = V_26 -> V_129 -> V_130 [ V_4 ] ;
if ( V_54 && V_54 -> V_117 > V_27 )
V_27 = V_54 -> V_117 ;
}
V_2 -> V_5 = F_5 ( sizeof( struct V_14 ) * V_27 , V_126 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_109 = F_32 ( V_81 * V_27 , V_126 ) ;
if ( ! V_2 -> V_109 )
goto V_131;
V_2 -> V_50 = V_51 ;
return V_2 ;
V_131:
F_33 ( V_2 -> V_5 ) ;
error:
F_33 ( V_2 ) ;
return NULL ;
}
static void
F_34 ( void * V_52 , struct V_55 * V_31 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
F_33 ( V_2 -> V_109 ) ;
F_33 ( V_2 -> V_5 ) ;
F_33 ( V_2 ) ;
}
static void
F_35 ( struct V_22 * V_23 )
{
static const int V_114 [ 4 ] = { 10 , 20 , 55 , 110 } ;
struct V_53 * V_54 ;
T_2 V_113 = F_29 ( & V_23 -> V_26 -> V_116 . V_100 ) ;
int V_4 , V_7 ;
V_54 = V_23 -> V_26 -> V_129 -> V_130 [ V_132 ] ;
if ( ! V_54 )
return;
for ( V_4 = 0 , V_7 = 0 ; V_4 < V_54 -> V_117 ; V_4 ++ ) {
struct V_98 * V_15 = & V_54 -> V_114 [ V_4 ] ;
if ( V_15 -> V_66 & V_102 )
continue;
if ( ( V_113 & V_54 -> V_114 [ V_4 ] . V_66 ) != V_113 )
continue;
for ( V_7 = 0 ; V_7 < F_36 ( V_114 ) ; V_7 ++ ) {
if ( V_15 -> V_104 != V_114 [ V_7 ] )
continue;
V_23 -> V_133 [ V_7 ] = V_4 ;
break;
}
}
}
static void *
F_37 ( struct V_127 * V_26 , struct V_134 * V_135 )
{
struct V_22 * V_23 ;
V_23 = F_5 ( sizeof( struct V_22 ) , V_24 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_123 = 15 ;
V_23 -> V_124 = 1023 ;
V_23 -> V_93 = 5 ;
V_23 -> V_92 = 10 ;
V_23 -> V_125 = 6000 ;
if ( V_26 -> V_136 > 0 )
V_23 -> V_30 = V_26 -> V_136 ;
else
V_23 -> V_30 = 7 ;
if ( V_26 -> V_27 >= 4 )
V_23 -> V_89 = true ;
V_23 -> V_26 = V_26 ;
V_23 -> V_72 = 100 ;
#ifdef F_38
V_23 -> V_137 = ( T_2 ) - 1 ;
V_23 -> V_138 = F_39 ( L_1 ,
V_139 | V_140 , V_135 , & V_23 -> V_137 ) ;
#endif
F_35 ( V_23 ) ;
return V_23 ;
}
static void
F_40 ( void * V_52 )
{
#ifdef F_38
F_41 ( ( (struct V_22 * ) V_52 ) -> V_138 ) ;
#endif
F_33 ( V_52 ) ;
}
int T_4
F_42 ( void )
{
return F_43 ( & V_141 ) ;
}
void
F_44 ( void )
{
F_45 ( & V_141 ) ;
}
