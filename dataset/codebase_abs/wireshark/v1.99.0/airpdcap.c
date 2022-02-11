static void
F_1 ( const T_1 * V_1 , T_2 * V_2 , T_3 V_3 , T_4 V_4 )
{
T_2 V_5 [ 32 ] ;
T_2 V_6 ;
T_2 * V_7 ;
T_5 V_8 = 0 ;
T_5 V_9 = 0 ;
static T_6 V_10 ;
V_6 = F_2 ( V_1 -> V_11 [ 1 ] ) ;
if ( V_6 == V_12 ) {
V_8 = F_3 ( V_1 -> V_13 ) ;
} else if ( V_6 == V_14 ) {
V_8 = F_3 ( V_1 -> V_15 ) ;
}
if ( V_8 > V_16 || V_8 == 0 ) {
return;
}
V_7 = ( T_2 * ) F_4 ( V_1 -> V_17 , V_8 ) ;
F_5 ( L_1 , V_7 , V_8 ) ;
F_5 ( L_2 , V_1 -> V_18 , 16 ) ;
F_5 ( L_3 , V_2 , 16 ) ;
memcpy ( V_5 , V_1 -> V_18 , 16 ) ;
memcpy ( V_5 + 16 , V_2 , 16 ) ;
F_5 ( L_4 , V_5 , 32 ) ;
if ( V_6 == V_12 ) {
T_2 V_19 [ 256 ] ;
T_7 V_20 ;
V_3 -> V_21 . V_22 = ( V_8 >= V_23 ) ? V_12 : V_14 ;
F_6 ( & V_20 , V_5 , sizeof( V_5 ) ) ;
F_7 ( & V_20 , V_19 , 256 ) ;
F_7 ( & V_20 , V_7 , V_8 ) ;
} else if ( V_6 == V_14 ) {
T_2 V_24 ;
T_5 V_25 ;
T_2 * V_26 ;
if ( V_4 )
V_3 -> V_21 . V_22 = ( V_8 >= ( V_27 ) ) ? V_12 : V_14 ;
else
V_3 -> V_21 . V_22 = ( V_8 >= ( V_28 ) ) ? V_12 : V_14 ;
V_26 = ( T_2 * ) F_8 ( V_8 ) ;
F_9 ( V_2 , 16 , V_7 , V_8 , V_26 ) ;
V_24 = FALSE ;
V_25 = 0 ;
while( V_25 < V_8 && ! V_24 ) {
T_2 V_29 ;
V_29 = V_26 [ V_25 ] ;
if ( V_29 != 0xdd ) {
V_25 += V_26 [ V_25 + 1 ] + 2 ;
} else{
V_24 = TRUE ;
}
}
if ( V_24 ) {
memcpy ( V_7 , V_26 + V_25 + 8 , V_8 - V_25 - 8 ) ;
}
F_10 ( V_26 ) ;
}
V_9 = ( V_3 -> V_21 . V_22 == V_12 ) ? V_23 : V_30 ;
F_5 ( L_5 , V_7 , V_9 ) ;
V_3 -> V_31 = & V_10 ;
V_3 -> V_32 = TRUE ;
memset ( V_3 -> V_21 . V_33 , 0 , sizeof( V_3 -> V_21 . V_33 ) ) ;
memcpy ( V_3 -> V_21 . V_33 + 32 , V_7 , V_9 ) ;
F_10 ( V_7 ) ;
}
static T_3
F_11 (
T_8 V_34 ,
T_9 * V_35 )
{
int V_36 ;
if ( ( V_36 = F_12 ( V_34 , V_35 ) ) == - 1 ) {
if ( ( V_36 = F_13 ( V_34 , V_35 ) ) == - 1 ) {
return NULL ;
}
}
return & V_34 -> V_3 [ V_36 ] ;
}
static INT F_14 (
T_8 V_34 ,
const T_2 * V_37 ,
const T_10 V_38 ,
const T_10 V_39
)
{
const T_11 * V_40 ;
T_9 V_35 ;
T_10 V_41 ;
T_3 V_42 ;
T_3 V_3 ;
int V_43 = 0 ;
const T_2 V_44 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
const T_1 * V_1 ;
#ifdef F_15
CHAR V_45 [ 255 ] ;
#endif
F_16 ( L_6 ) ;
if ( V_38 + V_46 > V_39 ) {
F_17 ( L_6 , L_7 , V_47 ) ;
return V_48 ;
}
V_43 = V_38 ;
if ( memcmp ( V_37 + V_43 , V_44 , 8 ) == 0 ) {
F_17 ( L_6 , L_8 , V_47 ) ;
V_43 += 8 ;
if ( V_37 [ V_43 + 1 ] != 3 ) {
F_17 ( L_6 , L_9 , V_47 ) ;
return V_48 ;
}
V_41 = F_3 ( V_37 + V_43 + 2 ) ;
if ( ( V_39 - V_43 - 4 ) > V_41 ) {
F_17 ( L_6 , L_10 , V_47 ) ;
return V_48 ;
}
V_43 += 4 ;
V_1 = ( const T_1 * ) ( V_37 + V_43 ) ;
if (
V_1 -> type != V_49 &&
V_1 -> type != V_50 )
{
F_17 ( L_6 , L_11 , V_47 ) ;
return V_48 ;
}
V_43 += 1 ;
if ( F_18 ( V_37 [ V_43 + 1 ] ) != 0 ||
F_19 ( V_37 [ V_43 + 1 ] ) != 1 ||
F_20 ( V_37 [ V_43 ] ) != 1 ||
F_21 ( V_37 [ V_43 ] ) != 1 ) {
F_17 ( L_6 , L_12 , V_47 ) ;
return V_48 ;
}
if ( ( V_40 = F_22 ( ( const V_51 * ) ( V_37 ) ) ) != NULL ) {
memcpy ( V_35 . V_52 , V_40 , V_53 ) ;
#ifdef F_15
sprintf ( V_45 , L_13 , V_35 . V_52 [ 0 ] , V_35 . V_52 [ 1 ] , V_35 . V_52 [ 2 ] , V_35 . V_52 [ 3 ] , V_35 . V_52 [ 4 ] , V_35 . V_52 [ 5 ] ) ;
#endif
F_17 ( L_6 , V_45 , V_47 ) ;
} else {
F_17 ( L_6 , L_14 , V_54 ) ;
return V_55 ;
}
memcpy ( V_35 . V_56 , V_57 , V_53 ) ;
V_3 = F_11 ( V_34 , & V_35 ) ;
if ( V_3 == NULL ) {
return V_58 ;
}
if ( ( V_40 = F_23 ( ( const V_51 * ) ( V_37 ) ) ) != NULL ) {
memcpy ( V_35 . V_56 , V_40 , V_53 ) ;
#ifdef F_15
sprintf ( V_45 , L_15 , V_35 . V_56 [ 0 ] , V_35 . V_56 [ 1 ] , V_35 . V_56 [ 2 ] , V_35 . V_56 [ 3 ] , V_35 . V_56 [ 4 ] , V_35 . V_56 [ 5 ] ) ;
#endif
F_17 ( L_6 , V_45 , V_47 ) ;
} else {
F_17 ( L_6 , L_16 , V_54 ) ;
return V_55 ;
}
V_42 = F_11 ( V_34 , & V_35 ) ;
if ( V_42 == NULL ) {
return V_58 ;
}
F_1 ( V_1 , V_42 -> V_21 . V_33 + 16 , V_3 , TRUE ) ;
} else{
F_17 ( L_6 , L_17 , V_47 ) ;
}
F_24 ( L_6 ) ;
return 0 ;
}
INT F_25 (
T_8 V_34 ,
const T_2 * V_37 ,
const T_10 V_38 ,
const T_10 V_39 ,
T_11 * V_59 ,
T_10 * V_60 ,
T_12 V_31 ,
T_4 V_61 ,
T_4 V_62 )
{
const T_11 * V_40 ;
T_9 V_35 ;
T_3 V_3 ;
int V_43 = 0 ;
T_10 V_41 ;
const T_2 V_44 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x00 , 0x00 ,
0x88 , 0x8E
} ;
const T_2 V_63 [] = {
0xAA ,
0xAA ,
0x03 ,
0x00 , 0x19 , 0x58 ,
0x00 , 0x03
} ;
#ifdef F_15
CHAR V_45 [ 255 ] ;
#endif
F_16 ( L_18 ) ;
if ( V_34 == NULL ) {
F_17 ( L_18 , L_19 , V_54 ) ;
F_24 ( L_18 ) ;
return V_58 ;
}
if ( V_37 == NULL || V_39 == 0 ) {
F_17 ( L_18 , L_20 , V_54 ) ;
F_24 ( L_18 ) ;
return V_58 ;
}
if ( F_26 ( V_37 [ 0 ] ) != V_64 ) {
F_17 ( L_18 , L_21 , V_54 ) ;
return V_65 ;
}
if ( V_39 < ( V_66 ) ( V_38 + V_67 ) ) {
F_17 ( L_18 , L_22 , V_54 ) ;
return V_68 ;
}
if ( ( V_40 = F_22 ( ( const V_51 * ) ( V_37 ) ) ) != NULL ) {
memcpy ( V_35 . V_52 , V_40 , V_53 ) ;
#ifdef F_15
sprintf ( V_45 , L_13 , V_35 . V_52 [ 0 ] , V_35 . V_52 [ 1 ] , V_35 . V_52 [ 2 ] , V_35 . V_52 [ 3 ] , V_35 . V_52 [ 4 ] , V_35 . V_52 [ 5 ] ) ;
#endif
F_17 ( L_18 , V_45 , V_47 ) ;
} else {
F_17 ( L_18 , L_14 , V_54 ) ;
return V_55 ;
}
if ( ( V_40 = F_23 ( ( const V_51 * ) ( V_37 ) ) ) != NULL ) {
memcpy ( V_35 . V_56 , V_40 , V_53 ) ;
#ifdef F_15
sprintf ( V_45 , L_15 , V_35 . V_56 [ 0 ] , V_35 . V_56 [ 1 ] , V_35 . V_56 [ 2 ] , V_35 . V_56 [ 3 ] , V_35 . V_56 [ 4 ] , V_35 . V_56 [ 5 ] ) ;
#endif
F_17 ( L_18 , V_45 , V_47 ) ;
} else {
F_17 ( L_18 , L_16 , V_54 ) ;
return V_55 ;
}
V_3 = F_11 ( V_34 , & V_35 ) ;
if ( V_3 == NULL ) {
return V_58 ;
}
V_43 = V_38 ;
if ( F_27 ( V_37 [ 1 ] ) == 0 )
{
if ( V_61 ) {
F_17 ( L_18 , L_23 , V_47 ) ;
if ( memcmp ( V_37 + V_43 , V_44 , 8 ) == 0 || memcmp ( V_37 + V_43 , V_63 , 8 ) == 0 ) {
F_17 ( L_18 , L_8 , V_47 ) ;
V_43 += 8 ;
#if 0
if (data[offset]!=2) {
AIRPDCAP_DEBUG_PRINT_LINE("EAPOL protocol version not recognized", AIRPDCAP_DEBUG_LEVEL_5);
return AIRPDCAP_RET_NO_VALID_HANDSHAKE;
}
#endif
if ( V_37 [ V_43 + 1 ] != 3 ) {
F_17 ( L_18 , L_9 , V_54 ) ;
return V_48 ;
}
V_41 = F_3 ( V_37 + V_43 + 2 ) ;
if ( ( V_39 - V_43 - 4 ) < V_41 ) {
F_17 ( L_18 , L_10 , V_54 ) ;
return V_48 ;
}
V_43 += 4 ;
if (
V_37 [ V_43 ] != 0x2 &&
V_37 [ V_43 ] != 0xFE )
{
F_17 ( L_18 , L_11 , V_54 ) ;
return V_48 ;
}
V_43 += 1 ;
return F_28 ( V_34 , V_37 , V_3 , V_31 , V_43 ) ;
} else {
F_17 ( L_18 , L_24 , V_54 ) ;
return V_69 ;
}
}
} else {
if ( V_62 ) {
if ( V_59 == NULL )
return V_58 ;
* V_60 = V_39 ;
memcpy ( V_59 , V_37 , * V_60 ) ;
F_17 ( L_18 , L_25 , V_47 ) ;
if ( F_29 ( V_37 [ V_43 + 3 ] ) == 0 ) {
F_17 ( L_18 , L_26 , V_47 ) ;
return F_30 ( V_34 , V_59 , V_38 , V_60 , V_31 , V_3 , V_43 ) ;
} else {
INT V_70 ;
F_17 ( L_18 , L_27 , V_47 ) ;
if ( F_31 ( V_37 [ V_43 + 3 ] ) >= 1 ) {
F_17 ( L_18 , L_28 , V_47 ) ;
memcpy ( V_35 . V_56 , V_57 , V_53 ) ;
#ifdef F_15
sprintf ( V_45 , L_15 , V_35 . V_56 [ 0 ] , V_35 . V_56 [ 1 ] , V_35 . V_56 [ 2 ] , V_35 . V_56 [ 3 ] , V_35 . V_56 [ 4 ] , V_35 . V_56 [ 5 ] ) ;
F_17 ( L_18 , V_45 , V_47 ) ;
#endif
V_3 = F_11 ( V_34 , & V_35 ) ;
if ( V_3 == NULL ) {
return V_58 ;
}
}
V_70 = F_32 ( V_59 , V_38 , V_60 , V_31 , V_3 , V_43 ) ;
if ( V_70 == V_71 )
F_14 ( V_34 , V_59 , V_38 , * V_60 ) ;
return V_70 ;
}
}
}
return V_58 ;
}
INT F_33 (
T_8 V_34 ,
T_6 V_72 [] ,
const T_13 V_73 )
{
INT V_74 ;
INT V_75 ;
F_16 ( L_29 ) ;
if ( V_34 == NULL || V_72 == NULL ) {
F_17 ( L_29 , L_30 , V_47 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
if ( V_73 > V_76 ) {
F_17 ( L_29 , L_31 , V_47 ) ;
F_24 ( L_29 ) ;
return 0 ;
}
F_34 ( V_34 ) ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < ( INT ) V_73 ; V_74 ++ ) {
if ( F_35 ( V_72 + V_74 ) == TRUE ) {
if ( V_72 [ V_74 ] . V_77 == V_78 ) {
F_17 ( L_29 , L_32 , V_79 ) ;
F_36 ( V_72 [ V_74 ] . V_80 . V_81 , V_72 [ V_74 ] . V_80 . V_82 , V_72 [ V_74 ] . V_80 . V_83 , V_72 [ V_74 ] . V_84 . V_85 . V_86 ) ;
}
#ifdef F_15
else if ( V_72 [ V_74 ] . V_77 == V_87 ) {
F_17 ( L_29 , L_33 , V_79 ) ;
} else if ( V_72 [ V_74 ] . V_77 == V_88 ) {
F_17 ( L_29 , L_34 , V_79 ) ;
} else {
F_17 ( L_29 , L_35 , V_79 ) ;
}
#endif
memcpy ( & V_34 -> V_72 [ V_75 ] , & V_72 [ V_74 ] , sizeof( V_72 [ V_74 ] ) ) ;
V_75 ++ ;
}
}
V_34 -> V_73 = V_75 ;
F_24 ( L_29 ) ;
return V_75 ;
}
static void
F_37 (
T_8 V_34 )
{
F_16 ( L_36 ) ;
if ( V_34 == NULL ) {
F_17 ( L_36 , L_19 , V_54 ) ;
F_24 ( L_36 ) ;
return;
}
memset ( V_34 -> V_72 , 0 , sizeof( T_6 ) * V_76 ) ;
V_34 -> V_73 = 0 ;
F_17 ( L_36 , L_37 , V_54 ) ;
F_24 ( L_36 ) ;
}
INT F_38 (
const T_8 V_34 ,
T_6 V_72 [] ,
const T_13 V_73 )
{
V_66 V_74 ;
V_66 V_89 ;
F_16 ( L_38 ) ;
if ( V_34 == NULL ) {
F_17 ( L_38 , L_19 , V_54 ) ;
F_24 ( L_38 ) ;
return 0 ;
} else if ( V_72 == NULL ) {
F_17 ( L_38 , L_39 , V_54 ) ;
F_24 ( L_38 ) ;
return ( INT ) V_34 -> V_73 ;
} else {
for ( V_74 = 0 , V_89 = 0 ; V_74 < V_34 -> V_73 && V_74 < V_73 && V_74 < V_76 ; V_74 ++ ) {
memcpy ( & V_72 [ V_89 ] , & V_34 -> V_72 [ V_74 ] , sizeof( V_72 [ V_89 ] ) ) ;
V_89 ++ ;
F_17 ( L_38 , L_40 , V_54 ) ;
}
F_24 ( L_38 ) ;
return V_89 ;
}
}
INT F_39 (
T_8 V_34 ,
CHAR * V_90 ,
T_13 V_91 )
{
if ( ! V_34 || ! V_90 || V_91 < 1 || V_91 > V_92 )
return V_58 ;
memcpy ( V_34 -> V_90 , V_90 , V_91 ) ;
V_34 -> V_91 = V_91 ;
return V_71 ;
}
INT F_34 (
T_8 V_34 )
{
F_16 ( L_41 ) ;
if ( V_34 == NULL ) {
F_17 ( L_41 , L_19 , V_54 ) ;
F_24 ( L_41 ) ;
return V_58 ;
}
F_37 ( V_34 ) ;
V_34 -> V_93 = 0 ;
V_34 -> V_94 = - 1 ;
V_34 -> V_36 = - 1 ;
V_34 -> V_91 = 0 ;
memset ( V_34 -> V_3 , 0 , V_95 * sizeof( V_96 ) ) ;
F_17 ( L_41 , L_42 , V_54 ) ;
F_24 ( L_41 ) ;
return V_71 ;
}
INT F_40 (
T_8 V_34 )
{
F_16 ( L_43 ) ;
if ( V_34 == NULL ) {
F_17 ( L_43 , L_19 , V_54 ) ;
F_24 ( L_43 ) ;
return V_58 ;
}
F_37 ( V_34 ) ;
V_34 -> V_93 = 0 ;
V_34 -> V_94 = - 1 ;
V_34 -> V_36 = - 1 ;
F_17 ( L_43 , L_44 , V_54 ) ;
F_24 ( L_43 ) ;
return V_71 ;
}
static INT
F_32 (
T_11 * V_59 ,
T_10 V_38 ,
T_10 * V_60 ,
T_12 V_31 ,
V_96 * V_3 ,
INT V_43 )
{
INT V_97 = 1 ;
T_11 * V_98 ;
T_10 V_99 = * V_60 ;
if ( V_3 -> V_31 == NULL ) {
F_17 ( L_45 , L_46 , V_47 ) ;
return V_55 ;
}
if ( V_3 -> V_32 == FALSE ) {
F_17 ( L_45 , L_47 , V_47 ) ;
return V_58 ;
}
V_98 = ( T_11 * ) F_41 ( V_99 ) ;
for(; V_3 != NULL ; V_3 = V_3 -> V_100 ) {
if ( * V_60 > V_99 ) {
F_17 ( L_45 , L_48 , V_47 ) ;
return V_58 ;
}
memcpy ( V_98 , V_59 , * V_60 ) ;
if ( V_3 -> V_21 . V_22 == 1 ) {
F_17 ( L_45 , L_49 , V_47 ) ;
F_5 ( L_50 , V_3 -> V_21 . V_33 , 64 ) ;
F_5 ( L_51 , F_42 ( V_3 -> V_21 . V_33 ) , 16 ) ;
V_97 = F_43 ( V_98 + V_43 , * V_60 - V_43 , V_98 + V_101 , F_42 ( V_3 -> V_21 . V_33 ) ) ;
if ( V_97 ) {
F_17 ( L_45 , L_52 , V_47 ) ;
continue;
}
F_17 ( L_45 , L_53 , V_47 ) ;
* V_60 -= 12 ;
break;
} else {
F_17 ( L_45 , L_54 , V_47 ) ;
V_97 = F_44 ( V_98 , V_38 , ( INT ) * V_60 , F_42 ( V_3 -> V_21 . V_33 ) ) ;
if ( V_97 )
continue;
F_17 ( L_45 , L_55 , V_47 ) ;
* V_60 -= 8 ;
break;
}
}
if( V_3 == NULL )
return V_97 ;
if ( * V_60 > V_99 || * V_60 < 8 ) {
F_17 ( L_45 , L_48 , V_47 ) ;
return V_58 ;
}
memcpy ( V_59 , V_98 , * V_60 ) ;
V_59 [ 1 ] &= 0xBF ;
V_43 = V_38 ;
* V_60 -= 8 ;
memmove ( V_59 + V_43 , V_59 + V_43 + 8 , * V_60 - V_43 ) ;
if ( V_31 != NULL ) {
memcpy ( V_31 , V_3 -> V_31 , sizeof( T_6 ) ) ;
if ( V_3 -> V_21 . V_22 == V_12 )
V_31 -> V_77 = V_102 ;
else if ( V_3 -> V_21 . V_22 == V_14 )
V_31 -> V_77 = V_103 ;
}
return V_71 ;
}
static INT
F_30 (
T_8 V_34 ,
T_11 * V_59 ,
T_10 V_38 ,
T_10 * V_60 ,
T_12 V_31 ,
V_96 * V_3 ,
INT V_43 )
{
T_11 V_104 [ V_105 + V_106 ] ;
T_13 V_107 ;
INT V_97 = 1 ;
INT V_25 ;
T_6 * V_108 ;
T_14 V_109 = FALSE ;
T_11 * V_98 ;
T_10 V_99 = * V_60 ;
V_98 = ( T_11 * ) F_41 ( V_99 ) ;
if ( V_3 -> V_31 != NULL )
V_109 = TRUE ;
for ( V_25 = 0 ; V_25 < ( INT ) V_34 -> V_73 ; V_25 ++ ) {
if ( ! V_109 ) {
V_108 = & V_34 -> V_72 [ V_25 ] ;
} else {
if ( V_3 -> V_31 != NULL && V_3 -> V_31 -> V_77 == V_88 ) {
F_17 ( L_56 , L_57 , V_47 ) ;
V_108 = V_3 -> V_31 ;
} else {
F_17 ( L_56 , L_58 , V_47 ) ;
V_108 = & V_34 -> V_72 [ V_25 ] ;
}
}
if ( V_108 -> V_77 == V_88 )
{
F_17 ( L_56 , L_59 , V_47 ) ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
memcpy ( V_98 , V_59 , * V_60 ) ;
memcpy ( V_104 , V_98 + V_38 , V_106 ) ;
V_107 = V_108 -> V_84 . V_110 . V_111 ;
memcpy ( V_104 + V_106 , V_108 -> V_84 . V_110 . V_112 , V_107 ) ;
V_97 = F_45 ( V_104 ,
V_107 + V_106 ,
V_98 + ( V_38 + V_106 + V_113 ) ,
* V_60 - ( V_38 + V_106 + V_113 + V_114 ) ) ;
if ( V_97 == V_71 )
memcpy ( V_59 , V_98 , * V_60 ) ;
}
if ( ! V_97 && V_108 -> V_77 == V_88 ) {
V_3 -> V_31 = V_108 ;
if ( V_31 != NULL ) {
memcpy ( V_31 , & V_3 -> V_31 , sizeof( T_6 ) ) ;
V_31 -> V_77 = V_88 ;
}
break;
} else {
if ( V_109 == TRUE ) {
V_109 = FALSE ;
V_25 -- ;
}
}
}
if ( V_97 )
return V_97 ;
F_17 ( L_56 , L_60 , V_47 ) ;
* V_60 -= 4 ;
if ( * V_60 < 4 ) {
F_17 ( L_56 , L_61 , V_47 ) ;
return V_58 ;
}
V_59 [ 1 ] &= 0xBF ;
V_43 = V_38 ;
* V_60 -= 4 ;
memcpy ( V_59 + V_43 , V_59 + V_43 + V_106 + V_113 , * V_60 - V_43 ) ;
return V_71 ;
}
static INT
F_28 (
T_8 V_34 ,
const T_11 * V_37 ,
V_96 * V_3 ,
T_12 V_31 ,
INT V_43 )
{
T_6 * V_108 , * V_115 , V_116 ;
V_96 * V_117 ;
INT V_25 ;
INT V_97 = 1 ;
T_11 V_109 = FALSE ;
T_11 V_118 [ V_119 ] ;
T_15 V_120 ;
if ( V_3 -> V_31 != NULL )
V_109 = TRUE ;
if ( F_18 ( V_37 [ V_43 + 1 ] ) != 1 ) {
F_17 ( L_62 , L_63 , V_54 ) ;
return V_48 ;
}
if( V_3 -> V_121 == 4 ) {
V_117 = ( V_96 * ) F_46 ( sizeof( V_96 ) ) ;
memcpy ( V_117 , V_3 , sizeof( V_96 ) ) ;
V_3 -> V_100 = V_117 ;
}
F_17 ( L_62 , L_64 , V_54 ) ;
if ( F_47 ( V_37 [ V_43 + 1 ] ) == 0 &&
F_19 ( V_37 [ V_43 + 1 ] ) == 1 &&
F_20 ( V_37 [ V_43 ] ) == 0 )
{
F_17 ( L_62 , L_65 , V_47 ) ;
memcpy ( V_3 -> V_21 . V_122 , V_37 + V_43 + 12 , 32 ) ;
V_3 -> V_21 . V_22 = F_2 ( V_37 [ V_43 + 1 ] ) ;
V_3 -> V_121 = 1 ;
return V_123 ;
}
if ( F_47 ( V_37 [ V_43 + 1 ] ) == 0 &&
F_19 ( V_37 [ V_43 + 1 ] ) == 0 &&
F_20 ( V_37 [ V_43 ] ) == 1 )
{
if ( F_21 ( V_37 [ V_43 ] ) == 0 ) {
if ( V_37 [ V_43 + 92 ] != 0 || V_37 [ V_43 + 93 ] != 0 ) {
F_17 ( L_62 , L_66 , V_47 ) ;
for ( V_25 = 0 ; V_25 < ( INT ) V_34 -> V_73 || V_109 ; V_25 ++ ) {
if ( ! V_109 ) {
F_17 ( L_62 , L_67 , V_47 ) ;
V_108 = & V_34 -> V_72 [ V_25 ] ;
} else {
if ( V_3 -> V_31 != NULL &&
( V_3 -> V_31 -> V_77 == V_78 ||
V_3 -> V_31 -> V_77 == V_124 ||
V_3 -> V_31 -> V_77 == V_87 ) ) {
F_17 ( L_62 , L_68 , V_47 ) ;
V_108 = V_3 -> V_31 ;
} else {
F_17 ( L_62 , L_69 , V_47 ) ;
V_108 = & V_34 -> V_72 [ V_25 ] ;
}
}
if ( V_108 -> V_77 == V_78 ||
V_108 -> V_77 == V_124 ||
V_108 -> V_77 == V_87 )
{
if ( V_108 -> V_77 == V_78 && V_108 -> V_80 . V_83 == 0 && V_34 -> V_91 > 0 && V_34 -> V_91 <= V_125 ) {
memcpy ( & V_116 , V_108 , sizeof( V_116 ) ) ;
memcpy ( & V_116 . V_80 . V_82 , V_34 -> V_90 , V_34 -> V_91 ) ;
V_116 . V_80 . V_83 = V_34 -> V_91 ;
F_36 ( V_116 . V_80 . V_81 , V_116 . V_80 . V_82 ,
V_116 . V_80 . V_83 , V_116 . V_84 . V_85 . V_86 ) ;
V_115 = & V_116 ;
} else {
V_115 = V_108 ;
}
F_48 ( V_3 ,
V_115 -> V_84 . V_85 . V_126 ,
V_37 + V_43 + 12 ,
512 ,
V_3 -> V_21 . V_33 ) ;
V_120 = F_3 ( V_37 + V_43 - 3 ) + 4 ;
memcpy ( V_118 , & V_37 [ V_43 - 5 ] , ( V_120 < V_119 ? V_120 : V_119 ) ) ;
V_97 = F_49 ( V_118 ,
V_120 ,
V_3 -> V_21 . V_33 ,
F_2 ( V_37 [ V_43 + 1 ] ) ) ;
}
if ( ! V_97 &&
( V_108 -> V_77 == V_78 ||
V_108 -> V_77 == V_124 ||
V_108 -> V_77 == V_87 ) )
{
V_3 -> V_31 = V_108 ;
if ( V_31 != NULL ) {
memcpy ( V_31 , & V_108 , sizeof( T_6 ) ) ;
if ( F_2 ( V_37 [ V_43 + 1 ] ) == V_12 )
V_31 -> V_77 = V_102 ;
else if ( F_2 ( V_37 [ V_43 + 1 ] ) == V_14 )
V_31 -> V_77 = V_103 ;
}
break;
} else {
if ( V_109 == TRUE ) {
V_109 = FALSE ;
V_25 -- ;
}
}
}
if ( V_97 ) {
F_17 ( L_62 , L_70 , V_47 ) ;
return V_48 ;
}
V_3 -> V_121 = 2 ;
return V_123 ;
} else {
F_17 ( L_62 , L_71 , V_47 ) ;
V_3 -> V_121 = 4 ;
V_3 -> V_32 = TRUE ;
return V_123 ;
}
} else {
F_17 ( L_62 , L_72 , V_47 ) ;
V_3 -> V_121 = 4 ;
V_3 -> V_32 = TRUE ;
return V_123 ;
}
}
if ( F_19 ( V_37 [ V_43 + 1 ] ) == 1 &&
F_20 ( V_37 [ V_43 ] ) == 1 )
{
const T_1 * V_1 ;
F_17 ( L_62 , L_73 , V_47 ) ;
V_1 = ( const T_1 * ) ( & ( V_37 [ V_43 - 1 ] ) ) ;
if ( V_1 -> type == V_49 ) {
T_3 V_127 ;
T_9 V_35 ;
memcpy ( V_35 . V_56 , V_57 , V_53 ) ;
memcpy ( V_35 . V_52 , V_3 -> V_128 . V_52 , V_53 ) ;
V_127 = F_11 ( V_34 , & V_35 ) ;
if ( V_127 == NULL ) {
return V_58 ;
}
F_1 ( V_1 , V_3 -> V_21 . V_33 + 16 , V_127 , FALSE ) ;
}
return V_123 ;
}
return V_58 ;
}
static INT
F_49 (
T_11 * V_118 ,
T_15 V_120 ,
T_11 V_129 [ V_130 ] ,
T_15 V_22 )
{
T_11 V_131 [ V_132 ] ;
T_11 V_133 [ 20 ] ;
memcpy ( V_131 , V_118 + V_134 + 4 , V_132 ) ;
memset ( V_118 + V_134 + 4 , 0 , V_132 ) ;
if ( V_22 == V_12 ) {
F_50 ( V_118 , V_120 , V_129 , V_130 , V_133 ) ;
} else if ( V_22 == V_14 ) {
F_51 ( V_129 , V_130 , V_118 , V_120 , V_133 ) ;
} else
return V_58 ;
return memcmp ( V_131 , V_133 , V_132 ) ;
}
static INT
F_35 (
T_12 V_31 )
{
T_13 V_135 ;
T_11 V_136 = TRUE ;
F_16 ( L_74 ) ;
if ( V_31 == NULL ) {
F_17 ( L_74 , L_75 , V_54 ) ;
F_16 ( L_74 ) ;
return FALSE ;
}
switch ( V_31 -> V_77 ) {
case V_88 :
V_135 = V_31 -> V_84 . V_110 . V_111 ;
if ( V_135 < V_137 || V_135 > V_105 ) {
F_17 ( L_74 , L_76 , V_54 ) ;
V_136 = FALSE ;
}
break;
case V_138 :
V_31 -> V_84 . V_110 . V_111 = V_139 ;
V_31 -> V_77 = V_88 ;
break;
case V_140 :
V_31 -> V_84 . V_110 . V_111 = V_141 ;
V_31 -> V_77 = V_88 ;
break;
case V_78 :
V_135 = strlen ( V_31 -> V_80 . V_81 ) ;
if ( V_135 < V_142 || V_135 > V_143 ) {
F_17 ( L_74 , L_77 , V_54 ) ;
V_136 = FALSE ;
}
V_135 = V_31 -> V_80 . V_83 ;
if ( V_135 > V_125 ) {
F_17 ( L_74 , L_78 , V_54 ) ;
V_136 = FALSE ;
}
break;
case V_124 :
break;
case V_87 :
break;
default:
V_136 = FALSE ;
}
F_24 ( L_74 ) ;
return V_136 ;
}
static INT
F_12 (
T_8 V_34 ,
T_9 * V_35 )
{
INT V_36 ;
if ( V_34 -> V_36 != - 1 ) {
for ( V_36 = V_34 -> V_36 ; V_36 >= 0 ; V_36 -- ) {
if ( V_34 -> V_3 [ V_36 ] . V_144 ) {
if ( memcmp ( V_35 , & ( V_34 -> V_3 [ V_36 ] . V_128 ) , sizeof( T_9 ) ) == 0 ) {
V_34 -> V_94 = V_36 ;
return V_36 ;
}
}
}
}
return - 1 ;
}
static INT
F_13 (
T_8 V_34 ,
T_9 * V_35 )
{
INT V_145 ;
if ( V_34 -> V_3 [ V_34 -> V_93 ] . V_144 ) {
for ( V_145 = V_34 -> V_93 ; V_145 < V_95 ; V_145 ++ )
if ( ! V_34 -> V_3 [ V_145 ] . V_144 )
break;
if ( V_145 >= V_95 ) {
return - 1 ;
}
V_34 -> V_93 = V_145 ;
}
V_34 -> V_94 = V_34 -> V_93 ;
memset ( V_34 -> V_3 + V_34 -> V_94 , 0 , sizeof( V_96 ) ) ;
V_34 -> V_3 [ V_34 -> V_94 ] . V_144 = 1 ;
memcpy ( & ( V_34 -> V_3 [ V_34 -> V_94 ] . V_128 ) , V_35 , sizeof( T_9 ) ) ;
V_34 -> V_93 ++ ;
if ( V_34 -> V_94 > V_34 -> V_36 )
V_34 -> V_36 = V_34 -> V_94 ;
return V_34 -> V_94 ;
}
static const T_11 *
F_23 (
const V_51 * V_146 )
{
switch( F_52 ( V_146 -> V_147 [ 1 ] ) ) {
case 0 :
case 1 :
return V_146 -> V_148 ;
case 2 :
return V_146 -> V_149 ;
case 3 :
if ( memcmp ( V_146 -> V_149 , V_146 -> V_148 , V_53 ) < 0 )
return V_146 -> V_149 ;
else
return V_146 -> V_148 ;
default:
return NULL ;
}
}
static const T_11 *
F_22 (
const V_51 * V_146 )
{
switch( F_52 ( V_146 -> V_147 [ 1 ] ) ) {
case 0 :
return V_146 -> V_150 ;
case 1 :
return V_146 -> V_149 ;
case 2 :
return V_146 -> V_148 ;
case 3 :
if ( memcmp ( V_146 -> V_149 , V_146 -> V_148 , V_53 ) > 0 )
return V_146 -> V_149 ;
else
return V_146 -> V_148 ;
default:
return NULL ;
}
}
static void
F_48 (
V_96 * V_3 ,
const T_11 V_151 [ 32 ] ,
const T_11 V_152 [ 32 ] ,
const INT V_153 ,
T_11 * V_33 )
{
T_14 V_74 ;
T_11 V_154 [ 100 ] ;
INT V_43 = sizeof( L_79 ) ;
memset ( V_154 , 0 , 100 ) ;
memcpy ( V_154 , L_79 , V_43 ) ;
if ( memcmp ( V_3 -> V_128 . V_56 , V_3 -> V_128 . V_52 , V_53 ) < 0 )
{
memcpy ( V_154 + V_43 , V_3 -> V_128 . V_56 , V_53 ) ;
memcpy ( V_154 + V_43 + V_53 , V_3 -> V_128 . V_52 , V_53 ) ;
}
else
{
memcpy ( V_154 + V_43 , V_3 -> V_128 . V_52 , V_53 ) ;
memcpy ( V_154 + V_43 + V_53 , V_3 -> V_128 . V_56 , V_53 ) ;
}
V_43 += V_53 * 2 ;
if( memcmp ( V_152 , V_3 -> V_21 . V_122 , 32 ) < 0 )
{
memcpy ( V_154 + V_43 , V_152 , 32 ) ;
memcpy ( V_154 + V_43 + 32 , V_3 -> V_21 . V_122 , 32 ) ;
}
else
{
memcpy ( V_154 + V_43 , V_3 -> V_21 . V_122 , 32 ) ;
memcpy ( V_154 + V_43 + 32 , V_152 , 32 ) ;
}
V_43 += 32 * 2 ;
for( V_74 = 0 ; V_74 < ( V_153 + 159 ) / 160 ; V_74 ++ )
{
V_154 [ V_43 ] = V_74 ;
F_51 ( V_151 , 32 , V_154 , 100 , V_33 + V_74 * 20 ) ;
}
}
static INT
F_53 (
const T_2 * V_155 ,
const T_10 V_156 ,
const CHAR * V_157 ,
const T_13 V_158 ,
const INT V_159 ,
const INT V_160 ,
T_11 * V_161 )
{
T_11 V_162 [ 64 ] , V_163 [ 64 ] ;
INT V_74 , V_89 ;
if ( V_158 + 4 > 36 )
return V_58 ;
memset ( V_162 , 0 , 64 ) ;
memset ( V_163 , 0 , 64 ) ;
memcpy ( V_162 , V_157 , V_158 ) ;
V_162 [ V_158 ] = ( T_11 ) ( ( V_160 >> 24 ) & 0xff ) ;
V_162 [ V_158 + 1 ] = ( T_11 ) ( ( V_160 >> 16 ) & 0xff ) ;
V_162 [ V_158 + 2 ] = ( T_11 ) ( ( V_160 >> 8 ) & 0xff ) ;
V_162 [ V_158 + 3 ] = ( T_11 ) ( V_160 & 0xff ) ;
F_51 ( V_155 , V_156 , V_162 , ( V_164 ) V_158 + 4 , V_163 ) ;
memcpy ( V_161 , V_163 , V_165 ) ;
for ( V_74 = 1 ; V_74 < V_159 ; V_74 ++ ) {
F_51 ( V_155 , V_156 , V_163 , V_165 , V_162 ) ;
memcpy ( V_163 , V_162 , V_165 ) ;
for ( V_89 = 0 ; V_89 < V_165 ; V_89 ++ ) {
V_161 [ V_89 ] ^= V_162 [ V_89 ] ;
}
}
return V_71 ;
}
static INT
F_36 (
const CHAR * V_166 ,
const CHAR * V_157 ,
const T_13 V_158 ,
T_11 * V_161 )
{
T_11 V_167 [ V_168 ] ;
T_16 * V_169 = F_54 () ;
memset ( V_167 , 0 , V_168 ) ;
if ( ! F_55 ( V_166 , V_169 ) ) {
F_56 ( V_169 , TRUE ) ;
return 0 ;
}
F_53 ( V_169 -> V_37 , V_169 -> V_135 , V_157 , V_158 , 4096 , 1 , V_167 ) ;
F_53 ( V_169 -> V_37 , V_169 -> V_135 , V_157 , V_158 , 4096 , 2 , & V_167 [ V_165 ] ) ;
memcpy ( V_161 , V_167 , V_168 ) ;
F_56 ( V_169 , TRUE ) ;
return 0 ;
}
T_17 *
F_57 ( T_18 * V_170 , T_2 V_171 )
{
T_18 * V_31 ;
T_18 * V_157 ;
T_19 * V_172 = NULL ;
T_16 * V_173 = NULL , * V_174 ;
T_4 V_175 ;
T_18 * * V_176 ;
T_10 V_177 = 0 ;
T_17 * V_178 ;
if( V_170 == NULL )
return NULL ;
switch( V_171 )
{
case V_88 :
case V_138 :
case V_140 :
V_174 = F_54 () ;
V_175 = F_58 ( V_170 , V_174 , FALSE ) ;
if ( V_175 && V_174 -> V_135 > 0 ) {
V_178 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_178 -> type = V_88 ;
V_178 -> V_31 = F_59 ( F_60 ( V_174 -> V_37 , V_174 -> V_135 ) ) ;
F_61 ( V_178 -> V_31 ) ;
V_178 -> V_179 = V_174 -> V_135 * 8 ;
V_178 -> V_157 = NULL ;
F_56 ( V_174 , TRUE ) ;
return V_178 ;
}
F_56 ( V_174 , TRUE ) ;
return NULL ;
case V_78 :
V_176 = F_62 ( V_170 , L_80 , 0 ) ;
while( V_176 [ V_177 ] != NULL )
V_177 ++ ;
if( V_177 < 1 )
{
F_63 ( V_176 ) ;
return NULL ;
}
V_31 = F_64 ( V_176 [ 0 ] ) ;
V_157 = NULL ;
if( V_177 >= 2 )
{
V_157 = F_64 ( V_176 [ 1 ] ) ;
}
V_172 = F_59 ( V_31 ) ;
V_173 = NULL ;
if( ( ( V_172 -> V_135 ) > V_180 ) || ( ( V_172 -> V_135 ) < V_181 ) )
{
F_65 ( V_172 , TRUE ) ;
F_10 ( V_31 ) ;
F_10 ( V_157 ) ;
F_63 ( V_176 ) ;
return NULL ;
}
if( V_157 != NULL )
{
V_173 = F_54 () ;
if ( ! F_55 ( V_157 , V_173 ) ) {
F_65 ( V_172 , TRUE ) ;
F_56 ( V_173 , TRUE ) ;
F_10 ( V_31 ) ;
F_10 ( V_157 ) ;
F_63 ( V_176 ) ;
return NULL ;
}
if( V_173 -> V_135 > V_182 )
{
F_65 ( V_172 , TRUE ) ;
F_56 ( V_173 , TRUE ) ;
F_10 ( V_31 ) ;
F_10 ( V_157 ) ;
F_63 ( V_176 ) ;
return NULL ;
}
}
V_178 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_178 -> type = V_78 ;
V_178 -> V_31 = F_59 ( V_31 ) ;
V_178 -> V_179 = 256 ;
V_178 -> V_157 = F_66 ( V_173 ) ;
F_65 ( V_172 , TRUE ) ;
if ( V_173 != NULL )
F_56 ( V_173 , TRUE ) ;
F_10 ( V_31 ) ;
if( V_157 != NULL )
F_10 ( V_157 ) ;
F_63 ( V_176 ) ;
return V_178 ;
case V_124 :
V_174 = F_54 () ;
V_175 = F_58 ( V_170 , V_174 , FALSE ) ;
if( ! V_175 || ( ( V_174 -> V_135 ) != V_183 ) )
{
F_56 ( V_174 , TRUE ) ;
return NULL ;
}
V_178 = ( T_17 * ) F_8 ( sizeof( T_17 ) ) ;
V_178 -> type = V_124 ;
V_178 -> V_31 = F_59 ( V_170 ) ;
V_178 -> V_179 = ( T_10 ) V_178 -> V_31 -> V_135 * 4 ;
V_178 -> V_157 = NULL ;
F_56 ( V_174 , TRUE ) ;
return V_178 ;
}
return NULL ;
}
T_18 *
F_67 ( T_17 * V_178 )
{
T_18 * V_184 = NULL ;
if( V_178 == NULL || V_178 -> V_31 == NULL )
return NULL ;
switch( V_178 -> type ) {
case V_88 :
V_184 = F_64 ( V_178 -> V_31 -> V_185 ) ;
break;
case V_78 :
if( V_178 -> V_157 == NULL )
V_184 = F_64 ( V_178 -> V_31 -> V_185 ) ;
else
V_184 = F_68 ( L_81 ,
V_178 -> V_31 -> V_185 , F_69 ( V_178 -> V_157 , L_80 ) ) ;
break;
case V_87 :
V_184 = F_64 ( V_178 -> V_31 -> V_185 ) ;
break;
default:
return NULL ;
}
return V_184 ;
}
