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
while ( V_7 > 0 && V_2 -> V_5 [ V_4 ] . V_9 . V_10 > V_2 -> V_5 [ V_6 [ V_7 - 1 ] ] . V_9 . V_10 )
V_7 -- ;
if ( V_7 < V_8 - 1 )
memmove ( & V_6 [ V_7 + 1 ] , & V_6 [ V_7 ] , V_8 - ( V_7 + 1 ) ) ;
if ( V_7 < V_8 )
V_6 [ V_7 ] = V_4 ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_13 , int V_14 )
{
struct V_15 * V_5 = & V_2 -> V_5 [ V_14 ] ;
V_12 -> V_16 [ V_13 ] . V_14 = V_5 -> V_3 ;
V_12 -> V_16 [ V_13 ] . V_17 = V_5 -> V_18 ;
V_12 -> V_16 [ V_13 ] . V_19 = V_5 -> V_20 ;
V_12 -> V_16 [ V_13 ] . V_21 = V_5 -> V_9 . V_22 ;
}
static void
F_4 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
struct V_11 * V_12 ;
int V_4 = 0 ;
V_12 = F_5 ( sizeof( * V_12 ) , V_25 ) ;
if ( ! V_12 )
return;
F_3 ( V_2 , V_12 , V_4 ++ , V_2 -> V_26 [ 0 ] ) ;
if ( V_24 -> V_27 -> V_28 >= 3 ) {
F_3 ( V_2 , V_12 , V_4 ++ , V_2 -> V_26 [ 1 ] ) ;
}
if ( V_24 -> V_27 -> V_28 >= 2 ) {
F_3 ( V_2 , V_12 , V_4 ++ , V_2 -> V_29 ) ;
}
V_12 -> V_16 [ V_4 ] . V_14 = V_2 -> V_30 ;
V_12 -> V_16 [ V_4 ] . V_17 = V_24 -> V_31 ;
V_12 -> V_16 [ V_4 ] . V_19 = V_24 -> V_31 ;
V_12 -> V_16 [ V_4 ] . V_21 = V_24 -> V_31 ;
F_6 ( V_24 -> V_27 , V_2 -> V_32 , V_12 ) ;
}
static void
F_7 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
T_1 V_33 [ V_8 ] ;
T_1 V_34 = 0 ;
T_2 V_35 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ )
V_33 [ V_4 ] = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_36 ; V_4 ++ ) {
struct V_15 * V_37 = & V_2 -> V_5 [ V_4 ] ;
struct V_38 * V_39 = & V_2 -> V_5 [ V_4 ] . V_9 ;
V_35 = V_37 -> V_40 ;
if ( ! V_35 )
V_35 = 1000000 ;
if ( F_8 ( V_39 -> V_41 > 0 ) ) {
V_39 -> V_42 = 0 ;
V_39 -> V_43 = F_9 ( V_39 -> V_44 ,
V_39 -> V_41 ) ;
V_39 -> V_45 += V_39 -> V_44 ;
V_39 -> V_46 += V_39 -> V_41 ;
V_39 -> V_47 = F_10 ( V_39 -> V_47 ,
V_39 -> V_43 ,
V_48 ) ;
} else
V_39 -> V_42 ++ ;
V_39 -> V_49 = V_39 -> V_44 ;
V_39 -> V_50 = V_39 -> V_41 ;
V_39 -> V_44 = 0 ;
V_39 -> V_41 = 0 ;
if ( V_39 -> V_47 < F_9 ( 10 , 100 ) )
V_39 -> V_10 = 0 ;
else
V_39 -> V_10 = V_39 -> V_47 * ( 1000000 / V_35 ) ;
if ( V_39 -> V_47 > F_9 ( 95 , 100 ) ||
V_39 -> V_47 < F_9 ( 10 , 100 ) ) {
V_37 -> V_18 = V_39 -> V_51 >> 1 ;
if ( V_37 -> V_18 > 2 )
V_37 -> V_18 = 2 ;
V_37 -> V_52 = 4 ;
} else {
V_37 -> V_52 = - 1 ;
V_37 -> V_18 = V_39 -> V_51 ;
}
if ( ! V_37 -> V_18 )
V_37 -> V_18 = 2 ;
F_2 ( V_2 , V_4 , V_33 ) ;
if ( V_39 -> V_47 >= F_9 ( 95 , 100 ) ) {
if ( V_39 -> V_10 >= V_2 -> V_5 [ V_34 ] . V_9 . V_10 )
V_34 = V_4 ;
} else {
if ( V_39 -> V_47 >= V_2 -> V_5 [ V_34 ] . V_9 . V_47 )
V_34 = V_4 ;
}
}
memcpy ( V_2 -> V_26 , V_33 , sizeof( V_2 -> V_26 ) ) ;
V_2 -> V_29 = V_34 ;
#ifdef F_11
if ( V_24 -> V_53 != - 1 ) {
V_2 -> V_26 [ 0 ] = V_24 -> V_53 ;
V_2 -> V_26 [ 1 ] = V_24 -> V_53 ;
V_2 -> V_29 = V_24 -> V_53 ;
}
#endif
V_2 -> V_54 = V_55 ;
F_4 ( V_24 , V_2 ) ;
}
static void
F_12 ( void * V_56 , struct V_57 * V_58 ,
struct V_59 * V_32 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_23 * V_24 = V_56 ;
struct V_1 * V_2 = V_60 ;
struct V_63 * V_64 = V_62 -> V_65 . V_66 ;
int V_4 , V_67 ;
int V_44 ;
V_44 = ! ! ( V_62 -> V_68 & V_69 ) ;
for ( V_4 = 0 ; V_4 < V_70 ; V_4 ++ ) {
if ( V_64 [ V_4 ] . V_14 < 0 )
break;
V_67 = F_1 ( V_2 , V_64 [ V_4 ] . V_14 ) ;
if ( V_67 < 0 )
continue;
V_2 -> V_5 [ V_67 ] . V_9 . V_41 += V_64 [ V_4 ] . V_17 ;
if ( ( V_4 != V_70 - 1 ) && ( V_64 [ V_4 + 1 ] . V_14 < 0 ) )
V_2 -> V_5 [ V_67 ] . V_9 . V_44 += V_44 ;
}
if ( ( V_62 -> V_68 & V_71 ) && ( V_4 >= 0 ) )
V_2 -> V_72 ++ ;
if ( V_2 -> V_73 > 0 )
V_2 -> V_73 -- ;
if ( F_13 ( V_55 , V_2 -> V_54 +
( V_24 -> V_74 * V_75 ) / 1000 ) )
F_7 ( V_24 , V_2 ) ;
}
static inline unsigned int
F_14 ( struct V_15 * V_37 ,
struct V_61 * V_62 )
{
unsigned int V_76 = V_37 -> V_18 ;
if ( V_62 -> V_77 . V_78 )
V_76 = F_15 ( 2U , F_16 ( V_37 -> V_9 . V_22 , V_76 ) ) ;
else if ( V_62 -> V_77 . V_79 )
V_76 = F_15 ( 2U , F_16 ( V_37 -> V_20 , V_76 ) ) ;
return V_76 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
unsigned int V_80 ;
V_80 = F_18 ( V_2 , V_2 -> V_81 , V_2 -> V_82 ) ;
V_2 -> V_81 ++ ;
if ( ( int ) V_2 -> V_81 >= V_2 -> V_36 ) {
V_2 -> V_81 = 0 ;
V_2 -> V_82 ++ ;
if ( V_2 -> V_82 >= V_83 )
V_2 -> V_82 = 0 ;
}
return V_80 ;
}
static void
F_19 ( void * V_56 , struct V_59 * V_32 ,
void * V_60 , struct V_84 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_87 ;
struct V_61 * V_62 = F_20 ( V_87 ) ;
struct V_1 * V_2 = V_60 ;
struct V_23 * V_24 = V_56 ;
struct V_63 * V_16 = & V_62 -> V_77 . V_66 [ 0 ] ;
struct V_15 * V_88 , * V_37 ;
unsigned int V_67 ;
bool V_89 ;
bool V_90 ;
int V_91 ;
int V_92 ;
if ( F_21 ( V_32 , V_60 , V_85 ) )
return;
V_89 = V_24 -> V_93 &&
! V_85 -> V_94 &&
! V_85 -> V_95 -> V_79 ;
if ( V_89 )
V_92 = V_24 -> V_96 ;
else
V_92 = V_24 -> V_97 ;
V_2 -> V_98 ++ ;
#ifdef F_11
if ( V_24 -> V_53 != - 1 )
return;
#endif
V_91 = ( V_2 -> V_98 * V_92 / 100 ) -
( V_2 -> V_72 + V_2 -> V_73 / 2 ) ;
V_90 = V_2 -> V_90 ;
V_2 -> V_90 = false ;
if ( V_91 < 0 || ( ! V_89 && V_90 ) )
return;
if ( V_2 -> V_98 >= 10000 ) {
V_2 -> V_73 = 0 ;
V_2 -> V_72 = 0 ;
V_2 -> V_98 = 0 ;
} else if ( V_91 > V_2 -> V_36 * 2 ) {
V_2 -> V_72 += ( V_91 - V_2 -> V_36 * 2 ) ;
}
V_67 = F_17 ( V_2 ) ;
V_88 = & V_2 -> V_5 [ V_67 ] ;
V_37 = & V_2 -> V_5 [ V_2 -> V_26 [ 0 ] ] ;
if ( V_89 &&
V_88 -> V_40 > V_37 -> V_40 &&
V_88 -> V_9 . V_42 < 20 ) {
V_62 -> V_68 |= V_71 ;
V_16 ++ ;
V_2 -> V_73 ++ ;
} else {
if ( ! V_88 -> V_52 != 0 )
return;
V_2 -> V_72 ++ ;
if ( V_88 -> V_52 > 0 )
V_88 -> V_52 -- ;
}
if ( ! V_89 &&
( V_2 -> V_5 [ V_67 ] . V_9 . V_47 > F_9 ( 95 , 100 ) ) )
return;
V_2 -> V_90 = true ;
V_16 -> V_14 = V_2 -> V_5 [ V_67 ] . V_3 ;
V_16 -> V_17 = F_14 ( & V_2 -> V_5 [ V_67 ] , V_62 ) ;
}
static void
F_22 ( enum V_99 V_100 ,
struct V_15 * V_101 ,
struct V_102 * V_16 ,
struct V_103 * V_104 )
{
int V_105 = ! ! ( V_16 -> V_68 & V_106 ) ;
int V_107 = F_23 ( V_104 ) ;
V_101 -> V_40 = F_24 ( V_100 , 1200 ,
F_25 ( V_16 -> V_108 , 1 << V_107 ) , V_105 , 1 ,
V_107 ) ;
V_101 -> V_109 = F_24 ( V_100 , 10 ,
F_25 ( V_16 -> V_108 , 1 << V_107 ) , V_105 , 1 ,
V_107 ) ;
}
static void
F_26 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_110 , V_111 ;
T_1 V_112 [ 8 ] ;
V_2 -> V_82 = 0 ;
V_2 -> V_81 = 0 ;
memset ( V_2 -> V_113 , 0xff , V_83 * V_2 -> V_36 ) ;
for ( V_110 = 0 ; V_110 < V_83 ; V_110 ++ ) {
F_27 ( V_112 , sizeof( V_112 ) ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_36 ; V_4 ++ ) {
V_111 = ( V_4 + V_112 [ V_4 & 7 ] ) % V_2 -> V_36 ;
while ( F_18 ( V_2 , V_111 , V_110 ) != 0xff )
V_111 = ( V_111 + 1 ) % V_2 -> V_36 ;
F_18 ( V_2 , V_111 , V_110 ) = V_4 ;
}
}
}
static void
F_28 ( void * V_56 , struct V_57 * V_58 ,
struct V_103 * V_104 ,
struct V_59 * V_32 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
struct V_23 * V_24 = V_56 ;
struct V_102 * V_114 ;
unsigned int V_4 , V_115 = 0 ;
unsigned int V_116 = 9 ;
T_2 V_117 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_30 = F_29 ( V_58 , V_32 ) ;
V_114 = & V_58 -> V_118 [ V_2 -> V_30 ] ;
V_2 -> V_119 = F_24 ( V_58 -> V_100 , 10 ,
V_114 -> V_108 ,
! ! ( V_114 -> V_68 & V_106 ) , 1 ,
F_23 ( V_104 ) ) ;
V_117 = F_30 ( & V_24 -> V_27 -> V_120 . V_104 ) ;
memset ( V_2 -> V_26 , 0 , sizeof( V_2 -> V_26 ) ) ;
V_2 -> V_29 = 0 ;
for ( V_4 = 0 ; V_4 < V_58 -> V_121 ; V_4 ++ ) {
struct V_15 * V_37 = & V_2 -> V_5 [ V_115 ] ;
struct V_38 * V_39 = & V_2 -> V_5 [ V_115 ] . V_9 ;
unsigned int V_122 = 0 , V_123 = 0 , V_124 = 0 ;
unsigned int V_125 ;
unsigned int V_126 = V_24 -> V_127 ;
int V_107 ;
if ( ! F_31 ( V_32 , V_58 -> V_100 , V_4 ) )
continue;
if ( ( V_117 & V_58 -> V_118 [ V_4 ] . V_68 ) != V_117 )
continue;
V_115 ++ ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_37 -> V_3 = V_4 ;
V_107 = F_23 ( V_104 ) ;
V_37 -> V_108 = F_25 ( V_58 -> V_118 [ V_4 ] . V_108 ,
( 1 << V_107 ) * 5 ) ;
F_22 ( V_58 -> V_100 , V_37 , & V_58 -> V_118 [ V_4 ] ,
V_104 ) ;
V_37 -> V_52 = - 1 ;
V_39 -> V_51 = 1 ;
V_37 -> V_20 = 1 ;
V_39 -> V_22 = 1 ;
V_122 = V_37 -> V_40 + V_2 -> V_119 ;
do {
V_125 = V_37 -> V_109 + V_37 -> V_40 ;
V_125 += ( V_116 * V_126 ) >> 1 ;
V_126 = F_16 ( ( V_126 << 1 ) | 1 , V_24 -> V_128 ) ;
V_122 += V_125 ;
V_123 += V_125 + V_2 -> V_119 ;
V_124 += V_125 + 2 * V_2 -> V_119 ;
if ( ( V_123 < V_24 -> V_129 ) &&
( V_37 -> V_20 < V_24 -> V_31 ) )
V_37 -> V_20 ++ ;
if ( ( V_124 < V_24 -> V_129 ) &&
( V_39 -> V_22 < V_24 -> V_31 ) )
V_39 -> V_22 ++ ;
} while ( ( V_122 < V_24 -> V_129 ) &&
( ++ V_37 -> V_9 . V_51 < V_24 -> V_31 ) );
V_37 -> V_18 = V_39 -> V_51 ;
if ( ! ( V_58 -> V_118 [ V_4 ] . V_68 & V_106 ) )
V_37 -> V_20 = V_39 -> V_51 ;
}
for ( V_4 = V_115 ; V_4 < V_58 -> V_121 ; V_4 ++ ) {
struct V_15 * V_37 = & V_2 -> V_5 [ V_4 ] ;
V_37 -> V_3 = - 1 ;
}
V_2 -> V_36 = V_115 ;
V_2 -> V_54 = V_55 ;
F_26 ( V_2 ) ;
F_4 ( V_24 , V_2 ) ;
}
static void *
F_32 ( void * V_56 , struct V_59 * V_32 , T_3 V_130 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
struct V_23 * V_24 = V_56 ;
struct V_131 * V_27 = V_24 -> V_27 ;
int V_28 = 0 ;
int V_4 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_130 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_132 ; V_4 ++ ) {
V_58 = V_27 -> V_133 -> V_134 [ V_4 ] ;
if ( V_58 && V_58 -> V_121 > V_28 )
V_28 = V_58 -> V_121 ;
}
V_2 -> V_5 = F_5 ( sizeof( struct V_15 ) * V_28 , V_130 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_113 = F_33 ( V_83 * V_28 , V_130 ) ;
if ( ! V_2 -> V_113 )
goto V_135;
V_2 -> V_54 = V_55 ;
return V_2 ;
V_135:
F_34 ( V_2 -> V_5 ) ;
error:
F_34 ( V_2 ) ;
return NULL ;
}
static void
F_35 ( void * V_56 , struct V_59 * V_32 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
F_34 ( V_2 -> V_113 ) ;
F_34 ( V_2 -> V_5 ) ;
F_34 ( V_2 ) ;
}
static void
F_36 ( struct V_23 * V_24 )
{
static const int V_118 [ 4 ] = { 10 , 20 , 55 , 110 } ;
struct V_57 * V_58 ;
T_2 V_117 = F_30 ( & V_24 -> V_27 -> V_120 . V_104 ) ;
int V_4 , V_7 ;
V_58 = V_24 -> V_27 -> V_133 -> V_134 [ V_136 ] ;
if ( ! V_58 )
return;
for ( V_4 = 0 , V_7 = 0 ; V_4 < V_58 -> V_121 ; V_4 ++ ) {
struct V_102 * V_16 = & V_58 -> V_118 [ V_4 ] ;
if ( V_16 -> V_68 & V_106 )
continue;
if ( ( V_117 & V_58 -> V_118 [ V_4 ] . V_68 ) != V_117 )
continue;
for ( V_7 = 0 ; V_7 < F_37 ( V_118 ) ; V_7 ++ ) {
if ( V_16 -> V_108 != V_118 [ V_7 ] )
continue;
V_24 -> V_137 [ V_7 ] = V_4 ;
break;
}
}
}
static void *
F_38 ( struct V_131 * V_27 , struct V_138 * V_139 )
{
struct V_23 * V_24 ;
V_24 = F_5 ( sizeof( struct V_23 ) , V_25 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_127 = 15 ;
V_24 -> V_128 = 1023 ;
V_24 -> V_97 = 5 ;
V_24 -> V_96 = 10 ;
V_24 -> V_129 = 6000 ;
if ( V_27 -> V_140 > 0 )
V_24 -> V_31 = V_27 -> V_140 ;
else
V_24 -> V_31 = 7 ;
if ( V_27 -> V_28 >= 4 )
V_24 -> V_93 = true ;
V_24 -> V_27 = V_27 ;
V_24 -> V_74 = 100 ;
#ifdef F_11
V_24 -> V_53 = ( T_2 ) - 1 ;
V_24 -> V_141 = F_39 ( L_1 ,
V_142 | V_143 , V_139 , & V_24 -> V_53 ) ;
#endif
F_36 ( V_24 ) ;
return V_24 ;
}
static void
F_40 ( void * V_56 )
{
#ifdef F_11
F_41 ( ( (struct V_23 * ) V_56 ) -> V_141 ) ;
#endif
F_34 ( V_56 ) ;
}
static T_2 F_42 ( void * V_60 )
{
struct V_1 * V_2 = V_60 ;
int V_14 = V_2 -> V_26 [ 0 ] ;
return F_43 ( V_2 -> V_5 [ V_14 ] . V_9 . V_10 ) * 1200 * 8 / 1024 ;
}
int T_4
F_44 ( void )
{
return F_45 ( & V_144 ) ;
}
void
F_46 ( void )
{
F_47 ( & V_144 ) ;
}
