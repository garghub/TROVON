static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 - V_4 ;
if ( V_3 < 8 )
F_2 ( ( F_3 ( V_5 )
& ~ ( 1 << V_3 ) ) , V_5 ) ;
else if ( V_3 < 16 )
F_2 ( ( F_3 ( V_6 )
& ~ ( 1 << ( V_3 - 8 ) ) ) , V_6 ) ;
else
F_2 ( ( F_3 ( V_7 )
& ~ ( 1 << ( V_3 - 16 ) ) ) , V_7 ) ;
}
static inline T_1 F_4 ( void )
{
return
( ( F_3 ( V_8 ) &
F_3 ( V_5 ) ) ) |
( ( F_3 ( V_9 ) &
F_3 ( V_6 ) ) << 8 ) |
( ( F_3 ( V_10 ) &
F_3 ( V_7 ) ) << 16 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 - V_4 ;
if ( V_3 < 8 )
F_2 ( ( F_3 ( V_5 ) | ( 1 << V_3 ) ) ,
V_5 ) ;
else if ( V_3 < 16 )
F_2 ( ( F_3 ( V_6 )
| ( 1 << ( V_3 - 8 ) ) ) , V_6 ) ;
else
F_2 ( ( F_3 ( V_7 )
| ( 1 << ( V_3 - 16 ) ) ) , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
T_1 V_13 ;
int V_14 ;
V_13 = F_4 () ;
if ( ! V_13 )
return;
for ( V_14 = V_4 ;
( V_14 < V_15 ) && V_13 ;
V_14 ++ , V_13 >>= 1 ) {
if ( V_13 & 1 ) {
F_9 ( V_14 ) ;
}
}
}
void F_10 ( void )
{
int V_16 , V_17 ;
F_2 ( 0 , V_5 ) ;
F_2 ( 0 , V_6 ) ;
F_2 ( 0 , V_7 ) ;
for ( V_16 = V_4 ; V_16 < V_15 ; V_16 ++ ) {
if ( V_16 == V_18 ) {
F_11 ( V_16 , & V_19 ) ;
}
else {
F_11 ( V_16 , & V_20 ) ;
}
F_12 ( V_16 , V_21 ) ;
F_13 ( V_16 , V_22 ) ;
}
V_17 = F_14 ( 13 , L_1 ) ;
if ( V_17 ) {
F_15 ( L_2 , V_23 ) ;
return;
}
F_16 ( 13 ) ;
F_17 ( F_18 ( 13 ) , V_24 ) ;
F_19 ( V_25 , F_8 ) ;
}
