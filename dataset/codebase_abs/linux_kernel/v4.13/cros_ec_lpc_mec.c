static void F_1 ( T_1 V_1 ,
enum V_2 V_3 )
{
V_1 -= V_4 ;
F_2 ( ( V_1 & 0xfc ) | V_3 , V_5 ) ;
F_2 ( ( V_1 >> 8 ) & 0x7f , V_6 ) ;
}
T_2 F_3 ( enum V_7 V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_2 * V_11 )
{
int V_12 = 0 ;
int V_13 ;
T_2 V_14 = 0 ;
enum V_2 V_15 , V_16 ;
if ( V_9 & 0x3 || V_10 < 4 )
V_15 = V_17 ;
else
V_15 = V_18 ;
F_4 ( & V_19 ) ;
F_1 ( V_9 , V_15 ) ;
V_13 = V_20 + ( V_9 & 0x3 ) ;
while ( V_12 < V_10 ) {
while ( V_13 <= V_21 ) {
if ( V_8 == V_22 )
V_11 [ V_12 ] = F_5 ( V_13 ++ ) ;
else
F_2 ( V_11 [ V_12 ] , V_13 ++ ) ;
V_14 += V_11 [ V_12 ++ ] ;
V_9 ++ ;
if ( V_12 == V_10 )
goto V_23;
}
if ( V_10 - V_12 < 4 && V_8 == V_24 )
V_16 = V_17 ;
else
V_16 = V_18 ;
if ( V_16 != V_15 ||
V_15 != V_18 ) {
V_15 = V_16 ;
F_1 ( V_9 , V_15 ) ;
}
V_13 = V_20 ;
}
V_23:
F_6 ( & V_19 ) ;
return V_14 ;
}
void F_7 ( void )
{
F_8 ( & V_19 ) ;
}
void F_9 ( void )
{
F_10 ( & V_19 ) ;
}
