static unsigned int F_1 ( unsigned char * V_1 ,
const struct V_2 * V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_1 += V_3 -> V_6 / 8 ;
V_5 = ( V_3 -> V_6 & 7 ) + V_3 -> V_5 ;
V_4 = 0 ;
do {
V_4 <<= 8 ;
V_4 |= ( unsigned int ) * V_1 ++ ;
V_5 -= 8 ;
} while ( V_5 > 0 );
V_4 >>= - V_5 ;
V_4 &= ( ( 1U << ( V_3 -> V_5 - 1 ) ) << 1 ) - 1 ;
if ( V_3 -> V_5 == 20 && V_3 -> V_6 == 20 )
V_4 = ( V_4 & 0xff ) << 12 | ( V_4 & 0xfff00 ) >> 8 ;
if ( ( V_3 -> V_7 & ( V_8 | V_9 ) ) &&
( V_4 & ( 1U << ( V_3 -> V_5 - 1 ) ) ) )
V_4 |= ( - 1U << ( V_3 -> V_5 - 1 ) ) << 1 ;
if ( V_3 -> V_7 & V_9 )
V_4 <<= 1 ;
if ( V_3 -> V_7 & V_10 )
V_4 ++ ;
return V_4 ;
}
struct V_11 * F_2 ( unsigned char * V_1 )
{
unsigned char V_12 = V_1 [ 1 ] ;
unsigned char V_13 ;
struct V_11 * V_14 ;
switch ( V_1 [ 0 ] ) {
case 0x01 :
V_14 = V_15 ;
break;
case 0xa5 :
V_14 = V_16 ;
break;
case 0xa7 :
V_14 = V_17 ;
break;
case 0xaa :
V_14 = V_18 ;
break;
case 0xb2 :
V_14 = V_19 ;
break;
case 0xb3 :
V_14 = V_20 ;
break;
case 0xb9 :
V_14 = V_21 ;
break;
case 0xc0 :
V_14 = V_22 ;
break;
case 0xc2 :
V_14 = V_23 ;
break;
case 0xc4 :
V_14 = V_24 ;
break;
case 0xc6 :
V_14 = V_25 ;
break;
case 0xc8 :
V_14 = V_26 ;
break;
case 0xcc :
V_14 = V_27 ;
break;
case 0xe3 :
V_14 = V_28 ;
V_12 = V_1 [ 5 ] ;
break;
case 0xe5 :
V_14 = V_29 ;
break;
case 0xeb :
V_14 = V_30 ;
V_12 = V_1 [ 5 ] ;
break;
case 0xec :
V_14 = V_31 ;
V_12 = V_1 [ 5 ] ;
break;
case 0xed :
V_14 = V_32 ;
V_12 = V_1 [ 5 ] ;
break;
default:
V_14 = V_33 ;
V_12 = V_1 [ 0 ] ;
break;
}
while ( V_14 -> V_34 != V_35 ) {
V_13 = V_36 [ V_14 -> V_34 ] [ 0 ] ;
if ( V_14 -> V_12 == ( V_12 & V_13 ) )
return V_14 ;
V_14 ++ ;
}
return NULL ;
}
int F_3 ( unsigned char * V_37 , char * V_38 , unsigned int V_39 )
{
struct V_11 * V_40 ;
V_40 = F_2 ( V_37 ) ;
if ( ! V_40 )
return - V_41 ;
if ( V_40 -> V_42 [ 0 ] == '\0' )
snprintf ( V_38 , V_39 , L_1 ,
V_43 [ ( int ) V_40 -> V_42 [ 1 ] ] ) ;
else
snprintf ( V_38 , V_39 , L_2 , V_40 -> V_42 ) ;
return 0 ;
}
static int F_4 ( char * V_44 , unsigned char * V_1 , unsigned long V_45 )
{
struct V_11 * V_40 ;
const unsigned char * V_46 ;
const struct V_2 * V_3 ;
unsigned int V_47 ;
char V_48 ;
char * V_49 ;
int V_50 ;
V_49 = V_44 ;
V_40 = F_2 ( V_1 ) ;
if ( V_40 ) {
if ( V_40 -> V_42 [ 0 ] == '\0' )
V_49 += sprintf ( V_49 , L_3 ,
V_43 [ ( int ) V_40 -> V_42 [ 1 ] ] ) ;
else
V_49 += sprintf ( V_49 , L_4 , V_40 -> V_42 ) ;
V_48 = 0 ;
for ( V_46 = V_36 [ V_40 -> V_34 ] + 1 , V_50 = 0 ;
* V_46 != 0 && V_50 < 6 ; V_46 ++ , V_50 ++ ) {
V_3 = V_51 + * V_46 ;
V_47 = F_1 ( V_1 , V_3 ) ;
if ( ( V_3 -> V_7 & V_52 ) && V_47 == 0 )
continue;
if ( ( V_3 -> V_7 & V_53 ) &&
V_47 == 0 && V_48 == '(' ) {
V_48 = ',' ;
continue;
}
if ( V_48 )
V_49 += sprintf ( V_49 , L_5 , V_48 ) ;
if ( V_3 -> V_7 & V_54 )
V_49 += sprintf ( V_49 , L_6 , V_47 ) ;
else if ( V_3 -> V_7 & V_55 )
V_49 += sprintf ( V_49 , L_7 , V_47 ) ;
else if ( V_3 -> V_7 & V_56 )
V_49 += sprintf ( V_49 , L_8 , V_47 ) ;
else if ( V_3 -> V_7 & V_57 )
V_49 += sprintf ( V_49 , L_9 , V_47 ) ;
else if ( V_3 -> V_7 & V_9 )
V_49 += sprintf ( V_49 , L_10 , ( signed int ) V_47
+ V_45 ) ;
else if ( V_3 -> V_7 & V_8 )
V_49 += sprintf ( V_49 , L_11 , V_47 ) ;
else
V_49 += sprintf ( V_49 , L_12 , V_47 ) ;
if ( V_3 -> V_7 & V_58 )
V_48 = '(' ;
else if ( V_3 -> V_7 & V_53 ) {
V_49 += sprintf ( V_49 , L_13 ) ;
V_48 = ',' ;
} else
V_48 = ',' ;
}
} else
V_49 += sprintf ( V_49 , L_14 ) ;
return ( int ) ( V_49 - V_44 ) ;
}
void F_5 ( struct V_59 * V_60 )
{
char * V_61 = F_6 ( V_60 ) ? L_15 : L_16 ;
unsigned char V_1 [ 64 ] ;
char V_44 [ 64 ] , * V_49 ;
T_1 V_62 ;
unsigned long V_45 ;
int V_63 , V_64 , V_65 , V_66 , V_50 ;
V_62 = F_7 () ;
F_8 ( F_6 ( V_60 ) ? V_67 : V_68 ) ;
for ( V_63 = 32 ; V_63 && V_60 -> V_69 . V_45 >= 34 - V_63 ; V_63 -= 2 ) {
V_45 = V_60 -> V_69 . V_45 - 34 + V_63 ;
if ( F_9 ( V_1 + V_63 - 2 ,
( char V_70 * ) V_45 , 2 ) )
break;
}
for ( V_64 = 32 ; V_64 < 64 ; V_64 += 2 ) {
V_45 = V_60 -> V_69 . V_45 + V_64 - 32 ;
if ( F_9 ( V_1 + V_64 ,
( char V_70 * ) V_45 , 2 ) )
break;
}
F_8 ( V_62 ) ;
if ( ( V_60 -> V_69 . V_45 & 1 ) || V_63 >= V_64 ) {
F_10 ( L_17 , V_61 ) ;
return;
}
while ( V_63 < 32 ) {
for ( V_50 = 0 , V_66 = 0 ; V_63 + V_50 < 32 && V_66 < 3 ; V_66 ++ ) {
if ( ! F_2 ( V_1 + V_63 + V_50 ) )
break;
V_50 += F_11 ( V_1 [ V_63 + V_50 ] ) ;
}
if ( V_63 + V_50 == 32 )
break;
V_63 += 2 ;
}
V_49 = V_44 ;
V_49 += sprintf ( V_49 , L_18 , V_61 ) ;
V_66 = 0 ;
while ( V_63 < V_64 && V_66 < 8 ) {
V_65 = F_11 ( V_1 [ V_63 ] ) ;
if ( V_63 + V_65 == 32 )
* V_49 ++ = '#' ;
else if ( V_63 == 32 )
* V_49 ++ = '>' ;
else
* V_49 ++ = ' ' ;
V_45 = V_60 -> V_69 . V_45 + V_63 - 32 ;
V_49 += sprintf ( V_49 , V_71 , V_45 ) ;
if ( V_63 + V_65 >= V_64 )
break;
for ( V_50 = 0 ; V_50 < V_65 ; V_50 ++ )
V_49 += sprintf ( V_49 , L_19 , V_1 [ V_63 + V_50 ] ) ;
* V_49 ++ = '\t' ;
if ( V_50 < 6 )
* V_49 ++ = '\t' ;
V_49 += F_4 ( V_49 , V_1 + V_63 , V_45 ) ;
V_63 += V_65 ;
F_10 ( V_44 ) ;
V_49 = V_44 ;
V_49 += sprintf ( V_49 , L_20 ) ;
V_66 ++ ;
}
F_10 ( L_21 ) ;
}
void F_12 ( unsigned char * V_1 , unsigned long V_39 )
{
char V_44 [ 64 ] , * V_49 ;
int V_65 , V_50 ;
while ( V_39 ) {
V_49 = V_44 ;
V_65 = F_11 ( * V_1 ) ;
if ( V_65 > V_39 )
break;
V_49 += sprintf ( V_49 , L_22 , V_1 ) ;
for ( V_50 = 0 ; V_50 < V_65 ; V_50 ++ )
V_49 += sprintf ( V_49 , L_19 , V_1 [ V_50 ] ) ;
* V_49 ++ = '\t' ;
if ( V_50 < 4 )
* V_49 ++ = '\t' ;
V_49 += F_4 ( V_49 , V_1 , ( unsigned long ) V_1 ) ;
* V_49 ++ = '\n' ;
* V_49 ++ = 0 ;
F_10 ( V_44 ) ;
V_1 += V_65 ;
V_39 -= V_65 ;
}
}
