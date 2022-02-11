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
F_4 ( V_12 ) ;
V_8 = ( V_5 < 16 ) ? V_13 [ V_5 ] : 0 ;
V_7 = F_5 ( V_4 + V_14 ) ;
if( ( ( V_7 & 0x0f ) == V_8 ) && V_8 > 0
&& ! V_6 )
{
F_6 ( L_1
L_2 ) ;
F_2 ( 0x4d , V_4 + V_15 ) ;
}
else
{
V_7 = ( V_7 & 0x0f ) | ( V_8 << 4 ) ;
F_2 ( V_7 , V_4 + V_14 ) ;
F_2 ( 0x6d , V_4 + V_15 ) ;
}
}
static int T_1
F_7 ( unsigned short V_1 )
{
unsigned char V_16 , V_7 ;
unsigned short V_4 = V_17 [ V_1 ] . V_4 ;
F_1 ( V_1 , V_4 ) ;
V_16 = F_5 ( V_4 + V_18 ) ;
if( V_16 == 0xff )
return 0 ;
V_7 = V_16 ^ 0xe0 ;
F_2 ( V_7 , V_4 + V_18 ) ;
V_7 = F_5 ( V_4 + V_18 ) ;
F_2 ( V_16 , V_4 + V_18 ) ;
if( V_16 != V_7 )
return 0 ;
if( ( F_5 ( V_4 + V_19 ) & 0x03 ) != 0x03 )
return 0 ;
F_2 ( 0x01 , V_4 + V_11 ) ;
F_8 ( V_20 , 0x20 ) ;
if( F_4 ( V_20 ) != 0x20 )
return 0 ;
F_8 ( V_20 , 0x00 ) ;
if( F_4 ( V_20 ) != 0x00 )
return 0 ;
return 1 ;
}
static int T_1 F_9 ( char * V_21 )
{
static int V_22 = 0 ;
int V_23 ;
int V_24 [ 10 ] ;
F_10 ( V_21 , F_11 ( V_24 ) , V_24 ) ;
if ( V_24 [ 0 ] != 2 )
F_6 ( L_3 ) ;
else
if ( V_22 < V_25 ) {
V_26 [ V_22 ] . V_4 = ( unsigned short ) V_24 [ 1 ] ;
V_26 [ V_22 ] . V_5 = V_24 [ 2 ] ;
for ( V_23 = 0 ; V_23 < V_27 ; ++ V_23 )
if ( V_17 [ V_23 ] . V_4 == ( unsigned short ) V_24 [ 1 ] ) {
V_17 [ V_23 ] . V_28 = 1 ;
break;
}
++ V_22 ;
}
return 1 ;
}
static int T_1 F_12 ( struct V_29 * V_30 )
{
static int V_31 = 0 ;
static unsigned short V_32 = 0 ;
struct V_33 * V_34 ;
unsigned short V_4 ;
int V_35 ;
if ( V_36 != 0 ) {
V_26 [ 0 ] . V_4 = V_36 ;
for ( V_35 = 0 ; V_35 < V_27 ; ++ V_35 )
if ( V_17 [ V_35 ] . V_4 == V_36 ) {
V_17 [ V_35 ] . V_28 = 1 ;
break;
}
}
if ( V_37 != 0 )
V_26 [ 0 ] . V_5 = V_37 ;
for ( V_35 = 0 ; V_31 < V_25 ; ++ V_31 ) {
V_4 = 0 ;
if ( V_26 [ V_31 ] . V_4 )
{
V_4 = V_26 [ V_31 ] . V_4 ;
F_1 ( V_31 , V_4 ) ;
F_3 ( V_4 , V_26 [ V_31 ] . V_5 , 1 ) ;
}
else
for (; ! V_4 && ( V_32 < V_27 ) ; ++ V_32 ) {
#if ( V_38 & V_39 )
F_6 ( L_4 , ( unsigned int ) V_17 [ V_32 ] . V_4 ) ;
#endif
if ( ! V_17 [ V_32 ] . V_28 &&
F_7 ( V_32 ) ) {
V_4 = V_17 [ V_32 ] . V_4 ;
F_3 ( V_4 , V_40 [ V_32 ] , 0 ) ;
#if ( V_38 & V_39 )
F_6 ( L_5 ) ;
#endif
}
}
#if F_13 ( V_38 ) && ( V_38 & V_39 )
F_6 ( L_6 , ( unsigned int ) V_4 ) ;
#endif
if ( ! V_4 )
break;
V_34 = F_14 ( V_30 , sizeof( struct V_41 ) ) ;
if( V_34 == NULL )
break;
V_34 -> V_4 = V_4 ;
F_15 ( V_34 , 0 ) ;
if ( V_26 [ V_31 ] . V_5 != V_42 )
V_34 -> V_5 = V_26 [ V_31 ] . V_5 ;
else
V_34 -> V_5 = F_16 ( V_34 , V_43 ) ;
if ( V_34 -> V_5 == 255 )
V_34 -> V_5 = V_44 ;
if ( V_34 -> V_5 != V_44 )
if ( F_17 ( V_34 -> V_5 , V_45 , 0 ,
L_7 , V_34 ) ) {
F_6 ( L_8 ,
V_34 -> V_46 , V_34 -> V_5 ) ;
V_34 -> V_5 = V_44 ;
}
if ( V_34 -> V_5 == V_44 ) {
F_6 ( L_9 , V_34 -> V_46 ) ;
F_6 ( L_10 , V_34 -> V_46 ) ;
F_2 ( 0x4d , V_4 + V_15 ) ;
F_2 ( ( F_5 ( V_4 + V_14 ) & 0x0f ) , V_4 + V_14 ) ;
}
#if F_13 ( V_38 ) && ( V_38 & V_39 )
F_6 ( L_11 , V_34 -> V_46 , V_34 -> V_5 ) ;
#endif
++ V_31 ;
++ V_35 ;
}
return V_35 ;
}
static int F_18 ( struct V_47 * V_48 , struct V_49 * V_50 ,
T_2 V_51 , int * V_52 )
{
int V_53 = V_51 ;
V_52 [ 0 ] = 64 ;
V_52 [ 1 ] = 32 ;
V_52 [ 2 ] = V_53 >> 11 ;
if( V_52 [ 2 ] > 1024 ) {
V_52 [ 0 ] = 255 ;
V_52 [ 1 ] = 63 ;
V_52 [ 2 ] = V_53 / ( 63 * 255 ) ;
if( V_52 [ 2 ] > 1023 )
V_52 [ 2 ] = 1023 ;
}
return 0 ;
}
static inline int F_19 ( struct V_33 * V_34 , unsigned char * V_54 ,
int V_55 ) {
register unsigned char * V_56 = V_54 ;
register unsigned short V_57 = ( unsigned short ) ( V_34 -> V_4 +
V_58 ) ;
register int V_23 = V_55 ;
int V_59 = 0 ;
struct V_41 * V_60 = F_20 ( V_34 ) ;
while ( ! ( F_5 ( V_34 -> V_4 + V_61 ) & V_62 ) )
++ V_59 ;
F_21 ( V_57 , V_56 , V_23 ) ;
if ( F_5 ( V_34 -> V_4 + V_10 ) & V_63 ) {
F_2 ( V_64 , V_34 -> V_4 + V_10 ) ;
F_6 ( L_12 ,
V_34 -> V_46 ) ;
return - 1 ;
}
if ( V_59 > V_60 -> V_65 )
V_60 -> V_65 = V_59 ;
return 0 ;
}
static inline int F_22 ( struct V_33 * V_34 , unsigned char * V_66 ,
int V_55 ) {
register unsigned char * V_67 = V_66 ;
register unsigned short V_57 = ( V_34 -> V_4 + V_58 ) ;
register int V_23 = V_55 ;
int V_59 = 0 ;
struct V_41 * V_60 = F_20 ( V_34 ) ;
while ( ! ( ( F_5 ( V_34 -> V_4 + V_61 ) ) & V_62 ) )
++ V_59 ;
F_23 ( V_57 , V_67 , V_23 ) ;
if ( F_5 ( V_34 -> V_4 + V_10 ) & V_63 ) {
F_2 ( V_64 , V_34 -> V_4 + V_10 ) ;
F_6 ( L_13 ,
V_34 -> V_46 ) ;
return - 1 ;
}
if ( V_59 > V_60 -> V_68 )
V_60 -> V_68 = V_59 ;
return 0 ;
}
static int F_24 ( struct V_33 * V_69 )
{
if ( V_69 -> V_5 != V_44 )
F_25 ( V_69 -> V_5 , V_69 ) ;
F_26 ( V_69 ) ;
if ( V_69 -> V_4 && V_69 -> V_70 )
F_27 ( V_69 -> V_4 , V_69 -> V_70 ) ;
F_28 ( V_69 ) ;
return 0 ;
}
