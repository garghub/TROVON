T_1 *
F_1 ( int type , int V_1 )
{
T_1 * V_2 = NULL ;
if ( type == V_3 ) {
F_2 ( V_1 == V_4 ) ;
F_3 ( & V_5 . V_6 ) ;
if ( ! F_4 ( & V_5 . V_7 ) ) {
V_2 = F_5 ( V_5 . V_7 . \
V_8 , T_1 , V_9 ) ;
F_2 ( V_2 -> V_10 == V_1 ) ;
F_6 ( & V_2 -> V_9 ) ;
}
F_7 ( & V_5 . V_6 ) ;
}
if ( V_2 == NULL )
F_8 ( V_2 , V_1 ) ;
if ( V_2 == NULL )
return NULL ;
F_9 ( & V_2 -> V_11 , 1 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_10 = V_1 ;
F_10 ( & V_5 . V_15 ) ;
return V_2 ;
}
T_1 *
F_11 ( T_2 V_16 , int V_17 )
{
T_1 * V_2 ;
V_2 = F_1 ( V_3 , V_4 ) ;
if ( V_2 == NULL ) {
F_12 ( L_1 ) ;
return NULL ;
}
V_2 -> V_18 = NULL ;
V_2 -> V_19 = NULL ;
V_2 -> V_20 = NULL ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = V_2 -> V_23 . V_24 . V_25 ;
V_2 -> V_26 = 1 ;
V_2 -> V_27 = V_17 ;
F_13 ( & V_2 -> V_28 , V_3 ) ;
V_2 -> V_28 . V_29 [ 1 ] = V_16 ;
return V_2 ;
}
void
F_14 ( T_1 * V_2 )
{
F_15 ( & V_5 . V_15 ) ;
if ( V_2 -> V_19 == NULL && V_2 -> V_10 == V_4 ) {
F_3 ( & V_5 . V_6 ) ;
F_16 ( & V_2 -> V_9 , & V_5 . V_7 ) ;
F_7 ( & V_5 . V_6 ) ;
} else {
F_17 ( V_2 , V_2 -> V_10 ) ;
}
}
int
F_18 ( T_3 * V_30 , T_1 * V_2 )
{
struct V_31 * V_25 = V_2 -> V_22 ;
int V_32 ;
int V_33 ;
F_2 ( V_2 -> V_26 > 0 ) ;
V_33 = F_19 ( V_30 , V_2 ) ;
if ( V_33 <= 0 )
return ( V_33 ) ;
V_32 = V_33 ;
F_2 ( V_32 <= V_2 -> V_34 ) ;
V_2 -> V_34 -= V_32 ;
do {
F_2 ( V_2 -> V_26 > 0 ) ;
if ( V_32 < ( int ) V_25 -> V_35 ) {
V_25 -> V_36 = ( void * ) ( ( char * ) V_25 -> V_36 + V_32 ) ;
V_25 -> V_35 -= V_32 ;
return ( V_33 ) ;
}
V_32 -= V_25 -> V_35 ;
V_2 -> V_22 = ++ V_25 ;
V_2 -> V_26 -- ;
} while ( V_32 != 0 );
return ( V_33 ) ;
}
int
F_20 ( T_3 * V_30 , T_1 * V_2 )
{
T_4 * V_37 = V_2 -> V_20 ;
int V_32 ;
int V_33 ;
F_2 ( V_2 -> V_26 == 0 ) ;
F_2 ( V_2 -> V_21 > 0 ) ;
V_33 = F_21 ( V_30 , V_2 ) ;
if ( V_33 <= 0 )
return ( V_33 ) ;
V_32 = V_33 ;
F_2 ( V_32 <= V_2 -> V_34 ) ;
V_2 -> V_34 -= V_32 ;
do {
F_2 ( V_2 -> V_21 > 0 ) ;
if ( V_32 < ( int ) V_37 -> V_38 ) {
V_37 -> V_39 += V_32 ;
V_37 -> V_38 -= V_32 ;
return V_33 ;
}
V_32 -= ( int ) V_37 -> V_38 ;
V_2 -> V_20 = ++ V_37 ;
V_2 -> V_21 -- ;
} while ( V_32 != 0 );
return ( V_33 ) ;
}
int
F_22 ( T_3 * V_30 , T_1 * V_2 )
{
int V_33 ;
int V_40 ;
if ( V_5 . V_41 != 0 ) {
F_23 ( F_24 ( V_5 . V_41 ) ) ;
}
F_2 ( V_2 -> V_34 != 0 ) ;
V_33 = F_25 ( V_30 ) ;
if ( V_33 != 0 ) {
F_2 ( V_30 -> V_42 ) ;
return ( - V_43 ) ;
}
do {
if ( V_5 . V_44 > 0 ) {
V_5 . V_44 -- ;
V_33 = - V_45 ;
} else if ( V_2 -> V_26 != 0 ) {
V_33 = F_18 ( V_30 , V_2 ) ;
} else {
V_33 = F_20 ( V_30 , V_2 ) ;
}
V_40 = F_26 ( V_30 -> V_46 ) ;
if ( V_33 > 0 )
V_30 -> V_47 += V_33 ;
if ( V_40 < V_30 -> V_47 ) {
V_30 -> V_48 =
F_27 ( * V_49 . V_50 ) ;
V_30 -> V_51 -> V_52 = F_28 () ;
V_30 -> V_47 = V_40 ;
F_29 () ;
}
if ( V_33 <= 0 ) {
if ( V_33 == 0 )
V_33 = - V_45 ;
if( V_33 == - V_45 && F_30 ( V_30 ) )
V_33 = - V_53 ;
break;
}
F_31 ( V_33 , & V_30 -> V_54 ) ;
V_33 = 0 ;
} while ( V_2 -> V_34 != 0 );
F_32 ( V_30 ) ;
return ( V_33 ) ;
}
int
F_33 ( T_3 * V_30 )
{
struct V_31 * V_25 = V_30 -> V_55 ;
int V_32 ;
int V_33 ;
F_2 ( V_30 -> V_56 > 0 ) ;
V_33 = F_34 ( V_30 ) ;
if ( V_33 <= 0 )
return ( V_33 ) ;
V_32 = V_33 ;
V_30 -> V_51 -> V_52 = F_28 () ;
V_30 -> V_57 =
F_27 ( * V_49 . V_50 ) ;
F_29 () ;
V_30 -> V_58 = 1 ;
V_30 -> V_59 -= V_32 ;
V_30 -> V_60 -= V_32 ;
do {
F_2 ( V_30 -> V_56 > 0 ) ;
if ( V_32 < ( int ) V_25 -> V_35 ) {
V_25 -> V_35 -= V_32 ;
V_25 -> V_36 = ( void * ) ( ( char * ) V_25 -> V_36 + V_32 ) ;
return ( - V_45 ) ;
}
V_32 -= V_25 -> V_35 ;
V_30 -> V_55 = ++ V_25 ;
V_30 -> V_56 -- ;
} while ( V_32 != 0 );
return ( V_33 ) ;
}
int
F_35 ( T_3 * V_30 )
{
T_4 * V_37 = V_30 -> V_61 ;
int V_32 ;
int V_33 ;
F_2 ( V_30 -> V_62 > 0 ) ;
V_33 = F_36 ( V_30 ) ;
if ( V_33 <= 0 )
return ( V_33 ) ;
V_32 = V_33 ;
V_30 -> V_51 -> V_52 = F_28 () ;
V_30 -> V_57 =
F_27 ( * V_49 . V_50 ) ;
F_29 () ;
V_30 -> V_58 = 1 ;
V_30 -> V_59 -= V_32 ;
V_30 -> V_60 -= V_32 ;
do {
F_2 ( V_30 -> V_62 > 0 ) ;
if ( V_32 < ( int ) V_37 -> V_38 ) {
V_37 -> V_39 += V_32 ;
V_37 -> V_38 -= V_32 ;
return - V_45 ;
}
V_32 -= V_37 -> V_38 ;
V_30 -> V_61 = ++ V_37 ;
V_30 -> V_62 -- ;
} while ( V_32 != 0 );
return 1 ;
}
int
F_37 ( T_3 * V_30 )
{
int V_33 ;
if ( V_5 . V_63 != 0 ) {
F_23 ( F_24 ( V_5 . V_63 ) ) ;
}
V_33 = F_25 ( V_30 ) ;
if ( V_33 != 0 ) {
F_2 ( V_30 -> V_42 ) ;
return ( - V_43 ) ;
}
for (; ; ) {
if ( V_30 -> V_56 != 0 )
V_33 = F_33 ( V_30 ) ;
else
V_33 = F_35 ( V_30 ) ;
if ( V_33 <= 0 ) {
if ( V_33 == - V_45 ) {
V_33 = 1 ;
} else if ( V_33 == 0 && V_30 -> V_58 ) {
V_33 = - V_64 ;
}
break;
}
if ( V_30 -> V_59 == 0 ) {
V_33 = 1 ;
break;
}
}
F_32 ( V_30 ) ;
return V_33 ;
}
void
F_38 ( T_5 * V_65 , T_1 * V_2 )
{
T_6 * V_66 = V_2 -> V_19 ;
int V_33 = ( V_2 -> V_34 == 0 && ! V_2 -> V_12 ) ? 0 : - V_67 ;
F_2 ( V_65 != NULL || V_2 -> V_18 != NULL ) ;
if ( V_2 -> V_18 != NULL )
F_39 ( V_2 -> V_18 ) ;
if ( V_65 == NULL && V_2 -> V_18 != NULL )
V_65 = V_2 -> V_18 -> V_51 -> V_68 ;
F_14 ( V_2 ) ;
if ( V_66 != NULL )
F_40 ( V_65 , V_66 , V_33 ) ;
}
void
F_41 ( T_5 * V_65 , struct V_69 * V_70 , int error )
{
T_1 * V_2 ;
while ( ! F_4 ( V_70 ) ) {
V_2 = F_5 ( V_70 -> V_8 , T_1 , V_9 ) ;
if ( error && V_2 -> V_19 != NULL ) {
F_42 ( L_2 ,
F_43 ( V_2 -> V_19 -> V_71 . type ) ,
F_43 ( V_2 -> V_19 -> V_71 . V_72 ) ,
F_44 ( F_45 ( V_2 -> V_19 -> V_71 . V_73 ) ) ,
F_44 ( F_45 ( V_2 -> V_19 -> V_71 . V_74 ) ) ) ;
} else if ( error ) {
F_42 ( L_3 ) ;
}
F_6 ( & V_2 -> V_9 ) ;
F_2 ( F_46 ( & V_2 -> V_11 ) == 1 ) ;
F_38 ( V_65 , V_2 ) ;
}
}
static void
F_47 ( T_1 * V_2 )
{
T_3 * V_30 = V_2 -> V_18 ;
T_7 * V_75 = V_30 -> V_51 ;
F_2 ( V_2 -> V_28 . V_76 != V_3 ) ;
F_2 ( V_2 -> V_13 ) ;
V_2 -> V_14 = 1 ;
if ( V_30 -> V_77 == & V_78 ||
! V_30 -> V_79 )
return;
F_48 ( V_2 ) ;
F_3 ( & V_75 -> V_80 ) ;
V_2 -> V_81 =
F_27 ( * V_49 . V_50 ) ;
F_2 ( V_2 -> V_28 . V_29 [ 0 ] == 0 ) ;
V_2 -> V_28 . V_29 [ 0 ] = V_75 -> V_82 ++ ;
if ( V_75 -> V_82 == 0 )
V_75 -> V_82 = V_83 + 1 ;
F_49 ( & V_2 -> V_84 , & V_75 -> V_85 ) ;
F_7 ( & V_75 -> V_80 ) ;
}
static void
F_50 ( T_1 * V_2 )
{
T_7 * V_75 = V_2 -> V_18 -> V_51 ;
F_2 ( V_2 -> V_28 . V_76 != V_3 ) ;
F_2 ( V_2 -> V_13 ) ;
V_2 -> V_14 = 0 ;
F_3 ( & V_75 -> V_80 ) ;
if ( V_2 -> V_28 . V_29 [ 0 ] == 0 ) {
F_7 ( & V_75 -> V_80 ) ;
return;
}
V_2 -> V_28 . V_29 [ 0 ] = 0 ;
F_6 ( & V_2 -> V_84 ) ;
F_7 ( & V_75 -> V_80 ) ;
F_51 ( V_2 ) ;
}
int
F_52 ( T_3 * V_30 , T_1 * V_2 )
{
int V_33 ;
if ( V_2 -> V_13 && ! V_2 -> V_14 )
F_47 ( V_2 ) ;
V_33 = F_22 ( V_30 , V_2 ) ;
F_53 ( V_86 , L_4 , V_2 -> V_34 , V_33 ) ;
if ( V_2 -> V_34 == 0 ) {
F_2 ( V_33 == 0 ) ;
return ( 0 ) ;
}
if ( V_33 == - V_45 )
return ( V_33 ) ;
if ( V_33 == - V_53 ) {
static int V_87 ;
V_87 ++ ;
if ( ( V_87 & ( - V_87 ) ) == V_87 )
F_54 ( L_5 ,
V_87 , V_30 , F_46 ( & V_88 ) ) ;
F_55 ( & V_5 . V_89 ) ;
F_2 ( V_30 -> V_90 ) ;
F_49 ( & V_30 -> V_91 ,
& V_5 . V_92 ) ;
if ( ! F_56 ( F_57 ( F_28 () ,
V_93 ) ,
V_5 . V_94 ) )
F_58 ( & V_5 . V_95 ) ;
F_59 ( & V_5 . V_89 ) ;
return ( V_33 ) ;
}
F_2 ( V_33 < 0 ) ;
if ( ! V_30 -> V_42 ) {
switch ( V_33 ) {
case - V_96 :
F_60 ( L_6
L_7
L_8 ,
& V_30 -> V_97 ) ;
break;
default:
F_60 ( L_9
L_10 ,
& V_30 -> V_97 , V_33 ) ;
break;
}
F_53 ( V_86 , L_11
L_12 , V_30 , V_33 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
}
if ( V_2 -> V_14 )
F_50 ( V_2 ) ;
F_62 ( V_30 ,
( V_30 -> V_42 ) ? 0 : V_33 ) ;
return ( V_33 ) ;
}
void
F_63 ( T_8 * V_100 )
{
F_2 ( ! V_100 -> V_101 ) ;
F_2 ( ! V_100 -> V_102 ) ;
F_2 ( ( F_64 () & ~ V_100 -> V_103 ) != 0 ) ;
V_100 -> V_101 = 1 ;
F_65 ( V_100 ) ;
F_55 ( & V_5 . V_104 ) ;
F_49 ( & V_100 -> V_105 ,
& V_5 . V_106 ) ;
F_58 ( & V_5 . V_107 ) ;
F_59 ( & V_5 . V_104 ) ;
}
void
F_66 ( T_7 * V_75 )
{
T_8 * V_100 ;
for (; ; ) {
V_100 = F_67 ( V_75 ) ;
if ( V_100 == NULL )
return;
F_63 ( V_100 ) ;
}
}
T_3 *
F_68 ( T_7 * V_75 , T_1 * V_2 , int V_17 )
{
struct V_69 * V_108 ;
T_3 * V_30 ;
T_3 * V_109 = NULL ;
T_3 * V_110 = NULL ;
int V_111 = 0 ;
int V_112 = 0 ;
F_69 (tmp, &peer->ksnp_conns) {
T_3 * V_113 = F_5 ( V_108 , T_3 , V_114 ) ;
int V_32 = F_46 ( & V_113 -> V_54 ) +
F_26 ( V_113 -> V_46 ) ;
int V_33 ;
F_2 ( ! V_113 -> V_42 ) ;
F_2 ( V_113 -> V_77 != NULL &&
V_113 -> V_77 -> V_115 != NULL ) ;
V_33 = V_113 -> V_77 -> V_115 ( V_113 , V_2 , V_17 ) ;
switch ( V_33 ) {
default:
F_70 () ;
case V_116 :
continue;
case V_117 :
if ( V_109 == NULL || V_111 > V_32 ||
( V_111 == V_32 && * V_49 . V_118 &&
F_71 ( V_109 -> V_119 , V_113 -> V_119 ) ) ) {
V_109 = V_113 ;
V_111 = V_32 ;
}
break;
case V_120 :
if ( V_110 == NULL || V_112 > V_32 ||
( V_112 == V_32 && * V_49 . V_118 &&
F_71 ( V_110 -> V_119 , V_113 -> V_119 ) ) ) {
V_110 = V_113 ;
V_112 = V_32 ;
}
break;
}
}
V_30 = ( V_109 != NULL ) ? V_109 : V_110 ;
if ( V_30 != NULL )
V_30 -> V_119 = F_28 () ;
return V_30 ;
}
void
F_72 ( T_3 * V_30 , T_1 * V_2 )
{
V_30 -> V_77 -> V_121 ( V_2 ) ;
F_73 ( V_2 -> V_122 , & V_30 -> V_54 ) ;
F_74 ( V_30 ) ;
V_2 -> V_18 = V_30 ;
}
void
F_75 ( T_1 * V_2 , T_3 * V_30 )
{
T_9 * V_123 = V_30 -> V_124 ;
T_10 * V_125 = & V_2 -> V_28 ;
T_1 * V_126 = NULL ;
int V_40 = 0 ;
F_2 ( ! V_30 -> V_42 ) ;
F_53 ( V_86 , L_13 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
F_72 ( V_30 , V_2 ) ;
F_2 ( F_76 ( V_2 -> V_26 , V_2 -> V_22 ) +
F_77 ( V_2 -> V_21 , V_2 -> V_20 ) ==
( unsigned int ) V_2 -> V_122 ) ;
F_2 ( V_2 -> V_26 >= 1 ) ;
F_2 ( V_2 -> V_34 == V_2 -> V_122 ) ;
F_53 ( V_86 , L_14 ,
V_2 , ( V_2 -> V_19 != NULL ) ? V_2 -> V_19 -> V_71 . type :
V_3 ,
V_2 -> V_122 , V_2 -> V_26 , V_2 -> V_21 ) ;
V_40 = F_26 ( V_30 -> V_46 ) ;
F_55 ( & V_123 -> V_127 ) ;
if ( F_4 ( & V_30 -> V_128 ) && V_40 == 0 ) {
V_30 -> V_48 =
F_27 ( * V_49 . V_50 ) ;
if ( V_30 -> V_47 > 0 )
V_30 -> V_51 -> V_52 = F_28 () ;
V_30 -> V_47 = 0 ;
F_29 () ;
}
if ( V_125 -> V_76 == V_3 ) {
F_2 ( V_125 -> V_29 [ 1 ] != 0 ) ;
F_2 ( V_30 -> V_77 -> V_129 != NULL ) ;
if ( V_30 -> V_77 -> V_129 ( V_30 , V_2 , 0 ) )
V_126 = V_2 ;
} else {
F_2 ( V_125 -> V_29 [ 1 ] == 0 ) ;
F_2 ( V_30 -> V_77 -> V_130 != NULL ) ;
V_126 = V_30 -> V_77 -> V_130 ( V_30 , V_2 ) ;
}
if ( V_126 != NULL ) {
F_31 ( V_126 -> V_122 , & V_30 -> V_54 ) ;
F_49 ( & V_126 -> V_9 , & V_123 -> V_131 ) ;
}
if ( V_30 -> V_132 &&
! V_30 -> V_90 ) {
F_74 ( V_30 ) ;
F_49 ( & V_30 -> V_91 ,
& V_123 -> V_133 ) ;
V_30 -> V_90 = 1 ;
F_58 ( & V_123 -> V_134 ) ;
}
F_59 ( & V_123 -> V_127 ) ;
}
T_8 *
F_67 ( T_7 * V_75 )
{
T_11 V_135 = F_28 () ;
struct V_69 * V_108 ;
T_8 * V_100 ;
F_69 (tmp, &peer->ksnp_routes) {
V_100 = F_5 ( V_108 , T_8 , V_136 ) ;
F_2 ( ! V_100 -> V_102 || V_100 -> V_101 ) ;
if ( V_100 -> V_101 )
continue;
if ( ( F_64 () & ~ V_100 -> V_103 ) == 0 )
continue;
if ( ! ( V_100 -> V_137 == 0 ||
F_56 ( V_135 , V_100 -> V_138 ) ) ) {
F_53 ( V_86 ,
L_15
L_16 ,
& V_100 -> V_139 ,
V_100 -> V_103 ,
V_100 -> V_137 ,
F_78 ( V_100 -> V_138 - V_135 ) ) ;
continue;
}
return ( V_100 ) ;
}
return ( NULL ) ;
}
T_8 *
F_79 ( T_7 * V_75 )
{
struct V_69 * V_108 ;
T_8 * V_100 ;
F_69 (tmp, &peer->ksnp_routes) {
V_100 = F_5 ( V_108 , T_8 , V_136 ) ;
F_2 ( ! V_100 -> V_102 || V_100 -> V_101 ) ;
if ( V_100 -> V_101 )
return ( V_100 ) ;
}
return ( NULL ) ;
}
int
F_80 ( T_5 * V_65 , T_1 * V_2 , T_12 V_140 )
{
T_7 * V_75 ;
T_3 * V_30 ;
T_13 * V_141 ;
int V_142 ;
int V_33 ;
F_2 ( V_2 -> V_18 == NULL ) ;
V_141 = & V_5 . V_143 ;
for ( V_142 = 0 ; ; V_142 = 1 ) {
F_81 ( V_141 ) ;
V_75 = F_82 ( V_65 , V_140 ) ;
if ( V_75 != NULL ) {
if ( F_67 ( V_75 ) == NULL ) {
V_30 = F_68 ( V_75 , V_2 , V_2 -> V_27 ) ;
if ( V_30 != NULL ) {
F_75 ( V_2 , V_30 ) ;
F_83 ( V_141 ) ;
return ( 0 ) ;
}
}
}
F_83 ( V_141 ) ;
F_84 ( V_141 ) ;
V_75 = F_82 ( V_65 , V_140 ) ;
if ( V_75 != NULL )
break;
F_85 ( V_141 ) ;
if ( ( V_140 . V_144 & V_145 ) != 0 ) {
F_12 ( L_17
L_18 , F_61 ( V_140 ) ) ;
return - V_146 ;
}
if ( V_142 ) {
F_12 ( L_19 , F_61 ( V_140 ) ) ;
return - V_146 ;
}
V_33 = F_86 ( V_65 , V_140 ,
F_87 ( V_140 . V_147 ) ,
F_88 () ) ;
if ( V_33 != 0 ) {
F_12 ( L_20 ,
F_61 ( V_140 ) , V_33 ) ;
return V_33 ;
}
}
F_66 ( V_75 ) ;
V_30 = F_68 ( V_75 , V_2 , V_2 -> V_27 ) ;
if ( V_30 != NULL ) {
F_75 ( V_2 , V_30 ) ;
F_85 ( V_141 ) ;
return ( 0 ) ;
}
if ( V_75 -> V_148 > 0 ||
F_79 ( V_75 ) != NULL ) {
V_2 -> V_81 =
F_27 ( * V_49 . V_50 ) ;
F_49 ( & V_2 -> V_9 , & V_75 -> V_149 ) ;
F_85 ( V_141 ) ;
return 0 ;
}
F_85 ( V_141 ) ;
F_42 ( L_21 , F_61 ( V_140 ) ) ;
return ( - V_146 ) ;
}
int
F_89 ( T_5 * V_65 , void * V_150 , T_6 * V_151 )
{
int V_152 = 1 ;
int type = V_151 -> V_153 ;
T_12 V_154 = V_151 -> V_155 ;
unsigned int V_156 = V_151 -> V_157 ;
struct V_31 * V_158 = V_151 -> V_159 ;
T_4 * V_160 = V_151 -> V_161 ;
unsigned int V_162 = V_151 -> V_163 ;
unsigned int V_164 = V_151 -> V_165 ;
T_1 * V_2 ;
int V_166 ;
int V_33 ;
F_53 ( V_86 , L_22 ,
V_164 , V_156 , F_61 ( V_154 ) ) ;
F_2 ( V_164 == 0 || V_156 > 0 ) ;
F_2 ( V_156 <= V_167 ) ;
F_2 ( ! ( V_160 != NULL && V_158 != NULL ) ) ;
F_2 ( ! F_90 () ) ;
if ( V_158 != NULL )
V_166 = F_91 ( T_1 ,
V_23 . V_24 . V_25 [ 1 + V_156 ] ) ;
else
V_166 = F_91 ( T_1 ,
V_23 . V_168 . V_37 [ V_156 ] ) ;
if ( V_151 -> V_169 )
V_152 = F_92 () ;
V_2 = F_1 ( V_170 , V_166 ) ;
if ( V_2 == NULL ) {
F_12 ( L_23 ,
type , V_166 ) ;
if ( V_151 -> V_169 )
F_93 ( V_152 ) ;
return ( - V_53 ) ;
}
V_2 -> V_18 = NULL ;
V_2 -> V_19 = V_151 ;
if ( V_158 != NULL ) {
V_2 -> V_20 = NULL ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = V_2 -> V_23 . V_24 . V_25 ;
V_2 -> V_26 = 1 +
F_94 ( V_156 , & V_2 -> V_22 [ 1 ] ,
V_156 , V_158 ,
V_162 , V_164 ) ;
} else {
V_2 -> V_26 = 1 ;
V_2 -> V_22 = & V_2 -> V_23 . V_168 . V_25 ;
V_2 -> V_20 = V_2 -> V_23 . V_168 . V_37 ;
V_2 -> V_21 = F_95 ( V_156 , V_2 -> V_20 ,
V_156 , V_160 ,
V_162 , V_164 ) ;
if ( V_164 >= * V_49 . V_171 )
V_2 -> V_13 = 1 ;
}
F_13 ( & V_2 -> V_28 , V_170 ) ;
V_33 = F_80 ( V_65 , V_2 , V_154 ) ;
if ( ! V_152 )
F_93 ( V_152 ) ;
if ( V_33 == 0 )
return ( 0 ) ;
F_14 ( V_2 ) ;
return ( - V_67 ) ;
}
int
F_96 ( int (* F_97)( void * V_172 ) , void * V_172 , char * V_173 )
{
struct V_174 * V_175 = F_98 ( F_97 , V_172 , L_24 , V_173 ) ;
if ( F_99 ( V_175 ) )
return F_100 ( V_175 ) ;
F_84 ( & V_5 . V_143 ) ;
V_5 . V_176 ++ ;
F_85 ( & V_5 . V_143 ) ;
return 0 ;
}
void
F_101 ( void )
{
F_84 ( & V_5 . V_143 ) ;
V_5 . V_176 -- ;
F_85 ( & V_5 . V_143 ) ;
}
int
F_102 ( T_3 * V_30 , int V_177 )
{
static char V_178 [ 4096 ] ;
int V_32 ;
unsigned int V_179 ;
int V_180 ;
F_2 ( V_30 -> V_77 != NULL ) ;
if ( ( * V_49 . V_181 & V_30 -> V_182 ) != 0 ) {
F_103 ( V_30 ) ;
}
if ( V_177 == 0 ) {
V_30 -> V_58 = 0 ;
F_29 () ;
switch ( V_30 -> V_77 -> V_183 ) {
case V_184 :
case V_185 :
V_30 -> V_186 = V_187 ;
V_30 -> V_55 = (struct V_31 * ) & V_30 -> V_188 ;
V_30 -> V_55 [ 0 ] . V_36 = ( char * ) & V_30 -> V_189 ;
V_30 -> V_59 = F_91 ( T_10 , V_190 ) ;
V_30 -> V_60 = F_91 ( T_10 , V_190 ) ;
V_30 -> V_55 [ 0 ] . V_35 = F_91 ( T_10 , V_190 ) ;
break;
case V_191 :
V_30 -> V_186 = V_192 ;
V_30 -> V_59 = sizeof( V_193 ) ;
V_30 -> V_60 = sizeof( V_193 ) ;
V_30 -> V_55 = (struct V_31 * ) & V_30 -> V_188 ;
V_30 -> V_55 [ 0 ] . V_36 = ( char * ) & V_30 -> V_189 . V_190 . V_66 ;
V_30 -> V_55 [ 0 ] . V_35 = sizeof ( V_193 ) ;
break;
default:
F_70 () ;
}
V_30 -> V_56 = 1 ;
V_30 -> V_61 = NULL ;
V_30 -> V_62 = 0 ;
V_30 -> V_194 = ~ 0 ;
return ( 1 ) ;
}
V_30 -> V_186 = V_195 ;
V_30 -> V_60 = V_177 ;
V_30 -> V_55 = (struct V_31 * ) & V_30 -> V_188 ;
V_180 = 0 ;
V_179 = 0 ;
do {
V_32 = F_104 ( V_177 , sizeof ( V_178 ) ) ;
V_30 -> V_55 [ V_179 ] . V_36 = V_178 ;
V_30 -> V_55 [ V_179 ] . V_35 = V_32 ;
V_179 ++ ;
V_180 += V_32 ;
V_177 -= V_32 ;
} while ( V_177 != 0 &&
V_179 < sizeof( V_30 -> V_188 ) / sizeof ( struct V_31 ) );
V_30 -> V_56 = V_179 ;
V_30 -> V_61 = NULL ;
V_30 -> V_62 = 0 ;
V_30 -> V_59 = V_180 ;
return ( 0 ) ;
}
int
F_105 ( T_3 * V_30 )
{
V_193 * V_196 ;
T_12 * V_140 ;
int V_33 ;
F_2 ( F_46 ( & V_30 -> V_197 ) > 0 ) ;
F_2 ( V_30 -> V_186 == V_187 ||
V_30 -> V_186 == V_198 ||
V_30 -> V_186 == V_192 ||
V_30 -> V_186 == V_195 ) ;
V_199:
if ( V_30 -> V_59 != 0 ) {
V_33 = F_37 ( V_30 ) ;
if ( V_33 <= 0 ) {
F_2 ( V_33 != - V_45 ) ;
if ( V_33 == 0 )
F_53 ( V_86 , L_25
L_12 , V_30 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
else if ( ! V_30 -> V_42 )
F_12 ( L_26
L_12 ,
V_30 , V_33 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
F_62 ( V_30 ,
( V_30 -> V_42 ) ? 0 : V_33 ) ;
return ( V_33 == 0 ? - V_43 : V_33 ) ;
}
if ( V_30 -> V_59 != 0 ) {
return ( - V_45 ) ;
}
}
switch ( V_30 -> V_186 ) {
case V_187 :
if ( V_30 -> V_200 ) {
F_106 ( & V_30 -> V_189 . V_76 ) ;
F_106 ( & V_30 -> V_189 . V_201 ) ;
F_107 ( & V_30 -> V_189 . V_29 [ 0 ] ) ;
F_107 ( & V_30 -> V_189 . V_29 [ 1 ] ) ;
}
if ( V_30 -> V_189 . V_76 != V_3 &&
V_30 -> V_189 . V_76 != V_170 ) {
F_12 ( L_27 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
V_30 -> V_189 . V_76 ) ;
F_102 ( V_30 , 0 ) ;
F_62 ( V_30 , - V_64 ) ;
return ( - V_64 ) ;
}
if ( V_30 -> V_189 . V_76 == V_3 &&
V_30 -> V_189 . V_201 != 0 &&
V_30 -> V_189 . V_201 != V_30 -> V_194 ) {
F_12 ( L_28 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
V_30 -> V_189 . V_201 , V_30 -> V_194 ) ;
F_102 ( V_30 , 0 ) ;
F_62 ( V_30 , - V_64 ) ;
return ( - V_67 ) ;
}
if ( V_30 -> V_189 . V_29 [ 1 ] != 0 ) {
T_2 V_16 = 0 ;
F_2 ( V_30 -> V_77 != & V_78 ) ;
if ( V_30 -> V_189 . V_76 == V_3 )
V_16 = V_30 -> V_189 . V_29 [ 0 ] ;
V_33 = V_30 -> V_77 -> V_202 ( V_30 , V_16 ,
V_30 -> V_189 . V_29 [ 1 ] ) ;
if ( V_33 != 0 ) {
F_12 ( L_29 V_203 L_30 V_203 L_31 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
V_16 , V_30 -> V_189 . V_29 [ 1 ] ) ;
F_102 ( V_30 , 0 ) ;
F_62 ( V_30 , - V_64 ) ;
return ( V_33 ) ;
}
}
if ( V_30 -> V_189 . V_76 == V_3 ) {
F_102 ( V_30 , 0 ) ;
return 0 ;
}
V_30 -> V_186 = V_192 ;
V_30 -> V_59 = sizeof( V_204 ) ;
V_30 -> V_60 = sizeof( V_204 ) ;
V_30 -> V_55 = (struct V_31 * ) & V_30 -> V_188 ;
V_30 -> V_55 [ 0 ] . V_36 = ( char * ) & V_30 -> V_189 . V_190 . V_66 ;
V_30 -> V_55 [ 0 ] . V_35 = sizeof( V_204 ) ;
V_30 -> V_56 = 1 ;
V_30 -> V_61 = NULL ;
V_30 -> V_62 = 0 ;
goto V_199;
case V_192 :
V_30 -> V_77 -> V_205 ( & V_30 -> V_189 ) ;
if ( ( V_30 -> V_51 -> V_98 . V_144 & V_145 ) != 0 ) {
V_196 = & V_30 -> V_189 . V_190 . V_66 . V_206 ;
V_140 = & V_30 -> V_51 -> V_98 ;
V_196 -> V_207 = F_108 ( V_140 -> V_144 ) ;
V_196 -> V_73 = F_109 ( V_140 -> V_147 ) ;
}
V_30 -> V_186 = V_208 ;
F_74 ( V_30 ) ;
V_33 = F_110 ( V_30 -> V_51 -> V_68 ,
& V_30 -> V_189 . V_190 . V_66 . V_206 ,
V_30 -> V_51 -> V_98 . V_147 , V_30 , 0 ) ;
if ( V_33 < 0 ) {
F_102 ( V_30 , 0 ) ;
F_62 ( V_30 , V_33 ) ;
F_39 ( V_30 ) ;
return ( - V_64 ) ;
}
F_2 ( V_30 -> V_186 == V_208 ||
V_30 -> V_186 == V_198 ) ;
if ( V_30 -> V_186 != V_198 )
return 0 ;
goto V_199;
case V_198 :
V_33 = 0 ;
if ( V_30 -> V_60 == 0 &&
V_30 -> V_189 . V_201 != 0 &&
V_30 -> V_189 . V_201 != V_30 -> V_194 ) {
F_12 ( L_28 ,
F_61 ( V_30 -> V_51 -> V_98 ) ,
V_30 -> V_189 . V_201 , V_30 -> V_194 ) ;
V_33 = - V_67 ;
}
if ( V_33 == 0 && V_30 -> V_189 . V_29 [ 0 ] != 0 ) {
F_2 ( V_30 -> V_77 != & V_78 ) ;
V_196 = & V_30 -> V_189 . V_190 . V_66 . V_206 ;
V_140 = & V_30 -> V_51 -> V_98 ;
V_33 = V_30 -> V_77 -> V_209 ( V_30 ,
V_30 -> V_189 . V_29 [ 0 ] ,
* V_49 . V_210 ||
F_45 ( V_196 -> V_73 ) != V_140 -> V_147 ) ;
}
F_40 ( V_30 -> V_51 -> V_68 , V_30 -> V_211 , V_33 ) ;
if ( V_33 != 0 ) {
F_102 ( V_30 , 0 ) ;
F_62 ( V_30 , V_33 ) ;
return ( - V_64 ) ;
}
case V_195 :
if ( F_102 ( V_30 , V_30 -> V_60 ) )
return 0 ;
goto V_199;
default:
break;
}
F_70 () ;
return ( - V_212 ) ;
}
int
F_111 ( T_5 * V_65 , void * V_150 , T_6 * V_125 , int V_213 ,
unsigned int V_179 , struct V_31 * V_25 , T_4 * V_37 ,
unsigned int V_214 , unsigned int V_215 , unsigned int V_216 )
{
T_3 * V_30 = ( T_3 * ) V_150 ;
T_9 * V_123 = V_30 -> V_124 ;
F_2 ( V_215 <= V_216 ) ;
F_2 ( V_179 <= V_167 ) ;
V_30 -> V_211 = V_125 ;
V_30 -> V_59 = V_215 ;
V_30 -> V_60 = V_216 ;
if ( V_215 == 0 || V_25 != NULL ) {
V_30 -> V_62 = 0 ;
V_30 -> V_61 = NULL ;
V_30 -> V_55 = V_30 -> V_188 . V_25 ;
V_30 -> V_56 =
F_94 ( V_167 , V_30 -> V_55 ,
V_179 , V_25 , V_214 , V_215 ) ;
} else {
V_30 -> V_56 = 0 ;
V_30 -> V_55 = NULL ;
V_30 -> V_61 = V_30 -> V_188 . V_37 ;
V_30 -> V_62 =
F_95 ( V_167 , V_30 -> V_61 ,
V_179 , V_37 , V_214 , V_215 ) ;
}
F_2 ( V_215 ==
F_76 ( V_30 -> V_56 , V_30 -> V_55 ) +
F_77 ( V_30 -> V_62 , V_30 -> V_61 ) ) ;
F_2 ( V_30 -> V_217 ) ;
F_55 ( & V_123 -> V_127 ) ;
switch ( V_30 -> V_186 ) {
case V_218 :
F_49 ( & V_30 -> V_219 , & V_123 -> V_220 ) ;
F_58 ( & V_123 -> V_134 ) ;
F_2 ( V_30 -> V_221 ) ;
break;
case V_208 :
break;
}
V_30 -> V_186 = V_198 ;
F_59 ( & V_123 -> V_127 ) ;
F_39 ( V_30 ) ;
return 0 ;
}
static inline int
F_112 ( T_9 * V_123 )
{
int V_33 ;
F_55 ( & V_123 -> V_127 ) ;
V_33 = ( ! V_5 . V_222 &&
F_4 ( & V_123 -> V_220 ) &&
F_4 ( & V_123 -> V_133 ) ) ;
F_59 ( & V_123 -> V_127 ) ;
return V_33 ;
}
int F_113 ( void * V_172 )
{
struct V_223 * V_224 ;
T_9 * V_123 ;
T_3 * V_30 ;
T_1 * V_2 ;
int V_33 ;
int V_225 = 0 ;
long V_140 = ( long ) V_172 ;
V_224 = V_5 . V_226 [ F_114 ( V_140 ) ] ;
V_123 = & V_224 -> V_227 [ F_115 ( V_140 ) ] ;
F_116 () ;
V_33 = F_117 ( F_118 () , V_224 -> V_228 ) ;
if ( V_33 != 0 ) {
F_12 ( L_32 ,
V_224 -> V_228 , V_33 ) ;
}
F_55 ( & V_123 -> V_127 ) ;
while ( ! V_5 . V_222 ) {
int V_229 = 0 ;
if ( ! F_4 ( & V_123 -> V_220 ) ) {
V_30 = F_5 ( V_123 -> V_220 . V_8 ,
T_3 , V_219 ) ;
F_6 ( & V_30 -> V_219 ) ;
F_2 ( V_30 -> V_217 ) ;
F_2 ( V_30 -> V_221 ) ;
V_30 -> V_221 = 0 ;
F_59 ( & V_123 -> V_127 ) ;
V_33 = F_105 ( V_30 ) ;
F_55 ( & V_123 -> V_127 ) ;
F_2 ( V_30 -> V_217 ) ;
if ( V_33 == 0 )
V_30 -> V_221 = 1 ;
if ( V_30 -> V_186 == V_208 ) {
V_30 -> V_186 = V_218 ;
} else if ( V_30 -> V_221 ) {
F_49 ( & V_30 -> V_219 ,
& V_123 -> V_220 ) ;
} else {
V_30 -> V_217 = 0 ;
F_39 ( V_30 ) ;
}
V_229 = 1 ;
}
if ( ! F_4 ( & V_123 -> V_133 ) ) {
F_119 ( V_230 ) ;
if ( ! F_4 ( & V_123 -> V_131 ) ) {
F_16 ( & V_230 ,
& V_123 -> V_131 ) ;
F_120 ( & V_123 -> V_131 ) ;
}
V_30 = F_5 ( V_123 -> V_133 . V_8 ,
T_3 , V_91 ) ;
F_6 ( & V_30 -> V_91 ) ;
F_2 ( V_30 -> V_90 ) ;
F_2 ( V_30 -> V_132 ) ;
F_2 ( ! F_4 ( & V_30 -> V_128 ) ) ;
V_2 = F_5 ( V_30 -> V_128 . V_8 ,
T_1 , V_9 ) ;
if ( V_30 -> V_231 == V_2 )
F_121 ( V_30 ) ;
F_6 ( & V_2 -> V_9 ) ;
V_30 -> V_132 = 0 ;
F_59 ( & V_123 -> V_127 ) ;
if ( ! F_4 ( & V_230 ) ) {
F_41 ( NULL , & V_230 , 0 ) ;
}
V_33 = F_52 ( V_30 , V_2 ) ;
if ( V_33 == - V_53 || V_33 == - V_45 ) {
F_55 ( & V_123 -> V_127 ) ;
F_16 ( & V_2 -> V_9 ,
& V_30 -> V_128 ) ;
} else {
F_51 ( V_2 ) ;
F_55 ( & V_123 -> V_127 ) ;
V_30 -> V_132 = 1 ;
}
if ( V_33 == - V_53 ) {
} else if ( V_30 -> V_132 &&
! F_4 ( & V_30 -> V_128 ) ) {
F_49 ( & V_30 -> V_91 ,
& V_123 -> V_133 ) ;
} else {
V_30 -> V_90 = 0 ;
F_39 ( V_30 ) ;
}
V_229 = 1 ;
}
if ( ! V_229 ||
++ V_225 == V_232 ) {
F_59 ( & V_123 -> V_127 ) ;
V_225 = 0 ;
if ( ! V_229 ) {
F_122 (
V_123 -> V_134 ,
! F_112 ( V_123 ) , V_33 ) ;
F_2 ( V_33 == 0 ) ;
} else {
F_123 () ;
}
F_55 ( & V_123 -> V_127 ) ;
}
}
F_59 ( & V_123 -> V_127 ) ;
F_101 () ;
return 0 ;
}
void F_124 ( T_3 * V_30 )
{
T_9 * V_123 ;
V_123 = V_30 -> V_124 ;
F_55 ( & V_123 -> V_127 ) ;
V_30 -> V_221 = 1 ;
if ( ! V_30 -> V_217 ) {
F_49 ( & V_30 -> V_219 ,
& V_123 -> V_220 ) ;
V_30 -> V_217 = 1 ;
F_74 ( V_30 ) ;
F_58 ( & V_123 -> V_134 ) ;
}
F_59 ( & V_123 -> V_127 ) ;
}
void F_125 ( T_3 * V_30 )
{
T_9 * V_123 ;
V_123 = V_30 -> V_124 ;
F_55 ( & V_123 -> V_127 ) ;
V_30 -> V_132 = 1 ;
if ( ! V_30 -> V_90 &&
! F_4 ( & V_30 -> V_128 ) ) {
F_49 ( & V_30 -> V_91 ,
& V_123 -> V_133 ) ;
V_30 -> V_90 = 1 ;
F_74 ( V_30 ) ;
F_58 ( & V_123 -> V_134 ) ;
}
F_59 ( & V_123 -> V_127 ) ;
}
T_14 *
F_126 ( T_15 * V_233 )
{
T_16 V_234 = 0 ;
if ( V_233 -> V_235 == V_236 )
V_234 = V_233 -> V_237 ;
else if ( V_233 -> V_235 == F_127 ( V_236 ) )
V_234 = F_127 ( V_233 -> V_237 ) ;
if ( V_234 != 0 ) {
#if V_238
if ( * V_49 . V_239 == 1 )
return NULL ;
if ( * V_49 . V_239 == 2 &&
V_234 == V_185 )
return NULL ;
#endif
if ( V_234 == V_184 )
return & V_240 ;
if ( V_234 == V_185 )
return & V_241 ;
return NULL ;
}
if ( V_233 -> V_235 == F_43 ( V_242 ) ) {
T_17 * V_243 = ( T_17 * ) V_233 ;
F_128 ( sizeof ( T_17 ) ==
F_91 ( T_15 , V_244 ) ) ;
if ( V_243 -> V_245 == F_129 ( V_246 ) &&
V_243 -> V_247 == F_129 ( V_248 ) )
return & V_78 ;
}
return NULL ;
}
int
F_130 ( T_5 * V_65 , T_3 * V_30 ,
T_18 V_249 , T_15 * V_233 )
{
T_19 * V_250 = ( T_19 * ) V_65 -> V_251 ;
F_2 ( V_233 -> V_252 <= V_253 ) ;
F_2 ( V_30 -> V_77 != NULL ) ;
V_233 -> V_244 = V_65 -> V_254 ;
V_233 -> V_255 = V_249 ;
V_233 -> V_256 = V_257 . V_258 ;
V_233 -> V_259 = V_250 -> V_260 ;
V_233 -> V_261 = V_30 -> V_182 ;
return V_30 -> V_77 -> V_262 ( V_30 , V_233 ) ;
}
int
F_131 ( int type )
{
switch ( type )
{
case V_263 :
case V_264 :
return ( type ) ;
case V_265 :
return V_266 ;
case V_266 :
return V_265 ;
default:
return ( V_267 ) ;
}
}
int
F_132 ( T_5 * V_65 , T_3 * V_30 ,
T_15 * V_233 , T_12 * V_268 ,
T_2 * V_269 )
{
T_20 * V_270 = V_30 -> V_46 ;
int V_271 = ( V_30 -> V_77 != NULL ) ;
int V_272 ;
int V_273 ;
int V_33 ;
T_14 * V_274 ;
T_12 V_275 ;
F_2 ( ! V_271 == ! ( V_30 -> V_182 != V_267 ) ) ;
V_272 = V_271 ? * V_49 . V_50 :
F_133 () ;
V_33 = F_134 ( V_270 , & V_233 -> V_235 , sizeof ( V_233 -> V_235 ) , V_272 ) ;
if ( V_33 != 0 ) {
F_12 ( L_33 ,
V_33 , & V_30 -> V_97 ) ;
F_2 ( V_33 < 0 ) ;
return V_33 ;
}
if ( V_233 -> V_235 != V_236 &&
V_233 -> V_235 != F_127 ( V_236 ) &&
V_233 -> V_235 != F_43 ( V_242 ) ) {
F_12 ( L_34
L_35 , F_135 ( V_233 -> V_235 ) ,
V_242 ,
& V_30 -> V_97 ) ;
return - V_64 ;
}
V_33 = F_134 ( V_270 , & V_233 -> V_237 ,
sizeof( V_233 -> V_237 ) , V_272 ) ;
if ( V_33 != 0 ) {
F_12 ( L_33 ,
V_33 , & V_30 -> V_97 ) ;
F_2 ( V_33 < 0 ) ;
return V_33 ;
}
V_274 = F_126 ( V_233 ) ;
if ( V_274 == NULL ) {
if ( ! V_271 ) {
V_30 -> V_77 = & V_241 ;
#if V_238
if ( * V_49 . V_239 == 2 )
V_30 -> V_77 = & V_240 ;
else if ( * V_49 . V_239 == 1 )
V_30 -> V_77 = & V_78 ;
#endif
V_233 -> V_252 = 0 ;
F_130 ( V_65 , V_30 , V_65 -> V_254 , V_233 ) ;
}
F_12 ( L_36
L_37 ,
V_30 -> V_77 -> V_183 ,
& V_30 -> V_97 ) ;
return - V_64 ;
}
V_273 = ( V_30 -> V_77 == V_274 ) ;
V_30 -> V_77 = V_274 ;
V_33 = V_30 -> V_77 -> V_276 ( V_30 , V_233 , V_272 ) ;
if ( V_33 != 0 ) {
F_12 ( L_38 ,
V_33 , & V_30 -> V_97 ) ;
F_2 ( V_33 < 0 ) ;
return V_33 ;
}
* V_269 = V_233 -> V_259 ;
if ( V_233 -> V_244 == V_277 ) {
F_12 ( L_39
L_40 , & V_30 -> V_97 ) ;
return - V_64 ;
}
if ( ! V_271 &&
V_30 -> V_99 > V_278 ) {
V_275 . V_144 = V_30 -> V_99 | V_145 ;
V_275 . V_147 = F_136 ( F_137 ( V_65 -> V_254 ) , V_30 -> V_97 ) ;
} else {
V_275 . V_147 = V_233 -> V_244 ;
V_275 . V_144 = V_233 -> V_256 ;
}
if ( ! V_271 ) {
* V_268 = V_275 ;
V_30 -> V_182 = F_131 ( V_233 -> V_261 ) ;
if ( V_30 -> V_182 == V_267 ) {
F_12 ( L_41 ,
V_233 -> V_261 , F_61 ( * V_268 ) ,
& V_30 -> V_97 ) ;
return - V_64 ;
}
return 0 ;
}
if ( V_268 -> V_144 != V_275 . V_144 ||
V_268 -> V_147 != V_275 . V_147 ) {
F_138 ( 0x130 , L_42
L_43
L_44
L_45 ,
F_61 ( * V_268 ) ,
& V_30 -> V_97 ,
F_61 ( V_275 ) ) ;
return - V_64 ;
}
if ( V_233 -> V_261 == V_267 ) {
return V_273 ? V_279 : V_64 ;
}
if ( F_131 ( V_233 -> V_261 ) != V_30 -> V_182 ) {
F_12 ( L_46 ,
V_30 -> V_182 , F_61 ( * V_268 ) ,
& V_30 -> V_97 ,
V_233 -> V_261 ) ;
return - V_64 ;
}
return 0 ;
}
int
F_139 ( T_8 * V_100 )
{
F_119 ( V_280 ) ;
T_7 * V_75 = V_100 -> V_281 ;
int type ;
int V_282 ;
T_20 * V_270 ;
T_11 V_283 ;
int V_284 = 0 ;
int V_33 = 0 ;
V_283 = F_57 ( F_28 () ,
F_24 ( * V_49 . V_50 ) ) ;
F_84 ( & V_5 . V_143 ) ;
F_2 ( V_100 -> V_101 ) ;
F_2 ( ! V_100 -> V_102 ) ;
V_100 -> V_102 = 1 ;
for (; ; ) {
V_282 = F_64 () & ~ V_100 -> V_103 ;
if ( V_75 -> V_285 || V_100 -> V_286 ||
V_282 == 0 ) {
V_284 = 0 ;
break;
}
if ( V_75 -> V_148 > 0 ) {
F_53 ( V_86 ,
L_47 ,
F_44 ( V_75 -> V_98 . V_147 ) , V_75 -> V_148 ) ;
V_284 = 1 ;
}
if ( V_284 )
break;
if ( ( V_282 & ( 1 << V_263 ) ) != 0 ) {
type = V_263 ;
} else if ( ( V_282 & ( 1 << V_264 ) ) != 0 ) {
type = V_264 ;
} else if ( ( V_282 & ( 1 << V_265 ) ) != 0 ) {
type = V_265 ;
} else {
F_2 ( ( V_282 & ( 1 << V_266 ) ) != 0 ) ;
type = V_266 ;
}
F_85 ( & V_5 . V_143 ) ;
if ( F_56 ( F_28 () , V_283 ) ) {
V_33 = - V_287 ;
F_140 ( V_33 , V_75 -> V_98 . V_147 ,
V_100 -> V_139 ,
V_100 -> V_288 ) ;
goto V_289;
}
V_33 = F_141 ( & V_270 , V_75 -> V_98 . V_147 ,
V_100 -> V_290 ,
V_100 -> V_139 , V_100 -> V_288 ) ;
if ( V_33 != 0 )
goto V_289;
V_33 = F_142 ( V_75 -> V_68 , V_100 , V_270 , type ) ;
if ( V_33 < 0 ) {
F_140 ( V_33 , V_75 -> V_98 . V_147 ,
V_100 -> V_139 ,
V_100 -> V_288 ) ;
goto V_289;
}
V_284 = ( V_33 != 0 ) ;
if ( V_284 )
F_53 ( V_86 , L_48 ,
F_44 ( V_75 -> V_98 . V_147 ) ) ;
F_84 ( & V_5 . V_143 ) ;
}
V_100 -> V_101 = 0 ;
V_100 -> V_102 = 0 ;
if ( V_284 ) {
if ( V_33 == V_279 ||
( V_33 == 0 && V_75 -> V_148 > 0 ) ) {
V_100 -> V_137 =
F_24 ( * V_49 . V_291 ) / 1000 ;
V_100 -> V_138 = F_57 ( F_28 () ,
V_100 -> V_137 ) ;
}
F_63 ( V_100 ) ;
}
F_85 ( & V_5 . V_143 ) ;
return V_284 ;
V_289:
F_84 ( & V_5 . V_143 ) ;
V_100 -> V_101 = 0 ;
V_100 -> V_102 = 0 ;
V_100 -> V_137 *= 2 ;
V_100 -> V_137 =
F_143 ( V_100 -> V_137 ,
F_24 ( * V_49 . V_291 ) / 1000 ) ;
V_100 -> V_137 =
F_104 ( V_100 -> V_137 ,
F_24 ( * V_49 . V_292 ) / 1000 ) ;
F_2 ( V_100 -> V_137 != 0 ) ;
V_100 -> V_138 = F_57 ( F_28 () ,
V_100 -> V_137 ) ;
if ( ! F_4 ( & V_75 -> V_149 ) &&
V_75 -> V_148 == 0 &&
F_79 ( V_75 ) == NULL ) {
T_3 * V_30 ;
if ( ! F_4 ( & V_75 -> V_293 ) ) {
V_30 = F_5 ( V_75 -> V_293 . V_8 ,
T_3 , V_114 ) ;
F_2 ( V_30 -> V_77 == & V_241 ) ;
}
F_144 ( & V_75 -> V_149 , & V_280 ) ;
}
#if 0
if (!route->ksnr_deleted) {
list_del(&route->ksnr_list);
list_add_tail(&route->ksnr_list, &peer->ksnp_routes);
}
#endif
F_85 ( & V_5 . V_143 ) ;
F_145 ( V_75 ) ;
F_41 ( V_75 -> V_68 , & V_280 , 1 ) ;
return 0 ;
}
static int
F_146 ( long V_294 , long * V_272 )
{
char V_173 [ 16 ] ;
int V_33 ;
int V_295 = V_5 . V_296 +
V_5 . V_297 ;
if ( F_147 ( V_5 . V_298 < V_299 ) ) {
return 0 ;
}
if ( V_295 >= * V_49 . V_300 ||
V_295 > V_5 . V_301 + V_302 ) {
return 0 ;
}
if ( F_4 ( & V_5 . V_106 ) ) {
return 0 ;
}
if ( V_294 - V_5 . V_303 <= 1 ) {
* V_272 = F_24 ( 1 ) ;
return 0 ;
}
if ( V_5 . V_296 > 0 ) {
return 0 ;
}
V_5 . V_304 = V_294 ;
V_5 . V_296 ++ ;
F_59 ( & V_5 . V_104 ) ;
snprintf ( V_173 , sizeof( V_173 ) , L_49 , V_295 ) ;
V_33 = F_96 ( V_305 , NULL , V_173 ) ;
F_55 ( & V_5 . V_104 ) ;
if ( V_33 == 0 )
return 1 ;
F_2 ( V_5 . V_296 > 0 ) ;
V_5 . V_296 -- ;
V_5 . V_303 = F_148 () ;
return 1 ;
}
static int
F_149 ( long V_294 , long * V_272 )
{
int V_306 ;
if ( F_147 ( V_5 . V_298 < V_299 ) ) {
return 0 ;
}
if ( V_5 . V_296 > 0 ) {
return 0 ;
}
if ( V_5 . V_297 <=
* V_49 . V_307 ) {
return 0 ;
}
V_306 = ( int ) ( V_5 . V_304 +
V_308 - V_294 ) ;
* V_272 = ( V_306 > 0 ) ? F_24 ( V_306 ) :
F_24 ( V_308 ) ;
if ( V_306 > 0 )
return 0 ;
return V_5 . V_297 >
V_5 . V_301 + V_302 ;
}
static T_8 *
F_150 ( signed long * V_309 )
{
T_8 * V_100 ;
T_11 V_135 ;
V_135 = F_28 () ;
F_151 (route, &ksocknal_data.ksnd_connd_routes,
ksnr_connd_list) {
if ( V_100 -> V_137 == 0 ||
F_56 ( V_135 , V_100 -> V_138 ) )
return V_100 ;
if ( * V_309 == V_310 ||
( int ) * V_309 > ( int ) ( V_100 -> V_138 - V_135 ) )
* V_309 = ( int ) ( V_100 -> V_138 - V_135 ) ;
}
return NULL ;
}
int
V_305 ( void * V_172 )
{
T_21 * V_311 = & V_5 . V_104 ;
T_22 * V_312 ;
T_23 V_313 ;
int V_225 = 0 ;
int V_314 = 0 ;
F_116 () ;
F_152 ( & V_313 ) ;
F_55 ( V_311 ) ;
F_2 ( V_5 . V_296 > 0 ) ;
V_5 . V_296 -- ;
V_5 . V_297 ++ ;
while ( ! V_5 . V_222 ) {
T_8 * V_100 = NULL ;
long V_294 = F_148 () ;
long V_272 = V_310 ;
int V_315 = 0 ;
if ( F_149 ( V_294 , & V_272 ) ) {
F_58 ( & V_5 . V_107 ) ;
break;
}
if ( F_146 ( V_294 , & V_272 ) ) {
V_315 = 1 ;
}
if ( ! F_4 ( & V_5 . V_316 ) ) {
V_312 = F_5 ( V_5 . V_316 . \
V_8 , T_22 , V_317 ) ;
F_6 ( & V_312 -> V_317 ) ;
F_59 ( V_311 ) ;
V_315 = 1 ;
F_142 ( V_312 -> V_318 , NULL ,
V_312 -> V_319 , V_267 ) ;
F_153 ( V_312 -> V_318 ) ;
F_17 ( V_312 , sizeof( * V_312 ) ) ;
F_55 ( V_311 ) ;
}
if ( V_5 . V_301 + V_302 <
V_5 . V_297 ) {
V_100 = F_150 ( & V_272 ) ;
}
if ( V_100 != NULL ) {
F_6 ( & V_100 -> V_105 ) ;
V_5 . V_301 ++ ;
F_59 ( V_311 ) ;
V_315 = 1 ;
if ( F_139 ( V_100 ) ) {
if ( V_314 ++ > V_320 ) {
F_54 ( L_50
L_51 ,
& V_100 -> V_139 ) ;
V_314 = 0 ;
}
} else {
V_314 = 0 ;
}
F_154 ( V_100 ) ;
F_55 ( V_311 ) ;
V_5 . V_301 -- ;
}
if ( V_315 ) {
if ( ++ V_225 < V_232 )
continue;
F_59 ( V_311 ) ;
V_225 = 0 ;
F_123 () ;
F_55 ( V_311 ) ;
continue;
}
F_155 ( V_321 ) ;
F_156 ( & V_5 . V_107 , & V_313 ) ;
F_59 ( V_311 ) ;
V_225 = 0 ;
F_157 ( & V_313 , V_321 , V_272 ) ;
F_155 ( V_322 ) ;
F_158 ( & V_5 . V_107 , & V_313 ) ;
F_55 ( V_311 ) ;
}
V_5 . V_297 -- ;
F_59 ( V_311 ) ;
F_101 () ;
return 0 ;
}
T_3 *
F_159 ( T_7 * V_75 )
{
T_3 * V_30 ;
struct V_69 * V_323 ;
F_69 (ctmp, &peer->ksnp_conns) {
int error ;
V_30 = F_5 ( V_323 , T_3 , V_114 ) ;
F_2 ( ! V_30 -> V_42 ) ;
error = F_160 ( V_30 -> V_46 ) ;
if ( error != 0 ) {
F_74 ( V_30 ) ;
switch ( error ) {
case V_96 :
F_42 ( L_52
L_53
L_54 ,
F_61 ( V_75 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
break;
case V_287 :
F_42 ( L_52
L_55
L_56 ,
F_61 ( V_75 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
break;
default:
F_42 ( L_57
L_58
L_59 , error ,
F_61 ( V_75 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
break;
}
return ( V_30 ) ;
}
if ( V_30 -> V_58 &&
F_56 ( F_28 () ,
V_30 -> V_57 ) ) {
F_74 ( V_30 ) ;
F_42 ( L_60
L_61 ,
F_61 ( V_75 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ,
V_30 -> V_186 ,
V_30 -> V_59 ,
V_30 -> V_60 ) ;
return ( V_30 ) ;
}
if ( ( ! F_4 ( & V_30 -> V_128 ) ||
F_26 ( V_30 -> V_46 ) != 0 ) &&
F_56 ( F_28 () ,
V_30 -> V_48 ) ) {
F_74 ( V_30 ) ;
F_42 ( L_62
L_63 ,
F_61 ( V_75 -> V_98 ) ,
& V_30 -> V_97 ,
V_30 -> V_99 ) ;
return ( V_30 ) ;
}
}
return ( NULL ) ;
}
static inline void
F_161 ( T_7 * V_75 )
{
T_1 * V_2 ;
F_119 ( V_324 ) ;
F_84 ( & V_5 . V_143 ) ;
while ( ! F_4 ( & V_75 -> V_149 ) ) {
V_2 = F_5 ( V_75 -> V_149 . V_8 ,
T_1 , V_9 ) ;
if ( ! F_56 ( F_28 () ,
V_2 -> V_81 ) )
break;
F_6 ( & V_2 -> V_9 ) ;
F_49 ( & V_2 -> V_9 , & V_324 ) ;
}
F_85 ( & V_5 . V_143 ) ;
F_41 ( V_75 -> V_68 , & V_324 , 1 ) ;
}
int
F_162 ( T_7 * V_75 )
{
T_9 * V_123 ;
T_3 * V_30 ;
T_1 * V_2 ;
if ( F_4 ( & V_75 -> V_293 ) )
return 0 ;
if ( V_75 -> V_325 != & V_241 )
return 0 ;
if ( * V_49 . V_326 <= 0 ||
F_163 ( F_28 () ,
F_57 ( V_75 -> V_52 ,
F_24 ( * V_49 . V_326 ) ) ) )
return 0 ;
if ( F_163 ( F_28 () ,
V_75 -> V_327 ) )
return 0 ;
V_75 -> V_327 = F_27 ( 10 ) ;
V_30 = F_68 ( V_75 , NULL , 1 ) ;
if ( V_30 != NULL ) {
V_123 = V_30 -> V_124 ;
F_55 ( & V_123 -> V_127 ) ;
if ( ! F_4 ( & V_30 -> V_128 ) ) {
F_59 ( & V_123 -> V_127 ) ;
return 0 ;
}
F_59 ( & V_123 -> V_127 ) ;
}
F_83 ( & V_5 . V_143 ) ;
V_2 = F_11 ( 1 , 1 ) ;
if ( V_2 == NULL ) {
F_81 ( & V_5 . V_143 ) ;
return - V_53 ;
}
if ( F_80 ( V_75 -> V_68 , V_2 , V_75 -> V_98 ) == 0 ) {
F_81 ( & V_5 . V_143 ) ;
return 1 ;
}
F_14 ( V_2 ) ;
F_81 ( & V_5 . V_143 ) ;
return - V_67 ;
}
void
F_164 ( int V_328 )
{
struct V_69 * V_329 = & V_5 . V_330 [ V_328 ] ;
T_7 * V_75 ;
T_3 * V_30 ;
T_1 * V_2 ;
V_199:
F_81 ( & V_5 . V_143 ) ;
F_151 (peer, peers, ksnp_list) {
T_11 V_283 = 0 ;
int V_331 = 0 ;
int V_332 = 0 ;
if ( F_162 ( V_75 ) != 0 ) {
F_83 ( & V_5 . V_143 ) ;
goto V_199;
}
V_30 = F_159 ( V_75 ) ;
if ( V_30 != NULL ) {
F_83 ( & V_5 . V_143 ) ;
F_62 ( V_30 , - V_287 ) ;
F_39 ( V_30 ) ;
goto V_199;
}
if ( ! F_4 ( & V_75 -> V_149 ) ) {
T_1 * V_2 =
F_5 ( V_75 -> V_149 . V_8 ,
T_1 , V_9 ) ;
if ( F_56 ( F_28 () ,
V_2 -> V_81 ) ) {
F_165 ( V_75 ) ;
F_83 ( & V_5 . V_143 ) ;
F_161 ( V_75 ) ;
F_166 ( V_75 ) ;
goto V_199;
}
}
if ( F_4 ( & V_75 -> V_85 ) )
continue;
F_3 ( & V_75 -> V_80 ) ;
F_151 (tx, &peer->ksnp_zc_req_list, tx_zc_list) {
if ( ! F_56 ( F_28 () ,
V_2 -> V_81 ) )
break;
if ( V_2 -> V_18 -> V_42 )
continue;
V_332 ++ ;
}
if ( V_332 == 0 ) {
F_7 ( & V_75 -> V_80 ) ;
continue;
}
V_2 = F_5 ( V_75 -> V_85 . V_8 ,
T_1 , V_84 ) ;
V_283 = V_2 -> V_81 ;
V_331 = V_2 -> V_34 ;
V_30 = V_2 -> V_18 ;
F_74 ( V_30 ) ;
F_7 ( & V_75 -> V_80 ) ;
F_83 ( & V_5 . V_143 ) ;
F_12 ( L_64
L_65
L_66 ,
V_332 , F_44 ( V_75 -> V_98 . V_147 ) , V_2 ,
F_78 ( F_28 () - V_283 ) ,
V_331 , F_26 ( V_30 -> V_46 ) ) ;
F_62 ( V_30 , - V_287 ) ;
F_39 ( V_30 ) ;
goto V_199;
}
F_83 ( & V_5 . V_143 ) ;
}
int
F_167 ( void * V_172 )
{
T_23 V_313 ;
T_3 * V_30 ;
T_9 * V_123 ;
struct V_69 V_333 ;
int V_334 ;
T_24 V_272 ;
int V_335 ;
int V_336 = 0 ;
T_11 V_283 = F_28 () ;
F_116 () ;
F_168 ( & V_333 ) ;
F_152 ( & V_313 ) ;
F_55 ( & V_5 . V_89 ) ;
while ( ! V_5 . V_222 ) {
if ( ! F_4 ( & V_5 . V_337 ) ) {
V_30 = F_5 ( V_5 . \
V_337 . V_8 ,
T_3 , V_114 ) ;
F_6 ( & V_30 -> V_114 ) ;
F_59 ( & V_5 . V_89 ) ;
F_169 ( V_30 ) ;
F_39 ( V_30 ) ;
F_55 ( & V_5 . V_89 ) ;
continue;
}
if ( ! F_4 ( & V_5 . V_338 ) ) {
V_30 = F_5 ( V_5 . V_338 .\
V_8 , T_3 , V_114 ) ;
F_6 ( & V_30 -> V_114 ) ;
F_59 ( & V_5 . V_89 ) ;
F_170 ( V_30 ) ;
F_55 ( & V_5 . V_89 ) ;
continue;
}
if ( ! F_4 ( & V_5 . V_92 ) ) {
F_16 ( & V_333 ,
& V_5 . V_92 ) ;
F_120 ( & V_5 . V_92 ) ;
}
F_59 ( & V_5 . V_89 ) ;
V_334 = 0 ;
while ( ! F_4 ( & V_333 ) ) {
V_30 = F_5 ( V_333 . V_8 ,
T_3 , V_91 ) ;
F_6 ( & V_30 -> V_91 ) ;
V_123 = V_30 -> V_124 ;
F_55 ( & V_123 -> V_127 ) ;
F_2 ( V_30 -> V_90 ) ;
V_30 -> V_132 = 1 ;
F_49 ( & V_30 -> V_91 ,
& V_123 -> V_133 ) ;
F_58 ( & V_123 -> V_134 ) ;
F_59 ( & V_123 -> V_127 ) ;
V_334 ++ ;
}
while ( ( V_272 = F_171 ( V_283 ,
F_28 () ) ) <= 0 ) {
const int V_332 = 4 ;
const int V_339 = 1 ;
int V_340 = V_5 . V_341 ;
if ( * V_49 . V_50 > V_332 * V_339 )
V_340 = ( V_340 * V_332 * V_339 ) /
* V_49 . V_50 ;
if ( V_340 == 0 )
V_340 = 1 ;
for ( V_335 = 0 ; V_335 < V_340 ; V_335 ++ ) {
F_164 ( V_336 ) ;
V_336 = ( V_336 + 1 ) %
V_5 . V_341 ;
}
V_283 = F_57 ( V_283 , F_24 ( V_339 ) ) ;
}
if ( V_334 != 0 ) {
V_272 = V_93 ;
}
V_5 . V_94 =
F_57 ( F_28 () , V_272 ) ;
F_155 ( V_321 ) ;
F_172 ( & V_5 . V_95 , & V_313 ) ;
if ( ! V_5 . V_222 &&
F_4 ( & V_5 . V_337 ) &&
F_4 ( & V_5 . V_338 ) )
F_157 ( & V_313 , V_321 ,
V_272 ) ;
F_155 ( V_322 ) ;
F_158 ( & V_5 . V_95 , & V_313 ) ;
F_55 ( & V_5 . V_89 ) ;
}
F_59 ( & V_5 . V_89 ) ;
F_101 () ;
return 0 ;
}
