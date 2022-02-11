static void
F_1 ( const T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 V_5 ;
T_2 * V_6 ;
T_5 V_7 = 0 ;
T_5 V_8 ;
static T_6 V_9 ;
T_7 * V_10 ;
V_5 = F_2 ( V_1 -> V_11 [ 1 ] ) ;
if ( V_5 == V_12 ) {
V_7 = F_3 ( V_1 -> V_13 ) ;
} else if ( V_5 == V_14 ) {
V_7 = F_3 ( V_1 -> V_15 ) ;
if ( V_7 < 16 ) {
return;
}
}
if ( V_7 > V_16 || V_7 == 0 ) {
return;
}
V_6 = ( T_2 * ) F_4 ( V_1 -> V_17 , V_7 ) ;
F_5 ( L_1 , V_6 , V_7 ) ;
F_5 ( L_2 , V_1 -> V_18 , 16 ) ;
F_5 ( L_3 , V_2 , 16 ) ;
V_10 = ( T_7 * ) F_6 ( sizeof( T_7 ) ) ;
memcpy ( V_10 , V_3 , sizeof( T_7 ) ) ;
V_3 -> V_19 = V_10 ;
if ( V_5 == V_12 ) {
T_2 V_20 [ 32 ] ;
T_2 V_21 [ 256 ] ;
T_8 V_22 ;
V_3 -> V_23 . V_24 = ( V_7 >= V_25 ) ? V_12 : V_14 ;
memcpy ( V_20 , V_1 -> V_18 , 16 ) ;
memcpy ( V_20 + 16 , V_2 , 16 ) ;
F_5 ( L_4 , V_20 , 32 ) ;
F_7 ( & V_22 , V_20 , sizeof( V_20 ) ) ;
F_8 ( & V_22 , V_21 , 256 ) ;
F_8 ( & V_22 , V_6 , V_7 ) ;
} else if ( V_5 == V_14 ) {
T_2 V_26 ;
T_5 V_27 ;
T_2 * V_28 ;
if ( V_4 )
V_3 -> V_23 . V_24 = ( V_7 >= ( V_29 ) ) ? V_12 : V_14 ;
else
V_3 -> V_23 . V_24 = ( V_7 >= ( V_30 ) ) ? V_12 : V_14 ;
V_28 = F_9 ( V_2 , 16 , V_6 , V_7 ) ;
V_26 = FALSE ;
V_27 = 0 ;
while( V_27 < V_7 && ! V_26 ) {
T_2 V_31 ;
V_31 = V_28 [ V_27 ] ;
if ( V_31 != 0xdd ) {
if ( V_27 + 1 >= V_7 ) {
return;
}
V_27 += V_28 [ V_27 + 1 ] + 2 ;
} else{
V_26 = TRUE ;
}
}
if ( V_26 ) {
if ( V_27 + 8 >= V_7 )
return;
memcpy ( V_6 , V_28 + V_27 + 8 , V_7 - V_27 - 8 ) ;
}
F_10 ( V_28 ) ;
}
V_8 = ( V_3 -> V_23 . V_24 == V_12 ) ? V_25 : V_32 ;
F_5 ( L_5 , V_6 , V_8 ) ;
V_3 -> V_33 = & V_9 ;
V_3 -> V_34 = TRUE ;
memset ( V_3 -> V_23 . V_35 , 0 , sizeof( V_3 -> V_23 . V_35 ) ) ;
memcpy ( V_3 -> V_23 . V_35 + 32 , V_6 , V_8 ) ;
F_10 ( V_6 ) ;
}
static T_3
F_11 (
T_9 V_36 ,
T_10 * V_37 )
{
int V_38 ;
if ( ( V_38 = F_12 ( V_36 , V_37 ) ) == - 1 ) {
if ( ( V_38 = F_13 ( V_36 , V_37 ) ) == - 1 ) {
return NULL ;
}
}
return & V_36 -> V_3 [ V_38 ] ;
}
static INT F_14 (
T_9 V_36 ,
const T_2 * V_39 ,
const T_11 V_40 ,
const T_11 V_41 ,
T_10 V_37 ,
T_12 V_33
)
{
const T_13 * V_42 ;
T_11 V_43 ;
T_3 V_44 ;
T_3 V_3 ;
int V_45 = 0 ;
const T_2 V_46 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
const T_2 V_47 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x19 , 0x58 ,
0x00 , 0x03
} ;
const T_1 * V_1 ;
#ifdef F_15
#define F_16 255
CHAR V_48 [ F_16 ] ;
#endif
F_17 ( L_6 ) ;
V_45 = V_40 ;
if ( memcmp ( V_39 + V_45 , V_46 , 8 ) == 0 || memcmp ( V_39 + V_45 , V_47 , 8 ) == 0 ) {
F_18 ( L_6 , L_7 , V_49 ) ;
V_45 += 8 ;
if ( V_39 [ V_45 + 1 ] != 3 ) {
F_18 ( L_6 , L_8 , V_49 ) ;
return V_50 ;
}
V_43 = F_3 ( V_39 + V_45 + 2 ) ;
if ( ( V_41 - V_45 - 4 ) > V_43 ) {
F_18 ( L_6 , L_9 , V_49 ) ;
return V_50 ;
}
V_45 += 4 ;
V_1 = ( const T_1 * ) ( V_39 + V_45 ) ;
if (
V_1 -> type != V_51 &&
V_1 -> type != V_52 )
{
F_18 ( L_6 , L_10 , V_49 ) ;
return V_50 ;
}
V_45 += 1 ;
V_3 = F_11 ( V_36 , & V_37 ) ;
if ( V_3 == NULL ) {
return V_53 ;
}
if ( F_19 ( V_36 , V_39 , V_3 , V_33 , V_45 ) == V_54 )
return V_54 ;
if ( V_40 + V_55 > V_41 ) {
F_18 ( L_6 , L_11 , V_49 ) ;
return V_50 ;
}
if ( F_20 ( V_39 [ V_45 + 1 ] ) != 0 ||
F_21 ( V_39 [ V_45 + 1 ] ) != 1 ||
F_22 ( V_39 [ V_45 ] ) != 1 ||
F_23 ( V_39 [ V_45 ] ) != 1 ) {
F_18 ( L_6 , L_12 , V_49 ) ;
return V_50 ;
}
memcpy ( V_37 . V_56 , V_57 , V_58 ) ;
V_3 = F_11 ( V_36 , & V_37 ) ;
if ( V_3 == NULL ) {
return V_53 ;
}
if ( ( V_42 = F_24 ( ( const V_59 * ) ( V_39 ) ) ) != NULL ) {
memcpy ( V_37 . V_56 , V_42 , V_58 ) ;
#ifdef F_15
F_25 ( V_48 , F_16 , L_13 , V_37 . V_56 [ 0 ] , V_37 . V_56 [ 1 ] , V_37 . V_56 [ 2 ] , V_37 . V_56 [ 3 ] , V_37 . V_56 [ 4 ] , V_37 . V_56 [ 5 ] ) ;
#endif
F_18 ( L_6 , V_48 , V_49 ) ;
} else {
F_18 ( L_6 , L_14 , V_60 ) ;
return V_61 ;
}
V_44 = F_11 ( V_36 , & V_37 ) ;
if ( V_44 == NULL ) {
return V_53 ;
}
F_1 ( V_1 , V_44 -> V_23 . V_35 + 16 , V_3 , TRUE ) ;
} else{
F_18 ( L_6 , L_15 , V_49 ) ;
}
F_26 ( L_6 ) ;
return 0 ;
}
INT F_27 (
T_9 V_36 ,
const T_2 * V_39 ,
const T_11 V_40 ,
const T_11 V_41 ,
T_13 * V_62 ,
T_11 * V_63 ,
T_12 V_33 ,
T_4 V_64 ,
T_4 V_65 )
{
const T_13 * V_42 ;
T_10 V_37 ;
#ifdef F_15
#define F_16 255
CHAR V_48 [ F_16 ] ;
#endif
F_17 ( L_16 ) ;
if ( V_36 == NULL ) {
F_18 ( L_16 , L_17 , V_60 ) ;
F_26 ( L_16 ) ;
return V_53 ;
}
if ( V_39 == NULL || V_41 == 0 ) {
F_18 ( L_16 , L_18 , V_60 ) ;
F_26 ( L_16 ) ;
return V_53 ;
}
if ( F_28 ( V_39 [ 0 ] ) != V_66 ) {
F_18 ( L_16 , L_19 , V_60 ) ;
return V_67 ;
}
if ( V_41 < ( V_68 ) ( V_40 + V_69 ) ) {
F_18 ( L_16 , L_20 , V_60 ) ;
return V_70 ;
}
if ( ( V_42 = F_29 ( ( const V_59 * ) ( V_39 ) ) ) != NULL ) {
memcpy ( V_37 . V_71 , V_42 , V_58 ) ;
#ifdef F_15
F_25 ( V_48 , F_16 , L_21 , V_37 . V_71 [ 0 ] , V_37 . V_71 [ 1 ] , V_37 . V_71 [ 2 ] , V_37 . V_71 [ 3 ] , V_37 . V_71 [ 4 ] , V_37 . V_71 [ 5 ] ) ;
#endif
F_18 ( L_16 , V_48 , V_49 ) ;
} else {
F_18 ( L_16 , L_22 , V_60 ) ;
return V_61 ;
}
if ( ( V_42 = F_24 ( ( const V_59 * ) ( V_39 ) ) ) != NULL ) {
memcpy ( V_37 . V_56 , V_42 , V_58 ) ;
#ifdef F_15
F_25 ( V_48 , F_16 , L_13 , V_37 . V_56 [ 0 ] , V_37 . V_56 [ 1 ] , V_37 . V_56 [ 2 ] , V_37 . V_56 [ 3 ] , V_37 . V_56 [ 4 ] , V_37 . V_56 [ 5 ] ) ;
#endif
F_18 ( L_16 , V_48 , V_49 ) ;
} else {
F_18 ( L_16 , L_14 , V_60 ) ;
return V_61 ;
}
if ( F_30 ( V_39 [ 1 ] ) == 0 )
{
if ( V_64 ) {
F_18 ( L_16 , L_23 , V_49 ) ;
return ( F_14 ( V_36 , V_39 , V_40 , V_41 , V_37 , V_33 ) ) ;
}
} else {
if ( V_65 ) {
T_3 V_3 ;
int V_45 = 0 ;
V_3 = F_11 ( V_36 , & V_37 ) ;
if ( V_3 == NULL ) {
return V_53 ;
}
V_45 = V_40 ;
if ( V_62 == NULL )
return V_53 ;
* V_63 = V_41 ;
memcpy ( V_62 , V_39 , * V_63 ) ;
F_18 ( L_16 , L_24 , V_49 ) ;
if ( F_31 ( V_39 [ V_45 + 3 ] ) == 0 ) {
F_18 ( L_16 , L_25 , V_49 ) ;
return F_32 ( V_36 , V_62 , V_40 , V_63 , V_33 , V_3 , V_45 ) ;
} else {
F_18 ( L_16 , L_26 , V_49 ) ;
if ( F_33 ( V_39 [ V_45 + 3 ] ) >= 1 ) {
F_18 ( L_16 , L_27 , V_49 ) ;
memcpy ( V_37 . V_56 , V_57 , V_58 ) ;
#ifdef F_15
F_25 ( V_48 , F_16 , L_13 , V_37 . V_56 [ 0 ] , V_37 . V_56 [ 1 ] , V_37 . V_56 [ 2 ] , V_37 . V_56 [ 3 ] , V_37 . V_56 [ 4 ] , V_37 . V_56 [ 5 ] ) ;
F_18 ( L_16 , V_48 , V_49 ) ;
#endif
V_3 = F_11 ( V_36 , & V_37 ) ;
if ( V_3 == NULL ) {
return V_53 ;
}
}
if ( F_34 ( V_62 , V_40 , V_63 , V_33 , V_3 , V_45 ) == V_72 )
{
F_14 ( V_36 , V_62 , V_40 , * V_63 , V_37 , NULL ) ;
return V_72 ;
}
}
}
}
return V_53 ;
}
INT F_35 (
T_9 V_36 ,
T_6 V_73 [] ,
const T_14 V_74 )
{
INT V_75 ;
INT V_76 ;
F_17 ( L_28 ) ;
if ( V_36 == NULL || V_73 == NULL ) {
F_18 ( L_28 , L_29 , V_49 ) ;
F_26 ( L_28 ) ;
return 0 ;
}
if ( V_74 > V_77 ) {
F_18 ( L_28 , L_30 , V_49 ) ;
F_26 ( L_28 ) ;
return 0 ;
}
F_36 ( V_36 ) ;
for ( V_75 = 0 , V_76 = 0 ; V_75 < ( INT ) V_74 ; V_75 ++ ) {
if ( F_37 ( V_73 + V_75 ) == TRUE ) {
if ( V_73 [ V_75 ] . V_78 == V_79 ) {
F_18 ( L_28 , L_31 , V_80 ) ;
F_38 ( V_73 [ V_75 ] . V_81 . V_82 , V_73 [ V_75 ] . V_81 . V_83 , V_73 [ V_75 ] . V_81 . V_84 , V_73 [ V_75 ] . V_85 . V_86 . V_87 ) ;
}
#ifdef F_15
else if ( V_73 [ V_75 ] . V_78 == V_88 ) {
F_18 ( L_28 , L_32 , V_80 ) ;
} else if ( V_73 [ V_75 ] . V_78 == V_89 ) {
F_18 ( L_28 , L_33 , V_80 ) ;
} else {
F_18 ( L_28 , L_34 , V_80 ) ;
}
#endif
memcpy ( & V_36 -> V_73 [ V_76 ] , & V_73 [ V_75 ] , sizeof( V_73 [ V_75 ] ) ) ;
V_76 ++ ;
}
}
V_36 -> V_74 = V_76 ;
F_26 ( L_28 ) ;
return V_76 ;
}
static void
F_39 (
T_9 V_36 )
{
F_17 ( L_35 ) ;
if ( V_36 == NULL ) {
F_18 ( L_35 , L_17 , V_60 ) ;
F_26 ( L_35 ) ;
return;
}
memset ( V_36 -> V_73 , 0 , sizeof( T_6 ) * V_77 ) ;
V_36 -> V_74 = 0 ;
F_18 ( L_35 , L_36 , V_60 ) ;
F_26 ( L_35 ) ;
}
static void
F_40 (
T_3 V_3 )
{
if ( V_3 -> V_19 != NULL ) {
F_40 ( V_3 -> V_19 ) ;
F_10 ( V_3 -> V_19 ) ;
V_3 -> V_19 = NULL ;
}
}
static void
F_41 (
T_9 V_36 )
{
T_3 V_90 ;
int V_75 ;
for ( V_90 = V_36 -> V_3 , V_75 = 0 ; V_75 < V_91 ; V_75 ++ , V_90 ++ ) {
F_40 ( V_90 ) ;
}
}
INT F_42 (
const T_9 V_36 ,
T_6 V_73 [] ,
const T_14 V_74 )
{
V_68 V_75 ;
V_68 V_92 ;
F_17 ( L_37 ) ;
if ( V_36 == NULL ) {
F_18 ( L_37 , L_17 , V_60 ) ;
F_26 ( L_37 ) ;
return 0 ;
} else if ( V_73 == NULL ) {
F_18 ( L_37 , L_38 , V_60 ) ;
F_26 ( L_37 ) ;
return ( INT ) V_36 -> V_74 ;
} else {
for ( V_75 = 0 , V_92 = 0 ; V_75 < V_36 -> V_74 && V_75 < V_74 && V_75 < V_77 ; V_75 ++ ) {
memcpy ( & V_73 [ V_92 ] , & V_36 -> V_73 [ V_75 ] , sizeof( V_73 [ V_92 ] ) ) ;
V_92 ++ ;
F_18 ( L_37 , L_39 , V_60 ) ;
}
F_26 ( L_37 ) ;
return V_92 ;
}
}
INT F_43 (
T_9 V_36 ,
CHAR * V_93 ,
T_14 V_94 )
{
if ( ! V_36 || ! V_93 || V_94 < 1 || V_94 > V_95 )
return V_53 ;
memcpy ( V_36 -> V_93 , V_93 , V_94 ) ;
V_36 -> V_94 = V_94 ;
return V_72 ;
}
INT F_36 (
T_9 V_36 )
{
F_17 ( L_40 ) ;
if ( V_36 == NULL ) {
F_18 ( L_40 , L_17 , V_60 ) ;
F_26 ( L_40 ) ;
return V_53 ;
}
F_39 ( V_36 ) ;
V_36 -> V_96 = 0 ;
V_36 -> V_97 = - 1 ;
V_36 -> V_38 = - 1 ;
V_36 -> V_94 = 0 ;
memset ( V_36 -> V_3 , 0 , V_91 * sizeof( T_7 ) ) ;
F_18 ( L_40 , L_41 , V_60 ) ;
F_26 ( L_40 ) ;
return V_72 ;
}
INT F_44 (
T_9 V_36 )
{
F_17 ( L_42 ) ;
if ( V_36 == NULL ) {
F_18 ( L_42 , L_17 , V_60 ) ;
F_26 ( L_42 ) ;
return V_53 ;
}
F_39 ( V_36 ) ;
F_41 ( V_36 ) ;
V_36 -> V_96 = 0 ;
V_36 -> V_97 = - 1 ;
V_36 -> V_38 = - 1 ;
F_18 ( L_42 , L_43 , V_60 ) ;
F_26 ( L_42 ) ;
return V_72 ;
}
static INT
F_34 (
T_13 * V_62 ,
T_11 V_40 ,
T_11 * V_63 ,
T_12 V_33 ,
T_7 * V_3 ,
INT V_45 )
{
INT V_98 = 1 ;
T_13 * V_99 ;
T_11 V_100 = * V_63 ;
if ( V_3 -> V_33 == NULL ) {
F_18 ( L_44 , L_45 , V_49 ) ;
return V_61 ;
}
if ( V_3 -> V_34 == FALSE ) {
F_18 ( L_44 , L_46 , V_49 ) ;
return V_53 ;
}
V_99 = ( T_13 * ) F_6 ( V_100 ) ;
for(; V_3 != NULL ; V_3 = V_3 -> V_19 ) {
if ( * V_63 > V_100 ) {
F_18 ( L_44 , L_47 , V_49 ) ;
F_10 ( V_99 ) ;
return V_53 ;
}
memcpy ( V_99 , V_62 , * V_63 ) ;
if ( V_3 -> V_23 . V_24 == 1 ) {
F_18 ( L_44 , L_48 , V_49 ) ;
F_5 ( L_49 , V_3 -> V_23 . V_35 , 64 ) ;
F_5 ( L_50 , F_45 ( V_3 -> V_23 . V_35 ) , 16 ) ;
V_98 = F_46 ( V_99 + V_45 , * V_63 - V_45 , V_99 + V_101 , F_45 ( V_3 -> V_23 . V_35 ) ) ;
if ( V_98 ) {
F_18 ( L_44 , L_51 , V_49 ) ;
continue;
}
F_18 ( L_44 , L_52 , V_49 ) ;
* V_63 -= 12 ;
break;
} else {
F_18 ( L_44 , L_53 , V_49 ) ;
V_98 = F_47 ( V_99 , V_40 , ( INT ) * V_63 , F_45 ( V_3 -> V_23 . V_35 ) ) ;
if ( V_98 )
continue;
F_18 ( L_44 , L_54 , V_49 ) ;
* V_63 -= 8 ;
break;
}
}
if( V_3 == NULL ) {
F_10 ( V_99 ) ;
return V_98 ;
}
if ( * V_63 > V_100 || * V_63 < 8 ) {
F_18 ( L_44 , L_47 , V_49 ) ;
F_10 ( V_99 ) ;
return V_53 ;
}
memcpy ( V_62 , V_99 , * V_63 ) ;
F_10 ( V_99 ) ;
V_62 [ 1 ] &= 0xBF ;
V_45 = V_40 ;
* V_63 -= 8 ;
memmove ( V_62 + V_45 , V_62 + V_45 + 8 , * V_63 - V_45 ) ;
if ( V_33 != NULL ) {
memcpy ( V_33 , V_3 -> V_33 , sizeof( T_6 ) ) ;
memcpy ( V_33 -> V_85 . V_86 . V_102 , V_3 -> V_23 . V_35 , V_103 ) ;
if ( V_3 -> V_23 . V_24 == V_12 )
V_33 -> V_78 = V_104 ;
else if ( V_3 -> V_23 . V_24 == V_14 )
V_33 -> V_78 = V_105 ;
}
return V_72 ;
}
static INT
F_32 (
T_9 V_36 ,
T_13 * V_62 ,
T_11 V_40 ,
T_11 * V_63 ,
T_12 V_33 ,
T_7 * V_3 ,
INT V_45 )
{
T_13 V_106 [ V_107 + V_108 ] ;
T_14 V_109 ;
INT V_98 = 1 ;
INT V_27 ;
T_6 * V_110 ;
T_15 V_111 = FALSE ;
T_13 * V_99 ;
T_11 V_100 = * V_63 ;
V_99 = ( T_13 * ) F_6 ( V_100 ) ;
if ( V_3 -> V_33 != NULL )
V_111 = TRUE ;
for ( V_27 = 0 ; V_27 < ( INT ) V_36 -> V_74 ; V_27 ++ ) {
if ( ! V_111 ) {
V_110 = & V_36 -> V_73 [ V_27 ] ;
} else {
if ( V_3 -> V_33 != NULL && V_3 -> V_33 -> V_78 == V_89 ) {
F_18 ( L_55 , L_56 , V_49 ) ;
V_110 = V_3 -> V_33 ;
} else {
F_18 ( L_55 , L_57 , V_49 ) ;
V_110 = & V_36 -> V_73 [ V_27 ] ;
}
}
if ( V_110 -> V_78 == V_89 )
{
F_18 ( L_55 , L_58 , V_49 ) ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
memcpy ( V_99 , V_62 , * V_63 ) ;
memcpy ( V_106 , V_99 + V_40 , V_108 ) ;
V_109 = V_110 -> V_85 . V_112 . V_113 ;
memcpy ( V_106 + V_108 , V_110 -> V_85 . V_112 . V_114 , V_109 ) ;
V_98 = F_48 ( V_106 ,
V_109 + V_108 ,
V_99 + ( V_40 + V_108 + V_115 ) ,
* V_63 - ( V_40 + V_108 + V_115 + V_116 ) ) ;
if ( V_98 == V_72 )
memcpy ( V_62 , V_99 , * V_63 ) ;
}
if ( ! V_98 && V_110 -> V_78 == V_89 ) {
V_3 -> V_33 = V_110 ;
if ( V_33 != NULL ) {
memcpy ( V_33 , V_3 -> V_33 , sizeof( T_6 ) ) ;
V_33 -> V_78 = V_89 ;
}
break;
} else {
if ( V_111 == TRUE ) {
V_111 = FALSE ;
V_27 -- ;
}
}
}
F_10 ( V_99 ) ;
if ( V_98 )
return V_98 ;
F_18 ( L_55 , L_59 , V_49 ) ;
* V_63 -= 4 ;
if ( * V_63 < 4 ) {
F_18 ( L_55 , L_60 , V_49 ) ;
return V_53 ;
}
V_62 [ 1 ] &= 0xBF ;
V_45 = V_40 ;
* V_63 -= 4 ;
memmove ( V_62 + V_45 , V_62 + V_45 + V_108 + V_115 , * V_63 - V_45 ) ;
return V_72 ;
}
static INT
F_19 (
T_9 V_36 ,
const T_13 * V_39 ,
T_7 * V_3 ,
T_12 V_33 ,
INT V_45 )
{
T_6 * V_110 , * V_117 , V_118 ;
T_7 * V_10 ;
INT V_27 ;
INT V_98 = 1 ;
T_13 V_111 = FALSE ;
T_13 V_119 [ V_120 ] ;
T_16 V_121 ;
if ( V_3 -> V_33 != NULL )
V_111 = TRUE ;
if ( F_20 ( V_39 [ V_45 + 1 ] ) != 1 ) {
F_18 ( L_61 , L_62 , V_60 ) ;
return V_50 ;
}
if( V_3 -> V_122 == 4 ) {
V_10 = F_49 ( T_7 , 1 ) ;
memcpy ( V_10 , V_3 , sizeof( T_7 ) ) ;
V_3 -> V_19 = V_10 ;
}
F_18 ( L_61 , L_63 , V_60 ) ;
if ( F_50 ( V_39 [ V_45 + 1 ] ) == 0 &&
F_21 ( V_39 [ V_45 + 1 ] ) == 1 &&
F_22 ( V_39 [ V_45 ] ) == 0 )
{
F_18 ( L_61 , L_64 , V_49 ) ;
memcpy ( V_3 -> V_23 . V_123 , V_39 + V_45 + 12 , 32 ) ;
V_3 -> V_23 . V_24 = F_2 ( V_39 [ V_45 + 1 ] ) ;
V_3 -> V_122 = 1 ;
return V_54 ;
}
if ( F_50 ( V_39 [ V_45 + 1 ] ) == 0 &&
F_21 ( V_39 [ V_45 + 1 ] ) == 0 &&
F_22 ( V_39 [ V_45 ] ) == 1 )
{
if ( F_23 ( V_39 [ V_45 ] ) == 0 ) {
if ( V_39 [ V_45 + 92 ] != 0 || V_39 [ V_45 + 93 ] != 0 ) {
F_18 ( L_61 , L_65 , V_49 ) ;
for ( V_27 = 0 ; V_27 < ( INT ) V_36 -> V_74 || V_111 ; V_27 ++ ) {
if ( ! V_111 ) {
F_18 ( L_61 , L_66 , V_49 ) ;
V_110 = & V_36 -> V_73 [ V_27 ] ;
} else {
if ( V_3 -> V_33 != NULL &&
( V_3 -> V_33 -> V_78 == V_79 ||
V_3 -> V_33 -> V_78 == V_124 ||
V_3 -> V_33 -> V_78 == V_88 ) ) {
F_18 ( L_61 , L_67 , V_49 ) ;
V_110 = V_3 -> V_33 ;
} else {
F_18 ( L_61 , L_68 , V_49 ) ;
V_110 = & V_36 -> V_73 [ V_27 ] ;
}
}
if ( V_110 -> V_78 == V_79 ||
V_110 -> V_78 == V_124 ||
V_110 -> V_78 == V_88 )
{
if ( V_110 -> V_78 == V_79 && V_110 -> V_81 . V_84 == 0 && V_36 -> V_94 > 0 && V_36 -> V_94 <= V_125 ) {
memcpy ( & V_118 , V_110 , sizeof( V_118 ) ) ;
memcpy ( & V_118 . V_81 . V_83 , V_36 -> V_93 , V_36 -> V_94 ) ;
V_118 . V_81 . V_84 = V_36 -> V_94 ;
F_38 ( V_118 . V_81 . V_82 , V_118 . V_81 . V_83 ,
V_118 . V_81 . V_84 , V_118 . V_85 . V_86 . V_87 ) ;
V_117 = & V_118 ;
} else {
V_117 = V_110 ;
}
F_51 ( V_3 ,
V_117 -> V_85 . V_86 . V_87 ,
V_39 + V_45 + 12 ,
512 ,
V_3 -> V_23 . V_35 ) ;
V_121 = F_3 ( V_39 + V_45 - 3 ) + 4 ;
memcpy ( V_119 , & V_39 [ V_45 - 5 ] , ( V_121 < V_120 ? V_121 : V_120 ) ) ;
V_98 = F_52 ( V_119 ,
V_121 ,
V_3 -> V_23 . V_35 ,
F_2 ( V_39 [ V_45 + 1 ] ) ) ;
}
if ( ! V_98 &&
( V_110 -> V_78 == V_79 ||
V_110 -> V_78 == V_124 ||
V_110 -> V_78 == V_88 ) )
{
V_3 -> V_33 = V_110 ;
if ( V_33 != NULL ) {
memcpy ( V_33 , V_110 , sizeof( T_6 ) ) ;
if ( F_2 ( V_39 [ V_45 + 1 ] ) == V_12 )
V_33 -> V_78 = V_104 ;
else if ( F_2 ( V_39 [ V_45 + 1 ] ) == V_14 )
V_33 -> V_78 = V_105 ;
}
break;
} else {
if ( V_111 == TRUE ) {
V_111 = FALSE ;
V_27 -- ;
}
}
}
if ( V_98 ) {
F_18 ( L_61 , L_69 , V_49 ) ;
return V_50 ;
}
V_3 -> V_122 = 2 ;
return V_54 ;
} else {
F_18 ( L_61 , L_70 , V_49 ) ;
V_3 -> V_122 = 4 ;
V_3 -> V_34 = TRUE ;
return V_54 ;
}
} else {
F_18 ( L_61 , L_71 , V_49 ) ;
V_3 -> V_122 = 4 ;
V_3 -> V_34 = TRUE ;
return V_54 ;
}
}
if ( F_21 ( V_39 [ V_45 + 1 ] ) == 1 &&
F_22 ( V_39 [ V_45 ] ) == 1 )
{
const T_1 * V_1 ;
F_18 ( L_61 , L_72 , V_49 ) ;
V_1 = ( const T_1 * ) ( & ( V_39 [ V_45 - 1 ] ) ) ;
if ( V_1 -> type == V_51 ) {
T_3 V_126 ;
T_10 V_37 ;
memcpy ( V_37 . V_56 , V_57 , V_58 ) ;
memcpy ( V_37 . V_71 , V_3 -> V_127 . V_71 , V_58 ) ;
V_126 = F_11 ( V_36 , & V_37 ) ;
if ( V_126 == NULL ) {
return V_53 ;
}
F_1 ( V_1 , V_3 -> V_23 . V_35 + 16 , V_126 , FALSE ) ;
}
return V_54 ;
}
return V_53 ;
}
static INT
F_52 (
T_13 * V_119 ,
T_16 V_121 ,
T_13 V_128 [ V_129 ] ,
T_16 V_24 )
{
T_13 V_130 [ V_131 ] ;
T_13 V_132 [ 20 ] ;
memcpy ( V_130 , V_119 + V_133 + 4 , V_131 ) ;
memset ( V_119 + V_133 + 4 , 0 , V_131 ) ;
if ( V_24 == V_12 ) {
F_53 ( V_119 , V_121 , V_128 , V_129 , V_132 ) ;
} else if ( V_24 == V_14 ) {
F_54 ( V_128 , V_129 , V_119 , V_121 , V_132 ) ;
} else
return V_53 ;
return memcmp ( V_130 , V_132 , V_131 ) ;
}
static INT
F_37 (
T_12 V_33 )
{
T_14 V_134 ;
T_13 V_135 = TRUE ;
F_17 ( L_73 ) ;
if ( V_33 == NULL ) {
F_18 ( L_73 , L_74 , V_60 ) ;
F_17 ( L_73 ) ;
return FALSE ;
}
switch ( V_33 -> V_78 ) {
case V_89 :
V_134 = V_33 -> V_85 . V_112 . V_113 ;
if ( V_134 < V_136 || V_134 > V_107 ) {
F_18 ( L_73 , L_75 , V_60 ) ;
V_135 = FALSE ;
}
break;
case V_137 :
V_33 -> V_85 . V_112 . V_113 = V_138 ;
V_33 -> V_78 = V_89 ;
break;
case V_139 :
V_33 -> V_85 . V_112 . V_113 = V_140 ;
V_33 -> V_78 = V_89 ;
break;
case V_79 :
V_134 = strlen ( V_33 -> V_81 . V_82 ) ;
if ( V_134 < V_141 || V_134 > V_142 ) {
F_18 ( L_73 , L_76 , V_60 ) ;
V_135 = FALSE ;
}
V_134 = V_33 -> V_81 . V_84 ;
if ( V_134 > V_125 ) {
F_18 ( L_73 , L_77 , V_60 ) ;
V_135 = FALSE ;
}
break;
case V_124 :
break;
case V_88 :
break;
default:
V_135 = FALSE ;
}
F_26 ( L_73 ) ;
return V_135 ;
}
static INT
F_12 (
T_9 V_36 ,
T_10 * V_37 )
{
INT V_38 ;
if ( V_36 -> V_38 != - 1 ) {
for ( V_38 = V_36 -> V_38 ; V_38 >= 0 ; V_38 -- ) {
if ( V_36 -> V_3 [ V_38 ] . V_143 ) {
if ( memcmp ( V_37 , & ( V_36 -> V_3 [ V_38 ] . V_127 ) , sizeof( T_10 ) ) == 0 ) {
V_36 -> V_97 = V_38 ;
return V_38 ;
}
}
}
}
return - 1 ;
}
static INT
F_13 (
T_9 V_36 ,
T_10 * V_37 )
{
INT V_144 ;
if ( V_36 -> V_96 >= V_91 ) {
return - 1 ;
}
if ( V_36 -> V_3 [ V_36 -> V_96 ] . V_143 ) {
for ( V_144 = V_36 -> V_96 ; V_144 < V_91 ; V_144 ++ )
if ( ! V_36 -> V_3 [ V_144 ] . V_143 )
break;
if ( V_144 >= V_91 ) {
return - 1 ;
}
V_36 -> V_96 = V_144 ;
}
V_36 -> V_97 = V_36 -> V_96 ;
memset ( V_36 -> V_3 + V_36 -> V_97 , 0 , sizeof( T_7 ) ) ;
V_36 -> V_3 [ V_36 -> V_97 ] . V_143 = 1 ;
memcpy ( & ( V_36 -> V_3 [ V_36 -> V_97 ] . V_127 ) , V_37 , sizeof( T_10 ) ) ;
V_36 -> V_96 ++ ;
if ( V_36 -> V_97 > V_36 -> V_38 )
V_36 -> V_38 = V_36 -> V_97 ;
return V_36 -> V_97 ;
}
static const T_13 *
F_24 (
const V_59 * V_145 )
{
switch( F_55 ( V_145 -> V_146 [ 1 ] ) ) {
case 0 :
case 1 :
return V_145 -> V_147 ;
case 2 :
return V_145 -> V_148 ;
case 3 :
if ( memcmp ( V_145 -> V_148 , V_145 -> V_147 , V_58 ) < 0 )
return V_145 -> V_148 ;
else
return V_145 -> V_147 ;
default:
return NULL ;
}
}
static const T_13 *
F_29 (
const V_59 * V_145 )
{
switch( F_55 ( V_145 -> V_146 [ 1 ] ) ) {
case 0 :
return V_145 -> V_149 ;
case 1 :
return V_145 -> V_148 ;
case 2 :
return V_145 -> V_147 ;
case 3 :
if ( memcmp ( V_145 -> V_148 , V_145 -> V_147 , V_58 ) > 0 )
return V_145 -> V_148 ;
else
return V_145 -> V_147 ;
default:
return NULL ;
}
}
static void
F_51 (
T_7 * V_3 ,
const T_13 V_150 [ 32 ] ,
const T_13 V_151 [ 32 ] ,
const INT V_152 ,
T_13 * V_35 )
{
T_15 V_75 ;
T_13 V_153 [ 100 ] ;
INT V_45 = sizeof( L_78 ) ;
T_13 V_154 [ 80 ] ;
memset ( V_153 , 0 , 100 ) ;
memcpy ( V_153 , L_78 , V_45 ) ;
if ( memcmp ( V_3 -> V_127 . V_56 , V_3 -> V_127 . V_71 , V_58 ) < 0 )
{
memcpy ( V_153 + V_45 , V_3 -> V_127 . V_56 , V_58 ) ;
memcpy ( V_153 + V_45 + V_58 , V_3 -> V_127 . V_71 , V_58 ) ;
}
else
{
memcpy ( V_153 + V_45 , V_3 -> V_127 . V_71 , V_58 ) ;
memcpy ( V_153 + V_45 + V_58 , V_3 -> V_127 . V_56 , V_58 ) ;
}
V_45 += V_58 * 2 ;
if( memcmp ( V_151 , V_3 -> V_23 . V_123 , 32 ) < 0 )
{
memcpy ( V_153 + V_45 , V_151 , 32 ) ;
memcpy ( V_153 + V_45 + 32 , V_3 -> V_23 . V_123 , 32 ) ;
}
else
{
memcpy ( V_153 + V_45 , V_3 -> V_23 . V_123 , 32 ) ;
memcpy ( V_153 + V_45 + 32 , V_151 , 32 ) ;
}
V_45 += 32 * 2 ;
for( V_75 = 0 ; V_75 < ( V_152 + 159 ) / 160 ; V_75 ++ )
{
V_153 [ V_45 ] = V_75 ;
F_54 ( V_150 , 32 , V_153 , 100 , & V_154 [ 20 * V_75 ] ) ;
}
memcpy ( V_35 , V_154 , V_152 / 8 ) ;
}
static INT
F_56 (
const T_2 * V_155 ,
const T_11 V_156 ,
const CHAR * V_157 ,
const T_14 V_158 ,
const INT V_159 ,
const INT V_160 ,
T_13 * V_154 )
{
T_13 V_161 [ V_162 + 4 ] ;
T_13 V_163 [ V_164 ] ;
INT V_75 , V_92 ;
if ( V_158 > V_162 ) {
return V_53 ;
}
memset ( V_161 , 0 , sizeof V_161 ) ;
memset ( V_163 , 0 , sizeof V_163 ) ;
memcpy ( V_161 , V_157 , V_158 ) ;
V_161 [ V_158 ] = ( T_13 ) ( ( V_160 >> 24 ) & 0xff ) ;
V_161 [ V_158 + 1 ] = ( T_13 ) ( ( V_160 >> 16 ) & 0xff ) ;
V_161 [ V_158 + 2 ] = ( T_13 ) ( ( V_160 >> 8 ) & 0xff ) ;
V_161 [ V_158 + 3 ] = ( T_13 ) ( V_160 & 0xff ) ;
F_54 ( V_155 , V_156 , V_161 , ( V_165 ) V_158 + 4 , V_163 ) ;
memcpy ( V_154 , V_163 , V_164 ) ;
for ( V_75 = 1 ; V_75 < V_159 ; V_75 ++ ) {
F_54 ( V_155 , V_156 , V_163 , V_164 , V_161 ) ;
memcpy ( V_163 , V_161 , V_164 ) ;
for ( V_92 = 0 ; V_92 < V_164 ; V_92 ++ ) {
V_154 [ V_92 ] ^= V_161 [ V_92 ] ;
}
}
return V_72 ;
}
static INT
F_38 (
const CHAR * V_166 ,
const CHAR * V_157 ,
const T_14 V_158 ,
T_13 * V_154 )
{
T_13 V_167 [ 2 * V_164 ] ;
T_17 * V_168 = F_57 () ;
memset ( V_167 , 0 , 2 * V_164 ) ;
if ( ! F_58 ( V_166 , V_168 ) ) {
F_59 ( V_168 , TRUE ) ;
return 0 ;
}
F_56 ( V_168 -> V_39 , V_168 -> V_134 , V_157 , V_158 , 4096 , 1 , V_167 ) ;
F_56 ( V_168 -> V_39 , V_168 -> V_134 , V_157 , V_158 , 4096 , 2 , & V_167 [ V_164 ] ) ;
memcpy ( V_154 , V_167 , V_169 ) ;
F_59 ( V_168 , TRUE ) ;
return 0 ;
}
T_18 *
F_60 ( T_19 * V_170 , T_2 V_171 )
{
T_19 * V_33 , * V_172 ;
T_19 * V_157 ;
T_20 * V_173 = NULL ;
T_17 * V_174 = NULL , * V_175 ;
T_4 V_176 ;
T_19 * * V_177 ;
T_11 V_178 = 0 ;
T_18 * V_179 ;
if( V_170 == NULL )
return NULL ;
switch( V_171 )
{
case V_89 :
case V_137 :
case V_139 :
V_175 = F_57 () ;
V_176 = F_61 ( V_170 , V_175 , FALSE ) ;
if ( V_176 && V_175 -> V_134 > 0 ) {
V_179 = ( T_18 * ) F_6 ( sizeof( T_18 ) ) ;
V_179 -> type = V_89 ;
V_172 = F_62 ( NULL , V_175 -> V_39 , V_175 -> V_134 ) ;
V_179 -> V_33 = F_63 ( V_172 ) ;
F_64 ( V_179 -> V_33 ) ;
V_179 -> V_180 = V_175 -> V_134 * 8 ;
V_179 -> V_157 = NULL ;
F_65 ( NULL , V_172 ) ;
F_59 ( V_175 , TRUE ) ;
return V_179 ;
}
F_59 ( V_175 , TRUE ) ;
return NULL ;
case V_79 :
V_177 = F_66 ( V_170 , L_79 , 0 ) ;
while( V_177 [ V_178 ] != NULL )
V_178 ++ ;
if( V_178 < 1 )
{
F_67 ( V_177 ) ;
return NULL ;
}
V_33 = F_68 ( V_177 [ 0 ] ) ;
V_157 = NULL ;
if( V_178 >= 2 )
{
V_157 = F_68 ( V_177 [ 1 ] ) ;
}
V_173 = F_63 ( V_33 ) ;
V_174 = NULL ;
if( ( ( V_173 -> V_134 ) > V_181 ) || ( ( V_173 -> V_134 ) < V_182 ) )
{
F_69 ( V_173 , TRUE ) ;
F_10 ( V_33 ) ;
F_10 ( V_157 ) ;
F_67 ( V_177 ) ;
return NULL ;
}
if( V_157 != NULL )
{
V_174 = F_57 () ;
if ( ! F_58 ( V_157 , V_174 ) ) {
F_69 ( V_173 , TRUE ) ;
F_59 ( V_174 , TRUE ) ;
F_10 ( V_33 ) ;
F_10 ( V_157 ) ;
F_67 ( V_177 ) ;
return NULL ;
}
if( V_174 -> V_134 > V_183 )
{
F_69 ( V_173 , TRUE ) ;
F_59 ( V_174 , TRUE ) ;
F_10 ( V_33 ) ;
F_10 ( V_157 ) ;
F_67 ( V_177 ) ;
return NULL ;
}
}
V_179 = ( T_18 * ) F_6 ( sizeof( T_18 ) ) ;
V_179 -> type = V_79 ;
V_179 -> V_33 = F_63 ( V_33 ) ;
V_179 -> V_180 = 256 ;
V_179 -> V_157 = F_70 ( V_174 ) ;
F_69 ( V_173 , TRUE ) ;
if ( V_174 != NULL )
F_59 ( V_174 , TRUE ) ;
F_10 ( V_33 ) ;
if( V_157 != NULL )
F_10 ( V_157 ) ;
F_67 ( V_177 ) ;
return V_179 ;
case V_124 :
V_175 = F_57 () ;
V_176 = F_61 ( V_170 , V_175 , FALSE ) ;
if( ! V_176 || ( ( V_175 -> V_134 ) != V_184 ) )
{
F_59 ( V_175 , TRUE ) ;
return NULL ;
}
V_179 = ( T_18 * ) F_6 ( sizeof( T_18 ) ) ;
V_179 -> type = V_124 ;
V_179 -> V_33 = F_63 ( V_170 ) ;
V_179 -> V_180 = ( T_11 ) V_179 -> V_33 -> V_134 * 4 ;
V_179 -> V_157 = NULL ;
F_59 ( V_175 , TRUE ) ;
return V_179 ;
}
return NULL ;
}
void
F_71 ( T_18 * V_179 )
{
if ( V_179 -> V_33 )
F_69 ( V_179 -> V_33 , TRUE ) ;
if ( V_179 -> V_157 )
F_59 ( V_179 -> V_157 , TRUE ) ;
F_10 ( V_179 ) ;
}
T_19 *
F_72 ( T_18 * V_179 )
{
T_19 * V_185 = NULL ;
if( V_179 == NULL || V_179 -> V_33 == NULL )
return NULL ;
switch( V_179 -> type ) {
case V_89 :
V_185 = F_68 ( V_179 -> V_33 -> V_186 ) ;
break;
case V_79 :
if( V_179 -> V_157 == NULL )
V_185 = F_68 ( V_179 -> V_33 -> V_186 ) ;
else
V_185 = F_73 ( L_80 ,
V_179 -> V_33 -> V_186 , F_74 ( V_179 -> V_157 , L_79 ) ) ;
break;
case V_88 :
V_185 = F_68 ( V_179 -> V_33 -> V_186 ) ;
break;
default:
return NULL ;
}
return V_185 ;
}
