static unsigned int T_1 F_1 ( struct V_1 * V_2 , char V_3 )
{
unsigned int V_4 = 0 ;
while ( V_2 -> V_5 < V_3 ) {
if ( V_2 -> V_6 == V_2 -> V_7 ) {
if ( V_2 -> V_8 )
return 0 ;
V_2 -> V_7 = V_2 -> V_9 ( V_2 -> V_10 , V_11 ) ;
if ( V_2 -> V_7 <= 0 ) {
V_2 -> V_8 = V_12 ;
return 0 ;
}
V_2 -> V_6 = 0 ;
}
if ( V_2 -> V_5 >= 24 ) {
V_4 = V_2 -> V_13 & ( ( 1 << V_2 -> V_5 ) - 1 ) ;
V_3 -= V_2 -> V_5 ;
V_4 <<= V_3 ;
V_2 -> V_5 = 0 ;
}
V_2 -> V_13 = ( V_2 -> V_13 << 8 ) | V_2 -> V_10 [ V_2 -> V_6 ++ ] ;
V_2 -> V_5 += 8 ;
}
V_2 -> V_5 -= V_3 ;
V_4 |= ( V_2 -> V_13 >> V_2 -> V_5 ) & ( ( 1 << V_3 ) - 1 ) ;
return V_4 ;
}
static int T_1 F_2 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = NULL ;
int * V_16 = NULL ;
int * V_17 = NULL ;
int V_18 , V_19 , V_20 , V_21 , V_22 ,
V_23 , V_24 , V_25 , V_26 , V_27 , V_28 , V_29 , V_30 , * V_31 ;
unsigned char V_32 , * V_33 , * V_34 , * V_35 ;
unsigned int * V_36 , V_37 ;
V_36 = V_2 -> V_36 ;
V_20 = V_2 -> V_20 ;
V_35 = V_2 -> V_35 ;
V_31 = V_2 -> V_31 ;
V_33 = V_2 -> V_33 ;
V_34 = V_2 -> V_34 ;
V_23 = F_1 ( V_2 , 24 ) ;
V_24 = F_1 ( V_2 , 24 ) ;
V_2 -> V_38 = F_1 ( V_2 , 32 ) ;
if ( ( V_23 == 0x177245 ) && ( V_24 == 0x385090 ) )
return V_39 ;
if ( ( V_23 != 0x314159 ) || ( V_24 != 0x265359 ) )
return V_40 ;
if ( F_1 ( V_2 , 1 ) )
return V_41 ;
V_37 = F_1 ( V_2 , 24 ) ;
if ( V_37 > V_20 )
return V_42 ;
V_26 = F_1 ( V_2 , 16 ) ;
V_29 = 0 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
if ( V_26 & ( 1 << ( 15 - V_23 ) ) ) {
V_25 = F_1 ( V_2 , 16 ) ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ )
if ( V_25 & ( 1 << ( 15 - V_24 ) ) )
V_33 [ V_29 ++ ] = ( 16 * V_23 ) + V_24 ;
}
}
V_21 = F_1 ( V_2 , 3 ) ;
if ( V_21 < 2 || V_21 > V_43 )
return V_42 ;
V_30 = F_1 ( V_2 , 15 ) ;
if ( ! V_30 )
return V_42 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
V_34 [ V_23 ] = V_23 ;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ ) {
for ( V_24 = 0 ; F_1 ( V_2 , 1 ) ; V_24 ++ )
if ( V_24 >= V_21 )
return V_42 ;
V_32 = V_34 [ V_24 ] ;
for (; V_24 ; V_24 -- )
V_34 [ V_24 ] = V_34 [ V_24 - 1 ] ;
V_34 [ 0 ] = V_35 [ V_23 ] = V_32 ;
}
V_28 = V_29 + 2 ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
unsigned char V_44 [ V_45 ] , V_46 [ V_47 + 1 ] ;
int V_48 , V_49 , V_50 ;
V_26 = F_1 ( V_2 , 5 ) - 1 ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ ) {
for (; ; ) {
if ( ( ( unsigned ) V_26 ) > ( V_47 - 1 ) )
return V_42 ;
V_25 = F_1 ( V_2 , 2 ) ;
if ( V_25 < 2 ) {
V_2 -> V_5 ++ ;
break;
}
V_26 += ( ( ( V_25 + 1 ) & 2 ) - 1 ) ;
}
V_44 [ V_23 ] = V_26 + 1 ;
}
V_48 = V_49 = V_44 [ 0 ] ;
for ( V_23 = 1 ; V_23 < V_28 ; V_23 ++ ) {
if ( V_44 [ V_23 ] > V_49 )
V_49 = V_44 [ V_23 ] ;
else if ( V_44 [ V_23 ] < V_48 )
V_48 = V_44 [ V_23 ] ;
}
V_15 = V_2 -> V_51 + V_24 ;
V_15 -> V_48 = V_48 ;
V_15 -> V_49 = V_49 ;
V_16 = V_15 -> V_16 - 1 ;
V_17 = V_15 -> V_17 - 1 ;
V_50 = 0 ;
for ( V_23 = V_48 ; V_23 <= V_49 ; V_23 ++ ) {
V_46 [ V_23 ] = V_17 [ V_23 ] = 0 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ )
if ( V_44 [ V_26 ] == V_23 )
V_15 -> V_52 [ V_50 ++ ] = V_26 ;
}
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ )
V_46 [ V_44 [ V_23 ] ] ++ ;
V_50 = V_26 = 0 ;
for ( V_23 = V_48 ; V_23 < V_49 ; V_23 ++ ) {
V_50 += V_46 [ V_23 ] ;
V_17 [ V_23 ] = ( V_50 << ( V_49 - V_23 ) ) - 1 ;
V_50 <<= 1 ;
V_16 [ V_23 + 1 ] = V_50 - ( V_26 += V_46 [ V_23 ] ) ;
}
V_17 [ V_49 + 1 ] = V_53 ;
V_17 [ V_49 ] = V_50 + V_46 [ V_49 ] - 1 ;
V_16 [ V_48 ] = 0 ;
}
for ( V_23 = 0 ; V_23 < 256 ; V_23 ++ ) {
V_31 [ V_23 ] = 0 ;
V_34 [ V_23 ] = ( unsigned char ) V_23 ;
}
V_27 = V_18 = V_28 = V_22 = 0 ;
for (; ; ) {
if ( ! ( V_28 -- ) ) {
V_28 = V_54 - 1 ;
if ( V_22 >= V_30 )
return V_42 ;
V_15 = V_2 -> V_51 + V_35 [ V_22 ++ ] ;
V_16 = V_15 -> V_16 - 1 ;
V_17 = V_15 -> V_17 - 1 ;
}
while ( V_2 -> V_5 < V_15 -> V_49 ) {
if ( V_2 -> V_6 == V_2 -> V_7 ) {
V_24 = F_1 ( V_2 , V_15 -> V_49 ) ;
goto V_55;
}
V_2 -> V_13 =
( V_2 -> V_13 << 8 ) | V_2 -> V_10 [ V_2 -> V_6 ++ ] ;
V_2 -> V_5 += 8 ;
} ;
V_2 -> V_5 -= V_15 -> V_49 ;
V_24 = ( V_2 -> V_13 >> V_2 -> V_5 ) &
( ( 1 << V_15 -> V_49 ) - 1 ) ;
V_55:
V_23 = V_15 -> V_48 ;
while ( V_24 > V_17 [ V_23 ] )
++ V_23 ;
V_2 -> V_5 += ( V_15 -> V_49 - V_23 ) ;
if ( ( V_23 > V_15 -> V_49 )
|| ( ( ( unsigned ) ( V_24 = ( V_24 >> ( V_15 -> V_49 - V_23 ) ) - V_16 [ V_23 ] ) )
>= V_45 ) )
return V_42 ;
V_19 = V_15 -> V_52 [ V_24 ] ;
if ( ( ( unsigned ) V_19 ) <= V_56 ) {
if ( ! V_27 ) {
V_27 = 1 ;
V_26 = 0 ;
}
V_26 += ( V_27 << V_19 ) ;
V_27 <<= 1 ;
continue;
}
if ( V_27 ) {
V_27 = 0 ;
if ( V_18 + V_26 >= V_20 )
return V_42 ;
V_32 = V_33 [ V_34 [ 0 ] ] ;
V_31 [ V_32 ] += V_26 ;
while ( V_26 -- )
V_36 [ V_18 ++ ] = V_32 ;
}
if ( V_19 > V_29 )
break;
if ( V_18 >= V_20 )
return V_42 ;
V_23 = V_19 - 1 ;
V_32 = V_34 [ V_23 ] ;
do {
V_34 [ V_23 ] = V_34 [ V_23 - 1 ] ;
} while ( -- V_23 );
V_34 [ 0 ] = V_32 ;
V_32 = V_33 [ V_32 ] ;
V_31 [ V_32 ] ++ ;
V_36 [ V_18 ++ ] = ( unsigned int ) V_32 ;
}
V_24 = 0 ;
for ( V_23 = 0 ; V_23 < 256 ; V_23 ++ ) {
V_25 = V_24 + V_31 [ V_23 ] ;
V_31 [ V_23 ] = V_24 ;
V_24 = V_25 ;
}
for ( V_23 = 0 ; V_23 < V_18 ; V_23 ++ ) {
V_32 = ( unsigned char ) ( V_36 [ V_23 ] & 0xff ) ;
V_36 [ V_31 [ V_32 ] ] |= ( V_23 << 8 ) ;
V_31 [ V_32 ] ++ ;
}
if ( V_18 ) {
if ( V_37 >= V_18 )
return V_42 ;
V_2 -> V_57 = V_36 [ V_37 ] ;
V_2 -> V_58 = ( unsigned char ) ( V_2 -> V_57 & 0xff ) ;
V_2 -> V_57 >>= 8 ;
V_2 -> V_59 = 5 ;
}
V_2 -> V_60 = V_18 ;
return V_61 ;
}
static int T_1 F_3 ( struct V_1 * V_2 , char * V_62 , int V_63 )
{
const unsigned int * V_36 ;
int V_64 , V_65 , V_66 , V_67 ;
if ( V_2 -> V_60 < 0 )
return V_2 -> V_60 ;
V_67 = 0 ;
V_36 = V_2 -> V_36 ;
V_64 = V_2 -> V_57 ;
V_65 = V_2 -> V_58 ;
if ( V_2 -> V_68 ) {
-- V_2 -> V_68 ;
for (; ; ) {
if ( V_67 >= V_63 ) {
V_2 -> V_57 = V_64 ;
V_2 -> V_58 = V_65 ;
V_2 -> V_68 ++ ;
return V_63 ;
}
V_62 [ V_67 ++ ] = V_65 ;
V_2 -> V_69 = ( ( ( V_2 -> V_69 ) << 8 )
^ V_2 -> V_70 [ ( ( V_2 -> V_69 ) >> 24 )
^ V_65 ] ) ;
if ( V_2 -> V_68 ) {
-- V_2 -> V_68 ;
continue;
}
V_71:
if ( ! V_2 -> V_60 -- )
break;
V_66 = V_65 ;
V_64 = V_36 [ V_64 ] ;
V_65 = V_64 & 0xff ;
V_64 >>= 8 ;
if ( -- V_2 -> V_59 ) {
if ( V_65 != V_66 )
V_2 -> V_59 = 4 ;
} else {
V_2 -> V_68 = V_65 ;
V_65 = V_66 ;
V_2 -> V_59 = 5 ;
if ( ! V_2 -> V_68 )
goto V_71;
-- V_2 -> V_68 ;
}
}
V_2 -> V_69 = ~ V_2 -> V_69 ;
V_2 -> V_72 = ( ( V_2 -> V_72 << 1 ) |
( V_2 -> V_72 >> 31 ) ) ^ V_2 -> V_69 ;
if ( V_2 -> V_69 != V_2 -> V_38 ) {
V_2 -> V_72 = V_2 -> V_38 + 1 ;
return V_39 ;
}
}
V_66 = F_2 ( V_2 ) ;
if ( V_66 ) {
V_2 -> V_60 = V_66 ;
return ( V_66 != V_39 ) ? V_66 : V_67 ;
}
V_2 -> V_69 = 0xffffffffUL ;
V_64 = V_2 -> V_57 ;
V_65 = V_2 -> V_58 ;
goto V_71;
}
static long T_1 F_4 ( void * V_73 , unsigned long V_63 )
{
return - 1 ;
}
static int T_1 F_5 ( struct V_1 * * V_74 , void * V_10 , long V_63 ,
long (* V_9)( void * , unsigned long ) )
{
struct V_1 * V_2 ;
unsigned int V_23 , V_24 , V_75 ;
const unsigned int V_76 =
( ( ( unsigned int ) 'B' ) << 24 ) + ( ( ( unsigned int ) 'Z' ) << 16 )
+ ( ( ( unsigned int ) 'h' ) << 8 ) + ( unsigned int ) '0' ;
V_23 = sizeof( struct V_1 ) ;
V_2 = * V_74 = malloc ( V_23 ) ;
if ( ! V_2 )
return V_77 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_7 = V_63 ;
if ( V_9 != NULL )
V_2 -> V_9 = V_9 ;
else
V_2 -> V_9 = F_4 ;
for ( V_23 = 0 ; V_23 < 256 ; V_23 ++ ) {
V_75 = V_23 << 24 ;
for ( V_24 = 8 ; V_24 ; V_24 -- )
V_75 = V_75 & 0x80000000 ? ( V_75 << 1 ) ^ 0x04c11db7 : ( V_75 << 1 ) ;
V_2 -> V_70 [ V_23 ] = V_75 ;
}
V_23 = F_1 ( V_2 , 32 ) ;
if ( ( ( unsigned int ) ( V_23 - V_76 - 1 ) ) >= 9 )
return V_40 ;
V_2 -> V_20 = 100000 * ( V_23 - V_76 ) ;
V_2 -> V_36 = F_6 ( V_2 -> V_20 * sizeof( int ) ) ;
if ( ! V_2 -> V_36 )
return V_77 ;
return V_61 ;
}
STATIC int T_1 F_7 ( unsigned char * V_73 , long V_63 ,
long (* V_9)( void * , unsigned long ) ,
long (* F_8)( void * , unsigned long ) ,
unsigned char * V_62 ,
long * V_64 ,
void (* error)( char * V_78 ) )
{
struct V_1 * V_2 ;
int V_23 = - 1 ;
unsigned char * V_10 ;
if ( F_8 )
V_62 = malloc ( V_11 ) ;
if ( ! V_62 ) {
error ( L_1 ) ;
return V_77 ;
}
if ( V_73 )
V_10 = V_73 ;
else
V_10 = malloc ( V_11 ) ;
if ( ! V_10 ) {
error ( L_2 ) ;
V_23 = V_77 ;
goto V_79;
}
V_23 = F_5 ( & V_2 , V_10 , V_63 , V_9 ) ;
if ( ! V_23 ) {
for (; ; ) {
V_23 = F_3 ( V_2 , V_62 , V_11 ) ;
if ( V_23 <= 0 )
break;
if ( ! F_8 )
V_62 += V_23 ;
else
if ( V_23 != F_8 ( V_62 , V_23 ) ) {
V_23 = V_80 ;
break;
}
}
}
if ( V_23 == V_39 ) {
if ( V_2 -> V_38 != V_2 -> V_72 )
error ( L_3 ) ;
else
V_23 = V_61 ;
} else if ( V_23 == V_80 ) {
error ( L_4 ) ;
}
if ( ! V_2 )
goto V_81;
if ( V_2 -> V_36 )
F_9 ( V_2 -> V_36 ) ;
if ( V_64 )
* V_64 = V_2 -> V_6 ;
free ( V_2 ) ;
V_81:
if ( ! V_73 )
free ( V_10 ) ;
V_79:
if ( F_8 )
free ( V_62 ) ;
return V_23 ;
}
STATIC int T_1 F_10 ( unsigned char * V_73 , long V_63 ,
long (* V_9)( void * , unsigned long ) ,
long (* F_8)( void * , unsigned long ) ,
unsigned char * V_62 ,
long * V_64 ,
void (* error)( char * V_78 ) )
{
return F_7 ( V_73 , V_63 - 4 , V_9 , F_8 , V_62 , V_64 , error ) ;
}
