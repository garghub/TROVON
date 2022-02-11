static int
F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned char * V_4 , unsigned int V_5 ) {
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
unsigned int V_9 = ( V_3 == V_10 ) ?
V_2 -> V_11 : V_2 -> V_12 ;
if ( ! V_5 )
return V_13 ;
V_7 -> V_14 = V_15 ;
return F_2 ( V_2 , V_9 , V_4 , V_5 , NULL ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_16 ;
unsigned char * V_17 = V_2 -> V_18 ;
unsigned char * V_19 = V_2 -> V_18 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
memset ( V_17 , 0 , 8 ) ;
V_17 [ 5 ] = 0xB0 ;
V_17 [ 7 ] = 0x80 ;
V_16 = F_1 ( V_2 ,
V_20 , V_17 , 8 ) ;
F_4 ( V_2 , L_1 , V_16 ) ;
if ( V_16 != V_13 ) {
F_5 ( 4 , 0 , 0 ) ;
return V_21 ;
}
V_16 = F_1 ( V_2 ,
V_10 , V_19 , 4 ) ;
if ( V_16 == V_22 || V_16 == V_23 ) {
F_6 ( V_7 -> V_24 ) ;
F_6 ( V_7 -> V_25 ) ;
V_7 -> V_24 = NULL ;
V_7 -> V_25 = NULL ;
V_7 -> V_26 = 0 ;
V_7 -> V_27 = 0 ;
F_5 ( 2 , 0x3a , 0 ) ;
return V_28 ;
}
if ( V_16 != V_13 ) {
F_5 ( 4 , 0 , 0 ) ;
return V_28 ;
}
V_7 -> V_29 = ( V_19 [ 0 ] & 0x20 ) ;
V_16 = F_1 ( V_2 ,
V_10 , V_19 , 2 ) ;
if ( V_16 != V_13 ) {
F_5 ( 4 , 0 , 0 ) ;
}
return ( V_16 == V_13 ?
V_30 : V_28 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_31 ,
unsigned int V_32 ,
unsigned short V_33 ) {
int V_16 = V_30 ;
unsigned char * V_17 = V_2 -> V_18 ;
unsigned char * V_19 = V_2 -> V_18 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
unsigned char * V_34 ;
unsigned int V_35 ;
unsigned long V_36 ;
unsigned short V_37 ;
unsigned int V_5 , V_38 ;
struct V_39 * V_40 ;
V_5 = F_8 ( ( unsigned int ) V_33 , ( unsigned int ) V_7 -> V_41 >>
V_7 -> V_42 ) * V_43 ;
V_34 = F_9 ( V_5 , V_44 ) ;
if ( V_34 == NULL )
return V_21 ;
V_38 = 0 ;
V_40 = NULL ;
while ( V_33 > 0 ) {
if ( V_31 >= V_7 -> V_45 )
break;
V_35 = V_7 -> V_24 [ V_31 ] ;
V_37 = F_8 ( ( unsigned int ) V_33 << V_7 -> V_42 ,
V_7 -> V_41 - V_32 ) ;
V_5 = V_37 << V_7 -> V_46 ;
F_4 ( V_2 , L_2 ,
V_37 , V_35 , V_31 , V_32 ) ;
if ( V_35 == V_47 ) {
memset ( V_34 , 0 , V_5 ) ;
} else {
V_36 = ( V_35 << V_7 -> V_48 ) + V_32 ;
V_17 [ 0 ] = 0 ;
V_17 [ 1 ] = F_10 ( V_36 >> 16 ) ;
V_17 [ 2 ] = F_10 ( V_36 >> 8 ) ;
V_17 [ 3 ] = F_10 ( V_36 ) ;
V_17 [ 4 ] = 0 ;
V_17 [ 5 ] = 0xB0 ;
V_17 [ 6 ] = F_10 ( V_37 << ( 1 - V_7 -> V_42 ) ) ;
V_17 [ 7 ] = 0x85 ;
V_16 = F_1 ( V_2 ,
V_20 , V_17 , 8 ) ;
F_4 ( V_2 , L_3 ,
V_16 ) ;
if ( V_16 != V_13 ) {
V_16 = V_21 ;
goto V_49;
}
V_16 = F_1 ( V_2 ,
V_10 , V_34 , V_5 ) ;
if ( V_16 != V_13 ) {
V_16 = V_21 ;
goto V_49;
}
V_16 = F_1 ( V_2 ,
V_10 , V_19 , 2 ) ;
if ( V_16 != V_13 ) {
V_16 = V_21 ;
goto V_49;
}
if ( V_19 [ 0 ] == 0xff && V_19 [ 1 ] == 0x4 ) {
F_5 ( 3 , 0x11 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
}
F_11 ( V_34 , V_5 , V_2 -> V_50 ,
& V_40 , & V_38 , V_51 ) ;
V_32 = 0 ;
V_31 ++ ;
V_33 -= V_37 >> V_7 -> V_42 ;
}
V_16 = V_30 ;
V_49:
F_6 ( V_34 ) ;
return V_16 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_31 ,
unsigned int V_32 ,
unsigned short V_33 ) {
int V_16 = V_30 ;
unsigned char * V_17 = V_2 -> V_18 ;
unsigned char * V_19 = V_2 -> V_18 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
unsigned char * V_34 ;
unsigned int V_35 ;
unsigned int V_52 ;
unsigned long V_36 ;
unsigned short V_37 ;
int V_53 ;
unsigned int V_5 , V_38 ;
struct V_39 * V_40 ;
if ( V_7 -> V_29 || V_7 -> V_27 ) {
F_5 ( 7 , 0x27 , 0 ) ;
return V_28 ;
}
V_5 = F_8 ( ( unsigned int ) V_33 , ( unsigned int ) V_7 -> V_41 >>
V_7 -> V_42 ) * V_43 ;
V_34 = F_9 ( V_5 , V_44 ) ;
if ( V_34 == NULL )
return V_21 ;
V_38 = 0 ;
V_40 = NULL ;
while ( V_33 > 0 ) {
if ( V_31 >= V_7 -> V_45 )
break;
V_35 = V_7 -> V_24 [ V_31 ] ;
V_37 = F_8 ( ( unsigned int ) V_33 << V_7 -> V_42 ,
V_7 -> V_41 - V_32 ) ;
V_5 = V_37 << V_7 -> V_46 ;
F_11 ( V_34 , V_5 , V_2 -> V_50 ,
& V_40 , & V_38 , V_54 ) ;
F_4 ( V_2 , L_4 ,
V_37 , V_35 , V_31 , V_32 ) ;
V_17 [ 4 ] = 0 ;
if ( V_35 == V_47 ) {
int V_55 = ( V_7 -> V_45 / 250 ) * 256 ;
int V_56 = 0 ;
int V_57 = - 1 ;
V_35 = ( V_31 / 1000 ) * 1024 ;
F_4 ( V_2 , L_5 , V_31 ) ;
if ( V_55 > 1024 )
V_55 = 1024 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ , V_35 ++ ) {
if ( V_7 -> V_25 [ V_35 ] == V_58 ) {
V_57 = V_35 ;
if ( V_56 ++ > 16 )
break;
}
}
V_35 = V_57 ;
if ( V_35 == - 1 ) {
F_4 ( V_2 , L_6 ) ;
F_5 ( 3 , 0x31 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
F_4 ( V_2 , L_7 ,
V_35 , V_31 ) ;
V_17 [ 4 ] = 0x40 ;
}
V_36 = ( V_35 << V_7 -> V_48 ) + V_32 ;
V_17 [ 1 ] = F_10 ( V_36 >> 16 ) ;
V_17 [ 2 ] = F_10 ( V_36 >> 8 ) ;
V_17 [ 3 ] = F_10 ( V_36 ) ;
V_17 [ 0 ] = F_10 ( V_31 % 1000 ) ;
V_17 [ 6 ] = F_13 ( V_31 % 1000 ) ;
V_17 [ 4 ] |= F_10 ( V_37 >> V_7 -> V_42 ) ;
V_17 [ 5 ] = 0xB0 ;
V_17 [ 7 ] = 0x86 ;
V_16 = F_1 ( V_2 ,
V_20 , V_17 , 8 ) ;
if ( V_16 != V_13 ) {
F_4 ( V_2 , L_8 ,
V_16 ) ;
F_5 ( 3 , 0x3 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
V_16 = F_1 ( V_2 ,
V_20 , V_34 , V_5 ) ;
if ( V_16 != V_13 ) {
F_4 ( V_2 , L_9 ,
V_16 ) ;
F_5 ( 3 , 0x3 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
V_16 = F_1 ( V_2 , V_10 , V_19 , 6 ) ;
if ( V_16 != V_13 ) {
F_4 ( V_2 , L_10 ,
V_16 ) ;
F_5 ( 3 , 0x3 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
V_52 = ( V_19 [ 3 ] + ( V_19 [ 4 ] << 8 ) + ( V_19 [ 5 ] << 16 ) )
>> V_7 -> V_48 ;
if ( V_19 [ 0 ] == 0xff && V_19 [ 1 ] == 0x4 ) {
V_7 -> V_25 [ V_52 ] = V_59 ;
F_5 ( 3 , 0x0c , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
F_4 ( V_2 , L_11 ,
V_31 , V_35 , V_52 ) ;
V_7 -> V_24 [ V_31 ] = V_52 ;
V_7 -> V_25 [ V_35 ] = V_58 ;
if ( V_7 -> V_25 [ V_52 ] != V_58 ) {
F_14 ( V_60 L_12 ,
V_52 , V_7 -> V_25 [ V_52 ] ) ;
V_7 -> V_26 = 1 ;
F_5 ( 3 , 0x31 , 0 ) ;
V_16 = V_28 ;
goto V_49;
}
V_7 -> V_25 [ V_52 ] = V_31 % 1000 ;
V_32 = 0 ;
V_31 ++ ;
V_33 -= V_37 >> V_7 -> V_42 ;
}
V_16 = V_30 ;
V_49:
F_6 ( V_34 ) ;
return V_16 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned char * V_61 ,
unsigned char * V_62 ) {
int V_16 ;
unsigned char * V_17 = V_2 -> V_18 ;
unsigned char * V_63 = V_2 -> V_18 ;
memset ( V_17 , 0 , 8 ) ;
V_17 [ 5 ] = 0xB0 ;
V_17 [ 7 ] = 0x84 ;
V_16 = F_1 ( V_2 , V_20 , V_17 , 8 ) ;
F_4 ( V_2 , L_13 ,
V_16 ) ;
if ( V_16 != V_13 )
return V_21 ;
V_16 = F_1 ( V_2 ,
V_10 , V_63 , 4 ) ;
if ( V_16 != V_13 )
return V_21 ;
* V_61 = V_63 [ 0 ] ;
* V_62 = V_63 [ 1 ] ;
if ( V_63 [ 0 ] != 0xff ) {
V_16 = F_1 ( V_2 ,
V_10 , V_63 , 2 ) ;
}
return V_30 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static unsigned long F_17 ( struct V_1 * V_2 ) {
unsigned char V_64 ( V_61 ) ;
unsigned char V_64 ( V_62 ) ;
int V_16 ;
struct V_6 * V_7 = (struct V_6 * ) V_2 -> V_8 ;
F_4 ( V_2 , L_14 ) ;
V_16 = F_15 ( V_2 ,
& V_61 ,
& V_62 ) ;
F_4 ( V_2 , L_15 , V_16 ) ;
if ( V_16 != V_13 )
return 0 ;
F_4 ( V_2 , L_16 , V_62 ) ;
F_4 ( V_2 , L_17 , V_61 ) ;
V_7 -> V_46 = 9 ;
V_7 -> V_42 = 0 ;
V_7 -> V_41 = 16 ;
V_7 -> V_48 = 4 ;
V_7 -> V_65 = 15 ;
switch ( V_62 ) {
case 0x6e :
case 0xe8 :
case 0xec :
V_7 -> V_46 = 8 ;
V_7 -> V_42 = 1 ;
return 0x00100000 ;
case 0xea :
case 0x64 :
V_7 -> V_46 = 8 ;
V_7 -> V_42 = 1 ;
case 0x5d :
return 0x00200000 ;
case 0xe3 :
case 0xe5 :
case 0x6b :
case 0xd5 :
return 0x00400000 ;
case 0xe6 :
case 0xd6 :
return 0x00800000 ;
case 0x73 :
V_7 -> V_41 = 32 ;
V_7 -> V_48 = 5 ;
V_7 -> V_65 = 31 ;
return 0x01000000 ;
case 0x75 :
V_7 -> V_41 = 32 ;
V_7 -> V_48 = 5 ;
V_7 -> V_65 = 31 ;
return 0x02000000 ;
case 0x76 :
V_7 -> V_41 = 32 ;
V_7 -> V_48 = 5 ;
V_7 -> V_65 = 31 ;
return 0x04000000 ;
case 0x79 :
V_7 -> V_41 = 32 ;
V_7 -> V_48 = 5 ;
V_7 -> V_65 = 31 ;
return 0x08000000 ;
default:
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 ) {
struct V_6 * V_7 = (struct V_6 * ) ( V_2 -> V_8 ) ;
int V_66 ;
unsigned char * V_34 ;
unsigned char * V_17 = V_2 -> V_18 ;
int V_53 ;
unsigned short V_31 ;
unsigned short V_67 ;
int V_16 ;
if ( ! V_7 -> V_68 )
return - 1 ;
V_66 = V_7 -> V_68 >> ( V_7 -> V_48 + V_7 -> V_46 ) ;
V_34 = F_9 ( V_66 * 2 , V_44 ) ;
if ( ! V_34 )
return - 1 ;
memset ( V_17 , 0 , 8 ) ;
V_17 [ 5 ] = 0xB0 ;
V_17 [ 6 ] = V_66 * 2 / 256 ;
V_17 [ 7 ] = 0x8A ;
V_16 = F_1 ( V_2 , V_20 , V_17 , 8 ) ;
if ( V_16 != V_13 ) {
F_6 ( V_34 ) ;
return - 1 ;
}
V_16 = F_1 ( V_2 , V_10 , V_34 , V_66 * 2 ) ;
if ( V_16 != V_13 ) {
F_6 ( V_34 ) ;
return - 1 ;
}
V_16 = F_1 ( V_2 , V_10 , V_17 , 2 ) ;
if ( V_16 != V_13 ) {
F_6 ( V_34 ) ;
return - 1 ;
}
F_6 ( V_7 -> V_24 ) ;
F_6 ( V_7 -> V_25 ) ;
V_7 -> V_24 = F_9 ( V_66 * sizeof( int ) , V_44 ) ;
V_7 -> V_25 = F_9 ( V_66 * sizeof( int ) , V_44 ) ;
if ( V_7 -> V_24 == NULL || V_7 -> V_25 == NULL ) {
F_6 ( V_7 -> V_24 ) ;
F_6 ( V_7 -> V_25 ) ;
V_7 -> V_24 = NULL ;
V_7 -> V_25 = NULL ;
F_6 ( V_34 ) ;
return - 1 ;
}
memset ( V_7 -> V_24 , 0xff , V_66 * sizeof( int ) ) ;
memset ( V_7 -> V_25 , 0xff , V_66 * sizeof( int ) ) ;
V_67 = V_7 -> V_45 ;
if ( V_67 > 1000 )
V_67 = 1000 ;
for ( V_53 = 0 ; V_53 < V_66 ; V_53 ++ ) {
int V_69 = V_53 / 1024 ;
V_31 = F_19 ( V_34 [ V_53 * 2 ] , V_34 [ V_53 * 2 + 1 ] ) ;
V_7 -> V_25 [ V_53 ] = V_31 ;
if ( V_31 >= V_67 ) {
continue;
}
if ( V_7 -> V_24 [ V_31 + V_69 * 1000 ] != V_47 &&
! V_7 -> V_27 ) {
F_14 ( V_70
L_18 ,
V_31 + V_69 * 1000 ) ;
V_7 -> V_27 = 1 ;
}
if ( V_31 < 0x10 || ( V_31 >= 0x3E0 && V_31 < 0x3EF ) )
F_4 ( V_2 , L_19 , V_31 , V_53 ) ;
V_7 -> V_24 [ V_31 + V_69 * 1000 ] = V_53 ;
}
F_6 ( V_34 ) ;
return 0 ;
}
static void F_20 ( void * V_8 ) {
struct V_6 * V_7 = (struct V_6 * ) V_8 ;
if ( ! V_8 )
return;
F_6 ( V_7 -> V_24 ) ;
F_6 ( V_7 -> V_25 ) ;
}
static int F_21 ( struct V_71 * V_50 , struct V_1 * V_2 )
{
int V_16 ;
static unsigned char V_72 [ 8 ] = {
0x00 , 0x80 , 0x00 , 0x02 , 0x1F , 0x00 , 0x00 , 0x00
} ;
static unsigned char V_73 [ 20 ] = {
0x0 , 0x12 , 0x00 , 0x80 , 0x0 , 0x0 , 0x0 , 0x0 ,
0x01 , 0x0A ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned char * V_74 = V_2 -> V_18 ;
unsigned long V_68 ;
unsigned int V_31 ;
unsigned int V_35 ;
unsigned int V_32 ;
unsigned short V_37 ;
struct V_6 * V_7 ;
if ( ! V_2 -> V_8 ) {
V_2 -> V_8 = F_22 (
sizeof( struct V_6 ) , V_44 ) ;
if ( ! V_2 -> V_8 )
return V_21 ;
V_2 -> V_75 = F_20 ;
}
V_7 = (struct V_6 * ) ( V_2 -> V_8 ) ;
if ( V_50 -> V_76 [ 0 ] == V_77 ) {
F_4 ( V_2 , L_20 ,
V_7 -> V_78 [ 2 ] ,
V_7 -> V_78 [ 12 ] ,
V_7 -> V_78 [ 13 ] ) ;
memcpy ( V_74 , V_7 -> V_78 , sizeof V_7 -> V_78 ) ;
V_74 [ 0 ] = 0x70 ;
V_74 [ 7 ] = 11 ;
F_23 ( V_74 , sizeof V_7 -> V_78 , V_50 ) ;
memset ( V_7 -> V_78 , 0 , sizeof V_7 -> V_78 ) ;
return V_30 ;
}
memset ( V_7 -> V_78 , 0 , sizeof V_7 -> V_78 ) ;
if ( V_50 -> V_76 [ 0 ] == V_79 ) {
memcpy ( V_74 , V_72 , 8 ) ;
F_24 ( V_2 , V_74 , 36 ) ;
return V_30 ;
}
if ( V_7 -> V_24 == NULL || F_25 ( V_15 , V_7 -> V_14 + V_80 / 2 ) ) {
V_16 = F_3 ( V_2 ) ;
if ( V_16 ) {
V_16 = F_3 ( V_2 ) ;
if ( ! V_16 ) {
F_5 ( 6 , 0x28 , 0 ) ;
}
return V_28 ;
}
}
if ( V_7 -> V_26 ) {
F_5 ( 3 , 0x31 , 0 ) ;
return V_28 ;
}
if ( V_50 -> V_76 [ 0 ] == V_81 ) {
V_68 = F_17 ( V_2 ) ;
if ( ! V_68 ) {
F_5 ( 3 , 0x30 , 0 ) ;
return V_28 ;
}
V_7 -> V_68 = V_68 ;
V_7 -> V_45 = ( ( V_7 -> V_68 >> ( V_7 -> V_46 + V_7 -> V_48 ) ) / 256 ) * 250 ;
V_68 = ( V_68 / 256 ) * 250 ;
V_68 /= V_43 ;
V_68 -- ;
( ( V_82 * ) V_74 ) [ 0 ] = F_26 ( V_68 ) ;
( ( V_82 * ) V_74 ) [ 1 ] = F_26 ( V_43 ) ;
F_23 ( V_74 , 8 , V_50 ) ;
F_18 ( V_2 ) ;
return V_30 ;
}
if ( V_50 -> V_76 [ 0 ] == V_83 ) {
memcpy ( V_74 , V_73 , sizeof V_73 ) ;
V_74 [ 3 ] = ( V_7 -> V_29 || V_7 -> V_27 ) ? 0x80 : 0 ;
F_23 ( V_74 , sizeof( V_73 ) , V_50 ) ;
if ( ( V_50 -> V_76 [ 2 ] & 0x3F ) == 0x01 ) {
F_4 ( V_2 , L_21 ) ;
return V_30 ;
} else if ( ( V_50 -> V_76 [ 2 ] & 0x3F ) == 0x3F ) {
F_4 ( V_2 , L_22 ) ;
return V_30 ;
}
F_5 ( 5 , 0x24 , 0 ) ;
return V_28 ;
}
if ( V_50 -> V_76 [ 0 ] == V_84 ) {
F_4 ( V_2 , L_23 ,
( V_50 -> V_76 [ 4 ] & 0x03 ) ? L_24 : L_25 ) ;
return V_30 ;
}
if ( V_50 -> V_76 [ 0 ] == V_85 || V_50 -> V_76 [ 0 ] == V_86 ) {
V_32 = F_19 ( V_50 -> V_76 [ 3 ] , V_50 -> V_76 [ 2 ] ) ;
V_32 <<= 16 ;
V_32 |= F_19 ( V_50 -> V_76 [ 5 ] , V_50 -> V_76 [ 4 ] ) ;
V_37 = F_19 ( V_50 -> V_76 [ 8 ] , V_50 -> V_76 [ 7 ] ) ;
V_32 <<= V_7 -> V_42 ;
V_31 = V_32 >> V_7 -> V_48 ;
V_32 = V_32 & V_7 -> V_65 ;
if ( V_31 >= V_7 -> V_45 ) {
F_4 ( V_2 , L_26 ,
V_31 , V_7 -> V_45 - 1 ) ;
F_5 ( 5 , 0x24 , 0 ) ;
return V_28 ;
}
V_35 = V_7 -> V_24 [ V_31 ] ;
if ( V_50 -> V_76 [ 0 ] == V_86 ) {
F_4 ( V_2 , L_27 ,
V_35 , V_31 , V_32 , V_37 ) ;
return F_12 ( V_2 , V_31 , V_32 , V_37 ) ;
} else {
F_4 ( V_2 , L_28 ,
V_35 , V_31 , V_32 , V_37 ) ;
return F_7 ( V_2 , V_31 , V_32 , V_37 ) ;
}
}
if ( V_50 -> V_76 [ 0 ] == V_87 ) {
return V_30 ;
}
if ( V_50 -> V_76 [ 0 ] == V_88 ) {
return V_30 ;
}
F_5 ( 5 , 0x20 , 0 ) ;
return V_28 ;
}
static int F_27 ( struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_28 ( & V_2 , V_90 , V_92 ,
( V_92 - V_93 ) + V_94 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_95 = L_29 ;
V_2 -> V_96 = F_21 ;
V_2 -> V_97 = F_16 ;
V_2 -> V_98 = 0 ;
V_16 = F_29 ( V_2 ) ;
return V_16 ;
}
