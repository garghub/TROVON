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
void T_1 F_9 ( char * V_21 , int * V_22 )
{
static int V_23 = 0 ;
int V_24 ;
if ( V_22 [ 0 ] != 2 )
F_6 ( L_3 ) ;
else
if ( V_23 < V_25 ) {
V_26 [ V_23 ] . V_4 = ( unsigned short ) V_22 [ 1 ] ;
V_26 [ V_23 ] . V_5 = V_22 [ 2 ] ;
for ( V_24 = 0 ; V_24 < V_27 ; ++ V_24 )
if ( V_17 [ V_24 ] . V_4 == ( unsigned short ) V_22 [ 1 ] ) {
V_17 [ V_24 ] . V_28 = 1 ;
break;
}
++ V_23 ;
}
}
int T_1 F_10 ( struct V_29 * V_30 )
{
static int V_31 = 0 ;
static unsigned short V_32 = 0 ;
struct V_33 * V_34 ;
unsigned short V_4 ;
int V_35 ;
V_30 -> V_36 = L_4 ;
V_30 -> V_37 = V_38 ;
V_30 -> V_39 = V_40 ;
if ( V_41 != 0 ) {
V_26 [ 0 ] . V_4 = V_41 ;
for ( V_35 = 0 ; V_35 < V_27 ; ++ V_35 )
if ( V_17 [ V_35 ] . V_4 == V_41 ) {
V_17 [ V_35 ] . V_28 = 1 ;
break;
}
}
if ( V_42 != 0 )
V_26 [ 0 ] . V_5 = V_42 ;
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
#if ( V_43 & V_44 )
F_6 ( L_5 , ( unsigned int ) V_17 [ V_32 ] . V_4 ) ;
#endif
if ( ! V_17 [ V_32 ] . V_28 &&
F_7 ( V_32 ) ) {
V_4 = V_17 [ V_32 ] . V_4 ;
F_3 ( V_4 , V_45 [ V_32 ] , 0 ) ;
#if ( V_43 & V_44 )
F_6 ( L_6 ) ;
#endif
}
}
#if F_11 ( V_43 ) && ( V_43 & V_44 )
F_6 ( L_7 , ( unsigned int ) V_4 ) ;
#endif
if ( ! V_4 )
break;
V_34 = F_12 ( V_30 , sizeof( struct V_46 ) ) ;
if( V_34 == NULL )
break;
V_34 -> V_4 = V_4 ;
F_13 ( V_34 , 0 ) ;
if ( V_26 [ V_31 ] . V_5 != V_47 )
V_34 -> V_5 = V_26 [ V_31 ] . V_5 ;
else
V_34 -> V_5 = F_14 ( V_34 , V_48 ) ;
if ( V_34 -> V_5 != V_49 )
if ( F_15 ( V_34 -> V_5 , V_50 , V_51 ,
L_4 , V_34 ) ) {
F_6 ( L_8 ,
V_34 -> V_52 , V_34 -> V_5 ) ;
V_34 -> V_5 = V_49 ;
}
if ( V_34 -> V_5 == V_49 ) {
F_6 ( L_9 , V_34 -> V_52 ) ;
F_6 ( L_10 , V_34 -> V_52 ) ;
F_2 ( 0x4d , V_4 + V_15 ) ;
F_2 ( ( F_5 ( V_4 + V_14 ) & 0x0f ) , V_4 + V_14 ) ;
}
#if F_11 ( V_43 ) && ( V_43 & V_44 )
F_6 ( L_11 , V_34 -> V_52 , V_34 -> V_5 ) ;
#endif
F_6 ( L_12 , V_34 -> V_52 , ( int )
V_34 -> V_4 ) ;
if ( V_34 -> V_5 == V_49 )
F_6 ( L_13 ) ;
else
F_6 ( L_14 , V_34 -> V_5 ) ;
F_6 ( L_15 ,
V_53 , V_54 , V_55 ) ;
F_16 ( V_34 ) ;
F_6 ( L_16 ) ;
++ V_31 ;
++ V_35 ;
}
return V_35 ;
}
int F_17 ( struct V_56 * V_57 , struct V_58 * V_59 ,
T_2 V_60 , int * V_61 )
{
int V_62 = V_60 ;
V_61 [ 0 ] = 64 ;
V_61 [ 1 ] = 32 ;
V_61 [ 2 ] = V_62 >> 11 ;
if( V_61 [ 2 ] > 1024 ) {
V_61 [ 0 ] = 255 ;
V_61 [ 1 ] = 63 ;
V_61 [ 2 ] = V_62 / ( 63 * 255 ) ;
if( V_61 [ 2 ] > 1023 )
V_61 [ 2 ] = 1023 ;
}
return 0 ;
}
static inline int F_18 ( struct V_33 * V_34 , unsigned char * V_63 ,
int V_64 ) {
register unsigned char * V_65 = V_63 ;
register unsigned short V_66 = ( unsigned short ) ( V_34 -> V_4 +
V_67 ) ;
register int V_24 = V_64 ;
int V_68 = 0 ;
while ( ! ( F_5 ( V_34 -> V_4 + V_69 ) & V_70 ) )
++ V_68 ;
F_19 ( V_66 , V_65 , V_24 ) ;
if ( F_5 ( V_34 -> V_4 + V_10 ) & V_71 ) {
F_2 ( V_72 , V_34 -> V_4 + V_10 ) ;
F_6 ( L_17 ,
V_34 -> V_52 ) ;
return - 1 ;
}
if ( V_68 > V_73 )
V_73 = V_68 ;
return 0 ;
}
static inline int F_20 ( struct V_33 * V_34 , unsigned char * V_74 ,
int V_64 ) {
register unsigned char * V_75 = V_74 ;
register unsigned short V_66 = ( V_34 -> V_4 + V_67 ) ;
register int V_24 = V_64 ;
int V_68 = 0 ;
while ( ! ( ( F_5 ( V_34 -> V_4 + V_69 ) ) & V_70 ) )
++ V_68 ;
F_21 ( V_66 , V_75 , V_24 ) ;
if ( F_5 ( V_34 -> V_4 + V_10 ) & V_71 ) {
F_2 ( V_72 , V_34 -> V_4 + V_10 ) ;
F_6 ( L_18 ,
V_34 -> V_52 ) ;
return - 1 ;
}
if ( V_68 > V_73 )
V_76 = V_68 ;
return 0 ;
}
static int F_22 ( struct V_33 * V_77 )
{
if ( V_77 -> V_5 )
F_23 ( V_77 -> V_5 , V_77 ) ;
F_24 ( V_77 ) ;
if ( V_77 -> V_78 != 0xff )
F_25 ( V_77 -> V_78 ) ;
if ( V_77 -> V_4 && V_77 -> V_79 )
F_26 ( V_77 -> V_4 , V_77 -> V_79 ) ;
F_27 ( V_77 ) ;
return 0 ;
}
