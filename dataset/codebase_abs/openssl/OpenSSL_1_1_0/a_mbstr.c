int F_1 ( T_1 * * V_1 , const unsigned char * V_2 , int V_3 ,
int V_4 , unsigned long V_5 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , 0 , 0 ) ;
}
int F_2 ( T_1 * * V_1 , const unsigned char * V_2 , int V_3 ,
int V_4 , unsigned long V_5 ,
long V_6 , long V_7 )
{
int V_8 ;
int V_9 ;
char V_10 ;
int V_11 , V_12 = 0 ;
T_1 * V_13 ;
unsigned char * V_14 ;
int V_15 ;
char V_16 [ 32 ] ;
int (* F_3) ( unsigned long , void * ) = NULL ;
if ( V_3 == - 1 )
V_3 = strlen ( ( const char * ) V_2 ) ;
if ( ! V_5 )
V_5 = V_17 ;
switch ( V_4 ) {
case V_18 :
if ( V_3 & 1 ) {
F_4 ( V_19 ,
V_20 ) ;
return - 1 ;
}
V_15 = V_3 >> 1 ;
break;
case V_21 :
if ( V_3 & 3 ) {
F_4 ( V_19 ,
V_22 ) ;
return - 1 ;
}
V_15 = V_3 >> 2 ;
break;
case V_23 :
V_15 = 0 ;
V_9 = F_5 ( V_2 , V_3 , V_23 , V_24 , & V_15 ) ;
if ( V_9 < 0 ) {
F_4 ( V_19 , V_25 ) ;
return - 1 ;
}
break;
case V_26 :
V_15 = V_3 ;
break;
default:
F_4 ( V_19 , V_27 ) ;
return - 1 ;
}
if ( ( V_6 > 0 ) && ( V_15 < V_6 ) ) {
F_4 ( V_19 , V_28 ) ;
F_6 ( V_16 , sizeof V_16 , L_1 , V_6 ) ;
F_7 ( 2 , L_2 , V_16 ) ;
return - 1 ;
}
if ( ( V_7 > 0 ) && ( V_15 > V_7 ) ) {
F_4 ( V_19 , V_29 ) ;
F_6 ( V_16 , sizeof V_16 , L_1 , V_7 ) ;
F_7 ( 2 , L_3 , V_16 ) ;
return - 1 ;
}
if ( F_5 ( V_2 , V_3 , V_4 , V_30 , & V_5 ) < 0 ) {
F_4 ( V_19 , V_31 ) ;
return - 1 ;
}
V_11 = V_26 ;
if ( V_5 & V_32 )
V_8 = V_33 ;
else if ( V_5 & V_34 )
V_8 = V_35 ;
else if ( V_5 & V_36 )
V_8 = V_37 ;
else if ( V_5 & V_38 )
V_8 = V_39 ;
else if ( V_5 & V_40 ) {
V_8 = V_41 ;
V_11 = V_18 ;
} else if ( V_5 & V_42 ) {
V_8 = V_43 ;
V_11 = V_21 ;
} else {
V_8 = V_44 ;
V_11 = V_23 ;
}
if ( ! V_1 )
return V_8 ;
if ( * V_1 ) {
V_10 = 0 ;
V_13 = * V_1 ;
F_8 ( V_13 -> V_45 ) ;
V_13 -> V_45 = NULL ;
V_13 -> V_46 = 0 ;
V_13 -> type = V_8 ;
} else {
V_10 = 1 ;
V_13 = F_9 ( V_8 ) ;
if ( V_13 == NULL ) {
F_4 ( V_19 , V_47 ) ;
return - 1 ;
}
* V_1 = V_13 ;
}
if ( V_4 == V_11 ) {
if ( ! F_10 ( V_13 , V_2 , V_3 ) ) {
F_4 ( V_19 , V_47 ) ;
return - 1 ;
}
return V_8 ;
}
switch ( V_11 ) {
case V_26 :
V_12 = V_15 ;
F_3 = V_48 ;
break;
case V_18 :
V_12 = V_15 << 1 ;
F_3 = V_49 ;
break;
case V_21 :
V_12 = V_15 << 2 ;
F_3 = V_50 ;
break;
case V_23 :
V_12 = 0 ;
F_5 ( V_2 , V_3 , V_4 , V_51 , & V_12 ) ;
F_3 = V_52 ;
break;
}
if ( ( V_14 = F_11 ( V_12 + 1 ) ) == NULL ) {
if ( V_10 )
F_12 ( V_13 ) ;
F_4 ( V_19 , V_47 ) ;
return - 1 ;
}
V_13 -> V_46 = V_12 ;
V_13 -> V_45 = V_14 ;
V_14 [ V_12 ] = 0 ;
F_5 ( V_2 , V_3 , V_4 , F_3 , & V_14 ) ;
return V_8 ;
}
static int F_5 ( const unsigned char * V_14 , int V_3 , int V_4 ,
int (* F_13) ( unsigned long V_53 , void * V_2 ) ,
void * V_54 )
{
unsigned long V_53 ;
int V_9 ;
while ( V_3 ) {
if ( V_4 == V_26 ) {
V_53 = * V_14 ++ ;
V_3 -- ;
} else if ( V_4 == V_18 ) {
V_53 = * V_14 ++ << 8 ;
V_53 |= * V_14 ++ ;
V_3 -= 2 ;
} else if ( V_4 == V_21 ) {
V_53 = ( ( unsigned long ) * V_14 ++ ) << 24 ;
V_53 |= ( ( unsigned long ) * V_14 ++ ) << 16 ;
V_53 |= * V_14 ++ << 8 ;
V_53 |= * V_14 ++ ;
V_3 -= 4 ;
} else {
V_9 = F_14 ( V_14 , V_3 , & V_53 ) ;
if ( V_9 < 0 )
return - 1 ;
V_3 -= V_9 ;
V_14 += V_9 ;
}
if ( F_13 ) {
V_9 = F_13 ( V_53 , V_54 ) ;
if ( V_9 <= 0 )
return V_9 ;
}
}
return 1 ;
}
static int V_24 ( unsigned long V_53 , void * V_54 )
{
int * V_15 ;
V_15 = V_54 ;
( * V_15 ) ++ ;
return 1 ;
}
static int V_51 ( unsigned long V_53 , void * V_54 )
{
int * V_12 ;
V_12 = V_54 ;
* V_12 += F_15 ( NULL , - 1 , V_53 ) ;
return 1 ;
}
static int V_30 ( unsigned long V_53 , void * V_54 )
{
unsigned long V_55 ;
V_55 = * ( ( unsigned long * ) V_54 ) ;
if ( ( V_55 & V_32 ) && ! F_16 ( V_53 ) )
V_55 &= ~ V_32 ;
if ( ( V_55 & V_34 ) && ! F_17 ( V_53 ) )
V_55 &= ~ V_34 ;
if ( ( V_55 & V_36 ) && ( V_53 > 127 ) )
V_55 &= ~ V_36 ;
if ( ( V_55 & V_38 ) && ( V_53 > 0xff ) )
V_55 &= ~ V_38 ;
if ( ( V_55 & V_40 ) && ( V_53 > 0xffff ) )
V_55 &= ~ V_40 ;
if ( ! V_55 )
return - 1 ;
* ( ( unsigned long * ) V_54 ) = V_55 ;
return 1 ;
}
static int V_48 ( unsigned long V_53 , void * V_54 )
{
unsigned char * * V_14 , * V_56 ;
V_14 = V_54 ;
V_56 = * V_14 ;
* V_56 = ( unsigned char ) V_53 ;
( * V_14 ) ++ ;
return 1 ;
}
static int V_49 ( unsigned long V_53 , void * V_54 )
{
unsigned char * * V_14 , * V_56 ;
V_14 = V_54 ;
V_56 = * V_14 ;
* V_56 ++ = ( unsigned char ) ( ( V_53 >> 8 ) & 0xff ) ;
* V_56 = ( unsigned char ) ( V_53 & 0xff ) ;
* V_14 += 2 ;
return 1 ;
}
static int V_50 ( unsigned long V_53 , void * V_54 )
{
unsigned char * * V_14 , * V_56 ;
V_14 = V_54 ;
V_56 = * V_14 ;
* V_56 ++ = ( unsigned char ) ( ( V_53 >> 24 ) & 0xff ) ;
* V_56 ++ = ( unsigned char ) ( ( V_53 >> 16 ) & 0xff ) ;
* V_56 ++ = ( unsigned char ) ( ( V_53 >> 8 ) & 0xff ) ;
* V_56 = ( unsigned char ) ( V_53 & 0xff ) ;
* V_14 += 4 ;
return 1 ;
}
static int V_52 ( unsigned long V_53 , void * V_54 )
{
unsigned char * * V_14 ;
int V_9 ;
V_14 = V_54 ;
V_9 = F_15 ( * V_14 , 0xff , V_53 ) ;
* V_14 += V_9 ;
return 1 ;
}
static int F_17 ( unsigned long V_53 )
{
int V_57 ;
if ( V_53 > 0x7f )
return 0 ;
V_57 = ( int ) V_53 ;
#ifndef F_18
if ( ( V_57 >= 'a' ) && ( V_57 <= 'z' ) )
return 1 ;
if ( ( V_57 >= 'A' ) && ( V_57 <= 'Z' ) )
return 1 ;
if ( ( V_57 >= '0' ) && ( V_57 <= '9' ) )
return 1 ;
if ( ( V_57 == ' ' ) || strchr ( L_4 , V_57 ) )
return 1 ;
#else
if ( ( V_57 >= V_58 [ 'a' ] ) && ( V_57 <= V_58 [ 'z' ] ) )
return 1 ;
if ( ( V_57 >= V_58 [ 'A' ] ) && ( V_57 <= V_58 [ 'Z' ] ) )
return 1 ;
if ( ( V_57 >= V_58 [ '0' ] ) && ( V_57 <= V_58 [ '9' ] ) )
return 1 ;
if ( ( V_57 == V_58 [ ' ' ] ) || strchr ( L_4 , V_59 [ V_57 ] ) )
return 1 ;
#endif
return 0 ;
}
static int F_16 ( unsigned long V_53 )
{
int V_57 ;
if ( V_53 > 0x7f )
return 0 ;
V_57 = ( int ) V_53 ;
#ifndef F_18
if ( ! isdigit ( V_57 ) && V_57 != ' ' )
return 0 ;
#else
if ( V_57 > V_58 [ '9' ] )
return 0 ;
if ( V_57 < V_58 [ '0' ] && V_57 != V_58 [ ' ' ] )
return 0 ;
#endif
return 1 ;
}
