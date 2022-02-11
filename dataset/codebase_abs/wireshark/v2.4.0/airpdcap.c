static INT
F_1 ( const T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 V_5 ;
const T_2 * V_6 ;
T_2 * V_7 ;
T_5 V_8 = 0 ;
T_5 V_9 ;
static T_6 V_10 ;
T_7 * V_11 ;
V_5 = F_2 ( V_1 -> V_12 [ 1 ] ) ;
if ( V_5 == V_13 ) {
V_8 = F_3 ( V_1 -> V_14 ) ;
} else if ( V_5 == V_15 ) {
V_8 = F_3 ( V_1 -> V_16 ) ;
if ( V_8 < 16 ) {
return V_17 ;
}
}
if ( ( V_8 < V_18 ) ||
( V_4 < sizeof( T_1 ) ) ||
( V_8 > V_4 - sizeof( T_1 ) ) ) {
return V_17 ;
}
V_6 = ( const T_2 * ) V_1 + sizeof( T_1 ) ;
V_7 = ( T_2 * ) F_4 ( V_6 , V_8 ) ;
F_5 ( L_1 , V_7 , V_8 ) ;
F_5 ( L_2 , V_1 -> V_19 , 16 ) ;
F_5 ( L_3 , V_2 , 16 ) ;
V_11 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
memcpy ( V_11 , V_3 , sizeof( T_7 ) ) ;
V_3 -> V_20 = V_11 ;
if ( V_5 == V_13 ) {
T_2 V_21 [ 32 ] ;
T_2 V_22 [ 256 ] = { 0 } ;
T_8 V_23 ;
V_3 -> V_24 . V_25 = ( V_8 >= V_26 ) ? V_13 : V_15 ;
memcpy ( V_21 , V_1 -> V_19 , 16 ) ;
memcpy ( V_21 + 16 , V_2 , 16 ) ;
F_5 ( L_4 , V_21 , 32 ) ;
if ( F_7 ( & V_23 , V_27 , V_28 , 0 ) ) {
return V_17 ;
}
if ( F_8 ( V_23 , V_21 , sizeof( V_21 ) ) ) {
F_9 ( V_23 ) ;
return V_17 ;
}
F_10 ( V_23 , V_22 , 256 , NULL , 0 ) ;
F_10 ( V_23 , V_7 , V_8 , NULL , 0 ) ;
F_9 ( V_23 ) ;
} else if ( V_5 == V_15 ) {
T_2 V_29 ;
T_2 V_14 ;
T_5 V_30 ;
T_2 * V_31 ;
V_31 = F_11 ( V_2 , 16 , V_7 , V_8 ) ;
V_29 = FALSE ;
V_30 = 0 ;
while( V_30 < ( V_8 - 6 ) && ! V_29 ) {
T_2 V_32 ;
T_9 type ;
V_32 = V_31 [ V_30 ] ;
type = ( ( V_31 [ V_30 + 2 ] << 24 ) +
( V_31 [ V_30 + 3 ] << 16 ) +
( V_31 [ V_30 + 4 ] << 8 ) +
( V_31 [ V_30 + 5 ] ) ) ;
if ( V_32 == 0xdd && type == 0x000fac01 ) {
V_29 = TRUE ;
} else {
V_30 += V_31 [ V_30 + 1 ] + 2 ;
}
}
if ( V_29 ) {
V_14 = V_31 [ V_30 + 1 ] - 6 ;
if ( V_30 + 8 >= V_8 ||
V_14 > V_8 - V_30 - 8 ) {
F_12 ( V_31 ) ;
F_12 ( V_7 ) ;
return V_17 ;
}
memcpy ( V_7 , V_31 + V_30 + 8 , V_14 ) ;
} else {
F_12 ( V_31 ) ;
F_12 ( V_7 ) ;
return V_17 ;
}
if ( V_14 == V_26 )
V_3 -> V_24 . V_25 = V_13 ;
else
V_3 -> V_24 . V_25 = V_15 ;
F_12 ( V_31 ) ;
}
V_9 = ( V_3 -> V_24 . V_25 == V_13 ) ? V_26 : V_33 ;
if ( V_9 > V_8 ) {
F_12 ( V_7 ) ;
return V_17 ;
}
F_5 ( L_5 , V_7 , V_9 ) ;
V_3 -> V_34 = & V_10 ;
V_3 -> V_35 = TRUE ;
memset ( V_3 -> V_24 . V_36 , 0 , sizeof( V_3 -> V_24 . V_36 ) ) ;
memcpy ( V_3 -> V_24 . V_36 + 32 , V_7 , V_9 ) ;
F_12 ( V_7 ) ;
return V_37 ;
}
static T_3
F_13 (
T_10 V_38 ,
T_11 * V_39 )
{
int V_40 ;
if ( ( V_40 = F_14 ( V_38 , V_39 ) ) == - 1 ) {
if ( ( V_40 = F_15 ( V_38 , V_39 ) ) == - 1 ) {
return NULL ;
}
}
return & V_38 -> V_3 [ V_40 ] ;
}
static INT F_16 (
T_10 V_38 ,
const T_2 * V_41 ,
const T_4 V_42 ,
const T_4 V_43 ,
T_11 V_39
)
{
const T_12 * V_44 ;
T_4 V_45 ;
T_3 V_46 ;
T_3 V_3 ;
T_4 V_47 = 0 ;
const T_2 V_48 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
const T_2 V_49 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x19 , 0x58 ,
0x00 , 0x03
} ;
const T_2 V_50 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x89 , 0x0D ,
0x02 ,
0X0C
} ;
const T_1 * V_1 ;
#ifdef F_17
#define F_18 255
CHAR V_51 [ F_18 ] ;
#endif
F_19 ( L_6 ) ;
V_47 = V_42 ;
if ( memcmp ( V_41 + V_47 , V_48 , 8 ) == 0 || memcmp ( V_41 + V_47 , V_49 , 8 ) == 0 ) {
F_20 ( L_6 , L_7 , V_52 ) ;
V_47 += 8 ;
if ( V_41 [ V_47 + 1 ] != 3 ) {
F_20 ( L_6 , L_8 , V_52 ) ;
return V_17 ;
}
V_45 = F_3 ( V_41 + V_47 + 2 ) ;
if ( ( ( V_43 - V_47 - 4 ) < V_45 ) || ( V_45 < sizeof( T_1 ) ) ) {
F_20 ( L_6 , L_9 , V_52 ) ;
return V_17 ;
}
V_47 += 4 ;
V_1 = ( const T_1 * ) ( V_41 + V_47 ) ;
if (
V_1 -> type != V_53 &&
V_1 -> type != V_54 )
{
F_20 ( L_6 , L_10 , V_52 ) ;
return V_17 ;
}
V_47 += 1 ;
V_3 = F_13 ( V_38 , & V_39 ) ;
if ( V_3 == NULL ) {
F_20 ( L_6 , L_11 , V_52 ) ;
return V_55 ;
}
if ( F_21 ( V_38 , V_41 , V_3 , V_47 , V_43 ) == V_37 )
return V_37 ;
if ( V_42 + V_56 > V_43 ) {
F_20 ( L_6 , L_12 , V_52 ) ;
return V_17 ;
}
if ( F_22 ( V_41 [ V_47 + 1 ] ) != 0 ||
F_23 ( V_41 [ V_47 + 1 ] ) != 1 ||
F_24 ( V_41 [ V_47 ] ) != 1 ||
F_25 ( V_41 [ V_47 ] ) != 1 ) {
F_20 ( L_6 , L_13 , V_52 ) ;
return V_17 ;
}
memcpy ( V_39 . V_57 , V_58 , V_59 ) ;
V_3 = F_13 ( V_38 , & V_39 ) ;
if ( V_3 == NULL ) {
return V_55 ;
}
if ( ( V_44 = F_26 ( ( const V_60 * ) ( V_41 ) ) ) != NULL ) {
memcpy ( V_39 . V_57 , V_44 , V_59 ) ;
#ifdef F_17
F_27 ( V_51 , F_18 , L_14 , V_39 . V_57 [ 0 ] , V_39 . V_57 [ 1 ] , V_39 . V_57 [ 2 ] , V_39 . V_57 [ 3 ] , V_39 . V_57 [ 4 ] , V_39 . V_57 [ 5 ] ) ;
#endif
F_20 ( L_6 , V_51 , V_52 ) ;
} else {
F_20 ( L_6 , L_15 , V_61 ) ;
return V_55 ;
}
V_46 = F_13 ( V_38 , & V_39 ) ;
if ( V_46 == NULL ) {
return V_55 ;
}
return ( F_1 ( V_1 , V_46 -> V_24 . V_36 + 16 , V_3 , V_43 - V_47 + 1 ) ) ;
} else if ( memcmp ( V_41 + V_47 , V_50 , 10 ) == 0 ) {
const T_2 * V_62 , * V_63 ;
T_2 V_64 ;
T_4 V_65 , V_66 = 0 , V_67 = 0 , V_68 = 0 , V_69 = 0 ;
F_20 ( L_6 , L_16 , V_52 ) ;
V_47 += 10 ;
V_64 = V_41 [ V_47 ] ;
if ( V_64 != 1 && V_64 != 2 ) {
F_20 ( L_6 , L_17 , V_52 ) ;
return V_17 ;
}
V_47 ++ ;
V_65 = F_3 ( V_41 + V_47 ) ;
if ( V_65 != 0 ) {
F_20 ( L_6 , L_18 , V_52 ) ;
return V_17 ;
}
V_47 += 5 ;
while( V_47 < ( V_43 - 2 ) ) {
if ( V_41 [ V_47 ] == 48 ) {
V_66 = V_47 ;
} else if ( V_41 [ V_47 ] == 55 ) {
V_67 = V_47 ;
} else if ( V_41 [ V_47 ] == 56 ) {
V_69 = V_47 ;
} else if ( V_41 [ V_47 ] == 101 ) {
V_68 = V_47 ;
}
if ( V_43 < V_47 + V_41 [ V_47 + 1 ] + 2 ) {
return V_17 ;
}
V_47 += V_41 [ V_47 + 1 ] + 2 ;
}
if ( V_66 == 0 || V_67 == 0 ||
V_69 == 0 || V_68 == 0 )
{
F_20 ( L_6 , L_19 , V_52 ) ;
return V_17 ;
}
F_20 ( L_6 , L_20 , V_52 ) ;
V_62 = & V_41 [ V_68 + 8 ] ;
V_63 = & V_41 [ V_68 + 14 ] ;
if ( memcmp ( V_62 , V_63 , V_59 ) < 0 ) {
memcpy ( V_39 . V_57 , V_62 , V_59 ) ;
memcpy ( V_39 . V_70 , V_63 , V_59 ) ;
} else {
memcpy ( V_39 . V_57 , V_63 , V_59 ) ;
memcpy ( V_39 . V_70 , V_62 , V_59 ) ;
}
V_3 = F_13 ( V_38 , & V_39 ) ;
if ( V_3 == NULL ) {
return V_55 ;
}
if ( V_3 -> V_35 ) {
if ( memcmp ( V_3 -> V_24 . V_71 , V_41 + V_67 + 52 , V_72 ) == 0 ) {
return V_37 ;
} else {
T_7 * V_11 = F_28 ( T_7 , 1 ) ;
memcpy ( V_11 , V_3 , sizeof( T_7 ) ) ;
V_3 -> V_20 = V_11 ;
V_3 -> V_35 = FALSE ;
}
}
if ( F_29 ( V_3 , V_41 , V_66 , V_67 , V_69 , V_68 , V_64 )
== V_73 ) {
F_30 ( L_6 ) ;
return V_37 ;
}
} else {
F_20 ( L_6 , L_21 , V_52 ) ;
}
F_30 ( L_6 ) ;
return V_17 ;
}
INT F_31 (
T_10 V_38 ,
const T_2 * V_41 ,
const T_4 V_42 ,
const T_4 V_43 ,
T_12 * V_74 ,
T_4 * V_75 ,
T_13 V_34 ,
T_14 V_76 )
{
T_11 V_39 ;
T_12 V_77 [ V_78 ] ;
T_4 V_79 ;
#ifdef F_17
#define F_18 255
CHAR V_51 [ F_18 ] ;
#endif
F_19 ( L_22 ) ;
if ( V_38 == NULL ) {
F_20 ( L_22 , L_23 , V_61 ) ;
F_30 ( L_22 ) ;
return V_55 ;
}
if ( V_41 == NULL || V_43 == 0 ) {
F_20 ( L_22 , L_24 , V_61 ) ;
F_30 ( L_22 ) ;
return V_55 ;
}
if ( ! ( ( F_32 ( V_41 [ 0 ] ) == V_80 ) ||
( F_32 ( V_41 [ 0 ] ) == V_81 &&
( F_33 ( V_41 [ 0 ] ) == V_82 ||
F_33 ( V_41 [ 0 ] ) == V_83 ||
F_33 ( V_41 [ 0 ] ) == V_84 ) ) ) ) {
F_20 ( L_22 , L_25 , V_61 ) ;
return V_85 ;
}
if ( V_43 < ( V_86 ) ( V_42 + V_87 ) ) {
F_20 ( L_22 , L_26 , V_61 ) ;
return V_88 ;
}
if ( V_43 > V_78 ) {
F_20 ( L_22 , L_27 , V_52 ) ;
return V_89 ;
}
if ( F_34 ( ( const V_60 * ) ( V_41 ) , & V_39 ) != V_73 ) {
F_20 ( L_22 , L_28 , V_61 ) ;
return V_55 ;
}
if ( F_35 ( V_41 [ 1 ] ) == 0 ) {
if ( V_76 ) {
F_20 ( L_22 , L_29 , V_52 ) ;
return ( F_16 ( V_38 , V_41 , V_42 , V_43 , V_39 ) ) ;
}
return V_90 ;
} else {
T_3 V_3 ;
int V_47 = 0 ;
V_3 = F_13 ( V_38 , & V_39 ) ;
if ( V_3 == NULL ) {
return V_55 ;
}
V_47 = V_42 ;
if ( V_74 == NULL ) {
F_20 ( L_22 , L_30 , V_52 ) ;
V_74 = V_77 ;
V_75 = & V_79 ;
}
* V_75 = V_43 ;
memcpy ( V_74 , V_41 , * V_75 ) ;
F_20 ( L_22 , L_31 , V_52 ) ;
if ( F_36 ( V_41 [ V_47 + 3 ] ) == 0 ) {
F_20 ( L_22 , L_32 , V_52 ) ;
return F_37 ( V_38 , V_74 , V_42 , V_75 , V_34 , V_3 , V_47 ) ;
} else {
F_20 ( L_22 , L_33 , V_52 ) ;
if ( F_38 ( V_41 [ V_47 + 3 ] ) >= 1 ) {
F_20 ( L_22 , L_34 , V_52 ) ;
memcpy ( V_39 . V_57 , V_58 , V_59 ) ;
#ifdef F_17
F_27 ( V_51 , F_18 , L_14 , V_39 . V_57 [ 0 ] , V_39 . V_57 [ 1 ] , V_39 . V_57 [ 2 ] , V_39 . V_57 [ 3 ] , V_39 . V_57 [ 4 ] , V_39 . V_57 [ 5 ] ) ;
F_20 ( L_22 , V_51 , V_52 ) ;
#endif
V_3 = F_13 ( V_38 , & V_39 ) ;
if ( V_3 == NULL )
return V_55 ;
}
if ( F_39 ( V_74 , V_42 , V_75 , V_34 , V_3 , V_47 ) == V_73 ) {
if ( V_76 ) {
return ( F_16 ( V_38 , V_74 , V_42 , * V_75 , V_39 ) ) ;
} else {
return V_73 ;
}
}
}
}
return V_89 ;
}
INT F_40 (
T_10 V_38 ,
T_6 V_91 [] ,
const T_15 V_92 )
{
INT V_93 ;
INT V_94 ;
F_19 ( L_35 ) ;
if ( V_38 == NULL || V_91 == NULL ) {
F_20 ( L_35 , L_36 , V_52 ) ;
F_30 ( L_35 ) ;
return 0 ;
}
if ( V_92 > V_95 ) {
F_20 ( L_35 , L_37 , V_52 ) ;
F_30 ( L_35 ) ;
return 0 ;
}
F_41 ( V_38 ) ;
for ( V_93 = 0 , V_94 = 0 ; V_93 < ( INT ) V_92 ; V_93 ++ ) {
if ( F_42 ( V_91 + V_93 ) == TRUE ) {
if ( V_91 [ V_93 ] . V_96 == V_97 ) {
F_20 ( L_35 , L_38 , V_98 ) ;
F_43 ( V_91 [ V_93 ] . V_99 . V_100 , V_91 [ V_93 ] . V_99 . V_101 , V_91 [ V_93 ] . V_99 . V_102 , V_91 [ V_93 ] . V_103 . V_104 . V_105 ) ;
}
#ifdef F_17
else if ( V_91 [ V_93 ] . V_96 == V_106 ) {
F_20 ( L_35 , L_39 , V_98 ) ;
} else if ( V_91 [ V_93 ] . V_96 == V_107 ) {
F_20 ( L_35 , L_40 , V_98 ) ;
} else {
F_20 ( L_35 , L_41 , V_98 ) ;
}
#endif
memcpy ( & V_38 -> V_91 [ V_94 ] , & V_91 [ V_93 ] , sizeof( V_91 [ V_93 ] ) ) ;
V_94 ++ ;
}
}
V_38 -> V_92 = V_94 ;
F_30 ( L_35 ) ;
return V_94 ;
}
static void
F_44 (
T_10 V_38 )
{
F_19 ( L_42 ) ;
if ( V_38 == NULL ) {
F_20 ( L_42 , L_23 , V_61 ) ;
F_30 ( L_42 ) ;
return;
}
memset ( V_38 -> V_91 , 0 , sizeof( T_6 ) * V_95 ) ;
V_38 -> V_92 = 0 ;
F_20 ( L_42 , L_43 , V_61 ) ;
F_30 ( L_42 ) ;
}
static void
F_45 (
T_3 V_3 )
{
if ( V_3 -> V_20 != NULL ) {
F_45 ( V_3 -> V_20 ) ;
F_12 ( V_3 -> V_20 ) ;
V_3 -> V_20 = NULL ;
}
}
static void
F_46 (
T_10 V_38 )
{
T_3 V_108 ;
int V_93 ;
for ( V_108 = V_38 -> V_3 , V_93 = 0 ; V_93 < V_109 ; V_93 ++ , V_108 ++ ) {
F_45 ( V_108 ) ;
}
}
INT F_47 (
const T_10 V_38 ,
T_6 V_91 [] ,
const T_15 V_92 )
{
V_86 V_93 ;
V_86 V_110 ;
F_19 ( L_44 ) ;
if ( V_38 == NULL ) {
F_20 ( L_44 , L_23 , V_61 ) ;
F_30 ( L_44 ) ;
return 0 ;
} else if ( V_91 == NULL ) {
F_20 ( L_44 , L_45 , V_61 ) ;
F_30 ( L_44 ) ;
return ( INT ) V_38 -> V_92 ;
} else {
for ( V_93 = 0 , V_110 = 0 ; V_93 < V_38 -> V_92 && V_93 < V_92 && V_93 < V_95 ; V_93 ++ ) {
memcpy ( & V_91 [ V_110 ] , & V_38 -> V_91 [ V_93 ] , sizeof( V_91 [ V_110 ] ) ) ;
V_110 ++ ;
F_20 ( L_44 , L_46 , V_61 ) ;
}
F_30 ( L_44 ) ;
return V_110 ;
}
}
INT F_48 (
T_10 V_38 ,
CHAR * V_111 ,
T_15 V_112 )
{
if ( ! V_38 || ! V_111 || V_112 < 1 || V_112 > V_113 )
return V_89 ;
memcpy ( V_38 -> V_111 , V_111 , V_112 ) ;
V_38 -> V_112 = V_112 ;
return V_73 ;
}
INT F_41 (
T_10 V_38 )
{
F_19 ( L_47 ) ;
if ( V_38 == NULL ) {
F_20 ( L_47 , L_23 , V_61 ) ;
F_30 ( L_47 ) ;
return V_89 ;
}
F_44 ( V_38 ) ;
V_38 -> V_114 = 0 ;
V_38 -> V_115 = - 1 ;
V_38 -> V_40 = - 1 ;
V_38 -> V_112 = 0 ;
memset ( V_38 -> V_3 , 0 , V_109 * sizeof( T_7 ) ) ;
F_20 ( L_47 , L_48 , V_61 ) ;
F_30 ( L_47 ) ;
return V_73 ;
}
INT F_49 (
T_10 V_38 )
{
F_19 ( L_49 ) ;
if ( V_38 == NULL ) {
F_20 ( L_49 , L_23 , V_61 ) ;
F_30 ( L_49 ) ;
return V_89 ;
}
F_44 ( V_38 ) ;
F_46 ( V_38 ) ;
V_38 -> V_114 = 0 ;
V_38 -> V_115 = - 1 ;
V_38 -> V_40 = - 1 ;
F_20 ( L_49 , L_50 , V_61 ) ;
F_30 ( L_49 ) ;
return V_73 ;
}
static INT
F_39 (
T_12 * V_74 ,
T_4 V_42 ,
T_4 * V_75 ,
T_13 V_34 ,
T_7 * V_3 ,
INT V_47 )
{
INT V_116 = 1 ;
T_12 * V_117 ;
T_4 V_118 = * V_75 ;
if ( * V_75 > V_118 ) {
F_20 ( L_51 , L_52 , V_52 ) ;
return V_89 ;
}
V_117 = ( T_12 * ) F_6 ( V_118 ) ;
for(; V_3 != NULL ; V_3 = V_3 -> V_20 ) {
if ( V_3 -> V_35 == FALSE ) {
F_20 ( L_51 , L_53 , V_52 ) ;
continue;
}
memcpy ( V_117 , V_74 , * V_75 ) ;
if ( V_3 -> V_24 . V_25 == 1 ) {
F_20 ( L_51 , L_54 , V_52 ) ;
F_5 ( L_55 , V_3 -> V_24 . V_36 , 64 ) ;
F_5 ( L_56 , F_50 ( V_3 -> V_24 . V_36 ) , 16 ) ;
V_116 = F_51 ( V_117 + V_47 , * V_75 - V_47 , V_117 + V_119 , F_50 ( V_3 -> V_24 . V_36 ) ) ;
if ( V_116 ) {
F_20 ( L_51 , L_57 , V_52 ) ;
continue;
}
F_20 ( L_51 , L_58 , V_52 ) ;
* V_75 -= 12 ;
break;
} else {
F_20 ( L_51 , L_59 , V_52 ) ;
V_116 = F_52 ( V_117 , V_42 , ( INT ) * V_75 , F_50 ( V_3 -> V_24 . V_36 ) ) ;
if ( V_116 )
continue;
F_20 ( L_51 , L_60 , V_52 ) ;
* V_75 -= 8 ;
break;
}
}
if( V_3 == NULL ) {
F_12 ( V_117 ) ;
return V_116 ;
}
if ( * V_75 > V_118 || * V_75 < 8 ) {
F_20 ( L_51 , L_52 , V_52 ) ;
F_12 ( V_117 ) ;
return V_89 ;
}
memcpy ( V_74 , V_117 , * V_75 ) ;
F_12 ( V_117 ) ;
V_74 [ 1 ] &= 0xBF ;
V_47 = V_42 ;
* V_75 -= 8 ;
memmove ( V_74 + V_47 , V_74 + V_47 + 8 , * V_75 - V_47 ) ;
if ( V_34 != NULL ) {
if ( V_3 -> V_34 != NULL )
memcpy ( V_34 , V_3 -> V_34 , sizeof( T_6 ) ) ;
else
memset ( V_34 , 0 , sizeof( T_6 ) ) ;
memcpy ( V_34 -> V_103 . V_104 . V_120 , V_3 -> V_24 . V_36 , V_121 ) ;
if ( V_3 -> V_24 . V_25 == V_13 )
V_34 -> V_96 = V_122 ;
else if ( V_3 -> V_24 . V_25 == V_15 )
V_34 -> V_96 = V_123 ;
}
return V_73 ;
}
static INT
F_37 (
T_10 V_38 ,
T_12 * V_74 ,
T_4 V_42 ,
T_4 * V_75 ,
T_13 V_34 ,
T_7 * V_3 ,
INT V_47 )
{
T_12 V_124 [ V_125 + V_126 ] ;
T_15 V_127 ;
INT V_116 = 1 ;
INT V_30 ;
T_6 * V_128 ;
T_16 V_129 = FALSE ;
T_12 * V_117 ;
T_4 V_118 = * V_75 ;
V_117 = ( T_12 * ) F_6 ( V_118 ) ;
if ( V_3 -> V_34 != NULL )
V_129 = TRUE ;
for ( V_30 = 0 ; V_30 < ( INT ) V_38 -> V_92 ; V_30 ++ ) {
if ( ! V_129 ) {
V_128 = & V_38 -> V_91 [ V_30 ] ;
} else {
if ( V_3 -> V_34 != NULL && V_3 -> V_34 -> V_96 == V_107 ) {
F_20 ( L_61 , L_62 , V_52 ) ;
V_128 = V_3 -> V_34 ;
} else {
F_20 ( L_61 , L_63 , V_52 ) ;
V_128 = & V_38 -> V_91 [ V_30 ] ;
}
}
if ( V_128 -> V_96 == V_107 ) {
F_20 ( L_61 , L_64 , V_52 ) ;
memset ( V_124 , 0 , sizeof( V_124 ) ) ;
memcpy ( V_117 , V_74 , * V_75 ) ;
memcpy ( V_124 , V_117 + V_42 , V_126 ) ;
V_127 = V_128 -> V_103 . V_130 . V_131 ;
memcpy ( V_124 + V_126 , V_128 -> V_103 . V_130 . V_132 , V_127 ) ;
V_116 = F_53 ( V_124 ,
V_127 + V_126 ,
V_117 + ( V_42 + V_126 + V_133 ) ,
* V_75 - ( V_42 + V_126 + V_133 + V_134 ) ) ;
if ( V_116 == V_73 )
memcpy ( V_74 , V_117 , * V_75 ) ;
}
if ( ! V_116 && V_128 -> V_96 == V_107 ) {
V_3 -> V_34 = V_128 ;
if ( V_34 != NULL ) {
memcpy ( V_34 , V_3 -> V_34 , sizeof( T_6 ) ) ;
V_34 -> V_96 = V_107 ;
}
break;
} else {
if ( V_129 == TRUE ) {
V_129 = FALSE ;
V_30 -- ;
}
}
}
F_12 ( V_117 ) ;
if ( V_116 )
return V_89 ;
F_20 ( L_61 , L_65 , V_52 ) ;
* V_75 -= 4 ;
if ( * V_75 < 4 ) {
F_20 ( L_61 , L_66 , V_52 ) ;
return V_89 ;
}
V_74 [ 1 ] &= 0xBF ;
V_47 = V_42 ;
* V_75 -= 4 ;
memmove ( V_74 + V_47 , V_74 + V_47 + V_126 + V_133 , * V_75 - V_47 ) ;
return V_73 ;
}
static INT
F_21 (
T_10 V_38 ,
const T_12 * V_41 ,
T_7 * V_3 ,
INT V_47 ,
const T_4 V_43 )
{
T_6 * V_128 , * V_135 , V_136 ;
T_7 * V_11 ;
INT V_30 ;
INT V_116 = 1 ;
T_12 V_129 = FALSE ;
T_12 V_137 [ V_138 ] ;
T_17 V_4 ;
if ( V_3 -> V_34 != NULL )
V_129 = TRUE ;
if ( F_22 ( V_41 [ V_47 + 1 ] ) != 1 ) {
F_20 ( L_67 , L_68 , V_61 ) ;
return V_17 ;
}
F_20 ( L_67 , L_69 , V_61 ) ;
if ( F_54 ( V_41 [ V_47 + 1 ] ) == 0 &&
F_23 ( V_41 [ V_47 + 1 ] ) == 1 &&
F_24 ( V_41 [ V_47 ] ) == 0 )
{
F_20 ( L_67 , L_70 , V_52 ) ;
if( V_3 -> V_139 >= 2 ) {
V_11 = F_28 ( T_7 , 1 ) ;
memcpy ( V_11 , V_3 , sizeof( T_7 ) ) ;
V_3 -> V_35 = FALSE ;
V_3 -> V_20 = V_11 ;
}
memcpy ( V_3 -> V_24 . V_71 , V_41 + V_47 + 12 , 32 ) ;
V_3 -> V_24 . V_25 = F_2 ( V_41 [ V_47 + 1 ] ) ;
V_3 -> V_139 = 1 ;
return V_37 ;
}
if ( F_54 ( V_41 [ V_47 + 1 ] ) == 0 &&
F_23 ( V_41 [ V_47 + 1 ] ) == 0 &&
F_24 ( V_41 [ V_47 ] ) == 1 )
{
if ( F_3 ( V_41 + V_47 + 92 ) ) {
F_20 ( L_67 , L_71 , V_52 ) ;
for ( V_30 = 0 ; V_30 < ( INT ) V_38 -> V_92 || V_129 ; V_30 ++ ) {
if ( ! V_129 ) {
F_20 ( L_67 , L_72 , V_52 ) ;
V_128 = & V_38 -> V_91 [ V_30 ] ;
} else {
if ( V_3 -> V_34 != NULL &&
( V_3 -> V_34 -> V_96 == V_97 ||
V_3 -> V_34 -> V_96 == V_140 ||
V_3 -> V_34 -> V_96 == V_106 ) ) {
F_20 ( L_67 , L_73 , V_52 ) ;
V_128 = V_3 -> V_34 ;
} else {
F_20 ( L_67 , L_74 , V_52 ) ;
V_128 = & V_38 -> V_91 [ V_30 ] ;
}
}
if ( V_128 -> V_96 == V_97 ||
V_128 -> V_96 == V_140 ||
V_128 -> V_96 == V_106 )
{
if ( V_128 -> V_96 == V_97 && V_128 -> V_99 . V_102 == 0 && V_38 -> V_112 > 0 && V_38 -> V_112 <= V_141 ) {
memcpy ( & V_136 , V_128 , sizeof( V_136 ) ) ;
memcpy ( & V_136 . V_99 . V_101 , V_38 -> V_111 , V_38 -> V_112 ) ;
V_136 . V_99 . V_102 = V_38 -> V_112 ;
F_43 ( V_136 . V_99 . V_100 , V_136 . V_99 . V_101 ,
V_136 . V_99 . V_102 , V_136 . V_103 . V_104 . V_105 ) ;
V_135 = & V_136 ;
} else {
V_135 = V_128 ;
}
F_55 ( V_3 ,
V_135 -> V_103 . V_104 . V_105 ,
V_41 + V_47 + 12 ,
512 ,
V_3 -> V_24 . V_36 ) ;
V_4 = F_3 ( V_41 + V_47 - 3 ) + 4 ;
memcpy ( V_137 , & V_41 [ V_47 - 5 ] , ( V_4 < V_138 ? V_4 : V_138 ) ) ;
V_116 = F_56 ( V_137 ,
V_4 ,
V_3 -> V_24 . V_36 ,
F_2 ( V_41 [ V_47 + 1 ] ) ) ;
}
if ( ! V_116 &&
( V_128 -> V_96 == V_97 ||
V_128 -> V_96 == V_140 ||
V_128 -> V_96 == V_106 ) )
{
V_3 -> V_34 = V_128 ;
break;
} else {
if ( V_129 == TRUE ) {
V_129 = FALSE ;
V_30 -- ;
}
}
}
if ( V_116 ) {
F_20 ( L_67 , L_75 , V_52 ) ;
return V_17 ;
}
V_3 -> V_139 = 2 ;
V_3 -> V_35 = TRUE ;
return V_37 ;
} else {
F_20 ( L_67 , L_76 , V_52 ) ;
V_3 -> V_139 = 4 ;
return V_37 ;
}
}
if ( F_23 ( V_41 [ V_47 + 1 ] ) == 1 &&
F_24 ( V_41 [ V_47 ] ) == 1 )
{
const T_1 * V_1 ;
F_20 ( L_67 , L_77 , V_52 ) ;
V_1 = ( const T_1 * ) ( & ( V_41 [ V_47 - 1 ] ) ) ;
if ( V_1 -> type == V_53 ) {
T_3 V_142 ;
T_11 V_39 ;
memcpy ( V_39 . V_57 , V_58 , V_59 ) ;
memcpy ( V_39 . V_70 , V_3 -> V_143 . V_70 , V_59 ) ;
V_142 = F_13 ( V_38 , & V_39 ) ;
if ( V_142 == NULL ) {
return V_55 ;
}
return ( F_1 ( V_1 , V_3 -> V_24 . V_36 + 16 , V_142 , V_43 - V_47 + 1 ) ) ;
}
}
return V_17 ;
}
static INT
F_56 (
T_12 * V_137 ,
T_17 V_4 ,
T_12 V_144 [ V_145 ] ,
T_17 V_25 )
{
T_12 V_146 [ V_147 ] ;
T_12 V_148 [ V_149 ] = { 0 } ;
int V_150 ;
memcpy ( V_146 , V_137 + V_151 + 4 , V_147 ) ;
memset ( V_137 + V_151 + 4 , 0 , V_147 ) ;
if ( V_25 == V_13 ) {
V_150 = V_152 ;
} else if ( V_25 == V_15 ) {
V_150 = V_153 ;
} else {
return V_89 ;
}
if ( F_57 ( V_150 , V_148 , V_137 , V_4 , V_144 , V_145 ) ) {
return V_89 ;
}
return memcmp ( V_146 , V_148 , V_147 ) ;
}
static INT
F_42 (
T_13 V_34 )
{
T_15 V_154 ;
T_12 V_155 = TRUE ;
F_19 ( L_78 ) ;
if ( V_34 == NULL ) {
F_20 ( L_78 , L_79 , V_61 ) ;
F_19 ( L_78 ) ;
return FALSE ;
}
switch ( V_34 -> V_96 ) {
case V_107 :
V_154 = V_34 -> V_103 . V_130 . V_131 ;
if ( V_154 < V_156 || V_154 > V_125 ) {
F_20 ( L_78 , L_80 , V_61 ) ;
V_155 = FALSE ;
}
break;
case V_157 :
V_34 -> V_103 . V_130 . V_131 = V_158 ;
V_34 -> V_96 = V_107 ;
break;
case V_159 :
V_34 -> V_103 . V_130 . V_131 = V_160 ;
V_34 -> V_96 = V_107 ;
break;
case V_97 :
V_154 = strlen ( V_34 -> V_99 . V_100 ) ;
if ( V_154 < V_161 || V_154 > V_162 ) {
F_20 ( L_78 , L_81 , V_61 ) ;
V_155 = FALSE ;
}
V_154 = V_34 -> V_99 . V_102 ;
if ( V_154 > V_141 ) {
F_20 ( L_78 , L_82 , V_61 ) ;
V_155 = FALSE ;
}
break;
case V_140 :
break;
case V_106 :
break;
default:
V_155 = FALSE ;
}
F_30 ( L_78 ) ;
return V_155 ;
}
static INT
F_14 (
T_10 V_38 ,
T_11 * V_39 )
{
INT V_40 ;
if ( V_38 -> V_40 != - 1 ) {
for ( V_40 = V_38 -> V_40 ; V_40 >= 0 ; V_40 -- ) {
if ( V_38 -> V_3 [ V_40 ] . V_163 ) {
if ( memcmp ( V_39 , & ( V_38 -> V_3 [ V_40 ] . V_143 ) , sizeof( T_11 ) ) == 0 ) {
V_38 -> V_115 = V_40 ;
return V_40 ;
}
}
}
}
return - 1 ;
}
static INT
F_15 (
T_10 V_38 ,
T_11 * V_39 )
{
INT V_164 ;
if ( V_38 -> V_114 >= V_109 ) {
return - 1 ;
}
if ( V_38 -> V_3 [ V_38 -> V_114 ] . V_163 ) {
for ( V_164 = V_38 -> V_114 ; V_164 < V_109 ; V_164 ++ )
if ( ! V_38 -> V_3 [ V_164 ] . V_163 )
break;
if ( V_164 >= V_109 ) {
return - 1 ;
}
V_38 -> V_114 = V_164 ;
}
V_38 -> V_115 = V_38 -> V_114 ;
memset ( V_38 -> V_3 + V_38 -> V_115 , 0 , sizeof( T_7 ) ) ;
V_38 -> V_3 [ V_38 -> V_115 ] . V_163 = 1 ;
memcpy ( & ( V_38 -> V_3 [ V_38 -> V_115 ] . V_143 ) , V_39 , sizeof( T_11 ) ) ;
V_38 -> V_114 ++ ;
if ( V_38 -> V_115 > V_38 -> V_40 )
V_38 -> V_40 = V_38 -> V_115 ;
return V_38 -> V_115 ;
}
static INT
F_34 (
const V_60 * V_165 ,
T_11 * V_39 )
{
#ifdef F_17
#define F_18 255
CHAR V_51 [ F_18 ] ;
#endif
if ( ( F_32 ( V_165 -> V_166 [ 0 ] ) == V_80 ) &&
( F_58 ( V_165 -> V_166 [ 1 ] ) == 0 ) &&
( memcmp ( V_165 -> V_167 , V_165 -> V_168 , V_59 ) != 0 ) &&
( memcmp ( V_165 -> V_169 , V_165 -> V_168 , V_59 ) != 0 ) ) {
if ( memcmp ( V_165 -> V_169 , V_165 -> V_167 , V_59 ) < 0 ) {
memcpy ( V_39 -> V_57 , V_165 -> V_169 , V_59 ) ;
memcpy ( V_39 -> V_70 , V_165 -> V_167 , V_59 ) ;
} else {
memcpy ( V_39 -> V_57 , V_165 -> V_167 , V_59 ) ;
memcpy ( V_39 -> V_70 , V_165 -> V_169 , V_59 ) ;
}
} else {
const T_12 * V_44 ;
if ( ( V_44 = F_59 ( V_165 ) ) != NULL ) {
memcpy ( V_39 -> V_70 , V_44 , V_59 ) ;
} else {
return V_89 ;
}
if ( ( V_44 = F_26 ( V_165 ) ) != NULL ) {
memcpy ( V_39 -> V_57 , V_44 , V_59 ) ;
} else {
return V_89 ;
}
}
#ifdef F_17
F_27 ( V_51 , F_18 , L_83 ,
V_39 -> V_70 [ 0 ] , V_39 -> V_70 [ 1 ] , V_39 -> V_70 [ 2 ] , V_39 -> V_70 [ 3 ] , V_39 -> V_70 [ 4 ] , V_39 -> V_70 [ 5 ] ) ;
F_20 ( L_84 , V_51 , V_52 ) ;
F_27 ( V_51 , F_18 , L_85 ,
V_39 -> V_57 [ 0 ] , V_39 -> V_57 [ 1 ] , V_39 -> V_57 [ 2 ] , V_39 -> V_57 [ 3 ] , V_39 -> V_57 [ 4 ] , V_39 -> V_57 [ 5 ] ) ;
F_20 ( L_84 , V_51 , V_52 ) ;
#endif
return V_73 ;
}
static const T_12 *
F_26 (
const V_60 * V_165 )
{
switch( F_58 ( V_165 -> V_166 [ 1 ] ) ) {
case 0 :
if ( memcmp ( V_165 -> V_167 , V_165 -> V_168 , V_59 ) == 0 )
return V_165 -> V_169 ;
else
return V_165 -> V_167 ;
case 1 :
return V_165 -> V_167 ;
case 2 :
return V_165 -> V_169 ;
case 3 :
if ( memcmp ( V_165 -> V_169 , V_165 -> V_167 , V_59 ) < 0 )
return V_165 -> V_169 ;
else
return V_165 -> V_167 ;
default:
return NULL ;
}
}
static const T_12 *
F_59 (
const V_60 * V_165 )
{
switch( F_58 ( V_165 -> V_166 [ 1 ] ) ) {
case 0 :
return V_165 -> V_168 ;
case 1 :
return V_165 -> V_169 ;
case 2 :
return V_165 -> V_167 ;
case 3 :
if ( memcmp ( V_165 -> V_169 , V_165 -> V_167 , V_59 ) > 0 )
return V_165 -> V_169 ;
else
return V_165 -> V_167 ;
default:
return NULL ;
}
}
static void
F_55 (
T_7 * V_3 ,
const T_12 V_170 [ 32 ] ,
const T_12 V_171 [ 32 ] ,
const INT V_172 ,
T_12 * V_36 )
{
T_16 V_93 ;
T_12 V_173 [ 100 ] ;
INT V_47 = sizeof( L_86 ) ;
T_12 V_174 [ 80 ] ;
memset ( V_173 , 0 , 100 ) ;
memcpy ( V_173 , L_86 , V_47 ) ;
if ( memcmp ( V_3 -> V_143 . V_57 , V_3 -> V_143 . V_70 , V_59 ) < 0 )
{
memcpy ( V_173 + V_47 , V_3 -> V_143 . V_57 , V_59 ) ;
memcpy ( V_173 + V_47 + V_59 , V_3 -> V_143 . V_70 , V_59 ) ;
}
else
{
memcpy ( V_173 + V_47 , V_3 -> V_143 . V_70 , V_59 ) ;
memcpy ( V_173 + V_47 + V_59 , V_3 -> V_143 . V_57 , V_59 ) ;
}
V_47 += V_59 * 2 ;
if( memcmp ( V_171 , V_3 -> V_24 . V_71 , 32 ) < 0 )
{
memcpy ( V_173 + V_47 , V_171 , 32 ) ;
memcpy ( V_173 + V_47 + 32 , V_3 -> V_24 . V_71 , 32 ) ;
}
else
{
memcpy ( V_173 + V_47 , V_3 -> V_24 . V_71 , 32 ) ;
memcpy ( V_173 + V_47 + 32 , V_171 , 32 ) ;
}
V_47 += 32 * 2 ;
for( V_93 = 0 ; V_93 < ( V_172 + 159 ) / 160 ; V_93 ++ )
{
V_173 [ V_47 ] = V_93 ;
if ( F_57 ( V_153 , & V_174 [ V_149 * V_93 ] , V_173 , 100 , V_170 , 32 ) ) {
return;
}
}
memcpy ( V_36 , V_174 , V_172 / 8 ) ;
}
static INT
F_60 (
const T_2 * V_175 ,
const T_4 V_176 ,
const CHAR * V_177 ,
const T_15 V_178 ,
const INT V_179 ,
const INT V_180 ,
T_12 * V_174 )
{
T_12 V_181 [ V_182 + 4 ] = { 0 } ;
INT V_93 , V_110 ;
if ( V_178 > V_182 ) {
return V_89 ;
}
memcpy ( V_181 , V_177 , V_178 ) ;
V_181 [ V_178 ] = ( T_12 ) ( ( V_180 >> 24 ) & 0xff ) ;
V_181 [ V_178 + 1 ] = ( T_12 ) ( ( V_180 >> 16 ) & 0xff ) ;
V_181 [ V_178 + 2 ] = ( T_12 ) ( ( V_180 >> 8 ) & 0xff ) ;
V_181 [ V_178 + 3 ] = ( T_12 ) ( V_180 & 0xff ) ;
if ( F_57 ( V_153 , V_181 , V_181 , ( T_9 ) V_178 + 4 , V_175 , V_176 ) ) {
return V_89 ;
}
memcpy ( V_174 , V_181 , 20 ) ;
for ( V_93 = 1 ; V_93 < V_179 ; V_93 ++ ) {
if ( F_57 ( V_153 , V_181 , V_181 , V_149 , V_175 , V_176 ) ) {
return V_89 ;
}
for ( V_110 = 0 ; V_110 < 20 ; V_110 ++ ) {
V_174 [ V_110 ] ^= V_181 [ V_110 ] ;
}
}
return V_73 ;
}
static INT
F_43 (
const CHAR * V_183 ,
const CHAR * V_177 ,
const T_15 V_178 ,
T_12 * V_174 )
{
T_12 V_184 [ 40 ] = { 0 } ;
T_18 * V_185 = F_61 () ;
if ( ! F_62 ( V_183 , V_185 ) ) {
F_63 ( V_185 , TRUE ) ;
return 0 ;
}
F_60 ( V_185 -> V_41 , V_185 -> V_154 , V_177 , V_178 , 4096 , 1 , V_184 ) ;
F_60 ( V_185 -> V_41 , V_185 -> V_154 , V_177 , V_178 , 4096 , 2 , & V_184 [ 20 ] ) ;
memcpy ( V_174 , V_184 , V_186 ) ;
F_63 ( V_185 , TRUE ) ;
return 0 ;
}
T_19 *
F_64 ( T_20 * V_187 , T_2 V_188 )
{
T_20 * V_34 , * V_189 ;
T_20 * V_177 ;
T_21 * V_190 = NULL ;
T_18 * V_191 = NULL , * V_192 ;
T_14 V_193 ;
T_20 * * V_194 ;
T_4 V_195 = 0 ;
T_19 * V_196 ;
if( V_187 == NULL )
return NULL ;
switch( V_188 )
{
case V_107 :
case V_157 :
case V_159 :
V_192 = F_61 () ;
V_193 = F_65 ( V_187 , V_192 , FALSE ) ;
if ( V_193 && V_192 -> V_154 > 0 ) {
V_196 = ( T_19 * ) F_6 ( sizeof( T_19 ) ) ;
V_196 -> type = V_107 ;
V_189 = F_66 ( NULL , V_192 -> V_41 , V_192 -> V_154 ) ;
V_196 -> V_34 = F_67 ( V_189 ) ;
F_68 ( V_196 -> V_34 ) ;
V_196 -> V_197 = V_192 -> V_154 * 8 ;
V_196 -> V_177 = NULL ;
F_69 ( NULL , V_189 ) ;
F_63 ( V_192 , TRUE ) ;
return V_196 ;
}
F_63 ( V_192 , TRUE ) ;
return NULL ;
case V_97 :
V_194 = F_70 ( V_187 , L_87 , 0 ) ;
while( V_194 [ V_195 ] != NULL )
V_195 ++ ;
if( V_195 < 1 )
{
F_71 ( V_194 ) ;
return NULL ;
}
V_34 = F_72 ( V_194 [ 0 ] ) ;
V_177 = NULL ;
if( V_195 >= 2 )
{
V_177 = F_72 ( V_194 [ 1 ] ) ;
}
V_190 = F_67 ( V_34 ) ;
V_191 = NULL ;
if( ( ( V_190 -> V_154 ) > V_198 ) || ( ( V_190 -> V_154 ) < V_199 ) )
{
F_73 ( V_190 , TRUE ) ;
F_12 ( V_34 ) ;
F_12 ( V_177 ) ;
F_71 ( V_194 ) ;
return NULL ;
}
if( V_177 != NULL )
{
V_191 = F_61 () ;
if ( ! F_62 ( V_177 , V_191 ) ) {
F_73 ( V_190 , TRUE ) ;
F_63 ( V_191 , TRUE ) ;
F_12 ( V_34 ) ;
F_12 ( V_177 ) ;
F_71 ( V_194 ) ;
return NULL ;
}
if( V_191 -> V_154 > V_200 )
{
F_73 ( V_190 , TRUE ) ;
F_63 ( V_191 , TRUE ) ;
F_12 ( V_34 ) ;
F_12 ( V_177 ) ;
F_71 ( V_194 ) ;
return NULL ;
}
}
V_196 = ( T_19 * ) F_6 ( sizeof( T_19 ) ) ;
V_196 -> type = V_97 ;
V_196 -> V_34 = F_67 ( V_34 ) ;
V_196 -> V_197 = 256 ;
V_196 -> V_177 = F_74 ( V_191 ) ;
F_73 ( V_190 , TRUE ) ;
if ( V_191 != NULL )
F_63 ( V_191 , TRUE ) ;
F_12 ( V_34 ) ;
if( V_177 != NULL )
F_12 ( V_177 ) ;
F_71 ( V_194 ) ;
return V_196 ;
case V_140 :
V_192 = F_61 () ;
V_193 = F_65 ( V_187 , V_192 , FALSE ) ;
if( ! V_193 || ( ( V_192 -> V_154 ) != V_201 ) )
{
F_63 ( V_192 , TRUE ) ;
return NULL ;
}
V_196 = ( T_19 * ) F_6 ( sizeof( T_19 ) ) ;
V_196 -> type = V_140 ;
V_196 -> V_34 = F_67 ( V_187 ) ;
V_196 -> V_197 = ( T_4 ) V_196 -> V_34 -> V_154 * 4 ;
V_196 -> V_177 = NULL ;
F_63 ( V_192 , TRUE ) ;
return V_196 ;
}
return NULL ;
}
void
F_75 ( T_19 * V_196 )
{
if ( V_196 -> V_34 )
F_73 ( V_196 -> V_34 , TRUE ) ;
if ( V_196 -> V_177 )
F_63 ( V_196 -> V_177 , TRUE ) ;
F_12 ( V_196 ) ;
}
T_20 *
F_76 ( T_19 * V_196 )
{
T_20 * V_202 = NULL ;
if( V_196 == NULL || V_196 -> V_34 == NULL )
return NULL ;
switch( V_196 -> type ) {
case V_107 :
V_202 = F_72 ( V_196 -> V_34 -> V_203 ) ;
break;
case V_97 :
if( V_196 -> V_177 == NULL )
V_202 = F_72 ( V_196 -> V_34 -> V_203 ) ;
else {
T_20 * V_177 = F_77 ( NULL , V_196 -> V_177 , L_87 ) ;
V_202 = F_78 ( L_88 ,
V_196 -> V_34 -> V_203 , V_177 ) ;
F_69 ( NULL , V_177 ) ;
}
break;
case V_106 :
V_202 = F_72 ( V_196 -> V_34 -> V_203 ) ;
break;
default:
return NULL ;
}
return V_202 ;
}
