static unsigned int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_2 ) & V_3 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 )
{
F_4 ( V_1 , V_2 , V_4 ) ;
F_5 () ;
}
static void F_6 ( struct V_1 * V_1 , int V_5 )
{
int V_6 ;
F_3 ( V_1 , V_7 ) ;
F_3 ( V_1 , V_8 ) ;
for ( V_6 = 4 + V_9 ; V_6 >= 0 ; V_6 -- ) {
int V_10 = ( V_5 & ( 1 << V_6 ) ) ? V_11 : 0 ;
F_3 ( V_1 , V_8 | V_10 ) ;
F_3 ( V_1 , V_8 |
V_12 | V_10 ) ;
}
F_3 ( V_1 , V_8 ) ;
}
unsigned int F_7 ( struct V_1 * V_1 , int V_13 )
{
int V_14 = ( V_13 ? 0x3f : 0 ) | ( V_15 << V_9 ) ;
unsigned int V_16 = 0 ;
int V_6 ;
F_6 ( V_1 , V_14 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
F_3 ( V_1 , V_8 |
V_12 ) ;
V_16 = ( V_16 << 1 ) | F_1 ( V_1 ) ;
F_3 ( V_1 , V_8 ) ;
V_16 = ( V_16 << 1 ) | F_1 ( V_1 ) ;
}
F_3 ( V_1 , ~ V_17 ) ;
V_16 = ( V_16 << 1 ) | F_1 ( V_1 ) ;
return V_16 ;
}
T_2 F_8 ( struct V_1 * V_1 , int V_18 )
{
int V_19 = V_18 | ( V_20 << V_9 ) ;
unsigned short V_16 = 0 ;
int V_6 ;
F_6 ( V_1 , V_19 ) ;
for ( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
F_3 ( V_1 , V_8 |
V_12 ) ;
V_16 = ( V_16 << 1 ) | F_1 ( V_1 ) ;
F_3 ( V_1 , V_8 ) ;
}
F_3 ( V_1 , ~ V_17 ) ;
return ( V_21 T_2 ) V_16 ;
}
int F_9 ( struct V_1 * V_1 , int V_18 ,
T_2 V_4 )
{
int V_22 = V_18 | ( V_23 << V_9 ) ;
unsigned int V_16 ;
int V_6 ;
F_6 ( V_1 , V_22 ) ;
for ( V_6 = 15 ; V_6 >= 0 ; V_6 -- ) {
unsigned int V_10 = ( ( V_21 unsigned ) V_4 >> V_6 ) & 1 ;
F_3 ( V_1 , V_24 ) ;
F_3 ( V_1 ,
V_24 | ( V_10 << 1 ) | V_12 ) ;
}
F_3 ( V_1 , V_24 ) ;
F_3 ( V_1 , ~ V_17 ) ;
F_3 ( V_1 , V_24 ) ;
for ( V_6 = V_16 = 0 ; V_6 < 10000 && ! V_16 ; V_6 ++ )
V_16 = F_1 ( V_1 ) ;
F_3 ( V_1 , ~ V_17 ) ;
return ! V_16 ;
}
