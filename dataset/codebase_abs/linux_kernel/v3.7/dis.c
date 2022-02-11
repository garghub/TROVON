static unsigned int F_1 ( unsigned char * V_1 ,
const struct V_2 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_1 += V_2 -> V_5 / 8 ;
V_4 = ( V_2 -> V_5 & 7 ) + V_2 -> V_4 ;
V_3 = 0 ;
do {
V_3 <<= 8 ;
V_3 |= ( unsigned int ) * V_1 ++ ;
V_4 -= 8 ;
} while ( V_4 > 0 );
V_3 >>= - V_4 ;
V_3 &= ( ( 1U << ( V_2 -> V_4 - 1 ) ) << 1 ) - 1 ;
if ( V_2 -> V_4 == 20 && V_2 -> V_5 == 20 )
V_3 = ( V_3 & 0xff ) << 12 | ( V_3 & 0xfff00 ) >> 8 ;
if ( ( V_2 -> V_6 & ( V_7 | V_8 ) ) &&
( V_3 & ( 1U << ( V_2 -> V_4 - 1 ) ) ) )
V_3 |= ( - 1U << ( V_2 -> V_4 - 1 ) ) << 1 ;
if ( V_2 -> V_6 & V_8 )
V_3 <<= 1 ;
if ( V_2 -> V_6 & V_9 )
V_3 ++ ;
return V_3 ;
}
static inline int F_2 ( unsigned char V_1 )
{
return ( ( ( ( int ) V_1 + 64 ) >> 7 ) + 1 ) << 1 ;
}
static struct V_10 * F_3 ( unsigned char * V_1 )
{
unsigned char V_11 = V_1 [ 1 ] ;
unsigned char V_12 ;
struct V_10 * V_13 ;
switch ( V_1 [ 0 ] ) {
case 0x01 :
V_13 = V_14 ;
break;
case 0xa5 :
V_13 = V_15 ;
break;
case 0xa7 :
V_13 = V_16 ;
break;
case 0xaa :
V_13 = V_17 ;
break;
case 0xb2 :
V_13 = V_18 ;
break;
case 0xb3 :
V_13 = V_19 ;
break;
case 0xb9 :
V_13 = V_20 ;
break;
case 0xc0 :
V_13 = V_21 ;
break;
case 0xc2 :
V_13 = V_22 ;
break;
case 0xc4 :
V_13 = V_23 ;
break;
case 0xc6 :
V_13 = V_24 ;
break;
case 0xc8 :
V_13 = V_25 ;
break;
case 0xcc :
V_13 = V_26 ;
break;
case 0xe3 :
V_13 = V_27 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xe5 :
V_13 = V_28 ;
break;
case 0xeb :
V_13 = V_29 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xec :
V_13 = V_30 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xed :
V_13 = V_31 ;
V_11 = V_1 [ 5 ] ;
break;
default:
V_13 = V_32 ;
V_11 = V_1 [ 0 ] ;
break;
}
while ( V_13 -> V_33 != V_34 ) {
V_12 = V_35 [ V_13 -> V_33 ] [ 0 ] ;
if ( V_13 -> V_11 == ( V_11 & V_12 ) )
return V_13 ;
V_13 ++ ;
}
return NULL ;
}
int F_4 ( unsigned char * V_36 , char V_37 [ 8 ] )
{
struct V_10 * V_10 ;
V_10 = F_3 ( V_36 ) ;
if ( ! V_10 )
return - V_38 ;
if ( V_10 -> V_39 [ 0 ] == '\0' )
snprintf ( V_37 , sizeof( V_37 ) , L_1 ,
V_40 [ ( int ) V_10 -> V_39 [ 1 ] ] ) ;
else
snprintf ( V_37 , sizeof( V_37 ) , L_2 , V_10 -> V_39 ) ;
return 0 ;
}
static int F_5 ( char * V_41 , unsigned char * V_1 , unsigned long V_42 )
{
struct V_10 * V_10 ;
const unsigned char * V_43 ;
const struct V_2 * V_2 ;
unsigned int V_44 ;
char V_45 ;
char * V_46 ;
int V_47 ;
V_46 = V_41 ;
V_10 = F_3 ( V_1 ) ;
if ( V_10 ) {
if ( V_10 -> V_39 [ 0 ] == '\0' )
V_46 += sprintf ( V_46 , L_3 ,
V_40 [ ( int ) V_10 -> V_39 [ 1 ] ] ) ;
else
V_46 += sprintf ( V_46 , L_4 , V_10 -> V_39 ) ;
V_45 = 0 ;
for ( V_43 = V_35 [ V_10 -> V_33 ] + 1 , V_47 = 0 ;
* V_43 != 0 && V_47 < 6 ; V_43 ++ , V_47 ++ ) {
V_2 = V_48 + * V_43 ;
V_44 = F_1 ( V_1 , V_2 ) ;
if ( ( V_2 -> V_6 & V_49 ) && V_44 == 0 )
continue;
if ( ( V_2 -> V_6 & V_50 ) &&
V_44 == 0 && V_45 == '(' ) {
V_45 = ',' ;
continue;
}
if ( V_45 )
V_46 += sprintf ( V_46 , L_5 , V_45 ) ;
if ( V_2 -> V_6 & V_51 )
V_46 += sprintf ( V_46 , L_6 , V_44 ) ;
else if ( V_2 -> V_6 & V_52 )
V_46 += sprintf ( V_46 , L_7 , V_44 ) ;
else if ( V_2 -> V_6 & V_53 )
V_46 += sprintf ( V_46 , L_8 , V_44 ) ;
else if ( V_2 -> V_6 & V_54 )
V_46 += sprintf ( V_46 , L_9 , V_44 ) ;
else if ( V_2 -> V_6 & V_8 )
V_46 += sprintf ( V_46 , L_10 , ( signed int ) V_44
+ V_42 ) ;
else if ( V_2 -> V_6 & V_7 )
V_46 += sprintf ( V_46 , L_11 , V_44 ) ;
else
V_46 += sprintf ( V_46 , L_12 , V_44 ) ;
if ( V_2 -> V_6 & V_55 )
V_45 = '(' ;
else if ( V_2 -> V_6 & V_50 ) {
V_46 += sprintf ( V_46 , L_13 ) ;
V_45 = ',' ;
} else
V_45 = ',' ;
}
} else
V_46 += sprintf ( V_46 , L_14 ) ;
return ( int ) ( V_46 - V_41 ) ;
}
void F_6 ( struct V_56 * V_57 )
{
char * V_58 = F_7 ( V_57 ) ? L_15 : L_16 ;
unsigned char V_1 [ 64 ] ;
char V_41 [ 64 ] , * V_46 ;
T_1 V_59 ;
unsigned long V_42 ;
int V_60 , V_61 , V_62 , V_63 , V_47 ;
V_59 = F_8 () ;
F_9 ( F_7 ( V_57 ) ? V_64 : V_65 ) ;
for ( V_60 = 32 ; V_60 && V_57 -> V_66 . V_42 >= 34 - V_60 ; V_60 -= 2 ) {
V_42 = V_57 -> V_66 . V_42 - 34 + V_60 ;
if ( F_10 ( V_1 + V_60 - 2 ,
( char V_67 * ) V_42 , 2 ) )
break;
}
for ( V_61 = 32 ; V_61 < 64 ; V_61 += 2 ) {
V_42 = V_57 -> V_66 . V_42 + V_61 - 32 ;
if ( F_10 ( V_1 + V_61 ,
( char V_67 * ) V_42 , 2 ) )
break;
}
F_9 ( V_59 ) ;
if ( ( V_57 -> V_66 . V_42 & 1 ) || V_60 >= V_61 ) {
F_11 ( L_17 , V_58 ) ;
return;
}
while ( V_60 < 32 ) {
for ( V_47 = 0 , V_63 = 0 ; V_60 + V_47 < 32 && V_63 < 3 ; V_63 ++ ) {
if ( ! F_3 ( V_1 + V_60 + V_47 ) )
break;
V_47 += F_2 ( V_1 [ V_60 + V_47 ] ) ;
}
if ( V_60 + V_47 == 32 )
break;
V_60 += 2 ;
}
V_46 = V_41 ;
V_46 += sprintf ( V_46 , L_18 , V_58 ) ;
V_63 = 0 ;
while ( V_60 < V_61 && V_63 < 8 ) {
V_62 = F_2 ( V_1 [ V_60 ] ) ;
if ( V_60 + V_62 == 32 )
* V_46 ++ = '#' ;
else if ( V_60 == 32 )
* V_46 ++ = '>' ;
else
* V_46 ++ = ' ' ;
V_42 = V_57 -> V_66 . V_42 + V_60 - 32 ;
V_46 += sprintf ( V_46 , V_68 , V_42 ) ;
if ( V_60 + V_62 >= V_61 )
break;
for ( V_47 = 0 ; V_47 < V_62 ; V_47 ++ )
V_46 += sprintf ( V_46 , L_19 , V_1 [ V_60 + V_47 ] ) ;
* V_46 ++ = '\t' ;
if ( V_47 < 6 )
* V_46 ++ = '\t' ;
V_46 += F_5 ( V_46 , V_1 + V_60 , V_42 ) ;
V_60 += V_62 ;
F_11 ( V_41 ) ;
V_46 = V_41 ;
V_46 += sprintf ( V_46 , L_20 ) ;
V_63 ++ ;
}
F_11 ( L_21 ) ;
}
void F_12 ( unsigned char * V_1 , unsigned long V_69 )
{
char V_41 [ 64 ] , * V_46 ;
int V_62 , V_47 ;
while ( V_69 ) {
V_46 = V_41 ;
V_62 = F_2 ( * V_1 ) ;
V_46 += sprintf ( V_46 , L_22 , V_1 ) ;
for ( V_47 = 0 ; V_47 < V_62 ; V_47 ++ )
V_46 += sprintf ( V_46 , L_19 , V_1 [ V_47 ] ) ;
* V_46 ++ = '\t' ;
if ( V_47 < 4 )
* V_46 ++ = '\t' ;
V_46 += F_5 ( V_46 , V_1 , ( unsigned long ) V_1 ) ;
* V_46 ++ = '\n' ;
* V_46 ++ = 0 ;
F_11 ( V_41 ) ;
V_1 += V_62 ;
V_69 -= V_62 ;
}
}
