static unsigned long long F_1 ( void )
{
T_1 V_1 ;
unsigned V_2 ;
unsigned long long V_3 = 0 ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
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
void * V_6 ;
T_1 V_1 ;
F_4 ( 0x0ULL , V_7 ) ;
F_5 ( V_8 , 0x1 ) ;
V_1 = F_2 ( V_9 ) & ~ 0x2 ;
F_5 ( V_9 , V_1 ) ;
V_6 = F_6 ( L_1 ) ;
if ( V_6 > 0 ) {
if ( V_10 )
F_7 ( V_6 , L_2 ,
( ( V_11 * ) & V_10 ) + 2 , 6 ) ;
}
}
void F_8 ( char * V_12 )
{
unsigned long V_13 , V_14 ;
T_1 V_15 ;
int V_16 , V_17 ;
const T_1 * V_18 ;
int V_19 , V_2 , V_20 ;
char * V_21 ;
V_12 [ V_22 - 1 ] = '\0' ;
V_20 = strlen ( V_12 ) ;
for ( V_2 = 0 ; V_2 < V_20 - 15 ; V_2 ++ ) {
if ( strncmp ( & V_12 [ V_2 ] , L_3 , 15 ) == 0 ) {
if ( V_2 > 0 && V_12 [ V_2 - 1 ] != ' ' ) {
continue;
}
V_10 = F_9 ( & V_12 [ V_2 + 15 ] , & V_21 , 16 ) ;
if ( * V_21 == ' ' )
V_21 ++ ;
V_19 = ( ( int ) V_21 ) - ( ( int ) & V_12 [ V_2 ] ) ;
memmove ( & V_12 [ V_2 ] , V_21 ,
V_20 - ( V_19 + V_2 ) + 1 ) ;
break;
}
}
V_23 . V_24 = V_12 ;
V_23 . V_25 = 256 ;
V_7 = F_1 () ;
if ( V_7 >> 32 )
V_13 = ~ 0UL ;
else
V_13 = V_7 ;
V_14 = V_13 - ( unsigned long ) V_26 ;
F_10 ( V_26 , V_14 , 128 , 64 ) ;
V_27 . V_28 = F_3 ;
V_27 . exit = V_29 ;
V_15 = F_11 ( V_30 ) ;
if ( F_12 ( V_31 ) != 0 )
F_13 ( L_4 ) ;
V_16 = F_14 ( V_31 , - 1 , L_5 ,
L_6 , sizeof( L_6 ) ) ;
if ( ! V_16 )
F_13 ( L_7 ) ;
V_18 = F_15 ( V_31 , V_16 , L_8 , & V_17 ) ;
if ( V_18 && ( V_17 == 4 ) )
V_32 = 1000000000 / * V_18 ;
F_16 ( V_31 , V_15 ) ;
F_17 ( V_31 ) ;
F_18 () ;
}
