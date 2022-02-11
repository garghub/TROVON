static void
F_1 ( const T_1 * V_1 , T_2 * V_2 , T_3 V_3 )
{
T_2 V_4 [ 32 ] ;
T_2 V_5 ;
T_2 * V_6 ;
T_4 V_7 = 0 ;
static T_5 V_8 ;
V_5 = F_2 ( V_1 -> V_9 [ 1 ] ) ;
if ( V_5 == V_10 ) {
V_7 = F_3 ( V_1 -> V_11 ) ;
} else if ( V_5 == V_12 ) {
V_7 = F_3 ( V_1 -> V_13 ) ;
}
if ( V_7 > sizeof( V_14 ) || V_7 == 0 ) {
return;
}
V_6 = ( T_2 * ) F_4 ( V_1 -> V_15 , V_7 ) ;
F_5 ( L_1 , V_6 , V_7 ) ;
F_5 ( L_2 , V_1 -> V_16 , 16 ) ;
F_5 ( L_3 , V_2 , 16 ) ;
memcpy ( V_4 , V_1 -> V_16 , 16 ) ;
memcpy ( V_4 + 16 , V_2 , 16 ) ;
F_5 ( L_4 , V_4 , 32 ) ;
if ( V_5 == V_10 ) {
T_2 V_17 [ 256 ] ;
T_6 V_18 ;
F_6 ( & V_18 , V_4 , sizeof( V_4 ) ) ;
F_7 ( & V_18 , V_17 , 256 ) ;
F_7 ( & V_18 , V_6 , V_7 ) ;
} else if ( V_5 == V_12 ) {
T_2 V_19 ;
T_4 V_20 ;
T_2 * V_21 ;
V_21 = ( T_2 * ) F_8 ( V_7 ) ;
F_9 ( V_2 , 16 , V_6 , V_7 , V_21 ) ;
V_19 = FALSE ;
V_20 = 0 ;
while( V_20 < V_7 && ! V_19 ) {
T_2 V_22 ;
V_22 = V_21 [ V_20 ] ;
if ( V_22 != 0xdd ) {
V_20 += V_21 [ V_20 + 1 ] + 2 ;
} else{
V_19 = TRUE ;
}
}
if ( V_19 ) {
memcpy ( V_6 , V_21 + V_20 + 8 , V_7 - V_20 - 8 ) ;
}
F_10 ( V_21 ) ;
}
F_5 ( L_5 , V_6 , V_7 ) ;
V_3 -> V_23 = & V_8 ;
V_3 -> V_24 = TRUE ;
V_3 -> V_25 . V_26 = V_5 ;
memset ( V_3 -> V_25 . V_27 , 0 , sizeof( V_3 -> V_25 . V_27 ) ) ;
memcpy ( V_3 -> V_25 . V_27 + 32 , V_6 , V_7 ) ;
F_10 ( V_6 ) ;
}
static T_3
F_11 (
T_7 V_28 ,
T_8 * V_29 )
{
int V_30 ;
if ( ( V_30 = F_12 ( V_28 , V_29 ) ) == - 1 ) {
if ( ( V_30 = F_13 ( V_28 , V_29 ) ) == - 1 ) {
return NULL ;
}
}
return & V_28 -> V_3 [ V_30 ] ;
}
static INT F_14 (
T_7 V_28 ,
const T_2 * V_31 ,
const T_9 V_32 ,
const T_9 V_33
)
{
const T_10 * V_34 ;
T_8 V_29 ;
T_9 V_35 ;
T_3 V_36 ;
T_3 V_3 ;
int V_37 = 0 ;
const T_2 V_38 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
const T_1 * V_1 ;
#ifdef F_15
CHAR V_39 [ 255 ] ;
#endif
F_16 ( L_6 ) ;
if ( V_32 + V_40 < V_33 ) {
F_17 ( L_6 , L_7 , V_41 ) ;
return V_42 ;
}
V_37 = V_32 ;
if ( memcmp ( V_31 + V_37 , V_38 , 8 ) == 0 ) {
F_17 ( L_6 , L_8 , V_41 ) ;
V_37 += 8 ;
if ( V_31 [ V_37 + 1 ] != 3 ) {
F_17 ( L_6 , L_9 , V_41 ) ;
return V_42 ;
}
V_35 = F_3 ( V_31 + V_37 + 2 ) ;
if ( ( V_33 - V_37 - 4 ) < V_35 ) {
F_17 ( L_6 , L_10 , V_41 ) ;
return V_42 ;
}
V_37 += 4 ;
V_1 = ( const T_1 * ) ( V_31 + V_37 ) ;
if (
V_1 -> type != V_43 &&
V_1 -> type != V_44 )
{
F_17 ( L_6 , L_11 , V_41 ) ;
return V_42 ;
}
V_37 += 1 ;
if ( F_18 ( V_31 [ V_37 + 1 ] ) != 0 ||
F_19 ( V_31 [ V_37 + 1 ] ) != 1 ||
F_20 ( V_31 [ V_37 ] ) != 1 ||
F_21 ( V_31 [ V_37 ] ) != 1 ) {
F_17 ( L_6 , L_12 , V_41 ) ;
return V_42 ;
}
if ( ( V_34 = F_22 ( ( const V_45 * ) ( V_31 ) ) ) != NULL ) {
memcpy ( V_29 . V_46 , V_34 , V_47 ) ;
#ifdef F_15
sprintf ( V_39 , L_13 , V_29 . V_46 [ 0 ] , V_29 . V_46 [ 1 ] , V_29 . V_46 [ 2 ] , V_29 . V_46 [ 3 ] , V_29 . V_46 [ 4 ] , V_29 . V_46 [ 5 ] ) ;
#endif
F_17 ( L_6 , V_39 , V_41 ) ;
} else {
F_17 ( L_6 , L_14 , V_48 ) ;
return V_49 ;
}
memcpy ( V_29 . V_50 , V_51 , V_47 ) ;
V_3 = F_11 ( V_28 , & V_29 ) ;
if ( V_3 == NULL ) {
return V_52 ;
}
if ( ( V_34 = F_23 ( ( const V_45 * ) ( V_31 ) ) ) != NULL ) {
memcpy ( V_29 . V_50 , V_34 , V_47 ) ;
#ifdef F_15
sprintf ( V_39 , L_15 , V_29 . V_50 [ 0 ] , V_29 . V_50 [ 1 ] , V_29 . V_50 [ 2 ] , V_29 . V_50 [ 3 ] , V_29 . V_50 [ 4 ] , V_29 . V_50 [ 5 ] ) ;
#endif
F_17 ( L_6 , V_39 , V_41 ) ;
} else {
F_17 ( L_6 , L_16 , V_48 ) ;
return V_49 ;
}
V_36 = F_11 ( V_28 , & V_29 ) ;
if ( V_36 == NULL ) {
return V_52 ;
}
F_1 ( V_1 , V_36 -> V_25 . V_27 + 16 , V_3 ) ;
} else{
F_17 ( L_6 , L_17 , V_41 ) ;
}
F_24 ( L_6 ) ;
return 0 ;
}
INT F_25 (
T_7 V_28 ,
const T_2 * V_31 ,
const T_9 V_32 ,
const T_9 V_33 ,
T_10 * V_53 ,
T_9 * V_54 ,
T_11 V_23 ,
T_12 V_55 ,
T_12 V_56 )
{
const T_10 * V_34 ;
T_8 V_29 ;
T_3 V_3 ;
int V_37 = 0 ;
T_9 V_35 ;
const T_2 V_38 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
#ifdef F_15
CHAR V_39 [ 255 ] ;
#endif
F_16 ( L_18 ) ;
if ( V_28 == NULL ) {
F_17 ( L_18 , L_19 , V_48 ) ;
F_24 ( L_18 ) ;
return V_52 ;
}
if ( V_31 == NULL || V_33 == 0 ) {
F_17 ( L_18 , L_20 , V_48 ) ;
F_24 ( L_18 ) ;
return V_52 ;
}
if ( F_26 ( V_31 [ 0 ] ) != V_57 ) {
F_17 ( L_18 , L_21 , V_48 ) ;
return V_58 ;
}
if ( V_33 < ( V_59 ) ( V_32 + V_60 ) ) {
F_17 ( L_18 , L_22 , V_48 ) ;
return V_61 ;
}
if ( ( V_34 = F_22 ( ( const V_45 * ) ( V_31 ) ) ) != NULL ) {
memcpy ( V_29 . V_46 , V_34 , V_47 ) ;
#ifdef F_15
sprintf ( V_39 , L_13 , V_29 . V_46 [ 0 ] , V_29 . V_46 [ 1 ] , V_29 . V_46 [ 2 ] , V_29 . V_46 [ 3 ] , V_29 . V_46 [ 4 ] , V_29 . V_46 [ 5 ] ) ;
#endif
F_17 ( L_18 , V_39 , V_41 ) ;
} else {
F_17 ( L_18 , L_14 , V_48 ) ;
return V_49 ;
}
if ( ( V_34 = F_23 ( ( const V_45 * ) ( V_31 ) ) ) != NULL ) {
memcpy ( V_29 . V_50 , V_34 , V_47 ) ;
#ifdef F_15
sprintf ( V_39 , L_15 , V_29 . V_50 [ 0 ] , V_29 . V_50 [ 1 ] , V_29 . V_50 [ 2 ] , V_29 . V_50 [ 3 ] , V_29 . V_50 [ 4 ] , V_29 . V_50 [ 5 ] ) ;
#endif
F_17 ( L_18 , V_39 , V_41 ) ;
} else {
F_17 ( L_18 , L_16 , V_48 ) ;
return V_49 ;
}
V_3 = F_11 ( V_28 , & V_29 ) ;
if ( V_3 == NULL ) {
return V_52 ;
}
V_37 = V_32 ;
if ( F_27 ( V_31 [ 1 ] ) == 0 )
{
if ( V_55 ) {
F_17 ( L_18 , L_23 , V_41 ) ;
if ( memcmp ( V_31 + V_37 , V_38 , 8 ) == 0 ) {
F_17 ( L_18 , L_8 , V_41 ) ;
V_37 += 8 ;
#if 0
if (data[offset]!=2) {
AIRPDCAP_DEBUG_PRINT_LINE("EAPOL protocol version not recognized", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
#endif
if ( V_31 [ V_37 + 1 ] != 3 ) {
F_17 ( L_18 , L_9 , V_48 ) ;
return V_42 ;
}
V_35 = F_3 ( V_31 + V_37 + 2 ) ;
if ( ( V_33 - V_37 - 4 ) < V_35 ) {
F_17 ( L_18 , L_10 , V_48 ) ;
return V_42 ;
}
V_37 += 4 ;
if (
V_31 [ V_37 ] != 0x2 &&
V_31 [ V_37 ] != 0xFE )
{
F_17 ( L_18 , L_11 , V_48 ) ;
return V_42 ;
}
V_37 += 1 ;
return F_28 ( V_28 , V_31 , V_3 , V_23 , V_37 ) ;
} else {
F_17 ( L_18 , L_24 , V_48 ) ;
return V_62 ;
}
}
} else {
if ( V_56 ) {
if ( V_53 == NULL )
return V_52 ;
* V_54 = V_33 ;
memcpy ( V_53 , V_31 , * V_54 ) ;
F_17 ( L_18 , L_25 , V_41 ) ;
if ( F_29 ( V_31 [ V_37 + 3 ] ) == 0 ) {
F_17 ( L_18 , L_26 , V_41 ) ;
return F_30 ( V_28 , V_53 , V_32 , V_54 , V_23 , V_3 , V_37 ) ;
} else {
INT V_63 ;
F_17 ( L_18 , L_27 , V_41 ) ;
if ( F_31 ( V_31 [ V_37 + 3 ] ) >= 1 ) {
F_17 ( L_18 , L_28 , V_41 ) ;
memcpy ( V_29 . V_50 , V_51 , V_47 ) ;
#ifdef F_15
sprintf ( V_39 , L_15 , V_29 . V_50 [ 0 ] , V_29 . V_50 [ 1 ] , V_29 . V_50 [ 2 ] , V_29 . V_50 [ 3 ] , V_29 . V_50 [ 4 ] , V_29 . V_50 [ 5 ] ) ;
F_17 ( L_18 , V_39 , V_41 ) ;
#endif
V_3 = F_11 ( V_28 , & V_29 ) ;
if ( V_3 == NULL ) {
return V_52 ;
}
}
V_63 = F_32 ( V_53 , V_32 , V_54 , V_23 , V_3 , V_37 ) ;
if ( V_63 == V_64 )
F_14 ( V_28 , V_53 , V_32 , * V_54 ) ;
return V_63 ;
}
}
}
return V_52 ;
}
INT F_33 (
T_7 V_28 ,
T_5 V_65 [] ,
const T_13 V_66 )
{
INT V_67 ;
INT V_68 ;
F_16 ( L_29 ) ;
if ( V_28 == NULL || V_65 == NULL ) {
F_17 ( L_29 , L_30 , V_41 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
if ( V_66 > V_69 ) {
F_17 ( L_29 , L_31 , V_41 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
F_34 ( V_28 ) ;
for ( V_67 = 0 , V_68 = 0 ; V_67 < ( INT ) V_66 ; V_67 ++ ) {
if ( F_35 ( V_65 + V_67 ) == TRUE ) {
if ( V_65 [ V_67 ] . V_70 == V_71 ) {
F_17 ( L_29 , L_32 , V_72 ) ;
F_36 ( V_65 [ V_67 ] . V_73 . V_74 , V_65 [ V_67 ] . V_73 . V_75 , V_65 [ V_67 ] . V_73 . V_76 , V_65 [ V_67 ] . V_77 . V_78 . V_79 ) ;
}
#ifdef F_15
else if ( V_65 [ V_67 ] . V_70 == V_80 ) {
F_17 ( L_29 , L_33 , V_72 ) ;
} else if ( V_65 [ V_67 ] . V_70 == V_81 ) {
F_17 ( L_29 , L_34 , V_72 ) ;
} else {
F_17 ( L_29 , L_35 , V_72 ) ;
}
#endif
memcpy ( & V_28 -> V_65 [ V_68 ] , & V_65 [ V_67 ] , sizeof( V_65 [ V_67 ] ) ) ;
V_68 ++ ;
}
}
V_28 -> V_66 = V_68 ;
F_24 ( L_29 ) ;
return V_68 ;
}
static void
F_37 (
T_7 V_28 )
{
F_16 ( L_36 ) ;
if ( V_28 == NULL ) {
F_17 ( L_36 , L_19 , V_48 ) ;
F_24 ( L_36 ) ;
return;
}
memset ( V_28 -> V_65 , 0 , sizeof( T_5 ) * V_69 ) ;
V_28 -> V_66 = 0 ;
F_17 ( L_36 , L_37 , V_48 ) ;
F_24 ( L_36 ) ;
}
INT F_38 (
const T_7 V_28 ,
T_5 V_65 [] ,
const T_13 V_66 )
{
V_59 V_67 ;
V_59 V_82 ;
F_16 ( L_38 ) ;
if ( V_28 == NULL ) {
F_17 ( L_38 , L_19 , V_48 ) ;
F_24 ( L_38 ) ;
return 0 ;
} else if ( V_65 == NULL ) {
F_17 ( L_38 , L_39 , V_48 ) ;
F_24 ( L_38 ) ;
return ( INT ) V_28 -> V_66 ;
} else {
for ( V_67 = 0 , V_82 = 0 ; V_67 < V_28 -> V_66 && V_67 < V_66 && V_67 < V_69 ; V_67 ++ ) {
memcpy ( & V_65 [ V_82 ] , & V_28 -> V_65 [ V_67 ] , sizeof( V_65 [ V_82 ] ) ) ;
V_82 ++ ;
F_17 ( L_38 , L_40 , V_48 ) ;
}
F_24 ( L_38 ) ;
return V_82 ;
}
}
INT F_39 (
T_7 V_28 ,
CHAR * V_83 ,
T_13 V_84 )
{
if ( ! V_28 || ! V_83 || V_84 < 1 || V_84 > V_85 )
return V_52 ;
memcpy ( V_28 -> V_83 , V_83 , V_84 ) ;
V_28 -> V_84 = V_84 ;
return V_64 ;
}
INT F_34 (
T_7 V_28 )
{
F_16 ( L_41 ) ;
if ( V_28 == NULL ) {
F_17 ( L_41 , L_19 , V_48 ) ;
F_24 ( L_41 ) ;
return V_52 ;
}
F_37 ( V_28 ) ;
V_28 -> V_86 = 0 ;
V_28 -> V_87 = - 1 ;
V_28 -> V_30 = - 1 ;
V_28 -> V_84 = 0 ;
memset ( V_28 -> V_3 , 0 , V_88 * sizeof( V_89 ) ) ;
F_17 ( L_41 , L_42 , V_48 ) ;
F_24 ( L_41 ) ;
return V_64 ;
}
INT F_40 (
T_7 V_28 )
{
F_16 ( L_43 ) ;
if ( V_28 == NULL ) {
F_17 ( L_43 , L_19 , V_48 ) ;
F_24 ( L_43 ) ;
return V_52 ;
}
F_37 ( V_28 ) ;
V_28 -> V_86 = 0 ;
V_28 -> V_87 = - 1 ;
V_28 -> V_30 = - 1 ;
F_17 ( L_43 , L_44 , V_48 ) ;
F_24 ( L_43 ) ;
return V_64 ;
}
static INT
F_32 (
T_10 * V_53 ,
T_9 V_32 ,
T_9 * V_54 ,
T_11 V_23 ,
V_89 * V_3 ,
INT V_37 )
{
INT V_90 = 1 ;
T_10 * V_91 ;
T_9 V_92 = * V_54 ;
if ( V_3 -> V_23 == NULL ) {
F_17 ( L_45 , L_46 , V_41 ) ;
return V_49 ;
}
if ( V_3 -> V_24 == FALSE ) {
F_17 ( L_45 , L_47 , V_41 ) ;
return V_52 ;
}
V_91 = ( T_10 * ) F_41 ( V_92 ) ;
for(; V_3 != NULL ; V_3 = V_3 -> V_93 ) {
if ( * V_54 > V_92 ) {
F_17 ( L_45 , L_48 , V_41 ) ;
return V_52 ;
}
memcpy ( V_91 , V_53 , * V_54 ) ;
if ( V_3 -> V_25 . V_26 == 1 ) {
F_17 ( L_45 , L_49 , V_41 ) ;
F_5 ( L_50 , V_3 -> V_25 . V_27 , 64 ) ;
F_5 ( L_51 , F_42 ( V_3 -> V_25 . V_27 ) , 16 ) ;
V_90 = F_43 ( V_91 + V_37 , * V_54 - V_37 , V_91 + V_94 , F_42 ( V_3 -> V_25 . V_27 ) ) ;
if ( V_90 ) {
F_17 ( L_45 , L_52 , V_41 ) ;
continue;
}
F_17 ( L_45 , L_53 , V_41 ) ;
* V_54 -= 12 ;
break;
} else {
F_17 ( L_45 , L_54 , V_41 ) ;
V_90 = F_44 ( V_91 , V_32 , ( INT ) * V_54 , F_42 ( V_3 -> V_25 . V_27 ) ) ;
if ( V_90 )
continue;
F_17 ( L_45 , L_55 , V_41 ) ;
* V_54 -= 8 ;
break;
}
}
if( V_3 == NULL )
return V_90 ;
if ( * V_54 > V_92 || * V_54 < 8 ) {
F_17 ( L_45 , L_48 , V_41 ) ;
return V_52 ;
}
memcpy ( V_53 , V_91 , * V_54 ) ;
V_53 [ 1 ] &= 0xBF ;
V_37 = V_32 ;
* V_54 -= 8 ;
memmove ( V_53 + V_37 , V_53 + V_37 + 8 , * V_54 - V_37 ) ;
if ( V_23 != NULL ) {
memcpy ( V_23 , V_3 -> V_23 , sizeof( T_5 ) ) ;
if ( V_3 -> V_25 . V_26 == V_10 )
V_23 -> V_70 = V_95 ;
else if ( V_3 -> V_25 . V_26 == V_12 )
V_23 -> V_70 = V_96 ;
}
return V_64 ;
}
static INT
F_30 (
T_7 V_28 ,
T_10 * V_53 ,
T_9 V_32 ,
T_9 * V_54 ,
T_11 V_23 ,
V_89 * V_3 ,
INT V_37 )
{
T_10 V_97 [ V_98 + V_99 ] ;
T_13 V_100 ;
INT V_90 = 1 ;
INT V_20 ;
T_5 * V_101 ;
T_14 V_102 = FALSE ;
T_10 * V_91 ;
T_9 V_92 = * V_54 ;
V_91 = ( T_10 * ) F_41 ( V_92 ) ;
if ( V_3 -> V_23 != NULL )
V_102 = TRUE ;
for ( V_20 = 0 ; V_20 < ( INT ) V_28 -> V_66 ; V_20 ++ ) {
if ( ! V_102 ) {
V_101 = & V_28 -> V_65 [ V_20 ] ;
} else {
if ( V_3 -> V_23 != NULL && V_3 -> V_23 -> V_70 == V_81 ) {
F_17 ( L_56 , L_57 , V_41 ) ;
V_101 = V_3 -> V_23 ;
} else {
F_17 ( L_56 , L_58 , V_41 ) ;
V_101 = & V_28 -> V_65 [ V_20 ] ;
}
}
if ( V_101 -> V_70 == V_81 )
{
F_17 ( L_56 , L_59 , V_41 ) ;
memset ( V_97 , 0 , sizeof( V_97 ) ) ;
memcpy ( V_91 , V_53 , * V_54 ) ;
memcpy ( V_97 , V_91 + V_32 , V_99 ) ;
V_100 = V_101 -> V_77 . V_103 . V_104 ;
memcpy ( V_97 + V_99 , V_101 -> V_77 . V_103 . V_105 , V_100 ) ;
V_90 = F_45 ( V_97 ,
V_100 + V_99 ,
V_91 + ( V_32 + V_99 + V_106 ) ,
* V_54 - ( V_32 + V_99 + V_106 + V_107 ) ) ;
if ( V_90 == V_64 )
memcpy ( V_53 , V_91 , * V_54 ) ;
}
if ( ! V_90 && V_101 -> V_70 == V_81 ) {
V_3 -> V_23 = V_101 ;
if ( V_23 != NULL ) {
memcpy ( V_23 , & V_3 -> V_23 , sizeof( T_5 ) ) ;
V_23 -> V_70 = V_81 ;
}
break;
} else {
if ( V_102 == TRUE ) {
V_102 = FALSE ;
V_20 -- ;
}
}
}
if ( V_90 )
return V_90 ;
F_17 ( L_56 , L_60 , V_41 ) ;
* V_54 -= 4 ;
if ( * V_54 < 4 ) {
F_17 ( L_56 , L_61 , V_41 ) ;
return V_52 ;
}
V_53 [ 1 ] &= 0xBF ;
V_37 = V_32 ;
* V_54 -= 4 ;
memcpy ( V_53 + V_37 , V_53 + V_37 + V_99 + V_106 , * V_54 - V_37 ) ;
return V_64 ;
}
static INT
F_28 (
T_7 V_28 ,
const T_10 * V_31 ,
V_89 * V_3 ,
T_11 V_23 ,
INT V_37 )
{
T_5 * V_101 , V_108 ;
V_89 * V_109 ;
INT V_20 ;
INT V_90 = 1 ;
T_10 V_102 = FALSE ;
T_10 V_110 [ V_111 ] ;
T_15 V_112 ;
if ( V_3 -> V_23 != NULL )
V_102 = TRUE ;
if ( F_18 ( V_31 [ V_37 + 1 ] ) != 1 ) {
F_17 ( L_62 , L_63 , V_48 ) ;
return V_42 ;
}
if( V_3 -> V_113 == 4 ) {
V_109 = ( V_89 * ) F_46 ( sizeof( V_89 ) ) ;
memcpy ( V_109 , V_3 , sizeof( V_89 ) ) ;
V_3 -> V_93 = V_109 ;
}
F_17 ( L_62 , L_64 , V_48 ) ;
if ( F_47 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_19 ( V_31 [ V_37 + 1 ] ) == 1 &&
F_20 ( V_31 [ V_37 ] ) == 0 )
{
F_17 ( L_62 , L_65 , V_41 ) ;
memcpy ( V_3 -> V_25 . V_114 , V_31 + V_37 + 12 , 32 ) ;
V_3 -> V_25 . V_26 = F_2 ( V_31 [ V_37 + 1 ] ) ;
V_3 -> V_113 = 1 ;
return V_115 ;
}
if ( F_47 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_19 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_20 ( V_31 [ V_37 ] ) == 1 )
{
if ( F_21 ( V_31 [ V_37 ] ) == 0 ) {
if ( V_31 [ V_37 + 92 ] != 0 || V_31 [ V_37 + 93 ] != 0 ) {
F_17 ( L_62 , L_66 , V_41 ) ;
for ( V_20 = 0 ; V_20 < ( INT ) V_28 -> V_66 || V_102 ; V_20 ++ ) {
if ( ! V_102 ) {
F_17 ( L_62 , L_67 , V_41 ) ;
V_101 = & V_28 -> V_65 [ V_20 ] ;
} else {
if ( V_3 -> V_23 != NULL &&
( V_3 -> V_23 -> V_70 == V_71 ||
V_3 -> V_23 -> V_70 == V_116 ||
V_3 -> V_23 -> V_70 == V_80 ) ) {
F_17 ( L_62 , L_68 , V_41 ) ;
V_101 = V_3 -> V_23 ;
} else {
F_17 ( L_62 , L_69 , V_41 ) ;
V_101 = & V_28 -> V_65 [ V_20 ] ;
}
}
if ( V_101 -> V_70 == V_71 ||
V_101 -> V_70 == V_116 ||
V_101 -> V_70 == V_80 )
{
if ( V_101 -> V_70 == V_71 && V_101 -> V_73 . V_76 == 0 && V_28 -> V_84 > 0 && V_28 -> V_84 <= V_117 ) {
memcpy ( & V_108 , V_101 , sizeof( V_108 ) ) ;
memcpy ( & V_108 . V_73 . V_75 , V_28 -> V_83 , V_28 -> V_84 ) ;
V_108 . V_73 . V_76 = V_28 -> V_84 ;
F_36 ( V_108 . V_73 . V_74 , V_108 . V_73 . V_75 ,
V_108 . V_73 . V_76 , V_108 . V_77 . V_78 . V_79 ) ;
V_101 = & V_108 ;
}
F_48 ( V_3 ,
V_101 -> V_77 . V_78 . V_118 ,
V_31 + V_37 + 12 ,
512 ,
V_3 -> V_25 . V_27 ) ;
V_112 = F_3 ( V_31 + V_37 - 3 ) + 4 ;
memcpy ( V_110 , & V_31 [ V_37 - 5 ] , ( V_112 < V_111 ? V_112 : V_111 ) ) ;
V_90 = F_49 ( V_110 ,
V_112 ,
V_3 -> V_25 . V_27 ,
F_2 ( V_31 [ V_37 + 1 ] ) ) ;
}
if ( ! V_90 &&
( V_101 -> V_70 == V_71 ||
V_101 -> V_70 == V_116 ||
V_101 -> V_70 == V_80 ) )
{
V_3 -> V_23 = V_101 ;
if ( V_23 != NULL ) {
memcpy ( V_23 , & V_101 , sizeof( T_5 ) ) ;
if ( F_2 ( V_31 [ V_37 + 1 ] ) == V_10 )
V_23 -> V_70 = V_95 ;
else if ( F_2 ( V_31 [ V_37 + 1 ] ) == V_12 )
V_23 -> V_70 = V_96 ;
}
break;
} else {
if ( V_102 == TRUE ) {
V_102 = FALSE ;
V_20 -- ;
}
}
}
if ( V_90 ) {
F_17 ( L_62 , L_70 , V_41 ) ;
return V_42 ;
}
V_3 -> V_113 = 2 ;
return V_115 ;
} else {
F_17 ( L_62 , L_71 , V_41 ) ;
V_3 -> V_113 = 4 ;
V_3 -> V_24 = TRUE ;
return V_115 ;
}
} else {
F_17 ( L_62 , L_72 , V_41 ) ;
V_3 -> V_113 = 4 ;
V_3 -> V_24 = TRUE ;
return V_115 ;
}
}
if ( F_19 ( V_31 [ V_37 + 1 ] ) == 1 &&
F_20 ( V_31 [ V_37 ] ) == 1 )
{
const T_1 * V_1 ;
F_17 ( L_62 , L_73 , V_41 ) ;
V_1 = ( const T_1 * ) ( & ( V_31 [ V_37 - 1 ] ) ) ;
if ( V_1 -> type == V_43 ) {
T_3 V_119 ;
T_8 V_29 ;
memcpy ( V_29 . V_50 , V_51 , V_47 ) ;
memcpy ( V_29 . V_46 , V_3 -> V_120 . V_46 , V_47 ) ;
V_119 = F_11 ( V_28 , & V_29 ) ;
if ( V_119 == NULL ) {
return V_52 ;
}
F_1 ( V_1 , V_3 -> V_25 . V_27 + 16 , V_119 ) ;
}
return V_115 ;
}
return V_52 ;
}
static INT
F_49 (
T_10 * V_110 ,
T_15 V_112 ,
T_10 V_121 [ V_122 ] ,
T_15 V_26 )
{
T_10 V_123 [ V_124 ] ;
T_10 V_125 [ 20 ] ;
memcpy ( V_123 , V_110 + V_126 + 4 , V_124 ) ;
memset ( V_110 + V_126 + 4 , 0 , V_124 ) ;
if ( V_26 == V_10 ) {
F_50 ( V_110 , V_112 , V_121 , V_122 , V_125 ) ;
} else if ( V_26 == V_12 ) {
F_51 ( V_121 , V_122 , V_110 , V_112 , V_125 ) ;
} else
return V_52 ;
return memcmp ( V_123 , V_125 , V_124 ) ;
}
static INT
F_35 (
T_11 V_23 )
{
T_13 V_127 ;
T_10 V_128 = TRUE ;
F_16 ( L_74 ) ;
if ( V_23 == NULL ) {
F_17 ( L_74 , L_75 , V_48 ) ;
F_16 ( L_74 ) ;
return FALSE ;
}
switch ( V_23 -> V_70 ) {
case V_81 :
V_127 = V_23 -> V_77 . V_103 . V_104 ;
if ( V_127 < V_129 || V_127 > V_98 ) {
F_17 ( L_74 , L_76 , V_48 ) ;
V_128 = FALSE ;
}
break;
case V_130 :
V_23 -> V_77 . V_103 . V_104 = V_131 ;
V_23 -> V_70 = V_81 ;
break;
case V_132 :
V_23 -> V_77 . V_103 . V_104 = V_133 ;
V_23 -> V_70 = V_81 ;
break;
case V_71 :
V_127 = strlen ( V_23 -> V_73 . V_74 ) ;
if ( V_127 < V_134 || V_127 > V_135 ) {
F_17 ( L_74 , L_77 , V_48 ) ;
V_128 = FALSE ;
}
V_127 = V_23 -> V_73 . V_76 ;
if ( V_127 > V_117 ) {
F_17 ( L_74 , L_78 , V_48 ) ;
V_128 = FALSE ;
}
break;
case V_116 :
break;
case V_80 :
break;
default:
V_128 = FALSE ;
}
F_24 ( L_74 ) ;
return V_128 ;
}
static INT
F_12 (
T_7 V_28 ,
T_8 * V_29 )
{
INT V_30 ;
if ( V_28 -> V_30 != - 1 ) {
for ( V_30 = V_28 -> V_30 ; V_30 >= 0 ; V_30 -- ) {
if ( V_28 -> V_3 [ V_30 ] . V_136 ) {
if ( memcmp ( V_29 , & ( V_28 -> V_3 [ V_30 ] . V_120 ) , sizeof( T_8 ) ) == 0 ) {
V_28 -> V_87 = V_30 ;
return V_30 ;
}
}
}
}
return - 1 ;
}
static INT
F_13 (
T_7 V_28 ,
T_8 * V_29 )
{
INT V_137 ;
if ( V_28 -> V_3 [ V_28 -> V_86 ] . V_136 ) {
for ( V_137 = V_28 -> V_86 ; V_137 < V_88 ; V_137 ++ )
if ( ! V_28 -> V_3 [ V_137 ] . V_136 )
break;
if ( V_137 >= V_88 ) {
return - 1 ;
}
V_28 -> V_86 = V_137 ;
}
V_28 -> V_87 = V_28 -> V_86 ;
memset ( V_28 -> V_3 + V_28 -> V_87 , 0 , sizeof( V_89 ) ) ;
V_28 -> V_3 [ V_28 -> V_87 ] . V_136 = 1 ;
memcpy ( & ( V_28 -> V_3 [ V_28 -> V_87 ] . V_120 ) , V_29 , sizeof( T_8 ) ) ;
V_28 -> V_86 ++ ;
if ( V_28 -> V_87 > V_28 -> V_30 )
V_28 -> V_30 = V_28 -> V_87 ;
return V_28 -> V_87 ;
}
static const T_10 *
F_23 (
const V_45 * V_138 )
{
switch( F_52 ( V_138 -> V_139 [ 1 ] ) ) {
case 0 :
case 1 :
case 3 :
return V_138 -> V_140 ;
case 2 :
return V_138 -> V_141 ;
default:
return NULL ;
}
}
static const T_10 *
F_22 (
const V_45 * V_138 )
{
switch( F_52 ( V_138 -> V_139 [ 1 ] ) ) {
case 0 :
return V_138 -> V_142 ;
case 1 :
case 3 :
return V_138 -> V_141 ;
case 2 :
return V_138 -> V_140 ;
default:
return NULL ;
}
}
static void
F_48 (
V_89 * V_3 ,
const T_10 V_143 [ 32 ] ,
const T_10 V_144 [ 32 ] ,
const INT V_145 ,
T_10 * V_27 )
{
T_14 V_67 ;
T_10 V_146 [ 100 ] ;
INT V_37 = sizeof( L_79 ) ;
memset ( V_146 , 0 , 100 ) ;
memcpy ( V_146 , L_79 , V_37 ) ;
if ( memcmp ( V_3 -> V_120 . V_50 , V_3 -> V_120 . V_46 , V_47 ) < 0 )
{
memcpy ( V_146 + V_37 , V_3 -> V_120 . V_50 , V_47 ) ;
memcpy ( V_146 + V_37 + V_47 , V_3 -> V_120 . V_46 , V_47 ) ;
}
else
{
memcpy ( V_146 + V_37 , V_3 -> V_120 . V_46 , V_47 ) ;
memcpy ( V_146 + V_37 + V_47 , V_3 -> V_120 . V_50 , V_47 ) ;
}
V_37 += V_47 * 2 ;
if( memcmp ( V_144 , V_3 -> V_25 . V_114 , 32 ) < 0 )
{
memcpy ( V_146 + V_37 , V_144 , 32 ) ;
memcpy ( V_146 + V_37 + 32 , V_3 -> V_25 . V_114 , 32 ) ;
}
else
{
memcpy ( V_146 + V_37 , V_3 -> V_25 . V_114 , 32 ) ;
memcpy ( V_146 + V_37 + 32 , V_144 , 32 ) ;
}
V_37 += 32 * 2 ;
for( V_67 = 0 ; V_67 < ( V_145 + 159 ) / 160 ; V_67 ++ )
{
V_146 [ V_37 ] = V_67 ;
F_51 ( V_143 , 32 , V_146 , 100 , V_27 + V_67 * 20 ) ;
}
}
static INT
F_53 (
const T_2 * V_147 ,
const T_9 V_148 ,
const CHAR * V_149 ,
const T_13 V_150 ,
const INT V_151 ,
const INT V_152 ,
T_10 * V_153 )
{
T_10 V_154 [ 64 ] , V_155 [ 64 ] ;
INT V_67 , V_82 ;
if ( V_150 + 4 > 36 )
return V_52 ;
memset ( V_154 , 0 , 64 ) ;
memset ( V_155 , 0 , 64 ) ;
memcpy ( V_154 , V_149 , V_150 ) ;
V_154 [ V_150 ] = ( T_10 ) ( ( V_152 >> 24 ) & 0xff ) ;
V_154 [ V_150 + 1 ] = ( T_10 ) ( ( V_152 >> 16 ) & 0xff ) ;
V_154 [ V_150 + 2 ] = ( T_10 ) ( ( V_152 >> 8 ) & 0xff ) ;
V_154 [ V_150 + 3 ] = ( T_10 ) ( V_152 & 0xff ) ;
F_51 ( V_147 , V_148 , V_154 , ( V_156 ) V_150 + 4 , V_155 ) ;
memcpy ( V_153 , V_155 , V_157 ) ;
for ( V_67 = 1 ; V_67 < V_151 ; V_67 ++ ) {
F_51 ( V_147 , V_148 , V_155 , V_157 , V_154 ) ;
memcpy ( V_155 , V_154 , V_157 ) ;
for ( V_82 = 0 ; V_82 < V_157 ; V_82 ++ ) {
V_153 [ V_82 ] ^= V_154 [ V_82 ] ;
}
}
return V_64 ;
}
static INT
F_36 (
const CHAR * V_158 ,
const CHAR * V_149 ,
const T_13 V_150 ,
T_10 * V_153 )
{
T_10 V_159 [ V_160 ] ;
T_16 * V_161 = F_54 () ;
memset ( V_159 , 0 , V_160 ) ;
if ( ! F_55 ( V_158 , V_161 ) ) {
F_56 ( V_161 , TRUE ) ;
return 0 ;
}
F_53 ( V_161 -> V_31 , V_161 -> V_127 , V_149 , V_150 , 4096 , 1 , V_159 ) ;
F_53 ( V_161 -> V_31 , V_161 -> V_127 , V_149 , V_150 , 4096 , 2 , & V_159 [ V_157 ] ) ;
memcpy ( V_153 , V_159 , V_160 ) ;
F_56 ( V_161 , TRUE ) ;
return 0 ;
}
T_17 *
F_57 ( T_18 * V_162 , T_2 V_163 )
{
T_18 * V_23 ;
T_18 * V_149 ;
T_19 * V_164 = NULL ;
T_16 * V_165 = NULL , * V_166 ;
T_12 V_167 ;
T_18 * * V_168 ;
T_9 V_169 = 0 ;
T_17 * V_170 ;
if( V_162 == NULL )
return NULL ;
switch( V_163 )
{
case V_81 :
case V_130 :
case V_132 :
V_166 = F_54 () ;
V_167 = F_58 ( V_162 , V_166 , FALSE ) ;
if ( V_167 && V_166 -> V_127 > 0 ) {
V_170 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_170 -> type = V_81 ;
V_170 -> V_23 = F_59 ( F_60 ( V_166 -> V_31 , V_166 -> V_127 ) ) ;
F_61 ( V_170 -> V_23 ) ;
V_170 -> V_171 = V_166 -> V_127 * 8 ;
V_170 -> V_149 = NULL ;
F_56 ( V_166 , TRUE ) ;
return V_170 ;
}
F_56 ( V_166 , TRUE ) ;
return NULL ;
case V_71 :
V_168 = F_62 ( V_162 , L_80 , 0 ) ;
while( V_168 [ V_169 ] != NULL )
V_169 ++ ;
if( V_169 < 1 )
{
F_63 ( V_168 ) ;
return NULL ;
}
V_23 = F_64 ( V_168 [ 0 ] ) ;
V_149 = NULL ;
if( V_169 >= 2 )
{
V_149 = F_64 ( V_168 [ 1 ] ) ;
}
V_164 = F_59 ( V_23 ) ;
V_165 = NULL ;
if( ( ( V_164 -> V_127 ) > V_172 ) || ( ( V_164 -> V_127 ) < V_173 ) )
{
F_65 ( V_164 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_149 ) ;
F_63 ( V_168 ) ;
return NULL ;
}
if( V_149 != NULL )
{
V_165 = F_54 () ;
if ( ! F_55 ( V_149 , V_165 ) ) {
F_65 ( V_164 , TRUE ) ;
F_56 ( V_165 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_149 ) ;
F_63 ( V_168 ) ;
return NULL ;
}
if( V_165 -> V_127 > V_174 )
{
F_65 ( V_164 , TRUE ) ;
F_56 ( V_165 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_149 ) ;
F_63 ( V_168 ) ;
return NULL ;
}
}
V_170 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_170 -> type = V_71 ;
V_170 -> V_23 = F_59 ( V_23 ) ;
V_170 -> V_171 = 256 ;
V_170 -> V_149 = F_66 ( V_165 ) ;
F_65 ( V_164 , TRUE ) ;
if ( V_165 != NULL )
F_56 ( V_165 , TRUE ) ;
F_10 ( V_23 ) ;
if( V_149 != NULL )
F_10 ( V_149 ) ;
F_63 ( V_168 ) ;
return V_170 ;
case V_116 :
V_166 = F_54 () ;
V_167 = F_58 ( V_162 , V_166 , FALSE ) ;
if( ! V_167 || ( ( V_166 -> V_127 ) != V_175 ) )
{
F_56 ( V_166 , TRUE ) ;
return NULL ;
}
V_170 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_170 -> type = V_80 ;
V_170 -> V_23 = F_59 ( V_162 ) ;
V_170 -> V_171 = ( T_9 ) V_170 -> V_23 -> V_127 * 4 ;
V_170 -> V_149 = NULL ;
F_56 ( V_166 , TRUE ) ;
return V_170 ;
}
return NULL ;
}
T_18 *
F_67 ( T_17 * V_170 )
{
T_18 * V_176 = NULL ;
if( V_170 == NULL || V_170 -> V_23 == NULL )
return NULL ;
switch( V_170 -> type ) {
case V_81 :
V_176 = F_68 ( L_81 , V_177 , V_170 -> V_23 -> V_178 ) ;
break;
case V_71 :
if( V_170 -> V_149 == NULL )
V_176 = F_68 ( L_81 , V_179 , V_170 -> V_23 -> V_178 ) ;
else
V_176 = F_68 ( L_82 ,
V_179 , V_170 -> V_23 -> V_178 ,
F_69 ( V_170 -> V_149 , L_80 ) ) ;
break;
case V_80 :
V_176 = F_68 ( L_81 , V_180 , V_170 -> V_23 -> V_178 ) ;
break;
default:
return NULL ;
}
return V_176 ;
}
