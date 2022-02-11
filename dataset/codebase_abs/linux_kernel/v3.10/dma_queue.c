void F_1 ( T_1 * V_1 ,
void * V_2 , unsigned int V_3 )
{
T_2 V_4 = ( V_3 < 65536 ) ? V_3 : 65535 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_2 = V_2 ;
V_1 -> V_5 = 0 ;
V_1 -> V_6 = V_4 << V_7 ;
}
void F_2 ( T_1 * V_1 )
{
T_3 V_8 ;
T_4 V_9 ;
T_4 V_10 ;
T_4 V_11 ;
T_4 V_12 =
F_3 ( & V_1 -> V_5 ,
- 1 , - 1 ) ;
F_4 ( V_12 ) ;
V_8 . V_13 = F_5 ( V_1 -> V_2 ) ;
V_9 = V_8 . V_9 ;
V_10 = ( V_9 - V_12 ) & 0xffff ;
if ( V_10 == 0 )
return;
V_11 = V_12 + V_10 ;
if ( F_3 ( & V_1 -> V_5 ,
V_12 ,
V_11 ) != V_12 )
return;
F_6 ( & V_1 -> V_6 ,
( V_10 << V_7 ) ) ;
}
T_2 F_7 ( T_1 * V_1 ,
T_2 V_14 )
{
int V_15 = 16 ;
T_2 V_16 ;
do {
int V_17 ;
for ( V_17 = V_15 ; V_17 > 0 ; V_17 -- )
F_8 ( V_18 ) ;
F_2 ( V_1 ) ;
V_16 = F_9 ( & V_1 -> V_6 ,
V_14 ) ;
if ( V_15 < 256 )
V_15 *= 2 ;
} while ( V_16 + V_14 < 0 );
return V_16 ;
}
T_2 F_10 ( T_1 * V_1 ,
unsigned int V_19 , int V_20 )
{
return F_11 ( V_1 , V_19 , V_20 != 0 , true ) ;
}
int F_12 ( T_1 * V_1 ,
T_2 V_21 , int V_22 )
{
if ( V_22 ) {
if ( F_13 ( V_1 -> V_5 ) >
V_21 )
return 1 ;
F_2 ( V_1 ) ;
}
return F_13 ( V_1 -> V_5 ) > V_21 ;
}
