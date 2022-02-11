static inline T_1
F_1 ( T_1 V_1 , unsigned long int V_2 )
{
return F_2 ( V_1 ,
F_3 ( F_4 ( V_3 + V_2 ) ) ) ;
}
const char *
F_5 ( const char * V_4 , T_2 V_5 , const char * V_6 )
{
const char * V_7 ;
T_1 V_8 ;
int V_2 ;
#if F_6 ( V_9 ) || F_7 ( V_10 )
{
T_2 V_11 ;
V_11 = strlen ( V_6 ) ;
if ( V_11 > 16 )
return F_8 ( V_4 , V_5 , V_6 ) ;
V_8 = F_9 () ;
memcpy ( & V_8 , V_6 , V_11 ) ;
}
#else
V_2 = ( int ) ( ( T_2 ) V_6 & 15 ) ;
V_7 = ( const char * ) ( ( T_2 ) V_6 & - 16L ) ;
if ( V_2 != 0 )
{
int V_11 ;
V_8 = F_1 ( F_10 ( F_4 ( V_7 ) ) , V_2 ) ;
V_11 = F_11 ( V_8 , V_8 , 0x3a ) ;
if ( V_11 == 16 - V_2 )
{
T_1 V_12 = F_10 ( F_4 ( V_7 + 16 ) ) ;
int V_13 = F_11 ( V_12 , V_12 , 0x3a ) ;
V_11 += V_13 ;
if ( V_11 > 16 )
return F_8 ( V_4 , V_5 , V_6 ) ;
if ( V_13 != 0 )
{
V_8 = F_3 ( F_4 ( V_6 ) ) ;
}
}
}
else
{
int V_11 ;
V_8 = F_10 ( F_4 ( V_6 ) ) ;
V_11 = F_11 ( V_8 , V_8 , 0x3a ) ;
if ( V_11 == 16 )
{
if ( V_6 [ 16 ] != 0 )
return F_8 ( V_4 , V_5 , V_6 ) ;
}
}
#endif
V_2 = ( int ) ( ( T_2 ) V_4 & 15 ) ;
V_7 = ( const char * ) ( ( T_2 ) V_4 & - 16L ) ;
if ( V_2 != 0 )
{
T_1 V_1 = F_1 ( F_10 ( F_4 ( V_7 ) ) , V_2 ) ;
int V_11 = F_11 ( V_8 , V_1 , 0x2 ) ;
int V_14 = F_12 ( V_8 , V_1 , 0x2 ) ;
int V_13 = F_11 ( V_1 , V_1 , 0x3a ) ;
if ( V_14 )
return V_4 + V_11 ;
if ( V_13 < 16 - V_2 )
{
return F_8 ( V_4 + V_13 + 1 , V_5 - V_13 - 1 , V_6 ) ;
}
V_7 += 16 ;
V_5 -= ( 16 - V_2 ) ;
}
else
V_7 = V_4 ;
while ( V_5 >= 16 )
{
T_1 V_1 = F_10 ( F_4 ( V_7 ) ) ;
int V_13 = F_11 ( V_8 , V_1 , 0x2 ) ;
int V_14 = F_12 ( V_8 , V_1 , 0x2 ) ;
int V_15 = F_13 ( V_8 , V_1 , 0x2 ) ;
if ( V_14 )
return V_7 + V_13 ;
if ( V_15 )
{
return F_8 ( V_7 , V_5 , V_6 ) ;
}
V_7 += 16 ;
V_5 -= 16 ;
}
return F_8 ( V_7 , V_5 , V_6 ) ;
}
