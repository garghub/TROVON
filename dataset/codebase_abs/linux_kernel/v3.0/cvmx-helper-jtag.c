void F_1 ( void )
{
union V_1 V_2 ;
T_1 V_3 = 0 ;
T_1 V_4 = F_2 () -> V_5 / ( 25 * 1000000 ) ;
V_4 = ( V_4 - 1 ) >> 2 ;
while ( V_4 ) {
V_3 ++ ;
V_4 = V_4 >> 1 ;
}
V_2 . V_6 = 0 ;
V_2 . V_7 . V_8 = V_3 ;
V_2 . V_7 . V_9 = 0 ;
if ( F_3 ( V_10 ) )
V_2 . V_7 . V_11 = 0x3 ;
else
V_2 . V_7 . V_11 = 0xf ;
F_4 ( V_12 , V_2 . V_6 ) ;
F_5 ( V_12 ) ;
}
T_1 F_6 ( int V_13 , int V_14 , T_1 V_15 )
{
union V_16 V_17 ;
V_17 . V_6 = 0 ;
V_17 . V_7 . V_18 = 1 ;
V_17 . V_7 . V_19 = V_14 - 1 ;
V_17 . V_7 . V_20 = V_15 ;
if ( ! F_3 ( V_21 ) )
V_17 . V_7 . V_22 = 1 << V_13 ;
F_4 ( V_23 , V_17 . V_6 ) ;
do {
V_17 . V_6 = F_5 ( V_23 ) ;
} while ( V_17 . V_7 . V_18 );
return V_17 . V_7 . V_20 >> ( 32 - V_14 ) ;
}
void F_7 ( int V_13 , int V_14 )
{
while ( V_14 > 0 ) {
int V_24 = V_14 ;
if ( V_24 > 32 )
V_24 = 32 ;
F_6 ( V_13 , V_24 , 0 ) ;
V_14 -= V_24 ;
}
}
void F_8 ( int V_13 )
{
union V_16 V_17 ;
V_17 . V_6 = 0 ;
V_17 . V_7 . V_25 = 1 ;
if ( ! F_3 ( V_21 ) )
V_17 . V_7 . V_22 = 1 << V_13 ;
F_4 ( V_23 , V_17 . V_6 ) ;
do {
V_17 . V_6 = F_5 ( V_23 ) ;
} while ( V_17 . V_7 . V_25 );
}
