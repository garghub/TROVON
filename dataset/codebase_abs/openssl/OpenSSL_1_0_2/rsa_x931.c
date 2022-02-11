int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 ;
unsigned char * V_6 ;
V_5 = V_2 - V_4 - 2 ;
if ( V_5 < 0 ) {
F_2 ( V_7 , V_8 ) ;
return - 1 ;
}
V_6 = ( unsigned char * ) V_1 ;
if ( V_5 == 0 )
* V_6 ++ = 0x6A ;
else {
* V_6 ++ = 0x6B ;
if ( V_5 > 1 ) {
memset ( V_6 , 0xBB , V_5 - 1 ) ;
V_6 += V_5 - 1 ;
}
* V_6 ++ = 0xBA ;
}
memcpy ( V_6 , V_3 , ( unsigned int ) V_4 ) ;
V_6 += V_4 ;
* V_6 = 0xCC ;
return ( 1 ) ;
}
int F_3 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_9 )
{
int V_10 = 0 , V_5 ;
const unsigned char * V_6 ;
V_6 = V_3 ;
if ( ( V_9 != V_4 ) || ( ( * V_6 != 0x6A ) && ( * V_6 != 0x6B ) ) ) {
F_2 ( V_11 , V_12 ) ;
return - 1 ;
}
if ( * V_6 ++ == 0x6B ) {
V_5 = V_4 - 3 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
unsigned char V_13 = * V_6 ++ ;
if ( V_13 == 0xBA )
break;
if ( V_13 != 0xBB ) {
F_2 ( V_11 , V_14 ) ;
return - 1 ;
}
}
V_5 -= V_10 ;
if ( V_10 == 0 ) {
F_2 ( V_11 , V_14 ) ;
return - 1 ;
}
} else
V_5 = V_4 - 2 ;
if ( V_6 [ V_5 ] != 0xCC ) {
F_2 ( V_11 , V_15 ) ;
return - 1 ;
}
memcpy ( V_1 , V_6 , ( unsigned int ) V_5 ) ;
return ( V_5 ) ;
}
int F_4 ( int V_16 )
{
switch ( V_16 ) {
case V_17 :
return 0x33 ;
case V_18 :
return 0x34 ;
case V_19 :
return 0x36 ;
case V_20 :
return 0x35 ;
}
return - 1 ;
}
