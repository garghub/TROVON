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
const T_2 V_57 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x19 , 0x58 ,
0x00 , 0x03
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
if ( F_26 ( V_31 [ 0 ] ) != V_58 ) {
F_17 ( L_18 , L_21 , V_48 ) ;
return V_59 ;
}
if ( V_33 < ( V_60 ) ( V_32 + V_61 ) ) {
F_17 ( L_18 , L_22 , V_48 ) ;
return V_62 ;
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
if ( memcmp ( V_31 + V_37 , V_38 , 8 ) == 0 || memcmp ( V_31 + V_37 , V_57 , 8 ) == 0 ) {
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
return V_63 ;
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
INT V_64 ;
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
V_64 = F_32 ( V_53 , V_32 , V_54 , V_23 , V_3 , V_37 ) ;
if ( V_64 == V_65 )
F_14 ( V_28 , V_53 , V_32 , * V_54 ) ;
return V_64 ;
}
}
}
return V_52 ;
}
INT F_33 (
T_7 V_28 ,
T_5 V_66 [] ,
const T_13 V_67 )
{
INT V_68 ;
INT V_69 ;
F_16 ( L_29 ) ;
if ( V_28 == NULL || V_66 == NULL ) {
F_17 ( L_29 , L_30 , V_41 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
if ( V_67 > V_70 ) {
F_17 ( L_29 , L_31 , V_41 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
F_34 ( V_28 ) ;
for ( V_68 = 0 , V_69 = 0 ; V_68 < ( INT ) V_67 ; V_68 ++ ) {
if ( F_35 ( V_66 + V_68 ) == TRUE ) {
if ( V_66 [ V_68 ] . V_71 == V_72 ) {
F_17 ( L_29 , L_32 , V_73 ) ;
F_36 ( V_66 [ V_68 ] . V_74 . V_75 , V_66 [ V_68 ] . V_74 . V_76 , V_66 [ V_68 ] . V_74 . V_77 , V_66 [ V_68 ] . V_78 . V_79 . V_80 ) ;
}
#ifdef F_15
else if ( V_66 [ V_68 ] . V_71 == V_81 ) {
F_17 ( L_29 , L_33 , V_73 ) ;
} else if ( V_66 [ V_68 ] . V_71 == V_82 ) {
F_17 ( L_29 , L_34 , V_73 ) ;
} else {
F_17 ( L_29 , L_35 , V_73 ) ;
}
#endif
memcpy ( & V_28 -> V_66 [ V_69 ] , & V_66 [ V_68 ] , sizeof( V_66 [ V_68 ] ) ) ;
V_69 ++ ;
}
}
V_28 -> V_67 = V_69 ;
F_24 ( L_29 ) ;
return V_69 ;
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
memset ( V_28 -> V_66 , 0 , sizeof( T_5 ) * V_70 ) ;
V_28 -> V_67 = 0 ;
F_17 ( L_36 , L_37 , V_48 ) ;
F_24 ( L_36 ) ;
}
INT F_38 (
const T_7 V_28 ,
T_5 V_66 [] ,
const T_13 V_67 )
{
V_60 V_68 ;
V_60 V_83 ;
F_16 ( L_38 ) ;
if ( V_28 == NULL ) {
F_17 ( L_38 , L_19 , V_48 ) ;
F_24 ( L_38 ) ;
return 0 ;
} else if ( V_66 == NULL ) {
F_17 ( L_38 , L_39 , V_48 ) ;
F_24 ( L_38 ) ;
return ( INT ) V_28 -> V_67 ;
} else {
for ( V_68 = 0 , V_83 = 0 ; V_68 < V_28 -> V_67 && V_68 < V_67 && V_68 < V_70 ; V_68 ++ ) {
memcpy ( & V_66 [ V_83 ] , & V_28 -> V_66 [ V_68 ] , sizeof( V_66 [ V_83 ] ) ) ;
V_83 ++ ;
F_17 ( L_38 , L_40 , V_48 ) ;
}
F_24 ( L_38 ) ;
return V_83 ;
}
}
INT F_39 (
T_7 V_28 ,
CHAR * V_84 ,
T_13 V_85 )
{
if ( ! V_28 || ! V_84 || V_85 < 1 || V_85 > V_86 )
return V_52 ;
memcpy ( V_28 -> V_84 , V_84 , V_85 ) ;
V_28 -> V_85 = V_85 ;
return V_65 ;
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
V_28 -> V_87 = 0 ;
V_28 -> V_88 = - 1 ;
V_28 -> V_30 = - 1 ;
V_28 -> V_85 = 0 ;
memset ( V_28 -> V_3 , 0 , V_89 * sizeof( V_90 ) ) ;
F_17 ( L_41 , L_42 , V_48 ) ;
F_24 ( L_41 ) ;
return V_65 ;
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
V_28 -> V_87 = 0 ;
V_28 -> V_88 = - 1 ;
V_28 -> V_30 = - 1 ;
F_17 ( L_43 , L_44 , V_48 ) ;
F_24 ( L_43 ) ;
return V_65 ;
}
static INT
F_32 (
T_10 * V_53 ,
T_9 V_32 ,
T_9 * V_54 ,
T_11 V_23 ,
V_90 * V_3 ,
INT V_37 )
{
INT V_91 = 1 ;
T_10 * V_92 ;
T_9 V_93 = * V_54 ;
if ( V_3 -> V_23 == NULL ) {
F_17 ( L_45 , L_46 , V_41 ) ;
return V_49 ;
}
if ( V_3 -> V_24 == FALSE ) {
F_17 ( L_45 , L_47 , V_41 ) ;
return V_52 ;
}
V_92 = ( T_10 * ) F_41 ( V_93 ) ;
for(; V_3 != NULL ; V_3 = V_3 -> V_94 ) {
if ( * V_54 > V_93 ) {
F_17 ( L_45 , L_48 , V_41 ) ;
return V_52 ;
}
memcpy ( V_92 , V_53 , * V_54 ) ;
if ( V_3 -> V_25 . V_26 == 1 ) {
F_17 ( L_45 , L_49 , V_41 ) ;
F_5 ( L_50 , V_3 -> V_25 . V_27 , 64 ) ;
F_5 ( L_51 , F_42 ( V_3 -> V_25 . V_27 ) , 16 ) ;
V_91 = F_43 ( V_92 + V_37 , * V_54 - V_37 , V_92 + V_95 , F_42 ( V_3 -> V_25 . V_27 ) ) ;
if ( V_91 ) {
F_17 ( L_45 , L_52 , V_41 ) ;
continue;
}
F_17 ( L_45 , L_53 , V_41 ) ;
* V_54 -= 12 ;
break;
} else {
F_17 ( L_45 , L_54 , V_41 ) ;
V_91 = F_44 ( V_92 , V_32 , ( INT ) * V_54 , F_42 ( V_3 -> V_25 . V_27 ) ) ;
if ( V_91 )
continue;
F_17 ( L_45 , L_55 , V_41 ) ;
* V_54 -= 8 ;
break;
}
}
if( V_3 == NULL )
return V_91 ;
if ( * V_54 > V_93 || * V_54 < 8 ) {
F_17 ( L_45 , L_48 , V_41 ) ;
return V_52 ;
}
memcpy ( V_53 , V_92 , * V_54 ) ;
V_53 [ 1 ] &= 0xBF ;
V_37 = V_32 ;
* V_54 -= 8 ;
memmove ( V_53 + V_37 , V_53 + V_37 + 8 , * V_54 - V_37 ) ;
if ( V_23 != NULL ) {
memcpy ( V_23 , V_3 -> V_23 , sizeof( T_5 ) ) ;
if ( V_3 -> V_25 . V_26 == V_10 )
V_23 -> V_71 = V_96 ;
else if ( V_3 -> V_25 . V_26 == V_12 )
V_23 -> V_71 = V_97 ;
}
return V_65 ;
}
static INT
F_30 (
T_7 V_28 ,
T_10 * V_53 ,
T_9 V_32 ,
T_9 * V_54 ,
T_11 V_23 ,
V_90 * V_3 ,
INT V_37 )
{
T_10 V_98 [ V_99 + V_100 ] ;
T_13 V_101 ;
INT V_91 = 1 ;
INT V_20 ;
T_5 * V_102 ;
T_14 V_103 = FALSE ;
T_10 * V_92 ;
T_9 V_93 = * V_54 ;
V_92 = ( T_10 * ) F_41 ( V_93 ) ;
if ( V_3 -> V_23 != NULL )
V_103 = TRUE ;
for ( V_20 = 0 ; V_20 < ( INT ) V_28 -> V_67 ; V_20 ++ ) {
if ( ! V_103 ) {
V_102 = & V_28 -> V_66 [ V_20 ] ;
} else {
if ( V_3 -> V_23 != NULL && V_3 -> V_23 -> V_71 == V_82 ) {
F_17 ( L_56 , L_57 , V_41 ) ;
V_102 = V_3 -> V_23 ;
} else {
F_17 ( L_56 , L_58 , V_41 ) ;
V_102 = & V_28 -> V_66 [ V_20 ] ;
}
}
if ( V_102 -> V_71 == V_82 )
{
F_17 ( L_56 , L_59 , V_41 ) ;
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
memcpy ( V_92 , V_53 , * V_54 ) ;
memcpy ( V_98 , V_92 + V_32 , V_100 ) ;
V_101 = V_102 -> V_78 . V_104 . V_105 ;
memcpy ( V_98 + V_100 , V_102 -> V_78 . V_104 . V_106 , V_101 ) ;
V_91 = F_45 ( V_98 ,
V_101 + V_100 ,
V_92 + ( V_32 + V_100 + V_107 ) ,
* V_54 - ( V_32 + V_100 + V_107 + V_108 ) ) ;
if ( V_91 == V_65 )
memcpy ( V_53 , V_92 , * V_54 ) ;
}
if ( ! V_91 && V_102 -> V_71 == V_82 ) {
V_3 -> V_23 = V_102 ;
if ( V_23 != NULL ) {
memcpy ( V_23 , & V_3 -> V_23 , sizeof( T_5 ) ) ;
V_23 -> V_71 = V_82 ;
}
break;
} else {
if ( V_103 == TRUE ) {
V_103 = FALSE ;
V_20 -- ;
}
}
}
if ( V_91 )
return V_91 ;
F_17 ( L_56 , L_60 , V_41 ) ;
* V_54 -= 4 ;
if ( * V_54 < 4 ) {
F_17 ( L_56 , L_61 , V_41 ) ;
return V_52 ;
}
V_53 [ 1 ] &= 0xBF ;
V_37 = V_32 ;
* V_54 -= 4 ;
memcpy ( V_53 + V_37 , V_53 + V_37 + V_100 + V_107 , * V_54 - V_37 ) ;
return V_65 ;
}
static INT
F_28 (
T_7 V_28 ,
const T_10 * V_31 ,
V_90 * V_3 ,
T_11 V_23 ,
INT V_37 )
{
T_5 * V_102 , * V_109 , V_110 ;
V_90 * V_111 ;
INT V_20 ;
INT V_91 = 1 ;
T_10 V_103 = FALSE ;
T_10 V_112 [ V_113 ] ;
T_15 V_114 ;
if ( V_3 -> V_23 != NULL )
V_103 = TRUE ;
if ( F_18 ( V_31 [ V_37 + 1 ] ) != 1 ) {
F_17 ( L_62 , L_63 , V_48 ) ;
return V_42 ;
}
if( V_3 -> V_115 == 4 ) {
V_111 = ( V_90 * ) F_46 ( sizeof( V_90 ) ) ;
memcpy ( V_111 , V_3 , sizeof( V_90 ) ) ;
V_3 -> V_94 = V_111 ;
}
F_17 ( L_62 , L_64 , V_48 ) ;
if ( F_47 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_19 ( V_31 [ V_37 + 1 ] ) == 1 &&
F_20 ( V_31 [ V_37 ] ) == 0 )
{
F_17 ( L_62 , L_65 , V_41 ) ;
memcpy ( V_3 -> V_25 . V_116 , V_31 + V_37 + 12 , 32 ) ;
V_3 -> V_25 . V_26 = F_2 ( V_31 [ V_37 + 1 ] ) ;
V_3 -> V_115 = 1 ;
return V_117 ;
}
if ( F_47 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_19 ( V_31 [ V_37 + 1 ] ) == 0 &&
F_20 ( V_31 [ V_37 ] ) == 1 )
{
if ( F_21 ( V_31 [ V_37 ] ) == 0 ) {
if ( V_31 [ V_37 + 92 ] != 0 || V_31 [ V_37 + 93 ] != 0 ) {
F_17 ( L_62 , L_66 , V_41 ) ;
for ( V_20 = 0 ; V_20 < ( INT ) V_28 -> V_67 || V_103 ; V_20 ++ ) {
if ( ! V_103 ) {
F_17 ( L_62 , L_67 , V_41 ) ;
V_102 = & V_28 -> V_66 [ V_20 ] ;
} else {
if ( V_3 -> V_23 != NULL &&
( V_3 -> V_23 -> V_71 == V_72 ||
V_3 -> V_23 -> V_71 == V_118 ||
V_3 -> V_23 -> V_71 == V_81 ) ) {
F_17 ( L_62 , L_68 , V_41 ) ;
V_102 = V_3 -> V_23 ;
} else {
F_17 ( L_62 , L_69 , V_41 ) ;
V_102 = & V_28 -> V_66 [ V_20 ] ;
}
}
if ( V_102 -> V_71 == V_72 ||
V_102 -> V_71 == V_118 ||
V_102 -> V_71 == V_81 )
{
if ( V_102 -> V_71 == V_72 && V_102 -> V_74 . V_77 == 0 && V_28 -> V_85 > 0 && V_28 -> V_85 <= V_119 ) {
memcpy ( & V_110 , V_102 , sizeof( V_110 ) ) ;
memcpy ( & V_110 . V_74 . V_76 , V_28 -> V_84 , V_28 -> V_85 ) ;
V_110 . V_74 . V_77 = V_28 -> V_85 ;
F_36 ( V_110 . V_74 . V_75 , V_110 . V_74 . V_76 ,
V_110 . V_74 . V_77 , V_110 . V_78 . V_79 . V_80 ) ;
V_109 = & V_110 ;
} else {
V_109 = V_102 ;
}
F_48 ( V_3 ,
V_109 -> V_78 . V_79 . V_120 ,
V_31 + V_37 + 12 ,
512 ,
V_3 -> V_25 . V_27 ) ;
V_114 = F_3 ( V_31 + V_37 - 3 ) + 4 ;
memcpy ( V_112 , & V_31 [ V_37 - 5 ] , ( V_114 < V_113 ? V_114 : V_113 ) ) ;
V_91 = F_49 ( V_112 ,
V_114 ,
V_3 -> V_25 . V_27 ,
F_2 ( V_31 [ V_37 + 1 ] ) ) ;
}
if ( ! V_91 &&
( V_102 -> V_71 == V_72 ||
V_102 -> V_71 == V_118 ||
V_102 -> V_71 == V_81 ) )
{
V_3 -> V_23 = V_102 ;
if ( V_23 != NULL ) {
memcpy ( V_23 , & V_102 , sizeof( T_5 ) ) ;
if ( F_2 ( V_31 [ V_37 + 1 ] ) == V_10 )
V_23 -> V_71 = V_96 ;
else if ( F_2 ( V_31 [ V_37 + 1 ] ) == V_12 )
V_23 -> V_71 = V_97 ;
}
break;
} else {
if ( V_103 == TRUE ) {
V_103 = FALSE ;
V_20 -- ;
}
}
}
if ( V_91 ) {
F_17 ( L_62 , L_70 , V_41 ) ;
return V_42 ;
}
V_3 -> V_115 = 2 ;
return V_117 ;
} else {
F_17 ( L_62 , L_71 , V_41 ) ;
V_3 -> V_115 = 4 ;
V_3 -> V_24 = TRUE ;
return V_117 ;
}
} else {
F_17 ( L_62 , L_72 , V_41 ) ;
V_3 -> V_115 = 4 ;
V_3 -> V_24 = TRUE ;
return V_117 ;
}
}
if ( F_19 ( V_31 [ V_37 + 1 ] ) == 1 &&
F_20 ( V_31 [ V_37 ] ) == 1 )
{
const T_1 * V_1 ;
F_17 ( L_62 , L_73 , V_41 ) ;
V_1 = ( const T_1 * ) ( & ( V_31 [ V_37 - 1 ] ) ) ;
if ( V_1 -> type == V_43 ) {
T_3 V_121 ;
T_8 V_29 ;
memcpy ( V_29 . V_50 , V_51 , V_47 ) ;
memcpy ( V_29 . V_46 , V_3 -> V_122 . V_46 , V_47 ) ;
V_121 = F_11 ( V_28 , & V_29 ) ;
if ( V_121 == NULL ) {
return V_52 ;
}
F_1 ( V_1 , V_3 -> V_25 . V_27 + 16 , V_121 ) ;
}
return V_117 ;
}
return V_52 ;
}
static INT
F_49 (
T_10 * V_112 ,
T_15 V_114 ,
T_10 V_123 [ V_124 ] ,
T_15 V_26 )
{
T_10 V_125 [ V_126 ] ;
T_10 V_127 [ 20 ] ;
memcpy ( V_125 , V_112 + V_128 + 4 , V_126 ) ;
memset ( V_112 + V_128 + 4 , 0 , V_126 ) ;
if ( V_26 == V_10 ) {
F_50 ( V_112 , V_114 , V_123 , V_124 , V_127 ) ;
} else if ( V_26 == V_12 ) {
F_51 ( V_123 , V_124 , V_112 , V_114 , V_127 ) ;
} else
return V_52 ;
return memcmp ( V_125 , V_127 , V_126 ) ;
}
static INT
F_35 (
T_11 V_23 )
{
T_13 V_129 ;
T_10 V_130 = TRUE ;
F_16 ( L_74 ) ;
if ( V_23 == NULL ) {
F_17 ( L_74 , L_75 , V_48 ) ;
F_16 ( L_74 ) ;
return FALSE ;
}
switch ( V_23 -> V_71 ) {
case V_82 :
V_129 = V_23 -> V_78 . V_104 . V_105 ;
if ( V_129 < V_131 || V_129 > V_99 ) {
F_17 ( L_74 , L_76 , V_48 ) ;
V_130 = FALSE ;
}
break;
case V_132 :
V_23 -> V_78 . V_104 . V_105 = V_133 ;
V_23 -> V_71 = V_82 ;
break;
case V_134 :
V_23 -> V_78 . V_104 . V_105 = V_135 ;
V_23 -> V_71 = V_82 ;
break;
case V_72 :
V_129 = strlen ( V_23 -> V_74 . V_75 ) ;
if ( V_129 < V_136 || V_129 > V_137 ) {
F_17 ( L_74 , L_77 , V_48 ) ;
V_130 = FALSE ;
}
V_129 = V_23 -> V_74 . V_77 ;
if ( V_129 > V_119 ) {
F_17 ( L_74 , L_78 , V_48 ) ;
V_130 = FALSE ;
}
break;
case V_118 :
break;
case V_81 :
break;
default:
V_130 = FALSE ;
}
F_24 ( L_74 ) ;
return V_130 ;
}
static INT
F_12 (
T_7 V_28 ,
T_8 * V_29 )
{
INT V_30 ;
if ( V_28 -> V_30 != - 1 ) {
for ( V_30 = V_28 -> V_30 ; V_30 >= 0 ; V_30 -- ) {
if ( V_28 -> V_3 [ V_30 ] . V_138 ) {
if ( memcmp ( V_29 , & ( V_28 -> V_3 [ V_30 ] . V_122 ) , sizeof( T_8 ) ) == 0 ) {
V_28 -> V_88 = V_30 ;
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
INT V_139 ;
if ( V_28 -> V_3 [ V_28 -> V_87 ] . V_138 ) {
for ( V_139 = V_28 -> V_87 ; V_139 < V_89 ; V_139 ++ )
if ( ! V_28 -> V_3 [ V_139 ] . V_138 )
break;
if ( V_139 >= V_89 ) {
return - 1 ;
}
V_28 -> V_87 = V_139 ;
}
V_28 -> V_88 = V_28 -> V_87 ;
memset ( V_28 -> V_3 + V_28 -> V_88 , 0 , sizeof( V_90 ) ) ;
V_28 -> V_3 [ V_28 -> V_88 ] . V_138 = 1 ;
memcpy ( & ( V_28 -> V_3 [ V_28 -> V_88 ] . V_122 ) , V_29 , sizeof( T_8 ) ) ;
V_28 -> V_87 ++ ;
if ( V_28 -> V_88 > V_28 -> V_30 )
V_28 -> V_30 = V_28 -> V_88 ;
return V_28 -> V_88 ;
}
static const T_10 *
F_23 (
const V_45 * V_140 )
{
switch( F_52 ( V_140 -> V_141 [ 1 ] ) ) {
case 0 :
case 1 :
return V_140 -> V_142 ;
case 2 :
return V_140 -> V_143 ;
case 3 :
if ( memcmp ( V_140 -> V_143 , V_140 -> V_142 , V_47 ) < 0 )
return V_140 -> V_143 ;
else
return V_140 -> V_142 ;
default:
return NULL ;
}
}
static const T_10 *
F_22 (
const V_45 * V_140 )
{
switch( F_52 ( V_140 -> V_141 [ 1 ] ) ) {
case 0 :
return V_140 -> V_144 ;
case 1 :
return V_140 -> V_143 ;
case 2 :
return V_140 -> V_142 ;
case 3 :
if ( memcmp ( V_140 -> V_143 , V_140 -> V_142 , V_47 ) > 0 )
return V_140 -> V_143 ;
else
return V_140 -> V_142 ;
default:
return NULL ;
}
}
static void
F_48 (
V_90 * V_3 ,
const T_10 V_145 [ 32 ] ,
const T_10 V_146 [ 32 ] ,
const INT V_147 ,
T_10 * V_27 )
{
T_14 V_68 ;
T_10 V_148 [ 100 ] ;
INT V_37 = sizeof( L_79 ) ;
memset ( V_148 , 0 , 100 ) ;
memcpy ( V_148 , L_79 , V_37 ) ;
if ( memcmp ( V_3 -> V_122 . V_50 , V_3 -> V_122 . V_46 , V_47 ) < 0 )
{
memcpy ( V_148 + V_37 , V_3 -> V_122 . V_50 , V_47 ) ;
memcpy ( V_148 + V_37 + V_47 , V_3 -> V_122 . V_46 , V_47 ) ;
}
else
{
memcpy ( V_148 + V_37 , V_3 -> V_122 . V_46 , V_47 ) ;
memcpy ( V_148 + V_37 + V_47 , V_3 -> V_122 . V_50 , V_47 ) ;
}
V_37 += V_47 * 2 ;
if( memcmp ( V_146 , V_3 -> V_25 . V_116 , 32 ) < 0 )
{
memcpy ( V_148 + V_37 , V_146 , 32 ) ;
memcpy ( V_148 + V_37 + 32 , V_3 -> V_25 . V_116 , 32 ) ;
}
else
{
memcpy ( V_148 + V_37 , V_3 -> V_25 . V_116 , 32 ) ;
memcpy ( V_148 + V_37 + 32 , V_146 , 32 ) ;
}
V_37 += 32 * 2 ;
for( V_68 = 0 ; V_68 < ( V_147 + 159 ) / 160 ; V_68 ++ )
{
V_148 [ V_37 ] = V_68 ;
F_51 ( V_145 , 32 , V_148 , 100 , V_27 + V_68 * 20 ) ;
}
}
static INT
F_53 (
const T_2 * V_149 ,
const T_9 V_150 ,
const CHAR * V_151 ,
const T_13 V_152 ,
const INT V_153 ,
const INT V_154 ,
T_10 * V_155 )
{
T_10 V_156 [ 64 ] , V_157 [ 64 ] ;
INT V_68 , V_83 ;
if ( V_152 + 4 > 36 )
return V_52 ;
memset ( V_156 , 0 , 64 ) ;
memset ( V_157 , 0 , 64 ) ;
memcpy ( V_156 , V_151 , V_152 ) ;
V_156 [ V_152 ] = ( T_10 ) ( ( V_154 >> 24 ) & 0xff ) ;
V_156 [ V_152 + 1 ] = ( T_10 ) ( ( V_154 >> 16 ) & 0xff ) ;
V_156 [ V_152 + 2 ] = ( T_10 ) ( ( V_154 >> 8 ) & 0xff ) ;
V_156 [ V_152 + 3 ] = ( T_10 ) ( V_154 & 0xff ) ;
F_51 ( V_149 , V_150 , V_156 , ( V_158 ) V_152 + 4 , V_157 ) ;
memcpy ( V_155 , V_157 , V_159 ) ;
for ( V_68 = 1 ; V_68 < V_153 ; V_68 ++ ) {
F_51 ( V_149 , V_150 , V_157 , V_159 , V_156 ) ;
memcpy ( V_157 , V_156 , V_159 ) ;
for ( V_83 = 0 ; V_83 < V_159 ; V_83 ++ ) {
V_155 [ V_83 ] ^= V_156 [ V_83 ] ;
}
}
return V_65 ;
}
static INT
F_36 (
const CHAR * V_160 ,
const CHAR * V_151 ,
const T_13 V_152 ,
T_10 * V_155 )
{
T_10 V_161 [ V_162 ] ;
T_16 * V_163 = F_54 () ;
memset ( V_161 , 0 , V_162 ) ;
if ( ! F_55 ( V_160 , V_163 ) ) {
F_56 ( V_163 , TRUE ) ;
return 0 ;
}
F_53 ( V_163 -> V_31 , V_163 -> V_129 , V_151 , V_152 , 4096 , 1 , V_161 ) ;
F_53 ( V_163 -> V_31 , V_163 -> V_129 , V_151 , V_152 , 4096 , 2 , & V_161 [ V_159 ] ) ;
memcpy ( V_155 , V_161 , V_162 ) ;
F_56 ( V_163 , TRUE ) ;
return 0 ;
}
T_17 *
F_57 ( T_18 * V_164 , T_2 V_165 )
{
T_18 * V_23 ;
T_18 * V_151 ;
T_19 * V_166 = NULL ;
T_16 * V_167 = NULL , * V_168 ;
T_12 V_169 ;
T_18 * * V_170 ;
T_9 V_171 = 0 ;
T_17 * V_172 ;
if( V_164 == NULL )
return NULL ;
switch( V_165 )
{
case V_82 :
case V_132 :
case V_134 :
V_168 = F_54 () ;
V_169 = F_58 ( V_164 , V_168 , FALSE ) ;
if ( V_169 && V_168 -> V_129 > 0 ) {
V_172 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_172 -> type = V_82 ;
V_172 -> V_23 = F_59 ( F_60 ( V_168 -> V_31 , V_168 -> V_129 ) ) ;
F_61 ( V_172 -> V_23 ) ;
V_172 -> V_173 = V_168 -> V_129 * 8 ;
V_172 -> V_151 = NULL ;
F_56 ( V_168 , TRUE ) ;
return V_172 ;
}
F_56 ( V_168 , TRUE ) ;
return NULL ;
case V_72 :
V_170 = F_62 ( V_164 , L_80 , 0 ) ;
while( V_170 [ V_171 ] != NULL )
V_171 ++ ;
if( V_171 < 1 )
{
F_63 ( V_170 ) ;
return NULL ;
}
V_23 = F_64 ( V_170 [ 0 ] ) ;
V_151 = NULL ;
if( V_171 >= 2 )
{
V_151 = F_64 ( V_170 [ 1 ] ) ;
}
V_166 = F_59 ( V_23 ) ;
V_167 = NULL ;
if( ( ( V_166 -> V_129 ) > V_174 ) || ( ( V_166 -> V_129 ) < V_175 ) )
{
F_65 ( V_166 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_151 ) ;
F_63 ( V_170 ) ;
return NULL ;
}
if( V_151 != NULL )
{
V_167 = F_54 () ;
if ( ! F_55 ( V_151 , V_167 ) ) {
F_65 ( V_166 , TRUE ) ;
F_56 ( V_167 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_151 ) ;
F_63 ( V_170 ) ;
return NULL ;
}
if( V_167 -> V_129 > V_176 )
{
F_65 ( V_166 , TRUE ) ;
F_56 ( V_167 , TRUE ) ;
F_10 ( V_23 ) ;
F_10 ( V_151 ) ;
F_63 ( V_170 ) ;
return NULL ;
}
}
V_172 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_172 -> type = V_72 ;
V_172 -> V_23 = F_59 ( V_23 ) ;
V_172 -> V_173 = 256 ;
V_172 -> V_151 = F_66 ( V_167 ) ;
F_65 ( V_166 , TRUE ) ;
if ( V_167 != NULL )
F_56 ( V_167 , TRUE ) ;
F_10 ( V_23 ) ;
if( V_151 != NULL )
F_10 ( V_151 ) ;
F_63 ( V_170 ) ;
return V_172 ;
case V_118 :
V_168 = F_54 () ;
V_169 = F_58 ( V_164 , V_168 , FALSE ) ;
if( ! V_169 || ( ( V_168 -> V_129 ) != V_177 ) )
{
F_56 ( V_168 , TRUE ) ;
return NULL ;
}
V_172 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_172 -> type = V_118 ;
V_172 -> V_23 = F_59 ( V_164 ) ;
V_172 -> V_173 = ( T_9 ) V_172 -> V_23 -> V_129 * 4 ;
V_172 -> V_151 = NULL ;
F_56 ( V_168 , TRUE ) ;
return V_172 ;
}
return NULL ;
}
T_18 *
F_67 ( T_17 * V_172 )
{
T_18 * V_178 = NULL ;
if( V_172 == NULL || V_172 -> V_23 == NULL )
return NULL ;
switch( V_172 -> type ) {
case V_82 :
V_178 = F_64 ( V_172 -> V_23 -> V_179 ) ;
break;
case V_72 :
if( V_172 -> V_151 == NULL )
V_178 = F_64 ( V_172 -> V_23 -> V_179 ) ;
else
V_178 = F_68 ( L_81 ,
V_172 -> V_23 -> V_179 , F_69 ( V_172 -> V_151 , L_80 ) ) ;
break;
case V_81 :
V_178 = F_64 ( V_172 -> V_23 -> V_179 ) ;
break;
default:
return NULL ;
}
return V_178 ;
}
