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
#ifdef F_11
if ( V_23 -> V_50 != - 1 ) {
V_2 -> V_25 [ 0 ] = V_23 -> V_50 ;
V_2 -> V_25 [ 1 ] = V_23 -> V_50 ;
V_2 -> V_28 = V_23 -> V_50 ;
}
#endif
V_2 -> V_51 = V_52 ;
F_4 ( V_23 , V_2 ) ;
}
static void
F_12 ( void * V_53 , struct V_54 * V_55 ,
struct V_56 * V_31 , void * V_57 ,
struct V_58 * V_59 )
{
struct V_22 * V_23 = V_53 ;
struct V_1 * V_2 = V_57 ;
struct V_60 * V_61 = F_13 ( V_59 ) ;
struct V_62 * V_63 = V_61 -> V_64 . V_65 ;
int V_4 , V_66 ;
int V_41 ;
V_41 = ! ! ( V_61 -> V_67 & V_68 ) ;
for ( V_4 = 0 ; V_4 < V_69 ; V_4 ++ ) {
if ( V_63 [ V_4 ] . V_13 < 0 )
break;
V_66 = F_1 ( V_2 , V_63 [ V_4 ] . V_13 ) ;
if ( V_66 < 0 )
continue;
V_2 -> V_5 [ V_66 ] . V_38 += V_63 [ V_4 ] . V_16 ;
if ( ( V_4 != V_69 - 1 ) && ( V_63 [ V_4 + 1 ] . V_13 < 0 ) )
V_2 -> V_5 [ V_66 ] . V_41 += V_41 ;
}
if ( ( V_61 -> V_67 & V_70 ) && ( V_4 >= 0 ) )
V_2 -> V_71 ++ ;
if ( V_2 -> V_72 > 0 )
V_2 -> V_72 -- ;
if ( F_14 ( V_52 , V_2 -> V_51 +
( V_23 -> V_73 * V_74 ) / 1000 ) )
F_7 ( V_23 , V_2 ) ;
}
static inline unsigned int
F_15 ( struct V_14 * V_36 ,
struct V_60 * V_61 )
{
unsigned int V_75 = V_36 -> V_17 ;
if ( V_61 -> V_76 . V_77 )
V_75 = F_16 ( 2U , F_17 ( V_36 -> V_21 , V_75 ) ) ;
else if ( V_61 -> V_76 . V_78 )
V_75 = F_16 ( 2U , F_17 ( V_36 -> V_19 , V_75 ) ) ;
return V_75 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
unsigned int V_79 ;
V_79 = F_19 ( V_2 , V_2 -> V_80 , V_2 -> V_81 ) ;
V_2 -> V_80 ++ ;
if ( ( int ) V_2 -> V_80 >= V_2 -> V_35 ) {
V_2 -> V_80 = 0 ;
V_2 -> V_81 ++ ;
if ( V_2 -> V_81 >= V_82 )
V_2 -> V_81 = 0 ;
}
return V_79 ;
}
static void
F_20 ( void * V_53 , struct V_56 * V_31 ,
void * V_57 , struct V_83 * V_84 )
{
struct V_58 * V_59 = V_84 -> V_59 ;
struct V_60 * V_61 = F_13 ( V_59 ) ;
struct V_1 * V_2 = V_57 ;
struct V_22 * V_23 = V_53 ;
struct V_62 * V_15 = & V_61 -> V_76 . V_65 [ 0 ] ;
struct V_14 * V_85 , * V_36 ;
unsigned int V_66 ;
bool V_86 ;
bool V_87 ;
int V_88 ;
int V_89 ;
if ( F_21 ( V_31 , V_57 , V_84 ) )
return;
V_86 = V_23 -> V_90 &&
! V_84 -> V_91 &&
! V_84 -> V_92 -> V_78 ;
if ( V_86 )
V_89 = V_23 -> V_93 ;
else
V_89 = V_23 -> V_94 ;
V_2 -> V_95 ++ ;
#ifdef F_11
if ( V_23 -> V_50 != - 1 )
return;
#endif
V_88 = ( V_2 -> V_95 * V_89 / 100 ) -
( V_2 -> V_71 + V_2 -> V_72 / 2 ) ;
V_87 = V_2 -> V_87 ;
V_2 -> V_87 = false ;
if ( V_88 < 0 || ( ! V_86 && V_87 ) )
return;
if ( V_2 -> V_95 >= 10000 ) {
V_2 -> V_72 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_95 = 0 ;
} else if ( V_88 > V_2 -> V_35 * 2 ) {
V_2 -> V_71 += ( V_88 - V_2 -> V_35 * 2 ) ;
}
V_66 = F_18 ( V_2 ) ;
V_85 = & V_2 -> V_5 [ V_66 ] ;
V_36 = & V_2 -> V_5 [ V_2 -> V_25 [ 0 ] ] ;
if ( V_86 &&
V_85 -> V_37 > V_36 -> V_37 &&
V_85 -> V_39 < 20 ) {
V_61 -> V_67 |= V_70 ;
V_15 ++ ;
V_2 -> V_72 ++ ;
} else {
if ( ! V_85 -> V_49 != 0 )
return;
V_2 -> V_71 ++ ;
if ( V_85 -> V_49 > 0 )
V_85 -> V_49 -- ;
}
if ( ! V_86 &&
( V_2 -> V_5 [ V_66 ] . V_44 > F_9 ( 95 , 100 ) ) )
return;
V_2 -> V_87 = true ;
V_15 -> V_13 = V_2 -> V_5 [ V_66 ] . V_3 ;
V_15 -> V_16 = F_15 ( & V_2 -> V_5 [ V_66 ] , V_61 ) ;
}
static void
F_22 ( enum V_96 V_97 ,
struct V_14 * V_98 ,
struct V_99 * V_15 ,
struct V_100 * V_101 )
{
int V_102 = ! ! ( V_15 -> V_67 & V_103 ) ;
int V_104 = F_23 ( V_101 ) ;
V_98 -> V_37 = F_24 ( V_97 , 1200 ,
F_25 ( V_15 -> V_105 , 1 << V_104 ) , V_102 , 1 ,
V_104 ) ;
V_98 -> V_106 = F_24 ( V_97 , 10 ,
F_25 ( V_15 -> V_105 , 1 << V_104 ) , V_102 , 1 ,
V_104 ) ;
}
static void
F_26 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_107 , V_108 ;
T_1 V_109 [ 8 ] ;
V_2 -> V_81 = 0 ;
V_2 -> V_80 = 0 ;
memset ( V_2 -> V_110 , 0xff , V_82 * V_2 -> V_35 ) ;
for ( V_107 = 0 ; V_107 < V_82 ; V_107 ++ ) {
F_27 ( V_109 , sizeof( V_109 ) ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_35 ; V_4 ++ ) {
V_108 = ( V_4 + V_109 [ V_4 & 7 ] ) % V_2 -> V_35 ;
while ( F_19 ( V_2 , V_108 , V_107 ) != 0xff )
V_108 = ( V_108 + 1 ) % V_2 -> V_35 ;
F_19 ( V_2 , V_108 , V_107 ) = V_4 ;
}
}
}
static void
F_28 ( void * V_53 , struct V_54 * V_55 ,
struct V_100 * V_101 ,
struct V_56 * V_31 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_22 * V_23 = V_53 ;
struct V_99 * V_111 ;
unsigned int V_4 , V_112 = 0 ;
unsigned int V_113 = 9 ;
T_2 V_114 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_29 = F_29 ( V_55 , V_31 ) ;
V_111 = & V_55 -> V_115 [ V_2 -> V_29 ] ;
V_2 -> V_116 = F_24 ( V_55 -> V_97 , 10 ,
V_111 -> V_105 ,
! ! ( V_111 -> V_67 & V_103 ) , 1 ,
F_23 ( V_101 ) ) ;
V_114 = F_30 ( & V_23 -> V_26 -> V_117 . V_101 ) ;
memset ( V_2 -> V_25 , 0 , sizeof( V_2 -> V_25 ) ) ;
V_2 -> V_28 = 0 ;
for ( V_4 = 0 ; V_4 < V_55 -> V_118 ; V_4 ++ ) {
struct V_14 * V_36 = & V_2 -> V_5 [ V_112 ] ;
unsigned int V_119 = 0 , V_120 = 0 , V_121 = 0 ;
unsigned int V_122 ;
unsigned int V_123 = V_23 -> V_124 ;
int V_104 ;
if ( ! F_31 ( V_31 , V_55 -> V_97 , V_4 ) )
continue;
if ( ( V_114 & V_55 -> V_115 [ V_4 ] . V_67 ) != V_114 )
continue;
V_112 ++ ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_3 = V_4 ;
V_104 = F_23 ( V_101 ) ;
V_36 -> V_105 = F_25 ( V_55 -> V_115 [ V_4 ] . V_105 ,
( 1 << V_104 ) * 5 ) ;
F_22 ( V_55 -> V_97 , V_36 , & V_55 -> V_115 [ V_4 ] ,
V_101 ) ;
V_36 -> V_49 = - 1 ;
V_36 -> V_48 = 1 ;
V_36 -> V_19 = 1 ;
V_36 -> V_21 = 1 ;
V_119 = V_36 -> V_37 + V_2 -> V_116 ;
do {
V_122 = V_36 -> V_106 + V_36 -> V_37 ;
V_122 += ( V_113 * V_123 ) >> 1 ;
V_123 = F_17 ( ( V_123 << 1 ) | 1 , V_23 -> V_125 ) ;
V_119 += V_122 ;
V_120 += V_122 + V_2 -> V_116 ;
V_121 += V_122 + 2 * V_2 -> V_116 ;
if ( ( V_120 < V_23 -> V_126 ) &&
( V_36 -> V_19 < V_23 -> V_30 ) )
V_36 -> V_19 ++ ;
if ( ( V_121 < V_23 -> V_126 ) &&
( V_36 -> V_21 < V_23 -> V_30 ) )
V_36 -> V_21 ++ ;
} while ( ( V_119 < V_23 -> V_126 ) &&
( ++ V_36 -> V_48 < V_23 -> V_30 ) );
V_36 -> V_17 = V_36 -> V_48 ;
if ( ! ( V_55 -> V_115 [ V_4 ] . V_67 & V_103 ) )
V_36 -> V_19 = V_36 -> V_48 ;
}
for ( V_4 = V_112 ; V_4 < V_55 -> V_118 ; V_4 ++ ) {
struct V_14 * V_36 = & V_2 -> V_5 [ V_4 ] ;
V_36 -> V_3 = - 1 ;
}
V_2 -> V_35 = V_112 ;
V_2 -> V_51 = V_52 ;
F_26 ( V_2 ) ;
F_4 ( V_23 , V_2 ) ;
}
static void *
F_32 ( void * V_53 , struct V_56 * V_31 , T_3 V_127 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 ;
struct V_22 * V_23 = V_53 ;
struct V_128 * V_26 = V_23 -> V_26 ;
int V_27 = 0 ;
int V_4 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_127 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_129 ; V_4 ++ ) {
V_55 = V_26 -> V_130 -> V_131 [ V_4 ] ;
if ( V_55 && V_55 -> V_118 > V_27 )
V_27 = V_55 -> V_118 ;
}
V_2 -> V_5 = F_5 ( sizeof( struct V_14 ) * V_27 , V_127 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_110 = F_33 ( V_82 * V_27 , V_127 ) ;
if ( ! V_2 -> V_110 )
goto V_132;
V_2 -> V_51 = V_52 ;
return V_2 ;
V_132:
F_34 ( V_2 -> V_5 ) ;
error:
F_34 ( V_2 ) ;
return NULL ;
}
static void
F_35 ( void * V_53 , struct V_56 * V_31 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
F_34 ( V_2 -> V_110 ) ;
F_34 ( V_2 -> V_5 ) ;
F_34 ( V_2 ) ;
}
static void
F_36 ( struct V_22 * V_23 )
{
static const int V_115 [ 4 ] = { 10 , 20 , 55 , 110 } ;
struct V_54 * V_55 ;
T_2 V_114 = F_30 ( & V_23 -> V_26 -> V_117 . V_101 ) ;
int V_4 , V_7 ;
V_55 = V_23 -> V_26 -> V_130 -> V_131 [ V_133 ] ;
if ( ! V_55 )
return;
for ( V_4 = 0 , V_7 = 0 ; V_4 < V_55 -> V_118 ; V_4 ++ ) {
struct V_99 * V_15 = & V_55 -> V_115 [ V_4 ] ;
if ( V_15 -> V_67 & V_103 )
continue;
if ( ( V_114 & V_55 -> V_115 [ V_4 ] . V_67 ) != V_114 )
continue;
for ( V_7 = 0 ; V_7 < F_37 ( V_115 ) ; V_7 ++ ) {
if ( V_15 -> V_105 != V_115 [ V_7 ] )
continue;
V_23 -> V_134 [ V_7 ] = V_4 ;
break;
}
}
}
static void *
F_38 ( struct V_128 * V_26 , struct V_135 * V_136 )
{
struct V_22 * V_23 ;
V_23 = F_5 ( sizeof( struct V_22 ) , V_24 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_124 = 15 ;
V_23 -> V_125 = 1023 ;
V_23 -> V_94 = 5 ;
V_23 -> V_93 = 10 ;
V_23 -> V_126 = 6000 ;
if ( V_26 -> V_137 > 0 )
V_23 -> V_30 = V_26 -> V_137 ;
else
V_23 -> V_30 = 7 ;
if ( V_26 -> V_27 >= 4 )
V_23 -> V_90 = true ;
V_23 -> V_26 = V_26 ;
V_23 -> V_73 = 100 ;
#ifdef F_11
V_23 -> V_50 = ( T_2 ) - 1 ;
V_23 -> V_138 = F_39 ( L_1 ,
V_139 | V_140 , V_136 , & V_23 -> V_50 ) ;
#endif
F_36 ( V_23 ) ;
return V_23 ;
}
static void
F_40 ( void * V_53 )
{
#ifdef F_11
F_41 ( ( (struct V_22 * ) V_53 ) -> V_138 ) ;
#endif
F_34 ( V_53 ) ;
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
