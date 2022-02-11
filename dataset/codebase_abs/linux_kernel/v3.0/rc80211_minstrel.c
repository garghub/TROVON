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
}
static inline unsigned int
F_5 ( struct V_18 * V_19 ,
struct V_45 * V_46 )
{
unsigned int V_60 = V_19 -> V_31 ;
if ( V_46 -> V_61 . V_50 [ 0 ] . V_52 & V_62 )
V_60 = F_6 ( 2U , F_7 ( V_19 -> V_63 , V_60 ) ) ;
else if ( V_46 -> V_61 . V_50 [ 0 ] . V_52 & V_64 )
V_60 = F_6 ( 2U , F_7 ( V_19 -> V_65 , V_60 ) ) ;
return V_60 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
unsigned int V_66 ;
V_66 = F_9 ( V_2 , V_2 -> V_67 , V_2 -> V_68 ) ;
V_2 -> V_67 ++ ;
if ( ( int ) V_2 -> V_67 > ( V_2 -> V_17 - 2 ) ) {
V_2 -> V_67 = 0 ;
V_2 -> V_68 ++ ;
if ( V_2 -> V_68 >= V_69 )
V_2 -> V_68 = 0 ;
}
return V_66 ;
}
static void
F_10 ( void * V_37 , struct V_40 * V_41 ,
void * V_42 , struct V_70 * V_71 )
{
struct V_43 * V_44 = V_71 -> V_44 ;
struct V_45 * V_46 = F_4 ( V_44 ) ;
struct V_1 * V_2 = V_42 ;
struct V_6 * V_7 = V_37 ;
struct V_47 * V_48 = V_46 -> V_61 . V_50 ;
unsigned int V_51 , V_66 = 0 ;
bool V_72 ;
bool V_73 = false ;
bool V_74 = false ;
int V_4 , V_75 ;
int V_76 [ 3 ] ;
int V_77 ;
if ( F_11 ( V_41 , V_42 , V_71 ) )
return;
V_72 = V_7 -> V_78 && ! V_71 -> V_79 && ! V_71 -> V_80 -> V_81 ;
if ( F_12 ( V_16 , V_2 -> V_15 + ( V_7 -> V_82 *
V_83 ) / 1000 ) )
F_2 ( V_7 , V_2 ) ;
V_51 = V_2 -> V_34 ;
if ( V_72 )
V_77 = V_7 -> V_84 ;
else
V_77 = V_7 -> V_85 ;
V_2 -> V_86 ++ ;
V_75 = ( V_2 -> V_86 * V_77 / 100 ) -
( V_2 -> V_58 + V_2 -> V_59 / 2 ) ;
if ( ( V_75 > 0 ) && ( V_72 || ! V_2 -> V_87 ) ) {
struct V_18 * V_88 ;
if ( V_2 -> V_86 >= 10000 ) {
V_2 -> V_59 = 0 ;
V_2 -> V_58 = 0 ;
V_2 -> V_86 = 0 ;
} else if ( V_75 > V_2 -> V_17 * 2 ) {
V_2 -> V_58 += ( V_75 - V_2 -> V_17 * 2 ) ;
}
V_66 = F_8 ( V_2 ) ;
V_88 = & V_2 -> V_5 [ V_66 ] ;
V_74 = true ;
V_73 = V_72 && ( V_88 -> V_20 >
V_2 -> V_5 [ V_51 ] . V_20 ) ;
if ( ! V_73 ) {
if ( V_88 -> V_33 != 0 ) {
V_51 = V_66 ;
V_2 -> V_58 ++ ;
if ( V_88 -> V_33 > 0 )
V_88 -> V_33 -- ;
} else {
V_74 = false ;
}
} else {
V_46 -> V_52 |= V_57 ;
V_2 -> V_59 ++ ;
}
}
V_2 -> V_87 = V_74 ;
if ( ! V_72 && V_74 && ( V_2 -> V_5 [ V_51 ] . V_27 > 17100 ) )
V_51 = V_2 -> V_34 ;
V_48 [ 0 ] . V_55 = V_2 -> V_5 [ V_51 ] . V_3 ;
V_48 [ 0 ] . V_56 = F_5 ( & V_2 -> V_5 [ V_51 ] , V_46 ) ;
if ( ! V_72 ) {
if ( ! V_74 )
V_48 [ 0 ] . V_56 = V_7 -> V_89 ;
V_48 [ 1 ] . V_55 = V_2 -> V_90 ;
V_48 [ 1 ] . V_56 = V_7 -> V_89 ;
return;
}
if ( V_74 ) {
if ( V_73 )
V_76 [ 0 ] = V_66 ;
else
V_76 [ 0 ] = V_2 -> V_34 ;
} else {
V_76 [ 0 ] = V_2 -> V_35 ;
}
V_76 [ 1 ] = V_2 -> V_36 ;
V_76 [ 2 ] = 0 ;
for ( V_4 = 1 ; V_4 < 4 ; V_4 ++ ) {
V_48 [ V_4 ] . V_55 = V_2 -> V_5 [ V_76 [ V_4 - 1 ] ] . V_3 ;
V_48 [ V_4 ] . V_56 = V_2 -> V_5 [ V_76 [ V_4 - 1 ] ] . V_31 ;
}
}
static void
F_13 ( struct V_1 * V_2 , struct V_91 * V_92 ,
struct V_18 * V_93 , struct V_94 * V_95 )
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
V_2 -> V_68 = 0 ;
V_2 -> V_67 = 0 ;
memset ( V_2 -> V_104 , 0 , V_69 * V_2 -> V_17 ) ;
for ( V_100 = 0 ; V_100 < V_69 ; V_100 ++ ) {
for ( V_4 = 0 ; V_4 < V_102 ; V_4 ++ ) {
F_16 ( V_103 , sizeof( V_103 ) ) ;
V_101 = ( V_4 + V_103 [ V_4 & 7 ] ) % V_102 ;
while ( F_9 ( V_2 , V_101 , V_100 ) != 0 )
V_101 = ( V_101 + 1 ) % V_102 ;
F_9 ( V_2 , V_101 , V_100 ) = V_4 + 1 ;
}
}
}
static void
F_17 ( void * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_6 * V_7 = V_37 ;
struct V_91 * V_92 = F_18 ( V_7 -> V_105 ) ;
struct V_94 * V_106 ;
unsigned int V_4 , V_107 = 0 ;
unsigned int V_108 = 9 ;
V_2 -> V_90 = F_19 ( V_39 , V_41 ) ;
V_106 = & V_39 -> V_109 [ V_2 -> V_90 ] ;
V_2 -> V_110 = F_14 ( V_92 , 10 , V_106 -> V_98 ,
! ! ( V_106 -> V_52 & V_97 ) , 1 ) ;
for ( V_4 = 0 ; V_4 < V_39 -> V_111 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_107 ] ;
unsigned int V_112 = 0 , V_113 = 0 , V_114 = 0 ;
unsigned int V_115 ;
unsigned int V_116 = V_7 -> V_117 ;
if ( ! F_20 ( V_41 , V_39 -> V_118 , V_4 ) )
continue;
V_107 ++ ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_3 = V_4 ;
V_19 -> V_98 = V_39 -> V_109 [ V_4 ] . V_98 / 5 ;
F_13 ( V_2 , V_92 , V_19 ,
& V_39 -> V_109 [ V_4 ] ) ;
V_19 -> V_33 = - 1 ;
V_19 -> V_32 = 1 ;
V_19 -> V_65 = 1 ;
V_19 -> V_63 = 1 ;
V_112 = V_19 -> V_20 + V_2 -> V_110 ;
do {
V_115 = V_19 -> V_99 + V_19 -> V_20 ;
V_115 += ( V_108 * V_116 ) >> 1 ;
V_116 = F_7 ( ( V_116 << 1 ) | 1 , V_7 -> V_119 ) ;
V_112 += V_115 ;
V_113 += V_115 + V_2 -> V_110 ;
V_114 += V_115 + 2 * V_2 -> V_110 ;
if ( ( V_113 < V_7 -> V_120 ) &&
( V_19 -> V_65 < V_7 -> V_89 ) )
V_19 -> V_65 ++ ;
if ( ( V_114 < V_7 -> V_120 ) &&
( V_19 -> V_63 < V_7 -> V_89 ) )
V_19 -> V_63 ++ ;
} while ( ( V_112 < V_7 -> V_120 ) &&
( ++ V_19 -> V_32 < V_7 -> V_89 ) );
V_19 -> V_31 = V_19 -> V_32 ;
}
for ( V_4 = V_107 ; V_4 < V_39 -> V_111 ; V_4 ++ ) {
struct V_18 * V_19 = & V_2 -> V_5 [ V_4 ] ;
V_19 -> V_3 = - 1 ;
}
V_2 -> V_17 = V_107 ;
V_2 -> V_15 = V_16 ;
F_15 ( V_2 ) ;
}
static void *
F_21 ( void * V_37 , struct V_40 * V_41 , T_3 V_121 )
{
struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_6 * V_7 = V_37 ;
struct V_122 * V_105 = V_7 -> V_105 ;
int V_123 = 0 ;
int V_4 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_121 ) ;
if ( ! V_2 )
return NULL ;
for ( V_4 = 0 ; V_4 < V_124 ; V_4 ++ ) {
V_39 = V_105 -> V_125 -> V_126 [ V_4 ] ;
if ( V_39 && V_39 -> V_111 > V_123 )
V_123 = V_39 -> V_111 ;
}
V_2 -> V_5 = F_22 ( sizeof( struct V_18 ) * V_123 , V_121 ) ;
if ( ! V_2 -> V_5 )
goto error;
V_2 -> V_104 = F_23 ( V_69 * V_123 , V_121 ) ;
if ( ! V_2 -> V_104 )
goto V_127;
V_2 -> V_15 = V_16 ;
return V_2 ;
V_127:
F_24 ( V_2 -> V_5 ) ;
error:
F_24 ( V_2 ) ;
return NULL ;
}
static void
F_25 ( void * V_37 , struct V_40 * V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
F_24 ( V_2 -> V_104 ) ;
F_24 ( V_2 -> V_5 ) ;
F_24 ( V_2 ) ;
}
static void *
F_26 ( struct V_122 * V_105 , struct V_128 * V_129 )
{
struct V_6 * V_7 ;
V_7 = F_22 ( sizeof( struct V_6 ) , V_130 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_117 = 15 ;
V_7 -> V_119 = 1023 ;
V_7 -> V_85 = 5 ;
V_7 -> V_84 = 10 ;
V_7 -> V_26 = 75 ;
V_7 -> V_120 = 6000 ;
if ( V_105 -> V_131 > 0 )
V_7 -> V_89 = V_105 -> V_131 ;
else
V_7 -> V_89 = 7 ;
if ( V_105 -> V_123 >= 4 )
V_7 -> V_78 = true ;
V_7 -> V_105 = V_105 ;
V_7 -> V_82 = 100 ;
return V_7 ;
}
static void
F_27 ( void * V_37 )
{
F_24 ( V_37 ) ;
}
int T_4
F_28 ( void )
{
return F_29 ( & V_132 ) ;
}
void
F_30 ( void )
{
F_31 ( & V_132 ) ;
}
