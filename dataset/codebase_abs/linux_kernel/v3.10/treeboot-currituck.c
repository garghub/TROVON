static unsigned long long F_1 ( void )
{
T_1 V_1 ;
unsigned V_2 ;
unsigned long long V_3 = 0 ;
for( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_1 = F_2 ( V_5 + V_2 ) ;
if ( ! ( V_1 & 1 ) )
continue;
V_1 &= 0x0000f000 ;
V_1 >>= 12 ;
V_3 += ( 0x800000ULL << V_1 ) ;
}
return V_3 ;
}
static void F_3 ( void )
{
void * V_6 = F_4 ( L_1 ) ;
T_1 V_7 [ 7 ] ;
F_5 ( 0x0ULL , V_8 ) ;
while ( ( V_6 = F_6 ( V_6 , L_2 ) ) ) {
if ( F_7 ( V_6 , L_3 , V_7 , sizeof( V_7 ) ) < 0 ) {
printf ( L_4 , V_9 ) ;
continue;
}
V_7 [ 5 ] = V_8 >> 32 ;
V_7 [ 6 ] = V_8 & 0xffffffffUL ;
F_8 ( V_6 , L_3 , V_7 , sizeof( V_7 ) ) ;
}
}
void F_9 ( void )
{
unsigned long V_10 , V_11 ;
T_1 V_12 ;
int V_13 , V_14 ;
const T_1 * V_15 ;
V_8 = F_1 () ;
if ( V_8 >> 32 )
V_10 = ~ 0UL ;
else
V_10 = V_8 ;
V_11 = V_10 - ( unsigned long ) V_16 ;
F_10 ( V_16 , V_11 , 128 , 64 ) ;
V_17 . V_18 = F_3 ;
V_17 . exit = V_19 ;
V_12 = F_11 ( V_20 ) ;
if ( F_12 ( V_21 ) != 0 )
F_13 ( L_5 ) ;
V_13 = F_14 ( V_21 , - 1 , L_6 ,
L_7 , sizeof( L_7 ) ) ;
if ( ! V_13 )
F_13 ( L_8 ) ;
V_15 = F_15 ( V_21 , V_13 , L_9 , & V_14 ) ;
if ( V_15 && ( V_14 == 4 ) )
V_22 = 1000000000 / * V_15 ;
F_16 ( V_21 , V_12 ) ;
F_17 ( V_21 ) ;
F_18 () ;
}
