static inline int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 ;
for ( V_4 = V_3 ; V_4 >= 0 ; V_4 -- )
if ( V_2 -> V_5 [ V_4 ] . V_3 == V_3 )
break;
return V_4 ;
}
int F_2 ( struct V_6 * V_7 , int V_8 )
{
int V_9 ;
V_9 = V_7 -> V_10 ;
if ( ! V_9 )
V_9 = 1000000 ;
if ( V_7 -> V_11 . V_8 < F_3 ( 10 , 100 ) )
return 0 ;
if ( V_8 > F_3 ( 90 , 100 ) )
return F_4 ( 100000 * ( F_3 ( 90 , 100 ) / V_9 ) ) ;
else
return F_4 ( 100000 * ( V_8 / V_9 ) ) ;
}
static inline void
F_5 ( struct V_1 * V_2 , int V_4 , T_1 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_14 * V_16 = & V_2 -> V_5 [ V_4 ] . V_11 ;
for ( V_13 = V_17 ; V_13 > 0 ; -- V_13 ) {
V_15 = & V_2 -> V_5 [ V_12 [ V_13 - 1 ] ] . V_11 ;
if ( F_2 ( & V_2 -> V_5 [ V_4 ] , V_16 -> V_8 ) <=
F_2 ( & V_2 -> V_5 [ V_12 [ V_13 - 1 ] ] , V_15 -> V_8 ) )
break;
}
if ( V_13 < V_17 - 1 )
memmove ( & V_12 [ V_13 + 1 ] , & V_12 [ V_13 ] , V_17 - ( V_13 + 1 ) ) ;
if ( V_13 < V_17 )
V_12 [ V_13 ] = V_4 ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_20 , int V_21 )
{
struct V_6 * V_5 = & V_2 -> V_5 [ V_21 ] ;
V_19 -> V_22 [ V_20 ] . V_21 = V_5 -> V_3 ;
V_19 -> V_22 [ V_20 ] . V_23 = V_5 -> V_24 ;
V_19 -> V_22 [ V_20 ] . V_25 = V_5 -> V_26 ;
V_19 -> V_22 [ V_20 ] . V_27 = V_5 -> V_11 . V_28 ;
}
static void
F_7 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_18 * V_19 ;
int V_4 = 0 ;
V_19 = F_8 ( sizeof( * V_19 ) , V_31 ) ;
if ( ! V_19 )
return;
F_6 ( V_2 , V_19 , V_4 ++ , V_2 -> V_32 [ 0 ] ) ;
if ( V_30 -> V_33 -> V_34 >= 3 ) {
F_6 ( V_2 , V_19 , V_4 ++ , V_2 -> V_32 [ 1 ] ) ;
}
if ( V_30 -> V_33 -> V_34 >= 2 ) {
F_6 ( V_2 , V_19 , V_4 ++ , V_2 -> V_35 ) ;
}
V_19 -> V_22 [ V_4 ] . V_21 = V_2 -> V_36 ;
V_19 -> V_22 [ V_4 ] . V_23 = V_30 -> V_37 ;
V_19 -> V_22 [ V_4 ] . V_25 = V_30 -> V_37 ;
V_19 -> V_22 [ V_4 ] . V_27 = V_30 -> V_37 ;
F_9 ( V_30 -> V_33 , V_2 -> V_38 , V_19 ) ;
}
void
F_10 ( struct V_14 * V_39 )
{
if ( F_11 ( V_39 -> V_40 > 0 ) ) {
V_39 -> V_41 = 0 ;
V_39 -> V_42 = F_3 ( V_39 -> V_43 , V_39 -> V_40 ) ;
if ( F_11 ( ! V_39 -> V_44 ) ) {
V_39 -> V_8 = V_39 -> V_42 ;
} else {
V_39 -> V_45 = F_12 ( V_39 -> V_45 ,
V_39 -> V_42 ,
V_39 -> V_8 ,
V_46 ) ;
V_39 -> V_8 = F_13 ( V_39 -> V_8 ,
V_39 -> V_42 ,
V_46 ) ;
}
V_39 -> V_44 += V_39 -> V_40 ;
V_39 -> V_47 += V_39 -> V_43 ;
} else {
V_39 -> V_41 ++ ;
}
V_39 -> V_48 = V_39 -> V_43 ;
V_39 -> V_49 = V_39 -> V_40 ;
V_39 -> V_43 = 0 ;
V_39 -> V_40 = 0 ;
}
static void
F_14 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
T_1 V_50 [ V_17 ] ;
T_1 V_51 = 0 ;
int V_4 , V_52 , V_53 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
V_50 [ V_4 ] = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_54 ; V_4 ++ ) {
struct V_6 * V_7 = & V_2 -> V_5 [ V_4 ] ;
struct V_14 * V_39 = & V_2 -> V_5 [ V_4 ] . V_11 ;
struct V_14 * V_15 = & V_2 -> V_5 [ V_51 ] . V_11 ;
F_10 ( V_39 ) ;
if ( V_39 -> V_8 > F_3 ( 95 , 100 ) ||
V_39 -> V_8 < F_3 ( 10 , 100 ) ) {
V_7 -> V_24 = V_39 -> V_55 >> 1 ;
if ( V_7 -> V_24 > 2 )
V_7 -> V_24 = 2 ;
V_7 -> V_56 = 4 ;
} else {
V_7 -> V_56 = - 1 ;
V_7 -> V_24 = V_39 -> V_55 ;
}
if ( ! V_7 -> V_24 )
V_7 -> V_24 = 2 ;
F_5 ( V_2 , V_4 , V_50 ) ;
if ( V_39 -> V_8 >= F_3 ( 95 , 100 ) ) {
V_52 = F_2 ( V_7 , V_39 -> V_8 ) ;
V_53 = F_2 ( & V_2 -> V_5 [ V_51 ] ,
V_15 -> V_8 ) ;
if ( V_52 >= V_53 )
V_51 = V_4 ;
} else {
if ( V_39 -> V_8 >= V_15 -> V_8 )
V_51 = V_4 ;
}
}
memcpy ( V_2 -> V_32 , V_50 , sizeof( V_2 -> V_32 ) ) ;
V_2 -> V_35 = V_51 ;
#ifdef F_15
if ( V_30 -> V_57 != - 1 ) {
V_2 -> V_32 [ 0 ] = V_30 -> V_57 ;
V_2 -> V_32 [ 1 ] = V_30 -> V_57 ;
V_2 -> V_35 = V_30 -> V_57 ;
}
#endif
V_2 -> V_58 = V_59 ;
F_7 ( V_30 , V_2 ) ;
}
static void
F_16 ( void * V_60 , struct V_61 * V_62 ,
struct V_63 * V_38 , void * V_64 ,
struct V_65 * V_66 )
{
struct V_29 * V_30 = V_60 ;
struct V_1 * V_2 = V_64 ;
struct V_67 * V_68 = V_66 -> V_69 . V_70 ;
int V_4 , V_71 ;
int V_43 ;
V_43 = ! ! ( V_66 -> V_72 & V_73 ) ;
for ( V_4 = 0 ; V_4 < V_74 ; V_4 ++ ) {
if ( V_68 [ V_4 ] . V_21 < 0 )
break;
V_71 = F_1 ( V_2 , V_68 [ V_4 ] . V_21 ) ;
if ( V_71 < 0 )
continue;
V_2 -> V_5 [ V_71 ] . V_11 . V_40 += V_68 [ V_4 ] . V_23 ;
if ( ( V_4 != V_74 - 1 ) && ( V_68 [ V_4 + 1 ] . V_21 < 0 ) )
V_2 -> V_5 [ V_71 ] . V_11 . V_43 += V_43 ;
}
if ( ( V_66 -> V_72 & V_75 ) && ( V_4 >= 0 ) )
V_2 -> V_76 ++ ;
if ( V_2 -> V_77 > 0 )
V_2 -> V_77 -- ;
if ( F_17 ( V_59 , V_2 -> V_58 +
( V_30 -> V_78 * V_79 ) / 1000 ) )
F_14 ( V_30 , V_2 ) ;
}
static inline unsigned int
F_18 ( struct V_6 * V_7 ,
struct V_65 * V_66 )
{
T_1 V_80 = V_7 -> V_24 ;
if ( V_66 -> V_81 . V_82 )
V_80 = F_19 ( T_1 , 2 , F_20 ( V_7 -> V_11 . V_28 , V_80 ) ) ;
else if ( V_66 -> V_81 . V_83 )
V_80 = F_19 ( T_1 , 2 , F_20 ( V_7 -> V_26 , V_80 ) ) ;
return V_80 ;
}
static int
F_21 ( struct V_1 * V_2 )
{
unsigned int V_84 ;
V_84 = F_22 ( V_2 , V_2 -> V_85 , V_2 -> V_86 ) ;
V_2 -> V_85 ++ ;
if ( ( int ) V_2 -> V_85 >= V_2 -> V_54 ) {
V_2 -> V_85 = 0 ;
V_2 -> V_86 ++ ;
if ( V_2 -> V_86 >= V_87 )
V_2 -> V_86 = 0 ;
}
return V_84 ;
}
static void
F_23 ( void * V_60 , struct V_63 * V_38 ,
void * V_64 , struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_91 ;
struct V_65 * V_66 = F_24 ( V_91 ) ;
struct V_1 * V_2 = V_64 ;
struct V_29 * V_30 = V_60 ;
struct V_67 * V_22 = & V_66 -> V_81 . V_70 [ 0 ] ;
struct V_6 * V_92 , * V_7 ;
unsigned int V_71 ;
bool V_93 ;
bool V_94 ;
int V_95 ;
int V_96 ;
if ( F_25 ( V_38 , V_64 , V_89 ) )
return;
V_93 = V_30 -> V_97 &&
! V_89 -> V_98 &&
! V_89 -> V_99 -> V_83 ;
if ( V_93 )
V_96 = V_30 -> V_100 ;
else
V_96 = V_30 -> V_101 ;
V_2 -> V_102 ++ ;
#ifdef F_15
if ( V_30 -> V_57 != - 1 )
return;
#endif
V_95 = ( V_2 -> V_102 * V_96 / 100 ) -
( V_2 -> V_76 + V_2 -> V_77 / 2 ) ;
V_94 = V_2 -> V_94 ;
V_2 -> V_94 = false ;
if ( V_95 < 0 || ( ! V_93 && V_94 ) )
return;
if ( V_2 -> V_102 >= 10000 ) {
V_2 -> V_77 = 0 ;
V_2 -> V_76 = 0 ;
V_2 -> V_102 = 0 ;
} else if ( V_95 > V_2 -> V_54 * 2 ) {
V_2 -> V_76 += ( V_95 - V_2 -> V_54 * 2 ) ;
}
V_71 = F_21 ( V_2 ) ;
V_92 = & V_2 -> V_5 [ V_71 ] ;
V_7 = & V_2 -> V_5 [ V_2 -> V_32 [ 0 ] ] ;
if ( V_93 &&
V_92 -> V_10 > V_7 -> V_10 &&
V_92 -> V_11 . V_41 < 20 ) {
V_66 -> V_72 |= V_75 ;
V_22 ++ ;
V_2 -> V_77 ++ ;
} else {
if ( ! V_92 -> V_56 )
return;
V_2 -> V_76 ++ ;
if ( V_92 -> V_56 > 0 )
V_92 -> V_56 -- ;
}
if ( ! V_93 &&
( V_2 -> V_5 [ V_71 ] . V_11 . V_8 > F_3 ( 95 , 100 ) ) )
return;
V_2 -> V_94 = true ;
V_22 -> V_21 = V_2 -> V_5 [ V_71 ] . V_3 ;
V_22 -> V_23 = F_18 ( & V_2 -> V_5 [ V_71 ] , V_66 ) ;
}
static void
F_26 ( enum V_103 V_104 ,
struct V_6 * V_105 ,
struct V_106 * V_22 ,
struct V_107 * V_108 )
{
int V_109 = ! ! ( V_22 -> V_72 & V_110 ) ;
int V_111 = F_27 ( V_108 ) ;
V_105 -> V_10 = F_28 ( V_104 , 1200 ,
F_29 ( V_22 -> V_112 , 1 << V_111 ) , V_109 , 1 ,
V_111 ) ;
V_105 -> V_113 = F_28 ( V_104 , 10 ,
F_29 ( V_22 -> V_112 , 1 << V_111 ) , V_109 , 1 ,
V_111 ) ;
}
static void
F_30 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_114 , V_115 ;
T_1 V_116 [ 8 ] ;
V_2 -> V_86 = 0 ;
V_2 -> V_85 = 0 ;
memset ( V_2 -> V_117 , 0xff , V_87 * V_2 -> V_54 ) ;
for ( V_114 = 0 ; V_114 < V_87 ; V_114 ++ ) {
F_31 ( V_116 , sizeof( V_116 ) ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_54 ; V_4 ++ ) {
V_115 = ( V_4 + V_116 [ V_4 & 7 ] ) % V_2 -> V_54 ;
while ( F_22 ( V_2 , V_115 , V_114 ) != 0xff )
V_115 = ( V_115 + 1 ) % V_2 -> V_54 ;
F_22 ( V_2 , V_115 , V_114 ) = V_4 ;
}
}
}
static void
F_32 ( void * V_60 , struct V_61 * V_62 ,
struct V_107 * V_108 ,
struct V_63 * V_38 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
struct V_29 * V_30 = V_60 ;
struct V_106 * V_118 ;
unsigned int V_4 , V_119 = 0 ;
unsigned int V_120 = 9 ;
T_2 V_121 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_36 = F_33 ( V_62 , V_38 ) ;
V_118 = & V_62 -> V_122 [ V_2 -> V_36 ] ;
V_2 -> V_123 = F_28 ( V_62 -> V_104 , 10 ,
V_118 -> V_112 ,
! ! ( V_118 -> V_72 & V_110 ) , 1 ,
F_27 ( V_108 ) ) ;
V_121 = F_34 ( & V_30 -> V_33 -> V_124 . V_108 ) ;
memset ( V_2 -> V_32 , 0 , sizeof( V_2 -> V_32 ) ) ;
V_2 -> V_35 = 0 ;
for ( V_4 = 0 ; V_4 < V_62 -> V_125 ; V_4 ++ ) {
struct V_6 * V_7 = & V_2 -> V_5 [ V_119 ] ;
struct V_14 * V_39 = & V_2 -> V_5 [ V_119 ] . V_11 ;
unsigned int V_126 = 0 , V_127 = 0 , V_128 = 0 ;
unsigned int V_129 ;
unsigned int V_130 = V_30 -> V_131 ;
int V_111 ;
if ( ! F_35 ( V_38 , V_62 -> V_104 , V_4 ) )
continue;
if ( ( V_121 & V_62 -> V_122 [ V_4 ] . V_72 ) != V_121 )
continue;
V_119 ++ ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_7 -> V_3 = V_4 ;
V_111 = F_27 ( V_108 ) ;
V_7 -> V_112 = F_29 ( V_62 -> V_122 [ V_4 ] . V_112 ,
( 1 << V_111 ) * 5 ) ;
F_26 ( V_62 -> V_104 , V_7 , & V_62 -> V_122 [ V_4 ] ,
V_108 ) ;
V_7 -> V_56 = - 1 ;
V_39 -> V_55 = 1 ;
V_7 -> V_26 = 1 ;
V_39 -> V_28 = 1 ;
V_126 = V_7 -> V_10 + V_2 -> V_123 ;
do {
V_129 = V_7 -> V_113 + V_7 -> V_10 ;
V_129 += ( V_120 * V_130 ) >> 1 ;
V_130 = F_20 ( ( V_130 << 1 ) | 1 , V_30 -> V_132 ) ;
V_126 += V_129 ;
V_127 += V_129 + V_2 -> V_123 ;
V_128 += V_129 + 2 * V_2 -> V_123 ;
if ( ( V_127 < V_30 -> V_133 ) &&
( V_7 -> V_26 < V_30 -> V_37 ) )
V_7 -> V_26 ++ ;
if ( ( V_128 < V_30 -> V_133 ) &&
( V_39 -> V_28 < V_30 -> V_37 ) )
V_39 -> V_28 ++ ;
} while ( ( V_126 < V_30 -> V_133 ) &&
( ++ V_7 -> V_11 . V_55 < V_30 -> V_37 ) );
V_7 -> V_24 = V_39 -> V_55 ;
if ( ! ( V_62 -> V_122 [ V_4 ] . V_72 & V_110 ) )
V_7 -> V_26 = V_39 -> V_55 ;
}
for ( V_4 = V_119 ; V_4 < V_62 -> V_125 ; V_4 ++ ) {
struct V_6 * V_7 = & V_2 -> V_5 [ V_4 ] ;
V_7 -> V_3 = - 1 ;
}
V_2 -> V_54 = V_119 ;
V_2 -> V_58 = V_59 ;
F_30 ( V_2 ) ;
F_7 ( V_30 , V_2 ) ;
}
static void *
F_36 ( void * V_60 , struct V_63 * V_38 , T_3 V_134 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 ;
struct V_29 * V_30 = V_60 ;
struct V_135 * V_33 = V_30 -> V_33 ;
int V_34 = 0 ;
int V_4 ;
V_2 = F_8 ( sizeof( struct V_1 ) , V_134 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_136 ; V_4 ++ ) {
V_62 = V_33 -> V_137 -> V_138 [ V_4 ] ;
if ( V_62 && V_62 -> V_125 > V_34 )
V_34 = V_62 -> V_125 ;
}
V_2 -> V_5 = F_8 ( sizeof( struct V_6 ) * V_34 , V_134 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_117 = F_37 ( V_87 * V_34 , V_134 ) ;
if ( ! V_2 -> V_117 )
goto V_139;
V_2 -> V_58 = V_59 ;
return V_2 ;
V_139:
F_38 ( V_2 -> V_5 ) ;
error:
F_38 ( V_2 ) ;
return NULL ;
}
static void
F_39 ( void * V_60 , struct V_63 * V_38 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
F_38 ( V_2 -> V_117 ) ;
F_38 ( V_2 -> V_5 ) ;
F_38 ( V_2 ) ;
}
static void
F_40 ( struct V_29 * V_30 )
{
static const int V_122 [ 4 ] = { 10 , 20 , 55 , 110 } ;
struct V_61 * V_62 ;
T_2 V_121 = F_34 ( & V_30 -> V_33 -> V_124 . V_108 ) ;
int V_4 , V_13 ;
V_62 = V_30 -> V_33 -> V_137 -> V_138 [ V_140 ] ;
if ( ! V_62 )
return;
for ( V_4 = 0 , V_13 = 0 ; V_4 < V_62 -> V_125 ; V_4 ++ ) {
struct V_106 * V_22 = & V_62 -> V_122 [ V_4 ] ;
if ( V_22 -> V_72 & V_110 )
continue;
if ( ( V_121 & V_62 -> V_122 [ V_4 ] . V_72 ) != V_121 )
continue;
for ( V_13 = 0 ; V_13 < F_41 ( V_122 ) ; V_13 ++ ) {
if ( V_22 -> V_112 != V_122 [ V_13 ] )
continue;
V_30 -> V_141 [ V_13 ] = V_4 ;
break;
}
}
}
static void *
F_42 ( struct V_135 * V_33 , struct V_142 * V_143 )
{
struct V_29 * V_30 ;
V_30 = F_8 ( sizeof( struct V_29 ) , V_31 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_131 = 15 ;
V_30 -> V_132 = 1023 ;
V_30 -> V_101 = 5 ;
V_30 -> V_100 = 10 ;
V_30 -> V_133 = 6000 ;
if ( V_33 -> V_144 > 0 )
V_30 -> V_37 = V_33 -> V_144 ;
else
V_30 -> V_37 = 7 ;
if ( V_33 -> V_34 >= 4 )
V_30 -> V_97 = true ;
V_30 -> V_33 = V_33 ;
V_30 -> V_78 = 100 ;
#ifdef F_15
V_30 -> V_57 = ( T_2 ) - 1 ;
V_30 -> V_145 = F_43 ( L_1 ,
V_146 | V_147 , V_143 , & V_30 -> V_57 ) ;
#endif
F_40 ( V_30 ) ;
return V_30 ;
}
static void
F_44 ( void * V_60 )
{
#ifdef F_15
F_45 ( ( (struct V_29 * ) V_60 ) -> V_145 ) ;
#endif
F_38 ( V_60 ) ;
}
static T_2 F_46 ( void * V_64 )
{
struct V_1 * V_2 = V_64 ;
struct V_14 * V_15 ;
int V_21 = V_2 -> V_32 [ 0 ] ;
int V_52 ;
V_15 = & V_2 -> V_5 [ V_21 ] . V_11 ;
V_52 = F_2 ( & V_2 -> V_5 [ V_21 ] , V_15 -> V_8 ) ;
V_52 = V_52 * 1200 * 8 / 1024 ;
return V_52 ;
}
int T_4
F_47 ( void )
{
return F_48 ( & V_148 ) ;
}
void
F_49 ( void )
{
F_50 ( & V_148 ) ;
}
