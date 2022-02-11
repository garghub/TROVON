static inline int
F_1 ( struct V_1 * V_2 , unsigned char * V_3 , unsigned int V_4 ) {
if ( V_4 == 0 )
return V_5 ;
F_2 ( V_2 , L_1 , V_4 ) ;
return F_3 ( V_2 , V_2 -> V_6 ,
V_3 , V_4 , NULL ) ;
}
static inline int
F_4 ( struct V_1 * V_2 , unsigned char * V_3 , unsigned int V_4 ) {
if ( V_4 == 0 )
return V_5 ;
F_2 ( V_2 , L_1 , V_4 ) ;
return F_3 ( V_2 , V_2 -> V_7 ,
V_3 , V_4 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
unsigned char * V_12 = V_2 -> V_13 ;
unsigned char * V_14 ;
unsigned char V_15 ;
unsigned int V_16 , V_17 ;
int V_4 , V_18 ;
unsigned int V_19 = 0 ;
struct V_20 * V_21 = NULL ;
if ( V_11 > 0x0FFFFFFF )
return V_22 ;
if ( V_9 -> V_23 == - 1 ) {
V_18 = F_6 ( V_2 , V_9 ) ;
if ( V_18 != V_24 )
return V_18 ;
}
V_16 = V_11 * V_9 -> V_25 ;
V_17 = F_7 ( V_16 , 65536u ) ;
V_14 = F_8 ( V_17 , V_26 ) ;
if ( V_14 == NULL )
return V_22 ;
do {
V_4 = F_7 ( V_16 , V_17 ) ;
V_15 = ( V_4 / V_9 -> V_25 ) & 0xff ;
V_12 [ 0 ] = 0 ;
V_12 [ 1 ] = V_15 ;
V_12 [ 2 ] = V_10 & 0xFF ;
V_12 [ 3 ] = ( V_10 >> 8 ) & 0xFF ;
V_12 [ 4 ] = ( V_10 >> 16 ) & 0xFF ;
V_12 [ 5 ] = 0xE0 + ( V_9 -> V_23 << 4 ) ;
V_12 [ 5 ] |= ( V_10 >> 24 ) & 0x0F ;
V_12 [ 6 ] = 0x20 ;
V_12 [ 7 ] = 0x01 ;
V_18 = F_4 ( V_2 , V_12 , 8 ) ;
if ( V_18 != V_5 )
goto V_27;
V_18 = F_1 ( V_2 , V_14 , V_4 ) ;
if ( V_18 != V_5 )
goto V_27;
F_9 ( V_14 , V_4 , V_2 -> V_28 ,
& V_21 , & V_19 , V_29 ) ;
V_10 += V_15 ;
V_16 -= V_4 ;
} while ( V_16 > 0 );
F_10 ( V_14 ) ;
return V_24 ;
V_27:
F_10 ( V_14 ) ;
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
unsigned char * V_12 = V_2 -> V_13 ;
unsigned char * V_30 = V_2 -> V_13 ;
unsigned char * V_14 ;
unsigned char V_15 ;
unsigned int V_16 , V_17 ;
int V_4 , V_18 ;
unsigned int V_19 = 0 ;
struct V_20 * V_21 = NULL ;
if ( V_11 > 0x0FFFFFFF )
return V_22 ;
if ( V_9 -> V_23 == - 1 ) {
V_18 = F_6 ( V_2 , V_9 ) ;
if ( V_18 != V_24 )
return V_18 ;
}
V_16 = V_11 * V_9 -> V_25 ;
V_17 = F_7 ( V_16 , 65536u ) ;
V_14 = F_8 ( V_17 , V_26 ) ;
if ( V_14 == NULL )
return V_22 ;
do {
V_4 = F_7 ( V_16 , V_17 ) ;
V_15 = ( V_4 / V_9 -> V_25 ) & 0xff ;
F_9 ( V_14 , V_4 , V_2 -> V_28 ,
& V_21 , & V_19 , V_31 ) ;
V_12 [ 0 ] = 0 ;
V_12 [ 1 ] = V_15 ;
V_12 [ 2 ] = V_10 & 0xFF ;
V_12 [ 3 ] = ( V_10 >> 8 ) & 0xFF ;
V_12 [ 4 ] = ( V_10 >> 16 ) & 0xFF ;
V_12 [ 5 ] = 0xE0 + ( V_9 -> V_23 << 4 ) ;
V_12 [ 5 ] |= ( V_10 >> 24 ) & 0x0F ;
V_12 [ 6 ] = 0x30 ;
V_12 [ 7 ] = 0x02 ;
V_18 = F_4 ( V_2 , V_12 , 8 ) ;
if ( V_18 != V_5 )
goto V_27;
V_18 = F_4 ( V_2 , V_14 , V_4 ) ;
if ( V_18 != V_5 )
goto V_27;
V_18 = F_1 ( V_2 , V_30 , 2 ) ;
if ( V_18 != V_5 )
goto V_27;
if ( V_30 [ 0 ] != 0x50 && V_30 [ 1 ] != 0 ) {
F_2 ( V_2 , L_2 ,
V_30 [ 0 ] , V_30 [ 1 ] ) ;
V_18 = V_22 ;
goto V_27;
}
V_10 += V_15 ;
V_16 -= V_4 ;
} while ( V_16 > 0 );
F_10 ( V_14 ) ;
return V_24 ;
V_27:
F_10 ( V_14 ) ;
return V_22 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
static unsigned char V_32 [ 8 ] = { 0 , 1 , 0 , 0 , 0 , 0xa0 , 0xec , 1 } ;
unsigned char * V_12 = V_2 -> V_13 ;
unsigned char * V_33 ;
int V_34 = 0 , V_35 ;
if ( ! V_9 )
return V_22 ;
memcpy ( V_12 , V_32 , 8 ) ;
V_33 = F_8 ( 512 , V_26 ) ;
if ( ! V_33 )
return V_22 ;
F_2 ( V_2 , L_3 ) ;
while ( V_34 ++ < 3 ) {
V_12 [ 5 ] = 0xa0 ;
V_35 = F_4 ( V_2 , V_12 , 8 ) ;
if ( V_35 != V_5 ) {
V_35 = V_22 ;
goto V_27;
}
V_35 = F_1 ( V_2 , V_33 , 512 ) ;
if ( V_35 == V_5 ) {
V_9 -> V_23 = 0 ;
V_35 = V_24 ;
goto V_27;
}
V_12 [ 5 ] = 0xb0 ;
V_35 = F_4 ( V_2 , V_12 , 8 ) ;
if ( V_35 != V_5 ) {
V_35 = V_22 ;
goto V_27;
}
V_35 = F_1 ( V_2 , V_33 , 512 ) ;
if ( V_35 == V_5 ) {
V_9 -> V_23 = 1 ;
V_35 = V_24 ;
goto V_27;
}
F_12 ( 20 ) ;
}
V_35 = V_22 ;
V_27:
F_10 ( V_33 ) ;
return V_35 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
static unsigned char V_32 [ 8 ] = { 0 , 1 , 0 , 0 , 0 , 0xa0 , 0xec , 1 } ;
unsigned char * V_12 = V_2 -> V_13 ;
unsigned char * V_30 ;
int V_35 ;
if ( ! V_9 )
return V_22 ;
if ( V_9 -> V_23 == - 1 ) {
V_35 = F_6 ( V_2 , V_9 ) ;
if ( V_35 != V_24 )
return V_35 ;
}
memcpy ( V_12 , V_32 , 8 ) ;
V_30 = F_8 ( 512 , V_26 ) ;
if ( ! V_30 )
return V_22 ;
V_12 [ 5 ] += ( V_9 -> V_23 << 4 ) ;
V_35 = F_4 ( V_2 , V_12 , 8 ) ;
if ( V_35 != V_5 ) {
V_35 = V_22 ;
goto V_27;
}
V_35 = F_1 ( V_2 , V_30 , 512 ) ;
if ( V_35 == V_5 ) {
V_9 -> V_11 = ( ( T_1 ) ( V_30 [ 117 ] ) << 24 ) |
( ( T_1 ) ( V_30 [ 116 ] ) << 16 ) |
( ( T_1 ) ( V_30 [ 115 ] ) << 8 ) |
( ( T_1 ) ( V_30 [ 114 ] ) ) ;
V_35 = V_24 ;
goto V_27;
}
V_35 = V_22 ;
V_27:
F_10 ( V_30 ) ;
return V_35 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_36 * V_28 ,
int V_37 )
{
static unsigned char V_38 [ 12 ] = {
0x1 , 0xA , 0x21 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0
} ;
static unsigned char V_39 [ 12 ] = {
0x8 , 0xA , 0x1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ;
static unsigned char V_40 [ 12 ] = {
0x1B , 0xA , 0 , 0x81 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ;
static unsigned char V_41 [ 8 ] = {
0x1C , 0x6 , 0 , 0 , 0 , 0
} ;
unsigned char V_42 , V_43 ;
unsigned int V_44 = 0 ;
struct V_8 * V_9 = (struct V_8 * ) ( V_2 -> V_45 ) ;
unsigned char * V_46 = V_2 -> V_13 ;
V_42 = V_28 -> V_47 [ 2 ] >> 6 ;
V_43 = V_28 -> V_47 [ 2 ] & 0x3F ;
switch ( V_42 ) {
case 0x0 :
F_2 ( V_2 , L_4 ) ;
break;
case 0x1 :
F_2 ( V_2 , L_5 ) ;
break;
case 0x2 :
F_2 ( V_2 , L_6 ) ;
break;
case 0x3 :
F_2 ( V_2 , L_7 ) ;
break;
}
memset ( V_46 , 0 , 8 ) ;
if ( V_37 ) {
V_46 [ 2 ] = 0x00 ;
V_44 = 4 ;
} else {
V_46 [ 3 ] = 0x00 ;
V_44 = 8 ;
}
switch ( V_43 ) {
default:
V_9 -> V_48 = 0x05 ;
V_9 -> V_49 = 0x24 ;
V_9 -> V_50 = 0x00 ;
return V_51 ;
case 0x1 :
memcpy ( V_46 + V_44 , V_38 , sizeof( V_38 ) ) ;
V_44 += sizeof( V_38 ) ;
break;
case 0x8 :
memcpy ( V_46 + V_44 , V_39 , sizeof( V_39 ) ) ;
V_44 += sizeof( V_39 ) ;
break;
case 0x1B :
memcpy ( V_46 + V_44 , V_40 , sizeof( V_40 ) ) ;
V_44 += sizeof( V_40 ) ;
break;
case 0x1C :
memcpy ( V_46 + V_44 , V_41 , sizeof( V_41 ) ) ;
V_44 += sizeof( V_41 ) ;
break;
case 0x3F :
memcpy ( V_46 + V_44 , V_41 , sizeof( V_41 ) ) ;
V_44 += sizeof( V_41 ) ;
memcpy ( V_46 + V_44 , V_40 , sizeof( V_40 ) ) ;
V_44 += sizeof( V_40 ) ;
memcpy ( V_46 + V_44 , V_39 , sizeof( V_39 ) ) ;
V_44 += sizeof( V_39 ) ;
memcpy ( V_46 + V_44 , V_38 , sizeof( V_38 ) ) ;
V_44 += sizeof( V_38 ) ;
break;
}
if ( V_37 )
V_46 [ 0 ] = V_44 - 1 ;
else
( ( V_52 * ) V_46 ) [ 0 ] = F_15 ( V_44 - 2 ) ;
F_16 ( V_46 , V_44 , V_28 ) ;
return V_24 ;
}
static void F_17 ( void * V_45 )
{
}
static int F_18 ( struct V_36 * V_28 , struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_35 ;
unsigned long V_53 , V_54 ;
unsigned char * V_46 = V_2 -> V_13 ;
static unsigned char V_55 [ 8 ] = {
0x00 , 0x80 , 0x00 , 0x01 , 0x1F , 0x00 , 0x00 , 0x00
} ;
if ( ! V_2 -> V_45 ) {
V_2 -> V_45 = F_19 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_2 -> V_45 )
return V_22 ;
V_2 -> V_56 = F_17 ;
( (struct V_8 * ) V_2 -> V_45 ) -> V_23 = - 1 ;
}
V_9 = (struct V_8 * ) ( V_2 -> V_45 ) ;
if ( V_28 -> V_47 [ 0 ] == V_57 ) {
F_2 ( V_2 , L_8 ) ;
memcpy ( V_46 , V_55 , sizeof( V_55 ) ) ;
F_20 ( V_2 , V_46 , 36 ) ;
return V_24 ;
}
if ( V_28 -> V_47 [ 0 ] == V_58 ) {
V_9 -> V_25 = 0x200 ;
V_35 = F_13 ( V_2 , V_9 ) ;
if ( V_35 != V_24 )
return V_35 ;
F_2 ( V_2 , L_9 ,
V_9 -> V_11 , V_9 -> V_25 ) ;
( ( V_59 * ) V_46 ) [ 0 ] = F_21 ( V_9 -> V_11 - 1 ) ;
( ( V_59 * ) V_46 ) [ 1 ] = F_21 ( V_9 -> V_25 ) ;
F_16 ( V_46 , 8 , V_28 ) ;
return V_24 ;
}
if ( V_28 -> V_47 [ 0 ] == V_60 ) {
F_2 ( V_2 , L_10 ) ;
return V_22 ;
}
if ( V_28 -> V_47 [ 0 ] == V_61 ) {
V_53 = ( ( T_1 ) ( V_28 -> V_47 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 5 ] ) ) ;
V_54 = ( ( T_1 ) ( V_28 -> V_47 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 8 ] ) ) ;
F_2 ( V_2 , L_11 ,
V_53 , V_54 ) ;
return F_5 ( V_2 , V_9 , V_53 , V_54 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_62 ) {
V_53 = ( ( T_1 ) ( V_28 -> V_47 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 5 ] ) ) ;
V_54 = ( ( T_1 ) ( V_28 -> V_47 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 9 ] ) ) ;
F_2 ( V_2 , L_12 ,
V_53 , V_54 ) ;
return F_5 ( V_2 , V_9 , V_53 , V_54 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_63 ) {
V_53 = ( ( T_1 ) ( V_28 -> V_47 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 5 ] ) ) ;
V_54 = ( ( T_1 ) ( V_28 -> V_47 [ 7 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 8 ] ) ) ;
F_2 ( V_2 , L_13 ,
V_53 , V_54 ) ;
return F_11 ( V_2 , V_9 , V_53 , V_54 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_64 ) {
V_53 = ( ( T_1 ) ( V_28 -> V_47 [ 2 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 3 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 4 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 5 ] ) ) ;
V_54 = ( ( T_1 ) ( V_28 -> V_47 [ 6 ] ) << 24 ) | ( ( T_1 ) ( V_28 -> V_47 [ 7 ] ) << 16 ) |
( ( T_1 ) ( V_28 -> V_47 [ 8 ] ) << 8 ) | ( ( T_1 ) ( V_28 -> V_47 [ 9 ] ) ) ;
F_2 ( V_2 , L_14 ,
V_53 , V_54 ) ;
return F_11 ( V_2 , V_9 , V_53 , V_54 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_65 ) {
F_2 ( V_2 , L_15 ) ;
return F_13 ( V_2 , V_9 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_66 ) {
F_2 ( V_2 , L_16 ) ;
memset ( V_46 , 0 , 18 ) ;
V_46 [ 0 ] = 0xF0 ;
V_46 [ 2 ] = V_9 -> V_48 ;
V_46 [ 7 ] = 11 ;
V_46 [ 12 ] = V_9 -> V_49 ;
V_46 [ 13 ] = V_9 -> V_50 ;
F_16 ( V_46 , 18 , V_28 ) ;
return V_24 ;
}
if ( V_28 -> V_47 [ 0 ] == V_67 ) {
F_2 ( V_2 , L_17 ) ;
return F_14 ( V_2 , V_28 , 1 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_68 ) {
F_2 ( V_2 , L_18 ) ;
return F_14 ( V_2 , V_28 , 0 ) ;
}
if ( V_28 -> V_47 [ 0 ] == V_69 ) {
return V_24 ;
}
if ( V_28 -> V_47 [ 0 ] == V_70 ) {
F_2 ( V_2 , L_19 ) ;
V_35 = F_13 ( V_2 , V_9 ) ;
if ( V_35 == V_24 ) {
V_9 -> V_48 = V_71 ;
V_28 -> V_18 = V_72 ;
} else {
V_9 -> V_48 = V_73 ;
V_28 -> V_18 = V_74 ;
}
return V_35 ;
}
F_2 ( V_2 , L_20 ,
V_28 -> V_47 [ 0 ] , V_28 -> V_47 [ 0 ] ) ;
V_9 -> V_48 = 0x05 ;
V_9 -> V_49 = 0x20 ;
V_9 -> V_50 = 0x00 ;
return V_51 ;
}
static int F_22 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_1 * V_2 ;
int V_18 ;
V_18 = F_23 ( & V_2 , V_76 , V_78 ,
( V_78 - V_79 ) + V_80 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_81 = L_21 ;
V_2 -> V_82 = F_18 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = 1 ;
V_18 = F_24 ( V_2 ) ;
return V_18 ;
}
