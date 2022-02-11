static void
F_1 ( T_1 V_1 )
{
unsigned char V_2 [ 10000 ] ;
int V_3 ;
F_2 ( L_1 ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_4 , FALSE , V_2 , & V_3 ) ) {
T_2 * V_5 = ( T_2 * ) V_2 ;
while ( V_3 >= 4 ) {
printf ( L_2 , * V_5 , F_4 ( * V_5 , V_6 , L_3 ) ) ;
V_5 ++ ;
V_3 -= 4 ;
}
}
}
static T_3
F_5 ( T_1 V_1 , T_2 V_7 )
{
unsigned char V_2 [ 10000 ] ;
int V_3 ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_4 , FALSE , V_2 , & V_3 ) ) {
T_2 * V_5 = ( T_2 * ) V_2 ;
while ( V_3 >= 4 ) {
if( * V_5 == V_7 ) {
return TRUE ;
}
V_5 ++ ;
V_3 -= 4 ;
}
}
return FALSE ;
}
static void
F_6 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , const T_6 * V_5 , T_3 V_11 )
{
T_4 * V_12 ;
T_6 * V_13 ;
if( strlen ( V_5 ) != 0 ) {
V_13 = F_7 ( L_4 , V_10 ) ;
} else {
V_13 = F_8 ( V_10 ) ;
}
V_12 = F_9 ( V_13 ) ;
F_10 ( V_13 ) ;
F_11 ( F_12 ( V_12 ) , 0.0 , 0.5 ) ;
F_13 ( V_12 , V_11 ) ;
F_14 ( F_15 ( V_8 ) , V_12 , 0 , 1 , * V_9 , * V_9 + 1 , V_14 | V_15 , 0 , 0 , 0 ) ;
V_12 = F_9 ( V_5 ) ;
F_11 ( F_12 ( V_12 ) , 0.0 , 0.5 ) ;
F_13 ( V_12 , V_11 ) ;
F_14 ( F_15 ( V_8 ) , V_12 , 1 , 2 , * V_9 , * V_9 + 1 , V_14 | V_15 , 0 , 0 , 0 ) ;
* V_9 = * V_9 + 1 ;
}
static void
F_16 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , T_6 * V_5 , T_3 V_11 )
{
F_6 ( V_8 , V_9 , V_10 , V_5 , V_11 ) ;
}
static void
F_17 ( T_4 * V_8 , T_5 * V_9 , T_6 * V_10 , const T_6 * V_5 )
{
F_6 ( V_8 , V_9 , V_10 , V_5 , TRUE ) ;
}
static void
F_18 ( T_4 * V_16 , T_5 * V_9 , struct V_17 * V_18 ) {
struct V_17 V_19 [ 2 ] ;
V_19 [ 0 ] = * V_18 ;
F_19 ( V_19 -> V_3 <= V_20 ) ;
if( V_19 -> V_3 != 0 ) {
V_19 -> V_21 [ V_19 -> V_3 ] = '\0' ;
F_17 ( V_16 , V_9 , L_5 , V_19 -> V_21 ) ;
} else {
F_17 ( V_16 , V_9 , L_5 , L_6 ) ;
}
}
static T_7 *
F_20 ( unsigned char * V_2 , int V_3 ) {
int V_22 ;
T_7 * V_23 ;
float V_24 ;
int V_25 ;
V_23 = F_21 ( L_7 ) ;
if( V_3 != 0 ) {
V_22 = 0 ;
while( V_3 -- ) {
if( V_2 [ V_22 ] ) {
if( V_22 != 0 ) {
F_22 ( V_23 , L_8 ) ;
}
V_24 = ( ( float ) ( V_2 [ V_22 ] & 0x7F ) ) / 2 ;
V_25 = ( int ) V_24 ;
if( V_24 == ( float ) V_25 ) {
F_23 ( V_23 , L_9 , V_24 ) ;
} else {
F_23 ( V_23 , L_10 , V_24 ) ;
}
}
V_22 ++ ;
}
V_23 = F_22 ( V_23 , L_11 ) ;
} else {
V_23 = F_22 ( V_23 , L_12 ) ;
}
return V_23 ;
}
static void
F_24 ( unsigned char * V_26 , int V_27 ) {
int V_22 = 0 ;
while( V_27 ) {
F_2 ( L_13 , V_22 , * V_26 , * V_26 ,
isprint ( * V_26 ) ? * V_26 : '.' ) ;
V_22 ++ ;
V_26 ++ ;
V_27 -- ;
}
}
static void
F_25 ( T_4 * V_28 , struct V_29 * V_30 )
{
struct V_31 * V_32 ;
unsigned char V_33 [ 6 ] ;
const T_6 * V_34 ;
T_7 * V_23 ;
if( V_30 -> V_35 != 0 ) {
char * V_36 [] = { L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
T_4 * V_8 ;
T_3 V_37 ;
T_3 V_38 ;
T_3 V_39 ;
T_6 V_40 [ V_41 ] ;
T_6 V_42 [ V_41 ] ;
T_6 V_43 [ V_41 ] ;
T_6 V_44 [ V_41 ] ;
T_6 V_45 [ V_41 ] ;
T_6 V_46 [ V_41 ] ;
T_6 V_47 [ V_41 ] ;
T_6 V_48 [ V_41 ] ;
T_6 V_49 [ V_41 ] = L_7 ;
V_8 = F_26 ( 10 , V_36 ) ;
F_27 ( F_28 ( V_28 ) , V_8 , TRUE , TRUE , 0 ) ;
V_32 = & V_30 -> V_50 [ 0 ] ;
while( V_30 -> V_35 -- ) {
V_37 = FALSE ;
V_38 = FALSE ;
V_39 = FALSE ;
if( V_32 -> V_19 . V_3 > V_41 - 1 ) {
V_32 -> V_19 . V_3 = V_41 - 1 ;
}
memcpy ( V_40 , V_32 -> V_19 . V_21 , V_32 -> V_19 . V_3 ) ;
V_40 [ V_32 -> V_19 . V_3 ] = '\0' ;
memcpy ( V_33 , & V_32 -> V_33 , sizeof( V_33 ) ) ;
F_29 ( V_42 , V_41 , L_24 ,
V_33 [ 0 ] , V_33 [ 1 ] , V_33 [ 2 ] ,
V_33 [ 3 ] , V_33 [ 4 ] , V_33 [ 5 ] ) ;
V_34 = F_30 ( V_33 ) ;
if( V_34 != NULL ) {
F_31 ( V_43 , V_34 , V_41 ) ;
} else {
V_43 [ 0 ] = '\0' ;
}
V_23 = F_20 ( V_32 -> V_51 , V_52 ) ;
F_29 ( V_45 , V_41 , L_25 , V_32 -> V_53 ) ;
if( V_32 -> V_54 ) {
V_37 = TRUE ;
}
F_29 ( V_46 , sizeof( V_46 ) , L_26 ,
F_4 ( V_32 -> V_55 , V_56 , L_27 ) ) ;
F_29 ( V_47 , sizeof( V_47 ) , L_26 ,
F_4 ( V_32 -> V_57 , V_58 , L_27 ) ) ;
F_29 ( V_48 , sizeof( V_48 ) , L_26 ,
F_4 ( V_32 -> V_59 . V_60 , V_61 , L_28 ) ) ;
{
int V_27 = V_32 -> V_62 ;
unsigned char * V_63 = V_32 -> V_64 ;
unsigned char V_65 ;
unsigned V_66 ;
T_8 * V_67 ;
#ifdef F_32
const T_6 * V_34 ;
T_6 V_68 [ V_41 ] ;
#endif
V_67 = ( T_8 * ) V_63 ;
#if 0
UCHAR Timestamp[8];
USHORT BeaconInterval;
USHORT Capabilities;
} NDIS_802_11_FIXED_IEs, *PNDIS_802_11_FIXED_IEs;
#endif
V_63 += sizeof( T_8 ) ;
V_27 = V_32 -> V_62 - sizeof( T_8 ) ;
while( V_27 >= 2 ) {
V_65 = * V_63 ;
V_63 ++ ;
V_66 = * V_63 ;
V_63 ++ ;
V_27 -= 2 ;
#ifdef F_32
F_2 ( L_29 ,
F_4 ( V_65 , V_69 , L_30 ) , V_65 , V_66 ) ;
#endif
switch( V_65 ) {
case ( V_70 ) :
if( V_66 >= 6 )
F_29 ( V_49 , sizeof( V_49 ) , L_31 ,
V_63 [ 0 ] , V_63 [ 1 ] , V_63 [ 3 ] , V_63 [ 4 ] , V_63 [ 5 ] ) ;
break;
case ( V_71 ) :
V_39 = TRUE ;
break;
case ( V_72 ) :
V_38 = TRUE ;
#ifdef F_32
V_34 = F_30 ( V_63 ) ;
if( V_34 != NULL ) {
F_29 ( V_68 , V_41 , L_32 ,
* ( V_63 ) , * ( V_63 + 1 ) , * ( V_63 + 2 ) , V_34 , * ( V_63 + 3 ) ) ;
} else {
F_29 ( V_68 , V_41 , L_33 ,
* ( V_63 ) , * ( V_63 + 1 ) , * ( V_63 + 2 ) , * ( V_63 + 3 ) ) ;
}
F_2 ( L_26 , V_68 ) ;
V_63 += 4 ;
V_66 -= 4 ;
V_27 -= 4 ;
F_2 ( L_34 , V_65 ) ;
F_24 ( V_63 , V_66 ) ;
#endif
break;
case ( V_73 ) :
case ( V_74 ) :
case ( V_75 ) :
case ( V_76 ) :
case ( V_77 ) :
case ( V_78 ) :
break;
default:
F_2 ( L_35 , V_65 , V_66 ) ;
F_24 ( V_63 , V_66 ) ;
}
V_63 += V_66 ;
V_27 -= V_66 ;
}
}
if( V_37 ) {
if( V_39 ) {
F_29 ( V_44 , V_41 , L_36 ) ;
} else {
if( V_38 ) {
F_29 ( V_44 , V_41 , L_37 ) ;
} else {
F_29 ( V_44 , V_41 , L_38 ) ;
}
}
} else {
F_29 ( V_44 , V_41 , L_39 ) ;
}
F_33 ( V_8 ,
0 , V_40 ,
1 , V_42 ,
2 , V_43 ,
3 , V_44 ,
4 , V_45 ,
5 , V_46 ,
6 , V_47 ,
7 , V_48 ,
8 , V_23 -> V_79 ,
9 , V_49 ,
- 1 ) ;
F_34 ( V_23 , TRUE ) ;
V_32 = (struct V_31 * ) ( ( ( char * ) V_32 ) + V_32 -> V_3 ) ;
}
}
}
static int
F_35 ( T_4 * V_16 , T_4 * V_28 , T_5 * V_9 , T_1 V_1 ) {
T_9 V_80 ;
LONG V_53 = - 100 ;
unsigned int V_81 ;
unsigned char V_2 [ 100 ] ;
struct V_17 V_19 ;
int V_3 ;
struct V_29 * V_30 ;
struct V_82 * V_83 ;
T_6 V_68 [ V_41 ] ;
T_7 * V_23 ;
int V_84 = 0 ;
const T_6 * V_34 ;
F_17 ( V_16 , V_9 , L_40 , L_7 ) ;
V_3 = sizeof( struct V_17 ) ;
memset ( & V_19 , 0 , V_3 ) ;
if ( F_3 ( V_1 , V_85 , FALSE , ( char * ) & V_19 , & V_3 ) ) {
F_18 ( V_16 , V_9 , & V_19 ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_5 , L_12 ) ;
}
V_3 = sizeof( V_2 ) ;
memset ( V_2 , 0 , 6 ) ;
if ( F_3 ( V_1 , V_86 , FALSE , V_2 , & V_3 ) ) {
V_34 = F_30 ( V_2 ) ;
if( V_34 != NULL ) {
F_29 ( V_68 , V_41 , L_41 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ,
V_34 ) ;
} else {
F_29 ( V_68 , V_41 , L_24 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ) ;
}
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_42 , V_68 ) ;
if ( F_36 ( V_1 , V_87 , & V_81 ) ) {
F_17 ( V_16 , V_9 , L_43 ,
F_4 ( V_81 , V_56 , L_27 ) ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_43 , L_12 ) ;
}
if ( F_37 ( V_1 , V_88 , & V_81 ) ) {
F_17 ( V_16 , V_9 , L_44 ,
F_4 ( V_81 , V_58 , L_27 ) ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_44 , L_12 ) ;
}
if ( F_37 ( V_1 , V_89 , & V_81 ) ) {
F_17 ( V_16 , V_9 , L_45 ,
F_4 ( V_81 , V_90 , L_27 ) ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_45 , L_12 ) ;
}
if ( F_37 ( V_1 , V_91 , & V_81 ) ) {
F_17 ( V_16 , V_9 , L_46 ,
F_4 ( V_81 , V_92 , L_27 ) ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_46 , L_12 ) ;
}
if ( F_37 ( V_1 , V_93 , & V_80 ) ) {
F_29 ( V_68 , V_41 , L_47 , V_80 ) ;
F_17 ( V_16 , V_9 , L_48 , V_68 ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_48 , L_12 ) ;
}
if ( F_37 ( V_1 , V_94 , & V_53 ) ) {
#if 0
int i;
GList * scale_items = NULL;
GList * current;
GtkVUMeterScaleItem *item;
for (i = 0; i <= 100; i++) {
item = g_malloc(sizeof(GtkVUMeterScaleItem));
item->level = i;
item->large = !(i%5);
item->label = NULL;
switch(item->level) {
case 0:
item->label = "-100 ";
break;
case 20:
item->label = "-80 ";
break;
case 40:
item->label = "-60 ";
break;
case 60:
item->label = "-40 ";
break;
case 80:
item->label = "-20 ";
break;
case 100:
item->label = "0";
break;
default:
item->label = NULL;
}
scale_items = g_list_append(scale_items, item);
}
if(rssi < -100) {
rssi = -100;
}
g_snprintf(string_buff, DETAILS_STR_MAX, "%ld dBm", rssi);
add_meter_to_table(table, row, "RSSI (Received Signal Strength Indication)",
rssi+100 , string_buff, -100+100, 0+100, -80+100, scale_items);
current = scale_items;
while (current != NULL) {
g_free(current->data);
current = g_list_next(current);
}
g_list_free(scale_items);
entries++;
#endif
} else {
F_17 ( V_16 , V_9 , L_49 , L_12 ) ;
}
V_3 = sizeof( V_2 ) ;
if ( ! F_3 ( V_1 , V_95 , FALSE , V_2 , & V_3 ) ) {
V_3 = 0 ;
} else {
V_84 ++ ;
}
if ( V_3 != 0 && F_36 ( V_1 , V_96 , & V_81 ) ) {
#if 0
int max;
int yellow;
GList *rates_list;
GList * current;
rates_list = rates_vu_list(values, length, &max);
if(rssi == -100) {
uint_value = 0;
}
uint_value /= 10 * 1000;
g_snprintf(string_buff, DETAILS_STR_MAX, "%u MBits/s", uint_value);
if(max >= 54) {
yellow = 2;
} else {
yellow = 1;
}
add_meter_to_table(table, row, "Link Speed",
uint_value, string_buff, 0, max, yellow, rates_list);
current = rates_list;
while (current != NULL) {
g_free(current->data);
current = g_list_next(current);
}
g_list_free(rates_list);
#endif
}
V_23 = F_20 ( V_2 , V_3 ) ;
F_17 ( V_16 , V_9 , L_50 , V_23 -> V_79 ) ;
F_34 ( V_23 , TRUE ) ;
V_3 = sizeof( V_2 ) ;
if ( ! F_3 ( V_1 , V_97 , FALSE , V_2 , & V_3 ) ) {
V_3 = 0 ;
} else {
V_84 ++ ;
}
V_23 = F_20 ( V_2 , V_3 ) ;
F_17 ( V_16 , V_9 , L_51 , V_23 -> V_79 ) ;
F_34 ( V_23 , TRUE ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_98 , FALSE , ( char * ) V_2 , & V_3 ) ) {
V_83 = (struct V_82 * ) V_2 ;
F_17 ( V_16 , V_9 , L_52 ,
F_4 ( V_83 -> V_60 , V_99 , L_28 ) ) ;
V_84 ++ ;
} else {
F_17 ( V_16 , V_9 , L_52 , L_12 ) ;
}
V_3 = sizeof( V_81 ) ;
if ( F_3 ( V_1 , V_100 , TRUE , ( char * ) & V_81 , & V_3 ) ) {
#if 0
g_warning("BSSID list scan done");
} else {
g_warning("BSSID list scan failed");
#endif
}
V_3 = sizeof( T_9 ) + sizeof( struct V_31 ) * 16 ;
V_30 = F_38 ( V_3 ) ;
memset ( V_30 , 0 , V_3 ) ;
if ( F_3 ( V_1 , V_101 , FALSE , ( char * ) V_30 , & V_3 ) ) {
F_17 ( V_16 , V_9 , L_7 , L_7 ) ;
F_17 ( V_16 , V_9 , L_53 , L_7 ) ;
F_25 ( V_28 , V_30 ) ;
V_84 += V_30 -> V_35 ;
} else {
F_17 ( V_16 , V_9 , L_53 , L_12 ) ;
}
F_10 ( V_30 ) ;
return V_84 ;
}
static int
F_39 ( T_4 * V_16 , T_4 * V_28 , T_5 * V_9 , T_1 V_1 ) {
unsigned int V_81 ;
unsigned char V_2 [ 100 ] ;
int V_3 ;
T_6 V_68 [ V_41 ] ;
const T_6 * V_34 ;
int V_84 = 0 ;
F_17 ( V_16 , V_9 , L_54 , L_7 ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_102 , FALSE , V_2 , & V_3 ) ) {
V_34 = F_30 ( V_2 ) ;
if( V_34 != NULL ) {
F_29 ( V_68 , V_41 , L_41 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ,
V_34 ) ;
} else {
F_29 ( V_68 , V_41 , L_24 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ) ;
}
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_55 , V_68 ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_103 , FALSE , V_2 , & V_3 ) ) {
V_34 = F_30 ( V_2 ) ;
if( V_34 != NULL ) {
F_29 ( V_68 , V_41 , L_41 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ,
V_34 ) ;
} else {
F_29 ( V_68 , V_41 , L_24 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] ,
V_2 [ 3 ] , V_2 [ 4 ] , V_2 [ 5 ] ) ;
}
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_56 , V_68 ) ;
F_17 ( V_16 , V_9 , L_7 , L_7 ) ;
F_17 ( V_16 , V_9 , L_57 , L_7 ) ;
if ( F_36 ( V_1 , V_104 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_59 , V_68 ) ;
if ( F_36 ( V_1 , V_105 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_60 , V_68 ) ;
if ( F_36 ( V_1 , V_106 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_61 , V_68 ) ;
if ( F_36 ( V_1 , V_107 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_62 , V_68 ) ;
if ( F_36 ( V_1 , V_108 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_63 , V_68 ) ;
if ( F_36 ( V_1 , V_109 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_64 , V_68 ) ;
if ( F_36 ( V_1 , V_110 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_65 , V_68 ) ;
if ( F_36 ( V_1 , V_111 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_66 , V_68 ) ;
if ( F_36 ( V_1 , V_112 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_67 , V_68 ) ;
if ( F_36 ( V_1 , V_113 , & V_81 ) ) {
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_68 , V_68 ) ;
return V_84 ;
}
static int
F_40 ( T_4 * V_16 , T_4 * V_28 , T_5 * V_9 , T_1 V_1 ) {
T_10 * V_114 ;
unsigned char V_2 [ 10000 ] ;
int V_3 ;
T_6 V_68 [ V_41 ] ;
int V_84 = 0 ;
int V_115 = 0 ;
int V_116 = 0 ;
int V_117 = 0 ;
V_114 = ( T_10 * ) V_2 ;
V_114 -> V_118 = V_119 ;
V_114 -> V_120 = sizeof( T_10 ) ;
V_114 -> V_121 = 0 ;
V_114 -> V_122 = 0 ;
V_114 -> V_123 . V_124 = V_125 ;
V_114 -> V_123 . V_126 . V_127 = 1 ;
V_114 -> V_123 . V_126 . V_121 = 0 ;
V_114 -> V_123 . V_128 = 14 ; ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_129 , FALSE , V_2 , & V_3 ) ) {
T_11 * V_130 ;
unsigned char * V_131 = V_2 + V_114 -> V_122 ;
V_3 -= V_114 -> V_122 ;
do {
V_130 = ( T_11 * ) V_131 ;
switch( V_130 -> V_132 ) {
case V_133 :
{
T_12 * V_134 = ( T_12 * ) ( V_130 -> V_135 ) ;
V_84 ++ ;
V_115 ++ ;
F_17 ( V_16 , V_9 , L_69 , L_7 ) ;
F_29 ( V_68 , V_41 , L_7 ) ;
F_17 ( V_16 , V_9 , L_70 , L_7 ) ;
F_29 ( V_68 , V_41 , L_71 ,
V_134 -> V_136 . V_137 ? L_72 : L_73 ,
V_134 -> V_136 . V_138 ? L_72 : L_73 ,
V_134 -> V_136 . V_139 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_74 , V_68 ) ;
F_29 ( V_68 , V_41 , L_75 ,
V_134 -> V_136 . V_140 ? L_72 : L_73 ,
V_134 -> V_136 . V_141 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_76 , V_68 ) ;
F_29 ( V_68 , V_41 , L_7 ) ;
F_17 ( V_16 , V_9 , L_77 , L_7 ) ;
F_29 ( V_68 , V_41 , L_71 ,
V_134 -> V_142 . V_137 ? L_72 : L_73 ,
V_134 -> V_142 . V_138 ? L_72 : L_73 ,
V_134 -> V_142 . V_139 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_78 , V_68 ) ;
F_29 ( V_68 , V_41 , L_75 ,
V_134 -> V_142 . V_140 ? L_72 : L_73 ,
V_134 -> V_142 . V_141 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_76 , V_68 ) ;
F_29 ( V_68 , V_41 , L_7 ) ;
F_17 ( V_16 , V_9 , L_79 , L_7 ) ;
F_29 ( V_68 , V_41 , L_80 ,
V_134 -> V_143 . V_137 ? L_72 : L_73 ,
V_134 -> V_143 . V_138 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_74 , V_68 ) ;
F_29 ( V_68 , V_41 , L_75 ,
V_134 -> V_143 . V_140 ? L_72 : L_73 ,
V_134 -> V_143 . V_141 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_76 , V_68 ) ;
F_29 ( V_68 , V_41 , L_7 ) ;
F_17 ( V_16 , V_9 , L_81 , L_7 ) ;
F_29 ( V_68 , V_41 , L_80 ,
V_134 -> V_144 . V_137 ? L_72 : L_73 ,
V_134 -> V_144 . V_138 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_78 , V_68 ) ;
F_29 ( V_68 , V_41 , L_75 ,
V_134 -> V_144 . V_140 ? L_72 : L_73 ,
V_134 -> V_144 . V_141 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_76 , V_68 ) ;
}
break;
case V_145 :
V_84 ++ ;
V_116 ++ ;
F_17 ( V_16 , V_9 , L_82 , L_7 ) ;
F_29 ( V_68 , V_41 , L_83 ) ;
F_17 ( V_16 , V_9 , L_84 , V_68 ) ;
break;
case V_146 :
{
T_13 * V_147 = ( T_13 * ) ( V_130 -> V_135 ) ;
V_84 ++ ;
V_117 ++ ;
F_17 ( V_16 , V_9 , L_85 , L_7 ) ;
if( V_147 -> V_118 == 1 ) {
F_29 ( V_68 , V_41 , L_86 , V_147 -> V_148 ) ;
F_17 ( V_16 , V_9 , L_87 , V_68 ) ;
F_29 ( V_68 , V_41 , L_86 , V_147 -> V_149 ) ;
F_17 ( V_16 , V_9 , L_88 , V_68 ) ;
F_29 ( V_68 , V_41 , L_26 , V_147 -> V_150 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_89 , V_68 ) ;
F_29 ( V_68 , V_41 , L_26 , V_147 -> V_151 ? L_72 : L_73 ) ;
F_17 ( V_16 , V_9 , L_90 , V_68 ) ;
} else {
F_29 ( V_68 , V_41 , L_91 , V_147 -> V_118 ) ;
F_17 ( V_16 , V_9 , L_92 , V_68 ) ;
}
}
break;
default:
F_29 ( V_68 , V_41 , L_93 , V_130 -> V_132 ) ;
F_17 ( V_16 , V_9 , L_84 , V_68 ) ;
}
F_17 ( V_16 , V_9 , L_7 , L_7 ) ;
V_131 += V_130 -> V_152 ;
V_3 -= V_130 -> V_152 ;
} while( V_130 -> V_152 != 0 );
}
if( V_115 == 0 ) {
F_17 ( V_16 , V_9 , L_69 , L_7 ) ;
F_17 ( V_16 , V_9 , L_94 , L_12 ) ;
}
if( V_116 == 0 ) {
F_17 ( V_16 , V_9 , L_95 , L_7 ) ;
F_17 ( V_16 , V_9 , L_94 , L_12 ) ;
}
if( V_117 == 0 ) {
F_17 ( V_16 , V_9 , L_96 , L_7 ) ;
F_17 ( V_16 , V_9 , L_94 , L_12 ) ;
}
return V_84 ;
}
static int
F_41 ( T_4 * V_16 , T_4 * V_28 , T_5 * V_9 , T_1 V_1 , T_6 * V_153 ) {
T_6 V_68 [ V_41 ] ;
const T_6 * V_34 ;
unsigned int V_81 ;
unsigned int V_154 [ 50 ] ;
int V_155 ;
unsigned int V_156 ;
int V_22 ;
unsigned char V_2 [ 100 ] ;
int V_3 ;
unsigned short V_157 ;
int V_84 = 0 ;
F_17 ( V_16 , V_9 , L_54 , L_7 ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_158 , FALSE , V_2 , & V_3 ) ) {
F_29 ( V_68 , V_41 , L_26 , V_2 ) ;
V_84 ++ ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_97 , V_68 ) ;
F_17 ( V_16 , V_9 , L_98 , V_153 ) ;
if ( F_36 ( V_1 , V_159 , & V_81 ) ) {
V_84 ++ ;
if( V_81 == 0 ) {
F_17 ( V_16 , V_9 , L_99 , L_100 ) ;
} else {
F_17 ( V_16 , V_9 , L_99 , L_101 ) ;
}
} else {
F_17 ( V_16 , V_9 , L_99 , L_12 ) ;
}
if ( F_36 ( V_1 , V_96 , & V_81 ) ) {
V_84 ++ ;
V_81 *= 100 ;
if( V_81 >= 1000 * 1000 ) {
F_29 ( V_68 , V_41 , L_102 , V_81 / 1000 / 1000 ) ;
} else {
if( V_81 >= 1000 ) {
F_29 ( V_68 , V_41 , L_103 , V_81 / 1000 ) ;
} else {
F_29 ( V_68 , V_41 , L_104 , V_81 ) ;
}
}
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_105 , V_68 ) ;
V_155 = sizeof( V_154 ) ;
if ( F_3 ( V_1 , V_160 , FALSE , ( char * ) V_154 , & V_155 ) ) {
V_84 ++ ;
V_155 /= sizeof( unsigned int ) ;
V_22 = 0 ;
while( V_155 -- ) {
F_17 ( V_16 , V_9 , L_106 ,
F_4 ( V_154 [ V_22 ] , V_161 , L_27 ) ) ;
V_22 ++ ;
}
} else {
F_17 ( V_16 , V_9 , L_106 , L_12 ) ;
}
V_155 = sizeof( V_154 ) ;
if ( F_3 ( V_1 , V_162 , FALSE , ( char * ) V_154 , & V_155 ) ) {
V_84 ++ ;
V_155 /= sizeof( unsigned int ) ;
V_22 = 0 ;
while( V_155 -- ) {
F_17 ( V_16 , V_9 , L_107 ,
F_4 ( V_154 [ V_22 ] , V_161 , L_27 ) ) ;
V_22 ++ ;
}
} else {
F_17 ( V_16 , V_9 , L_107 , L_12 ) ;
}
if ( F_36 ( V_1 , V_163 , & V_156 ) ) {
V_84 ++ ;
F_17 ( V_16 , V_9 , L_108 ,
F_4 ( V_156 , V_164 , L_27 ) ) ;
} else {
F_17 ( V_16 , V_9 , L_108 , L_12 ) ;
}
V_3 = sizeof( V_157 ) ;
if ( F_3 ( V_1 , V_165 , FALSE , ( char * ) & V_157 , & V_3 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_109 , V_157 / 0x100 , V_157 % 0x100 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_110 , V_68 ) ;
V_3 = sizeof( V_81 ) ;
if ( F_3 ( V_1 , V_166 , FALSE , ( char * ) & V_81 , & V_3 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_111 ,
( V_81 / 0x10000 ) % 0x10000 ,
V_81 % 0x10000 ,
( V_81 / 0x10000 ) % 0x10000 ,
V_81 % 0x10000 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_112 , V_68 ) ;
V_3 = sizeof( V_2 ) ;
if ( F_3 ( V_1 , V_167 , FALSE , V_2 , & V_3 ) ) {
V_84 ++ ;
V_34 = F_30 ( V_2 ) ;
if( V_34 != NULL ) {
F_29 ( V_68 , V_41 , L_113 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_34 , V_2 [ 3 ] ) ;
} else {
F_29 ( V_68 , V_41 , L_114 ,
V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] ) ;
}
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_115 , V_68 ) ;
if ( F_36 ( V_1 , V_168 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 ,
L_116 ,
( V_81 & V_169 ) ? L_117 : L_118 ,
( V_81 & V_170 ) ? L_117 : L_118 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_119 , V_68 ) ;
if ( F_36 ( V_1 , V_171 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_86 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_120 , V_68 ) ;
#if 0
if (wpcap_packet_request_uint(adapter, OID_GEN_CURRENT_PACKET_FILTER, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packet filter", string_buff);
#endif
if ( F_36 ( V_1 , V_172 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_121 , V_68 ) ;
if ( F_36 ( V_1 , V_173 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_122 , V_68 ) ;
if ( F_36 ( V_1 , V_174 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_123 , V_68 ) ;
if ( F_36 ( V_1 , V_175 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_124 , V_68 ) ;
if ( F_36 ( V_1 , V_176 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_125 , V_68 ) ;
return V_84 ;
}
static int
F_42 ( T_4 * V_16 , T_4 * V_28 , T_5 * V_9 , T_1 V_1 ) {
T_6 V_68 [ V_41 ] ;
unsigned int V_81 ;
int V_84 = 0 ;
F_17 ( V_16 , V_9 , L_57 , L_7 ) ;
if ( F_36 ( V_1 , V_177 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_126 , V_68 ) ;
if ( F_36 ( V_1 , V_178 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_127 , V_68 ) ;
if ( F_36 ( V_1 , V_179 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_128 , V_68 ) ;
if ( F_36 ( V_1 , V_180 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_129 , V_68 ) ;
if ( F_36 ( V_1 , V_181 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_130 , V_68 ) ;
if ( F_36 ( V_1 , V_182 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_131 , V_68 ) ;
if ( F_36 ( V_1 , V_183 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_132 , V_68 ) ;
if ( F_36 ( V_1 , V_184 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_133 , V_68 ) ;
if ( F_36 ( V_1 , V_185 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_134 , V_68 ) ;
if ( F_36 ( V_1 , V_186 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_135 , V_68 ) ;
if ( F_36 ( V_1 , V_187 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_136 , V_68 ) ;
if ( F_36 ( V_1 , V_188 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_137 , V_68 ) ;
if ( F_36 ( V_1 , V_189 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_138 , V_68 ) ;
if ( F_36 ( V_1 , V_190 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_139 , V_68 ) ;
if ( F_36 ( V_1 , V_191 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_140 , V_68 ) ;
if ( F_36 ( V_1 , V_192 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_141 , V_68 ) ;
if ( F_36 ( V_1 , V_193 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_142 , V_68 ) ;
if ( F_36 ( V_1 , V_194 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_143 , V_68 ) ;
if ( F_36 ( V_1 , V_195 , & V_81 ) ) {
V_84 ++ ;
F_29 ( V_68 , V_41 , L_58 , V_81 ) ;
} else {
F_29 ( V_68 , V_41 , L_12 ) ;
}
F_17 ( V_16 , V_9 , L_144 , V_68 ) ;
return V_84 ;
}
static T_4 *
F_43 ( T_4 * * V_16 )
{
T_4 * V_28 ;
V_28 = F_44 ( V_196 , 6 , FALSE ) ;
F_45 ( F_46 ( V_28 ) , 12 ) ;
* V_16 = F_47 ( 1 , 2 , FALSE ) ;
F_48 ( F_15 ( * V_16 ) , 6 ) ;
F_49 ( F_15 ( * V_16 ) , 3 ) ;
F_50 ( F_46 ( V_28 ) , * V_16 ) ;
return V_28 ;
}
static void
F_51 ( char * V_153 )
{
T_4 * V_197 ,
* V_28 , * V_198 , * V_199 , * V_200 ;
T_4 * V_201 , * V_202 , * V_203 , * V_204 , * V_205 ;
T_4 * V_206 ;
T_4 * V_16 , * V_207 , * V_12 ;
T_5 V_9 ;
T_1 V_1 ;
int V_84 ;
V_1 = F_52 ( V_153 ) ;
if( V_1 == NULL ) {
F_53 ( V_208 , V_209 ,
L_145
L_146 ,
F_54 () , V_153 , F_55 () ) ;
return;
}
V_197 = F_56 ( L_147 ) ;
F_57 ( F_58 ( V_197 ) , TRUE ) ;
V_28 = F_44 ( V_196 , 12 , FALSE ) ;
F_45 ( F_46 ( V_28 ) , 12 ) ;
F_50 ( F_46 ( V_197 ) , V_28 ) ;
V_207 = F_59 () ;
F_27 ( F_28 ( V_28 ) , V_207 , TRUE , TRUE , 0 ) ;
V_201 = F_43 ( & V_16 ) ;
V_206 = F_9 ( L_54 ) ;
F_60 ( F_61 ( V_207 ) , V_201 , V_206 ) ;
V_9 = 0 ;
V_84 = F_41 ( V_16 , V_201 , & V_9 , V_1 , V_153 ) ;
if( V_84 == 0 ) {
F_13 ( V_206 , FALSE ) ;
}
V_202 = F_43 ( & V_16 ) ;
V_206 = F_9 ( L_57 ) ;
F_60 ( F_61 ( V_207 ) , V_202 , V_206 ) ;
V_9 = 0 ;
V_84 = F_42 ( V_16 , V_202 , & V_9 , V_1 ) ;
if( V_84 == 0 ) {
F_13 ( V_206 , FALSE ) ;
}
V_203 = F_43 ( & V_16 ) ;
V_206 = F_9 ( L_148 ) ;
F_60 ( F_61 ( V_207 ) , V_203 , V_206 ) ;
V_9 = 0 ;
V_84 = F_39 ( V_16 , V_203 , & V_9 , V_1 ) ;
if( V_84 == 0 ) {
F_13 ( V_206 , FALSE ) ;
}
V_204 = F_43 ( & V_16 ) ;
V_206 = F_9 ( L_149 ) ;
F_60 ( F_61 ( V_207 ) , V_204 , V_206 ) ;
V_9 = 0 ;
V_84 = F_35 ( V_16 , V_204 , & V_9 , V_1 ) ;
if( V_84 == 0 ) {
F_13 ( V_206 , FALSE ) ;
}
V_205 = F_43 ( & V_16 ) ;
V_206 = F_9 ( L_150 ) ;
F_60 ( F_61 ( V_207 ) , V_205 , V_206 ) ;
V_9 = 0 ;
V_84 = F_40 ( V_16 , V_205 , & V_9 , V_1 ) ;
if( V_84 == 0 ) {
F_13 ( V_206 , FALSE ) ;
}
F_62 ( V_1 ) ;
V_12 = F_9 ( L_151 ) ;
F_27 ( F_28 ( V_28 ) , V_12 , FALSE , FALSE , 0 ) ;
V_198 = F_63 ( V_210 , V_211 , NULL ) ;
F_27 ( F_28 ( V_28 ) , V_198 , FALSE , FALSE , 0 ) ;
V_199 = F_64 ( F_65 ( V_198 ) , V_210 ) ;
F_66 ( V_197 , V_199 , V_212 ) ;
V_200 = F_64 ( F_65 ( V_198 ) , V_211 ) ;
F_67 ( V_200 , L_152 , F_68 ( V_213 ) , ( V_214 ) ( V_215 ) ) ;
F_69 ( V_199 ) ;
F_67 ( V_197 , L_153 , F_68 ( V_216 ) , NULL ) ;
F_70 ( V_197 ) ;
F_71 ( V_197 ) ;
}
static void F_72 ( V_214 T_14 V_217 , T_15 V_218 , V_214 V_219 )
{
switch( V_218 ) {
case ( V_209 ) :
F_51 ( V_219 ) ;
break;
case ( V_220 ) :
break;
default:
F_73 () ;
}
}
void
F_74 ( char * V_153 )
{
char * V_221 ;
T_3 V_222 = FALSE ;
V_214 T_14 ;
V_221 = F_75 () ;
if( V_221 == NULL ) {
F_53 ( V_223 , V_209 ,
L_154
L_155
L_156 ,
F_54 () , F_55 () ) ;
return;
}
if(
strcmp ( V_221 , L_157 ) > 0 ||
strcmp ( V_221 , L_158 ) == 0 ||
strcmp ( V_221 , L_159 ) == 0 ||
strcmp ( V_221 , L_160 ) == 0 ||
strcmp ( V_221 , L_161 ) == 0 ||
strcmp ( V_221 , L_162 ) == 0 ||
strcmp ( V_221 , L_163 ) == 0 ||
strcmp ( V_221 , L_164 ) == 0 ||
strcmp ( V_221 , L_165 ) == 0
) {
V_222 = TRUE ;
}
if( ! V_222 ) {
T_14 = F_53 ( V_223 , V_209 | V_220 ,
L_166
L_167
L_168
L_169
L_170 ,
F_54 () , F_55 () , V_221 ) ;
F_76 ( T_14 , F_72 , V_153 ) ;
} else {
F_51 ( V_153 ) ;
}
}
T_3
F_77 ( char * V_153 ) {
T_1 V_1 ;
if ( ! V_153 ) {
return FALSE ;
}
V_1 = F_52 ( V_153 ) ;
if ( V_1 ) {
F_62 ( V_1 ) ;
return TRUE ;
}
return FALSE ;
}
