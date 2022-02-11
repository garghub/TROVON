static inline int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 ;
for ( V_4 = V_3 ; V_4 >= 0 ; V_4 -- )
if ( V_2 -> V_5 [ V_4 ] . V_3 == V_3 )
break;
return V_4 ;
}
static void
F_2 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
T_1 V_8 = 0 , V_9 = 0 , V_10 = 0 ;
T_1 V_11 = 0 , V_12 = 0 ;
T_1 V_13 ;
T_1 V_14 ;
int V_4 ;
V_2 -> V_15 = V_16 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_17 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_4 ] ;
V_13 = V_19 -> V_20 ;
if ( ! V_13 )
V_13 = 1000000 ;
if ( V_19 -> V_21 ) {
V_14 = ( V_19 -> V_22 * 18000 ) / V_19 -> V_21 ;
V_19 -> V_23 += V_19 -> V_22 ;
V_19 -> V_24 += V_19 -> V_21 ;
V_19 -> V_25 = V_14 ;
V_14 = ( ( V_14 * ( 100 - V_7 -> V_26 ) ) + ( V_19 -> V_27 *
V_7 -> V_26 ) ) / 100 ;
V_19 -> V_27 = V_14 ;
V_19 -> V_28 = V_14 * ( 1000000 / V_13 ) ;
}
V_19 -> V_29 = V_19 -> V_22 ;
V_19 -> V_30 = V_19 -> V_21 ;
V_19 -> V_22 = 0 ;
V_19 -> V_21 = 0 ;
if ( ( V_19 -> V_27 > 17100 ) || ( V_19 -> V_27 < 1800 ) ) {
V_19 -> V_31 = V_19 -> V_32 >> 1 ;
if ( V_19 -> V_31 > 2 )
V_19 -> V_31 = 2 ;
V_19 -> V_33 = 4 ;
} else {
V_19 -> V_33 = - 1 ;
V_19 -> V_31 = V_19 -> V_32 ;
}
if ( ! V_19 -> V_31 )
V_19 -> V_31 = 2 ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_17 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_4 ] ;
if ( V_8 < V_19 -> V_28 ) {
V_9 = V_4 ;
V_8 = V_19 -> V_28 ;
}
if ( V_11 < V_19 -> V_27 ) {
V_12 = V_4 ;
V_11 = V_19 -> V_27 ;
}
}
V_8 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_17 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_4 ] ;
if ( V_4 == V_9 )
continue;
if ( V_8 < V_19 -> V_28 ) {
V_10 = V_4 ;
V_8 = V_19 -> V_28 ;
}
}
V_2 -> V_34 = V_9 ;
V_2 -> V_35 = V_10 ;
V_2 -> V_36 = V_12 ;
}
static void
F_3 ( void * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_7 = V_37 ;
struct V_1 * V_2 = V_42 ;
struct V_45 * V_46 = F_4 ( V_44 ) ;
struct V_47 * V_48 = V_46 -> V_49 . V_50 ;
int V_4 , V_51 ;
int V_22 ;
V_22 = ! ! ( V_46 -> V_52 & V_53 ) ;
for ( V_4 = 0 ; V_4 < V_54 ; V_4 ++ ) {
if ( V_48 [ V_4 ] . V_55 < 0 )
break;
V_51 = F_1 ( V_2 , V_48 [ V_4 ] . V_55 ) ;
if ( V_51 < 0 )
continue;
V_2 -> V_5 [ V_51 ] . V_21 += V_48 [ V_4 ] . V_56 ;
if ( ( V_4 != V_54 - 1 ) && ( V_48 [ V_4 + 1 ] . V_55 < 0 ) )
V_2 -> V_5 [ V_51 ] . V_22 += V_22 ;
}
if ( ( V_46 -> V_52 & V_57 ) && ( V_4 >= 0 ) )
V_2 -> V_58 ++ ;
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
if ( F_5 ( V_16 , V_2 -> V_15 +
( V_7 -> V_60 * V_61 ) / 1000 ) )
F_2 ( V_7 , V_2 ) ;
}
static inline unsigned int
F_6 ( struct V_18 * V_19 ,
struct V_45 * V_46 )
{
unsigned int V_62 = V_19 -> V_31 ;
if ( V_46 -> V_63 . V_50 [ 0 ] . V_52 & V_64 )
V_62 = F_7 ( 2U , F_8 ( V_19 -> V_65 , V_62 ) ) ;
else if ( V_46 -> V_63 . V_50 [ 0 ] . V_52 & V_66 )
V_62 = F_7 ( 2U , F_8 ( V_19 -> V_67 , V_62 ) ) ;
return V_62 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
V_68 = F_10 ( V_2 , V_2 -> V_69 , V_2 -> V_70 ) ;
V_2 -> V_69 ++ ;
if ( ( int ) V_2 -> V_69 > ( V_2 -> V_17 - 2 ) ) {
V_2 -> V_69 = 0 ;
V_2 -> V_70 ++ ;
if ( V_2 -> V_70 >= V_71 )
V_2 -> V_70 = 0 ;
}
return V_68 ;
}
static void
F_11 ( void * V_37 , struct V_40 * V_41 ,
void * V_42 , struct V_72 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_44 ;
struct V_45 * V_46 = F_4 ( V_44 ) ;
struct V_1 * V_2 = V_42 ;
struct V_6 * V_7 = V_37 ;
struct V_47 * V_48 = V_46 -> V_63 . V_50 ;
unsigned int V_51 , V_68 = 0 ;
bool V_74 ;
bool V_75 = false ;
bool V_76 = false ;
int V_4 , V_77 ;
int V_78 [ 3 ] ;
int V_79 ;
if ( F_12 ( V_41 , V_42 , V_73 ) )
return;
V_74 = V_7 -> V_80 && ! V_73 -> V_81 && ! V_73 -> V_82 -> V_83 ;
V_51 = V_2 -> V_34 ;
if ( V_74 )
V_79 = V_7 -> V_84 ;
else
V_79 = V_7 -> V_85 ;
V_2 -> V_86 ++ ;
V_77 = ( V_2 -> V_86 * V_79 / 100 ) -
( V_2 -> V_58 + V_2 -> V_59 / 2 ) ;
if ( ( V_77 > 0 ) && ( V_74 || ! V_2 -> V_87 ) ) {
struct V_18 * V_88 ;
if ( V_2 -> V_86 >= 10000 ) {
V_2 -> V_59 = 0 ;
V_2 -> V_58 = 0 ;
V_2 -> V_86 = 0 ;
} else if ( V_77 > V_2 -> V_17 * 2 ) {
V_2 -> V_58 += ( V_77 - V_2 -> V_17 * 2 ) ;
}
V_68 = F_9 ( V_2 ) ;
V_88 = & V_2 -> V_5 [ V_68 ] ;
V_76 = true ;
V_75 = V_74 && ( V_88 -> V_20 >
V_2 -> V_5 [ V_51 ] . V_20 ) ;
if ( ! V_75 ) {
if ( V_88 -> V_33 != 0 ) {
V_51 = V_68 ;
V_2 -> V_58 ++ ;
if ( V_88 -> V_33 > 0 )
V_88 -> V_33 -- ;
} else {
V_76 = false ;
}
} else {
V_46 -> V_52 |= V_57 ;
V_2 -> V_59 ++ ;
}
}
V_2 -> V_87 = V_76 ;
if ( ! V_74 && V_76 && ( V_2 -> V_5 [ V_51 ] . V_27 > 17100 ) )
V_51 = V_2 -> V_34 ;
V_48 [ 0 ] . V_55 = V_2 -> V_5 [ V_51 ] . V_3 ;
V_48 [ 0 ] . V_56 = F_6 ( & V_2 -> V_5 [ V_51 ] , V_46 ) ;
if ( ! V_74 ) {
if ( ! V_76 )
V_48 [ 0 ] . V_56 = V_7 -> V_89 ;
V_48 [ 1 ] . V_55 = V_2 -> V_90 ;
V_48 [ 1 ] . V_56 = V_7 -> V_89 ;
return;
}
if ( V_76 ) {
if ( V_75 )
V_78 [ 0 ] = V_68 ;
else
V_78 [ 0 ] = V_2 -> V_34 ;
} else {
V_78 [ 0 ] = V_2 -> V_35 ;
}
V_78 [ 1 ] = V_2 -> V_36 ;
V_78 [ 2 ] = 0 ;
for ( V_4 = 1 ; V_4 < 4 ; V_4 ++ ) {
V_48 [ V_4 ] . V_55 = V_2 -> V_5 [ V_78 [ V_4 - 1 ] ] . V_3 ;
V_48 [ V_4 ] . V_56 = V_2 -> V_5 [ V_78 [ V_4 - 1 ] ] . V_31 ;
}
}
static void
F_13 ( enum V_91 V_92 ,
struct V_18 * V_93 ,
struct V_94 * V_95 )
{
int V_96 = ! ! ( V_95 -> V_52 & V_97 ) ;
V_93 -> V_20 = F_14 ( V_92 , 1200 ,
V_95 -> V_98 , V_96 , 1 ) ;
V_93 -> V_99 = F_14 ( V_92 , 10 ,
V_95 -> V_98 , V_96 , 1 ) ;
}
static void
F_15 ( struct V_1 * V_2 )
{
unsigned int V_4 , V_100 , V_101 ;
unsigned int V_102 = V_2 -> V_17 - 1 ;
T_2 V_103 [ 8 ] ;
V_2 -> V_70 = 0 ;
V_2 -> V_69 = 0 ;
memset ( V_2 -> V_104 , 0 , V_71 * V_2 -> V_17 ) ;
for ( V_100 = 0 ; V_100 < V_71 ; V_100 ++ ) {
for ( V_4 = 0 ; V_4 < V_102 ; V_4 ++ ) {
F_16 ( V_103 , sizeof( V_103 ) ) ;
V_101 = ( V_4 + V_103 [ V_4 & 7 ] ) % V_102 ;
while ( F_10 ( V_2 , V_101 , V_100 ) != 0 )
V_101 = ( V_101 + 1 ) % V_102 ;
F_10 ( V_2 , V_101 , V_100 ) = V_4 + 1 ;
}
}
}
static void
F_17 ( void * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_6 * V_7 = V_37 ;
struct V_94 * V_105 ;
unsigned int V_4 , V_106 = 0 ;
unsigned int V_107 = 9 ;
V_2 -> V_90 = F_18 ( V_39 , V_41 ) ;
V_105 = & V_39 -> V_108 [ V_2 -> V_90 ] ;
V_2 -> V_109 = F_14 ( V_39 -> V_92 , 10 ,
V_105 -> V_98 ,
! ! ( V_105 -> V_52 & V_97 ) , 1 ) ;
for ( V_4 = 0 ; V_4 < V_39 -> V_110 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_106 ] ;
unsigned int V_111 = 0 , V_112 = 0 , V_113 = 0 ;
unsigned int V_114 ;
unsigned int V_115 = V_7 -> V_116 ;
if ( ! F_19 ( V_41 , V_39 -> V_92 , V_4 ) )
continue;
V_106 ++ ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_3 = V_4 ;
V_19 -> V_98 = V_39 -> V_108 [ V_4 ] . V_98 / 5 ;
F_13 ( V_39 -> V_92 , V_19 , & V_39 -> V_108 [ V_4 ] ) ;
V_19 -> V_33 = - 1 ;
V_19 -> V_32 = 1 ;
V_19 -> V_67 = 1 ;
V_19 -> V_65 = 1 ;
V_111 = V_19 -> V_20 + V_2 -> V_109 ;
do {
V_114 = V_19 -> V_99 + V_19 -> V_20 ;
V_114 += ( V_107 * V_115 ) >> 1 ;
V_115 = F_8 ( ( V_115 << 1 ) | 1 , V_7 -> V_117 ) ;
V_111 += V_114 ;
V_112 += V_114 + V_2 -> V_109 ;
V_113 += V_114 + 2 * V_2 -> V_109 ;
if ( ( V_112 < V_7 -> V_118 ) &&
( V_19 -> V_67 < V_7 -> V_89 ) )
V_19 -> V_67 ++ ;
if ( ( V_113 < V_7 -> V_118 ) &&
( V_19 -> V_65 < V_7 -> V_89 ) )
V_19 -> V_65 ++ ;
} while ( ( V_111 < V_7 -> V_118 ) &&
( ++ V_19 -> V_32 < V_7 -> V_89 ) );
V_19 -> V_31 = V_19 -> V_32 ;
}
for ( V_4 = V_106 ; V_4 < V_39 -> V_110 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_4 ] ;
V_19 -> V_3 = - 1 ;
}
V_2 -> V_17 = V_106 ;
V_2 -> V_15 = V_16 ;
F_15 ( V_2 ) ;
}
static void *
F_20 ( void * V_37 , struct V_40 * V_41 , T_3 V_119 )
{
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_6 * V_7 = V_37 ;
struct V_120 * V_121 = V_7 -> V_121 ;
int V_122 = 0 ;
int V_4 ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_119 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_123 ; V_4 ++ ) {
V_39 = V_121 -> V_124 -> V_125 [ V_4 ] ;
if ( V_39 && V_39 -> V_110 > V_122 )
V_122 = V_39 -> V_110 ;
}
V_2 -> V_5 = F_21 ( sizeof( struct V_18 ) * V_122 , V_119 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_104 = F_22 ( V_71 * V_122 , V_119 ) ;
if ( ! V_2 -> V_104 )
goto V_126;
V_2 -> V_15 = V_16 ;
return V_2 ;
V_126:
F_23 ( V_2 -> V_5 ) ;
error:
F_23 ( V_2 ) ;
return NULL ;
}
static void
F_24 ( void * V_37 , struct V_40 * V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
F_23 ( V_2 -> V_104 ) ;
F_23 ( V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
}
static void *
F_25 ( struct V_120 * V_121 , struct V_127 * V_128 )
{
struct V_6 * V_7 ;
V_7 = F_21 ( sizeof( struct V_6 ) , V_129 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_116 = 15 ;
V_7 -> V_117 = 1023 ;
V_7 -> V_85 = 5 ;
V_7 -> V_84 = 10 ;
V_7 -> V_26 = 75 ;
V_7 -> V_118 = 6000 ;
if ( V_121 -> V_130 > 0 )
V_7 -> V_89 = V_121 -> V_130 ;
else
V_7 -> V_89 = 7 ;
if ( V_121 -> V_122 >= 4 )
V_7 -> V_80 = true ;
V_7 -> V_121 = V_121 ;
V_7 -> V_60 = 100 ;
#ifdef F_26
V_7 -> V_131 = ( T_1 ) - 1 ;
V_7 -> V_132 = F_27 ( L_1 ,
V_133 | V_134 , V_128 , & V_7 -> V_131 ) ;
#endif
return V_7 ;
}
static void
F_28 ( void * V_37 )
{
#ifdef F_26
F_29 ( ( (struct V_6 * ) V_37 ) -> V_132 ) ;
#endif
F_23 ( V_37 ) ;
}
int T_4
F_30 ( void )
{
return F_31 ( & V_135 ) ;
}
void
F_32 ( void )
{
F_33 ( & V_135 ) ;
}
