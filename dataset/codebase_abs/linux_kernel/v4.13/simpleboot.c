void F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
const T_1 * V_6 , * V_7 , * V_8 , * V_9 ;
T_2 V_10 ;
int V_11 , V_12 , V_13 ;
if ( F_2 ( V_14 ) != 0 )
F_3 ( L_1 ) ;
V_11 = F_4 ( V_14 , L_2 ) ;
if ( V_11 < 0 )
F_3 ( L_3 ) ;
V_6 = F_5 ( V_14 , V_11 , L_4 , & V_12 ) ;
if ( ! V_6 || ( V_12 != 4 ) )
F_3 ( L_5 ) ;
V_7 = F_5 ( V_14 , V_11 , L_6 , & V_12 ) ;
if ( ! V_7 || ( V_12 != 4 ) )
F_3 ( L_7 ) ;
V_11 = F_6 ( V_14 , - 1 , L_8 ,
L_9 , sizeof( L_9 ) ) ;
if ( V_11 < 0 )
F_3 ( L_10 ) ;
V_8 = F_5 ( V_14 , V_11 , L_11 , & V_12 ) ;
if ( V_12 < ( * V_6 + * V_7 ) * sizeof( T_1 ) )
F_3 ( L_12 ) ;
for ( V_13 = 0 ; V_13 < * V_6 ; V_13 ++ )
if ( * V_8 ++ != 0 )
F_3 ( L_13 ) ;
V_10 = 0 ;
for ( V_13 = 0 ; V_13 < * V_7 ; V_13 ++ )
V_10 = ( V_10 << 32 ) | * V_8 ++ ;
if ( sizeof( void * ) == 4 && V_10 >= 0x100000000ULL )
V_10 = 0xffffffff ;
V_11 = F_6 ( V_14 , - 1 , L_8 ,
L_14 , sizeof( L_14 ) ) ;
if ( ! V_11 )
F_3 ( L_15 ) ;
V_9 = F_5 ( V_14 , V_11 , L_16 , & V_12 ) ;
if ( V_9 && ( V_12 == 4 ) )
V_15 = 1000000000 / * V_9 ;
F_7 ( V_16 , V_10 - ( unsigned long ) V_16 , 32 , 64 ) ;
F_8 ( V_14 ) ;
if ( V_17 )
V_17 () ;
F_9 () ;
}
