static inline int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
if ( V_4 == 0 )
return V_5 ;
F_2 ( V_2 , L_1 , V_4 ) ;
return F_3 ( V_2 , V_2 -> V_6 ,
V_3 , V_4 , NULL ) ;
}
static inline int F_4 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
if ( V_4 == 0 )
return V_5 ;
F_2 ( V_2 , L_1 , V_4 ) ;
return F_3 ( V_2 , V_2 -> V_7 ,
V_3 , V_4 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! V_2 )
return V_9 ;
V_8 = F_6 ( V_2 , V_2 -> V_10 ,
0 , 0xA0 , 0 , 7 , V_2 -> V_11 , 1 ) ;
if ( V_8 != V_5 )
return V_9 ;
if ( V_2 -> V_11 [ 0 ] != 0x50 ) {
F_2 ( V_2 , L_2 , V_2 -> V_11 [ 0 ] ) ;
return V_9 ;
}
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_1 V_15 ,
T_1 V_16 )
{
unsigned char * V_17 = V_2 -> V_11 ;
unsigned char * V_18 ;
unsigned char V_19 ;
unsigned int V_20 , V_21 ;
int V_4 , V_22 ;
unsigned int V_23 = 0 ;
struct V_24 * V_25 = NULL ;
if ( V_15 > 0x0FFFFFFF )
return V_9 ;
V_20 = V_16 * V_14 -> V_26 ;
V_21 = F_8 ( V_20 , 65536u ) ;
V_18 = F_9 ( V_21 , V_27 ) ;
if ( V_18 == NULL )
return V_9 ;
do {
V_4 = F_8 ( V_20 , V_21 ) ;
V_19 = ( V_4 / V_14 -> V_26 ) & 0xff ;
V_17 [ 0 ] = 0 ;
V_17 [ 1 ] = V_19 ;
V_17 [ 2 ] = V_15 & 0xFF ;
V_17 [ 3 ] = ( V_15 >> 8 ) & 0xFF ;
V_17 [ 4 ] = ( V_15 >> 16 ) & 0xFF ;
V_17 [ 5 ] = 0xE0 | ( ( V_15 >> 24 ) & 0x0F ) ;
V_17 [ 6 ] = 0x20 ;
V_22 = F_6 ( V_2 , V_2 -> V_28 ,
0 , 0x20 , 0 , 1 , V_17 , 7 ) ;
if ( V_22 != V_5 )
goto V_29;
V_22 = F_1 ( V_2 , V_18 , V_4 ) ;
if ( V_22 != V_5 )
goto V_29;
F_2 ( V_2 , L_3 , V_4 ) ;
F_10 ( V_18 , V_4 , V_2 -> V_30 ,
& V_25 , & V_23 , V_31 ) ;
V_15 += V_19 ;
V_20 -= V_4 ;
} while ( V_20 > 0 );
F_11 ( V_18 ) ;
return V_12 ;
V_29:
F_11 ( V_18 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_1 V_15 ,
T_1 V_16 )
{
unsigned char * V_17 = V_2 -> V_11 ;
unsigned char * V_18 ;
unsigned char V_19 ;
unsigned int V_20 , V_21 ;
int V_4 , V_22 , V_32 ;
unsigned int V_23 = 0 ;
struct V_24 * V_25 = NULL ;
if ( V_15 > 0x0FFFFFFF )
return V_9 ;
V_20 = V_16 * V_14 -> V_26 ;
V_21 = F_8 ( V_20 , 65536u ) ;
V_18 = F_9 ( V_21 , V_27 ) ;
if ( V_18 == NULL )
return V_9 ;
do {
V_4 = F_8 ( V_20 , V_21 ) ;
V_19 = ( V_4 / V_14 -> V_26 ) & 0xff ;
F_10 ( V_18 , V_4 , V_2 -> V_30 ,
& V_25 , & V_23 , V_33 ) ;
V_17 [ 0 ] = 0 ;
V_17 [ 1 ] = V_19 ;
V_17 [ 2 ] = V_15 & 0xFF ;
V_17 [ 3 ] = ( V_15 >> 8 ) & 0xFF ;
V_17 [ 4 ] = ( V_15 >> 16 ) & 0xFF ;
V_17 [ 5 ] = 0xE0 | ( ( V_15 >> 24 ) & 0x0F ) ;
V_17 [ 6 ] = 0x30 ;
V_22 = F_6 ( V_2 , V_2 -> V_28 ,
0 , 0x20 , 0 , 1 , V_17 , 7 ) ;
if ( V_22 != V_5 )
goto V_29;
V_22 = F_4 ( V_2 , V_18 , V_4 ) ;
if ( V_22 != V_5 )
goto V_29;
V_32 = 0 ;
do {
V_22 = F_5 ( V_2 ) ;
if ( V_22 != V_12 ) {
F_13 ( 50 ) ;
}
} while ( ( V_22 != V_12 ) && ( V_32 < 10 ) );
if ( V_22 != V_12 )
F_2 ( V_2 , L_4 ) ;
V_15 += V_19 ;
V_20 -= V_4 ;
} while ( V_20 > 0 );
F_11 ( V_18 ) ;
return V_22 ;
V_29:
F_11 ( V_18 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
unsigned char * V_17 = V_2 -> V_11 ;
unsigned char * V_34 ;
int V_8 ;
if ( ! V_14 )
return V_9 ;
V_17 [ 0 ] = 0xE0 ;
V_17 [ 1 ] = 0xEC ;
V_34 = F_9 ( 512 , V_27 ) ;
if ( ! V_34 )
return V_9 ;
V_8 = F_6 ( V_2 , V_2 -> V_28 ,
0 , 0x20 , 0 , 6 , V_17 , 2 ) ;
if ( V_8 != V_5 ) {
F_2 ( V_2 , L_5 ) ;
V_8 = V_9 ;
goto V_29;
}
V_8 = F_1 ( V_2 , V_34 , 512 ) ;
if ( V_8 != V_5 ) {
V_8 = V_9 ;
goto V_29;
}
V_14 -> V_16 = ( ( T_1 ) ( V_34 [ 117 ] ) << 24 ) |
( ( T_1 ) ( V_34 [ 116 ] ) << 16 ) |
( ( T_1 ) ( V_34 [ 115 ] ) << 8 ) |
( ( T_1 ) ( V_34 [ 114 ] ) ) ;
V_8 = V_12 ;
V_29:
F_11 ( V_34 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_35 * V_30 ,
int V_36 )
{
static unsigned char V_37 [ 12 ] = {
0x1 , 0xA , 0x21 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0
} ;
static unsigned char V_38 [ 12 ] = {
0x8 , 0xA , 0x1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ;
static unsigned char V_39 [ 12 ] = {
0x1B , 0xA , 0 , 0x81 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ;
static unsigned char V_40 [ 8 ] = {
0x1C , 0x6 , 0 , 0 , 0 , 0
} ;
unsigned char V_41 , V_42 ;
unsigned int V_43 = 0 ;
struct V_13 * V_14 = (struct V_13 * ) ( V_2 -> V_44 ) ;
unsigned char * V_45 = V_2 -> V_11 ;
V_41 = V_30 -> V_46 [ 2 ] >> 6 ;
V_42 = V_30 -> V_46 [ 2 ] & 0x3F ;
switch ( V_41 ) {
case 0x0 :
F_2 ( V_2 , L_6 ) ;
break;
case 0x1 :
F_2 ( V_2 , L_7 ) ;
break;
case 0x2 :
F_2 ( V_2 , L_8 ) ;
break;
case 0x3 :
F_2 ( V_2 , L_9 ) ;
break;
}
memset ( V_45 , 0 , 8 ) ;
if ( V_36 ) {
V_45 [ 2 ] = 0x00 ;
V_43 = 4 ;
} else {
V_45 [ 3 ] = 0x00 ;
V_43 = 8 ;
}
switch ( V_42 ) {
case 0x0 :
V_14 -> V_47 = 0x05 ;
V_14 -> V_48 = 0x24 ;
V_14 -> V_49 = 0x00 ;
return V_50 ;
case 0x1 :
memcpy ( V_45 + V_43 , V_37 , sizeof( V_37 ) ) ;
V_43 += sizeof( V_37 ) ;
break;
case 0x8 :
memcpy ( V_45 + V_43 , V_38 , sizeof( V_38 ) ) ;
V_43 += sizeof( V_38 ) ;
break;
case 0x1B :
memcpy ( V_45 + V_43 , V_39 , sizeof( V_39 ) ) ;
V_43 += sizeof( V_39 ) ;
break;
case 0x1C :
memcpy ( V_45 + V_43 , V_40 , sizeof( V_40 ) ) ;
V_43 += sizeof( V_40 ) ;
break;
case 0x3F :
memcpy ( V_45 + V_43 , V_40 , sizeof( V_40 ) ) ;
V_43 += sizeof( V_40 ) ;
memcpy ( V_45 + V_43 , V_39 , sizeof( V_39 ) ) ;
V_43 += sizeof( V_39 ) ;
memcpy ( V_45 + V_43 , V_38 , sizeof( V_38 ) ) ;
V_43 += sizeof( V_38 ) ;
memcpy ( V_45 + V_43 , V_37 , sizeof( V_37 ) ) ;
V_43 += sizeof( V_37 ) ;
break;
}
if ( V_36 )
V_45 [ 0 ] = V_43 - 1 ;
else
( ( V_51 * ) V_45 ) [ 0 ] = F_16 ( V_43 - 2 ) ;
F_17 ( V_45 , V_43 , V_30 ) ;
return V_12 ;
}
static void F_18 ( void * V_44 )
{
}
static int F_19 ( struct V_35 * V_30 , struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_8 ;
unsigned long V_52 , V_53 ;
unsigned char * V_45 = V_2 -> V_11 ;
static unsigned char V_54 [ 8 ] = {
0x00 , 0x80 , 0x00 , 0x01 , 0x1F , 0x00 , 0x00 , 0x00
} ;
if ( ! V_2 -> V_44 ) {
V_2 -> V_44 = F_20 ( sizeof( struct V_13 ) , V_27 ) ;
if ( ! V_2 -> V_44 )
return V_9 ;
V_2 -> V_55 = F_18 ;
}
V_14 = (struct V_13 * ) ( V_2 -> V_44 ) ;
if ( V_30 -> V_46 [ 0 ] == V_56 ) {
F_2 ( V_2 , L_10 ) ;
memcpy ( V_45 , V_54 , sizeof( V_54 ) ) ;
F_21 ( V_2 , V_45 , 36 ) ;
return V_12 ;
}
if ( V_30 -> V_46 [ 0 ] == V_57 ) {
V_14 -> V_26 = 0x200 ;
V_8 = F_5 ( V_2 ) ;
if ( V_8 != V_12 )
return V_8 ;
V_8 = F_14 ( V_2 , V_14 ) ;
if ( V_8 != V_12 )
return V_8 ;
F_2 ( V_2 , L_11 ,
V_14 -> V_16 , V_14 -> V_26 ) ;
( ( V_58 * ) V_45 ) [ 0 ] = F_22 ( V_14 -> V_16 - 1 ) ;
( ( V_58 * ) V_45 ) [ 1 ] = F_22 ( V_14 -> V_26 ) ;
F_17 ( V_45 , 8 , V_30 ) ;
return V_12 ;
}
if ( V_30 -> V_46 [ 0 ] == V_59 ) {
F_2 ( V_2 , L_12 ) ;
return V_9 ;
}
if ( V_30 -> V_46 [ 0 ] == V_60 ) {
V_52 = ( ( T_1 ) ( V_30 -> V_46 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 5 ] ) ) ;
V_53 = ( ( T_1 ) ( V_30 -> V_46 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 8 ] ) ) ;
F_2 ( V_2 , L_13 ,
V_52 , V_53 ) ;
return F_7 ( V_2 , V_14 , V_52 , V_53 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_61 ) {
V_52 = ( ( T_1 ) ( V_30 -> V_46 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 5 ] ) ) ;
V_53 = ( ( T_1 ) ( V_30 -> V_46 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 9 ] ) ) ;
F_2 ( V_2 , L_14 ,
V_52 , V_53 ) ;
return F_7 ( V_2 , V_14 , V_52 , V_53 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_62 ) {
V_52 = ( ( T_1 ) ( V_30 -> V_46 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 5 ] ) ) ;
V_53 = ( ( T_1 ) ( V_30 -> V_46 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 8 ] ) ) ;
F_2 ( V_2 , L_15 ,
V_52 , V_53 ) ;
return F_12 ( V_2 , V_14 , V_52 , V_53 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_63 ) {
V_52 = ( ( T_1 ) ( V_30 -> V_46 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 5 ] ) ) ;
V_53 = ( ( T_1 ) ( V_30 -> V_46 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_30 -> V_46 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_30 -> V_46 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_30 -> V_46 [ 9 ] ) ) ;
F_2 ( V_2 , L_16 ,
V_52 , V_53 ) ;
return F_12 ( V_2 , V_14 , V_52 , V_53 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_64 ) {
F_2 ( V_2 , L_17 ) ;
return F_5 ( V_2 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_65 ) {
F_2 ( V_2 , L_18 ) ;
memset ( V_45 , 0 , 18 ) ;
V_45 [ 0 ] = 0xF0 ;
V_45 [ 2 ] = V_14 -> V_47 ;
V_45 [ 7 ] = 11 ;
V_45 [ 12 ] = V_14 -> V_48 ;
V_45 [ 13 ] = V_14 -> V_49 ;
F_17 ( V_45 , 18 , V_30 ) ;
return V_12 ;
}
if ( V_30 -> V_46 [ 0 ] == V_66 ) {
F_2 ( V_2 , L_19 ) ;
return F_15 ( V_2 , V_30 , 1 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_67 ) {
F_2 ( V_2 , L_20 ) ;
return F_15 ( V_2 , V_30 , 0 ) ;
}
if ( V_30 -> V_46 [ 0 ] == V_68 ) {
return V_12 ;
}
if ( V_30 -> V_46 [ 0 ] == V_69 ) {
F_2 ( V_2 , L_21 ) ;
V_8 = F_14 ( V_2 , V_14 ) ;
if ( V_8 == V_12 ) {
V_14 -> V_47 = V_70 ;
V_30 -> V_22 = V_71 ;
} else {
V_14 -> V_47 = V_72 ;
V_30 -> V_22 = V_73 ;
}
return V_8 ;
}
F_2 ( V_2 , L_22 ,
V_30 -> V_46 [ 0 ] , V_30 -> V_46 [ 0 ] ) ;
V_14 -> V_47 = 0x05 ;
V_14 -> V_48 = 0x20 ;
V_14 -> V_49 = 0x00 ;
return V_50 ;
}
static int F_23 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_1 * V_2 ;
int V_22 ;
V_22 = F_24 ( & V_2 , V_75 , V_77 ,
( V_77 - V_78 ) + V_79 ,
& V_80 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_81 = L_23 ;
V_2 -> V_82 = F_19 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = 1 ;
V_22 = F_25 ( V_2 ) ;
return V_22 ;
}
