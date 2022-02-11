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
case 0xb2 :
V_13 = V_17 ;
break;
case 0xb3 :
V_13 = V_18 ;
break;
case 0xb9 :
V_13 = V_19 ;
break;
case 0xc0 :
V_13 = V_20 ;
break;
case 0xc2 :
V_13 = V_21 ;
break;
case 0xc4 :
V_13 = V_22 ;
break;
case 0xc6 :
V_13 = V_23 ;
break;
case 0xc8 :
V_13 = V_24 ;
break;
case 0xcc :
V_13 = V_25 ;
break;
case 0xe3 :
V_13 = V_26 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xe5 :
V_13 = V_27 ;
break;
case 0xeb :
V_13 = V_28 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xec :
V_13 = V_29 ;
V_11 = V_1 [ 5 ] ;
break;
case 0xed :
V_13 = V_30 ;
V_11 = V_1 [ 5 ] ;
break;
default:
V_13 = V_31 ;
V_11 = V_1 [ 0 ] ;
break;
}
while ( V_13 -> V_32 != V_33 ) {
V_12 = V_34 [ V_13 -> V_32 ] [ 0 ] ;
if ( V_13 -> V_11 == ( V_11 & V_12 ) )
return V_13 ;
V_13 ++ ;
}
return NULL ;
}
static int F_4 ( char * V_35 , unsigned char * V_1 , unsigned long V_36 )
{
struct V_10 * V_10 ;
const unsigned char * V_37 ;
const struct V_2 * V_2 ;
unsigned int V_38 ;
char V_39 ;
char * V_40 ;
int V_41 ;
V_40 = V_35 ;
V_10 = F_3 ( V_1 ) ;
if ( V_10 ) {
if ( V_10 -> V_42 [ 0 ] == '\0' )
V_40 += sprintf ( V_40 , L_1 ,
V_43 [ ( int ) V_10 -> V_42 [ 1 ] ] ) ;
else
V_40 += sprintf ( V_40 , L_2 , V_10 -> V_42 ) ;
V_39 = 0 ;
for ( V_37 = V_34 [ V_10 -> V_32 ] + 1 , V_41 = 0 ;
* V_37 != 0 && V_41 < 6 ; V_37 ++ , V_41 ++ ) {
V_2 = V_44 + * V_37 ;
V_38 = F_1 ( V_1 , V_2 ) ;
if ( ( V_2 -> V_6 & V_45 ) && V_38 == 0 )
continue;
if ( ( V_2 -> V_6 & V_46 ) &&
V_38 == 0 && V_39 == '(' ) {
V_39 = ',' ;
continue;
}
if ( V_39 )
V_40 += sprintf ( V_40 , L_3 , V_39 ) ;
if ( V_2 -> V_6 & V_47 )
V_40 += sprintf ( V_40 , L_4 , V_38 ) ;
else if ( V_2 -> V_6 & V_48 )
V_40 += sprintf ( V_40 , L_5 , V_38 ) ;
else if ( V_2 -> V_6 & V_49 )
V_40 += sprintf ( V_40 , L_6 , V_38 ) ;
else if ( V_2 -> V_6 & V_50 )
V_40 += sprintf ( V_40 , L_7 , V_38 ) ;
else if ( V_2 -> V_6 & V_8 )
V_40 += sprintf ( V_40 , L_8 , ( signed int ) V_38
+ V_36 ) ;
else if ( V_2 -> V_6 & V_7 )
V_40 += sprintf ( V_40 , L_9 , V_38 ) ;
else
V_40 += sprintf ( V_40 , L_10 , V_38 ) ;
if ( V_2 -> V_6 & V_51 )
V_39 = '(' ;
else if ( V_2 -> V_6 & V_46 ) {
V_40 += sprintf ( V_40 , L_11 ) ;
V_39 = ',' ;
} else
V_39 = ',' ;
}
} else
V_40 += sprintf ( V_40 , L_12 ) ;
return ( int ) ( V_40 - V_35 ) ;
}
void F_5 ( struct V_52 * V_53 )
{
char * V_54 = F_6 ( V_53 ) ? L_13 : L_14 ;
unsigned char V_1 [ 64 ] ;
char V_35 [ 64 ] , * V_40 ;
T_1 V_55 ;
unsigned long V_36 ;
int V_56 , V_57 , V_58 , V_59 , V_41 ;
V_55 = F_7 () ;
F_8 ( F_6 ( V_53 ) ? V_60 : V_61 ) ;
for ( V_56 = 32 ; V_56 && V_53 -> V_62 . V_36 >= 34 - V_56 ; V_56 -= 2 ) {
V_36 = V_53 -> V_62 . V_36 - 34 + V_56 ;
if ( F_9 ( V_1 + V_56 - 2 ,
( char V_63 * ) V_36 , 2 ) )
break;
}
for ( V_57 = 32 ; V_57 < 64 ; V_57 += 2 ) {
V_36 = V_53 -> V_62 . V_36 + V_57 - 32 ;
if ( F_9 ( V_1 + V_57 ,
( char V_63 * ) V_36 , 2 ) )
break;
}
F_8 ( V_55 ) ;
if ( ( V_53 -> V_62 . V_36 & 1 ) || V_56 >= V_57 ) {
F_10 ( L_15 , V_54 ) ;
return;
}
while ( V_56 < 32 ) {
for ( V_41 = 0 , V_59 = 0 ; V_56 + V_41 < 32 && V_59 < 3 ; V_59 ++ ) {
if ( ! F_3 ( V_1 + V_56 + V_41 ) )
break;
V_41 += F_2 ( V_1 [ V_56 + V_41 ] ) ;
}
if ( V_56 + V_41 == 32 )
break;
V_56 += 2 ;
}
V_40 = V_35 ;
V_40 += sprintf ( V_40 , L_16 , V_54 ) ;
V_59 = 0 ;
while ( V_56 < V_57 && V_59 < 8 ) {
V_58 = F_2 ( V_1 [ V_56 ] ) ;
if ( V_56 + V_58 == 32 )
* V_40 ++ = '#' ;
else if ( V_56 == 32 )
* V_40 ++ = '>' ;
else
* V_40 ++ = ' ' ;
V_36 = V_53 -> V_62 . V_36 + V_56 - 32 ;
V_40 += sprintf ( V_40 , V_64 , V_36 ) ;
if ( V_56 + V_58 >= V_57 )
break;
for ( V_41 = 0 ; V_41 < V_58 ; V_41 ++ )
V_40 += sprintf ( V_40 , L_17 , V_1 [ V_56 + V_41 ] ) ;
* V_40 ++ = '\t' ;
if ( V_41 < 6 )
* V_40 ++ = '\t' ;
V_40 += F_4 ( V_40 , V_1 + V_56 , V_36 ) ;
V_56 += V_58 ;
F_10 ( V_35 ) ;
V_40 = V_35 ;
V_40 += sprintf ( V_40 , L_18 ) ;
V_59 ++ ;
}
F_10 ( L_19 ) ;
}
