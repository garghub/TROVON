void * memmove ( void * V_1 , const void * V_2 , T_1 V_3 )
{
const char * V_4 = V_2 ;
char * V_5 = V_1 ;
if ( ! V_3 )
return V_1 ;
if ( V_1 <= V_2 )
return memcpy ( V_1 , V_2 , V_3 ) ;
V_4 += V_3 ;
V_5 += V_3 ;
while ( V_3 -- )
* -- V_5 = * -- V_4 ;
return V_1 ;
}
void * memmove ( void * V_1 , const void * V_2 , T_1 V_3 )
{
const char * V_4 = V_2 ;
char * V_5 = V_1 ;
const T_2 * V_6 ;
T_2 * V_7 ;
if ( ! V_3 )
return V_1 ;
if ( V_1 <= V_2 )
return memcpy ( V_1 , V_2 , V_3 ) ;
V_5 += V_3 ;
V_4 += V_3 ;
if ( V_3 >= 4 ) {
unsigned V_8 , V_9 ;
switch ( ( unsigned long ) V_5 & 3 ) {
case 3 :
* -- V_5 = * -- V_4 ;
-- V_3 ;
case 2 :
* -- V_5 = * -- V_4 ;
-- V_3 ;
case 1 :
* -- V_5 = * -- V_4 ;
-- V_3 ;
}
V_7 = ( void * ) V_5 ;
switch ( ( unsigned long ) V_4 & 3 ) {
case 0x0 :
V_6 = ( const void * ) V_4 ;
for (; V_3 >= 4 ; V_3 -= 4 )
* -- V_7 = * -- V_6 ;
V_4 = ( const void * ) V_6 ;
break;
case 0x1 :
V_6 = ( const void * ) ( ( ( unsigned ) V_4 + 4 ) & ~ 3 ) ;
#ifndef F_1
V_9 = * -- V_6 >> 24 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 << 8 | V_8 ;
V_9 = V_8 >> 24 ;
}
#else
V_9 = ( * -- V_6 & 0xFF ) << 24 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 | ( ( V_8 & 0xFFFFFF00 ) >> 8 ) ;
V_9 = ( V_8 & 0xFF ) << 24 ;
}
#endif
V_4 = ( const void * ) V_6 ;
V_4 += 1 ;
break;
case 0x2 :
V_6 = ( const void * ) ( ( ( unsigned ) V_4 + 4 ) & ~ 3 ) ;
#ifndef F_1
V_9 = * -- V_6 >> 16 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 << 16 | V_8 ;
V_9 = V_8 >> 16 ;
}
#else
V_9 = ( * -- V_6 & 0xFFFF ) << 16 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 | ( ( V_8 & 0xFFFF0000 ) >> 16 ) ;
V_9 = ( V_8 & 0xFFFF ) << 16 ;
}
#endif
V_4 = ( const void * ) V_6 ;
V_4 += 2 ;
break;
case 0x3 :
V_6 = ( const void * ) ( ( ( unsigned ) V_4 + 4 ) & ~ 3 ) ;
#ifndef F_1
V_9 = * -- V_6 >> 8 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 << 24 | V_8 ;
V_9 = V_8 >> 8 ;
}
#else
V_9 = ( * -- V_6 & 0xFFFFFF ) << 8 ;
for (; V_3 >= 4 ; V_3 -= 4 ) {
V_8 = * -- V_6 ;
* -- V_7 = V_9 | ( ( V_8 & 0xFF000000 ) >> 24 ) ;
V_9 = ( V_8 & 0xFFFFFF ) << 8 ;
}
#endif
V_4 = ( const void * ) V_6 ;
V_4 += 3 ;
break;
}
V_5 = ( void * ) V_7 ;
}
switch ( V_3 ) {
case 4 :
* -- V_5 = * -- V_4 ;
case 3 :
* -- V_5 = * -- V_4 ;
case 2 :
* -- V_5 = * -- V_4 ;
case 1 :
* -- V_5 = * -- V_4 ;
}
return V_1 ;
}
