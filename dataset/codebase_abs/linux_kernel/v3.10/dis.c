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
int F_4 ( unsigned char * V_36 , char * V_37 , unsigned int V_38 )
{
struct V_10 * V_10 ;
V_10 = F_3 ( V_36 ) ;
if ( ! V_10 )
return - V_39 ;
if ( V_10 -> V_40 [ 0 ] == '\0' )
snprintf ( V_37 , V_38 , L_1 ,
V_41 [ ( int ) V_10 -> V_40 [ 1 ] ] ) ;
else
snprintf ( V_37 , V_38 , L_2 , V_10 -> V_40 ) ;
return 0 ;
}
static int F_5 ( char * V_42 , unsigned char * V_1 , unsigned long V_43 )
{
struct V_10 * V_10 ;
const unsigned char * V_44 ;
const struct V_2 * V_2 ;
unsigned int V_45 ;
char V_46 ;
char * V_47 ;
int V_48 ;
V_47 = V_42 ;
V_10 = F_3 ( V_1 ) ;
if ( V_10 ) {
if ( V_10 -> V_40 [ 0 ] == '\0' )
V_47 += sprintf ( V_47 , L_3 ,
V_41 [ ( int ) V_10 -> V_40 [ 1 ] ] ) ;
else
V_47 += sprintf ( V_47 , L_4 , V_10 -> V_40 ) ;
V_46 = 0 ;
for ( V_44 = V_35 [ V_10 -> V_33 ] + 1 , V_48 = 0 ;
* V_44 != 0 && V_48 < 6 ; V_44 ++ , V_48 ++ ) {
V_2 = V_49 + * V_44 ;
V_45 = F_1 ( V_1 , V_2 ) ;
if ( ( V_2 -> V_6 & V_50 ) && V_45 == 0 )
continue;
if ( ( V_2 -> V_6 & V_51 ) &&
V_45 == 0 && V_46 == '(' ) {
V_46 = ',' ;
continue;
}
if ( V_46 )
V_47 += sprintf ( V_47 , L_5 , V_46 ) ;
if ( V_2 -> V_6 & V_52 )
V_47 += sprintf ( V_47 , L_6 , V_45 ) ;
else if ( V_2 -> V_6 & V_53 )
V_47 += sprintf ( V_47 , L_7 , V_45 ) ;
else if ( V_2 -> V_6 & V_54 )
V_47 += sprintf ( V_47 , L_8 , V_45 ) ;
else if ( V_2 -> V_6 & V_55 )
V_47 += sprintf ( V_47 , L_9 , V_45 ) ;
else if ( V_2 -> V_6 & V_8 )
V_47 += sprintf ( V_47 , L_10 , ( signed int ) V_45
+ V_43 ) ;
else if ( V_2 -> V_6 & V_7 )
V_47 += sprintf ( V_47 , L_11 , V_45 ) ;
else
V_47 += sprintf ( V_47 , L_12 , V_45 ) ;
if ( V_2 -> V_6 & V_56 )
V_46 = '(' ;
else if ( V_2 -> V_6 & V_51 ) {
V_47 += sprintf ( V_47 , L_13 ) ;
V_46 = ',' ;
} else
V_46 = ',' ;
}
} else
V_47 += sprintf ( V_47 , L_14 ) ;
return ( int ) ( V_47 - V_42 ) ;
}
void F_6 ( struct V_57 * V_58 )
{
char * V_59 = F_7 ( V_58 ) ? L_15 : L_16 ;
unsigned char V_1 [ 64 ] ;
char V_42 [ 64 ] , * V_47 ;
T_1 V_60 ;
unsigned long V_43 ;
int V_61 , V_62 , V_63 , V_64 , V_48 ;
V_60 = F_8 () ;
F_9 ( F_7 ( V_58 ) ? V_65 : V_66 ) ;
for ( V_61 = 32 ; V_61 && V_58 -> V_67 . V_43 >= 34 - V_61 ; V_61 -= 2 ) {
V_43 = V_58 -> V_67 . V_43 - 34 + V_61 ;
if ( F_10 ( V_1 + V_61 - 2 ,
( char V_68 * ) V_43 , 2 ) )
break;
}
for ( V_62 = 32 ; V_62 < 64 ; V_62 += 2 ) {
V_43 = V_58 -> V_67 . V_43 + V_62 - 32 ;
if ( F_10 ( V_1 + V_62 ,
( char V_68 * ) V_43 , 2 ) )
break;
}
F_9 ( V_60 ) ;
if ( ( V_58 -> V_67 . V_43 & 1 ) || V_61 >= V_62 ) {
F_11 ( L_17 , V_59 ) ;
return;
}
while ( V_61 < 32 ) {
for ( V_48 = 0 , V_64 = 0 ; V_61 + V_48 < 32 && V_64 < 3 ; V_64 ++ ) {
if ( ! F_3 ( V_1 + V_61 + V_48 ) )
break;
V_48 += F_2 ( V_1 [ V_61 + V_48 ] ) ;
}
if ( V_61 + V_48 == 32 )
break;
V_61 += 2 ;
}
V_47 = V_42 ;
V_47 += sprintf ( V_47 , L_18 , V_59 ) ;
V_64 = 0 ;
while ( V_61 < V_62 && V_64 < 8 ) {
V_63 = F_2 ( V_1 [ V_61 ] ) ;
if ( V_61 + V_63 == 32 )
* V_47 ++ = '#' ;
else if ( V_61 == 32 )
* V_47 ++ = '>' ;
else
* V_47 ++ = ' ' ;
V_43 = V_58 -> V_67 . V_43 + V_61 - 32 ;
V_47 += sprintf ( V_47 , V_69 , V_43 ) ;
if ( V_61 + V_63 >= V_62 )
break;
for ( V_48 = 0 ; V_48 < V_63 ; V_48 ++ )
V_47 += sprintf ( V_47 , L_19 , V_1 [ V_61 + V_48 ] ) ;
* V_47 ++ = '\t' ;
if ( V_48 < 6 )
* V_47 ++ = '\t' ;
V_47 += F_5 ( V_47 , V_1 + V_61 , V_43 ) ;
V_61 += V_63 ;
F_11 ( V_42 ) ;
V_47 = V_42 ;
V_47 += sprintf ( V_47 , L_20 ) ;
V_64 ++ ;
}
F_11 ( L_21 ) ;
}
void F_12 ( unsigned char * V_1 , unsigned long V_38 )
{
char V_42 [ 64 ] , * V_47 ;
int V_63 , V_48 ;
while ( V_38 ) {
V_47 = V_42 ;
V_63 = F_2 ( * V_1 ) ;
if ( V_63 > V_38 )
break;
V_47 += sprintf ( V_47 , L_22 , V_1 ) ;
for ( V_48 = 0 ; V_48 < V_63 ; V_48 ++ )
V_47 += sprintf ( V_47 , L_19 , V_1 [ V_48 ] ) ;
* V_47 ++ = '\t' ;
if ( V_48 < 4 )
* V_47 ++ = '\t' ;
V_47 += F_5 ( V_47 , V_1 , ( unsigned long ) V_1 ) ;
* V_47 ++ = '\n' ;
* V_47 ++ = 0 ;
F_11 ( V_42 ) ;
V_1 += V_63 ;
V_38 -= V_63 ;
}
}
