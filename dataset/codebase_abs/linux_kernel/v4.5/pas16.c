static void T_1
F_1 ( int V_1 , unsigned short V_2 )
{
F_2 ( 0xbc + V_1 , V_3 ) ;
F_2 ( V_2 >> 2 , V_3 ) ;
}
static void T_1
F_3 ( unsigned short V_4 , int V_5 , int V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
F_2 ( 0x30 , V_4 + V_9 ) ;
F_2 ( 0x01 , V_4 + V_10 ) ;
F_2 ( 0x01 , V_4 + V_11 ) ;
F_4 ( V_4 + V_12 [ V_13 ] ) ;
V_8 = ( V_5 < 16 ) ? V_14 [ V_5 ] : 0 ;
V_7 = F_4 ( V_4 + V_15 ) ;
if( ( ( V_7 & 0x0f ) == V_8 ) && V_8 > 0
&& ! V_6 )
{
F_5 ( L_1
L_2 ) ;
F_2 ( 0x4d , V_4 + V_16 ) ;
}
else
{
V_7 = ( V_7 & 0x0f ) | ( V_8 << 4 ) ;
F_2 ( V_7 , V_4 + V_15 ) ;
F_2 ( 0x6d , V_4 + V_16 ) ;
}
}
static int T_1
F_6 ( unsigned short V_1 )
{
unsigned char V_17 , V_7 ;
unsigned short V_4 = V_18 [ V_1 ] . V_4 ;
F_1 ( V_1 , V_4 ) ;
V_17 = F_4 ( V_4 + V_19 ) ;
if( V_17 == 0xff )
return 0 ;
V_7 = V_17 ^ 0xe0 ;
F_2 ( V_7 , V_4 + V_19 ) ;
V_7 = F_4 ( V_4 + V_19 ) ;
F_2 ( V_17 , V_4 + V_19 ) ;
if( V_17 != V_7 )
return 0 ;
if( ( F_4 ( V_4 + V_20 ) & 0x03 ) != 0x03 )
return 0 ;
F_2 ( 0x01 , V_4 + V_11 ) ;
F_2 ( 0x20 , V_4 + V_12 [ V_21 ] ) ;
if ( F_4 ( V_4 + V_12 [ V_21 ] ) != 0x20 )
return 0 ;
F_2 ( 0x00 , V_4 + V_12 [ V_21 ] ) ;
if ( F_4 ( V_4 + V_12 [ V_21 ] ) != 0x00 )
return 0 ;
return 1 ;
}
static int T_1 F_7 ( char * V_22 )
{
static int V_23 ;
int V_24 ;
int V_25 [ 10 ] ;
F_8 ( V_22 , F_9 ( V_25 ) , V_25 ) ;
if ( V_25 [ 0 ] != 2 )
F_5 ( L_3 ) ;
else
if ( V_23 < V_26 ) {
V_27 [ V_23 ] . V_4 = ( unsigned short ) V_25 [ 1 ] ;
V_27 [ V_23 ] . V_5 = V_25 [ 2 ] ;
for ( V_24 = 0 ; V_24 < V_28 ; ++ V_24 )
if ( V_18 [ V_24 ] . V_4 == ( unsigned short ) V_25 [ 1 ] ) {
V_18 [ V_24 ] . V_29 = 1 ;
break;
}
++ V_23 ;
}
return 1 ;
}
static int T_1 F_10 ( struct V_30 * V_31 )
{
static int V_32 ;
static unsigned short V_33 ;
struct V_34 * V_35 ;
unsigned short V_4 ;
int V_36 ;
if ( V_37 != 0 ) {
V_27 [ 0 ] . V_4 = V_37 ;
for ( V_36 = 0 ; V_36 < V_28 ; ++ V_36 )
if ( V_18 [ V_36 ] . V_4 == V_37 ) {
V_18 [ V_36 ] . V_29 = 1 ;
break;
}
}
if ( V_38 != 0 )
V_27 [ 0 ] . V_5 = V_38 ;
for ( V_36 = 0 ; V_32 < V_26 ; ++ V_32 ) {
V_4 = 0 ;
if ( V_27 [ V_32 ] . V_4 )
{
V_4 = V_27 [ V_32 ] . V_4 ;
F_1 ( V_32 , V_4 ) ;
F_3 ( V_4 , V_27 [ V_32 ] . V_5 , 1 ) ;
}
else
for (; ! V_4 && ( V_33 < V_28 ) ; ++ V_33 ) {
F_11 ( V_39 , L_4 ,
( unsigned int ) V_18 [ V_33 ] . V_4 ) ;
if ( ! V_18 [ V_33 ] . V_29 &&
F_6 ( V_33 ) ) {
V_4 = V_18 [ V_33 ] . V_4 ;
F_3 ( V_4 , V_40 [ V_33 ] , 0 ) ;
F_11 ( V_39 , L_5 ) ;
}
}
F_11 ( V_39 , L_6 ,
( unsigned int ) V_4 ) ;
if ( ! V_4 )
break;
V_35 = F_12 ( V_31 , sizeof( struct V_41 ) ) ;
if( V_35 == NULL )
goto V_42;
V_35 -> V_4 = V_4 ;
if ( F_13 ( V_35 , 0 ) )
goto V_43;
F_14 ( V_35 ) ;
if ( V_27 [ V_32 ] . V_5 != V_44 )
V_35 -> V_5 = V_27 [ V_32 ] . V_5 ;
else
V_35 -> V_5 = F_15 ( V_35 , V_45 ) ;
if ( V_35 -> V_5 == 255 )
V_35 -> V_5 = V_46 ;
if ( V_35 -> V_5 != V_46 )
if ( F_16 ( V_35 -> V_5 , V_47 , 0 ,
L_7 , V_35 ) ) {
F_5 ( L_8 ,
V_35 -> V_48 , V_35 -> V_5 ) ;
V_35 -> V_5 = V_46 ;
}
if ( V_35 -> V_5 == V_46 ) {
F_5 ( L_9 , V_35 -> V_48 ) ;
F_5 ( L_10 , V_35 -> V_48 ) ;
F_2 ( 0x4d , V_4 + V_16 ) ;
F_2 ( ( F_4 ( V_4 + V_15 ) & 0x0f ) , V_4 + V_15 ) ;
}
F_11 ( V_39 , L_11 ,
V_35 -> V_48 , V_35 -> V_5 ) ;
++ V_32 ;
++ V_36 ;
}
return V_36 ;
V_43:
F_17 ( V_35 ) ;
V_42:
return V_36 ;
}
static int F_18 ( struct V_49 * V_50 , struct V_51 * V_52 ,
T_2 V_53 , int * V_54 )
{
int V_55 = V_53 ;
V_54 [ 0 ] = 64 ;
V_54 [ 1 ] = 32 ;
V_54 [ 2 ] = V_55 >> 11 ;
if( V_54 [ 2 ] > 1024 ) {
V_54 [ 0 ] = 255 ;
V_54 [ 1 ] = 63 ;
V_54 [ 2 ] = V_55 / ( 63 * 255 ) ;
if( V_54 [ 2 ] > 1023 )
V_54 [ 2 ] = 1023 ;
}
return 0 ;
}
static inline int F_19 ( struct V_34 * V_35 , unsigned char * V_56 ,
int V_57 ) {
register unsigned char * V_58 = V_56 ;
register unsigned short V_59 = ( unsigned short ) ( V_35 -> V_4 +
V_60 ) ;
register int V_24 = V_57 ;
int V_61 = 0 ;
struct V_41 * V_62 = F_20 ( V_35 ) ;
while ( ! ( F_4 ( V_35 -> V_4 + V_63 ) & V_64 ) )
++ V_61 ;
F_21 ( V_59 , V_58 , V_24 ) ;
if ( F_4 ( V_35 -> V_4 + V_10 ) & V_65 ) {
F_2 ( V_66 , V_35 -> V_4 + V_10 ) ;
F_5 ( L_12 ,
V_35 -> V_48 ) ;
return - 1 ;
}
if ( V_61 > V_62 -> V_67 )
V_62 -> V_67 = V_61 ;
return 0 ;
}
static inline int F_22 ( struct V_34 * V_35 , unsigned char * V_68 ,
int V_57 ) {
register unsigned char * V_69 = V_68 ;
register unsigned short V_59 = ( V_35 -> V_4 + V_60 ) ;
register int V_24 = V_57 ;
int V_61 = 0 ;
struct V_41 * V_62 = F_20 ( V_35 ) ;
while ( ! ( ( F_4 ( V_35 -> V_4 + V_63 ) ) & V_64 ) )
++ V_61 ;
F_23 ( V_59 , V_69 , V_24 ) ;
if ( F_4 ( V_35 -> V_4 + V_10 ) & V_65 ) {
F_2 ( V_66 , V_35 -> V_4 + V_10 ) ;
F_5 ( L_13 ,
V_35 -> V_48 ) ;
return - 1 ;
}
if ( V_61 > V_62 -> V_70 )
V_62 -> V_70 = V_61 ;
return 0 ;
}
static int F_24 ( struct V_34 * V_71 )
{
if ( V_71 -> V_5 != V_46 )
F_25 ( V_71 -> V_5 , V_71 ) ;
F_26 ( V_71 ) ;
F_17 ( V_71 ) ;
return 0 ;
}
