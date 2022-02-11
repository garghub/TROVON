void F_1 ( unsigned long V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
V_4 = ( void V_5 * ) V_1 ;
V_6 = V_2 ;
V_7 = V_3 ;
}
static inline T_1 F_2 ( int V_8 )
{
return F_3 ( V_4 + ( V_8 << V_6 ) ) ;
}
static inline void F_4 ( int V_8 , char V_9 )
{
F_5 ( V_9 , V_4 + ( V_8 << V_6 ) ) ;
}
void F_6 ( char V_10 )
{
unsigned int V_3 ;
int V_11 , V_12 ;
if ( ! V_4 )
return;
V_3 = V_7 ;
V_12 = V_13 | V_14 ;
do {
V_11 = F_2 ( V_15 ) ;
if ( -- V_3 == 0 )
break;
} while ( ( V_11 & V_12 ) != V_12 );
if ( V_3 )
F_4 ( V_16 , V_10 ) ;
}
