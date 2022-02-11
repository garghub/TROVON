static inline T_1
F_1 ( T_1 V_1 , unsigned long int V_2 )
{
return F_2 ( V_1 ,
F_3 ( F_4 ( V_3 + V_2 ) ) ) ;
}
void
F_5 ( T_2 * V_4 , const T_3 * V_5 )
{
T_4 V_6 = strlen ( V_5 ) ;
V_4 -> V_7 = F_6 () && ( V_6 <= 16 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_8 = F_7 () ;
memcpy ( & ( V_4 -> V_8 ) , V_5 , V_6 ) ;
}
}
const char *
F_8 ( const char * V_9 , T_4 V_10 , const T_2 * V_4 , T_5 * V_11 )
{
const char * V_12 ;
int V_2 ;
V_2 = ( int ) ( ( T_4 ) V_9 & 15 ) ;
V_12 = ( const char * ) ( ( T_4 ) V_9 & - 16L ) ;
if ( V_2 != 0 )
{
T_1 V_1 = F_1 ( F_9 ( F_4 ( V_12 ) ) , V_2 ) ;
int V_6 = F_10 ( V_4 -> V_8 , V_1 , 0x2 ) ;
int V_13 = F_11 ( V_4 -> V_8 , V_1 , 0x2 ) ;
int V_14 = F_10 ( V_1 , V_1 , 0x3a ) ;
if ( V_13 ) {
if ( V_11 )
* V_11 = * ( V_9 + V_6 ) ;
return V_9 + V_6 ;
}
if ( V_14 < 16 - V_2 )
{
return F_12 ( V_9 + V_14 + 1 , V_10 - V_14 - 1 , V_4 , V_11 ) ;
}
V_12 += 16 ;
V_10 -= ( 16 - V_2 ) ;
}
else
V_12 = V_9 ;
while ( V_10 >= 16 )
{
T_1 V_1 = F_9 ( F_4 ( V_12 ) ) ;
int V_14 = F_10 ( V_4 -> V_8 , V_1 , 0x2 ) ;
int V_13 = F_11 ( V_4 -> V_8 , V_1 , 0x2 ) ;
int V_15 = F_13 ( V_4 -> V_8 , V_1 , 0x2 ) ;
if ( V_13 ) {
if ( V_11 )
* V_11 = * ( V_12 + V_14 ) ;
return V_12 + V_14 ;
}
if ( V_15 )
{
return F_12 ( V_12 , V_10 , V_4 , V_11 ) ;
}
V_12 += 16 ;
V_10 -= 16 ;
}
return F_12 ( V_12 , V_10 , V_4 , V_11 ) ;
}
