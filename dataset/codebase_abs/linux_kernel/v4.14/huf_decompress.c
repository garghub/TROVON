static T_1 F_1 ( const T_2 * V_1 )
{
T_1 V_2 ;
memcpy ( & V_2 , V_1 , sizeof( V_2 ) ) ;
return V_2 ;
}
T_3 F_2 ( T_2 * V_3 , const void * V_4 , T_3 V_5 , void * V_6 , T_3 V_7 )
{
T_4 V_8 = 0 ;
T_4 V_9 = 0 ;
T_3 V_10 ;
void * const V_11 = V_3 + 1 ;
T_5 * const V_12 = ( T_5 * ) V_11 ;
T_4 * V_13 ;
T_6 * V_14 ;
T_3 V_15 = 0 ;
V_13 = ( T_4 * ) V_6 + V_15 ;
V_15 += V_16 + 1 ;
V_14 = ( T_6 * ) ( ( T_4 * ) V_6 + V_15 ) ;
V_15 += F_3 ( V_17 + 1 , sizeof( T_4 ) ) >> 2 ;
if ( ( V_15 << 2 ) > V_7 )
return ERROR ( V_18 ) ;
V_6 = ( T_4 * ) V_6 + V_15 ;
V_7 -= ( V_15 << 2 ) ;
F_4 ( sizeof( T_1 ) == sizeof( T_2 ) ) ;
V_10 = F_5 ( V_14 , V_17 + 1 , V_13 , & V_9 , & V_8 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_6 ( V_10 ) )
return V_10 ;
{
T_1 V_2 = F_1 ( V_3 ) ;
if ( V_8 > ( T_4 ) ( V_2 . V_19 + 1 ) )
return ERROR ( V_18 ) ;
V_2 . V_20 = 0 ;
V_2 . V_8 = ( T_6 ) V_8 ;
memcpy ( V_3 , & V_2 , sizeof( V_2 ) ) ;
}
{
T_4 V_21 , V_22 = 0 ;
for ( V_21 = 1 ; V_21 < V_8 + 1 ; V_21 ++ ) {
T_4 const V_23 = V_22 ;
V_22 += ( V_13 [ V_21 ] << ( V_21 - 1 ) ) ;
V_13 [ V_21 ] = V_23 ;
}
}
{
T_4 V_21 ;
for ( V_21 = 0 ; V_21 < V_9 ; V_21 ++ ) {
T_4 const V_24 = V_14 [ V_21 ] ;
T_4 const V_25 = ( 1 << V_24 ) >> 1 ;
T_4 V_26 ;
T_5 V_27 ;
V_27 . V_28 = ( T_6 ) V_21 ;
V_27 . V_29 = ( T_6 ) ( V_8 + 1 - V_24 ) ;
for ( V_26 = V_13 [ V_24 ] ; V_26 < V_13 [ V_24 ] + V_25 ; V_26 ++ )
V_12 [ V_26 ] = V_27 ;
V_13 [ V_24 ] += V_25 ;
}
}
return V_10 ;
}
static T_6 F_7 ( T_7 * V_30 , const T_5 * V_12 , const T_4 V_31 )
{
T_3 const V_32 = F_8 ( V_30 , V_31 ) ;
T_6 const V_33 = V_12 [ V_32 ] . V_28 ;
F_9 ( V_30 , V_12 [ V_32 ] . V_29 ) ;
return V_33 ;
}
T_8 T_3 F_10 ( T_6 * V_34 , T_7 * const V_35 , T_6 * const V_36 , const T_5 * const V_12 , const T_4 V_31 )
{
T_6 * const V_37 = V_34 ;
while ( ( F_11 ( V_35 ) == V_38 ) && ( V_34 <= V_36 - 4 ) ) {
F_12 ( V_34 , V_35 ) ;
F_13 ( V_34 , V_35 ) ;
F_12 ( V_34 , V_35 ) ;
F_14 ( V_34 , V_35 ) ;
}
while ( ( F_11 ( V_35 ) == V_38 ) && ( V_34 < V_36 ) )
F_14 ( V_34 , V_35 ) ;
while ( V_34 < V_36 )
F_14 ( V_34 , V_35 ) ;
return V_36 - V_37 ;
}
static T_3 F_15 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_6 * V_43 = ( T_6 * ) V_39 ;
T_6 * const V_44 = V_43 + V_40 ;
const void * V_11 = V_3 + 1 ;
const T_5 * const V_12 = ( const T_5 * ) V_11 ;
T_7 V_45 ;
T_1 const V_2 = F_1 ( V_3 ) ;
T_4 const V_31 = V_2 . V_8 ;
{
T_3 const V_46 = F_16 ( & V_45 , V_41 , V_42 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
F_10 ( V_43 , & V_45 , V_44 , V_12 , V_31 ) ;
if ( ! F_17 ( & V_45 ) )
return ERROR ( V_47 ) ;
return V_40 ;
}
T_3 F_18 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 V_2 = F_1 ( V_3 ) ;
if ( V_2 . V_20 != 0 )
return ERROR ( V_48 ) ;
return F_15 ( V_39 , V_40 , V_41 , V_42 , V_3 ) ;
}
T_3 F_19 ( T_2 * V_49 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
const T_6 * V_50 = ( const T_6 * ) V_41 ;
T_3 const V_51 = F_2 ( V_49 , V_41 , V_42 , V_6 , V_7 ) ;
if ( F_6 ( V_51 ) )
return V_51 ;
if ( V_51 >= V_42 )
return ERROR ( V_52 ) ;
V_50 += V_51 ;
V_42 -= V_51 ;
return F_15 ( V_39 , V_40 , V_50 , V_42 , V_49 ) ;
}
static T_3 F_20 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
if ( V_42 < 10 )
return ERROR ( V_47 ) ;
{
const T_6 * const V_53 = ( const T_6 * ) V_41 ;
T_6 * const V_54 = ( T_6 * ) V_39 ;
T_6 * const V_44 = V_54 + V_40 ;
const void * const V_11 = V_3 + 1 ;
const T_5 * const V_12 = ( const T_5 * ) V_11 ;
T_7 V_55 ;
T_7 V_56 ;
T_7 V_57 ;
T_7 V_58 ;
T_3 const V_59 = F_21 ( V_53 ) ;
T_3 const V_60 = F_21 ( V_53 + 2 ) ;
T_3 const V_61 = F_21 ( V_53 + 4 ) ;
T_3 const V_62 = V_42 - ( V_59 + V_60 + V_61 + 6 ) ;
const T_6 * const V_63 = V_53 + 6 ;
const T_6 * const V_64 = V_63 + V_59 ;
const T_6 * const V_65 = V_64 + V_60 ;
const T_6 * const V_66 = V_65 + V_61 ;
const T_3 V_67 = ( V_40 + 3 ) / 4 ;
T_6 * const V_68 = V_54 + V_67 ;
T_6 * const V_69 = V_68 + V_67 ;
T_6 * const V_70 = V_69 + V_67 ;
T_6 * V_71 = V_54 ;
T_6 * V_72 = V_68 ;
T_6 * V_73 = V_69 ;
T_6 * V_74 = V_70 ;
T_4 V_75 ;
T_1 const V_2 = F_1 ( V_3 ) ;
T_4 const V_31 = V_2 . V_8 ;
if ( V_62 > V_42 )
return ERROR ( V_47 ) ;
{
T_3 const V_46 = F_16 ( & V_55 , V_63 , V_59 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_56 , V_64 , V_60 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_57 , V_65 , V_61 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_58 , V_66 , V_62 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
V_75 = F_11 ( & V_55 ) | F_11 ( & V_56 ) | F_11 ( & V_57 ) | F_11 ( & V_58 ) ;
for (; ( V_75 == V_38 ) && ( V_74 < ( V_44 - 7 ) ) ; ) {
F_12 ( V_71 , & V_55 ) ;
F_12 ( V_72 , & V_56 ) ;
F_12 ( V_73 , & V_57 ) ;
F_12 ( V_74 , & V_58 ) ;
F_13 ( V_71 , & V_55 ) ;
F_13 ( V_72 , & V_56 ) ;
F_13 ( V_73 , & V_57 ) ;
F_13 ( V_74 , & V_58 ) ;
F_12 ( V_71 , & V_55 ) ;
F_12 ( V_72 , & V_56 ) ;
F_12 ( V_73 , & V_57 ) ;
F_12 ( V_74 , & V_58 ) ;
F_14 ( V_71 , & V_55 ) ;
F_14 ( V_72 , & V_56 ) ;
F_14 ( V_73 , & V_57 ) ;
F_14 ( V_74 , & V_58 ) ;
V_75 = F_11 ( & V_55 ) | F_11 ( & V_56 ) | F_11 ( & V_57 ) | F_11 ( & V_58 ) ;
}
if ( V_71 > V_68 )
return ERROR ( V_47 ) ;
if ( V_72 > V_69 )
return ERROR ( V_47 ) ;
if ( V_73 > V_70 )
return ERROR ( V_47 ) ;
F_10 ( V_71 , & V_55 , V_68 , V_12 , V_31 ) ;
F_10 ( V_72 , & V_56 , V_69 , V_12 , V_31 ) ;
F_10 ( V_73 , & V_57 , V_70 , V_12 , V_31 ) ;
F_10 ( V_74 , & V_58 , V_44 , V_12 , V_31 ) ;
V_75 = F_17 ( & V_55 ) & F_17 ( & V_56 ) & F_17 ( & V_57 ) & F_17 ( & V_58 ) ;
if ( ! V_75 )
return ERROR ( V_47 ) ;
return V_40 ;
}
}
T_3 F_22 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 V_2 = F_1 ( V_3 ) ;
if ( V_2 . V_20 != 0 )
return ERROR ( V_48 ) ;
return F_20 ( V_39 , V_40 , V_41 , V_42 , V_3 ) ;
}
T_3 F_23 ( T_2 * V_76 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
const T_6 * V_50 = ( const T_6 * ) V_41 ;
T_3 const V_51 = F_2 ( V_76 , V_41 , V_42 , V_6 , V_7 ) ;
if ( F_6 ( V_51 ) )
return V_51 ;
if ( V_51 >= V_42 )
return ERROR ( V_52 ) ;
V_50 += V_51 ;
V_42 -= V_51 ;
return F_20 ( V_39 , V_40 , V_50 , V_42 , V_76 ) ;
}
static void F_24 ( T_9 * V_3 , T_4 V_77 , const T_4 V_78 , const T_4 * V_79 , const int V_80 ,
const T_10 * V_81 , const T_4 V_82 , T_4 V_83 , T_11 V_84 )
{
T_9 V_85 ;
T_4 V_13 [ V_86 + 1 ] ;
memcpy ( V_13 , V_79 , sizeof( V_13 ) ) ;
if ( V_80 > 1 ) {
T_4 V_87 , V_88 = V_13 [ V_80 ] ;
F_25 ( & ( V_85 . V_89 ) , V_84 ) ;
V_85 . V_29 = ( T_6 ) ( V_78 ) ;
V_85 . V_25 = 1 ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
V_3 [ V_87 ] = V_85 ;
}
{
T_4 V_90 ;
for ( V_90 = 0 ; V_90 < V_82 ; V_90 ++ ) {
const T_4 V_91 = V_81 [ V_90 ] . V_91 ;
const T_4 V_92 = V_81 [ V_90 ] . V_92 ;
const T_4 V_29 = V_83 - V_92 ;
const T_4 V_25 = 1 << ( V_77 - V_29 ) ;
const T_4 V_93 = V_13 [ V_92 ] ;
T_4 V_87 = V_93 ;
const T_4 V_94 = V_93 + V_25 ;
F_25 ( & ( V_85 . V_89 ) , ( T_11 ) ( V_84 + ( V_91 << 8 ) ) ) ;
V_85 . V_29 = ( T_6 ) ( V_29 + V_78 ) ;
V_85 . V_25 = 2 ;
do {
V_3 [ V_87 ++ ] = V_85 ;
} while ( V_87 < V_94 );
V_13 [ V_92 ] += V_25 ;
}
}
}
static void F_26 ( T_9 * V_3 , const T_4 V_95 , const T_10 * V_96 , const T_4 V_82 , const T_4 * V_97 ,
T_12 V_79 , const T_4 V_98 , const T_4 V_83 )
{
T_4 V_13 [ V_86 + 1 ] ;
const int V_99 = V_83 - V_95 ;
const T_4 V_100 = V_83 - V_98 ;
T_4 V_90 ;
memcpy ( V_13 , V_79 , sizeof( V_13 ) ) ;
for ( V_90 = 0 ; V_90 < V_82 ; V_90 ++ ) {
const T_11 V_91 = V_96 [ V_90 ] . V_91 ;
const T_4 V_92 = V_96 [ V_90 ] . V_92 ;
const T_4 V_29 = V_83 - V_92 ;
const T_4 V_93 = V_13 [ V_92 ] ;
const T_4 V_25 = 1 << ( V_95 - V_29 ) ;
if ( V_95 - V_29 >= V_100 ) {
T_4 V_101 ;
int V_80 = V_29 + V_99 ;
if ( V_80 < 1 )
V_80 = 1 ;
V_101 = V_97 [ V_80 ] ;
F_24 ( V_3 + V_93 , V_95 - V_29 , V_29 , V_79 [ V_29 ] , V_80 , V_96 + V_101 ,
V_82 - V_101 , V_83 , V_91 ) ;
} else {
T_9 V_85 ;
F_25 ( & ( V_85 . V_89 ) , V_91 ) ;
V_85 . V_29 = ( T_6 ) ( V_29 ) ;
V_85 . V_25 = 1 ;
{
T_4 const V_94 = V_93 + V_25 ;
T_4 V_26 ;
for ( V_26 = V_93 ; V_26 < V_94 ; V_26 ++ )
V_3 [ V_26 ] = V_85 ;
}
}
V_13 [ V_92 ] += V_25 ;
}
}
T_3 F_27 ( T_2 * V_3 , const void * V_4 , T_3 V_5 , void * V_6 , T_3 V_7 )
{
T_4 V_8 , V_102 , V_103 , V_9 ;
T_1 V_2 = F_1 ( V_3 ) ;
T_4 const V_19 = V_2 . V_19 ;
T_3 V_10 ;
void * V_11 = V_3 + 1 ;
T_9 * const V_12 = ( T_9 * ) V_11 ;
T_4 * V_97 ;
T_13 * V_13 ;
T_4 * V_104 ;
T_4 * V_105 ;
T_10 * V_106 ;
T_6 * V_107 ;
T_3 V_15 = 0 ;
F_4 ( ( sizeof( T_13 ) & 3 ) == 0 ) ;
V_13 = ( T_13 * ) ( ( T_4 * ) V_6 + V_15 ) ;
V_15 += ( sizeof( T_13 ) * V_86 ) >> 2 ;
V_104 = ( T_4 * ) V_6 + V_15 ;
V_15 += V_86 + 1 ;
V_105 = ( T_4 * ) V_6 + V_15 ;
V_15 += V_86 + 2 ;
V_106 = ( T_10 * ) ( ( T_4 * ) V_6 + V_15 ) ;
V_15 += F_3 ( sizeof( T_10 ) * ( V_17 + 1 ) , sizeof( T_4 ) ) >> 2 ;
V_107 = ( T_6 * ) ( ( T_4 * ) V_6 + V_15 ) ;
V_15 += F_3 ( V_17 + 1 , sizeof( T_4 ) ) >> 2 ;
if ( ( V_15 << 2 ) > V_7 )
return ERROR ( V_18 ) ;
V_6 = ( T_4 * ) V_6 + V_15 ;
V_7 -= ( V_15 << 2 ) ;
V_97 = V_105 + 1 ;
memset ( V_104 , 0 , sizeof( T_4 ) * ( 2 * V_86 + 2 + 1 ) ) ;
F_4 ( sizeof( T_9 ) == sizeof( T_2 ) ) ;
if ( V_19 > V_86 )
return ERROR ( V_18 ) ;
V_10 = F_5 ( V_107 , V_17 + 1 , V_104 , & V_9 , & V_8 , V_4 , V_5 , V_6 , V_7 ) ;
if ( F_6 ( V_10 ) )
return V_10 ;
if ( V_8 > V_19 )
return ERROR ( V_18 ) ;
for ( V_102 = V_8 ; V_104 [ V_102 ] == 0 ; V_102 -- ) {
}
{
T_4 V_24 , V_22 = 0 ;
for ( V_24 = 1 ; V_24 < V_102 + 1 ; V_24 ++ ) {
T_4 V_23 = V_22 ;
V_22 += V_104 [ V_24 ] ;
V_97 [ V_24 ] = V_23 ;
}
V_97 [ 0 ] = V_22 ;
V_103 = V_22 ;
}
{
T_4 V_90 ;
for ( V_90 = 0 ; V_90 < V_9 ; V_90 ++ ) {
T_4 const V_24 = V_107 [ V_90 ] ;
T_4 const V_108 = V_97 [ V_24 ] ++ ;
V_106 [ V_108 ] . V_91 = ( T_6 ) V_90 ;
V_106 [ V_108 ] . V_92 = ( T_6 ) V_24 ;
}
V_97 [ 0 ] = 0 ;
}
{
T_4 * const V_109 = V_13 [ 0 ] ;
{
int const V_110 = ( V_19 - V_8 ) - 1 ;
T_4 V_111 = 0 ;
T_4 V_24 ;
for ( V_24 = 1 ; V_24 < V_102 + 1 ; V_24 ++ ) {
T_4 V_23 = V_111 ;
V_111 += V_104 [ V_24 ] << ( V_24 + V_110 ) ;
V_109 [ V_24 ] = V_23 ;
}
}
{
T_4 const V_100 = V_8 + 1 - V_102 ;
T_4 V_78 ;
for ( V_78 = V_100 ; V_78 < V_19 - V_100 + 1 ; V_78 ++ ) {
T_4 * const V_112 = V_13 [ V_78 ] ;
T_4 V_24 ;
for ( V_24 = 1 ; V_24 < V_102 + 1 ; V_24 ++ ) {
V_112 [ V_24 ] = V_109 [ V_24 ] >> V_78 ;
}
}
}
}
F_26 ( V_12 , V_19 , V_106 , V_103 , V_105 , V_13 , V_102 , V_8 + 1 ) ;
V_2 . V_8 = ( T_6 ) V_19 ;
V_2 . V_20 = 1 ;
memcpy ( V_3 , & V_2 , sizeof( V_2 ) ) ;
return V_10 ;
}
static T_4 F_28 ( void * V_43 , T_7 * V_113 , const T_9 * V_12 , const T_4 V_31 )
{
T_3 const V_32 = F_8 ( V_113 , V_31 ) ;
memcpy ( V_43 , V_12 + V_32 , 2 ) ;
F_9 ( V_113 , V_12 [ V_32 ] . V_29 ) ;
return V_12 [ V_32 ] . V_25 ;
}
static T_4 F_29 ( void * V_43 , T_7 * V_113 , const T_9 * V_12 , const T_4 V_31 )
{
T_3 const V_32 = F_8 ( V_113 , V_31 ) ;
memcpy ( V_43 , V_12 + V_32 , 1 ) ;
if ( V_12 [ V_32 ] . V_25 == 1 )
F_9 ( V_113 , V_12 [ V_32 ] . V_29 ) ;
else {
if ( V_113 -> V_114 < ( sizeof( V_113 -> V_115 ) * 8 ) ) {
F_9 ( V_113 , V_12 [ V_32 ] . V_29 ) ;
if ( V_113 -> V_114 > ( sizeof( V_113 -> V_115 ) * 8 ) )
V_113 -> V_114 = ( sizeof( V_113 -> V_115 ) * 8 ) ;
}
}
return 1 ;
}
T_8 T_3 F_30 ( T_6 * V_34 , T_7 * V_35 , T_6 * const V_36 , const T_9 * const V_12 , const T_4 V_31 )
{
T_6 * const V_37 = V_34 ;
while ( ( F_11 ( V_35 ) == V_38 ) & ( V_34 < V_36 - ( sizeof( V_35 -> V_115 ) - 1 ) ) ) {
F_31 ( V_34 , V_35 ) ;
F_32 ( V_34 , V_35 ) ;
F_31 ( V_34 , V_35 ) ;
F_33 ( V_34 , V_35 ) ;
}
while ( ( F_11 ( V_35 ) == V_38 ) & ( V_34 <= V_36 - 2 ) )
F_33 ( V_34 , V_35 ) ;
while ( V_34 <= V_36 - 2 )
F_33 ( V_34 , V_35 ) ;
if ( V_34 < V_36 )
V_34 += F_29 ( V_34 , V_35 , V_12 , V_31 ) ;
return V_34 - V_37 ;
}
static T_3 F_34 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_7 V_45 ;
{
T_3 const V_46 = F_16 ( & V_45 , V_41 , V_42 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_6 * const V_54 = ( T_6 * ) V_39 ;
T_6 * const V_44 = V_54 + V_40 ;
const void * const V_11 = V_3 + 1 ;
const T_9 * const V_12 = ( const T_9 * ) V_11 ;
T_1 const V_2 = F_1 ( V_3 ) ;
F_30 ( V_54 , & V_45 , V_44 , V_12 , V_2 . V_8 ) ;
}
if ( ! F_17 ( & V_45 ) )
return ERROR ( V_47 ) ;
return V_40 ;
}
T_3 F_35 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 V_2 = F_1 ( V_3 ) ;
if ( V_2 . V_20 != 1 )
return ERROR ( V_48 ) ;
return F_34 ( V_39 , V_40 , V_41 , V_42 , V_3 ) ;
}
T_3 F_36 ( T_2 * V_49 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
const T_6 * V_50 = ( const T_6 * ) V_41 ;
T_3 const V_51 = F_27 ( V_49 , V_41 , V_42 , V_6 , V_7 ) ;
if ( F_6 ( V_51 ) )
return V_51 ;
if ( V_51 >= V_42 )
return ERROR ( V_52 ) ;
V_50 += V_51 ;
V_42 -= V_51 ;
return F_34 ( V_39 , V_40 , V_50 , V_42 , V_49 ) ;
}
static T_3 F_37 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
if ( V_42 < 10 )
return ERROR ( V_47 ) ;
{
const T_6 * const V_53 = ( const T_6 * ) V_41 ;
T_6 * const V_54 = ( T_6 * ) V_39 ;
T_6 * const V_44 = V_54 + V_40 ;
const void * const V_11 = V_3 + 1 ;
const T_9 * const V_12 = ( const T_9 * ) V_11 ;
T_7 V_55 ;
T_7 V_56 ;
T_7 V_57 ;
T_7 V_58 ;
T_3 const V_59 = F_21 ( V_53 ) ;
T_3 const V_60 = F_21 ( V_53 + 2 ) ;
T_3 const V_61 = F_21 ( V_53 + 4 ) ;
T_3 const V_62 = V_42 - ( V_59 + V_60 + V_61 + 6 ) ;
const T_6 * const V_63 = V_53 + 6 ;
const T_6 * const V_64 = V_63 + V_59 ;
const T_6 * const V_65 = V_64 + V_60 ;
const T_6 * const V_66 = V_65 + V_61 ;
T_3 const V_67 = ( V_40 + 3 ) / 4 ;
T_6 * const V_68 = V_54 + V_67 ;
T_6 * const V_69 = V_68 + V_67 ;
T_6 * const V_70 = V_69 + V_67 ;
T_6 * V_71 = V_54 ;
T_6 * V_72 = V_68 ;
T_6 * V_73 = V_69 ;
T_6 * V_74 = V_70 ;
T_4 V_75 ;
T_1 const V_2 = F_1 ( V_3 ) ;
T_4 const V_31 = V_2 . V_8 ;
if ( V_62 > V_42 )
return ERROR ( V_47 ) ;
{
T_3 const V_46 = F_16 ( & V_55 , V_63 , V_59 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_56 , V_64 , V_60 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_57 , V_65 , V_61 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
{
T_3 const V_46 = F_16 ( & V_58 , V_66 , V_62 ) ;
if ( F_6 ( V_46 ) )
return V_46 ;
}
V_75 = F_11 ( & V_55 ) | F_11 ( & V_56 ) | F_11 ( & V_57 ) | F_11 ( & V_58 ) ;
for (; ( V_75 == V_38 ) & ( V_74 < ( V_44 - ( sizeof( V_58 . V_115 ) - 1 ) ) ) ; ) {
F_31 ( V_71 , & V_55 ) ;
F_31 ( V_72 , & V_56 ) ;
F_31 ( V_73 , & V_57 ) ;
F_31 ( V_74 , & V_58 ) ;
F_32 ( V_71 , & V_55 ) ;
F_32 ( V_72 , & V_56 ) ;
F_32 ( V_73 , & V_57 ) ;
F_32 ( V_74 , & V_58 ) ;
F_31 ( V_71 , & V_55 ) ;
F_31 ( V_72 , & V_56 ) ;
F_31 ( V_73 , & V_57 ) ;
F_31 ( V_74 , & V_58 ) ;
F_33 ( V_71 , & V_55 ) ;
F_33 ( V_72 , & V_56 ) ;
F_33 ( V_73 , & V_57 ) ;
F_33 ( V_74 , & V_58 ) ;
V_75 = F_11 ( & V_55 ) | F_11 ( & V_56 ) | F_11 ( & V_57 ) | F_11 ( & V_58 ) ;
}
if ( V_71 > V_68 )
return ERROR ( V_47 ) ;
if ( V_72 > V_69 )
return ERROR ( V_47 ) ;
if ( V_73 > V_70 )
return ERROR ( V_47 ) ;
F_30 ( V_71 , & V_55 , V_68 , V_12 , V_31 ) ;
F_30 ( V_72 , & V_56 , V_69 , V_12 , V_31 ) ;
F_30 ( V_73 , & V_57 , V_70 , V_12 , V_31 ) ;
F_30 ( V_74 , & V_58 , V_44 , V_12 , V_31 ) ;
{
T_4 const V_116 = F_17 ( & V_55 ) & F_17 ( & V_56 ) & F_17 ( & V_57 ) & F_17 ( & V_58 ) ;
if ( ! V_116 )
return ERROR ( V_47 ) ;
}
return V_40 ;
}
}
T_3 F_38 ( void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 V_2 = F_1 ( V_3 ) ;
if ( V_2 . V_20 != 1 )
return ERROR ( V_48 ) ;
return F_37 ( V_39 , V_40 , V_41 , V_42 , V_3 ) ;
}
T_3 F_39 ( T_2 * V_76 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
const T_6 * V_50 = ( const T_6 * ) V_41 ;
T_3 V_51 = F_27 ( V_76 , V_41 , V_42 , V_6 , V_7 ) ;
if ( F_6 ( V_51 ) )
return V_51 ;
if ( V_51 >= V_42 )
return ERROR ( V_52 ) ;
V_50 += V_51 ;
V_42 -= V_51 ;
return F_37 ( V_39 , V_40 , V_50 , V_42 , V_76 ) ;
}
T_3 F_40 ( void * V_39 , T_3 V_117 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 const V_2 = F_1 ( V_3 ) ;
return V_2 . V_20 ? F_34 ( V_39 , V_117 , V_41 , V_42 , V_3 )
: F_15 ( V_39 , V_117 , V_41 , V_42 , V_3 ) ;
}
T_3 F_41 ( void * V_39 , T_3 V_117 , const void * V_41 , T_3 V_42 , const T_2 * V_3 )
{
T_1 const V_2 = F_1 ( V_3 ) ;
return V_2 . V_20 ? F_37 ( V_39 , V_117 , V_41 , V_42 , V_3 )
: F_20 ( V_39 , V_117 , V_41 , V_42 , V_3 ) ;
}
T_4 F_42 ( T_3 V_40 , T_3 V_42 )
{
T_4 const V_118 = ( T_4 ) ( V_42 * 16 / V_40 ) ;
T_4 const V_119 = ( T_4 ) ( V_40 >> 8 ) ;
T_4 const V_120 = V_121 [ V_118 ] [ 0 ] . V_122 + ( V_121 [ V_118 ] [ 0 ] . V_123 * V_119 ) ;
T_4 V_124 = V_121 [ V_118 ] [ 1 ] . V_122 + ( V_121 [ V_118 ] [ 1 ] . V_123 * V_119 ) ;
V_124 += V_124 >> 3 ;
return V_124 < V_120 ;
}
T_3 F_43 ( T_2 * V_76 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
if ( V_40 == 0 )
return ERROR ( V_125 ) ;
if ( V_42 > V_40 )
return ERROR ( V_47 ) ;
if ( V_42 == V_40 ) {
memcpy ( V_39 , V_41 , V_40 ) ;
return V_40 ;
}
if ( V_42 == 1 ) {
memset ( V_39 , * ( const T_6 * ) V_41 , V_40 ) ;
return V_40 ;
}
{
T_4 const V_126 = F_42 ( V_40 , V_42 ) ;
return V_126 ? F_39 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 )
: F_23 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 ) ;
}
}
T_3 F_44 ( T_2 * V_76 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
if ( V_40 == 0 )
return ERROR ( V_125 ) ;
if ( ( V_42 >= V_40 ) || ( V_42 <= 1 ) )
return ERROR ( V_47 ) ;
{
T_4 const V_126 = F_42 ( V_40 , V_42 ) ;
return V_126 ? F_39 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 )
: F_23 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 ) ;
}
}
T_3 F_45 ( T_2 * V_76 , void * V_39 , T_3 V_40 , const void * V_41 , T_3 V_42 , void * V_6 , T_3 V_7 )
{
if ( V_40 == 0 )
return ERROR ( V_125 ) ;
if ( V_42 > V_40 )
return ERROR ( V_47 ) ;
if ( V_42 == V_40 ) {
memcpy ( V_39 , V_41 , V_40 ) ;
return V_40 ;
}
if ( V_42 == 1 ) {
memset ( V_39 , * ( const T_6 * ) V_41 , V_40 ) ;
return V_40 ;
}
{
T_4 const V_126 = F_42 ( V_40 , V_42 ) ;
return V_126 ? F_36 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 )
: F_19 ( V_76 , V_39 , V_40 , V_41 , V_42 , V_6 , V_7 ) ;
}
}
