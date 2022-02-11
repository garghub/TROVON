void F_1 ( unsigned long V_1 , const void * V_2 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
const T_2 * V_5 = V_2 ;
while ( V_3 -- )
F_2 ( * V_5 ++ , V_4 ) ;
}
void F_3 ( unsigned long V_1 , const void * V_2 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
while ( V_3 -- ) {
F_4 ( * ( V_6 * ) V_2 , V_4 ) ;
V_2 += sizeof( V_6 ) ;
}
}
void F_5 ( unsigned long V_1 , const void * V_2 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
T_3 V_7 , V_8 ;
if ( ! V_3 )
return;
switch ( ( ( unsigned long ) V_2 ) & 0x3 ) {
case 0x0 :
while ( V_3 -- ) {
F_6 ( * ( T_3 * ) V_2 , V_4 ) ;
V_2 += sizeof( T_3 ) ;
}
break;
case 0x2 :
while ( V_3 -- ) {
V_7 = ( * ( V_6 * ) V_2 ) << 16 ;
V_7 |= * ( V_6 * ) ( V_2 + sizeof( V_6 ) ) ;
F_6 ( V_7 , V_4 ) ;
V_2 += sizeof( T_3 ) ;
}
break;
case 0x1 :
V_7 = ( * ( T_2 * ) V_2 ) << 24 ;
V_7 |= ( * ( V_6 * ) ( V_2 + sizeof( T_2 ) ) ) << 8 ;
V_2 += sizeof( T_2 ) + sizeof( V_6 ) ;
while ( V_3 -- ) {
V_8 = * ( T_3 * ) V_2 ;
V_7 |= ( V_8 >> 24 ) ;
F_6 ( V_7 , V_4 ) ;
V_7 = V_8 << 8 ;
V_2 += sizeof( T_3 ) ;
}
break;
case 0x3 :
V_7 = ( * ( T_2 * ) V_2 ) << 24 ;
V_2 += sizeof( T_2 ) ;
while ( V_3 -- ) {
V_8 = * ( T_3 * ) V_2 ;
V_7 |= ( V_8 >> 8 ) ;
F_6 ( V_7 , V_4 ) ;
V_7 = V_8 << 24 ;
V_2 += sizeof( T_3 ) ;
}
break;
}
}
void F_7 ( unsigned long V_1 , void * V_9 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
if ( V_3 ) {
T_3 * V_10 ;
T_2 * V_11 = V_9 ;
while ( ( ( ( unsigned long ) V_11 ) & 0x3 ) && V_3 -- )
* V_11 ++ = F_8 ( V_4 ) ;
V_10 = ( T_3 * ) V_11 ;
while ( V_3 >= 4 ) {
T_3 V_12 ;
V_12 = ( F_8 ( V_4 ) << 24 ) ;
V_12 |= ( F_8 ( V_4 ) << 16 ) ;
V_12 |= ( F_8 ( V_4 ) << 8 ) ;
V_12 |= ( F_8 ( V_4 ) << 0 ) ;
* V_10 ++ = V_12 ;
V_3 -= 4 ;
}
V_11 = ( T_2 * ) V_10 ;
while ( V_3 -- )
* V_11 ++ = F_8 ( V_4 ) ;
}
}
void F_9 ( unsigned long V_1 , void * V_9 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
if ( V_3 ) {
V_6 * V_13 = V_9 ;
T_3 * V_10 ;
if ( ( ( unsigned long ) V_13 ) & 0x2 ) {
* V_13 ++ = F_10 ( V_4 ) ;
V_3 -- ;
}
V_10 = ( T_3 * ) V_13 ;
while ( V_3 >= 2 ) {
T_3 V_12 ;
V_12 = F_10 ( V_4 ) << 16 ;
V_12 |= F_10 ( V_4 ) << 0 ;
* V_10 ++ = V_12 ;
V_3 -= 2 ;
}
V_13 = ( V_6 * ) V_10 ;
if ( V_3 )
* V_13 = F_10 ( V_4 ) ;
}
}
void F_11 ( unsigned long V_1 , void * V_9 , unsigned long V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
if ( V_3 ) {
if ( ( ( ( unsigned long ) V_9 ) & 0x3 ) == 0 ) {
T_3 * V_10 = V_9 ;
while ( V_3 -- )
* V_10 ++ = F_12 ( V_4 ) ;
} else {
T_3 V_7 = 0 , V_8 , * V_10 ;
V_6 * V_13 ;
T_2 * V_11 ;
switch ( ( ( unsigned long ) V_9 ) & 3 ) {
case 0x2 :
V_13 = V_9 ;
V_3 -= 1 ;
V_7 = F_12 ( V_4 ) ;
* V_13 ++ = V_7 ;
V_10 = ( T_3 * ) V_13 ;
while ( V_3 -- ) {
V_8 = F_12 ( V_4 ) ;
* V_10 ++ = ( V_7 << 16 ) | ( V_8 >> 16 ) ;
V_7 = V_8 ;
}
V_13 = ( V_6 * ) V_10 ;
* V_13 = V_7 ;
break;
case 0x1 :
V_11 = V_9 ;
V_3 -= 1 ;
V_7 = F_12 ( V_4 ) ;
* V_11 ++ = V_7 >> 24 ;
V_13 = ( V_6 * ) V_11 ;
* V_13 ++ = ( ( V_7 >> 8 ) & 0xffff ) ;
V_10 = ( T_3 * ) V_13 ;
while ( V_3 -- ) {
V_8 = F_12 ( V_4 ) ;
* V_10 ++ = ( V_7 << 24 ) | ( V_8 >> 8 ) ;
V_7 = V_8 ;
}
V_11 = ( T_2 * ) V_10 ;
* V_11 = V_7 ;
break;
case 0x3 :
V_11 = ( T_2 * ) V_9 ;
V_3 -= 1 ;
V_7 = F_12 ( V_4 ) ;
* V_11 ++ = V_7 >> 24 ;
V_10 = ( T_3 * ) V_11 ;
while ( V_3 -- ) {
V_8 = F_12 ( V_4 ) ;
* V_10 ++ = ( V_7 << 8 ) | ( V_8 >> 24 ) ;
V_7 = V_8 ;
}
V_13 = ( V_6 * ) V_10 ;
* V_13 ++ = ( ( V_7 >> 8 ) & 0xffff ) ;
V_11 = ( T_2 * ) V_13 ;
* V_11 = V_7 ;
break;
}
}
}
}
