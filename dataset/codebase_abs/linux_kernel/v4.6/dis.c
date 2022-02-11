static unsigned int F_1 ( unsigned char * V_1 ,
const struct V_2 * V_3 )
{
unsigned char * V_4 ;
unsigned int V_5 ;
int V_6 ;
V_4 = V_1 + V_3 -> V_7 / 8 ;
V_6 = ( V_3 -> V_7 & 7 ) + V_3 -> V_6 ;
V_5 = 0 ;
do {
V_5 <<= 8 ;
V_5 |= ( unsigned int ) * V_4 ++ ;
V_6 -= 8 ;
} while ( V_6 > 0 );
V_5 >>= - V_6 ;
V_5 &= ( ( 1U << ( V_3 -> V_6 - 1 ) ) << 1 ) - 1 ;
if ( V_3 -> V_6 == 20 && V_3 -> V_7 == 20 )
V_5 = ( V_5 & 0xff ) << 12 | ( V_5 & 0xfff00 ) >> 8 ;
if ( V_3 -> V_8 & V_9 ) {
if ( V_3 -> V_7 == 8 )
V_5 |= ( V_1 [ 4 ] & 8 ) << 1 ;
else if ( V_3 -> V_7 == 12 )
V_5 |= ( V_1 [ 4 ] & 4 ) << 2 ;
else if ( V_3 -> V_7 == 16 )
V_5 |= ( V_1 [ 4 ] & 2 ) << 3 ;
else if ( V_3 -> V_7 == 32 )
V_5 |= ( V_1 [ 4 ] & 1 ) << 4 ;
}
if ( ( V_3 -> V_8 & ( V_10 | V_11 ) ) &&
( V_5 & ( 1U << ( V_3 -> V_6 - 1 ) ) ) )
V_5 |= ( - 1U << ( V_3 -> V_6 - 1 ) ) << 1 ;
if ( V_3 -> V_8 & V_11 )
V_5 <<= 1 ;
if ( V_3 -> V_8 & V_12 )
V_5 ++ ;
return V_5 ;
}
struct V_13 * F_2 ( unsigned char * V_1 )
{
unsigned char V_14 = V_1 [ 1 ] ;
unsigned char V_15 ;
struct V_13 * V_16 ;
switch ( V_1 [ 0 ] ) {
case 0x01 :
V_16 = V_17 ;
break;
case 0xa5 :
V_16 = V_18 ;
break;
case 0xa7 :
V_16 = V_19 ;
break;
case 0xaa :
V_16 = V_20 ;
break;
case 0xb2 :
V_16 = V_21 ;
break;
case 0xb3 :
V_16 = V_22 ;
break;
case 0xb9 :
V_16 = V_23 ;
break;
case 0xc0 :
V_16 = V_24 ;
break;
case 0xc2 :
V_16 = V_25 ;
break;
case 0xc4 :
V_16 = V_26 ;
break;
case 0xc6 :
V_16 = V_27 ;
break;
case 0xc8 :
V_16 = V_28 ;
break;
case 0xcc :
V_16 = V_29 ;
break;
case 0xe3 :
V_16 = V_30 ;
V_14 = V_1 [ 5 ] ;
break;
case 0xe5 :
V_16 = V_31 ;
break;
case 0xe7 :
V_16 = V_32 ;
V_14 = V_1 [ 5 ] ;
break;
case 0xeb :
V_16 = V_33 ;
V_14 = V_1 [ 5 ] ;
break;
case 0xec :
V_16 = V_34 ;
V_14 = V_1 [ 5 ] ;
break;
case 0xed :
V_16 = V_35 ;
V_14 = V_1 [ 5 ] ;
break;
default:
V_16 = V_36 ;
V_14 = V_1 [ 0 ] ;
break;
}
while ( V_16 -> V_37 != V_38 ) {
V_15 = V_39 [ V_16 -> V_37 ] [ 0 ] ;
if ( V_16 -> V_14 == ( V_14 & V_15 ) )
return V_16 ;
V_16 ++ ;
}
return NULL ;
}
int F_3 ( unsigned char * V_40 , char * V_41 , unsigned int V_42 )
{
struct V_13 * V_43 ;
V_43 = F_2 ( V_40 ) ;
if ( ! V_43 )
return - V_44 ;
if ( V_43 -> V_45 [ 0 ] == '\0' )
snprintf ( V_41 , V_42 , L_1 ,
V_46 [ ( int ) V_43 -> V_45 [ 1 ] ] ) ;
else
snprintf ( V_41 , V_42 , L_2 , V_43 -> V_45 ) ;
return 0 ;
}
static int F_4 ( char * V_47 , unsigned char * V_1 , unsigned long V_48 )
{
struct V_13 * V_43 ;
const unsigned char * V_49 ;
const struct V_2 * V_3 ;
unsigned int V_50 ;
char V_51 ;
char * V_52 ;
int V_53 ;
V_52 = V_47 ;
V_43 = F_2 ( V_1 ) ;
if ( V_43 ) {
if ( V_43 -> V_45 [ 0 ] == '\0' )
V_52 += sprintf ( V_52 , L_3 ,
V_46 [ ( int ) V_43 -> V_45 [ 1 ] ] ) ;
else
V_52 += sprintf ( V_52 , L_4 , V_43 -> V_45 ) ;
V_51 = 0 ;
for ( V_49 = V_39 [ V_43 -> V_37 ] + 1 , V_53 = 0 ;
* V_49 != 0 && V_53 < 6 ; V_49 ++ , V_53 ++ ) {
V_3 = V_54 + * V_49 ;
V_50 = F_1 ( V_1 , V_3 ) ;
if ( ( V_3 -> V_8 & V_55 ) && V_50 == 0 )
continue;
if ( ( V_3 -> V_8 & V_56 ) &&
V_50 == 0 && V_51 == '(' ) {
V_51 = ',' ;
continue;
}
if ( V_51 )
V_52 += sprintf ( V_52 , L_5 , V_51 ) ;
if ( V_3 -> V_8 & V_57 )
V_52 += sprintf ( V_52 , L_6 , V_50 ) ;
else if ( V_3 -> V_8 & V_58 )
V_52 += sprintf ( V_52 , L_7 , V_50 ) ;
else if ( V_3 -> V_8 & V_59 )
V_52 += sprintf ( V_52 , L_8 , V_50 ) ;
else if ( V_3 -> V_8 & V_60 )
V_52 += sprintf ( V_52 , L_9 , V_50 ) ;
else if ( V_3 -> V_8 & V_9 )
V_52 += sprintf ( V_52 , L_10 , V_50 ) ;
else if ( V_3 -> V_8 & V_11 )
V_52 += sprintf ( V_52 , L_11 , ( signed int ) V_50
+ V_48 ) ;
else if ( V_3 -> V_8 & V_10 )
V_52 += sprintf ( V_52 , L_12 , V_50 ) ;
else
V_52 += sprintf ( V_52 , L_13 , V_50 ) ;
if ( V_3 -> V_8 & V_61 )
V_51 = '(' ;
else if ( V_3 -> V_8 & V_56 ) {
V_52 += sprintf ( V_52 , L_14 ) ;
V_51 = ',' ;
} else
V_51 = ',' ;
}
} else
V_52 += sprintf ( V_52 , L_15 ) ;
return ( int ) ( V_52 - V_47 ) ;
}
void F_5 ( struct V_62 * V_63 )
{
char * V_64 = F_6 ( V_63 ) ? L_16 : L_17 ;
unsigned char V_1 [ 64 ] ;
char V_47 [ 64 ] , * V_52 ;
T_1 V_65 ;
unsigned long V_48 ;
int V_66 , V_67 , V_68 , V_69 , V_53 ;
V_65 = F_7 () ;
F_8 ( F_6 ( V_63 ) ? V_70 : V_71 ) ;
for ( V_66 = 32 ; V_66 && V_63 -> V_72 . V_48 >= 34 - V_66 ; V_66 -= 2 ) {
V_48 = V_63 -> V_72 . V_48 - 34 + V_66 ;
if ( F_9 ( V_1 + V_66 - 2 ,
( char V_73 * ) V_48 , 2 ) )
break;
}
for ( V_67 = 32 ; V_67 < 64 ; V_67 += 2 ) {
V_48 = V_63 -> V_72 . V_48 + V_67 - 32 ;
if ( F_9 ( V_1 + V_67 ,
( char V_73 * ) V_48 , 2 ) )
break;
}
F_8 ( V_65 ) ;
if ( ( V_63 -> V_72 . V_48 & 1 ) || V_66 >= V_67 ) {
F_10 ( L_18 , V_64 ) ;
return;
}
while ( V_66 < 32 ) {
for ( V_53 = 0 , V_69 = 0 ; V_66 + V_53 < 32 && V_69 < 3 ; V_69 ++ ) {
if ( ! F_2 ( V_1 + V_66 + V_53 ) )
break;
V_53 += F_11 ( V_1 [ V_66 + V_53 ] ) ;
}
if ( V_66 + V_53 == 32 )
break;
V_66 += 2 ;
}
V_52 = V_47 ;
V_52 += sprintf ( V_52 , L_19 , V_64 ) ;
V_69 = 0 ;
while ( V_66 < V_67 && V_69 < 8 ) {
V_68 = F_11 ( V_1 [ V_66 ] ) ;
if ( V_66 + V_68 == 32 )
* V_52 ++ = '#' ;
else if ( V_66 == 32 )
* V_52 ++ = '>' ;
else
* V_52 ++ = ' ' ;
V_48 = V_63 -> V_72 . V_48 + V_66 - 32 ;
V_52 += sprintf ( V_52 , L_20 , V_48 ) ;
if ( V_66 + V_68 >= V_67 )
break;
for ( V_53 = 0 ; V_53 < V_68 ; V_53 ++ )
V_52 += sprintf ( V_52 , L_21 , V_1 [ V_66 + V_53 ] ) ;
* V_52 ++ = '\t' ;
if ( V_53 < 6 )
* V_52 ++ = '\t' ;
V_52 += F_4 ( V_52 , V_1 + V_66 , V_48 ) ;
V_66 += V_68 ;
F_10 ( L_1 , V_47 ) ;
V_52 = V_47 ;
V_52 += sprintf ( V_52 , L_22 ) ;
V_69 ++ ;
}
F_10 ( L_23 ) ;
}
void F_12 ( unsigned char * V_1 , unsigned long V_42 )
{
char V_47 [ 64 ] , * V_52 ;
int V_68 , V_53 ;
while ( V_42 ) {
V_52 = V_47 ;
V_68 = F_11 ( * V_1 ) ;
if ( V_68 > V_42 )
break;
V_52 += sprintf ( V_52 , L_24 , V_1 ) ;
for ( V_53 = 0 ; V_53 < V_68 ; V_53 ++ )
V_52 += sprintf ( V_52 , L_21 , V_1 [ V_53 ] ) ;
* V_52 ++ = '\t' ;
if ( V_53 < 4 )
* V_52 ++ = '\t' ;
V_52 += F_4 ( V_52 , V_1 , ( unsigned long ) V_1 ) ;
* V_52 ++ = '\n' ;
* V_52 ++ = 0 ;
F_10 ( L_1 , V_47 ) ;
V_1 += V_68 ;
V_42 -= V_68 ;
}
}
