static struct V_1 * F_1 ( unsigned char V_2 ) {
int V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_2 != 0 ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & ( V_4 [ V_3 ] ) ;
return NULL ;
}
static void F_2 ( void ) {
int V_3 , V_5 , V_6 ;
V_7 [ 0 ] = 0 ;
for ( V_3 = 1 ; V_3 < 256 ; V_3 ++ )
V_7 [ V_3 ] = ( V_7 [ V_3 & ( V_3 - 1 ) ] ^ 1 ) ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ ) {
V_6 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_3 & ( 1 << V_5 ) ) {
if ( ( V_5 & 1 ) == 0 )
V_6 ^= 0x04 ;
if ( ( V_5 & 2 ) == 0 )
V_6 ^= 0x10 ;
if ( ( V_5 & 4 ) == 0 )
V_6 ^= 0x40 ;
}
}
V_8 [ V_3 ] = ~ ( V_6 ^ ( V_6 << 1 ) ^ ( V_7 [ V_3 ] ? 0xa8 : 0 ) ) ;
}
}
static void F_3 ( unsigned char * V_9 , unsigned char * V_10 ) {
int V_3 , V_5 , V_6 ;
unsigned char V_11 = 0 , V_12 , V_13 [ 8 ] = { 0 } ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ ) {
V_11 ^= V_9 [ V_3 ] ;
V_12 = V_7 [ V_9 [ V_3 ] ] ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
if ( ( V_3 & ( 1 << V_5 ) ) == 0 )
V_13 [ V_5 ] ^= V_12 ;
}
V_6 = ( V_13 [ 3 ] << 6 ) + ( V_13 [ 2 ] << 4 ) + ( V_13 [ 1 ] << 2 ) + V_13 [ 0 ] ;
V_10 [ 0 ] = ~ ( V_6 ^ ( V_6 << 1 ) ^ ( V_7 [ V_11 ] ? 0xaa : 0 ) ) ;
V_6 = ( V_13 [ 7 ] << 6 ) + ( V_13 [ 6 ] << 4 ) + ( V_13 [ 5 ] << 2 ) + V_13 [ 4 ] ;
V_10 [ 1 ] = ~ ( V_6 ^ ( V_6 << 1 ) ^ ( V_7 [ V_11 ] ? 0xaa : 0 ) ) ;
V_10 [ 2 ] = V_8 [ V_11 ] ;
}
static int F_4 ( unsigned char * V_9 , unsigned char * V_10 ) {
return ( V_9 [ 0 ] == V_10 [ 0 ] && V_9 [ 1 ] == V_10 [ 1 ] && V_9 [ 2 ] == V_10 [ 2 ] ) ;
}
static void F_5 ( unsigned char * V_9 , unsigned char * V_10 ) {
memcpy ( V_9 , V_10 , 3 ) ;
}
static void F_6 ( struct V_14 * V_15 )
{
unsigned int V_16 = V_15 -> V_17
+ V_15 -> V_18 + V_15 -> V_19 ;
unsigned int V_20 = V_15 -> V_21 >> V_16 ;
unsigned int V_3 ;
if ( V_15 -> V_22 != NULL )
for ( V_3 = 0 ; V_3 < V_20 ; V_3 ++ ) {
F_7 ( V_15 -> V_22 [ V_3 ] ) ;
V_15 -> V_22 [ V_3 ] = NULL ;
}
if ( V_15 -> V_23 != NULL )
for ( V_3 = 0 ; V_3 < V_20 ; V_3 ++ ) {
F_7 ( V_15 -> V_23 [ V_3 ] ) ;
V_15 -> V_23 [ V_3 ] = NULL ;
}
}
static int F_8 ( struct V_24 * V_25 , unsigned char * V_9 )
{
int V_26 ;
unsigned char V_27 ;
if ( F_9 ( V_25 ) == V_28 )
V_27 = V_29 ;
else
V_27 = V_30 ;
V_26 = F_10 ( V_25 , V_25 -> V_31 ,
V_27 , 0xc0 , 0 , 1 , V_9 , 2 ) ;
F_11 ( V_25 , L_1 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
return V_26 ;
}
static int F_12 ( struct V_24 * V_25 )
{
unsigned char V_27 ;
if ( F_9 ( V_25 ) == V_28 )
V_27 = V_32 ;
else
V_27 = V_33 ;
return F_10 ( V_25 , V_25 -> V_34 ,
V_27 , 0x40 , 0 , 1 , NULL , 0 ) ;
}
static int F_13 ( struct V_24 * V_25 , unsigned char * V_9 )
{
unsigned char V_27 ;
if ( F_9 ( V_25 ) == V_28 )
V_27 = V_35 ;
else
V_27 = V_36 ;
return F_10 ( V_25 , V_25 -> V_31 ,
V_27 , 0xc0 , 0 , 0 , V_9 , 4 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
unsigned char * V_27 = V_25 -> V_37 ;
memset ( V_27 , 0 , 9 ) ;
V_27 [ 0 ] = V_38 ;
V_27 [ 1 ] = V_39 ;
V_27 [ 8 ] = F_9 ( V_25 ) ;
return F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
}
static int F_16 ( struct V_24 * V_25 )
{
unsigned char * V_9 = V_25 -> V_37 ;
int V_41 = 0 ;
struct V_1 * V_15 ;
unsigned int V_20 ;
while ( V_41 == 0 ) {
F_17 ( 20 ) ;
if ( F_8 ( V_25 , V_9 ) != V_42 )
return V_43 ;
if ( V_9 [ 0 ] & 0x10 )
V_41 = 1 ;
}
F_11 ( V_25 , L_2 ) ;
if ( F_12 ( V_25 ) != V_42 )
return V_43 ;
F_17 ( 10 ) ;
if ( F_8 ( V_25 , V_9 ) != V_42 )
return V_43 ;
if ( V_9 [ 0 ] != 0x14 ) {
F_11 ( V_25 , L_3 ) ;
return V_43 ;
}
if ( F_13 ( V_25 , V_9 ) != V_42 )
return V_43 ;
F_11 ( V_25 , L_4 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] ) ;
V_15 = F_1 ( V_9 [ 1 ] ) ;
if ( V_15 == NULL ) {
F_18 ( V_44
L_5
L_6 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] ) ;
return V_43 ;
}
F_19 ( V_25 ) . V_21 = 1 << V_15 -> V_45 ;
F_11 ( V_25 , L_7 ,
F_19 ( V_25 ) . V_21 >> 20 ) ;
F_19 ( V_25 ) . V_19 = V_15 -> V_19 ;
F_19 ( V_25 ) . V_18 = V_15 -> V_18 ;
F_19 ( V_25 ) . V_17 = V_15 -> V_17 ;
F_19 ( V_25 ) . V_46 = 1 << V_15 -> V_19 ;
F_19 ( V_25 ) . V_47 = 1 << V_15 -> V_18 ;
F_19 ( V_25 ) . V_48 = 1 << V_15 -> V_17 ;
F_19 ( V_25 ) . V_49 = ( ( 1 << V_15 -> V_17 ) / 128 ) * 125 ;
F_19 ( V_25 ) . V_50 = F_19 ( V_25 ) . V_47 - 1 ;
V_20 = F_19 ( V_25 ) . V_21 >> ( F_19 ( V_25 ) . V_17
+ F_19 ( V_25 ) . V_18 + F_19 ( V_25 ) . V_19 ) ;
F_19 ( V_25 ) . V_23 = F_20 ( V_20 , sizeof( V_51 * ) , V_52 ) ;
F_19 ( V_25 ) . V_22 = F_20 ( V_20 , sizeof( V_51 * ) , V_52 ) ;
if ( F_14 ( V_25 ) != V_42 )
return V_43 ;
return V_53 ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_54 * V_55 = (struct V_54 * ) V_25 -> V_56 ;
unsigned char V_57 [ 2 ] ;
int V_26 ;
V_26 = F_8 ( V_25 , V_57 ) ;
if ( ( V_57 [ 0 ] & 0x80 ) || ( ( V_57 [ 0 ] & 0x1F ) == 0x10 )
|| ( ( V_57 [ 1 ] & 0x01 ) == 0 ) ) {
F_11 ( V_25 , L_8 ) ;
F_6 ( & F_19 ( V_25 ) ) ;
V_55 -> V_58 = 0x02 ;
V_55 -> V_59 = 0x3A ;
V_55 -> V_60 = 0x00 ;
return V_61 ;
}
if ( V_57 [ 0 ] & 0x08 ) {
F_11 ( V_25 , L_9 ) ;
F_6 ( & F_19 ( V_25 ) ) ;
F_16 ( V_25 ) ;
V_55 -> V_58 = V_62 ;
V_55 -> V_59 = 0x28 ;
V_55 -> V_60 = 0x00 ;
return V_61 ;
}
return V_53 ;
}
static int F_22 ( struct V_24 * V_25 )
{
int V_26 ;
unsigned char V_27 [] = {
V_38 , V_63 ,
0 , 0 , 0 , 0 , 3 , 0 , F_9 (us)
} ;
unsigned char V_9 [ 3 ] ;
V_26 = F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
V_26 = F_15 ( V_25 , V_25 -> V_64 ,
V_9 , 3 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
F_11 ( V_25 , L_10 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] ) ;
if ( V_9 [ 0 ] & V_65 )
return V_66 ;
return V_42 ;
}
static int F_23 ( struct V_24 * V_25 , V_51 V_67 , unsigned char * V_9 )
{
int V_26 ;
unsigned char V_27 [] = {
V_38 , V_68 ,
F_24 ( V_67 ) , F_25 ( V_67 ) , 0 , F_26 ( V_67 ) , 0 , 0 , F_9 (us)
} ;
V_26 = F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
return F_15 ( V_25 , V_25 -> V_64 ,
V_9 , 16 , NULL ) ;
}
static V_51 F_27 ( struct V_14 * V_55 ,
unsigned int V_69 )
{
V_51 * V_23 = V_55 -> V_23 [ V_69 ] ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_55 -> V_48 ; V_3 ++ )
if ( V_23 [ V_3 ] == UNDEF )
return ( V_69 << V_55 -> V_17 ) + V_3 ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 , unsigned int V_69 )
{
unsigned char * V_9 = V_25 -> V_37 ;
int V_70 ;
int V_3 , V_5 ;
unsigned int V_48 = F_19 ( V_25 ) . V_48 ;
unsigned int V_49 = F_19 ( V_25 ) . V_49 ;
unsigned int V_71 , V_72 , V_73 ;
unsigned int V_74 = V_69 * V_49 ;
unsigned int V_75 = V_69 * V_48 ;
V_51 * V_22 = F_20 ( V_48 , sizeof( V_51 ) , V_52 ) ;
V_51 * V_23 = F_20 ( V_48 , sizeof( V_51 ) , V_52 ) ;
if ( V_22 == NULL || V_23 == NULL ) {
V_70 = V_43 ;
goto error;
}
F_11 ( V_25 , L_11 , V_69 ) ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
V_22 [ V_3 ] = V_23 [ V_3 ] = UNDEF ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
V_73 = V_75 + V_3 ;
V_70 = F_23 ( V_25 , V_73 , V_9 ) ;
if ( V_70 != V_42 ) {
V_70 = V_43 ;
goto error;
}
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ )
if ( V_9 [ V_5 ] != 0 )
goto V_76;
V_23 [ V_3 ] = V_77 ;
F_11 ( V_25 , L_12 , V_73 ) ;
continue;
V_76:
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ )
if ( V_9 [ V_5 ] != 0xff )
goto V_78;
continue;
V_78:
if ( V_5 < 6 ) {
F_11 ( V_25 , L_13 ,
V_73 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_23 [ V_3 ] = V_77 ;
continue;
}
if ( ( V_9 [ 6 ] >> 4 ) != 0x01 ) {
F_11 ( V_25 , L_14 ,
V_73 , V_9 [ 6 ] , V_9 [ 7 ] ,
V_9 [ 11 ] , V_9 [ 12 ] ) ;
V_23 [ V_3 ] = V_77 ;
continue;
}
if ( V_7 [ V_9 [ 6 ] ^ V_9 [ 7 ] ] ) {
F_18 ( V_44
L_15
L_16 , V_3 , V_9 [ 6 ] , V_9 [ 7 ] ) ;
V_23 [ V_3 ] = V_77 ;
continue;
}
V_71 = F_29 ( V_9 [ 7 ] , V_9 [ 6 ] ) ;
V_71 = ( V_71 & 0x07FF ) >> 1 ;
V_72 = V_71 + V_74 ;
if ( V_71 >= V_49 ) {
F_18 ( V_44
L_17 ,
V_72 , V_73 ) ;
continue;
}
if ( V_22 [ V_71 ] != UNDEF ) {
F_18 ( V_44
L_18
L_19 ,
V_72 , V_22 [ V_71 ] , V_73 ) ;
continue;
}
V_23 [ V_3 ] = V_72 ;
V_22 [ V_71 ] = V_73 ;
continue;
}
F_19 ( V_25 ) . V_22 [ V_69 ] = V_22 ;
F_19 ( V_25 ) . V_23 [ V_69 ] = V_23 ;
V_70 = 0 ;
goto V_79;
error:
F_7 ( V_22 ) ;
F_7 ( V_23 ) ;
V_79:
return V_70 ;
}
static void F_30 ( struct V_24 * V_25 , unsigned int V_69 )
{
if ( F_19 ( V_25 ) . V_22 [ V_69 ] == NULL
|| F_19 ( V_25 ) . V_23 [ V_69 ] == NULL )
F_28 ( V_25 , V_69 ) ;
}
static int F_31 ( struct V_24 * V_25 , V_51 V_67 )
{
int V_26 ;
unsigned char V_27 [] = {
V_38 , V_80 , F_24 ( V_67 ) ,
F_25 ( V_67 ) , 0 , F_26 ( V_67 ) , 0x02 , 0 , F_9 (us)
} ;
unsigned char V_81 [ 2 ] ;
F_11 ( V_25 , L_20 , V_67 ) ;
V_26 = F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
V_26 = F_15 ( V_25 , V_25 -> V_64 ,
V_81 , 2 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
F_11 ( V_25 , L_21 , V_81 [ 0 ] , V_81 [ 1 ] ) ;
return V_26 ;
}
static int F_32 ( struct V_24 * V_25 , V_51 V_67 ,
unsigned int V_82 , unsigned int V_83 , unsigned char * V_9 )
{
int V_26 ;
unsigned char V_27 [] = {
V_38 , V_84 , F_24 ( V_67 ) ,
F_25 ( V_67 ) , 0 , F_26 ( V_67 ) + V_82 , V_83 , 0 , F_9 (us)
} ;
F_11 ( V_25 , L_22 , V_67 , V_82 , V_83 ) ;
V_26 = F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
return F_15 ( V_25 , V_25 -> V_64 ,
V_9 , ( F_19 ( V_25 ) . V_46 + 64 ) * V_83 , NULL ) ;
}
static int F_33 ( struct V_24 * V_25 , V_51 V_67 ,
unsigned int V_82 , unsigned int V_83 , unsigned char * V_9 )
{
int V_3 , V_26 ;
unsigned int V_46 = F_19 ( V_25 ) . V_46 ;
V_26 = F_32 ( V_25 , V_67 , V_82 , V_83 , V_9 ) ;
if ( V_26 != V_42 )
return V_26 ;
for ( V_3 = 0 ; V_3 < V_83 ; V_3 ++ ) {
int V_85 = V_3 * V_46 ;
int V_86 = V_3 * ( V_46 + 64 ) ;
memmove ( V_9 + V_85 , V_9 + V_86 , V_46 ) ;
}
return V_26 ;
}
static int F_34 ( struct V_24 * V_25 , V_51 V_67 , unsigned char * V_9 )
{
int V_26 ;
struct V_54 * V_55 = (struct V_54 * ) V_25 -> V_56 ;
unsigned char V_27 [] = {
V_38 , V_87 , F_24 ( V_67 ) ,
F_25 ( V_67 ) , 0 , F_26 ( V_67 ) , 32 , 0 , F_9 (us)
} ;
F_11 ( V_25 , L_23 , V_67 ) ;
V_26 = F_15 ( V_25 , V_25 -> V_40 ,
V_27 , 9 , NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
V_26 = F_15 ( V_25 , V_55 -> V_88 , V_9 ,
( F_19 ( V_25 ) . V_46 + 64 ) * F_19 ( V_25 ) . V_47 ,
NULL ) ;
if ( V_26 != V_42 )
return V_26 ;
return F_22 ( V_25 ) ;
}
static int F_35 ( struct V_24 * V_25 , V_51 V_89 ,
unsigned int V_82 , unsigned int V_83 ,
unsigned char * V_90 , unsigned char * V_91 )
{
V_51 V_67 , V_92 , V_93 ;
unsigned char * V_94 , * V_95 , * V_96 ;
unsigned char V_10 [ 3 ] ;
int V_3 , V_70 ;
unsigned int V_49 = F_19 ( V_25 ) . V_49 ;
unsigned int V_48 = F_19 ( V_25 ) . V_48 ;
unsigned int V_46 = F_19 ( V_25 ) . V_46 ;
unsigned int V_47 = F_19 ( V_25 ) . V_47 ;
unsigned int V_71 = V_89 % V_49 ;
unsigned int V_97 ;
unsigned int V_69 = V_89 / V_49 ;
F_30 ( V_25 , V_69 ) ;
V_67 = F_19 ( V_25 ) . V_22 [ V_69 ] [ V_71 ] ;
if ( V_67 == 1 ) {
F_18 ( V_44
L_24 ) ;
return V_53 ;
}
V_93 = F_27 ( & F_19 ( V_25 ) , V_69 ) ;
if ( ! V_93 ) {
F_18 ( V_44
L_25 ) ;
return V_43 ;
}
if ( V_67 != UNDEF ) {
V_70 = F_32 ( V_25 , V_67 , 0 ,
V_47 , V_91 ) ;
if ( V_70 != V_42 )
return V_70 ;
} else {
memset ( V_91 , 0 , V_47 * ( V_46 + 64 ) ) ;
}
V_92 = ( V_71 << 1 ) | 0x1000 ;
if ( V_7 [ F_36 ( V_92 ) ^ F_37 ( V_92 ) ] )
V_92 ^= 1 ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
V_94 = V_91 + ( V_3 * ( V_46 + 64 ) ) ;
V_95 = V_94 + V_46 ;
F_3 ( V_94 , V_10 ) ;
if ( ! F_4 ( V_95 + 13 , V_10 ) ) {
F_11 ( V_25 , L_26 ,
V_3 , V_67 ) ;
F_5 ( V_95 + 13 , V_10 ) ;
}
F_3 ( V_94 + ( V_46 / 2 ) , V_10 ) ;
if ( ! F_4 ( V_95 + 8 , V_10 ) ) {
F_11 ( V_25 , L_27 ,
V_3 , V_67 ) ;
F_5 ( V_95 + 8 , V_10 ) ;
}
V_95 [ 6 ] = V_95 [ 11 ] = F_36 ( V_92 ) ;
V_95 [ 7 ] = V_95 [ 12 ] = F_37 ( V_92 ) ;
}
V_96 = V_90 ;
for ( V_3 = V_82 ; V_3 < V_82 + V_83 ; V_3 ++ ) {
V_94 = V_91 + ( V_3 * ( V_46 + 64 ) ) ;
V_95 = V_94 + V_46 ;
memcpy ( V_94 , V_96 , V_46 ) ;
V_96 += V_46 ;
F_3 ( V_94 , V_10 ) ;
F_5 ( V_95 + 13 , V_10 ) ;
F_3 ( V_94 + ( V_46 / 2 ) , V_10 ) ;
F_5 ( V_95 + 8 , V_10 ) ;
}
V_70 = F_34 ( V_25 , V_93 , V_91 ) ;
if ( V_70 != V_42 )
return V_70 ;
V_97 = V_93 - ( V_69 * V_48 ) ;
F_19 ( V_25 ) . V_23 [ V_69 ] [ V_97 ] = V_89 ;
F_19 ( V_25 ) . V_22 [ V_69 ] [ V_71 ] = V_93 ;
F_11 ( V_25 , L_28 , V_89 , V_93 ) ;
if ( V_67 != UNDEF ) {
unsigned int V_98 = V_67 - ( V_69 * V_48 ) ;
V_70 = F_31 ( V_25 , V_67 ) ;
if ( V_70 != V_42 )
return V_70 ;
F_19 ( V_25 ) . V_23 [ V_69 ] [ V_98 ] = UNDEF ;
}
return V_53 ;
}
static int F_38 ( struct V_24 * V_25 , unsigned long V_99 ,
unsigned int V_100 )
{
unsigned char * V_101 ;
V_51 V_89 , V_102 ;
unsigned int V_82 , V_103 , V_104 ;
unsigned int V_18 = F_19 ( V_25 ) . V_18 ;
unsigned int V_19 = F_19 ( V_25 ) . V_19 ;
unsigned int V_47 = F_19 ( V_25 ) . V_47 ;
unsigned int V_46 = F_19 ( V_25 ) . V_46 ;
unsigned int V_49 = F_19 ( V_25 ) . V_49 ;
struct V_105 * V_106 ;
int V_70 ;
V_103 = F_39 ( V_100 , V_47 ) * ( V_46 + 64 ) ;
V_101 = F_40 ( V_103 , V_52 ) ;
if ( V_101 == NULL ) {
F_18 ( V_44 L_29 ) ;
return V_43 ;
}
V_89 = V_99 >> V_18 ;
V_82 = ( V_99 & F_19 ( V_25 ) . V_50 ) ;
V_102 = F_19 ( V_25 ) . V_21 >> ( V_18 + V_19 ) ;
V_70 = V_53 ;
V_104 = 0 ;
V_106 = NULL ;
while ( V_100 > 0 ) {
unsigned int V_69 = V_89 / V_49 ;
unsigned int V_71 = V_89 - ( V_69 * V_49 ) ;
unsigned int V_83 ;
V_51 V_67 ;
F_30 ( V_25 , V_69 ) ;
if ( V_89 >= V_102 ) {
F_11 ( V_25 , L_30 ,
V_89 , V_102 ) ;
V_70 = V_43 ;
break;
}
V_83 = F_39 ( V_100 , V_47 - V_82 ) ;
V_103 = V_83 << V_19 ;
V_67 = F_19 ( V_25 ) . V_22 [ V_69 ] [ V_71 ] ;
if ( V_67 == UNDEF ) {
F_11 ( V_25 , L_31 ,
V_83 , V_89 , V_82 ) ;
memset ( V_101 , 0 , V_103 ) ;
} else {
F_11 ( V_25 , L_32 ,
V_83 , V_67 , V_89 , V_82 ) ;
V_70 = F_33 ( V_25 , V_67 , V_82 , V_83 , V_101 ) ;
if ( V_70 != V_53 )
break;
}
F_41 ( V_101 , V_103 , V_25 -> V_107 ,
& V_106 , & V_104 , V_108 ) ;
V_82 = 0 ;
V_89 ++ ;
V_100 -= V_83 ;
}
F_7 ( V_101 ) ;
return V_70 ;
}
static int F_42 ( struct V_24 * V_25 , unsigned long V_99 ,
unsigned int V_100 )
{
unsigned char * V_101 , * V_91 ;
unsigned int V_82 , V_103 , V_104 ;
unsigned int V_18 = F_19 ( V_25 ) . V_18 ;
unsigned int V_19 = F_19 ( V_25 ) . V_19 ;
unsigned int V_47 = F_19 ( V_25 ) . V_47 ;
unsigned int V_46 = F_19 ( V_25 ) . V_46 ;
struct V_105 * V_106 ;
V_51 V_89 , V_102 ;
int V_70 ;
V_103 = F_39 ( V_100 , V_47 ) * V_46 ;
V_101 = F_40 ( V_103 , V_52 ) ;
if ( V_101 == NULL ) {
F_18 ( V_44 L_33 ) ;
return V_43 ;
}
V_91 = F_40 ( ( V_46 + 64 ) * V_47 , V_52 ) ;
if ( V_91 == NULL ) {
F_18 ( V_44 L_33 ) ;
F_7 ( V_101 ) ;
return V_43 ;
}
V_89 = V_99 >> V_18 ;
V_82 = ( V_99 & F_19 ( V_25 ) . V_50 ) ;
V_102 = F_19 ( V_25 ) . V_21 >> ( V_19 + V_18 ) ;
V_70 = V_53 ;
V_104 = 0 ;
V_106 = NULL ;
while ( V_100 > 0 ) {
unsigned int V_83 = F_39 ( V_100 , V_47 - V_82 ) ;
V_103 = V_83 << V_19 ;
if ( V_89 >= V_102 ) {
F_11 ( V_25 , L_34 ,
V_89 , V_102 ) ;
V_70 = V_43 ;
break;
}
F_41 ( V_101 , V_103 , V_25 -> V_107 ,
& V_106 , & V_104 , V_109 ) ;
V_70 = F_35 ( V_25 , V_89 , V_82 , V_83 , V_101 ,
V_91 ) ;
if ( V_70 != V_53 )
break;
V_82 = 0 ;
V_89 ++ ;
V_100 -= V_83 ;
}
F_7 ( V_101 ) ;
F_7 ( V_91 ) ;
return V_70 ;
}
static void F_43 ( void * V_56 )
{
struct V_54 * V_55 = (struct V_54 * ) V_56 ;
int V_110 ;
if ( ! V_55 )
return;
for ( V_110 = 0 ; V_110 < 2 ; V_110 ++ ) {
struct V_14 * V_15 = & V_55 -> V_110 [ V_110 ] ;
F_6 ( V_15 ) ;
F_7 ( V_15 -> V_22 ) ;
F_7 ( V_15 -> V_23 ) ;
}
}
static int F_44 ( struct V_24 * V_25 )
{
struct V_54 * V_55 ;
struct V_111 * V_112 = V_25 -> V_113 -> V_114 ;
F_2 () ;
V_25 -> V_56 = F_45 ( sizeof( struct V_54 ) , V_52 ) ;
if ( ! V_25 -> V_56 )
return V_43 ;
V_55 = (struct V_54 * ) V_25 -> V_56 ;
V_25 -> V_115 = F_43 ;
V_55 -> V_88 = F_46 ( V_25 -> V_116 ,
V_112 -> V_117 [ 0 ] . V_118 . V_119
& V_120 ) ;
return V_53 ;
}
static int F_47 ( struct V_121 * V_107 , struct V_24 * V_25 )
{
int V_26 ;
struct V_54 * V_55 = (struct V_54 * ) V_25 -> V_56 ;
unsigned char * V_90 = V_25 -> V_37 ;
static unsigned char V_122 [ 36 ] = {
0x00 , 0x80 , 0x00 , 0x01 , 0x1F , 0x00 , 0x00 , 0x00
} ;
if ( V_107 -> V_123 [ 0 ] == V_124 ) {
F_11 ( V_25 , L_35 ) ;
memcpy ( V_90 , V_122 , sizeof( V_122 ) ) ;
F_48 ( V_25 , V_90 , 36 ) ;
return V_53 ;
}
if ( V_107 -> V_123 [ 0 ] == V_125 ) {
F_11 ( V_25 , L_36 ) ;
return F_21 ( V_25 ) ;
}
if ( V_107 -> V_123 [ 0 ] == V_126 ) {
unsigned int V_20 ;
unsigned long V_21 ;
V_26 = F_21 ( V_25 ) ;
if ( V_26 != V_53 )
return V_26 ;
V_20 = F_19 ( V_25 ) . V_21 >> ( F_19 ( V_25 ) . V_17
+ F_19 ( V_25 ) . V_18 + F_19 ( V_25 ) . V_19 ) ;
V_21 = V_20 * F_19 ( V_25 ) . V_49
* F_19 ( V_25 ) . V_47 ;
( ( V_127 * ) V_90 ) [ 0 ] = F_49 ( V_21 - 1 ) ;
( ( V_127 * ) V_90 ) [ 1 ] = F_49 ( 512 ) ;
F_50 ( V_90 , 8 , V_107 ) ;
return V_53 ;
}
if ( V_107 -> V_123 [ 0 ] == V_128 ) {
unsigned int V_82 , V_83 ;
V_26 = F_21 ( V_25 ) ;
if ( V_26 != V_53 )
return V_26 ;
V_82 = F_29 ( V_107 -> V_123 [ 3 ] , V_107 -> V_123 [ 2 ] ) ;
V_82 <<= 16 ;
V_82 |= F_29 ( V_107 -> V_123 [ 5 ] , V_107 -> V_123 [ 4 ] ) ;
V_83 = F_29 ( V_107 -> V_123 [ 8 ] , V_107 -> V_123 [ 7 ] ) ;
F_11 ( V_25 , L_37 , V_82 , V_83 ) ;
return F_38 ( V_25 , V_82 , V_83 ) ;
}
if ( V_107 -> V_123 [ 0 ] == V_129 ) {
unsigned int V_82 , V_83 ;
V_26 = F_21 ( V_25 ) ;
if ( V_26 != V_53 )
return V_26 ;
V_82 = F_29 ( V_107 -> V_123 [ 3 ] , V_107 -> V_123 [ 2 ] ) ;
V_82 <<= 16 ;
V_82 |= F_29 ( V_107 -> V_123 [ 5 ] , V_107 -> V_123 [ 4 ] ) ;
V_83 = F_29 ( V_107 -> V_123 [ 8 ] , V_107 -> V_123 [ 7 ] ) ;
F_11 ( V_25 , L_38 , V_82 , V_83 ) ;
return F_42 ( V_25 , V_82 , V_83 ) ;
}
if ( V_107 -> V_123 [ 0 ] == V_130 ) {
F_11 ( V_25 , L_39 ) ;
memset ( V_90 , 0 , 18 ) ;
V_90 [ 0 ] = 0xF0 ;
V_90 [ 2 ] = V_55 -> V_58 ;
V_90 [ 7 ] = 11 ;
V_90 [ 12 ] = V_55 -> V_59 ;
V_90 [ 13 ] = V_55 -> V_60 ;
F_50 ( V_90 , 18 , V_107 ) ;
return V_53 ;
}
if ( V_107 -> V_123 [ 0 ] == V_131 ) {
return V_53 ;
}
F_11 ( V_25 , L_40 ,
V_107 -> V_123 [ 0 ] , V_107 -> V_123 [ 0 ] ) ;
V_55 -> V_58 = 0x05 ;
V_55 -> V_59 = 0x20 ;
V_55 -> V_60 = 0x00 ;
return V_61 ;
}
static int F_51 ( struct V_132 * V_133 ,
const struct V_134 * V_2 )
{
struct V_24 * V_25 ;
int V_70 ;
V_70 = F_52 ( & V_25 , V_133 , V_2 ,
( V_2 - V_135 ) + V_136 ) ;
if ( V_70 )
return V_70 ;
V_25 -> V_137 = L_41 ;
V_25 -> V_138 = F_47 ;
V_25 -> V_139 = V_140 ;
V_25 -> V_141 = 1 ;
V_70 = F_53 ( V_25 ) ;
return V_70 ;
}
