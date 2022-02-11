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
int V_10 , V_11 ;
T_1 * V_12 ;
unsigned char * V_13 ;
int V_14 ;
char V_15 [ 32 ] ;
int (* F_3)( unsigned long , void * ) = NULL ;
if( V_3 == - 1 ) V_3 = strlen ( ( const char * ) V_2 ) ;
if( ! V_5 ) V_5 = V_16 ;
switch( V_4 ) {
case V_17 :
if( V_3 & 1 ) {
F_4 ( V_18 ,
V_19 ) ;
return - 1 ;
}
V_14 = V_3 >> 1 ;
break;
case V_20 :
if( V_3 & 3 ) {
F_4 ( V_18 ,
V_21 ) ;
return - 1 ;
}
V_14 = V_3 >> 2 ;
break;
case V_22 :
V_14 = 0 ;
V_9 = F_5 ( V_2 , V_3 , V_22 , V_23 , & V_14 ) ;
if( V_9 < 0 ) {
F_4 ( V_18 ,
V_24 ) ;
return - 1 ;
}
break;
case V_25 :
V_14 = V_3 ;
break;
default:
F_4 ( V_18 , V_26 ) ;
return - 1 ;
}
if( ( V_6 > 0 ) && ( V_14 < V_6 ) ) {
F_4 ( V_18 , V_27 ) ;
sprintf ( V_15 , L_1 , V_6 ) ;
F_6 ( 2 , L_2 , V_15 ) ;
return - 1 ;
}
if( ( V_7 > 0 ) && ( V_14 > V_7 ) ) {
F_4 ( V_18 , V_28 ) ;
sprintf ( V_15 , L_1 , V_7 ) ;
F_6 ( 2 , L_3 , V_15 ) ;
return - 1 ;
}
if( F_5 ( V_2 , V_3 , V_4 , V_29 , & V_5 ) < 0 ) {
F_4 ( V_18 , V_30 ) ;
return - 1 ;
}
V_10 = V_25 ;
if( V_5 & V_31 ) V_8 = V_32 ;
else if( V_5 & V_33 ) V_8 = V_34 ;
else if( V_5 & V_35 ) V_8 = V_36 ;
else if( V_5 & V_37 ) {
V_8 = V_38 ;
V_10 = V_17 ;
} else if( V_5 & V_39 ) {
V_8 = V_40 ;
V_10 = V_20 ;
} else {
V_8 = V_41 ;
V_10 = V_22 ;
}
if( ! V_1 ) return V_8 ;
if( * V_1 ) {
V_12 = * V_1 ;
if( V_12 -> V_42 ) {
V_12 -> V_43 = 0 ;
Free ( V_12 -> V_42 ) ;
V_12 -> V_42 = NULL ;
}
V_12 -> type = V_8 ;
} else {
V_12 = F_7 ( V_8 ) ;
if( ! V_12 ) {
F_4 ( V_18 ,
V_44 ) ;
return - 1 ;
}
* V_1 = V_12 ;
}
if( V_4 == V_10 ) {
if( ! F_8 ( V_12 , V_2 , V_3 ) ) {
F_4 ( V_18 , V_44 ) ;
return - 1 ;
}
return V_8 ;
}
switch( V_10 ) {
case V_25 :
V_11 = V_14 ;
F_3 = V_45 ;
break;
case V_17 :
V_11 = V_14 << 1 ;
F_3 = V_46 ;
break;
case V_20 :
V_11 = V_14 << 2 ;
F_3 = V_47 ;
break;
case V_22 :
V_11 = 0 ;
F_5 ( V_2 , V_3 , V_4 , V_48 , & V_11 ) ;
F_3 = V_49 ;
break;
}
if( ! ( V_13 = Malloc ( V_11 + 1 ) ) ) {
F_9 ( V_12 ) ;
F_4 ( V_18 , V_44 ) ;
return - 1 ;
}
V_12 -> V_43 = V_11 ;
V_12 -> V_42 = V_13 ;
V_13 [ V_11 ] = 0 ;
F_5 ( V_2 , V_3 , V_4 , F_3 , & V_13 ) ;
return V_8 ;
}
static int F_5 ( const unsigned char * V_13 , int V_3 , int V_4 ,
int (* F_10)( unsigned long V_50 , void * V_2 ) , void * V_51 )
{
unsigned long V_50 ;
int V_9 ;
while( V_3 ) {
if( V_4 == V_25 ) {
V_50 = * V_13 ++ ;
V_3 -- ;
} else if( V_4 == V_17 ) {
V_50 = * V_13 ++ << 8 ;
V_50 |= * V_13 ++ ;
V_3 -= 2 ;
} else if( V_4 == V_20 ) {
V_50 = * V_13 ++ << 24 ;
V_50 |= * V_13 ++ << 16 ;
V_50 |= * V_13 ++ << 8 ;
V_50 |= * V_13 ++ ;
V_3 -= 4 ;
} else {
V_9 = F_11 ( V_13 , V_3 , & V_50 ) ;
if( V_9 < 0 ) return - 1 ;
V_3 -= V_9 ;
V_13 += V_9 ;
}
if( F_10 ) {
V_9 = F_10 ( V_50 , V_51 ) ;
if( V_9 <= 0 ) return V_9 ;
}
}
return 1 ;
}
static int V_23 ( unsigned long V_50 , void * V_51 )
{
int * V_14 ;
V_14 = V_51 ;
( * V_14 ) ++ ;
return 1 ;
}
static int V_48 ( unsigned long V_50 , void * V_51 )
{
long * V_11 ;
V_11 = V_51 ;
* V_11 += F_12 ( NULL , - 1 , V_50 ) ;
return 1 ;
}
static int V_29 ( unsigned long V_50 , void * V_51 )
{
unsigned long V_52 ;
V_52 = * ( ( unsigned long * ) V_51 ) ;
if( ( V_52 & V_31 ) && ! F_13 ( V_50 ) )
V_52 &= ~ V_31 ;
if( ( V_52 & V_33 ) && ( V_50 > 127 ) )
V_52 &= ~ V_33 ;
if( ( V_52 & V_35 ) && ( V_50 > 0xff ) )
V_52 &= ~ V_35 ;
if( ( V_52 & V_37 ) && ( V_50 > 0xffff ) )
V_52 &= ~ V_37 ;
if( ! V_52 ) return - 1 ;
* ( ( unsigned long * ) V_51 ) = V_52 ;
return 1 ;
}
static int V_45 ( unsigned long V_50 , void * V_51 )
{
unsigned char * * V_13 , * V_53 ;
V_13 = V_51 ;
V_53 = * V_13 ;
* V_53 = ( unsigned char ) V_50 ;
( * V_13 ) ++ ;
return 1 ;
}
static int V_46 ( unsigned long V_50 , void * V_51 )
{
unsigned char * * V_13 , * V_53 ;
V_13 = V_51 ;
V_53 = * V_13 ;
* V_53 ++ = ( unsigned char ) ( ( V_50 >> 8 ) & 0xff ) ;
* V_53 = ( unsigned char ) ( V_50 & 0xff ) ;
* V_13 += 2 ;
return 1 ;
}
static int V_47 ( unsigned long V_50 , void * V_51 )
{
unsigned char * * V_13 , * V_53 ;
V_13 = V_51 ;
V_53 = * V_13 ;
* V_53 ++ = ( unsigned char ) ( ( V_50 >> 24 ) & 0xff ) ;
* V_53 ++ = ( unsigned char ) ( ( V_50 >> 16 ) & 0xff ) ;
* V_53 ++ = ( unsigned char ) ( ( V_50 >> 8 ) & 0xff ) ;
* V_53 = ( unsigned char ) ( V_50 & 0xff ) ;
* V_13 += 4 ;
return 1 ;
}
static int V_49 ( unsigned long V_50 , void * V_51 )
{
unsigned char * * V_13 ;
int V_9 ;
V_13 = V_51 ;
V_9 = F_12 ( * V_13 , 0xff , V_50 ) ;
* V_13 += V_9 ;
return 1 ;
}
static int F_13 ( unsigned long V_50 )
{
int V_54 ;
if( V_50 > 0x7f ) return 0 ;
V_54 = ( int ) V_50 ;
if( ( V_54 >= 'a' ) && ( V_54 <= 'z' ) ) return 1 ;
if( ( V_54 >= 'A' ) && ( V_54 <= 'Z' ) ) return 1 ;
if( ( V_54 >= '0' ) && ( V_54 <= '9' ) ) return 1 ;
if ( ( V_54 == ' ' ) || strchr ( L_4 , V_54 ) ) return 1 ;
return 0 ;
}
